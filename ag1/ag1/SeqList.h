#pragma once
#ifndef __SEQLIST__
#define __SEQLIST__

#include "ElementType.h"
/*
* 初始化顺序链表
* @param list 链表
* @param ele 元素
* @length 初始化插入的个数
*/
void InitSeqlist(Seqlist* list, Element* ele, int length);
void InsertSeqlist(Seqlist* list, Element ele, int index);
void display(Seqlist list);
#endif