#pragma once

#ifndef _TreeDef_H
typedef int ElementType;

typedef struct TreeNode* Position, * SearchTree;

SearchTree MakeEmpty(SearchTree T);
Position Find(ElementType X, SearchTree T);
Position FindMax(SearchTree T);
Position FindMin(SearchTree T);
SearchTree Insert(ElementType X, SearchTree T);
SearchTree Delete(ElementType X, SearchTree T);
ElementType Retrieve(Position P);

#endif /*_TreeDef_H*/

//Defination of binary tree
struct TreeNode
{
	ElementType Element;
	SearchTree Left;
	SearchTree Right;
};
