#ifndef LIVM_H
#define LIVM_H

typedef char LByte;
typedef short LInt16;
typedef long LInt32;
typedef long long LInt64;
typedef unsigned char LUByte;
typedef unsigned short LUInt16;
typedef unsigned long LUInt32;
typedef unsigned long long LUInt64;

typedef float LFloat;
typedef float LDouble;
typedef float LLongDouble;

typedef enum
{
    LTByte,     // byte
    LTInt16,    // int16, short
    LTInt32,    // int32, int
    LTInt64,    // int64, long
    LTUByte,
    LTUInt16,
    LTUInt32,
    LTUInt64,
    LTFloat,
    LTDouble,
    LTLongDouble,
    LTBool,
    LTString,
    LTRef
} LType; 

typedef union LValue
{
    LByte byte;
    LInt16 int16;
    LInt32 int32;
    LInt64 int64;

    LUByte ubyte;
    LUInt16 uint16;
    LUInt32 uint32;
    LUInt64 uint64;

    LFloat float_;
    LDouble double_;
    LLongDouble long_double;
} LValue;

typedef struct
{
    LUInt64 length;
    LByte* bytes;
} LString;

/* When type field is LTString
 * value field is UInt64 pointer to LString */
typedef struct
{
    LType type;
    LValue value;
} LObject;

typedef struct
{
    LType type;
    LInt64 length;
    LValue* values;
} LArray;

// Registers
LUInt64 R_IP;      // Instruction Pointer

void livm_run();

#endif
