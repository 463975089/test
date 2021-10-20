#pragma once
#ifndef _DATALINK_
#define _DATALINK_
#include "DataType.h"
#include <stdio.h>
#include <stdlib.h>


void Init(CirLink* link, Element* e, int length);
void Insert(CirLink* link, Element e, int index);
void Display(CirLink* link);
void Delete(CirLink* link, int index);
#endif
