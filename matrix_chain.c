#include <stdio.h>
#include <stdlib.h>

void print_parens(int** c, int i, int j) {
	if (i==j)
		printf("A");
	else {
		printf("(");
		print_parens(c,i,c[i][j]);
		print_parens(c, c[i][j]+1, j);
		printf(")");
	}

}

int main() {
	int n=4;
	int p[] = {2,3,5,4,2};
	int **s = malloc((n+1)*sizeof(int*));
	for (int i=0;i<=n;i++)
		s[i] = malloc((n+1)*sizeof(int));
	int **c = malloc(n*sizeof(int*));
	for (int i=0;i<=n;i++)
		c[i] = malloc((n+1)*sizeof(int));

	for(int i=0;i<=n;i++)
		s[i][i] = 0;
	
	for (int i=0;i<n;i++) {
		for (int j=0;j<=n;j++) {
			c[i][j] = 0;
		}
	}


	for (int l=2;l<=n;l++) {
		for (int i=1;i<=n-l+1;i++) {
			int j=i+l-1;
			s[i][j] = s[i][i]+s[i+1][j]+p[i-1]*p[i]*p[j];
			for (int k=i;k<=j-1;k++) {
				int r = s[i][k] + s[k+1][j]+p[i-1]*p[k]*p[j];
				if (r<s[i][j]) {
					s[i][j] = r;
					c[i][j] = k;
				}
			}
		}
	}
	
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			printf("%d ", s[i][j]);
		}
		printf("\n");
	}

	for (int i=1;i<n;i++) {
		for (int j=2;j<=n;j++) {
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}

}
