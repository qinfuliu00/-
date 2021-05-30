#include<stdio.h>
#include<stdlib.h>
#define MaxSize 50

typedef int ElemType;
typedef struct LNode {      //������
	ElemType data;
	struct LNode* next;
}LNode,*LinkList;
typedef struct DNode {      //˫����
	ElemType data;
	struct DNode* prior, * next;
}DNode, * DLinkList;
typedef struct {            //��̬����
	ElemType data;
	int next;               //��һ��Ԫ�ص������±꣬��-1��Ϊ������ı�־
}SLinkList[MaxSize];

LinkList List_HeadInsert(LinkList L) {     //ͷ�巨����������  ʱ�临�Ӷ�o(n)
	LNode* s; int x;
	L = (LinkList)malloc(sizeof(LNode));   //����ͷ���
	L->next = NULL;
	scanf_s("%d", &x);
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));  //�����½��
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf_s("%d", &x);
	}
	return L;
}

LinkList List_TailInsert(LinkList L) {       //β�巨����������   ʱ�临�Ӷ�o��n��
	int x;
	L = (LinkList)malloc(sizeof(LNode));     //����ͷ���
	LNode* s, * r = L;                       //rΪ��βָ��
	scanf_s("%d", &x);
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;                               //rָ���µı�β���
		scanf_s("%d", &x);
	}
	r->next = NULL;                         //β���ָ���ÿ�
	return L;
}

LNode* GetElem(LinkList L, int i) {   //����Ų��ҽ��ֵ  ʱ�临�Ӷ�o��n��
	int j = 1;
	LNode* p = L->next;
	if (i == 0)
		return L;
	if (i < 1)
		return NULL;
	while (p && j < i) {
		p = p->next;
		j++;
	}
	return p;                         //���ص�i������ָ�룬��i���ڱ��򷵻�NULL
}

LNode* LocateElem(LinkList L, ElemType x) {   //��ֵ���ұ���
	LNode* p = L->next;
	while (p != NULL & p->data != x)
		p = p->next;
	return p;                                 //�ҵ��󷵻ظý��ָ�룬���򷵻�NULL
}




