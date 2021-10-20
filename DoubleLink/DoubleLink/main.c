#include"DoubleLink.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
	Element elem[4] = { {1,"张三"} ,{2,"李四"}, {3,"王五"}, {4,"赵六"} };
	DoubleLink* link = (DoubleLink*)malloc(sizeof(DoubleLink));
	link->length = 0;
	link->head = NULL;
	Init(link, elem, 4);
	Display(link);
	Delete(link, 2);
	Display(link);
}