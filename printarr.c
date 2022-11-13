#include <stdio.h>
#include "printarr.h"

void printArr(int* arr, int n) {
	for (int i=0;i<n;i++)
		printf("%3d ", arr[i]);
	printf("\n");
}
