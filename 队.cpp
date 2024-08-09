#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
typedef struct list//节点
{
	int data;
	list* next;
}list;

list* initlist()//初始化
{
	list* L = (list*)malloc(sizeof(list));
	L->data = 0;
	L->next = NULL;
	return L;
}

void enqueue(list* L, int data)//入队
{
	list* p = L;
	while (p->next != NULL)
	{
		p = p->next;
	}
	list* node = (list*)malloc(sizeof(list));
	node->data = data;
	node->next = NULL;
	p->next = node;
	L->data++;
}

int dequeue(list* L)//出队
{
	list* p = L->next;
	L->next = p->next;
	int q = p->data;
	free(p);
	return q;
}

void printlist(list* L)//遍历
{
	list* p = L->next;
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}

int main()
{
	list* L = initlist();
	enqueue(L,1);
	enqueue(L,2);
	enqueue(L,3);
	enqueue(L,4);
	enqueue(L,5);
	enqueue(L,6);
	enqueue(L,7);
	enqueue(L,8);
	dequeue(L);
	printlist(L);
}