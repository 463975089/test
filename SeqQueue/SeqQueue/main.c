#include <stdio.h>
#include <stdlib.h>

/*
* ��Ϊ˳����еļ�������⣬����ѭ�����У�����һ���ո��ʾ��־λ������ȡ���ݡ�
* �������ͷfront,�������βrear.��front==rearʱ������Ϊ�գ���(rear+1)%MAX==front��Ϊ��
*/
#define MAX_ 10
typedef struct SeqQueue {
	int queue[MAX_];
	int front;
	int rear;
}SeqCirQueue;
//���г�ʼ��
void InitSeqCirQueue(SeqCirQueue* SCQ)
{
	SCQ->front = SCQ->rear = 0;
}
//�ж϶����Ƿ�Ϊ��
int isEmpty(SeqCirQueue* SCQ)
{
	if (SCQ->front == SCQ->rear)
	{
		printf("����Ϊ��\n");
		return 1;
	}
	else
	{
		return 0;
	}
}
//�ж϶����Ƿ�Ϊ��
int isFull(SeqCirQueue* SCQ)
{
	if ((SCQ->rear + 1) % MAX_ == SCQ->front)
	{
		printf("��������\n");
		return 1;
	}
	else
	{
		return 0;
	}
}
//��Ӳ���
int EnterSeqCirQueue(SeqCirQueue* SCQ, int data)
{
	if (isFull(SCQ))
	{
		printf("��������\n");
		return 0;
	}
	SCQ->queue[SCQ->rear] = data;
	SCQ->rear = (SCQ->rear + 1) % MAX_;
	return 1;
}
//���Ӳ���
int DeleteSeqCirQueue(SeqCirQueue* SCQ)
{
	if (isEmpty(SCQ))
	{
		printf("����Ϊ��\n");
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