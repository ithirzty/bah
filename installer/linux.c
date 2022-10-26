//COMPILE WITH: 'gcc -I "/opt/bah/libs/linux/include/" -L "/opt/bah/libs/linux/" ../installer/linux.c -static -O1 -w  -lgc -lpthread -lm'

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
char * r = memoryAlloc(s);
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
if (__builtin_expect(((void *)s==null), 0)) {
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
pthread_mutex_t* id;
};
void mutex__init(struct mutex* this){
this->id = memoryAlloc(sizeof(pthread_mutex_t));
pthread_mutex_init(this->id,0);
};
void mutex__lock(struct mutex* this){
pthread_mutex_lock(this->id);
};
void mutex__unlock(struct mutex* this){
pthread_mutex_unlock(this->id);
};
void mutex__destroy(struct mutex* this){
pthread_mutex_destroy(this->id);
};
struct mutexCondition {
pthread_cond_t id;
};
void mutexCondition__init(struct mutexCondition* this){
pthread_cond_init(&this->id,0);
};
void mutexCondition__wait(struct mutexCondition* this,struct mutex m){
pthread_mutex_t* mid = m.id;
pthread_cond_wait(&this->id,mid);
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
long int backtrace(void * arr,long int l);
void __BAH_panic(char * e,char * line){
if ((__BAH_panic_chan!=null)) {
channel__send(__BAH_panic_chan, e);
return;
}
char** ____BAH_COMPILER_VAR_9 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_9[4] = "\n";____BAH_COMPILER_VAR_9[3] = e;____BAH_COMPILER_VAR_9[2] = "): ";____BAH_COMPILER_VAR_9[1] = line;____BAH_COMPILER_VAR_9[0] = "panic (";char * ____BAH_COMPILER_VAR_10 =__Bah_multiple_concat(____BAH_COMPILER_VAR_9, 5);print(____BAH_COMPILER_VAR_10);
array(void *)* arr = memoryAlloc(sizeof(array(void *)));

arr->length = 0;
arr->elemSize = sizeof(void *);
allocateArray(arr,10);
long int size = backtrace(arr->data,10);
print("Backtrace:\n");
long int min = -1;
long int max = -1;
register long int i = 1;
for (; (i<size); ++i) {
long int p = arr->data[i];
struct __Bah_fnName_mapper closest;
long int dist = -1;
register long int j = 0;
for (; (j<len(__Bah_fnNames)); ++j) {
struct __Bah_fnName_mapper fnn = __Bah_fnNames->data[j];
long int fnp = fnn.p;
if ((fnp<min)||(min==-1)) {
min = fnp;
}
if ((fnp>max)||(max==-1)) {
max = fnp;
}
if ((p>fnp)) {
if ((dist==-1)||(p-fnp<dist)) {
dist = p-fnp;
closest = fnn;
}
}
};
if ((dist==-1)) {
print("\t???\n");
continue;
}
char * status = "";
long int fnp = closest.p;
if ((min==fnp)||(max==fnp)) {
if ((dist>10000)) {
continue;
}
status = "?";
}
char** ____BAH_COMPILER_VAR_11 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_11[4] = " \n";____BAH_COMPILER_VAR_11[3] = status;____BAH_COMPILER_VAR_11[2] = "() ";____BAH_COMPILER_VAR_11[1] = closest.n;____BAH_COMPILER_VAR_11[0] = "\t";char * ____BAH_COMPILER_VAR_12 =__Bah_multiple_concat(____BAH_COMPILER_VAR_11, 5);print(____BAH_COMPILER_VAR_12);
if ((strcmp(closest.n, "main") == 0)) {
break;
}
};
cleanShutDown();
};
char * (*onMemoryError)();
void __Bah_segfault_handle(long int sig){
char * res = "";
if ((onMemoryError!=null)) {
res = onMemoryError();
}
char** ____BAH_COMPILER_VAR_13 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_13[1] = res;____BAH_COMPILER_VAR_13[0] = "Memory error (segfault).\n";char * ____BAH_COMPILER_VAR_14 =__Bah_multiple_concat(____BAH_COMPILER_VAR_13, 2);__BAH_panic(____BAH_COMPILER_VAR_14,"???");
};
char __Bah_init_segfaultHandle(){
signal(SIGSEGV,__Bah_segfault_handle);
return true;
};
char __Bah_init_segfaultHandle_OK;
char recover(char ** s){
__BAH_panic_chan = channel();
char * ____BAH_COMPILER_VAR_15 =channel__receive(__BAH_panic_chan);char * err = ____BAH_COMPILER_VAR_15;
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

    unsigned int ____BAH_COMPILER_VAR_16 = 47;
    __Bah_realocate_arr(a, ____BAH_COMPILER_VAR_16);
    a->data[____BAH_COMPILER_VAR_16] = 46;

    unsigned int ____BAH_COMPILER_VAR_17 = 48;
    __Bah_realocate_arr(a, ____BAH_COMPILER_VAR_17);
    a->data[____BAH_COMPILER_VAR_17] = 46;

    unsigned int ____BAH_COMPILER_VAR_18 = 49;
    __Bah_realocate_arr(a, ____BAH_COMPILER_VAR_18);
    a->data[____BAH_COMPILER_VAR_18] = 46;

    unsigned int ____BAH_COMPILER_VAR_19 = 50;
    __Bah_realocate_arr(a, ____BAH_COMPILER_VAR_19);
    a->data[____BAH_COMPILER_VAR_19] = (char)0;
}
char** ____BAH_COMPILER_VAR_20 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_20[2] = "\"";____BAH_COMPILER_VAR_20[1] = s;____BAH_COMPILER_VAR_20[0] = "\"";char * ____BAH_COMPILER_VAR_21 =__Bah_multiple_concat(____BAH_COMPILER_VAR_20, 3);return ____BAH_COMPILER_VAR_21;
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
struct mapSearchRes {
char found;
void * res;
unsigned int l;
};
struct mapNode {
char * str;
unsigned int strL;
struct mapNode* left;
struct mapNode* right;
void * value;
};
int mapNode__calc(struct mapNode* this,char * s,unsigned int i){
for (; (i<this->strL); ++i) {
if ((s[i]==null)||(this->str[i]!=s[i])) {
break;
}
};
if ((i==this->strL)&&(s[i]==null)) {
return -1;
}
return i;
};
void mapNode__getFast(struct mapNode* this,char * s,int r,struct mapSearchRes* msr){
if ((r==-1)) {
msr->found = true;
msr->res = this;
return;
}
if ((r==0)&&(this->strL!=0)) {
msr->found = false;
msr->res = null;
return;
}
long int lr = 0;
long int rr = 0;
if ((this->left!=null)) {
lr = mapNode__calc(this->left,s,r);
}
if ((this->right!=null)) {
rr = mapNode__calc(this->right,s,r);
}
if ((lr==-1)) {
msr->found = true;
msr->res = this->left;
return;
}
if ((rr==-1)) {
msr->found = true;
msr->res = this->right;
return;
}
if ((lr>r)&&(lr>rr)) {
mapNode__getFast(this->left,s,lr,msr);
return;
}
if ((rr>r)&&(rr>lr)) {
mapNode__getFast(this->right,s,rr,msr);
return;
}
if ((this->left!=null)&&(this->left->strL==this->strL)) {
mapNode__getFast(this->left,s,lr,msr);
if ((msr->l==r)&&(msr->found==false)) {
msr->res = this;
}
return;
}
msr->found = false;
msr->res = this;
msr->l = r;
return;
};
void mapNode__append(struct mapNode* this,char * k,void * e,unsigned int l){
struct mapNode* ____BAH_COMPILER_VAR_22 = memoryAlloc(sizeof(struct mapNode));
____BAH_COMPILER_VAR_22->str = k;
____BAH_COMPILER_VAR_22->strL = strlen(k);
____BAH_COMPILER_VAR_22->value = e;
struct mapNode* ne = ____BAH_COMPILER_VAR_22;
if ((l!=this->strL)) {
struct mapNode* ____BAH_COMPILER_VAR_23 = memoryAlloc(sizeof(struct mapNode));
____BAH_COMPILER_VAR_23->value = this->value;
____BAH_COMPILER_VAR_23->right = this->right;
____BAH_COMPILER_VAR_23->left = this->left;
____BAH_COMPILER_VAR_23->str = this->str;
____BAH_COMPILER_VAR_23->strL = this->strL;
this->right = ____BAH_COMPILER_VAR_23;
this->str = cpstringSubsitute(this->str, 0, l);
this->value = null;
this->strL = l;
this->left = ne;
return;
}
if ((this->left==null)) {
this->left = ne;
return;
}
if ((this->right==null)) {
this->right = ne;
return;
}
struct mapNode* ol = this->left;
struct mapNode* ____BAH_COMPILER_VAR_24 = memoryAlloc(sizeof(struct mapNode));
____BAH_COMPILER_VAR_24->str = this->str;
____BAH_COMPILER_VAR_24->strL = this->strL;
____BAH_COMPILER_VAR_24->value = null;
____BAH_COMPILER_VAR_24->left = ol;
____BAH_COMPILER_VAR_24->right = ne;
this->left = ____BAH_COMPILER_VAR_24;
};
void mapWrapperSetAlgo(void * p,unsigned int nb);
struct mapWrapper {
long int length;
unsigned int algo;
struct mapNode* nodes;
struct mapSearchRes msr;
array(struct mapElem*)* elems;
char changingAlgo;
unsigned long int nbMisses;
unsigned long int nbTotal;
unsigned long int nbDelete;
void (*set)(struct mapWrapper*,char *,void *);
void * (*get)(struct mapWrapper*,char *);
void (*delete)(struct mapWrapper*,char *);
};
void mapWrapper__algoChecks(struct mapWrapper* this){
if ((this->nbDelete<this->length)&&((this->length>=40000)||((double)this->nbMisses/(double)this->nbTotal>=20.0))) {
mapWrapperSetAlgo(this,1);
}
else if ((this->nbDelete>=this->length*2)||(this->length<500)) {
mapWrapperSetAlgo(this,2);
}
};
void mapWrapper__grow(struct mapWrapper* this,long int nb){
long int l = len(this->elems);
register long int i = l;
for (; (i<l+nb); ++i) {

    unsigned int ____BAH_COMPILER_VAR_25 = i;
    __Bah_realocate_arr(this->elems, ____BAH_COMPILER_VAR_25);
    this->elems->data[____BAH_COMPILER_VAR_25] = null;
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

    unsigned int ____BAH_COMPILER_VAR_26 = i;
    __Bah_realocate_arr(this->elems, ____BAH_COMPILER_VAR_26);
    this->elems->data[____BAH_COMPILER_VAR_26] = null;

    unsigned int ____BAH_COMPILER_VAR_27 = j;
    __Bah_realocate_arr(this->elems, ____BAH_COMPILER_VAR_27);
    this->elems->data[____BAH_COMPILER_VAR_27] = e;
break;
}
};
}
};
};
void mapWrapper__set2(struct mapWrapper* this,char * k,void * e){
if ((this->length==0)) {
mapWrapper__grow(this,50);
}
if ((this->length*2>=len(this->elems))) {
mapWrapper__grow(this,this->length);
}
struct mapElem* ____BAH_COMPILER_VAR_28 = memoryAlloc(sizeof(struct mapElem));
____BAH_COMPILER_VAR_28->key = k;
____BAH_COMPILER_VAR_28->val = e;
struct mapElem* elem = ____BAH_COMPILER_VAR_28;
long int ind = __Bah_map_hash(k,len(this->elems));
register long int i = 0;
for (; (i<len(this->elems)); ++i) {
long int j = (i+ind)%len(this->elems);
struct mapElem* ce = this->elems->data[j];
if ((ce==null)) {

    unsigned int ____BAH_COMPILER_VAR_29 = j;
    __Bah_realocate_arr(this->elems, ____BAH_COMPILER_VAR_29);
    this->elems->data[____BAH_COMPILER_VAR_29] = elem;
++this->length;
break;
}
else if ((strcmp(ce->key, k) == 0)) {

    unsigned int ____BAH_COMPILER_VAR_30 = j;
    __Bah_realocate_arr(this->elems, ____BAH_COMPILER_VAR_30);
    this->elems->data[____BAH_COMPILER_VAR_30] = elem;
break;
}
};
this->nbMisses = this->nbMisses+i;
++this->nbTotal;
if ((this->length%1000==0)) {
mapWrapper__algoChecks(this);
}
};
void mapWrapper__delete2(struct mapWrapper* this,char * k){
long int ind = __Bah_map_hash(k,len(this->elems));
register long int i = 0;
for (; (i<len(this->elems)); ++i) {
long int j = (i+ind)%len(this->elems);
struct mapElem* e = this->elems->data[j];
if ((e!=null)&&(strcmp(e->key, k) == 0)) {
this->nbMisses = this->nbMisses+i;
++this->nbTotal;
++this->nbDelete;

    unsigned int ____BAH_COMPILER_VAR_31 = j;
    __Bah_realocate_arr(this->elems, ____BAH_COMPILER_VAR_31);
    this->elems->data[____BAH_COMPILER_VAR_31] = null;
if ((this->length%1000==0)) {
mapWrapper__algoChecks(this);
}
}
};
};
void * mapWrapper__get2(struct mapWrapper* this,char * k){
long int ind = __Bah_map_hash(k,len(this->elems));
register long int i = 0;
for (; (i<len(this->elems)); ++i) {
long int j = (i+ind)%len(this->elems);
struct mapElem* e = this->elems->data[j];
if ((e!=null)&&(strcmp(e->key, k) == 0)) {
this->nbMisses = this->nbMisses+i;
++this->nbTotal;
return e->val;
}
};
return null;
};
void mapWrapper__clearMsr(struct mapWrapper* this){
this->msr.found = false;
this->msr.res = null;
this->msr.l = 0;
};
void * mapWrapper__get1(struct mapWrapper* this,char * k){
mapWrapper__clearMsr(this);
if ((this->nodes==null)) {
return null;
}
mapNode__getFast(this->nodes,k,mapNode__calc(this->nodes,k,0),&this->msr);
if (this->msr.found) {
struct mapNode* n = this->msr.res;
return n->value;
}
return null;
};
void mapWrapper__set1(struct mapWrapper* this,char * k,void * e){
mapWrapper__clearMsr(this);
if ((this->nodes==null)) {
struct mapNode* ____BAH_COMPILER_VAR_32 = memoryAlloc(sizeof(struct mapNode));
____BAH_COMPILER_VAR_32->str = k;
____BAH_COMPILER_VAR_32->strL = strlen(k);
____BAH_COMPILER_VAR_32->value = e;
this->nodes = ____BAH_COMPILER_VAR_32;
this->length = 1;
return;
}
struct mapSearchRes* n = &this->msr;
n->res = null;
n->found = false;
mapNode__getFast(this->nodes,k,mapNode__calc(this->nodes,k,0),&this->msr);
if ((n->res==null)) {
struct mapNode* ____BAH_COMPILER_VAR_33 = memoryAlloc(sizeof(struct mapNode));
____BAH_COMPILER_VAR_33->str = k;
____BAH_COMPILER_VAR_33->strL = strlen(k);
____BAH_COMPILER_VAR_33->value = e;
struct mapNode* ne = ____BAH_COMPILER_VAR_33;
struct mapNode* ____BAH_COMPILER_VAR_34 = memoryAlloc(sizeof(struct mapNode));
____BAH_COMPILER_VAR_34->str = "";
____BAH_COMPILER_VAR_34->strL = 0;
____BAH_COMPILER_VAR_34->left = ne;
____BAH_COMPILER_VAR_34->right = this->nodes;
struct mapNode* nh = ____BAH_COMPILER_VAR_34;
this->nodes = nh;
struct mapNode* nodesP = this->nodes;
++this->length;
return;
}
struct mapNode* nn = n->res;
if ((n->found==true)) {
nn->str = k;
nn->strL = strlen(k);
nn->value = e;
return;
}
++this->length;
mapNode__append(nn,k,e,n->l);
if ((this->length%1000==0)) {
mapWrapper__algoChecks(this);
}
};
void mapWrapper__delete1(struct mapWrapper* this,char * k){
mapWrapper__clearMsr(this);
mapNode__getFast(this->nodes,k,mapNode__calc(this->nodes,k,0),&this->msr);
if (this->msr.found) {
struct mapNode* n = this->msr.res;
n->value = null;
++this->nbDelete;
--this->length;
if ((this->length%1000==0)) {
mapWrapper__algoChecks(this);
}
}
};
void mapWrapper__setAny(struct mapWrapper* this,char * k,void * e,long int s){
void * p = memoryAlloc(s);
memcpy(p,e,s);
this->set(this,k,p);
};
void mapWrapperSetAlgo(void * p,unsigned int nb){
struct mapWrapper* this = p;
if ((nb==this->algo)||(this->changingAlgo==true)) {
return;
}
this->changingAlgo = true;
if ((nb==1)) {
this->set = mapWrapper__set1;
this->get = mapWrapper__get1;
this->delete = mapWrapper__delete1;
this->algo = 1;
this->length = 0;
register long int i = 0;
for (; (i<len(this->elems)); ++i) {
struct mapElem* e = this->elems->data[i];
if ((e!=null)) {
this->set(this,e->key,e->val);
}
};
this->elems = memoryAlloc(sizeof(array(struct mapElem*)));

this->elems->length = 0;
this->elems->elemSize = sizeof(struct mapElem*);
}
else if ((nb==2)) {
this->nbDelete = 0;
mapWrapper__grow(this,this->length);
this->set = mapWrapper__set2;
this->get = mapWrapper__get2;
this->delete = mapWrapper__delete2;
this->algo = 2;
this->length = 0;
struct mapNode* current = this->nodes;
array(struct mapNode*)* stack = memoryAlloc(sizeof(array(struct mapNode*)));

stack->length = 0;
stack->elemSize = sizeof(struct mapNode*);
while ((current!=null)) {
while ((current->left!=null)) {

    unsigned int ____BAH_COMPILER_VAR_35 = len(stack);
    __Bah_realocate_arr(stack, ____BAH_COMPILER_VAR_35);
    stack->data[____BAH_COMPILER_VAR_35] = current;
current = current->left;
};
if ((current->value!=null)) {
this->set(this,current->str,current->value);
}
while ((current->right==null)&&(len(stack)>0)) {
current = stack->data[len(stack)-1];
delete(stack,len(stack)-1);
if ((current->value!=null)) {
this->set(this,current->str,current->value);
}
};
current = current->right;
};
this->nodes = null;
}
this->changingAlgo = false;
};
struct mapWrapper* mapWrapper(){
struct mapWrapper* ____BAH_COMPILER_VAR_36 = memoryAlloc(sizeof(struct mapWrapper));
____BAH_COMPILER_VAR_36->algo = 2;
____BAH_COMPILER_VAR_36->elems = memoryAlloc(sizeof(array(struct mapElem*)));
            ____BAH_COMPILER_VAR_36->elems->length = 0;
            ____BAH_COMPILER_VAR_36->elems->elemSize = sizeof(struct mapElem*);
            ____BAH_COMPILER_VAR_36->nbTotal = 1;
struct mapWrapper* m = ____BAH_COMPILER_VAR_36;
m->algo = 2;
m->set = mapWrapper__set2;
m->get = mapWrapper__get2;
m->delete = mapWrapper__delete2;
mapWrapper__grow(m,50);
return m;
};
void deleteMap(void * m,char * k){
struct mapWrapper* mm = m;
mm->delete(mm,k);
};
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
char * __Bah_iostream_stdinputBuffer;
long int __Bah_iostream_stdinputBufferLength;
char * stdinput(){
char * response = "";
register long int nDataLength = 0;
if ((__Bah_iostream_stdinputBufferLength>0)) {
response = __Bah_iostream_stdinputBuffer;
nDataLength = __Bah_iostream_stdinputBufferLength;
}
else {
char * buff = memoryAlloc(1025);
nDataLength = read((void *)0,buff,1024);
if ((nDataLength<1024)) {
char** ____BAH_COMPILER_VAR_37 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_37[1] = buff;____BAH_COMPILER_VAR_37[0] = response;char * ____BAH_COMPILER_VAR_38 =__Bah_multiple_concat(____BAH_COMPILER_VAR_37, 2);response = ____BAH_COMPILER_VAR_38;
}
else {
while ((nDataLength>0)) {
char** ____BAH_COMPILER_VAR_39 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_39[1] = buff;____BAH_COMPILER_VAR_39[0] = response;char * ____BAH_COMPILER_VAR_40 =__Bah_multiple_concat(____BAH_COMPILER_VAR_39, 2);response = ____BAH_COMPILER_VAR_40;
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
}
if ((response[nDataLength-1]==(char)10)) {
strTrimRight(&response,1);
}
register long int i = 0;
for (; (i<nDataLength); ++i) {
if ((response[i]==(char)10)) {
__Bah_iostream_stdinputBuffer = cpstringSubsitute(response, i+1, strlen(response));
__Bah_iostream_stdinputBufferLength = nDataLength-i;
return cpstringSubsitute(response, 0, i);
}
};
__Bah_iostream_stdinputBuffer = "";
__Bah_iostream_stdinputBufferLength = 0;
return response;
};
void println(char * s){
char** ____BAH_COMPILER_VAR_41 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_41[1] = "\n";____BAH_COMPILER_VAR_41[0] = s;char * ____BAH_COMPILER_VAR_42 =__Bah_multiple_concat(____BAH_COMPILER_VAR_41, 2);write((void *)1,____BAH_COMPILER_VAR_42,strlen(s)+1);
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

    unsigned int ____BAH_COMPILER_VAR_43 = l;
    __Bah_realocate_arr(rarr, ____BAH_COMPILER_VAR_43);
    rarr->data[____BAH_COMPILER_VAR_43] = (char)0;
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
char** ____BAH_COMPILER_VAR_44 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_44[2] = "'.";____BAH_COMPILER_VAR_44[1] = this->name;____BAH_COMPILER_VAR_44[0] = "iostream: warning, auto-closing file: '";char * ____BAH_COMPILER_VAR_45 =__Bah_multiple_concat(____BAH_COMPILER_VAR_44, 3);println(____BAH_COMPILER_VAR_45);
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
struct stat ____BAH_COMPILER_VAR_46 = {};
struct stat sb = ____BAH_COMPILER_VAR_46;
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

    unsigned int ____BAH_COMPILER_VAR_47 = lf;
    __Bah_realocate_arr(files, ____BAH_COMPILER_VAR_47);
    files->data[____BAH_COMPILER_VAR_47] = __STR(file->d_name);
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
if (__builtin_expect((nc==null), 0)) {
__BAH_panic("Error appending to string, possibly due to memory shortage.","/opt/bah/string.bah:95");
}
this->content = nc;
strCatOffset(this->content,this->length,s,sl+1);
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
strCatOffset(this->content,sl,tmpS,this->length+1);
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
struct string ____BAH_COMPILER_VAR_48 = {};
struct string needle = ____BAH_COMPILER_VAR_48;
string__set(&needle,nd);
struct string ____BAH_COMPILER_VAR_49 = {};
struct string repl = ____BAH_COMPILER_VAR_49;
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

    unsigned int ____BAH_COMPILER_VAR_50 = len(buff);
    __Bah_realocate_arr(buff, ____BAH_COMPILER_VAR_50);
    buff->data[____BAH_COMPILER_VAR_50] = string__charAt(this,j+replcBuffSart);
j = j+1;
};
replcBuffLength = 0;
}

    unsigned int ____BAH_COMPILER_VAR_51 = len(buff);
    __Bah_realocate_arr(buff, ____BAH_COMPILER_VAR_51);
    buff->data[____BAH_COMPILER_VAR_51] = c;
}
if ((si==needle.length)) {
replcBuffLength = 0;
register long int ii = 0;
while ((ii<repl.length)) {
long int a = ii;

    unsigned int ____BAH_COMPILER_VAR_52 = len(buff);
    __Bah_realocate_arr(buff, ____BAH_COMPILER_VAR_52);
    buff->data[____BAH_COMPILER_VAR_52] = string__charAt(&repl,ii);
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

    unsigned int ____BAH_COMPILER_VAR_53 = j;
    __Bah_realocate_arr(replbuffStr, ____BAH_COMPILER_VAR_53);
    replbuffStr->data[____BAH_COMPILER_VAR_53] = string__charAt(this,j+replcBuffSart);
j = j+1;
};
char** ____BAH_COMPILER_VAR_54 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_54[1] = arrAsStr(replbuffStr);____BAH_COMPILER_VAR_54[0] = r;char * ____BAH_COMPILER_VAR_55 =__Bah_multiple_concat(____BAH_COMPILER_VAR_54, 2);r = ____BAH_COMPILER_VAR_55;
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
struct string ____BAH_COMPILER_VAR_56 = {};
struct string needle = ____BAH_COMPILER_VAR_56;
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
struct string ____BAH_COMPILER_VAR_57 = {};
struct string r = ____BAH_COMPILER_VAR_57;
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
struct string ____BAH_COMPILER_VAR_58 = {};
struct string a = ____BAH_COMPILER_VAR_58;
string__set(&a,s);
return a;
};
char * intToStr(long int i){
if ((i==0)) {
return "0";
}
char ____BAH_COMPILER_VAR_59[66];char* s = ____BAH_COMPILER_VAR_59;
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
char * ____BAH_COMPILER_VAR_60 =intToStr(i);struct string r = string(____BAH_COMPILER_VAR_60);
return r;
};
char * floatToStr(double f){
char ____BAH_COMPILER_VAR_61[50];char* buff = ____BAH_COMPILER_VAR_61;
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
char * ____BAH_COMPILER_VAR_62 =charToString(c);string__append(&replcBuff,____BAH_COMPILER_VAR_62);
}
else {
if ((sepIndex>0)) {
sepIndex = 0;
char * ____BAH_COMPILER_VAR_63 =charToString(c);string__append(&replcBuff,____BAH_COMPILER_VAR_63);
register long int ii = 0;
while ((ii<replcBuff.length)) {

    unsigned int ____BAH_COMPILER_VAR_64 = len(tmpString);
    __Bah_realocate_arr(tmpString, ____BAH_COMPILER_VAR_64);
    tmpString->data[____BAH_COMPILER_VAR_64] = string__charAt(&replcBuff,ii);
ii = ii+1;
};
string__set(&replcBuff,"");
}
else {

    unsigned int ____BAH_COMPILER_VAR_65 = len(tmpString);
    __Bah_realocate_arr(tmpString, ____BAH_COMPILER_VAR_65);
    tmpString->data[____BAH_COMPILER_VAR_65] = c;
}
}
if ((sepIndex==sep.length)) {
string__set(&replcBuff,"");
struct string* ____BAH_COMPILER_VAR_66 = memoryAlloc(sizeof(struct string));
struct string* elem = ____BAH_COMPILER_VAR_66;
char * ____BAH_COMPILER_VAR_67 =arrToStr(tmpString);string__set(elem,____BAH_COMPILER_VAR_67);
long int lenRes = len(res);

    unsigned int ____BAH_COMPILER_VAR_68 = lenRes;
    __Bah_realocate_arr(res, ____BAH_COMPILER_VAR_68);
    res->data[____BAH_COMPILER_VAR_68] = *elem;
clear(tmpString);
sepIndex = 0;
}
i = i+1;
};
if ((replcBuff.length>0)) {
register long int ii = 0;
while ((ii<replcBuff.length)) {

    unsigned int ____BAH_COMPILER_VAR_69 = len(tmpString);
    __Bah_realocate_arr(tmpString, ____BAH_COMPILER_VAR_69);
    tmpString->data[____BAH_COMPILER_VAR_69] = string__charAt(&replcBuff,ii);
ii = ii+1;
};
}
if ((len(tmpString)>0)) {
struct string* ____BAH_COMPILER_VAR_70 = memoryAlloc(sizeof(struct string));
struct string* elem = ____BAH_COMPILER_VAR_70;
char * ____BAH_COMPILER_VAR_71 =arrToStr(tmpString);string__set(elem,____BAH_COMPILER_VAR_71);
long int lenRes = len(res);

    unsigned int ____BAH_COMPILER_VAR_72 = lenRes;
    __Bah_realocate_arr(res, ____BAH_COMPILER_VAR_72);
    res->data[____BAH_COMPILER_VAR_72] = *elem;
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
char * ____BAH_COMPILER_VAR_73 =string__str(&e);struct string tmpS = string(____BAH_COMPILER_VAR_73);
if ((i!=max)) {
string__append(&tmpS,sep);
}
char * ____BAH_COMPILER_VAR_74 =string__str(&tmpS);string__append(&s,____BAH_COMPILER_VAR_74);
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

    unsigned int ____BAH_COMPILER_VAR_75 = len(ns);
    __Bah_realocate_arr(ns, ____BAH_COMPILER_VAR_75);
    ns->data[____BAH_COMPILER_VAR_75] = c;
i = i+1;
};
char * ____BAH_COMPILER_VAR_76 =arrToStr(ns);return string(____BAH_COMPILER_VAR_76);
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
struct flag* ____BAH_COMPILER_VAR_77 = memoryAlloc(sizeof(struct flag));
struct flag* f = ____BAH_COMPILER_VAR_77;
f->name = name;
f->help = help;
f->type = FLAG_TYPE_CPSTRING;
long int lf = len(this->flags);

    unsigned int ____BAH_COMPILER_VAR_78 = lf;
    __Bah_realocate_arr(this->flags, ____BAH_COMPILER_VAR_78);
    this->flags->data[____BAH_COMPILER_VAR_78] = f;
};
void flags__addBool(struct flags* this,char * name,char * help){
struct flag* ____BAH_COMPILER_VAR_79 = memoryAlloc(sizeof(struct flag));
struct flag* f = ____BAH_COMPILER_VAR_79;
f->name = name;
f->help = help;
f->type = FLAG_TYPE_BOOL;
long int lf = len(this->flags);

    unsigned int ____BAH_COMPILER_VAR_80 = lf;
    __Bah_realocate_arr(this->flags, ____BAH_COMPILER_VAR_80);
    this->flags->data[____BAH_COMPILER_VAR_80] = f;
};
void flags__addInt(struct flags* this,char * name,char * help){
struct flag* ____BAH_COMPILER_VAR_81 = memoryAlloc(sizeof(struct flag));
struct flag* f = ____BAH_COMPILER_VAR_81;
f->name = name;
f->help = help;
f->type = FLAG_TYPE_INT;
long int lf = len(this->flags);

    unsigned int ____BAH_COMPILER_VAR_82 = lf;
    __Bah_realocate_arr(this->flags, ____BAH_COMPILER_VAR_82);
    this->flags->data[____BAH_COMPILER_VAR_82] = f;
};
void flags__addFloat(struct flags* this,char * name,char * help){
struct flag* ____BAH_COMPILER_VAR_83 = memoryAlloc(sizeof(struct flag));
struct flag* f = ____BAH_COMPILER_VAR_83;
f->name = name;
f->help = help;
f->type = FLAG_TYPE_FLOAT;
long int lf = len(this->flags);

    unsigned int ____BAH_COMPILER_VAR_84 = lf;
    __Bah_realocate_arr(this->flags, ____BAH_COMPILER_VAR_84);
    this->flags->data[____BAH_COMPILER_VAR_84] = f;
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
struct flag* ____BAH_COMPILER_VAR_85 = memoryAlloc(sizeof(struct flag));
struct flag* z = ____BAH_COMPILER_VAR_85;
z->isSet = 0;
return z;
};
char * flags__get(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_86 =string(name);struct flag* flag = flags__getFlag(this,____BAH_COMPILER_VAR_86);
return flag->content;
};
long int flags__getInt(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_87 =string(name);struct flag* flag = flags__getFlag(this,____BAH_COMPILER_VAR_87);
if (__builtin_expect((flag->type!=FLAG_TYPE_INT), 0)) {
char** ____BAH_COMPILER_VAR_88 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_88[2] = "' is not int.";____BAH_COMPILER_VAR_88[1] = flag->name;____BAH_COMPILER_VAR_88[0] = "Flag '";char * ____BAH_COMPILER_VAR_89 =__Bah_multiple_concat(____BAH_COMPILER_VAR_88, 3);__BAH_panic(____BAH_COMPILER_VAR_89,"/opt/bah/flags.bah:122");
}
return flag->cont_int;
};
double flags__getFloat(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_90 =string(name);struct flag* flag = flags__getFlag(this,____BAH_COMPILER_VAR_90);
if (__builtin_expect((flag->type!=FLAG_TYPE_FLOAT), 0)) {
char** ____BAH_COMPILER_VAR_91 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_91[2] = "' is not float.";____BAH_COMPILER_VAR_91[1] = flag->name;____BAH_COMPILER_VAR_91[0] = "Flag '";char * ____BAH_COMPILER_VAR_92 =__Bah_multiple_concat(____BAH_COMPILER_VAR_91, 3);__BAH_panic(____BAH_COMPILER_VAR_92,"/opt/bah/flags.bah:132");
}
return flag->cont_float;
};
long int flags__isSet(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_93 =string(name);struct flag* flag = flags__getFlag(this,____BAH_COMPILER_VAR_93);
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
char * ____BAH_COMPILER_VAR_94 =string__str(&argName);currentFlag->cont_int = strToInt(____BAH_COMPILER_VAR_94);
}
else if ((currentFlag->type==FLAG_TYPE_FLOAT)) {
char * ____BAH_COMPILER_VAR_95 =string__str(&argName);currentFlag->cont_float = strToFloat(____BAH_COMPILER_VAR_95);
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
struct timespec ____BAH_COMPILER_VAR_96 = {};
struct timespec ts = ____BAH_COMPILER_VAR_96;
timespec_get(&ts,TIME_UTC);
long int s = ts.tv_sec*1000000000+ts.tv_nsec;
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
struct fileStream ____BAH_COMPILER_VAR_97 = {};
struct fileStream fs = ____BAH_COMPILER_VAR_97;
fileStream__open(&fs,"/dev/urandom","r");
char c = fileStream__getChar(&fs);
fileStream__close(&fs);
long int i = (long int)c;
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
struct rope* ____BAH_COMPILER_VAR_98 = memoryAlloc(sizeof(struct rope));
struct rope* tmp = ____BAH_COMPILER_VAR_98;
tmp->left = this;
tmp->right = root2;
tmp->totalLen = this->totalLen+root2->totalLen;
tmp->str = null;
return tmp;
};
struct rope* createRopeStructure(struct rope* par,char * a,long int l,long int r){
struct rope* ____BAH_COMPILER_VAR_99 = memoryAlloc(sizeof(struct rope));
struct rope* tmp = ____BAH_COMPILER_VAR_99;
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
struct rope* ____BAH_COMPILER_VAR_100 = memoryAlloc(sizeof(struct rope));
struct rope* tmp = ____BAH_COMPILER_VAR_100;
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
char** ____BAH_COMPILER_VAR_101 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_101[1] = " 2>/dev/null";____BAH_COMPILER_VAR_101[0] = cm;char * ____BAH_COMPILER_VAR_102 =__Bah_multiple_concat(____BAH_COMPILER_VAR_101, 2);cm = ____BAH_COMPILER_VAR_102;
}
else {
char** ____BAH_COMPILER_VAR_103 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_103[1] = " 2>&1";____BAH_COMPILER_VAR_103[0] = cm;char * ____BAH_COMPILER_VAR_104 =__Bah_multiple_concat(____BAH_COMPILER_VAR_103, 2);cm = ____BAH_COMPILER_VAR_104;
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
char** ____BAH_COMPILER_VAR_105 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_105[1] = buff;____BAH_COMPILER_VAR_105[0] = res;char * ____BAH_COMPILER_VAR_106 =__Bah_multiple_concat(____BAH_COMPILER_VAR_105, 2);res = ____BAH_COMPILER_VAR_106;
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
char** ____BAH_COMPILER_VAR_107 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_107[1] = " 2>/dev/null";____BAH_COMPILER_VAR_107[0] = cm;char * ____BAH_COMPILER_VAR_108 =__Bah_multiple_concat(____BAH_COMPILER_VAR_107, 2);cm = ____BAH_COMPILER_VAR_108;
}
else {
char** ____BAH_COMPILER_VAR_109 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_109[1] = " 2>&1";____BAH_COMPILER_VAR_109[0] = cm;char * ____BAH_COMPILER_VAR_110 =__Bah_multiple_concat(____BAH_COMPILER_VAR_109, 2);cm = ____BAH_COMPILER_VAR_110;
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
char** ____BAH_COMPILER_VAR_111 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_111[1] = buff;____BAH_COMPILER_VAR_111[0] = response;char * ____BAH_COMPILER_VAR_112 =__Bah_multiple_concat(____BAH_COMPILER_VAR_111, 2);response = ____BAH_COMPILER_VAR_112;
res = fgets(buff,1023,this->handle);
};
this->status = pclose(this->handle);
arr->data=response;
arr->length=strlen(response);
return arr;
};
struct command command(char * s){
struct command ____BAH_COMPILER_VAR_113 = {};
____BAH_COMPILER_VAR_113.error = true;
struct command cmd = ____BAH_COMPILER_VAR_113;
cmd.command = s;
return cmd;
};
long int exec(char * s,__BAH_ARR_TYPE_cpstring args){
long int r;
array(char *)* nArgs = memoryAlloc(sizeof(array(char *)));

nArgs->length = 0;
nArgs->elemSize = sizeof(char *);

    unsigned int ____BAH_COMPILER_VAR_114 = 0;
    __Bah_realocate_arr(nArgs, ____BAH_COMPILER_VAR_114);
    nArgs->data[____BAH_COMPILER_VAR_114] = s;
register long int i = 0;
while ((i<len(args))) {

    unsigned int ____BAH_COMPILER_VAR_115 = i+1;
    __Bah_realocate_arr(nArgs, ____BAH_COMPILER_VAR_115);
    nArgs->data[____BAH_COMPILER_VAR_115] = args->data[i];
i = i+1;
};

    unsigned int ____BAH_COMPILER_VAR_116 = i+2;
    __Bah_realocate_arr(nArgs, ____BAH_COMPILER_VAR_116);
    nArgs->data[____BAH_COMPILER_VAR_116] = (char *)0;
r=execvp(s,nArgs->data);
return r;
};
char * BAH_DIR;
char * BAH_OS;
char * BAH_CC;
#define BAH_VERSION "v1.2 (build 125)"
char debug;
char verboseRuntime;
char isObject;
char isUnsafe;
char isOptimized;
char noticeEnabled;
char RAIIenabled;
char isFixMeEnabled;
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
array(struct variable*)* deletedVars;
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
char processedStr;
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
struct Tok ____BAH_COMPILER_VAR_117 = {};
____BAH_COMPILER_VAR_117.cont = "";
____BAH_COMPILER_VAR_117.ogCont = "";
____BAH_COMPILER_VAR_117.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_117.line = 1;
____BAH_COMPILER_VAR_117.begLine = 1;
____BAH_COMPILER_VAR_117.bahType = "";
struct Tok t = ____BAH_COMPILER_VAR_117;
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
};
char isMinus(char c,char nc){
return (c==45)&&isNumber(nc);
};
void lexerErr(long int line,long int pos,char * msg){
char * lineStr = intToStr(line);
char * posStr = intToStr(pos);
char** ____BAH_COMPILER_VAR_118 = alloca(8 * sizeof(char*));____BAH_COMPILER_VAR_118[7] = msg;____BAH_COMPILER_VAR_118[6] = "\n\e[0m\n";____BAH_COMPILER_VAR_118[5] = posStr;____BAH_COMPILER_VAR_118[4] = ":";____BAH_COMPILER_VAR_118[3] = lineStr;____BAH_COMPILER_VAR_118[2] = ":";____BAH_COMPILER_VAR_118[1] = compilerState.currentFile;____BAH_COMPILER_VAR_118[0] = "\e[1;31m[LEXER-ERROR]\e[0m ";char * ____BAH_COMPILER_VAR_119 =__Bah_multiple_concat(____BAH_COMPILER_VAR_118, 8);println(____BAH_COMPILER_VAR_119);
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

    unsigned int ____BAH_COMPILER_VAR_120 = 0;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_120);
    memory->data[____BAH_COMPILER_VAR_120] = c;
i = i+1;
for (; (i<codeLength); ++i) {
c = s[i];
char pc = s[i-1];
if ((c==(char)34)) {
if ((pc!=(char)92)) {

    unsigned int ____BAH_COMPILER_VAR_121 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_121);
    memory->data[____BAH_COMPILER_VAR_121] = c;
break;
}
}
if ((c==(char)10)) {
lineNb = lineNb+1;
if ((pc!=(char)92)) {

    unsigned int ____BAH_COMPILER_VAR_122 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_122);
    memory->data[____BAH_COMPILER_VAR_122] = (char)92;
c = 110;
}
}

    unsigned int ____BAH_COMPILER_VAR_123 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_123);
    memory->data[____BAH_COMPILER_VAR_123] = c;
};

    unsigned int ____BAH_COMPILER_VAR_124 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_124);
    tokens->data[____BAH_COMPILER_VAR_124] = makeToken(pos,lineNb,memory,TOKEN_TYPE_STR);
struct Tok lt = tokens->data[len(tokens)-1];
lt.begLine = begLine;

    unsigned int ____BAH_COMPILER_VAR_125 = len(tokens)-1;
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_125);
    tokens->data[____BAH_COMPILER_VAR_125] = lt;
}
else if (isNumber(c)||isMinus(c,nc)) {

    unsigned int ____BAH_COMPILER_VAR_126 = 0;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_126);
    memory->data[____BAH_COMPILER_VAR_126] = c;
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

    unsigned int ____BAH_COMPILER_VAR_127 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_127);
    memory->data[____BAH_COMPILER_VAR_127] = c;
};
--i;

    unsigned int ____BAH_COMPILER_VAR_128 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_128);
    tokens->data[____BAH_COMPILER_VAR_128] = makeToken(pos,lineNb,memory,currentType);
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

    unsigned int ____BAH_COMPILER_VAR_129 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_129);
    tokens->data[____BAH_COMPILER_VAR_129] = makeToken(i-1,lineNb,memory,TOKEN_TYPE_CHAR);
}
else if ((c==(char)35)) {
long int pos = i;

    unsigned int ____BAH_COMPILER_VAR_130 = 0;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_130);
    memory->data[____BAH_COMPILER_VAR_130] = c;
++i;
for (; (i<codeLength); ++i) {
c = s[i];
if ((isAlphaNumeric(c)==false)) {
break;
}

    unsigned int ____BAH_COMPILER_VAR_131 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_131);
    memory->data[____BAH_COMPILER_VAR_131] = c;
};
--i;

    unsigned int ____BAH_COMPILER_VAR_132 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_132);
    tokens->data[____BAH_COMPILER_VAR_132] = makeToken(pos,lineNb,memory,TOKEN_TYPE_KEYWORD);
}
else if (inArray(c,enclavers)) {

    unsigned int ____BAH_COMPILER_VAR_133 = 0;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_133);
    memory->data[____BAH_COMPILER_VAR_133] = c;

    unsigned int ____BAH_COMPILER_VAR_134 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_134);
    tokens->data[____BAH_COMPILER_VAR_134] = makeToken(i,lineNb,memory,TOKEN_TYPE_ENCL);
}
else if (inArray(c,syntaxes)) {
if ((c==60)) {
long int pos = i;
char isCast = false;

    unsigned int ____BAH_COMPILER_VAR_135 = 0;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_135);
    memory->data[____BAH_COMPILER_VAR_135] = c;
++i;
for (; (i<codeLength); ++i) {
c = s[i];
if ((c==62)) {
isCast = true;

    unsigned int ____BAH_COMPILER_VAR_136 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_136);
    memory->data[____BAH_COMPILER_VAR_136] = c;
break;
}
if ((isAlphaNumeric(c)==false)&&(c!=42)&&(c!=58)&&(c!=95)&&(c!=91)&&(c!=93)) {
break;
}

    unsigned int ____BAH_COMPILER_VAR_137 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_137);
    memory->data[____BAH_COMPILER_VAR_137] = c;
};
if ((isCast==true)) {

    unsigned int ____BAH_COMPILER_VAR_138 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_138);
    tokens->data[____BAH_COMPILER_VAR_138] = makeToken(pos,lineNb,memory,TOKEN_TYPE_CAST);
continue;
}
i = pos;
c = 60;
clear(memory);
}

    unsigned int ____BAH_COMPILER_VAR_139 = 0;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_139);
    memory->data[____BAH_COMPILER_VAR_139] = c;
long int pos = i;
++i;
char fc = c;
for (; (i<codeLength); ++i) {
c = s[i];
char ____BAH_COMPILER_VAR_141 =c;
        char ____BAH_COMPILER_VAR_140 = 0;
        for(int i=syntaxes->length-1; i!=-1;i--) {
            if (syntaxes->data[i] == ____BAH_COMPILER_VAR_141) {
                ____BAH_COMPILER_VAR_140=1;
                break;
            };
        }
        if ((____BAH_COMPILER_VAR_140==false)) {
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

    unsigned int ____BAH_COMPILER_VAR_142 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_142);
    memory->data[____BAH_COMPILER_VAR_142] = c;
};
--i;

    unsigned int ____BAH_COMPILER_VAR_143 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_143);
    tokens->data[____BAH_COMPILER_VAR_143] = makeToken(pos,lineNb,memory,TOKEN_TYPE_SYNTAX);
}
else if ((c==46)) {

    unsigned int ____BAH_COMPILER_VAR_144 = 0;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_144);
    memory->data[____BAH_COMPILER_VAR_144] = c;

    unsigned int ____BAH_COMPILER_VAR_145 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_145);
    tokens->data[____BAH_COMPILER_VAR_145] = makeToken(i,lineNb,memory,TOKEN_TYPE_SEP);
}
else if (isAlphaNumeric(c)||(c==95)) {

    unsigned int ____BAH_COMPILER_VAR_146 = 0;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_146);
    memory->data[____BAH_COMPILER_VAR_146] = c;
long int pos = i;
++i;
for (; (i<codeLength); ++i) {
c = s[i];
if ((isAlphaNumeric(c)==false)) {
if ((c!=95)) {
if ((c==62)) {
char lc = memory->data[len(memory)-1];
if ((lc==45)) {

    unsigned int ____BAH_COMPILER_VAR_147 = len(memory)-1;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_147);
    memory->data[____BAH_COMPILER_VAR_147] = (char)0;
--i;
break;
}
}
break;
}
}

    unsigned int ____BAH_COMPILER_VAR_148 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_148);
    memory->data[____BAH_COMPILER_VAR_148] = c;
};
--i;
tokenType currentType = TOKEN_TYPE_VAR;
char * memstr = arrAsStr(memory);
char * ____BAH_COMPILER_VAR_150 =memstr;
        char ____BAH_COMPILER_VAR_149 = 0;
        for(int i=keywords->length-1; i!=-1;i--) {
            if (keywords->data[i] != 0 && strcmp(keywords->data[i], ____BAH_COMPILER_VAR_150) == 0) {
                ____BAH_COMPILER_VAR_149=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_149) {
currentType = TOKEN_TYPE_KEYWORD;
}

    unsigned int ____BAH_COMPILER_VAR_151 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_151);
    tokens->data[____BAH_COMPILER_VAR_151] = makeToken(pos,lineNb,memory,currentType);
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
char * ____BAH_COMPILER_VAR_152 =splitStringBefore(*n,".");struct string res = string(____BAH_COMPILER_VAR_152);
return res;
}
if (string__count(n,"->")) {
char * ____BAH_COMPILER_VAR_153 =splitStringBefore(*n,"->");struct string res = string(____BAH_COMPILER_VAR_153);
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
struct structMemb* ____BAH_COMPILER_VAR_154 = memoryAlloc(sizeof(struct structMemb));
____BAH_COMPILER_VAR_154->name = "";
____BAH_COMPILER_VAR_154->type = "";
____BAH_COMPILER_VAR_154->constVal = "";
____BAH_COMPILER_VAR_154->from = "";
____BAH_COMPILER_VAR_154->def = "";
struct structMemb* sm = ____BAH_COMPILER_VAR_154;
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
char** ____BAH_COMPILER_VAR_155 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_155[2] = name;____BAH_COMPILER_VAR_155[1] = "__";____BAH_COMPILER_VAR_155[0] = s->name;char * ____BAH_COMPILER_VAR_156 =__Bah_multiple_concat(____BAH_COMPILER_VAR_155, 3);struct func* fn = searchFunc(____BAH_COMPILER_VAR_156,elems,true);
if ((fn!=null)) {
return fn;
}
register long int i = 0;
for (; (i<len(s->members)); ++i) {
if ((strcmp(s->members->data[i]->name, name) == 0)) {
struct string ____BAH_COMPILER_VAR_157 =string(s->members->data[i]->type);fn = parseFnType(____BAH_COMPILER_VAR_157);
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
char** ____BAH_COMPILER_VAR_158 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_158[2] = ")*";____BAH_COMPILER_VAR_158[1] = t;____BAH_COMPILER_VAR_158[0] = "array(";char * ____BAH_COMPILER_VAR_159 =__Bah_multiple_concat(____BAH_COMPILER_VAR_158, 3);char * r = ____BAH_COMPILER_VAR_159;
return string(r);
}
string__replace(&tp,"!","*");
struct string ctp = tp;
string__replace(&ctp,"*","");
if (string__hasPrefix(&tp,"tuple:")) {
array(struct string)* parts = splitString(tp,":");
char * ____BAH_COMPILER_VAR_160 =string__str(&parts->data[2]);
                struct string ____BAH_COMPILER_VAR_161 = getCType(____BAH_COMPILER_VAR_160,elems);
                char** ____BAH_COMPILER_VAR_162 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_162[1] = "*";____BAH_COMPILER_VAR_162[0] = string__str(&____BAH_COMPILER_VAR_161);char * ____BAH_COMPILER_VAR_163 =__Bah_multiple_concat(____BAH_COMPILER_VAR_162, 2);string__set(&tp,____BAH_COMPILER_VAR_163);
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
char** ____BAH_COMPILER_VAR_164 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_164[1] = "*";____BAH_COMPILER_VAR_164[0] = cpstringSubsitute(a, 0, strlen(a)-1);char * ____BAH_COMPILER_VAR_165 =__Bah_multiple_concat(____BAH_COMPILER_VAR_164, 2);a = ____BAH_COMPILER_VAR_165;
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
char * ____BAH_COMPILER_VAR_167 =a;
        char ____BAH_COMPILER_VAR_166 = 0;
        for(int i=intTypes->length-1; i!=-1;i--) {
            if (intTypes->data[i] != 0 && strcmp(intTypes->data[i], ____BAH_COMPILER_VAR_167) == 0) {
                ____BAH_COMPILER_VAR_166=1;
                break;
            };
        }
        char * ____BAH_COMPILER_VAR_169 =b;
        char ____BAH_COMPILER_VAR_168 = 0;
        for(int i=intTypes->length-1; i!=-1;i--) {
            if (intTypes->data[i] != 0 && strcmp(intTypes->data[i], ____BAH_COMPILER_VAR_169) == 0) {
                ____BAH_COMPILER_VAR_168=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_166&&____BAH_COMPILER_VAR_168) {
return true;
}
char * ____BAH_COMPILER_VAR_171 =a;
        char ____BAH_COMPILER_VAR_170 = 0;
        for(int i=floatTypes->length-1; i!=-1;i--) {
            if (floatTypes->data[i] != 0 && strcmp(floatTypes->data[i], ____BAH_COMPILER_VAR_171) == 0) {
                ____BAH_COMPILER_VAR_170=1;
                break;
            };
        }
        char * ____BAH_COMPILER_VAR_173 =b;
        char ____BAH_COMPILER_VAR_172 = 0;
        for(int i=floatTypes->length-1; i!=-1;i--) {
            if (floatTypes->data[i] != 0 && strcmp(floatTypes->data[i], ____BAH_COMPILER_VAR_173) == 0) {
                ____BAH_COMPILER_VAR_172=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_170&&____BAH_COMPILER_VAR_172) {
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
struct reflectElement ____BAH_COMPILER_VAR_174 = {};
____BAH_COMPILER_VAR_174.structLayout = memoryAlloc(sizeof(array(struct reflectElement)));
            ____BAH_COMPILER_VAR_174.structLayout->length = 0;
            ____BAH_COMPILER_VAR_174.structLayout->elemSize = sizeof(struct reflectElement);
            struct reflectElement re = ____BAH_COMPILER_VAR_174;
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
struct reflectElement ____BAH_COMPILER_VAR_175 = {};
____BAH_COMPILER_VAR_175.structLayout = memoryAlloc(sizeof(array(struct reflectElement)));
            ____BAH_COMPILER_VAR_175.structLayout->length = 0;
            ____BAH_COMPILER_VAR_175.structLayout->elemSize = sizeof(struct reflectElement);
            struct reflectElement ns = ____BAH_COMPILER_VAR_175;
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

    unsigned int ____BAH_COMPILER_VAR_176 = j-1;
    __Bah_realocate_arr(nk, ____BAH_COMPILER_VAR_176);
    nk->data[____BAH_COMPILER_VAR_176] = c;
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

    unsigned int ____BAH_COMPILER_VAR_177 = i;
    __Bah_realocate_arr(arr, ____BAH_COMPILER_VAR_177);
    arr->data[____BAH_COMPILER_VAR_177] = strToInt(c->content);
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

    unsigned int ____BAH_COMPILER_VAR_178 = i;
    __Bah_realocate_arr(arr, ____BAH_COMPILER_VAR_178);
    arr->data[____BAH_COMPILER_VAR_178] = strToFloat(c->content);
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

    unsigned int ____BAH_COMPILER_VAR_179 = i;
    __Bah_realocate_arr(arr, ____BAH_COMPILER_VAR_179);
    arr->data[____BAH_COMPILER_VAR_179] = c->content;
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

    unsigned int ____BAH_COMPILER_VAR_180 = i;
    __Bah_realocate_arr(arr, ____BAH_COMPILER_VAR_180);
    arr->data[____BAH_COMPILER_VAR_180] = ne;
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

    unsigned int ____BAH_COMPILER_VAR_181 = j;
    __Bah_realocate_arr(ae->structLayout, ____BAH_COMPILER_VAR_181);
    ae->structLayout->data[____BAH_COMPILER_VAR_181] = m;
};
json_scan_inner(c,*ae,true);
struct string k = string(c->key);
string__trimLeft(&k,1);
string__trimRight(&k,1);
if (strCount(ae->type,"*")||(strcmp(ae->type, "ptr") == 0)||(strcmp(ae->type, "cpstring") == 0)||strHasPrefix(ae->type,"[]")||strHasPrefix(ae->type,"map:")) {
struct mapWrapper* m = *p;
char * ____BAH_COMPILER_VAR_182 =string__str(&k);m->set(m,____BAH_COMPILER_VAR_182,v);
}
else {
struct mapWrapper* m = *p;
char * ____BAH_COMPILER_VAR_183 =string__str(&k);m->set(m,____BAH_COMPILER_VAR_183,&v);
}
};
}
};
struct jsonElement* parseJson(char * s){
struct jsonElement* ____BAH_COMPILER_VAR_184 = memoryAlloc(sizeof(struct jsonElement));
____BAH_COMPILER_VAR_184->children = memoryAlloc(sizeof(array(struct jsonElement*)));
            ____BAH_COMPILER_VAR_184->children->length = 0;
            ____BAH_COMPILER_VAR_184->children->elemSize = sizeof(struct jsonElement*);
            struct jsonElement* jsonElem = ____BAH_COMPILER_VAR_184;
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

    unsigned int ____BAH_COMPILER_VAR_185 = len(ns)-1;
    __Bah_realocate_arr(ns, ____BAH_COMPILER_VAR_185);
    ns->data[____BAH_COMPILER_VAR_185] = c;
}
else {

    unsigned int ____BAH_COMPILER_VAR_186 = len(ns);
    __Bah_realocate_arr(ns, ____BAH_COMPILER_VAR_186);
    ns->data[____BAH_COMPILER_VAR_186] = c;
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

    unsigned int ____BAH_COMPILER_VAR_187 = len(currentElem);
    __Bah_realocate_arr(currentElem, ____BAH_COMPILER_VAR_187);
    currentElem->data[____BAH_COMPILER_VAR_187] = c;
i = i+1;
continue;
}
if ((c==44)) {
char * ____BAH_COMPILER_VAR_188 =arrToStr(currentElem);struct jsonElement* child = parseJson(____BAH_COMPILER_VAR_188);
if ((child!=null)) {

    unsigned int ____BAH_COMPILER_VAR_189 = elemIndex;
    __Bah_realocate_arr(jsonElem->children, ____BAH_COMPILER_VAR_189);
    jsonElem->children->data[____BAH_COMPILER_VAR_189] = child;
}
clear(currentElem);
elemIndex = elemIndex+1;
}
else {
if (isSpace(c)) {
i = i+1;
continue;
}

    unsigned int ____BAH_COMPILER_VAR_190 = len(currentElem);
    __Bah_realocate_arr(currentElem, ____BAH_COMPILER_VAR_190);
    currentElem->data[____BAH_COMPILER_VAR_190] = c;
}
i = i+1;
};
char * ____BAH_COMPILER_VAR_191 =arrToStr(currentElem);struct jsonElement* child = parseJson(____BAH_COMPILER_VAR_191);
if ((child!=null)) {

    unsigned int ____BAH_COMPILER_VAR_192 = elemIndex;
    __Bah_realocate_arr(jsonElem->children, ____BAH_COMPILER_VAR_192);
    jsonElem->children->data[____BAH_COMPILER_VAR_192] = child;
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

    unsigned int ____BAH_COMPILER_VAR_193 = len(currentElem);
    __Bah_realocate_arr(currentElem, ____BAH_COMPILER_VAR_193);
    currentElem->data[____BAH_COMPILER_VAR_193] = c;
}
else {

    unsigned int ____BAH_COMPILER_VAR_194 = len(currentKey);
    __Bah_realocate_arr(currentKey, ____BAH_COMPILER_VAR_194);
    currentKey->data[____BAH_COMPILER_VAR_194] = c;
}
i = i+1;
continue;
}
if ((c==58)) {
isVal = 1;
}
else if ((c==44)) {
char * ____BAH_COMPILER_VAR_195 =arrToStr(currentElem);struct jsonElement* elem = parseJson(____BAH_COMPILER_VAR_195);
if ((elem!=null)) {
elem->key = arrToStr(currentKey);

    unsigned int ____BAH_COMPILER_VAR_196 = elemIndex;
    __Bah_realocate_arr(jsonElem->children, ____BAH_COMPILER_VAR_196);
    jsonElem->children->data[____BAH_COMPILER_VAR_196] = elem;
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

    unsigned int ____BAH_COMPILER_VAR_197 = len(currentElem);
    __Bah_realocate_arr(currentElem, ____BAH_COMPILER_VAR_197);
    currentElem->data[____BAH_COMPILER_VAR_197] = c;
}
else {

    unsigned int ____BAH_COMPILER_VAR_198 = len(currentKey);
    __Bah_realocate_arr(currentKey, ____BAH_COMPILER_VAR_198);
    currentKey->data[____BAH_COMPILER_VAR_198] = c;
}
}
i = i+1;
};
char * ____BAH_COMPILER_VAR_199 =arrToStr(currentElem);struct jsonElement* elem = parseJson(____BAH_COMPILER_VAR_199);
if ((elem!=null)) {
elem->key = arrToStr(currentKey);

    unsigned int ____BAH_COMPILER_VAR_200 = elemIndex;
    __Bah_realocate_arr(jsonElem->children, ____BAH_COMPILER_VAR_200);
    jsonElem->children->data[____BAH_COMPILER_VAR_200] = elem;
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
if (((unsigned char)c==(unsigned char)195)) {

    unsigned int ____BAH_COMPILER_VAR_201 = len(r);
    __Bah_realocate_arr(r, ____BAH_COMPILER_VAR_201);
    r->data[____BAH_COMPILER_VAR_201] = c;

    unsigned int ____BAH_COMPILER_VAR_202 = len(r);
    __Bah_realocate_arr(r, ____BAH_COMPILER_VAR_202);
    r->data[____BAH_COMPILER_VAR_202] = a->data[i+1];
++i;
}
++i;
continue;
}
if ((c==(char)34)) {

    unsigned int ____BAH_COMPILER_VAR_203 = len(r);
    __Bah_realocate_arr(r, ____BAH_COMPILER_VAR_203);
    r->data[____BAH_COMPILER_VAR_203] = (char)92;
}
else if ((c==(char)10)) {

    unsigned int ____BAH_COMPILER_VAR_204 = len(r);
    __Bah_realocate_arr(r, ____BAH_COMPILER_VAR_204);
    r->data[____BAH_COMPILER_VAR_204] = (char)92;

    unsigned int ____BAH_COMPILER_VAR_205 = len(r);
    __Bah_realocate_arr(r, ____BAH_COMPILER_VAR_205);
    r->data[____BAH_COMPILER_VAR_205] = 110;
i = i+1;
continue;
}
else if ((c==(char)13)) {

    unsigned int ____BAH_COMPILER_VAR_206 = len(r);
    __Bah_realocate_arr(r, ____BAH_COMPILER_VAR_206);
    r->data[____BAH_COMPILER_VAR_206] = (char)92;

    unsigned int ____BAH_COMPILER_VAR_207 = len(r);
    __Bah_realocate_arr(r, ____BAH_COMPILER_VAR_207);
    r->data[____BAH_COMPILER_VAR_207] = 114;
i = i+1;
continue;
}

    unsigned int ____BAH_COMPILER_VAR_208 = len(r);
    __Bah_realocate_arr(r, ____BAH_COMPILER_VAR_208);
    r->data[____BAH_COMPILER_VAR_208] = c;
i = i+1;
};

    unsigned int ____BAH_COMPILER_VAR_209 = len(r);
    __Bah_realocate_arr(r, ____BAH_COMPILER_VAR_209);
    r->data[____BAH_COMPILER_VAR_209] = null;
return arrAsStr(r);
};
char * oldToJson__inner(struct reflectElement e,char isMember,long int tabs){
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
char** ____BAH_COMPILER_VAR_210 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_210[1] = "\t";____BAH_COMPILER_VAR_210[0] = tabsStr;char * ____BAH_COMPILER_VAR_211 =__Bah_multiple_concat(____BAH_COMPILER_VAR_210, 2);tabsStr = ____BAH_COMPILER_VAR_211;
i = i+1;
};
char * s = "{\n";
i = 0;
while ((i<len(e.structLayout))) {
struct reflectElement m = e.structLayout->data[i];
i = i+1;
m.value = reflectElement__calculateOffset(&m,e.value);
if ((i<len(e.structLayout))) {
char** ____BAH_COMPILER_VAR_212 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_212[6] = ",\n";____BAH_COMPILER_VAR_212[5] = oldToJson__inner(m,true,tabs);____BAH_COMPILER_VAR_212[4] = "\": ";____BAH_COMPILER_VAR_212[3] = m.name;____BAH_COMPILER_VAR_212[2] = "\"";____BAH_COMPILER_VAR_212[1] = tabsStr;____BAH_COMPILER_VAR_212[0] = s;char * ____BAH_COMPILER_VAR_213 =__Bah_multiple_concat(____BAH_COMPILER_VAR_212, 7);s = ____BAH_COMPILER_VAR_213;
}
else {
char** ____BAH_COMPILER_VAR_214 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_214[6] = "\n";____BAH_COMPILER_VAR_214[5] = oldToJson__inner(m,true,tabs);____BAH_COMPILER_VAR_214[4] = "\": ";____BAH_COMPILER_VAR_214[3] = m.name;____BAH_COMPILER_VAR_214[2] = "\"";____BAH_COMPILER_VAR_214[1] = tabsStr;____BAH_COMPILER_VAR_214[0] = s;char * ____BAH_COMPILER_VAR_215 =__Bah_multiple_concat(____BAH_COMPILER_VAR_214, 7);s = ____BAH_COMPILER_VAR_215;
}
};
tabs = tabs-1;
tabsStr = "";
i = 0;
while ((i<tabs)) {
char** ____BAH_COMPILER_VAR_216 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_216[1] = "\t";____BAH_COMPILER_VAR_216[0] = tabsStr;char * ____BAH_COMPILER_VAR_217 =__Bah_multiple_concat(____BAH_COMPILER_VAR_216, 2);tabsStr = ____BAH_COMPILER_VAR_217;
i = i+1;
};
char** ____BAH_COMPILER_VAR_218 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_218[2] = "}";____BAH_COMPILER_VAR_218[1] = tabsStr;____BAH_COMPILER_VAR_218[0] = s;char * ____BAH_COMPILER_VAR_219 =__Bah_multiple_concat(____BAH_COMPILER_VAR_218, 3);s = ____BAH_COMPILER_VAR_219;
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
char** ____BAH_COMPILER_VAR_220 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_220[2] = "\"";____BAH_COMPILER_VAR_220[1] = jsonEscapeStr(s);____BAH_COMPILER_VAR_220[0] = "\"";char * ____BAH_COMPILER_VAR_221 =__Bah_multiple_concat(____BAH_COMPILER_VAR_220, 3);return ____BAH_COMPILER_VAR_221;
}
else {
char ** sp = e.value;
char * s = *sp;
char** ____BAH_COMPILER_VAR_222 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_222[2] = "\"";____BAH_COMPILER_VAR_222[1] = jsonEscapeStr(s);____BAH_COMPILER_VAR_222[0] = "\"";char * ____BAH_COMPILER_VAR_223 =__Bah_multiple_concat(____BAH_COMPILER_VAR_222, 3);return ____BAH_COMPILER_VAR_223;
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
char** ____BAH_COMPILER_VAR_224 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_224[1] = intToStr(arr->data[i]);____BAH_COMPILER_VAR_224[0] = s;char * ____BAH_COMPILER_VAR_225 =__Bah_multiple_concat(____BAH_COMPILER_VAR_224, 2);s = ____BAH_COMPILER_VAR_225;
i = i+1;
if ((i<len(arr))) {
char** ____BAH_COMPILER_VAR_226 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_226[1] = ",";____BAH_COMPILER_VAR_226[0] = s;char * ____BAH_COMPILER_VAR_227 =__Bah_multiple_concat(____BAH_COMPILER_VAR_226, 2);s = ____BAH_COMPILER_VAR_227;
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
char** ____BAH_COMPILER_VAR_228 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_228[1] = floatToStr(arr->data[i]);____BAH_COMPILER_VAR_228[0] = s;char * ____BAH_COMPILER_VAR_229 =__Bah_multiple_concat(____BAH_COMPILER_VAR_228, 2);s = ____BAH_COMPILER_VAR_229;
i = i+1;
if ((i<len(arr))) {
char** ____BAH_COMPILER_VAR_230 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_230[1] = ",";____BAH_COMPILER_VAR_230[0] = s;char * ____BAH_COMPILER_VAR_231 =__Bah_multiple_concat(____BAH_COMPILER_VAR_230, 2);s = ____BAH_COMPILER_VAR_231;
}
};
}
else if ((strcmp(ae->type, "cpstring") == 0)) {
array(char *)* arr = memoryAlloc(sizeof(array(char *)));

arr->length = 0;
arr->elemSize = sizeof(char *);
void ** arrPtr = e.value;
arr = *arrPtr;
char** ____BAH_COMPILER_VAR_232 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_232[1] = "\n";____BAH_COMPILER_VAR_232[0] = s;char * ____BAH_COMPILER_VAR_233 =__Bah_multiple_concat(____BAH_COMPILER_VAR_232, 2);s = ____BAH_COMPILER_VAR_233;
register long int i = 0;
while ((i<len(arr))) {
char** ____BAH_COMPILER_VAR_234 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_234[3] = "\"";____BAH_COMPILER_VAR_234[2] = jsonEscapeStr(arr->data[i]);____BAH_COMPILER_VAR_234[1] = "\"";____BAH_COMPILER_VAR_234[0] = s;char * ____BAH_COMPILER_VAR_235 =__Bah_multiple_concat(____BAH_COMPILER_VAR_234, 4);s = ____BAH_COMPILER_VAR_235;
i = i+1;
if ((i<len(arr))) {
char** ____BAH_COMPILER_VAR_236 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_236[1] = ",\n";____BAH_COMPILER_VAR_236[0] = s;char * ____BAH_COMPILER_VAR_237 =__Bah_multiple_concat(____BAH_COMPILER_VAR_236, 2);s = ____BAH_COMPILER_VAR_237;
}
else {
char** ____BAH_COMPILER_VAR_238 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_238[1] = "\n";____BAH_COMPILER_VAR_238[0] = s;char * ____BAH_COMPILER_VAR_239 =__Bah_multiple_concat(____BAH_COMPILER_VAR_238, 2);s = ____BAH_COMPILER_VAR_239;
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

    unsigned int ____BAH_COMPILER_VAR_240 = j;
    __Bah_realocate_arr(ae->structLayout, ____BAH_COMPILER_VAR_240);
    ae->structLayout->data[____BAH_COMPILER_VAR_240] = m;
j = j+1;
};
char** ____BAH_COMPILER_VAR_241 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_241[1] = oldToJson__inner(*ae,false,tabs);____BAH_COMPILER_VAR_241[0] = s;char * ____BAH_COMPILER_VAR_242 =__Bah_multiple_concat(____BAH_COMPILER_VAR_241, 2);s = ____BAH_COMPILER_VAR_242;
i = i+1;
if ((i<len(arr))) {
char** ____BAH_COMPILER_VAR_243 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_243[1] = ",\n";____BAH_COMPILER_VAR_243[0] = s;char * ____BAH_COMPILER_VAR_244 =__Bah_multiple_concat(____BAH_COMPILER_VAR_243, 2);s = ____BAH_COMPILER_VAR_244;
}
else {
char** ____BAH_COMPILER_VAR_245 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_245[1] = "\n";____BAH_COMPILER_VAR_245[0] = s;char * ____BAH_COMPILER_VAR_246 =__Bah_multiple_concat(____BAH_COMPILER_VAR_245, 2);s = ____BAH_COMPILER_VAR_246;
}
};
}
char** ____BAH_COMPILER_VAR_247 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_247[1] = "]";____BAH_COMPILER_VAR_247[0] = s;char * ____BAH_COMPILER_VAR_248 =__Bah_multiple_concat(____BAH_COMPILER_VAR_247, 2);s = ____BAH_COMPILER_VAR_248;
return s;
}
return "0";
};
char * oldToJson(struct reflectElement e){
return oldToJson__inner(e,false,0);
};
char * toJson(struct reflectElement e){
register long int l = strlen(e.type);
if (__builtin_expect((e.isArray==false)&&(e.type[l-1]!=42), 0)) {
char** ____BAH_COMPILER_VAR_249 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_249[6] = ").";____BAH_COMPILER_VAR_249[5] = e.name;____BAH_COMPILER_VAR_249[4] = " but a pointer is required, try: toJson(&";____BAH_COMPILER_VAR_249[3] = e.type;____BAH_COMPILER_VAR_249[2] = ") of type ";____BAH_COMPILER_VAR_249[1] = e.name;____BAH_COMPILER_VAR_249[0] = "toJson(";char * ____BAH_COMPILER_VAR_250 =__Bah_multiple_concat(____BAH_COMPILER_VAR_249, 7);__BAH_panic(____BAH_COMPILER_VAR_250,"/opt/bah/json.bah:605");
}
if ((e.isArray==false)) {
long int ol = l;
for (; (l>=2)&&(e.type[l-1]==42)&&(e.type[l-2]==42); --l) {
if ((e.value==null)) {
return "0";
}
void ** v = e.value;
e.value = *v;
};
if ((l!=ol)) {
e.type = cpstringSubsitute(e.type, 0, l);
}
}
if ((e.value==null)) {
return "0";
}
if ((e.isStruct==true)) {
char * s = "{";
register long int i = 0;
for (; (i<len(e.structLayout)); ++i) {
struct reflectElement m = e.structLayout->data[i];
if ((m.type[strlen(m.type)-1]!=42)&&(m.isArray==false)) {
char** ____BAH_COMPILER_VAR_251 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_251[1] = "*";____BAH_COMPILER_VAR_251[0] = m.type;char * ____BAH_COMPILER_VAR_252 =__Bah_multiple_concat(____BAH_COMPILER_VAR_251, 2);m.type = ____BAH_COMPILER_VAR_252;
}
m.value = reflectElement__calculateOffset(&m,e.value);
char** ____BAH_COMPILER_VAR_253 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_253[3] = toJson(m);____BAH_COMPILER_VAR_253[2] = "\": ";____BAH_COMPILER_VAR_253[1] = m.name;____BAH_COMPILER_VAR_253[0] = "\"";char * ____BAH_COMPILER_VAR_254 =__Bah_multiple_concat(____BAH_COMPILER_VAR_253, 4);char** ____BAH_COMPILER_VAR_255 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_255[1] = ____BAH_COMPILER_VAR_254;____BAH_COMPILER_VAR_255[0] = s;char * ____BAH_COMPILER_VAR_256 =__Bah_multiple_concat(____BAH_COMPILER_VAR_255, 2);s = ____BAH_COMPILER_VAR_256;
if ((i+1<len(e.structLayout))) {
char** ____BAH_COMPILER_VAR_257 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_257[1] = ", ";____BAH_COMPILER_VAR_257[0] = s;char * ____BAH_COMPILER_VAR_258 =__Bah_multiple_concat(____BAH_COMPILER_VAR_257, 2);s = ____BAH_COMPILER_VAR_258;
}
};
char** ____BAH_COMPILER_VAR_259 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_259[1] = "}";____BAH_COMPILER_VAR_259[0] = s;char * ____BAH_COMPILER_VAR_260 =__Bah_multiple_concat(____BAH_COMPILER_VAR_259, 2);s = ____BAH_COMPILER_VAR_260;
return s;
}
if ((e.isArray==true)) {
char * s = "[";
void ** arrp = e.value;
array(void *)* arr = (array(void *)*)*arrp;
if ((arr==null)) {
return "[]";
}
void * base = cArr(arr);
l = len(arr);
long int es = arr->elemSize;
struct reflectElement* ae = e.arrayElem;
if ((ae->type[strlen(ae->type)-1]!=42)&&(ae->isArray==false)) {
char** ____BAH_COMPILER_VAR_261 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_261[1] = "*";____BAH_COMPILER_VAR_261[0] = ae->type;char * ____BAH_COMPILER_VAR_262 =__Bah_multiple_concat(____BAH_COMPILER_VAR_261, 2);ae->type = ____BAH_COMPILER_VAR_262;
}
register long int i = 0;
for (; (i<l); ++i) {
struct reflectElement m = *ae;
m.value = (void *)((long int)base+es*i);
char** ____BAH_COMPILER_VAR_263 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_263[1] = toJson(m);____BAH_COMPILER_VAR_263[0] = s;char * ____BAH_COMPILER_VAR_264 =__Bah_multiple_concat(____BAH_COMPILER_VAR_263, 2);s = ____BAH_COMPILER_VAR_264;
if ((i+1<l)) {
char** ____BAH_COMPILER_VAR_265 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_265[1] = ", ";____BAH_COMPILER_VAR_265[0] = s;char * ____BAH_COMPILER_VAR_266 =__Bah_multiple_concat(____BAH_COMPILER_VAR_265, 2);s = ____BAH_COMPILER_VAR_266;
}
};
char** ____BAH_COMPILER_VAR_267 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_267[1] = "]";____BAH_COMPILER_VAR_267[0] = s;char * ____BAH_COMPILER_VAR_268 =__Bah_multiple_concat(____BAH_COMPILER_VAR_267, 2);s = ____BAH_COMPILER_VAR_268;
return s;
}
if ((strcmp(e.type, "int*") == 0)||(strcmp(e.type, "int32*") == 0)) {
long int* j = e.value;
return intToStr(*j);
}
if ((strcmp(e.type, "cpstring*") == 0)) {
char ** s = e.value;
if ((s==null)) {
return "\"\"";
}
char** ____BAH_COMPILER_VAR_269 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_269[2] = "\"";____BAH_COMPILER_VAR_269[1] = jsonEscapeStr(*s);____BAH_COMPILER_VAR_269[0] = "\"";char * ____BAH_COMPILER_VAR_270 =__Bah_multiple_concat(____BAH_COMPILER_VAR_269, 3);return ____BAH_COMPILER_VAR_270;
}
if ((strcmp(e.type, "float*") == 0)||(strcmp(e.type, "float32*") == 0)) {
double* f = e.value;
return floatToStr(*f);
}
if ((strcmp(e.type, "uint*") == 0)||(strcmp(e.type, "uint32*") == 0)) {
unsigned long int* uj = e.value;
return intToStr(*uj);
}
if ((strcmp(e.type, "char*") == 0)) {
char* c = e.value;
char** ____BAH_COMPILER_VAR_271 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_271[2] = "\"";____BAH_COMPILER_VAR_271[1] = charToString(*c);____BAH_COMPILER_VAR_271[0] = "\"";char * ____BAH_COMPILER_VAR_272 =__Bah_multiple_concat(____BAH_COMPILER_VAR_271, 3);return ____BAH_COMPILER_VAR_272;
}
if ((strcmp(e.type, "bool*") == 0)) {
char* b = e.value;
if ((*b==true)) {
return "true";
}
return "false";
}
char** ____BAH_COMPILER_VAR_273 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_273[2] = "\"";____BAH_COMPILER_VAR_273[1] = e.type;____BAH_COMPILER_VAR_273[0] = "\"invalid: ";char * ____BAH_COMPILER_VAR_274 =__Bah_multiple_concat(____BAH_COMPILER_VAR_273, 3);return ____BAH_COMPILER_VAR_274;
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
char ** ____BAH_COMPILER_VAR_275 = &name;
struct reflectElement ____BAH_COMPILER_VAR_276 = __reflect(____BAH_COMPILER_VAR_275, sizeof(char **), "cpstring*", "&name", 0, 0, 0, 0, 0);
char** ____BAH_COMPILER_VAR_277 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_277[8] = "\n    },\n    ";____BAH_COMPILER_VAR_277[7] = toJson(e);____BAH_COMPILER_VAR_277[6] = "\",\n        \"element\": ";____BAH_COMPILER_VAR_277[5] = intToStr(line);____BAH_COMPILER_VAR_277[4] = ":";____BAH_COMPILER_VAR_277[3] = compilerState.currentFile;____BAH_COMPILER_VAR_277[2] = ",\n        \"path\": \"";____BAH_COMPILER_VAR_277[1] = toJson(____BAH_COMPILER_VAR_276);____BAH_COMPILER_VAR_277[0] = "\n    {\n        \"name\": ";char * ____BAH_COMPILER_VAR_278 =__Bah_multiple_concat(____BAH_COMPILER_VAR_277, 9);println(____BAH_COMPILER_VAR_278);
};
void debugError(char * name,long int line,long int from,long int to,struct reflectElement e){
if ((debug==false)) {
return;
}
char ** ____BAH_COMPILER_VAR_279 = &name;
struct reflectElement ____BAH_COMPILER_VAR_280 = __reflect(____BAH_COMPILER_VAR_279, sizeof(char **), "cpstring*", "&name", 0, 0, 0, 0, 0);
char** ____BAH_COMPILER_VAR_281 = alloca(13 * sizeof(char*));____BAH_COMPILER_VAR_281[12] = "\n    },\n    ";____BAH_COMPILER_VAR_281[11] = toJson(e);____BAH_COMPILER_VAR_281[10] = "\n        ],\n        \"element\": ";____BAH_COMPILER_VAR_281[9] = intToStr(to);____BAH_COMPILER_VAR_281[8] = ",\n            ";____BAH_COMPILER_VAR_281[7] = intToStr(from);____BAH_COMPILER_VAR_281[6] = "\",\n        \"range\": [\n            ";____BAH_COMPILER_VAR_281[5] = intToStr(line);____BAH_COMPILER_VAR_281[4] = ":";____BAH_COMPILER_VAR_281[3] = compilerState.currentFile;____BAH_COMPILER_VAR_281[2] = ",\n        \"path\": \"";____BAH_COMPILER_VAR_281[1] = toJson(____BAH_COMPILER_VAR_280);____BAH_COMPILER_VAR_281[0] = "\n    {\n        \"name\": ";char * ____BAH_COMPILER_VAR_282 =__Bah_multiple_concat(____BAH_COMPILER_VAR_281, 13);println(____BAH_COMPILER_VAR_282);
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
struct variable* ____BAH_COMPILER_VAR_283 = v;
char ** ____BAH_COMPILER_VAR_285 = (char **)((char*)(____BAH_COMPILER_VAR_283) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_286 = __reflect(____BAH_COMPILER_VAR_285, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_287 = (char **)((char*)(____BAH_COMPILER_VAR_283) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_288 = __reflect(____BAH_COMPILER_VAR_287, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_289 = (char*)((char*)(____BAH_COMPILER_VAR_283) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_290 = __reflect(____BAH_COMPILER_VAR_289, sizeof(char), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_291 = (char **)((char*)(____BAH_COMPILER_VAR_283) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_292 = __reflect(____BAH_COMPILER_VAR_291, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_293 = (char*)((char*)(____BAH_COMPILER_VAR_283) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_294 = __reflect(____BAH_COMPILER_VAR_293, sizeof(char), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_295 = (char **)((char*)(____BAH_COMPILER_VAR_283) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_296 = __reflect(____BAH_COMPILER_VAR_295, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
void ** ____BAH_COMPILER_VAR_297 = (void **)((char*)(____BAH_COMPILER_VAR_283) + offsetof(struct variable, declScope));
struct reflectElement ____BAH_COMPILER_VAR_298 = __reflect(____BAH_COMPILER_VAR_297, sizeof(void *), "ptr", "declScope", 0, 0, 0, 0, offsetof(struct variable, declScope));
char* ____BAH_COMPILER_VAR_299 = (char*)((char*)(____BAH_COMPILER_VAR_283) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_300 = __reflect(____BAH_COMPILER_VAR_299, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));
struct rope** ____BAH_COMPILER_VAR_301 = (struct rope**)((char*)(____BAH_COMPILER_VAR_283) + offsetof(struct variable, declRope));
void ** ____BAH_COMPILER_VAR_303 = (void **)((char*)(____BAH_COMPILER_VAR_301) + offsetof(struct rope, left));
struct reflectElement ____BAH_COMPILER_VAR_304 = __reflect(____BAH_COMPILER_VAR_303, sizeof(void *), "ptr", "left", 0, 0, 0, 0, offsetof(struct rope, left));
void ** ____BAH_COMPILER_VAR_305 = (void **)((char*)(____BAH_COMPILER_VAR_301) + offsetof(struct rope, right));
struct reflectElement ____BAH_COMPILER_VAR_306 = __reflect(____BAH_COMPILER_VAR_305, sizeof(void *), "ptr", "right", 0, 0, 0, 0, offsetof(struct rope, right));
char ** ____BAH_COMPILER_VAR_307 = (char **)((char*)(____BAH_COMPILER_VAR_301) + offsetof(struct rope, str));
struct reflectElement ____BAH_COMPILER_VAR_308 = __reflect(____BAH_COMPILER_VAR_307, sizeof(char *), "cpstring", "str", 0, 0, 0, 0, offsetof(struct rope, str));
int* ____BAH_COMPILER_VAR_309 = (int*)((char*)(____BAH_COMPILER_VAR_301) + offsetof(struct rope, lCount));
struct reflectElement ____BAH_COMPILER_VAR_310 = __reflect(____BAH_COMPILER_VAR_309, sizeof(int), "int32", "lCount", 0, 0, 0, 0, offsetof(struct rope, lCount));
int* ____BAH_COMPILER_VAR_311 = (int*)((char*)(____BAH_COMPILER_VAR_301) + offsetof(struct rope, len));
struct reflectElement ____BAH_COMPILER_VAR_312 = __reflect(____BAH_COMPILER_VAR_311, sizeof(int), "int32", "len", 0, 0, 0, 0, offsetof(struct rope, len));
int* ____BAH_COMPILER_VAR_313 = (int*)((char*)(____BAH_COMPILER_VAR_301) + offsetof(struct rope, totalLen));
struct reflectElement ____BAH_COMPILER_VAR_314 = __reflect(____BAH_COMPILER_VAR_313, sizeof(int), "int32", "totalLen", 0, 0, 0, 0, offsetof(struct rope, totalLen));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_302 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_302->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_302->length = 6;
        ____BAH_COMPILER_VAR_302->data = memoryAlloc(____BAH_COMPILER_VAR_302->length * ____BAH_COMPILER_VAR_302->elemSize);
        ____BAH_COMPILER_VAR_302->data[0] = ____BAH_COMPILER_VAR_304;
____BAH_COMPILER_VAR_302->data[1] = ____BAH_COMPILER_VAR_306;
____BAH_COMPILER_VAR_302->data[2] = ____BAH_COMPILER_VAR_308;
____BAH_COMPILER_VAR_302->data[3] = ____BAH_COMPILER_VAR_310;
____BAH_COMPILER_VAR_302->data[4] = ____BAH_COMPILER_VAR_312;
____BAH_COMPILER_VAR_302->data[5] = ____BAH_COMPILER_VAR_314;
struct reflectElement ____BAH_COMPILER_VAR_315 = __reflect(____BAH_COMPILER_VAR_301, sizeof(struct rope), "rope*", "declRope", 0, 0, 1, ____BAH_COMPILER_VAR_302, offsetof(struct variable, declRope));
char* ____BAH_COMPILER_VAR_316 = (char*)((char*)(____BAH_COMPILER_VAR_283) + offsetof(struct variable, canBeNull));
struct reflectElement ____BAH_COMPILER_VAR_317 = __reflect(____BAH_COMPILER_VAR_316, sizeof(char), "bool", "canBeNull", 0, 0, 0, 0, offsetof(struct variable, canBeNull));
char* ____BAH_COMPILER_VAR_318 = (char*)((char*)(____BAH_COMPILER_VAR_283) + offsetof(struct variable, canBeReg));
struct reflectElement ____BAH_COMPILER_VAR_319 = __reflect(____BAH_COMPILER_VAR_318, sizeof(char), "bool", "canBeReg", 0, 0, 0, 0, offsetof(struct variable, canBeReg));
char* ____BAH_COMPILER_VAR_320 = (char*)((char*)(____BAH_COMPILER_VAR_283) + offsetof(struct variable, isReg));
struct reflectElement ____BAH_COMPILER_VAR_321 = __reflect(____BAH_COMPILER_VAR_320, sizeof(char), "bool", "isReg", 0, 0, 0, 0, offsetof(struct variable, isReg));
void ** ____BAH_COMPILER_VAR_322 = (void **)((char*)(____BAH_COMPILER_VAR_283) + offsetof(struct variable, lastSet));
struct reflectElement ____BAH_COMPILER_VAR_323 = __reflect(____BAH_COMPILER_VAR_322, sizeof(void *), "ptr", "lastSet", 0, 0, 0, 0, offsetof(struct variable, lastSet));
char* ____BAH_COMPILER_VAR_324 = (char*)((char*)(____BAH_COMPILER_VAR_283) + offsetof(struct variable, isArg));
struct reflectElement ____BAH_COMPILER_VAR_325 = __reflect(____BAH_COMPILER_VAR_324, sizeof(char), "bool", "isArg", 0, 0, 0, 0, offsetof(struct variable, isArg));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_284 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_284->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_284->length = 14;
        ____BAH_COMPILER_VAR_284->data = memoryAlloc(____BAH_COMPILER_VAR_284->length * ____BAH_COMPILER_VAR_284->elemSize);
        ____BAH_COMPILER_VAR_284->data[0] = ____BAH_COMPILER_VAR_286;
____BAH_COMPILER_VAR_284->data[1] = ____BAH_COMPILER_VAR_288;
____BAH_COMPILER_VAR_284->data[2] = ____BAH_COMPILER_VAR_290;
____BAH_COMPILER_VAR_284->data[3] = ____BAH_COMPILER_VAR_292;
____BAH_COMPILER_VAR_284->data[4] = ____BAH_COMPILER_VAR_294;
____BAH_COMPILER_VAR_284->data[5] = ____BAH_COMPILER_VAR_296;
____BAH_COMPILER_VAR_284->data[6] = ____BAH_COMPILER_VAR_298;
____BAH_COMPILER_VAR_284->data[7] = ____BAH_COMPILER_VAR_300;
____BAH_COMPILER_VAR_284->data[8] = ____BAH_COMPILER_VAR_315;
____BAH_COMPILER_VAR_284->data[9] = ____BAH_COMPILER_VAR_317;
____BAH_COMPILER_VAR_284->data[10] = ____BAH_COMPILER_VAR_319;
____BAH_COMPILER_VAR_284->data[11] = ____BAH_COMPILER_VAR_321;
____BAH_COMPILER_VAR_284->data[12] = ____BAH_COMPILER_VAR_323;
____BAH_COMPILER_VAR_284->data[13] = ____BAH_COMPILER_VAR_325;
struct reflectElement ____BAH_COMPILER_VAR_326 = __reflect(____BAH_COMPILER_VAR_283, sizeof(struct variable), "variable*", "v", 0, 0, 1, ____BAH_COMPILER_VAR_284, 0);
debugPrint("var_end",line,____BAH_COMPILER_VAR_326);
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
struct fileMap ____BAH_COMPILER_VAR_327 = {};
____BAH_COMPILER_VAR_327.handle = -1;
struct fileMap fm = ____BAH_COMPILER_VAR_327;
char * fileSrcStr = fileMap__open(&fm,compilerState.currentFile);
struct Tok* t = tp;
struct string ffmt = string(format);
if ((strlen(t->ogCont)==0)) {
t->ogCont = t->cont;
}
char** ____BAH_COMPILER_VAR_328 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_328[2] = "'";____BAH_COMPILER_VAR_328[1] = t->ogCont;____BAH_COMPILER_VAR_328[0] = "'";char * ____BAH_COMPILER_VAR_329 =__Bah_multiple_concat(____BAH_COMPILER_VAR_328, 3);string__replace(&ffmt,"{TOKEN}",____BAH_COMPILER_VAR_329);
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

    unsigned int ____BAH_COMPILER_VAR_330 = len(errCont);
    __Bah_realocate_arr(errCont, ____BAH_COMPILER_VAR_330);
    errCont->data[____BAH_COMPILER_VAR_330] = fileSrcStr[i];
};
char** ____BAH_COMPILER_VAR_331 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_331[2] = "\e[1;37m";____BAH_COMPILER_VAR_331[1] = arrToStr(errCont);____BAH_COMPILER_VAR_331[0] = "\e[1;31m";char * ____BAH_COMPILER_VAR_332 =__Bah_multiple_concat(____BAH_COMPILER_VAR_331, 3);array(char)* errTk = strToArr(____BAH_COMPILER_VAR_332);
register long int ii = 0;
for (; (ii<len(errTk)); ++ii) {

    unsigned int ____BAH_COMPILER_VAR_333 = len(line);
    __Bah_realocate_arr(line, ____BAH_COMPILER_VAR_333);
    line->data[____BAH_COMPILER_VAR_333] = errTk->data[ii];
};
--i;
continue;
}

    unsigned int ____BAH_COMPILER_VAR_334 = len(line);
    __Bah_realocate_arr(line, ____BAH_COMPILER_VAR_334);
    line->data[____BAH_COMPILER_VAR_334] = c;
};
fileMap__close(&fm);
str = arrToStr(line);
char** ____BAH_COMPILER_VAR_335 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_335[2] = intToStr(pos);____BAH_COMPILER_VAR_335[1] = ":";____BAH_COMPILER_VAR_335[0] = intToStr(t->line);char * ____BAH_COMPILER_VAR_336 =__Bah_multiple_concat(____BAH_COMPILER_VAR_335, 3);info = ____BAH_COMPILER_VAR_336;
}
if ((debug==true)) {
struct Tok* t = tp;
char * ____BAH_COMPILER_VAR_337 = format;
struct reflectElement ____BAH_COMPILER_VAR_338 = __reflect(____BAH_COMPILER_VAR_337, sizeof(char *), "cpstring", "format", 0, 0, 0, 0, 0);
debugError("error",t->line,pos,pos+strlen(t->ogCont),____BAH_COMPILER_VAR_338);
debugExit();
}
else {
advertiseGeneric();
char** ____BAH_COMPILER_VAR_339 = alloca(8 * sizeof(char*));____BAH_COMPILER_VAR_339[7] = format;____BAH_COMPILER_VAR_339[6] = "\e[0m\n";____BAH_COMPILER_VAR_339[5] = str;____BAH_COMPILER_VAR_339[4] = "\n\e[1;37m\t";____BAH_COMPILER_VAR_339[3] = info;____BAH_COMPILER_VAR_339[2] = ":";____BAH_COMPILER_VAR_339[1] = compilerState.currentFile;____BAH_COMPILER_VAR_339[0] = "\e[1;31m[ERROR]\e[0m ";char * ____BAH_COMPILER_VAR_340 =__Bah_multiple_concat(____BAH_COMPILER_VAR_339, 8);println(____BAH_COMPILER_VAR_340);
}
exit(1);
};
void throwWarning(char * s){
char** ____BAH_COMPILER_VAR_341 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_341[4] = "\e[0m";____BAH_COMPILER_VAR_341[3] = s;____BAH_COMPILER_VAR_341[2] = "\n\e[0m\t";____BAH_COMPILER_VAR_341[1] = compilerState.currentFile;____BAH_COMPILER_VAR_341[0] = "\e[1;33m[WARNING]\e[0m ";char * ____BAH_COMPILER_VAR_342 =__Bah_multiple_concat(____BAH_COMPILER_VAR_341, 5);println(____BAH_COMPILER_VAR_342);
};
void throwWarningLine(char * s,long int l){
char** ____BAH_COMPILER_VAR_343 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_343[6] = "\e[0m";____BAH_COMPILER_VAR_343[5] = s;____BAH_COMPILER_VAR_343[4] = "\n\e[0m\t";____BAH_COMPILER_VAR_343[3] = intToStr(l);____BAH_COMPILER_VAR_343[2] = ":";____BAH_COMPILER_VAR_343[1] = compilerState.currentFile;____BAH_COMPILER_VAR_343[0] = "\e[1;33m[WARNING]\e[0m ";char * ____BAH_COMPILER_VAR_344 =__Bah_multiple_concat(____BAH_COMPILER_VAR_343, 7);println(____BAH_COMPILER_VAR_344);
};
void throwNoticeLine(char * s,long int l){
if ((noticeEnabled==false)) {
return;
}
char** ____BAH_COMPILER_VAR_345 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_345[6] = "\e[0m";____BAH_COMPILER_VAR_345[5] = s;____BAH_COMPILER_VAR_345[4] = "\n\e[0m\t";____BAH_COMPILER_VAR_345[3] = intToStr(l);____BAH_COMPILER_VAR_345[2] = ":";____BAH_COMPILER_VAR_345[1] = compilerState.currentFile;____BAH_COMPILER_VAR_345[0] = "\e[1;36m[NOTICE]\e[0m ";char * ____BAH_COMPILER_VAR_346 =__Bah_multiple_concat(____BAH_COMPILER_VAR_345, 7);println(____BAH_COMPILER_VAR_346);
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
else if (string__hasPrefix(&vt,"tuple:")) {
array(struct string)* parts = splitString(vt,":");
char * ____BAH_COMPILER_VAR_347 =string__str(&parts->data[2]);string__set(&vt,____BAH_COMPILER_VAR_347);
}
else {
string__set(&vt,"char");
}
char * vtstr = string__str(&vt);
struct variable* ____BAH_COMPILER_VAR_348 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_348->name = "";
____BAH_COMPILER_VAR_348->type = "";
____BAH_COMPILER_VAR_348->constVal = "";
____BAH_COMPILER_VAR_348->from = "";
struct variable* nv = ____BAH_COMPILER_VAR_348;
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
struct variable* ____BAH_COMPILER_VAR_349 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_349->name = "";
____BAH_COMPILER_VAR_349->type = "";
____BAH_COMPILER_VAR_349->constVal = "";
____BAH_COMPILER_VAR_349->from = "";
struct variable* nv = ____BAH_COMPILER_VAR_349;
nv->from = memb->from;
nv->name = memb->name;
nv->type = memb->type;
nv->declScope = v->declScope;
nv->name = ogName;
char * r = nv->type;
struct string tcc = string(ogName);
if (string__count(&tcc,"&")) {
char** ____BAH_COMPILER_VAR_350 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_350[1] = "*";____BAH_COMPILER_VAR_350[0] = r;char * ____BAH_COMPILER_VAR_351 =__Bah_multiple_concat(____BAH_COMPILER_VAR_350, 2);r = ____BAH_COMPILER_VAR_351;
}
long int nbUnaries = string__count(&tcc,"*");
if ((nbUnaries>0)) {
struct string ct = string(r);
long int pointerLevel = string__count(&ct,"*");
if (__builtin_expect((pointerLevel<nbUnaries), 0)) {
char** ____BAH_COMPILER_VAR_352 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_352[2] = "' because it is not pointer.";____BAH_COMPILER_VAR_352[1] = name;____BAH_COMPILER_VAR_352[0] = "Cannot use '*' on '";char * ____BAH_COMPILER_VAR_353 =__Bah_multiple_concat(____BAH_COMPILER_VAR_352, 3);throwErr(null,____BAH_COMPILER_VAR_353);
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
struct variable* ____BAH_COMPILER_VAR_354 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_354->name = "";
____BAH_COMPILER_VAR_354->type = "";
____BAH_COMPILER_VAR_354->constVal = "";
____BAH_COMPILER_VAR_354->from = "";
struct variable* nv = ____BAH_COMPILER_VAR_354;
*nv = *v;
char * r = nv->type;
struct string tcc = string(ogName);
if (string__count(&tcc,"&")) {
char** ____BAH_COMPILER_VAR_355 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_355[1] = "*";____BAH_COMPILER_VAR_355[0] = r;char * ____BAH_COMPILER_VAR_356 =__Bah_multiple_concat(____BAH_COMPILER_VAR_355, 2);r = ____BAH_COMPILER_VAR_356;
}
long int nbUnaries = string__count(&tcc,"*");
if ((nbUnaries>0)) {
struct string ct = string(r);
long int pointerLevel = string__count(&ct,"*");
if (__builtin_expect((pointerLevel<nbUnaries), 0)) {
char** ____BAH_COMPILER_VAR_357 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_357[2] = "' because it is not pointer.";____BAH_COMPILER_VAR_357[1] = name;____BAH_COMPILER_VAR_357[0] = "Cannot use '*' on '";char * ____BAH_COMPILER_VAR_358 =__Bah_multiple_concat(____BAH_COMPILER_VAR_357, 3);throwErr(null,____BAH_COMPILER_VAR_358);
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
struct variable* ____BAH_COMPILER_VAR_359 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_359->name = "";
____BAH_COMPILER_VAR_359->type = "";
____BAH_COMPILER_VAR_359->constVal = "";
____BAH_COMPILER_VAR_359->from = "";
struct variable* nv = ____BAH_COMPILER_VAR_359;
nv->name = name;
nv->type = "function(";
register long int j = 0;
while ((j<len(fn->args))) {
struct variable* arg = fn->args->data[j];
char** ____BAH_COMPILER_VAR_360 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_360[1] = arg->type;____BAH_COMPILER_VAR_360[0] = nv->type;char * ____BAH_COMPILER_VAR_361 =__Bah_multiple_concat(____BAH_COMPILER_VAR_360, 2);nv->type = ____BAH_COMPILER_VAR_361;
j = j+1;
if ((j<len(fn->args))) {
char** ____BAH_COMPILER_VAR_362 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_362[1] = ",";____BAH_COMPILER_VAR_362[0] = nv->type;char * ____BAH_COMPILER_VAR_363 =__Bah_multiple_concat(____BAH_COMPILER_VAR_362, 2);nv->type = ____BAH_COMPILER_VAR_363;
}
};
fn->used = true;
char** ____BAH_COMPILER_VAR_364 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_364[2] = fn->returns->type;____BAH_COMPILER_VAR_364[1] = ")";____BAH_COMPILER_VAR_364[0] = nv->type;char * ____BAH_COMPILER_VAR_365 =__Bah_multiple_concat(____BAH_COMPILER_VAR_364, 3);nv->type = ____BAH_COMPILER_VAR_365;
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
char * ____BAH_COMPILER_VAR_366 =string__str(&cont);return getRealVar(____BAH_COMPILER_VAR_366,elems);
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
char** ____BAH_COMPILER_VAR_367 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_367[2] = v->name;____BAH_COMPILER_VAR_367[1] = " ";____BAH_COMPILER_VAR_367[0] = t;char * ____BAH_COMPILER_VAR_368 =__Bah_multiple_concat(____BAH_COMPILER_VAR_367, 3);t = ____BAH_COMPILER_VAR_368;
return t;
};
void isMissingVar(struct Tok* t,struct Elems* elems){
register long int i = 0;
for (; (i<len(elems->deletedVars)); ++i) {
if (__builtin_expect((strcmp(elems->deletedVars->data[i]->name, t->cont) == 0), 0)) {
throwErr(t,"Variable {TOKEN} has reached its end of life.");
}
};
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
isMissingVar(t,elems);
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
struct func* ____BAH_COMPILER_VAR_369 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_369->name = "";
____BAH_COMPILER_VAR_369->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_369->args->length = 0;
            ____BAH_COMPILER_VAR_369->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_369->from = "";
____BAH_COMPILER_VAR_369->file = "";
____BAH_COMPILER_VAR_369->line = 1;
struct func* nf = ____BAH_COMPILER_VAR_369;
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
struct variable* ____BAH_COMPILER_VAR_370 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_370->name = "";
____BAH_COMPILER_VAR_370->type = "";
____BAH_COMPILER_VAR_370->constVal = "";
____BAH_COMPILER_VAR_370->from = "";
struct variable* arg = ____BAH_COMPILER_VAR_370;
char** ____BAH_COMPILER_VAR_371 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_371[1] = intToStr(len(nf->args));____BAH_COMPILER_VAR_371[0] = "arg_";char * ____BAH_COMPILER_VAR_372 =__Bah_multiple_concat(____BAH_COMPILER_VAR_371, 2);arg->name = ____BAH_COMPILER_VAR_372;
while ((j<cvt.length)) {
c = string__charAt(&cvt,j);
if ((c==44)||(c==41)) {
break;
}

    unsigned int ____BAH_COMPILER_VAR_373 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_373);
    memory->data[____BAH_COMPILER_VAR_373] = c;
j = j+1;
};
arg->type = arrToStr(memory);
clear(memory);

    unsigned int ____BAH_COMPILER_VAR_374 = len(nf->args);
    __Bah_realocate_arr(nf->args, ____BAH_COMPILER_VAR_374);
    nf->args->data[____BAH_COMPILER_VAR_374] = arg;
if ((c==41)) {
break;
}
j = j+1;
};
j = j+1;
while ((j<cvt.length)) {
char c = string__charAt(&cvt,j);

    unsigned int ____BAH_COMPILER_VAR_375 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_375);
    memory->data[____BAH_COMPILER_VAR_375] = c;
j = j+1;
};
struct variable* ____BAH_COMPILER_VAR_376 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_376->name = "";
____BAH_COMPILER_VAR_376->type = "";
____BAH_COMPILER_VAR_376->constVal = "";
____BAH_COMPILER_VAR_376->from = "";
nf->returns = ____BAH_COMPILER_VAR_376;
nf->returns->name = "_return";
nf->returns->type = arrToStr(memory);
return nf;
};
struct func* searchFunc(char * name,struct Elems* elems,char inclCurr){
char * ogName = name;
if ((strcmp(name, "noCheck") == 0)) {
struct func* ____BAH_COMPILER_VAR_377 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_377->name = "";
____BAH_COMPILER_VAR_377->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_377->args->length = 0;
            ____BAH_COMPILER_VAR_377->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_377->from = "";
____BAH_COMPILER_VAR_377->file = "";
____BAH_COMPILER_VAR_377->line = 1;
struct func* fn = ____BAH_COMPILER_VAR_377;
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
char * ____BAH_COMPILER_VAR_378 =string__str(&fnName);struct structMemb* memb = searchStructMemb(____BAH_COMPILER_VAR_378,s,elems);
if ((memb==null)) {
return null;
}
name = fnName.content;
char** ____BAH_COMPILER_VAR_379 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_379[2] = name;____BAH_COMPILER_VAR_379[1] = "__";____BAH_COMPILER_VAR_379[0] = memb->from;char * ____BAH_COMPILER_VAR_380 =__Bah_multiple_concat(____BAH_COMPILER_VAR_379, 3);name = ____BAH_COMPILER_VAR_380;
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
struct func* ____BAH_COMPILER_VAR_381 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_381->name = "";
____BAH_COMPILER_VAR_381->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_381->args->length = 0;
            ____BAH_COMPILER_VAR_381->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_381->from = "";
____BAH_COMPILER_VAR_381->file = "";
____BAH_COMPILER_VAR_381->line = 1;
struct func* nf = ____BAH_COMPILER_VAR_381;
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
struct string ____BAH_COMPILER_VAR_382 =string(t->cont);char * fnName = splitStringBefore(____BAH_COMPILER_VAR_382,"(");
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
char** ____BAH_COMPILER_VAR_383 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_383[6] = ";\n";____BAH_COMPILER_VAR_383[5] = m->def;____BAH_COMPILER_VAR_383[4] = " = ";____BAH_COMPILER_VAR_383[3] = m->name;____BAH_COMPILER_VAR_383[2] = sep;____BAH_COMPILER_VAR_383[1] = v->name;____BAH_COMPILER_VAR_383[0] = code;char * ____BAH_COMPILER_VAR_384 =__Bah_multiple_concat(____BAH_COMPILER_VAR_383, 7);code = ____BAH_COMPILER_VAR_384;
}
continue;
}
if ((string__hasPrefix(&cmpt,"[]")==1)) {
string__trimLeft(&cmpt,2);
char * cmptstr = string__str(&cmpt);
struct string elemCType = getCType(cmptstr,elems);
char * elemCTypeStr = string__str(&elemCType);
char** ____BAH_COMPILER_VAR_385 = alloca(17 * sizeof(char*));____BAH_COMPILER_VAR_385[16] = ");\n            ";____BAH_COMPILER_VAR_385[15] = elemCTypeStr;____BAH_COMPILER_VAR_385[14] = "->elemSize = sizeof(";____BAH_COMPILER_VAR_385[13] = m->name;____BAH_COMPILER_VAR_385[12] = sep;____BAH_COMPILER_VAR_385[11] = v->name;____BAH_COMPILER_VAR_385[10] = "->length = 0;\n            ";____BAH_COMPILER_VAR_385[9] = m->name;____BAH_COMPILER_VAR_385[8] = sep;____BAH_COMPILER_VAR_385[7] = v->name;____BAH_COMPILER_VAR_385[6] = ")));\n            ";____BAH_COMPILER_VAR_385[5] = elemCTypeStr;____BAH_COMPILER_VAR_385[4] = " = memoryAlloc(sizeof(array(";____BAH_COMPILER_VAR_385[3] = m->name;____BAH_COMPILER_VAR_385[2] = sep;____BAH_COMPILER_VAR_385[1] = v->name;____BAH_COMPILER_VAR_385[0] = code;char * ____BAH_COMPILER_VAR_386 =__Bah_multiple_concat(____BAH_COMPILER_VAR_385, 17);code = ____BAH_COMPILER_VAR_386;
continue;
}
if ((string__hasPrefix(&cmpt,"map:")==1)) {
string__trimLeft(&cmpt,4);
char** ____BAH_COMPILER_VAR_387 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_387[3] = " = mapWrapper();\n";____BAH_COMPILER_VAR_387[2] = m->name;____BAH_COMPILER_VAR_387[1] = sep;____BAH_COMPILER_VAR_387[0] = v->name;char * ____BAH_COMPILER_VAR_388 =__Bah_multiple_concat(____BAH_COMPILER_VAR_387, 4);char** ____BAH_COMPILER_VAR_389 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_389[1] = ____BAH_COMPILER_VAR_388;____BAH_COMPILER_VAR_389[0] = code;char * ____BAH_COMPILER_VAR_390 =__Bah_multiple_concat(____BAH_COMPILER_VAR_389, 2);code = ____BAH_COMPILER_VAR_390;
continue;
}
if ((string__hasPrefix(&cmpt,"chan:")==1)) {
string__trimLeft(&cmpt,5);
char** ____BAH_COMPILER_VAR_391 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_391[3] = " = channel();\n";____BAH_COMPILER_VAR_391[2] = m->name;____BAH_COMPILER_VAR_391[1] = sep;____BAH_COMPILER_VAR_391[0] = v->name;char * ____BAH_COMPILER_VAR_392 =__Bah_multiple_concat(____BAH_COMPILER_VAR_391, 4);char** ____BAH_COMPILER_VAR_393 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_393[1] = ____BAH_COMPILER_VAR_392;____BAH_COMPILER_VAR_393[0] = code;char * ____BAH_COMPILER_VAR_394 =__Bah_multiple_concat(____BAH_COMPILER_VAR_393, 2);code = ____BAH_COMPILER_VAR_394;
}
};
if ((s->isBinding==false)) {
long int found = 0;
i = 0;
for (; (i<len(s->methods)); ++i) {
struct func* m = s->methods->data[i];
if ((strcmp(m->name, "_init") == 0)) {
char** ____BAH_COMPILER_VAR_395 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_395[6] = ");\n";____BAH_COMPILER_VAR_395[5] = v->name;____BAH_COMPILER_VAR_395[4] = amp;____BAH_COMPILER_VAR_395[3] = "(";____BAH_COMPILER_VAR_395[2] = m->name;____BAH_COMPILER_VAR_395[1] = sep;____BAH_COMPILER_VAR_395[0] = v->name;char * ____BAH_COMPILER_VAR_396 =__Bah_multiple_concat(____BAH_COMPILER_VAR_395, 7);char** ____BAH_COMPILER_VAR_397 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_397[1] = ____BAH_COMPILER_VAR_396;____BAH_COMPILER_VAR_397[0] = NEXT_LINE;char * ____BAH_COMPILER_VAR_398 =__Bah_multiple_concat(____BAH_COMPILER_VAR_397, 2);NEXT_LINE = ____BAH_COMPILER_VAR_398;
++found;
}
else if ((strcmp(m->name, "_end") == 0)) {
if ((strcmp(sep, "->") == 0)) {
char** ____BAH_COMPILER_VAR_399 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_399[6] = ");\n";____BAH_COMPILER_VAR_399[5] = m->name;____BAH_COMPILER_VAR_399[4] = sep;____BAH_COMPILER_VAR_399[3] = v->name;____BAH_COMPILER_VAR_399[2] = ", ";____BAH_COMPILER_VAR_399[1] = v->name;____BAH_COMPILER_VAR_399[0] = "memoryOnEnd(";char * ____BAH_COMPILER_VAR_400 =__Bah_multiple_concat(____BAH_COMPILER_VAR_399, 7);char** ____BAH_COMPILER_VAR_401 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_401[1] = ____BAH_COMPILER_VAR_400;____BAH_COMPILER_VAR_401[0] = code;char * ____BAH_COMPILER_VAR_402 =__Bah_multiple_concat(____BAH_COMPILER_VAR_401, 2);code = ____BAH_COMPILER_VAR_402;
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
char** ____BAH_COMPILER_VAR_403 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_403[1] = intToStr(NB_COMP_VAR);____BAH_COMPILER_VAR_403[0] = "____BAH_COMPILER_VAR_";char * ____BAH_COMPILER_VAR_404 =__Bah_multiple_concat(____BAH_COMPILER_VAR_403, 2);char * name = ____BAH_COMPILER_VAR_404;
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

    unsigned int ____BAH_COMPILER_VAR_405 = i;
    __Bah_realocate_arr(a, ____BAH_COMPILER_VAR_405);
    a->data[____BAH_COMPILER_VAR_405] = (char)c;
};
return arrToStr(a);
};
void makeInit(){
char * name = "__BAH_init";
if ((isObject==true)) {
char** ____BAH_COMPILER_VAR_406 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_406[1] = pathToVarName(compilerState.currentFile);____BAH_COMPILER_VAR_406[0] = name;char * ____BAH_COMPILER_VAR_407 =__Bah_multiple_concat(____BAH_COMPILER_VAR_406, 2);name = ____BAH_COMPILER_VAR_407;
}
char * evals = "";
char** ____BAH_COMPILER_VAR_408 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_408[2] = "] = {";____BAH_COMPILER_VAR_408[1] = intToStr(len(compilerState.evals));____BAH_COMPILER_VAR_408[0] = "volatile struct __eval_binding __tmp__evals_bindings[";char * ____BAH_COMPILER_VAR_409 =__Bah_multiple_concat(____BAH_COMPILER_VAR_408, 3);char * evalsTMPDecl = ____BAH_COMPILER_VAR_409;
register long int i = 0;
for (; (i<len(compilerState.evals)); ++i) {
char * e = compilerState.evals->data[i];
char** ____BAH_COMPILER_VAR_410 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_410[4] = "\n        }";____BAH_COMPILER_VAR_410[3] = e;____BAH_COMPILER_VAR_410[2] = "\",\n            .evalFn = __Bah_eval_";____BAH_COMPILER_VAR_410[1] = e;____BAH_COMPILER_VAR_410[0] = "{\n            .name = \"";char * ____BAH_COMPILER_VAR_411 =__Bah_multiple_concat(____BAH_COMPILER_VAR_410, 5);char** ____BAH_COMPILER_VAR_412 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_412[1] = ____BAH_COMPILER_VAR_411;____BAH_COMPILER_VAR_412[0] = evalsTMPDecl;char * ____BAH_COMPILER_VAR_413 =__Bah_multiple_concat(____BAH_COMPILER_VAR_412, 2);evalsTMPDecl = ____BAH_COMPILER_VAR_413;
if ((i+1!=len(compilerState.evals))) {
char** ____BAH_COMPILER_VAR_414 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_414[1] = ",\n";____BAH_COMPILER_VAR_414[0] = evalsTMPDecl;char * ____BAH_COMPILER_VAR_415 =__Bah_multiple_concat(____BAH_COMPILER_VAR_414, 2);evalsTMPDecl = ____BAH_COMPILER_VAR_415;
}
else {
char** ____BAH_COMPILER_VAR_416 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_416[1] = "};";____BAH_COMPILER_VAR_416[0] = evalsTMPDecl;char * ____BAH_COMPILER_VAR_417 =__Bah_multiple_concat(____BAH_COMPILER_VAR_416, 2);evalsTMPDecl = ____BAH_COMPILER_VAR_417;
}
};
if ((len(compilerState.evals)!=0)) {
char** ____BAH_COMPILER_VAR_418 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_418[2] = ";";____BAH_COMPILER_VAR_418[1] = intToStr(len(compilerState.evals));____BAH_COMPILER_VAR_418[0] = "__evals_bindings = __tmp__evals_bindings; __evals_length = ";char * ____BAH_COMPILER_VAR_419 =__Bah_multiple_concat(____BAH_COMPILER_VAR_418, 3);evals = ____BAH_COMPILER_VAR_419;
}
else {
evalsTMPDecl = "";
}
char** ____BAH_COMPILER_VAR_420 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_420[4] = "() {\n        ";____BAH_COMPILER_VAR_420[3] = name;____BAH_COMPILER_VAR_420[2] = "\n    void __attribute__((optimize(\"O0\"))) ";____BAH_COMPILER_VAR_420[1] = evalsTMPDecl;____BAH_COMPILER_VAR_420[0] = "\n    ";char * ____BAH_COMPILER_VAR_421 =__Bah_multiple_concat(____BAH_COMPILER_VAR_420, 5);char** ____BAH_COMPILER_VAR_422 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_422[2] = "\n    };\n    ";____BAH_COMPILER_VAR_422[1] = evals;____BAH_COMPILER_VAR_422[0] = "\n        ";char * ____BAH_COMPILER_VAR_423 =__Bah_multiple_concat(____BAH_COMPILER_VAR_422, 3);OUTPUT = rope__add(OUTPUT, rope__add(rope(____BAH_COMPILER_VAR_421), rope__add(INIT, rope(____BAH_COMPILER_VAR_423))));
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
char * removeCast(char * s){
register long int i = strlen(s)-1;
for (; (i>=0); --i) {
if ((s[i]==41)) {
s = cpstringSubsitute(s, i+1, strlen(s));
break;
}
};
return s;
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
char** ____BAH_COMPILER_VAR_424 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_424[2] = ");\n";____BAH_COMPILER_VAR_424[1] = v->name;____BAH_COMPILER_VAR_424[0] = "RCP_decr(";char * ____BAH_COMPILER_VAR_425 =__Bah_multiple_concat(____BAH_COMPILER_VAR_424, 3);r = rope__add(r, rope(____BAH_COMPILER_VAR_425));
}
else if (strHasPrefix(v->type,"chan:")) {
char** ____BAH_COMPILER_VAR_426 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_426[2] = ");\n";____BAH_COMPILER_VAR_426[1] = v->name;____BAH_COMPILER_VAR_426[0] = "RCP_decr(";char * ____BAH_COMPILER_VAR_427 =__Bah_multiple_concat(____BAH_COMPILER_VAR_426, 3);r = rope__add(r, rope(____BAH_COMPILER_VAR_427));
}
else {
if (strHasPrefix(v->type,"map:")) {
struct variable* ____BAH_COMPILER_VAR_428 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_428->name = "";
____BAH_COMPILER_VAR_428->type = "";
____BAH_COMPILER_VAR_428->constVal = "";
____BAH_COMPILER_VAR_428->from = "";
struct variable* nv = ____BAH_COMPILER_VAR_428;
*nv = *v;
v = nv;
v->type = "mapWrapper*";
}
char isPointer = isRCPpointerType(v->type);
struct cStruct* s = searchStruct(v->type,elems);
if ((s!=null)&&(s->isBinding==false)) {
if ((isPointer==true)) {
char** ____BAH_COMPILER_VAR_429 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_429[2] = ");\n";____BAH_COMPILER_VAR_429[1] = v->name;____BAH_COMPILER_VAR_429[0] = "RCP_decr(";char * ____BAH_COMPILER_VAR_430 =__Bah_multiple_concat(____BAH_COMPILER_VAR_429, 3);r = rope__add(r, rope(____BAH_COMPILER_VAR_430));
}
else {
char** ____BAH_COMPILER_VAR_431 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_431[4] = "), 1);\n";____BAH_COMPILER_VAR_431[3] = v->name;____BAH_COMPILER_VAR_431[2] = ", sizeof(";____BAH_COMPILER_VAR_431[1] = v->name;____BAH_COMPILER_VAR_431[0] = "RCP_scanStack(&";char * ____BAH_COMPILER_VAR_432 =__Bah_multiple_concat(____BAH_COMPILER_VAR_431, 5);r = rope__add(r, rope(____BAH_COMPILER_VAR_432));
}
}
else if ((isPointer==true)) {
char** ____BAH_COMPILER_VAR_433 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_433[2] = ");\n";____BAH_COMPILER_VAR_433[1] = v->name;____BAH_COMPILER_VAR_433[0] = "RCP_decr(";char * ____BAH_COMPILER_VAR_434 =__Bah_multiple_concat(____BAH_COMPILER_VAR_433, 3);r = rope__add(r, rope(____BAH_COMPILER_VAR_434));
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
char** ____BAH_COMPILER_VAR_435 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_435[4] = "), 0);";____BAH_COMPILER_VAR_435[3] = v->name;____BAH_COMPILER_VAR_435[2] = ", sizeof(";____BAH_COMPILER_VAR_435[1] = v->name;____BAH_COMPILER_VAR_435[0] = "RCP_scanStack(&";char * ____BAH_COMPILER_VAR_436 =__Bah_multiple_concat(____BAH_COMPILER_VAR_435, 5);return rope(____BAH_COMPILER_VAR_436);
}
char** ____BAH_COMPILER_VAR_437 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_437[2] = ");";____BAH_COMPILER_VAR_437[1] = v->name;____BAH_COMPILER_VAR_437[0] = "RCP_incr(";char * ____BAH_COMPILER_VAR_438 =__Bah_multiple_concat(____BAH_COMPILER_VAR_437, 3);return rope(____BAH_COMPILER_VAR_438);
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
struct variable* ____BAH_COMPILER_VAR_439 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_439->name = "";
____BAH_COMPILER_VAR_439->type = "";
____BAH_COMPILER_VAR_439->constVal = "";
____BAH_COMPILER_VAR_439->from = "";
struct variable* av = ____BAH_COMPILER_VAR_439;
av->type = t;
av->declScope = elems;
av->name = genCompilerVar();

    unsigned int ____BAH_COMPILER_VAR_440 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_440);
    elems->vars->data[____BAH_COMPILER_VAR_440] = av;
struct string cType = getCType(av->type,elems);
if (isGlobal()) {
char** ____BAH_COMPILER_VAR_441 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_441[3] = ";";____BAH_COMPILER_VAR_441[2] = av->name;____BAH_COMPILER_VAR_441[1] = " ";____BAH_COMPILER_VAR_441[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_442 =__Bah_multiple_concat(____BAH_COMPILER_VAR_441, 4);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_442));
char** ____BAH_COMPILER_VAR_443 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_443[3] = ";";____BAH_COMPILER_VAR_443[2] = c;____BAH_COMPILER_VAR_443[1] = " =";____BAH_COMPILER_VAR_443[0] = av->name;char * ____BAH_COMPILER_VAR_444 =__Bah_multiple_concat(____BAH_COMPILER_VAR_443, 4);INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_444));
}
else {
char** ____BAH_COMPILER_VAR_445 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_445[5] = ";";____BAH_COMPILER_VAR_445[4] = c;____BAH_COMPILER_VAR_445[3] = " =";____BAH_COMPILER_VAR_445[2] = av->name;____BAH_COMPILER_VAR_445[1] = " ";____BAH_COMPILER_VAR_445[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_446 =__Bah_multiple_concat(____BAH_COMPILER_VAR_445, 6);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_446));
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
char * ____BAH_COMPILER_VAR_448 =currentFn->name;
        char ____BAH_COMPILER_VAR_447 = 0;
        for(int i=noVOfns->length-1; i!=-1;i--) {
            if (noVOfns->data[i] != 0 && strcmp(noVOfns->data[i], ____BAH_COMPILER_VAR_448) == 0) {
                ____BAH_COMPILER_VAR_447=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_447) {
return false;
}
}
return true;
};
struct verboseOutVar verboseOutTransformVar(struct variable* v,char * cont,struct Elems* elems){
struct verboseOutVar ____BAH_COMPILER_VAR_449 = {};
struct verboseOutVar rv = ____BAH_COMPILER_VAR_449;
char * ogCont = cont;
if ((strcmp(v->type, "cpstring") == 0)) {
char** ____BAH_COMPILER_VAR_450 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_450[2] = ")";____BAH_COMPILER_VAR_450[1] = cont;____BAH_COMPILER_VAR_450[0] = "__Bah_safe_string(";char * ____BAH_COMPILER_VAR_451 =__Bah_multiple_concat(____BAH_COMPILER_VAR_450, 3);cont = ____BAH_COMPILER_VAR_451;
}
char** ____BAH_COMPILER_VAR_452 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_452[1] = cont;____BAH_COMPILER_VAR_452[0] = ", ";char * ____BAH_COMPILER_VAR_453 =__Bah_multiple_concat(____BAH_COMPILER_VAR_452, 2);cont = ____BAH_COMPILER_VAR_453;
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
char** ____BAH_COMPILER_VAR_454 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_454[1] = "{";____BAH_COMPILER_VAR_454[0] = ASCII_RESET;char * ____BAH_COMPILER_VAR_455 =__Bah_multiple_concat(____BAH_COMPILER_VAR_454, 2);ct = ____BAH_COMPILER_VAR_455;
cont = "";
register long int i = 0;
for (; (i<len(s->members)); ++i) {
struct variable* m = s->members->data[i];
char** ____BAH_COMPILER_VAR_456 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_456[4] = m->name;____BAH_COMPILER_VAR_456[3] = ".";____BAH_COMPILER_VAR_456[2] = ")";____BAH_COMPILER_VAR_456[1] = ogCont;____BAH_COMPILER_VAR_456[0] = "(";char * ____BAH_COMPILER_VAR_457 =__Bah_multiple_concat(____BAH_COMPILER_VAR_456, 5);struct verboseOutVar mv = verboseOutTransformVar(m,____BAH_COMPILER_VAR_457,elems);
if ((i!=0)) {
char** ____BAH_COMPILER_VAR_458 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_458[1] = ", ";____BAH_COMPILER_VAR_458[0] = ct;char * ____BAH_COMPILER_VAR_459 =__Bah_multiple_concat(____BAH_COMPILER_VAR_458, 2);ct = ____BAH_COMPILER_VAR_459;
}
char** ____BAH_COMPILER_VAR_460 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_460[1] = mv.markup;____BAH_COMPILER_VAR_460[0] = ct;char * ____BAH_COMPILER_VAR_461 =__Bah_multiple_concat(____BAH_COMPILER_VAR_460, 2);ct = ____BAH_COMPILER_VAR_461;
char** ____BAH_COMPILER_VAR_462 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_462[1] = mv.content;____BAH_COMPILER_VAR_462[0] = cont;char * ____BAH_COMPILER_VAR_463 =__Bah_multiple_concat(____BAH_COMPILER_VAR_462, 2);cont = ____BAH_COMPILER_VAR_463;
};
char** ____BAH_COMPILER_VAR_464 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_464[1] = "}";____BAH_COMPILER_VAR_464[0] = ct;char * ____BAH_COMPILER_VAR_465 =__Bah_multiple_concat(____BAH_COMPILER_VAR_464, 2);ct = ____BAH_COMPILER_VAR_465;
}
}
char** ____BAH_COMPILER_VAR_466 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_466[6] = ASCII_RESET;____BAH_COMPILER_VAR_466[5] = ct;____BAH_COMPILER_VAR_466[4] = ASCII_MAGENTA;____BAH_COMPILER_VAR_466[3] = " = ";____BAH_COMPILER_VAR_466[2] = ASCII_RESET;____BAH_COMPILER_VAR_466[1] = v->name;____BAH_COMPILER_VAR_466[0] = ASCII_BLUE;char * ____BAH_COMPILER_VAR_467 =__Bah_multiple_concat(____BAH_COMPILER_VAR_466, 7);rv.markup = ____BAH_COMPILER_VAR_467;
rv.content = cont;
return rv;
};
struct verboseOutVar verboseOutTransformTok(struct Tok* t,struct Elems* elems){
if ((t->type==TOKEN_TYPE_VAR)&&(t->isOper==false)) {
struct variable* v = searchVar(t->cont,elems);
if ((v==null)) {
struct verboseOutVar ____BAH_COMPILER_VAR_468 = {};
struct verboseOutVar rv = ____BAH_COMPILER_VAR_468;
return rv;
}
}
struct variable ____BAH_COMPILER_VAR_469 = {};
____BAH_COMPILER_VAR_469.name = "";
____BAH_COMPILER_VAR_469.type = "";
____BAH_COMPILER_VAR_469.constVal = "";
____BAH_COMPILER_VAR_469.from = "";
____BAH_COMPILER_VAR_469.name = "(value)";
____BAH_COMPILER_VAR_469.type = getTypeFromToken(t,true,elems);
struct variable v = ____BAH_COMPILER_VAR_469;
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
char** ____BAH_COMPILER_VAR_470 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_470[1] = ", ";____BAH_COMPILER_VAR_470[0] = fnArgs;char * ____BAH_COMPILER_VAR_471 =__Bah_multiple_concat(____BAH_COMPILER_VAR_470, 2);fnArgs = ____BAH_COMPILER_VAR_471;
}
struct Tok t = args->data[j];
struct verboseOutVar v = verboseOutTransformVar(a,t.cont,elems);
char** ____BAH_COMPILER_VAR_472 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_472[1] = v.markup;____BAH_COMPILER_VAR_472[0] = fnArgs;char * ____BAH_COMPILER_VAR_473 =__Bah_multiple_concat(____BAH_COMPILER_VAR_472, 2);fnArgs = ____BAH_COMPILER_VAR_473;
char** ____BAH_COMPILER_VAR_474 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_474[1] = v.content;____BAH_COMPILER_VAR_474[0] = fnArgsValues;char * ____BAH_COMPILER_VAR_475 =__Bah_multiple_concat(____BAH_COMPILER_VAR_474, 2);fnArgsValues = ____BAH_COMPILER_VAR_475;
};
char** ____BAH_COMPILER_VAR_476 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_476[2] = intToStr(lineNb);____BAH_COMPILER_VAR_476[1] = ":";____BAH_COMPILER_VAR_476[0] = compilerState.currentFile;char * ____BAH_COMPILER_VAR_477 =__Bah_multiple_concat(____BAH_COMPILER_VAR_476, 3);char * line = ____BAH_COMPILER_VAR_477;
char** ____BAH_COMPILER_VAR_478 = alloca(13 * sizeof(char*));____BAH_COMPILER_VAR_478[12] = ");\n    //\n    ";____BAH_COMPILER_VAR_478[11] = fnArgsValues;____BAH_COMPILER_VAR_478[10] = "\\n\"";____BAH_COMPILER_VAR_478[9] = ASCII_RESET;____BAH_COMPILER_VAR_478[8] = line;____BAH_COMPILER_VAR_478[7] = ASCII_GREEN;____BAH_COMPILER_VAR_478[6] = ") -> ";____BAH_COMPILER_VAR_478[5] = fnArgs;____BAH_COMPILER_VAR_478[4] = "(";____BAH_COMPILER_VAR_478[3] = ASCII_RESET;____BAH_COMPILER_VAR_478[2] = fn->name;____BAH_COMPILER_VAR_478[1] = nameColor;____BAH_COMPILER_VAR_478[0] = "\n    //Verbose Runtime\n        printf(\"[VO] calling: ";char * ____BAH_COMPILER_VAR_479 =__Bah_multiple_concat(____BAH_COMPILER_VAR_478, 13);struct rope* verboseOut = rope(____BAH_COMPILER_VAR_479);
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
char** ____BAH_COMPILER_VAR_480 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_480[1] = nvo.content;____BAH_COMPILER_VAR_480[0] = pvo.content;char * ____BAH_COMPILER_VAR_481 =__Bah_multiple_concat(____BAH_COMPILER_VAR_480, 2);char * values = ____BAH_COMPILER_VAR_481;
char** ____BAH_COMPILER_VAR_482 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_482[2] = intToStr(lineNb);____BAH_COMPILER_VAR_482[1] = ":";____BAH_COMPILER_VAR_482[0] = compilerState.currentFile;char * ____BAH_COMPILER_VAR_483 =__Bah_multiple_concat(____BAH_COMPILER_VAR_482, 3);char * line = ____BAH_COMPILER_VAR_483;
char** ____BAH_COMPILER_VAR_484 = alloca(11 * sizeof(char*));____BAH_COMPILER_VAR_484[10] = ");\n    //\n    ";____BAH_COMPILER_VAR_484[9] = values;____BAH_COMPILER_VAR_484[8] = "\\n\"";____BAH_COMPILER_VAR_484[7] = ASCII_RESET;____BAH_COMPILER_VAR_484[6] = line;____BAH_COMPILER_VAR_484[5] = ASCII_GREEN;____BAH_COMPILER_VAR_484[4] = " -> ";____BAH_COMPILER_VAR_484[3] = nvo.markup;____BAH_COMPILER_VAR_484[2] = " AND ";____BAH_COMPILER_VAR_484[1] = pvo.markup;____BAH_COMPILER_VAR_484[0] = "\n    //Verbose Runtime\n        printf(\"[VO]    oper: ";char * ____BAH_COMPILER_VAR_485 =__Bah_multiple_concat(____BAH_COMPILER_VAR_484, 11);struct rope* verboseOut = rope(____BAH_COMPILER_VAR_485);
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
struct fileStream ____BAH_COMPILER_VAR_486 = {};
struct fileStream fs = ____BAH_COMPILER_VAR_486;
char** ____BAH_COMPILER_VAR_487 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_487[1] = "cache/cache.json";____BAH_COMPILER_VAR_487[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_488 =__Bah_multiple_concat(____BAH_COMPILER_VAR_487, 2);fileStream__open(&fs,____BAH_COMPILER_VAR_488,"r");
if ((fileStream__isValid(&fs)==0)||(fileStream__getSize(&fs)==0)) {
char** ____BAH_COMPILER_VAR_489 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_489[1] = "cache";____BAH_COMPILER_VAR_489[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_490 =__Bah_multiple_concat(____BAH_COMPILER_VAR_489, 2);mkdir(____BAH_COMPILER_VAR_490,S_IRWXU);
char** ____BAH_COMPILER_VAR_491 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_491[1] = "cache/cache.json";____BAH_COMPILER_VAR_491[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_492 =__Bah_multiple_concat(____BAH_COMPILER_VAR_491, 2);fileStream__createFile(&fs,____BAH_COMPILER_VAR_492);
return;
}
if ((fileStream__getSize(&fs)>0)) {
char * ____BAH_COMPILER_VAR_493 =fileStream__readContent(&fs);struct jsonElement* j = parseJson(____BAH_COMPILER_VAR_493);
fileStream__close(&fs);
array(struct cacheFile**)* ____BAH_COMPILER_VAR_494 = &cache;
struct cacheFile*** ____BAH_COMPILER_VAR_495 = 0;
char ** ____BAH_COMPILER_VAR_497 = (char **)((char*)(____BAH_COMPILER_VAR_495) + offsetof(struct cacheFile, file));
struct reflectElement ____BAH_COMPILER_VAR_498 = __reflect(____BAH_COMPILER_VAR_497, sizeof(char *), "cpstring", "file", 0, 0, 0, 0, offsetof(struct cacheFile, file));
long int* ____BAH_COMPILER_VAR_499 = (long int*)((char*)(____BAH_COMPILER_VAR_495) + offsetof(struct cacheFile, last));
struct reflectElement ____BAH_COMPILER_VAR_500 = __reflect(____BAH_COMPILER_VAR_499, sizeof(long int), "int", "last", 0, 0, 0, 0, offsetof(struct cacheFile, last));
char ** ____BAH_COMPILER_VAR_501 = (char **)((char*)(____BAH_COMPILER_VAR_495) + offsetof(struct cacheFile, ver));
struct reflectElement ____BAH_COMPILER_VAR_502 = __reflect(____BAH_COMPILER_VAR_501, sizeof(char *), "cpstring", "ver", 0, 0, 0, 0, offsetof(struct cacheFile, ver));
long int* ____BAH_COMPILER_VAR_503 = (long int*)((char*)(____BAH_COMPILER_VAR_495) + offsetof(struct cacheFile, date));
struct reflectElement ____BAH_COMPILER_VAR_504 = __reflect(____BAH_COMPILER_VAR_503, sizeof(long int), "int", "date", 0, 0, 0, 0, offsetof(struct cacheFile, date));
long int* ____BAH_COMPILER_VAR_505 = (long int*)((char*)(____BAH_COMPILER_VAR_495) + offsetof(struct cacheFile, mem));
struct reflectElement ____BAH_COMPILER_VAR_506 = __reflect(____BAH_COMPILER_VAR_505, sizeof(long int), "int", "mem", 0, 0, 0, 0, offsetof(struct cacheFile, mem));
long int* ____BAH_COMPILER_VAR_507 = (long int*)((char*)(____BAH_COMPILER_VAR_495) + offsetof(struct cacheFile, opti));
struct reflectElement ____BAH_COMPILER_VAR_508 = __reflect(____BAH_COMPILER_VAR_507, sizeof(long int), "int", "opti", 0, 0, 0, 0, offsetof(struct cacheFile, opti));
array(char *)** ____BAH_COMPILER_VAR_509 = (array(char *)**)((char*)(____BAH_COMPILER_VAR_495) + offsetof(struct cacheFile, files));
char ** ____BAH_COMPILER_VAR_510 = 0;
struct reflectElement ____BAH_COMPILER_VAR_511 = __reflect(____BAH_COMPILER_VAR_510, sizeof(char *), "cpstring", "", 0, 0, 0, 0, 0);

        struct reflectElement ____BAH_COMPILER_VAR_512 = ____BAH_COMPILER_VAR_511;
        struct reflectElement ____BAH_COMPILER_VAR_513 = __reflect(____BAH_COMPILER_VAR_509, sizeof(array(char *)*), "[]cpstring", "files", 1, &____BAH_COMPILER_VAR_512, 0, 0, offsetof(struct cacheFile, files));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_496 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_496->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_496->length = 7;
        ____BAH_COMPILER_VAR_496->data = memoryAlloc(____BAH_COMPILER_VAR_496->length * ____BAH_COMPILER_VAR_496->elemSize);
        ____BAH_COMPILER_VAR_496->data[0] = ____BAH_COMPILER_VAR_498;
____BAH_COMPILER_VAR_496->data[1] = ____BAH_COMPILER_VAR_500;
____BAH_COMPILER_VAR_496->data[2] = ____BAH_COMPILER_VAR_502;
____BAH_COMPILER_VAR_496->data[3] = ____BAH_COMPILER_VAR_504;
____BAH_COMPILER_VAR_496->data[4] = ____BAH_COMPILER_VAR_506;
____BAH_COMPILER_VAR_496->data[5] = ____BAH_COMPILER_VAR_508;
____BAH_COMPILER_VAR_496->data[6] = ____BAH_COMPILER_VAR_513;
struct reflectElement ____BAH_COMPILER_VAR_514 = __reflect(____BAH_COMPILER_VAR_495, sizeof(struct cacheFile), "cacheFile**", "", 0, 0, 1, ____BAH_COMPILER_VAR_496, 0);

        struct reflectElement ____BAH_COMPILER_VAR_515 = ____BAH_COMPILER_VAR_514;
        struct reflectElement ____BAH_COMPILER_VAR_516 = __reflect(____BAH_COMPILER_VAR_494, sizeof(array(struct cacheFile**)*), "[]cacheFile**", "&cache", 1, &____BAH_COMPILER_VAR_515, 0, 0, 0);
jsonElement__scan(j,____BAH_COMPILER_VAR_516);
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
struct cacheFile* ____BAH_COMPILER_VAR_517 = memoryAlloc(sizeof(struct cacheFile));
____BAH_COMPILER_VAR_517->files = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_517->files->length = 0;
            ____BAH_COMPILER_VAR_517->files->elemSize = sizeof(char *);
            struct cacheFile* c = ____BAH_COMPILER_VAR_517;
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

    unsigned int ____BAH_COMPILER_VAR_518 = len(cache);
    __Bah_realocate_arr(cache, ____BAH_COMPILER_VAR_518);
    cache->data[____BAH_COMPILER_VAR_518] = c;
};
void writeCache(){
struct fileStream ____BAH_COMPILER_VAR_519 = {};
struct fileStream fs = ____BAH_COMPILER_VAR_519;
char** ____BAH_COMPILER_VAR_520 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_520[1] = "cache/cache.json";____BAH_COMPILER_VAR_520[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_521 =__Bah_multiple_concat(____BAH_COMPILER_VAR_520, 2);fileStream__open(&fs,____BAH_COMPILER_VAR_521,"w");
array(struct cacheFile**)* ____BAH_COMPILER_VAR_522 = &cache;
struct cacheFile*** ____BAH_COMPILER_VAR_523 = 0;
char ** ____BAH_COMPILER_VAR_525 = (char **)((char*)(____BAH_COMPILER_VAR_523) + offsetof(struct cacheFile, file));
struct reflectElement ____BAH_COMPILER_VAR_526 = __reflect(____BAH_COMPILER_VAR_525, sizeof(char *), "cpstring", "file", 0, 0, 0, 0, offsetof(struct cacheFile, file));
long int* ____BAH_COMPILER_VAR_527 = (long int*)((char*)(____BAH_COMPILER_VAR_523) + offsetof(struct cacheFile, last));
struct reflectElement ____BAH_COMPILER_VAR_528 = __reflect(____BAH_COMPILER_VAR_527, sizeof(long int), "int", "last", 0, 0, 0, 0, offsetof(struct cacheFile, last));
char ** ____BAH_COMPILER_VAR_529 = (char **)((char*)(____BAH_COMPILER_VAR_523) + offsetof(struct cacheFile, ver));
struct reflectElement ____BAH_COMPILER_VAR_530 = __reflect(____BAH_COMPILER_VAR_529, sizeof(char *), "cpstring", "ver", 0, 0, 0, 0, offsetof(struct cacheFile, ver));
long int* ____BAH_COMPILER_VAR_531 = (long int*)((char*)(____BAH_COMPILER_VAR_523) + offsetof(struct cacheFile, date));
struct reflectElement ____BAH_COMPILER_VAR_532 = __reflect(____BAH_COMPILER_VAR_531, sizeof(long int), "int", "date", 0, 0, 0, 0, offsetof(struct cacheFile, date));
long int* ____BAH_COMPILER_VAR_533 = (long int*)((char*)(____BAH_COMPILER_VAR_523) + offsetof(struct cacheFile, mem));
struct reflectElement ____BAH_COMPILER_VAR_534 = __reflect(____BAH_COMPILER_VAR_533, sizeof(long int), "int", "mem", 0, 0, 0, 0, offsetof(struct cacheFile, mem));
long int* ____BAH_COMPILER_VAR_535 = (long int*)((char*)(____BAH_COMPILER_VAR_523) + offsetof(struct cacheFile, opti));
struct reflectElement ____BAH_COMPILER_VAR_536 = __reflect(____BAH_COMPILER_VAR_535, sizeof(long int), "int", "opti", 0, 0, 0, 0, offsetof(struct cacheFile, opti));
array(char *)** ____BAH_COMPILER_VAR_537 = (array(char *)**)((char*)(____BAH_COMPILER_VAR_523) + offsetof(struct cacheFile, files));
char ** ____BAH_COMPILER_VAR_538 = 0;
struct reflectElement ____BAH_COMPILER_VAR_539 = __reflect(____BAH_COMPILER_VAR_538, sizeof(char *), "cpstring", "", 0, 0, 0, 0, 0);

        struct reflectElement ____BAH_COMPILER_VAR_540 = ____BAH_COMPILER_VAR_539;
        struct reflectElement ____BAH_COMPILER_VAR_541 = __reflect(____BAH_COMPILER_VAR_537, sizeof(array(char *)*), "[]cpstring", "files", 1, &____BAH_COMPILER_VAR_540, 0, 0, offsetof(struct cacheFile, files));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_524 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_524->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_524->length = 7;
        ____BAH_COMPILER_VAR_524->data = memoryAlloc(____BAH_COMPILER_VAR_524->length * ____BAH_COMPILER_VAR_524->elemSize);
        ____BAH_COMPILER_VAR_524->data[0] = ____BAH_COMPILER_VAR_526;
____BAH_COMPILER_VAR_524->data[1] = ____BAH_COMPILER_VAR_528;
____BAH_COMPILER_VAR_524->data[2] = ____BAH_COMPILER_VAR_530;
____BAH_COMPILER_VAR_524->data[3] = ____BAH_COMPILER_VAR_532;
____BAH_COMPILER_VAR_524->data[4] = ____BAH_COMPILER_VAR_534;
____BAH_COMPILER_VAR_524->data[5] = ____BAH_COMPILER_VAR_536;
____BAH_COMPILER_VAR_524->data[6] = ____BAH_COMPILER_VAR_541;
struct reflectElement ____BAH_COMPILER_VAR_542 = __reflect(____BAH_COMPILER_VAR_523, sizeof(struct cacheFile), "cacheFile**", "", 0, 0, 1, ____BAH_COMPILER_VAR_524, 0);

        struct reflectElement ____BAH_COMPILER_VAR_543 = ____BAH_COMPILER_VAR_542;
        struct reflectElement ____BAH_COMPILER_VAR_544 = __reflect(____BAH_COMPILER_VAR_522, sizeof(array(struct cacheFile**)*), "[]cacheFile**", "&cache", 1, &____BAH_COMPILER_VAR_543, 0, 0, 0);
char * ____BAH_COMPILER_VAR_545 =toJson(____BAH_COMPILER_VAR_544);fileStream__writeFile(&fs,____BAH_COMPILER_VAR_545);
fileStream__close(&fs);
};
char isValidCacheFile(struct cacheFile* cf){
if ((cf->last!=getLastModified(cf->file))) {
return false;
}
char** ____BAH_COMPILER_VAR_546 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_546[5] = ".o.o";____BAH_COMPILER_VAR_546[4] = intToStr(cf->opti);____BAH_COMPILER_VAR_546[3] = intToStr(cf->mem);____BAH_COMPILER_VAR_546[2] = pathToVarName(cf->file);____BAH_COMPILER_VAR_546[1] = "cache/";____BAH_COMPILER_VAR_546[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_547 =__Bah_multiple_concat(____BAH_COMPILER_VAR_546, 6);if ((fileExists(____BAH_COMPILER_VAR_547)==0)) {
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
char** ____BAH_COMPILER_VAR_548 = alloca(15 * sizeof(char*));____BAH_COMPILER_VAR_548[14] = val;____BAH_COMPILER_VAR_548[13] = "] = ";____BAH_COMPILER_VAR_548[12] = nLength;____BAH_COMPILER_VAR_548[11] = "->data[";____BAH_COMPILER_VAR_548[10] = nstr;____BAH_COMPILER_VAR_548[9] = preVal;____BAH_COMPILER_VAR_548[8] = ");\n    ";____BAH_COMPILER_VAR_548[7] = nLength;____BAH_COMPILER_VAR_548[6] = ", ";____BAH_COMPILER_VAR_548[5] = nstr;____BAH_COMPILER_VAR_548[4] = ";\n    __Bah_realocate_arr(";____BAH_COMPILER_VAR_548[3] = nLengthStr;____BAH_COMPILER_VAR_548[2] = " = ";____BAH_COMPILER_VAR_548[1] = nLength;____BAH_COMPILER_VAR_548[0] = "\n    unsigned int ";char * ____BAH_COMPILER_VAR_549 =__Bah_multiple_concat(____BAH_COMPILER_VAR_548, 15);return ____BAH_COMPILER_VAR_549;
};
char * genConcat(__BAH_ARR_TYPE_cpstring strs,struct Elems* elems){
char * buff = genCompilerVar();
char** ____BAH_COMPILER_VAR_550 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_550[4] = " * sizeof(char*));";____BAH_COMPILER_VAR_550[3] = intToStr(len(strs));____BAH_COMPILER_VAR_550[2] = " = alloca(";____BAH_COMPILER_VAR_550[1] = buff;____BAH_COMPILER_VAR_550[0] = "char** ";char * ____BAH_COMPILER_VAR_551 =__Bah_multiple_concat(____BAH_COMPILER_VAR_550, 5);char * r = ____BAH_COMPILER_VAR_551;
register long int i = 0;
for (; (i<len(strs)); ++i) {
char** ____BAH_COMPILER_VAR_552 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_552[5] = ";";____BAH_COMPILER_VAR_552[4] = strs->data[i];____BAH_COMPILER_VAR_552[3] = "] = ";____BAH_COMPILER_VAR_552[2] = intToStr(len(strs)-i-1);____BAH_COMPILER_VAR_552[1] = "[";____BAH_COMPILER_VAR_552[0] = buff;char * ____BAH_COMPILER_VAR_553 =__Bah_multiple_concat(____BAH_COMPILER_VAR_552, 6);char** ____BAH_COMPILER_VAR_554 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_554[1] = ____BAH_COMPILER_VAR_553;____BAH_COMPILER_VAR_554[0] = r;char * ____BAH_COMPILER_VAR_555 =__Bah_multiple_concat(____BAH_COMPILER_VAR_554, 2);r = ____BAH_COMPILER_VAR_555;
};
if (isGlobal()) {
INIT = rope__add(INIT, rope(r));
}
else {
OUTPUT = rope__add(OUTPUT, rope(r));
}
char** ____BAH_COMPILER_VAR_556 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_556[4] = ")";____BAH_COMPILER_VAR_556[3] = intToStr(len(strs));____BAH_COMPILER_VAR_556[2] = ", ";____BAH_COMPILER_VAR_556[1] = buff;____BAH_COMPILER_VAR_556[0] = "__Bah_multiple_concat(";char * ____BAH_COMPILER_VAR_557 =__Bah_multiple_concat(____BAH_COMPILER_VAR_556, 5);char * rstr = registerRCPvar("cpstring",____BAH_COMPILER_VAR_557,elems);
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

                struct string ____BAH_COMPILER_VAR_558 = string(v->name);
                if ((isRCPpointerType(v->type)==false)&&(strcmp(v->type, "reflectElement") != 0)&&(string__hasPrefix(&____BAH_COMPILER_VAR_558,"____BAH_COMPILER_VAR_")==false)) {
struct cStruct* s = searchStruct(v->type,elems);
if ((s!=null)&&(currentFn!=null)) {
char** ____BAH_COMPILER_VAR_559 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_559[6] = ") could be passed by reference.";____BAH_COMPILER_VAR_559[5] = v->type;____BAH_COMPILER_VAR_559[4] = "\e[0m (";____BAH_COMPILER_VAR_559[3] = v->name;____BAH_COMPILER_VAR_559[2] = "()\e[0m: argument \e[1;37m";____BAH_COMPILER_VAR_559[1] = currentFn->name;____BAH_COMPILER_VAR_559[0] = "in \e[1;37m";char * ____BAH_COMPILER_VAR_560 =__Bah_multiple_concat(____BAH_COMPILER_VAR_559, 7);throwNoticeLine(____BAH_COMPILER_VAR_560,currentFn->line);
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
char * byteToOctal(unsigned char b){
unsigned int n = b;
char * r = "";
long int i = 0;
for (; (n!=0); ++i) {
char** ____BAH_COMPILER_VAR_561 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_561[1] = r;____BAH_COMPILER_VAR_561[0] = intToStr(n%8);char * ____BAH_COMPILER_VAR_562 =__Bah_multiple_concat(____BAH_COMPILER_VAR_561, 2);r = ____BAH_COMPILER_VAR_562;
n = n/8;
};
char * escp = "\\0";
if ((i==3)) {
escp = cpstringSubsitute(escp, 0, 1);
}
char** ____BAH_COMPILER_VAR_563 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_563[1] = r;____BAH_COMPILER_VAR_563[0] = escp;char * ____BAH_COMPILER_VAR_564 =__Bah_multiple_concat(____BAH_COMPILER_VAR_563, 2);return ____BAH_COMPILER_VAR_564;
};
char * escapeIntOctal(long int n){
char * s = &n;
char * r = "";
register long int i = 0;
for (; (i<8); ++i) {
char** ____BAH_COMPILER_VAR_565 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_565[1] = byteToOctal((unsigned char)s[i]);____BAH_COMPILER_VAR_565[0] = r;char * ____BAH_COMPILER_VAR_566 =__Bah_multiple_concat(____BAH_COMPILER_VAR_565, 2);r = ____BAH_COMPILER_VAR_566;
};
return r;
};
unsigned long int getStrLen(char * s){
long int l = 0;
long int i = 0;
for (; (s[i]!=null); ++i) {
if ((s[i]==(char)92)) {
continue;
}
++l;
};
return l;
};
char * strLitteralToBahStr(char * s){
return s;
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
struct func* ____BAH_COMPILER_VAR_567 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_567->name = "";
____BAH_COMPILER_VAR_567->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_567->args->length = 0;
            ____BAH_COMPILER_VAR_567->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_567->from = "";
____BAH_COMPILER_VAR_567->file = "";
____BAH_COMPILER_VAR_567->line = 1;
struct func* r = ____BAH_COMPILER_VAR_567;
r->name = this->baseFn->name;
register long int i = 0;
for (; (i<len(this->baseFn->args)); ++i) {
struct variable* a = this->baseFn->args->data[i];
struct variable* ____BAH_COMPILER_VAR_568 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_568->name = "";
____BAH_COMPILER_VAR_568->type = "";
____BAH_COMPILER_VAR_568->constVal = "";
____BAH_COMPILER_VAR_568->from = "";
struct variable* na = ____BAH_COMPILER_VAR_568;
*na = *a;

    unsigned int ____BAH_COMPILER_VAR_569 = i;
    __Bah_realocate_arr(r->args, ____BAH_COMPILER_VAR_569);
    r->args->data[____BAH_COMPILER_VAR_569] = na;
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

    unsigned int ____BAH_COMPILER_VAR_570 = len(this->declared);
    __Bah_realocate_arr(this->declared, ____BAH_COMPILER_VAR_570);
    this->declared->data[____BAH_COMPILER_VAR_570] = fn;

                struct string ____BAH_COMPILER_VAR_571 = getCType(fn->returns->type,elems);
                char** ____BAH_COMPILER_VAR_572 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_572[3] = "(";____BAH_COMPILER_VAR_572[2] = fn->name;____BAH_COMPILER_VAR_572[1] = " __generic_";____BAH_COMPILER_VAR_572[0] = string__str(&____BAH_COMPILER_VAR_571);char * ____BAH_COMPILER_VAR_573 =__Bah_multiple_concat(____BAH_COMPILER_VAR_572, 4);OUTPUT = rope(____BAH_COMPILER_VAR_573);
struct Elems* fnElems = dupElems(elems);
register long int i = 0;
for (; (i<len(fn->args)); ++i) {
struct variable* arg = fn->args->data[i];
arg->declScope = elems;
arg->isArg = true;

    unsigned int ____BAH_COMPILER_VAR_574 = len(fnElems->vars);
    __Bah_realocate_arr(fnElems->vars, ____BAH_COMPILER_VAR_574);
    fnElems->vars->data[____BAH_COMPILER_VAR_574] = arg;

                struct string ____BAH_COMPILER_VAR_575 = getCType(arg->type,elems);
                char** ____BAH_COMPILER_VAR_576 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_576[2] = arg->name;____BAH_COMPILER_VAR_576[1] = " ";____BAH_COMPILER_VAR_576[0] = string__str(&____BAH_COMPILER_VAR_575);char * ____BAH_COMPILER_VAR_577 =__Bah_multiple_concat(____BAH_COMPILER_VAR_576, 3);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_577));
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
char** ____BAH_COMPILER_VAR_578 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_578[2] = "' is not returned.";____BAH_COMPILER_VAR_578[1] = fn->name;____BAH_COMPILER_VAR_578[0] = "Function '";char * ____BAH_COMPILER_VAR_579 =__Bah_multiple_concat(____BAH_COMPILER_VAR_578, 3);throwErr(this->tokenName,____BAH_COMPILER_VAR_579);
}
endRCPscope(fnElems,fn->args);
}
else {
}
struct rope* code = rope__add(OUTPUT, rope("};\n"));
OUTPUT = oldOut;
char** ____BAH_COMPILER_VAR_580 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_580[1] = rope__toStr(code);____BAH_COMPILER_VAR_580[0] = rope__toStr(postDeclHandle);char * ____BAH_COMPILER_VAR_581 =__Bah_multiple_concat(____BAH_COMPILER_VAR_580, 2);OUTPUT->totalLen = OUTPUT->totalLen+ropeSet(postDeclHandle,____BAH_COMPILER_VAR_581);
};
array(struct genericFunc*)* generics;
void advertiseGeneric(){
if ((currGen==null)) {
return;
}
struct genericFunc* gen = currGen;
char** ____BAH_COMPILER_VAR_582 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_582[3] = intToStr(gen->callToken->line);____BAH_COMPILER_VAR_582[2] = ":";____BAH_COMPILER_VAR_582[1] = compilerState.currentFile;____BAH_COMPILER_VAR_582[0] = "[Generic] called here: ";char * ____BAH_COMPILER_VAR_583 =__Bah_multiple_concat(____BAH_COMPILER_VAR_582, 4);println(____BAH_COMPILER_VAR_583);
};
void debugLine(__BAH_ARR_TYPE_Tok line){
char * cont = "";
register long int i = 0;
while ((i<len(line))) {
struct Tok t = line->data[i];
char** ____BAH_COMPILER_VAR_584 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_584[3] = "'";____BAH_COMPILER_VAR_584[2] = t.cont;____BAH_COMPILER_VAR_584[1] = " '";____BAH_COMPILER_VAR_584[0] = cont;char * ____BAH_COMPILER_VAR_585 =__Bah_multiple_concat(____BAH_COMPILER_VAR_584, 4);cont = ____BAH_COMPILER_VAR_585;
++i;
};
println(cont);
};
struct Elems* dupElems(struct Elems* elems){
struct Elems* ____BAH_COMPILER_VAR_586 = memoryAlloc(sizeof(struct Elems));
____BAH_COMPILER_VAR_586->vars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_586->vars->length = 0;
            ____BAH_COMPILER_VAR_586->vars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_586->structs = memoryAlloc(sizeof(array(struct cStruct*)));
            ____BAH_COMPILER_VAR_586->structs->length = 0;
            ____BAH_COMPILER_VAR_586->structs->elemSize = sizeof(struct cStruct*);
            ____BAH_COMPILER_VAR_586->types = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_586->types->length = 0;
            ____BAH_COMPILER_VAR_586->types->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_586->fns = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_586->fns->length = 0;
            ____BAH_COMPILER_VAR_586->fns->elemSize = sizeof(struct func*);
            ____BAH_COMPILER_VAR_586->deletedVars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_586->deletedVars->length = 0;
            ____BAH_COMPILER_VAR_586->deletedVars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_586->branchChecks = memoryAlloc(sizeof(array(struct varCheck)));
            ____BAH_COMPILER_VAR_586->branchChecks->length = 0;
            ____BAH_COMPILER_VAR_586->branchChecks->elemSize = sizeof(struct varCheck);
            struct Elems* nElems = ____BAH_COMPILER_VAR_586;
nElems->parent = elems;
allocateArray(nElems->vars,len(elems->vars));
register long int j = 0;
for (; (j<len(elems->vars)); ++j) {

    unsigned int ____BAH_COMPILER_VAR_587 = j;
    __Bah_realocate_arr(nElems->vars, ____BAH_COMPILER_VAR_587);
    nElems->vars->data[____BAH_COMPILER_VAR_587] = elems->vars->data[j];
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

                struct string ____BAH_COMPILER_VAR_588 = string(compilerState.currentDir);
                if ((isUnsafe==false)&&(string__hasPrefix(&____BAH_COMPILER_VAR_588,BAH_DIR)==false)&&isRCPpointerType(tt)&&(t->cont[0]!=38)&&(t->cont[0]!=42)) {
struct variable* sv = searchVarByToken(t,elems);
if ((sv!=null)) {
if (__builtin_expect((sv->canBeNull==true)&&(checkedNotNull(sv->name,elems)==false), 0)) {
char * globCheck = "";
struct cStruct* s = searchStruct(sv->type,elems);
if ((sv->isGlobal==true)&&(s!=null)) {
char** ____BAH_COMPILER_VAR_589 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_589[2] = "'.";____BAH_COMPILER_VAR_589[1] = s->name;____BAH_COMPILER_VAR_589[0] = " or declare the var as 'new ";char * ____BAH_COMPILER_VAR_590 =__Bah_multiple_concat(____BAH_COMPILER_VAR_589, 3);globCheck = ____BAH_COMPILER_VAR_590;
}
char** ____BAH_COMPILER_VAR_591 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_591[2] = ".";____BAH_COMPILER_VAR_591[1] = globCheck;____BAH_COMPILER_VAR_591[0] = "{TOKEN} can contain a null value. Check if the value is null";char * ____BAH_COMPILER_VAR_592 =__Bah_multiple_concat(____BAH_COMPILER_VAR_591, 3);throwErr(t,____BAH_COMPILER_VAR_592);
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
char fixMeEnabled(){
if ((isFixMeEnabled==false)) {
return false;
}
return (isInside(BAH_DIR,compilerState.currentDir)==false);
};
void fixMeRegisterVar(struct variable* v,struct Tok* t){
char * name = v->name;

                struct string ____BAH_COMPILER_VAR_593 = string(v->type);
                if ((string__count(&____BAH_COMPILER_VAR_593,"*")==0)) {
char** ____BAH_COMPILER_VAR_594 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_594[1] = name;____BAH_COMPILER_VAR_594[0] = "&";char * ____BAH_COMPILER_VAR_595 =__Bah_multiple_concat(____BAH_COMPILER_VAR_594, 2);name = ____BAH_COMPILER_VAR_595;
}
char** ____BAH_COMPILER_VAR_596 = alloca(15 * sizeof(char*));____BAH_COMPILER_VAR_596[14] = "\");\n    ";____BAH_COMPILER_VAR_596[13] = intToStr(t->line);____BAH_COMPILER_VAR_596[12] = ":";____BAH_COMPILER_VAR_596[11] = compilerState.currentFile;____BAH_COMPILER_VAR_596[10] = ", \"";____BAH_COMPILER_VAR_596[9] = name;____BAH_COMPILER_VAR_596[8] = "\", ";____BAH_COMPILER_VAR_596[7] = v->name;____BAH_COMPILER_VAR_596[6] = "\n    fixMeAddVar(\"";____BAH_COMPILER_VAR_596[5] = intToStr(t->line);____BAH_COMPILER_VAR_596[4] = ":";____BAH_COMPILER_VAR_596[3] = compilerState.currentFile;____BAH_COMPILER_VAR_596[2] = "\n    //src: ";____BAH_COMPILER_VAR_596[1] = v->name;____BAH_COMPILER_VAR_596[0] = "\n    //BEGINING\n    //var: ";char * ____BAH_COMPILER_VAR_597 =__Bah_multiple_concat(____BAH_COMPILER_VAR_596, 15);char** ____BAH_COMPILER_VAR_598 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_598[1] = ____BAH_COMPILER_VAR_597;____BAH_COMPILER_VAR_598[0] = NEXT_LINE;char * ____BAH_COMPILER_VAR_599 =__Bah_multiple_concat(____BAH_COMPILER_VAR_598, 2);NEXT_LINE = ____BAH_COMPILER_VAR_599;
};
void fixMeEndScope(struct Elems* elems,struct Tok* t){
if ((fixMeEnabled()==false)) {
return;
}
register long int i = 0;
for (; (i<len(elems->vars)); ++i) {
struct variable* v = elems->vars->data[i];
if ((v->declScope==elems)) {
char * name = v->name;

                struct string ____BAH_COMPILER_VAR_600 = string(v->type);
                if ((string__count(&____BAH_COMPILER_VAR_600,"*")==0)) {
char** ____BAH_COMPILER_VAR_601 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_601[1] = name;____BAH_COMPILER_VAR_601[0] = "&";char * ____BAH_COMPILER_VAR_602 =__Bah_multiple_concat(____BAH_COMPILER_VAR_601, 2);name = ____BAH_COMPILER_VAR_602;
}
else {
continue;
}
char** ____BAH_COMPILER_VAR_603 = alloca(15 * sizeof(char*));____BAH_COMPILER_VAR_603[14] = "\");\n            ";____BAH_COMPILER_VAR_603[13] = intToStr(t->line);____BAH_COMPILER_VAR_603[12] = ":";____BAH_COMPILER_VAR_603[11] = compilerState.currentFile;____BAH_COMPILER_VAR_603[10] = ", \"";____BAH_COMPILER_VAR_603[9] = name;____BAH_COMPILER_VAR_603[8] = "\", ";____BAH_COMPILER_VAR_603[7] = v->name;____BAH_COMPILER_VAR_603[6] = "\n            fixMeRemVar(\"";____BAH_COMPILER_VAR_603[5] = intToStr(t->line);____BAH_COMPILER_VAR_603[4] = ":";____BAH_COMPILER_VAR_603[3] = compilerState.currentFile;____BAH_COMPILER_VAR_603[2] = "\n            //src: ";____BAH_COMPILER_VAR_603[1] = v->name;____BAH_COMPILER_VAR_603[0] = "\n            //END\n            //var: ";char * ____BAH_COMPILER_VAR_604 =__Bah_multiple_concat(____BAH_COMPILER_VAR_603, 15);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_604));
}
};
};
void fixMeTestVar(struct Tok* t,struct Elems* elems){
if ((fixMeEnabled()==false)) {
return;
}
char * name = t->cont;
char * tt = getTypeFromToken(t,true,elems);

                struct string ____BAH_COMPILER_VAR_605 = string(tt);
                if ((string__count(&____BAH_COMPILER_VAR_605,"*")==0)) {
if ((name[0]==42)) {
name = cpstringSubsitute(name, 1, strlen(name));
}
else {
char** ____BAH_COMPILER_VAR_606 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_606[1] = name;____BAH_COMPILER_VAR_606[0] = "&";char * ____BAH_COMPILER_VAR_607 =__Bah_multiple_concat(____BAH_COMPILER_VAR_606, 2);name = ____BAH_COMPILER_VAR_607;
}
}
char** ____BAH_COMPILER_VAR_608 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_608[6] = "\");\n    ";____BAH_COMPILER_VAR_608[5] = intToStr(t->line);____BAH_COMPILER_VAR_608[4] = ":";____BAH_COMPILER_VAR_608[3] = compilerState.currentFile;____BAH_COMPILER_VAR_608[2] = ", \"";____BAH_COMPILER_VAR_608[1] = name;____BAH_COMPILER_VAR_608[0] = "\n    fixMeIsVarOk(";char * ____BAH_COMPILER_VAR_609 =__Bah_multiple_concat(____BAH_COMPILER_VAR_608, 7);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_609));
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

    unsigned int ____BAH_COMPILER_VAR_610 = i;
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_610);
    nl->data[____BAH_COMPILER_VAR_610] = t;
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
char * ____BAH_COMPILER_VAR_611 =string__str(&tc);struct string cCast = getCType(____BAH_COMPILER_VAR_611,elems);
char * cCastStr = string__str(&cCast);
char** ____BAH_COMPILER_VAR_612 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_612[3] = nnnt.cont;____BAH_COMPILER_VAR_612[2] = ")";____BAH_COMPILER_VAR_612[1] = cCastStr;____BAH_COMPILER_VAR_612[0] = "(";char * ____BAH_COMPILER_VAR_613 =__Bah_multiple_concat(____BAH_COMPILER_VAR_612, 4);nnnt.cont = ____BAH_COMPILER_VAR_613;

    unsigned int ____BAH_COMPILER_VAR_614 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_614);
    nl->data[____BAH_COMPILER_VAR_614] = nnnt;
i = i+2;
continue;
}
}

    unsigned int ____BAH_COMPILER_VAR_615 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_615);
    nl->data[____BAH_COMPILER_VAR_615] = t;
};
return nl;
};
char * getDirFromFile(char * f){
char * ____BAH_COMPILER_VAR_616 =__STR(f);array(char)* p = strAsArr(____BAH_COMPILER_VAR_616);
register long int i = len(p)-1;
while ((i>=0)) {
char c = p->data[i];
if ((c==47)) {

    unsigned int ____BAH_COMPILER_VAR_617 = i+1;
    __Bah_realocate_arr(p, ____BAH_COMPILER_VAR_617);
    p->data[____BAH_COMPILER_VAR_617] = (char)0;
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
if ((RAIIenabled==true)) {
ccstr = "raii.bah";
}
else if ((RCPenabled==true)) {
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
char * ____BAH_COMPILER_VAR_619 =ccstr;
        char ____BAH_COMPILER_VAR_618 = 0;
        for(int i=compilerState.includes->length-1; i!=-1;i--) {
            if (compilerState.includes->data[i] != 0 && strcmp(compilerState.includes->data[i], ____BAH_COMPILER_VAR_619) == 0) {
                ____BAH_COMPILER_VAR_618=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_618) {
return true;
}
struct fileMap ____BAH_COMPILER_VAR_620 = {};
____BAH_COMPILER_VAR_620.handle = -1;
struct fileMap fm = ____BAH_COMPILER_VAR_620;
char** ____BAH_COMPILER_VAR_621 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_621[1] = ccstr;____BAH_COMPILER_VAR_621[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_622 =__Bah_multiple_concat(____BAH_COMPILER_VAR_621, 2);char * fileName = ____BAH_COMPILER_VAR_622;
char isBahDir = true;
char * f = fileMap__open(&fm,fileName);
if ((fileMap__isValid(&fm)==0)) {
char** ____BAH_COMPILER_VAR_623 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_623[1] = ccstr;____BAH_COMPILER_VAR_623[0] = compilerState.currentDir;char * ____BAH_COMPILER_VAR_624 =__Bah_multiple_concat(____BAH_COMPILER_VAR_623, 2);fileName = absPath(____BAH_COMPILER_VAR_624);
f = fileMap__open(&fm,fileName);
isBahDir = false;
if ((fileMap__isValid(&fm)==0)) {
return false;
}
}
char * oDir = compilerState.currentDir;
if ((isBahDir==false)) {
char** ____BAH_COMPILER_VAR_625 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_625[1] = getDirFromFile(ccstr);____BAH_COMPILER_VAR_625[0] = compilerState.currentDir;char * ____BAH_COMPILER_VAR_626 =__Bah_multiple_concat(____BAH_COMPILER_VAR_625, 2);compilerState.currentDir = ____BAH_COMPILER_VAR_626;
}
else {
char** ____BAH_COMPILER_VAR_627 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_627[1] = getDirFromFile(ccstr);____BAH_COMPILER_VAR_627[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_628 =__Bah_multiple_concat(____BAH_COMPILER_VAR_627, 2);compilerState.currentDir = ____BAH_COMPILER_VAR_628;
}
char * oFile = compilerState.currentFile;
compilerState.currentFile = fileName;

    unsigned int ____BAH_COMPILER_VAR_629 = len(compilerState.includes);
    __Bah_realocate_arr(compilerState.includes, ____BAH_COMPILER_VAR_629);
    compilerState.includes->data[____BAH_COMPILER_VAR_629] = ccstr;
array(struct Tok)* tokens = lexer(f,fm.size);
fileMap__close(&fm);
if (__builtin_expect((len(tokens)==0), 0)) {
char** ____BAH_COMPILER_VAR_630 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_630[2] = "' not recognized.";____BAH_COMPILER_VAR_630[1] = ccstr;____BAH_COMPILER_VAR_630[0] = "File '";char * ____BAH_COMPILER_VAR_631 =__Bah_multiple_concat(____BAH_COMPILER_VAR_630, 3);__BAH_panic(____BAH_COMPILER_VAR_631,"/home/alois/Documents/bah-bah/src/parser.bah:254");
}
char oshd = shouldOnlyDecl;
if ((isObject==true)) {

                struct string ____BAH_COMPILER_VAR_632 = string(compilerState.currentFile);
                if ((isBahDir==true)||(string__hasPrefix(&____BAH_COMPILER_VAR_632,oDir)==false)) {
shouldOnlyDecl = true;
}
else {
shouldOnlyDecl = false;
}
}
else if ((isSubObject==true)) {

                struct string ____BAH_COMPILER_VAR_633 = string(compilerState.currentFile);
                if ((isBahDir==true)||(string__hasPrefix(&____BAH_COMPILER_VAR_633,oDir)==false)) {
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
struct cacheFile* ____BAH_COMPILER_VAR_634 = memoryAlloc(sizeof(struct cacheFile));
____BAH_COMPILER_VAR_634->files = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_634->files->length = 0;
            ____BAH_COMPILER_VAR_634->files->elemSize = sizeof(char *);
            scf = ____BAH_COMPILER_VAR_634;
}
if ((cf==null)||(isValidCacheFile(scf)==false)) {
setCurrentPath(compilerState.currentDir);
char * verboseCC = "";
if ((flags__isSet(&flags,"verboseCC")==1)) {
verboseCC = "-verboseCC";
}
if ((debug==false)) {
char** ____BAH_COMPILER_VAR_635 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_635[1] = fn;____BAH_COMPILER_VAR_635[0] = "[compiling] ";char * ____BAH_COMPILER_VAR_636 =__Bah_multiple_concat(____BAH_COMPILER_VAR_635, 2);println(____BAH_COMPILER_VAR_636);
}
char * opti = "";
if ((isOptimized==true)) {
opti = "-optimize";
}
char** ____BAH_COMPILER_VAR_637 = alloca(11 * sizeof(char*));____BAH_COMPILER_VAR_637[10] = oName;____BAH_COMPILER_VAR_637[9] = " -o ";____BAH_COMPILER_VAR_637[8] = verboseCC;____BAH_COMPILER_VAR_637[7] = " -object ";____BAH_COMPILER_VAR_637[6] = opti;____BAH_COMPILER_VAR_637[5] = " ";____BAH_COMPILER_VAR_637[4] = rcp;____BAH_COMPILER_VAR_637[3] = " ";____BAH_COMPILER_VAR_637[2] = fn;____BAH_COMPILER_VAR_637[1] = " ";____BAH_COMPILER_VAR_637[0] = execName;char * ____BAH_COMPILER_VAR_638 =__Bah_multiple_concat(____BAH_COMPILER_VAR_637, 11);struct command cmd = command(____BAH_COMPILER_VAR_638);
array(char)* res = command__runBytes(&cmd);
setCurrentPath(wrkd);
if (__builtin_expect((cmd.status!=0), 0)) {
char * ____BAH_COMPILER_VAR_639 =arrToStr(res);print(____BAH_COMPILER_VAR_639);
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

        char ____BAH_COMPILER_VAR_640 = true;
        channel__sendAny(done, &____BAH_COMPILER_VAR_640, sizeof(____BAH_COMPILER_VAR_640));
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
char * ____BAH_COMPILER_VAR_642 =string__str(&fileName);
        char ____BAH_COMPILER_VAR_641 = 0;
        for(int i=compilerState.includes->length-1; i!=-1;i--) {
            if (compilerState.includes->data[i] != 0 && strcmp(compilerState.includes->data[i], ____BAH_COMPILER_VAR_642) == 0) {
                ____BAH_COMPILER_VAR_641=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_641) {
return;
}

    unsigned int ____BAH_COMPILER_VAR_643 = len(compilerState.includes);
    __Bah_realocate_arr(compilerState.includes, ____BAH_COMPILER_VAR_643);
    compilerState.includes->data[____BAH_COMPILER_VAR_643] = string__str(&fileName);
char** ____BAH_COMPILER_VAR_644 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_644[1] = string__str(&fileName);____BAH_COMPILER_VAR_644[0] = compilerState.currentDir;char * ____BAH_COMPILER_VAR_645 =__Bah_multiple_concat(____BAH_COMPILER_VAR_644, 2);char * fn = absPath(____BAH_COMPILER_VAR_645);
if (((void *)fn==null)) {
char** ____BAH_COMPILER_VAR_646 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_646[1] = string__str(&fileName);____BAH_COMPILER_VAR_646[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_647 =__Bah_multiple_concat(____BAH_COMPILER_VAR_646, 2);fn = absPath(____BAH_COMPILER_VAR_647);
if (__builtin_expect(((void *)fn==null), 0)) {
throwErr(&strt,"Unknown file {TOKEN}.");
}
}
char * of = compilerState.currentFile;
char * od = compilerState.currentDir;
compilerState.currentFile = fn;
compilerState.currentDir = getDirFromFile(fn);
struct fileStream ____BAH_COMPILER_VAR_648 = {};
struct fileStream fs = ____BAH_COMPILER_VAR_648;
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
char** ____BAH_COMPILER_VAR_649 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_649[5] = ".o";____BAH_COMPILER_VAR_649[4] = intToStr(isOptimized);____BAH_COMPILER_VAR_649[3] = intToStr(RCPlevel);____BAH_COMPILER_VAR_649[2] = pathToVarName(fn);____BAH_COMPILER_VAR_649[1] = "cache/";____BAH_COMPILER_VAR_649[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_650 =__Bah_multiple_concat(____BAH_COMPILER_VAR_649, 6);char * oName = ____BAH_COMPILER_VAR_650;
register long int i = len(compilerState.cLibs);
for (; (i!=0); --i) {

    unsigned int ____BAH_COMPILER_VAR_651 = i;
    __Bah_realocate_arr(compilerState.cLibs, ____BAH_COMPILER_VAR_651);
    compilerState.cLibs->data[____BAH_COMPILER_VAR_651] = compilerState.cLibs->data[i-1];
};
char** ____BAH_COMPILER_VAR_652 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_652[2] = ".o";____BAH_COMPILER_VAR_652[1] = oName;____BAH_COMPILER_VAR_652[0] = "w ";char * ____BAH_COMPILER_VAR_653 =__Bah_multiple_concat(____BAH_COMPILER_VAR_652, 3);
    unsigned int ____BAH_COMPILER_VAR_654 = 0;
    __Bah_realocate_arr(compilerState.cLibs, ____BAH_COMPILER_VAR_654);
    compilerState.cLibs->data[____BAH_COMPILER_VAR_654] = ____BAH_COMPILER_VAR_653;
struct channel * done = channel();
parallelObjCompile(fn,oName,done);
parseLines(tokens,elems);
char ok = *(char*)channel__receive(done);
char** ____BAH_COMPILER_VAR_655 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_655[2] = "();\n";____BAH_COMPILER_VAR_655[1] = pathToVarName(fn);____BAH_COMPILER_VAR_655[0] = "__BAH_init";char * ____BAH_COMPILER_VAR_656 =__Bah_multiple_concat(____BAH_COMPILER_VAR_655, 3);INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_656));
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
if ((isSubObject==false)||(isSupressed==false)) {
char** ____BAH_COMPILER_VAR_657 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_657[2] = "\n";____BAH_COMPILER_VAR_657[1] = sc;____BAH_COMPILER_VAR_657[0] = "#include ";char * ____BAH_COMPILER_VAR_658 =__Bah_multiple_concat(____BAH_COMPILER_VAR_657, 3);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_658));

    unsigned int ____BAH_COMPILER_VAR_659 = len(compilerState.cIncludes);
    __Bah_realocate_arr(compilerState.cIncludes, ____BAH_COMPILER_VAR_659);
    compilerState.cIncludes->data[____BAH_COMPILER_VAR_659] = sc;
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

    unsigned int ____BAH_COMPILER_VAR_660 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_660);
    nl->data[____BAH_COMPILER_VAR_660] = t;
++i;
continue;
}
++i;
struct Tok ____BAH_COMPILER_VAR_661 = {};
____BAH_COMPILER_VAR_661.cont = "";
____BAH_COMPILER_VAR_661.ogCont = "";
____BAH_COMPILER_VAR_661.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_661.line = 1;
____BAH_COMPILER_VAR_661.begLine = 1;
____BAH_COMPILER_VAR_661.bahType = "";
____BAH_COMPILER_VAR_661.cont = "";
struct Tok nt = ____BAH_COMPILER_VAR_661;
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
struct variable* ____BAH_COMPILER_VAR_662 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_662->name = "";
____BAH_COMPILER_VAR_662->type = "";
____BAH_COMPILER_VAR_662->constVal = "";
____BAH_COMPILER_VAR_662->from = "";
struct variable* tmpV = ____BAH_COMPILER_VAR_662;
tmpV->name = t.cont;
char** ____BAH_COMPILER_VAR_663 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_663[1] = "*";____BAH_COMPILER_VAR_663[0] = s->name;char * ____BAH_COMPILER_VAR_664 =__Bah_multiple_concat(____BAH_COMPILER_VAR_663, 2);tmpV->type = ____BAH_COMPILER_VAR_664;
struct string cType = getCType(tmpV->type,elems);
struct string structType = getCType(s->name,elems);

    unsigned int ____BAH_COMPILER_VAR_665 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_665);
    elems->vars->data[____BAH_COMPILER_VAR_665] = tmpV;
char** ____BAH_COMPILER_VAR_666 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_666[6] = declareStructMethods(tmpV,s,elems);____BAH_COMPILER_VAR_666[5] = "));\n";____BAH_COMPILER_VAR_666[4] = string__str(&structType);____BAH_COMPILER_VAR_666[3] = " = memoryAlloc(sizeof(";____BAH_COMPILER_VAR_666[2] = t.cont;____BAH_COMPILER_VAR_666[1] = " ";____BAH_COMPILER_VAR_666[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_667 =__Bah_multiple_concat(____BAH_COMPILER_VAR_666, 7);struct rope* r = rope(____BAH_COMPILER_VAR_667);
if (isGlobal()) {
INIT = rope__add(INIT, r);
}
else {
OUTPUT = rope__add(OUTPUT, r);
}

    unsigned int ____BAH_COMPILER_VAR_668 = len(nl)-1;
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_668);
    nl->data[____BAH_COMPILER_VAR_668] = t;
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

    unsigned int ____BAH_COMPILER_VAR_669 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_669);
    memory->data[____BAH_COMPILER_VAR_669] = t;
};
if ((len(memory)>0)) {
memory = prePross(memory,(lineType)-1,elems);
}
long int declType = 0;
char * rvn = genCompilerVar();
struct variable* ____BAH_COMPILER_VAR_670 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_670->name = "";
____BAH_COMPILER_VAR_670->type = "";
____BAH_COMPILER_VAR_670->constVal = "";
____BAH_COMPILER_VAR_670->from = "";
struct variable* tmpV = ____BAH_COMPILER_VAR_670;
tmpV->name = rvn;
if ((isHeap==true)) {
char** ____BAH_COMPILER_VAR_671 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_671[1] = "*";____BAH_COMPILER_VAR_671[0] = s->name;char * ____BAH_COMPILER_VAR_672 =__Bah_multiple_concat(____BAH_COMPILER_VAR_671, 2);tmpV->type = ____BAH_COMPILER_VAR_672;

    unsigned int ____BAH_COMPILER_VAR_673 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_673);
    elems->vars->data[____BAH_COMPILER_VAR_673] = tmpV;
}
else {
tmpV->type = s->name;
}
struct string rst = getCType(tmpV->type,elems);
struct rope* r= null;
if ((isHeap==true)) {
char * ____BAH_COMPILER_VAR_674 =string__str(&rst);struct string structType = string(____BAH_COMPILER_VAR_674);
string__trimRight(&structType,1);
char** ____BAH_COMPILER_VAR_675 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_675[6] = declareStructMethods(tmpV,s,elems);____BAH_COMPILER_VAR_675[5] = "));\n";____BAH_COMPILER_VAR_675[4] = string__str(&structType);____BAH_COMPILER_VAR_675[3] = " = memoryAlloc(sizeof(";____BAH_COMPILER_VAR_675[2] = rvn;____BAH_COMPILER_VAR_675[1] = " ";____BAH_COMPILER_VAR_675[0] = string__str(&rst);char * ____BAH_COMPILER_VAR_676 =__Bah_multiple_concat(____BAH_COMPILER_VAR_675, 7);r = rope(____BAH_COMPILER_VAR_676);
}
else {
char** ____BAH_COMPILER_VAR_677 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_677[4] = declareStructMethods(tmpV,s,elems);____BAH_COMPILER_VAR_677[3] = " = {};\n";____BAH_COMPILER_VAR_677[2] = rvn;____BAH_COMPILER_VAR_677[1] = " ";____BAH_COMPILER_VAR_677[0] = string__str(&rst);char * ____BAH_COMPILER_VAR_678 =__Bah_multiple_concat(____BAH_COMPILER_VAR_677, 5);r = rope(____BAH_COMPILER_VAR_678);
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
char** ____BAH_COMPILER_VAR_679 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_679[4] = "'.";____BAH_COMPILER_VAR_679[3] = m->type;____BAH_COMPILER_VAR_679[2] = ") as '";____BAH_COMPILER_VAR_679[1] = vlt;____BAH_COMPILER_VAR_679[0] = "Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_680 =__Bah_multiple_concat(____BAH_COMPILER_VAR_679, 5);throwErr(&vl,____BAH_COMPILER_VAR_680);
}
char** ____BAH_COMPILER_VAR_681 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_681[5] = ";\n";____BAH_COMPILER_VAR_681[4] = vl.cont;____BAH_COMPILER_VAR_681[3] = " = ";____BAH_COMPILER_VAR_681[2] = m->name;____BAH_COMPILER_VAR_681[1] = sep;____BAH_COMPILER_VAR_681[0] = rvn;char * ____BAH_COMPILER_VAR_682 =__Bah_multiple_concat(____BAH_COMPILER_VAR_681, 6);r = rope__add(r, rope(____BAH_COMPILER_VAR_682));
break;
};
if (__builtin_expect((j==len(s->members)), 0)) {
char** ____BAH_COMPILER_VAR_683 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_683[2] = "' has no member called {TOKEN}.";____BAH_COMPILER_VAR_683[1] = s->name;____BAH_COMPILER_VAR_683[0] = "Struct '";char * ____BAH_COMPILER_VAR_684 =__Bah_multiple_concat(____BAH_COMPILER_VAR_683, 3);throwErr(&t,____BAH_COMPILER_VAR_684);
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
char** ____BAH_COMPILER_VAR_685 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_685[4] = "'.";____BAH_COMPILER_VAR_685[3] = m->type;____BAH_COMPILER_VAR_685[2] = ") as '";____BAH_COMPILER_VAR_685[1] = tt;____BAH_COMPILER_VAR_685[0] = "Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_686 =__Bah_multiple_concat(____BAH_COMPILER_VAR_685, 5);throwErr(&t,____BAH_COMPILER_VAR_686);
}
char** ____BAH_COMPILER_VAR_687 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_687[5] = ";\n";____BAH_COMPILER_VAR_687[4] = t.cont;____BAH_COMPILER_VAR_687[3] = " = ";____BAH_COMPILER_VAR_687[2] = m->name;____BAH_COMPILER_VAR_687[1] = sep;____BAH_COMPILER_VAR_687[0] = rvn;char * ____BAH_COMPILER_VAR_688 =__Bah_multiple_concat(____BAH_COMPILER_VAR_687, 6);r = rope__add(r, rope(____BAH_COMPILER_VAR_688));
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

    unsigned int ____BAH_COMPILER_VAR_689 = len(nl)-1;
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_689);
    nl->data[____BAH_COMPILER_VAR_689] = t;
}
else {
t.isEqual = true;

    unsigned int ____BAH_COMPILER_VAR_690 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_690);
    nl->data[____BAH_COMPILER_VAR_690] = t;
}
++i;
continue;
}
else {
--i;
}
}
}

    unsigned int ____BAH_COMPILER_VAR_691 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_691);
    nl->data[____BAH_COMPILER_VAR_691] = t;
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
char** ____BAH_COMPILER_VAR_692 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_692[1] = "[]";____BAH_COMPILER_VAR_692[0] = bracks;char * ____BAH_COMPILER_VAR_693 =__Bah_multiple_concat(____BAH_COMPILER_VAR_692, 2);bracks = ____BAH_COMPILER_VAR_693;
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
char** ____BAH_COMPILER_VAR_694 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_694[1] = arrElem;____BAH_COMPILER_VAR_694[0] = bracks;char * ____BAH_COMPILER_VAR_695 =__Bah_multiple_concat(____BAH_COMPILER_VAR_694, 2);t.bahType = ____BAH_COMPILER_VAR_695;
t.cont = "";
t.isValue = true;

    unsigned int ____BAH_COMPILER_VAR_696 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_696);
    nl->data[____BAH_COMPILER_VAR_696] = t;
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

    unsigned int ____BAH_COMPILER_VAR_697 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_697);
    nl->data[____BAH_COMPILER_VAR_697] = t;
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
if ((strcmp(l->data[i+1].cont, "(") != 0)&&(l->data[i+1].type!=TOKEN_TYPE_CAST)&&(l->data[i+1].isValue!=true)) {
char** ____BAH_COMPILER_VAR_698 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_698[1] = t.cont;____BAH_COMPILER_VAR_698[0] = l->data[i-1].cont;char * ____BAH_COMPILER_VAR_699 =__Bah_multiple_concat(____BAH_COMPILER_VAR_698, 2);l->data[i-1].cont = ____BAH_COMPILER_VAR_699;
delete(l,i);
--i;
}
}
else {
char** ____BAH_COMPILER_VAR_700 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_700[1] = t.cont;____BAH_COMPILER_VAR_700[0] = l->data[i-1].cont;char * ____BAH_COMPILER_VAR_701 =__Bah_multiple_concat(____BAH_COMPILER_VAR_700, 2);l->data[i-1].cont = ____BAH_COMPILER_VAR_701;
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
char** ____BAH_COMPILER_VAR_702 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_702[1] = l->data[i+1].cont;____BAH_COMPILER_VAR_702[0] = t.cont;char * ____BAH_COMPILER_VAR_703 =__Bah_multiple_concat(____BAH_COMPILER_VAR_702, 2);l->data[i+1].cont = ____BAH_COMPILER_VAR_703;
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
char** ____BAH_COMPILER_VAR_704 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_704[5] = ")";____BAH_COMPILER_VAR_704[4] = string__str(&svt);____BAH_COMPILER_VAR_704[3] = "sizeof(struct ";____BAH_COMPILER_VAR_704[2] = ", ";____BAH_COMPILER_VAR_704[1] = e->cont;____BAH_COMPILER_VAR_704[0] = "__serialize(&";char * ____BAH_COMPILER_VAR_705 =__Bah_multiple_concat(____BAH_COMPILER_VAR_704, 6);code = ____BAH_COMPILER_VAR_705;
}
else {
char * ptrRect = "";
while ((ptrLevel>1)) {
char** ____BAH_COMPILER_VAR_706 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_706[1] = "*";____BAH_COMPILER_VAR_706[0] = ptrRect;char * ____BAH_COMPILER_VAR_707 =__Bah_multiple_concat(____BAH_COMPILER_VAR_706, 2);ptrRect = ____BAH_COMPILER_VAR_707;
ptrLevel = ptrLevel-1;
};
char** ____BAH_COMPILER_VAR_708 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_708[6] = ")";____BAH_COMPILER_VAR_708[5] = string__str(&svt);____BAH_COMPILER_VAR_708[4] = "sizeof(struct ";____BAH_COMPILER_VAR_708[3] = ", ";____BAH_COMPILER_VAR_708[2] = e->cont;____BAH_COMPILER_VAR_708[1] = ptrRect;____BAH_COMPILER_VAR_708[0] = "__serialize(";char * ____BAH_COMPILER_VAR_709 =__Bah_multiple_concat(____BAH_COMPILER_VAR_708, 7);code = ____BAH_COMPILER_VAR_709;
register long int i = 0;
while ((i<len(s->members))) {
struct structMemb* m = s->members->data[i];
if ((strcmp(m->type, "cpstring") == 0)) {
char** ____BAH_COMPILER_VAR_710 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_710[5] = ")";____BAH_COMPILER_VAR_710[4] = m->name;____BAH_COMPILER_VAR_710[3] = "->";____BAH_COMPILER_VAR_710[2] = e->cont;____BAH_COMPILER_VAR_710[1] = "+strlen(";____BAH_COMPILER_VAR_710[0] = code;char * ____BAH_COMPILER_VAR_711 =__Bah_multiple_concat(____BAH_COMPILER_VAR_710, 6);code = ____BAH_COMPILER_VAR_711;
}
i = i+1;
};
}
char** ____BAH_COMPILER_VAR_712 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_712[1] = ")";____BAH_COMPILER_VAR_712[0] = code;char * ____BAH_COMPILER_VAR_713 =__Bah_multiple_concat(____BAH_COMPILER_VAR_712, 2);return ____BAH_COMPILER_VAR_713;
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
char** ____BAH_COMPILER_VAR_714 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_714[5] = ";\n";____BAH_COMPILER_VAR_714[4] = t.cont;____BAH_COMPILER_VAR_714[3] = " = ";____BAH_COMPILER_VAR_714[2] = v;____BAH_COMPILER_VAR_714[1] = " ";____BAH_COMPILER_VAR_714[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_715 =__Bah_multiple_concat(____BAH_COMPILER_VAR_714, 6);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_715));
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
struct Tok ____BAH_COMPILER_VAR_716 = {};
____BAH_COMPILER_VAR_716.cont = "";
____BAH_COMPILER_VAR_716.ogCont = "";
____BAH_COMPILER_VAR_716.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_716.line = 1;
____BAH_COMPILER_VAR_716.begLine = 1;
____BAH_COMPILER_VAR_716.bahType = "";
struct Tok tmpT = ____BAH_COMPILER_VAR_716;
tmpT.type = TOKEN_TYPE_VAR;
tmpT.cont = "0";
char * ____BAH_COMPILER_VAR_717 =string__str(&aet);struct Tok rt = parseReflect(tmpT,____BAH_COMPILER_VAR_717,elems,true,"","0");
char * aev = genCompilerVar();
char** ____BAH_COMPILER_VAR_718 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_718[4] = ";\n        ";____BAH_COMPILER_VAR_718[3] = rt.cont;____BAH_COMPILER_VAR_718[2] = " = ";____BAH_COMPILER_VAR_718[1] = aev;____BAH_COMPILER_VAR_718[0] = "\n        struct reflectElement ";char * ____BAH_COMPILER_VAR_719 =__Bah_multiple_concat(____BAH_COMPILER_VAR_718, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_719));
char** ____BAH_COMPILER_VAR_720 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_720[1] = aev;____BAH_COMPILER_VAR_720[0] = "&";char * ____BAH_COMPILER_VAR_721 =__Bah_multiple_concat(____BAH_COMPILER_VAR_720, 2);arrElem = ____BAH_COMPILER_VAR_721;
}
else if (strHasPrefix(tt,"map:")) {
struct string aet = string(tt);
string__trimLeft(&aet,4);
struct Tok ____BAH_COMPILER_VAR_722 = {};
____BAH_COMPILER_VAR_722.cont = "";
____BAH_COMPILER_VAR_722.ogCont = "";
____BAH_COMPILER_VAR_722.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_722.line = 1;
____BAH_COMPILER_VAR_722.begLine = 1;
____BAH_COMPILER_VAR_722.bahType = "";
struct Tok tmpT = ____BAH_COMPILER_VAR_722;
tmpT.type = TOKEN_TYPE_VAR;
tmpT.cont = "0";
char * ____BAH_COMPILER_VAR_723 =string__str(&aet);struct Tok rt = parseReflect(tmpT,____BAH_COMPILER_VAR_723,elems,true,"","0");
char * aev = genCompilerVar();
char** ____BAH_COMPILER_VAR_724 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_724[4] = ";\n        ";____BAH_COMPILER_VAR_724[3] = rt.cont;____BAH_COMPILER_VAR_724[2] = " = ";____BAH_COMPILER_VAR_724[1] = aev;____BAH_COMPILER_VAR_724[0] = "\n        struct reflectElement ";char * ____BAH_COMPILER_VAR_725 =__Bah_multiple_concat(____BAH_COMPILER_VAR_724, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_725));
char** ____BAH_COMPILER_VAR_726 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_726[1] = aev;____BAH_COMPILER_VAR_726[0] = "&";char * ____BAH_COMPILER_VAR_727 =__Bah_multiple_concat(____BAH_COMPILER_VAR_726, 2);arrElem = ____BAH_COMPILER_VAR_727;
}
char * isStruct = "0";
struct cStruct* ts = searchStruct(tt,elems);
char * structLayout = "0";
if ((ts!=null)) {
isStruct = "1";
structLayout = genCompilerVar();
struct variable* ____BAH_COMPILER_VAR_728 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_728->name = "";
____BAH_COMPILER_VAR_728->type = "";
____BAH_COMPILER_VAR_728->constVal = "";
____BAH_COMPILER_VAR_728->from = "";
struct variable* slv = ____BAH_COMPILER_VAR_728;
slv->name = structLayout;
slv->type = "[]reflectElement";

    unsigned int ____BAH_COMPILER_VAR_729 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_729);
    elems->vars->data[____BAH_COMPILER_VAR_729] = slv;
struct rope* dataLayout = rope("");
register long int i = 0;
for (; (i<len(ts->members)); ++i) {
struct structMemb* m = ts->members->data[i];
if ((strcmp(m->type, tt) == 0)) {
struct structMemb* ____BAH_COMPILER_VAR_730 = memoryAlloc(sizeof(struct structMemb));
____BAH_COMPILER_VAR_730->name = "";
____BAH_COMPILER_VAR_730->type = "";
____BAH_COMPILER_VAR_730->constVal = "";
____BAH_COMPILER_VAR_730->from = "";
____BAH_COMPILER_VAR_730->def = "";
struct structMemb* nm = ____BAH_COMPILER_VAR_730;
*nm = *m;
m = nm;
m->type = "ptr";
}
struct Tok ____BAH_COMPILER_VAR_731 = {};
____BAH_COMPILER_VAR_731.cont = "";
____BAH_COMPILER_VAR_731.ogCont = "";
____BAH_COMPILER_VAR_731.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_731.line = 1;
____BAH_COMPILER_VAR_731.begLine = 1;
____BAH_COMPILER_VAR_731.bahType = "";
struct Tok tmpT = ____BAH_COMPILER_VAR_731;
tmpT.type = TOKEN_TYPE_VAR;
char * sep = "->";
if ((strCount(tt,"*")==0)) {
sep = ".";
}
struct string mCtype = getCType(m->type,elems);
struct string offsetTT = string(tt);
string__replace(&offsetTT,"*","");
char** ____BAH_COMPILER_VAR_732 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_732[8] = "))";____BAH_COMPILER_VAR_732[7] = m->name;____BAH_COMPILER_VAR_732[6] = ", ";____BAH_COMPILER_VAR_732[5] = string__str(&offsetTT);____BAH_COMPILER_VAR_732[4] = ") + offsetof(struct ";____BAH_COMPILER_VAR_732[3] = t.cont;____BAH_COMPILER_VAR_732[2] = "*)((char*)(";____BAH_COMPILER_VAR_732[1] = string__str(&mCtype);____BAH_COMPILER_VAR_732[0] = "(";char * ____BAH_COMPILER_VAR_733 =__Bah_multiple_concat(____BAH_COMPILER_VAR_732, 9);tmpT.cont = ____BAH_COMPILER_VAR_733;
char** ____BAH_COMPILER_VAR_734 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_734[4] = ")";____BAH_COMPILER_VAR_734[3] = m->name;____BAH_COMPILER_VAR_734[2] = ", ";____BAH_COMPILER_VAR_734[1] = string__str(&offsetTT);____BAH_COMPILER_VAR_734[0] = "offsetof(struct ";char * ____BAH_COMPILER_VAR_735 =__Bah_multiple_concat(____BAH_COMPILER_VAR_734, 5);struct Tok rt = parseReflect(tmpT,m->type,elems,true,m->name,____BAH_COMPILER_VAR_735);
char** ____BAH_COMPILER_VAR_736 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_736[5] = ";\n";____BAH_COMPILER_VAR_736[4] = rt.cont;____BAH_COMPILER_VAR_736[3] = "] = ";____BAH_COMPILER_VAR_736[2] = intToStr(i);____BAH_COMPILER_VAR_736[1] = "->data[";____BAH_COMPILER_VAR_736[0] = structLayout;char * ____BAH_COMPILER_VAR_737 =__Bah_multiple_concat(____BAH_COMPILER_VAR_736, 6);dataLayout = rope__add(dataLayout, rope(____BAH_COMPILER_VAR_737));
};
char** ____BAH_COMPILER_VAR_738 = alloca(15 * sizeof(char*));____BAH_COMPILER_VAR_738[14] = "->elemSize);\n        ";____BAH_COMPILER_VAR_738[13] = structLayout;____BAH_COMPILER_VAR_738[12] = "->length * ";____BAH_COMPILER_VAR_738[11] = structLayout;____BAH_COMPILER_VAR_738[10] = "->data = memoryAlloc(";____BAH_COMPILER_VAR_738[9] = structLayout;____BAH_COMPILER_VAR_738[8] = ";\n        ";____BAH_COMPILER_VAR_738[7] = intToStr(len(ts->members));____BAH_COMPILER_VAR_738[6] = "->length = ";____BAH_COMPILER_VAR_738[5] = structLayout;____BAH_COMPILER_VAR_738[4] = "->elemSize = sizeof(struct reflectElement);\n        ";____BAH_COMPILER_VAR_738[3] = structLayout;____BAH_COMPILER_VAR_738[2] = " = memoryAlloc(sizeof(array(struct reflectElement)));\n        ";____BAH_COMPILER_VAR_738[1] = structLayout;____BAH_COMPILER_VAR_738[0] = "\n        array(struct reflectElement) * ";char * ____BAH_COMPILER_VAR_739 =__Bah_multiple_concat(____BAH_COMPILER_VAR_738, 15);OUTPUT = rope__add(OUTPUT, rope__add(rope(____BAH_COMPILER_VAR_739), dataLayout));
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
struct variable* ____BAH_COMPILER_VAR_740 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_740->name = "";
____BAH_COMPILER_VAR_740->type = "";
____BAH_COMPILER_VAR_740->constVal = "";
____BAH_COMPILER_VAR_740->from = "";
struct variable* rv = ____BAH_COMPILER_VAR_740;
rv->name = genCompilerVar();
rv->type = "reflectElement";

    unsigned int ____BAH_COMPILER_VAR_741 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_741);
    elems->vars->data[____BAH_COMPILER_VAR_741] = rv;
char** ____BAH_COMPILER_VAR_742 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_742[2] = "\"";____BAH_COMPILER_VAR_742[1] = tt;____BAH_COMPILER_VAR_742[0] = "\"";char * ____BAH_COMPILER_VAR_743 =__Bah_multiple_concat(____BAH_COMPILER_VAR_742, 3);char** ____BAH_COMPILER_VAR_744 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_744[2] = "\"";____BAH_COMPILER_VAR_744[1] = string__str(&name);____BAH_COMPILER_VAR_744[0] = "\"";char * ____BAH_COMPILER_VAR_745 =__Bah_multiple_concat(____BAH_COMPILER_VAR_744, 3);char** ____BAH_COMPILER_VAR_746 = alloca(22 * sizeof(char*));____BAH_COMPILER_VAR_746[21] = ");\n";____BAH_COMPILER_VAR_746[20] = offset;____BAH_COMPILER_VAR_746[19] = ", ";____BAH_COMPILER_VAR_746[18] = structLayout;____BAH_COMPILER_VAR_746[17] = ", ";____BAH_COMPILER_VAR_746[16] = isStruct;____BAH_COMPILER_VAR_746[15] = ", ";____BAH_COMPILER_VAR_746[14] = arrElem;____BAH_COMPILER_VAR_746[13] = ", ";____BAH_COMPILER_VAR_746[12] = isArr;____BAH_COMPILER_VAR_746[11] = ", ";____BAH_COMPILER_VAR_746[10] = strLitteralToBahStr(____BAH_COMPILER_VAR_745);____BAH_COMPILER_VAR_746[9] = ", ";____BAH_COMPILER_VAR_746[8] = strLitteralToBahStr(____BAH_COMPILER_VAR_743);____BAH_COMPILER_VAR_746[7] = "), ";____BAH_COMPILER_VAR_746[6] = string__str(&cType);____BAH_COMPILER_VAR_746[5] = ", sizeof(";____BAH_COMPILER_VAR_746[4] = t.cont;____BAH_COMPILER_VAR_746[3] = amp;____BAH_COMPILER_VAR_746[2] = " = __reflect(";____BAH_COMPILER_VAR_746[1] = rv->name;____BAH_COMPILER_VAR_746[0] = "struct reflectElement ";char * ____BAH_COMPILER_VAR_747 =__Bah_multiple_concat(____BAH_COMPILER_VAR_746, 22);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_747));
t.cont = rv->name;
return t;
};
char * parseArrayDecl(struct variable* v,__BAH_ARR_TYPE_Tok l,long int i,long int max,struct Elems* elems){
long int arrayLength = 0;
struct string arrType = getCType(v->type,elems);
string__trimRight(&arrType,1);
char** ____BAH_COMPILER_VAR_748 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_748[2] = "))";____BAH_COMPILER_VAR_748[1] = string__str(&arrType);____BAH_COMPILER_VAR_748[0] = "memoryAlloc(sizeof(";char * ____BAH_COMPILER_VAR_749 =__Bah_multiple_concat(____BAH_COMPILER_VAR_748, 3);char * code = ____BAH_COMPILER_VAR_749;
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

    unsigned int ____BAH_COMPILER_VAR_750 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_750);
    memory->data[____BAH_COMPILER_VAR_750] = l->data[i];
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
struct variable* ____BAH_COMPILER_VAR_751 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_751->name = "";
____BAH_COMPILER_VAR_751->type = "";
____BAH_COMPILER_VAR_751->constVal = "";
____BAH_COMPILER_VAR_751->from = "";
struct variable* tmpV = ____BAH_COMPILER_VAR_751;
tmpV->name = genCompilerVar();
struct string elemType = string(v->type);
string__trimLeft(&elemType,2);
tmpV->type = string__str(&elemType);

    unsigned int ____BAH_COMPILER_VAR_752 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_752);
    elems->vars->data[____BAH_COMPILER_VAR_752] = tmpV;
char * oldNL = NEXT_LINE;
NEXT_LINE = "";
char * innerCode = parseArrayDecl(tmpV,memory,j,i+1,elems);
char * ____BAH_COMPILER_VAR_753 =string__str(&elemType);struct string cType = getCType(____BAH_COMPILER_VAR_753,elems);
char** ____BAH_COMPILER_VAR_754 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_754[8] = "\n                ";____BAH_COMPILER_VAR_754[7] = NEXT_LINE;____BAH_COMPILER_VAR_754[6] = ";\n                ";____BAH_COMPILER_VAR_754[5] = innerCode;____BAH_COMPILER_VAR_754[4] = " = ";____BAH_COMPILER_VAR_754[3] = tmpV->name;____BAH_COMPILER_VAR_754[2] = ") * ";____BAH_COMPILER_VAR_754[1] = string__str(&cType);____BAH_COMPILER_VAR_754[0] = "\n                array(";char * ____BAH_COMPILER_VAR_755 =__Bah_multiple_concat(____BAH_COMPILER_VAR_754, 9);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_755));
NEXT_LINE = oldNL;
struct Tok ____BAH_COMPILER_VAR_756 = {};
____BAH_COMPILER_VAR_756.cont = "";
____BAH_COMPILER_VAR_756.ogCont = "";
____BAH_COMPILER_VAR_756.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_756.line = 1;
____BAH_COMPILER_VAR_756.begLine = 1;
____BAH_COMPILER_VAR_756.bahType = "";
____BAH_COMPILER_VAR_756.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_756.cont = tmpV->name;
____BAH_COMPILER_VAR_756.bahType = string__str(&elemType);
____BAH_COMPILER_VAR_756.isValue = true;
t = ____BAH_COMPILER_VAR_756;
}
char * tt = getTypeFromToken(&t,true,elems);
if (__builtin_expect((compTypes(tt,elemBahTypeStr)==false), 0)) {
char** ____BAH_COMPILER_VAR_757 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_757[3] = elemBahTypeStr;____BAH_COMPILER_VAR_757[2] = ") as ";____BAH_COMPILER_VAR_757[1] = tt;____BAH_COMPILER_VAR_757[0] = "Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_758 =__Bah_multiple_concat(____BAH_COMPILER_VAR_757, 4);throwErr(&t,____BAH_COMPILER_VAR_758);
}
char * strArrayLength = intToStr(arrayLength);
arrayLength = arrayLength+1;
char** ____BAH_COMPILER_VAR_759 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_759[6] = ";\n";____BAH_COMPILER_VAR_759[5] = t.cont;____BAH_COMPILER_VAR_759[4] = "] = ";____BAH_COMPILER_VAR_759[3] = strArrayLength;____BAH_COMPILER_VAR_759[2] = "->data[";____BAH_COMPILER_VAR_759[1] = v->name;____BAH_COMPILER_VAR_759[0] = NEXT_LINE;char * ____BAH_COMPILER_VAR_760 =__Bah_multiple_concat(____BAH_COMPILER_VAR_759, 7);NEXT_LINE = ____BAH_COMPILER_VAR_760;
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
char** ____BAH_COMPILER_VAR_761 = alloca(11 * sizeof(char*));____BAH_COMPILER_VAR_761[10] = NEXT_LINE;____BAH_COMPILER_VAR_761[9] = ";\n";____BAH_COMPILER_VAR_761[8] = allocLengthStr;____BAH_COMPILER_VAR_761[7] = "->realLength = ";____BAH_COMPILER_VAR_761[6] = v->name;____BAH_COMPILER_VAR_761[5] = ");\n                    ";____BAH_COMPILER_VAR_761[4] = allocLengthStr;____BAH_COMPILER_VAR_761[3] = ") * ";____BAH_COMPILER_VAR_761[2] = elemTypeStr;____BAH_COMPILER_VAR_761[1] = "->data = memoryAlloc(sizeof(";____BAH_COMPILER_VAR_761[0] = v->name;char * ____BAH_COMPILER_VAR_762 =__Bah_multiple_concat(____BAH_COMPILER_VAR_761, 11);NEXT_LINE = ____BAH_COMPILER_VAR_762;
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
char** ____BAH_COMPILER_VAR_763 = alloca(10 * sizeof(char*));____BAH_COMPILER_VAR_763[9] = NEXT_LINE;____BAH_COMPILER_VAR_763[8] = ");\n";____BAH_COMPILER_VAR_763[7] = elemTypeStr;____BAH_COMPILER_VAR_763[6] = "->elemSize = sizeof(";____BAH_COMPILER_VAR_763[5] = v->name;____BAH_COMPILER_VAR_763[4] = ";\n";____BAH_COMPILER_VAR_763[3] = strArrayLength;____BAH_COMPILER_VAR_763[2] = "->length = ";____BAH_COMPILER_VAR_763[1] = v->name;____BAH_COMPILER_VAR_763[0] = "\n";char * ____BAH_COMPILER_VAR_764 =__Bah_multiple_concat(____BAH_COMPILER_VAR_763, 10);NEXT_LINE = ____BAH_COMPILER_VAR_764;
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
char** ____BAH_COMPILER_VAR_765 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_765[1] = ";\n";____BAH_COMPILER_VAR_765[0] = ft.cont;char * ____BAH_COMPILER_VAR_766 =__Bah_multiple_concat(____BAH_COMPILER_VAR_765, 2);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_766));
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
struct variable* ____BAH_COMPILER_VAR_767 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_767->name = "";
____BAH_COMPILER_VAR_767->type = "";
____BAH_COMPILER_VAR_767->constVal = "";
____BAH_COMPILER_VAR_767->from = "";
v = ____BAH_COMPILER_VAR_767;
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
char * ____BAH_COMPILER_VAR_768 =string__str(&c);v = searchVar(____BAH_COMPILER_VAR_768,elems);
if (__builtin_expect((v==null), 0)) {
throwErr(&t,"Cannot increase/decrease not declared variable {TOKEN}.");
}
char** ____BAH_COMPILER_VAR_769 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_769[1] = ";\n";____BAH_COMPILER_VAR_769[0] = t.cont;char * ____BAH_COMPILER_VAR_770 =__Bah_multiple_concat(____BAH_COMPILER_VAR_769, 2);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_770));
return;
}
if (__builtin_expect((len(l)<2), 0)) {
throwErr(&ft,"Missing '=' after {TOKEN}.");
}
struct Tok operT = l->data[1];
char * ____BAH_COMPILER_VAR_772 =operT.cont;
        char ____BAH_COMPILER_VAR_771 = 0;
        for(int i=equalsTokens->length-1; i!=-1;i--) {
            if (equalsTokens->data[i] != 0 && strcmp(equalsTokens->data[i], ____BAH_COMPILER_VAR_772) == 0) {
                ____BAH_COMPILER_VAR_771=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_771&&(strcmp(operT.cont, "=") != 0)) {
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

    unsigned int ____BAH_COMPILER_VAR_773 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_773);
    nl->data[____BAH_COMPILER_VAR_773] = operT;
register long int j = 0;
for (; (j<len(tmpL)); ++j) {

    unsigned int ____BAH_COMPILER_VAR_774 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_774);
    nl->data[____BAH_COMPILER_VAR_774] = tmpL->data[j];
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
char** ____BAH_COMPILER_VAR_775 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_775[1] = t.cont;____BAH_COMPILER_VAR_775[0] = currentType;char * ____BAH_COMPILER_VAR_776 =__Bah_multiple_concat(____BAH_COMPILER_VAR_775, 2);currentType = ____BAH_COMPILER_VAR_776;
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
char** ____BAH_COMPILER_VAR_777 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_777[1] = nt.cont;____BAH_COMPILER_VAR_777[0] = "chan:";char * ____BAH_COMPILER_VAR_778 =__Bah_multiple_concat(____BAH_COMPILER_VAR_777, 2);v->type = ____BAH_COMPILER_VAR_778;
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
char** ____BAH_COMPILER_VAR_779 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_779[1] = nt.cont;____BAH_COMPILER_VAR_779[0] = "map:";char * ____BAH_COMPILER_VAR_780 =__Bah_multiple_concat(____BAH_COMPILER_VAR_779, 2);v->type = ____BAH_COMPILER_VAR_780;
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
char** ____BAH_COMPILER_VAR_781 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_781[1] = nt.cont;____BAH_COMPILER_VAR_781[0] = "buffer:";char * ____BAH_COMPILER_VAR_782 =__Bah_multiple_concat(____BAH_COMPILER_VAR_781, 2);v->type = ____BAH_COMPILER_VAR_782;
struct variable* ____BAH_COMPILER_VAR_783 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_783->name = "";
____BAH_COMPILER_VAR_783->type = "";
____BAH_COMPILER_VAR_783->constVal = "";
____BAH_COMPILER_VAR_783->from = "";
struct variable* av = ____BAH_COMPILER_VAR_783;
av->type = "char*";
av->name = genCompilerVar();

    unsigned int ____BAH_COMPILER_VAR_784 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_784);
    elems->vars->data[____BAH_COMPILER_VAR_784] = av;
struct string cType = getCType(av->type,elems);
char** ____BAH_COMPILER_VAR_785 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_785[4] = "];";____BAH_COMPILER_VAR_785[3] = nt.cont;____BAH_COMPILER_VAR_785[2] = "[";____BAH_COMPILER_VAR_785[1] = av->name;____BAH_COMPILER_VAR_785[0] = "char ";char * ____BAH_COMPILER_VAR_786 =__Bah_multiple_concat(____BAH_COMPILER_VAR_785, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_786));
code = av->name;
if (__builtin_expect((i+1!=len(l)), 0)) {
struct Tok errT = l->data[i+1];
throwErr(&errT,"{TOKEN} not expected after buffer declaration.");
}
break;
}
char * tp = getTypeFromToken(&t,true,elems);

                struct string ____BAH_COMPILER_VAR_787 = string(compilerState.currentDir);
                if ((isUnsafe==false)&&(string__hasPrefix(&____BAH_COMPILER_VAR_787,BAH_DIR)==false)&&isRCPpointerType(tp)) {
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
char** ____BAH_COMPILER_VAR_788 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_788[4] = ".";____BAH_COMPILER_VAR_788[3] = v->type;____BAH_COMPILER_VAR_788[2] = ") as ";____BAH_COMPILER_VAR_788[1] = tp;____BAH_COMPILER_VAR_788[0] = "Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_789 =__Bah_multiple_concat(____BAH_COMPILER_VAR_788, 5);throwErr(&t,____BAH_COMPILER_VAR_789);
}
}
else {
if ((strcmp(currentType, "") == 0)) {
if ((strcmp(v->type, "") == 0)) {
v->type = tp;
}
else {
if (__builtin_expect((compTypes(tp,v->type)==false), 0)) {
char** ____BAH_COMPILER_VAR_790 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_790[4] = ".";____BAH_COMPILER_VAR_790[3] = v->type;____BAH_COMPILER_VAR_790[2] = ") as ";____BAH_COMPILER_VAR_790[1] = tp;____BAH_COMPILER_VAR_790[0] = "Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_791 =__Bah_multiple_concat(____BAH_COMPILER_VAR_790, 5);throwErr(&t,____BAH_COMPILER_VAR_791);
}
}
}
}
if ((RAIIenabled==true)&&(t.type==TOKEN_TYPE_VAR)&&isRCPtype(tp,elems)) {
char * ____BAH_COMPILER_VAR_792 =removeCast(t.cont);struct variable* ov = searchVar(____BAH_COMPILER_VAR_792,elems);
if ((ov!=null)) {
register long int k = 0;
for (; (k<len(elems->vars)); ++k) {
if ((strcmp(elems->vars->data[k]->name, ov->name) == 0)) {

    unsigned int ____BAH_COMPILER_VAR_793 = len(elems->deletedVars);
    __Bah_realocate_arr(elems->deletedVars, ____BAH_COMPILER_VAR_793);
    elems->deletedVars->data[____BAH_COMPILER_VAR_793] = elems->vars->data[k];
delete(elems->vars,k);
break;
}
};
}
}
if ((strcmp(t.cont, "") != 0)&&(strHasPrefix(t.cont,"{")==false)) {
char** ____BAH_COMPILER_VAR_794 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_794[1] = t.cont;____BAH_COMPILER_VAR_794[0] = code;char * ____BAH_COMPILER_VAR_795 =__Bah_multiple_concat(____BAH_COMPILER_VAR_794, 2);code = ____BAH_COMPILER_VAR_795;
if ((t.isOper==false)&&(RCPavailable()==true)) {
struct variable* iv = searchVar(t.cont,elems);
if ((iv!=null)&&(iv->isConst==false)) {
toVar = true;
isPointedVar = strHasPrefix(t.cont,"&");
struct cStruct* s = searchStruct(iv->type,elems);
if ((s!=null)&&(strCount(iv->type,"*")==0)&&(s->isBinding==false)) {
if ((strCount(iv->name,"*")==0)) {
char** ____BAH_COMPILER_VAR_796 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_796[5] = "), 0)";____BAH_COMPILER_VAR_796[4] = iv->name;____BAH_COMPILER_VAR_796[3] = ", sizeof(";____BAH_COMPILER_VAR_796[2] = iv->name;____BAH_COMPILER_VAR_796[1] = "; RCP_scanStack(&";____BAH_COMPILER_VAR_796[0] = code;char * ____BAH_COMPILER_VAR_797 =__Bah_multiple_concat(____BAH_COMPILER_VAR_796, 6);code = ____BAH_COMPILER_VAR_797;
}
else {
struct string ivn = string(iv->name);
if ((string__count(&ivn,"*")>0)) {
string__replace(&ivn,"*","");
char** ____BAH_COMPILER_VAR_798 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_798[4] = "), 0)";____BAH_COMPILER_VAR_798[3] = iv->name;____BAH_COMPILER_VAR_798[2] = ", sizeof(";____BAH_COMPILER_VAR_798[1] = string__str(&ivn);____BAH_COMPILER_VAR_798[0] = "; RCP_scanStack(";char * ____BAH_COMPILER_VAR_799 =__Bah_multiple_concat(____BAH_COMPILER_VAR_798, 5);char** ____BAH_COMPILER_VAR_800 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_800[1] = ____BAH_COMPILER_VAR_799;____BAH_COMPILER_VAR_800[0] = code;char * ____BAH_COMPILER_VAR_801 =__Bah_multiple_concat(____BAH_COMPILER_VAR_800, 2);code = ____BAH_COMPILER_VAR_801;
}
else {
char** ____BAH_COMPILER_VAR_802 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_802[3] = ")";____BAH_COMPILER_VAR_802[2] = iv->name;____BAH_COMPILER_VAR_802[1] = "; RCP_incr(";____BAH_COMPILER_VAR_802[0] = code;char * ____BAH_COMPILER_VAR_803 =__Bah_multiple_concat(____BAH_COMPILER_VAR_802, 4);code = ____BAH_COMPILER_VAR_803;
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
char** ____BAH_COMPILER_VAR_804 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_804[1] = t.cont;____BAH_COMPILER_VAR_804[0] = code;char * ____BAH_COMPILER_VAR_805 =__Bah_multiple_concat(____BAH_COMPILER_VAR_804, 2);code = ____BAH_COMPILER_VAR_805;
}
++i;
};
if ((exists==true)) {
v->lastSet = elems;
if ((ft.parent!=null)) {
ft.parent->lastSet = elems;
}
if ((currentFn!=null)) {

                struct string ____BAH_COMPILER_VAR_806 = string(v->name);
                if ((strcmp(v->name, "this") == 0)||string__hasPrefix(&____BAH_COMPILER_VAR_806,"this->")) {
currentFn->isMut = true;
}
}
if (__builtin_expect((strlen(code)==0), 0)) {
throwErr(&ft,"Cannot re-declare {TOKEN}.");
}
if (__builtin_expect((strlen(currentType)>0), 0)) {
struct Tok st = l->data[1];
char** ____BAH_COMPILER_VAR_807 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_807[2] = "' to {TOKEN}.";____BAH_COMPILER_VAR_807[1] = ft.cont;____BAH_COMPILER_VAR_807[0] = "Cannot change the type of already declared var '";char * ____BAH_COMPILER_VAR_808 =__Bah_multiple_concat(____BAH_COMPILER_VAR_807, 3);throwErr(&st,____BAH_COMPILER_VAR_808);
}
char * preCode = "";
char * val = code;
if ((isStruct==false)) {
if (isRCPpointerType(v->type)&&(isPointedVar==false)&&(RCPavailable()==true)) {
struct string cType = getCType(v->type,elems);
if ((toVar==true)) {
if ((RCPselfRef(v)==false)) {
char** ____BAH_COMPILER_VAR_809 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_809[8] = ")";____BAH_COMPILER_VAR_809[7] = code;____BAH_COMPILER_VAR_809[6] = "*)RCP_incrIL(&";____BAH_COMPILER_VAR_809[5] = string__str(&cType);____BAH_COMPILER_VAR_809[4] = ") = *(";____BAH_COMPILER_VAR_809[3] = v->name;____BAH_COMPILER_VAR_809[2] = "*)RCP_decrIL(&";____BAH_COMPILER_VAR_809[1] = string__str(&cType);____BAH_COMPILER_VAR_809[0] = "*(";char * ____BAH_COMPILER_VAR_810 =__Bah_multiple_concat(____BAH_COMPILER_VAR_809, 9);code = ____BAH_COMPILER_VAR_810;
}
else {
struct variable* ____BAH_COMPILER_VAR_811 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_811->name = "";
____BAH_COMPILER_VAR_811->type = "";
____BAH_COMPILER_VAR_811->constVal = "";
____BAH_COMPILER_VAR_811->from = "";
struct variable* tmpV = ____BAH_COMPILER_VAR_811;
tmpV->name = genCompilerVar();
tmpV->type = v->type;
struct rope* dv = decrVar(tmpV,elems);
char** ____BAH_COMPILER_VAR_812 = alloca(13 * sizeof(char*));____BAH_COMPILER_VAR_812[12] = rope__toStr(dv);____BAH_COMPILER_VAR_812[11] = ");";____BAH_COMPILER_VAR_812[10] = code;____BAH_COMPILER_VAR_812[9] = "*)RCP_incrIL(&";____BAH_COMPILER_VAR_812[8] = string__str(&cType);____BAH_COMPILER_VAR_812[7] = " = *(";____BAH_COMPILER_VAR_812[6] = v->name;____BAH_COMPILER_VAR_812[5] = "; ";____BAH_COMPILER_VAR_812[4] = v->name;____BAH_COMPILER_VAR_812[3] = " = ";____BAH_COMPILER_VAR_812[2] = tmpV->name;____BAH_COMPILER_VAR_812[1] = " ";____BAH_COMPILER_VAR_812[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_813 =__Bah_multiple_concat(____BAH_COMPILER_VAR_812, 13);code = ____BAH_COMPILER_VAR_813;
}
}
else {
struct variable* ____BAH_COMPILER_VAR_814 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_814->name = "";
____BAH_COMPILER_VAR_814->type = "";
____BAH_COMPILER_VAR_814->constVal = "";
____BAH_COMPILER_VAR_814->from = "";
struct variable* tmpV = ____BAH_COMPILER_VAR_814;
tmpV->name = genCompilerVar();
tmpV->type = v->type;
struct rope* dv = decrVar(tmpV,elems);
char** ____BAH_COMPILER_VAR_815 = alloca(11 * sizeof(char*));____BAH_COMPILER_VAR_815[10] = rope__toStr(dv);____BAH_COMPILER_VAR_815[9] = ";";____BAH_COMPILER_VAR_815[8] = code;____BAH_COMPILER_VAR_815[7] = " = ";____BAH_COMPILER_VAR_815[6] = v->name;____BAH_COMPILER_VAR_815[5] = "; ";____BAH_COMPILER_VAR_815[4] = v->name;____BAH_COMPILER_VAR_815[3] = " = ";____BAH_COMPILER_VAR_815[2] = tmpV->name;____BAH_COMPILER_VAR_815[1] = " ";____BAH_COMPILER_VAR_815[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_816 =__Bah_multiple_concat(____BAH_COMPILER_VAR_815, 11);code = ____BAH_COMPILER_VAR_816;
}
}
else {
struct cStruct* s = searchStruct(v->type,elems);
if ((s!=null)&&(RCPavailable()==true)&&(RCPselfRef(v)==false)&&(s->isBinding==false)) {
if ((strCount(v->name,"*")==0)) {
char** ____BAH_COMPILER_VAR_817 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_817[4] = "), 1); ";____BAH_COMPILER_VAR_817[3] = v->name;____BAH_COMPILER_VAR_817[2] = ", sizeof(";____BAH_COMPILER_VAR_817[1] = v->name;____BAH_COMPILER_VAR_817[0] = "RCP_scanStack(&";char * ____BAH_COMPILER_VAR_818 =__Bah_multiple_concat(____BAH_COMPILER_VAR_817, 5);preCode = ____BAH_COMPILER_VAR_818;
}
else {
struct string vn = string(v->name);
string__replace(&vn,"*","");
char** ____BAH_COMPILER_VAR_819 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_819[4] = "), 1); ";____BAH_COMPILER_VAR_819[3] = v->name;____BAH_COMPILER_VAR_819[2] = ", sizeof(";____BAH_COMPILER_VAR_819[1] = string__str(&vn);____BAH_COMPILER_VAR_819[0] = "RCP_scanStack(";char * ____BAH_COMPILER_VAR_820 =__Bah_multiple_concat(____BAH_COMPILER_VAR_819, 5);preCode = ____BAH_COMPILER_VAR_820;
}
char** ____BAH_COMPILER_VAR_821 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_821[2] = code;____BAH_COMPILER_VAR_821[1] = " = ";____BAH_COMPILER_VAR_821[0] = v->name;char * ____BAH_COMPILER_VAR_822 =__Bah_multiple_concat(____BAH_COMPILER_VAR_821, 3);code = ____BAH_COMPILER_VAR_822;
}
else {
char** ____BAH_COMPILER_VAR_823 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_823[2] = code;____BAH_COMPILER_VAR_823[1] = " = ";____BAH_COMPILER_VAR_823[0] = v->name;char * ____BAH_COMPILER_VAR_824 =__Bah_multiple_concat(____BAH_COMPILER_VAR_823, 3);code = ____BAH_COMPILER_VAR_824;
}
}
}
else {
strTrim(&code);
if ((strHasPrefix(code,"{")==false)) {
char** ____BAH_COMPILER_VAR_825 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_825[2] = code;____BAH_COMPILER_VAR_825[1] = " = ";____BAH_COMPILER_VAR_825[0] = v->name;char * ____BAH_COMPILER_VAR_826 =__Bah_multiple_concat(____BAH_COMPILER_VAR_825, 3);code = ____BAH_COMPILER_VAR_826;
}
}
if ((v->isArray==true)) {
code = genArrRealloc(v,preCode,val,elems);
}
else {
char** ____BAH_COMPILER_VAR_827 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_827[1] = code;____BAH_COMPILER_VAR_827[0] = preCode;char * ____BAH_COMPILER_VAR_828 =__Bah_multiple_concat(____BAH_COMPILER_VAR_827, 2);code = ____BAH_COMPILER_VAR_828;
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
char** ____BAH_COMPILER_VAR_829 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_829[1] = string__str(&ct);____BAH_COMPILER_VAR_829[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_830 =__Bah_multiple_concat(____BAH_COMPILER_VAR_829, 2);tmpfnArgsCType = ____BAH_COMPILER_VAR_830;
j = j+1;
if ((j<len(tmpfn->args))) {
char** ____BAH_COMPILER_VAR_831 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_831[1] = ",";____BAH_COMPILER_VAR_831[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_832 =__Bah_multiple_concat(____BAH_COMPILER_VAR_831, 2);tmpfnArgsCType = ____BAH_COMPILER_VAR_832;
}
};
char** ____BAH_COMPILER_VAR_833 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_833[5] = ")";____BAH_COMPILER_VAR_833[4] = tmpfnArgsCType;____BAH_COMPILER_VAR_833[3] = ")(";____BAH_COMPILER_VAR_833[2] = v->name;____BAH_COMPILER_VAR_833[1] = " (*";____BAH_COMPILER_VAR_833[0] = string__str(&tmpfnRetCType);char * ____BAH_COMPILER_VAR_834 =__Bah_multiple_concat(____BAH_COMPILER_VAR_833, 6);vct = ____BAH_COMPILER_VAR_834;
}
else {
vct = setCType(v,elems);
}
if ((strcmp(code, "") != 0)&&(shouldOnlyDecl==false)) {
if (isRCPpointerType(v->type)&&(RCPavailable()==true)&&(toVar==true)&&(isPointedVar==false)) {
struct string cType = getCType(v->type,elems);
if (isGlobal()) {
char** ____BAH_COMPILER_VAR_835 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_835[5] = ");\n";____BAH_COMPILER_VAR_835[4] = code;____BAH_COMPILER_VAR_835[3] = "*)RCP_incrIL(&";____BAH_COMPILER_VAR_835[2] = string__str(&cType);____BAH_COMPILER_VAR_835[1] = " = *(";____BAH_COMPILER_VAR_835[0] = v->name;char * ____BAH_COMPILER_VAR_836 =__Bah_multiple_concat(____BAH_COMPILER_VAR_835, 6);INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_836));
}
else {
char** ____BAH_COMPILER_VAR_837 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_837[5] = ")";____BAH_COMPILER_VAR_837[4] = code;____BAH_COMPILER_VAR_837[3] = "*)RCP_incrIL(&";____BAH_COMPILER_VAR_837[2] = string__str(&cType);____BAH_COMPILER_VAR_837[1] = " = *(";____BAH_COMPILER_VAR_837[0] = vct;char * ____BAH_COMPILER_VAR_838 =__Bah_multiple_concat(____BAH_COMPILER_VAR_837, 6);code = ____BAH_COMPILER_VAR_838;
}
}
else {
if (isGlobal()) {
char** ____BAH_COMPILER_VAR_839 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_839[3] = ";\n";____BAH_COMPILER_VAR_839[2] = code;____BAH_COMPILER_VAR_839[1] = " = ";____BAH_COMPILER_VAR_839[0] = v->name;char * ____BAH_COMPILER_VAR_840 =__Bah_multiple_concat(____BAH_COMPILER_VAR_839, 4);INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_840));
}
else {
char** ____BAH_COMPILER_VAR_841 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_841[2] = code;____BAH_COMPILER_VAR_841[1] = " = ";____BAH_COMPILER_VAR_841[0] = vct;char * ____BAH_COMPILER_VAR_842 =__Bah_multiple_concat(____BAH_COMPILER_VAR_841, 3);code = ____BAH_COMPILER_VAR_842;
}
}
}
else {
if (isRCPpointerType(v->type)&&(shouldOnlyDecl==false)) {
char** ____BAH_COMPILER_VAR_843 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_843[1] = "= null";____BAH_COMPILER_VAR_843[0] = vct;char * ____BAH_COMPILER_VAR_844 =__Bah_multiple_concat(____BAH_COMPILER_VAR_843, 2);code = ____BAH_COMPILER_VAR_844;
}
else {
code = vct;
}
}
if ((shouldOnlyDecl==true)) {
char** ____BAH_COMPILER_VAR_845 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_845[1] = vct;____BAH_COMPILER_VAR_845[0] = "extern ";char * ____BAH_COMPILER_VAR_846 =__Bah_multiple_concat(____BAH_COMPILER_VAR_845, 2);vct = ____BAH_COMPILER_VAR_846;
}
if (isGlobal()) {
v->isGlobal = true;
}
else {
v->isGlobal = false;
}
v->declScope = elems;

    unsigned int ____BAH_COMPILER_VAR_847 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_847);
    elems->vars->data[____BAH_COMPILER_VAR_847] = v;
if (fixMeEnabled()) {
fixMeRegisterVar(v,&ft);
}
struct variable* ____BAH_COMPILER_VAR_848 = v;
char ** ____BAH_COMPILER_VAR_850 = (char **)((char*)(____BAH_COMPILER_VAR_848) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_851 = __reflect(____BAH_COMPILER_VAR_850, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_852 = (char **)((char*)(____BAH_COMPILER_VAR_848) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_853 = __reflect(____BAH_COMPILER_VAR_852, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_854 = (char*)((char*)(____BAH_COMPILER_VAR_848) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_855 = __reflect(____BAH_COMPILER_VAR_854, sizeof(char), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_856 = (char **)((char*)(____BAH_COMPILER_VAR_848) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_857 = __reflect(____BAH_COMPILER_VAR_856, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_858 = (char*)((char*)(____BAH_COMPILER_VAR_848) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_859 = __reflect(____BAH_COMPILER_VAR_858, sizeof(char), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_860 = (char **)((char*)(____BAH_COMPILER_VAR_848) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_861 = __reflect(____BAH_COMPILER_VAR_860, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
void ** ____BAH_COMPILER_VAR_862 = (void **)((char*)(____BAH_COMPILER_VAR_848) + offsetof(struct variable, declScope));
struct reflectElement ____BAH_COMPILER_VAR_863 = __reflect(____BAH_COMPILER_VAR_862, sizeof(void *), "ptr", "declScope", 0, 0, 0, 0, offsetof(struct variable, declScope));
char* ____BAH_COMPILER_VAR_864 = (char*)((char*)(____BAH_COMPILER_VAR_848) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_865 = __reflect(____BAH_COMPILER_VAR_864, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));
struct rope** ____BAH_COMPILER_VAR_866 = (struct rope**)((char*)(____BAH_COMPILER_VAR_848) + offsetof(struct variable, declRope));
void ** ____BAH_COMPILER_VAR_868 = (void **)((char*)(____BAH_COMPILER_VAR_866) + offsetof(struct rope, left));
struct reflectElement ____BAH_COMPILER_VAR_869 = __reflect(____BAH_COMPILER_VAR_868, sizeof(void *), "ptr", "left", 0, 0, 0, 0, offsetof(struct rope, left));
void ** ____BAH_COMPILER_VAR_870 = (void **)((char*)(____BAH_COMPILER_VAR_866) + offsetof(struct rope, right));
struct reflectElement ____BAH_COMPILER_VAR_871 = __reflect(____BAH_COMPILER_VAR_870, sizeof(void *), "ptr", "right", 0, 0, 0, 0, offsetof(struct rope, right));
char ** ____BAH_COMPILER_VAR_872 = (char **)((char*)(____BAH_COMPILER_VAR_866) + offsetof(struct rope, str));
struct reflectElement ____BAH_COMPILER_VAR_873 = __reflect(____BAH_COMPILER_VAR_872, sizeof(char *), "cpstring", "str", 0, 0, 0, 0, offsetof(struct rope, str));
int* ____BAH_COMPILER_VAR_874 = (int*)((char*)(____BAH_COMPILER_VAR_866) + offsetof(struct rope, lCount));
struct reflectElement ____BAH_COMPILER_VAR_875 = __reflect(____BAH_COMPILER_VAR_874, sizeof(int), "int32", "lCount", 0, 0, 0, 0, offsetof(struct rope, lCount));
int* ____BAH_COMPILER_VAR_876 = (int*)((char*)(____BAH_COMPILER_VAR_866) + offsetof(struct rope, len));
struct reflectElement ____BAH_COMPILER_VAR_877 = __reflect(____BAH_COMPILER_VAR_876, sizeof(int), "int32", "len", 0, 0, 0, 0, offsetof(struct rope, len));
int* ____BAH_COMPILER_VAR_878 = (int*)((char*)(____BAH_COMPILER_VAR_866) + offsetof(struct rope, totalLen));
struct reflectElement ____BAH_COMPILER_VAR_879 = __reflect(____BAH_COMPILER_VAR_878, sizeof(int), "int32", "totalLen", 0, 0, 0, 0, offsetof(struct rope, totalLen));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_867 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_867->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_867->length = 6;
        ____BAH_COMPILER_VAR_867->data = memoryAlloc(____BAH_COMPILER_VAR_867->length * ____BAH_COMPILER_VAR_867->elemSize);
        ____BAH_COMPILER_VAR_867->data[0] = ____BAH_COMPILER_VAR_869;
____BAH_COMPILER_VAR_867->data[1] = ____BAH_COMPILER_VAR_871;
____BAH_COMPILER_VAR_867->data[2] = ____BAH_COMPILER_VAR_873;
____BAH_COMPILER_VAR_867->data[3] = ____BAH_COMPILER_VAR_875;
____BAH_COMPILER_VAR_867->data[4] = ____BAH_COMPILER_VAR_877;
____BAH_COMPILER_VAR_867->data[5] = ____BAH_COMPILER_VAR_879;
struct reflectElement ____BAH_COMPILER_VAR_880 = __reflect(____BAH_COMPILER_VAR_866, sizeof(struct rope), "rope*", "declRope", 0, 0, 1, ____BAH_COMPILER_VAR_867, offsetof(struct variable, declRope));
char* ____BAH_COMPILER_VAR_881 = (char*)((char*)(____BAH_COMPILER_VAR_848) + offsetof(struct variable, canBeNull));
struct reflectElement ____BAH_COMPILER_VAR_882 = __reflect(____BAH_COMPILER_VAR_881, sizeof(char), "bool", "canBeNull", 0, 0, 0, 0, offsetof(struct variable, canBeNull));
char* ____BAH_COMPILER_VAR_883 = (char*)((char*)(____BAH_COMPILER_VAR_848) + offsetof(struct variable, canBeReg));
struct reflectElement ____BAH_COMPILER_VAR_884 = __reflect(____BAH_COMPILER_VAR_883, sizeof(char), "bool", "canBeReg", 0, 0, 0, 0, offsetof(struct variable, canBeReg));
char* ____BAH_COMPILER_VAR_885 = (char*)((char*)(____BAH_COMPILER_VAR_848) + offsetof(struct variable, isReg));
struct reflectElement ____BAH_COMPILER_VAR_886 = __reflect(____BAH_COMPILER_VAR_885, sizeof(char), "bool", "isReg", 0, 0, 0, 0, offsetof(struct variable, isReg));
void ** ____BAH_COMPILER_VAR_887 = (void **)((char*)(____BAH_COMPILER_VAR_848) + offsetof(struct variable, lastSet));
struct reflectElement ____BAH_COMPILER_VAR_888 = __reflect(____BAH_COMPILER_VAR_887, sizeof(void *), "ptr", "lastSet", 0, 0, 0, 0, offsetof(struct variable, lastSet));
char* ____BAH_COMPILER_VAR_889 = (char*)((char*)(____BAH_COMPILER_VAR_848) + offsetof(struct variable, isArg));
struct reflectElement ____BAH_COMPILER_VAR_890 = __reflect(____BAH_COMPILER_VAR_889, sizeof(char), "bool", "isArg", 0, 0, 0, 0, offsetof(struct variable, isArg));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_849 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_849->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_849->length = 14;
        ____BAH_COMPILER_VAR_849->data = memoryAlloc(____BAH_COMPILER_VAR_849->length * ____BAH_COMPILER_VAR_849->elemSize);
        ____BAH_COMPILER_VAR_849->data[0] = ____BAH_COMPILER_VAR_851;
____BAH_COMPILER_VAR_849->data[1] = ____BAH_COMPILER_VAR_853;
____BAH_COMPILER_VAR_849->data[2] = ____BAH_COMPILER_VAR_855;
____BAH_COMPILER_VAR_849->data[3] = ____BAH_COMPILER_VAR_857;
____BAH_COMPILER_VAR_849->data[4] = ____BAH_COMPILER_VAR_859;
____BAH_COMPILER_VAR_849->data[5] = ____BAH_COMPILER_VAR_861;
____BAH_COMPILER_VAR_849->data[6] = ____BAH_COMPILER_VAR_863;
____BAH_COMPILER_VAR_849->data[7] = ____BAH_COMPILER_VAR_865;
____BAH_COMPILER_VAR_849->data[8] = ____BAH_COMPILER_VAR_880;
____BAH_COMPILER_VAR_849->data[9] = ____BAH_COMPILER_VAR_882;
____BAH_COMPILER_VAR_849->data[10] = ____BAH_COMPILER_VAR_884;
____BAH_COMPILER_VAR_849->data[11] = ____BAH_COMPILER_VAR_886;
____BAH_COMPILER_VAR_849->data[12] = ____BAH_COMPILER_VAR_888;
____BAH_COMPILER_VAR_849->data[13] = ____BAH_COMPILER_VAR_890;
struct reflectElement ____BAH_COMPILER_VAR_891 = __reflect(____BAH_COMPILER_VAR_848, sizeof(struct variable), "variable*", "v", 0, 0, 1, ____BAH_COMPILER_VAR_849, 0);
debugPrint("var_declaration",ft.line,____BAH_COMPILER_VAR_891);
if (isGlobal()) {
char** ____BAH_COMPILER_VAR_892 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_892[1] = ";\n";____BAH_COMPILER_VAR_892[0] = vct;char * ____BAH_COMPILER_VAR_893 =__Bah_multiple_concat(____BAH_COMPILER_VAR_892, 2);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_893));
}
}
if (isGlobal()) {
if ((isSubObject==false)) {
INIT = rope__add(INIT, rope(NEXT_LINE));
}
NEXT_LINE = "";
}
else {
char** ____BAH_COMPILER_VAR_894 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_894[1] = ";\n";____BAH_COMPILER_VAR_894[0] = code;char * ____BAH_COMPILER_VAR_895 =__Bah_multiple_concat(____BAH_COMPILER_VAR_894, 2);struct rope* declR = rope(____BAH_COMPILER_VAR_895);
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
char** ____BAH_COMPILER_VAR_896 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_896[1] = string__str(&ct);____BAH_COMPILER_VAR_896[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_897 =__Bah_multiple_concat(____BAH_COMPILER_VAR_896, 2);tmpfnArgsCType = ____BAH_COMPILER_VAR_897;
j = j+1;
if ((j<len(tmpfn->args))) {
char** ____BAH_COMPILER_VAR_898 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_898[1] = ",";____BAH_COMPILER_VAR_898[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_899 =__Bah_multiple_concat(____BAH_COMPILER_VAR_898, 2);tmpfnArgsCType = ____BAH_COMPILER_VAR_899;
}
};
char** ____BAH_COMPILER_VAR_900 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_900[5] = ")";____BAH_COMPILER_VAR_900[4] = tmpfnArgsCType;____BAH_COMPILER_VAR_900[3] = ")(";____BAH_COMPILER_VAR_900[2] = elemName;____BAH_COMPILER_VAR_900[1] = " (*";____BAH_COMPILER_VAR_900[0] = string__str(&tmpfnRetCType);char * ____BAH_COMPILER_VAR_901 =__Bah_multiple_concat(____BAH_COMPILER_VAR_900, 6);return ____BAH_COMPILER_VAR_901;
};
char * parseFnHeader(char * prev,__BAH_ARR_TYPE_Tok l,long int* i,struct func* fn,struct Elems* elems){
register long int j = *i;
struct Tok ft = l->data[j];
char * tpdf = "";
if (__builtin_expect((ft.type!=TOKEN_TYPE_VAR), 0)) {
throwErr(&ft,"Cannot use {TOKEN} as function name.");
}
char** ____BAH_COMPILER_VAR_902 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_902[1] = ft.cont;____BAH_COMPILER_VAR_902[0] = prev;char * ____BAH_COMPILER_VAR_903 =__Bah_multiple_concat(____BAH_COMPILER_VAR_902, 2);fn->name = ____BAH_COMPILER_VAR_903;
array(struct variable*)* arguments = memoryAlloc(sizeof(array(struct variable*)));

arguments->length = 0;
arguments->elemSize = sizeof(struct variable*);
char** ____BAH_COMPILER_VAR_904 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_904[1] = "(";____BAH_COMPILER_VAR_904[0] = fn->name;char * ____BAH_COMPILER_VAR_905 =__Bah_multiple_concat(____BAH_COMPILER_VAR_904, 2);char * code = ____BAH_COMPILER_VAR_905;
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
char** ____BAH_COMPILER_VAR_906 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_906[1] = t.cont;____BAH_COMPILER_VAR_906[0] = argType;char * ____BAH_COMPILER_VAR_907 =__Bah_multiple_concat(____BAH_COMPILER_VAR_906, 2);argType = ____BAH_COMPILER_VAR_907;
}
}
else {
isComa = true;
break;
}
j = j+1;
};
struct variable* ____BAH_COMPILER_VAR_908 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_908->name = "";
____BAH_COMPILER_VAR_908->type = "";
____BAH_COMPILER_VAR_908->constVal = "";
____BAH_COMPILER_VAR_908->from = "";
struct variable* argument = ____BAH_COMPILER_VAR_908;
argument->name = argName;
argument->type = argType;

    unsigned int ____BAH_COMPILER_VAR_909 = len(arguments);
    __Bah_realocate_arr(arguments, ____BAH_COMPILER_VAR_909);
    arguments->data[____BAH_COMPILER_VAR_909] = argument;
struct string argCType = getCType(argType,elems);
struct string cfrt = string(argType);
char * newArgType = string__str(&argCType);
if ((string__hasPrefix(&cfrt,"[]")==1)) {
string__trimLeft(&cfrt,2);
if (string__hasSuffix(&cfrt,"*")) {
long int nbast = string__count(&cfrt,"*");
string__trimRight(&cfrt,nbast);
}
char** ____BAH_COMPILER_VAR_910 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_910[1] = string__str(&cfrt);____BAH_COMPILER_VAR_910[0] = "__BAH_ARR_TYPE_";char * ____BAH_COMPILER_VAR_911 =__Bah_multiple_concat(____BAH_COMPILER_VAR_910, 2);newArgType = ____BAH_COMPILER_VAR_911;
array(char *)* csatd = compilerState.arrTypesDecl;
if ((inArrayStr(newArgType,csatd)==false)) {

    unsigned int ____BAH_COMPILER_VAR_912 = len(csatd);
    __Bah_realocate_arr(csatd, ____BAH_COMPILER_VAR_912);
    csatd->data[____BAH_COMPILER_VAR_912] = newArgType;
char** ____BAH_COMPILER_VAR_913 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_913[5] = ";\n";____BAH_COMPILER_VAR_913[4] = newArgType;____BAH_COMPILER_VAR_913[3] = " ";____BAH_COMPILER_VAR_913[2] = string__str(&argCType);____BAH_COMPILER_VAR_913[1] = "typedef ";____BAH_COMPILER_VAR_913[0] = tpdf;char * ____BAH_COMPILER_VAR_914 =__Bah_multiple_concat(____BAH_COMPILER_VAR_913, 6);tpdf = ____BAH_COMPILER_VAR_914;
}
}
if ((string__hasPrefix(&cfrt,"function(")==1)) {
char** ____BAH_COMPILER_VAR_915 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_915[1] = getCfunctionType(&cfrt,argName,elems);____BAH_COMPILER_VAR_915[0] = code;char * ____BAH_COMPILER_VAR_916 =__Bah_multiple_concat(____BAH_COMPILER_VAR_915, 2);code = ____BAH_COMPILER_VAR_916;
}
else {
char** ____BAH_COMPILER_VAR_917 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_917[3] = argName;____BAH_COMPILER_VAR_917[2] = " ";____BAH_COMPILER_VAR_917[1] = newArgType;____BAH_COMPILER_VAR_917[0] = code;char * ____BAH_COMPILER_VAR_918 =__Bah_multiple_concat(____BAH_COMPILER_VAR_917, 4);code = ____BAH_COMPILER_VAR_918;
}
if ((isComa==true)) {
char** ____BAH_COMPILER_VAR_919 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_919[1] = ",";____BAH_COMPILER_VAR_919[0] = code;char * ____BAH_COMPILER_VAR_920 =__Bah_multiple_concat(____BAH_COMPILER_VAR_919, 2);code = ____BAH_COMPILER_VAR_920;
}
else {
char** ____BAH_COMPILER_VAR_921 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_921[1] = ")";____BAH_COMPILER_VAR_921[0] = code;char * ____BAH_COMPILER_VAR_922 =__Bah_multiple_concat(____BAH_COMPILER_VAR_921, 2);code = ____BAH_COMPILER_VAR_922;
break;
}
j = j+1;
};
}
else {
char** ____BAH_COMPILER_VAR_923 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_923[1] = ")";____BAH_COMPILER_VAR_923[0] = code;char * ____BAH_COMPILER_VAR_924 =__Bah_multiple_concat(____BAH_COMPILER_VAR_923, 2);code = ____BAH_COMPILER_VAR_924;
}
j = j+1;
struct variable* ____BAH_COMPILER_VAR_925 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_925->name = "";
____BAH_COMPILER_VAR_925->type = "";
____BAH_COMPILER_VAR_925->constVal = "";
____BAH_COMPILER_VAR_925->from = "";
struct variable* returns = ____BAH_COMPILER_VAR_925;
returns->type = "";
while ((j<len(l))) {
t = l->data[j];
if ((strcmp(t.cont, "{") == 0)) {
break;
}
char** ____BAH_COMPILER_VAR_926 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_926[1] = t.cont;____BAH_COMPILER_VAR_926[0] = returns->type;char * ____BAH_COMPILER_VAR_927 =__Bah_multiple_concat(____BAH_COMPILER_VAR_926, 2);returns->type = ____BAH_COMPILER_VAR_927;
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
char** ____BAH_COMPILER_VAR_928 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_928[1] = string__str(&cfrt);____BAH_COMPILER_VAR_928[0] = "__BAH_ARR_TYPE_";char * ____BAH_COMPILER_VAR_929 =__Bah_multiple_concat(____BAH_COMPILER_VAR_928, 2);newFnRetType = ____BAH_COMPILER_VAR_929;
array(char *)* csatd = compilerState.arrTypesDecl;
if ((inArrayStr(newFnRetType,csatd)==false)) {

    unsigned int ____BAH_COMPILER_VAR_930 = len(csatd);
    __Bah_realocate_arr(csatd, ____BAH_COMPILER_VAR_930);
    csatd->data[____BAH_COMPILER_VAR_930] = newFnRetType;
char** ____BAH_COMPILER_VAR_931 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_931[5] = ";\n";____BAH_COMPILER_VAR_931[4] = newFnRetType;____BAH_COMPILER_VAR_931[3] = " ";____BAH_COMPILER_VAR_931[2] = string__str(&fnRetType);____BAH_COMPILER_VAR_931[1] = "typedef ";____BAH_COMPILER_VAR_931[0] = tpdf;char * ____BAH_COMPILER_VAR_932 =__Bah_multiple_concat(____BAH_COMPILER_VAR_931, 6);tpdf = ____BAH_COMPILER_VAR_932;
}
}
char** ____BAH_COMPILER_VAR_933 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_933[3] = code;____BAH_COMPILER_VAR_933[2] = " ";____BAH_COMPILER_VAR_933[1] = newFnRetType;____BAH_COMPILER_VAR_933[0] = tpdf;char * ____BAH_COMPILER_VAR_934 =__Bah_multiple_concat(____BAH_COMPILER_VAR_933, 4);code = ____BAH_COMPILER_VAR_934;
return code;
};
void parseStruct(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
struct cStruct* ____BAH_COMPILER_VAR_935 = memoryAlloc(sizeof(struct cStruct));
____BAH_COMPILER_VAR_935->name = "";
____BAH_COMPILER_VAR_935->members = memoryAlloc(sizeof(array(struct structMemb*)));
            ____BAH_COMPILER_VAR_935->members->length = 0;
            ____BAH_COMPILER_VAR_935->members->elemSize = sizeof(struct structMemb*);
            ____BAH_COMPILER_VAR_935->methods = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_935->methods->length = 0;
            ____BAH_COMPILER_VAR_935->methods->elemSize = sizeof(struct func*);
            ____BAH_COMPILER_VAR_935->postCode = "";
____BAH_COMPILER_VAR_935->extendedFrom = "";
struct cStruct* s = ____BAH_COMPILER_VAR_935;
array(struct cStruct*)* structs = elems->structs;

    unsigned int ____BAH_COMPILER_VAR_936 = len(structs);
    __Bah_realocate_arr(structs, ____BAH_COMPILER_VAR_936);
    structs->data[____BAH_COMPILER_VAR_936] = s;
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
char** ____BAH_COMPILER_VAR_937 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_937[1] = string__str(&ct);____BAH_COMPILER_VAR_937[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_938 =__Bah_multiple_concat(____BAH_COMPILER_VAR_937, 2);tmpfnArgsCType = ____BAH_COMPILER_VAR_938;
j = j+1;
if ((j<len(tmpfn->args))) {
char** ____BAH_COMPILER_VAR_939 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_939[1] = ",";____BAH_COMPILER_VAR_939[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_940 =__Bah_multiple_concat(____BAH_COMPILER_VAR_939, 2);tmpfnArgsCType = ____BAH_COMPILER_VAR_940;
}
};
char** ____BAH_COMPILER_VAR_941 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_941[5] = ")";____BAH_COMPILER_VAR_941[4] = tmpfnArgsCType;____BAH_COMPILER_VAR_941[3] = ")(";____BAH_COMPILER_VAR_941[2] = em->name;____BAH_COMPILER_VAR_941[1] = " (*";____BAH_COMPILER_VAR_941[0] = string__str(&tmpfnRetCType);char * ____BAH_COMPILER_VAR_942 =__Bah_multiple_concat(____BAH_COMPILER_VAR_941, 6);membDeclStr = ____BAH_COMPILER_VAR_942;
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

    unsigned int ____BAH_COMPILER_VAR_943 = len(allMembs);
    __Bah_realocate_arr(allMembs, ____BAH_COMPILER_VAR_943);
    allMembs->data[____BAH_COMPILER_VAR_943] = membDeclStr;

    unsigned int ____BAH_COMPILER_VAR_944 = len(members);
    __Bah_realocate_arr(members, ____BAH_COMPILER_VAR_944);
    members->data[____BAH_COMPILER_VAR_944] = em;
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
struct structMemb* ____BAH_COMPILER_VAR_945 = memoryAlloc(sizeof(struct structMemb));
____BAH_COMPILER_VAR_945->name = "";
____BAH_COMPILER_VAR_945->type = "";
____BAH_COMPILER_VAR_945->constVal = "";
____BAH_COMPILER_VAR_945->from = "";
____BAH_COMPILER_VAR_945->def = "";
struct structMemb* memb = ____BAH_COMPILER_VAR_945;
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
char** ____BAH_COMPILER_VAR_946 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_946[1] = "__";____BAH_COMPILER_VAR_946[0] = s->name;char * ____BAH_COMPILER_VAR_947 =__Bah_multiple_concat(____BAH_COMPILER_VAR_946, 2);char * fnPrefix = ____BAH_COMPILER_VAR_947;
struct func* ____BAH_COMPILER_VAR_948 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_948->name = "";
____BAH_COMPILER_VAR_948->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_948->args->length = 0;
            ____BAH_COMPILER_VAR_948->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_948->from = "";
____BAH_COMPILER_VAR_948->file = "";
____BAH_COMPILER_VAR_948->line = 1;
struct func* fn = ____BAH_COMPILER_VAR_948;
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
register long int j = i-1;
while ((j<len(l))) {
t = l->data[j];
if ((strcmp(t.cont, "{") == 0)) {
break;
}

    unsigned int ____BAH_COMPILER_VAR_949 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_949);
    nl->data[____BAH_COMPILER_VAR_949] = t;
if ((j==i)) {
t.type = TOKEN_TYPE_VAR;
t.cont = "this";
t.isValue = true;

    unsigned int ____BAH_COMPILER_VAR_950 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_950);
    nl->data[____BAH_COMPILER_VAR_950] = t;
t.type = TOKEN_TYPE_VAR;
char** ____BAH_COMPILER_VAR_951 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_951[1] = "*";____BAH_COMPILER_VAR_951[0] = s->name;char * ____BAH_COMPILER_VAR_952 =__Bah_multiple_concat(____BAH_COMPILER_VAR_951, 2);t.cont = ____BAH_COMPILER_VAR_952;
t.isValue = true;

    unsigned int ____BAH_COMPILER_VAR_953 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_953);
    nl->data[____BAH_COMPILER_VAR_953] = t;
struct Tok nt = l->data[j+1];
if ((strcmp(nt.cont, ")") != 0)) {
t.type = TOKEN_TYPE_SYNTAX;
t.cont = ",";
t.isValue = false;

    unsigned int ____BAH_COMPILER_VAR_954 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_954);
    nl->data[____BAH_COMPILER_VAR_954] = t;
}
}
j = j+1;
};
--i;
long int nli = 0;
char * ____BAH_COMPILER_VAR_955 =parseFnHeader(fnPrefix,nl,&nli,fn,elems);struct rope* code = rope(____BAH_COMPILER_VAR_955);
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

    unsigned int ____BAH_COMPILER_VAR_956 = len(fnElems->vars);
    __Bah_realocate_arr(fnElems->vars, ____BAH_COMPILER_VAR_956);
    fnElems->vars->data[____BAH_COMPILER_VAR_956] = a;
};
array(struct func*)* fns = elems->fns;

    unsigned int ____BAH_COMPILER_VAR_957 = len(fns);
    __Bah_realocate_arr(fns, ____BAH_COMPILER_VAR_957);
    fns->data[____BAH_COMPILER_VAR_957] = fn;
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

    unsigned int ____BAH_COMPILER_VAR_958 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_958);
    tokens->data[____BAH_COMPILER_VAR_958] = t;
++i;
};
struct func* ____BAH_COMPILER_VAR_959 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_959->name = "";
____BAH_COMPILER_VAR_959->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_959->args->length = 0;
            ____BAH_COMPILER_VAR_959->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_959->from = "";
____BAH_COMPILER_VAR_959->file = "";
____BAH_COMPILER_VAR_959->line = 1;
struct func* mfn = ____BAH_COMPILER_VAR_959;
mfn->args = fn->args;
mfn->name = fn->name;
mfn->returns = fn->returns;
mfn->from = s->name;
strTrimLeft(&mfn->name,strlen(fnPrefix));

    unsigned int ____BAH_COMPILER_VAR_960 = len(methds);
    __Bah_realocate_arr(methds, ____BAH_COMPILER_VAR_960);
    methds->data[____BAH_COMPILER_VAR_960] = mfn;
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
char** ____BAH_COMPILER_VAR_961 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_961[2] = "' is not returned.";____BAH_COMPILER_VAR_961[1] = fn->name;____BAH_COMPILER_VAR_961[0] = "Function '";char * ____BAH_COMPILER_VAR_962 =__Bah_multiple_concat(____BAH_COMPILER_VAR_961, 3);throwErr(&l->data[len(l)-1],____BAH_COMPILER_VAR_962);
}
endRCPscope(fnElems,fn->args);
fixMeEndScope(fnElems,&tokens->data[len(tokens-1)]);
}
code = rope__add(code, rope__add(OUTPUT, rope("};\n")));
}
}
else {
fn->isImported = true;
mfn->isImported = true;
}
if ((doesOutput==true)) {
char** ____BAH_COMPILER_VAR_963 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_963[1] = rope__toStr(code);____BAH_COMPILER_VAR_963[0] = nextLine;char * ____BAH_COMPILER_VAR_964 =__Bah_multiple_concat(____BAH_COMPILER_VAR_963, 2);nextLine = ____BAH_COMPILER_VAR_964;
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
char** ____BAH_COMPILER_VAR_965 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_965[1] = t.cont;____BAH_COMPILER_VAR_965[0] = mbmType;char * ____BAH_COMPILER_VAR_966 =__Bah_multiple_concat(____BAH_COMPILER_VAR_965, 2);mbmType = ____BAH_COMPILER_VAR_966;
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
char** ____BAH_COMPILER_VAR_967 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_967[4] = " for member.";____BAH_COMPILER_VAR_967[3] = memb->type;____BAH_COMPILER_VAR_967[2] = ") as ";____BAH_COMPILER_VAR_967[1] = tt;____BAH_COMPILER_VAR_967[0] = "Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_968 =__Bah_multiple_concat(____BAH_COMPILER_VAR_967, 5);throwErr(&t,____BAH_COMPILER_VAR_968);
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

    unsigned int ____BAH_COMPILER_VAR_969 = len(members);
    __Bah_realocate_arr(members, ____BAH_COMPILER_VAR_969);
    members->data[____BAH_COMPILER_VAR_969] = memb;
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
char** ____BAH_COMPILER_VAR_970 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_970[1] = string__str(&ct);____BAH_COMPILER_VAR_970[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_971 =__Bah_multiple_concat(____BAH_COMPILER_VAR_970, 2);tmpfnArgsCType = ____BAH_COMPILER_VAR_971;
j = j+1;
if ((j<len(tmpfn->args))) {
char** ____BAH_COMPILER_VAR_972 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_972[1] = ",";____BAH_COMPILER_VAR_972[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_973 =__Bah_multiple_concat(____BAH_COMPILER_VAR_972, 2);tmpfnArgsCType = ____BAH_COMPILER_VAR_973;
}
};
char** ____BAH_COMPILER_VAR_974 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_974[5] = ")";____BAH_COMPILER_VAR_974[4] = tmpfnArgsCType;____BAH_COMPILER_VAR_974[3] = ")(";____BAH_COMPILER_VAR_974[2] = memb->name;____BAH_COMPILER_VAR_974[1] = " (*";____BAH_COMPILER_VAR_974[0] = string__str(&tmpfnRetCType);char * ____BAH_COMPILER_VAR_975 =__Bah_multiple_concat(____BAH_COMPILER_VAR_974, 6);membDeclStr = ____BAH_COMPILER_VAR_975;
}
else {
struct string membDecl = getCType(memb->type,elems);
char** ____BAH_COMPILER_VAR_976 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_976[1] = memb->name;____BAH_COMPILER_VAR_976[0] = " ";char * ____BAH_COMPILER_VAR_977 =__Bah_multiple_concat(____BAH_COMPILER_VAR_976, 2);string__append(&membDecl,____BAH_COMPILER_VAR_977);
membDeclStr = string__str(&membDecl);
}

    unsigned int ____BAH_COMPILER_VAR_978 = len(allMembs);
    __Bah_realocate_arr(allMembs, ____BAH_COMPILER_VAR_978);
    allMembs->data[____BAH_COMPILER_VAR_978] = membDeclStr;
++i;
};
s->members = members;
if ((doesOutput==true)) {
OUTPUT = OOUT;
NEXT_LINE = nextLine;
char** ____BAH_COMPILER_VAR_979 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_979[2] = " {\n";____BAH_COMPILER_VAR_979[1] = s->name;____BAH_COMPILER_VAR_979[0] = "struct ";char * ____BAH_COMPILER_VAR_980 =__Bah_multiple_concat(____BAH_COMPILER_VAR_979, 3);struct rope* code = rope(____BAH_COMPILER_VAR_980);
i = 0;
while ((i<len(allMembs))) {
char * m = allMembs->data[i];
char** ____BAH_COMPILER_VAR_981 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_981[1] = ";\n";____BAH_COMPILER_VAR_981[0] = m;char * ____BAH_COMPILER_VAR_982 =__Bah_multiple_concat(____BAH_COMPILER_VAR_981, 2);code = rope__add(code, rope(____BAH_COMPILER_VAR_982));
++i;
};
code = rope__add(code, rope("};\n"));
OUTPUT = rope__add(OUTPUT, code);
char * phd = rope__toStr(postDeclHandle);
OUTPUT->totalLen = OUTPUT->totalLen+ropeSet(postDeclHandle,"");
char** ____BAH_COMPILER_VAR_983 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_983[1] = phd;____BAH_COMPILER_VAR_983[0] = NEXT_LINE;char * ____BAH_COMPILER_VAR_984 =__Bah_multiple_concat(____BAH_COMPILER_VAR_983, 2);NEXT_LINE = ____BAH_COMPILER_VAR_984;
}
if ((debug==true)) {
struct debugStruct* ____BAH_COMPILER_VAR_985 = memoryAlloc(sizeof(struct debugStruct));
____BAH_COMPILER_VAR_985->membs = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_985->membs->length = 0;
            ____BAH_COMPILER_VAR_985->membs->elemSize = sizeof(struct variable*);
            struct debugStruct* ds = ____BAH_COMPILER_VAR_985;
ds->name = s->name;
i = 0;
while ((i<len(s->members))) {
struct structMemb* m = s->members->data[i];
struct variable* ____BAH_COMPILER_VAR_986 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_986->name = "";
____BAH_COMPILER_VAR_986->type = "";
____BAH_COMPILER_VAR_986->constVal = "";
____BAH_COMPILER_VAR_986->from = "";
struct variable* mv = ____BAH_COMPILER_VAR_986;
mv->name = m->name;
mv->type = m->type;
mv->isConst = false;
mv->isArray = m->isArray;

    unsigned int ____BAH_COMPILER_VAR_987 = i;
    __Bah_realocate_arr(ds->membs, ____BAH_COMPILER_VAR_987);
    ds->membs->data[____BAH_COMPILER_VAR_987] = mv;
i = i+1;
};
struct debugStruct* ____BAH_COMPILER_VAR_988 = ds;
char ** ____BAH_COMPILER_VAR_990 = (char **)((char*)(____BAH_COMPILER_VAR_988) + offsetof(struct debugStruct, name));
struct reflectElement ____BAH_COMPILER_VAR_991 = __reflect(____BAH_COMPILER_VAR_990, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct debugStruct, name));
array(struct variable*)** ____BAH_COMPILER_VAR_992 = (array(struct variable*)**)((char*)(____BAH_COMPILER_VAR_988) + offsetof(struct debugStruct, membs));
struct variable** ____BAH_COMPILER_VAR_993 = 0;
char ** ____BAH_COMPILER_VAR_995 = (char **)((char*)(____BAH_COMPILER_VAR_993) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_996 = __reflect(____BAH_COMPILER_VAR_995, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_997 = (char **)((char*)(____BAH_COMPILER_VAR_993) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_998 = __reflect(____BAH_COMPILER_VAR_997, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_999 = (char*)((char*)(____BAH_COMPILER_VAR_993) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_1000 = __reflect(____BAH_COMPILER_VAR_999, sizeof(char), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_1001 = (char **)((char*)(____BAH_COMPILER_VAR_993) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_1002 = __reflect(____BAH_COMPILER_VAR_1001, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_1003 = (char*)((char*)(____BAH_COMPILER_VAR_993) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_1004 = __reflect(____BAH_COMPILER_VAR_1003, sizeof(char), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_1005 = (char **)((char*)(____BAH_COMPILER_VAR_993) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_1006 = __reflect(____BAH_COMPILER_VAR_1005, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
void ** ____BAH_COMPILER_VAR_1007 = (void **)((char*)(____BAH_COMPILER_VAR_993) + offsetof(struct variable, declScope));
struct reflectElement ____BAH_COMPILER_VAR_1008 = __reflect(____BAH_COMPILER_VAR_1007, sizeof(void *), "ptr", "declScope", 0, 0, 0, 0, offsetof(struct variable, declScope));
char* ____BAH_COMPILER_VAR_1009 = (char*)((char*)(____BAH_COMPILER_VAR_993) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_1010 = __reflect(____BAH_COMPILER_VAR_1009, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));
struct rope** ____BAH_COMPILER_VAR_1011 = (struct rope**)((char*)(____BAH_COMPILER_VAR_993) + offsetof(struct variable, declRope));
void ** ____BAH_COMPILER_VAR_1013 = (void **)((char*)(____BAH_COMPILER_VAR_1011) + offsetof(struct rope, left));
struct reflectElement ____BAH_COMPILER_VAR_1014 = __reflect(____BAH_COMPILER_VAR_1013, sizeof(void *), "ptr", "left", 0, 0, 0, 0, offsetof(struct rope, left));
void ** ____BAH_COMPILER_VAR_1015 = (void **)((char*)(____BAH_COMPILER_VAR_1011) + offsetof(struct rope, right));
struct reflectElement ____BAH_COMPILER_VAR_1016 = __reflect(____BAH_COMPILER_VAR_1015, sizeof(void *), "ptr", "right", 0, 0, 0, 0, offsetof(struct rope, right));
char ** ____BAH_COMPILER_VAR_1017 = (char **)((char*)(____BAH_COMPILER_VAR_1011) + offsetof(struct rope, str));
struct reflectElement ____BAH_COMPILER_VAR_1018 = __reflect(____BAH_COMPILER_VAR_1017, sizeof(char *), "cpstring", "str", 0, 0, 0, 0, offsetof(struct rope, str));
int* ____BAH_COMPILER_VAR_1019 = (int*)((char*)(____BAH_COMPILER_VAR_1011) + offsetof(struct rope, lCount));
struct reflectElement ____BAH_COMPILER_VAR_1020 = __reflect(____BAH_COMPILER_VAR_1019, sizeof(int), "int32", "lCount", 0, 0, 0, 0, offsetof(struct rope, lCount));
int* ____BAH_COMPILER_VAR_1021 = (int*)((char*)(____BAH_COMPILER_VAR_1011) + offsetof(struct rope, len));
struct reflectElement ____BAH_COMPILER_VAR_1022 = __reflect(____BAH_COMPILER_VAR_1021, sizeof(int), "int32", "len", 0, 0, 0, 0, offsetof(struct rope, len));
int* ____BAH_COMPILER_VAR_1023 = (int*)((char*)(____BAH_COMPILER_VAR_1011) + offsetof(struct rope, totalLen));
struct reflectElement ____BAH_COMPILER_VAR_1024 = __reflect(____BAH_COMPILER_VAR_1023, sizeof(int), "int32", "totalLen", 0, 0, 0, 0, offsetof(struct rope, totalLen));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_1012 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_1012->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_1012->length = 6;
        ____BAH_COMPILER_VAR_1012->data = memoryAlloc(____BAH_COMPILER_VAR_1012->length * ____BAH_COMPILER_VAR_1012->elemSize);
        ____BAH_COMPILER_VAR_1012->data[0] = ____BAH_COMPILER_VAR_1014;
____BAH_COMPILER_VAR_1012->data[1] = ____BAH_COMPILER_VAR_1016;
____BAH_COMPILER_VAR_1012->data[2] = ____BAH_COMPILER_VAR_1018;
____BAH_COMPILER_VAR_1012->data[3] = ____BAH_COMPILER_VAR_1020;
____BAH_COMPILER_VAR_1012->data[4] = ____BAH_COMPILER_VAR_1022;
____BAH_COMPILER_VAR_1012->data[5] = ____BAH_COMPILER_VAR_1024;
struct reflectElement ____BAH_COMPILER_VAR_1025 = __reflect(____BAH_COMPILER_VAR_1011, sizeof(struct rope), "rope*", "declRope", 0, 0, 1, ____BAH_COMPILER_VAR_1012, offsetof(struct variable, declRope));
char* ____BAH_COMPILER_VAR_1026 = (char*)((char*)(____BAH_COMPILER_VAR_993) + offsetof(struct variable, canBeNull));
struct reflectElement ____BAH_COMPILER_VAR_1027 = __reflect(____BAH_COMPILER_VAR_1026, sizeof(char), "bool", "canBeNull", 0, 0, 0, 0, offsetof(struct variable, canBeNull));
char* ____BAH_COMPILER_VAR_1028 = (char*)((char*)(____BAH_COMPILER_VAR_993) + offsetof(struct variable, canBeReg));
struct reflectElement ____BAH_COMPILER_VAR_1029 = __reflect(____BAH_COMPILER_VAR_1028, sizeof(char), "bool", "canBeReg", 0, 0, 0, 0, offsetof(struct variable, canBeReg));
char* ____BAH_COMPILER_VAR_1030 = (char*)((char*)(____BAH_COMPILER_VAR_993) + offsetof(struct variable, isReg));
struct reflectElement ____BAH_COMPILER_VAR_1031 = __reflect(____BAH_COMPILER_VAR_1030, sizeof(char), "bool", "isReg", 0, 0, 0, 0, offsetof(struct variable, isReg));
void ** ____BAH_COMPILER_VAR_1032 = (void **)((char*)(____BAH_COMPILER_VAR_993) + offsetof(struct variable, lastSet));
struct reflectElement ____BAH_COMPILER_VAR_1033 = __reflect(____BAH_COMPILER_VAR_1032, sizeof(void *), "ptr", "lastSet", 0, 0, 0, 0, offsetof(struct variable, lastSet));
char* ____BAH_COMPILER_VAR_1034 = (char*)((char*)(____BAH_COMPILER_VAR_993) + offsetof(struct variable, isArg));
struct reflectElement ____BAH_COMPILER_VAR_1035 = __reflect(____BAH_COMPILER_VAR_1034, sizeof(char), "bool", "isArg", 0, 0, 0, 0, offsetof(struct variable, isArg));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_994 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_994->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_994->length = 14;
        ____BAH_COMPILER_VAR_994->data = memoryAlloc(____BAH_COMPILER_VAR_994->length * ____BAH_COMPILER_VAR_994->elemSize);
        ____BAH_COMPILER_VAR_994->data[0] = ____BAH_COMPILER_VAR_996;
____BAH_COMPILER_VAR_994->data[1] = ____BAH_COMPILER_VAR_998;
____BAH_COMPILER_VAR_994->data[2] = ____BAH_COMPILER_VAR_1000;
____BAH_COMPILER_VAR_994->data[3] = ____BAH_COMPILER_VAR_1002;
____BAH_COMPILER_VAR_994->data[4] = ____BAH_COMPILER_VAR_1004;
____BAH_COMPILER_VAR_994->data[5] = ____BAH_COMPILER_VAR_1006;
____BAH_COMPILER_VAR_994->data[6] = ____BAH_COMPILER_VAR_1008;
____BAH_COMPILER_VAR_994->data[7] = ____BAH_COMPILER_VAR_1010;
____BAH_COMPILER_VAR_994->data[8] = ____BAH_COMPILER_VAR_1025;
____BAH_COMPILER_VAR_994->data[9] = ____BAH_COMPILER_VAR_1027;
____BAH_COMPILER_VAR_994->data[10] = ____BAH_COMPILER_VAR_1029;
____BAH_COMPILER_VAR_994->data[11] = ____BAH_COMPILER_VAR_1031;
____BAH_COMPILER_VAR_994->data[12] = ____BAH_COMPILER_VAR_1033;
____BAH_COMPILER_VAR_994->data[13] = ____BAH_COMPILER_VAR_1035;
struct reflectElement ____BAH_COMPILER_VAR_1036 = __reflect(____BAH_COMPILER_VAR_993, sizeof(struct variable), "variable*", "", 0, 0, 1, ____BAH_COMPILER_VAR_994, 0);

        struct reflectElement ____BAH_COMPILER_VAR_1037 = ____BAH_COMPILER_VAR_1036;
        struct reflectElement ____BAH_COMPILER_VAR_1038 = __reflect(____BAH_COMPILER_VAR_992, sizeof(array(struct variable*)*), "[]variable*", "membs", 1, &____BAH_COMPILER_VAR_1037, 0, 0, offsetof(struct debugStruct, membs));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_989 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_989->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_989->length = 2;
        ____BAH_COMPILER_VAR_989->data = memoryAlloc(____BAH_COMPILER_VAR_989->length * ____BAH_COMPILER_VAR_989->elemSize);
        ____BAH_COMPILER_VAR_989->data[0] = ____BAH_COMPILER_VAR_991;
____BAH_COMPILER_VAR_989->data[1] = ____BAH_COMPILER_VAR_1038;
struct reflectElement ____BAH_COMPILER_VAR_1039 = __reflect(____BAH_COMPILER_VAR_988, sizeof(struct debugStruct), "debugStruct*", "ds", 0, 0, 1, ____BAH_COMPILER_VAR_989, 0);
debugPrint("struct_declare",nameToken.line,____BAH_COMPILER_VAR_1039);
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
struct func* ____BAH_COMPILER_VAR_1040 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_1040->name = "";
____BAH_COMPILER_VAR_1040->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_1040->args->length = 0;
            ____BAH_COMPILER_VAR_1040->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_1040->from = "";
____BAH_COMPILER_VAR_1040->file = "";
____BAH_COMPILER_VAR_1040->line = 1;
struct func* fn = ____BAH_COMPILER_VAR_1040;
char * code = parseFnHeader("",l,&i,fn,elems);
array(struct func*)* fns = elems->fns;
fn->isBinding = true;

    unsigned int ____BAH_COMPILER_VAR_1041 = len(fns);
    __Bah_realocate_arr(fns, ____BAH_COMPILER_VAR_1041);
    fns->data[____BAH_COMPILER_VAR_1041] = fn;
if ((doesOutput==true)) {
char** ____BAH_COMPILER_VAR_1042 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1042[1] = ";\n";____BAH_COMPILER_VAR_1042[0] = code;char * ____BAH_COMPILER_VAR_1043 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1042, 2);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1043));
}
}
else {
char * tp = "";
++i;
for (; (i<len(l)); ++i) {
struct Tok t = l->data[i];
char** ____BAH_COMPILER_VAR_1044 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1044[1] = t.cont;____BAH_COMPILER_VAR_1044[0] = tp;char * ____BAH_COMPILER_VAR_1045 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1044, 2);tp = ____BAH_COMPILER_VAR_1045;
};
if (__builtin_expect((ft.type!=TOKEN_TYPE_VAR), 0)) {
throwErr(&ft,"Cannot use {TOKEN} as new type name.");
}
struct string cTypeNewType = getCType(tp,elems);
char * cTypeNewTypeStr = string__str(&cTypeNewType);
if ((doesOutput==true)) {
char** ____BAH_COMPILER_VAR_1046 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1046[4] = ";\n";____BAH_COMPILER_VAR_1046[3] = ft.cont;____BAH_COMPILER_VAR_1046[2] = " ";____BAH_COMPILER_VAR_1046[1] = cTypeNewTypeStr;____BAH_COMPILER_VAR_1046[0] = "typedef ";char * ____BAH_COMPILER_VAR_1047 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1046, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1047));
}
if ((debug==true)) {
struct debugType* ____BAH_COMPILER_VAR_1048 = memoryAlloc(sizeof(struct debugType));
struct debugType* dt = ____BAH_COMPILER_VAR_1048;
dt->name = ft.cont;
dt->refers = tp;
struct debugType* ____BAH_COMPILER_VAR_1049 = dt;
char ** ____BAH_COMPILER_VAR_1051 = (char **)((char*)(____BAH_COMPILER_VAR_1049) + offsetof(struct debugType, name));
struct reflectElement ____BAH_COMPILER_VAR_1052 = __reflect(____BAH_COMPILER_VAR_1051, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct debugType, name));
char ** ____BAH_COMPILER_VAR_1053 = (char **)((char*)(____BAH_COMPILER_VAR_1049) + offsetof(struct debugType, refers));
struct reflectElement ____BAH_COMPILER_VAR_1054 = __reflect(____BAH_COMPILER_VAR_1053, sizeof(char *), "cpstring", "refers", 0, 0, 0, 0, offsetof(struct debugType, refers));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_1050 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_1050->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_1050->length = 2;
        ____BAH_COMPILER_VAR_1050->data = memoryAlloc(____BAH_COMPILER_VAR_1050->length * ____BAH_COMPILER_VAR_1050->elemSize);
        ____BAH_COMPILER_VAR_1050->data[0] = ____BAH_COMPILER_VAR_1052;
____BAH_COMPILER_VAR_1050->data[1] = ____BAH_COMPILER_VAR_1054;
struct reflectElement ____BAH_COMPILER_VAR_1055 = __reflect(____BAH_COMPILER_VAR_1049, sizeof(struct debugType), "debugType*", "dt", 0, 0, 1, ____BAH_COMPILER_VAR_1050, 0);
debugPrint("type_declare",ft.line,____BAH_COMPILER_VAR_1055);
}
array(char *)* tps = elems->types;

    unsigned int ____BAH_COMPILER_VAR_1056 = len(tps);
    __Bah_realocate_arr(tps, ____BAH_COMPILER_VAR_1056);
    tps->data[____BAH_COMPILER_VAR_1056] = ft.cont;
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

    unsigned int ____BAH_COMPILER_VAR_1057 = len(clibs);
    __Bah_realocate_arr(clibs, ____BAH_COMPILER_VAR_1057);
    clibs->data[____BAH_COMPILER_VAR_1057] = ccstr;
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
struct variable* ____BAH_COMPILER_VAR_1058 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1058->name = "";
____BAH_COMPILER_VAR_1058->type = "";
____BAH_COMPILER_VAR_1058->constVal = "";
____BAH_COMPILER_VAR_1058->from = "";
struct variable* v = ____BAH_COMPILER_VAR_1058;
if (isGlobal()) {
v->isGlobal = true;
}
v->isConst = true;
v->constVal = valt.cont;
v->name = vart.cont;
v->type = getTypeFromToken(&valt,true,elems);
array(struct variable*)* vars = elems->vars;

    unsigned int ____BAH_COMPILER_VAR_1059 = len(vars);
    __Bah_realocate_arr(vars, ____BAH_COMPILER_VAR_1059);
    vars->data[____BAH_COMPILER_VAR_1059] = v;
if ((valt.type==TOKEN_TYPE_STR)) {
valt.cont = strLitteralToBahStr(valt.cont);
}
char** ____BAH_COMPILER_VAR_1060 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1060[4] = "\n";____BAH_COMPILER_VAR_1060[3] = valt.cont;____BAH_COMPILER_VAR_1060[2] = " ";____BAH_COMPILER_VAR_1060[1] = v->name;____BAH_COMPILER_VAR_1060[0] = "#define ";char * ____BAH_COMPILER_VAR_1061 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1060, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1061));
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
char** ____BAH_COMPILER_VAR_1062 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1062[2] = ".";____BAH_COMPILER_VAR_1062[1] = currentFn->returns->type;____BAH_COMPILER_VAR_1062[0] = "Cannot return nothing as ";char * ____BAH_COMPILER_VAR_1063 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1062, 3);throwErr(&l->data[0],____BAH_COMPILER_VAR_1063);
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

                struct string ____BAH_COMPILER_VAR_1064 = string(compilerState.currentDir);
                if ((isUnsafe==false)&&(string__hasPrefix(&____BAH_COMPILER_VAR_1064,BAH_DIR)==false)&&(currentFn->returns->type[strlen(currentFn->returns->type)-1]!=33)) {
if ((tmpV->canBeNull==true)||(strcmp(rv, "null") == 0)) {
currentFn->returns->canBeNull = true;
char** ____BAH_COMPILER_VAR_1065 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1065[2] = "' that can be null as pointer.\n\tUse maybe values instead.";____BAH_COMPILER_VAR_1065[1] = tmpV->name;____BAH_COMPILER_VAR_1065[0] = "Returning '";char * ____BAH_COMPILER_VAR_1066 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1065, 3);throwNoticeLine(____BAH_COMPILER_VAR_1066,rvt.line);
}
}
}
}
else if (RCPavailable()&&(rvt.type==TOKEN_TYPE_FUNC)) {
rv = genCompilerVar();
struct string cType = getCType(tt,elems);
char** ____BAH_COMPILER_VAR_1067 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_1067[5] = ";\n";____BAH_COMPILER_VAR_1067[4] = rvt.cont;____BAH_COMPILER_VAR_1067[3] = "=";____BAH_COMPILER_VAR_1067[2] = rv;____BAH_COMPILER_VAR_1067[1] = " ";____BAH_COMPILER_VAR_1067[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_1068 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1067, 6);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1068));
}
if (__builtin_expect((compTypes(tt,currentFn->returns->type)==false), 0)) {
char** ____BAH_COMPILER_VAR_1069 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1069[4] = ".";____BAH_COMPILER_VAR_1069[3] = currentFn->returns->type;____BAH_COMPILER_VAR_1069[2] = ") as ";____BAH_COMPILER_VAR_1069[1] = tt;____BAH_COMPILER_VAR_1069[0] = "Cannot return {TOKEN} (";char * ____BAH_COMPILER_VAR_1070 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1069, 5);throwErr(&rvt,____BAH_COMPILER_VAR_1070);
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
char** ____BAH_COMPILER_VAR_1071 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_1071[5] = ";\n";____BAH_COMPILER_VAR_1071[4] = rv;____BAH_COMPILER_VAR_1071[3] = " = ";____BAH_COMPILER_VAR_1071[2] = rvar;____BAH_COMPILER_VAR_1071[1] = " ";____BAH_COMPILER_VAR_1071[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_1072 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1071, 6);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1072));
if ((tmpV!=null)&&(tmpV->declScope!=elems)) {
OUTPUT = rope__add(OUTPUT, incrVar(tmpV,elems));
}
}
struct string stt = string(tt);
if (string__hasPrefix(&stt,"buffer:")) {
char** ____BAH_COMPILER_VAR_1073 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1073[2] = ")";____BAH_COMPILER_VAR_1073[1] = rvar;____BAH_COMPILER_VAR_1073[0] = "__STR(";char * ____BAH_COMPILER_VAR_1074 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1073, 3);rvar = ____BAH_COMPILER_VAR_1074;
}
else if (string__hasPrefix(&stt,"tuple:")) {
array(struct string)* parts = splitString(stt,":");
char * v = genCompilerVar();

                struct string ____BAH_COMPILER_VAR_1075 = getCType(tt,elems);
                char * ____BAH_COMPILER_VAR_1076 =string__str(&parts->data[2]);
                struct string ____BAH_COMPILER_VAR_1077 = getCType(____BAH_COMPILER_VAR_1076,elems);
                char * ____BAH_COMPILER_VAR_1078 =string__str(&parts->data[2]);
                struct string ____BAH_COMPILER_VAR_1079 = getCType(____BAH_COMPILER_VAR_1078,elems);
                char** ____BAH_COMPILER_VAR_1080 = alloca(17 * sizeof(char*));____BAH_COMPILER_VAR_1080[16] = ");";____BAH_COMPILER_VAR_1080[15] = string__str(&parts->data[1]);____BAH_COMPILER_VAR_1080[14] = ") * ";____BAH_COMPILER_VAR_1080[13] = string__str(&____BAH_COMPILER_VAR_1079);____BAH_COMPILER_VAR_1080[12] = ", sizeof(";____BAH_COMPILER_VAR_1080[11] = rv;____BAH_COMPILER_VAR_1080[10] = ", ";____BAH_COMPILER_VAR_1080[9] = v;____BAH_COMPILER_VAR_1080[8] = "));\n            memcpy(";____BAH_COMPILER_VAR_1080[7] = string__str(&____BAH_COMPILER_VAR_1077);____BAH_COMPILER_VAR_1080[6] = " * sizeof(";____BAH_COMPILER_VAR_1080[5] = string__str(&parts->data[1]);____BAH_COMPILER_VAR_1080[4] = " = memoryAlloc(";____BAH_COMPILER_VAR_1080[3] = v;____BAH_COMPILER_VAR_1080[2] = " ";____BAH_COMPILER_VAR_1080[1] = string__str(&____BAH_COMPILER_VAR_1075);____BAH_COMPILER_VAR_1080[0] = "";char * ____BAH_COMPILER_VAR_1081 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1080, 17);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1081));
rvar = v;
}
if (RCPavailable()) {
array(struct variable*)* excl = memoryAlloc(sizeof(array(struct variable*)));

excl->length = 0;
excl->elemSize = sizeof(struct variable*);
register long int j = 0;
for (; (j<len(currentFn->args)); ++j) {

    unsigned int ____BAH_COMPILER_VAR_1082 = j;
    __Bah_realocate_arr(excl, ____BAH_COMPILER_VAR_1082);
    excl->data[____BAH_COMPILER_VAR_1082] = currentFn->args->data[j];
};
if ((tmpV!=null)) {

    unsigned int ____BAH_COMPILER_VAR_1083 = len(excl);
    __Bah_realocate_arr(excl, ____BAH_COMPILER_VAR_1083);
    excl->data[____BAH_COMPILER_VAR_1083] = tmpV;
}
endRCPscope(elems,excl);
}
fixMeEndScope(elems,&l->data[0]);
char** ____BAH_COMPILER_VAR_1084 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1084[2] = ";\n";____BAH_COMPILER_VAR_1084[1] = rvar;____BAH_COMPILER_VAR_1084[0] = "return ";char * ____BAH_COMPILER_VAR_1085 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1084, 3);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1085));
}
else {
if (RCPavailable()) {
array(struct variable*)* excl = memoryAlloc(sizeof(array(struct variable*)));

excl->length = 0;
excl->elemSize = sizeof(struct variable*);
register long int j = 0;
for (; (j<len(currentFn->args)); ++j) {

    unsigned int ____BAH_COMPILER_VAR_1086 = j;
    __Bah_realocate_arr(excl, ____BAH_COMPILER_VAR_1086);
    excl->data[____BAH_COMPILER_VAR_1086] = currentFn->args->data[j];
};
if ((tmpV!=null)) {

    unsigned int ____BAH_COMPILER_VAR_1087 = len(excl);
    __Bah_realocate_arr(excl, ____BAH_COMPILER_VAR_1087);
    excl->data[____BAH_COMPILER_VAR_1087] = tmpV;
}
endRCPscope(elems,excl);
}
fixMeEndScope(elems,&l->data[0]);
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

    unsigned int ____BAH_COMPILER_VAR_1088 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_1088);
    tokens->data[____BAH_COMPILER_VAR_1088] = t;
++i;
};
char** ____BAH_COMPILER_VAR_1089 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1089[2] = ") {\n";____BAH_COMPILER_VAR_1089[1] = condt.cont;____BAH_COMPILER_VAR_1089[0] = "if (";char * ____BAH_COMPILER_VAR_1090 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1089, 3);struct rope* ifHeader = rope(____BAH_COMPILER_VAR_1090);
OUTPUT = rope__add(OUTPUT, ifHeader);
struct Elems* ifElems = dupElems(elems);
if ((fromElse==true)) {
i = 0;
for (; (i<len(prevIfChecks)); ++i) {
struct varCheck bc = prevIfChecks->data[i];
bc.checkNull = (bc.checkNull==false);

    unsigned int ____BAH_COMPILER_VAR_1091 = i;
    __Bah_realocate_arr(ifElems->branchChecks, ____BAH_COMPILER_VAR_1091);
    ifElems->branchChecks->data[____BAH_COMPILER_VAR_1091] = bc;
};
}
i = 0;
for (; (i<len(currChecks)); ++i) {

    unsigned int ____BAH_COMPILER_VAR_1092 = len(ifElems->branchChecks);
    __Bah_realocate_arr(ifElems->branchChecks, ____BAH_COMPILER_VAR_1092);
    ifElems->branchChecks->data[____BAH_COMPILER_VAR_1092] = currChecks->data[i];
};
prevIfChecks = ifElems->branchChecks;
char oldIB = compilerState.isBranch;
compilerState.isBranch = true;
beginRCPscopeLeaky(ifElems);
parseLines(tokens,ifElems);
if ((ifElems->currFlowEnd==true)) {
char** ____BAH_COMPILER_VAR_1093 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1093[2] = ", 0)) {\n";____BAH_COMPILER_VAR_1093[1] = condt.cont;____BAH_COMPILER_VAR_1093[0] = "if (__builtin_expect(";char * ____BAH_COMPILER_VAR_1094 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1093, 3);OUTPUT->totalLen = OUTPUT->totalLen+ropeSet(ifHeader,____BAH_COMPILER_VAR_1094);
}
endRCPscopeLeaky(ifElems,null,true);
fixMeEndScope(ifElems,&tokens->data[len(tokens)-1]);
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

    unsigned int ____BAH_COMPILER_VAR_1095 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1095);
    memory->data[____BAH_COMPILER_VAR_1095] = l->data[i];
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

    unsigned int ____BAH_COMPILER_VAR_1096 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1096);
    memory->data[____BAH_COMPILER_VAR_1096] = l->data[i];
++i;
};
OUTPUT = rope__add(OUTPUT, rope("{\n"));
struct Elems* ifElems = dupElems(elems);
i = 0;
for (; (i<len(prevIfChecks)); ++i) {
struct varCheck bc = prevIfChecks->data[i];
bc.checkNull = (bc.checkNull==false);

    unsigned int ____BAH_COMPILER_VAR_1097 = i;
    __Bah_realocate_arr(ifElems->branchChecks, ____BAH_COMPILER_VAR_1097);
    ifElems->branchChecks->data[____BAH_COMPILER_VAR_1097] = bc;
};
char oldIB = compilerState.isBranch;
compilerState.isBranch = true;
struct Tok t = l->data[0];
beginRCPscopeLeaky(ifElems);
parseLines(memory,ifElems);
endRCPscopeLeaky(ifElems,null,true);
fixMeEndScope(ifElems,&memory->data[len(memory)-1]);
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

    unsigned int ____BAH_COMPILER_VAR_1098 = len(inst);
    __Bah_realocate_arr(inst, ____BAH_COMPILER_VAR_1098);
    inst->data[____BAH_COMPILER_VAR_1098] = t;
};
struct rope* oldOut = OUTPUT;
OUTPUT = rope("");
parseLine(inst,elems);
char * ____BAH_COMPILER_VAR_1099 =rope__toStr(OUTPUT);struct string instC = string(____BAH_COMPILER_VAR_1099);
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

    unsigned int ____BAH_COMPILER_VAR_1100 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_1100);
    tokens->data[____BAH_COMPILER_VAR_1100] = t;
};
char** ____BAH_COMPILER_VAR_1101 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1101[4] = ") {\n";____BAH_COMPILER_VAR_1101[3] = string__str(&instC);____BAH_COMPILER_VAR_1101[2] = "; ";____BAH_COMPILER_VAR_1101[1] = condt.cont;____BAH_COMPILER_VAR_1101[0] = "for (; ";char * ____BAH_COMPILER_VAR_1102 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1101, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1102));
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

    unsigned int ____BAH_COMPILER_VAR_1103 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_1103);
    tokens->data[____BAH_COMPILER_VAR_1103] = t;
};
char** ____BAH_COMPILER_VAR_1104 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1104[2] = ") {\n";____BAH_COMPILER_VAR_1104[1] = condt.cont;____BAH_COMPILER_VAR_1104[0] = "while (";char * ____BAH_COMPILER_VAR_1105 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1104, 3);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1105));
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
fixMeEndScope(ifElems,&tokens->data[len(tokens)-1]);
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
fixMeEndScope(elems,&ft);
fixMeEndScope(compilerState.currForElems,&ft);
char** ____BAH_COMPILER_VAR_1106 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1106[1] = ";\n";____BAH_COMPILER_VAR_1106[0] = ft.cont;char * ____BAH_COMPILER_VAR_1107 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1106, 2);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1107));
};
void makeEvalFunc(struct func* fn,struct Elems* elems){
char * ____BAH_COMPILER_VAR_1109 =fn->name;
        char ____BAH_COMPILER_VAR_1108 = 0;
        for(int i=compilerState.evals->length-1; i!=-1;i--) {
            if (compilerState.evals->data[i] != 0 && strcmp(compilerState.evals->data[i], ____BAH_COMPILER_VAR_1109) == 0) {
                ____BAH_COMPILER_VAR_1108=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_1108) {
return;
}
char** ____BAH_COMPILER_VAR_1110 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1110[1] = fn->name;____BAH_COMPILER_VAR_1110[0] = "__Bah_eval_";char * ____BAH_COMPILER_VAR_1111 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1110, 2);struct func* ____BAH_COMPILER_VAR_1112 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_1112->name = "";
____BAH_COMPILER_VAR_1112->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_1112->args->length = 0;
            ____BAH_COMPILER_VAR_1112->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_1112->from = "";
____BAH_COMPILER_VAR_1112->file = "";
____BAH_COMPILER_VAR_1112->line = 1;
____BAH_COMPILER_VAR_1112->name = ____BAH_COMPILER_VAR_1111;
struct func* efn = ____BAH_COMPILER_VAR_1112;
struct variable* ____BAH_COMPILER_VAR_1113 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1113->name = "";
____BAH_COMPILER_VAR_1113->type = "";
____BAH_COMPILER_VAR_1113->constVal = "";
____BAH_COMPILER_VAR_1113->from = "";
____BAH_COMPILER_VAR_1113->type = "ptr";
efn->returns = ____BAH_COMPILER_VAR_1113;
struct variable* ____BAH_COMPILER_VAR_1114 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1114->name = "";
____BAH_COMPILER_VAR_1114->type = "";
____BAH_COMPILER_VAR_1114->constVal = "";
____BAH_COMPILER_VAR_1114->from = "";
____BAH_COMPILER_VAR_1114->name = "fnArgs";
____BAH_COMPILER_VAR_1114->type = "[]ptr";
efn->args = memoryAlloc(sizeof(array(struct variable*)));

efn->args->length = 1;
efn->args->elemSize = sizeof(struct variable*);
efn->args->data = memoryAlloc(sizeof(struct variable*) * 50);
                    efn->args->realLength = 50;
efn->args->data[0] = ____BAH_COMPILER_VAR_1114;
char * fnBinding = "";
char** ____BAH_COMPILER_VAR_1115 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1115[1] = "(";____BAH_COMPILER_VAR_1115[0] = fn->name;char * ____BAH_COMPILER_VAR_1116 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1115, 2);char * fnCall = ____BAH_COMPILER_VAR_1116;
register long int i = 0;
for (; (i<len(fn->args)); ++i) {
struct variable* a = fn->args->data[i];
char * v = genCompilerVar();
struct string cType = getCType(a->type,elems);
if ((isRCPpointerType(a->type)==false)) {
string__append(&cType,"*");
}
char** ____BAH_COMPILER_VAR_1117 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_1117[5] = "];";____BAH_COMPILER_VAR_1117[4] = intToStr(i);____BAH_COMPILER_VAR_1117[3] = " = fnArgs->data[";____BAH_COMPILER_VAR_1117[2] = v;____BAH_COMPILER_VAR_1117[1] = " ";____BAH_COMPILER_VAR_1117[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_1118 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1117, 6);char** ____BAH_COMPILER_VAR_1119 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1119[1] = ____BAH_COMPILER_VAR_1118;____BAH_COMPILER_VAR_1119[0] = fnBinding;char * ____BAH_COMPILER_VAR_1120 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1119, 2);fnBinding = ____BAH_COMPILER_VAR_1120;
if ((i!=0)) {
char** ____BAH_COMPILER_VAR_1121 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1121[1] = ", ";____BAH_COMPILER_VAR_1121[0] = fnCall;char * ____BAH_COMPILER_VAR_1122 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1121, 2);fnCall = ____BAH_COMPILER_VAR_1122;
}
if (isRCPpointerType(a->type)) {
char** ____BAH_COMPILER_VAR_1123 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1123[1] = v;____BAH_COMPILER_VAR_1123[0] = fnCall;char * ____BAH_COMPILER_VAR_1124 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1123, 2);fnCall = ____BAH_COMPILER_VAR_1124;
}
else {
char** ____BAH_COMPILER_VAR_1125 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1125[1] = v;____BAH_COMPILER_VAR_1125[0] = "*";char * ____BAH_COMPILER_VAR_1126 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1125, 2);char** ____BAH_COMPILER_VAR_1127 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1127[1] = ____BAH_COMPILER_VAR_1126;____BAH_COMPILER_VAR_1127[0] = fnCall;char * ____BAH_COMPILER_VAR_1128 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1127, 2);fnCall = ____BAH_COMPILER_VAR_1128;
}
};
char * setReturnValue = "void* r = 0;";
if (isRCPpointerType(fn->returns->type)) {
setReturnValue = "void* r = ";
}
else {
struct string cType = getCType(fn->returns->type,elems);
if ((strcmp(string__str(&cType), "void") != 0)) {
char** ____BAH_COMPILER_VAR_1129 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1129[3] = "));*r = ";____BAH_COMPILER_VAR_1129[2] = string__str(&cType);____BAH_COMPILER_VAR_1129[1] = "* r = memoryAlloc(sizeof(";____BAH_COMPILER_VAR_1129[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_1130 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1129, 4);setReturnValue = ____BAH_COMPILER_VAR_1130;
}
}
char** ____BAH_COMPILER_VAR_1131 = alloca(12 * sizeof(char*));____BAH_COMPILER_VAR_1131[11] = ");\n        return (void*)r;\n    };";____BAH_COMPILER_VAR_1131[10] = fnCall;____BAH_COMPILER_VAR_1131[9] = setReturnValue;____BAH_COMPILER_VAR_1131[8] = "\n        ";____BAH_COMPILER_VAR_1131[7] = fnBinding;____BAH_COMPILER_VAR_1131[6] = "() with the wrong number of arguments.\", \"BAH_COMPILER_INTERNAL\");\n        }\n        ";____BAH_COMPILER_VAR_1131[5] = fn->name;____BAH_COMPILER_VAR_1131[4] = ") {\n            __BAH_panic((char*)\"eval: calling function ";____BAH_COMPILER_VAR_1131[3] = intToStr(len(fn->args));____BAH_COMPILER_VAR_1131[2] = "(array(void*)* fnArgs) {\n        if (fnArgs->length != ";____BAH_COMPILER_VAR_1131[1] = efn->name;____BAH_COMPILER_VAR_1131[0] = "void* __attribute__((optimize(\"O0\"))) ";char * ____BAH_COMPILER_VAR_1132 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1131, 12);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1132));

    unsigned int ____BAH_COMPILER_VAR_1133 = len(compilerState.evals);
    __Bah_realocate_arr(compilerState.evals, ____BAH_COMPILER_VAR_1133);
    compilerState.evals->data[____BAH_COMPILER_VAR_1133] = fn->name;

    unsigned int ____BAH_COMPILER_VAR_1134 = len(elems->fns);
    __Bah_realocate_arr(elems->fns, ____BAH_COMPILER_VAR_1134);
    elems->fns->data[____BAH_COMPILER_VAR_1134] = efn;
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
char * ____BAH_COMPILER_VAR_1135 =string__str(&msg);throwWarning(____BAH_COMPILER_VAR_1135);
return;
}
if ((strcmp(ft.cont, "#eval") == 0)) {
char * ____BAH_COMPILER_VAR_1137 ="eval.bah";
        char ____BAH_COMPILER_VAR_1136 = 0;
        for(int i=compilerState.includes->length-1; i!=-1;i--) {
            if (compilerState.includes->data[i] != 0 && strcmp(compilerState.includes->data[i], ____BAH_COMPILER_VAR_1137) == 0) {
                ____BAH_COMPILER_VAR_1136=1;
                break;
            };
        }
        if ((____BAH_COMPILER_VAR_1136==false)) {
if (__builtin_expect((includeFile("eval.bah",elems)==false), 0)) {
char** ____BAH_COMPILER_VAR_1138 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1138[2] = ").";____BAH_COMPILER_VAR_1138[1] = BAH_DIR;____BAH_COMPILER_VAR_1138[0] = "Could not find file 'eval.bah'. Check your bah directory (";char * ____BAH_COMPILER_VAR_1139 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1138, 3);throwErr(&l->data[0],____BAH_COMPILER_VAR_1139);
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
if (__builtin_expect((strcmp(st.cont, "{") != 0)||(strcmp(lt.cont, "}") != 0), 0)) {
throwErr(&st,"Expected code block after keyword {TOKEN}.");
}
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
register long int i = 2;
while ((i<len(l)-1)) {

    unsigned int ____BAH_COMPILER_VAR_1140 = i-2;
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_1140);
    nl->data[____BAH_COMPILER_VAR_1140] = l->data[i];
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

    unsigned int ____BAH_COMPILER_VAR_1141 = len(compilerState.cLibs);
    __Bah_realocate_arr(compilerState.cLibs, ____BAH_COMPILER_VAR_1141);
    compilerState.cLibs->data[____BAH_COMPILER_VAR_1141] = "lpthread";
}
struct string sFnT = string(fnT.cont);
array(struct string)* fnNameParts = splitString(sFnT,"(");
struct string fnName = fnNameParts->data[0];
struct func* fn = searchFuncByToken(&fnT,elems);
if (__builtin_expect((fn==null), 0)) {
char** ____BAH_COMPILER_VAR_1142 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1142[2] = "', arround {TOKEN}.";____BAH_COMPILER_VAR_1142[1] = string__str(&fnName);____BAH_COMPILER_VAR_1142[0] = "Internal compiler error.\n Error parsing async call for function '";char * ____BAH_COMPILER_VAR_1143 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1142, 3);throwErr(&fnT,____BAH_COMPILER_VAR_1143);
}
fnName = string(fn->name);
char * sMembs = "";
char * unSerMembs = "";
i = 0;
while ((i<len(fn->args))) {
struct variable* a = fn->args->data[i];
struct string cType = getCType(a->type,elems);
char** ____BAH_COMPILER_VAR_1144 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1144[4] = ";\n";____BAH_COMPILER_VAR_1144[3] = a->name;____BAH_COMPILER_VAR_1144[2] = " ";____BAH_COMPILER_VAR_1144[1] = string__str(&cType);____BAH_COMPILER_VAR_1144[0] = sMembs;char * ____BAH_COMPILER_VAR_1145 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1144, 5);sMembs = ____BAH_COMPILER_VAR_1145;
char** ____BAH_COMPILER_VAR_1146 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1146[2] = a->name;____BAH_COMPILER_VAR_1146[1] = "args->";____BAH_COMPILER_VAR_1146[0] = unSerMembs;char * ____BAH_COMPILER_VAR_1147 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1146, 3);unSerMembs = ____BAH_COMPILER_VAR_1147;
i = i+1;
if ((i<len(fn->args))) {
char** ____BAH_COMPILER_VAR_1148 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1148[1] = ", ";____BAH_COMPILER_VAR_1148[0] = unSerMembs;char * ____BAH_COMPILER_VAR_1149 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1148, 2);unSerMembs = ____BAH_COMPILER_VAR_1149;
}
};
char** ____BAH_COMPILER_VAR_1150 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1150[2] = "}";____BAH_COMPILER_VAR_1150[1] = sMembs;____BAH_COMPILER_VAR_1150[0] = "struct {\n";char * ____BAH_COMPILER_VAR_1151 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1150, 3);char * tmpArgsStruct = ____BAH_COMPILER_VAR_1151;
char * fnWrapper = genCompilerVar();
char * tmpArgs = genCompilerVar();
string__trimLeft(&sFnT,fnName.length+1);
string__trimRight(&sFnT,1);
char * tCreate = "";
if ((strcmp(BAH_OS, "windows") == 0)) {
tCreate = "pthread_create";
}
else {
if (RCPavailable()||(RAIIenabled==true)) {
tCreate = "pthread_create";
}
else {
tCreate = "GC_pthread_create";
}
}
char** ____BAH_COMPILER_VAR_1152 = alloca(25 * sizeof(char*));____BAH_COMPILER_VAR_1152[24] = ", tmpArgs);\n    }; \n    \n    ";____BAH_COMPILER_VAR_1152[23] = fnWrapper;____BAH_COMPILER_VAR_1152[22] = "(&id, 0, ";____BAH_COMPILER_VAR_1152[21] = tCreate;____BAH_COMPILER_VAR_1152[20] = "));\n        pthread_t id;\n        ";____BAH_COMPILER_VAR_1152[19] = tmpArgs;____BAH_COMPILER_VAR_1152[18] = ", sizeof(";____BAH_COMPILER_VAR_1152[17] = tmpArgs;____BAH_COMPILER_VAR_1152[16] = "));\n        memcpy(tmpArgs, &";____BAH_COMPILER_VAR_1152[15] = tmpArgs;____BAH_COMPILER_VAR_1152[14] = "};\n        void* tmpArgs = memoryAlloc(sizeof(";____BAH_COMPILER_VAR_1152[13] = string__str(&sFnT);____BAH_COMPILER_VAR_1152[12] = " = {";____BAH_COMPILER_VAR_1152[11] = tmpArgs;____BAH_COMPILER_VAR_1152[10] = " ";____BAH_COMPILER_VAR_1152[9] = tmpArgsStruct;____BAH_COMPILER_VAR_1152[8] = ");\n    };\n    {\n        ";____BAH_COMPILER_VAR_1152[7] = unSerMembs;____BAH_COMPILER_VAR_1152[6] = "(";____BAH_COMPILER_VAR_1152[5] = string__str(&fnName);____BAH_COMPILER_VAR_1152[4] = "* args) {\n        ";____BAH_COMPILER_VAR_1152[3] = tmpArgsStruct;____BAH_COMPILER_VAR_1152[2] = "(";____BAH_COMPILER_VAR_1152[1] = fnWrapper;____BAH_COMPILER_VAR_1152[0] = "\n    void ";char * ____BAH_COMPILER_VAR_1153 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1152, 25);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1153));
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

    unsigned int ____BAH_COMPILER_VAR_1154 = len(compilerState.RCPvars);
    __Bah_realocate_arr(compilerState.RCPvars, ____BAH_COMPILER_VAR_1154);
    compilerState.RCPvars->data[____BAH_COMPILER_VAR_1154] = v;
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
char * ____BAH_COMPILER_VAR_1155 =getTypeFromToken(&nt,true,elems);struct string ntt = string(____BAH_COMPILER_VAR_1155);
if (__builtin_expect((string__hasPrefix(&ntt,"chan:")==0), 0)) {
char** ____BAH_COMPILER_VAR_1156 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1156[2] = ") as channel.";____BAH_COMPILER_VAR_1156[1] = string__str(&ntt);____BAH_COMPILER_VAR_1156[0] = "Cannot use var {TOKEN} (";char * ____BAH_COMPILER_VAR_1157 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1156, 3);throwErr(&nt,____BAH_COMPILER_VAR_1157);
}
string__trimLeft(&ntt,5);
if (__builtin_expect(isGlobal(), 0)) {
throwErr(&t,"Cannot receive ({TOKEN}) from a channel outside of a function.");
}
char * tmpV = "";
char * ____BAH_COMPILER_VAR_1158 =string__str(&ntt);if (isRCPpointerType(____BAH_COMPILER_VAR_1158)) {
char * ____BAH_COMPILER_VAR_1159 =string__str(&ntt);struct string ct = getCType(____BAH_COMPILER_VAR_1159,elems);
char** ____BAH_COMPILER_VAR_1160 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_1160[6] = ")";____BAH_COMPILER_VAR_1160[5] = nt.cont;____BAH_COMPILER_VAR_1160[4] = "->receive(";____BAH_COMPILER_VAR_1160[3] = nt.cont;____BAH_COMPILER_VAR_1160[2] = ")";____BAH_COMPILER_VAR_1160[1] = string__str(&ct);____BAH_COMPILER_VAR_1160[0] = "(";char * ____BAH_COMPILER_VAR_1161 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1160, 7);t.cont = ____BAH_COMPILER_VAR_1161;
}
else {
char * ____BAH_COMPILER_VAR_1162 =string__str(&ntt);struct string ct = getCType(____BAH_COMPILER_VAR_1162,elems);
if (RCPavailable()) {
char** ____BAH_COMPILER_VAR_1163 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1163[1] = "*";____BAH_COMPILER_VAR_1163[0] = string__str(&ntt);char * ____BAH_COMPILER_VAR_1164 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1163, 2);char** ____BAH_COMPILER_VAR_1165 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_1165[6] = ")";____BAH_COMPILER_VAR_1165[5] = nt.cont;____BAH_COMPILER_VAR_1165[4] = "->receive(";____BAH_COMPILER_VAR_1165[3] = nt.cont;____BAH_COMPILER_VAR_1165[2] = "*)";____BAH_COMPILER_VAR_1165[1] = string__str(&ct);____BAH_COMPILER_VAR_1165[0] = "(";char * ____BAH_COMPILER_VAR_1166 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1165, 7);tmpV = registerRCPvar(____BAH_COMPILER_VAR_1164,____BAH_COMPILER_VAR_1166,elems);
char** ____BAH_COMPILER_VAR_1167 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1167[1] = tmpV;____BAH_COMPILER_VAR_1167[0] = "*";char * ____BAH_COMPILER_VAR_1168 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1167, 2);t.cont = ____BAH_COMPILER_VAR_1168;
}
else {
char** ____BAH_COMPILER_VAR_1169 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_1169[6] = ")";____BAH_COMPILER_VAR_1169[5] = nt.cont;____BAH_COMPILER_VAR_1169[4] = "->receive(";____BAH_COMPILER_VAR_1169[3] = nt.cont;____BAH_COMPILER_VAR_1169[2] = "*)";____BAH_COMPILER_VAR_1169[1] = string__str(&ct);____BAH_COMPILER_VAR_1169[0] = "*(";char * ____BAH_COMPILER_VAR_1170 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1169, 7);t.cont = ____BAH_COMPILER_VAR_1170;
}
}
t.type = TOKEN_TYPE_FUNC;
t.isFunc = true;
if (RCPavailable()) {
char * ____BAH_COMPILER_VAR_1171 =string__str(&ntt);if (isRCPpointerType(____BAH_COMPILER_VAR_1171)) {
char * ____BAH_COMPILER_VAR_1172 =string__str(&ntt);tmpV = registerRCPvar(____BAH_COMPILER_VAR_1172,t.cont,elems);
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
char * ____BAH_COMPILER_VAR_1173 =getTypeFromToken(&pt,true,elems);struct string ptt = string(____BAH_COMPILER_VAR_1173);
if (__builtin_expect((string__hasPrefix(&ptt,"chan:")==0), 0)) {
char** ____BAH_COMPILER_VAR_1174 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1174[2] = ") as channel.";____BAH_COMPILER_VAR_1174[1] = ntt;____BAH_COMPILER_VAR_1174[0] = "Cannot use var {TOKEN} (";char * ____BAH_COMPILER_VAR_1175 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1174, 3);throwErr(&pt,____BAH_COMPILER_VAR_1175);
}
string__trimLeft(&ptt,5);
if (__builtin_expect(isGlobal(), 0)) {
throwErr(&t,"Cannot send ({TOKEN}) to a channel outside of a function.");
}
char * ____BAH_COMPILER_VAR_1176 =string__str(&ptt);if (__builtin_expect((compTypes(____BAH_COMPILER_VAR_1176,ntt)==false), 0)) {
char** ____BAH_COMPILER_VAR_1177 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1177[4] = ".";____BAH_COMPILER_VAR_1177[3] = string__str(&ptt);____BAH_COMPILER_VAR_1177[2] = ") to channel of type ";____BAH_COMPILER_VAR_1177[1] = ntt;____BAH_COMPILER_VAR_1177[0] = "Cannot send {TOKEN} (";char * ____BAH_COMPILER_VAR_1178 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1177, 5);throwErr(&nt,____BAH_COMPILER_VAR_1178);
}
++i;
char * ____BAH_COMPILER_VAR_1179 =string__str(&ptt);if (isRCPpointerType(____BAH_COMPILER_VAR_1179)) {
char** ____BAH_COMPILER_VAR_1180 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_1180[5] = ");\n";____BAH_COMPILER_VAR_1180[4] = nt.cont;____BAH_COMPILER_VAR_1180[3] = ", ";____BAH_COMPILER_VAR_1180[2] = pt.cont;____BAH_COMPILER_VAR_1180[1] = "->send(";____BAH_COMPILER_VAR_1180[0] = pt.cont;char * ____BAH_COMPILER_VAR_1181 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1180, 6);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1181));
}
else {
struct string ct = getCType(ntt,elems);
char * tmpV = genCompilerVar();
char** ____BAH_COMPILER_VAR_1182 = alloca(15 * sizeof(char*));____BAH_COMPILER_VAR_1182[14] = "));\n";____BAH_COMPILER_VAR_1182[13] = tmpV;____BAH_COMPILER_VAR_1182[12] = ", sizeof(";____BAH_COMPILER_VAR_1182[11] = tmpV;____BAH_COMPILER_VAR_1182[10] = ", &";____BAH_COMPILER_VAR_1182[9] = pt.cont;____BAH_COMPILER_VAR_1182[8] = "->sendAny(";____BAH_COMPILER_VAR_1182[7] = pt.cont;____BAH_COMPILER_VAR_1182[6] = ";\n                    ";____BAH_COMPILER_VAR_1182[5] = nt.cont;____BAH_COMPILER_VAR_1182[4] = " = ";____BAH_COMPILER_VAR_1182[3] = tmpV;____BAH_COMPILER_VAR_1182[2] = " ";____BAH_COMPILER_VAR_1182[1] = string__str(&ct);____BAH_COMPILER_VAR_1182[0] = "\n                    ";char * ____BAH_COMPILER_VAR_1183 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1182, 15);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1183));
}
nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
return nl;
}
}

    unsigned int ____BAH_COMPILER_VAR_1184 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_1184);
    nl->data[____BAH_COMPILER_VAR_1184] = t;
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
char** ____BAH_COMPILER_VAR_1185 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1185[1] = t.ogCont;____BAH_COMPILER_VAR_1185[0] = fnt.ogCont;char * ____BAH_COMPILER_VAR_1186 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1185, 2);fnt.ogCont = ____BAH_COMPILER_VAR_1186;
if ((strcmp(t.cont, "(") == 0)||(strcmp(t.cont, "{") == 0)||(strcmp(t.cont, "[") == 0)) {
++nbEncls;
}
else if ((strcmp(t.cont, ")") == 0)||(strcmp(t.cont, "}") == 0)||(strcmp(t.cont, "]") == 0)) {
--nbEncls;
if ((nbEncls==0)) {
break;
}
}

    unsigned int ____BAH_COMPILER_VAR_1187 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1187);
    memory->data[____BAH_COMPILER_VAR_1187] = t;
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
char** ____BAH_COMPILER_VAR_1188 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1188[1] = t.cont;____BAH_COMPILER_VAR_1188[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1189 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1188, 2);fnt.cont = ____BAH_COMPILER_VAR_1189;
};
char** ____BAH_COMPILER_VAR_1190 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1190[1] = ")";____BAH_COMPILER_VAR_1190[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1191 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1190, 2);fnt.cont = ____BAH_COMPILER_VAR_1191;

    unsigned int ____BAH_COMPILER_VAR_1192 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1192);
    l->data[____BAH_COMPILER_VAR_1192] = fnt;
return tokPos;
}
if ((strcmp(fn->name, "exit") == 0)||(strcmp(fn->name, "panic") == 0)||(fn->exits==true)) {
if ((compilerState.isBranch==true)) {
elems->currFlowEnd = true;
}
setNullStateBranchFlowEnd(elems);
}
char** ____BAH_COMPILER_VAR_1193 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1193[1] = "(";____BAH_COMPILER_VAR_1193[0] = fn->name;char * ____BAH_COMPILER_VAR_1194 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1193, 2);fnt.cont = ____BAH_COMPILER_VAR_1194;
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
char** ____BAH_COMPILER_VAR_1195 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1195[1] = "(";____BAH_COMPILER_VAR_1195[0] = fn->name;char * ____BAH_COMPILER_VAR_1196 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1195, 2);fnt.ogCont = ____BAH_COMPILER_VAR_1196;
for (; (i<len(l)); ++i) {
struct Tok t = l->data[i];
char** ____BAH_COMPILER_VAR_1197 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1197[1] = t.ogCont;____BAH_COMPILER_VAR_1197[0] = fnt.ogCont;char * ____BAH_COMPILER_VAR_1198 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1197, 2);fnt.ogCont = ____BAH_COMPILER_VAR_1198;
if ((strcmp(t.cont, "(") == 0)||(strcmp(t.cont, "{") == 0)||(strcmp(t.cont, "[") == 0)) {
++nbEncls;
}
else if ((strcmp(t.cont, ")") == 0)||(strcmp(t.cont, "}") == 0)||(strcmp(t.cont, "]") == 0)) {
--nbEncls;
if ((nbEncls==0)) {
break;
}
}

    unsigned int ____BAH_COMPILER_VAR_1199 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1199);
    memory->data[____BAH_COMPILER_VAR_1199] = t;
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
char** ____BAH_COMPILER_VAR_1200 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1200[1] = t.cont;____BAH_COMPILER_VAR_1200[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1201 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1200, 2);fnt.cont = ____BAH_COMPILER_VAR_1201;
};

    unsigned int ____BAH_COMPILER_VAR_1202 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1202);
    l->data[____BAH_COMPILER_VAR_1202] = fnt;
return tokPos;
}
char** ____BAH_COMPILER_VAR_1203 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1203[4] = "\"";____BAH_COMPILER_VAR_1203[3] = intToStr(fnt.line);____BAH_COMPILER_VAR_1203[2] = ":";____BAH_COMPILER_VAR_1203[1] = compilerState.currentFile;____BAH_COMPILER_VAR_1203[0] = "\"";char * ____BAH_COMPILER_VAR_1204 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1203, 5);char * currLine = ____BAH_COMPILER_VAR_1204;
if ((strcmp(fn->name, "panic") == 0)) {
struct Tok ____BAH_COMPILER_VAR_1205 = {};
____BAH_COMPILER_VAR_1205.cont = "";
____BAH_COMPILER_VAR_1205.ogCont = "";
____BAH_COMPILER_VAR_1205.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1205.line = 1;
____BAH_COMPILER_VAR_1205.begLine = 1;
____BAH_COMPILER_VAR_1205.bahType = "";
____BAH_COMPILER_VAR_1205.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_1205.cont = ",";
____BAH_COMPILER_VAR_1205.line = fnt.line;

    unsigned int ____BAH_COMPILER_VAR_1206 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1206);
    memory->data[____BAH_COMPILER_VAR_1206] = ____BAH_COMPILER_VAR_1205;
struct Tok ____BAH_COMPILER_VAR_1207 = {};
____BAH_COMPILER_VAR_1207.cont = "";
____BAH_COMPILER_VAR_1207.ogCont = "";
____BAH_COMPILER_VAR_1207.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1207.line = 1;
____BAH_COMPILER_VAR_1207.begLine = 1;
____BAH_COMPILER_VAR_1207.bahType = "";
____BAH_COMPILER_VAR_1207.type = TOKEN_TYPE_STR;
____BAH_COMPILER_VAR_1207.cont = currLine;
____BAH_COMPILER_VAR_1207.line = fnt.line;

    unsigned int ____BAH_COMPILER_VAR_1208 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1208);
    memory->data[____BAH_COMPILER_VAR_1208] = ____BAH_COMPILER_VAR_1207;
fn = searchFunc("__BAH_panic",elems,true);
char** ____BAH_COMPILER_VAR_1209 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1209[1] = "(";____BAH_COMPILER_VAR_1209[0] = fn->name;char * ____BAH_COMPILER_VAR_1210 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1209, 2);fnt.cont = ____BAH_COMPILER_VAR_1210;
}
else if ((strcmp(fn->name, "__dumpSymbols") == 0)) {
array(struct variable*)* symbols = memoryAlloc(sizeof(array(struct variable*)));

symbols->length = 0;
symbols->elemSize = sizeof(struct variable*);
register long int j = 0;
for (; (j<len(elems->vars)); ++j) {
struct variable* v = elems->vars->data[j];
if ((v->isConst==false)) {

    unsigned int ____BAH_COMPILER_VAR_1211 = len(symbols);
    __Bah_realocate_arr(symbols, ____BAH_COMPILER_VAR_1211);
    symbols->data[____BAH_COMPILER_VAR_1211] = v;
}
};
struct variable* ____BAH_COMPILER_VAR_1212 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1212->name = "";
____BAH_COMPILER_VAR_1212->type = "";
____BAH_COMPILER_VAR_1212->constVal = "";
____BAH_COMPILER_VAR_1212->from = "";
____BAH_COMPILER_VAR_1212->name = genCompilerVar();
____BAH_COMPILER_VAR_1212->type = "[]reflectElement";
____BAH_COMPILER_VAR_1212->isArray = true;
struct variable* tmpV = ____BAH_COMPILER_VAR_1212;
char * decls = "";
j = 0;
for (; (j<len(symbols)); ++j) {
struct variable* v = symbols->data[j];
char * vname = v->name;
if ((strCount(v->type,"*")==0)) {
char** ____BAH_COMPILER_VAR_1213 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1213[1] = v->name;____BAH_COMPILER_VAR_1213[0] = "&";char * ____BAH_COMPILER_VAR_1214 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1213, 2);vname = ____BAH_COMPILER_VAR_1214;
}
struct Tok ____BAH_COMPILER_VAR_1215 = {};
____BAH_COMPILER_VAR_1215.cont = "";
____BAH_COMPILER_VAR_1215.ogCont = "";
____BAH_COMPILER_VAR_1215.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1215.line = 1;
____BAH_COMPILER_VAR_1215.begLine = 1;
____BAH_COMPILER_VAR_1215.bahType = "";
____BAH_COMPILER_VAR_1215.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_1215.cont = vname;
____BAH_COMPILER_VAR_1215.bahType = v->type;
____BAH_COMPILER_VAR_1215.isValue = true;
struct Tok tmpT = ____BAH_COMPILER_VAR_1215;
tmpT = parseReflect(tmpT,v->type,elems,true,v->name,"0");
char** ____BAH_COMPILER_VAR_1216 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_1216[5] = ";\n";____BAH_COMPILER_VAR_1216[4] = tmpT.cont;____BAH_COMPILER_VAR_1216[3] = "] = ";____BAH_COMPILER_VAR_1216[2] = intToStr(j);____BAH_COMPILER_VAR_1216[1] = "->data[";____BAH_COMPILER_VAR_1216[0] = tmpV->name;char * ____BAH_COMPILER_VAR_1217 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1216, 6);char** ____BAH_COMPILER_VAR_1218 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1218[1] = ____BAH_COMPILER_VAR_1217;____BAH_COMPILER_VAR_1218[0] = decls;char * ____BAH_COMPILER_VAR_1219 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1218, 2);decls = ____BAH_COMPILER_VAR_1219;
};

    unsigned int ____BAH_COMPILER_VAR_1220 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_1220);
    elems->vars->data[____BAH_COMPILER_VAR_1220] = tmpV;
char** ____BAH_COMPILER_VAR_1221 = alloca(15 * sizeof(char*));____BAH_COMPILER_VAR_1221[14] = "\n        ";____BAH_COMPILER_VAR_1221[13] = decls;____BAH_COMPILER_VAR_1221[12] = "->elemSize = sizeof(struct reflectElement);\n        ";____BAH_COMPILER_VAR_1221[11] = tmpV->name;____BAH_COMPILER_VAR_1221[10] = ";\n        ";____BAH_COMPILER_VAR_1221[9] = intToStr(len(symbols));____BAH_COMPILER_VAR_1221[8] = "->length = ";____BAH_COMPILER_VAR_1221[7] = tmpV->name;____BAH_COMPILER_VAR_1221[6] = ");\n        ";____BAH_COMPILER_VAR_1221[5] = intToStr(len(symbols));____BAH_COMPILER_VAR_1221[4] = "->data = memoryAlloc(sizeof(struct reflectElement) * ";____BAH_COMPILER_VAR_1221[3] = tmpV->name;____BAH_COMPILER_VAR_1221[2] = " = memoryAlloc(sizeof(array(struct reflectElement)));\n        ";____BAH_COMPILER_VAR_1221[1] = tmpV->name;____BAH_COMPILER_VAR_1221[0] = "\n        array(struct reflectElement)* ";char * ____BAH_COMPILER_VAR_1222 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1221, 15);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1222));
struct Tok ____BAH_COMPILER_VAR_1223 = {};
____BAH_COMPILER_VAR_1223.cont = "";
____BAH_COMPILER_VAR_1223.ogCont = "";
____BAH_COMPILER_VAR_1223.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1223.line = 1;
____BAH_COMPILER_VAR_1223.begLine = 1;
____BAH_COMPILER_VAR_1223.bahType = "";
____BAH_COMPILER_VAR_1223.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_1223.cont = tmpV->name;
____BAH_COMPILER_VAR_1223.line = fnt.line;
____BAH_COMPILER_VAR_1223.isValue = true;

    unsigned int ____BAH_COMPILER_VAR_1224 = 0;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1224);
    memory->data[____BAH_COMPILER_VAR_1224] = ____BAH_COMPILER_VAR_1223;
}
else if ((strcmp(fn->name, "breakPoint") == 0)) {
struct Tok ____BAH_COMPILER_VAR_1225 = {};
____BAH_COMPILER_VAR_1225.cont = "";
____BAH_COMPILER_VAR_1225.ogCont = "";
____BAH_COMPILER_VAR_1225.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1225.line = 1;
____BAH_COMPILER_VAR_1225.begLine = 1;
____BAH_COMPILER_VAR_1225.bahType = "";
____BAH_COMPILER_VAR_1225.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_1225.cont = "__dumpSymbols";
____BAH_COMPILER_VAR_1225.line = fnt.line;
struct Tok ____BAH_COMPILER_VAR_1226 = {};
____BAH_COMPILER_VAR_1226.cont = "";
____BAH_COMPILER_VAR_1226.ogCont = "";
____BAH_COMPILER_VAR_1226.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1226.line = 1;
____BAH_COMPILER_VAR_1226.begLine = 1;
____BAH_COMPILER_VAR_1226.bahType = "";
____BAH_COMPILER_VAR_1226.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_1226.cont = "(";
____BAH_COMPILER_VAR_1226.line = fnt.line;
struct Tok ____BAH_COMPILER_VAR_1227 = {};
____BAH_COMPILER_VAR_1227.cont = "";
____BAH_COMPILER_VAR_1227.ogCont = "";
____BAH_COMPILER_VAR_1227.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1227.line = 1;
____BAH_COMPILER_VAR_1227.begLine = 1;
____BAH_COMPILER_VAR_1227.bahType = "";
____BAH_COMPILER_VAR_1227.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_1227.cont = ")";
____BAH_COMPILER_VAR_1227.line = fnt.line;
memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 3;
memory->elemSize = sizeof(struct Tok);
memory->data = memoryAlloc(sizeof(struct Tok) * 50);
                    memory->realLength = 50;
memory->data[0] = ____BAH_COMPILER_VAR_1225;
memory->data[1] = ____BAH_COMPILER_VAR_1226;
memory->data[2] = ____BAH_COMPILER_VAR_1227;
memory = prePross(memory,LINE_TYPE_FN_CALL,elems);
struct Tok ____BAH_COMPILER_VAR_1228 = {};
____BAH_COMPILER_VAR_1228.cont = "";
____BAH_COMPILER_VAR_1228.ogCont = "";
____BAH_COMPILER_VAR_1228.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1228.line = 1;
____BAH_COMPILER_VAR_1228.begLine = 1;
____BAH_COMPILER_VAR_1228.bahType = "";
____BAH_COMPILER_VAR_1228.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_1228.cont = ",";
____BAH_COMPILER_VAR_1228.line = fnt.line;

    unsigned int ____BAH_COMPILER_VAR_1229 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1229);
    memory->data[____BAH_COMPILER_VAR_1229] = ____BAH_COMPILER_VAR_1228;
struct Tok ____BAH_COMPILER_VAR_1230 = {};
____BAH_COMPILER_VAR_1230.cont = "";
____BAH_COMPILER_VAR_1230.ogCont = "";
____BAH_COMPILER_VAR_1230.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1230.line = 1;
____BAH_COMPILER_VAR_1230.begLine = 1;
____BAH_COMPILER_VAR_1230.bahType = "";
____BAH_COMPILER_VAR_1230.type = TOKEN_TYPE_STR;
____BAH_COMPILER_VAR_1230.cont = currLine;
____BAH_COMPILER_VAR_1230.line = fnt.line;

    unsigned int ____BAH_COMPILER_VAR_1231 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1231);
    memory->data[____BAH_COMPILER_VAR_1231] = ____BAH_COMPILER_VAR_1230;
fn = searchFunc("breakPoint__inner",elems,true);
char** ____BAH_COMPILER_VAR_1232 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1232[1] = "(";____BAH_COMPILER_VAR_1232[0] = fn->name;char * ____BAH_COMPILER_VAR_1233 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1232, 2);fnt.cont = ____BAH_COMPILER_VAR_1233;
}
else if ((strcmp(fn->name, "sizeof") == 0)) {
char * tp = "";
register long int j = 0;
for (; (j<len(memory)); ++j) {
struct Tok tmpT = memory->data[j];
char** ____BAH_COMPILER_VAR_1234 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1234[1] = tmpT.cont;____BAH_COMPILER_VAR_1234[0] = tp;char * ____BAH_COMPILER_VAR_1235 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1234, 2);tp = ____BAH_COMPILER_VAR_1235;
};
struct variable* tmpV = searchVar(tp,elems);
if ((tmpV!=null)) {
struct string cType = getCType(tmpV->type,elems);
char** ____BAH_COMPILER_VAR_1236 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1236[1] = ")";____BAH_COMPILER_VAR_1236[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_1237 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1236, 2);char** ____BAH_COMPILER_VAR_1238 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1238[1] = ____BAH_COMPILER_VAR_1237;____BAH_COMPILER_VAR_1238[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1239 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1238, 2);fnt.cont = ____BAH_COMPILER_VAR_1239;
}
else {
struct string cType = getCType(tp,elems);
if (__builtin_expect((cType.length==0), 0)) {
struct Tok ft = memory->data[0];
throwErr(&ft,"Cannot get size of {TOKEN}.");
}
char** ____BAH_COMPILER_VAR_1240 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1240[1] = ")";____BAH_COMPILER_VAR_1240[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_1241 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1240, 2);char** ____BAH_COMPILER_VAR_1242 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1242[1] = ____BAH_COMPILER_VAR_1241;____BAH_COMPILER_VAR_1242[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1243 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1242, 2);fnt.cont = ____BAH_COMPILER_VAR_1243;
}
fnt.type = TOKEN_TYPE_FUNC;
fnt.isFunc = true;
fnt.bahType = "int";
fnt.bahRef = fn;

    unsigned int ____BAH_COMPILER_VAR_1244 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1244);
    l->data[____BAH_COMPILER_VAR_1244] = fnt;
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
char** ____BAH_COMPILER_VAR_1245 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1245[1] = parent->name;____BAH_COMPILER_VAR_1245[0] = amp;char * ____BAH_COMPILER_VAR_1246 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1245, 2);char** ____BAH_COMPILER_VAR_1247 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1247[1] = ____BAH_COMPILER_VAR_1246;____BAH_COMPILER_VAR_1247[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1248 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1247, 2);fnt.cont = ____BAH_COMPILER_VAR_1248;
++argIndex;
if ((len(fn->args)>argIndex)) {
char** ____BAH_COMPILER_VAR_1249 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1249[1] = ",";____BAH_COMPILER_VAR_1249[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1250 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1249, 2);fnt.cont = ____BAH_COMPILER_VAR_1250;
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
if (((fn->isImported==true)||isInside(BAH_DIR,fn->file))&&(t.type==TOKEN_TYPE_VAR)) {
fixMeTestVar(&t,elems);
}
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
char** ____BAH_COMPILER_VAR_1251 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1251[1] = string__str(&tts);____BAH_COMPILER_VAR_1251[0] = "__";char * ____BAH_COMPILER_VAR_1252 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1251, 2);char** ____BAH_COMPILER_VAR_1253 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1253[1] = ____BAH_COMPILER_VAR_1252;____BAH_COMPILER_VAR_1253[0] = fn->name;char * ____BAH_COMPILER_VAR_1254 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1253, 2);fn->name = ____BAH_COMPILER_VAR_1254;
}
else {
if (__builtin_expect((compTypes(arg->type,tt)==false), 0)) {
char** ____BAH_COMPILER_VAR_1255 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1255[4] = " in function call.";____BAH_COMPILER_VAR_1255[3] = arg->type;____BAH_COMPILER_VAR_1255[2] = ") as ";____BAH_COMPILER_VAR_1255[1] = tt;____BAH_COMPILER_VAR_1255[0] = "Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_1256 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1255, 5);throwErr(&t,____BAH_COMPILER_VAR_1256);
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
char** ____BAH_COMPILER_VAR_1257 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1257[1] = t.cont;____BAH_COMPILER_VAR_1257[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1258 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1257, 2);fnt.cont = ____BAH_COMPILER_VAR_1258;
++argIndex;
if ((j+1<len(memory))) {
++j;
t = memory->data[j];
if (__builtin_expect((strcmp(t.cont, ",") != 0), 0)) {
throwErr(&t,"Need separator between arguments, not {TOKEN}.");
}
char** ____BAH_COMPILER_VAR_1259 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1259[1] = ",";____BAH_COMPILER_VAR_1259[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1260 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1259, 2);fnt.cont = ____BAH_COMPILER_VAR_1260;
}
};
if (__builtin_expect((argIndex!=len(fn->args)), 0)) {
struct Tok lt = l->data[tokPos];
char** ____BAH_COMPILER_VAR_1261 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1261[2] = "'.";____BAH_COMPILER_VAR_1261[1] = fn->name;____BAH_COMPILER_VAR_1261[0] = "Not enough argument {TOKEN}, calling '";char * ____BAH_COMPILER_VAR_1262 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1261, 3);throwErr(&lt,____BAH_COMPILER_VAR_1262);
}
if ((generic!=null)) {
char** ____BAH_COMPILER_VAR_1263 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1263[3] = cpstringSubsitute(fnt.cont, ogFntContL, strlen(fnt.cont));____BAH_COMPILER_VAR_1263[2] = "(";____BAH_COMPILER_VAR_1263[1] = fn->name;____BAH_COMPILER_VAR_1263[0] = "__generic_";char * ____BAH_COMPILER_VAR_1264 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1263, 4);fnt.cont = ____BAH_COMPILER_VAR_1264;
if ((genericFunc__isAlreadyDecl(generic,fn->name)==false)) {
genericFunc__declare(generic,fn,elems);
}
}
fnt.bahRef = fn;
char** ____BAH_COMPILER_VAR_1265 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1265[1] = ")";____BAH_COMPILER_VAR_1265[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1266 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1265, 2);fnt.cont = ____BAH_COMPILER_VAR_1266;

    unsigned int ____BAH_COMPILER_VAR_1267 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1267);
    l->data[____BAH_COMPILER_VAR_1267] = fnt;
return tokPos;
};
long int valueStruct(__BAH_ARR_TYPE_Tok l,long int i,lineType ltp,struct Elems* elems){
long int tokPos = i-1;
struct Tok t = l->data[i-1];
char * tt = getTypeFromToken(&t,true,elems);
struct cStruct* s = searchStruct(tt,elems);
if ((s==null)) {
if (__builtin_expect((tt[strlen(tt)-1]==33), 0)) {
char** ____BAH_COMPILER_VAR_1268 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1268[2] = ") as structure.";____BAH_COMPILER_VAR_1268[1] = tt;____BAH_COMPILER_VAR_1268[0] = "Cannot use maybe value {TOKEN} (";char * ____BAH_COMPILER_VAR_1269 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1268, 3);throwErr(&t,____BAH_COMPILER_VAR_1269);
}
else {
char** ____BAH_COMPILER_VAR_1270 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1270[2] = ").";____BAH_COMPILER_VAR_1270[1] = tt;____BAH_COMPILER_VAR_1270[0] = "Unkown struct {TOKEN} (";char * ____BAH_COMPILER_VAR_1271 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1270, 3);throwErr(&t,____BAH_COMPILER_VAR_1271);
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
if ((t.type==TOKEN_TYPE_VAR)) {
fixMeTestVar(&t,elems);
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
char** ____BAH_COMPILER_VAR_1272 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_1272[6] = ";\n                ";____BAH_COMPILER_VAR_1272[5] = t.cont;____BAH_COMPILER_VAR_1272[4] = " = ";____BAH_COMPILER_VAR_1272[3] = tmpV;____BAH_COMPILER_VAR_1272[2] = " ";____BAH_COMPILER_VAR_1272[1] = string__str(&cType);____BAH_COMPILER_VAR_1272[0] = "\n                ";char * ____BAH_COMPILER_VAR_1273 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1272, 7);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1273));
t.cont = tmpV;
struct variable* ____BAH_COMPILER_VAR_1274 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1274->name = "";
____BAH_COMPILER_VAR_1274->type = "";
____BAH_COMPILER_VAR_1274->constVal = "";
____BAH_COMPILER_VAR_1274->from = "";
____BAH_COMPILER_VAR_1274->name = tmpV;
____BAH_COMPILER_VAR_1274->type = tt;
parent = ____BAH_COMPILER_VAR_1274;
if (RCPavailable()) {

    unsigned int ____BAH_COMPILER_VAR_1275 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_1275);
    elems->vars->data[____BAH_COMPILER_VAR_1275] = parent;
}
}
struct func* fn = searchStructMethod(nt.cont,s,elems);
if (__builtin_expect((fn==null), 0)) {
char** ____BAH_COMPILER_VAR_1276 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1276[2] = ".";____BAH_COMPILER_VAR_1276[1] = s->name;____BAH_COMPILER_VAR_1276[0] = "Unknown method {TOKEN} in struct ";char * ____BAH_COMPILER_VAR_1277 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1276, 3);throwErr(&nt,____BAH_COMPILER_VAR_1277);
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
char** ____BAH_COMPILER_VAR_1278 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1278[2] = fn->name;____BAH_COMPILER_VAR_1278[1] = sep;____BAH_COMPILER_VAR_1278[0] = t.cont;char * ____BAH_COMPILER_VAR_1279 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1278, 3);fn->name = ____BAH_COMPILER_VAR_1279;
}
if (__builtin_expect((parent==null), 0)) {
throwErr(&t,"Could not find structure {TOKEN}.");
}
valueFunc(fn,parent,l,i,ltp,elems);
struct Tok fnt = l->data[i];
delete(l,i);
char** ____BAH_COMPILER_VAR_1280 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1280[2] = nt.ogCont;____BAH_COMPILER_VAR_1280[1] = ".";____BAH_COMPILER_VAR_1280[0] = t.ogCont;char * ____BAH_COMPILER_VAR_1281 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1280, 3);fnt.ogCont = ____BAH_COMPILER_VAR_1281;
fnt.pos = t.pos;

    unsigned int ____BAH_COMPILER_VAR_1282 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1282);
    l->data[____BAH_COMPILER_VAR_1282] = fnt;
return tokPos;
}
}
struct structMemb* m = searchStructMemb(nt.cont,s,elems);
if (__builtin_expect((m==null), 0)) {
char** ____BAH_COMPILER_VAR_1283 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1283[2] = "'.";____BAH_COMPILER_VAR_1283[1] = s->name;____BAH_COMPILER_VAR_1283[0] = "Unknown struct member {TOKEN} in struct '";char * ____BAH_COMPILER_VAR_1284 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1283, 3);throwErr(&nt,____BAH_COMPILER_VAR_1284);
}
char * ast = "";
if ((t.cont[0]==38)) {
ast = "*";
}
if ((m->isFn==true)) {
char** ____BAH_COMPILER_VAR_1285 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1285[2] = m->name;____BAH_COMPILER_VAR_1285[1] = "__";____BAH_COMPILER_VAR_1285[0] = s->name;char * ____BAH_COMPILER_VAR_1286 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1285, 3);t.cont = ____BAH_COMPILER_VAR_1286;
}
else {
if ((t.type==TOKEN_TYPE_VAR)) {
t.parent = searchVarByToken(&t,elems);
}
char** ____BAH_COMPILER_VAR_1287 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1287[1] = nt.cont;____BAH_COMPILER_VAR_1287[0] = sep;char * ____BAH_COMPILER_VAR_1288 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1287, 2);char** ____BAH_COMPILER_VAR_1289 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1289[1] = ____BAH_COMPILER_VAR_1288;____BAH_COMPILER_VAR_1289[0] = t.cont;char * ____BAH_COMPILER_VAR_1290 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1289, 2);t.cont = ____BAH_COMPILER_VAR_1290;
}
char** ____BAH_COMPILER_VAR_1291 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1291[1] = nt.cont;____BAH_COMPILER_VAR_1291[0] = ".";char * ____BAH_COMPILER_VAR_1292 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1291, 2);char** ____BAH_COMPILER_VAR_1293 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1293[1] = ____BAH_COMPILER_VAR_1292;____BAH_COMPILER_VAR_1293[0] = t.ogCont;char * ____BAH_COMPILER_VAR_1294 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1293, 2);t.ogCont = ____BAH_COMPILER_VAR_1294;
char** ____BAH_COMPILER_VAR_1295 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1295[1] = ast;____BAH_COMPILER_VAR_1295[0] = m->type;char * ____BAH_COMPILER_VAR_1296 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1295, 2);t.bahType = ____BAH_COMPILER_VAR_1296;
struct variable* ____BAH_COMPILER_VAR_1297 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1297->name = "";
____BAH_COMPILER_VAR_1297->type = "";
____BAH_COMPILER_VAR_1297->constVal = "";
____BAH_COMPILER_VAR_1297->from = "";
____BAH_COMPILER_VAR_1297->name = t.cont;
____BAH_COMPILER_VAR_1297->type = t.bahType;
t.bahRef = ____BAH_COMPILER_VAR_1297;

    unsigned int ____BAH_COMPILER_VAR_1298 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1298);
    l->data[____BAH_COMPILER_VAR_1298] = t;
return tokPos;
};
long int valueArr(__BAH_ARR_TYPE_Tok l,long int i,lineType ltp,struct Elems* elems){
long int tokPos = i-1;
struct Tok pt = l->data[tokPos];
delete(l,tokPos);
if (__builtin_expect((pt.isValue==false), 0)) {
throwErr(&pt,"Cannot use {TOKEN} as value (array).");
}
char * ____BAH_COMPILER_VAR_1299 =getTypeFromToken(&pt,true,elems);struct string ptt = string(____BAH_COMPILER_VAR_1299);
struct Tok t = pt;
t.isValue = true;
char** ____BAH_COMPILER_VAR_1300 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1300[1] = "[";____BAH_COMPILER_VAR_1300[0] = t.ogCont;char * ____BAH_COMPILER_VAR_1301 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1300, 2);t.ogCont = ____BAH_COMPILER_VAR_1301;
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
char** ____BAH_COMPILER_VAR_1302 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1302[1] = "]";____BAH_COMPILER_VAR_1302[0] = t.ogCont;char * ____BAH_COMPILER_VAR_1303 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1302, 2);t.ogCont = ____BAH_COMPILER_VAR_1303;
if ((nbEncls==0)) {
break;
}
}
char** ____BAH_COMPILER_VAR_1304 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1304[1] = tmpT.ogCont;____BAH_COMPILER_VAR_1304[0] = t.ogCont;char * ____BAH_COMPILER_VAR_1305 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1304, 2);t.ogCont = ____BAH_COMPILER_VAR_1305;

    unsigned int ____BAH_COMPILER_VAR_1306 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1306);
    memory->data[____BAH_COMPILER_VAR_1306] = tmpT;
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
char * ____BAH_COMPILER_VAR_1307 =getTypeFromToken(&index,true,elems);if (__builtin_expect((compTypes(____BAH_COMPILER_VAR_1307,"int")==false), 0)) {
throwErr(&index,"Cannot use {TOKEN} as array index (int).");
}
string__trimLeft(&ptt,2);
t.bahType = string__str(&ptt);
char** ____BAH_COMPILER_VAR_1308 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1308[3] = "]";____BAH_COMPILER_VAR_1308[2] = index.cont;____BAH_COMPILER_VAR_1308[1] = "->data[";____BAH_COMPILER_VAR_1308[0] = pt.cont;char * ____BAH_COMPILER_VAR_1309 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1308, 4);t.cont = ____BAH_COMPILER_VAR_1309;
if ((tokPos+1<len(l))&&(strcmp(l->data[tokPos+1].cont, ".") == 0)) {
struct variable* ____BAH_COMPILER_VAR_1310 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1310->name = "";
____BAH_COMPILER_VAR_1310->type = "";
____BAH_COMPILER_VAR_1310->constVal = "";
____BAH_COMPILER_VAR_1310->from = "";
____BAH_COMPILER_VAR_1310->name = t.cont;
____BAH_COMPILER_VAR_1310->type = t.bahType;
struct variable* tmpV = ____BAH_COMPILER_VAR_1310;
t.bahRef = tmpV;
}
}
else {
t.bahType = string__str(&ptt);
if ((strcmp(to, "") == 0)) {
char** ____BAH_COMPILER_VAR_1311 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1311[1] = "->length";____BAH_COMPILER_VAR_1311[0] = pt.cont;char * ____BAH_COMPILER_VAR_1312 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1311, 2);to = ____BAH_COMPILER_VAR_1312;
}
char** ____BAH_COMPILER_VAR_1313 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_1313[6] = ")";____BAH_COMPILER_VAR_1313[5] = to;____BAH_COMPILER_VAR_1313[4] = ", ";____BAH_COMPILER_VAR_1313[3] = from;____BAH_COMPILER_VAR_1313[2] = ", ";____BAH_COMPILER_VAR_1313[1] = pt.cont;____BAH_COMPILER_VAR_1313[0] = "arraySubstitute(";char * ____BAH_COMPILER_VAR_1314 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1313, 7);t.cont = ____BAH_COMPILER_VAR_1314;
}
}
else if (string__hasPrefix(&ptt,"buffer:")) {
if ((split==false)) {
t.bahType = "char";
struct Tok index = memory->data[0];
char * ____BAH_COMPILER_VAR_1315 =getTypeFromToken(&index,true,elems);if (__builtin_expect((compTypes(____BAH_COMPILER_VAR_1315,"int")==false), 0)) {
throwErr(&index,"Cannot use {TOKEN} as buffer index (int).");
}
char** ____BAH_COMPILER_VAR_1316 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1316[3] = "]";____BAH_COMPILER_VAR_1316[2] = index.cont;____BAH_COMPILER_VAR_1316[1] = "[";____BAH_COMPILER_VAR_1316[0] = pt.cont;char * ____BAH_COMPILER_VAR_1317 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1316, 4);t.cont = ____BAH_COMPILER_VAR_1317;
}
else {
t.bahType = "cpstring";
if ((strcmp(to, "") == 0)) {
char** ____BAH_COMPILER_VAR_1318 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1318[2] = ")";____BAH_COMPILER_VAR_1318[1] = pt.cont;____BAH_COMPILER_VAR_1318[0] = "strlen(";char * ____BAH_COMPILER_VAR_1319 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1318, 3);to = ____BAH_COMPILER_VAR_1319;
}
char** ____BAH_COMPILER_VAR_1320 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_1320[6] = ")";____BAH_COMPILER_VAR_1320[5] = to;____BAH_COMPILER_VAR_1320[4] = ", ";____BAH_COMPILER_VAR_1320[3] = from;____BAH_COMPILER_VAR_1320[2] = ", ";____BAH_COMPILER_VAR_1320[1] = pt.cont;____BAH_COMPILER_VAR_1320[0] = "cpstringSubsitute(";char * ____BAH_COMPILER_VAR_1321 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1320, 7);t.cont = ____BAH_COMPILER_VAR_1321;
}
}
else if (string__hasPrefix(&ptt,"map:")) {
if (__builtin_expect((split==true), 0)) {
throwErr(&pt,"Cannot do substitution on a map {TOKEN}.");
}
string__trimLeft(&ptt,4);
char * ____BAH_COMPILER_VAR_1322 =string__str(&ptt);struct string elemType = getCType(____BAH_COMPILER_VAR_1322,elems);
struct Tok index = memory->data[0];
char * ____BAH_COMPILER_VAR_1323 =getTypeFromToken(&index,true,elems);if (__builtin_expect((compTypes(____BAH_COMPILER_VAR_1323,"cpstring")==false), 0)) {
throwErr(&index,"Cannot use {TOKEN} as map index (cpstring).");
}
if ((tokPos==0)&&(ltp==LINE_TYPE_VAR)) {
struct variable* ____BAH_COMPILER_VAR_1324 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1324->name = "";
____BAH_COMPILER_VAR_1324->type = "";
____BAH_COMPILER_VAR_1324->constVal = "";
____BAH_COMPILER_VAR_1324->from = "";
____BAH_COMPILER_VAR_1324->name = genCompilerVar();
____BAH_COMPILER_VAR_1324->type = string__str(&ptt);
struct variable* tmpV = ____BAH_COMPILER_VAR_1324;

    unsigned int ____BAH_COMPILER_VAR_1325 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_1325);
    elems->vars->data[____BAH_COMPILER_VAR_1325] = tmpV;
if (isGlobal()) {
char** ____BAH_COMPILER_VAR_1326 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1326[3] = ";\n";____BAH_COMPILER_VAR_1326[2] = tmpV->name;____BAH_COMPILER_VAR_1326[1] = " ";____BAH_COMPILER_VAR_1326[0] = string__str(&elemType);char * ____BAH_COMPILER_VAR_1327 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1326, 4);INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_1327));
}
else {
char** ____BAH_COMPILER_VAR_1328 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1328[3] = ";\n";____BAH_COMPILER_VAR_1328[2] = tmpV->name;____BAH_COMPILER_VAR_1328[1] = " ";____BAH_COMPILER_VAR_1328[0] = string__str(&elemType);char * ____BAH_COMPILER_VAR_1329 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1328, 4);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1329));
}
char * ____BAH_COMPILER_VAR_1330 =string__str(&ptt);if (isRCPpointerType(____BAH_COMPILER_VAR_1330)) {
char** ____BAH_COMPILER_VAR_1331 = alloca(8 * sizeof(char*));____BAH_COMPILER_VAR_1331[7] = ");\n";____BAH_COMPILER_VAR_1331[6] = tmpV->name;____BAH_COMPILER_VAR_1331[5] = ", ";____BAH_COMPILER_VAR_1331[4] = index.cont;____BAH_COMPILER_VAR_1331[3] = ", ";____BAH_COMPILER_VAR_1331[2] = pt.cont;____BAH_COMPILER_VAR_1331[1] = "->set(";____BAH_COMPILER_VAR_1331[0] = pt.cont;char * ____BAH_COMPILER_VAR_1332 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1331, 8);NEXT_LINE = ____BAH_COMPILER_VAR_1332;
}
else {
char** ____BAH_COMPILER_VAR_1333 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_1333[8] = "));\n";____BAH_COMPILER_VAR_1333[7] = string__str(&elemType);____BAH_COMPILER_VAR_1333[6] = ", sizeof(";____BAH_COMPILER_VAR_1333[5] = tmpV->name;____BAH_COMPILER_VAR_1333[4] = ", &";____BAH_COMPILER_VAR_1333[3] = index.cont;____BAH_COMPILER_VAR_1333[2] = ", ";____BAH_COMPILER_VAR_1333[1] = pt.cont;____BAH_COMPILER_VAR_1333[0] = "mapWrapper__setAny(";char * ____BAH_COMPILER_VAR_1334 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1333, 9);NEXT_LINE = ____BAH_COMPILER_VAR_1334;
}
t.cont = tmpV->name;
t.bahType = string__str(&ptt);
}
else {
t.isFunc = true;
struct rope* res= null;
char * tmpV = genCompilerVar();
char * ____BAH_COMPILER_VAR_1335 =string__str(&ptt);if (isRCPpointerType(____BAH_COMPILER_VAR_1335)) {
char** ____BAH_COMPILER_VAR_1336 = alloca(10 * sizeof(char*));____BAH_COMPILER_VAR_1336[9] = ");\n";____BAH_COMPILER_VAR_1336[8] = index.cont;____BAH_COMPILER_VAR_1336[7] = ", ";____BAH_COMPILER_VAR_1336[6] = t.cont;____BAH_COMPILER_VAR_1336[5] = "->get(";____BAH_COMPILER_VAR_1336[4] = t.cont;____BAH_COMPILER_VAR_1336[3] = "=";____BAH_COMPILER_VAR_1336[2] = tmpV;____BAH_COMPILER_VAR_1336[1] = " ";____BAH_COMPILER_VAR_1336[0] = string__str(&elemType);char * ____BAH_COMPILER_VAR_1337 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1336, 10);res = rope(____BAH_COMPILER_VAR_1337);
t.cont = tmpV;
}
else {
char** ____BAH_COMPILER_VAR_1338 = alloca(10 * sizeof(char*));____BAH_COMPILER_VAR_1338[9] = ");\n";____BAH_COMPILER_VAR_1338[8] = index.cont;____BAH_COMPILER_VAR_1338[7] = ", ";____BAH_COMPILER_VAR_1338[6] = pt.cont;____BAH_COMPILER_VAR_1338[5] = "->get(";____BAH_COMPILER_VAR_1338[4] = pt.cont;____BAH_COMPILER_VAR_1338[3] = "=";____BAH_COMPILER_VAR_1338[2] = tmpV;____BAH_COMPILER_VAR_1338[1] = "* ";____BAH_COMPILER_VAR_1338[0] = string__str(&elemType);char * ____BAH_COMPILER_VAR_1339 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1338, 10);res = rope(____BAH_COMPILER_VAR_1339);
char** ____BAH_COMPILER_VAR_1340 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1340[4] = ")";____BAH_COMPILER_VAR_1340[3] = tmpV;____BAH_COMPILER_VAR_1340[2] = ")(*";____BAH_COMPILER_VAR_1340[1] = string__str(&elemType);____BAH_COMPILER_VAR_1340[0] = "(";char * ____BAH_COMPILER_VAR_1341 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1340, 5);t.cont = ____BAH_COMPILER_VAR_1341;
}
if (RCPavailable()) {
struct variable* ____BAH_COMPILER_VAR_1342 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1342->name = "";
____BAH_COMPILER_VAR_1342->type = "";
____BAH_COMPILER_VAR_1342->constVal = "";
____BAH_COMPILER_VAR_1342->from = "";
____BAH_COMPILER_VAR_1342->name = tmpV;
____BAH_COMPILER_VAR_1342->type = string__str(&ptt);

    unsigned int ____BAH_COMPILER_VAR_1343 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_1343);
    elems->vars->data[____BAH_COMPILER_VAR_1343] = ____BAH_COMPILER_VAR_1342;
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
char * ____BAH_COMPILER_VAR_1344 =getTypeFromToken(&index,true,elems);if (__builtin_expect((compTypes(____BAH_COMPILER_VAR_1344,"int")==false), 0)) {
throwErr(&index,"Cannot use {TOKEN} as cpstring index (int).");
}
char** ____BAH_COMPILER_VAR_1345 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1345[3] = "]";____BAH_COMPILER_VAR_1345[2] = index.cont;____BAH_COMPILER_VAR_1345[1] = "[";____BAH_COMPILER_VAR_1345[0] = pt.cont;char * ____BAH_COMPILER_VAR_1346 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1345, 4);t.cont = ____BAH_COMPILER_VAR_1346;
}
else {
if ((strcmp(to, "") == 0)) {
char** ____BAH_COMPILER_VAR_1347 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1347[2] = ")";____BAH_COMPILER_VAR_1347[1] = pt.cont;____BAH_COMPILER_VAR_1347[0] = "strlen(";char * ____BAH_COMPILER_VAR_1348 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1347, 3);to = ____BAH_COMPILER_VAR_1348;
}
char** ____BAH_COMPILER_VAR_1349 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_1349[6] = ")";____BAH_COMPILER_VAR_1349[5] = to;____BAH_COMPILER_VAR_1349[4] = ", ";____BAH_COMPILER_VAR_1349[3] = from;____BAH_COMPILER_VAR_1349[2] = ", ";____BAH_COMPILER_VAR_1349[1] = pt.cont;____BAH_COMPILER_VAR_1349[0] = "cpstringSubsitute(";char * ____BAH_COMPILER_VAR_1350 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1349, 7);t.cont = ____BAH_COMPILER_VAR_1350;
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
char * ____BAH_COMPILER_VAR_1351 =string__str(&parts->data[1]);if (__builtin_expect((ind>=strToInt(____BAH_COMPILER_VAR_1351)), 0)) {
char** ____BAH_COMPILER_VAR_1352 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1352[4] = ".";____BAH_COMPILER_VAR_1352[3] = string__str(&parts->data[1]);____BAH_COMPILER_VAR_1352[2] = " of length ";____BAH_COMPILER_VAR_1352[1] = pt.cont;____BAH_COMPILER_VAR_1352[0] = "Cannot access index {TOKEN} of tupple ";char * ____BAH_COMPILER_VAR_1353 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1352, 5);throwErr(&index,____BAH_COMPILER_VAR_1353);
}
}
else {
char * ____BAH_COMPILER_VAR_1354 =getTypeFromToken(&index,true,elems);if (__builtin_expect((compTypes(____BAH_COMPILER_VAR_1354,"int")==false), 0)) {
throwErr(&index,"Cannot use {TOKEN} as tuple index (int).");
}
}
char** ____BAH_COMPILER_VAR_1355 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1355[3] = "]";____BAH_COMPILER_VAR_1355[2] = index.cont;____BAH_COMPILER_VAR_1355[1] = "[";____BAH_COMPILER_VAR_1355[0] = pt.cont;char * ____BAH_COMPILER_VAR_1356 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1355, 4);t.cont = ____BAH_COMPILER_VAR_1356;
t.bahType = string__str(&parts->data[2]);
}
else {
char** ____BAH_COMPILER_VAR_1357 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1357[2] = ") as array.";____BAH_COMPILER_VAR_1357[1] = string__str(&ptt);____BAH_COMPILER_VAR_1357[0] = "Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_1358 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1357, 3);throwErr(&pt,____BAH_COMPILER_VAR_1358);
}
t.isValue = true;

    unsigned int ____BAH_COMPILER_VAR_1359 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1359);
    l->data[____BAH_COMPILER_VAR_1359] = t;
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
char** ____BAH_COMPILER_VAR_1360 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1360[1] = odecl;____BAH_COMPILER_VAR_1360[0] = "register ";char * ____BAH_COMPILER_VAR_1361 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1360, 2);OUTPUT->totalLen = OUTPUT->totalLen+ropeSet(v->declRope,____BAH_COMPILER_VAR_1361);
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
char** ____BAH_COMPILER_VAR_1362 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1362[2] = ") as array.";____BAH_COMPILER_VAR_1362[1] = ntt;____BAH_COMPILER_VAR_1362[0] = "Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_1363 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1362, 3);throwErr(&nt,____BAH_COMPILER_VAR_1363);
}
string__trimLeft(&arrT,2);
char * ____BAH_COMPILER_VAR_1364 =string__str(&arrT);if (__builtin_expect((compTypes(ptt,____BAH_COMPILER_VAR_1364)==false), 0)) {
char** ____BAH_COMPILER_VAR_1365 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1365[4] = ".";____BAH_COMPILER_VAR_1365[3] = ntt;____BAH_COMPILER_VAR_1365[2] = ") in ";____BAH_COMPILER_VAR_1365[1] = ptt;____BAH_COMPILER_VAR_1365[0] = "Cannot search for {TOKEN} (";char * ____BAH_COMPILER_VAR_1366 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1365, 5);throwErr(&pt,____BAH_COMPILER_VAR_1366);
}
char * compVar = genCompilerVar();
char * comp = "";
pt.cont = registerRCPvar(ptt,pt.cont,elems);
if ((strcmp(ptt, "cpstring") == 0)) {
char** ____BAH_COMPILER_VAR_1367 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_1367[5] = ") == 0";____BAH_COMPILER_VAR_1367[4] = pt.cont;____BAH_COMPILER_VAR_1367[3] = "->data[i], ";____BAH_COMPILER_VAR_1367[2] = nt.cont;____BAH_COMPILER_VAR_1367[1] = "->data[i] != 0 && strcmp(";____BAH_COMPILER_VAR_1367[0] = nt.cont;char * ____BAH_COMPILER_VAR_1368 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1367, 6);comp = ____BAH_COMPILER_VAR_1368;
}
else {
char** ____BAH_COMPILER_VAR_1369 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1369[2] = pt.cont;____BAH_COMPILER_VAR_1369[1] = "->data[i] == ";____BAH_COMPILER_VAR_1369[0] = nt.cont;char * ____BAH_COMPILER_VAR_1370 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1369, 3);comp = ____BAH_COMPILER_VAR_1370;
}
char** ____BAH_COMPILER_VAR_1371 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_1371[8] = "=1;\n                break;\n            };\n        }\n        ";____BAH_COMPILER_VAR_1371[7] = compVar;____BAH_COMPILER_VAR_1371[6] = ") {\n                ";____BAH_COMPILER_VAR_1371[5] = comp;____BAH_COMPILER_VAR_1371[4] = "->length-1; i!=-1;i--) {\n            if (";____BAH_COMPILER_VAR_1371[3] = nt.cont;____BAH_COMPILER_VAR_1371[2] = " = 0;\n        for(int i=";____BAH_COMPILER_VAR_1371[1] = compVar;____BAH_COMPILER_VAR_1371[0] = "\n        char ";char * ____BAH_COMPILER_VAR_1372 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1371, 9);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1372));
pt.isExpensive = true;
pt.cont = compVar;
}
else {
if (__builtin_expect((compTypes(ptt,ntt)==false), 0)) {
char** ____BAH_COMPILER_VAR_1373 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1373[4] = ".";____BAH_COMPILER_VAR_1373[3] = ptt;____BAH_COMPILER_VAR_1373[2] = ") with type ";____BAH_COMPILER_VAR_1373[1] = ntt;____BAH_COMPILER_VAR_1373[0] = "Cannot compare {TOKEN} (";char * ____BAH_COMPILER_VAR_1374 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1373, 5);throwErr(&nt,____BAH_COMPILER_VAR_1374);
}
if ((strcmp(ptt, "cpstring") == 0)) {
if ((strcmp(t.cont, "==") == 0)) {
char** ____BAH_COMPILER_VAR_1375 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1375[4] = ") == 0)";____BAH_COMPILER_VAR_1375[3] = nt.cont;____BAH_COMPILER_VAR_1375[2] = ", ";____BAH_COMPILER_VAR_1375[1] = pt.cont;____BAH_COMPILER_VAR_1375[0] = "(strcmp(";char * ____BAH_COMPILER_VAR_1376 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1375, 5);pt.cont = ____BAH_COMPILER_VAR_1376;
}
else if ((strcmp(t.cont, "!=") == 0)) {
char** ____BAH_COMPILER_VAR_1377 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1377[4] = ") != 0)";____BAH_COMPILER_VAR_1377[3] = nt.cont;____BAH_COMPILER_VAR_1377[2] = ", ";____BAH_COMPILER_VAR_1377[1] = pt.cont;____BAH_COMPILER_VAR_1377[0] = "(strcmp(";char * ____BAH_COMPILER_VAR_1378 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1377, 5);pt.cont = ____BAH_COMPILER_VAR_1378;
}
else if ((strcmp(t.cont, ">") == 0)) {
char** ____BAH_COMPILER_VAR_1379 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1379[4] = "))";____BAH_COMPILER_VAR_1379[3] = nt.cont;____BAH_COMPILER_VAR_1379[2] = ") > srtlen(";____BAH_COMPILER_VAR_1379[1] = pt.cont;____BAH_COMPILER_VAR_1379[0] = "(strlen(";char * ____BAH_COMPILER_VAR_1380 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1379, 5);pt.cont = ____BAH_COMPILER_VAR_1380;
}
else if ((strcmp(t.cont, "<") == 0)) {
char** ____BAH_COMPILER_VAR_1381 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1381[4] = "))";____BAH_COMPILER_VAR_1381[3] = nt.cont;____BAH_COMPILER_VAR_1381[2] = ") < srtlen(";____BAH_COMPILER_VAR_1381[1] = pt.cont;____BAH_COMPILER_VAR_1381[0] = "(strlen(";char * ____BAH_COMPILER_VAR_1382 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1381, 5);pt.cont = ____BAH_COMPILER_VAR_1382;
}
else if ((strcmp(t.cont, ">=") == 0)) {
char** ____BAH_COMPILER_VAR_1383 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1383[4] = "))";____BAH_COMPILER_VAR_1383[3] = nt.cont;____BAH_COMPILER_VAR_1383[2] = ") >= srtlen(";____BAH_COMPILER_VAR_1383[1] = pt.cont;____BAH_COMPILER_VAR_1383[0] = "(strlen(";char * ____BAH_COMPILER_VAR_1384 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1383, 5);pt.cont = ____BAH_COMPILER_VAR_1384;
}
else if ((strcmp(t.cont, "<=") == 0)) {
char** ____BAH_COMPILER_VAR_1385 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1385[4] = "))";____BAH_COMPILER_VAR_1385[3] = nt.cont;____BAH_COMPILER_VAR_1385[2] = ") <= srtlen(";____BAH_COMPILER_VAR_1385[1] = pt.cont;____BAH_COMPILER_VAR_1385[0] = "(strlen(";char * ____BAH_COMPILER_VAR_1386 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1385, 5);pt.cont = ____BAH_COMPILER_VAR_1386;
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
struct varCheck ____BAH_COMPILER_VAR_1387 = {};
____BAH_COMPILER_VAR_1387.v = ptV;
____BAH_COMPILER_VAR_1387.checkNull = ntIsNull;

    unsigned int ____BAH_COMPILER_VAR_1388 = len(currChecks);
    __Bah_realocate_arr(currChecks, ____BAH_COMPILER_VAR_1388);
    currChecks->data[____BAH_COMPILER_VAR_1388] = ____BAH_COMPILER_VAR_1387;
}
else if ((strcmp(t.cont, "!=") == 0)) {
struct varCheck ____BAH_COMPILER_VAR_1389 = {};
____BAH_COMPILER_VAR_1389.v = ptV;
____BAH_COMPILER_VAR_1389.checkNull = (ntIsNull==false);

    unsigned int ____BAH_COMPILER_VAR_1390 = len(currChecks);
    __Bah_realocate_arr(currChecks, ____BAH_COMPILER_VAR_1390);
    currChecks->data[____BAH_COMPILER_VAR_1390] = ____BAH_COMPILER_VAR_1389;
}
}
}
if (isExprExpensive(&pt)||isExprExpensive(&nt)) {
pt.isExpensive = true;
}
else {
pt.isExpensive = false;
}
char** ____BAH_COMPILER_VAR_1391 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1391[4] = ")";____BAH_COMPILER_VAR_1391[3] = nt.cont;____BAH_COMPILER_VAR_1391[2] = t.cont;____BAH_COMPILER_VAR_1391[1] = pt.cont;____BAH_COMPILER_VAR_1391[0] = "(";char * ____BAH_COMPILER_VAR_1392 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1391, 5);pt.cont = ____BAH_COMPILER_VAR_1392;
}
}
pt.isOper = true;
pt.bahType = "bool";
pt.isValue = true;

    unsigned int ____BAH_COMPILER_VAR_1393 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1393);
    l->data[____BAH_COMPILER_VAR_1393] = pt;
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
char** ____BAH_COMPILER_VAR_1394 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1394[2] = pt.cont;____BAH_COMPILER_VAR_1394[1] = t.cont;____BAH_COMPILER_VAR_1394[0] = t.cont;char * ____BAH_COMPILER_VAR_1395 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1394, 3);pt.cont = ____BAH_COMPILER_VAR_1395;

    unsigned int ____BAH_COMPILER_VAR_1396 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1396);
    l->data[____BAH_COMPILER_VAR_1396] = pt;
return tokPos;
}
char * ntt = getTypeFromToken(&nt,true,elems);
if (__builtin_expect((compTypes(ptt,ntt)==false), 0)) {
char** ____BAH_COMPILER_VAR_1397 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1397[4] = ".";____BAH_COMPILER_VAR_1397[3] = ptt;____BAH_COMPILER_VAR_1397[2] = ") as ";____BAH_COMPILER_VAR_1397[1] = ntt;____BAH_COMPILER_VAR_1397[0] = "Cannot compare {TOKEN} (";char * ____BAH_COMPILER_VAR_1398 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1397, 5);throwErr(&nt,____BAH_COMPILER_VAR_1398);
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
char** ____BAH_COMPILER_VAR_1399 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1399[2] = ").";____BAH_COMPILER_VAR_1399[1] = tt;____BAH_COMPILER_VAR_1399[0] = "Cannot concatenate cpstring with {TOKEN} (";char * ____BAH_COMPILER_VAR_1400 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1399, 3);throwErr(&currStrTk,____BAH_COMPILER_VAR_1400);
}

    unsigned int ____BAH_COMPILER_VAR_1401 = len(strs);
    __Bah_realocate_arr(strs, ____BAH_COMPILER_VAR_1401);
    strs->data[____BAH_COMPILER_VAR_1401] = currStrTk.cont;
if ((i-1>=0)) {
--i;
t = l->data[i];
if ((strcmp(t.cont, "+") != 0)) {
char * ____BAH_COMPILER_VAR_1403 =t.cont;
        char ____BAH_COMPILER_VAR_1402 = 0;
        for(int i=signs->length-1; i!=-1;i--) {
            if (signs->data[i] != 0 && strcmp(signs->data[i], ____BAH_COMPILER_VAR_1403) == 0) {
                ____BAH_COMPILER_VAR_1402=1;
                break;
            };
        }
        if (__builtin_expect(____BAH_COMPILER_VAR_1402, 0)) {
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
char** ____BAH_COMPILER_VAR_1404 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1404[2] = ").";____BAH_COMPILER_VAR_1404[1] = ptt;____BAH_COMPILER_VAR_1404[0] = "Undefined operation on struct {TOKEN} (";char * ____BAH_COMPILER_VAR_1405 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1404, 3);throwErr(&pt,____BAH_COMPILER_VAR_1405);
}
struct structMemb* methd = searchStructMemb(mName,s,elems);
if ((methd!=null)&&(methd->isFn==true)) {
if (RCPavailable()) {
char** ____BAH_COMPILER_VAR_1406 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_1406[8] = ")";____BAH_COMPILER_VAR_1406[7] = nt.cont;____BAH_COMPILER_VAR_1406[6] = ", ";____BAH_COMPILER_VAR_1406[5] = pt.cont;____BAH_COMPILER_VAR_1406[4] = amp;____BAH_COMPILER_VAR_1406[3] = "(";____BAH_COMPILER_VAR_1406[2] = mName;____BAH_COMPILER_VAR_1406[1] = "__";____BAH_COMPILER_VAR_1406[0] = s->name;char * ____BAH_COMPILER_VAR_1407 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1406, 9);pt.cont = registerRCPvar(ptt,____BAH_COMPILER_VAR_1407,elems);
pt.type = TOKEN_TYPE_VAR;
pt.isFunc = false;
pt.isOper = false;
}
else {
char** ____BAH_COMPILER_VAR_1408 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_1408[8] = ")";____BAH_COMPILER_VAR_1408[7] = nt.cont;____BAH_COMPILER_VAR_1408[6] = ", ";____BAH_COMPILER_VAR_1408[5] = pt.cont;____BAH_COMPILER_VAR_1408[4] = amp;____BAH_COMPILER_VAR_1408[3] = "(";____BAH_COMPILER_VAR_1408[2] = mName;____BAH_COMPILER_VAR_1408[1] = "__";____BAH_COMPILER_VAR_1408[0] = s->name;char * ____BAH_COMPILER_VAR_1409 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1408, 9);pt.cont = ____BAH_COMPILER_VAR_1409;
pt.isFunc = true;
}
}
}
else {
char** ____BAH_COMPILER_VAR_1410 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1410[1] = nt.cont;____BAH_COMPILER_VAR_1410[0] = t.cont;char * ____BAH_COMPILER_VAR_1411 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1410, 2);char** ____BAH_COMPILER_VAR_1412 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1412[1] = ____BAH_COMPILER_VAR_1411;____BAH_COMPILER_VAR_1412[0] = pt.cont;char * ____BAH_COMPILER_VAR_1413 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1412, 2);pt.cont = ____BAH_COMPILER_VAR_1413;
}
pt.isOper = true;
}
pt.isNotExpsvOper = false;

    unsigned int ____BAH_COMPILER_VAR_1414 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1414);
    l->data[____BAH_COMPILER_VAR_1414] = pt;
return tokPos;
};
long int valueSendChan(__BAH_ARR_TYPE_Tok l,long int i,struct Elems* elems){
long int posTok = i-2;
struct Tok nt = l->data[posTok];
struct Tok pt = l->data[posTok+2];
deleteRange(l,posTok,posTok+2);
char * ntt = getTypeFromToken(&nt,true,elems);
char * ____BAH_COMPILER_VAR_1415 =getTypeFromToken(&pt,true,elems);struct string ptt = string(____BAH_COMPILER_VAR_1415);
if (__builtin_expect((string__hasPrefix(&ptt,"chan:")==0), 0)) {
char** ____BAH_COMPILER_VAR_1416 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1416[2] = ") as chan.";____BAH_COMPILER_VAR_1416[1] = string__str(&ptt);____BAH_COMPILER_VAR_1416[0] = "Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_1417 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1416, 3);throwErr(&pt,____BAH_COMPILER_VAR_1417);
}
string__trimLeft(&ptt,5);
if (__builtin_expect(isGlobal(), 0)) {
throwErr(&pt,"Cannot send to channel {TOKEN} of a function.");
}
char * ____BAH_COMPILER_VAR_1418 =string__str(&ptt);if (__builtin_expect((compTypes(ntt,____BAH_COMPILER_VAR_1418)==false), 0)) {
char** ____BAH_COMPILER_VAR_1419 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1419[4] = ".";____BAH_COMPILER_VAR_1419[3] = string__str(&ptt);____BAH_COMPILER_VAR_1419[2] = ") through chan:";____BAH_COMPILER_VAR_1419[1] = ntt;____BAH_COMPILER_VAR_1419[0] = "Cannot send {TOKEN} (";char * ____BAH_COMPILER_VAR_1420 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1419, 5);throwErr(&nt,____BAH_COMPILER_VAR_1420);
}
char * ____BAH_COMPILER_VAR_1421 =string__str(&ptt);if (isRCPpointerType(____BAH_COMPILER_VAR_1421)) {
char** ____BAH_COMPILER_VAR_1422 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1422[4] = ");\n";____BAH_COMPILER_VAR_1422[3] = nt.cont;____BAH_COMPILER_VAR_1422[2] = ", ";____BAH_COMPILER_VAR_1422[1] = pt.cont;____BAH_COMPILER_VAR_1422[0] = "channel__send(";char * ____BAH_COMPILER_VAR_1423 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1422, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1423));
}
else {
struct string ct = getCType(ntt,elems);
char * tmpV = genCompilerVar();
char** ____BAH_COMPILER_VAR_1424 = alloca(13 * sizeof(char*));____BAH_COMPILER_VAR_1424[12] = "));\n        ";____BAH_COMPILER_VAR_1424[11] = tmpV;____BAH_COMPILER_VAR_1424[10] = ", sizeof(";____BAH_COMPILER_VAR_1424[9] = tmpV;____BAH_COMPILER_VAR_1424[8] = ", &";____BAH_COMPILER_VAR_1424[7] = pt.cont;____BAH_COMPILER_VAR_1424[6] = ";\n        channel__sendAny(";____BAH_COMPILER_VAR_1424[5] = nt.cont;____BAH_COMPILER_VAR_1424[4] = " = ";____BAH_COMPILER_VAR_1424[3] = tmpV;____BAH_COMPILER_VAR_1424[2] = " ";____BAH_COMPILER_VAR_1424[1] = string__str(&ct);____BAH_COMPILER_VAR_1424[0] = "\n        ";char * ____BAH_COMPILER_VAR_1425 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1424, 13);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1425));
}
return posTok;
};
long int valueChan(__BAH_ARR_TYPE_Tok l,long int i,struct Elems* elems){
long int posTok = i-1;
delete(l,posTok);
struct Tok nt = l->data[posTok];
char * ____BAH_COMPILER_VAR_1426 =getTypeFromToken(&nt,true,elems);struct string ntt = string(____BAH_COMPILER_VAR_1426);
if (__builtin_expect((string__hasPrefix(&ntt,"chan:")==0), 0)) {
char** ____BAH_COMPILER_VAR_1427 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1427[2] = ") as chan.";____BAH_COMPILER_VAR_1427[1] = string__str(&ntt);____BAH_COMPILER_VAR_1427[0] = "Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_1428 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1427, 3);throwErr(&nt,____BAH_COMPILER_VAR_1428);
}
string__trimLeft(&ntt,5);
if (__builtin_expect(isGlobal(), 0)) {
throwErr(&nt,"Cannot receive from chan {TOKEN} outside a function body.");
}
char * ____BAH_COMPILER_VAR_1429 =string__str(&ntt);struct string ct = getCType(____BAH_COMPILER_VAR_1429,elems);
char * ____BAH_COMPILER_VAR_1430 =string__str(&ntt);if (isRCPpointerType(____BAH_COMPILER_VAR_1430)) {
char** ____BAH_COMPILER_VAR_1431 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1431[2] = ")";____BAH_COMPILER_VAR_1431[1] = nt.cont;____BAH_COMPILER_VAR_1431[0] = "channel__receive(";char * ____BAH_COMPILER_VAR_1432 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1431, 3);char * ____BAH_COMPILER_VAR_1433 =string__str(&ntt);char * tmpV = registerRCPvar(____BAH_COMPILER_VAR_1433,____BAH_COMPILER_VAR_1432,elems);
nt.cont = tmpV;
}
else {
if (RCPavailable()) {
char** ____BAH_COMPILER_VAR_1434 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1434[1] = "*";____BAH_COMPILER_VAR_1434[0] = string__str(&ntt);char * ____BAH_COMPILER_VAR_1435 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1434, 2);char** ____BAH_COMPILER_VAR_1436 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1436[4] = ")";____BAH_COMPILER_VAR_1436[3] = nt.cont;____BAH_COMPILER_VAR_1436[2] = "*)channel__receive(";____BAH_COMPILER_VAR_1436[1] = string__str(&ct);____BAH_COMPILER_VAR_1436[0] = "(";char * ____BAH_COMPILER_VAR_1437 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1436, 5);char * tmpV = registerRCPvar(____BAH_COMPILER_VAR_1435,____BAH_COMPILER_VAR_1437,elems);
char** ____BAH_COMPILER_VAR_1438 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1438[1] = tmpV;____BAH_COMPILER_VAR_1438[0] = "*";char * ____BAH_COMPILER_VAR_1439 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1438, 2);nt.cont = ____BAH_COMPILER_VAR_1439;
}
else {
char** ____BAH_COMPILER_VAR_1440 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1440[4] = ")";____BAH_COMPILER_VAR_1440[3] = nt.cont;____BAH_COMPILER_VAR_1440[2] = "*)channel__receive(";____BAH_COMPILER_VAR_1440[1] = string__str(&ct);____BAH_COMPILER_VAR_1440[0] = "*(";char * ____BAH_COMPILER_VAR_1441 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1440, 5);nt.cont = ____BAH_COMPILER_VAR_1441;
}
}
nt.type = TOKEN_TYPE_FUNC;
nt.isFunc = true;
nt.isValue = true;
nt.bahType = string__str(&ntt);

    unsigned int ____BAH_COMPILER_VAR_1442 = posTok;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1442);
    l->data[____BAH_COMPILER_VAR_1442] = nt;
return posTok;
};
long int valueTuple(__BAH_ARR_TYPE_Tok l,long int i,struct Elems* elems){
long int tokPos = i;
long int nbBracks = 0;
if (__builtin_expect((strcmp(l->data[tokPos+1].cont, "]") == 0), 0)) {
long int offset = 1;
while ((strcmp(l->data[tokPos+offset+1].cont, "[") == 0)&&(strcmp(l->data[tokPos+offset+2].cont, "]") == 0)) {
offset = offset+2;
};
if ((l->data[tokPos+offset+1].type==TOKEN_TYPE_VAR)) {
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
memory = prePross(memory,(lineType)-1,elems);
struct Tok ft = memory->data[0];
char * tupT = getTypeFromToken(&ft,true,elems);
register long int j = 0;
for (; (j<len(memory)); j = j+2) {
struct Tok t = memory->data[j];
char * tt = getTypeFromToken(&t,true,elems);
if (__builtin_expect((compTypes(tupT,tt)==false), 0)) {
char** ____BAH_COMPILER_VAR_1443 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1443[4] = " in tuple declaration.";____BAH_COMPILER_VAR_1443[3] = tupT;____BAH_COMPILER_VAR_1443[2] = ") as ";____BAH_COMPILER_VAR_1443[1] = tt;____BAH_COMPILER_VAR_1443[0] = "Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_1444 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1443, 5);throwErr(&t,____BAH_COMPILER_VAR_1444);
}

    unsigned int ____BAH_COMPILER_VAR_1445 = len(vals);
    __Bah_realocate_arr(vals, ____BAH_COMPILER_VAR_1445);
    vals->data[____BAH_COMPILER_VAR_1445] = t.cont;
struct Tok nt = memory->data[j+1];
if ((strcmp(nt.cont, "]") == 0)) {
break;
}
else if (__builtin_expect((strcmp(nt.cont, ",") != 0), 0)) {
throwErr(&nt,"Expected separator between values in tuple declaration, got {TOKEN}.");
}
};
char** ____BAH_COMPILER_VAR_1446 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1446[3] = tupT;____BAH_COMPILER_VAR_1446[2] = ":";____BAH_COMPILER_VAR_1446[1] = intToStr(len(vals));____BAH_COMPILER_VAR_1446[0] = "tuple:";char * ____BAH_COMPILER_VAR_1447 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1446, 4);char * type = ____BAH_COMPILER_VAR_1447;
deleteRange(l,tokPos+1,j+1);

                struct string ____BAH_COMPILER_VAR_1448 = getCType(tupT,elems);
                char** ____BAH_COMPILER_VAR_1449 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1449[4] = ")";____BAH_COMPILER_VAR_1449[3] = intToStr(len(vals));____BAH_COMPILER_VAR_1449[2] = ") * ";____BAH_COMPILER_VAR_1449[1] = string__str(&____BAH_COMPILER_VAR_1448);____BAH_COMPILER_VAR_1449[0] = "alloca(sizeof(";char * ____BAH_COMPILER_VAR_1450 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1449, 5);char * v = registerRCPvar(type,____BAH_COMPILER_VAR_1450,elems);
char * r = "";
i = 0;
for (; (i<len(vals)); ++i) {
char** ____BAH_COMPILER_VAR_1451 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_1451[5] = ";";____BAH_COMPILER_VAR_1451[4] = vals->data[i];____BAH_COMPILER_VAR_1451[3] = "] = ";____BAH_COMPILER_VAR_1451[2] = intToStr(i);____BAH_COMPILER_VAR_1451[1] = "[";____BAH_COMPILER_VAR_1451[0] = v;char * ____BAH_COMPILER_VAR_1452 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1451, 6);char** ____BAH_COMPILER_VAR_1453 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1453[1] = ____BAH_COMPILER_VAR_1452;____BAH_COMPILER_VAR_1453[0] = r;char * ____BAH_COMPILER_VAR_1454 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1453, 2);r = ____BAH_COMPILER_VAR_1454;
};
if (isGlobal()) {
INIT = rope__add(INIT, rope(r));
}
else {
OUTPUT = rope__add(OUTPUT, rope(r));
}
struct Tok ____BAH_COMPILER_VAR_1455 = {};
____BAH_COMPILER_VAR_1455.cont = "";
____BAH_COMPILER_VAR_1455.ogCont = "";
____BAH_COMPILER_VAR_1455.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1455.line = 1;
____BAH_COMPILER_VAR_1455.begLine = 1;
____BAH_COMPILER_VAR_1455.bahType = "";
____BAH_COMPILER_VAR_1455.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_1455.bahType = type;
____BAH_COMPILER_VAR_1455.cont = v;

    unsigned int ____BAH_COMPILER_VAR_1456 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1456);
    l->data[____BAH_COMPILER_VAR_1456] = ____BAH_COMPILER_VAR_1455;
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
struct Tok ____BAH_COMPILER_VAR_1457 = {};
____BAH_COMPILER_VAR_1457.cont = "";
____BAH_COMPILER_VAR_1457.ogCont = "";
____BAH_COMPILER_VAR_1457.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1457.line = 1;
____BAH_COMPILER_VAR_1457.begLine = 1;
____BAH_COMPILER_VAR_1457.bahType = "";
struct Tok pt = ____BAH_COMPILER_VAR_1457;
long int l = len(fl);
i = 0;
for (; (i<len(fl)); ++i) {
struct Tok t = fl->data[i];
if ((t.type==TOKEN_TYPE_VAR)&&(t.isOper==false)&&(t.cont[0]==38)) {
struct string tc = string(t.cont);
string__trimLeft(&tc,1);
char * ____BAH_COMPILER_VAR_1458 =string__str(&tc);struct variable* rv = getRealVar(____BAH_COMPILER_VAR_1458,elems);
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
if ((fl->data[i].type==TOKEN_TYPE_STR)&&(fl->data[i].processedStr==false)) {
fl->data[i].cont = strLitteralToBahStr(fl->data[i].cont);
fl->data[i].processedStr = true;
}
};
if (fixMeEnabled()) {
i = 0;
for (; (i<len(fl)); ++i) {
if ((fl->data[i].cont[0]==42)) {
fixMeTestVar(&fl->data[i],elems);
}
};
}
i = 0;
for (; (i<len(fl)); ++i) {
struct Tok t = fl->data[i];
if ((i>0)) {
pt = fl->data[i-1];
}
else {
struct Tok ____BAH_COMPILER_VAR_1459 = {};
____BAH_COMPILER_VAR_1459.cont = "";
____BAH_COMPILER_VAR_1459.ogCont = "";
____BAH_COMPILER_VAR_1459.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1459.line = 1;
____BAH_COMPILER_VAR_1459.begLine = 1;
____BAH_COMPILER_VAR_1459.bahType = "";
pt = ____BAH_COMPILER_VAR_1459;
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
if ((t.type==TOKEN_TYPE_VAR)) {
struct variable* v = searchVar(t.cont,elems);
t.bahRef = v;
}
t.bahType = string__str(&ptc);
char * ____BAH_COMPILER_VAR_1460 =string__str(&ptc);struct string cType = getCType(____BAH_COMPILER_VAR_1460,elems);
char** ____BAH_COMPILER_VAR_1461 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1461[3] = t.cont;____BAH_COMPILER_VAR_1461[2] = ")";____BAH_COMPILER_VAR_1461[1] = string__str(&cType);____BAH_COMPILER_VAR_1461[0] = "(";char * ____BAH_COMPILER_VAR_1462 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1461, 4);t.cont = ____BAH_COMPILER_VAR_1462;

    unsigned int ____BAH_COMPILER_VAR_1463 = i-1;
    __Bah_realocate_arr(fl, ____BAH_COMPILER_VAR_1463);
    fl->data[____BAH_COMPILER_VAR_1463] = t;
i = i-2;
}
else if (inArrayStr(pt.cont,signs)) {
if ((strcmp(t.cont, pt.cont) == 0)&&(i>1)) {
struct Tok ppt = fl->data[i-2];
if ((ppt.type==TOKEN_TYPE_VAR)) {
long int posTok = i-2;
deleteRange(fl,i-1,i);
char** ____BAH_COMPILER_VAR_1464 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1464[2] = ppt.cont;____BAH_COMPILER_VAR_1464[1] = t.cont;____BAH_COMPILER_VAR_1464[0] = t.cont;char * ____BAH_COMPILER_VAR_1465 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1464, 3);ppt.cont = ____BAH_COMPILER_VAR_1465;
ppt.isValue = true;
ppt.isOper = true;

    unsigned int ____BAH_COMPILER_VAR_1466 = posTok;
    __Bah_realocate_arr(fl, ____BAH_COMPILER_VAR_1466);
    fl->data[____BAH_COMPILER_VAR_1466] = ppt;
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
char** ____BAH_COMPILER_VAR_1467 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1467[1] = t.cont;____BAH_COMPILER_VAR_1467[0] = pt.cont;char * ____BAH_COMPILER_VAR_1468 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1467, 2);pt.cont = ____BAH_COMPILER_VAR_1468;

    unsigned int ____BAH_COMPILER_VAR_1469 = i-1;
    __Bah_realocate_arr(fl, ____BAH_COMPILER_VAR_1469);
    fl->data[____BAH_COMPILER_VAR_1469] = pt;
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
char** ____BAH_COMPILER_VAR_1470 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1470[2] = ".";____BAH_COMPILER_VAR_1470[1] = ptt;____BAH_COMPILER_VAR_1470[0] = "Cannot use {TOKEN} on ";char * ____BAH_COMPILER_VAR_1471 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1470, 3);throwErr(&t,____BAH_COMPILER_VAR_1471);
}
if ((strcmp(t.cont, "||") == 0)&&(isExprExpensive(&pt)==false)&&(isExprExpensive(&nt)==false)) {
char** ____BAH_COMPILER_VAR_1472 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1472[1] = nt.cont;____BAH_COMPILER_VAR_1472[0] = "||";char * ____BAH_COMPILER_VAR_1473 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1472, 2);char** ____BAH_COMPILER_VAR_1474 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1474[1] = ____BAH_COMPILER_VAR_1473;____BAH_COMPILER_VAR_1474[0] = pt.cont;char * ____BAH_COMPILER_VAR_1475 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1474, 2);pt.cont = ____BAH_COMPILER_VAR_1475;
}
else {
char** ____BAH_COMPILER_VAR_1476 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1476[1] = nt.cont;____BAH_COMPILER_VAR_1476[0] = t.cont;char * ____BAH_COMPILER_VAR_1477 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1476, 2);char** ____BAH_COMPILER_VAR_1478 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1478[1] = ____BAH_COMPILER_VAR_1477;____BAH_COMPILER_VAR_1478[0] = pt.cont;char * ____BAH_COMPILER_VAR_1479 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1478, 2);pt.cont = ____BAH_COMPILER_VAR_1479;
}

    unsigned int ____BAH_COMPILER_VAR_1480 = i-1;
    __Bah_realocate_arr(fl, ____BAH_COMPILER_VAR_1480);
    fl->data[____BAH_COMPILER_VAR_1480] = pt;
deleteRange(fl,i,i+1);
i = i-2;
}
else if ((t.type==TOKEN_TYPE_VAR)&&(t.cont[0]==38)) {
char * tt = getTypeFromToken(&t,true,elems);

                struct string ____BAH_COMPILER_VAR_1481 = string(tt);
                if (__builtin_expect(string__hasPrefix(&____BAH_COMPILER_VAR_1481,"tuple:"), 0)) {
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

    unsigned int ____BAH_COMPILER_VAR_1482 = len(fl);
    __Bah_realocate_arr(fl, ____BAH_COMPILER_VAR_1482);
    fl->data[____BAH_COMPILER_VAR_1482] = line->data[sepI];
++sepI;
};
}
return fl;
};
void parseFnDeclare(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
long int i = 0;
struct func* ____BAH_COMPILER_VAR_1483 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_1483->name = "";
____BAH_COMPILER_VAR_1483->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_1483->args->length = 0;
            ____BAH_COMPILER_VAR_1483->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_1483->from = "";
____BAH_COMPILER_VAR_1483->file = "";
____BAH_COMPILER_VAR_1483->line = 1;
struct func* fn = ____BAH_COMPILER_VAR_1483;
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
char** ____BAH_COMPILER_VAR_1484 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1484[4] = ".";____BAH_COMPILER_VAR_1484[3] = lineStr;____BAH_COMPILER_VAR_1484[2] = ":";____BAH_COMPILER_VAR_1484[1] = ogFn->file;____BAH_COMPILER_VAR_1484[0] = "Cannot redeclare function {TOKEN}, previous declaration: ";char * ____BAH_COMPILER_VAR_1485 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1484, 5);throwErr(&ft,____BAH_COMPILER_VAR_1485);
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
struct debugFunction* ____BAH_COMPILER_VAR_1486 = memoryAlloc(sizeof(struct debugFunction));
____BAH_COMPILER_VAR_1486->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_1486->args->length = 0;
            ____BAH_COMPILER_VAR_1486->args->elemSize = sizeof(struct variable*);
            struct debugFunction* df = ____BAH_COMPILER_VAR_1486;
df->name = fn->name;
df->args = fn->args;
df->returns = fn->returns->type;
struct debugFunction* ____BAH_COMPILER_VAR_1487 = df;
char ** ____BAH_COMPILER_VAR_1489 = (char **)((char*)(____BAH_COMPILER_VAR_1487) + offsetof(struct debugFunction, name));
struct reflectElement ____BAH_COMPILER_VAR_1490 = __reflect(____BAH_COMPILER_VAR_1489, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct debugFunction, name));
char ** ____BAH_COMPILER_VAR_1491 = (char **)((char*)(____BAH_COMPILER_VAR_1487) + offsetof(struct debugFunction, returns));
struct reflectElement ____BAH_COMPILER_VAR_1492 = __reflect(____BAH_COMPILER_VAR_1491, sizeof(char *), "cpstring", "returns", 0, 0, 0, 0, offsetof(struct debugFunction, returns));
array(struct variable*)** ____BAH_COMPILER_VAR_1493 = (array(struct variable*)**)((char*)(____BAH_COMPILER_VAR_1487) + offsetof(struct debugFunction, args));
struct variable** ____BAH_COMPILER_VAR_1494 = 0;
char ** ____BAH_COMPILER_VAR_1496 = (char **)((char*)(____BAH_COMPILER_VAR_1494) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_1497 = __reflect(____BAH_COMPILER_VAR_1496, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_1498 = (char **)((char*)(____BAH_COMPILER_VAR_1494) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_1499 = __reflect(____BAH_COMPILER_VAR_1498, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_1500 = (char*)((char*)(____BAH_COMPILER_VAR_1494) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_1501 = __reflect(____BAH_COMPILER_VAR_1500, sizeof(char), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_1502 = (char **)((char*)(____BAH_COMPILER_VAR_1494) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_1503 = __reflect(____BAH_COMPILER_VAR_1502, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_1504 = (char*)((char*)(____BAH_COMPILER_VAR_1494) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_1505 = __reflect(____BAH_COMPILER_VAR_1504, sizeof(char), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_1506 = (char **)((char*)(____BAH_COMPILER_VAR_1494) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_1507 = __reflect(____BAH_COMPILER_VAR_1506, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
void ** ____BAH_COMPILER_VAR_1508 = (void **)((char*)(____BAH_COMPILER_VAR_1494) + offsetof(struct variable, declScope));
struct reflectElement ____BAH_COMPILER_VAR_1509 = __reflect(____BAH_COMPILER_VAR_1508, sizeof(void *), "ptr", "declScope", 0, 0, 0, 0, offsetof(struct variable, declScope));
char* ____BAH_COMPILER_VAR_1510 = (char*)((char*)(____BAH_COMPILER_VAR_1494) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_1511 = __reflect(____BAH_COMPILER_VAR_1510, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));
struct rope** ____BAH_COMPILER_VAR_1512 = (struct rope**)((char*)(____BAH_COMPILER_VAR_1494) + offsetof(struct variable, declRope));
void ** ____BAH_COMPILER_VAR_1514 = (void **)((char*)(____BAH_COMPILER_VAR_1512) + offsetof(struct rope, left));
struct reflectElement ____BAH_COMPILER_VAR_1515 = __reflect(____BAH_COMPILER_VAR_1514, sizeof(void *), "ptr", "left", 0, 0, 0, 0, offsetof(struct rope, left));
void ** ____BAH_COMPILER_VAR_1516 = (void **)((char*)(____BAH_COMPILER_VAR_1512) + offsetof(struct rope, right));
struct reflectElement ____BAH_COMPILER_VAR_1517 = __reflect(____BAH_COMPILER_VAR_1516, sizeof(void *), "ptr", "right", 0, 0, 0, 0, offsetof(struct rope, right));
char ** ____BAH_COMPILER_VAR_1518 = (char **)((char*)(____BAH_COMPILER_VAR_1512) + offsetof(struct rope, str));
struct reflectElement ____BAH_COMPILER_VAR_1519 = __reflect(____BAH_COMPILER_VAR_1518, sizeof(char *), "cpstring", "str", 0, 0, 0, 0, offsetof(struct rope, str));
int* ____BAH_COMPILER_VAR_1520 = (int*)((char*)(____BAH_COMPILER_VAR_1512) + offsetof(struct rope, lCount));
struct reflectElement ____BAH_COMPILER_VAR_1521 = __reflect(____BAH_COMPILER_VAR_1520, sizeof(int), "int32", "lCount", 0, 0, 0, 0, offsetof(struct rope, lCount));
int* ____BAH_COMPILER_VAR_1522 = (int*)((char*)(____BAH_COMPILER_VAR_1512) + offsetof(struct rope, len));
struct reflectElement ____BAH_COMPILER_VAR_1523 = __reflect(____BAH_COMPILER_VAR_1522, sizeof(int), "int32", "len", 0, 0, 0, 0, offsetof(struct rope, len));
int* ____BAH_COMPILER_VAR_1524 = (int*)((char*)(____BAH_COMPILER_VAR_1512) + offsetof(struct rope, totalLen));
struct reflectElement ____BAH_COMPILER_VAR_1525 = __reflect(____BAH_COMPILER_VAR_1524, sizeof(int), "int32", "totalLen", 0, 0, 0, 0, offsetof(struct rope, totalLen));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_1513 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_1513->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_1513->length = 6;
        ____BAH_COMPILER_VAR_1513->data = memoryAlloc(____BAH_COMPILER_VAR_1513->length * ____BAH_COMPILER_VAR_1513->elemSize);
        ____BAH_COMPILER_VAR_1513->data[0] = ____BAH_COMPILER_VAR_1515;
____BAH_COMPILER_VAR_1513->data[1] = ____BAH_COMPILER_VAR_1517;
____BAH_COMPILER_VAR_1513->data[2] = ____BAH_COMPILER_VAR_1519;
____BAH_COMPILER_VAR_1513->data[3] = ____BAH_COMPILER_VAR_1521;
____BAH_COMPILER_VAR_1513->data[4] = ____BAH_COMPILER_VAR_1523;
____BAH_COMPILER_VAR_1513->data[5] = ____BAH_COMPILER_VAR_1525;
struct reflectElement ____BAH_COMPILER_VAR_1526 = __reflect(____BAH_COMPILER_VAR_1512, sizeof(struct rope), "rope*", "declRope", 0, 0, 1, ____BAH_COMPILER_VAR_1513, offsetof(struct variable, declRope));
char* ____BAH_COMPILER_VAR_1527 = (char*)((char*)(____BAH_COMPILER_VAR_1494) + offsetof(struct variable, canBeNull));
struct reflectElement ____BAH_COMPILER_VAR_1528 = __reflect(____BAH_COMPILER_VAR_1527, sizeof(char), "bool", "canBeNull", 0, 0, 0, 0, offsetof(struct variable, canBeNull));
char* ____BAH_COMPILER_VAR_1529 = (char*)((char*)(____BAH_COMPILER_VAR_1494) + offsetof(struct variable, canBeReg));
struct reflectElement ____BAH_COMPILER_VAR_1530 = __reflect(____BAH_COMPILER_VAR_1529, sizeof(char), "bool", "canBeReg", 0, 0, 0, 0, offsetof(struct variable, canBeReg));
char* ____BAH_COMPILER_VAR_1531 = (char*)((char*)(____BAH_COMPILER_VAR_1494) + offsetof(struct variable, isReg));
struct reflectElement ____BAH_COMPILER_VAR_1532 = __reflect(____BAH_COMPILER_VAR_1531, sizeof(char), "bool", "isReg", 0, 0, 0, 0, offsetof(struct variable, isReg));
void ** ____BAH_COMPILER_VAR_1533 = (void **)((char*)(____BAH_COMPILER_VAR_1494) + offsetof(struct variable, lastSet));
struct reflectElement ____BAH_COMPILER_VAR_1534 = __reflect(____BAH_COMPILER_VAR_1533, sizeof(void *), "ptr", "lastSet", 0, 0, 0, 0, offsetof(struct variable, lastSet));
char* ____BAH_COMPILER_VAR_1535 = (char*)((char*)(____BAH_COMPILER_VAR_1494) + offsetof(struct variable, isArg));
struct reflectElement ____BAH_COMPILER_VAR_1536 = __reflect(____BAH_COMPILER_VAR_1535, sizeof(char), "bool", "isArg", 0, 0, 0, 0, offsetof(struct variable, isArg));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_1495 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_1495->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_1495->length = 14;
        ____BAH_COMPILER_VAR_1495->data = memoryAlloc(____BAH_COMPILER_VAR_1495->length * ____BAH_COMPILER_VAR_1495->elemSize);
        ____BAH_COMPILER_VAR_1495->data[0] = ____BAH_COMPILER_VAR_1497;
____BAH_COMPILER_VAR_1495->data[1] = ____BAH_COMPILER_VAR_1499;
____BAH_COMPILER_VAR_1495->data[2] = ____BAH_COMPILER_VAR_1501;
____BAH_COMPILER_VAR_1495->data[3] = ____BAH_COMPILER_VAR_1503;
____BAH_COMPILER_VAR_1495->data[4] = ____BAH_COMPILER_VAR_1505;
____BAH_COMPILER_VAR_1495->data[5] = ____BAH_COMPILER_VAR_1507;
____BAH_COMPILER_VAR_1495->data[6] = ____BAH_COMPILER_VAR_1509;
____BAH_COMPILER_VAR_1495->data[7] = ____BAH_COMPILER_VAR_1511;
____BAH_COMPILER_VAR_1495->data[8] = ____BAH_COMPILER_VAR_1526;
____BAH_COMPILER_VAR_1495->data[9] = ____BAH_COMPILER_VAR_1528;
____BAH_COMPILER_VAR_1495->data[10] = ____BAH_COMPILER_VAR_1530;
____BAH_COMPILER_VAR_1495->data[11] = ____BAH_COMPILER_VAR_1532;
____BAH_COMPILER_VAR_1495->data[12] = ____BAH_COMPILER_VAR_1534;
____BAH_COMPILER_VAR_1495->data[13] = ____BAH_COMPILER_VAR_1536;
struct reflectElement ____BAH_COMPILER_VAR_1537 = __reflect(____BAH_COMPILER_VAR_1494, sizeof(struct variable), "variable*", "", 0, 0, 1, ____BAH_COMPILER_VAR_1495, 0);

        struct reflectElement ____BAH_COMPILER_VAR_1538 = ____BAH_COMPILER_VAR_1537;
        struct reflectElement ____BAH_COMPILER_VAR_1539 = __reflect(____BAH_COMPILER_VAR_1493, sizeof(array(struct variable*)*), "[]variable*", "args", 1, &____BAH_COMPILER_VAR_1538, 0, 0, offsetof(struct debugFunction, args));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_1488 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_1488->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_1488->length = 3;
        ____BAH_COMPILER_VAR_1488->data = memoryAlloc(____BAH_COMPILER_VAR_1488->length * ____BAH_COMPILER_VAR_1488->elemSize);
        ____BAH_COMPILER_VAR_1488->data[0] = ____BAH_COMPILER_VAR_1490;
____BAH_COMPILER_VAR_1488->data[1] = ____BAH_COMPILER_VAR_1492;
____BAH_COMPILER_VAR_1488->data[2] = ____BAH_COMPILER_VAR_1539;
struct reflectElement ____BAH_COMPILER_VAR_1540 = __reflect(____BAH_COMPILER_VAR_1487, sizeof(struct debugFunction), "debugFunction*", "df", 0, 0, 1, ____BAH_COMPILER_VAR_1488, 0);
debugPrint("fn_declare",ft.line,____BAH_COMPILER_VAR_1540);
}
register long int j = 0;
for (; (j<len(fn->args)); ++j) {
if ((strcmp(fn->args->data[j]->type, "<any>") == 0)) {
struct genericFunc* ____BAH_COMPILER_VAR_1541 = memoryAlloc(sizeof(struct genericFunc));
____BAH_COMPILER_VAR_1541->tokens = memoryAlloc(sizeof(array(struct Tok)));
            ____BAH_COMPILER_VAR_1541->tokens->length = 0;
            ____BAH_COMPILER_VAR_1541->tokens->elemSize = sizeof(struct Tok);
            ____BAH_COMPILER_VAR_1541->declared = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_1541->declared->length = 0;
            ____BAH_COMPILER_VAR_1541->declared->elemSize = sizeof(struct func*);
            ____BAH_COMPILER_VAR_1541->tokens = arraySubstitute(l, i+1, len(l)-1);
____BAH_COMPILER_VAR_1541->baseFn = fn;
____BAH_COMPILER_VAR_1541->tokenName = &ft;

    unsigned int ____BAH_COMPILER_VAR_1542 = len(generics);
    __Bah_realocate_arr(generics, ____BAH_COMPILER_VAR_1542);
    generics->data[____BAH_COMPILER_VAR_1542] = ____BAH_COMPILER_VAR_1541;
return;
}
};
if ((shouldOnlyDecl==true)) {
if ((ogFn!=null)) {
fn->isBinding = false;
}
fn->isImported = true;

    unsigned int ____BAH_COMPILER_VAR_1543 = len(elems->fns);
    __Bah_realocate_arr(elems->fns, ____BAH_COMPILER_VAR_1543);
    elems->fns->data[____BAH_COMPILER_VAR_1543] = fn;
char** ____BAH_COMPILER_VAR_1544 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1544[1] = ";\n";____BAH_COMPILER_VAR_1544[0] = code;char * ____BAH_COMPILER_VAR_1545 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1544, 2);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1545));
return;
}
postDeclHandle = rope("");
OUTPUT = rope__add(OUTPUT, postDeclHandle);
char** ____BAH_COMPILER_VAR_1546 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1546[1] = "{\n";____BAH_COMPILER_VAR_1546[0] = code;char * ____BAH_COMPILER_VAR_1547 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1546, 2);code = ____BAH_COMPILER_VAR_1547;
fn->code = rope(code);
struct Elems* fnElems = dupElems(elems);
array(struct variable*)* vs = fnElems->vars;
j = 0;
while ((j<len(fn->args))) {
struct variable* a = fn->args->data[j];
a->declScope = elems;
a->isArg = true;

    unsigned int ____BAH_COMPILER_VAR_1548 = len(vs);
    __Bah_realocate_arr(vs, ____BAH_COMPILER_VAR_1548);
    vs->data[____BAH_COMPILER_VAR_1548] = a;
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

    unsigned int ____BAH_COMPILER_VAR_1549 = len(fns);
    __Bah_realocate_arr(fns, ____BAH_COMPILER_VAR_1549);
    fns->data[____BAH_COMPILER_VAR_1549] = fn;
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
char** ____BAH_COMPILER_VAR_1550 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1550[2] = "' is not returned.";____BAH_COMPILER_VAR_1550[1] = fn->name;____BAH_COMPILER_VAR_1550[0] = "Function '";char * ____BAH_COMPILER_VAR_1551 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1550, 3);throwErr(&l->data[len(l)-1],____BAH_COMPILER_VAR_1551);
}
endRCPscope(fnElems,fn->args);
fixMeEndScope(fnElems,&tokens->data[len(tokens)-1]);
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
char** ____BAH_COMPILER_VAR_1552 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1552[2] = ") as maybe value.";____BAH_COMPILER_VAR_1552[1] = valType;____BAH_COMPILER_VAR_1552[0] = "Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_1553 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1552, 3);throwErr(&valTok,____BAH_COMPILER_VAR_1553);
}
char** ____BAH_COMPILER_VAR_1554 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1554[1] = "*";____BAH_COMPILER_VAR_1554[0] = cpstringSubsitute(valType, 0, strlen(valType)-1);char * ____BAH_COMPILER_VAR_1555 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1554, 2);char * newType = ____BAH_COMPILER_VAR_1555;
if (__builtin_expect((strcmp(line->data[4].cont, "else") != 0)&&(strcmp(line->data[4].cont, "then") != 0), 0)) {
throwErr(&line->data[4],"Expected 'then' or 'else' got {TOKEN}.");
}
if ((strcmp(line->data[4].cont, "then") == 0)) {
isThen = true;
}
struct variable* v = searchVar(varTok.cont,elems);
char * code = "";
if ((v==null)) {
struct variable* ____BAH_COMPILER_VAR_1556 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1556->name = "";
____BAH_COMPILER_VAR_1556->type = "";
____BAH_COMPILER_VAR_1556->constVal = "";
____BAH_COMPILER_VAR_1556->from = "";
____BAH_COMPILER_VAR_1556->name = varTok.cont;
____BAH_COMPILER_VAR_1556->type = newType;
v = ____BAH_COMPILER_VAR_1556;

    unsigned int ____BAH_COMPILER_VAR_1557 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_1557);
    elems->vars->data[____BAH_COMPILER_VAR_1557] = v;

                struct string ____BAH_COMPILER_VAR_1558 = getCType(v->type,elems);
                char** ____BAH_COMPILER_VAR_1559 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1559[1] = " ";____BAH_COMPILER_VAR_1559[0] = string__str(&____BAH_COMPILER_VAR_1558);char * ____BAH_COMPILER_VAR_1560 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1559, 2);code = ____BAH_COMPILER_VAR_1560;
}
else {
if (__builtin_expect((strcmp(v->type, newType) != 0), 0)) {
char** ____BAH_COMPILER_VAR_1561 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1561[4] = ".";____BAH_COMPILER_VAR_1561[3] = newType;____BAH_COMPILER_VAR_1561[2] = ") as ";____BAH_COMPILER_VAR_1561[1] = v->type;____BAH_COMPILER_VAR_1561[0] = "Cannot use var {TOKEN} (";char * ____BAH_COMPILER_VAR_1562 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1561, 5);throwErr(&varTok,____BAH_COMPILER_VAR_1562);
}
}
char** ____BAH_COMPILER_VAR_1563 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1563[3] = ";";____BAH_COMPILER_VAR_1563[2] = valTok.cont;____BAH_COMPILER_VAR_1563[1] = " = ";____BAH_COMPILER_VAR_1563[0] = v->name;char * ____BAH_COMPILER_VAR_1564 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1563, 4);char** ____BAH_COMPILER_VAR_1565 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1565[1] = ____BAH_COMPILER_VAR_1564;____BAH_COMPILER_VAR_1565[0] = code;char * ____BAH_COMPILER_VAR_1566 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1565, 2);code = ____BAH_COMPILER_VAR_1566;
if ((isThen==true)) {
char** ____BAH_COMPILER_VAR_1567 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1567[2] = " != null) {";____BAH_COMPILER_VAR_1567[1] = v->name;____BAH_COMPILER_VAR_1567[0] = "if (";char * ____BAH_COMPILER_VAR_1568 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1567, 3);char** ____BAH_COMPILER_VAR_1569 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1569[1] = ____BAH_COMPILER_VAR_1568;____BAH_COMPILER_VAR_1569[0] = code;char * ____BAH_COMPILER_VAR_1570 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1569, 2);code = ____BAH_COMPILER_VAR_1570;
}
else {
char** ____BAH_COMPILER_VAR_1571 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1571[2] = " == null) {";____BAH_COMPILER_VAR_1571[1] = v->name;____BAH_COMPILER_VAR_1571[0] = "if (";char * ____BAH_COMPILER_VAR_1572 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1571, 3);char** ____BAH_COMPILER_VAR_1573 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1573[1] = ____BAH_COMPILER_VAR_1572;____BAH_COMPILER_VAR_1573[0] = code;char * ____BAH_COMPILER_VAR_1574 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1573, 2);code = ____BAH_COMPILER_VAR_1574;
}
OUTPUT = rope__add(OUTPUT, rope(code));
array(struct Tok)* tokens = arraySubstitute(line, 6, len(line)-1);
struct Elems* CaptElems = dupElems(elems);
parseLines(tokens,CaptElems);
if ((isThen==true)) {
OUTPUT = rope__add(OUTPUT, rope("}\n"));
}
else {
char** ____BAH_COMPILER_VAR_1575 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1575[4] = "\");}\n";____BAH_COMPILER_VAR_1575[3] = intToStr(line->data[0].line);____BAH_COMPILER_VAR_1575[2] = ":";____BAH_COMPILER_VAR_1575[1] = compilerState.currentFile;____BAH_COMPILER_VAR_1575[0] = "\n__BAH_panic(\"Undefined capture resolution.\", \"";char * ____BAH_COMPILER_VAR_1576 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1575, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1576));
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
char * ____BAH_COMPILER_VAR_1577 =registerRCPvar(fn->returns->type,ft.cont,elems);return;
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
char** ____BAH_COMPILER_VAR_1578 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1578[1] = ";\n";____BAH_COMPILER_VAR_1578[0] = ft.cont;char * ____BAH_COMPILER_VAR_1579 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1578, 2);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1579));
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

    unsigned int ____BAH_COMPILER_VAR_1580 = len(line);
    __Bah_realocate_arr(line, ____BAH_COMPILER_VAR_1580);
    line->data[____BAH_COMPILER_VAR_1580] = t;
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

    unsigned int ____BAH_COMPILER_VAR_1581 = len(line);
    __Bah_realocate_arr(line, ____BAH_COMPILER_VAR_1581);
    line->data[____BAH_COMPILER_VAR_1581] = t;
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
char** ____BAH_COMPILER_VAR_1582 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1582[3] = arg->name;____BAH_COMPILER_VAR_1582[2] = " ";____BAH_COMPILER_VAR_1582[1] = string__str(&ct);____BAH_COMPILER_VAR_1582[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_1583 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1582, 4);tmpfnArgsCType = ____BAH_COMPILER_VAR_1583;
j = j+1;
if ((j<len(fn->args))) {
char** ____BAH_COMPILER_VAR_1584 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1584[1] = ", ";____BAH_COMPILER_VAR_1584[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_1585 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1584, 2);tmpfnArgsCType = ____BAH_COMPILER_VAR_1585;
}
};
char** ____BAH_COMPILER_VAR_1586 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_1586[5] = ");\n";____BAH_COMPILER_VAR_1586[4] = tmpfnArgsCType;____BAH_COMPILER_VAR_1586[3] = "(";____BAH_COMPILER_VAR_1586[2] = fn->name;____BAH_COMPILER_VAR_1586[1] = " ";____BAH_COMPILER_VAR_1586[0] = string__str(&tmpfnRetCType);char * ____BAH_COMPILER_VAR_1587 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1586, 6);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1587));
};
void declareVar(struct variable* v,struct Elems* elems){
if ((v->isConst==true)) {
char** ____BAH_COMPILER_VAR_1588 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1588[4] = "\n";____BAH_COMPILER_VAR_1588[3] = v->constVal;____BAH_COMPILER_VAR_1588[2] = " ";____BAH_COMPILER_VAR_1588[1] = v->name;____BAH_COMPILER_VAR_1588[0] = "#define ";char * ____BAH_COMPILER_VAR_1589 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1588, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1589));
}
else {
struct string cType = getCType(v->type,elems);
char** ____BAH_COMPILER_VAR_1590 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1590[3] = ";\n";____BAH_COMPILER_VAR_1590[2] = v->name;____BAH_COMPILER_VAR_1590[1] = " ";____BAH_COMPILER_VAR_1590[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_1591 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1590, 4);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1591));
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
char** ____BAH_COMPILER_VAR_1592 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1592[2] = "\n";____BAH_COMPILER_VAR_1592[1] = compilerState.cIncludes->data[i];____BAH_COMPILER_VAR_1592[0] = "#include ";char * ____BAH_COMPILER_VAR_1593 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1592, 3);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1593));
};
i = 1;
for (; (i<len(compilerState.arrTypesDecl)); ++i) {
char * t = compilerState.arrTypesDecl->data[i];
struct string elemType = string(t);
string__trimLeft(&elemType,15);
char * ____BAH_COMPILER_VAR_1594 =string__str(&elemType);struct string elemCtype = getCType(____BAH_COMPILER_VAR_1594,elems);
char** ____BAH_COMPILER_VAR_1595 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1595[4] = ";\n";____BAH_COMPILER_VAR_1595[3] = t;____BAH_COMPILER_VAR_1595[2] = ")* ";____BAH_COMPILER_VAR_1595[1] = string__str(&elemCtype);____BAH_COMPILER_VAR_1595[0] = "typedef array(";char * ____BAH_COMPILER_VAR_1596 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1595, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1596));
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
char** ____BAH_COMPILER_VAR_1597 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1597[1] = compilerState.currentFile;____BAH_COMPILER_VAR_1597[0] = "file: ";char * ____BAH_COMPILER_VAR_1598 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1597, 2);char * r = ____BAH_COMPILER_VAR_1598;
if ((currentFn!=null)) {
char** ____BAH_COMPILER_VAR_1599 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1599[2] = "()";____BAH_COMPILER_VAR_1599[1] = currentFn->name;____BAH_COMPILER_VAR_1599[0] = "\nfunction: ";char * ____BAH_COMPILER_VAR_1600 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1599, 3);char** ____BAH_COMPILER_VAR_1601 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1601[1] = ____BAH_COMPILER_VAR_1600;____BAH_COMPILER_VAR_1601[0] = r;char * ____BAH_COMPILER_VAR_1602 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1601, 2);r = ____BAH_COMPILER_VAR_1602;
}
return r;
};
long int main(__BAH_ARR_TYPE_cpstring args){
onMemoryError = memErrHandle;
execName = args->data[0];
if ((execName[0]==46)||(execName[0]==47)) {
execName = absPath(execName);
}
struct flags ____BAH_COMPILER_VAR_1603 = {};
____BAH_COMPILER_VAR_1603.flags = memoryAlloc(sizeof(array(struct flag*)));
            ____BAH_COMPILER_VAR_1603.flags->length = 0;
            ____BAH_COMPILER_VAR_1603.flags->elemSize = sizeof(struct flag*);
            ____BAH_COMPILER_VAR_1603.args = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_1603.args->length = 0;
            ____BAH_COMPILER_VAR_1603.args->elemSize = sizeof(char *);
            flags = ____BAH_COMPILER_VAR_1603;
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
char** ____BAH_COMPILER_VAR_1604 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1604[2] = ".";____BAH_COMPILER_VAR_1604[1] = BAH_OS;____BAH_COMPILER_VAR_1604[0] = "Select the target OS for cross compilling (linux, windows, darwin), default: ";char * ____BAH_COMPILER_VAR_1605 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1604, 3);flags__addString(&flags,"target",____BAH_COMPILER_VAR_1605);
char** ____BAH_COMPILER_VAR_1606 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1606[2] = ").";____BAH_COMPILER_VAR_1606[1] = BAH_DIR;____BAH_COMPILER_VAR_1606[0] = "If your Bah directory is not the default one (";char * ____BAH_COMPILER_VAR_1607 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1606, 3);flags__addString(&flags,"bahDir",____BAH_COMPILER_VAR_1607);
char** ____BAH_COMPILER_VAR_1608 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1608[2] = ".";____BAH_COMPILER_VAR_1608[1] = BAH_CC;____BAH_COMPILER_VAR_1608[0] = "To change the C compiler used, default: ";char * ____BAH_COMPILER_VAR_1609 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1608, 3);flags__addString(&flags,"CC",____BAH_COMPILER_VAR_1609);
flags__addBool(&flags,"object","Compile as an object.");
flags__addBool(&flags,"unsafe","Compile without safety checking. This will make for faster executable but if your program crashes, it will show less informations.");
flags__addBool(&flags,"nobuiltin","Does not include the builtin library (be really carefull, your program WILL break).");
flags__addBool(&flags,"optimize","Includes optimized functions");
flags__addBool(&flags,"n","Disables notices while keeping warnings enabled.");
flags__addBool(&flags,"raii","Enables RAII memory management.");
flags__addBool(&flags,"fixMe","Enables runtime debugging engine, useful for segfaults...");
flags__parse(&flags,args);
RAIIenabled = (flags__isSet(&flags,"raii")==1);
isFixMeEnabled = (flags__isSet(&flags,"fixMe")==1);
if ((RAIIenabled==true)) {
println("RAII is not yet available...");
return 1;
}
if ((flags__isSet(&flags,"target")==1)) {
BAH_OS = flags__get(&flags,"target");
char** ____BAH_COMPILER_VAR_1610 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1610[1] = BAH_OS;____BAH_COMPILER_VAR_1610[0] = "Build target: ";char * ____BAH_COMPILER_VAR_1611 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1610, 2);println(____BAH_COMPILER_VAR_1611);
}
if ((flags__isSet(&flags,"bahDir")==1)) {
BAH_DIR = flags__get(&flags,"bahDir");
array(char)* bahDirArr = strAsArr(BAH_DIR);
if ((bahDirArr->data[len(bahDirArr)-1]!=47)) {
char** ____BAH_COMPILER_VAR_1612 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1612[1] = "/";____BAH_COMPILER_VAR_1612[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_1613 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1612, 2);BAH_DIR = ____BAH_COMPILER_VAR_1613;
}
char** ____BAH_COMPILER_VAR_1614 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1614[1] = BAH_DIR;____BAH_COMPILER_VAR_1614[0] = "Bah directory: ";char * ____BAH_COMPILER_VAR_1615 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1614, 2);println(____BAH_COMPILER_VAR_1615);
}
if ((flags__isSet(&flags,"CC")==1)) {
BAH_CC = flags__get(&flags,"CC");
char** ____BAH_COMPILER_VAR_1616 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1616[1] = BAH_CC;____BAH_COMPILER_VAR_1616[0] = "C compiler: ";char * ____BAH_COMPILER_VAR_1617 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1616, 2);println(____BAH_COMPILER_VAR_1617);
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
char** ____BAH_COMPILER_VAR_1618 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1618[2] = ".\n© Alois Laurent Boe";____BAH_COMPILER_VAR_1618[1] = BAH_VERSION;____BAH_COMPILER_VAR_1618[0] = "Bah compiler version: ";char * ____BAH_COMPILER_VAR_1619 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1618, 3);println(____BAH_COMPILER_VAR_1619);
return 0;
}
if (__builtin_expect((flags__isSet(&flags,"c")==1)&&(flags__isSet(&flags,"l")==1), 0)) {
__BAH_panic("Cannot use -c (to translate to C code) and -l (to compile as a library) at the same time.","/home/alois/Documents/bah-bah/src/main.bah:156");
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
else if ((RAIIenabled==true)) {
OUTPUT = rope__add(OUTPUT, rope("\n            #include <string.h>\n            int main(int argc, char ** argv) {\n            array(char*) * args = malloc(sizeof(array(char*)));\n            args->data = malloc(sizeof(char*)*argc);\n            memcpy(args->data, argv, sizeof(char*)*argc);\n            args->elemSize = sizeof(char*);\n            args->length = argc;\n            __BAH_init();\n            long int r =  __BAH__main((__BAH_ARR_TYPE_cpstring)args);\n            free(args->data);\n            free(args);\n            return r;\n            };\n            #define main(v) __BAH__main(v)\n            "));
}
else {
OUTPUT = rope__add(OUTPUT, rope("\n            #include <gc.h>\n            #include <string.h>\n            int main(int argc, char ** argv) {\n            GC_INIT();\n            array(char*) * args = GC_MALLOC(sizeof(array(char*)));\n            args->data = GC_MALLOC(sizeof(char*)*argc);\n            memcpy(args->data, argv, sizeof(char*)*argc);\n            args->elemSize = sizeof(char*);\n            args->length = argc;\n            __BAH_init();\n            long int r =  __BAH__main((__BAH_ARR_TYPE_cpstring)args);\n            GC_FREE(args->data);\n            GC_FREE(args);\n            return r;\n            };\n            #define main(v) __BAH__main(v)\n            "));
}
}
struct compilerStateTag ____BAH_COMPILER_VAR_1620 = {};
____BAH_COMPILER_VAR_1620.includes = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_1620.includes->length = 0;
            ____BAH_COMPILER_VAR_1620.includes->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_1620.cIncludes = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_1620.cIncludes->length = 0;
            ____BAH_COMPILER_VAR_1620.cIncludes->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_1620.cLibs = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_1620.cLibs->length = 0;
            ____BAH_COMPILER_VAR_1620.cLibs->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_1620.currentDir = "./";
____BAH_COMPILER_VAR_1620.arrTypesDecl = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_1620.arrTypesDecl->length = 0;
            ____BAH_COMPILER_VAR_1620.arrTypesDecl->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_1620.RCPvars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_1620.RCPvars->length = 0;
            ____BAH_COMPILER_VAR_1620.RCPvars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_1620.evals = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_1620.evals->length = 0;
            ____BAH_COMPILER_VAR_1620.evals->elemSize = sizeof(char *);
            compilerState = ____BAH_COMPILER_VAR_1620;

    unsigned int ____BAH_COMPILER_VAR_1621 = 0;
    __Bah_realocate_arr(compilerState.arrTypesDecl, ____BAH_COMPILER_VAR_1621);
    compilerState.arrTypesDecl->data[____BAH_COMPILER_VAR_1621] = "__BAH_ARR_TYPE_cpstring";
char * fileName = absPath(args->data[1]);
compilerState.currentFile = fileName;
struct fileMap ____BAH_COMPILER_VAR_1622 = {};
____BAH_COMPILER_VAR_1622.handle = -1;
struct fileMap fm = ____BAH_COMPILER_VAR_1622;
char * f = fileMap__open(&fm,fileName);
if (__builtin_expect((fileMap__isValid(&fm)==0)||(fm.size==0), 0)) {
char** ____BAH_COMPILER_VAR_1623 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1623[2] = "'.";____BAH_COMPILER_VAR_1623[1] = args->data[1];____BAH_COMPILER_VAR_1623[0] = "Could not open file '";char * ____BAH_COMPILER_VAR_1624 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1623, 3);println(____BAH_COMPILER_VAR_1624);
exit(1);
}
long int startTime = getTimeUnix();
array(struct Tok)* tokens = lexer(f,fm.size);
fileMap__close(&fm);
if (__builtin_expect((len(tokens)==0), 0)) {
char** ____BAH_COMPILER_VAR_1625 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1625[2] = "' not recognized.";____BAH_COMPILER_VAR_1625[1] = fileName;____BAH_COMPILER_VAR_1625[0] = "File '";char * ____BAH_COMPILER_VAR_1626 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1625, 3);println(____BAH_COMPILER_VAR_1626);
exit(1);
}
struct Elems* ____BAH_COMPILER_VAR_1627 = memoryAlloc(sizeof(struct Elems));
____BAH_COMPILER_VAR_1627->vars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_1627->vars->length = 0;
            ____BAH_COMPILER_VAR_1627->vars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_1627->structs = memoryAlloc(sizeof(array(struct cStruct*)));
            ____BAH_COMPILER_VAR_1627->structs->length = 0;
            ____BAH_COMPILER_VAR_1627->structs->elemSize = sizeof(struct cStruct*);
            ____BAH_COMPILER_VAR_1627->types = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_1627->types->length = 0;
            ____BAH_COMPILER_VAR_1627->types->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_1627->fns = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_1627->fns->length = 0;
            ____BAH_COMPILER_VAR_1627->fns->elemSize = sizeof(struct func*);
            ____BAH_COMPILER_VAR_1627->deletedVars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_1627->deletedVars->length = 0;
            ____BAH_COMPILER_VAR_1627->deletedVars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_1627->branchChecks = memoryAlloc(sizeof(array(struct varCheck)));
            ____BAH_COMPILER_VAR_1627->branchChecks->length = 0;
            ____BAH_COMPILER_VAR_1627->branchChecks->elemSize = sizeof(struct varCheck);
            struct Elems* elems = ____BAH_COMPILER_VAR_1627;
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

                struct string ____BAH_COMPILER_VAR_1628 = string(fileName);
                if ((flags__isSet(&flags,"nobuiltin")==0)&&(string__hasSuffix(&____BAH_COMPILER_VAR_1628,".bahstrp")==false)) {
if (__builtin_expect((includeFile("builtin.bah",elems)==false), 0)) {
char** ____BAH_COMPILER_VAR_1629 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1629[2] = "'";____BAH_COMPILER_VAR_1629[1] = BAH_DIR;____BAH_COMPILER_VAR_1629[0] = "Could not find std-libs, please check '";char * ____BAH_COMPILER_VAR_1630 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1629, 3);__BAH_panic(____BAH_COMPILER_VAR_1630,"/home/alois/Documents/bah-bah/src/main.bah:284");
}
}
if ((isFixMeEnabled==true)) {
if (__builtin_expect((includeFile("fixme.bah",elems)==false), 0)) {
char** ____BAH_COMPILER_VAR_1631 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1631[2] = "'";____BAH_COMPILER_VAR_1631[1] = BAH_DIR;____BAH_COMPILER_VAR_1631[0] = "Could not find fixme.bah, please check '";char * ____BAH_COMPILER_VAR_1632 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1631, 3);__BAH_panic(____BAH_COMPILER_VAR_1632,"/home/alois/Documents/bah-bah/src/main.bah:290");
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
char** ____BAH_COMPILER_VAR_1633 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1633[2] = "];";____BAH_COMPILER_VAR_1633[1] = intToStr(l);____BAH_COMPILER_VAR_1633[0] = "volatile struct __Bah_fnName_mapper __tmp____Bah_fnNames[";char * ____BAH_COMPILER_VAR_1634 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1633, 3);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1634));
long int j = 0;
i = 0;
for (; (i<len(elems->fns)); ++i) {
struct func* fn = elems->fns->data[i];
if ((fn->isBinding==true)) {
continue;
}
char * name = fn->name;
char** ____BAH_COMPILER_VAR_1635 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1635[1] = "__";____BAH_COMPILER_VAR_1635[0] = fn->from;char * ____BAH_COMPILER_VAR_1636 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1635, 2);if ((strcmp(fn->from, "") != 0)&&strHasPrefix(name,____BAH_COMPILER_VAR_1636)) {
struct string n = string(name);
string__trimLeft(&n,strlen(fn->from)+2);
char** ____BAH_COMPILER_VAR_1637 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1637[2] = string__str(&n);____BAH_COMPILER_VAR_1637[1] = ".";____BAH_COMPILER_VAR_1637[0] = fn->from;char * ____BAH_COMPILER_VAR_1638 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1637, 3);name = ____BAH_COMPILER_VAR_1638;
}
char** ____BAH_COMPILER_VAR_1639 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1639[2] = "\"";____BAH_COMPILER_VAR_1639[1] = name;____BAH_COMPILER_VAR_1639[0] = "\"";char * ____BAH_COMPILER_VAR_1640 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1639, 3);char** ____BAH_COMPILER_VAR_1641 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_1641[8] = ";\n";____BAH_COMPILER_VAR_1641[7] = fn->name;____BAH_COMPILER_VAR_1641[6] = "].p = ";____BAH_COMPILER_VAR_1641[5] = intToStr(j);____BAH_COMPILER_VAR_1641[4] = ";\n            __tmp____Bah_fnNames[";____BAH_COMPILER_VAR_1641[3] = strLitteralToBahStr(____BAH_COMPILER_VAR_1640);____BAH_COMPILER_VAR_1641[2] = "].n = ";____BAH_COMPILER_VAR_1641[1] = intToStr(j);____BAH_COMPILER_VAR_1641[0] = "\n            __tmp____Bah_fnNames[";char * ____BAH_COMPILER_VAR_1642 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1641, 9);INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_1642));
++j;
};
char** ____BAH_COMPILER_VAR_1643 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1643[2] = ";";____BAH_COMPILER_VAR_1643[1] = intToStr(l);____BAH_COMPILER_VAR_1643[0] = "\n        __Bah_fnNames->data = __tmp____Bah_fnNames;\n        __Bah_fnNames->length = ";char * ____BAH_COMPILER_VAR_1644 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1643, 3);INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_1644));
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
char** ____BAH_COMPILER_VAR_1645 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_1645[6] = "ms)\e[0m";____BAH_COMPILER_VAR_1645[5] = intToStr(totalLexerTime/1000000);____BAH_COMPILER_VAR_1645[4] = "ms, lexer time: ";____BAH_COMPILER_VAR_1645[3] = intToStr(totalTime/1000000);____BAH_COMPILER_VAR_1645[2] = " lines, total time: ";____BAH_COMPILER_VAR_1645[1] = intToStr(totalLines);____BAH_COMPILER_VAR_1645[0] = "Parsed. (";char * ____BAH_COMPILER_VAR_1646 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1645, 7);println(____BAH_COMPILER_VAR_1646);
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
char** ____BAH_COMPILER_VAR_1647 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1647[1] = ".o";____BAH_COMPILER_VAR_1647[0] = fileName;char * ____BAH_COMPILER_VAR_1648 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1647, 2);fileName = ____BAH_COMPILER_VAR_1648;
obj = "-c";
}
char * randFileName = "-x c - -x none";
char** ____BAH_COMPILER_VAR_1649 = alloca(17 * sizeof(char*));____BAH_COMPILER_VAR_1649[16] = fileName;____BAH_COMPILER_VAR_1649[15] = " -w -O1 -o ";____BAH_COMPILER_VAR_1649[14] = obj;____BAH_COMPILER_VAR_1649[13] = " ";____BAH_COMPILER_VAR_1649[12] = isStatic;____BAH_COMPILER_VAR_1649[11] = " ";____BAH_COMPILER_VAR_1649[10] = randFileName;____BAH_COMPILER_VAR_1649[9] = "/\" ";____BAH_COMPILER_VAR_1649[8] = BAH_OS;____BAH_COMPILER_VAR_1649[7] = "libs/";____BAH_COMPILER_VAR_1649[6] = BAH_DIR;____BAH_COMPILER_VAR_1649[5] = "/include/\" -L \"";____BAH_COMPILER_VAR_1649[4] = BAH_OS;____BAH_COMPILER_VAR_1649[3] = "libs/";____BAH_COMPILER_VAR_1649[2] = BAH_DIR;____BAH_COMPILER_VAR_1649[1] = " -I \"";____BAH_COMPILER_VAR_1649[0] = BAH_CC;char * ____BAH_COMPILER_VAR_1650 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1649, 17);char * gccArgs = ____BAH_COMPILER_VAR_1650;
if ((flags__isSet(&flags,"l")==1)) {
char** ____BAH_COMPILER_VAR_1651 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1651[1] = " -c";____BAH_COMPILER_VAR_1651[0] = gccArgs;char * ____BAH_COMPILER_VAR_1652 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1651, 2);gccArgs = ____BAH_COMPILER_VAR_1652;
}
array(char *)* cLibs = compilerState.cLibs;
register long int i = 0;
while ((i<len(cLibs))) {
char * l = cLibs->data[i];
char** ____BAH_COMPILER_VAR_1653 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1653[2] = l;____BAH_COMPILER_VAR_1653[1] = " -";____BAH_COMPILER_VAR_1653[0] = gccArgs;char * ____BAH_COMPILER_VAR_1654 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1653, 3);gccArgs = ____BAH_COMPILER_VAR_1654;
i = i+1;
};
struct command cmd = command(gccArgs);
cmd.input = rope__toStr(OUTPUT);
if ((flags__isSet(&flags,"verboseCC")==0)) {
cmd.error = false;
}
if ((flags__isSet(&flags,"verboseCC")==1)) {
char * ____BAH_COMPILER_VAR_1655 =command__run(&cmd);println(____BAH_COMPILER_VAR_1655);
}
else {
char * ____BAH_COMPILER_VAR_1656 =command__run(&cmd);}
if ((cmd.status!=0)) {
println("\e[1;31m[CC-ERROR]\e[0m\nCould not compiled.");
return 1;
}
if ((flags__isSet(&flags,"l")==1)) {
char** ____BAH_COMPILER_VAR_1657 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1657[3] = fileName;____BAH_COMPILER_VAR_1657[2] = ".a ";____BAH_COMPILER_VAR_1657[1] = fileName;____BAH_COMPILER_VAR_1657[0] = "ar rcs ";char * ____BAH_COMPILER_VAR_1658 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1657, 4);cmd = command(____BAH_COMPILER_VAR_1658);
char * ____BAH_COMPILER_VAR_1659 =command__run(&cmd);}
}
else {
if ((flags__isSet(&flags,"o")==0)) {
char** ____BAH_COMPILER_VAR_1660 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1660[1] = ".c";____BAH_COMPILER_VAR_1660[0] = fileName;char * ____BAH_COMPILER_VAR_1661 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1660, 2);fileName = ____BAH_COMPILER_VAR_1661;
}
char** ____BAH_COMPILER_VAR_1662 = alloca(14 * sizeof(char*));____BAH_COMPILER_VAR_1662[13] = " -O1 -w ";____BAH_COMPILER_VAR_1662[12] = isStatic;____BAH_COMPILER_VAR_1662[11] = " ";____BAH_COMPILER_VAR_1662[10] = fileName;____BAH_COMPILER_VAR_1662[9] = "/\" ";____BAH_COMPILER_VAR_1662[8] = BAH_OS;____BAH_COMPILER_VAR_1662[7] = "libs/";____BAH_COMPILER_VAR_1662[6] = BAH_DIR;____BAH_COMPILER_VAR_1662[5] = "/include/\" -L \"";____BAH_COMPILER_VAR_1662[4] = BAH_OS;____BAH_COMPILER_VAR_1662[3] = "libs/";____BAH_COMPILER_VAR_1662[2] = BAH_DIR;____BAH_COMPILER_VAR_1662[1] = " -I \"";____BAH_COMPILER_VAR_1662[0] = BAH_CC;char * ____BAH_COMPILER_VAR_1663 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1662, 14);char * gccArgs = ____BAH_COMPILER_VAR_1663;
array(char *)* cLibs = compilerState.cLibs;
register long int i = 0;
while ((i<len(cLibs))) {
char * l = cLibs->data[i];
char** ____BAH_COMPILER_VAR_1664 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1664[2] = l;____BAH_COMPILER_VAR_1664[1] = " -";____BAH_COMPILER_VAR_1664[0] = gccArgs;char * ____BAH_COMPILER_VAR_1665 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1664, 3);gccArgs = ____BAH_COMPILER_VAR_1665;
i = i+1;
};
char** ____BAH_COMPILER_VAR_1666 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1666[2] = "'\n";____BAH_COMPILER_VAR_1666[1] = gccArgs;____BAH_COMPILER_VAR_1666[0] = "//COMPILE WITH: '";char * ____BAH_COMPILER_VAR_1667 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1666, 3);OUTPUT = rope__add(rope(____BAH_COMPILER_VAR_1667), OUTPUT);
struct fileStream ____BAH_COMPILER_VAR_1668 = {};
struct fileStream fs = ____BAH_COMPILER_VAR_1668;
fileStream__open(&fs,fileName,"w");
char * ____BAH_COMPILER_VAR_1669 =rope__toStr(OUTPUT);fileStream__writeFile(&fs,____BAH_COMPILER_VAR_1669);
fileStream__close(&fs);
}
if ((isObject==false)) {
long int totalTime = getTimeUnix()-startTime;
char** ____BAH_COMPILER_VAR_1670 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1670[2] = "ms)\e[0m";____BAH_COMPILER_VAR_1670[1] = intToStr(totalTime/1000000);____BAH_COMPILER_VAR_1670[0] = "\e[1;32mDone. (compiled in ";char * ____BAH_COMPILER_VAR_1671 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1670, 3);println(____BAH_COMPILER_VAR_1671);
}
return 0;
};
volatile struct __Bah_fnName_mapper __tmp____Bah_fnNames[342];
    
    void __attribute__((optimize("O0"))) __BAH_init() {
        __BAH_panic_chan = null;
__Bah_fnNames = memoryAlloc(sizeof(array(struct __Bah_fnName_mapper)));

__Bah_fnNames->length = 0;
__Bah_fnNames->elemSize = sizeof(struct __Bah_fnName_mapper);
onMemoryError = null;
__Bah_init_segfaultHandle_OK = __Bah_init_segfaultHandle();
__Bah_iostream_stdinputBuffer = "";
__Bah_iostream_stdinputBufferLength = 0;
RAND_SEEDED = false;
BAH_DIR = "/opt/bah/";
BAH_OS = "linux";
BAH_CC = "gcc";
debug = false;
verboseRuntime = false;
isObject = false;
isUnsafe = false;
isOptimized = false;
noticeEnabled = true;
RAIIenabled = false;
isFixMeEnabled = false;
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

            __tmp____Bah_fnNames[70].n = "mapNode.calc";
            __tmp____Bah_fnNames[70].p = mapNode__calc;

            __tmp____Bah_fnNames[71].n = "mapNode.getFast";
            __tmp____Bah_fnNames[71].p = mapNode__getFast;

            __tmp____Bah_fnNames[72].n = "mapNode.append";
            __tmp____Bah_fnNames[72].p = mapNode__append;

            __tmp____Bah_fnNames[73].n = "mapWrapperSetAlgo";
            __tmp____Bah_fnNames[73].p = mapWrapperSetAlgo;

            __tmp____Bah_fnNames[74].n = "mapWrapper.algoChecks";
            __tmp____Bah_fnNames[74].p = mapWrapper__algoChecks;

            __tmp____Bah_fnNames[75].n = "mapWrapper.grow";
            __tmp____Bah_fnNames[75].p = mapWrapper__grow;

            __tmp____Bah_fnNames[76].n = "mapWrapper.set2";
            __tmp____Bah_fnNames[76].p = mapWrapper__set2;

            __tmp____Bah_fnNames[77].n = "mapWrapper.delete2";
            __tmp____Bah_fnNames[77].p = mapWrapper__delete2;

            __tmp____Bah_fnNames[78].n = "mapWrapper.get2";
            __tmp____Bah_fnNames[78].p = mapWrapper__get2;

            __tmp____Bah_fnNames[79].n = "mapWrapper.clearMsr";
            __tmp____Bah_fnNames[79].p = mapWrapper__clearMsr;

            __tmp____Bah_fnNames[80].n = "mapWrapper.get1";
            __tmp____Bah_fnNames[80].p = mapWrapper__get1;

            __tmp____Bah_fnNames[81].n = "mapWrapper.set1";
            __tmp____Bah_fnNames[81].p = mapWrapper__set1;

            __tmp____Bah_fnNames[82].n = "mapWrapper.delete1";
            __tmp____Bah_fnNames[82].p = mapWrapper__delete1;

            __tmp____Bah_fnNames[83].n = "mapWrapper.setAny";
            __tmp____Bah_fnNames[83].p = mapWrapper__setAny;

            __tmp____Bah_fnNames[84].n = "mapWrapper";
            __tmp____Bah_fnNames[84].p = mapWrapper;

            __tmp____Bah_fnNames[85].n = "deleteMap";
            __tmp____Bah_fnNames[85].p = deleteMap;

            __tmp____Bah_fnNames[86].n = "stdinput";
            __tmp____Bah_fnNames[86].p = stdinput;

            __tmp____Bah_fnNames[87].n = "println";
            __tmp____Bah_fnNames[87].p = println;

            __tmp____Bah_fnNames[88].n = "fileStream.isValid";
            __tmp____Bah_fnNames[88].p = fileStream__isValid;

            __tmp____Bah_fnNames[89].n = "fileStream.open";
            __tmp____Bah_fnNames[89].p = fileStream__open;

            __tmp____Bah_fnNames[90].n = "fileStream.close";
            __tmp____Bah_fnNames[90].p = fileStream__close;

            __tmp____Bah_fnNames[91].n = "fileStream.getPos";
            __tmp____Bah_fnNames[91].p = fileStream__getPos;

            __tmp____Bah_fnNames[92].n = "fileStream.setPos";
            __tmp____Bah_fnNames[92].p = fileStream__setPos;

            __tmp____Bah_fnNames[93].n = "fileStream.getSize";
            __tmp____Bah_fnNames[93].p = fileStream__getSize;

            __tmp____Bah_fnNames[94].n = "fileStream.rewind";
            __tmp____Bah_fnNames[94].p = fileStream__rewind;

            __tmp____Bah_fnNames[95].n = "fileStream.getChar";
            __tmp____Bah_fnNames[95].p = fileStream__getChar;

            __tmp____Bah_fnNames[96].n = "fileStream.setChar";
            __tmp____Bah_fnNames[96].p = fileStream__setChar;

            __tmp____Bah_fnNames[97].n = "fileStream.createFile";
            __tmp____Bah_fnNames[97].p = fileStream__createFile;

            __tmp____Bah_fnNames[98].n = "fileStream.writeFile";
            __tmp____Bah_fnNames[98].p = fileStream__writeFile;

            __tmp____Bah_fnNames[99].n = "fileStream.writePtr";
            __tmp____Bah_fnNames[99].p = fileStream__writePtr;

            __tmp____Bah_fnNames[100].n = "fileStream.readPtr";
            __tmp____Bah_fnNames[100].p = fileStream__readPtr;

            __tmp____Bah_fnNames[101].n = "fileStream.readContent";
            __tmp____Bah_fnNames[101].p = fileStream__readContent;

            __tmp____Bah_fnNames[102].n = "fileStream.readBytes";
            __tmp____Bah_fnNames[102].p = fileStream__readBytes;

            __tmp____Bah_fnNames[103].n = "fileStream.writeBytes";
            __tmp____Bah_fnNames[103].p = fileStream__writeBytes;

            __tmp____Bah_fnNames[104].n = "fileStream._end";
            __tmp____Bah_fnNames[104].p = fileStream___end;

            __tmp____Bah_fnNames[105].n = "fileMap.open";
            __tmp____Bah_fnNames[105].p = fileMap__open;

            __tmp____Bah_fnNames[106].n = "fileMap.isValid";
            __tmp____Bah_fnNames[106].p = fileMap__isValid;

            __tmp____Bah_fnNames[107].n = "fileMap.close";
            __tmp____Bah_fnNames[107].p = fileMap__close;

            __tmp____Bah_fnNames[108].n = "listFiles";
            __tmp____Bah_fnNames[108].p = listFiles;

            __tmp____Bah_fnNames[109].n = "fileExists";
            __tmp____Bah_fnNames[109].p = fileExists;

            __tmp____Bah_fnNames[110].n = "isFolder";
            __tmp____Bah_fnNames[110].p = isFolder;

            __tmp____Bah_fnNames[111].n = "removeFile";
            __tmp____Bah_fnNames[111].p = removeFile;

            __tmp____Bah_fnNames[112].n = "getLastModified";
            __tmp____Bah_fnNames[112].p = getLastModified;

            __tmp____Bah_fnNames[113].n = "strCatOffset";
            __tmp____Bah_fnNames[113].p = strCatOffset;

            __tmp____Bah_fnNames[114].n = "charToString";
            __tmp____Bah_fnNames[114].p = charToString;

            __tmp____Bah_fnNames[115].n = "isUpper";
            __tmp____Bah_fnNames[115].p = isUpper;

            __tmp____Bah_fnNames[116].n = "isLower";
            __tmp____Bah_fnNames[116].p = isLower;

            __tmp____Bah_fnNames[117].n = "isLetter";
            __tmp____Bah_fnNames[117].p = isLetter;

            __tmp____Bah_fnNames[118].n = "isNumber";
            __tmp____Bah_fnNames[118].p = isNumber;

            __tmp____Bah_fnNames[119].n = "isAlphaNumeric";
            __tmp____Bah_fnNames[119].p = isAlphaNumeric;

            __tmp____Bah_fnNames[120].n = "isSpace";
            __tmp____Bah_fnNames[120].p = isSpace;

            __tmp____Bah_fnNames[121].n = "string.set";
            __tmp____Bah_fnNames[121].p = string__set;

            __tmp____Bah_fnNames[122].n = "string.makeEditable";
            __tmp____Bah_fnNames[122].p = string__makeEditable;

            __tmp____Bah_fnNames[123].n = "string.append";
            __tmp____Bah_fnNames[123].p = string__append;

            __tmp____Bah_fnNames[124].n = "string.prepend";
            __tmp____Bah_fnNames[124].p = string__prepend;

            __tmp____Bah_fnNames[125].n = "string.charAt";
            __tmp____Bah_fnNames[125].p = string__charAt;

            __tmp____Bah_fnNames[126].n = "string.compare";
            __tmp____Bah_fnNames[126].p = string__compare;

            __tmp____Bah_fnNames[127].n = "string.str";
            __tmp____Bah_fnNames[127].p = string__str;

            __tmp____Bah_fnNames[128].n = "string.replace";
            __tmp____Bah_fnNames[128].p = string__replace;

            __tmp____Bah_fnNames[129].n = "string.countChar";
            __tmp____Bah_fnNames[129].p = string__countChar;

            __tmp____Bah_fnNames[130].n = "string.count";
            __tmp____Bah_fnNames[130].p = string__count;

            __tmp____Bah_fnNames[131].n = "string.hasPrefix";
            __tmp____Bah_fnNames[131].p = string__hasPrefix;

            __tmp____Bah_fnNames[132].n = "string.hasSuffix";
            __tmp____Bah_fnNames[132].p = string__hasSuffix;

            __tmp____Bah_fnNames[133].n = "string.trim";
            __tmp____Bah_fnNames[133].p = string__trim;

            __tmp____Bah_fnNames[134].n = "string.trimLeft";
            __tmp____Bah_fnNames[134].p = string__trimLeft;

            __tmp____Bah_fnNames[135].n = "string.trimRight";
            __tmp____Bah_fnNames[135].p = string__trimRight;

            __tmp____Bah_fnNames[136].n = "string.add";
            __tmp____Bah_fnNames[136].p = string__add;

            __tmp____Bah_fnNames[137].n = "string.asArr";
            __tmp____Bah_fnNames[137].p = string__asArr;

            __tmp____Bah_fnNames[138].n = "string";
            __tmp____Bah_fnNames[138].p = string;

            __tmp____Bah_fnNames[139].n = "intToStr";
            __tmp____Bah_fnNames[139].p = intToStr;

            __tmp____Bah_fnNames[140].n = "intToString";
            __tmp____Bah_fnNames[140].p = intToString;

            __tmp____Bah_fnNames[141].n = "floatToStr";
            __tmp____Bah_fnNames[141].p = floatToStr;

            __tmp____Bah_fnNames[142].n = "strToInt";
            __tmp____Bah_fnNames[142].p = strToInt;

            __tmp____Bah_fnNames[143].n = "strToFloat";
            __tmp____Bah_fnNames[143].p = strToFloat;

            __tmp____Bah_fnNames[144].n = "stringToInt";
            __tmp____Bah_fnNames[144].p = stringToInt;

            __tmp____Bah_fnNames[145].n = "splitString";
            __tmp____Bah_fnNames[145].p = splitString;

            __tmp____Bah_fnNames[146].n = "joinString";
            __tmp____Bah_fnNames[146].p = joinString;

            __tmp____Bah_fnNames[147].n = "splitStringBefore";
            __tmp____Bah_fnNames[147].p = splitStringBefore;

            __tmp____Bah_fnNames[148].n = "toLower";
            __tmp____Bah_fnNames[148].p = toLower;

            __tmp____Bah_fnNames[149].n = "strHasPrefix";
            __tmp____Bah_fnNames[149].p = strHasPrefix;

            __tmp____Bah_fnNames[150].n = "strHasSuffix";
            __tmp____Bah_fnNames[150].p = strHasSuffix;

            __tmp____Bah_fnNames[151].n = "strTrim";
            __tmp____Bah_fnNames[151].p = strTrim;

            __tmp____Bah_fnNames[152].n = "strCount";
            __tmp____Bah_fnNames[152].p = strCount;

            __tmp____Bah_fnNames[153].n = "flags.addString";
            __tmp____Bah_fnNames[153].p = flags__addString;

            __tmp____Bah_fnNames[154].n = "flags.addBool";
            __tmp____Bah_fnNames[154].p = flags__addBool;

            __tmp____Bah_fnNames[155].n = "flags.addInt";
            __tmp____Bah_fnNames[155].p = flags__addInt;

            __tmp____Bah_fnNames[156].n = "flags.addFloat";
            __tmp____Bah_fnNames[156].p = flags__addFloat;

            __tmp____Bah_fnNames[157].n = "flags.invalidate";
            __tmp____Bah_fnNames[157].p = flags__invalidate;

            __tmp____Bah_fnNames[158].n = "flags.getFlag";
            __tmp____Bah_fnNames[158].p = flags__getFlag;

            __tmp____Bah_fnNames[159].n = "flags.get";
            __tmp____Bah_fnNames[159].p = flags__get;

            __tmp____Bah_fnNames[160].n = "flags.getInt";
            __tmp____Bah_fnNames[160].p = flags__getInt;

            __tmp____Bah_fnNames[161].n = "flags.getFloat";
            __tmp____Bah_fnNames[161].p = flags__getFloat;

            __tmp____Bah_fnNames[162].n = "flags.isSet";
            __tmp____Bah_fnNames[162].p = flags__isSet;

            __tmp____Bah_fnNames[163].n = "flags.parse";
            __tmp____Bah_fnNames[163].p = flags__parse;

            __tmp____Bah_fnNames[164].n = "time.now";
            __tmp____Bah_fnNames[164].p = time__now;

            __tmp____Bah_fnNames[165].n = "time.format";
            __tmp____Bah_fnNames[165].p = time__format;

            __tmp____Bah_fnNames[166].n = "time.since";
            __tmp____Bah_fnNames[166].p = time__since;

            __tmp____Bah_fnNames[167].n = "getTimeUnix";
            __tmp____Bah_fnNames[167].p = getTimeUnix;

            __tmp____Bah_fnNames[168].n = "seedRandom";
            __tmp____Bah_fnNames[168].p = seedRandom;

            __tmp____Bah_fnNames[169].n = "randomInRange";
            __tmp____Bah_fnNames[169].p = randomInRange;

            __tmp____Bah_fnNames[170].n = "cryptoRand";
            __tmp____Bah_fnNames[170].p = cryptoRand;

            __tmp____Bah_fnNames[171].n = "rope.addStr";
            __tmp____Bah_fnNames[171].p = rope__addStr;

            __tmp____Bah_fnNames[172].n = "rope.toStr";
            __tmp____Bah_fnNames[172].p = rope__toStr;

            __tmp____Bah_fnNames[173].n = "rope.add";
            __tmp____Bah_fnNames[173].p = rope__add;

            __tmp____Bah_fnNames[174].n = "createRopeStructure";
            __tmp____Bah_fnNames[174].p = createRopeStructure;

            __tmp____Bah_fnNames[175].n = "ropeSet";
            __tmp____Bah_fnNames[175].p = ropeSet;

            __tmp____Bah_fnNames[176].n = "concatenateRopes";
            __tmp____Bah_fnNames[176].p = concatenateRopes;

            __tmp____Bah_fnNames[177].n = "rope";
            __tmp____Bah_fnNames[177].p = rope;

            __tmp____Bah_fnNames[178].n = "command.run";
            __tmp____Bah_fnNames[178].p = command__run;

            __tmp____Bah_fnNames[179].n = "command.runBytes";
            __tmp____Bah_fnNames[179].p = command__runBytes;

            __tmp____Bah_fnNames[180].n = "command";
            __tmp____Bah_fnNames[180].p = command;

            __tmp____Bah_fnNames[181].n = "exec";
            __tmp____Bah_fnNames[181].p = exec;

            __tmp____Bah_fnNames[182].n = "inArray";
            __tmp____Bah_fnNames[182].p = inArray;

            __tmp____Bah_fnNames[183].n = "inArrayStr";
            __tmp____Bah_fnNames[183].p = inArrayStr;

            __tmp____Bah_fnNames[184].n = "makeToken";
            __tmp____Bah_fnNames[184].p = makeToken;

            __tmp____Bah_fnNames[185].n = "isMinus";
            __tmp____Bah_fnNames[185].p = isMinus;

            __tmp____Bah_fnNames[186].n = "lexerErr";
            __tmp____Bah_fnNames[186].p = lexerErr;

            __tmp____Bah_fnNames[187].n = "lexer";
            __tmp____Bah_fnNames[187].p = lexer;

            __tmp____Bah_fnNames[188].n = "hasStructSep";
            __tmp____Bah_fnNames[188].p = hasStructSep;

            __tmp____Bah_fnNames[189].n = "splitStructSepBefore";
            __tmp____Bah_fnNames[189].p = splitStructSepBefore;

            __tmp____Bah_fnNames[190].n = "splitStructSepAfter";
            __tmp____Bah_fnNames[190].p = splitStructSepAfter;

            __tmp____Bah_fnNames[191].n = "searchStruct";
            __tmp____Bah_fnNames[191].p = searchStruct;

            __tmp____Bah_fnNames[192].n = "searchStructMemb";
            __tmp____Bah_fnNames[192].p = searchStructMemb;

            __tmp____Bah_fnNames[193].n = "searchFunc";
            __tmp____Bah_fnNames[193].p = searchFunc;

            __tmp____Bah_fnNames[194].n = "parseFnType";
            __tmp____Bah_fnNames[194].p = parseFnType;

            __tmp____Bah_fnNames[195].n = "searchStructMethod";
            __tmp____Bah_fnNames[195].p = searchStructMethod;

            __tmp____Bah_fnNames[196].n = "typeAsStar";
            __tmp____Bah_fnNames[196].p = typeAsStar;

            __tmp____Bah_fnNames[197].n = "isRCPpointerType";
            __tmp____Bah_fnNames[197].p = isRCPpointerType;

            __tmp____Bah_fnNames[198].n = "isRCPtype";
            __tmp____Bah_fnNames[198].p = isRCPtype;

            __tmp____Bah_fnNames[199].n = "getCType";
            __tmp____Bah_fnNames[199].p = getCType;

            __tmp____Bah_fnNames[200].n = "maybeToPtr";
            __tmp____Bah_fnNames[200].p = maybeToPtr;

            __tmp____Bah_fnNames[201].n = "compTypeEquiv";
            __tmp____Bah_fnNames[201].p = compTypeEquiv;

            __tmp____Bah_fnNames[202].n = "compTypes";
            __tmp____Bah_fnNames[202].p = compTypes;

            __tmp____Bah_fnNames[203].n = "reflectElement.calculateOffset";
            __tmp____Bah_fnNames[203].p = reflectElement__calculateOffset;

            __tmp____Bah_fnNames[204].n = "__reflect";
            __tmp____Bah_fnNames[204].p = __reflect;

            __tmp____Bah_fnNames[205].n = "__dumpSymbols";
            __tmp____Bah_fnNames[205].p = __dumpSymbols;

            __tmp____Bah_fnNames[206].n = "__debug_get_sym";
            __tmp____Bah_fnNames[206].p = __debug_get_sym;

            __tmp____Bah_fnNames[207].n = "toJson";
            __tmp____Bah_fnNames[207].p = toJson;

            __tmp____Bah_fnNames[208].n = "json_scan_inner";
            __tmp____Bah_fnNames[208].p = json_scan_inner;

            __tmp____Bah_fnNames[209].n = "jsonElement.get";
            __tmp____Bah_fnNames[209].p = jsonElement__get;

            __tmp____Bah_fnNames[210].n = "jsonElement.str";
            __tmp____Bah_fnNames[210].p = jsonElement__str;

            __tmp____Bah_fnNames[211].n = "jsonElement.scan";
            __tmp____Bah_fnNames[211].p = jsonElement__scan;

            __tmp____Bah_fnNames[212].n = "parseJson";
            __tmp____Bah_fnNames[212].p = parseJson;

            __tmp____Bah_fnNames[213].n = "json_isPrintable";
            __tmp____Bah_fnNames[213].p = json_isPrintable;

            __tmp____Bah_fnNames[214].n = "jsonEscapeStr";
            __tmp____Bah_fnNames[214].p = jsonEscapeStr;

            __tmp____Bah_fnNames[215].n = "oldToJson__inner";
            __tmp____Bah_fnNames[215].p = oldToJson__inner;

            __tmp____Bah_fnNames[216].n = "oldToJson";
            __tmp____Bah_fnNames[216].p = oldToJson;

            __tmp____Bah_fnNames[217].n = "debugStart";
            __tmp____Bah_fnNames[217].p = debugStart;

            __tmp____Bah_fnNames[218].n = "debugPrint";
            __tmp____Bah_fnNames[218].p = debugPrint;

            __tmp____Bah_fnNames[219].n = "debugError";
            __tmp____Bah_fnNames[219].p = debugError;

            __tmp____Bah_fnNames[220].n = "debugEnd";
            __tmp____Bah_fnNames[220].p = debugEnd;

            __tmp____Bah_fnNames[221].n = "debugExit";
            __tmp____Bah_fnNames[221].p = debugExit;

            __tmp____Bah_fnNames[222].n = "debugEndScope";
            __tmp____Bah_fnNames[222].p = debugEndScope;

            __tmp____Bah_fnNames[223].n = "advertiseGeneric";
            __tmp____Bah_fnNames[223].p = advertiseGeneric;

            __tmp____Bah_fnNames[224].n = "throwErr";
            __tmp____Bah_fnNames[224].p = throwErr;

            __tmp____Bah_fnNames[225].n = "throwWarning";
            __tmp____Bah_fnNames[225].p = throwWarning;

            __tmp____Bah_fnNames[226].n = "throwWarningLine";
            __tmp____Bah_fnNames[226].p = throwWarningLine;

            __tmp____Bah_fnNames[227].n = "throwNoticeLine";
            __tmp____Bah_fnNames[227].p = throwNoticeLine;

            __tmp____Bah_fnNames[228].n = "absPath";
            __tmp____Bah_fnNames[228].p = absPath;

            __tmp____Bah_fnNames[229].n = "getCurrentPath";
            __tmp____Bah_fnNames[229].p = getCurrentPath;

            __tmp____Bah_fnNames[230].n = "isInside";
            __tmp____Bah_fnNames[230].p = isInside;

            __tmp____Bah_fnNames[231].n = "setCurrentPath";
            __tmp____Bah_fnNames[231].p = setCurrentPath;

            __tmp____Bah_fnNames[232].n = "isGlobal";
            __tmp____Bah_fnNames[232].p = isGlobal;

            __tmp____Bah_fnNames[233].n = "getRealVar";
            __tmp____Bah_fnNames[233].p = getRealVar;

            __tmp____Bah_fnNames[234].n = "removeVarUnar";
            __tmp____Bah_fnNames[234].p = removeVarUnar;

            __tmp____Bah_fnNames[235].n = "searchVar";
            __tmp____Bah_fnNames[235].p = searchVar;

            __tmp____Bah_fnNames[236].n = "searchVarByToken";
            __tmp____Bah_fnNames[236].p = searchVarByToken;

            __tmp____Bah_fnNames[237].n = "searchVirtVarByToken";
            __tmp____Bah_fnNames[237].p = searchVirtVarByToken;

            __tmp____Bah_fnNames[238].n = "setCType";
            __tmp____Bah_fnNames[238].p = setCType;

            __tmp____Bah_fnNames[239].n = "isMissingVar";
            __tmp____Bah_fnNames[239].p = isMissingVar;

            __tmp____Bah_fnNames[240].n = "getTypeFromToken";
            __tmp____Bah_fnNames[240].p = getTypeFromToken;

            __tmp____Bah_fnNames[241].n = "searchFuncByToken";
            __tmp____Bah_fnNames[241].p = searchFuncByToken;

            __tmp____Bah_fnNames[242].n = "RCPavailable";
            __tmp____Bah_fnNames[242].p = RCPavailable;

            __tmp____Bah_fnNames[243].n = "declareStructMethods";
            __tmp____Bah_fnNames[243].p = declareStructMethods;

            __tmp____Bah_fnNames[244].n = "genCompilerVar";
            __tmp____Bah_fnNames[244].p = genCompilerVar;

            __tmp____Bah_fnNames[245].n = "varInArr";
            __tmp____Bah_fnNames[245].p = varInArr;

            __tmp____Bah_fnNames[246].n = "pathToVarName";
            __tmp____Bah_fnNames[246].p = pathToVarName;

            __tmp____Bah_fnNames[247].n = "makeInit";
            __tmp____Bah_fnNames[247].p = makeInit;

            __tmp____Bah_fnNames[248].n = "checkedNull";
            __tmp____Bah_fnNames[248].p = checkedNull;

            __tmp____Bah_fnNames[249].n = "checkedNotNull";
            __tmp____Bah_fnNames[249].p = checkedNotNull;

            __tmp____Bah_fnNames[250].n = "canChangeNullState";
            __tmp____Bah_fnNames[250].p = canChangeNullState;

            __tmp____Bah_fnNames[251].n = "removeCast";
            __tmp____Bah_fnNames[251].p = removeCast;

            __tmp____Bah_fnNames[252].n = "isOutterScope";
            __tmp____Bah_fnNames[252].p = isOutterScope;

            __tmp____Bah_fnNames[253].n = "decrVar";
            __tmp____Bah_fnNames[253].p = decrVar;

            __tmp____Bah_fnNames[254].n = "incrVar";
            __tmp____Bah_fnNames[254].p = incrVar;

            __tmp____Bah_fnNames[255].n = "beginRCPscope";
            __tmp____Bah_fnNames[255].p = beginRCPscope;

            __tmp____Bah_fnNames[256].n = "beginRCPscopeLeaky";
            __tmp____Bah_fnNames[256].p = beginRCPscopeLeaky;

            __tmp____Bah_fnNames[257].n = "endRCPscope";
            __tmp____Bah_fnNames[257].p = endRCPscope;

            __tmp____Bah_fnNames[258].n = "endRCPscopeLeaky";
            __tmp____Bah_fnNames[258].p = endRCPscopeLeaky;

            __tmp____Bah_fnNames[259].n = "registerRCPvar";
            __tmp____Bah_fnNames[259].p = registerRCPvar;

            __tmp____Bah_fnNames[260].n = "RCPselfRef";
            __tmp____Bah_fnNames[260].p = RCPselfRef;

            __tmp____Bah_fnNames[261].n = "verboseOutGuard";
            __tmp____Bah_fnNames[261].p = verboseOutGuard;

            __tmp____Bah_fnNames[262].n = "verboseOutTransformVar";
            __tmp____Bah_fnNames[262].p = verboseOutTransformVar;

            __tmp____Bah_fnNames[263].n = "verboseOutTransformTok";
            __tmp____Bah_fnNames[263].p = verboseOutTransformTok;

            __tmp____Bah_fnNames[264].n = "verboseOutFunc";
            __tmp____Bah_fnNames[264].p = verboseOutFunc;

            __tmp____Bah_fnNames[265].n = "verboseOutOper";
            __tmp____Bah_fnNames[265].p = verboseOutOper;

            __tmp____Bah_fnNames[266].n = "readCache";
            __tmp____Bah_fnNames[266].p = readCache;

            __tmp____Bah_fnNames[267].n = "getCacheFile";
            __tmp____Bah_fnNames[267].p = getCacheFile;

            __tmp____Bah_fnNames[268].n = "updateCacheFile";
            __tmp____Bah_fnNames[268].p = updateCacheFile;

            __tmp____Bah_fnNames[269].n = "makeCacheFile";
            __tmp____Bah_fnNames[269].p = makeCacheFile;

            __tmp____Bah_fnNames[270].n = "writeCache";
            __tmp____Bah_fnNames[270].p = writeCache;

            __tmp____Bah_fnNames[271].n = "isValidCacheFile";
            __tmp____Bah_fnNames[271].p = isValidCacheFile;

            __tmp____Bah_fnNames[272].n = "genArrRealloc";
            __tmp____Bah_fnNames[272].p = genArrRealloc;

            __tmp____Bah_fnNames[273].n = "genConcat";
            __tmp____Bah_fnNames[273].p = genConcat;

            __tmp____Bah_fnNames[274].n = "OPTI_checkFuncScopeRef";
            __tmp____Bah_fnNames[274].p = OPTI_checkFuncScopeRef;

            __tmp____Bah_fnNames[275].n = "isExprExpensive";
            __tmp____Bah_fnNames[275].p = isExprExpensive;

            __tmp____Bah_fnNames[276].n = "byteToOctal";
            __tmp____Bah_fnNames[276].p = byteToOctal;

            __tmp____Bah_fnNames[277].n = "escapeIntOctal";
            __tmp____Bah_fnNames[277].p = escapeIntOctal;

            __tmp____Bah_fnNames[278].n = "getStrLen";
            __tmp____Bah_fnNames[278].p = getStrLen;

            __tmp____Bah_fnNames[279].n = "strLitteralToBahStr";
            __tmp____Bah_fnNames[279].p = strLitteralToBahStr;

            __tmp____Bah_fnNames[280].n = "dupElems";
            __tmp____Bah_fnNames[280].p = dupElems;

            __tmp____Bah_fnNames[281].n = "parseLines";
            __tmp____Bah_fnNames[281].p = parseLines;

            __tmp____Bah_fnNames[282].n = "genericFunc.dupBaseFn";
            __tmp____Bah_fnNames[282].p = genericFunc__dupBaseFn;

            __tmp____Bah_fnNames[283].n = "genericFunc.setCurrGeneric";
            __tmp____Bah_fnNames[283].p = genericFunc__setCurrGeneric;

            __tmp____Bah_fnNames[284].n = "genericFunc.isAlreadyDecl";
            __tmp____Bah_fnNames[284].p = genericFunc__isAlreadyDecl;

            __tmp____Bah_fnNames[285].n = "genericFunc.declare";
            __tmp____Bah_fnNames[285].p = genericFunc__declare;

            __tmp____Bah_fnNames[286].n = "debugLine";
            __tmp____Bah_fnNames[286].p = debugLine;

            __tmp____Bah_fnNames[287].n = "checkCanBeNull";
            __tmp____Bah_fnNames[287].p = checkCanBeNull;

            __tmp____Bah_fnNames[288].n = "setNullStateBranchFlowEnd";
            __tmp____Bah_fnNames[288].p = setNullStateBranchFlowEnd;

            __tmp____Bah_fnNames[289].n = "fixMeEnabled";
            __tmp____Bah_fnNames[289].p = fixMeEnabled;

            __tmp____Bah_fnNames[290].n = "fixMeRegisterVar";
            __tmp____Bah_fnNames[290].p = fixMeRegisterVar;

            __tmp____Bah_fnNames[291].n = "fixMeEndScope";
            __tmp____Bah_fnNames[291].p = fixMeEndScope;

            __tmp____Bah_fnNames[292].n = "fixMeTestVar";
            __tmp____Bah_fnNames[292].p = fixMeTestVar;

            __tmp____Bah_fnNames[293].n = "getLineType";
            __tmp____Bah_fnNames[293].p = getLineType;

            __tmp____Bah_fnNames[294].n = "parseCast";
            __tmp____Bah_fnNames[294].p = parseCast;

            __tmp____Bah_fnNames[295].n = "getDirFromFile";
            __tmp____Bah_fnNames[295].p = getDirFromFile;

            __tmp____Bah_fnNames[296].n = "includeFile";
            __tmp____Bah_fnNames[296].p = includeFile;

            __tmp____Bah_fnNames[297].n = "parallelObjCompile";
            __tmp____Bah_fnNames[297].p = parallelObjCompile;

            __tmp____Bah_fnNames[298].n = "parseImport";
            __tmp____Bah_fnNames[298].p = parseImport;

            __tmp____Bah_fnNames[299].n = "parseInclude";
            __tmp____Bah_fnNames[299].p = parseInclude;

            __tmp____Bah_fnNames[300].n = "prePross";
            __tmp____Bah_fnNames[300].p = prePross;

            __tmp____Bah_fnNames[301].n = "parseStructType";
            __tmp____Bah_fnNames[301].p = parseStructType;

            __tmp____Bah_fnNames[302].n = "parseArrayType";
            __tmp____Bah_fnNames[302].p = parseArrayType;

            __tmp____Bah_fnNames[303].n = "parsePointers";
            __tmp____Bah_fnNames[303].p = parsePointers;

            __tmp____Bah_fnNames[304].n = "parseSerialize";
            __tmp____Bah_fnNames[304].p = parseSerialize;

            __tmp____Bah_fnNames[305].n = "parseReflect";
            __tmp____Bah_fnNames[305].p = parseReflect;

            __tmp____Bah_fnNames[306].n = "parseArrayDecl";
            __tmp____Bah_fnNames[306].p = parseArrayDecl;

            __tmp____Bah_fnNames[307].n = "parseVar";
            __tmp____Bah_fnNames[307].p = parseVar;

            __tmp____Bah_fnNames[308].n = "getCfunctionType";
            __tmp____Bah_fnNames[308].p = getCfunctionType;

            __tmp____Bah_fnNames[309].n = "parseFnHeader";
            __tmp____Bah_fnNames[309].p = parseFnHeader;

            __tmp____Bah_fnNames[310].n = "parseStruct";
            __tmp____Bah_fnNames[310].p = parseStruct;

            __tmp____Bah_fnNames[311].n = "parseDefine";
            __tmp____Bah_fnNames[311].p = parseDefine;

            __tmp____Bah_fnNames[312].n = "parseClib";
            __tmp____Bah_fnNames[312].p = parseClib;

            __tmp____Bah_fnNames[313].n = "parseConst";
            __tmp____Bah_fnNames[313].p = parseConst;

            __tmp____Bah_fnNames[314].n = "parseReturn";
            __tmp____Bah_fnNames[314].p = parseReturn;

            __tmp____Bah_fnNames[315].n = "parseIf";
            __tmp____Bah_fnNames[315].p = parseIf;

            __tmp____Bah_fnNames[316].n = "parseElse";
            __tmp____Bah_fnNames[316].p = parseElse;

            __tmp____Bah_fnNames[317].n = "parseLine";
            __tmp____Bah_fnNames[317].p = parseLine;

            __tmp____Bah_fnNames[318].n = "parseFor";
            __tmp____Bah_fnNames[318].p = parseFor;

            __tmp____Bah_fnNames[319].n = "parseForOp";
            __tmp____Bah_fnNames[319].p = parseForOp;

            __tmp____Bah_fnNames[320].n = "makeEvalFunc";
            __tmp____Bah_fnNames[320].p = makeEvalFunc;

            __tmp____Bah_fnNames[321].n = "parsePreKeyword";
            __tmp____Bah_fnNames[321].p = parsePreKeyword;

            __tmp____Bah_fnNames[322].n = "parseAsync";
            __tmp____Bah_fnNames[322].p = parseAsync;

            __tmp____Bah_fnNames[323].n = "addRCPvars";
            __tmp____Bah_fnNames[323].p = addRCPvars;

            __tmp____Bah_fnNames[324].n = "parseChan";
            __tmp____Bah_fnNames[324].p = parseChan;

            __tmp____Bah_fnNames[325].n = "valueFunc";
            __tmp____Bah_fnNames[325].p = valueFunc;

            __tmp____Bah_fnNames[326].n = "valueStruct";
            __tmp____Bah_fnNames[326].p = valueStruct;

            __tmp____Bah_fnNames[327].n = "valueArr";
            __tmp____Bah_fnNames[327].p = valueArr;

            __tmp____Bah_fnNames[328].n = "valueBool";
            __tmp____Bah_fnNames[328].p = valueBool;

            __tmp____Bah_fnNames[329].n = "valueOper";
            __tmp____Bah_fnNames[329].p = valueOper;

            __tmp____Bah_fnNames[330].n = "valueSendChan";
            __tmp____Bah_fnNames[330].p = valueSendChan;

            __tmp____Bah_fnNames[331].n = "valueChan";
            __tmp____Bah_fnNames[331].p = valueChan;

            __tmp____Bah_fnNames[332].n = "valueTuple";
            __tmp____Bah_fnNames[332].p = valueTuple;

            __tmp____Bah_fnNames[333].n = "isSmallValue";
            __tmp____Bah_fnNames[333].p = isSmallValue;

            __tmp____Bah_fnNames[334].n = "isValue";
            __tmp____Bah_fnNames[334].p = isValue;

            __tmp____Bah_fnNames[335].n = "parseFnDeclare";
            __tmp____Bah_fnNames[335].p = parseFnDeclare;

            __tmp____Bah_fnNames[336].n = "parseCapture";
            __tmp____Bah_fnNames[336].p = parseCapture;

            __tmp____Bah_fnNames[337].n = "declareFunc";
            __tmp____Bah_fnNames[337].p = declareFunc;

            __tmp____Bah_fnNames[338].n = "declareVar";
            __tmp____Bah_fnNames[338].p = declareVar;

            __tmp____Bah_fnNames[339].n = "declareAll";
            __tmp____Bah_fnNames[339].p = declareAll;

            __tmp____Bah_fnNames[340].n = "memErrHandle";
            __tmp____Bah_fnNames[340].p = memErrHandle;

            __tmp____Bah_fnNames[341].n = "main";
            __tmp____Bah_fnNames[341].p = main;

        __Bah_fnNames->data = __tmp____Bah_fnNames;
        __Bah_fnNames->length = 342;
        
    };
    