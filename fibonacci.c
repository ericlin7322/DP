#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int fib(int n) {
	if (n==0 || n==1) return n;
	int* f = malloc(sizeof(int)*(n+1));
	f[0] = 0;
	f[1] = 1;
	for (int i=2;i<=n;i++)
		f[i] = f[i-1] + f[i-2];
	return f[n];
}

int main(int argc, char** argv) {
	
	int cmd_opt = 0;
	int n = strtol(argv[1], NULL, 10);
	printf("%d", fib(n));

	return 0;
}
