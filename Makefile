all: boggle

boggle: main.o list.o dict.o
	gcc -o boggle main.o list.o dict.o

dict.o: dict.c dict.h
	gcc -c dict.c

main.o: main.h main.c
	gcc -c main.c

list.o: list.h list.c
	gcc -c list.c

board.o: board.c board.h
	gcc -c board.c

test_board.o: test_board.c
	gcc -c test_board.c

test_board: board.o test_board.o list.o
	gcc -o test_board board.o test_board.o list.o

test_list.o: test_list.c
	gcc -c test_list.c

test_list: list.o test_list.o
	gcc -o test_list list.o test_list.o

tests: test_list test_board

clean:
	-@rm -rf *.o boggle test_list 2>/dev/null || true
