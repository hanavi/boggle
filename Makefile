CFLAGS = -g `pkg-config --cflags gtk+-3.0` `pkg-config --libs gtk+-3.0` -rdynamic

all: boggle

boggle: main.o lists.o dict.o board.o solve.o
	gcc $(CFLAGS) -o boggle main.o lists.o dict.o board.o solve.o

solve.o: solve.h solve.c
	gcc $(CFLAGS) -c solve.c

dict.o: dict.c dict.h
	gcc $(CFLAGS) -c dict.c

main.o: main.h main.c
	gcc $(CFLAGS) -c main.c

lists.o: lists.h lists.c
	gcc $(CFLAGS) -c lists.c

board.o: board.c board.h
	gcc $(CFLAGS) -c board.c

test_board.o: test_board.c
	gcc $(CFLAGS) -c test_board.c

test_board: board.o test_board.o lists.o
	gcc $(CFLAGS) -o test_board board.o test_board.o lists.o

test_lists.o: test_lists.c
	gcc $(CFLAGS) -c test_lists.c

test_lists: lists.o test_lists.o
	gcc $(CFLAGS) -o test_lists lists.o test_lists.o

test_dict.o: test_dict.c
	gcc $(CFLAGS) -c test_dict.c

test_dict: test_dict.o dict.o board.o lists.o
	gcc $(CFLAGS) -o test_dict test_dict.o dict.o board.o lists.o

tests: test_lists test_board test_dict

clean:
	-@rm -rf *.o boggle test_dict test_board test_lists main 2>/dev/null || true
