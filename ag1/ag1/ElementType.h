#ifndef __ELEMENTYPPE__
#define __ELEMENTTYPE__
#include <stdio.h>
#include <stdlib.h>

#define MAX_ 255

typedef struct {
	int num;
	char name[10];
}Element;

typedef struct {
	Element ele[MAX_];
	int length ;
}Seqlist;

#endif
