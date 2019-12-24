all: boggle

boggle: main.h main.c
	g++ -o boggle main.c
