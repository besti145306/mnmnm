edit : main.o add.o subtract.o multiply.o divide.o
	gcc -o edit  main.o add.o subtract.o multiply.o divide.o

main.o : main.c head.h
	gcc -c main.c

add.o : add.c head.h
	gcc -c add.c

subtract : subtract.c head.h
	gcc -c subtract.c

multiply : multiply.c head.h
	gcc -c multiply.c

divide : divide.c head.h
	gcc -c divide.c

clean :
	rm edit main.o add.o subtract.o multiply.o divide.o
        
