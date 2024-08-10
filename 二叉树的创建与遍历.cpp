#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct treenode//Ê÷½Úµã
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
		*T=NULL;
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
	if (T==NULL)
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

void postorder(treenode* T)
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

int main()
{
	treenode* T;
	int index = 0;
	char ch[] = { 'A','B','D','#','#','E','#','#','C','#','#'};
	createtree(&T, ch, &index);
	preorder(T);
	printf("\n");
	inorder(T);
	printf("\n");
	postorder(T);
	printf("\n");
	return 0;
}