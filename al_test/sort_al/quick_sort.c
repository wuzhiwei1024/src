#include <stdio.h>

int data_array[] = {44,3,5,4,44,55,3,2,7,88,7,9,88,9,66,3};

void quick_sort(int *array, int n)
{
	int i, j;
	int pivotValue;

	if (n == 0) {
		printf("recursive over!\n");
		return;
	}

	i = 0;
	j = n - 1;

	pivotValue = array[i];
	while(i != j) {
		while(j > i && array[j] >= pivotValue) 
			j--;
		array[i] = array[j];
		
		while(i < j && array[i] <= pivotValue)
			i++;
		array[j] = array[i];
	}
	array[i] = pivotValue;

	quick_sort(array, i);
	quick_sort(array + i + 1, n - 1 - i);
		
}

int main()
{
	int n, i;

	n = sizeof(data_array) / sizeof(int);
	printf("%d\n", n);

	for (i = 0; i < n; i++)
		printf("%d ", data_array[i]);
	printf("\n");

	quick_sort(data_array, n);

	
	for (i = 0; i < n; i++)
		printf("%d ", data_array[i]);
	printf("\n");

	return 0;
}
