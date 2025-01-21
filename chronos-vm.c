/* myvm.c */
#include "chronos-vm.h"

// initialize and allocate memory for new instance of VM
VM *virtualmachine(){
    VM *p;
    int16 size;
    
    size = sizeof(struct s_vm); // in bytes
    p = (VM *)malloc($i size);
    if (!p){
        errno = ErrMem;
        return (VM *)0; // null pointer
    }
    zero($1 p, size);
}

int main(int argc, char *argv[]) {
    return 0;
}