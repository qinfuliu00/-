#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"LinkList.h"

int main()
{

}

void DeleteRecursion(LinkList L,ElemType x) {     //删除不带头结点的单链表L中的所有值为x的结点
	LNode* p = L, * q;
	if (p->data == x) {
		q = p->next;
		free(p);
		p = q;
		DeleteRecursion(L, x);
	}
	else if (p->data != x)
		DeleteRecursion(L, x);
	else if (p = NULL)
		return;
}

void DeleteHead(LinkList L, ElemType x) {        //在带头结点的单链表L中，删除所有值为x的结点
	LNode* p, * q;
	for (p = L->next; p = NULL; p = p->next)     //p指向单链表的第一个结点
		if (p->data == x) {
			q = p->next;                         //q指向要删除节点的下一个结点
			L->next = q;                         //头结点指向p，防止断链
			free(p);
		}
}

void AdverseOut(LinkList L) {                             //设L为带头结点的单链表，从尾到头反向输出每个结点值
	LNode* p = L->next, * q = p->next;
	L->next = NULL;
	while (p != NULL) {                                   //采用头插法将L逆置
		p->next = L->next;
		L->next = p;
		p = q;                                            
		q = p->next;
	}
	for (p = L->next; p != NULL; p = p->next)             //依次输出L中每个结点的值
		printf("%d ", p->data);
}

void DeleteMin(LinkList L) {                            //在带头结点的单链表L中删除一个最小值结点
	LNode* pre, * p, * min;
	for (pre = L->next, p = L->next->next,min=pre;      //找到最小值所在结点min
		p != NULL; pre=pre->next,p=pre->next) 
		if (p->data > min->data) 
			min = p;
	pre->next = min->next;
	free(min);
}

void Reverse(LinkList L) {                  //将带头结点的单链表就地逆置
	LNode* p, * q;
	for (p = L->next, q = p->next, L->next = NULL; 
		p != NULL; p=q,q=q->next) {
		p->next = L->next;
		L->next = p;
	}
}

void SortAscend(LinkList L) {           //使带头结点的单链表L元素递增有序
	LNode* pre, * max, * p;
	LNode* head=L->next;
	pre = L->next;
	p = pre->next;
	L->next = NULL;             //将头结点拆下
	max = pre;
	while (p != NULL) {
		pre = head;
		p = pre->next;
		max = pre;
		while (p != NULL) {          //找到当前最大值所在结点;
			if (p->data > max)
				max = p;
			pre = pre->next;
			p = pre->next;
		}
		pre->next = p->next;        //将最小值所在结点从原链表中断开
		max->next = L->next;        //采用头插法将最大值所在结点链入L之后
		L->next = max;
	}
}

void DeleteBetween(LinkList L, int s, int t) {    //在一个无序单链表中，删除给定两个值间的所有元素
	LNode* pre, * p;
	pre = L;
	p = pre->next;
	while (p != NULL) {
		if (p->data > s && p->data < t) {         //找到范围间的元素并删除
			pre->next = p->next;
			free(p);
		}
		pre = pre->next;
		p = pre->next;
	}
}

bool GetPublic(LinkList A, LinkList B) {             //找出两个链表的公共结点
	LNode* p, * q, * pub;                            //p指向A，q指向p，pub指向公共结点
	for (p = A; p != NULL;p=p->next) 
		for (q = B; q != NULL; q = q->next) 
			if (p->next == q->next) {                //找到公共结点
				pub = p->next;
				break;
			}
	return false;                                   //没有公共结点，返回false
}

void AscendOutFree(LinkList L) {         //按递增次序输出单链表中各结点数据元素，并释放其存储空间
	SortAscend(L);                       //利用头结点将单链表递增有序
	while (L != NULL) {
		printf("%d ", L->data);
		L = L->next;
	}
	free(L);
}

void Spilt(LinkList L) {           //将L分解为A、B两个带头结点的单链表
	LinkList A, B;                 //A中含有原表中序号为奇数的元素,B中含有原表中序号为偶数的元素
	LNode* p = L->next, * pre = L; //保持其相对顺序不变
	LNode* pa = A, * pb = B;
	int count=1;
	A->next = NULL;   //建立A链表的头结点
	B->next = NULL;   //建立B链表的头结点
	while (p != NULL) {
		if((count % 2) != 0) {        //奇数位通过尾插法插入A链表
			pre->next = p->next;      //将p从L中断开
			pa->next = p;
			pa = p;
			p = pre->next;
			count++;
		}
		else {                        //偶数位通过尾插法插入B链表
			pre->next = p->next;      //将p从L中断开
			pb->next = p;
			pb = p;
			p = pre->next;
			count++;
		}
	}
}

void SpiltSitu(LinkList hc) {        //将单链表hc分解为两个线性表
	LinkList A, B;                   //A维持原本相对顺序，B采用逆序
	LNode* pre = hc, * p = pre->next, * pa = A;
	int count = 1;
	A->next = NULL;
	B->next = NULL;
	while (p != NULL) {
		pre->next = p->next;   //将当前要分解的结点断链
		if (count % 2 != 0) {  //A表采用尾插法插入，保持相对顺序不变
			pa->next = p;
			pa = p;
		}
		if (count % 2 == 0) {  //B表采用头插法,使得B表尾逆序
			p->next = B->next;
			B->next = p;
		}
		p = pre->next;
		count++;
	}
}

void DeleteRepeat(LinkList L) {                 //在一个递增有序的单链表中去掉数值相同的元素
	LNode* p, * pre;
	int temp;
	for (pre = L, p = pre->next; p != NULL;     //按序查找数值相同的元素
		pre = pre->next, p = pre->next) 
		if (pre->data == p->data) {             //将第二个数值相同的元素释放
			pre->next = p->next;
			free(p);
		}
}

void MergeToDesc(LinkList A, LinkList B) {              //将两个升序单链表以原表结点按降序合并
	LNode* qa, * pa, * qb, * pb;
	for (qa = A->next, qb = B->next,A->next=NULL;      //依次分别遍历两个单链表
		qa != NULL && qb != NULL;) {
		if (qa->data < qb->data) {                     //采取头插法依次对比两个线性表
			pa = qa->next;							   //将将小的结点链入A后
			qa->next = A->next;
			A->next = qa;
			qa = pa;
		}
		else {
			pb = qb->next;
			qb->next = B->next;
			B->next = qb;
			qb = pb;
		}
	}
	if (qa != NULL) {                                  //若两个单链表还有剩余，将其链入A表之后
		for (pa = A->next; pa != NULL; pa = pa->next);
		pa->next = qa;
	}
	if (qb != NULL) {
		for (pb = B->next; pb != NULL; pb = pb->next);
		pb->next = qb;
	}
}

void PubToNew(LinkList A, LinkList B) {             //从两个升序的单链表中找到公共结点并产生链表C
	LNode* pa, * pb, * prea, * preb;
	LinkList C=(LinkList)malloc(sizeof(LinkList));
	C->next = NULL;
	for (prea=A,pa = A->next, pb = B->next;                //依次对比A链表和B链表，寻找是否有公共结点
		pb != NULL;pb=pb->next,prea=A->next,pa=prea->next) {
		while (pa != NULL) {
			if (pa->next != pb->next)
				pa = pa->next;
			else                                   //找到公共结点，结点为pa的下一个结点
				break;
		}
	}
	if (pb == NULL)
		return false;
	C->next = pa;                                   	//将pa链入C之后
}

void PubEleToNew(LinkList A, LinkList B) {             //从A和B中的公共元素产生单链表C，并不破坏A、B的结点
	LNode* pa, * pb, * s, * r;
	LinkList C=(LinkList)malloc(sizeof(LNode));        //初始化链表C
	for (pa = A->next, pb = B->next,r=C; 
		 pb != NULL;) {
		while (pa != NULL) 
			if (pa->data == pb->data)
				break;
		s = (LNode*)malloc(sizeof(LNode));            //初始化一个新结点，并赋值公共元素链入C
		s->data = pa->data;
		C->next = s;
		r = s;
	}
	if (pb == NULL)
		return false;
	r->next = NULL;                                  //C链表末尾置NULL
}

bool JudgeSeira(LinkList A, LinkList B) {           //两个整数序列，判断B序列是否是序列A的连续子序列
	LNode* pa = A, * pb = B, * prea = A;
	while (pa != NULL && pb != NULL) {
		if (pa->data = pb->data) {                  //若两个链表有元素相等,开始逐个对比
			pa = pa->next;
			pb = pb->next;
		}
		else {                                     //若出现不相等,从A上次开始比较的后继结点开始
			prea = prea->next;
			pa = prea;
			pb = B;
		}
		if (pb == NULL)
			return true;
		else
			return false;
	}
}

bool JudgeSym(DLinkList L) {                                //判断带头结点的循环双链表是否对称
	DNode* pre, * p;

	for (pre = L->prior, p = L->next; p->next!= pre;) {          //p从正向遍历,pre后向遍历
		if (p == pre) {
			p = p->next;
			pre = pre->prior;
		}
		else
			return false;
	}
	return true;

}

void MergeCycle(LinkList h1, LinkList h2) {                //合并两个循环单链表
	LNode* prh1, * prh2;
	for (prh1 = h1; prh1->next != h1; prh1 = prh1->next);         //prh1指向h1尾结点
	for (prh2 = h2; prh2->next != h2; prh2 = prh1->next);         //phr2指向h2尾结点
	prh2->next = h1;                                              //h2尾结点指向h1头结点
	prh1->next = h2->next;                                        //h1尾结点指向h2第一个结点
	h2->next = NULL;                                              //断开h2头结点
	free(h2);
}

void CycleDeleteMin(LinkList L) {             //反复删除单链表中最小的结点并输出
	LNode* pre, * p, * min, * minpre;
	while (L->next != NULL) {
		p = L->next;
		pre = L;
		min = p;
		minpre = pre;
		while (p != NULL) {                  //找到最小值结点和其前驱
			if (p->data < min->data) {
				min = p;
				minpre = pre;
			}
			pre = pre->next;
			p = pre->next;
		}
		printf("%d ", min->data);
		minpre->next = min->next;              //删除最小值结点
		free(min);
	}
	free(L);                                   //最后删除头结点
}

