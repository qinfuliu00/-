#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

#define MAXSIZE 100
#define InitSize 100

typedef int ElemType;
typedef struct SqList {       //˳���ṹ
	ElemType * data;
	ElemType length;
	ElemType maxsize;
}*SqList;

SqList InitList(SqList L) {    //˳����ʼ������̬���䣩
	L->data = (ElemType*)malloc(sizeof(ElemType) * InitSize);
}

bool ListInsert(SqList L, int i, ElemType e) {     //����  ʱ�临�Ӷ�o(n)
	if (i<1 || i>L->length + 1)
		return false;
	if (L->length >= MAXSIZE)
		return false;
	for (int j, j = L->length; j >= i; j--)        //����i��Ԫ�ؼ���֮���Ԫ�غ���
		L->data[i - 1] = e;                        //��λ��i������e
	L->length++;
	return true;
}

bool ListDelete(SqList L, int i, ElemType e) {    //ɾ��  ʱ�临�Ӷ�o(n)
	if (i<1 || i>L->length)
		return false;
	e = L->data[i - 1];                    //��Ҫ��ɾ����Ԫ�ظ���e
	for (int j = i; j < L->length; j++)    //����i��λ�ú��Ԫ��ǰ��
		L->data[j - 1] = L->data[j];
	L->length--;
	return true;
}

int LocateElem(SqList L, ElemType e) {         //��ֵ���ң�˳����ң�   ʱ�临�Ӷ�o��n��
	int i;
	for (i = 0; i < L->length; i++)
		if (L->data[i] == e)
			return i + 1;                     //�±�Ϊi��Ԫ��ֵ����e��������λ��i+1
	return 0;
}