#pragma once
#ifndef _DATATYPE_
#define _DATATYPE_
typedef struct Element {
	int age;
	char* name;
}Element;
typedef struct CirNode {
	Element elem;
	struct CirNode* next;
}Node;
typedef struct CirLink {
	Node* head;
	int length;
}CirLink;
#endif // !_DATATYPE_

