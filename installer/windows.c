//COMPILE WITH: 'x86_64-w64-mingw32-gcc -I "/opt/bah/libs/windows/include/" -L "/opt/bah/libs/windows/" ../installer/windows.c -static -O1 -w  -l:gc.a -lpthread -lm'

    void __BAH_init();
    #define noCheck(v) v
    #define array(type)	    struct{	    type *data;     long int length;     long int elemSize;     }
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
if (((void *)a==null)) {
a = "";
}
if (((void *)b==null)) {
b = "";
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
long int i = 0;
array(void*)*arr=a;
i=arr->length;
return i;
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
destroy(arr->data);
arr->data=memoryAlloc(sizeof(0));
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
if ((GLOBAL_MAPPED_MEMORY_FILE==null)) {
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
sarr->data = memoryAlloc(sizeof(char) * 50);sarr->data[0] = data->data[0];
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
i++;
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
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
void print(char * s){
write((void *)1,s,strlen(s));
};
void * cArr(void * arr){
array(void*)*a=arr;
return a->data;
};
char __checkString(char * s,char * l){
if (((void *)s==null)) {
char * ____BAH_COMPILER_VAR_0 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(l);
long int strLen_1 = strlen(") is null \n");
long int strLen_2 = strlen("cpstring (");
;                            
            ____BAH_COMPILER_VAR_0 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_0+currStrOff, "cpstring (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_0+currStrOff, l, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_0+currStrOff, ") is null \n", strLen_1);
            currStrOff += strLen_1;
        
        }print(____BAH_COMPILER_VAR_0);
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
void(*init)(struct mutex* this);
void(*lock)(struct mutex* this);
void(*unlock)(struct mutex* this);
void(*destroy)(struct mutex* this);
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
void(*init)(struct mutexCondition* this);
void(*wait)(struct mutexCondition* this,struct mutex m);
void(*send)(struct mutexCondition* this);
void(*destroy)(struct mutexCondition* this);
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
struct mutexCondition ____BAH_COMPILER_VAR_1 = {};
____BAH_COMPILER_VAR_1.init = mutexCondition__init;
____BAH_COMPILER_VAR_1.wait = mutexCondition__wait;
____BAH_COMPILER_VAR_1.send = mutexCondition__send;
____BAH_COMPILER_VAR_1.destroy = mutexCondition__destroy;
#define m ____BAH_COMPILER_VAR_1
m.init(&m);
return m;
};
struct thread {
pthread_t id;
void (*handle)(void *);
void(*create)(struct thread* this);
void(*createWithArg)(struct thread* this,void * arg);
void(*wait)(struct thread* this);
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
struct mutex ____BAH_COMPILER_VAR_2 = {};
____BAH_COMPILER_VAR_2.init = mutex__init;
____BAH_COMPILER_VAR_2.lock = mutex__lock;
____BAH_COMPILER_VAR_2.unlock = mutex__unlock;
____BAH_COMPILER_VAR_2.destroy = mutex__destroy;
#define m ____BAH_COMPILER_VAR_2
m.init(&m);
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
void(*insert)(struct queue* this,void * data);
void(*delete)(struct queue* this,long int key);
void *(*get)(struct queue* this,long int key);
void(*set)(struct queue* this,long int key,void * data);
void *(*pop)(struct queue* this);
void(*clear)(struct queue* this);
};
void queue__insert(struct queue* this,void * data){
struct queueNode* ____BAH_COMPILER_VAR_3 = memoryAlloc(sizeof(struct queueNode));
____BAH_COMPILER_VAR_3->data= null;
____BAH_COMPILER_VAR_3->next= null;
____BAH_COMPILER_VAR_3->prev= null;
____BAH_COMPILER_VAR_3->key = this->length;
____BAH_COMPILER_VAR_3->data = data;
____BAH_COMPILER_VAR_3->prev = this->end;
struct queueNode* node = ____BAH_COMPILER_VAR_3;
this->length++;
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
this->delete(this,key);
struct queueNode* ____BAH_COMPILER_VAR_4 = memoryAlloc(sizeof(struct queueNode));
____BAH_COMPILER_VAR_4->data= null;
____BAH_COMPILER_VAR_4->next= null;
____BAH_COMPILER_VAR_4->prev= null;
struct queueNode* node = ____BAH_COMPILER_VAR_4;
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
this->length--;
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
void(*send)(struct channel* this,void * data);
void(*sendAny)(struct channel* this,void * data,long int len);
void *(*receive)(struct channel* this);
void(*destroy)(struct channel* this);
long int(*len)(struct channel* this);
};
void channel__send(struct channel* this,void * data){
pthread_mutex_lock(&this->m_mut);
if ((this->cap!=-1)) {
while ((this->queue->length==this->cap)) {
this->w_waitting++;
pthread_cond_wait(&this->w_cond,&this->m_mut);
this->w_waitting--;
};
}
this->queue->insert(this->queue,data);
if ((this->r_waitting>0)) {
pthread_cond_signal(&this->r_cond);
}
pthread_mutex_unlock(&this->m_mut);
};
void channel__sendAny(struct channel* this,void * data,long int len){
pthread_mutex_lock(&this->m_mut);
if ((this->cap!=-1)) {
while ((this->queue->length==this->cap)) {
this->w_waitting++;
pthread_cond_wait(&this->w_cond,&this->m_mut);
this->w_waitting--;
};
}
void * p = memoryAlloc(len);
memcpy(p,data,len);
this->queue->insert(this->queue,p);
if ((this->r_waitting>0)) {
pthread_cond_signal(&this->r_cond);
}
pthread_mutex_unlock(&this->m_mut);
};
void * channel__receive(struct channel* this){
pthread_mutex_lock(&this->m_mut);
while ((this->queue->length==0)) {
this->r_waitting++;
pthread_cond_wait(&this->r_cond,&this->m_mut);
this->r_waitting--;
};
void * data = this->queue->pop(this->queue);
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
struct channel* ____BAH_COMPILER_VAR_5 = memoryAlloc(sizeof(struct channel));
____BAH_COMPILER_VAR_5->w_waitting = 0;
____BAH_COMPILER_VAR_5->r_waitting = 0;
____BAH_COMPILER_VAR_5->queue= null;
____BAH_COMPILER_VAR_5->cap = -1;
____BAH_COMPILER_VAR_5->send = channel__send;
____BAH_COMPILER_VAR_5->sendAny = channel__sendAny;
____BAH_COMPILER_VAR_5->receive = channel__receive;
____BAH_COMPILER_VAR_5->destroy = channel__destroy;
____BAH_COMPILER_VAR_5->len = channel__len;
struct channel* c = ____BAH_COMPILER_VAR_5;
pthread_mutex_init(&c->m_mut,0);
pthread_cond_init(&c->w_cond,0);
pthread_cond_init(&c->r_cond,0);
struct queue* ____BAH_COMPILER_VAR_6 = memoryAlloc(sizeof(struct queue));
____BAH_COMPILER_VAR_6->length = 0;
____BAH_COMPILER_VAR_6->head = null;
____BAH_COMPILER_VAR_6->end = null;
____BAH_COMPILER_VAR_6->insert = queue__insert;
____BAH_COMPILER_VAR_6->delete = queue__delete;
____BAH_COMPILER_VAR_6->get = queue__get;
____BAH_COMPILER_VAR_6->set = queue__set;
____BAH_COMPILER_VAR_6->pop = queue__pop;
____BAH_COMPILER_VAR_6->clear = queue__clear;
c->queue = ____BAH_COMPILER_VAR_6;
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

{
long nLength = len(__Bah_fnNames);
if (__Bah_fnNames->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(__Bah_fnNames->data, (nLength+50)*sizeof(struct __Bah_fnName_mapper));
__Bah_fnNames->data = newPtr;
}
__Bah_fnNames->data[len(__Bah_fnNames)] = fnn;
__Bah_fnNames->length = nLength+1;
} else {
__Bah_fnNames->data[len(__Bah_fnNames)] = fnn;
}
};
};
void __BAH_panic(char * e,char * line){
if ((__BAH_panic_chan!=null)) {
__BAH_panic_chan->send(__BAH_panic_chan, e);
return;
}
char * ____BAH_COMPILER_VAR_7 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(e);
long int strLen_1 = strlen("\n");
long int strLen_2 = strlen("): ");
long int strLen_3 = strlen(line);
long int strLen_4 = strlen("panic (");
;                            
            ____BAH_COMPILER_VAR_7 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_7+currStrOff, "panic (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_7+currStrOff, line, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_7+currStrOff, "): ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_7+currStrOff, e, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_7+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }print(____BAH_COMPILER_VAR_7);
cleanShutDown();
};
char * (*onMemoryError)();
void __Bah_segfault_handle(long int sig){
char * res = "";
if ((onMemoryError!=null)) {
res = onMemoryError();
}
char * ____BAH_COMPILER_VAR_8 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("Memory error (segfault).\n");
long int strLen_1 = strlen(res);
;                            
            ____BAH_COMPILER_VAR_8 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_8+currStrOff, "Memory error (segfault).\n", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_8+currStrOff, res, strLen_1);
            currStrOff += strLen_1;
        
        }__BAH_panic(____BAH_COMPILER_VAR_8,"???");
};
char __Bah_init_segfaultHandle(){
signal(SIGSEGV,__Bah_segfault_handle);
return true;
};
char __Bah_init_segfaultHandle_OK;
char recover(char ** s){
__BAH_panic_chan = channel();
char * err = (char *)__BAH_panic_chan->receive(__BAH_panic_chan);
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

{
long nLength = 47;
if (a->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(a->data, (nLength+50)*sizeof(char));
a->data = newPtr;
}
a->data[47] = 46;
a->length = nLength+1;
} else {
a->data[47] = 46;
}
};

{
long nLength = 48;
if (a->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(a->data, (nLength+50)*sizeof(char));
a->data = newPtr;
}
a->data[48] = 46;
a->length = nLength+1;
} else {
a->data[48] = 46;
}
};

{
long nLength = 49;
if (a->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(a->data, (nLength+50)*sizeof(char));
a->data = newPtr;
}
a->data[49] = 46;
a->length = nLength+1;
} else {
a->data[49] = 46;
}
};

{
long nLength = 50;
if (a->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(a->data, (nLength+50)*sizeof(char));
a->data = newPtr;
}
a->data[50] = (char)0;
a->length = nLength+1;
} else {
a->data[50] = (char)0;
}
};
}
char * ____BAH_COMPILER_VAR_9 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s);
long int strLen_1 = strlen("\"");
long int strLen_2 = strlen("\"");
;                            
            ____BAH_COMPILER_VAR_9 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_9+currStrOff, "\"", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_9+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_9+currStrOff, "\"", strLen_1);
            currStrOff += strLen_1;
        
        }return ____BAH_COMPILER_VAR_9;
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
typedef array(void *)* __BAH_ARR_TYPE_ptr;
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
for (; (i<strlen(s)); i++) {
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
void(*grow)(struct mapWrapper* this,long int nb);
void(*set)(struct mapWrapper* this,char * k,void * e);
void(*setAny)(struct mapWrapper* this,char * k,void * e,long int s);
void(*delete)(struct mapWrapper* this,char * k);
void *(*get)(struct mapWrapper* this,char * k);
};
void mapWrapper__grow(struct mapWrapper* this,long int nb){
long int l = len(this->elems);
register long int i = l;
for (; (i<l+nb); i++) {

{
long nLength = i;
if (this->elems->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(this->elems->data, (nLength+50)*sizeof(struct mapElem*));
this->elems->data = newPtr;
}
this->elems->data[i] = null;
this->elems->length = nLength+1;
} else {
this->elems->data[i] = null;
}
};
};
};
void mapWrapper__set(struct mapWrapper* this,char * k,void * e){
if ((this->length*2>=len(this->elems))) {
this->grow(this,this->length);
}
struct mapElem* ____BAH_COMPILER_VAR_10 = memoryAlloc(sizeof(struct mapElem));
____BAH_COMPILER_VAR_10->key= null;
____BAH_COMPILER_VAR_10->val= null;
____BAH_COMPILER_VAR_10->key = k;
____BAH_COMPILER_VAR_10->val = e;
struct mapElem* elem = ____BAH_COMPILER_VAR_10;
long int ind = __Bah_map_hash(k,len(this->elems));
register long int i = 0;
for (; (i<len(this->elems)); i++) {
long int j = (i+ind)%len(this->elems);
struct mapElem* ce = this->elems->data[j];
if ((ce==null)) {

{
long nLength = j;
if (this->elems->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(this->elems->data, (nLength+50)*sizeof(struct mapElem*));
this->elems->data = newPtr;
}
this->elems->data[j] = elem;
this->elems->length = nLength+1;
} else {
this->elems->data[j] = elem;
}
};
this->length++;
break;
}
else if ((strcmp(ce->key, k) == 0)) {

{
long nLength = j;
if (this->elems->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(this->elems->data, (nLength+50)*sizeof(struct mapElem*));
this->elems->data = newPtr;
}
this->elems->data[j] = elem;
this->elems->length = nLength+1;
} else {
this->elems->data[j] = elem;
}
};
break;
}
};
};
void mapWrapper__setAny(struct mapWrapper* this,char * k,void * e,long int s){
if ((this->length==0)) {
this->grow(this,50);
}
if ((this->length*2>=len(this->elems))) {
this->grow(this,this->length);
}
void * p = memoryAlloc(s);
memcpy(p,e,s);
struct mapElem* ____BAH_COMPILER_VAR_11 = memoryAlloc(sizeof(struct mapElem));
____BAH_COMPILER_VAR_11->key= null;
____BAH_COMPILER_VAR_11->val= null;
____BAH_COMPILER_VAR_11->key = k;
____BAH_COMPILER_VAR_11->val = p;
struct mapElem* elem = ____BAH_COMPILER_VAR_11;
long int ind = __Bah_map_hash(k,len(this->elems));
register long int i = 0;
for (; (i<len(this->elems)); i++) {
long int j = (i+ind)%len(this->elems);
struct mapElem* ce = this->elems->data[j];
if ((ce==null)) {

{
long nLength = j;
if (this->elems->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(this->elems->data, (nLength+50)*sizeof(struct mapElem*));
this->elems->data = newPtr;
}
this->elems->data[j] = elem;
this->elems->length = nLength+1;
} else {
this->elems->data[j] = elem;
}
};
this->length++;
break;
}
else if ((strcmp(ce->key, k) == 0)) {

{
long nLength = j;
if (this->elems->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(this->elems->data, (nLength+50)*sizeof(struct mapElem*));
this->elems->data = newPtr;
}
this->elems->data[j] = elem;
this->elems->length = nLength+1;
} else {
this->elems->data[j] = elem;
}
};
break;
}
};
};
void mapWrapper__delete(struct mapWrapper* this,char * k){
long int ind = __Bah_map_hash(k,len(this->elems));
register long int i = 0;
for (; (i<len(this->elems)); i++) {
long int j = (i+ind)%len(this->elems);
struct mapElem* e = this->elems->data[j];
if ((e!=null)&&(strcmp(e->key, k) == 0)) {

{
long nLength = j;
if (this->elems->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(this->elems->data, (nLength+50)*sizeof(struct mapElem*));
this->elems->data = newPtr;
}
this->elems->data[j] = null;
this->elems->length = nLength+1;
} else {
this->elems->data[j] = null;
}
};
}
};
};
void * mapWrapper__get(struct mapWrapper* this,char * k){
long int ind = __Bah_map_hash(k,len(this->elems));
register long int i = 0;
for (; (i<len(this->elems)); i++) {
long int j = (i+ind)%len(this->elems);
struct mapElem* e = this->elems->data[j];
if ((e!=null)&&(strcmp(e->key, k) == 0)) {
return e->val;
}
};
return null;
};
struct mapWrapper* mapWrapper(){
struct mapWrapper* ____BAH_COMPILER_VAR_12 = memoryAlloc(sizeof(struct mapWrapper));
____BAH_COMPILER_VAR_12->elems = memoryAlloc(sizeof(array(struct mapElem*)));
            ____BAH_COMPILER_VAR_12->elems->length = 0;
            ____BAH_COMPILER_VAR_12->elems->elemSize = sizeof(struct mapElem*);
            ____BAH_COMPILER_VAR_12->grow = mapWrapper__grow;
____BAH_COMPILER_VAR_12->set = mapWrapper__set;
____BAH_COMPILER_VAR_12->setAny = mapWrapper__setAny;
____BAH_COMPILER_VAR_12->delete = mapWrapper__delete;
____BAH_COMPILER_VAR_12->get = mapWrapper__get;
struct mapWrapper* m = ____BAH_COMPILER_VAR_12;
m->grow(m,50);
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
char * ____BAH_COMPILER_VAR_13 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(response);
long int strLen_1 = strlen(buff);
;                            
            ____BAH_COMPILER_VAR_13 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_13+currStrOff, response, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_13+currStrOff, buff, strLen_1);
            currStrOff += strLen_1;
        
        }response = ____BAH_COMPILER_VAR_13;
}
else {
while ((nDataLength>0)) {
char * ____BAH_COMPILER_VAR_14 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(response);
long int strLen_1 = strlen(buff);
;                            
            ____BAH_COMPILER_VAR_14 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_14+currStrOff, response, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_14+currStrOff, buff, strLen_1);
            currStrOff += strLen_1;
        
        }response = ____BAH_COMPILER_VAR_14;
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
char * ____BAH_COMPILER_VAR_15 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s);
long int strLen_1 = strlen("\n");
;                            
            ____BAH_COMPILER_VAR_15 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_15+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_15+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }write((void *)1,____BAH_COMPILER_VAR_15,strlen(s)+1);
};
struct fileStream {
FILE* handle;
char * name;
long int(*isValid)(struct fileStream* this);
void(*open)(struct fileStream* this,char * path,char * mode);
void(*close)(struct fileStream* this);
long int(*getPos)(struct fileStream* this);
void(*setPos)(struct fileStream* this,long int i);
long int(*getSize)(struct fileStream* this);
void(*rewind)(struct fileStream* this);
char(*getChar)(struct fileStream* this);
void(*setChar)(struct fileStream* this,char c);
void(*createFile)(struct fileStream* this,char * path);
long int(*writeFile)(struct fileStream* this,char * content);
void(*writePtr)(struct fileStream* this,void * a,long int s);
long int(*readPtr)(struct fileStream* this,void * a,long int s);
char *(*readContent)(struct fileStream* this);
array(char)*(*readBytes)(struct fileStream* this);
void(*writeBytes)(struct fileStream* this,array(char)* d);
void(*_end)(struct fileStream* this);
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
if ((this->isValid(this)==0)) {
return;
}
fclose(this->handle);
this->handle = null;
};
long int fileStream__getPos(struct fileStream* this){
if ((this->isValid(this)==0)) {
return 0;
}
return ftell(this->handle);
};
void fileStream__setPos(struct fileStream* this,long int i){
if ((this->isValid(this)==0)) {
return;
}
fseek(this->handle,i,0);
};
long int fileStream__getSize(struct fileStream* this){
if ((this->isValid(this)==0)) {
return -1;
}
long int oldPos = this->getPos(this);
fseek(this->handle,0,2);
long int size = ftell(this->handle);
this->setPos(this,oldPos);
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
this->open(this,path,"w");
this->close(this);
};
long int fileStream__writeFile(struct fileStream* this,char * content){
if ((this->isValid(this)==0)) {
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
if ((this->isValid(this)==0)) {
return "invalid";
}
long int sz = this->getSize(this);
char * r = memoryAllocSTR(sz+1);
long int l = fread(r,1,sz,this->handle);
if ((sz!=l)) {
array(char)* rarr = strAsArr(r);

{
long nLength = l;
if (rarr->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(rarr->data, (nLength+50)*sizeof(char));
rarr->data = newPtr;
}
rarr->data[l] = (char)0;
rarr->length = nLength+1;
} else {
rarr->data[l] = (char)0;
}
};
}
return r;
};
__BAH_ARR_TYPE_char fileStream__readBytes(struct fileStream* this){
array(char)* r = memoryAlloc(sizeof(array(char)));

r->length = 0;
r->elemSize = sizeof(char);
allocateArray(r,this->getSize(this));
this->readPtr(this,r->data,len(r));
return r;
};
void fileStream__writeBytes(struct fileStream* this,__BAH_ARR_TYPE_char d){
this->writePtr(this,d->data,len(d));
};
void fileStream___end(struct fileStream* this){
if (this->isValid(this)) {
char * ____BAH_COMPILER_VAR_16 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(this->name);
long int strLen_1 = strlen("'.");
long int strLen_2 = strlen("iostream: warning, auto-closing file: '");
;                            
            ____BAH_COMPILER_VAR_16 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_16+currStrOff, "iostream: warning, auto-closing file: '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_16+currStrOff, this->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_16+currStrOff, "'.", strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_16);
this->close(this);
}
};
struct fileMap {
long int handle;
long int size;
void * p;
char *(*open)(struct fileMap* this,char * fileName);
long int(*isValid)(struct fileMap* this);
void(*close)(struct fileMap* this);
};
char * fileMap__open(struct fileMap* this,char * fileName){
struct fileStream ____BAH_COMPILER_VAR_17 = {};
____BAH_COMPILER_VAR_17.handle= null;
____BAH_COMPILER_VAR_17.name= null;
____BAH_COMPILER_VAR_17.isValid = fileStream__isValid;
____BAH_COMPILER_VAR_17.open = fileStream__open;
____BAH_COMPILER_VAR_17.close = fileStream__close;
____BAH_COMPILER_VAR_17.getPos = fileStream__getPos;
____BAH_COMPILER_VAR_17.setPos = fileStream__setPos;
____BAH_COMPILER_VAR_17.getSize = fileStream__getSize;
____BAH_COMPILER_VAR_17.rewind = fileStream__rewind;
____BAH_COMPILER_VAR_17.getChar = fileStream__getChar;
____BAH_COMPILER_VAR_17.setChar = fileStream__setChar;
____BAH_COMPILER_VAR_17.createFile = fileStream__createFile;
____BAH_COMPILER_VAR_17.writeFile = fileStream__writeFile;
____BAH_COMPILER_VAR_17.writePtr = fileStream__writePtr;
____BAH_COMPILER_VAR_17.readPtr = fileStream__readPtr;
____BAH_COMPILER_VAR_17.readContent = fileStream__readContent;
____BAH_COMPILER_VAR_17.readBytes = fileStream__readBytes;
____BAH_COMPILER_VAR_17.writeBytes = fileStream__writeBytes;
____BAH_COMPILER_VAR_17._end = fileStream___end;
#define fs ____BAH_COMPILER_VAR_17
fs.open(&fs,fileName,"r+");
long int iv = fs.isValid(&fs);
if ((iv==1)) {
this->handle = 0;
}
else {
this->handle = -1;
}
char * file = fs.readContent(&fs);
fs.close(&fs);
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

{
long nLength = lf;
if (files->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(files->data, (nLength+50)*sizeof(char *));
files->data = newPtr;
}
files->data[lf] = __STR(file->d_name);
files->length = nLength+1;
} else {
files->data[lf] = __STR(file->d_name);
}
};
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
return (c==(char)32)||(c==(char)9)||(c==(char)10)||(c==(char)11)||(c==(char)13);
};
struct string {
char * content;
char editable;
long int length;
void(*set)(struct string* this,char * s);
void(*makeEditable)(struct string* this);
void(*append)(struct string* this,char * s);
void(*prepend)(struct string* this,char * s);
char(*charAt)(struct string* this,long int i);
long int(*compare)(struct string* this,char * s);
char *(*str)(struct string* this);
void(*replace)(struct string* this,char * nd,char * rl);
long int(*countChar)(struct string* this,char need);
long int(*count)(struct string* this,char * need);
long int(*hasPrefix)(struct string* this,char * need);
long int(*hasSuffix)(struct string* this,char * need);
void(*trim)(struct string* this);
void(*trimLeft)(struct string* this,long int s);
void(*trimRight)(struct string* this,long int s);
struct string(*add)(struct string* this,struct string s2);
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
this->makeEditable(this);
}
long int sl = strlen(s);
long int nl = sl+this->length;
void * nc = memoryRealloc(this->content,nl+1);
if ((nc==null)) {
__BAH_panic("Error appending to string, possibly due to memory shortage.","/opt/bah/string.bah:109");
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
__BAH_panic("Error appending to string, possibly due to memory shortage.","/opt/bah/string.bah:124");
}
this->content = nc;
strncpy(this->content,s,sl);
strCatOffset(this->content,sl,tmpS,this->length);
destroy(tmpS);
this->length = nl;
};
char string__charAt(struct string* this,long int i){
if (((void *)this->content==null)) {
return null;
}
if ((i<this->length)&&(i>=0)) {
return this->content[i];
}
return null;
};
long int string__compare(struct string* this,char * s){
long int r = strcmp(this->content,s);
if ((r==0)) {
return 1;
}
return 0;
};
char * string__str(struct string* this){
return this->content;
};
void string__replace(struct string* this,char * nd,char * rl){
if ((this->editable==false)) {
this->makeEditable(this);
}
struct string ____BAH_COMPILER_VAR_18 = {};
____BAH_COMPILER_VAR_18.content= null;
____BAH_COMPILER_VAR_18.set = string__set;
____BAH_COMPILER_VAR_18.makeEditable = string__makeEditable;
____BAH_COMPILER_VAR_18.append = string__append;
____BAH_COMPILER_VAR_18.prepend = string__prepend;
____BAH_COMPILER_VAR_18.charAt = string__charAt;
____BAH_COMPILER_VAR_18.compare = string__compare;
____BAH_COMPILER_VAR_18.str = string__str;
____BAH_COMPILER_VAR_18.replace = string__replace;
#define needle ____BAH_COMPILER_VAR_18
needle.set(&needle,nd);
struct string ____BAH_COMPILER_VAR_19 = {};
____BAH_COMPILER_VAR_19.content= null;
____BAH_COMPILER_VAR_19.set = string__set;
____BAH_COMPILER_VAR_19.makeEditable = string__makeEditable;
____BAH_COMPILER_VAR_19.append = string__append;
____BAH_COMPILER_VAR_19.prepend = string__prepend;
____BAH_COMPILER_VAR_19.charAt = string__charAt;
____BAH_COMPILER_VAR_19.compare = string__compare;
____BAH_COMPILER_VAR_19.str = string__str;
____BAH_COMPILER_VAR_19.replace = string__replace;
#define repl ____BAH_COMPILER_VAR_19
repl.set(&repl,rl);
register long int i = 0;
long int si = 0;
long int replcBuffSart = 0;
long int replcBuffLength = 0;
array(char)* buff = memoryAlloc(sizeof(array(char)));

buff->length = 0;
buff->elemSize = sizeof(char);
while ((i<this->length)) {
char c = this->charAt(this,i);
char rc = needle.charAt(&needle,si);
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

{
long nLength = len(buff);
if (buff->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(buff->data, (nLength+50)*sizeof(char));
buff->data = newPtr;
}
buff->data[len(buff)] = this->charAt(this,j+replcBuffSart);
buff->length = nLength+1;
} else {
buff->data[len(buff)] = this->charAt(this,j+replcBuffSart);
}
};
j = j+1;
};
replcBuffLength = 0;
}

{
long nLength = len(buff);
if (buff->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(buff->data, (nLength+50)*sizeof(char));
buff->data = newPtr;
}
buff->data[len(buff)] = c;
buff->length = nLength+1;
} else {
buff->data[len(buff)] = c;
}
};
}
if ((si==needle.length)) {
replcBuffLength = 0;
register long int ii = 0;
while ((ii<repl.length)) {
long int a = ii;

{
long nLength = len(buff);
if (buff->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(buff->data, (nLength+50)*sizeof(char));
buff->data = newPtr;
}
buff->data[len(buff)] = repl.charAt(&repl,ii);
buff->length = nLength+1;
} else {
buff->data[len(buff)] = repl.charAt(&repl,ii);
}
};
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

{
long nLength = j;
if (replbuffStr->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(replbuffStr->data, (nLength+50)*sizeof(char));
replbuffStr->data = newPtr;
}
replbuffStr->data[j] = this->charAt(this,j+replcBuffSart);
replbuffStr->length = nLength+1;
} else {
replbuffStr->data[j] = this->charAt(this,j+replcBuffSart);
}
};
j = j+1;
};
char * ____BAH_COMPILER_VAR_20 =null;char * ____BAH_COMPILER_VAR_21 =arrAsStr(replbuffStr);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(r);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_21);
;                            
            ____BAH_COMPILER_VAR_20 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_20+currStrOff, r, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_20+currStrOff, ____BAH_COMPILER_VAR_21, strLen_1);
            currStrOff += strLen_1;
        
        }r = ____BAH_COMPILER_VAR_20;
}
if (((void *)r!=null)) {
this->set(this,r);
}

#undef needle

#undef repl
};
long int string__countChar(struct string* this,char need){
long int c = 0;
register long int i = 0;
for (; (i<this->length); i++) {
if ((this->charAt(this,i)==need)) {
c++;
}
};
return c;
};
long int string__count(struct string* this,char * need){
if ((strlen(need)==1)) {
return this->countChar(this,need[0]);
}
register long int i = 0;
long int count = 0;
struct string ____BAH_COMPILER_VAR_22 = {};
____BAH_COMPILER_VAR_22.content= null;
____BAH_COMPILER_VAR_22.set = string__set;
____BAH_COMPILER_VAR_22.makeEditable = string__makeEditable;
____BAH_COMPILER_VAR_22.append = string__append;
____BAH_COMPILER_VAR_22.prepend = string__prepend;
____BAH_COMPILER_VAR_22.charAt = string__charAt;
____BAH_COMPILER_VAR_22.compare = string__compare;
____BAH_COMPILER_VAR_22.str = string__str;
____BAH_COMPILER_VAR_22.replace = string__replace;
____BAH_COMPILER_VAR_22.countChar = string__countChar;
____BAH_COMPILER_VAR_22.count = string__count;
#define needle ____BAH_COMPILER_VAR_22
needle.set(&needle,need);
long int countIndex = 0;
while ((i<this->length)) {
char c = this->charAt(this,i);
char sc = needle.charAt(&needle,countIndex);
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
char c = this->charAt(this,i);
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
char c = this->charAt(this,i);
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
char fc = this->charAt(this,0);
if ((isSpace(fc)==false)) {
return;
}
register long int i = 0;
for (; (i<this->length); i++) {
if ((isSpace(this->charAt(this,i))==false)) {
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
long int nSize = this->length-s;
void * tmpS = memoryAlloc(nSize+1);
memcpy(tmpS,this->content+s,nSize);
this->content = tmpS;
this->editable = true;
this->length = nSize;
};
void string__trimRight(struct string* this,long int s){
long int nSize = this->length-s;
void * tmpS = memoryAlloc(nSize+1);
memcpy(tmpS,this->content,nSize);
this->content = tmpS;
this->editable = true;
this->length = nSize;
};
struct string string__add(struct string* this,struct string s2){
struct string ____BAH_COMPILER_VAR_23 = {};
____BAH_COMPILER_VAR_23.content= null;
____BAH_COMPILER_VAR_23.set = string__set;
____BAH_COMPILER_VAR_23.makeEditable = string__makeEditable;
____BAH_COMPILER_VAR_23.append = string__append;
____BAH_COMPILER_VAR_23.prepend = string__prepend;
____BAH_COMPILER_VAR_23.charAt = string__charAt;
____BAH_COMPILER_VAR_23.compare = string__compare;
____BAH_COMPILER_VAR_23.str = string__str;
____BAH_COMPILER_VAR_23.replace = string__replace;
____BAH_COMPILER_VAR_23.countChar = string__countChar;
____BAH_COMPILER_VAR_23.count = string__count;
____BAH_COMPILER_VAR_23.hasPrefix = string__hasPrefix;
____BAH_COMPILER_VAR_23.hasSuffix = string__hasSuffix;
____BAH_COMPILER_VAR_23.trim = string__trim;
____BAH_COMPILER_VAR_23.trimLeft = string__trimLeft;
____BAH_COMPILER_VAR_23.trimRight = string__trimRight;
____BAH_COMPILER_VAR_23.add = string__add;
#define r ____BAH_COMPILER_VAR_23
r.length = this->length+s2.length;
r.content = memoryAlloc(r.length+1);
strncpy(r.content,this->content,this->length);
strCatOffset(r.content,this->length,s2.content,s2.length);
return r;
};
struct string string(char * s){
struct string ____BAH_COMPILER_VAR_24 = {};
____BAH_COMPILER_VAR_24.content= null;
____BAH_COMPILER_VAR_24.set = string__set;
____BAH_COMPILER_VAR_24.makeEditable = string__makeEditable;
____BAH_COMPILER_VAR_24.append = string__append;
____BAH_COMPILER_VAR_24.prepend = string__prepend;
____BAH_COMPILER_VAR_24.charAt = string__charAt;
____BAH_COMPILER_VAR_24.compare = string__compare;
____BAH_COMPILER_VAR_24.str = string__str;
____BAH_COMPILER_VAR_24.replace = string__replace;
____BAH_COMPILER_VAR_24.countChar = string__countChar;
____BAH_COMPILER_VAR_24.count = string__count;
____BAH_COMPILER_VAR_24.hasPrefix = string__hasPrefix;
____BAH_COMPILER_VAR_24.hasSuffix = string__hasSuffix;
____BAH_COMPILER_VAR_24.trim = string__trim;
____BAH_COMPILER_VAR_24.trimLeft = string__trimLeft;
____BAH_COMPILER_VAR_24.trimRight = string__trimRight;
____BAH_COMPILER_VAR_24.add = string__add;
#define a ____BAH_COMPILER_VAR_24
a.set(&a,s);
return a;
};
char * intToStr(long int i){
if ((i==0)) {
return "0";
}
char ____BAH_COMPILER_VAR_25[66];char* s = ____BAH_COMPILER_VAR_25;
long int ind = -1;
char subZero = (i<0);
if ((subZero==true)) {
i = 0-i;
}
for (; (i!=0); i = i/10) {
long int conv = i%10;
conv = conv+48;
s[ind+1] = (char)conv;
ind++;
};
if ((subZero==true)) {
s[ind+1] = 45;
ind++;
}
long int ls = ind+1;
i = 0;
for (; (i<ls/2); i++) {
long int ii = ls-i-1;
char osi = s[i];
s[i] = s[ii];
s[ii] = osi;
};
s[ind+1] = (char)0;
return __STR(s);
};
struct string intToString(long int i){
char * ____BAH_COMPILER_VAR_26 =intToStr(i);struct string r = string(____BAH_COMPILER_VAR_26);
return r;
};
char * floatToStr(double f){
char ____BAH_COMPILER_VAR_27[50];char* buff = ____BAH_COMPILER_VAR_27;
sprintf(buff,"%lf",f);
return __STR(buff);
};
long int strToInt(char * s){
return atol(s);
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
char c = s.charAt(&s,i);
char sepc = sep.charAt(&sep,sepIndex);
if ((c==sepc)) {
sepIndex = sepIndex+1;
char * ____BAH_COMPILER_VAR_28 =charToString(c);replcBuff.append(&replcBuff,____BAH_COMPILER_VAR_28);
}
else {
if ((sepIndex>0)) {
sepIndex = 0;
char * ____BAH_COMPILER_VAR_29 =charToString(c);replcBuff.append(&replcBuff,____BAH_COMPILER_VAR_29);
register long int ii = 0;
while ((ii<replcBuff.length)) {

{
long nLength = len(tmpString);
if (tmpString->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tmpString->data, (nLength+50)*sizeof(char));
tmpString->data = newPtr;
}
tmpString->data[len(tmpString)] = replcBuff.charAt(&replcBuff,ii);
tmpString->length = nLength+1;
} else {
tmpString->data[len(tmpString)] = replcBuff.charAt(&replcBuff,ii);
}
};
ii = ii+1;
};
replcBuff.set(&replcBuff,"");
}
else {

{
long nLength = len(tmpString);
if (tmpString->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tmpString->data, (nLength+50)*sizeof(char));
tmpString->data = newPtr;
}
tmpString->data[len(tmpString)] = c;
tmpString->length = nLength+1;
} else {
tmpString->data[len(tmpString)] = c;
}
};
}
}
if ((sepIndex==sep.length)) {
replcBuff.set(&replcBuff,"");
struct string* ____BAH_COMPILER_VAR_30 = memoryAlloc(sizeof(struct string));
____BAH_COMPILER_VAR_30->content= null;
____BAH_COMPILER_VAR_30->set = string__set;
____BAH_COMPILER_VAR_30->makeEditable = string__makeEditable;
____BAH_COMPILER_VAR_30->append = string__append;
____BAH_COMPILER_VAR_30->prepend = string__prepend;
____BAH_COMPILER_VAR_30->charAt = string__charAt;
____BAH_COMPILER_VAR_30->compare = string__compare;
____BAH_COMPILER_VAR_30->str = string__str;
____BAH_COMPILER_VAR_30->replace = string__replace;
____BAH_COMPILER_VAR_30->countChar = string__countChar;
____BAH_COMPILER_VAR_30->count = string__count;
____BAH_COMPILER_VAR_30->hasPrefix = string__hasPrefix;
____BAH_COMPILER_VAR_30->hasSuffix = string__hasSuffix;
____BAH_COMPILER_VAR_30->trim = string__trim;
____BAH_COMPILER_VAR_30->trimLeft = string__trimLeft;
____BAH_COMPILER_VAR_30->trimRight = string__trimRight;
____BAH_COMPILER_VAR_30->add = string__add;
struct string* elem = ____BAH_COMPILER_VAR_30;
char * ____BAH_COMPILER_VAR_31 =arrToStr(tmpString);elem->set(elem,____BAH_COMPILER_VAR_31);
long int lenRes = len(res);

{
long nLength = lenRes;
if (res->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(res->data, (nLength+50)*sizeof(struct string));
res->data = newPtr;
}
res->data[lenRes] = *elem;
res->length = nLength+1;
} else {
res->data[lenRes] = *elem;
}
};
clear(tmpString);
sepIndex = 0;
}
i = i+1;
};
if ((replcBuff.length>0)) {
register long int ii = 0;
while ((ii<replcBuff.length)) {

{
long nLength = len(tmpString);
if (tmpString->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tmpString->data, (nLength+50)*sizeof(char));
tmpString->data = newPtr;
}
tmpString->data[len(tmpString)] = replcBuff.charAt(&replcBuff,ii);
tmpString->length = nLength+1;
} else {
tmpString->data[len(tmpString)] = replcBuff.charAt(&replcBuff,ii);
}
};
ii = ii+1;
};
}
if ((len(tmpString)>0)) {
struct string* ____BAH_COMPILER_VAR_32 = memoryAlloc(sizeof(struct string));
____BAH_COMPILER_VAR_32->content= null;
____BAH_COMPILER_VAR_32->set = string__set;
____BAH_COMPILER_VAR_32->makeEditable = string__makeEditable;
____BAH_COMPILER_VAR_32->append = string__append;
____BAH_COMPILER_VAR_32->prepend = string__prepend;
____BAH_COMPILER_VAR_32->charAt = string__charAt;
____BAH_COMPILER_VAR_32->compare = string__compare;
____BAH_COMPILER_VAR_32->str = string__str;
____BAH_COMPILER_VAR_32->replace = string__replace;
____BAH_COMPILER_VAR_32->countChar = string__countChar;
____BAH_COMPILER_VAR_32->count = string__count;
____BAH_COMPILER_VAR_32->hasPrefix = string__hasPrefix;
____BAH_COMPILER_VAR_32->hasSuffix = string__hasSuffix;
____BAH_COMPILER_VAR_32->trim = string__trim;
____BAH_COMPILER_VAR_32->trimLeft = string__trimLeft;
____BAH_COMPILER_VAR_32->trimRight = string__trimRight;
____BAH_COMPILER_VAR_32->add = string__add;
struct string* elem = ____BAH_COMPILER_VAR_32;
char * ____BAH_COMPILER_VAR_33 =arrToStr(tmpString);elem->set(elem,____BAH_COMPILER_VAR_33);
long int lenRes = len(res);

{
long nLength = lenRes;
if (res->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(res->data, (nLength+50)*sizeof(struct string));
res->data = newPtr;
}
res->data[lenRes] = *elem;
res->length = nLength+1;
} else {
res->data[lenRes] = *elem;
}
};
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
char * ____BAH_COMPILER_VAR_34 =e.str(&e);struct string tmpS = string(____BAH_COMPILER_VAR_34);
if ((i!=max)) {
tmpS.append(&tmpS,sep);
}
char * ____BAH_COMPILER_VAR_35 =tmpS.str(&tmpS);s.append(&s,____BAH_COMPILER_VAR_35);
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
char c = s.charAt(&s,i);
char sc = sep.charAt(&sep,sepIndex);
if ((c==sc)) {
if ((sepIndex==0)) {
foundIndex = i-1;
}
sepIndex = sepIndex+1;
if ((sepIndex==sep.length)) {
long int max = s.length-foundIndex-1;
s.trimRight(&s,max);
return s.str(&s);
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
char c = s.charAt(&s,i);
if (isUpper(c)) {
c = c+(char)32;
}

{
long nLength = len(ns);
if (ns->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(ns->data, (nLength+50)*sizeof(char));
ns->data = newPtr;
}
ns->data[len(ns)] = c;
ns->length = nLength+1;
} else {
ns->data[len(ns)] = c;
}
};
i = i+1;
};
char * ____BAH_COMPILER_VAR_36 =arrToStr(ns);return string(____BAH_COMPILER_VAR_36);
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
void(*addString)(struct flags* this,char * name,char * help);
void(*addBool)(struct flags* this,char * name,char * help);
void(*addInt)(struct flags* this,char * name,char * help);
void(*addFloat)(struct flags* this,char * name,char * help);
void(*invalidate)(struct flags* this);
struct flag*(*getFlag)(struct flags* this,struct string name);
char *(*get)(struct flags* this,char * name);
long int(*getInt)(struct flags* this,char * name);
double(*getFloat)(struct flags* this,char * name);
long int(*isSet)(struct flags* this,char * name);
void(*parse)(struct flags* this,array(char *)* args);
};
void flags__addString(struct flags* this,char * name,char * help){
struct flag* ____BAH_COMPILER_VAR_37 = memoryAlloc(sizeof(struct flag));
____BAH_COMPILER_VAR_37->name= null;
____BAH_COMPILER_VAR_37->help= null;
____BAH_COMPILER_VAR_37->content= null;
struct flag* f = ____BAH_COMPILER_VAR_37;
f->name = name;
f->help = help;
f->type = FLAG_TYPE_CPSTRING;
long int lf = len(this->flags);

{
long nLength = lf;
if (this->flags->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(this->flags->data, (nLength+50)*sizeof(struct flag*));
this->flags->data = newPtr;
}
this->flags->data[lf] = f;
this->flags->length = nLength+1;
} else {
this->flags->data[lf] = f;
}
};
};
void flags__addBool(struct flags* this,char * name,char * help){
struct flag* ____BAH_COMPILER_VAR_38 = memoryAlloc(sizeof(struct flag));
____BAH_COMPILER_VAR_38->name= null;
____BAH_COMPILER_VAR_38->help= null;
____BAH_COMPILER_VAR_38->content= null;
struct flag* f = ____BAH_COMPILER_VAR_38;
f->name = name;
f->help = help;
f->type = FLAG_TYPE_BOOL;
long int lf = len(this->flags);

{
long nLength = lf;
if (this->flags->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(this->flags->data, (nLength+50)*sizeof(struct flag*));
this->flags->data = newPtr;
}
this->flags->data[lf] = f;
this->flags->length = nLength+1;
} else {
this->flags->data[lf] = f;
}
};
};
void flags__addInt(struct flags* this,char * name,char * help){
struct flag* ____BAH_COMPILER_VAR_39 = memoryAlloc(sizeof(struct flag));
____BAH_COMPILER_VAR_39->name= null;
____BAH_COMPILER_VAR_39->help= null;
____BAH_COMPILER_VAR_39->content= null;
struct flag* f = ____BAH_COMPILER_VAR_39;
f->name = name;
f->help = help;
f->type = FLAG_TYPE_INT;
long int lf = len(this->flags);

{
long nLength = lf;
if (this->flags->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(this->flags->data, (nLength+50)*sizeof(struct flag*));
this->flags->data = newPtr;
}
this->flags->data[lf] = f;
this->flags->length = nLength+1;
} else {
this->flags->data[lf] = f;
}
};
};
void flags__addFloat(struct flags* this,char * name,char * help){
struct flag* ____BAH_COMPILER_VAR_40 = memoryAlloc(sizeof(struct flag));
____BAH_COMPILER_VAR_40->name= null;
____BAH_COMPILER_VAR_40->help= null;
____BAH_COMPILER_VAR_40->content= null;
struct flag* f = ____BAH_COMPILER_VAR_40;
f->name = name;
f->help = help;
f->type = FLAG_TYPE_FLOAT;
long int lf = len(this->flags);

{
long nLength = lf;
if (this->flags->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(this->flags->data, (nLength+50)*sizeof(struct flag*));
this->flags->data = newPtr;
}
this->flags->data[lf] = f;
this->flags->length = nLength+1;
} else {
this->flags->data[lf] = f;
}
};
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
if (name.compare(&name,flag->name)) {
return flag;
}
i = i+1;
};
struct flag* ____BAH_COMPILER_VAR_41 = memoryAlloc(sizeof(struct flag));
____BAH_COMPILER_VAR_41->name= null;
____BAH_COMPILER_VAR_41->help= null;
____BAH_COMPILER_VAR_41->content= null;
struct flag* z = ____BAH_COMPILER_VAR_41;
z->isSet = 0;
return z;
};
char * flags__get(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_42 =string(name);struct flag* flag = this->getFlag(this,____BAH_COMPILER_VAR_42);
char * ctn = flag->content;
return ctn;
};
long int flags__getInt(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_43 =string(name);struct flag* flag = this->getFlag(this,____BAH_COMPILER_VAR_43);
if ((flag->type!=FLAG_TYPE_INT)) {
char * ____BAH_COMPILER_VAR_44 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(flag->name);
long int strLen_1 = strlen("' is not int.");
long int strLen_2 = strlen("Flag '");
;                            
            ____BAH_COMPILER_VAR_44 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_44+currStrOff, "Flag '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_44+currStrOff, flag->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_44+currStrOff, "' is not int.", strLen_1);
            currStrOff += strLen_1;
        
        }char * error = ____BAH_COMPILER_VAR_44;
__BAH_panic(error,"/opt/bah/flags.bah:124");
}
long int ctn = flag->cont_int;
return ctn;
};
double flags__getFloat(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_45 =string(name);struct flag* flag = this->getFlag(this,____BAH_COMPILER_VAR_45);
if ((flag->type!=FLAG_TYPE_FLOAT)) {
char * ____BAH_COMPILER_VAR_46 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(flag->name);
long int strLen_1 = strlen("' is not float.");
long int strLen_2 = strlen("Flag '");
;                            
            ____BAH_COMPILER_VAR_46 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_46+currStrOff, "Flag '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_46+currStrOff, flag->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_46+currStrOff, "' is not float.", strLen_1);
            currStrOff += strLen_1;
        
        }char * error = ____BAH_COMPILER_VAR_46;
__BAH_panic(error,"/opt/bah/flags.bah:136");
}
double ctn = flag->cont_float;
return ctn;
};
long int flags__isSet(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_47 =string(name);struct flag* flag = this->getFlag(this,____BAH_COMPILER_VAR_47);
long int ctn = flag->isSet;
return ctn;
};
void flags__parse(struct flags* this,__BAH_ARR_TYPE_cpstring args){
struct flag* currentFlag= null;
char isVal = false;
this->args = args;
register long int i = 1;
while ((i<len(args))) {
struct string argName = string(args->data[i]);
if ((isVal==true)) {
currentFlag->content = argName.str(&argName);
if ((currentFlag->type==FLAG_TYPE_INT)) {
char * ____BAH_COMPILER_VAR_48 =argName.str(&argName);currentFlag->cont_int = atoi(____BAH_COMPILER_VAR_48);
}
else if ((currentFlag->type==FLAG_TYPE_FLOAT)) {
char * ____BAH_COMPILER_VAR_49 =argName.str(&argName);currentFlag->cont_float = strtod(____BAH_COMPILER_VAR_49,0);
}
isVal = false;
}
else {
if ((argName.charAt(&argName,0)!=45)) {
i = i+1;
continue;
}
argName.trimLeft(&argName,1);
if (argName.compare(&argName,"help")) {
this->invalidate(this);
}
else if (argName.compare(&argName,"h")) {
this->invalidate(this);
}
currentFlag = this->getFlag(this,argName);
if ((currentFlag==null)) {
this->invalidate(this);
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
this->invalidate(this);
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
void(*now)(struct time* this);
char *(*format)(struct time* this,char * a);
long int(*since)(struct time* this);
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
struct timespec ____BAH_COMPILER_VAR_50 = {};
#define ts ____BAH_COMPILER_VAR_50
long int s = clock_gettime(CLOCK_REALTIME,&ts);
s = ts.tv_sec*1000000000+ts.tv_nsec;
return s;
};
long int RAND_SEEDED;
void seedRandom(long int i){
srand(i);
RAND_SEEDED = 1;
};
long int randomInRange(long int min,long int max){
if ((RAND_SEEDED==0)) {
srand(time(0)+getTimeUnix());
RAND_SEEDED = 1;
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
long int lCount;
long int len;
long int totalLen;
void(*addStr)(struct rope* this,char * s,long int* offset);
char *(*toStr)(struct rope* this);
struct rope*(*add)(struct rope* this,struct rope* root2);
};
void rope__addStr(struct rope* this,char * s,long int* offset){
if ((this->left==null)&&(this->right==null)) {
long int off = *offset;
memcpy(s+off,this->str,this->lCount+1);
*offset = *offset+this->lCount+1;
return;
}
long int l = *offset;
this->left->addStr(this->left,s,offset);
this->right->addStr(this->right,s,offset);
};
char * rope__toStr(struct rope* this){
if ((this->left==null)&&(this->right==null)) {
return this->str;
}
char * s = memoryAlloc(this->totalLen+1);
long int offset = 0;
this->left->addStr(this->left,s,&offset);
this->right->addStr(this->right,s,&offset);
return s;
};
struct rope* rope__add(struct rope* this,struct rope* root2){
long int n1 = this->len;
struct rope* ____BAH_COMPILER_VAR_51 = memoryAlloc(sizeof(struct rope));
____BAH_COMPILER_VAR_51->left= null;
____BAH_COMPILER_VAR_51->right= null;
____BAH_COMPILER_VAR_51->str= null;
____BAH_COMPILER_VAR_51->len = 0;
____BAH_COMPILER_VAR_51->addStr = rope__addStr;
____BAH_COMPILER_VAR_51->toStr = rope__toStr;
____BAH_COMPILER_VAR_51->add = rope__add;
struct rope* tmp = ____BAH_COMPILER_VAR_51;
tmp->left = this;
tmp->right = root2;
tmp->totalLen = this->totalLen+root2->totalLen;
tmp->str = null;
return tmp;
};
struct rope* createRopeStructure(struct rope* par,char * a,long int l,long int r){
struct rope* ____BAH_COMPILER_VAR_52 = memoryAlloc(sizeof(struct rope));
____BAH_COMPILER_VAR_52->left= null;
____BAH_COMPILER_VAR_52->right= null;
____BAH_COMPILER_VAR_52->str= null;
____BAH_COMPILER_VAR_52->len = 0;
____BAH_COMPILER_VAR_52->addStr = rope__addStr;
____BAH_COMPILER_VAR_52->toStr = rope__toStr;
____BAH_COMPILER_VAR_52->add = rope__add;
struct rope* tmp = ____BAH_COMPILER_VAR_52;
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
j++;
i++;
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
long int n1 = root1->len;
struct rope* ____BAH_COMPILER_VAR_53 = memoryAlloc(sizeof(struct rope));
____BAH_COMPILER_VAR_53->left= null;
____BAH_COMPILER_VAR_53->right= null;
____BAH_COMPILER_VAR_53->str= null;
____BAH_COMPILER_VAR_53->len = 0;
____BAH_COMPILER_VAR_53->addStr = rope__addStr;
____BAH_COMPILER_VAR_53->toStr = rope__toStr;
____BAH_COMPILER_VAR_53->add = rope__add;
struct rope* tmp = ____BAH_COMPILER_VAR_53;
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
char *(*run)(struct command* this);
array(char)*(*runBytes)(struct command* this);
};
char * command__run(struct command* this){
char * cm = this->command;
if ((this->error==false)) {
char * ____BAH_COMPILER_VAR_54 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(cm);
long int strLen_1 = strlen(" 2>/dev/null");
;                            
            ____BAH_COMPILER_VAR_54 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_54+currStrOff, cm, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_54+currStrOff, " 2>/dev/null", strLen_1);
            currStrOff += strLen_1;
        
        }cm = ____BAH_COMPILER_VAR_54;
}
else {
char * ____BAH_COMPILER_VAR_55 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(cm);
long int strLen_1 = strlen(" 2>&1");
;                            
            ____BAH_COMPILER_VAR_55 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_55+currStrOff, cm, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_55+currStrOff, " 2>&1", strLen_1);
            currStrOff += strLen_1;
        
        }cm = ____BAH_COMPILER_VAR_55;
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
char * ____BAH_COMPILER_VAR_56 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(res);
long int strLen_1 = strlen(buff);
;                            
            ____BAH_COMPILER_VAR_56 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_56+currStrOff, res, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_56+currStrOff, buff, strLen_1);
            currStrOff += strLen_1;
        
        }res = ____BAH_COMPILER_VAR_56;
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
char * ____BAH_COMPILER_VAR_57 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(cm);
long int strLen_1 = strlen(" 2>/dev/null");
;                            
            ____BAH_COMPILER_VAR_57 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_57+currStrOff, cm, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_57+currStrOff, " 2>/dev/null", strLen_1);
            currStrOff += strLen_1;
        
        }cm = ____BAH_COMPILER_VAR_57;
}
else {
char * ____BAH_COMPILER_VAR_58 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(cm);
long int strLen_1 = strlen(" 2>&1");
;                            
            ____BAH_COMPILER_VAR_58 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_58+currStrOff, cm, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_58+currStrOff, " 2>&1", strLen_1);
            currStrOff += strLen_1;
        
        }cm = ____BAH_COMPILER_VAR_58;
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
char * ____BAH_COMPILER_VAR_59 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(response);
long int strLen_1 = strlen(buff);
;                            
            ____BAH_COMPILER_VAR_59 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_59+currStrOff, response, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_59+currStrOff, buff, strLen_1);
            currStrOff += strLen_1;
        
        }response = ____BAH_COMPILER_VAR_59;
res = fgets(buff,1023,this->handle);
};
this->status = pclose(this->handle);
arr->data=response;
arr->length=strlen(response);
return arr;
};
struct command command(char * s){
struct command ____BAH_COMPILER_VAR_60 = {};
____BAH_COMPILER_VAR_60.command= null;
____BAH_COMPILER_VAR_60.error = true;
____BAH_COMPILER_VAR_60.status = 0;
____BAH_COMPILER_VAR_60.input = null;
____BAH_COMPILER_VAR_60.handle= null;
____BAH_COMPILER_VAR_60.run = command__run;
____BAH_COMPILER_VAR_60.runBytes = command__runBytes;
#define cmd ____BAH_COMPILER_VAR_60
cmd.command = s;
return cmd;
};
long int exec(char * s,__BAH_ARR_TYPE_cpstring args){
long int r;
array(char *)* nArgs = memoryAlloc(sizeof(array(char *)));

nArgs->length = 0;
nArgs->elemSize = sizeof(char *);

{
long nLength = 0;
if (nArgs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nArgs->data, (nLength+50)*sizeof(char *));
nArgs->data = newPtr;
}
nArgs->data[0] = s;
nArgs->length = nLength+1;
} else {
nArgs->data[0] = s;
}
};
register long int i = 0;
while ((i<len(args))) {

{
long nLength = i+1;
if (nArgs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nArgs->data, (nLength+50)*sizeof(char *));
nArgs->data = newPtr;
}
nArgs->data[i+1] = args->data[i];
nArgs->length = nLength+1;
} else {
nArgs->data[i+1] = args->data[i];
}
};
i = i+1;
};

{
long nLength = i+2;
if (nArgs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nArgs->data, (nLength+50)*sizeof(char *));
nArgs->data = newPtr;
}
nArgs->data[i+2] = (char *)0;
nArgs->length = nLength+1;
} else {
nArgs->data[i+2] = (char *)0;
}
};
r=execvp(s,nArgs->data);
return r;
};
char * BAH_DIR;
char * BAH_OS;
char * BAH_CC;
#define BAH_VERSION "v1.2 (build 89)"
char debug;
char verboseRuntime;
char isObject;
char isUnsafe;
char * execName;
char isSubObject;
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
char canBeReg;
char isReg;
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
char canBeReg;
char isReg;
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
long int line;
char used;
struct rope* code;
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
struct Elems {
array(struct variable*)* vars;
array(struct cStruct*)* structs;
array(char *)* types;
array(struct func*)* fns;
array(char *)* defined;
struct Elems* parent;
long int id;
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
typedef long int tokenType;
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
long int pos;
long int line;
long int begLine;
char * bahType;
char isValue;
char isFunc;
char isOper;
char isEqual;
char pass;
void * bahRef;
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
struct Tok ____BAH_COMPILER_VAR_61 = {};
____BAH_COMPILER_VAR_61.cont = "";
____BAH_COMPILER_VAR_61.ogCont = "";
____BAH_COMPILER_VAR_61.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_61.pos = 0;
____BAH_COMPILER_VAR_61.line = 1;
____BAH_COMPILER_VAR_61.begLine = 1;
____BAH_COMPILER_VAR_61.bahType = "";
____BAH_COMPILER_VAR_61.isValue = false;
____BAH_COMPILER_VAR_61.isFunc = false;
____BAH_COMPILER_VAR_61.isOper = false;
____BAH_COMPILER_VAR_61.isEqual = false;
____BAH_COMPILER_VAR_61.pass = false;
____BAH_COMPILER_VAR_61.bahRef= null;
#define t ____BAH_COMPILER_VAR_61
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
char * ____BAH_COMPILER_VAR_62 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("\n\e[0m\n");
long int strLen_1 = strlen(msg);
long int strLen_2 = strlen(posStr);
long int strLen_3 = strlen(":");
long int strLen_4 = strlen(lineStr);
long int strLen_5 = strlen(":");
long int strLen_6 = strlen(compilerState.currentFile);
long int strLen_7 = strlen("\e[1;31m[LEXER-ERROR]\e[0m ");
;                            
            ____BAH_COMPILER_VAR_62 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7);
            
                    memcpy(____BAH_COMPILER_VAR_62+currStrOff, "\e[1;31m[LEXER-ERROR]\e[0m ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_62+currStrOff, compilerState.currentFile, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_62+currStrOff, ":", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_62+currStrOff, lineStr, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_62+currStrOff, ":", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_62+currStrOff, posStr, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_62+currStrOff, "\n\e[0m\n", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_62+currStrOff, msg, strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_62);
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
for (; (i<codeLength); i++) {
char c = s[i];
char nc = (char)0;
if ((i+1<codeLength)) {
nc = s[i+1];
}
if ((c==47)) {
nc = s[i+1];
if ((nc==47)) {
for (; (i<codeLength); i++) {
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
lineNb++;
}
if ((c==(char)34)) {
long int pos = i;
long int begLine = lineNb;

{
long nLength = 0;
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[0] = c;
memory->length = nLength+1;
} else {
memory->data[0] = c;
}
};
i = i+1;
for (; (i<codeLength); i++) {
c = s[i];
char pc = s[i-1];
if ((c==(char)34)) {
if ((pc!=(char)92)) {

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[len(memory)] = c;
memory->length = nLength+1;
} else {
memory->data[len(memory)] = c;
}
};
break;
}
}
if ((c==(char)10)) {
lineNb = lineNb+1;
if ((pc!=(char)92)) {

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[len(memory)] = (char)92;
memory->length = nLength+1;
} else {
memory->data[len(memory)] = (char)92;
}
};
c = 110;
}
}

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[len(memory)] = c;
memory->length = nLength+1;
} else {
memory->data[len(memory)] = c;
}
};
};

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] = makeToken(pos,lineNb,memory,TOKEN_TYPE_STR);
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] = makeToken(pos,lineNb,memory,TOKEN_TYPE_STR);
}
};
struct Tok lt = tokens->data[len(tokens)-1];
lt.begLine = begLine;

{
long nLength = len(tokens)-1;
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)-1] = lt;
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)-1] = lt;
}
};
}
else if (isNumber(c)||isMinus(c,nc)) {

{
long nLength = 0;
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[0] = c;
memory->length = nLength+1;
} else {
memory->data[0] = c;
}
};
long int pos = i;
i = i+1;
tokenType currentType = TOKEN_TYPE_INT;
char isHex = false;
for (; (i<codeLength); i++) {
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

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[len(memory)] = c;
memory->length = nLength+1;
} else {
memory->data[len(memory)] = c;
}
};
};
i--;

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] = makeToken(pos,lineNb,memory,currentType);
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] = makeToken(pos,lineNb,memory,currentType);
}
};
}
else if ((c==(char)39)) {
i++;
char n = s[i];
char * toInt = intToStr((long int)nc);
memory = strToArr(toInt);
i++;
c = s[i];
if ((c!=(char)39)) {
lexerErr(lineNb,i,"Missing closing tag in char declaration.");
}

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] = makeToken(i-1,lineNb,memory,TOKEN_TYPE_CHAR);
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] = makeToken(i-1,lineNb,memory,TOKEN_TYPE_CHAR);
}
};
}
else if ((c==(char)35)) {
long int pos = i;

{
long nLength = 0;
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[0] = c;
memory->length = nLength+1;
} else {
memory->data[0] = c;
}
};
i++;
for (; (i<codeLength); i++) {
c = s[i];
if ((isAlphaNumeric(c)==false)) {
break;
}

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[len(memory)] = c;
memory->length = nLength+1;
} else {
memory->data[len(memory)] = c;
}
};
};
i--;

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] = makeToken(pos,lineNb,memory,TOKEN_TYPE_KEYWORD);
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] = makeToken(pos,lineNb,memory,TOKEN_TYPE_KEYWORD);
}
};
}
else if (inArray(c,enclavers)) {

{
long nLength = 0;
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[0] = c;
memory->length = nLength+1;
} else {
memory->data[0] = c;
}
};

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] = makeToken(i,lineNb,memory,TOKEN_TYPE_ENCL);
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] = makeToken(i,lineNb,memory,TOKEN_TYPE_ENCL);
}
};
}
else if (inArray(c,syntaxes)) {
if ((c==60)) {
long int pos = i;
char isCast = false;

{
long nLength = 0;
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[0] = c;
memory->length = nLength+1;
} else {
memory->data[0] = c;
}
};
i++;
for (; (i<codeLength); i++) {
c = s[i];
if ((c==62)) {
isCast = true;

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[len(memory)] = c;
memory->length = nLength+1;
} else {
memory->data[len(memory)] = c;
}
};
break;
}
if ((isAlphaNumeric(c)==false)&&(c!=42)&&(c!=58)&&(c!=95)&&(c!=91)&&(c!=93)) {
break;
}

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[len(memory)] = c;
memory->length = nLength+1;
} else {
memory->data[len(memory)] = c;
}
};
};
if ((isCast==true)) {

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] = makeToken(pos,lineNb,memory,TOKEN_TYPE_CAST);
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] = makeToken(pos,lineNb,memory,TOKEN_TYPE_CAST);
}
};
continue;
}
i = pos;
c = 60;
clear(memory);
}

{
long nLength = 0;
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[0] = c;
memory->length = nLength+1;
} else {
memory->data[0] = c;
}
};
long int pos = i;
i++;
char fc = c;
for (; (i<codeLength); i++) {
c = s[i];

        char ____BAH_COMPILER_VAR_63 = 0;
        for(int i=syntaxes->length-1; i!=-1;i--) {
            if (syntaxes->data[i] == c) {
                ____BAH_COMPILER_VAR_63=1;
                break;
            };
        }
        if ((____BAH_COMPILER_VAR_63==false)) {
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

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[len(memory)] = c;
memory->length = nLength+1;
} else {
memory->data[len(memory)] = c;
}
};
};
i--;

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] = makeToken(pos,lineNb,memory,TOKEN_TYPE_SYNTAX);
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] = makeToken(pos,lineNb,memory,TOKEN_TYPE_SYNTAX);
}
};
}
else if ((c==46)) {

{
long nLength = 0;
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[0] = c;
memory->length = nLength+1;
} else {
memory->data[0] = c;
}
};

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] = makeToken(i,lineNb,memory,TOKEN_TYPE_SEP);
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] = makeToken(i,lineNb,memory,TOKEN_TYPE_SEP);
}
};
}
else if (isAlphaNumeric(c)||(c==95)) {

{
long nLength = 0;
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[0] = c;
memory->length = nLength+1;
} else {
memory->data[0] = c;
}
};
long int pos = i;
i++;
for (; (i<codeLength); i++) {
c = s[i];
if ((isAlphaNumeric(c)==false)) {
if ((c!=95)) {
if ((c==62)) {
char lc = memory->data[len(memory)-1];
if ((lc==45)) {

{
long nLength = len(memory)-1;
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[len(memory)-1] = (char)0;
memory->length = nLength+1;
} else {
memory->data[len(memory)-1] = (char)0;
}
};
i--;
break;
}
}
break;
}
}

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[len(memory)] = c;
memory->length = nLength+1;
} else {
memory->data[len(memory)] = c;
}
};
};
i--;
tokenType currentType = TOKEN_TYPE_VAR;
char * memstr = arrAsStr(memory);

        char ____BAH_COMPILER_VAR_64 = 0;
        for(int i=keywords->length-1; i!=-1;i--) {
            if (keywords->data[i] != 0 && strcmp(keywords->data[i], memstr) == 0) {
                ____BAH_COMPILER_VAR_64=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_64) {
currentType = TOKEN_TYPE_KEYWORD;
}

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] = makeToken(pos,lineNb,memory,currentType);
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] = makeToken(pos,lineNb,memory,currentType);
}
};
}
};
totalLines = totalLines+lineNb-1;
dur = getTimeUnix()-dur;
totalLexerTime = totalLexerTime+dur;
return tokens;
};
char hasStructSep(struct string n){
if (n.count(&n,".")) {
return true;
}
if (n.count(&n,"->")) {
return true;
}
return false;
};
struct string splitStructSepBefore(struct string n){
if (n.count(&n,".")) {
char * ____BAH_COMPILER_VAR_65 =splitStringBefore(n,".");struct string res = string(____BAH_COMPILER_VAR_65);
return res;
}
if (n.count(&n,"->")) {
char * ____BAH_COMPILER_VAR_66 =splitStringBefore(n,"->");struct string res = string(____BAH_COMPILER_VAR_66);
return res;
}
return string("");
};
struct string splitStructSepAfter(struct string n){
register long int i = n.length;
while ((i>0)) {
char c = n.charAt(&n,i);
if ((c==46)) {
break;
}
else if ((c==62)) {
char pc = n.charAt(&n,i-1);
if ((pc==45)) {
break;
}
}
i = i-1;
};
i = i+1;
n.trimLeft(&n,i);
return n;
};
struct cStruct* searchStruct(char * name,struct Elems* elems){
struct string n = string(name);
n.replace(&n,"&","");
n.replace(&n,"*","");
name = n.content;
register long int i = len(elems->structs)-1;
for (; (i!=-1); i--) {
struct cStruct* s = elems->structs->data[i];
if ((strcmp(s->name, name) == 0)) {
return s;
}
};
return null;
};
struct structMemb* searchStructMemb(char * name,struct cStruct* s,struct Elems* elems){
struct string n = string(name);
if (hasStructSep(n)) {
struct string rn = splitStructSepBefore(n);
name = rn.content;
n.trimLeft(&n,rn.length);
if (n.hasPrefix(&n,".")) {
n.trimLeft(&n,1);
}
else {
n.trimLeft(&n,2);
}
char * membs = n.content;
struct structMemb* memb = searchStructMemb(name,s,elems);
if ((n.length>0)) {
s = searchStruct(memb->type,elems);
char * nstr = n.str(&n);
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
struct structMemb* ____BAH_COMPILER_VAR_67 = memoryAlloc(sizeof(struct structMemb));
____BAH_COMPILER_VAR_67->name = "";
____BAH_COMPILER_VAR_67->type = "";
____BAH_COMPILER_VAR_67->isConst = false;
____BAH_COMPILER_VAR_67->constVal = "";
____BAH_COMPILER_VAR_67->isArray = false;
____BAH_COMPILER_VAR_67->from = "";
____BAH_COMPILER_VAR_67->declScope= null;
____BAH_COMPILER_VAR_67->isGlobal = false;
____BAH_COMPILER_VAR_67->declRope= null;
____BAH_COMPILER_VAR_67->isReg = false;
____BAH_COMPILER_VAR_67->def = "";
____BAH_COMPILER_VAR_67->isFn = false;
struct structMemb* sm = ____BAH_COMPILER_VAR_67;
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
return searchStructMemb(name,es,elems);
};
struct func* searchFunc(char * n,struct Elems* e,char c);
struct func* parseFnType(struct string n);
struct func* searchStructMethod(char * name,struct cStruct* s,struct Elems* elems){
if ((s==null)) {
return null;
}
char * ____BAH_COMPILER_VAR_68 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("__");
long int strLen_1 = strlen(name);
long int strLen_2 = strlen(s->name);
;                            
            ____BAH_COMPILER_VAR_68 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_68+currStrOff, s->name, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_68+currStrOff, "__", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_68+currStrOff, name, strLen_1);
            currStrOff += strLen_1;
        
        }struct func* fn = searchFunc(____BAH_COMPILER_VAR_68,elems,true);
if ((fn!=null)) {
return fn;
}
register long int i = 0;
for (; (i<len(s->members)); i++) {
if ((strcmp(s->members->data[i]->name, name) == 0)) {
struct string ____BAH_COMPILER_VAR_69 =string(s->members->data[i]->type);fn = parseFnType(____BAH_COMPILER_VAR_69);
fn->name = name;
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
if ((strcmp(t, "cpstring") == 0)||(strcmp(t, "ptr") == 0)||typeAsStar(t)||strHasPrefix(t,"[]")||strHasPrefix(t,"chan:")||strHasPrefix(t,"map:")) {
return true;
}
return false;
};
char isRCPtype(char * t,struct Elems* elems){
if ((isRCPpointerType(t)==true)) {
return true;
}
struct cStruct* s = searchStruct(t,elems);
if ((s!=null)&&(s->isBinding==false)) {
return true;
}
return false;
};
struct string getCType(char * t,struct Elems* elems){
if ((strlen(t)==0)) {
return string("void");
}
struct string tp = string(t);
tp.replace(&tp," ","");
if (tp.hasPrefix(&tp,"[]")) {
tp.trimLeft(&tp,2);
char * tpstr = tp.str(&tp);
tp = getCType(tpstr,elems);
t = tp.str(&tp);
char * ____BAH_COMPILER_VAR_70 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t);
long int strLen_1 = strlen(")*");
long int strLen_2 = strlen("array(");
;                            
            ____BAH_COMPILER_VAR_70 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_70+currStrOff, "array(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_70+currStrOff, t, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_70+currStrOff, ")*", strLen_1);
            currStrOff += strLen_1;
        
        }char * r = ____BAH_COMPILER_VAR_70;
return string(r);
}
struct string ctp = tp;
ctp.replace(&ctp,"*","");
if ((tp.hasPrefix(&tp,"chan:")==1)) {
tp.set(&tp,"struct channel *");
}
else if ((tp.hasPrefix(&tp,"map:")==1)) {
tp.set(&tp,"struct mapWrapper *");
}
else if ((tp.hasPrefix(&tp,"buffer:")==1)) {
tp.set(&tp,"char*");
}
else if ((strcmp(ctp.str(&ctp), "int") == 0)) {
tp.replace(&tp,"int","long int");
}
else if ((strcmp(ctp.str(&ctp), "int32") == 0)) {
tp.replace(&tp,"int32","int");
}
else if ((strcmp(ctp.str(&ctp), "uint32") == 0)) {
tp.replace(&tp,"uint32","unsigned int");
}
else if ((strcmp(ctp.str(&ctp), "uint") == 0)) {
tp.replace(&tp,"uint","unsigned long int");
}
else if ((strcmp(ctp.str(&ctp), "float32") == 0)) {
tp.replace(&tp,"float32","float");
}
else if ((strcmp(ctp.str(&ctp), "ufloat32") == 0)) {
tp.replace(&tp,"ufloat32","unsigned float");
}
else if ((strcmp(ctp.str(&ctp), "ufloat") == 0)) {
tp.replace(&tp,"ufloat","unsigned double");
}
else if ((strcmp(ctp.str(&ctp), "float") == 0)) {
tp.replace(&tp,"float","double");
}
else if ((strcmp(ctp.str(&ctp), "long") == 0)) {
tp.replace(&tp,"long","long long");
}
else if ((strcmp(ctp.str(&ctp), "ulong") == 0)) {
tp.replace(&tp,"ulong","unsigned long long");
}
else if ((strcmp(ctp.str(&ctp), "cpstring") == 0)) {
tp.replace(&tp,"cpstring","char *");
}
else if ((strcmp(ctp.str(&ctp), "ptr") == 0)) {
tp.replace(&tp,"ptr","void *");
}
else if ((strcmp(ctp.str(&ctp), "ushort") == 0)) {
tp.replace(&tp,"ushort","unsigned short");
}
else if ((strcmp(ctp.str(&ctp), "byte") == 0)) {
tp.replace(&tp,"byte","unsigned char");
}
else if ((strcmp(ctp.str(&ctp), "bool") == 0)) {
tp.replace(&tp,"bool","char");
}
else if ((strcmp(ctp.str(&ctp), "char") == 0)) {
}
else {
char * ctpstr = ctp.str(&ctp);
struct cStruct* s = searchStruct(ctpstr,elems);
if ((s!=null)) {
tp.prepend(&tp,"struct ");
}
else {
register long int i = 0;
while ((i<len(elems->types))) {
char * ct = elems->types->data[i];
if (ctp.compare(&ctp,ct)) {
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
char compTypeEquiv(char * a,char * b,char first){
if ((strcmp(a, "cpstring") == 0)&&strHasPrefix(b,"buffer:")) {
return true;
}

        char ____BAH_COMPILER_VAR_71 = 0;
        for(int i=intTypes->length-1; i!=-1;i--) {
            if (intTypes->data[i] != 0 && strcmp(intTypes->data[i], a) == 0) {
                ____BAH_COMPILER_VAR_71=1;
                break;
            };
        }
        
        char ____BAH_COMPILER_VAR_72 = 0;
        for(int i=intTypes->length-1; i!=-1;i--) {
            if (intTypes->data[i] != 0 && strcmp(intTypes->data[i], b) == 0) {
                ____BAH_COMPILER_VAR_72=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_71&&____BAH_COMPILER_VAR_72) {
return true;
}

        char ____BAH_COMPILER_VAR_73 = 0;
        for(int i=floatTypes->length-1; i!=-1;i--) {
            if (floatTypes->data[i] != 0 && strcmp(floatTypes->data[i], a) == 0) {
                ____BAH_COMPILER_VAR_73=1;
                break;
            };
        }
        
        char ____BAH_COMPILER_VAR_74 = 0;
        for(int i=floatTypes->length-1; i!=-1;i--) {
            if (floatTypes->data[i] != 0 && strcmp(floatTypes->data[i], b) == 0) {
                ____BAH_COMPILER_VAR_74=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_73&&____BAH_COMPILER_VAR_74) {
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
if ((strcmp(a, "ptr") == 0)||(strcmp(b, "ptr") == 0)||(strcmp(a, b) == 0)) {
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
void *(*calculateOffset)(struct reflectElement* this,void * origin);
};
void * reflectElement__calculateOffset(struct reflectElement* this,void * origin){
char * base = origin;
return base+this->offset;
};
typedef array(struct reflectElement)* __BAH_ARR_TYPE_reflectElement;
struct reflectElement __reflect(void * v,long int s,char * t,char * n,char isArr,struct reflectElement* ae,char isStruct,__BAH_ARR_TYPE_reflectElement sl,long int offset){
struct reflectElement ____BAH_COMPILER_VAR_75 = {};
____BAH_COMPILER_VAR_75.type= null;
____BAH_COMPILER_VAR_75.name= null;
____BAH_COMPILER_VAR_75.arrayElem= null;
____BAH_COMPILER_VAR_75.structLayout = memoryAlloc(sizeof(array(struct reflectElement)));
            ____BAH_COMPILER_VAR_75.structLayout->length = 0;
            ____BAH_COMPILER_VAR_75.structLayout->elemSize = sizeof(struct reflectElement);
            ____BAH_COMPILER_VAR_75.value= null;
____BAH_COMPILER_VAR_75.calculateOffset = reflectElement__calculateOffset;
#define re ____BAH_COMPILER_VAR_75
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
if ((a.count(&a,".")>0)) {
array(struct string)* parts = splitString(a,".");
struct string p1 = parts->data[0];
struct string p2 = parts->data[1];
register long int j = 0;
for (; (j<len(syms)); j++) {
struct reflectElement s = syms->data[j];
if ((strcmp(s.name, p1.str(&p1)) == 0)) {
register long int k = 0;
for (; (k<len(s.structLayout)); k++) {
struct reflectElement m = s.structLayout->data[k];
if ((strcmp(m.name, p2.str(&p2)) == 0)) {
m.value = m.calculateOffset(&m,s.value);
return m;
}
};
break;
}
};
}
else {
register long int j = 0;
for (; (j<len(syms)); j++) {
struct reflectElement s = syms->data[j];
if ((strcmp(s.name, a.str(&a)) == 0)) {
return s;
}
};
}
struct reflectElement ____BAH_COMPILER_VAR_76 = {};
____BAH_COMPILER_VAR_76.type= null;
____BAH_COMPILER_VAR_76.name= null;
____BAH_COMPILER_VAR_76.arrayElem= null;
____BAH_COMPILER_VAR_76.structLayout = memoryAlloc(sizeof(array(struct reflectElement)));
            ____BAH_COMPILER_VAR_76.structLayout->length = 0;
            ____BAH_COMPILER_VAR_76.structLayout->elemSize = sizeof(struct reflectElement);
            ____BAH_COMPILER_VAR_76.value= null;
____BAH_COMPILER_VAR_76.calculateOffset = reflectElement__calculateOffset;
#define ns ____BAH_COMPILER_VAR_76
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
struct jsonElement*(*get)(struct jsonElement* this,char * key);
char *(*str)(struct jsonElement* this);
void(*scan)(struct jsonElement* this,struct reflectElement e);
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

{
long nLength = j-1;
if (nk->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nk->data, (nLength+50)*sizeof(char));
nk->data = newPtr;
}
nk->data[j-1] = c;
nk->length = nLength+1;
} else {
nk->data[j-1] = c;
}
};
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
struct jsonElement* ov = this->get(this,m.name);
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
*ep = memoryAlloc(strlen(this->content)+1);
strcpy(*ep,this->content);
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

{
long nLength = i;
if (arr->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(arr->data, (nLength+50)*sizeof(long int));
arr->data = newPtr;
}
arr->data[i] = strToInt(c->content);
arr->length = nLength+1;
} else {
arr->data[i] = strToInt(c->content);
}
};
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

{
long nLength = i;
if (arr->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(arr->data, (nLength+50)*sizeof(double));
arr->data = newPtr;
}
arr->data[i] = strToFloat(c->content);
arr->length = nLength+1;
} else {
arr->data[i] = strToFloat(c->content);
}
};
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

{
long nLength = i;
if (arr->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(arr->data, (nLength+50)*sizeof(char *));
arr->data = newPtr;
}
arr->data[i] = memoryAlloc(strlen(c->content)+1);
arr->length = nLength+1;
} else {
arr->data[i] = memoryAlloc(strlen(c->content)+1);
}
};
strcpy(arr->data[i],c->content);
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
m.value = m.calculateOffset(&m,ne);
struct jsonElement* ov = c->get(c,m.name);
if ((ov!=null)) {
json_scan_inner(ov,m,true);
}
j = j+1;
};

{
long nLength = i;
if (arr->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(arr->data, (nLength+50)*sizeof(void *));
arr->data = newPtr;
}
arr->data[i] = ne;
arr->length = nLength+1;
} else {
arr->data[i] = ne;
}
};
i = i+1;
};
}
}
else if (strHasPrefix(e.type,"map:")) {
struct mapWrapper** p = e.value;
register long int i = 0;
for (; (i<len(this->children)); i++) {
struct jsonElement* c = this->children->data[i];
struct reflectElement* ae = e.arrayElem;
void * v = memoryAlloc(ae->size);
ae->value = &v;
register long int j = 0;
for (; (j<len(ae->structLayout)); j++) {
struct reflectElement m = ae->structLayout->data[j];
m.value = m.calculateOffset(&m,&v);

{
long nLength = j;
if (ae->structLayout->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(ae->structLayout->data, (nLength+50)*sizeof(struct reflectElement));
ae->structLayout->data = newPtr;
}
ae->structLayout->data[j] = m;
ae->structLayout->length = nLength+1;
} else {
ae->structLayout->data[j] = m;
}
};
};
json_scan_inner(c,*ae,true);
struct string k = string(c->key);
k.trimLeft(&k,1);
k.trimRight(&k,1);
if (strCount(ae->type,"*")||(strcmp(ae->type, "ptr") == 0)||(strcmp(ae->type, "cpstring") == 0)||strHasPrefix(ae->type,"[]")||strHasPrefix(ae->type,"map:")) {
char * ____BAH_COMPILER_VAR_77 =k.str(&k);mapWrapper__set(*p,____BAH_COMPILER_VAR_77,v);
}
else {
char * ____BAH_COMPILER_VAR_78 =k.str(&k);mapWrapper__set(*p,____BAH_COMPILER_VAR_78,&v);
}
};
}
};
struct jsonElement* parseJson(char * s){
struct jsonElement* ____BAH_COMPILER_VAR_79 = memoryAlloc(sizeof(struct jsonElement));
____BAH_COMPILER_VAR_79->key= null;
____BAH_COMPILER_VAR_79->content= null;
____BAH_COMPILER_VAR_79->children = memoryAlloc(sizeof(array(struct jsonElement*)));
            ____BAH_COMPILER_VAR_79->children->length = 0;
            ____BAH_COMPILER_VAR_79->children->elemSize = sizeof(struct jsonElement*);
            ____BAH_COMPILER_VAR_79->get = jsonElement__get;
____BAH_COMPILER_VAR_79->str = jsonElement__str;
____BAH_COMPILER_VAR_79->scan = jsonElement__scan;
struct jsonElement* jsonElem = ____BAH_COMPILER_VAR_79;
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

{
long nLength = len(ns)-1;
if (ns->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(ns->data, (nLength+50)*sizeof(char));
ns->data = newPtr;
}
ns->data[len(ns)-1] = c;
ns->length = nLength+1;
} else {
ns->data[len(ns)-1] = c;
}
};
}
else {

{
long nLength = len(ns);
if (ns->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(ns->data, (nLength+50)*sizeof(char));
ns->data = newPtr;
}
ns->data[len(ns)] = c;
ns->length = nLength+1;
} else {
ns->data[len(ns)] = c;
}
};
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

{
long nLength = len(currentElem);
if (currentElem->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(currentElem->data, (nLength+50)*sizeof(char));
currentElem->data = newPtr;
}
currentElem->data[len(currentElem)] = c;
currentElem->length = nLength+1;
} else {
currentElem->data[len(currentElem)] = c;
}
};
i = i+1;
continue;
}
if ((c==44)) {
char * ____BAH_COMPILER_VAR_80 =arrToStr(currentElem);struct jsonElement* child = parseJson(____BAH_COMPILER_VAR_80);
if ((child!=null)) {

{
long nLength = elemIndex;
if (jsonElem->children->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(jsonElem->children->data, (nLength+50)*sizeof(struct jsonElement*));
jsonElem->children->data = newPtr;
}
jsonElem->children->data[elemIndex] = child;
jsonElem->children->length = nLength+1;
} else {
jsonElem->children->data[elemIndex] = child;
}
};
}
clear(currentElem);
elemIndex = elemIndex+1;
}
else {
if (isSpace(c)) {
i = i+1;
continue;
}

{
long nLength = len(currentElem);
if (currentElem->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(currentElem->data, (nLength+50)*sizeof(char));
currentElem->data = newPtr;
}
currentElem->data[len(currentElem)] = c;
currentElem->length = nLength+1;
} else {
currentElem->data[len(currentElem)] = c;
}
};
}
i = i+1;
};
char * ____BAH_COMPILER_VAR_81 =arrToStr(currentElem);struct jsonElement* child = parseJson(____BAH_COMPILER_VAR_81);
if ((child!=null)) {

{
long nLength = elemIndex;
if (jsonElem->children->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(jsonElem->children->data, (nLength+50)*sizeof(struct jsonElement*));
jsonElem->children->data = newPtr;
}
jsonElem->children->data[elemIndex] = child;
jsonElem->children->length = nLength+1;
} else {
jsonElem->children->data[elemIndex] = child;
}
};
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

{
long nLength = len(currentElem);
if (currentElem->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(currentElem->data, (nLength+50)*sizeof(char));
currentElem->data = newPtr;
}
currentElem->data[len(currentElem)] = c;
currentElem->length = nLength+1;
} else {
currentElem->data[len(currentElem)] = c;
}
};
}
else {

{
long nLength = len(currentKey);
if (currentKey->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(currentKey->data, (nLength+50)*sizeof(char));
currentKey->data = newPtr;
}
currentKey->data[len(currentKey)] = c;
currentKey->length = nLength+1;
} else {
currentKey->data[len(currentKey)] = c;
}
};
}
i = i+1;
continue;
}
if ((c==58)) {
isVal = 1;
}
else if ((c==44)) {
char * ____BAH_COMPILER_VAR_82 =arrToStr(currentElem);struct jsonElement* elem = parseJson(____BAH_COMPILER_VAR_82);
if ((elem!=null)) {
elem->key = arrToStr(currentKey);

{
long nLength = elemIndex;
if (jsonElem->children->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(jsonElem->children->data, (nLength+50)*sizeof(struct jsonElement*));
jsonElem->children->data = newPtr;
}
jsonElem->children->data[elemIndex] = elem;
jsonElem->children->length = nLength+1;
} else {
jsonElem->children->data[elemIndex] = elem;
}
};
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

{
long nLength = len(currentElem);
if (currentElem->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(currentElem->data, (nLength+50)*sizeof(char));
currentElem->data = newPtr;
}
currentElem->data[len(currentElem)] = c;
currentElem->length = nLength+1;
} else {
currentElem->data[len(currentElem)] = c;
}
};
}
else {

{
long nLength = len(currentKey);
if (currentKey->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(currentKey->data, (nLength+50)*sizeof(char));
currentKey->data = newPtr;
}
currentKey->data[len(currentKey)] = c;
currentKey->length = nLength+1;
} else {
currentKey->data[len(currentKey)] = c;
}
};
}
}
i = i+1;
};
char * ____BAH_COMPILER_VAR_83 =arrToStr(currentElem);struct jsonElement* elem = parseJson(____BAH_COMPILER_VAR_83);
if ((elem!=null)) {
elem->key = arrToStr(currentKey);

{
long nLength = elemIndex;
if (jsonElem->children->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(jsonElem->children->data, (nLength+50)*sizeof(struct jsonElement*));
jsonElem->children->data = newPtr;
}
jsonElem->children->data[elemIndex] = elem;
jsonElem->children->length = nLength+1;
} else {
jsonElem->children->data[elemIndex] = elem;
}
};
}
}
return jsonElem;
};
char * jsonEscapeStr(char * s){
array(char)* a = strAsArr(s);
array(char)* r = memoryAlloc(sizeof(array(char)));

r->length = 0;
r->elemSize = sizeof(char);
register long int i = 0;
while ((i<len(a))) {
char c = a->data[i];
if ((c==(char)34)) {

{
long nLength = len(r);
if (r->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(r->data, (nLength+50)*sizeof(char));
r->data = newPtr;
}
r->data[len(r)] = (char)92;
r->length = nLength+1;
} else {
r->data[len(r)] = (char)92;
}
};
}
else if ((c==(char)10)) {

{
long nLength = len(r);
if (r->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(r->data, (nLength+50)*sizeof(char));
r->data = newPtr;
}
r->data[len(r)] = (char)92;
r->length = nLength+1;
} else {
r->data[len(r)] = (char)92;
}
};

{
long nLength = len(r);
if (r->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(r->data, (nLength+50)*sizeof(char));
r->data = newPtr;
}
r->data[len(r)] = 110;
r->length = nLength+1;
} else {
r->data[len(r)] = 110;
}
};
i = i+1;
continue;
}
else if ((c==(char)13)) {

{
long nLength = len(r);
if (r->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(r->data, (nLength+50)*sizeof(char));
r->data = newPtr;
}
r->data[len(r)] = (char)92;
r->length = nLength+1;
} else {
r->data[len(r)] = (char)92;
}
};

{
long nLength = len(r);
if (r->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(r->data, (nLength+50)*sizeof(char));
r->data = newPtr;
}
r->data[len(r)] = 114;
r->length = nLength+1;
} else {
r->data[len(r)] = 114;
}
};
i = i+1;
continue;
}

{
long nLength = len(r);
if (r->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(r->data, (nLength+50)*sizeof(char));
r->data = newPtr;
}
r->data[len(r)] = c;
r->length = nLength+1;
} else {
r->data[len(r)] = c;
}
};
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
char * ____BAH_COMPILER_VAR_84 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tabsStr);
long int strLen_1 = strlen("\t");
;                            
            ____BAH_COMPILER_VAR_84 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_84+currStrOff, tabsStr, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_84+currStrOff, "\t", strLen_1);
            currStrOff += strLen_1;
        
        }tabsStr = ____BAH_COMPILER_VAR_84;
i = i+1;
};
char * s = "{\n";
i = 0;
while ((i<len(e.structLayout))) {
struct reflectElement m = e.structLayout->data[i];
i = i+1;
if ((i<len(e.structLayout))) {
char * ____BAH_COMPILER_VAR_85 =null;char * ____BAH_COMPILER_VAR_86 =toJson__inner(m,true,tabs);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_86);
long int strLen_1 = strlen(",\n");
long int strLen_2 = strlen("\": ");
long int strLen_3 = strlen(m.name);
long int strLen_4 = strlen("\"");
long int strLen_5 = strlen(tabsStr);
long int strLen_6 = strlen(s);
;                            
            ____BAH_COMPILER_VAR_85 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_85+currStrOff, s, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_85+currStrOff, tabsStr, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_85+currStrOff, "\"", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_85+currStrOff, m.name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_85+currStrOff, "\": ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_85+currStrOff, ____BAH_COMPILER_VAR_86, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_85+currStrOff, ",\n", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_85;
}
else {
char * ____BAH_COMPILER_VAR_87 =null;char * ____BAH_COMPILER_VAR_88 =toJson__inner(m,true,tabs);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_88);
long int strLen_1 = strlen("\n");
long int strLen_2 = strlen("\": ");
long int strLen_3 = strlen(m.name);
long int strLen_4 = strlen("\"");
long int strLen_5 = strlen(tabsStr);
long int strLen_6 = strlen(s);
;                            
            ____BAH_COMPILER_VAR_87 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_87+currStrOff, s, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_87+currStrOff, tabsStr, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_87+currStrOff, "\"", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_87+currStrOff, m.name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_87+currStrOff, "\": ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_87+currStrOff, ____BAH_COMPILER_VAR_88, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_87+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_87;
}
};
tabs = tabs-1;
tabsStr = "";
i = 0;
while ((i<tabs)) {
char * ____BAH_COMPILER_VAR_89 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tabsStr);
long int strLen_1 = strlen("\t");
;                            
            ____BAH_COMPILER_VAR_89 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_89+currStrOff, tabsStr, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_89+currStrOff, "\t", strLen_1);
            currStrOff += strLen_1;
        
        }tabsStr = ____BAH_COMPILER_VAR_89;
i = i+1;
};
char * ____BAH_COMPILER_VAR_90 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tabsStr);
long int strLen_1 = strlen("}");
long int strLen_2 = strlen(s);
;                            
            ____BAH_COMPILER_VAR_90 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_90+currStrOff, s, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_90+currStrOff, tabsStr, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_90+currStrOff, "}", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_90;
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
char * ____BAH_COMPILER_VAR_91 =null;char * ____BAH_COMPILER_VAR_92 =jsonEscapeStr(s);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_92);
long int strLen_1 = strlen("\"");
long int strLen_2 = strlen("\"");
;                            
            ____BAH_COMPILER_VAR_91 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_91+currStrOff, "\"", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_91+currStrOff, ____BAH_COMPILER_VAR_92, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_91+currStrOff, "\"", strLen_1);
            currStrOff += strLen_1;
        
        }return ____BAH_COMPILER_VAR_91;
}
else {
char ** sp = e.value;
char * s = *sp;
char * ____BAH_COMPILER_VAR_93 =null;char * ____BAH_COMPILER_VAR_94 =jsonEscapeStr(s);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_94);
long int strLen_1 = strlen("\"");
long int strLen_2 = strlen("\"");
;                            
            ____BAH_COMPILER_VAR_93 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_93+currStrOff, "\"", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_93+currStrOff, ____BAH_COMPILER_VAR_94, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_93+currStrOff, "\"", strLen_1);
            currStrOff += strLen_1;
        
        }return ____BAH_COMPILER_VAR_93;
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
char * ____BAH_COMPILER_VAR_95 =null;char * ____BAH_COMPILER_VAR_96 =intToStr(arr->data[i]);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_96);
;                            
            ____BAH_COMPILER_VAR_95 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_95+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_95+currStrOff, ____BAH_COMPILER_VAR_96, strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_95;
i = i+1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_97 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s);
long int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_97 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_97+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_97+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_97;
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
char * ____BAH_COMPILER_VAR_98 =null;char * ____BAH_COMPILER_VAR_99 =floatToStr(arr->data[i]);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_99);
;                            
            ____BAH_COMPILER_VAR_98 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_98+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_98+currStrOff, ____BAH_COMPILER_VAR_99, strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_98;
i = i+1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_100 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s);
long int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_100 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_100+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_100+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_100;
}
};
}
else if ((strcmp(ae->type, "cpstring") == 0)) {
array(char *)* arr = memoryAlloc(sizeof(array(char *)));

arr->length = 0;
arr->elemSize = sizeof(char *);
void ** arrPtr = e.value;
arr = *arrPtr;
char * ____BAH_COMPILER_VAR_101 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s);
long int strLen_1 = strlen("\n");
;                            
            ____BAH_COMPILER_VAR_101 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_101+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_101+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_101;
register long int i = 0;
while ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_102 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s);
long int strLen_1 = strlen(arr->data[i]);
;                            
            ____BAH_COMPILER_VAR_102 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_102+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_102+currStrOff, arr->data[i], strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_102;
i = i+1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_103 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s);
long int strLen_1 = strlen(",\n");
;                            
            ____BAH_COMPILER_VAR_103 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_103+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_103+currStrOff, ",\n", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_103;
}
else {
char * ____BAH_COMPILER_VAR_104 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s);
long int strLen_1 = strlen("\n");
;                            
            ____BAH_COMPILER_VAR_104 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_104+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_104+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_104;
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
m.value = m.calculateOffset(&m,ae->value);

{
long nLength = j;
if (ae->structLayout->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(ae->structLayout->data, (nLength+50)*sizeof(struct reflectElement));
ae->structLayout->data = newPtr;
}
ae->structLayout->data[j] = m;
ae->structLayout->length = nLength+1;
} else {
ae->structLayout->data[j] = m;
}
};
j = j+1;
};
char * ____BAH_COMPILER_VAR_105 =null;char * ____BAH_COMPILER_VAR_106 =toJson__inner(*ae,false,tabs);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_106);
;                            
            ____BAH_COMPILER_VAR_105 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_105+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_105+currStrOff, ____BAH_COMPILER_VAR_106, strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_105;
i = i+1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_107 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s);
long int strLen_1 = strlen(",\n");
;                            
            ____BAH_COMPILER_VAR_107 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_107+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_107+currStrOff, ",\n", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_107;
}
else {
char * ____BAH_COMPILER_VAR_108 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s);
long int strLen_1 = strlen("\n");
;                            
            ____BAH_COMPILER_VAR_108 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_108+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_108+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_108;
}
};
}
char * ____BAH_COMPILER_VAR_109 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s);
long int strLen_1 = strlen("]");
;                            
            ____BAH_COMPILER_VAR_109 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_109+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_109+currStrOff, "]", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_109;
return s;
}
return "";
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
char * ____BAH_COMPILER_VAR_110 = name;
struct reflectElement ____BAH_COMPILER_VAR_111 = __reflect(____BAH_COMPILER_VAR_110, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, 0);
char * ____BAH_COMPILER_VAR_112 =null;char * ____BAH_COMPILER_VAR_113 =toJson(e);char * ____BAH_COMPILER_VAR_114 =intToStr(line);char * ____BAH_COMPILER_VAR_115 =toJson(____BAH_COMPILER_VAR_111);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_113);
long int strLen_1 = strlen("\n    },\n    ");
long int strLen_2 = strlen("\",\n        \"element\": ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_114);
long int strLen_4 = strlen(":");
long int strLen_5 = strlen(compilerState.currentFile);
long int strLen_6 = strlen(",\n        \"path\": \"");
long int strLen_7 = strlen(____BAH_COMPILER_VAR_115);
long int strLen_8 = strlen("\n    {\n        \"name\": ");
;                            
            ____BAH_COMPILER_VAR_112 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_112+currStrOff, "\n    {\n        \"name\": ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_112+currStrOff, ____BAH_COMPILER_VAR_115, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_112+currStrOff, ",\n        \"path\": \"", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_112+currStrOff, compilerState.currentFile, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_112+currStrOff, ":", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_112+currStrOff, ____BAH_COMPILER_VAR_114, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_112+currStrOff, "\",\n        \"element\": ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_112+currStrOff, ____BAH_COMPILER_VAR_113, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_112+currStrOff, "\n    },\n    ", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_116 =____BAH_COMPILER_VAR_112;println(____BAH_COMPILER_VAR_116);
};
void debugError(char * name,long int line,long int from,long int to,struct reflectElement e){
if ((debug==false)) {
return;
}
char * ____BAH_COMPILER_VAR_117 = name;
struct reflectElement ____BAH_COMPILER_VAR_118 = __reflect(____BAH_COMPILER_VAR_117, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, 0);
char * ____BAH_COMPILER_VAR_119 =null;char * ____BAH_COMPILER_VAR_120 =toJson(e);char * ____BAH_COMPILER_VAR_121 =intToStr(to);char * ____BAH_COMPILER_VAR_122 =intToStr(from);char * ____BAH_COMPILER_VAR_123 =intToStr(line);char * ____BAH_COMPILER_VAR_124 =toJson(____BAH_COMPILER_VAR_118);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_120);
long int strLen_1 = strlen("\n    },\n    ");
long int strLen_2 = strlen("\n        ],\n        \"element\": ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_121);
long int strLen_4 = strlen(",\n            ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_122);
long int strLen_6 = strlen("\",\n        \"range\": [\n            ");
long int strLen_7 = strlen(____BAH_COMPILER_VAR_123);
long int strLen_8 = strlen(":");
long int strLen_9 = strlen(compilerState.currentFile);
long int strLen_10 = strlen(",\n        \"path\": \"");
long int strLen_11 = strlen(____BAH_COMPILER_VAR_124);
long int strLen_12 = strlen("\n    {\n        \"name\": ");
;                            
            ____BAH_COMPILER_VAR_119 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12);
            
                    memcpy(____BAH_COMPILER_VAR_119+currStrOff, "\n    {\n        \"name\": ", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_119+currStrOff, ____BAH_COMPILER_VAR_124, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_119+currStrOff, ",\n        \"path\": \"", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_119+currStrOff, compilerState.currentFile, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_119+currStrOff, ":", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_119+currStrOff, ____BAH_COMPILER_VAR_123, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_119+currStrOff, "\",\n        \"range\": [\n            ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_119+currStrOff, ____BAH_COMPILER_VAR_122, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_119+currStrOff, ",\n            ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_119+currStrOff, ____BAH_COMPILER_VAR_121, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_119+currStrOff, "\n        ],\n        \"element\": ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_119+currStrOff, ____BAH_COMPILER_VAR_120, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_119+currStrOff, "\n    },\n    ", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_125 =____BAH_COMPILER_VAR_119;println(____BAH_COMPILER_VAR_125);
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
struct variable* ____BAH_COMPILER_VAR_126 = v;
char ** ____BAH_COMPILER_VAR_128 = (char **)((char*)(____BAH_COMPILER_VAR_126) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_129 = __reflect(____BAH_COMPILER_VAR_128, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_130 = (char **)((char*)(____BAH_COMPILER_VAR_126) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_131 = __reflect(____BAH_COMPILER_VAR_130, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_132 = (char*)((char*)(____BAH_COMPILER_VAR_126) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_133 = __reflect(____BAH_COMPILER_VAR_132, sizeof(char), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_134 = (char **)((char*)(____BAH_COMPILER_VAR_126) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_135 = __reflect(____BAH_COMPILER_VAR_134, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_136 = (char*)((char*)(____BAH_COMPILER_VAR_126) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_137 = __reflect(____BAH_COMPILER_VAR_136, sizeof(char), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_138 = (char **)((char*)(____BAH_COMPILER_VAR_126) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_139 = __reflect(____BAH_COMPILER_VAR_138, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
void ** ____BAH_COMPILER_VAR_140 = (void **)((char*)(____BAH_COMPILER_VAR_126) + offsetof(struct variable, declScope));
struct reflectElement ____BAH_COMPILER_VAR_141 = __reflect(____BAH_COMPILER_VAR_140, sizeof(void *), "ptr", "declScope", 0, 0, 0, 0, offsetof(struct variable, declScope));
char* ____BAH_COMPILER_VAR_142 = (char*)((char*)(____BAH_COMPILER_VAR_126) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_143 = __reflect(____BAH_COMPILER_VAR_142, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));
struct rope** ____BAH_COMPILER_VAR_144 = (struct rope**)((char*)(____BAH_COMPILER_VAR_126) + offsetof(struct variable, declRope));
void ** ____BAH_COMPILER_VAR_146 = (void **)((char*)(____BAH_COMPILER_VAR_144) + offsetof(struct rope, left));
struct reflectElement ____BAH_COMPILER_VAR_147 = __reflect(____BAH_COMPILER_VAR_146, sizeof(void *), "ptr", "left", 0, 0, 0, 0, offsetof(struct rope, left));
void ** ____BAH_COMPILER_VAR_148 = (void **)((char*)(____BAH_COMPILER_VAR_144) + offsetof(struct rope, right));
struct reflectElement ____BAH_COMPILER_VAR_149 = __reflect(____BAH_COMPILER_VAR_148, sizeof(void *), "ptr", "right", 0, 0, 0, 0, offsetof(struct rope, right));
char ** ____BAH_COMPILER_VAR_150 = (char **)((char*)(____BAH_COMPILER_VAR_144) + offsetof(struct rope, str));
struct reflectElement ____BAH_COMPILER_VAR_151 = __reflect(____BAH_COMPILER_VAR_150, sizeof(char *), "cpstring", "str", 0, 0, 0, 0, offsetof(struct rope, str));
long int* ____BAH_COMPILER_VAR_152 = (long int*)((char*)(____BAH_COMPILER_VAR_144) + offsetof(struct rope, lCount));
struct reflectElement ____BAH_COMPILER_VAR_153 = __reflect(____BAH_COMPILER_VAR_152, sizeof(long int), "int", "lCount", 0, 0, 0, 0, offsetof(struct rope, lCount));
long int* ____BAH_COMPILER_VAR_154 = (long int*)((char*)(____BAH_COMPILER_VAR_144) + offsetof(struct rope, len));
struct reflectElement ____BAH_COMPILER_VAR_155 = __reflect(____BAH_COMPILER_VAR_154, sizeof(long int), "int", "len", 0, 0, 0, 0, offsetof(struct rope, len));
long int* ____BAH_COMPILER_VAR_156 = (long int*)((char*)(____BAH_COMPILER_VAR_144) + offsetof(struct rope, totalLen));
struct reflectElement ____BAH_COMPILER_VAR_157 = __reflect(____BAH_COMPILER_VAR_156, sizeof(long int), "int", "totalLen", 0, 0, 0, 0, offsetof(struct rope, totalLen));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_145 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_145->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_145->length = 6;
        ____BAH_COMPILER_VAR_145->data = memoryAlloc(____BAH_COMPILER_VAR_145->length * ____BAH_COMPILER_VAR_145->elemSize);
        ____BAH_COMPILER_VAR_145->data[0] = ____BAH_COMPILER_VAR_147;
____BAH_COMPILER_VAR_145->data[1] = ____BAH_COMPILER_VAR_149;
____BAH_COMPILER_VAR_145->data[2] = ____BAH_COMPILER_VAR_151;
____BAH_COMPILER_VAR_145->data[3] = ____BAH_COMPILER_VAR_153;
____BAH_COMPILER_VAR_145->data[4] = ____BAH_COMPILER_VAR_155;
____BAH_COMPILER_VAR_145->data[5] = ____BAH_COMPILER_VAR_157;
struct reflectElement ____BAH_COMPILER_VAR_158 = __reflect(____BAH_COMPILER_VAR_144, sizeof(struct rope), "rope*", "declRope", 0, 0, 1, ____BAH_COMPILER_VAR_145, offsetof(struct variable, declRope));
char* ____BAH_COMPILER_VAR_159 = (char*)((char*)(____BAH_COMPILER_VAR_126) + offsetof(struct variable, canBeReg));
struct reflectElement ____BAH_COMPILER_VAR_160 = __reflect(____BAH_COMPILER_VAR_159, sizeof(char), "bool", "canBeReg", 0, 0, 0, 0, offsetof(struct variable, canBeReg));
char* ____BAH_COMPILER_VAR_161 = (char*)((char*)(____BAH_COMPILER_VAR_126) + offsetof(struct variable, isReg));
struct reflectElement ____BAH_COMPILER_VAR_162 = __reflect(____BAH_COMPILER_VAR_161, sizeof(char), "bool", "isReg", 0, 0, 0, 0, offsetof(struct variable, isReg));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_127 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_127->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_127->length = 11;
        ____BAH_COMPILER_VAR_127->data = memoryAlloc(____BAH_COMPILER_VAR_127->length * ____BAH_COMPILER_VAR_127->elemSize);
        ____BAH_COMPILER_VAR_127->data[0] = ____BAH_COMPILER_VAR_129;
____BAH_COMPILER_VAR_127->data[1] = ____BAH_COMPILER_VAR_131;
____BAH_COMPILER_VAR_127->data[2] = ____BAH_COMPILER_VAR_133;
____BAH_COMPILER_VAR_127->data[3] = ____BAH_COMPILER_VAR_135;
____BAH_COMPILER_VAR_127->data[4] = ____BAH_COMPILER_VAR_137;
____BAH_COMPILER_VAR_127->data[5] = ____BAH_COMPILER_VAR_139;
____BAH_COMPILER_VAR_127->data[6] = ____BAH_COMPILER_VAR_141;
____BAH_COMPILER_VAR_127->data[7] = ____BAH_COMPILER_VAR_143;
____BAH_COMPILER_VAR_127->data[8] = ____BAH_COMPILER_VAR_158;
____BAH_COMPILER_VAR_127->data[9] = ____BAH_COMPILER_VAR_160;
____BAH_COMPILER_VAR_127->data[10] = ____BAH_COMPILER_VAR_162;
struct reflectElement ____BAH_COMPILER_VAR_163 = __reflect(____BAH_COMPILER_VAR_126, sizeof(struct variable), "variable*", "v", 0, 0, 1, ____BAH_COMPILER_VAR_127, 0);
debugPrint("var_end",line,____BAH_COMPILER_VAR_163);
}
i = i+1;
};
};
void throwErr(void * tp,char * format){
char * str = "";
char * info = "";
long int pos = 0;
if ((tp!=null)) {
struct fileMap ____BAH_COMPILER_VAR_164 = {};
____BAH_COMPILER_VAR_164.handle = -1;
____BAH_COMPILER_VAR_164.p= null;
____BAH_COMPILER_VAR_164.open = fileMap__open;
____BAH_COMPILER_VAR_164.isValid = fileMap__isValid;
____BAH_COMPILER_VAR_164.close = fileMap__close;
#define fm ____BAH_COMPILER_VAR_164
char * fileSrcStr = fm.open(&fm,compilerState.currentFile);
struct Tok* t = tp;
struct string ffmt = string(format);
if ((strlen(t->ogCont)==0)) {
t->ogCont = t->cont;
}
char * ____BAH_COMPILER_VAR_165 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t->ogCont);
long int strLen_1 = strlen("'");
long int strLen_2 = strlen("'");
;                            
            ____BAH_COMPILER_VAR_165 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_165+currStrOff, "'", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_165+currStrOff, t->ogCont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_165+currStrOff, "'", strLen_1);
            currStrOff += strLen_1;
        
        }ffmt.replace(&ffmt,"{TOKEN}",____BAH_COMPILER_VAR_165);
format = ffmt.str(&ffmt);
array(char)* line = memoryAlloc(sizeof(array(char)));

line->length = 0;
line->elemSize = sizeof(char);
register long int beg = t->pos;
while ((beg>0)) {
char c = fileSrcStr[beg];
if ((c==(char)10)) {
beg = beg+1;
break;
}
beg = beg-1;
};
pos = t->pos-beg+1;
register long int i = beg;
for (; (i<fm.size); i++) {
char c = fileSrcStr[i];
if ((c==(char)10)) {
break;
}
if ((i==t->pos)) {
array(char)* errCont = memoryAlloc(sizeof(array(char)));

errCont->length = 0;
errCont->elemSize = sizeof(char);
long int offset = i;
for (; (i<fm.size); i++) {
if ((i-offset>=strlen(t->ogCont))) {
break;
}
if ((fileSrcStr[i]!=t->ogCont[i-offset])) {
if ((isSpace(fileSrcStr[i])==false)) {
break;
}
offset++;
}

{
long nLength = len(errCont);
if (errCont->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(errCont->data, (nLength+50)*sizeof(char));
errCont->data = newPtr;
}
errCont->data[len(errCont)] = fileSrcStr[i];
errCont->length = nLength+1;
} else {
errCont->data[len(errCont)] = fileSrcStr[i];
}
};
};
char * ____BAH_COMPILER_VAR_166 =null;char * ____BAH_COMPILER_VAR_167 =arrToStr(errCont);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_167);
long int strLen_1 = strlen("\e[1;37m");
long int strLen_2 = strlen("\e[1;31m");
;                            
            ____BAH_COMPILER_VAR_166 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_166+currStrOff, "\e[1;31m", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_166+currStrOff, ____BAH_COMPILER_VAR_167, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_166+currStrOff, "\e[1;37m", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_168 =____BAH_COMPILER_VAR_166;array(char)* errTk = strToArr(____BAH_COMPILER_VAR_168);
register long int ii = 0;
for (; (ii<len(errTk)); ii++) {

{
long nLength = len(line);
if (line->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(line->data, (nLength+50)*sizeof(char));
line->data = newPtr;
}
line->data[len(line)] = errTk->data[ii];
line->length = nLength+1;
} else {
line->data[len(line)] = errTk->data[ii];
}
};
};
i--;
continue;
}

{
long nLength = len(line);
if (line->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(line->data, (nLength+50)*sizeof(char));
line->data = newPtr;
}
line->data[len(line)] = c;
line->length = nLength+1;
} else {
line->data[len(line)] = c;
}
};
};
fm.close(&fm);
str = arrToStr(line);
char * ____BAH_COMPILER_VAR_169 =null;char * ____BAH_COMPILER_VAR_170 =intToStr(pos);char * ____BAH_COMPILER_VAR_171 =intToStr(t->line);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(":");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_170);
long int strLen_2 = strlen(____BAH_COMPILER_VAR_171);
;                            
            ____BAH_COMPILER_VAR_169 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_169+currStrOff, ____BAH_COMPILER_VAR_171, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_169+currStrOff, ":", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_169+currStrOff, ____BAH_COMPILER_VAR_170, strLen_1);
            currStrOff += strLen_1;
        
        }info = ____BAH_COMPILER_VAR_169;

#undef fm
}
if ((debug==true)) {
struct Tok* t = tp;
char * ____BAH_COMPILER_VAR_172 = format;
struct reflectElement ____BAH_COMPILER_VAR_173 = __reflect(____BAH_COMPILER_VAR_172, sizeof(char *), "cpstring", "format", 0, 0, 0, 0, 0);
debugError("error",t->line,pos,pos+strlen(t->ogCont),____BAH_COMPILER_VAR_173);
debugExit();
}
else {
char * ____BAH_COMPILER_VAR_174 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("\e[0m\n");
long int strLen_1 = strlen(format);
long int strLen_2 = strlen(str);
long int strLen_3 = strlen("\n\e[1;37m\t");
long int strLen_4 = strlen(info);
long int strLen_5 = strlen(":");
long int strLen_6 = strlen(compilerState.currentFile);
long int strLen_7 = strlen("\e[1;31m[ERROR]\e[0m ");
;                            
            ____BAH_COMPILER_VAR_174 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7);
            
                    memcpy(____BAH_COMPILER_VAR_174+currStrOff, "\e[1;31m[ERROR]\e[0m ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_174+currStrOff, compilerState.currentFile, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_174+currStrOff, ":", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_174+currStrOff, info, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_174+currStrOff, "\n\e[1;37m\t", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_174+currStrOff, str, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_174+currStrOff, "\e[0m\n", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_174+currStrOff, format, strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_174);
}
exit(1);
};
void throwWarning(char * s){
char * ____BAH_COMPILER_VAR_175 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s);
long int strLen_1 = strlen("\e[0m");
long int strLen_2 = strlen("\n\e[1;37m\t");
long int strLen_3 = strlen(compilerState.currentFile);
long int strLen_4 = strlen("\e[1;33m[WARNING]\e[0m ");
;                            
            ____BAH_COMPILER_VAR_175 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_175+currStrOff, "\e[1;33m[WARNING]\e[0m ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_175+currStrOff, compilerState.currentFile, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_175+currStrOff, "\n\e[1;37m\t", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_175+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_175+currStrOff, "\e[0m", strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_175);
};
#include <stdlib.h>
char * absPath(char * path){
char * buff = memoryAlloc(4096);
char * p = _fullpath(buff,path,4095);
if (((void *)p!=null)) {
array(char)* arr = strAsArr(p);
register long int i = 0;
for (; (i<len(arr)); i++) {
char c = arr->data[i];
if ((c==(char)92)) {

{
long nLength = i;
if (arr->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(arr->data, (nLength+50)*sizeof(char));
arr->data = newPtr;
}
arr->data[i] = 47;
arr->length = nLength+1;
} else {
arr->data[i] = 47;
}
};
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
for (; (i!=-1); i--) {
if ((strcmp(elems->vars->data[i]->name, n) == 0)) {
return elems->vars->data[i];
}
};
return null;
};
struct variable* searchVar(char * name,struct Elems* elems){
char * ogName = name;
struct string n = string(name);
n.replace(&n,"&","");
n.replace(&n,"*","");
if (n.hasSuffix(&n,"]")) {
register long int i = n.length;
while ((i>0)) {
char c = n.charAt(&n,i);
if ((c==91)) {
break;
}
i = i-1;
};
long int tamm = n.length-i;
n.trimRight(&n,tamm);
char isArr = (n.hasSuffix(&n,"->data")==1);
if ((isArr==true)) {
n.trimRight(&n,6);
}
name = n.str(&n);
struct variable* v = searchVar(name,elems);
struct string vt = string(v->type);
if ((isArr==true)) {
vt.trimLeft(&vt,2);
}
else {
vt.set(&vt,"char");
}
char * vtstr = vt.str(&vt);
struct variable* ____BAH_COMPILER_VAR_176 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_176->name = "";
____BAH_COMPILER_VAR_176->type = "";
____BAH_COMPILER_VAR_176->isConst = false;
____BAH_COMPILER_VAR_176->constVal = "";
____BAH_COMPILER_VAR_176->isArray = false;
____BAH_COMPILER_VAR_176->from = "";
____BAH_COMPILER_VAR_176->declScope= null;
____BAH_COMPILER_VAR_176->isGlobal = false;
____BAH_COMPILER_VAR_176->declRope= null;
____BAH_COMPILER_VAR_176->isReg = false;
struct variable* nv = ____BAH_COMPILER_VAR_176;
nv->type = vtstr;
nv->name = ogName;
nv->declScope = v->declScope;
nv->isArray = isArr;
return nv;
}
name = n.content;
if (hasStructSep(n)&&(n.count(&n,")")==0)) {
struct string rn = splitStructSepBefore(n);
name = rn.content;
n.trimLeft(&n,rn.length);
if (n.hasPrefix(&n,".")) {
n.trimLeft(&n,1);
}
else {
n.trimLeft(&n,2);
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
struct variable* ____BAH_COMPILER_VAR_177 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_177->name = "";
____BAH_COMPILER_VAR_177->type = "";
____BAH_COMPILER_VAR_177->isConst = false;
____BAH_COMPILER_VAR_177->constVal = "";
____BAH_COMPILER_VAR_177->isArray = false;
____BAH_COMPILER_VAR_177->from = "";
____BAH_COMPILER_VAR_177->declScope= null;
____BAH_COMPILER_VAR_177->isGlobal = false;
____BAH_COMPILER_VAR_177->declRope= null;
____BAH_COMPILER_VAR_177->isReg = false;
struct variable* nv = ____BAH_COMPILER_VAR_177;
nv->from = memb->from;
nv->name = memb->name;
nv->type = memb->type;
nv->declScope = v->declScope;
nv->name = ogName;
char * r = nv->type;
struct string tcc = string(ogName);
if (tcc.count(&tcc,"&")) {
char * ____BAH_COMPILER_VAR_178 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(r);
long int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_178 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_178+currStrOff, r, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_178+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }r = ____BAH_COMPILER_VAR_178;
}
long int nbUnaries = tcc.count(&tcc,"*");
if ((nbUnaries>0)) {
struct string ct = string(r);
long int pointerLevel = ct.count(&ct,"*");
if ((pointerLevel<nbUnaries)) {
char * ____BAH_COMPILER_VAR_179 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nv->name);
long int strLen_1 = strlen(" because it is not pointer.");
long int strLen_2 = strlen("Cannot use '*' on ");
;                            
            ____BAH_COMPILER_VAR_179 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_179+currStrOff, "Cannot use '*' on ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_179+currStrOff, nv->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_179+currStrOff, " because it is not pointer.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(null,____BAH_COMPILER_VAR_179);
}
ct.trimRight(&ct,nbUnaries);
r = ct.str(&ct);
}
nv->type = r;
nv->name = ogName;
return nv;
}
register long int i = len(elems->vars)-1;
for (; (i!=-1); i--) {
struct variable* v = elems->vars->data[i];
if ((strcmp(v->name, name) == 0)) {
struct variable* ____BAH_COMPILER_VAR_180 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_180->name = "";
____BAH_COMPILER_VAR_180->type = "";
____BAH_COMPILER_VAR_180->isConst = false;
____BAH_COMPILER_VAR_180->constVal = "";
____BAH_COMPILER_VAR_180->isArray = false;
____BAH_COMPILER_VAR_180->from = "";
____BAH_COMPILER_VAR_180->declScope= null;
____BAH_COMPILER_VAR_180->isGlobal = false;
____BAH_COMPILER_VAR_180->declRope= null;
____BAH_COMPILER_VAR_180->isReg = false;
struct variable* nv = ____BAH_COMPILER_VAR_180;
nv->type = v->type;
nv->name = v->name;
nv->isConst = v->isConst;
nv->constVal = v->constVal;
nv->declScope = v->declScope;
char * r = nv->type;
struct string tcc = string(ogName);
if (tcc.count(&tcc,"&")) {
char * ____BAH_COMPILER_VAR_181 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(r);
long int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_181 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_181+currStrOff, r, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_181+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }r = ____BAH_COMPILER_VAR_181;
}
long int nbUnaries = tcc.count(&tcc,"*");
if ((nbUnaries>0)) {
struct string ct = string(r);
long int pointerLevel = ct.count(&ct,"*");
if ((pointerLevel<nbUnaries)) {
char * ____BAH_COMPILER_VAR_182 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen(" because it is not pointer.");
long int strLen_2 = strlen("Cannot use '*' on ");
;                            
            ____BAH_COMPILER_VAR_182 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_182+currStrOff, "Cannot use '*' on ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_182+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_182+currStrOff, " because it is not pointer.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(null,____BAH_COMPILER_VAR_182);
}
ct.trimRight(&ct,nbUnaries);
r = ct.str(&ct);
}
nv->type = r;
nv->name = ogName;
return nv;
}
};
i = 0;
for (; (i<len(elems->fns)); i++) {
struct func* fn = elems->fns->data[i];
if ((strcmp(fn->name, name) == 0)) {
struct variable* ____BAH_COMPILER_VAR_183 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_183->name = "";
____BAH_COMPILER_VAR_183->type = "";
____BAH_COMPILER_VAR_183->isConst = false;
____BAH_COMPILER_VAR_183->constVal = "";
____BAH_COMPILER_VAR_183->isArray = false;
____BAH_COMPILER_VAR_183->from = "";
____BAH_COMPILER_VAR_183->declScope= null;
____BAH_COMPILER_VAR_183->isGlobal = false;
____BAH_COMPILER_VAR_183->declRope= null;
____BAH_COMPILER_VAR_183->isReg = false;
struct variable* nv = ____BAH_COMPILER_VAR_183;
nv->name = name;
nv->type = "function(";
register long int j = 0;
while ((j<len(fn->args))) {
struct variable* arg = fn->args->data[j];
char * ____BAH_COMPILER_VAR_184 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nv->type);
long int strLen_1 = strlen(arg->type);
;                            
            ____BAH_COMPILER_VAR_184 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_184+currStrOff, nv->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_184+currStrOff, arg->type, strLen_1);
            currStrOff += strLen_1;
        
        }nv->type = ____BAH_COMPILER_VAR_184;
j = j+1;
if ((j<len(fn->args))) {
char * ____BAH_COMPILER_VAR_185 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nv->type);
long int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_185 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_185+currStrOff, nv->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_185+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }nv->type = ____BAH_COMPILER_VAR_185;
}
};
fn->used = true;
char * ____BAH_COMPILER_VAR_186 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(")");
long int strLen_1 = strlen(fn->returns->type);
long int strLen_2 = strlen(nv->type);
;                            
            ____BAH_COMPILER_VAR_186 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_186+currStrOff, nv->type, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_186+currStrOff, ")", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_186+currStrOff, fn->returns->type, strLen_1);
            currStrOff += strLen_1;
        
        }nv->type = ____BAH_COMPILER_VAR_186;
return nv;
}
};
return null;
};
struct variable* searchVarByToken(struct Tok t,struct Elems* elems){
if ((t.bahRef!=null)) {
return t.bahRef;
}
return searchVar(t.cont,elems);
};
char * setCType(struct variable* v,struct Elems* elems){
struct string tp = getCType(v->type,elems);
char * t = tp.str(&tp);
char * ____BAH_COMPILER_VAR_187 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(" ");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(t);
;                            
            ____BAH_COMPILER_VAR_187 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_187+currStrOff, t, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_187+currStrOff, " ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_187+currStrOff, v->name, strLen_1);
            currStrOff += strLen_1;
        
        }t = ____BAH_COMPILER_VAR_187;
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
struct func* ____BAH_COMPILER_VAR_188 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_188->name = "";
____BAH_COMPILER_VAR_188->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_188->args->length = 0;
            ____BAH_COMPILER_VAR_188->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_188->returns= null;
____BAH_COMPILER_VAR_188->isBinding = false;
____BAH_COMPILER_VAR_188->from = "";
____BAH_COMPILER_VAR_188->file = "";
____BAH_COMPILER_VAR_188->line = 1;
____BAH_COMPILER_VAR_188->used = false;
____BAH_COMPILER_VAR_188->code = null;
struct func* nf = ____BAH_COMPILER_VAR_188;
cvt.trimLeft(&cvt,9);
array(char)* memory = memoryAlloc(sizeof(array(char)));

memory->length = 0;
memory->elemSize = sizeof(char);
register long int j = 0;
while ((j<cvt.length)) {
char c = cvt.charAt(&cvt,j);
if ((c==41)) {
break;
}
struct variable* ____BAH_COMPILER_VAR_189 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_189->name = "";
____BAH_COMPILER_VAR_189->type = "";
____BAH_COMPILER_VAR_189->isConst = false;
____BAH_COMPILER_VAR_189->constVal = "";
____BAH_COMPILER_VAR_189->isArray = false;
____BAH_COMPILER_VAR_189->from = "";
____BAH_COMPILER_VAR_189->declScope= null;
____BAH_COMPILER_VAR_189->isGlobal = false;
____BAH_COMPILER_VAR_189->declRope= null;
____BAH_COMPILER_VAR_189->isReg = false;
struct variable* arg = ____BAH_COMPILER_VAR_189;
char * ____BAH_COMPILER_VAR_190 =null;char * ____BAH_COMPILER_VAR_191 =intToStr(len(nf->args));
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("arg_");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_191);
;                            
            ____BAH_COMPILER_VAR_190 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_190+currStrOff, "arg_", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_190+currStrOff, ____BAH_COMPILER_VAR_191, strLen_1);
            currStrOff += strLen_1;
        
        }arg->name = ____BAH_COMPILER_VAR_190;
while ((j<cvt.length)) {
c = cvt.charAt(&cvt,j);
if ((c==44)||(c==41)) {
break;
}

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[len(memory)] = c;
memory->length = nLength+1;
} else {
memory->data[len(memory)] = c;
}
};
j = j+1;
};
arg->type = arrToStr(memory);
clear(memory);

{
long nLength = len(nf->args);
if (nf->args->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nf->args->data, (nLength+50)*sizeof(struct variable*));
nf->args->data = newPtr;
}
nf->args->data[len(nf->args)] = arg;
nf->args->length = nLength+1;
} else {
nf->args->data[len(nf->args)] = arg;
}
};
if ((c==41)) {
break;
}
j = j+1;
};
j = j+1;
while ((j<cvt.length)) {
char c = cvt.charAt(&cvt,j);

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[len(memory)] = c;
memory->length = nLength+1;
} else {
memory->data[len(memory)] = c;
}
};
j = j+1;
};
struct variable* ____BAH_COMPILER_VAR_192 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_192->name = "";
____BAH_COMPILER_VAR_192->type = "";
____BAH_COMPILER_VAR_192->isConst = false;
____BAH_COMPILER_VAR_192->constVal = "";
____BAH_COMPILER_VAR_192->isArray = false;
____BAH_COMPILER_VAR_192->from = "";
____BAH_COMPILER_VAR_192->declScope= null;
____BAH_COMPILER_VAR_192->isGlobal = false;
____BAH_COMPILER_VAR_192->declRope= null;
____BAH_COMPILER_VAR_192->isReg = false;
nf->returns = ____BAH_COMPILER_VAR_192;
nf->returns->name = "_return";
nf->returns->type = arrToStr(memory);
return nf;
};
struct func* searchFunc(char * name,struct Elems* elems,char inclCurr){
char * ogName = name;
if ((strcmp(name, "noCheck") == 0)) {
struct func* ____BAH_COMPILER_VAR_193 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_193->name = "";
____BAH_COMPILER_VAR_193->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_193->args->length = 0;
            ____BAH_COMPILER_VAR_193->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_193->returns= null;
____BAH_COMPILER_VAR_193->isBinding = false;
____BAH_COMPILER_VAR_193->from = "";
____BAH_COMPILER_VAR_193->file = "";
____BAH_COMPILER_VAR_193->line = 1;
____BAH_COMPILER_VAR_193->used = false;
____BAH_COMPILER_VAR_193->code = null;
struct func* fn = ____BAH_COMPILER_VAR_193;
fn->name = "noCheck";
return fn;
}
struct string n = string(name);
if (hasStructSep(n)) {
struct string fnName = splitStructSepAfter(n);
n.trimRight(&n,fnName.length);
char c = n.charAt(&n,n.length-1);
if ((c==46)) {
n.trimRight(&n,1);
}
else {
n.trimRight(&n,2);
}
name = n.str(&n);
struct variable* v = searchVar(name,elems);
struct cStruct* s = searchStruct(v->type,elems);
char * ____BAH_COMPILER_VAR_194 =fnName.str(&fnName);struct structMemb* memb = searchStructMemb(____BAH_COMPILER_VAR_194,s,elems);
name = fnName.content;
char * ____BAH_COMPILER_VAR_195 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("__");
long int strLen_1 = strlen(name);
long int strLen_2 = strlen(memb->from);
;                            
            ____BAH_COMPILER_VAR_195 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_195+currStrOff, memb->from, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_195+currStrOff, "__", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_195+currStrOff, name, strLen_1);
            currStrOff += strLen_1;
        
        }name = ____BAH_COMPILER_VAR_195;
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
if ((inclCurr==true)) {
if ((strcmp(currentFn->name, name) == 0)) {
currentFn->used = true;
return currentFn;
}
}
struct variable* v = searchVar(ogName,elems);
if ((v==null)) {
return null;
}
struct func* ____BAH_COMPILER_VAR_196 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_196->name = "";
____BAH_COMPILER_VAR_196->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_196->args->length = 0;
            ____BAH_COMPILER_VAR_196->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_196->returns= null;
____BAH_COMPILER_VAR_196->isBinding = false;
____BAH_COMPILER_VAR_196->from = "";
____BAH_COMPILER_VAR_196->file = "";
____BAH_COMPILER_VAR_196->line = 1;
____BAH_COMPILER_VAR_196->used = false;
____BAH_COMPILER_VAR_196->code = null;
struct func* nf = ____BAH_COMPILER_VAR_196;
nf->name = ogName;
struct string cvt = string(v->type);
if ((cvt.hasPrefix(&cvt,"function(")==0)) {
return null;
}
struct func* pfn = parseFnType(cvt);
nf->returns = pfn->returns;
nf->args = pfn->args;
return nf;
};
struct func* searchFuncByToken(struct Tok t,struct Elems* elems){
if ((t.bahRef!=null)) {
return t.bahRef;
}
struct string ____BAH_COMPILER_VAR_197 =string(t.cont);char * fnName = splitStringBefore(____BAH_COMPILER_VAR_197,"(");
return searchFunc(fnName,elems,true);
};
char RCPavailable();
char * declareStructMethods(struct variable* v,struct cStruct* s,struct Elems* elems){
char * code = "";
array(struct structMemb*)* members = s->members;
struct string typec = string(v->type);
char * sep = ".";
char * amp = "&";
if (typec.count(&typec,"*")) {
sep = "->";
amp = "";
}
register long int i = 0;
while ((i<len(members))) {
struct structMemb* m = members->data[i];
struct string cmpt = string(m->type);
char declared = false;
if ((strlen(m->def)>0)) {
char * ____BAH_COMPILER_VAR_198 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(m->def);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen(" = ");
long int strLen_3 = strlen(m->name);
long int strLen_4 = strlen(sep);
long int strLen_5 = strlen(v->name);
long int strLen_6 = strlen(code);
;                            
            ____BAH_COMPILER_VAR_198 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_198+currStrOff, code, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_198+currStrOff, v->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_198+currStrOff, sep, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_198+currStrOff, m->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_198+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_198+currStrOff, m->def, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_198+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_198;
declared = true;
}
if ((cmpt.hasPrefix(&cmpt,"[]")==1)) {
cmpt.trimLeft(&cmpt,2);
char * cmptstr = cmpt.str(&cmpt);
struct string elemCType = getCType(cmptstr,elems);
char * elemCTypeStr = elemCType.str(&elemCType);
char * ____BAH_COMPILER_VAR_199 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(elemCTypeStr);
long int strLen_1 = strlen(");\n            ");
long int strLen_2 = strlen("->elemSize = sizeof(");
long int strLen_3 = strlen(m->name);
long int strLen_4 = strlen(sep);
long int strLen_5 = strlen(v->name);
long int strLen_6 = strlen("->length = 0;\n            ");
long int strLen_7 = strlen(m->name);
long int strLen_8 = strlen(sep);
long int strLen_9 = strlen(v->name);
long int strLen_10 = strlen(")));\n            ");
long int strLen_11 = strlen(elemCTypeStr);
long int strLen_12 = strlen(" = memoryAlloc(sizeof(array(");
long int strLen_13 = strlen(m->name);
long int strLen_14 = strlen(sep);
long int strLen_15 = strlen(v->name);
long int strLen_16 = strlen(code);
;                            
            ____BAH_COMPILER_VAR_199 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13+strLen_14+strLen_15+strLen_16);
            
                    memcpy(____BAH_COMPILER_VAR_199+currStrOff, code, strLen_16);
                    currStrOff += strLen_16;
                    
                    memcpy(____BAH_COMPILER_VAR_199+currStrOff, v->name, strLen_15);
                    currStrOff += strLen_15;
                    
                    memcpy(____BAH_COMPILER_VAR_199+currStrOff, sep, strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_199+currStrOff, m->name, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_199+currStrOff, " = memoryAlloc(sizeof(array(", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_199+currStrOff, elemCTypeStr, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_199+currStrOff, ")));\n            ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_199+currStrOff, v->name, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_199+currStrOff, sep, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_199+currStrOff, m->name, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_199+currStrOff, "->length = 0;\n            ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_199+currStrOff, v->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_199+currStrOff, sep, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_199+currStrOff, m->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_199+currStrOff, "->elemSize = sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_199+currStrOff, elemCTypeStr, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_199+currStrOff, ");\n            ", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_199;
declared = true;
}
else if ((cmpt.hasPrefix(&cmpt,"map:")==1)) {
cmpt.trimLeft(&cmpt,4);
char * ____BAH_COMPILER_VAR_200 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(m->name);
long int strLen_1 = strlen(" = mapWrapper();\n");
long int strLen_2 = strlen(sep);
long int strLen_3 = strlen(v->name);
;                            
            ____BAH_COMPILER_VAR_200 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_200+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_200+currStrOff, sep, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_200+currStrOff, m->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_200+currStrOff, " = mapWrapper();\n", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_201 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_200);
;                            
            ____BAH_COMPILER_VAR_201 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_201+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_201+currStrOff, ____BAH_COMPILER_VAR_200, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_201;
declared = true;
}
else if ((cmpt.hasPrefix(&cmpt,"chan:")==1)) {
cmpt.trimLeft(&cmpt,5);
char * ____BAH_COMPILER_VAR_202 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(m->name);
long int strLen_1 = strlen(" = channel();\n");
long int strLen_2 = strlen(sep);
long int strLen_3 = strlen(v->name);
;                            
            ____BAH_COMPILER_VAR_202 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_202+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_202+currStrOff, sep, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_202+currStrOff, m->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_202+currStrOff, " = channel();\n", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_203 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_202);
;                            
            ____BAH_COMPILER_VAR_203 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_203+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_203+currStrOff, ____BAH_COMPILER_VAR_202, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_203;
declared = true;
}
if (isRCPpointerType(m->type)&&(declared==false)) {
char * ____BAH_COMPILER_VAR_204 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(m->name);
long int strLen_1 = strlen("= null;\n");
long int strLen_2 = strlen(sep);
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen(code);
;                            
            ____BAH_COMPILER_VAR_204 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_204+currStrOff, code, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_204+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_204+currStrOff, sep, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_204+currStrOff, m->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_204+currStrOff, "= null;\n", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_204;
}
i = i+1;
};
if ((strlen(s->extendedFrom)>0)) {
struct cStruct* es = searchStruct(s->extendedFrom,elems);
i = 0;
while ((i<len(es->methods))) {
struct func* m = es->methods->data[i];
char * ____BAH_COMPILER_VAR_205 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(m->name);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen("__");
long int strLen_3 = strlen(es->name);
long int strLen_4 = strlen(" = ");
long int strLen_5 = strlen(m->name);
long int strLen_6 = strlen(sep);
long int strLen_7 = strlen(v->name);
long int strLen_8 = strlen(code);
;                            
            ____BAH_COMPILER_VAR_205 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_205+currStrOff, code, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_205+currStrOff, v->name, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_205+currStrOff, sep, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_205+currStrOff, m->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_205+currStrOff, " = ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_205+currStrOff, es->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_205+currStrOff, "__", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_205+currStrOff, m->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_205+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_205;
i = i+1;
};
}
array(struct func*)* methods = s->methods;
i = 0;
while ((i<len(methods))) {
struct func* m = methods->data[i];
char * ____BAH_COMPILER_VAR_206 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(m->name);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen("__");
long int strLen_3 = strlen(s->name);
long int strLen_4 = strlen(" = ");
long int strLen_5 = strlen(m->name);
long int strLen_6 = strlen(sep);
long int strLen_7 = strlen(v->name);
long int strLen_8 = strlen(code);
;                            
            ____BAH_COMPILER_VAR_206 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_206+currStrOff, code, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_206+currStrOff, v->name, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_206+currStrOff, sep, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_206+currStrOff, m->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_206+currStrOff, " = ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_206+currStrOff, s->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_206+currStrOff, "__", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_206+currStrOff, m->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_206+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_206;
i = i+1;
};
if ((s->isBinding==false)) {
long int found = 0;
i = 0;
for (; (i<len(s->methods)); i++) {
struct func* m = s->methods->data[i];
if ((strcmp(m->name, "_init") == 0)) {
char * ____BAH_COMPILER_VAR_207 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen(");\n");
long int strLen_2 = strlen(amp);
long int strLen_3 = strlen("(");
long int strLen_4 = strlen(m->name);
long int strLen_5 = strlen(sep);
long int strLen_6 = strlen(v->name);
;                            
            ____BAH_COMPILER_VAR_207 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_207+currStrOff, v->name, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_207+currStrOff, sep, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_207+currStrOff, m->name, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_207+currStrOff, "(", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_207+currStrOff, amp, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_207+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_207+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_208 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(NEXT_LINE);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_207);
;                            
            ____BAH_COMPILER_VAR_208 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_208+currStrOff, NEXT_LINE, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_208+currStrOff, ____BAH_COMPILER_VAR_207, strLen_1);
            currStrOff += strLen_1;
        
        }NEXT_LINE = ____BAH_COMPILER_VAR_208;
found++;
}
else if ((strcmp(m->name, "_end") == 0)) {
if ((strcmp(sep, "->") == 0)) {
char * ____BAH_COMPILER_VAR_209 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(m->name);
long int strLen_1 = strlen(");\n");
long int strLen_2 = strlen(sep);
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen(", ");
long int strLen_5 = strlen(v->name);
long int strLen_6 = strlen("memoryOnEnd(");
;                            
            ____BAH_COMPILER_VAR_209 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_209+currStrOff, "memoryOnEnd(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_209+currStrOff, v->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_209+currStrOff, ", ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_209+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_209+currStrOff, sep, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_209+currStrOff, m->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_209+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_210 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_209);
;                            
            ____BAH_COMPILER_VAR_210 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_210+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_210+currStrOff, ____BAH_COMPILER_VAR_209, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_210;
}
found++;
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
char * ____BAH_COMPILER_VAR_211 =null;char * ____BAH_COMPILER_VAR_212 =intToStr(NB_COMP_VAR);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("____BAH_COMPILER_VAR_");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_212);
;                            
            ____BAH_COMPILER_VAR_211 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_211+currStrOff, "____BAH_COMPILER_VAR_", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_211+currStrOff, ____BAH_COMPILER_VAR_212, strLen_1);
            currStrOff += strLen_1;
        
        }char * name = ____BAH_COMPILER_VAR_211;
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
for (; (i<len(a)); i++) {
long int c = a->data[i];
c = c-(long int)97;
if ((c<0)) {
c = 0-c;
}
c = c%((long int)122-(long int)97);
c = c+(long int)97;

{
long nLength = i;
if (a->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(a->data, (nLength+50)*sizeof(char));
a->data = newPtr;
}
a->data[i] = (char)c;
a->length = nLength+1;
} else {
a->data[i] = (char)c;
}
};
};
return arrToStr(a);
};
void makeInit(){
char * name = "__BAH_init";
if ((isObject==true)) {
char * ____BAH_COMPILER_VAR_213 =null;char * ____BAH_COMPILER_VAR_214 =pathToVarName(compilerState.currentFile);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(name);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_214);
;                            
            ____BAH_COMPILER_VAR_213 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_213+currStrOff, name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_213+currStrOff, ____BAH_COMPILER_VAR_214, strLen_1);
            currStrOff += strLen_1;
        
        }name = ____BAH_COMPILER_VAR_213;
}
char * evals = "";
char * ____BAH_COMPILER_VAR_215 =null;char * ____BAH_COMPILER_VAR_216 =intToStr(len(compilerState.evals));
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_216);
long int strLen_1 = strlen("] = {");
long int strLen_2 = strlen("volatile struct __eval_binding __tmp__evals_bindings[");
;                            
            ____BAH_COMPILER_VAR_215 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_215+currStrOff, "volatile struct __eval_binding __tmp__evals_bindings[", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_215+currStrOff, ____BAH_COMPILER_VAR_216, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_215+currStrOff, "] = {", strLen_1);
            currStrOff += strLen_1;
        
        }char * evalsTMPDecl = ____BAH_COMPILER_VAR_215;
register long int i = 0;
for (; (i<len(compilerState.evals)); i++) {
char * e = compilerState.evals->data[i];
char * ____BAH_COMPILER_VAR_217 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(e);
long int strLen_1 = strlen("\n        }");
long int strLen_2 = strlen("\",\n            .evalFn = __Bah_eval_");
long int strLen_3 = strlen(e);
long int strLen_4 = strlen("{\n            .name = \"");
;                            
            ____BAH_COMPILER_VAR_217 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_217+currStrOff, "{\n            .name = \"", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_217+currStrOff, e, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_217+currStrOff, "\",\n            .evalFn = __Bah_eval_", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_217+currStrOff, e, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_217+currStrOff, "\n        }", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_218 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(evalsTMPDecl);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_217);
;                            
            ____BAH_COMPILER_VAR_218 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_218+currStrOff, evalsTMPDecl, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_218+currStrOff, ____BAH_COMPILER_VAR_217, strLen_1);
            currStrOff += strLen_1;
        
        }evalsTMPDecl = ____BAH_COMPILER_VAR_218;
if ((i+1!=len(compilerState.evals))) {
char * ____BAH_COMPILER_VAR_219 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(evalsTMPDecl);
long int strLen_1 = strlen(",\n");
;                            
            ____BAH_COMPILER_VAR_219 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_219+currStrOff, evalsTMPDecl, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_219+currStrOff, ",\n", strLen_1);
            currStrOff += strLen_1;
        
        }evalsTMPDecl = ____BAH_COMPILER_VAR_219;
}
else {
char * ____BAH_COMPILER_VAR_220 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(evalsTMPDecl);
long int strLen_1 = strlen("};");
;                            
            ____BAH_COMPILER_VAR_220 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_220+currStrOff, evalsTMPDecl, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_220+currStrOff, "};", strLen_1);
            currStrOff += strLen_1;
        
        }evalsTMPDecl = ____BAH_COMPILER_VAR_220;
}
};
if ((len(compilerState.evals)!=0)) {
char * ____BAH_COMPILER_VAR_221 =null;char * ____BAH_COMPILER_VAR_222 =intToStr(len(compilerState.evals));
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_222);
long int strLen_1 = strlen(";");
long int strLen_2 = strlen("__evals_bindings = __tmp__evals_bindings; __evals_length = ");
;                            
            ____BAH_COMPILER_VAR_221 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_221+currStrOff, "__evals_bindings = __tmp__evals_bindings; __evals_length = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_221+currStrOff, ____BAH_COMPILER_VAR_222, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_221+currStrOff, ";", strLen_1);
            currStrOff += strLen_1;
        
        }evals = ____BAH_COMPILER_VAR_221;
}
else {
evalsTMPDecl = "";
}
char * ____BAH_COMPILER_VAR_223 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(name);
long int strLen_1 = strlen("() {\n        ");
long int strLen_2 = strlen("\n    void __attribute__((optimize(\"O0\"))) ");
long int strLen_3 = strlen(evalsTMPDecl);
long int strLen_4 = strlen("\n    ");
;                            
            ____BAH_COMPILER_VAR_223 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_223+currStrOff, "\n    ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_223+currStrOff, evalsTMPDecl, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_223+currStrOff, "\n    void __attribute__((optimize(\"O0\"))) ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_223+currStrOff, name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_223+currStrOff, "() {\n        ", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_224 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(evals);
long int strLen_1 = strlen("\n    };\n    ");
long int strLen_2 = strlen("\n        ");
;                            
            ____BAH_COMPILER_VAR_224 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_224+currStrOff, "\n        ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_224+currStrOff, evals, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_224+currStrOff, "\n    };\n    ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_223)->add(rope(____BAH_COMPILER_VAR_223), INIT->add(INIT, rope(____BAH_COMPILER_VAR_224))));
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
char * ____BAH_COMPILER_VAR_225 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen(");\n");
long int strLen_2 = strlen("RCP_decr(");
;                            
            ____BAH_COMPILER_VAR_225 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_225+currStrOff, "RCP_decr(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_225+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_225+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }r = r->add(r, rope(____BAH_COMPILER_VAR_225));
}
else if (strHasPrefix(v->type,"chan:")) {
char * ____BAH_COMPILER_VAR_226 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen(");\n");
long int strLen_2 = strlen("RCP_decr(");
;                            
            ____BAH_COMPILER_VAR_226 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_226+currStrOff, "RCP_decr(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_226+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_226+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }r = r->add(r, rope(____BAH_COMPILER_VAR_226));
}
else {
if (strHasPrefix(v->type,"map:")) {
struct variable* ____BAH_COMPILER_VAR_227 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_227->name = "";
____BAH_COMPILER_VAR_227->type = "";
____BAH_COMPILER_VAR_227->isConst = false;
____BAH_COMPILER_VAR_227->constVal = "";
____BAH_COMPILER_VAR_227->isArray = false;
____BAH_COMPILER_VAR_227->from = "";
____BAH_COMPILER_VAR_227->declScope= null;
____BAH_COMPILER_VAR_227->isGlobal = false;
____BAH_COMPILER_VAR_227->declRope= null;
____BAH_COMPILER_VAR_227->isReg = false;
struct variable* nv = ____BAH_COMPILER_VAR_227;
*nv = *v;
v = nv;
v->type = "mapWrapper*";
}
char isPointer = isRCPpointerType(v->type);
struct cStruct* s = searchStruct(v->type,elems);
if ((s!=null)&&(s->isBinding==false)) {
if ((isPointer==true)) {
char * ____BAH_COMPILER_VAR_228 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen(");\n");
long int strLen_2 = strlen("RCP_decr(");
;                            
            ____BAH_COMPILER_VAR_228 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_228+currStrOff, "RCP_decr(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_228+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_228+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }r = r->add(r, rope(____BAH_COMPILER_VAR_228));
}
else {
char * ____BAH_COMPILER_VAR_229 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen("), 1);\n");
long int strLen_2 = strlen(", sizeof(");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen("RCP_scanStack(&");
;                            
            ____BAH_COMPILER_VAR_229 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_229+currStrOff, "RCP_scanStack(&", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_229+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_229+currStrOff, ", sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_229+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_229+currStrOff, "), 1);\n", strLen_1);
            currStrOff += strLen_1;
        
        }r = r->add(r, rope(____BAH_COMPILER_VAR_229));
}
}
else if ((isPointer==true)) {
char * ____BAH_COMPILER_VAR_230 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen(");\n");
long int strLen_2 = strlen("RCP_decr(");
;                            
            ____BAH_COMPILER_VAR_230 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_230+currStrOff, "RCP_decr(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_230+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_230+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }r = r->add(r, rope(____BAH_COMPILER_VAR_230));
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
char * ____BAH_COMPILER_VAR_231 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen("), 0);");
long int strLen_2 = strlen(", sizeof(");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen("RCP_scanStack(&");
;                            
            ____BAH_COMPILER_VAR_231 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_231+currStrOff, "RCP_scanStack(&", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_231+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_231+currStrOff, ", sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_231+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_231+currStrOff, "), 0);", strLen_1);
            currStrOff += strLen_1;
        
        }return rope(____BAH_COMPILER_VAR_231);
}
char * ____BAH_COMPILER_VAR_232 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen(");");
long int strLen_2 = strlen("RCP_incr(");
;                            
            ____BAH_COMPILER_VAR_232 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_232+currStrOff, "RCP_incr(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_232+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_232+currStrOff, ");", strLen_1);
            currStrOff += strLen_1;
        
        }return rope(____BAH_COMPILER_VAR_232);
};
char RCPavailable(){
return (RCPenabled==true);
};
void beginRCPscope(struct Elems* elems,__BAH_ARR_TYPE_variable excl){
if ((RCPavailable()==false)) {
return;
}
register long int i = 0;
for (; (i<len(elems->vars)); i++) {
struct variable* v = elems->vars->data[i];
if (varInArr(v,excl)) {
continue;
}
if ((v->isGlobal==false)&&isRCPtype(v->type,elems)) {
OUTPUT = OUTPUT->add(OUTPUT, incrVar(v,elems));
}
};
};
void beginRCPscopeLeaky(struct Elems* elems){
if ((RCPavailable()==false)) {
return;
}
register long int i = 0;
for (; (i<len(elems->vars)); i++) {
struct variable* v = elems->vars->data[i];
if ((v->isGlobal==false)&&(v->declScope==elems)&&isRCPtype(v->type,elems)) {
OUTPUT = OUTPUT->add(OUTPUT, incrVar(v,elems));
}
};
};
void removeDefs(struct Elems* elems){
register long int i = 0;
for (; (i<len(elems->defined)); i++) {
char * ____BAH_COMPILER_VAR_233 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(elems->defined->data[i]);
long int strLen_1 = strlen("\n");
long int strLen_2 = strlen("\n#undef ");
;                            
            ____BAH_COMPILER_VAR_233 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_233+currStrOff, "\n#undef ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_233+currStrOff, elems->defined->data[i], strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_233+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_233));
};
};
void endRCPscope(struct Elems* elems,__BAH_ARR_TYPE_variable excl){
if ((RCPavailable()==false)) {
removeDefs(elems);
return;
}
register long int i = 0;
for (; (i<len(elems->vars)); i++) {
struct variable* v = elems->vars->data[i];
if (varInArr(v,excl)) {
continue;
}
if ((v->isGlobal==false)&&isRCPtype(v->type,elems)) {
OUTPUT = OUTPUT->add(OUTPUT, decrVar(v,elems));
}
};
removeDefs(elems);
};
void endRCPscopeLeaky(struct Elems* elems,struct variable* excl){
if ((RCPavailable()==false)) {
removeDefs(elems);
return;
}
register long int i = 0;
for (; (i<len(elems->vars)); i++) {
struct variable* v = elems->vars->data[i];
if ((excl!=null)&&(strcmp(excl->name, v->name) == 0)) {
continue;
}
if ((v->isGlobal==false)&&(v->declScope==elems)&&isRCPtype(v->type,elems)) {
OUTPUT = OUTPUT->add(OUTPUT, decrVar(v,elems));
}
};
removeDefs(elems);
};
char * registerRCPvar(char * t,char * c,struct Elems* elems){
struct variable* ____BAH_COMPILER_VAR_234 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_234->name = "";
____BAH_COMPILER_VAR_234->type = "";
____BAH_COMPILER_VAR_234->isConst = false;
____BAH_COMPILER_VAR_234->constVal = "";
____BAH_COMPILER_VAR_234->isArray = false;
____BAH_COMPILER_VAR_234->from = "";
____BAH_COMPILER_VAR_234->declScope= null;
____BAH_COMPILER_VAR_234->isGlobal = false;
____BAH_COMPILER_VAR_234->declRope= null;
____BAH_COMPILER_VAR_234->isReg = false;
struct variable* av = ____BAH_COMPILER_VAR_234;
av->type = t;
av->name = genCompilerVar();

{
long nLength = len(elems->vars);
if (elems->vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(elems->vars->data, (nLength+50)*sizeof(struct variable*));
elems->vars->data = newPtr;
}
elems->vars->data[len(elems->vars)] = av;
elems->vars->length = nLength+1;
} else {
elems->vars->data[len(elems->vars)] = av;
}
};
struct string cType = getCType(av->type,elems);
char * ____BAH_COMPILER_VAR_235 =null;char * ____BAH_COMPILER_VAR_236 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(c);
long int strLen_1 = strlen(";");
long int strLen_2 = strlen(" =");
long int strLen_3 = strlen(av->name);
long int strLen_4 = strlen(" ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_236);
;                            
            ____BAH_COMPILER_VAR_235 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_235+currStrOff, ____BAH_COMPILER_VAR_236, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_235+currStrOff, " ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_235+currStrOff, av->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_235+currStrOff, " =", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_235+currStrOff, c, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_235+currStrOff, ";", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_235));
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

        char ____BAH_COMPILER_VAR_237 = 0;
        for(int i=noVOfns->length-1; i!=-1;i--) {
            if (noVOfns->data[i] != 0 && strcmp(noVOfns->data[i], currentFn->name) == 0) {
                ____BAH_COMPILER_VAR_237=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_237) {
return false;
}
}
return true;
};
struct verboseOutVar verboseOutTransformVar(struct variable* v,char * cont,struct Elems* elems){
struct verboseOutVar ____BAH_COMPILER_VAR_238 = {};
____BAH_COMPILER_VAR_238.markup= null;
____BAH_COMPILER_VAR_238.content= null;
#define rv ____BAH_COMPILER_VAR_238
char * ogCont = cont;
if ((strcmp(v->type, "cpstring") == 0)) {
char * ____BAH_COMPILER_VAR_239 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(cont);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen("__Bah_safe_string(");
;                            
            ____BAH_COMPILER_VAR_239 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_239+currStrOff, "__Bah_safe_string(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_239+currStrOff, cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_239+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }cont = ____BAH_COMPILER_VAR_239;
}
char * ____BAH_COMPILER_VAR_240 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(", ");
long int strLen_1 = strlen(cont);
;                            
            ____BAH_COMPILER_VAR_240 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_240+currStrOff, ", ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_240+currStrOff, cont, strLen_1);
            currStrOff += strLen_1;
        
        }cont = ____BAH_COMPILER_VAR_240;
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
char * ____BAH_COMPILER_VAR_241 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ASCII_RESET);
long int strLen_1 = strlen("{");
;                            
            ____BAH_COMPILER_VAR_241 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_241+currStrOff, ASCII_RESET, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_241+currStrOff, "{", strLen_1);
            currStrOff += strLen_1;
        
        }ct = ____BAH_COMPILER_VAR_241;
cont = "";
register long int i = 0;
for (; (i<len(s->members)); i++) {
struct variable* m = s->members->data[i];
char * ____BAH_COMPILER_VAR_242 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(".");
long int strLen_1 = strlen(m->name);
long int strLen_2 = strlen(")");
long int strLen_3 = strlen(ogCont);
long int strLen_4 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_242 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_242+currStrOff, "(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_242+currStrOff, ogCont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_242+currStrOff, ")", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_242+currStrOff, ".", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_242+currStrOff, m->name, strLen_1);
            currStrOff += strLen_1;
        
        }struct verboseOutVar mv = verboseOutTransformVar(m,____BAH_COMPILER_VAR_242,elems);
if ((i!=0)) {
char * ____BAH_COMPILER_VAR_243 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ct);
long int strLen_1 = strlen(", ");
;                            
            ____BAH_COMPILER_VAR_243 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_243+currStrOff, ct, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_243+currStrOff, ", ", strLen_1);
            currStrOff += strLen_1;
        
        }ct = ____BAH_COMPILER_VAR_243;
}
char * ____BAH_COMPILER_VAR_244 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ct);
long int strLen_1 = strlen(mv.markup);
;                            
            ____BAH_COMPILER_VAR_244 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_244+currStrOff, ct, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_244+currStrOff, mv.markup, strLen_1);
            currStrOff += strLen_1;
        
        }ct = ____BAH_COMPILER_VAR_244;
char * ____BAH_COMPILER_VAR_245 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(cont);
long int strLen_1 = strlen(mv.content);
;                            
            ____BAH_COMPILER_VAR_245 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_245+currStrOff, cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_245+currStrOff, mv.content, strLen_1);
            currStrOff += strLen_1;
        
        }cont = ____BAH_COMPILER_VAR_245;
};
char * ____BAH_COMPILER_VAR_246 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ct);
long int strLen_1 = strlen("}");
;                            
            ____BAH_COMPILER_VAR_246 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_246+currStrOff, ct, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_246+currStrOff, "}", strLen_1);
            currStrOff += strLen_1;
        
        }ct = ____BAH_COMPILER_VAR_246;
}
}
char * ____BAH_COMPILER_VAR_247 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ct);
long int strLen_1 = strlen(ASCII_RESET);
long int strLen_2 = strlen(ASCII_MAGENTA);
long int strLen_3 = strlen(" = ");
long int strLen_4 = strlen(ASCII_RESET);
long int strLen_5 = strlen(v->name);
long int strLen_6 = strlen(ASCII_BLUE);
;                            
            ____BAH_COMPILER_VAR_247 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_247+currStrOff, ASCII_BLUE, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_247+currStrOff, v->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_247+currStrOff, ASCII_RESET, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_247+currStrOff, " = ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_247+currStrOff, ASCII_MAGENTA, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_247+currStrOff, ct, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_247+currStrOff, ASCII_RESET, strLen_1);
            currStrOff += strLen_1;
        
        }rv.markup = ____BAH_COMPILER_VAR_247;
rv.content = cont;
return rv;
};
struct verboseOutVar verboseOutTransformTok(struct Tok t,struct Elems* elems){
if ((t.type==TOKEN_TYPE_VAR)&&(t.isOper==false)) {
struct variable* v = searchVar(t.cont,elems);
if ((v==null)) {
return verboseOutTransformVar(v,t.cont,elems);
}
}
struct variable ____BAH_COMPILER_VAR_248 = {};
____BAH_COMPILER_VAR_248.name = "";
____BAH_COMPILER_VAR_248.type = "";
____BAH_COMPILER_VAR_248.isConst = false;
____BAH_COMPILER_VAR_248.constVal = "";
____BAH_COMPILER_VAR_248.isArray = false;
____BAH_COMPILER_VAR_248.from = "";
____BAH_COMPILER_VAR_248.declScope= null;
____BAH_COMPILER_VAR_248.isGlobal = false;
____BAH_COMPILER_VAR_248.declRope= null;
____BAH_COMPILER_VAR_248.isReg = false;
____BAH_COMPILER_VAR_248.name = "(value)";
____BAH_COMPILER_VAR_248.type = getTypeFromToken(&t,true,elems);
#define v ____BAH_COMPILER_VAR_248
return verboseOutTransformVar(&v,t.cont,elems);
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
for (; (i<len(fn->args)); i++) {
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
for (; (j<len(fn->args)); j++) {
struct variable* a = fn->args->data[j];
if ((j!=0)) {
char * ____BAH_COMPILER_VAR_249 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnArgs);
long int strLen_1 = strlen(", ");
;                            
            ____BAH_COMPILER_VAR_249 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_249+currStrOff, fnArgs, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_249+currStrOff, ", ", strLen_1);
            currStrOff += strLen_1;
        
        }fnArgs = ____BAH_COMPILER_VAR_249;
}
struct Tok t = args->data[j];
struct verboseOutVar v = verboseOutTransformVar(a,t.cont,elems);
char * ____BAH_COMPILER_VAR_250 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnArgs);
long int strLen_1 = strlen(v.markup);
;                            
            ____BAH_COMPILER_VAR_250 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_250+currStrOff, fnArgs, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_250+currStrOff, v.markup, strLen_1);
            currStrOff += strLen_1;
        
        }fnArgs = ____BAH_COMPILER_VAR_250;
char * ____BAH_COMPILER_VAR_251 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnArgsValues);
long int strLen_1 = strlen(v.content);
;                            
            ____BAH_COMPILER_VAR_251 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_251+currStrOff, fnArgsValues, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_251+currStrOff, v.content, strLen_1);
            currStrOff += strLen_1;
        
        }fnArgsValues = ____BAH_COMPILER_VAR_251;
};
char * ____BAH_COMPILER_VAR_252 =null;char * ____BAH_COMPILER_VAR_253 =intToStr(lineNb);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(":");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_253);
long int strLen_2 = strlen(compilerState.currentFile);
;                            
            ____BAH_COMPILER_VAR_252 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_252+currStrOff, compilerState.currentFile, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_252+currStrOff, ":", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_252+currStrOff, ____BAH_COMPILER_VAR_253, strLen_1);
            currStrOff += strLen_1;
        
        }char * line = ____BAH_COMPILER_VAR_252;
char * ____BAH_COMPILER_VAR_254 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnArgsValues);
long int strLen_1 = strlen(");\n    //\n    ");
long int strLen_2 = strlen("\\n\"");
long int strLen_3 = strlen(ASCII_RESET);
long int strLen_4 = strlen(line);
long int strLen_5 = strlen(ASCII_GREEN);
long int strLen_6 = strlen(") -> ");
long int strLen_7 = strlen(fnArgs);
long int strLen_8 = strlen("(");
long int strLen_9 = strlen(ASCII_RESET);
long int strLen_10 = strlen(fn->name);
long int strLen_11 = strlen(nameColor);
long int strLen_12 = strlen("\n    //Verbose Runtime\n        printf(\"[VO] calling: ");
;                            
            ____BAH_COMPILER_VAR_254 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12);
            
                    memcpy(____BAH_COMPILER_VAR_254+currStrOff, "\n    //Verbose Runtime\n        printf(\"[VO] calling: ", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_254+currStrOff, nameColor, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_254+currStrOff, fn->name, strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_254+currStrOff, ASCII_RESET, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_254+currStrOff, "(", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_254+currStrOff, fnArgs, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_254+currStrOff, ") -> ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_254+currStrOff, ASCII_GREEN, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_254+currStrOff, line, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_254+currStrOff, ASCII_RESET, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_254+currStrOff, "\\n\"", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_254+currStrOff, fnArgsValues, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_254+currStrOff, ");\n    //\n    ", strLen_1);
            currStrOff += strLen_1;
        
        }struct rope* verboseOut = rope(____BAH_COMPILER_VAR_254);
if (isGlobal()) {
INIT = INIT->add(INIT, verboseOut);
}
else {
OUTPUT = OUTPUT->add(OUTPUT, verboseOut);
}
};
void verboseOutOper(struct Tok pt,struct Tok nt,long int lineNb,struct Elems* elems){
if ((verboseOutGuard()==false)) {
return;
}
struct verboseOutVar pvo = verboseOutTransformTok(pt,elems);
struct verboseOutVar nvo = verboseOutTransformTok(nt,elems);
char * ____BAH_COMPILER_VAR_255 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(pvo.content);
long int strLen_1 = strlen(nvo.content);
;                            
            ____BAH_COMPILER_VAR_255 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_255+currStrOff, pvo.content, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_255+currStrOff, nvo.content, strLen_1);
            currStrOff += strLen_1;
        
        }char * values = ____BAH_COMPILER_VAR_255;
char * ____BAH_COMPILER_VAR_256 =null;char * ____BAH_COMPILER_VAR_257 =intToStr(lineNb);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(":");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_257);
long int strLen_2 = strlen(compilerState.currentFile);
;                            
            ____BAH_COMPILER_VAR_256 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_256+currStrOff, compilerState.currentFile, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_256+currStrOff, ":", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_256+currStrOff, ____BAH_COMPILER_VAR_257, strLen_1);
            currStrOff += strLen_1;
        
        }char * line = ____BAH_COMPILER_VAR_256;
char * ____BAH_COMPILER_VAR_258 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(values);
long int strLen_1 = strlen(");\n    //\n    ");
long int strLen_2 = strlen("\\n\"");
long int strLen_3 = strlen(ASCII_RESET);
long int strLen_4 = strlen(line);
long int strLen_5 = strlen(ASCII_GREEN);
long int strLen_6 = strlen(" -> ");
long int strLen_7 = strlen(nvo.markup);
long int strLen_8 = strlen(" AND ");
long int strLen_9 = strlen(pvo.markup);
long int strLen_10 = strlen("\n    //Verbose Runtime\n        printf(\"[VO]    oper: ");
;                            
            ____BAH_COMPILER_VAR_258 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10);
            
                    memcpy(____BAH_COMPILER_VAR_258+currStrOff, "\n    //Verbose Runtime\n        printf(\"[VO]    oper: ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_258+currStrOff, pvo.markup, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_258+currStrOff, " AND ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_258+currStrOff, nvo.markup, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_258+currStrOff, " -> ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_258+currStrOff, ASCII_GREEN, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_258+currStrOff, line, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_258+currStrOff, ASCII_RESET, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_258+currStrOff, "\\n\"", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_258+currStrOff, values, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_258+currStrOff, ");\n    //\n    ", strLen_1);
            currStrOff += strLen_1;
        
        }struct rope* verboseOut = rope(____BAH_COMPILER_VAR_258);
if (isGlobal()) {
INIT = INIT->add(INIT, verboseOut);
}
else {
OUTPUT = OUTPUT->add(OUTPUT, verboseOut);
}
};
struct cacheFile {
char * file;
long int last;
char * ver;
long int date;
long int mem;
array(char *)* files;
};
array(struct cacheFile*)* cache;
void readCache(){
struct fileStream ____BAH_COMPILER_VAR_259 = {};
____BAH_COMPILER_VAR_259.handle= null;
____BAH_COMPILER_VAR_259.name= null;
____BAH_COMPILER_VAR_259.isValid = fileStream__isValid;
____BAH_COMPILER_VAR_259.open = fileStream__open;
____BAH_COMPILER_VAR_259.close = fileStream__close;
____BAH_COMPILER_VAR_259.getPos = fileStream__getPos;
____BAH_COMPILER_VAR_259.setPos = fileStream__setPos;
____BAH_COMPILER_VAR_259.getSize = fileStream__getSize;
____BAH_COMPILER_VAR_259.rewind = fileStream__rewind;
____BAH_COMPILER_VAR_259.getChar = fileStream__getChar;
____BAH_COMPILER_VAR_259.setChar = fileStream__setChar;
____BAH_COMPILER_VAR_259.createFile = fileStream__createFile;
____BAH_COMPILER_VAR_259.writeFile = fileStream__writeFile;
____BAH_COMPILER_VAR_259.writePtr = fileStream__writePtr;
____BAH_COMPILER_VAR_259.readPtr = fileStream__readPtr;
____BAH_COMPILER_VAR_259.readContent = fileStream__readContent;
____BAH_COMPILER_VAR_259.readBytes = fileStream__readBytes;
____BAH_COMPILER_VAR_259.writeBytes = fileStream__writeBytes;
____BAH_COMPILER_VAR_259._end = fileStream___end;
#define fs ____BAH_COMPILER_VAR_259
char * ____BAH_COMPILER_VAR_260 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen("cache/cache.json");
;                            
            ____BAH_COMPILER_VAR_260 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_260+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_260+currStrOff, "cache/cache.json", strLen_1);
            currStrOff += strLen_1;
        
        }fs.open(&fs,____BAH_COMPILER_VAR_260,"r");
if ((fs.isValid(&fs)==0)) {
char * ____BAH_COMPILER_VAR_261 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen("cache");
;                            
            ____BAH_COMPILER_VAR_261 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_261+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_261+currStrOff, "cache", strLen_1);
            currStrOff += strLen_1;
        
        }mkdir(____BAH_COMPILER_VAR_261,S_IRWXU);
char * ____BAH_COMPILER_VAR_262 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen("cache/cache.json");
;                            
            ____BAH_COMPILER_VAR_262 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_262+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_262+currStrOff, "cache/cache.json", strLen_1);
            currStrOff += strLen_1;
        
        }fs.createFile(&fs,____BAH_COMPILER_VAR_262);
return;
}
char * ____BAH_COMPILER_VAR_263 =fs.readContent(&fs);struct jsonElement* j = parseJson(____BAH_COMPILER_VAR_263);
fs.close(&fs);
array(struct cacheFile**)* ____BAH_COMPILER_VAR_264 = &cache;
struct cacheFile*** ____BAH_COMPILER_VAR_265 = 0;
char ** ____BAH_COMPILER_VAR_267 = (char **)((char*)(____BAH_COMPILER_VAR_265) + offsetof(struct cacheFile, file));
struct reflectElement ____BAH_COMPILER_VAR_268 = __reflect(____BAH_COMPILER_VAR_267, sizeof(char *), "cpstring", "file", 0, 0, 0, 0, offsetof(struct cacheFile, file));
long int* ____BAH_COMPILER_VAR_269 = (long int*)((char*)(____BAH_COMPILER_VAR_265) + offsetof(struct cacheFile, last));
struct reflectElement ____BAH_COMPILER_VAR_270 = __reflect(____BAH_COMPILER_VAR_269, sizeof(long int), "int", "last", 0, 0, 0, 0, offsetof(struct cacheFile, last));
char ** ____BAH_COMPILER_VAR_271 = (char **)((char*)(____BAH_COMPILER_VAR_265) + offsetof(struct cacheFile, ver));
struct reflectElement ____BAH_COMPILER_VAR_272 = __reflect(____BAH_COMPILER_VAR_271, sizeof(char *), "cpstring", "ver", 0, 0, 0, 0, offsetof(struct cacheFile, ver));
long int* ____BAH_COMPILER_VAR_273 = (long int*)((char*)(____BAH_COMPILER_VAR_265) + offsetof(struct cacheFile, date));
struct reflectElement ____BAH_COMPILER_VAR_274 = __reflect(____BAH_COMPILER_VAR_273, sizeof(long int), "int", "date", 0, 0, 0, 0, offsetof(struct cacheFile, date));
long int* ____BAH_COMPILER_VAR_275 = (long int*)((char*)(____BAH_COMPILER_VAR_265) + offsetof(struct cacheFile, mem));
struct reflectElement ____BAH_COMPILER_VAR_276 = __reflect(____BAH_COMPILER_VAR_275, sizeof(long int), "int", "mem", 0, 0, 0, 0, offsetof(struct cacheFile, mem));
array(char *)** ____BAH_COMPILER_VAR_277 = (array(char *)**)((char*)(____BAH_COMPILER_VAR_265) + offsetof(struct cacheFile, files));
char ** ____BAH_COMPILER_VAR_278 = 0;
struct reflectElement ____BAH_COMPILER_VAR_279 = __reflect(____BAH_COMPILER_VAR_278, sizeof(char *), "cpstring", "", 0, 0, 0, 0, 0);

        struct reflectElement ____BAH_COMPILER_VAR_280 = ____BAH_COMPILER_VAR_279;
        struct reflectElement ____BAH_COMPILER_VAR_281 = __reflect(____BAH_COMPILER_VAR_277, sizeof(array(char *)*), "[]cpstring", "files", 1, &____BAH_COMPILER_VAR_280, 0, 0, offsetof(struct cacheFile, files));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_266 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_266->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_266->length = 6;
        ____BAH_COMPILER_VAR_266->data = memoryAlloc(____BAH_COMPILER_VAR_266->length * ____BAH_COMPILER_VAR_266->elemSize);
        ____BAH_COMPILER_VAR_266->data[0] = ____BAH_COMPILER_VAR_268;
____BAH_COMPILER_VAR_266->data[1] = ____BAH_COMPILER_VAR_270;
____BAH_COMPILER_VAR_266->data[2] = ____BAH_COMPILER_VAR_272;
____BAH_COMPILER_VAR_266->data[3] = ____BAH_COMPILER_VAR_274;
____BAH_COMPILER_VAR_266->data[4] = ____BAH_COMPILER_VAR_276;
____BAH_COMPILER_VAR_266->data[5] = ____BAH_COMPILER_VAR_281;
struct reflectElement ____BAH_COMPILER_VAR_282 = __reflect(____BAH_COMPILER_VAR_265, sizeof(struct cacheFile), "cacheFile**", "", 0, 0, 1, ____BAH_COMPILER_VAR_266, 0);

        struct reflectElement ____BAH_COMPILER_VAR_283 = ____BAH_COMPILER_VAR_282;
        struct reflectElement ____BAH_COMPILER_VAR_284 = __reflect(____BAH_COMPILER_VAR_264, sizeof(array(struct cacheFile**)*), "[]cacheFile**", "&cache", 1, &____BAH_COMPILER_VAR_283, 0, 0, 0);
j->scan(j,____BAH_COMPILER_VAR_284);
if ((cache!=null)) {
}

#undef fs
};
struct cacheFile* getCacheFile(char * s){
if ((cache==null)) {
return null;
}
register long int i = 0;
for (; (i<len(cache)); i++) {
struct cacheFile* c = cache->data[i];
if ((strcmp(c->file, s) == 0)&&(c->mem==RCPlevel)) {
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
struct cacheFile* ____BAH_COMPILER_VAR_285 = memoryAlloc(sizeof(struct cacheFile));
____BAH_COMPILER_VAR_285->file= null;
____BAH_COMPILER_VAR_285->ver= null;
____BAH_COMPILER_VAR_285->files = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_285->files->length = 0;
            ____BAH_COMPILER_VAR_285->files->elemSize = sizeof(char *);
            struct cacheFile* c = ____BAH_COMPILER_VAR_285;
c->file = f;
c->ver = BAH_VERSION;
c->mem = RCPlevel;
c->date = getTimeUnix();
c->last = getLastModified(f);
if ((cache==null)) {
cache = memoryAlloc(sizeof(array(struct cacheFile*)));

cache->length = 0;
cache->elemSize = sizeof(struct cacheFile*);
}

{
long nLength = len(cache);
if (cache->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(cache->data, (nLength+50)*sizeof(struct cacheFile*));
cache->data = newPtr;
}
cache->data[len(cache)] = c;
cache->length = nLength+1;
} else {
cache->data[len(cache)] = c;
}
};
};
void writeCache(){
struct fileStream ____BAH_COMPILER_VAR_286 = {};
____BAH_COMPILER_VAR_286.handle= null;
____BAH_COMPILER_VAR_286.name= null;
____BAH_COMPILER_VAR_286.isValid = fileStream__isValid;
____BAH_COMPILER_VAR_286.open = fileStream__open;
____BAH_COMPILER_VAR_286.close = fileStream__close;
____BAH_COMPILER_VAR_286.getPos = fileStream__getPos;
____BAH_COMPILER_VAR_286.setPos = fileStream__setPos;
____BAH_COMPILER_VAR_286.getSize = fileStream__getSize;
____BAH_COMPILER_VAR_286.rewind = fileStream__rewind;
____BAH_COMPILER_VAR_286.getChar = fileStream__getChar;
____BAH_COMPILER_VAR_286.setChar = fileStream__setChar;
____BAH_COMPILER_VAR_286.createFile = fileStream__createFile;
____BAH_COMPILER_VAR_286.writeFile = fileStream__writeFile;
____BAH_COMPILER_VAR_286.writePtr = fileStream__writePtr;
____BAH_COMPILER_VAR_286.readPtr = fileStream__readPtr;
____BAH_COMPILER_VAR_286.readContent = fileStream__readContent;
____BAH_COMPILER_VAR_286.readBytes = fileStream__readBytes;
____BAH_COMPILER_VAR_286.writeBytes = fileStream__writeBytes;
____BAH_COMPILER_VAR_286._end = fileStream___end;
#define fs ____BAH_COMPILER_VAR_286
char * ____BAH_COMPILER_VAR_287 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen("cache/cache.json");
;                            
            ____BAH_COMPILER_VAR_287 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_287+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_287+currStrOff, "cache/cache.json", strLen_1);
            currStrOff += strLen_1;
        
        }fs.open(&fs,____BAH_COMPILER_VAR_287,"w");
array(struct cacheFile*)* ____BAH_COMPILER_VAR_288 = cache;
struct cacheFile** ____BAH_COMPILER_VAR_289 = 0;
char ** ____BAH_COMPILER_VAR_291 = (char **)((char*)(____BAH_COMPILER_VAR_289) + offsetof(struct cacheFile, file));
struct reflectElement ____BAH_COMPILER_VAR_292 = __reflect(____BAH_COMPILER_VAR_291, sizeof(char *), "cpstring", "file", 0, 0, 0, 0, offsetof(struct cacheFile, file));
long int* ____BAH_COMPILER_VAR_293 = (long int*)((char*)(____BAH_COMPILER_VAR_289) + offsetof(struct cacheFile, last));
struct reflectElement ____BAH_COMPILER_VAR_294 = __reflect(____BAH_COMPILER_VAR_293, sizeof(long int), "int", "last", 0, 0, 0, 0, offsetof(struct cacheFile, last));
char ** ____BAH_COMPILER_VAR_295 = (char **)((char*)(____BAH_COMPILER_VAR_289) + offsetof(struct cacheFile, ver));
struct reflectElement ____BAH_COMPILER_VAR_296 = __reflect(____BAH_COMPILER_VAR_295, sizeof(char *), "cpstring", "ver", 0, 0, 0, 0, offsetof(struct cacheFile, ver));
long int* ____BAH_COMPILER_VAR_297 = (long int*)((char*)(____BAH_COMPILER_VAR_289) + offsetof(struct cacheFile, date));
struct reflectElement ____BAH_COMPILER_VAR_298 = __reflect(____BAH_COMPILER_VAR_297, sizeof(long int), "int", "date", 0, 0, 0, 0, offsetof(struct cacheFile, date));
long int* ____BAH_COMPILER_VAR_299 = (long int*)((char*)(____BAH_COMPILER_VAR_289) + offsetof(struct cacheFile, mem));
struct reflectElement ____BAH_COMPILER_VAR_300 = __reflect(____BAH_COMPILER_VAR_299, sizeof(long int), "int", "mem", 0, 0, 0, 0, offsetof(struct cacheFile, mem));
array(char *)** ____BAH_COMPILER_VAR_301 = (array(char *)**)((char*)(____BAH_COMPILER_VAR_289) + offsetof(struct cacheFile, files));
char ** ____BAH_COMPILER_VAR_302 = 0;
struct reflectElement ____BAH_COMPILER_VAR_303 = __reflect(____BAH_COMPILER_VAR_302, sizeof(char *), "cpstring", "", 0, 0, 0, 0, 0);

        struct reflectElement ____BAH_COMPILER_VAR_304 = ____BAH_COMPILER_VAR_303;
        struct reflectElement ____BAH_COMPILER_VAR_305 = __reflect(____BAH_COMPILER_VAR_301, sizeof(array(char *)*), "[]cpstring", "files", 1, &____BAH_COMPILER_VAR_304, 0, 0, offsetof(struct cacheFile, files));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_290 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_290->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_290->length = 6;
        ____BAH_COMPILER_VAR_290->data = memoryAlloc(____BAH_COMPILER_VAR_290->length * ____BAH_COMPILER_VAR_290->elemSize);
        ____BAH_COMPILER_VAR_290->data[0] = ____BAH_COMPILER_VAR_292;
____BAH_COMPILER_VAR_290->data[1] = ____BAH_COMPILER_VAR_294;
____BAH_COMPILER_VAR_290->data[2] = ____BAH_COMPILER_VAR_296;
____BAH_COMPILER_VAR_290->data[3] = ____BAH_COMPILER_VAR_298;
____BAH_COMPILER_VAR_290->data[4] = ____BAH_COMPILER_VAR_300;
____BAH_COMPILER_VAR_290->data[5] = ____BAH_COMPILER_VAR_305;
struct reflectElement ____BAH_COMPILER_VAR_306 = __reflect(____BAH_COMPILER_VAR_289, sizeof(struct cacheFile), "cacheFile*", "", 0, 0, 1, ____BAH_COMPILER_VAR_290, 0);

        struct reflectElement ____BAH_COMPILER_VAR_307 = ____BAH_COMPILER_VAR_306;
        struct reflectElement ____BAH_COMPILER_VAR_308 = __reflect(____BAH_COMPILER_VAR_288, sizeof(array(struct cacheFile*)*), "[]cacheFile*", "cache", 1, &____BAH_COMPILER_VAR_307, 0, 0, 0);
char * ____BAH_COMPILER_VAR_309 =toJson(____BAH_COMPILER_VAR_308);fs.writeFile(&fs,____BAH_COMPILER_VAR_309);
fs.close(&fs);

#undef fs
};
char isValidCacheFile(struct cacheFile* cf){
if ((cf==null)||(cf->last!=getLastModified(cf->file))) {
return false;
}
char * ____BAH_COMPILER_VAR_310 =null;char * ____BAH_COMPILER_VAR_311 =intToStr(cf->mem);char * ____BAH_COMPILER_VAR_312 =pathToVarName(cf->file);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_311);
long int strLen_1 = strlen(".o.o");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_312);
long int strLen_3 = strlen("cache/");
long int strLen_4 = strlen(BAH_DIR);
;                            
            ____BAH_COMPILER_VAR_310 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_310+currStrOff, BAH_DIR, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_310+currStrOff, "cache/", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_310+currStrOff, ____BAH_COMPILER_VAR_312, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_310+currStrOff, ____BAH_COMPILER_VAR_311, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_310+currStrOff, ".o.o", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_313 =____BAH_COMPILER_VAR_310;if ((fileExists(____BAH_COMPILER_VAR_313)==0)) {
return false;
}
if ((strcmp(cf->ver, BAH_VERSION) != 0)) {
return false;
}
return true;
};
void debugLine(__BAH_ARR_TYPE_Tok line){
char * cont = "";
register long int i = 0;
while ((i<len(line))) {
struct Tok t = line->data[i];
char * ____BAH_COMPILER_VAR_314 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen("'");
long int strLen_2 = strlen(" '");
long int strLen_3 = strlen(cont);
;                            
            ____BAH_COMPILER_VAR_314 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_314+currStrOff, cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_314+currStrOff, " '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_314+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_314+currStrOff, "'", strLen_1);
            currStrOff += strLen_1;
        
        }cont = ____BAH_COMPILER_VAR_314;
i++;
};
println(cont);
};
struct Elems* dupElems(struct Elems* elems){
struct Elems* ____BAH_COMPILER_VAR_315 = memoryAlloc(sizeof(struct Elems));
____BAH_COMPILER_VAR_315->vars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_315->vars->length = 0;
            ____BAH_COMPILER_VAR_315->vars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_315->structs = memoryAlloc(sizeof(array(struct cStruct*)));
            ____BAH_COMPILER_VAR_315->structs->length = 0;
            ____BAH_COMPILER_VAR_315->structs->elemSize = sizeof(struct cStruct*);
            ____BAH_COMPILER_VAR_315->types = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_315->types->length = 0;
            ____BAH_COMPILER_VAR_315->types->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_315->fns = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_315->fns->length = 0;
            ____BAH_COMPILER_VAR_315->fns->elemSize = sizeof(struct func*);
            ____BAH_COMPILER_VAR_315->defined = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_315->defined->length = 0;
            ____BAH_COMPILER_VAR_315->defined->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_315->parent= null;
struct Elems* nElems = ____BAH_COMPILER_VAR_315;
nElems->parent = elems;
register long int j = 0;
for (; (j<len(elems->vars)); j++) {

{
long nLength = j;
if (nElems->vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nElems->vars->data, (nLength+50)*sizeof(struct variable*));
nElems->vars->data = newPtr;
}
nElems->vars->data[j] = elems->vars->data[j];
nElems->vars->length = nLength+1;
} else {
nElems->vars->data[j] = elems->vars->data[j];
}
};
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
lineType prevLine;
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

{
long nLength = i;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[i] = t;
nl->length = nLength+1;
} else {
nl->data[i] = t;
}
};
i = i+1;
};
if ((i==len(line))) {
return line;
}
}
for (; (i<len(line)); i++) {
struct Tok t = line->data[i];
if ((t.type==TOKEN_TYPE_CAST)) {
if ((i+1<len(line))) {
struct Tok nnnt = line->data[i+1];
struct string tc = string(t.cont);
tc.trimLeft(&tc,1);
tc.trimRight(&tc,1);
nnnt.bahType = tc.str(&tc);
char * ____BAH_COMPILER_VAR_316 =tc.str(&tc);struct string cCast = getCType(____BAH_COMPILER_VAR_316,elems);
char * cCastStr = cCast.str(&cCast);
char * ____BAH_COMPILER_VAR_317 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(")");
long int strLen_1 = strlen(nnnt.cont);
long int strLen_2 = strlen(cCastStr);
long int strLen_3 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_317 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_317+currStrOff, "(", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_317+currStrOff, cCastStr, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_317+currStrOff, ")", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_317+currStrOff, nnnt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }nnnt.cont = ____BAH_COMPILER_VAR_317;

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] = nnnt;
nl->length = nLength+1;
} else {
nl->data[len(nl)] = nnnt;
}
};
i = i+2;
continue;
}
}

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] = t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] = t;
}
};
};
return nl;
};
char * getDirFromFile(char * f){
char * ____BAH_COMPILER_VAR_318 =__STR(f);array(char)* p = strAsArr(____BAH_COMPILER_VAR_318);
register long int i = len(p)-1;
while ((i>=0)) {
char c = p->data[i];
if ((c==47)) {

{
long nLength = i+1;
if (p->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(p->data, (nLength+50)*sizeof(char));
p->data = newPtr;
}
p->data[i+1] = (char)0;
p->length = nLength+1;
} else {
p->data[i+1] = (char)0;
}
};
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
if (flags.isSet(&flags,"rcp")) {
ccstr = "rcp.bah";
}
else if (flags.isSet(&flags,"fastrcp")) {
ccstr = "fastrcp.bah";
}
}
else {
ccstr = "gc.bah";
}
}

        char ____BAH_COMPILER_VAR_319 = 0;
        for(int i=compilerState.includes->length-1; i!=-1;i--) {
            if (compilerState.includes->data[i] != 0 && strcmp(compilerState.includes->data[i], ccstr) == 0) {
                ____BAH_COMPILER_VAR_319=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_319) {
return true;
}
struct fileMap ____BAH_COMPILER_VAR_320 = {};
____BAH_COMPILER_VAR_320.handle = -1;
____BAH_COMPILER_VAR_320.p= null;
____BAH_COMPILER_VAR_320.open = fileMap__open;
____BAH_COMPILER_VAR_320.isValid = fileMap__isValid;
____BAH_COMPILER_VAR_320.close = fileMap__close;
#define fm ____BAH_COMPILER_VAR_320
char * ____BAH_COMPILER_VAR_321 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen(ccstr);
;                            
            ____BAH_COMPILER_VAR_321 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_321+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_321+currStrOff, ccstr, strLen_1);
            currStrOff += strLen_1;
        
        }char * fileName = ____BAH_COMPILER_VAR_321;
char isBahDir = true;
char * f = fm.open(&fm,fileName);
if ((fm.isValid(&fm)==0)) {
char * ____BAH_COMPILER_VAR_322 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(compilerState.currentDir);
long int strLen_1 = strlen(ccstr);
;                            
            ____BAH_COMPILER_VAR_322 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_322+currStrOff, compilerState.currentDir, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_322+currStrOff, ccstr, strLen_1);
            currStrOff += strLen_1;
        
        }fileName = absPath(____BAH_COMPILER_VAR_322);
f = fm.open(&fm,fileName);
isBahDir = false;
if ((fm.isValid(&fm)==0)) {
return false;
}
}
char * oDir = compilerState.currentDir;
if ((isBahDir==false)) {
char * ____BAH_COMPILER_VAR_323 =null;char * ____BAH_COMPILER_VAR_324 =getDirFromFile(ccstr);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(compilerState.currentDir);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_324);
;                            
            ____BAH_COMPILER_VAR_323 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_323+currStrOff, compilerState.currentDir, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_323+currStrOff, ____BAH_COMPILER_VAR_324, strLen_1);
            currStrOff += strLen_1;
        
        }compilerState.currentDir = ____BAH_COMPILER_VAR_323;
}
else {
char * ____BAH_COMPILER_VAR_325 =null;char * ____BAH_COMPILER_VAR_326 =getDirFromFile(ccstr);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_326);
;                            
            ____BAH_COMPILER_VAR_325 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_325+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_325+currStrOff, ____BAH_COMPILER_VAR_326, strLen_1);
            currStrOff += strLen_1;
        
        }compilerState.currentDir = ____BAH_COMPILER_VAR_325;
}
char * oFile = compilerState.currentFile;
compilerState.currentFile = fileName;

{
long nLength = len(compilerState.includes);
if (compilerState.includes->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(compilerState.includes->data, (nLength+50)*sizeof(char *));
compilerState.includes->data = newPtr;
}
compilerState.includes->data[len(compilerState.includes)] = ccstr;
compilerState.includes->length = nLength+1;
} else {
compilerState.includes->data[len(compilerState.includes)] = ccstr;
}
};
array(struct Tok)* tokens = lexer(f);
fm.close(&fm);
if ((len(tokens)==0)) {
char * ____BAH_COMPILER_VAR_327 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ccstr);
long int strLen_1 = strlen("' not recognized.");
long int strLen_2 = strlen("File '");
;                            
            ____BAH_COMPILER_VAR_327 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_327+currStrOff, "File '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_327+currStrOff, ccstr, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_327+currStrOff, "' not recognized.", strLen_1);
            currStrOff += strLen_1;
        
        }__BAH_panic(____BAH_COMPILER_VAR_327,"/home/alois/Documents/bah-bah/src/parser.bah:242");
}
char oshd = shouldOnlyDecl;
if ((isObject==true)) {
shouldOnlyDecl = true;
}
else if ((isSubObject==true)) {
shouldOnlyDecl = false;
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
if ((isValidCacheFile(cf)==false)) {
setCurrentPath(compilerState.currentDir);
char * verboseCC = "";
if ((flags.isSet(&flags,"verboseCC")==1)) {
verboseCC = "-verboseCC";
}
char * ____BAH_COMPILER_VAR_328 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fn);
long int strLen_1 = strlen("... ");
long int strLen_2 = strlen("compilling: ");
;                            
            ____BAH_COMPILER_VAR_328 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_328+currStrOff, "compilling: ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_328+currStrOff, fn, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_328+currStrOff, "... ", strLen_1);
            currStrOff += strLen_1;
        
        }print(____BAH_COMPILER_VAR_328);
char * ____BAH_COMPILER_VAR_329 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(" -o ");
long int strLen_1 = strlen(oName);
long int strLen_2 = strlen(verboseCC);
long int strLen_3 = strlen(" -object ");
long int strLen_4 = strlen(rcp);
long int strLen_5 = strlen(" ");
long int strLen_6 = strlen(fn);
long int strLen_7 = strlen(" ");
long int strLen_8 = strlen(execName);
;                            
            ____BAH_COMPILER_VAR_329 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_329+currStrOff, execName, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_329+currStrOff, " ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_329+currStrOff, fn, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_329+currStrOff, " ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_329+currStrOff, rcp, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_329+currStrOff, " -object ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_329+currStrOff, verboseCC, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_329+currStrOff, " -o ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_329+currStrOff, oName, strLen_1);
            currStrOff += strLen_1;
        
        }struct command cmd = command(____BAH_COMPILER_VAR_329);
char * res = cmd.run(&cmd);
println("ok");
setCurrentPath(wrkd);
if ((cmd.status!=0)) {
print(res);
exit(1);
}
if ((cf==null)) {
makeCacheFile(fn);
}
else {
updateCacheFile(cf);
}
}

        char ____BAH_COMPILER_VAR_330 = true;
        done->sendAny(done, &____BAH_COMPILER_VAR_330, sizeof(____BAH_COMPILER_VAR_330));
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
fileName.trimLeft(&fileName,1);
fileName.trimRight(&fileName,1);

        char ____BAH_COMPILER_VAR_331 = 0;
        for(int i=compilerState.includes->length-1; i!=-1;i--) {
            if (compilerState.includes->data[i] != 0 && strcmp(compilerState.includes->data[i], fileName.str(&fileName)) == 0) {
                ____BAH_COMPILER_VAR_331=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_331) {
return;
}

{
long nLength = len(compilerState.includes);
if (compilerState.includes->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(compilerState.includes->data, (nLength+50)*sizeof(char *));
compilerState.includes->data = newPtr;
}
compilerState.includes->data[len(compilerState.includes)] = fileName.str(&fileName);
compilerState.includes->length = nLength+1;
} else {
compilerState.includes->data[len(compilerState.includes)] = fileName.str(&fileName);
}
};
char * ____BAH_COMPILER_VAR_332 =fileName.str(&fileName);char * fn = absPath(____BAH_COMPILER_VAR_332);
if (((void *)fn==null)) {
char * ____BAH_COMPILER_VAR_333 =null;char * ____BAH_COMPILER_VAR_334 =fileName.str(&fileName);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_334);
;                            
            ____BAH_COMPILER_VAR_333 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_333+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_333+currStrOff, ____BAH_COMPILER_VAR_334, strLen_1);
            currStrOff += strLen_1;
        
        }fn = absPath(____BAH_COMPILER_VAR_333);
if (((void *)fn==null)) {
throwErr(&strt,"Unknown file {TOKEN}.");
}
}
char * of = compilerState.currentFile;
char * od = compilerState.currentDir;
compilerState.currentFile = fn;
compilerState.currentDir = getDirFromFile(fn);
struct fileStream ____BAH_COMPILER_VAR_335 = {};
____BAH_COMPILER_VAR_335.handle= null;
____BAH_COMPILER_VAR_335.name= null;
____BAH_COMPILER_VAR_335.isValid = fileStream__isValid;
____BAH_COMPILER_VAR_335.open = fileStream__open;
____BAH_COMPILER_VAR_335.close = fileStream__close;
____BAH_COMPILER_VAR_335.getPos = fileStream__getPos;
____BAH_COMPILER_VAR_335.setPos = fileStream__setPos;
____BAH_COMPILER_VAR_335.getSize = fileStream__getSize;
____BAH_COMPILER_VAR_335.rewind = fileStream__rewind;
____BAH_COMPILER_VAR_335.getChar = fileStream__getChar;
____BAH_COMPILER_VAR_335.setChar = fileStream__setChar;
____BAH_COMPILER_VAR_335.createFile = fileStream__createFile;
____BAH_COMPILER_VAR_335.writeFile = fileStream__writeFile;
____BAH_COMPILER_VAR_335.writePtr = fileStream__writePtr;
____BAH_COMPILER_VAR_335.readPtr = fileStream__readPtr;
____BAH_COMPILER_VAR_335.readContent = fileStream__readContent;
____BAH_COMPILER_VAR_335.readBytes = fileStream__readBytes;
____BAH_COMPILER_VAR_335.writeBytes = fileStream__writeBytes;
____BAH_COMPILER_VAR_335._end = fileStream___end;
#define fs ____BAH_COMPILER_VAR_335
fs.open(&fs,fn,"r");
char * f = fs.readContent(&fs);
fs.close(&fs);
array(struct Tok)* tokens = lexer(f);
char osod = shouldOnlyDecl;
shouldOnlyDecl = true;
char oiso = isSubObject;
isSubObject = true;
char * ____BAH_COMPILER_VAR_336 =null;char * ____BAH_COMPILER_VAR_337 =intToStr(RCPlevel);char * ____BAH_COMPILER_VAR_338 =pathToVarName(fn);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_337);
long int strLen_1 = strlen(".o");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_338);
long int strLen_3 = strlen("cache/");
long int strLen_4 = strlen(BAH_DIR);
;                            
            ____BAH_COMPILER_VAR_336 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_336+currStrOff, BAH_DIR, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_336+currStrOff, "cache/", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_336+currStrOff, ____BAH_COMPILER_VAR_338, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_336+currStrOff, ____BAH_COMPILER_VAR_337, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_336+currStrOff, ".o", strLen_1);
            currStrOff += strLen_1;
        
        }char * oName = ____BAH_COMPILER_VAR_336;
char * ____BAH_COMPILER_VAR_339 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(oName);
long int strLen_1 = strlen(".o");
long int strLen_2 = strlen("w ");
;                            
            ____BAH_COMPILER_VAR_339 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_339+currStrOff, "w ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_339+currStrOff, oName, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_339+currStrOff, ".o", strLen_1);
            currStrOff += strLen_1;
        
        }
{
long nLength = len(compilerState.cLibs);
if (compilerState.cLibs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(compilerState.cLibs->data, (nLength+50)*sizeof(char *));
compilerState.cLibs->data = newPtr;
}
compilerState.cLibs->data[len(compilerState.cLibs)] = ____BAH_COMPILER_VAR_339;
compilerState.cLibs->length = nLength+1;
} else {
compilerState.cLibs->data[len(compilerState.cLibs)] = ____BAH_COMPILER_VAR_339;
}
};
struct channel * done = channel();
parallelObjCompile(fn,oName,done);
parseLines(tokens,elems);
char ok = *(char*)done->receive(done);
char * ____BAH_COMPILER_VAR_340 =null;char * ____BAH_COMPILER_VAR_341 =pathToVarName(fn);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_341);
long int strLen_1 = strlen("();\n");
long int strLen_2 = strlen("__BAH_init");
;                            
            ____BAH_COMPILER_VAR_340 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_340+currStrOff, "__BAH_init", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_340+currStrOff, ____BAH_COMPILER_VAR_341, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_340+currStrOff, "();\n", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_342 =____BAH_COMPILER_VAR_340;INIT = INIT->add(INIT, rope(____BAH_COMPILER_VAR_342));
writeCache();
shouldOnlyDecl = osod;
isSubObject = oiso;
compilerState.currentFile = of;
compilerState.currentDir = od;

#undef fs
};
void parseInclude(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
if ((len(l)>2)) {
throwErr(&l->data[len(l)-1],"Invalid usage of include, ending by {TOKEN}.");
}
struct Tok strt = l->data[1];
if ((strt.type!=TOKEN_TYPE_STR)) {
throwErr(&strt,"Cannot use {TOKEN} as string in include.");
}
char * sc = strt.cont;
strTrimLeft(&sc,1);
strTrimRight(&sc,1);
if (strHasPrefix(sc,"<")||strHasSuffix(sc,".h")||strHasSuffix(sc,".c")) {
char * ____BAH_COMPILER_VAR_343 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(sc);
long int strLen_1 = strlen("\n");
long int strLen_2 = strlen("#include ");
;                            
            ____BAH_COMPILER_VAR_343 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_343+currStrOff, "#include ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_343+currStrOff, sc, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_343+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_343));

{
long nLength = len(compilerState.cIncludes);
if (compilerState.cIncludes->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(compilerState.cIncludes->data, (nLength+50)*sizeof(char *));
compilerState.cIncludes->data = newPtr;
}
compilerState.cIncludes->data[len(compilerState.cIncludes)] = sc;
compilerState.cIncludes->length = nLength+1;
} else {
compilerState.cIncludes->data[len(compilerState.cIncludes)] = sc;
}
};
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

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] = t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] = t;
}
};
i++;
continue;
}
i++;
struct Tok ____BAH_COMPILER_VAR_344 = {};
____BAH_COMPILER_VAR_344.cont = "";
____BAH_COMPILER_VAR_344.ogCont = "";
____BAH_COMPILER_VAR_344.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_344.pos = 0;
____BAH_COMPILER_VAR_344.line = 1;
____BAH_COMPILER_VAR_344.begLine = 1;
____BAH_COMPILER_VAR_344.bahType = "";
____BAH_COMPILER_VAR_344.isValue = false;
____BAH_COMPILER_VAR_344.isFunc = false;
____BAH_COMPILER_VAR_344.isOper = false;
____BAH_COMPILER_VAR_344.isEqual = false;
____BAH_COMPILER_VAR_344.pass = false;
____BAH_COMPILER_VAR_344.bahRef= null;
____BAH_COMPILER_VAR_344.cont = "";
#define nt ____BAH_COMPILER_VAR_344
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
struct variable* ____BAH_COMPILER_VAR_345 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_345->name = "";
____BAH_COMPILER_VAR_345->type = "";
____BAH_COMPILER_VAR_345->isConst = false;
____BAH_COMPILER_VAR_345->constVal = "";
____BAH_COMPILER_VAR_345->isArray = false;
____BAH_COMPILER_VAR_345->from = "";
____BAH_COMPILER_VAR_345->declScope= null;
____BAH_COMPILER_VAR_345->isGlobal = false;
____BAH_COMPILER_VAR_345->declRope= null;
____BAH_COMPILER_VAR_345->isReg = false;
struct variable* tmpV = ____BAH_COMPILER_VAR_345;
tmpV->name = t.cont;
char * ____BAH_COMPILER_VAR_346 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s->name);
long int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_346 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_346+currStrOff, s->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_346+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }tmpV->type = ____BAH_COMPILER_VAR_346;
struct string cType = getCType(tmpV->type,elems);
struct string structType = getCType(s->name,elems);

{
long nLength = len(elems->vars);
if (elems->vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(elems->vars->data, (nLength+50)*sizeof(struct variable*));
elems->vars->data = newPtr;
}
elems->vars->data[len(elems->vars)] = tmpV;
elems->vars->length = nLength+1;
} else {
elems->vars->data[len(elems->vars)] = tmpV;
}
};
char * ____BAH_COMPILER_VAR_347 =null;char * ____BAH_COMPILER_VAR_348 =declareStructMethods(tmpV,s,elems);char * ____BAH_COMPILER_VAR_349 =structType.str(&structType);char * ____BAH_COMPILER_VAR_350 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("));\n");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_348);
long int strLen_2 = strlen(____BAH_COMPILER_VAR_349);
long int strLen_3 = strlen(" = memoryAlloc(sizeof(");
long int strLen_4 = strlen(t.cont);
long int strLen_5 = strlen(" ");
long int strLen_6 = strlen(____BAH_COMPILER_VAR_350);
;                            
            ____BAH_COMPILER_VAR_347 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_347+currStrOff, ____BAH_COMPILER_VAR_350, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_347+currStrOff, " ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_347+currStrOff, t.cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_347+currStrOff, " = memoryAlloc(sizeof(", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_347+currStrOff, ____BAH_COMPILER_VAR_349, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_347+currStrOff, "));\n", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_347+currStrOff, ____BAH_COMPILER_VAR_348, strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_347));

{
long nLength = len(nl)-1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)-1] = t;
nl->length = nLength+1;
} else {
nl->data[len(nl)-1] = t;
}
};
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
i++;
struct cStruct* s = searchStruct(t.cont,elems);
if ((s==null)) {
throwErr(&t,"Unknown struct name {TOKEN}.");
}
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
long int nbBraces = 1;
for (; (i<len(line)); i++) {
t = line->data[i];
if ((strcmp(t.cont, "{") == 0)) {
nbBraces++;
}
else if ((strcmp(t.cont, "}") == 0)) {
nbBraces--;
if ((nbBraces==0)) {
break;
}
}

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] = t;
memory->length = nLength+1;
} else {
memory->data[len(memory)] = t;
}
};
};
if ((len(memory)>0)) {
memory = prePross(memory,(lineType)-1,elems);
}
long int declType = 0;
char * rvn = genCompilerVar();
struct variable* ____BAH_COMPILER_VAR_351 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_351->name = "";
____BAH_COMPILER_VAR_351->type = "";
____BAH_COMPILER_VAR_351->isConst = false;
____BAH_COMPILER_VAR_351->constVal = "";
____BAH_COMPILER_VAR_351->isArray = false;
____BAH_COMPILER_VAR_351->from = "";
____BAH_COMPILER_VAR_351->declScope= null;
____BAH_COMPILER_VAR_351->isGlobal = false;
____BAH_COMPILER_VAR_351->declRope= null;
____BAH_COMPILER_VAR_351->isReg = false;
struct variable* tmpV = ____BAH_COMPILER_VAR_351;
tmpV->name = rvn;
if ((isHeap==true)) {
char * ____BAH_COMPILER_VAR_352 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s->name);
long int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_352 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_352+currStrOff, s->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_352+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }tmpV->type = ____BAH_COMPILER_VAR_352;

{
long nLength = len(elems->vars);
if (elems->vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(elems->vars->data, (nLength+50)*sizeof(struct variable*));
elems->vars->data = newPtr;
}
elems->vars->data[len(elems->vars)] = tmpV;
elems->vars->length = nLength+1;
} else {
elems->vars->data[len(elems->vars)] = tmpV;
}
};
}
else {
tmpV->type = s->name;
}
struct string rst = getCType(tmpV->type,elems);
struct rope* r= null;
if ((isHeap==true)) {
char * ____BAH_COMPILER_VAR_353 =rst.str(&rst);struct string structType = string(____BAH_COMPILER_VAR_353);
structType.trimRight(&structType,1);
char * ____BAH_COMPILER_VAR_354 =null;char * ____BAH_COMPILER_VAR_355 =declareStructMethods(tmpV,s,elems);char * ____BAH_COMPILER_VAR_356 =structType.str(&structType);char * ____BAH_COMPILER_VAR_357 =rst.str(&rst);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("));\n");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_355);
long int strLen_2 = strlen(____BAH_COMPILER_VAR_356);
long int strLen_3 = strlen(" = memoryAlloc(sizeof(");
long int strLen_4 = strlen(rvn);
long int strLen_5 = strlen(" ");
long int strLen_6 = strlen(____BAH_COMPILER_VAR_357);
;                            
            ____BAH_COMPILER_VAR_354 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_354+currStrOff, ____BAH_COMPILER_VAR_357, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_354+currStrOff, " ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_354+currStrOff, rvn, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_354+currStrOff, " = memoryAlloc(sizeof(", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_354+currStrOff, ____BAH_COMPILER_VAR_356, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_354+currStrOff, "));\n", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_354+currStrOff, ____BAH_COMPILER_VAR_355, strLen_1);
            currStrOff += strLen_1;
        
        }r = rope(____BAH_COMPILER_VAR_354);
}
else {
char * ____BAH_COMPILER_VAR_358 =null;char * ____BAH_COMPILER_VAR_359 =declareStructMethods(tmpV,s,elems);char * ____BAH_COMPILER_VAR_360 =rst.str(&rst);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(" = {};\n");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_359);
long int strLen_2 = strlen(rvn);
long int strLen_3 = strlen(" ");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_360);
;                            
            ____BAH_COMPILER_VAR_358 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_358+currStrOff, ____BAH_COMPILER_VAR_360, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_358+currStrOff, " ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_358+currStrOff, rvn, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_358+currStrOff, " = {};\n", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_358+currStrOff, ____BAH_COMPILER_VAR_359, strLen_1);
            currStrOff += strLen_1;
        
        }r = rope(____BAH_COMPILER_VAR_358);
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
char * ____BAH_COMPILER_VAR_361 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(m->type);
long int strLen_1 = strlen("'.");
long int strLen_2 = strlen(") as '");
long int strLen_3 = strlen(vlt);
long int strLen_4 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_361 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_361+currStrOff, "Cannot use {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_361+currStrOff, vlt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_361+currStrOff, ") as '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_361+currStrOff, m->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_361+currStrOff, "'.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&vl,____BAH_COMPILER_VAR_361);
}
char * ____BAH_COMPILER_VAR_362 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(vl.cont);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen(" = ");
long int strLen_3 = strlen(m->name);
long int strLen_4 = strlen(sep);
long int strLen_5 = strlen(rvn);
;                            
            ____BAH_COMPILER_VAR_362 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_362+currStrOff, rvn, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_362+currStrOff, sep, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_362+currStrOff, m->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_362+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_362+currStrOff, vl.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_362+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }r = r->add(r, rope(____BAH_COMPILER_VAR_362));
break;
};
if ((j==len(s->members))) {
char * ____BAH_COMPILER_VAR_363 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s->name);
long int strLen_1 = strlen("' has no member called {TOKEN}.");
long int strLen_2 = strlen("Struct '");
;                            
            ____BAH_COMPILER_VAR_363 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_363+currStrOff, "Struct '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_363+currStrOff, s->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_363+currStrOff, "' has no member called {TOKEN}.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&t,____BAH_COMPILER_VAR_363);
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
j++;
char * tt = getTypeFromToken(&t,true,elems);
if ((compTypes(tt,m->type)==false)) {
char * ____BAH_COMPILER_VAR_364 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(m->type);
long int strLen_1 = strlen("'.");
long int strLen_2 = strlen(") as '");
long int strLen_3 = strlen(tt);
long int strLen_4 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_364 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_364+currStrOff, "Cannot use {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_364+currStrOff, tt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_364+currStrOff, ") as '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_364+currStrOff, m->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_364+currStrOff, "'.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&t,____BAH_COMPILER_VAR_364);
}
char * ____BAH_COMPILER_VAR_365 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen(" = ");
long int strLen_3 = strlen(m->name);
long int strLen_4 = strlen(sep);
long int strLen_5 = strlen(rvn);
;                            
            ____BAH_COMPILER_VAR_365 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_365+currStrOff, rvn, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_365+currStrOff, sep, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_365+currStrOff, m->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_365+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_365+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_365+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }r = r->add(r, rope(____BAH_COMPILER_VAR_365));
if ((k+1<len(memory))) {
k++;
struct Tok st = memory->data[k];
if ((strcmp(st.cont, ",") != 0)) {
throwErr(&st,"Need ',' separator between two values, not {TOKEN}.");
}
}
k++;
};
if (isGlobal()) {
INIT = INIT->add(INIT, r);
}
else {
OUTPUT = OUTPUT->add(OUTPUT, r);
}
t.bahType = tmpV->type;
t.cont = rvn;
t.isValue = true;
if ((isHeap==true)) {

{
long nLength = len(nl)-1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)-1] = t;
nl->length = nLength+1;
} else {
nl->data[len(nl)-1] = t;
}
};
}
else {
t.isEqual = true;

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] = t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] = t;
}
};
}
i++;
continue;
}
else {
i--;
}
}

#undef nt
}

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] = t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] = t;
}
};
i++;
};
return nl;
};
__BAH_ARR_TYPE_Tok parseArrayType(__BAH_ARR_TYPE_Tok line,struct Elems* elems,char guard){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
register long int i = 0;
if ((guard==true)) {
for (; (i<len(line)); i++) {
struct Tok t = line->data[i];
if ((strcmp(t.cont, "[") == 0)) {
break;
}

{
long nLength = i;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[i] = t;
nl->length = nLength+1;
} else {
nl->data[i] = t;
}
};
};
if ((i==len(line))) {
return line;
}
}
for (; (i<len(line)); i++) {
struct Tok t = line->data[i];
if ((strcmp(t.cont, "[") == 0)) {
i++;
if ((i<len(line))) {
t = line->data[i];
if ((strcmp(t.cont, "]") == 0)) {
i++;
long int depth = 1;
char * bracks = "[]";
for (; (i<len(line)-1); i++) {
t = line->data[i];
struct Tok nt = line->data[i+1];
if ((strcmp(t.cont, "[") == 0)&&(strcmp(nt.cont, "]") == 0)) {
depth++;
char * ____BAH_COMPILER_VAR_366 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(bracks);
long int strLen_1 = strlen("[]");
;                            
            ____BAH_COMPILER_VAR_366 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_366+currStrOff, bracks, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_366+currStrOff, "[]", strLen_1);
            currStrOff += strLen_1;
        
        }bracks = ____BAH_COMPILER_VAR_366;
i++;
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
char * ____BAH_COMPILER_VAR_367 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(bracks);
long int strLen_1 = strlen(arrElem);
;                            
            ____BAH_COMPILER_VAR_367 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_367+currStrOff, bracks, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_367+currStrOff, arrElem, strLen_1);
            currStrOff += strLen_1;
        
        }t.bahType = ____BAH_COMPILER_VAR_367;
t.cont = "";
t.isValue = true;

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] = t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] = t;
}
};
continue;
}
}
}
}

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] = t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] = t;
}
};
};
return nl;
};
array(char *)* comparators;
array(char *)* compSep;
__BAH_ARR_TYPE_Tok parsePointers(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
array(char *)* ptrOpers = memoryAlloc(sizeof(array(char *)));

ptrOpers->length = 2;
ptrOpers->elemSize = sizeof(char *);
ptrOpers->data = memoryAlloc(sizeof(char *) * 50);ptrOpers->data[0] = "&";
ptrOpers->data[1] = "*";
register long int i = 0;
while ((i<len(l))) {
struct Tok t = l->data[i];
if ((t.type==TOKEN_TYPE_SYNTAX)) {
if ((strcmp(t.cont, "*") == 0)) {
if ((i>0)) {
struct Tok pt = nl->data[len(nl)-1];
if ((pt.type==TOKEN_TYPE_VAR)) {
if ((i+1<len(l))) {
struct Tok nt = l->data[i+1];
if ((nt.isValue==false)&&(strcmp(nt.cont, "(") != 0)) {
char * ____BAH_COMPILER_VAR_368 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_368 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_368+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_368+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_368;

{
long nLength = len(nl)-1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)-1] = pt;
nl->length = nLength+1;
} else {
nl->data[len(nl)-1] = pt;
}
};
i = i+1;
continue;
}
}
else {
char * ____BAH_COMPILER_VAR_369 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_369 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_369+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_369+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_369;

{
long nLength = len(nl)-1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)-1] = pt;
nl->length = nLength+1;
} else {
nl->data[len(nl)-1] = pt;
}
};
i = i+1;
continue;
}
}
}
}
if (inArrayStr(t.cont,ptrOpers)) {
if ((i>0)) {
struct Tok pt = nl->data[len(nl)-1];
if ((pt.isValue==true)) {

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] = t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] = t;
}
};
i = i+1;
continue;
}
}
i = i+1;
if ((i<len(l))) {
struct Tok nt = l->data[i];
if ((nt.type==TOKEN_TYPE_VAR)) {
char * ____BAH_COMPILER_VAR_370 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_370 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_370+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_370+currStrOff, nt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }nt.cont = ____BAH_COMPILER_VAR_370;

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] = nt;
nl->length = nLength+1;
} else {
nl->data[len(nl)] = nt;
}
};
i = i+1;
continue;
}
}
}
}

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] = t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] = t;
}
};
i = i+1;
};
return nl;
};
char * parseSerialize(struct Tok e,struct Elems* elems){
struct variable* v = searchVar(e.cont,elems);
if ((v==null)) {
throwErr(&e,"Must be a var, not {TOKEN}.");
}
struct cStruct* s = searchStruct(v->type,elems);
if ((s==null)) {
throwErr(&e,"Must be a struct, not {TOKEN}.");
}
struct string svt = string(v->type);
register long int ptrLevel = svt.count(&svt,"*");
svt.replace(&svt,"*","");
char * code= null;
if ((ptrLevel==0)) {
char * ____BAH_COMPILER_VAR_371 =null;char * ____BAH_COMPILER_VAR_372 =svt.str(&svt);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_372);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen("sizeof(struct ");
long int strLen_3 = strlen(", ");
long int strLen_4 = strlen(e.cont);
long int strLen_5 = strlen("__serialize(&");
;                            
            ____BAH_COMPILER_VAR_371 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_371+currStrOff, "__serialize(&", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_371+currStrOff, e.cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_371+currStrOff, ", ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_371+currStrOff, "sizeof(struct ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_371+currStrOff, ____BAH_COMPILER_VAR_372, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_371+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_371;
}
else {
char * ptrRect = "";
while ((ptrLevel>1)) {
char * ____BAH_COMPILER_VAR_373 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ptrRect);
long int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_373 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_373+currStrOff, ptrRect, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_373+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }ptrRect = ____BAH_COMPILER_VAR_373;
ptrLevel = ptrLevel-1;
};
char * ____BAH_COMPILER_VAR_374 =null;char * ____BAH_COMPILER_VAR_375 =svt.str(&svt);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_375);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen("sizeof(struct ");
long int strLen_3 = strlen(", ");
long int strLen_4 = strlen(e.cont);
long int strLen_5 = strlen(ptrRect);
long int strLen_6 = strlen("__serialize(");
;                            
            ____BAH_COMPILER_VAR_374 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_374+currStrOff, "__serialize(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_374+currStrOff, ptrRect, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_374+currStrOff, e.cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_374+currStrOff, ", ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_374+currStrOff, "sizeof(struct ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_374+currStrOff, ____BAH_COMPILER_VAR_375, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_374+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_374;
register long int i = 0;
while ((i<len(s->members))) {
struct structMemb* m = s->members->data[i];
if ((strcmp(m->type, "cpstring") == 0)) {
char * ____BAH_COMPILER_VAR_376 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(m->name);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen("->");
long int strLen_3 = strlen(e.cont);
long int strLen_4 = strlen("+strlen(");
long int strLen_5 = strlen(code);
;                            
            ____BAH_COMPILER_VAR_376 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_376+currStrOff, code, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_376+currStrOff, "+strlen(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_376+currStrOff, e.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_376+currStrOff, "->", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_376+currStrOff, m->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_376+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_376;
}
i = i+1;
};
}
char * ____BAH_COMPILER_VAR_377 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(")");
;                            
            ____BAH_COMPILER_VAR_377 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_377+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_377+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }return ____BAH_COMPILER_VAR_377;
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
cType.append(&cType,"*");
}
char * ____BAH_COMPILER_VAR_378 =null;char * ____BAH_COMPILER_VAR_379 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen(" = ");
long int strLen_3 = strlen(v);
long int strLen_4 = strlen(" ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_379);
;                            
            ____BAH_COMPILER_VAR_378 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_378+currStrOff, ____BAH_COMPILER_VAR_379, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_378+currStrOff, " ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_378+currStrOff, v, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_378+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_378+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_378+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_378));
t.cont = v;
if ((t.type==TOKEN_TYPE_STR)) {
ogName = "[bah cpstring]";
}
}
char * arrElem = "0";
if (strHasPrefix(tt,"[]")) {
isArr = "1";
struct string aet = string(tt);
aet.trimLeft(&aet,2);
struct Tok ____BAH_COMPILER_VAR_380 = {};
____BAH_COMPILER_VAR_380.cont = "";
____BAH_COMPILER_VAR_380.ogCont = "";
____BAH_COMPILER_VAR_380.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_380.pos = 0;
____BAH_COMPILER_VAR_380.line = 1;
____BAH_COMPILER_VAR_380.begLine = 1;
____BAH_COMPILER_VAR_380.bahType = "";
____BAH_COMPILER_VAR_380.isValue = false;
____BAH_COMPILER_VAR_380.isFunc = false;
____BAH_COMPILER_VAR_380.isOper = false;
____BAH_COMPILER_VAR_380.isEqual = false;
____BAH_COMPILER_VAR_380.pass = false;
____BAH_COMPILER_VAR_380.bahRef= null;
#define tmpT ____BAH_COMPILER_VAR_380
tmpT.type = TOKEN_TYPE_VAR;
tmpT.cont = "0";
char * ____BAH_COMPILER_VAR_381 =aet.str(&aet);struct Tok rt = parseReflect(tmpT,____BAH_COMPILER_VAR_381,elems,true,"","0");
char * aev = genCompilerVar();
char * ____BAH_COMPILER_VAR_382 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(rt.cont);
long int strLen_1 = strlen(";\n        ");
long int strLen_2 = strlen(" = ");
long int strLen_3 = strlen(aev);
long int strLen_4 = strlen("\n        struct reflectElement ");
;                            
            ____BAH_COMPILER_VAR_382 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_382+currStrOff, "\n        struct reflectElement ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_382+currStrOff, aev, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_382+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_382+currStrOff, rt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_382+currStrOff, ";\n        ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_382));
char * ____BAH_COMPILER_VAR_383 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("&");
long int strLen_1 = strlen(aev);
;                            
            ____BAH_COMPILER_VAR_383 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_383+currStrOff, "&", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_383+currStrOff, aev, strLen_1);
            currStrOff += strLen_1;
        
        }arrElem = ____BAH_COMPILER_VAR_383;

#undef tmpT
}
else if (strHasPrefix(tt,"map:")) {
struct string aet = string(tt);
aet.trimLeft(&aet,4);
struct Tok ____BAH_COMPILER_VAR_384 = {};
____BAH_COMPILER_VAR_384.cont = "";
____BAH_COMPILER_VAR_384.ogCont = "";
____BAH_COMPILER_VAR_384.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_384.pos = 0;
____BAH_COMPILER_VAR_384.line = 1;
____BAH_COMPILER_VAR_384.begLine = 1;
____BAH_COMPILER_VAR_384.bahType = "";
____BAH_COMPILER_VAR_384.isValue = false;
____BAH_COMPILER_VAR_384.isFunc = false;
____BAH_COMPILER_VAR_384.isOper = false;
____BAH_COMPILER_VAR_384.isEqual = false;
____BAH_COMPILER_VAR_384.pass = false;
____BAH_COMPILER_VAR_384.bahRef= null;
#define tmpT ____BAH_COMPILER_VAR_384
tmpT.type = TOKEN_TYPE_VAR;
tmpT.cont = "0";
char * ____BAH_COMPILER_VAR_385 =aet.str(&aet);struct Tok rt = parseReflect(tmpT,____BAH_COMPILER_VAR_385,elems,true,"","0");
char * aev = genCompilerVar();
char * ____BAH_COMPILER_VAR_386 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(rt.cont);
long int strLen_1 = strlen(";\n        ");
long int strLen_2 = strlen(" = ");
long int strLen_3 = strlen(aev);
long int strLen_4 = strlen("\n        struct reflectElement ");
;                            
            ____BAH_COMPILER_VAR_386 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_386+currStrOff, "\n        struct reflectElement ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_386+currStrOff, aev, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_386+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_386+currStrOff, rt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_386+currStrOff, ";\n        ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_386));
char * ____BAH_COMPILER_VAR_387 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("&");
long int strLen_1 = strlen(aev);
;                            
            ____BAH_COMPILER_VAR_387 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_387+currStrOff, "&", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_387+currStrOff, aev, strLen_1);
            currStrOff += strLen_1;
        
        }arrElem = ____BAH_COMPILER_VAR_387;

#undef tmpT
}
char * isStruct = "0";
struct cStruct* ts = searchStruct(tt,elems);
char * structLayout = "0";
if ((ts!=null)) {
isStruct = "1";
structLayout = genCompilerVar();
struct variable* ____BAH_COMPILER_VAR_388 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_388->name = "";
____BAH_COMPILER_VAR_388->type = "";
____BAH_COMPILER_VAR_388->isConst = false;
____BAH_COMPILER_VAR_388->constVal = "";
____BAH_COMPILER_VAR_388->isArray = false;
____BAH_COMPILER_VAR_388->from = "";
____BAH_COMPILER_VAR_388->declScope= null;
____BAH_COMPILER_VAR_388->isGlobal = false;
____BAH_COMPILER_VAR_388->declRope= null;
____BAH_COMPILER_VAR_388->isReg = false;
struct variable* slv = ____BAH_COMPILER_VAR_388;
slv->name = structLayout;
slv->type = "[]reflectElement";

{
long nLength = len(elems->vars);
if (elems->vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(elems->vars->data, (nLength+50)*sizeof(struct variable*));
elems->vars->data = newPtr;
}
elems->vars->data[len(elems->vars)] = slv;
elems->vars->length = nLength+1;
} else {
elems->vars->data[len(elems->vars)] = slv;
}
};
struct rope* dataLayout = rope("");
register long int i = 0;
for (; (i<len(ts->members)); i++) {
struct structMemb* m = ts->members->data[i];
if ((strcmp(m->type, tt) == 0)) {
struct structMemb* ____BAH_COMPILER_VAR_389 = memoryAlloc(sizeof(struct structMemb));
____BAH_COMPILER_VAR_389->name = "";
____BAH_COMPILER_VAR_389->type = "";
____BAH_COMPILER_VAR_389->isConst = false;
____BAH_COMPILER_VAR_389->constVal = "";
____BAH_COMPILER_VAR_389->isArray = false;
____BAH_COMPILER_VAR_389->from = "";
____BAH_COMPILER_VAR_389->declScope= null;
____BAH_COMPILER_VAR_389->isGlobal = false;
____BAH_COMPILER_VAR_389->declRope= null;
____BAH_COMPILER_VAR_389->isReg = false;
____BAH_COMPILER_VAR_389->def = "";
____BAH_COMPILER_VAR_389->isFn = false;
struct structMemb* nm = ____BAH_COMPILER_VAR_389;
*nm = *m;
m = nm;
m->type = "ptr";
}
struct Tok ____BAH_COMPILER_VAR_390 = {};
____BAH_COMPILER_VAR_390.cont = "";
____BAH_COMPILER_VAR_390.ogCont = "";
____BAH_COMPILER_VAR_390.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_390.pos = 0;
____BAH_COMPILER_VAR_390.line = 1;
____BAH_COMPILER_VAR_390.begLine = 1;
____BAH_COMPILER_VAR_390.bahType = "";
____BAH_COMPILER_VAR_390.isValue = false;
____BAH_COMPILER_VAR_390.isFunc = false;
____BAH_COMPILER_VAR_390.isOper = false;
____BAH_COMPILER_VAR_390.isEqual = false;
____BAH_COMPILER_VAR_390.pass = false;
____BAH_COMPILER_VAR_390.bahRef= null;
#define tmpT ____BAH_COMPILER_VAR_390
tmpT.type = TOKEN_TYPE_VAR;
char * sep = "->";
if ((strCount(tt,"*")==0)) {
sep = ".";
}
struct string mCtype = getCType(m->type,elems);
struct string offsetTT = string(tt);
offsetTT.replace(&offsetTT,"*","");
char * ____BAH_COMPILER_VAR_391 =null;char * ____BAH_COMPILER_VAR_392 =offsetTT.str(&offsetTT);char * ____BAH_COMPILER_VAR_393 =mCtype.str(&mCtype);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(m->name);
long int strLen_1 = strlen("))");
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_392);
long int strLen_4 = strlen(") + offsetof(struct ");
long int strLen_5 = strlen(t.cont);
long int strLen_6 = strlen("*)((char*)(");
long int strLen_7 = strlen(____BAH_COMPILER_VAR_393);
long int strLen_8 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_391 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_391+currStrOff, "(", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_391+currStrOff, ____BAH_COMPILER_VAR_393, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_391+currStrOff, "*)((char*)(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_391+currStrOff, t.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_391+currStrOff, ") + offsetof(struct ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_391+currStrOff, ____BAH_COMPILER_VAR_392, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_391+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_391+currStrOff, m->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_391+currStrOff, "))", strLen_1);
            currStrOff += strLen_1;
        
        }tmpT.cont = ____BAH_COMPILER_VAR_391;
char * ____BAH_COMPILER_VAR_394 =null;char * ____BAH_COMPILER_VAR_395 =offsetTT.str(&offsetTT);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(m->name);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_395);
long int strLen_4 = strlen("offsetof(struct ");
;                            
            ____BAH_COMPILER_VAR_394 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_394+currStrOff, "offsetof(struct ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_394+currStrOff, ____BAH_COMPILER_VAR_395, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_394+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_394+currStrOff, m->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_394+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }struct Tok rt = parseReflect(tmpT,m->type,elems,true,m->name,____BAH_COMPILER_VAR_394);
char * ____BAH_COMPILER_VAR_396 =null;char * ____BAH_COMPILER_VAR_397 =intToStr(i);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(rt.cont);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen("] = ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_397);
long int strLen_4 = strlen("->data[");
long int strLen_5 = strlen(structLayout);
;                            
            ____BAH_COMPILER_VAR_396 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_396+currStrOff, structLayout, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_396+currStrOff, "->data[", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_396+currStrOff, ____BAH_COMPILER_VAR_397, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_396+currStrOff, "] = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_396+currStrOff, rt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_396+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }dataLayout = dataLayout->add(dataLayout, rope(____BAH_COMPILER_VAR_396));

#undef tmpT
};
char * ____BAH_COMPILER_VAR_398 =null;char * ____BAH_COMPILER_VAR_399 =intToStr(len(ts->members));
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(structLayout);
long int strLen_1 = strlen("->elemSize);\n        ");
long int strLen_2 = strlen("->length * ");
long int strLen_3 = strlen(structLayout);
long int strLen_4 = strlen("->data = memoryAlloc(");
long int strLen_5 = strlen(structLayout);
long int strLen_6 = strlen(";\n        ");
long int strLen_7 = strlen(____BAH_COMPILER_VAR_399);
long int strLen_8 = strlen("->length = ");
long int strLen_9 = strlen(structLayout);
long int strLen_10 = strlen("->elemSize = sizeof(struct reflectElement);\n        ");
long int strLen_11 = strlen(structLayout);
long int strLen_12 = strlen(" = memoryAlloc(sizeof(array(struct reflectElement)));\n        ");
long int strLen_13 = strlen(structLayout);
long int strLen_14 = strlen("\n        array(struct reflectElement) * ");
;                            
            ____BAH_COMPILER_VAR_398 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13+strLen_14);
            
                    memcpy(____BAH_COMPILER_VAR_398+currStrOff, "\n        array(struct reflectElement) * ", strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_398+currStrOff, structLayout, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_398+currStrOff, " = memoryAlloc(sizeof(array(struct reflectElement)));\n        ", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_398+currStrOff, structLayout, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_398+currStrOff, "->elemSize = sizeof(struct reflectElement);\n        ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_398+currStrOff, structLayout, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_398+currStrOff, "->length = ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_398+currStrOff, ____BAH_COMPILER_VAR_399, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_398+currStrOff, ";\n        ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_398+currStrOff, structLayout, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_398+currStrOff, "->data = memoryAlloc(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_398+currStrOff, structLayout, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_398+currStrOff, "->length * ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_398+currStrOff, structLayout, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_398+currStrOff, "->elemSize);\n        ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_398)->add(rope(____BAH_COMPILER_VAR_398), dataLayout));
}
char * amp = "";
if ((strCount(tt,"*")==0)&&(strcmp(tt, "cpstring") != 0)&&(strcmp(tt, "ptr") != 0)&&(parsedPointer==false)) {
amp = "&";
}
struct string name = string(ogName);
if ((hasStructSep(name)==true)) {
name = splitStructSepAfter(name);
}
struct string cType;
if (strHasPrefix(tt,"function(")) {
cType = string("void*");
}
else {
cType = getCType(tt,elems);
}
if (cType.hasPrefix(&cType,"struct ")) {
cType.replace(&cType,"*","");
}
if ((cType.length==0)) {
cType.set(&cType,"0");
}
struct variable* ____BAH_COMPILER_VAR_400 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_400->name = "";
____BAH_COMPILER_VAR_400->type = "";
____BAH_COMPILER_VAR_400->isConst = false;
____BAH_COMPILER_VAR_400->constVal = "";
____BAH_COMPILER_VAR_400->isArray = false;
____BAH_COMPILER_VAR_400->from = "";
____BAH_COMPILER_VAR_400->declScope= null;
____BAH_COMPILER_VAR_400->isGlobal = false;
____BAH_COMPILER_VAR_400->declRope= null;
____BAH_COMPILER_VAR_400->isReg = false;
struct variable* rv = ____BAH_COMPILER_VAR_400;
rv->name = genCompilerVar();
rv->type = "reflectElement";

{
long nLength = len(elems->vars);
if (elems->vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(elems->vars->data, (nLength+50)*sizeof(struct variable*));
elems->vars->data = newPtr;
}
elems->vars->data[len(elems->vars)] = rv;
elems->vars->length = nLength+1;
} else {
elems->vars->data[len(elems->vars)] = rv;
}
};
char * ____BAH_COMPILER_VAR_401 =null;char * ____BAH_COMPILER_VAR_402 =name.str(&name);char * ____BAH_COMPILER_VAR_403 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(offset);
long int strLen_1 = strlen(");\n");
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(structLayout);
long int strLen_4 = strlen(", ");
long int strLen_5 = strlen(isStruct);
long int strLen_6 = strlen(", ");
long int strLen_7 = strlen(arrElem);
long int strLen_8 = strlen(", ");
long int strLen_9 = strlen(isArr);
long int strLen_10 = strlen("\", ");
long int strLen_11 = strlen(____BAH_COMPILER_VAR_402);
long int strLen_12 = strlen("\", \"");
long int strLen_13 = strlen(tt);
long int strLen_14 = strlen("), \"");
long int strLen_15 = strlen(____BAH_COMPILER_VAR_403);
long int strLen_16 = strlen(", sizeof(");
long int strLen_17 = strlen(t.cont);
long int strLen_18 = strlen(amp);
long int strLen_19 = strlen(" = __reflect(");
long int strLen_20 = strlen(rv->name);
long int strLen_21 = strlen("struct reflectElement ");
;                            
            ____BAH_COMPILER_VAR_401 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13+strLen_14+strLen_15+strLen_16+strLen_17+strLen_18+strLen_19+strLen_20+strLen_21);
            
                    memcpy(____BAH_COMPILER_VAR_401+currStrOff, "struct reflectElement ", strLen_21);
                    currStrOff += strLen_21;
                    
                    memcpy(____BAH_COMPILER_VAR_401+currStrOff, rv->name, strLen_20);
                    currStrOff += strLen_20;
                    
                    memcpy(____BAH_COMPILER_VAR_401+currStrOff, " = __reflect(", strLen_19);
                    currStrOff += strLen_19;
                    
                    memcpy(____BAH_COMPILER_VAR_401+currStrOff, amp, strLen_18);
                    currStrOff += strLen_18;
                    
                    memcpy(____BAH_COMPILER_VAR_401+currStrOff, t.cont, strLen_17);
                    currStrOff += strLen_17;
                    
                    memcpy(____BAH_COMPILER_VAR_401+currStrOff, ", sizeof(", strLen_16);
                    currStrOff += strLen_16;
                    
                    memcpy(____BAH_COMPILER_VAR_401+currStrOff, ____BAH_COMPILER_VAR_403, strLen_15);
                    currStrOff += strLen_15;
                    
                    memcpy(____BAH_COMPILER_VAR_401+currStrOff, "), \"", strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_401+currStrOff, tt, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_401+currStrOff, "\", \"", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_401+currStrOff, ____BAH_COMPILER_VAR_402, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_401+currStrOff, "\", ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_401+currStrOff, isArr, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_401+currStrOff, ", ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_401+currStrOff, arrElem, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_401+currStrOff, ", ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_401+currStrOff, isStruct, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_401+currStrOff, ", ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_401+currStrOff, structLayout, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_401+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_401+currStrOff, offset, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_401+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_401));
t.cont = rv->name;
return t;
};
char * parseArrayDecl(struct variable* v,__BAH_ARR_TYPE_Tok l,long int i,long int max,struct Elems* elems){
long int arrayLength = 0;
struct string arrType = getCType(v->type,elems);
arrType.trimRight(&arrType,1);
char * ____BAH_COMPILER_VAR_404 =null;char * ____BAH_COMPILER_VAR_405 =arrType.str(&arrType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_405);
long int strLen_1 = strlen("))");
long int strLen_2 = strlen("memoryAlloc(sizeof(");
;                            
            ____BAH_COMPILER_VAR_404 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_404+currStrOff, "memoryAlloc(sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_404+currStrOff, ____BAH_COMPILER_VAR_405, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_404+currStrOff, "))", strLen_1);
            currStrOff += strLen_1;
        
        }char * code = ____BAH_COMPILER_VAR_404;
arrType.trimLeft(&arrType,6);
arrType.trimRight(&arrType,1);
char * elemTypeStr = arrType.str(&arrType);
if ((i+1!=max)) {
i++;
struct Tok nt = l->data[i];
if ((strcmp(nt.cont, "{") != 0)) {
throwErr(&l->data[i+1],"{TOKEN} not expected after array initialization.");
}
struct string elemBahType = string(v->type);
elemBahType.trimLeft(&elemBahType,2);
char * elemBahTypeStr = elemBahType.str(&elemBahType);
i = i+1;
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
while ((i<max)) {

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] = l->data[i];
memory->length = nLength+1;
} else {
memory->data[len(memory)] = l->data[i];
}
};
i = i+1;
};
memory = prePross(memory,(lineType)-1,elems);
i = 0;
while ((i<len(memory))) {
struct Tok t = memory->data[i];
if ((strcmp(t.cont, "{") == 0)) {
long int j = i-1;
long int nbBraces = 0;
for (; (i<len(memory)); i++) {
struct Tok tmpT = memory->data[i];
if ((strcmp(tmpT.cont, "{") == 0)) {
nbBraces++;
}
else if ((strcmp(tmpT.cont, "}") == 0)) {
nbBraces--;
}
if ((nbBraces==0)) {
break;
}
};
struct variable* ____BAH_COMPILER_VAR_406 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_406->name = "";
____BAH_COMPILER_VAR_406->type = "";
____BAH_COMPILER_VAR_406->isConst = false;
____BAH_COMPILER_VAR_406->constVal = "";
____BAH_COMPILER_VAR_406->isArray = false;
____BAH_COMPILER_VAR_406->from = "";
____BAH_COMPILER_VAR_406->declScope= null;
____BAH_COMPILER_VAR_406->isGlobal = false;
____BAH_COMPILER_VAR_406->declRope= null;
____BAH_COMPILER_VAR_406->isReg = false;
struct variable* tmpV = ____BAH_COMPILER_VAR_406;
tmpV->name = genCompilerVar();
struct string elemType = string(v->type);
elemType.trimLeft(&elemType,2);
tmpV->type = elemType.str(&elemType);

{
long nLength = len(elems->vars);
if (elems->vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(elems->vars->data, (nLength+50)*sizeof(struct variable*));
elems->vars->data = newPtr;
}
elems->vars->data[len(elems->vars)] = tmpV;
elems->vars->length = nLength+1;
} else {
elems->vars->data[len(elems->vars)] = tmpV;
}
};
char * oldNL = NEXT_LINE;
NEXT_LINE = "";
char * innerCode = parseArrayDecl(tmpV,memory,j,i+1,elems);
char * ____BAH_COMPILER_VAR_407 =elemType.str(&elemType);struct string cType = getCType(____BAH_COMPILER_VAR_407,elems);
char * ____BAH_COMPILER_VAR_408 =null;char * ____BAH_COMPILER_VAR_409 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(NEXT_LINE);
long int strLen_1 = strlen("\n                ");
long int strLen_2 = strlen(";\n                ");
long int strLen_3 = strlen(innerCode);
long int strLen_4 = strlen(" = ");
long int strLen_5 = strlen(tmpV->name);
long int strLen_6 = strlen(") * ");
long int strLen_7 = strlen(____BAH_COMPILER_VAR_409);
long int strLen_8 = strlen("\n                array(");
;                            
            ____BAH_COMPILER_VAR_408 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_408+currStrOff, "\n                array(", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_408+currStrOff, ____BAH_COMPILER_VAR_409, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_408+currStrOff, ") * ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_408+currStrOff, tmpV->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_408+currStrOff, " = ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_408+currStrOff, innerCode, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_408+currStrOff, ";\n                ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_408+currStrOff, NEXT_LINE, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_408+currStrOff, "\n                ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_408));
NEXT_LINE = oldNL;
struct Tok ____BAH_COMPILER_VAR_410 = {};
____BAH_COMPILER_VAR_410.cont = "";
____BAH_COMPILER_VAR_410.ogCont = "";
____BAH_COMPILER_VAR_410.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_410.pos = 0;
____BAH_COMPILER_VAR_410.line = 1;
____BAH_COMPILER_VAR_410.begLine = 1;
____BAH_COMPILER_VAR_410.bahType = "";
____BAH_COMPILER_VAR_410.isValue = false;
____BAH_COMPILER_VAR_410.isFunc = false;
____BAH_COMPILER_VAR_410.isOper = false;
____BAH_COMPILER_VAR_410.isEqual = false;
____BAH_COMPILER_VAR_410.pass = false;
____BAH_COMPILER_VAR_410.bahRef= null;
____BAH_COMPILER_VAR_410.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_410.cont = tmpV->name;
____BAH_COMPILER_VAR_410.bahType = elemType.str(&elemType);
____BAH_COMPILER_VAR_410.isValue = true;
t = ____BAH_COMPILER_VAR_410;
}
char * tt = getTypeFromToken(&t,true,elems);
if ((compTypes(tt,elemBahTypeStr)==false)) {
char * ____BAH_COMPILER_VAR_411 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(") as ");
long int strLen_1 = strlen(elemBahTypeStr);
long int strLen_2 = strlen(tt);
long int strLen_3 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_411 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_411+currStrOff, "Cannot use {TOKEN} (", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_411+currStrOff, tt, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_411+currStrOff, ") as ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_411+currStrOff, elemBahTypeStr, strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&t,____BAH_COMPILER_VAR_411);
}
char * strArrayLength = intToStr(arrayLength);
arrayLength = arrayLength+1;
char * ____BAH_COMPILER_VAR_412 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen("] = ");
long int strLen_3 = strlen(strArrayLength);
long int strLen_4 = strlen("->data[");
long int strLen_5 = strlen(v->name);
long int strLen_6 = strlen(NEXT_LINE);
;                            
            ____BAH_COMPILER_VAR_412 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_412+currStrOff, NEXT_LINE, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_412+currStrOff, v->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_412+currStrOff, "->data[", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_412+currStrOff, strArrayLength, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_412+currStrOff, "] = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_412+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_412+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }NEXT_LINE = ____BAH_COMPILER_VAR_412;
i++;
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
char * ____BAH_COMPILER_VAR_413 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(");");
long int strLen_1 = strlen(NEXT_LINE);
long int strLen_2 = strlen(allocLengthStr);
long int strLen_3 = strlen(") * ");
long int strLen_4 = strlen(elemTypeStr);
long int strLen_5 = strlen("->data = memoryAlloc(sizeof(");
long int strLen_6 = strlen(v->name);
;                            
            ____BAH_COMPILER_VAR_413 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_413+currStrOff, v->name, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_413+currStrOff, "->data = memoryAlloc(sizeof(", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_413+currStrOff, elemTypeStr, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_413+currStrOff, ") * ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_413+currStrOff, allocLengthStr, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_413+currStrOff, ");", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_413+currStrOff, NEXT_LINE, strLen_1);
            currStrOff += strLen_1;
        
        }NEXT_LINE = ____BAH_COMPILER_VAR_413;
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
char * ____BAH_COMPILER_VAR_414 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(");\n");
long int strLen_1 = strlen(NEXT_LINE);
long int strLen_2 = strlen(elemTypeStr);
long int strLen_3 = strlen("->elemSize = sizeof(");
long int strLen_4 = strlen(v->name);
long int strLen_5 = strlen(";\n");
long int strLen_6 = strlen(strArrayLength);
long int strLen_7 = strlen("->length = ");
long int strLen_8 = strlen(v->name);
long int strLen_9 = strlen("\n");
;                            
            ____BAH_COMPILER_VAR_414 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9);
            
                    memcpy(____BAH_COMPILER_VAR_414+currStrOff, "\n", strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_414+currStrOff, v->name, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_414+currStrOff, "->length = ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_414+currStrOff, strArrayLength, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_414+currStrOff, ";\n", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_414+currStrOff, v->name, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_414+currStrOff, "->elemSize = sizeof(", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_414+currStrOff, elemTypeStr, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_414+currStrOff, ");\n", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_414+currStrOff, NEXT_LINE, strLen_1);
            currStrOff += strLen_1;
        
        }NEXT_LINE = ____BAH_COMPILER_VAR_414;
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
char * ____BAH_COMPILER_VAR_415 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ft.cont);
long int strLen_1 = strlen(";\n");
;                            
            ____BAH_COMPILER_VAR_415 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_415+currStrOff, ft.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_415+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_415));
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
struct variable* ____BAH_COMPILER_VAR_416 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_416->name = "";
____BAH_COMPILER_VAR_416->type = "";
____BAH_COMPILER_VAR_416->isConst = false;
____BAH_COMPILER_VAR_416->constVal = "";
____BAH_COMPILER_VAR_416->isArray = false;
____BAH_COMPILER_VAR_416->from = "";
____BAH_COMPILER_VAR_416->declScope= null;
____BAH_COMPILER_VAR_416->isGlobal = false;
____BAH_COMPILER_VAR_416->declRope= null;
____BAH_COMPILER_VAR_416->isReg = false;
v = ____BAH_COMPILER_VAR_416;
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
c.trimRight(&c,2);
char * ____BAH_COMPILER_VAR_417 =c.str(&c);v = searchVar(____BAH_COMPILER_VAR_417,elems);
if ((v==null)) {
throwErr(&t,"Cannot increase/decrease not declared variable {TOKEN}.");
}
char * ____BAH_COMPILER_VAR_418 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(";\n");
;                            
            ____BAH_COMPILER_VAR_418 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_418+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_418+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_418));
return;
}
if ((len(l)<2)) {
throwErr(&ft,"Missing '=' after {TOKEN}.");
}
struct Tok operT = l->data[1];

        char ____BAH_COMPILER_VAR_419 = 0;
        for(int i=equalsTokens->length-1; i!=-1;i--) {
            if (equalsTokens->data[i] != 0 && strcmp(equalsTokens->data[i], operT.cont) == 0) {
                ____BAH_COMPILER_VAR_419=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_419&&(strcmp(operT.cont, "=") != 0)) {
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 1;
nl->elemSize = sizeof(struct Tok);
nl->data = memoryAlloc(sizeof(struct Tok) * 50);nl->data[0] = l->data[0];
if ((2==len(l))) {
throwErr(&operT,"Cannot use {TOKEN} on nothing.");
}
struct string oper = string(operT.cont);
oper.trimRight(&oper,1);
struct Tok operTok = operT;
operTok.cont = oper.str(&oper);
array(struct Tok)* tmpL = memoryAlloc(sizeof(array(struct Tok)));

tmpL->length = 3;
tmpL->elemSize = sizeof(struct Tok);
tmpL->data = memoryAlloc(sizeof(struct Tok) * 50);tmpL->data[0] = ft;
tmpL->data[1] = operTok;
tmpL->data[2] = l->data[2];
tmpL = prePross(tmpL,LINE_TYPE_VAR,elems);
operT.cont = "=";

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] = operT;
nl->length = nLength+1;
} else {
nl->data[len(nl)] = operT;
}
};
register long int j = 0;
for (; (j<len(tmpL)); j++) {

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] = tmpL->data[j];
nl->length = nLength+1;
} else {
nl->data[len(nl)] = tmpL->data[j];
}
};
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
sct.replace(&sct," ","");
v->type = sct.str(&sct);
}
isEqual = true;
i = i+1;
continue;
}
}
if ((isEqual==false)) {
char * ____BAH_COMPILER_VAR_420 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(currentType);
long int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_420 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_420+currStrOff, currentType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_420+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }currentType = ____BAH_COMPILER_VAR_420;
}
else {
if ((t.isEqual==true)&&(exists==false)&&(isGlobal()==false)) {
needsDefine = true;
}
if ((strcmp(t.cont, "chan") == 0)) {
if ((i>=len(l))) {
throwErr(&t,"Cannot declare a {TOKEN} without a type (chan <type>).");
}
i++;
struct Tok nt = l->data[i];
char * ____BAH_COMPILER_VAR_421 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("chan:");
long int strLen_1 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_421 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_421+currStrOff, "chan:", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_421+currStrOff, nt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }v->type = ____BAH_COMPILER_VAR_421;
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
i++;
struct Tok nt = l->data[i];
char * ____BAH_COMPILER_VAR_422 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("map:");
long int strLen_1 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_422 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_422+currStrOff, "map:", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_422+currStrOff, nt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }v->type = ____BAH_COMPILER_VAR_422;
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
i++;
struct Tok nt = l->data[i];
if ((nt.type!=TOKEN_TYPE_INT)) {
throwErr(&nt,"Expected buffer length, not {TOKEN}.");
}
char * ____BAH_COMPILER_VAR_423 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("buffer:");
long int strLen_1 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_423 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_423+currStrOff, "buffer:", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_423+currStrOff, nt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }v->type = ____BAH_COMPILER_VAR_423;
struct variable* ____BAH_COMPILER_VAR_424 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_424->name = "";
____BAH_COMPILER_VAR_424->type = "";
____BAH_COMPILER_VAR_424->isConst = false;
____BAH_COMPILER_VAR_424->constVal = "";
____BAH_COMPILER_VAR_424->isArray = false;
____BAH_COMPILER_VAR_424->from = "";
____BAH_COMPILER_VAR_424->declScope= null;
____BAH_COMPILER_VAR_424->isGlobal = false;
____BAH_COMPILER_VAR_424->declRope= null;
____BAH_COMPILER_VAR_424->isReg = false;
struct variable* av = ____BAH_COMPILER_VAR_424;
av->type = "char*";
av->name = genCompilerVar();

{
long nLength = len(elems->vars);
if (elems->vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(elems->vars->data, (nLength+50)*sizeof(struct variable*));
elems->vars->data = newPtr;
}
elems->vars->data[len(elems->vars)] = av;
elems->vars->length = nLength+1;
} else {
elems->vars->data[len(elems->vars)] = av;
}
};
struct string cType = getCType(av->type,elems);
char * ____BAH_COMPILER_VAR_425 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen("];");
long int strLen_2 = strlen("[");
long int strLen_3 = strlen(av->name);
long int strLen_4 = strlen("char ");
;                            
            ____BAH_COMPILER_VAR_425 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_425+currStrOff, "char ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_425+currStrOff, av->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_425+currStrOff, "[", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_425+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_425+currStrOff, "];", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_425));
code = av->name;
if ((i+1!=len(l))) {
struct Tok errT = l->data[i+1];
throwErr(&errT,"{TOKEN} not expected after buffer declaration.");
}
break;
}
char * tp = getTypeFromToken(&t,true,elems);
if ((exists==true)) {
if ((compTypes(tp,v->type)==false)) {
char * ____BAH_COMPILER_VAR_426 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(v->type);
long int strLen_1 = strlen(".");
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(tp);
long int strLen_4 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_426 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_426+currStrOff, "Cannot use {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_426+currStrOff, tp, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_426+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_426+currStrOff, v->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_426+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&t,____BAH_COMPILER_VAR_426);
}
}
else {
if ((strcmp(currentType, "") == 0)) {
if ((strcmp(v->type, "") == 0)) {
v->type = tp;
}
else {
if ((compTypes(tp,v->type)==false)) {
char * ____BAH_COMPILER_VAR_427 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(v->type);
long int strLen_1 = strlen(".");
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(tp);
long int strLen_4 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_427 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_427+currStrOff, "Cannot use {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_427+currStrOff, tp, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_427+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_427+currStrOff, v->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_427+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&t,____BAH_COMPILER_VAR_427);
}
}
}
}
if ((strcmp(t.cont, "") != 0)&&(strHasPrefix(t.cont,"{")==false)) {
char * ____BAH_COMPILER_VAR_428 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_428 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_428+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_428+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_428;
if ((t.isOper==false)&&(RCPavailable()==true)) {
struct variable* iv = searchVar(t.cont,elems);
if ((iv!=null)&&(iv->isConst==false)) {
toVar = true;
isPointedVar = strHasPrefix(t.cont,"&");
struct cStruct* s = searchStruct(iv->type,elems);
if ((s!=null)&&(strCount(iv->type,"*")==0)&&(s->isBinding==false)) {
if ((strCount(iv->name,"*")==0)) {
char * ____BAH_COMPILER_VAR_429 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(iv->name);
long int strLen_1 = strlen("), 0)");
long int strLen_2 = strlen(", sizeof(");
long int strLen_3 = strlen(iv->name);
long int strLen_4 = strlen("; RCP_scanStack(&");
long int strLen_5 = strlen(code);
;                            
            ____BAH_COMPILER_VAR_429 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_429+currStrOff, code, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_429+currStrOff, "; RCP_scanStack(&", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_429+currStrOff, iv->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_429+currStrOff, ", sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_429+currStrOff, iv->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_429+currStrOff, "), 0)", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_429;
}
else {
struct string ivn = string(iv->name);
if ((ivn.count(&ivn,"*")>0)) {
ivn.replace(&ivn,"*","");
char * ____BAH_COMPILER_VAR_430 =null;char * ____BAH_COMPILER_VAR_431 =ivn.str(&ivn);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(iv->name);
long int strLen_1 = strlen("), 0)");
long int strLen_2 = strlen(", sizeof(");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_431);
long int strLen_4 = strlen("; RCP_scanStack(");
;                            
            ____BAH_COMPILER_VAR_430 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_430+currStrOff, "; RCP_scanStack(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_430+currStrOff, ____BAH_COMPILER_VAR_431, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_430+currStrOff, ", sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_430+currStrOff, iv->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_430+currStrOff, "), 0)", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_432 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_430);
;                            
            ____BAH_COMPILER_VAR_432 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_432+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_432+currStrOff, ____BAH_COMPILER_VAR_430, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_432;
}
else {
char * ____BAH_COMPILER_VAR_433 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(iv->name);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen("; RCP_incr(");
long int strLen_3 = strlen(code);
;                            
            ____BAH_COMPILER_VAR_433 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_433+currStrOff, code, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_433+currStrOff, "; RCP_incr(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_433+currStrOff, iv->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_433+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_433;
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
char * ____BAH_COMPILER_VAR_434 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_434 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_434+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_434+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_434;
}
i++;
};
if ((exists==true)) {
if ((strlen(code)==0)) {
throwErr(&ft,"Cannot re-declare {TOKEN}.");
}
if ((strlen(currentType)>0)) {
struct Tok st = l->data[1];
char * ____BAH_COMPILER_VAR_435 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ft.cont);
long int strLen_1 = strlen("' to {TOKEN}.");
long int strLen_2 = strlen("Cannot change the type of already declared var '");
;                            
            ____BAH_COMPILER_VAR_435 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_435+currStrOff, "Cannot change the type of already declared var '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_435+currStrOff, ft.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_435+currStrOff, "' to {TOKEN}.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&st,____BAH_COMPILER_VAR_435);
}
char * preCode = "";
if ((isStruct==false)) {
if (isRCPpointerType(v->type)&&(isPointedVar==false)&&(RCPavailable()==true)) {
struct string cType = getCType(v->type,elems);
if ((toVar==true)) {
if ((RCPselfRef(v)==false)) {
char * ____BAH_COMPILER_VAR_436 =null;char * ____BAH_COMPILER_VAR_437 =cType.str(&cType);char * ____BAH_COMPILER_VAR_438 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen("*)RCP_incrIL(&");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_437);
long int strLen_4 = strlen(") = *(");
long int strLen_5 = strlen(v->name);
long int strLen_6 = strlen("*)RCP_decrIL(&");
long int strLen_7 = strlen(____BAH_COMPILER_VAR_438);
long int strLen_8 = strlen("*(");
;                            
            ____BAH_COMPILER_VAR_436 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_436+currStrOff, "*(", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_436+currStrOff, ____BAH_COMPILER_VAR_438, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_436+currStrOff, "*)RCP_decrIL(&", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_436+currStrOff, v->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_436+currStrOff, ") = *(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_436+currStrOff, ____BAH_COMPILER_VAR_437, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_436+currStrOff, "*)RCP_incrIL(&", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_436+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_436+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_436;
}
else {
struct variable* ____BAH_COMPILER_VAR_439 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_439->name = "";
____BAH_COMPILER_VAR_439->type = "";
____BAH_COMPILER_VAR_439->isConst = false;
____BAH_COMPILER_VAR_439->constVal = "";
____BAH_COMPILER_VAR_439->isArray = false;
____BAH_COMPILER_VAR_439->from = "";
____BAH_COMPILER_VAR_439->declScope= null;
____BAH_COMPILER_VAR_439->isGlobal = false;
____BAH_COMPILER_VAR_439->declRope= null;
____BAH_COMPILER_VAR_439->isReg = false;
struct variable* tmpV = ____BAH_COMPILER_VAR_439;
tmpV->name = genCompilerVar();
tmpV->type = v->type;
struct rope* dv = decrVar(tmpV,elems);
char * ____BAH_COMPILER_VAR_440 =null;char * ____BAH_COMPILER_VAR_441 =dv->toStr(dv);char * ____BAH_COMPILER_VAR_442 =cType.str(&cType);char * ____BAH_COMPILER_VAR_443 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(");");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_441);
long int strLen_2 = strlen(code);
long int strLen_3 = strlen("*)RCP_incrIL(&");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_442);
long int strLen_5 = strlen(" = *(");
long int strLen_6 = strlen(v->name);
long int strLen_7 = strlen("; ");
long int strLen_8 = strlen(v->name);
long int strLen_9 = strlen(" = ");
long int strLen_10 = strlen(tmpV->name);
long int strLen_11 = strlen(" ");
long int strLen_12 = strlen(____BAH_COMPILER_VAR_443);
;                            
            ____BAH_COMPILER_VAR_440 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12);
            
                    memcpy(____BAH_COMPILER_VAR_440+currStrOff, ____BAH_COMPILER_VAR_443, strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_440+currStrOff, " ", strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_440+currStrOff, tmpV->name, strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_440+currStrOff, " = ", strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_440+currStrOff, v->name, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_440+currStrOff, "; ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_440+currStrOff, v->name, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_440+currStrOff, " = *(", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_440+currStrOff, ____BAH_COMPILER_VAR_442, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_440+currStrOff, "*)RCP_incrIL(&", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_440+currStrOff, code, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_440+currStrOff, ");", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_440+currStrOff, ____BAH_COMPILER_VAR_441, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_440;
}
}
else {
struct variable* ____BAH_COMPILER_VAR_444 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_444->name = "";
____BAH_COMPILER_VAR_444->type = "";
____BAH_COMPILER_VAR_444->isConst = false;
____BAH_COMPILER_VAR_444->constVal = "";
____BAH_COMPILER_VAR_444->isArray = false;
____BAH_COMPILER_VAR_444->from = "";
____BAH_COMPILER_VAR_444->declScope= null;
____BAH_COMPILER_VAR_444->isGlobal = false;
____BAH_COMPILER_VAR_444->declRope= null;
____BAH_COMPILER_VAR_444->isReg = false;
struct variable* tmpV = ____BAH_COMPILER_VAR_444;
tmpV->name = genCompilerVar();
tmpV->type = v->type;
struct rope* dv = decrVar(tmpV,elems);
char * ____BAH_COMPILER_VAR_445 =null;char * ____BAH_COMPILER_VAR_446 =dv->toStr(dv);char * ____BAH_COMPILER_VAR_447 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(";");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_446);
long int strLen_2 = strlen(code);
long int strLen_3 = strlen(" = ");
long int strLen_4 = strlen(v->name);
long int strLen_5 = strlen("; ");
long int strLen_6 = strlen(v->name);
long int strLen_7 = strlen(" = ");
long int strLen_8 = strlen(tmpV->name);
long int strLen_9 = strlen(" ");
long int strLen_10 = strlen(____BAH_COMPILER_VAR_447);
;                            
            ____BAH_COMPILER_VAR_445 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10);
            
                    memcpy(____BAH_COMPILER_VAR_445+currStrOff, ____BAH_COMPILER_VAR_447, strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_445+currStrOff, " ", strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_445+currStrOff, tmpV->name, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_445+currStrOff, " = ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_445+currStrOff, v->name, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_445+currStrOff, "; ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_445+currStrOff, v->name, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_445+currStrOff, " = ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_445+currStrOff, code, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_445+currStrOff, ";", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_445+currStrOff, ____BAH_COMPILER_VAR_446, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_445;
}
}
else {
struct cStruct* s = searchStruct(v->type,elems);
if ((s!=null)&&(RCPavailable()==true)&&(RCPselfRef(v)==false)&&(s->isBinding==false)) {
if ((strCount(v->name,"*")==0)) {
char * ____BAH_COMPILER_VAR_448 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen("), 1); ");
long int strLen_2 = strlen(", sizeof(");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen("RCP_scanStack(&");
;                            
            ____BAH_COMPILER_VAR_448 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_448+currStrOff, "RCP_scanStack(&", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_448+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_448+currStrOff, ", sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_448+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_448+currStrOff, "), 1); ", strLen_1);
            currStrOff += strLen_1;
        
        }preCode = ____BAH_COMPILER_VAR_448;
}
else {
struct string vn = string(v->name);
vn.replace(&vn,"*","");
char * ____BAH_COMPILER_VAR_449 =null;char * ____BAH_COMPILER_VAR_450 =vn.str(&vn);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen("), 1); ");
long int strLen_2 = strlen(", sizeof(");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_450);
long int strLen_4 = strlen("RCP_scanStack(");
;                            
            ____BAH_COMPILER_VAR_449 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_449+currStrOff, "RCP_scanStack(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_449+currStrOff, ____BAH_COMPILER_VAR_450, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_449+currStrOff, ", sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_449+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_449+currStrOff, "), 1); ", strLen_1);
            currStrOff += strLen_1;
        
        }preCode = ____BAH_COMPILER_VAR_449;
}
char * ____BAH_COMPILER_VAR_451 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(" = ");
long int strLen_1 = strlen(code);
long int strLen_2 = strlen(v->name);
;                            
            ____BAH_COMPILER_VAR_451 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_451+currStrOff, v->name, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_451+currStrOff, " = ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_451+currStrOff, code, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_451;
}
else {
char * ____BAH_COMPILER_VAR_452 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(" = ");
long int strLen_1 = strlen(code);
long int strLen_2 = strlen(v->name);
;                            
            ____BAH_COMPILER_VAR_452 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_452+currStrOff, v->name, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_452+currStrOff, " = ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_452+currStrOff, code, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_452;
}
}
}
else {
strTrim(&code);
if ((strHasPrefix(code,"{")==false)) {
char * ____BAH_COMPILER_VAR_453 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(" = ");
long int strLen_1 = strlen(code);
long int strLen_2 = strlen(v->name);
;                            
            ____BAH_COMPILER_VAR_453 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_453+currStrOff, v->name, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_453+currStrOff, " = ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_453+currStrOff, code, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_453;
}
}
if ((v->isArray==true)) {
struct string nLength = string(v->name);
struct string n = string(v->name);
i = 0;
while ((i<nLength.length)) {
char c = nLength.charAt(&nLength,i);
if ((c==91)) {
break;
}
i++;
};
nLength.trimLeft(&nLength,i+1);
nLength.trimRight(&nLength,1);
char * nLengthStr = nLength.str(&nLength);
i = n.length;
while ((i>0)) {
char c = n.charAt(&n,i);
if ((c==91)) {
break;
}
i--;
};
long int tamm = n.length-i;
n.trimRight(&n,tamm+6);
char * nstr = n.str(&n);
struct string elemType = getCType(v->type,elems);
char * elemTypeStr = elemType.str(&elemType);
char * ____BAH_COMPILER_VAR_454 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(";\n}\n}");
long int strLen_2 = strlen(preCode);
long int strLen_3 = strlen("->length = nLength+1;\n} else {\n");
long int strLen_4 = strlen(nstr);
long int strLen_5 = strlen(";\n");
long int strLen_6 = strlen(code);
long int strLen_7 = strlen("->data = newPtr;\n}\n");
long int strLen_8 = strlen(nstr);
long int strLen_9 = strlen("));\n");
long int strLen_10 = strlen(elemTypeStr);
long int strLen_11 = strlen("->data, (nLength+50)*sizeof(");
long int strLen_12 = strlen(nstr);
long int strLen_13 = strlen("->length < nLength+1) {\nif ((nLength+1) % 50 == 0 || nLength == 0) {\nvoid * newPtr = memoryRealloc(");
long int strLen_14 = strlen(nstr);
long int strLen_15 = strlen(";\nif (");
long int strLen_16 = strlen(nLengthStr);
long int strLen_17 = strlen("\n{\nlong nLength = ");
;                            
            ____BAH_COMPILER_VAR_454 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13+strLen_14+strLen_15+strLen_16+strLen_17);
            
                    memcpy(____BAH_COMPILER_VAR_454+currStrOff, "\n{\nlong nLength = ", strLen_17);
                    currStrOff += strLen_17;
                    
                    memcpy(____BAH_COMPILER_VAR_454+currStrOff, nLengthStr, strLen_16);
                    currStrOff += strLen_16;
                    
                    memcpy(____BAH_COMPILER_VAR_454+currStrOff, ";\nif (", strLen_15);
                    currStrOff += strLen_15;
                    
                    memcpy(____BAH_COMPILER_VAR_454+currStrOff, nstr, strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_454+currStrOff, "->length < nLength+1) {\nif ((nLength+1) % 50 == 0 || nLength == 0) {\nvoid * newPtr = memoryRealloc(", strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_454+currStrOff, nstr, strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_454+currStrOff, "->data, (nLength+50)*sizeof(", strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_454+currStrOff, elemTypeStr, strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_454+currStrOff, "));\n", strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_454+currStrOff, nstr, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_454+currStrOff, "->data = newPtr;\n}\n", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_454+currStrOff, code, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_454+currStrOff, ";\n", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_454+currStrOff, nstr, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_454+currStrOff, "->length = nLength+1;\n} else {\n", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_454+currStrOff, preCode, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_454+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_454+currStrOff, ";\n}\n}", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_454;
}
else {
char * ____BAH_COMPILER_VAR_455 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(preCode);
long int strLen_1 = strlen(code);
;                            
            ____BAH_COMPILER_VAR_455 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_455+currStrOff, preCode, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_455+currStrOff, code, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_455;
}
}
else {
if ((strcmp(currentType, "") != 0)) {
v->type = currentType;
}
struct string vts = string(v->type);
vts.replace(&vts," ","");
v->type = vts.str(&vts);
if ((strlen(v->type)==0)) {
throwErr(&ft,"Cannot declare {TOKEN} without a type.");
}
char * vct= null;
if (vts.hasPrefix(&vts,"function(")) {
struct func* tmpfn = parseFnType(vts);
struct string tmpfnRetCType = getCType(tmpfn->returns->type,elems);
char * tmpfnArgsCType = "";
register long int j = 0;
while ((j<len(tmpfn->args))) {
struct variable* arg = tmpfn->args->data[j];
struct string ct = getCType(arg->type,elems);
char * ____BAH_COMPILER_VAR_456 =null;char * ____BAH_COMPILER_VAR_457 =ct.str(&ct);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_457);
;                            
            ____BAH_COMPILER_VAR_456 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_456+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_456+currStrOff, ____BAH_COMPILER_VAR_457, strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_456;
j = j+1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_458 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_458 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_458+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_458+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_458;
}
};
char * ____BAH_COMPILER_VAR_459 =null;char * ____BAH_COMPILER_VAR_460 =tmpfnRetCType.str(&tmpfnRetCType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen(")(");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen(" (*");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_460);
;                            
            ____BAH_COMPILER_VAR_459 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_459+currStrOff, ____BAH_COMPILER_VAR_460, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_459+currStrOff, " (*", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_459+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_459+currStrOff, ")(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_459+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_459+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }vct = ____BAH_COMPILER_VAR_459;
}
else {
vct = setCType(v,elems);
}
if ((strcmp(code, "") != 0)&&(shouldOnlyDecl==false)) {
if (isRCPpointerType(v->type)&&(RCPavailable()==true)&&(toVar==true)&&(isPointedVar==false)) {
struct string cType = getCType(v->type,elems);
if (isGlobal()) {
char * ____BAH_COMPILER_VAR_461 =null;char * ____BAH_COMPILER_VAR_462 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(");\n");
long int strLen_2 = strlen("*)RCP_incrIL(&");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_462);
long int strLen_4 = strlen(" = *(");
long int strLen_5 = strlen(v->name);
;                            
            ____BAH_COMPILER_VAR_461 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_461+currStrOff, v->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_461+currStrOff, " = *(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_461+currStrOff, ____BAH_COMPILER_VAR_462, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_461+currStrOff, "*)RCP_incrIL(&", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_461+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_461+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }INIT = INIT->add(INIT, rope(____BAH_COMPILER_VAR_461));
}
else {
char * ____BAH_COMPILER_VAR_463 =null;char * ____BAH_COMPILER_VAR_464 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen("*)RCP_incrIL(&");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_464);
long int strLen_4 = strlen(" = *(");
long int strLen_5 = strlen(vct);
;                            
            ____BAH_COMPILER_VAR_463 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_463+currStrOff, vct, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_463+currStrOff, " = *(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_463+currStrOff, ____BAH_COMPILER_VAR_464, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_463+currStrOff, "*)RCP_incrIL(&", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_463+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_463+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_463;
}
}
else {
if ((needsDefine==true)) {

{
long nLength = len(elems->defined);
if (elems->defined->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(elems->defined->data, (nLength+50)*sizeof(char *));
elems->defined->data = newPtr;
}
elems->defined->data[len(elems->defined)] = v->name;
elems->defined->length = nLength+1;
} else {
elems->defined->data[len(elems->defined)] = v->name;
}
};
if (isGlobal()) {
char * ____BAH_COMPILER_VAR_465 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen("\n");
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen("#define ");
;                            
            ____BAH_COMPILER_VAR_465 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_465+currStrOff, "#define ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_465+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_465+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_465+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_465+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }INIT = INIT->add(INIT, rope(____BAH_COMPILER_VAR_465));
}
else {
char * ____BAH_COMPILER_VAR_466 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(" ");
long int strLen_1 = strlen(code);
long int strLen_2 = strlen(v->name);
long int strLen_3 = strlen("#define ");
;                            
            ____BAH_COMPILER_VAR_466 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_466+currStrOff, "#define ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_466+currStrOff, v->name, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_466+currStrOff, " ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_466+currStrOff, code, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_466;
}
}
else {
if (isGlobal()) {
char * ____BAH_COMPILER_VAR_467 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen(" = ");
long int strLen_3 = strlen(v->name);
;                            
            ____BAH_COMPILER_VAR_467 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_467+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_467+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_467+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_467+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }INIT = INIT->add(INIT, rope(____BAH_COMPILER_VAR_467));
}
else {
char * ____BAH_COMPILER_VAR_468 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(" = ");
long int strLen_1 = strlen(code);
long int strLen_2 = strlen(vct);
;                            
            ____BAH_COMPILER_VAR_468 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_468+currStrOff, vct, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_468+currStrOff, " = ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_468+currStrOff, code, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_468;
}
}
}
}
else {
if (isRCPpointerType(v->type)&&(shouldOnlyDecl==false)) {
char * ____BAH_COMPILER_VAR_469 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(vct);
long int strLen_1 = strlen("= null");
;                            
            ____BAH_COMPILER_VAR_469 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_469+currStrOff, vct, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_469+currStrOff, "= null", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_469;
}
else {
code = vct;
}
}
if ((shouldOnlyDecl==true)) {
char * ____BAH_COMPILER_VAR_470 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("extern ");
long int strLen_1 = strlen(vct);
;                            
            ____BAH_COMPILER_VAR_470 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_470+currStrOff, "extern ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_470+currStrOff, vct, strLen_1);
            currStrOff += strLen_1;
        
        }vct = ____BAH_COMPILER_VAR_470;
}
if (isGlobal()) {
v->isGlobal = true;
}
else {
v->isGlobal = false;
}
v->declScope = elems;

{
long nLength = len(elems->vars);
if (elems->vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(elems->vars->data, (nLength+50)*sizeof(struct variable*));
elems->vars->data = newPtr;
}
elems->vars->data[len(elems->vars)] = v;
elems->vars->length = nLength+1;
} else {
elems->vars->data[len(elems->vars)] = v;
}
};
struct variable* ____BAH_COMPILER_VAR_471 = v;
char ** ____BAH_COMPILER_VAR_473 = (char **)((char*)(____BAH_COMPILER_VAR_471) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_474 = __reflect(____BAH_COMPILER_VAR_473, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_475 = (char **)((char*)(____BAH_COMPILER_VAR_471) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_476 = __reflect(____BAH_COMPILER_VAR_475, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_477 = (char*)((char*)(____BAH_COMPILER_VAR_471) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_478 = __reflect(____BAH_COMPILER_VAR_477, sizeof(char), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_479 = (char **)((char*)(____BAH_COMPILER_VAR_471) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_480 = __reflect(____BAH_COMPILER_VAR_479, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_481 = (char*)((char*)(____BAH_COMPILER_VAR_471) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_482 = __reflect(____BAH_COMPILER_VAR_481, sizeof(char), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_483 = (char **)((char*)(____BAH_COMPILER_VAR_471) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_484 = __reflect(____BAH_COMPILER_VAR_483, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
void ** ____BAH_COMPILER_VAR_485 = (void **)((char*)(____BAH_COMPILER_VAR_471) + offsetof(struct variable, declScope));
struct reflectElement ____BAH_COMPILER_VAR_486 = __reflect(____BAH_COMPILER_VAR_485, sizeof(void *), "ptr", "declScope", 0, 0, 0, 0, offsetof(struct variable, declScope));
char* ____BAH_COMPILER_VAR_487 = (char*)((char*)(____BAH_COMPILER_VAR_471) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_488 = __reflect(____BAH_COMPILER_VAR_487, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));
struct rope** ____BAH_COMPILER_VAR_489 = (struct rope**)((char*)(____BAH_COMPILER_VAR_471) + offsetof(struct variable, declRope));
void ** ____BAH_COMPILER_VAR_491 = (void **)((char*)(____BAH_COMPILER_VAR_489) + offsetof(struct rope, left));
struct reflectElement ____BAH_COMPILER_VAR_492 = __reflect(____BAH_COMPILER_VAR_491, sizeof(void *), "ptr", "left", 0, 0, 0, 0, offsetof(struct rope, left));
void ** ____BAH_COMPILER_VAR_493 = (void **)((char*)(____BAH_COMPILER_VAR_489) + offsetof(struct rope, right));
struct reflectElement ____BAH_COMPILER_VAR_494 = __reflect(____BAH_COMPILER_VAR_493, sizeof(void *), "ptr", "right", 0, 0, 0, 0, offsetof(struct rope, right));
char ** ____BAH_COMPILER_VAR_495 = (char **)((char*)(____BAH_COMPILER_VAR_489) + offsetof(struct rope, str));
struct reflectElement ____BAH_COMPILER_VAR_496 = __reflect(____BAH_COMPILER_VAR_495, sizeof(char *), "cpstring", "str", 0, 0, 0, 0, offsetof(struct rope, str));
long int* ____BAH_COMPILER_VAR_497 = (long int*)((char*)(____BAH_COMPILER_VAR_489) + offsetof(struct rope, lCount));
struct reflectElement ____BAH_COMPILER_VAR_498 = __reflect(____BAH_COMPILER_VAR_497, sizeof(long int), "int", "lCount", 0, 0, 0, 0, offsetof(struct rope, lCount));
long int* ____BAH_COMPILER_VAR_499 = (long int*)((char*)(____BAH_COMPILER_VAR_489) + offsetof(struct rope, len));
struct reflectElement ____BAH_COMPILER_VAR_500 = __reflect(____BAH_COMPILER_VAR_499, sizeof(long int), "int", "len", 0, 0, 0, 0, offsetof(struct rope, len));
long int* ____BAH_COMPILER_VAR_501 = (long int*)((char*)(____BAH_COMPILER_VAR_489) + offsetof(struct rope, totalLen));
struct reflectElement ____BAH_COMPILER_VAR_502 = __reflect(____BAH_COMPILER_VAR_501, sizeof(long int), "int", "totalLen", 0, 0, 0, 0, offsetof(struct rope, totalLen));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_490 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_490->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_490->length = 6;
        ____BAH_COMPILER_VAR_490->data = memoryAlloc(____BAH_COMPILER_VAR_490->length * ____BAH_COMPILER_VAR_490->elemSize);
        ____BAH_COMPILER_VAR_490->data[0] = ____BAH_COMPILER_VAR_492;
____BAH_COMPILER_VAR_490->data[1] = ____BAH_COMPILER_VAR_494;
____BAH_COMPILER_VAR_490->data[2] = ____BAH_COMPILER_VAR_496;
____BAH_COMPILER_VAR_490->data[3] = ____BAH_COMPILER_VAR_498;
____BAH_COMPILER_VAR_490->data[4] = ____BAH_COMPILER_VAR_500;
____BAH_COMPILER_VAR_490->data[5] = ____BAH_COMPILER_VAR_502;
struct reflectElement ____BAH_COMPILER_VAR_503 = __reflect(____BAH_COMPILER_VAR_489, sizeof(struct rope), "rope*", "declRope", 0, 0, 1, ____BAH_COMPILER_VAR_490, offsetof(struct variable, declRope));
char* ____BAH_COMPILER_VAR_504 = (char*)((char*)(____BAH_COMPILER_VAR_471) + offsetof(struct variable, canBeReg));
struct reflectElement ____BAH_COMPILER_VAR_505 = __reflect(____BAH_COMPILER_VAR_504, sizeof(char), "bool", "canBeReg", 0, 0, 0, 0, offsetof(struct variable, canBeReg));
char* ____BAH_COMPILER_VAR_506 = (char*)((char*)(____BAH_COMPILER_VAR_471) + offsetof(struct variable, isReg));
struct reflectElement ____BAH_COMPILER_VAR_507 = __reflect(____BAH_COMPILER_VAR_506, sizeof(char), "bool", "isReg", 0, 0, 0, 0, offsetof(struct variable, isReg));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_472 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_472->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_472->length = 11;
        ____BAH_COMPILER_VAR_472->data = memoryAlloc(____BAH_COMPILER_VAR_472->length * ____BAH_COMPILER_VAR_472->elemSize);
        ____BAH_COMPILER_VAR_472->data[0] = ____BAH_COMPILER_VAR_474;
____BAH_COMPILER_VAR_472->data[1] = ____BAH_COMPILER_VAR_476;
____BAH_COMPILER_VAR_472->data[2] = ____BAH_COMPILER_VAR_478;
____BAH_COMPILER_VAR_472->data[3] = ____BAH_COMPILER_VAR_480;
____BAH_COMPILER_VAR_472->data[4] = ____BAH_COMPILER_VAR_482;
____BAH_COMPILER_VAR_472->data[5] = ____BAH_COMPILER_VAR_484;
____BAH_COMPILER_VAR_472->data[6] = ____BAH_COMPILER_VAR_486;
____BAH_COMPILER_VAR_472->data[7] = ____BAH_COMPILER_VAR_488;
____BAH_COMPILER_VAR_472->data[8] = ____BAH_COMPILER_VAR_503;
____BAH_COMPILER_VAR_472->data[9] = ____BAH_COMPILER_VAR_505;
____BAH_COMPILER_VAR_472->data[10] = ____BAH_COMPILER_VAR_507;
struct reflectElement ____BAH_COMPILER_VAR_508 = __reflect(____BAH_COMPILER_VAR_471, sizeof(struct variable), "variable*", "v", 0, 0, 1, ____BAH_COMPILER_VAR_472, 0);
debugPrint("var_declaration",ft.line,____BAH_COMPILER_VAR_508);
if (isGlobal()) {
char * ____BAH_COMPILER_VAR_509 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(vct);
long int strLen_1 = strlen(";\n");
;                            
            ____BAH_COMPILER_VAR_509 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_509+currStrOff, vct, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_509+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_509));
}
}
if (isGlobal()) {
if ((isSubObject==false)) {
INIT = INIT->add(INIT, rope(NEXT_LINE));
}
NEXT_LINE = "";
}
else {
if ((needsDefine==true)) {
char * ____BAH_COMPILER_VAR_510 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen("\n");
;                            
            ____BAH_COMPILER_VAR_510 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_510+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_510+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_510));
}
else {
char * ____BAH_COMPILER_VAR_511 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(";\n");
;                            
            ____BAH_COMPILER_VAR_511 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_511+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_511+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }struct rope* declR = rope(____BAH_COMPILER_VAR_511);
if ((exists==false)) {
v->declRope = declR;
v->canBeReg = true;
}
OUTPUT = OUTPUT->add(OUTPUT, declR);
}
}
};
char * getCfunctionType(struct string cfrt,char * elemName,struct Elems* elems){
struct func* tmpfn = parseFnType(cfrt);
struct string tmpfnRetCType = getCType(tmpfn->returns->type,elems);
char * tmpfnArgsCType = "";
register long int j = 0;
while ((j<len(tmpfn->args))) {
struct variable* arg = tmpfn->args->data[j];
struct string ct = getCType(arg->type,elems);
char * ____BAH_COMPILER_VAR_512 =null;char * ____BAH_COMPILER_VAR_513 =ct.str(&ct);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_513);
;                            
            ____BAH_COMPILER_VAR_512 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_512+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_512+currStrOff, ____BAH_COMPILER_VAR_513, strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_512;
j = j+1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_514 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_514 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_514+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_514+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_514;
}
};
char * ____BAH_COMPILER_VAR_515 =null;char * ____BAH_COMPILER_VAR_516 =tmpfnRetCType.str(&tmpfnRetCType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen(")(");
long int strLen_3 = strlen(elemName);
long int strLen_4 = strlen(" (*");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_516);
;                            
            ____BAH_COMPILER_VAR_515 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_515+currStrOff, ____BAH_COMPILER_VAR_516, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_515+currStrOff, " (*", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_515+currStrOff, elemName, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_515+currStrOff, ")(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_515+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_515+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }return ____BAH_COMPILER_VAR_515;
};
char * parseFnHeader(char * prev,__BAH_ARR_TYPE_Tok l,long int* i,struct func* fn,struct Elems* elems){
register long int j = *i;
struct Tok ft = l->data[j];
char * tpdf = "";
if ((ft.type!=TOKEN_TYPE_VAR)) {
throwErr(&ft,"Cannot use {TOKEN} as function name.");
}
char * ____BAH_COMPILER_VAR_517 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(prev);
long int strLen_1 = strlen(ft.cont);
;                            
            ____BAH_COMPILER_VAR_517 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_517+currStrOff, prev, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_517+currStrOff, ft.cont, strLen_1);
            currStrOff += strLen_1;
        
        }fn->name = ____BAH_COMPILER_VAR_517;
array(struct variable*)* arguments = memoryAlloc(sizeof(array(struct variable*)));

arguments->length = 0;
arguments->elemSize = sizeof(struct variable*);
char * ____BAH_COMPILER_VAR_518 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fn->name);
long int strLen_1 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_518 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_518+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_518+currStrOff, "(", strLen_1);
            currStrOff += strLen_1;
        
        }char * code = ____BAH_COMPILER_VAR_518;
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
char * ____BAH_COMPILER_VAR_519 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(argType);
long int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_519 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_519+currStrOff, argType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_519+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }argType = ____BAH_COMPILER_VAR_519;
}
}
else {
isComa = true;
break;
}
j = j+1;
};
struct variable* ____BAH_COMPILER_VAR_520 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_520->name = "";
____BAH_COMPILER_VAR_520->type = "";
____BAH_COMPILER_VAR_520->isConst = false;
____BAH_COMPILER_VAR_520->constVal = "";
____BAH_COMPILER_VAR_520->isArray = false;
____BAH_COMPILER_VAR_520->from = "";
____BAH_COMPILER_VAR_520->declScope= null;
____BAH_COMPILER_VAR_520->isGlobal = false;
____BAH_COMPILER_VAR_520->declRope= null;
____BAH_COMPILER_VAR_520->isReg = false;
struct variable* argument = ____BAH_COMPILER_VAR_520;
argument->name = argName;
argument->type = argType;

{
long nLength = len(arguments);
if (arguments->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(arguments->data, (nLength+50)*sizeof(struct variable*));
arguments->data = newPtr;
}
arguments->data[len(arguments)] = argument;
arguments->length = nLength+1;
} else {
arguments->data[len(arguments)] = argument;
}
};
struct string argCType = getCType(argType,elems);
struct string cfrt = string(argType);
char * newArgType = argCType.str(&argCType);
if ((cfrt.hasPrefix(&cfrt,"[]")==1)) {
cfrt.trimLeft(&cfrt,2);
if (cfrt.hasSuffix(&cfrt,"*")) {
long int nbast = cfrt.count(&cfrt,"*");
cfrt.trimRight(&cfrt,nbast);
}
char * ____BAH_COMPILER_VAR_521 =null;char * ____BAH_COMPILER_VAR_522 =cfrt.str(&cfrt);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("__BAH_ARR_TYPE_");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_522);
;                            
            ____BAH_COMPILER_VAR_521 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_521+currStrOff, "__BAH_ARR_TYPE_", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_521+currStrOff, ____BAH_COMPILER_VAR_522, strLen_1);
            currStrOff += strLen_1;
        
        }newArgType = ____BAH_COMPILER_VAR_521;
array(char *)* csatd = compilerState.arrTypesDecl;
if ((inArrayStr(newArgType,csatd)==false)) {

{
long nLength = len(csatd);
if (csatd->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(csatd->data, (nLength+50)*sizeof(char *));
csatd->data = newPtr;
}
csatd->data[len(csatd)] = newArgType;
csatd->length = nLength+1;
} else {
csatd->data[len(csatd)] = newArgType;
}
};
char * ____BAH_COMPILER_VAR_523 =null;char * ____BAH_COMPILER_VAR_524 =argCType.str(&argCType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(newArgType);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_524);
long int strLen_4 = strlen("typedef ");
long int strLen_5 = strlen(tpdf);
;                            
            ____BAH_COMPILER_VAR_523 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_523+currStrOff, tpdf, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_523+currStrOff, "typedef ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_523+currStrOff, ____BAH_COMPILER_VAR_524, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_523+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_523+currStrOff, newArgType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_523+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }tpdf = ____BAH_COMPILER_VAR_523;
}
}
if ((cfrt.hasPrefix(&cfrt,"function(")==1)) {
char * ____BAH_COMPILER_VAR_525 =null;char * ____BAH_COMPILER_VAR_526 =getCfunctionType(cfrt,argName,elems);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_526);
;                            
            ____BAH_COMPILER_VAR_525 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_525+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_525+currStrOff, ____BAH_COMPILER_VAR_526, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_525;
}
else {
char * ____BAH_COMPILER_VAR_527 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(" ");
long int strLen_1 = strlen(argName);
long int strLen_2 = strlen(newArgType);
long int strLen_3 = strlen(code);
;                            
            ____BAH_COMPILER_VAR_527 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_527+currStrOff, code, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_527+currStrOff, newArgType, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_527+currStrOff, " ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_527+currStrOff, argName, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_527;
}
if ((isComa==true)) {
char * ____BAH_COMPILER_VAR_528 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_528 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_528+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_528+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_528;
}
else {
char * ____BAH_COMPILER_VAR_529 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(")");
;                            
            ____BAH_COMPILER_VAR_529 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_529+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_529+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_529;
break;
}
j = j+1;
};
}
else {
char * ____BAH_COMPILER_VAR_530 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(")");
;                            
            ____BAH_COMPILER_VAR_530 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_530+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_530+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_530;
}
j = j+1;
struct variable* ____BAH_COMPILER_VAR_531 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_531->name = "";
____BAH_COMPILER_VAR_531->type = "";
____BAH_COMPILER_VAR_531->isConst = false;
____BAH_COMPILER_VAR_531->constVal = "";
____BAH_COMPILER_VAR_531->isArray = false;
____BAH_COMPILER_VAR_531->from = "";
____BAH_COMPILER_VAR_531->declScope= null;
____BAH_COMPILER_VAR_531->isGlobal = false;
____BAH_COMPILER_VAR_531->declRope= null;
____BAH_COMPILER_VAR_531->isReg = false;
struct variable* returns = ____BAH_COMPILER_VAR_531;
returns->type = "";
while ((j<len(l))) {
t = l->data[j];
if ((strcmp(t.cont, "{") == 0)) {
break;
}
char * ____BAH_COMPILER_VAR_532 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(returns->type);
long int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_532 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_532+currStrOff, returns->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_532+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }returns->type = ____BAH_COMPILER_VAR_532;
j = j+1;
};
if (strlen(returns->type)) {
struct string rts = string(returns->type);
rts.replace(&rts," ","");
returns->type = rts.content;
}
*i = j;
returns->name = fn->name;
fn->returns = returns;
fn->args = arguments;
struct string fnRetType = getCType(returns->type,elems);
char * newFnRetType = fnRetType.str(&fnRetType);
struct string cfrt = string(returns->type);
if ((cfrt.hasPrefix(&cfrt,"[]")==1)) {
cfrt.trimLeft(&cfrt,2);
if (cfrt.hasSuffix(&cfrt,"*")) {
long int nbast = cfrt.count(&cfrt,"*");
cfrt.trimRight(&cfrt,nbast);
}
char * ____BAH_COMPILER_VAR_533 =null;char * ____BAH_COMPILER_VAR_534 =cfrt.str(&cfrt);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("__BAH_ARR_TYPE_");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_534);
;                            
            ____BAH_COMPILER_VAR_533 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_533+currStrOff, "__BAH_ARR_TYPE_", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_533+currStrOff, ____BAH_COMPILER_VAR_534, strLen_1);
            currStrOff += strLen_1;
        
        }newFnRetType = ____BAH_COMPILER_VAR_533;
array(char *)* csatd = compilerState.arrTypesDecl;
if ((inArrayStr(newFnRetType,csatd)==false)) {

{
long nLength = len(csatd);
if (csatd->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(csatd->data, (nLength+50)*sizeof(char *));
csatd->data = newPtr;
}
csatd->data[len(csatd)] = newFnRetType;
csatd->length = nLength+1;
} else {
csatd->data[len(csatd)] = newFnRetType;
}
};
char * ____BAH_COMPILER_VAR_535 =null;char * ____BAH_COMPILER_VAR_536 =fnRetType.str(&fnRetType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(newFnRetType);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_536);
long int strLen_4 = strlen("typedef ");
long int strLen_5 = strlen(tpdf);
;                            
            ____BAH_COMPILER_VAR_535 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_535+currStrOff, tpdf, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_535+currStrOff, "typedef ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_535+currStrOff, ____BAH_COMPILER_VAR_536, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_535+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_535+currStrOff, newFnRetType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_535+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }tpdf = ____BAH_COMPILER_VAR_535;
}
}
char * ____BAH_COMPILER_VAR_537 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(" ");
long int strLen_1 = strlen(code);
long int strLen_2 = strlen(newFnRetType);
long int strLen_3 = strlen(tpdf);
;                            
            ____BAH_COMPILER_VAR_537 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_537+currStrOff, tpdf, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_537+currStrOff, newFnRetType, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_537+currStrOff, " ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_537+currStrOff, code, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_537;
return code;
};
void parseStruct(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
struct cStruct* ____BAH_COMPILER_VAR_538 = memoryAlloc(sizeof(struct cStruct));
____BAH_COMPILER_VAR_538->name = "";
____BAH_COMPILER_VAR_538->members = memoryAlloc(sizeof(array(struct structMemb*)));
            ____BAH_COMPILER_VAR_538->members->length = 0;
            ____BAH_COMPILER_VAR_538->members->elemSize = sizeof(struct structMemb*);
            ____BAH_COMPILER_VAR_538->methods = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_538->methods->length = 0;
            ____BAH_COMPILER_VAR_538->methods->elemSize = sizeof(struct func*);
            ____BAH_COMPILER_VAR_538->postCode = "";
____BAH_COMPILER_VAR_538->extendedFrom = "";
____BAH_COMPILER_VAR_538->isBinding = false;
____BAH_COMPILER_VAR_538->hasRCPmemb = false;
struct cStruct* s = ____BAH_COMPILER_VAR_538;
array(struct cStruct*)* structs = elems->structs;

{
long nLength = len(structs);
if (structs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(structs->data, (nLength+50)*sizeof(struct cStruct*));
structs->data = newPtr;
}
structs->data[len(structs)] = s;
structs->length = nLength+1;
} else {
structs->data[len(structs)] = s;
}
};
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
i++;
struct Tok extdSNameTk = l->data[i];
i++;
if ((extdSNameTk.type!=TOKEN_TYPE_VAR)) {
throwErr(&extdSNameTk,"Cannot use {TOKEN} as struct name.");
}
struct cStruct* extdS = searchStruct(extdSNameTk.cont,elems);
s->extendedFrom = extdS->name;
if ((extdS==null)) {
throwErr(&extdSNameTk,"Struct {TOKEN} does not exist.");
}
array(struct structMemb*)* extdsmbs = extdS->members;
register long int j = 0;
while ((j<len(extdsmbs))) {
struct structMemb* em = extdsmbs->data[j];
struct string cemt = string(em->type);
char * membDeclStr= null;
if ((cemt.hasPrefix(&cemt,"function(")==1)) {
struct func* tmpfn = parseFnType(cemt);
struct string tmpfnRetCType = getCType(tmpfn->returns->type,elems);
char * tmpfnArgsCType = "";
j = 0;
while ((j<len(tmpfn->args))) {
struct variable* arg = tmpfn->args->data[j];
struct string ct = getCType(arg->type,elems);
char * ____BAH_COMPILER_VAR_539 =null;char * ____BAH_COMPILER_VAR_540 =ct.str(&ct);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_540);
;                            
            ____BAH_COMPILER_VAR_539 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_539+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_539+currStrOff, ____BAH_COMPILER_VAR_540, strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_539;
j = j+1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_541 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_541 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_541+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_541+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_541;
}
};
char * ____BAH_COMPILER_VAR_542 =null;char * ____BAH_COMPILER_VAR_543 =tmpfnRetCType.str(&tmpfnRetCType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen(")(");
long int strLen_3 = strlen(em->name);
long int strLen_4 = strlen(" (*");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_543);
;                            
            ____BAH_COMPILER_VAR_542 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_542+currStrOff, ____BAH_COMPILER_VAR_543, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_542+currStrOff, " (*", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_542+currStrOff, em->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_542+currStrOff, ")(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_542+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_542+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }membDeclStr = ____BAH_COMPILER_VAR_542;
}
else {
if (isRCPpointerType(em->type)) {
s->hasRCPmemb = true;
}
struct string membDecl = getCType(em->type,elems);
membDecl.append(&membDecl," ");
membDecl.append(&membDecl,em->name);
membDeclStr = membDecl.content;
}

{
long nLength = len(allMembs);
if (allMembs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(allMembs->data, (nLength+50)*sizeof(char *));
allMembs->data = newPtr;
}
allMembs->data[len(allMembs)] = membDeclStr;
allMembs->length = nLength+1;
} else {
allMembs->data[len(allMembs)] = membDeclStr;
}
};

{
long nLength = len(members);
if (members->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(members->data, (nLength+50)*sizeof(struct structMemb*));
members->data = newPtr;
}
members->data[len(members)] = em;
members->length = nLength+1;
} else {
members->data[len(members)] = em;
}
};
j = j+1;
};
register long int k = 0;
while ((k<len(extdS->methods))) {
struct func* emt = extdS->methods->data[k];
struct string mthdDecl = getCType(emt->returns->type,elems);
char * ____BAH_COMPILER_VAR_544 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(emt->name);
long int strLen_1 = strlen(")(");
long int strLen_2 = strlen("(*");
;                            
            ____BAH_COMPILER_VAR_544 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_544+currStrOff, "(*", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_544+currStrOff, emt->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_544+currStrOff, ")(", strLen_1);
            currStrOff += strLen_1;
        
        }mthdDecl.append(&mthdDecl,____BAH_COMPILER_VAR_544);
j = 0;
while ((j<len(emt->args))) {
struct variable* a = emt->args->data[j];
struct string tp = getCType(a->type,elems);
char * ____BAH_COMPILER_VAR_545 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(" ");
long int strLen_1 = strlen(a->name);
;                            
            ____BAH_COMPILER_VAR_545 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_545+currStrOff, " ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_545+currStrOff, a->name, strLen_1);
            currStrOff += strLen_1;
        
        }tp.append(&tp,____BAH_COMPILER_VAR_545);
long int max = len(emt->args)-1;
if ((j!=max)) {
tp.append(&tp,",");
}
char * ____BAH_COMPILER_VAR_546 =tp.str(&tp);mthdDecl.append(&mthdDecl,____BAH_COMPILER_VAR_546);
j = j+1;
};
mthdDecl.append(&mthdDecl,")");

{
long nLength = len(allMembs);
if (allMembs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(allMembs->data, (nLength+50)*sizeof(char *));
allMembs->data = newPtr;
}
allMembs->data[len(allMembs)] = mthdDecl.str(&mthdDecl);
allMembs->length = nLength+1;
} else {
allMembs->data[len(allMembs)] = mthdDecl.str(&mthdDecl);
}
};
k = k+1;
};
}
else {
throwErr(&st,"Cannot use keyword {TOKEN} in struct declaration.");
}
}
struct Tok braceTk = l->data[i];
i++;
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
struct structMemb* ____BAH_COMPILER_VAR_547 = memoryAlloc(sizeof(struct structMemb));
____BAH_COMPILER_VAR_547->name = "";
____BAH_COMPILER_VAR_547->type = "";
____BAH_COMPILER_VAR_547->isConst = false;
____BAH_COMPILER_VAR_547->constVal = "";
____BAH_COMPILER_VAR_547->isArray = false;
____BAH_COMPILER_VAR_547->from = "";
____BAH_COMPILER_VAR_547->declScope= null;
____BAH_COMPILER_VAR_547->isGlobal = false;
____BAH_COMPILER_VAR_547->declRope= null;
____BAH_COMPILER_VAR_547->isReg = false;
____BAH_COMPILER_VAR_547->def = "";
____BAH_COMPILER_VAR_547->isFn = false;
struct structMemb* memb = ____BAH_COMPILER_VAR_547;
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
i++;
t = l->data[i];
if ((strcmp(t.cont, ":") != 0)) {
if ((strcmp(t.cont, "(") != 0)) {
throwErr(&t,"Member name should be followed by ':' not {TOKEN}.");
}
else {
char * ____BAH_COMPILER_VAR_548 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s->name);
long int strLen_1 = strlen("__");
;                            
            ____BAH_COMPILER_VAR_548 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_548+currStrOff, s->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_548+currStrOff, "__", strLen_1);
            currStrOff += strLen_1;
        
        }char * fnPrefix = ____BAH_COMPILER_VAR_548;
struct func* ____BAH_COMPILER_VAR_549 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_549->name = "";
____BAH_COMPILER_VAR_549->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_549->args->length = 0;
            ____BAH_COMPILER_VAR_549->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_549->returns= null;
____BAH_COMPILER_VAR_549->isBinding = false;
____BAH_COMPILER_VAR_549->from = "";
____BAH_COMPILER_VAR_549->file = "";
____BAH_COMPILER_VAR_549->line = 1;
____BAH_COMPILER_VAR_549->used = false;
____BAH_COMPILER_VAR_549->code = null;
struct func* fn = ____BAH_COMPILER_VAR_549;
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
register long int j = i-1;
while ((j<len(l))) {
t = l->data[j];
if ((strcmp(t.cont, "{") == 0)) {
break;
}

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] = t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] = t;
}
};
if ((j==i)) {
t.type = TOKEN_TYPE_VAR;
t.cont = "this";
t.isValue = true;

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] = t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] = t;
}
};
t.type = TOKEN_TYPE_VAR;
char * ____BAH_COMPILER_VAR_550 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s->name);
long int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_550 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_550+currStrOff, s->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_550+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_550;
t.isValue = true;

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] = t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] = t;
}
};
struct Tok nt = l->data[j+1];
if ((strcmp(nt.cont, ")") != 0)) {
t.type = TOKEN_TYPE_SYNTAX;
t.cont = ",";
t.isValue = false;

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] = t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] = t;
}
};
}
}
j = j+1;
};
i--;
long int nli = 0;
char * ____BAH_COMPILER_VAR_551 =parseFnHeader(fnPrefix,nl,&nli,fn,elems);struct rope* code = rope(____BAH_COMPILER_VAR_551);
i = i+nli;
i = i-2;
struct variable* returns = fn->returns;
array(struct variable*)* arguments = fn->args;
fn->from = s->name;
if ((shouldOnlyDecl==true)) {
code = code->add(code, rope(";\n"));
}
else {
code = code->add(code, rope("{\n"));
}
struct Elems* fnElems = dupElems(elems);
j = 0;
while ((j<len(arguments))) {
struct variable* a = arguments->data[j];
a->declScope = elems;

{
long nLength = len(fnElems->vars);
if (fnElems->vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(fnElems->vars->data, (nLength+50)*sizeof(struct variable*));
fnElems->vars->data = newPtr;
}
fnElems->vars->data[len(fnElems->vars)] = a;
fnElems->vars->length = nLength+1;
} else {
fnElems->vars->data[len(fnElems->vars)] = a;
}
};
j = j+1;
};
array(struct func*)* fns = elems->fns;

{
long nLength = len(fns);
if (fns->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(fns->data, (nLength+50)*sizeof(struct func*));
fns->data = newPtr;
}
fns->data[len(fns)] = fn;
fns->length = nLength+1;
} else {
fns->data[len(fns)] = fn;
}
};
array(struct Tok)* tokens = memoryAlloc(sizeof(array(struct Tok)));

tokens->length = 0;
tokens->elemSize = sizeof(struct Tok);
long int nbBraces = 1;
t = l->data[i];
if ((strcmp(t.cont, "{") == 0)) {
i++;
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

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] = t;
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] = t;
}
};
i++;
};
struct func* ____BAH_COMPILER_VAR_552 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_552->name = "";
____BAH_COMPILER_VAR_552->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_552->args->length = 0;
            ____BAH_COMPILER_VAR_552->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_552->returns= null;
____BAH_COMPILER_VAR_552->isBinding = false;
____BAH_COMPILER_VAR_552->from = "";
____BAH_COMPILER_VAR_552->file = "";
____BAH_COMPILER_VAR_552->line = 1;
____BAH_COMPILER_VAR_552->used = false;
____BAH_COMPILER_VAR_552->code = null;
struct func* mfn = ____BAH_COMPILER_VAR_552;
mfn->args = fn->args;
mfn->name = fn->name;
mfn->returns = fn->returns;
mfn->from = s->name;
strTrimLeft(&mfn->name,strlen(fnPrefix));

{
long nLength = len(methds);
if (methds->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(methds->data, (nLength+50)*sizeof(struct func*));
methds->data = newPtr;
}
methds->data[len(methds)] = mfn;
methds->length = nLength+1;
} else {
methds->data[len(methds)] = mfn;
}
};
if ((shouldOnlyDecl==false)) {
if ((len(tokens)==0)) {
code = code->add(code, rope("};\n"));
}
else {
OUTPUT = rope("");
currentFn = fn;
beginRCPscope(fnElems,fn->args);
struct Elems* ocurrFnElems = compilerState.currFnElems;
compilerState.currFnElems = fnElems;
parseLines(tokens,fnElems);
compilerState.currFnElems = ocurrFnElems;
currentFn = null;
if ((fn->returned==false)) {
if ((strlen(fn->returns->type)>0)) {
char * ____BAH_COMPILER_VAR_553 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fn->name);
long int strLen_1 = strlen("' is not returned.");
long int strLen_2 = strlen("Function '");
;                            
            ____BAH_COMPILER_VAR_553 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_553+currStrOff, "Function '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_553+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_553+currStrOff, "' is not returned.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&l->data[len(l)-1],____BAH_COMPILER_VAR_553);
}
endRCPscope(fnElems,fn->args);
}
code = code->add(code, OUTPUT->add(OUTPUT, rope("};\n")));
}
}
if ((doesOutput==true)) {
char * ____BAH_COMPILER_VAR_554 =null;char * ____BAH_COMPILER_VAR_555 =code->toStr(code);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nextLine);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_555);
;                            
            ____BAH_COMPILER_VAR_554 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_554+currStrOff, nextLine, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_554+currStrOff, ____BAH_COMPILER_VAR_555, strLen_1);
            currStrOff += strLen_1;
        
        }nextLine = ____BAH_COMPILER_VAR_554;
}
struct string mthdDecl = getCType(fn->returns->type,elems);
char * ____BAH_COMPILER_VAR_556 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(mfn->name);
long int strLen_1 = strlen(")(");
long int strLen_2 = strlen("(*");
;                            
            ____BAH_COMPILER_VAR_556 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_556+currStrOff, "(*", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_556+currStrOff, mfn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_556+currStrOff, ")(", strLen_1);
            currStrOff += strLen_1;
        
        }mthdDecl.append(&mthdDecl,____BAH_COMPILER_VAR_556);
j = 0;
while ((j<len(arguments))) {
struct variable* a = arguments->data[j];
struct string tp = getCType(a->type,elems);
char * ____BAH_COMPILER_VAR_557 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(" ");
long int strLen_1 = strlen(a->name);
;                            
            ____BAH_COMPILER_VAR_557 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_557+currStrOff, " ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_557+currStrOff, a->name, strLen_1);
            currStrOff += strLen_1;
        
        }tp.append(&tp,____BAH_COMPILER_VAR_557);
max = len(arguments)-1;
if ((j!=max)) {
tp.append(&tp,",");
}
char * ____BAH_COMPILER_VAR_558 =tp.str(&tp);mthdDecl.append(&mthdDecl,____BAH_COMPILER_VAR_558);
j = j+1;
};
mthdDecl.append(&mthdDecl,")");

{
long nLength = len(allMembs);
if (allMembs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(allMembs->data, (nLength+50)*sizeof(char *));
allMembs->data = newPtr;
}
allMembs->data[len(allMembs)] = mthdDecl.str(&mthdDecl);
allMembs->length = nLength+1;
} else {
allMembs->data[len(allMembs)] = mthdDecl.str(&mthdDecl);
}
};
i++;
continue;
}
}
i++;
char * mbmType = "";
long int currentLine = t.line;
while ((i<len(l))) {
t = l->data[i];
if ((strcmp(t.cont, "=") == 0)) {
i--;
break;
}
if ((t.line!=currentLine)) {
i--;
break;
}
char * ____BAH_COMPILER_VAR_559 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(mbmType);
long int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_559 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_559+currStrOff, mbmType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_559+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }mbmType = ____BAH_COMPILER_VAR_559;
i++;
};
memb->type = mbmType;
i++;
t = l->data[i];
if ((i<len(l))) {
if ((strcmp(t.cont, "=") == 0)) {
i++;
t = l->data[i];
if ((t.isValue==false)) {
throwErr(&t,"Cannot use {TOKEN} as default value for member.");
}
char * tt = getTypeFromToken(&t,true,elems);
if ((compTypes(tt,memb->type)==false)) {
char * ____BAH_COMPILER_VAR_560 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(memb->type);
long int strLen_1 = strlen(" for member.");
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(tt);
long int strLen_4 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_560 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_560+currStrOff, "Cannot use {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_560+currStrOff, tt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_560+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_560+currStrOff, memb->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_560+currStrOff, " for member.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&t,____BAH_COMPILER_VAR_560);
}
memb->def = t.cont;
}
else {
i--;
}
}
if (isRCPpointerType(memb->type)) {
s->hasRCPmemb = true;
}

{
long nLength = len(members);
if (members->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(members->data, (nLength+50)*sizeof(struct structMemb*));
members->data = newPtr;
}
members->data[len(members)] = memb;
members->length = nLength+1;
} else {
members->data[len(members)] = memb;
}
};
char * membDeclStr= null;
struct string cmt = string(memb->type);
if ((cmt.hasPrefix(&cmt,"function(")==1)) {
struct func* tmpfn = parseFnType(cmt);
struct string tmpfnRetCType = getCType(tmpfn->returns->type,elems);
char * tmpfnArgsCType = "";
register long int j = 0;
while ((j<len(tmpfn->args))) {
struct variable* arg = tmpfn->args->data[j];
struct string ct = getCType(arg->type,elems);
char * ____BAH_COMPILER_VAR_561 =null;char * ____BAH_COMPILER_VAR_562 =ct.str(&ct);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_562);
;                            
            ____BAH_COMPILER_VAR_561 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_561+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_561+currStrOff, ____BAH_COMPILER_VAR_562, strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_561;
j = j+1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_563 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_563 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_563+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_563+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_563;
}
};
char * ____BAH_COMPILER_VAR_564 =null;char * ____BAH_COMPILER_VAR_565 =tmpfnRetCType.str(&tmpfnRetCType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen(")(");
long int strLen_3 = strlen(memb->name);
long int strLen_4 = strlen(" (*");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_565);
;                            
            ____BAH_COMPILER_VAR_564 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_564+currStrOff, ____BAH_COMPILER_VAR_565, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_564+currStrOff, " (*", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_564+currStrOff, memb->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_564+currStrOff, ")(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_564+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_564+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }membDeclStr = ____BAH_COMPILER_VAR_564;
}
else {
struct string membDecl = getCType(memb->type,elems);
char * ____BAH_COMPILER_VAR_566 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(" ");
long int strLen_1 = strlen(memb->name);
;                            
            ____BAH_COMPILER_VAR_566 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_566+currStrOff, " ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_566+currStrOff, memb->name, strLen_1);
            currStrOff += strLen_1;
        
        }membDecl.append(&membDecl,____BAH_COMPILER_VAR_566);
membDeclStr = membDecl.str(&membDecl);
}

{
long nLength = len(allMembs);
if (allMembs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(allMembs->data, (nLength+50)*sizeof(char *));
allMembs->data = newPtr;
}
allMembs->data[len(allMembs)] = membDeclStr;
allMembs->length = nLength+1;
} else {
allMembs->data[len(allMembs)] = membDeclStr;
}
};
i++;
};
s->members = members;
if ((doesOutput==true)) {
OUTPUT = OOUT;
NEXT_LINE = nextLine;
char * ____BAH_COMPILER_VAR_567 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s->name);
long int strLen_1 = strlen(" {\n");
long int strLen_2 = strlen("struct ");
;                            
            ____BAH_COMPILER_VAR_567 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_567+currStrOff, "struct ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_567+currStrOff, s->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_567+currStrOff, " {\n", strLen_1);
            currStrOff += strLen_1;
        
        }struct rope* code = rope(____BAH_COMPILER_VAR_567);
i = 0;
while ((i<len(allMembs))) {
char * m = allMembs->data[i];
char * ____BAH_COMPILER_VAR_568 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(m);
long int strLen_1 = strlen(";\n");
;                            
            ____BAH_COMPILER_VAR_568 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_568+currStrOff, m, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_568+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }code = code->add(code, rope(____BAH_COMPILER_VAR_568));
i++;
};
code = code->add(code, rope("};\n"));
OUTPUT = OUTPUT->add(OUTPUT, code);
}
if ((debug==true)) {
struct debugStruct* ____BAH_COMPILER_VAR_569 = memoryAlloc(sizeof(struct debugStruct));
____BAH_COMPILER_VAR_569->name= null;
____BAH_COMPILER_VAR_569->membs = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_569->membs->length = 0;
            ____BAH_COMPILER_VAR_569->membs->elemSize = sizeof(struct variable*);
            struct debugStruct* ds = ____BAH_COMPILER_VAR_569;
ds->name = s->name;
i = 0;
while ((i<len(s->members))) {
struct structMemb* m = s->members->data[i];
struct variable* ____BAH_COMPILER_VAR_570 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_570->name = "";
____BAH_COMPILER_VAR_570->type = "";
____BAH_COMPILER_VAR_570->isConst = false;
____BAH_COMPILER_VAR_570->constVal = "";
____BAH_COMPILER_VAR_570->isArray = false;
____BAH_COMPILER_VAR_570->from = "";
____BAH_COMPILER_VAR_570->declScope= null;
____BAH_COMPILER_VAR_570->isGlobal = false;
____BAH_COMPILER_VAR_570->declRope= null;
____BAH_COMPILER_VAR_570->isReg = false;
struct variable* mv = ____BAH_COMPILER_VAR_570;
mv->name = m->name;
mv->type = m->type;
mv->isConst = false;
mv->isArray = m->isArray;

{
long nLength = i;
if (ds->membs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(ds->membs->data, (nLength+50)*sizeof(struct variable*));
ds->membs->data = newPtr;
}
ds->membs->data[i] = mv;
ds->membs->length = nLength+1;
} else {
ds->membs->data[i] = mv;
}
};
i = i+1;
};
struct debugStruct* ____BAH_COMPILER_VAR_571 = ds;
char ** ____BAH_COMPILER_VAR_573 = (char **)((char*)(____BAH_COMPILER_VAR_571) + offsetof(struct debugStruct, name));
struct reflectElement ____BAH_COMPILER_VAR_574 = __reflect(____BAH_COMPILER_VAR_573, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct debugStruct, name));
array(struct variable*)** ____BAH_COMPILER_VAR_575 = (array(struct variable*)**)((char*)(____BAH_COMPILER_VAR_571) + offsetof(struct debugStruct, membs));
struct variable** ____BAH_COMPILER_VAR_576 = 0;
char ** ____BAH_COMPILER_VAR_578 = (char **)((char*)(____BAH_COMPILER_VAR_576) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_579 = __reflect(____BAH_COMPILER_VAR_578, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_580 = (char **)((char*)(____BAH_COMPILER_VAR_576) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_581 = __reflect(____BAH_COMPILER_VAR_580, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_582 = (char*)((char*)(____BAH_COMPILER_VAR_576) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_583 = __reflect(____BAH_COMPILER_VAR_582, sizeof(char), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_584 = (char **)((char*)(____BAH_COMPILER_VAR_576) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_585 = __reflect(____BAH_COMPILER_VAR_584, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_586 = (char*)((char*)(____BAH_COMPILER_VAR_576) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_587 = __reflect(____BAH_COMPILER_VAR_586, sizeof(char), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_588 = (char **)((char*)(____BAH_COMPILER_VAR_576) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_589 = __reflect(____BAH_COMPILER_VAR_588, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
void ** ____BAH_COMPILER_VAR_590 = (void **)((char*)(____BAH_COMPILER_VAR_576) + offsetof(struct variable, declScope));
struct reflectElement ____BAH_COMPILER_VAR_591 = __reflect(____BAH_COMPILER_VAR_590, sizeof(void *), "ptr", "declScope", 0, 0, 0, 0, offsetof(struct variable, declScope));
char* ____BAH_COMPILER_VAR_592 = (char*)((char*)(____BAH_COMPILER_VAR_576) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_593 = __reflect(____BAH_COMPILER_VAR_592, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));
struct rope** ____BAH_COMPILER_VAR_594 = (struct rope**)((char*)(____BAH_COMPILER_VAR_576) + offsetof(struct variable, declRope));
void ** ____BAH_COMPILER_VAR_596 = (void **)((char*)(____BAH_COMPILER_VAR_594) + offsetof(struct rope, left));
struct reflectElement ____BAH_COMPILER_VAR_597 = __reflect(____BAH_COMPILER_VAR_596, sizeof(void *), "ptr", "left", 0, 0, 0, 0, offsetof(struct rope, left));
void ** ____BAH_COMPILER_VAR_598 = (void **)((char*)(____BAH_COMPILER_VAR_594) + offsetof(struct rope, right));
struct reflectElement ____BAH_COMPILER_VAR_599 = __reflect(____BAH_COMPILER_VAR_598, sizeof(void *), "ptr", "right", 0, 0, 0, 0, offsetof(struct rope, right));
char ** ____BAH_COMPILER_VAR_600 = (char **)((char*)(____BAH_COMPILER_VAR_594) + offsetof(struct rope, str));
struct reflectElement ____BAH_COMPILER_VAR_601 = __reflect(____BAH_COMPILER_VAR_600, sizeof(char *), "cpstring", "str", 0, 0, 0, 0, offsetof(struct rope, str));
long int* ____BAH_COMPILER_VAR_602 = (long int*)((char*)(____BAH_COMPILER_VAR_594) + offsetof(struct rope, lCount));
struct reflectElement ____BAH_COMPILER_VAR_603 = __reflect(____BAH_COMPILER_VAR_602, sizeof(long int), "int", "lCount", 0, 0, 0, 0, offsetof(struct rope, lCount));
long int* ____BAH_COMPILER_VAR_604 = (long int*)((char*)(____BAH_COMPILER_VAR_594) + offsetof(struct rope, len));
struct reflectElement ____BAH_COMPILER_VAR_605 = __reflect(____BAH_COMPILER_VAR_604, sizeof(long int), "int", "len", 0, 0, 0, 0, offsetof(struct rope, len));
long int* ____BAH_COMPILER_VAR_606 = (long int*)((char*)(____BAH_COMPILER_VAR_594) + offsetof(struct rope, totalLen));
struct reflectElement ____BAH_COMPILER_VAR_607 = __reflect(____BAH_COMPILER_VAR_606, sizeof(long int), "int", "totalLen", 0, 0, 0, 0, offsetof(struct rope, totalLen));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_595 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_595->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_595->length = 6;
        ____BAH_COMPILER_VAR_595->data = memoryAlloc(____BAH_COMPILER_VAR_595->length * ____BAH_COMPILER_VAR_595->elemSize);
        ____BAH_COMPILER_VAR_595->data[0] = ____BAH_COMPILER_VAR_597;
____BAH_COMPILER_VAR_595->data[1] = ____BAH_COMPILER_VAR_599;
____BAH_COMPILER_VAR_595->data[2] = ____BAH_COMPILER_VAR_601;
____BAH_COMPILER_VAR_595->data[3] = ____BAH_COMPILER_VAR_603;
____BAH_COMPILER_VAR_595->data[4] = ____BAH_COMPILER_VAR_605;
____BAH_COMPILER_VAR_595->data[5] = ____BAH_COMPILER_VAR_607;
struct reflectElement ____BAH_COMPILER_VAR_608 = __reflect(____BAH_COMPILER_VAR_594, sizeof(struct rope), "rope*", "declRope", 0, 0, 1, ____BAH_COMPILER_VAR_595, offsetof(struct variable, declRope));
char* ____BAH_COMPILER_VAR_609 = (char*)((char*)(____BAH_COMPILER_VAR_576) + offsetof(struct variable, canBeReg));
struct reflectElement ____BAH_COMPILER_VAR_610 = __reflect(____BAH_COMPILER_VAR_609, sizeof(char), "bool", "canBeReg", 0, 0, 0, 0, offsetof(struct variable, canBeReg));
char* ____BAH_COMPILER_VAR_611 = (char*)((char*)(____BAH_COMPILER_VAR_576) + offsetof(struct variable, isReg));
struct reflectElement ____BAH_COMPILER_VAR_612 = __reflect(____BAH_COMPILER_VAR_611, sizeof(char), "bool", "isReg", 0, 0, 0, 0, offsetof(struct variable, isReg));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_577 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_577->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_577->length = 11;
        ____BAH_COMPILER_VAR_577->data = memoryAlloc(____BAH_COMPILER_VAR_577->length * ____BAH_COMPILER_VAR_577->elemSize);
        ____BAH_COMPILER_VAR_577->data[0] = ____BAH_COMPILER_VAR_579;
____BAH_COMPILER_VAR_577->data[1] = ____BAH_COMPILER_VAR_581;
____BAH_COMPILER_VAR_577->data[2] = ____BAH_COMPILER_VAR_583;
____BAH_COMPILER_VAR_577->data[3] = ____BAH_COMPILER_VAR_585;
____BAH_COMPILER_VAR_577->data[4] = ____BAH_COMPILER_VAR_587;
____BAH_COMPILER_VAR_577->data[5] = ____BAH_COMPILER_VAR_589;
____BAH_COMPILER_VAR_577->data[6] = ____BAH_COMPILER_VAR_591;
____BAH_COMPILER_VAR_577->data[7] = ____BAH_COMPILER_VAR_593;
____BAH_COMPILER_VAR_577->data[8] = ____BAH_COMPILER_VAR_608;
____BAH_COMPILER_VAR_577->data[9] = ____BAH_COMPILER_VAR_610;
____BAH_COMPILER_VAR_577->data[10] = ____BAH_COMPILER_VAR_612;
struct reflectElement ____BAH_COMPILER_VAR_613 = __reflect(____BAH_COMPILER_VAR_576, sizeof(struct variable), "variable*", "", 0, 0, 1, ____BAH_COMPILER_VAR_577, 0);

        struct reflectElement ____BAH_COMPILER_VAR_614 = ____BAH_COMPILER_VAR_613;
        struct reflectElement ____BAH_COMPILER_VAR_615 = __reflect(____BAH_COMPILER_VAR_575, sizeof(array(struct variable*)*), "[]variable*", "membs", 1, &____BAH_COMPILER_VAR_614, 0, 0, offsetof(struct debugStruct, membs));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_572 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_572->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_572->length = 2;
        ____BAH_COMPILER_VAR_572->data = memoryAlloc(____BAH_COMPILER_VAR_572->length * ____BAH_COMPILER_VAR_572->elemSize);
        ____BAH_COMPILER_VAR_572->data[0] = ____BAH_COMPILER_VAR_574;
____BAH_COMPILER_VAR_572->data[1] = ____BAH_COMPILER_VAR_615;
struct reflectElement ____BAH_COMPILER_VAR_616 = __reflect(____BAH_COMPILER_VAR_571, sizeof(struct debugStruct), "debugStruct*", "ds", 0, 0, 1, ____BAH_COMPILER_VAR_572, 0);
debugPrint("struct_declare",nameToken.line,____BAH_COMPILER_VAR_616);
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
struct func* ____BAH_COMPILER_VAR_617 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_617->name = "";
____BAH_COMPILER_VAR_617->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_617->args->length = 0;
            ____BAH_COMPILER_VAR_617->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_617->returns= null;
____BAH_COMPILER_VAR_617->isBinding = false;
____BAH_COMPILER_VAR_617->from = "";
____BAH_COMPILER_VAR_617->file = "";
____BAH_COMPILER_VAR_617->line = 1;
____BAH_COMPILER_VAR_617->used = false;
____BAH_COMPILER_VAR_617->code = null;
struct func* fn = ____BAH_COMPILER_VAR_617;
char * code = parseFnHeader("",l,&i,fn,elems);
array(struct func*)* fns = elems->fns;
fn->isBinding = true;

{
long nLength = len(fns);
if (fns->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(fns->data, (nLength+50)*sizeof(struct func*));
fns->data = newPtr;
}
fns->data[len(fns)] = fn;
fns->length = nLength+1;
} else {
fns->data[len(fns)] = fn;
}
};
if ((doesOutput==true)) {
char * ____BAH_COMPILER_VAR_618 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(";\n");
;                            
            ____BAH_COMPILER_VAR_618 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_618+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_618+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_618));
}
}
else {
char * tp = "";
i++;
for (; (i<len(l)); i++) {
struct Tok t = l->data[i];
char * ____BAH_COMPILER_VAR_619 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tp);
long int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_619 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_619+currStrOff, tp, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_619+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }tp = ____BAH_COMPILER_VAR_619;
};
if ((ft.type!=TOKEN_TYPE_VAR)) {
throwErr(&ft,"Cannot use {TOKEN} as new type name.");
}
struct string cTypeNewType = getCType(tp,elems);
char * cTypeNewTypeStr = cTypeNewType.str(&cTypeNewType);
if ((doesOutput==true)) {
char * ____BAH_COMPILER_VAR_620 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ft.cont);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(cTypeNewTypeStr);
long int strLen_4 = strlen("typedef ");
;                            
            ____BAH_COMPILER_VAR_620 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_620+currStrOff, "typedef ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_620+currStrOff, cTypeNewTypeStr, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_620+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_620+currStrOff, ft.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_620+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_620));
}
if ((debug==true)) {
struct debugType* ____BAH_COMPILER_VAR_621 = memoryAlloc(sizeof(struct debugType));
____BAH_COMPILER_VAR_621->name= null;
____BAH_COMPILER_VAR_621->refers= null;
struct debugType* dt = ____BAH_COMPILER_VAR_621;
dt->name = ft.cont;
dt->refers = tp;
struct debugType* ____BAH_COMPILER_VAR_622 = dt;
char ** ____BAH_COMPILER_VAR_624 = (char **)((char*)(____BAH_COMPILER_VAR_622) + offsetof(struct debugType, name));
struct reflectElement ____BAH_COMPILER_VAR_625 = __reflect(____BAH_COMPILER_VAR_624, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct debugType, name));
char ** ____BAH_COMPILER_VAR_626 = (char **)((char*)(____BAH_COMPILER_VAR_622) + offsetof(struct debugType, refers));
struct reflectElement ____BAH_COMPILER_VAR_627 = __reflect(____BAH_COMPILER_VAR_626, sizeof(char *), "cpstring", "refers", 0, 0, 0, 0, offsetof(struct debugType, refers));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_623 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_623->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_623->length = 2;
        ____BAH_COMPILER_VAR_623->data = memoryAlloc(____BAH_COMPILER_VAR_623->length * ____BAH_COMPILER_VAR_623->elemSize);
        ____BAH_COMPILER_VAR_623->data[0] = ____BAH_COMPILER_VAR_625;
____BAH_COMPILER_VAR_623->data[1] = ____BAH_COMPILER_VAR_627;
struct reflectElement ____BAH_COMPILER_VAR_628 = __reflect(____BAH_COMPILER_VAR_622, sizeof(struct debugType), "debugType*", "dt", 0, 0, 1, ____BAH_COMPILER_VAR_623, 0);
debugPrint("type_declare",ft.line,____BAH_COMPILER_VAR_628);
}
array(char *)* tps = elems->types;

{
long nLength = len(tps);
if (tps->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tps->data, (nLength+50)*sizeof(char *));
tps->data = newPtr;
}
tps->data[len(tps)] = ft.cont;
tps->length = nLength+1;
} else {
tps->data[len(tps)] = ft.cont;
}
};
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
cc.trimLeft(&cc,1);
cc.trimRight(&cc,1);
char * ccstr = cc.str(&cc);
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
i++;
continue;
}

{
long nLength = len(clibs);
if (clibs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(clibs->data, (nLength+50)*sizeof(char *));
clibs->data = newPtr;
}
clibs->data[len(clibs)] = ccstr;
clibs->length = nLength+1;
} else {
clibs->data[len(clibs)] = ccstr;
}
};
i++;
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
struct variable* ____BAH_COMPILER_VAR_629 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_629->name = "";
____BAH_COMPILER_VAR_629->type = "";
____BAH_COMPILER_VAR_629->isConst = false;
____BAH_COMPILER_VAR_629->constVal = "";
____BAH_COMPILER_VAR_629->isArray = false;
____BAH_COMPILER_VAR_629->from = "";
____BAH_COMPILER_VAR_629->declScope= null;
____BAH_COMPILER_VAR_629->isGlobal = false;
____BAH_COMPILER_VAR_629->declRope= null;
____BAH_COMPILER_VAR_629->isReg = false;
struct variable* v = ____BAH_COMPILER_VAR_629;
if (isGlobal()) {
v->isGlobal = true;
}
v->isConst = true;
v->constVal = valt.cont;
v->name = vart.cont;
v->type = getTypeFromToken(&valt,true,elems);
array(struct variable*)* vars = elems->vars;

{
long nLength = len(vars);
if (vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(vars->data, (nLength+50)*sizeof(struct variable*));
vars->data = newPtr;
}
vars->data[len(vars)] = v;
vars->length = nLength+1;
} else {
vars->data[len(vars)] = v;
}
};
char * ____BAH_COMPILER_VAR_630 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(valt.cont);
long int strLen_1 = strlen("\n");
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen("#define ");
;                            
            ____BAH_COMPILER_VAR_630 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_630+currStrOff, "#define ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_630+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_630+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_630+currStrOff, valt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_630+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_630));
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
char * ____BAH_COMPILER_VAR_631 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(currentFn->returns->type);
long int strLen_1 = strlen(".");
long int strLen_2 = strlen("Cannot return nothing as ");
;                            
            ____BAH_COMPILER_VAR_631 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_631+currStrOff, "Cannot return nothing as ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_631+currStrOff, currentFn->returns->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_631+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&l->data[0],____BAH_COMPILER_VAR_631);
}
}
else {
struct Tok rvt = l->data[1];
tt = getTypeFromToken(&rvt,true,elems);
rv = rvt.cont;
if ((rvt.isValue==false)) {
throwErr(&rvt,"Must be a value, not {TOKEN}.");
}
else if ((rvt.type==TOKEN_TYPE_VAR)&&(rvt.isOper==false)) {
tmpV = searchVar(rvt.cont,compilerState.currFnElems);
if ((tmpV==null)) {
tmpV = searchVar(rvt.cont,elems);
}
}
else if (RCPavailable()&&(rvt.type==TOKEN_TYPE_FUNC)) {
rv = genCompilerVar();
struct string cType = getCType(tt,elems);
char * ____BAH_COMPILER_VAR_632 =null;char * ____BAH_COMPILER_VAR_633 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(rvt.cont);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen("=");
long int strLen_3 = strlen(rv);
long int strLen_4 = strlen(" ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_633);
;                            
            ____BAH_COMPILER_VAR_632 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_632+currStrOff, ____BAH_COMPILER_VAR_633, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_632+currStrOff, " ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_632+currStrOff, rv, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_632+currStrOff, "=", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_632+currStrOff, rvt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_632+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_632));
}
if ((compTypes(tt,currentFn->returns->type)==false)) {
char * ____BAH_COMPILER_VAR_634 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(currentFn->returns->type);
long int strLen_1 = strlen(".");
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(tt);
long int strLen_4 = strlen("Cannot return {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_634 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_634+currStrOff, "Cannot return {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_634+currStrOff, tt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_634+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_634+currStrOff, currentFn->returns->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_634+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&rvt,____BAH_COMPILER_VAR_634);
}
}
if ((compilerState.isBranch==false)) {
currentFn->returned = true;
}
if ((strlen(rv)>0)) {
char * rvar = rv;
if ((RCPavailable()==true)&&isRCPtype(currentFn->returns->type,elems)) {
rvar = genCompilerVar();
struct string cType = getCType(currentFn->returns->type,elems);
char * ____BAH_COMPILER_VAR_635 =null;char * ____BAH_COMPILER_VAR_636 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(rv);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen(" = ");
long int strLen_3 = strlen(rvar);
long int strLen_4 = strlen(" ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_636);
;                            
            ____BAH_COMPILER_VAR_635 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_635+currStrOff, ____BAH_COMPILER_VAR_636, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_635+currStrOff, " ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_635+currStrOff, rvar, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_635+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_635+currStrOff, rv, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_635+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_635));
if ((tmpV!=null)&&(tmpV->declScope!=elems)) {
OUTPUT = OUTPUT->add(OUTPUT, incrVar(tmpV,elems));
}
}
if (strHasPrefix(tt,"buffer:")) {
char * ____BAH_COMPILER_VAR_637 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(rvar);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen("__STR(");
;                            
            ____BAH_COMPILER_VAR_637 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_637+currStrOff, "__STR(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_637+currStrOff, rvar, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_637+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }rvar = ____BAH_COMPILER_VAR_637;
}
if (RCPavailable()) {
array(struct variable*)* excl = memoryAlloc(sizeof(array(struct variable*)));

excl->length = 0;
excl->elemSize = sizeof(struct variable*);
register long int j = 0;
for (; (j<len(currentFn->args)); j++) {

{
long nLength = j;
if (excl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(excl->data, (nLength+50)*sizeof(struct variable*));
excl->data = newPtr;
}
excl->data[j] = currentFn->args->data[j];
excl->length = nLength+1;
} else {
excl->data[j] = currentFn->args->data[j];
}
};
};
if ((tmpV!=null)) {

{
long nLength = len(excl);
if (excl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(excl->data, (nLength+50)*sizeof(struct variable*));
excl->data = newPtr;
}
excl->data[len(excl)] = tmpV;
excl->length = nLength+1;
} else {
excl->data[len(excl)] = tmpV;
}
};
}
endRCPscope(elems,excl);
}
char * ____BAH_COMPILER_VAR_638 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(rvar);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen("return ");
;                            
            ____BAH_COMPILER_VAR_638 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_638+currStrOff, "return ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_638+currStrOff, rvar, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_638+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_638));
}
else {
if (RCPavailable()) {
array(struct variable*)* excl = memoryAlloc(sizeof(array(struct variable*)));

excl->length = 0;
excl->elemSize = sizeof(struct variable*);
register long int j = 0;
for (; (j<len(currentFn->args)); j++) {

{
long nLength = j;
if (excl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(excl->data, (nLength+50)*sizeof(struct variable*));
excl->data = newPtr;
}
excl->data[j] = currentFn->args->data[j];
excl->length = nLength+1;
} else {
excl->data[j] = currentFn->args->data[j];
}
};
};
if ((tmpV!=null)) {

{
long nLength = len(excl);
if (excl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(excl->data, (nLength+50)*sizeof(struct variable*));
excl->data = newPtr;
}
excl->data[len(excl)] = tmpV;
excl->length = nLength+1;
} else {
excl->data[len(excl)] = tmpV;
}
};
}
endRCPscope(elems,excl);
}
OUTPUT = OUTPUT->add(OUTPUT, rope("return;\n"));
}
};
void parseIf(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
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

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] = t;
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] = t;
}
};
i++;
};
char * ____BAH_COMPILER_VAR_639 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(condt.cont);
long int strLen_1 = strlen(") {\n");
long int strLen_2 = strlen("if (");
;                            
            ____BAH_COMPILER_VAR_639 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_639+currStrOff, "if (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_639+currStrOff, condt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_639+currStrOff, ") {\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_639));
struct Elems* ifElems = dupElems(elems);
char oldIB = compilerState.isBranch;
compilerState.isBranch = true;
beginRCPscopeLeaky(ifElems);
parseLines(tokens,ifElems);
endRCPscopeLeaky(ifElems,null);
if ((debug==true)) {
struct Tok lt = l->data[len(l)-1];
debugEndScope(lt.line,ifElems);
}
compilerState.isBranch = oldIB;
OUTPUT = OUTPUT->add(OUTPUT, rope("}\n"));
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
OUTPUT = OUTPUT->add(OUTPUT, rope("else "));
if ((strcmp(ft.cont, "if") == 0)) {
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
register long int i = 1;
while ((i<len(l))) {

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] = l->data[i];
memory->length = nLength+1;
} else {
memory->data[len(memory)] = l->data[i];
}
};
i++;
};
parseIf(memory,elems);
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

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] = l->data[i];
memory->length = nLength+1;
} else {
memory->data[len(memory)] = l->data[i];
}
};
i++;
};
OUTPUT = OUTPUT->add(OUTPUT, rope("{\n"));
struct Elems* ifElems = dupElems(elems);
char oldIB = compilerState.isBranch;
compilerState.isBranch = true;
struct Tok t = l->data[0];
beginRCPscopeLeaky(ifElems);
parseLines(memory,ifElems);
endRCPscopeLeaky(ifElems,null);
if ((debug==true)) {
struct Tok lt = l->data[len(l)-1];
debugEndScope(lt.line,ifElems);
}
compilerState.isBranch = oldIB;
OUTPUT = OUTPUT->add(OUTPUT, rope("}\n"));
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
for (; (i<len(l)); i++) {
struct Tok t = l->data[i];
if ((t.type==TOKEN_TYPE_ENCL)&&(strcmp(t.cont, "{") == 0)) {
break;
}

{
long nLength = len(inst);
if (inst->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(inst->data, (nLength+50)*sizeof(struct Tok));
inst->data = newPtr;
}
inst->data[len(inst)] = t;
inst->length = nLength+1;
} else {
inst->data[len(inst)] = t;
}
};
};
struct rope* oldOut = OUTPUT;
OUTPUT = rope("");
parseLine(inst,elems);
char * ____BAH_COMPILER_VAR_640 =OUTPUT->toStr(OUTPUT);struct string instC = string(____BAH_COMPILER_VAR_640);
OUTPUT = oldOut;
instC.trimRight(&instC,2);
struct Tok t = l->data[i];
if ((strcmp(t.cont, "{") != 0)) {
throwErr(&t,"Expected '{' not {TOKEN} after '<condition>,<instruction>' in for statement.");
}
long int max = len(l)-1;
i = i+1;
for (; (i<max); i++) {
t = l->data[i];

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] = t;
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] = t;
}
};
};
char * ____BAH_COMPILER_VAR_641 =null;char * ____BAH_COMPILER_VAR_642 =instC.str(&instC);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_642);
long int strLen_1 = strlen(") {\n");
long int strLen_2 = strlen("; ");
long int strLen_3 = strlen(condt.cont);
long int strLen_4 = strlen("for (; ");
;                            
            ____BAH_COMPILER_VAR_641 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_641+currStrOff, "for (; ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_641+currStrOff, condt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_641+currStrOff, "; ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_641+currStrOff, ____BAH_COMPILER_VAR_642, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_641+currStrOff, ") {\n", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_643 =____BAH_COMPILER_VAR_641;OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_643));
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
for (; (i<max); i++) {
t = l->data[i];

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] = t;
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] = t;
}
};
};
char * ____BAH_COMPILER_VAR_644 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(condt.cont);
long int strLen_1 = strlen(") {\n");
long int strLen_2 = strlen("while (");
;                            
            ____BAH_COMPILER_VAR_644 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_644+currStrOff, "while (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_644+currStrOff, condt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_644+currStrOff, ") {\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_644));
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
endRCPscopeLeaky(ifElems,null);
if ((debug==true)) {
struct Tok lt = l->data[len(l)-1];
debugEndScope(lt.line,ifElems);
}
compilerState.isFor = oldIF;
compilerState.isBranch = oldIB;
compilerState.currForElems = oForElems;
OUTPUT = OUTPUT->add(OUTPUT, rope("};\n"));
};
void parseForOp(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
struct Tok ft = l->data[0];
if ((compilerState.isFor==false)) {
throwErr(&ft,"Cannot {TOKEN} outside of for statement.");
}
if ((len(l)!=1)) {
throwErr(&ft,"Nothing expected after {TOKEN}.");
}
endRCPscopeLeaky(elems,null);
endRCPscopeLeaky(compilerState.currForElems,null);
char * ____BAH_COMPILER_VAR_645 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ft.cont);
long int strLen_1 = strlen(";\n");
;                            
            ____BAH_COMPILER_VAR_645 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_645+currStrOff, ft.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_645+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_645));
};
void makeEvalFunc(struct func* fn,struct Elems* elems){

        char ____BAH_COMPILER_VAR_646 = 0;
        for(int i=compilerState.evals->length-1; i!=-1;i--) {
            if (compilerState.evals->data[i] != 0 && strcmp(compilerState.evals->data[i], fn->name) == 0) {
                ____BAH_COMPILER_VAR_646=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_646) {
return;
}
char * ____BAH_COMPILER_VAR_647 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("__Bah_eval_");
long int strLen_1 = strlen(fn->name);
;                            
            ____BAH_COMPILER_VAR_647 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_647+currStrOff, "__Bah_eval_", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_647+currStrOff, fn->name, strLen_1);
            currStrOff += strLen_1;
        
        }struct func* ____BAH_COMPILER_VAR_648 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_648->name = "";
____BAH_COMPILER_VAR_648->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_648->args->length = 0;
            ____BAH_COMPILER_VAR_648->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_648->returns= null;
____BAH_COMPILER_VAR_648->isBinding = false;
____BAH_COMPILER_VAR_648->from = "";
____BAH_COMPILER_VAR_648->file = "";
____BAH_COMPILER_VAR_648->line = 1;
____BAH_COMPILER_VAR_648->used = false;
____BAH_COMPILER_VAR_648->code = null;
____BAH_COMPILER_VAR_648->name = ____BAH_COMPILER_VAR_647;
struct func* efn = ____BAH_COMPILER_VAR_648;
struct variable* ____BAH_COMPILER_VAR_649 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_649->name = "";
____BAH_COMPILER_VAR_649->type = "";
____BAH_COMPILER_VAR_649->isConst = false;
____BAH_COMPILER_VAR_649->constVal = "";
____BAH_COMPILER_VAR_649->isArray = false;
____BAH_COMPILER_VAR_649->from = "";
____BAH_COMPILER_VAR_649->declScope= null;
____BAH_COMPILER_VAR_649->isGlobal = false;
____BAH_COMPILER_VAR_649->declRope= null;
____BAH_COMPILER_VAR_649->isReg = false;
____BAH_COMPILER_VAR_649->type = "ptr";
efn->returns = ____BAH_COMPILER_VAR_649;
struct variable* ____BAH_COMPILER_VAR_650 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_650->name = "";
____BAH_COMPILER_VAR_650->type = "";
____BAH_COMPILER_VAR_650->isConst = false;
____BAH_COMPILER_VAR_650->constVal = "";
____BAH_COMPILER_VAR_650->isArray = false;
____BAH_COMPILER_VAR_650->from = "";
____BAH_COMPILER_VAR_650->declScope= null;
____BAH_COMPILER_VAR_650->isGlobal = false;
____BAH_COMPILER_VAR_650->declRope= null;
____BAH_COMPILER_VAR_650->isReg = false;
____BAH_COMPILER_VAR_650->name = "fnArgs";
____BAH_COMPILER_VAR_650->type = "[]ptr";
efn->args = memoryAlloc(sizeof(array(struct variable*)));

efn->args->length = 1;
efn->args->elemSize = sizeof(struct variable*);
efn->args->data = memoryAlloc(sizeof(struct variable*) * 50);efn->args->data[0] = ____BAH_COMPILER_VAR_650;
char * fnBinding = "";
char * ____BAH_COMPILER_VAR_651 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fn->name);
long int strLen_1 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_651 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_651+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_651+currStrOff, "(", strLen_1);
            currStrOff += strLen_1;
        
        }char * fnCall = ____BAH_COMPILER_VAR_651;
register long int i = 0;
for (; (i<len(fn->args)); i++) {
struct variable* a = fn->args->data[i];
char * v = genCompilerVar();
struct string cType = getCType(a->type,elems);
if ((isRCPpointerType(a->type)==false)) {
cType.append(&cType,"*");
}
char * ____BAH_COMPILER_VAR_652 =null;char * ____BAH_COMPILER_VAR_653 =intToStr(i);char * ____BAH_COMPILER_VAR_654 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_653);
long int strLen_1 = strlen("];");
long int strLen_2 = strlen(" = fnArgs->data[");
long int strLen_3 = strlen(v);
long int strLen_4 = strlen(" ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_654);
;                            
            ____BAH_COMPILER_VAR_652 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_652+currStrOff, ____BAH_COMPILER_VAR_654, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_652+currStrOff, " ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_652+currStrOff, v, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_652+currStrOff, " = fnArgs->data[", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_652+currStrOff, ____BAH_COMPILER_VAR_653, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_652+currStrOff, "];", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_655 =null;char * ____BAH_COMPILER_VAR_656 =____BAH_COMPILER_VAR_652;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnBinding);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_656);
;                            
            ____BAH_COMPILER_VAR_655 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_655+currStrOff, fnBinding, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_655+currStrOff, ____BAH_COMPILER_VAR_656, strLen_1);
            currStrOff += strLen_1;
        
        }fnBinding = ____BAH_COMPILER_VAR_655;
if ((i!=0)) {
char * ____BAH_COMPILER_VAR_657 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnCall);
long int strLen_1 = strlen(", ");
;                            
            ____BAH_COMPILER_VAR_657 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_657+currStrOff, fnCall, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_657+currStrOff, ", ", strLen_1);
            currStrOff += strLen_1;
        
        }fnCall = ____BAH_COMPILER_VAR_657;
}
if (isRCPpointerType(a->type)) {
char * ____BAH_COMPILER_VAR_658 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnCall);
long int strLen_1 = strlen(v);
;                            
            ____BAH_COMPILER_VAR_658 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_658+currStrOff, fnCall, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_658+currStrOff, v, strLen_1);
            currStrOff += strLen_1;
        
        }fnCall = ____BAH_COMPILER_VAR_658;
}
else {
char * ____BAH_COMPILER_VAR_659 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("*");
long int strLen_1 = strlen(v);
;                            
            ____BAH_COMPILER_VAR_659 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_659+currStrOff, "*", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_659+currStrOff, v, strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_660 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnCall);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_659);
;                            
            ____BAH_COMPILER_VAR_660 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_660+currStrOff, fnCall, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_660+currStrOff, ____BAH_COMPILER_VAR_659, strLen_1);
            currStrOff += strLen_1;
        
        }fnCall = ____BAH_COMPILER_VAR_660;
}
};
char * setReturnValue = "void* r = 0;";
if (isRCPpointerType(fn->returns->type)) {
setReturnValue = "void* r = ";
}
else {
struct string cType = getCType(fn->returns->type,elems);
if ((strcmp(cType.str(&cType), "void") != 0)) {
char * ____BAH_COMPILER_VAR_661 =null;char * ____BAH_COMPILER_VAR_662 =cType.str(&cType);char * ____BAH_COMPILER_VAR_663 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_662);
long int strLen_1 = strlen("));*r = ");
long int strLen_2 = strlen("* r = memoryAlloc(sizeof(");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_663);
;                            
            ____BAH_COMPILER_VAR_661 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_661+currStrOff, ____BAH_COMPILER_VAR_663, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_661+currStrOff, "* r = memoryAlloc(sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_661+currStrOff, ____BAH_COMPILER_VAR_662, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_661+currStrOff, "));*r = ", strLen_1);
            currStrOff += strLen_1;
        
        }setReturnValue = ____BAH_COMPILER_VAR_661;
}
}
char * ____BAH_COMPILER_VAR_664 =null;char * ____BAH_COMPILER_VAR_665 =intToStr(len(fn->args));
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnCall);
long int strLen_1 = strlen(");\n        return (void*)r;\n    };");
long int strLen_2 = strlen(setReturnValue);
long int strLen_3 = strlen("\n        ");
long int strLen_4 = strlen(fnBinding);
long int strLen_5 = strlen("() with the wrong number of arguments.\", \"BAH_COMPILER_INTERNAL\");\n        }\n        ");
long int strLen_6 = strlen(fn->name);
long int strLen_7 = strlen(") {\n            __BAH_panic((char*)\"eval: calling function ");
long int strLen_8 = strlen(____BAH_COMPILER_VAR_665);
long int strLen_9 = strlen("(array(void*)* fnArgs) {\n        if (fnArgs->length != ");
long int strLen_10 = strlen(efn->name);
long int strLen_11 = strlen("void* __attribute__((optimize(\"O0\"))) ");
;                            
            ____BAH_COMPILER_VAR_664 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11);
            
                    memcpy(____BAH_COMPILER_VAR_664+currStrOff, "void* __attribute__((optimize(\"O0\"))) ", strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_664+currStrOff, efn->name, strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_664+currStrOff, "(array(void*)* fnArgs) {\n        if (fnArgs->length != ", strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_664+currStrOff, ____BAH_COMPILER_VAR_665, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_664+currStrOff, ") {\n            __BAH_panic((char*)\"eval: calling function ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_664+currStrOff, fn->name, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_664+currStrOff, "() with the wrong number of arguments.\", \"BAH_COMPILER_INTERNAL\");\n        }\n        ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_664+currStrOff, fnBinding, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_664+currStrOff, "\n        ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_664+currStrOff, setReturnValue, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_664+currStrOff, fnCall, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_664+currStrOff, ");\n        return (void*)r;\n    };", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_664));

{
long nLength = len(compilerState.evals);
if (compilerState.evals->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(compilerState.evals->data, (nLength+50)*sizeof(char *));
compilerState.evals->data = newPtr;
}
compilerState.evals->data[len(compilerState.evals)] = fn->name;
compilerState.evals->length = nLength+1;
} else {
compilerState.evals->data[len(compilerState.evals)] = fn->name;
}
};

{
long nLength = len(elems->fns);
if (elems->fns->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(elems->fns->data, (nLength+50)*sizeof(struct func*));
elems->fns->data = newPtr;
}
elems->fns->data[len(elems->fns)] = efn;
elems->fns->length = nLength+1;
} else {
elems->fns->data[len(elems->fns)] = efn;
}
};
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
msg.trimLeft(&msg,1);
msg.trimRight(&msg,1);
char * ____BAH_COMPILER_VAR_666 =msg.str(&msg);throwWarning(____BAH_COMPILER_VAR_666);
return;
}
if ((strcmp(ft.cont, "#eval") == 0)) {

        char ____BAH_COMPILER_VAR_667 = 0;
        for(int i=compilerState.includes->length-1; i!=-1;i--) {
            if (compilerState.includes->data[i] != 0 && strcmp(compilerState.includes->data[i], "eval.bah") == 0) {
                ____BAH_COMPILER_VAR_667=1;
                break;
            };
        }
        if ((____BAH_COMPILER_VAR_667==false)) {
if ((includeFile("eval.bah",elems)==false)) {
char * ____BAH_COMPILER_VAR_668 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen(").");
long int strLen_2 = strlen("Could not find file 'eval.bah'. Check your bah directory (");
;                            
            ____BAH_COMPILER_VAR_668 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_668+currStrOff, "Could not find file 'eval.bah'. Check your bah directory (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_668+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_668+currStrOff, ").", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&l->data[0],____BAH_COMPILER_VAR_668);
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
for (; (i<len(elems->fns)); i++) {
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
isOS.trimLeft(&isOS,1);
if ((strcmp(isOS.str(&isOS), BAH_OS) != 0)) {
return;
}
}
else if ((strcmp(ft.cont, "#static") == 0)) {
if ((flags.isSet(&flags,"d")==1)) {
return;
}
}
else if ((strcmp(ft.cont, "#dynamic") == 0)) {
if ((flags.isSet(&flags,"d")==0)) {
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
if ((flags.isSet(&flags,"l")==0)) {
return;
}
}
else if ((strcmp(ft.cont, "#exec") == 0)) {
if ((flags.isSet(&flags,"l")==1)) {
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

{
long nLength = i-2;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[i-2] = l->data[i];
nl->length = nLength+1;
} else {
nl->data[i-2] = l->data[i];
}
};
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

{
long nLength = len(compilerState.cLibs);
if (compilerState.cLibs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(compilerState.cLibs->data, (nLength+50)*sizeof(char *));
compilerState.cLibs->data = newPtr;
}
compilerState.cLibs->data[len(compilerState.cLibs)] = "lpthread";
compilerState.cLibs->length = nLength+1;
} else {
compilerState.cLibs->data[len(compilerState.cLibs)] = "lpthread";
}
};
}
struct string sFnT = string(fnT.cont);
array(struct string)* fnNameParts = splitString(sFnT,"(");
struct string fnName = fnNameParts->data[0];
char * ____BAH_COMPILER_VAR_669 =fnName.str(&fnName);struct func* fn = searchFunc(____BAH_COMPILER_VAR_669,elems,true);
if ((fn==null)) {
char * ____BAH_COMPILER_VAR_670 =null;char * ____BAH_COMPILER_VAR_671 =fnName.str(&fnName);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_671);
long int strLen_1 = strlen("', arround {TOKEN}.");
long int strLen_2 = strlen("Internal compiler error.\n Error parsing async call for function '");
;                            
            ____BAH_COMPILER_VAR_670 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_670+currStrOff, "Internal compiler error.\n Error parsing async call for function '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_670+currStrOff, ____BAH_COMPILER_VAR_671, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_670+currStrOff, "', arround {TOKEN}.", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_672 =____BAH_COMPILER_VAR_670;throwErr(&fnT,____BAH_COMPILER_VAR_672);
}
char * sMembs = "";
char * unSerMembs = "";
i = 0;
while ((i<len(fn->args))) {
struct variable* a = fn->args->data[i];
struct string cType = getCType(a->type,elems);
char * ____BAH_COMPILER_VAR_673 =null;char * ____BAH_COMPILER_VAR_674 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(a->name);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_674);
long int strLen_4 = strlen(sMembs);
;                            
            ____BAH_COMPILER_VAR_673 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_673+currStrOff, sMembs, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_673+currStrOff, ____BAH_COMPILER_VAR_674, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_673+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_673+currStrOff, a->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_673+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }sMembs = ____BAH_COMPILER_VAR_673;
char * ____BAH_COMPILER_VAR_675 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("args->");
long int strLen_1 = strlen(a->name);
long int strLen_2 = strlen(unSerMembs);
;                            
            ____BAH_COMPILER_VAR_675 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_675+currStrOff, unSerMembs, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_675+currStrOff, "args->", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_675+currStrOff, a->name, strLen_1);
            currStrOff += strLen_1;
        
        }unSerMembs = ____BAH_COMPILER_VAR_675;
i = i+1;
if ((i<len(fn->args))) {
char * ____BAH_COMPILER_VAR_676 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(unSerMembs);
long int strLen_1 = strlen(", ");
;                            
            ____BAH_COMPILER_VAR_676 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_676+currStrOff, unSerMembs, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_676+currStrOff, ", ", strLen_1);
            currStrOff += strLen_1;
        
        }unSerMembs = ____BAH_COMPILER_VAR_676;
}
};
char * ____BAH_COMPILER_VAR_677 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(sMembs);
long int strLen_1 = strlen("}");
long int strLen_2 = strlen("struct {\n");
;                            
            ____BAH_COMPILER_VAR_677 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_677+currStrOff, "struct {\n", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_677+currStrOff, sMembs, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_677+currStrOff, "}", strLen_1);
            currStrOff += strLen_1;
        
        }char * tmpArgsStruct = ____BAH_COMPILER_VAR_677;
char * fnWrapper = genCompilerVar();
char * tmpArgs = genCompilerVar();
sFnT.trimLeft(&sFnT,fnName.length+1);
sFnT.trimRight(&sFnT,1);
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
char * ____BAH_COMPILER_VAR_678 =null;char * ____BAH_COMPILER_VAR_679 =sFnT.str(&sFnT);char * ____BAH_COMPILER_VAR_680 =fnName.str(&fnName);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpArgs);
long int strLen_1 = strlen(");\n    }; \n    \n    ");
long int strLen_2 = strlen(", &");
long int strLen_3 = strlen(fnWrapper);
long int strLen_4 = strlen("(&id, 0, ");
long int strLen_5 = strlen(tCreate);
long int strLen_6 = strlen("};\n        pthread_t id;\n        ");
long int strLen_7 = strlen(____BAH_COMPILER_VAR_679);
long int strLen_8 = strlen(" = {");
long int strLen_9 = strlen(tmpArgs);
long int strLen_10 = strlen(" ");
long int strLen_11 = strlen(tmpArgsStruct);
long int strLen_12 = strlen(");\n    };\n    {\n        ");
long int strLen_13 = strlen(unSerMembs);
long int strLen_14 = strlen("(");
long int strLen_15 = strlen(____BAH_COMPILER_VAR_680);
long int strLen_16 = strlen("* args) {\n        ");
long int strLen_17 = strlen(tmpArgsStruct);
long int strLen_18 = strlen("(");
long int strLen_19 = strlen(fnWrapper);
long int strLen_20 = strlen("\n    void ");
;                            
            ____BAH_COMPILER_VAR_678 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13+strLen_14+strLen_15+strLen_16+strLen_17+strLen_18+strLen_19+strLen_20);
            
                    memcpy(____BAH_COMPILER_VAR_678+currStrOff, "\n    void ", strLen_20);
                    currStrOff += strLen_20;
                    
                    memcpy(____BAH_COMPILER_VAR_678+currStrOff, fnWrapper, strLen_19);
                    currStrOff += strLen_19;
                    
                    memcpy(____BAH_COMPILER_VAR_678+currStrOff, "(", strLen_18);
                    currStrOff += strLen_18;
                    
                    memcpy(____BAH_COMPILER_VAR_678+currStrOff, tmpArgsStruct, strLen_17);
                    currStrOff += strLen_17;
                    
                    memcpy(____BAH_COMPILER_VAR_678+currStrOff, "* args) {\n        ", strLen_16);
                    currStrOff += strLen_16;
                    
                    memcpy(____BAH_COMPILER_VAR_678+currStrOff, ____BAH_COMPILER_VAR_680, strLen_15);
                    currStrOff += strLen_15;
                    
                    memcpy(____BAH_COMPILER_VAR_678+currStrOff, "(", strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_678+currStrOff, unSerMembs, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_678+currStrOff, ");\n    };\n    {\n        ", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_678+currStrOff, tmpArgsStruct, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_678+currStrOff, " ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_678+currStrOff, tmpArgs, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_678+currStrOff, " = {", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_678+currStrOff, ____BAH_COMPILER_VAR_679, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_678+currStrOff, "};\n        pthread_t id;\n        ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_678+currStrOff, tCreate, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_678+currStrOff, "(&id, 0, ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_678+currStrOff, fnWrapper, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_678+currStrOff, ", &", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_678+currStrOff, tmpArgs, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_678+currStrOff, ");\n    }; \n    \n    ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_678));
};
void addRCPvars(__BAH_ARR_TYPE_Tok l,lineType ltp,struct Elems* elems){
register long int i = 0;
if ((ltp==LINE_TYPE_VAR)) {
i = 1;
}
while ((i<len(l))) {
struct Tok t = l->data[i];
if ((t.type==TOKEN_TYPE_VAR)&&(t.isOper==false)) {
struct variable* v = searchVarByToken(t,elems);
if ((v!=null)) {

{
long nLength = len(compilerState.RCPvars);
if (compilerState.RCPvars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(compilerState.RCPvars->data, (nLength+50)*sizeof(struct variable*));
compilerState.RCPvars->data = newPtr;
}
compilerState.RCPvars->data[len(compilerState.RCPvars)] = v;
compilerState.RCPvars->length = nLength+1;
} else {
compilerState.RCPvars->data[len(compilerState.RCPvars)] = v;
}
};
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
for (; (i<len(l)); i++) {
struct Tok t = l->data[i];
if ((t.type==TOKEN_TYPE_SYNTAX)&&(strcmp(t.cont, "->") == 0)||(strcmp(t.cont, "<-") == 0)) {
if ((strcmp(t.cont, "<-") == 0)) {
i++;
if ((i<len(l))) {
struct Tok nt = l->data[i];
if ((nt.type!=TOKEN_TYPE_VAR)) {
throwErr(&nt,"Cannot use {TOKEN} as channel.");
}
char * ____BAH_COMPILER_VAR_681 =getTypeFromToken(&nt,true,elems);struct string ntt = string(____BAH_COMPILER_VAR_681);
if ((ntt.hasPrefix(&ntt,"chan:")==0)) {
char * ____BAH_COMPILER_VAR_682 =null;char * ____BAH_COMPILER_VAR_683 =ntt.str(&ntt);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_683);
long int strLen_1 = strlen(") as channel.");
long int strLen_2 = strlen("Cannot use var {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_682 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_682+currStrOff, "Cannot use var {TOKEN} (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_682+currStrOff, ____BAH_COMPILER_VAR_683, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_682+currStrOff, ") as channel.", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_684 =____BAH_COMPILER_VAR_682;throwErr(&nt,____BAH_COMPILER_VAR_684);
}
ntt.trimLeft(&ntt,5);
if (isGlobal()) {
throwErr(&t,"Cannot receive ({TOKEN}) from a channel outside of a function.");
}
char * tmpV = "";
char * ____BAH_COMPILER_VAR_685 =ntt.str(&ntt);if (isRCPpointerType(____BAH_COMPILER_VAR_685)) {
char * ____BAH_COMPILER_VAR_686 =ntt.str(&ntt);struct string ct = getCType(____BAH_COMPILER_VAR_686,elems);
char * ____BAH_COMPILER_VAR_687 =null;char * ____BAH_COMPILER_VAR_688 =ct.str(&ct);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen("->receive(");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen(")");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_688);
long int strLen_6 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_687 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_687+currStrOff, "(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_687+currStrOff, ____BAH_COMPILER_VAR_688, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_687+currStrOff, ")", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_687+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_687+currStrOff, "->receive(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_687+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_687+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_687;
}
else {
char * ____BAH_COMPILER_VAR_689 =ntt.str(&ntt);struct string ct = getCType(____BAH_COMPILER_VAR_689,elems);
if (RCPavailable()) {
char * ____BAH_COMPILER_VAR_690 =null;char * ____BAH_COMPILER_VAR_691 =ntt.str(&ntt);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_691);
long int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_690 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_690+currStrOff, ____BAH_COMPILER_VAR_691, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_690+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_692 =null;char * ____BAH_COMPILER_VAR_693 =ct.str(&ct);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen("->receive(");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen("*)");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_693);
long int strLen_6 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_692 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_692+currStrOff, "(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_692+currStrOff, ____BAH_COMPILER_VAR_693, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_692+currStrOff, "*)", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_692+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_692+currStrOff, "->receive(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_692+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_692+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_694 =____BAH_COMPILER_VAR_690;tmpV = registerRCPvar(____BAH_COMPILER_VAR_694,____BAH_COMPILER_VAR_692,elems);
char * ____BAH_COMPILER_VAR_695 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("*");
long int strLen_1 = strlen(tmpV);
;                            
            ____BAH_COMPILER_VAR_695 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_695+currStrOff, "*", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_695+currStrOff, tmpV, strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_695;
}
else {
char * ____BAH_COMPILER_VAR_696 =null;char * ____BAH_COMPILER_VAR_697 =ct.str(&ct);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen("->receive(");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen("*)");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_697);
long int strLen_6 = strlen("*(");
;                            
            ____BAH_COMPILER_VAR_696 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_696+currStrOff, "*(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_696+currStrOff, ____BAH_COMPILER_VAR_697, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_696+currStrOff, "*)", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_696+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_696+currStrOff, "->receive(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_696+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_696+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_696;
}
}
t.type = TOKEN_TYPE_FUNC;
t.isFunc = true;
if (RCPavailable()) {
char * ____BAH_COMPILER_VAR_698 =ntt.str(&ntt);if (isRCPpointerType(____BAH_COMPILER_VAR_698)) {
char * ____BAH_COMPILER_VAR_699 =ntt.str(&ntt);tmpV = registerRCPvar(____BAH_COMPILER_VAR_699,t.cont,elems);
t.type = TOKEN_TYPE_VAR;
t.isFunc = false;
t.cont = tmpV;
}
else {
}
}
t.isValue = true;
t.bahType = ntt.str(&ntt);
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
char * ____BAH_COMPILER_VAR_700 =getTypeFromToken(&pt,true,elems);struct string ptt = string(____BAH_COMPILER_VAR_700);
if ((ptt.hasPrefix(&ptt,"chan:")==0)) {
char * ____BAH_COMPILER_VAR_701 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ntt);
long int strLen_1 = strlen(") as channel.");
long int strLen_2 = strlen("Cannot use var {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_701 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_701+currStrOff, "Cannot use var {TOKEN} (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_701+currStrOff, ntt, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_701+currStrOff, ") as channel.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&pt,____BAH_COMPILER_VAR_701);
}
ptt.trimLeft(&ptt,5);
if (isGlobal()) {
throwErr(&t,"Cannot send ({TOKEN}) to a channel outside of a function.");
}
char * ____BAH_COMPILER_VAR_702 =ptt.str(&ptt);if ((compTypes(____BAH_COMPILER_VAR_702,ntt)==false)) {
char * ____BAH_COMPILER_VAR_703 =null;char * ____BAH_COMPILER_VAR_704 =ptt.str(&ptt);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_704);
long int strLen_1 = strlen(".");
long int strLen_2 = strlen(") to channel of type ");
long int strLen_3 = strlen(ntt);
long int strLen_4 = strlen("Cannot send {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_703 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_703+currStrOff, "Cannot send {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_703+currStrOff, ntt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_703+currStrOff, ") to channel of type ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_703+currStrOff, ____BAH_COMPILER_VAR_704, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_703+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_705 =____BAH_COMPILER_VAR_703;throwErr(&nt,____BAH_COMPILER_VAR_705);
}
i++;
char * ____BAH_COMPILER_VAR_706 =ptt.str(&ptt);if (isRCPpointerType(____BAH_COMPILER_VAR_706)) {
char * ____BAH_COMPILER_VAR_707 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen(");\n");
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(pt.cont);
long int strLen_4 = strlen("->send(");
long int strLen_5 = strlen(pt.cont);
;                            
            ____BAH_COMPILER_VAR_707 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_707+currStrOff, pt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_707+currStrOff, "->send(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_707+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_707+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_707+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_707+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_707));
}
else {
struct string ct = getCType(ntt,elems);
char * tmpV = genCompilerVar();
char * ____BAH_COMPILER_VAR_708 =null;char * ____BAH_COMPILER_VAR_709 =ct.str(&ct);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpV);
long int strLen_1 = strlen("));\n");
long int strLen_2 = strlen(", sizeof(");
long int strLen_3 = strlen(tmpV);
long int strLen_4 = strlen(", &");
long int strLen_5 = strlen(pt.cont);
long int strLen_6 = strlen("->sendAny(");
long int strLen_7 = strlen(pt.cont);
long int strLen_8 = strlen(";\n                    ");
long int strLen_9 = strlen(nt.cont);
long int strLen_10 = strlen(" = ");
long int strLen_11 = strlen(tmpV);
long int strLen_12 = strlen(" ");
long int strLen_13 = strlen(____BAH_COMPILER_VAR_709);
long int strLen_14 = strlen("\n                    ");
;                            
            ____BAH_COMPILER_VAR_708 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13+strLen_14);
            
                    memcpy(____BAH_COMPILER_VAR_708+currStrOff, "\n                    ", strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_708+currStrOff, ____BAH_COMPILER_VAR_709, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_708+currStrOff, " ", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_708+currStrOff, tmpV, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_708+currStrOff, " = ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_708+currStrOff, nt.cont, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_708+currStrOff, ";\n                    ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_708+currStrOff, pt.cont, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_708+currStrOff, "->sendAny(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_708+currStrOff, pt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_708+currStrOff, ", &", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_708+currStrOff, tmpV, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_708+currStrOff, ", sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_708+currStrOff, tmpV, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_708+currStrOff, "));\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_708));
}
nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
return nl;
}
}

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] = t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] = t;
}
};
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
tokPos++;
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
for (; (i<len(l)); i++) {
struct Tok t = l->data[i];
char * ____BAH_COMPILER_VAR_710 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnt.ogCont);
long int strLen_1 = strlen(t.ogCont);
;                            
            ____BAH_COMPILER_VAR_710 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_710+currStrOff, fnt.ogCont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_710+currStrOff, t.ogCont, strLen_1);
            currStrOff += strLen_1;
        
        }fnt.ogCont = ____BAH_COMPILER_VAR_710;
if ((strcmp(t.cont, "(") == 0)||(strcmp(t.cont, "{") == 0)||(strcmp(t.cont, "[") == 0)) {
nbEncls++;
}
else if ((strcmp(t.cont, ")") == 0)||(strcmp(t.cont, "}") == 0)||(strcmp(t.cont, "]") == 0)) {
nbEncls--;
if ((nbEncls==0)) {
break;
}
}

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] = t;
memory->length = nLength+1;
} else {
memory->data[len(memory)] = t;
}
};
};
deleteRange(l,tokPos+1,i);
array(struct Tok)* memort = prePross(memory,(lineType)-1,elems);
struct Tok ft = memory->data[0];
fnt.cont = "(";
fnt.isOper = true;
fnt.isValue = true;
fnt.bahType = getTypeFromToken(&ft,true,elems);
register long int j = 0;
for (; (j<len(memory)); j++) {
struct Tok t = memory->data[j];
char * ____BAH_COMPILER_VAR_711 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnt.cont);
long int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_711 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_711+currStrOff, fnt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_711+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_711;
};
char * ____BAH_COMPILER_VAR_712 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnt.cont);
long int strLen_1 = strlen(")");
;                            
            ____BAH_COMPILER_VAR_712 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_712+currStrOff, fnt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_712+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_712;

{
long nLength = tokPos;
if (l->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(l->data, (nLength+50)*sizeof(struct Tok));
l->data = newPtr;
}
l->data[tokPos] = fnt;
l->length = nLength+1;
} else {
l->data[tokPos] = fnt;
}
};
return tokPos;
}
char * ____BAH_COMPILER_VAR_713 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fn->name);
long int strLen_1 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_713 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_713+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_713+currStrOff, "(", strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_713;
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
char * ____BAH_COMPILER_VAR_714 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fn->name);
long int strLen_1 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_714 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_714+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_714+currStrOff, "(", strLen_1);
            currStrOff += strLen_1;
        
        }fnt.ogCont = ____BAH_COMPILER_VAR_714;
for (; (i<len(l)); i++) {
struct Tok t = l->data[i];
char * ____BAH_COMPILER_VAR_715 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnt.ogCont);
long int strLen_1 = strlen(t.ogCont);
;                            
            ____BAH_COMPILER_VAR_715 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_715+currStrOff, fnt.ogCont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_715+currStrOff, t.ogCont, strLen_1);
            currStrOff += strLen_1;
        
        }fnt.ogCont = ____BAH_COMPILER_VAR_715;
if ((strcmp(t.cont, "(") == 0)||(strcmp(t.cont, "{") == 0)||(strcmp(t.cont, "[") == 0)) {
nbEncls++;
}
else if ((strcmp(t.cont, ")") == 0)||(strcmp(t.cont, "}") == 0)||(strcmp(t.cont, "]") == 0)) {
nbEncls--;
if ((nbEncls==0)) {
break;
}
}

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] = t;
memory->length = nLength+1;
} else {
memory->data[len(memory)] = t;
}
};
};
deleteRange(l,tokPos+1,i);
if ((strcmp(fn->name, "noCheck") == 0)) {
fnt.cont = "";
fnt.isOper = true;
fnt.isValue = true;
fnt.bahType = "ptr";
register long int j = 0;
for (; (j<len(memory)); j++) {
struct Tok t = memory->data[j];
char * ____BAH_COMPILER_VAR_716 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnt.cont);
long int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_716 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_716+currStrOff, fnt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_716+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_716;
};

{
long nLength = tokPos;
if (l->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(l->data, (nLength+50)*sizeof(struct Tok));
l->data = newPtr;
}
l->data[tokPos] = fnt;
l->length = nLength+1;
} else {
l->data[tokPos] = fnt;
}
};
return tokPos;
}
char * ____BAH_COMPILER_VAR_717 =null;char * ____BAH_COMPILER_VAR_718 =intToStr(fnt.line);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_718);
long int strLen_1 = strlen("\"");
long int strLen_2 = strlen(":");
long int strLen_3 = strlen(compilerState.currentFile);
long int strLen_4 = strlen("\"");
;                            
            ____BAH_COMPILER_VAR_717 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_717+currStrOff, "\"", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_717+currStrOff, compilerState.currentFile, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_717+currStrOff, ":", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_717+currStrOff, ____BAH_COMPILER_VAR_718, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_717+currStrOff, "\"", strLen_1);
            currStrOff += strLen_1;
        
        }char * currLine = ____BAH_COMPILER_VAR_717;
if ((strcmp(fn->name, "panic") == 0)) {
struct Tok ____BAH_COMPILER_VAR_719 = {};
____BAH_COMPILER_VAR_719.cont = "";
____BAH_COMPILER_VAR_719.ogCont = "";
____BAH_COMPILER_VAR_719.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_719.pos = 0;
____BAH_COMPILER_VAR_719.line = 1;
____BAH_COMPILER_VAR_719.begLine = 1;
____BAH_COMPILER_VAR_719.bahType = "";
____BAH_COMPILER_VAR_719.isValue = false;
____BAH_COMPILER_VAR_719.isFunc = false;
____BAH_COMPILER_VAR_719.isOper = false;
____BAH_COMPILER_VAR_719.isEqual = false;
____BAH_COMPILER_VAR_719.pass = false;
____BAH_COMPILER_VAR_719.bahRef= null;
____BAH_COMPILER_VAR_719.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_719.cont = ",";
____BAH_COMPILER_VAR_719.line = fnt.line;

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] = ____BAH_COMPILER_VAR_719;
memory->length = nLength+1;
} else {
memory->data[len(memory)] = ____BAH_COMPILER_VAR_719;
}
};
struct Tok ____BAH_COMPILER_VAR_720 = {};
____BAH_COMPILER_VAR_720.cont = "";
____BAH_COMPILER_VAR_720.ogCont = "";
____BAH_COMPILER_VAR_720.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_720.pos = 0;
____BAH_COMPILER_VAR_720.line = 1;
____BAH_COMPILER_VAR_720.begLine = 1;
____BAH_COMPILER_VAR_720.bahType = "";
____BAH_COMPILER_VAR_720.isValue = false;
____BAH_COMPILER_VAR_720.isFunc = false;
____BAH_COMPILER_VAR_720.isOper = false;
____BAH_COMPILER_VAR_720.isEqual = false;
____BAH_COMPILER_VAR_720.pass = false;
____BAH_COMPILER_VAR_720.bahRef= null;
____BAH_COMPILER_VAR_720.type = TOKEN_TYPE_STR;
____BAH_COMPILER_VAR_720.cont = currLine;
____BAH_COMPILER_VAR_720.line = fnt.line;

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] = ____BAH_COMPILER_VAR_720;
memory->length = nLength+1;
} else {
memory->data[len(memory)] = ____BAH_COMPILER_VAR_720;
}
};
fn = searchFunc("__BAH_panic",elems,true);
char * ____BAH_COMPILER_VAR_721 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fn->name);
long int strLen_1 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_721 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_721+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_721+currStrOff, "(", strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_721;
}
else if ((strcmp(fn->name, "__dumpSymbols") == 0)) {
array(struct variable*)* symbols = memoryAlloc(sizeof(array(struct variable*)));

symbols->length = 0;
symbols->elemSize = sizeof(struct variable*);
register long int j = 0;
for (; (j<len(elems->vars)); j++) {
struct variable* v = elems->vars->data[j];
if ((v->isConst==false)) {

{
long nLength = len(symbols);
if (symbols->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(symbols->data, (nLength+50)*sizeof(struct variable*));
symbols->data = newPtr;
}
symbols->data[len(symbols)] = v;
symbols->length = nLength+1;
} else {
symbols->data[len(symbols)] = v;
}
};
}
};
struct variable* ____BAH_COMPILER_VAR_722 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_722->name = "";
____BAH_COMPILER_VAR_722->type = "";
____BAH_COMPILER_VAR_722->isConst = false;
____BAH_COMPILER_VAR_722->constVal = "";
____BAH_COMPILER_VAR_722->isArray = false;
____BAH_COMPILER_VAR_722->from = "";
____BAH_COMPILER_VAR_722->declScope= null;
____BAH_COMPILER_VAR_722->isGlobal = false;
____BAH_COMPILER_VAR_722->declRope= null;
____BAH_COMPILER_VAR_722->isReg = false;
____BAH_COMPILER_VAR_722->name = genCompilerVar();
____BAH_COMPILER_VAR_722->type = "[]reflectElement";
____BAH_COMPILER_VAR_722->isArray = true;
struct variable* tmpV = ____BAH_COMPILER_VAR_722;
char * decls = "";
j = 0;
for (; (j<len(symbols)); j++) {
struct variable* v = symbols->data[j];
char * vname = v->name;
if ((strCount(v->type,"*")==0)) {
char * ____BAH_COMPILER_VAR_723 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("&");
long int strLen_1 = strlen(v->name);
;                            
            ____BAH_COMPILER_VAR_723 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_723+currStrOff, "&", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_723+currStrOff, v->name, strLen_1);
            currStrOff += strLen_1;
        
        }vname = ____BAH_COMPILER_VAR_723;
}
struct Tok ____BAH_COMPILER_VAR_724 = {};
____BAH_COMPILER_VAR_724.cont = "";
____BAH_COMPILER_VAR_724.ogCont = "";
____BAH_COMPILER_VAR_724.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_724.pos = 0;
____BAH_COMPILER_VAR_724.line = 1;
____BAH_COMPILER_VAR_724.begLine = 1;
____BAH_COMPILER_VAR_724.bahType = "";
____BAH_COMPILER_VAR_724.isValue = false;
____BAH_COMPILER_VAR_724.isFunc = false;
____BAH_COMPILER_VAR_724.isOper = false;
____BAH_COMPILER_VAR_724.isEqual = false;
____BAH_COMPILER_VAR_724.pass = false;
____BAH_COMPILER_VAR_724.bahRef= null;
____BAH_COMPILER_VAR_724.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_724.cont = vname;
____BAH_COMPILER_VAR_724.bahType = v->type;
____BAH_COMPILER_VAR_724.isValue = true;
#define tmpT ____BAH_COMPILER_VAR_724
tmpT = parseReflect(tmpT,v->type,elems,true,v->name,"0");
char * ____BAH_COMPILER_VAR_725 =null;char * ____BAH_COMPILER_VAR_726 =intToStr(j);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpT.cont);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen("] = ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_726);
long int strLen_4 = strlen("->data[");
long int strLen_5 = strlen(tmpV->name);
;                            
            ____BAH_COMPILER_VAR_725 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_725+currStrOff, tmpV->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_725+currStrOff, "->data[", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_725+currStrOff, ____BAH_COMPILER_VAR_726, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_725+currStrOff, "] = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_725+currStrOff, tmpT.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_725+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_727 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(decls);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_725);
;                            
            ____BAH_COMPILER_VAR_727 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_727+currStrOff, decls, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_727+currStrOff, ____BAH_COMPILER_VAR_725, strLen_1);
            currStrOff += strLen_1;
        
        }decls = ____BAH_COMPILER_VAR_727;

#undef tmpT
};

{
long nLength = len(elems->vars);
if (elems->vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(elems->vars->data, (nLength+50)*sizeof(struct variable*));
elems->vars->data = newPtr;
}
elems->vars->data[len(elems->vars)] = tmpV;
elems->vars->length = nLength+1;
} else {
elems->vars->data[len(elems->vars)] = tmpV;
}
};
char * ____BAH_COMPILER_VAR_728 =null;char * ____BAH_COMPILER_VAR_729 =intToStr(len(symbols));char * ____BAH_COMPILER_VAR_730 =intToStr(len(symbols));
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(decls);
long int strLen_1 = strlen("\n        ");
long int strLen_2 = strlen("->elemSize = sizeof(struct reflectElement);\n        ");
long int strLen_3 = strlen(tmpV->name);
long int strLen_4 = strlen(";\n        ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_729);
long int strLen_6 = strlen("->length = ");
long int strLen_7 = strlen(tmpV->name);
long int strLen_8 = strlen(");\n        ");
long int strLen_9 = strlen(____BAH_COMPILER_VAR_730);
long int strLen_10 = strlen("->data = memoryAlloc(sizeof(struct reflectElement) * ");
long int strLen_11 = strlen(tmpV->name);
long int strLen_12 = strlen(" = memoryAlloc(sizeof(array(struct reflectElement)));\n        ");
long int strLen_13 = strlen(tmpV->name);
long int strLen_14 = strlen("\n        array(struct reflectElement)* ");
;                            
            ____BAH_COMPILER_VAR_728 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13+strLen_14);
            
                    memcpy(____BAH_COMPILER_VAR_728+currStrOff, "\n        array(struct reflectElement)* ", strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_728+currStrOff, tmpV->name, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_728+currStrOff, " = memoryAlloc(sizeof(array(struct reflectElement)));\n        ", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_728+currStrOff, tmpV->name, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_728+currStrOff, "->data = memoryAlloc(sizeof(struct reflectElement) * ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_728+currStrOff, ____BAH_COMPILER_VAR_730, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_728+currStrOff, ");\n        ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_728+currStrOff, tmpV->name, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_728+currStrOff, "->length = ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_728+currStrOff, ____BAH_COMPILER_VAR_729, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_728+currStrOff, ";\n        ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_728+currStrOff, tmpV->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_728+currStrOff, "->elemSize = sizeof(struct reflectElement);\n        ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_728+currStrOff, decls, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_728+currStrOff, "\n        ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_728));
struct Tok ____BAH_COMPILER_VAR_731 = {};
____BAH_COMPILER_VAR_731.cont = "";
____BAH_COMPILER_VAR_731.ogCont = "";
____BAH_COMPILER_VAR_731.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_731.pos = 0;
____BAH_COMPILER_VAR_731.line = 1;
____BAH_COMPILER_VAR_731.begLine = 1;
____BAH_COMPILER_VAR_731.bahType = "";
____BAH_COMPILER_VAR_731.isValue = false;
____BAH_COMPILER_VAR_731.isFunc = false;
____BAH_COMPILER_VAR_731.isOper = false;
____BAH_COMPILER_VAR_731.isEqual = false;
____BAH_COMPILER_VAR_731.pass = false;
____BAH_COMPILER_VAR_731.bahRef= null;
____BAH_COMPILER_VAR_731.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_731.cont = tmpV->name;
____BAH_COMPILER_VAR_731.line = fnt.line;
____BAH_COMPILER_VAR_731.isValue = true;

{
long nLength = 0;
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[0] = ____BAH_COMPILER_VAR_731;
memory->length = nLength+1;
} else {
memory->data[0] = ____BAH_COMPILER_VAR_731;
}
};
}
else if ((strcmp(fn->name, "breakPoint") == 0)) {
struct Tok ____BAH_COMPILER_VAR_732 = {};
____BAH_COMPILER_VAR_732.cont = "";
____BAH_COMPILER_VAR_732.ogCont = "";
____BAH_COMPILER_VAR_732.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_732.pos = 0;
____BAH_COMPILER_VAR_732.line = 1;
____BAH_COMPILER_VAR_732.begLine = 1;
____BAH_COMPILER_VAR_732.bahType = "";
____BAH_COMPILER_VAR_732.isValue = false;
____BAH_COMPILER_VAR_732.isFunc = false;
____BAH_COMPILER_VAR_732.isOper = false;
____BAH_COMPILER_VAR_732.isEqual = false;
____BAH_COMPILER_VAR_732.pass = false;
____BAH_COMPILER_VAR_732.bahRef= null;
____BAH_COMPILER_VAR_732.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_732.cont = "__dumpSymbols";
____BAH_COMPILER_VAR_732.line = fnt.line;
struct Tok ____BAH_COMPILER_VAR_733 = {};
____BAH_COMPILER_VAR_733.cont = "";
____BAH_COMPILER_VAR_733.ogCont = "";
____BAH_COMPILER_VAR_733.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_733.pos = 0;
____BAH_COMPILER_VAR_733.line = 1;
____BAH_COMPILER_VAR_733.begLine = 1;
____BAH_COMPILER_VAR_733.bahType = "";
____BAH_COMPILER_VAR_733.isValue = false;
____BAH_COMPILER_VAR_733.isFunc = false;
____BAH_COMPILER_VAR_733.isOper = false;
____BAH_COMPILER_VAR_733.isEqual = false;
____BAH_COMPILER_VAR_733.pass = false;
____BAH_COMPILER_VAR_733.bahRef= null;
____BAH_COMPILER_VAR_733.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_733.cont = "(";
____BAH_COMPILER_VAR_733.line = fnt.line;
struct Tok ____BAH_COMPILER_VAR_734 = {};
____BAH_COMPILER_VAR_734.cont = "";
____BAH_COMPILER_VAR_734.ogCont = "";
____BAH_COMPILER_VAR_734.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_734.pos = 0;
____BAH_COMPILER_VAR_734.line = 1;
____BAH_COMPILER_VAR_734.begLine = 1;
____BAH_COMPILER_VAR_734.bahType = "";
____BAH_COMPILER_VAR_734.isValue = false;
____BAH_COMPILER_VAR_734.isFunc = false;
____BAH_COMPILER_VAR_734.isOper = false;
____BAH_COMPILER_VAR_734.isEqual = false;
____BAH_COMPILER_VAR_734.pass = false;
____BAH_COMPILER_VAR_734.bahRef= null;
____BAH_COMPILER_VAR_734.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_734.cont = ")";
____BAH_COMPILER_VAR_734.line = fnt.line;
memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 3;
memory->elemSize = sizeof(struct Tok);
memory->data = memoryAlloc(sizeof(struct Tok) * 50);memory->data[0] = ____BAH_COMPILER_VAR_732;
memory->data[1] = ____BAH_COMPILER_VAR_733;
memory->data[2] = ____BAH_COMPILER_VAR_734;
memory = prePross(memory,LINE_TYPE_FN_CALL,elems);
struct Tok ____BAH_COMPILER_VAR_735 = {};
____BAH_COMPILER_VAR_735.cont = "";
____BAH_COMPILER_VAR_735.ogCont = "";
____BAH_COMPILER_VAR_735.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_735.pos = 0;
____BAH_COMPILER_VAR_735.line = 1;
____BAH_COMPILER_VAR_735.begLine = 1;
____BAH_COMPILER_VAR_735.bahType = "";
____BAH_COMPILER_VAR_735.isValue = false;
____BAH_COMPILER_VAR_735.isFunc = false;
____BAH_COMPILER_VAR_735.isOper = false;
____BAH_COMPILER_VAR_735.isEqual = false;
____BAH_COMPILER_VAR_735.pass = false;
____BAH_COMPILER_VAR_735.bahRef= null;
____BAH_COMPILER_VAR_735.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_735.cont = ",";
____BAH_COMPILER_VAR_735.line = fnt.line;

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] = ____BAH_COMPILER_VAR_735;
memory->length = nLength+1;
} else {
memory->data[len(memory)] = ____BAH_COMPILER_VAR_735;
}
};
struct Tok ____BAH_COMPILER_VAR_736 = {};
____BAH_COMPILER_VAR_736.cont = "";
____BAH_COMPILER_VAR_736.ogCont = "";
____BAH_COMPILER_VAR_736.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_736.pos = 0;
____BAH_COMPILER_VAR_736.line = 1;
____BAH_COMPILER_VAR_736.begLine = 1;
____BAH_COMPILER_VAR_736.bahType = "";
____BAH_COMPILER_VAR_736.isValue = false;
____BAH_COMPILER_VAR_736.isFunc = false;
____BAH_COMPILER_VAR_736.isOper = false;
____BAH_COMPILER_VAR_736.isEqual = false;
____BAH_COMPILER_VAR_736.pass = false;
____BAH_COMPILER_VAR_736.bahRef= null;
____BAH_COMPILER_VAR_736.type = TOKEN_TYPE_STR;
____BAH_COMPILER_VAR_736.cont = currLine;
____BAH_COMPILER_VAR_736.line = fnt.line;

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] = ____BAH_COMPILER_VAR_736;
memory->length = nLength+1;
} else {
memory->data[len(memory)] = ____BAH_COMPILER_VAR_736;
}
};
fn = searchFunc("breakPoint__inner",elems,true);
char * ____BAH_COMPILER_VAR_737 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fn->name);
long int strLen_1 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_737 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_737+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_737+currStrOff, "(", strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_737;
}
else if ((strcmp(fn->name, "sizeof") == 0)) {
char * tp = "";
register long int j = 0;
for (; (j<len(memory)); j++) {
struct Tok tmpT = memory->data[j];
char * ____BAH_COMPILER_VAR_738 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tp);
long int strLen_1 = strlen(tmpT.cont);
;                            
            ____BAH_COMPILER_VAR_738 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_738+currStrOff, tp, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_738+currStrOff, tmpT.cont, strLen_1);
            currStrOff += strLen_1;
        
        }tp = ____BAH_COMPILER_VAR_738;
};
struct string cType = getCType(tp,elems);
char * ____BAH_COMPILER_VAR_739 =null;char * ____BAH_COMPILER_VAR_740 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_740);
long int strLen_1 = strlen(")");
;                            
            ____BAH_COMPILER_VAR_739 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_739+currStrOff, ____BAH_COMPILER_VAR_740, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_739+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_741 =null;char * ____BAH_COMPILER_VAR_742 =____BAH_COMPILER_VAR_739;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnt.cont);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_742);
;                            
            ____BAH_COMPILER_VAR_741 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_741+currStrOff, fnt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_741+currStrOff, ____BAH_COMPILER_VAR_742, strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_741;
fnt.type = TOKEN_TYPE_FUNC;
fnt.isFunc = true;
fnt.bahType = "int";
fnt.bahRef = fn;

{
long nLength = tokPos;
if (l->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(l->data, (nLength+50)*sizeof(struct Tok));
l->data = newPtr;
}
l->data[tokPos] = fnt;
l->length = nLength+1;
} else {
l->data[tokPos] = fnt;
}
};
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
char * ____BAH_COMPILER_VAR_743 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(amp);
long int strLen_1 = strlen(parent->name);
;                            
            ____BAH_COMPILER_VAR_743 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_743+currStrOff, amp, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_743+currStrOff, parent->name, strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_744 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnt.cont);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_743);
;                            
            ____BAH_COMPILER_VAR_744 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_744+currStrOff, fnt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_744+currStrOff, ____BAH_COMPILER_VAR_743, strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_744;
argIndex++;
if ((len(fn->args)>argIndex)) {
char * ____BAH_COMPILER_VAR_745 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnt.cont);
long int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_745 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_745+currStrOff, fnt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_745+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_745;
}
}
register long int j = 0;
for (; (j<len(memory)); j++) {
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
char * ____BAH_COMPILER_VAR_746 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(arg->type);
long int strLen_1 = strlen(" in function call.");
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(tt);
long int strLen_4 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_746 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_746+currStrOff, "Cannot use {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_746+currStrOff, tt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_746+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_746+currStrOff, arg->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_746+currStrOff, " in function call.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&t,____BAH_COMPILER_VAR_746);
}
if ((RCPavailable()==true)&&(ltp==LINE_TYPE_VAR)&&(t.type==TOKEN_TYPE_VAR)&&(t.isOper==false)&&(currSetVar!=null)&&(strcmp(t.cont, currSetVar->name) == 0)&&isRCPtype(currSetVar->type,elems)) {
OUTPUT = OUTPUT->add(OUTPUT, incrVar(currSetVar,elems));
}
if ((t.type==TOKEN_TYPE_FUNC)) {
struct func* afn = searchFuncByToken(t,elems);
if ((afn!=null)&&(isRCPtype(afn->returns->type,elems)==true)) {
t.cont = registerRCPvar(afn->returns->type,t.cont,elems);
}
}
char * ____BAH_COMPILER_VAR_747 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnt.cont);
long int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_747 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_747+currStrOff, fnt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_747+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_747;
argIndex++;
if ((j+1<len(memory))) {
j++;
t = memory->data[j];
if ((strcmp(t.cont, ",") != 0)) {
throwErr(&t,"Need separator between arguments, not {TOKEN}.");
}
char * ____BAH_COMPILER_VAR_748 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnt.cont);
long int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_748 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_748+currStrOff, fnt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_748+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_748;
}
};
if ((argIndex!=len(fn->args))) {
struct Tok lt = l->data[tokPos];
char * ____BAH_COMPILER_VAR_749 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fn->name);
long int strLen_1 = strlen("'.");
long int strLen_2 = strlen("Not enough argument {TOKEN}, calling '");
;                            
            ____BAH_COMPILER_VAR_749 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_749+currStrOff, "Not enough argument {TOKEN}, calling '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_749+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_749+currStrOff, "'.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&lt,____BAH_COMPILER_VAR_749);
}
fnt.bahRef = fn;
char * ____BAH_COMPILER_VAR_750 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnt.cont);
long int strLen_1 = strlen(")");
;                            
            ____BAH_COMPILER_VAR_750 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_750+currStrOff, fnt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_750+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_750;

{
long nLength = tokPos;
if (l->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(l->data, (nLength+50)*sizeof(struct Tok));
l->data = newPtr;
}
l->data[tokPos] = fnt;
l->length = nLength+1;
} else {
l->data[tokPos] = fnt;
}
};
return tokPos;
};
long int valueStruct(__BAH_ARR_TYPE_Tok l,long int i,lineType ltp,struct Elems* elems){
long int tokPos = i-1;
struct Tok t = l->data[i-1];
char * tt = getTypeFromToken(&t,true,elems);
struct cStruct* s = searchStruct(tt,elems);
if ((s==null)) {
throwErr(&t,"Cannot use {TOKEN} as structure.");
}
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
if (((t.type==TOKEN_TYPE_VAR)==true)) {
parent = searchVar(t.cont,elems);
}
else {
char * tmpV = genCompilerVar();
struct string cType = getCType(tt,elems);
char * ____BAH_COMPILER_VAR_751 =null;char * ____BAH_COMPILER_VAR_752 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(";\n                ");
long int strLen_2 = strlen(" = ");
long int strLen_3 = strlen(tmpV);
long int strLen_4 = strlen(" ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_752);
long int strLen_6 = strlen("\n                ");
;                            
            ____BAH_COMPILER_VAR_751 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_751+currStrOff, "\n                ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_751+currStrOff, ____BAH_COMPILER_VAR_752, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_751+currStrOff, " ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_751+currStrOff, tmpV, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_751+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_751+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_751+currStrOff, ";\n                ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_751));
t.cont = tmpV;
struct variable* ____BAH_COMPILER_VAR_753 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_753->name = "";
____BAH_COMPILER_VAR_753->type = "";
____BAH_COMPILER_VAR_753->isConst = false;
____BAH_COMPILER_VAR_753->constVal = "";
____BAH_COMPILER_VAR_753->isArray = false;
____BAH_COMPILER_VAR_753->from = "";
____BAH_COMPILER_VAR_753->declScope= null;
____BAH_COMPILER_VAR_753->isGlobal = false;
____BAH_COMPILER_VAR_753->declRope= null;
____BAH_COMPILER_VAR_753->isReg = false;
____BAH_COMPILER_VAR_753->name = tmpV;
____BAH_COMPILER_VAR_753->type = tt;
parent = ____BAH_COMPILER_VAR_753;
if (RCPavailable()) {

{
long nLength = len(elems->vars);
if (elems->vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(elems->vars->data, (nLength+50)*sizeof(struct variable*));
elems->vars->data = newPtr;
}
elems->vars->data[len(elems->vars)] = parent;
elems->vars->length = nLength+1;
} else {
elems->vars->data[len(elems->vars)] = parent;
}
};
}
}
struct func* fn = searchStructMethod(nt.cont,s,elems);
if ((fn==null)) {
char * ____BAH_COMPILER_VAR_754 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s->name);
long int strLen_1 = strlen(".");
long int strLen_2 = strlen("Unknown method {TOKEN} in struct ");
;                            
            ____BAH_COMPILER_VAR_754 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_754+currStrOff, "Unknown method {TOKEN} in struct ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_754+currStrOff, s->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_754+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&nt,____BAH_COMPILER_VAR_754);
}
struct func* ____BAH_COMPILER_VAR_755 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_755->name = "";
____BAH_COMPILER_VAR_755->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_755->args->length = 0;
            ____BAH_COMPILER_VAR_755->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_755->returns= null;
____BAH_COMPILER_VAR_755->isBinding = false;
____BAH_COMPILER_VAR_755->from = "";
____BAH_COMPILER_VAR_755->file = "";
____BAH_COMPILER_VAR_755->line = 1;
____BAH_COMPILER_VAR_755->used = false;
____BAH_COMPILER_VAR_755->code = null;
struct func* nfn = ____BAH_COMPILER_VAR_755;
*nfn = *fn;
nfn->name = nt.cont;
valueFunc(nfn,parent,l,i,ltp,elems);
struct Tok fnt = l->data[i];
delete(l,i);
char * ____BAH_COMPILER_VAR_756 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(".");
long int strLen_1 = strlen(nt.ogCont);
long int strLen_2 = strlen(t.ogCont);
;                            
            ____BAH_COMPILER_VAR_756 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_756+currStrOff, t.ogCont, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_756+currStrOff, ".", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_756+currStrOff, nt.ogCont, strLen_1);
            currStrOff += strLen_1;
        
        }fnt.ogCont = ____BAH_COMPILER_VAR_756;
fnt.pos = t.pos;
char * ____BAH_COMPILER_VAR_757 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(sep);
long int strLen_1 = strlen(fnt.cont);
long int strLen_2 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_757 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_757+currStrOff, t.cont, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_757+currStrOff, sep, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_757+currStrOff, fnt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_757;

{
long nLength = tokPos;
if (l->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(l->data, (nLength+50)*sizeof(struct Tok));
l->data = newPtr;
}
l->data[tokPos] = fnt;
l->length = nLength+1;
} else {
l->data[tokPos] = fnt;
}
};
return tokPos;
}
}
struct structMemb* m = searchStructMemb(nt.cont,s,elems);
if ((m==null)) {
char * ____BAH_COMPILER_VAR_758 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s->name);
long int strLen_1 = strlen("'.");
long int strLen_2 = strlen("Unknown struct member {TOKEN} in struct '");
;                            
            ____BAH_COMPILER_VAR_758 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_758+currStrOff, "Unknown struct member {TOKEN} in struct '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_758+currStrOff, s->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_758+currStrOff, "'.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&nt,____BAH_COMPILER_VAR_758);
}
char * ____BAH_COMPILER_VAR_759 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(sep);
long int strLen_1 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_759 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_759+currStrOff, sep, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_759+currStrOff, nt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_760 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_759);
;                            
            ____BAH_COMPILER_VAR_760 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_760+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_760+currStrOff, ____BAH_COMPILER_VAR_759, strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_760;
char * ____BAH_COMPILER_VAR_761 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(".");
long int strLen_1 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_761 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_761+currStrOff, ".", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_761+currStrOff, nt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_762 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t.ogCont);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_761);
;                            
            ____BAH_COMPILER_VAR_762 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_762+currStrOff, t.ogCont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_762+currStrOff, ____BAH_COMPILER_VAR_761, strLen_1);
            currStrOff += strLen_1;
        
        }t.ogCont = ____BAH_COMPILER_VAR_762;
t.bahType = m->type;
struct variable* ____BAH_COMPILER_VAR_763 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_763->name = "";
____BAH_COMPILER_VAR_763->type = "";
____BAH_COMPILER_VAR_763->isConst = false;
____BAH_COMPILER_VAR_763->constVal = "";
____BAH_COMPILER_VAR_763->isArray = false;
____BAH_COMPILER_VAR_763->from = "";
____BAH_COMPILER_VAR_763->declScope= null;
____BAH_COMPILER_VAR_763->isGlobal = false;
____BAH_COMPILER_VAR_763->declRope= null;
____BAH_COMPILER_VAR_763->isReg = false;
____BAH_COMPILER_VAR_763->name = t.cont;
____BAH_COMPILER_VAR_763->type = t.bahType;
t.bahRef = ____BAH_COMPILER_VAR_763;

{
long nLength = tokPos;
if (l->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(l->data, (nLength+50)*sizeof(struct Tok));
l->data = newPtr;
}
l->data[tokPos] = t;
l->length = nLength+1;
} else {
l->data[tokPos] = t;
}
};
return tokPos;
};
long int valueArr(__BAH_ARR_TYPE_Tok l,long int i,lineType ltp,struct Elems* elems){
long int tokPos = i-1;
struct Tok pt = l->data[tokPos];
delete(l,tokPos);
if ((pt.isValue==false)) {
throwErr(&pt,"Cannot use {TOKEN} as value (array).");
}
char * ____BAH_COMPILER_VAR_764 =getTypeFromToken(&pt,true,elems);struct string ptt = string(____BAH_COMPILER_VAR_764);
struct Tok t = pt;
t.isValue = true;
char * ____BAH_COMPILER_VAR_765 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t.ogCont);
long int strLen_1 = strlen("[");
;                            
            ____BAH_COMPILER_VAR_765 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_765+currStrOff, t.ogCont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_765+currStrOff, "[", strLen_1);
            currStrOff += strLen_1;
        
        }t.ogCont = ____BAH_COMPILER_VAR_765;
long int nbEncls = 1;
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
i = tokPos+1;
for (; (i<len(l)); i++) {
struct Tok tmpT = l->data[i];
if ((strcmp(tmpT.cont, "(") == 0)||(strcmp(tmpT.cont, "{") == 0)||(strcmp(tmpT.cont, "[") == 0)) {
nbEncls++;
}
else if ((strcmp(tmpT.cont, ")") == 0)||(strcmp(tmpT.cont, "}") == 0)||(strcmp(tmpT.cont, "]") == 0)) {
nbEncls--;
char * ____BAH_COMPILER_VAR_766 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t.ogCont);
long int strLen_1 = strlen("]");
;                            
            ____BAH_COMPILER_VAR_766 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_766+currStrOff, t.ogCont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_766+currStrOff, "]", strLen_1);
            currStrOff += strLen_1;
        
        }t.ogCont = ____BAH_COMPILER_VAR_766;
if ((nbEncls==0)) {
break;
}
}
char * ____BAH_COMPILER_VAR_767 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t.ogCont);
long int strLen_1 = strlen(tmpT.ogCont);
;                            
            ____BAH_COMPILER_VAR_767 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_767+currStrOff, t.ogCont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_767+currStrOff, tmpT.ogCont, strLen_1);
            currStrOff += strLen_1;
        
        }t.ogCont = ____BAH_COMPILER_VAR_767;

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] = tmpT;
memory->length = nLength+1;
} else {
memory->data[len(memory)] = tmpT;
}
};
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
if ((strcmp(first.cont, ":") == 0)) {
struct Tok second = memory->data[1];
char * secondt = getTypeFromToken(&second,true,elems);
if ((compTypes(secondt,"int")==false)) {
throwErr(&second,"Cannot use {TOKEN} as index (int).");
}
from = "0";
to = second.cont;
}
else {
struct Tok second = memory->data[1];
if ((strcmp(second.cont, ":") == 0)) {
if ((len(memory)==2)) {
char * firstt = getTypeFromToken(&first,true,elems);
if ((compTypes(firstt,"int")==false)) {
throwErr(&first,"Cannot use {TOKEN} as index (int).");
}
from = first.cont;
to = "";
}
else if ((len(memory)==3)) {
char * firstt = getTypeFromToken(&first,true,elems);
if ((compTypes(firstt,"int")==false)) {
throwErr(&first,"Cannot use {TOKEN} as index (int).");
}
struct Tok third = memory->data[1];
char * thirdt = getTypeFromToken(&third,true,elems);
if ((compTypes(thirdt,"int")==false)) {
throwErr(&third,"Cannot use {TOKEN} as index (int).");
}
from = first.cont;
to = third.cont;
}
else {
throwErr(&second,"Cannot substitute by more than 2 values.");
}
}
}
}
if (ptt.hasPrefix(&ptt,"[]")) {
if ((split==false)) {
struct Tok index = memory->data[0];
char * ____BAH_COMPILER_VAR_768 =getTypeFromToken(&index,true,elems);if ((compTypes(____BAH_COMPILER_VAR_768,"int")==false)) {
throwErr(&index,"Cannot use {TOKEN} as array index (int).");
}
char * ____BAH_COMPILER_VAR_769 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(index.cont);
long int strLen_1 = strlen("]");
long int strLen_2 = strlen("->data[");
long int strLen_3 = strlen(pt.cont);
;                            
            ____BAH_COMPILER_VAR_769 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_769+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_769+currStrOff, "->data[", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_769+currStrOff, index.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_769+currStrOff, "]", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_769;
ptt.trimLeft(&ptt,2);
t.bahType = ptt.str(&ptt);
}
else {
t.bahType = ptt.str(&ptt);
if ((strcmp(to, "") == 0)) {
char * ____BAH_COMPILER_VAR_770 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen("->length");
;                            
            ____BAH_COMPILER_VAR_770 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_770+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_770+currStrOff, "->length", strLen_1);
            currStrOff += strLen_1;
        
        }to = ____BAH_COMPILER_VAR_770;
}
char * ____BAH_COMPILER_VAR_771 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(to);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(from);
long int strLen_4 = strlen(", ");
long int strLen_5 = strlen(pt.cont);
long int strLen_6 = strlen("arraySubstitute(");
;                            
            ____BAH_COMPILER_VAR_771 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_771+currStrOff, "arraySubstitute(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_771+currStrOff, pt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_771+currStrOff, ", ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_771+currStrOff, from, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_771+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_771+currStrOff, to, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_771+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_771;
}
}
else if (ptt.hasPrefix(&ptt,"buffer:")) {
if ((split==false)) {
t.bahType = "char";
struct Tok index = memory->data[0];
char * ____BAH_COMPILER_VAR_772 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(index.cont);
long int strLen_1 = strlen("]");
long int strLen_2 = strlen("[");
long int strLen_3 = strlen(pt.cont);
;                            
            ____BAH_COMPILER_VAR_772 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_772+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_772+currStrOff, "[", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_772+currStrOff, index.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_772+currStrOff, "]", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_772;
}
else {
t.bahType = "cpstring";
if ((strcmp(to, "") == 0)) {
char * ____BAH_COMPILER_VAR_773 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen("strlen(");
;                            
            ____BAH_COMPILER_VAR_773 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_773+currStrOff, "strlen(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_773+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_773+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }to = ____BAH_COMPILER_VAR_773;
}
char * ____BAH_COMPILER_VAR_774 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(to);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(from);
long int strLen_4 = strlen(", ");
long int strLen_5 = strlen(pt.cont);
long int strLen_6 = strlen("cpstringSubsitute(");
;                            
            ____BAH_COMPILER_VAR_774 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_774+currStrOff, "cpstringSubsitute(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_774+currStrOff, pt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_774+currStrOff, ", ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_774+currStrOff, from, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_774+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_774+currStrOff, to, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_774+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_774;
}
}
else if (ptt.hasPrefix(&ptt,"map:")) {
if ((split==true)) {
throwErr(&pt,"Cannot do substitution on a map {TOKEN}.");
}
ptt.trimLeft(&ptt,4);
char * ____BAH_COMPILER_VAR_775 =ptt.str(&ptt);struct string elemType = getCType(____BAH_COMPILER_VAR_775,elems);
struct Tok index = memory->data[0];
if ((tokPos==0)&&(ltp==LINE_TYPE_VAR)) {
struct variable* ____BAH_COMPILER_VAR_776 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_776->name = "";
____BAH_COMPILER_VAR_776->type = "";
____BAH_COMPILER_VAR_776->isConst = false;
____BAH_COMPILER_VAR_776->constVal = "";
____BAH_COMPILER_VAR_776->isArray = false;
____BAH_COMPILER_VAR_776->from = "";
____BAH_COMPILER_VAR_776->declScope= null;
____BAH_COMPILER_VAR_776->isGlobal = false;
____BAH_COMPILER_VAR_776->declRope= null;
____BAH_COMPILER_VAR_776->isReg = false;
____BAH_COMPILER_VAR_776->name = genCompilerVar();
____BAH_COMPILER_VAR_776->type = ptt.str(&ptt);
struct variable* tmpV = ____BAH_COMPILER_VAR_776;

{
long nLength = len(elems->vars);
if (elems->vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(elems->vars->data, (nLength+50)*sizeof(struct variable*));
elems->vars->data = newPtr;
}
elems->vars->data[len(elems->vars)] = tmpV;
elems->vars->length = nLength+1;
} else {
elems->vars->data[len(elems->vars)] = tmpV;
}
};
if (isGlobal()) {
char * ____BAH_COMPILER_VAR_777 =null;char * ____BAH_COMPILER_VAR_778 =elemType.str(&elemType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpV->name);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_778);
;                            
            ____BAH_COMPILER_VAR_777 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_777+currStrOff, ____BAH_COMPILER_VAR_778, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_777+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_777+currStrOff, tmpV->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_777+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }INIT = INIT->add(INIT, rope(____BAH_COMPILER_VAR_777));
}
else {
char * ____BAH_COMPILER_VAR_779 =null;char * ____BAH_COMPILER_VAR_780 =elemType.str(&elemType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpV->name);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_780);
;                            
            ____BAH_COMPILER_VAR_779 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_779+currStrOff, ____BAH_COMPILER_VAR_780, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_779+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_779+currStrOff, tmpV->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_779+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_779));
}
char * ____BAH_COMPILER_VAR_781 =ptt.str(&ptt);if (isRCPpointerType(____BAH_COMPILER_VAR_781)) {
char * ____BAH_COMPILER_VAR_782 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpV->name);
long int strLen_1 = strlen(");\n");
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(index.cont);
long int strLen_4 = strlen(", ");
long int strLen_5 = strlen(pt.cont);
long int strLen_6 = strlen("->set(");
long int strLen_7 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_782 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7);
            
                    memcpy(____BAH_COMPILER_VAR_782+currStrOff, t.cont, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_782+currStrOff, "->set(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_782+currStrOff, pt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_782+currStrOff, ", ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_782+currStrOff, index.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_782+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_782+currStrOff, tmpV->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_782+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }NEXT_LINE = ____BAH_COMPILER_VAR_782;
}
else {
char * ____BAH_COMPILER_VAR_783 =null;char * ____BAH_COMPILER_VAR_784 =elemType.str(&elemType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_784);
long int strLen_1 = strlen("));\n");
long int strLen_2 = strlen(", sizeof(");
long int strLen_3 = strlen(tmpV->name);
long int strLen_4 = strlen(", &");
long int strLen_5 = strlen(index.cont);
long int strLen_6 = strlen(", ");
long int strLen_7 = strlen(pt.cont);
long int strLen_8 = strlen("->setAny(");
long int strLen_9 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_783 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9);
            
                    memcpy(____BAH_COMPILER_VAR_783+currStrOff, t.cont, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_783+currStrOff, "->setAny(", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_783+currStrOff, pt.cont, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_783+currStrOff, ", ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_783+currStrOff, index.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_783+currStrOff, ", &", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_783+currStrOff, tmpV->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_783+currStrOff, ", sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_783+currStrOff, ____BAH_COMPILER_VAR_784, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_783+currStrOff, "));\n", strLen_1);
            currStrOff += strLen_1;
        
        }NEXT_LINE = ____BAH_COMPILER_VAR_783;
}
t.cont = tmpV->name;
t.bahType = ptt.str(&ptt);
}
else {
t.isFunc = true;
char * ____BAH_COMPILER_VAR_785 =ptt.str(&ptt);if (isRCPpointerType(____BAH_COMPILER_VAR_785)) {
char * ____BAH_COMPILER_VAR_786 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(index.cont);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(t.cont);
long int strLen_4 = strlen("->get(");
;                            
            ____BAH_COMPILER_VAR_786 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_786+currStrOff, "->get(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_786+currStrOff, t.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_786+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_786+currStrOff, index.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_786+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_787 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_786);
;                            
            ____BAH_COMPILER_VAR_787 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_787+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_787+currStrOff, ____BAH_COMPILER_VAR_786, strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_787;
}
else {
char * tmpV = genCompilerVar();
char * ____BAH_COMPILER_VAR_788 =null;char * ____BAH_COMPILER_VAR_789 =elemType.str(&elemType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(index.cont);
long int strLen_1 = strlen(");\n");
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(pt.cont);
long int strLen_4 = strlen("->get(");
long int strLen_5 = strlen(pt.cont);
long int strLen_6 = strlen("=");
long int strLen_7 = strlen(tmpV);
long int strLen_8 = strlen("* ");
long int strLen_9 = strlen(____BAH_COMPILER_VAR_789);
;                            
            ____BAH_COMPILER_VAR_788 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9);
            
                    memcpy(____BAH_COMPILER_VAR_788+currStrOff, ____BAH_COMPILER_VAR_789, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_788+currStrOff, "* ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_788+currStrOff, tmpV, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_788+currStrOff, "=", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_788+currStrOff, pt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_788+currStrOff, "->get(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_788+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_788+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_788+currStrOff, index.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_788+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }struct rope* res = rope(____BAH_COMPILER_VAR_788);
char * ____BAH_COMPILER_VAR_790 =null;char * ____BAH_COMPILER_VAR_791 =elemType.str(&elemType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpV);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen(")(*");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_791);
long int strLen_4 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_790 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_790+currStrOff, "(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_790+currStrOff, ____BAH_COMPILER_VAR_791, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_790+currStrOff, ")(*", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_790+currStrOff, tmpV, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_790+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_790;
if (isGlobal()) {
INIT = INIT->add(INIT, res);
}
else {
OUTPUT = OUTPUT->add(OUTPUT, res);
}
}
t.bahType = ptt.str(&ptt);
}
}
else if ((strcmp(ptt.str(&ptt), "cpstring") == 0)) {
t.isFunc = true;
t.type = TOKEN_TYPE_FUNC;
if ((split==false)) {
t.bahType = "char";
struct Tok index = memory->data[0];
char * ____BAH_COMPILER_VAR_792 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(index.cont);
long int strLen_1 = strlen("]");
long int strLen_2 = strlen("[");
long int strLen_3 = strlen(pt.cont);
;                            
            ____BAH_COMPILER_VAR_792 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_792+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_792+currStrOff, "[", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_792+currStrOff, index.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_792+currStrOff, "]", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_792;
}
else {
if ((strcmp(to, "") == 0)) {
char * ____BAH_COMPILER_VAR_793 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen("strlen(");
;                            
            ____BAH_COMPILER_VAR_793 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_793+currStrOff, "strlen(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_793+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_793+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }to = ____BAH_COMPILER_VAR_793;
}
char * ____BAH_COMPILER_VAR_794 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(to);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(from);
long int strLen_4 = strlen(", ");
long int strLen_5 = strlen(pt.cont);
long int strLen_6 = strlen("cpstringSubsitute(");
;                            
            ____BAH_COMPILER_VAR_794 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_794+currStrOff, "cpstringSubsitute(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_794+currStrOff, pt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_794+currStrOff, ", ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_794+currStrOff, from, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_794+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_794+currStrOff, to, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_794+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_794;
}
}
else {
char * ____BAH_COMPILER_VAR_795 =null;char * ____BAH_COMPILER_VAR_796 =ptt.str(&ptt);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_796);
long int strLen_1 = strlen(") as array.");
long int strLen_2 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_795 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_795+currStrOff, "Cannot use {TOKEN} (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_795+currStrOff, ____BAH_COMPILER_VAR_796, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_795+currStrOff, ") as array.", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_797 =____BAH_COMPILER_VAR_795;throwErr(&pt,____BAH_COMPILER_VAR_797);
}
t.isValue = true;

{
long nLength = tokPos;
if (l->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(l->data, (nLength+50)*sizeof(struct Tok));
l->data = newPtr;
}
l->data[tokPos] = t;
l->length = nLength+1;
} else {
l->data[tokPos] = t;
}
};
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
char * odecl = v->declRope->toStr(v->declRope);
if ((strHasPrefix(odecl,"register ")==false)) {
char * ____BAH_COMPILER_VAR_798 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("register ");
long int strLen_1 = strlen(odecl);
;                            
            ____BAH_COMPILER_VAR_798 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_798+currStrOff, "register ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_798+currStrOff, odecl, strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT->totalLen = OUTPUT->totalLen+ropeSet(v->declRope,____BAH_COMPILER_VAR_798);
}
v->isReg = true;
}
}
struct Tok nt = l->data[tokPos];
char * ntt = getTypeFromToken(&nt,true,elems);
if ((strcmp(t.cont, "in") == 0)) {
struct string arrT = string(ntt);
if ((arrT.hasPrefix(&arrT,"[]")==0)) {
char * ____BAH_COMPILER_VAR_799 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ntt);
long int strLen_1 = strlen(") as array.");
long int strLen_2 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_799 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_799+currStrOff, "Cannot use {TOKEN} (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_799+currStrOff, ntt, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_799+currStrOff, ") as array.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&nt,____BAH_COMPILER_VAR_799);
}
arrT.trimLeft(&arrT,2);
char * ____BAH_COMPILER_VAR_800 =arrT.str(&arrT);if ((compTypes(ptt,____BAH_COMPILER_VAR_800)==false)) {
char * ____BAH_COMPILER_VAR_801 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ntt);
long int strLen_1 = strlen(".");
long int strLen_2 = strlen(") in ");
long int strLen_3 = strlen(ptt);
long int strLen_4 = strlen("Cannot search for {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_801 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_801+currStrOff, "Cannot search for {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_801+currStrOff, ptt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_801+currStrOff, ") in ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_801+currStrOff, ntt, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_801+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&pt,____BAH_COMPILER_VAR_801);
}
char * compVar = genCompilerVar();
char * comp = "";
if ((strcmp(ptt, "cpstring") == 0)) {
char * ____BAH_COMPILER_VAR_802 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(") == 0");
long int strLen_2 = strlen("->data[i], ");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen("->data[i] != 0 && strcmp(");
long int strLen_5 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_802 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_802+currStrOff, nt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_802+currStrOff, "->data[i] != 0 && strcmp(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_802+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_802+currStrOff, "->data[i], ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_802+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_802+currStrOff, ") == 0", strLen_1);
            currStrOff += strLen_1;
        
        }comp = ____BAH_COMPILER_VAR_802;
}
else {
char * ____BAH_COMPILER_VAR_803 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("->data[i] == ");
long int strLen_1 = strlen(pt.cont);
long int strLen_2 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_803 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_803+currStrOff, nt.cont, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_803+currStrOff, "->data[i] == ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_803+currStrOff, pt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }comp = ____BAH_COMPILER_VAR_803;
}
char * ____BAH_COMPILER_VAR_804 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(compVar);
long int strLen_1 = strlen("=1;\n                break;\n            };\n        }\n        ");
long int strLen_2 = strlen(") {\n                ");
long int strLen_3 = strlen(comp);
long int strLen_4 = strlen("->length-1; i!=-1;i--) {\n            if (");
long int strLen_5 = strlen(nt.cont);
long int strLen_6 = strlen(" = 0;\n        for(int i=");
long int strLen_7 = strlen(compVar);
long int strLen_8 = strlen("\n        char ");
;                            
            ____BAH_COMPILER_VAR_804 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_804+currStrOff, "\n        char ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_804+currStrOff, compVar, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_804+currStrOff, " = 0;\n        for(int i=", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_804+currStrOff, nt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_804+currStrOff, "->length-1; i!=-1;i--) {\n            if (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_804+currStrOff, comp, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_804+currStrOff, ") {\n                ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_804+currStrOff, compVar, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_804+currStrOff, "=1;\n                break;\n            };\n        }\n        ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_804));
pt.cont = compVar;
}
else {
if ((compTypes(ptt,ntt)==false)) {
char * ____BAH_COMPILER_VAR_805 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ptt);
long int strLen_1 = strlen(".");
long int strLen_2 = strlen(") with type ");
long int strLen_3 = strlen(ntt);
long int strLen_4 = strlen("Cannot compare {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_805 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_805+currStrOff, "Cannot compare {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_805+currStrOff, ntt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_805+currStrOff, ") with type ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_805+currStrOff, ptt, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_805+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&nt,____BAH_COMPILER_VAR_805);
}
if ((strcmp(ptt, "cpstring") == 0)) {
if ((strcmp(t.cont, "==") == 0)) {
char * ____BAH_COMPILER_VAR_806 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen(") == 0)");
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(pt.cont);
long int strLen_4 = strlen("(strcmp(");
;                            
            ____BAH_COMPILER_VAR_806 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_806+currStrOff, "(strcmp(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_806+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_806+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_806+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_806+currStrOff, ") == 0)", strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_806;
}
else if ((strcmp(t.cont, "!=") == 0)) {
char * ____BAH_COMPILER_VAR_807 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen(") != 0)");
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(pt.cont);
long int strLen_4 = strlen("(strcmp(");
;                            
            ____BAH_COMPILER_VAR_807 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_807+currStrOff, "(strcmp(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_807+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_807+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_807+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_807+currStrOff, ") != 0)", strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_807;
}
else if ((strcmp(t.cont, ">") == 0)) {
char * ____BAH_COMPILER_VAR_808 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen("))");
long int strLen_2 = strlen(") > srtlen(");
long int strLen_3 = strlen(pt.cont);
long int strLen_4 = strlen("(strlen(");
;                            
            ____BAH_COMPILER_VAR_808 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_808+currStrOff, "(strlen(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_808+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_808+currStrOff, ") > srtlen(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_808+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_808+currStrOff, "))", strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_808;
}
else if ((strcmp(t.cont, "<") == 0)) {
char * ____BAH_COMPILER_VAR_809 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen("))");
long int strLen_2 = strlen(") < srtlen(");
long int strLen_3 = strlen(pt.cont);
long int strLen_4 = strlen("(strlen(");
;                            
            ____BAH_COMPILER_VAR_809 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_809+currStrOff, "(strlen(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_809+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_809+currStrOff, ") < srtlen(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_809+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_809+currStrOff, "))", strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_809;
}
else if ((strcmp(t.cont, ">=") == 0)) {
char * ____BAH_COMPILER_VAR_810 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen("))");
long int strLen_2 = strlen(") >= srtlen(");
long int strLen_3 = strlen(pt.cont);
long int strLen_4 = strlen("(strlen(");
;                            
            ____BAH_COMPILER_VAR_810 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_810+currStrOff, "(strlen(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_810+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_810+currStrOff, ") >= srtlen(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_810+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_810+currStrOff, "))", strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_810;
}
else if ((strcmp(t.cont, "<=") == 0)) {
char * ____BAH_COMPILER_VAR_811 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen("))");
long int strLen_2 = strlen(") <= srtlen(");
long int strLen_3 = strlen(pt.cont);
long int strLen_4 = strlen("(strlen(");
;                            
            ____BAH_COMPILER_VAR_811 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_811+currStrOff, "(strlen(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_811+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_811+currStrOff, ") <= srtlen(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_811+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_811+currStrOff, "))", strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_811;
}
}
else {
char * ____BAH_COMPILER_VAR_812 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen(t.cont);
long int strLen_3 = strlen(pt.cont);
long int strLen_4 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_812 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_812+currStrOff, "(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_812+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_812+currStrOff, t.cont, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_812+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_812+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_812;
}
}
pt.isOper = true;
pt.bahType = "bool";
pt.isValue = true;

{
long nLength = tokPos;
if (l->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(l->data, (nLength+50)*sizeof(struct Tok));
l->data = newPtr;
}
l->data[tokPos] = pt;
l->length = nLength+1;
} else {
l->data[tokPos] = pt;
}
};
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
char * ____BAH_COMPILER_VAR_813 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_813 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_813+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_813+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_814 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_813);
;                            
            ____BAH_COMPILER_VAR_814 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_814+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_814+currStrOff, ____BAH_COMPILER_VAR_813, strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_814;

{
long nLength = tokPos;
if (l->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(l->data, (nLength+50)*sizeof(struct Tok));
l->data = newPtr;
}
l->data[tokPos] = pt;
l->length = nLength+1;
} else {
l->data[tokPos] = pt;
}
};
return tokPos;
}
char * ntt = getTypeFromToken(&nt,true,elems);
if ((compTypes(ptt,ntt)==false)) {
char * ____BAH_COMPILER_VAR_815 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ptt);
long int strLen_1 = strlen(".");
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(ntt);
long int strLen_4 = strlen("Cannot compare {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_815 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_815+currStrOff, "Cannot compare {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_815+currStrOff, ntt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_815+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_815+currStrOff, ptt, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_815+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&nt,____BAH_COMPILER_VAR_815);
}
if ((strcmp(ptt, "cpstring") == 0)) {
char * lens = "";
char * totStrLen = "1+strLen_0+strLen_1";
struct rope* cats = rope("");
char * rstr = registerRCPvar("cpstring","null",elems);
if ((pt.isFunc==true)) {
pt.cont = registerRCPvar("cpstring",pt.cont,elems);
}
char * ____BAH_COMPILER_VAR_816 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(");\n");
long int strLen_2 = strlen("long int strLen_0 = strlen(");
;                            
            ____BAH_COMPILER_VAR_816 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_816+currStrOff, "long int strLen_0 = strlen(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_816+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_816+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_817 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(lens);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_816);
;                            
            ____BAH_COMPILER_VAR_817 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_817+currStrOff, lens, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_817+currStrOff, ____BAH_COMPILER_VAR_816, strLen_1);
            currStrOff += strLen_1;
        
        }lens = ____BAH_COMPILER_VAR_817;
char * ____BAH_COMPILER_VAR_818 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(", strLen_0);\n            currStrOff += strLen_0;\n        ");
long int strLen_2 = strlen("+currStrOff, ");
long int strLen_3 = strlen(rstr);
long int strLen_4 = strlen("\n            memcpy(");
;                            
            ____BAH_COMPILER_VAR_818 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_818+currStrOff, "\n            memcpy(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_818+currStrOff, rstr, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_818+currStrOff, "+currStrOff, ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_818+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_818+currStrOff, ", strLen_0);\n            currStrOff += strLen_0;\n        ", strLen_1);
            currStrOff += strLen_1;
        
        }cats = cats->add(cats, rope(____BAH_COMPILER_VAR_818));
if ((nt.isFunc==true)) {
nt.cont = registerRCPvar("cpstring",nt.cont,elems);
}
char * ____BAH_COMPILER_VAR_819 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen(");\n");
long int strLen_2 = strlen("long int strLen_1 = strlen(");
;                            
            ____BAH_COMPILER_VAR_819 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_819+currStrOff, "long int strLen_1 = strlen(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_819+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_819+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_820 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(lens);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_819);
;                            
            ____BAH_COMPILER_VAR_820 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_820+currStrOff, lens, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_820+currStrOff, ____BAH_COMPILER_VAR_819, strLen_1);
            currStrOff += strLen_1;
        
        }lens = ____BAH_COMPILER_VAR_820;
char * ____BAH_COMPILER_VAR_821 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen(", strLen_1);\n            currStrOff += strLen_1;\n        ");
long int strLen_2 = strlen("+currStrOff, ");
long int strLen_3 = strlen(rstr);
long int strLen_4 = strlen("\n            memcpy(");
;                            
            ____BAH_COMPILER_VAR_821 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_821+currStrOff, "\n            memcpy(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_821+currStrOff, rstr, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_821+currStrOff, "+currStrOff, ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_821+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_821+currStrOff, ", strLen_1);\n            currStrOff += strLen_1;\n        ", strLen_1);
            currStrOff += strLen_1;
        
        }cats = cats->add(cats, rope(____BAH_COMPILER_VAR_821));
if ((strcmp(t.cont, "+") != 0)) {
throwErr(&t,"Can only do concatenation on cpstring, not {TOKEN}.");
}
if ((tokPos-1>=0)) {
struct Tok nat = l->data[tokPos-1];
if ((strcmp(nat.cont, "+") == 0)) {
long int rangeEnds = tokPos-1;
i = tokPos-2;
long int nb = 2;
for (; (i>=0); i--) {
tokPos = i;
struct Tok currStrTk = l->data[i];
char * tt = getTypeFromToken(&currStrTk,true,elems);
if ((compTypes(tt,"cpstring")==false)) {
char * ____BAH_COMPILER_VAR_822 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tt);
long int strLen_1 = strlen(").");
long int strLen_2 = strlen("Cannot concatenate cpstring with {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_822 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_822+currStrOff, "Cannot concatenate cpstring with {TOKEN} (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_822+currStrOff, tt, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_822+currStrOff, ").", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&currStrTk,____BAH_COMPILER_VAR_822);
}
if ((currStrTk.isFunc==true)) {
currStrTk.cont = registerRCPvar("cpstring",currStrTk.cont,elems);
}
char * is = intToStr(nb);
nb++;
char * ____BAH_COMPILER_VAR_823 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(currStrTk.cont);
long int strLen_1 = strlen(");\n");
long int strLen_2 = strlen(" = strlen(");
long int strLen_3 = strlen(is);
long int strLen_4 = strlen("long int strLen_");
;                            
            ____BAH_COMPILER_VAR_823 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_823+currStrOff, "long int strLen_", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_823+currStrOff, is, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_823+currStrOff, " = strlen(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_823+currStrOff, currStrTk.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_823+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_824 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(lens);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_823);
;                            
            ____BAH_COMPILER_VAR_824 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_824+currStrOff, lens, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_824+currStrOff, ____BAH_COMPILER_VAR_823, strLen_1);
            currStrOff += strLen_1;
        
        }lens = ____BAH_COMPILER_VAR_824;
char * ____BAH_COMPILER_VAR_825 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("+strLen_");
long int strLen_1 = strlen(is);
;                            
            ____BAH_COMPILER_VAR_825 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_825+currStrOff, "+strLen_", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_825+currStrOff, is, strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_826 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(totStrLen);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_825);
;                            
            ____BAH_COMPILER_VAR_826 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_826+currStrOff, totStrLen, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_826+currStrOff, ____BAH_COMPILER_VAR_825, strLen_1);
            currStrOff += strLen_1;
        
        }totStrLen = ____BAH_COMPILER_VAR_826;
char * ____BAH_COMPILER_VAR_827 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(is);
long int strLen_1 = strlen(";\n                    ");
long int strLen_2 = strlen(");\n                    currStrOff += strLen_");
long int strLen_3 = strlen(is);
long int strLen_4 = strlen(", strLen_");
long int strLen_5 = strlen(currStrTk.cont);
long int strLen_6 = strlen("+currStrOff, ");
long int strLen_7 = strlen(rstr);
long int strLen_8 = strlen("\n                    memcpy(");
;                            
            ____BAH_COMPILER_VAR_827 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_827+currStrOff, "\n                    memcpy(", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_827+currStrOff, rstr, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_827+currStrOff, "+currStrOff, ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_827+currStrOff, currStrTk.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_827+currStrOff, ", strLen_", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_827+currStrOff, is, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_827+currStrOff, ");\n                    currStrOff += strLen_", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_827+currStrOff, is, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_827+currStrOff, ";\n                    ", strLen_1);
            currStrOff += strLen_1;
        
        }cats = rope(____BAH_COMPILER_VAR_827)->add(rope(____BAH_COMPILER_VAR_827), cats);
if ((i-1>=0)) {
i--;
t = l->data[i];
if ((strcmp(t.cont, "+") != 0)) {

        char ____BAH_COMPILER_VAR_828 = 0;
        for(int i=signs->length-1; i!=-1;i--) {
            if (signs->data[i] != 0 && strcmp(signs->data[i], t.cont) == 0) {
                ____BAH_COMPILER_VAR_828=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_828) {
throwErr(&t,"Can only do concatenation on cpstring, not {TOKEN}.");
}
else {
i++;
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
char * ____BAH_COMPILER_VAR_829 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(totStrLen);
long int strLen_1 = strlen(");\n            ");
long int strLen_2 = strlen(" = memoryAllocSTR(");
long int strLen_3 = strlen(rstr);
long int strLen_4 = strlen(";                            \n            ");
long int strLen_5 = strlen(lens);
long int strLen_6 = strlen("\n        {\n            long int currStrOff = 0;\n            ");
;                            
            ____BAH_COMPILER_VAR_829 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_829+currStrOff, "\n        {\n            long int currStrOff = 0;\n            ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_829+currStrOff, lens, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_829+currStrOff, ";                            \n            ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_829+currStrOff, rstr, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_829+currStrOff, " = memoryAllocSTR(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_829+currStrOff, totStrLen, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_829+currStrOff, ");\n            ", strLen_1);
            currStrOff += strLen_1;
        
        }struct rope* res = rope(____BAH_COMPILER_VAR_829)->add(rope(____BAH_COMPILER_VAR_829), cats->add(cats, rope("\n        }")));
if (isGlobal()) {
INIT = INIT->add(INIT, res);
}
else {
OUTPUT = OUTPUT->add(OUTPUT, res);
}
pt.cont = rstr;
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
char * ____BAH_COMPILER_VAR_830 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ptt);
long int strLen_1 = strlen(").");
long int strLen_2 = strlen("Undefined operation on struct {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_830 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_830+currStrOff, "Undefined operation on struct {TOKEN} (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_830+currStrOff, ptt, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_830+currStrOff, ").", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&pt,____BAH_COMPILER_VAR_830);
}
struct structMemb* methd = searchStructMemb(mName,s,elems);
if ((methd!=null)&&(methd->isFn==true)) {
char * ____BAH_COMPILER_VAR_831 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(pt.cont);
long int strLen_4 = strlen(amp);
long int strLen_5 = strlen("(");
long int strLen_6 = strlen(mName);
long int strLen_7 = strlen(sep);
;                            
            ____BAH_COMPILER_VAR_831 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7);
            
                    memcpy(____BAH_COMPILER_VAR_831+currStrOff, sep, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_831+currStrOff, mName, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_831+currStrOff, "(", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_831+currStrOff, amp, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_831+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_831+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_831+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_831+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_832 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_831);
;                            
            ____BAH_COMPILER_VAR_832 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_832+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_832+currStrOff, ____BAH_COMPILER_VAR_831, strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_832;
pt.isFunc = true;
}
}
else {
char * ____BAH_COMPILER_VAR_833 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_833 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_833+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_833+currStrOff, nt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_834 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_833);
;                            
            ____BAH_COMPILER_VAR_834 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_834+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_834+currStrOff, ____BAH_COMPILER_VAR_833, strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_834;
}
}
pt.isOper = true;

{
long nLength = tokPos;
if (l->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(l->data, (nLength+50)*sizeof(struct Tok));
l->data = newPtr;
}
l->data[tokPos] = pt;
l->length = nLength+1;
} else {
l->data[tokPos] = pt;
}
};
return tokPos;
};
long int valueSendChan(__BAH_ARR_TYPE_Tok l,long int i,struct Elems* elems){
long int posTok = i-2;
struct Tok nt = l->data[posTok];
struct Tok pt = l->data[posTok+2];
deleteRange(l,posTok,posTok+2);
char * ntt = getTypeFromToken(&nt,true,elems);
char * ____BAH_COMPILER_VAR_835 =getTypeFromToken(&pt,true,elems);struct string ptt = string(____BAH_COMPILER_VAR_835);
if ((ptt.hasPrefix(&ptt,"chan:")==0)) {
char * ____BAH_COMPILER_VAR_836 =null;char * ____BAH_COMPILER_VAR_837 =ptt.str(&ptt);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_837);
long int strLen_1 = strlen(") as chan.");
long int strLen_2 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_836 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_836+currStrOff, "Cannot use {TOKEN} (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_836+currStrOff, ____BAH_COMPILER_VAR_837, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_836+currStrOff, ") as chan.", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_838 =____BAH_COMPILER_VAR_836;throwErr(&pt,____BAH_COMPILER_VAR_838);
}
ptt.trimLeft(&ptt,5);
if (isGlobal()) {
throwErr(&pt,"Cannot send to channel {TOKEN} of a function.");
}
char * ____BAH_COMPILER_VAR_839 =ptt.str(&ptt);if ((compTypes(ntt,____BAH_COMPILER_VAR_839)==false)) {
char * ____BAH_COMPILER_VAR_840 =null;char * ____BAH_COMPILER_VAR_841 =ptt.str(&ptt);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_841);
long int strLen_1 = strlen(".");
long int strLen_2 = strlen(") through chan:");
long int strLen_3 = strlen(ntt);
long int strLen_4 = strlen("Cannot send {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_840 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_840+currStrOff, "Cannot send {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_840+currStrOff, ntt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_840+currStrOff, ") through chan:", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_840+currStrOff, ____BAH_COMPILER_VAR_841, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_840+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_842 =____BAH_COMPILER_VAR_840;throwErr(&nt,____BAH_COMPILER_VAR_842);
}
char * ____BAH_COMPILER_VAR_843 =ptt.str(&ptt);if (isRCPpointerType(____BAH_COMPILER_VAR_843)) {
char * ____BAH_COMPILER_VAR_844 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen(");\n");
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(pt.cont);
long int strLen_4 = strlen("->send(");
long int strLen_5 = strlen(pt.cont);
;                            
            ____BAH_COMPILER_VAR_844 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_844+currStrOff, pt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_844+currStrOff, "->send(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_844+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_844+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_844+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_844+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_844));
}
else {
struct string ct = getCType(ntt,elems);
char * tmpV = genCompilerVar();
char * ____BAH_COMPILER_VAR_845 =null;char * ____BAH_COMPILER_VAR_846 =ct.str(&ct);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpV);
long int strLen_1 = strlen("));\n        ");
long int strLen_2 = strlen(", sizeof(");
long int strLen_3 = strlen(tmpV);
long int strLen_4 = strlen(", &");
long int strLen_5 = strlen(pt.cont);
long int strLen_6 = strlen("->sendAny(");
long int strLen_7 = strlen(pt.cont);
long int strLen_8 = strlen(";\n        ");
long int strLen_9 = strlen(nt.cont);
long int strLen_10 = strlen(" = ");
long int strLen_11 = strlen(tmpV);
long int strLen_12 = strlen(" ");
long int strLen_13 = strlen(____BAH_COMPILER_VAR_846);
long int strLen_14 = strlen("\n        ");
;                            
            ____BAH_COMPILER_VAR_845 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13+strLen_14);
            
                    memcpy(____BAH_COMPILER_VAR_845+currStrOff, "\n        ", strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_845+currStrOff, ____BAH_COMPILER_VAR_846, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_845+currStrOff, " ", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_845+currStrOff, tmpV, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_845+currStrOff, " = ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_845+currStrOff, nt.cont, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_845+currStrOff, ";\n        ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_845+currStrOff, pt.cont, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_845+currStrOff, "->sendAny(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_845+currStrOff, pt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_845+currStrOff, ", &", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_845+currStrOff, tmpV, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_845+currStrOff, ", sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_845+currStrOff, tmpV, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_845+currStrOff, "));\n        ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_845));
}
return posTok;
};
long int valueChan(__BAH_ARR_TYPE_Tok l,long int i,struct Elems* elems){
long int posTok = i-1;
delete(l,posTok);
struct Tok nt = l->data[posTok];
char * ____BAH_COMPILER_VAR_847 =getTypeFromToken(&nt,true,elems);struct string ntt = string(____BAH_COMPILER_VAR_847);
if ((ntt.hasPrefix(&ntt,"chan:")==0)) {
char * ____BAH_COMPILER_VAR_848 =null;char * ____BAH_COMPILER_VAR_849 =ntt.str(&ntt);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_849);
long int strLen_1 = strlen(") as chan.");
long int strLen_2 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_848 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_848+currStrOff, "Cannot use {TOKEN} (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_848+currStrOff, ____BAH_COMPILER_VAR_849, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_848+currStrOff, ") as chan.", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_850 =____BAH_COMPILER_VAR_848;throwErr(&nt,____BAH_COMPILER_VAR_850);
}
ntt.trimLeft(&ntt,5);
if (isGlobal()) {
throwErr(&nt,"Cannot receive from chan {TOKEN} outside a function body.");
}
char * tmpV = "";
char * ____BAH_COMPILER_VAR_851 =ntt.str(&ntt);struct string ct = getCType(____BAH_COMPILER_VAR_851,elems);
char * ____BAH_COMPILER_VAR_852 =ntt.str(&ntt);if (isRCPpointerType(____BAH_COMPILER_VAR_852)) {
char * ____BAH_COMPILER_VAR_853 =null;char * ____BAH_COMPILER_VAR_854 =ct.str(&ct);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen("->receive(");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen(")");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_854);
long int strLen_6 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_853 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_853+currStrOff, "(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_853+currStrOff, ____BAH_COMPILER_VAR_854, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_853+currStrOff, ")", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_853+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_853+currStrOff, "->receive(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_853+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_853+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }nt.cont = ____BAH_COMPILER_VAR_853;
}
else {
if (RCPavailable()) {
char * ____BAH_COMPILER_VAR_855 =null;char * ____BAH_COMPILER_VAR_856 =ntt.str(&ntt);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_856);
long int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_855 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_855+currStrOff, ____BAH_COMPILER_VAR_856, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_855+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_857 =null;char * ____BAH_COMPILER_VAR_858 =ct.str(&ct);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen("->receive(");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen("*)");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_858);
long int strLen_6 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_857 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_857+currStrOff, "(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_857+currStrOff, ____BAH_COMPILER_VAR_858, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_857+currStrOff, "*)", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_857+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_857+currStrOff, "->receive(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_857+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_857+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_859 =____BAH_COMPILER_VAR_855;tmpV = registerRCPvar(____BAH_COMPILER_VAR_859,____BAH_COMPILER_VAR_857,elems);
char * ____BAH_COMPILER_VAR_860 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("*");
long int strLen_1 = strlen(tmpV);
;                            
            ____BAH_COMPILER_VAR_860 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_860+currStrOff, "*", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_860+currStrOff, tmpV, strLen_1);
            currStrOff += strLen_1;
        
        }nt.cont = ____BAH_COMPILER_VAR_860;
}
else {
char * ____BAH_COMPILER_VAR_861 =null;char * ____BAH_COMPILER_VAR_862 =ct.str(&ct);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen("->receive(");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen("*)");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_862);
long int strLen_6 = strlen("*(");
;                            
            ____BAH_COMPILER_VAR_861 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_861+currStrOff, "*(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_861+currStrOff, ____BAH_COMPILER_VAR_862, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_861+currStrOff, "*)", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_861+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_861+currStrOff, "->receive(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_861+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_861+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }nt.cont = ____BAH_COMPILER_VAR_861;
}
}
nt.type = TOKEN_TYPE_FUNC;
nt.isFunc = true;
nt.isValue = true;
nt.bahType = ntt.str(&ntt);

{
long nLength = posTok;
if (l->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(l->data, (nLength+50)*sizeof(struct Tok));
l->data = newPtr;
}
l->data[posTok] = nt;
l->length = nLength+1;
} else {
l->data[posTok] = nt;
}
};
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
while ((i<len(line))) {
struct Tok t = line->data[i];
if ((strcmp(t.cont, "(") == 0)) {
char isFunc = true;
nbPar = nbPar+1;
}
else if ((strcmp(t.cont, ")") == 0)) {
nbPar = nbPar-1;
}
else if ((nbPar==0)&&(strcmp(t.cont, "{") == 0)) {
struct Tok nt = line->data[i+1];
char isStructType = true;
if ((nt.line!=t.line)) {
break;
}
}

{
long nLength = len(fl);
if (fl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(fl->data, (nLength+50)*sizeof(struct Tok));
fl->data = newPtr;
}
fl->data[len(fl)] = t;
fl->length = nLength+1;
} else {
fl->data[len(fl)] = t;
}
};
i++;
};
sepI = i;
}
else {
char isStruct = true;
char isFunc = true;
char isChan = true;
char isArr = true;
char isBool = true;
char isOper = true;
char isCast = true;
char needGuard = true;
fl = line;
}
struct Tok ____BAH_COMPILER_VAR_863 = {};
____BAH_COMPILER_VAR_863.cont = "";
____BAH_COMPILER_VAR_863.ogCont = "";
____BAH_COMPILER_VAR_863.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_863.pos = 0;
____BAH_COMPILER_VAR_863.line = 1;
____BAH_COMPILER_VAR_863.begLine = 1;
____BAH_COMPILER_VAR_863.bahType = "";
____BAH_COMPILER_VAR_863.isValue = false;
____BAH_COMPILER_VAR_863.isFunc = false;
____BAH_COMPILER_VAR_863.isOper = false;
____BAH_COMPILER_VAR_863.isEqual = false;
____BAH_COMPILER_VAR_863.pass = false;
____BAH_COMPILER_VAR_863.bahRef= null;
#define pt ____BAH_COMPILER_VAR_863
long int l = len(fl);
i = 0;
for (; (i<len(fl)); i++) {
struct Tok t = fl->data[i];
if ((t.type==TOKEN_TYPE_VAR)&&(t.isOper==false)&&(t.cont[0]==38)) {
struct string tc = string(t.cont);
tc.trimLeft(&tc,1);
char * ____BAH_COMPILER_VAR_864 =tc.str(&tc);struct variable* rv = getRealVar(____BAH_COMPILER_VAR_864,elems);
if ((rv!=null)&&(rv->canBeReg==true)&&(rv->declRope!=null)) {
char * rvdr = rv->declRope->toStr(rv->declRope);
if (strHasPrefix(rvdr,"register ")) {
strTrimLeft(&rvdr,9);
OUTPUT->totalLen = OUTPUT->totalLen+ropeSet(rv->declRope,rvdr);
}
rv->canBeReg = false;
}
}
};
i = 0;
for (; (i<len(fl)); i++) {
struct Tok t = fl->data[i];
if ((i>0)) {
pt = fl->data[i-1];
}
else {
struct Tok ____BAH_COMPILER_VAR_865 = {};
____BAH_COMPILER_VAR_865.cont = "";
____BAH_COMPILER_VAR_865.ogCont = "";
____BAH_COMPILER_VAR_865.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_865.pos = 0;
____BAH_COMPILER_VAR_865.line = 1;
____BAH_COMPILER_VAR_865.begLine = 1;
____BAH_COMPILER_VAR_865.bahType = "";
____BAH_COMPILER_VAR_865.isValue = false;
____BAH_COMPILER_VAR_865.isFunc = false;
____BAH_COMPILER_VAR_865.isOper = false;
____BAH_COMPILER_VAR_865.isEqual = false;
____BAH_COMPILER_VAR_865.pass = false;
____BAH_COMPILER_VAR_865.bahRef= null;
pt = ____BAH_COMPILER_VAR_865;
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
ptc.trimLeft(&ptc,1);
ptc.trimRight(&ptc,1);
t.bahType = ptc.str(&ptc);
char * ____BAH_COMPILER_VAR_866 =ptc.str(&ptc);struct string cType = getCType(____BAH_COMPILER_VAR_866,elems);
char * ____BAH_COMPILER_VAR_867 =null;char * ____BAH_COMPILER_VAR_868 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(")");
long int strLen_1 = strlen(t.cont);
long int strLen_2 = strlen(____BAH_COMPILER_VAR_868);
long int strLen_3 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_867 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_867+currStrOff, "(", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_867+currStrOff, ____BAH_COMPILER_VAR_868, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_867+currStrOff, ")", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_867+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_867;

{
long nLength = i-1;
if (fl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(fl->data, (nLength+50)*sizeof(struct Tok));
fl->data = newPtr;
}
fl->data[i-1] = t;
fl->length = nLength+1;
} else {
fl->data[i-1] = t;
}
};
i = i-2;
}
else if (inArrayStr(pt.cont,signs)) {
if ((strcmp(t.cont, pt.cont) == 0)&&(i>1)) {
struct Tok ppt = fl->data[i-2];
if ((ppt.type==TOKEN_TYPE_VAR)) {
long int posTok = i-2;
deleteRange(fl,i-1,i);
char * ____BAH_COMPILER_VAR_869 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_869 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_869+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_869+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_870 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ppt.cont);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_869);
;                            
            ____BAH_COMPILER_VAR_870 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_870+currStrOff, ppt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_870+currStrOff, ____BAH_COMPILER_VAR_869, strLen_1);
            currStrOff += strLen_1;
        
        }ppt.cont = ____BAH_COMPILER_VAR_870;
ppt.isValue = true;
ppt.isOper = true;

{
long nLength = posTok;
if (fl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(fl->data, (nLength+50)*sizeof(struct Tok));
fl->data = newPtr;
}
fl->data[posTok] = ppt;
fl->length = nLength+1;
} else {
fl->data[posTok] = ppt;
}
};
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
char * ____BAH_COMPILER_VAR_871 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_871 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_871+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_871+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_871;

{
long nLength = i-1;
if (fl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(fl->data, (nLength+50)*sizeof(struct Tok));
fl->data = newPtr;
}
fl->data[i-1] = pt;
fl->length = nLength+1;
} else {
fl->data[i-1] = pt;
}
};
i--;
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
for (; (i<len(fl)); i++) {
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
char * ____BAH_COMPILER_VAR_872 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ptt);
long int strLen_1 = strlen(".");
long int strLen_2 = strlen("Cannot use {TOKEN} on ");
;                            
            ____BAH_COMPILER_VAR_872 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_872+currStrOff, "Cannot use {TOKEN} on ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_872+currStrOff, ptt, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_872+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&t,____BAH_COMPILER_VAR_872);
}
char * ____BAH_COMPILER_VAR_873 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_873 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_873+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_873+currStrOff, nt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_874 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_873);
;                            
            ____BAH_COMPILER_VAR_874 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_874+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_874+currStrOff, ____BAH_COMPILER_VAR_873, strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_874;

{
long nLength = i-1;
if (fl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(fl->data, (nLength+50)*sizeof(struct Tok));
fl->data = newPtr;
}
fl->data[i-1] = pt;
fl->length = nLength+1;
} else {
fl->data[i-1] = pt;
}
};
deleteRange(fl,i,i+1);
i = i-2;
}
else if ((t.type==TOKEN_TYPE_VAR)&&(strcmp(t.bahType, "") != 0)) {
if ((t.cont[0]==38)) {
char * ____BAH_COMPILER_VAR_875 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t.bahType);
long int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_875 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_875+currStrOff, t.bahType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_875+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }t.bahType = ____BAH_COMPILER_VAR_875;

{
long nLength = i;
if (fl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(fl->data, (nLength+50)*sizeof(struct Tok));
fl->data = newPtr;
}
fl->data[i] = t;
fl->length = nLength+1;
} else {
fl->data[i] = t;
}
};
}
else if ((t.cont[0]==42)) {
struct string tt = string(t.bahType);
tt.replace(&tt,"*","");
t.bahType = tt.str(&tt);

{
long nLength = i;
if (fl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(fl->data, (nLength+50)*sizeof(struct Tok));
fl->data = newPtr;
}
fl->data[i] = t;
fl->length = nLength+1;
} else {
fl->data[i] = t;
}
};
}
}
};
fl = parseArrayType(fl,elems,true);
if ((RCPavailable()==true)) {
addRCPvars(fl,ltp,elems);
}
if ((ltp!=(lineType)-1)) {
while ((sepI<len(line))) {

{
long nLength = len(fl);
if (fl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(fl->data, (nLength+50)*sizeof(struct Tok));
fl->data = newPtr;
}
fl->data[len(fl)] = line->data[sepI];
fl->length = nLength+1;
} else {
fl->data[len(fl)] = line->data[sepI];
}
};
sepI++;
};
}
return fl;
};
void parseFnDeclare(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
long int i = 0;
struct func* ____BAH_COMPILER_VAR_876 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_876->name = "";
____BAH_COMPILER_VAR_876->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_876->args->length = 0;
            ____BAH_COMPILER_VAR_876->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_876->returns= null;
____BAH_COMPILER_VAR_876->isBinding = false;
____BAH_COMPILER_VAR_876->from = "";
____BAH_COMPILER_VAR_876->file = "";
____BAH_COMPILER_VAR_876->line = 1;
____BAH_COMPILER_VAR_876->used = false;
____BAH_COMPILER_VAR_876->code = null;
struct func* fn = ____BAH_COMPILER_VAR_876;
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
char * ____BAH_COMPILER_VAR_877 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(lineStr);
long int strLen_1 = strlen(".");
long int strLen_2 = strlen(":");
long int strLen_3 = strlen(ogFn->file);
long int strLen_4 = strlen("Cannot redeclare function {TOKEN}, previous declaration: ");
;                            
            ____BAH_COMPILER_VAR_877 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_877+currStrOff, "Cannot redeclare function {TOKEN}, previous declaration: ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_877+currStrOff, ogFn->file, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_877+currStrOff, ":", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_877+currStrOff, lineStr, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_877+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&ft,____BAH_COMPILER_VAR_877);
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
if ((shouldOnlyDecl==true)) {
if ((ogFn!=null)) {
fn->isBinding = false;
}

{
long nLength = len(elems->fns);
if (elems->fns->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(elems->fns->data, (nLength+50)*sizeof(struct func*));
elems->fns->data = newPtr;
}
elems->fns->data[len(elems->fns)] = fn;
elems->fns->length = nLength+1;
} else {
elems->fns->data[len(elems->fns)] = fn;
}
};
char * ____BAH_COMPILER_VAR_878 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(";\n");
;                            
            ____BAH_COMPILER_VAR_878 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_878+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_878+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_878));
return;
}
char * ____BAH_COMPILER_VAR_879 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen("{\n");
;                            
            ____BAH_COMPILER_VAR_879 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_879+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_879+currStrOff, "{\n", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_879;
fn->code = rope(code);
struct Elems* fnElems = dupElems(elems);
array(struct variable*)* vs = fnElems->vars;
register long int j = 0;
while ((j<len(fn->args))) {
struct variable* a = fn->args->data[j];
a->declScope = elems;

{
long nLength = len(vs);
if (vs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(vs->data, (nLength+50)*sizeof(struct variable*));
vs->data = newPtr;
}
vs->data[len(vs)] = a;
vs->length = nLength+1;
} else {
vs->data[len(vs)] = a;
}
};
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

{
long nLength = len(fns);
if (fns->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(fns->data, (nLength+50)*sizeof(struct func*));
fns->data = newPtr;
}
fns->data[len(fns)] = fn;
fns->length = nLength+1;
} else {
fns->data[len(fns)] = fn;
}
};
}
array(struct Tok)* tokens = memoryAlloc(sizeof(array(struct Tok)));

tokens->length = 0;
tokens->elemSize = sizeof(struct Tok);
i++;
long int max = len(l)-1;
while ((i<max)) {
struct Tok t = l->data[i];

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] = t;
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] = t;
}
};
i++;
};
if ((len(tokens)==0)) {
fn->code = fn->code->add(fn->code, rope("};\n"));
OUTPUT = OUTPUT->add(OUTPUT, fn->code);
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
compilerState.currFnElems = ocurrFnElems;
currentFn = null;
if ((fn->returned==false)) {
if ((strlen(fn->returns->type)>0)) {
char * ____BAH_COMPILER_VAR_880 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fn->name);
long int strLen_1 = strlen("' is not returned.");
long int strLen_2 = strlen("Function '");
;                            
            ____BAH_COMPILER_VAR_880 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_880+currStrOff, "Function '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_880+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_880+currStrOff, "' is not returned.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&l->data[len(l)-1],____BAH_COMPILER_VAR_880);
}
endRCPscope(fnElems,fn->args);
}
fn->code = fn->code->add(fn->code, OUTPUT);
OUTPUT = oOut;
fn->code = fn->code->add(fn->code, rope("};\n"));
OUTPUT = OUTPUT->add(OUTPUT, fn->code);
if ((debug==true)) {
struct debugFunction* ____BAH_COMPILER_VAR_881 = memoryAlloc(sizeof(struct debugFunction));
____BAH_COMPILER_VAR_881->name= null;
____BAH_COMPILER_VAR_881->returns= null;
____BAH_COMPILER_VAR_881->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_881->args->length = 0;
            ____BAH_COMPILER_VAR_881->args->elemSize = sizeof(struct variable*);
            struct debugFunction* df = ____BAH_COMPILER_VAR_881;
df->name = fn->name;
df->args = fn->args;
df->returns = fn->returns->type;
struct debugFunction* ____BAH_COMPILER_VAR_882 = df;
char ** ____BAH_COMPILER_VAR_884 = (char **)((char*)(____BAH_COMPILER_VAR_882) + offsetof(struct debugFunction, name));
struct reflectElement ____BAH_COMPILER_VAR_885 = __reflect(____BAH_COMPILER_VAR_884, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct debugFunction, name));
char ** ____BAH_COMPILER_VAR_886 = (char **)((char*)(____BAH_COMPILER_VAR_882) + offsetof(struct debugFunction, returns));
struct reflectElement ____BAH_COMPILER_VAR_887 = __reflect(____BAH_COMPILER_VAR_886, sizeof(char *), "cpstring", "returns", 0, 0, 0, 0, offsetof(struct debugFunction, returns));
array(struct variable*)** ____BAH_COMPILER_VAR_888 = (array(struct variable*)**)((char*)(____BAH_COMPILER_VAR_882) + offsetof(struct debugFunction, args));
struct variable** ____BAH_COMPILER_VAR_889 = 0;
char ** ____BAH_COMPILER_VAR_891 = (char **)((char*)(____BAH_COMPILER_VAR_889) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_892 = __reflect(____BAH_COMPILER_VAR_891, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_893 = (char **)((char*)(____BAH_COMPILER_VAR_889) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_894 = __reflect(____BAH_COMPILER_VAR_893, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_895 = (char*)((char*)(____BAH_COMPILER_VAR_889) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_896 = __reflect(____BAH_COMPILER_VAR_895, sizeof(char), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_897 = (char **)((char*)(____BAH_COMPILER_VAR_889) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_898 = __reflect(____BAH_COMPILER_VAR_897, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_899 = (char*)((char*)(____BAH_COMPILER_VAR_889) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_900 = __reflect(____BAH_COMPILER_VAR_899, sizeof(char), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_901 = (char **)((char*)(____BAH_COMPILER_VAR_889) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_902 = __reflect(____BAH_COMPILER_VAR_901, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
void ** ____BAH_COMPILER_VAR_903 = (void **)((char*)(____BAH_COMPILER_VAR_889) + offsetof(struct variable, declScope));
struct reflectElement ____BAH_COMPILER_VAR_904 = __reflect(____BAH_COMPILER_VAR_903, sizeof(void *), "ptr", "declScope", 0, 0, 0, 0, offsetof(struct variable, declScope));
char* ____BAH_COMPILER_VAR_905 = (char*)((char*)(____BAH_COMPILER_VAR_889) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_906 = __reflect(____BAH_COMPILER_VAR_905, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));
struct rope** ____BAH_COMPILER_VAR_907 = (struct rope**)((char*)(____BAH_COMPILER_VAR_889) + offsetof(struct variable, declRope));
void ** ____BAH_COMPILER_VAR_909 = (void **)((char*)(____BAH_COMPILER_VAR_907) + offsetof(struct rope, left));
struct reflectElement ____BAH_COMPILER_VAR_910 = __reflect(____BAH_COMPILER_VAR_909, sizeof(void *), "ptr", "left", 0, 0, 0, 0, offsetof(struct rope, left));
void ** ____BAH_COMPILER_VAR_911 = (void **)((char*)(____BAH_COMPILER_VAR_907) + offsetof(struct rope, right));
struct reflectElement ____BAH_COMPILER_VAR_912 = __reflect(____BAH_COMPILER_VAR_911, sizeof(void *), "ptr", "right", 0, 0, 0, 0, offsetof(struct rope, right));
char ** ____BAH_COMPILER_VAR_913 = (char **)((char*)(____BAH_COMPILER_VAR_907) + offsetof(struct rope, str));
struct reflectElement ____BAH_COMPILER_VAR_914 = __reflect(____BAH_COMPILER_VAR_913, sizeof(char *), "cpstring", "str", 0, 0, 0, 0, offsetof(struct rope, str));
long int* ____BAH_COMPILER_VAR_915 = (long int*)((char*)(____BAH_COMPILER_VAR_907) + offsetof(struct rope, lCount));
struct reflectElement ____BAH_COMPILER_VAR_916 = __reflect(____BAH_COMPILER_VAR_915, sizeof(long int), "int", "lCount", 0, 0, 0, 0, offsetof(struct rope, lCount));
long int* ____BAH_COMPILER_VAR_917 = (long int*)((char*)(____BAH_COMPILER_VAR_907) + offsetof(struct rope, len));
struct reflectElement ____BAH_COMPILER_VAR_918 = __reflect(____BAH_COMPILER_VAR_917, sizeof(long int), "int", "len", 0, 0, 0, 0, offsetof(struct rope, len));
long int* ____BAH_COMPILER_VAR_919 = (long int*)((char*)(____BAH_COMPILER_VAR_907) + offsetof(struct rope, totalLen));
struct reflectElement ____BAH_COMPILER_VAR_920 = __reflect(____BAH_COMPILER_VAR_919, sizeof(long int), "int", "totalLen", 0, 0, 0, 0, offsetof(struct rope, totalLen));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_908 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_908->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_908->length = 6;
        ____BAH_COMPILER_VAR_908->data = memoryAlloc(____BAH_COMPILER_VAR_908->length * ____BAH_COMPILER_VAR_908->elemSize);
        ____BAH_COMPILER_VAR_908->data[0] = ____BAH_COMPILER_VAR_910;
____BAH_COMPILER_VAR_908->data[1] = ____BAH_COMPILER_VAR_912;
____BAH_COMPILER_VAR_908->data[2] = ____BAH_COMPILER_VAR_914;
____BAH_COMPILER_VAR_908->data[3] = ____BAH_COMPILER_VAR_916;
____BAH_COMPILER_VAR_908->data[4] = ____BAH_COMPILER_VAR_918;
____BAH_COMPILER_VAR_908->data[5] = ____BAH_COMPILER_VAR_920;
struct reflectElement ____BAH_COMPILER_VAR_921 = __reflect(____BAH_COMPILER_VAR_907, sizeof(struct rope), "rope*", "declRope", 0, 0, 1, ____BAH_COMPILER_VAR_908, offsetof(struct variable, declRope));
char* ____BAH_COMPILER_VAR_922 = (char*)((char*)(____BAH_COMPILER_VAR_889) + offsetof(struct variable, canBeReg));
struct reflectElement ____BAH_COMPILER_VAR_923 = __reflect(____BAH_COMPILER_VAR_922, sizeof(char), "bool", "canBeReg", 0, 0, 0, 0, offsetof(struct variable, canBeReg));
char* ____BAH_COMPILER_VAR_924 = (char*)((char*)(____BAH_COMPILER_VAR_889) + offsetof(struct variable, isReg));
struct reflectElement ____BAH_COMPILER_VAR_925 = __reflect(____BAH_COMPILER_VAR_924, sizeof(char), "bool", "isReg", 0, 0, 0, 0, offsetof(struct variable, isReg));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_890 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_890->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_890->length = 11;
        ____BAH_COMPILER_VAR_890->data = memoryAlloc(____BAH_COMPILER_VAR_890->length * ____BAH_COMPILER_VAR_890->elemSize);
        ____BAH_COMPILER_VAR_890->data[0] = ____BAH_COMPILER_VAR_892;
____BAH_COMPILER_VAR_890->data[1] = ____BAH_COMPILER_VAR_894;
____BAH_COMPILER_VAR_890->data[2] = ____BAH_COMPILER_VAR_896;
____BAH_COMPILER_VAR_890->data[3] = ____BAH_COMPILER_VAR_898;
____BAH_COMPILER_VAR_890->data[4] = ____BAH_COMPILER_VAR_900;
____BAH_COMPILER_VAR_890->data[5] = ____BAH_COMPILER_VAR_902;
____BAH_COMPILER_VAR_890->data[6] = ____BAH_COMPILER_VAR_904;
____BAH_COMPILER_VAR_890->data[7] = ____BAH_COMPILER_VAR_906;
____BAH_COMPILER_VAR_890->data[8] = ____BAH_COMPILER_VAR_921;
____BAH_COMPILER_VAR_890->data[9] = ____BAH_COMPILER_VAR_923;
____BAH_COMPILER_VAR_890->data[10] = ____BAH_COMPILER_VAR_925;
struct reflectElement ____BAH_COMPILER_VAR_926 = __reflect(____BAH_COMPILER_VAR_889, sizeof(struct variable), "variable*", "", 0, 0, 1, ____BAH_COMPILER_VAR_890, 0);

        struct reflectElement ____BAH_COMPILER_VAR_927 = ____BAH_COMPILER_VAR_926;
        struct reflectElement ____BAH_COMPILER_VAR_928 = __reflect(____BAH_COMPILER_VAR_888, sizeof(array(struct variable*)*), "[]variable*", "args", 1, &____BAH_COMPILER_VAR_927, 0, 0, offsetof(struct debugFunction, args));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_883 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_883->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_883->length = 3;
        ____BAH_COMPILER_VAR_883->data = memoryAlloc(____BAH_COMPILER_VAR_883->length * ____BAH_COMPILER_VAR_883->elemSize);
        ____BAH_COMPILER_VAR_883->data[0] = ____BAH_COMPILER_VAR_885;
____BAH_COMPILER_VAR_883->data[1] = ____BAH_COMPILER_VAR_887;
____BAH_COMPILER_VAR_883->data[2] = ____BAH_COMPILER_VAR_928;
struct reflectElement ____BAH_COMPILER_VAR_929 = __reflect(____BAH_COMPILER_VAR_882, sizeof(struct debugFunction), "debugFunction*", "df", 0, 0, 1, ____BAH_COMPILER_VAR_883, 0);
debugPrint("fn_declare",ft.line,____BAH_COMPILER_VAR_929);
struct Tok lt = l->data[len(l)-1];
debugEndScope(lt.line,fnElems);
}
};
void parseLine(__BAH_ARR_TYPE_Tok line,struct Elems* elems){
if ((len(line)==0)) {
return;
}
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
struct func* fn = searchFuncByToken(ft,elems);
if ((fn!=null)&&(fn->returns!=null)&&isRCPtype(fn->returns->type,elems)) {
char * ____BAH_COMPILER_VAR_930 =registerRCPvar(fn->returns->type,ft.cont,elems);return;
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
char * ____BAH_COMPILER_VAR_931 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ft.cont);
long int strLen_1 = strlen(";\n");
;                            
            ____BAH_COMPILER_VAR_931 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_931+currStrOff, ft.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_931+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_931));
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
parseIf(line,elems);
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
if ((parsed==false)) {
throwErr(&ft,"{TOKEN} not expected.");
}
if ((strlen(NEXT_LINE)>0)) {
OUTPUT = OUTPUT->add(OUTPUT, rope(NEXT_LINE));
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
long int currentLine = ft.line;
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

{
long nLength = len(line);
if (line->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(line->data, (nLength+50)*sizeof(struct Tok));
line->data = newPtr;
}
line->data[len(line)] = t;
line->length = nLength+1;
} else {
line->data[len(line)] = t;
}
};
struct Tok pt = tokens->data[i-1];
currentLine = pt.line;
}
else {
currentLine = t.line;
}
parseLine(line,elems);
clear(line);
if ((t.type==TOKEN_TYPE_ENCL)) {
i++;
continue;
}
}
else if ((strcmp(t.cont, ";") == 0)) {
currentLine = t.line;
parseLine(line,elems);
clear(line);
i++;
continue;
}
}

{
long nLength = len(line);
if (line->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(line->data, (nLength+50)*sizeof(struct Tok));
line->data = newPtr;
}
line->data[len(line)] = t;
line->length = nLength+1;
} else {
line->data[len(line)] = t;
}
};
i++;
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
char * ____BAH_COMPILER_VAR_932 =null;char * ____BAH_COMPILER_VAR_933 =ct.str(&ct);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(" ");
long int strLen_1 = strlen(arg->name);
long int strLen_2 = strlen(____BAH_COMPILER_VAR_933);
long int strLen_3 = strlen(tmpfnArgsCType);
;                            
            ____BAH_COMPILER_VAR_932 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_932+currStrOff, tmpfnArgsCType, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_932+currStrOff, ____BAH_COMPILER_VAR_933, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_932+currStrOff, " ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_932+currStrOff, arg->name, strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_932;
j = j+1;
if ((j<len(fn->args))) {
char * ____BAH_COMPILER_VAR_934 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(", ");
;                            
            ____BAH_COMPILER_VAR_934 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_934+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_934+currStrOff, ", ", strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_934;
}
};
char * ____BAH_COMPILER_VAR_935 =null;char * ____BAH_COMPILER_VAR_936 =tmpfnRetCType.str(&tmpfnRetCType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(");\n");
long int strLen_2 = strlen("(");
long int strLen_3 = strlen(fn->name);
long int strLen_4 = strlen(" ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_936);
;                            
            ____BAH_COMPILER_VAR_935 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_935+currStrOff, ____BAH_COMPILER_VAR_936, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_935+currStrOff, " ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_935+currStrOff, fn->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_935+currStrOff, "(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_935+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_935+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_935));
};
void declareVar(struct variable* v,struct Elems* elems){
if ((v->isConst==true)) {
char * ____BAH_COMPILER_VAR_937 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(v->constVal);
long int strLen_1 = strlen("\n");
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen("#define ");
;                            
            ____BAH_COMPILER_VAR_937 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_937+currStrOff, "#define ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_937+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_937+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_937+currStrOff, v->constVal, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_937+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_937));
}
else {
struct string cType = getCType(v->type,elems);
char * ____BAH_COMPILER_VAR_938 =null;char * ____BAH_COMPILER_VAR_939 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_939);
;                            
            ____BAH_COMPILER_VAR_938 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_938+currStrOff, ____BAH_COMPILER_VAR_939, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_938+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_938+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_938+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_938));
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
for (; (i<len(compilerState.cIncludes)); i++) {
char * ____BAH_COMPILER_VAR_940 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(compilerState.cIncludes->data[i]);
long int strLen_1 = strlen("\n");
long int strLen_2 = strlen("#include ");
;                            
            ____BAH_COMPILER_VAR_940 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_940+currStrOff, "#include ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_940+currStrOff, compilerState.cIncludes->data[i], strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_940+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_940));
};
i = 1;
for (; (i<len(compilerState.arrTypesDecl)); i++) {
char * t = compilerState.arrTypesDecl->data[i];
struct string elemType = string(t);
elemType.trimLeft(&elemType,15);
char * ____BAH_COMPILER_VAR_941 =elemType.str(&elemType);struct string elemCtype = getCType(____BAH_COMPILER_VAR_941,elems);
char * ____BAH_COMPILER_VAR_942 =null;char * ____BAH_COMPILER_VAR_943 =elemCtype.str(&elemCtype);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen(")* ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_943);
long int strLen_4 = strlen("typedef array(");
;                            
            ____BAH_COMPILER_VAR_942 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_942+currStrOff, "typedef array(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_942+currStrOff, ____BAH_COMPILER_VAR_943, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_942+currStrOff, ")* ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_942+currStrOff, t, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_942+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_942));
};
i = 0;
for (; (i<len(elems->vars)); i++) {
struct variable* v = elems->vars->data[i];
declareVar(v,elems);
};
i = 0;
for (; (i<len(elems->fns)); i++) {
struct func* fn = elems->fns->data[i];
if ((fn->isBinding==true)) {
continue;
}
declareFunc(fn,elems);
};
};
char * memErrHandle(){
char * ____BAH_COMPILER_VAR_944 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("file: ");
long int strLen_1 = strlen(compilerState.currentFile);
;                            
            ____BAH_COMPILER_VAR_944 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_944+currStrOff, "file: ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_944+currStrOff, compilerState.currentFile, strLen_1);
            currStrOff += strLen_1;
        
        }char * r = ____BAH_COMPILER_VAR_944;
if ((currentFn!=null)) {
char * ____BAH_COMPILER_VAR_945 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(currentFn->name);
long int strLen_1 = strlen("()");
long int strLen_2 = strlen("\nfunction: ");
;                            
            ____BAH_COMPILER_VAR_945 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_945+currStrOff, "\nfunction: ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_945+currStrOff, currentFn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_945+currStrOff, "()", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_946 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(r);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_945);
;                            
            ____BAH_COMPILER_VAR_946 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_946+currStrOff, r, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_946+currStrOff, ____BAH_COMPILER_VAR_945, strLen_1);
            currStrOff += strLen_1;
        
        }r = ____BAH_COMPILER_VAR_946;
}
return r;
};
long int main(__BAH_ARR_TYPE_cpstring args){
onMemoryError = memErrHandle;
execName = args->data[0];
if ((execName[0]==46)||(execName[0]==47)) {
execName = absPath(execName);
}
struct flags ____BAH_COMPILER_VAR_947 = {};
____BAH_COMPILER_VAR_947.flags = memoryAlloc(sizeof(array(struct flag*)));
            ____BAH_COMPILER_VAR_947.flags->length = 0;
            ____BAH_COMPILER_VAR_947.flags->elemSize = sizeof(struct flag*);
            ____BAH_COMPILER_VAR_947.args = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_947.args->length = 0;
            ____BAH_COMPILER_VAR_947.args->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_947.addString = flags__addString;
____BAH_COMPILER_VAR_947.addBool = flags__addBool;
____BAH_COMPILER_VAR_947.addInt = flags__addInt;
____BAH_COMPILER_VAR_947.addFloat = flags__addFloat;
____BAH_COMPILER_VAR_947.invalidate = flags__invalidate;
____BAH_COMPILER_VAR_947.getFlag = flags__getFlag;
____BAH_COMPILER_VAR_947.get = flags__get;
____BAH_COMPILER_VAR_947.getInt = flags__getInt;
____BAH_COMPILER_VAR_947.getFloat = flags__getFloat;
____BAH_COMPILER_VAR_947.isSet = flags__isSet;
____BAH_COMPILER_VAR_947.parse = flags__parse;
flags = ____BAH_COMPILER_VAR_947;
flags.addString(&flags,"o","Name of the file to output.");
flags.addBool(&flags,"c","Translate bah file to C instead of compiling it.");
flags.addBool(&flags,"v","Show version of the compiler.");
flags.addBool(&flags,"l","Compile as a library.");
flags.addBool(&flags,"d","Compile as a dynamic executable. (useful if you are using a library that is only available shared but might reduce portability).");
flags.addBool(&flags,"rcp","Enables RCP (reference counter) instead of the garbage collector. Warning: if you are using self-reference, this will lead to memory leaks!");
flags.addBool(&flags,"fastrcp","Enables RCP without leak detection. It is recommended to test you programs with the -rcp flag to test for leak detection before using this flag.");
flags.addBool(&flags,"debug","Enables verbose json output.");
flags.addBool(&flags,"verboseRuntime","Enables verbose runtime, a debug mode of the compiled program. (obsolete)");
flags.addBool(&flags,"verboseCC","Enables verbose C compiler output, USE IN LAST RESORT.");
char * ____BAH_COMPILER_VAR_948 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(BAH_OS);
long int strLen_1 = strlen(".");
long int strLen_2 = strlen("Select the target OS for cross compilling (linux, windows, darwin), default: ");
;                            
            ____BAH_COMPILER_VAR_948 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_948+currStrOff, "Select the target OS for cross compilling (linux, windows, darwin), default: ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_948+currStrOff, BAH_OS, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_948+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }flags.addString(&flags,"target",____BAH_COMPILER_VAR_948);
char * ____BAH_COMPILER_VAR_949 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen(").");
long int strLen_2 = strlen("If your Bah directory is not the default one (");
;                            
            ____BAH_COMPILER_VAR_949 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_949+currStrOff, "If your Bah directory is not the default one (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_949+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_949+currStrOff, ").", strLen_1);
            currStrOff += strLen_1;
        
        }flags.addString(&flags,"bahDir",____BAH_COMPILER_VAR_949);
char * ____BAH_COMPILER_VAR_950 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(BAH_CC);
long int strLen_1 = strlen(".");
long int strLen_2 = strlen("To change the C compiler used, default: ");
;                            
            ____BAH_COMPILER_VAR_950 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_950+currStrOff, "To change the C compiler used, default: ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_950+currStrOff, BAH_CC, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_950+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }flags.addString(&flags,"CC",____BAH_COMPILER_VAR_950);
flags.addBool(&flags,"object","Compile as an object.");
flags.addBool(&flags,"unsafe","Compile without safety checking. This will make for faster executable but if your program crashes, it will show less informations.");
flags.parse(&flags,args);
if ((flags.isSet(&flags,"target")==1)) {
BAH_OS = flags.get(&flags,"target");
char * ____BAH_COMPILER_VAR_951 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("Build target: ");
long int strLen_1 = strlen(BAH_OS);
;                            
            ____BAH_COMPILER_VAR_951 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_951+currStrOff, "Build target: ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_951+currStrOff, BAH_OS, strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_951);
}
if ((flags.isSet(&flags,"bahDir")==1)) {
BAH_DIR = flags.get(&flags,"bahDir");
array(char)* bahDirArr = strAsArr(BAH_DIR);
if ((bahDirArr->data[len(bahDirArr)-1]!=47)) {
char * ____BAH_COMPILER_VAR_952 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen("/");
;                            
            ____BAH_COMPILER_VAR_952 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_952+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_952+currStrOff, "/", strLen_1);
            currStrOff += strLen_1;
        
        }BAH_DIR = ____BAH_COMPILER_VAR_952;
}
char * ____BAH_COMPILER_VAR_953 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("Bah directory: ");
long int strLen_1 = strlen(BAH_DIR);
;                            
            ____BAH_COMPILER_VAR_953 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_953+currStrOff, "Bah directory: ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_953+currStrOff, BAH_DIR, strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_953);
}
if ((flags.isSet(&flags,"CC")==1)) {
BAH_CC = flags.get(&flags,"CC");
char * ____BAH_COMPILER_VAR_954 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("C compiler: ");
long int strLen_1 = strlen(BAH_CC);
;                            
            ____BAH_COMPILER_VAR_954 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_954+currStrOff, "C compiler: ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_954+currStrOff, BAH_CC, strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_954);
}
if (flags.isSet(&flags,"verboseRuntime")) {
println("-verboseRuntime is obsolete.");
exit(1);
}
RCPlevel = 0;
if (flags.isSet(&flags,"rcp")) {
RCPlevel = 1;
}
else if (flags.isSet(&flags,"fastrcp")) {
RCPlevel = 2;
}
verboseRuntime = (flags.isSet(&flags,"verboseRuntime")==1);
debug = (flags.isSet(&flags,"debug")==1);
isObject = (flags.isSet(&flags,"object")==1);
isUnsafe = (flags.isSet(&flags,"unsafe")==1);
if ((debug==true)) {
debugStart();
}
RCPenabled = (flags.isSet(&flags,"rcp")==1)||flags.isSet(&flags,"fastrcp");
if ((flags.isSet(&flags,"v")==1)) {
char * ____BAH_COMPILER_VAR_955 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(BAH_VERSION);
long int strLen_1 = strlen(".\n© Alois Laurent Boe");
long int strLen_2 = strlen("Bah compiler version: ");
;                            
            ____BAH_COMPILER_VAR_955 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_955+currStrOff, "Bah compiler version: ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_955+currStrOff, BAH_VERSION, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_955+currStrOff, ".\n© Alois Laurent Boe", strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_955);
return 0;
}
if ((flags.isSet(&flags,"c")==1)&&(flags.isSet(&flags,"l")==1)) {
__BAH_panic("Cannot use -c (to translate to C code) and -l (to compile as a library) at the same time.","/home/alois/Documents/bah-bah/src/main.bah:135");
}
INIT = rope("");
OUTPUT = rope("\n    void __BAH_init();\n    #define noCheck(v) v\n    #define array(type)	\
    struct{	\
    type *data; \
    long int length; \
    long int elemSize; \
    }\n    typedef array(char*)* __BAH_ARR_TYPE_cpstring;\n    long int __BAH__main(__BAH_ARR_TYPE_cpstring);\n    ");
if ((flags.isSet(&flags,"l")==0)) {
if ((RCPenabled==true)) {
OUTPUT = OUTPUT->add(OUTPUT, rope("\n            void RCP_init();\n            void RCP_shutdown();\n            void free(void*);\n            #include <string.h>\n            int main(int argc, char ** argv) {\n            RCP_init();\n            array(char*) * args = malloc(sizeof(array(char*)));\n            args->data = malloc(sizeof(char*)*argc);\n            memcpy(args->data, argv, sizeof(char*)*argc);\n            args->elemSize = sizeof(char*);\n            args->length = argc;\n            __BAH_init();\n            long int r =  __BAH__main((__BAH_ARR_TYPE_cpstring)args);\n            free(args->data);\n            free(args);\n            RCP_shutdown();\n            return r;\n            };\n            #define main(v) __BAH__main(v)\n            "));
}
else {
OUTPUT = OUTPUT->add(OUTPUT, rope("\n            #include <gc.h>\n            #include <string.h>\n            int main(int argc, char ** argv) {\n            GC_INIT();\n            array(char*) * args = GC_MALLOC(sizeof(array(char*)));\n            args->data = GC_MALLOC(sizeof(char*)*argc);\n            memcpy(args->data, argv, sizeof(char*)*argc);\n            args->elemSize = sizeof(char*);\n            args->length = argc;\n            __BAH_init();\n            long int r =  __BAH__main((__BAH_ARR_TYPE_cpstring)args);\n            GC_FREE(args->data);\n            GC_FREE(args);\n            return r;\n            };\n            #define main(v) __BAH__main(v)\n            "));
}
}
struct compilerStateTag ____BAH_COMPILER_VAR_956 = {};
____BAH_COMPILER_VAR_956.includes = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_956.includes->length = 0;
            ____BAH_COMPILER_VAR_956.includes->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_956.cIncludes = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_956.cIncludes->length = 0;
            ____BAH_COMPILER_VAR_956.cIncludes->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_956.cLibs = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_956.cLibs->length = 0;
            ____BAH_COMPILER_VAR_956.cLibs->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_956.currentFile= null;
____BAH_COMPILER_VAR_956.currentDir = "./";
____BAH_COMPILER_VAR_956.isBranch = false;
____BAH_COMPILER_VAR_956.isFor = false;
____BAH_COMPILER_VAR_956.arrTypesDecl = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_956.arrTypesDecl->length = 0;
            ____BAH_COMPILER_VAR_956.arrTypesDecl->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_956.haveEntryPoint = false;
____BAH_COMPILER_VAR_956.RCPvars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_956.RCPvars->length = 0;
            ____BAH_COMPILER_VAR_956.RCPvars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_956.evals = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_956.evals->length = 0;
            ____BAH_COMPILER_VAR_956.evals->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_956.hasImports = false;
____BAH_COMPILER_VAR_956.currForElems= null;
____BAH_COMPILER_VAR_956.currFnElems= null;
compilerState = ____BAH_COMPILER_VAR_956;

{
long nLength = 0;
if (compilerState.arrTypesDecl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(compilerState.arrTypesDecl->data, (nLength+50)*sizeof(char *));
compilerState.arrTypesDecl->data = newPtr;
}
compilerState.arrTypesDecl->data[0] = "__BAH_ARR_TYPE_cpstring";
compilerState.arrTypesDecl->length = nLength+1;
} else {
compilerState.arrTypesDecl->data[0] = "__BAH_ARR_TYPE_cpstring";
}
};
char * fileName = absPath(args->data[1]);
compilerState.currentFile = fileName;
struct fileMap ____BAH_COMPILER_VAR_957 = {};
____BAH_COMPILER_VAR_957.handle = -1;
____BAH_COMPILER_VAR_957.p= null;
____BAH_COMPILER_VAR_957.open = fileMap__open;
____BAH_COMPILER_VAR_957.isValid = fileMap__isValid;
____BAH_COMPILER_VAR_957.close = fileMap__close;
#define fm ____BAH_COMPILER_VAR_957
char * f = fm.open(&fm,fileName);
if ((fm.isValid(&fm)==0)||(fm.size==0)) {
char * ____BAH_COMPILER_VAR_958 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(args->data[1]);
long int strLen_1 = strlen("'.");
long int strLen_2 = strlen("Could not open file '");
;                            
            ____BAH_COMPILER_VAR_958 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_958+currStrOff, "Could not open file '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_958+currStrOff, args->data[1], strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_958+currStrOff, "'.", strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_958);
exit(1);
}
long int startTime = getTimeUnix();
array(struct Tok)* tokens = lexer(f);
fm.close(&fm);
if ((len(tokens)==0)) {
char * ____BAH_COMPILER_VAR_959 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fileName);
long int strLen_1 = strlen("' not recognized.");
long int strLen_2 = strlen("File '");
;                            
            ____BAH_COMPILER_VAR_959 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_959+currStrOff, "File '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_959+currStrOff, fileName, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_959+currStrOff, "' not recognized.", strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_959);
exit(1);
}
struct Elems* ____BAH_COMPILER_VAR_960 = memoryAlloc(sizeof(struct Elems));
____BAH_COMPILER_VAR_960->vars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_960->vars->length = 0;
            ____BAH_COMPILER_VAR_960->vars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_960->structs = memoryAlloc(sizeof(array(struct cStruct*)));
            ____BAH_COMPILER_VAR_960->structs->length = 0;
            ____BAH_COMPILER_VAR_960->structs->elemSize = sizeof(struct cStruct*);
            ____BAH_COMPILER_VAR_960->types = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_960->types->length = 0;
            ____BAH_COMPILER_VAR_960->types->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_960->fns = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_960->fns->length = 0;
            ____BAH_COMPILER_VAR_960->fns->elemSize = sizeof(struct func*);
            ____BAH_COMPILER_VAR_960->defined = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_960->defined->length = 0;
            ____BAH_COMPILER_VAR_960->defined->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_960->parent= null;
struct Elems* elems = ____BAH_COMPILER_VAR_960;
if ((isObject==true)) {
OUTPUT = rope("\n        #define noCheck(v) v\n        #define array(type)	\
        struct{	\
        type *data; \
        long int length; \
        long int elemSize; \
        }\n        typedef array(char*)* __BAH_ARR_TYPE_cpstring;\n        long int __BAH__main(__BAH_ARR_TYPE_cpstring);\n        ");
shouldOnlyDecl = true;
}
if ((includeFile("builtin.bah",elems)==false)) {
char * ____BAH_COMPILER_VAR_961 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen("'");
long int strLen_2 = strlen("Could not find std-libs, please check '");
;                            
            ____BAH_COMPILER_VAR_961 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_961+currStrOff, "Could not find std-libs, please check '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_961+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_961+currStrOff, "'", strLen_1);
            currStrOff += strLen_1;
        
        }__BAH_panic(____BAH_COMPILER_VAR_961,"/home/alois/Documents/bah-bah/src/main.bah:243");
}
shouldOnlyDecl = false;
if ((flags.isSet(&flags,"l")==1)) {
OUTPUT = rope("");
declareAll(elems);
}
compilerState.currentDir = getDirFromFile(fileName);
parseLines(tokens,elems);
if ((isObject==false)&&(isUnsafe==false)) {
long int l = 0;
register long int i = 0;
for (; (i<len(elems->fns)); i++) {
struct func* fn = elems->fns->data[i];
if ((fn->isBinding==true)) {
continue;
}
l++;
};
char * ____BAH_COMPILER_VAR_962 =null;char * ____BAH_COMPILER_VAR_963 =intToStr(l);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_963);
long int strLen_1 = strlen("];");
long int strLen_2 = strlen("volatile struct __Bah_fnName_mapper __tmp____Bah_fnNames[");
;                            
            ____BAH_COMPILER_VAR_962 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_962+currStrOff, "volatile struct __Bah_fnName_mapper __tmp____Bah_fnNames[", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_962+currStrOff, ____BAH_COMPILER_VAR_963, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_962+currStrOff, "];", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_964 =____BAH_COMPILER_VAR_962;OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_964));
long int j = 0;
i = 0;
for (; (i<len(elems->fns)); i++) {
struct func* fn = elems->fns->data[i];
if ((fn->isBinding==true)) {
continue;
}
char * name = fn->name;
char * ____BAH_COMPILER_VAR_965 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fn->from);
long int strLen_1 = strlen("__");
;                            
            ____BAH_COMPILER_VAR_965 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_965+currStrOff, fn->from, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_965+currStrOff, "__", strLen_1);
            currStrOff += strLen_1;
        
        }if ((strcmp(fn->from, "") != 0)&&strHasPrefix(name,____BAH_COMPILER_VAR_965)) {
struct string n = string(name);
n.trimLeft(&n,strlen(fn->from)+2);
char * ____BAH_COMPILER_VAR_966 =null;char * ____BAH_COMPILER_VAR_967 =n.str(&n);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(".");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_967);
long int strLen_2 = strlen(fn->from);
;                            
            ____BAH_COMPILER_VAR_966 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_966+currStrOff, fn->from, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_966+currStrOff, ".", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_966+currStrOff, ____BAH_COMPILER_VAR_967, strLen_1);
            currStrOff += strLen_1;
        
        }name = ____BAH_COMPILER_VAR_966;
}
char * ____BAH_COMPILER_VAR_968 =null;char * ____BAH_COMPILER_VAR_969 =intToStr(j);char * ____BAH_COMPILER_VAR_970 =intToStr(j);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fn->name);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen("].p = ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_969);
long int strLen_4 = strlen("\";\n            __tmp____Bah_fnNames[");
long int strLen_5 = strlen(name);
long int strLen_6 = strlen("].n = \"");
long int strLen_7 = strlen(____BAH_COMPILER_VAR_970);
long int strLen_8 = strlen("\n            __tmp____Bah_fnNames[");
;                            
            ____BAH_COMPILER_VAR_968 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_968+currStrOff, "\n            __tmp____Bah_fnNames[", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_968+currStrOff, ____BAH_COMPILER_VAR_970, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_968+currStrOff, "].n = \"", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_968+currStrOff, name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_968+currStrOff, "\";\n            __tmp____Bah_fnNames[", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_968+currStrOff, ____BAH_COMPILER_VAR_969, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_968+currStrOff, "].p = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_968+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_968+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }INIT = INIT->add(INIT, rope(____BAH_COMPILER_VAR_968));
j++;
};
char * ____BAH_COMPILER_VAR_971 =null;char * ____BAH_COMPILER_VAR_972 =intToStr(l);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_972);
long int strLen_1 = strlen(";");
long int strLen_2 = strlen("\n        __Bah_fnNames->data = __tmp____Bah_fnNames;\n        __Bah_fnNames->length = ");
;                            
            ____BAH_COMPILER_VAR_971 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_971+currStrOff, "\n        __Bah_fnNames->data = __tmp____Bah_fnNames;\n        __Bah_fnNames->length = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_971+currStrOff, ____BAH_COMPILER_VAR_972, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_971+currStrOff, ";", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_973 =____BAH_COMPILER_VAR_971;INIT = INIT->add(INIT, rope(____BAH_COMPILER_VAR_973));
}
makeInit();
array(char *)* excludeFns = memoryAlloc(sizeof(array(char *)));

excludeFns->length = 6;
excludeFns->elemSize = sizeof(char *);
excludeFns->data = memoryAlloc(sizeof(char *) * 50);excludeFns->data[0] = "main";
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
char * ____BAH_COMPILER_VAR_974 =null;char * ____BAH_COMPILER_VAR_975 =intToStr(totalLexerTime/1000000);char * ____BAH_COMPILER_VAR_976 =intToStr(totalTime/1000000);char * ____BAH_COMPILER_VAR_977 =intToStr(totalLines);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_975);
long int strLen_1 = strlen("ms)\e[0m");
long int strLen_2 = strlen("ms, lexer time: ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_976);
long int strLen_4 = strlen(" lines, total time: ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_977);
long int strLen_6 = strlen("Parsed. (");
;                            
            ____BAH_COMPILER_VAR_974 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_974+currStrOff, "Parsed. (", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_974+currStrOff, ____BAH_COMPILER_VAR_977, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_974+currStrOff, " lines, total time: ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_974+currStrOff, ____BAH_COMPILER_VAR_976, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_974+currStrOff, "ms, lexer time: ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_974+currStrOff, ____BAH_COMPILER_VAR_975, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_974+currStrOff, "ms)\e[0m", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_978 =____BAH_COMPILER_VAR_974;println(____BAH_COMPILER_VAR_978);
}
if ((flags.isSet(&flags,"o")==1)) {
fileName = flags.get(&flags,"o");
}
else {
struct string outFileName = string(args->data[1]);
outFileName.trimRight(&outFileName,4);
fileName = outFileName.str(&outFileName);
}
char * isStatic = "-static";
if ((flags.isSet(&flags,"d")==1)||(strcmp(BAH_OS, "darwin") == 0)) {
isStatic = "";
}
if ((flags.isSet(&flags,"c")==0)) {
char * obj = "";
if ((flags.isSet(&flags,"object")==1)) {
char * ____BAH_COMPILER_VAR_979 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fileName);
long int strLen_1 = strlen(".o");
;                            
            ____BAH_COMPILER_VAR_979 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_979+currStrOff, fileName, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_979+currStrOff, ".o", strLen_1);
            currStrOff += strLen_1;
        
        }fileName = ____BAH_COMPILER_VAR_979;
obj = "-c";
}
char * randFileName = "-x c - -x none";
char * ____BAH_COMPILER_VAR_980 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(" -w -O1 -o ");
long int strLen_1 = strlen(fileName);
long int strLen_2 = strlen(obj);
long int strLen_3 = strlen(" ");
long int strLen_4 = strlen(isStatic);
long int strLen_5 = strlen(" ");
long int strLen_6 = strlen(randFileName);
long int strLen_7 = strlen("/\" ");
long int strLen_8 = strlen(BAH_OS);
long int strLen_9 = strlen("libs/");
long int strLen_10 = strlen(BAH_DIR);
long int strLen_11 = strlen("/include/\" -L \"");
long int strLen_12 = strlen(BAH_OS);
long int strLen_13 = strlen("libs/");
long int strLen_14 = strlen(BAH_DIR);
long int strLen_15 = strlen(" -I \"");
long int strLen_16 = strlen(BAH_CC);
;                            
            ____BAH_COMPILER_VAR_980 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13+strLen_14+strLen_15+strLen_16);
            
                    memcpy(____BAH_COMPILER_VAR_980+currStrOff, BAH_CC, strLen_16);
                    currStrOff += strLen_16;
                    
                    memcpy(____BAH_COMPILER_VAR_980+currStrOff, " -I \"", strLen_15);
                    currStrOff += strLen_15;
                    
                    memcpy(____BAH_COMPILER_VAR_980+currStrOff, BAH_DIR, strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_980+currStrOff, "libs/", strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_980+currStrOff, BAH_OS, strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_980+currStrOff, "/include/\" -L \"", strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_980+currStrOff, BAH_DIR, strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_980+currStrOff, "libs/", strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_980+currStrOff, BAH_OS, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_980+currStrOff, "/\" ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_980+currStrOff, randFileName, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_980+currStrOff, " ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_980+currStrOff, isStatic, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_980+currStrOff, " ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_980+currStrOff, obj, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_980+currStrOff, " -w -O1 -o ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_980+currStrOff, fileName, strLen_1);
            currStrOff += strLen_1;
        
        }char * gccArgs = ____BAH_COMPILER_VAR_980;
if ((flags.isSet(&flags,"l")==1)) {
char * ____BAH_COMPILER_VAR_981 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(gccArgs);
long int strLen_1 = strlen(" -c");
;                            
            ____BAH_COMPILER_VAR_981 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_981+currStrOff, gccArgs, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_981+currStrOff, " -c", strLen_1);
            currStrOff += strLen_1;
        
        }gccArgs = ____BAH_COMPILER_VAR_981;
}
array(char *)* cLibs = compilerState.cLibs;
register long int i = 0;
while ((i<len(cLibs))) {
char * l = cLibs->data[i];
char * ____BAH_COMPILER_VAR_982 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(" -");
long int strLen_1 = strlen(l);
long int strLen_2 = strlen(gccArgs);
;                            
            ____BAH_COMPILER_VAR_982 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_982+currStrOff, gccArgs, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_982+currStrOff, " -", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_982+currStrOff, l, strLen_1);
            currStrOff += strLen_1;
        
        }gccArgs = ____BAH_COMPILER_VAR_982;
i = i+1;
};
struct command cmd = command(gccArgs);
cmd.input = OUTPUT->toStr(OUTPUT);
if ((flags.isSet(&flags,"verboseCC")==1)) {
char * ____BAH_COMPILER_VAR_983 =cmd.run(&cmd);println(____BAH_COMPILER_VAR_983);
}
else {
char * ____BAH_COMPILER_VAR_984 =cmd.run(&cmd);}
if ((cmd.status!=0)) {
println("\e[1;31m[CC-ERROR]\e[0m\nCould not compiled.");
return 1;
}
if ((flags.isSet(&flags,"l")==1)) {
char * ____BAH_COMPILER_VAR_985 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(".a ");
long int strLen_1 = strlen(fileName);
long int strLen_2 = strlen(fileName);
long int strLen_3 = strlen("ar rcs ");
;                            
            ____BAH_COMPILER_VAR_985 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_985+currStrOff, "ar rcs ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_985+currStrOff, fileName, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_985+currStrOff, ".a ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_985+currStrOff, fileName, strLen_1);
            currStrOff += strLen_1;
        
        }cmd = command(____BAH_COMPILER_VAR_985);
char * ____BAH_COMPILER_VAR_986 =cmd.run(&cmd);}
}
else {
if ((flags.isSet(&flags,"o")==0)) {
char * ____BAH_COMPILER_VAR_987 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fileName);
long int strLen_1 = strlen(".c");
;                            
            ____BAH_COMPILER_VAR_987 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_987+currStrOff, fileName, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_987+currStrOff, ".c", strLen_1);
            currStrOff += strLen_1;
        
        }fileName = ____BAH_COMPILER_VAR_987;
}
char * ____BAH_COMPILER_VAR_988 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(isStatic);
long int strLen_1 = strlen(" -O1 -w ");
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(fileName);
long int strLen_4 = strlen("/\" ");
long int strLen_5 = strlen(BAH_OS);
long int strLen_6 = strlen("libs/");
long int strLen_7 = strlen(BAH_DIR);
long int strLen_8 = strlen("/include/\" -L \"");
long int strLen_9 = strlen(BAH_OS);
long int strLen_10 = strlen("libs/");
long int strLen_11 = strlen(BAH_DIR);
long int strLen_12 = strlen(" -I \"");
long int strLen_13 = strlen(BAH_CC);
;                            
            ____BAH_COMPILER_VAR_988 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13);
            
                    memcpy(____BAH_COMPILER_VAR_988+currStrOff, BAH_CC, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_988+currStrOff, " -I \"", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_988+currStrOff, BAH_DIR, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_988+currStrOff, "libs/", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_988+currStrOff, BAH_OS, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_988+currStrOff, "/include/\" -L \"", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_988+currStrOff, BAH_DIR, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_988+currStrOff, "libs/", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_988+currStrOff, BAH_OS, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_988+currStrOff, "/\" ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_988+currStrOff, fileName, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_988+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_988+currStrOff, isStatic, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_988+currStrOff, " -O1 -w ", strLen_1);
            currStrOff += strLen_1;
        
        }char * gccArgs = ____BAH_COMPILER_VAR_988;
array(char *)* cLibs = compilerState.cLibs;
register long int i = 0;
while ((i<len(cLibs))) {
char * l = cLibs->data[i];
char * ____BAH_COMPILER_VAR_989 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(" -");
long int strLen_1 = strlen(l);
long int strLen_2 = strlen(gccArgs);
;                            
            ____BAH_COMPILER_VAR_989 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_989+currStrOff, gccArgs, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_989+currStrOff, " -", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_989+currStrOff, l, strLen_1);
            currStrOff += strLen_1;
        
        }gccArgs = ____BAH_COMPILER_VAR_989;
i = i+1;
};
char * ____BAH_COMPILER_VAR_990 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(gccArgs);
long int strLen_1 = strlen("'\n");
long int strLen_2 = strlen("//COMPILE WITH: '");
;                            
            ____BAH_COMPILER_VAR_990 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_990+currStrOff, "//COMPILE WITH: '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_990+currStrOff, gccArgs, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_990+currStrOff, "'\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope(____BAH_COMPILER_VAR_990)->add(rope(____BAH_COMPILER_VAR_990), OUTPUT);
struct fileStream ____BAH_COMPILER_VAR_991 = {};
____BAH_COMPILER_VAR_991.handle= null;
____BAH_COMPILER_VAR_991.name= null;
____BAH_COMPILER_VAR_991.isValid = fileStream__isValid;
____BAH_COMPILER_VAR_991.open = fileStream__open;
____BAH_COMPILER_VAR_991.close = fileStream__close;
____BAH_COMPILER_VAR_991.getPos = fileStream__getPos;
____BAH_COMPILER_VAR_991.setPos = fileStream__setPos;
____BAH_COMPILER_VAR_991.getSize = fileStream__getSize;
____BAH_COMPILER_VAR_991.rewind = fileStream__rewind;
____BAH_COMPILER_VAR_991.getChar = fileStream__getChar;
____BAH_COMPILER_VAR_991.setChar = fileStream__setChar;
____BAH_COMPILER_VAR_991.createFile = fileStream__createFile;
____BAH_COMPILER_VAR_991.writeFile = fileStream__writeFile;
____BAH_COMPILER_VAR_991.writePtr = fileStream__writePtr;
____BAH_COMPILER_VAR_991.readPtr = fileStream__readPtr;
____BAH_COMPILER_VAR_991.readContent = fileStream__readContent;
____BAH_COMPILER_VAR_991.readBytes = fileStream__readBytes;
____BAH_COMPILER_VAR_991.writeBytes = fileStream__writeBytes;
____BAH_COMPILER_VAR_991._end = fileStream___end;
#define fs ____BAH_COMPILER_VAR_991
fs.open(&fs,fileName,"w");
char * ____BAH_COMPILER_VAR_992 =OUTPUT->toStr(OUTPUT);fs.writeFile(&fs,____BAH_COMPILER_VAR_992);
fs.close(&fs);

#undef fs
}
if ((isObject==false)) {
long int totalTime = getTimeUnix()-startTime;
char * ____BAH_COMPILER_VAR_993 =null;char * ____BAH_COMPILER_VAR_994 =intToStr(totalTime/1000000);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_994);
long int strLen_1 = strlen("ms)\e[0m");
long int strLen_2 = strlen("\e[1;32mDone. (compiled in ");
;                            
            ____BAH_COMPILER_VAR_993 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_993+currStrOff, "\e[1;32mDone. (compiled in ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_993+currStrOff, ____BAH_COMPILER_VAR_994, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_993+currStrOff, "ms)\e[0m", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_995 =____BAH_COMPILER_VAR_993;println(____BAH_COMPILER_VAR_995);
}
return 0;
};
volatile struct __Bah_fnName_mapper __tmp____Bah_fnNames[297];
    
    void __attribute__((optimize("O0"))) __BAH_init() {
        __BAH_panic_chan = null;
__Bah_fnNames = memoryAlloc(sizeof(array(struct __Bah_fnName_mapper)));

__Bah_fnNames->length = 0;
__Bah_fnNames->elemSize = sizeof(struct __Bah_fnName_mapper);
onMemoryError = null;
__Bah_init_segfaultHandle_OK = __Bah_init_segfaultHandle();
RAND_SEEDED = 0;
BAH_DIR = "C:/Bah/";
BAH_OS = "windows";
BAH_CC = "gcc";
debug = false;
verboseRuntime = false;
isObject = false;
isUnsafe = false;
execName = "bah";
isSubObject = false;
NEXT_LINE = "";
shouldOnlyDecl = false;
threadCount = 0;
currentFn = null;
totalLines = 0;
totalLexerTime = 0;
RCPenabled = false;
RCPlevel = 0;
currSetVar = null;
enclavers = memoryAlloc(sizeof(array(char)));

enclavers->length = 6;
enclavers->elemSize = sizeof(char);
enclavers->data = memoryAlloc(sizeof(char) * 50);enclavers->data[0] = 40;
enclavers->data[1] = 41;
enclavers->data[2] = 123;
enclavers->data[3] = 125;
enclavers->data[4] = 91;
enclavers->data[5] = 93;
syntaxes = memoryAlloc(sizeof(array(char)));

syntaxes->length = 14;
syntaxes->elemSize = sizeof(char);
syntaxes->data = memoryAlloc(sizeof(char) * 50);syntaxes->data[0] = 33;
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
keywords = memoryAlloc(sizeof(array(char *)));

keywords->length = 21;
keywords->elemSize = sizeof(char *);
keywords->data = memoryAlloc(sizeof(char *) * 50);keywords->data[0] = "if";
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
intTypes = memoryAlloc(sizeof(array(char *)));

intTypes->length = 5;
intTypes->elemSize = sizeof(char *);
intTypes->data = memoryAlloc(sizeof(char *) * 50);intTypes->data[0] = "int";
intTypes->data[1] = "int32";
intTypes->data[2] = "uint";
intTypes->data[3] = "uint32";
intTypes->data[4] = "bool";
floatTypes = memoryAlloc(sizeof(array(char *)));

floatTypes->length = 4;
floatTypes->elemSize = sizeof(char *);
floatTypes->data = memoryAlloc(sizeof(char *) * 50);floatTypes->data[0] = "float";
floatTypes->data[1] = "float32";
floatTypes->data[2] = "ufloat";
floatTypes->data[3] = "ufloat32";
NB_COMP_VAR = 0;
noVOfns = memoryAlloc(sizeof(array(char *)));

noVOfns->length = 1;
noVOfns->elemSize = sizeof(char *);
noVOfns->data = memoryAlloc(sizeof(char *) * 50);noVOfns->data[0] = "__Bah_safe_string";
cache = memoryAlloc(sizeof(array(struct cacheFile*)));

cache->length = 0;
cache->elemSize = sizeof(struct cacheFile*);
prevLine = (lineType)-1;
signs = memoryAlloc(sizeof(array(char *)));

signs->length = 9;
signs->elemSize = sizeof(char *);
signs->data = memoryAlloc(sizeof(char *) * 50);signs->data[0] = "|";
signs->data[1] = "&";
signs->data[2] = "%";
signs->data[3] = "+";
signs->data[4] = "-";
signs->data[5] = "*";
signs->data[6] = "/";
signs->data[7] = "<<";
signs->data[8] = ">>";
comparators = memoryAlloc(sizeof(array(char *)));

comparators->length = 7;
comparators->elemSize = sizeof(char *);
comparators->data = memoryAlloc(sizeof(char *) * 50);comparators->data[0] = "==";
comparators->data[1] = "!=";
comparators->data[2] = ">";
comparators->data[3] = "<";
comparators->data[4] = "<=";
comparators->data[5] = ">=";
comparators->data[6] = "in";
compSep = memoryAlloc(sizeof(array(char *)));

compSep->length = 2;
compSep->elemSize = sizeof(char *);
compSep->data = memoryAlloc(sizeof(char *) * 50);compSep->data[0] = "||";
compSep->data[1] = "&&";
equalsTokens = memoryAlloc(sizeof(array(char *)));

equalsTokens->length = 5;
equalsTokens->elemSize = sizeof(char *);
equalsTokens->data = memoryAlloc(sizeof(char *) * 50);equalsTokens->data[0] = "=";
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

            __tmp____Bah_fnNames[4].n = "len";
            __tmp____Bah_fnNames[4].p = len;

            __tmp____Bah_fnNames[5].n = "memoryAlloc";
            __tmp____Bah_fnNames[5].p = memoryAlloc;

            __tmp____Bah_fnNames[6].n = "destroy";
            __tmp____Bah_fnNames[6].p = destroy;

            __tmp____Bah_fnNames[7].n = "clear";
            __tmp____Bah_fnNames[7].p = clear;

            __tmp____Bah_fnNames[8].n = "memoryRealloc";
            __tmp____Bah_fnNames[8].p = memoryRealloc;

            __tmp____Bah_fnNames[9].n = "cleanShutDown";
            __tmp____Bah_fnNames[9].p = cleanShutDown;

            __tmp____Bah_fnNames[10].n = "memoryOnEnd";
            __tmp____Bah_fnNames[10].p = memoryOnEnd;

            __tmp____Bah_fnNames[11].n = "append";
            __tmp____Bah_fnNames[11].p = append;

            __tmp____Bah_fnNames[12].n = "copy";
            __tmp____Bah_fnNames[12].p = copy;

            __tmp____Bah_fnNames[13].n = "sharedMemory";
            __tmp____Bah_fnNames[13].p = sharedMemory;

            __tmp____Bah_fnNames[14].n = "closeSharedMemory";
            __tmp____Bah_fnNames[14].p = closeSharedMemory;

            __tmp____Bah_fnNames[15].n = "allocateArray";
            __tmp____Bah_fnNames[15].p = allocateArray;

            __tmp____Bah_fnNames[16].n = "__serialize";
            __tmp____Bah_fnNames[16].p = __serialize;

            __tmp____Bah_fnNames[17].n = "serlen";
            __tmp____Bah_fnNames[17].p = serlen;

            __tmp____Bah_fnNames[18].n = "unser";
            __tmp____Bah_fnNames[18].p = unser;

            __tmp____Bah_fnNames[19].n = "memoryAllocSTR";
            __tmp____Bah_fnNames[19].p = memoryAllocSTR;

            __tmp____Bah_fnNames[20].n = "delete";
            __tmp____Bah_fnNames[20].p = delete;

            __tmp____Bah_fnNames[21].n = "deleteRange";
            __tmp____Bah_fnNames[21].p = deleteRange;

            __tmp____Bah_fnNames[22].n = "arrToStr";
            __tmp____Bah_fnNames[22].p = arrToStr;

            __tmp____Bah_fnNames[23].n = "strToArr";
            __tmp____Bah_fnNames[23].p = strToArr;

            __tmp____Bah_fnNames[24].n = "arrAsStr";
            __tmp____Bah_fnNames[24].p = arrAsStr;

            __tmp____Bah_fnNames[25].n = "strAsArr";
            __tmp____Bah_fnNames[25].p = strAsArr;

            __tmp____Bah_fnNames[26].n = "strTrimLeft";
            __tmp____Bah_fnNames[26].p = strTrimLeft;

            __tmp____Bah_fnNames[27].n = "strTrimRight";
            __tmp____Bah_fnNames[27].p = strTrimRight;

            __tmp____Bah_fnNames[28].n = "concatCPSTRING";
            __tmp____Bah_fnNames[28].p = concatCPSTRING;

            __tmp____Bah_fnNames[29].n = "__STR";
            __tmp____Bah_fnNames[29].p = __STR;

            __tmp____Bah_fnNames[30].n = "print";
            __tmp____Bah_fnNames[30].p = print;

            __tmp____Bah_fnNames[31].n = "cArr";
            __tmp____Bah_fnNames[31].p = cArr;

            __tmp____Bah_fnNames[32].n = "__checkString";
            __tmp____Bah_fnNames[32].p = __checkString;

            __tmp____Bah_fnNames[33].n = "mutex.init";
            __tmp____Bah_fnNames[33].p = mutex__init;

            __tmp____Bah_fnNames[34].n = "mutex.lock";
            __tmp____Bah_fnNames[34].p = mutex__lock;

            __tmp____Bah_fnNames[35].n = "mutex.unlock";
            __tmp____Bah_fnNames[35].p = mutex__unlock;

            __tmp____Bah_fnNames[36].n = "mutex.destroy";
            __tmp____Bah_fnNames[36].p = mutex__destroy;

            __tmp____Bah_fnNames[37].n = "mutexCondition.init";
            __tmp____Bah_fnNames[37].p = mutexCondition__init;

            __tmp____Bah_fnNames[38].n = "mutexCondition.wait";
            __tmp____Bah_fnNames[38].p = mutexCondition__wait;

            __tmp____Bah_fnNames[39].n = "mutexCondition.send";
            __tmp____Bah_fnNames[39].p = mutexCondition__send;

            __tmp____Bah_fnNames[40].n = "mutexCondition.destroy";
            __tmp____Bah_fnNames[40].p = mutexCondition__destroy;

            __tmp____Bah_fnNames[41].n = "mutexCondition";
            __tmp____Bah_fnNames[41].p = mutexCondition;

            __tmp____Bah_fnNames[42].n = "thread.create";
            __tmp____Bah_fnNames[42].p = thread__create;

            __tmp____Bah_fnNames[43].n = "thread.createWithArg";
            __tmp____Bah_fnNames[43].p = thread__createWithArg;

            __tmp____Bah_fnNames[44].n = "thread.wait";
            __tmp____Bah_fnNames[44].p = thread__wait;

            __tmp____Bah_fnNames[45].n = "mutex";
            __tmp____Bah_fnNames[45].p = mutex;

            __tmp____Bah_fnNames[46].n = "queue.insert";
            __tmp____Bah_fnNames[46].p = queue__insert;

            __tmp____Bah_fnNames[47].n = "queue.delete";
            __tmp____Bah_fnNames[47].p = queue__delete;

            __tmp____Bah_fnNames[48].n = "queue.get";
            __tmp____Bah_fnNames[48].p = queue__get;

            __tmp____Bah_fnNames[49].n = "queue.set";
            __tmp____Bah_fnNames[49].p = queue__set;

            __tmp____Bah_fnNames[50].n = "queue.pop";
            __tmp____Bah_fnNames[50].p = queue__pop;

            __tmp____Bah_fnNames[51].n = "queue.clear";
            __tmp____Bah_fnNames[51].p = queue__clear;

            __tmp____Bah_fnNames[52].n = "channel.send";
            __tmp____Bah_fnNames[52].p = channel__send;

            __tmp____Bah_fnNames[53].n = "channel.sendAny";
            __tmp____Bah_fnNames[53].p = channel__sendAny;

            __tmp____Bah_fnNames[54].n = "channel.receive";
            __tmp____Bah_fnNames[54].p = channel__receive;

            __tmp____Bah_fnNames[55].n = "channel.destroy";
            __tmp____Bah_fnNames[55].p = channel__destroy;

            __tmp____Bah_fnNames[56].n = "channel.len";
            __tmp____Bah_fnNames[56].p = channel__len;

            __tmp____Bah_fnNames[57].n = "channel";
            __tmp____Bah_fnNames[57].p = channel;

            __tmp____Bah_fnNames[58].n = "setChanCap";
            __tmp____Bah_fnNames[58].p = setChanCap;

            __tmp____Bah_fnNames[59].n = "__Bah_common_panic";
            __tmp____Bah_fnNames[59].p = __Bah_common_panic;

            __tmp____Bah_fnNames[60].n = "__Bah_fnNames_append";
            __tmp____Bah_fnNames[60].p = __Bah_fnNames_append;

            __tmp____Bah_fnNames[61].n = "__Bah_segfault_handle";
            __tmp____Bah_fnNames[61].p = __Bah_segfault_handle;

            __tmp____Bah_fnNames[62].n = "__Bah_init_segfaultHandle";
            __tmp____Bah_fnNames[62].p = __Bah_init_segfaultHandle;

            __tmp____Bah_fnNames[63].n = "recover";
            __tmp____Bah_fnNames[63].p = recover;

            __tmp____Bah_fnNames[64].n = "cpstringCharAt";
            __tmp____Bah_fnNames[64].p = cpstringCharAt;

            __tmp____Bah_fnNames[65].n = "cpstringSubsitute";
            __tmp____Bah_fnNames[65].p = cpstringSubsitute;

            __tmp____Bah_fnNames[66].n = "arraySubstitute";
            __tmp____Bah_fnNames[66].p = arraySubstitute;

            __tmp____Bah_fnNames[67].n = "__Bah_map_hash";
            __tmp____Bah_fnNames[67].p = __Bah_map_hash;

            __tmp____Bah_fnNames[68].n = "mapWrapper.grow";
            __tmp____Bah_fnNames[68].p = mapWrapper__grow;

            __tmp____Bah_fnNames[69].n = "mapWrapper.set";
            __tmp____Bah_fnNames[69].p = mapWrapper__set;

            __tmp____Bah_fnNames[70].n = "mapWrapper.setAny";
            __tmp____Bah_fnNames[70].p = mapWrapper__setAny;

            __tmp____Bah_fnNames[71].n = "mapWrapper.delete";
            __tmp____Bah_fnNames[71].p = mapWrapper__delete;

            __tmp____Bah_fnNames[72].n = "mapWrapper.get";
            __tmp____Bah_fnNames[72].p = mapWrapper__get;

            __tmp____Bah_fnNames[73].n = "mapWrapper";
            __tmp____Bah_fnNames[73].p = mapWrapper;

            __tmp____Bah_fnNames[74].n = "stdinput";
            __tmp____Bah_fnNames[74].p = stdinput;

            __tmp____Bah_fnNames[75].n = "println";
            __tmp____Bah_fnNames[75].p = println;

            __tmp____Bah_fnNames[76].n = "fileStream.isValid";
            __tmp____Bah_fnNames[76].p = fileStream__isValid;

            __tmp____Bah_fnNames[77].n = "fileStream.open";
            __tmp____Bah_fnNames[77].p = fileStream__open;

            __tmp____Bah_fnNames[78].n = "fileStream.close";
            __tmp____Bah_fnNames[78].p = fileStream__close;

            __tmp____Bah_fnNames[79].n = "fileStream.getPos";
            __tmp____Bah_fnNames[79].p = fileStream__getPos;

            __tmp____Bah_fnNames[80].n = "fileStream.setPos";
            __tmp____Bah_fnNames[80].p = fileStream__setPos;

            __tmp____Bah_fnNames[81].n = "fileStream.getSize";
            __tmp____Bah_fnNames[81].p = fileStream__getSize;

            __tmp____Bah_fnNames[82].n = "fileStream.rewind";
            __tmp____Bah_fnNames[82].p = fileStream__rewind;

            __tmp____Bah_fnNames[83].n = "fileStream.getChar";
            __tmp____Bah_fnNames[83].p = fileStream__getChar;

            __tmp____Bah_fnNames[84].n = "fileStream.setChar";
            __tmp____Bah_fnNames[84].p = fileStream__setChar;

            __tmp____Bah_fnNames[85].n = "fileStream.createFile";
            __tmp____Bah_fnNames[85].p = fileStream__createFile;

            __tmp____Bah_fnNames[86].n = "fileStream.writeFile";
            __tmp____Bah_fnNames[86].p = fileStream__writeFile;

            __tmp____Bah_fnNames[87].n = "fileStream.writePtr";
            __tmp____Bah_fnNames[87].p = fileStream__writePtr;

            __tmp____Bah_fnNames[88].n = "fileStream.readPtr";
            __tmp____Bah_fnNames[88].p = fileStream__readPtr;

            __tmp____Bah_fnNames[89].n = "fileStream.readContent";
            __tmp____Bah_fnNames[89].p = fileStream__readContent;

            __tmp____Bah_fnNames[90].n = "fileStream.readBytes";
            __tmp____Bah_fnNames[90].p = fileStream__readBytes;

            __tmp____Bah_fnNames[91].n = "fileStream.writeBytes";
            __tmp____Bah_fnNames[91].p = fileStream__writeBytes;

            __tmp____Bah_fnNames[92].n = "fileStream._end";
            __tmp____Bah_fnNames[92].p = fileStream___end;

            __tmp____Bah_fnNames[93].n = "fileMap.open";
            __tmp____Bah_fnNames[93].p = fileMap__open;

            __tmp____Bah_fnNames[94].n = "fileMap.isValid";
            __tmp____Bah_fnNames[94].p = fileMap__isValid;

            __tmp____Bah_fnNames[95].n = "fileMap.close";
            __tmp____Bah_fnNames[95].p = fileMap__close;

            __tmp____Bah_fnNames[96].n = "listFiles";
            __tmp____Bah_fnNames[96].p = listFiles;

            __tmp____Bah_fnNames[97].n = "fileExists";
            __tmp____Bah_fnNames[97].p = fileExists;

            __tmp____Bah_fnNames[98].n = "removeFile";
            __tmp____Bah_fnNames[98].p = removeFile;

            __tmp____Bah_fnNames[99].n = "getLastModified";
            __tmp____Bah_fnNames[99].p = getLastModified;

            __tmp____Bah_fnNames[100].n = "__windows_mkdir";
            __tmp____Bah_fnNames[100].p = __windows_mkdir;

            __tmp____Bah_fnNames[101].n = "strCatOffset";
            __tmp____Bah_fnNames[101].p = strCatOffset;

            __tmp____Bah_fnNames[102].n = "charToString";
            __tmp____Bah_fnNames[102].p = charToString;

            __tmp____Bah_fnNames[103].n = "isUpper";
            __tmp____Bah_fnNames[103].p = isUpper;

            __tmp____Bah_fnNames[104].n = "isLower";
            __tmp____Bah_fnNames[104].p = isLower;

            __tmp____Bah_fnNames[105].n = "isLetter";
            __tmp____Bah_fnNames[105].p = isLetter;

            __tmp____Bah_fnNames[106].n = "isNumber";
            __tmp____Bah_fnNames[106].p = isNumber;

            __tmp____Bah_fnNames[107].n = "isAlphaNumeric";
            __tmp____Bah_fnNames[107].p = isAlphaNumeric;

            __tmp____Bah_fnNames[108].n = "isSpace";
            __tmp____Bah_fnNames[108].p = isSpace;

            __tmp____Bah_fnNames[109].n = "string.set";
            __tmp____Bah_fnNames[109].p = string__set;

            __tmp____Bah_fnNames[110].n = "string.makeEditable";
            __tmp____Bah_fnNames[110].p = string__makeEditable;

            __tmp____Bah_fnNames[111].n = "string.append";
            __tmp____Bah_fnNames[111].p = string__append;

            __tmp____Bah_fnNames[112].n = "string.prepend";
            __tmp____Bah_fnNames[112].p = string__prepend;

            __tmp____Bah_fnNames[113].n = "string.charAt";
            __tmp____Bah_fnNames[113].p = string__charAt;

            __tmp____Bah_fnNames[114].n = "string.compare";
            __tmp____Bah_fnNames[114].p = string__compare;

            __tmp____Bah_fnNames[115].n = "string.str";
            __tmp____Bah_fnNames[115].p = string__str;

            __tmp____Bah_fnNames[116].n = "string.replace";
            __tmp____Bah_fnNames[116].p = string__replace;

            __tmp____Bah_fnNames[117].n = "string.countChar";
            __tmp____Bah_fnNames[117].p = string__countChar;

            __tmp____Bah_fnNames[118].n = "string.count";
            __tmp____Bah_fnNames[118].p = string__count;

            __tmp____Bah_fnNames[119].n = "string.hasPrefix";
            __tmp____Bah_fnNames[119].p = string__hasPrefix;

            __tmp____Bah_fnNames[120].n = "string.hasSuffix";
            __tmp____Bah_fnNames[120].p = string__hasSuffix;

            __tmp____Bah_fnNames[121].n = "string.trim";
            __tmp____Bah_fnNames[121].p = string__trim;

            __tmp____Bah_fnNames[122].n = "string.trimLeft";
            __tmp____Bah_fnNames[122].p = string__trimLeft;

            __tmp____Bah_fnNames[123].n = "string.trimRight";
            __tmp____Bah_fnNames[123].p = string__trimRight;

            __tmp____Bah_fnNames[124].n = "string.add";
            __tmp____Bah_fnNames[124].p = string__add;

            __tmp____Bah_fnNames[125].n = "string";
            __tmp____Bah_fnNames[125].p = string;

            __tmp____Bah_fnNames[126].n = "intToStr";
            __tmp____Bah_fnNames[126].p = intToStr;

            __tmp____Bah_fnNames[127].n = "intToString";
            __tmp____Bah_fnNames[127].p = intToString;

            __tmp____Bah_fnNames[128].n = "floatToStr";
            __tmp____Bah_fnNames[128].p = floatToStr;

            __tmp____Bah_fnNames[129].n = "strToInt";
            __tmp____Bah_fnNames[129].p = strToInt;

            __tmp____Bah_fnNames[130].n = "strToFloat";
            __tmp____Bah_fnNames[130].p = strToFloat;

            __tmp____Bah_fnNames[131].n = "stringToInt";
            __tmp____Bah_fnNames[131].p = stringToInt;

            __tmp____Bah_fnNames[132].n = "splitString";
            __tmp____Bah_fnNames[132].p = splitString;

            __tmp____Bah_fnNames[133].n = "joinString";
            __tmp____Bah_fnNames[133].p = joinString;

            __tmp____Bah_fnNames[134].n = "splitStringBefore";
            __tmp____Bah_fnNames[134].p = splitStringBefore;

            __tmp____Bah_fnNames[135].n = "toLower";
            __tmp____Bah_fnNames[135].p = toLower;

            __tmp____Bah_fnNames[136].n = "strHasPrefix";
            __tmp____Bah_fnNames[136].p = strHasPrefix;

            __tmp____Bah_fnNames[137].n = "strHasSuffix";
            __tmp____Bah_fnNames[137].p = strHasSuffix;

            __tmp____Bah_fnNames[138].n = "strTrim";
            __tmp____Bah_fnNames[138].p = strTrim;

            __tmp____Bah_fnNames[139].n = "strCount";
            __tmp____Bah_fnNames[139].p = strCount;

            __tmp____Bah_fnNames[140].n = "flags.addString";
            __tmp____Bah_fnNames[140].p = flags__addString;

            __tmp____Bah_fnNames[141].n = "flags.addBool";
            __tmp____Bah_fnNames[141].p = flags__addBool;

            __tmp____Bah_fnNames[142].n = "flags.addInt";
            __tmp____Bah_fnNames[142].p = flags__addInt;

            __tmp____Bah_fnNames[143].n = "flags.addFloat";
            __tmp____Bah_fnNames[143].p = flags__addFloat;

            __tmp____Bah_fnNames[144].n = "flags.invalidate";
            __tmp____Bah_fnNames[144].p = flags__invalidate;

            __tmp____Bah_fnNames[145].n = "flags.getFlag";
            __tmp____Bah_fnNames[145].p = flags__getFlag;

            __tmp____Bah_fnNames[146].n = "flags.get";
            __tmp____Bah_fnNames[146].p = flags__get;

            __tmp____Bah_fnNames[147].n = "flags.getInt";
            __tmp____Bah_fnNames[147].p = flags__getInt;

            __tmp____Bah_fnNames[148].n = "flags.getFloat";
            __tmp____Bah_fnNames[148].p = flags__getFloat;

            __tmp____Bah_fnNames[149].n = "flags.isSet";
            __tmp____Bah_fnNames[149].p = flags__isSet;

            __tmp____Bah_fnNames[150].n = "flags.parse";
            __tmp____Bah_fnNames[150].p = flags__parse;

            __tmp____Bah_fnNames[151].n = "time.now";
            __tmp____Bah_fnNames[151].p = time__now;

            __tmp____Bah_fnNames[152].n = "time.format";
            __tmp____Bah_fnNames[152].p = time__format;

            __tmp____Bah_fnNames[153].n = "time.since";
            __tmp____Bah_fnNames[153].p = time__since;

            __tmp____Bah_fnNames[154].n = "getTimeUnix";
            __tmp____Bah_fnNames[154].p = getTimeUnix;

            __tmp____Bah_fnNames[155].n = "seedRandom";
            __tmp____Bah_fnNames[155].p = seedRandom;

            __tmp____Bah_fnNames[156].n = "randomInRange";
            __tmp____Bah_fnNames[156].p = randomInRange;

            __tmp____Bah_fnNames[157].n = "cryptoRand";
            __tmp____Bah_fnNames[157].p = cryptoRand;

            __tmp____Bah_fnNames[158].n = "rope.addStr";
            __tmp____Bah_fnNames[158].p = rope__addStr;

            __tmp____Bah_fnNames[159].n = "rope.toStr";
            __tmp____Bah_fnNames[159].p = rope__toStr;

            __tmp____Bah_fnNames[160].n = "rope.add";
            __tmp____Bah_fnNames[160].p = rope__add;

            __tmp____Bah_fnNames[161].n = "createRopeStructure";
            __tmp____Bah_fnNames[161].p = createRopeStructure;

            __tmp____Bah_fnNames[162].n = "ropeSet";
            __tmp____Bah_fnNames[162].p = ropeSet;

            __tmp____Bah_fnNames[163].n = "concatenateRopes";
            __tmp____Bah_fnNames[163].p = concatenateRopes;

            __tmp____Bah_fnNames[164].n = "rope";
            __tmp____Bah_fnNames[164].p = rope;

            __tmp____Bah_fnNames[165].n = "command.run";
            __tmp____Bah_fnNames[165].p = command__run;

            __tmp____Bah_fnNames[166].n = "command.runBytes";
            __tmp____Bah_fnNames[166].p = command__runBytes;

            __tmp____Bah_fnNames[167].n = "command";
            __tmp____Bah_fnNames[167].p = command;

            __tmp____Bah_fnNames[168].n = "exec";
            __tmp____Bah_fnNames[168].p = exec;

            __tmp____Bah_fnNames[169].n = "inArray";
            __tmp____Bah_fnNames[169].p = inArray;

            __tmp____Bah_fnNames[170].n = "inArrayStr";
            __tmp____Bah_fnNames[170].p = inArrayStr;

            __tmp____Bah_fnNames[171].n = "makeToken";
            __tmp____Bah_fnNames[171].p = makeToken;

            __tmp____Bah_fnNames[172].n = "isMinus";
            __tmp____Bah_fnNames[172].p = isMinus;

            __tmp____Bah_fnNames[173].n = "lexerErr";
            __tmp____Bah_fnNames[173].p = lexerErr;

            __tmp____Bah_fnNames[174].n = "lexer";
            __tmp____Bah_fnNames[174].p = lexer;

            __tmp____Bah_fnNames[175].n = "hasStructSep";
            __tmp____Bah_fnNames[175].p = hasStructSep;

            __tmp____Bah_fnNames[176].n = "splitStructSepBefore";
            __tmp____Bah_fnNames[176].p = splitStructSepBefore;

            __tmp____Bah_fnNames[177].n = "splitStructSepAfter";
            __tmp____Bah_fnNames[177].p = splitStructSepAfter;

            __tmp____Bah_fnNames[178].n = "searchStruct";
            __tmp____Bah_fnNames[178].p = searchStruct;

            __tmp____Bah_fnNames[179].n = "searchStructMemb";
            __tmp____Bah_fnNames[179].p = searchStructMemb;

            __tmp____Bah_fnNames[180].n = "searchFunc";
            __tmp____Bah_fnNames[180].p = searchFunc;

            __tmp____Bah_fnNames[181].n = "parseFnType";
            __tmp____Bah_fnNames[181].p = parseFnType;

            __tmp____Bah_fnNames[182].n = "searchStructMethod";
            __tmp____Bah_fnNames[182].p = searchStructMethod;

            __tmp____Bah_fnNames[183].n = "typeAsStar";
            __tmp____Bah_fnNames[183].p = typeAsStar;

            __tmp____Bah_fnNames[184].n = "isRCPpointerType";
            __tmp____Bah_fnNames[184].p = isRCPpointerType;

            __tmp____Bah_fnNames[185].n = "isRCPtype";
            __tmp____Bah_fnNames[185].p = isRCPtype;

            __tmp____Bah_fnNames[186].n = "getCType";
            __tmp____Bah_fnNames[186].p = getCType;

            __tmp____Bah_fnNames[187].n = "compTypeEquiv";
            __tmp____Bah_fnNames[187].p = compTypeEquiv;

            __tmp____Bah_fnNames[188].n = "compTypes";
            __tmp____Bah_fnNames[188].p = compTypes;

            __tmp____Bah_fnNames[189].n = "reflectElement.calculateOffset";
            __tmp____Bah_fnNames[189].p = reflectElement__calculateOffset;

            __tmp____Bah_fnNames[190].n = "__reflect";
            __tmp____Bah_fnNames[190].p = __reflect;

            __tmp____Bah_fnNames[191].n = "__dumpSymbols";
            __tmp____Bah_fnNames[191].p = __dumpSymbols;

            __tmp____Bah_fnNames[192].n = "__debug_get_sym";
            __tmp____Bah_fnNames[192].p = __debug_get_sym;

            __tmp____Bah_fnNames[193].n = "toJson";
            __tmp____Bah_fnNames[193].p = toJson;

            __tmp____Bah_fnNames[194].n = "json_scan_inner";
            __tmp____Bah_fnNames[194].p = json_scan_inner;

            __tmp____Bah_fnNames[195].n = "jsonElement.get";
            __tmp____Bah_fnNames[195].p = jsonElement__get;

            __tmp____Bah_fnNames[196].n = "jsonElement.str";
            __tmp____Bah_fnNames[196].p = jsonElement__str;

            __tmp____Bah_fnNames[197].n = "jsonElement.scan";
            __tmp____Bah_fnNames[197].p = jsonElement__scan;

            __tmp____Bah_fnNames[198].n = "parseJson";
            __tmp____Bah_fnNames[198].p = parseJson;

            __tmp____Bah_fnNames[199].n = "jsonEscapeStr";
            __tmp____Bah_fnNames[199].p = jsonEscapeStr;

            __tmp____Bah_fnNames[200].n = "toJson__inner";
            __tmp____Bah_fnNames[200].p = toJson__inner;

            __tmp____Bah_fnNames[201].n = "debugStart";
            __tmp____Bah_fnNames[201].p = debugStart;

            __tmp____Bah_fnNames[202].n = "debugPrint";
            __tmp____Bah_fnNames[202].p = debugPrint;

            __tmp____Bah_fnNames[203].n = "debugError";
            __tmp____Bah_fnNames[203].p = debugError;

            __tmp____Bah_fnNames[204].n = "debugEnd";
            __tmp____Bah_fnNames[204].p = debugEnd;

            __tmp____Bah_fnNames[205].n = "debugExit";
            __tmp____Bah_fnNames[205].p = debugExit;

            __tmp____Bah_fnNames[206].n = "debugEndScope";
            __tmp____Bah_fnNames[206].p = debugEndScope;

            __tmp____Bah_fnNames[207].n = "throwErr";
            __tmp____Bah_fnNames[207].p = throwErr;

            __tmp____Bah_fnNames[208].n = "throwWarning";
            __tmp____Bah_fnNames[208].p = throwWarning;

            __tmp____Bah_fnNames[209].n = "absPath";
            __tmp____Bah_fnNames[209].p = absPath;

            __tmp____Bah_fnNames[210].n = "getCurrentPath";
            __tmp____Bah_fnNames[210].p = getCurrentPath;

            __tmp____Bah_fnNames[211].n = "isInside";
            __tmp____Bah_fnNames[211].p = isInside;

            __tmp____Bah_fnNames[212].n = "setCurrentPath";
            __tmp____Bah_fnNames[212].p = setCurrentPath;

            __tmp____Bah_fnNames[213].n = "isGlobal";
            __tmp____Bah_fnNames[213].p = isGlobal;

            __tmp____Bah_fnNames[214].n = "getRealVar";
            __tmp____Bah_fnNames[214].p = getRealVar;

            __tmp____Bah_fnNames[215].n = "searchVar";
            __tmp____Bah_fnNames[215].p = searchVar;

            __tmp____Bah_fnNames[216].n = "searchVarByToken";
            __tmp____Bah_fnNames[216].p = searchVarByToken;

            __tmp____Bah_fnNames[217].n = "setCType";
            __tmp____Bah_fnNames[217].p = setCType;

            __tmp____Bah_fnNames[218].n = "getTypeFromToken";
            __tmp____Bah_fnNames[218].p = getTypeFromToken;

            __tmp____Bah_fnNames[219].n = "searchFuncByToken";
            __tmp____Bah_fnNames[219].p = searchFuncByToken;

            __tmp____Bah_fnNames[220].n = "RCPavailable";
            __tmp____Bah_fnNames[220].p = RCPavailable;

            __tmp____Bah_fnNames[221].n = "declareStructMethods";
            __tmp____Bah_fnNames[221].p = declareStructMethods;

            __tmp____Bah_fnNames[222].n = "genCompilerVar";
            __tmp____Bah_fnNames[222].p = genCompilerVar;

            __tmp____Bah_fnNames[223].n = "varInArr";
            __tmp____Bah_fnNames[223].p = varInArr;

            __tmp____Bah_fnNames[224].n = "pathToVarName";
            __tmp____Bah_fnNames[224].p = pathToVarName;

            __tmp____Bah_fnNames[225].n = "makeInit";
            __tmp____Bah_fnNames[225].p = makeInit;

            __tmp____Bah_fnNames[226].n = "isOutterScope";
            __tmp____Bah_fnNames[226].p = isOutterScope;

            __tmp____Bah_fnNames[227].n = "decrVar";
            __tmp____Bah_fnNames[227].p = decrVar;

            __tmp____Bah_fnNames[228].n = "incrVar";
            __tmp____Bah_fnNames[228].p = incrVar;

            __tmp____Bah_fnNames[229].n = "beginRCPscope";
            __tmp____Bah_fnNames[229].p = beginRCPscope;

            __tmp____Bah_fnNames[230].n = "beginRCPscopeLeaky";
            __tmp____Bah_fnNames[230].p = beginRCPscopeLeaky;

            __tmp____Bah_fnNames[231].n = "removeDefs";
            __tmp____Bah_fnNames[231].p = removeDefs;

            __tmp____Bah_fnNames[232].n = "endRCPscope";
            __tmp____Bah_fnNames[232].p = endRCPscope;

            __tmp____Bah_fnNames[233].n = "endRCPscopeLeaky";
            __tmp____Bah_fnNames[233].p = endRCPscopeLeaky;

            __tmp____Bah_fnNames[234].n = "registerRCPvar";
            __tmp____Bah_fnNames[234].p = registerRCPvar;

            __tmp____Bah_fnNames[235].n = "RCPselfRef";
            __tmp____Bah_fnNames[235].p = RCPselfRef;

            __tmp____Bah_fnNames[236].n = "verboseOutGuard";
            __tmp____Bah_fnNames[236].p = verboseOutGuard;

            __tmp____Bah_fnNames[237].n = "verboseOutTransformVar";
            __tmp____Bah_fnNames[237].p = verboseOutTransformVar;

            __tmp____Bah_fnNames[238].n = "verboseOutTransformTok";
            __tmp____Bah_fnNames[238].p = verboseOutTransformTok;

            __tmp____Bah_fnNames[239].n = "verboseOutFunc";
            __tmp____Bah_fnNames[239].p = verboseOutFunc;

            __tmp____Bah_fnNames[240].n = "verboseOutOper";
            __tmp____Bah_fnNames[240].p = verboseOutOper;

            __tmp____Bah_fnNames[241].n = "readCache";
            __tmp____Bah_fnNames[241].p = readCache;

            __tmp____Bah_fnNames[242].n = "getCacheFile";
            __tmp____Bah_fnNames[242].p = getCacheFile;

            __tmp____Bah_fnNames[243].n = "updateCacheFile";
            __tmp____Bah_fnNames[243].p = updateCacheFile;

            __tmp____Bah_fnNames[244].n = "makeCacheFile";
            __tmp____Bah_fnNames[244].p = makeCacheFile;

            __tmp____Bah_fnNames[245].n = "writeCache";
            __tmp____Bah_fnNames[245].p = writeCache;

            __tmp____Bah_fnNames[246].n = "isValidCacheFile";
            __tmp____Bah_fnNames[246].p = isValidCacheFile;

            __tmp____Bah_fnNames[247].n = "debugLine";
            __tmp____Bah_fnNames[247].p = debugLine;

            __tmp____Bah_fnNames[248].n = "dupElems";
            __tmp____Bah_fnNames[248].p = dupElems;

            __tmp____Bah_fnNames[249].n = "getLineType";
            __tmp____Bah_fnNames[249].p = getLineType;

            __tmp____Bah_fnNames[250].n = "parseCast";
            __tmp____Bah_fnNames[250].p = parseCast;

            __tmp____Bah_fnNames[251].n = "getDirFromFile";
            __tmp____Bah_fnNames[251].p = getDirFromFile;

            __tmp____Bah_fnNames[252].n = "parseLines";
            __tmp____Bah_fnNames[252].p = parseLines;

            __tmp____Bah_fnNames[253].n = "includeFile";
            __tmp____Bah_fnNames[253].p = includeFile;

            __tmp____Bah_fnNames[254].n = "parallelObjCompile";
            __tmp____Bah_fnNames[254].p = parallelObjCompile;

            __tmp____Bah_fnNames[255].n = "parseImport";
            __tmp____Bah_fnNames[255].p = parseImport;

            __tmp____Bah_fnNames[256].n = "parseInclude";
            __tmp____Bah_fnNames[256].p = parseInclude;

            __tmp____Bah_fnNames[257].n = "prePross";
            __tmp____Bah_fnNames[257].p = prePross;

            __tmp____Bah_fnNames[258].n = "parseStructType";
            __tmp____Bah_fnNames[258].p = parseStructType;

            __tmp____Bah_fnNames[259].n = "parseArrayType";
            __tmp____Bah_fnNames[259].p = parseArrayType;

            __tmp____Bah_fnNames[260].n = "parsePointers";
            __tmp____Bah_fnNames[260].p = parsePointers;

            __tmp____Bah_fnNames[261].n = "parseSerialize";
            __tmp____Bah_fnNames[261].p = parseSerialize;

            __tmp____Bah_fnNames[262].n = "parseReflect";
            __tmp____Bah_fnNames[262].p = parseReflect;

            __tmp____Bah_fnNames[263].n = "parseArrayDecl";
            __tmp____Bah_fnNames[263].p = parseArrayDecl;

            __tmp____Bah_fnNames[264].n = "parseVar";
            __tmp____Bah_fnNames[264].p = parseVar;

            __tmp____Bah_fnNames[265].n = "getCfunctionType";
            __tmp____Bah_fnNames[265].p = getCfunctionType;

            __tmp____Bah_fnNames[266].n = "parseFnHeader";
            __tmp____Bah_fnNames[266].p = parseFnHeader;

            __tmp____Bah_fnNames[267].n = "parseStruct";
            __tmp____Bah_fnNames[267].p = parseStruct;

            __tmp____Bah_fnNames[268].n = "parseDefine";
            __tmp____Bah_fnNames[268].p = parseDefine;

            __tmp____Bah_fnNames[269].n = "parseClib";
            __tmp____Bah_fnNames[269].p = parseClib;

            __tmp____Bah_fnNames[270].n = "parseConst";
            __tmp____Bah_fnNames[270].p = parseConst;

            __tmp____Bah_fnNames[271].n = "parseReturn";
            __tmp____Bah_fnNames[271].p = parseReturn;

            __tmp____Bah_fnNames[272].n = "parseIf";
            __tmp____Bah_fnNames[272].p = parseIf;

            __tmp____Bah_fnNames[273].n = "parseElse";
            __tmp____Bah_fnNames[273].p = parseElse;

            __tmp____Bah_fnNames[274].n = "parseLine";
            __tmp____Bah_fnNames[274].p = parseLine;

            __tmp____Bah_fnNames[275].n = "parseFor";
            __tmp____Bah_fnNames[275].p = parseFor;

            __tmp____Bah_fnNames[276].n = "parseForOp";
            __tmp____Bah_fnNames[276].p = parseForOp;

            __tmp____Bah_fnNames[277].n = "makeEvalFunc";
            __tmp____Bah_fnNames[277].p = makeEvalFunc;

            __tmp____Bah_fnNames[278].n = "parsePreKeyword";
            __tmp____Bah_fnNames[278].p = parsePreKeyword;

            __tmp____Bah_fnNames[279].n = "parseAsync";
            __tmp____Bah_fnNames[279].p = parseAsync;

            __tmp____Bah_fnNames[280].n = "addRCPvars";
            __tmp____Bah_fnNames[280].p = addRCPvars;

            __tmp____Bah_fnNames[281].n = "parseChan";
            __tmp____Bah_fnNames[281].p = parseChan;

            __tmp____Bah_fnNames[282].n = "valueFunc";
            __tmp____Bah_fnNames[282].p = valueFunc;

            __tmp____Bah_fnNames[283].n = "valueStruct";
            __tmp____Bah_fnNames[283].p = valueStruct;

            __tmp____Bah_fnNames[284].n = "valueArr";
            __tmp____Bah_fnNames[284].p = valueArr;

            __tmp____Bah_fnNames[285].n = "valueBool";
            __tmp____Bah_fnNames[285].p = valueBool;

            __tmp____Bah_fnNames[286].n = "valueOper";
            __tmp____Bah_fnNames[286].p = valueOper;

            __tmp____Bah_fnNames[287].n = "valueSendChan";
            __tmp____Bah_fnNames[287].p = valueSendChan;

            __tmp____Bah_fnNames[288].n = "valueChan";
            __tmp____Bah_fnNames[288].p = valueChan;

            __tmp____Bah_fnNames[289].n = "isSmallValue";
            __tmp____Bah_fnNames[289].p = isSmallValue;

            __tmp____Bah_fnNames[290].n = "isValue";
            __tmp____Bah_fnNames[290].p = isValue;

            __tmp____Bah_fnNames[291].n = "parseFnDeclare";
            __tmp____Bah_fnNames[291].p = parseFnDeclare;

            __tmp____Bah_fnNames[292].n = "declareFunc";
            __tmp____Bah_fnNames[292].p = declareFunc;

            __tmp____Bah_fnNames[293].n = "declareVar";
            __tmp____Bah_fnNames[293].p = declareVar;

            __tmp____Bah_fnNames[294].n = "declareAll";
            __tmp____Bah_fnNames[294].p = declareAll;

            __tmp____Bah_fnNames[295].n = "memErrHandle";
            __tmp____Bah_fnNames[295].p = memErrHandle;

            __tmp____Bah_fnNames[296].n = "main";
            __tmp____Bah_fnNames[296].p = main;

        __Bah_fnNames->data = __tmp____Bah_fnNames;
        __Bah_fnNames->length = 297;
        
    };
    