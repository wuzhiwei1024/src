#include <stdio.h>

int data_array[] = {2,4,2,1,5,6,4,3,2,6,5,77,66,7,6,88,9,88,9,34,10,1,2,33};

void merge(int *array, int p, int m, int q)
{
	int i, j, k;
	int a, b;

	a = m - q + 1;
	b = q - m;

	int a1[a], a2[b];

	for (i = 0; i < a; i++)
		a1[i] = array[p - 1 + i];
	for (i = 0; i < b; i++)
		a2[i] = array[m + i];

	i = j = 0;
	k = p - 1;

	while (i < a && j < b) {
		if (a1[i] < a2[j]) 
			array[k++] = a1[i++];
		else
			array[k++] = a2[j++];
	}
	
	while (i < a)
		array[k++] = a1[i++];
	while (j < b)
		array[k++] = a2[j++];
	
	return;
}

void recursive_mergesort(int *array, int p, int q)
{
	int m;
	if (p < q) {
		m = (p + q) / 2;
		recursive_mergesort(array, p, m);
		recursive_mergesort(array, m + 1, q);
		merge(array, p, m, q);
	}
}

int main()
{
	int i,n;

	n = sizeof(data_array) / sizeof(int);
	printf("%d\n",n);

	for (i = 0; i < n; i++)
	  printf("%d ", data_array[i]);
	printf("\n");

	recursive_mergesort(data_array, 1, n);

	for (i = 0; i < n; i++)
	  printf("%d ", data_array[i]);
	printf("\n");

	return 0;
}
