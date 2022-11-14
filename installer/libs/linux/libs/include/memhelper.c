//This is used by lightgc.bah (the portable garbage collector)

#define stackbase volatile long int
#define __bahEnddecl char end
#define __bahEtextdecl char etext

long int stack_pointer() {
  void* p = NULL;
  return &p;
}

long int getBSSend() {
  extern char end;
  return &end;
}

long int getBSSbeg() {
  extern char etext;
  return &etext;
}