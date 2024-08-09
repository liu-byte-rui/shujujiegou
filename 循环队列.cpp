#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXSIZE 20

typedef struct queue
{
	int front;
	int rear;
	int data[MAXSIZE];
}queue;

queue* initqueue()//��ʼ��
{
	queue* Q = (queue*)malloc(sizeof(queue));
	Q->front = Q->rear = 0;
	return Q;
}

int isfull(queue* Q)//�ж϶����Ƿ���
{
	if ((Q->rear + 1) % MAXSIZE == Q->front)
	{
		return 1;
	}
	else
		return 0;
}

void enqueue(queue* Q, int data)//���
{
	if (!isfull(Q))
	{
		Q->data[Q->rear] = data;
		Q->rear = (Q->rear + 1) % MAXSIZE;
	}
	else
	{
		printf("��������");
	}
}

int isempty(queue* Q)//�ж϶����Ƿ�Ϊ��
{
	if (Q->front == Q->rear)
		return 1;
	else
		return 0;
}

void dequeue(queue* Q)//����
{
	if (isempty(Q))
	{
		printf("����Ϊ��");
		return;
	}
	else
	{
		Q->front = (Q->front + 1) % MAXSIZE;
	}
}

void printqueue(queue* Q)//��ӡ����
{
	int length = (Q->rear - Q->front + MAXSIZE) % MAXSIZE;
	int index = Q->front;
	for (int i = 0; i < length; i++)
	{
		printf("%d ", Q->data[index]);
		index = (index + 1) % MAXSIZE;
	}
}

int main()
{
	queue* Q = initqueue();
	enqueue(Q,1);
	enqueue(Q,2);
	enqueue(Q,3);
	enqueue(Q,4);
	enqueue(Q,5);
	enqueue(Q,6);
	enqueue(Q,7);
	enqueue(Q,8);
	enqueue(Q,9);
	dequeue(Q);
	dequeue(Q);
	printqueue(Q);
	return 0;
}
