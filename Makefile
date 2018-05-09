as.o: as.c
	gcc -c as.c
as: as.o
	gcc as.o -o as
