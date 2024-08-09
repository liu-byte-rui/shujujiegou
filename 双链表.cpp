#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

typedef struct list//节点
{
	int data;
	list* pre;
	list* next;
}list;

list* initlist()//初始化
{
	list* L = (list*)malloc(sizeof(list));
	L->data = 0;
	L->next = NULL;
	L->pre = NULL;
	return L;
}

void headadd(list* L, int data)//头节点插入
{
	list* node = (list*)malloc(sizeof(list));
	node->data = data;
	node->next = L->next;
	L->next->pre = node;
	node->pre = L;
	L->next = node;
	L->data++;
}

void tailadd(list* L, int data)//尾节点插入
{
	list* p = L;
	while (p->next != NULL)
	{
		p = p->next;
	}
	list* node = (list*)malloc(sizeof(list));
	node->data = data;
	node->next = NULL;
	node->pre = p;
	p->next = node;
	L->data++;
}

void deletelist(list* L, int data)//删除节点
{
	list* node = L->next;
	while (node->next != NULL)
	{
		if (node->data == data)
		{
			node->pre->next = node->next;
			node->next->pre = node->pre;
			free(node);
			L->data--;
			return;
		}
		node = node->next;
	}
}

void printlist(list* L)//遍历链表
{
	list* P = L->next;
	while (P)
	{
		printf("%d ", P->data);
		P = P->next;
	}
}
int main()
{
	list* L = initlist();
	tailadd(L,1);
	tailadd(L,2);
	tailadd(L,3);
	tailadd(L,4);
	tailadd(L,5);
	tailadd(L,6);
	tailadd(L,7);
	tailadd(L,8);
	deletelist(L, 3);
	headadd(L,10);
	printlist(L);
	return 0;
}