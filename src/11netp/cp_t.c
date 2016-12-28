#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <pthread.h>

typedef struct {
	char *src_address;
	char *dest_address;
	int len;
} arg_t;

static void err_sys(const char *s);
static int get_file_length(int fd);
static int extend(int fd, int len);
arg_t map_src_dest(const char *src, const char *dest);
static void *cpy(void *arg);
void divide_thread(int pnum, arg_t arg_file);

int main(int argc, char *argv[])
{
	arg_t arg_file;

	if (argc != 4) {
		fprintf(stderr, "Usage:%s file1 file2 thread_num", argv[0]);
		exit(1);
	}

	arg_file = map_src_dest(argv[1], argv[2]);
	divide_thread(atoi(argv[3]), arg_file);

	munmap(arg_file.src_address, arg_file.len);
	munmap(arg_file.dest_address, arg_file.len);

	return 0;
}

static void err_sys(const char *s)
{
	perror(s);
	exit(1);
}

static int get_file_length(int fd)
{
	int position = lseek(fd, 0, SEEK_CUR);
	int length = lseek(fd, 0, SEEK_END);
	lseek(fd, position, SEEK_SET);

	return length;
}

static int extend(int fd, int len)
{
	int file_len = get_file_length(fd);
	if (file_len >= len) {
		return -1;
	}
	lseek(fd, len - file_len - 1, SEEK_END);
	write(fd, "", 1);

	return 0;
}

arg_t map_src_dest(const char *src, const char *dest)
{
	int fd_src, fd_dest, len;
	char *src_address, *dest_address;
	arg_t arg_file;

	fd_src = open(src, O_RDONLY);
	if (fd_src < 0) {
		err_sys("open src");
	}

	len = get_file_length(fd_src);

	src_address = mmap(NULL, len, PROT_READ, MAP_SHARED, fd_src, 0);
	if (src_address == MAP_FAILED) {
		err_sys("mmap src");
	}

	close(fd_src);	

	fd_dest = open(dest, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd_dest < 0) {
		err_sys("open dest");
	}

	extend(fd_dest, len);

	dest_address = mmap(NULL, len, PROT_WRITE, MAP_SHARED, fd_dest, 0);
	if (dest_address == MAP_FAILED) {
		err_sys("mmap dest");
	}

	close(fd_dest);		

	arg_file.len = len;
	arg_file.src_address = src_address;
	arg_file.dest_address = dest_address;

	return arg_file;
}

static void *cpy(void *arg)
{
	char *src_address, *dest_address;
	int len;

	src_address = ((arg_t *) arg)->src_address;
	dest_address = ((arg_t *) arg)->dest_address;
	len = ((arg_t *) arg)->len;

	memcpy(dest_address, src_address, len);

	return NULL;
}

void divide_thread(int pnum, arg_t arg_file)
{
	int i, len;
	char *src_address, *dest_address;
	pthread_t *pid;
	arg_t arg[pnum];

	len = arg_file.len;
	src_address = arg_file.src_address;
	dest_address = arg_file.dest_address;
	pid = malloc(pnum * sizeof(pid));

	if (pnum > len) {
		fprintf(stderr,
			"too many threads, even larger than length, are you crazy?!\n");
		exit(1);
	}

	for (i = 0; i < pnum; i++) {
		arg[i].src_address = src_address + len / pnum * i;
		arg[i].dest_address = dest_address + len / pnum * i;
		if (i != pnum - 1) {
			arg[i].len = len / pnum;
		} else {
			arg[i].len = len - len / pnum * i;
		}
		pthread_create(&pid[i], NULL, cpy, &arg[i]);
	}

	for (i = 0; i < pnum; i++) {
		pthread_join(pid[i], NULL);
	}

	free(pid);
}
