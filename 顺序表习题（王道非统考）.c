#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"SequenceList.h"

int main()
{

}

ElemType DeleteMin(SqList L) {   //从顺序表中删除具有最小值的元素（假设唯一），并返回其值
	ElemType min = L->data[0];
	ElemType i, j;

	if (L->length <= 0)
		return false;
	for (j = 0; j < L->length; j++) {   //顺序查找最小值
		if (L->data[j] < min) {             //min保存最小值
			min = L->data[j];
			i = j;                          //i记录最小值位置
		}
	}
	L->data[i] = L->data[j];  //用最后一个元素填补空出位
	L->length--;
	return min;
}

void Reverse(SqList L) {    //将顺序表逆置 ，要求空间复杂度为o（1）
	int i, j, temp;
	for (i = 0,j=L->length; i+1==j; i++,j--) {
		temp = L->data[i];
		L->data[i] = L->data[j];
		L->data[j] = temp;
	}
}

void DeleteDesignation(SqList L, int x) {     //删除线性表中所以值为x的数据元素
	int i;
	for (i = 0; i < L->length; i++) {
		if (L->data[i] == x) {
			L->data[i] = L->data[L->length];     //用线性表最后一个元素替代被删除元素
			L->length--;                         //线性表长度减1
			i--;                                 //将检索位置后移一位，从替代元素继续查询
		}
	}
} 

void DeleteBetween(SqList L, int s, int t) {     //删除值在s与t之间的所有元素
	int i, j, k = 0;
	if (s >= t||L==NULL)
		return false;
	for (i = 0; i < L->length; i++) {           //顺序查找
		if (L->data[i] > s && L->data[i] < t)    //若位置i处的值位于s与t之间
			k++;
		else
			L->data[i - k] = L->data[i];    //当前元素前移k个位置  
	}
	L->length -= k;
}

void DeleteSqBetween(SqList L, int s, int t) {     //从有序顺序表中删除其值在给定值s与t之间的所有元素(包含s和t,s<t）
	int i, j;
	if (s >= t || L == NULL)
		return false;
	for (i = 0; L->data[i] < s; i++);             //找到有序顺序表中第一个大于等于s值的位置
	for (j = i; L->data <= t; j++);               //找到有序顺序表中第一个大于等于t值的位置
	for (; i < L->length; i++,j++) {                  //将有序顺序表中符合要求的位置删除
		L->data[i] = L->data[j];
		L->length--;
	}
		
}

void DeleteSqRepeat(SqList L) {              //从有序顺序表中删除所有其值重复的元素;
	int i, j;
	for (i = 0; i < L->length; i++) {
		if (L->data[i] == L->data[i + 1])         //若当前元素值等于后一位元素值
			L->data[i + 1] = L->data[i + 2];      //将后面第二位元素前移覆盖掉后一位重复的元素
		L->length--;
	}
}

SqList MergeSq(SqList A, SqList B) {               //将两个有序顺序表合并为一个新的有序顺序表
	int i, j, k, length;
	SqList C;
	if (A->length + B->length > C->maxsize)
		return false;
	for (i = 0, j = 0, k = 0; i < A->length && j < B->length; ) {              //将两个顺序表中较小的值存入
		if (A->data[i] < B->data[j])
			C->data[k++] = A->data[i++];
		else
			C->data[k++] = B->data[j++];
	}
	if (A->length > B->length)                                                //将未合并完的表加入新表
		for (k = k + 1, i = i + 1; i < A->length; i++, k++) 
			C->data[k] = A->data[i];
	else
		for (k = k + 1; j < B->length; j++, k++)
			C->data[k] = B->data[j];
	C->length = k;
	return C;
}

void SwitchToFront(SqList L,int m,int n) {      //一维数组L[m+n]中依次存放两个线性表(a1到am和b1到bn)
	int i, j, temp;                             //将b1到bm放在a1到am前面
	for (i = 0, j = m; i < m && j < m + n; i++, j++) {   //交换两个顺序表位置，直到较短的顺序表交换完成
		temp = L->data[i];
		L->data[i] = L->data[j];
		L->data[j] = temp;
	}
	if (m > n) {                                  //将剩下的未交换完的顺序表内部逆置
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

void LocateSwitchNext(SqList L,int x) {    //找到值为x的元素，若找到就将其与后继元素位置交换 
	int i, j, temp;                        //若找不到就将其按序插入
	for (i = 0; i < L->length; i++)        //找到x的位置，并与其后继元素交换
		if (L->data[i] == x) {
			temp = L->data[i];
			L->data[i] = L->data[i + 1];
			L->data[i + 1] = L->data[i];
			break;
		}
	if (i == L->length) {                 //若找不到x，将其插入
		for (i = 0; L->data[i]< x; i++);  //定位x应插入位置
		for (j=L->length; j>i-1; j--)     //将定位处元素及其之后元素全部后移
			L->data[j] = L->data[j - 1];
		L->data[i] = x;
	}

}

