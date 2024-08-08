#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct list//节点
{
	int data;
	list* next;
}list;

list* initlist()//初始化单链表
{
	list* L = (list*)malloc(sizeof(list));
	L->data = 0;
	L->next = NULL;
	return L;
}

void headadd(list* L, int data)//头节点插入
{
	list* node = (list*)malloc(sizeof(list));
	node->data = data;
	node->next = L->next;
	L->next = node;
	L->data++;
}

void tailadd(list* L, int data)//尾节点插入
{
	list* node = L;
	for (int i = 0; i < L->data; i++)
	{
		node = node->next;
	}
	list* p = (list*)malloc(sizeof(list));
	p->data = data;
	p->next = NULL;
	node->next = p;
	L->data++;
}

void deletelist(list* L, int data)//删除元素
{
	list* prenode = L;
	list* node = L->next;
	while (node)
	{
		if (node->data == data)
		{
			prenode->next = node->next;
			free(node);
			L->data--;
			return;
		}
		prenode = node;
		node = node->next;
	}
}

void printlist(list* L)//打印单链表
{
	list* P= L->next;
	while (P)
	{
		printf("%d ", P->data);
		P = P->next;
	}
}

int main()
{
	list* L = initlist();
	tailadd(L,1 );
	tailadd(L, 2);
	tailadd(L, 3);
	tailadd(L, 4);
	tailadd(L, 5);
	tailadd(L,6 );
	tailadd(L, 7);
	headadd(L,10 );
	deletelist(L, 1);
	printlist(L);
	return 0;
}
