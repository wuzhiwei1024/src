#include <stdio.h>

int data_array[] = {4,5,6,3,5,6,3,9,8,3,2,0,6,3,3,4};

void simple_select(int *array, int n)
{
	int i,j,index;
	int tmp;

	for (i = 0; i < n - 1; i++) {
		index = i;

		for (j = i; j < n; j++) {
				if (array[j] < array[index]) 
					index = j;
						
		}

		if (index != i) {
			tmp = array[index];
			array[index] = array[i];
			array[i] = tmp;
		}
	}
}

int main(void)
{
	int n,i;
	
	n = sizeof(data_array) / sizeof(int);
	printf("%d\n", n);

	for (i = 0; i < n; i++) 
		printf("%d ", data_array[i]);
	printf("\n");

	simple_select(data_array, n);

	for (i = 0; i < n; i++) 
		printf("%d ", data_array[i]);
	printf("\n");
	
	return 0;
}
