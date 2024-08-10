#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stying
{
	char* data;
	int len;
}string;

string* initstring()//初始化
{
	string* S = (string*)malloc(sizeof(string));
	S->data = NULL;
	S->len = 0;
	return S;
}

void stringassign(string* S, char* data)//为字符串赋值
{
	if (S->data)
	{
		free(S->data);
	}
	char* temp = data;
	int len = 0;
	while (*temp)
	{
		len++;
		temp++;
	}
	if (len == 0)
	{
		S->data = NULL;
		S->len = 0;
	}
	else
	{
		S->len = len;
		temp = data;
		S->data = (char*)malloc(sizeof(char) * (len + 1));
		for (int i = 0; i < len; i++)
		{
			S->data[i] = temp[i];
		}
	}
}



void printstring(string* S)
{
	for (int i = 0; i < S->len; i++)
	{
		printf("%c ", S->data[i]);
	}
	printf("\n");
}

int* getnext(string* L)
{
	int* next = (int*)malloc(sizeof(int) * L->len);
	int i = 0;
	int j = -1;
	next[i] = j;
	while (i < L->len - 1)
	{
		if (j == -1 || L->data[i] == L->data[j])
		{
			i++;
			j++;
			next[i] = j;
		}
		else
			j = next[j];
	}
	return next;
}

void KMP(string* L, string* sub)
{
	int* next = getnext(sub);
	int i = 0;
	int j = 0;
	while (i < L->len && j < sub->len)
	{
		if (L->data[i] == sub->data[j]||j==-1)
		{
			i++;
			j++;
		}
		else
		{
				j = next[j];
		}
	}
	if (j == sub->len)
	{
		printf("force match success\n");
	}
	else
	{
		printf("force match false\n");
	}
}
int main()
{
	string* S = initstring();
	string* sub = initstring();
	char ch[6] = { 'A','B','A','B','C' };
	char sh[4] = { 'A','B','C' };
	stringassign(S, ch);
	stringassign(sub, sh);
	printstring(S);
	printstring(sub);
	KMP(S, sub);
}
