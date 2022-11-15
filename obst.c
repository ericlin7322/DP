#include <stdio.h>
#include <stdlib.h>

int main() {
	int n = 4;
	int **s = malloc((n+2)*sizeof(int*));
	for (int i=0;i<n+2;i++)
		s[i] = malloc((n+1)*sizeof(int));
	int **w = malloc((n+2)*sizeof(int*));
	for (int i=0;i<n+2;i++)
		w[i] = malloc((n+1)*sizeof(int));
	int **root = malloc((n+1)*sizeof(int*));
	for (int i=0;i<n+1;i++)
		root[i] = malloc((n+1)*sizeof(int));
	int p[5] = {0,5,2,4,3};
	int q[5]= {3,2,3,4,2};

	for (int i=0;i<=n+1;i++)
		for (int j=0;j<=n;j++)
			s[i][j] = 0;
	for (int i=0;i<=n;i++)
		for (int j=0;j<=n;j++) {
			w[i][j] = 0;
			root[i][j] = 0;
		}

	for (int i=1;i<=n+1;i++) {
		s[i][i-1] = q[i-1];
		w[i][i-1] = q[i-1];
	}
	for (int l=1;l<=n;l++) {
		for (int i=1;i<=n-l+1;i++) {
			int j = i + l - 1;
			w[i][j] = w[i][j-1]+p[j] + q[j];
			s[i][j] = s[i][i-1]+s[i+1][j]+w[i][j];
			for (int r = i+1;r<=j;r++) {
				int t = s[i][r-1]+s[r+1][j]+w[i][j];
				if (t < s[i][j]) {
					s[i][j] = t;
					root[i][j] = r;
				}
			}
			if (root[i][j] == 0)
				root[i][j]  = i;
		}

	}
		
	for (int i=1;i<n+2;i++) {
		for (int j=0;j<=n;j++)
			printf("%3d ", w[i][j]);
		printf("\n");
	}
	printf("\n");
	for (int i=1;i<n+2;i++) {
		for (int j=0;j<=n;j++)
			printf("%3d ", s[i][j]);
		printf("\n");
	}
	printf("\n");
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++)
			printf("%3d ", root[i][j]);
		printf("\n");
	}
	

	return 0;
}
