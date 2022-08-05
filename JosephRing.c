/*
 *
 * 约瑟夫环
 * 已知n个人围在一个圆桌周围,从编号为k的人开始报数,数到m的人出列
 * 然后剩下的人从一接着开始,最后一个人为胜者
 *
 */
#include<stdio.h>
#include<stdlib.h>

// 循环单链表
typedef struct LNode {
	int data;
	struct LNode *next;
}LNode , *LList;

// 初始化
LList InitList(int n) {
	LNode * s = NULL;
	LNode *tail = (LNode *) malloc (sizeof(LNode));
	tail->data = n; tail->next = tail;	//表头
	for(int i = n-1; i > 0; i--) {
		s = (LNode *) malloc (sizeof(LNode));
		s->data = i;
		s->next = tail->next;
		tail->next = s;		//顺序插入
		s = tail;
	}
	return tail;
}

void Insert(LNode *L, int num) {
	while(L->data != num) 
		L = L->next;
	LNode *s = (LNode *) malloc (sizeof(LNode));
	s->data = 0;
	s->next = L->next;
	L->next = s;
}

void Print(LNode *L, int size) {
	for(int i = 0; i < size; i++ ){
		printf("%d ",L->data);
		L = L->next;
	}
	printf("\n");
}

void Select(LNode *L, int key) {
	LNode *tail; LNode *p;
	tail = L; p = L->next;
	int count = 1;
	while(tail->next != tail) {
		if(count != key) {
			tail = p;
			p = p->next;
			count++;
		}
		else {
			tail->next = p->next;
			printf("%d ",p->data);
			free(p);
			p = tail->next;
			count = 1;
		}
	}
	printf("\nThe winer is:%d\n",tail->data);
}

int main(void) {
	printf("This is a test of JosephRing.\n");
	LList L = NULL;

	int num, key;
	printf("Please input size of Ring:");
	scanf("%d",&num);

	L = InitList(num);
	Print(L, num);
	printf("Please input the key number of this test\n:");
	scanf("%d",&key);
	Select(L, key);
	return 0;
}
