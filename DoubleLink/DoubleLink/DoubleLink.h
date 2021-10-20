#pragma once
#ifndef _DOUBLELINK_
#define _DOUBLELINK_
#include "DataType.h"
void Init(DoubleLink* link, Element* e, int length);
void Insert(DoubleLink* link, Element e, int index);
void Delete(DoubleLink* link, int index);
void Display(DoubleLink* link);

#endif // !_DOUBLELINK_

