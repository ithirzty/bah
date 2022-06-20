//COMPILE WITH: '../builder/osxcross/target/bin/x86_64h-apple-darwin14-clang -I "/opt/bah/libs/darwin/include/" -L "/opt/bah/libs/darwin/" ../installer/darwin.c  -O1 -w  -lgc -lpthread -lm'

    void __BAH_init();
    #define noCheck(v) v
    #define array(type)	    struct{	    type *data;     long int length;     long int realLength;     long int elemSize;     }
    typedef array(char*)* __BAH_ARR_TYPE_cpstring;
    long int __BAH__main(__BAH_ARR_TYPE_cpstring);
    
            #include <gc.h>
            #include <string.h>
            int main(int argc, char ** argv) {
            GC_INIT();
            array(char*) * args = GC_MALLOC(sizeof(array(char*)));
            args->data = GC_MALLOC(sizeof(char*)*argc);
            memcpy(args->data, argv, sizeof(char*)*argc);
            args->elemSize = sizeof(char*);
            args->length = argc;
            __BAH_init();
            long int r =  __BAH__main((__BAH_ARR_TYPE_cpstring)args);
            GC_FREE(args->data);
            GC_FREE(args);
            return r;
            };
            #define main(v) __BAH__main(v)
            #include <signal.h>
#include <string.h>
#include <mach/mach.h>
void __BAH_panic(char * e,char * l);
char * __Bah_safe_string(char * s);
#define null (void *)0
#define true (char)1
#define false (char)0
long int __bah_strcmp(char * a,char * b){
long int ai = (long int)a;
long int bi = (long int)b;
if ((ai*bi==0)) {
return 1;
}
return strcmp(a,b);
};
#define strcmp __bah_strcmp
long int __bah_strlen(char * s){
if (((void *)s==null)) {
return 0;
}
return strlen(s);
};
#define strlen __bah_strlen
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
void print(char * s){
write((void *)1,s,strlen(s));
};
void __BAH_memcpy(char * dest,char * source,long int l);
#define memcpy __BAH_memcpy
#include <sys/mman.h>
#define SIZE_OF_INT 8
#define SIZE_OF_CHAR 1
#define SIZE_OF_INT32 4
#define SIZE_OF_FLOAT32 4
#define SIZE_OF_FLOAT 8
long int len(void * a){
if ((a==null)) {
return 0;
}
array(void*)*arr=a;
return arr->length;
};
#include <gc.h>
void * memoryAlloc(long int s){
return GC_MALLOC(s);
};
void destroy(void * a){
GC_FREE(a);
};
void clear(void * a){
array(void*)*arr=a;
memset(arr->data,null,arr->realLength*arr->elemSize);
arr->length=0;
};
void * memoryRealloc(void * p,long int s){
return GC_REALLOC(p,s);
};
void cleanShutDown(){
exit(1);
return;
};
void memoryOnEnd(void * obj,void * fn){
GC_REGISTER_FINALIZER_IGNORE_SELF(obj,fn,null,null,null);
};
void __BAH_memcpy(char * dest,char * source,long int l){
register long int lm = l%sizeof(long int);
if ((lm!=0)) {
for (; (lm!=0); --lm) {
long int i = l-lm;
dest[i]=source[i];
};
}
long int* destI = (void *)((long int)dest-sizeof(long int));
long int* sourceI = (void *)((long int)source-sizeof(long int));
register long int i = l/sizeof(long int);
for (; (i!=0); --i) {
destI[i]=sourceI[i];
};
};
void append(void * a,void * b){
array(void*)*arrA=a;
array(void*)*arrB=b;
long int lenA = 0;
long int lenB = 0;
long int realSizeA = 0;
long int realSizeB = 0;
lenA=len(arrA);
lenB=len(arrB);
if ((lenB==0)) {
return;
}
if ((lenA==0)) {
arrA->data=arrB->data;
arrA->length=arrB->length;
return;
}
realSizeA=lenA*arrA->elemSize;
realSizeB=lenB*arrB->elemSize;
void * buff = memoryAlloc(realSizeA+realSizeB+32);
memcpy(buff,arrA->data,realSizeA);
memcpy(buff+lenA,arrB->data,realSizeB);
arrA->length=lenA+lenB;
arrA->data=buff;
};
void copy(void * a,void * b){
array(void*)*arrA=a;
array(void*)*arrB=b;
long int lenB = 0;
long int realSizeB = 0;
lenB=len(arrB);
realSizeB=lenB*arrB->elemSize;
arrA->data=memoryAlloc(realSizeB);
memcpy(arrA->data,arrB->data,realSizeB);
arrA->length=arrB->length;
};
#define PROT_READ 1
#define PROT_WRITE 2
#define PROT_READWRITE 3
#define MAP_SHARED 1
#define MAP_ANONYMOUS 32
void * sharedMemory(long int size){
if ((size==0)) {
size = 4096;
}
void * r = mmap(0,size,PROT_READ+PROT_WRITE,MAP_SHARED+MAP_ANONYMOUS,-1,0);
return r;
};
void allocateArray(void * arr,long int nbElems){
array(void*)*a=arr;
a->length=nbElems;
a->realLength=nbElems;
a->data=memoryAlloc(nbElems*a->elemSize);
};
typedef array(char)* __BAH_ARR_TYPE_char;
__BAH_ARR_TYPE_char ser(void * a);
__BAH_ARR_TYPE_char __serialize(void * a,long int s){
char * r = memoryAlloc(s+9);
memcpy(r,&s,8);
memcpy(r+8,a,s);
long int l = s+1;
array(char)* arr = memoryAlloc(sizeof(array(char)));

arr->length = 0;
arr->elemSize = sizeof(char);
arr->length=s+8;
arr->elemSize=1;
arr->data=r;
return arr;
};
long int serlen(__BAH_ARR_TYPE_char data){
array(char)* sarr = memoryAlloc(sizeof(array(char)));

sarr->length = 8;
sarr->elemSize = sizeof(char);
sarr->data = memoryAlloc(sizeof(char) * 50);
                    sarr->realLength = 50;
sarr->data[0] = data->data[0];
sarr->data[1] = data->data[1];
sarr->data[2] = data->data[2];
sarr->data[3] = data->data[3];
sarr->data[4] = data->data[4];
sarr->data[5] = data->data[5];
sarr->data[6] = data->data[6];
sarr->data[7] = data->data[7];
return *sarr->data;
};
void * unser(__BAH_ARR_TYPE_char data){
long int sptr = serlen(data);
void * r = memoryAlloc(sptr);
memcpy(r,data->data+8,sptr);
return r;
};
char * memoryAllocSTR(long int s){
char * r = GC_malloc_atomic(s);
r[s-1]=0;
return r;
};
void delete(void * a,long int i){
array(void *)* arr = (array(void *)*)a;
long int length = len(arr);
if ((i>=length)||(i<0)) {
return;
}
if ((length==1)) {
arr->length=0;
return;
}
long int elemSize = arr->elemSize;
char* data = arr->data;
void * destOffset = elemSize*i;
++i;
void * offset = elemSize*i;
char* src = (long int)data+(long int)offset;
char* dest = (long int)data+(long int)destOffset;
long int rightNB = length-(i-1);
memmove(dest,src,rightNB*elemSize);
arr->length=length-1;
};
void deleteRange(void * a,long int from,long int to){
if ((from==to)) {
delete(a,from);
return;
}
array(void *)* arr = (array(void *)*)a;
long int length = len(arr);
long int elemSize = arr->elemSize;
char* data = arr->data;
long int size = elemSize*(to-from);
void * dest = (long int)data+elemSize*from;
void * src = (long int)dest+size+elemSize;
long int rightNB = length-to;
memmove(dest,src,rightNB*elemSize);
arr->length=length-(to-from+1);
};
char * arrToStr(__BAH_ARR_TYPE_char arr){
long int strLen = len(arr);
char * str = memoryAllocSTR(strLen+1);
memcpy(str,arr->data,strLen);
return str;
};
__BAH_ARR_TYPE_char strToArr(char * str){
long int strLen = strlen(str);
array(char)* arr = memoryAlloc(sizeof(array(char)));

arr->length = 0;
arr->elemSize = sizeof(char);
arr->data=memoryAlloc(strLen+1);
memcpy(arr->data,str,strLen);
arr->length=strLen;
return arr;
};
char * arrAsStr(__BAH_ARR_TYPE_char arr){
return arr->data;
};
__BAH_ARR_TYPE_char strAsArr(char * str){
long int l = strlen(str);
array(char)* arr = memoryAlloc(sizeof(array(char)));

arr->length = 0;
arr->elemSize = sizeof(char);
arr->length=l;
arr->data=str;
return arr;
};
void strTrimLeft(char ** s,long int i){
long int ls = strlen(*s);
char * ns = memoryAlloc(ls-i+1);
memcpy(ns,*s+i,ls-i);
*s = ns;
};
void strTrimRight(char ** s,long int i){
long int ls = strlen(*s);
char * ns = memoryAlloc(ls-i+1);
memcpy(ns,*s,ls-i);
*s = ns;
};
#define __bah_memory_realloc memoryRealloc
#define __bah_memory_str memoryAllocSTR
typedef array(void *)* __BAH_ARR_TYPE_ptr;
void __Bah_realocate_arr(__BAH_ARR_TYPE_ptr arr,unsigned int nLength){
if ((nLength<arr->length)) {
return;
}
if ((nLength>=arr->realLength)) {
if ((arr->realLength!=0)) {
arr->realLength*=2;
}
else {
arr->realLength=50;
}
void * newPtr = memoryRealloc(arr->data,arr->realLength*arr->elemSize);
arr->data=newPtr;
}
arr->length=arr->length+1;
return;
};
char * __Bah_multiple_concat(char ** b,unsigned int l){
unsigned int* lens = alloca(l*sizeof(unsigned int));
unsigned int tot = 0;
int offset = 0;
register long int i = 0;
for (; (i<l); ++i) {
long int sl = strlen(b[i]);
tot = tot+sl;
lens[i]=sl;
};
char * r = memoryAllocSTR(tot+1);
i = 0;
for (; (i<l); ++i) {
memcpy((void *)((long int)r+offset),b[i],lens[i]);
offset = offset+lens[i];
};
return r;
};
char * concatCPSTRING(char * a,char * b){
long int lenA = strlen(a);
long int lenB = strlen(b);
char * r = memoryAlloc(lenA+lenB+1);
strncpy(r,a,lenA);
strcat(r,b);
return r;
};
char * __STR(char * a){
long int lenA = strlen(a);
char * r = memoryAllocSTR(lenA+1);
memcpy(r,a,lenA);
return r;
};
void * cArr(void * arr){
array(void*)*a=arr;
return a->data;
};
char __checkString(char * s,char * l){
if (((void *)s==null)) {
char** ____BAH_COMPILER_VAR_0 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_0[2] = ") is null \n";____BAH_COMPILER_VAR_0[1] = l;____BAH_COMPILER_VAR_0[0] = "cpstring (";char * ____BAH_COMPILER_VAR_1 =__Bah_multiple_concat(____BAH_COMPILER_VAR_0, 3);print(____BAH_COMPILER_VAR_1);
exit(1);
}
return true;
};
#include <pthread.h>
#define __thread_create GC_pthread_create
#define __thread_join GC_pthread_join
#define currentThread pthread_self
struct mutex {
pthread_mutex_t id;
};
void mutex__init(struct mutex* this){
pthread_mutex_init(&this->id,0);
};
void mutex__lock(struct mutex* this){
pthread_mutex_lock(&this->id);
};
void mutex__unlock(struct mutex* this){
pthread_mutex_unlock(&this->id);
};
void mutex__destroy(struct mutex* this){
pthread_mutex_destroy(&this->id);
};
struct mutexCondition {
pthread_cond_t id;
};
void mutexCondition__init(struct mutexCondition* this){
pthread_cond_init(&this->id,0);
};
void mutexCondition__wait(struct mutexCondition* this,struct mutex m){
pthread_mutex_t mid = m.id;
pthread_cond_wait(&this->id,&mid);
};
void mutexCondition__send(struct mutexCondition* this){
pthread_cond_signal(&this->id);
};
void mutexCondition__destroy(struct mutexCondition* this){
pthread_cond_destroy(&this->id);
};
struct mutexCondition mutexCondition(){
struct mutexCondition ____BAH_COMPILER_VAR_2 = {};
#define m ____BAH_COMPILER_VAR_2
mutexCondition__init(&m);
return m;

#undef m
};
struct thread {
pthread_t id;
void (*handle)(void *);
};
void thread__create(struct thread* this){
__thread_create(&this->id,null,this->handle,null);
};
void thread__createWithArg(struct thread* this,void * arg){
__thread_create(&this->id,null,this->handle,arg);
};
void thread__wait(struct thread* this){
__thread_join(this->id,null);
};
struct mutex mutex(){
struct mutex ____BAH_COMPILER_VAR_3 = {};
#define m ____BAH_COMPILER_VAR_3
mutex__init(&m);
return m;

#undef m
};
struct queueNode {
long int key;
void * data;
struct queueNode* next;
struct queueNode* prev;
};
struct queue {
long int length;
struct queueNode* head;
struct queueNode* end;
};
void queue__insert(struct queue* this,void * data){
struct queueNode* ____BAH_COMPILER_VAR_4 = memoryAlloc(sizeof(struct queueNode));
____BAH_COMPILER_VAR_4->key = this->length;
____BAH_COMPILER_VAR_4->data = data;
____BAH_COMPILER_VAR_4->prev = this->end;
struct queueNode* node = ____BAH_COMPILER_VAR_4;
++this->length;
if ((this->end==null)) {
this->head = node;
this->end = this->head;
}
else {
this->end->next = node;
this->end = node;
}
};
void queue__delete(struct queue* this,long int key){
if ((this->length==0)) {
return;
}
struct queueNode* current = this->head;
struct queueNode* previous= null;
while ((current->key!=key)) {
if ((current->next==null)) {
return;
}
previous = current;
current = current->next;
};
if ((current==this->head)) {
this->head = current->next;
}
else {
previous->next = current->next;
}
this->length = this->length-1;
};
void * queue__get(struct queue* this,long int key){
long int z = 0;
void * zp = (void *)z;
if ((this->length==0)) {
return zp;
}
struct queueNode* ptr = this->head;
while ((ptr->key!=key)) {
if ((ptr->next==null)) {
return zp;
}
ptr = ptr->next;
};
void * data = ptr->data;
return data;
};
void queue__set(struct queue* this,long int key,void * data){
queue__delete(this,key);
struct queueNode* ____BAH_COMPILER_VAR_5 = memoryAlloc(sizeof(struct queueNode));
struct queueNode* node = ____BAH_COMPILER_VAR_5;
node->key = key;
node->data = data;
node->next = this->head;
this->length = this->length+1;
this->head = node;
};
void * queue__pop(struct queue* this){
if ((this->head==null)) {
return null;
}
void * data = this->head->data;
this->head = this->head->next;
if ((this->head==null)) {
this->end = null;
}
--this->length;
return data;
};
void queue__clear(struct queue* this){
this->head = (void *)0;
this->length = 0;
};
struct channel {
pthread_mutex_t m_mut;
pthread_cond_t w_cond;
pthread_cond_t r_cond;
long int w_waitting;
long int r_waitting;
struct queue* queue;
long int cap;
};
void channel__send(struct channel* this,void * data){
pthread_mutex_lock(&this->m_mut);
if ((this->cap!=-1)) {
while ((this->queue->length==this->cap)) {
++this->w_waitting;
pthread_cond_wait(&this->w_cond,&this->m_mut);
--this->w_waitting;
};
}
queue__insert(this->queue,data);
if ((this->r_waitting>0)) {
pthread_cond_signal(&this->r_cond);
}
pthread_mutex_unlock(&this->m_mut);
};
void channel__sendAny(struct channel* this,void * data,long int len){
pthread_mutex_lock(&this->m_mut);
if ((this->cap!=-1)) {
while ((this->queue->length==this->cap)) {
++this->w_waitting;
pthread_cond_wait(&this->w_cond,&this->m_mut);
--this->w_waitting;
};
}
void * p = memoryAlloc(len);
memcpy(p,data,len);
queue__insert(this->queue,p);
if ((this->r_waitting>0)) {
pthread_cond_signal(&this->r_cond);
}
pthread_mutex_unlock(&this->m_mut);
};
void * channel__receive(struct channel* this){
pthread_mutex_lock(&this->m_mut);
while ((this->queue->length==0)) {
++this->r_waitting;
pthread_cond_wait(&this->r_cond,&this->m_mut);
--this->r_waitting;
};
void * data = queue__pop(this->queue);
if ((this->w_waitting>0)) {
pthread_cond_signal(&this->w_cond);
}
pthread_mutex_unlock(&this->m_mut);
return data;
};
void channel__destroy(struct channel* this){
pthread_mutex_destroy(&this->m_mut);
pthread_cond_destroy(&this->w_cond);
pthread_cond_destroy(&this->r_cond);
};
long int channel__len(struct channel* this){
long int l = this->queue->length;
return l;
};
struct channel* channel(){
struct channel* ____BAH_COMPILER_VAR_6 = memoryAlloc(sizeof(struct channel));
____BAH_COMPILER_VAR_6->cap = -1;
struct channel* c = ____BAH_COMPILER_VAR_6;
pthread_mutex_init(&c->m_mut,0);
pthread_cond_init(&c->w_cond,0);
pthread_cond_init(&c->r_cond,0);
struct queue* ____BAH_COMPILER_VAR_7 = memoryAlloc(sizeof(struct queue));
c->queue = ____BAH_COMPILER_VAR_7;
return c;
};
void setChanCap(void * c,long int cap){
struct channel* cp = c;
cp->cap = cap;
};
struct channel * __BAH_panic_chan;
void __Bah_common_panic(char * e){
if (strlen(e)) {
print(e);
print("\n");
cleanShutDown();
}
};
#define panic __Bah_common_panic
struct __Bah_fnName_mapper {
void * p;
char * n;
};
array(struct __Bah_fnName_mapper)* __Bah_fnNames;
void __Bah_fnNames_append(struct __Bah_fnName_mapper fnn){

    unsigned int ____BAH_COMPILER_VAR_8 = len(__Bah_fnNames);
    __Bah_realocate_arr(__Bah_fnNames, ____BAH_COMPILER_VAR_8);
    __Bah_fnNames->data[____BAH_COMPILER_VAR_8] = fnn;
};
void __BAH_panic(char * e,char * line){
if ((__BAH_panic_chan!=null)) {
channel__send(__BAH_panic_chan, e);
return;
}
char** ____BAH_COMPILER_VAR_9 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_9[4] = "\n";____BAH_COMPILER_VAR_9[3] = e;____BAH_COMPILER_VAR_9[2] = "): ";____BAH_COMPILER_VAR_9[1] = line;____BAH_COMPILER_VAR_9[0] = "panic (";char * ____BAH_COMPILER_VAR_10 =__Bah_multiple_concat(____BAH_COMPILER_VAR_9, 5);print(____BAH_COMPILER_VAR_10);
cleanShutDown();
};
char * (*onMemoryError)();
void __Bah_segfault_handle(long int sig){
char * res = "";
if ((onMemoryError!=null)) {
res = onMemoryError();
}
char** ____BAH_COMPILER_VAR_11 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_11[1] = res;____BAH_COMPILER_VAR_11[0] = "Memory error (segfault).\n";char * ____BAH_COMPILER_VAR_12 =__Bah_multiple_concat(____BAH_COMPILER_VAR_11, 2);__BAH_panic(____BAH_COMPILER_VAR_12,"???");
};
char __Bah_init_segfaultHandle(){
signal(SIGSEGV,__Bah_segfault_handle);
return true;
};
char __Bah_init_segfaultHandle_OK;
char recover(char ** s){
__BAH_panic_chan = channel();
char * ____BAH_COMPILER_VAR_13 =channel__receive(__BAH_panic_chan);char * err = ____BAH_COMPILER_VAR_13;
if ((s!=null)) {
*s = err;
}
return true;
};
char * __Bah_safe_string(char * s){
if (((void *)s==null)) {
return "(nil)";
}
if ((strlen(s)>50)) {
s = __STR(s);
array(char)* a = strAsArr(s);

    unsigned int ____BAH_COMPILER_VAR_14 = 47;
    __Bah_realocate_arr(a, ____BAH_COMPILER_VAR_14);
    a->data[____BAH_COMPILER_VAR_14] = 46;

    unsigned int ____BAH_COMPILER_VAR_15 = 48;
    __Bah_realocate_arr(a, ____BAH_COMPILER_VAR_15);
    a->data[____BAH_COMPILER_VAR_15] = 46;

    unsigned int ____BAH_COMPILER_VAR_16 = 49;
    __Bah_realocate_arr(a, ____BAH_COMPILER_VAR_16);
    a->data[____BAH_COMPILER_VAR_16] = 46;

    unsigned int ____BAH_COMPILER_VAR_17 = 50;
    __Bah_realocate_arr(a, ____BAH_COMPILER_VAR_17);
    a->data[____BAH_COMPILER_VAR_17] = (char)0;
}
char** ____BAH_COMPILER_VAR_18 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_18[2] = "\"";____BAH_COMPILER_VAR_18[1] = s;____BAH_COMPILER_VAR_18[0] = "\"";char * ____BAH_COMPILER_VAR_19 =__Bah_multiple_concat(____BAH_COMPILER_VAR_18, 3);return ____BAH_COMPILER_VAR_19;
};
char cpstringCharAt(char * s,long int i){
char c = (char)0;
c=s[i];
return c;
};
char * cpstringSubsitute(char * s,long int i,long int l){
long int size = l-i;
char * ns = memoryAllocSTR(size+1);
memcpy(ns,s+i,size);
return ns;
};
void * arraySubstitute(__BAH_ARR_TYPE_ptr arr,long int i,long int l){
long int length = l-i;
long int offset = i*arr->elemSize;
array(void *)* na = memoryAlloc(sizeof(array(void *)));

na->length = 0;
na->elemSize = sizeof(void *);
na->elemSize=arr->elemSize;
na->length=length;
long int allocLength = length;
if ((length>50)) {
allocLength = allocLength+allocLength%50;
}
else {
allocLength = 50;
}
long int size = allocLength*arr->elemSize;
long int realSize = length*arr->elemSize;
void * data = memoryAlloc(size);
char * oData = arr->data;
memcpy(data,oData+offset,realSize);
na->data=data;
return na;
};
long int __Bah_map_hash(char * s,long int l){
long int hash = 5381;
register long int i = 0;
for (; (i<strlen(s)); ++i) {
hash = ((long int)hash<<5+0)+hash+(long int)s[i];
};
if ((hash<0)) {
hash = 0-hash;
}
return hash%l;
};
struct mapElem {
char * key;
void * val;
};
struct mapWrapper {
array(struct mapElem*)* elems;
long int length;
};
void mapWrapper__grow(struct mapWrapper* this,long int nb){
long int l = len(this->elems);
register long int i = l;
for (; (i<l+nb); ++i) {

    unsigned int ____BAH_COMPILER_VAR_20 = i;
    __Bah_realocate_arr(this->elems, ____BAH_COMPILER_VAR_20);
    this->elems->data[____BAH_COMPILER_VAR_20] = null;
};
i = 0;
for (; (i<l); ++i) {
struct mapElem* e = this->elems->data[i];
if ((e==null)) {
continue;
}
long int ind = __Bah_map_hash(e->key,len(this->elems));
if ((ind!=i)) {
register long int j = ind;
for (; (j<len(this->elems)); ++j) {
if ((this->elems->data[j]==null)) {

    unsigned int ____BAH_COMPILER_VAR_21 = i;
    __Bah_realocate_arr(this->elems, ____BAH_COMPILER_VAR_21);
    this->elems->data[____BAH_COMPILER_VAR_21] = null;

    unsigned int ____BAH_COMPILER_VAR_22 = j;
    __Bah_realocate_arr(this->elems, ____BAH_COMPILER_VAR_22);
    this->elems->data[____BAH_COMPILER_VAR_22] = e;
break;
}
};
}
};
};
void mapWrapper__set(struct mapWrapper* this,char * k,void * e){
if ((this->length==0)) {
mapWrapper__grow(this,50);
}
if ((this->length*2>=len(this->elems))) {
mapWrapper__grow(this,this->length);
}
struct mapElem* ____BAH_COMPILER_VAR_23 = memoryAlloc(sizeof(struct mapElem));
____BAH_COMPILER_VAR_23->key = k;
____BAH_COMPILER_VAR_23->val = e;
struct mapElem* elem = ____BAH_COMPILER_VAR_23;
long int ind = __Bah_map_hash(k,len(this->elems));
register long int i = 0;
for (; (i<len(this->elems)); ++i) {
long int j = (i+ind)%len(this->elems);
struct mapElem* ce = this->elems->data[j];
if ((ce==null)) {

    unsigned int ____BAH_COMPILER_VAR_24 = j;
    __Bah_realocate_arr(this->elems, ____BAH_COMPILER_VAR_24);
    this->elems->data[____BAH_COMPILER_VAR_24] = elem;
++this->length;
break;
}
else if ((strcmp(ce->key, k) == 0)) {

    unsigned int ____BAH_COMPILER_VAR_25 = j;
    __Bah_realocate_arr(this->elems, ____BAH_COMPILER_VAR_25);
    this->elems->data[____BAH_COMPILER_VAR_25] = elem;
break;
}
};
};
void mapWrapper__setAny(struct mapWrapper* this,char * k,void * e,long int s){
if ((this->length==0)) {
mapWrapper__grow(this,50);
}
if ((this->length*2>=len(this->elems))) {
mapWrapper__grow(this,this->length);
}
void * p = memoryAlloc(s);
memcpy(p,e,s);
struct mapElem* ____BAH_COMPILER_VAR_26 = memoryAlloc(sizeof(struct mapElem));
____BAH_COMPILER_VAR_26->key = k;
____BAH_COMPILER_VAR_26->val = p;
struct mapElem* elem = ____BAH_COMPILER_VAR_26;
long int ind = __Bah_map_hash(k,len(this->elems));
register long int i = 0;
for (; (i<len(this->elems)); ++i) {
long int j = (i+ind)%len(this->elems);
struct mapElem* ce = this->elems->data[j];
if ((ce==null)) {

    unsigned int ____BAH_COMPILER_VAR_27 = j;
    __Bah_realocate_arr(this->elems, ____BAH_COMPILER_VAR_27);
    this->elems->data[____BAH_COMPILER_VAR_27] = elem;
++this->length;
break;
}
else if ((strcmp(ce->key, k) == 0)) {

    unsigned int ____BAH_COMPILER_VAR_28 = j;
    __Bah_realocate_arr(this->elems, ____BAH_COMPILER_VAR_28);
    this->elems->data[____BAH_COMPILER_VAR_28] = elem;
break;
}
};
};
void mapWrapper__delete(struct mapWrapper* this,char * k){
long int ind = __Bah_map_hash(k,len(this->elems));
register long int i = 0;
for (; (i<len(this->elems)); ++i) {
long int j = (i+ind)%len(this->elems);
struct mapElem* e = this->elems->data[j];
if ((e!=null)&&(strcmp(e->key, k) == 0)) {

    unsigned int ____BAH_COMPILER_VAR_29 = j;
    __Bah_realocate_arr(this->elems, ____BAH_COMPILER_VAR_29);
    this->elems->data[____BAH_COMPILER_VAR_29] = null;
}
};
};
void * mapWrapper__get(struct mapWrapper* this,char * k){
long int ind = __Bah_map_hash(k,len(this->elems));
register long int i = 0;
for (; (i<len(this->elems)); ++i) {
long int j = (i+ind)%len(this->elems);
struct mapElem* e = this->elems->data[j];
if ((e!=null)&&(strcmp(e->key, k) == 0)) {
return e->val;
}
};
return null;
};
struct mapWrapper* mapWrapper(){
struct mapWrapper* ____BAH_COMPILER_VAR_30 = memoryAlloc(sizeof(struct mapWrapper));
____BAH_COMPILER_VAR_30->elems = memoryAlloc(sizeof(array(struct mapElem*)));
            ____BAH_COMPILER_VAR_30->elems->length = 0;
            ____BAH_COMPILER_VAR_30->elems->elemSize = sizeof(struct mapElem*);
            struct mapWrapper* m = ____BAH_COMPILER_VAR_30;
mapWrapper__grow(m,50);
return m;
};
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
char * stdinput(){
char * buff = memoryAlloc(1025);
char * response = "";
register long int nDataLength = read((void *)0,buff,1024);
if ((nDataLength<1024)) {
char** ____BAH_COMPILER_VAR_31 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_31[1] = buff;____BAH_COMPILER_VAR_31[0] = response;char * ____BAH_COMPILER_VAR_32 =__Bah_multiple_concat(____BAH_COMPILER_VAR_31, 2);response = ____BAH_COMPILER_VAR_32;
}
else {
while ((nDataLength>0)) {
char** ____BAH_COMPILER_VAR_33 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_33[1] = buff;____BAH_COMPILER_VAR_33[0] = response;char * ____BAH_COMPILER_VAR_34 =__Bah_multiple_concat(____BAH_COMPILER_VAR_33, 2);response = ____BAH_COMPILER_VAR_34;
if ((nDataLength<1024)) {
long int trimAmm = 1024-nDataLength;
strTrimRight(&response,trimAmm);
break;
}
else {
nDataLength = read((void *)0,buff,1024);
}
};
}
strTrimRight(&response,1);
return response;
};
void println(char * s){
char** ____BAH_COMPILER_VAR_35 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_35[1] = "\n";____BAH_COMPILER_VAR_35[0] = s;char * ____BAH_COMPILER_VAR_36 =__Bah_multiple_concat(____BAH_COMPILER_VAR_35, 2);write((void *)1,____BAH_COMPILER_VAR_36,strlen(s)+1);
};
struct fileStream {
FILE* handle;
char * name;
};
long int fileStream__isValid(struct fileStream* this){
if ((this->handle==null)) {
return 0;
}
return 1;
};
void fileStream__open(struct fileStream* this,char * path,char * mode){
this->name = path;
this->handle = fopen(path,mode);
};
void fileStream__close(struct fileStream* this){
if ((fileStream__isValid(this)==0)) {
return;
}
fclose(this->handle);
this->handle = null;
};
long int fileStream__getPos(struct fileStream* this){
if ((fileStream__isValid(this)==0)) {
return 0;
}
return ftell(this->handle);
};
void fileStream__setPos(struct fileStream* this,long int i){
if ((fileStream__isValid(this)==0)) {
return;
}
fseek(this->handle,i,0);
};
long int fileStream__getSize(struct fileStream* this){
if ((fileStream__isValid(this)==0)) {
return -1;
}
long int oldPos = fileStream__getPos(this);
fseek(this->handle,0,2);
long int size = ftell(this->handle);
fileStream__setPos(this,oldPos);
return size;
};
void fileStream__rewind(struct fileStream* this){
rewind(this->handle);
};
char fileStream__getChar(struct fileStream* this){
char c = getc(this->handle);
return c;
};
void fileStream__setChar(struct fileStream* this,char c){
fputc(c,this->handle);
};
void fileStream__createFile(struct fileStream* this,char * path){
fileStream__open(this,path,"w");
fileStream__close(this);
};
long int fileStream__writeFile(struct fileStream* this,char * content){
if ((fileStream__isValid(this)==0)) {
return -1;
}
fputs(content,this->handle);
return 1;
};
void fileStream__writePtr(struct fileStream* this,void * a,long int s){
fwrite(a,s,1,this->handle);
};
long int fileStream__readPtr(struct fileStream* this,void * a,long int s){
return fread(a,s,1,this->handle);
};
char * fileStream__readContent(struct fileStream* this){
if ((fileStream__isValid(this)==0)) {
return "invalid";
}
long int sz = fileStream__getSize(this);
char * r = memoryAllocSTR(sz+1);
long int l = fread(r,1,sz,this->handle);
if ((sz!=l)) {
array(char)* rarr = strAsArr(r);

    unsigned int ____BAH_COMPILER_VAR_37 = l;
    __Bah_realocate_arr(rarr, ____BAH_COMPILER_VAR_37);
    rarr->data[____BAH_COMPILER_VAR_37] = (char)0;
}
return r;
};
__BAH_ARR_TYPE_char fileStream__readBytes(struct fileStream* this){
array(char)* r = memoryAlloc(sizeof(array(char)));

r->length = 0;
r->elemSize = sizeof(char);
allocateArray(r,fileStream__getSize(this));
fileStream__readPtr(this,r->data,len(r));
return r;
};
void fileStream__writeBytes(struct fileStream* this,__BAH_ARR_TYPE_char d){
fileStream__writePtr(this,d->data,len(d));
};
void fileStream___end(struct fileStream* this){
if (fileStream__isValid(this)) {
char** ____BAH_COMPILER_VAR_38 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_38[2] = "'.";____BAH_COMPILER_VAR_38[1] = this->name;____BAH_COMPILER_VAR_38[0] = "iostream: warning, auto-closing file: '";char * ____BAH_COMPILER_VAR_39 =__Bah_multiple_concat(____BAH_COMPILER_VAR_38, 3);println(____BAH_COMPILER_VAR_39);
fileStream__close(this);
}
};
struct fileMap {
long int handle;
long int size;
void * p;
};
char * fileMap__open(struct fileMap* this,char * fileName){
this->handle = open(fileName,O_RDWR,S_IRUSR|S_IWUSR);
struct stat ____BAH_COMPILER_VAR_40 = {};
#define sb ____BAH_COMPILER_VAR_40
fstat(this->handle,&sb);
this->size = sb.st_size;
this->p = mmap(0,sb.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,this->handle,0);
return this->p;
};
long int fileMap__isValid(struct fileMap* this){
if ((this->handle<0)) {
return 0;
}
return 1;
};
void fileMap__close(struct fileMap* this){
if ((this->handle==-1)) {
return;
}
munmap(this->p,this->size);
close(this->handle);
};
__BAH_ARR_TYPE_cpstring listFiles(char * dir){
array(char *)* files = memoryAlloc(sizeof(array(char *)));

files->length = 0;
files->elemSize = sizeof(char *);
DIR* d = opendir(dir);
struct dirent* file = readdir(d);
while ((file!=null)) {
long int lf = len(files);
if ((strcmp(file->d_name,".")==0)) {
file = readdir(d);
continue;
}
if ((strcmp(file->d_name,"..")==0)) {
file = readdir(d);
continue;
}

    unsigned int ____BAH_COMPILER_VAR_41 = lf;
    __Bah_realocate_arr(files, ____BAH_COMPILER_VAR_41);
    files->data[____BAH_COMPILER_VAR_41] = __STR(file->d_name);
file = readdir(d);
};
closedir(d);
return files;
};
long int fileExists(char * path){
long int is = access(path,0);
if ((is==0)) {
return 1;
}
return 0;
};
char isFolder(char * path){
struct stat s;
if ((stat(path,&s)!=0)) {
return false;
}
if (s.st_mode&S_IFDIR) {
return true;
}
return false;
};
char removeFile(char * name){
if ((remove(name)==0)) {
return true;
}
return false;
};
long int getLastModified(char * name){
struct stat attr;
stat(name,&attr);
return attr.st_ctime;
};
#include <string.h>
#include <math.h>
#include <stdlib.h>
void strCatOffset(char * dest,long int destLen,char * src,long int srcLen){
memcpy(dest+destLen,src,srcLen);
};
char * charToString(char c){
char * s = memoryAlloc(2);
strncpy(s,(char *)&c,1);
return s;
};
char isUpper(char c){
return (c>=65)&&(c<=90);
};
char isLower(char c){
return (c>=97)&&(c<=122);
};
char isLetter(char s){
return isLower(s)||isUpper(s);
};
char isNumber(char c){
return (c>=48)&&(c<=57);
};
char isAlphaNumeric(char s){
return isLetter(s)||isNumber(s);
};
char isSpace(char c){
return (c==(char)32)||(c==(char)9)||(c==(char)10)||(c==(char)11)||(c==(char)13);
};
struct string {
char * content;
char editable;
long int length;
};
void string__set(struct string* this,char * s){
this->length = strlen(s);
this->editable = false;
this->content = s;
};
void string__makeEditable(struct string* this){
this->editable = true;
char * old = this->content;
this->content = (char *)memoryAlloc(this->length+1);
strncpy(this->content,old,this->length);
};
void string__append(struct string* this,char * s){
if ((this->editable==false)) {
string__makeEditable(this);
}
long int sl = strlen(s);
long int nl = sl+this->length;
void * nc = memoryRealloc(this->content,nl+1);
if ((nc==null)) {
__BAH_panic("Error appending to string, possibly due to memory shortage.","/opt/bah/string.bah:95");
}
this->content = nc;
strCatOffset(this->content,this->length,s,sl);
this->length = nl;
};
void string__prepend(struct string* this,char * s){
this->editable = true;
long int sl = strlen(s);
long int nl = this->length+sl;
char * tmpS = this->content;
void * nc = memoryAlloc(nl+1);
if ((nc==null)) {
__BAH_panic("Error appending to string, possibly due to memory shortage.","/opt/bah/string.bah:110");
}
this->content = nc;
strncpy(this->content,s,sl);
strCatOffset(this->content,sl,tmpS,this->length);
this->length = nl;
};
char string__charAt(struct string* this,long int i){
return this->content[i];
};
long int string__compare(struct string* this,char * s){
return (strcmp(this->content,s)==0);
};
char * string__str(struct string* this){
return this->content;
};
void string__replace(struct string* this,char * nd,char * rl){
if ((this->editable==false)) {
string__makeEditable(this);
}
struct string ____BAH_COMPILER_VAR_42 = {};
#define needle ____BAH_COMPILER_VAR_42
string__set(&needle,nd);
struct string ____BAH_COMPILER_VAR_43 = {};
#define repl ____BAH_COMPILER_VAR_43
string__set(&repl,rl);
register long int i = 0;
long int si = 0;
long int replcBuffSart = 0;
long int replcBuffLength = 0;
array(char)* buff = memoryAlloc(sizeof(array(char)));

buff->length = 0;
buff->elemSize = sizeof(char);
while ((i<this->length)) {
char c = string__charAt(this,i);
char rc = string__charAt(&needle,si);
if ((c==rc)) {
si = si+1;
if ((replcBuffLength==0)) {
replcBuffSart = i;
}
replcBuffLength = replcBuffLength+1;
}
else {
if ((replcBuffLength>0)) {
si = 0;
register long int j = 0;
while ((j<replcBuffLength)) {

    unsigned int ____BAH_COMPILER_VAR_44 = len(buff);
    __Bah_realocate_arr(buff, ____BAH_COMPILER_VAR_44);
    buff->data[____BAH_COMPILER_VAR_44] = string__charAt(this,j+replcBuffSart);
j = j+1;
};
replcBuffLength = 0;
}

    unsigned int ____BAH_COMPILER_VAR_45 = len(buff);
    __Bah_realocate_arr(buff, ____BAH_COMPILER_VAR_45);
    buff->data[____BAH_COMPILER_VAR_45] = c;
}
if ((si==needle.length)) {
replcBuffLength = 0;
register long int ii = 0;
while ((ii<repl.length)) {
long int a = ii;

    unsigned int ____BAH_COMPILER_VAR_46 = len(buff);
    __Bah_realocate_arr(buff, ____BAH_COMPILER_VAR_46);
    buff->data[____BAH_COMPILER_VAR_46] = string__charAt(&repl,ii);
ii = ii+1;
};
si = 0;
}
i = i+1;
};
char * r = arrToStr(buff);
if ((replcBuffLength>0)) {
array(char)* replbuffStr = memoryAlloc(sizeof(array(char)));

replbuffStr->length = 0;
replbuffStr->elemSize = sizeof(char);
allocateArray(replbuffStr,replcBuffLength+1);
register long int j = 0;
while ((j<replcBuffLength)) {

    unsigned int ____BAH_COMPILER_VAR_47 = j;
    __Bah_realocate_arr(replbuffStr, ____BAH_COMPILER_VAR_47);
    replbuffStr->data[____BAH_COMPILER_VAR_47] = string__charAt(this,j+replcBuffSart);
j = j+1;
};
char** ____BAH_COMPILER_VAR_48 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_48[1] = arrAsStr(replbuffStr);____BAH_COMPILER_VAR_48[0] = r;char * ____BAH_COMPILER_VAR_49 =__Bah_multiple_concat(____BAH_COMPILER_VAR_48, 2);r = ____BAH_COMPILER_VAR_49;
}
if (((void *)r!=null)) {
string__set(this,r);
}

#undef needle

#undef repl
};
long int string__countChar(struct string* this,char need){
long int c = 0;
register long int i = 0;
for (; (i<this->length); ++i) {
if ((string__charAt(this,i)==need)) {
++c;
}
};
return c;
};
long int string__count(struct string* this,char * need){
if ((strlen(need)==1)) {
return string__countChar(this,need[0]);
}
register long int i = 0;
long int count = 0;
struct string ____BAH_COMPILER_VAR_50 = {};
#define needle ____BAH_COMPILER_VAR_50
string__set(&needle,need);
long int countIndex = 0;
while ((i<this->length)) {
char c = string__charAt(this,i);
char sc = string__charAt(&needle,countIndex);
if ((c==sc)) {
countIndex = countIndex+1;
}
else {
countIndex = 0;
}
if ((countIndex==needle.length)) {
count = count+1;
countIndex = 0;
}
i = i+1;
};
return count;
};
long int string__hasPrefix(struct string* this,char * need){
register long int i = 0;
long int nl = strlen(need);
if ((this->length<nl)) {
return 0;
}
while ((i<nl)) {
char c = string__charAt(this,i);
char sc = cpstringCharAt(need,i);
if ((c!=sc)) {
return 0;
}
i = i+1;
};
return 1;
};
long int string__hasSuffix(struct string* this,char * need){
long int nl = strlen(need);
if ((this->length<nl)) {
return 0;
}
register long int i = this->length-nl;
long int needleIndex = 0;
while ((i<this->length)) {
char c = string__charAt(this,i);
char sc = cpstringCharAt(need,needleIndex);
if ((c!=sc)) {
return 0;
}
needleIndex = needleIndex+1;
i = i+1;
};
return 1;
};
void string__trim(struct string* this){
if ((this->length==0)) {
return;
}
char fc = string__charAt(this,0);
if ((isSpace(fc)==false)) {
return;
}
register long int i = 0;
for (; (i<this->length); ++i) {
if ((isSpace(string__charAt(this,i))==false)) {
break;
}
};
if ((i>0)) {
this->length = this->length-i;
char * tmpS = memoryAlloc(this->length+1);
memcpy(tmpS,this->content+i,this->length+1);
this->content = tmpS;
this->editable = true;
}
};
void string__trimLeft(struct string* this,long int s){
if ((s>this->length)) {
return;
}
long int nSize = this->length-s;
void * tmpS = memoryAlloc(nSize+1);
memcpy(tmpS,this->content+s,nSize);
this->content = tmpS;
this->editable = true;
this->length = nSize;
};
void string__trimRight(struct string* this,long int s){
if ((s>this->length)) {
return;
}
long int nSize = this->length-s;
void * tmpS = memoryAlloc(nSize+1);
memcpy(tmpS,this->content,nSize);
this->content = tmpS;
this->editable = true;
this->length = nSize;
};
struct string string__add(struct string* this,struct string s2){
struct string ____BAH_COMPILER_VAR_51 = {};
#define r ____BAH_COMPILER_VAR_51
r.length = this->length+s2.length;
r.content = memoryAlloc(r.length+1);
strncpy(r.content,this->content,this->length);
strCatOffset(r.content,this->length,s2.content,s2.length);
return r;
};
__BAH_ARR_TYPE_char string__asArr(struct string* this){
if ((this->editable==false)) {
string__makeEditable(this);
}
array(char)* arr = memoryAlloc(sizeof(array(char)));

arr->length = 0;
arr->elemSize = sizeof(char);
arr->data=this->content;
arr->length=this->length;
arr->realLength=this->length;
return arr;
};
struct string string(char * s){
struct string ____BAH_COMPILER_VAR_52 = {};
#define a ____BAH_COMPILER_VAR_52
string__set(&a,s);
return a;

#undef a
};
char * intToStr(long int i){
if ((i==0)) {
return "0";
}
char ____BAH_COMPILER_VAR_53[66];char* s = ____BAH_COMPILER_VAR_53;
long int ind = -1;
char subZero = (i<0);
if ((subZero==true)) {
i = 0-i;
}
for (; (i!=0); i = i/10) {
long int conv = i%10;
conv = conv+48;
s[ind+1] = (char)conv;
++ind;
};
if ((subZero==true)) {
s[ind+1] = 45;
++ind;
}
long int ls = ind+1;
i = 0;
for (; (i<ls/2); ++i) {
long int ii = ls-i-1;
char osi = s[i];
s[i] = s[ii];
s[ii] = osi;
};
s[ind+1] = (char)0;
return __STR(s);
};
struct string intToString(long int i){
char * ____BAH_COMPILER_VAR_54 =intToStr(i);struct string r = string(____BAH_COMPILER_VAR_54);
return r;
};
char * floatToStr(double f){
char ____BAH_COMPILER_VAR_55[50];char* buff = ____BAH_COMPILER_VAR_55;
sprintf(buff,"%lf",f);
return __STR(buff);
};
long int strToInt(char * s){
register long int l = strlen(s)-1;
long int offset = 1;
long int r = 0;
long int end = 0;
if ((s[0]==45)) {
end = 1;
}
for (; (l>=end); --l) {
if ((s[l]<48)||(s[l]>57)) {
continue;
}
r = r+((long int)s[l]-48)*offset;
offset = offset*10;
};
if ((end==1)) {
r = 0-r;
}
return r;
};
double strToFloat(char * s){
return strtod(s,null);
};
long int stringToInt(struct string s){
long int i = atol(s.content);
return i;
};
typedef array(struct string)* __BAH_ARR_TYPE_string;
__BAH_ARR_TYPE_string splitString(struct string s,char * sp){
struct string sep = string(sp);
array(struct string)* res = memoryAlloc(sizeof(array(struct string)));

res->length = 0;
res->elemSize = sizeof(struct string);
struct string sepBuffer = string("");
long int sepIndex = 0;
register long int i = 0;
struct string replcBuff = string("");
array(char)* tmpString = memoryAlloc(sizeof(array(char)));

tmpString->length = 0;
tmpString->elemSize = sizeof(char);
while ((i<s.length)) {
char c = string__charAt(&s,i);
char sepc = string__charAt(&sep,sepIndex);
if ((c==sepc)) {
sepIndex = sepIndex+1;
char * ____BAH_COMPILER_VAR_56 =charToString(c);string__append(&replcBuff,____BAH_COMPILER_VAR_56);
}
else {
if ((sepIndex>0)) {
sepIndex = 0;
char * ____BAH_COMPILER_VAR_57 =charToString(c);string__append(&replcBuff,____BAH_COMPILER_VAR_57);
register long int ii = 0;
while ((ii<replcBuff.length)) {

    unsigned int ____BAH_COMPILER_VAR_58 = len(tmpString);
    __Bah_realocate_arr(tmpString, ____BAH_COMPILER_VAR_58);
    tmpString->data[____BAH_COMPILER_VAR_58] = string__charAt(&replcBuff,ii);
ii = ii+1;
};
string__set(&replcBuff,"");
}
else {

    unsigned int ____BAH_COMPILER_VAR_59 = len(tmpString);
    __Bah_realocate_arr(tmpString, ____BAH_COMPILER_VAR_59);
    tmpString->data[____BAH_COMPILER_VAR_59] = c;
}
}
if ((sepIndex==sep.length)) {
string__set(&replcBuff,"");
struct string* ____BAH_COMPILER_VAR_60 = memoryAlloc(sizeof(struct string));
struct string* elem = ____BAH_COMPILER_VAR_60;
char * ____BAH_COMPILER_VAR_61 =arrToStr(tmpString);string__set(elem,____BAH_COMPILER_VAR_61);
long int lenRes = len(res);

    unsigned int ____BAH_COMPILER_VAR_62 = lenRes;
    __Bah_realocate_arr(res, ____BAH_COMPILER_VAR_62);
    res->data[____BAH_COMPILER_VAR_62] = *elem;
clear(tmpString);
sepIndex = 0;
}
i = i+1;
};
if ((replcBuff.length>0)) {
register long int ii = 0;
while ((ii<replcBuff.length)) {

    unsigned int ____BAH_COMPILER_VAR_63 = len(tmpString);
    __Bah_realocate_arr(tmpString, ____BAH_COMPILER_VAR_63);
    tmpString->data[____BAH_COMPILER_VAR_63] = string__charAt(&replcBuff,ii);
ii = ii+1;
};
}
if ((len(tmpString)>0)) {
struct string* ____BAH_COMPILER_VAR_64 = memoryAlloc(sizeof(struct string));
struct string* elem = ____BAH_COMPILER_VAR_64;
char * ____BAH_COMPILER_VAR_65 =arrToStr(tmpString);string__set(elem,____BAH_COMPILER_VAR_65);
long int lenRes = len(res);

    unsigned int ____BAH_COMPILER_VAR_66 = lenRes;
    __Bah_realocate_arr(res, ____BAH_COMPILER_VAR_66);
    res->data[____BAH_COMPILER_VAR_66] = *elem;
}
return res;
};
struct string joinString(__BAH_ARR_TYPE_string a,char * sep){
register long int i = 0;
struct string s = string("");
long int max = len(a)-1;
while ((i<len(a))) {
struct string e = a->data[i];
if ((e.length==0)) {
i = i+1;
continue;
}
char * ____BAH_COMPILER_VAR_67 =string__str(&e);struct string tmpS = string(____BAH_COMPILER_VAR_67);
if ((i!=max)) {
string__append(&tmpS,sep);
}
char * ____BAH_COMPILER_VAR_68 =string__str(&tmpS);string__append(&s,____BAH_COMPILER_VAR_68);
i = i+1;
};
return s;
};
char * splitStringBefore(struct string s,char * sp){
struct string sep = string(sp);
if ((sep.length>=s.length)) {
return "";
}
long int sepIndex = 0;
long int foundIndex = 0;
register long int i = 0;
while ((i<s.length)) {
char c = string__charAt(&s,i);
char sc = string__charAt(&sep,sepIndex);
if ((c==sc)) {
if ((sepIndex==0)) {
foundIndex = i-1;
}
sepIndex = sepIndex+1;
if ((sepIndex==sep.length)) {
long int max = s.length-foundIndex-1;
string__trimRight(&s,max);
return string__str(&s);
}
}
else {
foundIndex = 0;
sepIndex = 0;
}
i = i+1;
};
return "";
};
struct string toLower(struct string s){
array(char)* ns = memoryAlloc(sizeof(array(char)));

ns->length = 0;
ns->elemSize = sizeof(char);
register long int i = 0;
while ((i<s.length)) {
char c = string__charAt(&s,i);
if (isUpper(c)) {
c = c+(char)32;
}

    unsigned int ____BAH_COMPILER_VAR_69 = len(ns);
    __Bah_realocate_arr(ns, ____BAH_COMPILER_VAR_69);
    ns->data[____BAH_COMPILER_VAR_69] = c;
i = i+1;
};
char * ____BAH_COMPILER_VAR_70 =arrToStr(ns);return string(____BAH_COMPILER_VAR_70);
};
char strHasPrefix(char * s,char * need){
register long int i = 0;
long int nl = strlen(need);
long int sl = strlen(s);
if ((sl<nl)) {
return false;
}
while ((i<nl)) {
if ((cpstringCharAt(s,i)!=cpstringCharAt(need,i))) {
return false;
}
i = i+1;
};
return true;
};
char strHasSuffix(char * s,char * need){
long int sl = strlen(s);
long int nl = strlen(need);
if ((nl>sl)) {
return false;
}
register long int i = sl-nl;
while ((i<sl)) {
if ((cpstringCharAt(s,i)!=cpstringCharAt(need,i))) {
return false;
}
i = i+1;
};
return true;
};
void strTrim(char ** s){
long int l = strlen(*s);
register long int i = 0;
while ((i<l)) {
char c = cpstringCharAt(*s,i);
if ((isSpace(c)==false)) {
break;
}
i = i+1;
};
*s = *s+i;
};
long int strCount(char * src,char * needle){
register long int i = 0;
long int count = 0;
long int countIndex = 0;
long int sl = strlen(src);
long int nl = strlen(needle);
while ((i<sl)) {
char c = cpstringCharAt(src,i);
char sc = cpstringCharAt(needle,countIndex);
if ((c==sc)) {
countIndex = countIndex+1;
}
else {
countIndex = 0;
}
if ((countIndex==nl)) {
count = count+1;
countIndex = 0;
}
i = i+1;
};
return count;
};
#define FLAG_TYPE_CPSTRING 0
#define FLAG_TYPE_INT 1
#define FLAG_TYPE_FLOAT 2
#define FLAG_TYPE_BOOL 3
struct flag {
char * name;
char * help;
char * content;
long int cont_int;
double cont_float;
long int isSet;
long int type;
};
struct flags {
array(struct flag*)* flags;
array(char *)* args;
};
void flags__addString(struct flags* this,char * name,char * help){
struct flag* ____BAH_COMPILER_VAR_71 = memoryAlloc(sizeof(struct flag));
struct flag* f = ____BAH_COMPILER_VAR_71;
f->name = name;
f->help = help;
f->type = FLAG_TYPE_CPSTRING;
long int lf = len(this->flags);

    unsigned int ____BAH_COMPILER_VAR_72 = lf;
    __Bah_realocate_arr(this->flags, ____BAH_COMPILER_VAR_72);
    this->flags->data[____BAH_COMPILER_VAR_72] = f;
};
void flags__addBool(struct flags* this,char * name,char * help){
struct flag* ____BAH_COMPILER_VAR_73 = memoryAlloc(sizeof(struct flag));
struct flag* f = ____BAH_COMPILER_VAR_73;
f->name = name;
f->help = help;
f->type = FLAG_TYPE_BOOL;
long int lf = len(this->flags);

    unsigned int ____BAH_COMPILER_VAR_74 = lf;
    __Bah_realocate_arr(this->flags, ____BAH_COMPILER_VAR_74);
    this->flags->data[____BAH_COMPILER_VAR_74] = f;
};
void flags__addInt(struct flags* this,char * name,char * help){
struct flag* ____BAH_COMPILER_VAR_75 = memoryAlloc(sizeof(struct flag));
struct flag* f = ____BAH_COMPILER_VAR_75;
f->name = name;
f->help = help;
f->type = FLAG_TYPE_INT;
long int lf = len(this->flags);

    unsigned int ____BAH_COMPILER_VAR_76 = lf;
    __Bah_realocate_arr(this->flags, ____BAH_COMPILER_VAR_76);
    this->flags->data[____BAH_COMPILER_VAR_76] = f;
};
void flags__addFloat(struct flags* this,char * name,char * help){
struct flag* ____BAH_COMPILER_VAR_77 = memoryAlloc(sizeof(struct flag));
struct flag* f = ____BAH_COMPILER_VAR_77;
f->name = name;
f->help = help;
f->type = FLAG_TYPE_FLOAT;
long int lf = len(this->flags);

    unsigned int ____BAH_COMPILER_VAR_78 = lf;
    __Bah_realocate_arr(this->flags, ____BAH_COMPILER_VAR_78);
    this->flags->data[____BAH_COMPILER_VAR_78] = f;
};
void flags__invalidate(struct flags* this){
print("Usage of ");
print(this->args->data[0]);
println(":");
register long int i = 0;
while ((i<len(this->flags))) {
struct flag* flag = this->flags->data[i];
print("    -");
print(flag->name);
if ((flag->type==FLAG_TYPE_CPSTRING)) {
println(" (string)");
}
else if ((flag->type==FLAG_TYPE_BOOL)) {
println(" (bool)");
}
else if ((flag->type==FLAG_TYPE_INT)) {
println(" (int)");
}
else if ((flag->type==FLAG_TYPE_FLOAT)) {
println(" (float)");
}
print("\t");
println(flag->help);
i = i+1;
};
exit(1);
};
struct flag* flags__getFlag(struct flags* this,struct string name){
register long int i = 0;
while ((i<len(this->flags))) {
struct flag* flag = this->flags->data[i];
if (string__compare(&name,flag->name)) {
return flag;
}
i = i+1;
};
struct flag* ____BAH_COMPILER_VAR_79 = memoryAlloc(sizeof(struct flag));
struct flag* z = ____BAH_COMPILER_VAR_79;
z->isSet = 0;
return z;
};
char * flags__get(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_80 =string(name);struct flag* flag = flags__getFlag(this,____BAH_COMPILER_VAR_80);
return flag->content;
};
long int flags__getInt(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_81 =string(name);struct flag* flag = flags__getFlag(this,____BAH_COMPILER_VAR_81);
if ((flag->type!=FLAG_TYPE_INT)) {
char** ____BAH_COMPILER_VAR_82 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_82[2] = "' is not int.";____BAH_COMPILER_VAR_82[1] = flag->name;____BAH_COMPILER_VAR_82[0] = "Flag '";char * ____BAH_COMPILER_VAR_83 =__Bah_multiple_concat(____BAH_COMPILER_VAR_82, 3);__BAH_panic(____BAH_COMPILER_VAR_83,"/opt/bah/flags.bah:122");
}
return flag->cont_int;
};
double flags__getFloat(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_84 =string(name);struct flag* flag = flags__getFlag(this,____BAH_COMPILER_VAR_84);
if ((flag->type!=FLAG_TYPE_FLOAT)) {
char** ____BAH_COMPILER_VAR_85 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_85[2] = "' is not float.";____BAH_COMPILER_VAR_85[1] = flag->name;____BAH_COMPILER_VAR_85[0] = "Flag '";char * ____BAH_COMPILER_VAR_86 =__Bah_multiple_concat(____BAH_COMPILER_VAR_85, 3);__BAH_panic(____BAH_COMPILER_VAR_86,"/opt/bah/flags.bah:132");
}
return flag->cont_float;
};
long int flags__isSet(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_87 =string(name);struct flag* flag = flags__getFlag(this,____BAH_COMPILER_VAR_87);
return flag->isSet;
};
void flags__parse(struct flags* this,__BAH_ARR_TYPE_cpstring args){
struct flag* currentFlag= null;
char isVal = false;
this->args = args;
register long int i = 1;
while ((i<len(args))) {
struct string argName = string(args->data[i]);
if ((isVal==true)) {
currentFlag->content = string__str(&argName);
if ((currentFlag->type==FLAG_TYPE_INT)) {
char * ____BAH_COMPILER_VAR_88 =string__str(&argName);currentFlag->cont_int = strToInt(____BAH_COMPILER_VAR_88);
}
else if ((currentFlag->type==FLAG_TYPE_FLOAT)) {
char * ____BAH_COMPILER_VAR_89 =string__str(&argName);currentFlag->cont_float = strToFloat(____BAH_COMPILER_VAR_89);
}
isVal = false;
}
else {
if ((string__charAt(&argName,0)!=45)) {
i = i+1;
continue;
}
string__trimLeft(&argName,1);
if (string__compare(&argName,"help")) {
flags__invalidate(this);
}
else if (string__compare(&argName,"h")) {
flags__invalidate(this);
}
currentFlag = flags__getFlag(this,argName);
if ((currentFlag==null)) {
flags__invalidate(this);
}
currentFlag->isSet = 1;
if ((currentFlag->type!=FLAG_TYPE_BOOL)) {
isVal = true;
}
}
i = i+1;
};
if ((isVal==true)) {
if ((currentFlag->type!=FLAG_TYPE_BOOL)) {
flags__invalidate(this);
}
}
};
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <mach/clock.h>
#define TIME_MS 1000000
#define TIME_S 1000000000
#define TIME_MIN 60000000000
struct time {
long int timestamp;
};
void time__now(struct time* this){
this->timestamp = time(0);
};
char * time__format(struct time* this,char * a){
long int lt = localtime(&this->timestamp);
char * date = memoryAlloc(1024);
strftime(date,1024,a,lt);
return date;
};
long int time__since(struct time* this){
long int nt = time(0);
long int r = nt-this->timestamp;
return r;
};
long int getTimeUnix(){
struct timespec ____BAH_COMPILER_VAR_90 = {};
#define ts ____BAH_COMPILER_VAR_90
clock_serv_t cclock;
mach_timespec_t mts;
void * ____BAH_COMPILER_VAR_91 =mach_host_self();host_get_clock_service(____BAH_COMPILER_VAR_91,CALENDAR_CLOCK,&cclock);
clock_get_time(cclock,&mts);
void * ____BAH_COMPILER_VAR_92 =mach_task_self();mach_port_deallocate(____BAH_COMPILER_VAR_92,cclock);
mach_timespec_t* mtsp = &mts;
ts.tv_sec = mtsp->tv_sec;
ts.tv_nsec = mtsp->tv_nsec;
long int s = ts.tv_sec*1000000000+ts.tv_nsec;
return s;

#undef ts
};
char RAND_SEEDED;
void seedRandom(long int i){
srand(i);
RAND_SEEDED = 1;
};
long int randomInRange(long int min,long int max){
if ((RAND_SEEDED==false)) {
srand(time(0)+getTimeUnix());
RAND_SEEDED = true;
}
long int range = max-min;
long int i = rand()%range+1;
i = i+min;
return i;
};
long int cryptoRand(){
struct fileStream ____BAH_COMPILER_VAR_93 = {};
#define fs ____BAH_COMPILER_VAR_93
fileStream__open(&fs,"/dev/urandom","r");
char c = fileStream__getChar(&fs);
fileStream__close(&fs);
long int i = (long int)c;
return i;

#undef fs
};
#define ROPE_LEAF_LEN 200
struct rope {
struct rope* left;
struct rope* right;
char * str;
int lCount;
int len;
int totalLen;
};
void rope__addStr(struct rope* this,char * s,long int* offset){
if ((this->left==null)&&(this->right==null)) {
long int off = *offset;
memcpy(s+off,this->str,this->lCount+1);
*offset = *offset+this->lCount+1;
return;
}
long int l = *offset;
rope__addStr(this->left,s,offset);
rope__addStr(this->right,s,offset);
};
char * rope__toStr(struct rope* this){
if ((this->left==null)&&(this->right==null)) {
return this->str;
}
char * s = memoryAlloc(this->totalLen+1);
long int offset = 0;
rope__addStr(this->left,s,&offset);
rope__addStr(this->right,s,&offset);
return s;
};
struct rope* rope__add(struct rope* this,struct rope* root2){
int n1 = this->len;
struct rope* ____BAH_COMPILER_VAR_94 = memoryAlloc(sizeof(struct rope));
struct rope* tmp = ____BAH_COMPILER_VAR_94;
tmp->left = this;
tmp->right = root2;
tmp->totalLen = this->totalLen+root2->totalLen;
tmp->str = null;
return tmp;
};
struct rope* createRopeStructure(struct rope* par,char * a,long int l,long int r){
struct rope* ____BAH_COMPILER_VAR_95 = memoryAlloc(sizeof(struct rope));
struct rope* tmp = ____BAH_COMPILER_VAR_95;
tmp->left = null;
tmp->right = null;
if ((r-l>ROPE_LEAF_LEN)) {
tmp->str = null;
tmp->lCount = r-l;
tmp->lCount = tmp->lCount/2;
struct rope* node = tmp;
long int m = l+r;
m = m/2;
node->left = createRopeStructure(node,a,l,m);
node->right = createRopeStructure(node,a,m+1,r);
}
else {
struct rope* node = tmp;
tmp->lCount = r-l;
long int j = 0;
register long int i = l;
char * arr = memoryAlloc(r+1);
while ((i<=r)) {
arr[j]=a[i];
++j;
++i;
};
tmp->str = arr;
}
return tmp;
};
long int ropeSet(struct rope* r,char * a){
long int n1 = strlen(a);
long int diff = n1-r->totalLen;
struct rope* nr = createRopeStructure(null,a,0,n1-1);
nr->totalLen = n1;
nr->len = n1;
*r = *nr;
return diff;
};
struct rope* concatenateRopes(struct rope* root1,struct rope* root2){
int n1 = root1->len;
struct rope* ____BAH_COMPILER_VAR_96 = memoryAlloc(sizeof(struct rope));
struct rope* tmp = ____BAH_COMPILER_VAR_96;
tmp->left = root1;
tmp->right = root2;
tmp->totalLen = root1->totalLen+root2->totalLen;
tmp->str = null;
return tmp;
};
struct rope* rope(char * a){
long int n1 = strlen(a);
struct rope* r = createRopeStructure(null,a,0,n1-1);
r->totalLen = n1;
r->len = n1;
return r;
};
struct command {
char * command;
char error;
long int status;
char * input;
FILE* handle;
};
char * command__run(struct command* this){
char * cm = this->command;
if ((this->error==false)) {
char** ____BAH_COMPILER_VAR_97 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_97[1] = " 2>/dev/null";____BAH_COMPILER_VAR_97[0] = cm;char * ____BAH_COMPILER_VAR_98 =__Bah_multiple_concat(____BAH_COMPILER_VAR_97, 2);cm = ____BAH_COMPILER_VAR_98;
}
else {
char** ____BAH_COMPILER_VAR_99 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_99[1] = " 2>&1";____BAH_COMPILER_VAR_99[0] = cm;char * ____BAH_COMPILER_VAR_100 =__Bah_multiple_concat(____BAH_COMPILER_VAR_99, 2);cm = ____BAH_COMPILER_VAR_100;
}
this->handle = popen(cm,"w");
if ((this->handle==null)) {
return "";
}
if ((strcmp(this->input, null) != 0)) {
fputs(this->input,(void *)this->handle);
}
char * buff = memoryAlloc(1025);
char * res = "";
while (((void *)fgets(buff,1024,this->handle)!=null)) {
char** ____BAH_COMPILER_VAR_101 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_101[1] = buff;____BAH_COMPILER_VAR_101[0] = res;char * ____BAH_COMPILER_VAR_102 =__Bah_multiple_concat(____BAH_COMPILER_VAR_101, 2);res = ____BAH_COMPILER_VAR_102;
};
this->status = pclose(this->handle);
return res;
};
__BAH_ARR_TYPE_char command__runBytes(struct command* this){
array(char)* arr = memoryAlloc(sizeof(array(char)));

arr->length = 0;
arr->elemSize = sizeof(char);
char * cm = this->command;
if ((this->error==false)) {
char** ____BAH_COMPILER_VAR_103 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_103[1] = " 2>/dev/null";____BAH_COMPILER_VAR_103[0] = cm;char * ____BAH_COMPILER_VAR_104 =__Bah_multiple_concat(____BAH_COMPILER_VAR_103, 2);cm = ____BAH_COMPILER_VAR_104;
}
else {
char** ____BAH_COMPILER_VAR_105 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_105[1] = " 2>&1";____BAH_COMPILER_VAR_105[0] = cm;char * ____BAH_COMPILER_VAR_106 =__Bah_multiple_concat(____BAH_COMPILER_VAR_105, 2);cm = ____BAH_COMPILER_VAR_106;
}
this->handle = popen(cm,"r");
if ((this->handle==null)) {
return arr;
}
long int total = 0;
long int fd = fileno(this->handle);
char * buff = memoryAlloc(1024);
char * response = "";
void * res = fgets(buff,1023,this->handle);
while ((res!=null)) {
char** ____BAH_COMPILER_VAR_107 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_107[1] = buff;____BAH_COMPILER_VAR_107[0] = response;char * ____BAH_COMPILER_VAR_108 =__Bah_multiple_concat(____BAH_COMPILER_VAR_107, 2);response = ____BAH_COMPILER_VAR_108;
res = fgets(buff,1023,this->handle);
};
this->status = pclose(this->handle);
arr->data=response;
arr->length=strlen(response);
return arr;
};
struct command command(char * s){
struct command ____BAH_COMPILER_VAR_109 = {};
____BAH_COMPILER_VAR_109.error = true;
#define cmd ____BAH_COMPILER_VAR_109
cmd.command = s;
return cmd;

#undef cmd
};
long int exec(char * s,__BAH_ARR_TYPE_cpstring args){
long int r;
array(char *)* nArgs = memoryAlloc(sizeof(array(char *)));

nArgs->length = 0;
nArgs->elemSize = sizeof(char *);

    unsigned int ____BAH_COMPILER_VAR_110 = 0;
    __Bah_realocate_arr(nArgs, ____BAH_COMPILER_VAR_110);
    nArgs->data[____BAH_COMPILER_VAR_110] = s;
register long int i = 0;
while ((i<len(args))) {

    unsigned int ____BAH_COMPILER_VAR_111 = i+1;
    __Bah_realocate_arr(nArgs, ____BAH_COMPILER_VAR_111);
    nArgs->data[____BAH_COMPILER_VAR_111] = args->data[i];
i = i+1;
};

    unsigned int ____BAH_COMPILER_VAR_112 = i+2;
    __Bah_realocate_arr(nArgs, ____BAH_COMPILER_VAR_112);
    nArgs->data[____BAH_COMPILER_VAR_112] = (char *)0;
r=execvp(s,nArgs->data);
return r;
};
char * BAH_DIR;
char * BAH_OS;
char * BAH_CC;
#define BAH_VERSION "v1.2 (build 111)"
char debug;
char verboseRuntime;
char isObject;
char isUnsafe;
char isOptimized;
char noticeEnabled;
char * execName;
char isSubObject;
char isImportedSubObject;
struct rope* OUTPUT;
char * NEXT_LINE;
struct rope* INIT;
struct variable {
char * name;
char * type;
char isConst;
char * constVal;
char isArray;
char * from;
void * declScope;
char isGlobal;
struct rope* declRope;
char canBeNull;
char canBeReg;
char isReg;
void * lastSet;
char isArg;
};
struct structMemb {
char * name;
char * type;
char isConst;
char * constVal;
char isArray;
char * from;
void * declScope;
char isGlobal;
struct rope* declRope;
char canBeNull;
char canBeReg;
char isReg;
void * lastSet;
char isArg;
char * def;
char isFn;
};
struct func {
char * name;
array(struct variable*)* args;
struct variable* returns;
char returned;
char isBinding;
char * from;
char * file;
unsigned int line;
char isVar;
char used;
struct rope* code;
char isMut;
char isImported;
char exits;
};
struct cStruct {
char * name;
array(struct structMemb*)* members;
array(struct func*)* methods;
char * postCode;
char print;
char * extendedFrom;
char isBinding;
char hasRCPmemb;
};
struct varCheck {
struct variable* v;
char checkNull;
};
struct Elems {
array(struct variable*)* vars;
array(struct cStruct*)* structs;
array(char *)* types;
array(struct func*)* fns;
array(char *)* defined;
struct Elems* parent;
unsigned int id;
array(struct varCheck)* branchChecks;
};
struct compilerStateTag {
array(char *)* includes;
array(char *)* cIncludes;
array(char *)* cLibs;
char * currentFile;
char * currentDir;
char isBranch;
char isFor;
array(char *)* arrTypesDecl;
char haveEntryPoint;
array(struct variable*)* RCPvars;
array(char *)* evals;
char hasImports;
struct Elems* currForElems;
struct Elems* currFnElems;
};
char shouldOnlyDecl;
struct compilerStateTag compilerState;
struct cStruct* currentCStruct;
long int threadCount;
struct func* currentFn;
long int totalLines;
long int totalLexerTime;
char RCPenabled;
long int RCPlevel;
struct flags flags;
struct variable* currSetVar;
array(struct varCheck)* currChecks;
char prevIfExits;
array(struct varCheck)* prevIfChecks;
typedef char tokenType;
#define TOKEN_NO_TYPE (tokenType)-1
#define TOKEN_TYPE_INT (tokenType)0
#define TOKEN_TYPE_FLOAT (tokenType)1
#define TOKEN_TYPE_VAR (tokenType)2
#define TOKEN_TYPE_ENCL (tokenType)3
#define TOKEN_TYPE_SEP (tokenType)4
#define TOKEN_TYPE_STR (tokenType)5
#define TOKEN_TYPE_KEYWORD (tokenType)6
#define TOKEN_TYPE_CHAR (tokenType)7
#define TOKEN_TYPE_BOOL (tokenType)8
#define TOKEN_TYPE_SYNTAX (tokenType)10
#define TOKEN_TYPE_FUNC (tokenType)11
#define TOKEN_TYPE_CAST (tokenType)12
struct Tok {
char * cont;
char * ogCont;
tokenType type;
unsigned int pos;
unsigned int line;
unsigned int begLine;
char * bahType;
char isValue;
char isFunc;
char isOper;
char isEqual;
char pass;
void * bahRef;
struct variable* parent;
};
char inArray(char needle,__BAH_ARR_TYPE_char arr){
register long int i = 0;
while ((i<len(arr))) {
if ((needle==arr->data[i])) {
return true;
}
i = i+1;
};
return false;
};
char inArrayStr(char * needle,__BAH_ARR_TYPE_cpstring arr){
register long int i = 0;
while ((i<len(arr))) {
if ((strcmp(needle, arr->data[i]) == 0)) {
return true;
}
i = i+1;
};
return false;
};
struct Tok makeToken(long int pos,long int lineNb,__BAH_ARR_TYPE_char cont,tokenType type){
struct Tok ____BAH_COMPILER_VAR_113 = {};
____BAH_COMPILER_VAR_113.cont = "";
____BAH_COMPILER_VAR_113.ogCont = "";
____BAH_COMPILER_VAR_113.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_113.line = 1;
____BAH_COMPILER_VAR_113.begLine = 1;
____BAH_COMPILER_VAR_113.bahType = "";
#define t ____BAH_COMPILER_VAR_113
t.cont = arrToStr(cont);
t.ogCont = t.cont;
clear(cont);
t.pos = pos;
t.line = lineNb;
t.type = type;
if ((type==TOKEN_TYPE_INT)||(type==TOKEN_TYPE_STR)||(type==TOKEN_TYPE_FLOAT)||(type==TOKEN_TYPE_VAR)||(type==TOKEN_TYPE_BOOL)||(type==TOKEN_TYPE_CHAR)) {
t.isValue = true;
}
return t;

#undef t
};
char isMinus(char c,char nc){
return (c==45)&&isNumber(nc);
};
void lexerErr(long int line,long int pos,char * msg){
char * lineStr = intToStr(line);
char * posStr = intToStr(pos);
char** ____BAH_COMPILER_VAR_114 = alloca(8 * sizeof(char*));____BAH_COMPILER_VAR_114[7] = msg;____BAH_COMPILER_VAR_114[6] = "\n\e[0m\n";____BAH_COMPILER_VAR_114[5] = posStr;____BAH_COMPILER_VAR_114[4] = ":";____BAH_COMPILER_VAR_114[3] = lineStr;____BAH_COMPILER_VAR_114[2] = ":";____BAH_COMPILER_VAR_114[1] = compilerState.currentFile;____BAH_COMPILER_VAR_114[0] = "\e[1;31m[LEXER-ERROR]\e[0m ";char * ____BAH_COMPILER_VAR_115 =__Bah_multiple_concat(____BAH_COMPILER_VAR_114, 8);println(____BAH_COMPILER_VAR_115);
exit(1);
};
array(char)* enclavers;
array(char)* syntaxes;
array(char *)* keywords;
typedef array(struct Tok)* __BAH_ARR_TYPE_Tok;
__BAH_ARR_TYPE_Tok lexer(char * s){
long int dur = getTimeUnix();
array(struct Tok)* tokens = memoryAlloc(sizeof(array(struct Tok)));

tokens->length = 0;
tokens->elemSize = sizeof(struct Tok);
long int codeLength = strlen(s);
array(char)* memory = memoryAlloc(sizeof(array(char)));

memory->length = 0;
memory->elemSize = sizeof(char);
long int lineNb = 1;
register long int i = 0;
for (; (i<codeLength); ++i) {
char c = s[i];
char nc = (char)0;
if ((i+1<codeLength)) {
nc = s[i+1];
}
if ((c==47)) {
nc = s[i+1];
if ((nc==47)) {
for (; (i<codeLength); ++i) {
c = s[i];
if ((c==(char)10)) {
break;
}
};
if ((i==codeLength)) {
break;
}
}
}
if ((c==(char)10)) {
++lineNb;
}
if ((c==(char)34)) {
long int pos = i;
long int begLine = lineNb;

    unsigned int ____BAH_COMPILER_VAR_116 = 0;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_116);
    memory->data[____BAH_COMPILER_VAR_116] = c;
i = i+1;
for (; (i<codeLength); ++i) {
c = s[i];
char pc = s[i-1];
if ((c==(char)34)) {
if ((pc!=(char)92)) {

    unsigned int ____BAH_COMPILER_VAR_117 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_117);
    memory->data[____BAH_COMPILER_VAR_117] = c;
break;
}
}
if ((c==(char)10)) {
lineNb = lineNb+1;
if ((pc!=(char)92)) {

    unsigned int ____BAH_COMPILER_VAR_118 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_118);
    memory->data[____BAH_COMPILER_VAR_118] = (char)92;
c = 110;
}
}

    unsigned int ____BAH_COMPILER_VAR_119 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_119);
    memory->data[____BAH_COMPILER_VAR_119] = c;
};

    unsigned int ____BAH_COMPILER_VAR_120 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_120);
    tokens->data[____BAH_COMPILER_VAR_120] = makeToken(pos,lineNb,memory,TOKEN_TYPE_STR);
struct Tok lt = tokens->data[len(tokens)-1];
lt.begLine = begLine;

    unsigned int ____BAH_COMPILER_VAR_121 = len(tokens)-1;
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_121);
    tokens->data[____BAH_COMPILER_VAR_121] = lt;
}
else if (isNumber(c)||isMinus(c,nc)) {

    unsigned int ____BAH_COMPILER_VAR_122 = 0;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_122);
    memory->data[____BAH_COMPILER_VAR_122] = c;
long int pos = i;
i = i+1;
tokenType currentType = TOKEN_TYPE_INT;
char isHex = false;
for (; (i<codeLength); ++i) {
c = s[i];
if ((c==(char)46)) {
currentType = TOKEN_TYPE_FLOAT;
}
else if ((isNumber(c)==false)) {
if ((isHex==false)) {
if ((c==120)) {
isHex = true;
}
else {
break;
}
}
else {
if (isUpper(c)) {
c = c+(char)32;
}
if ((c<97)||(c>102)) {
break;
}
}
if ((isHex==false)) {
break;
}
}

    unsigned int ____BAH_COMPILER_VAR_123 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_123);
    memory->data[____BAH_COMPILER_VAR_123] = c;
};
--i;

    unsigned int ____BAH_COMPILER_VAR_124 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_124);
    tokens->data[____BAH_COMPILER_VAR_124] = makeToken(pos,lineNb,memory,currentType);
}
else if ((c==(char)39)) {
++i;
char n = s[i];
char * toInt = intToStr((long int)nc);
memory = strToArr(toInt);
++i;
c = s[i];
if ((c!=(char)39)) {
lexerErr(lineNb,i,"Missing closing tag in char declaration.");
}

    unsigned int ____BAH_COMPILER_VAR_125 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_125);
    tokens->data[____BAH_COMPILER_VAR_125] = makeToken(i-1,lineNb,memory,TOKEN_TYPE_CHAR);
}
else if ((c==(char)35)) {
long int pos = i;

    unsigned int ____BAH_COMPILER_VAR_126 = 0;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_126);
    memory->data[____BAH_COMPILER_VAR_126] = c;
++i;
for (; (i<codeLength); ++i) {
c = s[i];
if ((isAlphaNumeric(c)==false)) {
break;
}

    unsigned int ____BAH_COMPILER_VAR_127 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_127);
    memory->data[____BAH_COMPILER_VAR_127] = c;
};
--i;

    unsigned int ____BAH_COMPILER_VAR_128 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_128);
    tokens->data[____BAH_COMPILER_VAR_128] = makeToken(pos,lineNb,memory,TOKEN_TYPE_KEYWORD);
}
else if (inArray(c,enclavers)) {

    unsigned int ____BAH_COMPILER_VAR_129 = 0;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_129);
    memory->data[____BAH_COMPILER_VAR_129] = c;

    unsigned int ____BAH_COMPILER_VAR_130 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_130);
    tokens->data[____BAH_COMPILER_VAR_130] = makeToken(i,lineNb,memory,TOKEN_TYPE_ENCL);
}
else if (inArray(c,syntaxes)) {
if ((c==60)) {
long int pos = i;
char isCast = false;

    unsigned int ____BAH_COMPILER_VAR_131 = 0;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_131);
    memory->data[____BAH_COMPILER_VAR_131] = c;
++i;
for (; (i<codeLength); ++i) {
c = s[i];
if ((c==62)) {
isCast = true;

    unsigned int ____BAH_COMPILER_VAR_132 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_132);
    memory->data[____BAH_COMPILER_VAR_132] = c;
break;
}
if ((isAlphaNumeric(c)==false)&&(c!=42)&&(c!=58)&&(c!=95)&&(c!=91)&&(c!=93)) {
break;
}

    unsigned int ____BAH_COMPILER_VAR_133 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_133);
    memory->data[____BAH_COMPILER_VAR_133] = c;
};
if ((isCast==true)) {

    unsigned int ____BAH_COMPILER_VAR_134 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_134);
    tokens->data[____BAH_COMPILER_VAR_134] = makeToken(pos,lineNb,memory,TOKEN_TYPE_CAST);
continue;
}
i = pos;
c = 60;
clear(memory);
}

    unsigned int ____BAH_COMPILER_VAR_135 = 0;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_135);
    memory->data[____BAH_COMPILER_VAR_135] = c;
long int pos = i;
++i;
char fc = c;
for (; (i<codeLength); ++i) {
c = s[i];

        char ____BAH_COMPILER_VAR_136 = 0;
        for(int i=syntaxes->length-1; i!=-1;i--) {
            if (syntaxes->data[i] == c) {
                ____BAH_COMPILER_VAR_136=1;
                break;
            };
        }
        if ((____BAH_COMPILER_VAR_136==false)) {
break;
}
if ((fc==60)) {
if ((c!=45)&&(c!=61)&&(c!=60)) {
break;
}
}
else if ((c==124)) {
if ((fc!=c)) {
break;
}
}
else if ((c==38)) {
if ((fc!=c)) {
break;
}
}
else if ((c!=61)) {
if ((c!=62)) {
break;
}
}

    unsigned int ____BAH_COMPILER_VAR_137 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_137);
    memory->data[____BAH_COMPILER_VAR_137] = c;
};
--i;

    unsigned int ____BAH_COMPILER_VAR_138 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_138);
    tokens->data[____BAH_COMPILER_VAR_138] = makeToken(pos,lineNb,memory,TOKEN_TYPE_SYNTAX);
}
else if ((c==46)) {

    unsigned int ____BAH_COMPILER_VAR_139 = 0;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_139);
    memory->data[____BAH_COMPILER_VAR_139] = c;

    unsigned int ____BAH_COMPILER_VAR_140 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_140);
    tokens->data[____BAH_COMPILER_VAR_140] = makeToken(i,lineNb,memory,TOKEN_TYPE_SEP);
}
else if (isAlphaNumeric(c)||(c==95)) {

    unsigned int ____BAH_COMPILER_VAR_141 = 0;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_141);
    memory->data[____BAH_COMPILER_VAR_141] = c;
long int pos = i;
++i;
for (; (i<codeLength); ++i) {
c = s[i];
if ((isAlphaNumeric(c)==false)) {
if ((c!=95)) {
if ((c==62)) {
char lc = memory->data[len(memory)-1];
if ((lc==45)) {

    unsigned int ____BAH_COMPILER_VAR_142 = len(memory)-1;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_142);
    memory->data[____BAH_COMPILER_VAR_142] = (char)0;
--i;
break;
}
}
break;
}
}

    unsigned int ____BAH_COMPILER_VAR_143 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_143);
    memory->data[____BAH_COMPILER_VAR_143] = c;
};
--i;
tokenType currentType = TOKEN_TYPE_VAR;
char * memstr = arrAsStr(memory);

        char ____BAH_COMPILER_VAR_144 = 0;
        for(int i=keywords->length-1; i!=-1;i--) {
            if (keywords->data[i] != 0 && strcmp(keywords->data[i], memstr) == 0) {
                ____BAH_COMPILER_VAR_144=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_144) {
currentType = TOKEN_TYPE_KEYWORD;
}

    unsigned int ____BAH_COMPILER_VAR_145 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_145);
    tokens->data[____BAH_COMPILER_VAR_145] = makeToken(pos,lineNb,memory,currentType);
}
};
totalLines = totalLines+lineNb-1;
dur = getTimeUnix()-dur;
totalLexerTime = totalLexerTime+dur;
return tokens;
};
char hasStructSep(struct string* n){
if (string__count(n,".")) {
return true;
}
if (string__count(n,"->")) {
return true;
}
return false;
};
struct string splitStructSepBefore(struct string* n){
if (string__count(n,".")) {
char * ____BAH_COMPILER_VAR_146 =splitStringBefore(*n,".");struct string res = string(____BAH_COMPILER_VAR_146);
return res;
}
if (string__count(n,"->")) {
char * ____BAH_COMPILER_VAR_147 =splitStringBefore(*n,"->");struct string res = string(____BAH_COMPILER_VAR_147);
return res;
}
return string("");
};
struct string splitStructSepAfter(struct string n){
register long int i = n.length;
while ((i>0)) {
char c = string__charAt(&n,i);
if ((c==46)) {
break;
}
else if ((c==62)) {
char pc = string__charAt(&n,i-1);
if ((pc==45)) {
break;
}
}
i = i-1;
};
i = i+1;
string__trimLeft(&n,i);
return n;
};
struct cStruct* searchStruct(char * name,struct Elems* elems){
struct string n = string(name);
string__replace(&n,"&","");
string__replace(&n,"*","");
name = n.content;
register long int i = len(elems->structs)-1;
for (; (i!=-1); --i) {
struct cStruct* s = elems->structs->data[i];
if ((strcmp(s->name, name) == 0)) {
return s;
}
};
return null;
};
struct structMemb* searchStructMemb(char * name,struct cStruct* s,struct Elems* elems){
struct string n = string(name);
if (hasStructSep(&n)) {
struct string rn = splitStructSepBefore(&n);
name = rn.content;
string__trimLeft(&n,rn.length);
if (string__hasPrefix(&n,".")) {
string__trimLeft(&n,1);
}
else {
string__trimLeft(&n,2);
}
char * membs = n.content;
struct structMemb* memb = searchStructMemb(name,s,elems);
if ((n.length>0)) {
s = searchStruct(memb->type,elems);
char * nstr = string__str(&n);
memb = searchStructMemb(nstr,s,elems);
}
return memb;
}
array(struct structMemb*)* members = s->members;
register long int i = 0;
while ((i<len(members))) {
struct structMemb* m = members->data[i];
if ((strcmp(m->name, name) == 0)) {
return m;
}
i = i+1;
};
array(struct func*)* mthds = s->methods;
i = 0;
while ((i<len(mthds))) {
struct func* m = mthds->data[i];
if ((strcmp(m->name, name) == 0)) {
struct structMemb* ____BAH_COMPILER_VAR_148 = memoryAlloc(sizeof(struct structMemb));
____BAH_COMPILER_VAR_148->name = "";
____BAH_COMPILER_VAR_148->type = "";
____BAH_COMPILER_VAR_148->constVal = "";
____BAH_COMPILER_VAR_148->from = "";
____BAH_COMPILER_VAR_148->def = "";
struct structMemb* sm = ____BAH_COMPILER_VAR_148;
sm->name = m->name;
sm->from = m->from;
sm->type = m->returns->type;
sm->isFn = true;
return sm;
}
i = i+1;
};
if ((strlen(s->extendedFrom)==0)) {
return null;
}
struct cStruct* es = searchStruct(s->extendedFrom,elems);
if ((es==null)) {
return null;
}
return searchStructMemb(name,es,elems);
};
struct func* searchFunc(char * n,struct Elems* e,char c);
struct func* parseFnType(struct string n);
struct func* searchStructMethod(char * name,struct cStruct* s,struct Elems* elems){
if ((s==null)) {
return null;
}
char** ____BAH_COMPILER_VAR_149 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_149[2] = name;____BAH_COMPILER_VAR_149[1] = "__";____BAH_COMPILER_VAR_149[0] = s->name;char * ____BAH_COMPILER_VAR_150 =__Bah_multiple_concat(____BAH_COMPILER_VAR_149, 3);struct func* fn = searchFunc(____BAH_COMPILER_VAR_150,elems,true);
if ((fn!=null)) {
return fn;
}
register long int i = 0;
for (; (i<len(s->members)); ++i) {
if ((strcmp(s->members->data[i]->name, name) == 0)) {
struct string ____BAH_COMPILER_VAR_151 =string(s->members->data[i]->type);fn = parseFnType(____BAH_COMPILER_VAR_151);
fn->name = name;
fn->isVar = true;
return fn;
}
};
s = searchStruct(s->extendedFrom,elems);
return searchStructMethod(name,s,elems);
};
char typeAsStar(char * t){
return (t[strlen(t)-1]==42);
};
char isRCPpointerType(char * t){
if (strHasPrefix(t,"function(")) {
return false;
}
return (strcmp(t, "cpstring") == 0)||(strcmp(t, "ptr") == 0)||typeAsStar(t)||strHasPrefix(t,"[]")||strHasPrefix(t,"chan:")||strHasPrefix(t,"map:");
};
char isRCPtype(char * t,struct Elems* elems){
if ((isRCPpointerType(t)==true)) {
return true;
}
struct cStruct* s = searchStruct(t,elems);
return (s!=null)&&(s->isBinding==false);
};
struct string getCType(char * t,struct Elems* elems){
if ((strlen(t)==0)) {
return string("void");
}
struct string tp = string(t);
string__replace(&tp," ","");
if (string__hasPrefix(&tp,"[]")) {
string__trimLeft(&tp,2);
char * tpstr = string__str(&tp);
tp = getCType(tpstr,elems);
t = string__str(&tp);
char** ____BAH_COMPILER_VAR_152 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_152[2] = ")*";____BAH_COMPILER_VAR_152[1] = t;____BAH_COMPILER_VAR_152[0] = "array(";char * ____BAH_COMPILER_VAR_153 =__Bah_multiple_concat(____BAH_COMPILER_VAR_152, 3);char * r = ____BAH_COMPILER_VAR_153;
return string(r);
}
string__replace(&tp,"!","*");
struct string ctp = tp;
string__replace(&ctp,"*","");
if ((string__hasPrefix(&tp,"chan:")==1)) {
string__set(&tp,"struct channel *");
}
else if ((string__hasPrefix(&tp,"map:")==1)) {
string__set(&tp,"struct mapWrapper *");
}
else if ((string__hasPrefix(&tp,"buffer:")==1)) {
string__set(&tp,"char*");
}
else if ((strcmp(string__str(&ctp), "int") == 0)) {
string__replace(&tp,"int","long int");
}
else if ((strcmp(string__str(&ctp), "int32") == 0)) {
string__replace(&tp,"int32","int");
}
else if ((strcmp(string__str(&ctp), "uint32") == 0)) {
string__replace(&tp,"uint32","unsigned int");
}
else if ((strcmp(string__str(&ctp), "uint") == 0)) {
string__replace(&tp,"uint","unsigned long int");
}
else if ((strcmp(string__str(&ctp), "float32") == 0)) {
string__replace(&tp,"float32","float");
}
else if ((strcmp(string__str(&ctp), "ufloat32") == 0)) {
string__replace(&tp,"ufloat32","unsigned float");
}
else if ((strcmp(string__str(&ctp), "ufloat") == 0)) {
string__replace(&tp,"ufloat","unsigned double");
}
else if ((strcmp(string__str(&ctp), "float") == 0)) {
string__replace(&tp,"float","double");
}
else if ((strcmp(string__str(&ctp), "long") == 0)) {
string__replace(&tp,"long","long long");
}
else if ((strcmp(string__str(&ctp), "ulong") == 0)) {
string__replace(&tp,"ulong","unsigned long long");
}
else if ((strcmp(string__str(&ctp), "cpstring") == 0)) {
string__replace(&tp,"cpstring","char *");
}
else if ((strcmp(string__str(&ctp), "ptr") == 0)) {
string__replace(&tp,"ptr","void *");
}
else if ((strcmp(string__str(&ctp), "ushort") == 0)) {
string__replace(&tp,"ushort","unsigned short");
}
else if ((strcmp(string__str(&ctp), "byte") == 0)) {
string__replace(&tp,"byte","unsigned char");
}
else if ((strcmp(string__str(&ctp), "bool") == 0)) {
string__replace(&tp,"bool","char");
}
else if ((strcmp(string__str(&ctp), "char") == 0)) {
}
else {
char * ctpstr = string__str(&ctp);
struct cStruct* s = searchStruct(ctpstr,elems);
if ((s!=null)) {
string__prepend(&tp,"struct ");
}
else {
register long int i = 0;
while ((i<len(elems->types))) {
char * ct = elems->types->data[i];
if (string__compare(&ctp,ct)) {
return tp;
}
i = i+1;
};
return string("");
}
}
return tp;
};
array(char *)* intTypes;
array(char *)* floatTypes;
char * maybeToPtr(char * a){
if ((a[strlen(a)-1]!=33)) {
return a;
}
char** ____BAH_COMPILER_VAR_154 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_154[1] = "*";____BAH_COMPILER_VAR_154[0] = cpstringSubsitute(a, 0, strlen(a)-1);char * ____BAH_COMPILER_VAR_155 =__Bah_multiple_concat(____BAH_COMPILER_VAR_154, 2);a = ____BAH_COMPILER_VAR_155;
return a;
};
char compTypeEquiv(char * a,char * b,char first){
if ((strcmp(a, "cpstring") == 0)&&strHasPrefix(b,"buffer:")) {
return true;
}
if ((first==false)) {
return false;
}
if (compTypeEquiv(b,a,false)) {
return true;
}
return (strcmp(a, b) == 0);
};
char compTypes(char * a,char * b){
a = maybeToPtr(a);
b = maybeToPtr(b);
if ((strcmp(a, b) == 0)||(strcmp(a, "ptr") == 0)||(strcmp(b, "ptr") == 0)) {
return true;
}

        char ____BAH_COMPILER_VAR_156 = 0;
        for(int i=intTypes->length-1; i!=-1;i--) {
            if (intTypes->data[i] != 0 && strcmp(intTypes->data[i], a) == 0) {
                ____BAH_COMPILER_VAR_156=1;
                break;
            };
        }
        
        char ____BAH_COMPILER_VAR_157 = 0;
        for(int i=intTypes->length-1; i!=-1;i--) {
            if (intTypes->data[i] != 0 && strcmp(intTypes->data[i], b) == 0) {
                ____BAH_COMPILER_VAR_157=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_156&&____BAH_COMPILER_VAR_157) {
return true;
}

        char ____BAH_COMPILER_VAR_158 = 0;
        for(int i=floatTypes->length-1; i!=-1;i--) {
            if (floatTypes->data[i] != 0 && strcmp(floatTypes->data[i], a) == 0) {
                ____BAH_COMPILER_VAR_158=1;
                break;
            };
        }
        
        char ____BAH_COMPILER_VAR_159 = 0;
        for(int i=floatTypes->length-1; i!=-1;i--) {
            if (floatTypes->data[i] != 0 && strcmp(floatTypes->data[i], b) == 0) {
                ____BAH_COMPILER_VAR_159=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_158&&____BAH_COMPILER_VAR_159) {
return true;
}
return compTypeEquiv(a,b,true);
};
#include <stddef.h>
struct reflectElement {
long int size;
char * type;
char * name;
char isArray;
struct reflectElement* arrayElem;
char isStruct;
array(struct reflectElement)* structLayout;
long int offset;
void * value;
};
void * reflectElement__calculateOffset(struct reflectElement* this,void * origin){
char * base = origin;
return base+this->offset;
};
typedef array(struct reflectElement)* __BAH_ARR_TYPE_reflectElement;
struct reflectElement __reflect(void * v,long int s,char * t,char * n,char isArr,struct reflectElement* ae,char isStruct,__BAH_ARR_TYPE_reflectElement sl,long int offset){
struct reflectElement ____BAH_COMPILER_VAR_160 = {};
____BAH_COMPILER_VAR_160.structLayout = memoryAlloc(sizeof(array(struct reflectElement)));
            ____BAH_COMPILER_VAR_160.structLayout->length = 0;
            ____BAH_COMPILER_VAR_160.structLayout->elemSize = sizeof(struct reflectElement);
            #define re ____BAH_COMPILER_VAR_160
re.size = s;
re.type = t;
re.name = n;
re.isArray = isArr;
re.arrayElem = ae;
re.isStruct = isStruct;
re.structLayout = sl;
re.value = v;
re.offset = offset;
return re;

#undef re
};
typedef void * reflectSymbols;
__BAH_ARR_TYPE_reflectElement __dumpSymbols(__BAH_ARR_TYPE_reflectElement syms){
return syms;
};
struct reflectElement __debug_get_sym(__BAH_ARR_TYPE_reflectElement syms,struct string a){
if ((string__count(&a,".")>0)) {
array(struct string)* parts = splitString(a,".");
struct string p1 = parts->data[0];
struct string p2 = parts->data[1];
register long int j = 0;
for (; (j<len(syms)); ++j) {
struct reflectElement s = syms->data[j];
if ((strcmp(s.name, string__str(&p1)) == 0)) {
register long int k = 0;
for (; (k<len(s.structLayout)); ++k) {
struct reflectElement m = s.structLayout->data[k];
if ((strcmp(m.name, string__str(&p2)) == 0)) {
m.value = reflectElement__calculateOffset(&m,s.value);
return m;
}
};
break;
}
};
}
else {
register long int j = 0;
for (; (j<len(syms)); ++j) {
struct reflectElement s = syms->data[j];
if ((strcmp(s.name, string__str(&a)) == 0)) {
return s;
}
};
}
struct reflectElement ____BAH_COMPILER_VAR_161 = {};
____BAH_COMPILER_VAR_161.structLayout = memoryAlloc(sizeof(array(struct reflectElement)));
            ____BAH_COMPILER_VAR_161.structLayout->length = 0;
            ____BAH_COMPILER_VAR_161.structLayout->elemSize = sizeof(struct reflectElement);
            #define ns ____BAH_COMPILER_VAR_161
return ns;

#undef ns
};
#define __bah_reflect __reflect
#define __bah_dump_symbols __dumpSymbols
#define __bah_debug_get_sym __debug_get_sym
#define JSON_TYPE_STRING 0
#define JSON_TYPE_INT 1
#define JSON_TYPE_FLOAT 2
#define JSON_TYPE_ARRAY 3
#define JSON_TYPE_MAP 4
char * toJson(struct reflectElement e);
void json_scan_inner(void * this,struct reflectElement e,char isMember);
struct jsonElement {
long int type;
char * key;
char * content;
array(struct jsonElement*)* children;
};
struct jsonElement* jsonElement__get(struct jsonElement* this,char * key){
long int l = len(this->children);
register long int i = 0;
while ((i<l)) {
struct jsonElement* elem = this->children->data[i];
char fc = cpstringCharAt(elem->key,0);
if ((fc==(char)34)) {
array(char)* nk = memoryAlloc(sizeof(array(char)));

nk->length = 0;
nk->elemSize = sizeof(char);
long int lk = strlen(elem->key);
register long int j = 1;
while ((j<lk-1)) {
char c = cpstringCharAt(elem->key,j);

    unsigned int ____BAH_COMPILER_VAR_162 = j-1;
    __Bah_realocate_arr(nk, ____BAH_COMPILER_VAR_162);
    nk->data[____BAH_COMPILER_VAR_162] = c;
j = j+1;
};
if ((strcmp(arrAsStr(nk), key) == 0)) {
return elem;
}
}
else {
if ((strcmp(elem->key, key) == 0)) {
return elem;
}
}
i = i+1;
};
void * z = (void *)0;
return z;
};
char * jsonElement__str(struct jsonElement* this){
char * ctn = this->content;
return ctn;
};
void jsonElement__scan(struct jsonElement* this,struct reflectElement e){
json_scan_inner(this,e,false);
};
void json_scan_inner(void * thisp,struct reflectElement e,char isMember){
struct jsonElement* this = thisp;
if ((e.isStruct==true)) {
register long int i = 0;
while ((i<len(e.structLayout))) {
struct reflectElement m = e.structLayout->data[i];
struct jsonElement* ov = jsonElement__get(this,m.name);
if ((ov!=null)) {
json_scan_inner(ov,m,true);
}
i = i+1;
};
}
else if ((strcmp(e.type, "int") == 0)) {
long int* ep = e.value;
*ep = strToInt(this->content);
}
else if ((strcmp(e.type, "cpstring") == 0)) {
char ** ep = e.value;
*ep = this->content;
}
else if ((strcmp(e.type, "float") == 0)) {
double* ep = e.value;
*ep = strToFloat(this->content);
}
else if ((strcmp(e.type, "bool") == 0)) {
char* ep = e.value;
if ((strcmp(this->content, "1") == 0)||(strcmp(this->content, "true") == 0)) {
*ep = true;
}
else {
*ep = false;
}
}
else if ((e.isArray==true)) {
if ((len(this->children)==0)) {
return;
}
struct reflectElement* ae = e.arrayElem;
if ((strcmp(ae->type, "int") == 0)) {
array(long int)* arr = memoryAlloc(sizeof(array(long int)));

arr->length = 0;
arr->elemSize = sizeof(long int);
void ** arrPtr = e.value;
if ((isMember==true)) {
*arrPtr = arr;
}
else {
arr = *arrPtr;
}
register long int i = 0;
while ((i<len(this->children))) {
struct jsonElement* c = this->children->data[i];

    unsigned int ____BAH_COMPILER_VAR_163 = i;
    __Bah_realocate_arr(arr, ____BAH_COMPILER_VAR_163);
    arr->data[____BAH_COMPILER_VAR_163] = strToInt(c->content);
i = i+1;
};
}
else if ((strcmp(ae->type, "float") == 0)) {
array(double)* arr = memoryAlloc(sizeof(array(double)));

arr->length = 0;
arr->elemSize = sizeof(double);
void ** arrPtr = e.value;
if ((isMember==true)) {
*arrPtr = arr;
}
else {
arr = *arrPtr;
}
register long int i = 0;
while ((i<len(this->children))) {
struct jsonElement* c = this->children->data[i];

    unsigned int ____BAH_COMPILER_VAR_164 = i;
    __Bah_realocate_arr(arr, ____BAH_COMPILER_VAR_164);
    arr->data[____BAH_COMPILER_VAR_164] = strToFloat(c->content);
i = i+1;
};
}
else if ((strcmp(ae->type, "cpstring") == 0)) {
array(char *)* arr = memoryAlloc(sizeof(array(char *)));

arr->length = 0;
arr->elemSize = sizeof(char *);
void ** arrPtr = e.value;
if ((isMember==true)) {
*arrPtr = arr;
}
else {
arr = *arrPtr;
}
register long int i = 0;
while ((i<len(this->children))) {
struct jsonElement* c = this->children->data[i];

    unsigned int ____BAH_COMPILER_VAR_165 = i;
    __Bah_realocate_arr(arr, ____BAH_COMPILER_VAR_165);
    arr->data[____BAH_COMPILER_VAR_165] = c->content;
i = i+1;
};
}
else if ((ae->isStruct==true)) {
array(void *)* arr = memoryAlloc(sizeof(array(void *)));

arr->length = 0;
arr->elemSize = sizeof(void *);
void ** arrPtr = e.value;
if ((isMember==true)) {
*arrPtr = arr;
}
else {
arr = *arrPtr;
}
register long int i = 0;
while ((i<len(this->children))) {
struct jsonElement* c = this->children->data[i];
void * ne = memoryAlloc(ae->size);
register long int j = 0;
while ((j<len(ae->structLayout))) {
struct reflectElement m = ae->structLayout->data[j];
m.value = reflectElement__calculateOffset(&m,ne);
struct jsonElement* ov = jsonElement__get(c,m.name);
if ((ov!=null)) {
json_scan_inner(ov,m,true);
}
j = j+1;
};

    unsigned int ____BAH_COMPILER_VAR_166 = i;
    __Bah_realocate_arr(arr, ____BAH_COMPILER_VAR_166);
    arr->data[____BAH_COMPILER_VAR_166] = ne;
i = i+1;
};
}
}
else if (strHasPrefix(e.type,"map:")) {
struct mapWrapper** p = e.value;
register long int i = 0;
for (; (i<len(this->children)); ++i) {
struct jsonElement* c = this->children->data[i];
struct reflectElement* ae = e.arrayElem;
void * v = memoryAlloc(ae->size);
ae->value = &v;
register long int j = 0;
for (; (j<len(ae->structLayout)); ++j) {
struct reflectElement m = ae->structLayout->data[j];
m.value = reflectElement__calculateOffset(&m,&v);

    unsigned int ____BAH_COMPILER_VAR_167 = j;
    __Bah_realocate_arr(ae->structLayout, ____BAH_COMPILER_VAR_167);
    ae->structLayout->data[____BAH_COMPILER_VAR_167] = m;
};
json_scan_inner(c,*ae,true);
struct string k = string(c->key);
string__trimLeft(&k,1);
string__trimRight(&k,1);
if (strCount(ae->type,"*")||(strcmp(ae->type, "ptr") == 0)||(strcmp(ae->type, "cpstring") == 0)||strHasPrefix(ae->type,"[]")||strHasPrefix(ae->type,"map:")) {
char * ____BAH_COMPILER_VAR_168 =string__str(&k);mapWrapper__set(*p,____BAH_COMPILER_VAR_168,v);
}
else {
char * ____BAH_COMPILER_VAR_169 =string__str(&k);mapWrapper__set(*p,____BAH_COMPILER_VAR_169,&v);
}
};
}
};
struct jsonElement* parseJson(char * s){
struct jsonElement* ____BAH_COMPILER_VAR_170 = memoryAlloc(sizeof(struct jsonElement));
____BAH_COMPILER_VAR_170->children = memoryAlloc(sizeof(array(struct jsonElement*)));
            ____BAH_COMPILER_VAR_170->children->length = 0;
            ____BAH_COMPILER_VAR_170->children->elemSize = sizeof(struct jsonElement*);
            struct jsonElement* jsonElem = ____BAH_COMPILER_VAR_170;
long int lenS = strlen(s);
register long int i = 0;
while ((i<lenS)) {
if ((isSpace(cpstringCharAt(s,i))==false)) {
break;
}
i = i+1;
};
char fc = cpstringCharAt(s,i);
if ((fc==91)) {
jsonElem->type = JSON_TYPE_ARRAY;
}
else if ((fc==123)) {
jsonElem->type = JSON_TYPE_MAP;
}
else if ((fc==(char)34)) {
jsonElem->type = JSON_TYPE_STRING;
array(char)* ns = memoryAlloc(sizeof(array(char)));

ns->length = 0;
ns->elemSize = sizeof(char);
i = i+1;
long int start = i;
while ((i<lenS-1)) {
char c = cpstringCharAt(s,i);
if ((i>start)&&(cpstringCharAt(s,i-1)==(char)92)) {
if ((c==110)) {
c = (char)10;
}
else if ((c==114)) {
c = (char)13;
}

    unsigned int ____BAH_COMPILER_VAR_171 = len(ns)-1;
    __Bah_realocate_arr(ns, ____BAH_COMPILER_VAR_171);
    ns->data[____BAH_COMPILER_VAR_171] = c;
}
else {

    unsigned int ____BAH_COMPILER_VAR_172 = len(ns);
    __Bah_realocate_arr(ns, ____BAH_COMPILER_VAR_172);
    ns->data[____BAH_COMPILER_VAR_172] = c;
}
i = i+1;
};
jsonElem->content = arrToStr(ns);
}
else if (isNumber(cpstringCharAt(s,strlen(s)-1))) {
char isFloat = false;
while ((i<lenS)) {
if ((cpstringCharAt(s,i)==46)) {
isFloat = true;
break;
}
i = i+1;
};
if ((isFloat==true)) {
jsonElem->type = JSON_TYPE_FLOAT;
}
else {
jsonElem->type = JSON_TYPE_INT;
}
jsonElem->content = s;
}
else {
return null;
}
if ((jsonElem->type==JSON_TYPE_ARRAY)) {
i = i+1;
long int trim = 1;
register long int j = lenS-1;
while ((j>=0)) {
char c = cpstringCharAt(s,j);
if (isSpace(c)) {
trim = trim+1;
}
else {
break;
}
j = j-1;
};
while ((i<lenS-1)) {
char c = cpstringCharAt(s,i);
if ((isSpace(c)==false)) {
break;
}
i = i+1;
};
array(char)* currentElem = memoryAlloc(sizeof(array(char)));

currentElem->length = 0;
currentElem->elemSize = sizeof(char);
long int currentBracks = 0;
long int currentBraces = 0;
long int currentQuotes = 0;
long int elemIndex = 0;
while ((i<lenS-trim)) {
char c = cpstringCharAt(s,i);
if ((c==(char)34)) {
if ((currentQuotes==0)) {
currentQuotes = 1;
}
else {
currentQuotes = 0;
}
}
else if ((c==91)) {
currentBracks = currentBracks+1;
}
else if ((c==93)) {
currentBracks = currentBracks-1;
}
else if ((c==123)) {
currentBraces = currentBraces+1;
}
else if ((c==125)) {
currentBraces = currentBraces-1;
}
long int total = currentBracks+currentBraces+currentQuotes;
if ((total>0)) {

    unsigned int ____BAH_COMPILER_VAR_173 = len(currentElem);
    __Bah_realocate_arr(currentElem, ____BAH_COMPILER_VAR_173);
    currentElem->data[____BAH_COMPILER_VAR_173] = c;
i = i+1;
continue;
}
if ((c==44)) {
char * ____BAH_COMPILER_VAR_174 =arrToStr(currentElem);struct jsonElement* child = parseJson(____BAH_COMPILER_VAR_174);
if ((child!=null)) {

    unsigned int ____BAH_COMPILER_VAR_175 = elemIndex;
    __Bah_realocate_arr(jsonElem->children, ____BAH_COMPILER_VAR_175);
    jsonElem->children->data[____BAH_COMPILER_VAR_175] = child;
}
clear(currentElem);
elemIndex = elemIndex+1;
}
else {
if (isSpace(c)) {
i = i+1;
continue;
}

    unsigned int ____BAH_COMPILER_VAR_176 = len(currentElem);
    __Bah_realocate_arr(currentElem, ____BAH_COMPILER_VAR_176);
    currentElem->data[____BAH_COMPILER_VAR_176] = c;
}
i = i+1;
};
char * ____BAH_COMPILER_VAR_177 =arrToStr(currentElem);struct jsonElement* child = parseJson(____BAH_COMPILER_VAR_177);
if ((child!=null)) {

    unsigned int ____BAH_COMPILER_VAR_178 = elemIndex;
    __Bah_realocate_arr(jsonElem->children, ____BAH_COMPILER_VAR_178);
    jsonElem->children->data[____BAH_COMPILER_VAR_178] = child;
}
}
else if ((jsonElem->type==JSON_TYPE_MAP)) {
i = i+1;
long int trim = 1;
register long int j = lenS-1;
while ((j>=0)) {
char c = cpstringCharAt(s,j);
if (isSpace(c)) {
trim = trim+1;
}
else {
break;
}
j = j-1;
};
while ((i<lenS-1)) {
char c = cpstringCharAt(s,i);
if ((isSpace(c)==false)) {
break;
}
i = i+1;
};
array(char)* currentElem = memoryAlloc(sizeof(array(char)));

currentElem->length = 0;
currentElem->elemSize = sizeof(char);
array(char)* currentKey = memoryAlloc(sizeof(array(char)));

currentKey->length = 0;
currentKey->elemSize = sizeof(char);
long int isVal = 0;
long int currentBracks = 0;
long int currentBraces = 0;
long int currentQuotes = 0;
long int elemIndex = 0;
while ((i<lenS-trim)) {
char c = cpstringCharAt(s,i);
if ((c==(char)34)) {
if ((currentQuotes==0)) {
currentQuotes = 1;
}
else {
currentQuotes = 0;
}
}
else if ((c==91)) {
currentBracks = currentBracks+1;
}
else if ((c==93)) {
currentBracks = currentBracks-1;
}
else if ((c==123)) {
currentBraces = currentBraces+1;
}
else if ((c==125)) {
currentBraces = currentBraces-1;
}
long int total = currentBracks+currentBraces+currentQuotes;
if ((total>0)) {
if ((isVal==1)) {

    unsigned int ____BAH_COMPILER_VAR_179 = len(currentElem);
    __Bah_realocate_arr(currentElem, ____BAH_COMPILER_VAR_179);
    currentElem->data[____BAH_COMPILER_VAR_179] = c;
}
else {

    unsigned int ____BAH_COMPILER_VAR_180 = len(currentKey);
    __Bah_realocate_arr(currentKey, ____BAH_COMPILER_VAR_180);
    currentKey->data[____BAH_COMPILER_VAR_180] = c;
}
i = i+1;
continue;
}
if ((c==58)) {
isVal = 1;
}
else if ((c==44)) {
char * ____BAH_COMPILER_VAR_181 =arrToStr(currentElem);struct jsonElement* elem = parseJson(____BAH_COMPILER_VAR_181);
if ((elem!=null)) {
elem->key = arrToStr(currentKey);

    unsigned int ____BAH_COMPILER_VAR_182 = elemIndex;
    __Bah_realocate_arr(jsonElem->children, ____BAH_COMPILER_VAR_182);
    jsonElem->children->data[____BAH_COMPILER_VAR_182] = elem;
elemIndex = elemIndex+1;
}
clear(currentElem);
clear(currentKey);
isVal = 0;
}
else {
if (isSpace(c)) {
i = i+1;
continue;
}
if ((isVal==1)) {

    unsigned int ____BAH_COMPILER_VAR_183 = len(currentElem);
    __Bah_realocate_arr(currentElem, ____BAH_COMPILER_VAR_183);
    currentElem->data[____BAH_COMPILER_VAR_183] = c;
}
else {

    unsigned int ____BAH_COMPILER_VAR_184 = len(currentKey);
    __Bah_realocate_arr(currentKey, ____BAH_COMPILER_VAR_184);
    currentKey->data[____BAH_COMPILER_VAR_184] = c;
}
}
i = i+1;
};
char * ____BAH_COMPILER_VAR_185 =arrToStr(currentElem);struct jsonElement* elem = parseJson(____BAH_COMPILER_VAR_185);
if ((elem!=null)) {
elem->key = arrToStr(currentKey);

    unsigned int ____BAH_COMPILER_VAR_186 = elemIndex;
    __Bah_realocate_arr(jsonElem->children, ____BAH_COMPILER_VAR_186);
    jsonElem->children->data[____BAH_COMPILER_VAR_186] = elem;
}
}
return jsonElem;
};
char json_isPrintable(unsigned int c){
if ((c<32)||(c>255)) {
return false;
}
return (c!=127)&&(c!=129)&&(c!=141)&&(c!=143)&&(c!=144)&&(c!=157);
};
char * jsonEscapeStr(char * s){
array(char)* a = strAsArr(s);
array(char)* r = memoryAlloc(sizeof(array(char)));

r->length = 0;
r->elemSize = sizeof(char);
register long int i = 0;
while ((i<len(a))) {
char c = a->data[i];
if ((json_isPrintable((unsigned int)c)==false)) {
++i;
continue;
}
if ((c==(char)34)) {

    unsigned int ____BAH_COMPILER_VAR_187 = len(r);
    __Bah_realocate_arr(r, ____BAH_COMPILER_VAR_187);
    r->data[____BAH_COMPILER_VAR_187] = (char)92;
}
else if ((c==(char)10)) {

    unsigned int ____BAH_COMPILER_VAR_188 = len(r);
    __Bah_realocate_arr(r, ____BAH_COMPILER_VAR_188);
    r->data[____BAH_COMPILER_VAR_188] = (char)92;

    unsigned int ____BAH_COMPILER_VAR_189 = len(r);
    __Bah_realocate_arr(r, ____BAH_COMPILER_VAR_189);
    r->data[____BAH_COMPILER_VAR_189] = 110;
i = i+1;
continue;
}
else if ((c==(char)13)) {

    unsigned int ____BAH_COMPILER_VAR_190 = len(r);
    __Bah_realocate_arr(r, ____BAH_COMPILER_VAR_190);
    r->data[____BAH_COMPILER_VAR_190] = (char)92;

    unsigned int ____BAH_COMPILER_VAR_191 = len(r);
    __Bah_realocate_arr(r, ____BAH_COMPILER_VAR_191);
    r->data[____BAH_COMPILER_VAR_191] = 114;
i = i+1;
continue;
}

    unsigned int ____BAH_COMPILER_VAR_192 = len(r);
    __Bah_realocate_arr(r, ____BAH_COMPILER_VAR_192);
    r->data[____BAH_COMPILER_VAR_192] = c;
i = i+1;
};
return arrToStr(r);
};
char * toJson__inner(struct reflectElement e,char isMember,long int tabs){
void ** v = e.value;
if ((e.value==null)||(*v==null)) {
if ((strcmp(e.type, "int") == 0)||(strcmp(e.type, "float") == 0)) {
return "0";
}
if ((strcmp(e.type, "bool") == 0)) {
return "false";
}
if ((strcmp(e.type, "ptr") == 0)||(strcmp(e.type, "cpstring") == 0)||(strCount(e.type,"*")!=0)) {
return "null";
}
}
if ((e.isStruct==true)) {
tabs = tabs+1;
char * tabsStr = "";
register long int i = 0;
while ((i<tabs)) {
char** ____BAH_COMPILER_VAR_193 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_193[1] = "\t";____BAH_COMPILER_VAR_193[0] = tabsStr;char * ____BAH_COMPILER_VAR_194 =__Bah_multiple_concat(____BAH_COMPILER_VAR_193, 2);tabsStr = ____BAH_COMPILER_VAR_194;
i = i+1;
};
char * s = "{\n";
i = 0;
while ((i<len(e.structLayout))) {
struct reflectElement m = e.structLayout->data[i];
i = i+1;
if ((i<len(e.structLayout))) {
char** ____BAH_COMPILER_VAR_195 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_195[6] = ",\n";____BAH_COMPILER_VAR_195[5] = toJson__inner(m,true,tabs);____BAH_COMPILER_VAR_195[4] = "\": ";____BAH_COMPILER_VAR_195[3] = m.name;____BAH_COMPILER_VAR_195[2] = "\"";____BAH_COMPILER_VAR_195[1] = tabsStr;____BAH_COMPILER_VAR_195[0] = s;char * ____BAH_COMPILER_VAR_196 =__Bah_multiple_concat(____BAH_COMPILER_VAR_195, 7);s = ____BAH_COMPILER_VAR_196;
}
else {
char** ____BAH_COMPILER_VAR_197 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_197[6] = "\n";____BAH_COMPILER_VAR_197[5] = toJson__inner(m,true,tabs);____BAH_COMPILER_VAR_197[4] = "\": ";____BAH_COMPILER_VAR_197[3] = m.name;____BAH_COMPILER_VAR_197[2] = "\"";____BAH_COMPILER_VAR_197[1] = tabsStr;____BAH_COMPILER_VAR_197[0] = s;char * ____BAH_COMPILER_VAR_198 =__Bah_multiple_concat(____BAH_COMPILER_VAR_197, 7);s = ____BAH_COMPILER_VAR_198;
}
};
tabs = tabs-1;
tabsStr = "";
i = 0;
while ((i<tabs)) {
char** ____BAH_COMPILER_VAR_199 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_199[1] = "\t";____BAH_COMPILER_VAR_199[0] = tabsStr;char * ____BAH_COMPILER_VAR_200 =__Bah_multiple_concat(____BAH_COMPILER_VAR_199, 2);tabsStr = ____BAH_COMPILER_VAR_200;
i = i+1;
};
char** ____BAH_COMPILER_VAR_201 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_201[2] = "}";____BAH_COMPILER_VAR_201[1] = tabsStr;____BAH_COMPILER_VAR_201[0] = s;char * ____BAH_COMPILER_VAR_202 =__Bah_multiple_concat(____BAH_COMPILER_VAR_201, 3);s = ____BAH_COMPILER_VAR_202;
return s;
}
else if ((strcmp(e.type, "int") == 0)) {
long int* ip = e.value;
return intToStr(*ip);
}
else if ((strcmp(e.type, "float") == 0)) {
double* fp = e.value;
return floatToStr(*fp);
}
else if ((strcmp(e.type, "cpstring") == 0)) {
if ((isMember==false)) {
void * s = e.value;
char** ____BAH_COMPILER_VAR_203 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_203[2] = "\"";____BAH_COMPILER_VAR_203[1] = jsonEscapeStr(s);____BAH_COMPILER_VAR_203[0] = "\"";char * ____BAH_COMPILER_VAR_204 =__Bah_multiple_concat(____BAH_COMPILER_VAR_203, 3);return ____BAH_COMPILER_VAR_204;
}
else {
char ** sp = e.value;
char * s = *sp;
char** ____BAH_COMPILER_VAR_205 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_205[2] = "\"";____BAH_COMPILER_VAR_205[1] = jsonEscapeStr(s);____BAH_COMPILER_VAR_205[0] = "\"";char * ____BAH_COMPILER_VAR_206 =__Bah_multiple_concat(____BAH_COMPILER_VAR_205, 3);return ____BAH_COMPILER_VAR_206;
}
}
else if ((strcmp(e.type, "bool") == 0)) {
char* bp = e.value;
if ((*bp==true)) {
return "true";
}
return "false";
}
else if ((e.isArray==true)) {
char * s = "[";
struct reflectElement* ae = e.arrayElem;
if ((strcmp(ae->type, "int") == 0)) {
array(long int)* arr = memoryAlloc(sizeof(array(long int)));

arr->length = 0;
arr->elemSize = sizeof(long int);
void ** arrPtr = e.value;
arr = *arrPtr;
register long int i = 0;
while ((i<len(arr))) {
char** ____BAH_COMPILER_VAR_207 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_207[1] = intToStr(arr->data[i]);____BAH_COMPILER_VAR_207[0] = s;char * ____BAH_COMPILER_VAR_208 =__Bah_multiple_concat(____BAH_COMPILER_VAR_207, 2);s = ____BAH_COMPILER_VAR_208;
i = i+1;
if ((i<len(arr))) {
char** ____BAH_COMPILER_VAR_209 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_209[1] = ",";____BAH_COMPILER_VAR_209[0] = s;char * ____BAH_COMPILER_VAR_210 =__Bah_multiple_concat(____BAH_COMPILER_VAR_209, 2);s = ____BAH_COMPILER_VAR_210;
}
};
}
else if ((strcmp(ae->type, "float") == 0)) {
array(double)* arr = memoryAlloc(sizeof(array(double)));

arr->length = 0;
arr->elemSize = sizeof(double);
void ** arrPtr = e.value;
arr = *arrPtr;
register long int i = 0;
while ((i<len(arr))) {
char** ____BAH_COMPILER_VAR_211 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_211[1] = floatToStr(arr->data[i]);____BAH_COMPILER_VAR_211[0] = s;char * ____BAH_COMPILER_VAR_212 =__Bah_multiple_concat(____BAH_COMPILER_VAR_211, 2);s = ____BAH_COMPILER_VAR_212;
i = i+1;
if ((i<len(arr))) {
char** ____BAH_COMPILER_VAR_213 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_213[1] = ",";____BAH_COMPILER_VAR_213[0] = s;char * ____BAH_COMPILER_VAR_214 =__Bah_multiple_concat(____BAH_COMPILER_VAR_213, 2);s = ____BAH_COMPILER_VAR_214;
}
};
}
else if ((strcmp(ae->type, "cpstring") == 0)) {
array(char *)* arr = memoryAlloc(sizeof(array(char *)));

arr->length = 0;
arr->elemSize = sizeof(char *);
void ** arrPtr = e.value;
arr = *arrPtr;
char** ____BAH_COMPILER_VAR_215 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_215[1] = "\n";____BAH_COMPILER_VAR_215[0] = s;char * ____BAH_COMPILER_VAR_216 =__Bah_multiple_concat(____BAH_COMPILER_VAR_215, 2);s = ____BAH_COMPILER_VAR_216;
register long int i = 0;
while ((i<len(arr))) {
char** ____BAH_COMPILER_VAR_217 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_217[3] = "\"";____BAH_COMPILER_VAR_217[2] = jsonEscapeStr(arr->data[i]);____BAH_COMPILER_VAR_217[1] = "\"";____BAH_COMPILER_VAR_217[0] = s;char * ____BAH_COMPILER_VAR_218 =__Bah_multiple_concat(____BAH_COMPILER_VAR_217, 4);s = ____BAH_COMPILER_VAR_218;
i = i+1;
if ((i<len(arr))) {
char** ____BAH_COMPILER_VAR_219 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_219[1] = ",\n";____BAH_COMPILER_VAR_219[0] = s;char * ____BAH_COMPILER_VAR_220 =__Bah_multiple_concat(____BAH_COMPILER_VAR_219, 2);s = ____BAH_COMPILER_VAR_220;
}
else {
char** ____BAH_COMPILER_VAR_221 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_221[1] = "\n";____BAH_COMPILER_VAR_221[0] = s;char * ____BAH_COMPILER_VAR_222 =__Bah_multiple_concat(____BAH_COMPILER_VAR_221, 2);s = ____BAH_COMPILER_VAR_222;
}
};
}
else if ((ae->isStruct==true)) {
array(void *)* arr = memoryAlloc(sizeof(array(void *)));

arr->length = 0;
arr->elemSize = sizeof(void *);
if ((isMember==false)) {
arr = e.value;
}
else {
void ** ev = e.value;
arr = *ev;
}
register long int i = 0;
while ((i<len(arr))) {
void * arrElem = arr->data[i];
ae->value = arrElem;
register long int j = 0;
while ((j<len(ae->structLayout))) {
struct reflectElement m = ae->structLayout->data[j];
m.value = reflectElement__calculateOffset(&m,ae->value);

    unsigned int ____BAH_COMPILER_VAR_223 = j;
    __Bah_realocate_arr(ae->structLayout, ____BAH_COMPILER_VAR_223);
    ae->structLayout->data[____BAH_COMPILER_VAR_223] = m;
j = j+1;
};
char** ____BAH_COMPILER_VAR_224 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_224[1] = toJson__inner(*ae,false,tabs);____BAH_COMPILER_VAR_224[0] = s;char * ____BAH_COMPILER_VAR_225 =__Bah_multiple_concat(____BAH_COMPILER_VAR_224, 2);s = ____BAH_COMPILER_VAR_225;
i = i+1;
if ((i<len(arr))) {
char** ____BAH_COMPILER_VAR_226 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_226[1] = ",\n";____BAH_COMPILER_VAR_226[0] = s;char * ____BAH_COMPILER_VAR_227 =__Bah_multiple_concat(____BAH_COMPILER_VAR_226, 2);s = ____BAH_COMPILER_VAR_227;
}
else {
char** ____BAH_COMPILER_VAR_228 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_228[1] = "\n";____BAH_COMPILER_VAR_228[0] = s;char * ____BAH_COMPILER_VAR_229 =__Bah_multiple_concat(____BAH_COMPILER_VAR_228, 2);s = ____BAH_COMPILER_VAR_229;
}
};
}
char** ____BAH_COMPILER_VAR_230 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_230[1] = "]";____BAH_COMPILER_VAR_230[0] = s;char * ____BAH_COMPILER_VAR_231 =__Bah_multiple_concat(____BAH_COMPILER_VAR_230, 2);s = ____BAH_COMPILER_VAR_231;
return s;
}
return "0";
};
char * toJson(struct reflectElement e){
return toJson__inner(e,false,0);
};
struct debugFunctionArgument {
char * name;
char * type;
};
struct debugFunction {
char * name;
char * returns;
array(struct variable*)* args;
};
struct debugStruct {
char * name;
array(struct variable*)* membs;
};
struct debugType {
char * name;
char * refers;
};
void debugStart(){
println("[");
};
void debugPrint(char * name,long int line,struct reflectElement e){
if ((debug==false)) {
return;
}
char * ____BAH_COMPILER_VAR_232 = name;
struct reflectElement ____BAH_COMPILER_VAR_233 = __reflect(____BAH_COMPILER_VAR_232, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, 0);
char** ____BAH_COMPILER_VAR_234 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_234[8] = "\n    },\n    ";____BAH_COMPILER_VAR_234[7] = toJson(e);____BAH_COMPILER_VAR_234[6] = "\",\n        \"element\": ";____BAH_COMPILER_VAR_234[5] = intToStr(line);____BAH_COMPILER_VAR_234[4] = ":";____BAH_COMPILER_VAR_234[3] = compilerState.currentFile;____BAH_COMPILER_VAR_234[2] = ",\n        \"path\": \"";____BAH_COMPILER_VAR_234[1] = toJson(____BAH_COMPILER_VAR_233);____BAH_COMPILER_VAR_234[0] = "\n    {\n        \"name\": ";char * ____BAH_COMPILER_VAR_235 =__Bah_multiple_concat(____BAH_COMPILER_VAR_234, 9);println(____BAH_COMPILER_VAR_235);
};
void debugError(char * name,long int line,long int from,long int to,struct reflectElement e){
if ((debug==false)) {
return;
}
char * ____BAH_COMPILER_VAR_236 = name;
struct reflectElement ____BAH_COMPILER_VAR_237 = __reflect(____BAH_COMPILER_VAR_236, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, 0);
char** ____BAH_COMPILER_VAR_238 = alloca(13 * sizeof(char*));____BAH_COMPILER_VAR_238[12] = "\n    },\n    ";____BAH_COMPILER_VAR_238[11] = toJson(e);____BAH_COMPILER_VAR_238[10] = "\n        ],\n        \"element\": ";____BAH_COMPILER_VAR_238[9] = intToStr(to);____BAH_COMPILER_VAR_238[8] = ",\n            ";____BAH_COMPILER_VAR_238[7] = intToStr(from);____BAH_COMPILER_VAR_238[6] = "\",\n        \"range\": [\n            ";____BAH_COMPILER_VAR_238[5] = intToStr(line);____BAH_COMPILER_VAR_238[4] = ":";____BAH_COMPILER_VAR_238[3] = compilerState.currentFile;____BAH_COMPILER_VAR_238[2] = ",\n        \"path\": \"";____BAH_COMPILER_VAR_238[1] = toJson(____BAH_COMPILER_VAR_237);____BAH_COMPILER_VAR_238[0] = "\n    {\n        \"name\": ";char * ____BAH_COMPILER_VAR_239 =__Bah_multiple_concat(____BAH_COMPILER_VAR_238, 13);println(____BAH_COMPILER_VAR_239);
};
void debugEnd(){
println("\n    {\n        \"name\": \"file_end\"\n    }\n    ]\n    ");
};
void debugExit(){
println("\n    {\n        \"name\": \"error_end\"\n    }\n    ]\n    ");
};
void debugEndScope(long int line,struct Elems* elems){
if ((debug==false)) {
return;
}
register long int i = 0;
while ((i<len(elems->vars))) {
struct variable* v = elems->vars->data[i];
if ((v->declScope==elems)&&(v->isConst==false)) {
struct variable* ____BAH_COMPILER_VAR_240 = v;
char ** ____BAH_COMPILER_VAR_242 = (char **)((char*)(____BAH_COMPILER_VAR_240) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_243 = __reflect(____BAH_COMPILER_VAR_242, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_244 = (char **)((char*)(____BAH_COMPILER_VAR_240) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_245 = __reflect(____BAH_COMPILER_VAR_244, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_246 = (char*)((char*)(____BAH_COMPILER_VAR_240) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_247 = __reflect(____BAH_COMPILER_VAR_246, sizeof(char), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_248 = (char **)((char*)(____BAH_COMPILER_VAR_240) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_249 = __reflect(____BAH_COMPILER_VAR_248, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_250 = (char*)((char*)(____BAH_COMPILER_VAR_240) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_251 = __reflect(____BAH_COMPILER_VAR_250, sizeof(char), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_252 = (char **)((char*)(____BAH_COMPILER_VAR_240) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_253 = __reflect(____BAH_COMPILER_VAR_252, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
void ** ____BAH_COMPILER_VAR_254 = (void **)((char*)(____BAH_COMPILER_VAR_240) + offsetof(struct variable, declScope));
struct reflectElement ____BAH_COMPILER_VAR_255 = __reflect(____BAH_COMPILER_VAR_254, sizeof(void *), "ptr", "declScope", 0, 0, 0, 0, offsetof(struct variable, declScope));
char* ____BAH_COMPILER_VAR_256 = (char*)((char*)(____BAH_COMPILER_VAR_240) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_257 = __reflect(____BAH_COMPILER_VAR_256, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));
struct rope** ____BAH_COMPILER_VAR_258 = (struct rope**)((char*)(____BAH_COMPILER_VAR_240) + offsetof(struct variable, declRope));
void ** ____BAH_COMPILER_VAR_260 = (void **)((char*)(____BAH_COMPILER_VAR_258) + offsetof(struct rope, left));
struct reflectElement ____BAH_COMPILER_VAR_261 = __reflect(____BAH_COMPILER_VAR_260, sizeof(void *), "ptr", "left", 0, 0, 0, 0, offsetof(struct rope, left));
void ** ____BAH_COMPILER_VAR_262 = (void **)((char*)(____BAH_COMPILER_VAR_258) + offsetof(struct rope, right));
struct reflectElement ____BAH_COMPILER_VAR_263 = __reflect(____BAH_COMPILER_VAR_262, sizeof(void *), "ptr", "right", 0, 0, 0, 0, offsetof(struct rope, right));
char ** ____BAH_COMPILER_VAR_264 = (char **)((char*)(____BAH_COMPILER_VAR_258) + offsetof(struct rope, str));
struct reflectElement ____BAH_COMPILER_VAR_265 = __reflect(____BAH_COMPILER_VAR_264, sizeof(char *), "cpstring", "str", 0, 0, 0, 0, offsetof(struct rope, str));
int* ____BAH_COMPILER_VAR_266 = (int*)((char*)(____BAH_COMPILER_VAR_258) + offsetof(struct rope, lCount));
struct reflectElement ____BAH_COMPILER_VAR_267 = __reflect(____BAH_COMPILER_VAR_266, sizeof(int), "int32", "lCount", 0, 0, 0, 0, offsetof(struct rope, lCount));
int* ____BAH_COMPILER_VAR_268 = (int*)((char*)(____BAH_COMPILER_VAR_258) + offsetof(struct rope, len));
struct reflectElement ____BAH_COMPILER_VAR_269 = __reflect(____BAH_COMPILER_VAR_268, sizeof(int), "int32", "len", 0, 0, 0, 0, offsetof(struct rope, len));
int* ____BAH_COMPILER_VAR_270 = (int*)((char*)(____BAH_COMPILER_VAR_258) + offsetof(struct rope, totalLen));
struct reflectElement ____BAH_COMPILER_VAR_271 = __reflect(____BAH_COMPILER_VAR_270, sizeof(int), "int32", "totalLen", 0, 0, 0, 0, offsetof(struct rope, totalLen));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_259 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_259->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_259->length = 6;
        ____BAH_COMPILER_VAR_259->data = memoryAlloc(____BAH_COMPILER_VAR_259->length * ____BAH_COMPILER_VAR_259->elemSize);
        ____BAH_COMPILER_VAR_259->data[0] = ____BAH_COMPILER_VAR_261;
____BAH_COMPILER_VAR_259->data[1] = ____BAH_COMPILER_VAR_263;
____BAH_COMPILER_VAR_259->data[2] = ____BAH_COMPILER_VAR_265;
____BAH_COMPILER_VAR_259->data[3] = ____BAH_COMPILER_VAR_267;
____BAH_COMPILER_VAR_259->data[4] = ____BAH_COMPILER_VAR_269;
____BAH_COMPILER_VAR_259->data[5] = ____BAH_COMPILER_VAR_271;
struct reflectElement ____BAH_COMPILER_VAR_272 = __reflect(____BAH_COMPILER_VAR_258, sizeof(struct rope), "rope*", "declRope", 0, 0, 1, ____BAH_COMPILER_VAR_259, offsetof(struct variable, declRope));
char* ____BAH_COMPILER_VAR_273 = (char*)((char*)(____BAH_COMPILER_VAR_240) + offsetof(struct variable, canBeNull));
struct reflectElement ____BAH_COMPILER_VAR_274 = __reflect(____BAH_COMPILER_VAR_273, sizeof(char), "bool", "canBeNull", 0, 0, 0, 0, offsetof(struct variable, canBeNull));
char* ____BAH_COMPILER_VAR_275 = (char*)((char*)(____BAH_COMPILER_VAR_240) + offsetof(struct variable, canBeReg));
struct reflectElement ____BAH_COMPILER_VAR_276 = __reflect(____BAH_COMPILER_VAR_275, sizeof(char), "bool", "canBeReg", 0, 0, 0, 0, offsetof(struct variable, canBeReg));
char* ____BAH_COMPILER_VAR_277 = (char*)((char*)(____BAH_COMPILER_VAR_240) + offsetof(struct variable, isReg));
struct reflectElement ____BAH_COMPILER_VAR_278 = __reflect(____BAH_COMPILER_VAR_277, sizeof(char), "bool", "isReg", 0, 0, 0, 0, offsetof(struct variable, isReg));
void ** ____BAH_COMPILER_VAR_279 = (void **)((char*)(____BAH_COMPILER_VAR_240) + offsetof(struct variable, lastSet));
struct reflectElement ____BAH_COMPILER_VAR_280 = __reflect(____BAH_COMPILER_VAR_279, sizeof(void *), "ptr", "lastSet", 0, 0, 0, 0, offsetof(struct variable, lastSet));
char* ____BAH_COMPILER_VAR_281 = (char*)((char*)(____BAH_COMPILER_VAR_240) + offsetof(struct variable, isArg));
struct reflectElement ____BAH_COMPILER_VAR_282 = __reflect(____BAH_COMPILER_VAR_281, sizeof(char), "bool", "isArg", 0, 0, 0, 0, offsetof(struct variable, isArg));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_241 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_241->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_241->length = 14;
        ____BAH_COMPILER_VAR_241->data = memoryAlloc(____BAH_COMPILER_VAR_241->length * ____BAH_COMPILER_VAR_241->elemSize);
        ____BAH_COMPILER_VAR_241->data[0] = ____BAH_COMPILER_VAR_243;
____BAH_COMPILER_VAR_241->data[1] = ____BAH_COMPILER_VAR_245;
____BAH_COMPILER_VAR_241->data[2] = ____BAH_COMPILER_VAR_247;
____BAH_COMPILER_VAR_241->data[3] = ____BAH_COMPILER_VAR_249;
____BAH_COMPILER_VAR_241->data[4] = ____BAH_COMPILER_VAR_251;
____BAH_COMPILER_VAR_241->data[5] = ____BAH_COMPILER_VAR_253;
____BAH_COMPILER_VAR_241->data[6] = ____BAH_COMPILER_VAR_255;
____BAH_COMPILER_VAR_241->data[7] = ____BAH_COMPILER_VAR_257;
____BAH_COMPILER_VAR_241->data[8] = ____BAH_COMPILER_VAR_272;
____BAH_COMPILER_VAR_241->data[9] = ____BAH_COMPILER_VAR_274;
____BAH_COMPILER_VAR_241->data[10] = ____BAH_COMPILER_VAR_276;
____BAH_COMPILER_VAR_241->data[11] = ____BAH_COMPILER_VAR_278;
____BAH_COMPILER_VAR_241->data[12] = ____BAH_COMPILER_VAR_280;
____BAH_COMPILER_VAR_241->data[13] = ____BAH_COMPILER_VAR_282;
struct reflectElement ____BAH_COMPILER_VAR_283 = __reflect(____BAH_COMPILER_VAR_240, sizeof(struct variable), "variable*", "v", 0, 0, 1, ____BAH_COMPILER_VAR_241, 0);
debugPrint("var_end",line,____BAH_COMPILER_VAR_283);
}
i = i+1;
};
};
void throwErr(void * tp,char * format){
char * str = "";
char * info = "";
long int pos = 0;
if ((tp!=null)) {
struct fileMap ____BAH_COMPILER_VAR_284 = {};
____BAH_COMPILER_VAR_284.handle = -1;
#define fm ____BAH_COMPILER_VAR_284
char * fileSrcStr = fileMap__open(&fm,compilerState.currentFile);
struct Tok* t = tp;
struct string ffmt = string(format);
if ((strlen(t->ogCont)==0)) {
t->ogCont = t->cont;
}
char** ____BAH_COMPILER_VAR_285 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_285[2] = "'";____BAH_COMPILER_VAR_285[1] = t->ogCont;____BAH_COMPILER_VAR_285[0] = "'";char * ____BAH_COMPILER_VAR_286 =__Bah_multiple_concat(____BAH_COMPILER_VAR_285, 3);string__replace(&ffmt,"{TOKEN}",____BAH_COMPILER_VAR_286);
format = string__str(&ffmt);
array(char)* line = memoryAlloc(sizeof(array(char)));

line->length = 0;
line->elemSize = sizeof(char);
unsigned int beg = t->pos;
while ((beg>0)) {
char c = fileSrcStr[beg];
if ((c==(char)10)) {
beg = beg+1;
break;
}
beg = beg-1;
};
pos = t->pos-beg+1;
unsigned int i = beg;
for (; (i<fm.size); ++i) {
char c = fileSrcStr[i];
if ((c==(char)10)) {
break;
}
if ((i==t->pos)) {
array(char)* errCont = memoryAlloc(sizeof(array(char)));

errCont->length = 0;
errCont->elemSize = sizeof(char);
unsigned int offset = i;
for (; (i<fm.size); ++i) {
if ((i-offset>=strlen(t->ogCont))) {
break;
}
if ((fileSrcStr[i]!=t->ogCont[i-offset])) {
if ((isSpace(fileSrcStr[i])==false)) {
break;
}
++offset;
}

    unsigned int ____BAH_COMPILER_VAR_287 = len(errCont);
    __Bah_realocate_arr(errCont, ____BAH_COMPILER_VAR_287);
    errCont->data[____BAH_COMPILER_VAR_287] = fileSrcStr[i];
};
char** ____BAH_COMPILER_VAR_288 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_288[2] = "\e[1;37m";____BAH_COMPILER_VAR_288[1] = arrToStr(errCont);____BAH_COMPILER_VAR_288[0] = "\e[1;31m";char * ____BAH_COMPILER_VAR_289 =__Bah_multiple_concat(____BAH_COMPILER_VAR_288, 3);array(char)* errTk = strToArr(____BAH_COMPILER_VAR_289);
register long int ii = 0;
for (; (ii<len(errTk)); ++ii) {

    unsigned int ____BAH_COMPILER_VAR_290 = len(line);
    __Bah_realocate_arr(line, ____BAH_COMPILER_VAR_290);
    line->data[____BAH_COMPILER_VAR_290] = errTk->data[ii];
};
--i;
continue;
}

    unsigned int ____BAH_COMPILER_VAR_291 = len(line);
    __Bah_realocate_arr(line, ____BAH_COMPILER_VAR_291);
    line->data[____BAH_COMPILER_VAR_291] = c;
};
fileMap__close(&fm);
str = arrToStr(line);
char** ____BAH_COMPILER_VAR_292 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_292[2] = intToStr(pos);____BAH_COMPILER_VAR_292[1] = ":";____BAH_COMPILER_VAR_292[0] = intToStr(t->line);char * ____BAH_COMPILER_VAR_293 =__Bah_multiple_concat(____BAH_COMPILER_VAR_292, 3);info = ____BAH_COMPILER_VAR_293;

#undef fm
}
if ((debug==true)) {
struct Tok* t = tp;
char * ____BAH_COMPILER_VAR_294 = format;
struct reflectElement ____BAH_COMPILER_VAR_295 = __reflect(____BAH_COMPILER_VAR_294, sizeof(char *), "cpstring", "format", 0, 0, 0, 0, 0);
debugError("error",t->line,pos,pos+strlen(t->ogCont),____BAH_COMPILER_VAR_295);
debugExit();
}
else {
char** ____BAH_COMPILER_VAR_296 = alloca(8 * sizeof(char*));____BAH_COMPILER_VAR_296[7] = format;____BAH_COMPILER_VAR_296[6] = "\e[0m\n";____BAH_COMPILER_VAR_296[5] = str;____BAH_COMPILER_VAR_296[4] = "\n\e[1;37m\t";____BAH_COMPILER_VAR_296[3] = info;____BAH_COMPILER_VAR_296[2] = ":";____BAH_COMPILER_VAR_296[1] = compilerState.currentFile;____BAH_COMPILER_VAR_296[0] = "\e[1;31m[ERROR]\e[0m ";char * ____BAH_COMPILER_VAR_297 =__Bah_multiple_concat(____BAH_COMPILER_VAR_296, 8);println(____BAH_COMPILER_VAR_297);
}
exit(1);
};
void throwWarning(char * s){
char** ____BAH_COMPILER_VAR_298 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_298[4] = "\e[0m";____BAH_COMPILER_VAR_298[3] = s;____BAH_COMPILER_VAR_298[2] = "\n\e[0m\t";____BAH_COMPILER_VAR_298[1] = compilerState.currentFile;____BAH_COMPILER_VAR_298[0] = "\e[1;33m[WARNING]\e[0m ";char * ____BAH_COMPILER_VAR_299 =__Bah_multiple_concat(____BAH_COMPILER_VAR_298, 5);println(____BAH_COMPILER_VAR_299);
};
void throwWarningLine(char * s,long int l){
char** ____BAH_COMPILER_VAR_300 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_300[6] = "\e[0m";____BAH_COMPILER_VAR_300[5] = s;____BAH_COMPILER_VAR_300[4] = "\n\e[0m\t";____BAH_COMPILER_VAR_300[3] = intToStr(l);____BAH_COMPILER_VAR_300[2] = ":";____BAH_COMPILER_VAR_300[1] = compilerState.currentFile;____BAH_COMPILER_VAR_300[0] = "\e[1;33m[WARNING]\e[0m ";char * ____BAH_COMPILER_VAR_301 =__Bah_multiple_concat(____BAH_COMPILER_VAR_300, 7);println(____BAH_COMPILER_VAR_301);
};
void throwNoticeLine(char * s,long int l){
if ((noticeEnabled==false)) {
return;
}
char** ____BAH_COMPILER_VAR_302 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_302[6] = "\e[0m";____BAH_COMPILER_VAR_302[5] = s;____BAH_COMPILER_VAR_302[4] = "\n\e[0m\t";____BAH_COMPILER_VAR_302[3] = intToStr(l);____BAH_COMPILER_VAR_302[2] = ":";____BAH_COMPILER_VAR_302[1] = compilerState.currentFile;____BAH_COMPILER_VAR_302[0] = "\e[1;36m[NOTICE]\e[0m ";char * ____BAH_COMPILER_VAR_303 =__Bah_multiple_concat(____BAH_COMPILER_VAR_302, 7);println(____BAH_COMPILER_VAR_303);
};
#include <stdlib.h>
char * absPath(char * path){
char * p = realpath(path,null);
return p;
};
char * getCurrentPath(){
char * cwd = memoryAlloc(4096);
getcwd(cwd,4096);
return cwd;
};
char isInside(char * basePath,char * subPath){
char * abs1 = absPath(basePath);
char * abs2 = absPath(subPath);
return (strHasPrefix(subPath,basePath)==true);
};
void setCurrentPath(char * s){
chdir(s);
};
char isGlobal(){
return (currentFn==null);
};
struct variable* getRealVar(char * n,struct Elems* elems){
register long int i = len(elems->vars)-1;
for (; (i!=-1); --i) {
if ((strcmp(elems->vars->data[i]->name, n) == 0)) {
return elems->vars->data[i];
}
};
return null;
};
void removeVarUnar(struct string* s){
array(char)* arr = string__asArr(s);
register long int i = 0;
for (; (i<len(arr)); ++i) {
char c = arr->data[i];
if ((c==38)||(c==42)) {
delete(arr,i);
--i;
continue;
}
};
};
struct variable* searchVar(char * name,struct Elems* elems){
char * ogName = name;
struct string n = string(name);
removeVarUnar(&n);
if ((string__charAt(&n,n.length-1)==93)) {
register long int i = n.length;
while ((i>0)) {
char c = string__charAt(&n,i);
if ((c==91)) {
break;
}
i = i-1;
};
long int tamm = n.length-i;
string__trimRight(&n,tamm);
char isArr = (string__hasSuffix(&n,"->data")==1);
if ((isArr==true)) {
string__trimRight(&n,6);
}
name = string__str(&n);
struct variable* v = searchVar(name,elems);
struct string vt = string(v->type);
if ((isArr==true)) {
string__trimLeft(&vt,2);
}
else {
string__set(&vt,"char");
}
char * vtstr = string__str(&vt);
struct variable* ____BAH_COMPILER_VAR_304 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_304->name = "";
____BAH_COMPILER_VAR_304->type = "";
____BAH_COMPILER_VAR_304->constVal = "";
____BAH_COMPILER_VAR_304->from = "";
struct variable* nv = ____BAH_COMPILER_VAR_304;
*nv = *v;
nv->type = vtstr;
nv->name = ogName;
nv->isArray = isArr;
return nv;
}
name = n.content;
if (hasStructSep(&n)&&(string__count(&n,")")==0)) {
struct string rn = splitStructSepBefore(&n);
name = rn.content;
string__trimLeft(&n,rn.length);
if (string__hasPrefix(&n,".")) {
string__trimLeft(&n,1);
}
else {
string__trimLeft(&n,2);
}
char * membs = n.content;
struct variable* v = searchVar(name,elems);
if ((v==null)) {
return null;
}
struct cStruct* s = searchStruct(v->type,elems);
if ((s==null)) {
return null;
}
struct structMemb* memb = searchStructMemb(membs,s,elems);
if ((memb==null)) {
return null;
}
struct variable* ____BAH_COMPILER_VAR_305 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_305->name = "";
____BAH_COMPILER_VAR_305->type = "";
____BAH_COMPILER_VAR_305->constVal = "";
____BAH_COMPILER_VAR_305->from = "";
struct variable* nv = ____BAH_COMPILER_VAR_305;
nv->from = memb->from;
nv->name = memb->name;
nv->type = memb->type;
nv->declScope = v->declScope;
nv->name = ogName;
char * r = nv->type;
struct string tcc = string(ogName);
if (string__count(&tcc,"&")) {
char** ____BAH_COMPILER_VAR_306 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_306[1] = "*";____BAH_COMPILER_VAR_306[0] = r;char * ____BAH_COMPILER_VAR_307 =__Bah_multiple_concat(____BAH_COMPILER_VAR_306, 2);r = ____BAH_COMPILER_VAR_307;
}
long int nbUnaries = string__count(&tcc,"*");
if ((nbUnaries>0)) {
struct string ct = string(r);
long int pointerLevel = string__count(&ct,"*");
if ((pointerLevel<nbUnaries)) {
char** ____BAH_COMPILER_VAR_308 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_308[2] = " because it is not pointer.";____BAH_COMPILER_VAR_308[1] = nv->name;____BAH_COMPILER_VAR_308[0] = "Cannot use '*' on ";char * ____BAH_COMPILER_VAR_309 =__Bah_multiple_concat(____BAH_COMPILER_VAR_308, 3);throwErr(null,____BAH_COMPILER_VAR_309);
}
string__trimRight(&ct,nbUnaries);
r = string__str(&ct);
}
nv->type = r;
nv->name = ogName;
return nv;
}
register long int i = len(elems->vars)-1;
for (; (i!=-1); --i) {
struct variable* v = elems->vars->data[i];
if ((strcmp(v->name, name) == 0)) {
struct variable* ____BAH_COMPILER_VAR_310 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_310->name = "";
____BAH_COMPILER_VAR_310->type = "";
____BAH_COMPILER_VAR_310->constVal = "";
____BAH_COMPILER_VAR_310->from = "";
struct variable* nv = ____BAH_COMPILER_VAR_310;
*nv = *v;
char * r = nv->type;
struct string tcc = string(ogName);
if (string__count(&tcc,"&")) {
char** ____BAH_COMPILER_VAR_311 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_311[1] = "*";____BAH_COMPILER_VAR_311[0] = r;char * ____BAH_COMPILER_VAR_312 =__Bah_multiple_concat(____BAH_COMPILER_VAR_311, 2);r = ____BAH_COMPILER_VAR_312;
}
long int nbUnaries = string__count(&tcc,"*");
if ((nbUnaries>0)) {
struct string ct = string(r);
long int pointerLevel = string__count(&ct,"*");
if ((pointerLevel<nbUnaries)) {
char** ____BAH_COMPILER_VAR_313 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_313[2] = " because it is not pointer.";____BAH_COMPILER_VAR_313[1] = v->name;____BAH_COMPILER_VAR_313[0] = "Cannot use '*' on ";char * ____BAH_COMPILER_VAR_314 =__Bah_multiple_concat(____BAH_COMPILER_VAR_313, 3);throwErr(null,____BAH_COMPILER_VAR_314);
}
string__trimRight(&ct,nbUnaries);
r = string__str(&ct);
}
nv->type = r;
nv->name = ogName;
return nv;
}
};
i = 0;
for (; (i<len(elems->fns)); ++i) {
struct func* fn = elems->fns->data[i];
if ((strcmp(fn->name, name) == 0)) {
struct variable* ____BAH_COMPILER_VAR_315 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_315->name = "";
____BAH_COMPILER_VAR_315->type = "";
____BAH_COMPILER_VAR_315->constVal = "";
____BAH_COMPILER_VAR_315->from = "";
struct variable* nv = ____BAH_COMPILER_VAR_315;
nv->name = name;
nv->type = "function(";
register long int j = 0;
while ((j<len(fn->args))) {
struct variable* arg = fn->args->data[j];
char** ____BAH_COMPILER_VAR_316 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_316[1] = arg->type;____BAH_COMPILER_VAR_316[0] = nv->type;char * ____BAH_COMPILER_VAR_317 =__Bah_multiple_concat(____BAH_COMPILER_VAR_316, 2);nv->type = ____BAH_COMPILER_VAR_317;
j = j+1;
if ((j<len(fn->args))) {
char** ____BAH_COMPILER_VAR_318 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_318[1] = ",";____BAH_COMPILER_VAR_318[0] = nv->type;char * ____BAH_COMPILER_VAR_319 =__Bah_multiple_concat(____BAH_COMPILER_VAR_318, 2);nv->type = ____BAH_COMPILER_VAR_319;
}
};
fn->used = true;
char** ____BAH_COMPILER_VAR_320 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_320[2] = fn->returns->type;____BAH_COMPILER_VAR_320[1] = ")";____BAH_COMPILER_VAR_320[0] = nv->type;char * ____BAH_COMPILER_VAR_321 =__Bah_multiple_concat(____BAH_COMPILER_VAR_320, 3);nv->type = ____BAH_COMPILER_VAR_321;
return nv;
}
};
return null;
};
struct variable* searchVarByToken(struct Tok* t,struct Elems* elems){
if ((t->bahRef!=null)) {
return t->bahRef;
}
struct string cont = string(t->cont);
removeVarUnar(&cont);
char * ____BAH_COMPILER_VAR_322 =string__str(&cont);return getRealVar(____BAH_COMPILER_VAR_322,elems);
};
struct variable* searchVirtVarByToken(struct Tok* t,struct Elems* elems){
if ((t->bahRef!=null)) {
return t->bahRef;
}
return searchVar(t->cont,elems);
};
char * setCType(struct variable* v,struct Elems* elems){
struct string tp = getCType(v->type,elems);
char * t = string__str(&tp);
char** ____BAH_COMPILER_VAR_323 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_323[2] = v->name;____BAH_COMPILER_VAR_323[1] = " ";____BAH_COMPILER_VAR_323[0] = t;char * ____BAH_COMPILER_VAR_324 =__Bah_multiple_concat(____BAH_COMPILER_VAR_323, 3);t = ____BAH_COMPILER_VAR_324;
return t;
};
char * getTypeFromToken(struct Tok* t,char strict,struct Elems* elems){
if ((strcmp(t->bahType, "") != 0)) {
char * r = t->bahType;
return r;
}
if ((t->type==TOKEN_TYPE_VAR)) {
struct variable* v = searchVar(t->cont,elems);
if ((v==null)) {
if ((strict==true)) {
throwErr(t,"Unknown var {TOKEN}.");
}
else {
return "";
}
}
if ((strict==true)) {
if ((strcmp(v->type, "") == 0)) {
throwErr(t,"Cannot use {TOKEN} because it does not have any type.");
}
}
t->bahType = v->type;
return v->type;
}
if ((t->type==TOKEN_TYPE_FLOAT)) {
return "float";
}
if ((t->type==TOKEN_TYPE_INT)) {
return "int";
}
if ((t->type==TOKEN_TYPE_STR)) {
return "cpstring";
}
if ((t->type==TOKEN_TYPE_CHAR)) {
return "char";
}
if ((t->type==TOKEN_TYPE_BOOL)) {
return "bool";
}
throwErr(t,"Cannot use {TOKEN} as value.");
return "";
};
struct func* parseFnType(struct string cvt){
struct func* ____BAH_COMPILER_VAR_325 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_325->name = "";
____BAH_COMPILER_VAR_325->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_325->args->length = 0;
            ____BAH_COMPILER_VAR_325->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_325->from = "";
____BAH_COMPILER_VAR_325->file = "";
____BAH_COMPILER_VAR_325->line = 1;
struct func* nf = ____BAH_COMPILER_VAR_325;
string__trimLeft(&cvt,9);
array(char)* memory = memoryAlloc(sizeof(array(char)));

memory->length = 0;
memory->elemSize = sizeof(char);
register long int j = 0;
while ((j<cvt.length)) {
char c = string__charAt(&cvt,j);
if ((c==41)) {
break;
}
struct variable* ____BAH_COMPILER_VAR_326 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_326->name = "";
____BAH_COMPILER_VAR_326->type = "";
____BAH_COMPILER_VAR_326->constVal = "";
____BAH_COMPILER_VAR_326->from = "";
struct variable* arg = ____BAH_COMPILER_VAR_326;
char** ____BAH_COMPILER_VAR_327 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_327[1] = intToStr(len(nf->args));____BAH_COMPILER_VAR_327[0] = "arg_";char * ____BAH_COMPILER_VAR_328 =__Bah_multiple_concat(____BAH_COMPILER_VAR_327, 2);arg->name = ____BAH_COMPILER_VAR_328;
while ((j<cvt.length)) {
c = string__charAt(&cvt,j);
if ((c==44)||(c==41)) {
break;
}

    unsigned int ____BAH_COMPILER_VAR_329 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_329);
    memory->data[____BAH_COMPILER_VAR_329] = c;
j = j+1;
};
arg->type = arrToStr(memory);
clear(memory);

    unsigned int ____BAH_COMPILER_VAR_330 = len(nf->args);
    __Bah_realocate_arr(nf->args, ____BAH_COMPILER_VAR_330);
    nf->args->data[____BAH_COMPILER_VAR_330] = arg;
if ((c==41)) {
break;
}
j = j+1;
};
j = j+1;
while ((j<cvt.length)) {
char c = string__charAt(&cvt,j);

    unsigned int ____BAH_COMPILER_VAR_331 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_331);
    memory->data[____BAH_COMPILER_VAR_331] = c;
j = j+1;
};
struct variable* ____BAH_COMPILER_VAR_332 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_332->name = "";
____BAH_COMPILER_VAR_332->type = "";
____BAH_COMPILER_VAR_332->constVal = "";
____BAH_COMPILER_VAR_332->from = "";
nf->returns = ____BAH_COMPILER_VAR_332;
nf->returns->name = "_return";
nf->returns->type = arrToStr(memory);
return nf;
};
struct func* searchFunc(char * name,struct Elems* elems,char inclCurr){
char * ogName = name;
if ((strcmp(name, "noCheck") == 0)) {
struct func* ____BAH_COMPILER_VAR_333 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_333->name = "";
____BAH_COMPILER_VAR_333->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_333->args->length = 0;
            ____BAH_COMPILER_VAR_333->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_333->from = "";
____BAH_COMPILER_VAR_333->file = "";
____BAH_COMPILER_VAR_333->line = 1;
struct func* fn = ____BAH_COMPILER_VAR_333;
fn->name = "noCheck";
return fn;
}
struct string n = string(name);
if (hasStructSep(&n)) {
struct string fnName = splitStructSepAfter(n);
string__trimRight(&n,fnName.length);
char c = string__charAt(&n,n.length-1);
if ((c==46)) {
string__trimRight(&n,1);
}
else {
string__trimRight(&n,2);
}
name = string__str(&n);
struct variable* v = searchVar(name,elems);
if ((v==null)) {
return null;
}
struct cStruct* s = searchStruct(v->type,elems);
if ((s==null)) {
return null;
}
char * ____BAH_COMPILER_VAR_334 =string__str(&fnName);struct structMemb* memb = searchStructMemb(____BAH_COMPILER_VAR_334,s,elems);
if ((memb==null)) {
return null;
}
name = fnName.content;
char** ____BAH_COMPILER_VAR_335 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_335[2] = name;____BAH_COMPILER_VAR_335[1] = "__";____BAH_COMPILER_VAR_335[0] = memb->from;char * ____BAH_COMPILER_VAR_336 =__Bah_multiple_concat(____BAH_COMPILER_VAR_335, 3);name = ____BAH_COMPILER_VAR_336;
}
array(struct func*)* fns = elems->fns;
register long int i = 0;
while ((i<len(fns))) {
struct func* fn = fns->data[i];
if ((strcmp(fn->name, name) == 0)) {
fn->used = true;
return fn;
}
i = i+1;
};
if ((inclCurr==true)&&(currentFn!=null)) {
if ((strcmp(currentFn->name, name) == 0)) {
currentFn->used = true;
return currentFn;
}
}
struct variable* v = searchVar(ogName,elems);
if ((v==null)) {
return null;
}
struct func* ____BAH_COMPILER_VAR_337 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_337->name = "";
____BAH_COMPILER_VAR_337->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_337->args->length = 0;
            ____BAH_COMPILER_VAR_337->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_337->from = "";
____BAH_COMPILER_VAR_337->file = "";
____BAH_COMPILER_VAR_337->line = 1;
struct func* nf = ____BAH_COMPILER_VAR_337;
nf->name = ogName;
struct string cvt = string(v->type);
if ((string__hasPrefix(&cvt,"function(")==0)) {
return null;
}
struct func* pfn = parseFnType(cvt);
nf->returns = pfn->returns;
nf->args = pfn->args;
return nf;
};
struct func* searchFuncByToken(struct Tok* t,struct Elems* elems){
if ((t->bahRef!=null)) {
return t->bahRef;
}
struct string ____BAH_COMPILER_VAR_338 =string(t->cont);char * fnName = splitStringBefore(____BAH_COMPILER_VAR_338,"(");
return searchFunc(fnName,elems,true);
};
char RCPavailable();
char * declareStructMethods(struct variable* v,struct cStruct* s,struct Elems* elems){
char * code = "";
array(struct structMemb*)* members = s->members;
struct string typec = string(v->type);
char * sep = ".";
char * amp = "&";
if (string__count(&typec,"*")) {
sep = "->";
amp = "";
}
register long int i = 0;
for (; (i<len(members)); ++i) {
struct structMemb* m = members->data[i];
struct string cmpt = string(m->type);
if ((strcmp(m->def, "") != 0)) {
if ((strcmp(m->def, "false") != 0)&&(strcmp(m->def, "0") != 0)&&(strcmp(m->def, "null") != 0)) {
char** ____BAH_COMPILER_VAR_339 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_339[6] = ";\n";____BAH_COMPILER_VAR_339[5] = m->def;____BAH_COMPILER_VAR_339[4] = " = ";____BAH_COMPILER_VAR_339[3] = m->name;____BAH_COMPILER_VAR_339[2] = sep;____BAH_COMPILER_VAR_339[1] = v->name;____BAH_COMPILER_VAR_339[0] = code;char * ____BAH_COMPILER_VAR_340 =__Bah_multiple_concat(____BAH_COMPILER_VAR_339, 7);code = ____BAH_COMPILER_VAR_340;
}
continue;
}
if ((string__hasPrefix(&cmpt,"[]")==1)) {
string__trimLeft(&cmpt,2);
char * cmptstr = string__str(&cmpt);
struct string elemCType = getCType(cmptstr,elems);
char * elemCTypeStr = string__str(&elemCType);
char** ____BAH_COMPILER_VAR_341 = alloca(17 * sizeof(char*));____BAH_COMPILER_VAR_341[16] = ");\n            ";____BAH_COMPILER_VAR_341[15] = elemCTypeStr;____BAH_COMPILER_VAR_341[14] = "->elemSize = sizeof(";____BAH_COMPILER_VAR_341[13] = m->name;____BAH_COMPILER_VAR_341[12] = sep;____BAH_COMPILER_VAR_341[11] = v->name;____BAH_COMPILER_VAR_341[10] = "->length = 0;\n            ";____BAH_COMPILER_VAR_341[9] = m->name;____BAH_COMPILER_VAR_341[8] = sep;____BAH_COMPILER_VAR_341[7] = v->name;____BAH_COMPILER_VAR_341[6] = ")));\n            ";____BAH_COMPILER_VAR_341[5] = elemCTypeStr;____BAH_COMPILER_VAR_341[4] = " = memoryAlloc(sizeof(array(";____BAH_COMPILER_VAR_341[3] = m->name;____BAH_COMPILER_VAR_341[2] = sep;____BAH_COMPILER_VAR_341[1] = v->name;____BAH_COMPILER_VAR_341[0] = code;char * ____BAH_COMPILER_VAR_342 =__Bah_multiple_concat(____BAH_COMPILER_VAR_341, 17);code = ____BAH_COMPILER_VAR_342;
continue;
}
if ((string__hasPrefix(&cmpt,"map:")==1)) {
string__trimLeft(&cmpt,4);
char** ____BAH_COMPILER_VAR_343 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_343[3] = " = mapWrapper();\n";____BAH_COMPILER_VAR_343[2] = m->name;____BAH_COMPILER_VAR_343[1] = sep;____BAH_COMPILER_VAR_343[0] = v->name;char * ____BAH_COMPILER_VAR_344 =__Bah_multiple_concat(____BAH_COMPILER_VAR_343, 4);char** ____BAH_COMPILER_VAR_345 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_345[1] = ____BAH_COMPILER_VAR_344;____BAH_COMPILER_VAR_345[0] = code;char * ____BAH_COMPILER_VAR_346 =__Bah_multiple_concat(____BAH_COMPILER_VAR_345, 2);code = ____BAH_COMPILER_VAR_346;
continue;
}
if ((string__hasPrefix(&cmpt,"chan:")==1)) {
string__trimLeft(&cmpt,5);
char** ____BAH_COMPILER_VAR_347 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_347[3] = " = channel();\n";____BAH_COMPILER_VAR_347[2] = m->name;____BAH_COMPILER_VAR_347[1] = sep;____BAH_COMPILER_VAR_347[0] = v->name;char * ____BAH_COMPILER_VAR_348 =__Bah_multiple_concat(____BAH_COMPILER_VAR_347, 4);char** ____BAH_COMPILER_VAR_349 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_349[1] = ____BAH_COMPILER_VAR_348;____BAH_COMPILER_VAR_349[0] = code;char * ____BAH_COMPILER_VAR_350 =__Bah_multiple_concat(____BAH_COMPILER_VAR_349, 2);code = ____BAH_COMPILER_VAR_350;
}
};
if ((s->isBinding==false)) {
long int found = 0;
i = 0;
for (; (i<len(s->methods)); ++i) {
struct func* m = s->methods->data[i];
if ((strcmp(m->name, "_init") == 0)) {
char** ____BAH_COMPILER_VAR_351 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_351[6] = ");\n";____BAH_COMPILER_VAR_351[5] = v->name;____BAH_COMPILER_VAR_351[4] = amp;____BAH_COMPILER_VAR_351[3] = "(";____BAH_COMPILER_VAR_351[2] = m->name;____BAH_COMPILER_VAR_351[1] = sep;____BAH_COMPILER_VAR_351[0] = v->name;char * ____BAH_COMPILER_VAR_352 =__Bah_multiple_concat(____BAH_COMPILER_VAR_351, 7);char** ____BAH_COMPILER_VAR_353 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_353[1] = ____BAH_COMPILER_VAR_352;____BAH_COMPILER_VAR_353[0] = NEXT_LINE;char * ____BAH_COMPILER_VAR_354 =__Bah_multiple_concat(____BAH_COMPILER_VAR_353, 2);NEXT_LINE = ____BAH_COMPILER_VAR_354;
++found;
}
else if ((strcmp(m->name, "_end") == 0)) {
if ((strcmp(sep, "->") == 0)) {
char** ____BAH_COMPILER_VAR_355 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_355[6] = ");\n";____BAH_COMPILER_VAR_355[5] = m->name;____BAH_COMPILER_VAR_355[4] = sep;____BAH_COMPILER_VAR_355[3] = v->name;____BAH_COMPILER_VAR_355[2] = ", ";____BAH_COMPILER_VAR_355[1] = v->name;____BAH_COMPILER_VAR_355[0] = "memoryOnEnd(";char * ____BAH_COMPILER_VAR_356 =__Bah_multiple_concat(____BAH_COMPILER_VAR_355, 7);char** ____BAH_COMPILER_VAR_357 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_357[1] = ____BAH_COMPILER_VAR_356;____BAH_COMPILER_VAR_357[0] = code;char * ____BAH_COMPILER_VAR_358 =__Bah_multiple_concat(____BAH_COMPILER_VAR_357, 2);code = ____BAH_COMPILER_VAR_358;
}
++found;
}
if ((found==2)) {
break;
}
};
}
return code;
};
long int NB_COMP_VAR;
char * genCompilerVar(){
char** ____BAH_COMPILER_VAR_359 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_359[1] = intToStr(NB_COMP_VAR);____BAH_COMPILER_VAR_359[0] = "____BAH_COMPILER_VAR_";char * ____BAH_COMPILER_VAR_360 =__Bah_multiple_concat(____BAH_COMPILER_VAR_359, 2);char * name = ____BAH_COMPILER_VAR_360;
NB_COMP_VAR = NB_COMP_VAR+1;
return name;
};
typedef array(struct variable*)* __BAH_ARR_TYPE_variable;
char varInArr(struct variable* v,__BAH_ARR_TYPE_variable arr){
if ((arr==null)) {
return false;
}
register long int j = 0;
while ((j<len(arr))) {
struct variable* ev = arr->data[j];
if ((strcmp(ev->name, v->name) == 0)) {
return true;
}
j = j+1;
};
return false;
};
char * pathToVarName(char * p){
array(char)* a = strToArr(p);
register long int i = 0;
for (; (i<len(a)); ++i) {
long int c = a->data[i];
c = c-(long int)97;
if ((c<0)) {
c = 0-c;
}
c = c%((long int)122-(long int)97);
c = c+(long int)97;

    unsigned int ____BAH_COMPILER_VAR_361 = i;
    __Bah_realocate_arr(a, ____BAH_COMPILER_VAR_361);
    a->data[____BAH_COMPILER_VAR_361] = (char)c;
};
return arrToStr(a);
};
void makeInit(){
char * name = "__BAH_init";
if ((isObject==true)) {
char** ____BAH_COMPILER_VAR_362 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_362[1] = pathToVarName(compilerState.currentFile);____BAH_COMPILER_VAR_362[0] = name;char * ____BAH_COMPILER_VAR_363 =__Bah_multiple_concat(____BAH_COMPILER_VAR_362, 2);name = ____BAH_COMPILER_VAR_363;
}
char * evals = "";
char** ____BAH_COMPILER_VAR_364 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_364[2] = "] = {";____BAH_COMPILER_VAR_364[1] = intToStr(len(compilerState.evals));____BAH_COMPILER_VAR_364[0] = "volatile struct __eval_binding __tmp__evals_bindings[";char * ____BAH_COMPILER_VAR_365 =__Bah_multiple_concat(____BAH_COMPILER_VAR_364, 3);char * evalsTMPDecl = ____BAH_COMPILER_VAR_365;
register long int i = 0;
for (; (i<len(compilerState.evals)); ++i) {
char * e = compilerState.evals->data[i];
char** ____BAH_COMPILER_VAR_366 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_366[4] = "\n        }";____BAH_COMPILER_VAR_366[3] = e;____BAH_COMPILER_VAR_366[2] = "\",\n            .evalFn = __Bah_eval_";____BAH_COMPILER_VAR_366[1] = e;____BAH_COMPILER_VAR_366[0] = "{\n            .name = \"";char * ____BAH_COMPILER_VAR_367 =__Bah_multiple_concat(____BAH_COMPILER_VAR_366, 5);char** ____BAH_COMPILER_VAR_368 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_368[1] = ____BAH_COMPILER_VAR_367;____BAH_COMPILER_VAR_368[0] = evalsTMPDecl;char * ____BAH_COMPILER_VAR_369 =__Bah_multiple_concat(____BAH_COMPILER_VAR_368, 2);evalsTMPDecl = ____BAH_COMPILER_VAR_369;
if ((i+1!=len(compilerState.evals))) {
char** ____BAH_COMPILER_VAR_370 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_370[1] = ",\n";____BAH_COMPILER_VAR_370[0] = evalsTMPDecl;char * ____BAH_COMPILER_VAR_371 =__Bah_multiple_concat(____BAH_COMPILER_VAR_370, 2);evalsTMPDecl = ____BAH_COMPILER_VAR_371;
}
else {
char** ____BAH_COMPILER_VAR_372 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_372[1] = "};";____BAH_COMPILER_VAR_372[0] = evalsTMPDecl;char * ____BAH_COMPILER_VAR_373 =__Bah_multiple_concat(____BAH_COMPILER_VAR_372, 2);evalsTMPDecl = ____BAH_COMPILER_VAR_373;
}
};
if ((len(compilerState.evals)!=0)) {
char** ____BAH_COMPILER_VAR_374 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_374[2] = ";";____BAH_COMPILER_VAR_374[1] = intToStr(len(compilerState.evals));____BAH_COMPILER_VAR_374[0] = "__evals_bindings = __tmp__evals_bindings; __evals_length = ";char * ____BAH_COMPILER_VAR_375 =__Bah_multiple_concat(____BAH_COMPILER_VAR_374, 3);evals = ____BAH_COMPILER_VAR_375;
}
else {
evalsTMPDecl = "";
}
char** ____BAH_COMPILER_VAR_376 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_376[4] = "() {\n        ";____BAH_COMPILER_VAR_376[3] = name;____BAH_COMPILER_VAR_376[2] = "\n    void __attribute__((optimize(\"O0\"))) ";____BAH_COMPILER_VAR_376[1] = evalsTMPDecl;____BAH_COMPILER_VAR_376[0] = "\n    ";char * ____BAH_COMPILER_VAR_377 =__Bah_multiple_concat(____BAH_COMPILER_VAR_376, 5);char** ____BAH_COMPILER_VAR_378 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_378[2] = "\n    };\n    ";____BAH_COMPILER_VAR_378[1] = evals;____BAH_COMPILER_VAR_378[0] = "\n        ";char * ____BAH_COMPILER_VAR_379 =__Bah_multiple_concat(____BAH_COMPILER_VAR_378, 3);OUTPUT = rope__add(OUTPUT, rope__add(rope(____BAH_COMPILER_VAR_377), rope__add(INIT, rope(____BAH_COMPILER_VAR_379))));
};
char checkedNull(char * v,struct Elems* elems){
for (; (elems!=null); elems = elems->parent) {
register long int i = 0;
for (; (i<len(elems->branchChecks)); ++i) {
struct varCheck bc = elems->branchChecks->data[i];
if ((bc.v==null)) {
continue;
}
if ((strcmp(bc.v->name, v) == 0)) {
return bc.checkNull;
}
};
i = 0;
for (; (i<len(currChecks)); ++i) {
struct varCheck bc = currChecks->data[i];
if ((bc.v==null)) {
continue;
}
if ((strcmp(bc.v->name, v) == 0)) {
return bc.checkNull;
}
};
};
return false;
};
char checkedNotNull(char * v,struct Elems* elems){
for (; (elems!=null); elems = elems->parent) {
register long int i = 0;
for (; (i<len(elems->branchChecks)); ++i) {
struct varCheck bc = elems->branchChecks->data[i];
if ((bc.v==null)) {
continue;
}
if ((strcmp(bc.v->name, v) == 0)) {
return (bc.checkNull==false);
}
};
i = 0;
for (; (i<len(currChecks)); ++i) {
struct varCheck bc = currChecks->data[i];
if ((bc.v==null)) {
continue;
}
if ((strcmp(bc.v->name, v) == 0)) {
return (bc.checkNull==false);
}
};
};
return false;
};
char canChangeNullState(struct variable* v,struct Elems* elems){
if ((v->declScope==elems)) {
return true;
}
return checkedNull(v->name,elems);
};
char isOutterScope(void * ce,struct Elems* e){
while ((e!=null)) {
if ((ce==e)) {
return true;
}
e = e->parent;
};
return false;
};
struct rope* decrVar(struct variable* v,struct Elems* elems){
struct rope* r = rope("");
if (strHasPrefix(v->type,"[]")) {
char** ____BAH_COMPILER_VAR_380 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_380[2] = ");\n";____BAH_COMPILER_VAR_380[1] = v->name;____BAH_COMPILER_VAR_380[0] = "RCP_decr(";char * ____BAH_COMPILER_VAR_381 =__Bah_multiple_concat(____BAH_COMPILER_VAR_380, 3);r = rope__add(r, rope(____BAH_COMPILER_VAR_381));
}
else if (strHasPrefix(v->type,"chan:")) {
char** ____BAH_COMPILER_VAR_382 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_382[2] = ");\n";____BAH_COMPILER_VAR_382[1] = v->name;____BAH_COMPILER_VAR_382[0] = "RCP_decr(";char * ____BAH_COMPILER_VAR_383 =__Bah_multiple_concat(____BAH_COMPILER_VAR_382, 3);r = rope__add(r, rope(____BAH_COMPILER_VAR_383));
}
else {
if (strHasPrefix(v->type,"map:")) {
struct variable* ____BAH_COMPILER_VAR_384 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_384->name = "";
____BAH_COMPILER_VAR_384->type = "";
____BAH_COMPILER_VAR_384->constVal = "";
____BAH_COMPILER_VAR_384->from = "";
struct variable* nv = ____BAH_COMPILER_VAR_384;
*nv = *v;
v = nv;
v->type = "mapWrapper*";
}
char isPointer = isRCPpointerType(v->type);
struct cStruct* s = searchStruct(v->type,elems);
if ((s!=null)&&(s->isBinding==false)) {
if ((isPointer==true)) {
char** ____BAH_COMPILER_VAR_385 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_385[2] = ");\n";____BAH_COMPILER_VAR_385[1] = v->name;____BAH_COMPILER_VAR_385[0] = "RCP_decr(";char * ____BAH_COMPILER_VAR_386 =__Bah_multiple_concat(____BAH_COMPILER_VAR_385, 3);r = rope__add(r, rope(____BAH_COMPILER_VAR_386));
}
else {
char** ____BAH_COMPILER_VAR_387 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_387[4] = "), 1);\n";____BAH_COMPILER_VAR_387[3] = v->name;____BAH_COMPILER_VAR_387[2] = ", sizeof(";____BAH_COMPILER_VAR_387[1] = v->name;____BAH_COMPILER_VAR_387[0] = "RCP_scanStack(&";char * ____BAH_COMPILER_VAR_388 =__Bah_multiple_concat(____BAH_COMPILER_VAR_387, 5);r = rope__add(r, rope(____BAH_COMPILER_VAR_388));
}
}
else if ((isPointer==true)) {
char** ____BAH_COMPILER_VAR_389 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_389[2] = ");\n";____BAH_COMPILER_VAR_389[1] = v->name;____BAH_COMPILER_VAR_389[0] = "RCP_decr(";char * ____BAH_COMPILER_VAR_390 =__Bah_multiple_concat(____BAH_COMPILER_VAR_389, 3);r = rope__add(r, rope(____BAH_COMPILER_VAR_390));
}
}
return r;
};
struct rope* incrVar(struct variable* v,struct Elems* elems){
if ((strCount(v->name,"*")>0)) {
return rope("");
}
struct cStruct* s = searchStruct(v->type,elems);
if ((s!=null)&&(isRCPpointerType(v->type)==false)&&(s->isBinding==false)) {
char** ____BAH_COMPILER_VAR_391 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_391[4] = "), 0);";____BAH_COMPILER_VAR_391[3] = v->name;____BAH_COMPILER_VAR_391[2] = ", sizeof(";____BAH_COMPILER_VAR_391[1] = v->name;____BAH_COMPILER_VAR_391[0] = "RCP_scanStack(&";char * ____BAH_COMPILER_VAR_392 =__Bah_multiple_concat(____BAH_COMPILER_VAR_391, 5);return rope(____BAH_COMPILER_VAR_392);
}
char** ____BAH_COMPILER_VAR_393 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_393[2] = ");";____BAH_COMPILER_VAR_393[1] = v->name;____BAH_COMPILER_VAR_393[0] = "RCP_incr(";char * ____BAH_COMPILER_VAR_394 =__Bah_multiple_concat(____BAH_COMPILER_VAR_393, 3);return rope(____BAH_COMPILER_VAR_394);
};
char RCPavailable(){
return (RCPenabled==true);
};
void beginRCPscope(struct Elems* elems,__BAH_ARR_TYPE_variable excl){
if ((RCPavailable()==false)) {
return;
}
register long int i = 0;
for (; (i<len(elems->vars)); ++i) {
struct variable* v = elems->vars->data[i];
if (varInArr(v,excl)) {
continue;
}
if ((v->isGlobal==false)&&isRCPtype(v->type,elems)) {
OUTPUT = rope__add(OUTPUT, incrVar(v,elems));
}
};
};
void beginRCPscopeLeaky(struct Elems* elems){
if ((RCPavailable()==false)) {
return;
}
register long int i = 0;
for (; (i<len(elems->vars)); ++i) {
struct variable* v = elems->vars->data[i];
if ((v->isGlobal==false)&&(v->declScope==elems)&&isRCPtype(v->type,elems)) {
OUTPUT = rope__add(OUTPUT, incrVar(v,elems));
}
};
};
void removeDefs(struct Elems* elems){
register long int i = 0;
for (; (i<len(elems->defined)); ++i) {
char** ____BAH_COMPILER_VAR_395 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_395[2] = "\n";____BAH_COMPILER_VAR_395[1] = elems->defined->data[i];____BAH_COMPILER_VAR_395[0] = "\n#undef ";char * ____BAH_COMPILER_VAR_396 =__Bah_multiple_concat(____BAH_COMPILER_VAR_395, 3);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_396));
};
};
void endRCPscope(struct Elems* elems,__BAH_ARR_TYPE_variable excl){
if ((RCPavailable()==false)) {
removeDefs(elems);
return;
}
register long int i = 0;
for (; (i<len(elems->vars)); ++i) {
struct variable* v = elems->vars->data[i];
if (varInArr(v,excl)) {
continue;
}
if ((v->isGlobal==false)&&isRCPtype(v->type,elems)) {
OUTPUT = rope__add(OUTPUT, decrVar(v,elems));
}
};
removeDefs(elems);
};
void endRCPscopeLeaky(struct Elems* elems,struct variable* excl,char undef){
if ((RCPavailable()==false)) {
if ((undef==true)) {
removeDefs(elems);
}
return;
}
register long int i = 0;
for (; (i<len(elems->vars)); ++i) {
struct variable* v = elems->vars->data[i];
if ((excl!=null)&&(strcmp(excl->name, v->name) == 0)) {
continue;
}
if ((v->isGlobal==false)&&(v->declScope==elems)&&isRCPtype(v->type,elems)) {
OUTPUT = rope__add(OUTPUT, decrVar(v,elems));
}
};
if ((undef==true)) {
removeDefs(elems);
}
};
char * registerRCPvar(char * t,char * c,struct Elems* elems){
struct variable* ____BAH_COMPILER_VAR_397 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_397->name = "";
____BAH_COMPILER_VAR_397->type = "";
____BAH_COMPILER_VAR_397->constVal = "";
____BAH_COMPILER_VAR_397->from = "";
struct variable* av = ____BAH_COMPILER_VAR_397;
av->type = t;
av->declScope = elems;
av->name = genCompilerVar();

    unsigned int ____BAH_COMPILER_VAR_398 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_398);
    elems->vars->data[____BAH_COMPILER_VAR_398] = av;
struct string cType = getCType(av->type,elems);
char** ____BAH_COMPILER_VAR_399 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_399[5] = ";";____BAH_COMPILER_VAR_399[4] = c;____BAH_COMPILER_VAR_399[3] = " =";____BAH_COMPILER_VAR_399[2] = av->name;____BAH_COMPILER_VAR_399[1] = " ";____BAH_COMPILER_VAR_399[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_400 =__Bah_multiple_concat(____BAH_COMPILER_VAR_399, 6);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_400));
return av->name;
};
char RCPselfRef(struct variable* v){
register long int i = 0;
while ((i<len(compilerState.RCPvars))) {
struct variable* r = compilerState.RCPvars->data[i];
if ((strcmp(r->name, v->name) == 0)) {
return true;
}
i = i+1;
};
return false;
};
#define ASCII_RESET "\\033[0m"
#define ASCII_YELLOW "\\033[33m"
#define ASCII_BLUE "\\033[36m"
#define ASCII_GREEN "\\033[32m"
#define ASCII_MAGENTA "\\033[35m"
#define ASCII_GREY "\\033[2m"
struct verboseOutVar {
char * markup;
char * content;
};
array(char *)* noVOfns;
char verboseOutGuard(){
if ((currentFn!=null)) {

        char ____BAH_COMPILER_VAR_401 = 0;
        for(int i=noVOfns->length-1; i!=-1;i--) {
            if (noVOfns->data[i] != 0 && strcmp(noVOfns->data[i], currentFn->name) == 0) {
                ____BAH_COMPILER_VAR_401=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_401) {
return false;
}
}
return true;
};
struct verboseOutVar verboseOutTransformVar(struct variable* v,char * cont,struct Elems* elems){
struct verboseOutVar ____BAH_COMPILER_VAR_402 = {};
#define rv ____BAH_COMPILER_VAR_402
char * ogCont = cont;
if ((strcmp(v->type, "cpstring") == 0)) {
char** ____BAH_COMPILER_VAR_403 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_403[2] = ")";____BAH_COMPILER_VAR_403[1] = cont;____BAH_COMPILER_VAR_403[0] = "__Bah_safe_string(";char * ____BAH_COMPILER_VAR_404 =__Bah_multiple_concat(____BAH_COMPILER_VAR_403, 3);cont = ____BAH_COMPILER_VAR_404;
}
char** ____BAH_COMPILER_VAR_405 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_405[1] = cont;____BAH_COMPILER_VAR_405[0] = ", ";char * ____BAH_COMPILER_VAR_406 =__Bah_multiple_concat(____BAH_COMPILER_VAR_405, 2);cont = ____BAH_COMPILER_VAR_406;
char * ct = "";
if ((strcmp(v->type, "cpstring") == 0)) {
ct = "%s";
}
else if ((strcmp(v->type, "int") == 0)) {
ct = "%li";
}
else if ((strcmp(v->type, "float") == 0)) {
ct = "%d";
}
else if ((isRCPpointerType(v->type)==true)) {
ct = "%p";
}
else {
struct cStruct* s = searchStruct(v->type,elems);
if ((s==null)) {
ct = "%li";
}
else {
char** ____BAH_COMPILER_VAR_407 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_407[1] = "{";____BAH_COMPILER_VAR_407[0] = ASCII_RESET;char * ____BAH_COMPILER_VAR_408 =__Bah_multiple_concat(____BAH_COMPILER_VAR_407, 2);ct = ____BAH_COMPILER_VAR_408;
cont = "";
register long int i = 0;
for (; (i<len(s->members)); ++i) {
struct variable* m = s->members->data[i];
char** ____BAH_COMPILER_VAR_409 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_409[4] = m->name;____BAH_COMPILER_VAR_409[3] = ".";____BAH_COMPILER_VAR_409[2] = ")";____BAH_COMPILER_VAR_409[1] = ogCont;____BAH_COMPILER_VAR_409[0] = "(";char * ____BAH_COMPILER_VAR_410 =__Bah_multiple_concat(____BAH_COMPILER_VAR_409, 5);struct verboseOutVar mv = verboseOutTransformVar(m,____BAH_COMPILER_VAR_410,elems);
if ((i!=0)) {
char** ____BAH_COMPILER_VAR_411 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_411[1] = ", ";____BAH_COMPILER_VAR_411[0] = ct;char * ____BAH_COMPILER_VAR_412 =__Bah_multiple_concat(____BAH_COMPILER_VAR_411, 2);ct = ____BAH_COMPILER_VAR_412;
}
char** ____BAH_COMPILER_VAR_413 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_413[1] = mv.markup;____BAH_COMPILER_VAR_413[0] = ct;char * ____BAH_COMPILER_VAR_414 =__Bah_multiple_concat(____BAH_COMPILER_VAR_413, 2);ct = ____BAH_COMPILER_VAR_414;
char** ____BAH_COMPILER_VAR_415 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_415[1] = mv.content;____BAH_COMPILER_VAR_415[0] = cont;char * ____BAH_COMPILER_VAR_416 =__Bah_multiple_concat(____BAH_COMPILER_VAR_415, 2);cont = ____BAH_COMPILER_VAR_416;
};
char** ____BAH_COMPILER_VAR_417 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_417[1] = "}";____BAH_COMPILER_VAR_417[0] = ct;char * ____BAH_COMPILER_VAR_418 =__Bah_multiple_concat(____BAH_COMPILER_VAR_417, 2);ct = ____BAH_COMPILER_VAR_418;
}
}
char** ____BAH_COMPILER_VAR_419 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_419[6] = ASCII_RESET;____BAH_COMPILER_VAR_419[5] = ct;____BAH_COMPILER_VAR_419[4] = ASCII_MAGENTA;____BAH_COMPILER_VAR_419[3] = " = ";____BAH_COMPILER_VAR_419[2] = ASCII_RESET;____BAH_COMPILER_VAR_419[1] = v->name;____BAH_COMPILER_VAR_419[0] = ASCII_BLUE;char * ____BAH_COMPILER_VAR_420 =__Bah_multiple_concat(____BAH_COMPILER_VAR_419, 7);rv.markup = ____BAH_COMPILER_VAR_420;
rv.content = cont;
return rv;

#undef rv
};
struct verboseOutVar verboseOutTransformTok(struct Tok* t,struct Elems* elems){
if ((t->type==TOKEN_TYPE_VAR)&&(t->isOper==false)) {
struct variable* v = searchVar(t->cont,elems);
if ((v==null)) {
struct verboseOutVar ____BAH_COMPILER_VAR_421 = {};
#define rv ____BAH_COMPILER_VAR_421
return rv;

#undef rv
}
}
struct variable ____BAH_COMPILER_VAR_422 = {};
____BAH_COMPILER_VAR_422.name = "";
____BAH_COMPILER_VAR_422.type = "";
____BAH_COMPILER_VAR_422.constVal = "";
____BAH_COMPILER_VAR_422.from = "";
____BAH_COMPILER_VAR_422.name = "(value)";
____BAH_COMPILER_VAR_422.type = getTypeFromToken(t,true,elems);
#define v ____BAH_COMPILER_VAR_422
return verboseOutTransformVar(&v,t->cont,elems);

#undef v
};
void verboseOutFunc(struct func* fn,__BAH_ARR_TYPE_Tok args,long int lineNb,struct Elems* elems){
if ((verboseOutGuard()==false)) {
return;
}
char * nameColor = ASCII_YELLOW;
if ((fn->isBinding==true)) {
if (strHasPrefix(compilerState.currentFile,BAH_DIR)) {
return;
}
nameColor = ASCII_GREY;
}
if (strHasPrefix(fn->file,BAH_DIR)) {
char hasPtr = false;
register long int i = 0;
for (; (i<len(fn->args)); ++i) {
struct variable* a = fn->args->data[i];
if ((isRCPpointerType(a->type)==true)) {
hasPtr = true;
break;
}
};
if ((hasPtr==false)) {
return;
}
}
char * fnArgs = "";
char * fnArgsValues = "";
register long int j = 0;
for (; (j<len(fn->args)); ++j) {
struct variable* a = fn->args->data[j];
if ((j!=0)) {
char** ____BAH_COMPILER_VAR_423 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_423[1] = ", ";____BAH_COMPILER_VAR_423[0] = fnArgs;char * ____BAH_COMPILER_VAR_424 =__Bah_multiple_concat(____BAH_COMPILER_VAR_423, 2);fnArgs = ____BAH_COMPILER_VAR_424;
}
struct Tok t = args->data[j];
struct verboseOutVar v = verboseOutTransformVar(a,t.cont,elems);
char** ____BAH_COMPILER_VAR_425 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_425[1] = v.markup;____BAH_COMPILER_VAR_425[0] = fnArgs;char * ____BAH_COMPILER_VAR_426 =__Bah_multiple_concat(____BAH_COMPILER_VAR_425, 2);fnArgs = ____BAH_COMPILER_VAR_426;
char** ____BAH_COMPILER_VAR_427 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_427[1] = v.content;____BAH_COMPILER_VAR_427[0] = fnArgsValues;char * ____BAH_COMPILER_VAR_428 =__Bah_multiple_concat(____BAH_COMPILER_VAR_427, 2);fnArgsValues = ____BAH_COMPILER_VAR_428;
};
char** ____BAH_COMPILER_VAR_429 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_429[2] = intToStr(lineNb);____BAH_COMPILER_VAR_429[1] = ":";____BAH_COMPILER_VAR_429[0] = compilerState.currentFile;char * ____BAH_COMPILER_VAR_430 =__Bah_multiple_concat(____BAH_COMPILER_VAR_429, 3);char * line = ____BAH_COMPILER_VAR_430;
char** ____BAH_COMPILER_VAR_431 = alloca(13 * sizeof(char*));____BAH_COMPILER_VAR_431[12] = ");\n    //\n    ";____BAH_COMPILER_VAR_431[11] = fnArgsValues;____BAH_COMPILER_VAR_431[10] = "\\n\"";____BAH_COMPILER_VAR_431[9] = ASCII_RESET;____BAH_COMPILER_VAR_431[8] = line;____BAH_COMPILER_VAR_431[7] = ASCII_GREEN;____BAH_COMPILER_VAR_431[6] = ") -> ";____BAH_COMPILER_VAR_431[5] = fnArgs;____BAH_COMPILER_VAR_431[4] = "(";____BAH_COMPILER_VAR_431[3] = ASCII_RESET;____BAH_COMPILER_VAR_431[2] = fn->name;____BAH_COMPILER_VAR_431[1] = nameColor;____BAH_COMPILER_VAR_431[0] = "\n    //Verbose Runtime\n        printf(\"[VO] calling: ";char * ____BAH_COMPILER_VAR_432 =__Bah_multiple_concat(____BAH_COMPILER_VAR_431, 13);struct rope* verboseOut = rope(____BAH_COMPILER_VAR_432);
if (isGlobal()) {
INIT = rope__add(INIT, verboseOut);
}
else {
OUTPUT = rope__add(OUTPUT, verboseOut);
}
};
void verboseOutOper(struct Tok* pt,struct Tok* nt,long int lineNb,struct Elems* elems){
if ((verboseOutGuard()==false)) {
return;
}
struct verboseOutVar pvo = verboseOutTransformTok(pt,elems);
struct verboseOutVar nvo = verboseOutTransformTok(nt,elems);
char** ____BAH_COMPILER_VAR_433 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_433[1] = nvo.content;____BAH_COMPILER_VAR_433[0] = pvo.content;char * ____BAH_COMPILER_VAR_434 =__Bah_multiple_concat(____BAH_COMPILER_VAR_433, 2);char * values = ____BAH_COMPILER_VAR_434;
char** ____BAH_COMPILER_VAR_435 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_435[2] = intToStr(lineNb);____BAH_COMPILER_VAR_435[1] = ":";____BAH_COMPILER_VAR_435[0] = compilerState.currentFile;char * ____BAH_COMPILER_VAR_436 =__Bah_multiple_concat(____BAH_COMPILER_VAR_435, 3);char * line = ____BAH_COMPILER_VAR_436;
char** ____BAH_COMPILER_VAR_437 = alloca(11 * sizeof(char*));____BAH_COMPILER_VAR_437[10] = ");\n    //\n    ";____BAH_COMPILER_VAR_437[9] = values;____BAH_COMPILER_VAR_437[8] = "\\n\"";____BAH_COMPILER_VAR_437[7] = ASCII_RESET;____BAH_COMPILER_VAR_437[6] = line;____BAH_COMPILER_VAR_437[5] = ASCII_GREEN;____BAH_COMPILER_VAR_437[4] = " -> ";____BAH_COMPILER_VAR_437[3] = nvo.markup;____BAH_COMPILER_VAR_437[2] = " AND ";____BAH_COMPILER_VAR_437[1] = pvo.markup;____BAH_COMPILER_VAR_437[0] = "\n    //Verbose Runtime\n        printf(\"[VO]    oper: ";char * ____BAH_COMPILER_VAR_438 =__Bah_multiple_concat(____BAH_COMPILER_VAR_437, 11);struct rope* verboseOut = rope(____BAH_COMPILER_VAR_438);
if (isGlobal()) {
INIT = rope__add(INIT, verboseOut);
}
else {
OUTPUT = rope__add(OUTPUT, verboseOut);
}
};
struct cacheFile {
char * file;
long int last;
char * ver;
long int date;
long int mem;
long int opti;
array(char *)* files;
};
array(struct cacheFile*)* cache;
void readCache(){
struct fileStream ____BAH_COMPILER_VAR_439 = {};
#define fs ____BAH_COMPILER_VAR_439
char** ____BAH_COMPILER_VAR_440 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_440[1] = "cache/cache.json";____BAH_COMPILER_VAR_440[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_441 =__Bah_multiple_concat(____BAH_COMPILER_VAR_440, 2);fileStream__open(&fs,____BAH_COMPILER_VAR_441,"r");
if ((fileStream__isValid(&fs)==0)||(fileStream__getSize(&fs)==0)) {
char** ____BAH_COMPILER_VAR_442 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_442[1] = "cache";____BAH_COMPILER_VAR_442[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_443 =__Bah_multiple_concat(____BAH_COMPILER_VAR_442, 2);mkdir(____BAH_COMPILER_VAR_443,S_IRWXU);
char** ____BAH_COMPILER_VAR_444 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_444[1] = "cache/cache.json";____BAH_COMPILER_VAR_444[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_445 =__Bah_multiple_concat(____BAH_COMPILER_VAR_444, 2);fileStream__createFile(&fs,____BAH_COMPILER_VAR_445);
return;
}
if ((fileStream__getSize(&fs)>0)) {
char * ____BAH_COMPILER_VAR_446 =fileStream__readContent(&fs);struct jsonElement* j = parseJson(____BAH_COMPILER_VAR_446);
fileStream__close(&fs);
array(struct cacheFile**)* ____BAH_COMPILER_VAR_447 = &cache;
struct cacheFile*** ____BAH_COMPILER_VAR_448 = 0;
char ** ____BAH_COMPILER_VAR_450 = (char **)((char*)(____BAH_COMPILER_VAR_448) + offsetof(struct cacheFile, file));
struct reflectElement ____BAH_COMPILER_VAR_451 = __reflect(____BAH_COMPILER_VAR_450, sizeof(char *), "cpstring", "file", 0, 0, 0, 0, offsetof(struct cacheFile, file));
long int* ____BAH_COMPILER_VAR_452 = (long int*)((char*)(____BAH_COMPILER_VAR_448) + offsetof(struct cacheFile, last));
struct reflectElement ____BAH_COMPILER_VAR_453 = __reflect(____BAH_COMPILER_VAR_452, sizeof(long int), "int", "last", 0, 0, 0, 0, offsetof(struct cacheFile, last));
char ** ____BAH_COMPILER_VAR_454 = (char **)((char*)(____BAH_COMPILER_VAR_448) + offsetof(struct cacheFile, ver));
struct reflectElement ____BAH_COMPILER_VAR_455 = __reflect(____BAH_COMPILER_VAR_454, sizeof(char *), "cpstring", "ver", 0, 0, 0, 0, offsetof(struct cacheFile, ver));
long int* ____BAH_COMPILER_VAR_456 = (long int*)((char*)(____BAH_COMPILER_VAR_448) + offsetof(struct cacheFile, date));
struct reflectElement ____BAH_COMPILER_VAR_457 = __reflect(____BAH_COMPILER_VAR_456, sizeof(long int), "int", "date", 0, 0, 0, 0, offsetof(struct cacheFile, date));
long int* ____BAH_COMPILER_VAR_458 = (long int*)((char*)(____BAH_COMPILER_VAR_448) + offsetof(struct cacheFile, mem));
struct reflectElement ____BAH_COMPILER_VAR_459 = __reflect(____BAH_COMPILER_VAR_458, sizeof(long int), "int", "mem", 0, 0, 0, 0, offsetof(struct cacheFile, mem));
long int* ____BAH_COMPILER_VAR_460 = (long int*)((char*)(____BAH_COMPILER_VAR_448) + offsetof(struct cacheFile, opti));
struct reflectElement ____BAH_COMPILER_VAR_461 = __reflect(____BAH_COMPILER_VAR_460, sizeof(long int), "int", "opti", 0, 0, 0, 0, offsetof(struct cacheFile, opti));
array(char *)** ____BAH_COMPILER_VAR_462 = (array(char *)**)((char*)(____BAH_COMPILER_VAR_448) + offsetof(struct cacheFile, files));
char ** ____BAH_COMPILER_VAR_463 = 0;
struct reflectElement ____BAH_COMPILER_VAR_464 = __reflect(____BAH_COMPILER_VAR_463, sizeof(char *), "cpstring", "", 0, 0, 0, 0, 0);

        struct reflectElement ____BAH_COMPILER_VAR_465 = ____BAH_COMPILER_VAR_464;
        struct reflectElement ____BAH_COMPILER_VAR_466 = __reflect(____BAH_COMPILER_VAR_462, sizeof(array(char *)*), "[]cpstring", "files", 1, &____BAH_COMPILER_VAR_465, 0, 0, offsetof(struct cacheFile, files));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_449 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_449->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_449->length = 7;
        ____BAH_COMPILER_VAR_449->data = memoryAlloc(____BAH_COMPILER_VAR_449->length * ____BAH_COMPILER_VAR_449->elemSize);
        ____BAH_COMPILER_VAR_449->data[0] = ____BAH_COMPILER_VAR_451;
____BAH_COMPILER_VAR_449->data[1] = ____BAH_COMPILER_VAR_453;
____BAH_COMPILER_VAR_449->data[2] = ____BAH_COMPILER_VAR_455;
____BAH_COMPILER_VAR_449->data[3] = ____BAH_COMPILER_VAR_457;
____BAH_COMPILER_VAR_449->data[4] = ____BAH_COMPILER_VAR_459;
____BAH_COMPILER_VAR_449->data[5] = ____BAH_COMPILER_VAR_461;
____BAH_COMPILER_VAR_449->data[6] = ____BAH_COMPILER_VAR_466;
struct reflectElement ____BAH_COMPILER_VAR_467 = __reflect(____BAH_COMPILER_VAR_448, sizeof(struct cacheFile), "cacheFile**", "", 0, 0, 1, ____BAH_COMPILER_VAR_449, 0);

        struct reflectElement ____BAH_COMPILER_VAR_468 = ____BAH_COMPILER_VAR_467;
        struct reflectElement ____BAH_COMPILER_VAR_469 = __reflect(____BAH_COMPILER_VAR_447, sizeof(array(struct cacheFile**)*), "[]cacheFile**", "&cache", 1, &____BAH_COMPILER_VAR_468, 0, 0, 0);
jsonElement__scan(j,____BAH_COMPILER_VAR_469);
}

#undef fs
};
struct cacheFile* getCacheFile(char * s){
if ((cache==null)) {
return null;
}
register long int i = 0;
for (; (i<len(cache)); ++i) {
struct cacheFile* c = cache->data[i];
if ((strcmp(c->file, s) == 0)&&(c->mem==RCPlevel)&&(c->opti==isOptimized)) {
return c;
}
};
return null;
};
void updateCacheFile(struct cacheFile* c){
c->last = getLastModified(c->file);
c->ver = BAH_VERSION;
c->date = getTimeUnix();
};
void makeCacheFile(char * f){
struct cacheFile* ____BAH_COMPILER_VAR_470 = memoryAlloc(sizeof(struct cacheFile));
____BAH_COMPILER_VAR_470->files = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_470->files->length = 0;
            ____BAH_COMPILER_VAR_470->files->elemSize = sizeof(char *);
            struct cacheFile* c = ____BAH_COMPILER_VAR_470;
c->file = f;
c->ver = BAH_VERSION;
c->mem = RCPlevel;
c->opti = isOptimized;
c->date = getTimeUnix();
c->last = getLastModified(f);
if ((cache==null)) {
cache = memoryAlloc(sizeof(array(struct cacheFile*)));

cache->length = 0;
cache->elemSize = sizeof(struct cacheFile*);
}

    unsigned int ____BAH_COMPILER_VAR_471 = len(cache);
    __Bah_realocate_arr(cache, ____BAH_COMPILER_VAR_471);
    cache->data[____BAH_COMPILER_VAR_471] = c;
};
void writeCache(){
struct fileStream ____BAH_COMPILER_VAR_472 = {};
#define fs ____BAH_COMPILER_VAR_472
char** ____BAH_COMPILER_VAR_473 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_473[1] = "cache/cache.json";____BAH_COMPILER_VAR_473[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_474 =__Bah_multiple_concat(____BAH_COMPILER_VAR_473, 2);fileStream__open(&fs,____BAH_COMPILER_VAR_474,"w");
array(struct cacheFile*)* ____BAH_COMPILER_VAR_475 = cache;
struct cacheFile** ____BAH_COMPILER_VAR_476 = 0;
char ** ____BAH_COMPILER_VAR_478 = (char **)((char*)(____BAH_COMPILER_VAR_476) + offsetof(struct cacheFile, file));
struct reflectElement ____BAH_COMPILER_VAR_479 = __reflect(____BAH_COMPILER_VAR_478, sizeof(char *), "cpstring", "file", 0, 0, 0, 0, offsetof(struct cacheFile, file));
long int* ____BAH_COMPILER_VAR_480 = (long int*)((char*)(____BAH_COMPILER_VAR_476) + offsetof(struct cacheFile, last));
struct reflectElement ____BAH_COMPILER_VAR_481 = __reflect(____BAH_COMPILER_VAR_480, sizeof(long int), "int", "last", 0, 0, 0, 0, offsetof(struct cacheFile, last));
char ** ____BAH_COMPILER_VAR_482 = (char **)((char*)(____BAH_COMPILER_VAR_476) + offsetof(struct cacheFile, ver));
struct reflectElement ____BAH_COMPILER_VAR_483 = __reflect(____BAH_COMPILER_VAR_482, sizeof(char *), "cpstring", "ver", 0, 0, 0, 0, offsetof(struct cacheFile, ver));
long int* ____BAH_COMPILER_VAR_484 = (long int*)((char*)(____BAH_COMPILER_VAR_476) + offsetof(struct cacheFile, date));
struct reflectElement ____BAH_COMPILER_VAR_485 = __reflect(____BAH_COMPILER_VAR_484, sizeof(long int), "int", "date", 0, 0, 0, 0, offsetof(struct cacheFile, date));
long int* ____BAH_COMPILER_VAR_486 = (long int*)((char*)(____BAH_COMPILER_VAR_476) + offsetof(struct cacheFile, mem));
struct reflectElement ____BAH_COMPILER_VAR_487 = __reflect(____BAH_COMPILER_VAR_486, sizeof(long int), "int", "mem", 0, 0, 0, 0, offsetof(struct cacheFile, mem));
long int* ____BAH_COMPILER_VAR_488 = (long int*)((char*)(____BAH_COMPILER_VAR_476) + offsetof(struct cacheFile, opti));
struct reflectElement ____BAH_COMPILER_VAR_489 = __reflect(____BAH_COMPILER_VAR_488, sizeof(long int), "int", "opti", 0, 0, 0, 0, offsetof(struct cacheFile, opti));
array(char *)** ____BAH_COMPILER_VAR_490 = (array(char *)**)((char*)(____BAH_COMPILER_VAR_476) + offsetof(struct cacheFile, files));
char ** ____BAH_COMPILER_VAR_491 = 0;
struct reflectElement ____BAH_COMPILER_VAR_492 = __reflect(____BAH_COMPILER_VAR_491, sizeof(char *), "cpstring", "", 0, 0, 0, 0, 0);

        struct reflectElement ____BAH_COMPILER_VAR_493 = ____BAH_COMPILER_VAR_492;
        struct reflectElement ____BAH_COMPILER_VAR_494 = __reflect(____BAH_COMPILER_VAR_490, sizeof(array(char *)*), "[]cpstring", "files", 1, &____BAH_COMPILER_VAR_493, 0, 0, offsetof(struct cacheFile, files));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_477 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_477->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_477->length = 7;
        ____BAH_COMPILER_VAR_477->data = memoryAlloc(____BAH_COMPILER_VAR_477->length * ____BAH_COMPILER_VAR_477->elemSize);
        ____BAH_COMPILER_VAR_477->data[0] = ____BAH_COMPILER_VAR_479;
____BAH_COMPILER_VAR_477->data[1] = ____BAH_COMPILER_VAR_481;
____BAH_COMPILER_VAR_477->data[2] = ____BAH_COMPILER_VAR_483;
____BAH_COMPILER_VAR_477->data[3] = ____BAH_COMPILER_VAR_485;
____BAH_COMPILER_VAR_477->data[4] = ____BAH_COMPILER_VAR_487;
____BAH_COMPILER_VAR_477->data[5] = ____BAH_COMPILER_VAR_489;
____BAH_COMPILER_VAR_477->data[6] = ____BAH_COMPILER_VAR_494;
struct reflectElement ____BAH_COMPILER_VAR_495 = __reflect(____BAH_COMPILER_VAR_476, sizeof(struct cacheFile), "cacheFile*", "", 0, 0, 1, ____BAH_COMPILER_VAR_477, 0);

        struct reflectElement ____BAH_COMPILER_VAR_496 = ____BAH_COMPILER_VAR_495;
        struct reflectElement ____BAH_COMPILER_VAR_497 = __reflect(____BAH_COMPILER_VAR_475, sizeof(array(struct cacheFile*)*), "[]cacheFile*", "cache", 1, &____BAH_COMPILER_VAR_496, 0, 0, 0);
char * ____BAH_COMPILER_VAR_498 =toJson(____BAH_COMPILER_VAR_497);fileStream__writeFile(&fs,____BAH_COMPILER_VAR_498);
fileStream__close(&fs);

#undef fs
};
char isValidCacheFile(struct cacheFile* cf){
if ((cf==null)||(cf->last!=getLastModified(cf->file))) {
return false;
}
char** ____BAH_COMPILER_VAR_499 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_499[5] = ".o.o";____BAH_COMPILER_VAR_499[4] = intToStr(cf->opti);____BAH_COMPILER_VAR_499[3] = intToStr(cf->mem);____BAH_COMPILER_VAR_499[2] = pathToVarName(cf->file);____BAH_COMPILER_VAR_499[1] = "cache/";____BAH_COMPILER_VAR_499[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_500 =__Bah_multiple_concat(____BAH_COMPILER_VAR_499, 6);if ((fileExists(____BAH_COMPILER_VAR_500)==0)) {
return false;
}
if ((strcmp(cf->ver, BAH_VERSION) != 0)) {
return false;
}
return true;
};
char * genArrRealloc(struct variable* v,char * preVal,char * val,struct Elems* elems){
struct string vn = string(v->name);
char * nstr = splitStringBefore(vn,"->data[");
string__trimLeft(&vn,strlen(nstr)+7);
string__trimRight(&vn,1);
char * nLengthStr = string__str(&vn);
char * nLength = genCompilerVar();
char** ____BAH_COMPILER_VAR_501 = alloca(15 * sizeof(char*));____BAH_COMPILER_VAR_501[14] = val;____BAH_COMPILER_VAR_501[13] = "] = ";____BAH_COMPILER_VAR_501[12] = nLength;____BAH_COMPILER_VAR_501[11] = "->data[";____BAH_COMPILER_VAR_501[10] = nstr;____BAH_COMPILER_VAR_501[9] = preVal;____BAH_COMPILER_VAR_501[8] = ");\n    ";____BAH_COMPILER_VAR_501[7] = nLength;____BAH_COMPILER_VAR_501[6] = ", ";____BAH_COMPILER_VAR_501[5] = nstr;____BAH_COMPILER_VAR_501[4] = ";\n    __Bah_realocate_arr(";____BAH_COMPILER_VAR_501[3] = nLengthStr;____BAH_COMPILER_VAR_501[2] = " = ";____BAH_COMPILER_VAR_501[1] = nLength;____BAH_COMPILER_VAR_501[0] = "\n    unsigned int ";char * ____BAH_COMPILER_VAR_502 =__Bah_multiple_concat(____BAH_COMPILER_VAR_501, 15);return ____BAH_COMPILER_VAR_502;
};
char * genConcat(__BAH_ARR_TYPE_cpstring strs,struct Elems* elems){
char * buff = genCompilerVar();
char** ____BAH_COMPILER_VAR_503 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_503[4] = " * sizeof(char*));";____BAH_COMPILER_VAR_503[3] = intToStr(len(strs));____BAH_COMPILER_VAR_503[2] = " = alloca(";____BAH_COMPILER_VAR_503[1] = buff;____BAH_COMPILER_VAR_503[0] = "char** ";char * ____BAH_COMPILER_VAR_504 =__Bah_multiple_concat(____BAH_COMPILER_VAR_503, 5);char * r = ____BAH_COMPILER_VAR_504;
register long int i = 0;
for (; (i<len(strs)); ++i) {
char** ____BAH_COMPILER_VAR_505 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_505[5] = ";";____BAH_COMPILER_VAR_505[4] = strs->data[i];____BAH_COMPILER_VAR_505[3] = "] = ";____BAH_COMPILER_VAR_505[2] = intToStr(len(strs)-i-1);____BAH_COMPILER_VAR_505[1] = "[";____BAH_COMPILER_VAR_505[0] = buff;char * ____BAH_COMPILER_VAR_506 =__Bah_multiple_concat(____BAH_COMPILER_VAR_505, 6);char** ____BAH_COMPILER_VAR_507 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_507[1] = ____BAH_COMPILER_VAR_506;____BAH_COMPILER_VAR_507[0] = r;char * ____BAH_COMPILER_VAR_508 =__Bah_multiple_concat(____BAH_COMPILER_VAR_507, 2);r = ____BAH_COMPILER_VAR_508;
};
if (isGlobal()) {
INIT = rope__add(INIT, rope(r));
}
else {
OUTPUT = rope__add(OUTPUT, rope(r));
}
char** ____BAH_COMPILER_VAR_509 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_509[4] = ")";____BAH_COMPILER_VAR_509[3] = intToStr(len(strs));____BAH_COMPILER_VAR_509[2] = ", ";____BAH_COMPILER_VAR_509[1] = buff;____BAH_COMPILER_VAR_509[0] = "__Bah_multiple_concat(";char * ____BAH_COMPILER_VAR_510 =__Bah_multiple_concat(____BAH_COMPILER_VAR_509, 5);char * rstr = registerRCPvar("cpstring",____BAH_COMPILER_VAR_510,elems);
return rstr;
};
void OPTI_checkFuncScopeRef(struct Elems* elems){
if ((strHasPrefix(compilerState.currentFile,BAH_DIR)==true)) {
return;
}
register long int i = 0;
for (; (i<len(elems->vars)); ++i) {
struct variable* v = elems->vars->data[i];
if ((v->isArg==false)) {
continue;
}
if ((v->lastSet!=elems)) {

                struct string ____BAH_COMPILER_VAR_511 = string(v->name);
                if ((isRCPpointerType(v->type)==false)&&(strcmp(v->type, "reflectElement") != 0)&&(string__hasPrefix(&____BAH_COMPILER_VAR_511,"____BAH_COMPILER_VAR_")==false)) {
struct cStruct* s = searchStruct(v->type,elems);
if ((s!=null)&&(currentFn!=null)) {
char** ____BAH_COMPILER_VAR_512 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_512[6] = ") could be passed by reference.";____BAH_COMPILER_VAR_512[5] = v->type;____BAH_COMPILER_VAR_512[4] = "\e[0m (";____BAH_COMPILER_VAR_512[3] = v->name;____BAH_COMPILER_VAR_512[2] = "()\e[0m: argument \e[1;37m";____BAH_COMPILER_VAR_512[1] = currentFn->name;____BAH_COMPILER_VAR_512[0] = "in \e[1;37m";char * ____BAH_COMPILER_VAR_513 =__Bah_multiple_concat(____BAH_COMPILER_VAR_512, 7);throwNoticeLine(____BAH_COMPILER_VAR_513,currentFn->line);
}
}
}
};
};
void debugLine(__BAH_ARR_TYPE_Tok line){
char * cont = "";
register long int i = 0;
while ((i<len(line))) {
struct Tok t = line->data[i];
char** ____BAH_COMPILER_VAR_514 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_514[3] = "'";____BAH_COMPILER_VAR_514[2] = t.cont;____BAH_COMPILER_VAR_514[1] = " '";____BAH_COMPILER_VAR_514[0] = cont;char * ____BAH_COMPILER_VAR_515 =__Bah_multiple_concat(____BAH_COMPILER_VAR_514, 4);cont = ____BAH_COMPILER_VAR_515;
++i;
};
println(cont);
};
struct Elems* dupElems(struct Elems* elems){
struct Elems* ____BAH_COMPILER_VAR_516 = memoryAlloc(sizeof(struct Elems));
____BAH_COMPILER_VAR_516->vars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_516->vars->length = 0;
            ____BAH_COMPILER_VAR_516->vars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_516->structs = memoryAlloc(sizeof(array(struct cStruct*)));
            ____BAH_COMPILER_VAR_516->structs->length = 0;
            ____BAH_COMPILER_VAR_516->structs->elemSize = sizeof(struct cStruct*);
            ____BAH_COMPILER_VAR_516->types = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_516->types->length = 0;
            ____BAH_COMPILER_VAR_516->types->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_516->fns = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_516->fns->length = 0;
            ____BAH_COMPILER_VAR_516->fns->elemSize = sizeof(struct func*);
            ____BAH_COMPILER_VAR_516->defined = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_516->defined->length = 0;
            ____BAH_COMPILER_VAR_516->defined->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_516->branchChecks = memoryAlloc(sizeof(array(struct varCheck)));
            ____BAH_COMPILER_VAR_516->branchChecks->length = 0;
            ____BAH_COMPILER_VAR_516->branchChecks->elemSize = sizeof(struct varCheck);
            struct Elems* nElems = ____BAH_COMPILER_VAR_516;
nElems->parent = elems;
allocateArray(nElems->vars,len(elems->vars));
register long int j = 0;
for (; (j<len(elems->vars)); ++j) {

    unsigned int ____BAH_COMPILER_VAR_517 = j;
    __Bah_realocate_arr(nElems->vars, ____BAH_COMPILER_VAR_517);
    nElems->vars->data[____BAH_COMPILER_VAR_517] = elems->vars->data[j];
};
nElems->structs = elems->structs;
nElems->types = elems->types;
nElems->fns = elems->fns;
return nElems;
};
typedef long int lineType;
#define LINE_TYPE_INCLUDE (lineType)0
#define LINE_TYPE_DEFINE (lineType)1
#define LINE_TYPE_CONST (lineType)2
#define LINE_TYPE_VAR (lineType)3
#define LINE_TYPE_FN_DECL (lineType)4
#define LINE_TYPE_FN_CALL (lineType)5
#define LINE_TYPE_STRUCT (lineType)6
#define LINE_TYPE_CLIB (lineType)7
#define LINE_TYPE_RETURN (lineType)8
#define LINE_TYPE_IF (lineType)9
#define LINE_TYPE_ELSE (lineType)10
#define LINE_TYPE_MACRO (lineType)11
#define LINE_TYPE_FOR (lineType)12
#define LINE_TYPE_FOR_OPERATOR (lineType)13
#define LINE_TYPE_PRE_KEYWORD (lineType)14
#define LINE_TYPE_ASYNC (lineType)15
#define LINE_TYPE_IMPORT (lineType)16
#define LINE_TYPE_CAPTURE (lineType)17
lineType prevLine;
void checkCanBeNull(struct Tok* t,char * tt,struct Elems* elems){

                struct string ____BAH_COMPILER_VAR_518 = string(compilerState.currentDir);
                if ((isUnsafe==false)&&(string__hasPrefix(&____BAH_COMPILER_VAR_518,BAH_DIR)==false)&&isRCPpointerType(tt)&&(t->cont[0]!=38)&&(t->cont[0]!=42)) {
struct variable* sv = searchVarByToken(t,elems);
if ((sv!=null)) {
if ((sv->canBeNull==true)&&(checkedNotNull(sv->name,elems)==false)) {
char * globCheck = "";
struct cStruct* s = searchStruct(sv->type,elems);
if ((sv->isGlobal==true)&&(s!=null)) {
char** ____BAH_COMPILER_VAR_519 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_519[2] = "'.";____BAH_COMPILER_VAR_519[1] = s->name;____BAH_COMPILER_VAR_519[0] = " or declare the var as 'new ";char * ____BAH_COMPILER_VAR_520 =__Bah_multiple_concat(____BAH_COMPILER_VAR_519, 3);globCheck = ____BAH_COMPILER_VAR_520;
}
char** ____BAH_COMPILER_VAR_521 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_521[2] = ".";____BAH_COMPILER_VAR_521[1] = globCheck;____BAH_COMPILER_VAR_521[0] = "{TOKEN} can contain a null value. Check if the value is null";char * ____BAH_COMPILER_VAR_522 =__Bah_multiple_concat(____BAH_COMPILER_VAR_521, 3);throwErr(t,____BAH_COMPILER_VAR_522);
}
}
}
};
void setNullStateBranchFlowEnd(struct Elems* elems){
if ((currentFn==null)) {
return;
}
if ((compilerState.isBranch==false)) {
currentFn->exits = true;
}
else {
register long int i = 0;
for (; (i<len(elems->branchChecks)); ++i) {
struct varCheck bc = elems->branchChecks->data[i];
if ((bc.v==null)) {
continue;
}
if ((bc.checkNull==true)) {
register long int j = 0;
for (; (j<len(elems->parent->vars)); ++j) {
struct variable* pv = elems->parent->vars->data[j];
if ((strcmp(pv->name, bc.v->name) == 0)) {
pv->canBeNull = false;
break;
}
};
}
};
if ((prevLine==LINE_TYPE_IF)&&(prevIfExits==true)) {
struct Elems* currElems = elems;
for (; (currElems!=null); currElems = currElems->parent) {
i = 0;
for (; (i<len(currElems->branchChecks)); ++i) {
struct varCheck bc = currElems->branchChecks->data[i];
if ((bc.v==null)) {
continue;
}
if ((bc.checkNull==true)) {
register long int j = 0;
for (; (j<len(currElems->parent->vars)); ++j) {
struct variable* pv = currElems->parent->vars->data[j];
if ((strcmp(pv->name, bc.v->name) == 0)) {
pv->canBeNull = false;
break;
}
};
}
};
};
}
prevIfExits = true;
}
};
lineType getLineType(__BAH_ARR_TYPE_Tok line){
struct Tok ft = line->data[0];
if ((ft.type==TOKEN_TYPE_FUNC)) {
return LINE_TYPE_FN_CALL;
}
if ((ft.type==TOKEN_TYPE_KEYWORD)) {
if ((strcmp(ft.cont, "#include") == 0)) {
return LINE_TYPE_INCLUDE;
}
else if ((strcmp(ft.cont, "#import") == 0)) {
return LINE_TYPE_IMPORT;
}
else if ((strcmp(ft.cont, "#define") == 0)) {
return LINE_TYPE_DEFINE;
}
else if ((strcmp(ft.cont, "const") == 0)) {
return LINE_TYPE_CONST;
}
else if ((strcmp(ft.cont, "struct") == 0)) {
return LINE_TYPE_STRUCT;
}
else if ((strcmp(ft.cont, "#cLib") == 0)) {
return LINE_TYPE_CLIB;
}
else if ((strcmp(ft.cont, "return") == 0)) {
return LINE_TYPE_RETURN;
}
else if ((strcmp(ft.cont, "if") == 0)) {
return LINE_TYPE_IF;
}
else if ((strcmp(ft.cont, "else") == 0)) {
return LINE_TYPE_ELSE;
}
else if ((strcmp(ft.cont, "#macro") == 0)) {
return LINE_TYPE_MACRO;
}
else if ((strcmp(ft.cont, "for") == 0)) {
return LINE_TYPE_FOR;
}
else if ((strcmp(ft.cont, "async") == 0)) {
return LINE_TYPE_ASYNC;
}
else if ((strcmp(ft.cont, "continue") == 0)||(strcmp(ft.cont, "break") == 0)) {
return LINE_TYPE_FOR_OPERATOR;
}
else if ((strcmp(ft.cont, "capture") == 0)) {
return LINE_TYPE_CAPTURE;
}
else {
return LINE_TYPE_PRE_KEYWORD;
}
}
else if ((ft.type==TOKEN_TYPE_VAR)) {
if ((len(line)>1)) {
struct Tok st = line->data[1];
if ((st.type==TOKEN_TYPE_ENCL)&&(strcmp(st.cont, "(") == 0)) {
struct Tok lt = line->data[len(line)-1];
if ((lt.type==TOKEN_TYPE_ENCL)&&(strcmp(lt.cont, "}") == 0)) {
return LINE_TYPE_FN_DECL;
}
return LINE_TYPE_FN_CALL;
}
}
return LINE_TYPE_VAR;
}
return (lineType)-1;
};
__BAH_ARR_TYPE_Tok parseCast(__BAH_ARR_TYPE_Tok line,struct Elems* elems,char guard){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
register long int i = 0;
if ((guard==true)) {
while ((i<len(line))) {
struct Tok t = line->data[i];
if ((t.type==TOKEN_TYPE_CAST)) {
break;
}

    unsigned int ____BAH_COMPILER_VAR_523 = i;
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_523);
    nl->data[____BAH_COMPILER_VAR_523] = t;
i = i+1;
};
if ((i==len(line))) {
return line;
}
}
for (; (i<len(line)); ++i) {
struct Tok t = line->data[i];
if ((t.type==TOKEN_TYPE_CAST)) {
if ((i+1<len(line))) {
struct Tok nnnt = line->data[i+1];
struct string tc = string(t.cont);
string__trimLeft(&tc,1);
string__trimRight(&tc,1);
nnnt.bahType = string__str(&tc);
char * ____BAH_COMPILER_VAR_524 =string__str(&tc);struct string cCast = getCType(____BAH_COMPILER_VAR_524,elems);
char * cCastStr = string__str(&cCast);
char** ____BAH_COMPILER_VAR_525 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_525[3] = nnnt.cont;____BAH_COMPILER_VAR_525[2] = ")";____BAH_COMPILER_VAR_525[1] = cCastStr;____BAH_COMPILER_VAR_525[0] = "(";char * ____BAH_COMPILER_VAR_526 =__Bah_multiple_concat(____BAH_COMPILER_VAR_525, 4);nnnt.cont = ____BAH_COMPILER_VAR_526;

    unsigned int ____BAH_COMPILER_VAR_527 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_527);
    nl->data[____BAH_COMPILER_VAR_527] = nnnt;
i = i+2;
continue;
}
}

    unsigned int ____BAH_COMPILER_VAR_528 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_528);
    nl->data[____BAH_COMPILER_VAR_528] = t;
};
return nl;
};
char * getDirFromFile(char * f){
char * ____BAH_COMPILER_VAR_529 =__STR(f);array(char)* p = strAsArr(____BAH_COMPILER_VAR_529);
register long int i = len(p)-1;
while ((i>=0)) {
char c = p->data[i];
if ((c==47)) {

    unsigned int ____BAH_COMPILER_VAR_530 = i+1;
    __Bah_realocate_arr(p, ____BAH_COMPILER_VAR_530);
    p->data[____BAH_COMPILER_VAR_530] = (char)0;
break;
}
i = i-1;
};
if ((i<=0)) {
return "";
}
return arrAsStr(p);
};
void parseLines(__BAH_ARR_TYPE_Tok ts,struct Elems* elems);
char includeFile(char * ccstr,struct Elems* elems){
char needDisableRCP = false;
if ((strcmp(ccstr, "BAH_MEM_COLLECTOR") == 0)) {
if ((RCPenabled==true)) {
needDisableRCP = true;
if (flags__isSet(&flags,"rcp")) {
ccstr = "rcp.bah";
}
else if (flags__isSet(&flags,"fastrcp")) {
ccstr = "fastrcp.bah";
}
}
else {
ccstr = "gc.bah";
}
}

        char ____BAH_COMPILER_VAR_531 = 0;
        for(int i=compilerState.includes->length-1; i!=-1;i--) {
            if (compilerState.includes->data[i] != 0 && strcmp(compilerState.includes->data[i], ccstr) == 0) {
                ____BAH_COMPILER_VAR_531=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_531) {
return true;
}
struct fileMap ____BAH_COMPILER_VAR_532 = {};
____BAH_COMPILER_VAR_532.handle = -1;
#define fm ____BAH_COMPILER_VAR_532
char** ____BAH_COMPILER_VAR_533 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_533[1] = ccstr;____BAH_COMPILER_VAR_533[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_534 =__Bah_multiple_concat(____BAH_COMPILER_VAR_533, 2);char * fileName = ____BAH_COMPILER_VAR_534;
char isBahDir = true;
char * f = fileMap__open(&fm,fileName);
if ((fileMap__isValid(&fm)==0)) {
char** ____BAH_COMPILER_VAR_535 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_535[1] = ccstr;____BAH_COMPILER_VAR_535[0] = compilerState.currentDir;char * ____BAH_COMPILER_VAR_536 =__Bah_multiple_concat(____BAH_COMPILER_VAR_535, 2);fileName = absPath(____BAH_COMPILER_VAR_536);
f = fileMap__open(&fm,fileName);
isBahDir = false;
if ((fileMap__isValid(&fm)==0)) {
return false;
}
}
char * oDir = compilerState.currentDir;
if ((isBahDir==false)) {
char** ____BAH_COMPILER_VAR_537 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_537[1] = getDirFromFile(ccstr);____BAH_COMPILER_VAR_537[0] = compilerState.currentDir;char * ____BAH_COMPILER_VAR_538 =__Bah_multiple_concat(____BAH_COMPILER_VAR_537, 2);compilerState.currentDir = ____BAH_COMPILER_VAR_538;
}
else {
char** ____BAH_COMPILER_VAR_539 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_539[1] = getDirFromFile(ccstr);____BAH_COMPILER_VAR_539[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_540 =__Bah_multiple_concat(____BAH_COMPILER_VAR_539, 2);compilerState.currentDir = ____BAH_COMPILER_VAR_540;
}
char * oFile = compilerState.currentFile;
compilerState.currentFile = fileName;

    unsigned int ____BAH_COMPILER_VAR_541 = len(compilerState.includes);
    __Bah_realocate_arr(compilerState.includes, ____BAH_COMPILER_VAR_541);
    compilerState.includes->data[____BAH_COMPILER_VAR_541] = ccstr;
array(struct Tok)* tokens = lexer(f);
fileMap__close(&fm);
if ((len(tokens)==0)) {
char** ____BAH_COMPILER_VAR_542 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_542[2] = "' not recognized.";____BAH_COMPILER_VAR_542[1] = ccstr;____BAH_COMPILER_VAR_542[0] = "File '";char * ____BAH_COMPILER_VAR_543 =__Bah_multiple_concat(____BAH_COMPILER_VAR_542, 3);__BAH_panic(____BAH_COMPILER_VAR_543,"/home/alois/Documents/bah-bah/src/parser.bah:250");
}
char oshd = shouldOnlyDecl;
if ((isObject==true)) {

                struct string ____BAH_COMPILER_VAR_544 = string(compilerState.currentFile);
                if ((isBahDir==true)||(string__hasPrefix(&____BAH_COMPILER_VAR_544,oDir)==false)) {
shouldOnlyDecl = true;
}
else {
shouldOnlyDecl = false;
}
}
else if ((isSubObject==true)) {

                struct string ____BAH_COMPILER_VAR_545 = string(compilerState.currentFile);
                if ((isBahDir==true)||(string__hasPrefix(&____BAH_COMPILER_VAR_545,oDir)==false)) {
if ((isImportedSubObject==true)&&(isBahDir==false)) {
shouldOnlyDecl = true;
}
else {
shouldOnlyDecl = false;
}
}
else {
shouldOnlyDecl = true;
}
}
if ((needDisableRCP==true)) {
RCPenabled = false;
}
parseLines(tokens,elems);
if ((needDisableRCP==true)) {
RCPenabled = true;
}
shouldOnlyDecl = oshd;
compilerState.currentFile = oFile;
compilerState.currentDir = oDir;
return true;

#undef fm
};
void parallelObjCompile(char * fn,char * oName,struct channel * done){
readCache();
struct cacheFile* cf = getCacheFile(fn);
char * wrkd = getCurrentPath();
char * rcp = "";
if ((RCPlevel==1)) {
rcp = "-rcp";
}
else if ((RCPlevel==2)) {
rcp = "-fastrcp";
}
if ((cf==null)||(cf!=null)&&(isValidCacheFile(cf)==false)) {
setCurrentPath(compilerState.currentDir);
char * verboseCC = "";
if ((flags__isSet(&flags,"verboseCC")==1)) {
verboseCC = "-verboseCC";
}
if ((debug==false)) {
char** ____BAH_COMPILER_VAR_546 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_546[1] = fn;____BAH_COMPILER_VAR_546[0] = "[compiling] ";char * ____BAH_COMPILER_VAR_547 =__Bah_multiple_concat(____BAH_COMPILER_VAR_546, 2);println(____BAH_COMPILER_VAR_547);
}
char * opti = "";
if ((isOptimized==true)) {
opti = "-optimize";
}
char** ____BAH_COMPILER_VAR_548 = alloca(11 * sizeof(char*));____BAH_COMPILER_VAR_548[10] = oName;____BAH_COMPILER_VAR_548[9] = " -o ";____BAH_COMPILER_VAR_548[8] = verboseCC;____BAH_COMPILER_VAR_548[7] = " -object ";____BAH_COMPILER_VAR_548[6] = opti;____BAH_COMPILER_VAR_548[5] = " ";____BAH_COMPILER_VAR_548[4] = rcp;____BAH_COMPILER_VAR_548[3] = " ";____BAH_COMPILER_VAR_548[2] = fn;____BAH_COMPILER_VAR_548[1] = " ";____BAH_COMPILER_VAR_548[0] = execName;char * ____BAH_COMPILER_VAR_549 =__Bah_multiple_concat(____BAH_COMPILER_VAR_548, 11);struct command cmd = command(____BAH_COMPILER_VAR_549);
array(char)* res = command__runBytes(&cmd);
setCurrentPath(wrkd);
if ((cmd.status!=0)) {
char * ____BAH_COMPILER_VAR_550 =arrToStr(res);print(____BAH_COMPILER_VAR_550);
exit(1);
}
if ((cf==null)) {
makeCacheFile(fn);
}
else {
updateCacheFile(cf);
}
}

        char ____BAH_COMPILER_VAR_551 = true;
        channel__sendAny(done, &____BAH_COMPILER_VAR_551, sizeof(____BAH_COMPILER_VAR_551));
        };
void parseImport(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
compilerState.hasImports = true;
if ((len(l)!=2)) {
throwErr(&l->data[0],"Invalid usage of {TOKEN}.");
}
struct Tok strt = l->data[1];
if ((strt.type!=TOKEN_TYPE_STR)) {
throwErr(&strt,"Cannot use {TOKEN} as file name (#import \"file\")");
}
struct string fileName = string(strt.cont);
string__trimLeft(&fileName,1);
string__trimRight(&fileName,1);

        char ____BAH_COMPILER_VAR_552 = 0;
        for(int i=compilerState.includes->length-1; i!=-1;i--) {
            if (compilerState.includes->data[i] != 0 && strcmp(compilerState.includes->data[i], string__str(&fileName)) == 0) {
                ____BAH_COMPILER_VAR_552=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_552) {
return;
}

    unsigned int ____BAH_COMPILER_VAR_553 = len(compilerState.includes);
    __Bah_realocate_arr(compilerState.includes, ____BAH_COMPILER_VAR_553);
    compilerState.includes->data[____BAH_COMPILER_VAR_553] = string__str(&fileName);
char** ____BAH_COMPILER_VAR_554 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_554[1] = string__str(&fileName);____BAH_COMPILER_VAR_554[0] = compilerState.currentDir;char * ____BAH_COMPILER_VAR_555 =__Bah_multiple_concat(____BAH_COMPILER_VAR_554, 2);char * fn = absPath(____BAH_COMPILER_VAR_555);
if (((void *)fn==null)) {
char** ____BAH_COMPILER_VAR_556 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_556[1] = string__str(&fileName);____BAH_COMPILER_VAR_556[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_557 =__Bah_multiple_concat(____BAH_COMPILER_VAR_556, 2);fn = absPath(____BAH_COMPILER_VAR_557);
if (((void *)fn==null)) {
throwErr(&strt,"Unknown file {TOKEN}.");
}
}
char * of = compilerState.currentFile;
char * od = compilerState.currentDir;
compilerState.currentFile = fn;
compilerState.currentDir = getDirFromFile(fn);
struct fileStream ____BAH_COMPILER_VAR_558 = {};
#define fs ____BAH_COMPILER_VAR_558
fileStream__open(&fs,fn,"r");
char * f = fileStream__readContent(&fs);
fileStream__close(&fs);
array(struct Tok)* tokens = lexer(f);
char osod = shouldOnlyDecl;
char oiso = isSubObject;
char oiiso = isImportedSubObject;
if ((isSubObject==true)) {
isImportedSubObject = true;
}
shouldOnlyDecl = true;
isSubObject = true;
char** ____BAH_COMPILER_VAR_559 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_559[5] = ".o";____BAH_COMPILER_VAR_559[4] = intToStr(isOptimized);____BAH_COMPILER_VAR_559[3] = intToStr(RCPlevel);____BAH_COMPILER_VAR_559[2] = pathToVarName(fn);____BAH_COMPILER_VAR_559[1] = "cache/";____BAH_COMPILER_VAR_559[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_560 =__Bah_multiple_concat(____BAH_COMPILER_VAR_559, 6);char * oName = ____BAH_COMPILER_VAR_560;
char** ____BAH_COMPILER_VAR_561 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_561[2] = ".o";____BAH_COMPILER_VAR_561[1] = oName;____BAH_COMPILER_VAR_561[0] = "w ";char * ____BAH_COMPILER_VAR_562 =__Bah_multiple_concat(____BAH_COMPILER_VAR_561, 3);
    unsigned int ____BAH_COMPILER_VAR_563 = len(compilerState.cLibs);
    __Bah_realocate_arr(compilerState.cLibs, ____BAH_COMPILER_VAR_563);
    compilerState.cLibs->data[____BAH_COMPILER_VAR_563] = ____BAH_COMPILER_VAR_562;
struct channel * done = channel();
parallelObjCompile(fn,oName,done);
parseLines(tokens,elems);
char ok = *(char*)channel__receive(done);
char** ____BAH_COMPILER_VAR_564 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_564[2] = "();\n";____BAH_COMPILER_VAR_564[1] = pathToVarName(fn);____BAH_COMPILER_VAR_564[0] = "__BAH_init";char * ____BAH_COMPILER_VAR_565 =__Bah_multiple_concat(____BAH_COMPILER_VAR_564, 3);INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_565));
writeCache();
shouldOnlyDecl = osod;
isSubObject = oiso;
compilerState.currentFile = of;
compilerState.currentDir = od;
isImportedSubObject = oiiso;

#undef fs
};
void parseInclude(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
if ((len(l)!=2)&&(len(l)!=3)) {
throwErr(&l->data[len(l)-1],"Invalid usage of include, ending by {TOKEN}.");
}
struct Tok strt = l->data[1];
char isSupressed = false;
if ((strcmp(strt.cont, "!") == 0)&&(len(l)>2)) {
isSupressed = true;
strt = l->data[2];
}
if ((strt.type!=TOKEN_TYPE_STR)) {
throwErr(&strt,"Cannot use {TOKEN} as string in include.");
}
char * sc = strt.cont;
strTrimLeft(&sc,1);
strTrimRight(&sc,1);
if (strHasPrefix(sc,"<")||strHasSuffix(sc,".h")||strHasSuffix(sc,".c")) {
if ((isSubObject==false)||(isSupressed==false)) {
char** ____BAH_COMPILER_VAR_566 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_566[2] = "\n";____BAH_COMPILER_VAR_566[1] = sc;____BAH_COMPILER_VAR_566[0] = "#include ";char * ____BAH_COMPILER_VAR_567 =__Bah_multiple_concat(____BAH_COMPILER_VAR_566, 3);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_567));

    unsigned int ____BAH_COMPILER_VAR_568 = len(compilerState.cIncludes);
    __Bah_realocate_arr(compilerState.cIncludes, ____BAH_COMPILER_VAR_568);
    compilerState.cIncludes->data[____BAH_COMPILER_VAR_568] = sc;
}
}
else {
if ((includeFile(sc,elems)==false)) {
throwErr(&strt,"Could not find file {TOKEN}.");
}
}
};
array(char *)* signs;
__BAH_ARR_TYPE_Tok prePross(__BAH_ARR_TYPE_Tok line,lineType ltp,struct Elems* elems);
__BAH_ARR_TYPE_Tok parseStructType(__BAH_ARR_TYPE_Tok line,lineType ltp,struct Elems* elems){
if ((ltp==LINE_TYPE_VAR)) {
return line;
}
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
register long int i = 0;
while ((i<len(line))) {
struct Tok t = line->data[i];
if ((t.type==TOKEN_TYPE_VAR)) {
if (strHasPrefix(t.bahType,"[]")) {

    unsigned int ____BAH_COMPILER_VAR_569 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_569);
    nl->data[____BAH_COMPILER_VAR_569] = t;
++i;
continue;
}
++i;
struct Tok ____BAH_COMPILER_VAR_570 = {};
____BAH_COMPILER_VAR_570.cont = "";
____BAH_COMPILER_VAR_570.ogCont = "";
____BAH_COMPILER_VAR_570.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_570.line = 1;
____BAH_COMPILER_VAR_570.begLine = 1;
____BAH_COMPILER_VAR_570.bahType = "";
____BAH_COMPILER_VAR_570.cont = "";
#define nt ____BAH_COMPILER_VAR_570
if ((i<len(line))) {
nt = line->data[i];
}
if ((i==len(line))||(strcmp(nt.cont, "{") != 0)) {
if ((i-2>=0)) {
struct Tok newTk = line->data[i-2];
if ((strcmp(newTk.cont, "new") == 0)) {
struct cStruct* s = searchStruct(t.cont,elems);
if ((s==null)) {
throwErr(&t,"Cannot initialize new unknown struct {TOKEN}.");
}
t.cont = genCompilerVar();
struct variable* ____BAH_COMPILER_VAR_571 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_571->name = "";
____BAH_COMPILER_VAR_571->type = "";
____BAH_COMPILER_VAR_571->constVal = "";
____BAH_COMPILER_VAR_571->from = "";
struct variable* tmpV = ____BAH_COMPILER_VAR_571;
tmpV->name = t.cont;
char** ____BAH_COMPILER_VAR_572 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_572[1] = "*";____BAH_COMPILER_VAR_572[0] = s->name;char * ____BAH_COMPILER_VAR_573 =__Bah_multiple_concat(____BAH_COMPILER_VAR_572, 2);tmpV->type = ____BAH_COMPILER_VAR_573;
struct string cType = getCType(tmpV->type,elems);
struct string structType = getCType(s->name,elems);

    unsigned int ____BAH_COMPILER_VAR_574 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_574);
    elems->vars->data[____BAH_COMPILER_VAR_574] = tmpV;
char** ____BAH_COMPILER_VAR_575 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_575[6] = declareStructMethods(tmpV,s,elems);____BAH_COMPILER_VAR_575[5] = "));\n";____BAH_COMPILER_VAR_575[4] = string__str(&structType);____BAH_COMPILER_VAR_575[3] = " = memoryAlloc(sizeof(";____BAH_COMPILER_VAR_575[2] = t.cont;____BAH_COMPILER_VAR_575[1] = " ";____BAH_COMPILER_VAR_575[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_576 =__Bah_multiple_concat(____BAH_COMPILER_VAR_575, 7);struct rope* r = rope(____BAH_COMPILER_VAR_576);
if (isGlobal()) {
INIT = rope__add(INIT, r);
}
else {
OUTPUT = rope__add(OUTPUT, r);
}

    unsigned int ____BAH_COMPILER_VAR_577 = len(nl)-1;
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_577);
    nl->data[____BAH_COMPILER_VAR_577] = t;
continue;
}
}
}
if ((i<len(line))) {
nt = line->data[i];
if ((strcmp(nt.cont, "{") == 0)) {
char isHeap = false;
char * sep = ".";
if ((i-2>=0)) {
struct Tok newTk = line->data[i-2];
if ((strcmp(newTk.cont, "new") == 0)) {
isHeap = true;
sep = "->";
}
}
++i;
struct cStruct* s = searchStruct(t.cont,elems);
if ((s==null)) {
throwErr(&t,"Unknown struct name {TOKEN}.");
}
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
long int nbBraces = 1;
for (; (i<len(line)); ++i) {
t = line->data[i];
if ((strcmp(t.cont, "{") == 0)) {
++nbBraces;
}
else if ((strcmp(t.cont, "}") == 0)) {
--nbBraces;
if ((nbBraces==0)) {
break;
}
}

    unsigned int ____BAH_COMPILER_VAR_578 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_578);
    memory->data[____BAH_COMPILER_VAR_578] = t;
};
if ((len(memory)>0)) {
memory = prePross(memory,(lineType)-1,elems);
}
long int declType = 0;
char * rvn = genCompilerVar();
struct variable* ____BAH_COMPILER_VAR_579 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_579->name = "";
____BAH_COMPILER_VAR_579->type = "";
____BAH_COMPILER_VAR_579->constVal = "";
____BAH_COMPILER_VAR_579->from = "";
struct variable* tmpV = ____BAH_COMPILER_VAR_579;
tmpV->name = rvn;
if ((isHeap==true)) {
char** ____BAH_COMPILER_VAR_580 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_580[1] = "*";____BAH_COMPILER_VAR_580[0] = s->name;char * ____BAH_COMPILER_VAR_581 =__Bah_multiple_concat(____BAH_COMPILER_VAR_580, 2);tmpV->type = ____BAH_COMPILER_VAR_581;

    unsigned int ____BAH_COMPILER_VAR_582 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_582);
    elems->vars->data[____BAH_COMPILER_VAR_582] = tmpV;
}
else {
tmpV->type = s->name;
}
struct string rst = getCType(tmpV->type,elems);
struct rope* r= null;
if ((isHeap==true)) {
char * ____BAH_COMPILER_VAR_583 =string__str(&rst);struct string structType = string(____BAH_COMPILER_VAR_583);
string__trimRight(&structType,1);
char** ____BAH_COMPILER_VAR_584 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_584[6] = declareStructMethods(tmpV,s,elems);____BAH_COMPILER_VAR_584[5] = "));\n";____BAH_COMPILER_VAR_584[4] = string__str(&structType);____BAH_COMPILER_VAR_584[3] = " = memoryAlloc(sizeof(";____BAH_COMPILER_VAR_584[2] = rvn;____BAH_COMPILER_VAR_584[1] = " ";____BAH_COMPILER_VAR_584[0] = string__str(&rst);char * ____BAH_COMPILER_VAR_585 =__Bah_multiple_concat(____BAH_COMPILER_VAR_584, 7);r = rope(____BAH_COMPILER_VAR_585);
}
else {
char** ____BAH_COMPILER_VAR_586 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_586[4] = declareStructMethods(tmpV,s,elems);____BAH_COMPILER_VAR_586[3] = " = {};\n";____BAH_COMPILER_VAR_586[2] = rvn;____BAH_COMPILER_VAR_586[1] = " ";____BAH_COMPILER_VAR_586[0] = string__str(&rst);char * ____BAH_COMPILER_VAR_587 =__Bah_multiple_concat(____BAH_COMPILER_VAR_586, 5);r = rope(____BAH_COMPILER_VAR_587);
}
register long int j = 0;
register long int k = 0;
while ((k<len(memory))) {
t = memory->data[k];
if ((k+2<len(memory))) {
struct Tok st = memory->data[k+1];
struct Tok vl = memory->data[k+2];
if ((strcmp(st.cont, ":") == 0)) {
if ((declType!=0)&&(declType!=1)) {
throwErr(&t,"Cannot declare member {TOKEN} by name in list declaration.");
}
declType = 1;
if ((t.type!=TOKEN_TYPE_VAR)) {
throwErr(&t,"Cannot use {TOKEN} as struct member name.");
}
j = 0;
while ((j<len(s->members))) {
struct structMemb* m = s->members->data[j];
if ((strcmp(m->name, t.cont) != 0)) {
j = j+1;
continue;
}
char * vlt = getTypeFromToken(&vl,true,elems);
if ((compTypes(vlt,m->type)==false)) {
char** ____BAH_COMPILER_VAR_588 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_588[4] = "'.";____BAH_COMPILER_VAR_588[3] = m->type;____BAH_COMPILER_VAR_588[2] = ") as '";____BAH_COMPILER_VAR_588[1] = vlt;____BAH_COMPILER_VAR_588[0] = "Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_589 =__Bah_multiple_concat(____BAH_COMPILER_VAR_588, 5);throwErr(&vl,____BAH_COMPILER_VAR_589);
}
char** ____BAH_COMPILER_VAR_590 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_590[5] = ";\n";____BAH_COMPILER_VAR_590[4] = vl.cont;____BAH_COMPILER_VAR_590[3] = " = ";____BAH_COMPILER_VAR_590[2] = m->name;____BAH_COMPILER_VAR_590[1] = sep;____BAH_COMPILER_VAR_590[0] = rvn;char * ____BAH_COMPILER_VAR_591 =__Bah_multiple_concat(____BAH_COMPILER_VAR_590, 6);r = rope__add(r, rope(____BAH_COMPILER_VAR_591));
break;
};
if ((j==len(s->members))) {
char** ____BAH_COMPILER_VAR_592 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_592[2] = "' has no member called {TOKEN}.";____BAH_COMPILER_VAR_592[1] = s->name;____BAH_COMPILER_VAR_592[0] = "Struct '";char * ____BAH_COMPILER_VAR_593 =__Bah_multiple_concat(____BAH_COMPILER_VAR_592, 3);throwErr(&t,____BAH_COMPILER_VAR_593);
}
k = k+3;
continue;
}
}
if ((declType!=0)&&(declType!=2)) {
throwErr(&t,"Cannot declare member {TOKEN} without specifying its name.");
}
declType = 2;
if ((j>len(s->members))) {
throwErr(&t,"Too many members {TOKEN}.");
}
struct structMemb* m = s->members->data[j];
++j;
char * tt = getTypeFromToken(&t,true,elems);
if ((compTypes(tt,m->type)==false)) {
char** ____BAH_COMPILER_VAR_594 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_594[4] = "'.";____BAH_COMPILER_VAR_594[3] = m->type;____BAH_COMPILER_VAR_594[2] = ") as '";____BAH_COMPILER_VAR_594[1] = tt;____BAH_COMPILER_VAR_594[0] = "Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_595 =__Bah_multiple_concat(____BAH_COMPILER_VAR_594, 5);throwErr(&t,____BAH_COMPILER_VAR_595);
}
char** ____BAH_COMPILER_VAR_596 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_596[5] = ";\n";____BAH_COMPILER_VAR_596[4] = t.cont;____BAH_COMPILER_VAR_596[3] = " = ";____BAH_COMPILER_VAR_596[2] = m->name;____BAH_COMPILER_VAR_596[1] = sep;____BAH_COMPILER_VAR_596[0] = rvn;char * ____BAH_COMPILER_VAR_597 =__Bah_multiple_concat(____BAH_COMPILER_VAR_596, 6);r = rope__add(r, rope(____BAH_COMPILER_VAR_597));
if ((k+1<len(memory))) {
++k;
struct Tok st = memory->data[k];
if ((strcmp(st.cont, ",") != 0)) {
throwErr(&st,"Need ',' separator between two values, not {TOKEN}.");
}
}
++k;
};
if (isGlobal()) {
INIT = rope__add(INIT, r);
}
else {
OUTPUT = rope__add(OUTPUT, r);
}
t.bahType = tmpV->type;
t.cont = rvn;
t.isValue = true;
if ((isHeap==true)) {

    unsigned int ____BAH_COMPILER_VAR_598 = len(nl)-1;
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_598);
    nl->data[____BAH_COMPILER_VAR_598] = t;
}
else {
t.isEqual = true;

    unsigned int ____BAH_COMPILER_VAR_599 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_599);
    nl->data[____BAH_COMPILER_VAR_599] = t;
}
++i;
continue;
}
else {
--i;
}
}

#undef nt
}

    unsigned int ____BAH_COMPILER_VAR_600 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_600);
    nl->data[____BAH_COMPILER_VAR_600] = t;
++i;
};
return nl;
};
__BAH_ARR_TYPE_Tok parseArrayType(__BAH_ARR_TYPE_Tok line,struct Elems* elems,char guard){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
register long int i = 0;
if ((guard==true)) {
for (; (i<len(line)); ++i) {
struct Tok t = line->data[i];
if ((strcmp(t.cont, "[") == 0)) {
break;
}

    unsigned int ____BAH_COMPILER_VAR_601 = i;
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_601);
    nl->data[____BAH_COMPILER_VAR_601] = t;
};
if ((i==len(line))) {
return line;
}
}
for (; (i<len(line)); ++i) {
struct Tok t = line->data[i];
if ((strcmp(t.cont, "[") == 0)) {
++i;
if ((i<len(line))) {
t = line->data[i];
if ((strcmp(t.cont, "]") == 0)) {
++i;
long int depth = 1;
char * bracks = "[]";
for (; (i<len(line)-1); ++i) {
t = line->data[i];
struct Tok nt = line->data[i+1];
if ((strcmp(t.cont, "[") == 0)&&(strcmp(nt.cont, "]") == 0)) {
++depth;
char** ____BAH_COMPILER_VAR_602 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_602[1] = "[]";____BAH_COMPILER_VAR_602[0] = bracks;char * ____BAH_COMPILER_VAR_603 =__Bah_multiple_concat(____BAH_COMPILER_VAR_602, 2);bracks = ____BAH_COMPILER_VAR_603;
++i;
}
else {
break;
}
};
if ((i<len(line))) {
t = line->data[i];
if ((t.type!=TOKEN_TYPE_VAR)) {
throwErr(&t,"Cannot use {TOKEN} as array type.");
}
char * arrElem = t.cont;
char** ____BAH_COMPILER_VAR_604 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_604[1] = arrElem;____BAH_COMPILER_VAR_604[0] = bracks;char * ____BAH_COMPILER_VAR_605 =__Bah_multiple_concat(____BAH_COMPILER_VAR_604, 2);t.bahType = ____BAH_COMPILER_VAR_605;
t.cont = "";
t.isValue = true;

    unsigned int ____BAH_COMPILER_VAR_606 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_606);
    nl->data[____BAH_COMPILER_VAR_606] = t;
continue;
}
}
}
}

    unsigned int ____BAH_COMPILER_VAR_607 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_607);
    nl->data[____BAH_COMPILER_VAR_607] = t;
};
return nl;
};
array(char *)* comparators;
array(char *)* compSep;
__BAH_ARR_TYPE_Tok parsePointers(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
register long int i = 0;
for (; (i<len(l)); ++i) {
struct Tok t = l->data[i];
if ((strcmp(t.cont, "&") == 0)||(strcmp(t.cont, "*") == 0)) {
if ((i>0)) {
if ((l->data[i-1].type==TOKEN_TYPE_VAR)||(l->data[i-1].isValue==true)) {
if ((strcmp(t.cont, "*") == 0)) {
if ((i+1<len(l))) {
if ((strcmp(l->data[i+1].cont, "(") != 0)&&(strcmp(l->data[i+1].cont, "<") != 0)&&(l->data[i+1].isValue!=true)) {
char** ____BAH_COMPILER_VAR_608 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_608[1] = t.cont;____BAH_COMPILER_VAR_608[0] = l->data[i-1].cont;char * ____BAH_COMPILER_VAR_609 =__Bah_multiple_concat(____BAH_COMPILER_VAR_608, 2);l->data[i-1].cont = ____BAH_COMPILER_VAR_609;
delete(l,i);
--i;
}
}
else {
char** ____BAH_COMPILER_VAR_610 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_610[1] = t.cont;____BAH_COMPILER_VAR_610[0] = l->data[i-1].cont;char * ____BAH_COMPILER_VAR_611 =__Bah_multiple_concat(____BAH_COMPILER_VAR_610, 2);l->data[i-1].cont = ____BAH_COMPILER_VAR_611;
delete(l,i);
--i;
}
}
continue;
}
}
}
if ((strcmp(t.cont, "&") == 0)||(strcmp(t.cont, "*") == 0)) {
if ((i+1<len(l))) {
if ((i>0)) {
if ((strcmp(l->data[i-1].cont, ")") == 0)||(l->data[i-1].isValue==true)) {
continue;
}
}
if ((l->data[i+1].type==TOKEN_TYPE_VAR)) {
char** ____BAH_COMPILER_VAR_612 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_612[1] = l->data[i+1].cont;____BAH_COMPILER_VAR_612[0] = t.cont;char * ____BAH_COMPILER_VAR_613 =__Bah_multiple_concat(____BAH_COMPILER_VAR_612, 2);l->data[i+1].cont = ____BAH_COMPILER_VAR_613;
delete(l,i);
--i;
}
}
}
};
return l;
};
char * parseSerialize(struct Tok* e,struct Elems* elems){
struct variable* v = searchVar(e->cont,elems);
if ((v==null)) {
throwErr(&e,"Must be a var, not {TOKEN}.");
}
struct cStruct* s = searchStruct(v->type,elems);
if ((s==null)) {
throwErr(&e,"Must be a struct, not {TOKEN}.");
}
struct string svt = string(v->type);
register long int ptrLevel = string__count(&svt,"*");
string__replace(&svt,"*","");
char * code= null;
if ((ptrLevel==0)) {
char** ____BAH_COMPILER_VAR_614 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_614[5] = ")";____BAH_COMPILER_VAR_614[4] = string__str(&svt);____BAH_COMPILER_VAR_614[3] = "sizeof(struct ";____BAH_COMPILER_VAR_614[2] = ", ";____BAH_COMPILER_VAR_614[1] = e->cont;____BAH_COMPILER_VAR_614[0] = "__serialize(&";char * ____BAH_COMPILER_VAR_615 =__Bah_multiple_concat(____BAH_COMPILER_VAR_614, 6);code = ____BAH_COMPILER_VAR_615;
}
else {
char * ptrRect = "";
while ((ptrLevel>1)) {
char** ____BAH_COMPILER_VAR_616 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_616[1] = "*";____BAH_COMPILER_VAR_616[0] = ptrRect;char * ____BAH_COMPILER_VAR_617 =__Bah_multiple_concat(____BAH_COMPILER_VAR_616, 2);ptrRect = ____BAH_COMPILER_VAR_617;
ptrLevel = ptrLevel-1;
};
char** ____BAH_COMPILER_VAR_618 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_618[6] = ")";____BAH_COMPILER_VAR_618[5] = string__str(&svt);____BAH_COMPILER_VAR_618[4] = "sizeof(struct ";____BAH_COMPILER_VAR_618[3] = ", ";____BAH_COMPILER_VAR_618[2] = e->cont;____BAH_COMPILER_VAR_618[1] = ptrRect;____BAH_COMPILER_VAR_618[0] = "__serialize(";char * ____BAH_COMPILER_VAR_619 =__Bah_multiple_concat(____BAH_COMPILER_VAR_618, 7);code = ____BAH_COMPILER_VAR_619;
register long int i = 0;
while ((i<len(s->members))) {
struct structMemb* m = s->members->data[i];
if ((strcmp(m->type, "cpstring") == 0)) {
char** ____BAH_COMPILER_VAR_620 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_620[5] = ")";____BAH_COMPILER_VAR_620[4] = m->name;____BAH_COMPILER_VAR_620[3] = "->";____BAH_COMPILER_VAR_620[2] = e->cont;____BAH_COMPILER_VAR_620[1] = "+strlen(";____BAH_COMPILER_VAR_620[0] = code;char * ____BAH_COMPILER_VAR_621 =__Bah_multiple_concat(____BAH_COMPILER_VAR_620, 6);code = ____BAH_COMPILER_VAR_621;
}
i = i+1;
};
}
char** ____BAH_COMPILER_VAR_622 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_622[1] = ")";____BAH_COMPILER_VAR_622[0] = code;char * ____BAH_COMPILER_VAR_623 =__Bah_multiple_concat(____BAH_COMPILER_VAR_622, 2);return ____BAH_COMPILER_VAR_623;
};
struct Tok parseReflect(struct Tok t,char * tt,struct Elems* elems,char parsedPointer,char * ogName,char * offset){
char * isArr = "0";
if ((t.type!=TOKEN_TYPE_VAR)||(t.type!=TOKEN_TYPE_FUNC)) {
struct string cType;
if (strHasPrefix(tt,"function(")) {
cType = string("void*");
}
else {
cType = getCType(tt,elems);
}
char * v = genCompilerVar();
if ((parsedPointer==true)) {
string__append(&cType,"*");
}
char** ____BAH_COMPILER_VAR_624 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_624[5] = ";\n";____BAH_COMPILER_VAR_624[4] = t.cont;____BAH_COMPILER_VAR_624[3] = " = ";____BAH_COMPILER_VAR_624[2] = v;____BAH_COMPILER_VAR_624[1] = " ";____BAH_COMPILER_VAR_624[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_625 =__Bah_multiple_concat(____BAH_COMPILER_VAR_624, 6);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_625));
t.cont = v;
if ((t.type==TOKEN_TYPE_STR)) {
ogName = "[bah cpstring]";
}
}
char * arrElem = "0";
if (strHasPrefix(tt,"[]")) {
isArr = "1";
struct string aet = string(tt);
string__trimLeft(&aet,2);
struct Tok ____BAH_COMPILER_VAR_626 = {};
____BAH_COMPILER_VAR_626.cont = "";
____BAH_COMPILER_VAR_626.ogCont = "";
____BAH_COMPILER_VAR_626.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_626.line = 1;
____BAH_COMPILER_VAR_626.begLine = 1;
____BAH_COMPILER_VAR_626.bahType = "";
#define tmpT ____BAH_COMPILER_VAR_626
tmpT.type = TOKEN_TYPE_VAR;
tmpT.cont = "0";
char * ____BAH_COMPILER_VAR_627 =string__str(&aet);struct Tok rt = parseReflect(tmpT,____BAH_COMPILER_VAR_627,elems,true,"","0");
char * aev = genCompilerVar();
char** ____BAH_COMPILER_VAR_628 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_628[4] = ";\n        ";____BAH_COMPILER_VAR_628[3] = rt.cont;____BAH_COMPILER_VAR_628[2] = " = ";____BAH_COMPILER_VAR_628[1] = aev;____BAH_COMPILER_VAR_628[0] = "\n        struct reflectElement ";char * ____BAH_COMPILER_VAR_629 =__Bah_multiple_concat(____BAH_COMPILER_VAR_628, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_629));
char** ____BAH_COMPILER_VAR_630 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_630[1] = aev;____BAH_COMPILER_VAR_630[0] = "&";char * ____BAH_COMPILER_VAR_631 =__Bah_multiple_concat(____BAH_COMPILER_VAR_630, 2);arrElem = ____BAH_COMPILER_VAR_631;

#undef tmpT
}
else if (strHasPrefix(tt,"map:")) {
struct string aet = string(tt);
string__trimLeft(&aet,4);
struct Tok ____BAH_COMPILER_VAR_632 = {};
____BAH_COMPILER_VAR_632.cont = "";
____BAH_COMPILER_VAR_632.ogCont = "";
____BAH_COMPILER_VAR_632.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_632.line = 1;
____BAH_COMPILER_VAR_632.begLine = 1;
____BAH_COMPILER_VAR_632.bahType = "";
#define tmpT ____BAH_COMPILER_VAR_632
tmpT.type = TOKEN_TYPE_VAR;
tmpT.cont = "0";
char * ____BAH_COMPILER_VAR_633 =string__str(&aet);struct Tok rt = parseReflect(tmpT,____BAH_COMPILER_VAR_633,elems,true,"","0");
char * aev = genCompilerVar();
char** ____BAH_COMPILER_VAR_634 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_634[4] = ";\n        ";____BAH_COMPILER_VAR_634[3] = rt.cont;____BAH_COMPILER_VAR_634[2] = " = ";____BAH_COMPILER_VAR_634[1] = aev;____BAH_COMPILER_VAR_634[0] = "\n        struct reflectElement ";char * ____BAH_COMPILER_VAR_635 =__Bah_multiple_concat(____BAH_COMPILER_VAR_634, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_635));
char** ____BAH_COMPILER_VAR_636 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_636[1] = aev;____BAH_COMPILER_VAR_636[0] = "&";char * ____BAH_COMPILER_VAR_637 =__Bah_multiple_concat(____BAH_COMPILER_VAR_636, 2);arrElem = ____BAH_COMPILER_VAR_637;

#undef tmpT
}
char * isStruct = "0";
struct cStruct* ts = searchStruct(tt,elems);
char * structLayout = "0";
if ((ts!=null)) {
isStruct = "1";
structLayout = genCompilerVar();
struct variable* ____BAH_COMPILER_VAR_638 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_638->name = "";
____BAH_COMPILER_VAR_638->type = "";
____BAH_COMPILER_VAR_638->constVal = "";
____BAH_COMPILER_VAR_638->from = "";
struct variable* slv = ____BAH_COMPILER_VAR_638;
slv->name = structLayout;
slv->type = "[]reflectElement";

    unsigned int ____BAH_COMPILER_VAR_639 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_639);
    elems->vars->data[____BAH_COMPILER_VAR_639] = slv;
struct rope* dataLayout = rope("");
register long int i = 0;
for (; (i<len(ts->members)); ++i) {
struct structMemb* m = ts->members->data[i];
if ((strcmp(m->type, tt) == 0)) {
struct structMemb* ____BAH_COMPILER_VAR_640 = memoryAlloc(sizeof(struct structMemb));
____BAH_COMPILER_VAR_640->name = "";
____BAH_COMPILER_VAR_640->type = "";
____BAH_COMPILER_VAR_640->constVal = "";
____BAH_COMPILER_VAR_640->from = "";
____BAH_COMPILER_VAR_640->def = "";
struct structMemb* nm = ____BAH_COMPILER_VAR_640;
*nm = *m;
m = nm;
m->type = "ptr";
}
struct Tok ____BAH_COMPILER_VAR_641 = {};
____BAH_COMPILER_VAR_641.cont = "";
____BAH_COMPILER_VAR_641.ogCont = "";
____BAH_COMPILER_VAR_641.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_641.line = 1;
____BAH_COMPILER_VAR_641.begLine = 1;
____BAH_COMPILER_VAR_641.bahType = "";
#define tmpT ____BAH_COMPILER_VAR_641
tmpT.type = TOKEN_TYPE_VAR;
char * sep = "->";
if ((strCount(tt,"*")==0)) {
sep = ".";
}
struct string mCtype = getCType(m->type,elems);
struct string offsetTT = string(tt);
string__replace(&offsetTT,"*","");
char** ____BAH_COMPILER_VAR_642 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_642[8] = "))";____BAH_COMPILER_VAR_642[7] = m->name;____BAH_COMPILER_VAR_642[6] = ", ";____BAH_COMPILER_VAR_642[5] = string__str(&offsetTT);____BAH_COMPILER_VAR_642[4] = ") + offsetof(struct ";____BAH_COMPILER_VAR_642[3] = t.cont;____BAH_COMPILER_VAR_642[2] = "*)((char*)(";____BAH_COMPILER_VAR_642[1] = string__str(&mCtype);____BAH_COMPILER_VAR_642[0] = "(";char * ____BAH_COMPILER_VAR_643 =__Bah_multiple_concat(____BAH_COMPILER_VAR_642, 9);tmpT.cont = ____BAH_COMPILER_VAR_643;
char** ____BAH_COMPILER_VAR_644 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_644[4] = ")";____BAH_COMPILER_VAR_644[3] = m->name;____BAH_COMPILER_VAR_644[2] = ", ";____BAH_COMPILER_VAR_644[1] = string__str(&offsetTT);____BAH_COMPILER_VAR_644[0] = "offsetof(struct ";char * ____BAH_COMPILER_VAR_645 =__Bah_multiple_concat(____BAH_COMPILER_VAR_644, 5);struct Tok rt = parseReflect(tmpT,m->type,elems,true,m->name,____BAH_COMPILER_VAR_645);
char** ____BAH_COMPILER_VAR_646 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_646[5] = ";\n";____BAH_COMPILER_VAR_646[4] = rt.cont;____BAH_COMPILER_VAR_646[3] = "] = ";____BAH_COMPILER_VAR_646[2] = intToStr(i);____BAH_COMPILER_VAR_646[1] = "->data[";____BAH_COMPILER_VAR_646[0] = structLayout;char * ____BAH_COMPILER_VAR_647 =__Bah_multiple_concat(____BAH_COMPILER_VAR_646, 6);dataLayout = rope__add(dataLayout, rope(____BAH_COMPILER_VAR_647));

#undef tmpT
};
char** ____BAH_COMPILER_VAR_648 = alloca(15 * sizeof(char*));____BAH_COMPILER_VAR_648[14] = "->elemSize);\n        ";____BAH_COMPILER_VAR_648[13] = structLayout;____BAH_COMPILER_VAR_648[12] = "->length * ";____BAH_COMPILER_VAR_648[11] = structLayout;____BAH_COMPILER_VAR_648[10] = "->data = memoryAlloc(";____BAH_COMPILER_VAR_648[9] = structLayout;____BAH_COMPILER_VAR_648[8] = ";\n        ";____BAH_COMPILER_VAR_648[7] = intToStr(len(ts->members));____BAH_COMPILER_VAR_648[6] = "->length = ";____BAH_COMPILER_VAR_648[5] = structLayout;____BAH_COMPILER_VAR_648[4] = "->elemSize = sizeof(struct reflectElement);\n        ";____BAH_COMPILER_VAR_648[3] = structLayout;____BAH_COMPILER_VAR_648[2] = " = memoryAlloc(sizeof(array(struct reflectElement)));\n        ";____BAH_COMPILER_VAR_648[1] = structLayout;____BAH_COMPILER_VAR_648[0] = "\n        array(struct reflectElement) * ";char * ____BAH_COMPILER_VAR_649 =__Bah_multiple_concat(____BAH_COMPILER_VAR_648, 15);OUTPUT = rope__add(OUTPUT, rope__add(rope(____BAH_COMPILER_VAR_649), dataLayout));
}
char * amp = "";
if ((strCount(tt,"*")==0)&&(strcmp(tt, "cpstring") != 0)&&(strcmp(tt, "ptr") != 0)&&(parsedPointer==false)) {
amp = "&";
}
struct string name = string(ogName);
if ((hasStructSep(&name)==true)) {
name = splitStructSepAfter(name);
}
struct string cType;
if (strHasPrefix(tt,"function(")) {
cType = string("void*");
}
else {
cType = getCType(tt,elems);
}
if (string__hasPrefix(&cType,"struct ")) {
string__replace(&cType,"*","");
}
if ((cType.length==0)) {
string__set(&cType,"0");
}
struct variable* ____BAH_COMPILER_VAR_650 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_650->name = "";
____BAH_COMPILER_VAR_650->type = "";
____BAH_COMPILER_VAR_650->constVal = "";
____BAH_COMPILER_VAR_650->from = "";
struct variable* rv = ____BAH_COMPILER_VAR_650;
rv->name = genCompilerVar();
rv->type = "reflectElement";

    unsigned int ____BAH_COMPILER_VAR_651 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_651);
    elems->vars->data[____BAH_COMPILER_VAR_651] = rv;
char** ____BAH_COMPILER_VAR_652 = alloca(22 * sizeof(char*));____BAH_COMPILER_VAR_652[21] = ");\n";____BAH_COMPILER_VAR_652[20] = offset;____BAH_COMPILER_VAR_652[19] = ", ";____BAH_COMPILER_VAR_652[18] = structLayout;____BAH_COMPILER_VAR_652[17] = ", ";____BAH_COMPILER_VAR_652[16] = isStruct;____BAH_COMPILER_VAR_652[15] = ", ";____BAH_COMPILER_VAR_652[14] = arrElem;____BAH_COMPILER_VAR_652[13] = ", ";____BAH_COMPILER_VAR_652[12] = isArr;____BAH_COMPILER_VAR_652[11] = "\", ";____BAH_COMPILER_VAR_652[10] = string__str(&name);____BAH_COMPILER_VAR_652[9] = "\", \"";____BAH_COMPILER_VAR_652[8] = tt;____BAH_COMPILER_VAR_652[7] = "), \"";____BAH_COMPILER_VAR_652[6] = string__str(&cType);____BAH_COMPILER_VAR_652[5] = ", sizeof(";____BAH_COMPILER_VAR_652[4] = t.cont;____BAH_COMPILER_VAR_652[3] = amp;____BAH_COMPILER_VAR_652[2] = " = __reflect(";____BAH_COMPILER_VAR_652[1] = rv->name;____BAH_COMPILER_VAR_652[0] = "struct reflectElement ";char * ____BAH_COMPILER_VAR_653 =__Bah_multiple_concat(____BAH_COMPILER_VAR_652, 22);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_653));
t.cont = rv->name;
return t;
};
char * parseArrayDecl(struct variable* v,__BAH_ARR_TYPE_Tok l,long int i,long int max,struct Elems* elems){
long int arrayLength = 0;
struct string arrType = getCType(v->type,elems);
string__trimRight(&arrType,1);
char** ____BAH_COMPILER_VAR_654 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_654[2] = "))";____BAH_COMPILER_VAR_654[1] = string__str(&arrType);____BAH_COMPILER_VAR_654[0] = "memoryAlloc(sizeof(";char * ____BAH_COMPILER_VAR_655 =__Bah_multiple_concat(____BAH_COMPILER_VAR_654, 3);char * code = ____BAH_COMPILER_VAR_655;
string__trimLeft(&arrType,6);
string__trimRight(&arrType,1);
char * elemTypeStr = string__str(&arrType);
if ((i+1!=max)) {
++i;
struct Tok nt = l->data[i];
if ((strcmp(nt.cont, "{") != 0)) {
throwErr(&l->data[i+1],"{TOKEN} not expected after array initialization.");
}
struct string elemBahType = string(v->type);
string__trimLeft(&elemBahType,2);
char * elemBahTypeStr = string__str(&elemBahType);
i = i+1;
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
while ((i<max)) {

    unsigned int ____BAH_COMPILER_VAR_656 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_656);
    memory->data[____BAH_COMPILER_VAR_656] = l->data[i];
i = i+1;
};
memory = prePross(memory,(lineType)-1,elems);
i = 0;
while ((i<len(memory))) {
struct Tok t = memory->data[i];
if ((strcmp(t.cont, "{") == 0)) {
long int j = i-1;
long int nbBraces = 0;
for (; (i<len(memory)); ++i) {
struct Tok tmpT = memory->data[i];
if ((strcmp(tmpT.cont, "{") == 0)) {
++nbBraces;
}
else if ((strcmp(tmpT.cont, "}") == 0)) {
--nbBraces;
}
if ((nbBraces==0)) {
break;
}
};
struct variable* ____BAH_COMPILER_VAR_657 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_657->name = "";
____BAH_COMPILER_VAR_657->type = "";
____BAH_COMPILER_VAR_657->constVal = "";
____BAH_COMPILER_VAR_657->from = "";
struct variable* tmpV = ____BAH_COMPILER_VAR_657;
tmpV->name = genCompilerVar();
struct string elemType = string(v->type);
string__trimLeft(&elemType,2);
tmpV->type = string__str(&elemType);

    unsigned int ____BAH_COMPILER_VAR_658 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_658);
    elems->vars->data[____BAH_COMPILER_VAR_658] = tmpV;
char * oldNL = NEXT_LINE;
NEXT_LINE = "";
char * innerCode = parseArrayDecl(tmpV,memory,j,i+1,elems);
char * ____BAH_COMPILER_VAR_659 =string__str(&elemType);struct string cType = getCType(____BAH_COMPILER_VAR_659,elems);
char** ____BAH_COMPILER_VAR_660 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_660[8] = "\n                ";____BAH_COMPILER_VAR_660[7] = NEXT_LINE;____BAH_COMPILER_VAR_660[6] = ";\n                ";____BAH_COMPILER_VAR_660[5] = innerCode;____BAH_COMPILER_VAR_660[4] = " = ";____BAH_COMPILER_VAR_660[3] = tmpV->name;____BAH_COMPILER_VAR_660[2] = ") * ";____BAH_COMPILER_VAR_660[1] = string__str(&cType);____BAH_COMPILER_VAR_660[0] = "\n                array(";char * ____BAH_COMPILER_VAR_661 =__Bah_multiple_concat(____BAH_COMPILER_VAR_660, 9);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_661));
NEXT_LINE = oldNL;
struct Tok ____BAH_COMPILER_VAR_662 = {};
____BAH_COMPILER_VAR_662.cont = "";
____BAH_COMPILER_VAR_662.ogCont = "";
____BAH_COMPILER_VAR_662.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_662.line = 1;
____BAH_COMPILER_VAR_662.begLine = 1;
____BAH_COMPILER_VAR_662.bahType = "";
____BAH_COMPILER_VAR_662.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_662.cont = tmpV->name;
____BAH_COMPILER_VAR_662.bahType = string__str(&elemType);
____BAH_COMPILER_VAR_662.isValue = true;
t = ____BAH_COMPILER_VAR_662;
}
char * tt = getTypeFromToken(&t,true,elems);
if ((compTypes(tt,elemBahTypeStr)==false)) {
char** ____BAH_COMPILER_VAR_663 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_663[3] = elemBahTypeStr;____BAH_COMPILER_VAR_663[2] = ") as ";____BAH_COMPILER_VAR_663[1] = tt;____BAH_COMPILER_VAR_663[0] = "Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_664 =__Bah_multiple_concat(____BAH_COMPILER_VAR_663, 4);throwErr(&t,____BAH_COMPILER_VAR_664);
}
char * strArrayLength = intToStr(arrayLength);
arrayLength = arrayLength+1;
char** ____BAH_COMPILER_VAR_665 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_665[6] = ";\n";____BAH_COMPILER_VAR_665[5] = t.cont;____BAH_COMPILER_VAR_665[4] = "] = ";____BAH_COMPILER_VAR_665[3] = strArrayLength;____BAH_COMPILER_VAR_665[2] = "->data[";____BAH_COMPILER_VAR_665[1] = v->name;____BAH_COMPILER_VAR_665[0] = NEXT_LINE;char * ____BAH_COMPILER_VAR_666 =__Bah_multiple_concat(____BAH_COMPILER_VAR_665, 7);NEXT_LINE = ____BAH_COMPILER_VAR_666;
++i;
t = memory->data[i];
if ((strcmp(t.cont, ",") != 0)) {
if ((strcmp(t.cont, "}") == 0)) {
long int allocLength = arrayLength;
if ((allocLength>50)) {
long int modAllocAmm = allocLength%50;
allocLength = allocLength+modAllocAmm;
}
else {
allocLength = 50;
}
char * allocLengthStr = intToStr(allocLength);
char** ____BAH_COMPILER_VAR_667 = alloca(11 * sizeof(char*));____BAH_COMPILER_VAR_667[10] = NEXT_LINE;____BAH_COMPILER_VAR_667[9] = ";\n";____BAH_COMPILER_VAR_667[8] = allocLengthStr;____BAH_COMPILER_VAR_667[7] = "->realLength = ";____BAH_COMPILER_VAR_667[6] = v->name;____BAH_COMPILER_VAR_667[5] = ");\n                    ";____BAH_COMPILER_VAR_667[4] = allocLengthStr;____BAH_COMPILER_VAR_667[3] = ") * ";____BAH_COMPILER_VAR_667[2] = elemTypeStr;____BAH_COMPILER_VAR_667[1] = "->data = memoryAlloc(sizeof(";____BAH_COMPILER_VAR_667[0] = v->name;char * ____BAH_COMPILER_VAR_668 =__Bah_multiple_concat(____BAH_COMPILER_VAR_667, 11);NEXT_LINE = ____BAH_COMPILER_VAR_668;
break;
}
else {
throwErr(&t,"Expected ',' got {TOKEN}.");
}
}
i = i+1;
};
}
char * strArrayLength = intToStr(arrayLength);
char** ____BAH_COMPILER_VAR_669 = alloca(10 * sizeof(char*));____BAH_COMPILER_VAR_669[9] = NEXT_LINE;____BAH_COMPILER_VAR_669[8] = ");\n";____BAH_COMPILER_VAR_669[7] = elemTypeStr;____BAH_COMPILER_VAR_669[6] = "->elemSize = sizeof(";____BAH_COMPILER_VAR_669[5] = v->name;____BAH_COMPILER_VAR_669[4] = ";\n";____BAH_COMPILER_VAR_669[3] = strArrayLength;____BAH_COMPILER_VAR_669[2] = "->length = ";____BAH_COMPILER_VAR_669[1] = v->name;____BAH_COMPILER_VAR_669[0] = "\n";char * ____BAH_COMPILER_VAR_670 =__Bah_multiple_concat(____BAH_COMPILER_VAR_669, 10);NEXT_LINE = ____BAH_COMPILER_VAR_670;
return code;
};
array(char *)* equalsTokens;
void parseVar(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
struct Tok ft = l->data[0];
if ((ft.isFunc==true)) {
if ((len(l)>1)) {
throwErr(&l->data[len(l)-1],"Not expecting {TOKEN} after function call.");
}
ft = l->data[0];
char parsed = true;
char** ____BAH_COMPILER_VAR_671 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_671[1] = ";\n";____BAH_COMPILER_VAR_671[0] = ft.cont;char * ____BAH_COMPILER_VAR_672 =__Bah_multiple_concat(____BAH_COMPILER_VAR_671, 2);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_672));
return;
}
l = parseStructType(l,(lineType)-1,elems);
char isEqual = false;
char toVar = false;
char isPointedVar = false;
char isStruct = false;
char * currentType = "";
char needsDefine = false;
ft = l->data[0];
struct variable* v = searchVar(ft.cont,elems);
char exists = true;
char * ogName= null;
if ((v==null)) {
exists = false;
struct variable* ____BAH_COMPILER_VAR_673 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_673->name = "";
____BAH_COMPILER_VAR_673->type = "";
____BAH_COMPILER_VAR_673->constVal = "";
____BAH_COMPILER_VAR_673->from = "";
v = ____BAH_COMPILER_VAR_673;
v->name = ft.cont;
v->type = "";
}
else {
ogName = v->name;
}
if ((v->isConst==true)) {
throwErr(&ft,"Cannot set the value of const {TOKEN}.");
}
char * code = "";
if ((exists==true)&&isGlobal()) {
throwErr(&ft,"Cannot redeclare global variable {TOKEN}.");
}
if ((len(l)==1)) {
struct Tok t = l->data[0];
struct string c = string(t.cont);
string__trimLeft(&c,2);
char * ____BAH_COMPILER_VAR_674 =string__str(&c);v = searchVar(____BAH_COMPILER_VAR_674,elems);
if ((v==null)) {
throwErr(&t,"Cannot increase/decrease not declared variable {TOKEN}.");
}
char** ____BAH_COMPILER_VAR_675 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_675[1] = ";\n";____BAH_COMPILER_VAR_675[0] = t.cont;char * ____BAH_COMPILER_VAR_676 =__Bah_multiple_concat(____BAH_COMPILER_VAR_675, 2);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_676));
return;
}
if ((len(l)<2)) {
throwErr(&ft,"Missing '=' after {TOKEN}.");
}
struct Tok operT = l->data[1];

        char ____BAH_COMPILER_VAR_677 = 0;
        for(int i=equalsTokens->length-1; i!=-1;i--) {
            if (equalsTokens->data[i] != 0 && strcmp(equalsTokens->data[i], operT.cont) == 0) {
                ____BAH_COMPILER_VAR_677=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_677&&(strcmp(operT.cont, "=") != 0)) {
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 1;
nl->elemSize = sizeof(struct Tok);
nl->data = memoryAlloc(sizeof(struct Tok) * 50);
                    nl->realLength = 50;
nl->data[0] = l->data[0];
if ((2==len(l))) {
throwErr(&operT,"Cannot use {TOKEN} on nothing.");
}
struct string oper = string(operT.cont);
string__trimRight(&oper,1);
struct Tok operTok = operT;
operTok.cont = string__str(&oper);
array(struct Tok)* tmpL = memoryAlloc(sizeof(array(struct Tok)));

tmpL->length = 3;
tmpL->elemSize = sizeof(struct Tok);
tmpL->data = memoryAlloc(sizeof(struct Tok) * 50);
                    tmpL->realLength = 50;
tmpL->data[0] = ft;
tmpL->data[1] = operTok;
tmpL->data[2] = l->data[2];
tmpL = prePross(tmpL,LINE_TYPE_VAR,elems);
operT.cont = "=";

    unsigned int ____BAH_COMPILER_VAR_678 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_678);
    nl->data[____BAH_COMPILER_VAR_678] = operT;
register long int j = 0;
for (; (j<len(tmpL)); ++j) {

    unsigned int ____BAH_COMPILER_VAR_679 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_679);
    nl->data[____BAH_COMPILER_VAR_679] = tmpL->data[j];
};
l = nl;
}
register long int i = 1;
while ((i<len(l))) {
struct Tok t = l->data[i];
if ((t.type==TOKEN_TYPE_SYNTAX)) {
if ((strcmp(t.cont, "=") == 0)) {
if ((strlen(currentType)>0)) {
struct string sct = string(currentType);
string__replace(&sct," ","");
v->type = string__str(&sct);
}
isEqual = true;
i = i+1;
continue;
}
}
if ((isEqual==false)) {
char** ____BAH_COMPILER_VAR_680 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_680[1] = t.cont;____BAH_COMPILER_VAR_680[0] = currentType;char * ____BAH_COMPILER_VAR_681 =__Bah_multiple_concat(____BAH_COMPILER_VAR_680, 2);currentType = ____BAH_COMPILER_VAR_681;
}
else {
if ((t.isEqual==true)&&(exists==false)&&(isGlobal()==false)) {
needsDefine = true;
v->canBeNull = false;
}
if ((strcmp(t.cont, "chan") == 0)) {
if ((i>=len(l))) {
throwErr(&t,"Cannot declare a {TOKEN} without a type (chan <type>).");
}
++i;
struct Tok nt = l->data[i];
char** ____BAH_COMPILER_VAR_682 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_682[1] = nt.cont;____BAH_COMPILER_VAR_682[0] = "chan:";char * ____BAH_COMPILER_VAR_683 =__Bah_multiple_concat(____BAH_COMPILER_VAR_682, 2);v->type = ____BAH_COMPILER_VAR_683;
code = "channel()";
if ((i+1!=len(l))) {
struct Tok errT = l->data[i+1];
throwErr(&errT,"{TOKEN} not expected after channel declaration.");
}
break;
}
else if ((strcmp(t.cont, "map") == 0)) {
if ((i>=len(l))) {
throwErr(&t,"Cannot declare a {TOKEN} without a type (map <type>).");
}
++i;
struct Tok nt = l->data[i];
char** ____BAH_COMPILER_VAR_684 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_684[1] = nt.cont;____BAH_COMPILER_VAR_684[0] = "map:";char * ____BAH_COMPILER_VAR_685 =__Bah_multiple_concat(____BAH_COMPILER_VAR_684, 2);v->type = ____BAH_COMPILER_VAR_685;
code = "mapWrapper()";
if ((i+1!=len(l))) {
struct Tok errT = l->data[i+1];
throwErr(&errT,"{TOKEN} not expected after map declaration.");
}
break;
}
else if ((strcmp(t.cont, "buffer") == 0)) {
if ((i>=len(l))) {
throwErr(&t,"Cannot declare a {TOKEN} without a length (buffer <length>).");
}
++i;
struct Tok nt = l->data[i];
if ((nt.type!=TOKEN_TYPE_INT)) {
throwErr(&nt,"Expected buffer length, not {TOKEN}.");
}
char** ____BAH_COMPILER_VAR_686 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_686[1] = nt.cont;____BAH_COMPILER_VAR_686[0] = "buffer:";char * ____BAH_COMPILER_VAR_687 =__Bah_multiple_concat(____BAH_COMPILER_VAR_686, 2);v->type = ____BAH_COMPILER_VAR_687;
struct variable* ____BAH_COMPILER_VAR_688 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_688->name = "";
____BAH_COMPILER_VAR_688->type = "";
____BAH_COMPILER_VAR_688->constVal = "";
____BAH_COMPILER_VAR_688->from = "";
struct variable* av = ____BAH_COMPILER_VAR_688;
av->type = "char*";
av->name = genCompilerVar();

    unsigned int ____BAH_COMPILER_VAR_689 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_689);
    elems->vars->data[____BAH_COMPILER_VAR_689] = av;
struct string cType = getCType(av->type,elems);
char** ____BAH_COMPILER_VAR_690 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_690[4] = "];";____BAH_COMPILER_VAR_690[3] = nt.cont;____BAH_COMPILER_VAR_690[2] = "[";____BAH_COMPILER_VAR_690[1] = av->name;____BAH_COMPILER_VAR_690[0] = "char ";char * ____BAH_COMPILER_VAR_691 =__Bah_multiple_concat(____BAH_COMPILER_VAR_690, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_691));
code = av->name;
if ((i+1!=len(l))) {
struct Tok errT = l->data[i+1];
throwErr(&errT,"{TOKEN} not expected after buffer declaration.");
}
break;
}
char * tp = getTypeFromToken(&t,true,elems);

                struct string ____BAH_COMPILER_VAR_692 = string(compilerState.currentDir);
                if ((isUnsafe==false)&&(string__hasPrefix(&____BAH_COMPILER_VAR_692,BAH_DIR)==false)&&isRCPpointerType(tp)) {
if ((strcmp(t.cont, "null") == 0)||(tp[strlen(tp)-1]==33)) {
if ((exists==true)) {
struct variable* rv = getRealVar(v->name,elems);
if ((rv!=null)) {
rv->canBeNull = true;
}
}
else {
v->canBeNull = true;
}
}
else if ((t.type==TOKEN_TYPE_VAR)) {
struct variable* tv = searchVar(t.cont,elems);
if ((tv!=null)) {
if ((exists==true)&&(tv->canBeNull==false)) {
if (canChangeNullState(v,elems)) {
struct variable* rv = getRealVar(v->name,elems);
if ((rv!=null)) {
rv->canBeNull = false;
}
}
}
else {
v->canBeNull = tv->canBeNull;
}
}
}
else if ((t.isFunc==true)) {
struct func* fn = searchFuncByToken(&t,elems);
if ((fn!=null)&&(fn->returns!=null)) {
if ((fn->returns->canBeNull==true)) {
v->canBeNull = true;
}
else {
if ((exists==true)) {
if (canChangeNullState(v,elems)) {
v->canBeNull = false;
}
}
else {
v->canBeNull = false;
}
}
}
}
else {
if ((exists==true)) {
if (canChangeNullState(v,elems)) {
struct variable* rv = getRealVar(v->name,elems);
if ((rv!=null)) {
rv->canBeNull = false;
}
}
}
else {
v->canBeNull = false;
}
}
}
if ((exists==true)) {
if ((compTypes(tp,v->type)==false)) {
char** ____BAH_COMPILER_VAR_693 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_693[4] = ".";____BAH_COMPILER_VAR_693[3] = v->type;____BAH_COMPILER_VAR_693[2] = ") as ";____BAH_COMPILER_VAR_693[1] = tp;____BAH_COMPILER_VAR_693[0] = "Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_694 =__Bah_multiple_concat(____BAH_COMPILER_VAR_693, 5);throwErr(&t,____BAH_COMPILER_VAR_694);
}
}
else {
if ((strcmp(currentType, "") == 0)) {
if ((strcmp(v->type, "") == 0)) {
v->type = tp;
}
else {
if ((compTypes(tp,v->type)==false)) {
char** ____BAH_COMPILER_VAR_695 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_695[4] = ".";____BAH_COMPILER_VAR_695[3] = v->type;____BAH_COMPILER_VAR_695[2] = ") as ";____BAH_COMPILER_VAR_695[1] = tp;____BAH_COMPILER_VAR_695[0] = "Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_696 =__Bah_multiple_concat(____BAH_COMPILER_VAR_695, 5);throwErr(&t,____BAH_COMPILER_VAR_696);
}
}
}
}
if ((strcmp(t.cont, "") != 0)&&(strHasPrefix(t.cont,"{")==false)) {
char** ____BAH_COMPILER_VAR_697 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_697[1] = t.cont;____BAH_COMPILER_VAR_697[0] = code;char * ____BAH_COMPILER_VAR_698 =__Bah_multiple_concat(____BAH_COMPILER_VAR_697, 2);code = ____BAH_COMPILER_VAR_698;
if ((t.isOper==false)&&(RCPavailable()==true)) {
struct variable* iv = searchVar(t.cont,elems);
if ((iv!=null)&&(iv->isConst==false)) {
toVar = true;
isPointedVar = strHasPrefix(t.cont,"&");
struct cStruct* s = searchStruct(iv->type,elems);
if ((s!=null)&&(strCount(iv->type,"*")==0)&&(s->isBinding==false)) {
if ((strCount(iv->name,"*")==0)) {
char** ____BAH_COMPILER_VAR_699 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_699[5] = "), 0)";____BAH_COMPILER_VAR_699[4] = iv->name;____BAH_COMPILER_VAR_699[3] = ", sizeof(";____BAH_COMPILER_VAR_699[2] = iv->name;____BAH_COMPILER_VAR_699[1] = "; RCP_scanStack(&";____BAH_COMPILER_VAR_699[0] = code;char * ____BAH_COMPILER_VAR_700 =__Bah_multiple_concat(____BAH_COMPILER_VAR_699, 6);code = ____BAH_COMPILER_VAR_700;
}
else {
struct string ivn = string(iv->name);
if ((string__count(&ivn,"*")>0)) {
string__replace(&ivn,"*","");
char** ____BAH_COMPILER_VAR_701 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_701[4] = "), 0)";____BAH_COMPILER_VAR_701[3] = iv->name;____BAH_COMPILER_VAR_701[2] = ", sizeof(";____BAH_COMPILER_VAR_701[1] = string__str(&ivn);____BAH_COMPILER_VAR_701[0] = "; RCP_scanStack(";char * ____BAH_COMPILER_VAR_702 =__Bah_multiple_concat(____BAH_COMPILER_VAR_701, 5);char** ____BAH_COMPILER_VAR_703 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_703[1] = ____BAH_COMPILER_VAR_702;____BAH_COMPILER_VAR_703[0] = code;char * ____BAH_COMPILER_VAR_704 =__Bah_multiple_concat(____BAH_COMPILER_VAR_703, 2);code = ____BAH_COMPILER_VAR_704;
}
else {
char** ____BAH_COMPILER_VAR_705 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_705[3] = ")";____BAH_COMPILER_VAR_705[2] = iv->name;____BAH_COMPILER_VAR_705[1] = "; RCP_incr(";____BAH_COMPILER_VAR_705[0] = code;char * ____BAH_COMPILER_VAR_706 =__Bah_multiple_concat(____BAH_COMPILER_VAR_705, 4);code = ____BAH_COMPILER_VAR_706;
}
}
}
}
}
break;
}
if (strHasPrefix(v->type,"[]")) {
code = parseArrayDecl(v,l,i,len(l),elems);
break;
}
isStruct = true;
if ((i+1!=len(l))) {
throwErr(&l->data[i+1],"{TOKEN} not expected after struct initialization.");
}
char** ____BAH_COMPILER_VAR_707 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_707[1] = t.cont;____BAH_COMPILER_VAR_707[0] = code;char * ____BAH_COMPILER_VAR_708 =__Bah_multiple_concat(____BAH_COMPILER_VAR_707, 2);code = ____BAH_COMPILER_VAR_708;
}
++i;
};
if ((exists==true)) {
v->lastSet = elems;
if ((ft.parent!=null)) {
ft.parent->lastSet = elems;
}
if ((currentFn!=null)) {

                struct string ____BAH_COMPILER_VAR_709 = string(v->name);
                if ((strcmp(v->name, "this") == 0)||string__hasPrefix(&____BAH_COMPILER_VAR_709,"this->")) {
currentFn->isMut = true;
}
}
if ((strlen(code)==0)) {
throwErr(&ft,"Cannot re-declare {TOKEN}.");
}
if ((strlen(currentType)>0)) {
struct Tok st = l->data[1];
char** ____BAH_COMPILER_VAR_710 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_710[2] = "' to {TOKEN}.";____BAH_COMPILER_VAR_710[1] = ft.cont;____BAH_COMPILER_VAR_710[0] = "Cannot change the type of already declared var '";char * ____BAH_COMPILER_VAR_711 =__Bah_multiple_concat(____BAH_COMPILER_VAR_710, 3);throwErr(&st,____BAH_COMPILER_VAR_711);
}
char * preCode = "";
char * val = code;
if ((isStruct==false)) {
if (isRCPpointerType(v->type)&&(isPointedVar==false)&&(RCPavailable()==true)) {
struct string cType = getCType(v->type,elems);
if ((toVar==true)) {
if ((RCPselfRef(v)==false)) {
char** ____BAH_COMPILER_VAR_712 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_712[8] = ")";____BAH_COMPILER_VAR_712[7] = code;____BAH_COMPILER_VAR_712[6] = "*)RCP_incrIL(&";____BAH_COMPILER_VAR_712[5] = string__str(&cType);____BAH_COMPILER_VAR_712[4] = ") = *(";____BAH_COMPILER_VAR_712[3] = v->name;____BAH_COMPILER_VAR_712[2] = "*)RCP_decrIL(&";____BAH_COMPILER_VAR_712[1] = string__str(&cType);____BAH_COMPILER_VAR_712[0] = "*(";char * ____BAH_COMPILER_VAR_713 =__Bah_multiple_concat(____BAH_COMPILER_VAR_712, 9);code = ____BAH_COMPILER_VAR_713;
}
else {
struct variable* ____BAH_COMPILER_VAR_714 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_714->name = "";
____BAH_COMPILER_VAR_714->type = "";
____BAH_COMPILER_VAR_714->constVal = "";
____BAH_COMPILER_VAR_714->from = "";
struct variable* tmpV = ____BAH_COMPILER_VAR_714;
tmpV->name = genCompilerVar();
tmpV->type = v->type;
struct rope* dv = decrVar(tmpV,elems);
char** ____BAH_COMPILER_VAR_715 = alloca(13 * sizeof(char*));____BAH_COMPILER_VAR_715[12] = rope__toStr(dv);____BAH_COMPILER_VAR_715[11] = ");";____BAH_COMPILER_VAR_715[10] = code;____BAH_COMPILER_VAR_715[9] = "*)RCP_incrIL(&";____BAH_COMPILER_VAR_715[8] = string__str(&cType);____BAH_COMPILER_VAR_715[7] = " = *(";____BAH_COMPILER_VAR_715[6] = v->name;____BAH_COMPILER_VAR_715[5] = "; ";____BAH_COMPILER_VAR_715[4] = v->name;____BAH_COMPILER_VAR_715[3] = " = ";____BAH_COMPILER_VAR_715[2] = tmpV->name;____BAH_COMPILER_VAR_715[1] = " ";____BAH_COMPILER_VAR_715[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_716 =__Bah_multiple_concat(____BAH_COMPILER_VAR_715, 13);code = ____BAH_COMPILER_VAR_716;
}
}
else {
struct variable* ____BAH_COMPILER_VAR_717 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_717->name = "";
____BAH_COMPILER_VAR_717->type = "";
____BAH_COMPILER_VAR_717->constVal = "";
____BAH_COMPILER_VAR_717->from = "";
struct variable* tmpV = ____BAH_COMPILER_VAR_717;
tmpV->name = genCompilerVar();
tmpV->type = v->type;
struct rope* dv = decrVar(tmpV,elems);
char** ____BAH_COMPILER_VAR_718 = alloca(11 * sizeof(char*));____BAH_COMPILER_VAR_718[10] = rope__toStr(dv);____BAH_COMPILER_VAR_718[9] = ";";____BAH_COMPILER_VAR_718[8] = code;____BAH_COMPILER_VAR_718[7] = " = ";____BAH_COMPILER_VAR_718[6] = v->name;____BAH_COMPILER_VAR_718[5] = "; ";____BAH_COMPILER_VAR_718[4] = v->name;____BAH_COMPILER_VAR_718[3] = " = ";____BAH_COMPILER_VAR_718[2] = tmpV->name;____BAH_COMPILER_VAR_718[1] = " ";____BAH_COMPILER_VAR_718[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_719 =__Bah_multiple_concat(____BAH_COMPILER_VAR_718, 11);code = ____BAH_COMPILER_VAR_719;
}
}
else {
struct cStruct* s = searchStruct(v->type,elems);
if ((s!=null)&&(RCPavailable()==true)&&(RCPselfRef(v)==false)&&(s->isBinding==false)) {
if ((strCount(v->name,"*")==0)) {
char** ____BAH_COMPILER_VAR_720 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_720[4] = "), 1); ";____BAH_COMPILER_VAR_720[3] = v->name;____BAH_COMPILER_VAR_720[2] = ", sizeof(";____BAH_COMPILER_VAR_720[1] = v->name;____BAH_COMPILER_VAR_720[0] = "RCP_scanStack(&";char * ____BAH_COMPILER_VAR_721 =__Bah_multiple_concat(____BAH_COMPILER_VAR_720, 5);preCode = ____BAH_COMPILER_VAR_721;
}
else {
struct string vn = string(v->name);
string__replace(&vn,"*","");
char** ____BAH_COMPILER_VAR_722 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_722[4] = "), 1); ";____BAH_COMPILER_VAR_722[3] = v->name;____BAH_COMPILER_VAR_722[2] = ", sizeof(";____BAH_COMPILER_VAR_722[1] = string__str(&vn);____BAH_COMPILER_VAR_722[0] = "RCP_scanStack(";char * ____BAH_COMPILER_VAR_723 =__Bah_multiple_concat(____BAH_COMPILER_VAR_722, 5);preCode = ____BAH_COMPILER_VAR_723;
}
char** ____BAH_COMPILER_VAR_724 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_724[2] = code;____BAH_COMPILER_VAR_724[1] = " = ";____BAH_COMPILER_VAR_724[0] = v->name;char * ____BAH_COMPILER_VAR_725 =__Bah_multiple_concat(____BAH_COMPILER_VAR_724, 3);code = ____BAH_COMPILER_VAR_725;
}
else {
char** ____BAH_COMPILER_VAR_726 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_726[2] = code;____BAH_COMPILER_VAR_726[1] = " = ";____BAH_COMPILER_VAR_726[0] = v->name;char * ____BAH_COMPILER_VAR_727 =__Bah_multiple_concat(____BAH_COMPILER_VAR_726, 3);code = ____BAH_COMPILER_VAR_727;
}
}
}
else {
strTrim(&code);
if ((strHasPrefix(code,"{")==false)) {
char** ____BAH_COMPILER_VAR_728 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_728[2] = code;____BAH_COMPILER_VAR_728[1] = " = ";____BAH_COMPILER_VAR_728[0] = v->name;char * ____BAH_COMPILER_VAR_729 =__Bah_multiple_concat(____BAH_COMPILER_VAR_728, 3);code = ____BAH_COMPILER_VAR_729;
}
}
if ((v->isArray==true)) {
code = genArrRealloc(v,preCode,val,elems);
}
else {
char** ____BAH_COMPILER_VAR_730 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_730[1] = code;____BAH_COMPILER_VAR_730[0] = preCode;char * ____BAH_COMPILER_VAR_731 =__Bah_multiple_concat(____BAH_COMPILER_VAR_730, 2);code = ____BAH_COMPILER_VAR_731;
}
}
else {
if ((strcmp(currentType, "") != 0)) {
v->type = currentType;
}
if ((strlen(code)==0)) {
v->canBeNull = true;
}
struct string vts = string(v->type);
string__replace(&vts," ","");
v->type = string__str(&vts);
if ((strlen(v->type)==0)) {
throwErr(&ft,"Cannot declare {TOKEN} without a type.");
}
char * vct= null;
if (string__hasPrefix(&vts,"function(")) {
struct func* tmpfn = parseFnType(vts);
struct string tmpfnRetCType = getCType(tmpfn->returns->type,elems);
char * tmpfnArgsCType = "";
register long int j = 0;
while ((j<len(tmpfn->args))) {
struct variable* arg = tmpfn->args->data[j];
struct string ct = getCType(arg->type,elems);
char** ____BAH_COMPILER_VAR_732 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_732[1] = string__str(&ct);____BAH_COMPILER_VAR_732[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_733 =__Bah_multiple_concat(____BAH_COMPILER_VAR_732, 2);tmpfnArgsCType = ____BAH_COMPILER_VAR_733;
j = j+1;
if ((j<len(tmpfn->args))) {
char** ____BAH_COMPILER_VAR_734 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_734[1] = ",";____BAH_COMPILER_VAR_734[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_735 =__Bah_multiple_concat(____BAH_COMPILER_VAR_734, 2);tmpfnArgsCType = ____BAH_COMPILER_VAR_735;
}
};
char** ____BAH_COMPILER_VAR_736 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_736[5] = ")";____BAH_COMPILER_VAR_736[4] = tmpfnArgsCType;____BAH_COMPILER_VAR_736[3] = ")(";____BAH_COMPILER_VAR_736[2] = v->name;____BAH_COMPILER_VAR_736[1] = " (*";____BAH_COMPILER_VAR_736[0] = string__str(&tmpfnRetCType);char * ____BAH_COMPILER_VAR_737 =__Bah_multiple_concat(____BAH_COMPILER_VAR_736, 6);vct = ____BAH_COMPILER_VAR_737;
}
else {
vct = setCType(v,elems);
}
if ((strcmp(code, "") != 0)&&(shouldOnlyDecl==false)) {
if (isRCPpointerType(v->type)&&(RCPavailable()==true)&&(toVar==true)&&(isPointedVar==false)) {
struct string cType = getCType(v->type,elems);
if (isGlobal()) {
char** ____BAH_COMPILER_VAR_738 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_738[5] = ");\n";____BAH_COMPILER_VAR_738[4] = code;____BAH_COMPILER_VAR_738[3] = "*)RCP_incrIL(&";____BAH_COMPILER_VAR_738[2] = string__str(&cType);____BAH_COMPILER_VAR_738[1] = " = *(";____BAH_COMPILER_VAR_738[0] = v->name;char * ____BAH_COMPILER_VAR_739 =__Bah_multiple_concat(____BAH_COMPILER_VAR_738, 6);INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_739));
}
else {
char** ____BAH_COMPILER_VAR_740 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_740[5] = ")";____BAH_COMPILER_VAR_740[4] = code;____BAH_COMPILER_VAR_740[3] = "*)RCP_incrIL(&";____BAH_COMPILER_VAR_740[2] = string__str(&cType);____BAH_COMPILER_VAR_740[1] = " = *(";____BAH_COMPILER_VAR_740[0] = vct;char * ____BAH_COMPILER_VAR_741 =__Bah_multiple_concat(____BAH_COMPILER_VAR_740, 6);code = ____BAH_COMPILER_VAR_741;
}
}
else {
if ((needsDefine==true)) {

    unsigned int ____BAH_COMPILER_VAR_742 = len(elems->defined);
    __Bah_realocate_arr(elems->defined, ____BAH_COMPILER_VAR_742);
    elems->defined->data[____BAH_COMPILER_VAR_742] = v->name;
if (isGlobal()) {
char** ____BAH_COMPILER_VAR_743 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_743[4] = "\n";____BAH_COMPILER_VAR_743[3] = code;____BAH_COMPILER_VAR_743[2] = " ";____BAH_COMPILER_VAR_743[1] = v->name;____BAH_COMPILER_VAR_743[0] = "#define ";char * ____BAH_COMPILER_VAR_744 =__Bah_multiple_concat(____BAH_COMPILER_VAR_743, 5);INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_744));
}
else {
char** ____BAH_COMPILER_VAR_745 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_745[3] = code;____BAH_COMPILER_VAR_745[2] = " ";____BAH_COMPILER_VAR_745[1] = v->name;____BAH_COMPILER_VAR_745[0] = "#define ";char * ____BAH_COMPILER_VAR_746 =__Bah_multiple_concat(____BAH_COMPILER_VAR_745, 4);code = ____BAH_COMPILER_VAR_746;
}
}
else {
if (isGlobal()) {
char** ____BAH_COMPILER_VAR_747 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_747[3] = ";\n";____BAH_COMPILER_VAR_747[2] = code;____BAH_COMPILER_VAR_747[1] = " = ";____BAH_COMPILER_VAR_747[0] = v->name;char * ____BAH_COMPILER_VAR_748 =__Bah_multiple_concat(____BAH_COMPILER_VAR_747, 4);INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_748));
}
else {
char** ____BAH_COMPILER_VAR_749 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_749[2] = code;____BAH_COMPILER_VAR_749[1] = " = ";____BAH_COMPILER_VAR_749[0] = vct;char * ____BAH_COMPILER_VAR_750 =__Bah_multiple_concat(____BAH_COMPILER_VAR_749, 3);code = ____BAH_COMPILER_VAR_750;
}
}
}
}
else {
if (isRCPpointerType(v->type)&&(shouldOnlyDecl==false)) {
char** ____BAH_COMPILER_VAR_751 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_751[1] = "= null";____BAH_COMPILER_VAR_751[0] = vct;char * ____BAH_COMPILER_VAR_752 =__Bah_multiple_concat(____BAH_COMPILER_VAR_751, 2);code = ____BAH_COMPILER_VAR_752;
}
else {
code = vct;
}
}
if ((shouldOnlyDecl==true)) {
char** ____BAH_COMPILER_VAR_753 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_753[1] = vct;____BAH_COMPILER_VAR_753[0] = "extern ";char * ____BAH_COMPILER_VAR_754 =__Bah_multiple_concat(____BAH_COMPILER_VAR_753, 2);vct = ____BAH_COMPILER_VAR_754;
}
if (isGlobal()) {
v->isGlobal = true;
}
else {
v->isGlobal = false;
}
v->declScope = elems;

    unsigned int ____BAH_COMPILER_VAR_755 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_755);
    elems->vars->data[____BAH_COMPILER_VAR_755] = v;
struct variable* ____BAH_COMPILER_VAR_756 = v;
char ** ____BAH_COMPILER_VAR_758 = (char **)((char*)(____BAH_COMPILER_VAR_756) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_759 = __reflect(____BAH_COMPILER_VAR_758, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_760 = (char **)((char*)(____BAH_COMPILER_VAR_756) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_761 = __reflect(____BAH_COMPILER_VAR_760, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_762 = (char*)((char*)(____BAH_COMPILER_VAR_756) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_763 = __reflect(____BAH_COMPILER_VAR_762, sizeof(char), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_764 = (char **)((char*)(____BAH_COMPILER_VAR_756) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_765 = __reflect(____BAH_COMPILER_VAR_764, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_766 = (char*)((char*)(____BAH_COMPILER_VAR_756) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_767 = __reflect(____BAH_COMPILER_VAR_766, sizeof(char), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_768 = (char **)((char*)(____BAH_COMPILER_VAR_756) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_769 = __reflect(____BAH_COMPILER_VAR_768, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
void ** ____BAH_COMPILER_VAR_770 = (void **)((char*)(____BAH_COMPILER_VAR_756) + offsetof(struct variable, declScope));
struct reflectElement ____BAH_COMPILER_VAR_771 = __reflect(____BAH_COMPILER_VAR_770, sizeof(void *), "ptr", "declScope", 0, 0, 0, 0, offsetof(struct variable, declScope));
char* ____BAH_COMPILER_VAR_772 = (char*)((char*)(____BAH_COMPILER_VAR_756) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_773 = __reflect(____BAH_COMPILER_VAR_772, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));
struct rope** ____BAH_COMPILER_VAR_774 = (struct rope**)((char*)(____BAH_COMPILER_VAR_756) + offsetof(struct variable, declRope));
void ** ____BAH_COMPILER_VAR_776 = (void **)((char*)(____BAH_COMPILER_VAR_774) + offsetof(struct rope, left));
struct reflectElement ____BAH_COMPILER_VAR_777 = __reflect(____BAH_COMPILER_VAR_776, sizeof(void *), "ptr", "left", 0, 0, 0, 0, offsetof(struct rope, left));
void ** ____BAH_COMPILER_VAR_778 = (void **)((char*)(____BAH_COMPILER_VAR_774) + offsetof(struct rope, right));
struct reflectElement ____BAH_COMPILER_VAR_779 = __reflect(____BAH_COMPILER_VAR_778, sizeof(void *), "ptr", "right", 0, 0, 0, 0, offsetof(struct rope, right));
char ** ____BAH_COMPILER_VAR_780 = (char **)((char*)(____BAH_COMPILER_VAR_774) + offsetof(struct rope, str));
struct reflectElement ____BAH_COMPILER_VAR_781 = __reflect(____BAH_COMPILER_VAR_780, sizeof(char *), "cpstring", "str", 0, 0, 0, 0, offsetof(struct rope, str));
int* ____BAH_COMPILER_VAR_782 = (int*)((char*)(____BAH_COMPILER_VAR_774) + offsetof(struct rope, lCount));
struct reflectElement ____BAH_COMPILER_VAR_783 = __reflect(____BAH_COMPILER_VAR_782, sizeof(int), "int32", "lCount", 0, 0, 0, 0, offsetof(struct rope, lCount));
int* ____BAH_COMPILER_VAR_784 = (int*)((char*)(____BAH_COMPILER_VAR_774) + offsetof(struct rope, len));
struct reflectElement ____BAH_COMPILER_VAR_785 = __reflect(____BAH_COMPILER_VAR_784, sizeof(int), "int32", "len", 0, 0, 0, 0, offsetof(struct rope, len));
int* ____BAH_COMPILER_VAR_786 = (int*)((char*)(____BAH_COMPILER_VAR_774) + offsetof(struct rope, totalLen));
struct reflectElement ____BAH_COMPILER_VAR_787 = __reflect(____BAH_COMPILER_VAR_786, sizeof(int), "int32", "totalLen", 0, 0, 0, 0, offsetof(struct rope, totalLen));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_775 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_775->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_775->length = 6;
        ____BAH_COMPILER_VAR_775->data = memoryAlloc(____BAH_COMPILER_VAR_775->length * ____BAH_COMPILER_VAR_775->elemSize);
        ____BAH_COMPILER_VAR_775->data[0] = ____BAH_COMPILER_VAR_777;
____BAH_COMPILER_VAR_775->data[1] = ____BAH_COMPILER_VAR_779;
____BAH_COMPILER_VAR_775->data[2] = ____BAH_COMPILER_VAR_781;
____BAH_COMPILER_VAR_775->data[3] = ____BAH_COMPILER_VAR_783;
____BAH_COMPILER_VAR_775->data[4] = ____BAH_COMPILER_VAR_785;
____BAH_COMPILER_VAR_775->data[5] = ____BAH_COMPILER_VAR_787;
struct reflectElement ____BAH_COMPILER_VAR_788 = __reflect(____BAH_COMPILER_VAR_774, sizeof(struct rope), "rope*", "declRope", 0, 0, 1, ____BAH_COMPILER_VAR_775, offsetof(struct variable, declRope));
char* ____BAH_COMPILER_VAR_789 = (char*)((char*)(____BAH_COMPILER_VAR_756) + offsetof(struct variable, canBeNull));
struct reflectElement ____BAH_COMPILER_VAR_790 = __reflect(____BAH_COMPILER_VAR_789, sizeof(char), "bool", "canBeNull", 0, 0, 0, 0, offsetof(struct variable, canBeNull));
char* ____BAH_COMPILER_VAR_791 = (char*)((char*)(____BAH_COMPILER_VAR_756) + offsetof(struct variable, canBeReg));
struct reflectElement ____BAH_COMPILER_VAR_792 = __reflect(____BAH_COMPILER_VAR_791, sizeof(char), "bool", "canBeReg", 0, 0, 0, 0, offsetof(struct variable, canBeReg));
char* ____BAH_COMPILER_VAR_793 = (char*)((char*)(____BAH_COMPILER_VAR_756) + offsetof(struct variable, isReg));
struct reflectElement ____BAH_COMPILER_VAR_794 = __reflect(____BAH_COMPILER_VAR_793, sizeof(char), "bool", "isReg", 0, 0, 0, 0, offsetof(struct variable, isReg));
void ** ____BAH_COMPILER_VAR_795 = (void **)((char*)(____BAH_COMPILER_VAR_756) + offsetof(struct variable, lastSet));
struct reflectElement ____BAH_COMPILER_VAR_796 = __reflect(____BAH_COMPILER_VAR_795, sizeof(void *), "ptr", "lastSet", 0, 0, 0, 0, offsetof(struct variable, lastSet));
char* ____BAH_COMPILER_VAR_797 = (char*)((char*)(____BAH_COMPILER_VAR_756) + offsetof(struct variable, isArg));
struct reflectElement ____BAH_COMPILER_VAR_798 = __reflect(____BAH_COMPILER_VAR_797, sizeof(char), "bool", "isArg", 0, 0, 0, 0, offsetof(struct variable, isArg));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_757 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_757->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_757->length = 14;
        ____BAH_COMPILER_VAR_757->data = memoryAlloc(____BAH_COMPILER_VAR_757->length * ____BAH_COMPILER_VAR_757->elemSize);
        ____BAH_COMPILER_VAR_757->data[0] = ____BAH_COMPILER_VAR_759;
____BAH_COMPILER_VAR_757->data[1] = ____BAH_COMPILER_VAR_761;
____BAH_COMPILER_VAR_757->data[2] = ____BAH_COMPILER_VAR_763;
____BAH_COMPILER_VAR_757->data[3] = ____BAH_COMPILER_VAR_765;
____BAH_COMPILER_VAR_757->data[4] = ____BAH_COMPILER_VAR_767;
____BAH_COMPILER_VAR_757->data[5] = ____BAH_COMPILER_VAR_769;
____BAH_COMPILER_VAR_757->data[6] = ____BAH_COMPILER_VAR_771;
____BAH_COMPILER_VAR_757->data[7] = ____BAH_COMPILER_VAR_773;
____BAH_COMPILER_VAR_757->data[8] = ____BAH_COMPILER_VAR_788;
____BAH_COMPILER_VAR_757->data[9] = ____BAH_COMPILER_VAR_790;
____BAH_COMPILER_VAR_757->data[10] = ____BAH_COMPILER_VAR_792;
____BAH_COMPILER_VAR_757->data[11] = ____BAH_COMPILER_VAR_794;
____BAH_COMPILER_VAR_757->data[12] = ____BAH_COMPILER_VAR_796;
____BAH_COMPILER_VAR_757->data[13] = ____BAH_COMPILER_VAR_798;
struct reflectElement ____BAH_COMPILER_VAR_799 = __reflect(____BAH_COMPILER_VAR_756, sizeof(struct variable), "variable*", "v", 0, 0, 1, ____BAH_COMPILER_VAR_757, 0);
debugPrint("var_declaration",ft.line,____BAH_COMPILER_VAR_799);
if (isGlobal()) {
char** ____BAH_COMPILER_VAR_800 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_800[1] = ";\n";____BAH_COMPILER_VAR_800[0] = vct;char * ____BAH_COMPILER_VAR_801 =__Bah_multiple_concat(____BAH_COMPILER_VAR_800, 2);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_801));
}
}
if (isGlobal()) {
if ((isSubObject==false)) {
INIT = rope__add(INIT, rope(NEXT_LINE));
}
NEXT_LINE = "";
}
else {
if ((needsDefine==true)) {
char** ____BAH_COMPILER_VAR_802 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_802[1] = "\n";____BAH_COMPILER_VAR_802[0] = code;char * ____BAH_COMPILER_VAR_803 =__Bah_multiple_concat(____BAH_COMPILER_VAR_802, 2);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_803));
}
else {
char** ____BAH_COMPILER_VAR_804 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_804[1] = ";\n";____BAH_COMPILER_VAR_804[0] = code;char * ____BAH_COMPILER_VAR_805 =__Bah_multiple_concat(____BAH_COMPILER_VAR_804, 2);struct rope* declR = rope(____BAH_COMPILER_VAR_805);
if ((exists==false)) {
v->declRope = declR;
v->canBeReg = true;
}
OUTPUT = rope__add(OUTPUT, declR);
}
}
};
char * getCfunctionType(struct string* cfrt,char * elemName,struct Elems* elems){
struct func* tmpfn = parseFnType(*cfrt);
struct string tmpfnRetCType = getCType(tmpfn->returns->type,elems);
char * tmpfnArgsCType = "";
register long int j = 0;
while ((j<len(tmpfn->args))) {
struct variable* arg = tmpfn->args->data[j];
struct string ct = getCType(arg->type,elems);
char** ____BAH_COMPILER_VAR_806 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_806[1] = string__str(&ct);____BAH_COMPILER_VAR_806[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_807 =__Bah_multiple_concat(____BAH_COMPILER_VAR_806, 2);tmpfnArgsCType = ____BAH_COMPILER_VAR_807;
j = j+1;
if ((j<len(tmpfn->args))) {
char** ____BAH_COMPILER_VAR_808 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_808[1] = ",";____BAH_COMPILER_VAR_808[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_809 =__Bah_multiple_concat(____BAH_COMPILER_VAR_808, 2);tmpfnArgsCType = ____BAH_COMPILER_VAR_809;
}
};
char** ____BAH_COMPILER_VAR_810 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_810[5] = ")";____BAH_COMPILER_VAR_810[4] = tmpfnArgsCType;____BAH_COMPILER_VAR_810[3] = ")(";____BAH_COMPILER_VAR_810[2] = elemName;____BAH_COMPILER_VAR_810[1] = " (*";____BAH_COMPILER_VAR_810[0] = string__str(&tmpfnRetCType);char * ____BAH_COMPILER_VAR_811 =__Bah_multiple_concat(____BAH_COMPILER_VAR_810, 6);return ____BAH_COMPILER_VAR_811;
};
char * parseFnHeader(char * prev,__BAH_ARR_TYPE_Tok l,long int* i,struct func* fn,struct Elems* elems){
register long int j = *i;
struct Tok ft = l->data[j];
char * tpdf = "";
if ((ft.type!=TOKEN_TYPE_VAR)) {
throwErr(&ft,"Cannot use {TOKEN} as function name.");
}
char** ____BAH_COMPILER_VAR_812 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_812[1] = ft.cont;____BAH_COMPILER_VAR_812[0] = prev;char * ____BAH_COMPILER_VAR_813 =__Bah_multiple_concat(____BAH_COMPILER_VAR_812, 2);fn->name = ____BAH_COMPILER_VAR_813;
array(struct variable*)* arguments = memoryAlloc(sizeof(array(struct variable*)));

arguments->length = 0;
arguments->elemSize = sizeof(struct variable*);
char** ____BAH_COMPILER_VAR_814 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_814[1] = "(";____BAH_COMPILER_VAR_814[0] = fn->name;char * ____BAH_COMPILER_VAR_815 =__Bah_multiple_concat(____BAH_COMPILER_VAR_814, 2);char * code = ____BAH_COMPILER_VAR_815;
j = j+2;
struct Tok t = l->data[j];
if ((strcmp(t.cont, ")") != 0)) {
while ((j<len(l))) {
t = l->data[j];
if ((t.type!=TOKEN_TYPE_VAR)) {
throwErr(&t,"Cannot use {TOKEN} as argument name.");
}
char * argName = t.cont;
j = j+1;
if ((j>=len(l))) {
throwErr(&t,"Cannot declare argument {TOKEN} without a type.");
}
t = l->data[j];
char * argType = t.cont;
j = j+1;
char isComa = false;
long int nbPars = 1;
while ((j<len(l))) {
t = l->data[j];
isComa = false;
if ((strcmp(t.cont, ",") != 0)) {
if ((strcmp(t.cont, "(") == 0)) {
nbPars = nbPars+1;
}
else if ((strcmp(t.cont, ")") == 0)) {
nbPars = nbPars-1;
}
if ((strcmp(t.cont, ")") == 0)&&(nbPars==0)) {
break;
}
else {
char** ____BAH_COMPILER_VAR_816 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_816[1] = t.cont;____BAH_COMPILER_VAR_816[0] = argType;char * ____BAH_COMPILER_VAR_817 =__Bah_multiple_concat(____BAH_COMPILER_VAR_816, 2);argType = ____BAH_COMPILER_VAR_817;
}
}
else {
isComa = true;
break;
}
j = j+1;
};
struct variable* ____BAH_COMPILER_VAR_818 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_818->name = "";
____BAH_COMPILER_VAR_818->type = "";
____BAH_COMPILER_VAR_818->constVal = "";
____BAH_COMPILER_VAR_818->from = "";
struct variable* argument = ____BAH_COMPILER_VAR_818;
argument->name = argName;
argument->type = argType;

    unsigned int ____BAH_COMPILER_VAR_819 = len(arguments);
    __Bah_realocate_arr(arguments, ____BAH_COMPILER_VAR_819);
    arguments->data[____BAH_COMPILER_VAR_819] = argument;
struct string argCType = getCType(argType,elems);
struct string cfrt = string(argType);
char * newArgType = string__str(&argCType);
if ((string__hasPrefix(&cfrt,"[]")==1)) {
string__trimLeft(&cfrt,2);
if (string__hasSuffix(&cfrt,"*")) {
long int nbast = string__count(&cfrt,"*");
string__trimRight(&cfrt,nbast);
}
char** ____BAH_COMPILER_VAR_820 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_820[1] = string__str(&cfrt);____BAH_COMPILER_VAR_820[0] = "__BAH_ARR_TYPE_";char * ____BAH_COMPILER_VAR_821 =__Bah_multiple_concat(____BAH_COMPILER_VAR_820, 2);newArgType = ____BAH_COMPILER_VAR_821;
array(char *)* csatd = compilerState.arrTypesDecl;
if ((inArrayStr(newArgType,csatd)==false)) {

    unsigned int ____BAH_COMPILER_VAR_822 = len(csatd);
    __Bah_realocate_arr(csatd, ____BAH_COMPILER_VAR_822);
    csatd->data[____BAH_COMPILER_VAR_822] = newArgType;
char** ____BAH_COMPILER_VAR_823 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_823[5] = ";\n";____BAH_COMPILER_VAR_823[4] = newArgType;____BAH_COMPILER_VAR_823[3] = " ";____BAH_COMPILER_VAR_823[2] = string__str(&argCType);____BAH_COMPILER_VAR_823[1] = "typedef ";____BAH_COMPILER_VAR_823[0] = tpdf;char * ____BAH_COMPILER_VAR_824 =__Bah_multiple_concat(____BAH_COMPILER_VAR_823, 6);tpdf = ____BAH_COMPILER_VAR_824;
}
}
if ((string__hasPrefix(&cfrt,"function(")==1)) {
char** ____BAH_COMPILER_VAR_825 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_825[1] = getCfunctionType(&cfrt,argName,elems);____BAH_COMPILER_VAR_825[0] = code;char * ____BAH_COMPILER_VAR_826 =__Bah_multiple_concat(____BAH_COMPILER_VAR_825, 2);code = ____BAH_COMPILER_VAR_826;
}
else {
char** ____BAH_COMPILER_VAR_827 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_827[3] = argName;____BAH_COMPILER_VAR_827[2] = " ";____BAH_COMPILER_VAR_827[1] = newArgType;____BAH_COMPILER_VAR_827[0] = code;char * ____BAH_COMPILER_VAR_828 =__Bah_multiple_concat(____BAH_COMPILER_VAR_827, 4);code = ____BAH_COMPILER_VAR_828;
}
if ((isComa==true)) {
char** ____BAH_COMPILER_VAR_829 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_829[1] = ",";____BAH_COMPILER_VAR_829[0] = code;char * ____BAH_COMPILER_VAR_830 =__Bah_multiple_concat(____BAH_COMPILER_VAR_829, 2);code = ____BAH_COMPILER_VAR_830;
}
else {
char** ____BAH_COMPILER_VAR_831 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_831[1] = ")";____BAH_COMPILER_VAR_831[0] = code;char * ____BAH_COMPILER_VAR_832 =__Bah_multiple_concat(____BAH_COMPILER_VAR_831, 2);code = ____BAH_COMPILER_VAR_832;
break;
}
j = j+1;
};
}
else {
char** ____BAH_COMPILER_VAR_833 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_833[1] = ")";____BAH_COMPILER_VAR_833[0] = code;char * ____BAH_COMPILER_VAR_834 =__Bah_multiple_concat(____BAH_COMPILER_VAR_833, 2);code = ____BAH_COMPILER_VAR_834;
}
j = j+1;
struct variable* ____BAH_COMPILER_VAR_835 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_835->name = "";
____BAH_COMPILER_VAR_835->type = "";
____BAH_COMPILER_VAR_835->constVal = "";
____BAH_COMPILER_VAR_835->from = "";
struct variable* returns = ____BAH_COMPILER_VAR_835;
returns->type = "";
while ((j<len(l))) {
t = l->data[j];
if ((strcmp(t.cont, "{") == 0)) {
break;
}
char** ____BAH_COMPILER_VAR_836 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_836[1] = t.cont;____BAH_COMPILER_VAR_836[0] = returns->type;char * ____BAH_COMPILER_VAR_837 =__Bah_multiple_concat(____BAH_COMPILER_VAR_836, 2);returns->type = ____BAH_COMPILER_VAR_837;
j = j+1;
};
if (strlen(returns->type)) {
struct string rts = string(returns->type);
string__replace(&rts," ","");
returns->type = rts.content;
}
*i = j;
returns->name = fn->name;
fn->returns = returns;
fn->args = arguments;
struct string fnRetType = getCType(returns->type,elems);
char * newFnRetType = string__str(&fnRetType);
struct string cfrt = string(returns->type);
if ((string__hasPrefix(&cfrt,"[]")==1)) {
string__trimLeft(&cfrt,2);
if (string__hasSuffix(&cfrt,"*")) {
long int nbast = string__count(&cfrt,"*");
string__trimRight(&cfrt,nbast);
}
char** ____BAH_COMPILER_VAR_838 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_838[1] = string__str(&cfrt);____BAH_COMPILER_VAR_838[0] = "__BAH_ARR_TYPE_";char * ____BAH_COMPILER_VAR_839 =__Bah_multiple_concat(____BAH_COMPILER_VAR_838, 2);newFnRetType = ____BAH_COMPILER_VAR_839;
array(char *)* csatd = compilerState.arrTypesDecl;
if ((inArrayStr(newFnRetType,csatd)==false)) {

    unsigned int ____BAH_COMPILER_VAR_840 = len(csatd);
    __Bah_realocate_arr(csatd, ____BAH_COMPILER_VAR_840);
    csatd->data[____BAH_COMPILER_VAR_840] = newFnRetType;
char** ____BAH_COMPILER_VAR_841 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_841[5] = ";\n";____BAH_COMPILER_VAR_841[4] = newFnRetType;____BAH_COMPILER_VAR_841[3] = " ";____BAH_COMPILER_VAR_841[2] = string__str(&fnRetType);____BAH_COMPILER_VAR_841[1] = "typedef ";____BAH_COMPILER_VAR_841[0] = tpdf;char * ____BAH_COMPILER_VAR_842 =__Bah_multiple_concat(____BAH_COMPILER_VAR_841, 6);tpdf = ____BAH_COMPILER_VAR_842;
}
}
char** ____BAH_COMPILER_VAR_843 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_843[3] = code;____BAH_COMPILER_VAR_843[2] = " ";____BAH_COMPILER_VAR_843[1] = newFnRetType;____BAH_COMPILER_VAR_843[0] = tpdf;char * ____BAH_COMPILER_VAR_844 =__Bah_multiple_concat(____BAH_COMPILER_VAR_843, 4);code = ____BAH_COMPILER_VAR_844;
return code;
};
void parseStruct(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
struct cStruct* ____BAH_COMPILER_VAR_845 = memoryAlloc(sizeof(struct cStruct));
____BAH_COMPILER_VAR_845->name = "";
____BAH_COMPILER_VAR_845->members = memoryAlloc(sizeof(array(struct structMemb*)));
            ____BAH_COMPILER_VAR_845->members->length = 0;
            ____BAH_COMPILER_VAR_845->members->elemSize = sizeof(struct structMemb*);
            ____BAH_COMPILER_VAR_845->methods = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_845->methods->length = 0;
            ____BAH_COMPILER_VAR_845->methods->elemSize = sizeof(struct func*);
            ____BAH_COMPILER_VAR_845->postCode = "";
____BAH_COMPILER_VAR_845->extendedFrom = "";
struct cStruct* s = ____BAH_COMPILER_VAR_845;
array(struct cStruct*)* structs = elems->structs;

    unsigned int ____BAH_COMPILER_VAR_846 = len(structs);
    __Bah_realocate_arr(structs, ____BAH_COMPILER_VAR_846);
    structs->data[____BAH_COMPILER_VAR_846] = s;
array(struct func*)* methds = s->methods;
if ((len(l)<4)) {
throwErr(&l->data[len(l)-1],"Cannot declare struct has such, please do 'struct <name> { <memberName>:<memberType> }'.");
}
struct Tok nameToken = l->data[1];
register long int i = 2;
char doesOutput = true;
if ((strcmp(nameToken.cont, "!") == 0)) {
nameToken = l->data[2];
i = 3;
doesOutput = false;
s->isBinding = true;
}
if ((nameToken.type!=TOKEN_TYPE_VAR)) {
throwErr(&nameToken,"Cannot use {TOKEN} as struct name.");
}
struct cStruct* os = searchStruct(nameToken.cont,elems);
if ((os!=null)) {
throwErr(&nameToken,"Struct {TOKEN} already exists.");
}
s->name = nameToken.cont;
array(struct structMemb*)* members = s->members;
currentCStruct = s;
array(char *)* allMembs = memoryAlloc(sizeof(array(char *)));

allMembs->length = 0;
allMembs->elemSize = sizeof(char *);
struct Tok st = l->data[i];
if ((st.type==TOKEN_TYPE_KEYWORD)) {
if ((strcmp(st.cont, "extend") == 0)) {
++i;
struct Tok extdSNameTk = l->data[i];
++i;
if ((extdSNameTk.type!=TOKEN_TYPE_VAR)) {
throwErr(&extdSNameTk,"Cannot use {TOKEN} as struct name.");
}
struct cStruct* extdS = searchStruct(extdSNameTk.cont,elems);
if ((extdS==null)) {
throwErr(&extdSNameTk,"Struct {TOKEN} does not exist.");
}
s->extendedFrom = extdS->name;
array(struct structMemb*)* extdsmbs = extdS->members;
register long int j = 0;
while ((j<len(extdsmbs))) {
struct structMemb* em = extdsmbs->data[j];
struct string cemt = string(em->type);
char * membDeclStr= null;
if ((string__hasPrefix(&cemt,"function(")==1)) {
struct func* tmpfn = parseFnType(cemt);
struct string tmpfnRetCType = getCType(tmpfn->returns->type,elems);
char * tmpfnArgsCType = "";
j = 0;
while ((j<len(tmpfn->args))) {
struct variable* arg = tmpfn->args->data[j];
struct string ct = getCType(arg->type,elems);
char** ____BAH_COMPILER_VAR_847 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_847[1] = string__str(&ct);____BAH_COMPILER_VAR_847[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_848 =__Bah_multiple_concat(____BAH_COMPILER_VAR_847, 2);tmpfnArgsCType = ____BAH_COMPILER_VAR_848;
j = j+1;
if ((j<len(tmpfn->args))) {
char** ____BAH_COMPILER_VAR_849 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_849[1] = ",";____BAH_COMPILER_VAR_849[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_850 =__Bah_multiple_concat(____BAH_COMPILER_VAR_849, 2);tmpfnArgsCType = ____BAH_COMPILER_VAR_850;
}
};
char** ____BAH_COMPILER_VAR_851 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_851[5] = ")";____BAH_COMPILER_VAR_851[4] = tmpfnArgsCType;____BAH_COMPILER_VAR_851[3] = ")(";____BAH_COMPILER_VAR_851[2] = em->name;____BAH_COMPILER_VAR_851[1] = " (*";____BAH_COMPILER_VAR_851[0] = string__str(&tmpfnRetCType);char * ____BAH_COMPILER_VAR_852 =__Bah_multiple_concat(____BAH_COMPILER_VAR_851, 6);membDeclStr = ____BAH_COMPILER_VAR_852;
}
else {
if (isRCPpointerType(em->type)) {
s->hasRCPmemb = true;
}
struct string membDecl = getCType(em->type,elems);
string__append(&membDecl," ");
string__append(&membDecl,em->name);
membDeclStr = membDecl.content;
}

    unsigned int ____BAH_COMPILER_VAR_853 = len(allMembs);
    __Bah_realocate_arr(allMembs, ____BAH_COMPILER_VAR_853);
    allMembs->data[____BAH_COMPILER_VAR_853] = membDeclStr;

    unsigned int ____BAH_COMPILER_VAR_854 = len(members);
    __Bah_realocate_arr(members, ____BAH_COMPILER_VAR_854);
    members->data[____BAH_COMPILER_VAR_854] = em;
j = j+1;
};
}
else {
throwErr(&st,"Cannot use keyword {TOKEN} in struct declaration.");
}
}
struct Tok braceTk = l->data[i];
++i;
if ((strcmp(braceTk.cont, "{") != 0)) {
throwErr(&braceTk,"Cannot use {TOKEN} in struct declaration.");
}
struct rope* OOUT = OUTPUT;
char * nextLine = "";
while ((i<len(l))) {
struct Tok t = l->data[i];
long int max = i+2;
if ((max>=len(l))) {
if ((t.type==TOKEN_TYPE_ENCL)&&(strcmp(t.cont, "}") == 0)) {
break;
}
throwErr(&l->data[len(l)-1],"Not enough argument in member declaration, ending by {TOKEN}.");
}
struct structMemb* ____BAH_COMPILER_VAR_855 = memoryAlloc(sizeof(struct structMemb));
____BAH_COMPILER_VAR_855->name = "";
____BAH_COMPILER_VAR_855->type = "";
____BAH_COMPILER_VAR_855->constVal = "";
____BAH_COMPILER_VAR_855->from = "";
____BAH_COMPILER_VAR_855->def = "";
struct structMemb* memb = ____BAH_COMPILER_VAR_855;
if ((t.type!=TOKEN_TYPE_VAR)) {
throwErr(&t,"Cannot use {TOKEN} as member name.");
}
memb->name = t.cont;
register long int ii = 0;
while ((ii<len(members))) {
struct structMemb* m = members->data[ii];
if ((strcmp(m->name, memb->name) == 0)) {
throwErr(&t,"Member {TOKEN} has already been declared.");
}
ii = ii+1;
};
++i;
t = l->data[i];
if ((strcmp(t.cont, ":") != 0)) {
if ((strcmp(t.cont, "(") != 0)) {
throwErr(&t,"Member name should be followed by ':' not {TOKEN}.");
}
else {
char** ____BAH_COMPILER_VAR_856 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_856[1] = "__";____BAH_COMPILER_VAR_856[0] = s->name;char * ____BAH_COMPILER_VAR_857 =__Bah_multiple_concat(____BAH_COMPILER_VAR_856, 2);char * fnPrefix = ____BAH_COMPILER_VAR_857;
struct func* ____BAH_COMPILER_VAR_858 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_858->name = "";
____BAH_COMPILER_VAR_858->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_858->args->length = 0;
            ____BAH_COMPILER_VAR_858->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_858->from = "";
____BAH_COMPILER_VAR_858->file = "";
____BAH_COMPILER_VAR_858->line = 1;
struct func* fn = ____BAH_COMPILER_VAR_858;
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
register long int j = i-1;
while ((j<len(l))) {
t = l->data[j];
if ((strcmp(t.cont, "{") == 0)) {
break;
}

    unsigned int ____BAH_COMPILER_VAR_859 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_859);
    nl->data[____BAH_COMPILER_VAR_859] = t;
if ((j==i)) {
t.type = TOKEN_TYPE_VAR;
t.cont = "this";
t.isValue = true;

    unsigned int ____BAH_COMPILER_VAR_860 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_860);
    nl->data[____BAH_COMPILER_VAR_860] = t;
t.type = TOKEN_TYPE_VAR;
char** ____BAH_COMPILER_VAR_861 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_861[1] = "*";____BAH_COMPILER_VAR_861[0] = s->name;char * ____BAH_COMPILER_VAR_862 =__Bah_multiple_concat(____BAH_COMPILER_VAR_861, 2);t.cont = ____BAH_COMPILER_VAR_862;
t.isValue = true;

    unsigned int ____BAH_COMPILER_VAR_863 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_863);
    nl->data[____BAH_COMPILER_VAR_863] = t;
struct Tok nt = l->data[j+1];
if ((strcmp(nt.cont, ")") != 0)) {
t.type = TOKEN_TYPE_SYNTAX;
t.cont = ",";
t.isValue = false;

    unsigned int ____BAH_COMPILER_VAR_864 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_864);
    nl->data[____BAH_COMPILER_VAR_864] = t;
}
}
j = j+1;
};
--i;
long int nli = 0;
char * ____BAH_COMPILER_VAR_865 =parseFnHeader(fnPrefix,nl,&nli,fn,elems);struct rope* code = rope(____BAH_COMPILER_VAR_865);
i = i+nli;
i = i-2;
struct variable* returns = fn->returns;
array(struct variable*)* arguments = fn->args;
fn->from = s->name;
if ((shouldOnlyDecl==true)) {
code = rope__add(code, rope(";\n"));
}
else {
code = rope__add(code, rope("{\n"));
}
struct Elems* fnElems = dupElems(elems);
j = 0;
for (; (j<len(arguments)); ++j) {
struct variable* a = arguments->data[j];
a->declScope = elems;
a->isArg = true;

    unsigned int ____BAH_COMPILER_VAR_866 = len(fnElems->vars);
    __Bah_realocate_arr(fnElems->vars, ____BAH_COMPILER_VAR_866);
    fnElems->vars->data[____BAH_COMPILER_VAR_866] = a;
};
array(struct func*)* fns = elems->fns;

    unsigned int ____BAH_COMPILER_VAR_867 = len(fns);
    __Bah_realocate_arr(fns, ____BAH_COMPILER_VAR_867);
    fns->data[____BAH_COMPILER_VAR_867] = fn;
array(struct Tok)* tokens = memoryAlloc(sizeof(array(struct Tok)));

tokens->length = 0;
tokens->elemSize = sizeof(struct Tok);
long int nbBraces = 1;
t = l->data[i];
if ((strcmp(t.cont, "{") == 0)) {
++i;
}
while ((i<len(l))) {
t = l->data[i];
if ((strcmp(t.cont, "{") == 0)) {
nbBraces = nbBraces+1;
}
else if ((strcmp(t.cont, "}") == 0)) {
nbBraces = nbBraces-1;
}
if ((nbBraces==0)) {
break;
}

    unsigned int ____BAH_COMPILER_VAR_868 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_868);
    tokens->data[____BAH_COMPILER_VAR_868] = t;
++i;
};
struct func* ____BAH_COMPILER_VAR_869 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_869->name = "";
____BAH_COMPILER_VAR_869->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_869->args->length = 0;
            ____BAH_COMPILER_VAR_869->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_869->from = "";
____BAH_COMPILER_VAR_869->file = "";
____BAH_COMPILER_VAR_869->line = 1;
struct func* mfn = ____BAH_COMPILER_VAR_869;
mfn->args = fn->args;
mfn->name = fn->name;
mfn->returns = fn->returns;
mfn->from = s->name;
strTrimLeft(&mfn->name,strlen(fnPrefix));

    unsigned int ____BAH_COMPILER_VAR_870 = len(methds);
    __Bah_realocate_arr(methds, ____BAH_COMPILER_VAR_870);
    methds->data[____BAH_COMPILER_VAR_870] = mfn;
if ((shouldOnlyDecl==false)) {
if ((len(tokens)==0)) {
code = rope__add(code, rope("};\n"));
}
else {
OUTPUT = rope("");
currentFn = fn;
beginRCPscope(fnElems,fn->args);
struct Elems* ocurrFnElems = compilerState.currFnElems;
compilerState.currFnElems = fnElems;
parseLines(tokens,fnElems);
OPTI_checkFuncScopeRef(fnElems);
compilerState.currFnElems = ocurrFnElems;
currentFn = null;
if ((fn->returned==false)) {
if ((strlen(fn->returns->type)>0)) {
char** ____BAH_COMPILER_VAR_871 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_871[2] = "' is not returned.";____BAH_COMPILER_VAR_871[1] = fn->name;____BAH_COMPILER_VAR_871[0] = "Function '";char * ____BAH_COMPILER_VAR_872 =__Bah_multiple_concat(____BAH_COMPILER_VAR_871, 3);throwErr(&l->data[len(l)-1],____BAH_COMPILER_VAR_872);
}
endRCPscope(fnElems,fn->args);
}
code = rope__add(code, rope__add(OUTPUT, rope("};\n")));
}
}
else {
fn->isImported = true;
mfn->isImported = true;
}
if ((doesOutput==true)) {
char** ____BAH_COMPILER_VAR_873 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_873[1] = rope__toStr(code);____BAH_COMPILER_VAR_873[0] = nextLine;char * ____BAH_COMPILER_VAR_874 =__Bah_multiple_concat(____BAH_COMPILER_VAR_873, 2);nextLine = ____BAH_COMPILER_VAR_874;
}
++i;
continue;
}
}
++i;
char * mbmType = "";
unsigned int currentLine = t.line;
while ((i<len(l))) {
t = l->data[i];
if ((strcmp(t.cont, "=") == 0)) {
--i;
break;
}
if ((t.line!=currentLine)) {
--i;
break;
}
char** ____BAH_COMPILER_VAR_875 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_875[1] = t.cont;____BAH_COMPILER_VAR_875[0] = mbmType;char * ____BAH_COMPILER_VAR_876 =__Bah_multiple_concat(____BAH_COMPILER_VAR_875, 2);mbmType = ____BAH_COMPILER_VAR_876;
++i;
};
memb->type = mbmType;
++i;
t = l->data[i];
if ((i<len(l))) {
if ((strcmp(t.cont, "=") == 0)) {
++i;
t = l->data[i];
if ((t.isValue==false)) {
throwErr(&t,"Cannot use {TOKEN} as default value for member.");
}
char * tt = getTypeFromToken(&t,true,elems);
if ((compTypes(tt,memb->type)==false)) {
char** ____BAH_COMPILER_VAR_877 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_877[4] = " for member.";____BAH_COMPILER_VAR_877[3] = memb->type;____BAH_COMPILER_VAR_877[2] = ") as ";____BAH_COMPILER_VAR_877[1] = tt;____BAH_COMPILER_VAR_877[0] = "Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_878 =__Bah_multiple_concat(____BAH_COMPILER_VAR_877, 5);throwErr(&t,____BAH_COMPILER_VAR_878);
}
memb->def = t.cont;
}
else {
--i;
}
}
if (isRCPpointerType(memb->type)) {
s->hasRCPmemb = true;
}

    unsigned int ____BAH_COMPILER_VAR_879 = len(members);
    __Bah_realocate_arr(members, ____BAH_COMPILER_VAR_879);
    members->data[____BAH_COMPILER_VAR_879] = memb;
char * membDeclStr= null;
struct string cmt = string(memb->type);
if ((string__hasPrefix(&cmt,"function(")==1)) {
struct func* tmpfn = parseFnType(cmt);
struct string tmpfnRetCType = getCType(tmpfn->returns->type,elems);
char * tmpfnArgsCType = "";
register long int j = 0;
while ((j<len(tmpfn->args))) {
struct variable* arg = tmpfn->args->data[j];
struct string ct = getCType(arg->type,elems);
char** ____BAH_COMPILER_VAR_880 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_880[1] = string__str(&ct);____BAH_COMPILER_VAR_880[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_881 =__Bah_multiple_concat(____BAH_COMPILER_VAR_880, 2);tmpfnArgsCType = ____BAH_COMPILER_VAR_881;
j = j+1;
if ((j<len(tmpfn->args))) {
char** ____BAH_COMPILER_VAR_882 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_882[1] = ",";____BAH_COMPILER_VAR_882[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_883 =__Bah_multiple_concat(____BAH_COMPILER_VAR_882, 2);tmpfnArgsCType = ____BAH_COMPILER_VAR_883;
}
};
char** ____BAH_COMPILER_VAR_884 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_884[5] = ")";____BAH_COMPILER_VAR_884[4] = tmpfnArgsCType;____BAH_COMPILER_VAR_884[3] = ")(";____BAH_COMPILER_VAR_884[2] = memb->name;____BAH_COMPILER_VAR_884[1] = " (*";____BAH_COMPILER_VAR_884[0] = string__str(&tmpfnRetCType);char * ____BAH_COMPILER_VAR_885 =__Bah_multiple_concat(____BAH_COMPILER_VAR_884, 6);membDeclStr = ____BAH_COMPILER_VAR_885;
}
else {
struct string membDecl = getCType(memb->type,elems);
char** ____BAH_COMPILER_VAR_886 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_886[1] = memb->name;____BAH_COMPILER_VAR_886[0] = " ";char * ____BAH_COMPILER_VAR_887 =__Bah_multiple_concat(____BAH_COMPILER_VAR_886, 2);string__append(&membDecl,____BAH_COMPILER_VAR_887);
membDeclStr = string__str(&membDecl);
}

    unsigned int ____BAH_COMPILER_VAR_888 = len(allMembs);
    __Bah_realocate_arr(allMembs, ____BAH_COMPILER_VAR_888);
    allMembs->data[____BAH_COMPILER_VAR_888] = membDeclStr;
++i;
};
s->members = members;
if ((doesOutput==true)) {
OUTPUT = OOUT;
NEXT_LINE = nextLine;
char** ____BAH_COMPILER_VAR_889 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_889[2] = " {\n";____BAH_COMPILER_VAR_889[1] = s->name;____BAH_COMPILER_VAR_889[0] = "struct ";char * ____BAH_COMPILER_VAR_890 =__Bah_multiple_concat(____BAH_COMPILER_VAR_889, 3);struct rope* code = rope(____BAH_COMPILER_VAR_890);
i = 0;
while ((i<len(allMembs))) {
char * m = allMembs->data[i];
char** ____BAH_COMPILER_VAR_891 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_891[1] = ";\n";____BAH_COMPILER_VAR_891[0] = m;char * ____BAH_COMPILER_VAR_892 =__Bah_multiple_concat(____BAH_COMPILER_VAR_891, 2);code = rope__add(code, rope(____BAH_COMPILER_VAR_892));
++i;
};
code = rope__add(code, rope("};\n"));
OUTPUT = rope__add(OUTPUT, code);
}
if ((debug==true)) {
struct debugStruct* ____BAH_COMPILER_VAR_893 = memoryAlloc(sizeof(struct debugStruct));
____BAH_COMPILER_VAR_893->membs = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_893->membs->length = 0;
            ____BAH_COMPILER_VAR_893->membs->elemSize = sizeof(struct variable*);
            struct debugStruct* ds = ____BAH_COMPILER_VAR_893;
ds->name = s->name;
i = 0;
while ((i<len(s->members))) {
struct structMemb* m = s->members->data[i];
struct variable* ____BAH_COMPILER_VAR_894 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_894->name = "";
____BAH_COMPILER_VAR_894->type = "";
____BAH_COMPILER_VAR_894->constVal = "";
____BAH_COMPILER_VAR_894->from = "";
struct variable* mv = ____BAH_COMPILER_VAR_894;
mv->name = m->name;
mv->type = m->type;
mv->isConst = false;
mv->isArray = m->isArray;

    unsigned int ____BAH_COMPILER_VAR_895 = i;
    __Bah_realocate_arr(ds->membs, ____BAH_COMPILER_VAR_895);
    ds->membs->data[____BAH_COMPILER_VAR_895] = mv;
i = i+1;
};
struct debugStruct* ____BAH_COMPILER_VAR_896 = ds;
char ** ____BAH_COMPILER_VAR_898 = (char **)((char*)(____BAH_COMPILER_VAR_896) + offsetof(struct debugStruct, name));
struct reflectElement ____BAH_COMPILER_VAR_899 = __reflect(____BAH_COMPILER_VAR_898, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct debugStruct, name));
array(struct variable*)** ____BAH_COMPILER_VAR_900 = (array(struct variable*)**)((char*)(____BAH_COMPILER_VAR_896) + offsetof(struct debugStruct, membs));
struct variable** ____BAH_COMPILER_VAR_901 = 0;
char ** ____BAH_COMPILER_VAR_903 = (char **)((char*)(____BAH_COMPILER_VAR_901) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_904 = __reflect(____BAH_COMPILER_VAR_903, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_905 = (char **)((char*)(____BAH_COMPILER_VAR_901) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_906 = __reflect(____BAH_COMPILER_VAR_905, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_907 = (char*)((char*)(____BAH_COMPILER_VAR_901) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_908 = __reflect(____BAH_COMPILER_VAR_907, sizeof(char), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_909 = (char **)((char*)(____BAH_COMPILER_VAR_901) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_910 = __reflect(____BAH_COMPILER_VAR_909, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_911 = (char*)((char*)(____BAH_COMPILER_VAR_901) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_912 = __reflect(____BAH_COMPILER_VAR_911, sizeof(char), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_913 = (char **)((char*)(____BAH_COMPILER_VAR_901) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_914 = __reflect(____BAH_COMPILER_VAR_913, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
void ** ____BAH_COMPILER_VAR_915 = (void **)((char*)(____BAH_COMPILER_VAR_901) + offsetof(struct variable, declScope));
struct reflectElement ____BAH_COMPILER_VAR_916 = __reflect(____BAH_COMPILER_VAR_915, sizeof(void *), "ptr", "declScope", 0, 0, 0, 0, offsetof(struct variable, declScope));
char* ____BAH_COMPILER_VAR_917 = (char*)((char*)(____BAH_COMPILER_VAR_901) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_918 = __reflect(____BAH_COMPILER_VAR_917, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));
struct rope** ____BAH_COMPILER_VAR_919 = (struct rope**)((char*)(____BAH_COMPILER_VAR_901) + offsetof(struct variable, declRope));
void ** ____BAH_COMPILER_VAR_921 = (void **)((char*)(____BAH_COMPILER_VAR_919) + offsetof(struct rope, left));
struct reflectElement ____BAH_COMPILER_VAR_922 = __reflect(____BAH_COMPILER_VAR_921, sizeof(void *), "ptr", "left", 0, 0, 0, 0, offsetof(struct rope, left));
void ** ____BAH_COMPILER_VAR_923 = (void **)((char*)(____BAH_COMPILER_VAR_919) + offsetof(struct rope, right));
struct reflectElement ____BAH_COMPILER_VAR_924 = __reflect(____BAH_COMPILER_VAR_923, sizeof(void *), "ptr", "right", 0, 0, 0, 0, offsetof(struct rope, right));
char ** ____BAH_COMPILER_VAR_925 = (char **)((char*)(____BAH_COMPILER_VAR_919) + offsetof(struct rope, str));
struct reflectElement ____BAH_COMPILER_VAR_926 = __reflect(____BAH_COMPILER_VAR_925, sizeof(char *), "cpstring", "str", 0, 0, 0, 0, offsetof(struct rope, str));
int* ____BAH_COMPILER_VAR_927 = (int*)((char*)(____BAH_COMPILER_VAR_919) + offsetof(struct rope, lCount));
struct reflectElement ____BAH_COMPILER_VAR_928 = __reflect(____BAH_COMPILER_VAR_927, sizeof(int), "int32", "lCount", 0, 0, 0, 0, offsetof(struct rope, lCount));
int* ____BAH_COMPILER_VAR_929 = (int*)((char*)(____BAH_COMPILER_VAR_919) + offsetof(struct rope, len));
struct reflectElement ____BAH_COMPILER_VAR_930 = __reflect(____BAH_COMPILER_VAR_929, sizeof(int), "int32", "len", 0, 0, 0, 0, offsetof(struct rope, len));
int* ____BAH_COMPILER_VAR_931 = (int*)((char*)(____BAH_COMPILER_VAR_919) + offsetof(struct rope, totalLen));
struct reflectElement ____BAH_COMPILER_VAR_932 = __reflect(____BAH_COMPILER_VAR_931, sizeof(int), "int32", "totalLen", 0, 0, 0, 0, offsetof(struct rope, totalLen));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_920 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_920->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_920->length = 6;
        ____BAH_COMPILER_VAR_920->data = memoryAlloc(____BAH_COMPILER_VAR_920->length * ____BAH_COMPILER_VAR_920->elemSize);
        ____BAH_COMPILER_VAR_920->data[0] = ____BAH_COMPILER_VAR_922;
____BAH_COMPILER_VAR_920->data[1] = ____BAH_COMPILER_VAR_924;
____BAH_COMPILER_VAR_920->data[2] = ____BAH_COMPILER_VAR_926;
____BAH_COMPILER_VAR_920->data[3] = ____BAH_COMPILER_VAR_928;
____BAH_COMPILER_VAR_920->data[4] = ____BAH_COMPILER_VAR_930;
____BAH_COMPILER_VAR_920->data[5] = ____BAH_COMPILER_VAR_932;
struct reflectElement ____BAH_COMPILER_VAR_933 = __reflect(____BAH_COMPILER_VAR_919, sizeof(struct rope), "rope*", "declRope", 0, 0, 1, ____BAH_COMPILER_VAR_920, offsetof(struct variable, declRope));
char* ____BAH_COMPILER_VAR_934 = (char*)((char*)(____BAH_COMPILER_VAR_901) + offsetof(struct variable, canBeNull));
struct reflectElement ____BAH_COMPILER_VAR_935 = __reflect(____BAH_COMPILER_VAR_934, sizeof(char), "bool", "canBeNull", 0, 0, 0, 0, offsetof(struct variable, canBeNull));
char* ____BAH_COMPILER_VAR_936 = (char*)((char*)(____BAH_COMPILER_VAR_901) + offsetof(struct variable, canBeReg));
struct reflectElement ____BAH_COMPILER_VAR_937 = __reflect(____BAH_COMPILER_VAR_936, sizeof(char), "bool", "canBeReg", 0, 0, 0, 0, offsetof(struct variable, canBeReg));
char* ____BAH_COMPILER_VAR_938 = (char*)((char*)(____BAH_COMPILER_VAR_901) + offsetof(struct variable, isReg));
struct reflectElement ____BAH_COMPILER_VAR_939 = __reflect(____BAH_COMPILER_VAR_938, sizeof(char), "bool", "isReg", 0, 0, 0, 0, offsetof(struct variable, isReg));
void ** ____BAH_COMPILER_VAR_940 = (void **)((char*)(____BAH_COMPILER_VAR_901) + offsetof(struct variable, lastSet));
struct reflectElement ____BAH_COMPILER_VAR_941 = __reflect(____BAH_COMPILER_VAR_940, sizeof(void *), "ptr", "lastSet", 0, 0, 0, 0, offsetof(struct variable, lastSet));
char* ____BAH_COMPILER_VAR_942 = (char*)((char*)(____BAH_COMPILER_VAR_901) + offsetof(struct variable, isArg));
struct reflectElement ____BAH_COMPILER_VAR_943 = __reflect(____BAH_COMPILER_VAR_942, sizeof(char), "bool", "isArg", 0, 0, 0, 0, offsetof(struct variable, isArg));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_902 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_902->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_902->length = 14;
        ____BAH_COMPILER_VAR_902->data = memoryAlloc(____BAH_COMPILER_VAR_902->length * ____BAH_COMPILER_VAR_902->elemSize);
        ____BAH_COMPILER_VAR_902->data[0] = ____BAH_COMPILER_VAR_904;
____BAH_COMPILER_VAR_902->data[1] = ____BAH_COMPILER_VAR_906;
____BAH_COMPILER_VAR_902->data[2] = ____BAH_COMPILER_VAR_908;
____BAH_COMPILER_VAR_902->data[3] = ____BAH_COMPILER_VAR_910;
____BAH_COMPILER_VAR_902->data[4] = ____BAH_COMPILER_VAR_912;
____BAH_COMPILER_VAR_902->data[5] = ____BAH_COMPILER_VAR_914;
____BAH_COMPILER_VAR_902->data[6] = ____BAH_COMPILER_VAR_916;
____BAH_COMPILER_VAR_902->data[7] = ____BAH_COMPILER_VAR_918;
____BAH_COMPILER_VAR_902->data[8] = ____BAH_COMPILER_VAR_933;
____BAH_COMPILER_VAR_902->data[9] = ____BAH_COMPILER_VAR_935;
____BAH_COMPILER_VAR_902->data[10] = ____BAH_COMPILER_VAR_937;
____BAH_COMPILER_VAR_902->data[11] = ____BAH_COMPILER_VAR_939;
____BAH_COMPILER_VAR_902->data[12] = ____BAH_COMPILER_VAR_941;
____BAH_COMPILER_VAR_902->data[13] = ____BAH_COMPILER_VAR_943;
struct reflectElement ____BAH_COMPILER_VAR_944 = __reflect(____BAH_COMPILER_VAR_901, sizeof(struct variable), "variable*", "", 0, 0, 1, ____BAH_COMPILER_VAR_902, 0);

        struct reflectElement ____BAH_COMPILER_VAR_945 = ____BAH_COMPILER_VAR_944;
        struct reflectElement ____BAH_COMPILER_VAR_946 = __reflect(____BAH_COMPILER_VAR_900, sizeof(array(struct variable*)*), "[]variable*", "membs", 1, &____BAH_COMPILER_VAR_945, 0, 0, offsetof(struct debugStruct, membs));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_897 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_897->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_897->length = 2;
        ____BAH_COMPILER_VAR_897->data = memoryAlloc(____BAH_COMPILER_VAR_897->length * ____BAH_COMPILER_VAR_897->elemSize);
        ____BAH_COMPILER_VAR_897->data[0] = ____BAH_COMPILER_VAR_899;
____BAH_COMPILER_VAR_897->data[1] = ____BAH_COMPILER_VAR_946;
struct reflectElement ____BAH_COMPILER_VAR_947 = __reflect(____BAH_COMPILER_VAR_896, sizeof(struct debugStruct), "debugStruct*", "ds", 0, 0, 1, ____BAH_COMPILER_VAR_897, 0);
debugPrint("struct_declare",nameToken.line,____BAH_COMPILER_VAR_947);
}
};
void parseDefine(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
if ((len(l)<3)) {
throwErr(&l->data[len(l)-1],"Invalid usage of define, cannot end on {TOKEN}.");
}
struct Tok ft = l->data[1];
struct Tok st = l->data[2];
long int i = 1;
char doesOutput = true;
if ((strcmp(ft.cont, "!") == 0)) {
ft = l->data[2];
st = l->data[3];
i = 2;
doesOutput = false;
}
if ((strcmp(st.cont, "(") == 0)) {
struct func* ____BAH_COMPILER_VAR_948 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_948->name = "";
____BAH_COMPILER_VAR_948->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_948->args->length = 0;
            ____BAH_COMPILER_VAR_948->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_948->from = "";
____BAH_COMPILER_VAR_948->file = "";
____BAH_COMPILER_VAR_948->line = 1;
struct func* fn = ____BAH_COMPILER_VAR_948;
char * code = parseFnHeader("",l,&i,fn,elems);
array(struct func*)* fns = elems->fns;
fn->isBinding = true;

    unsigned int ____BAH_COMPILER_VAR_949 = len(fns);
    __Bah_realocate_arr(fns, ____BAH_COMPILER_VAR_949);
    fns->data[____BAH_COMPILER_VAR_949] = fn;
if ((doesOutput==true)) {
char** ____BAH_COMPILER_VAR_950 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_950[1] = ";\n";____BAH_COMPILER_VAR_950[0] = code;char * ____BAH_COMPILER_VAR_951 =__Bah_multiple_concat(____BAH_COMPILER_VAR_950, 2);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_951));
}
}
else {
char * tp = "";
++i;
for (; (i<len(l)); ++i) {
struct Tok t = l->data[i];
char** ____BAH_COMPILER_VAR_952 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_952[1] = t.cont;____BAH_COMPILER_VAR_952[0] = tp;char * ____BAH_COMPILER_VAR_953 =__Bah_multiple_concat(____BAH_COMPILER_VAR_952, 2);tp = ____BAH_COMPILER_VAR_953;
};
if ((ft.type!=TOKEN_TYPE_VAR)) {
throwErr(&ft,"Cannot use {TOKEN} as new type name.");
}
struct string cTypeNewType = getCType(tp,elems);
char * cTypeNewTypeStr = string__str(&cTypeNewType);
if ((doesOutput==true)) {
char** ____BAH_COMPILER_VAR_954 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_954[4] = ";\n";____BAH_COMPILER_VAR_954[3] = ft.cont;____BAH_COMPILER_VAR_954[2] = " ";____BAH_COMPILER_VAR_954[1] = cTypeNewTypeStr;____BAH_COMPILER_VAR_954[0] = "typedef ";char * ____BAH_COMPILER_VAR_955 =__Bah_multiple_concat(____BAH_COMPILER_VAR_954, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_955));
}
if ((debug==true)) {
struct debugType* ____BAH_COMPILER_VAR_956 = memoryAlloc(sizeof(struct debugType));
struct debugType* dt = ____BAH_COMPILER_VAR_956;
dt->name = ft.cont;
dt->refers = tp;
struct debugType* ____BAH_COMPILER_VAR_957 = dt;
char ** ____BAH_COMPILER_VAR_959 = (char **)((char*)(____BAH_COMPILER_VAR_957) + offsetof(struct debugType, name));
struct reflectElement ____BAH_COMPILER_VAR_960 = __reflect(____BAH_COMPILER_VAR_959, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct debugType, name));
char ** ____BAH_COMPILER_VAR_961 = (char **)((char*)(____BAH_COMPILER_VAR_957) + offsetof(struct debugType, refers));
struct reflectElement ____BAH_COMPILER_VAR_962 = __reflect(____BAH_COMPILER_VAR_961, sizeof(char *), "cpstring", "refers", 0, 0, 0, 0, offsetof(struct debugType, refers));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_958 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_958->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_958->length = 2;
        ____BAH_COMPILER_VAR_958->data = memoryAlloc(____BAH_COMPILER_VAR_958->length * ____BAH_COMPILER_VAR_958->elemSize);
        ____BAH_COMPILER_VAR_958->data[0] = ____BAH_COMPILER_VAR_960;
____BAH_COMPILER_VAR_958->data[1] = ____BAH_COMPILER_VAR_962;
struct reflectElement ____BAH_COMPILER_VAR_963 = __reflect(____BAH_COMPILER_VAR_957, sizeof(struct debugType), "debugType*", "dt", 0, 0, 1, ____BAH_COMPILER_VAR_958, 0);
debugPrint("type_declare",ft.line,____BAH_COMPILER_VAR_963);
}
array(char *)* tps = elems->types;

    unsigned int ____BAH_COMPILER_VAR_964 = len(tps);
    __Bah_realocate_arr(tps, ____BAH_COMPILER_VAR_964);
    tps->data[____BAH_COMPILER_VAR_964] = ft.cont;
}
};
void parseClib(__BAH_ARR_TYPE_Tok line){
array(char *)* clibs = compilerState.cLibs;
register long int i = 1;
while ((i<len(line))) {
struct Tok t = line->data[i];
if ((t.type!=TOKEN_TYPE_STR)) {
throwErr(&t,"Cannot use {TOKEN} as C library name.");
}
struct string cc = string(t.cont);
string__trimLeft(&cc,1);
string__trimRight(&cc,1);
char * ccstr = string__str(&cc);
char found = false;
register long int j = 0;
while ((j<len(clibs))) {
char * l = clibs->data[j];
if ((strcmp(l, ccstr) == 0)) {
found = true;
break;
}
j = j+1;
};
if ((found==true)) {
++i;
continue;
}

    unsigned int ____BAH_COMPILER_VAR_965 = len(clibs);
    __Bah_realocate_arr(clibs, ____BAH_COMPILER_VAR_965);
    clibs->data[____BAH_COMPILER_VAR_965] = ccstr;
++i;
};
};
void parseConst(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
l = parseCast(l,elems,true);
if ((len(l)!=4)) {
throwErr(&l->data[0],"Invalid usage of {TOKEN}, must be 'const <constName> = <constValue>'. ");
}
struct Tok vart = l->data[1];
struct Tok equt = l->data[2];
struct Tok valt = l->data[3];
if ((vart.type!=TOKEN_TYPE_VAR)) {
throwErr(&vart,"Cannot take {TOKEN} as const name.");
}
if ((strcmp(equt.cont, "=") != 0)) {
throwErr(&equt,"Expected '=' not {TOKEN}.");
}
if ((valt.isValue==false)) {
throwErr(&equt,"Must be a value, not {TOKEN}.");
}
if ((valt.type==TOKEN_TYPE_VAR)) {
struct func* fn = searchFunc(valt.cont,elems,true);
if ((fn!=null)) {
fn->used = true;
}
}
struct variable* ____BAH_COMPILER_VAR_966 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_966->name = "";
____BAH_COMPILER_VAR_966->type = "";
____BAH_COMPILER_VAR_966->constVal = "";
____BAH_COMPILER_VAR_966->from = "";
struct variable* v = ____BAH_COMPILER_VAR_966;
if (isGlobal()) {
v->isGlobal = true;
}
v->isConst = true;
v->constVal = valt.cont;
v->name = vart.cont;
v->type = getTypeFromToken(&valt,true,elems);
array(struct variable*)* vars = elems->vars;

    unsigned int ____BAH_COMPILER_VAR_967 = len(vars);
    __Bah_realocate_arr(vars, ____BAH_COMPILER_VAR_967);
    vars->data[____BAH_COMPILER_VAR_967] = v;
char** ____BAH_COMPILER_VAR_968 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_968[4] = "\n";____BAH_COMPILER_VAR_968[3] = valt.cont;____BAH_COMPILER_VAR_968[2] = " ";____BAH_COMPILER_VAR_968[1] = v->name;____BAH_COMPILER_VAR_968[0] = "#define ";char * ____BAH_COMPILER_VAR_969 =__Bah_multiple_concat(____BAH_COMPILER_VAR_968, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_969));
};
void parseReturn(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
if ((len(l)>2)) {
throwErr(&l->data[0],"Invalid usage of {TOKEN}, must be 'return <returnValue>'");
}
if ((currentFn==null)) {
throwErr(&l->data[0],"Cannot return a value outside of a function.");
}
char * rv = "";
char * tt = "";
struct variable* tmpV = null;
if ((len(l)==1)) {
if ((strlen(currentFn->returns->type)!=0)) {
char** ____BAH_COMPILER_VAR_970 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_970[2] = ".";____BAH_COMPILER_VAR_970[1] = currentFn->returns->type;____BAH_COMPILER_VAR_970[0] = "Cannot return nothing as ";char * ____BAH_COMPILER_VAR_971 =__Bah_multiple_concat(____BAH_COMPILER_VAR_970, 3);throwErr(&l->data[0],____BAH_COMPILER_VAR_971);
}
}
else {
struct Tok rvt = l->data[1];
tt = getTypeFromToken(&rvt,true,elems);
rv = rvt.cont;
if ((rvt.type==TOKEN_TYPE_VAR)&&(rvt.isOper==false)) {
tmpV = searchVar(rvt.cont,compilerState.currFnElems);
if ((tmpV==null)) {
tmpV = searchVar(rvt.cont,elems);
}
if ((tmpV!=null)) {

                struct string ____BAH_COMPILER_VAR_972 = string(compilerState.currentDir);
                if ((isUnsafe==false)&&(string__hasPrefix(&____BAH_COMPILER_VAR_972,BAH_DIR)==false)&&(currentFn->returns->type[strlen(currentFn->returns->type)-1]!=33)) {
if ((tmpV->canBeNull==true)||(strcmp(rv, "null") == 0)) {
currentFn->returns->canBeNull = true;
char** ____BAH_COMPILER_VAR_973 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_973[2] = "' that can be null as pointer.\n\tUse maybe values instead.";____BAH_COMPILER_VAR_973[1] = tmpV->name;____BAH_COMPILER_VAR_973[0] = "Returning '";char * ____BAH_COMPILER_VAR_974 =__Bah_multiple_concat(____BAH_COMPILER_VAR_973, 3);throwNoticeLine(____BAH_COMPILER_VAR_974,rvt.line);
}
}
}
}
else if (RCPavailable()&&(rvt.type==TOKEN_TYPE_FUNC)) {
rv = genCompilerVar();
struct string cType = getCType(tt,elems);
char** ____BAH_COMPILER_VAR_975 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_975[5] = ";\n";____BAH_COMPILER_VAR_975[4] = rvt.cont;____BAH_COMPILER_VAR_975[3] = "=";____BAH_COMPILER_VAR_975[2] = rv;____BAH_COMPILER_VAR_975[1] = " ";____BAH_COMPILER_VAR_975[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_976 =__Bah_multiple_concat(____BAH_COMPILER_VAR_975, 6);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_976));
}
if ((compTypes(tt,currentFn->returns->type)==false)) {
char** ____BAH_COMPILER_VAR_977 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_977[4] = ".";____BAH_COMPILER_VAR_977[3] = currentFn->returns->type;____BAH_COMPILER_VAR_977[2] = ") as ";____BAH_COMPILER_VAR_977[1] = tt;____BAH_COMPILER_VAR_977[0] = "Cannot return {TOKEN} (";char * ____BAH_COMPILER_VAR_978 =__Bah_multiple_concat(____BAH_COMPILER_VAR_977, 5);throwErr(&rvt,____BAH_COMPILER_VAR_978);
}
}
if ((compilerState.isBranch==false)) {
currentFn->returned = true;
}
else {
setNullStateBranchFlowEnd(elems);
}
if ((strlen(rv)>0)) {
char * rvar = rv;
if ((RCPavailable()==true)&&isRCPtype(currentFn->returns->type,elems)) {
rvar = genCompilerVar();
struct string cType = getCType(currentFn->returns->type,elems);
char** ____BAH_COMPILER_VAR_979 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_979[5] = ";\n";____BAH_COMPILER_VAR_979[4] = rv;____BAH_COMPILER_VAR_979[3] = " = ";____BAH_COMPILER_VAR_979[2] = rvar;____BAH_COMPILER_VAR_979[1] = " ";____BAH_COMPILER_VAR_979[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_980 =__Bah_multiple_concat(____BAH_COMPILER_VAR_979, 6);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_980));
if ((tmpV!=null)&&(tmpV->declScope!=elems)) {
OUTPUT = rope__add(OUTPUT, incrVar(tmpV,elems));
}
}
if (strHasPrefix(tt,"buffer:")) {
char** ____BAH_COMPILER_VAR_981 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_981[2] = ")";____BAH_COMPILER_VAR_981[1] = rvar;____BAH_COMPILER_VAR_981[0] = "__STR(";char * ____BAH_COMPILER_VAR_982 =__Bah_multiple_concat(____BAH_COMPILER_VAR_981, 3);rvar = ____BAH_COMPILER_VAR_982;
}
if (RCPavailable()) {
array(struct variable*)* excl = memoryAlloc(sizeof(array(struct variable*)));

excl->length = 0;
excl->elemSize = sizeof(struct variable*);
register long int j = 0;
for (; (j<len(currentFn->args)); ++j) {

    unsigned int ____BAH_COMPILER_VAR_983 = j;
    __Bah_realocate_arr(excl, ____BAH_COMPILER_VAR_983);
    excl->data[____BAH_COMPILER_VAR_983] = currentFn->args->data[j];
};
if ((tmpV!=null)) {

    unsigned int ____BAH_COMPILER_VAR_984 = len(excl);
    __Bah_realocate_arr(excl, ____BAH_COMPILER_VAR_984);
    excl->data[____BAH_COMPILER_VAR_984] = tmpV;
}
endRCPscope(elems,excl);
}
char** ____BAH_COMPILER_VAR_985 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_985[2] = ";\n";____BAH_COMPILER_VAR_985[1] = rvar;____BAH_COMPILER_VAR_985[0] = "return ";char * ____BAH_COMPILER_VAR_986 =__Bah_multiple_concat(____BAH_COMPILER_VAR_985, 3);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_986));
}
else {
if (RCPavailable()) {
array(struct variable*)* excl = memoryAlloc(sizeof(array(struct variable*)));

excl->length = 0;
excl->elemSize = sizeof(struct variable*);
register long int j = 0;
for (; (j<len(currentFn->args)); ++j) {

    unsigned int ____BAH_COMPILER_VAR_987 = j;
    __Bah_realocate_arr(excl, ____BAH_COMPILER_VAR_987);
    excl->data[____BAH_COMPILER_VAR_987] = currentFn->args->data[j];
};
if ((tmpV!=null)) {

    unsigned int ____BAH_COMPILER_VAR_988 = len(excl);
    __Bah_realocate_arr(excl, ____BAH_COMPILER_VAR_988);
    excl->data[____BAH_COMPILER_VAR_988] = tmpV;
}
endRCPscope(elems,excl);
}
OUTPUT = rope__add(OUTPUT, rope("return;\n"));
}
};
void parseIf(__BAH_ARR_TYPE_Tok l,char fromElse,struct Elems* elems){
prevIfExits = false;
if ((len(l)<4)) {
struct Tok ft = l->data[0];
throwErr(&ft,"Invalid usage of {TOKEN}, must be 'if <condition> {<code>}'");
}
struct Tok condt = l->data[1];
if ((strcmp(condt.bahType, "bool") != 0)) {
if ((strcmp(condt.bahType, "int") != 0)) {
throwErr(&condt,"Cannot use {TOKEN} as condition in if statement.");
}
}
struct Tok t = l->data[2];
if ((strcmp(t.cont, "{") != 0)) {
throwErr(&t,"Expected '{' not {TOKEN} after condtition in if statement.");
}
array(struct Tok)* tokens = memoryAlloc(sizeof(array(struct Tok)));

tokens->length = 0;
tokens->elemSize = sizeof(struct Tok);
long int max = len(l)-1;
register long int i = 3;
while ((i<max)) {
t = l->data[i];

    unsigned int ____BAH_COMPILER_VAR_989 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_989);
    tokens->data[____BAH_COMPILER_VAR_989] = t;
++i;
};
char** ____BAH_COMPILER_VAR_990 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_990[2] = ") {\n";____BAH_COMPILER_VAR_990[1] = condt.cont;____BAH_COMPILER_VAR_990[0] = "if (";char * ____BAH_COMPILER_VAR_991 =__Bah_multiple_concat(____BAH_COMPILER_VAR_990, 3);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_991));
struct Elems* ifElems = dupElems(elems);
if ((fromElse==true)) {
i = 0;
for (; (i<len(prevIfChecks)); ++i) {
struct varCheck bc = prevIfChecks->data[i];
bc.checkNull = (bc.checkNull==false);

    unsigned int ____BAH_COMPILER_VAR_992 = i;
    __Bah_realocate_arr(ifElems->branchChecks, ____BAH_COMPILER_VAR_992);
    ifElems->branchChecks->data[____BAH_COMPILER_VAR_992] = bc;
};
}
i = 0;
for (; (i<len(currChecks)); ++i) {

    unsigned int ____BAH_COMPILER_VAR_993 = len(ifElems->branchChecks);
    __Bah_realocate_arr(ifElems->branchChecks, ____BAH_COMPILER_VAR_993);
    ifElems->branchChecks->data[____BAH_COMPILER_VAR_993] = currChecks->data[i];
};
prevIfChecks = ifElems->branchChecks;
char oldIB = compilerState.isBranch;
compilerState.isBranch = true;
beginRCPscopeLeaky(ifElems);
parseLines(tokens,ifElems);
endRCPscopeLeaky(ifElems,null,true);
if ((debug==true)) {
struct Tok lt = l->data[len(l)-1];
debugEndScope(lt.line,ifElems);
}
compilerState.isBranch = oldIB;
OUTPUT = rope__add(OUTPUT, rope("}\n"));
};
void parseElse(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
if ((prevLine!=LINE_TYPE_IF)) {
if ((prevLine!=LINE_TYPE_ELSE)) {
throwErr(&l->data[0],"Can only use {TOKEN} after 'if' statement.");
}
}
if ((len(l)<3)) {
throwErr(&l->data[0],"Incalid usage of {TOKEN}, must be 'else {<code>}'.");
}
struct Tok ft = l->data[1];
char prevReturned = prevIfExits;
OUTPUT = rope__add(OUTPUT, rope("else "));
if ((strcmp(ft.cont, "if") == 0)) {
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
register long int i = 1;
while ((i<len(l))) {

    unsigned int ____BAH_COMPILER_VAR_994 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_994);
    memory->data[____BAH_COMPILER_VAR_994] = l->data[i];
++i;
};
parseIf(memory,true,elems);
prevLine = LINE_TYPE_IF;
}
else {
if ((strcmp(ft.cont, "{") != 0)) {
throwErr(&ft,"Expected 'if' or '{' not {TOKEN}.");
}
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
long int max = len(l)-1;
register long int i = 2;
while ((i<max)) {

    unsigned int ____BAH_COMPILER_VAR_995 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_995);
    memory->data[____BAH_COMPILER_VAR_995] = l->data[i];
++i;
};
OUTPUT = rope__add(OUTPUT, rope("{\n"));
struct Elems* ifElems = dupElems(elems);
i = 0;
for (; (i<len(prevIfChecks)); ++i) {
struct varCheck bc = prevIfChecks->data[i];
bc.checkNull = (bc.checkNull==false);

    unsigned int ____BAH_COMPILER_VAR_996 = i;
    __Bah_realocate_arr(ifElems->branchChecks, ____BAH_COMPILER_VAR_996);
    ifElems->branchChecks->data[____BAH_COMPILER_VAR_996] = bc;
};
char oldIB = compilerState.isBranch;
compilerState.isBranch = true;
struct Tok t = l->data[0];
beginRCPscopeLeaky(ifElems);
parseLines(memory,ifElems);
endRCPscopeLeaky(ifElems,null,true);
if ((debug==true)) {
struct Tok lt = l->data[len(l)-1];
debugEndScope(lt.line,ifElems);
}
compilerState.isBranch = oldIB;
OUTPUT = rope__add(OUTPUT, rope("}\n"));
prevIfExits = false;
}
};
void parseLine(__BAH_ARR_TYPE_Tok l,struct Elems* elems);
void parseFor(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
if ((len(l)<4)) {
throwErr(&l->data[0],"Invalid usage of {TOKEN}.");
}
long int nbComas = 0;
register long int i = 1;
while ((i<len(l))) {
struct Tok t = l->data[i];
if ((strcmp(t.cont, "{") == 0)) {
break;
}
if ((t.type==TOKEN_TYPE_SYNTAX)&&(strcmp(t.cont, ",") == 0)) {
if ((nbComas==1)) {
throwErr(&t,"Invalid line separation of for, cannot set more than 2 lines: {TOKEN}.");
}
nbComas = nbComas+1;
}
i = i+1;
};
array(struct Tok)* tokens = memoryAlloc(sizeof(array(struct Tok)));

tokens->length = 0;
tokens->elemSize = sizeof(struct Tok);
if ((nbComas>0)) {
if ((nbComas!=1)) {
struct Tok t = l->data[0];
throwErr(&t,"Invalid usage of {TOKEN}, can only partition line in 2 using 'for <condition>, <insctruction> {<code>}'.");
}
array(struct Tok)* inst = memoryAlloc(sizeof(array(struct Tok)));

inst->length = 0;
inst->elemSize = sizeof(struct Tok);
struct Tok condt = l->data[1];
if ((strcmp(condt.bahType, "bool") != 0)) {
if ((strcmp(condt.bahType, "int") != 0)) {
throwErr(&condt,"Cannot use {TOKEN} as condition in for statement.");
}
}
struct Tok st = l->data[2];
if ((st.type!=TOKEN_TYPE_SYNTAX)||(strcmp(st.cont, ",") != 0)) {
throwErr(&st,"Cannot use {TOKEN}, need ',' to split for loop instructions.");
}
i = 3;
for (; (i<len(l)); ++i) {
struct Tok t = l->data[i];
if ((t.type==TOKEN_TYPE_ENCL)&&(strcmp(t.cont, "{") == 0)) {
break;
}

    unsigned int ____BAH_COMPILER_VAR_997 = len(inst);
    __Bah_realocate_arr(inst, ____BAH_COMPILER_VAR_997);
    inst->data[____BAH_COMPILER_VAR_997] = t;
};
struct rope* oldOut = OUTPUT;
OUTPUT = rope("");
parseLine(inst,elems);
char * ____BAH_COMPILER_VAR_998 =rope__toStr(OUTPUT);struct string instC = string(____BAH_COMPILER_VAR_998);
OUTPUT = oldOut;
string__trimRight(&instC,2);
struct Tok t = l->data[i];
if ((strcmp(t.cont, "{") != 0)) {
throwErr(&t,"Expected '{' not {TOKEN} after '<condition>,<instruction>' in for statement.");
}
long int max = len(l)-1;
i = i+1;
for (; (i<max); ++i) {
t = l->data[i];

    unsigned int ____BAH_COMPILER_VAR_999 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_999);
    tokens->data[____BAH_COMPILER_VAR_999] = t;
};
char** ____BAH_COMPILER_VAR_1000 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1000[4] = ") {\n";____BAH_COMPILER_VAR_1000[3] = string__str(&instC);____BAH_COMPILER_VAR_1000[2] = "; ";____BAH_COMPILER_VAR_1000[1] = condt.cont;____BAH_COMPILER_VAR_1000[0] = "for (; ";char * ____BAH_COMPILER_VAR_1001 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1000, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1001));
}
else {
struct Tok condt = l->data[1];
if ((strcmp(condt.bahType, "bool") != 0)) {
if ((strcmp(condt.bahType, "int") != 0)) {
throwErr(&condt,"Cannot use {TOKEN} as condition in for statement.");
}
}
struct Tok t = l->data[2];
if ((strcmp(t.cont, "{") != 0)) {
throwErr(&t,"Expected '{' not {TOKEN} after condtition in for statement.");
}
long int max = len(l)-1;
i = 3;
for (; (i<max); ++i) {
t = l->data[i];

    unsigned int ____BAH_COMPILER_VAR_1002 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_1002);
    tokens->data[____BAH_COMPILER_VAR_1002] = t;
};
char** ____BAH_COMPILER_VAR_1003 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1003[2] = ") {\n";____BAH_COMPILER_VAR_1003[1] = condt.cont;____BAH_COMPILER_VAR_1003[0] = "while (";char * ____BAH_COMPILER_VAR_1004 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1003, 3);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1004));
}
struct Elems* oForElems = compilerState.currForElems;
struct Elems* ifElems = dupElems(elems);
compilerState.currForElems = ifElems;
char oldIB = compilerState.isBranch;
char oldIF = compilerState.isFor;
compilerState.isBranch = true;
compilerState.isFor = true;
struct Tok t = l->data[0];
beginRCPscopeLeaky(ifElems);
parseLines(tokens,ifElems);
endRCPscopeLeaky(ifElems,null,true);
if ((debug==true)) {
struct Tok lt = l->data[len(l)-1];
debugEndScope(lt.line,ifElems);
}
compilerState.isFor = oldIF;
compilerState.isBranch = oldIB;
compilerState.currForElems = oForElems;
OUTPUT = rope__add(OUTPUT, rope("};\n"));
};
void parseForOp(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
struct Tok ft = l->data[0];
if ((compilerState.isFor==false)) {
throwErr(&ft,"Cannot {TOKEN} outside of for statement.");
}
if ((len(l)!=1)) {
throwErr(&ft,"Nothing expected after {TOKEN}.");
}
endRCPscopeLeaky(elems,null,false);
endRCPscopeLeaky(compilerState.currForElems,null,false);
char** ____BAH_COMPILER_VAR_1005 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1005[1] = ";\n";____BAH_COMPILER_VAR_1005[0] = ft.cont;char * ____BAH_COMPILER_VAR_1006 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1005, 2);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1006));
};
void makeEvalFunc(struct func* fn,struct Elems* elems){

        char ____BAH_COMPILER_VAR_1007 = 0;
        for(int i=compilerState.evals->length-1; i!=-1;i--) {
            if (compilerState.evals->data[i] != 0 && strcmp(compilerState.evals->data[i], fn->name) == 0) {
                ____BAH_COMPILER_VAR_1007=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_1007) {
return;
}
char** ____BAH_COMPILER_VAR_1008 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1008[1] = fn->name;____BAH_COMPILER_VAR_1008[0] = "__Bah_eval_";char * ____BAH_COMPILER_VAR_1009 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1008, 2);struct func* ____BAH_COMPILER_VAR_1010 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_1010->name = "";
____BAH_COMPILER_VAR_1010->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_1010->args->length = 0;
            ____BAH_COMPILER_VAR_1010->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_1010->from = "";
____BAH_COMPILER_VAR_1010->file = "";
____BAH_COMPILER_VAR_1010->line = 1;
____BAH_COMPILER_VAR_1010->name = ____BAH_COMPILER_VAR_1009;
struct func* efn = ____BAH_COMPILER_VAR_1010;
struct variable* ____BAH_COMPILER_VAR_1011 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1011->name = "";
____BAH_COMPILER_VAR_1011->type = "";
____BAH_COMPILER_VAR_1011->constVal = "";
____BAH_COMPILER_VAR_1011->from = "";
____BAH_COMPILER_VAR_1011->type = "ptr";
efn->returns = ____BAH_COMPILER_VAR_1011;
struct variable* ____BAH_COMPILER_VAR_1012 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1012->name = "";
____BAH_COMPILER_VAR_1012->type = "";
____BAH_COMPILER_VAR_1012->constVal = "";
____BAH_COMPILER_VAR_1012->from = "";
____BAH_COMPILER_VAR_1012->name = "fnArgs";
____BAH_COMPILER_VAR_1012->type = "[]ptr";
efn->args = memoryAlloc(sizeof(array(struct variable*)));

efn->args->length = 1;
efn->args->elemSize = sizeof(struct variable*);
efn->args->data = memoryAlloc(sizeof(struct variable*) * 50);
                    efn->args->realLength = 50;
efn->args->data[0] = ____BAH_COMPILER_VAR_1012;
char * fnBinding = "";
char** ____BAH_COMPILER_VAR_1013 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1013[1] = "(";____BAH_COMPILER_VAR_1013[0] = fn->name;char * ____BAH_COMPILER_VAR_1014 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1013, 2);char * fnCall = ____BAH_COMPILER_VAR_1014;
register long int i = 0;
for (; (i<len(fn->args)); ++i) {
struct variable* a = fn->args->data[i];
char * v = genCompilerVar();
struct string cType = getCType(a->type,elems);
if ((isRCPpointerType(a->type)==false)) {
string__append(&cType,"*");
}
char** ____BAH_COMPILER_VAR_1015 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_1015[5] = "];";____BAH_COMPILER_VAR_1015[4] = intToStr(i);____BAH_COMPILER_VAR_1015[3] = " = fnArgs->data[";____BAH_COMPILER_VAR_1015[2] = v;____BAH_COMPILER_VAR_1015[1] = " ";____BAH_COMPILER_VAR_1015[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_1016 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1015, 6);char** ____BAH_COMPILER_VAR_1017 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1017[1] = ____BAH_COMPILER_VAR_1016;____BAH_COMPILER_VAR_1017[0] = fnBinding;char * ____BAH_COMPILER_VAR_1018 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1017, 2);fnBinding = ____BAH_COMPILER_VAR_1018;
if ((i!=0)) {
char** ____BAH_COMPILER_VAR_1019 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1019[1] = ", ";____BAH_COMPILER_VAR_1019[0] = fnCall;char * ____BAH_COMPILER_VAR_1020 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1019, 2);fnCall = ____BAH_COMPILER_VAR_1020;
}
if (isRCPpointerType(a->type)) {
char** ____BAH_COMPILER_VAR_1021 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1021[1] = v;____BAH_COMPILER_VAR_1021[0] = fnCall;char * ____BAH_COMPILER_VAR_1022 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1021, 2);fnCall = ____BAH_COMPILER_VAR_1022;
}
else {
char** ____BAH_COMPILER_VAR_1023 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1023[1] = v;____BAH_COMPILER_VAR_1023[0] = "*";char * ____BAH_COMPILER_VAR_1024 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1023, 2);char** ____BAH_COMPILER_VAR_1025 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1025[1] = ____BAH_COMPILER_VAR_1024;____BAH_COMPILER_VAR_1025[0] = fnCall;char * ____BAH_COMPILER_VAR_1026 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1025, 2);fnCall = ____BAH_COMPILER_VAR_1026;
}
};
char * setReturnValue = "void* r = 0;";
if (isRCPpointerType(fn->returns->type)) {
setReturnValue = "void* r = ";
}
else {
struct string cType = getCType(fn->returns->type,elems);
if ((strcmp(string__str(&cType), "void") != 0)) {
char** ____BAH_COMPILER_VAR_1027 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1027[3] = "));*r = ";____BAH_COMPILER_VAR_1027[2] = string__str(&cType);____BAH_COMPILER_VAR_1027[1] = "* r = memoryAlloc(sizeof(";____BAH_COMPILER_VAR_1027[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_1028 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1027, 4);setReturnValue = ____BAH_COMPILER_VAR_1028;
}
}
char** ____BAH_COMPILER_VAR_1029 = alloca(12 * sizeof(char*));____BAH_COMPILER_VAR_1029[11] = ");\n        return (void*)r;\n    };";____BAH_COMPILER_VAR_1029[10] = fnCall;____BAH_COMPILER_VAR_1029[9] = setReturnValue;____BAH_COMPILER_VAR_1029[8] = "\n        ";____BAH_COMPILER_VAR_1029[7] = fnBinding;____BAH_COMPILER_VAR_1029[6] = "() with the wrong number of arguments.\", \"BAH_COMPILER_INTERNAL\");\n        }\n        ";____BAH_COMPILER_VAR_1029[5] = fn->name;____BAH_COMPILER_VAR_1029[4] = ") {\n            __BAH_panic((char*)\"eval: calling function ";____BAH_COMPILER_VAR_1029[3] = intToStr(len(fn->args));____BAH_COMPILER_VAR_1029[2] = "(array(void*)* fnArgs) {\n        if (fnArgs->length != ";____BAH_COMPILER_VAR_1029[1] = efn->name;____BAH_COMPILER_VAR_1029[0] = "void* __attribute__((optimize(\"O0\"))) ";char * ____BAH_COMPILER_VAR_1030 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1029, 12);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1030));

    unsigned int ____BAH_COMPILER_VAR_1031 = len(compilerState.evals);
    __Bah_realocate_arr(compilerState.evals, ____BAH_COMPILER_VAR_1031);
    compilerState.evals->data[____BAH_COMPILER_VAR_1031] = fn->name;

    unsigned int ____BAH_COMPILER_VAR_1032 = len(elems->fns);
    __Bah_realocate_arr(elems->fns, ____BAH_COMPILER_VAR_1032);
    elems->fns->data[____BAH_COMPILER_VAR_1032] = efn;
};
void parsePreKeyword(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
struct Tok ft = l->data[0];
if ((strcmp(ft.cont, "#warning") == 0)) {
if ((len(l)!=2)) {
throwErr(&ft,"Invalid usage of {TOKEN} '#warning \"message\"'.");
}
struct Tok mt = l->data[1];
if ((mt.type!=TOKEN_TYPE_STR)) {
throwErr(&mt,"Cannot use {TOKEN} as a string.");
}
struct string msg = string(mt.cont);
string__trimLeft(&msg,1);
string__trimRight(&msg,1);
char * ____BAH_COMPILER_VAR_1033 =string__str(&msg);throwWarning(____BAH_COMPILER_VAR_1033);
return;
}
if ((strcmp(ft.cont, "#eval") == 0)) {

        char ____BAH_COMPILER_VAR_1034 = 0;
        for(int i=compilerState.includes->length-1; i!=-1;i--) {
            if (compilerState.includes->data[i] != 0 && strcmp(compilerState.includes->data[i], "eval.bah") == 0) {
                ____BAH_COMPILER_VAR_1034=1;
                break;
            };
        }
        if ((____BAH_COMPILER_VAR_1034==false)) {
if ((includeFile("eval.bah",elems)==false)) {
char** ____BAH_COMPILER_VAR_1035 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1035[2] = ").";____BAH_COMPILER_VAR_1035[1] = BAH_DIR;____BAH_COMPILER_VAR_1035[0] = "Could not find file 'eval.bah'. Check your bah directory (";char * ____BAH_COMPILER_VAR_1036 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1035, 3);throwErr(&l->data[0],____BAH_COMPILER_VAR_1036);
}
}
if ((len(l)!=2)||(isGlobal()==false)) {
throwErr(&l->data[0],"Invalid usage of {TOKEN} <#eval fnName>.");
}
struct Tok fnT = l->data[1];
struct func* fn = searchFunc(fnT.cont,elems,false);
if ((fn==null)) {
throwErr(&fnT,"Unknown function {TOKEN}.");
}
fn->used = true;
makeEvalFunc(fn,elems);
return;
}
if ((strcmp(ft.cont, "#evalAll") == 0)) {
register long int i = 0;
for (; (i<len(elems->fns)); ++i) {
struct func* fn = elems->fns->data[i];
fn->used = true;
if ((fn->isBinding==false)&&(strHasPrefix(fn->name,"__Bah_eval_")==false)) {
makeEvalFunc(fn,elems);
}
};
return;
}
if ((len(l)<3)) {
throwErr(&ft,"Invalid usage of keyword {TOKEN}.");
}
if ((strcmp(ft.cont, "#linux") == 0)||(strcmp(ft.cont, "#windows") == 0)||(strcmp(ft.cont, "#darwin") == 0)) {
struct string isOS = string(ft.cont);
string__trimLeft(&isOS,1);
if ((strcmp(string__str(&isOS), BAH_OS) != 0)) {
return;
}
}
else if ((strcmp(ft.cont, "#static") == 0)) {
if ((flags__isSet(&flags,"d")==1)) {
return;
}
}
else if ((strcmp(ft.cont, "#dynamic") == 0)) {
if ((flags__isSet(&flags,"d")==0)) {
return;
}
}
else if ((strcmp(ft.cont, "#gc") == 0)) {
if ((RCPavailable()==true)) {
return;
}
}
else if ((strcmp(ft.cont, "#rcp") == 0)) {
if ((RCPavailable()==false)) {
return;
}
}
else if ((strcmp(ft.cont, "#lib") == 0)) {
if ((flags__isSet(&flags,"l")==0)) {
return;
}
}
else if ((strcmp(ft.cont, "#exec") == 0)) {
if ((flags__isSet(&flags,"l")==1)) {
return;
}
}
else if ((strcmp(ft.cont, "#imported") == 0)) {
if ((isSubObject==false)||(isObject==false)) {
return;
}
}
else if ((strcmp(ft.cont, "#included") == 0)) {
if ((isSubObject==true)||(isObject==true)) {
return;
}
}
else if ((strcmp(ft.cont, "#optimized") == 0)) {
if ((isOptimized==false)) {
return;
}
}
else if ((strcmp(ft.cont, "#unoptimized") == 0)) {
if ((isOptimized==true)) {
return;
}
}
else {
throwErr(&ft,"Undefined token {TOKEN}.");
}
struct Tok st = l->data[1];
struct Tok lt = l->data[len(l)-1];
if ((strcmp(st.cont, "{") != 0)||(strcmp(lt.cont, "}") != 0)) {
throwErr(&st,"Expected code block after keyword {TOKEN}.");
}
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
register long int i = 2;
while ((i<len(l)-1)) {

    unsigned int ____BAH_COMPILER_VAR_1037 = i-2;
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_1037);
    nl->data[____BAH_COMPILER_VAR_1037] = l->data[i];
i = i+1;
};
parseLines(nl,elems);
};
void parseAsync(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
if ((len(l)!=2)) {
struct Tok ft = l->data[0];
throwErr(&ft,"Cannot use keyword {TOKEN} on a function call 'async <function call>'.");
}
struct Tok fnT = l->data[1];
if ((fnT.isFunc==false)) {
throwErr(&fnT,"Cannot use keyword async on {TOKEN}. Usage: 'async <function call>'.");
}
char found = false;
register long int i = 0;
while ((i<len(compilerState.cLibs))) {
if ((strcmp(compilerState.cLibs->data[i], "lpthread") == 0)) {
found = true;
break;
}
i = i+1;
};
if ((found==false)) {

    unsigned int ____BAH_COMPILER_VAR_1038 = len(compilerState.cLibs);
    __Bah_realocate_arr(compilerState.cLibs, ____BAH_COMPILER_VAR_1038);
    compilerState.cLibs->data[____BAH_COMPILER_VAR_1038] = "lpthread";
}
struct string sFnT = string(fnT.cont);
array(struct string)* fnNameParts = splitString(sFnT,"(");
struct string fnName = fnNameParts->data[0];
struct func* fn = searchFuncByToken(&fnT,elems);
if ((fn==null)) {
char** ____BAH_COMPILER_VAR_1039 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1039[2] = "', arround {TOKEN}.";____BAH_COMPILER_VAR_1039[1] = string__str(&fnName);____BAH_COMPILER_VAR_1039[0] = "Internal compiler error.\n Error parsing async call for function '";char * ____BAH_COMPILER_VAR_1040 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1039, 3);throwErr(&fnT,____BAH_COMPILER_VAR_1040);
}
fnName = string(fn->name);
char * sMembs = "";
char * unSerMembs = "";
i = 0;
while ((i<len(fn->args))) {
struct variable* a = fn->args->data[i];
struct string cType = getCType(a->type,elems);
char** ____BAH_COMPILER_VAR_1041 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1041[4] = ";\n";____BAH_COMPILER_VAR_1041[3] = a->name;____BAH_COMPILER_VAR_1041[2] = " ";____BAH_COMPILER_VAR_1041[1] = string__str(&cType);____BAH_COMPILER_VAR_1041[0] = sMembs;char * ____BAH_COMPILER_VAR_1042 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1041, 5);sMembs = ____BAH_COMPILER_VAR_1042;
char** ____BAH_COMPILER_VAR_1043 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1043[2] = a->name;____BAH_COMPILER_VAR_1043[1] = "args->";____BAH_COMPILER_VAR_1043[0] = unSerMembs;char * ____BAH_COMPILER_VAR_1044 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1043, 3);unSerMembs = ____BAH_COMPILER_VAR_1044;
i = i+1;
if ((i<len(fn->args))) {
char** ____BAH_COMPILER_VAR_1045 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1045[1] = ", ";____BAH_COMPILER_VAR_1045[0] = unSerMembs;char * ____BAH_COMPILER_VAR_1046 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1045, 2);unSerMembs = ____BAH_COMPILER_VAR_1046;
}
};
char** ____BAH_COMPILER_VAR_1047 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1047[2] = "}";____BAH_COMPILER_VAR_1047[1] = sMembs;____BAH_COMPILER_VAR_1047[0] = "struct {\n";char * ____BAH_COMPILER_VAR_1048 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1047, 3);char * tmpArgsStruct = ____BAH_COMPILER_VAR_1048;
char * fnWrapper = genCompilerVar();
char * tmpArgs = genCompilerVar();
string__trimLeft(&sFnT,fnName.length+1);
string__trimRight(&sFnT,1);
char * tCreate = "";
if ((strcmp(BAH_OS, "windows") == 0)) {
tCreate = "pthread_create";
}
else {
if (RCPavailable()) {
tCreate = "pthread_create";
}
else {
tCreate = "GC_pthread_create";
}
}
char** ____BAH_COMPILER_VAR_1049 = alloca(21 * sizeof(char*));____BAH_COMPILER_VAR_1049[20] = ");\n    }; \n    \n    ";____BAH_COMPILER_VAR_1049[19] = tmpArgs;____BAH_COMPILER_VAR_1049[18] = ", &";____BAH_COMPILER_VAR_1049[17] = fnWrapper;____BAH_COMPILER_VAR_1049[16] = "(&id, 0, ";____BAH_COMPILER_VAR_1049[15] = tCreate;____BAH_COMPILER_VAR_1049[14] = "};\n        pthread_t id;\n        ";____BAH_COMPILER_VAR_1049[13] = string__str(&sFnT);____BAH_COMPILER_VAR_1049[12] = " = {";____BAH_COMPILER_VAR_1049[11] = tmpArgs;____BAH_COMPILER_VAR_1049[10] = " ";____BAH_COMPILER_VAR_1049[9] = tmpArgsStruct;____BAH_COMPILER_VAR_1049[8] = ");\n    };\n    {\n        ";____BAH_COMPILER_VAR_1049[7] = unSerMembs;____BAH_COMPILER_VAR_1049[6] = "(";____BAH_COMPILER_VAR_1049[5] = string__str(&fnName);____BAH_COMPILER_VAR_1049[4] = "* args) {\n        ";____BAH_COMPILER_VAR_1049[3] = tmpArgsStruct;____BAH_COMPILER_VAR_1049[2] = "(";____BAH_COMPILER_VAR_1049[1] = fnWrapper;____BAH_COMPILER_VAR_1049[0] = "\n    void ";char * ____BAH_COMPILER_VAR_1050 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1049, 21);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1050));
};
void addRCPvars(__BAH_ARR_TYPE_Tok l,lineType ltp,struct Elems* elems){
register long int i = 0;
if ((ltp==LINE_TYPE_VAR)) {
i = 1;
}
while ((i<len(l))) {
struct Tok t = l->data[i];
if ((t.type==TOKEN_TYPE_VAR)&&(t.isOper==false)) {
struct variable* v = searchVirtVarByToken(&t,elems);
if ((v!=null)) {

    unsigned int ____BAH_COMPILER_VAR_1051 = len(compilerState.RCPvars);
    __Bah_realocate_arr(compilerState.RCPvars, ____BAH_COMPILER_VAR_1051);
    compilerState.RCPvars->data[____BAH_COMPILER_VAR_1051] = v;
}
}
i = i+1;
};
};
__BAH_ARR_TYPE_Tok parseChan(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
register long int i = 0;
for (; (i<len(l)); ++i) {
struct Tok t = l->data[i];
if ((t.type==TOKEN_TYPE_SYNTAX)&&(strcmp(t.cont, "->") == 0)||(strcmp(t.cont, "<-") == 0)) {
if ((strcmp(t.cont, "<-") == 0)) {
++i;
if ((i<len(l))) {
struct Tok nt = l->data[i];
if ((nt.type!=TOKEN_TYPE_VAR)) {
throwErr(&nt,"Cannot use {TOKEN} as channel.");
}
char * ____BAH_COMPILER_VAR_1052 =getTypeFromToken(&nt,true,elems);struct string ntt = string(____BAH_COMPILER_VAR_1052);
if ((string__hasPrefix(&ntt,"chan:")==0)) {
char** ____BAH_COMPILER_VAR_1053 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1053[2] = ") as channel.";____BAH_COMPILER_VAR_1053[1] = string__str(&ntt);____BAH_COMPILER_VAR_1053[0] = "Cannot use var {TOKEN} (";char * ____BAH_COMPILER_VAR_1054 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1053, 3);throwErr(&nt,____BAH_COMPILER_VAR_1054);
}
string__trimLeft(&ntt,5);
if (isGlobal()) {
throwErr(&t,"Cannot receive ({TOKEN}) from a channel outside of a function.");
}
char * tmpV = "";
char * ____BAH_COMPILER_VAR_1055 =string__str(&ntt);if (isRCPpointerType(____BAH_COMPILER_VAR_1055)) {
char * ____BAH_COMPILER_VAR_1056 =string__str(&ntt);struct string ct = getCType(____BAH_COMPILER_VAR_1056,elems);
char** ____BAH_COMPILER_VAR_1057 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_1057[6] = ")";____BAH_COMPILER_VAR_1057[5] = nt.cont;____BAH_COMPILER_VAR_1057[4] = "->receive(";____BAH_COMPILER_VAR_1057[3] = nt.cont;____BAH_COMPILER_VAR_1057[2] = ")";____BAH_COMPILER_VAR_1057[1] = string__str(&ct);____BAH_COMPILER_VAR_1057[0] = "(";char * ____BAH_COMPILER_VAR_1058 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1057, 7);t.cont = ____BAH_COMPILER_VAR_1058;
}
else {
char * ____BAH_COMPILER_VAR_1059 =string__str(&ntt);struct string ct = getCType(____BAH_COMPILER_VAR_1059,elems);
if (RCPavailable()) {
char** ____BAH_COMPILER_VAR_1060 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1060[1] = "*";____BAH_COMPILER_VAR_1060[0] = string__str(&ntt);char * ____BAH_COMPILER_VAR_1061 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1060, 2);char** ____BAH_COMPILER_VAR_1062 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_1062[6] = ")";____BAH_COMPILER_VAR_1062[5] = nt.cont;____BAH_COMPILER_VAR_1062[4] = "->receive(";____BAH_COMPILER_VAR_1062[3] = nt.cont;____BAH_COMPILER_VAR_1062[2] = "*)";____BAH_COMPILER_VAR_1062[1] = string__str(&ct);____BAH_COMPILER_VAR_1062[0] = "(";char * ____BAH_COMPILER_VAR_1063 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1062, 7);tmpV = registerRCPvar(____BAH_COMPILER_VAR_1061,____BAH_COMPILER_VAR_1063,elems);
char** ____BAH_COMPILER_VAR_1064 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1064[1] = tmpV;____BAH_COMPILER_VAR_1064[0] = "*";char * ____BAH_COMPILER_VAR_1065 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1064, 2);t.cont = ____BAH_COMPILER_VAR_1065;
}
else {
char** ____BAH_COMPILER_VAR_1066 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_1066[6] = ")";____BAH_COMPILER_VAR_1066[5] = nt.cont;____BAH_COMPILER_VAR_1066[4] = "->receive(";____BAH_COMPILER_VAR_1066[3] = nt.cont;____BAH_COMPILER_VAR_1066[2] = "*)";____BAH_COMPILER_VAR_1066[1] = string__str(&ct);____BAH_COMPILER_VAR_1066[0] = "*(";char * ____BAH_COMPILER_VAR_1067 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1066, 7);t.cont = ____BAH_COMPILER_VAR_1067;
}
}
t.type = TOKEN_TYPE_FUNC;
t.isFunc = true;
if (RCPavailable()) {
char * ____BAH_COMPILER_VAR_1068 =string__str(&ntt);if (isRCPpointerType(____BAH_COMPILER_VAR_1068)) {
char * ____BAH_COMPILER_VAR_1069 =string__str(&ntt);tmpV = registerRCPvar(____BAH_COMPILER_VAR_1069,t.cont,elems);
t.type = TOKEN_TYPE_VAR;
t.isFunc = false;
t.cont = tmpV;
}
else {
}
}
t.isValue = true;
t.bahType = string__str(&ntt);
}
else {
throwErr(&t,"Cannot use {TOKEN} on nothing");
}
}
else {
if ((i==0)) {
throwErr(&t,"Cannot une {TOKEN} on nothing.");
}
if ((i+1>=len(l))) {
throwErr(&t,"Cannot send ({TOKEN}) to nothing.");
}
struct Tok pt = l->data[i+1];
struct Tok nt = l->data[i-1];
char * ntt = getTypeFromToken(&nt,true,elems);
if ((pt.type!=TOKEN_TYPE_VAR)) {
throwErr(&pt,"Cannot use {TOKEN} as channel.");
}
char * ____BAH_COMPILER_VAR_1070 =getTypeFromToken(&pt,true,elems);struct string ptt = string(____BAH_COMPILER_VAR_1070);
if ((string__hasPrefix(&ptt,"chan:")==0)) {
char** ____BAH_COMPILER_VAR_1071 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1071[2] = ") as channel.";____BAH_COMPILER_VAR_1071[1] = ntt;____BAH_COMPILER_VAR_1071[0] = "Cannot use var {TOKEN} (";char * ____BAH_COMPILER_VAR_1072 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1071, 3);throwErr(&pt,____BAH_COMPILER_VAR_1072);
}
string__trimLeft(&ptt,5);
if (isGlobal()) {
throwErr(&t,"Cannot send ({TOKEN}) to a channel outside of a function.");
}
char * ____BAH_COMPILER_VAR_1073 =string__str(&ptt);if ((compTypes(____BAH_COMPILER_VAR_1073,ntt)==false)) {
char** ____BAH_COMPILER_VAR_1074 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1074[4] = ".";____BAH_COMPILER_VAR_1074[3] = string__str(&ptt);____BAH_COMPILER_VAR_1074[2] = ") to channel of type ";____BAH_COMPILER_VAR_1074[1] = ntt;____BAH_COMPILER_VAR_1074[0] = "Cannot send {TOKEN} (";char * ____BAH_COMPILER_VAR_1075 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1074, 5);throwErr(&nt,____BAH_COMPILER_VAR_1075);
}
++i;
char * ____BAH_COMPILER_VAR_1076 =string__str(&ptt);if (isRCPpointerType(____BAH_COMPILER_VAR_1076)) {
char** ____BAH_COMPILER_VAR_1077 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_1077[5] = ");\n";____BAH_COMPILER_VAR_1077[4] = nt.cont;____BAH_COMPILER_VAR_1077[3] = ", ";____BAH_COMPILER_VAR_1077[2] = pt.cont;____BAH_COMPILER_VAR_1077[1] = "->send(";____BAH_COMPILER_VAR_1077[0] = pt.cont;char * ____BAH_COMPILER_VAR_1078 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1077, 6);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1078));
}
else {
struct string ct = getCType(ntt,elems);
char * tmpV = genCompilerVar();
char** ____BAH_COMPILER_VAR_1079 = alloca(15 * sizeof(char*));____BAH_COMPILER_VAR_1079[14] = "));\n";____BAH_COMPILER_VAR_1079[13] = tmpV;____BAH_COMPILER_VAR_1079[12] = ", sizeof(";____BAH_COMPILER_VAR_1079[11] = tmpV;____BAH_COMPILER_VAR_1079[10] = ", &";____BAH_COMPILER_VAR_1079[9] = pt.cont;____BAH_COMPILER_VAR_1079[8] = "->sendAny(";____BAH_COMPILER_VAR_1079[7] = pt.cont;____BAH_COMPILER_VAR_1079[6] = ";\n                    ";____BAH_COMPILER_VAR_1079[5] = nt.cont;____BAH_COMPILER_VAR_1079[4] = " = ";____BAH_COMPILER_VAR_1079[3] = tmpV;____BAH_COMPILER_VAR_1079[2] = " ";____BAH_COMPILER_VAR_1079[1] = string__str(&ct);____BAH_COMPILER_VAR_1079[0] = "\n                    ";char * ____BAH_COMPILER_VAR_1080 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1079, 15);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1080));
}
nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
return nl;
}
}

    unsigned int ____BAH_COMPILER_VAR_1081 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_1081);
    nl->data[____BAH_COMPILER_VAR_1081] = t;
};
return nl;
};
long int valueFunc(struct func* fn,struct variable* parent,__BAH_ARR_TYPE_Tok l,long int i,lineType ltp,struct Elems* elems){
long int tokPos = i;
long int errPos = -1;
if ((fn==null)) {
if ((i>0)) {
tokPos = i-1;
struct Tok pt = l->data[tokPos];
if ((pt.type==TOKEN_TYPE_VAR)) {
delete(l,tokPos);
errPos = pt.pos;
fn = searchFunc(pt.cont,elems,true);
if ((fn==null)) {
throwErr(&pt,"Unknown func {TOKEN}.");
}
}
else {
++tokPos;
}
}
else {
return i;
}
}
struct Tok fnt = l->data[tokPos];
if ((errPos!=-1)) {
fnt.pos = errPos;
}
if ((fn==null)) {
long int nbEncls = 1;
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
i = tokPos+1;
fnt.ogCont = "(";
for (; (i<len(l)); ++i) {
struct Tok t = l->data[i];
char** ____BAH_COMPILER_VAR_1082 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1082[1] = t.ogCont;____BAH_COMPILER_VAR_1082[0] = fnt.ogCont;char * ____BAH_COMPILER_VAR_1083 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1082, 2);fnt.ogCont = ____BAH_COMPILER_VAR_1083;
if ((strcmp(t.cont, "(") == 0)||(strcmp(t.cont, "{") == 0)||(strcmp(t.cont, "[") == 0)) {
++nbEncls;
}
else if ((strcmp(t.cont, ")") == 0)||(strcmp(t.cont, "}") == 0)||(strcmp(t.cont, "]") == 0)) {
--nbEncls;
if ((nbEncls==0)) {
break;
}
}

    unsigned int ____BAH_COMPILER_VAR_1084 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1084);
    memory->data[____BAH_COMPILER_VAR_1084] = t;
};
deleteRange(l,tokPos+1,i);
array(struct Tok)* memort = prePross(memory,(lineType)-1,elems);
struct Tok ft = memory->data[0];
fnt.cont = "(";
fnt.isOper = true;
fnt.isValue = true;
fnt.bahType = getTypeFromToken(&ft,true,elems);
register long int j = 0;
for (; (j<len(memory)); ++j) {
struct Tok t = memory->data[j];
char** ____BAH_COMPILER_VAR_1085 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1085[1] = t.cont;____BAH_COMPILER_VAR_1085[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1086 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1085, 2);fnt.cont = ____BAH_COMPILER_VAR_1086;
};
char** ____BAH_COMPILER_VAR_1087 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1087[1] = ")";____BAH_COMPILER_VAR_1087[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1088 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1087, 2);fnt.cont = ____BAH_COMPILER_VAR_1088;

    unsigned int ____BAH_COMPILER_VAR_1089 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1089);
    l->data[____BAH_COMPILER_VAR_1089] = fnt;
return tokPos;
}
if ((strcmp(fn->name, "exit") == 0)||(fn->exits==true)) {
setNullStateBranchFlowEnd(elems);
}
char** ____BAH_COMPILER_VAR_1090 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1090[1] = "(";____BAH_COMPILER_VAR_1090[0] = fn->name;char * ____BAH_COMPILER_VAR_1091 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1090, 2);fnt.cont = ____BAH_COMPILER_VAR_1091;
if ((fn->returns!=null)&&(strcmp(fn->returns->type, "") != 0)) {
fnt.isValue = true;
fnt.bahType = fn->returns->type;
}
fnt.isFunc = true;
fnt.type = TOKEN_TYPE_FUNC;
long int nbEncls = 1;
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
i = tokPos+1;
char** ____BAH_COMPILER_VAR_1092 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1092[1] = "(";____BAH_COMPILER_VAR_1092[0] = fn->name;char * ____BAH_COMPILER_VAR_1093 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1092, 2);fnt.ogCont = ____BAH_COMPILER_VAR_1093;
for (; (i<len(l)); ++i) {
struct Tok t = l->data[i];
char** ____BAH_COMPILER_VAR_1094 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1094[1] = t.ogCont;____BAH_COMPILER_VAR_1094[0] = fnt.ogCont;char * ____BAH_COMPILER_VAR_1095 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1094, 2);fnt.ogCont = ____BAH_COMPILER_VAR_1095;
if ((strcmp(t.cont, "(") == 0)||(strcmp(t.cont, "{") == 0)||(strcmp(t.cont, "[") == 0)) {
++nbEncls;
}
else if ((strcmp(t.cont, ")") == 0)||(strcmp(t.cont, "}") == 0)||(strcmp(t.cont, "]") == 0)) {
--nbEncls;
if ((nbEncls==0)) {
break;
}
}

    unsigned int ____BAH_COMPILER_VAR_1096 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1096);
    memory->data[____BAH_COMPILER_VAR_1096] = t;
};
deleteRange(l,tokPos+1,i);
if ((strcmp(fn->name, "noCheck") == 0)) {
fnt.cont = "";
fnt.isOper = true;
fnt.isValue = true;
fnt.bahType = "ptr";
register long int j = 0;
for (; (j<len(memory)); ++j) {
struct Tok t = memory->data[j];
char** ____BAH_COMPILER_VAR_1097 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1097[1] = t.cont;____BAH_COMPILER_VAR_1097[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1098 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1097, 2);fnt.cont = ____BAH_COMPILER_VAR_1098;
};

    unsigned int ____BAH_COMPILER_VAR_1099 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1099);
    l->data[____BAH_COMPILER_VAR_1099] = fnt;
return tokPos;
}
char** ____BAH_COMPILER_VAR_1100 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1100[4] = "\"";____BAH_COMPILER_VAR_1100[3] = intToStr(fnt.line);____BAH_COMPILER_VAR_1100[2] = ":";____BAH_COMPILER_VAR_1100[1] = compilerState.currentFile;____BAH_COMPILER_VAR_1100[0] = "\"";char * ____BAH_COMPILER_VAR_1101 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1100, 5);char * currLine = ____BAH_COMPILER_VAR_1101;
if ((strcmp(fn->name, "panic") == 0)) {
struct Tok ____BAH_COMPILER_VAR_1102 = {};
____BAH_COMPILER_VAR_1102.cont = "";
____BAH_COMPILER_VAR_1102.ogCont = "";
____BAH_COMPILER_VAR_1102.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1102.line = 1;
____BAH_COMPILER_VAR_1102.begLine = 1;
____BAH_COMPILER_VAR_1102.bahType = "";
____BAH_COMPILER_VAR_1102.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_1102.cont = ",";
____BAH_COMPILER_VAR_1102.line = fnt.line;

    unsigned int ____BAH_COMPILER_VAR_1103 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1103);
    memory->data[____BAH_COMPILER_VAR_1103] = ____BAH_COMPILER_VAR_1102;
struct Tok ____BAH_COMPILER_VAR_1104 = {};
____BAH_COMPILER_VAR_1104.cont = "";
____BAH_COMPILER_VAR_1104.ogCont = "";
____BAH_COMPILER_VAR_1104.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1104.line = 1;
____BAH_COMPILER_VAR_1104.begLine = 1;
____BAH_COMPILER_VAR_1104.bahType = "";
____BAH_COMPILER_VAR_1104.type = TOKEN_TYPE_STR;
____BAH_COMPILER_VAR_1104.cont = currLine;
____BAH_COMPILER_VAR_1104.line = fnt.line;

    unsigned int ____BAH_COMPILER_VAR_1105 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1105);
    memory->data[____BAH_COMPILER_VAR_1105] = ____BAH_COMPILER_VAR_1104;
fn = searchFunc("__BAH_panic",elems,true);
char** ____BAH_COMPILER_VAR_1106 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1106[1] = "(";____BAH_COMPILER_VAR_1106[0] = fn->name;char * ____BAH_COMPILER_VAR_1107 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1106, 2);fnt.cont = ____BAH_COMPILER_VAR_1107;
}
else if ((strcmp(fn->name, "__dumpSymbols") == 0)) {
array(struct variable*)* symbols = memoryAlloc(sizeof(array(struct variable*)));

symbols->length = 0;
symbols->elemSize = sizeof(struct variable*);
register long int j = 0;
for (; (j<len(elems->vars)); ++j) {
struct variable* v = elems->vars->data[j];
if ((v->isConst==false)) {

    unsigned int ____BAH_COMPILER_VAR_1108 = len(symbols);
    __Bah_realocate_arr(symbols, ____BAH_COMPILER_VAR_1108);
    symbols->data[____BAH_COMPILER_VAR_1108] = v;
}
};
struct variable* ____BAH_COMPILER_VAR_1109 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1109->name = "";
____BAH_COMPILER_VAR_1109->type = "";
____BAH_COMPILER_VAR_1109->constVal = "";
____BAH_COMPILER_VAR_1109->from = "";
____BAH_COMPILER_VAR_1109->name = genCompilerVar();
____BAH_COMPILER_VAR_1109->type = "[]reflectElement";
____BAH_COMPILER_VAR_1109->isArray = true;
struct variable* tmpV = ____BAH_COMPILER_VAR_1109;
char * decls = "";
j = 0;
for (; (j<len(symbols)); ++j) {
struct variable* v = symbols->data[j];
char * vname = v->name;
if ((strCount(v->type,"*")==0)) {
char** ____BAH_COMPILER_VAR_1110 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1110[1] = v->name;____BAH_COMPILER_VAR_1110[0] = "&";char * ____BAH_COMPILER_VAR_1111 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1110, 2);vname = ____BAH_COMPILER_VAR_1111;
}
struct Tok ____BAH_COMPILER_VAR_1112 = {};
____BAH_COMPILER_VAR_1112.cont = "";
____BAH_COMPILER_VAR_1112.ogCont = "";
____BAH_COMPILER_VAR_1112.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1112.line = 1;
____BAH_COMPILER_VAR_1112.begLine = 1;
____BAH_COMPILER_VAR_1112.bahType = "";
____BAH_COMPILER_VAR_1112.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_1112.cont = vname;
____BAH_COMPILER_VAR_1112.bahType = v->type;
____BAH_COMPILER_VAR_1112.isValue = true;
#define tmpT ____BAH_COMPILER_VAR_1112
tmpT = parseReflect(tmpT,v->type,elems,true,v->name,"0");
char** ____BAH_COMPILER_VAR_1113 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_1113[5] = ";\n";____BAH_COMPILER_VAR_1113[4] = tmpT.cont;____BAH_COMPILER_VAR_1113[3] = "] = ";____BAH_COMPILER_VAR_1113[2] = intToStr(j);____BAH_COMPILER_VAR_1113[1] = "->data[";____BAH_COMPILER_VAR_1113[0] = tmpV->name;char * ____BAH_COMPILER_VAR_1114 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1113, 6);char** ____BAH_COMPILER_VAR_1115 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1115[1] = ____BAH_COMPILER_VAR_1114;____BAH_COMPILER_VAR_1115[0] = decls;char * ____BAH_COMPILER_VAR_1116 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1115, 2);decls = ____BAH_COMPILER_VAR_1116;

#undef tmpT
};

    unsigned int ____BAH_COMPILER_VAR_1117 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_1117);
    elems->vars->data[____BAH_COMPILER_VAR_1117] = tmpV;
char** ____BAH_COMPILER_VAR_1118 = alloca(15 * sizeof(char*));____BAH_COMPILER_VAR_1118[14] = "\n        ";____BAH_COMPILER_VAR_1118[13] = decls;____BAH_COMPILER_VAR_1118[12] = "->elemSize = sizeof(struct reflectElement);\n        ";____BAH_COMPILER_VAR_1118[11] = tmpV->name;____BAH_COMPILER_VAR_1118[10] = ";\n        ";____BAH_COMPILER_VAR_1118[9] = intToStr(len(symbols));____BAH_COMPILER_VAR_1118[8] = "->length = ";____BAH_COMPILER_VAR_1118[7] = tmpV->name;____BAH_COMPILER_VAR_1118[6] = ");\n        ";____BAH_COMPILER_VAR_1118[5] = intToStr(len(symbols));____BAH_COMPILER_VAR_1118[4] = "->data = memoryAlloc(sizeof(struct reflectElement) * ";____BAH_COMPILER_VAR_1118[3] = tmpV->name;____BAH_COMPILER_VAR_1118[2] = " = memoryAlloc(sizeof(array(struct reflectElement)));\n        ";____BAH_COMPILER_VAR_1118[1] = tmpV->name;____BAH_COMPILER_VAR_1118[0] = "\n        array(struct reflectElement)* ";char * ____BAH_COMPILER_VAR_1119 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1118, 15);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1119));
struct Tok ____BAH_COMPILER_VAR_1120 = {};
____BAH_COMPILER_VAR_1120.cont = "";
____BAH_COMPILER_VAR_1120.ogCont = "";
____BAH_COMPILER_VAR_1120.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1120.line = 1;
____BAH_COMPILER_VAR_1120.begLine = 1;
____BAH_COMPILER_VAR_1120.bahType = "";
____BAH_COMPILER_VAR_1120.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_1120.cont = tmpV->name;
____BAH_COMPILER_VAR_1120.line = fnt.line;
____BAH_COMPILER_VAR_1120.isValue = true;

    unsigned int ____BAH_COMPILER_VAR_1121 = 0;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1121);
    memory->data[____BAH_COMPILER_VAR_1121] = ____BAH_COMPILER_VAR_1120;
}
else if ((strcmp(fn->name, "breakPoint") == 0)) {
struct Tok ____BAH_COMPILER_VAR_1122 = {};
____BAH_COMPILER_VAR_1122.cont = "";
____BAH_COMPILER_VAR_1122.ogCont = "";
____BAH_COMPILER_VAR_1122.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1122.line = 1;
____BAH_COMPILER_VAR_1122.begLine = 1;
____BAH_COMPILER_VAR_1122.bahType = "";
____BAH_COMPILER_VAR_1122.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_1122.cont = "__dumpSymbols";
____BAH_COMPILER_VAR_1122.line = fnt.line;
struct Tok ____BAH_COMPILER_VAR_1123 = {};
____BAH_COMPILER_VAR_1123.cont = "";
____BAH_COMPILER_VAR_1123.ogCont = "";
____BAH_COMPILER_VAR_1123.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1123.line = 1;
____BAH_COMPILER_VAR_1123.begLine = 1;
____BAH_COMPILER_VAR_1123.bahType = "";
____BAH_COMPILER_VAR_1123.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_1123.cont = "(";
____BAH_COMPILER_VAR_1123.line = fnt.line;
struct Tok ____BAH_COMPILER_VAR_1124 = {};
____BAH_COMPILER_VAR_1124.cont = "";
____BAH_COMPILER_VAR_1124.ogCont = "";
____BAH_COMPILER_VAR_1124.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1124.line = 1;
____BAH_COMPILER_VAR_1124.begLine = 1;
____BAH_COMPILER_VAR_1124.bahType = "";
____BAH_COMPILER_VAR_1124.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_1124.cont = ")";
____BAH_COMPILER_VAR_1124.line = fnt.line;
memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 3;
memory->elemSize = sizeof(struct Tok);
memory->data = memoryAlloc(sizeof(struct Tok) * 50);
                    memory->realLength = 50;
memory->data[0] = ____BAH_COMPILER_VAR_1122;
memory->data[1] = ____BAH_COMPILER_VAR_1123;
memory->data[2] = ____BAH_COMPILER_VAR_1124;
memory = prePross(memory,LINE_TYPE_FN_CALL,elems);
struct Tok ____BAH_COMPILER_VAR_1125 = {};
____BAH_COMPILER_VAR_1125.cont = "";
____BAH_COMPILER_VAR_1125.ogCont = "";
____BAH_COMPILER_VAR_1125.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1125.line = 1;
____BAH_COMPILER_VAR_1125.begLine = 1;
____BAH_COMPILER_VAR_1125.bahType = "";
____BAH_COMPILER_VAR_1125.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_1125.cont = ",";
____BAH_COMPILER_VAR_1125.line = fnt.line;

    unsigned int ____BAH_COMPILER_VAR_1126 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1126);
    memory->data[____BAH_COMPILER_VAR_1126] = ____BAH_COMPILER_VAR_1125;
struct Tok ____BAH_COMPILER_VAR_1127 = {};
____BAH_COMPILER_VAR_1127.cont = "";
____BAH_COMPILER_VAR_1127.ogCont = "";
____BAH_COMPILER_VAR_1127.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1127.line = 1;
____BAH_COMPILER_VAR_1127.begLine = 1;
____BAH_COMPILER_VAR_1127.bahType = "";
____BAH_COMPILER_VAR_1127.type = TOKEN_TYPE_STR;
____BAH_COMPILER_VAR_1127.cont = currLine;
____BAH_COMPILER_VAR_1127.line = fnt.line;

    unsigned int ____BAH_COMPILER_VAR_1128 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1128);
    memory->data[____BAH_COMPILER_VAR_1128] = ____BAH_COMPILER_VAR_1127;
fn = searchFunc("breakPoint__inner",elems,true);
char** ____BAH_COMPILER_VAR_1129 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1129[1] = "(";____BAH_COMPILER_VAR_1129[0] = fn->name;char * ____BAH_COMPILER_VAR_1130 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1129, 2);fnt.cont = ____BAH_COMPILER_VAR_1130;
}
else if ((strcmp(fn->name, "sizeof") == 0)) {
char * tp = "";
register long int j = 0;
for (; (j<len(memory)); ++j) {
struct Tok tmpT = memory->data[j];
char** ____BAH_COMPILER_VAR_1131 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1131[1] = tmpT.cont;____BAH_COMPILER_VAR_1131[0] = tp;char * ____BAH_COMPILER_VAR_1132 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1131, 2);tp = ____BAH_COMPILER_VAR_1132;
};
struct string cType = getCType(tp,elems);
char** ____BAH_COMPILER_VAR_1133 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1133[1] = ")";____BAH_COMPILER_VAR_1133[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_1134 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1133, 2);char** ____BAH_COMPILER_VAR_1135 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1135[1] = ____BAH_COMPILER_VAR_1134;____BAH_COMPILER_VAR_1135[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1136 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1135, 2);fnt.cont = ____BAH_COMPILER_VAR_1136;
fnt.type = TOKEN_TYPE_FUNC;
fnt.isFunc = true;
fnt.bahType = "int";
fnt.bahRef = fn;

    unsigned int ____BAH_COMPILER_VAR_1137 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1137);
    l->data[____BAH_COMPILER_VAR_1137] = fnt;
return tokPos;
}
if ((len(memory)>0)) {
memory = prePross(memory,(lineType)-1,elems);
}
long int argIndex = 0;
if ((parent!=null)) {
char * amp = "&";
if (isRCPpointerType(parent->type)) {
amp = "";
}
char** ____BAH_COMPILER_VAR_1138 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1138[1] = parent->name;____BAH_COMPILER_VAR_1138[0] = amp;char * ____BAH_COMPILER_VAR_1139 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1138, 2);char** ____BAH_COMPILER_VAR_1140 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1140[1] = ____BAH_COMPILER_VAR_1139;____BAH_COMPILER_VAR_1140[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1141 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1140, 2);fnt.cont = ____BAH_COMPILER_VAR_1141;
++argIndex;
if ((len(fn->args)>argIndex)) {
char** ____BAH_COMPILER_VAR_1142 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1142[1] = ",";____BAH_COMPILER_VAR_1142[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1143 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1142, 2);fnt.cont = ____BAH_COMPILER_VAR_1143;
}
}
register long int j = 0;
for (; (j<len(memory)); ++j) {
struct Tok t = memory->data[j];
if ((argIndex==len(fn->args))) {
throwErr(&t,"Too many arguments, expected ')' not {TOKEN}.");
}
struct variable* arg = fn->args->data[argIndex];
char * tt = getTypeFromToken(&t,true,elems);
if ((strcmp(arg->type, "reflectElement") == 0)&&(strcmp(tt, "reflectElement") != 0)) {
t = parseReflect(t,tt,elems,false,t.cont,"0");
tt = "reflectElement";
}
if ((compTypes(arg->type,tt)==false)) {
char** ____BAH_COMPILER_VAR_1144 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1144[4] = " in function call.";____BAH_COMPILER_VAR_1144[3] = arg->type;____BAH_COMPILER_VAR_1144[2] = ") as ";____BAH_COMPILER_VAR_1144[1] = tt;____BAH_COMPILER_VAR_1144[0] = "Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_1145 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1144, 5);throwErr(&t,____BAH_COMPILER_VAR_1145);
}
checkCanBeNull(&t,tt,elems);
if ((RCPavailable()==true)&&(ltp==LINE_TYPE_VAR)&&(t.type==TOKEN_TYPE_VAR)&&(t.isOper==false)&&(currSetVar!=null)&&(strcmp(t.cont, currSetVar->name) == 0)&&isRCPtype(currSetVar->type,elems)) {
OUTPUT = rope__add(OUTPUT, incrVar(currSetVar,elems));
}
if ((t.type==TOKEN_TYPE_FUNC)) {
struct func* afn = searchFuncByToken(&t,elems);
if ((afn!=null)&&(isRCPtype(afn->returns->type,elems)==true)) {
t.cont = registerRCPvar(afn->returns->type,t.cont,elems);
}
}
char** ____BAH_COMPILER_VAR_1146 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1146[1] = t.cont;____BAH_COMPILER_VAR_1146[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1147 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1146, 2);fnt.cont = ____BAH_COMPILER_VAR_1147;
++argIndex;
if ((j+1<len(memory))) {
++j;
t = memory->data[j];
if ((strcmp(t.cont, ",") != 0)) {
throwErr(&t,"Need separator between arguments, not {TOKEN}.");
}
char** ____BAH_COMPILER_VAR_1148 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1148[1] = ",";____BAH_COMPILER_VAR_1148[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1149 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1148, 2);fnt.cont = ____BAH_COMPILER_VAR_1149;
}
};
if ((argIndex!=len(fn->args))) {
struct Tok lt = l->data[tokPos];
char** ____BAH_COMPILER_VAR_1150 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1150[2] = "'.";____BAH_COMPILER_VAR_1150[1] = fn->name;____BAH_COMPILER_VAR_1150[0] = "Not enough argument {TOKEN}, calling '";char * ____BAH_COMPILER_VAR_1151 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1150, 3);throwErr(&lt,____BAH_COMPILER_VAR_1151);
}
fnt.bahRef = fn;
char** ____BAH_COMPILER_VAR_1152 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1152[1] = ")";____BAH_COMPILER_VAR_1152[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1153 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1152, 2);fnt.cont = ____BAH_COMPILER_VAR_1153;

    unsigned int ____BAH_COMPILER_VAR_1154 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1154);
    l->data[____BAH_COMPILER_VAR_1154] = fnt;
return tokPos;
};
long int valueStruct(__BAH_ARR_TYPE_Tok l,long int i,lineType ltp,struct Elems* elems){
long int tokPos = i-1;
struct Tok t = l->data[i-1];
char * tt = getTypeFromToken(&t,true,elems);
struct cStruct* s = searchStruct(tt,elems);
if ((s==null)) {
if ((tt[strlen(tt)-1]==33)) {
char** ____BAH_COMPILER_VAR_1155 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1155[2] = ") as structure.";____BAH_COMPILER_VAR_1155[1] = tt;____BAH_COMPILER_VAR_1155[0] = "Cannot use maybe value {TOKEN} (";char * ____BAH_COMPILER_VAR_1156 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1155, 3);throwErr(&t,____BAH_COMPILER_VAR_1156);
}
else {
char** ____BAH_COMPILER_VAR_1157 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1157[2] = ").";____BAH_COMPILER_VAR_1157[1] = tt;____BAH_COMPILER_VAR_1157[0] = "Unkown struct {TOKEN} (";char * ____BAH_COMPILER_VAR_1158 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1157, 3);throwErr(&t,____BAH_COMPILER_VAR_1158);
}
}
checkCanBeNull(&t,tt,elems);
struct Tok nt = l->data[i+1];
if ((nt.isValue==false)) {
throwErr(&nt,"Cannot use {TOKEN} as member.");
}
deleteRange(l,i,i+1);
char * sep = ".";
if (isRCPpointerType(tt)) {
sep = "->";
}
if ((i<len(l))) {
struct Tok ntt = l->data[i];
if ((strcmp(ntt.cont, "(") == 0)) {
struct variable* parent= null;
if ((t.type==TOKEN_TYPE_VAR)) {
parent = searchVar(t.cont,elems);
}
else {
char * tmpV = genCompilerVar();
struct string cType = getCType(tt,elems);
char** ____BAH_COMPILER_VAR_1159 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_1159[6] = ";\n                ";____BAH_COMPILER_VAR_1159[5] = t.cont;____BAH_COMPILER_VAR_1159[4] = " = ";____BAH_COMPILER_VAR_1159[3] = tmpV;____BAH_COMPILER_VAR_1159[2] = " ";____BAH_COMPILER_VAR_1159[1] = string__str(&cType);____BAH_COMPILER_VAR_1159[0] = "\n                ";char * ____BAH_COMPILER_VAR_1160 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1159, 7);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1160));
t.cont = tmpV;
struct variable* ____BAH_COMPILER_VAR_1161 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1161->name = "";
____BAH_COMPILER_VAR_1161->type = "";
____BAH_COMPILER_VAR_1161->constVal = "";
____BAH_COMPILER_VAR_1161->from = "";
____BAH_COMPILER_VAR_1161->name = tmpV;
____BAH_COMPILER_VAR_1161->type = tt;
parent = ____BAH_COMPILER_VAR_1161;
if (RCPavailable()) {

    unsigned int ____BAH_COMPILER_VAR_1162 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_1162);
    elems->vars->data[____BAH_COMPILER_VAR_1162] = parent;
}
}
struct func* fn = searchStructMethod(nt.cont,s,elems);
if ((fn==null)) {
char** ____BAH_COMPILER_VAR_1163 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1163[2] = ".";____BAH_COMPILER_VAR_1163[1] = s->name;____BAH_COMPILER_VAR_1163[0] = "Unknown method {TOKEN} in struct ";char * ____BAH_COMPILER_VAR_1164 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1163, 3);throwErr(&nt,____BAH_COMPILER_VAR_1164);
}
if ((t.type==TOKEN_TYPE_VAR)) {
if ((fn->isImported==true)||(fn->isMut==true)) {
struct variable* rp = searchVarByToken(&t,elems);
rp->lastSet = elems;
if ((rp->isArg==true)) {
currentFn->isMut = true;
}
}
}
if ((fn->isVar==true)) {
char** ____BAH_COMPILER_VAR_1165 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1165[2] = fn->name;____BAH_COMPILER_VAR_1165[1] = sep;____BAH_COMPILER_VAR_1165[0] = t.cont;char * ____BAH_COMPILER_VAR_1166 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1165, 3);fn->name = ____BAH_COMPILER_VAR_1166;
}
if ((parent==null)) {
throwErr(&t,"Could not find structure {TOKEN}.");
}
valueFunc(fn,parent,l,i,ltp,elems);
struct Tok fnt = l->data[i];
delete(l,i);
char** ____BAH_COMPILER_VAR_1167 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1167[2] = nt.ogCont;____BAH_COMPILER_VAR_1167[1] = ".";____BAH_COMPILER_VAR_1167[0] = t.ogCont;char * ____BAH_COMPILER_VAR_1168 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1167, 3);fnt.ogCont = ____BAH_COMPILER_VAR_1168;
fnt.pos = t.pos;

    unsigned int ____BAH_COMPILER_VAR_1169 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1169);
    l->data[____BAH_COMPILER_VAR_1169] = fnt;
return tokPos;
}
}
struct structMemb* m = searchStructMemb(nt.cont,s,elems);
if ((m==null)) {
char** ____BAH_COMPILER_VAR_1170 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1170[2] = "'.";____BAH_COMPILER_VAR_1170[1] = s->name;____BAH_COMPILER_VAR_1170[0] = "Unknown struct member {TOKEN} in struct '";char * ____BAH_COMPILER_VAR_1171 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1170, 3);throwErr(&nt,____BAH_COMPILER_VAR_1171);
}
if ((m->isFn==true)) {
char** ____BAH_COMPILER_VAR_1172 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1172[2] = m->name;____BAH_COMPILER_VAR_1172[1] = "__";____BAH_COMPILER_VAR_1172[0] = s->name;char * ____BAH_COMPILER_VAR_1173 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1172, 3);t.cont = ____BAH_COMPILER_VAR_1173;
}
else {
if ((t.type==TOKEN_TYPE_VAR)) {
t.parent = searchVarByToken(&t,elems);
}
char** ____BAH_COMPILER_VAR_1174 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1174[1] = nt.cont;____BAH_COMPILER_VAR_1174[0] = sep;char * ____BAH_COMPILER_VAR_1175 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1174, 2);char** ____BAH_COMPILER_VAR_1176 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1176[1] = ____BAH_COMPILER_VAR_1175;____BAH_COMPILER_VAR_1176[0] = t.cont;char * ____BAH_COMPILER_VAR_1177 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1176, 2);t.cont = ____BAH_COMPILER_VAR_1177;
}
char** ____BAH_COMPILER_VAR_1178 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1178[1] = nt.cont;____BAH_COMPILER_VAR_1178[0] = ".";char * ____BAH_COMPILER_VAR_1179 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1178, 2);char** ____BAH_COMPILER_VAR_1180 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1180[1] = ____BAH_COMPILER_VAR_1179;____BAH_COMPILER_VAR_1180[0] = t.ogCont;char * ____BAH_COMPILER_VAR_1181 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1180, 2);t.ogCont = ____BAH_COMPILER_VAR_1181;
t.bahType = m->type;
struct variable* ____BAH_COMPILER_VAR_1182 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1182->name = "";
____BAH_COMPILER_VAR_1182->type = "";
____BAH_COMPILER_VAR_1182->constVal = "";
____BAH_COMPILER_VAR_1182->from = "";
____BAH_COMPILER_VAR_1182->name = t.cont;
____BAH_COMPILER_VAR_1182->type = t.bahType;
t.bahRef = ____BAH_COMPILER_VAR_1182;

    unsigned int ____BAH_COMPILER_VAR_1183 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1183);
    l->data[____BAH_COMPILER_VAR_1183] = t;
return tokPos;
};
long int valueArr(__BAH_ARR_TYPE_Tok l,long int i,lineType ltp,struct Elems* elems){
long int tokPos = i-1;
struct Tok pt = l->data[tokPos];
delete(l,tokPos);
if ((pt.isValue==false)) {
throwErr(&pt,"Cannot use {TOKEN} as value (array).");
}
char * ____BAH_COMPILER_VAR_1184 =getTypeFromToken(&pt,true,elems);struct string ptt = string(____BAH_COMPILER_VAR_1184);
struct Tok t = pt;
t.isValue = true;
char** ____BAH_COMPILER_VAR_1185 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1185[1] = "[";____BAH_COMPILER_VAR_1185[0] = t.ogCont;char * ____BAH_COMPILER_VAR_1186 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1185, 2);t.ogCont = ____BAH_COMPILER_VAR_1186;
long int nbEncls = 1;
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
i = tokPos+1;
for (; (i<len(l)); ++i) {
struct Tok tmpT = l->data[i];
if ((strcmp(tmpT.cont, "(") == 0)||(strcmp(tmpT.cont, "{") == 0)||(strcmp(tmpT.cont, "[") == 0)) {
++nbEncls;
}
else if ((strcmp(tmpT.cont, ")") == 0)||(strcmp(tmpT.cont, "}") == 0)||(strcmp(tmpT.cont, "]") == 0)) {
--nbEncls;
char** ____BAH_COMPILER_VAR_1187 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1187[1] = "]";____BAH_COMPILER_VAR_1187[0] = t.ogCont;char * ____BAH_COMPILER_VAR_1188 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1187, 2);t.ogCont = ____BAH_COMPILER_VAR_1188;
if ((nbEncls==0)) {
break;
}
}
char** ____BAH_COMPILER_VAR_1189 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1189[1] = tmpT.ogCont;____BAH_COMPILER_VAR_1189[0] = t.ogCont;char * ____BAH_COMPILER_VAR_1190 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1189, 2);t.ogCont = ____BAH_COMPILER_VAR_1190;

    unsigned int ____BAH_COMPILER_VAR_1191 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1191);
    memory->data[____BAH_COMPILER_VAR_1191] = tmpT;
};
deleteRange(l,tokPos+1,i);
memory = prePross(memory,(lineType)-1,elems);
if ((len(memory)==0)) {
throwErr(&pt,"Cannot access empty index of array {TOKEN}.");
}
char split = false;
char * from = "";
char * to = "";
if ((len(memory)>1)) {
split = true;
struct Tok first = memory->data[0];
struct Tok second;
struct Tok third;
if ((len(memory)==3)) {
second = memory->data[1];
third = memory->data[2];
char * firstT = getTypeFromToken(&first,true,elems);
if ((compTypes(firstT,"int")==false)) {
throwErr(&first,"Cannot use {TOKEN} as int.");
}
char * thirdT = getTypeFromToken(&third,true,elems);
if ((compTypes(thirdT,"int")==false)) {
throwErr(&third,"Cannot use {TOKEN} as int.");
}
if ((strcmp(second.cont, ":") != 0)) {
throwErr(&second,"Expected ':' not {TOKEN}.");
}
from = first.cont;
to = third.cont;
}
else if ((len(memory)==2)) {
second = memory->data[1];
if ((strcmp(first.cont, ":") == 0)) {
from = "0";
char * secondT = getTypeFromToken(&second,true,elems);
if ((compTypes(secondT,"int")==false)) {
throwErr(&second,"Cannot use {TOKEN} as int.");
}
to = second.cont;
}
else if ((strcmp(second.cont, ":") == 0)) {
char * firstT = getTypeFromToken(&first,true,elems);
if ((compTypes(firstT,"int")==false)) {
throwErr(&first,"Cannot use {TOKEN} as int.");
}
from = first.cont;
}
else {
throwErr(&second,"Expected ':' not {TOKEN}");
}
}
else {
throwErr(&memory->data[3],"Cannot substiture with more than 2 values, expected ']' not {TOKEN}.");
}
}
if (string__hasPrefix(&ptt,"[]")) {
if ((split==false)) {
struct Tok index = memory->data[0];
char * ____BAH_COMPILER_VAR_1192 =getTypeFromToken(&index,true,elems);if ((compTypes(____BAH_COMPILER_VAR_1192,"int")==false)) {
throwErr(&index,"Cannot use {TOKEN} as array index (int).");
}
char** ____BAH_COMPILER_VAR_1193 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1193[3] = "]";____BAH_COMPILER_VAR_1193[2] = index.cont;____BAH_COMPILER_VAR_1193[1] = "->data[";____BAH_COMPILER_VAR_1193[0] = pt.cont;char * ____BAH_COMPILER_VAR_1194 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1193, 4);t.cont = ____BAH_COMPILER_VAR_1194;
string__trimLeft(&ptt,2);
t.bahType = string__str(&ptt);
}
else {
t.bahType = string__str(&ptt);
if ((strcmp(to, "") == 0)) {
char** ____BAH_COMPILER_VAR_1195 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1195[1] = "->length";____BAH_COMPILER_VAR_1195[0] = pt.cont;char * ____BAH_COMPILER_VAR_1196 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1195, 2);to = ____BAH_COMPILER_VAR_1196;
}
char** ____BAH_COMPILER_VAR_1197 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_1197[6] = ")";____BAH_COMPILER_VAR_1197[5] = to;____BAH_COMPILER_VAR_1197[4] = ", ";____BAH_COMPILER_VAR_1197[3] = from;____BAH_COMPILER_VAR_1197[2] = ", ";____BAH_COMPILER_VAR_1197[1] = pt.cont;____BAH_COMPILER_VAR_1197[0] = "arraySubstitute(";char * ____BAH_COMPILER_VAR_1198 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1197, 7);t.cont = ____BAH_COMPILER_VAR_1198;
}
}
else if (string__hasPrefix(&ptt,"buffer:")) {
if ((split==false)) {
t.bahType = "char";
struct Tok index = memory->data[0];
char** ____BAH_COMPILER_VAR_1199 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1199[3] = "]";____BAH_COMPILER_VAR_1199[2] = index.cont;____BAH_COMPILER_VAR_1199[1] = "[";____BAH_COMPILER_VAR_1199[0] = pt.cont;char * ____BAH_COMPILER_VAR_1200 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1199, 4);t.cont = ____BAH_COMPILER_VAR_1200;
}
else {
t.bahType = "cpstring";
if ((strcmp(to, "") == 0)) {
char** ____BAH_COMPILER_VAR_1201 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1201[2] = ")";____BAH_COMPILER_VAR_1201[1] = pt.cont;____BAH_COMPILER_VAR_1201[0] = "strlen(";char * ____BAH_COMPILER_VAR_1202 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1201, 3);to = ____BAH_COMPILER_VAR_1202;
}
char** ____BAH_COMPILER_VAR_1203 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_1203[6] = ")";____BAH_COMPILER_VAR_1203[5] = to;____BAH_COMPILER_VAR_1203[4] = ", ";____BAH_COMPILER_VAR_1203[3] = from;____BAH_COMPILER_VAR_1203[2] = ", ";____BAH_COMPILER_VAR_1203[1] = pt.cont;____BAH_COMPILER_VAR_1203[0] = "cpstringSubsitute(";char * ____BAH_COMPILER_VAR_1204 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1203, 7);t.cont = ____BAH_COMPILER_VAR_1204;
}
}
else if (string__hasPrefix(&ptt,"map:")) {
if ((split==true)) {
throwErr(&pt,"Cannot do substitution on a map {TOKEN}.");
}
string__trimLeft(&ptt,4);
char * ____BAH_COMPILER_VAR_1205 =string__str(&ptt);struct string elemType = getCType(____BAH_COMPILER_VAR_1205,elems);
struct Tok index = memory->data[0];
if ((tokPos==0)&&(ltp==LINE_TYPE_VAR)) {
struct variable* ____BAH_COMPILER_VAR_1206 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1206->name = "";
____BAH_COMPILER_VAR_1206->type = "";
____BAH_COMPILER_VAR_1206->constVal = "";
____BAH_COMPILER_VAR_1206->from = "";
____BAH_COMPILER_VAR_1206->name = genCompilerVar();
____BAH_COMPILER_VAR_1206->type = string__str(&ptt);
struct variable* tmpV = ____BAH_COMPILER_VAR_1206;

    unsigned int ____BAH_COMPILER_VAR_1207 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_1207);
    elems->vars->data[____BAH_COMPILER_VAR_1207] = tmpV;
if (isGlobal()) {
char** ____BAH_COMPILER_VAR_1208 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1208[3] = ";\n";____BAH_COMPILER_VAR_1208[2] = tmpV->name;____BAH_COMPILER_VAR_1208[1] = " ";____BAH_COMPILER_VAR_1208[0] = string__str(&elemType);char * ____BAH_COMPILER_VAR_1209 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1208, 4);INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_1209));
}
else {
char** ____BAH_COMPILER_VAR_1210 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1210[3] = ";\n";____BAH_COMPILER_VAR_1210[2] = tmpV->name;____BAH_COMPILER_VAR_1210[1] = " ";____BAH_COMPILER_VAR_1210[0] = string__str(&elemType);char * ____BAH_COMPILER_VAR_1211 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1210, 4);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1211));
}
char * ____BAH_COMPILER_VAR_1212 =string__str(&ptt);if (isRCPpointerType(____BAH_COMPILER_VAR_1212)) {
char** ____BAH_COMPILER_VAR_1213 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_1213[6] = ");\n";____BAH_COMPILER_VAR_1213[5] = tmpV->name;____BAH_COMPILER_VAR_1213[4] = ", ";____BAH_COMPILER_VAR_1213[3] = index.cont;____BAH_COMPILER_VAR_1213[2] = ", ";____BAH_COMPILER_VAR_1213[1] = pt.cont;____BAH_COMPILER_VAR_1213[0] = "mapWrapper__set(";char * ____BAH_COMPILER_VAR_1214 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1213, 7);NEXT_LINE = ____BAH_COMPILER_VAR_1214;
}
else {
char** ____BAH_COMPILER_VAR_1215 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_1215[8] = "));\n";____BAH_COMPILER_VAR_1215[7] = string__str(&elemType);____BAH_COMPILER_VAR_1215[6] = ", sizeof(";____BAH_COMPILER_VAR_1215[5] = tmpV->name;____BAH_COMPILER_VAR_1215[4] = ", &";____BAH_COMPILER_VAR_1215[3] = index.cont;____BAH_COMPILER_VAR_1215[2] = ", ";____BAH_COMPILER_VAR_1215[1] = pt.cont;____BAH_COMPILER_VAR_1215[0] = "mapWrapper__setAny(";char * ____BAH_COMPILER_VAR_1216 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1215, 9);NEXT_LINE = ____BAH_COMPILER_VAR_1216;
}
t.cont = tmpV->name;
t.bahType = string__str(&ptt);
}
else {
t.isFunc = true;
struct rope* res= null;
char * tmpV = genCompilerVar();
char * ____BAH_COMPILER_VAR_1217 =string__str(&ptt);if (isRCPpointerType(____BAH_COMPILER_VAR_1217)) {
char** ____BAH_COMPILER_VAR_1218 = alloca(8 * sizeof(char*));____BAH_COMPILER_VAR_1218[7] = ");\n";____BAH_COMPILER_VAR_1218[6] = index.cont;____BAH_COMPILER_VAR_1218[5] = ", ";____BAH_COMPILER_VAR_1218[4] = t.cont;____BAH_COMPILER_VAR_1218[3] = "=mapWrapper__get(";____BAH_COMPILER_VAR_1218[2] = tmpV;____BAH_COMPILER_VAR_1218[1] = " ";____BAH_COMPILER_VAR_1218[0] = string__str(&elemType);char * ____BAH_COMPILER_VAR_1219 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1218, 8);res = rope(____BAH_COMPILER_VAR_1219);
t.cont = tmpV;
}
else {
char** ____BAH_COMPILER_VAR_1220 = alloca(8 * sizeof(char*));____BAH_COMPILER_VAR_1220[7] = ");\n";____BAH_COMPILER_VAR_1220[6] = index.cont;____BAH_COMPILER_VAR_1220[5] = ", ";____BAH_COMPILER_VAR_1220[4] = pt.cont;____BAH_COMPILER_VAR_1220[3] = "=mapWrapper__get(";____BAH_COMPILER_VAR_1220[2] = tmpV;____BAH_COMPILER_VAR_1220[1] = "* ";____BAH_COMPILER_VAR_1220[0] = string__str(&elemType);char * ____BAH_COMPILER_VAR_1221 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1220, 8);res = rope(____BAH_COMPILER_VAR_1221);
char** ____BAH_COMPILER_VAR_1222 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1222[4] = ")";____BAH_COMPILER_VAR_1222[3] = tmpV;____BAH_COMPILER_VAR_1222[2] = ")(*";____BAH_COMPILER_VAR_1222[1] = string__str(&elemType);____BAH_COMPILER_VAR_1222[0] = "(";char * ____BAH_COMPILER_VAR_1223 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1222, 5);t.cont = ____BAH_COMPILER_VAR_1223;
}
if (RCPavailable()) {
struct variable* ____BAH_COMPILER_VAR_1224 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1224->name = "";
____BAH_COMPILER_VAR_1224->type = "";
____BAH_COMPILER_VAR_1224->constVal = "";
____BAH_COMPILER_VAR_1224->from = "";
____BAH_COMPILER_VAR_1224->name = tmpV;
____BAH_COMPILER_VAR_1224->type = string__str(&ptt);

    unsigned int ____BAH_COMPILER_VAR_1225 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_1225);
    elems->vars->data[____BAH_COMPILER_VAR_1225] = ____BAH_COMPILER_VAR_1224;
}
if (isGlobal()) {
INIT = rope__add(INIT, res);
}
else {
OUTPUT = rope__add(OUTPUT, res);
}
t.bahType = string__str(&ptt);
}
}
else if ((strcmp(string__str(&ptt), "cpstring") == 0)) {
t.isFunc = true;
t.type = TOKEN_TYPE_FUNC;
if ((split==false)) {
t.bahType = "char";
struct Tok index = memory->data[0];
char** ____BAH_COMPILER_VAR_1226 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1226[3] = "]";____BAH_COMPILER_VAR_1226[2] = index.cont;____BAH_COMPILER_VAR_1226[1] = "[";____BAH_COMPILER_VAR_1226[0] = pt.cont;char * ____BAH_COMPILER_VAR_1227 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1226, 4);t.cont = ____BAH_COMPILER_VAR_1227;
}
else {
if ((strcmp(to, "") == 0)) {
char** ____BAH_COMPILER_VAR_1228 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1228[2] = ")";____BAH_COMPILER_VAR_1228[1] = pt.cont;____BAH_COMPILER_VAR_1228[0] = "strlen(";char * ____BAH_COMPILER_VAR_1229 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1228, 3);to = ____BAH_COMPILER_VAR_1229;
}
char** ____BAH_COMPILER_VAR_1230 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_1230[6] = ")";____BAH_COMPILER_VAR_1230[5] = to;____BAH_COMPILER_VAR_1230[4] = ", ";____BAH_COMPILER_VAR_1230[3] = from;____BAH_COMPILER_VAR_1230[2] = ", ";____BAH_COMPILER_VAR_1230[1] = pt.cont;____BAH_COMPILER_VAR_1230[0] = "cpstringSubsitute(";char * ____BAH_COMPILER_VAR_1231 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1230, 7);t.cont = ____BAH_COMPILER_VAR_1231;
}
}
else {
char** ____BAH_COMPILER_VAR_1232 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1232[2] = ") as array.";____BAH_COMPILER_VAR_1232[1] = string__str(&ptt);____BAH_COMPILER_VAR_1232[0] = "Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_1233 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1232, 3);throwErr(&pt,____BAH_COMPILER_VAR_1233);
}
t.isValue = true;

    unsigned int ____BAH_COMPILER_VAR_1234 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1234);
    l->data[____BAH_COMPILER_VAR_1234] = t;
return tokPos;
};
long int valueBool(__BAH_ARR_TYPE_Tok l,long int i,lineType ltp,struct Elems* elems){
long int tokPos = i-2;
struct Tok pt = l->data[tokPos];
char * ptt = getTypeFromToken(&pt,true,elems);
struct Tok t = l->data[tokPos+1];
deleteRange(l,tokPos,tokPos+1);
if ((ltp==LINE_TYPE_FOR)&&(strcmp(ptt, "int") == 0)||(strcmp(ptt, "float") == 0)) {
struct variable* v = getRealVar(pt.cont,elems);
if ((v!=null)&&(v->canBeReg==true)&&(v->isReg==false)&&(v->declRope!=null)) {
char * odecl = rope__toStr(v->declRope);
if ((strHasPrefix(odecl,"register ")==false)) {
char** ____BAH_COMPILER_VAR_1235 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1235[1] = odecl;____BAH_COMPILER_VAR_1235[0] = "register ";char * ____BAH_COMPILER_VAR_1236 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1235, 2);OUTPUT->totalLen = OUTPUT->totalLen+ropeSet(v->declRope,____BAH_COMPILER_VAR_1236);
}
v->isReg = true;
}
}
if ((isUnsafe==false)) {
if ((tokPos>0)) {
if ((strcmp(l->data[tokPos-1].cont, "&&") != 0)) {
clear(currChecks);
}
}
else {
clear(currChecks);
}
}
struct Tok nt = l->data[tokPos];
char * ntt = getTypeFromToken(&nt,true,elems);
if ((strcmp(t.cont, "in") == 0)) {
struct string arrT = string(ntt);
if ((string__hasPrefix(&arrT,"[]")==0)) {
char** ____BAH_COMPILER_VAR_1237 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1237[2] = ") as array.";____BAH_COMPILER_VAR_1237[1] = ntt;____BAH_COMPILER_VAR_1237[0] = "Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_1238 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1237, 3);throwErr(&nt,____BAH_COMPILER_VAR_1238);
}
string__trimLeft(&arrT,2);
char * ____BAH_COMPILER_VAR_1239 =string__str(&arrT);if ((compTypes(ptt,____BAH_COMPILER_VAR_1239)==false)) {
char** ____BAH_COMPILER_VAR_1240 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1240[4] = ".";____BAH_COMPILER_VAR_1240[3] = ntt;____BAH_COMPILER_VAR_1240[2] = ") in ";____BAH_COMPILER_VAR_1240[1] = ptt;____BAH_COMPILER_VAR_1240[0] = "Cannot search for {TOKEN} (";char * ____BAH_COMPILER_VAR_1241 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1240, 5);throwErr(&pt,____BAH_COMPILER_VAR_1241);
}
char * compVar = genCompilerVar();
char * comp = "";
if ((strcmp(ptt, "cpstring") == 0)) {
char** ____BAH_COMPILER_VAR_1242 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_1242[5] = ") == 0";____BAH_COMPILER_VAR_1242[4] = pt.cont;____BAH_COMPILER_VAR_1242[3] = "->data[i], ";____BAH_COMPILER_VAR_1242[2] = nt.cont;____BAH_COMPILER_VAR_1242[1] = "->data[i] != 0 && strcmp(";____BAH_COMPILER_VAR_1242[0] = nt.cont;char * ____BAH_COMPILER_VAR_1243 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1242, 6);comp = ____BAH_COMPILER_VAR_1243;
}
else {
char** ____BAH_COMPILER_VAR_1244 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1244[2] = pt.cont;____BAH_COMPILER_VAR_1244[1] = "->data[i] == ";____BAH_COMPILER_VAR_1244[0] = nt.cont;char * ____BAH_COMPILER_VAR_1245 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1244, 3);comp = ____BAH_COMPILER_VAR_1245;
}
char** ____BAH_COMPILER_VAR_1246 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_1246[8] = "=1;\n                break;\n            };\n        }\n        ";____BAH_COMPILER_VAR_1246[7] = compVar;____BAH_COMPILER_VAR_1246[6] = ") {\n                ";____BAH_COMPILER_VAR_1246[5] = comp;____BAH_COMPILER_VAR_1246[4] = "->length-1; i!=-1;i--) {\n            if (";____BAH_COMPILER_VAR_1246[3] = nt.cont;____BAH_COMPILER_VAR_1246[2] = " = 0;\n        for(int i=";____BAH_COMPILER_VAR_1246[1] = compVar;____BAH_COMPILER_VAR_1246[0] = "\n        char ";char * ____BAH_COMPILER_VAR_1247 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1246, 9);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1247));
pt.cont = compVar;
}
else {
if ((compTypes(ptt,ntt)==false)) {
char** ____BAH_COMPILER_VAR_1248 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1248[4] = ".";____BAH_COMPILER_VAR_1248[3] = ptt;____BAH_COMPILER_VAR_1248[2] = ") with type ";____BAH_COMPILER_VAR_1248[1] = ntt;____BAH_COMPILER_VAR_1248[0] = "Cannot compare {TOKEN} (";char * ____BAH_COMPILER_VAR_1249 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1248, 5);throwErr(&nt,____BAH_COMPILER_VAR_1249);
}
if ((strcmp(ptt, "cpstring") == 0)) {
if ((strcmp(t.cont, "==") == 0)) {
char** ____BAH_COMPILER_VAR_1250 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1250[4] = ") == 0)";____BAH_COMPILER_VAR_1250[3] = nt.cont;____BAH_COMPILER_VAR_1250[2] = ", ";____BAH_COMPILER_VAR_1250[1] = pt.cont;____BAH_COMPILER_VAR_1250[0] = "(strcmp(";char * ____BAH_COMPILER_VAR_1251 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1250, 5);pt.cont = ____BAH_COMPILER_VAR_1251;
}
else if ((strcmp(t.cont, "!=") == 0)) {
char** ____BAH_COMPILER_VAR_1252 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1252[4] = ") != 0)";____BAH_COMPILER_VAR_1252[3] = nt.cont;____BAH_COMPILER_VAR_1252[2] = ", ";____BAH_COMPILER_VAR_1252[1] = pt.cont;____BAH_COMPILER_VAR_1252[0] = "(strcmp(";char * ____BAH_COMPILER_VAR_1253 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1252, 5);pt.cont = ____BAH_COMPILER_VAR_1253;
}
else if ((strcmp(t.cont, ">") == 0)) {
char** ____BAH_COMPILER_VAR_1254 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1254[4] = "))";____BAH_COMPILER_VAR_1254[3] = nt.cont;____BAH_COMPILER_VAR_1254[2] = ") > srtlen(";____BAH_COMPILER_VAR_1254[1] = pt.cont;____BAH_COMPILER_VAR_1254[0] = "(strlen(";char * ____BAH_COMPILER_VAR_1255 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1254, 5);pt.cont = ____BAH_COMPILER_VAR_1255;
}
else if ((strcmp(t.cont, "<") == 0)) {
char** ____BAH_COMPILER_VAR_1256 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1256[4] = "))";____BAH_COMPILER_VAR_1256[3] = nt.cont;____BAH_COMPILER_VAR_1256[2] = ") < srtlen(";____BAH_COMPILER_VAR_1256[1] = pt.cont;____BAH_COMPILER_VAR_1256[0] = "(strlen(";char * ____BAH_COMPILER_VAR_1257 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1256, 5);pt.cont = ____BAH_COMPILER_VAR_1257;
}
else if ((strcmp(t.cont, ">=") == 0)) {
char** ____BAH_COMPILER_VAR_1258 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1258[4] = "))";____BAH_COMPILER_VAR_1258[3] = nt.cont;____BAH_COMPILER_VAR_1258[2] = ") >= srtlen(";____BAH_COMPILER_VAR_1258[1] = pt.cont;____BAH_COMPILER_VAR_1258[0] = "(strlen(";char * ____BAH_COMPILER_VAR_1259 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1258, 5);pt.cont = ____BAH_COMPILER_VAR_1259;
}
else if ((strcmp(t.cont, "<=") == 0)) {
char** ____BAH_COMPILER_VAR_1260 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1260[4] = "))";____BAH_COMPILER_VAR_1260[3] = nt.cont;____BAH_COMPILER_VAR_1260[2] = ") <= srtlen(";____BAH_COMPILER_VAR_1260[1] = pt.cont;____BAH_COMPILER_VAR_1260[0] = "(strlen(";char * ____BAH_COMPILER_VAR_1261 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1260, 5);pt.cont = ____BAH_COMPILER_VAR_1261;
}
}
else {
if ((isUnsafe==false)&&(pt.type==TOKEN_TYPE_VAR)&&(pt.isOper==false)&&isRCPpointerType(ptt)) {
struct variable* ptV = searchVar(pt.cont,elems);
if ((ptV!=null)) {
char ntIsNull = false;
if ((strcmp(nt.cont, "null") == 0)) {
ntIsNull = true;
}
else if ((nt.type==TOKEN_TYPE_VAR)&&(nt.isOper==false)) {
struct variable* nv = searchVar(nt.cont,elems);
if ((nv!=null)) {
ntIsNull = nv->canBeNull;
}
}
else if ((nt.isFunc==true)) {
struct func* fn = searchFuncByToken(&nt,elems);
if ((fn!=null)&&(fn->returns!=null)) {
ntIsNull = (fn->returns->type[strlen(fn->returns->type)-1]==33);
}
}
if ((strcmp(t.cont, "==") == 0)) {
struct varCheck ____BAH_COMPILER_VAR_1262 = {};
____BAH_COMPILER_VAR_1262.v = ptV;
____BAH_COMPILER_VAR_1262.checkNull = ntIsNull;

    unsigned int ____BAH_COMPILER_VAR_1263 = len(currChecks);
    __Bah_realocate_arr(currChecks, ____BAH_COMPILER_VAR_1263);
    currChecks->data[____BAH_COMPILER_VAR_1263] = ____BAH_COMPILER_VAR_1262;
}
else if ((strcmp(t.cont, "!=") == 0)) {
struct varCheck ____BAH_COMPILER_VAR_1264 = {};
____BAH_COMPILER_VAR_1264.v = ptV;
____BAH_COMPILER_VAR_1264.checkNull = (ntIsNull==false);

    unsigned int ____BAH_COMPILER_VAR_1265 = len(currChecks);
    __Bah_realocate_arr(currChecks, ____BAH_COMPILER_VAR_1265);
    currChecks->data[____BAH_COMPILER_VAR_1265] = ____BAH_COMPILER_VAR_1264;
}
}
}
char** ____BAH_COMPILER_VAR_1266 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1266[4] = ")";____BAH_COMPILER_VAR_1266[3] = nt.cont;____BAH_COMPILER_VAR_1266[2] = t.cont;____BAH_COMPILER_VAR_1266[1] = pt.cont;____BAH_COMPILER_VAR_1266[0] = "(";char * ____BAH_COMPILER_VAR_1267 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1266, 5);pt.cont = ____BAH_COMPILER_VAR_1267;
}
}
pt.isOper = true;
pt.bahType = "bool";
pt.isValue = true;

    unsigned int ____BAH_COMPILER_VAR_1268 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1268);
    l->data[____BAH_COMPILER_VAR_1268] = pt;
return tokPos;
};
long int valueOper(__BAH_ARR_TYPE_Tok l,long int i,struct Elems* elems){
long int tokPos = i-2;
struct Tok pt = l->data[tokPos];
char * ptt = getTypeFromToken(&pt,true,elems);
struct Tok t = l->data[tokPos+1];
deleteRange(l,tokPos,tokPos+1);
struct Tok nt = l->data[tokPos];
if ((strcmp(nt.cont, t.cont) == 0)) {
pt.isOper = true;
char** ____BAH_COMPILER_VAR_1269 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1269[2] = pt.cont;____BAH_COMPILER_VAR_1269[1] = t.cont;____BAH_COMPILER_VAR_1269[0] = t.cont;char * ____BAH_COMPILER_VAR_1270 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1269, 3);pt.cont = ____BAH_COMPILER_VAR_1270;

    unsigned int ____BAH_COMPILER_VAR_1271 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1271);
    l->data[____BAH_COMPILER_VAR_1271] = pt;
return tokPos;
}
char * ntt = getTypeFromToken(&nt,true,elems);
if ((compTypes(ptt,ntt)==false)) {
char** ____BAH_COMPILER_VAR_1272 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1272[4] = ".";____BAH_COMPILER_VAR_1272[3] = ptt;____BAH_COMPILER_VAR_1272[2] = ") as ";____BAH_COMPILER_VAR_1272[1] = ntt;____BAH_COMPILER_VAR_1272[0] = "Cannot compare {TOKEN} (";char * ____BAH_COMPILER_VAR_1273 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1272, 5);throwErr(&nt,____BAH_COMPILER_VAR_1273);
}
if ((strcmp(ptt, "cpstring") == 0)) {
array(char *)* strs = memoryAlloc(sizeof(array(char *)));

strs->length = 2;
strs->elemSize = sizeof(char *);
strs->data = memoryAlloc(sizeof(char *) * 50);
                    strs->realLength = 50;
strs->data[0] = nt.cont;
strs->data[1] = pt.cont;
if ((strcmp(t.cont, "+") != 0)) {
throwErr(&t,"Can only do concatenation on cpstring, not {TOKEN}.");
}
if ((tokPos-1>=0)) {
struct Tok nat = l->data[tokPos-1];
if ((strcmp(nat.cont, "+") == 0)) {
long int rangeEnds = tokPos-1;
i = tokPos-2;
long int nb = 2;
for (; (i>=0); --i) {
tokPos = i;
struct Tok currStrTk = l->data[i];
char * tt = getTypeFromToken(&currStrTk,true,elems);
if ((compTypes(tt,"cpstring")==false)) {
char** ____BAH_COMPILER_VAR_1274 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1274[2] = ").";____BAH_COMPILER_VAR_1274[1] = tt;____BAH_COMPILER_VAR_1274[0] = "Cannot concatenate cpstring with {TOKEN} (";char * ____BAH_COMPILER_VAR_1275 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1274, 3);throwErr(&currStrTk,____BAH_COMPILER_VAR_1275);
}

    unsigned int ____BAH_COMPILER_VAR_1276 = len(strs);
    __Bah_realocate_arr(strs, ____BAH_COMPILER_VAR_1276);
    strs->data[____BAH_COMPILER_VAR_1276] = currStrTk.cont;
if ((i-1>=0)) {
--i;
t = l->data[i];
if ((strcmp(t.cont, "+") != 0)) {

        char ____BAH_COMPILER_VAR_1277 = 0;
        for(int i=signs->length-1; i!=-1;i--) {
            if (signs->data[i] != 0 && strcmp(signs->data[i], t.cont) == 0) {
                ____BAH_COMPILER_VAR_1277=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_1277) {
throwErr(&t,"Can only do concatenation on cpstring, not {TOKEN}.");
}
else {
++i;
break;
}
}
}
else {
i = 0;
break;
}
};
deleteRange(l,i,rangeEnds);
}
else if (inArrayStr(nat.cont,signs)) {
throwErr(&nat,"Can only do concatenation on cpstring, not {TOKEN}.");
}
}
pt.type = TOKEN_TYPE_VAR;
pt.isValue = true;
pt.cont = genConcat(strs,elems);
pt.isOper = false;
}
else {
struct cStruct* s = searchStruct(ptt,elems);
if ((s!=null)) {
char * sep = ".";
char * amp = "&";
if (isRCPpointerType(ptt)) {
sep = "->";
amp = "";
}
char * mName = "";
if ((strcmp(t.cont, "+") == 0)) {
mName = "add";
}
else if ((strcmp(t.cont, "-") == 0)) {
mName = "sub";
}
else if ((strcmp(t.cont, "*") == 0)) {
mName = "mult";
}
else if ((strcmp(t.cont, "/") == 0)) {
mName = "div";
}
else {
char** ____BAH_COMPILER_VAR_1278 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1278[2] = ").";____BAH_COMPILER_VAR_1278[1] = ptt;____BAH_COMPILER_VAR_1278[0] = "Undefined operation on struct {TOKEN} (";char * ____BAH_COMPILER_VAR_1279 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1278, 3);throwErr(&pt,____BAH_COMPILER_VAR_1279);
}
struct structMemb* methd = searchStructMemb(mName,s,elems);
if ((methd!=null)&&(methd->isFn==true)) {
if (RCPavailable()) {
char** ____BAH_COMPILER_VAR_1280 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_1280[8] = ")";____BAH_COMPILER_VAR_1280[7] = nt.cont;____BAH_COMPILER_VAR_1280[6] = ", ";____BAH_COMPILER_VAR_1280[5] = pt.cont;____BAH_COMPILER_VAR_1280[4] = amp;____BAH_COMPILER_VAR_1280[3] = "(";____BAH_COMPILER_VAR_1280[2] = mName;____BAH_COMPILER_VAR_1280[1] = "__";____BAH_COMPILER_VAR_1280[0] = s->name;char * ____BAH_COMPILER_VAR_1281 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1280, 9);pt.cont = registerRCPvar(ptt,____BAH_COMPILER_VAR_1281,elems);
pt.type = TOKEN_TYPE_VAR;
pt.isFunc = false;
pt.isOper = false;
}
else {
char** ____BAH_COMPILER_VAR_1282 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_1282[8] = ")";____BAH_COMPILER_VAR_1282[7] = nt.cont;____BAH_COMPILER_VAR_1282[6] = ", ";____BAH_COMPILER_VAR_1282[5] = pt.cont;____BAH_COMPILER_VAR_1282[4] = amp;____BAH_COMPILER_VAR_1282[3] = "(";____BAH_COMPILER_VAR_1282[2] = mName;____BAH_COMPILER_VAR_1282[1] = "__";____BAH_COMPILER_VAR_1282[0] = s->name;char * ____BAH_COMPILER_VAR_1283 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1282, 9);pt.cont = ____BAH_COMPILER_VAR_1283;
pt.isFunc = true;
}
}
}
else {
char** ____BAH_COMPILER_VAR_1284 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1284[1] = nt.cont;____BAH_COMPILER_VAR_1284[0] = t.cont;char * ____BAH_COMPILER_VAR_1285 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1284, 2);char** ____BAH_COMPILER_VAR_1286 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1286[1] = ____BAH_COMPILER_VAR_1285;____BAH_COMPILER_VAR_1286[0] = pt.cont;char * ____BAH_COMPILER_VAR_1287 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1286, 2);pt.cont = ____BAH_COMPILER_VAR_1287;
}
pt.isOper = true;
}

    unsigned int ____BAH_COMPILER_VAR_1288 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1288);
    l->data[____BAH_COMPILER_VAR_1288] = pt;
return tokPos;
};
long int valueSendChan(__BAH_ARR_TYPE_Tok l,long int i,struct Elems* elems){
long int posTok = i-2;
struct Tok nt = l->data[posTok];
struct Tok pt = l->data[posTok+2];
deleteRange(l,posTok,posTok+2);
char * ntt = getTypeFromToken(&nt,true,elems);
char * ____BAH_COMPILER_VAR_1289 =getTypeFromToken(&pt,true,elems);struct string ptt = string(____BAH_COMPILER_VAR_1289);
if ((string__hasPrefix(&ptt,"chan:")==0)) {
char** ____BAH_COMPILER_VAR_1290 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1290[2] = ") as chan.";____BAH_COMPILER_VAR_1290[1] = string__str(&ptt);____BAH_COMPILER_VAR_1290[0] = "Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_1291 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1290, 3);throwErr(&pt,____BAH_COMPILER_VAR_1291);
}
string__trimLeft(&ptt,5);
if (isGlobal()) {
throwErr(&pt,"Cannot send to channel {TOKEN} of a function.");
}
char * ____BAH_COMPILER_VAR_1292 =string__str(&ptt);if ((compTypes(ntt,____BAH_COMPILER_VAR_1292)==false)) {
char** ____BAH_COMPILER_VAR_1293 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1293[4] = ".";____BAH_COMPILER_VAR_1293[3] = string__str(&ptt);____BAH_COMPILER_VAR_1293[2] = ") through chan:";____BAH_COMPILER_VAR_1293[1] = ntt;____BAH_COMPILER_VAR_1293[0] = "Cannot send {TOKEN} (";char * ____BAH_COMPILER_VAR_1294 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1293, 5);throwErr(&nt,____BAH_COMPILER_VAR_1294);
}
char * ____BAH_COMPILER_VAR_1295 =string__str(&ptt);if (isRCPpointerType(____BAH_COMPILER_VAR_1295)) {
char** ____BAH_COMPILER_VAR_1296 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1296[4] = ");\n";____BAH_COMPILER_VAR_1296[3] = nt.cont;____BAH_COMPILER_VAR_1296[2] = ", ";____BAH_COMPILER_VAR_1296[1] = pt.cont;____BAH_COMPILER_VAR_1296[0] = "channel__send(";char * ____BAH_COMPILER_VAR_1297 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1296, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1297));
}
else {
struct string ct = getCType(ntt,elems);
char * tmpV = genCompilerVar();
char** ____BAH_COMPILER_VAR_1298 = alloca(13 * sizeof(char*));____BAH_COMPILER_VAR_1298[12] = "));\n        ";____BAH_COMPILER_VAR_1298[11] = tmpV;____BAH_COMPILER_VAR_1298[10] = ", sizeof(";____BAH_COMPILER_VAR_1298[9] = tmpV;____BAH_COMPILER_VAR_1298[8] = ", &";____BAH_COMPILER_VAR_1298[7] = pt.cont;____BAH_COMPILER_VAR_1298[6] = ";\n        channel__sendAny(";____BAH_COMPILER_VAR_1298[5] = nt.cont;____BAH_COMPILER_VAR_1298[4] = " = ";____BAH_COMPILER_VAR_1298[3] = tmpV;____BAH_COMPILER_VAR_1298[2] = " ";____BAH_COMPILER_VAR_1298[1] = string__str(&ct);____BAH_COMPILER_VAR_1298[0] = "\n        ";char * ____BAH_COMPILER_VAR_1299 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1298, 13);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1299));
}
return posTok;
};
long int valueChan(__BAH_ARR_TYPE_Tok l,long int i,struct Elems* elems){
long int posTok = i-1;
delete(l,posTok);
struct Tok nt = l->data[posTok];
char * ____BAH_COMPILER_VAR_1300 =getTypeFromToken(&nt,true,elems);struct string ntt = string(____BAH_COMPILER_VAR_1300);
if ((string__hasPrefix(&ntt,"chan:")==0)) {
char** ____BAH_COMPILER_VAR_1301 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1301[2] = ") as chan.";____BAH_COMPILER_VAR_1301[1] = string__str(&ntt);____BAH_COMPILER_VAR_1301[0] = "Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_1302 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1301, 3);throwErr(&nt,____BAH_COMPILER_VAR_1302);
}
string__trimLeft(&ntt,5);
if (isGlobal()) {
throwErr(&nt,"Cannot receive from chan {TOKEN} outside a function body.");
}
char * ____BAH_COMPILER_VAR_1303 =string__str(&ntt);struct string ct = getCType(____BAH_COMPILER_VAR_1303,elems);
char * ____BAH_COMPILER_VAR_1304 =string__str(&ntt);if (isRCPpointerType(____BAH_COMPILER_VAR_1304)) {
char** ____BAH_COMPILER_VAR_1305 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1305[2] = ")";____BAH_COMPILER_VAR_1305[1] = nt.cont;____BAH_COMPILER_VAR_1305[0] = "channel__receive(";char * ____BAH_COMPILER_VAR_1306 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1305, 3);char * ____BAH_COMPILER_VAR_1307 =string__str(&ntt);char * tmpV = registerRCPvar(____BAH_COMPILER_VAR_1307,____BAH_COMPILER_VAR_1306,elems);
nt.cont = tmpV;
}
else {
if (RCPavailable()) {
char** ____BAH_COMPILER_VAR_1308 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1308[1] = "*";____BAH_COMPILER_VAR_1308[0] = string__str(&ntt);char * ____BAH_COMPILER_VAR_1309 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1308, 2);char** ____BAH_COMPILER_VAR_1310 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1310[4] = ")";____BAH_COMPILER_VAR_1310[3] = nt.cont;____BAH_COMPILER_VAR_1310[2] = "*)channel__receive(";____BAH_COMPILER_VAR_1310[1] = string__str(&ct);____BAH_COMPILER_VAR_1310[0] = "(";char * ____BAH_COMPILER_VAR_1311 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1310, 5);char * tmpV = registerRCPvar(____BAH_COMPILER_VAR_1309,____BAH_COMPILER_VAR_1311,elems);
char** ____BAH_COMPILER_VAR_1312 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1312[1] = tmpV;____BAH_COMPILER_VAR_1312[0] = "*";char * ____BAH_COMPILER_VAR_1313 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1312, 2);nt.cont = ____BAH_COMPILER_VAR_1313;
}
else {
char** ____BAH_COMPILER_VAR_1314 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1314[4] = ")";____BAH_COMPILER_VAR_1314[3] = nt.cont;____BAH_COMPILER_VAR_1314[2] = "*)channel__receive(";____BAH_COMPILER_VAR_1314[1] = string__str(&ct);____BAH_COMPILER_VAR_1314[0] = "*(";char * ____BAH_COMPILER_VAR_1315 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1314, 5);nt.cont = ____BAH_COMPILER_VAR_1315;
}
}
nt.type = TOKEN_TYPE_FUNC;
nt.isFunc = true;
nt.isValue = true;
nt.bahType = string__str(&ntt);

    unsigned int ____BAH_COMPILER_VAR_1316 = posTok;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1316);
    l->data[____BAH_COMPILER_VAR_1316] = nt;
return posTok;
};
char isSmallValue(__BAH_ARR_TYPE_Tok l,long int i){
struct Tok t = l->data[i];
if ((t.type==TOKEN_TYPE_CAST)||(strcmp(t.cont, "(") == 0)) {
return false;
}
else if ((t.isValue==false)) {
throwErr(&t,"Cannot use {TOKEN} as value.");
}
if ((i+1<len(l))) {
struct Tok nt = l->data[i+1];
if ((strcmp(nt.cont, "[") == 0)||(strcmp(nt.cont, ".") == 0)||(strcmp(nt.cont, "(") == 0)) {
return false;
}
}
return true;
};
char isValue(__BAH_ARR_TYPE_Tok l,long int i){
struct Tok t = l->data[i];
if ((t.type==TOKEN_TYPE_CAST)||(strcmp(t.cont, "(") == 0)) {
return false;
}
else if ((t.isValue==false)) {
throwErr(&t,"Cannot use {TOKEN} as value.");
}
if ((i+1<len(l))) {
struct Tok nt = l->data[i+1];
if ((strcmp(nt.cont, "[") == 0)||(strcmp(nt.cont, ".") == 0)||(strcmp(nt.cont, "(") == 0)||inArrayStr(nt.cont,signs)) {
return false;
}
}
return true;
};
__BAH_ARR_TYPE_Tok prePross(__BAH_ARR_TYPE_Tok line,lineType ltp,struct Elems* elems){
array(struct Tok)* fl = memoryAlloc(sizeof(array(struct Tok)));

fl->length = 0;
fl->elemSize = sizeof(struct Tok);
register long int i = 0;
register long int sepI = 0;
long int nbPar = 0;
if ((ltp!=(lineType)-1)) {
for (; (i<len(line)); ++i) {
struct Tok t = line->data[i];
if ((strcmp(t.cont, "(") == 0)) {
char isFunc = true;
nbPar = nbPar+1;
}
else if ((strcmp(t.cont, ")") == 0)) {
nbPar = nbPar-1;
}
else if ((nbPar==0)&&(strcmp(t.cont, "{") == 0)) {
if ((line->data[i+1].line!=t.line)) {
break;
}
}
};
fl = arraySubstitute(line, 0, i);
sepI = i;
}
else {
fl = line;
}
struct Tok ____BAH_COMPILER_VAR_1317 = {};
____BAH_COMPILER_VAR_1317.cont = "";
____BAH_COMPILER_VAR_1317.ogCont = "";
____BAH_COMPILER_VAR_1317.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1317.line = 1;
____BAH_COMPILER_VAR_1317.begLine = 1;
____BAH_COMPILER_VAR_1317.bahType = "";
#define pt ____BAH_COMPILER_VAR_1317
long int l = len(fl);
i = 0;
for (; (i<len(fl)); ++i) {
struct Tok t = fl->data[i];
if ((t.type==TOKEN_TYPE_VAR)&&(t.isOper==false)&&(t.cont[0]==38)) {
struct string tc = string(t.cont);
string__trimLeft(&tc,1);
char * ____BAH_COMPILER_VAR_1318 =string__str(&tc);struct variable* rv = getRealVar(____BAH_COMPILER_VAR_1318,elems);
if ((rv!=null)&&(rv->canBeReg==true)&&(rv->declRope!=null)) {
char * rvdr = rope__toStr(rv->declRope);
if (strHasPrefix(rvdr,"register ")) {
strTrimLeft(&rvdr,9);
OUTPUT->totalLen = OUTPUT->totalLen+ropeSet(rv->declRope,rvdr);
}
rv->canBeReg = false;
}
}
};
i = 0;
for (; (i<len(fl)); ++i) {
struct Tok t = fl->data[i];
if ((i>0)) {
pt = fl->data[i-1];
}
else {
struct Tok ____BAH_COMPILER_VAR_1319 = {};
____BAH_COMPILER_VAR_1319.cont = "";
____BAH_COMPILER_VAR_1319.ogCont = "";
____BAH_COMPILER_VAR_1319.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1319.line = 1;
____BAH_COMPILER_VAR_1319.begLine = 1;
____BAH_COMPILER_VAR_1319.bahType = "";
pt = ____BAH_COMPILER_VAR_1319;
}
if ((strcmp(t.cont, ".") == 0)&&(i>0)) {
i = valueStruct(fl,i,ltp,elems)-1;
}
else if ((strcmp(t.cont, "(") == 0)&&(strcmp(pt.cont, "function") != 0)) {
i = valueFunc(null,null,fl,i,ltp,elems)-1;
}
else if ((strcmp(t.cont, "[") == 0)&&(pt.isValue==true)) {
i = valueArr(fl,i,ltp,elems)-1;
}
else if ((pt.type==TOKEN_TYPE_CAST)&&isSmallValue(fl,i)) {
delete(fl,i-1);
struct string ptc = string(pt.cont);
string__trimLeft(&ptc,1);
string__trimRight(&ptc,1);
t.bahType = string__str(&ptc);
char * ____BAH_COMPILER_VAR_1320 =string__str(&ptc);struct string cType = getCType(____BAH_COMPILER_VAR_1320,elems);
char** ____BAH_COMPILER_VAR_1321 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1321[3] = t.cont;____BAH_COMPILER_VAR_1321[2] = ")";____BAH_COMPILER_VAR_1321[1] = string__str(&cType);____BAH_COMPILER_VAR_1321[0] = "(";char * ____BAH_COMPILER_VAR_1322 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1321, 4);t.cont = ____BAH_COMPILER_VAR_1322;

    unsigned int ____BAH_COMPILER_VAR_1323 = i-1;
    __Bah_realocate_arr(fl, ____BAH_COMPILER_VAR_1323);
    fl->data[____BAH_COMPILER_VAR_1323] = t;
i = i-2;
}
else if (inArrayStr(pt.cont,signs)) {
if ((strcmp(t.cont, pt.cont) == 0)&&(i>1)) {
struct Tok ppt = fl->data[i-2];
if ((ppt.type==TOKEN_TYPE_VAR)) {
long int posTok = i-2;
deleteRange(fl,i-1,i);
char** ____BAH_COMPILER_VAR_1324 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1324[2] = ppt.cont;____BAH_COMPILER_VAR_1324[1] = t.cont;____BAH_COMPILER_VAR_1324[0] = t.cont;char * ____BAH_COMPILER_VAR_1325 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1324, 3);ppt.cont = ____BAH_COMPILER_VAR_1325;
ppt.isValue = true;
ppt.isOper = true;

    unsigned int ____BAH_COMPILER_VAR_1326 = posTok;
    __Bah_realocate_arr(fl, ____BAH_COMPILER_VAR_1326);
    fl->data[____BAH_COMPILER_VAR_1326] = ppt;
i = posTok-1;
}
else {
throwErr(&ppt,"Cannot increment/decrement non variable value {TOKEN}.");
}
}
else if (isValue(fl,i)) {
i = valueOper(fl,i,elems)-1;
}
}
else if ((t.cont[0]==45)&&(pt.isValue==true)) {
if ((t.type==TOKEN_TYPE_INT)||(t.type==TOKEN_TYPE_FLOAT)) {
delete(fl,i);
char * ptt = getTypeFromToken(&pt,true,elems);
pt.bahType = ptt;
pt.isOper = true;
char** ____BAH_COMPILER_VAR_1327 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1327[1] = t.cont;____BAH_COMPILER_VAR_1327[0] = pt.cont;char * ____BAH_COMPILER_VAR_1328 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1327, 2);pt.cont = ____BAH_COMPILER_VAR_1328;

    unsigned int ____BAH_COMPILER_VAR_1329 = i-1;
    __Bah_realocate_arr(fl, ____BAH_COMPILER_VAR_1329);
    fl->data[____BAH_COMPILER_VAR_1329] = pt;
--i;
}
}
else if (inArrayStr(pt.cont,comparators)&&isValue(fl,i)) {
i = valueBool(fl,i,ltp,elems)-1;
}
else if ((strcmp(pt.cont, "<-") == 0)&&isValue(fl,i)) {
i = valueChan(fl,i,elems)-1;
}
else if ((strcmp(pt.cont, "->") == 0)&&isValue(fl,i)) {
if ((i-2>=0)) {
if (isValue(fl,i-2)) {
i = valueSendChan(fl,i,elems)-1;
}
}
else {
throwErr(&t,"Cannot {TOKEN} nothing through chan.");
}
}
};
i = 0;
for (; (i<len(fl)); ++i) {
struct Tok t = fl->data[i];
if ((strcmp(t.cont, "||") == 0)||(strcmp(t.cont, "&&") == 0)) {
if ((i==0)||(i+1==len(fl))) {
throwErr(&t,"Cannot use {TOKEN} on nothing.");
}
pt = fl->data[i-1];
struct Tok nt = fl->data[i+1];
char * ptt = getTypeFromToken(&pt,true,elems);
char * ntt = getTypeFromToken(&nt,true,elems);
if ((compTypes(ptt,ntt)==false)||(compTypes(ptt,"bool")==false)) {
char** ____BAH_COMPILER_VAR_1330 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1330[2] = ".";____BAH_COMPILER_VAR_1330[1] = ptt;____BAH_COMPILER_VAR_1330[0] = "Cannot use {TOKEN} on ";char * ____BAH_COMPILER_VAR_1331 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1330, 3);throwErr(&t,____BAH_COMPILER_VAR_1331);
}
char** ____BAH_COMPILER_VAR_1332 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1332[1] = nt.cont;____BAH_COMPILER_VAR_1332[0] = t.cont;char * ____BAH_COMPILER_VAR_1333 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1332, 2);char** ____BAH_COMPILER_VAR_1334 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1334[1] = ____BAH_COMPILER_VAR_1333;____BAH_COMPILER_VAR_1334[0] = pt.cont;char * ____BAH_COMPILER_VAR_1335 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1334, 2);pt.cont = ____BAH_COMPILER_VAR_1335;

    unsigned int ____BAH_COMPILER_VAR_1336 = i-1;
    __Bah_realocate_arr(fl, ____BAH_COMPILER_VAR_1336);
    fl->data[____BAH_COMPILER_VAR_1336] = pt;
deleteRange(fl,i,i+1);
i = i-2;
}
else if ((t.type==TOKEN_TYPE_VAR)&&(strcmp(t.bahType, "") != 0)) {
if ((t.cont[0]==38)) {
char** ____BAH_COMPILER_VAR_1337 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1337[1] = "*";____BAH_COMPILER_VAR_1337[0] = t.bahType;char * ____BAH_COMPILER_VAR_1338 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1337, 2);t.bahType = ____BAH_COMPILER_VAR_1338;

    unsigned int ____BAH_COMPILER_VAR_1339 = i;
    __Bah_realocate_arr(fl, ____BAH_COMPILER_VAR_1339);
    fl->data[____BAH_COMPILER_VAR_1339] = t;
}
else if ((t.cont[0]==42)) {
struct string tt = string(t.bahType);
string__replace(&tt,"*","");
t.bahType = string__str(&tt);

    unsigned int ____BAH_COMPILER_VAR_1340 = i;
    __Bah_realocate_arr(fl, ____BAH_COMPILER_VAR_1340);
    fl->data[____BAH_COMPILER_VAR_1340] = t;
}
}
};
fl = parseArrayType(fl,elems,true);
if ((RCPavailable()==true)) {
addRCPvars(fl,ltp,elems);
}
if ((ltp!=(lineType)-1)) {
while ((sepI<len(line))) {

    unsigned int ____BAH_COMPILER_VAR_1341 = len(fl);
    __Bah_realocate_arr(fl, ____BAH_COMPILER_VAR_1341);
    fl->data[____BAH_COMPILER_VAR_1341] = line->data[sepI];
++sepI;
};
}
return fl;

#undef pt
};
void parseFnDeclare(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
long int i = 0;
struct func* ____BAH_COMPILER_VAR_1342 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_1342->name = "";
____BAH_COMPILER_VAR_1342->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_1342->args->length = 0;
            ____BAH_COMPILER_VAR_1342->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_1342->from = "";
____BAH_COMPILER_VAR_1342->file = "";
____BAH_COMPILER_VAR_1342->line = 1;
struct func* fn = ____BAH_COMPILER_VAR_1342;
if ((RCPavailable()==false)&&(RCPenabled==true)) {
fn->used = true;
}
struct Tok ft = l->data[0];
char * code = parseFnHeader("",l,&i,fn,elems);
fn->line = ft.line;
fn->file = compilerState.currentFile;
struct func* ogFn = searchFunc(fn->name,elems,false);
if ((ogFn!=null)) {
if ((ogFn->isBinding==false)) {
char * lineStr = intToStr(ogFn->line);
char** ____BAH_COMPILER_VAR_1343 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1343[4] = ".";____BAH_COMPILER_VAR_1343[3] = lineStr;____BAH_COMPILER_VAR_1343[2] = ":";____BAH_COMPILER_VAR_1343[1] = ogFn->file;____BAH_COMPILER_VAR_1343[0] = "Cannot redeclare function {TOKEN}, previous declaration: ";char * ____BAH_COMPILER_VAR_1344 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1343, 5);throwErr(&ft,____BAH_COMPILER_VAR_1344);
}
}
if ((strcmp(fn->name, "main") == 0)) {
compilerState.haveEntryPoint = true;
if ((compTypes(fn->returns->type,"int")==false)) {
throwErr(&ft,"{TOKEN} function should return 'int'.");
}
if ((len(fn->args)!=1)) {
throwErr(&ft,"{TOKEN} function should take one []cpstring argument. Should be: \n            'main(args []cpstring) int'");
}
struct variable* fa = fn->args->data[0];
if ((compTypes(fa->type,"[]cpstring")==false)) {
throwErr(&ft,"{TOKEN} function should take []cpstring as argument. Should be: \n            'main(args []cpstring) int'");
}
}
if ((debug==true)) {
struct debugFunction* ____BAH_COMPILER_VAR_1345 = memoryAlloc(sizeof(struct debugFunction));
____BAH_COMPILER_VAR_1345->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_1345->args->length = 0;
            ____BAH_COMPILER_VAR_1345->args->elemSize = sizeof(struct variable*);
            struct debugFunction* df = ____BAH_COMPILER_VAR_1345;
df->name = fn->name;
df->args = fn->args;
df->returns = fn->returns->type;
struct debugFunction* ____BAH_COMPILER_VAR_1346 = df;
char ** ____BAH_COMPILER_VAR_1348 = (char **)((char*)(____BAH_COMPILER_VAR_1346) + offsetof(struct debugFunction, name));
struct reflectElement ____BAH_COMPILER_VAR_1349 = __reflect(____BAH_COMPILER_VAR_1348, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct debugFunction, name));
char ** ____BAH_COMPILER_VAR_1350 = (char **)((char*)(____BAH_COMPILER_VAR_1346) + offsetof(struct debugFunction, returns));
struct reflectElement ____BAH_COMPILER_VAR_1351 = __reflect(____BAH_COMPILER_VAR_1350, sizeof(char *), "cpstring", "returns", 0, 0, 0, 0, offsetof(struct debugFunction, returns));
array(struct variable*)** ____BAH_COMPILER_VAR_1352 = (array(struct variable*)**)((char*)(____BAH_COMPILER_VAR_1346) + offsetof(struct debugFunction, args));
struct variable** ____BAH_COMPILER_VAR_1353 = 0;
char ** ____BAH_COMPILER_VAR_1355 = (char **)((char*)(____BAH_COMPILER_VAR_1353) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_1356 = __reflect(____BAH_COMPILER_VAR_1355, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_1357 = (char **)((char*)(____BAH_COMPILER_VAR_1353) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_1358 = __reflect(____BAH_COMPILER_VAR_1357, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_1359 = (char*)((char*)(____BAH_COMPILER_VAR_1353) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_1360 = __reflect(____BAH_COMPILER_VAR_1359, sizeof(char), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_1361 = (char **)((char*)(____BAH_COMPILER_VAR_1353) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_1362 = __reflect(____BAH_COMPILER_VAR_1361, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_1363 = (char*)((char*)(____BAH_COMPILER_VAR_1353) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_1364 = __reflect(____BAH_COMPILER_VAR_1363, sizeof(char), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_1365 = (char **)((char*)(____BAH_COMPILER_VAR_1353) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_1366 = __reflect(____BAH_COMPILER_VAR_1365, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
void ** ____BAH_COMPILER_VAR_1367 = (void **)((char*)(____BAH_COMPILER_VAR_1353) + offsetof(struct variable, declScope));
struct reflectElement ____BAH_COMPILER_VAR_1368 = __reflect(____BAH_COMPILER_VAR_1367, sizeof(void *), "ptr", "declScope", 0, 0, 0, 0, offsetof(struct variable, declScope));
char* ____BAH_COMPILER_VAR_1369 = (char*)((char*)(____BAH_COMPILER_VAR_1353) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_1370 = __reflect(____BAH_COMPILER_VAR_1369, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));
struct rope** ____BAH_COMPILER_VAR_1371 = (struct rope**)((char*)(____BAH_COMPILER_VAR_1353) + offsetof(struct variable, declRope));
void ** ____BAH_COMPILER_VAR_1373 = (void **)((char*)(____BAH_COMPILER_VAR_1371) + offsetof(struct rope, left));
struct reflectElement ____BAH_COMPILER_VAR_1374 = __reflect(____BAH_COMPILER_VAR_1373, sizeof(void *), "ptr", "left", 0, 0, 0, 0, offsetof(struct rope, left));
void ** ____BAH_COMPILER_VAR_1375 = (void **)((char*)(____BAH_COMPILER_VAR_1371) + offsetof(struct rope, right));
struct reflectElement ____BAH_COMPILER_VAR_1376 = __reflect(____BAH_COMPILER_VAR_1375, sizeof(void *), "ptr", "right", 0, 0, 0, 0, offsetof(struct rope, right));
char ** ____BAH_COMPILER_VAR_1377 = (char **)((char*)(____BAH_COMPILER_VAR_1371) + offsetof(struct rope, str));
struct reflectElement ____BAH_COMPILER_VAR_1378 = __reflect(____BAH_COMPILER_VAR_1377, sizeof(char *), "cpstring", "str", 0, 0, 0, 0, offsetof(struct rope, str));
int* ____BAH_COMPILER_VAR_1379 = (int*)((char*)(____BAH_COMPILER_VAR_1371) + offsetof(struct rope, lCount));
struct reflectElement ____BAH_COMPILER_VAR_1380 = __reflect(____BAH_COMPILER_VAR_1379, sizeof(int), "int32", "lCount", 0, 0, 0, 0, offsetof(struct rope, lCount));
int* ____BAH_COMPILER_VAR_1381 = (int*)((char*)(____BAH_COMPILER_VAR_1371) + offsetof(struct rope, len));
struct reflectElement ____BAH_COMPILER_VAR_1382 = __reflect(____BAH_COMPILER_VAR_1381, sizeof(int), "int32", "len", 0, 0, 0, 0, offsetof(struct rope, len));
int* ____BAH_COMPILER_VAR_1383 = (int*)((char*)(____BAH_COMPILER_VAR_1371) + offsetof(struct rope, totalLen));
struct reflectElement ____BAH_COMPILER_VAR_1384 = __reflect(____BAH_COMPILER_VAR_1383, sizeof(int), "int32", "totalLen", 0, 0, 0, 0, offsetof(struct rope, totalLen));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_1372 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_1372->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_1372->length = 6;
        ____BAH_COMPILER_VAR_1372->data = memoryAlloc(____BAH_COMPILER_VAR_1372->length * ____BAH_COMPILER_VAR_1372->elemSize);
        ____BAH_COMPILER_VAR_1372->data[0] = ____BAH_COMPILER_VAR_1374;
____BAH_COMPILER_VAR_1372->data[1] = ____BAH_COMPILER_VAR_1376;
____BAH_COMPILER_VAR_1372->data[2] = ____BAH_COMPILER_VAR_1378;
____BAH_COMPILER_VAR_1372->data[3] = ____BAH_COMPILER_VAR_1380;
____BAH_COMPILER_VAR_1372->data[4] = ____BAH_COMPILER_VAR_1382;
____BAH_COMPILER_VAR_1372->data[5] = ____BAH_COMPILER_VAR_1384;
struct reflectElement ____BAH_COMPILER_VAR_1385 = __reflect(____BAH_COMPILER_VAR_1371, sizeof(struct rope), "rope*", "declRope", 0, 0, 1, ____BAH_COMPILER_VAR_1372, offsetof(struct variable, declRope));
char* ____BAH_COMPILER_VAR_1386 = (char*)((char*)(____BAH_COMPILER_VAR_1353) + offsetof(struct variable, canBeNull));
struct reflectElement ____BAH_COMPILER_VAR_1387 = __reflect(____BAH_COMPILER_VAR_1386, sizeof(char), "bool", "canBeNull", 0, 0, 0, 0, offsetof(struct variable, canBeNull));
char* ____BAH_COMPILER_VAR_1388 = (char*)((char*)(____BAH_COMPILER_VAR_1353) + offsetof(struct variable, canBeReg));
struct reflectElement ____BAH_COMPILER_VAR_1389 = __reflect(____BAH_COMPILER_VAR_1388, sizeof(char), "bool", "canBeReg", 0, 0, 0, 0, offsetof(struct variable, canBeReg));
char* ____BAH_COMPILER_VAR_1390 = (char*)((char*)(____BAH_COMPILER_VAR_1353) + offsetof(struct variable, isReg));
struct reflectElement ____BAH_COMPILER_VAR_1391 = __reflect(____BAH_COMPILER_VAR_1390, sizeof(char), "bool", "isReg", 0, 0, 0, 0, offsetof(struct variable, isReg));
void ** ____BAH_COMPILER_VAR_1392 = (void **)((char*)(____BAH_COMPILER_VAR_1353) + offsetof(struct variable, lastSet));
struct reflectElement ____BAH_COMPILER_VAR_1393 = __reflect(____BAH_COMPILER_VAR_1392, sizeof(void *), "ptr", "lastSet", 0, 0, 0, 0, offsetof(struct variable, lastSet));
char* ____BAH_COMPILER_VAR_1394 = (char*)((char*)(____BAH_COMPILER_VAR_1353) + offsetof(struct variable, isArg));
struct reflectElement ____BAH_COMPILER_VAR_1395 = __reflect(____BAH_COMPILER_VAR_1394, sizeof(char), "bool", "isArg", 0, 0, 0, 0, offsetof(struct variable, isArg));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_1354 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_1354->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_1354->length = 14;
        ____BAH_COMPILER_VAR_1354->data = memoryAlloc(____BAH_COMPILER_VAR_1354->length * ____BAH_COMPILER_VAR_1354->elemSize);
        ____BAH_COMPILER_VAR_1354->data[0] = ____BAH_COMPILER_VAR_1356;
____BAH_COMPILER_VAR_1354->data[1] = ____BAH_COMPILER_VAR_1358;
____BAH_COMPILER_VAR_1354->data[2] = ____BAH_COMPILER_VAR_1360;
____BAH_COMPILER_VAR_1354->data[3] = ____BAH_COMPILER_VAR_1362;
____BAH_COMPILER_VAR_1354->data[4] = ____BAH_COMPILER_VAR_1364;
____BAH_COMPILER_VAR_1354->data[5] = ____BAH_COMPILER_VAR_1366;
____BAH_COMPILER_VAR_1354->data[6] = ____BAH_COMPILER_VAR_1368;
____BAH_COMPILER_VAR_1354->data[7] = ____BAH_COMPILER_VAR_1370;
____BAH_COMPILER_VAR_1354->data[8] = ____BAH_COMPILER_VAR_1385;
____BAH_COMPILER_VAR_1354->data[9] = ____BAH_COMPILER_VAR_1387;
____BAH_COMPILER_VAR_1354->data[10] = ____BAH_COMPILER_VAR_1389;
____BAH_COMPILER_VAR_1354->data[11] = ____BAH_COMPILER_VAR_1391;
____BAH_COMPILER_VAR_1354->data[12] = ____BAH_COMPILER_VAR_1393;
____BAH_COMPILER_VAR_1354->data[13] = ____BAH_COMPILER_VAR_1395;
struct reflectElement ____BAH_COMPILER_VAR_1396 = __reflect(____BAH_COMPILER_VAR_1353, sizeof(struct variable), "variable*", "", 0, 0, 1, ____BAH_COMPILER_VAR_1354, 0);

        struct reflectElement ____BAH_COMPILER_VAR_1397 = ____BAH_COMPILER_VAR_1396;
        struct reflectElement ____BAH_COMPILER_VAR_1398 = __reflect(____BAH_COMPILER_VAR_1352, sizeof(array(struct variable*)*), "[]variable*", "args", 1, &____BAH_COMPILER_VAR_1397, 0, 0, offsetof(struct debugFunction, args));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_1347 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_1347->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_1347->length = 3;
        ____BAH_COMPILER_VAR_1347->data = memoryAlloc(____BAH_COMPILER_VAR_1347->length * ____BAH_COMPILER_VAR_1347->elemSize);
        ____BAH_COMPILER_VAR_1347->data[0] = ____BAH_COMPILER_VAR_1349;
____BAH_COMPILER_VAR_1347->data[1] = ____BAH_COMPILER_VAR_1351;
____BAH_COMPILER_VAR_1347->data[2] = ____BAH_COMPILER_VAR_1398;
struct reflectElement ____BAH_COMPILER_VAR_1399 = __reflect(____BAH_COMPILER_VAR_1346, sizeof(struct debugFunction), "debugFunction*", "df", 0, 0, 1, ____BAH_COMPILER_VAR_1347, 0);
debugPrint("fn_declare",ft.line,____BAH_COMPILER_VAR_1399);
}
if ((shouldOnlyDecl==true)) {
if ((ogFn!=null)) {
fn->isBinding = false;
}
fn->isImported = true;

    unsigned int ____BAH_COMPILER_VAR_1400 = len(elems->fns);
    __Bah_realocate_arr(elems->fns, ____BAH_COMPILER_VAR_1400);
    elems->fns->data[____BAH_COMPILER_VAR_1400] = fn;
char** ____BAH_COMPILER_VAR_1401 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1401[1] = ";\n";____BAH_COMPILER_VAR_1401[0] = code;char * ____BAH_COMPILER_VAR_1402 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1401, 2);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1402));
return;
}
char** ____BAH_COMPILER_VAR_1403 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1403[1] = "{\n";____BAH_COMPILER_VAR_1403[0] = code;char * ____BAH_COMPILER_VAR_1404 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1403, 2);code = ____BAH_COMPILER_VAR_1404;
fn->code = rope(code);
struct Elems* fnElems = dupElems(elems);
array(struct variable*)* vs = fnElems->vars;
register long int j = 0;
while ((j<len(fn->args))) {
struct variable* a = fn->args->data[j];
a->declScope = elems;
a->isArg = true;

    unsigned int ____BAH_COMPILER_VAR_1405 = len(vs);
    __Bah_realocate_arr(vs, ____BAH_COMPILER_VAR_1405);
    vs->data[____BAH_COMPILER_VAR_1405] = a;
j = j+1;
};
fnElems->vars = vs;
if ((ogFn!=null)) {
ogFn->isBinding = false;
ogFn->used = true;
ogFn = fn;
}
else {
array(struct func*)* fns = elems->fns;

    unsigned int ____BAH_COMPILER_VAR_1406 = len(fns);
    __Bah_realocate_arr(fns, ____BAH_COMPILER_VAR_1406);
    fns->data[____BAH_COMPILER_VAR_1406] = fn;
}
array(struct Tok)* tokens = memoryAlloc(sizeof(array(struct Tok)));

tokens->length = 0;
tokens->elemSize = sizeof(struct Tok);
++i;
long int max = len(l)-1;
while ((i<max)) {
struct Tok t = l->data[i];

    unsigned int ____BAH_COMPILER_VAR_1407 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_1407);
    tokens->data[____BAH_COMPILER_VAR_1407] = t;
++i;
};
if ((len(tokens)==0)) {
fn->code = rope__add(fn->code, rope("};\n"));
OUTPUT = rope__add(OUTPUT, fn->code);
return;
}
currentFn = fn;
struct rope* oOut = OUTPUT;
OUTPUT = rope("");
struct Tok t = tokens->data[0];
beginRCPscope(fnElems,fn->args);
struct Elems* ocurrFnElems = compilerState.currFnElems;
compilerState.currFnElems = fnElems;
parseLines(tokens,fnElems);
OPTI_checkFuncScopeRef(fnElems);
compilerState.currFnElems = ocurrFnElems;
currentFn = null;
if ((fn->returned==false)) {
if ((strlen(fn->returns->type)>0)) {
char** ____BAH_COMPILER_VAR_1408 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1408[2] = "' is not returned.";____BAH_COMPILER_VAR_1408[1] = fn->name;____BAH_COMPILER_VAR_1408[0] = "Function '";char * ____BAH_COMPILER_VAR_1409 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1408, 3);throwErr(&l->data[len(l)-1],____BAH_COMPILER_VAR_1409);
}
endRCPscope(fnElems,fn->args);
}
else {
removeDefs(fnElems);
}
fn->code = rope__add(fn->code, OUTPUT);
OUTPUT = oOut;
fn->code = rope__add(fn->code, rope("};\n"));
if ((debug==true)) {
struct Tok lt = l->data[len(l)-1];
debugEndScope(lt.line,fnElems);
}
OUTPUT = rope__add(OUTPUT, fn->code);
};
void parseCapture(__BAH_ARR_TYPE_Tok line,struct Elems* elems){
if ((len(line)<7)) {
throwErr(&line->data[0],"Invalid usage of {TOKEN} 'capture <var> = <maybe value> else {<code>}'");
}
struct Tok varTok = line->data[1];
struct Tok valTok = line->data[3];
char isThen = false;
if ((varTok.type!=TOKEN_TYPE_VAR)) {
throwErr(&varTok,"Cannot use {TOKEN} as variable.");
}
if ((strcmp(line->data[2].cont, "=") != 0)) {
throwErr(&line->data[2],"Expected '=' got {TOKEN}.");
}
char * valType = getTypeFromToken(&valTok,true,elems);
if ((valType[strlen(valType)-1]!=33)) {
char** ____BAH_COMPILER_VAR_1410 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1410[2] = ") as maybe value.";____BAH_COMPILER_VAR_1410[1] = valType;____BAH_COMPILER_VAR_1410[0] = "Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_1411 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1410, 3);throwErr(&valTok,____BAH_COMPILER_VAR_1411);
}
char** ____BAH_COMPILER_VAR_1412 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1412[1] = "*";____BAH_COMPILER_VAR_1412[0] = cpstringSubsitute(valType, 0, strlen(valType)-1);char * ____BAH_COMPILER_VAR_1413 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1412, 2);char * newType = ____BAH_COMPILER_VAR_1413;
if ((strcmp(line->data[4].cont, "else") != 0)&&(strcmp(line->data[4].cont, "then") != 0)) {
throwErr(&line->data[4],"Expected 'then' or 'else' got {TOKEN}.");
}
if ((strcmp(line->data[4].cont, "then") == 0)) {
isThen = true;
}
struct variable* v = searchVar(varTok.cont,elems);
char * code = "";
if ((v==null)) {
struct variable* ____BAH_COMPILER_VAR_1414 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1414->name = "";
____BAH_COMPILER_VAR_1414->type = "";
____BAH_COMPILER_VAR_1414->constVal = "";
____BAH_COMPILER_VAR_1414->from = "";
____BAH_COMPILER_VAR_1414->name = varTok.cont;
____BAH_COMPILER_VAR_1414->type = newType;
v = ____BAH_COMPILER_VAR_1414;

    unsigned int ____BAH_COMPILER_VAR_1415 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_1415);
    elems->vars->data[____BAH_COMPILER_VAR_1415] = v;

                struct string ____BAH_COMPILER_VAR_1416 = getCType(v->type,elems);
                char** ____BAH_COMPILER_VAR_1417 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1417[1] = " ";____BAH_COMPILER_VAR_1417[0] = string__str(&____BAH_COMPILER_VAR_1416);char * ____BAH_COMPILER_VAR_1418 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1417, 2);code = ____BAH_COMPILER_VAR_1418;
}
else {
if ((strcmp(v->type, newType) != 0)) {
char** ____BAH_COMPILER_VAR_1419 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1419[4] = ".";____BAH_COMPILER_VAR_1419[3] = newType;____BAH_COMPILER_VAR_1419[2] = ") as ";____BAH_COMPILER_VAR_1419[1] = v->type;____BAH_COMPILER_VAR_1419[0] = "Cannot use var {TOKEN} (";char * ____BAH_COMPILER_VAR_1420 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1419, 5);throwErr(&varTok,____BAH_COMPILER_VAR_1420);
}
}
char** ____BAH_COMPILER_VAR_1421 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1421[3] = ";";____BAH_COMPILER_VAR_1421[2] = valTok.cont;____BAH_COMPILER_VAR_1421[1] = " = ";____BAH_COMPILER_VAR_1421[0] = v->name;char * ____BAH_COMPILER_VAR_1422 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1421, 4);char** ____BAH_COMPILER_VAR_1423 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1423[1] = ____BAH_COMPILER_VAR_1422;____BAH_COMPILER_VAR_1423[0] = code;char * ____BAH_COMPILER_VAR_1424 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1423, 2);code = ____BAH_COMPILER_VAR_1424;
if ((isThen==true)) {
char** ____BAH_COMPILER_VAR_1425 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1425[2] = " != null) {";____BAH_COMPILER_VAR_1425[1] = v->name;____BAH_COMPILER_VAR_1425[0] = "if (";char * ____BAH_COMPILER_VAR_1426 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1425, 3);char** ____BAH_COMPILER_VAR_1427 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1427[1] = ____BAH_COMPILER_VAR_1426;____BAH_COMPILER_VAR_1427[0] = code;char * ____BAH_COMPILER_VAR_1428 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1427, 2);code = ____BAH_COMPILER_VAR_1428;
}
else {
char** ____BAH_COMPILER_VAR_1429 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1429[2] = " == null) {";____BAH_COMPILER_VAR_1429[1] = v->name;____BAH_COMPILER_VAR_1429[0] = "if (";char * ____BAH_COMPILER_VAR_1430 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1429, 3);char** ____BAH_COMPILER_VAR_1431 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1431[1] = ____BAH_COMPILER_VAR_1430;____BAH_COMPILER_VAR_1431[0] = code;char * ____BAH_COMPILER_VAR_1432 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1431, 2);code = ____BAH_COMPILER_VAR_1432;
}
OUTPUT = rope__add(OUTPUT, rope(code));
array(struct Tok)* tokens = arraySubstitute(line, 6, len(line)-1);
struct Elems* CaptElems = dupElems(elems);
parseLines(tokens,CaptElems);
if ((isThen==true)) {
OUTPUT = rope__add(OUTPUT, rope("}\n"));
}
else {
char** ____BAH_COMPILER_VAR_1433 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1433[4] = "\");}\n";____BAH_COMPILER_VAR_1433[3] = intToStr(line->data[0].line);____BAH_COMPILER_VAR_1433[2] = ":";____BAH_COMPILER_VAR_1433[1] = compilerState.currentFile;____BAH_COMPILER_VAR_1433[0] = "\n__BAH_panic(\"Undefined capture resolution.\", \"";char * ____BAH_COMPILER_VAR_1434 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1433, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1434));
}
};
void parseLine(__BAH_ARR_TYPE_Tok line,struct Elems* elems){
if ((len(line)==0)) {
return;
}
clear(currChecks);
line = parsePointers(line,elems);
lineType ltp = getLineType(line);
compilerState.RCPvars = memoryAlloc(sizeof(array(struct variable*)));

compilerState.RCPvars->length = 0;
compilerState.RCPvars->elemSize = sizeof(struct variable*);
currSetVar = null;
if ((ltp==LINE_TYPE_VAR)&&(len(line)>1)) {
struct Tok ft = line->data[0];
struct Tok st = line->data[1];
if ((strcmp(st.cont, "=") == 0)) {
struct variable* v = searchVar(ft.cont,elems);
currSetVar = v;
}
}
char parsed = false;
if ((ltp==LINE_TYPE_INCLUDE)) {
parsed = true;
parseInclude(line,elems);
}
else if ((ltp==LINE_TYPE_IMPORT)) {
parsed = true;
parseImport(line,elems);
}
else if ((ltp==LINE_TYPE_DEFINE)) {
parsed = true;
parseDefine(line,elems);
}
else if ((ltp==LINE_TYPE_CLIB)) {
parsed = true;
parseClib(line);
}
else if ((ltp==LINE_TYPE_STRUCT)) {
parsed = true;
parseStruct(line,elems);
}
else if ((ltp==LINE_TYPE_CONST)) {
parsed = true;
parseConst(line,elems);
}
else if ((ltp==LINE_TYPE_MACRO)) {
return;
}
else if ((ltp!=LINE_TYPE_FN_DECL)) {
line = prePross(line,ltp,elems);
if ((len(line)==0)) {
return;
}
}
struct Tok ft = line->data[0];
if ((ft.isOper==false)&&(ft.isFunc==true)) {
struct func* fn = searchFuncByToken(&ft,elems);
if ((fn!=null)&&(fn->returns!=null)&&isRCPtype(fn->returns->type,elems)) {
char * ____BAH_COMPILER_VAR_1435 =registerRCPvar(fn->returns->type,ft.cont,elems);return;
}
}
if ((ltp==LINE_TYPE_VAR)) {
parsed = true;
parseVar(line,elems);
}
else if ((ltp==LINE_TYPE_FN_CALL)) {
if ((len(line)>1)) {
throwErr(&line->data[len(line)-1],"Not expecting {TOKEN} after function call.");
}
parsed = true;
char** ____BAH_COMPILER_VAR_1436 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1436[1] = ";\n";____BAH_COMPILER_VAR_1436[0] = ft.cont;char * ____BAH_COMPILER_VAR_1437 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1436, 2);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1437));
}
else if ((ltp==LINE_TYPE_FN_DECL)) {
parsed = true;
parseFnDeclare(line,elems);
}
else if ((ltp==LINE_TYPE_RETURN)) {
parsed = true;
parseReturn(line,elems);
}
else if ((ltp==LINE_TYPE_IF)) {
parsed = true;
parseIf(line,false,elems);
}
else if ((ltp==LINE_TYPE_ELSE)) {
parsed = true;
parseElse(line,elems);
}
else if ((ltp==LINE_TYPE_FOR)) {
parsed = true;
parseFor(line,elems);
}
else if ((ltp==LINE_TYPE_FOR_OPERATOR)) {
parsed = true;
parseForOp(line,elems);
}
else if ((ltp==LINE_TYPE_PRE_KEYWORD)) {
parsePreKeyword(line,elems);
parsed = true;
}
else if ((ltp==LINE_TYPE_ASYNC)) {
parseAsync(line,elems);
parsed = true;
}
else if ((ltp==LINE_TYPE_CAPTURE)) {
parseCapture(line,elems);
parsed = true;
}
if ((parsed==false)) {
throwErr(&ft,"{TOKEN} not expected.");
}
if ((strlen(NEXT_LINE)>0)) {
OUTPUT = rope__add(OUTPUT, rope(NEXT_LINE));
NEXT_LINE = "";
}
prevLine = ltp;
};
void parseLines(__BAH_ARR_TYPE_Tok tokens,struct Elems* elems){
if ((len(tokens)==0)) {
return;
}
array(struct Tok)* line = memoryAlloc(sizeof(array(struct Tok)));

line->length = 0;
line->elemSize = sizeof(struct Tok);
struct Tok ft = tokens->data[0];
unsigned int currentLine = ft.line;
long int nbEncl = 0;
register long int i = 0;
while ((i<len(tokens))) {
struct Tok t = tokens->data[i];
if ((t.type==TOKEN_TYPE_ENCL)) {
if ((strcmp(t.cont, "(") == 0)) {
nbEncl = nbEncl+1;
}
else if ((strcmp(t.cont, ")") == 0)) {
nbEncl = nbEncl-1;
}
else if ((strcmp(t.cont, "{") == 0)) {
nbEncl = nbEncl+1;
}
else if ((strcmp(t.cont, "}") == 0)) {
nbEncl = nbEncl-1;
}
else if ((strcmp(t.cont, "[") == 0)) {
nbEncl = nbEncl+1;
}
else if ((strcmp(t.cont, "]") == 0)) {
nbEncl = nbEncl-1;
}
}
if ((t.type==TOKEN_TYPE_STR)&&(t.begLine==currentLine)) {
currentLine = t.line;
}
if ((nbEncl==0)) {
if ((t.line!=currentLine)) {
if ((t.type==TOKEN_TYPE_ENCL)) {

    unsigned int ____BAH_COMPILER_VAR_1438 = len(line);
    __Bah_realocate_arr(line, ____BAH_COMPILER_VAR_1438);
    line->data[____BAH_COMPILER_VAR_1438] = t;
struct Tok pt = tokens->data[i-1];
currentLine = pt.line;
}
else {
currentLine = t.line;
}
parseLine(line,elems);
clear(line);
if ((t.type==TOKEN_TYPE_ENCL)) {
++i;
continue;
}
}
else if ((strcmp(t.cont, ";") == 0)) {
currentLine = t.line;
parseLine(line,elems);
clear(line);
++i;
continue;
}
}

    unsigned int ____BAH_COMPILER_VAR_1439 = len(line);
    __Bah_realocate_arr(line, ____BAH_COMPILER_VAR_1439);
    line->data[____BAH_COMPILER_VAR_1439] = t;
++i;
};
if ((len(line)>0)) {
if ((nbEncl==0)) {
parseLine(line,elems);
clear(line);
}
else {
ft = line->data[len(line)-1];
throwErr(&ft,"Missing closing token, line ending by {TOKEN}.");
}
}
};
void declareFunc(struct func* fn,struct Elems* elems){
struct string tmpfnRetCType = getCType(fn->returns->type,elems);
char * tmpfnArgsCType = "";
register long int j = 0;
while ((j<len(fn->args))) {
struct variable* arg = fn->args->data[j];
struct string ct = getCType(arg->type,elems);
char** ____BAH_COMPILER_VAR_1440 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1440[3] = arg->name;____BAH_COMPILER_VAR_1440[2] = " ";____BAH_COMPILER_VAR_1440[1] = string__str(&ct);____BAH_COMPILER_VAR_1440[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_1441 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1440, 4);tmpfnArgsCType = ____BAH_COMPILER_VAR_1441;
j = j+1;
if ((j<len(fn->args))) {
char** ____BAH_COMPILER_VAR_1442 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1442[1] = ", ";____BAH_COMPILER_VAR_1442[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_1443 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1442, 2);tmpfnArgsCType = ____BAH_COMPILER_VAR_1443;
}
};
char** ____BAH_COMPILER_VAR_1444 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_1444[5] = ");\n";____BAH_COMPILER_VAR_1444[4] = tmpfnArgsCType;____BAH_COMPILER_VAR_1444[3] = "(";____BAH_COMPILER_VAR_1444[2] = fn->name;____BAH_COMPILER_VAR_1444[1] = " ";____BAH_COMPILER_VAR_1444[0] = string__str(&tmpfnRetCType);char * ____BAH_COMPILER_VAR_1445 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1444, 6);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1445));
};
void declareVar(struct variable* v,struct Elems* elems){
if ((v->isConst==true)) {
char** ____BAH_COMPILER_VAR_1446 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1446[4] = "\n";____BAH_COMPILER_VAR_1446[3] = v->constVal;____BAH_COMPILER_VAR_1446[2] = " ";____BAH_COMPILER_VAR_1446[1] = v->name;____BAH_COMPILER_VAR_1446[0] = "#define ";char * ____BAH_COMPILER_VAR_1447 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1446, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1447));
}
else {
struct string cType = getCType(v->type,elems);
char** ____BAH_COMPILER_VAR_1448 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1448[3] = ";\n";____BAH_COMPILER_VAR_1448[2] = v->name;____BAH_COMPILER_VAR_1448[1] = " ";____BAH_COMPILER_VAR_1448[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_1449 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1448, 4);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1449));
}
};
void declareAll(struct Elems* elems){
OUTPUT = rope("\n#define noCheck(v) v\n#define array(type)	\
struct{	\
type *data; \
long int length; \
long int elemSize; \
}\ntypedef array(char*)* __BAH_ARR_TYPE_cpstring;\nlong int __BAH__main(__BAH_ARR_TYPE_cpstring);\n");
register long int i = 0;
for (; (i<len(compilerState.cIncludes)); ++i) {
char** ____BAH_COMPILER_VAR_1450 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1450[2] = "\n";____BAH_COMPILER_VAR_1450[1] = compilerState.cIncludes->data[i];____BAH_COMPILER_VAR_1450[0] = "#include ";char * ____BAH_COMPILER_VAR_1451 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1450, 3);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1451));
};
i = 1;
for (; (i<len(compilerState.arrTypesDecl)); ++i) {
char * t = compilerState.arrTypesDecl->data[i];
struct string elemType = string(t);
string__trimLeft(&elemType,15);
char * ____BAH_COMPILER_VAR_1452 =string__str(&elemType);struct string elemCtype = getCType(____BAH_COMPILER_VAR_1452,elems);
char** ____BAH_COMPILER_VAR_1453 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1453[4] = ";\n";____BAH_COMPILER_VAR_1453[3] = t;____BAH_COMPILER_VAR_1453[2] = ")* ";____BAH_COMPILER_VAR_1453[1] = string__str(&elemCtype);____BAH_COMPILER_VAR_1453[0] = "typedef array(";char * ____BAH_COMPILER_VAR_1454 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1453, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1454));
};
i = 0;
for (; (i<len(elems->vars)); ++i) {
struct variable* v = elems->vars->data[i];
declareVar(v,elems);
};
i = 0;
for (; (i<len(elems->fns)); ++i) {
struct func* fn = elems->fns->data[i];
if ((fn->isBinding==true)) {
continue;
}
declareFunc(fn,elems);
};
};
char * memErrHandle(){
char** ____BAH_COMPILER_VAR_1455 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1455[1] = compilerState.currentFile;____BAH_COMPILER_VAR_1455[0] = "file: ";char * ____BAH_COMPILER_VAR_1456 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1455, 2);char * r = ____BAH_COMPILER_VAR_1456;
if ((currentFn!=null)) {
char** ____BAH_COMPILER_VAR_1457 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1457[2] = "()";____BAH_COMPILER_VAR_1457[1] = currentFn->name;____BAH_COMPILER_VAR_1457[0] = "\nfunction: ";char * ____BAH_COMPILER_VAR_1458 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1457, 3);char** ____BAH_COMPILER_VAR_1459 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1459[1] = ____BAH_COMPILER_VAR_1458;____BAH_COMPILER_VAR_1459[0] = r;char * ____BAH_COMPILER_VAR_1460 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1459, 2);r = ____BAH_COMPILER_VAR_1460;
}
return r;
};
long int main(__BAH_ARR_TYPE_cpstring args){
onMemoryError = memErrHandle;
execName = args->data[0];
if ((execName[0]==46)||(execName[0]==47)) {
execName = absPath(execName);
}
struct flags ____BAH_COMPILER_VAR_1461 = {};
____BAH_COMPILER_VAR_1461.flags = memoryAlloc(sizeof(array(struct flag*)));
            ____BAH_COMPILER_VAR_1461.flags->length = 0;
            ____BAH_COMPILER_VAR_1461.flags->elemSize = sizeof(struct flag*);
            ____BAH_COMPILER_VAR_1461.args = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_1461.args->length = 0;
            ____BAH_COMPILER_VAR_1461.args->elemSize = sizeof(char *);
            flags = ____BAH_COMPILER_VAR_1461;
flags__addString(&flags,"o","Name of the file to output.");
flags__addBool(&flags,"c","Translate bah file to C instead of compiling it.");
flags__addBool(&flags,"v","Show version of the compiler.");
flags__addBool(&flags,"l","Compile as a library.");
flags__addBool(&flags,"rcp","Enables RCP (reference counter) instead of the garbage collector. Warning: if you are using self-reference, this will lead to memory leaks!");
flags__addBool(&flags,"fastrcp","Enables RCP without leak detection. It is recommended to test you programs with the -rcp flag to test for leak detection before using this flag.");
flags__addBool(&flags,"debug","Enables verbose json output.");
flags__addBool(&flags,"verboseRuntime","Enables verbose runtime, a debug mode of the compiled program. (obsolete)");
flags__addBool(&flags,"verboseCC","Enables verbose C compiler output, USE IN LAST RESORT.");
char** ____BAH_COMPILER_VAR_1462 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1462[2] = ".";____BAH_COMPILER_VAR_1462[1] = BAH_OS;____BAH_COMPILER_VAR_1462[0] = "Select the target OS for cross compilling (linux, windows, darwin), default: ";char * ____BAH_COMPILER_VAR_1463 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1462, 3);flags__addString(&flags,"target",____BAH_COMPILER_VAR_1463);
char** ____BAH_COMPILER_VAR_1464 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1464[2] = ").";____BAH_COMPILER_VAR_1464[1] = BAH_DIR;____BAH_COMPILER_VAR_1464[0] = "If your Bah directory is not the default one (";char * ____BAH_COMPILER_VAR_1465 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1464, 3);flags__addString(&flags,"bahDir",____BAH_COMPILER_VAR_1465);
char** ____BAH_COMPILER_VAR_1466 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1466[2] = ".";____BAH_COMPILER_VAR_1466[1] = BAH_CC;____BAH_COMPILER_VAR_1466[0] = "To change the C compiler used, default: ";char * ____BAH_COMPILER_VAR_1467 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1466, 3);flags__addString(&flags,"CC",____BAH_COMPILER_VAR_1467);
flags__addBool(&flags,"object","Compile as an object.");
flags__addBool(&flags,"unsafe","Compile without safety checking. This will make for faster executable but if your program crashes, it will show less informations.");
flags__addBool(&flags,"nobuiltin","Does not include the builtin library (be really carefull, your program WILL break).");
flags__addBool(&flags,"optimize","Includes optimized functions");
flags__addBool(&flags,"n","Disables notices while keeping warnings enabled.");
flags__parse(&flags,args);
if ((flags__isSet(&flags,"target")==1)) {
BAH_OS = flags__get(&flags,"target");
char** ____BAH_COMPILER_VAR_1468 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1468[1] = BAH_OS;____BAH_COMPILER_VAR_1468[0] = "Build target: ";char * ____BAH_COMPILER_VAR_1469 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1468, 2);println(____BAH_COMPILER_VAR_1469);
}
if ((flags__isSet(&flags,"bahDir")==1)) {
BAH_DIR = flags__get(&flags,"bahDir");
array(char)* bahDirArr = strAsArr(BAH_DIR);
if ((bahDirArr->data[len(bahDirArr)-1]!=47)) {
char** ____BAH_COMPILER_VAR_1470 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1470[1] = "/";____BAH_COMPILER_VAR_1470[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_1471 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1470, 2);BAH_DIR = ____BAH_COMPILER_VAR_1471;
}
char** ____BAH_COMPILER_VAR_1472 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1472[1] = BAH_DIR;____BAH_COMPILER_VAR_1472[0] = "Bah directory: ";char * ____BAH_COMPILER_VAR_1473 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1472, 2);println(____BAH_COMPILER_VAR_1473);
}
if ((flags__isSet(&flags,"CC")==1)) {
BAH_CC = flags__get(&flags,"CC");
char** ____BAH_COMPILER_VAR_1474 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1474[1] = BAH_CC;____BAH_COMPILER_VAR_1474[0] = "C compiler: ";char * ____BAH_COMPILER_VAR_1475 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1474, 2);println(____BAH_COMPILER_VAR_1475);
}
if (flags__isSet(&flags,"verboseRuntime")) {
println("-verboseRuntime is obsolete.");
exit(1);
}
noticeEnabled = (flags__isSet(&flags,"n")==0);
RCPlevel = 0;
if (flags__isSet(&flags,"rcp")) {
RCPlevel = 1;
}
else if (flags__isSet(&flags,"fastrcp")) {
RCPlevel = 2;
}
verboseRuntime = (flags__isSet(&flags,"verboseRuntime")==1);
debug = (flags__isSet(&flags,"debug")==1);
isObject = (flags__isSet(&flags,"object")==1);
isUnsafe = (flags__isSet(&flags,"unsafe")==1);
isOptimized = (flags__isSet(&flags,"optimize")==1);
if ((debug==true)) {
debugStart();
}
RCPenabled = (flags__isSet(&flags,"rcp")==1)||flags__isSet(&flags,"fastrcp");
if ((flags__isSet(&flags,"v")==1)) {
char** ____BAH_COMPILER_VAR_1476 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1476[2] = ".\n© Alois Laurent Boe";____BAH_COMPILER_VAR_1476[1] = BAH_VERSION;____BAH_COMPILER_VAR_1476[0] = "Bah compiler version: ";char * ____BAH_COMPILER_VAR_1477 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1476, 3);println(____BAH_COMPILER_VAR_1477);
return 0;
}
if ((flags__isSet(&flags,"c")==1)&&(flags__isSet(&flags,"l")==1)) {
__BAH_panic("Cannot use -c (to translate to C code) and -l (to compile as a library) at the same time.","/home/alois/Documents/bah-bah/src/main.bah:144");
}
INIT = rope("");
OUTPUT = rope("\n    void __BAH_init();\n    #define noCheck(v) v\n    #define array(type)	\
    struct{	\
    type *data; \
    long int length; \
    long int realLength; \
    long int elemSize; \
    }\n    typedef array(char*)* __BAH_ARR_TYPE_cpstring;\n    long int __BAH__main(__BAH_ARR_TYPE_cpstring);\n    ");
if ((flags__isSet(&flags,"l")==0)) {
if ((RCPenabled==true)) {
OUTPUT = rope__add(OUTPUT, rope("\n            void RCP_init();\n            void RCP_shutdown();\n            void free(void*);\n            #include <string.h>\n            int main(int argc, char ** argv) {\n            RCP_init();\n            array(char*) * args = malloc(sizeof(array(char*)));\n            args->data = malloc(sizeof(char*)*argc);\n            memcpy(args->data, argv, sizeof(char*)*argc);\n            args->elemSize = sizeof(char*);\n            args->length = argc;\n            __BAH_init();\n            long int r =  __BAH__main((__BAH_ARR_TYPE_cpstring)args);\n            free(args->data);\n            free(args);\n            RCP_shutdown();\n            return r;\n            };\n            #define main(v) __BAH__main(v)\n            "));
}
else {
OUTPUT = rope__add(OUTPUT, rope("\n            #include <gc.h>\n            #include <string.h>\n            int main(int argc, char ** argv) {\n            GC_INIT();\n            array(char*) * args = GC_MALLOC(sizeof(array(char*)));\n            args->data = GC_MALLOC(sizeof(char*)*argc);\n            memcpy(args->data, argv, sizeof(char*)*argc);\n            args->elemSize = sizeof(char*);\n            args->length = argc;\n            __BAH_init();\n            long int r =  __BAH__main((__BAH_ARR_TYPE_cpstring)args);\n            GC_FREE(args->data);\n            GC_FREE(args);\n            return r;\n            };\n            #define main(v) __BAH__main(v)\n            "));
}
}
struct compilerStateTag ____BAH_COMPILER_VAR_1478 = {};
____BAH_COMPILER_VAR_1478.includes = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_1478.includes->length = 0;
            ____BAH_COMPILER_VAR_1478.includes->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_1478.cIncludes = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_1478.cIncludes->length = 0;
            ____BAH_COMPILER_VAR_1478.cIncludes->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_1478.cLibs = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_1478.cLibs->length = 0;
            ____BAH_COMPILER_VAR_1478.cLibs->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_1478.currentDir = "./";
____BAH_COMPILER_VAR_1478.arrTypesDecl = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_1478.arrTypesDecl->length = 0;
            ____BAH_COMPILER_VAR_1478.arrTypesDecl->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_1478.RCPvars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_1478.RCPvars->length = 0;
            ____BAH_COMPILER_VAR_1478.RCPvars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_1478.evals = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_1478.evals->length = 0;
            ____BAH_COMPILER_VAR_1478.evals->elemSize = sizeof(char *);
            compilerState = ____BAH_COMPILER_VAR_1478;

    unsigned int ____BAH_COMPILER_VAR_1479 = 0;
    __Bah_realocate_arr(compilerState.arrTypesDecl, ____BAH_COMPILER_VAR_1479);
    compilerState.arrTypesDecl->data[____BAH_COMPILER_VAR_1479] = "__BAH_ARR_TYPE_cpstring";
char * fileName = absPath(args->data[1]);
compilerState.currentFile = fileName;
struct fileMap ____BAH_COMPILER_VAR_1480 = {};
____BAH_COMPILER_VAR_1480.handle = -1;
#define fm ____BAH_COMPILER_VAR_1480
char * f = fileMap__open(&fm,fileName);
if ((fileMap__isValid(&fm)==0)||(fm.size==0)) {
char** ____BAH_COMPILER_VAR_1481 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1481[2] = "'.";____BAH_COMPILER_VAR_1481[1] = args->data[1];____BAH_COMPILER_VAR_1481[0] = "Could not open file '";char * ____BAH_COMPILER_VAR_1482 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1481, 3);println(____BAH_COMPILER_VAR_1482);
exit(1);
}
long int startTime = getTimeUnix();
array(struct Tok)* tokens = lexer(f);
fileMap__close(&fm);
if ((len(tokens)==0)) {
char** ____BAH_COMPILER_VAR_1483 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1483[2] = "' not recognized.";____BAH_COMPILER_VAR_1483[1] = fileName;____BAH_COMPILER_VAR_1483[0] = "File '";char * ____BAH_COMPILER_VAR_1484 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1483, 3);println(____BAH_COMPILER_VAR_1484);
exit(1);
}
struct Elems* ____BAH_COMPILER_VAR_1485 = memoryAlloc(sizeof(struct Elems));
____BAH_COMPILER_VAR_1485->vars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_1485->vars->length = 0;
            ____BAH_COMPILER_VAR_1485->vars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_1485->structs = memoryAlloc(sizeof(array(struct cStruct*)));
            ____BAH_COMPILER_VAR_1485->structs->length = 0;
            ____BAH_COMPILER_VAR_1485->structs->elemSize = sizeof(struct cStruct*);
            ____BAH_COMPILER_VAR_1485->types = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_1485->types->length = 0;
            ____BAH_COMPILER_VAR_1485->types->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_1485->fns = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_1485->fns->length = 0;
            ____BAH_COMPILER_VAR_1485->fns->elemSize = sizeof(struct func*);
            ____BAH_COMPILER_VAR_1485->defined = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_1485->defined->length = 0;
            ____BAH_COMPILER_VAR_1485->defined->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_1485->branchChecks = memoryAlloc(sizeof(array(struct varCheck)));
            ____BAH_COMPILER_VAR_1485->branchChecks->length = 0;
            ____BAH_COMPILER_VAR_1485->branchChecks->elemSize = sizeof(struct varCheck);
            struct Elems* elems = ____BAH_COMPILER_VAR_1485;
if ((isObject==true)) {
OUTPUT = rope("\n        #define noCheck(v) v\n        #define array(type)	\
        struct{	\
        type *data; \
        long int length; \
        long int realLength; \
        long int elemSize; \
        }\n        typedef array(char*)* __BAH_ARR_TYPE_cpstring;\n        long int __BAH__main(__BAH_ARR_TYPE_cpstring);\n        ");
shouldOnlyDecl = true;
}

                struct string ____BAH_COMPILER_VAR_1486 = string(fileName);
                if ((flags__isSet(&flags,"nobuiltin")==0)&&(string__hasSuffix(&____BAH_COMPILER_VAR_1486,".bahstrp")==false)) {
if ((includeFile("builtin.bah",elems)==false)) {
char** ____BAH_COMPILER_VAR_1487 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1487[2] = "'";____BAH_COMPILER_VAR_1487[1] = BAH_DIR;____BAH_COMPILER_VAR_1487[0] = "Could not find std-libs, please check '";char * ____BAH_COMPILER_VAR_1488 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1487, 3);__BAH_panic(____BAH_COMPILER_VAR_1488,"/home/alois/Documents/bah-bah/src/main.bah:255");
}
}
shouldOnlyDecl = false;
if ((flags__isSet(&flags,"l")==1)) {
OUTPUT = rope("");
declareAll(elems);
}
compilerState.currentDir = getDirFromFile(fileName);
parseLines(tokens,elems);
if ((isObject==false)&&(isUnsafe==false)) {
long int l = 0;
register long int i = 0;
for (; (i<len(elems->fns)); ++i) {
struct func* fn = elems->fns->data[i];
if ((fn->isBinding==true)) {
continue;
}
++l;
};
char** ____BAH_COMPILER_VAR_1489 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1489[2] = "];";____BAH_COMPILER_VAR_1489[1] = intToStr(l);____BAH_COMPILER_VAR_1489[0] = "volatile struct __Bah_fnName_mapper __tmp____Bah_fnNames[";char * ____BAH_COMPILER_VAR_1490 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1489, 3);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1490));
long int j = 0;
i = 0;
for (; (i<len(elems->fns)); ++i) {
struct func* fn = elems->fns->data[i];
if ((fn->isBinding==true)) {
continue;
}
char * name = fn->name;
char** ____BAH_COMPILER_VAR_1491 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1491[1] = "__";____BAH_COMPILER_VAR_1491[0] = fn->from;char * ____BAH_COMPILER_VAR_1492 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1491, 2);if ((strcmp(fn->from, "") != 0)&&strHasPrefix(name,____BAH_COMPILER_VAR_1492)) {
struct string n = string(name);
string__trimLeft(&n,strlen(fn->from)+2);
char** ____BAH_COMPILER_VAR_1493 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1493[2] = string__str(&n);____BAH_COMPILER_VAR_1493[1] = ".";____BAH_COMPILER_VAR_1493[0] = fn->from;char * ____BAH_COMPILER_VAR_1494 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1493, 3);name = ____BAH_COMPILER_VAR_1494;
}
char** ____BAH_COMPILER_VAR_1495 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_1495[8] = ";\n";____BAH_COMPILER_VAR_1495[7] = fn->name;____BAH_COMPILER_VAR_1495[6] = "].p = ";____BAH_COMPILER_VAR_1495[5] = intToStr(j);____BAH_COMPILER_VAR_1495[4] = "\";\n            __tmp____Bah_fnNames[";____BAH_COMPILER_VAR_1495[3] = name;____BAH_COMPILER_VAR_1495[2] = "].n = \"";____BAH_COMPILER_VAR_1495[1] = intToStr(j);____BAH_COMPILER_VAR_1495[0] = "\n            __tmp____Bah_fnNames[";char * ____BAH_COMPILER_VAR_1496 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1495, 9);INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_1496));
++j;
};
char** ____BAH_COMPILER_VAR_1497 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1497[2] = ";";____BAH_COMPILER_VAR_1497[1] = intToStr(l);____BAH_COMPILER_VAR_1497[0] = "\n        __Bah_fnNames->data = __tmp____Bah_fnNames;\n        __Bah_fnNames->length = ";char * ____BAH_COMPILER_VAR_1498 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1497, 3);INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_1498));
}
makeInit();
array(char *)* excludeFns = memoryAlloc(sizeof(array(char *)));

excludeFns->length = 6;
excludeFns->elemSize = sizeof(char *);
excludeFns->data = memoryAlloc(sizeof(char *) * 50);
                    excludeFns->realLength = 50;
excludeFns->data[0] = "main";
excludeFns->data[1] = "cpstringCharAt";
excludeFns->data[2] = "cpstringSubsitute";
excludeFns->data[3] = "channel";
excludeFns->data[4] = "mapWrapper";
excludeFns->data[5] = "arraySubstitute";
if ((debug==true)) {
debugEnd();
return 0;
}
if ((isObject==false)) {
long int totalTime = getTimeUnix()-startTime;
char** ____BAH_COMPILER_VAR_1499 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_1499[6] = "ms)\e[0m";____BAH_COMPILER_VAR_1499[5] = intToStr(totalLexerTime/1000000);____BAH_COMPILER_VAR_1499[4] = "ms, lexer time: ";____BAH_COMPILER_VAR_1499[3] = intToStr(totalTime/1000000);____BAH_COMPILER_VAR_1499[2] = " lines, total time: ";____BAH_COMPILER_VAR_1499[1] = intToStr(totalLines);____BAH_COMPILER_VAR_1499[0] = "Parsed. (";char * ____BAH_COMPILER_VAR_1500 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1499, 7);println(____BAH_COMPILER_VAR_1500);
}
if ((flags__isSet(&flags,"o")==1)) {
fileName = flags__get(&flags,"o");
}
else {
struct string outFileName = string(args->data[1]);
string__trimRight(&outFileName,4);
fileName = string__str(&outFileName);
}
char * isStatic = "-static";
if ((flags__isSet(&flags,"d")==1)||(strcmp(BAH_OS, "darwin") == 0)) {
isStatic = "";
}
if ((flags__isSet(&flags,"c")==0)) {
char * obj = "";
if ((flags__isSet(&flags,"object")==1)) {
char** ____BAH_COMPILER_VAR_1501 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1501[1] = ".o";____BAH_COMPILER_VAR_1501[0] = fileName;char * ____BAH_COMPILER_VAR_1502 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1501, 2);fileName = ____BAH_COMPILER_VAR_1502;
obj = "-c";
}
char * randFileName = "-x c - -x none";
char** ____BAH_COMPILER_VAR_1503 = alloca(17 * sizeof(char*));____BAH_COMPILER_VAR_1503[16] = fileName;____BAH_COMPILER_VAR_1503[15] = " -w -O1 -o ";____BAH_COMPILER_VAR_1503[14] = obj;____BAH_COMPILER_VAR_1503[13] = " ";____BAH_COMPILER_VAR_1503[12] = isStatic;____BAH_COMPILER_VAR_1503[11] = " ";____BAH_COMPILER_VAR_1503[10] = randFileName;____BAH_COMPILER_VAR_1503[9] = "/\" ";____BAH_COMPILER_VAR_1503[8] = BAH_OS;____BAH_COMPILER_VAR_1503[7] = "libs/";____BAH_COMPILER_VAR_1503[6] = BAH_DIR;____BAH_COMPILER_VAR_1503[5] = "/include/\" -L \"";____BAH_COMPILER_VAR_1503[4] = BAH_OS;____BAH_COMPILER_VAR_1503[3] = "libs/";____BAH_COMPILER_VAR_1503[2] = BAH_DIR;____BAH_COMPILER_VAR_1503[1] = " -I \"";____BAH_COMPILER_VAR_1503[0] = BAH_CC;char * ____BAH_COMPILER_VAR_1504 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1503, 17);char * gccArgs = ____BAH_COMPILER_VAR_1504;
if ((flags__isSet(&flags,"l")==1)) {
char** ____BAH_COMPILER_VAR_1505 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1505[1] = " -c";____BAH_COMPILER_VAR_1505[0] = gccArgs;char * ____BAH_COMPILER_VAR_1506 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1505, 2);gccArgs = ____BAH_COMPILER_VAR_1506;
}
array(char *)* cLibs = compilerState.cLibs;
register long int i = 0;
while ((i<len(cLibs))) {
char * l = cLibs->data[i];
char** ____BAH_COMPILER_VAR_1507 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1507[2] = l;____BAH_COMPILER_VAR_1507[1] = " -";____BAH_COMPILER_VAR_1507[0] = gccArgs;char * ____BAH_COMPILER_VAR_1508 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1507, 3);gccArgs = ____BAH_COMPILER_VAR_1508;
i = i+1;
};
struct command cmd = command(gccArgs);
cmd.input = rope__toStr(OUTPUT);
if ((flags__isSet(&flags,"verboseCC")==1)) {
char * ____BAH_COMPILER_VAR_1509 =command__run(&cmd);println(____BAH_COMPILER_VAR_1509);
}
else {
char * ____BAH_COMPILER_VAR_1510 =command__run(&cmd);}
if ((cmd.status!=0)) {
println("\e[1;31m[CC-ERROR]\e[0m\nCould not compiled.");
return 1;
}
if ((flags__isSet(&flags,"l")==1)) {
char** ____BAH_COMPILER_VAR_1511 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1511[3] = fileName;____BAH_COMPILER_VAR_1511[2] = ".a ";____BAH_COMPILER_VAR_1511[1] = fileName;____BAH_COMPILER_VAR_1511[0] = "ar rcs ";char * ____BAH_COMPILER_VAR_1512 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1511, 4);cmd = command(____BAH_COMPILER_VAR_1512);
char * ____BAH_COMPILER_VAR_1513 =command__run(&cmd);}
}
else {
if ((flags__isSet(&flags,"o")==0)) {
char** ____BAH_COMPILER_VAR_1514 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1514[1] = ".c";____BAH_COMPILER_VAR_1514[0] = fileName;char * ____BAH_COMPILER_VAR_1515 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1514, 2);fileName = ____BAH_COMPILER_VAR_1515;
}
char** ____BAH_COMPILER_VAR_1516 = alloca(14 * sizeof(char*));____BAH_COMPILER_VAR_1516[13] = " -O1 -w ";____BAH_COMPILER_VAR_1516[12] = isStatic;____BAH_COMPILER_VAR_1516[11] = " ";____BAH_COMPILER_VAR_1516[10] = fileName;____BAH_COMPILER_VAR_1516[9] = "/\" ";____BAH_COMPILER_VAR_1516[8] = BAH_OS;____BAH_COMPILER_VAR_1516[7] = "libs/";____BAH_COMPILER_VAR_1516[6] = BAH_DIR;____BAH_COMPILER_VAR_1516[5] = "/include/\" -L \"";____BAH_COMPILER_VAR_1516[4] = BAH_OS;____BAH_COMPILER_VAR_1516[3] = "libs/";____BAH_COMPILER_VAR_1516[2] = BAH_DIR;____BAH_COMPILER_VAR_1516[1] = " -I \"";____BAH_COMPILER_VAR_1516[0] = BAH_CC;char * ____BAH_COMPILER_VAR_1517 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1516, 14);char * gccArgs = ____BAH_COMPILER_VAR_1517;
array(char *)* cLibs = compilerState.cLibs;
register long int i = 0;
while ((i<len(cLibs))) {
char * l = cLibs->data[i];
char** ____BAH_COMPILER_VAR_1518 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1518[2] = l;____BAH_COMPILER_VAR_1518[1] = " -";____BAH_COMPILER_VAR_1518[0] = gccArgs;char * ____BAH_COMPILER_VAR_1519 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1518, 3);gccArgs = ____BAH_COMPILER_VAR_1519;
i = i+1;
};
char** ____BAH_COMPILER_VAR_1520 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1520[2] = "'\n";____BAH_COMPILER_VAR_1520[1] = gccArgs;____BAH_COMPILER_VAR_1520[0] = "//COMPILE WITH: '";char * ____BAH_COMPILER_VAR_1521 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1520, 3);OUTPUT = rope__add(rope(____BAH_COMPILER_VAR_1521), OUTPUT);
struct fileStream ____BAH_COMPILER_VAR_1522 = {};
#define fs ____BAH_COMPILER_VAR_1522
fileStream__open(&fs,fileName,"w");
char * ____BAH_COMPILER_VAR_1523 =rope__toStr(OUTPUT);fileStream__writeFile(&fs,____BAH_COMPILER_VAR_1523);
fileStream__close(&fs);

#undef fs
}
if ((isObject==false)) {
long int totalTime = getTimeUnix()-startTime;
char** ____BAH_COMPILER_VAR_1524 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1524[2] = "ms)\e[0m";____BAH_COMPILER_VAR_1524[1] = intToStr(totalTime/1000000);____BAH_COMPILER_VAR_1524[0] = "\e[1;32mDone. (compiled in ";char * ____BAH_COMPILER_VAR_1525 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1524, 3);println(____BAH_COMPILER_VAR_1525);
}
return 0;

#undef fm
};
volatile struct __Bah_fnName_mapper __tmp____Bah_fnNames[315];
    
    void __attribute__((optimize("O0"))) __BAH_init() {
        __BAH_panic_chan = null;
__Bah_fnNames = memoryAlloc(sizeof(array(struct __Bah_fnName_mapper)));

__Bah_fnNames->length = 0;
__Bah_fnNames->elemSize = sizeof(struct __Bah_fnName_mapper);
onMemoryError = null;
__Bah_init_segfaultHandle_OK = __Bah_init_segfaultHandle();
RAND_SEEDED = false;
BAH_DIR = "/opt/bah/";
BAH_OS = "darwin";
BAH_CC = "clang";
debug = false;
verboseRuntime = false;
isObject = false;
isUnsafe = false;
isOptimized = false;
noticeEnabled = true;
execName = "bah";
isSubObject = false;
isImportedSubObject = false;
OUTPUT = rope("");
NEXT_LINE = "";
INIT = rope("");
shouldOnlyDecl = false;
threadCount = 0;
currentFn = null;
totalLines = 0;
totalLexerTime = 0;
RCPenabled = false;
RCPlevel = 0;
currSetVar = null;
currChecks = memoryAlloc(sizeof(array(struct varCheck)));

currChecks->length = 0;
currChecks->elemSize = sizeof(struct varCheck);
prevIfExits = false;
prevIfChecks = memoryAlloc(sizeof(array(struct varCheck)));

prevIfChecks->length = 0;
prevIfChecks->elemSize = sizeof(struct varCheck);
enclavers = memoryAlloc(sizeof(array(char)));

enclavers->length = 6;
enclavers->elemSize = sizeof(char);
enclavers->data = memoryAlloc(sizeof(char) * 50);
                    enclavers->realLength = 50;
enclavers->data[0] = 40;
enclavers->data[1] = 41;
enclavers->data[2] = 123;
enclavers->data[3] = 125;
enclavers->data[4] = 91;
enclavers->data[5] = 93;
syntaxes = memoryAlloc(sizeof(array(char)));

syntaxes->length = 15;
syntaxes->elemSize = sizeof(char);
syntaxes->data = memoryAlloc(sizeof(char) * 50);
                    syntaxes->realLength = 50;
syntaxes->data[0] = 33;
syntaxes->data[1] = 61;
syntaxes->data[2] = 124;
syntaxes->data[3] = (char)38;
syntaxes->data[4] = 37;
syntaxes->data[5] = 43;
syntaxes->data[6] = 45;
syntaxes->data[7] = 42;
syntaxes->data[8] = 47;
syntaxes->data[9] = 44;
syntaxes->data[10] = 60;
syntaxes->data[11] = 62;
syntaxes->data[12] = 58;
syntaxes->data[13] = (char)59;
syntaxes->data[14] = 94;
keywords = memoryAlloc(sizeof(array(char *)));

keywords->length = 23;
keywords->elemSize = sizeof(char *);
keywords->data = memoryAlloc(sizeof(char *) * 50);
                    keywords->realLength = 50;
keywords->data[0] = "if";
keywords->data[1] = "else";
keywords->data[2] = "for";
keywords->data[3] = "struct";
keywords->data[4] = "const";
keywords->data[5] = "return";
keywords->data[6] = "extend";
keywords->data[7] = "new";
keywords->data[8] = "break";
keywords->data[9] = "continue";
keywords->data[10] = "default";
keywords->data[11] = "switch";
keywords->data[12] = "case";
keywords->data[13] = "while";
keywords->data[14] = "typedef";
keywords->data[15] = "function";
keywords->data[16] = "async";
keywords->data[17] = "in";
keywords->data[18] = "chan";
keywords->data[19] = "map";
keywords->data[20] = "buffer";
keywords->data[21] = "capture";
keywords->data[22] = "then";
intTypes = memoryAlloc(sizeof(array(char *)));

intTypes->length = 5;
intTypes->elemSize = sizeof(char *);
intTypes->data = memoryAlloc(sizeof(char *) * 50);
                    intTypes->realLength = 50;
intTypes->data[0] = "int";
intTypes->data[1] = "int32";
intTypes->data[2] = "uint";
intTypes->data[3] = "uint32";
intTypes->data[4] = "bool";
floatTypes = memoryAlloc(sizeof(array(char *)));

floatTypes->length = 4;
floatTypes->elemSize = sizeof(char *);
floatTypes->data = memoryAlloc(sizeof(char *) * 50);
                    floatTypes->realLength = 50;
floatTypes->data[0] = "float";
floatTypes->data[1] = "float32";
floatTypes->data[2] = "ufloat";
floatTypes->data[3] = "ufloat32";
NB_COMP_VAR = 0;
noVOfns = memoryAlloc(sizeof(array(char *)));

noVOfns->length = 1;
noVOfns->elemSize = sizeof(char *);
noVOfns->data = memoryAlloc(sizeof(char *) * 50);
                    noVOfns->realLength = 50;
noVOfns->data[0] = "__Bah_safe_string";
cache = memoryAlloc(sizeof(array(struct cacheFile*)));

cache->length = 0;
cache->elemSize = sizeof(struct cacheFile*);
prevLine = (lineType)-1;
signs = memoryAlloc(sizeof(array(char *)));

signs->length = 10;
signs->elemSize = sizeof(char *);
signs->data = memoryAlloc(sizeof(char *) * 50);
                    signs->realLength = 50;
signs->data[0] = "|";
signs->data[1] = "&";
signs->data[2] = "%";
signs->data[3] = "+";
signs->data[4] = "-";
signs->data[5] = "*";
signs->data[6] = "/";
signs->data[7] = "<<";
signs->data[8] = ">>";
signs->data[9] = "^";
comparators = memoryAlloc(sizeof(array(char *)));

comparators->length = 7;
comparators->elemSize = sizeof(char *);
comparators->data = memoryAlloc(sizeof(char *) * 50);
                    comparators->realLength = 50;
comparators->data[0] = "==";
comparators->data[1] = "!=";
comparators->data[2] = ">";
comparators->data[3] = "<";
comparators->data[4] = "<=";
comparators->data[5] = ">=";
comparators->data[6] = "in";
compSep = memoryAlloc(sizeof(array(char *)));

compSep->length = 2;
compSep->elemSize = sizeof(char *);
compSep->data = memoryAlloc(sizeof(char *) * 50);
                    compSep->realLength = 50;
compSep->data[0] = "||";
compSep->data[1] = "&&";
equalsTokens = memoryAlloc(sizeof(array(char *)));

equalsTokens->length = 5;
equalsTokens->elemSize = sizeof(char *);
equalsTokens->data = memoryAlloc(sizeof(char *) * 50);
                    equalsTokens->realLength = 50;
equalsTokens->data[0] = "=";
equalsTokens->data[1] = "+=";
equalsTokens->data[2] = "-=";
equalsTokens->data[3] = "*=";
equalsTokens->data[4] = "/=";

            __tmp____Bah_fnNames[0].n = "__BAH_panic";
            __tmp____Bah_fnNames[0].p = __BAH_panic;

            __tmp____Bah_fnNames[1].n = "__Bah_safe_string";
            __tmp____Bah_fnNames[1].p = __Bah_safe_string;

            __tmp____Bah_fnNames[2].n = "__bah_strcmp";
            __tmp____Bah_fnNames[2].p = __bah_strcmp;

            __tmp____Bah_fnNames[3].n = "__bah_strlen";
            __tmp____Bah_fnNames[3].p = __bah_strlen;

            __tmp____Bah_fnNames[4].n = "print";
            __tmp____Bah_fnNames[4].p = print;

            __tmp____Bah_fnNames[5].n = "__BAH_memcpy";
            __tmp____Bah_fnNames[5].p = __BAH_memcpy;

            __tmp____Bah_fnNames[6].n = "len";
            __tmp____Bah_fnNames[6].p = len;

            __tmp____Bah_fnNames[7].n = "memoryAlloc";
            __tmp____Bah_fnNames[7].p = memoryAlloc;

            __tmp____Bah_fnNames[8].n = "destroy";
            __tmp____Bah_fnNames[8].p = destroy;

            __tmp____Bah_fnNames[9].n = "clear";
            __tmp____Bah_fnNames[9].p = clear;

            __tmp____Bah_fnNames[10].n = "memoryRealloc";
            __tmp____Bah_fnNames[10].p = memoryRealloc;

            __tmp____Bah_fnNames[11].n = "cleanShutDown";
            __tmp____Bah_fnNames[11].p = cleanShutDown;

            __tmp____Bah_fnNames[12].n = "memoryOnEnd";
            __tmp____Bah_fnNames[12].p = memoryOnEnd;

            __tmp____Bah_fnNames[13].n = "append";
            __tmp____Bah_fnNames[13].p = append;

            __tmp____Bah_fnNames[14].n = "copy";
            __tmp____Bah_fnNames[14].p = copy;

            __tmp____Bah_fnNames[15].n = "sharedMemory";
            __tmp____Bah_fnNames[15].p = sharedMemory;

            __tmp____Bah_fnNames[16].n = "allocateArray";
            __tmp____Bah_fnNames[16].p = allocateArray;

            __tmp____Bah_fnNames[17].n = "__serialize";
            __tmp____Bah_fnNames[17].p = __serialize;

            __tmp____Bah_fnNames[18].n = "serlen";
            __tmp____Bah_fnNames[18].p = serlen;

            __tmp____Bah_fnNames[19].n = "unser";
            __tmp____Bah_fnNames[19].p = unser;

            __tmp____Bah_fnNames[20].n = "memoryAllocSTR";
            __tmp____Bah_fnNames[20].p = memoryAllocSTR;

            __tmp____Bah_fnNames[21].n = "delete";
            __tmp____Bah_fnNames[21].p = delete;

            __tmp____Bah_fnNames[22].n = "deleteRange";
            __tmp____Bah_fnNames[22].p = deleteRange;

            __tmp____Bah_fnNames[23].n = "arrToStr";
            __tmp____Bah_fnNames[23].p = arrToStr;

            __tmp____Bah_fnNames[24].n = "strToArr";
            __tmp____Bah_fnNames[24].p = strToArr;

            __tmp____Bah_fnNames[25].n = "arrAsStr";
            __tmp____Bah_fnNames[25].p = arrAsStr;

            __tmp____Bah_fnNames[26].n = "strAsArr";
            __tmp____Bah_fnNames[26].p = strAsArr;

            __tmp____Bah_fnNames[27].n = "strTrimLeft";
            __tmp____Bah_fnNames[27].p = strTrimLeft;

            __tmp____Bah_fnNames[28].n = "strTrimRight";
            __tmp____Bah_fnNames[28].p = strTrimRight;

            __tmp____Bah_fnNames[29].n = "__Bah_realocate_arr";
            __tmp____Bah_fnNames[29].p = __Bah_realocate_arr;

            __tmp____Bah_fnNames[30].n = "__Bah_multiple_concat";
            __tmp____Bah_fnNames[30].p = __Bah_multiple_concat;

            __tmp____Bah_fnNames[31].n = "concatCPSTRING";
            __tmp____Bah_fnNames[31].p = concatCPSTRING;

            __tmp____Bah_fnNames[32].n = "__STR";
            __tmp____Bah_fnNames[32].p = __STR;

            __tmp____Bah_fnNames[33].n = "cArr";
            __tmp____Bah_fnNames[33].p = cArr;

            __tmp____Bah_fnNames[34].n = "__checkString";
            __tmp____Bah_fnNames[34].p = __checkString;

            __tmp____Bah_fnNames[35].n = "mutex.init";
            __tmp____Bah_fnNames[35].p = mutex__init;

            __tmp____Bah_fnNames[36].n = "mutex.lock";
            __tmp____Bah_fnNames[36].p = mutex__lock;

            __tmp____Bah_fnNames[37].n = "mutex.unlock";
            __tmp____Bah_fnNames[37].p = mutex__unlock;

            __tmp____Bah_fnNames[38].n = "mutex.destroy";
            __tmp____Bah_fnNames[38].p = mutex__destroy;

            __tmp____Bah_fnNames[39].n = "mutexCondition.init";
            __tmp____Bah_fnNames[39].p = mutexCondition__init;

            __tmp____Bah_fnNames[40].n = "mutexCondition.wait";
            __tmp____Bah_fnNames[40].p = mutexCondition__wait;

            __tmp____Bah_fnNames[41].n = "mutexCondition.send";
            __tmp____Bah_fnNames[41].p = mutexCondition__send;

            __tmp____Bah_fnNames[42].n = "mutexCondition.destroy";
            __tmp____Bah_fnNames[42].p = mutexCondition__destroy;

            __tmp____Bah_fnNames[43].n = "mutexCondition";
            __tmp____Bah_fnNames[43].p = mutexCondition;

            __tmp____Bah_fnNames[44].n = "thread.create";
            __tmp____Bah_fnNames[44].p = thread__create;

            __tmp____Bah_fnNames[45].n = "thread.createWithArg";
            __tmp____Bah_fnNames[45].p = thread__createWithArg;

            __tmp____Bah_fnNames[46].n = "thread.wait";
            __tmp____Bah_fnNames[46].p = thread__wait;

            __tmp____Bah_fnNames[47].n = "mutex";
            __tmp____Bah_fnNames[47].p = mutex;

            __tmp____Bah_fnNames[48].n = "queue.insert";
            __tmp____Bah_fnNames[48].p = queue__insert;

            __tmp____Bah_fnNames[49].n = "queue.delete";
            __tmp____Bah_fnNames[49].p = queue__delete;

            __tmp____Bah_fnNames[50].n = "queue.get";
            __tmp____Bah_fnNames[50].p = queue__get;

            __tmp____Bah_fnNames[51].n = "queue.set";
            __tmp____Bah_fnNames[51].p = queue__set;

            __tmp____Bah_fnNames[52].n = "queue.pop";
            __tmp____Bah_fnNames[52].p = queue__pop;

            __tmp____Bah_fnNames[53].n = "queue.clear";
            __tmp____Bah_fnNames[53].p = queue__clear;

            __tmp____Bah_fnNames[54].n = "channel.send";
            __tmp____Bah_fnNames[54].p = channel__send;

            __tmp____Bah_fnNames[55].n = "channel.sendAny";
            __tmp____Bah_fnNames[55].p = channel__sendAny;

            __tmp____Bah_fnNames[56].n = "channel.receive";
            __tmp____Bah_fnNames[56].p = channel__receive;

            __tmp____Bah_fnNames[57].n = "channel.destroy";
            __tmp____Bah_fnNames[57].p = channel__destroy;

            __tmp____Bah_fnNames[58].n = "channel.len";
            __tmp____Bah_fnNames[58].p = channel__len;

            __tmp____Bah_fnNames[59].n = "channel";
            __tmp____Bah_fnNames[59].p = channel;

            __tmp____Bah_fnNames[60].n = "setChanCap";
            __tmp____Bah_fnNames[60].p = setChanCap;

            __tmp____Bah_fnNames[61].n = "__Bah_common_panic";
            __tmp____Bah_fnNames[61].p = __Bah_common_panic;

            __tmp____Bah_fnNames[62].n = "__Bah_fnNames_append";
            __tmp____Bah_fnNames[62].p = __Bah_fnNames_append;

            __tmp____Bah_fnNames[63].n = "__Bah_segfault_handle";
            __tmp____Bah_fnNames[63].p = __Bah_segfault_handle;

            __tmp____Bah_fnNames[64].n = "__Bah_init_segfaultHandle";
            __tmp____Bah_fnNames[64].p = __Bah_init_segfaultHandle;

            __tmp____Bah_fnNames[65].n = "recover";
            __tmp____Bah_fnNames[65].p = recover;

            __tmp____Bah_fnNames[66].n = "cpstringCharAt";
            __tmp____Bah_fnNames[66].p = cpstringCharAt;

            __tmp____Bah_fnNames[67].n = "cpstringSubsitute";
            __tmp____Bah_fnNames[67].p = cpstringSubsitute;

            __tmp____Bah_fnNames[68].n = "arraySubstitute";
            __tmp____Bah_fnNames[68].p = arraySubstitute;

            __tmp____Bah_fnNames[69].n = "__Bah_map_hash";
            __tmp____Bah_fnNames[69].p = __Bah_map_hash;

            __tmp____Bah_fnNames[70].n = "mapWrapper.grow";
            __tmp____Bah_fnNames[70].p = mapWrapper__grow;

            __tmp____Bah_fnNames[71].n = "mapWrapper.set";
            __tmp____Bah_fnNames[71].p = mapWrapper__set;

            __tmp____Bah_fnNames[72].n = "mapWrapper.setAny";
            __tmp____Bah_fnNames[72].p = mapWrapper__setAny;

            __tmp____Bah_fnNames[73].n = "mapWrapper.delete";
            __tmp____Bah_fnNames[73].p = mapWrapper__delete;

            __tmp____Bah_fnNames[74].n = "mapWrapper.get";
            __tmp____Bah_fnNames[74].p = mapWrapper__get;

            __tmp____Bah_fnNames[75].n = "mapWrapper";
            __tmp____Bah_fnNames[75].p = mapWrapper;

            __tmp____Bah_fnNames[76].n = "stdinput";
            __tmp____Bah_fnNames[76].p = stdinput;

            __tmp____Bah_fnNames[77].n = "println";
            __tmp____Bah_fnNames[77].p = println;

            __tmp____Bah_fnNames[78].n = "fileStream.isValid";
            __tmp____Bah_fnNames[78].p = fileStream__isValid;

            __tmp____Bah_fnNames[79].n = "fileStream.open";
            __tmp____Bah_fnNames[79].p = fileStream__open;

            __tmp____Bah_fnNames[80].n = "fileStream.close";
            __tmp____Bah_fnNames[80].p = fileStream__close;

            __tmp____Bah_fnNames[81].n = "fileStream.getPos";
            __tmp____Bah_fnNames[81].p = fileStream__getPos;

            __tmp____Bah_fnNames[82].n = "fileStream.setPos";
            __tmp____Bah_fnNames[82].p = fileStream__setPos;

            __tmp____Bah_fnNames[83].n = "fileStream.getSize";
            __tmp____Bah_fnNames[83].p = fileStream__getSize;

            __tmp____Bah_fnNames[84].n = "fileStream.rewind";
            __tmp____Bah_fnNames[84].p = fileStream__rewind;

            __tmp____Bah_fnNames[85].n = "fileStream.getChar";
            __tmp____Bah_fnNames[85].p = fileStream__getChar;

            __tmp____Bah_fnNames[86].n = "fileStream.setChar";
            __tmp____Bah_fnNames[86].p = fileStream__setChar;

            __tmp____Bah_fnNames[87].n = "fileStream.createFile";
            __tmp____Bah_fnNames[87].p = fileStream__createFile;

            __tmp____Bah_fnNames[88].n = "fileStream.writeFile";
            __tmp____Bah_fnNames[88].p = fileStream__writeFile;

            __tmp____Bah_fnNames[89].n = "fileStream.writePtr";
            __tmp____Bah_fnNames[89].p = fileStream__writePtr;

            __tmp____Bah_fnNames[90].n = "fileStream.readPtr";
            __tmp____Bah_fnNames[90].p = fileStream__readPtr;

            __tmp____Bah_fnNames[91].n = "fileStream.readContent";
            __tmp____Bah_fnNames[91].p = fileStream__readContent;

            __tmp____Bah_fnNames[92].n = "fileStream.readBytes";
            __tmp____Bah_fnNames[92].p = fileStream__readBytes;

            __tmp____Bah_fnNames[93].n = "fileStream.writeBytes";
            __tmp____Bah_fnNames[93].p = fileStream__writeBytes;

            __tmp____Bah_fnNames[94].n = "fileStream._end";
            __tmp____Bah_fnNames[94].p = fileStream___end;

            __tmp____Bah_fnNames[95].n = "fileMap.open";
            __tmp____Bah_fnNames[95].p = fileMap__open;

            __tmp____Bah_fnNames[96].n = "fileMap.isValid";
            __tmp____Bah_fnNames[96].p = fileMap__isValid;

            __tmp____Bah_fnNames[97].n = "fileMap.close";
            __tmp____Bah_fnNames[97].p = fileMap__close;

            __tmp____Bah_fnNames[98].n = "listFiles";
            __tmp____Bah_fnNames[98].p = listFiles;

            __tmp____Bah_fnNames[99].n = "fileExists";
            __tmp____Bah_fnNames[99].p = fileExists;

            __tmp____Bah_fnNames[100].n = "isFolder";
            __tmp____Bah_fnNames[100].p = isFolder;

            __tmp____Bah_fnNames[101].n = "removeFile";
            __tmp____Bah_fnNames[101].p = removeFile;

            __tmp____Bah_fnNames[102].n = "getLastModified";
            __tmp____Bah_fnNames[102].p = getLastModified;

            __tmp____Bah_fnNames[103].n = "strCatOffset";
            __tmp____Bah_fnNames[103].p = strCatOffset;

            __tmp____Bah_fnNames[104].n = "charToString";
            __tmp____Bah_fnNames[104].p = charToString;

            __tmp____Bah_fnNames[105].n = "isUpper";
            __tmp____Bah_fnNames[105].p = isUpper;

            __tmp____Bah_fnNames[106].n = "isLower";
            __tmp____Bah_fnNames[106].p = isLower;

            __tmp____Bah_fnNames[107].n = "isLetter";
            __tmp____Bah_fnNames[107].p = isLetter;

            __tmp____Bah_fnNames[108].n = "isNumber";
            __tmp____Bah_fnNames[108].p = isNumber;

            __tmp____Bah_fnNames[109].n = "isAlphaNumeric";
            __tmp____Bah_fnNames[109].p = isAlphaNumeric;

            __tmp____Bah_fnNames[110].n = "isSpace";
            __tmp____Bah_fnNames[110].p = isSpace;

            __tmp____Bah_fnNames[111].n = "string.set";
            __tmp____Bah_fnNames[111].p = string__set;

            __tmp____Bah_fnNames[112].n = "string.makeEditable";
            __tmp____Bah_fnNames[112].p = string__makeEditable;

            __tmp____Bah_fnNames[113].n = "string.append";
            __tmp____Bah_fnNames[113].p = string__append;

            __tmp____Bah_fnNames[114].n = "string.prepend";
            __tmp____Bah_fnNames[114].p = string__prepend;

            __tmp____Bah_fnNames[115].n = "string.charAt";
            __tmp____Bah_fnNames[115].p = string__charAt;

            __tmp____Bah_fnNames[116].n = "string.compare";
            __tmp____Bah_fnNames[116].p = string__compare;

            __tmp____Bah_fnNames[117].n = "string.str";
            __tmp____Bah_fnNames[117].p = string__str;

            __tmp____Bah_fnNames[118].n = "string.replace";
            __tmp____Bah_fnNames[118].p = string__replace;

            __tmp____Bah_fnNames[119].n = "string.countChar";
            __tmp____Bah_fnNames[119].p = string__countChar;

            __tmp____Bah_fnNames[120].n = "string.count";
            __tmp____Bah_fnNames[120].p = string__count;

            __tmp____Bah_fnNames[121].n = "string.hasPrefix";
            __tmp____Bah_fnNames[121].p = string__hasPrefix;

            __tmp____Bah_fnNames[122].n = "string.hasSuffix";
            __tmp____Bah_fnNames[122].p = string__hasSuffix;

            __tmp____Bah_fnNames[123].n = "string.trim";
            __tmp____Bah_fnNames[123].p = string__trim;

            __tmp____Bah_fnNames[124].n = "string.trimLeft";
            __tmp____Bah_fnNames[124].p = string__trimLeft;

            __tmp____Bah_fnNames[125].n = "string.trimRight";
            __tmp____Bah_fnNames[125].p = string__trimRight;

            __tmp____Bah_fnNames[126].n = "string.add";
            __tmp____Bah_fnNames[126].p = string__add;

            __tmp____Bah_fnNames[127].n = "string.asArr";
            __tmp____Bah_fnNames[127].p = string__asArr;

            __tmp____Bah_fnNames[128].n = "string";
            __tmp____Bah_fnNames[128].p = string;

            __tmp____Bah_fnNames[129].n = "intToStr";
            __tmp____Bah_fnNames[129].p = intToStr;

            __tmp____Bah_fnNames[130].n = "intToString";
            __tmp____Bah_fnNames[130].p = intToString;

            __tmp____Bah_fnNames[131].n = "floatToStr";
            __tmp____Bah_fnNames[131].p = floatToStr;

            __tmp____Bah_fnNames[132].n = "strToInt";
            __tmp____Bah_fnNames[132].p = strToInt;

            __tmp____Bah_fnNames[133].n = "strToFloat";
            __tmp____Bah_fnNames[133].p = strToFloat;

            __tmp____Bah_fnNames[134].n = "stringToInt";
            __tmp____Bah_fnNames[134].p = stringToInt;

            __tmp____Bah_fnNames[135].n = "splitString";
            __tmp____Bah_fnNames[135].p = splitString;

            __tmp____Bah_fnNames[136].n = "joinString";
            __tmp____Bah_fnNames[136].p = joinString;

            __tmp____Bah_fnNames[137].n = "splitStringBefore";
            __tmp____Bah_fnNames[137].p = splitStringBefore;

            __tmp____Bah_fnNames[138].n = "toLower";
            __tmp____Bah_fnNames[138].p = toLower;

            __tmp____Bah_fnNames[139].n = "strHasPrefix";
            __tmp____Bah_fnNames[139].p = strHasPrefix;

            __tmp____Bah_fnNames[140].n = "strHasSuffix";
            __tmp____Bah_fnNames[140].p = strHasSuffix;

            __tmp____Bah_fnNames[141].n = "strTrim";
            __tmp____Bah_fnNames[141].p = strTrim;

            __tmp____Bah_fnNames[142].n = "strCount";
            __tmp____Bah_fnNames[142].p = strCount;

            __tmp____Bah_fnNames[143].n = "flags.addString";
            __tmp____Bah_fnNames[143].p = flags__addString;

            __tmp____Bah_fnNames[144].n = "flags.addBool";
            __tmp____Bah_fnNames[144].p = flags__addBool;

            __tmp____Bah_fnNames[145].n = "flags.addInt";
            __tmp____Bah_fnNames[145].p = flags__addInt;

            __tmp____Bah_fnNames[146].n = "flags.addFloat";
            __tmp____Bah_fnNames[146].p = flags__addFloat;

            __tmp____Bah_fnNames[147].n = "flags.invalidate";
            __tmp____Bah_fnNames[147].p = flags__invalidate;

            __tmp____Bah_fnNames[148].n = "flags.getFlag";
            __tmp____Bah_fnNames[148].p = flags__getFlag;

            __tmp____Bah_fnNames[149].n = "flags.get";
            __tmp____Bah_fnNames[149].p = flags__get;

            __tmp____Bah_fnNames[150].n = "flags.getInt";
            __tmp____Bah_fnNames[150].p = flags__getInt;

            __tmp____Bah_fnNames[151].n = "flags.getFloat";
            __tmp____Bah_fnNames[151].p = flags__getFloat;

            __tmp____Bah_fnNames[152].n = "flags.isSet";
            __tmp____Bah_fnNames[152].p = flags__isSet;

            __tmp____Bah_fnNames[153].n = "flags.parse";
            __tmp____Bah_fnNames[153].p = flags__parse;

            __tmp____Bah_fnNames[154].n = "time.now";
            __tmp____Bah_fnNames[154].p = time__now;

            __tmp____Bah_fnNames[155].n = "time.format";
            __tmp____Bah_fnNames[155].p = time__format;

            __tmp____Bah_fnNames[156].n = "time.since";
            __tmp____Bah_fnNames[156].p = time__since;

            __tmp____Bah_fnNames[157].n = "getTimeUnix";
            __tmp____Bah_fnNames[157].p = getTimeUnix;

            __tmp____Bah_fnNames[158].n = "seedRandom";
            __tmp____Bah_fnNames[158].p = seedRandom;

            __tmp____Bah_fnNames[159].n = "randomInRange";
            __tmp____Bah_fnNames[159].p = randomInRange;

            __tmp____Bah_fnNames[160].n = "cryptoRand";
            __tmp____Bah_fnNames[160].p = cryptoRand;

            __tmp____Bah_fnNames[161].n = "rope.addStr";
            __tmp____Bah_fnNames[161].p = rope__addStr;

            __tmp____Bah_fnNames[162].n = "rope.toStr";
            __tmp____Bah_fnNames[162].p = rope__toStr;

            __tmp____Bah_fnNames[163].n = "rope.add";
            __tmp____Bah_fnNames[163].p = rope__add;

            __tmp____Bah_fnNames[164].n = "createRopeStructure";
            __tmp____Bah_fnNames[164].p = createRopeStructure;

            __tmp____Bah_fnNames[165].n = "ropeSet";
            __tmp____Bah_fnNames[165].p = ropeSet;

            __tmp____Bah_fnNames[166].n = "concatenateRopes";
            __tmp____Bah_fnNames[166].p = concatenateRopes;

            __tmp____Bah_fnNames[167].n = "rope";
            __tmp____Bah_fnNames[167].p = rope;

            __tmp____Bah_fnNames[168].n = "command.run";
            __tmp____Bah_fnNames[168].p = command__run;

            __tmp____Bah_fnNames[169].n = "command.runBytes";
            __tmp____Bah_fnNames[169].p = command__runBytes;

            __tmp____Bah_fnNames[170].n = "command";
            __tmp____Bah_fnNames[170].p = command;

            __tmp____Bah_fnNames[171].n = "exec";
            __tmp____Bah_fnNames[171].p = exec;

            __tmp____Bah_fnNames[172].n = "inArray";
            __tmp____Bah_fnNames[172].p = inArray;

            __tmp____Bah_fnNames[173].n = "inArrayStr";
            __tmp____Bah_fnNames[173].p = inArrayStr;

            __tmp____Bah_fnNames[174].n = "makeToken";
            __tmp____Bah_fnNames[174].p = makeToken;

            __tmp____Bah_fnNames[175].n = "isMinus";
            __tmp____Bah_fnNames[175].p = isMinus;

            __tmp____Bah_fnNames[176].n = "lexerErr";
            __tmp____Bah_fnNames[176].p = lexerErr;

            __tmp____Bah_fnNames[177].n = "lexer";
            __tmp____Bah_fnNames[177].p = lexer;

            __tmp____Bah_fnNames[178].n = "hasStructSep";
            __tmp____Bah_fnNames[178].p = hasStructSep;

            __tmp____Bah_fnNames[179].n = "splitStructSepBefore";
            __tmp____Bah_fnNames[179].p = splitStructSepBefore;

            __tmp____Bah_fnNames[180].n = "splitStructSepAfter";
            __tmp____Bah_fnNames[180].p = splitStructSepAfter;

            __tmp____Bah_fnNames[181].n = "searchStruct";
            __tmp____Bah_fnNames[181].p = searchStruct;

            __tmp____Bah_fnNames[182].n = "searchStructMemb";
            __tmp____Bah_fnNames[182].p = searchStructMemb;

            __tmp____Bah_fnNames[183].n = "searchFunc";
            __tmp____Bah_fnNames[183].p = searchFunc;

            __tmp____Bah_fnNames[184].n = "parseFnType";
            __tmp____Bah_fnNames[184].p = parseFnType;

            __tmp____Bah_fnNames[185].n = "searchStructMethod";
            __tmp____Bah_fnNames[185].p = searchStructMethod;

            __tmp____Bah_fnNames[186].n = "typeAsStar";
            __tmp____Bah_fnNames[186].p = typeAsStar;

            __tmp____Bah_fnNames[187].n = "isRCPpointerType";
            __tmp____Bah_fnNames[187].p = isRCPpointerType;

            __tmp____Bah_fnNames[188].n = "isRCPtype";
            __tmp____Bah_fnNames[188].p = isRCPtype;

            __tmp____Bah_fnNames[189].n = "getCType";
            __tmp____Bah_fnNames[189].p = getCType;

            __tmp____Bah_fnNames[190].n = "maybeToPtr";
            __tmp____Bah_fnNames[190].p = maybeToPtr;

            __tmp____Bah_fnNames[191].n = "compTypeEquiv";
            __tmp____Bah_fnNames[191].p = compTypeEquiv;

            __tmp____Bah_fnNames[192].n = "compTypes";
            __tmp____Bah_fnNames[192].p = compTypes;

            __tmp____Bah_fnNames[193].n = "reflectElement.calculateOffset";
            __tmp____Bah_fnNames[193].p = reflectElement__calculateOffset;

            __tmp____Bah_fnNames[194].n = "__reflect";
            __tmp____Bah_fnNames[194].p = __reflect;

            __tmp____Bah_fnNames[195].n = "__dumpSymbols";
            __tmp____Bah_fnNames[195].p = __dumpSymbols;

            __tmp____Bah_fnNames[196].n = "__debug_get_sym";
            __tmp____Bah_fnNames[196].p = __debug_get_sym;

            __tmp____Bah_fnNames[197].n = "toJson";
            __tmp____Bah_fnNames[197].p = toJson;

            __tmp____Bah_fnNames[198].n = "json_scan_inner";
            __tmp____Bah_fnNames[198].p = json_scan_inner;

            __tmp____Bah_fnNames[199].n = "jsonElement.get";
            __tmp____Bah_fnNames[199].p = jsonElement__get;

            __tmp____Bah_fnNames[200].n = "jsonElement.str";
            __tmp____Bah_fnNames[200].p = jsonElement__str;

            __tmp____Bah_fnNames[201].n = "jsonElement.scan";
            __tmp____Bah_fnNames[201].p = jsonElement__scan;

            __tmp____Bah_fnNames[202].n = "parseJson";
            __tmp____Bah_fnNames[202].p = parseJson;

            __tmp____Bah_fnNames[203].n = "json_isPrintable";
            __tmp____Bah_fnNames[203].p = json_isPrintable;

            __tmp____Bah_fnNames[204].n = "jsonEscapeStr";
            __tmp____Bah_fnNames[204].p = jsonEscapeStr;

            __tmp____Bah_fnNames[205].n = "toJson__inner";
            __tmp____Bah_fnNames[205].p = toJson__inner;

            __tmp____Bah_fnNames[206].n = "debugStart";
            __tmp____Bah_fnNames[206].p = debugStart;

            __tmp____Bah_fnNames[207].n = "debugPrint";
            __tmp____Bah_fnNames[207].p = debugPrint;

            __tmp____Bah_fnNames[208].n = "debugError";
            __tmp____Bah_fnNames[208].p = debugError;

            __tmp____Bah_fnNames[209].n = "debugEnd";
            __tmp____Bah_fnNames[209].p = debugEnd;

            __tmp____Bah_fnNames[210].n = "debugExit";
            __tmp____Bah_fnNames[210].p = debugExit;

            __tmp____Bah_fnNames[211].n = "debugEndScope";
            __tmp____Bah_fnNames[211].p = debugEndScope;

            __tmp____Bah_fnNames[212].n = "throwErr";
            __tmp____Bah_fnNames[212].p = throwErr;

            __tmp____Bah_fnNames[213].n = "throwWarning";
            __tmp____Bah_fnNames[213].p = throwWarning;

            __tmp____Bah_fnNames[214].n = "throwWarningLine";
            __tmp____Bah_fnNames[214].p = throwWarningLine;

            __tmp____Bah_fnNames[215].n = "throwNoticeLine";
            __tmp____Bah_fnNames[215].p = throwNoticeLine;

            __tmp____Bah_fnNames[216].n = "absPath";
            __tmp____Bah_fnNames[216].p = absPath;

            __tmp____Bah_fnNames[217].n = "getCurrentPath";
            __tmp____Bah_fnNames[217].p = getCurrentPath;

            __tmp____Bah_fnNames[218].n = "isInside";
            __tmp____Bah_fnNames[218].p = isInside;

            __tmp____Bah_fnNames[219].n = "setCurrentPath";
            __tmp____Bah_fnNames[219].p = setCurrentPath;

            __tmp____Bah_fnNames[220].n = "isGlobal";
            __tmp____Bah_fnNames[220].p = isGlobal;

            __tmp____Bah_fnNames[221].n = "getRealVar";
            __tmp____Bah_fnNames[221].p = getRealVar;

            __tmp____Bah_fnNames[222].n = "removeVarUnar";
            __tmp____Bah_fnNames[222].p = removeVarUnar;

            __tmp____Bah_fnNames[223].n = "searchVar";
            __tmp____Bah_fnNames[223].p = searchVar;

            __tmp____Bah_fnNames[224].n = "searchVarByToken";
            __tmp____Bah_fnNames[224].p = searchVarByToken;

            __tmp____Bah_fnNames[225].n = "searchVirtVarByToken";
            __tmp____Bah_fnNames[225].p = searchVirtVarByToken;

            __tmp____Bah_fnNames[226].n = "setCType";
            __tmp____Bah_fnNames[226].p = setCType;

            __tmp____Bah_fnNames[227].n = "getTypeFromToken";
            __tmp____Bah_fnNames[227].p = getTypeFromToken;

            __tmp____Bah_fnNames[228].n = "searchFuncByToken";
            __tmp____Bah_fnNames[228].p = searchFuncByToken;

            __tmp____Bah_fnNames[229].n = "RCPavailable";
            __tmp____Bah_fnNames[229].p = RCPavailable;

            __tmp____Bah_fnNames[230].n = "declareStructMethods";
            __tmp____Bah_fnNames[230].p = declareStructMethods;

            __tmp____Bah_fnNames[231].n = "genCompilerVar";
            __tmp____Bah_fnNames[231].p = genCompilerVar;

            __tmp____Bah_fnNames[232].n = "varInArr";
            __tmp____Bah_fnNames[232].p = varInArr;

            __tmp____Bah_fnNames[233].n = "pathToVarName";
            __tmp____Bah_fnNames[233].p = pathToVarName;

            __tmp____Bah_fnNames[234].n = "makeInit";
            __tmp____Bah_fnNames[234].p = makeInit;

            __tmp____Bah_fnNames[235].n = "checkedNull";
            __tmp____Bah_fnNames[235].p = checkedNull;

            __tmp____Bah_fnNames[236].n = "checkedNotNull";
            __tmp____Bah_fnNames[236].p = checkedNotNull;

            __tmp____Bah_fnNames[237].n = "canChangeNullState";
            __tmp____Bah_fnNames[237].p = canChangeNullState;

            __tmp____Bah_fnNames[238].n = "isOutterScope";
            __tmp____Bah_fnNames[238].p = isOutterScope;

            __tmp____Bah_fnNames[239].n = "decrVar";
            __tmp____Bah_fnNames[239].p = decrVar;

            __tmp____Bah_fnNames[240].n = "incrVar";
            __tmp____Bah_fnNames[240].p = incrVar;

            __tmp____Bah_fnNames[241].n = "beginRCPscope";
            __tmp____Bah_fnNames[241].p = beginRCPscope;

            __tmp____Bah_fnNames[242].n = "beginRCPscopeLeaky";
            __tmp____Bah_fnNames[242].p = beginRCPscopeLeaky;

            __tmp____Bah_fnNames[243].n = "removeDefs";
            __tmp____Bah_fnNames[243].p = removeDefs;

            __tmp____Bah_fnNames[244].n = "endRCPscope";
            __tmp____Bah_fnNames[244].p = endRCPscope;

            __tmp____Bah_fnNames[245].n = "endRCPscopeLeaky";
            __tmp____Bah_fnNames[245].p = endRCPscopeLeaky;

            __tmp____Bah_fnNames[246].n = "registerRCPvar";
            __tmp____Bah_fnNames[246].p = registerRCPvar;

            __tmp____Bah_fnNames[247].n = "RCPselfRef";
            __tmp____Bah_fnNames[247].p = RCPselfRef;

            __tmp____Bah_fnNames[248].n = "verboseOutGuard";
            __tmp____Bah_fnNames[248].p = verboseOutGuard;

            __tmp____Bah_fnNames[249].n = "verboseOutTransformVar";
            __tmp____Bah_fnNames[249].p = verboseOutTransformVar;

            __tmp____Bah_fnNames[250].n = "verboseOutTransformTok";
            __tmp____Bah_fnNames[250].p = verboseOutTransformTok;

            __tmp____Bah_fnNames[251].n = "verboseOutFunc";
            __tmp____Bah_fnNames[251].p = verboseOutFunc;

            __tmp____Bah_fnNames[252].n = "verboseOutOper";
            __tmp____Bah_fnNames[252].p = verboseOutOper;

            __tmp____Bah_fnNames[253].n = "readCache";
            __tmp____Bah_fnNames[253].p = readCache;

            __tmp____Bah_fnNames[254].n = "getCacheFile";
            __tmp____Bah_fnNames[254].p = getCacheFile;

            __tmp____Bah_fnNames[255].n = "updateCacheFile";
            __tmp____Bah_fnNames[255].p = updateCacheFile;

            __tmp____Bah_fnNames[256].n = "makeCacheFile";
            __tmp____Bah_fnNames[256].p = makeCacheFile;

            __tmp____Bah_fnNames[257].n = "writeCache";
            __tmp____Bah_fnNames[257].p = writeCache;

            __tmp____Bah_fnNames[258].n = "isValidCacheFile";
            __tmp____Bah_fnNames[258].p = isValidCacheFile;

            __tmp____Bah_fnNames[259].n = "genArrRealloc";
            __tmp____Bah_fnNames[259].p = genArrRealloc;

            __tmp____Bah_fnNames[260].n = "genConcat";
            __tmp____Bah_fnNames[260].p = genConcat;

            __tmp____Bah_fnNames[261].n = "OPTI_checkFuncScopeRef";
            __tmp____Bah_fnNames[261].p = OPTI_checkFuncScopeRef;

            __tmp____Bah_fnNames[262].n = "debugLine";
            __tmp____Bah_fnNames[262].p = debugLine;

            __tmp____Bah_fnNames[263].n = "dupElems";
            __tmp____Bah_fnNames[263].p = dupElems;

            __tmp____Bah_fnNames[264].n = "checkCanBeNull";
            __tmp____Bah_fnNames[264].p = checkCanBeNull;

            __tmp____Bah_fnNames[265].n = "setNullStateBranchFlowEnd";
            __tmp____Bah_fnNames[265].p = setNullStateBranchFlowEnd;

            __tmp____Bah_fnNames[266].n = "getLineType";
            __tmp____Bah_fnNames[266].p = getLineType;

            __tmp____Bah_fnNames[267].n = "parseCast";
            __tmp____Bah_fnNames[267].p = parseCast;

            __tmp____Bah_fnNames[268].n = "getDirFromFile";
            __tmp____Bah_fnNames[268].p = getDirFromFile;

            __tmp____Bah_fnNames[269].n = "parseLines";
            __tmp____Bah_fnNames[269].p = parseLines;

            __tmp____Bah_fnNames[270].n = "includeFile";
            __tmp____Bah_fnNames[270].p = includeFile;

            __tmp____Bah_fnNames[271].n = "parallelObjCompile";
            __tmp____Bah_fnNames[271].p = parallelObjCompile;

            __tmp____Bah_fnNames[272].n = "parseImport";
            __tmp____Bah_fnNames[272].p = parseImport;

            __tmp____Bah_fnNames[273].n = "parseInclude";
            __tmp____Bah_fnNames[273].p = parseInclude;

            __tmp____Bah_fnNames[274].n = "prePross";
            __tmp____Bah_fnNames[274].p = prePross;

            __tmp____Bah_fnNames[275].n = "parseStructType";
            __tmp____Bah_fnNames[275].p = parseStructType;

            __tmp____Bah_fnNames[276].n = "parseArrayType";
            __tmp____Bah_fnNames[276].p = parseArrayType;

            __tmp____Bah_fnNames[277].n = "parsePointers";
            __tmp____Bah_fnNames[277].p = parsePointers;

            __tmp____Bah_fnNames[278].n = "parseSerialize";
            __tmp____Bah_fnNames[278].p = parseSerialize;

            __tmp____Bah_fnNames[279].n = "parseReflect";
            __tmp____Bah_fnNames[279].p = parseReflect;

            __tmp____Bah_fnNames[280].n = "parseArrayDecl";
            __tmp____Bah_fnNames[280].p = parseArrayDecl;

            __tmp____Bah_fnNames[281].n = "parseVar";
            __tmp____Bah_fnNames[281].p = parseVar;

            __tmp____Bah_fnNames[282].n = "getCfunctionType";
            __tmp____Bah_fnNames[282].p = getCfunctionType;

            __tmp____Bah_fnNames[283].n = "parseFnHeader";
            __tmp____Bah_fnNames[283].p = parseFnHeader;

            __tmp____Bah_fnNames[284].n = "parseStruct";
            __tmp____Bah_fnNames[284].p = parseStruct;

            __tmp____Bah_fnNames[285].n = "parseDefine";
            __tmp____Bah_fnNames[285].p = parseDefine;

            __tmp____Bah_fnNames[286].n = "parseClib";
            __tmp____Bah_fnNames[286].p = parseClib;

            __tmp____Bah_fnNames[287].n = "parseConst";
            __tmp____Bah_fnNames[287].p = parseConst;

            __tmp____Bah_fnNames[288].n = "parseReturn";
            __tmp____Bah_fnNames[288].p = parseReturn;

            __tmp____Bah_fnNames[289].n = "parseIf";
            __tmp____Bah_fnNames[289].p = parseIf;

            __tmp____Bah_fnNames[290].n = "parseElse";
            __tmp____Bah_fnNames[290].p = parseElse;

            __tmp____Bah_fnNames[291].n = "parseLine";
            __tmp____Bah_fnNames[291].p = parseLine;

            __tmp____Bah_fnNames[292].n = "parseFor";
            __tmp____Bah_fnNames[292].p = parseFor;

            __tmp____Bah_fnNames[293].n = "parseForOp";
            __tmp____Bah_fnNames[293].p = parseForOp;

            __tmp____Bah_fnNames[294].n = "makeEvalFunc";
            __tmp____Bah_fnNames[294].p = makeEvalFunc;

            __tmp____Bah_fnNames[295].n = "parsePreKeyword";
            __tmp____Bah_fnNames[295].p = parsePreKeyword;

            __tmp____Bah_fnNames[296].n = "parseAsync";
            __tmp____Bah_fnNames[296].p = parseAsync;

            __tmp____Bah_fnNames[297].n = "addRCPvars";
            __tmp____Bah_fnNames[297].p = addRCPvars;

            __tmp____Bah_fnNames[298].n = "parseChan";
            __tmp____Bah_fnNames[298].p = parseChan;

            __tmp____Bah_fnNames[299].n = "valueFunc";
            __tmp____Bah_fnNames[299].p = valueFunc;

            __tmp____Bah_fnNames[300].n = "valueStruct";
            __tmp____Bah_fnNames[300].p = valueStruct;

            __tmp____Bah_fnNames[301].n = "valueArr";
            __tmp____Bah_fnNames[301].p = valueArr;

            __tmp____Bah_fnNames[302].n = "valueBool";
            __tmp____Bah_fnNames[302].p = valueBool;

            __tmp____Bah_fnNames[303].n = "valueOper";
            __tmp____Bah_fnNames[303].p = valueOper;

            __tmp____Bah_fnNames[304].n = "valueSendChan";
            __tmp____Bah_fnNames[304].p = valueSendChan;

            __tmp____Bah_fnNames[305].n = "valueChan";
            __tmp____Bah_fnNames[305].p = valueChan;

            __tmp____Bah_fnNames[306].n = "isSmallValue";
            __tmp____Bah_fnNames[306].p = isSmallValue;

            __tmp____Bah_fnNames[307].n = "isValue";
            __tmp____Bah_fnNames[307].p = isValue;

            __tmp____Bah_fnNames[308].n = "parseFnDeclare";
            __tmp____Bah_fnNames[308].p = parseFnDeclare;

            __tmp____Bah_fnNames[309].n = "parseCapture";
            __tmp____Bah_fnNames[309].p = parseCapture;

            __tmp____Bah_fnNames[310].n = "declareFunc";
            __tmp____Bah_fnNames[310].p = declareFunc;

            __tmp____Bah_fnNames[311].n = "declareVar";
            __tmp____Bah_fnNames[311].p = declareVar;

            __tmp____Bah_fnNames[312].n = "declareAll";
            __tmp____Bah_fnNames[312].p = declareAll;

            __tmp____Bah_fnNames[313].n = "memErrHandle";
            __tmp____Bah_fnNames[313].p = memErrHandle;

            __tmp____Bah_fnNames[314].n = "main";
            __tmp____Bah_fnNames[314].p = main;

        __Bah_fnNames->data = __tmp____Bah_fnNames;
        __Bah_fnNames->length = 315;
        
    };
    