
void* GC_MALLOC(long int s); 
// void* GC_malloc_atomic(long int s); 
void GC_INIT();
void GC_FREE(void * p);

// #define GC_pthread_create(a, b, c, d) pthread_create(a, b, c, d)
#define GC_pthread_join(a, b) pthread_join(a, b)
#define GC_malloc_atomic(a) GC_MALLOC(a)

char GC_getEtext() {
    extern char etext;
    return etext;
}

char GC_getEnd() {
    extern char end;
    return end;
}

#define __ASMV(v) asm volatile (v)