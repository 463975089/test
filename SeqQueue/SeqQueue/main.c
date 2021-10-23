#include <stdio.h>
#include <stdlib.h>

/*
* 因为顺序队列的假溢出问题，采用循环队列，采用一个空格表示标志位，不存取数据。
* 定义队列头front,定义队列尾rear.当front==rear时，队列为空，当(rear+1)%MAX==front是为满
*/
#define MAX_ 10
typedef struct SeqQueue {
	int queue[MAX_];
	int front;
	int rear;
}SeqCirQueue;
//队列初始化
void InitSeqCirQueue(SeqCirQueue* SCQ)
{
	SCQ->front = SCQ->rear = 0;
}
//判断队列是否为空
int isEmpty(SeqCirQueue* SCQ)
{
	if (SCQ->front == SCQ->rear)
	{
		printf("队列为空\n");
		return 1;
	}
	else
	{
		return 0;
	}
}
//判断队列是否为满
int isFull(SeqCirQueue* SCQ)
{
	if ((SCQ->rear + 1) % MAX_ == SCQ->front)
	{
		printf("队列已满\n");
		return 1;
	}
	else
	{
		return 0;
	}
}
//入队操作
int EnterSeqCirQueue(SeqCirQueue* SCQ, int data)
{
	if (isFull(SCQ))
	{
		printf("队列已满\n");
		return 0;
	}
	SCQ->queue[SCQ->rear] = data;
	SCQ->rear = (SCQ->rear + 1) % MAX_;
	return 1;
}
//出队操作
int DeleteSeqCirQueue(SeqCirQueue* SCQ)
{
	if (isEmpty(SCQ))
	{
		printf("队列为空\n");
		return 0;
	}
	int num = SCQ->queue[SCQ->front];
	SCQ->front = (SCQ->front + 1) % MAX_;
	return 1;
}
void ClearSeqCirQueue(SeqCirQueue* SCQ)
{
	SCQ->front = SCQ->rear = 0;
}
void PrintSeqCirQueue(SeqCirQueue* SCQ)
{
	int temp = SCQ->front;
	while ((temp+1)%MAX_!=SCQ->front)
	{
		printf("%d\n",SCQ->queue[temp]);
		temp++;
	}
}
int main()
{
	SeqCirQueue SCQ;
	int data;
	InitSeqCirQueue(&SCQ);
	EnterSeqCirQueue(&SCQ, 1);
	EnterSeqCirQueue(&SCQ, 2);
	EnterSeqCirQueue(&SCQ, 3);
	EnterSeqCirQueue(&SCQ, 4);
	EnterSeqCirQueue(&SCQ, 5);
	EnterSeqCirQueue(&SCQ, 6);
	EnterSeqCirQueue(&SCQ, 7);
	EnterSeqCirQueue(&SCQ, 8);
	EnterSeqCirQueue(&SCQ, 9);
	EnterSeqCirQueue(&SCQ, 10);
	PrintSeqCirQueue(&SCQ);
	DeleteSeqCirQueue(&SCQ);
}