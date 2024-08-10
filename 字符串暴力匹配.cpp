#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stying
{
	char* data;
	int len;
}string;

string* initstring()//³õÊ¼»¯
{
	string* S = (string*)malloc(sizeof(string));
	S->data = NULL;
	S->len = 0;
	return S;
}

void stringassign(string* S,char* data)//Îª×Ö·û´®¸³Öµ
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

void stringmatch(string* S, string* sub)//±©Á¦Æ¥Åä
{
	if (sub->data == NULL||S->data==NULL)
	{
		printf("false");
	}
	else
	{
		int i = 0;
		int j = 0;
		while (i < S->len && j < sub->len)
		{
			if (S->data[i] == sub->data[j])
			{
				i++;
				j++;
			}
			else
			{
				i = i - j + 1;
				j = 0;
			}
		}
		if (j == sub->len)
		{
			printf("force match success");
		}
		else
		{
			printf("force match false");
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
	stringmatch(S, sub);
}