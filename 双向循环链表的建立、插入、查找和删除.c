#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;				/* ����Ԫ������  */
typedef  struct LNode
{
	ElemType data;					/* ��������      */
	struct LNode* lnext, * rnext;	/* ָ������      */
}LNode;								/* ���ṹ����  */
LNode* L;							/* ͷָ��        */

/*  ��������  */
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
	printf("\n�ڸó�����������س���ִ����һ��\n");
	do {
		printf("\n======================================");
		printf("\n\n     1. ������������ ");
		printf("\n\n     2. ��iλ�ò���Ԫ��e");
		printf("\n\n     3. ɾ����i��Ԫ�أ�������ֵ");
		printf("\n\n     4. ����ֵΪ e ��Ԫ��");
		printf("\n\n     5. ������������");
		printf("\n\n======================================");
		printf("\n     ����������ѡ�� (1,2,3,4,5)\n");
		do
		{
			scanf_s("%d", &k);
			if (k < 1 || k > 5){printf("\n     ������1,2,3,4,5\n");}
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
				printf(" δ�ҵ�");
			else printf(" ���ҵ���Ԫ��λ���� %d", loc);
		} break;
		case 5:
		{
			printf("\n�û��س�����������\n");
			ch = getchar();
		} break;
		} /*  switch  */
	} while (k >= 1 && k < 5);
	ch = getchar();
} /* main */

/*  ������������ */
LNode* creat_L()
{
	LNode* h, * p, * s;  ElemType x;
	h = (LNode*)malloc(sizeof(LNode));        /* ����ͷ��� */
	h->lnext = h->rnext = h->data = NULL;
	p = h;
	printf("  data=?\n");
	scanf_s("%d", &x);                        /*  �����һ������Ԫ�� */
	while (x != -111)                         /*  ����-111������ѭ�� */
	{
		s = (LNode*)malloc(sizeof(LNode));    /*  �����½�� */
		s->data = x;
		s->rnext = h;
		s->lnext = p;
		p->rnext = s;
		p = s;
		printf("  data=?(����-111�Խ���)\n");
		scanf_s("%d", &x); /* ������һ������*/
	}
	return(h);
} /* creat_L  */

/* ��������е�����Ԫ��*/
void out_L(LNode* L)
{
	printf("Ŀǰ������");
	LNode* p;
	p = L->rnext;
	while (p->data != NULL)
	{
		printf("%5d", p->data);
		p = p->rnext;
	};
} /* out_link */

/*  ��iλ�ò���Ԫ��e  */
void insert_L(LNode* L, int i, ElemType e)
{
	LNode* s, * p;
	int j;
	p = L;      /* �ҵ�i-1�����  */
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

/*  ����ֵΪ e ��Ԫ��, ��������λ��  */
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

/* ɾ����i��λ�õ�Ԫ��, ��������ֵ  */
ElemType delete_L(LNode* L, int i)
{
	LNode* p;
	int j;
	p = L;      /* �ҵ�i-1�����  */
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