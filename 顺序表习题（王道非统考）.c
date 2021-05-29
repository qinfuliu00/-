#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"SequenceList.h"

int main()
{

}

ElemType DeleteMin(SqList L) {   //��˳�����ɾ��������Сֵ��Ԫ�أ�����Ψһ������������ֵ
	ElemType min = L->data[0];
	ElemType i, j;

	if (L->length <= 0)
		return false;
	for (j = 0; j < L->length; j++) {   //˳�������Сֵ
		if (L->data[j] < min) {             //min������Сֵ
			min = L->data[j];
			i = j;                          //i��¼��Сֵλ��
		}
	}
	L->data[i] = L->data[j];  //�����һ��Ԫ����ճ�λ
	L->length--;
	return min;
}

void Reverse(SqList L) {    //��˳������� ��Ҫ��ռ临�Ӷ�Ϊo��1��
	int i, j, temp;
	for (i = 0,j=L->length; i+1==j; i++,j--) {
		temp = L->data[i];
		L->data[i] = L->data[j];
		L->data[j] = temp;
	}
}

void DeleteDesignation(SqList L, int x) {     //ɾ�����Ա�������ֵΪx������Ԫ��
	int i;
	for (i = 0; i < L->length; i++) {
		if (L->data[i] == x) {
			L->data[i] = L->data[L->length];     //�����Ա����һ��Ԫ�������ɾ��Ԫ��
			L->length--;                         //���Ա��ȼ�1
			i--;                                 //������λ�ú���һλ�������Ԫ�ؼ�����ѯ
		}
	}
} 

void DeleteBetween(SqList L, int s, int t) {     //ɾ��ֵ��s��t֮�������Ԫ��
	int i, j, k = 0;
	if (s >= t||L==NULL)
		return false;
	for (i = 0; i < L->length; i++) {           //˳�����
		if (L->data[i] > s && L->data[i] < t)    //��λ��i����ֵλ��s��t֮��
			k++;
		else
			L->data[i - k] = L->data[i];    //��ǰԪ��ǰ��k��λ��  
	}
	L->length -= k;
}

void DeleteSqBetween(SqList L, int s, int t) {     //������˳�����ɾ����ֵ�ڸ���ֵs��t֮�������Ԫ��(����s��t,s<t��
	int i, j;
	if (s >= t || L == NULL)
		return false;
	for (i = 0; L->data[i] < s; i++);             //�ҵ�����˳����е�һ�����ڵ���sֵ��λ��
	for (j = i; L->data <= t; j++);               //�ҵ�����˳����е�һ�����ڵ���tֵ��λ��
	for (; i < L->length; i++,j++) {                  //������˳����з���Ҫ���λ��ɾ��
		L->data[i] = L->data[j];
		L->length--;
	}
		
}

void DeleteSqRepeat(SqList L) {              //������˳�����ɾ��������ֵ�ظ���Ԫ��;
	int i, j;
	for (i = 0; i < L->length; i++) {
		if (L->data[i] == L->data[i + 1])         //����ǰԪ��ֵ���ں�һλԪ��ֵ
			L->data[i + 1] = L->data[i + 2];      //������ڶ�λԪ��ǰ�Ƹ��ǵ���һλ�ظ���Ԫ��
		L->length--;
	}
}

SqList MergeSq(SqList A, SqList B) {               //����������˳���ϲ�Ϊһ���µ�����˳���
	int i, j, k, length;
	SqList C;
	if (A->length + B->length > C->maxsize)
		return false;
	for (i = 0, j = 0, k = 0; i < A->length && j < B->length; ) {              //������˳����н�С��ֵ����
		if (A->data[i] < B->data[j])
			C->data[k++] = A->data[i++];
		else
			C->data[k++] = B->data[j++];
	}
	if (A->length > B->length)                                                //��δ�ϲ���ı�����±�
		for (k = k + 1, i = i + 1; i < A->length; i++, k++) 
			C->data[k] = A->data[i];
	else
		for (k = k + 1; j < B->length; j++, k++)
			C->data[k] = B->data[j];
	C->length = k;
	return C;
}

void SwitchToFront(SqList L,int m,int n) {      //һά����L[m+n]�����δ���������Ա�(a1��am��b1��bn)
	int i, j, temp;                             //��b1��bm����a1��amǰ��
	for (i = 0, j = m; i < m && j < m + n; i++, j++) {   //��������˳���λ�ã�ֱ���϶̵�˳��������
		temp = L->data[i];
		L->data[i] = L->data[j];
		L->data[j] = temp;
	}
	if (m > n) {                                  //��ʣ�µ�δ�������˳����ڲ�����
		for (j = m; j < m + n; i++, j++) {
			temp = L->data[i];
			L->data[i] = L->data[j];
			L->data[j] = temp;
		}
	}
	else if(m<n){
		for (j = m; j < m + n; i++, j++) {
			temp = L->data[i];
			L->data[i] = L->data[j];
			L->data[j] = temp;
		}
	}
}

void LocateSwitchNext(SqList L,int x) {    //�ҵ�ֵΪx��Ԫ�أ����ҵ��ͽ�������Ԫ��λ�ý��� 
	int i, j, temp;                        //���Ҳ����ͽ��䰴�����
	for (i = 0; i < L->length; i++)        //�ҵ�x��λ�ã���������Ԫ�ؽ���
		if (L->data[i] == x) {
			temp = L->data[i];
			L->data[i] = L->data[i + 1];
			L->data[i + 1] = L->data[i];
			break;
		}
	if (i == L->length) {                 //���Ҳ���x���������
		for (i = 0; L->data[i]< x; i++);  //��λxӦ����λ��
		for (j=L->length; j>i-1; j--)     //����λ��Ԫ�ؼ���֮��Ԫ��ȫ������
			L->data[j] = L->data[j - 1];
		L->data[i] = x;
	}

}

