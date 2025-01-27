/* myvm.h */
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <errno.h>
#include <birchutils.h>

#define ErrMem      0x01
#define NoArgs      { 0x00, 0x00}

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;
typedef unsigned long long int int64;

#define $1 (int8 *)
#define $2 (int16)
#define $4 (int32)
#define $8 (int64)
#define $c (char *)
#define $i (int)


/*

    16 bit -- (Like Deskpro 386 Computer)
    Registers:
        AX 16bit
            - AL 8bit
            - AH 8bit
        BX
        CX
        DX
        SP (Stack Pointer)
        IP (Instructor Pointer)
        FLAGS

        1010
         ^----
         Zero flag
         Carry flag

         CMP AX,0x05

    65 KB (2^16 bytes) memory
    (Serial COM port)
    (Floppy drive)

*/
typedef unsigned short int Reg;

// Registers
struct s_registers {
    Reg ax;
    Reg bx;
    Reg cx;
    Reg dx;
    Reg sp;
    Reg ip;
};
typedef struct s_registers Registers;

// CPU
struct s_cpu {
    Registers r;

};
typedef struct s_cpu CPU;

/*
 mov ax,0x05 // (0x01 OR ax) mov encoded as 0x01
             // (0x01 OR 0x02) ax encoded as 0x02
             // 0000 0011 = mov ax
             // 0000 0000
             // 0000 0101 = 0x05
*/
enum e_opcode {
    mov = 0x01,
    nop = 0x02
};
typedef enum e_opcode Opcode;

struct s_instrmap {
    Opcode o;
    int8 s;
};
typedef struct s_instrmap IM;

typedef int8 Args;

struct s_instruction {
    Opcode o;
    Args a[]; // can be 0-2 bytes
};
typedef struct s_instruction *Instruction;

// Stack
typedef int8 Stack[((unsigned int)(-1))];
// Sequence of Instructions
typedef Instruction Program;

// Virtual Machine
struct s_vm {
    CPU c;
    Stack s;
    Program *p;
};
typedef struct s_vm VM;

static Opcode opc;

// Outlines all the current instructions
static IM instrmap[] = {
    { mov, 0x03 },
    { nop, 0x01 }
};
#define IMs (sizeof(instrmap) / sizeof(struct s_instrmap))

    Program exampleprogram(void); // to be removed/modified later

int8 map(Opcode);
// Constructor function, returns pointer to VM
VM *virtualmachine(Program, int16);

int main(int,char**);