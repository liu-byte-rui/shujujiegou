#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct treenode//���ڵ�
{
	char data;
	int tag;
	treenode* lchild;
	treenode* rchild;
}treenode;

void createtree(treenode** T, char* data, int* index)//������
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
		(*T)->tag = 0;
		createtree(&((*T)->lchild), data, index);
		createtree(&((*T)->rchild), data, index);
	}
}

void postorder(treenode* T)//����ݹ����
{
	if (T == NULL)
	{
		return;
	}
	else
	{
		postorder(T->lchild);
		postorder(T->rchild);
		printf("%c ", T->data);
	}
}

typedef struct stacknode
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

stacknode* gettop(stacknode* S)
{
	if (isempty(S))
	{
		return NULL;
	}
	else
	{
		stacknode* node = S->next;
		return node;
	}
}

void  postorde(treenode* T)
{
	treenode* node = T;
	stacknode* S = initstack();
	while (node || (!isempty(S)))
	{
		if (node)
		{
			enstack(S, node);
			node = node->lchild;
		}
		else
		{
			treenode* top = gettop(S)->data;
			if (top->rchild && top->rchild->tag == 0)
			{
				top = top->rchild;
				enstack(S, top);
				node = top->lchild;
			}
			else
			{
				top = destack(S);
				printf("%c ", top->data);
				top->tag = 1;
			}
		}
	}
}

int main()
{
	treenode* T;
	int index = 0;
	char ch[] = { 'A','B','#','#','C','#','#' };
	createtree(&T, ch, &index);
	//postorder(T);
	//printf("\n");
	postorde(T);
	printf("\n");
	return 0;
}