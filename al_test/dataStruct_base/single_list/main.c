#include <stdio.h>
#include <stdlib.h>
#include "single_list.h"

void PrintList(List L)
{
	Position TmpCell;

	TmpCell = L->Next;
	while (TmpCell != NULL)
	{
	  printf("%d ", TmpCell->Element);
	  TmpCell = TmpCell->Next;
	}
	printf("\n");
}

int main(void)
{
	List L;
	Position Previous;
	int i, j;
	ElementType ElementArray[10] = {0,1,2,3,4,5,6,7,8,9};	
	
	L = MakeEmpty();
	Previous = L;
	i = sizeof(ElementArray) / sizeof(ElementType);
	printf("i:%d\n", i);

	for (j = 0; j < i; j++)
	{
		InSert(ElementArray[j], L, Previous);
		Previous = Previous->Next;
		printf("%d ", ElementArray[j]);
	}
	printf("\n");

	PrintList(L);

	DeleteList(L);
	FreeListHead(L);

	return 0;
}
