#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#define MAXSIZE 50

typedef int ElemType;
typedef struct { 
	ElemType data[MAXSIZE];               //存放队列元素
	int front, rear;                      //队头指针和队尾指针
}SqQueue;                                 //顺序队列

//队列的链式存储（链队列）
typedef struct LinkNode{
	ElemType data;
	struct LinkNode* next;
}LinkNode;
typedef struct {
	LinkNode* front, * rear;
}LinkQueue;

/*队列常见的基本操作
InitQueue（&Q）：初始化队列，构造一个空队列Q。
QueueEmpty（Q）：判队列空，若队列Q为空则返回true，否则返回false。
EnQueue（&Q，x）：入队，若队列Q未满，将x加入，使之成为新的队尾。
DeQueue（&Q，&x）：出队，若队列Q非空，删除队头元素，并用x返回。
GetHead（Q，&x）：读队友元素，若队列Q非空，则将队头元素赋值给x。
*/

//循环队列的操作
void InitQueue(SqQueue& Q) {
	Q.rear = Q.front = 0;
}

bool isEmpty(SqQueue Q) {
	if (Q.rear == Q.front)    //队空条件
		return true;          
	else
		return false;
}

bool EnQueue(SqQueue& Q, ElemType& x) {
	if ((Q.rear + 1) % MAXSIZE == Q.front)     //队满报错
		return false;
	Q.data[Q.rear] = x;
	Q.rear = (Q.rear + 1) % MAXSIZE;           //队尾指针加一取模
	return true;
}

bool DeQueue(SqQueue& Q, ElemType& x) {
	if (Q.rear == Q.front)                  //队空报错
		return false;
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;      //队头指针加一取模
	return true;
}

//链式队列的操作
void InitQueue(LinkQueue& Q) {
	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));//建立头结点
	Q.front->next = NULL;                                  //初始为空
}

bool IsEmpty(LinkQueue Q) {
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}

void EnQueue(LinkQueue& Q, ElemType x) {
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;                          //创建新结点，插入到链尾
	Q.rear->next = s;
	Q.rear = s;
}

bool DeQueue(LinkQueue& Q, ElemType& x) {
	if (Q.front == Q.rear)
		return false;
	LinkNode* p = Q.front->next;
	x = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)                      //若原队列中只有一个结点，删除后变空
		Q.rear = Q.front;
	free(p);
	return true;
}