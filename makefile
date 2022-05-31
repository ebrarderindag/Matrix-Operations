all:make run

make:main.o	matrisoperations.o
	gcc	main.o	matrisoperations.o	-o	make
	
main.o:main.c
	gcc	-c	main.c

matrisoperations.o:	matrisoperations.c	matrisoperations.h
	gcc	-c	matrisoperations.c

clean:
	del	*.o	make.exe
run:
	make.exe

	