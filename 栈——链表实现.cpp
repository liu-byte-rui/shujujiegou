#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
typedef struct list//节点
{
	int data;
	list* next;
}list;

list* initlist()
{
	list* L = (list*)malloc(sizeof(list));
	L->data = 0;
	L->next = NULL;
	return L;
}

void push(list* head, int data)//入栈
{
	list* node = (list*)malloc(sizeof(list));
	node->data = data;
	node->next = head->next;
	head->next = node;
	head->data++;
}

int pop(list* head)//出栈
{
	list* node = head->next;
	int p = node->data;
	head->next = node->next;
	free(node);
	head->data--;
	return p;
}
void printlist(list* head)
{
	list* p = head->next;
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}

int main()
{
	list* head = initlist();
	push(head,1);
	push(head,2);
	push(head,3);
	push(head,4);
	push(head,5);
	push(head,6);
	push(head,7);
	push(head,8);
	push(head,9);
	push(head,10);
	pop(head);
	pop(head);
	printlist(head);
}

