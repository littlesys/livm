#include <stdio.h>
#include "linst.h"

static void nop()
{
    printf("nop\n");
}

static void pop()
{
    printf("pop\n");
}

void (*inst[256])();

void linst_init()
{
    inst[NOP] = nop;
    inst[POP] = pop;
}
