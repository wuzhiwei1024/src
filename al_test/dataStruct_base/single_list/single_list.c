#include <stdio.h>
#include <stdlib.h>
#include "single_list.h"

List MakeEmpty(void)
{
	List L;
	
	L = (struct Node *) malloc (sizeof(struct Node));
	if (NULL == L) 
	{
		printf("create empty List Fail!\n");
		return NULL;
	}

	L->Next = NULL;

	return L;
}

void FreeListHead(List L)
{
	free(L);
}

int IsEmpty(List L)
{
	return L->Next == NULL;
}

int IsLast(Position P, List L)
{
	return P->Next == NULL;
}

Position Find(ElementType X, List L)
{
	Position P;

	P = L->Next;

	while (P != NULL && P->Element != X)
	  P = P->Next;

	return P;
}


void Delete(ElementType X, List L)
{
	Position P, TmpCell;

	P = FindPrevious(X, L);
	
	if (!IsLast(P, L))
	{
		TmpCell = P->Next;
		P->Next = TmpCell->Next;
		free(TmpCell);
		P->Next = NULL;
	}
}
	  
Position FindPrevious(ElementType X, List L)
{
	Position P;

	P = L;
	while (P->Next != NULL && P->Next->Element != X)
	  P = P->Next;

	return P;
}

void InSert(ElementType X, List L, Position P)
{
	Position TmpCell;

	TmpCell = malloc(sizeof(struct Node));
	if (NULL == TmpCell)
		printf("out of space!\n");
		
	TmpCell->Element = X;
	TmpCell->Next = NULL;
	P->Next = TmpCell;
}

void DeleteList(List L)
{
	Position P, TmpCell;

	P = L->Next;
	L->Next = NULL;

	while (P != NULL) 
	{
		TmpCell = P->Next;
		free(P);
		P = TmpCell;
	}
}

Position Header(List L)
{
}

Position First(List L)
{
	return L->Next;
}

Position Advance(Position P)
{
}

ElementType Retrieve(Position P)
{
	return P->Element;
}



