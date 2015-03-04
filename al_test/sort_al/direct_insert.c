#include <stdio.h>

int data_array[] = {4,5,6,3,2,6,7,5,9,9,6,7,4,3,93,4,5,6,3,4,2,1,9,6,7,4,53};

void direct_insert(int *array, int n)
{
	int i,j;
	int tmp;

	for (i = 1; i < n; i++) {
		tmp = array[i];
		j = i - 1;
		while (j >= 0 && tmp < array[j]) {
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = tmp;
	}
}

int main(void)
{
	int i,n;
	n = sizeof(data_array) / sizeof(int);
	printf("%d\n", n);

	for (i = 0; i < n; i++) 
		printf("%d ", data_array[i]);
	printf("\n");

	direct_insert(data_array, n);
	
	for (i = 0; i < n; i++) 
		printf("%d ", data_array[i]);
	printf("\n");

	return 0;
}
			
