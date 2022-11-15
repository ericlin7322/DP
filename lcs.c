#include <stdio.h>
#include <stdlib.h>
void lcs(char *x, int xn, char *y, int yn) {
	int **s = malloc((xn+1)*sizeof(int*));
	for (int i=0;i<=xn;i++)
		s[i] = malloc((yn+1)*sizeof(int));

	for (int i=0;i<=yn;i++)
		s[0][i] = 0;

	for (int i=1;i<=xn;i++) {
		s[i][0] = 0;
		for (int j=1;j<=yn;j++) {
			if (x[i-1] == y[j-1])
				s[i][j] = s[i-1][j-1]+1;
			else if (s[i-1][j] >= s[i][j-1])
				s[i][j] = s[i-1][j];
			else
				s[i][j] = s[i][j-1];
		}
	}
	
	for (int i=0;i<=xn;i++) {
		for (int j=0;j<=yn;j++)
			printf("%3d", s[i][j]);
		printf("\n");
	}
}

int main() {
	
	char x[] = "GTCA";
	char y[] = "GTACG";
	int xn = 4;
	int yn = 5;

	lcs(x, xn, y, yn);

	return 0;
}
