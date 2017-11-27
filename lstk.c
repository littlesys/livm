#include "livm.h"
#include "lstk.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const int lobject_size = sizeof(LObject);
static const int LSTK_GROW_SIZE = 100;

LStack* lstk_create(LUInt64 size)
{
    LStack* s = malloc(sizeof(LStack));
    
    if(size == -1) size = LSTK_GROW_SIZE;
    s->size = size;

    s->objects = malloc(lobject_size * size);
    s->sp = 0;

    return s;
}

void lstk_destroy(LStack* s)
{
    if(s != NULL) 
    {
        if(s->objects != NULL) free(s->objects);
        free(s);
    }
}

void lstk_resize(LStack* s, LUInt64 size)
{
    s->objects = realloc(s->objects, lobject_size * size);
    s->size = size;
}

void lstk_push(LStack* s, LObject* o)
{
    memcpy(s->objects + (s->sp * lobject_size), o, lobject_size);
    s->sp++;
    if(s->sp == s->size) lstk_resize(s, s->size + LSTK_GROW_SIZE);
}

LObject* lstk_pop(LStack* s)
{
    return (LObject*) (s->objects + (--s->sp * lobject_size));
}
