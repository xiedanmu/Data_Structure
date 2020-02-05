#include<stdio.h>
#include "TreeDef.h"

SearchTree MakeEmpty(SearchTree T)
{
	if (T != NULL)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}

Position Find(ElementType X, SearchTree T)
{
	if (T == NULL)
		return NULL;
	if (X < T->Element)
		return Find(X, T->Element);
	if (X > T->Element)
		return Find(X, T->Element);
	return T;
}

Position FindMin(SearchTree T)
{
	if (T == NULL)
		return NULL;
	if (T->Left == NULL)
		return T;
	else
		return FindMin(T->Left);
}

Position FindMax(SearchTree T)
{
	if (T == NULL)
		return NULL;
	if (T->Right == NULL)
		return T;
	else
		return FindMax(T->Right);
}

SearchTree Insert(ElementType X, SearchTree T)
{
	if (T == NULL)
	{
		/*Create and return ond-node tree*/
		T = malloc(sizeof(struct TreeNode));
		if (T == NULL)
			FatalError("Out of space!!!");
		else
		{
			T->Element = X;
			T->Left = T->Right = NULL;
		}
	}
	else if(X<T->Element)
	{
		Insert(X, T->Left);
	}
	else if (X>T->Element)
	{
		Insert(X, T->Right);
	}
	/*Else X is in the tree already;we'll do nothing*/
	return T;/*Do not forget this line*/
}

SearchTree Delete(ElementType X, SearchTree T)
{
	Position TmpCell;
	if (T == NULL)
		Error("Element not fonud");
	else if (X < T->Element)	/*GO LEFT*/
		T->Left = Delete(X, T->Left);
	else if (X > T->Element)	/*GO RIGHT*/
		T->Right = Delete(X, T->Right);
	else if(T->Left&&T->Right)	/*Two children*/
	{
		/*Replace with smallest in right subtree*/
		TmpCell = FindMin(T->Right);
		T->Element = TmpCell->Element;
		T->Right = Delete(T->Element, T->Right);

	}
	else    /*One or zero children*/
	{
		TmpCell = T;
		if (T->Left == NULL) /*Also handles 0 children*/
			T = T->Right;
		else if (T->Right == NULL)
			T = T->Left;
		free(TmpCell);
	}
	return T;
}

