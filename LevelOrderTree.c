/*
 * 给你二叉树的根节点root,返回其节点值的层序遍历
 * 逐层地、从左到右访问所有节点
 * input: root = [3, 9, -1, -1, 20, 15, -1, -1, 7, -1, -1]
 * 其中 -1 代表 null
 *      3
 *     / \
 *    9  20
 *      /  \
 *     15   7
 * output: = [[3], [9, 20], [15, 7]]
 *
 * 树中节点数目范围[0, 2000]
 * 节点值[-1000, 1000]
 */
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left_child;
    struct TreeNode *right_child;
};

// 创建树(先序)
void create_node(struct TreeNode **node)
{
    int val;
    scanf("%d", &val);
    if (val == -1)
    {
        *node = NULL;
        return;
    }
    *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    (*node)->val = val;
    printf("Left child val: ");
    create_node(&(*node)->left_child);
    printf("Right child val: ");
    create_node(&(*node)->right_child);
}

// 层序遍历
void LeavelOrder(struct TreeNode *root)
{
	if (root == NULL)
		return;

    printf("The tree:\n");
	struct TreeNode* cur;   // 指针
	struct TreeNode* Queue[2001];  // 数组模拟队列
	int front = 0, rear = 0;  // 队头队尾
	Queue[rear++] = root;   // 根结点入队列

	while (front != rear)   // 外部循环处理队列
	{
        int last = rear;
        //内部循环处理每层的节点
		while (front < last)  // 每次循环出队一个节点,并将其孩子入队 
		{
			cur = Queue[front++];
            printf("%d ", cur->val);
			if (cur->left_child != NULL)
			{
				Queue[rear++] = cur->left_child;
			}
			if (cur->right_child != NULL)
			{
				Queue[rear++] = cur->right_child;
			}
		}
        printf("\n");
	}
}

int main(int argc, char **argv)
{
    struct TreeNode *root;
    printf("Please input the val of the treenode\nRoot val: ");
    create_node(&root);
    LeavelOrder(root);

    return 0;
}
