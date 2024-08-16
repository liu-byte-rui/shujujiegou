#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct treenode//树节点
{
	char data;
	treenode* lchild;
	treenode* rchild;
	treenode* parent;
	int ltag;
	int rtag;
}treenode;

void createtree(treenode** T, char* data, int* index,treenode* parent)//创建树
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
		(*T)->parent = parent;
		createtree(&((*T)->lchild), data, index,*T);
		createtree(&((*T)->rchild), data, index,*T);
	}
}


void postthread(treenode* T, treenode** pre)//二叉树后序线索化
{
	if (T)
	{
		postthread(T->lchild, pre);
		postthread(T->rchild, pre);
		if (T->lchild == NULL)
		{
			T->lchild = *pre;
			T->ltag = 1;
		}
		if ((*pre) != NULL && (*pre)->rchild == NULL)
		{
			(*pre)->rchild = T;
			(*pre)->rtag = 1;
		}
		*pre = T;
	}
}

treenode* getfirst(treenode* T)
{
	while (T->ltag == 0)
	{
		T = T->lchild;
	}
	if (T->rtag == 0)
	{
		return getfirst(T->rchild);
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
		if (T->parent->rchild == T)//右孩子
		{
			return T->parent;
		}
		else if (T->parent == NULL)//根节点
		{
			return NULL;
		}
		else//左孩子
		{
			if (T->parent->rtag == 1)
			{
				return T->parent;
			}
			else
			{
				return getfirst(T->parent->rchild);
			}
		}
	}

}

int main()
{
	treenode* T;
	treenode* pre = NULL;
	int index = 0;
	char ch[] = { 'A','B','D','#','#','E','#','#','C','#','#' };
	createtree(&T, ch, &index,NULL);
	postthread(T, &pre);
	treenode* node = NULL;
	for (node = getfirst(T); node != NULL; node = getnext(node))
	{
		printf("%c ", node->data);
	}
	printf("\n");
	return 0;
}