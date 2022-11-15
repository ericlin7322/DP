CC = gcc

all: fib rod_cutting knapsack matrix obst lcs kmp

fib: fibonacci.c
	$(CC) -c fibonacci.c
	$(CC) -o fibonacci fibonacci.o

rod_cutting: rod_cutting.c
	$(CC) -c rod_cutting.c
	$(CC) -o rod_cutting rod_cutting.o

knapsack: 01_knapsack.c printarr.c printarr.h 
	$(CC) -c 01_knapsack.c
	$(CC) -c printarr.c printarr.h
	$(CC) -o knapsack 01_knapsack.o printarr.o

matrix: matrix_chain.c
	$(CC) -c matrix_chain.c
	$(CC) -o matrix_chain matrix_chain.o

obst: obst.c
	$(CC) -c obst.c
	$(CC) -o obst obst.o

lcs: lcs.c
	$(CC) -c lcs.c
	$(CC) -o lcs lcs.o

kmp: kmp.c
	$(CC) -c kmp.c
	$(CC) -o kmp kmp.o

clean:
	rm *.o matrix_chain knapsack rod_cutting fibonacci obst lcs kmp
