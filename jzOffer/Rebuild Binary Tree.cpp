#include <stdio.h> 
#include <stdlib.h> 

struct TreeNode {
	int m_value;
	TreeNode* m_left;
	TreeNode* m_right;
};

TreeNode* ConstructCore(int* start_preoder, int* end_preoder, int* start_inoder, int* end_inoder);

TreeNode* Construct(int* pre_order,int* in_order,int length)
{
	if (pre_order == NULL || in_order == NULL || length <= 0)
	{
		return NULL;
	}

	return ConstructCore(pre_order, pre_order + length - 1, in_order, in_order + length - 1);
}

TreeNode* ConstructCore(int* start_preoder, int* end_preoder, int* start_inoder, int* end_inoder)
{
	int rootnode_value = *start_preoder;
	TreeNode* root = new TreeNode();
	root->m_value = rootnode_value;
	int* where_inorder = start_inoder;
	while (*where_inorder != rootnode_value)
	{
		where_inorder++;
	}
	int leftlength = where_inorder - start_inoder;
	if (leftlength > 0)
	{
		root->m_left = ConstructCore(start_preoder + 1, start_preoder + leftlength, start_inoder, start_inoder + leftlength - 1);
	}
	if (leftlength < end_preoder - start_preoder)
	{
		root->m_right = ConstructCore(start_preoder + leftlength + 1, end_preoder, start_inoder + leftlength, end_inoder);
	}

	return root;
}

/*
void main()
{
	int length = 8;
	int pre_order[8] = { 1,2,4,7,3,5,6,8 };
	int in_oreder[8] = { 4,7,2,1,5,3,8,6 };
	Construct(pre_order, in_oreder, 8);
	
	return;
}
*/