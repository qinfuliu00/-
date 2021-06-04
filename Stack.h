#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAXSIZE 50

typedef int ElemType;
typedef struct {
	ElemType data[MAXSIZE];
	int top;
}SqStack;                       //顺序栈
typedef struct {
	ElemType data[MAXSIZE];
	int top1, top0;
}ShareStack;                    //共享栈
typedef struct LinkNode {
	ElemType data;
	struct LinkNode* next;
}LinkNode, * LinkStack;        //链栈
/*栈的基本操作
InitStack（&S）：初始化一个栈。
StackEmpty（S）：判断栈是否为空，空返回true，不空返回false
Push（&S，x）：进栈，若栈S未满，则将x加入使之成为新栈顶。
Pop（&S，&x）：出栈，若栈S非空，则弹出栈顶元素，并用x返回。
GetTop（S，&x）：读栈顶元素，若栈S非空，则用x返回栈顶元素。
DestoryStack（&S）：销毁栈，并释放栈S所占用的存储空间。
*/
 //顺序栈
void InitStack(SqStack &S) {
	S.top = -1;                 //初始化栈顶指针
}

bool StackEmpty(SqStack S) {
	if (S.top == -1)             
		return true;           //栈空返回true
	else
		return false;
}

bool Push(SqStack& S, ElemType x) {
	if (S.top == MAXSIZE - 1)        //栈满，报错
		return false;
	S.data[++S.top] = x;             //指针先加一，再入栈
	return true;
}

bool Pop(SqStack& S, ElemType& x) {
	if (S.top == -1)             //栈空报错
		return false;
	x = S.data[S.top--];         //先出栈，指针再减一
	return true;
}

bool GetTop(SqStack S, ElemType& x) {      
	if (S.top == 1)                        //栈空，报错
		return false;
	x = S.data[S.top];                     //记录栈顶元素
	return true;                           //仅为读取栈顶元素，并没有出栈操作,原栈顶元素依然保留在栈中
}

//链栈
LinkStack push(LinkStack S, ElemType x) {
	LinkStack node = (LinkStack)malloc(sizeof(LinkStack));  //创建存储新元素的结点
	node->data = x;   //采用尾插法建立链栈
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
