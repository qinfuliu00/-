#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"LinkList.h"

int main()
{

}

void DeleteRecursion(LinkList L,ElemType x) {     //ɾ������ͷ���ĵ�����L�е�����ֵΪx�Ľ��
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

void DeleteHead(LinkList L, ElemType x) {        //�ڴ�ͷ���ĵ�����L�У�ɾ������ֵΪx�Ľ��
	LNode* p, * q;
	for (p = L->next; p = NULL; p = p->next)     //pָ������ĵ�һ�����
		if (p->data == x) {
			q = p->next;                         //qָ��Ҫɾ���ڵ����һ�����
			L->next = q;                         //ͷ���ָ��p����ֹ����
			free(p);
		}
}

void AdverseOut(LinkList L) {                             //��LΪ��ͷ���ĵ�������β��ͷ�������ÿ�����ֵ
	LNode* p = L->next, * q = p->next;
	L->next = NULL;
	while (p != NULL) {                                   //����ͷ�巨��L����
		p->next = L->next;
		L->next = p;
		p = q;                                            
		q = p->next;
	}
	for (p = L->next; p != NULL; p = p->next)             //�������L��ÿ������ֵ
		printf("%d ", p->data);
}

void DeleteMin(LinkList L) {                            //�ڴ�ͷ���ĵ�����L��ɾ��һ����Сֵ���
	LNode* pre, * p, * min;
	for (pre = L->next, p = L->next->next,min=pre;      //�ҵ���Сֵ���ڽ��min
		p != NULL; pre=pre->next,p=pre->next) 
		if (p->data > min->data) 
			min = p;
	pre->next = min->next;
	free(min);
}

void Reverse(LinkList L) {                  //����ͷ���ĵ�����͵�����
	LNode* p, * q;
	for (p = L->next, q = p->next, L->next = NULL; 
		p != NULL; p=q,q=q->next) {
		p->next = L->next;
		L->next = p;
	}
}

void SortAscend(LinkList L) {           //ʹ��ͷ���ĵ�����LԪ�ص�������
	LNode* pre, * max, * p;
	LNode* head=L->next;
	pre = L->next;
	p = pre->next;
	L->next = NULL;             //��ͷ������
	max = pre;
	while (p != NULL) {
		pre = head;
		p = pre->next;
		max = pre;
		while (p != NULL) {          //�ҵ���ǰ���ֵ���ڽ��;
			if (p->data > max)
				max = p;
			pre = pre->next;
			p = pre->next;
		}
		pre->next = p->next;        //����Сֵ���ڽ���ԭ�����жϿ�
		max->next = L->next;        //����ͷ�巨�����ֵ���ڽ������L֮��
		L->next = max;
	}
}

void DeleteBetween(LinkList L, int s, int t) {    //��һ�����������У�ɾ����������ֵ�������Ԫ��
	LNode* pre, * p;
	pre = L;
	p = pre->next;
	while (p != NULL) {
		if (p->data > s && p->data < t) {         //�ҵ���Χ���Ԫ�ز�ɾ��
			pre->next = p->next;
			free(p);
		}
		pre = pre->next;
		p = pre->next;
	}
}

bool GetPublic(LinkList A, LinkList B) {             //�ҳ���������Ĺ������
	LNode* p, * q, * pub;                            //pָ��A��qָ��p��pubָ�򹫹����
	for (p = A; p != NULL;p=p->next) 
		for (q = B; q != NULL; q = q->next) 
			if (p->next == q->next) {                //�ҵ��������
				pub = p->next;
				break;
			}
	return false;                                   //û�й�����㣬����false
}

void AscendOutFree(LinkList L) {         //��������������������и��������Ԫ�أ����ͷ���洢�ռ�
	SortAscend(L);                       //����ͷ��㽫�������������
	while (L != NULL) {
		printf("%d ", L->data);
		L = L->next;
	}
	free(L);
}

void Spilt(LinkList L) {           //��L�ֽ�ΪA��B������ͷ���ĵ�����
	LinkList A, B;                 //A�к���ԭ�������Ϊ������Ԫ��,B�к���ԭ�������Ϊż����Ԫ��
	LNode* p = L->next, * pre = L; //���������˳�򲻱�
	LNode* pa = A, * pb = B;
	int count=1;
	A->next = NULL;   //����A�����ͷ���
	B->next = NULL;   //����B�����ͷ���
	while (p != NULL) {
		if((count % 2) != 0) {        //����λͨ��β�巨����A����
			pre->next = p->next;      //��p��L�жϿ�
			pa->next = p;
			pa = p;
			p = pre->next;
			count++;
		}
		else {                        //ż��λͨ��β�巨����B����
			pre->next = p->next;      //��p��L�жϿ�
			pb->next = p;
			pb = p;
			p = pre->next;
			count++;
		}
	}
}

void SpiltSitu(LinkList hc) {        //��������hc�ֽ�Ϊ�������Ա�
	LinkList A, B;                   //Aά��ԭ�����˳��B��������
	LNode* pre = hc, * p = pre->next, * pa = A;
	int count = 1;
	A->next = NULL;
	B->next = NULL;
	while (p != NULL) {
		pre->next = p->next;   //����ǰҪ�ֽ�Ľ�����
		if (count % 2 != 0) {  //A�����β�巨���룬�������˳�򲻱�
			pa->next = p;
			pa = p;
		}
		if (count % 2 == 0) {  //B�����ͷ�巨,ʹ��B��β����
			p->next = B->next;
			B->next = p;
		}
		p = pre->next;
		count++;
	}
}

void DeleteRepeat(LinkList L) {                 //��һ����������ĵ�������ȥ����ֵ��ͬ��Ԫ��
	LNode* p, * pre;
	int temp;
	for (pre = L, p = pre->next; p != NULL;     //���������ֵ��ͬ��Ԫ��
		pre = pre->next, p = pre->next) 
		if (pre->data == p->data) {             //���ڶ�����ֵ��ͬ��Ԫ���ͷ�
			pre->next = p->next;
			free(p);
		}
}

void MergeToDesc(LinkList A, LinkList B) {              //����������������ԭ���㰴����ϲ�
	LNode* qa, * pa, * qb, * pb;
	for (qa = A->next, qb = B->next,A->next=NULL;      //���ηֱ��������������
		qa != NULL && qb != NULL;) {
		if (qa->data < qb->data) {                     //��ȡͷ�巨���ζԱ��������Ա�
			pa = qa->next;							   //����С�Ľ������A��
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
	if (qa != NULL) {                                  //��������������ʣ�࣬��������A��֮��
		for (pa = A->next; pa != NULL; pa = pa->next);
		pa->next = qa;
	}
	if (qb != NULL) {
		for (pb = B->next; pb != NULL; pb = pb->next);
		pb->next = qb;
	}
}

void PubToNew(LinkList A, LinkList B) {             //����������ĵ��������ҵ�������㲢��������C
	LNode* pa, * pb, * prea, * preb;
	LinkList C=(LinkList)malloc(sizeof(LinkList));
	C->next = NULL;
	for (prea=A,pa = A->next, pb = B->next;                //���ζԱ�A�����B����Ѱ���Ƿ��й������
		pb != NULL;pb=pb->next,prea=A->next,pa=prea->next) {
		while (pa != NULL) {
			if (pa->next != pb->next)
				pa = pa->next;
			else                                   //�ҵ�������㣬���Ϊpa����һ�����
				break;
		}
	}
	if (pb == NULL)
		return false;
	C->next = pa;                                   	//��pa����C֮��
}

void PubEleToNew(LinkList A, LinkList B) {             //��A��B�еĹ���Ԫ�ز���������C�������ƻ�A��B�Ľ��
	LNode* pa, * pb, * s, * r;
	LinkList C=(LinkList)malloc(sizeof(LNode));        //��ʼ������C
	for (pa = A->next, pb = B->next,r=C; 
		 pb != NULL;) {
		while (pa != NULL) 
			if (pa->data == pb->data)
				break;
		s = (LNode*)malloc(sizeof(LNode));            //��ʼ��һ���½�㣬����ֵ����Ԫ������C
		s->data = pa->data;
		C->next = s;
		r = s;
	}
	if (pb == NULL)
		return false;
	r->next = NULL;                                  //C����ĩβ��NULL
}

bool JudgeSeira(LinkList A, LinkList B) {           //�����������У��ж�B�����Ƿ�������A������������
	LNode* pa = A, * pb = B, * prea = A;
	while (pa != NULL && pb != NULL) {
		if (pa->data = pb->data) {                  //������������Ԫ�����,��ʼ����Ա�
			pa = pa->next;
			pb = pb->next;
		}
		else {                                     //�����ֲ����,��A�ϴο�ʼ�Ƚϵĺ�̽�㿪ʼ
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

bool JudgeSym(DLinkList L) {                                //�жϴ�ͷ����ѭ��˫�����Ƿ�Գ�
	DNode* pre, * p;

	for (pre = L->prior, p = L->next; p->next!= pre;) {          //p���������,pre�������
		if (p == pre) {
			p = p->next;
			pre = pre->prior;
		}
		else
			return false;
	}
	return true;

}

void MergeCycle(LinkList h1, LinkList h2) {                //�ϲ�����ѭ��������
	LNode* prh1, * prh2;
	for (prh1 = h1; prh1->next != h1; prh1 = prh1->next);         //prh1ָ��h1β���
	for (prh2 = h2; prh2->next != h2; prh2 = prh1->next);         //phr2ָ��h2β���
	prh2->next = h1;                                              //h2β���ָ��h1ͷ���
	prh1->next = h2->next;                                        //h1β���ָ��h2��һ�����
	h2->next = NULL;                                              //�Ͽ�h2ͷ���
	free(h2);
}

void CycleDeleteMin(LinkList L) {             //����ɾ������������С�Ľ�㲢���
	LNode* pre, * p, * min, * minpre;
	while (L->next != NULL) {
		p = L->next;
		pre = L;
		min = p;
		minpre = pre;
		while (p != NULL) {                  //�ҵ���Сֵ������ǰ��
			if (p->data < min->data) {
				min = p;
				minpre = pre;
			}
			pre = pre->next;
			p = pre->next;
		}
		printf("%d ", min->data);
		minpre->next = min->next;              //ɾ����Сֵ���
		free(min);
	}
	free(L);                                   //���ɾ��ͷ���
}

