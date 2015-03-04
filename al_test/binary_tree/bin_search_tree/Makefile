main : main.o bs_tree.o
	gcc -o main main.o bs_tree.o

main.o : main.c
	gcc -c main.c
bs_tree.o : bs_tree.h
	gcc -c bs_tree.c

.PHONY : clean
clean:
	rm *.o
