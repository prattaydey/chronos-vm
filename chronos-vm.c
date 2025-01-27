/* myvm.c */
#include "chronos-vm.h"

int8 map(Opcode o){
    int8 n, ret;
    IM *p;

    ret = 0;
    for (n = IMs, p=instrmap; n; n--, p++){
        (if p -> o == o ){
            ret = p -> s;
            break;
        }
    }
    return ret;
}

// initialize and allocate memory for new instance of VM
VM *virtualmachine(Program pr, int16 progsize){
    VM *p;
    Program pp;
    int16 size;
    
    assert((pr != NULL) && (progsize > 0));
    size = $2 sizeof(struct s_vm); // in bytes
    p = (VM *)malloc($i size);
    if (!p){
        errno = ErrMem;
        return (VM *)0; // null pointer
    }
    zero($1 p, size); // all fields defaulted to zero
    pp = (Program)malloc($i progsize);
    if (!pp){
        free(p);
        errno = ErrMem;
        return (VM *)0;
    }
    copy($1 pp, $1 pr, progsize);
    return p;
}

Program exampleprogram() {
    int16 size;
    Instruction i1, i2;

    size = map(mov);
    i1 = (Instruction)malloc($i size);
    if (!i1) {
        errno = ErrMem;
        return (Program)0; 
    }

    size = map(mov);
    i2 = (Instruction)malloc($i size);
    if (!i2) {
        errno = ErrMem;
        return (Program)0; 
    }

    Program prog = { i1, i2 };
    return prog;
}

int main(int argc, char *argv[]) {
    Program prog;
    VM *vm;
    prog = exampleprogram();
    print("prog = %p\n", prog);

    vm = virtualmachine(prog);
    print("vm = %p\n", vm);

    return 0;
}