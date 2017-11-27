#include "lheap.h"
#include <stdlib.h>

static const LUInt64 MAX_HEAP_BLOCKS = 10000;
static const int LHEAP_GROW_SIZE = 1000;

LHeap* lheap_create(LUInt64 size)
{
    LHeap* h = malloc(sizeof(LHeap));
    h->bytes = malloc(size);
    h->size = size;
    h->blocks = malloc(sizeof(LHeapBlock) * MAX_HEAP_BLOCKS);
    h->block_count = 0;
    h->next_block_offset = 4;   //  Leave 0 for lheap_allocate to indicate failure
}

void lheap_destory(LHeap* h)
{
    if(h != NULL)
    {
        if(h->bytes != NULL) free(h->bytes);
        if(h->blocks != NULL) free(h->blocks);
        free(h);
    }
}

void lheap_resize(LHeap* h, LUInt64 size)
{
    h->bytes = realloc(h->bytes, size);
    h->size = size;
}

LUInt64 lheap_allocate(LHeap* h, LUInt64 size)
{
    if(h->next_block_offset >= h->size) lheap_resize(h, size + LHEAP_GROW_SIZE);

    LHeapBlock* hb = h->blocks + h->block_count * sizeof(LHeapBlock);
    hb->state = IN_USE;
    hb->size = size;
    hb->offset = h->next_block_offset;

    h->block_count++;
    h->next_block_offset += size;

    return hb->offset;
}
