#ifndef LLOADER_H
#define LLOADER_H

#include "lstk.h"
#include "lheap.h"

typedef struct
{
    LHeap* heap;
    LStack* stack;
    LByte* code;
    LUInt64 ip;
} LProcess;

LProcess* lloader_loadfile(char *filename);

#endif