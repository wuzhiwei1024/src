main : main.o single_list.o 
	gcc -o main main.o single_list.o

single_list.o:single_list.h
main.o : main.c

.PHONY : clean
clean:
	rm *.o
