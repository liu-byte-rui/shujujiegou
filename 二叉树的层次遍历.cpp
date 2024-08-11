#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct treenode//���ڵ�
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

typedef struct queue//��������
{
	treenode* data;
	queue* pre;
	queue* next;
}queue;

queue* initqueue()//��ʼ����
{
	queue* Q = (queue*)malloc(sizeof(queue));
	Q->data = NULL;
	Q->pre = Q;
	Q->next = Q;
	return Q;
}

void enqueue(queue* Q, treenode* data)//���
{
	queue* node = (queue*)malloc(sizeof(queue));
	node->data = data;
	node->next = Q;
	node->pre = Q->pre;
	Q->pre->next = node;
	Q->pre = node;
}

int isempty(queue* Q)//�ж϶����Ƿ�Ϊ��
{
	if (Q->next == Q)
	{
		return 1;
	}
	else
		return 0;
}

treenode* dequeue(queue* Q)//����
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

void level(queue* Q, treenode* T)//��α���
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


void preorder(treenode* T)//ǰ�����
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