#pragma once
#ifndef __SEQLIST__
#define __SEQLIST__

#include "ElementType.h"
/*
* ��ʼ��˳������
* @param list ����
* @param ele Ԫ��
* @length ��ʼ������ĸ���
*/
void InitSeqlist(Seqlist* list, Element* ele, int length);
void InsertSeqlist(Seqlist* list, Element ele, int index);
void display(Seqlist list);
#endif