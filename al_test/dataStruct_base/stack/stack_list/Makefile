main : main.o stack_list.o
	gcc -o main main.o stack_list.o

main.o : main.c
	gcc -c main.c
stack_list.o : stack_list.h
	gcc -c stack_list.c

.PHONY : clean
clean:
	rm *.o
