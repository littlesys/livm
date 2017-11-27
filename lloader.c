#include "lloader.h"
#include "linst.h"
#include "lstk.h"
#include "lheap.h"
#include <stdlib.h>

LProcess* lloader_loadfile(char *filename)
{
    linst_init();

    LProcess* p = malloc(sizeof(LProcess));
    p->stack = lstk_create(-1);
    p->heap = lheap_create(-1);
    // byte code file should have string table. Create these strings in heap.
    // Allocate memory for code
    //   Replace opcodes with function pointers
    //   Convert constants to LObject
    return p;
}

void lloader_destroy(LProcess* p)
{
    if(p != NULL)
    {
        if(p->code != NULL) free(p->code);
        if(p->stack != NULL) lstk_destroy(p->stack);
        if(p->heap != NULL) lheap_destory(p->heap);
        free(p);
    }
}
