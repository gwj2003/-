#include <stdio.h>
#include <stdlib.h>
typedef int ElemType; /* 数据元素类型  */
int count = 0;        /* 计数器  */

/* 函数声明 */
typedef struct Node {
	ElemType data;          /* 数据域 */
	struct Node* leftChild; /* 左子树指针 */
	struct Node* rightChild; /* 右子树指针 */
} BiTreeNode;              /* 结点的结构体定义 */

BiTreeNode* addNode(int data)
{
	BiTreeNode* node = (BiTreeNode*)malloc(sizeof(BiTreeNode));
	node->data = data;
	node->leftChild = NULL;
	node->rightChild = NULL;
	return node;
}

void createNode(BiTreeNode* curr, int data)
{
	curr->data = data;
	curr->leftChild = NULL;
	curr->rightChild = NULL;
	return;
}

void Destroy(BiTreeNode* curr)
{
	if (curr != NULL && curr->leftChild != NULL)
		Destroy(curr->leftChild);
	if (curr != NULL && curr->rightChild != NULL)
		Destroy(curr->rightChild);
	free(curr);
}

void insertTree(BiTreeNode* curr, int data)
{
	if (data < curr->data)
	{
		if (curr->leftChild == NULL) { curr->leftChild = addNode(data); }
		else { insertTree(curr->leftChild, data); }
	}
	else
	{
		if (curr->rightChild == NULL) { curr->rightChild = addNode(data); }
		else { insertTree(curr->rightChild, data); }
	}
	return;
}

void preorderTraversal(BiTreeNode* root)
{
	if (root == NULL) { return; }
	printf("%5d", root->data);
	count++;
	preorderTraversal(root->leftChild);
	preorderTraversal(root->rightChild);
}

void inorderTraversal(BiTreeNode* curr)
{
	if (curr == NULL) { return; }
	inorderTraversal(curr->leftChild);
	printf("%5d", curr->data);
	count++;
	inorderTraversal(curr->rightChild);
}

void postorderTraversal(BiTreeNode* curr)
{
	if (curr == NULL) { return; }
	postorderTraversal(curr->leftChild);
	postorderTraversal(curr->rightChild);
	printf("%5d", curr->data);
	count++;
}

main()
{
	BiTreeNode* curr = (BiTreeNode*)malloc(sizeof(BiTreeNode));
	int i, k;
	printf("\n在该程序中请输入回车以执行下一步\n");
	do
	{
		printf("\n======================================");
		printf("\n\n     1. 建立二叉树 ");
		printf("\n\n     2. 前序遍历");
		printf("\n\n     3. 中序遍历");
		printf("\n\n     4. 后序遍历");
		printf("\n\n     5. 结束程序运行");
		printf("\n\n======================================");
		printf("\n     请输入您的选择 (1,2,3,4,5)\n");
		do
		{
			scanf_s("%d", &k);
			if (k < 1 || k > 5) { printf("\n     请输入1,2,3,4,5\n"); }
		} while (k < 1 || k > 5);
		switch (k) {
		case 1:
		{
			printf("请输入头结点\n");
			scanf_s("%d", &i);
			createNode(curr, i);
			printf("请输入结点(输入-111以结束) \n");
			scanf_s("%d", &i);
			while (i != -111)
			{
				insertTree(curr, i);
				printf("请输入结点(输入-111以结束) \n");
				scanf_s("%d", &i);
			}
		} break;
		case 2:
		{
			count = 0;
			printf("前序遍历的结果：");
			preorderTraversal(curr);
			printf("\n叶子节点数：%d\n", count);
		} break;
		case 3:
		{
			count = 0;
			printf("中序遍历的结果：");
			inorderTraversal(curr);
			printf("\n叶子节点数：%d\n", count);
		} break;
		case 4:
		{
			count = 0;
			printf("后序遍历的结果：");
			postorderTraversal(curr);
			printf("\n叶子节点数：%d\n", count);
		} break;
		case 5:
		{
			Destroy(curr);
		} break;
		} /*  switch  */
	} while (k >= 1 && k < 5);
}