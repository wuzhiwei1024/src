#include <stdio.h>

int data_array[] = {3,4,2,6,3,8,5,999,66,3,4,22,3,0};

void simple_bubble(int *array, int n)
{
	int i,j;
	int tmp;

	for (i = 0; i < n - 1; i++) {
		for (j = n - 1; j > i; j--) {
				if (array[j] < array[j - 1]) {
					tmp = array[j];
					array[j] = array[j - 1];
					array[j - 1] = tmp;
				}
		}
	}
}

int main()
{
	int n, i;

	n = sizeof(data_array) / sizeof(int);
	printf("%d\n", n);

	for (i = 0; i < n; i++) 
		printf("%d ", data_array[i]);
	printf("\n");

	simple_bubble(data_array, n);


	for (i = 0; i < n; i++) 
		printf("%d ", data_array[i]);
	printf("\n");

	return 0;
}
