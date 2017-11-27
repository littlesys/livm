#include <stdio.h>
#include <stdlib.h>
#include "livm.h"
#include "linst.h"
#include "lloader.h"

int main(int argc, char **argv)
{
    char* filename = NULL;

    printf("Little VM 0.1\n");

    if(argc > 1) filename = argv[1];

    if(filename == NULL)
    {
        printf("Usage: livm <filename>\n");
        exit(0);
    }

    lloader_loadfile(filename);
    livm_run();

    return 0;
}

void livm_run()
{
    inst[NOP]();
    inst[POP]();
    inst[POP]();
}
