#include<stdio.h>
#include<stdlib.h>
#define MaxSize 50

typedef int ElemType;
typedef struct LNode {      //单链表
	ElemType data;
	struct LNode* next;
}LNode,*LinkList;
typedef struct DNode {      //双链表
	ElemType data;
	struct DNode* prior, * next;
}DNode, * DLinkList;
typedef struct {            //静态链表
	ElemType data;
	int next;               //下一个元素的数组下标，以-1作为其结束的标志
}SLinkList[MaxSize];

LinkList List_HeadInsert(LinkList L) {     //头插法建立单链表  时间复杂度o(n)
	LNode* s; int x;
	L = (LinkList)malloc(sizeof(LNode));   //建立头结点
	L->next = NULL;
	scanf_s("%d", &x);
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));  //创建新结点
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf_s("%d", &x);
	}
	return L;
}

LinkList List_TailInsert(LinkList L) {       //尾插法建立单链表   时间复杂度o（n）
	int x;
	L = (LinkList)malloc(sizeof(LNode));     //建立头结点
	LNode* s, * r = L;                       //r为表尾指针
	scanf_s("%d", &x);
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;                               //r指向新的表尾结点
		scanf_s("%d", &x);
	}
	r->next = NULL;                         //尾结点指针置空
	return L;
}

LNode* GetElem(LinkList L, int i) {   //按序号查找结点值  时间复杂度o（n）
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
	return p;                         //返回第i个结点的指针，若i大于表长则返回NULL
}

LNode* LocateElem(LinkList L, ElemType x) {   //按值查找表结点
	LNode* p = L->next;
	while (p != NULL & p->data != x)
		p = p->next;
	return p;                                 //找到后返回该结点指针，否则返回NULL
}




