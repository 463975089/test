#pragma once
#ifndef _DATATYPE_
#define _DATATYPE_
typedef struct Element
{
	int num;
	char* name;
}Element;
typedef struct Node
{
	Element elem;
	struct Node* pre;
	struct Node* next;
}Node;
typedef struct DoubleLink {
	int length;
	struct Node* head;
}DoubleLink;
#endif // !_DATATYPE_
