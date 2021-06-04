#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAXSIZE 50

typedef int ElemType;
typedef struct {
	ElemType data[MAXSIZE];
	int top;
}SqStack;                       //˳��ջ
typedef struct {
	ElemType data[MAXSIZE];
	int top1, top0;
}ShareStack;                    //����ջ
typedef struct LinkNode {
	ElemType data;
	struct LinkNode* next;
}LinkNode, * LinkStack;        //��ջ
/*ջ�Ļ�������
InitStack��&S������ʼ��һ��ջ��
StackEmpty��S�����ж�ջ�Ƿ�Ϊ�գ��շ���true�����շ���false
Push��&S��x������ջ����ջSδ������x����ʹ֮��Ϊ��ջ����
Pop��&S��&x������ջ����ջS�ǿգ��򵯳�ջ��Ԫ�أ�����x���ء�
GetTop��S��&x������ջ��Ԫ�أ���ջS�ǿգ�����x����ջ��Ԫ�ء�
DestoryStack��&S��������ջ�����ͷ�ջS��ռ�õĴ洢�ռ䡣
*/
 //˳��ջ
void InitStack(SqStack &S) {
	S.top = -1;                 //��ʼ��ջ��ָ��
}

bool StackEmpty(SqStack S) {
	if (S.top == -1)             
		return true;           //ջ�շ���true
	else
		return false;
}

bool Push(SqStack& S, ElemType x) {
	if (S.top == MAXSIZE - 1)        //ջ��������
		return false;
	S.data[++S.top] = x;             //ָ���ȼ�һ������ջ
	return true;
}

bool Pop(SqStack& S, ElemType& x) {
	if (S.top == -1)             //ջ�ձ���
		return false;
	x = S.data[S.top--];         //�ȳ�ջ��ָ���ټ�һ
	return true;
}

bool GetTop(SqStack S, ElemType& x) {      
	if (S.top == 1)                        //ջ�գ�����
		return false;
	x = S.data[S.top];                     //��¼ջ��Ԫ��
	return true;                           //��Ϊ��ȡջ��Ԫ�أ���û�г�ջ����,ԭջ��Ԫ����Ȼ������ջ��
}

//��ջ
LinkStack push(LinkStack S, ElemType x) {
	LinkStack node = (LinkStack)malloc(sizeof(LinkStack));  //�����洢��Ԫ�صĽ��
	node->data = x;   //����β�巨������ջ
	node->next = S;
	S = node;
	return node;
}

LinkStack pop(LinkStack S) {
	if (S) {
		LinkNode* p = S;
		S = S->next;
		free(p);
	}
	else {
		return S;
	}
	return S;
}
