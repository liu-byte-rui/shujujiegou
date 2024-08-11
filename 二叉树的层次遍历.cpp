#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct treenode//树节点
{
	char data;
	treenode* lchild;
	treenode* rchild;
}treenode;

void createtree(treenode** T, char* data, int* index)
{
	char ch;
	ch = data[*index];
	*index += 1;
	if (ch == '#')
	{
		*T = NULL;
	}
	else
	{
		*T = (treenode*)malloc(sizeof(treenode));
		(*T)->data = ch;
		createtree(&((*T)->lchild), data, index);
		createtree(&((*T)->rchild), data, index);
	}
}

typedef struct queue//创建队列
{
	treenode* data;
	queue* pre;
	queue* next;
}queue;

queue* initqueue()//初始化队
{
	queue* Q = (queue*)malloc(sizeof(queue));
	Q->data = NULL;
	Q->pre = Q;
	Q->next = Q;
	return Q;
}

void enqueue(queue* Q, treenode* data)//入队
{
	queue* node = (queue*)malloc(sizeof(queue));
	node->data = data;
	node->next = Q;
	node->pre = Q->pre;
	Q->pre->next = node;
	Q->pre = node;
}

int isempty(queue* Q)//判断队列是否为空
{
	if (Q->next == Q)
	{
		return 1;
	}
	else
		return 0;
}

treenode* dequeue(queue* Q)//出队
{
	if (!isempty(Q))
	{
		queue* q = Q->next;
		q->next->pre = Q;
		Q->next = q->next;
		return q->data;
	}
	else
		return NULL;
}

void level(queue* Q, treenode* T)//层次遍历
{
	enqueue(Q, T);
	while (!isempty(Q))
	{
		treenode* node = dequeue(Q);
		printf("%c ", node->data);
		if (node->lchild)
		{
			enqueue(Q, node->lchild);
		}
		if (node->rchild)
		{
			enqueue(Q, node->rchild);
		}
	}
}


void preorder(treenode* T)//前序遍历
{
	if (T == NULL)
	{
		return;
	}
	else
	{
		printf("%c ", T->data);
		preorder(T->lchild);
		preorder(T->rchild);
	}
}


int main()
{
	treenode* T;
	int index = 0;
	char ch[] = { 'A','B','D','#','#','E','#','#','C','F','#','#','G','#','#'};
	createtree(&T, ch, &index);
	preorder(T);
	printf("\n");
	queue* Q = initqueue();
	level(Q, T);
	return 0;
}