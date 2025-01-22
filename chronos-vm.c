/* myvm.c */
#include "chronos-vm.h"

// initialize and allocate memory for new instance of VM
VM *virtualmachine(Program *pr, int16 progsize){
    VM *p;
    Program *pp;
    int16 size;
    
    assert((pr != NULL) && (progsize > 0));
    size = $2 sizeof(struct s_vm); // in bytes
    p = (VM *)malloc($i size);
    if (!p){
        errno = ErrMem;
        return (VM *)0; // null pointer
    }
    zero($1 p, size); // all fields defaulted to zero
    pp = (Program *)malloc($i progsize);
    if (!pp){
        free(p);
        errno = ErrMem;
        return (VM *)0;
    }
    copy(pp, pr, progsize);
    return p;
}

Program *exampleprogram() {
    static Program prog[] = {
        {
            .o = mov,
            .a = {
                0x00, 0x05
            }
        },
        {
            .o = nop,
            .a = NoArgs
        }
    };
    return prog;
}

int main(int argc, char *argv[]) {
    Program *prog;
    VM *vm;
    prog = exampleprogram();
    vm = virtualmachine(program);
}