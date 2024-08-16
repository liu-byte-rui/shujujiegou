#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct treenode
{
	int data;
	treenode* lchild;
	treenode* rchild;
}treenode;

void bstinsert(treenode** T, int data)
{
	if ((*T) == NULL)
	{
		*T = (treenode*)malloc(sizeof(treenode));
		(*T)->data = data;
		(*T)->lchild = NULL;
		(*T)->rchild = NULL;
	}
	else
	{
		if (data < (*T)->data)
		{
			bstinsert(&((*T)->lchild), data);
		}
		else if (data == (*T)->data)
		{
			return;
		}
		else 
		{
			bstinsert(&((*T)->rchild), data);
		}
	}
}

void preorder(treenode* T)
{
	if (T)
	{
		printf("%d ", T->data);
		preorder(T->lchild);
		preorder(T->rchild);
	}
}

int main()
{
	treenode* T=NULL;
	int num[6] = { 4,5,19,23,2,8 };
	for (int i = 0; i < 6; i++)
	{
		bstinsert(&T, num[i]);
	}
	preorder(T);
	printf("\n");
	return 0;
}