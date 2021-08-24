#define true 1
#define false 0
#define noCheck(v) v
#define array(type)         struct{             type *data;         long int length;            long int elemSize;     }
int main(int argc, char ** argv) {
        GC_INIT();
        array(char*) * args = GC_MALLOC(sizeof(array(char*)));
        args->data = GC_MALLOC(sizeof(char*)*argc);
        memcpy(args->data, argv, sizeof(char*)*argc);
        args->elemSize = sizeof(char*);
        args->length = argc;
        __BAH__main(args);
};
#define main(v) __BAH__main(v)
#include <stdio.h>
#include <gc.h>
void main(){
printf(concatCPSTRING(concatCPSTRING("test"," "),"bah"));
};