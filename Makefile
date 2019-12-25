CFLAGS = -g

all: boggle

boggle: main.o list.o dict.o
	gcc $(CFLAGS) -o boggle main.o list.o dict.o

dict.o: dict.c dict.h
	gcc $(CFLAGS) -c dict.c

main.o: main.h main.c
	gcc $(CFLAGS) -c main.c

list.o: list.h list.c
	gcc $(CFLAGS) -c list.c

board.o: board.c board.h
	gcc $(CFLAGS) -c board.c

test_board.o: test_board.c
	gcc $(CFLAGS) -c test_board.c

test_board: board.o test_board.o list.o
	gcc $(CFLAGS) -o test_board board.o test_board.o list.o

test_list.o: test_list.c
	gcc $(CFLAGS) -c test_list.c

test_list: list.o test_list.o
	gcc $(CFLAGS) -o test_list list.o test_list.o

test_dict.o: test_dict.c
	gcc $(CFLAGS) -c test_dict.c

test_dict: test_dict.o dict.o board.o list.o
	gcc $(CFLAGS) -o test_dict test_dict.o dict.o board.o list.o

tests: test_list test_board test_dict

clean:
	-@rm -rf *.o boggle test_list 2>/dev/null || true
