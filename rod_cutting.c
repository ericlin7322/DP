#include <stdio.h>
#include <limits.h>

void printArr(int* arr, int n) {
	for (int i=0;i<n;i++) {
		printf("%3d ", arr[i]);
	}
	printf("\n");
}

int main() {
	int p[11] = {0,1,3,8,8,9,10,18,18,23,25};
	int r[11] = {0};
	int c[11] = {0};

	for (int j=1;j<=10;j++) {
		int s = INT_MIN;
		for (int i=1;i<=j;i++) {
			if (s < p[i] + r[j-i]) {
				s = p[i] + r[j-i];
				c[j] = i;
			}
		}
		r[j] = s;
	}
	printf("p[i]: ");
	printArr(p, 11);
	printf("r[i]: ");
	printArr(r, 11);
	printf("c[i]: ");
	printArr(c, 11);
}
