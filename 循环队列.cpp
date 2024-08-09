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

queue* initqueue()//初始化
{
	queue* Q = (queue*)malloc(sizeof(queue));
	Q->front = Q->rear = 0;
	return Q;
}

int isfull(queue* Q)//判断队列是否满
{
	if ((Q->rear + 1) % MAXSIZE == Q->front)
	{
		return 1;
	}
	else
		return 0;
}

void enqueue(queue* Q, int data)//入队
{
	if (!isfull(Q))
	{
		Q->data[Q->rear] = data;
		Q->rear = (Q->rear + 1) % MAXSIZE;
	}
	else
	{
		printf("队列已满");
	}
}

int isempty(queue* Q)//判断队列是否为空
{
	if (Q->front == Q->rear)
		return 1;
	else
		return 0;
}

void dequeue(queue* Q)//出队
{
	if (isempty(Q))
	{
		printf("队列为空");
		return;
	}
	else
	{
		Q->front = (Q->front + 1) % MAXSIZE;
	}
}

void printqueue(queue* Q)//打印队列
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
