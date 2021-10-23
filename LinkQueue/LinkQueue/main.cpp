#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node* next;
}Node;
typedef struct Queue
{
    Node* front;
    Node* rear;
}Queue;
void Init(Queue* q)
{
    q->front = NULL;
    q->rear = NULL;
}
void Insert(Queue* q,int d)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = d;
    temp->next = NULL;
    if (q->rear == NULL)
    {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}
void Out(Queue* q)
{
    if (q->front == NULL) return ;
    Node* temp = q->front;
    q->front = q->front->next;
    free(temp);
}
void Display(Queue*q)
{
    if (q->front == NULL) return;
    Node* temp = q->front;
    while (temp != q->rear)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("%d\t", temp->data);
}
int main()
{
    Queue* q = (Queue*)malloc(sizeof(Queue));
    Init(q);
    Insert(q, 1);
    Insert(q, 2);
    Insert(q, 3);
    Insert(q, 4);
    Insert(q, 5);
    Display(q);
    Out(q);
    printf("\n-------------\n");
    Display(q);


}