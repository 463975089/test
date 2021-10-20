#include<stdio.h>
#include<stdlib.h>
#include"CirLink.h"

int main()
{
	/*Element elem[] = { {1,"王五"},{2,"赵六"},{3,"张三"},{4,"李四"} };
	CirLink* link = (CirLink*)malloc(sizeof(CirLink));
	link->length = 0;
	link->head = NULL;
	Init(link, elem, 4);
	Display(link);
	Delete(link, 2);
	Display(link);*/
	char* str = "123";
	char* str1 = "123";
	if (str == str1)
	{
		printf("1");
	}
	else
	{
		printf("2");
	}
	return 0;

}
int add(int a, int b)
{
	int num = a + b;
	printf("%X\n", &num);
	return num;
}