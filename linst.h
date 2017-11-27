#ifndef LINST_H
#define LINST_H

typedef enum LInst
{
    NOP = 0,
    CALL,
    RET,            // Return
    POP,
    LDN,            // Load null
    LDC,            // Load constant
    LDA,            // Load argument
    STA,            // Store to argument
    STL,            // Store to local variable

    JMP,            // Jump
    JE,             // Jump if equal
    JNE,            // Jump if not equal
    JL,             // Jump if less
    JLE,            // Jump if less or equal
    JG,             // Jump if greater
    JGE,            // Jump if greater or equal
    JT,             // Jump if true
    JF,             // Jump if false
    JN,             // Jump if null
    JNN,            // Jump if not null
    JZ,             // Jump if zero
    JNZ,            // Jump if not zero

    AND,            // Logical AND
    OR,             // Logical OR
    NOT,            // Logical NOT
    XOR,            // Logical XOR

    SHL,            // Shift left
    SHR,            // Shift right
    ADD,            // Add
    SUB,            // Subtract
    MUL,            // Multiply   
    DIV,            // Divide
    REM,            // Remainder
} LInst;

void (*inst[256])();
void linst_init();

#endif
