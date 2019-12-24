all: boggle

boggle: main.o list.o
	gcc -o boggle main.o list.o

main.o: main.h main.c
	gcc -c main.c

list.o: list.h list.c
	gcc -c list.c

test_list.o: test_list.c
	gcc -c test_list.c

test_list: list.o test_list.o
	gcc -o test_list list.o test_list.o

clean:
	-@rm -rf *.o boggle test_list 2>/dev/null || true
