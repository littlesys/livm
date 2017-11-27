#ifndef LSTK_H
#define LSTK_H

#include "livm.h"

typedef struct
{
    LObject* objects;
    LUInt64 sp;
    LUInt64 size;
} LStack;

LStack* lstk_create(LUInt64 size);
void lstk_destroy(LStack* s);
void lstk_resize(LStack* s, LUInt64 size);
void lstk_push(LStack* s, LObject* o);
LObject* lstk_pop(LStack* s);

#endif
