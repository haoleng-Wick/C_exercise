/*
 * 在二叉树中增加一行
 * 给一个二叉树的根,整数和深度,在该深度添加值为val的节点行
 * 
 * 先序遍历
 * input: root = [4, 2, 6, 3, 1, 5], val = 1, depth = 2
 * 		 4 					    4
 *	   /   \				   / \
 *	  2     6 			      1   1
 *	 / \   /	    	     /     \
 *	3   1 5 	    	   	2       6
 *					       / \     /
 *					      3   1   5
 * output = [4, 1, 1, 2, null, null, 6, 3, 1, 5]
 */
#include <stdio.h>
#include <stdlib.h>

struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

/*
 * node 二级指针,可以将变量通过参数传入函数内部且带出来
 * 这里的node是指向传入node的指针 
 * 因此修改参数指向的内容是要用(*node)->val 
 */
int create_node(struct TreeNode **node)
{
	int val;
	scanf("%d", &val);

	if (val == -1) {
		*node = NULL;	//将原本的node值设为NULL;
		return -1;
	} else {
		*node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
		if (node == NULL) {
			printf("failed\n");
			return -1;
		} else {
			(*node)->val = val;
			printf("intput left_val: ");
			create_node(&(*node)->left);
			printf("intput right_val: ");
			create_node(&(*node)->right);
		}
	} 
	return 0;
}

// 遍历节点
void pre_traver_tree(struct TreeNode *node)
{
	if (node == NULL) {
		printf("null ");
		return;
	} else {
		printf("%d ", node->val);
		pre_traver_tree(node->left);
		pre_traver_tree(node->right);
	}
}

// 深度优先搜索
struct TreeNode *add_one_row(struct TreeNode *root, int depth, int val)
{
	if (root == NULL) {
		return NULL;
	}
	struct TreeNode *node;
	if (depth == 1) {
		node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
		node->val = val;
		node->left = root;
		node->right = NULL;
		return node;
	} else if (depth == 2) {
		node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
		node->val = val;
		node->left = root->left;
		node->right = NULL;
		root->left =node;

		node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
		node->val = val;
		node->left = NULL;
		node->right = root->right;
		root->right = node;
	} else {
		root->left = add_one_row(root->left, val, depth - 1);
		root->left = add_one_row(root->right, val, depth - 1);
	}

	return root;
}

int main(int argc, char **argv)
{
	struct TreeNode *root;
	printf("create tree, please input the root_val:\n");
	create_node(&root);
	printf("create done!\n");

	printf("tree = [ ");
	pre_traver_tree(root);
	printf("]\n");
	
	printf("new_tree = [ ");
	pre_traver_tree(add_one_row(root, 2, 1));
	printf("]\n");

	return 0;
}
