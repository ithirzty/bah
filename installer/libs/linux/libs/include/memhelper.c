//This is used by lightgc.bah (the portable garbage collector)

#define stackbase volatile long int
#define __bahEnddecl char end
#define __bahEtextdecl char etext

unsigned long int stack_pointer() {
  volatile void* p = NULL;
  return &p;
}

unsigned long int getBSSend() {
  extern char end;
  return &end;
}

unsigned long int getBSSbeg() {
  extern char etext;
  return &etext;
}