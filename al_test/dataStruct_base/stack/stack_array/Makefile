main : main.o stack_array.o
	gcc -o main main.o stack_array.o

main.o : main.c
	gcc -c main.c
stack_array.o : stack_array.h stack_array.c
	gcc -c stack_array.c

.PHONY : clean
clean :
	rm *.o
