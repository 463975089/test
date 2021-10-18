#include <stdlib.h>
#include <stdio.h>
#include "SeqList.h"
void InitSeqlist(Seqlist* list, Element* ele, int length)
{
	list->length = 0;
	for (int i = 0; i < length; i++)
	{
		InsertSeqlist(list, ele[i], i);
	}
}
void InsertSeqlist(Seqlist* list, Element ele, int index)
{
	if (index<0 || index >MAX_ - 1)
	{
		printf("索引值不在范围之内");
		return;
	}
	if (list->length == MAX_)
	{
		printf("链表已满");
		return;
	}
	if (index < list->length)
	{
		for (int i = list->length; i > index; i--)
		{
			list->ele[i] = list->ele[i-1];
		}
		list->ele[index] = ele;
		list->length++;
	}else
	{
		list->ele[index] = ele;
		list->length++;
	}	
}
void display(Seqlist list)
{
	for (int i = 0; i < list.length; i++)
	{
		printf("%d,%s,\n", list.ele[i].num, list.ele[i].name);
	}
	printf("%d", list.length);
}