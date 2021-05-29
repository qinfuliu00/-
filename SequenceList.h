#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

#define MAXSIZE 100
#define InitSize 100

typedef int ElemType;
typedef struct SqList {       //顺序表结构
	ElemType * data;
	ElemType length;
	ElemType maxsize;
}*SqList;

SqList InitList(SqList L) {    //顺序表初始化（动态分配）
	L->data = (ElemType*)malloc(sizeof(ElemType) * InitSize);
}

bool ListInsert(SqList L, int i, ElemType e) {     //插入  时间复杂度o(n)
	if (i<1 || i>L->length + 1)
		return false;
	if (L->length >= MAXSIZE)
		return false;
	for (int j, j = L->length; j >= i; j--)        //将第i个元素及其之后的元素后移
		L->data[i - 1] = e;                        //在位置i处放入e
	L->length++;
	return true;
}

bool ListDelete(SqList L, int i, ElemType e) {    //删除  时间复杂度o(n)
	if (i<1 || i>L->length)
		return false;
	e = L->data[i - 1];                    //将要被删除的元素赋给e
	for (int j = i; j < L->length; j++)    //将第i个位置后的元素前移
		L->data[j - 1] = L->data[j];
	L->length--;
	return true;
}

int LocateElem(SqList L, ElemType e) {         //按值查找（顺序查找）   时间复杂度o（n）
	int i;
	for (i = 0; i < L->length; i++)
		if (L->data[i] == e)
			return i + 1;                     //下标为i的元素值等于e，返回其位序i+1
	return 0;
}