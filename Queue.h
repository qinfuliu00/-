#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#define MAXSIZE 50

typedef int ElemType;
typedef struct { 
	ElemType data[MAXSIZE];               //��Ŷ���Ԫ��
	int front, rear;                      //��ͷָ��Ͷ�βָ��
}SqQueue;                                 //˳�����

//���е���ʽ�洢�������У�
typedef struct LinkNode{
	ElemType data;
	struct LinkNode* next;
}LinkNode;
typedef struct {
	LinkNode* front, * rear;
}LinkQueue;

/*���г����Ļ�������
InitQueue��&Q������ʼ�����У�����һ���ն���Q��
QueueEmpty��Q�����ж��пգ�������QΪ���򷵻�true�����򷵻�false��
EnQueue��&Q��x������ӣ�������Qδ������x���룬ʹ֮��Ϊ�µĶ�β��
DeQueue��&Q��&x�������ӣ�������Q�ǿգ�ɾ����ͷԪ�أ�����x���ء�
GetHead��Q��&x����������Ԫ�أ�������Q�ǿգ��򽫶�ͷԪ�ظ�ֵ��x��
*/

//ѭ�����еĲ���
void InitQueue(SqQueue& Q) {
	Q.rear = Q.front = 0;
}

bool isEmpty(SqQueue Q) {
	if (Q.rear == Q.front)    //�ӿ�����
		return true;          
	else
		return false;
}

bool EnQueue(SqQueue& Q, ElemType& x) {
	if ((Q.rear + 1) % MAXSIZE == Q.front)     //��������
		return false;
	Q.data[Q.rear] = x;
	Q.rear = (Q.rear + 1) % MAXSIZE;           //��βָ���һȡģ
	return true;
}

bool DeQueue(SqQueue& Q, ElemType& x) {
	if (Q.rear == Q.front)                  //�ӿձ���
		return false;
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;      //��ͷָ���һȡģ
	return true;
}

//��ʽ���еĲ���
void InitQueue(LinkQueue& Q) {
	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));//����ͷ���
	Q.front->next = NULL;                                  //��ʼΪ��
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
	s->next = NULL;                          //�����½�㣬���뵽��β
	Q.rear->next = s;
	Q.rear = s;
}

bool DeQueue(LinkQueue& Q, ElemType& x) {
	if (Q.front == Q.rear)
		return false;
	LinkNode* p = Q.front->next;
	x = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)                      //��ԭ������ֻ��һ����㣬ɾ������
		Q.rear = Q.front;
	free(p);
	return true;
}