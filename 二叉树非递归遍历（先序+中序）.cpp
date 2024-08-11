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

void preorder(treenode* T)
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

void inorder(treenode* T)
{
	if (T == NULL)
	{
		return;
	}
	else
	{
		inorder(T->lchild);
		printf("%c ", T->data);
		inorder(T->rchild);
	}
}

typedef struct stacknode//ջ�ڵ�
{
	treenode* data;
	stacknode* next;
}stacknode;

stacknode* initstack()//��ʼ��ջ
{
	stacknode* S = (stacknode*)malloc(sizeof(stacknode));
	S->data = NULL;
	S->next = NULL;
	return S;
}

void enstack(stacknode* S, treenode* data)//��ջ
{
	stacknode* node = (stacknode*)malloc(sizeof(stacknode));
	node->data = data;
	node->next = S->next;
	S->next = node;
}

int isempty(stacknode* S)//�ж�ջ�Ƿ�Ϊ��
{
	if (S->next == NULL)
	{
		return 1;
	}
	else
		return 0;
}

treenode* destack(stacknode* S)//��ջ
{
	if (isempty(S))
		return NULL;
	else
	{
		stacknode* p = S->next;
		S->next = p->next;
		return p->data;
	}
}

void inorde(treenode* T)//�������
{
	stacknode* S = initstack();
	treenode* node = T;
	while (node || !isempty(S))
	{
		if (node)
		{
			enstack(S, node);
			node = node->lchild;
		}
		else
		{
			node = destack(S);
			printf("%c ", node->data);
			node = node->rchild;
		}
	}
}

void preorde(treenode* T)//�������
{
	stacknode* S = initstack();
	treenode* node = T;
	while (node || (!isempty(S)))
	{
		if (node)
		{
			printf("%c ", node->data);
			enstack(S, node);
			node = node->lchild;
		}
		else
		{
			node = destack(S);
			node = node->rchild;
		}
	}
}

int main()
{
	treenode* T;
	int index = 0;
	char ch[] = { 'A','B','D','#','#','E','#','#','C','#','#' };
	createtree(&T, ch, &index);
	preorder(T);
	printf("\n");
	inorder(T);
	printf("\n");
	preorde(T);
	printf("\n");
	inorde(T);
	printf("\n");
	return 0;
}