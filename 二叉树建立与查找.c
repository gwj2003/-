#include <stdio.h>
#include <stdlib.h>
typedef int ElemType; /* ����Ԫ������  */
int count = 0;        /* ������  */

/* �������� */
typedef struct Node {
	ElemType data;          /* ������ */
	struct Node* leftChild; /* ������ָ�� */
	struct Node* rightChild; /* ������ָ�� */
} BiTreeNode;              /* ���Ľṹ�嶨�� */

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
	printf("\n�ڸó�����������س���ִ����һ��\n");
	do
	{
		printf("\n======================================");
		printf("\n\n     1. ���������� ");
		printf("\n\n     2. ǰ�����");
		printf("\n\n     3. �������");
		printf("\n\n     4. �������");
		printf("\n\n     5. ������������");
		printf("\n\n======================================");
		printf("\n     ����������ѡ�� (1,2,3,4,5)\n");
		do
		{
			scanf_s("%d", &k);
			if (k < 1 || k > 5) { printf("\n     ������1,2,3,4,5\n"); }
		} while (k < 1 || k > 5);
		switch (k) {
		case 1:
		{
			printf("������ͷ���\n");
			scanf_s("%d", &i);
			createNode(curr, i);
			printf("��������(����-111�Խ���) \n");
			scanf_s("%d", &i);
			while (i != -111)
			{
				insertTree(curr, i);
				printf("��������(����-111�Խ���) \n");
				scanf_s("%d", &i);
			}
		} break;
		case 2:
		{
			count = 0;
			printf("ǰ������Ľ����");
			preorderTraversal(curr);
			printf("\nҶ�ӽڵ�����%d\n", count);
		} break;
		case 3:
		{
			count = 0;
			printf("��������Ľ����");
			inorderTraversal(curr);
			printf("\nҶ�ӽڵ�����%d\n", count);
		} break;
		case 4:
		{
			count = 0;
			printf("��������Ľ����");
			postorderTraversal(curr);
			printf("\nҶ�ӽڵ�����%d\n", count);
		} break;
		case 5:
		{
			Destroy(curr);
		} break;
		} /*  switch  */
	} while (k >= 1 && k < 5);
}