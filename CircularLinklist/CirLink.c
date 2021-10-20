#include"CirLink.h"
void Init(CirLink* link, Element* e, int length)
{
	for (int i = 1; i <= length; i++)
	{
		Insert(link, e[i - 1], i);
	}
}
void Insert(CirLink* link, Element e, int index)
{
	Node* p = (Node*)malloc(sizeof(Node));//
	p->elem = e;
	p->next = NULL;
	if (index == 1)
	{
		p->next = link->head;
		if (!link->head)//如果原先没有元素
		{
			p->next = p;
			link->head = p;
		}
		else//如果原先有元素
		{
			Node* last = link->head;
			for (int i = 1; i < link->length; i++)
			{
				last = link->length;
			}
			p->next = link->head;
			link->head = p;
			last->next = p;
		}
	}
	else
	{
		Node* temp = link->head;
		for (int i = 1; i < index - 1; i++)
		{
			temp = temp->next;
		}
		p->next = temp->next;
		temp->next = p;
	}
	link->length++;
}
void Display(CirLink* link)
{
	Node* node = link->head;
	for (int i = 0; i < link->length; i++)
	{
		printf("%d\t%s\n", node->elem.age, node->elem.name);
		node = node->next;
	}
}
void Delete(CirLink* link, int index)
{
	if (link->length == 0) return;
	if (index == 1)
	{
		Node* temp = link->head;
		Node* last = link->head;
		for (int i = 1; i < link->length; i++)
		{
			last = last->next;
		}
		link->head = temp->next;
		last->next = temp->next;
		free(temp);
	}
	else
	{
		Node* pre = link->head;
		Node* curr = NULL;
		for (int i = 1; i < index - 1; i++)
		{
			pre = pre->next;
		}
		curr = pre->next;
		pre->next = curr->next;
		free(curr);
	}
	link->length--;
}