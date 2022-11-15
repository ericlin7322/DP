#include <stdio.h>
#include <stdlib.h>

int* prefix(char *p, int n) {
	int *pi = malloc((n)*sizeof(int));
	
	for(int i=0;i<n;i++)
		pi[i] = 0;

	pi[1] = 0;
	int k = 0;
	for (int i=1;i<n;i++) {
		while (k>0 && p[k] != p[i])
			k=pi[k-1];
		if (p[k] == p[i])
			k=k+1;
		pi[i] = k;
	}

	for (int i=0;i<n;i++)
		printf("%d ", pi[i]);
	printf("\n");
	return pi;
}

void kmp(char *t, int tn, char *p, int pn) {
	int *pi = prefix(p, pn);
	int k = 0;
	for (int i=0;i<tn;i++) {
		printf("%d ", k);
		while (k>0 && p[k] != t[i])
			k=pi[k-1];
		if (p[k] == t[i])
			k=k+1;
		if (k-1 == pn) {
			k = pi[k-1];
		}
	}
	printf("%d", k);
}

int main() {

	char *t = "aababbababbbababbaaabb";
	char *p = "ababbaaa";

	kmp(t, 22, p, 8);
	return 0;
}
