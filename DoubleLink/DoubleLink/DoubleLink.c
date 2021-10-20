#include "DoubleLink.h"
#include<stdio.h>
#include<stdlib.h>
void Init(DoubleLink* link, Element* e, int length)
{
	for (int i = 1; i <= length; i++)
	{
		Insert(link, e[i-1],i);
	}
}
void Insert(DoubleLink* link, Element e, int index)
{
	Node* p= (Node*)malloc(sizeof(Node));
	p->elem = e;
	p->next = NULL;
	p->pre = NULL;
		if (index == 1)
		{
			if (link->head == NULL)
			{
				link->head = p;
				link->length++;
				return;
			}
			else
			{
				p->next = link->head;
				link->head->pre = p;
				link->head = p;
				link->length++;
				return;
			}
		}
		else
		{
			
			Node* temp = link->head;
			for (int i = 1; i < index - 1; i++)
			{
				temp = temp->next;
			}
			if (index > link->length)
			{
				p->next = temp->next;
				p->pre = temp;
				temp->next = p;
				link->length++;
				return;
			}
			else
			{
				p->next = temp->next;
				temp->next->pre = p;
				p->pre = temp;
				temp->next = p;
				link->length++;
				return;
			}

		}
}
void Display(DoubleLink* link)
{
	Node* temp = link->head;
	for (int i = 0; i < link->length; i++)
	{
		printf("%d,%s\n", temp->elem.num, temp->elem.name);
		temp = temp->next;
	}
}
void Delete(DoubleLink* link, int index)
{
	if (index == 1)
	{
		if (link->head = NULL) return;
		Node* temp = link->head;
		link->head = temp->next;
		link->head->pre = NULL;
		free(temp);
		link->length--;
	}
	else if (index == link->length)
	{
		Node* temp = link->head;
		for (int i = 1; i < index-1; i++)
		{
			temp = temp->next;
		}
		free(temp->next);
		temp->next = NULL;
		link->length--;
	}
	else
	{
		Node* temp = link->head;
		for (int i = 1; i < index - 1; i++)
		{
			temp = temp->next;
		}
		Node* curr = temp->next;
		temp->next = curr->next;
		curr->next->pre = temp;
		free(curr);
		link->length--;
	}
}