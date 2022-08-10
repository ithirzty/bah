//COMPILE WITH: 'x86_64-w64-mingw32-gcc -I "/opt/bah/libs/windows/include/" -L "/opt/bah/libs/windows/" ../installer/windows.c -static -O1 -w  -l:gc.a -lpthread -lm'

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
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
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
#define PROT_READ 2
#define PROT_READWRITE 4
void * GLOBAL_MAPPED_MEMORY_FILE;
void * sharedMemory(long int size){
if ((size==0)) {
size = 4096;
}
if ((GLOBAL_MAPPED_MEMORY_FILE==null)) {
GLOBAL_MAPPED_MEMORY_FILE = CreateFileMapping(-1,0,PROT_READWRITE,0,size,"Global\\BahFileMap");
}
if (__builtin_expect((GLOBAL_MAPPED_MEMORY_FILE==null), 0)) {
printf("sharedMemory: could not make map file.");
exit(1);
}
void * r = MapViewOfFile(GLOBAL_MAPPED_MEMORY_FILE,FILE_MAP_ALL_ACCESS,0,0,size);
return r;
};
void closeSharedMemory(){
CloseHandle(GLOBAL_MAPPED_MEMORY_FILE);
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
if ((i>=length)+(i<0)) {
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
if (__builtin_expect(((void *)s==null), 0)) {
char** ____BAH_COMPILER_VAR_0 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_0[2] = ") is null \n";____BAH_COMPILER_VAR_0[1] = l;____BAH_COMPILER_VAR_0[0] = "cpstring (";char * ____BAH_COMPILER_VAR_1 =__Bah_multiple_concat(____BAH_COMPILER_VAR_0, 3);print(____BAH_COMPILER_VAR_1);
exit(1);
}
return true;
};
#include <pthread.h>
#define __thread_create pthread_create
#define __thread_join pthread_join
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
struct mutexCondition m = ____BAH_COMPILER_VAR_2;
mutexCondition__init(&m);
return m;
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
struct mutex m = ____BAH_COMPILER_VAR_3;
mutex__init(&m);
return m;
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
if (__builtin_expect(strlen(e), 0)) {
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
struct fileStream ____BAH_COMPILER_VAR_40 = {};
struct fileStream fs = ____BAH_COMPILER_VAR_40;
fileStream__open(&fs,fileName,"r+");
long int iv = fileStream__isValid(&fs);
if ((iv==1)) {
this->handle = 0;
}
else {
this->handle = -1;
}
char * file = fileStream__readContent(&fs);
fileStream__close(&fs);
return file;
};
long int fileMap__isValid(struct fileMap* this){
if ((this->handle<0)) {
return 0;
}
return 1;
};
void fileMap__close(struct fileMap* this){
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
long int __windows_mkdir(char * s,long int m){
return mkdir(s);
};
#define mkdir __windows_mkdir
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
return (c==(char)32)+(c==(char)9)+(c==(char)10)+(c==(char)11)+(c==(char)13);
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
if (__builtin_expect((nc==null), 0)) {
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
if (__builtin_expect((nc==null), 0)) {
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
struct string needle = ____BAH_COMPILER_VAR_42;
string__set(&needle,nd);
struct string ____BAH_COMPILER_VAR_43 = {};
struct string repl = ____BAH_COMPILER_VAR_43;
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
struct string needle = ____BAH_COMPILER_VAR_50;
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
struct string r = ____BAH_COMPILER_VAR_51;
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
struct string a = ____BAH_COMPILER_VAR_52;
string__set(&a,s);
return a;
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
if (__builtin_expect((flag->type!=FLAG_TYPE_INT), 0)) {
char** ____BAH_COMPILER_VAR_82 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_82[2] = "' is not int.";____BAH_COMPILER_VAR_82[1] = flag->name;____BAH_COMPILER_VAR_82[0] = "Flag '";char * ____BAH_COMPILER_VAR_83 =__Bah_multiple_concat(____BAH_COMPILER_VAR_82, 3);__BAH_panic(____BAH_COMPILER_VAR_83,"/opt/bah/flags.bah:122");
}
return flag->cont_int;
};
double flags__getFloat(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_84 =string(name);struct flag* flag = flags__getFlag(this,____BAH_COMPILER_VAR_84);
if (__builtin_expect((flag->type!=FLAG_TYPE_FLOAT), 0)) {
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
if (__builtin_expect(string__compare(&argName,"help"), 0)) {
flags__invalidate(this);
}
else if (__builtin_expect(string__compare(&argName,"h"), 0)) {
flags__invalidate(this);
}
currentFlag = flags__getFlag(this,argName);
if (__builtin_expect((currentFlag==null), 0)) {
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
if (__builtin_expect((currentFlag->type!=FLAG_TYPE_BOOL), 0)) {
flags__invalidate(this);
}
}
};
#include <stdlib.h>
#include <wincrypt.h>
#include <time.h>
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
struct timespec ts = ____BAH_COMPILER_VAR_90;
long int s = clock_gettime(CLOCK_REALTIME,&ts);
s = ts.tv_sec*1000000000+ts.tv_nsec;
return s;
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
HCRYPTPROV hp;
long int* buff = memoryAlloc(SIZE_OF_INT);
CryptGenRandom(hp,1,buff);
long int i = *buff;
return i;
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
struct rope* ____BAH_COMPILER_VAR_91 = memoryAlloc(sizeof(struct rope));
struct rope* tmp = ____BAH_COMPILER_VAR_91;
tmp->left = this;
tmp->right = root2;
tmp->totalLen = this->totalLen+root2->totalLen;
tmp->str = null;
return tmp;
};
struct rope* createRopeStructure(struct rope* par,char * a,long int l,long int r){
struct rope* ____BAH_COMPILER_VAR_92 = memoryAlloc(sizeof(struct rope));
struct rope* tmp = ____BAH_COMPILER_VAR_92;
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
struct rope* ____BAH_COMPILER_VAR_93 = memoryAlloc(sizeof(struct rope));
struct rope* tmp = ____BAH_COMPILER_VAR_93;
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
char** ____BAH_COMPILER_VAR_94 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_94[1] = " 2>/dev/null";____BAH_COMPILER_VAR_94[0] = cm;char * ____BAH_COMPILER_VAR_95 =__Bah_multiple_concat(____BAH_COMPILER_VAR_94, 2);cm = ____BAH_COMPILER_VAR_95;
}
else {
char** ____BAH_COMPILER_VAR_96 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_96[1] = " 2>&1";____BAH_COMPILER_VAR_96[0] = cm;char * ____BAH_COMPILER_VAR_97 =__Bah_multiple_concat(____BAH_COMPILER_VAR_96, 2);cm = ____BAH_COMPILER_VAR_97;
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
char** ____BAH_COMPILER_VAR_98 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_98[1] = buff;____BAH_COMPILER_VAR_98[0] = res;char * ____BAH_COMPILER_VAR_99 =__Bah_multiple_concat(____BAH_COMPILER_VAR_98, 2);res = ____BAH_COMPILER_VAR_99;
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
char** ____BAH_COMPILER_VAR_100 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_100[1] = " 2>/dev/null";____BAH_COMPILER_VAR_100[0] = cm;char * ____BAH_COMPILER_VAR_101 =__Bah_multiple_concat(____BAH_COMPILER_VAR_100, 2);cm = ____BAH_COMPILER_VAR_101;
}
else {
char** ____BAH_COMPILER_VAR_102 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_102[1] = " 2>&1";____BAH_COMPILER_VAR_102[0] = cm;char * ____BAH_COMPILER_VAR_103 =__Bah_multiple_concat(____BAH_COMPILER_VAR_102, 2);cm = ____BAH_COMPILER_VAR_103;
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
char** ____BAH_COMPILER_VAR_104 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_104[1] = buff;____BAH_COMPILER_VAR_104[0] = response;char * ____BAH_COMPILER_VAR_105 =__Bah_multiple_concat(____BAH_COMPILER_VAR_104, 2);response = ____BAH_COMPILER_VAR_105;
res = fgets(buff,1023,this->handle);
};
this->status = pclose(this->handle);
arr->data=response;
arr->length=strlen(response);
return arr;
};
struct command command(char * s){
struct command ____BAH_COMPILER_VAR_106 = {};
____BAH_COMPILER_VAR_106.error = true;
struct command cmd = ____BAH_COMPILER_VAR_106;
cmd.command = s;
return cmd;
};
long int exec(char * s,__BAH_ARR_TYPE_cpstring args){
long int r;
array(char *)* nArgs = memoryAlloc(sizeof(array(char *)));

nArgs->length = 0;
nArgs->elemSize = sizeof(char *);

    unsigned int ____BAH_COMPILER_VAR_107 = 0;
    __Bah_realocate_arr(nArgs, ____BAH_COMPILER_VAR_107);
    nArgs->data[____BAH_COMPILER_VAR_107] = s;
register long int i = 0;
while ((i<len(args))) {

    unsigned int ____BAH_COMPILER_VAR_108 = i+1;
    __Bah_realocate_arr(nArgs, ____BAH_COMPILER_VAR_108);
    nArgs->data[____BAH_COMPILER_VAR_108] = args->data[i];
i = i+1;
};

    unsigned int ____BAH_COMPILER_VAR_109 = i+2;
    __Bah_realocate_arr(nArgs, ____BAH_COMPILER_VAR_109);
    nArgs->data[____BAH_COMPILER_VAR_109] = (char *)0;
r=execvp(s,nArgs->data);
return r;
};
char * BAH_DIR;
char * BAH_OS;
char * BAH_CC;
#define BAH_VERSION "v1.2 (build 118)"
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
struct rope* postDeclHandle;
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
char couldAlreadyReturn;
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
struct Elems* parent;
unsigned int id;
array(struct varCheck)* branchChecks;
char currFlowEnd;
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
long int totalSize;
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
char isNotExpsvOper;
void * bahRef;
struct variable* parent;
char isExpensive;
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
struct Tok ____BAH_COMPILER_VAR_110 = {};
____BAH_COMPILER_VAR_110.cont = "";
____BAH_COMPILER_VAR_110.ogCont = "";
____BAH_COMPILER_VAR_110.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_110.line = 1;
____BAH_COMPILER_VAR_110.begLine = 1;
____BAH_COMPILER_VAR_110.bahType = "";
struct Tok t = ____BAH_COMPILER_VAR_110;
t.cont = arrToStr(cont);
t.ogCont = t.cont;
clear(cont);
t.pos = pos;
t.line = lineNb;
t.type = type;
if ((type==TOKEN_TYPE_INT)+(type==TOKEN_TYPE_STR)+(type==TOKEN_TYPE_FLOAT)+(type==TOKEN_TYPE_VAR)+(type==TOKEN_TYPE_BOOL)+(type==TOKEN_TYPE_CHAR)) {
t.isValue = true;
}
return t;
};
char isMinus(char c,char nc){
return (c==45)&&isNumber(nc);
};
void lexerErr(long int line,long int pos,char * msg){
char * lineStr = intToStr(line);
char * posStr = intToStr(pos);
char** ____BAH_COMPILER_VAR_111 = alloca(8 * sizeof(char*));____BAH_COMPILER_VAR_111[7] = msg;____BAH_COMPILER_VAR_111[6] = "\n\e[0m\n";____BAH_COMPILER_VAR_111[5] = posStr;____BAH_COMPILER_VAR_111[4] = ":";____BAH_COMPILER_VAR_111[3] = lineStr;____BAH_COMPILER_VAR_111[2] = ":";____BAH_COMPILER_VAR_111[1] = compilerState.currentFile;____BAH_COMPILER_VAR_111[0] = "\e[1;31m[LEXER-ERROR]\e[0m ";char * ____BAH_COMPILER_VAR_112 =__Bah_multiple_concat(____BAH_COMPILER_VAR_111, 8);println(____BAH_COMPILER_VAR_112);
exit(1);
};
array(char)* enclavers;
array(char)* syntaxes;
array(char *)* keywords;
typedef array(struct Tok)* __BAH_ARR_TYPE_Tok;
__BAH_ARR_TYPE_Tok lexer(char * s,unsigned long int codeLength){
long int dur = getTimeUnix();
array(struct Tok)* tokens = memoryAlloc(sizeof(array(struct Tok)));

tokens->length = 0;
tokens->elemSize = sizeof(struct Tok);
totalSize = totalSize+codeLength;
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

    unsigned int ____BAH_COMPILER_VAR_113 = 0;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_113);
    memory->data[____BAH_COMPILER_VAR_113] = c;
i = i+1;
for (; (i<codeLength); ++i) {
c = s[i];
char pc = s[i-1];
if ((c==(char)34)) {
if ((pc!=(char)92)) {

    unsigned int ____BAH_COMPILER_VAR_114 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_114);
    memory->data[____BAH_COMPILER_VAR_114] = c;
break;
}
}
if ((c==(char)10)) {
lineNb = lineNb+1;
if ((pc!=(char)92)) {

    unsigned int ____BAH_COMPILER_VAR_115 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_115);
    memory->data[____BAH_COMPILER_VAR_115] = (char)92;
c = 110;
}
}

    unsigned int ____BAH_COMPILER_VAR_116 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_116);
    memory->data[____BAH_COMPILER_VAR_116] = c;
};

    unsigned int ____BAH_COMPILER_VAR_117 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_117);
    tokens->data[____BAH_COMPILER_VAR_117] = makeToken(pos,lineNb,memory,TOKEN_TYPE_STR);
struct Tok lt = tokens->data[len(tokens)-1];
lt.begLine = begLine;

    unsigned int ____BAH_COMPILER_VAR_118 = len(tokens)-1;
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_118);
    tokens->data[____BAH_COMPILER_VAR_118] = lt;
}
else if (isNumber(c)||isMinus(c,nc)) {

    unsigned int ____BAH_COMPILER_VAR_119 = 0;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_119);
    memory->data[____BAH_COMPILER_VAR_119] = c;
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

    unsigned int ____BAH_COMPILER_VAR_120 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_120);
    memory->data[____BAH_COMPILER_VAR_120] = c;
};
--i;

    unsigned int ____BAH_COMPILER_VAR_121 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_121);
    tokens->data[____BAH_COMPILER_VAR_121] = makeToken(pos,lineNb,memory,currentType);
}
else if ((c==(char)39)) {
++i;
char n = s[i];
char * toInt = intToStr((long int)nc);
memory = strToArr(toInt);
++i;
c = s[i];
if (__builtin_expect((c!=(char)39), 0)) {
lexerErr(lineNb,i,"Missing closing tag in char declaration.");
}

    unsigned int ____BAH_COMPILER_VAR_122 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_122);
    tokens->data[____BAH_COMPILER_VAR_122] = makeToken(i-1,lineNb,memory,TOKEN_TYPE_CHAR);
}
else if ((c==(char)35)) {
long int pos = i;

    unsigned int ____BAH_COMPILER_VAR_123 = 0;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_123);
    memory->data[____BAH_COMPILER_VAR_123] = c;
++i;
for (; (i<codeLength); ++i) {
c = s[i];
if ((isAlphaNumeric(c)==false)) {
break;
}

    unsigned int ____BAH_COMPILER_VAR_124 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_124);
    memory->data[____BAH_COMPILER_VAR_124] = c;
};
--i;

    unsigned int ____BAH_COMPILER_VAR_125 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_125);
    tokens->data[____BAH_COMPILER_VAR_125] = makeToken(pos,lineNb,memory,TOKEN_TYPE_KEYWORD);
}
else if (inArray(c,enclavers)) {

    unsigned int ____BAH_COMPILER_VAR_126 = 0;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_126);
    memory->data[____BAH_COMPILER_VAR_126] = c;

    unsigned int ____BAH_COMPILER_VAR_127 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_127);
    tokens->data[____BAH_COMPILER_VAR_127] = makeToken(i,lineNb,memory,TOKEN_TYPE_ENCL);
}
else if (inArray(c,syntaxes)) {
if ((c==60)) {
long int pos = i;
char isCast = false;

    unsigned int ____BAH_COMPILER_VAR_128 = 0;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_128);
    memory->data[____BAH_COMPILER_VAR_128] = c;
++i;
for (; (i<codeLength); ++i) {
c = s[i];
if ((c==62)) {
isCast = true;

    unsigned int ____BAH_COMPILER_VAR_129 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_129);
    memory->data[____BAH_COMPILER_VAR_129] = c;
break;
}
if ((isAlphaNumeric(c)==false)&&(c!=42)&&(c!=58)&&(c!=95)&&(c!=91)&&(c!=93)) {
break;
}

    unsigned int ____BAH_COMPILER_VAR_130 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_130);
    memory->data[____BAH_COMPILER_VAR_130] = c;
};
if ((isCast==true)) {

    unsigned int ____BAH_COMPILER_VAR_131 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_131);
    tokens->data[____BAH_COMPILER_VAR_131] = makeToken(pos,lineNb,memory,TOKEN_TYPE_CAST);
continue;
}
i = pos;
c = 60;
clear(memory);
}

    unsigned int ____BAH_COMPILER_VAR_132 = 0;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_132);
    memory->data[____BAH_COMPILER_VAR_132] = c;
long int pos = i;
++i;
char fc = c;
for (; (i<codeLength); ++i) {
c = s[i];
char ____BAH_COMPILER_VAR_134 =c;
        char ____BAH_COMPILER_VAR_133 = 0;
        for(int i=syntaxes->length-1; i!=-1;i--) {
            if (syntaxes->data[i] == ____BAH_COMPILER_VAR_134) {
                ____BAH_COMPILER_VAR_133=1;
                break;
            };
        }
        if ((____BAH_COMPILER_VAR_133==false)) {
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

    unsigned int ____BAH_COMPILER_VAR_135 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_135);
    memory->data[____BAH_COMPILER_VAR_135] = c;
};
--i;

    unsigned int ____BAH_COMPILER_VAR_136 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_136);
    tokens->data[____BAH_COMPILER_VAR_136] = makeToken(pos,lineNb,memory,TOKEN_TYPE_SYNTAX);
}
else if ((c==46)) {

    unsigned int ____BAH_COMPILER_VAR_137 = 0;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_137);
    memory->data[____BAH_COMPILER_VAR_137] = c;

    unsigned int ____BAH_COMPILER_VAR_138 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_138);
    tokens->data[____BAH_COMPILER_VAR_138] = makeToken(i,lineNb,memory,TOKEN_TYPE_SEP);
}
else if (isAlphaNumeric(c)||(c==95)) {

    unsigned int ____BAH_COMPILER_VAR_139 = 0;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_139);
    memory->data[____BAH_COMPILER_VAR_139] = c;
long int pos = i;
++i;
for (; (i<codeLength); ++i) {
c = s[i];
if ((isAlphaNumeric(c)==false)) {
if ((c!=95)) {
if ((c==62)) {
char lc = memory->data[len(memory)-1];
if ((lc==45)) {

    unsigned int ____BAH_COMPILER_VAR_140 = len(memory)-1;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_140);
    memory->data[____BAH_COMPILER_VAR_140] = (char)0;
--i;
break;
}
}
break;
}
}

    unsigned int ____BAH_COMPILER_VAR_141 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_141);
    memory->data[____BAH_COMPILER_VAR_141] = c;
};
--i;
tokenType currentType = TOKEN_TYPE_VAR;
char * memstr = arrAsStr(memory);
char * ____BAH_COMPILER_VAR_143 =memstr;
        char ____BAH_COMPILER_VAR_142 = 0;
        for(int i=keywords->length-1; i!=-1;i--) {
            if (keywords->data[i] != 0 && strcmp(keywords->data[i], ____BAH_COMPILER_VAR_143) == 0) {
                ____BAH_COMPILER_VAR_142=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_142) {
currentType = TOKEN_TYPE_KEYWORD;
}

    unsigned int ____BAH_COMPILER_VAR_144 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_144);
    tokens->data[____BAH_COMPILER_VAR_144] = makeToken(pos,lineNb,memory,currentType);
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
char * ____BAH_COMPILER_VAR_145 =splitStringBefore(*n,".");struct string res = string(____BAH_COMPILER_VAR_145);
return res;
}
if (string__count(n,"->")) {
char * ____BAH_COMPILER_VAR_146 =splitStringBefore(*n,"->");struct string res = string(____BAH_COMPILER_VAR_146);
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
struct structMemb* ____BAH_COMPILER_VAR_147 = memoryAlloc(sizeof(struct structMemb));
____BAH_COMPILER_VAR_147->name = "";
____BAH_COMPILER_VAR_147->type = "";
____BAH_COMPILER_VAR_147->constVal = "";
____BAH_COMPILER_VAR_147->from = "";
____BAH_COMPILER_VAR_147->def = "";
struct structMemb* sm = ____BAH_COMPILER_VAR_147;
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
char** ____BAH_COMPILER_VAR_148 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_148[2] = name;____BAH_COMPILER_VAR_148[1] = "__";____BAH_COMPILER_VAR_148[0] = s->name;char * ____BAH_COMPILER_VAR_149 =__Bah_multiple_concat(____BAH_COMPILER_VAR_148, 3);struct func* fn = searchFunc(____BAH_COMPILER_VAR_149,elems,true);
if ((fn!=null)) {
return fn;
}
register long int i = 0;
for (; (i<len(s->members)); ++i) {
if ((strcmp(s->members->data[i]->name, name) == 0)) {
struct string ____BAH_COMPILER_VAR_150 =string(s->members->data[i]->type);fn = parseFnType(____BAH_COMPILER_VAR_150);
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
char** ____BAH_COMPILER_VAR_151 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_151[2] = ")*";____BAH_COMPILER_VAR_151[1] = t;____BAH_COMPILER_VAR_151[0] = "array(";char * ____BAH_COMPILER_VAR_152 =__Bah_multiple_concat(____BAH_COMPILER_VAR_151, 3);char * r = ____BAH_COMPILER_VAR_152;
return string(r);
}
string__replace(&tp,"!","*");
struct string ctp = tp;
string__replace(&ctp,"*","");
if (string__hasPrefix(&tp,"tuple:")) {
array(struct string)* parts = splitString(tp,":");
char * ____BAH_COMPILER_VAR_153 =string__str(&parts->data[2]);
                struct string ____BAH_COMPILER_VAR_154 = getCType(____BAH_COMPILER_VAR_153,elems);
                char** ____BAH_COMPILER_VAR_155 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_155[1] = "*";____BAH_COMPILER_VAR_155[0] = string__str(&____BAH_COMPILER_VAR_154);char * ____BAH_COMPILER_VAR_156 =__Bah_multiple_concat(____BAH_COMPILER_VAR_155, 2);string__set(&tp,____BAH_COMPILER_VAR_156);
}
else if ((string__hasPrefix(&tp,"chan:")==1)) {
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
char** ____BAH_COMPILER_VAR_157 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_157[1] = "*";____BAH_COMPILER_VAR_157[0] = cpstringSubsitute(a, 0, strlen(a)-1);char * ____BAH_COMPILER_VAR_158 =__Bah_multiple_concat(____BAH_COMPILER_VAR_157, 2);a = ____BAH_COMPILER_VAR_158;
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
char * ____BAH_COMPILER_VAR_160 =a;
        char ____BAH_COMPILER_VAR_159 = 0;
        for(int i=intTypes->length-1; i!=-1;i--) {
            if (intTypes->data[i] != 0 && strcmp(intTypes->data[i], ____BAH_COMPILER_VAR_160) == 0) {
                ____BAH_COMPILER_VAR_159=1;
                break;
            };
        }
        char * ____BAH_COMPILER_VAR_162 =b;
        char ____BAH_COMPILER_VAR_161 = 0;
        for(int i=intTypes->length-1; i!=-1;i--) {
            if (intTypes->data[i] != 0 && strcmp(intTypes->data[i], ____BAH_COMPILER_VAR_162) == 0) {
                ____BAH_COMPILER_VAR_161=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_159&&____BAH_COMPILER_VAR_161) {
return true;
}
char * ____BAH_COMPILER_VAR_164 =a;
        char ____BAH_COMPILER_VAR_163 = 0;
        for(int i=floatTypes->length-1; i!=-1;i--) {
            if (floatTypes->data[i] != 0 && strcmp(floatTypes->data[i], ____BAH_COMPILER_VAR_164) == 0) {
                ____BAH_COMPILER_VAR_163=1;
                break;
            };
        }
        char * ____BAH_COMPILER_VAR_166 =b;
        char ____BAH_COMPILER_VAR_165 = 0;
        for(int i=floatTypes->length-1; i!=-1;i--) {
            if (floatTypes->data[i] != 0 && strcmp(floatTypes->data[i], ____BAH_COMPILER_VAR_166) == 0) {
                ____BAH_COMPILER_VAR_165=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_163&&____BAH_COMPILER_VAR_165) {
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
struct reflectElement ____BAH_COMPILER_VAR_167 = {};
____BAH_COMPILER_VAR_167.structLayout = memoryAlloc(sizeof(array(struct reflectElement)));
            ____BAH_COMPILER_VAR_167.structLayout->length = 0;
            ____BAH_COMPILER_VAR_167.structLayout->elemSize = sizeof(struct reflectElement);
            struct reflectElement re = ____BAH_COMPILER_VAR_167;
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
struct reflectElement ____BAH_COMPILER_VAR_168 = {};
____BAH_COMPILER_VAR_168.structLayout = memoryAlloc(sizeof(array(struct reflectElement)));
            ____BAH_COMPILER_VAR_168.structLayout->length = 0;
            ____BAH_COMPILER_VAR_168.structLayout->elemSize = sizeof(struct reflectElement);
            struct reflectElement ns = ____BAH_COMPILER_VAR_168;
return ns;
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

    unsigned int ____BAH_COMPILER_VAR_169 = j-1;
    __Bah_realocate_arr(nk, ____BAH_COMPILER_VAR_169);
    nk->data[____BAH_COMPILER_VAR_169] = c;
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
m.value = reflectElement__calculateOffset(&m,e.value);
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

    unsigned int ____BAH_COMPILER_VAR_170 = i;
    __Bah_realocate_arr(arr, ____BAH_COMPILER_VAR_170);
    arr->data[____BAH_COMPILER_VAR_170] = strToInt(c->content);
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

    unsigned int ____BAH_COMPILER_VAR_171 = i;
    __Bah_realocate_arr(arr, ____BAH_COMPILER_VAR_171);
    arr->data[____BAH_COMPILER_VAR_171] = strToFloat(c->content);
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

    unsigned int ____BAH_COMPILER_VAR_172 = i;
    __Bah_realocate_arr(arr, ____BAH_COMPILER_VAR_172);
    arr->data[____BAH_COMPILER_VAR_172] = c->content;
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

    unsigned int ____BAH_COMPILER_VAR_173 = i;
    __Bah_realocate_arr(arr, ____BAH_COMPILER_VAR_173);
    arr->data[____BAH_COMPILER_VAR_173] = ne;
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

    unsigned int ____BAH_COMPILER_VAR_174 = j;
    __Bah_realocate_arr(ae->structLayout, ____BAH_COMPILER_VAR_174);
    ae->structLayout->data[____BAH_COMPILER_VAR_174] = m;
};
json_scan_inner(c,*ae,true);
struct string k = string(c->key);
string__trimLeft(&k,1);
string__trimRight(&k,1);
if (strCount(ae->type,"*")||(strcmp(ae->type, "ptr") == 0)||(strcmp(ae->type, "cpstring") == 0)||strHasPrefix(ae->type,"[]")||strHasPrefix(ae->type,"map:")) {
char * ____BAH_COMPILER_VAR_175 =string__str(&k);mapWrapper__set(*p,____BAH_COMPILER_VAR_175,v);
}
else {
char * ____BAH_COMPILER_VAR_176 =string__str(&k);mapWrapper__set(*p,____BAH_COMPILER_VAR_176,&v);
}
};
}
};
struct jsonElement* parseJson(char * s){
struct jsonElement* ____BAH_COMPILER_VAR_177 = memoryAlloc(sizeof(struct jsonElement));
____BAH_COMPILER_VAR_177->children = memoryAlloc(sizeof(array(struct jsonElement*)));
            ____BAH_COMPILER_VAR_177->children->length = 0;
            ____BAH_COMPILER_VAR_177->children->elemSize = sizeof(struct jsonElement*);
            struct jsonElement* jsonElem = ____BAH_COMPILER_VAR_177;
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

    unsigned int ____BAH_COMPILER_VAR_178 = len(ns)-1;
    __Bah_realocate_arr(ns, ____BAH_COMPILER_VAR_178);
    ns->data[____BAH_COMPILER_VAR_178] = c;
}
else {

    unsigned int ____BAH_COMPILER_VAR_179 = len(ns);
    __Bah_realocate_arr(ns, ____BAH_COMPILER_VAR_179);
    ns->data[____BAH_COMPILER_VAR_179] = c;
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

    unsigned int ____BAH_COMPILER_VAR_180 = len(currentElem);
    __Bah_realocate_arr(currentElem, ____BAH_COMPILER_VAR_180);
    currentElem->data[____BAH_COMPILER_VAR_180] = c;
i = i+1;
continue;
}
if ((c==44)) {
char * ____BAH_COMPILER_VAR_181 =arrToStr(currentElem);struct jsonElement* child = parseJson(____BAH_COMPILER_VAR_181);
if ((child!=null)) {

    unsigned int ____BAH_COMPILER_VAR_182 = elemIndex;
    __Bah_realocate_arr(jsonElem->children, ____BAH_COMPILER_VAR_182);
    jsonElem->children->data[____BAH_COMPILER_VAR_182] = child;
}
clear(currentElem);
elemIndex = elemIndex+1;
}
else {
if (isSpace(c)) {
i = i+1;
continue;
}

    unsigned int ____BAH_COMPILER_VAR_183 = len(currentElem);
    __Bah_realocate_arr(currentElem, ____BAH_COMPILER_VAR_183);
    currentElem->data[____BAH_COMPILER_VAR_183] = c;
}
i = i+1;
};
char * ____BAH_COMPILER_VAR_184 =arrToStr(currentElem);struct jsonElement* child = parseJson(____BAH_COMPILER_VAR_184);
if ((child!=null)) {

    unsigned int ____BAH_COMPILER_VAR_185 = elemIndex;
    __Bah_realocate_arr(jsonElem->children, ____BAH_COMPILER_VAR_185);
    jsonElem->children->data[____BAH_COMPILER_VAR_185] = child;
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

    unsigned int ____BAH_COMPILER_VAR_186 = len(currentElem);
    __Bah_realocate_arr(currentElem, ____BAH_COMPILER_VAR_186);
    currentElem->data[____BAH_COMPILER_VAR_186] = c;
}
else {

    unsigned int ____BAH_COMPILER_VAR_187 = len(currentKey);
    __Bah_realocate_arr(currentKey, ____BAH_COMPILER_VAR_187);
    currentKey->data[____BAH_COMPILER_VAR_187] = c;
}
i = i+1;
continue;
}
if ((c==58)) {
isVal = 1;
}
else if ((c==44)) {
char * ____BAH_COMPILER_VAR_188 =arrToStr(currentElem);struct jsonElement* elem = parseJson(____BAH_COMPILER_VAR_188);
if ((elem!=null)) {
elem->key = arrToStr(currentKey);

    unsigned int ____BAH_COMPILER_VAR_189 = elemIndex;
    __Bah_realocate_arr(jsonElem->children, ____BAH_COMPILER_VAR_189);
    jsonElem->children->data[____BAH_COMPILER_VAR_189] = elem;
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

    unsigned int ____BAH_COMPILER_VAR_190 = len(currentElem);
    __Bah_realocate_arr(currentElem, ____BAH_COMPILER_VAR_190);
    currentElem->data[____BAH_COMPILER_VAR_190] = c;
}
else {

    unsigned int ____BAH_COMPILER_VAR_191 = len(currentKey);
    __Bah_realocate_arr(currentKey, ____BAH_COMPILER_VAR_191);
    currentKey->data[____BAH_COMPILER_VAR_191] = c;
}
}
i = i+1;
};
char * ____BAH_COMPILER_VAR_192 =arrToStr(currentElem);struct jsonElement* elem = parseJson(____BAH_COMPILER_VAR_192);
if ((elem!=null)) {
elem->key = arrToStr(currentKey);

    unsigned int ____BAH_COMPILER_VAR_193 = elemIndex;
    __Bah_realocate_arr(jsonElem->children, ____BAH_COMPILER_VAR_193);
    jsonElem->children->data[____BAH_COMPILER_VAR_193] = elem;
}
}
return jsonElem;
};
char json_isPrintable(unsigned int c){
if ((c<32)+(c>255)) {
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
if (((unsigned char)c==(unsigned char)195)) {

    unsigned int ____BAH_COMPILER_VAR_194 = len(r);
    __Bah_realocate_arr(r, ____BAH_COMPILER_VAR_194);
    r->data[____BAH_COMPILER_VAR_194] = c;

    unsigned int ____BAH_COMPILER_VAR_195 = len(r);
    __Bah_realocate_arr(r, ____BAH_COMPILER_VAR_195);
    r->data[____BAH_COMPILER_VAR_195] = a->data[i+1];
++i;
}
++i;
continue;
}
if ((c==(char)34)) {

    unsigned int ____BAH_COMPILER_VAR_196 = len(r);
    __Bah_realocate_arr(r, ____BAH_COMPILER_VAR_196);
    r->data[____BAH_COMPILER_VAR_196] = (char)92;
}
else if ((c==(char)10)) {

    unsigned int ____BAH_COMPILER_VAR_197 = len(r);
    __Bah_realocate_arr(r, ____BAH_COMPILER_VAR_197);
    r->data[____BAH_COMPILER_VAR_197] = (char)92;

    unsigned int ____BAH_COMPILER_VAR_198 = len(r);
    __Bah_realocate_arr(r, ____BAH_COMPILER_VAR_198);
    r->data[____BAH_COMPILER_VAR_198] = 110;
i = i+1;
continue;
}
else if ((c==(char)13)) {

    unsigned int ____BAH_COMPILER_VAR_199 = len(r);
    __Bah_realocate_arr(r, ____BAH_COMPILER_VAR_199);
    r->data[____BAH_COMPILER_VAR_199] = (char)92;

    unsigned int ____BAH_COMPILER_VAR_200 = len(r);
    __Bah_realocate_arr(r, ____BAH_COMPILER_VAR_200);
    r->data[____BAH_COMPILER_VAR_200] = 114;
i = i+1;
continue;
}

    unsigned int ____BAH_COMPILER_VAR_201 = len(r);
    __Bah_realocate_arr(r, ____BAH_COMPILER_VAR_201);
    r->data[____BAH_COMPILER_VAR_201] = c;
i = i+1;
};
return arrToStr(r);
};
char * toJson__inner(struct reflectElement e,char isMember,long int tabs){
void ** v = e.value;
if ((e.value==null)) {
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
char** ____BAH_COMPILER_VAR_202 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_202[1] = "\t";____BAH_COMPILER_VAR_202[0] = tabsStr;char * ____BAH_COMPILER_VAR_203 =__Bah_multiple_concat(____BAH_COMPILER_VAR_202, 2);tabsStr = ____BAH_COMPILER_VAR_203;
i = i+1;
};
char * s = "{\n";
i = 0;
while ((i<len(e.structLayout))) {
struct reflectElement m = e.structLayout->data[i];
i = i+1;
m.value = reflectElement__calculateOffset(&m,e.value);
if ((i<len(e.structLayout))) {
char** ____BAH_COMPILER_VAR_204 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_204[6] = ",\n";____BAH_COMPILER_VAR_204[5] = toJson__inner(m,true,tabs);____BAH_COMPILER_VAR_204[4] = "\": ";____BAH_COMPILER_VAR_204[3] = m.name;____BAH_COMPILER_VAR_204[2] = "\"";____BAH_COMPILER_VAR_204[1] = tabsStr;____BAH_COMPILER_VAR_204[0] = s;char * ____BAH_COMPILER_VAR_205 =__Bah_multiple_concat(____BAH_COMPILER_VAR_204, 7);s = ____BAH_COMPILER_VAR_205;
}
else {
char** ____BAH_COMPILER_VAR_206 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_206[6] = "\n";____BAH_COMPILER_VAR_206[5] = toJson__inner(m,true,tabs);____BAH_COMPILER_VAR_206[4] = "\": ";____BAH_COMPILER_VAR_206[3] = m.name;____BAH_COMPILER_VAR_206[2] = "\"";____BAH_COMPILER_VAR_206[1] = tabsStr;____BAH_COMPILER_VAR_206[0] = s;char * ____BAH_COMPILER_VAR_207 =__Bah_multiple_concat(____BAH_COMPILER_VAR_206, 7);s = ____BAH_COMPILER_VAR_207;
}
};
tabs = tabs-1;
tabsStr = "";
i = 0;
while ((i<tabs)) {
char** ____BAH_COMPILER_VAR_208 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_208[1] = "\t";____BAH_COMPILER_VAR_208[0] = tabsStr;char * ____BAH_COMPILER_VAR_209 =__Bah_multiple_concat(____BAH_COMPILER_VAR_208, 2);tabsStr = ____BAH_COMPILER_VAR_209;
i = i+1;
};
char** ____BAH_COMPILER_VAR_210 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_210[2] = "}";____BAH_COMPILER_VAR_210[1] = tabsStr;____BAH_COMPILER_VAR_210[0] = s;char * ____BAH_COMPILER_VAR_211 =__Bah_multiple_concat(____BAH_COMPILER_VAR_210, 3);s = ____BAH_COMPILER_VAR_211;
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
char** ____BAH_COMPILER_VAR_212 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_212[2] = "\"";____BAH_COMPILER_VAR_212[1] = jsonEscapeStr(s);____BAH_COMPILER_VAR_212[0] = "\"";char * ____BAH_COMPILER_VAR_213 =__Bah_multiple_concat(____BAH_COMPILER_VAR_212, 3);return ____BAH_COMPILER_VAR_213;
}
else {
char ** sp = e.value;
char * s = *sp;
char** ____BAH_COMPILER_VAR_214 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_214[2] = "\"";____BAH_COMPILER_VAR_214[1] = jsonEscapeStr(s);____BAH_COMPILER_VAR_214[0] = "\"";char * ____BAH_COMPILER_VAR_215 =__Bah_multiple_concat(____BAH_COMPILER_VAR_214, 3);return ____BAH_COMPILER_VAR_215;
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
if ((e.value==null)) {
return "null";
}
if ((strcmp(ae->type, "int") == 0)) {
array(long int)* arr = memoryAlloc(sizeof(array(long int)));

arr->length = 0;
arr->elemSize = sizeof(long int);
void ** arrPtr = e.value;
arr = *arrPtr;
register long int i = 0;
while ((i<len(arr))) {
char** ____BAH_COMPILER_VAR_216 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_216[1] = intToStr(arr->data[i]);____BAH_COMPILER_VAR_216[0] = s;char * ____BAH_COMPILER_VAR_217 =__Bah_multiple_concat(____BAH_COMPILER_VAR_216, 2);s = ____BAH_COMPILER_VAR_217;
i = i+1;
if ((i<len(arr))) {
char** ____BAH_COMPILER_VAR_218 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_218[1] = ",";____BAH_COMPILER_VAR_218[0] = s;char * ____BAH_COMPILER_VAR_219 =__Bah_multiple_concat(____BAH_COMPILER_VAR_218, 2);s = ____BAH_COMPILER_VAR_219;
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
char** ____BAH_COMPILER_VAR_220 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_220[1] = floatToStr(arr->data[i]);____BAH_COMPILER_VAR_220[0] = s;char * ____BAH_COMPILER_VAR_221 =__Bah_multiple_concat(____BAH_COMPILER_VAR_220, 2);s = ____BAH_COMPILER_VAR_221;
i = i+1;
if ((i<len(arr))) {
char** ____BAH_COMPILER_VAR_222 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_222[1] = ",";____BAH_COMPILER_VAR_222[0] = s;char * ____BAH_COMPILER_VAR_223 =__Bah_multiple_concat(____BAH_COMPILER_VAR_222, 2);s = ____BAH_COMPILER_VAR_223;
}
};
}
else if ((strcmp(ae->type, "cpstring") == 0)) {
array(char *)* arr = memoryAlloc(sizeof(array(char *)));

arr->length = 0;
arr->elemSize = sizeof(char *);
void ** arrPtr = e.value;
arr = *arrPtr;
char** ____BAH_COMPILER_VAR_224 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_224[1] = "\n";____BAH_COMPILER_VAR_224[0] = s;char * ____BAH_COMPILER_VAR_225 =__Bah_multiple_concat(____BAH_COMPILER_VAR_224, 2);s = ____BAH_COMPILER_VAR_225;
register long int i = 0;
while ((i<len(arr))) {
char** ____BAH_COMPILER_VAR_226 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_226[3] = "\"";____BAH_COMPILER_VAR_226[2] = jsonEscapeStr(arr->data[i]);____BAH_COMPILER_VAR_226[1] = "\"";____BAH_COMPILER_VAR_226[0] = s;char * ____BAH_COMPILER_VAR_227 =__Bah_multiple_concat(____BAH_COMPILER_VAR_226, 4);s = ____BAH_COMPILER_VAR_227;
i = i+1;
if ((i<len(arr))) {
char** ____BAH_COMPILER_VAR_228 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_228[1] = ",\n";____BAH_COMPILER_VAR_228[0] = s;char * ____BAH_COMPILER_VAR_229 =__Bah_multiple_concat(____BAH_COMPILER_VAR_228, 2);s = ____BAH_COMPILER_VAR_229;
}
else {
char** ____BAH_COMPILER_VAR_230 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_230[1] = "\n";____BAH_COMPILER_VAR_230[0] = s;char * ____BAH_COMPILER_VAR_231 =__Bah_multiple_concat(____BAH_COMPILER_VAR_230, 2);s = ____BAH_COMPILER_VAR_231;
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

    unsigned int ____BAH_COMPILER_VAR_232 = j;
    __Bah_realocate_arr(ae->structLayout, ____BAH_COMPILER_VAR_232);
    ae->structLayout->data[____BAH_COMPILER_VAR_232] = m;
j = j+1;
};
char** ____BAH_COMPILER_VAR_233 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_233[1] = toJson__inner(*ae,false,tabs);____BAH_COMPILER_VAR_233[0] = s;char * ____BAH_COMPILER_VAR_234 =__Bah_multiple_concat(____BAH_COMPILER_VAR_233, 2);s = ____BAH_COMPILER_VAR_234;
i = i+1;
if ((i<len(arr))) {
char** ____BAH_COMPILER_VAR_235 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_235[1] = ",\n";____BAH_COMPILER_VAR_235[0] = s;char * ____BAH_COMPILER_VAR_236 =__Bah_multiple_concat(____BAH_COMPILER_VAR_235, 2);s = ____BAH_COMPILER_VAR_236;
}
else {
char** ____BAH_COMPILER_VAR_237 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_237[1] = "\n";____BAH_COMPILER_VAR_237[0] = s;char * ____BAH_COMPILER_VAR_238 =__Bah_multiple_concat(____BAH_COMPILER_VAR_237, 2);s = ____BAH_COMPILER_VAR_238;
}
};
}
char** ____BAH_COMPILER_VAR_239 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_239[1] = "]";____BAH_COMPILER_VAR_239[0] = s;char * ____BAH_COMPILER_VAR_240 =__Bah_multiple_concat(____BAH_COMPILER_VAR_239, 2);s = ____BAH_COMPILER_VAR_240;
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
char * ____BAH_COMPILER_VAR_241 = name;
struct reflectElement ____BAH_COMPILER_VAR_242 = __reflect(____BAH_COMPILER_VAR_241, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, 0);
char** ____BAH_COMPILER_VAR_243 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_243[8] = "\n    },\n    ";____BAH_COMPILER_VAR_243[7] = toJson(e);____BAH_COMPILER_VAR_243[6] = "\",\n        \"element\": ";____BAH_COMPILER_VAR_243[5] = intToStr(line);____BAH_COMPILER_VAR_243[4] = ":";____BAH_COMPILER_VAR_243[3] = compilerState.currentFile;____BAH_COMPILER_VAR_243[2] = ",\n        \"path\": \"";____BAH_COMPILER_VAR_243[1] = toJson(____BAH_COMPILER_VAR_242);____BAH_COMPILER_VAR_243[0] = "\n    {\n        \"name\": ";char * ____BAH_COMPILER_VAR_244 =__Bah_multiple_concat(____BAH_COMPILER_VAR_243, 9);println(____BAH_COMPILER_VAR_244);
};
void debugError(char * name,long int line,long int from,long int to,struct reflectElement e){
if ((debug==false)) {
return;
}
char * ____BAH_COMPILER_VAR_245 = name;
struct reflectElement ____BAH_COMPILER_VAR_246 = __reflect(____BAH_COMPILER_VAR_245, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, 0);
char** ____BAH_COMPILER_VAR_247 = alloca(13 * sizeof(char*));____BAH_COMPILER_VAR_247[12] = "\n    },\n    ";____BAH_COMPILER_VAR_247[11] = toJson(e);____BAH_COMPILER_VAR_247[10] = "\n        ],\n        \"element\": ";____BAH_COMPILER_VAR_247[9] = intToStr(to);____BAH_COMPILER_VAR_247[8] = ",\n            ";____BAH_COMPILER_VAR_247[7] = intToStr(from);____BAH_COMPILER_VAR_247[6] = "\",\n        \"range\": [\n            ";____BAH_COMPILER_VAR_247[5] = intToStr(line);____BAH_COMPILER_VAR_247[4] = ":";____BAH_COMPILER_VAR_247[3] = compilerState.currentFile;____BAH_COMPILER_VAR_247[2] = ",\n        \"path\": \"";____BAH_COMPILER_VAR_247[1] = toJson(____BAH_COMPILER_VAR_246);____BAH_COMPILER_VAR_247[0] = "\n    {\n        \"name\": ";char * ____BAH_COMPILER_VAR_248 =__Bah_multiple_concat(____BAH_COMPILER_VAR_247, 13);println(____BAH_COMPILER_VAR_248);
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
struct variable* ____BAH_COMPILER_VAR_249 = v;
char ** ____BAH_COMPILER_VAR_251 = (char **)((char*)(____BAH_COMPILER_VAR_249) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_252 = __reflect(____BAH_COMPILER_VAR_251, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_253 = (char **)((char*)(____BAH_COMPILER_VAR_249) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_254 = __reflect(____BAH_COMPILER_VAR_253, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_255 = (char*)((char*)(____BAH_COMPILER_VAR_249) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_256 = __reflect(____BAH_COMPILER_VAR_255, sizeof(char), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_257 = (char **)((char*)(____BAH_COMPILER_VAR_249) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_258 = __reflect(____BAH_COMPILER_VAR_257, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_259 = (char*)((char*)(____BAH_COMPILER_VAR_249) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_260 = __reflect(____BAH_COMPILER_VAR_259, sizeof(char), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_261 = (char **)((char*)(____BAH_COMPILER_VAR_249) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_262 = __reflect(____BAH_COMPILER_VAR_261, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
void ** ____BAH_COMPILER_VAR_263 = (void **)((char*)(____BAH_COMPILER_VAR_249) + offsetof(struct variable, declScope));
struct reflectElement ____BAH_COMPILER_VAR_264 = __reflect(____BAH_COMPILER_VAR_263, sizeof(void *), "ptr", "declScope", 0, 0, 0, 0, offsetof(struct variable, declScope));
char* ____BAH_COMPILER_VAR_265 = (char*)((char*)(____BAH_COMPILER_VAR_249) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_266 = __reflect(____BAH_COMPILER_VAR_265, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));
struct rope** ____BAH_COMPILER_VAR_267 = (struct rope**)((char*)(____BAH_COMPILER_VAR_249) + offsetof(struct variable, declRope));
void ** ____BAH_COMPILER_VAR_269 = (void **)((char*)(____BAH_COMPILER_VAR_267) + offsetof(struct rope, left));
struct reflectElement ____BAH_COMPILER_VAR_270 = __reflect(____BAH_COMPILER_VAR_269, sizeof(void *), "ptr", "left", 0, 0, 0, 0, offsetof(struct rope, left));
void ** ____BAH_COMPILER_VAR_271 = (void **)((char*)(____BAH_COMPILER_VAR_267) + offsetof(struct rope, right));
struct reflectElement ____BAH_COMPILER_VAR_272 = __reflect(____BAH_COMPILER_VAR_271, sizeof(void *), "ptr", "right", 0, 0, 0, 0, offsetof(struct rope, right));
char ** ____BAH_COMPILER_VAR_273 = (char **)((char*)(____BAH_COMPILER_VAR_267) + offsetof(struct rope, str));
struct reflectElement ____BAH_COMPILER_VAR_274 = __reflect(____BAH_COMPILER_VAR_273, sizeof(char *), "cpstring", "str", 0, 0, 0, 0, offsetof(struct rope, str));
int* ____BAH_COMPILER_VAR_275 = (int*)((char*)(____BAH_COMPILER_VAR_267) + offsetof(struct rope, lCount));
struct reflectElement ____BAH_COMPILER_VAR_276 = __reflect(____BAH_COMPILER_VAR_275, sizeof(int), "int32", "lCount", 0, 0, 0, 0, offsetof(struct rope, lCount));
int* ____BAH_COMPILER_VAR_277 = (int*)((char*)(____BAH_COMPILER_VAR_267) + offsetof(struct rope, len));
struct reflectElement ____BAH_COMPILER_VAR_278 = __reflect(____BAH_COMPILER_VAR_277, sizeof(int), "int32", "len", 0, 0, 0, 0, offsetof(struct rope, len));
int* ____BAH_COMPILER_VAR_279 = (int*)((char*)(____BAH_COMPILER_VAR_267) + offsetof(struct rope, totalLen));
struct reflectElement ____BAH_COMPILER_VAR_280 = __reflect(____BAH_COMPILER_VAR_279, sizeof(int), "int32", "totalLen", 0, 0, 0, 0, offsetof(struct rope, totalLen));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_268 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_268->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_268->length = 6;
        ____BAH_COMPILER_VAR_268->data = memoryAlloc(____BAH_COMPILER_VAR_268->length * ____BAH_COMPILER_VAR_268->elemSize);
        ____BAH_COMPILER_VAR_268->data[0] = ____BAH_COMPILER_VAR_270;
____BAH_COMPILER_VAR_268->data[1] = ____BAH_COMPILER_VAR_272;
____BAH_COMPILER_VAR_268->data[2] = ____BAH_COMPILER_VAR_274;
____BAH_COMPILER_VAR_268->data[3] = ____BAH_COMPILER_VAR_276;
____BAH_COMPILER_VAR_268->data[4] = ____BAH_COMPILER_VAR_278;
____BAH_COMPILER_VAR_268->data[5] = ____BAH_COMPILER_VAR_280;
struct reflectElement ____BAH_COMPILER_VAR_281 = __reflect(____BAH_COMPILER_VAR_267, sizeof(struct rope), "rope*", "declRope", 0, 0, 1, ____BAH_COMPILER_VAR_268, offsetof(struct variable, declRope));
char* ____BAH_COMPILER_VAR_282 = (char*)((char*)(____BAH_COMPILER_VAR_249) + offsetof(struct variable, canBeNull));
struct reflectElement ____BAH_COMPILER_VAR_283 = __reflect(____BAH_COMPILER_VAR_282, sizeof(char), "bool", "canBeNull", 0, 0, 0, 0, offsetof(struct variable, canBeNull));
char* ____BAH_COMPILER_VAR_284 = (char*)((char*)(____BAH_COMPILER_VAR_249) + offsetof(struct variable, canBeReg));
struct reflectElement ____BAH_COMPILER_VAR_285 = __reflect(____BAH_COMPILER_VAR_284, sizeof(char), "bool", "canBeReg", 0, 0, 0, 0, offsetof(struct variable, canBeReg));
char* ____BAH_COMPILER_VAR_286 = (char*)((char*)(____BAH_COMPILER_VAR_249) + offsetof(struct variable, isReg));
struct reflectElement ____BAH_COMPILER_VAR_287 = __reflect(____BAH_COMPILER_VAR_286, sizeof(char), "bool", "isReg", 0, 0, 0, 0, offsetof(struct variable, isReg));
void ** ____BAH_COMPILER_VAR_288 = (void **)((char*)(____BAH_COMPILER_VAR_249) + offsetof(struct variable, lastSet));
struct reflectElement ____BAH_COMPILER_VAR_289 = __reflect(____BAH_COMPILER_VAR_288, sizeof(void *), "ptr", "lastSet", 0, 0, 0, 0, offsetof(struct variable, lastSet));
char* ____BAH_COMPILER_VAR_290 = (char*)((char*)(____BAH_COMPILER_VAR_249) + offsetof(struct variable, isArg));
struct reflectElement ____BAH_COMPILER_VAR_291 = __reflect(____BAH_COMPILER_VAR_290, sizeof(char), "bool", "isArg", 0, 0, 0, 0, offsetof(struct variable, isArg));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_250 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_250->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_250->length = 14;
        ____BAH_COMPILER_VAR_250->data = memoryAlloc(____BAH_COMPILER_VAR_250->length * ____BAH_COMPILER_VAR_250->elemSize);
        ____BAH_COMPILER_VAR_250->data[0] = ____BAH_COMPILER_VAR_252;
____BAH_COMPILER_VAR_250->data[1] = ____BAH_COMPILER_VAR_254;
____BAH_COMPILER_VAR_250->data[2] = ____BAH_COMPILER_VAR_256;
____BAH_COMPILER_VAR_250->data[3] = ____BAH_COMPILER_VAR_258;
____BAH_COMPILER_VAR_250->data[4] = ____BAH_COMPILER_VAR_260;
____BAH_COMPILER_VAR_250->data[5] = ____BAH_COMPILER_VAR_262;
____BAH_COMPILER_VAR_250->data[6] = ____BAH_COMPILER_VAR_264;
____BAH_COMPILER_VAR_250->data[7] = ____BAH_COMPILER_VAR_266;
____BAH_COMPILER_VAR_250->data[8] = ____BAH_COMPILER_VAR_281;
____BAH_COMPILER_VAR_250->data[9] = ____BAH_COMPILER_VAR_283;
____BAH_COMPILER_VAR_250->data[10] = ____BAH_COMPILER_VAR_285;
____BAH_COMPILER_VAR_250->data[11] = ____BAH_COMPILER_VAR_287;
____BAH_COMPILER_VAR_250->data[12] = ____BAH_COMPILER_VAR_289;
____BAH_COMPILER_VAR_250->data[13] = ____BAH_COMPILER_VAR_291;
struct reflectElement ____BAH_COMPILER_VAR_292 = __reflect(____BAH_COMPILER_VAR_249, sizeof(struct variable), "variable*", "v", 0, 0, 1, ____BAH_COMPILER_VAR_250, 0);
debugPrint("var_end",line,____BAH_COMPILER_VAR_292);
}
i = i+1;
};
};
void advertiseGeneric();
void throwErr(void * tp,char * format){
char * str = "";
char * info = "";
long int pos = 0;
if ((tp!=null)) {
struct fileMap ____BAH_COMPILER_VAR_293 = {};
____BAH_COMPILER_VAR_293.handle = -1;
struct fileMap fm = ____BAH_COMPILER_VAR_293;
char * fileSrcStr = fileMap__open(&fm,compilerState.currentFile);
struct Tok* t = tp;
struct string ffmt = string(format);
if ((strlen(t->ogCont)==0)) {
t->ogCont = t->cont;
}
char** ____BAH_COMPILER_VAR_294 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_294[2] = "'";____BAH_COMPILER_VAR_294[1] = t->ogCont;____BAH_COMPILER_VAR_294[0] = "'";char * ____BAH_COMPILER_VAR_295 =__Bah_multiple_concat(____BAH_COMPILER_VAR_294, 3);string__replace(&ffmt,"{TOKEN}",____BAH_COMPILER_VAR_295);
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

    unsigned int ____BAH_COMPILER_VAR_296 = len(errCont);
    __Bah_realocate_arr(errCont, ____BAH_COMPILER_VAR_296);
    errCont->data[____BAH_COMPILER_VAR_296] = fileSrcStr[i];
};
char** ____BAH_COMPILER_VAR_297 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_297[2] = "\e[1;37m";____BAH_COMPILER_VAR_297[1] = arrToStr(errCont);____BAH_COMPILER_VAR_297[0] = "\e[1;31m";char * ____BAH_COMPILER_VAR_298 =__Bah_multiple_concat(____BAH_COMPILER_VAR_297, 3);array(char)* errTk = strToArr(____BAH_COMPILER_VAR_298);
register long int ii = 0;
for (; (ii<len(errTk)); ++ii) {

    unsigned int ____BAH_COMPILER_VAR_299 = len(line);
    __Bah_realocate_arr(line, ____BAH_COMPILER_VAR_299);
    line->data[____BAH_COMPILER_VAR_299] = errTk->data[ii];
};
--i;
continue;
}

    unsigned int ____BAH_COMPILER_VAR_300 = len(line);
    __Bah_realocate_arr(line, ____BAH_COMPILER_VAR_300);
    line->data[____BAH_COMPILER_VAR_300] = c;
};
fileMap__close(&fm);
str = arrToStr(line);
char** ____BAH_COMPILER_VAR_301 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_301[2] = intToStr(pos);____BAH_COMPILER_VAR_301[1] = ":";____BAH_COMPILER_VAR_301[0] = intToStr(t->line);char * ____BAH_COMPILER_VAR_302 =__Bah_multiple_concat(____BAH_COMPILER_VAR_301, 3);info = ____BAH_COMPILER_VAR_302;
}
if ((debug==true)) {
struct Tok* t = tp;
char * ____BAH_COMPILER_VAR_303 = format;
struct reflectElement ____BAH_COMPILER_VAR_304 = __reflect(____BAH_COMPILER_VAR_303, sizeof(char *), "cpstring", "format", 0, 0, 0, 0, 0);
debugError("error",t->line,pos,pos+strlen(t->ogCont),____BAH_COMPILER_VAR_304);
debugExit();
}
else {
advertiseGeneric();
char** ____BAH_COMPILER_VAR_305 = alloca(8 * sizeof(char*));____BAH_COMPILER_VAR_305[7] = format;____BAH_COMPILER_VAR_305[6] = "\e[0m\n";____BAH_COMPILER_VAR_305[5] = str;____BAH_COMPILER_VAR_305[4] = "\n\e[1;37m\t";____BAH_COMPILER_VAR_305[3] = info;____BAH_COMPILER_VAR_305[2] = ":";____BAH_COMPILER_VAR_305[1] = compilerState.currentFile;____BAH_COMPILER_VAR_305[0] = "\e[1;31m[ERROR]\e[0m ";char * ____BAH_COMPILER_VAR_306 =__Bah_multiple_concat(____BAH_COMPILER_VAR_305, 8);println(____BAH_COMPILER_VAR_306);
}
exit(1);
};
void throwWarning(char * s){
char** ____BAH_COMPILER_VAR_307 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_307[4] = "\e[0m";____BAH_COMPILER_VAR_307[3] = s;____BAH_COMPILER_VAR_307[2] = "\n\e[0m\t";____BAH_COMPILER_VAR_307[1] = compilerState.currentFile;____BAH_COMPILER_VAR_307[0] = "\e[1;33m[WARNING]\e[0m ";char * ____BAH_COMPILER_VAR_308 =__Bah_multiple_concat(____BAH_COMPILER_VAR_307, 5);println(____BAH_COMPILER_VAR_308);
};
void throwWarningLine(char * s,long int l){
char** ____BAH_COMPILER_VAR_309 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_309[6] = "\e[0m";____BAH_COMPILER_VAR_309[5] = s;____BAH_COMPILER_VAR_309[4] = "\n\e[0m\t";____BAH_COMPILER_VAR_309[3] = intToStr(l);____BAH_COMPILER_VAR_309[2] = ":";____BAH_COMPILER_VAR_309[1] = compilerState.currentFile;____BAH_COMPILER_VAR_309[0] = "\e[1;33m[WARNING]\e[0m ";char * ____BAH_COMPILER_VAR_310 =__Bah_multiple_concat(____BAH_COMPILER_VAR_309, 7);println(____BAH_COMPILER_VAR_310);
};
void throwNoticeLine(char * s,long int l){
if ((noticeEnabled==false)) {
return;
}
char** ____BAH_COMPILER_VAR_311 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_311[6] = "\e[0m";____BAH_COMPILER_VAR_311[5] = s;____BAH_COMPILER_VAR_311[4] = "\n\e[0m\t";____BAH_COMPILER_VAR_311[3] = intToStr(l);____BAH_COMPILER_VAR_311[2] = ":";____BAH_COMPILER_VAR_311[1] = compilerState.currentFile;____BAH_COMPILER_VAR_311[0] = "\e[1;36m[NOTICE]\e[0m ";char * ____BAH_COMPILER_VAR_312 =__Bah_multiple_concat(____BAH_COMPILER_VAR_311, 7);println(____BAH_COMPILER_VAR_312);
};
#include <stdlib.h>
char * absPath(char * path){
char * buff = memoryAlloc(4096);
char * p = _fullpath(buff,path,4095);
if (((void *)p!=null)) {
array(char)* arr = strAsArr(p);
register long int i = 0;
for (; (i<len(arr)); ++i) {
char c = arr->data[i];
if ((c==(char)92)) {

    unsigned int ____BAH_COMPILER_VAR_313 = i;
    __Bah_realocate_arr(arr, ____BAH_COMPILER_VAR_313);
    arr->data[____BAH_COMPILER_VAR_313] = 47;
}
};
}
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
else if (string__hasPrefix(&vt,"tuple:")) {
array(struct string)* parts = splitString(vt,":");
char * ____BAH_COMPILER_VAR_314 =string__str(&parts->data[2]);string__set(&vt,____BAH_COMPILER_VAR_314);
}
else {
string__set(&vt,"char");
}
char * vtstr = string__str(&vt);
struct variable* ____BAH_COMPILER_VAR_315 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_315->name = "";
____BAH_COMPILER_VAR_315->type = "";
____BAH_COMPILER_VAR_315->constVal = "";
____BAH_COMPILER_VAR_315->from = "";
struct variable* nv = ____BAH_COMPILER_VAR_315;
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
struct variable* ____BAH_COMPILER_VAR_316 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_316->name = "";
____BAH_COMPILER_VAR_316->type = "";
____BAH_COMPILER_VAR_316->constVal = "";
____BAH_COMPILER_VAR_316->from = "";
struct variable* nv = ____BAH_COMPILER_VAR_316;
nv->from = memb->from;
nv->name = memb->name;
nv->type = memb->type;
nv->declScope = v->declScope;
nv->name = ogName;
char * r = nv->type;
struct string tcc = string(ogName);
if (string__count(&tcc,"&")) {
char** ____BAH_COMPILER_VAR_317 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_317[1] = "*";____BAH_COMPILER_VAR_317[0] = r;char * ____BAH_COMPILER_VAR_318 =__Bah_multiple_concat(____BAH_COMPILER_VAR_317, 2);r = ____BAH_COMPILER_VAR_318;
}
long int nbUnaries = string__count(&tcc,"*");
if ((nbUnaries>0)) {
struct string ct = string(r);
long int pointerLevel = string__count(&ct,"*");
if (__builtin_expect((pointerLevel<nbUnaries), 0)) {
char** ____BAH_COMPILER_VAR_319 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_319[2] = "' because it is not pointer.";____BAH_COMPILER_VAR_319[1] = name;____BAH_COMPILER_VAR_319[0] = "Cannot use '*' on '";char * ____BAH_COMPILER_VAR_320 =__Bah_multiple_concat(____BAH_COMPILER_VAR_319, 3);throwErr(null,____BAH_COMPILER_VAR_320);
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
struct variable* ____BAH_COMPILER_VAR_321 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_321->name = "";
____BAH_COMPILER_VAR_321->type = "";
____BAH_COMPILER_VAR_321->constVal = "";
____BAH_COMPILER_VAR_321->from = "";
struct variable* nv = ____BAH_COMPILER_VAR_321;
*nv = *v;
char * r = nv->type;
struct string tcc = string(ogName);
if (string__count(&tcc,"&")) {
char** ____BAH_COMPILER_VAR_322 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_322[1] = "*";____BAH_COMPILER_VAR_322[0] = r;char * ____BAH_COMPILER_VAR_323 =__Bah_multiple_concat(____BAH_COMPILER_VAR_322, 2);r = ____BAH_COMPILER_VAR_323;
}
long int nbUnaries = string__count(&tcc,"*");
if ((nbUnaries>0)) {
struct string ct = string(r);
long int pointerLevel = string__count(&ct,"*");
if (__builtin_expect((pointerLevel<nbUnaries), 0)) {
char** ____BAH_COMPILER_VAR_324 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_324[2] = "' because it is not pointer.";____BAH_COMPILER_VAR_324[1] = name;____BAH_COMPILER_VAR_324[0] = "Cannot use '*' on '";char * ____BAH_COMPILER_VAR_325 =__Bah_multiple_concat(____BAH_COMPILER_VAR_324, 3);throwErr(null,____BAH_COMPILER_VAR_325);
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
struct variable* ____BAH_COMPILER_VAR_326 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_326->name = "";
____BAH_COMPILER_VAR_326->type = "";
____BAH_COMPILER_VAR_326->constVal = "";
____BAH_COMPILER_VAR_326->from = "";
struct variable* nv = ____BAH_COMPILER_VAR_326;
nv->name = name;
nv->type = "function(";
register long int j = 0;
while ((j<len(fn->args))) {
struct variable* arg = fn->args->data[j];
char** ____BAH_COMPILER_VAR_327 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_327[1] = arg->type;____BAH_COMPILER_VAR_327[0] = nv->type;char * ____BAH_COMPILER_VAR_328 =__Bah_multiple_concat(____BAH_COMPILER_VAR_327, 2);nv->type = ____BAH_COMPILER_VAR_328;
j = j+1;
if ((j<len(fn->args))) {
char** ____BAH_COMPILER_VAR_329 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_329[1] = ",";____BAH_COMPILER_VAR_329[0] = nv->type;char * ____BAH_COMPILER_VAR_330 =__Bah_multiple_concat(____BAH_COMPILER_VAR_329, 2);nv->type = ____BAH_COMPILER_VAR_330;
}
};
fn->used = true;
char** ____BAH_COMPILER_VAR_331 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_331[2] = fn->returns->type;____BAH_COMPILER_VAR_331[1] = ")";____BAH_COMPILER_VAR_331[0] = nv->type;char * ____BAH_COMPILER_VAR_332 =__Bah_multiple_concat(____BAH_COMPILER_VAR_331, 3);nv->type = ____BAH_COMPILER_VAR_332;
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
char * ____BAH_COMPILER_VAR_333 =string__str(&cont);return getRealVar(____BAH_COMPILER_VAR_333,elems);
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
char** ____BAH_COMPILER_VAR_334 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_334[2] = v->name;____BAH_COMPILER_VAR_334[1] = " ";____BAH_COMPILER_VAR_334[0] = t;char * ____BAH_COMPILER_VAR_335 =__Bah_multiple_concat(____BAH_COMPILER_VAR_334, 3);t = ____BAH_COMPILER_VAR_335;
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
if (__builtin_expect((strict==true), 0)) {
throwErr(t,"Unknown var {TOKEN}.");
}
else {
return "";
}
}
if ((strict==true)) {
if (__builtin_expect((strcmp(v->type, "") == 0), 0)) {
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
struct func* ____BAH_COMPILER_VAR_336 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_336->name = "";
____BAH_COMPILER_VAR_336->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_336->args->length = 0;
            ____BAH_COMPILER_VAR_336->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_336->from = "";
____BAH_COMPILER_VAR_336->file = "";
____BAH_COMPILER_VAR_336->line = 1;
struct func* nf = ____BAH_COMPILER_VAR_336;
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
struct variable* ____BAH_COMPILER_VAR_337 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_337->name = "";
____BAH_COMPILER_VAR_337->type = "";
____BAH_COMPILER_VAR_337->constVal = "";
____BAH_COMPILER_VAR_337->from = "";
struct variable* arg = ____BAH_COMPILER_VAR_337;
char** ____BAH_COMPILER_VAR_338 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_338[1] = intToStr(len(nf->args));____BAH_COMPILER_VAR_338[0] = "arg_";char * ____BAH_COMPILER_VAR_339 =__Bah_multiple_concat(____BAH_COMPILER_VAR_338, 2);arg->name = ____BAH_COMPILER_VAR_339;
while ((j<cvt.length)) {
c = string__charAt(&cvt,j);
if ((c==44)||(c==41)) {
break;
}

    unsigned int ____BAH_COMPILER_VAR_340 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_340);
    memory->data[____BAH_COMPILER_VAR_340] = c;
j = j+1;
};
arg->type = arrToStr(memory);
clear(memory);

    unsigned int ____BAH_COMPILER_VAR_341 = len(nf->args);
    __Bah_realocate_arr(nf->args, ____BAH_COMPILER_VAR_341);
    nf->args->data[____BAH_COMPILER_VAR_341] = arg;
if ((c==41)) {
break;
}
j = j+1;
};
j = j+1;
while ((j<cvt.length)) {
char c = string__charAt(&cvt,j);

    unsigned int ____BAH_COMPILER_VAR_342 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_342);
    memory->data[____BAH_COMPILER_VAR_342] = c;
j = j+1;
};
struct variable* ____BAH_COMPILER_VAR_343 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_343->name = "";
____BAH_COMPILER_VAR_343->type = "";
____BAH_COMPILER_VAR_343->constVal = "";
____BAH_COMPILER_VAR_343->from = "";
nf->returns = ____BAH_COMPILER_VAR_343;
nf->returns->name = "_return";
nf->returns->type = arrToStr(memory);
return nf;
};
struct func* searchFunc(char * name,struct Elems* elems,char inclCurr){
char * ogName = name;
if ((strcmp(name, "noCheck") == 0)) {
struct func* ____BAH_COMPILER_VAR_344 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_344->name = "";
____BAH_COMPILER_VAR_344->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_344->args->length = 0;
            ____BAH_COMPILER_VAR_344->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_344->from = "";
____BAH_COMPILER_VAR_344->file = "";
____BAH_COMPILER_VAR_344->line = 1;
struct func* fn = ____BAH_COMPILER_VAR_344;
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
char * ____BAH_COMPILER_VAR_345 =string__str(&fnName);struct structMemb* memb = searchStructMemb(____BAH_COMPILER_VAR_345,s,elems);
if ((memb==null)) {
return null;
}
name = fnName.content;
char** ____BAH_COMPILER_VAR_346 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_346[2] = name;____BAH_COMPILER_VAR_346[1] = "__";____BAH_COMPILER_VAR_346[0] = memb->from;char * ____BAH_COMPILER_VAR_347 =__Bah_multiple_concat(____BAH_COMPILER_VAR_346, 3);name = ____BAH_COMPILER_VAR_347;
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
struct func* ____BAH_COMPILER_VAR_348 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_348->name = "";
____BAH_COMPILER_VAR_348->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_348->args->length = 0;
            ____BAH_COMPILER_VAR_348->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_348->from = "";
____BAH_COMPILER_VAR_348->file = "";
____BAH_COMPILER_VAR_348->line = 1;
struct func* nf = ____BAH_COMPILER_VAR_348;
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
struct string ____BAH_COMPILER_VAR_349 =string(t->cont);char * fnName = splitStringBefore(____BAH_COMPILER_VAR_349,"(");
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
char** ____BAH_COMPILER_VAR_350 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_350[6] = ";\n";____BAH_COMPILER_VAR_350[5] = m->def;____BAH_COMPILER_VAR_350[4] = " = ";____BAH_COMPILER_VAR_350[3] = m->name;____BAH_COMPILER_VAR_350[2] = sep;____BAH_COMPILER_VAR_350[1] = v->name;____BAH_COMPILER_VAR_350[0] = code;char * ____BAH_COMPILER_VAR_351 =__Bah_multiple_concat(____BAH_COMPILER_VAR_350, 7);code = ____BAH_COMPILER_VAR_351;
}
continue;
}
if ((string__hasPrefix(&cmpt,"[]")==1)) {
string__trimLeft(&cmpt,2);
char * cmptstr = string__str(&cmpt);
struct string elemCType = getCType(cmptstr,elems);
char * elemCTypeStr = string__str(&elemCType);
char** ____BAH_COMPILER_VAR_352 = alloca(17 * sizeof(char*));____BAH_COMPILER_VAR_352[16] = ");\n            ";____BAH_COMPILER_VAR_352[15] = elemCTypeStr;____BAH_COMPILER_VAR_352[14] = "->elemSize = sizeof(";____BAH_COMPILER_VAR_352[13] = m->name;____BAH_COMPILER_VAR_352[12] = sep;____BAH_COMPILER_VAR_352[11] = v->name;____BAH_COMPILER_VAR_352[10] = "->length = 0;\n            ";____BAH_COMPILER_VAR_352[9] = m->name;____BAH_COMPILER_VAR_352[8] = sep;____BAH_COMPILER_VAR_352[7] = v->name;____BAH_COMPILER_VAR_352[6] = ")));\n            ";____BAH_COMPILER_VAR_352[5] = elemCTypeStr;____BAH_COMPILER_VAR_352[4] = " = memoryAlloc(sizeof(array(";____BAH_COMPILER_VAR_352[3] = m->name;____BAH_COMPILER_VAR_352[2] = sep;____BAH_COMPILER_VAR_352[1] = v->name;____BAH_COMPILER_VAR_352[0] = code;char * ____BAH_COMPILER_VAR_353 =__Bah_multiple_concat(____BAH_COMPILER_VAR_352, 17);code = ____BAH_COMPILER_VAR_353;
continue;
}
if ((string__hasPrefix(&cmpt,"map:")==1)) {
string__trimLeft(&cmpt,4);
char** ____BAH_COMPILER_VAR_354 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_354[3] = " = mapWrapper();\n";____BAH_COMPILER_VAR_354[2] = m->name;____BAH_COMPILER_VAR_354[1] = sep;____BAH_COMPILER_VAR_354[0] = v->name;char * ____BAH_COMPILER_VAR_355 =__Bah_multiple_concat(____BAH_COMPILER_VAR_354, 4);char** ____BAH_COMPILER_VAR_356 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_356[1] = ____BAH_COMPILER_VAR_355;____BAH_COMPILER_VAR_356[0] = code;char * ____BAH_COMPILER_VAR_357 =__Bah_multiple_concat(____BAH_COMPILER_VAR_356, 2);code = ____BAH_COMPILER_VAR_357;
continue;
}
if ((string__hasPrefix(&cmpt,"chan:")==1)) {
string__trimLeft(&cmpt,5);
char** ____BAH_COMPILER_VAR_358 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_358[3] = " = channel();\n";____BAH_COMPILER_VAR_358[2] = m->name;____BAH_COMPILER_VAR_358[1] = sep;____BAH_COMPILER_VAR_358[0] = v->name;char * ____BAH_COMPILER_VAR_359 =__Bah_multiple_concat(____BAH_COMPILER_VAR_358, 4);char** ____BAH_COMPILER_VAR_360 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_360[1] = ____BAH_COMPILER_VAR_359;____BAH_COMPILER_VAR_360[0] = code;char * ____BAH_COMPILER_VAR_361 =__Bah_multiple_concat(____BAH_COMPILER_VAR_360, 2);code = ____BAH_COMPILER_VAR_361;
}
};
if ((s->isBinding==false)) {
long int found = 0;
i = 0;
for (; (i<len(s->methods)); ++i) {
struct func* m = s->methods->data[i];
if ((strcmp(m->name, "_init") == 0)) {
char** ____BAH_COMPILER_VAR_362 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_362[6] = ");\n";____BAH_COMPILER_VAR_362[5] = v->name;____BAH_COMPILER_VAR_362[4] = amp;____BAH_COMPILER_VAR_362[3] = "(";____BAH_COMPILER_VAR_362[2] = m->name;____BAH_COMPILER_VAR_362[1] = sep;____BAH_COMPILER_VAR_362[0] = v->name;char * ____BAH_COMPILER_VAR_363 =__Bah_multiple_concat(____BAH_COMPILER_VAR_362, 7);char** ____BAH_COMPILER_VAR_364 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_364[1] = ____BAH_COMPILER_VAR_363;____BAH_COMPILER_VAR_364[0] = NEXT_LINE;char * ____BAH_COMPILER_VAR_365 =__Bah_multiple_concat(____BAH_COMPILER_VAR_364, 2);NEXT_LINE = ____BAH_COMPILER_VAR_365;
++found;
}
else if ((strcmp(m->name, "_end") == 0)) {
if ((strcmp(sep, "->") == 0)) {
char** ____BAH_COMPILER_VAR_366 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_366[6] = ");\n";____BAH_COMPILER_VAR_366[5] = m->name;____BAH_COMPILER_VAR_366[4] = sep;____BAH_COMPILER_VAR_366[3] = v->name;____BAH_COMPILER_VAR_366[2] = ", ";____BAH_COMPILER_VAR_366[1] = v->name;____BAH_COMPILER_VAR_366[0] = "memoryOnEnd(";char * ____BAH_COMPILER_VAR_367 =__Bah_multiple_concat(____BAH_COMPILER_VAR_366, 7);char** ____BAH_COMPILER_VAR_368 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_368[1] = ____BAH_COMPILER_VAR_367;____BAH_COMPILER_VAR_368[0] = code;char * ____BAH_COMPILER_VAR_369 =__Bah_multiple_concat(____BAH_COMPILER_VAR_368, 2);code = ____BAH_COMPILER_VAR_369;
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
char** ____BAH_COMPILER_VAR_370 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_370[1] = intToStr(NB_COMP_VAR);____BAH_COMPILER_VAR_370[0] = "____BAH_COMPILER_VAR_";char * ____BAH_COMPILER_VAR_371 =__Bah_multiple_concat(____BAH_COMPILER_VAR_370, 2);char * name = ____BAH_COMPILER_VAR_371;
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

    unsigned int ____BAH_COMPILER_VAR_372 = i;
    __Bah_realocate_arr(a, ____BAH_COMPILER_VAR_372);
    a->data[____BAH_COMPILER_VAR_372] = (char)c;
};
return arrToStr(a);
};
void makeInit(){
char * name = "__BAH_init";
if ((isObject==true)) {
char** ____BAH_COMPILER_VAR_373 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_373[1] = pathToVarName(compilerState.currentFile);____BAH_COMPILER_VAR_373[0] = name;char * ____BAH_COMPILER_VAR_374 =__Bah_multiple_concat(____BAH_COMPILER_VAR_373, 2);name = ____BAH_COMPILER_VAR_374;
}
char * evals = "";
char** ____BAH_COMPILER_VAR_375 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_375[2] = "] = {";____BAH_COMPILER_VAR_375[1] = intToStr(len(compilerState.evals));____BAH_COMPILER_VAR_375[0] = "volatile struct __eval_binding __tmp__evals_bindings[";char * ____BAH_COMPILER_VAR_376 =__Bah_multiple_concat(____BAH_COMPILER_VAR_375, 3);char * evalsTMPDecl = ____BAH_COMPILER_VAR_376;
register long int i = 0;
for (; (i<len(compilerState.evals)); ++i) {
char * e = compilerState.evals->data[i];
char** ____BAH_COMPILER_VAR_377 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_377[4] = "\n        }";____BAH_COMPILER_VAR_377[3] = e;____BAH_COMPILER_VAR_377[2] = "\",\n            .evalFn = __Bah_eval_";____BAH_COMPILER_VAR_377[1] = e;____BAH_COMPILER_VAR_377[0] = "{\n            .name = \"";char * ____BAH_COMPILER_VAR_378 =__Bah_multiple_concat(____BAH_COMPILER_VAR_377, 5);char** ____BAH_COMPILER_VAR_379 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_379[1] = ____BAH_COMPILER_VAR_378;____BAH_COMPILER_VAR_379[0] = evalsTMPDecl;char * ____BAH_COMPILER_VAR_380 =__Bah_multiple_concat(____BAH_COMPILER_VAR_379, 2);evalsTMPDecl = ____BAH_COMPILER_VAR_380;
if ((i+1!=len(compilerState.evals))) {
char** ____BAH_COMPILER_VAR_381 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_381[1] = ",\n";____BAH_COMPILER_VAR_381[0] = evalsTMPDecl;char * ____BAH_COMPILER_VAR_382 =__Bah_multiple_concat(____BAH_COMPILER_VAR_381, 2);evalsTMPDecl = ____BAH_COMPILER_VAR_382;
}
else {
char** ____BAH_COMPILER_VAR_383 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_383[1] = "};";____BAH_COMPILER_VAR_383[0] = evalsTMPDecl;char * ____BAH_COMPILER_VAR_384 =__Bah_multiple_concat(____BAH_COMPILER_VAR_383, 2);evalsTMPDecl = ____BAH_COMPILER_VAR_384;
}
};
if ((len(compilerState.evals)!=0)) {
char** ____BAH_COMPILER_VAR_385 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_385[2] = ";";____BAH_COMPILER_VAR_385[1] = intToStr(len(compilerState.evals));____BAH_COMPILER_VAR_385[0] = "__evals_bindings = __tmp__evals_bindings; __evals_length = ";char * ____BAH_COMPILER_VAR_386 =__Bah_multiple_concat(____BAH_COMPILER_VAR_385, 3);evals = ____BAH_COMPILER_VAR_386;
}
else {
evalsTMPDecl = "";
}
char** ____BAH_COMPILER_VAR_387 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_387[4] = "() {\n        ";____BAH_COMPILER_VAR_387[3] = name;____BAH_COMPILER_VAR_387[2] = "\n    void __attribute__((optimize(\"O0\"))) ";____BAH_COMPILER_VAR_387[1] = evalsTMPDecl;____BAH_COMPILER_VAR_387[0] = "\n    ";char * ____BAH_COMPILER_VAR_388 =__Bah_multiple_concat(____BAH_COMPILER_VAR_387, 5);char** ____BAH_COMPILER_VAR_389 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_389[2] = "\n    };\n    ";____BAH_COMPILER_VAR_389[1] = evals;____BAH_COMPILER_VAR_389[0] = "\n        ";char * ____BAH_COMPILER_VAR_390 =__Bah_multiple_concat(____BAH_COMPILER_VAR_389, 3);OUTPUT = rope__add(OUTPUT, rope__add(rope(____BAH_COMPILER_VAR_388), rope__add(INIT, rope(____BAH_COMPILER_VAR_390))));
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
char** ____BAH_COMPILER_VAR_391 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_391[2] = ");\n";____BAH_COMPILER_VAR_391[1] = v->name;____BAH_COMPILER_VAR_391[0] = "RCP_decr(";char * ____BAH_COMPILER_VAR_392 =__Bah_multiple_concat(____BAH_COMPILER_VAR_391, 3);r = rope__add(r, rope(____BAH_COMPILER_VAR_392));
}
else if (strHasPrefix(v->type,"chan:")) {
char** ____BAH_COMPILER_VAR_393 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_393[2] = ");\n";____BAH_COMPILER_VAR_393[1] = v->name;____BAH_COMPILER_VAR_393[0] = "RCP_decr(";char * ____BAH_COMPILER_VAR_394 =__Bah_multiple_concat(____BAH_COMPILER_VAR_393, 3);r = rope__add(r, rope(____BAH_COMPILER_VAR_394));
}
else {
if (strHasPrefix(v->type,"map:")) {
struct variable* ____BAH_COMPILER_VAR_395 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_395->name = "";
____BAH_COMPILER_VAR_395->type = "";
____BAH_COMPILER_VAR_395->constVal = "";
____BAH_COMPILER_VAR_395->from = "";
struct variable* nv = ____BAH_COMPILER_VAR_395;
*nv = *v;
v = nv;
v->type = "mapWrapper*";
}
char isPointer = isRCPpointerType(v->type);
struct cStruct* s = searchStruct(v->type,elems);
if ((s!=null)&&(s->isBinding==false)) {
if ((isPointer==true)) {
char** ____BAH_COMPILER_VAR_396 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_396[2] = ");\n";____BAH_COMPILER_VAR_396[1] = v->name;____BAH_COMPILER_VAR_396[0] = "RCP_decr(";char * ____BAH_COMPILER_VAR_397 =__Bah_multiple_concat(____BAH_COMPILER_VAR_396, 3);r = rope__add(r, rope(____BAH_COMPILER_VAR_397));
}
else {
char** ____BAH_COMPILER_VAR_398 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_398[4] = "), 1);\n";____BAH_COMPILER_VAR_398[3] = v->name;____BAH_COMPILER_VAR_398[2] = ", sizeof(";____BAH_COMPILER_VAR_398[1] = v->name;____BAH_COMPILER_VAR_398[0] = "RCP_scanStack(&";char * ____BAH_COMPILER_VAR_399 =__Bah_multiple_concat(____BAH_COMPILER_VAR_398, 5);r = rope__add(r, rope(____BAH_COMPILER_VAR_399));
}
}
else if ((isPointer==true)) {
char** ____BAH_COMPILER_VAR_400 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_400[2] = ");\n";____BAH_COMPILER_VAR_400[1] = v->name;____BAH_COMPILER_VAR_400[0] = "RCP_decr(";char * ____BAH_COMPILER_VAR_401 =__Bah_multiple_concat(____BAH_COMPILER_VAR_400, 3);r = rope__add(r, rope(____BAH_COMPILER_VAR_401));
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
char** ____BAH_COMPILER_VAR_402 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_402[4] = "), 0);";____BAH_COMPILER_VAR_402[3] = v->name;____BAH_COMPILER_VAR_402[2] = ", sizeof(";____BAH_COMPILER_VAR_402[1] = v->name;____BAH_COMPILER_VAR_402[0] = "RCP_scanStack(&";char * ____BAH_COMPILER_VAR_403 =__Bah_multiple_concat(____BAH_COMPILER_VAR_402, 5);return rope(____BAH_COMPILER_VAR_403);
}
char** ____BAH_COMPILER_VAR_404 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_404[2] = ");";____BAH_COMPILER_VAR_404[1] = v->name;____BAH_COMPILER_VAR_404[0] = "RCP_incr(";char * ____BAH_COMPILER_VAR_405 =__Bah_multiple_concat(____BAH_COMPILER_VAR_404, 3);return rope(____BAH_COMPILER_VAR_405);
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
void endRCPscope(struct Elems* elems,__BAH_ARR_TYPE_variable excl){
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
OUTPUT = rope__add(OUTPUT, decrVar(v,elems));
}
};
};
void endRCPscopeLeaky(struct Elems* elems,struct variable* excl,char undef){
if ((RCPavailable()==false)) {
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
};
char * registerRCPvar(char * t,char * c,struct Elems* elems){
struct variable* ____BAH_COMPILER_VAR_406 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_406->name = "";
____BAH_COMPILER_VAR_406->type = "";
____BAH_COMPILER_VAR_406->constVal = "";
____BAH_COMPILER_VAR_406->from = "";
struct variable* av = ____BAH_COMPILER_VAR_406;
av->type = t;
av->declScope = elems;
av->name = genCompilerVar();

    unsigned int ____BAH_COMPILER_VAR_407 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_407);
    elems->vars->data[____BAH_COMPILER_VAR_407] = av;
struct string cType = getCType(av->type,elems);
if (isGlobal()) {
char** ____BAH_COMPILER_VAR_408 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_408[3] = ";";____BAH_COMPILER_VAR_408[2] = av->name;____BAH_COMPILER_VAR_408[1] = " ";____BAH_COMPILER_VAR_408[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_409 =__Bah_multiple_concat(____BAH_COMPILER_VAR_408, 4);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_409));
char** ____BAH_COMPILER_VAR_410 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_410[3] = ";";____BAH_COMPILER_VAR_410[2] = c;____BAH_COMPILER_VAR_410[1] = " =";____BAH_COMPILER_VAR_410[0] = av->name;char * ____BAH_COMPILER_VAR_411 =__Bah_multiple_concat(____BAH_COMPILER_VAR_410, 4);INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_411));
}
else {
char** ____BAH_COMPILER_VAR_412 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_412[5] = ";";____BAH_COMPILER_VAR_412[4] = c;____BAH_COMPILER_VAR_412[3] = " =";____BAH_COMPILER_VAR_412[2] = av->name;____BAH_COMPILER_VAR_412[1] = " ";____BAH_COMPILER_VAR_412[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_413 =__Bah_multiple_concat(____BAH_COMPILER_VAR_412, 6);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_413));
}
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
char * ____BAH_COMPILER_VAR_415 =currentFn->name;
        char ____BAH_COMPILER_VAR_414 = 0;
        for(int i=noVOfns->length-1; i!=-1;i--) {
            if (noVOfns->data[i] != 0 && strcmp(noVOfns->data[i], ____BAH_COMPILER_VAR_415) == 0) {
                ____BAH_COMPILER_VAR_414=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_414) {
return false;
}
}
return true;
};
struct verboseOutVar verboseOutTransformVar(struct variable* v,char * cont,struct Elems* elems){
struct verboseOutVar ____BAH_COMPILER_VAR_416 = {};
struct verboseOutVar rv = ____BAH_COMPILER_VAR_416;
char * ogCont = cont;
if ((strcmp(v->type, "cpstring") == 0)) {
char** ____BAH_COMPILER_VAR_417 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_417[2] = ")";____BAH_COMPILER_VAR_417[1] = cont;____BAH_COMPILER_VAR_417[0] = "__Bah_safe_string(";char * ____BAH_COMPILER_VAR_418 =__Bah_multiple_concat(____BAH_COMPILER_VAR_417, 3);cont = ____BAH_COMPILER_VAR_418;
}
char** ____BAH_COMPILER_VAR_419 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_419[1] = cont;____BAH_COMPILER_VAR_419[0] = ", ";char * ____BAH_COMPILER_VAR_420 =__Bah_multiple_concat(____BAH_COMPILER_VAR_419, 2);cont = ____BAH_COMPILER_VAR_420;
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
char** ____BAH_COMPILER_VAR_421 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_421[1] = "{";____BAH_COMPILER_VAR_421[0] = ASCII_RESET;char * ____BAH_COMPILER_VAR_422 =__Bah_multiple_concat(____BAH_COMPILER_VAR_421, 2);ct = ____BAH_COMPILER_VAR_422;
cont = "";
register long int i = 0;
for (; (i<len(s->members)); ++i) {
struct variable* m = s->members->data[i];
char** ____BAH_COMPILER_VAR_423 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_423[4] = m->name;____BAH_COMPILER_VAR_423[3] = ".";____BAH_COMPILER_VAR_423[2] = ")";____BAH_COMPILER_VAR_423[1] = ogCont;____BAH_COMPILER_VAR_423[0] = "(";char * ____BAH_COMPILER_VAR_424 =__Bah_multiple_concat(____BAH_COMPILER_VAR_423, 5);struct verboseOutVar mv = verboseOutTransformVar(m,____BAH_COMPILER_VAR_424,elems);
if ((i!=0)) {
char** ____BAH_COMPILER_VAR_425 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_425[1] = ", ";____BAH_COMPILER_VAR_425[0] = ct;char * ____BAH_COMPILER_VAR_426 =__Bah_multiple_concat(____BAH_COMPILER_VAR_425, 2);ct = ____BAH_COMPILER_VAR_426;
}
char** ____BAH_COMPILER_VAR_427 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_427[1] = mv.markup;____BAH_COMPILER_VAR_427[0] = ct;char * ____BAH_COMPILER_VAR_428 =__Bah_multiple_concat(____BAH_COMPILER_VAR_427, 2);ct = ____BAH_COMPILER_VAR_428;
char** ____BAH_COMPILER_VAR_429 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_429[1] = mv.content;____BAH_COMPILER_VAR_429[0] = cont;char * ____BAH_COMPILER_VAR_430 =__Bah_multiple_concat(____BAH_COMPILER_VAR_429, 2);cont = ____BAH_COMPILER_VAR_430;
};
char** ____BAH_COMPILER_VAR_431 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_431[1] = "}";____BAH_COMPILER_VAR_431[0] = ct;char * ____BAH_COMPILER_VAR_432 =__Bah_multiple_concat(____BAH_COMPILER_VAR_431, 2);ct = ____BAH_COMPILER_VAR_432;
}
}
char** ____BAH_COMPILER_VAR_433 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_433[6] = ASCII_RESET;____BAH_COMPILER_VAR_433[5] = ct;____BAH_COMPILER_VAR_433[4] = ASCII_MAGENTA;____BAH_COMPILER_VAR_433[3] = " = ";____BAH_COMPILER_VAR_433[2] = ASCII_RESET;____BAH_COMPILER_VAR_433[1] = v->name;____BAH_COMPILER_VAR_433[0] = ASCII_BLUE;char * ____BAH_COMPILER_VAR_434 =__Bah_multiple_concat(____BAH_COMPILER_VAR_433, 7);rv.markup = ____BAH_COMPILER_VAR_434;
rv.content = cont;
return rv;
};
struct verboseOutVar verboseOutTransformTok(struct Tok* t,struct Elems* elems){
if ((t->type==TOKEN_TYPE_VAR)&&(t->isOper==false)) {
struct variable* v = searchVar(t->cont,elems);
if ((v==null)) {
struct verboseOutVar ____BAH_COMPILER_VAR_435 = {};
struct verboseOutVar rv = ____BAH_COMPILER_VAR_435;
return rv;
}
}
struct variable ____BAH_COMPILER_VAR_436 = {};
____BAH_COMPILER_VAR_436.name = "";
____BAH_COMPILER_VAR_436.type = "";
____BAH_COMPILER_VAR_436.constVal = "";
____BAH_COMPILER_VAR_436.from = "";
____BAH_COMPILER_VAR_436.name = "(value)";
____BAH_COMPILER_VAR_436.type = getTypeFromToken(t,true,elems);
struct variable v = ____BAH_COMPILER_VAR_436;
return verboseOutTransformVar(&v,t->cont,elems);
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
char** ____BAH_COMPILER_VAR_437 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_437[1] = ", ";____BAH_COMPILER_VAR_437[0] = fnArgs;char * ____BAH_COMPILER_VAR_438 =__Bah_multiple_concat(____BAH_COMPILER_VAR_437, 2);fnArgs = ____BAH_COMPILER_VAR_438;
}
struct Tok t = args->data[j];
struct verboseOutVar v = verboseOutTransformVar(a,t.cont,elems);
char** ____BAH_COMPILER_VAR_439 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_439[1] = v.markup;____BAH_COMPILER_VAR_439[0] = fnArgs;char * ____BAH_COMPILER_VAR_440 =__Bah_multiple_concat(____BAH_COMPILER_VAR_439, 2);fnArgs = ____BAH_COMPILER_VAR_440;
char** ____BAH_COMPILER_VAR_441 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_441[1] = v.content;____BAH_COMPILER_VAR_441[0] = fnArgsValues;char * ____BAH_COMPILER_VAR_442 =__Bah_multiple_concat(____BAH_COMPILER_VAR_441, 2);fnArgsValues = ____BAH_COMPILER_VAR_442;
};
char** ____BAH_COMPILER_VAR_443 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_443[2] = intToStr(lineNb);____BAH_COMPILER_VAR_443[1] = ":";____BAH_COMPILER_VAR_443[0] = compilerState.currentFile;char * ____BAH_COMPILER_VAR_444 =__Bah_multiple_concat(____BAH_COMPILER_VAR_443, 3);char * line = ____BAH_COMPILER_VAR_444;
char** ____BAH_COMPILER_VAR_445 = alloca(13 * sizeof(char*));____BAH_COMPILER_VAR_445[12] = ");\n    //\n    ";____BAH_COMPILER_VAR_445[11] = fnArgsValues;____BAH_COMPILER_VAR_445[10] = "\\n\"";____BAH_COMPILER_VAR_445[9] = ASCII_RESET;____BAH_COMPILER_VAR_445[8] = line;____BAH_COMPILER_VAR_445[7] = ASCII_GREEN;____BAH_COMPILER_VAR_445[6] = ") -> ";____BAH_COMPILER_VAR_445[5] = fnArgs;____BAH_COMPILER_VAR_445[4] = "(";____BAH_COMPILER_VAR_445[3] = ASCII_RESET;____BAH_COMPILER_VAR_445[2] = fn->name;____BAH_COMPILER_VAR_445[1] = nameColor;____BAH_COMPILER_VAR_445[0] = "\n    //Verbose Runtime\n        printf(\"[VO] calling: ";char * ____BAH_COMPILER_VAR_446 =__Bah_multiple_concat(____BAH_COMPILER_VAR_445, 13);struct rope* verboseOut = rope(____BAH_COMPILER_VAR_446);
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
char** ____BAH_COMPILER_VAR_447 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_447[1] = nvo.content;____BAH_COMPILER_VAR_447[0] = pvo.content;char * ____BAH_COMPILER_VAR_448 =__Bah_multiple_concat(____BAH_COMPILER_VAR_447, 2);char * values = ____BAH_COMPILER_VAR_448;
char** ____BAH_COMPILER_VAR_449 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_449[2] = intToStr(lineNb);____BAH_COMPILER_VAR_449[1] = ":";____BAH_COMPILER_VAR_449[0] = compilerState.currentFile;char * ____BAH_COMPILER_VAR_450 =__Bah_multiple_concat(____BAH_COMPILER_VAR_449, 3);char * line = ____BAH_COMPILER_VAR_450;
char** ____BAH_COMPILER_VAR_451 = alloca(11 * sizeof(char*));____BAH_COMPILER_VAR_451[10] = ");\n    //\n    ";____BAH_COMPILER_VAR_451[9] = values;____BAH_COMPILER_VAR_451[8] = "\\n\"";____BAH_COMPILER_VAR_451[7] = ASCII_RESET;____BAH_COMPILER_VAR_451[6] = line;____BAH_COMPILER_VAR_451[5] = ASCII_GREEN;____BAH_COMPILER_VAR_451[4] = " -> ";____BAH_COMPILER_VAR_451[3] = nvo.markup;____BAH_COMPILER_VAR_451[2] = " AND ";____BAH_COMPILER_VAR_451[1] = pvo.markup;____BAH_COMPILER_VAR_451[0] = "\n    //Verbose Runtime\n        printf(\"[VO]    oper: ";char * ____BAH_COMPILER_VAR_452 =__Bah_multiple_concat(____BAH_COMPILER_VAR_451, 11);struct rope* verboseOut = rope(____BAH_COMPILER_VAR_452);
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
struct fileStream ____BAH_COMPILER_VAR_453 = {};
struct fileStream fs = ____BAH_COMPILER_VAR_453;
char** ____BAH_COMPILER_VAR_454 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_454[1] = "cache/cache.json";____BAH_COMPILER_VAR_454[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_455 =__Bah_multiple_concat(____BAH_COMPILER_VAR_454, 2);fileStream__open(&fs,____BAH_COMPILER_VAR_455,"r");
if ((fileStream__isValid(&fs)==0)||(fileStream__getSize(&fs)==0)) {
char** ____BAH_COMPILER_VAR_456 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_456[1] = "cache";____BAH_COMPILER_VAR_456[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_457 =__Bah_multiple_concat(____BAH_COMPILER_VAR_456, 2);mkdir(____BAH_COMPILER_VAR_457,S_IRWXU);
char** ____BAH_COMPILER_VAR_458 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_458[1] = "cache/cache.json";____BAH_COMPILER_VAR_458[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_459 =__Bah_multiple_concat(____BAH_COMPILER_VAR_458, 2);fileStream__createFile(&fs,____BAH_COMPILER_VAR_459);
return;
}
if ((fileStream__getSize(&fs)>0)) {
char * ____BAH_COMPILER_VAR_460 =fileStream__readContent(&fs);struct jsonElement* j = parseJson(____BAH_COMPILER_VAR_460);
fileStream__close(&fs);
array(struct cacheFile**)* ____BAH_COMPILER_VAR_461 = &cache;
struct cacheFile*** ____BAH_COMPILER_VAR_462 = 0;
char ** ____BAH_COMPILER_VAR_464 = (char **)((char*)(____BAH_COMPILER_VAR_462) + offsetof(struct cacheFile, file));
struct reflectElement ____BAH_COMPILER_VAR_465 = __reflect(____BAH_COMPILER_VAR_464, sizeof(char *), "cpstring", "file", 0, 0, 0, 0, offsetof(struct cacheFile, file));
long int* ____BAH_COMPILER_VAR_466 = (long int*)((char*)(____BAH_COMPILER_VAR_462) + offsetof(struct cacheFile, last));
struct reflectElement ____BAH_COMPILER_VAR_467 = __reflect(____BAH_COMPILER_VAR_466, sizeof(long int), "int", "last", 0, 0, 0, 0, offsetof(struct cacheFile, last));
char ** ____BAH_COMPILER_VAR_468 = (char **)((char*)(____BAH_COMPILER_VAR_462) + offsetof(struct cacheFile, ver));
struct reflectElement ____BAH_COMPILER_VAR_469 = __reflect(____BAH_COMPILER_VAR_468, sizeof(char *), "cpstring", "ver", 0, 0, 0, 0, offsetof(struct cacheFile, ver));
long int* ____BAH_COMPILER_VAR_470 = (long int*)((char*)(____BAH_COMPILER_VAR_462) + offsetof(struct cacheFile, date));
struct reflectElement ____BAH_COMPILER_VAR_471 = __reflect(____BAH_COMPILER_VAR_470, sizeof(long int), "int", "date", 0, 0, 0, 0, offsetof(struct cacheFile, date));
long int* ____BAH_COMPILER_VAR_472 = (long int*)((char*)(____BAH_COMPILER_VAR_462) + offsetof(struct cacheFile, mem));
struct reflectElement ____BAH_COMPILER_VAR_473 = __reflect(____BAH_COMPILER_VAR_472, sizeof(long int), "int", "mem", 0, 0, 0, 0, offsetof(struct cacheFile, mem));
long int* ____BAH_COMPILER_VAR_474 = (long int*)((char*)(____BAH_COMPILER_VAR_462) + offsetof(struct cacheFile, opti));
struct reflectElement ____BAH_COMPILER_VAR_475 = __reflect(____BAH_COMPILER_VAR_474, sizeof(long int), "int", "opti", 0, 0, 0, 0, offsetof(struct cacheFile, opti));
array(char *)** ____BAH_COMPILER_VAR_476 = (array(char *)**)((char*)(____BAH_COMPILER_VAR_462) + offsetof(struct cacheFile, files));
char ** ____BAH_COMPILER_VAR_477 = 0;
struct reflectElement ____BAH_COMPILER_VAR_478 = __reflect(____BAH_COMPILER_VAR_477, sizeof(char *), "cpstring", "", 0, 0, 0, 0, 0);

        struct reflectElement ____BAH_COMPILER_VAR_479 = ____BAH_COMPILER_VAR_478;
        struct reflectElement ____BAH_COMPILER_VAR_480 = __reflect(____BAH_COMPILER_VAR_476, sizeof(array(char *)*), "[]cpstring", "files", 1, &____BAH_COMPILER_VAR_479, 0, 0, offsetof(struct cacheFile, files));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_463 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_463->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_463->length = 7;
        ____BAH_COMPILER_VAR_463->data = memoryAlloc(____BAH_COMPILER_VAR_463->length * ____BAH_COMPILER_VAR_463->elemSize);
        ____BAH_COMPILER_VAR_463->data[0] = ____BAH_COMPILER_VAR_465;
____BAH_COMPILER_VAR_463->data[1] = ____BAH_COMPILER_VAR_467;
____BAH_COMPILER_VAR_463->data[2] = ____BAH_COMPILER_VAR_469;
____BAH_COMPILER_VAR_463->data[3] = ____BAH_COMPILER_VAR_471;
____BAH_COMPILER_VAR_463->data[4] = ____BAH_COMPILER_VAR_473;
____BAH_COMPILER_VAR_463->data[5] = ____BAH_COMPILER_VAR_475;
____BAH_COMPILER_VAR_463->data[6] = ____BAH_COMPILER_VAR_480;
struct reflectElement ____BAH_COMPILER_VAR_481 = __reflect(____BAH_COMPILER_VAR_462, sizeof(struct cacheFile), "cacheFile**", "", 0, 0, 1, ____BAH_COMPILER_VAR_463, 0);

        struct reflectElement ____BAH_COMPILER_VAR_482 = ____BAH_COMPILER_VAR_481;
        struct reflectElement ____BAH_COMPILER_VAR_483 = __reflect(____BAH_COMPILER_VAR_461, sizeof(array(struct cacheFile**)*), "[]cacheFile**", "&cache", 1, &____BAH_COMPILER_VAR_482, 0, 0, 0);
jsonElement__scan(j,____BAH_COMPILER_VAR_483);
}
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
struct cacheFile* ____BAH_COMPILER_VAR_484 = memoryAlloc(sizeof(struct cacheFile));
____BAH_COMPILER_VAR_484->files = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_484->files->length = 0;
            ____BAH_COMPILER_VAR_484->files->elemSize = sizeof(char *);
            struct cacheFile* c = ____BAH_COMPILER_VAR_484;
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

    unsigned int ____BAH_COMPILER_VAR_485 = len(cache);
    __Bah_realocate_arr(cache, ____BAH_COMPILER_VAR_485);
    cache->data[____BAH_COMPILER_VAR_485] = c;
};
void writeCache(){
struct fileStream ____BAH_COMPILER_VAR_486 = {};
struct fileStream fs = ____BAH_COMPILER_VAR_486;
char** ____BAH_COMPILER_VAR_487 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_487[1] = "cache/cache.json";____BAH_COMPILER_VAR_487[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_488 =__Bah_multiple_concat(____BAH_COMPILER_VAR_487, 2);fileStream__open(&fs,____BAH_COMPILER_VAR_488,"w");
array(struct cacheFile*)* ____BAH_COMPILER_VAR_489 = cache;
struct cacheFile** ____BAH_COMPILER_VAR_490 = 0;
char ** ____BAH_COMPILER_VAR_492 = (char **)((char*)(____BAH_COMPILER_VAR_490) + offsetof(struct cacheFile, file));
struct reflectElement ____BAH_COMPILER_VAR_493 = __reflect(____BAH_COMPILER_VAR_492, sizeof(char *), "cpstring", "file", 0, 0, 0, 0, offsetof(struct cacheFile, file));
long int* ____BAH_COMPILER_VAR_494 = (long int*)((char*)(____BAH_COMPILER_VAR_490) + offsetof(struct cacheFile, last));
struct reflectElement ____BAH_COMPILER_VAR_495 = __reflect(____BAH_COMPILER_VAR_494, sizeof(long int), "int", "last", 0, 0, 0, 0, offsetof(struct cacheFile, last));
char ** ____BAH_COMPILER_VAR_496 = (char **)((char*)(____BAH_COMPILER_VAR_490) + offsetof(struct cacheFile, ver));
struct reflectElement ____BAH_COMPILER_VAR_497 = __reflect(____BAH_COMPILER_VAR_496, sizeof(char *), "cpstring", "ver", 0, 0, 0, 0, offsetof(struct cacheFile, ver));
long int* ____BAH_COMPILER_VAR_498 = (long int*)((char*)(____BAH_COMPILER_VAR_490) + offsetof(struct cacheFile, date));
struct reflectElement ____BAH_COMPILER_VAR_499 = __reflect(____BAH_COMPILER_VAR_498, sizeof(long int), "int", "date", 0, 0, 0, 0, offsetof(struct cacheFile, date));
long int* ____BAH_COMPILER_VAR_500 = (long int*)((char*)(____BAH_COMPILER_VAR_490) + offsetof(struct cacheFile, mem));
struct reflectElement ____BAH_COMPILER_VAR_501 = __reflect(____BAH_COMPILER_VAR_500, sizeof(long int), "int", "mem", 0, 0, 0, 0, offsetof(struct cacheFile, mem));
long int* ____BAH_COMPILER_VAR_502 = (long int*)((char*)(____BAH_COMPILER_VAR_490) + offsetof(struct cacheFile, opti));
struct reflectElement ____BAH_COMPILER_VAR_503 = __reflect(____BAH_COMPILER_VAR_502, sizeof(long int), "int", "opti", 0, 0, 0, 0, offsetof(struct cacheFile, opti));
array(char *)** ____BAH_COMPILER_VAR_504 = (array(char *)**)((char*)(____BAH_COMPILER_VAR_490) + offsetof(struct cacheFile, files));
char ** ____BAH_COMPILER_VAR_505 = 0;
struct reflectElement ____BAH_COMPILER_VAR_506 = __reflect(____BAH_COMPILER_VAR_505, sizeof(char *), "cpstring", "", 0, 0, 0, 0, 0);

        struct reflectElement ____BAH_COMPILER_VAR_507 = ____BAH_COMPILER_VAR_506;
        struct reflectElement ____BAH_COMPILER_VAR_508 = __reflect(____BAH_COMPILER_VAR_504, sizeof(array(char *)*), "[]cpstring", "files", 1, &____BAH_COMPILER_VAR_507, 0, 0, offsetof(struct cacheFile, files));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_491 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_491->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_491->length = 7;
        ____BAH_COMPILER_VAR_491->data = memoryAlloc(____BAH_COMPILER_VAR_491->length * ____BAH_COMPILER_VAR_491->elemSize);
        ____BAH_COMPILER_VAR_491->data[0] = ____BAH_COMPILER_VAR_493;
____BAH_COMPILER_VAR_491->data[1] = ____BAH_COMPILER_VAR_495;
____BAH_COMPILER_VAR_491->data[2] = ____BAH_COMPILER_VAR_497;
____BAH_COMPILER_VAR_491->data[3] = ____BAH_COMPILER_VAR_499;
____BAH_COMPILER_VAR_491->data[4] = ____BAH_COMPILER_VAR_501;
____BAH_COMPILER_VAR_491->data[5] = ____BAH_COMPILER_VAR_503;
____BAH_COMPILER_VAR_491->data[6] = ____BAH_COMPILER_VAR_508;
struct reflectElement ____BAH_COMPILER_VAR_509 = __reflect(____BAH_COMPILER_VAR_490, sizeof(struct cacheFile), "cacheFile*", "", 0, 0, 1, ____BAH_COMPILER_VAR_491, 0);

        struct reflectElement ____BAH_COMPILER_VAR_510 = ____BAH_COMPILER_VAR_509;
        struct reflectElement ____BAH_COMPILER_VAR_511 = __reflect(____BAH_COMPILER_VAR_489, sizeof(array(struct cacheFile*)*), "[]cacheFile*", "cache", 1, &____BAH_COMPILER_VAR_510, 0, 0, 0);
char * ____BAH_COMPILER_VAR_512 =toJson(____BAH_COMPILER_VAR_511);fileStream__writeFile(&fs,____BAH_COMPILER_VAR_512);
fileStream__close(&fs);
};
char isValidCacheFile(struct cacheFile* cf){
if ((cf->last!=getLastModified(cf->file))) {
return false;
}
char** ____BAH_COMPILER_VAR_513 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_513[5] = ".o.o";____BAH_COMPILER_VAR_513[4] = intToStr(cf->opti);____BAH_COMPILER_VAR_513[3] = intToStr(cf->mem);____BAH_COMPILER_VAR_513[2] = pathToVarName(cf->file);____BAH_COMPILER_VAR_513[1] = "cache/";____BAH_COMPILER_VAR_513[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_514 =__Bah_multiple_concat(____BAH_COMPILER_VAR_513, 6);if ((fileExists(____BAH_COMPILER_VAR_514)==0)) {
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
char** ____BAH_COMPILER_VAR_515 = alloca(15 * sizeof(char*));____BAH_COMPILER_VAR_515[14] = val;____BAH_COMPILER_VAR_515[13] = "] = ";____BAH_COMPILER_VAR_515[12] = nLength;____BAH_COMPILER_VAR_515[11] = "->data[";____BAH_COMPILER_VAR_515[10] = nstr;____BAH_COMPILER_VAR_515[9] = preVal;____BAH_COMPILER_VAR_515[8] = ");\n    ";____BAH_COMPILER_VAR_515[7] = nLength;____BAH_COMPILER_VAR_515[6] = ", ";____BAH_COMPILER_VAR_515[5] = nstr;____BAH_COMPILER_VAR_515[4] = ";\n    __Bah_realocate_arr(";____BAH_COMPILER_VAR_515[3] = nLengthStr;____BAH_COMPILER_VAR_515[2] = " = ";____BAH_COMPILER_VAR_515[1] = nLength;____BAH_COMPILER_VAR_515[0] = "\n    unsigned int ";char * ____BAH_COMPILER_VAR_516 =__Bah_multiple_concat(____BAH_COMPILER_VAR_515, 15);return ____BAH_COMPILER_VAR_516;
};
char * genConcat(__BAH_ARR_TYPE_cpstring strs,struct Elems* elems){
char * buff = genCompilerVar();
char** ____BAH_COMPILER_VAR_517 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_517[4] = " * sizeof(char*));";____BAH_COMPILER_VAR_517[3] = intToStr(len(strs));____BAH_COMPILER_VAR_517[2] = " = alloca(";____BAH_COMPILER_VAR_517[1] = buff;____BAH_COMPILER_VAR_517[0] = "char** ";char * ____BAH_COMPILER_VAR_518 =__Bah_multiple_concat(____BAH_COMPILER_VAR_517, 5);char * r = ____BAH_COMPILER_VAR_518;
register long int i = 0;
for (; (i<len(strs)); ++i) {
char** ____BAH_COMPILER_VAR_519 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_519[5] = ";";____BAH_COMPILER_VAR_519[4] = strs->data[i];____BAH_COMPILER_VAR_519[3] = "] = ";____BAH_COMPILER_VAR_519[2] = intToStr(len(strs)-i-1);____BAH_COMPILER_VAR_519[1] = "[";____BAH_COMPILER_VAR_519[0] = buff;char * ____BAH_COMPILER_VAR_520 =__Bah_multiple_concat(____BAH_COMPILER_VAR_519, 6);char** ____BAH_COMPILER_VAR_521 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_521[1] = ____BAH_COMPILER_VAR_520;____BAH_COMPILER_VAR_521[0] = r;char * ____BAH_COMPILER_VAR_522 =__Bah_multiple_concat(____BAH_COMPILER_VAR_521, 2);r = ____BAH_COMPILER_VAR_522;
};
if (isGlobal()) {
INIT = rope__add(INIT, rope(r));
}
else {
OUTPUT = rope__add(OUTPUT, rope(r));
}
char** ____BAH_COMPILER_VAR_523 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_523[4] = ")";____BAH_COMPILER_VAR_523[3] = intToStr(len(strs));____BAH_COMPILER_VAR_523[2] = ", ";____BAH_COMPILER_VAR_523[1] = buff;____BAH_COMPILER_VAR_523[0] = "__Bah_multiple_concat(";char * ____BAH_COMPILER_VAR_524 =__Bah_multiple_concat(____BAH_COMPILER_VAR_523, 5);char * rstr = registerRCPvar("cpstring",____BAH_COMPILER_VAR_524,elems);
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

                struct string ____BAH_COMPILER_VAR_525 = string(v->name);
                if ((isRCPpointerType(v->type)==false)&&(strcmp(v->type, "reflectElement") != 0)&&(string__hasPrefix(&____BAH_COMPILER_VAR_525,"____BAH_COMPILER_VAR_")==false)) {
struct cStruct* s = searchStruct(v->type,elems);
if ((s!=null)&&(currentFn!=null)) {
char** ____BAH_COMPILER_VAR_526 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_526[6] = ") could be passed by reference.";____BAH_COMPILER_VAR_526[5] = v->type;____BAH_COMPILER_VAR_526[4] = "\e[0m (";____BAH_COMPILER_VAR_526[3] = v->name;____BAH_COMPILER_VAR_526[2] = "()\e[0m: argument \e[1;37m";____BAH_COMPILER_VAR_526[1] = currentFn->name;____BAH_COMPILER_VAR_526[0] = "in \e[1;37m";char * ____BAH_COMPILER_VAR_527 =__Bah_multiple_concat(____BAH_COMPILER_VAR_526, 7);throwNoticeLine(____BAH_COMPILER_VAR_527,currentFn->line);
}
}
}
};
};
char isExprExpensive(struct Tok* t){
if ((t->isExpensive==true)) {
return true;
}
if ((t->type!=TOKEN_TYPE_VAR)&&(t->type!=TOKEN_TYPE_INT)&&(t->type!=TOKEN_TYPE_FLOAT)) {
return true;
}
return false;
};
struct Elems* dupElems(struct Elems* e);
void parseLines(__BAH_ARR_TYPE_Tok l,struct Elems* elems);
void * currGen;
struct genericFunc {
array(struct Tok)* tokens;
array(struct func*)* declared;
struct func* baseFn;
struct Tok* tokenName;
struct Tok* callToken;
};
struct func* genericFunc__dupBaseFn(struct genericFunc* this){
struct func* ____BAH_COMPILER_VAR_528 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_528->name = "";
____BAH_COMPILER_VAR_528->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_528->args->length = 0;
            ____BAH_COMPILER_VAR_528->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_528->from = "";
____BAH_COMPILER_VAR_528->file = "";
____BAH_COMPILER_VAR_528->line = 1;
struct func* r = ____BAH_COMPILER_VAR_528;
r->name = this->baseFn->name;
register long int i = 0;
for (; (i<len(this->baseFn->args)); ++i) {
struct variable* a = this->baseFn->args->data[i];
struct variable* ____BAH_COMPILER_VAR_529 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_529->name = "";
____BAH_COMPILER_VAR_529->type = "";
____BAH_COMPILER_VAR_529->constVal = "";
____BAH_COMPILER_VAR_529->from = "";
struct variable* na = ____BAH_COMPILER_VAR_529;
*na = *a;

    unsigned int ____BAH_COMPILER_VAR_530 = i;
    __Bah_realocate_arr(r->args, ____BAH_COMPILER_VAR_530);
    r->args->data[____BAH_COMPILER_VAR_530] = na;
};
r->returns = this->baseFn->returns;
return r;
};
void genericFunc__setCurrGeneric(struct genericFunc* this,struct Tok* t){
this->callToken = t;
};
char genericFunc__isAlreadyDecl(struct genericFunc* this,char * n){
register long int i = 0;
for (; (i<len(this->declared)); ++i) {
if ((strcmp(this->declared->data[i]->name, n) == 0)) {
return true;
}
};
return false;
};
void genericFunc__declare(struct genericFunc* this,struct func* fn,struct Elems* elems){
struct rope* oldOut = OUTPUT;

    unsigned int ____BAH_COMPILER_VAR_531 = len(this->declared);
    __Bah_realocate_arr(this->declared, ____BAH_COMPILER_VAR_531);
    this->declared->data[____BAH_COMPILER_VAR_531] = fn;

                struct string ____BAH_COMPILER_VAR_532 = getCType(fn->returns->type,elems);
                char** ____BAH_COMPILER_VAR_533 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_533[3] = "(";____BAH_COMPILER_VAR_533[2] = fn->name;____BAH_COMPILER_VAR_533[1] = " __generic_";____BAH_COMPILER_VAR_533[0] = string__str(&____BAH_COMPILER_VAR_532);char * ____BAH_COMPILER_VAR_534 =__Bah_multiple_concat(____BAH_COMPILER_VAR_533, 4);OUTPUT = rope(____BAH_COMPILER_VAR_534);
struct Elems* fnElems = dupElems(elems);
register long int i = 0;
for (; (i<len(fn->args)); ++i) {
struct variable* arg = fn->args->data[i];
arg->declScope = elems;
arg->isArg = true;

    unsigned int ____BAH_COMPILER_VAR_535 = len(fnElems->vars);
    __Bah_realocate_arr(fnElems->vars, ____BAH_COMPILER_VAR_535);
    fnElems->vars->data[____BAH_COMPILER_VAR_535] = arg;

                struct string ____BAH_COMPILER_VAR_536 = getCType(arg->type,elems);
                char** ____BAH_COMPILER_VAR_537 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_537[2] = arg->name;____BAH_COMPILER_VAR_537[1] = " ";____BAH_COMPILER_VAR_537[0] = string__str(&____BAH_COMPILER_VAR_536);char * ____BAH_COMPILER_VAR_538 =__Bah_multiple_concat(____BAH_COMPILER_VAR_537, 3);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_538));
if ((i+1<len(fn->args))) {
OUTPUT = rope__add(OUTPUT, rope(", "));
}
};
OUTPUT = rope__add(OUTPUT, rope(") {\n"));
beginRCPscope(fnElems,fn->args);
struct Elems* ocurrFnElems = compilerState.currFnElems;
void * oCurrGen = currGen;
currGen = this;
struct func* oCurrFn = currentFn;
compilerState.currFnElems = fnElems;
parseLines(this->tokens,fnElems);
OPTI_checkFuncScopeRef(fnElems);
compilerState.currFnElems = ocurrFnElems;
currentFn = oCurrFn;
currGen = oCurrGen;
if ((fn->returned==false)) {
if (__builtin_expect((strlen(fn->returns->type)>0), 0)) {
char** ____BAH_COMPILER_VAR_539 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_539[2] = "' is not returned.";____BAH_COMPILER_VAR_539[1] = fn->name;____BAH_COMPILER_VAR_539[0] = "Function '";char * ____BAH_COMPILER_VAR_540 =__Bah_multiple_concat(____BAH_COMPILER_VAR_539, 3);throwErr(this->tokenName,____BAH_COMPILER_VAR_540);
}
endRCPscope(fnElems,fn->args);
}
else {
}
struct rope* code = rope__add(OUTPUT, rope("};\n"));
OUTPUT = oldOut;
char** ____BAH_COMPILER_VAR_541 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_541[1] = rope__toStr(code);____BAH_COMPILER_VAR_541[0] = rope__toStr(postDeclHandle);char * ____BAH_COMPILER_VAR_542 =__Bah_multiple_concat(____BAH_COMPILER_VAR_541, 2);OUTPUT->totalLen = OUTPUT->totalLen+ropeSet(postDeclHandle,____BAH_COMPILER_VAR_542);
};
array(struct genericFunc*)* generics;
void advertiseGeneric(){
if ((currGen==null)) {
return;
}
struct genericFunc* gen = currGen;
char** ____BAH_COMPILER_VAR_543 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_543[3] = intToStr(gen->callToken->line);____BAH_COMPILER_VAR_543[2] = ":";____BAH_COMPILER_VAR_543[1] = compilerState.currentFile;____BAH_COMPILER_VAR_543[0] = "[Generic] called here: ";char * ____BAH_COMPILER_VAR_544 =__Bah_multiple_concat(____BAH_COMPILER_VAR_543, 4);println(____BAH_COMPILER_VAR_544);
};
void debugLine(__BAH_ARR_TYPE_Tok line){
char * cont = "";
register long int i = 0;
while ((i<len(line))) {
struct Tok t = line->data[i];
char** ____BAH_COMPILER_VAR_545 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_545[3] = "'";____BAH_COMPILER_VAR_545[2] = t.cont;____BAH_COMPILER_VAR_545[1] = " '";____BAH_COMPILER_VAR_545[0] = cont;char * ____BAH_COMPILER_VAR_546 =__Bah_multiple_concat(____BAH_COMPILER_VAR_545, 4);cont = ____BAH_COMPILER_VAR_546;
++i;
};
println(cont);
};
struct Elems* dupElems(struct Elems* elems){
struct Elems* ____BAH_COMPILER_VAR_547 = memoryAlloc(sizeof(struct Elems));
____BAH_COMPILER_VAR_547->vars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_547->vars->length = 0;
            ____BAH_COMPILER_VAR_547->vars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_547->structs = memoryAlloc(sizeof(array(struct cStruct*)));
            ____BAH_COMPILER_VAR_547->structs->length = 0;
            ____BAH_COMPILER_VAR_547->structs->elemSize = sizeof(struct cStruct*);
            ____BAH_COMPILER_VAR_547->types = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_547->types->length = 0;
            ____BAH_COMPILER_VAR_547->types->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_547->fns = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_547->fns->length = 0;
            ____BAH_COMPILER_VAR_547->fns->elemSize = sizeof(struct func*);
            ____BAH_COMPILER_VAR_547->branchChecks = memoryAlloc(sizeof(array(struct varCheck)));
            ____BAH_COMPILER_VAR_547->branchChecks->length = 0;
            ____BAH_COMPILER_VAR_547->branchChecks->elemSize = sizeof(struct varCheck);
            struct Elems* nElems = ____BAH_COMPILER_VAR_547;
nElems->parent = elems;
allocateArray(nElems->vars,len(elems->vars));
register long int j = 0;
for (; (j<len(elems->vars)); ++j) {

    unsigned int ____BAH_COMPILER_VAR_548 = j;
    __Bah_realocate_arr(nElems->vars, ____BAH_COMPILER_VAR_548);
    nElems->vars->data[____BAH_COMPILER_VAR_548] = elems->vars->data[j];
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

                struct string ____BAH_COMPILER_VAR_549 = string(compilerState.currentDir);
                if ((isUnsafe==false)&&(string__hasPrefix(&____BAH_COMPILER_VAR_549,BAH_DIR)==false)&&isRCPpointerType(tt)&&(t->cont[0]!=38)&&(t->cont[0]!=42)) {
struct variable* sv = searchVarByToken(t,elems);
if ((sv!=null)) {
if (__builtin_expect((sv->canBeNull==true)&&(checkedNotNull(sv->name,elems)==false), 0)) {
char * globCheck = "";
struct cStruct* s = searchStruct(sv->type,elems);
if ((sv->isGlobal==true)&&(s!=null)) {
char** ____BAH_COMPILER_VAR_550 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_550[2] = "'.";____BAH_COMPILER_VAR_550[1] = s->name;____BAH_COMPILER_VAR_550[0] = " or declare the var as 'new ";char * ____BAH_COMPILER_VAR_551 =__Bah_multiple_concat(____BAH_COMPILER_VAR_550, 3);globCheck = ____BAH_COMPILER_VAR_551;
}
char** ____BAH_COMPILER_VAR_552 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_552[2] = ".";____BAH_COMPILER_VAR_552[1] = globCheck;____BAH_COMPILER_VAR_552[0] = "{TOKEN} can contain a null value. Check if the value is null";char * ____BAH_COMPILER_VAR_553 =__Bah_multiple_concat(____BAH_COMPILER_VAR_552, 3);throwErr(t,____BAH_COMPILER_VAR_553);
}
}
}
};
void setNullStateBranchFlowEnd(struct Elems* elems){
if ((currentFn==null)) {
return;
}
if ((compilerState.isBranch==false)) {
if ((currentFn->couldAlreadyReturn==false)) {
currentFn->exits = true;
}
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

    unsigned int ____BAH_COMPILER_VAR_554 = i;
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_554);
    nl->data[____BAH_COMPILER_VAR_554] = t;
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
char * ____BAH_COMPILER_VAR_555 =string__str(&tc);struct string cCast = getCType(____BAH_COMPILER_VAR_555,elems);
char * cCastStr = string__str(&cCast);
char** ____BAH_COMPILER_VAR_556 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_556[3] = nnnt.cont;____BAH_COMPILER_VAR_556[2] = ")";____BAH_COMPILER_VAR_556[1] = cCastStr;____BAH_COMPILER_VAR_556[0] = "(";char * ____BAH_COMPILER_VAR_557 =__Bah_multiple_concat(____BAH_COMPILER_VAR_556, 4);nnnt.cont = ____BAH_COMPILER_VAR_557;

    unsigned int ____BAH_COMPILER_VAR_558 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_558);
    nl->data[____BAH_COMPILER_VAR_558] = nnnt;
i = i+2;
continue;
}
}

    unsigned int ____BAH_COMPILER_VAR_559 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_559);
    nl->data[____BAH_COMPILER_VAR_559] = t;
};
return nl;
};
char * getDirFromFile(char * f){
char * ____BAH_COMPILER_VAR_560 =__STR(f);array(char)* p = strAsArr(____BAH_COMPILER_VAR_560);
register long int i = len(p)-1;
while ((i>=0)) {
char c = p->data[i];
if ((c==47)) {

    unsigned int ____BAH_COMPILER_VAR_561 = i+1;
    __Bah_realocate_arr(p, ____BAH_COMPILER_VAR_561);
    p->data[____BAH_COMPILER_VAR_561] = (char)0;
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
char * ____BAH_COMPILER_VAR_563 =ccstr;
        char ____BAH_COMPILER_VAR_562 = 0;
        for(int i=compilerState.includes->length-1; i!=-1;i--) {
            if (compilerState.includes->data[i] != 0 && strcmp(compilerState.includes->data[i], ____BAH_COMPILER_VAR_563) == 0) {
                ____BAH_COMPILER_VAR_562=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_562) {
return true;
}
struct fileMap ____BAH_COMPILER_VAR_564 = {};
____BAH_COMPILER_VAR_564.handle = -1;
struct fileMap fm = ____BAH_COMPILER_VAR_564;
char** ____BAH_COMPILER_VAR_565 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_565[1] = ccstr;____BAH_COMPILER_VAR_565[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_566 =__Bah_multiple_concat(____BAH_COMPILER_VAR_565, 2);char * fileName = ____BAH_COMPILER_VAR_566;
char isBahDir = true;
char * f = fileMap__open(&fm,fileName);
if ((fileMap__isValid(&fm)==0)) {
char** ____BAH_COMPILER_VAR_567 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_567[1] = ccstr;____BAH_COMPILER_VAR_567[0] = compilerState.currentDir;char * ____BAH_COMPILER_VAR_568 =__Bah_multiple_concat(____BAH_COMPILER_VAR_567, 2);fileName = absPath(____BAH_COMPILER_VAR_568);
f = fileMap__open(&fm,fileName);
isBahDir = false;
if ((fileMap__isValid(&fm)==0)) {
return false;
}
}
char * oDir = compilerState.currentDir;
if ((isBahDir==false)) {
char** ____BAH_COMPILER_VAR_569 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_569[1] = getDirFromFile(ccstr);____BAH_COMPILER_VAR_569[0] = compilerState.currentDir;char * ____BAH_COMPILER_VAR_570 =__Bah_multiple_concat(____BAH_COMPILER_VAR_569, 2);compilerState.currentDir = ____BAH_COMPILER_VAR_570;
}
else {
char** ____BAH_COMPILER_VAR_571 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_571[1] = getDirFromFile(ccstr);____BAH_COMPILER_VAR_571[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_572 =__Bah_multiple_concat(____BAH_COMPILER_VAR_571, 2);compilerState.currentDir = ____BAH_COMPILER_VAR_572;
}
char * oFile = compilerState.currentFile;
compilerState.currentFile = fileName;

    unsigned int ____BAH_COMPILER_VAR_573 = len(compilerState.includes);
    __Bah_realocate_arr(compilerState.includes, ____BAH_COMPILER_VAR_573);
    compilerState.includes->data[____BAH_COMPILER_VAR_573] = ccstr;
array(struct Tok)* tokens = lexer(f,fm.size);
fileMap__close(&fm);
if (__builtin_expect((len(tokens)==0), 0)) {
char** ____BAH_COMPILER_VAR_574 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_574[2] = "' not recognized.";____BAH_COMPILER_VAR_574[1] = ccstr;____BAH_COMPILER_VAR_574[0] = "File '";char * ____BAH_COMPILER_VAR_575 =__Bah_multiple_concat(____BAH_COMPILER_VAR_574, 3);__BAH_panic(____BAH_COMPILER_VAR_575,"/home/alois/Documents/bah-bah/src/parser.bah:252");
}
char oshd = shouldOnlyDecl;
if ((isObject==true)) {

                struct string ____BAH_COMPILER_VAR_576 = string(compilerState.currentFile);
                if ((isBahDir==true)||(string__hasPrefix(&____BAH_COMPILER_VAR_576,oDir)==false)) {
shouldOnlyDecl = true;
}
else {
shouldOnlyDecl = false;
}
}
else if ((isSubObject==true)) {

                struct string ____BAH_COMPILER_VAR_577 = string(compilerState.currentFile);
                if ((isBahDir==true)||(string__hasPrefix(&____BAH_COMPILER_VAR_577,oDir)==false)) {
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
struct cacheFile* scf = cf;
if ((scf==null)) {
struct cacheFile* ____BAH_COMPILER_VAR_578 = memoryAlloc(sizeof(struct cacheFile));
____BAH_COMPILER_VAR_578->files = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_578->files->length = 0;
            ____BAH_COMPILER_VAR_578->files->elemSize = sizeof(char *);
            scf = ____BAH_COMPILER_VAR_578;
}
if ((cf==null)||(isValidCacheFile(scf)==false)) {
setCurrentPath(compilerState.currentDir);
char * verboseCC = "";
if ((flags__isSet(&flags,"verboseCC")==1)) {
verboseCC = "-verboseCC";
}
if ((debug==false)) {
char** ____BAH_COMPILER_VAR_579 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_579[1] = fn;____BAH_COMPILER_VAR_579[0] = "[compiling] ";char * ____BAH_COMPILER_VAR_580 =__Bah_multiple_concat(____BAH_COMPILER_VAR_579, 2);println(____BAH_COMPILER_VAR_580);
}
char * opti = "";
if ((isOptimized==true)) {
opti = "-optimize";
}
char** ____BAH_COMPILER_VAR_581 = alloca(11 * sizeof(char*));____BAH_COMPILER_VAR_581[10] = oName;____BAH_COMPILER_VAR_581[9] = " -o ";____BAH_COMPILER_VAR_581[8] = verboseCC;____BAH_COMPILER_VAR_581[7] = " -object ";____BAH_COMPILER_VAR_581[6] = opti;____BAH_COMPILER_VAR_581[5] = " ";____BAH_COMPILER_VAR_581[4] = rcp;____BAH_COMPILER_VAR_581[3] = " ";____BAH_COMPILER_VAR_581[2] = fn;____BAH_COMPILER_VAR_581[1] = " ";____BAH_COMPILER_VAR_581[0] = execName;char * ____BAH_COMPILER_VAR_582 =__Bah_multiple_concat(____BAH_COMPILER_VAR_581, 11);struct command cmd = command(____BAH_COMPILER_VAR_582);
array(char)* res = command__runBytes(&cmd);
setCurrentPath(wrkd);
if (__builtin_expect((cmd.status!=0), 0)) {
char * ____BAH_COMPILER_VAR_583 =arrToStr(res);print(____BAH_COMPILER_VAR_583);
exit(1);
}
if ((cf==null)) {
makeCacheFile(fn);
}
else {
updateCacheFile(cf);
}
writeCache();
}

        char ____BAH_COMPILER_VAR_584 = true;
        channel__sendAny(done, &____BAH_COMPILER_VAR_584, sizeof(____BAH_COMPILER_VAR_584));
        };
void parseImport(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
compilerState.hasImports = true;
if (__builtin_expect((len(l)!=2), 0)) {
throwErr(&l->data[0],"Invalid usage of {TOKEN}.");
}
struct Tok strt = l->data[1];
if (__builtin_expect((strt.type!=TOKEN_TYPE_STR), 0)) {
throwErr(&strt,"Cannot use {TOKEN} as file name (#import \"file\")");
}
struct string fileName = string(strt.cont);
string__trimLeft(&fileName,1);
string__trimRight(&fileName,1);
char * ____BAH_COMPILER_VAR_586 =string__str(&fileName);
        char ____BAH_COMPILER_VAR_585 = 0;
        for(int i=compilerState.includes->length-1; i!=-1;i--) {
            if (compilerState.includes->data[i] != 0 && strcmp(compilerState.includes->data[i], ____BAH_COMPILER_VAR_586) == 0) {
                ____BAH_COMPILER_VAR_585=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_585) {
return;
}

    unsigned int ____BAH_COMPILER_VAR_587 = len(compilerState.includes);
    __Bah_realocate_arr(compilerState.includes, ____BAH_COMPILER_VAR_587);
    compilerState.includes->data[____BAH_COMPILER_VAR_587] = string__str(&fileName);
char** ____BAH_COMPILER_VAR_588 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_588[1] = string__str(&fileName);____BAH_COMPILER_VAR_588[0] = compilerState.currentDir;char * ____BAH_COMPILER_VAR_589 =__Bah_multiple_concat(____BAH_COMPILER_VAR_588, 2);char * fn = absPath(____BAH_COMPILER_VAR_589);
if (((void *)fn==null)) {
char** ____BAH_COMPILER_VAR_590 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_590[1] = string__str(&fileName);____BAH_COMPILER_VAR_590[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_591 =__Bah_multiple_concat(____BAH_COMPILER_VAR_590, 2);fn = absPath(____BAH_COMPILER_VAR_591);
if (__builtin_expect(((void *)fn==null), 0)) {
throwErr(&strt,"Unknown file {TOKEN}.");
}
}
char * of = compilerState.currentFile;
char * od = compilerState.currentDir;
compilerState.currentFile = fn;
compilerState.currentDir = getDirFromFile(fn);
struct fileStream ____BAH_COMPILER_VAR_592 = {};
struct fileStream fs = ____BAH_COMPILER_VAR_592;
fileStream__open(&fs,fn,"r");
char * f = fileStream__readContent(&fs);
array(struct Tok)* tokens = lexer(f,fileStream__getSize(&fs));
fileStream__close(&fs);
char osod = shouldOnlyDecl;
char oiso = isSubObject;
char oiiso = isImportedSubObject;
if ((isSubObject==true)) {
isImportedSubObject = true;
}
shouldOnlyDecl = true;
isSubObject = true;
char** ____BAH_COMPILER_VAR_593 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_593[5] = ".o";____BAH_COMPILER_VAR_593[4] = intToStr(isOptimized);____BAH_COMPILER_VAR_593[3] = intToStr(RCPlevel);____BAH_COMPILER_VAR_593[2] = pathToVarName(fn);____BAH_COMPILER_VAR_593[1] = "cache/";____BAH_COMPILER_VAR_593[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_594 =__Bah_multiple_concat(____BAH_COMPILER_VAR_593, 6);char * oName = ____BAH_COMPILER_VAR_594;
register long int i = len(compilerState.cLibs);
for (; (i!=0); --i) {

    unsigned int ____BAH_COMPILER_VAR_595 = i;
    __Bah_realocate_arr(compilerState.cLibs, ____BAH_COMPILER_VAR_595);
    compilerState.cLibs->data[____BAH_COMPILER_VAR_595] = compilerState.cLibs->data[i-1];
};
char** ____BAH_COMPILER_VAR_596 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_596[2] = ".o";____BAH_COMPILER_VAR_596[1] = oName;____BAH_COMPILER_VAR_596[0] = "w ";char * ____BAH_COMPILER_VAR_597 =__Bah_multiple_concat(____BAH_COMPILER_VAR_596, 3);
    unsigned int ____BAH_COMPILER_VAR_598 = 0;
    __Bah_realocate_arr(compilerState.cLibs, ____BAH_COMPILER_VAR_598);
    compilerState.cLibs->data[____BAH_COMPILER_VAR_598] = ____BAH_COMPILER_VAR_597;
struct channel * done = channel();
parallelObjCompile(fn,oName,done);
parseLines(tokens,elems);
char ok = *(char*)channel__receive(done);
char** ____BAH_COMPILER_VAR_599 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_599[2] = "();\n";____BAH_COMPILER_VAR_599[1] = pathToVarName(fn);____BAH_COMPILER_VAR_599[0] = "__BAH_init";char * ____BAH_COMPILER_VAR_600 =__Bah_multiple_concat(____BAH_COMPILER_VAR_599, 3);INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_600));
shouldOnlyDecl = osod;
isSubObject = oiso;
compilerState.currentFile = of;
compilerState.currentDir = od;
isImportedSubObject = oiiso;
};
void parseInclude(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
if (__builtin_expect((len(l)!=2)&&(len(l)!=3), 0)) {
throwErr(&l->data[len(l)-1],"Invalid usage of include, ending by {TOKEN}.");
}
struct Tok strt = l->data[1];
char isSupressed = false;
if ((strcmp(strt.cont, "!") == 0)&&(len(l)>2)) {
isSupressed = true;
strt = l->data[2];
}
if (__builtin_expect((strt.type!=TOKEN_TYPE_STR), 0)) {
throwErr(&strt,"Cannot use {TOKEN} as string in include.");
}
char * sc = strt.cont;
strTrimLeft(&sc,1);
strTrimRight(&sc,1);
if (strHasPrefix(sc,"<")||strHasSuffix(sc,".h")||strHasSuffix(sc,".c")) {
if ((isSubObject==false)+(isSupressed==false)) {
char** ____BAH_COMPILER_VAR_601 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_601[2] = "\n";____BAH_COMPILER_VAR_601[1] = sc;____BAH_COMPILER_VAR_601[0] = "#include ";char * ____BAH_COMPILER_VAR_602 =__Bah_multiple_concat(____BAH_COMPILER_VAR_601, 3);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_602));

    unsigned int ____BAH_COMPILER_VAR_603 = len(compilerState.cIncludes);
    __Bah_realocate_arr(compilerState.cIncludes, ____BAH_COMPILER_VAR_603);
    compilerState.cIncludes->data[____BAH_COMPILER_VAR_603] = sc;
}
}
else {
if (__builtin_expect((includeFile(sc,elems)==false), 0)) {
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

    unsigned int ____BAH_COMPILER_VAR_604 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_604);
    nl->data[____BAH_COMPILER_VAR_604] = t;
++i;
continue;
}
++i;
struct Tok ____BAH_COMPILER_VAR_605 = {};
____BAH_COMPILER_VAR_605.cont = "";
____BAH_COMPILER_VAR_605.ogCont = "";
____BAH_COMPILER_VAR_605.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_605.line = 1;
____BAH_COMPILER_VAR_605.begLine = 1;
____BAH_COMPILER_VAR_605.bahType = "";
____BAH_COMPILER_VAR_605.cont = "";
struct Tok nt = ____BAH_COMPILER_VAR_605;
if ((i<len(line))) {
nt = line->data[i];
}
if ((i==len(line))||(strcmp(nt.cont, "{") != 0)) {
if ((i-2>=0)) {
struct Tok newTk = line->data[i-2];
if ((strcmp(newTk.cont, "new") == 0)) {
struct cStruct* s = searchStruct(t.cont,elems);
if (__builtin_expect((s==null), 0)) {
throwErr(&t,"Cannot initialize new unknown struct {TOKEN}.");
}
t.cont = genCompilerVar();
struct variable* ____BAH_COMPILER_VAR_606 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_606->name = "";
____BAH_COMPILER_VAR_606->type = "";
____BAH_COMPILER_VAR_606->constVal = "";
____BAH_COMPILER_VAR_606->from = "";
struct variable* tmpV = ____BAH_COMPILER_VAR_606;
tmpV->name = t.cont;
char** ____BAH_COMPILER_VAR_607 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_607[1] = "*";____BAH_COMPILER_VAR_607[0] = s->name;char * ____BAH_COMPILER_VAR_608 =__Bah_multiple_concat(____BAH_COMPILER_VAR_607, 2);tmpV->type = ____BAH_COMPILER_VAR_608;
struct string cType = getCType(tmpV->type,elems);
struct string structType = getCType(s->name,elems);

    unsigned int ____BAH_COMPILER_VAR_609 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_609);
    elems->vars->data[____BAH_COMPILER_VAR_609] = tmpV;
char** ____BAH_COMPILER_VAR_610 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_610[6] = declareStructMethods(tmpV,s,elems);____BAH_COMPILER_VAR_610[5] = "));\n";____BAH_COMPILER_VAR_610[4] = string__str(&structType);____BAH_COMPILER_VAR_610[3] = " = memoryAlloc(sizeof(";____BAH_COMPILER_VAR_610[2] = t.cont;____BAH_COMPILER_VAR_610[1] = " ";____BAH_COMPILER_VAR_610[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_611 =__Bah_multiple_concat(____BAH_COMPILER_VAR_610, 7);struct rope* r = rope(____BAH_COMPILER_VAR_611);
if (isGlobal()) {
INIT = rope__add(INIT, r);
}
else {
OUTPUT = rope__add(OUTPUT, r);
}

    unsigned int ____BAH_COMPILER_VAR_612 = len(nl)-1;
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_612);
    nl->data[____BAH_COMPILER_VAR_612] = t;
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
if (__builtin_expect((s==null), 0)) {
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

    unsigned int ____BAH_COMPILER_VAR_613 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_613);
    memory->data[____BAH_COMPILER_VAR_613] = t;
};
if ((len(memory)>0)) {
memory = prePross(memory,(lineType)-1,elems);
}
long int declType = 0;
char * rvn = genCompilerVar();
struct variable* ____BAH_COMPILER_VAR_614 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_614->name = "";
____BAH_COMPILER_VAR_614->type = "";
____BAH_COMPILER_VAR_614->constVal = "";
____BAH_COMPILER_VAR_614->from = "";
struct variable* tmpV = ____BAH_COMPILER_VAR_614;
tmpV->name = rvn;
if ((isHeap==true)) {
char** ____BAH_COMPILER_VAR_615 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_615[1] = "*";____BAH_COMPILER_VAR_615[0] = s->name;char * ____BAH_COMPILER_VAR_616 =__Bah_multiple_concat(____BAH_COMPILER_VAR_615, 2);tmpV->type = ____BAH_COMPILER_VAR_616;

    unsigned int ____BAH_COMPILER_VAR_617 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_617);
    elems->vars->data[____BAH_COMPILER_VAR_617] = tmpV;
}
else {
tmpV->type = s->name;
}
struct string rst = getCType(tmpV->type,elems);
struct rope* r= null;
if ((isHeap==true)) {
char * ____BAH_COMPILER_VAR_618 =string__str(&rst);struct string structType = string(____BAH_COMPILER_VAR_618);
string__trimRight(&structType,1);
char** ____BAH_COMPILER_VAR_619 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_619[6] = declareStructMethods(tmpV,s,elems);____BAH_COMPILER_VAR_619[5] = "));\n";____BAH_COMPILER_VAR_619[4] = string__str(&structType);____BAH_COMPILER_VAR_619[3] = " = memoryAlloc(sizeof(";____BAH_COMPILER_VAR_619[2] = rvn;____BAH_COMPILER_VAR_619[1] = " ";____BAH_COMPILER_VAR_619[0] = string__str(&rst);char * ____BAH_COMPILER_VAR_620 =__Bah_multiple_concat(____BAH_COMPILER_VAR_619, 7);r = rope(____BAH_COMPILER_VAR_620);
}
else {
char** ____BAH_COMPILER_VAR_621 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_621[4] = declareStructMethods(tmpV,s,elems);____BAH_COMPILER_VAR_621[3] = " = {};\n";____BAH_COMPILER_VAR_621[2] = rvn;____BAH_COMPILER_VAR_621[1] = " ";____BAH_COMPILER_VAR_621[0] = string__str(&rst);char * ____BAH_COMPILER_VAR_622 =__Bah_multiple_concat(____BAH_COMPILER_VAR_621, 5);r = rope(____BAH_COMPILER_VAR_622);
}
register long int j = 0;
register long int k = 0;
while ((k<len(memory))) {
t = memory->data[k];
if ((k+2<len(memory))) {
struct Tok st = memory->data[k+1];
struct Tok vl = memory->data[k+2];
if ((strcmp(st.cont, ":") == 0)) {
if (__builtin_expect((declType!=0)&&(declType!=1), 0)) {
throwErr(&t,"Cannot declare member {TOKEN} by name in list declaration.");
}
declType = 1;
if (__builtin_expect((t.type!=TOKEN_TYPE_VAR), 0)) {
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
if (__builtin_expect((compTypes(vlt,m->type)==false), 0)) {
char** ____BAH_COMPILER_VAR_623 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_623[4] = "'.";____BAH_COMPILER_VAR_623[3] = m->type;____BAH_COMPILER_VAR_623[2] = ") as '";____BAH_COMPILER_VAR_623[1] = vlt;____BAH_COMPILER_VAR_623[0] = "Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_624 =__Bah_multiple_concat(____BAH_COMPILER_VAR_623, 5);throwErr(&vl,____BAH_COMPILER_VAR_624);
}
char** ____BAH_COMPILER_VAR_625 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_625[5] = ";\n";____BAH_COMPILER_VAR_625[4] = vl.cont;____BAH_COMPILER_VAR_625[3] = " = ";____BAH_COMPILER_VAR_625[2] = m->name;____BAH_COMPILER_VAR_625[1] = sep;____BAH_COMPILER_VAR_625[0] = rvn;char * ____BAH_COMPILER_VAR_626 =__Bah_multiple_concat(____BAH_COMPILER_VAR_625, 6);r = rope__add(r, rope(____BAH_COMPILER_VAR_626));
break;
};
if (__builtin_expect((j==len(s->members)), 0)) {
char** ____BAH_COMPILER_VAR_627 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_627[2] = "' has no member called {TOKEN}.";____BAH_COMPILER_VAR_627[1] = s->name;____BAH_COMPILER_VAR_627[0] = "Struct '";char * ____BAH_COMPILER_VAR_628 =__Bah_multiple_concat(____BAH_COMPILER_VAR_627, 3);throwErr(&t,____BAH_COMPILER_VAR_628);
}
k = k+3;
continue;
}
}
if (__builtin_expect((declType!=0)&&(declType!=2), 0)) {
throwErr(&t,"Cannot declare member {TOKEN} without specifying its name.");
}
declType = 2;
if (__builtin_expect((j>len(s->members)), 0)) {
throwErr(&t,"Too many members {TOKEN}.");
}
struct structMemb* m = s->members->data[j];
++j;
char * tt = getTypeFromToken(&t,true,elems);
if (__builtin_expect((compTypes(tt,m->type)==false), 0)) {
char** ____BAH_COMPILER_VAR_629 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_629[4] = "'.";____BAH_COMPILER_VAR_629[3] = m->type;____BAH_COMPILER_VAR_629[2] = ") as '";____BAH_COMPILER_VAR_629[1] = tt;____BAH_COMPILER_VAR_629[0] = "Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_630 =__Bah_multiple_concat(____BAH_COMPILER_VAR_629, 5);throwErr(&t,____BAH_COMPILER_VAR_630);
}
char** ____BAH_COMPILER_VAR_631 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_631[5] = ";\n";____BAH_COMPILER_VAR_631[4] = t.cont;____BAH_COMPILER_VAR_631[3] = " = ";____BAH_COMPILER_VAR_631[2] = m->name;____BAH_COMPILER_VAR_631[1] = sep;____BAH_COMPILER_VAR_631[0] = rvn;char * ____BAH_COMPILER_VAR_632 =__Bah_multiple_concat(____BAH_COMPILER_VAR_631, 6);r = rope__add(r, rope(____BAH_COMPILER_VAR_632));
if ((k+1<len(memory))) {
++k;
struct Tok st = memory->data[k];
if (__builtin_expect((strcmp(st.cont, ",") != 0), 0)) {
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

    unsigned int ____BAH_COMPILER_VAR_633 = len(nl)-1;
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_633);
    nl->data[____BAH_COMPILER_VAR_633] = t;
}
else {
t.isEqual = true;

    unsigned int ____BAH_COMPILER_VAR_634 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_634);
    nl->data[____BAH_COMPILER_VAR_634] = t;
}
++i;
continue;
}
else {
--i;
}
}
}

    unsigned int ____BAH_COMPILER_VAR_635 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_635);
    nl->data[____BAH_COMPILER_VAR_635] = t;
++i;
};
return nl;
};
__BAH_ARR_TYPE_Tok parseArrayType(__BAH_ARR_TYPE_Tok line,struct Elems* elems,char guard){
register long int i = 0;
if ((guard==true)) {
for (; (i<len(line)); ++i) {
struct Tok t = line->data[i];
if ((strcmp(t.cont, "[") == 0)) {
break;
}
};
if ((i==len(line))) {
return line;
}
}
array(struct Tok)* nl = arraySubstitute(line, 0, i);
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
char** ____BAH_COMPILER_VAR_636 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_636[1] = "[]";____BAH_COMPILER_VAR_636[0] = bracks;char * ____BAH_COMPILER_VAR_637 =__Bah_multiple_concat(____BAH_COMPILER_VAR_636, 2);bracks = ____BAH_COMPILER_VAR_637;
++i;
}
else {
break;
}
};
if ((i<len(line))) {
t = line->data[i];
if (__builtin_expect((t.type!=TOKEN_TYPE_VAR), 0)) {
throwErr(&t,"Cannot use {TOKEN} as array type.");
}
char * arrElem = t.cont;
char** ____BAH_COMPILER_VAR_638 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_638[1] = arrElem;____BAH_COMPILER_VAR_638[0] = bracks;char * ____BAH_COMPILER_VAR_639 =__Bah_multiple_concat(____BAH_COMPILER_VAR_638, 2);t.bahType = ____BAH_COMPILER_VAR_639;
t.cont = "";
t.isValue = true;

    unsigned int ____BAH_COMPILER_VAR_640 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_640);
    nl->data[____BAH_COMPILER_VAR_640] = t;
continue;
}
}
else {
--i;
t = line->data[i];
}
}
else {
--i;
}
}

    unsigned int ____BAH_COMPILER_VAR_641 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_641);
    nl->data[____BAH_COMPILER_VAR_641] = t;
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
if ((l->data[i-1].type==TOKEN_TYPE_VAR)+(l->data[i-1].isValue==true)) {
if ((strcmp(t.cont, "*") == 0)) {
if ((i+1<len(l))) {
if ((strcmp(l->data[i+1].cont, "(") != 0)&&(l->data[i+1].type!=TOKEN_TYPE_CAST)&&(l->data[i+1].isValue!=true)) {
char** ____BAH_COMPILER_VAR_642 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_642[1] = t.cont;____BAH_COMPILER_VAR_642[0] = l->data[i-1].cont;char * ____BAH_COMPILER_VAR_643 =__Bah_multiple_concat(____BAH_COMPILER_VAR_642, 2);l->data[i-1].cont = ____BAH_COMPILER_VAR_643;
delete(l,i);
--i;
}
}
else {
char** ____BAH_COMPILER_VAR_644 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_644[1] = t.cont;____BAH_COMPILER_VAR_644[0] = l->data[i-1].cont;char * ____BAH_COMPILER_VAR_645 =__Bah_multiple_concat(____BAH_COMPILER_VAR_644, 2);l->data[i-1].cont = ____BAH_COMPILER_VAR_645;
delete(l,i);
--i;
}
}
continue;
}
}
if ((i+1<len(l))) {
if ((i>0)) {
if ((strcmp(l->data[i-1].cont, ")") == 0)||(l->data[i-1].isValue==true)) {
continue;
}
}
if ((l->data[i+1].type==TOKEN_TYPE_VAR)) {
char** ____BAH_COMPILER_VAR_646 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_646[1] = l->data[i+1].cont;____BAH_COMPILER_VAR_646[0] = t.cont;char * ____BAH_COMPILER_VAR_647 =__Bah_multiple_concat(____BAH_COMPILER_VAR_646, 2);l->data[i+1].cont = ____BAH_COMPILER_VAR_647;
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
if (__builtin_expect((v==null), 0)) {
throwErr(&e,"Must be a var, not {TOKEN}.");
}
struct cStruct* s = searchStruct(v->type,elems);
if (__builtin_expect((s==null), 0)) {
throwErr(&e,"Must be a struct, not {TOKEN}.");
}
struct string svt = string(v->type);
register long int ptrLevel = string__count(&svt,"*");
string__replace(&svt,"*","");
char * code= null;
if ((ptrLevel==0)) {
char** ____BAH_COMPILER_VAR_648 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_648[5] = ")";____BAH_COMPILER_VAR_648[4] = string__str(&svt);____BAH_COMPILER_VAR_648[3] = "sizeof(struct ";____BAH_COMPILER_VAR_648[2] = ", ";____BAH_COMPILER_VAR_648[1] = e->cont;____BAH_COMPILER_VAR_648[0] = "__serialize(&";char * ____BAH_COMPILER_VAR_649 =__Bah_multiple_concat(____BAH_COMPILER_VAR_648, 6);code = ____BAH_COMPILER_VAR_649;
}
else {
char * ptrRect = "";
while ((ptrLevel>1)) {
char** ____BAH_COMPILER_VAR_650 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_650[1] = "*";____BAH_COMPILER_VAR_650[0] = ptrRect;char * ____BAH_COMPILER_VAR_651 =__Bah_multiple_concat(____BAH_COMPILER_VAR_650, 2);ptrRect = ____BAH_COMPILER_VAR_651;
ptrLevel = ptrLevel-1;
};
char** ____BAH_COMPILER_VAR_652 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_652[6] = ")";____BAH_COMPILER_VAR_652[5] = string__str(&svt);____BAH_COMPILER_VAR_652[4] = "sizeof(struct ";____BAH_COMPILER_VAR_652[3] = ", ";____BAH_COMPILER_VAR_652[2] = e->cont;____BAH_COMPILER_VAR_652[1] = ptrRect;____BAH_COMPILER_VAR_652[0] = "__serialize(";char * ____BAH_COMPILER_VAR_653 =__Bah_multiple_concat(____BAH_COMPILER_VAR_652, 7);code = ____BAH_COMPILER_VAR_653;
register long int i = 0;
while ((i<len(s->members))) {
struct structMemb* m = s->members->data[i];
if ((strcmp(m->type, "cpstring") == 0)) {
char** ____BAH_COMPILER_VAR_654 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_654[5] = ")";____BAH_COMPILER_VAR_654[4] = m->name;____BAH_COMPILER_VAR_654[3] = "->";____BAH_COMPILER_VAR_654[2] = e->cont;____BAH_COMPILER_VAR_654[1] = "+strlen(";____BAH_COMPILER_VAR_654[0] = code;char * ____BAH_COMPILER_VAR_655 =__Bah_multiple_concat(____BAH_COMPILER_VAR_654, 6);code = ____BAH_COMPILER_VAR_655;
}
i = i+1;
};
}
char** ____BAH_COMPILER_VAR_656 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_656[1] = ")";____BAH_COMPILER_VAR_656[0] = code;char * ____BAH_COMPILER_VAR_657 =__Bah_multiple_concat(____BAH_COMPILER_VAR_656, 2);return ____BAH_COMPILER_VAR_657;
};
struct Tok parseReflect(struct Tok t,char * tt,struct Elems* elems,char parsedPointer,char * ogName,char * offset){
char * isArr = "0";
if ((t.type!=TOKEN_TYPE_VAR)+(t.type!=TOKEN_TYPE_FUNC)) {
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
char** ____BAH_COMPILER_VAR_658 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_658[5] = ";\n";____BAH_COMPILER_VAR_658[4] = t.cont;____BAH_COMPILER_VAR_658[3] = " = ";____BAH_COMPILER_VAR_658[2] = v;____BAH_COMPILER_VAR_658[1] = " ";____BAH_COMPILER_VAR_658[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_659 =__Bah_multiple_concat(____BAH_COMPILER_VAR_658, 6);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_659));
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
struct Tok ____BAH_COMPILER_VAR_660 = {};
____BAH_COMPILER_VAR_660.cont = "";
____BAH_COMPILER_VAR_660.ogCont = "";
____BAH_COMPILER_VAR_660.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_660.line = 1;
____BAH_COMPILER_VAR_660.begLine = 1;
____BAH_COMPILER_VAR_660.bahType = "";
struct Tok tmpT = ____BAH_COMPILER_VAR_660;
tmpT.type = TOKEN_TYPE_VAR;
tmpT.cont = "0";
char * ____BAH_COMPILER_VAR_661 =string__str(&aet);struct Tok rt = parseReflect(tmpT,____BAH_COMPILER_VAR_661,elems,true,"","0");
char * aev = genCompilerVar();
char** ____BAH_COMPILER_VAR_662 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_662[4] = ";\n        ";____BAH_COMPILER_VAR_662[3] = rt.cont;____BAH_COMPILER_VAR_662[2] = " = ";____BAH_COMPILER_VAR_662[1] = aev;____BAH_COMPILER_VAR_662[0] = "\n        struct reflectElement ";char * ____BAH_COMPILER_VAR_663 =__Bah_multiple_concat(____BAH_COMPILER_VAR_662, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_663));
char** ____BAH_COMPILER_VAR_664 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_664[1] = aev;____BAH_COMPILER_VAR_664[0] = "&";char * ____BAH_COMPILER_VAR_665 =__Bah_multiple_concat(____BAH_COMPILER_VAR_664, 2);arrElem = ____BAH_COMPILER_VAR_665;
}
else if (strHasPrefix(tt,"map:")) {
struct string aet = string(tt);
string__trimLeft(&aet,4);
struct Tok ____BAH_COMPILER_VAR_666 = {};
____BAH_COMPILER_VAR_666.cont = "";
____BAH_COMPILER_VAR_666.ogCont = "";
____BAH_COMPILER_VAR_666.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_666.line = 1;
____BAH_COMPILER_VAR_666.begLine = 1;
____BAH_COMPILER_VAR_666.bahType = "";
struct Tok tmpT = ____BAH_COMPILER_VAR_666;
tmpT.type = TOKEN_TYPE_VAR;
tmpT.cont = "0";
char * ____BAH_COMPILER_VAR_667 =string__str(&aet);struct Tok rt = parseReflect(tmpT,____BAH_COMPILER_VAR_667,elems,true,"","0");
char * aev = genCompilerVar();
char** ____BAH_COMPILER_VAR_668 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_668[4] = ";\n        ";____BAH_COMPILER_VAR_668[3] = rt.cont;____BAH_COMPILER_VAR_668[2] = " = ";____BAH_COMPILER_VAR_668[1] = aev;____BAH_COMPILER_VAR_668[0] = "\n        struct reflectElement ";char * ____BAH_COMPILER_VAR_669 =__Bah_multiple_concat(____BAH_COMPILER_VAR_668, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_669));
char** ____BAH_COMPILER_VAR_670 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_670[1] = aev;____BAH_COMPILER_VAR_670[0] = "&";char * ____BAH_COMPILER_VAR_671 =__Bah_multiple_concat(____BAH_COMPILER_VAR_670, 2);arrElem = ____BAH_COMPILER_VAR_671;
}
char * isStruct = "0";
struct cStruct* ts = searchStruct(tt,elems);
char * structLayout = "0";
if ((ts!=null)) {
isStruct = "1";
structLayout = genCompilerVar();
struct variable* ____BAH_COMPILER_VAR_672 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_672->name = "";
____BAH_COMPILER_VAR_672->type = "";
____BAH_COMPILER_VAR_672->constVal = "";
____BAH_COMPILER_VAR_672->from = "";
struct variable* slv = ____BAH_COMPILER_VAR_672;
slv->name = structLayout;
slv->type = "[]reflectElement";

    unsigned int ____BAH_COMPILER_VAR_673 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_673);
    elems->vars->data[____BAH_COMPILER_VAR_673] = slv;
struct rope* dataLayout = rope("");
register long int i = 0;
for (; (i<len(ts->members)); ++i) {
struct structMemb* m = ts->members->data[i];
if ((strcmp(m->type, tt) == 0)) {
struct structMemb* ____BAH_COMPILER_VAR_674 = memoryAlloc(sizeof(struct structMemb));
____BAH_COMPILER_VAR_674->name = "";
____BAH_COMPILER_VAR_674->type = "";
____BAH_COMPILER_VAR_674->constVal = "";
____BAH_COMPILER_VAR_674->from = "";
____BAH_COMPILER_VAR_674->def = "";
struct structMemb* nm = ____BAH_COMPILER_VAR_674;
*nm = *m;
m = nm;
m->type = "ptr";
}
struct Tok ____BAH_COMPILER_VAR_675 = {};
____BAH_COMPILER_VAR_675.cont = "";
____BAH_COMPILER_VAR_675.ogCont = "";
____BAH_COMPILER_VAR_675.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_675.line = 1;
____BAH_COMPILER_VAR_675.begLine = 1;
____BAH_COMPILER_VAR_675.bahType = "";
struct Tok tmpT = ____BAH_COMPILER_VAR_675;
tmpT.type = TOKEN_TYPE_VAR;
char * sep = "->";
if ((strCount(tt,"*")==0)) {
sep = ".";
}
struct string mCtype = getCType(m->type,elems);
struct string offsetTT = string(tt);
string__replace(&offsetTT,"*","");
char** ____BAH_COMPILER_VAR_676 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_676[8] = "))";____BAH_COMPILER_VAR_676[7] = m->name;____BAH_COMPILER_VAR_676[6] = ", ";____BAH_COMPILER_VAR_676[5] = string__str(&offsetTT);____BAH_COMPILER_VAR_676[4] = ") + offsetof(struct ";____BAH_COMPILER_VAR_676[3] = t.cont;____BAH_COMPILER_VAR_676[2] = "*)((char*)(";____BAH_COMPILER_VAR_676[1] = string__str(&mCtype);____BAH_COMPILER_VAR_676[0] = "(";char * ____BAH_COMPILER_VAR_677 =__Bah_multiple_concat(____BAH_COMPILER_VAR_676, 9);tmpT.cont = ____BAH_COMPILER_VAR_677;
char** ____BAH_COMPILER_VAR_678 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_678[4] = ")";____BAH_COMPILER_VAR_678[3] = m->name;____BAH_COMPILER_VAR_678[2] = ", ";____BAH_COMPILER_VAR_678[1] = string__str(&offsetTT);____BAH_COMPILER_VAR_678[0] = "offsetof(struct ";char * ____BAH_COMPILER_VAR_679 =__Bah_multiple_concat(____BAH_COMPILER_VAR_678, 5);struct Tok rt = parseReflect(tmpT,m->type,elems,true,m->name,____BAH_COMPILER_VAR_679);
char** ____BAH_COMPILER_VAR_680 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_680[5] = ";\n";____BAH_COMPILER_VAR_680[4] = rt.cont;____BAH_COMPILER_VAR_680[3] = "] = ";____BAH_COMPILER_VAR_680[2] = intToStr(i);____BAH_COMPILER_VAR_680[1] = "->data[";____BAH_COMPILER_VAR_680[0] = structLayout;char * ____BAH_COMPILER_VAR_681 =__Bah_multiple_concat(____BAH_COMPILER_VAR_680, 6);dataLayout = rope__add(dataLayout, rope(____BAH_COMPILER_VAR_681));
};
char** ____BAH_COMPILER_VAR_682 = alloca(15 * sizeof(char*));____BAH_COMPILER_VAR_682[14] = "->elemSize);\n        ";____BAH_COMPILER_VAR_682[13] = structLayout;____BAH_COMPILER_VAR_682[12] = "->length * ";____BAH_COMPILER_VAR_682[11] = structLayout;____BAH_COMPILER_VAR_682[10] = "->data = memoryAlloc(";____BAH_COMPILER_VAR_682[9] = structLayout;____BAH_COMPILER_VAR_682[8] = ";\n        ";____BAH_COMPILER_VAR_682[7] = intToStr(len(ts->members));____BAH_COMPILER_VAR_682[6] = "->length = ";____BAH_COMPILER_VAR_682[5] = structLayout;____BAH_COMPILER_VAR_682[4] = "->elemSize = sizeof(struct reflectElement);\n        ";____BAH_COMPILER_VAR_682[3] = structLayout;____BAH_COMPILER_VAR_682[2] = " = memoryAlloc(sizeof(array(struct reflectElement)));\n        ";____BAH_COMPILER_VAR_682[1] = structLayout;____BAH_COMPILER_VAR_682[0] = "\n        array(struct reflectElement) * ";char * ____BAH_COMPILER_VAR_683 =__Bah_multiple_concat(____BAH_COMPILER_VAR_682, 15);OUTPUT = rope__add(OUTPUT, rope__add(rope(____BAH_COMPILER_VAR_683), dataLayout));
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
struct variable* ____BAH_COMPILER_VAR_684 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_684->name = "";
____BAH_COMPILER_VAR_684->type = "";
____BAH_COMPILER_VAR_684->constVal = "";
____BAH_COMPILER_VAR_684->from = "";
struct variable* rv = ____BAH_COMPILER_VAR_684;
rv->name = genCompilerVar();
rv->type = "reflectElement";

    unsigned int ____BAH_COMPILER_VAR_685 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_685);
    elems->vars->data[____BAH_COMPILER_VAR_685] = rv;
char** ____BAH_COMPILER_VAR_686 = alloca(22 * sizeof(char*));____BAH_COMPILER_VAR_686[21] = ");\n";____BAH_COMPILER_VAR_686[20] = offset;____BAH_COMPILER_VAR_686[19] = ", ";____BAH_COMPILER_VAR_686[18] = structLayout;____BAH_COMPILER_VAR_686[17] = ", ";____BAH_COMPILER_VAR_686[16] = isStruct;____BAH_COMPILER_VAR_686[15] = ", ";____BAH_COMPILER_VAR_686[14] = arrElem;____BAH_COMPILER_VAR_686[13] = ", ";____BAH_COMPILER_VAR_686[12] = isArr;____BAH_COMPILER_VAR_686[11] = "\", ";____BAH_COMPILER_VAR_686[10] = string__str(&name);____BAH_COMPILER_VAR_686[9] = "\", \"";____BAH_COMPILER_VAR_686[8] = tt;____BAH_COMPILER_VAR_686[7] = "), \"";____BAH_COMPILER_VAR_686[6] = string__str(&cType);____BAH_COMPILER_VAR_686[5] = ", sizeof(";____BAH_COMPILER_VAR_686[4] = t.cont;____BAH_COMPILER_VAR_686[3] = amp;____BAH_COMPILER_VAR_686[2] = " = __reflect(";____BAH_COMPILER_VAR_686[1] = rv->name;____BAH_COMPILER_VAR_686[0] = "struct reflectElement ";char * ____BAH_COMPILER_VAR_687 =__Bah_multiple_concat(____BAH_COMPILER_VAR_686, 22);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_687));
t.cont = rv->name;
return t;
};
char * parseArrayDecl(struct variable* v,__BAH_ARR_TYPE_Tok l,long int i,long int max,struct Elems* elems){
long int arrayLength = 0;
struct string arrType = getCType(v->type,elems);
string__trimRight(&arrType,1);
char** ____BAH_COMPILER_VAR_688 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_688[2] = "))";____BAH_COMPILER_VAR_688[1] = string__str(&arrType);____BAH_COMPILER_VAR_688[0] = "memoryAlloc(sizeof(";char * ____BAH_COMPILER_VAR_689 =__Bah_multiple_concat(____BAH_COMPILER_VAR_688, 3);char * code = ____BAH_COMPILER_VAR_689;
string__trimLeft(&arrType,6);
string__trimRight(&arrType,1);
char * elemTypeStr = string__str(&arrType);
if ((i+1!=max)) {
++i;
struct Tok nt = l->data[i];
if (__builtin_expect((strcmp(nt.cont, "{") != 0), 0)) {
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

    unsigned int ____BAH_COMPILER_VAR_690 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_690);
    memory->data[____BAH_COMPILER_VAR_690] = l->data[i];
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
struct variable* ____BAH_COMPILER_VAR_691 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_691->name = "";
____BAH_COMPILER_VAR_691->type = "";
____BAH_COMPILER_VAR_691->constVal = "";
____BAH_COMPILER_VAR_691->from = "";
struct variable* tmpV = ____BAH_COMPILER_VAR_691;
tmpV->name = genCompilerVar();
struct string elemType = string(v->type);
string__trimLeft(&elemType,2);
tmpV->type = string__str(&elemType);

    unsigned int ____BAH_COMPILER_VAR_692 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_692);
    elems->vars->data[____BAH_COMPILER_VAR_692] = tmpV;
char * oldNL = NEXT_LINE;
NEXT_LINE = "";
char * innerCode = parseArrayDecl(tmpV,memory,j,i+1,elems);
char * ____BAH_COMPILER_VAR_693 =string__str(&elemType);struct string cType = getCType(____BAH_COMPILER_VAR_693,elems);
char** ____BAH_COMPILER_VAR_694 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_694[8] = "\n                ";____BAH_COMPILER_VAR_694[7] = NEXT_LINE;____BAH_COMPILER_VAR_694[6] = ";\n                ";____BAH_COMPILER_VAR_694[5] = innerCode;____BAH_COMPILER_VAR_694[4] = " = ";____BAH_COMPILER_VAR_694[3] = tmpV->name;____BAH_COMPILER_VAR_694[2] = ") * ";____BAH_COMPILER_VAR_694[1] = string__str(&cType);____BAH_COMPILER_VAR_694[0] = "\n                array(";char * ____BAH_COMPILER_VAR_695 =__Bah_multiple_concat(____BAH_COMPILER_VAR_694, 9);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_695));
NEXT_LINE = oldNL;
struct Tok ____BAH_COMPILER_VAR_696 = {};
____BAH_COMPILER_VAR_696.cont = "";
____BAH_COMPILER_VAR_696.ogCont = "";
____BAH_COMPILER_VAR_696.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_696.line = 1;
____BAH_COMPILER_VAR_696.begLine = 1;
____BAH_COMPILER_VAR_696.bahType = "";
____BAH_COMPILER_VAR_696.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_696.cont = tmpV->name;
____BAH_COMPILER_VAR_696.bahType = string__str(&elemType);
____BAH_COMPILER_VAR_696.isValue = true;
t = ____BAH_COMPILER_VAR_696;
}
char * tt = getTypeFromToken(&t,true,elems);
if (__builtin_expect((compTypes(tt,elemBahTypeStr)==false), 0)) {
char** ____BAH_COMPILER_VAR_697 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_697[3] = elemBahTypeStr;____BAH_COMPILER_VAR_697[2] = ") as ";____BAH_COMPILER_VAR_697[1] = tt;____BAH_COMPILER_VAR_697[0] = "Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_698 =__Bah_multiple_concat(____BAH_COMPILER_VAR_697, 4);throwErr(&t,____BAH_COMPILER_VAR_698);
}
char * strArrayLength = intToStr(arrayLength);
arrayLength = arrayLength+1;
char** ____BAH_COMPILER_VAR_699 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_699[6] = ";\n";____BAH_COMPILER_VAR_699[5] = t.cont;____BAH_COMPILER_VAR_699[4] = "] = ";____BAH_COMPILER_VAR_699[3] = strArrayLength;____BAH_COMPILER_VAR_699[2] = "->data[";____BAH_COMPILER_VAR_699[1] = v->name;____BAH_COMPILER_VAR_699[0] = NEXT_LINE;char * ____BAH_COMPILER_VAR_700 =__Bah_multiple_concat(____BAH_COMPILER_VAR_699, 7);NEXT_LINE = ____BAH_COMPILER_VAR_700;
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
char** ____BAH_COMPILER_VAR_701 = alloca(11 * sizeof(char*));____BAH_COMPILER_VAR_701[10] = NEXT_LINE;____BAH_COMPILER_VAR_701[9] = ";\n";____BAH_COMPILER_VAR_701[8] = allocLengthStr;____BAH_COMPILER_VAR_701[7] = "->realLength = ";____BAH_COMPILER_VAR_701[6] = v->name;____BAH_COMPILER_VAR_701[5] = ");\n                    ";____BAH_COMPILER_VAR_701[4] = allocLengthStr;____BAH_COMPILER_VAR_701[3] = ") * ";____BAH_COMPILER_VAR_701[2] = elemTypeStr;____BAH_COMPILER_VAR_701[1] = "->data = memoryAlloc(sizeof(";____BAH_COMPILER_VAR_701[0] = v->name;char * ____BAH_COMPILER_VAR_702 =__Bah_multiple_concat(____BAH_COMPILER_VAR_701, 11);NEXT_LINE = ____BAH_COMPILER_VAR_702;
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
char** ____BAH_COMPILER_VAR_703 = alloca(10 * sizeof(char*));____BAH_COMPILER_VAR_703[9] = NEXT_LINE;____BAH_COMPILER_VAR_703[8] = ");\n";____BAH_COMPILER_VAR_703[7] = elemTypeStr;____BAH_COMPILER_VAR_703[6] = "->elemSize = sizeof(";____BAH_COMPILER_VAR_703[5] = v->name;____BAH_COMPILER_VAR_703[4] = ";\n";____BAH_COMPILER_VAR_703[3] = strArrayLength;____BAH_COMPILER_VAR_703[2] = "->length = ";____BAH_COMPILER_VAR_703[1] = v->name;____BAH_COMPILER_VAR_703[0] = "\n";char * ____BAH_COMPILER_VAR_704 =__Bah_multiple_concat(____BAH_COMPILER_VAR_703, 10);NEXT_LINE = ____BAH_COMPILER_VAR_704;
return code;
};
array(char *)* equalsTokens;
void parseVar(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
struct Tok ft = l->data[0];
if ((ft.isFunc==true)) {
if (__builtin_expect((len(l)>1), 0)) {
throwErr(&l->data[len(l)-1],"Not expecting {TOKEN} after function call.");
}
ft = l->data[0];
char parsed = true;
char** ____BAH_COMPILER_VAR_705 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_705[1] = ";\n";____BAH_COMPILER_VAR_705[0] = ft.cont;char * ____BAH_COMPILER_VAR_706 =__Bah_multiple_concat(____BAH_COMPILER_VAR_705, 2);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_706));
return;
}
l = parseStructType(l,(lineType)-1,elems);
char isEqual = false;
char toVar = false;
char isPointedVar = false;
char isStruct = false;
char * currentType = "";
ft = l->data[0];
struct variable* v = searchVar(ft.cont,elems);
char exists = true;
char * ogName= null;
if ((v==null)) {
exists = false;
struct variable* ____BAH_COMPILER_VAR_707 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_707->name = "";
____BAH_COMPILER_VAR_707->type = "";
____BAH_COMPILER_VAR_707->constVal = "";
____BAH_COMPILER_VAR_707->from = "";
v = ____BAH_COMPILER_VAR_707;
v->name = ft.cont;
v->type = "";
}
else {
ogName = v->name;
}
if (__builtin_expect((v->isConst==true), 0)) {
throwErr(&ft,"Cannot set the value of const {TOKEN}.");
}
char * code = "";
if (__builtin_expect((exists==true)&&isGlobal(), 0)) {
throwErr(&ft,"Cannot redeclare global variable {TOKEN}.");
}
if ((len(l)==1)) {
struct Tok t = l->data[0];
struct string c = string(t.cont);
string__trimLeft(&c,2);
char * ____BAH_COMPILER_VAR_708 =string__str(&c);v = searchVar(____BAH_COMPILER_VAR_708,elems);
if (__builtin_expect((v==null), 0)) {
throwErr(&t,"Cannot increase/decrease not declared variable {TOKEN}.");
}
char** ____BAH_COMPILER_VAR_709 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_709[1] = ";\n";____BAH_COMPILER_VAR_709[0] = t.cont;char * ____BAH_COMPILER_VAR_710 =__Bah_multiple_concat(____BAH_COMPILER_VAR_709, 2);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_710));
return;
}
if (__builtin_expect((len(l)<2), 0)) {
throwErr(&ft,"Missing '=' after {TOKEN}.");
}
struct Tok operT = l->data[1];
char * ____BAH_COMPILER_VAR_712 =operT.cont;
        char ____BAH_COMPILER_VAR_711 = 0;
        for(int i=equalsTokens->length-1; i!=-1;i--) {
            if (equalsTokens->data[i] != 0 && strcmp(equalsTokens->data[i], ____BAH_COMPILER_VAR_712) == 0) {
                ____BAH_COMPILER_VAR_711=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_711&&(strcmp(operT.cont, "=") != 0)) {
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 1;
nl->elemSize = sizeof(struct Tok);
nl->data = memoryAlloc(sizeof(struct Tok) * 50);
                    nl->realLength = 50;
nl->data[0] = l->data[0];
if (__builtin_expect((2==len(l)), 0)) {
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

    unsigned int ____BAH_COMPILER_VAR_713 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_713);
    nl->data[____BAH_COMPILER_VAR_713] = operT;
register long int j = 0;
for (; (j<len(tmpL)); ++j) {

    unsigned int ____BAH_COMPILER_VAR_714 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_714);
    nl->data[____BAH_COMPILER_VAR_714] = tmpL->data[j];
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
char** ____BAH_COMPILER_VAR_715 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_715[1] = t.cont;____BAH_COMPILER_VAR_715[0] = currentType;char * ____BAH_COMPILER_VAR_716 =__Bah_multiple_concat(____BAH_COMPILER_VAR_715, 2);currentType = ____BAH_COMPILER_VAR_716;
}
else {
if ((t.isEqual==true)&&(exists==false)&&(isGlobal()==false)) {
v->canBeNull = false;
}
if ((strcmp(t.cont, "chan") == 0)) {
if (__builtin_expect((i>=len(l)), 0)) {
throwErr(&t,"Cannot declare a {TOKEN} without a type (chan <type>).");
}
++i;
struct Tok nt = l->data[i];
char** ____BAH_COMPILER_VAR_717 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_717[1] = nt.cont;____BAH_COMPILER_VAR_717[0] = "chan:";char * ____BAH_COMPILER_VAR_718 =__Bah_multiple_concat(____BAH_COMPILER_VAR_717, 2);v->type = ____BAH_COMPILER_VAR_718;
code = "channel()";
if (__builtin_expect((i+1!=len(l)), 0)) {
struct Tok errT = l->data[i+1];
throwErr(&errT,"{TOKEN} not expected after channel declaration.");
}
break;
}
else if ((strcmp(t.cont, "map") == 0)) {
if (__builtin_expect((i>=len(l)), 0)) {
throwErr(&t,"Cannot declare a {TOKEN} without a type (map <type>).");
}
++i;
struct Tok nt = l->data[i];
char** ____BAH_COMPILER_VAR_719 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_719[1] = nt.cont;____BAH_COMPILER_VAR_719[0] = "map:";char * ____BAH_COMPILER_VAR_720 =__Bah_multiple_concat(____BAH_COMPILER_VAR_719, 2);v->type = ____BAH_COMPILER_VAR_720;
code = "mapWrapper()";
if (__builtin_expect((i+1!=len(l)), 0)) {
struct Tok errT = l->data[i+1];
throwErr(&errT,"{TOKEN} not expected after map declaration.");
}
break;
}
else if ((strcmp(t.cont, "buffer") == 0)) {
if (__builtin_expect((i>=len(l)), 0)) {
throwErr(&t,"Cannot declare a {TOKEN} without a length (buffer <length>).");
}
++i;
struct Tok nt = l->data[i];
if (__builtin_expect((nt.type!=TOKEN_TYPE_INT), 0)) {
throwErr(&nt,"Expected buffer length, not {TOKEN}.");
}
char** ____BAH_COMPILER_VAR_721 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_721[1] = nt.cont;____BAH_COMPILER_VAR_721[0] = "buffer:";char * ____BAH_COMPILER_VAR_722 =__Bah_multiple_concat(____BAH_COMPILER_VAR_721, 2);v->type = ____BAH_COMPILER_VAR_722;
struct variable* ____BAH_COMPILER_VAR_723 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_723->name = "";
____BAH_COMPILER_VAR_723->type = "";
____BAH_COMPILER_VAR_723->constVal = "";
____BAH_COMPILER_VAR_723->from = "";
struct variable* av = ____BAH_COMPILER_VAR_723;
av->type = "char*";
av->name = genCompilerVar();

    unsigned int ____BAH_COMPILER_VAR_724 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_724);
    elems->vars->data[____BAH_COMPILER_VAR_724] = av;
struct string cType = getCType(av->type,elems);
char** ____BAH_COMPILER_VAR_725 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_725[4] = "];";____BAH_COMPILER_VAR_725[3] = nt.cont;____BAH_COMPILER_VAR_725[2] = "[";____BAH_COMPILER_VAR_725[1] = av->name;____BAH_COMPILER_VAR_725[0] = "char ";char * ____BAH_COMPILER_VAR_726 =__Bah_multiple_concat(____BAH_COMPILER_VAR_725, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_726));
code = av->name;
if (__builtin_expect((i+1!=len(l)), 0)) {
struct Tok errT = l->data[i+1];
throwErr(&errT,"{TOKEN} not expected after buffer declaration.");
}
break;
}
char * tp = getTypeFromToken(&t,true,elems);

                struct string ____BAH_COMPILER_VAR_727 = string(compilerState.currentDir);
                if ((isUnsafe==false)&&(string__hasPrefix(&____BAH_COMPILER_VAR_727,BAH_DIR)==false)&&isRCPpointerType(tp)) {
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
if (__builtin_expect((compTypes(tp,v->type)==false), 0)) {
char** ____BAH_COMPILER_VAR_728 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_728[4] = ".";____BAH_COMPILER_VAR_728[3] = v->type;____BAH_COMPILER_VAR_728[2] = ") as ";____BAH_COMPILER_VAR_728[1] = tp;____BAH_COMPILER_VAR_728[0] = "Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_729 =__Bah_multiple_concat(____BAH_COMPILER_VAR_728, 5);throwErr(&t,____BAH_COMPILER_VAR_729);
}
}
else {
if ((strcmp(currentType, "") == 0)) {
if ((strcmp(v->type, "") == 0)) {
v->type = tp;
}
else {
if (__builtin_expect((compTypes(tp,v->type)==false), 0)) {
char** ____BAH_COMPILER_VAR_730 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_730[4] = ".";____BAH_COMPILER_VAR_730[3] = v->type;____BAH_COMPILER_VAR_730[2] = ") as ";____BAH_COMPILER_VAR_730[1] = tp;____BAH_COMPILER_VAR_730[0] = "Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_731 =__Bah_multiple_concat(____BAH_COMPILER_VAR_730, 5);throwErr(&t,____BAH_COMPILER_VAR_731);
}
}
}
}
if ((strcmp(t.cont, "") != 0)&&(strHasPrefix(t.cont,"{")==false)) {
char** ____BAH_COMPILER_VAR_732 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_732[1] = t.cont;____BAH_COMPILER_VAR_732[0] = code;char * ____BAH_COMPILER_VAR_733 =__Bah_multiple_concat(____BAH_COMPILER_VAR_732, 2);code = ____BAH_COMPILER_VAR_733;
if ((t.isOper==false)&&(RCPavailable()==true)) {
struct variable* iv = searchVar(t.cont,elems);
if ((iv!=null)&&(iv->isConst==false)) {
toVar = true;
isPointedVar = strHasPrefix(t.cont,"&");
struct cStruct* s = searchStruct(iv->type,elems);
if ((s!=null)&&(strCount(iv->type,"*")==0)&&(s->isBinding==false)) {
if ((strCount(iv->name,"*")==0)) {
char** ____BAH_COMPILER_VAR_734 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_734[5] = "), 0)";____BAH_COMPILER_VAR_734[4] = iv->name;____BAH_COMPILER_VAR_734[3] = ", sizeof(";____BAH_COMPILER_VAR_734[2] = iv->name;____BAH_COMPILER_VAR_734[1] = "; RCP_scanStack(&";____BAH_COMPILER_VAR_734[0] = code;char * ____BAH_COMPILER_VAR_735 =__Bah_multiple_concat(____BAH_COMPILER_VAR_734, 6);code = ____BAH_COMPILER_VAR_735;
}
else {
struct string ivn = string(iv->name);
if ((string__count(&ivn,"*")>0)) {
string__replace(&ivn,"*","");
char** ____BAH_COMPILER_VAR_736 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_736[4] = "), 0)";____BAH_COMPILER_VAR_736[3] = iv->name;____BAH_COMPILER_VAR_736[2] = ", sizeof(";____BAH_COMPILER_VAR_736[1] = string__str(&ivn);____BAH_COMPILER_VAR_736[0] = "; RCP_scanStack(";char * ____BAH_COMPILER_VAR_737 =__Bah_multiple_concat(____BAH_COMPILER_VAR_736, 5);char** ____BAH_COMPILER_VAR_738 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_738[1] = ____BAH_COMPILER_VAR_737;____BAH_COMPILER_VAR_738[0] = code;char * ____BAH_COMPILER_VAR_739 =__Bah_multiple_concat(____BAH_COMPILER_VAR_738, 2);code = ____BAH_COMPILER_VAR_739;
}
else {
char** ____BAH_COMPILER_VAR_740 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_740[3] = ")";____BAH_COMPILER_VAR_740[2] = iv->name;____BAH_COMPILER_VAR_740[1] = "; RCP_incr(";____BAH_COMPILER_VAR_740[0] = code;char * ____BAH_COMPILER_VAR_741 =__Bah_multiple_concat(____BAH_COMPILER_VAR_740, 4);code = ____BAH_COMPILER_VAR_741;
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
if (__builtin_expect((i+1!=len(l)), 0)) {
throwErr(&l->data[i+1],"{TOKEN} not expected after struct initialization.");
}
char** ____BAH_COMPILER_VAR_742 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_742[1] = t.cont;____BAH_COMPILER_VAR_742[0] = code;char * ____BAH_COMPILER_VAR_743 =__Bah_multiple_concat(____BAH_COMPILER_VAR_742, 2);code = ____BAH_COMPILER_VAR_743;
}
++i;
};
if ((exists==true)) {
v->lastSet = elems;
if ((ft.parent!=null)) {
ft.parent->lastSet = elems;
}
if ((currentFn!=null)) {

                struct string ____BAH_COMPILER_VAR_744 = string(v->name);
                if ((strcmp(v->name, "this") == 0)||string__hasPrefix(&____BAH_COMPILER_VAR_744,"this->")) {
currentFn->isMut = true;
}
}
if (__builtin_expect((strlen(code)==0), 0)) {
throwErr(&ft,"Cannot re-declare {TOKEN}.");
}
if (__builtin_expect((strlen(currentType)>0), 0)) {
struct Tok st = l->data[1];
char** ____BAH_COMPILER_VAR_745 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_745[2] = "' to {TOKEN}.";____BAH_COMPILER_VAR_745[1] = ft.cont;____BAH_COMPILER_VAR_745[0] = "Cannot change the type of already declared var '";char * ____BAH_COMPILER_VAR_746 =__Bah_multiple_concat(____BAH_COMPILER_VAR_745, 3);throwErr(&st,____BAH_COMPILER_VAR_746);
}
char * preCode = "";
char * val = code;
if ((isStruct==false)) {
if (isRCPpointerType(v->type)&&(isPointedVar==false)&&(RCPavailable()==true)) {
struct string cType = getCType(v->type,elems);
if ((toVar==true)) {
if ((RCPselfRef(v)==false)) {
char** ____BAH_COMPILER_VAR_747 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_747[8] = ")";____BAH_COMPILER_VAR_747[7] = code;____BAH_COMPILER_VAR_747[6] = "*)RCP_incrIL(&";____BAH_COMPILER_VAR_747[5] = string__str(&cType);____BAH_COMPILER_VAR_747[4] = ") = *(";____BAH_COMPILER_VAR_747[3] = v->name;____BAH_COMPILER_VAR_747[2] = "*)RCP_decrIL(&";____BAH_COMPILER_VAR_747[1] = string__str(&cType);____BAH_COMPILER_VAR_747[0] = "*(";char * ____BAH_COMPILER_VAR_748 =__Bah_multiple_concat(____BAH_COMPILER_VAR_747, 9);code = ____BAH_COMPILER_VAR_748;
}
else {
struct variable* ____BAH_COMPILER_VAR_749 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_749->name = "";
____BAH_COMPILER_VAR_749->type = "";
____BAH_COMPILER_VAR_749->constVal = "";
____BAH_COMPILER_VAR_749->from = "";
struct variable* tmpV = ____BAH_COMPILER_VAR_749;
tmpV->name = genCompilerVar();
tmpV->type = v->type;
struct rope* dv = decrVar(tmpV,elems);
char** ____BAH_COMPILER_VAR_750 = alloca(13 * sizeof(char*));____BAH_COMPILER_VAR_750[12] = rope__toStr(dv);____BAH_COMPILER_VAR_750[11] = ");";____BAH_COMPILER_VAR_750[10] = code;____BAH_COMPILER_VAR_750[9] = "*)RCP_incrIL(&";____BAH_COMPILER_VAR_750[8] = string__str(&cType);____BAH_COMPILER_VAR_750[7] = " = *(";____BAH_COMPILER_VAR_750[6] = v->name;____BAH_COMPILER_VAR_750[5] = "; ";____BAH_COMPILER_VAR_750[4] = v->name;____BAH_COMPILER_VAR_750[3] = " = ";____BAH_COMPILER_VAR_750[2] = tmpV->name;____BAH_COMPILER_VAR_750[1] = " ";____BAH_COMPILER_VAR_750[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_751 =__Bah_multiple_concat(____BAH_COMPILER_VAR_750, 13);code = ____BAH_COMPILER_VAR_751;
}
}
else {
struct variable* ____BAH_COMPILER_VAR_752 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_752->name = "";
____BAH_COMPILER_VAR_752->type = "";
____BAH_COMPILER_VAR_752->constVal = "";
____BAH_COMPILER_VAR_752->from = "";
struct variable* tmpV = ____BAH_COMPILER_VAR_752;
tmpV->name = genCompilerVar();
tmpV->type = v->type;
struct rope* dv = decrVar(tmpV,elems);
char** ____BAH_COMPILER_VAR_753 = alloca(11 * sizeof(char*));____BAH_COMPILER_VAR_753[10] = rope__toStr(dv);____BAH_COMPILER_VAR_753[9] = ";";____BAH_COMPILER_VAR_753[8] = code;____BAH_COMPILER_VAR_753[7] = " = ";____BAH_COMPILER_VAR_753[6] = v->name;____BAH_COMPILER_VAR_753[5] = "; ";____BAH_COMPILER_VAR_753[4] = v->name;____BAH_COMPILER_VAR_753[3] = " = ";____BAH_COMPILER_VAR_753[2] = tmpV->name;____BAH_COMPILER_VAR_753[1] = " ";____BAH_COMPILER_VAR_753[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_754 =__Bah_multiple_concat(____BAH_COMPILER_VAR_753, 11);code = ____BAH_COMPILER_VAR_754;
}
}
else {
struct cStruct* s = searchStruct(v->type,elems);
if ((s!=null)&&(RCPavailable()==true)&&(RCPselfRef(v)==false)&&(s->isBinding==false)) {
if ((strCount(v->name,"*")==0)) {
char** ____BAH_COMPILER_VAR_755 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_755[4] = "), 1); ";____BAH_COMPILER_VAR_755[3] = v->name;____BAH_COMPILER_VAR_755[2] = ", sizeof(";____BAH_COMPILER_VAR_755[1] = v->name;____BAH_COMPILER_VAR_755[0] = "RCP_scanStack(&";char * ____BAH_COMPILER_VAR_756 =__Bah_multiple_concat(____BAH_COMPILER_VAR_755, 5);preCode = ____BAH_COMPILER_VAR_756;
}
else {
struct string vn = string(v->name);
string__replace(&vn,"*","");
char** ____BAH_COMPILER_VAR_757 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_757[4] = "), 1); ";____BAH_COMPILER_VAR_757[3] = v->name;____BAH_COMPILER_VAR_757[2] = ", sizeof(";____BAH_COMPILER_VAR_757[1] = string__str(&vn);____BAH_COMPILER_VAR_757[0] = "RCP_scanStack(";char * ____BAH_COMPILER_VAR_758 =__Bah_multiple_concat(____BAH_COMPILER_VAR_757, 5);preCode = ____BAH_COMPILER_VAR_758;
}
char** ____BAH_COMPILER_VAR_759 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_759[2] = code;____BAH_COMPILER_VAR_759[1] = " = ";____BAH_COMPILER_VAR_759[0] = v->name;char * ____BAH_COMPILER_VAR_760 =__Bah_multiple_concat(____BAH_COMPILER_VAR_759, 3);code = ____BAH_COMPILER_VAR_760;
}
else {
char** ____BAH_COMPILER_VAR_761 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_761[2] = code;____BAH_COMPILER_VAR_761[1] = " = ";____BAH_COMPILER_VAR_761[0] = v->name;char * ____BAH_COMPILER_VAR_762 =__Bah_multiple_concat(____BAH_COMPILER_VAR_761, 3);code = ____BAH_COMPILER_VAR_762;
}
}
}
else {
strTrim(&code);
if ((strHasPrefix(code,"{")==false)) {
char** ____BAH_COMPILER_VAR_763 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_763[2] = code;____BAH_COMPILER_VAR_763[1] = " = ";____BAH_COMPILER_VAR_763[0] = v->name;char * ____BAH_COMPILER_VAR_764 =__Bah_multiple_concat(____BAH_COMPILER_VAR_763, 3);code = ____BAH_COMPILER_VAR_764;
}
}
if ((v->isArray==true)) {
code = genArrRealloc(v,preCode,val,elems);
}
else {
char** ____BAH_COMPILER_VAR_765 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_765[1] = code;____BAH_COMPILER_VAR_765[0] = preCode;char * ____BAH_COMPILER_VAR_766 =__Bah_multiple_concat(____BAH_COMPILER_VAR_765, 2);code = ____BAH_COMPILER_VAR_766;
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
if (__builtin_expect((strlen(v->type)==0), 0)) {
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
char** ____BAH_COMPILER_VAR_767 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_767[1] = string__str(&ct);____BAH_COMPILER_VAR_767[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_768 =__Bah_multiple_concat(____BAH_COMPILER_VAR_767, 2);tmpfnArgsCType = ____BAH_COMPILER_VAR_768;
j = j+1;
if ((j<len(tmpfn->args))) {
char** ____BAH_COMPILER_VAR_769 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_769[1] = ",";____BAH_COMPILER_VAR_769[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_770 =__Bah_multiple_concat(____BAH_COMPILER_VAR_769, 2);tmpfnArgsCType = ____BAH_COMPILER_VAR_770;
}
};
char** ____BAH_COMPILER_VAR_771 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_771[5] = ")";____BAH_COMPILER_VAR_771[4] = tmpfnArgsCType;____BAH_COMPILER_VAR_771[3] = ")(";____BAH_COMPILER_VAR_771[2] = v->name;____BAH_COMPILER_VAR_771[1] = " (*";____BAH_COMPILER_VAR_771[0] = string__str(&tmpfnRetCType);char * ____BAH_COMPILER_VAR_772 =__Bah_multiple_concat(____BAH_COMPILER_VAR_771, 6);vct = ____BAH_COMPILER_VAR_772;
}
else {
vct = setCType(v,elems);
}
if ((strcmp(code, "") != 0)&&(shouldOnlyDecl==false)) {
if (isRCPpointerType(v->type)&&(RCPavailable()==true)&&(toVar==true)&&(isPointedVar==false)) {
struct string cType = getCType(v->type,elems);
if (isGlobal()) {
char** ____BAH_COMPILER_VAR_773 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_773[5] = ");\n";____BAH_COMPILER_VAR_773[4] = code;____BAH_COMPILER_VAR_773[3] = "*)RCP_incrIL(&";____BAH_COMPILER_VAR_773[2] = string__str(&cType);____BAH_COMPILER_VAR_773[1] = " = *(";____BAH_COMPILER_VAR_773[0] = v->name;char * ____BAH_COMPILER_VAR_774 =__Bah_multiple_concat(____BAH_COMPILER_VAR_773, 6);INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_774));
}
else {
char** ____BAH_COMPILER_VAR_775 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_775[5] = ")";____BAH_COMPILER_VAR_775[4] = code;____BAH_COMPILER_VAR_775[3] = "*)RCP_incrIL(&";____BAH_COMPILER_VAR_775[2] = string__str(&cType);____BAH_COMPILER_VAR_775[1] = " = *(";____BAH_COMPILER_VAR_775[0] = vct;char * ____BAH_COMPILER_VAR_776 =__Bah_multiple_concat(____BAH_COMPILER_VAR_775, 6);code = ____BAH_COMPILER_VAR_776;
}
}
else {
if (isGlobal()) {
char** ____BAH_COMPILER_VAR_777 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_777[3] = ";\n";____BAH_COMPILER_VAR_777[2] = code;____BAH_COMPILER_VAR_777[1] = " = ";____BAH_COMPILER_VAR_777[0] = v->name;char * ____BAH_COMPILER_VAR_778 =__Bah_multiple_concat(____BAH_COMPILER_VAR_777, 4);INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_778));
}
else {
char** ____BAH_COMPILER_VAR_779 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_779[2] = code;____BAH_COMPILER_VAR_779[1] = " = ";____BAH_COMPILER_VAR_779[0] = vct;char * ____BAH_COMPILER_VAR_780 =__Bah_multiple_concat(____BAH_COMPILER_VAR_779, 3);code = ____BAH_COMPILER_VAR_780;
}
}
}
else {
if (isRCPpointerType(v->type)&&(shouldOnlyDecl==false)) {
char** ____BAH_COMPILER_VAR_781 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_781[1] = "= null";____BAH_COMPILER_VAR_781[0] = vct;char * ____BAH_COMPILER_VAR_782 =__Bah_multiple_concat(____BAH_COMPILER_VAR_781, 2);code = ____BAH_COMPILER_VAR_782;
}
else {
code = vct;
}
}
if ((shouldOnlyDecl==true)) {
char** ____BAH_COMPILER_VAR_783 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_783[1] = vct;____BAH_COMPILER_VAR_783[0] = "extern ";char * ____BAH_COMPILER_VAR_784 =__Bah_multiple_concat(____BAH_COMPILER_VAR_783, 2);vct = ____BAH_COMPILER_VAR_784;
}
if (isGlobal()) {
v->isGlobal = true;
}
else {
v->isGlobal = false;
}
v->declScope = elems;

    unsigned int ____BAH_COMPILER_VAR_785 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_785);
    elems->vars->data[____BAH_COMPILER_VAR_785] = v;
struct variable* ____BAH_COMPILER_VAR_786 = v;
char ** ____BAH_COMPILER_VAR_788 = (char **)((char*)(____BAH_COMPILER_VAR_786) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_789 = __reflect(____BAH_COMPILER_VAR_788, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_790 = (char **)((char*)(____BAH_COMPILER_VAR_786) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_791 = __reflect(____BAH_COMPILER_VAR_790, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_792 = (char*)((char*)(____BAH_COMPILER_VAR_786) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_793 = __reflect(____BAH_COMPILER_VAR_792, sizeof(char), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_794 = (char **)((char*)(____BAH_COMPILER_VAR_786) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_795 = __reflect(____BAH_COMPILER_VAR_794, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_796 = (char*)((char*)(____BAH_COMPILER_VAR_786) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_797 = __reflect(____BAH_COMPILER_VAR_796, sizeof(char), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_798 = (char **)((char*)(____BAH_COMPILER_VAR_786) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_799 = __reflect(____BAH_COMPILER_VAR_798, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
void ** ____BAH_COMPILER_VAR_800 = (void **)((char*)(____BAH_COMPILER_VAR_786) + offsetof(struct variable, declScope));
struct reflectElement ____BAH_COMPILER_VAR_801 = __reflect(____BAH_COMPILER_VAR_800, sizeof(void *), "ptr", "declScope", 0, 0, 0, 0, offsetof(struct variable, declScope));
char* ____BAH_COMPILER_VAR_802 = (char*)((char*)(____BAH_COMPILER_VAR_786) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_803 = __reflect(____BAH_COMPILER_VAR_802, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));
struct rope** ____BAH_COMPILER_VAR_804 = (struct rope**)((char*)(____BAH_COMPILER_VAR_786) + offsetof(struct variable, declRope));
void ** ____BAH_COMPILER_VAR_806 = (void **)((char*)(____BAH_COMPILER_VAR_804) + offsetof(struct rope, left));
struct reflectElement ____BAH_COMPILER_VAR_807 = __reflect(____BAH_COMPILER_VAR_806, sizeof(void *), "ptr", "left", 0, 0, 0, 0, offsetof(struct rope, left));
void ** ____BAH_COMPILER_VAR_808 = (void **)((char*)(____BAH_COMPILER_VAR_804) + offsetof(struct rope, right));
struct reflectElement ____BAH_COMPILER_VAR_809 = __reflect(____BAH_COMPILER_VAR_808, sizeof(void *), "ptr", "right", 0, 0, 0, 0, offsetof(struct rope, right));
char ** ____BAH_COMPILER_VAR_810 = (char **)((char*)(____BAH_COMPILER_VAR_804) + offsetof(struct rope, str));
struct reflectElement ____BAH_COMPILER_VAR_811 = __reflect(____BAH_COMPILER_VAR_810, sizeof(char *), "cpstring", "str", 0, 0, 0, 0, offsetof(struct rope, str));
int* ____BAH_COMPILER_VAR_812 = (int*)((char*)(____BAH_COMPILER_VAR_804) + offsetof(struct rope, lCount));
struct reflectElement ____BAH_COMPILER_VAR_813 = __reflect(____BAH_COMPILER_VAR_812, sizeof(int), "int32", "lCount", 0, 0, 0, 0, offsetof(struct rope, lCount));
int* ____BAH_COMPILER_VAR_814 = (int*)((char*)(____BAH_COMPILER_VAR_804) + offsetof(struct rope, len));
struct reflectElement ____BAH_COMPILER_VAR_815 = __reflect(____BAH_COMPILER_VAR_814, sizeof(int), "int32", "len", 0, 0, 0, 0, offsetof(struct rope, len));
int* ____BAH_COMPILER_VAR_816 = (int*)((char*)(____BAH_COMPILER_VAR_804) + offsetof(struct rope, totalLen));
struct reflectElement ____BAH_COMPILER_VAR_817 = __reflect(____BAH_COMPILER_VAR_816, sizeof(int), "int32", "totalLen", 0, 0, 0, 0, offsetof(struct rope, totalLen));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_805 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_805->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_805->length = 6;
        ____BAH_COMPILER_VAR_805->data = memoryAlloc(____BAH_COMPILER_VAR_805->length * ____BAH_COMPILER_VAR_805->elemSize);
        ____BAH_COMPILER_VAR_805->data[0] = ____BAH_COMPILER_VAR_807;
____BAH_COMPILER_VAR_805->data[1] = ____BAH_COMPILER_VAR_809;
____BAH_COMPILER_VAR_805->data[2] = ____BAH_COMPILER_VAR_811;
____BAH_COMPILER_VAR_805->data[3] = ____BAH_COMPILER_VAR_813;
____BAH_COMPILER_VAR_805->data[4] = ____BAH_COMPILER_VAR_815;
____BAH_COMPILER_VAR_805->data[5] = ____BAH_COMPILER_VAR_817;
struct reflectElement ____BAH_COMPILER_VAR_818 = __reflect(____BAH_COMPILER_VAR_804, sizeof(struct rope), "rope*", "declRope", 0, 0, 1, ____BAH_COMPILER_VAR_805, offsetof(struct variable, declRope));
char* ____BAH_COMPILER_VAR_819 = (char*)((char*)(____BAH_COMPILER_VAR_786) + offsetof(struct variable, canBeNull));
struct reflectElement ____BAH_COMPILER_VAR_820 = __reflect(____BAH_COMPILER_VAR_819, sizeof(char), "bool", "canBeNull", 0, 0, 0, 0, offsetof(struct variable, canBeNull));
char* ____BAH_COMPILER_VAR_821 = (char*)((char*)(____BAH_COMPILER_VAR_786) + offsetof(struct variable, canBeReg));
struct reflectElement ____BAH_COMPILER_VAR_822 = __reflect(____BAH_COMPILER_VAR_821, sizeof(char), "bool", "canBeReg", 0, 0, 0, 0, offsetof(struct variable, canBeReg));
char* ____BAH_COMPILER_VAR_823 = (char*)((char*)(____BAH_COMPILER_VAR_786) + offsetof(struct variable, isReg));
struct reflectElement ____BAH_COMPILER_VAR_824 = __reflect(____BAH_COMPILER_VAR_823, sizeof(char), "bool", "isReg", 0, 0, 0, 0, offsetof(struct variable, isReg));
void ** ____BAH_COMPILER_VAR_825 = (void **)((char*)(____BAH_COMPILER_VAR_786) + offsetof(struct variable, lastSet));
struct reflectElement ____BAH_COMPILER_VAR_826 = __reflect(____BAH_COMPILER_VAR_825, sizeof(void *), "ptr", "lastSet", 0, 0, 0, 0, offsetof(struct variable, lastSet));
char* ____BAH_COMPILER_VAR_827 = (char*)((char*)(____BAH_COMPILER_VAR_786) + offsetof(struct variable, isArg));
struct reflectElement ____BAH_COMPILER_VAR_828 = __reflect(____BAH_COMPILER_VAR_827, sizeof(char), "bool", "isArg", 0, 0, 0, 0, offsetof(struct variable, isArg));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_787 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_787->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_787->length = 14;
        ____BAH_COMPILER_VAR_787->data = memoryAlloc(____BAH_COMPILER_VAR_787->length * ____BAH_COMPILER_VAR_787->elemSize);
        ____BAH_COMPILER_VAR_787->data[0] = ____BAH_COMPILER_VAR_789;
____BAH_COMPILER_VAR_787->data[1] = ____BAH_COMPILER_VAR_791;
____BAH_COMPILER_VAR_787->data[2] = ____BAH_COMPILER_VAR_793;
____BAH_COMPILER_VAR_787->data[3] = ____BAH_COMPILER_VAR_795;
____BAH_COMPILER_VAR_787->data[4] = ____BAH_COMPILER_VAR_797;
____BAH_COMPILER_VAR_787->data[5] = ____BAH_COMPILER_VAR_799;
____BAH_COMPILER_VAR_787->data[6] = ____BAH_COMPILER_VAR_801;
____BAH_COMPILER_VAR_787->data[7] = ____BAH_COMPILER_VAR_803;
____BAH_COMPILER_VAR_787->data[8] = ____BAH_COMPILER_VAR_818;
____BAH_COMPILER_VAR_787->data[9] = ____BAH_COMPILER_VAR_820;
____BAH_COMPILER_VAR_787->data[10] = ____BAH_COMPILER_VAR_822;
____BAH_COMPILER_VAR_787->data[11] = ____BAH_COMPILER_VAR_824;
____BAH_COMPILER_VAR_787->data[12] = ____BAH_COMPILER_VAR_826;
____BAH_COMPILER_VAR_787->data[13] = ____BAH_COMPILER_VAR_828;
struct reflectElement ____BAH_COMPILER_VAR_829 = __reflect(____BAH_COMPILER_VAR_786, sizeof(struct variable), "variable*", "v", 0, 0, 1, ____BAH_COMPILER_VAR_787, 0);
debugPrint("var_declaration",ft.line,____BAH_COMPILER_VAR_829);
if (isGlobal()) {
char** ____BAH_COMPILER_VAR_830 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_830[1] = ";\n";____BAH_COMPILER_VAR_830[0] = vct;char * ____BAH_COMPILER_VAR_831 =__Bah_multiple_concat(____BAH_COMPILER_VAR_830, 2);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_831));
}
}
if (isGlobal()) {
if ((isSubObject==false)) {
INIT = rope__add(INIT, rope(NEXT_LINE));
}
NEXT_LINE = "";
}
else {
char** ____BAH_COMPILER_VAR_832 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_832[1] = ";\n";____BAH_COMPILER_VAR_832[0] = code;char * ____BAH_COMPILER_VAR_833 =__Bah_multiple_concat(____BAH_COMPILER_VAR_832, 2);struct rope* declR = rope(____BAH_COMPILER_VAR_833);
if ((exists==false)) {
v->declRope = declR;
v->canBeReg = true;
}
OUTPUT = rope__add(OUTPUT, declR);
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
char** ____BAH_COMPILER_VAR_834 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_834[1] = string__str(&ct);____BAH_COMPILER_VAR_834[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_835 =__Bah_multiple_concat(____BAH_COMPILER_VAR_834, 2);tmpfnArgsCType = ____BAH_COMPILER_VAR_835;
j = j+1;
if ((j<len(tmpfn->args))) {
char** ____BAH_COMPILER_VAR_836 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_836[1] = ",";____BAH_COMPILER_VAR_836[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_837 =__Bah_multiple_concat(____BAH_COMPILER_VAR_836, 2);tmpfnArgsCType = ____BAH_COMPILER_VAR_837;
}
};
char** ____BAH_COMPILER_VAR_838 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_838[5] = ")";____BAH_COMPILER_VAR_838[4] = tmpfnArgsCType;____BAH_COMPILER_VAR_838[3] = ")(";____BAH_COMPILER_VAR_838[2] = elemName;____BAH_COMPILER_VAR_838[1] = " (*";____BAH_COMPILER_VAR_838[0] = string__str(&tmpfnRetCType);char * ____BAH_COMPILER_VAR_839 =__Bah_multiple_concat(____BAH_COMPILER_VAR_838, 6);return ____BAH_COMPILER_VAR_839;
};
char * parseFnHeader(char * prev,__BAH_ARR_TYPE_Tok l,long int* i,struct func* fn,struct Elems* elems){
register long int j = *i;
struct Tok ft = l->data[j];
char * tpdf = "";
if (__builtin_expect((ft.type!=TOKEN_TYPE_VAR), 0)) {
throwErr(&ft,"Cannot use {TOKEN} as function name.");
}
char** ____BAH_COMPILER_VAR_840 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_840[1] = ft.cont;____BAH_COMPILER_VAR_840[0] = prev;char * ____BAH_COMPILER_VAR_841 =__Bah_multiple_concat(____BAH_COMPILER_VAR_840, 2);fn->name = ____BAH_COMPILER_VAR_841;
array(struct variable*)* arguments = memoryAlloc(sizeof(array(struct variable*)));

arguments->length = 0;
arguments->elemSize = sizeof(struct variable*);
char** ____BAH_COMPILER_VAR_842 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_842[1] = "(";____BAH_COMPILER_VAR_842[0] = fn->name;char * ____BAH_COMPILER_VAR_843 =__Bah_multiple_concat(____BAH_COMPILER_VAR_842, 2);char * code = ____BAH_COMPILER_VAR_843;
j = j+2;
struct Tok t = l->data[j];
if ((strcmp(t.cont, ")") != 0)) {
while ((j<len(l))) {
t = l->data[j];
if (__builtin_expect((t.type!=TOKEN_TYPE_VAR), 0)) {
throwErr(&t,"Cannot use {TOKEN} as argument name.");
}
char * argName = t.cont;
j = j+1;
if (__builtin_expect((j>=len(l)), 0)) {
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
char** ____BAH_COMPILER_VAR_844 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_844[1] = t.cont;____BAH_COMPILER_VAR_844[0] = argType;char * ____BAH_COMPILER_VAR_845 =__Bah_multiple_concat(____BAH_COMPILER_VAR_844, 2);argType = ____BAH_COMPILER_VAR_845;
}
}
else {
isComa = true;
break;
}
j = j+1;
};
struct variable* ____BAH_COMPILER_VAR_846 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_846->name = "";
____BAH_COMPILER_VAR_846->type = "";
____BAH_COMPILER_VAR_846->constVal = "";
____BAH_COMPILER_VAR_846->from = "";
struct variable* argument = ____BAH_COMPILER_VAR_846;
argument->name = argName;
argument->type = argType;

    unsigned int ____BAH_COMPILER_VAR_847 = len(arguments);
    __Bah_realocate_arr(arguments, ____BAH_COMPILER_VAR_847);
    arguments->data[____BAH_COMPILER_VAR_847] = argument;
struct string argCType = getCType(argType,elems);
struct string cfrt = string(argType);
char * newArgType = string__str(&argCType);
if ((string__hasPrefix(&cfrt,"[]")==1)) {
string__trimLeft(&cfrt,2);
if (string__hasSuffix(&cfrt,"*")) {
long int nbast = string__count(&cfrt,"*");
string__trimRight(&cfrt,nbast);
}
char** ____BAH_COMPILER_VAR_848 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_848[1] = string__str(&cfrt);____BAH_COMPILER_VAR_848[0] = "__BAH_ARR_TYPE_";char * ____BAH_COMPILER_VAR_849 =__Bah_multiple_concat(____BAH_COMPILER_VAR_848, 2);newArgType = ____BAH_COMPILER_VAR_849;
array(char *)* csatd = compilerState.arrTypesDecl;
if ((inArrayStr(newArgType,csatd)==false)) {

    unsigned int ____BAH_COMPILER_VAR_850 = len(csatd);
    __Bah_realocate_arr(csatd, ____BAH_COMPILER_VAR_850);
    csatd->data[____BAH_COMPILER_VAR_850] = newArgType;
char** ____BAH_COMPILER_VAR_851 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_851[5] = ";\n";____BAH_COMPILER_VAR_851[4] = newArgType;____BAH_COMPILER_VAR_851[3] = " ";____BAH_COMPILER_VAR_851[2] = string__str(&argCType);____BAH_COMPILER_VAR_851[1] = "typedef ";____BAH_COMPILER_VAR_851[0] = tpdf;char * ____BAH_COMPILER_VAR_852 =__Bah_multiple_concat(____BAH_COMPILER_VAR_851, 6);tpdf = ____BAH_COMPILER_VAR_852;
}
}
if ((string__hasPrefix(&cfrt,"function(")==1)) {
char** ____BAH_COMPILER_VAR_853 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_853[1] = getCfunctionType(&cfrt,argName,elems);____BAH_COMPILER_VAR_853[0] = code;char * ____BAH_COMPILER_VAR_854 =__Bah_multiple_concat(____BAH_COMPILER_VAR_853, 2);code = ____BAH_COMPILER_VAR_854;
}
else {
char** ____BAH_COMPILER_VAR_855 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_855[3] = argName;____BAH_COMPILER_VAR_855[2] = " ";____BAH_COMPILER_VAR_855[1] = newArgType;____BAH_COMPILER_VAR_855[0] = code;char * ____BAH_COMPILER_VAR_856 =__Bah_multiple_concat(____BAH_COMPILER_VAR_855, 4);code = ____BAH_COMPILER_VAR_856;
}
if ((isComa==true)) {
char** ____BAH_COMPILER_VAR_857 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_857[1] = ",";____BAH_COMPILER_VAR_857[0] = code;char * ____BAH_COMPILER_VAR_858 =__Bah_multiple_concat(____BAH_COMPILER_VAR_857, 2);code = ____BAH_COMPILER_VAR_858;
}
else {
char** ____BAH_COMPILER_VAR_859 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_859[1] = ")";____BAH_COMPILER_VAR_859[0] = code;char * ____BAH_COMPILER_VAR_860 =__Bah_multiple_concat(____BAH_COMPILER_VAR_859, 2);code = ____BAH_COMPILER_VAR_860;
break;
}
j = j+1;
};
}
else {
char** ____BAH_COMPILER_VAR_861 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_861[1] = ")";____BAH_COMPILER_VAR_861[0] = code;char * ____BAH_COMPILER_VAR_862 =__Bah_multiple_concat(____BAH_COMPILER_VAR_861, 2);code = ____BAH_COMPILER_VAR_862;
}
j = j+1;
struct variable* ____BAH_COMPILER_VAR_863 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_863->name = "";
____BAH_COMPILER_VAR_863->type = "";
____BAH_COMPILER_VAR_863->constVal = "";
____BAH_COMPILER_VAR_863->from = "";
struct variable* returns = ____BAH_COMPILER_VAR_863;
returns->type = "";
while ((j<len(l))) {
t = l->data[j];
if ((strcmp(t.cont, "{") == 0)) {
break;
}
char** ____BAH_COMPILER_VAR_864 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_864[1] = t.cont;____BAH_COMPILER_VAR_864[0] = returns->type;char * ____BAH_COMPILER_VAR_865 =__Bah_multiple_concat(____BAH_COMPILER_VAR_864, 2);returns->type = ____BAH_COMPILER_VAR_865;
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
char** ____BAH_COMPILER_VAR_866 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_866[1] = string__str(&cfrt);____BAH_COMPILER_VAR_866[0] = "__BAH_ARR_TYPE_";char * ____BAH_COMPILER_VAR_867 =__Bah_multiple_concat(____BAH_COMPILER_VAR_866, 2);newFnRetType = ____BAH_COMPILER_VAR_867;
array(char *)* csatd = compilerState.arrTypesDecl;
if ((inArrayStr(newFnRetType,csatd)==false)) {

    unsigned int ____BAH_COMPILER_VAR_868 = len(csatd);
    __Bah_realocate_arr(csatd, ____BAH_COMPILER_VAR_868);
    csatd->data[____BAH_COMPILER_VAR_868] = newFnRetType;
char** ____BAH_COMPILER_VAR_869 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_869[5] = ";\n";____BAH_COMPILER_VAR_869[4] = newFnRetType;____BAH_COMPILER_VAR_869[3] = " ";____BAH_COMPILER_VAR_869[2] = string__str(&fnRetType);____BAH_COMPILER_VAR_869[1] = "typedef ";____BAH_COMPILER_VAR_869[0] = tpdf;char * ____BAH_COMPILER_VAR_870 =__Bah_multiple_concat(____BAH_COMPILER_VAR_869, 6);tpdf = ____BAH_COMPILER_VAR_870;
}
}
char** ____BAH_COMPILER_VAR_871 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_871[3] = code;____BAH_COMPILER_VAR_871[2] = " ";____BAH_COMPILER_VAR_871[1] = newFnRetType;____BAH_COMPILER_VAR_871[0] = tpdf;char * ____BAH_COMPILER_VAR_872 =__Bah_multiple_concat(____BAH_COMPILER_VAR_871, 4);code = ____BAH_COMPILER_VAR_872;
return code;
};
void parseStruct(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
struct cStruct* ____BAH_COMPILER_VAR_873 = memoryAlloc(sizeof(struct cStruct));
____BAH_COMPILER_VAR_873->name = "";
____BAH_COMPILER_VAR_873->members = memoryAlloc(sizeof(array(struct structMemb*)));
            ____BAH_COMPILER_VAR_873->members->length = 0;
            ____BAH_COMPILER_VAR_873->members->elemSize = sizeof(struct structMemb*);
            ____BAH_COMPILER_VAR_873->methods = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_873->methods->length = 0;
            ____BAH_COMPILER_VAR_873->methods->elemSize = sizeof(struct func*);
            ____BAH_COMPILER_VAR_873->postCode = "";
____BAH_COMPILER_VAR_873->extendedFrom = "";
struct cStruct* s = ____BAH_COMPILER_VAR_873;
array(struct cStruct*)* structs = elems->structs;

    unsigned int ____BAH_COMPILER_VAR_874 = len(structs);
    __Bah_realocate_arr(structs, ____BAH_COMPILER_VAR_874);
    structs->data[____BAH_COMPILER_VAR_874] = s;
array(struct func*)* methds = s->methods;
if (__builtin_expect((len(l)<4), 0)) {
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
if (__builtin_expect((nameToken.type!=TOKEN_TYPE_VAR), 0)) {
throwErr(&nameToken,"Cannot use {TOKEN} as struct name.");
}
struct cStruct* os = searchStruct(nameToken.cont,elems);
if (__builtin_expect((os!=null), 0)) {
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
if (__builtin_expect((extdSNameTk.type!=TOKEN_TYPE_VAR), 0)) {
throwErr(&extdSNameTk,"Cannot use {TOKEN} as struct name.");
}
struct cStruct* extdS = searchStruct(extdSNameTk.cont,elems);
if (__builtin_expect((extdS==null), 0)) {
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
char** ____BAH_COMPILER_VAR_875 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_875[1] = string__str(&ct);____BAH_COMPILER_VAR_875[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_876 =__Bah_multiple_concat(____BAH_COMPILER_VAR_875, 2);tmpfnArgsCType = ____BAH_COMPILER_VAR_876;
j = j+1;
if ((j<len(tmpfn->args))) {
char** ____BAH_COMPILER_VAR_877 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_877[1] = ",";____BAH_COMPILER_VAR_877[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_878 =__Bah_multiple_concat(____BAH_COMPILER_VAR_877, 2);tmpfnArgsCType = ____BAH_COMPILER_VAR_878;
}
};
char** ____BAH_COMPILER_VAR_879 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_879[5] = ")";____BAH_COMPILER_VAR_879[4] = tmpfnArgsCType;____BAH_COMPILER_VAR_879[3] = ")(";____BAH_COMPILER_VAR_879[2] = em->name;____BAH_COMPILER_VAR_879[1] = " (*";____BAH_COMPILER_VAR_879[0] = string__str(&tmpfnRetCType);char * ____BAH_COMPILER_VAR_880 =__Bah_multiple_concat(____BAH_COMPILER_VAR_879, 6);membDeclStr = ____BAH_COMPILER_VAR_880;
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

    unsigned int ____BAH_COMPILER_VAR_881 = len(allMembs);
    __Bah_realocate_arr(allMembs, ____BAH_COMPILER_VAR_881);
    allMembs->data[____BAH_COMPILER_VAR_881] = membDeclStr;

    unsigned int ____BAH_COMPILER_VAR_882 = len(members);
    __Bah_realocate_arr(members, ____BAH_COMPILER_VAR_882);
    members->data[____BAH_COMPILER_VAR_882] = em;
j = j+1;
};
}
else {
throwErr(&st,"Cannot use keyword {TOKEN} in struct declaration.");
}
}
struct Tok braceTk = l->data[i];
++i;
if (__builtin_expect((strcmp(braceTk.cont, "{") != 0), 0)) {
throwErr(&braceTk,"Cannot use {TOKEN} in struct declaration.");
}
postDeclHandle = rope("");
OUTPUT = rope__add(OUTPUT, postDeclHandle);
struct rope* OOUT = OUTPUT;
char * nextLine = "";
while ((i<len(l))) {
struct Tok t = l->data[i];
long int max = i+2;
if (__builtin_expect((max>=len(l)), 0)) {
if ((t.type==TOKEN_TYPE_ENCL)&&(strcmp(t.cont, "}") == 0)) {
break;
}
throwErr(&l->data[len(l)-1],"Not enough argument in member declaration, ending by {TOKEN}.");
}
struct structMemb* ____BAH_COMPILER_VAR_883 = memoryAlloc(sizeof(struct structMemb));
____BAH_COMPILER_VAR_883->name = "";
____BAH_COMPILER_VAR_883->type = "";
____BAH_COMPILER_VAR_883->constVal = "";
____BAH_COMPILER_VAR_883->from = "";
____BAH_COMPILER_VAR_883->def = "";
struct structMemb* memb = ____BAH_COMPILER_VAR_883;
if (__builtin_expect((t.type!=TOKEN_TYPE_VAR), 0)) {
throwErr(&t,"Cannot use {TOKEN} as member name.");
}
memb->name = t.cont;
register long int ii = 0;
while ((ii<len(members))) {
struct structMemb* m = members->data[ii];
if (__builtin_expect((strcmp(m->name, memb->name) == 0), 0)) {
throwErr(&t,"Member {TOKEN} has already been declared.");
}
ii = ii+1;
};
++i;
t = l->data[i];
if ((strcmp(t.cont, ":") != 0)) {
if (__builtin_expect((strcmp(t.cont, "(") != 0), 0)) {
throwErr(&t,"Member name should be followed by ':' not {TOKEN}.");
}
else {
char** ____BAH_COMPILER_VAR_884 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_884[1] = "__";____BAH_COMPILER_VAR_884[0] = s->name;char * ____BAH_COMPILER_VAR_885 =__Bah_multiple_concat(____BAH_COMPILER_VAR_884, 2);char * fnPrefix = ____BAH_COMPILER_VAR_885;
struct func* ____BAH_COMPILER_VAR_886 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_886->name = "";
____BAH_COMPILER_VAR_886->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_886->args->length = 0;
            ____BAH_COMPILER_VAR_886->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_886->from = "";
____BAH_COMPILER_VAR_886->file = "";
____BAH_COMPILER_VAR_886->line = 1;
struct func* fn = ____BAH_COMPILER_VAR_886;
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
register long int j = i-1;
while ((j<len(l))) {
t = l->data[j];
if ((strcmp(t.cont, "{") == 0)) {
break;
}

    unsigned int ____BAH_COMPILER_VAR_887 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_887);
    nl->data[____BAH_COMPILER_VAR_887] = t;
if ((j==i)) {
t.type = TOKEN_TYPE_VAR;
t.cont = "this";
t.isValue = true;

    unsigned int ____BAH_COMPILER_VAR_888 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_888);
    nl->data[____BAH_COMPILER_VAR_888] = t;
t.type = TOKEN_TYPE_VAR;
char** ____BAH_COMPILER_VAR_889 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_889[1] = "*";____BAH_COMPILER_VAR_889[0] = s->name;char * ____BAH_COMPILER_VAR_890 =__Bah_multiple_concat(____BAH_COMPILER_VAR_889, 2);t.cont = ____BAH_COMPILER_VAR_890;
t.isValue = true;

    unsigned int ____BAH_COMPILER_VAR_891 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_891);
    nl->data[____BAH_COMPILER_VAR_891] = t;
struct Tok nt = l->data[j+1];
if ((strcmp(nt.cont, ")") != 0)) {
t.type = TOKEN_TYPE_SYNTAX;
t.cont = ",";
t.isValue = false;

    unsigned int ____BAH_COMPILER_VAR_892 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_892);
    nl->data[____BAH_COMPILER_VAR_892] = t;
}
}
j = j+1;
};
--i;
long int nli = 0;
char * ____BAH_COMPILER_VAR_893 =parseFnHeader(fnPrefix,nl,&nli,fn,elems);struct rope* code = rope(____BAH_COMPILER_VAR_893);
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

    unsigned int ____BAH_COMPILER_VAR_894 = len(fnElems->vars);
    __Bah_realocate_arr(fnElems->vars, ____BAH_COMPILER_VAR_894);
    fnElems->vars->data[____BAH_COMPILER_VAR_894] = a;
};
array(struct func*)* fns = elems->fns;

    unsigned int ____BAH_COMPILER_VAR_895 = len(fns);
    __Bah_realocate_arr(fns, ____BAH_COMPILER_VAR_895);
    fns->data[____BAH_COMPILER_VAR_895] = fn;
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

    unsigned int ____BAH_COMPILER_VAR_896 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_896);
    tokens->data[____BAH_COMPILER_VAR_896] = t;
++i;
};
struct func* ____BAH_COMPILER_VAR_897 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_897->name = "";
____BAH_COMPILER_VAR_897->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_897->args->length = 0;
            ____BAH_COMPILER_VAR_897->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_897->from = "";
____BAH_COMPILER_VAR_897->file = "";
____BAH_COMPILER_VAR_897->line = 1;
struct func* mfn = ____BAH_COMPILER_VAR_897;
mfn->args = fn->args;
mfn->name = fn->name;
mfn->returns = fn->returns;
mfn->from = s->name;
strTrimLeft(&mfn->name,strlen(fnPrefix));

    unsigned int ____BAH_COMPILER_VAR_898 = len(methds);
    __Bah_realocate_arr(methds, ____BAH_COMPILER_VAR_898);
    methds->data[____BAH_COMPILER_VAR_898] = mfn;
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
if (__builtin_expect((strlen(fn->returns->type)>0), 0)) {
char** ____BAH_COMPILER_VAR_899 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_899[2] = "' is not returned.";____BAH_COMPILER_VAR_899[1] = fn->name;____BAH_COMPILER_VAR_899[0] = "Function '";char * ____BAH_COMPILER_VAR_900 =__Bah_multiple_concat(____BAH_COMPILER_VAR_899, 3);throwErr(&l->data[len(l)-1],____BAH_COMPILER_VAR_900);
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
char** ____BAH_COMPILER_VAR_901 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_901[1] = rope__toStr(code);____BAH_COMPILER_VAR_901[0] = nextLine;char * ____BAH_COMPILER_VAR_902 =__Bah_multiple_concat(____BAH_COMPILER_VAR_901, 2);nextLine = ____BAH_COMPILER_VAR_902;
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
char** ____BAH_COMPILER_VAR_903 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_903[1] = t.cont;____BAH_COMPILER_VAR_903[0] = mbmType;char * ____BAH_COMPILER_VAR_904 =__Bah_multiple_concat(____BAH_COMPILER_VAR_903, 2);mbmType = ____BAH_COMPILER_VAR_904;
++i;
};
memb->type = mbmType;
++i;
t = l->data[i];
if ((i<len(l))) {
if ((strcmp(t.cont, "=") == 0)) {
++i;
t = l->data[i];
if (__builtin_expect((t.isValue==false), 0)) {
throwErr(&t,"Cannot use {TOKEN} as default value for member.");
}
char * tt = getTypeFromToken(&t,true,elems);
if (__builtin_expect((compTypes(tt,memb->type)==false), 0)) {
char** ____BAH_COMPILER_VAR_905 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_905[4] = " for member.";____BAH_COMPILER_VAR_905[3] = memb->type;____BAH_COMPILER_VAR_905[2] = ") as ";____BAH_COMPILER_VAR_905[1] = tt;____BAH_COMPILER_VAR_905[0] = "Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_906 =__Bah_multiple_concat(____BAH_COMPILER_VAR_905, 5);throwErr(&t,____BAH_COMPILER_VAR_906);
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

    unsigned int ____BAH_COMPILER_VAR_907 = len(members);
    __Bah_realocate_arr(members, ____BAH_COMPILER_VAR_907);
    members->data[____BAH_COMPILER_VAR_907] = memb;
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
char** ____BAH_COMPILER_VAR_908 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_908[1] = string__str(&ct);____BAH_COMPILER_VAR_908[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_909 =__Bah_multiple_concat(____BAH_COMPILER_VAR_908, 2);tmpfnArgsCType = ____BAH_COMPILER_VAR_909;
j = j+1;
if ((j<len(tmpfn->args))) {
char** ____BAH_COMPILER_VAR_910 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_910[1] = ",";____BAH_COMPILER_VAR_910[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_911 =__Bah_multiple_concat(____BAH_COMPILER_VAR_910, 2);tmpfnArgsCType = ____BAH_COMPILER_VAR_911;
}
};
char** ____BAH_COMPILER_VAR_912 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_912[5] = ")";____BAH_COMPILER_VAR_912[4] = tmpfnArgsCType;____BAH_COMPILER_VAR_912[3] = ")(";____BAH_COMPILER_VAR_912[2] = memb->name;____BAH_COMPILER_VAR_912[1] = " (*";____BAH_COMPILER_VAR_912[0] = string__str(&tmpfnRetCType);char * ____BAH_COMPILER_VAR_913 =__Bah_multiple_concat(____BAH_COMPILER_VAR_912, 6);membDeclStr = ____BAH_COMPILER_VAR_913;
}
else {
struct string membDecl = getCType(memb->type,elems);
char** ____BAH_COMPILER_VAR_914 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_914[1] = memb->name;____BAH_COMPILER_VAR_914[0] = " ";char * ____BAH_COMPILER_VAR_915 =__Bah_multiple_concat(____BAH_COMPILER_VAR_914, 2);string__append(&membDecl,____BAH_COMPILER_VAR_915);
membDeclStr = string__str(&membDecl);
}

    unsigned int ____BAH_COMPILER_VAR_916 = len(allMembs);
    __Bah_realocate_arr(allMembs, ____BAH_COMPILER_VAR_916);
    allMembs->data[____BAH_COMPILER_VAR_916] = membDeclStr;
++i;
};
s->members = members;
if ((doesOutput==true)) {
OUTPUT = OOUT;
NEXT_LINE = nextLine;
char** ____BAH_COMPILER_VAR_917 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_917[2] = " {\n";____BAH_COMPILER_VAR_917[1] = s->name;____BAH_COMPILER_VAR_917[0] = "struct ";char * ____BAH_COMPILER_VAR_918 =__Bah_multiple_concat(____BAH_COMPILER_VAR_917, 3);struct rope* code = rope(____BAH_COMPILER_VAR_918);
i = 0;
while ((i<len(allMembs))) {
char * m = allMembs->data[i];
char** ____BAH_COMPILER_VAR_919 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_919[1] = ";\n";____BAH_COMPILER_VAR_919[0] = m;char * ____BAH_COMPILER_VAR_920 =__Bah_multiple_concat(____BAH_COMPILER_VAR_919, 2);code = rope__add(code, rope(____BAH_COMPILER_VAR_920));
++i;
};
code = rope__add(code, rope("};\n"));
OUTPUT = rope__add(OUTPUT, code);
char * phd = rope__toStr(postDeclHandle);
OUTPUT->totalLen = OUTPUT->totalLen+ropeSet(postDeclHandle,"");
char** ____BAH_COMPILER_VAR_921 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_921[1] = phd;____BAH_COMPILER_VAR_921[0] = NEXT_LINE;char * ____BAH_COMPILER_VAR_922 =__Bah_multiple_concat(____BAH_COMPILER_VAR_921, 2);NEXT_LINE = ____BAH_COMPILER_VAR_922;
}
if ((debug==true)) {
struct debugStruct* ____BAH_COMPILER_VAR_923 = memoryAlloc(sizeof(struct debugStruct));
____BAH_COMPILER_VAR_923->membs = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_923->membs->length = 0;
            ____BAH_COMPILER_VAR_923->membs->elemSize = sizeof(struct variable*);
            struct debugStruct* ds = ____BAH_COMPILER_VAR_923;
ds->name = s->name;
i = 0;
while ((i<len(s->members))) {
struct structMemb* m = s->members->data[i];
struct variable* ____BAH_COMPILER_VAR_924 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_924->name = "";
____BAH_COMPILER_VAR_924->type = "";
____BAH_COMPILER_VAR_924->constVal = "";
____BAH_COMPILER_VAR_924->from = "";
struct variable* mv = ____BAH_COMPILER_VAR_924;
mv->name = m->name;
mv->type = m->type;
mv->isConst = false;
mv->isArray = m->isArray;

    unsigned int ____BAH_COMPILER_VAR_925 = i;
    __Bah_realocate_arr(ds->membs, ____BAH_COMPILER_VAR_925);
    ds->membs->data[____BAH_COMPILER_VAR_925] = mv;
i = i+1;
};
struct debugStruct* ____BAH_COMPILER_VAR_926 = ds;
char ** ____BAH_COMPILER_VAR_928 = (char **)((char*)(____BAH_COMPILER_VAR_926) + offsetof(struct debugStruct, name));
struct reflectElement ____BAH_COMPILER_VAR_929 = __reflect(____BAH_COMPILER_VAR_928, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct debugStruct, name));
array(struct variable*)** ____BAH_COMPILER_VAR_930 = (array(struct variable*)**)((char*)(____BAH_COMPILER_VAR_926) + offsetof(struct debugStruct, membs));
struct variable** ____BAH_COMPILER_VAR_931 = 0;
char ** ____BAH_COMPILER_VAR_933 = (char **)((char*)(____BAH_COMPILER_VAR_931) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_934 = __reflect(____BAH_COMPILER_VAR_933, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_935 = (char **)((char*)(____BAH_COMPILER_VAR_931) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_936 = __reflect(____BAH_COMPILER_VAR_935, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_937 = (char*)((char*)(____BAH_COMPILER_VAR_931) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_938 = __reflect(____BAH_COMPILER_VAR_937, sizeof(char), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_939 = (char **)((char*)(____BAH_COMPILER_VAR_931) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_940 = __reflect(____BAH_COMPILER_VAR_939, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_941 = (char*)((char*)(____BAH_COMPILER_VAR_931) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_942 = __reflect(____BAH_COMPILER_VAR_941, sizeof(char), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_943 = (char **)((char*)(____BAH_COMPILER_VAR_931) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_944 = __reflect(____BAH_COMPILER_VAR_943, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
void ** ____BAH_COMPILER_VAR_945 = (void **)((char*)(____BAH_COMPILER_VAR_931) + offsetof(struct variable, declScope));
struct reflectElement ____BAH_COMPILER_VAR_946 = __reflect(____BAH_COMPILER_VAR_945, sizeof(void *), "ptr", "declScope", 0, 0, 0, 0, offsetof(struct variable, declScope));
char* ____BAH_COMPILER_VAR_947 = (char*)((char*)(____BAH_COMPILER_VAR_931) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_948 = __reflect(____BAH_COMPILER_VAR_947, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));
struct rope** ____BAH_COMPILER_VAR_949 = (struct rope**)((char*)(____BAH_COMPILER_VAR_931) + offsetof(struct variable, declRope));
void ** ____BAH_COMPILER_VAR_951 = (void **)((char*)(____BAH_COMPILER_VAR_949) + offsetof(struct rope, left));
struct reflectElement ____BAH_COMPILER_VAR_952 = __reflect(____BAH_COMPILER_VAR_951, sizeof(void *), "ptr", "left", 0, 0, 0, 0, offsetof(struct rope, left));
void ** ____BAH_COMPILER_VAR_953 = (void **)((char*)(____BAH_COMPILER_VAR_949) + offsetof(struct rope, right));
struct reflectElement ____BAH_COMPILER_VAR_954 = __reflect(____BAH_COMPILER_VAR_953, sizeof(void *), "ptr", "right", 0, 0, 0, 0, offsetof(struct rope, right));
char ** ____BAH_COMPILER_VAR_955 = (char **)((char*)(____BAH_COMPILER_VAR_949) + offsetof(struct rope, str));
struct reflectElement ____BAH_COMPILER_VAR_956 = __reflect(____BAH_COMPILER_VAR_955, sizeof(char *), "cpstring", "str", 0, 0, 0, 0, offsetof(struct rope, str));
int* ____BAH_COMPILER_VAR_957 = (int*)((char*)(____BAH_COMPILER_VAR_949) + offsetof(struct rope, lCount));
struct reflectElement ____BAH_COMPILER_VAR_958 = __reflect(____BAH_COMPILER_VAR_957, sizeof(int), "int32", "lCount", 0, 0, 0, 0, offsetof(struct rope, lCount));
int* ____BAH_COMPILER_VAR_959 = (int*)((char*)(____BAH_COMPILER_VAR_949) + offsetof(struct rope, len));
struct reflectElement ____BAH_COMPILER_VAR_960 = __reflect(____BAH_COMPILER_VAR_959, sizeof(int), "int32", "len", 0, 0, 0, 0, offsetof(struct rope, len));
int* ____BAH_COMPILER_VAR_961 = (int*)((char*)(____BAH_COMPILER_VAR_949) + offsetof(struct rope, totalLen));
struct reflectElement ____BAH_COMPILER_VAR_962 = __reflect(____BAH_COMPILER_VAR_961, sizeof(int), "int32", "totalLen", 0, 0, 0, 0, offsetof(struct rope, totalLen));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_950 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_950->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_950->length = 6;
        ____BAH_COMPILER_VAR_950->data = memoryAlloc(____BAH_COMPILER_VAR_950->length * ____BAH_COMPILER_VAR_950->elemSize);
        ____BAH_COMPILER_VAR_950->data[0] = ____BAH_COMPILER_VAR_952;
____BAH_COMPILER_VAR_950->data[1] = ____BAH_COMPILER_VAR_954;
____BAH_COMPILER_VAR_950->data[2] = ____BAH_COMPILER_VAR_956;
____BAH_COMPILER_VAR_950->data[3] = ____BAH_COMPILER_VAR_958;
____BAH_COMPILER_VAR_950->data[4] = ____BAH_COMPILER_VAR_960;
____BAH_COMPILER_VAR_950->data[5] = ____BAH_COMPILER_VAR_962;
struct reflectElement ____BAH_COMPILER_VAR_963 = __reflect(____BAH_COMPILER_VAR_949, sizeof(struct rope), "rope*", "declRope", 0, 0, 1, ____BAH_COMPILER_VAR_950, offsetof(struct variable, declRope));
char* ____BAH_COMPILER_VAR_964 = (char*)((char*)(____BAH_COMPILER_VAR_931) + offsetof(struct variable, canBeNull));
struct reflectElement ____BAH_COMPILER_VAR_965 = __reflect(____BAH_COMPILER_VAR_964, sizeof(char), "bool", "canBeNull", 0, 0, 0, 0, offsetof(struct variable, canBeNull));
char* ____BAH_COMPILER_VAR_966 = (char*)((char*)(____BAH_COMPILER_VAR_931) + offsetof(struct variable, canBeReg));
struct reflectElement ____BAH_COMPILER_VAR_967 = __reflect(____BAH_COMPILER_VAR_966, sizeof(char), "bool", "canBeReg", 0, 0, 0, 0, offsetof(struct variable, canBeReg));
char* ____BAH_COMPILER_VAR_968 = (char*)((char*)(____BAH_COMPILER_VAR_931) + offsetof(struct variable, isReg));
struct reflectElement ____BAH_COMPILER_VAR_969 = __reflect(____BAH_COMPILER_VAR_968, sizeof(char), "bool", "isReg", 0, 0, 0, 0, offsetof(struct variable, isReg));
void ** ____BAH_COMPILER_VAR_970 = (void **)((char*)(____BAH_COMPILER_VAR_931) + offsetof(struct variable, lastSet));
struct reflectElement ____BAH_COMPILER_VAR_971 = __reflect(____BAH_COMPILER_VAR_970, sizeof(void *), "ptr", "lastSet", 0, 0, 0, 0, offsetof(struct variable, lastSet));
char* ____BAH_COMPILER_VAR_972 = (char*)((char*)(____BAH_COMPILER_VAR_931) + offsetof(struct variable, isArg));
struct reflectElement ____BAH_COMPILER_VAR_973 = __reflect(____BAH_COMPILER_VAR_972, sizeof(char), "bool", "isArg", 0, 0, 0, 0, offsetof(struct variable, isArg));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_932 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_932->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_932->length = 14;
        ____BAH_COMPILER_VAR_932->data = memoryAlloc(____BAH_COMPILER_VAR_932->length * ____BAH_COMPILER_VAR_932->elemSize);
        ____BAH_COMPILER_VAR_932->data[0] = ____BAH_COMPILER_VAR_934;
____BAH_COMPILER_VAR_932->data[1] = ____BAH_COMPILER_VAR_936;
____BAH_COMPILER_VAR_932->data[2] = ____BAH_COMPILER_VAR_938;
____BAH_COMPILER_VAR_932->data[3] = ____BAH_COMPILER_VAR_940;
____BAH_COMPILER_VAR_932->data[4] = ____BAH_COMPILER_VAR_942;
____BAH_COMPILER_VAR_932->data[5] = ____BAH_COMPILER_VAR_944;
____BAH_COMPILER_VAR_932->data[6] = ____BAH_COMPILER_VAR_946;
____BAH_COMPILER_VAR_932->data[7] = ____BAH_COMPILER_VAR_948;
____BAH_COMPILER_VAR_932->data[8] = ____BAH_COMPILER_VAR_963;
____BAH_COMPILER_VAR_932->data[9] = ____BAH_COMPILER_VAR_965;
____BAH_COMPILER_VAR_932->data[10] = ____BAH_COMPILER_VAR_967;
____BAH_COMPILER_VAR_932->data[11] = ____BAH_COMPILER_VAR_969;
____BAH_COMPILER_VAR_932->data[12] = ____BAH_COMPILER_VAR_971;
____BAH_COMPILER_VAR_932->data[13] = ____BAH_COMPILER_VAR_973;
struct reflectElement ____BAH_COMPILER_VAR_974 = __reflect(____BAH_COMPILER_VAR_931, sizeof(struct variable), "variable*", "", 0, 0, 1, ____BAH_COMPILER_VAR_932, 0);

        struct reflectElement ____BAH_COMPILER_VAR_975 = ____BAH_COMPILER_VAR_974;
        struct reflectElement ____BAH_COMPILER_VAR_976 = __reflect(____BAH_COMPILER_VAR_930, sizeof(array(struct variable*)*), "[]variable*", "membs", 1, &____BAH_COMPILER_VAR_975, 0, 0, offsetof(struct debugStruct, membs));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_927 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_927->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_927->length = 2;
        ____BAH_COMPILER_VAR_927->data = memoryAlloc(____BAH_COMPILER_VAR_927->length * ____BAH_COMPILER_VAR_927->elemSize);
        ____BAH_COMPILER_VAR_927->data[0] = ____BAH_COMPILER_VAR_929;
____BAH_COMPILER_VAR_927->data[1] = ____BAH_COMPILER_VAR_976;
struct reflectElement ____BAH_COMPILER_VAR_977 = __reflect(____BAH_COMPILER_VAR_926, sizeof(struct debugStruct), "debugStruct*", "ds", 0, 0, 1, ____BAH_COMPILER_VAR_927, 0);
debugPrint("struct_declare",nameToken.line,____BAH_COMPILER_VAR_977);
}
};
void parseDefine(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
if (__builtin_expect((len(l)<3), 0)) {
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
struct func* ____BAH_COMPILER_VAR_978 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_978->name = "";
____BAH_COMPILER_VAR_978->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_978->args->length = 0;
            ____BAH_COMPILER_VAR_978->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_978->from = "";
____BAH_COMPILER_VAR_978->file = "";
____BAH_COMPILER_VAR_978->line = 1;
struct func* fn = ____BAH_COMPILER_VAR_978;
char * code = parseFnHeader("",l,&i,fn,elems);
array(struct func*)* fns = elems->fns;
fn->isBinding = true;

    unsigned int ____BAH_COMPILER_VAR_979 = len(fns);
    __Bah_realocate_arr(fns, ____BAH_COMPILER_VAR_979);
    fns->data[____BAH_COMPILER_VAR_979] = fn;
if ((doesOutput==true)) {
char** ____BAH_COMPILER_VAR_980 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_980[1] = ";\n";____BAH_COMPILER_VAR_980[0] = code;char * ____BAH_COMPILER_VAR_981 =__Bah_multiple_concat(____BAH_COMPILER_VAR_980, 2);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_981));
}
}
else {
char * tp = "";
++i;
for (; (i<len(l)); ++i) {
struct Tok t = l->data[i];
char** ____BAH_COMPILER_VAR_982 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_982[1] = t.cont;____BAH_COMPILER_VAR_982[0] = tp;char * ____BAH_COMPILER_VAR_983 =__Bah_multiple_concat(____BAH_COMPILER_VAR_982, 2);tp = ____BAH_COMPILER_VAR_983;
};
if (__builtin_expect((ft.type!=TOKEN_TYPE_VAR), 0)) {
throwErr(&ft,"Cannot use {TOKEN} as new type name.");
}
struct string cTypeNewType = getCType(tp,elems);
char * cTypeNewTypeStr = string__str(&cTypeNewType);
if ((doesOutput==true)) {
char** ____BAH_COMPILER_VAR_984 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_984[4] = ";\n";____BAH_COMPILER_VAR_984[3] = ft.cont;____BAH_COMPILER_VAR_984[2] = " ";____BAH_COMPILER_VAR_984[1] = cTypeNewTypeStr;____BAH_COMPILER_VAR_984[0] = "typedef ";char * ____BAH_COMPILER_VAR_985 =__Bah_multiple_concat(____BAH_COMPILER_VAR_984, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_985));
}
if ((debug==true)) {
struct debugType* ____BAH_COMPILER_VAR_986 = memoryAlloc(sizeof(struct debugType));
struct debugType* dt = ____BAH_COMPILER_VAR_986;
dt->name = ft.cont;
dt->refers = tp;
struct debugType* ____BAH_COMPILER_VAR_987 = dt;
char ** ____BAH_COMPILER_VAR_989 = (char **)((char*)(____BAH_COMPILER_VAR_987) + offsetof(struct debugType, name));
struct reflectElement ____BAH_COMPILER_VAR_990 = __reflect(____BAH_COMPILER_VAR_989, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct debugType, name));
char ** ____BAH_COMPILER_VAR_991 = (char **)((char*)(____BAH_COMPILER_VAR_987) + offsetof(struct debugType, refers));
struct reflectElement ____BAH_COMPILER_VAR_992 = __reflect(____BAH_COMPILER_VAR_991, sizeof(char *), "cpstring", "refers", 0, 0, 0, 0, offsetof(struct debugType, refers));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_988 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_988->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_988->length = 2;
        ____BAH_COMPILER_VAR_988->data = memoryAlloc(____BAH_COMPILER_VAR_988->length * ____BAH_COMPILER_VAR_988->elemSize);
        ____BAH_COMPILER_VAR_988->data[0] = ____BAH_COMPILER_VAR_990;
____BAH_COMPILER_VAR_988->data[1] = ____BAH_COMPILER_VAR_992;
struct reflectElement ____BAH_COMPILER_VAR_993 = __reflect(____BAH_COMPILER_VAR_987, sizeof(struct debugType), "debugType*", "dt", 0, 0, 1, ____BAH_COMPILER_VAR_988, 0);
debugPrint("type_declare",ft.line,____BAH_COMPILER_VAR_993);
}
array(char *)* tps = elems->types;

    unsigned int ____BAH_COMPILER_VAR_994 = len(tps);
    __Bah_realocate_arr(tps, ____BAH_COMPILER_VAR_994);
    tps->data[____BAH_COMPILER_VAR_994] = ft.cont;
}
};
void parseClib(__BAH_ARR_TYPE_Tok line){
array(char *)* clibs = compilerState.cLibs;
register long int i = 1;
while ((i<len(line))) {
struct Tok t = line->data[i];
if (__builtin_expect((t.type!=TOKEN_TYPE_STR), 0)) {
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

    unsigned int ____BAH_COMPILER_VAR_995 = len(clibs);
    __Bah_realocate_arr(clibs, ____BAH_COMPILER_VAR_995);
    clibs->data[____BAH_COMPILER_VAR_995] = ccstr;
++i;
};
};
void parseConst(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
l = parseCast(l,elems,true);
if (__builtin_expect((len(l)!=4), 0)) {
throwErr(&l->data[0],"Invalid usage of {TOKEN}, must be 'const <constName> = <constValue>'. ");
}
struct Tok vart = l->data[1];
struct Tok equt = l->data[2];
struct Tok valt = l->data[3];
if (__builtin_expect((vart.type!=TOKEN_TYPE_VAR), 0)) {
throwErr(&vart,"Cannot take {TOKEN} as const name.");
}
if (__builtin_expect((strcmp(equt.cont, "=") != 0), 0)) {
throwErr(&equt,"Expected '=' not {TOKEN}.");
}
if (__builtin_expect((valt.isValue==false), 0)) {
throwErr(&equt,"Must be a value, not {TOKEN}.");
}
if ((valt.type==TOKEN_TYPE_VAR)) {
struct func* fn = searchFunc(valt.cont,elems,true);
if ((fn!=null)) {
fn->used = true;
}
}
struct variable* ____BAH_COMPILER_VAR_996 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_996->name = "";
____BAH_COMPILER_VAR_996->type = "";
____BAH_COMPILER_VAR_996->constVal = "";
____BAH_COMPILER_VAR_996->from = "";
struct variable* v = ____BAH_COMPILER_VAR_996;
if (isGlobal()) {
v->isGlobal = true;
}
v->isConst = true;
v->constVal = valt.cont;
v->name = vart.cont;
v->type = getTypeFromToken(&valt,true,elems);
array(struct variable*)* vars = elems->vars;

    unsigned int ____BAH_COMPILER_VAR_997 = len(vars);
    __Bah_realocate_arr(vars, ____BAH_COMPILER_VAR_997);
    vars->data[____BAH_COMPILER_VAR_997] = v;
char** ____BAH_COMPILER_VAR_998 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_998[4] = "\n";____BAH_COMPILER_VAR_998[3] = valt.cont;____BAH_COMPILER_VAR_998[2] = " ";____BAH_COMPILER_VAR_998[1] = v->name;____BAH_COMPILER_VAR_998[0] = "#define ";char * ____BAH_COMPILER_VAR_999 =__Bah_multiple_concat(____BAH_COMPILER_VAR_998, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_999));
};
void parseReturn(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
if (__builtin_expect((len(l)>2), 0)) {
throwErr(&l->data[0],"Invalid usage of {TOKEN}, must be 'return <returnValue>'");
}
if (__builtin_expect((currentFn==null), 0)) {
throwErr(&l->data[0],"Cannot return a value outside of a function.");
}
char * rv = "";
char * tt = "";
struct variable* tmpV = null;
if ((len(l)==1)) {
if (__builtin_expect((strlen(currentFn->returns->type)!=0), 0)) {
char** ____BAH_COMPILER_VAR_1000 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1000[2] = ".";____BAH_COMPILER_VAR_1000[1] = currentFn->returns->type;____BAH_COMPILER_VAR_1000[0] = "Cannot return nothing as ";char * ____BAH_COMPILER_VAR_1001 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1000, 3);throwErr(&l->data[0],____BAH_COMPILER_VAR_1001);
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

                struct string ____BAH_COMPILER_VAR_1002 = string(compilerState.currentDir);
                if ((isUnsafe==false)&&(string__hasPrefix(&____BAH_COMPILER_VAR_1002,BAH_DIR)==false)&&(currentFn->returns->type[strlen(currentFn->returns->type)-1]!=33)) {
if ((tmpV->canBeNull==true)||(strcmp(rv, "null") == 0)) {
currentFn->returns->canBeNull = true;
char** ____BAH_COMPILER_VAR_1003 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1003[2] = "' that can be null as pointer.\n\tUse maybe values instead.";____BAH_COMPILER_VAR_1003[1] = tmpV->name;____BAH_COMPILER_VAR_1003[0] = "Returning '";char * ____BAH_COMPILER_VAR_1004 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1003, 3);throwNoticeLine(____BAH_COMPILER_VAR_1004,rvt.line);
}
}
}
}
else if (RCPavailable()&&(rvt.type==TOKEN_TYPE_FUNC)) {
rv = genCompilerVar();
struct string cType = getCType(tt,elems);
char** ____BAH_COMPILER_VAR_1005 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_1005[5] = ";\n";____BAH_COMPILER_VAR_1005[4] = rvt.cont;____BAH_COMPILER_VAR_1005[3] = "=";____BAH_COMPILER_VAR_1005[2] = rv;____BAH_COMPILER_VAR_1005[1] = " ";____BAH_COMPILER_VAR_1005[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_1006 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1005, 6);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1006));
}
if (__builtin_expect((compTypes(tt,currentFn->returns->type)==false), 0)) {
char** ____BAH_COMPILER_VAR_1007 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1007[4] = ".";____BAH_COMPILER_VAR_1007[3] = currentFn->returns->type;____BAH_COMPILER_VAR_1007[2] = ") as ";____BAH_COMPILER_VAR_1007[1] = tt;____BAH_COMPILER_VAR_1007[0] = "Cannot return {TOKEN} (";char * ____BAH_COMPILER_VAR_1008 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1007, 5);throwErr(&rvt,____BAH_COMPILER_VAR_1008);
}
}
if ((compilerState.isBranch==false)) {
currentFn->returned = true;
}
else {
currentFn->couldAlreadyReturn = true;
setNullStateBranchFlowEnd(elems);
}
if ((strlen(rv)>0)) {
char * rvar = rv;
if ((RCPavailable()==true)&&isRCPtype(currentFn->returns->type,elems)) {
rvar = genCompilerVar();
struct string cType = getCType(currentFn->returns->type,elems);
char** ____BAH_COMPILER_VAR_1009 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_1009[5] = ";\n";____BAH_COMPILER_VAR_1009[4] = rv;____BAH_COMPILER_VAR_1009[3] = " = ";____BAH_COMPILER_VAR_1009[2] = rvar;____BAH_COMPILER_VAR_1009[1] = " ";____BAH_COMPILER_VAR_1009[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_1010 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1009, 6);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1010));
if ((tmpV!=null)&&(tmpV->declScope!=elems)) {
OUTPUT = rope__add(OUTPUT, incrVar(tmpV,elems));
}
}
struct string stt = string(tt);
if (string__hasPrefix(&stt,"buffer:")) {
char** ____BAH_COMPILER_VAR_1011 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1011[2] = ")";____BAH_COMPILER_VAR_1011[1] = rvar;____BAH_COMPILER_VAR_1011[0] = "__STR(";char * ____BAH_COMPILER_VAR_1012 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1011, 3);rvar = ____BAH_COMPILER_VAR_1012;
}
else if (string__hasPrefix(&stt,"tuple:")) {
array(struct string)* parts = splitString(stt,":");
char * v = genCompilerVar();

                struct string ____BAH_COMPILER_VAR_1013 = getCType(tt,elems);
                char * ____BAH_COMPILER_VAR_1014 =string__str(&parts->data[2]);
                struct string ____BAH_COMPILER_VAR_1015 = getCType(____BAH_COMPILER_VAR_1014,elems);
                char * ____BAH_COMPILER_VAR_1016 =string__str(&parts->data[2]);
                struct string ____BAH_COMPILER_VAR_1017 = getCType(____BAH_COMPILER_VAR_1016,elems);
                char** ____BAH_COMPILER_VAR_1018 = alloca(17 * sizeof(char*));____BAH_COMPILER_VAR_1018[16] = ");";____BAH_COMPILER_VAR_1018[15] = string__str(&parts->data[1]);____BAH_COMPILER_VAR_1018[14] = ") * ";____BAH_COMPILER_VAR_1018[13] = string__str(&____BAH_COMPILER_VAR_1017);____BAH_COMPILER_VAR_1018[12] = ", sizeof(";____BAH_COMPILER_VAR_1018[11] = rv;____BAH_COMPILER_VAR_1018[10] = ", ";____BAH_COMPILER_VAR_1018[9] = v;____BAH_COMPILER_VAR_1018[8] = "));\n            memcpy(";____BAH_COMPILER_VAR_1018[7] = string__str(&____BAH_COMPILER_VAR_1015);____BAH_COMPILER_VAR_1018[6] = " * sizeof(";____BAH_COMPILER_VAR_1018[5] = string__str(&parts->data[1]);____BAH_COMPILER_VAR_1018[4] = " = memoryAlloc(";____BAH_COMPILER_VAR_1018[3] = v;____BAH_COMPILER_VAR_1018[2] = " ";____BAH_COMPILER_VAR_1018[1] = string__str(&____BAH_COMPILER_VAR_1013);____BAH_COMPILER_VAR_1018[0] = "";char * ____BAH_COMPILER_VAR_1019 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1018, 17);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1019));
rvar = v;
}
if (RCPavailable()) {
array(struct variable*)* excl = memoryAlloc(sizeof(array(struct variable*)));

excl->length = 0;
excl->elemSize = sizeof(struct variable*);
register long int j = 0;
for (; (j<len(currentFn->args)); ++j) {

    unsigned int ____BAH_COMPILER_VAR_1020 = j;
    __Bah_realocate_arr(excl, ____BAH_COMPILER_VAR_1020);
    excl->data[____BAH_COMPILER_VAR_1020] = currentFn->args->data[j];
};
if ((tmpV!=null)) {

    unsigned int ____BAH_COMPILER_VAR_1021 = len(excl);
    __Bah_realocate_arr(excl, ____BAH_COMPILER_VAR_1021);
    excl->data[____BAH_COMPILER_VAR_1021] = tmpV;
}
endRCPscope(elems,excl);
}
char** ____BAH_COMPILER_VAR_1022 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1022[2] = ";\n";____BAH_COMPILER_VAR_1022[1] = rvar;____BAH_COMPILER_VAR_1022[0] = "return ";char * ____BAH_COMPILER_VAR_1023 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1022, 3);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1023));
}
else {
if (RCPavailable()) {
array(struct variable*)* excl = memoryAlloc(sizeof(array(struct variable*)));

excl->length = 0;
excl->elemSize = sizeof(struct variable*);
register long int j = 0;
for (; (j<len(currentFn->args)); ++j) {

    unsigned int ____BAH_COMPILER_VAR_1024 = j;
    __Bah_realocate_arr(excl, ____BAH_COMPILER_VAR_1024);
    excl->data[____BAH_COMPILER_VAR_1024] = currentFn->args->data[j];
};
if ((tmpV!=null)) {

    unsigned int ____BAH_COMPILER_VAR_1025 = len(excl);
    __Bah_realocate_arr(excl, ____BAH_COMPILER_VAR_1025);
    excl->data[____BAH_COMPILER_VAR_1025] = tmpV;
}
endRCPscope(elems,excl);
}
OUTPUT = rope__add(OUTPUT, rope("return;\n"));
}
};
void parseIf(__BAH_ARR_TYPE_Tok l,char fromElse,struct Elems* elems){
prevIfExits = false;
struct Tok ft = l->data[0];
if (__builtin_expect((len(l)<4), 0)) {
throwErr(&ft,"Invalid usage of {TOKEN}, must be 'if <condition> {<code>}'");
}
struct Tok condt = l->data[1];
if ((strcmp(condt.bahType, "bool") != 0)) {
if (__builtin_expect((strcmp(condt.bahType, "int") != 0), 0)) {
throwErr(&condt,"Cannot use {TOKEN} as condition in if statement.");
}
}
struct Tok t = l->data[2];
if (__builtin_expect((strcmp(t.cont, "{") != 0), 0)) {
throwErr(&t,"Expected '{' not {TOKEN} after condtition in if statement.");
}
array(struct Tok)* tokens = memoryAlloc(sizeof(array(struct Tok)));

tokens->length = 0;
tokens->elemSize = sizeof(struct Tok);
long int max = len(l)-1;
register long int i = 3;
while ((i<max)) {
t = l->data[i];

    unsigned int ____BAH_COMPILER_VAR_1026 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_1026);
    tokens->data[____BAH_COMPILER_VAR_1026] = t;
++i;
};
char** ____BAH_COMPILER_VAR_1027 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1027[2] = ") {\n";____BAH_COMPILER_VAR_1027[1] = condt.cont;____BAH_COMPILER_VAR_1027[0] = "if (";char * ____BAH_COMPILER_VAR_1028 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1027, 3);struct rope* ifHeader = rope(____BAH_COMPILER_VAR_1028);
OUTPUT = rope__add(OUTPUT, ifHeader);
struct Elems* ifElems = dupElems(elems);
if ((fromElse==true)) {
i = 0;
for (; (i<len(prevIfChecks)); ++i) {
struct varCheck bc = prevIfChecks->data[i];
bc.checkNull = (bc.checkNull==false);

    unsigned int ____BAH_COMPILER_VAR_1029 = i;
    __Bah_realocate_arr(ifElems->branchChecks, ____BAH_COMPILER_VAR_1029);
    ifElems->branchChecks->data[____BAH_COMPILER_VAR_1029] = bc;
};
}
i = 0;
for (; (i<len(currChecks)); ++i) {

    unsigned int ____BAH_COMPILER_VAR_1030 = len(ifElems->branchChecks);
    __Bah_realocate_arr(ifElems->branchChecks, ____BAH_COMPILER_VAR_1030);
    ifElems->branchChecks->data[____BAH_COMPILER_VAR_1030] = currChecks->data[i];
};
prevIfChecks = ifElems->branchChecks;
char oldIB = compilerState.isBranch;
compilerState.isBranch = true;
beginRCPscopeLeaky(ifElems);
parseLines(tokens,ifElems);
if ((ifElems->currFlowEnd==true)) {
char** ____BAH_COMPILER_VAR_1031 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1031[2] = ", 0)) {\n";____BAH_COMPILER_VAR_1031[1] = condt.cont;____BAH_COMPILER_VAR_1031[0] = "if (__builtin_expect(";char * ____BAH_COMPILER_VAR_1032 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1031, 3);OUTPUT->totalLen = OUTPUT->totalLen+ropeSet(ifHeader,____BAH_COMPILER_VAR_1032);
}
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
if (__builtin_expect((prevLine!=LINE_TYPE_ELSE), 0)) {
throwErr(&l->data[0],"Can only use {TOKEN} after 'if' statement.");
}
}
if (__builtin_expect((len(l)<3), 0)) {
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

    unsigned int ____BAH_COMPILER_VAR_1033 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1033);
    memory->data[____BAH_COMPILER_VAR_1033] = l->data[i];
++i;
};
parseIf(memory,true,elems);
prevLine = LINE_TYPE_IF;
}
else {
if (__builtin_expect((strcmp(ft.cont, "{") != 0), 0)) {
throwErr(&ft,"Expected 'if' or '{' not {TOKEN}.");
}
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
long int max = len(l)-1;
register long int i = 2;
while ((i<max)) {

    unsigned int ____BAH_COMPILER_VAR_1034 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1034);
    memory->data[____BAH_COMPILER_VAR_1034] = l->data[i];
++i;
};
OUTPUT = rope__add(OUTPUT, rope("{\n"));
struct Elems* ifElems = dupElems(elems);
i = 0;
for (; (i<len(prevIfChecks)); ++i) {
struct varCheck bc = prevIfChecks->data[i];
bc.checkNull = (bc.checkNull==false);

    unsigned int ____BAH_COMPILER_VAR_1035 = i;
    __Bah_realocate_arr(ifElems->branchChecks, ____BAH_COMPILER_VAR_1035);
    ifElems->branchChecks->data[____BAH_COMPILER_VAR_1035] = bc;
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
if (__builtin_expect((len(l)<4), 0)) {
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
if (__builtin_expect((nbComas==1), 0)) {
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
if (__builtin_expect((nbComas!=1), 0)) {
struct Tok t = l->data[0];
throwErr(&t,"Invalid usage of {TOKEN}, can only partition line in 2 using 'for <condition>, <insctruction> {<code>}'.");
}
array(struct Tok)* inst = memoryAlloc(sizeof(array(struct Tok)));

inst->length = 0;
inst->elemSize = sizeof(struct Tok);
struct Tok condt = l->data[1];
if ((strcmp(condt.bahType, "bool") != 0)) {
if (__builtin_expect((strcmp(condt.bahType, "int") != 0), 0)) {
throwErr(&condt,"Cannot use {TOKEN} as condition in for statement.");
}
}
struct Tok st = l->data[2];
if (__builtin_expect((st.type!=TOKEN_TYPE_SYNTAX)||(strcmp(st.cont, ",") != 0), 0)) {
throwErr(&st,"Cannot use {TOKEN}, need ',' to split for loop instructions.");
}
i = 3;
for (; (i<len(l)); ++i) {
struct Tok t = l->data[i];
if ((t.type==TOKEN_TYPE_ENCL)&&(strcmp(t.cont, "{") == 0)) {
break;
}

    unsigned int ____BAH_COMPILER_VAR_1036 = len(inst);
    __Bah_realocate_arr(inst, ____BAH_COMPILER_VAR_1036);
    inst->data[____BAH_COMPILER_VAR_1036] = t;
};
struct rope* oldOut = OUTPUT;
OUTPUT = rope("");
parseLine(inst,elems);
char * ____BAH_COMPILER_VAR_1037 =rope__toStr(OUTPUT);struct string instC = string(____BAH_COMPILER_VAR_1037);
OUTPUT = oldOut;
string__trimRight(&instC,2);
struct Tok t = l->data[i];
if (__builtin_expect((strcmp(t.cont, "{") != 0), 0)) {
throwErr(&t,"Expected '{' not {TOKEN} after '<condition>,<instruction>' in for statement.");
}
long int max = len(l)-1;
i = i+1;
for (; (i<max); ++i) {
t = l->data[i];

    unsigned int ____BAH_COMPILER_VAR_1038 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_1038);
    tokens->data[____BAH_COMPILER_VAR_1038] = t;
};
char** ____BAH_COMPILER_VAR_1039 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1039[4] = ") {\n";____BAH_COMPILER_VAR_1039[3] = string__str(&instC);____BAH_COMPILER_VAR_1039[2] = "; ";____BAH_COMPILER_VAR_1039[1] = condt.cont;____BAH_COMPILER_VAR_1039[0] = "for (; ";char * ____BAH_COMPILER_VAR_1040 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1039, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1040));
}
else {
struct Tok condt = l->data[1];
if ((strcmp(condt.bahType, "bool") != 0)) {
if (__builtin_expect((strcmp(condt.bahType, "int") != 0), 0)) {
throwErr(&condt,"Cannot use {TOKEN} as condition in for statement.");
}
}
struct Tok t = l->data[2];
if (__builtin_expect((strcmp(t.cont, "{") != 0), 0)) {
throwErr(&t,"Expected '{' not {TOKEN} after condtition in for statement.");
}
long int max = len(l)-1;
i = 3;
for (; (i<max); ++i) {
t = l->data[i];

    unsigned int ____BAH_COMPILER_VAR_1041 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_1041);
    tokens->data[____BAH_COMPILER_VAR_1041] = t;
};
char** ____BAH_COMPILER_VAR_1042 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1042[2] = ") {\n";____BAH_COMPILER_VAR_1042[1] = condt.cont;____BAH_COMPILER_VAR_1042[0] = "while (";char * ____BAH_COMPILER_VAR_1043 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1042, 3);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1043));
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
if (__builtin_expect((compilerState.isFor==false), 0)) {
throwErr(&ft,"Cannot {TOKEN} outside of for statement.");
}
if (__builtin_expect((len(l)!=1), 0)) {
throwErr(&ft,"Nothing expected after {TOKEN}.");
}
endRCPscopeLeaky(elems,null,false);
endRCPscopeLeaky(compilerState.currForElems,null,false);
char** ____BAH_COMPILER_VAR_1044 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1044[1] = ";\n";____BAH_COMPILER_VAR_1044[0] = ft.cont;char * ____BAH_COMPILER_VAR_1045 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1044, 2);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1045));
};
void makeEvalFunc(struct func* fn,struct Elems* elems){
char * ____BAH_COMPILER_VAR_1047 =fn->name;
        char ____BAH_COMPILER_VAR_1046 = 0;
        for(int i=compilerState.evals->length-1; i!=-1;i--) {
            if (compilerState.evals->data[i] != 0 && strcmp(compilerState.evals->data[i], ____BAH_COMPILER_VAR_1047) == 0) {
                ____BAH_COMPILER_VAR_1046=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_1046) {
return;
}
char** ____BAH_COMPILER_VAR_1048 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1048[1] = fn->name;____BAH_COMPILER_VAR_1048[0] = "__Bah_eval_";char * ____BAH_COMPILER_VAR_1049 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1048, 2);struct func* ____BAH_COMPILER_VAR_1050 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_1050->name = "";
____BAH_COMPILER_VAR_1050->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_1050->args->length = 0;
            ____BAH_COMPILER_VAR_1050->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_1050->from = "";
____BAH_COMPILER_VAR_1050->file = "";
____BAH_COMPILER_VAR_1050->line = 1;
____BAH_COMPILER_VAR_1050->name = ____BAH_COMPILER_VAR_1049;
struct func* efn = ____BAH_COMPILER_VAR_1050;
struct variable* ____BAH_COMPILER_VAR_1051 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1051->name = "";
____BAH_COMPILER_VAR_1051->type = "";
____BAH_COMPILER_VAR_1051->constVal = "";
____BAH_COMPILER_VAR_1051->from = "";
____BAH_COMPILER_VAR_1051->type = "ptr";
efn->returns = ____BAH_COMPILER_VAR_1051;
struct variable* ____BAH_COMPILER_VAR_1052 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1052->name = "";
____BAH_COMPILER_VAR_1052->type = "";
____BAH_COMPILER_VAR_1052->constVal = "";
____BAH_COMPILER_VAR_1052->from = "";
____BAH_COMPILER_VAR_1052->name = "fnArgs";
____BAH_COMPILER_VAR_1052->type = "[]ptr";
efn->args = memoryAlloc(sizeof(array(struct variable*)));

efn->args->length = 1;
efn->args->elemSize = sizeof(struct variable*);
efn->args->data = memoryAlloc(sizeof(struct variable*) * 50);
                    efn->args->realLength = 50;
efn->args->data[0] = ____BAH_COMPILER_VAR_1052;
char * fnBinding = "";
char** ____BAH_COMPILER_VAR_1053 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1053[1] = "(";____BAH_COMPILER_VAR_1053[0] = fn->name;char * ____BAH_COMPILER_VAR_1054 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1053, 2);char * fnCall = ____BAH_COMPILER_VAR_1054;
register long int i = 0;
for (; (i<len(fn->args)); ++i) {
struct variable* a = fn->args->data[i];
char * v = genCompilerVar();
struct string cType = getCType(a->type,elems);
if ((isRCPpointerType(a->type)==false)) {
string__append(&cType,"*");
}
char** ____BAH_COMPILER_VAR_1055 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_1055[5] = "];";____BAH_COMPILER_VAR_1055[4] = intToStr(i);____BAH_COMPILER_VAR_1055[3] = " = fnArgs->data[";____BAH_COMPILER_VAR_1055[2] = v;____BAH_COMPILER_VAR_1055[1] = " ";____BAH_COMPILER_VAR_1055[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_1056 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1055, 6);char** ____BAH_COMPILER_VAR_1057 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1057[1] = ____BAH_COMPILER_VAR_1056;____BAH_COMPILER_VAR_1057[0] = fnBinding;char * ____BAH_COMPILER_VAR_1058 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1057, 2);fnBinding = ____BAH_COMPILER_VAR_1058;
if ((i!=0)) {
char** ____BAH_COMPILER_VAR_1059 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1059[1] = ", ";____BAH_COMPILER_VAR_1059[0] = fnCall;char * ____BAH_COMPILER_VAR_1060 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1059, 2);fnCall = ____BAH_COMPILER_VAR_1060;
}
if (isRCPpointerType(a->type)) {
char** ____BAH_COMPILER_VAR_1061 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1061[1] = v;____BAH_COMPILER_VAR_1061[0] = fnCall;char * ____BAH_COMPILER_VAR_1062 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1061, 2);fnCall = ____BAH_COMPILER_VAR_1062;
}
else {
char** ____BAH_COMPILER_VAR_1063 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1063[1] = v;____BAH_COMPILER_VAR_1063[0] = "*";char * ____BAH_COMPILER_VAR_1064 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1063, 2);char** ____BAH_COMPILER_VAR_1065 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1065[1] = ____BAH_COMPILER_VAR_1064;____BAH_COMPILER_VAR_1065[0] = fnCall;char * ____BAH_COMPILER_VAR_1066 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1065, 2);fnCall = ____BAH_COMPILER_VAR_1066;
}
};
char * setReturnValue = "void* r = 0;";
if (isRCPpointerType(fn->returns->type)) {
setReturnValue = "void* r = ";
}
else {
struct string cType = getCType(fn->returns->type,elems);
if ((strcmp(string__str(&cType), "void") != 0)) {
char** ____BAH_COMPILER_VAR_1067 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1067[3] = "));*r = ";____BAH_COMPILER_VAR_1067[2] = string__str(&cType);____BAH_COMPILER_VAR_1067[1] = "* r = memoryAlloc(sizeof(";____BAH_COMPILER_VAR_1067[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_1068 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1067, 4);setReturnValue = ____BAH_COMPILER_VAR_1068;
}
}
char** ____BAH_COMPILER_VAR_1069 = alloca(12 * sizeof(char*));____BAH_COMPILER_VAR_1069[11] = ");\n        return (void*)r;\n    };";____BAH_COMPILER_VAR_1069[10] = fnCall;____BAH_COMPILER_VAR_1069[9] = setReturnValue;____BAH_COMPILER_VAR_1069[8] = "\n        ";____BAH_COMPILER_VAR_1069[7] = fnBinding;____BAH_COMPILER_VAR_1069[6] = "() with the wrong number of arguments.\", \"BAH_COMPILER_INTERNAL\");\n        }\n        ";____BAH_COMPILER_VAR_1069[5] = fn->name;____BAH_COMPILER_VAR_1069[4] = ") {\n            __BAH_panic((char*)\"eval: calling function ";____BAH_COMPILER_VAR_1069[3] = intToStr(len(fn->args));____BAH_COMPILER_VAR_1069[2] = "(array(void*)* fnArgs) {\n        if (fnArgs->length != ";____BAH_COMPILER_VAR_1069[1] = efn->name;____BAH_COMPILER_VAR_1069[0] = "void* __attribute__((optimize(\"O0\"))) ";char * ____BAH_COMPILER_VAR_1070 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1069, 12);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1070));

    unsigned int ____BAH_COMPILER_VAR_1071 = len(compilerState.evals);
    __Bah_realocate_arr(compilerState.evals, ____BAH_COMPILER_VAR_1071);
    compilerState.evals->data[____BAH_COMPILER_VAR_1071] = fn->name;

    unsigned int ____BAH_COMPILER_VAR_1072 = len(elems->fns);
    __Bah_realocate_arr(elems->fns, ____BAH_COMPILER_VAR_1072);
    elems->fns->data[____BAH_COMPILER_VAR_1072] = efn;
};
void parsePreKeyword(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
struct Tok ft = l->data[0];
if ((strcmp(ft.cont, "#warning") == 0)) {
if (__builtin_expect((len(l)!=2), 0)) {
throwErr(&ft,"Invalid usage of {TOKEN} '#warning \"message\"'.");
}
struct Tok mt = l->data[1];
if (__builtin_expect((mt.type!=TOKEN_TYPE_STR), 0)) {
throwErr(&mt,"Cannot use {TOKEN} as a string.");
}
struct string msg = string(mt.cont);
string__trimLeft(&msg,1);
string__trimRight(&msg,1);
char * ____BAH_COMPILER_VAR_1073 =string__str(&msg);throwWarning(____BAH_COMPILER_VAR_1073);
return;
}
if ((strcmp(ft.cont, "#eval") == 0)) {
char * ____BAH_COMPILER_VAR_1075 ="eval.bah";
        char ____BAH_COMPILER_VAR_1074 = 0;
        for(int i=compilerState.includes->length-1; i!=-1;i--) {
            if (compilerState.includes->data[i] != 0 && strcmp(compilerState.includes->data[i], ____BAH_COMPILER_VAR_1075) == 0) {
                ____BAH_COMPILER_VAR_1074=1;
                break;
            };
        }
        if ((____BAH_COMPILER_VAR_1074==false)) {
if (__builtin_expect((includeFile("eval.bah",elems)==false), 0)) {
char** ____BAH_COMPILER_VAR_1076 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1076[2] = ").";____BAH_COMPILER_VAR_1076[1] = BAH_DIR;____BAH_COMPILER_VAR_1076[0] = "Could not find file 'eval.bah'. Check your bah directory (";char * ____BAH_COMPILER_VAR_1077 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1076, 3);throwErr(&l->data[0],____BAH_COMPILER_VAR_1077);
}
}
if (__builtin_expect((len(l)!=2)||(isGlobal()==false), 0)) {
throwErr(&l->data[0],"Invalid usage of {TOKEN} <#eval fnName>.");
}
struct Tok fnT = l->data[1];
struct func* fn = searchFunc(fnT.cont,elems,false);
if (__builtin_expect((fn==null), 0)) {
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
if (__builtin_expect((len(l)<3), 0)) {
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
if ((isSubObject==false)+(isObject==false)) {
return;
}
}
else if ((strcmp(ft.cont, "#included") == 0)) {
if ((isSubObject==true)+(isObject==true)) {
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
if (__builtin_expect((strcmp(st.cont, "{") != 0)||(strcmp(lt.cont, "}") != 0), 0)) {
throwErr(&st,"Expected code block after keyword {TOKEN}.");
}
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
register long int i = 2;
while ((i<len(l)-1)) {

    unsigned int ____BAH_COMPILER_VAR_1078 = i-2;
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_1078);
    nl->data[____BAH_COMPILER_VAR_1078] = l->data[i];
i = i+1;
};
parseLines(nl,elems);
};
void parseAsync(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
if (__builtin_expect((len(l)!=2), 0)) {
struct Tok ft = l->data[0];
throwErr(&ft,"Cannot use keyword {TOKEN} on a function call 'async <function call>'.");
}
struct Tok fnT = l->data[1];
if (__builtin_expect((fnT.isFunc==false), 0)) {
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

    unsigned int ____BAH_COMPILER_VAR_1079 = len(compilerState.cLibs);
    __Bah_realocate_arr(compilerState.cLibs, ____BAH_COMPILER_VAR_1079);
    compilerState.cLibs->data[____BAH_COMPILER_VAR_1079] = "lpthread";
}
struct string sFnT = string(fnT.cont);
array(struct string)* fnNameParts = splitString(sFnT,"(");
struct string fnName = fnNameParts->data[0];
struct func* fn = searchFuncByToken(&fnT,elems);
if (__builtin_expect((fn==null), 0)) {
char** ____BAH_COMPILER_VAR_1080 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1080[2] = "', arround {TOKEN}.";____BAH_COMPILER_VAR_1080[1] = string__str(&fnName);____BAH_COMPILER_VAR_1080[0] = "Internal compiler error.\n Error parsing async call for function '";char * ____BAH_COMPILER_VAR_1081 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1080, 3);throwErr(&fnT,____BAH_COMPILER_VAR_1081);
}
fnName = string(fn->name);
char * sMembs = "";
char * unSerMembs = "";
i = 0;
while ((i<len(fn->args))) {
struct variable* a = fn->args->data[i];
struct string cType = getCType(a->type,elems);
char** ____BAH_COMPILER_VAR_1082 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1082[4] = ";\n";____BAH_COMPILER_VAR_1082[3] = a->name;____BAH_COMPILER_VAR_1082[2] = " ";____BAH_COMPILER_VAR_1082[1] = string__str(&cType);____BAH_COMPILER_VAR_1082[0] = sMembs;char * ____BAH_COMPILER_VAR_1083 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1082, 5);sMembs = ____BAH_COMPILER_VAR_1083;
char** ____BAH_COMPILER_VAR_1084 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1084[2] = a->name;____BAH_COMPILER_VAR_1084[1] = "args->";____BAH_COMPILER_VAR_1084[0] = unSerMembs;char * ____BAH_COMPILER_VAR_1085 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1084, 3);unSerMembs = ____BAH_COMPILER_VAR_1085;
i = i+1;
if ((i<len(fn->args))) {
char** ____BAH_COMPILER_VAR_1086 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1086[1] = ", ";____BAH_COMPILER_VAR_1086[0] = unSerMembs;char * ____BAH_COMPILER_VAR_1087 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1086, 2);unSerMembs = ____BAH_COMPILER_VAR_1087;
}
};
char** ____BAH_COMPILER_VAR_1088 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1088[2] = "}";____BAH_COMPILER_VAR_1088[1] = sMembs;____BAH_COMPILER_VAR_1088[0] = "struct {\n";char * ____BAH_COMPILER_VAR_1089 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1088, 3);char * tmpArgsStruct = ____BAH_COMPILER_VAR_1089;
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
char** ____BAH_COMPILER_VAR_1090 = alloca(21 * sizeof(char*));____BAH_COMPILER_VAR_1090[20] = ");\n    }; \n    \n    ";____BAH_COMPILER_VAR_1090[19] = tmpArgs;____BAH_COMPILER_VAR_1090[18] = ", &";____BAH_COMPILER_VAR_1090[17] = fnWrapper;____BAH_COMPILER_VAR_1090[16] = "(&id, 0, ";____BAH_COMPILER_VAR_1090[15] = tCreate;____BAH_COMPILER_VAR_1090[14] = "};\n        pthread_t id;\n        ";____BAH_COMPILER_VAR_1090[13] = string__str(&sFnT);____BAH_COMPILER_VAR_1090[12] = " = {";____BAH_COMPILER_VAR_1090[11] = tmpArgs;____BAH_COMPILER_VAR_1090[10] = " ";____BAH_COMPILER_VAR_1090[9] = tmpArgsStruct;____BAH_COMPILER_VAR_1090[8] = ");\n    };\n    {\n        ";____BAH_COMPILER_VAR_1090[7] = unSerMembs;____BAH_COMPILER_VAR_1090[6] = "(";____BAH_COMPILER_VAR_1090[5] = string__str(&fnName);____BAH_COMPILER_VAR_1090[4] = "* args) {\n        ";____BAH_COMPILER_VAR_1090[3] = tmpArgsStruct;____BAH_COMPILER_VAR_1090[2] = "(";____BAH_COMPILER_VAR_1090[1] = fnWrapper;____BAH_COMPILER_VAR_1090[0] = "\n    void ";char * ____BAH_COMPILER_VAR_1091 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1090, 21);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1091));
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

    unsigned int ____BAH_COMPILER_VAR_1092 = len(compilerState.RCPvars);
    __Bah_realocate_arr(compilerState.RCPvars, ____BAH_COMPILER_VAR_1092);
    compilerState.RCPvars->data[____BAH_COMPILER_VAR_1092] = v;
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
if (__builtin_expect((nt.type!=TOKEN_TYPE_VAR), 0)) {
throwErr(&nt,"Cannot use {TOKEN} as channel.");
}
char * ____BAH_COMPILER_VAR_1093 =getTypeFromToken(&nt,true,elems);struct string ntt = string(____BAH_COMPILER_VAR_1093);
if (__builtin_expect((string__hasPrefix(&ntt,"chan:")==0), 0)) {
char** ____BAH_COMPILER_VAR_1094 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1094[2] = ") as channel.";____BAH_COMPILER_VAR_1094[1] = string__str(&ntt);____BAH_COMPILER_VAR_1094[0] = "Cannot use var {TOKEN} (";char * ____BAH_COMPILER_VAR_1095 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1094, 3);throwErr(&nt,____BAH_COMPILER_VAR_1095);
}
string__trimLeft(&ntt,5);
if (__builtin_expect(isGlobal(), 0)) {
throwErr(&t,"Cannot receive ({TOKEN}) from a channel outside of a function.");
}
char * tmpV = "";
char * ____BAH_COMPILER_VAR_1096 =string__str(&ntt);if (isRCPpointerType(____BAH_COMPILER_VAR_1096)) {
char * ____BAH_COMPILER_VAR_1097 =string__str(&ntt);struct string ct = getCType(____BAH_COMPILER_VAR_1097,elems);
char** ____BAH_COMPILER_VAR_1098 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_1098[6] = ")";____BAH_COMPILER_VAR_1098[5] = nt.cont;____BAH_COMPILER_VAR_1098[4] = "->receive(";____BAH_COMPILER_VAR_1098[3] = nt.cont;____BAH_COMPILER_VAR_1098[2] = ")";____BAH_COMPILER_VAR_1098[1] = string__str(&ct);____BAH_COMPILER_VAR_1098[0] = "(";char * ____BAH_COMPILER_VAR_1099 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1098, 7);t.cont = ____BAH_COMPILER_VAR_1099;
}
else {
char * ____BAH_COMPILER_VAR_1100 =string__str(&ntt);struct string ct = getCType(____BAH_COMPILER_VAR_1100,elems);
if (RCPavailable()) {
char** ____BAH_COMPILER_VAR_1101 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1101[1] = "*";____BAH_COMPILER_VAR_1101[0] = string__str(&ntt);char * ____BAH_COMPILER_VAR_1102 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1101, 2);char** ____BAH_COMPILER_VAR_1103 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_1103[6] = ")";____BAH_COMPILER_VAR_1103[5] = nt.cont;____BAH_COMPILER_VAR_1103[4] = "->receive(";____BAH_COMPILER_VAR_1103[3] = nt.cont;____BAH_COMPILER_VAR_1103[2] = "*)";____BAH_COMPILER_VAR_1103[1] = string__str(&ct);____BAH_COMPILER_VAR_1103[0] = "(";char * ____BAH_COMPILER_VAR_1104 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1103, 7);tmpV = registerRCPvar(____BAH_COMPILER_VAR_1102,____BAH_COMPILER_VAR_1104,elems);
char** ____BAH_COMPILER_VAR_1105 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1105[1] = tmpV;____BAH_COMPILER_VAR_1105[0] = "*";char * ____BAH_COMPILER_VAR_1106 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1105, 2);t.cont = ____BAH_COMPILER_VAR_1106;
}
else {
char** ____BAH_COMPILER_VAR_1107 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_1107[6] = ")";____BAH_COMPILER_VAR_1107[5] = nt.cont;____BAH_COMPILER_VAR_1107[4] = "->receive(";____BAH_COMPILER_VAR_1107[3] = nt.cont;____BAH_COMPILER_VAR_1107[2] = "*)";____BAH_COMPILER_VAR_1107[1] = string__str(&ct);____BAH_COMPILER_VAR_1107[0] = "*(";char * ____BAH_COMPILER_VAR_1108 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1107, 7);t.cont = ____BAH_COMPILER_VAR_1108;
}
}
t.type = TOKEN_TYPE_FUNC;
t.isFunc = true;
if (RCPavailable()) {
char * ____BAH_COMPILER_VAR_1109 =string__str(&ntt);if (isRCPpointerType(____BAH_COMPILER_VAR_1109)) {
char * ____BAH_COMPILER_VAR_1110 =string__str(&ntt);tmpV = registerRCPvar(____BAH_COMPILER_VAR_1110,t.cont,elems);
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
if (__builtin_expect((i==0), 0)) {
throwErr(&t,"Cannot une {TOKEN} on nothing.");
}
if (__builtin_expect((i+1>=len(l)), 0)) {
throwErr(&t,"Cannot send ({TOKEN}) to nothing.");
}
struct Tok pt = l->data[i+1];
struct Tok nt = l->data[i-1];
char * ntt = getTypeFromToken(&nt,true,elems);
if (__builtin_expect((pt.type!=TOKEN_TYPE_VAR), 0)) {
throwErr(&pt,"Cannot use {TOKEN} as channel.");
}
char * ____BAH_COMPILER_VAR_1111 =getTypeFromToken(&pt,true,elems);struct string ptt = string(____BAH_COMPILER_VAR_1111);
if (__builtin_expect((string__hasPrefix(&ptt,"chan:")==0), 0)) {
char** ____BAH_COMPILER_VAR_1112 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1112[2] = ") as channel.";____BAH_COMPILER_VAR_1112[1] = ntt;____BAH_COMPILER_VAR_1112[0] = "Cannot use var {TOKEN} (";char * ____BAH_COMPILER_VAR_1113 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1112, 3);throwErr(&pt,____BAH_COMPILER_VAR_1113);
}
string__trimLeft(&ptt,5);
if (__builtin_expect(isGlobal(), 0)) {
throwErr(&t,"Cannot send ({TOKEN}) to a channel outside of a function.");
}
char * ____BAH_COMPILER_VAR_1114 =string__str(&ptt);if (__builtin_expect((compTypes(____BAH_COMPILER_VAR_1114,ntt)==false), 0)) {
char** ____BAH_COMPILER_VAR_1115 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1115[4] = ".";____BAH_COMPILER_VAR_1115[3] = string__str(&ptt);____BAH_COMPILER_VAR_1115[2] = ") to channel of type ";____BAH_COMPILER_VAR_1115[1] = ntt;____BAH_COMPILER_VAR_1115[0] = "Cannot send {TOKEN} (";char * ____BAH_COMPILER_VAR_1116 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1115, 5);throwErr(&nt,____BAH_COMPILER_VAR_1116);
}
++i;
char * ____BAH_COMPILER_VAR_1117 =string__str(&ptt);if (isRCPpointerType(____BAH_COMPILER_VAR_1117)) {
char** ____BAH_COMPILER_VAR_1118 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_1118[5] = ");\n";____BAH_COMPILER_VAR_1118[4] = nt.cont;____BAH_COMPILER_VAR_1118[3] = ", ";____BAH_COMPILER_VAR_1118[2] = pt.cont;____BAH_COMPILER_VAR_1118[1] = "->send(";____BAH_COMPILER_VAR_1118[0] = pt.cont;char * ____BAH_COMPILER_VAR_1119 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1118, 6);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1119));
}
else {
struct string ct = getCType(ntt,elems);
char * tmpV = genCompilerVar();
char** ____BAH_COMPILER_VAR_1120 = alloca(15 * sizeof(char*));____BAH_COMPILER_VAR_1120[14] = "));\n";____BAH_COMPILER_VAR_1120[13] = tmpV;____BAH_COMPILER_VAR_1120[12] = ", sizeof(";____BAH_COMPILER_VAR_1120[11] = tmpV;____BAH_COMPILER_VAR_1120[10] = ", &";____BAH_COMPILER_VAR_1120[9] = pt.cont;____BAH_COMPILER_VAR_1120[8] = "->sendAny(";____BAH_COMPILER_VAR_1120[7] = pt.cont;____BAH_COMPILER_VAR_1120[6] = ";\n                    ";____BAH_COMPILER_VAR_1120[5] = nt.cont;____BAH_COMPILER_VAR_1120[4] = " = ";____BAH_COMPILER_VAR_1120[3] = tmpV;____BAH_COMPILER_VAR_1120[2] = " ";____BAH_COMPILER_VAR_1120[1] = string__str(&ct);____BAH_COMPILER_VAR_1120[0] = "\n                    ";char * ____BAH_COMPILER_VAR_1121 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1120, 15);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1121));
}
nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
return nl;
}
}

    unsigned int ____BAH_COMPILER_VAR_1122 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_1122);
    nl->data[____BAH_COMPILER_VAR_1122] = t;
};
return nl;
};
long int valueFunc(struct func* fn,struct variable* parent,__BAH_ARR_TYPE_Tok l,long int i,lineType ltp,struct Elems* elems){
long int tokPos = i;
struct genericFunc* generic= null;
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
register long int j = 0;
for (; (j<len(generics)); ++j) {
if ((strcmp(generics->data[j]->baseFn->name, pt.cont) == 0)) {
generic = generics->data[j];
genericFunc__setCurrGeneric(generics->data[j],&pt);
fn = genericFunc__dupBaseFn(generics->data[j]);
break;
}
};
if (__builtin_expect((j==len(generics)), 0)) {
throwErr(&pt,"Unknown func {TOKEN}.");
}
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
char** ____BAH_COMPILER_VAR_1123 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1123[1] = t.ogCont;____BAH_COMPILER_VAR_1123[0] = fnt.ogCont;char * ____BAH_COMPILER_VAR_1124 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1123, 2);fnt.ogCont = ____BAH_COMPILER_VAR_1124;
if ((strcmp(t.cont, "(") == 0)||(strcmp(t.cont, "{") == 0)||(strcmp(t.cont, "[") == 0)) {
++nbEncls;
}
else if ((strcmp(t.cont, ")") == 0)||(strcmp(t.cont, "}") == 0)||(strcmp(t.cont, "]") == 0)) {
--nbEncls;
if ((nbEncls==0)) {
break;
}
}

    unsigned int ____BAH_COMPILER_VAR_1125 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1125);
    memory->data[____BAH_COMPILER_VAR_1125] = t;
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
char** ____BAH_COMPILER_VAR_1126 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1126[1] = t.cont;____BAH_COMPILER_VAR_1126[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1127 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1126, 2);fnt.cont = ____BAH_COMPILER_VAR_1127;
};
char** ____BAH_COMPILER_VAR_1128 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1128[1] = ")";____BAH_COMPILER_VAR_1128[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1129 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1128, 2);fnt.cont = ____BAH_COMPILER_VAR_1129;

    unsigned int ____BAH_COMPILER_VAR_1130 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1130);
    l->data[____BAH_COMPILER_VAR_1130] = fnt;
return tokPos;
}
if ((strcmp(fn->name, "exit") == 0)||(strcmp(fn->name, "panic") == 0)||(fn->exits==true)) {
if ((compilerState.isBranch==true)) {
elems->currFlowEnd = true;
}
setNullStateBranchFlowEnd(elems);
}
char** ____BAH_COMPILER_VAR_1131 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1131[1] = "(";____BAH_COMPILER_VAR_1131[0] = fn->name;char * ____BAH_COMPILER_VAR_1132 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1131, 2);fnt.cont = ____BAH_COMPILER_VAR_1132;
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
char** ____BAH_COMPILER_VAR_1133 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1133[1] = "(";____BAH_COMPILER_VAR_1133[0] = fn->name;char * ____BAH_COMPILER_VAR_1134 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1133, 2);fnt.ogCont = ____BAH_COMPILER_VAR_1134;
for (; (i<len(l)); ++i) {
struct Tok t = l->data[i];
char** ____BAH_COMPILER_VAR_1135 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1135[1] = t.ogCont;____BAH_COMPILER_VAR_1135[0] = fnt.ogCont;char * ____BAH_COMPILER_VAR_1136 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1135, 2);fnt.ogCont = ____BAH_COMPILER_VAR_1136;
if ((strcmp(t.cont, "(") == 0)||(strcmp(t.cont, "{") == 0)||(strcmp(t.cont, "[") == 0)) {
++nbEncls;
}
else if ((strcmp(t.cont, ")") == 0)||(strcmp(t.cont, "}") == 0)||(strcmp(t.cont, "]") == 0)) {
--nbEncls;
if ((nbEncls==0)) {
break;
}
}

    unsigned int ____BAH_COMPILER_VAR_1137 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1137);
    memory->data[____BAH_COMPILER_VAR_1137] = t;
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
char** ____BAH_COMPILER_VAR_1138 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1138[1] = t.cont;____BAH_COMPILER_VAR_1138[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1139 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1138, 2);fnt.cont = ____BAH_COMPILER_VAR_1139;
};

    unsigned int ____BAH_COMPILER_VAR_1140 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1140);
    l->data[____BAH_COMPILER_VAR_1140] = fnt;
return tokPos;
}
char** ____BAH_COMPILER_VAR_1141 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1141[4] = "\"";____BAH_COMPILER_VAR_1141[3] = intToStr(fnt.line);____BAH_COMPILER_VAR_1141[2] = ":";____BAH_COMPILER_VAR_1141[1] = compilerState.currentFile;____BAH_COMPILER_VAR_1141[0] = "\"";char * ____BAH_COMPILER_VAR_1142 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1141, 5);char * currLine = ____BAH_COMPILER_VAR_1142;
if ((strcmp(fn->name, "panic") == 0)) {
struct Tok ____BAH_COMPILER_VAR_1143 = {};
____BAH_COMPILER_VAR_1143.cont = "";
____BAH_COMPILER_VAR_1143.ogCont = "";
____BAH_COMPILER_VAR_1143.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1143.line = 1;
____BAH_COMPILER_VAR_1143.begLine = 1;
____BAH_COMPILER_VAR_1143.bahType = "";
____BAH_COMPILER_VAR_1143.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_1143.cont = ",";
____BAH_COMPILER_VAR_1143.line = fnt.line;

    unsigned int ____BAH_COMPILER_VAR_1144 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1144);
    memory->data[____BAH_COMPILER_VAR_1144] = ____BAH_COMPILER_VAR_1143;
struct Tok ____BAH_COMPILER_VAR_1145 = {};
____BAH_COMPILER_VAR_1145.cont = "";
____BAH_COMPILER_VAR_1145.ogCont = "";
____BAH_COMPILER_VAR_1145.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1145.line = 1;
____BAH_COMPILER_VAR_1145.begLine = 1;
____BAH_COMPILER_VAR_1145.bahType = "";
____BAH_COMPILER_VAR_1145.type = TOKEN_TYPE_STR;
____BAH_COMPILER_VAR_1145.cont = currLine;
____BAH_COMPILER_VAR_1145.line = fnt.line;

    unsigned int ____BAH_COMPILER_VAR_1146 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1146);
    memory->data[____BAH_COMPILER_VAR_1146] = ____BAH_COMPILER_VAR_1145;
fn = searchFunc("__BAH_panic",elems,true);
char** ____BAH_COMPILER_VAR_1147 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1147[1] = "(";____BAH_COMPILER_VAR_1147[0] = fn->name;char * ____BAH_COMPILER_VAR_1148 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1147, 2);fnt.cont = ____BAH_COMPILER_VAR_1148;
}
else if ((strcmp(fn->name, "__dumpSymbols") == 0)) {
array(struct variable*)* symbols = memoryAlloc(sizeof(array(struct variable*)));

symbols->length = 0;
symbols->elemSize = sizeof(struct variable*);
register long int j = 0;
for (; (j<len(elems->vars)); ++j) {
struct variable* v = elems->vars->data[j];
if ((v->isConst==false)) {

    unsigned int ____BAH_COMPILER_VAR_1149 = len(symbols);
    __Bah_realocate_arr(symbols, ____BAH_COMPILER_VAR_1149);
    symbols->data[____BAH_COMPILER_VAR_1149] = v;
}
};
struct variable* ____BAH_COMPILER_VAR_1150 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1150->name = "";
____BAH_COMPILER_VAR_1150->type = "";
____BAH_COMPILER_VAR_1150->constVal = "";
____BAH_COMPILER_VAR_1150->from = "";
____BAH_COMPILER_VAR_1150->name = genCompilerVar();
____BAH_COMPILER_VAR_1150->type = "[]reflectElement";
____BAH_COMPILER_VAR_1150->isArray = true;
struct variable* tmpV = ____BAH_COMPILER_VAR_1150;
char * decls = "";
j = 0;
for (; (j<len(symbols)); ++j) {
struct variable* v = symbols->data[j];
char * vname = v->name;
if ((strCount(v->type,"*")==0)) {
char** ____BAH_COMPILER_VAR_1151 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1151[1] = v->name;____BAH_COMPILER_VAR_1151[0] = "&";char * ____BAH_COMPILER_VAR_1152 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1151, 2);vname = ____BAH_COMPILER_VAR_1152;
}
struct Tok ____BAH_COMPILER_VAR_1153 = {};
____BAH_COMPILER_VAR_1153.cont = "";
____BAH_COMPILER_VAR_1153.ogCont = "";
____BAH_COMPILER_VAR_1153.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1153.line = 1;
____BAH_COMPILER_VAR_1153.begLine = 1;
____BAH_COMPILER_VAR_1153.bahType = "";
____BAH_COMPILER_VAR_1153.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_1153.cont = vname;
____BAH_COMPILER_VAR_1153.bahType = v->type;
____BAH_COMPILER_VAR_1153.isValue = true;
struct Tok tmpT = ____BAH_COMPILER_VAR_1153;
tmpT = parseReflect(tmpT,v->type,elems,true,v->name,"0");
char** ____BAH_COMPILER_VAR_1154 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_1154[5] = ";\n";____BAH_COMPILER_VAR_1154[4] = tmpT.cont;____BAH_COMPILER_VAR_1154[3] = "] = ";____BAH_COMPILER_VAR_1154[2] = intToStr(j);____BAH_COMPILER_VAR_1154[1] = "->data[";____BAH_COMPILER_VAR_1154[0] = tmpV->name;char * ____BAH_COMPILER_VAR_1155 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1154, 6);char** ____BAH_COMPILER_VAR_1156 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1156[1] = ____BAH_COMPILER_VAR_1155;____BAH_COMPILER_VAR_1156[0] = decls;char * ____BAH_COMPILER_VAR_1157 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1156, 2);decls = ____BAH_COMPILER_VAR_1157;
};

    unsigned int ____BAH_COMPILER_VAR_1158 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_1158);
    elems->vars->data[____BAH_COMPILER_VAR_1158] = tmpV;
char** ____BAH_COMPILER_VAR_1159 = alloca(15 * sizeof(char*));____BAH_COMPILER_VAR_1159[14] = "\n        ";____BAH_COMPILER_VAR_1159[13] = decls;____BAH_COMPILER_VAR_1159[12] = "->elemSize = sizeof(struct reflectElement);\n        ";____BAH_COMPILER_VAR_1159[11] = tmpV->name;____BAH_COMPILER_VAR_1159[10] = ";\n        ";____BAH_COMPILER_VAR_1159[9] = intToStr(len(symbols));____BAH_COMPILER_VAR_1159[8] = "->length = ";____BAH_COMPILER_VAR_1159[7] = tmpV->name;____BAH_COMPILER_VAR_1159[6] = ");\n        ";____BAH_COMPILER_VAR_1159[5] = intToStr(len(symbols));____BAH_COMPILER_VAR_1159[4] = "->data = memoryAlloc(sizeof(struct reflectElement) * ";____BAH_COMPILER_VAR_1159[3] = tmpV->name;____BAH_COMPILER_VAR_1159[2] = " = memoryAlloc(sizeof(array(struct reflectElement)));\n        ";____BAH_COMPILER_VAR_1159[1] = tmpV->name;____BAH_COMPILER_VAR_1159[0] = "\n        array(struct reflectElement)* ";char * ____BAH_COMPILER_VAR_1160 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1159, 15);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1160));
struct Tok ____BAH_COMPILER_VAR_1161 = {};
____BAH_COMPILER_VAR_1161.cont = "";
____BAH_COMPILER_VAR_1161.ogCont = "";
____BAH_COMPILER_VAR_1161.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1161.line = 1;
____BAH_COMPILER_VAR_1161.begLine = 1;
____BAH_COMPILER_VAR_1161.bahType = "";
____BAH_COMPILER_VAR_1161.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_1161.cont = tmpV->name;
____BAH_COMPILER_VAR_1161.line = fnt.line;
____BAH_COMPILER_VAR_1161.isValue = true;

    unsigned int ____BAH_COMPILER_VAR_1162 = 0;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1162);
    memory->data[____BAH_COMPILER_VAR_1162] = ____BAH_COMPILER_VAR_1161;
}
else if ((strcmp(fn->name, "breakPoint") == 0)) {
struct Tok ____BAH_COMPILER_VAR_1163 = {};
____BAH_COMPILER_VAR_1163.cont = "";
____BAH_COMPILER_VAR_1163.ogCont = "";
____BAH_COMPILER_VAR_1163.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1163.line = 1;
____BAH_COMPILER_VAR_1163.begLine = 1;
____BAH_COMPILER_VAR_1163.bahType = "";
____BAH_COMPILER_VAR_1163.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_1163.cont = "__dumpSymbols";
____BAH_COMPILER_VAR_1163.line = fnt.line;
struct Tok ____BAH_COMPILER_VAR_1164 = {};
____BAH_COMPILER_VAR_1164.cont = "";
____BAH_COMPILER_VAR_1164.ogCont = "";
____BAH_COMPILER_VAR_1164.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1164.line = 1;
____BAH_COMPILER_VAR_1164.begLine = 1;
____BAH_COMPILER_VAR_1164.bahType = "";
____BAH_COMPILER_VAR_1164.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_1164.cont = "(";
____BAH_COMPILER_VAR_1164.line = fnt.line;
struct Tok ____BAH_COMPILER_VAR_1165 = {};
____BAH_COMPILER_VAR_1165.cont = "";
____BAH_COMPILER_VAR_1165.ogCont = "";
____BAH_COMPILER_VAR_1165.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1165.line = 1;
____BAH_COMPILER_VAR_1165.begLine = 1;
____BAH_COMPILER_VAR_1165.bahType = "";
____BAH_COMPILER_VAR_1165.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_1165.cont = ")";
____BAH_COMPILER_VAR_1165.line = fnt.line;
memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 3;
memory->elemSize = sizeof(struct Tok);
memory->data = memoryAlloc(sizeof(struct Tok) * 50);
                    memory->realLength = 50;
memory->data[0] = ____BAH_COMPILER_VAR_1163;
memory->data[1] = ____BAH_COMPILER_VAR_1164;
memory->data[2] = ____BAH_COMPILER_VAR_1165;
memory = prePross(memory,LINE_TYPE_FN_CALL,elems);
struct Tok ____BAH_COMPILER_VAR_1166 = {};
____BAH_COMPILER_VAR_1166.cont = "";
____BAH_COMPILER_VAR_1166.ogCont = "";
____BAH_COMPILER_VAR_1166.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1166.line = 1;
____BAH_COMPILER_VAR_1166.begLine = 1;
____BAH_COMPILER_VAR_1166.bahType = "";
____BAH_COMPILER_VAR_1166.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_1166.cont = ",";
____BAH_COMPILER_VAR_1166.line = fnt.line;

    unsigned int ____BAH_COMPILER_VAR_1167 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1167);
    memory->data[____BAH_COMPILER_VAR_1167] = ____BAH_COMPILER_VAR_1166;
struct Tok ____BAH_COMPILER_VAR_1168 = {};
____BAH_COMPILER_VAR_1168.cont = "";
____BAH_COMPILER_VAR_1168.ogCont = "";
____BAH_COMPILER_VAR_1168.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1168.line = 1;
____BAH_COMPILER_VAR_1168.begLine = 1;
____BAH_COMPILER_VAR_1168.bahType = "";
____BAH_COMPILER_VAR_1168.type = TOKEN_TYPE_STR;
____BAH_COMPILER_VAR_1168.cont = currLine;
____BAH_COMPILER_VAR_1168.line = fnt.line;

    unsigned int ____BAH_COMPILER_VAR_1169 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1169);
    memory->data[____BAH_COMPILER_VAR_1169] = ____BAH_COMPILER_VAR_1168;
fn = searchFunc("breakPoint__inner",elems,true);
char** ____BAH_COMPILER_VAR_1170 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1170[1] = "(";____BAH_COMPILER_VAR_1170[0] = fn->name;char * ____BAH_COMPILER_VAR_1171 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1170, 2);fnt.cont = ____BAH_COMPILER_VAR_1171;
}
else if ((strcmp(fn->name, "sizeof") == 0)) {
char * tp = "";
register long int j = 0;
for (; (j<len(memory)); ++j) {
struct Tok tmpT = memory->data[j];
char** ____BAH_COMPILER_VAR_1172 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1172[1] = tmpT.cont;____BAH_COMPILER_VAR_1172[0] = tp;char * ____BAH_COMPILER_VAR_1173 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1172, 2);tp = ____BAH_COMPILER_VAR_1173;
};
struct variable* tmpV = searchVar(tp,elems);
if ((tmpV!=null)) {
struct string cType = getCType(tmpV->type,elems);
char** ____BAH_COMPILER_VAR_1174 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1174[1] = ")";____BAH_COMPILER_VAR_1174[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_1175 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1174, 2);char** ____BAH_COMPILER_VAR_1176 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1176[1] = ____BAH_COMPILER_VAR_1175;____BAH_COMPILER_VAR_1176[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1177 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1176, 2);fnt.cont = ____BAH_COMPILER_VAR_1177;
}
else {
struct string cType = getCType(tp,elems);
if (__builtin_expect((cType.length==0), 0)) {
struct Tok ft = memory->data[0];
throwErr(&ft,"Cannot get size of {TOKEN}.");
}
char** ____BAH_COMPILER_VAR_1178 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1178[1] = ")";____BAH_COMPILER_VAR_1178[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_1179 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1178, 2);char** ____BAH_COMPILER_VAR_1180 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1180[1] = ____BAH_COMPILER_VAR_1179;____BAH_COMPILER_VAR_1180[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1181 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1180, 2);fnt.cont = ____BAH_COMPILER_VAR_1181;
}
fnt.type = TOKEN_TYPE_FUNC;
fnt.isFunc = true;
fnt.bahType = "int";
fnt.bahRef = fn;

    unsigned int ____BAH_COMPILER_VAR_1182 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1182);
    l->data[____BAH_COMPILER_VAR_1182] = fnt;
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
char** ____BAH_COMPILER_VAR_1183 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1183[1] = parent->name;____BAH_COMPILER_VAR_1183[0] = amp;char * ____BAH_COMPILER_VAR_1184 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1183, 2);char** ____BAH_COMPILER_VAR_1185 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1185[1] = ____BAH_COMPILER_VAR_1184;____BAH_COMPILER_VAR_1185[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1186 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1185, 2);fnt.cont = ____BAH_COMPILER_VAR_1186;
++argIndex;
if ((len(fn->args)>argIndex)) {
char** ____BAH_COMPILER_VAR_1187 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1187[1] = ",";____BAH_COMPILER_VAR_1187[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1188 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1187, 2);fnt.cont = ____BAH_COMPILER_VAR_1188;
}
}
long int ogFntContL = strlen(fnt.cont);
register long int j = 0;
for (; (j<len(memory)); ++j) {
struct Tok t = memory->data[j];
if (__builtin_expect((argIndex==len(fn->args)), 0)) {
throwErr(&t,"Too many arguments, expected ')' not {TOKEN}.");
}
struct variable* arg = fn->args->data[argIndex];
char * tt = getTypeFromToken(&t,true,elems);
if ((strcmp(arg->type, "reflectElement") == 0)&&(strcmp(tt, "reflectElement") != 0)) {
t = parseReflect(t,tt,elems,false,t.cont,"0");
tt = "reflectElement";
}
if ((generic!=null)&&(strcmp(arg->type, "<any>") == 0)) {
arg->type = tt;
struct string tts = string(tt);
string__replace(&tts,"*","_AST_");
string__replace(&tts,":","_DP_");
string__replace(&tts,"[]","_ARR_");
char** ____BAH_COMPILER_VAR_1189 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1189[1] = string__str(&tts);____BAH_COMPILER_VAR_1189[0] = "__";char * ____BAH_COMPILER_VAR_1190 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1189, 2);char** ____BAH_COMPILER_VAR_1191 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1191[1] = ____BAH_COMPILER_VAR_1190;____BAH_COMPILER_VAR_1191[0] = fn->name;char * ____BAH_COMPILER_VAR_1192 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1191, 2);fn->name = ____BAH_COMPILER_VAR_1192;
}
else {
if (__builtin_expect((compTypes(arg->type,tt)==false), 0)) {
char** ____BAH_COMPILER_VAR_1193 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1193[4] = " in function call.";____BAH_COMPILER_VAR_1193[3] = arg->type;____BAH_COMPILER_VAR_1193[2] = ") as ";____BAH_COMPILER_VAR_1193[1] = tt;____BAH_COMPILER_VAR_1193[0] = "Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_1194 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1193, 5);throwErr(&t,____BAH_COMPILER_VAR_1194);
}
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
char** ____BAH_COMPILER_VAR_1195 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1195[1] = t.cont;____BAH_COMPILER_VAR_1195[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1196 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1195, 2);fnt.cont = ____BAH_COMPILER_VAR_1196;
++argIndex;
if ((j+1<len(memory))) {
++j;
t = memory->data[j];
if (__builtin_expect((strcmp(t.cont, ",") != 0), 0)) {
throwErr(&t,"Need separator between arguments, not {TOKEN}.");
}
char** ____BAH_COMPILER_VAR_1197 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1197[1] = ",";____BAH_COMPILER_VAR_1197[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1198 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1197, 2);fnt.cont = ____BAH_COMPILER_VAR_1198;
}
};
if (__builtin_expect((argIndex!=len(fn->args)), 0)) {
struct Tok lt = l->data[tokPos];
char** ____BAH_COMPILER_VAR_1199 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1199[2] = "'.";____BAH_COMPILER_VAR_1199[1] = fn->name;____BAH_COMPILER_VAR_1199[0] = "Not enough argument {TOKEN}, calling '";char * ____BAH_COMPILER_VAR_1200 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1199, 3);throwErr(&lt,____BAH_COMPILER_VAR_1200);
}
if ((generic!=null)) {
char** ____BAH_COMPILER_VAR_1201 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1201[3] = cpstringSubsitute(fnt.cont, ogFntContL, strlen(fnt.cont));____BAH_COMPILER_VAR_1201[2] = "(";____BAH_COMPILER_VAR_1201[1] = fn->name;____BAH_COMPILER_VAR_1201[0] = "__generic_";char * ____BAH_COMPILER_VAR_1202 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1201, 4);fnt.cont = ____BAH_COMPILER_VAR_1202;
if ((genericFunc__isAlreadyDecl(generic,fn->name)==false)) {
genericFunc__declare(generic,fn,elems);
}
}
fnt.bahRef = fn;
char** ____BAH_COMPILER_VAR_1203 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1203[1] = ")";____BAH_COMPILER_VAR_1203[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1204 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1203, 2);fnt.cont = ____BAH_COMPILER_VAR_1204;

    unsigned int ____BAH_COMPILER_VAR_1205 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1205);
    l->data[____BAH_COMPILER_VAR_1205] = fnt;
return tokPos;
};
long int valueStruct(__BAH_ARR_TYPE_Tok l,long int i,lineType ltp,struct Elems* elems){
long int tokPos = i-1;
struct Tok t = l->data[i-1];
char * tt = getTypeFromToken(&t,true,elems);
struct cStruct* s = searchStruct(tt,elems);
if ((s==null)) {
if (__builtin_expect((tt[strlen(tt)-1]==33), 0)) {
char** ____BAH_COMPILER_VAR_1206 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1206[2] = ") as structure.";____BAH_COMPILER_VAR_1206[1] = tt;____BAH_COMPILER_VAR_1206[0] = "Cannot use maybe value {TOKEN} (";char * ____BAH_COMPILER_VAR_1207 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1206, 3);throwErr(&t,____BAH_COMPILER_VAR_1207);
}
else {
char** ____BAH_COMPILER_VAR_1208 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1208[2] = ").";____BAH_COMPILER_VAR_1208[1] = tt;____BAH_COMPILER_VAR_1208[0] = "Unkown struct {TOKEN} (";char * ____BAH_COMPILER_VAR_1209 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1208, 3);throwErr(&t,____BAH_COMPILER_VAR_1209);
}
}
checkCanBeNull(&t,tt,elems);
struct Tok nt = l->data[i+1];
if (__builtin_expect((nt.isValue==false), 0)) {
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
if ((t.bahRef!=null)) {
parent = t.bahRef;
}
else {
parent = searchVar(t.cont,elems);
}
}
else {
char * tmpV = genCompilerVar();
struct string cType = getCType(tt,elems);
char** ____BAH_COMPILER_VAR_1210 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_1210[6] = ";\n                ";____BAH_COMPILER_VAR_1210[5] = t.cont;____BAH_COMPILER_VAR_1210[4] = " = ";____BAH_COMPILER_VAR_1210[3] = tmpV;____BAH_COMPILER_VAR_1210[2] = " ";____BAH_COMPILER_VAR_1210[1] = string__str(&cType);____BAH_COMPILER_VAR_1210[0] = "\n                ";char * ____BAH_COMPILER_VAR_1211 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1210, 7);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1211));
t.cont = tmpV;
struct variable* ____BAH_COMPILER_VAR_1212 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1212->name = "";
____BAH_COMPILER_VAR_1212->type = "";
____BAH_COMPILER_VAR_1212->constVal = "";
____BAH_COMPILER_VAR_1212->from = "";
____BAH_COMPILER_VAR_1212->name = tmpV;
____BAH_COMPILER_VAR_1212->type = tt;
parent = ____BAH_COMPILER_VAR_1212;
if (RCPavailable()) {

    unsigned int ____BAH_COMPILER_VAR_1213 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_1213);
    elems->vars->data[____BAH_COMPILER_VAR_1213] = parent;
}
}
struct func* fn = searchStructMethod(nt.cont,s,elems);
if (__builtin_expect((fn==null), 0)) {
char** ____BAH_COMPILER_VAR_1214 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1214[2] = ".";____BAH_COMPILER_VAR_1214[1] = s->name;____BAH_COMPILER_VAR_1214[0] = "Unknown method {TOKEN} in struct ";char * ____BAH_COMPILER_VAR_1215 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1214, 3);throwErr(&nt,____BAH_COMPILER_VAR_1215);
}
if ((t.type==TOKEN_TYPE_VAR)) {
if ((fn->isImported==true)+(fn->isMut==true)) {
struct variable* rp = searchVarByToken(&t,elems);
rp->lastSet = elems;
if ((rp->isArg==true)) {
currentFn->isMut = true;
}
}
}
if ((fn->isVar==true)) {
char** ____BAH_COMPILER_VAR_1216 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1216[2] = fn->name;____BAH_COMPILER_VAR_1216[1] = sep;____BAH_COMPILER_VAR_1216[0] = t.cont;char * ____BAH_COMPILER_VAR_1217 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1216, 3);fn->name = ____BAH_COMPILER_VAR_1217;
}
if (__builtin_expect((parent==null), 0)) {
throwErr(&t,"Could not find structure {TOKEN}.");
}
valueFunc(fn,parent,l,i,ltp,elems);
struct Tok fnt = l->data[i];
delete(l,i);
char** ____BAH_COMPILER_VAR_1218 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1218[2] = nt.ogCont;____BAH_COMPILER_VAR_1218[1] = ".";____BAH_COMPILER_VAR_1218[0] = t.ogCont;char * ____BAH_COMPILER_VAR_1219 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1218, 3);fnt.ogCont = ____BAH_COMPILER_VAR_1219;
fnt.pos = t.pos;

    unsigned int ____BAH_COMPILER_VAR_1220 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1220);
    l->data[____BAH_COMPILER_VAR_1220] = fnt;
return tokPos;
}
}
struct structMemb* m = searchStructMemb(nt.cont,s,elems);
if (__builtin_expect((m==null), 0)) {
char** ____BAH_COMPILER_VAR_1221 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1221[2] = "'.";____BAH_COMPILER_VAR_1221[1] = s->name;____BAH_COMPILER_VAR_1221[0] = "Unknown struct member {TOKEN} in struct '";char * ____BAH_COMPILER_VAR_1222 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1221, 3);throwErr(&nt,____BAH_COMPILER_VAR_1222);
}
if ((m->isFn==true)) {
char** ____BAH_COMPILER_VAR_1223 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1223[2] = m->name;____BAH_COMPILER_VAR_1223[1] = "__";____BAH_COMPILER_VAR_1223[0] = s->name;char * ____BAH_COMPILER_VAR_1224 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1223, 3);t.cont = ____BAH_COMPILER_VAR_1224;
}
else {
if ((t.type==TOKEN_TYPE_VAR)) {
t.parent = searchVarByToken(&t,elems);
}
char** ____BAH_COMPILER_VAR_1225 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1225[1] = nt.cont;____BAH_COMPILER_VAR_1225[0] = sep;char * ____BAH_COMPILER_VAR_1226 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1225, 2);char** ____BAH_COMPILER_VAR_1227 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1227[1] = ____BAH_COMPILER_VAR_1226;____BAH_COMPILER_VAR_1227[0] = t.cont;char * ____BAH_COMPILER_VAR_1228 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1227, 2);t.cont = ____BAH_COMPILER_VAR_1228;
}
char** ____BAH_COMPILER_VAR_1229 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1229[1] = nt.cont;____BAH_COMPILER_VAR_1229[0] = ".";char * ____BAH_COMPILER_VAR_1230 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1229, 2);char** ____BAH_COMPILER_VAR_1231 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1231[1] = ____BAH_COMPILER_VAR_1230;____BAH_COMPILER_VAR_1231[0] = t.ogCont;char * ____BAH_COMPILER_VAR_1232 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1231, 2);t.ogCont = ____BAH_COMPILER_VAR_1232;
t.bahType = m->type;
struct variable* ____BAH_COMPILER_VAR_1233 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1233->name = "";
____BAH_COMPILER_VAR_1233->type = "";
____BAH_COMPILER_VAR_1233->constVal = "";
____BAH_COMPILER_VAR_1233->from = "";
____BAH_COMPILER_VAR_1233->name = t.cont;
____BAH_COMPILER_VAR_1233->type = t.bahType;
t.bahRef = ____BAH_COMPILER_VAR_1233;

    unsigned int ____BAH_COMPILER_VAR_1234 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1234);
    l->data[____BAH_COMPILER_VAR_1234] = t;
return tokPos;
};
long int valueArr(__BAH_ARR_TYPE_Tok l,long int i,lineType ltp,struct Elems* elems){
long int tokPos = i-1;
struct Tok pt = l->data[tokPos];
delete(l,tokPos);
if (__builtin_expect((pt.isValue==false), 0)) {
throwErr(&pt,"Cannot use {TOKEN} as value (array).");
}
char * ____BAH_COMPILER_VAR_1235 =getTypeFromToken(&pt,true,elems);struct string ptt = string(____BAH_COMPILER_VAR_1235);
struct Tok t = pt;
t.isValue = true;
char** ____BAH_COMPILER_VAR_1236 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1236[1] = "[";____BAH_COMPILER_VAR_1236[0] = t.ogCont;char * ____BAH_COMPILER_VAR_1237 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1236, 2);t.ogCont = ____BAH_COMPILER_VAR_1237;
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
char** ____BAH_COMPILER_VAR_1238 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1238[1] = "]";____BAH_COMPILER_VAR_1238[0] = t.ogCont;char * ____BAH_COMPILER_VAR_1239 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1238, 2);t.ogCont = ____BAH_COMPILER_VAR_1239;
if ((nbEncls==0)) {
break;
}
}
char** ____BAH_COMPILER_VAR_1240 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1240[1] = tmpT.ogCont;____BAH_COMPILER_VAR_1240[0] = t.ogCont;char * ____BAH_COMPILER_VAR_1241 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1240, 2);t.ogCont = ____BAH_COMPILER_VAR_1241;

    unsigned int ____BAH_COMPILER_VAR_1242 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1242);
    memory->data[____BAH_COMPILER_VAR_1242] = tmpT;
};
deleteRange(l,tokPos+1,i);
memory = prePross(memory,(lineType)-1,elems);
if (__builtin_expect((len(memory)==0), 0)) {
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
if (__builtin_expect((compTypes(firstT,"int")==false), 0)) {
throwErr(&first,"Cannot use {TOKEN} as int.");
}
char * thirdT = getTypeFromToken(&third,true,elems);
if (__builtin_expect((compTypes(thirdT,"int")==false), 0)) {
throwErr(&third,"Cannot use {TOKEN} as int.");
}
if (__builtin_expect((strcmp(second.cont, ":") != 0), 0)) {
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
if (__builtin_expect((compTypes(secondT,"int")==false), 0)) {
throwErr(&second,"Cannot use {TOKEN} as int.");
}
to = second.cont;
}
else if ((strcmp(second.cont, ":") == 0)) {
char * firstT = getTypeFromToken(&first,true,elems);
if (__builtin_expect((compTypes(firstT,"int")==false), 0)) {
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
char * ____BAH_COMPILER_VAR_1243 =getTypeFromToken(&index,true,elems);if (__builtin_expect((compTypes(____BAH_COMPILER_VAR_1243,"int")==false), 0)) {
throwErr(&index,"Cannot use {TOKEN} as array index (int).");
}
string__trimLeft(&ptt,2);
t.bahType = string__str(&ptt);
char** ____BAH_COMPILER_VAR_1244 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1244[3] = "]";____BAH_COMPILER_VAR_1244[2] = index.cont;____BAH_COMPILER_VAR_1244[1] = "->data[";____BAH_COMPILER_VAR_1244[0] = pt.cont;char * ____BAH_COMPILER_VAR_1245 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1244, 4);t.cont = ____BAH_COMPILER_VAR_1245;
if ((tokPos+1<len(l))&&(strcmp(l->data[tokPos+1].cont, ".") == 0)) {
struct variable* ____BAH_COMPILER_VAR_1246 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1246->name = "";
____BAH_COMPILER_VAR_1246->type = "";
____BAH_COMPILER_VAR_1246->constVal = "";
____BAH_COMPILER_VAR_1246->from = "";
____BAH_COMPILER_VAR_1246->name = t.cont;
____BAH_COMPILER_VAR_1246->type = t.bahType;
struct variable* tmpV = ____BAH_COMPILER_VAR_1246;
t.bahRef = tmpV;
}
}
else {
t.bahType = string__str(&ptt);
if ((strcmp(to, "") == 0)) {
char** ____BAH_COMPILER_VAR_1247 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1247[1] = "->length";____BAH_COMPILER_VAR_1247[0] = pt.cont;char * ____BAH_COMPILER_VAR_1248 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1247, 2);to = ____BAH_COMPILER_VAR_1248;
}
char** ____BAH_COMPILER_VAR_1249 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_1249[6] = ")";____BAH_COMPILER_VAR_1249[5] = to;____BAH_COMPILER_VAR_1249[4] = ", ";____BAH_COMPILER_VAR_1249[3] = from;____BAH_COMPILER_VAR_1249[2] = ", ";____BAH_COMPILER_VAR_1249[1] = pt.cont;____BAH_COMPILER_VAR_1249[0] = "arraySubstitute(";char * ____BAH_COMPILER_VAR_1250 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1249, 7);t.cont = ____BAH_COMPILER_VAR_1250;
}
}
else if (string__hasPrefix(&ptt,"buffer:")) {
if ((split==false)) {
t.bahType = "char";
struct Tok index = memory->data[0];
char * ____BAH_COMPILER_VAR_1251 =getTypeFromToken(&index,true,elems);if (__builtin_expect((compTypes(____BAH_COMPILER_VAR_1251,"int")==false), 0)) {
throwErr(&index,"Cannot use {TOKEN} as buffer index (int).");
}
char** ____BAH_COMPILER_VAR_1252 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1252[3] = "]";____BAH_COMPILER_VAR_1252[2] = index.cont;____BAH_COMPILER_VAR_1252[1] = "[";____BAH_COMPILER_VAR_1252[0] = pt.cont;char * ____BAH_COMPILER_VAR_1253 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1252, 4);t.cont = ____BAH_COMPILER_VAR_1253;
}
else {
t.bahType = "cpstring";
if ((strcmp(to, "") == 0)) {
char** ____BAH_COMPILER_VAR_1254 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1254[2] = ")";____BAH_COMPILER_VAR_1254[1] = pt.cont;____BAH_COMPILER_VAR_1254[0] = "strlen(";char * ____BAH_COMPILER_VAR_1255 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1254, 3);to = ____BAH_COMPILER_VAR_1255;
}
char** ____BAH_COMPILER_VAR_1256 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_1256[6] = ")";____BAH_COMPILER_VAR_1256[5] = to;____BAH_COMPILER_VAR_1256[4] = ", ";____BAH_COMPILER_VAR_1256[3] = from;____BAH_COMPILER_VAR_1256[2] = ", ";____BAH_COMPILER_VAR_1256[1] = pt.cont;____BAH_COMPILER_VAR_1256[0] = "cpstringSubsitute(";char * ____BAH_COMPILER_VAR_1257 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1256, 7);t.cont = ____BAH_COMPILER_VAR_1257;
}
}
else if (string__hasPrefix(&ptt,"map:")) {
if (__builtin_expect((split==true), 0)) {
throwErr(&pt,"Cannot do substitution on a map {TOKEN}.");
}
string__trimLeft(&ptt,4);
char * ____BAH_COMPILER_VAR_1258 =string__str(&ptt);struct string elemType = getCType(____BAH_COMPILER_VAR_1258,elems);
struct Tok index = memory->data[0];
char * ____BAH_COMPILER_VAR_1259 =getTypeFromToken(&index,true,elems);if (__builtin_expect((compTypes(____BAH_COMPILER_VAR_1259,"cpstring")==false), 0)) {
throwErr(&index,"Cannot use {TOKEN} as map index (cpstring).");
}
if ((tokPos==0)&&(ltp==LINE_TYPE_VAR)) {
struct variable* ____BAH_COMPILER_VAR_1260 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1260->name = "";
____BAH_COMPILER_VAR_1260->type = "";
____BAH_COMPILER_VAR_1260->constVal = "";
____BAH_COMPILER_VAR_1260->from = "";
____BAH_COMPILER_VAR_1260->name = genCompilerVar();
____BAH_COMPILER_VAR_1260->type = string__str(&ptt);
struct variable* tmpV = ____BAH_COMPILER_VAR_1260;

    unsigned int ____BAH_COMPILER_VAR_1261 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_1261);
    elems->vars->data[____BAH_COMPILER_VAR_1261] = tmpV;
if (isGlobal()) {
char** ____BAH_COMPILER_VAR_1262 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1262[3] = ";\n";____BAH_COMPILER_VAR_1262[2] = tmpV->name;____BAH_COMPILER_VAR_1262[1] = " ";____BAH_COMPILER_VAR_1262[0] = string__str(&elemType);char * ____BAH_COMPILER_VAR_1263 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1262, 4);INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_1263));
}
else {
char** ____BAH_COMPILER_VAR_1264 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1264[3] = ";\n";____BAH_COMPILER_VAR_1264[2] = tmpV->name;____BAH_COMPILER_VAR_1264[1] = " ";____BAH_COMPILER_VAR_1264[0] = string__str(&elemType);char * ____BAH_COMPILER_VAR_1265 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1264, 4);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1265));
}
char * ____BAH_COMPILER_VAR_1266 =string__str(&ptt);if (isRCPpointerType(____BAH_COMPILER_VAR_1266)) {
char** ____BAH_COMPILER_VAR_1267 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_1267[6] = ");\n";____BAH_COMPILER_VAR_1267[5] = tmpV->name;____BAH_COMPILER_VAR_1267[4] = ", ";____BAH_COMPILER_VAR_1267[3] = index.cont;____BAH_COMPILER_VAR_1267[2] = ", ";____BAH_COMPILER_VAR_1267[1] = pt.cont;____BAH_COMPILER_VAR_1267[0] = "mapWrapper__set(";char * ____BAH_COMPILER_VAR_1268 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1267, 7);NEXT_LINE = ____BAH_COMPILER_VAR_1268;
}
else {
char** ____BAH_COMPILER_VAR_1269 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_1269[8] = "));\n";____BAH_COMPILER_VAR_1269[7] = string__str(&elemType);____BAH_COMPILER_VAR_1269[6] = ", sizeof(";____BAH_COMPILER_VAR_1269[5] = tmpV->name;____BAH_COMPILER_VAR_1269[4] = ", &";____BAH_COMPILER_VAR_1269[3] = index.cont;____BAH_COMPILER_VAR_1269[2] = ", ";____BAH_COMPILER_VAR_1269[1] = pt.cont;____BAH_COMPILER_VAR_1269[0] = "mapWrapper__setAny(";char * ____BAH_COMPILER_VAR_1270 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1269, 9);NEXT_LINE = ____BAH_COMPILER_VAR_1270;
}
t.cont = tmpV->name;
t.bahType = string__str(&ptt);
}
else {
t.isFunc = true;
struct rope* res= null;
char * tmpV = genCompilerVar();
char * ____BAH_COMPILER_VAR_1271 =string__str(&ptt);if (isRCPpointerType(____BAH_COMPILER_VAR_1271)) {
char** ____BAH_COMPILER_VAR_1272 = alloca(8 * sizeof(char*));____BAH_COMPILER_VAR_1272[7] = ");\n";____BAH_COMPILER_VAR_1272[6] = index.cont;____BAH_COMPILER_VAR_1272[5] = ", ";____BAH_COMPILER_VAR_1272[4] = t.cont;____BAH_COMPILER_VAR_1272[3] = "=mapWrapper__get(";____BAH_COMPILER_VAR_1272[2] = tmpV;____BAH_COMPILER_VAR_1272[1] = " ";____BAH_COMPILER_VAR_1272[0] = string__str(&elemType);char * ____BAH_COMPILER_VAR_1273 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1272, 8);res = rope(____BAH_COMPILER_VAR_1273);
t.cont = tmpV;
}
else {
char** ____BAH_COMPILER_VAR_1274 = alloca(8 * sizeof(char*));____BAH_COMPILER_VAR_1274[7] = ");\n";____BAH_COMPILER_VAR_1274[6] = index.cont;____BAH_COMPILER_VAR_1274[5] = ", ";____BAH_COMPILER_VAR_1274[4] = pt.cont;____BAH_COMPILER_VAR_1274[3] = "=mapWrapper__get(";____BAH_COMPILER_VAR_1274[2] = tmpV;____BAH_COMPILER_VAR_1274[1] = "* ";____BAH_COMPILER_VAR_1274[0] = string__str(&elemType);char * ____BAH_COMPILER_VAR_1275 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1274, 8);res = rope(____BAH_COMPILER_VAR_1275);
char** ____BAH_COMPILER_VAR_1276 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1276[4] = ")";____BAH_COMPILER_VAR_1276[3] = tmpV;____BAH_COMPILER_VAR_1276[2] = ")(*";____BAH_COMPILER_VAR_1276[1] = string__str(&elemType);____BAH_COMPILER_VAR_1276[0] = "(";char * ____BAH_COMPILER_VAR_1277 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1276, 5);t.cont = ____BAH_COMPILER_VAR_1277;
}
if (RCPavailable()) {
struct variable* ____BAH_COMPILER_VAR_1278 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1278->name = "";
____BAH_COMPILER_VAR_1278->type = "";
____BAH_COMPILER_VAR_1278->constVal = "";
____BAH_COMPILER_VAR_1278->from = "";
____BAH_COMPILER_VAR_1278->name = tmpV;
____BAH_COMPILER_VAR_1278->type = string__str(&ptt);

    unsigned int ____BAH_COMPILER_VAR_1279 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_1279);
    elems->vars->data[____BAH_COMPILER_VAR_1279] = ____BAH_COMPILER_VAR_1278;
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
char * ____BAH_COMPILER_VAR_1280 =getTypeFromToken(&index,true,elems);if (__builtin_expect((compTypes(____BAH_COMPILER_VAR_1280,"int")==false), 0)) {
throwErr(&index,"Cannot use {TOKEN} as cpstring index (int).");
}
char** ____BAH_COMPILER_VAR_1281 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1281[3] = "]";____BAH_COMPILER_VAR_1281[2] = index.cont;____BAH_COMPILER_VAR_1281[1] = "[";____BAH_COMPILER_VAR_1281[0] = pt.cont;char * ____BAH_COMPILER_VAR_1282 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1281, 4);t.cont = ____BAH_COMPILER_VAR_1282;
}
else {
if ((strcmp(to, "") == 0)) {
char** ____BAH_COMPILER_VAR_1283 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1283[2] = ")";____BAH_COMPILER_VAR_1283[1] = pt.cont;____BAH_COMPILER_VAR_1283[0] = "strlen(";char * ____BAH_COMPILER_VAR_1284 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1283, 3);to = ____BAH_COMPILER_VAR_1284;
}
char** ____BAH_COMPILER_VAR_1285 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_1285[6] = ")";____BAH_COMPILER_VAR_1285[5] = to;____BAH_COMPILER_VAR_1285[4] = ", ";____BAH_COMPILER_VAR_1285[3] = from;____BAH_COMPILER_VAR_1285[2] = ", ";____BAH_COMPILER_VAR_1285[1] = pt.cont;____BAH_COMPILER_VAR_1285[0] = "cpstringSubsitute(";char * ____BAH_COMPILER_VAR_1286 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1285, 7);t.cont = ____BAH_COMPILER_VAR_1286;
}
}
else if (string__hasPrefix(&ptt,"tuple:")) {
t.isOper = true;
struct variable* v = searchVar(pt.cont,elems);
if (__builtin_expect((v==null), 0)) {
throwErr(&pt,"Unkown var {TOKEN}.");
}
array(struct string)* parts = splitString(ptt,":");
struct Tok index = memory->data[0];
if ((index.type==TOKEN_TYPE_INT)) {
long int ind = strToInt(index.cont);
char * ____BAH_COMPILER_VAR_1287 =string__str(&parts->data[1]);if (__builtin_expect((ind>=strToInt(____BAH_COMPILER_VAR_1287)), 0)) {
char** ____BAH_COMPILER_VAR_1288 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1288[4] = ".";____BAH_COMPILER_VAR_1288[3] = string__str(&parts->data[1]);____BAH_COMPILER_VAR_1288[2] = " of length ";____BAH_COMPILER_VAR_1288[1] = pt.cont;____BAH_COMPILER_VAR_1288[0] = "Cannot access index {TOKEN} of tupple ";char * ____BAH_COMPILER_VAR_1289 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1288, 5);throwErr(&index,____BAH_COMPILER_VAR_1289);
}
}
else {
char * ____BAH_COMPILER_VAR_1290 =getTypeFromToken(&index,true,elems);if (__builtin_expect((compTypes(____BAH_COMPILER_VAR_1290,"int")==false), 0)) {
throwErr(&index,"Cannot use {TOKEN} as tuple index (int).");
}
}
char** ____BAH_COMPILER_VAR_1291 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1291[3] = "]";____BAH_COMPILER_VAR_1291[2] = index.cont;____BAH_COMPILER_VAR_1291[1] = "[";____BAH_COMPILER_VAR_1291[0] = pt.cont;char * ____BAH_COMPILER_VAR_1292 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1291, 4);t.cont = ____BAH_COMPILER_VAR_1292;
t.bahType = string__str(&parts->data[2]);
}
else {
char** ____BAH_COMPILER_VAR_1293 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1293[2] = ") as array.";____BAH_COMPILER_VAR_1293[1] = string__str(&ptt);____BAH_COMPILER_VAR_1293[0] = "Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_1294 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1293, 3);throwErr(&pt,____BAH_COMPILER_VAR_1294);
}
t.isValue = true;

    unsigned int ____BAH_COMPILER_VAR_1295 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1295);
    l->data[____BAH_COMPILER_VAR_1295] = t;
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
char** ____BAH_COMPILER_VAR_1296 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1296[1] = odecl;____BAH_COMPILER_VAR_1296[0] = "register ";char * ____BAH_COMPILER_VAR_1297 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1296, 2);OUTPUT->totalLen = OUTPUT->totalLen+ropeSet(v->declRope,____BAH_COMPILER_VAR_1297);
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
if (__builtin_expect((string__hasPrefix(&arrT,"[]")==0), 0)) {
char** ____BAH_COMPILER_VAR_1298 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1298[2] = ") as array.";____BAH_COMPILER_VAR_1298[1] = ntt;____BAH_COMPILER_VAR_1298[0] = "Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_1299 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1298, 3);throwErr(&nt,____BAH_COMPILER_VAR_1299);
}
string__trimLeft(&arrT,2);
char * ____BAH_COMPILER_VAR_1300 =string__str(&arrT);if (__builtin_expect((compTypes(ptt,____BAH_COMPILER_VAR_1300)==false), 0)) {
char** ____BAH_COMPILER_VAR_1301 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1301[4] = ".";____BAH_COMPILER_VAR_1301[3] = ntt;____BAH_COMPILER_VAR_1301[2] = ") in ";____BAH_COMPILER_VAR_1301[1] = ptt;____BAH_COMPILER_VAR_1301[0] = "Cannot search for {TOKEN} (";char * ____BAH_COMPILER_VAR_1302 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1301, 5);throwErr(&pt,____BAH_COMPILER_VAR_1302);
}
char * compVar = genCompilerVar();
char * comp = "";
pt.cont = registerRCPvar(ptt,pt.cont,elems);
if ((strcmp(ptt, "cpstring") == 0)) {
char** ____BAH_COMPILER_VAR_1303 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_1303[5] = ") == 0";____BAH_COMPILER_VAR_1303[4] = pt.cont;____BAH_COMPILER_VAR_1303[3] = "->data[i], ";____BAH_COMPILER_VAR_1303[2] = nt.cont;____BAH_COMPILER_VAR_1303[1] = "->data[i] != 0 && strcmp(";____BAH_COMPILER_VAR_1303[0] = nt.cont;char * ____BAH_COMPILER_VAR_1304 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1303, 6);comp = ____BAH_COMPILER_VAR_1304;
}
else {
char** ____BAH_COMPILER_VAR_1305 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1305[2] = pt.cont;____BAH_COMPILER_VAR_1305[1] = "->data[i] == ";____BAH_COMPILER_VAR_1305[0] = nt.cont;char * ____BAH_COMPILER_VAR_1306 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1305, 3);comp = ____BAH_COMPILER_VAR_1306;
}
char** ____BAH_COMPILER_VAR_1307 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_1307[8] = "=1;\n                break;\n            };\n        }\n        ";____BAH_COMPILER_VAR_1307[7] = compVar;____BAH_COMPILER_VAR_1307[6] = ") {\n                ";____BAH_COMPILER_VAR_1307[5] = comp;____BAH_COMPILER_VAR_1307[4] = "->length-1; i!=-1;i--) {\n            if (";____BAH_COMPILER_VAR_1307[3] = nt.cont;____BAH_COMPILER_VAR_1307[2] = " = 0;\n        for(int i=";____BAH_COMPILER_VAR_1307[1] = compVar;____BAH_COMPILER_VAR_1307[0] = "\n        char ";char * ____BAH_COMPILER_VAR_1308 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1307, 9);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1308));
pt.isExpensive = true;
pt.cont = compVar;
}
else {
if (__builtin_expect((compTypes(ptt,ntt)==false), 0)) {
char** ____BAH_COMPILER_VAR_1309 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1309[4] = ".";____BAH_COMPILER_VAR_1309[3] = ptt;____BAH_COMPILER_VAR_1309[2] = ") with type ";____BAH_COMPILER_VAR_1309[1] = ntt;____BAH_COMPILER_VAR_1309[0] = "Cannot compare {TOKEN} (";char * ____BAH_COMPILER_VAR_1310 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1309, 5);throwErr(&nt,____BAH_COMPILER_VAR_1310);
}
if ((strcmp(ptt, "cpstring") == 0)) {
if ((strcmp(t.cont, "==") == 0)) {
char** ____BAH_COMPILER_VAR_1311 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1311[4] = ") == 0)";____BAH_COMPILER_VAR_1311[3] = nt.cont;____BAH_COMPILER_VAR_1311[2] = ", ";____BAH_COMPILER_VAR_1311[1] = pt.cont;____BAH_COMPILER_VAR_1311[0] = "(strcmp(";char * ____BAH_COMPILER_VAR_1312 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1311, 5);pt.cont = ____BAH_COMPILER_VAR_1312;
}
else if ((strcmp(t.cont, "!=") == 0)) {
char** ____BAH_COMPILER_VAR_1313 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1313[4] = ") != 0)";____BAH_COMPILER_VAR_1313[3] = nt.cont;____BAH_COMPILER_VAR_1313[2] = ", ";____BAH_COMPILER_VAR_1313[1] = pt.cont;____BAH_COMPILER_VAR_1313[0] = "(strcmp(";char * ____BAH_COMPILER_VAR_1314 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1313, 5);pt.cont = ____BAH_COMPILER_VAR_1314;
}
else if ((strcmp(t.cont, ">") == 0)) {
char** ____BAH_COMPILER_VAR_1315 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1315[4] = "))";____BAH_COMPILER_VAR_1315[3] = nt.cont;____BAH_COMPILER_VAR_1315[2] = ") > srtlen(";____BAH_COMPILER_VAR_1315[1] = pt.cont;____BAH_COMPILER_VAR_1315[0] = "(strlen(";char * ____BAH_COMPILER_VAR_1316 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1315, 5);pt.cont = ____BAH_COMPILER_VAR_1316;
}
else if ((strcmp(t.cont, "<") == 0)) {
char** ____BAH_COMPILER_VAR_1317 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1317[4] = "))";____BAH_COMPILER_VAR_1317[3] = nt.cont;____BAH_COMPILER_VAR_1317[2] = ") < srtlen(";____BAH_COMPILER_VAR_1317[1] = pt.cont;____BAH_COMPILER_VAR_1317[0] = "(strlen(";char * ____BAH_COMPILER_VAR_1318 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1317, 5);pt.cont = ____BAH_COMPILER_VAR_1318;
}
else if ((strcmp(t.cont, ">=") == 0)) {
char** ____BAH_COMPILER_VAR_1319 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1319[4] = "))";____BAH_COMPILER_VAR_1319[3] = nt.cont;____BAH_COMPILER_VAR_1319[2] = ") >= srtlen(";____BAH_COMPILER_VAR_1319[1] = pt.cont;____BAH_COMPILER_VAR_1319[0] = "(strlen(";char * ____BAH_COMPILER_VAR_1320 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1319, 5);pt.cont = ____BAH_COMPILER_VAR_1320;
}
else if ((strcmp(t.cont, "<=") == 0)) {
char** ____BAH_COMPILER_VAR_1321 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1321[4] = "))";____BAH_COMPILER_VAR_1321[3] = nt.cont;____BAH_COMPILER_VAR_1321[2] = ") <= srtlen(";____BAH_COMPILER_VAR_1321[1] = pt.cont;____BAH_COMPILER_VAR_1321[0] = "(strlen(";char * ____BAH_COMPILER_VAR_1322 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1321, 5);pt.cont = ____BAH_COMPILER_VAR_1322;
}
pt.isExpensive = true;
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
struct varCheck ____BAH_COMPILER_VAR_1323 = {};
____BAH_COMPILER_VAR_1323.v = ptV;
____BAH_COMPILER_VAR_1323.checkNull = ntIsNull;

    unsigned int ____BAH_COMPILER_VAR_1324 = len(currChecks);
    __Bah_realocate_arr(currChecks, ____BAH_COMPILER_VAR_1324);
    currChecks->data[____BAH_COMPILER_VAR_1324] = ____BAH_COMPILER_VAR_1323;
}
else if ((strcmp(t.cont, "!=") == 0)) {
struct varCheck ____BAH_COMPILER_VAR_1325 = {};
____BAH_COMPILER_VAR_1325.v = ptV;
____BAH_COMPILER_VAR_1325.checkNull = (ntIsNull==false);

    unsigned int ____BAH_COMPILER_VAR_1326 = len(currChecks);
    __Bah_realocate_arr(currChecks, ____BAH_COMPILER_VAR_1326);
    currChecks->data[____BAH_COMPILER_VAR_1326] = ____BAH_COMPILER_VAR_1325;
}
}
}
if (isExprExpensive(&pt)||isExprExpensive(&nt)) {
pt.isExpensive = true;
}
else {
pt.isExpensive = false;
}
char** ____BAH_COMPILER_VAR_1327 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1327[4] = ")";____BAH_COMPILER_VAR_1327[3] = nt.cont;____BAH_COMPILER_VAR_1327[2] = t.cont;____BAH_COMPILER_VAR_1327[1] = pt.cont;____BAH_COMPILER_VAR_1327[0] = "(";char * ____BAH_COMPILER_VAR_1328 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1327, 5);pt.cont = ____BAH_COMPILER_VAR_1328;
}
}
pt.isOper = true;
pt.bahType = "bool";
pt.isValue = true;

    unsigned int ____BAH_COMPILER_VAR_1329 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1329);
    l->data[____BAH_COMPILER_VAR_1329] = pt;
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
char** ____BAH_COMPILER_VAR_1330 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1330[2] = pt.cont;____BAH_COMPILER_VAR_1330[1] = t.cont;____BAH_COMPILER_VAR_1330[0] = t.cont;char * ____BAH_COMPILER_VAR_1331 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1330, 3);pt.cont = ____BAH_COMPILER_VAR_1331;

    unsigned int ____BAH_COMPILER_VAR_1332 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1332);
    l->data[____BAH_COMPILER_VAR_1332] = pt;
return tokPos;
}
char * ntt = getTypeFromToken(&nt,true,elems);
if (__builtin_expect((compTypes(ptt,ntt)==false), 0)) {
char** ____BAH_COMPILER_VAR_1333 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1333[4] = ".";____BAH_COMPILER_VAR_1333[3] = ptt;____BAH_COMPILER_VAR_1333[2] = ") as ";____BAH_COMPILER_VAR_1333[1] = ntt;____BAH_COMPILER_VAR_1333[0] = "Cannot compare {TOKEN} (";char * ____BAH_COMPILER_VAR_1334 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1333, 5);throwErr(&nt,____BAH_COMPILER_VAR_1334);
}
if ((strcmp(ptt, "cpstring") == 0)) {
array(char *)* strs = memoryAlloc(sizeof(array(char *)));

strs->length = 2;
strs->elemSize = sizeof(char *);
strs->data = memoryAlloc(sizeof(char *) * 50);
                    strs->realLength = 50;
strs->data[0] = nt.cont;
strs->data[1] = pt.cont;
if (__builtin_expect((strcmp(t.cont, "+") != 0), 0)) {
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
if (__builtin_expect((compTypes(tt,"cpstring")==false), 0)) {
char** ____BAH_COMPILER_VAR_1335 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1335[2] = ").";____BAH_COMPILER_VAR_1335[1] = tt;____BAH_COMPILER_VAR_1335[0] = "Cannot concatenate cpstring with {TOKEN} (";char * ____BAH_COMPILER_VAR_1336 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1335, 3);throwErr(&currStrTk,____BAH_COMPILER_VAR_1336);
}

    unsigned int ____BAH_COMPILER_VAR_1337 = len(strs);
    __Bah_realocate_arr(strs, ____BAH_COMPILER_VAR_1337);
    strs->data[____BAH_COMPILER_VAR_1337] = currStrTk.cont;
if ((i-1>=0)) {
--i;
t = l->data[i];
if ((strcmp(t.cont, "+") != 0)) {
char * ____BAH_COMPILER_VAR_1339 =t.cont;
        char ____BAH_COMPILER_VAR_1338 = 0;
        for(int i=signs->length-1; i!=-1;i--) {
            if (signs->data[i] != 0 && strcmp(signs->data[i], ____BAH_COMPILER_VAR_1339) == 0) {
                ____BAH_COMPILER_VAR_1338=1;
                break;
            };
        }
        if (__builtin_expect(____BAH_COMPILER_VAR_1338, 0)) {
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
else if (__builtin_expect(inArrayStr(nat.cont,signs), 0)) {
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
char** ____BAH_COMPILER_VAR_1340 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1340[2] = ").";____BAH_COMPILER_VAR_1340[1] = ptt;____BAH_COMPILER_VAR_1340[0] = "Undefined operation on struct {TOKEN} (";char * ____BAH_COMPILER_VAR_1341 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1340, 3);throwErr(&pt,____BAH_COMPILER_VAR_1341);
}
struct structMemb* methd = searchStructMemb(mName,s,elems);
if ((methd!=null)&&(methd->isFn==true)) {
if (RCPavailable()) {
char** ____BAH_COMPILER_VAR_1342 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_1342[8] = ")";____BAH_COMPILER_VAR_1342[7] = nt.cont;____BAH_COMPILER_VAR_1342[6] = ", ";____BAH_COMPILER_VAR_1342[5] = pt.cont;____BAH_COMPILER_VAR_1342[4] = amp;____BAH_COMPILER_VAR_1342[3] = "(";____BAH_COMPILER_VAR_1342[2] = mName;____BAH_COMPILER_VAR_1342[1] = "__";____BAH_COMPILER_VAR_1342[0] = s->name;char * ____BAH_COMPILER_VAR_1343 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1342, 9);pt.cont = registerRCPvar(ptt,____BAH_COMPILER_VAR_1343,elems);
pt.type = TOKEN_TYPE_VAR;
pt.isFunc = false;
pt.isOper = false;
}
else {
char** ____BAH_COMPILER_VAR_1344 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_1344[8] = ")";____BAH_COMPILER_VAR_1344[7] = nt.cont;____BAH_COMPILER_VAR_1344[6] = ", ";____BAH_COMPILER_VAR_1344[5] = pt.cont;____BAH_COMPILER_VAR_1344[4] = amp;____BAH_COMPILER_VAR_1344[3] = "(";____BAH_COMPILER_VAR_1344[2] = mName;____BAH_COMPILER_VAR_1344[1] = "__";____BAH_COMPILER_VAR_1344[0] = s->name;char * ____BAH_COMPILER_VAR_1345 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1344, 9);pt.cont = ____BAH_COMPILER_VAR_1345;
pt.isFunc = true;
}
}
}
else {
char** ____BAH_COMPILER_VAR_1346 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1346[1] = nt.cont;____BAH_COMPILER_VAR_1346[0] = t.cont;char * ____BAH_COMPILER_VAR_1347 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1346, 2);char** ____BAH_COMPILER_VAR_1348 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1348[1] = ____BAH_COMPILER_VAR_1347;____BAH_COMPILER_VAR_1348[0] = pt.cont;char * ____BAH_COMPILER_VAR_1349 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1348, 2);pt.cont = ____BAH_COMPILER_VAR_1349;
}
pt.isOper = true;
}
pt.isNotExpsvOper = false;

    unsigned int ____BAH_COMPILER_VAR_1350 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1350);
    l->data[____BAH_COMPILER_VAR_1350] = pt;
return tokPos;
};
long int valueSendChan(__BAH_ARR_TYPE_Tok l,long int i,struct Elems* elems){
long int posTok = i-2;
struct Tok nt = l->data[posTok];
struct Tok pt = l->data[posTok+2];
deleteRange(l,posTok,posTok+2);
char * ntt = getTypeFromToken(&nt,true,elems);
char * ____BAH_COMPILER_VAR_1351 =getTypeFromToken(&pt,true,elems);struct string ptt = string(____BAH_COMPILER_VAR_1351);
if (__builtin_expect((string__hasPrefix(&ptt,"chan:")==0), 0)) {
char** ____BAH_COMPILER_VAR_1352 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1352[2] = ") as chan.";____BAH_COMPILER_VAR_1352[1] = string__str(&ptt);____BAH_COMPILER_VAR_1352[0] = "Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_1353 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1352, 3);throwErr(&pt,____BAH_COMPILER_VAR_1353);
}
string__trimLeft(&ptt,5);
if (__builtin_expect(isGlobal(), 0)) {
throwErr(&pt,"Cannot send to channel {TOKEN} of a function.");
}
char * ____BAH_COMPILER_VAR_1354 =string__str(&ptt);if (__builtin_expect((compTypes(ntt,____BAH_COMPILER_VAR_1354)==false), 0)) {
char** ____BAH_COMPILER_VAR_1355 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1355[4] = ".";____BAH_COMPILER_VAR_1355[3] = string__str(&ptt);____BAH_COMPILER_VAR_1355[2] = ") through chan:";____BAH_COMPILER_VAR_1355[1] = ntt;____BAH_COMPILER_VAR_1355[0] = "Cannot send {TOKEN} (";char * ____BAH_COMPILER_VAR_1356 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1355, 5);throwErr(&nt,____BAH_COMPILER_VAR_1356);
}
char * ____BAH_COMPILER_VAR_1357 =string__str(&ptt);if (isRCPpointerType(____BAH_COMPILER_VAR_1357)) {
char** ____BAH_COMPILER_VAR_1358 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1358[4] = ");\n";____BAH_COMPILER_VAR_1358[3] = nt.cont;____BAH_COMPILER_VAR_1358[2] = ", ";____BAH_COMPILER_VAR_1358[1] = pt.cont;____BAH_COMPILER_VAR_1358[0] = "channel__send(";char * ____BAH_COMPILER_VAR_1359 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1358, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1359));
}
else {
struct string ct = getCType(ntt,elems);
char * tmpV = genCompilerVar();
char** ____BAH_COMPILER_VAR_1360 = alloca(13 * sizeof(char*));____BAH_COMPILER_VAR_1360[12] = "));\n        ";____BAH_COMPILER_VAR_1360[11] = tmpV;____BAH_COMPILER_VAR_1360[10] = ", sizeof(";____BAH_COMPILER_VAR_1360[9] = tmpV;____BAH_COMPILER_VAR_1360[8] = ", &";____BAH_COMPILER_VAR_1360[7] = pt.cont;____BAH_COMPILER_VAR_1360[6] = ";\n        channel__sendAny(";____BAH_COMPILER_VAR_1360[5] = nt.cont;____BAH_COMPILER_VAR_1360[4] = " = ";____BAH_COMPILER_VAR_1360[3] = tmpV;____BAH_COMPILER_VAR_1360[2] = " ";____BAH_COMPILER_VAR_1360[1] = string__str(&ct);____BAH_COMPILER_VAR_1360[0] = "\n        ";char * ____BAH_COMPILER_VAR_1361 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1360, 13);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1361));
}
return posTok;
};
long int valueChan(__BAH_ARR_TYPE_Tok l,long int i,struct Elems* elems){
long int posTok = i-1;
delete(l,posTok);
struct Tok nt = l->data[posTok];
char * ____BAH_COMPILER_VAR_1362 =getTypeFromToken(&nt,true,elems);struct string ntt = string(____BAH_COMPILER_VAR_1362);
if (__builtin_expect((string__hasPrefix(&ntt,"chan:")==0), 0)) {
char** ____BAH_COMPILER_VAR_1363 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1363[2] = ") as chan.";____BAH_COMPILER_VAR_1363[1] = string__str(&ntt);____BAH_COMPILER_VAR_1363[0] = "Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_1364 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1363, 3);throwErr(&nt,____BAH_COMPILER_VAR_1364);
}
string__trimLeft(&ntt,5);
if (__builtin_expect(isGlobal(), 0)) {
throwErr(&nt,"Cannot receive from chan {TOKEN} outside a function body.");
}
char * ____BAH_COMPILER_VAR_1365 =string__str(&ntt);struct string ct = getCType(____BAH_COMPILER_VAR_1365,elems);
char * ____BAH_COMPILER_VAR_1366 =string__str(&ntt);if (isRCPpointerType(____BAH_COMPILER_VAR_1366)) {
char** ____BAH_COMPILER_VAR_1367 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1367[2] = ")";____BAH_COMPILER_VAR_1367[1] = nt.cont;____BAH_COMPILER_VAR_1367[0] = "channel__receive(";char * ____BAH_COMPILER_VAR_1368 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1367, 3);char * ____BAH_COMPILER_VAR_1369 =string__str(&ntt);char * tmpV = registerRCPvar(____BAH_COMPILER_VAR_1369,____BAH_COMPILER_VAR_1368,elems);
nt.cont = tmpV;
}
else {
if (RCPavailable()) {
char** ____BAH_COMPILER_VAR_1370 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1370[1] = "*";____BAH_COMPILER_VAR_1370[0] = string__str(&ntt);char * ____BAH_COMPILER_VAR_1371 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1370, 2);char** ____BAH_COMPILER_VAR_1372 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1372[4] = ")";____BAH_COMPILER_VAR_1372[3] = nt.cont;____BAH_COMPILER_VAR_1372[2] = "*)channel__receive(";____BAH_COMPILER_VAR_1372[1] = string__str(&ct);____BAH_COMPILER_VAR_1372[0] = "(";char * ____BAH_COMPILER_VAR_1373 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1372, 5);char * tmpV = registerRCPvar(____BAH_COMPILER_VAR_1371,____BAH_COMPILER_VAR_1373,elems);
char** ____BAH_COMPILER_VAR_1374 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1374[1] = tmpV;____BAH_COMPILER_VAR_1374[0] = "*";char * ____BAH_COMPILER_VAR_1375 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1374, 2);nt.cont = ____BAH_COMPILER_VAR_1375;
}
else {
char** ____BAH_COMPILER_VAR_1376 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1376[4] = ")";____BAH_COMPILER_VAR_1376[3] = nt.cont;____BAH_COMPILER_VAR_1376[2] = "*)channel__receive(";____BAH_COMPILER_VAR_1376[1] = string__str(&ct);____BAH_COMPILER_VAR_1376[0] = "*(";char * ____BAH_COMPILER_VAR_1377 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1376, 5);nt.cont = ____BAH_COMPILER_VAR_1377;
}
}
nt.type = TOKEN_TYPE_FUNC;
nt.isFunc = true;
nt.isValue = true;
nt.bahType = string__str(&ntt);

    unsigned int ____BAH_COMPILER_VAR_1378 = posTok;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1378);
    l->data[____BAH_COMPILER_VAR_1378] = nt;
return posTok;
};
long int valueTuple(__BAH_ARR_TYPE_Tok l,long int i,struct Elems* elems){
long int tokPos = i;
long int nbBracks = 0;
if (__builtin_expect((strcmp(l->data[tokPos+1].cont, "]") == 0), 0)) {
if ((l->data[tokPos+2].type==TOKEN_TYPE_VAR)) {
return tokPos+1;
}
throwErr(&l->data[tokPos],"Cannot declare {TOKEN} empty tuple.");
}
array(char *)* vals = memoryAlloc(sizeof(array(char *)));

vals->length = 0;
vals->elemSize = sizeof(char *);
long int nbEncl = 1;
++i;
for (; (i<len(l)); ++i) {
if ((strcmp(l->data[i].cont, "[") == 0)||(strcmp(l->data[i].cont, "(") == 0)) {
++nbEncl;
}
else if ((strcmp(l->data[1].cont, "]") == 0)||(strcmp(l->data[i].cont, ")") == 0)) {
--nbEncl;
if ((nbEncl==0)) {
break;
}
}
};
array(struct Tok)* memory = arraySubstitute(l, tokPos+1, i);
debugLine(memory);
memory = prePross(memory,(lineType)-1,elems);
struct Tok ft = memory->data[0];
char * tupT = getTypeFromToken(&ft,true,elems);
register long int j = 0;
for (; (j<len(memory)); j = j+2) {
struct Tok t = memory->data[j];
char * tt = getTypeFromToken(&t,true,elems);
if (__builtin_expect((compTypes(tupT,tt)==false), 0)) {
char** ____BAH_COMPILER_VAR_1379 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1379[4] = " in tuple declaration.";____BAH_COMPILER_VAR_1379[3] = tupT;____BAH_COMPILER_VAR_1379[2] = ") as ";____BAH_COMPILER_VAR_1379[1] = tt;____BAH_COMPILER_VAR_1379[0] = "Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_1380 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1379, 5);throwErr(&t,____BAH_COMPILER_VAR_1380);
}

    unsigned int ____BAH_COMPILER_VAR_1381 = len(vals);
    __Bah_realocate_arr(vals, ____BAH_COMPILER_VAR_1381);
    vals->data[____BAH_COMPILER_VAR_1381] = t.cont;
struct Tok nt = memory->data[j+1];
if ((strcmp(nt.cont, "]") == 0)) {
break;
}
else if (__builtin_expect((strcmp(nt.cont, ",") != 0), 0)) {
throwErr(&nt,"Expected separator between values in tuple declaration, got {TOKEN}.");
}
};
char** ____BAH_COMPILER_VAR_1382 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1382[3] = tupT;____BAH_COMPILER_VAR_1382[2] = ":";____BAH_COMPILER_VAR_1382[1] = intToStr(len(vals));____BAH_COMPILER_VAR_1382[0] = "tuple:";char * ____BAH_COMPILER_VAR_1383 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1382, 4);char * type = ____BAH_COMPILER_VAR_1383;
deleteRange(l,tokPos+1,j+1);

                struct string ____BAH_COMPILER_VAR_1384 = getCType(tupT,elems);
                char** ____BAH_COMPILER_VAR_1385 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1385[4] = ")";____BAH_COMPILER_VAR_1385[3] = intToStr(len(vals));____BAH_COMPILER_VAR_1385[2] = ") * ";____BAH_COMPILER_VAR_1385[1] = string__str(&____BAH_COMPILER_VAR_1384);____BAH_COMPILER_VAR_1385[0] = "alloca(sizeof(";char * ____BAH_COMPILER_VAR_1386 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1385, 5);char * v = registerRCPvar(type,____BAH_COMPILER_VAR_1386,elems);
char * r = "";
i = 0;
for (; (i<len(vals)); ++i) {
char** ____BAH_COMPILER_VAR_1387 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_1387[5] = ";";____BAH_COMPILER_VAR_1387[4] = vals->data[i];____BAH_COMPILER_VAR_1387[3] = "] = ";____BAH_COMPILER_VAR_1387[2] = intToStr(i);____BAH_COMPILER_VAR_1387[1] = "[";____BAH_COMPILER_VAR_1387[0] = v;char * ____BAH_COMPILER_VAR_1388 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1387, 6);char** ____BAH_COMPILER_VAR_1389 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1389[1] = ____BAH_COMPILER_VAR_1388;____BAH_COMPILER_VAR_1389[0] = r;char * ____BAH_COMPILER_VAR_1390 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1389, 2);r = ____BAH_COMPILER_VAR_1390;
};
if (isGlobal()) {
INIT = rope__add(INIT, rope(r));
}
else {
OUTPUT = rope__add(OUTPUT, rope(r));
}
struct Tok ____BAH_COMPILER_VAR_1391 = {};
____BAH_COMPILER_VAR_1391.cont = "";
____BAH_COMPILER_VAR_1391.ogCont = "";
____BAH_COMPILER_VAR_1391.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1391.line = 1;
____BAH_COMPILER_VAR_1391.begLine = 1;
____BAH_COMPILER_VAR_1391.bahType = "";
____BAH_COMPILER_VAR_1391.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_1391.bahType = type;
____BAH_COMPILER_VAR_1391.cont = v;

    unsigned int ____BAH_COMPILER_VAR_1392 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1392);
    l->data[____BAH_COMPILER_VAR_1392] = ____BAH_COMPILER_VAR_1391;
return tokPos;
};
char isSmallValue(__BAH_ARR_TYPE_Tok l,long int i){
struct Tok t = l->data[i];
if ((t.type==TOKEN_TYPE_CAST)||(strcmp(t.cont, "(") == 0)) {
return false;
}
else if (__builtin_expect((t.isValue==false), 0)) {
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
else if (__builtin_expect((t.isValue==false), 0)) {
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
struct Tok ____BAH_COMPILER_VAR_1393 = {};
____BAH_COMPILER_VAR_1393.cont = "";
____BAH_COMPILER_VAR_1393.ogCont = "";
____BAH_COMPILER_VAR_1393.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1393.line = 1;
____BAH_COMPILER_VAR_1393.begLine = 1;
____BAH_COMPILER_VAR_1393.bahType = "";
struct Tok pt = ____BAH_COMPILER_VAR_1393;
long int l = len(fl);
i = 0;
for (; (i<len(fl)); ++i) {
struct Tok t = fl->data[i];
if ((t.type==TOKEN_TYPE_VAR)&&(t.isOper==false)&&(t.cont[0]==38)) {
struct string tc = string(t.cont);
string__trimLeft(&tc,1);
char * ____BAH_COMPILER_VAR_1394 =string__str(&tc);struct variable* rv = getRealVar(____BAH_COMPILER_VAR_1394,elems);
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
struct Tok ____BAH_COMPILER_VAR_1395 = {};
____BAH_COMPILER_VAR_1395.cont = "";
____BAH_COMPILER_VAR_1395.ogCont = "";
____BAH_COMPILER_VAR_1395.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1395.line = 1;
____BAH_COMPILER_VAR_1395.begLine = 1;
____BAH_COMPILER_VAR_1395.bahType = "";
pt = ____BAH_COMPILER_VAR_1395;
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
else if ((strcmp(t.cont, "[") == 0)) {
i = valueTuple(fl,i,elems)-1;
}
else if ((pt.type==TOKEN_TYPE_CAST)&&isSmallValue(fl,i)) {
delete(fl,i-1);
struct string ptc = string(pt.cont);
string__trimLeft(&ptc,1);
string__trimRight(&ptc,1);
t.bahType = string__str(&ptc);
char * ____BAH_COMPILER_VAR_1396 =string__str(&ptc);struct string cType = getCType(____BAH_COMPILER_VAR_1396,elems);
char** ____BAH_COMPILER_VAR_1397 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1397[3] = t.cont;____BAH_COMPILER_VAR_1397[2] = ")";____BAH_COMPILER_VAR_1397[1] = string__str(&cType);____BAH_COMPILER_VAR_1397[0] = "(";char * ____BAH_COMPILER_VAR_1398 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1397, 4);t.cont = ____BAH_COMPILER_VAR_1398;

    unsigned int ____BAH_COMPILER_VAR_1399 = i-1;
    __Bah_realocate_arr(fl, ____BAH_COMPILER_VAR_1399);
    fl->data[____BAH_COMPILER_VAR_1399] = t;
i = i-2;
}
else if (inArrayStr(pt.cont,signs)) {
if ((strcmp(t.cont, pt.cont) == 0)&&(i>1)) {
struct Tok ppt = fl->data[i-2];
if ((ppt.type==TOKEN_TYPE_VAR)) {
long int posTok = i-2;
deleteRange(fl,i-1,i);
char** ____BAH_COMPILER_VAR_1400 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1400[2] = ppt.cont;____BAH_COMPILER_VAR_1400[1] = t.cont;____BAH_COMPILER_VAR_1400[0] = t.cont;char * ____BAH_COMPILER_VAR_1401 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1400, 3);ppt.cont = ____BAH_COMPILER_VAR_1401;
ppt.isValue = true;
ppt.isOper = true;

    unsigned int ____BAH_COMPILER_VAR_1402 = posTok;
    __Bah_realocate_arr(fl, ____BAH_COMPILER_VAR_1402);
    fl->data[____BAH_COMPILER_VAR_1402] = ppt;
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
if ((t.type==TOKEN_TYPE_INT)+(t.type==TOKEN_TYPE_FLOAT)) {
delete(fl,i);
char * ptt = getTypeFromToken(&pt,true,elems);
pt.bahType = ptt;
pt.isOper = true;
char** ____BAH_COMPILER_VAR_1403 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1403[1] = t.cont;____BAH_COMPILER_VAR_1403[0] = pt.cont;char * ____BAH_COMPILER_VAR_1404 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1403, 2);pt.cont = ____BAH_COMPILER_VAR_1404;

    unsigned int ____BAH_COMPILER_VAR_1405 = i-1;
    __Bah_realocate_arr(fl, ____BAH_COMPILER_VAR_1405);
    fl->data[____BAH_COMPILER_VAR_1405] = pt;
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
if (__builtin_expect((i==0)||(i+1==len(fl)), 0)) {
throwErr(&t,"Cannot use {TOKEN} on nothing.");
}
pt = fl->data[i-1];
struct Tok nt = fl->data[i+1];
char * ptt = getTypeFromToken(&pt,true,elems);
char * ntt = getTypeFromToken(&nt,true,elems);
if (__builtin_expect((compTypes(ptt,ntt)==false)||(compTypes(ptt,"bool")==false), 0)) {
char** ____BAH_COMPILER_VAR_1406 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1406[2] = ".";____BAH_COMPILER_VAR_1406[1] = ptt;____BAH_COMPILER_VAR_1406[0] = "Cannot use {TOKEN} on ";char * ____BAH_COMPILER_VAR_1407 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1406, 3);throwErr(&t,____BAH_COMPILER_VAR_1407);
}
if ((strcmp(t.cont, "||") == 0)&&(isExprExpensive(&pt)==false)&&(isExprExpensive(&nt)==false)) {
char** ____BAH_COMPILER_VAR_1408 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1408[1] = nt.cont;____BAH_COMPILER_VAR_1408[0] = "+";char * ____BAH_COMPILER_VAR_1409 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1408, 2);char** ____BAH_COMPILER_VAR_1410 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1410[1] = ____BAH_COMPILER_VAR_1409;____BAH_COMPILER_VAR_1410[0] = pt.cont;char * ____BAH_COMPILER_VAR_1411 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1410, 2);pt.cont = ____BAH_COMPILER_VAR_1411;
}
else {
char** ____BAH_COMPILER_VAR_1412 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1412[1] = nt.cont;____BAH_COMPILER_VAR_1412[0] = t.cont;char * ____BAH_COMPILER_VAR_1413 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1412, 2);char** ____BAH_COMPILER_VAR_1414 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1414[1] = ____BAH_COMPILER_VAR_1413;____BAH_COMPILER_VAR_1414[0] = pt.cont;char * ____BAH_COMPILER_VAR_1415 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1414, 2);pt.cont = ____BAH_COMPILER_VAR_1415;
}

    unsigned int ____BAH_COMPILER_VAR_1416 = i-1;
    __Bah_realocate_arr(fl, ____BAH_COMPILER_VAR_1416);
    fl->data[____BAH_COMPILER_VAR_1416] = pt;
deleteRange(fl,i,i+1);
i = i-2;
}
else if ((t.type==TOKEN_TYPE_VAR)&&(strcmp(t.bahType, "") != 0)) {
if ((t.cont[0]==38)) {

                struct string ____BAH_COMPILER_VAR_1417 = string(t.bahType);
                if (__builtin_expect(string__hasPrefix(&____BAH_COMPILER_VAR_1417,"tuple:"), 0)) {
throwErr(&t,"Cannot get pointer of a tuple {TOKEN}.");
}
char** ____BAH_COMPILER_VAR_1418 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1418[1] = "*";____BAH_COMPILER_VAR_1418[0] = t.bahType;char * ____BAH_COMPILER_VAR_1419 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1418, 2);t.bahType = ____BAH_COMPILER_VAR_1419;

    unsigned int ____BAH_COMPILER_VAR_1420 = i;
    __Bah_realocate_arr(fl, ____BAH_COMPILER_VAR_1420);
    fl->data[____BAH_COMPILER_VAR_1420] = t;
}
else if ((t.cont[0]==42)) {
struct string tt = string(t.bahType);
string__replace(&tt,"*","");
t.bahType = string__str(&tt);

    unsigned int ____BAH_COMPILER_VAR_1421 = i;
    __Bah_realocate_arr(fl, ____BAH_COMPILER_VAR_1421);
    fl->data[____BAH_COMPILER_VAR_1421] = t;
}
}
else if ((t.type==TOKEN_TYPE_VAR)&&(t.cont[0]==38)) {
char * tt = getTypeFromToken(&t,true,elems);

                struct string ____BAH_COMPILER_VAR_1422 = string(tt);
                if (__builtin_expect(string__hasPrefix(&____BAH_COMPILER_VAR_1422,"tuple:"), 0)) {
throwErr(&t,"Cannot get pointer of a tuple {TOKEN}.");
}
}
};
fl = parseArrayType(fl,elems,true);
if ((RCPavailable()==true)) {
addRCPvars(fl,ltp,elems);
}
if ((ltp!=(lineType)-1)) {
while ((sepI<len(line))) {

    unsigned int ____BAH_COMPILER_VAR_1423 = len(fl);
    __Bah_realocate_arr(fl, ____BAH_COMPILER_VAR_1423);
    fl->data[____BAH_COMPILER_VAR_1423] = line->data[sepI];
++sepI;
};
}
return fl;
};
void parseFnDeclare(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
long int i = 0;
struct func* ____BAH_COMPILER_VAR_1424 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_1424->name = "";
____BAH_COMPILER_VAR_1424->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_1424->args->length = 0;
            ____BAH_COMPILER_VAR_1424->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_1424->from = "";
____BAH_COMPILER_VAR_1424->file = "";
____BAH_COMPILER_VAR_1424->line = 1;
struct func* fn = ____BAH_COMPILER_VAR_1424;
if ((RCPavailable()==false)&&(RCPenabled==true)) {
fn->used = true;
}
struct Tok ft = l->data[0];
char * code = parseFnHeader("",l,&i,fn,elems);
fn->line = ft.line;
fn->file = compilerState.currentFile;
struct func* ogFn = searchFunc(fn->name,elems,false);
if ((ogFn!=null)) {
if (__builtin_expect((ogFn->isBinding==false), 0)) {
char * lineStr = intToStr(ogFn->line);
char** ____BAH_COMPILER_VAR_1425 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1425[4] = ".";____BAH_COMPILER_VAR_1425[3] = lineStr;____BAH_COMPILER_VAR_1425[2] = ":";____BAH_COMPILER_VAR_1425[1] = ogFn->file;____BAH_COMPILER_VAR_1425[0] = "Cannot redeclare function {TOKEN}, previous declaration: ";char * ____BAH_COMPILER_VAR_1426 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1425, 5);throwErr(&ft,____BAH_COMPILER_VAR_1426);
}
}
if ((strcmp(fn->name, "main") == 0)) {
compilerState.haveEntryPoint = true;
if (__builtin_expect((compTypes(fn->returns->type,"int")==false), 0)) {
throwErr(&ft,"{TOKEN} function should return 'int'.");
}
if (__builtin_expect((len(fn->args)!=1), 0)) {
throwErr(&ft,"{TOKEN} function should take one []cpstring argument. Should be: \n            'main(args []cpstring) int'");
}
struct variable* fa = fn->args->data[0];
if (__builtin_expect((compTypes(fa->type,"[]cpstring")==false), 0)) {
throwErr(&ft,"{TOKEN} function should take []cpstring as argument. Should be: \n            'main(args []cpstring) int'");
}
}
if ((debug==true)) {
struct debugFunction* ____BAH_COMPILER_VAR_1427 = memoryAlloc(sizeof(struct debugFunction));
____BAH_COMPILER_VAR_1427->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_1427->args->length = 0;
            ____BAH_COMPILER_VAR_1427->args->elemSize = sizeof(struct variable*);
            struct debugFunction* df = ____BAH_COMPILER_VAR_1427;
df->name = fn->name;
df->args = fn->args;
df->returns = fn->returns->type;
struct debugFunction* ____BAH_COMPILER_VAR_1428 = df;
char ** ____BAH_COMPILER_VAR_1430 = (char **)((char*)(____BAH_COMPILER_VAR_1428) + offsetof(struct debugFunction, name));
struct reflectElement ____BAH_COMPILER_VAR_1431 = __reflect(____BAH_COMPILER_VAR_1430, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct debugFunction, name));
char ** ____BAH_COMPILER_VAR_1432 = (char **)((char*)(____BAH_COMPILER_VAR_1428) + offsetof(struct debugFunction, returns));
struct reflectElement ____BAH_COMPILER_VAR_1433 = __reflect(____BAH_COMPILER_VAR_1432, sizeof(char *), "cpstring", "returns", 0, 0, 0, 0, offsetof(struct debugFunction, returns));
array(struct variable*)** ____BAH_COMPILER_VAR_1434 = (array(struct variable*)**)((char*)(____BAH_COMPILER_VAR_1428) + offsetof(struct debugFunction, args));
struct variable** ____BAH_COMPILER_VAR_1435 = 0;
char ** ____BAH_COMPILER_VAR_1437 = (char **)((char*)(____BAH_COMPILER_VAR_1435) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_1438 = __reflect(____BAH_COMPILER_VAR_1437, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_1439 = (char **)((char*)(____BAH_COMPILER_VAR_1435) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_1440 = __reflect(____BAH_COMPILER_VAR_1439, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_1441 = (char*)((char*)(____BAH_COMPILER_VAR_1435) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_1442 = __reflect(____BAH_COMPILER_VAR_1441, sizeof(char), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_1443 = (char **)((char*)(____BAH_COMPILER_VAR_1435) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_1444 = __reflect(____BAH_COMPILER_VAR_1443, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_1445 = (char*)((char*)(____BAH_COMPILER_VAR_1435) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_1446 = __reflect(____BAH_COMPILER_VAR_1445, sizeof(char), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_1447 = (char **)((char*)(____BAH_COMPILER_VAR_1435) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_1448 = __reflect(____BAH_COMPILER_VAR_1447, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
void ** ____BAH_COMPILER_VAR_1449 = (void **)((char*)(____BAH_COMPILER_VAR_1435) + offsetof(struct variable, declScope));
struct reflectElement ____BAH_COMPILER_VAR_1450 = __reflect(____BAH_COMPILER_VAR_1449, sizeof(void *), "ptr", "declScope", 0, 0, 0, 0, offsetof(struct variable, declScope));
char* ____BAH_COMPILER_VAR_1451 = (char*)((char*)(____BAH_COMPILER_VAR_1435) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_1452 = __reflect(____BAH_COMPILER_VAR_1451, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));
struct rope** ____BAH_COMPILER_VAR_1453 = (struct rope**)((char*)(____BAH_COMPILER_VAR_1435) + offsetof(struct variable, declRope));
void ** ____BAH_COMPILER_VAR_1455 = (void **)((char*)(____BAH_COMPILER_VAR_1453) + offsetof(struct rope, left));
struct reflectElement ____BAH_COMPILER_VAR_1456 = __reflect(____BAH_COMPILER_VAR_1455, sizeof(void *), "ptr", "left", 0, 0, 0, 0, offsetof(struct rope, left));
void ** ____BAH_COMPILER_VAR_1457 = (void **)((char*)(____BAH_COMPILER_VAR_1453) + offsetof(struct rope, right));
struct reflectElement ____BAH_COMPILER_VAR_1458 = __reflect(____BAH_COMPILER_VAR_1457, sizeof(void *), "ptr", "right", 0, 0, 0, 0, offsetof(struct rope, right));
char ** ____BAH_COMPILER_VAR_1459 = (char **)((char*)(____BAH_COMPILER_VAR_1453) + offsetof(struct rope, str));
struct reflectElement ____BAH_COMPILER_VAR_1460 = __reflect(____BAH_COMPILER_VAR_1459, sizeof(char *), "cpstring", "str", 0, 0, 0, 0, offsetof(struct rope, str));
int* ____BAH_COMPILER_VAR_1461 = (int*)((char*)(____BAH_COMPILER_VAR_1453) + offsetof(struct rope, lCount));
struct reflectElement ____BAH_COMPILER_VAR_1462 = __reflect(____BAH_COMPILER_VAR_1461, sizeof(int), "int32", "lCount", 0, 0, 0, 0, offsetof(struct rope, lCount));
int* ____BAH_COMPILER_VAR_1463 = (int*)((char*)(____BAH_COMPILER_VAR_1453) + offsetof(struct rope, len));
struct reflectElement ____BAH_COMPILER_VAR_1464 = __reflect(____BAH_COMPILER_VAR_1463, sizeof(int), "int32", "len", 0, 0, 0, 0, offsetof(struct rope, len));
int* ____BAH_COMPILER_VAR_1465 = (int*)((char*)(____BAH_COMPILER_VAR_1453) + offsetof(struct rope, totalLen));
struct reflectElement ____BAH_COMPILER_VAR_1466 = __reflect(____BAH_COMPILER_VAR_1465, sizeof(int), "int32", "totalLen", 0, 0, 0, 0, offsetof(struct rope, totalLen));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_1454 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_1454->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_1454->length = 6;
        ____BAH_COMPILER_VAR_1454->data = memoryAlloc(____BAH_COMPILER_VAR_1454->length * ____BAH_COMPILER_VAR_1454->elemSize);
        ____BAH_COMPILER_VAR_1454->data[0] = ____BAH_COMPILER_VAR_1456;
____BAH_COMPILER_VAR_1454->data[1] = ____BAH_COMPILER_VAR_1458;
____BAH_COMPILER_VAR_1454->data[2] = ____BAH_COMPILER_VAR_1460;
____BAH_COMPILER_VAR_1454->data[3] = ____BAH_COMPILER_VAR_1462;
____BAH_COMPILER_VAR_1454->data[4] = ____BAH_COMPILER_VAR_1464;
____BAH_COMPILER_VAR_1454->data[5] = ____BAH_COMPILER_VAR_1466;
struct reflectElement ____BAH_COMPILER_VAR_1467 = __reflect(____BAH_COMPILER_VAR_1453, sizeof(struct rope), "rope*", "declRope", 0, 0, 1, ____BAH_COMPILER_VAR_1454, offsetof(struct variable, declRope));
char* ____BAH_COMPILER_VAR_1468 = (char*)((char*)(____BAH_COMPILER_VAR_1435) + offsetof(struct variable, canBeNull));
struct reflectElement ____BAH_COMPILER_VAR_1469 = __reflect(____BAH_COMPILER_VAR_1468, sizeof(char), "bool", "canBeNull", 0, 0, 0, 0, offsetof(struct variable, canBeNull));
char* ____BAH_COMPILER_VAR_1470 = (char*)((char*)(____BAH_COMPILER_VAR_1435) + offsetof(struct variable, canBeReg));
struct reflectElement ____BAH_COMPILER_VAR_1471 = __reflect(____BAH_COMPILER_VAR_1470, sizeof(char), "bool", "canBeReg", 0, 0, 0, 0, offsetof(struct variable, canBeReg));
char* ____BAH_COMPILER_VAR_1472 = (char*)((char*)(____BAH_COMPILER_VAR_1435) + offsetof(struct variable, isReg));
struct reflectElement ____BAH_COMPILER_VAR_1473 = __reflect(____BAH_COMPILER_VAR_1472, sizeof(char), "bool", "isReg", 0, 0, 0, 0, offsetof(struct variable, isReg));
void ** ____BAH_COMPILER_VAR_1474 = (void **)((char*)(____BAH_COMPILER_VAR_1435) + offsetof(struct variable, lastSet));
struct reflectElement ____BAH_COMPILER_VAR_1475 = __reflect(____BAH_COMPILER_VAR_1474, sizeof(void *), "ptr", "lastSet", 0, 0, 0, 0, offsetof(struct variable, lastSet));
char* ____BAH_COMPILER_VAR_1476 = (char*)((char*)(____BAH_COMPILER_VAR_1435) + offsetof(struct variable, isArg));
struct reflectElement ____BAH_COMPILER_VAR_1477 = __reflect(____BAH_COMPILER_VAR_1476, sizeof(char), "bool", "isArg", 0, 0, 0, 0, offsetof(struct variable, isArg));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_1436 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_1436->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_1436->length = 14;
        ____BAH_COMPILER_VAR_1436->data = memoryAlloc(____BAH_COMPILER_VAR_1436->length * ____BAH_COMPILER_VAR_1436->elemSize);
        ____BAH_COMPILER_VAR_1436->data[0] = ____BAH_COMPILER_VAR_1438;
____BAH_COMPILER_VAR_1436->data[1] = ____BAH_COMPILER_VAR_1440;
____BAH_COMPILER_VAR_1436->data[2] = ____BAH_COMPILER_VAR_1442;
____BAH_COMPILER_VAR_1436->data[3] = ____BAH_COMPILER_VAR_1444;
____BAH_COMPILER_VAR_1436->data[4] = ____BAH_COMPILER_VAR_1446;
____BAH_COMPILER_VAR_1436->data[5] = ____BAH_COMPILER_VAR_1448;
____BAH_COMPILER_VAR_1436->data[6] = ____BAH_COMPILER_VAR_1450;
____BAH_COMPILER_VAR_1436->data[7] = ____BAH_COMPILER_VAR_1452;
____BAH_COMPILER_VAR_1436->data[8] = ____BAH_COMPILER_VAR_1467;
____BAH_COMPILER_VAR_1436->data[9] = ____BAH_COMPILER_VAR_1469;
____BAH_COMPILER_VAR_1436->data[10] = ____BAH_COMPILER_VAR_1471;
____BAH_COMPILER_VAR_1436->data[11] = ____BAH_COMPILER_VAR_1473;
____BAH_COMPILER_VAR_1436->data[12] = ____BAH_COMPILER_VAR_1475;
____BAH_COMPILER_VAR_1436->data[13] = ____BAH_COMPILER_VAR_1477;
struct reflectElement ____BAH_COMPILER_VAR_1478 = __reflect(____BAH_COMPILER_VAR_1435, sizeof(struct variable), "variable*", "", 0, 0, 1, ____BAH_COMPILER_VAR_1436, 0);

        struct reflectElement ____BAH_COMPILER_VAR_1479 = ____BAH_COMPILER_VAR_1478;
        struct reflectElement ____BAH_COMPILER_VAR_1480 = __reflect(____BAH_COMPILER_VAR_1434, sizeof(array(struct variable*)*), "[]variable*", "args", 1, &____BAH_COMPILER_VAR_1479, 0, 0, offsetof(struct debugFunction, args));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_1429 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_1429->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_1429->length = 3;
        ____BAH_COMPILER_VAR_1429->data = memoryAlloc(____BAH_COMPILER_VAR_1429->length * ____BAH_COMPILER_VAR_1429->elemSize);
        ____BAH_COMPILER_VAR_1429->data[0] = ____BAH_COMPILER_VAR_1431;
____BAH_COMPILER_VAR_1429->data[1] = ____BAH_COMPILER_VAR_1433;
____BAH_COMPILER_VAR_1429->data[2] = ____BAH_COMPILER_VAR_1480;
struct reflectElement ____BAH_COMPILER_VAR_1481 = __reflect(____BAH_COMPILER_VAR_1428, sizeof(struct debugFunction), "debugFunction*", "df", 0, 0, 1, ____BAH_COMPILER_VAR_1429, 0);
debugPrint("fn_declare",ft.line,____BAH_COMPILER_VAR_1481);
}
register long int j = 0;
for (; (j<len(fn->args)); ++j) {
if ((strcmp(fn->args->data[j]->type, "<any>") == 0)) {
struct genericFunc* ____BAH_COMPILER_VAR_1482 = memoryAlloc(sizeof(struct genericFunc));
____BAH_COMPILER_VAR_1482->tokens = memoryAlloc(sizeof(array(struct Tok)));
            ____BAH_COMPILER_VAR_1482->tokens->length = 0;
            ____BAH_COMPILER_VAR_1482->tokens->elemSize = sizeof(struct Tok);
            ____BAH_COMPILER_VAR_1482->declared = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_1482->declared->length = 0;
            ____BAH_COMPILER_VAR_1482->declared->elemSize = sizeof(struct func*);
            ____BAH_COMPILER_VAR_1482->tokens = arraySubstitute(l, i+1, len(l)-1);
____BAH_COMPILER_VAR_1482->baseFn = fn;
____BAH_COMPILER_VAR_1482->tokenName = &ft;

    unsigned int ____BAH_COMPILER_VAR_1483 = len(generics);
    __Bah_realocate_arr(generics, ____BAH_COMPILER_VAR_1483);
    generics->data[____BAH_COMPILER_VAR_1483] = ____BAH_COMPILER_VAR_1482;
return;
}
};
if ((shouldOnlyDecl==true)) {
if ((ogFn!=null)) {
fn->isBinding = false;
}
fn->isImported = true;

    unsigned int ____BAH_COMPILER_VAR_1484 = len(elems->fns);
    __Bah_realocate_arr(elems->fns, ____BAH_COMPILER_VAR_1484);
    elems->fns->data[____BAH_COMPILER_VAR_1484] = fn;
char** ____BAH_COMPILER_VAR_1485 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1485[1] = ";\n";____BAH_COMPILER_VAR_1485[0] = code;char * ____BAH_COMPILER_VAR_1486 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1485, 2);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1486));
return;
}
postDeclHandle = rope("");
OUTPUT = rope__add(OUTPUT, postDeclHandle);
char** ____BAH_COMPILER_VAR_1487 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1487[1] = "{\n";____BAH_COMPILER_VAR_1487[0] = code;char * ____BAH_COMPILER_VAR_1488 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1487, 2);code = ____BAH_COMPILER_VAR_1488;
fn->code = rope(code);
struct Elems* fnElems = dupElems(elems);
array(struct variable*)* vs = fnElems->vars;
j = 0;
while ((j<len(fn->args))) {
struct variable* a = fn->args->data[j];
a->declScope = elems;
a->isArg = true;

    unsigned int ____BAH_COMPILER_VAR_1489 = len(vs);
    __Bah_realocate_arr(vs, ____BAH_COMPILER_VAR_1489);
    vs->data[____BAH_COMPILER_VAR_1489] = a;
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

    unsigned int ____BAH_COMPILER_VAR_1490 = len(fns);
    __Bah_realocate_arr(fns, ____BAH_COMPILER_VAR_1490);
    fns->data[____BAH_COMPILER_VAR_1490] = fn;
}
++i;
array(struct Tok)* tokens = arraySubstitute(l, i, len(l)-1);
if ((len(tokens)==0)) {
fn->code = rope__add(fn->code, rope("};\n"));
OUTPUT = rope__add(OUTPUT, fn->code);
return;
}
currentFn = fn;
struct rope* oOut = OUTPUT;
OUTPUT = rope("");
beginRCPscope(fnElems,fn->args);
struct Elems* ocurrFnElems = compilerState.currFnElems;
compilerState.currFnElems = fnElems;
parseLines(tokens,fnElems);
OPTI_checkFuncScopeRef(fnElems);
compilerState.currFnElems = ocurrFnElems;
currentFn = null;
if ((fn->returned==false)) {
if (__builtin_expect((strlen(fn->returns->type)>0), 0)) {
char** ____BAH_COMPILER_VAR_1491 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1491[2] = "' is not returned.";____BAH_COMPILER_VAR_1491[1] = fn->name;____BAH_COMPILER_VAR_1491[0] = "Function '";char * ____BAH_COMPILER_VAR_1492 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1491, 3);throwErr(&l->data[len(l)-1],____BAH_COMPILER_VAR_1492);
}
endRCPscope(fnElems,fn->args);
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
if (__builtin_expect((len(line)<7), 0)) {
throwErr(&line->data[0],"Invalid usage of {TOKEN} 'capture <var> = <maybe value> else {<code>}'");
}
struct Tok varTok = line->data[1];
struct Tok valTok = line->data[3];
char isThen = false;
if (__builtin_expect((varTok.type!=TOKEN_TYPE_VAR), 0)) {
throwErr(&varTok,"Cannot use {TOKEN} as variable.");
}
if (__builtin_expect((strcmp(line->data[2].cont, "=") != 0), 0)) {
throwErr(&line->data[2],"Expected '=' got {TOKEN}.");
}
char * valType = getTypeFromToken(&valTok,true,elems);
if (__builtin_expect((valType[strlen(valType)-1]!=33), 0)) {
char** ____BAH_COMPILER_VAR_1493 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1493[2] = ") as maybe value.";____BAH_COMPILER_VAR_1493[1] = valType;____BAH_COMPILER_VAR_1493[0] = "Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_1494 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1493, 3);throwErr(&valTok,____BAH_COMPILER_VAR_1494);
}
char** ____BAH_COMPILER_VAR_1495 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1495[1] = "*";____BAH_COMPILER_VAR_1495[0] = cpstringSubsitute(valType, 0, strlen(valType)-1);char * ____BAH_COMPILER_VAR_1496 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1495, 2);char * newType = ____BAH_COMPILER_VAR_1496;
if (__builtin_expect((strcmp(line->data[4].cont, "else") != 0)&&(strcmp(line->data[4].cont, "then") != 0), 0)) {
throwErr(&line->data[4],"Expected 'then' or 'else' got {TOKEN}.");
}
if ((strcmp(line->data[4].cont, "then") == 0)) {
isThen = true;
}
struct variable* v = searchVar(varTok.cont,elems);
char * code = "";
if ((v==null)) {
struct variable* ____BAH_COMPILER_VAR_1497 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1497->name = "";
____BAH_COMPILER_VAR_1497->type = "";
____BAH_COMPILER_VAR_1497->constVal = "";
____BAH_COMPILER_VAR_1497->from = "";
____BAH_COMPILER_VAR_1497->name = varTok.cont;
____BAH_COMPILER_VAR_1497->type = newType;
v = ____BAH_COMPILER_VAR_1497;

    unsigned int ____BAH_COMPILER_VAR_1498 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_1498);
    elems->vars->data[____BAH_COMPILER_VAR_1498] = v;

                struct string ____BAH_COMPILER_VAR_1499 = getCType(v->type,elems);
                char** ____BAH_COMPILER_VAR_1500 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1500[1] = " ";____BAH_COMPILER_VAR_1500[0] = string__str(&____BAH_COMPILER_VAR_1499);char * ____BAH_COMPILER_VAR_1501 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1500, 2);code = ____BAH_COMPILER_VAR_1501;
}
else {
if (__builtin_expect((strcmp(v->type, newType) != 0), 0)) {
char** ____BAH_COMPILER_VAR_1502 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1502[4] = ".";____BAH_COMPILER_VAR_1502[3] = newType;____BAH_COMPILER_VAR_1502[2] = ") as ";____BAH_COMPILER_VAR_1502[1] = v->type;____BAH_COMPILER_VAR_1502[0] = "Cannot use var {TOKEN} (";char * ____BAH_COMPILER_VAR_1503 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1502, 5);throwErr(&varTok,____BAH_COMPILER_VAR_1503);
}
}
char** ____BAH_COMPILER_VAR_1504 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1504[3] = ";";____BAH_COMPILER_VAR_1504[2] = valTok.cont;____BAH_COMPILER_VAR_1504[1] = " = ";____BAH_COMPILER_VAR_1504[0] = v->name;char * ____BAH_COMPILER_VAR_1505 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1504, 4);char** ____BAH_COMPILER_VAR_1506 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1506[1] = ____BAH_COMPILER_VAR_1505;____BAH_COMPILER_VAR_1506[0] = code;char * ____BAH_COMPILER_VAR_1507 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1506, 2);code = ____BAH_COMPILER_VAR_1507;
if ((isThen==true)) {
char** ____BAH_COMPILER_VAR_1508 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1508[2] = " != null) {";____BAH_COMPILER_VAR_1508[1] = v->name;____BAH_COMPILER_VAR_1508[0] = "if (";char * ____BAH_COMPILER_VAR_1509 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1508, 3);char** ____BAH_COMPILER_VAR_1510 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1510[1] = ____BAH_COMPILER_VAR_1509;____BAH_COMPILER_VAR_1510[0] = code;char * ____BAH_COMPILER_VAR_1511 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1510, 2);code = ____BAH_COMPILER_VAR_1511;
}
else {
char** ____BAH_COMPILER_VAR_1512 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1512[2] = " == null) {";____BAH_COMPILER_VAR_1512[1] = v->name;____BAH_COMPILER_VAR_1512[0] = "if (";char * ____BAH_COMPILER_VAR_1513 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1512, 3);char** ____BAH_COMPILER_VAR_1514 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1514[1] = ____BAH_COMPILER_VAR_1513;____BAH_COMPILER_VAR_1514[0] = code;char * ____BAH_COMPILER_VAR_1515 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1514, 2);code = ____BAH_COMPILER_VAR_1515;
}
OUTPUT = rope__add(OUTPUT, rope(code));
array(struct Tok)* tokens = arraySubstitute(line, 6, len(line)-1);
struct Elems* CaptElems = dupElems(elems);
parseLines(tokens,CaptElems);
if ((isThen==true)) {
OUTPUT = rope__add(OUTPUT, rope("}\n"));
}
else {
char** ____BAH_COMPILER_VAR_1516 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1516[4] = "\");}\n";____BAH_COMPILER_VAR_1516[3] = intToStr(line->data[0].line);____BAH_COMPILER_VAR_1516[2] = ":";____BAH_COMPILER_VAR_1516[1] = compilerState.currentFile;____BAH_COMPILER_VAR_1516[0] = "\n__BAH_panic(\"Undefined capture resolution.\", \"";char * ____BAH_COMPILER_VAR_1517 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1516, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1517));
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
char * ____BAH_COMPILER_VAR_1518 =registerRCPvar(fn->returns->type,ft.cont,elems);return;
}
}
if ((ltp==LINE_TYPE_VAR)) {
parsed = true;
parseVar(line,elems);
}
else if ((ltp==LINE_TYPE_FN_CALL)) {
if (__builtin_expect((len(line)>1), 0)) {
throwErr(&line->data[len(line)-1],"Not expecting {TOKEN} after function call.");
}
parsed = true;
char** ____BAH_COMPILER_VAR_1519 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1519[1] = ";\n";____BAH_COMPILER_VAR_1519[0] = ft.cont;char * ____BAH_COMPILER_VAR_1520 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1519, 2);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1520));
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
if (__builtin_expect((parsed==false), 0)) {
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

    unsigned int ____BAH_COMPILER_VAR_1521 = len(line);
    __Bah_realocate_arr(line, ____BAH_COMPILER_VAR_1521);
    line->data[____BAH_COMPILER_VAR_1521] = t;
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

    unsigned int ____BAH_COMPILER_VAR_1522 = len(line);
    __Bah_realocate_arr(line, ____BAH_COMPILER_VAR_1522);
    line->data[____BAH_COMPILER_VAR_1522] = t;
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
char** ____BAH_COMPILER_VAR_1523 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1523[3] = arg->name;____BAH_COMPILER_VAR_1523[2] = " ";____BAH_COMPILER_VAR_1523[1] = string__str(&ct);____BAH_COMPILER_VAR_1523[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_1524 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1523, 4);tmpfnArgsCType = ____BAH_COMPILER_VAR_1524;
j = j+1;
if ((j<len(fn->args))) {
char** ____BAH_COMPILER_VAR_1525 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1525[1] = ", ";____BAH_COMPILER_VAR_1525[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_1526 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1525, 2);tmpfnArgsCType = ____BAH_COMPILER_VAR_1526;
}
};
char** ____BAH_COMPILER_VAR_1527 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_1527[5] = ");\n";____BAH_COMPILER_VAR_1527[4] = tmpfnArgsCType;____BAH_COMPILER_VAR_1527[3] = "(";____BAH_COMPILER_VAR_1527[2] = fn->name;____BAH_COMPILER_VAR_1527[1] = " ";____BAH_COMPILER_VAR_1527[0] = string__str(&tmpfnRetCType);char * ____BAH_COMPILER_VAR_1528 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1527, 6);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1528));
};
void declareVar(struct variable* v,struct Elems* elems){
if ((v->isConst==true)) {
char** ____BAH_COMPILER_VAR_1529 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1529[4] = "\n";____BAH_COMPILER_VAR_1529[3] = v->constVal;____BAH_COMPILER_VAR_1529[2] = " ";____BAH_COMPILER_VAR_1529[1] = v->name;____BAH_COMPILER_VAR_1529[0] = "#define ";char * ____BAH_COMPILER_VAR_1530 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1529, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1530));
}
else {
struct string cType = getCType(v->type,elems);
char** ____BAH_COMPILER_VAR_1531 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1531[3] = ";\n";____BAH_COMPILER_VAR_1531[2] = v->name;____BAH_COMPILER_VAR_1531[1] = " ";____BAH_COMPILER_VAR_1531[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_1532 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1531, 4);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1532));
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
char** ____BAH_COMPILER_VAR_1533 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1533[2] = "\n";____BAH_COMPILER_VAR_1533[1] = compilerState.cIncludes->data[i];____BAH_COMPILER_VAR_1533[0] = "#include ";char * ____BAH_COMPILER_VAR_1534 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1533, 3);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1534));
};
i = 1;
for (; (i<len(compilerState.arrTypesDecl)); ++i) {
char * t = compilerState.arrTypesDecl->data[i];
struct string elemType = string(t);
string__trimLeft(&elemType,15);
char * ____BAH_COMPILER_VAR_1535 =string__str(&elemType);struct string elemCtype = getCType(____BAH_COMPILER_VAR_1535,elems);
char** ____BAH_COMPILER_VAR_1536 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1536[4] = ";\n";____BAH_COMPILER_VAR_1536[3] = t;____BAH_COMPILER_VAR_1536[2] = ")* ";____BAH_COMPILER_VAR_1536[1] = string__str(&elemCtype);____BAH_COMPILER_VAR_1536[0] = "typedef array(";char * ____BAH_COMPILER_VAR_1537 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1536, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1537));
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
char** ____BAH_COMPILER_VAR_1538 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1538[1] = compilerState.currentFile;____BAH_COMPILER_VAR_1538[0] = "file: ";char * ____BAH_COMPILER_VAR_1539 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1538, 2);char * r = ____BAH_COMPILER_VAR_1539;
if ((currentFn!=null)) {
char** ____BAH_COMPILER_VAR_1540 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1540[2] = "()";____BAH_COMPILER_VAR_1540[1] = currentFn->name;____BAH_COMPILER_VAR_1540[0] = "\nfunction: ";char * ____BAH_COMPILER_VAR_1541 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1540, 3);char** ____BAH_COMPILER_VAR_1542 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1542[1] = ____BAH_COMPILER_VAR_1541;____BAH_COMPILER_VAR_1542[0] = r;char * ____BAH_COMPILER_VAR_1543 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1542, 2);r = ____BAH_COMPILER_VAR_1543;
}
return r;
};
long int main(__BAH_ARR_TYPE_cpstring args){
onMemoryError = memErrHandle;
execName = args->data[0];
if ((execName[0]==46)||(execName[0]==47)) {
execName = absPath(execName);
}
struct flags ____BAH_COMPILER_VAR_1544 = {};
____BAH_COMPILER_VAR_1544.flags = memoryAlloc(sizeof(array(struct flag*)));
            ____BAH_COMPILER_VAR_1544.flags->length = 0;
            ____BAH_COMPILER_VAR_1544.flags->elemSize = sizeof(struct flag*);
            ____BAH_COMPILER_VAR_1544.args = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_1544.args->length = 0;
            ____BAH_COMPILER_VAR_1544.args->elemSize = sizeof(char *);
            flags = ____BAH_COMPILER_VAR_1544;
flags__addString(&flags,"o","Name of the file to output.");
flags__addBool(&flags,"c","Translate bah file to C instead of compiling it.");
flags__addBool(&flags,"v","Show version of the compiler.");
flags__addBool(&flags,"l","Compile as a library.");
flags__addBool(&flags,"d","Compile as a dynamic executable. (useful if you are using a library that is only available shared but might reduce portability).");
flags__addBool(&flags,"rcp","Enables RCP (reference counter) instead of the garbage collector. Warning: if you are using self-reference, this will lead to memory leaks!");
flags__addBool(&flags,"fastrcp","Enables RCP without leak detection. It is recommended to test you programs with the -rcp flag to test for leak detection before using this flag.");
flags__addBool(&flags,"debug","Enables verbose json output.");
flags__addBool(&flags,"verboseRuntime","Enables verbose runtime, a debug mode of the compiled program. (obsolete)");
flags__addBool(&flags,"verboseCC","Enables verbose C compiler output, USE IN LAST RESORT.");
char** ____BAH_COMPILER_VAR_1545 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1545[2] = ".";____BAH_COMPILER_VAR_1545[1] = BAH_OS;____BAH_COMPILER_VAR_1545[0] = "Select the target OS for cross compilling (linux, windows, darwin), default: ";char * ____BAH_COMPILER_VAR_1546 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1545, 3);flags__addString(&flags,"target",____BAH_COMPILER_VAR_1546);
char** ____BAH_COMPILER_VAR_1547 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1547[2] = ").";____BAH_COMPILER_VAR_1547[1] = BAH_DIR;____BAH_COMPILER_VAR_1547[0] = "If your Bah directory is not the default one (";char * ____BAH_COMPILER_VAR_1548 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1547, 3);flags__addString(&flags,"bahDir",____BAH_COMPILER_VAR_1548);
char** ____BAH_COMPILER_VAR_1549 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1549[2] = ".";____BAH_COMPILER_VAR_1549[1] = BAH_CC;____BAH_COMPILER_VAR_1549[0] = "To change the C compiler used, default: ";char * ____BAH_COMPILER_VAR_1550 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1549, 3);flags__addString(&flags,"CC",____BAH_COMPILER_VAR_1550);
flags__addBool(&flags,"object","Compile as an object.");
flags__addBool(&flags,"unsafe","Compile without safety checking. This will make for faster executable but if your program crashes, it will show less informations.");
flags__addBool(&flags,"nobuiltin","Does not include the builtin library (be really carefull, your program WILL break).");
flags__addBool(&flags,"optimize","Includes optimized functions");
flags__addBool(&flags,"n","Disables notices while keeping warnings enabled.");
flags__parse(&flags,args);
if ((flags__isSet(&flags,"target")==1)) {
BAH_OS = flags__get(&flags,"target");
char** ____BAH_COMPILER_VAR_1551 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1551[1] = BAH_OS;____BAH_COMPILER_VAR_1551[0] = "Build target: ";char * ____BAH_COMPILER_VAR_1552 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1551, 2);println(____BAH_COMPILER_VAR_1552);
}
if ((flags__isSet(&flags,"bahDir")==1)) {
BAH_DIR = flags__get(&flags,"bahDir");
array(char)* bahDirArr = strAsArr(BAH_DIR);
if ((bahDirArr->data[len(bahDirArr)-1]!=47)) {
char** ____BAH_COMPILER_VAR_1553 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1553[1] = "/";____BAH_COMPILER_VAR_1553[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_1554 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1553, 2);BAH_DIR = ____BAH_COMPILER_VAR_1554;
}
char** ____BAH_COMPILER_VAR_1555 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1555[1] = BAH_DIR;____BAH_COMPILER_VAR_1555[0] = "Bah directory: ";char * ____BAH_COMPILER_VAR_1556 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1555, 2);println(____BAH_COMPILER_VAR_1556);
}
if ((flags__isSet(&flags,"CC")==1)) {
BAH_CC = flags__get(&flags,"CC");
char** ____BAH_COMPILER_VAR_1557 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1557[1] = BAH_CC;____BAH_COMPILER_VAR_1557[0] = "C compiler: ";char * ____BAH_COMPILER_VAR_1558 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1557, 2);println(____BAH_COMPILER_VAR_1558);
}
if (__builtin_expect(flags__isSet(&flags,"verboseRuntime"), 0)) {
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
char** ____BAH_COMPILER_VAR_1559 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1559[2] = ".\n© Alois Laurent Boe";____BAH_COMPILER_VAR_1559[1] = BAH_VERSION;____BAH_COMPILER_VAR_1559[0] = "Bah compiler version: ";char * ____BAH_COMPILER_VAR_1560 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1559, 3);println(____BAH_COMPILER_VAR_1560);
return 0;
}
if (__builtin_expect((flags__isSet(&flags,"c")==1)&&(flags__isSet(&flags,"l")==1), 0)) {
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
struct compilerStateTag ____BAH_COMPILER_VAR_1561 = {};
____BAH_COMPILER_VAR_1561.includes = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_1561.includes->length = 0;
            ____BAH_COMPILER_VAR_1561.includes->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_1561.cIncludes = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_1561.cIncludes->length = 0;
            ____BAH_COMPILER_VAR_1561.cIncludes->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_1561.cLibs = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_1561.cLibs->length = 0;
            ____BAH_COMPILER_VAR_1561.cLibs->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_1561.currentDir = "./";
____BAH_COMPILER_VAR_1561.arrTypesDecl = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_1561.arrTypesDecl->length = 0;
            ____BAH_COMPILER_VAR_1561.arrTypesDecl->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_1561.RCPvars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_1561.RCPvars->length = 0;
            ____BAH_COMPILER_VAR_1561.RCPvars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_1561.evals = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_1561.evals->length = 0;
            ____BAH_COMPILER_VAR_1561.evals->elemSize = sizeof(char *);
            compilerState = ____BAH_COMPILER_VAR_1561;

    unsigned int ____BAH_COMPILER_VAR_1562 = 0;
    __Bah_realocate_arr(compilerState.arrTypesDecl, ____BAH_COMPILER_VAR_1562);
    compilerState.arrTypesDecl->data[____BAH_COMPILER_VAR_1562] = "__BAH_ARR_TYPE_cpstring";
char * fileName = absPath(args->data[1]);
compilerState.currentFile = fileName;
struct fileMap ____BAH_COMPILER_VAR_1563 = {};
____BAH_COMPILER_VAR_1563.handle = -1;
struct fileMap fm = ____BAH_COMPILER_VAR_1563;
char * f = fileMap__open(&fm,fileName);
if (__builtin_expect((fileMap__isValid(&fm)==0)||(fm.size==0), 0)) {
char** ____BAH_COMPILER_VAR_1564 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1564[2] = "'.";____BAH_COMPILER_VAR_1564[1] = args->data[1];____BAH_COMPILER_VAR_1564[0] = "Could not open file '";char * ____BAH_COMPILER_VAR_1565 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1564, 3);println(____BAH_COMPILER_VAR_1565);
exit(1);
}
long int startTime = getTimeUnix();
array(struct Tok)* tokens = lexer(f,fm.size);
fileMap__close(&fm);
if (__builtin_expect((len(tokens)==0), 0)) {
char** ____BAH_COMPILER_VAR_1566 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1566[2] = "' not recognized.";____BAH_COMPILER_VAR_1566[1] = fileName;____BAH_COMPILER_VAR_1566[0] = "File '";char * ____BAH_COMPILER_VAR_1567 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1566, 3);println(____BAH_COMPILER_VAR_1567);
exit(1);
}
struct Elems* ____BAH_COMPILER_VAR_1568 = memoryAlloc(sizeof(struct Elems));
____BAH_COMPILER_VAR_1568->vars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_1568->vars->length = 0;
            ____BAH_COMPILER_VAR_1568->vars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_1568->structs = memoryAlloc(sizeof(array(struct cStruct*)));
            ____BAH_COMPILER_VAR_1568->structs->length = 0;
            ____BAH_COMPILER_VAR_1568->structs->elemSize = sizeof(struct cStruct*);
            ____BAH_COMPILER_VAR_1568->types = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_1568->types->length = 0;
            ____BAH_COMPILER_VAR_1568->types->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_1568->fns = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_1568->fns->length = 0;
            ____BAH_COMPILER_VAR_1568->fns->elemSize = sizeof(struct func*);
            ____BAH_COMPILER_VAR_1568->branchChecks = memoryAlloc(sizeof(array(struct varCheck)));
            ____BAH_COMPILER_VAR_1568->branchChecks->length = 0;
            ____BAH_COMPILER_VAR_1568->branchChecks->elemSize = sizeof(struct varCheck);
            struct Elems* elems = ____BAH_COMPILER_VAR_1568;
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

                struct string ____BAH_COMPILER_VAR_1569 = string(fileName);
                if ((flags__isSet(&flags,"nobuiltin")==0)&&(string__hasSuffix(&____BAH_COMPILER_VAR_1569,".bahstrp")==false)) {
if (__builtin_expect((includeFile("builtin.bah",elems)==false), 0)) {
char** ____BAH_COMPILER_VAR_1570 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1570[2] = "'";____BAH_COMPILER_VAR_1570[1] = BAH_DIR;____BAH_COMPILER_VAR_1570[0] = "Could not find std-libs, please check '";char * ____BAH_COMPILER_VAR_1571 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1570, 3);__BAH_panic(____BAH_COMPILER_VAR_1571,"/home/alois/Documents/bah-bah/src/main.bah:255");
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
char** ____BAH_COMPILER_VAR_1572 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1572[2] = "];";____BAH_COMPILER_VAR_1572[1] = intToStr(l);____BAH_COMPILER_VAR_1572[0] = "volatile struct __Bah_fnName_mapper __tmp____Bah_fnNames[";char * ____BAH_COMPILER_VAR_1573 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1572, 3);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1573));
long int j = 0;
i = 0;
for (; (i<len(elems->fns)); ++i) {
struct func* fn = elems->fns->data[i];
if ((fn->isBinding==true)) {
continue;
}
char * name = fn->name;
char** ____BAH_COMPILER_VAR_1574 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1574[1] = "__";____BAH_COMPILER_VAR_1574[0] = fn->from;char * ____BAH_COMPILER_VAR_1575 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1574, 2);if ((strcmp(fn->from, "") != 0)&&strHasPrefix(name,____BAH_COMPILER_VAR_1575)) {
struct string n = string(name);
string__trimLeft(&n,strlen(fn->from)+2);
char** ____BAH_COMPILER_VAR_1576 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1576[2] = string__str(&n);____BAH_COMPILER_VAR_1576[1] = ".";____BAH_COMPILER_VAR_1576[0] = fn->from;char * ____BAH_COMPILER_VAR_1577 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1576, 3);name = ____BAH_COMPILER_VAR_1577;
}
char** ____BAH_COMPILER_VAR_1578 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_1578[8] = ";\n";____BAH_COMPILER_VAR_1578[7] = fn->name;____BAH_COMPILER_VAR_1578[6] = "].p = ";____BAH_COMPILER_VAR_1578[5] = intToStr(j);____BAH_COMPILER_VAR_1578[4] = "\";\n            __tmp____Bah_fnNames[";____BAH_COMPILER_VAR_1578[3] = name;____BAH_COMPILER_VAR_1578[2] = "].n = \"";____BAH_COMPILER_VAR_1578[1] = intToStr(j);____BAH_COMPILER_VAR_1578[0] = "\n            __tmp____Bah_fnNames[";char * ____BAH_COMPILER_VAR_1579 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1578, 9);INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_1579));
++j;
};
char** ____BAH_COMPILER_VAR_1580 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1580[2] = ";";____BAH_COMPILER_VAR_1580[1] = intToStr(l);____BAH_COMPILER_VAR_1580[0] = "\n        __Bah_fnNames->data = __tmp____Bah_fnNames;\n        __Bah_fnNames->length = ";char * ____BAH_COMPILER_VAR_1581 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1580, 3);INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_1581));
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
char** ____BAH_COMPILER_VAR_1582 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_1582[6] = "ms)\e[0m";____BAH_COMPILER_VAR_1582[5] = intToStr(totalLexerTime/1000000);____BAH_COMPILER_VAR_1582[4] = "ms, lexer time: ";____BAH_COMPILER_VAR_1582[3] = intToStr(totalTime/1000000);____BAH_COMPILER_VAR_1582[2] = " lines, total time: ";____BAH_COMPILER_VAR_1582[1] = intToStr(totalLines);____BAH_COMPILER_VAR_1582[0] = "Parsed. (";char * ____BAH_COMPILER_VAR_1583 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1582, 7);println(____BAH_COMPILER_VAR_1583);
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
char** ____BAH_COMPILER_VAR_1584 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1584[1] = ".o";____BAH_COMPILER_VAR_1584[0] = fileName;char * ____BAH_COMPILER_VAR_1585 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1584, 2);fileName = ____BAH_COMPILER_VAR_1585;
obj = "-c";
}
char * randFileName = "-x c - -x none";
char** ____BAH_COMPILER_VAR_1586 = alloca(17 * sizeof(char*));____BAH_COMPILER_VAR_1586[16] = fileName;____BAH_COMPILER_VAR_1586[15] = " -w -O1 -o ";____BAH_COMPILER_VAR_1586[14] = obj;____BAH_COMPILER_VAR_1586[13] = " ";____BAH_COMPILER_VAR_1586[12] = isStatic;____BAH_COMPILER_VAR_1586[11] = " ";____BAH_COMPILER_VAR_1586[10] = randFileName;____BAH_COMPILER_VAR_1586[9] = "/\" ";____BAH_COMPILER_VAR_1586[8] = BAH_OS;____BAH_COMPILER_VAR_1586[7] = "libs/";____BAH_COMPILER_VAR_1586[6] = BAH_DIR;____BAH_COMPILER_VAR_1586[5] = "/include/\" -L \"";____BAH_COMPILER_VAR_1586[4] = BAH_OS;____BAH_COMPILER_VAR_1586[3] = "libs/";____BAH_COMPILER_VAR_1586[2] = BAH_DIR;____BAH_COMPILER_VAR_1586[1] = " -I \"";____BAH_COMPILER_VAR_1586[0] = BAH_CC;char * ____BAH_COMPILER_VAR_1587 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1586, 17);char * gccArgs = ____BAH_COMPILER_VAR_1587;
if ((flags__isSet(&flags,"l")==1)) {
char** ____BAH_COMPILER_VAR_1588 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1588[1] = " -c";____BAH_COMPILER_VAR_1588[0] = gccArgs;char * ____BAH_COMPILER_VAR_1589 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1588, 2);gccArgs = ____BAH_COMPILER_VAR_1589;
}
array(char *)* cLibs = compilerState.cLibs;
register long int i = 0;
while ((i<len(cLibs))) {
char * l = cLibs->data[i];
char** ____BAH_COMPILER_VAR_1590 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1590[2] = l;____BAH_COMPILER_VAR_1590[1] = " -";____BAH_COMPILER_VAR_1590[0] = gccArgs;char * ____BAH_COMPILER_VAR_1591 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1590, 3);gccArgs = ____BAH_COMPILER_VAR_1591;
i = i+1;
};
struct command cmd = command(gccArgs);
cmd.input = rope__toStr(OUTPUT);
if ((flags__isSet(&flags,"verboseCC")==1)) {
char * ____BAH_COMPILER_VAR_1592 =command__run(&cmd);println(____BAH_COMPILER_VAR_1592);
}
else {
char * ____BAH_COMPILER_VAR_1593 =command__run(&cmd);}
if ((cmd.status!=0)) {
println("\e[1;31m[CC-ERROR]\e[0m\nCould not compiled.");
return 1;
}
if ((flags__isSet(&flags,"l")==1)) {
char** ____BAH_COMPILER_VAR_1594 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1594[3] = fileName;____BAH_COMPILER_VAR_1594[2] = ".a ";____BAH_COMPILER_VAR_1594[1] = fileName;____BAH_COMPILER_VAR_1594[0] = "ar rcs ";char * ____BAH_COMPILER_VAR_1595 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1594, 4);cmd = command(____BAH_COMPILER_VAR_1595);
char * ____BAH_COMPILER_VAR_1596 =command__run(&cmd);}
}
else {
if ((flags__isSet(&flags,"o")==0)) {
char** ____BAH_COMPILER_VAR_1597 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1597[1] = ".c";____BAH_COMPILER_VAR_1597[0] = fileName;char * ____BAH_COMPILER_VAR_1598 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1597, 2);fileName = ____BAH_COMPILER_VAR_1598;
}
char** ____BAH_COMPILER_VAR_1599 = alloca(14 * sizeof(char*));____BAH_COMPILER_VAR_1599[13] = " -O1 -w ";____BAH_COMPILER_VAR_1599[12] = isStatic;____BAH_COMPILER_VAR_1599[11] = " ";____BAH_COMPILER_VAR_1599[10] = fileName;____BAH_COMPILER_VAR_1599[9] = "/\" ";____BAH_COMPILER_VAR_1599[8] = BAH_OS;____BAH_COMPILER_VAR_1599[7] = "libs/";____BAH_COMPILER_VAR_1599[6] = BAH_DIR;____BAH_COMPILER_VAR_1599[5] = "/include/\" -L \"";____BAH_COMPILER_VAR_1599[4] = BAH_OS;____BAH_COMPILER_VAR_1599[3] = "libs/";____BAH_COMPILER_VAR_1599[2] = BAH_DIR;____BAH_COMPILER_VAR_1599[1] = " -I \"";____BAH_COMPILER_VAR_1599[0] = BAH_CC;char * ____BAH_COMPILER_VAR_1600 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1599, 14);char * gccArgs = ____BAH_COMPILER_VAR_1600;
array(char *)* cLibs = compilerState.cLibs;
register long int i = 0;
while ((i<len(cLibs))) {
char * l = cLibs->data[i];
char** ____BAH_COMPILER_VAR_1601 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1601[2] = l;____BAH_COMPILER_VAR_1601[1] = " -";____BAH_COMPILER_VAR_1601[0] = gccArgs;char * ____BAH_COMPILER_VAR_1602 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1601, 3);gccArgs = ____BAH_COMPILER_VAR_1602;
i = i+1;
};
char** ____BAH_COMPILER_VAR_1603 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1603[2] = "'\n";____BAH_COMPILER_VAR_1603[1] = gccArgs;____BAH_COMPILER_VAR_1603[0] = "//COMPILE WITH: '";char * ____BAH_COMPILER_VAR_1604 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1603, 3);OUTPUT = rope__add(rope(____BAH_COMPILER_VAR_1604), OUTPUT);
struct fileStream ____BAH_COMPILER_VAR_1605 = {};
struct fileStream fs = ____BAH_COMPILER_VAR_1605;
fileStream__open(&fs,fileName,"w");
char * ____BAH_COMPILER_VAR_1606 =rope__toStr(OUTPUT);fileStream__writeFile(&fs,____BAH_COMPILER_VAR_1606);
fileStream__close(&fs);
}
if ((isObject==false)) {
long int totalTime = getTimeUnix()-startTime;
char** ____BAH_COMPILER_VAR_1607 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1607[2] = "ms)\e[0m";____BAH_COMPILER_VAR_1607[1] = intToStr(totalTime/1000000);____BAH_COMPILER_VAR_1607[0] = "\e[1;32mDone. (compiled in ";char * ____BAH_COMPILER_VAR_1608 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1607, 3);println(____BAH_COMPILER_VAR_1608);
}
return 0;
};
volatile struct __Bah_fnName_mapper __tmp____Bah_fnNames[323];
    
    void __attribute__((optimize("O0"))) __BAH_init() {
        __BAH_panic_chan = null;
__Bah_fnNames = memoryAlloc(sizeof(array(struct __Bah_fnName_mapper)));

__Bah_fnNames->length = 0;
__Bah_fnNames->elemSize = sizeof(struct __Bah_fnName_mapper);
onMemoryError = null;
__Bah_init_segfaultHandle_OK = __Bah_init_segfaultHandle();
RAND_SEEDED = false;
BAH_DIR = "C:/Bah/";
BAH_OS = "windows";
BAH_CC = "gcc";
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
postDeclHandle = rope("");
shouldOnlyDecl = false;
threadCount = 0;
currentFn = null;
totalLines = 0;
totalSize = 0;
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
generics = memoryAlloc(sizeof(array(struct genericFunc*)));

generics->length = 0;
generics->elemSize = sizeof(struct genericFunc*);
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

            __tmp____Bah_fnNames[16].n = "closeSharedMemory";
            __tmp____Bah_fnNames[16].p = closeSharedMemory;

            __tmp____Bah_fnNames[17].n = "allocateArray";
            __tmp____Bah_fnNames[17].p = allocateArray;

            __tmp____Bah_fnNames[18].n = "__serialize";
            __tmp____Bah_fnNames[18].p = __serialize;

            __tmp____Bah_fnNames[19].n = "serlen";
            __tmp____Bah_fnNames[19].p = serlen;

            __tmp____Bah_fnNames[20].n = "unser";
            __tmp____Bah_fnNames[20].p = unser;

            __tmp____Bah_fnNames[21].n = "memoryAllocSTR";
            __tmp____Bah_fnNames[21].p = memoryAllocSTR;

            __tmp____Bah_fnNames[22].n = "delete";
            __tmp____Bah_fnNames[22].p = delete;

            __tmp____Bah_fnNames[23].n = "deleteRange";
            __tmp____Bah_fnNames[23].p = deleteRange;

            __tmp____Bah_fnNames[24].n = "arrToStr";
            __tmp____Bah_fnNames[24].p = arrToStr;

            __tmp____Bah_fnNames[25].n = "strToArr";
            __tmp____Bah_fnNames[25].p = strToArr;

            __tmp____Bah_fnNames[26].n = "arrAsStr";
            __tmp____Bah_fnNames[26].p = arrAsStr;

            __tmp____Bah_fnNames[27].n = "strAsArr";
            __tmp____Bah_fnNames[27].p = strAsArr;

            __tmp____Bah_fnNames[28].n = "strTrimLeft";
            __tmp____Bah_fnNames[28].p = strTrimLeft;

            __tmp____Bah_fnNames[29].n = "strTrimRight";
            __tmp____Bah_fnNames[29].p = strTrimRight;

            __tmp____Bah_fnNames[30].n = "__Bah_realocate_arr";
            __tmp____Bah_fnNames[30].p = __Bah_realocate_arr;

            __tmp____Bah_fnNames[31].n = "__Bah_multiple_concat";
            __tmp____Bah_fnNames[31].p = __Bah_multiple_concat;

            __tmp____Bah_fnNames[32].n = "concatCPSTRING";
            __tmp____Bah_fnNames[32].p = concatCPSTRING;

            __tmp____Bah_fnNames[33].n = "__STR";
            __tmp____Bah_fnNames[33].p = __STR;

            __tmp____Bah_fnNames[34].n = "cArr";
            __tmp____Bah_fnNames[34].p = cArr;

            __tmp____Bah_fnNames[35].n = "__checkString";
            __tmp____Bah_fnNames[35].p = __checkString;

            __tmp____Bah_fnNames[36].n = "mutex.init";
            __tmp____Bah_fnNames[36].p = mutex__init;

            __tmp____Bah_fnNames[37].n = "mutex.lock";
            __tmp____Bah_fnNames[37].p = mutex__lock;

            __tmp____Bah_fnNames[38].n = "mutex.unlock";
            __tmp____Bah_fnNames[38].p = mutex__unlock;

            __tmp____Bah_fnNames[39].n = "mutex.destroy";
            __tmp____Bah_fnNames[39].p = mutex__destroy;

            __tmp____Bah_fnNames[40].n = "mutexCondition.init";
            __tmp____Bah_fnNames[40].p = mutexCondition__init;

            __tmp____Bah_fnNames[41].n = "mutexCondition.wait";
            __tmp____Bah_fnNames[41].p = mutexCondition__wait;

            __tmp____Bah_fnNames[42].n = "mutexCondition.send";
            __tmp____Bah_fnNames[42].p = mutexCondition__send;

            __tmp____Bah_fnNames[43].n = "mutexCondition.destroy";
            __tmp____Bah_fnNames[43].p = mutexCondition__destroy;

            __tmp____Bah_fnNames[44].n = "mutexCondition";
            __tmp____Bah_fnNames[44].p = mutexCondition;

            __tmp____Bah_fnNames[45].n = "thread.create";
            __tmp____Bah_fnNames[45].p = thread__create;

            __tmp____Bah_fnNames[46].n = "thread.createWithArg";
            __tmp____Bah_fnNames[46].p = thread__createWithArg;

            __tmp____Bah_fnNames[47].n = "thread.wait";
            __tmp____Bah_fnNames[47].p = thread__wait;

            __tmp____Bah_fnNames[48].n = "mutex";
            __tmp____Bah_fnNames[48].p = mutex;

            __tmp____Bah_fnNames[49].n = "queue.insert";
            __tmp____Bah_fnNames[49].p = queue__insert;

            __tmp____Bah_fnNames[50].n = "queue.delete";
            __tmp____Bah_fnNames[50].p = queue__delete;

            __tmp____Bah_fnNames[51].n = "queue.get";
            __tmp____Bah_fnNames[51].p = queue__get;

            __tmp____Bah_fnNames[52].n = "queue.set";
            __tmp____Bah_fnNames[52].p = queue__set;

            __tmp____Bah_fnNames[53].n = "queue.pop";
            __tmp____Bah_fnNames[53].p = queue__pop;

            __tmp____Bah_fnNames[54].n = "queue.clear";
            __tmp____Bah_fnNames[54].p = queue__clear;

            __tmp____Bah_fnNames[55].n = "channel.send";
            __tmp____Bah_fnNames[55].p = channel__send;

            __tmp____Bah_fnNames[56].n = "channel.sendAny";
            __tmp____Bah_fnNames[56].p = channel__sendAny;

            __tmp____Bah_fnNames[57].n = "channel.receive";
            __tmp____Bah_fnNames[57].p = channel__receive;

            __tmp____Bah_fnNames[58].n = "channel.destroy";
            __tmp____Bah_fnNames[58].p = channel__destroy;

            __tmp____Bah_fnNames[59].n = "channel.len";
            __tmp____Bah_fnNames[59].p = channel__len;

            __tmp____Bah_fnNames[60].n = "channel";
            __tmp____Bah_fnNames[60].p = channel;

            __tmp____Bah_fnNames[61].n = "setChanCap";
            __tmp____Bah_fnNames[61].p = setChanCap;

            __tmp____Bah_fnNames[62].n = "__Bah_common_panic";
            __tmp____Bah_fnNames[62].p = __Bah_common_panic;

            __tmp____Bah_fnNames[63].n = "__Bah_fnNames_append";
            __tmp____Bah_fnNames[63].p = __Bah_fnNames_append;

            __tmp____Bah_fnNames[64].n = "__Bah_segfault_handle";
            __tmp____Bah_fnNames[64].p = __Bah_segfault_handle;

            __tmp____Bah_fnNames[65].n = "__Bah_init_segfaultHandle";
            __tmp____Bah_fnNames[65].p = __Bah_init_segfaultHandle;

            __tmp____Bah_fnNames[66].n = "recover";
            __tmp____Bah_fnNames[66].p = recover;

            __tmp____Bah_fnNames[67].n = "cpstringCharAt";
            __tmp____Bah_fnNames[67].p = cpstringCharAt;

            __tmp____Bah_fnNames[68].n = "cpstringSubsitute";
            __tmp____Bah_fnNames[68].p = cpstringSubsitute;

            __tmp____Bah_fnNames[69].n = "arraySubstitute";
            __tmp____Bah_fnNames[69].p = arraySubstitute;

            __tmp____Bah_fnNames[70].n = "__Bah_map_hash";
            __tmp____Bah_fnNames[70].p = __Bah_map_hash;

            __tmp____Bah_fnNames[71].n = "mapWrapper.grow";
            __tmp____Bah_fnNames[71].p = mapWrapper__grow;

            __tmp____Bah_fnNames[72].n = "mapWrapper.set";
            __tmp____Bah_fnNames[72].p = mapWrapper__set;

            __tmp____Bah_fnNames[73].n = "mapWrapper.setAny";
            __tmp____Bah_fnNames[73].p = mapWrapper__setAny;

            __tmp____Bah_fnNames[74].n = "mapWrapper.delete";
            __tmp____Bah_fnNames[74].p = mapWrapper__delete;

            __tmp____Bah_fnNames[75].n = "mapWrapper.get";
            __tmp____Bah_fnNames[75].p = mapWrapper__get;

            __tmp____Bah_fnNames[76].n = "mapWrapper";
            __tmp____Bah_fnNames[76].p = mapWrapper;

            __tmp____Bah_fnNames[77].n = "stdinput";
            __tmp____Bah_fnNames[77].p = stdinput;

            __tmp____Bah_fnNames[78].n = "println";
            __tmp____Bah_fnNames[78].p = println;

            __tmp____Bah_fnNames[79].n = "fileStream.isValid";
            __tmp____Bah_fnNames[79].p = fileStream__isValid;

            __tmp____Bah_fnNames[80].n = "fileStream.open";
            __tmp____Bah_fnNames[80].p = fileStream__open;

            __tmp____Bah_fnNames[81].n = "fileStream.close";
            __tmp____Bah_fnNames[81].p = fileStream__close;

            __tmp____Bah_fnNames[82].n = "fileStream.getPos";
            __tmp____Bah_fnNames[82].p = fileStream__getPos;

            __tmp____Bah_fnNames[83].n = "fileStream.setPos";
            __tmp____Bah_fnNames[83].p = fileStream__setPos;

            __tmp____Bah_fnNames[84].n = "fileStream.getSize";
            __tmp____Bah_fnNames[84].p = fileStream__getSize;

            __tmp____Bah_fnNames[85].n = "fileStream.rewind";
            __tmp____Bah_fnNames[85].p = fileStream__rewind;

            __tmp____Bah_fnNames[86].n = "fileStream.getChar";
            __tmp____Bah_fnNames[86].p = fileStream__getChar;

            __tmp____Bah_fnNames[87].n = "fileStream.setChar";
            __tmp____Bah_fnNames[87].p = fileStream__setChar;

            __tmp____Bah_fnNames[88].n = "fileStream.createFile";
            __tmp____Bah_fnNames[88].p = fileStream__createFile;

            __tmp____Bah_fnNames[89].n = "fileStream.writeFile";
            __tmp____Bah_fnNames[89].p = fileStream__writeFile;

            __tmp____Bah_fnNames[90].n = "fileStream.writePtr";
            __tmp____Bah_fnNames[90].p = fileStream__writePtr;

            __tmp____Bah_fnNames[91].n = "fileStream.readPtr";
            __tmp____Bah_fnNames[91].p = fileStream__readPtr;

            __tmp____Bah_fnNames[92].n = "fileStream.readContent";
            __tmp____Bah_fnNames[92].p = fileStream__readContent;

            __tmp____Bah_fnNames[93].n = "fileStream.readBytes";
            __tmp____Bah_fnNames[93].p = fileStream__readBytes;

            __tmp____Bah_fnNames[94].n = "fileStream.writeBytes";
            __tmp____Bah_fnNames[94].p = fileStream__writeBytes;

            __tmp____Bah_fnNames[95].n = "fileStream._end";
            __tmp____Bah_fnNames[95].p = fileStream___end;

            __tmp____Bah_fnNames[96].n = "fileMap.open";
            __tmp____Bah_fnNames[96].p = fileMap__open;

            __tmp____Bah_fnNames[97].n = "fileMap.isValid";
            __tmp____Bah_fnNames[97].p = fileMap__isValid;

            __tmp____Bah_fnNames[98].n = "fileMap.close";
            __tmp____Bah_fnNames[98].p = fileMap__close;

            __tmp____Bah_fnNames[99].n = "listFiles";
            __tmp____Bah_fnNames[99].p = listFiles;

            __tmp____Bah_fnNames[100].n = "fileExists";
            __tmp____Bah_fnNames[100].p = fileExists;

            __tmp____Bah_fnNames[101].n = "isFolder";
            __tmp____Bah_fnNames[101].p = isFolder;

            __tmp____Bah_fnNames[102].n = "removeFile";
            __tmp____Bah_fnNames[102].p = removeFile;

            __tmp____Bah_fnNames[103].n = "getLastModified";
            __tmp____Bah_fnNames[103].p = getLastModified;

            __tmp____Bah_fnNames[104].n = "__windows_mkdir";
            __tmp____Bah_fnNames[104].p = __windows_mkdir;

            __tmp____Bah_fnNames[105].n = "strCatOffset";
            __tmp____Bah_fnNames[105].p = strCatOffset;

            __tmp____Bah_fnNames[106].n = "charToString";
            __tmp____Bah_fnNames[106].p = charToString;

            __tmp____Bah_fnNames[107].n = "isUpper";
            __tmp____Bah_fnNames[107].p = isUpper;

            __tmp____Bah_fnNames[108].n = "isLower";
            __tmp____Bah_fnNames[108].p = isLower;

            __tmp____Bah_fnNames[109].n = "isLetter";
            __tmp____Bah_fnNames[109].p = isLetter;

            __tmp____Bah_fnNames[110].n = "isNumber";
            __tmp____Bah_fnNames[110].p = isNumber;

            __tmp____Bah_fnNames[111].n = "isAlphaNumeric";
            __tmp____Bah_fnNames[111].p = isAlphaNumeric;

            __tmp____Bah_fnNames[112].n = "isSpace";
            __tmp____Bah_fnNames[112].p = isSpace;

            __tmp____Bah_fnNames[113].n = "string.set";
            __tmp____Bah_fnNames[113].p = string__set;

            __tmp____Bah_fnNames[114].n = "string.makeEditable";
            __tmp____Bah_fnNames[114].p = string__makeEditable;

            __tmp____Bah_fnNames[115].n = "string.append";
            __tmp____Bah_fnNames[115].p = string__append;

            __tmp____Bah_fnNames[116].n = "string.prepend";
            __tmp____Bah_fnNames[116].p = string__prepend;

            __tmp____Bah_fnNames[117].n = "string.charAt";
            __tmp____Bah_fnNames[117].p = string__charAt;

            __tmp____Bah_fnNames[118].n = "string.compare";
            __tmp____Bah_fnNames[118].p = string__compare;

            __tmp____Bah_fnNames[119].n = "string.str";
            __tmp____Bah_fnNames[119].p = string__str;

            __tmp____Bah_fnNames[120].n = "string.replace";
            __tmp____Bah_fnNames[120].p = string__replace;

            __tmp____Bah_fnNames[121].n = "string.countChar";
            __tmp____Bah_fnNames[121].p = string__countChar;

            __tmp____Bah_fnNames[122].n = "string.count";
            __tmp____Bah_fnNames[122].p = string__count;

            __tmp____Bah_fnNames[123].n = "string.hasPrefix";
            __tmp____Bah_fnNames[123].p = string__hasPrefix;

            __tmp____Bah_fnNames[124].n = "string.hasSuffix";
            __tmp____Bah_fnNames[124].p = string__hasSuffix;

            __tmp____Bah_fnNames[125].n = "string.trim";
            __tmp____Bah_fnNames[125].p = string__trim;

            __tmp____Bah_fnNames[126].n = "string.trimLeft";
            __tmp____Bah_fnNames[126].p = string__trimLeft;

            __tmp____Bah_fnNames[127].n = "string.trimRight";
            __tmp____Bah_fnNames[127].p = string__trimRight;

            __tmp____Bah_fnNames[128].n = "string.add";
            __tmp____Bah_fnNames[128].p = string__add;

            __tmp____Bah_fnNames[129].n = "string.asArr";
            __tmp____Bah_fnNames[129].p = string__asArr;

            __tmp____Bah_fnNames[130].n = "string";
            __tmp____Bah_fnNames[130].p = string;

            __tmp____Bah_fnNames[131].n = "intToStr";
            __tmp____Bah_fnNames[131].p = intToStr;

            __tmp____Bah_fnNames[132].n = "intToString";
            __tmp____Bah_fnNames[132].p = intToString;

            __tmp____Bah_fnNames[133].n = "floatToStr";
            __tmp____Bah_fnNames[133].p = floatToStr;

            __tmp____Bah_fnNames[134].n = "strToInt";
            __tmp____Bah_fnNames[134].p = strToInt;

            __tmp____Bah_fnNames[135].n = "strToFloat";
            __tmp____Bah_fnNames[135].p = strToFloat;

            __tmp____Bah_fnNames[136].n = "stringToInt";
            __tmp____Bah_fnNames[136].p = stringToInt;

            __tmp____Bah_fnNames[137].n = "splitString";
            __tmp____Bah_fnNames[137].p = splitString;

            __tmp____Bah_fnNames[138].n = "joinString";
            __tmp____Bah_fnNames[138].p = joinString;

            __tmp____Bah_fnNames[139].n = "splitStringBefore";
            __tmp____Bah_fnNames[139].p = splitStringBefore;

            __tmp____Bah_fnNames[140].n = "toLower";
            __tmp____Bah_fnNames[140].p = toLower;

            __tmp____Bah_fnNames[141].n = "strHasPrefix";
            __tmp____Bah_fnNames[141].p = strHasPrefix;

            __tmp____Bah_fnNames[142].n = "strHasSuffix";
            __tmp____Bah_fnNames[142].p = strHasSuffix;

            __tmp____Bah_fnNames[143].n = "strTrim";
            __tmp____Bah_fnNames[143].p = strTrim;

            __tmp____Bah_fnNames[144].n = "strCount";
            __tmp____Bah_fnNames[144].p = strCount;

            __tmp____Bah_fnNames[145].n = "flags.addString";
            __tmp____Bah_fnNames[145].p = flags__addString;

            __tmp____Bah_fnNames[146].n = "flags.addBool";
            __tmp____Bah_fnNames[146].p = flags__addBool;

            __tmp____Bah_fnNames[147].n = "flags.addInt";
            __tmp____Bah_fnNames[147].p = flags__addInt;

            __tmp____Bah_fnNames[148].n = "flags.addFloat";
            __tmp____Bah_fnNames[148].p = flags__addFloat;

            __tmp____Bah_fnNames[149].n = "flags.invalidate";
            __tmp____Bah_fnNames[149].p = flags__invalidate;

            __tmp____Bah_fnNames[150].n = "flags.getFlag";
            __tmp____Bah_fnNames[150].p = flags__getFlag;

            __tmp____Bah_fnNames[151].n = "flags.get";
            __tmp____Bah_fnNames[151].p = flags__get;

            __tmp____Bah_fnNames[152].n = "flags.getInt";
            __tmp____Bah_fnNames[152].p = flags__getInt;

            __tmp____Bah_fnNames[153].n = "flags.getFloat";
            __tmp____Bah_fnNames[153].p = flags__getFloat;

            __tmp____Bah_fnNames[154].n = "flags.isSet";
            __tmp____Bah_fnNames[154].p = flags__isSet;

            __tmp____Bah_fnNames[155].n = "flags.parse";
            __tmp____Bah_fnNames[155].p = flags__parse;

            __tmp____Bah_fnNames[156].n = "time.now";
            __tmp____Bah_fnNames[156].p = time__now;

            __tmp____Bah_fnNames[157].n = "time.format";
            __tmp____Bah_fnNames[157].p = time__format;

            __tmp____Bah_fnNames[158].n = "time.since";
            __tmp____Bah_fnNames[158].p = time__since;

            __tmp____Bah_fnNames[159].n = "getTimeUnix";
            __tmp____Bah_fnNames[159].p = getTimeUnix;

            __tmp____Bah_fnNames[160].n = "seedRandom";
            __tmp____Bah_fnNames[160].p = seedRandom;

            __tmp____Bah_fnNames[161].n = "randomInRange";
            __tmp____Bah_fnNames[161].p = randomInRange;

            __tmp____Bah_fnNames[162].n = "cryptoRand";
            __tmp____Bah_fnNames[162].p = cryptoRand;

            __tmp____Bah_fnNames[163].n = "rope.addStr";
            __tmp____Bah_fnNames[163].p = rope__addStr;

            __tmp____Bah_fnNames[164].n = "rope.toStr";
            __tmp____Bah_fnNames[164].p = rope__toStr;

            __tmp____Bah_fnNames[165].n = "rope.add";
            __tmp____Bah_fnNames[165].p = rope__add;

            __tmp____Bah_fnNames[166].n = "createRopeStructure";
            __tmp____Bah_fnNames[166].p = createRopeStructure;

            __tmp____Bah_fnNames[167].n = "ropeSet";
            __tmp____Bah_fnNames[167].p = ropeSet;

            __tmp____Bah_fnNames[168].n = "concatenateRopes";
            __tmp____Bah_fnNames[168].p = concatenateRopes;

            __tmp____Bah_fnNames[169].n = "rope";
            __tmp____Bah_fnNames[169].p = rope;

            __tmp____Bah_fnNames[170].n = "command.run";
            __tmp____Bah_fnNames[170].p = command__run;

            __tmp____Bah_fnNames[171].n = "command.runBytes";
            __tmp____Bah_fnNames[171].p = command__runBytes;

            __tmp____Bah_fnNames[172].n = "command";
            __tmp____Bah_fnNames[172].p = command;

            __tmp____Bah_fnNames[173].n = "exec";
            __tmp____Bah_fnNames[173].p = exec;

            __tmp____Bah_fnNames[174].n = "inArray";
            __tmp____Bah_fnNames[174].p = inArray;

            __tmp____Bah_fnNames[175].n = "inArrayStr";
            __tmp____Bah_fnNames[175].p = inArrayStr;

            __tmp____Bah_fnNames[176].n = "makeToken";
            __tmp____Bah_fnNames[176].p = makeToken;

            __tmp____Bah_fnNames[177].n = "isMinus";
            __tmp____Bah_fnNames[177].p = isMinus;

            __tmp____Bah_fnNames[178].n = "lexerErr";
            __tmp____Bah_fnNames[178].p = lexerErr;

            __tmp____Bah_fnNames[179].n = "lexer";
            __tmp____Bah_fnNames[179].p = lexer;

            __tmp____Bah_fnNames[180].n = "hasStructSep";
            __tmp____Bah_fnNames[180].p = hasStructSep;

            __tmp____Bah_fnNames[181].n = "splitStructSepBefore";
            __tmp____Bah_fnNames[181].p = splitStructSepBefore;

            __tmp____Bah_fnNames[182].n = "splitStructSepAfter";
            __tmp____Bah_fnNames[182].p = splitStructSepAfter;

            __tmp____Bah_fnNames[183].n = "searchStruct";
            __tmp____Bah_fnNames[183].p = searchStruct;

            __tmp____Bah_fnNames[184].n = "searchStructMemb";
            __tmp____Bah_fnNames[184].p = searchStructMemb;

            __tmp____Bah_fnNames[185].n = "searchFunc";
            __tmp____Bah_fnNames[185].p = searchFunc;

            __tmp____Bah_fnNames[186].n = "parseFnType";
            __tmp____Bah_fnNames[186].p = parseFnType;

            __tmp____Bah_fnNames[187].n = "searchStructMethod";
            __tmp____Bah_fnNames[187].p = searchStructMethod;

            __tmp____Bah_fnNames[188].n = "typeAsStar";
            __tmp____Bah_fnNames[188].p = typeAsStar;

            __tmp____Bah_fnNames[189].n = "isRCPpointerType";
            __tmp____Bah_fnNames[189].p = isRCPpointerType;

            __tmp____Bah_fnNames[190].n = "isRCPtype";
            __tmp____Bah_fnNames[190].p = isRCPtype;

            __tmp____Bah_fnNames[191].n = "getCType";
            __tmp____Bah_fnNames[191].p = getCType;

            __tmp____Bah_fnNames[192].n = "maybeToPtr";
            __tmp____Bah_fnNames[192].p = maybeToPtr;

            __tmp____Bah_fnNames[193].n = "compTypeEquiv";
            __tmp____Bah_fnNames[193].p = compTypeEquiv;

            __tmp____Bah_fnNames[194].n = "compTypes";
            __tmp____Bah_fnNames[194].p = compTypes;

            __tmp____Bah_fnNames[195].n = "reflectElement.calculateOffset";
            __tmp____Bah_fnNames[195].p = reflectElement__calculateOffset;

            __tmp____Bah_fnNames[196].n = "__reflect";
            __tmp____Bah_fnNames[196].p = __reflect;

            __tmp____Bah_fnNames[197].n = "__dumpSymbols";
            __tmp____Bah_fnNames[197].p = __dumpSymbols;

            __tmp____Bah_fnNames[198].n = "__debug_get_sym";
            __tmp____Bah_fnNames[198].p = __debug_get_sym;

            __tmp____Bah_fnNames[199].n = "toJson";
            __tmp____Bah_fnNames[199].p = toJson;

            __tmp____Bah_fnNames[200].n = "json_scan_inner";
            __tmp____Bah_fnNames[200].p = json_scan_inner;

            __tmp____Bah_fnNames[201].n = "jsonElement.get";
            __tmp____Bah_fnNames[201].p = jsonElement__get;

            __tmp____Bah_fnNames[202].n = "jsonElement.str";
            __tmp____Bah_fnNames[202].p = jsonElement__str;

            __tmp____Bah_fnNames[203].n = "jsonElement.scan";
            __tmp____Bah_fnNames[203].p = jsonElement__scan;

            __tmp____Bah_fnNames[204].n = "parseJson";
            __tmp____Bah_fnNames[204].p = parseJson;

            __tmp____Bah_fnNames[205].n = "json_isPrintable";
            __tmp____Bah_fnNames[205].p = json_isPrintable;

            __tmp____Bah_fnNames[206].n = "jsonEscapeStr";
            __tmp____Bah_fnNames[206].p = jsonEscapeStr;

            __tmp____Bah_fnNames[207].n = "toJson__inner";
            __tmp____Bah_fnNames[207].p = toJson__inner;

            __tmp____Bah_fnNames[208].n = "debugStart";
            __tmp____Bah_fnNames[208].p = debugStart;

            __tmp____Bah_fnNames[209].n = "debugPrint";
            __tmp____Bah_fnNames[209].p = debugPrint;

            __tmp____Bah_fnNames[210].n = "debugError";
            __tmp____Bah_fnNames[210].p = debugError;

            __tmp____Bah_fnNames[211].n = "debugEnd";
            __tmp____Bah_fnNames[211].p = debugEnd;

            __tmp____Bah_fnNames[212].n = "debugExit";
            __tmp____Bah_fnNames[212].p = debugExit;

            __tmp____Bah_fnNames[213].n = "debugEndScope";
            __tmp____Bah_fnNames[213].p = debugEndScope;

            __tmp____Bah_fnNames[214].n = "advertiseGeneric";
            __tmp____Bah_fnNames[214].p = advertiseGeneric;

            __tmp____Bah_fnNames[215].n = "throwErr";
            __tmp____Bah_fnNames[215].p = throwErr;

            __tmp____Bah_fnNames[216].n = "throwWarning";
            __tmp____Bah_fnNames[216].p = throwWarning;

            __tmp____Bah_fnNames[217].n = "throwWarningLine";
            __tmp____Bah_fnNames[217].p = throwWarningLine;

            __tmp____Bah_fnNames[218].n = "throwNoticeLine";
            __tmp____Bah_fnNames[218].p = throwNoticeLine;

            __tmp____Bah_fnNames[219].n = "absPath";
            __tmp____Bah_fnNames[219].p = absPath;

            __tmp____Bah_fnNames[220].n = "getCurrentPath";
            __tmp____Bah_fnNames[220].p = getCurrentPath;

            __tmp____Bah_fnNames[221].n = "isInside";
            __tmp____Bah_fnNames[221].p = isInside;

            __tmp____Bah_fnNames[222].n = "setCurrentPath";
            __tmp____Bah_fnNames[222].p = setCurrentPath;

            __tmp____Bah_fnNames[223].n = "isGlobal";
            __tmp____Bah_fnNames[223].p = isGlobal;

            __tmp____Bah_fnNames[224].n = "getRealVar";
            __tmp____Bah_fnNames[224].p = getRealVar;

            __tmp____Bah_fnNames[225].n = "removeVarUnar";
            __tmp____Bah_fnNames[225].p = removeVarUnar;

            __tmp____Bah_fnNames[226].n = "searchVar";
            __tmp____Bah_fnNames[226].p = searchVar;

            __tmp____Bah_fnNames[227].n = "searchVarByToken";
            __tmp____Bah_fnNames[227].p = searchVarByToken;

            __tmp____Bah_fnNames[228].n = "searchVirtVarByToken";
            __tmp____Bah_fnNames[228].p = searchVirtVarByToken;

            __tmp____Bah_fnNames[229].n = "setCType";
            __tmp____Bah_fnNames[229].p = setCType;

            __tmp____Bah_fnNames[230].n = "getTypeFromToken";
            __tmp____Bah_fnNames[230].p = getTypeFromToken;

            __tmp____Bah_fnNames[231].n = "searchFuncByToken";
            __tmp____Bah_fnNames[231].p = searchFuncByToken;

            __tmp____Bah_fnNames[232].n = "RCPavailable";
            __tmp____Bah_fnNames[232].p = RCPavailable;

            __tmp____Bah_fnNames[233].n = "declareStructMethods";
            __tmp____Bah_fnNames[233].p = declareStructMethods;

            __tmp____Bah_fnNames[234].n = "genCompilerVar";
            __tmp____Bah_fnNames[234].p = genCompilerVar;

            __tmp____Bah_fnNames[235].n = "varInArr";
            __tmp____Bah_fnNames[235].p = varInArr;

            __tmp____Bah_fnNames[236].n = "pathToVarName";
            __tmp____Bah_fnNames[236].p = pathToVarName;

            __tmp____Bah_fnNames[237].n = "makeInit";
            __tmp____Bah_fnNames[237].p = makeInit;

            __tmp____Bah_fnNames[238].n = "checkedNull";
            __tmp____Bah_fnNames[238].p = checkedNull;

            __tmp____Bah_fnNames[239].n = "checkedNotNull";
            __tmp____Bah_fnNames[239].p = checkedNotNull;

            __tmp____Bah_fnNames[240].n = "canChangeNullState";
            __tmp____Bah_fnNames[240].p = canChangeNullState;

            __tmp____Bah_fnNames[241].n = "isOutterScope";
            __tmp____Bah_fnNames[241].p = isOutterScope;

            __tmp____Bah_fnNames[242].n = "decrVar";
            __tmp____Bah_fnNames[242].p = decrVar;

            __tmp____Bah_fnNames[243].n = "incrVar";
            __tmp____Bah_fnNames[243].p = incrVar;

            __tmp____Bah_fnNames[244].n = "beginRCPscope";
            __tmp____Bah_fnNames[244].p = beginRCPscope;

            __tmp____Bah_fnNames[245].n = "beginRCPscopeLeaky";
            __tmp____Bah_fnNames[245].p = beginRCPscopeLeaky;

            __tmp____Bah_fnNames[246].n = "endRCPscope";
            __tmp____Bah_fnNames[246].p = endRCPscope;

            __tmp____Bah_fnNames[247].n = "endRCPscopeLeaky";
            __tmp____Bah_fnNames[247].p = endRCPscopeLeaky;

            __tmp____Bah_fnNames[248].n = "registerRCPvar";
            __tmp____Bah_fnNames[248].p = registerRCPvar;

            __tmp____Bah_fnNames[249].n = "RCPselfRef";
            __tmp____Bah_fnNames[249].p = RCPselfRef;

            __tmp____Bah_fnNames[250].n = "verboseOutGuard";
            __tmp____Bah_fnNames[250].p = verboseOutGuard;

            __tmp____Bah_fnNames[251].n = "verboseOutTransformVar";
            __tmp____Bah_fnNames[251].p = verboseOutTransformVar;

            __tmp____Bah_fnNames[252].n = "verboseOutTransformTok";
            __tmp____Bah_fnNames[252].p = verboseOutTransformTok;

            __tmp____Bah_fnNames[253].n = "verboseOutFunc";
            __tmp____Bah_fnNames[253].p = verboseOutFunc;

            __tmp____Bah_fnNames[254].n = "verboseOutOper";
            __tmp____Bah_fnNames[254].p = verboseOutOper;

            __tmp____Bah_fnNames[255].n = "readCache";
            __tmp____Bah_fnNames[255].p = readCache;

            __tmp____Bah_fnNames[256].n = "getCacheFile";
            __tmp____Bah_fnNames[256].p = getCacheFile;

            __tmp____Bah_fnNames[257].n = "updateCacheFile";
            __tmp____Bah_fnNames[257].p = updateCacheFile;

            __tmp____Bah_fnNames[258].n = "makeCacheFile";
            __tmp____Bah_fnNames[258].p = makeCacheFile;

            __tmp____Bah_fnNames[259].n = "writeCache";
            __tmp____Bah_fnNames[259].p = writeCache;

            __tmp____Bah_fnNames[260].n = "isValidCacheFile";
            __tmp____Bah_fnNames[260].p = isValidCacheFile;

            __tmp____Bah_fnNames[261].n = "genArrRealloc";
            __tmp____Bah_fnNames[261].p = genArrRealloc;

            __tmp____Bah_fnNames[262].n = "genConcat";
            __tmp____Bah_fnNames[262].p = genConcat;

            __tmp____Bah_fnNames[263].n = "OPTI_checkFuncScopeRef";
            __tmp____Bah_fnNames[263].p = OPTI_checkFuncScopeRef;

            __tmp____Bah_fnNames[264].n = "isExprExpensive";
            __tmp____Bah_fnNames[264].p = isExprExpensive;

            __tmp____Bah_fnNames[265].n = "dupElems";
            __tmp____Bah_fnNames[265].p = dupElems;

            __tmp____Bah_fnNames[266].n = "parseLines";
            __tmp____Bah_fnNames[266].p = parseLines;

            __tmp____Bah_fnNames[267].n = "genericFunc.dupBaseFn";
            __tmp____Bah_fnNames[267].p = genericFunc__dupBaseFn;

            __tmp____Bah_fnNames[268].n = "genericFunc.setCurrGeneric";
            __tmp____Bah_fnNames[268].p = genericFunc__setCurrGeneric;

            __tmp____Bah_fnNames[269].n = "genericFunc.isAlreadyDecl";
            __tmp____Bah_fnNames[269].p = genericFunc__isAlreadyDecl;

            __tmp____Bah_fnNames[270].n = "genericFunc.declare";
            __tmp____Bah_fnNames[270].p = genericFunc__declare;

            __tmp____Bah_fnNames[271].n = "debugLine";
            __tmp____Bah_fnNames[271].p = debugLine;

            __tmp____Bah_fnNames[272].n = "checkCanBeNull";
            __tmp____Bah_fnNames[272].p = checkCanBeNull;

            __tmp____Bah_fnNames[273].n = "setNullStateBranchFlowEnd";
            __tmp____Bah_fnNames[273].p = setNullStateBranchFlowEnd;

            __tmp____Bah_fnNames[274].n = "getLineType";
            __tmp____Bah_fnNames[274].p = getLineType;

            __tmp____Bah_fnNames[275].n = "parseCast";
            __tmp____Bah_fnNames[275].p = parseCast;

            __tmp____Bah_fnNames[276].n = "getDirFromFile";
            __tmp____Bah_fnNames[276].p = getDirFromFile;

            __tmp____Bah_fnNames[277].n = "includeFile";
            __tmp____Bah_fnNames[277].p = includeFile;

            __tmp____Bah_fnNames[278].n = "parallelObjCompile";
            __tmp____Bah_fnNames[278].p = parallelObjCompile;

            __tmp____Bah_fnNames[279].n = "parseImport";
            __tmp____Bah_fnNames[279].p = parseImport;

            __tmp____Bah_fnNames[280].n = "parseInclude";
            __tmp____Bah_fnNames[280].p = parseInclude;

            __tmp____Bah_fnNames[281].n = "prePross";
            __tmp____Bah_fnNames[281].p = prePross;

            __tmp____Bah_fnNames[282].n = "parseStructType";
            __tmp____Bah_fnNames[282].p = parseStructType;

            __tmp____Bah_fnNames[283].n = "parseArrayType";
            __tmp____Bah_fnNames[283].p = parseArrayType;

            __tmp____Bah_fnNames[284].n = "parsePointers";
            __tmp____Bah_fnNames[284].p = parsePointers;

            __tmp____Bah_fnNames[285].n = "parseSerialize";
            __tmp____Bah_fnNames[285].p = parseSerialize;

            __tmp____Bah_fnNames[286].n = "parseReflect";
            __tmp____Bah_fnNames[286].p = parseReflect;

            __tmp____Bah_fnNames[287].n = "parseArrayDecl";
            __tmp____Bah_fnNames[287].p = parseArrayDecl;

            __tmp____Bah_fnNames[288].n = "parseVar";
            __tmp____Bah_fnNames[288].p = parseVar;

            __tmp____Bah_fnNames[289].n = "getCfunctionType";
            __tmp____Bah_fnNames[289].p = getCfunctionType;

            __tmp____Bah_fnNames[290].n = "parseFnHeader";
            __tmp____Bah_fnNames[290].p = parseFnHeader;

            __tmp____Bah_fnNames[291].n = "parseStruct";
            __tmp____Bah_fnNames[291].p = parseStruct;

            __tmp____Bah_fnNames[292].n = "parseDefine";
            __tmp____Bah_fnNames[292].p = parseDefine;

            __tmp____Bah_fnNames[293].n = "parseClib";
            __tmp____Bah_fnNames[293].p = parseClib;

            __tmp____Bah_fnNames[294].n = "parseConst";
            __tmp____Bah_fnNames[294].p = parseConst;

            __tmp____Bah_fnNames[295].n = "parseReturn";
            __tmp____Bah_fnNames[295].p = parseReturn;

            __tmp____Bah_fnNames[296].n = "parseIf";
            __tmp____Bah_fnNames[296].p = parseIf;

            __tmp____Bah_fnNames[297].n = "parseElse";
            __tmp____Bah_fnNames[297].p = parseElse;

            __tmp____Bah_fnNames[298].n = "parseLine";
            __tmp____Bah_fnNames[298].p = parseLine;

            __tmp____Bah_fnNames[299].n = "parseFor";
            __tmp____Bah_fnNames[299].p = parseFor;

            __tmp____Bah_fnNames[300].n = "parseForOp";
            __tmp____Bah_fnNames[300].p = parseForOp;

            __tmp____Bah_fnNames[301].n = "makeEvalFunc";
            __tmp____Bah_fnNames[301].p = makeEvalFunc;

            __tmp____Bah_fnNames[302].n = "parsePreKeyword";
            __tmp____Bah_fnNames[302].p = parsePreKeyword;

            __tmp____Bah_fnNames[303].n = "parseAsync";
            __tmp____Bah_fnNames[303].p = parseAsync;

            __tmp____Bah_fnNames[304].n = "addRCPvars";
            __tmp____Bah_fnNames[304].p = addRCPvars;

            __tmp____Bah_fnNames[305].n = "parseChan";
            __tmp____Bah_fnNames[305].p = parseChan;

            __tmp____Bah_fnNames[306].n = "valueFunc";
            __tmp____Bah_fnNames[306].p = valueFunc;

            __tmp____Bah_fnNames[307].n = "valueStruct";
            __tmp____Bah_fnNames[307].p = valueStruct;

            __tmp____Bah_fnNames[308].n = "valueArr";
            __tmp____Bah_fnNames[308].p = valueArr;

            __tmp____Bah_fnNames[309].n = "valueBool";
            __tmp____Bah_fnNames[309].p = valueBool;

            __tmp____Bah_fnNames[310].n = "valueOper";
            __tmp____Bah_fnNames[310].p = valueOper;

            __tmp____Bah_fnNames[311].n = "valueSendChan";
            __tmp____Bah_fnNames[311].p = valueSendChan;

            __tmp____Bah_fnNames[312].n = "valueChan";
            __tmp____Bah_fnNames[312].p = valueChan;

            __tmp____Bah_fnNames[313].n = "valueTuple";
            __tmp____Bah_fnNames[313].p = valueTuple;

            __tmp____Bah_fnNames[314].n = "isSmallValue";
            __tmp____Bah_fnNames[314].p = isSmallValue;

            __tmp____Bah_fnNames[315].n = "isValue";
            __tmp____Bah_fnNames[315].p = isValue;

            __tmp____Bah_fnNames[316].n = "parseFnDeclare";
            __tmp____Bah_fnNames[316].p = parseFnDeclare;

            __tmp____Bah_fnNames[317].n = "parseCapture";
            __tmp____Bah_fnNames[317].p = parseCapture;

            __tmp____Bah_fnNames[318].n = "declareFunc";
            __tmp____Bah_fnNames[318].p = declareFunc;

            __tmp____Bah_fnNames[319].n = "declareVar";
            __tmp____Bah_fnNames[319].p = declareVar;

            __tmp____Bah_fnNames[320].n = "declareAll";
            __tmp____Bah_fnNames[320].p = declareAll;

            __tmp____Bah_fnNames[321].n = "memErrHandle";
            __tmp____Bah_fnNames[321].p = memErrHandle;

            __tmp____Bah_fnNames[322].n = "main";
            __tmp____Bah_fnNames[322].p = main;

        __Bah_fnNames->data = __tmp____Bah_fnNames;
        __Bah_fnNames->length = 323;
        
    };
    