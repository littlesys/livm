#ifndef LHEAP_H
#define LHEAP_H

#include "livm.h"

typedef enum
{
    FREE,
    IN_USE,
    READY_FOR_COLLECTION
} LHeapBlockState;

typedef struct
{
    LHeapBlockState state; 
    LUInt64 offset;     // Actual address = LHeap.bytes + offset
    LUInt64 size;       // Size in bytes
} LHeapBlock;

typedef struct
{
    LByte* bytes;
    LUInt64 size;
    LHeapBlock* blocks;
    LUInt64 block_count;
    LUInt64 next_block_offset;
} LHeap;

LHeap* lheap_create(LUInt64 size);
void lheap_destory(LHeap* h);
void lheap_resize(LHeap* h, LUInt64 size);
LUInt64 lheap_allocate(LHeap* h, LUInt64 size);

#endif