//This is used by lightgc.bah (the portable garbage collector)

#define stackbase volatile long int

long int stack_pointer() {
  void* p = NULL;
  return &p;
} 
