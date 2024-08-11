#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct treenode//树节点
{
	char data;
	treenode* lchild;
	treenode* rchild;
	int ltag;
	int rtag;
}treenode;

void createtree(treenode** T, char* data, int* index)//创建树
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
		(*T)->ltag = 0;
		(*T)->rtag = 0;
		createtree(&((*T)->lchild), data, index);
		createtree(&((*T)->rchild), data, index);
	}
}


void inthread(treenode* T,treenode** pre)//二叉树中序线索化
{
	if (T)
	{
		inthread(T->lchild,pre);
		if (T->lchild == NULL)
		{
			T->lchild = *pre;
			T->ltag = 1;
		}
		if ((*pre)!= NULL && (*pre)->rchild ==NULL)
		{
			(*pre)->rchild = T;
			(*pre)->rtag = 1;
		}
		*pre = T;
		inthread(T->rchild,pre);
	}
}

treenode* getfirst(treenode* T)
{
	while (T->ltag == 0)
	{
		T = T->lchild;
	}
	return T;
}

treenode* getnext(treenode* T)
{
	if (T->rtag == 1)
	{
		return T->rchild;
	}
	else
	{
		return getfirst(T->rchild);
	}

}

int main()
{
	treenode* T;
	treenode* pre = NULL;
	int index = 0;
	char ch[] = { 'A','B','D','#','#','E','#','#','C','#','#' };
	createtree(&T, ch, &index);
	inthread(T, &pre);
	pre->rtag = 1;
	pre->rchild = NULL;
	treenode* node = NULL;
	for(node=getfirst(T); node != NULL; node = getnext(node))
	{
		printf("%c ", node->data);
	}
	printf("\n");
	return 0;
}