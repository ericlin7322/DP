#include <stdio.h>
#include <stdlib.h>
#include "printarr.h"
#define MAX(a,b) (((a)>(b))?(a):(b))

int main() {
	int n = 3, W = 5;
	int v[] = {0,6,10,12};
	int w[] = {0,1,2,3};
	int **s = malloc((n+1) * sizeof(int*));
	for (int i=0;i<W;i++)
		s[i] = malloc((W+1) * sizeof(int));

	for (int k=0;k<=W;k++) {
		s[0][k] = 0;
	}
	
	for (int i=1;i<=n;i++) {
		s[i][0] = 0;
		for (int k=1;k<=W;k++) {
			if (k<w[i])
				s[i][k]=s[i-1][k];
			else
				s[i][k]=MAX(s[i-1][k], v[i]+s[i-1][k-w[i]]);
		}
	}

	for (int i=0;i<=n;i++) {
		printArr(s[i], W+1);
	}

}
