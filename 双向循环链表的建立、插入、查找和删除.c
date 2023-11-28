#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;				/* 数据元素类型  */
typedef  struct LNode
{
	ElemType data;					/* 数据子域      */
	struct LNode* lnext, * rnext;	/* 指针子域      */
}LNode;								/* 结点结构类型  */
LNode* L;							/* 头指针        */

/*  函数声明  */
LNode* creat_L();
void  out_L(LNode* L);
void  insert_L(LNode* L, int i, ElemType e);
ElemType delete_L(LNode* L, int i);
int locate_L(LNode* L, ElemType e);

int main()
{
	int i, k, loc;
	ElemType e, x;
	char ch;
	printf("\n在该程序中请输入回车以执行下一步\n");
	do {
		printf("\n======================================");
		printf("\n\n     1. 建立线性链表 ");
		printf("\n\n     2. 在i位置插入元素e");
		printf("\n\n     3. 删除第i个元素，返回其值");
		printf("\n\n     4. 查找值为 e 的元素");
		printf("\n\n     5. 结束程序运行");
		printf("\n\n======================================");
		printf("\n     请输入您的选择 (1,2,3,4,5)\n");
		do
		{
			scanf_s("%d", &k);
			if (k < 1 || k > 5){printf("\n     请输入1,2,3,4,5\n");}
		} while (k < 1 || k > 5);
		switch (k)
		{
		case 1:
		{
			L = creat_L();
			out_L(L);
		} break;
		case 2:
		{
			printf(" i,e=?\n");
			scanf_s("%d,%d", &i, &e);
			insert_L(L, i, e);
			out_L(L);
		} break;
		case 3:
		{
			printf(" i=?\n");
			scanf_s("%d", &i);
			x = delete_L(L, i);
			printf(" x=%d\n", x);
			out_L(L);
		} break;
		case 4:
		{
			printf(" e=?\n");
			scanf_s("%d", &e);
			loc = locate_L(L, e);
			if (loc == -1)
				printf(" 未找到");
			else printf(" 已找到，元素位置是 %d", loc);
		} break;
		case 5:
		{
			printf("\n敲击回车键结束程序\n");
			ch = getchar();
		} break;
		} /*  switch  */
	} while (k >= 1 && k < 5);
	ch = getchar();
} /* main */

/*  建立线性链表 */
LNode* creat_L()
{
	LNode* h, * p, * s;  ElemType x;
	h = (LNode*)malloc(sizeof(LNode));        /* 分配头结点 */
	h->lnext = h->rnext = h->data = NULL;
	p = h;
	printf("  data=?\n");
	scanf_s("%d", &x);                        /*  输入第一个数据元素 */
	while (x != -111)                         /*  输入-111，结束循环 */
	{
		s = (LNode*)malloc(sizeof(LNode));    /*  分配新结点 */
		s->data = x;
		s->rnext = h;
		s->lnext = p;
		p->rnext = s;
		p = s;
		printf("  data=?(输入-111以结束)\n");
		scanf_s("%d", &x); /* 输入下一个数据*/
	}
	return(h);
} /* creat_L  */

/* 输出链表中的数据元素*/
void out_L(LNode* L)
{
	printf("目前的链表：");
	LNode* p;
	p = L->rnext;
	while (p->data != NULL)
	{
		printf("%5d", p->data);
		p = p->rnext;
	};
} /* out_link */

/*  在i位置插入元素e  */
void insert_L(LNode* L, int i, ElemType e)
{
	LNode* s, * p;
	int j;
	p = L;      /* 找第i-1个结点  */
	j = 0;
	while (p->rnext->data != NULL && j < i - 1)
	{
		p = p->rnext;
		j++;
	}
	if (p->rnext->data == NULL || j > i - 1)
		printf("\n i ERROR !\n");
	else
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = e;
		s->rnext = p->rnext;
		s->lnext = p;
		p->rnext->lnext = s;
		p->rnext = s;
	}
} /* insert_L */

/*  查找值为 e 的元素, 返回它的位置  */
int locate_L(LNode* L, ElemType e)
{
	LNode* p; int j = 1;
	p = L->rnext;
	while (p->data != NULL && p->data != e)
	{
		p = p->rnext;
		j++;
	}
	if (p->data != NULL)
		return(j);
	else return(-1);
} /* locat_L */

/* 删除第i个位置的元素, 返回它的值  */
ElemType delete_L(LNode* L, int i)
{
	LNode* p;
	int j;
	p = L;      /* 找第i-1个结点  */
	j = 0;
	while (p->rnext->data != NULL && j < i - 1)
	{
		p = p->rnext;
		j++;
	}
	if (p->rnext->data == NULL || j > i - 1)
	{
		printf("\n i ERROR !\n");
		return -111;
	}
	else
	{
		p = p->rnext;
		p->rnext->lnext = p->lnext;
		p->lnext->rnext = p->rnext;
	}
	return p->data;
}