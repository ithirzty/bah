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
char * ____BAH_COMPILER_VAR_0 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(l);
unsigned int strLen_1 = strlen(") is null \n");
unsigned int strLen_2 = strlen("cpstring (");
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
struct mutexCondition ____BAH_COMPILER_VAR_1 = {};
#define m ____BAH_COMPILER_VAR_1
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
struct mutex ____BAH_COMPILER_VAR_2 = {};
#define m ____BAH_COMPILER_VAR_2
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
struct queueNode* ____BAH_COMPILER_VAR_3 = memoryAlloc(sizeof(struct queueNode));
____BAH_COMPILER_VAR_3->data= null;
____BAH_COMPILER_VAR_3->next= null;
____BAH_COMPILER_VAR_3->prev= null;
____BAH_COMPILER_VAR_3->key = this->length;
____BAH_COMPILER_VAR_3->data = data;
____BAH_COMPILER_VAR_3->prev = this->end;
struct queueNode* node = ____BAH_COMPILER_VAR_3;
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
struct channel* ____BAH_COMPILER_VAR_5 = memoryAlloc(sizeof(struct channel));
____BAH_COMPILER_VAR_5->w_waitting = 0;
____BAH_COMPILER_VAR_5->r_waitting = 0;
____BAH_COMPILER_VAR_5->queue= null;
____BAH_COMPILER_VAR_5->cap = -1;
struct channel* c = ____BAH_COMPILER_VAR_5;
pthread_mutex_init(&c->m_mut,0);
pthread_cond_init(&c->w_cond,0);
pthread_cond_init(&c->r_cond,0);
struct queue* ____BAH_COMPILER_VAR_6 = memoryAlloc(sizeof(struct queue));
____BAH_COMPILER_VAR_6->length = 0;
____BAH_COMPILER_VAR_6->head = null;
____BAH_COMPILER_VAR_6->end = null;
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
        unsigned long nLength = len(__Bah_fnNames);
        if (nLength >= __Bah_fnNames->length) {
            if (nLength >= __Bah_fnNames->realLength) {
                if (__Bah_fnNames->realLength != 0) {
                    __Bah_fnNames->realLength *= 2;
                } else {
                    __Bah_fnNames->realLength = 50;
                }
                void * newPtr = memoryRealloc(__Bah_fnNames->data, (__Bah_fnNames->realLength)*sizeof(struct __Bah_fnName_mapper));
                __Bah_fnNames->data = newPtr;
            }
            __Bah_fnNames->data[len(__Bah_fnNames)] = fnn;
            __Bah_fnNames->length = nLength+1;
        } else {
            __Bah_fnNames->data[len(__Bah_fnNames)] = fnn;
        }
    }
    ;
};
void __BAH_panic(char * e,char * line){
if ((__BAH_panic_chan!=null)) {
channel__send(__BAH_panic_chan, e);
return;
}
char * ____BAH_COMPILER_VAR_7 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(e);
unsigned int strLen_1 = strlen("\n");
unsigned int strLen_2 = strlen("): ");
unsigned int strLen_3 = strlen(line);
unsigned int strLen_4 = strlen("panic (");
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
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("Memory error (segfault).\n");
unsigned int strLen_1 = strlen(res);
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
char * ____BAH_COMPILER_VAR_9 =channel__receive(__BAH_panic_chan);char * err = ____BAH_COMPILER_VAR_9;
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
        unsigned long nLength = 47;
        if (nLength >= a->length) {
            if (nLength >= a->realLength) {
                if (a->realLength != 0) {
                    a->realLength *= 2;
                } else {
                    a->realLength = 50;
                }
                void * newPtr = memoryRealloc(a->data, (a->realLength)*sizeof(char));
                a->data = newPtr;
            }
            a->data[47] = 46;
            a->length = nLength+1;
        } else {
            a->data[47] = 46;
        }
    }
    ;

    {
        unsigned long nLength = 48;
        if (nLength >= a->length) {
            if (nLength >= a->realLength) {
                if (a->realLength != 0) {
                    a->realLength *= 2;
                } else {
                    a->realLength = 50;
                }
                void * newPtr = memoryRealloc(a->data, (a->realLength)*sizeof(char));
                a->data = newPtr;
            }
            a->data[48] = 46;
            a->length = nLength+1;
        } else {
            a->data[48] = 46;
        }
    }
    ;

    {
        unsigned long nLength = 49;
        if (nLength >= a->length) {
            if (nLength >= a->realLength) {
                if (a->realLength != 0) {
                    a->realLength *= 2;
                } else {
                    a->realLength = 50;
                }
                void * newPtr = memoryRealloc(a->data, (a->realLength)*sizeof(char));
                a->data = newPtr;
            }
            a->data[49] = 46;
            a->length = nLength+1;
        } else {
            a->data[49] = 46;
        }
    }
    ;

    {
        unsigned long nLength = 50;
        if (nLength >= a->length) {
            if (nLength >= a->realLength) {
                if (a->realLength != 0) {
                    a->realLength *= 2;
                } else {
                    a->realLength = 50;
                }
                void * newPtr = memoryRealloc(a->data, (a->realLength)*sizeof(char));
                a->data = newPtr;
            }
            a->data[50] = (char)0;
            a->length = nLength+1;
        } else {
            a->data[50] = (char)0;
        }
    }
    ;
}
char * ____BAH_COMPILER_VAR_10 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s);
unsigned int strLen_1 = strlen("\"");
unsigned int strLen_2 = strlen("\"");
;                            
            ____BAH_COMPILER_VAR_10 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_10+currStrOff, "\"", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_10+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_10+currStrOff, "\"", strLen_1);
            currStrOff += strLen_1;
        
        }return ____BAH_COMPILER_VAR_10;
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

    {
        unsigned long nLength = i;
        if (nLength >= this->elems->length) {
            if (nLength >= this->elems->realLength) {
                if (this->elems->realLength != 0) {
                    this->elems->realLength *= 2;
                } else {
                    this->elems->realLength = 50;
                }
                void * newPtr = memoryRealloc(this->elems->data, (this->elems->realLength)*sizeof(struct mapElem*));
                this->elems->data = newPtr;
            }
            this->elems->data[i] = null;
            this->elems->length = nLength+1;
        } else {
            this->elems->data[i] = null;
        }
    }
    ;
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

    {
        unsigned long nLength = i;
        if (nLength >= this->elems->length) {
            if (nLength >= this->elems->realLength) {
                if (this->elems->realLength != 0) {
                    this->elems->realLength *= 2;
                } else {
                    this->elems->realLength = 50;
                }
                void * newPtr = memoryRealloc(this->elems->data, (this->elems->realLength)*sizeof(struct mapElem*));
                this->elems->data = newPtr;
            }
            this->elems->data[i] = null;
            this->elems->length = nLength+1;
        } else {
            this->elems->data[i] = null;
        }
    }
    ;

    {
        unsigned long nLength = j;
        if (nLength >= this->elems->length) {
            if (nLength >= this->elems->realLength) {
                if (this->elems->realLength != 0) {
                    this->elems->realLength *= 2;
                } else {
                    this->elems->realLength = 50;
                }
                void * newPtr = memoryRealloc(this->elems->data, (this->elems->realLength)*sizeof(struct mapElem*));
                this->elems->data = newPtr;
            }
            this->elems->data[j] = e;
            this->elems->length = nLength+1;
        } else {
            this->elems->data[j] = e;
        }
    }
    ;
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
struct mapElem* ____BAH_COMPILER_VAR_11 = memoryAlloc(sizeof(struct mapElem));
____BAH_COMPILER_VAR_11->key= null;
____BAH_COMPILER_VAR_11->val= null;
____BAH_COMPILER_VAR_11->key = k;
____BAH_COMPILER_VAR_11->val = e;
struct mapElem* elem = ____BAH_COMPILER_VAR_11;
long int ind = __Bah_map_hash(k,len(this->elems));
register long int i = 0;
for (; (i<len(this->elems)); ++i) {
long int j = (i+ind)%len(this->elems);
struct mapElem* ce = this->elems->data[j];
if ((ce==null)) {

    {
        unsigned long nLength = j;
        if (nLength >= this->elems->length) {
            if (nLength >= this->elems->realLength) {
                if (this->elems->realLength != 0) {
                    this->elems->realLength *= 2;
                } else {
                    this->elems->realLength = 50;
                }
                void * newPtr = memoryRealloc(this->elems->data, (this->elems->realLength)*sizeof(struct mapElem*));
                this->elems->data = newPtr;
            }
            this->elems->data[j] = elem;
            this->elems->length = nLength+1;
        } else {
            this->elems->data[j] = elem;
        }
    }
    ;
++this->length;
break;
}
else if ((strcmp(ce->key, k) == 0)) {

    {
        unsigned long nLength = j;
        if (nLength >= this->elems->length) {
            if (nLength >= this->elems->realLength) {
                if (this->elems->realLength != 0) {
                    this->elems->realLength *= 2;
                } else {
                    this->elems->realLength = 50;
                }
                void * newPtr = memoryRealloc(this->elems->data, (this->elems->realLength)*sizeof(struct mapElem*));
                this->elems->data = newPtr;
            }
            this->elems->data[j] = elem;
            this->elems->length = nLength+1;
        } else {
            this->elems->data[j] = elem;
        }
    }
    ;
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
struct mapElem* ____BAH_COMPILER_VAR_12 = memoryAlloc(sizeof(struct mapElem));
____BAH_COMPILER_VAR_12->key= null;
____BAH_COMPILER_VAR_12->val= null;
____BAH_COMPILER_VAR_12->key = k;
____BAH_COMPILER_VAR_12->val = p;
struct mapElem* elem = ____BAH_COMPILER_VAR_12;
long int ind = __Bah_map_hash(k,len(this->elems));
register long int i = 0;
for (; (i<len(this->elems)); ++i) {
long int j = (i+ind)%len(this->elems);
struct mapElem* ce = this->elems->data[j];
if ((ce==null)) {

    {
        unsigned long nLength = j;
        if (nLength >= this->elems->length) {
            if (nLength >= this->elems->realLength) {
                if (this->elems->realLength != 0) {
                    this->elems->realLength *= 2;
                } else {
                    this->elems->realLength = 50;
                }
                void * newPtr = memoryRealloc(this->elems->data, (this->elems->realLength)*sizeof(struct mapElem*));
                this->elems->data = newPtr;
            }
            this->elems->data[j] = elem;
            this->elems->length = nLength+1;
        } else {
            this->elems->data[j] = elem;
        }
    }
    ;
++this->length;
break;
}
else if ((strcmp(ce->key, k) == 0)) {

    {
        unsigned long nLength = j;
        if (nLength >= this->elems->length) {
            if (nLength >= this->elems->realLength) {
                if (this->elems->realLength != 0) {
                    this->elems->realLength *= 2;
                } else {
                    this->elems->realLength = 50;
                }
                void * newPtr = memoryRealloc(this->elems->data, (this->elems->realLength)*sizeof(struct mapElem*));
                this->elems->data = newPtr;
            }
            this->elems->data[j] = elem;
            this->elems->length = nLength+1;
        } else {
            this->elems->data[j] = elem;
        }
    }
    ;
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

    {
        unsigned long nLength = j;
        if (nLength >= this->elems->length) {
            if (nLength >= this->elems->realLength) {
                if (this->elems->realLength != 0) {
                    this->elems->realLength *= 2;
                } else {
                    this->elems->realLength = 50;
                }
                void * newPtr = memoryRealloc(this->elems->data, (this->elems->realLength)*sizeof(struct mapElem*));
                this->elems->data = newPtr;
            }
            this->elems->data[j] = null;
            this->elems->length = nLength+1;
        } else {
            this->elems->data[j] = null;
        }
    }
    ;
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
struct mapWrapper* ____BAH_COMPILER_VAR_13 = memoryAlloc(sizeof(struct mapWrapper));
____BAH_COMPILER_VAR_13->elems = memoryAlloc(sizeof(array(struct mapElem*)));
            ____BAH_COMPILER_VAR_13->elems->length = 0;
            ____BAH_COMPILER_VAR_13->elems->elemSize = sizeof(struct mapElem*);
            struct mapWrapper* m = ____BAH_COMPILER_VAR_13;
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
char * ____BAH_COMPILER_VAR_14 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(response);
unsigned int strLen_1 = strlen(buff);
;                            
            ____BAH_COMPILER_VAR_14 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_14+currStrOff, response, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_14+currStrOff, buff, strLen_1);
            currStrOff += strLen_1;
        
        }response = ____BAH_COMPILER_VAR_14;
}
else {
while ((nDataLength>0)) {
char * ____BAH_COMPILER_VAR_15 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(response);
unsigned int strLen_1 = strlen(buff);
;                            
            ____BAH_COMPILER_VAR_15 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_15+currStrOff, response, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_15+currStrOff, buff, strLen_1);
            currStrOff += strLen_1;
        
        }response = ____BAH_COMPILER_VAR_15;
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
char * ____BAH_COMPILER_VAR_16 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s);
unsigned int strLen_1 = strlen("\n");
;                            
            ____BAH_COMPILER_VAR_16 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_16+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_16+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }write((void *)1,____BAH_COMPILER_VAR_16,strlen(s)+1);
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

    {
        unsigned long nLength = l;
        if (nLength >= rarr->length) {
            if (nLength >= rarr->realLength) {
                if (rarr->realLength != 0) {
                    rarr->realLength *= 2;
                } else {
                    rarr->realLength = 50;
                }
                void * newPtr = memoryRealloc(rarr->data, (rarr->realLength)*sizeof(char));
                rarr->data = newPtr;
            }
            rarr->data[l] = (char)0;
            rarr->length = nLength+1;
        } else {
            rarr->data[l] = (char)0;
        }
    }
    ;
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
char * ____BAH_COMPILER_VAR_17 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(this->name);
unsigned int strLen_1 = strlen("'.");
unsigned int strLen_2 = strlen("iostream: warning, auto-closing file: '");
;                            
            ____BAH_COMPILER_VAR_17 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_17+currStrOff, "iostream: warning, auto-closing file: '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_17+currStrOff, this->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_17+currStrOff, "'.", strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_17);
fileStream__close(this);
}
};
struct fileMap {
long int handle;
long int size;
void * p;
};
char * fileMap__open(struct fileMap* this,char * fileName){
struct fileStream ____BAH_COMPILER_VAR_18 = {};
____BAH_COMPILER_VAR_18.handle= null;
____BAH_COMPILER_VAR_18.name= null;
#define fs ____BAH_COMPILER_VAR_18
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

    {
        unsigned long nLength = lf;
        if (nLength >= files->length) {
            if (nLength >= files->realLength) {
                if (files->realLength != 0) {
                    files->realLength *= 2;
                } else {
                    files->realLength = 50;
                }
                void * newPtr = memoryRealloc(files->data, (files->realLength)*sizeof(char *));
                files->data = newPtr;
            }
            files->data[lf] = __STR(file->d_name);
            files->length = nLength+1;
        } else {
            files->data[lf] = __STR(file->d_name);
        }
    }
    ;
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
struct string ____BAH_COMPILER_VAR_19 = {};
____BAH_COMPILER_VAR_19.content= null;
#define needle ____BAH_COMPILER_VAR_19
string__set(&needle,nd);
struct string ____BAH_COMPILER_VAR_20 = {};
____BAH_COMPILER_VAR_20.content= null;
#define repl ____BAH_COMPILER_VAR_20
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

    {
        unsigned long nLength = len(buff);
        if (nLength >= buff->length) {
            if (nLength >= buff->realLength) {
                if (buff->realLength != 0) {
                    buff->realLength *= 2;
                } else {
                    buff->realLength = 50;
                }
                void * newPtr = memoryRealloc(buff->data, (buff->realLength)*sizeof(char));
                buff->data = newPtr;
            }
            buff->data[len(buff)] = string__charAt(this,j+replcBuffSart);
            buff->length = nLength+1;
        } else {
            buff->data[len(buff)] = string__charAt(this,j+replcBuffSart);
        }
    }
    ;
j = j+1;
};
replcBuffLength = 0;
}

    {
        unsigned long nLength = len(buff);
        if (nLength >= buff->length) {
            if (nLength >= buff->realLength) {
                if (buff->realLength != 0) {
                    buff->realLength *= 2;
                } else {
                    buff->realLength = 50;
                }
                void * newPtr = memoryRealloc(buff->data, (buff->realLength)*sizeof(char));
                buff->data = newPtr;
            }
            buff->data[len(buff)] = c;
            buff->length = nLength+1;
        } else {
            buff->data[len(buff)] = c;
        }
    }
    ;
}
if ((si==needle.length)) {
replcBuffLength = 0;
register long int ii = 0;
while ((ii<repl.length)) {
long int a = ii;

    {
        unsigned long nLength = len(buff);
        if (nLength >= buff->length) {
            if (nLength >= buff->realLength) {
                if (buff->realLength != 0) {
                    buff->realLength *= 2;
                } else {
                    buff->realLength = 50;
                }
                void * newPtr = memoryRealloc(buff->data, (buff->realLength)*sizeof(char));
                buff->data = newPtr;
            }
            buff->data[len(buff)] = string__charAt(&repl,ii);
            buff->length = nLength+1;
        } else {
            buff->data[len(buff)] = string__charAt(&repl,ii);
        }
    }
    ;
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
        unsigned long nLength = j;
        if (nLength >= replbuffStr->length) {
            if (nLength >= replbuffStr->realLength) {
                if (replbuffStr->realLength != 0) {
                    replbuffStr->realLength *= 2;
                } else {
                    replbuffStr->realLength = 50;
                }
                void * newPtr = memoryRealloc(replbuffStr->data, (replbuffStr->realLength)*sizeof(char));
                replbuffStr->data = newPtr;
            }
            replbuffStr->data[j] = string__charAt(this,j+replcBuffSart);
            replbuffStr->length = nLength+1;
        } else {
            replbuffStr->data[j] = string__charAt(this,j+replcBuffSart);
        }
    }
    ;
j = j+1;
};
char * ____BAH_COMPILER_VAR_21 =null;char * ____BAH_COMPILER_VAR_22 =arrAsStr(replbuffStr);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(r);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_22);
;                            
            ____BAH_COMPILER_VAR_21 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_21+currStrOff, r, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_21+currStrOff, ____BAH_COMPILER_VAR_22, strLen_1);
            currStrOff += strLen_1;
        
        }r = ____BAH_COMPILER_VAR_21;
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
struct string ____BAH_COMPILER_VAR_23 = {};
____BAH_COMPILER_VAR_23.content= null;
#define needle ____BAH_COMPILER_VAR_23
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
struct string ____BAH_COMPILER_VAR_24 = {};
____BAH_COMPILER_VAR_24.content= null;
#define r ____BAH_COMPILER_VAR_24
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
struct string ____BAH_COMPILER_VAR_25 = {};
____BAH_COMPILER_VAR_25.content= null;
#define a ____BAH_COMPILER_VAR_25
string__set(&a,s);
return a;

#undef a
};
char * intToStr(long int i){
if ((i==0)) {
return "0";
}
char ____BAH_COMPILER_VAR_26[66];char* s = ____BAH_COMPILER_VAR_26;
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
char * ____BAH_COMPILER_VAR_27 =intToStr(i);struct string r = string(____BAH_COMPILER_VAR_27);
return r;
};
char * floatToStr(double f){
char ____BAH_COMPILER_VAR_28[50];char* buff = ____BAH_COMPILER_VAR_28;
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
char * ____BAH_COMPILER_VAR_29 =charToString(c);string__append(&replcBuff,____BAH_COMPILER_VAR_29);
}
else {
if ((sepIndex>0)) {
sepIndex = 0;
char * ____BAH_COMPILER_VAR_30 =charToString(c);string__append(&replcBuff,____BAH_COMPILER_VAR_30);
register long int ii = 0;
while ((ii<replcBuff.length)) {

    {
        unsigned long nLength = len(tmpString);
        if (nLength >= tmpString->length) {
            if (nLength >= tmpString->realLength) {
                if (tmpString->realLength != 0) {
                    tmpString->realLength *= 2;
                } else {
                    tmpString->realLength = 50;
                }
                void * newPtr = memoryRealloc(tmpString->data, (tmpString->realLength)*sizeof(char));
                tmpString->data = newPtr;
            }
            tmpString->data[len(tmpString)] = string__charAt(&replcBuff,ii);
            tmpString->length = nLength+1;
        } else {
            tmpString->data[len(tmpString)] = string__charAt(&replcBuff,ii);
        }
    }
    ;
ii = ii+1;
};
string__set(&replcBuff,"");
}
else {

    {
        unsigned long nLength = len(tmpString);
        if (nLength >= tmpString->length) {
            if (nLength >= tmpString->realLength) {
                if (tmpString->realLength != 0) {
                    tmpString->realLength *= 2;
                } else {
                    tmpString->realLength = 50;
                }
                void * newPtr = memoryRealloc(tmpString->data, (tmpString->realLength)*sizeof(char));
                tmpString->data = newPtr;
            }
            tmpString->data[len(tmpString)] = c;
            tmpString->length = nLength+1;
        } else {
            tmpString->data[len(tmpString)] = c;
        }
    }
    ;
}
}
if ((sepIndex==sep.length)) {
string__set(&replcBuff,"");
struct string* ____BAH_COMPILER_VAR_31 = memoryAlloc(sizeof(struct string));
____BAH_COMPILER_VAR_31->content= null;
struct string* elem = ____BAH_COMPILER_VAR_31;
char * ____BAH_COMPILER_VAR_32 =arrToStr(tmpString);string__set(elem,____BAH_COMPILER_VAR_32);
long int lenRes = len(res);

    {
        unsigned long nLength = lenRes;
        if (nLength >= res->length) {
            if (nLength >= res->realLength) {
                if (res->realLength != 0) {
                    res->realLength *= 2;
                } else {
                    res->realLength = 50;
                }
                void * newPtr = memoryRealloc(res->data, (res->realLength)*sizeof(struct string));
                res->data = newPtr;
            }
            res->data[lenRes] = *elem;
            res->length = nLength+1;
        } else {
            res->data[lenRes] = *elem;
        }
    }
    ;
clear(tmpString);
sepIndex = 0;
}
i = i+1;
};
if ((replcBuff.length>0)) {
register long int ii = 0;
while ((ii<replcBuff.length)) {

    {
        unsigned long nLength = len(tmpString);
        if (nLength >= tmpString->length) {
            if (nLength >= tmpString->realLength) {
                if (tmpString->realLength != 0) {
                    tmpString->realLength *= 2;
                } else {
                    tmpString->realLength = 50;
                }
                void * newPtr = memoryRealloc(tmpString->data, (tmpString->realLength)*sizeof(char));
                tmpString->data = newPtr;
            }
            tmpString->data[len(tmpString)] = string__charAt(&replcBuff,ii);
            tmpString->length = nLength+1;
        } else {
            tmpString->data[len(tmpString)] = string__charAt(&replcBuff,ii);
        }
    }
    ;
ii = ii+1;
};
}
if ((len(tmpString)>0)) {
struct string* ____BAH_COMPILER_VAR_33 = memoryAlloc(sizeof(struct string));
____BAH_COMPILER_VAR_33->content= null;
struct string* elem = ____BAH_COMPILER_VAR_33;
char * ____BAH_COMPILER_VAR_34 =arrToStr(tmpString);string__set(elem,____BAH_COMPILER_VAR_34);
long int lenRes = len(res);

    {
        unsigned long nLength = lenRes;
        if (nLength >= res->length) {
            if (nLength >= res->realLength) {
                if (res->realLength != 0) {
                    res->realLength *= 2;
                } else {
                    res->realLength = 50;
                }
                void * newPtr = memoryRealloc(res->data, (res->realLength)*sizeof(struct string));
                res->data = newPtr;
            }
            res->data[lenRes] = *elem;
            res->length = nLength+1;
        } else {
            res->data[lenRes] = *elem;
        }
    }
    ;
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
char * ____BAH_COMPILER_VAR_35 =string__str(&e);struct string tmpS = string(____BAH_COMPILER_VAR_35);
if ((i!=max)) {
string__append(&tmpS,sep);
}
char * ____BAH_COMPILER_VAR_36 =string__str(&tmpS);string__append(&s,____BAH_COMPILER_VAR_36);
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

    {
        unsigned long nLength = len(ns);
        if (nLength >= ns->length) {
            if (nLength >= ns->realLength) {
                if (ns->realLength != 0) {
                    ns->realLength *= 2;
                } else {
                    ns->realLength = 50;
                }
                void * newPtr = memoryRealloc(ns->data, (ns->realLength)*sizeof(char));
                ns->data = newPtr;
            }
            ns->data[len(ns)] = c;
            ns->length = nLength+1;
        } else {
            ns->data[len(ns)] = c;
        }
    }
    ;
i = i+1;
};
char * ____BAH_COMPILER_VAR_37 =arrToStr(ns);return string(____BAH_COMPILER_VAR_37);
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
struct flag* ____BAH_COMPILER_VAR_38 = memoryAlloc(sizeof(struct flag));
____BAH_COMPILER_VAR_38->name= null;
____BAH_COMPILER_VAR_38->help= null;
____BAH_COMPILER_VAR_38->content= null;
struct flag* f = ____BAH_COMPILER_VAR_38;
f->name = name;
f->help = help;
f->type = FLAG_TYPE_CPSTRING;
long int lf = len(this->flags);

    {
        unsigned long nLength = lf;
        if (nLength >= this->flags->length) {
            if (nLength >= this->flags->realLength) {
                if (this->flags->realLength != 0) {
                    this->flags->realLength *= 2;
                } else {
                    this->flags->realLength = 50;
                }
                void * newPtr = memoryRealloc(this->flags->data, (this->flags->realLength)*sizeof(struct flag*));
                this->flags->data = newPtr;
            }
            this->flags->data[lf] = f;
            this->flags->length = nLength+1;
        } else {
            this->flags->data[lf] = f;
        }
    }
    ;
};
void flags__addBool(struct flags* this,char * name,char * help){
struct flag* ____BAH_COMPILER_VAR_39 = memoryAlloc(sizeof(struct flag));
____BAH_COMPILER_VAR_39->name= null;
____BAH_COMPILER_VAR_39->help= null;
____BAH_COMPILER_VAR_39->content= null;
struct flag* f = ____BAH_COMPILER_VAR_39;
f->name = name;
f->help = help;
f->type = FLAG_TYPE_BOOL;
long int lf = len(this->flags);

    {
        unsigned long nLength = lf;
        if (nLength >= this->flags->length) {
            if (nLength >= this->flags->realLength) {
                if (this->flags->realLength != 0) {
                    this->flags->realLength *= 2;
                } else {
                    this->flags->realLength = 50;
                }
                void * newPtr = memoryRealloc(this->flags->data, (this->flags->realLength)*sizeof(struct flag*));
                this->flags->data = newPtr;
            }
            this->flags->data[lf] = f;
            this->flags->length = nLength+1;
        } else {
            this->flags->data[lf] = f;
        }
    }
    ;
};
void flags__addInt(struct flags* this,char * name,char * help){
struct flag* ____BAH_COMPILER_VAR_40 = memoryAlloc(sizeof(struct flag));
____BAH_COMPILER_VAR_40->name= null;
____BAH_COMPILER_VAR_40->help= null;
____BAH_COMPILER_VAR_40->content= null;
struct flag* f = ____BAH_COMPILER_VAR_40;
f->name = name;
f->help = help;
f->type = FLAG_TYPE_INT;
long int lf = len(this->flags);

    {
        unsigned long nLength = lf;
        if (nLength >= this->flags->length) {
            if (nLength >= this->flags->realLength) {
                if (this->flags->realLength != 0) {
                    this->flags->realLength *= 2;
                } else {
                    this->flags->realLength = 50;
                }
                void * newPtr = memoryRealloc(this->flags->data, (this->flags->realLength)*sizeof(struct flag*));
                this->flags->data = newPtr;
            }
            this->flags->data[lf] = f;
            this->flags->length = nLength+1;
        } else {
            this->flags->data[lf] = f;
        }
    }
    ;
};
void flags__addFloat(struct flags* this,char * name,char * help){
struct flag* ____BAH_COMPILER_VAR_41 = memoryAlloc(sizeof(struct flag));
____BAH_COMPILER_VAR_41->name= null;
____BAH_COMPILER_VAR_41->help= null;
____BAH_COMPILER_VAR_41->content= null;
struct flag* f = ____BAH_COMPILER_VAR_41;
f->name = name;
f->help = help;
f->type = FLAG_TYPE_FLOAT;
long int lf = len(this->flags);

    {
        unsigned long nLength = lf;
        if (nLength >= this->flags->length) {
            if (nLength >= this->flags->realLength) {
                if (this->flags->realLength != 0) {
                    this->flags->realLength *= 2;
                } else {
                    this->flags->realLength = 50;
                }
                void * newPtr = memoryRealloc(this->flags->data, (this->flags->realLength)*sizeof(struct flag*));
                this->flags->data = newPtr;
            }
            this->flags->data[lf] = f;
            this->flags->length = nLength+1;
        } else {
            this->flags->data[lf] = f;
        }
    }
    ;
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
struct flag* ____BAH_COMPILER_VAR_42 = memoryAlloc(sizeof(struct flag));
____BAH_COMPILER_VAR_42->name= null;
____BAH_COMPILER_VAR_42->help= null;
____BAH_COMPILER_VAR_42->content= null;
struct flag* z = ____BAH_COMPILER_VAR_42;
z->isSet = 0;
return z;
};
char * flags__get(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_43 =string(name);struct flag* flag = flags__getFlag(this,____BAH_COMPILER_VAR_43);
return flag->content;
};
long int flags__getInt(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_44 =string(name);struct flag* flag = flags__getFlag(this,____BAH_COMPILER_VAR_44);
if ((flag->type!=FLAG_TYPE_INT)) {
char * ____BAH_COMPILER_VAR_45 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(flag->name);
unsigned int strLen_1 = strlen("' is not int.");
unsigned int strLen_2 = strlen("Flag '");
;                            
            ____BAH_COMPILER_VAR_45 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_45+currStrOff, "Flag '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_45+currStrOff, flag->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_45+currStrOff, "' is not int.", strLen_1);
            currStrOff += strLen_1;
        
        }__BAH_panic(____BAH_COMPILER_VAR_45,"/opt/bah/flags.bah:122");
}
return flag->cont_int;
};
double flags__getFloat(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_46 =string(name);struct flag* flag = flags__getFlag(this,____BAH_COMPILER_VAR_46);
if ((flag->type!=FLAG_TYPE_FLOAT)) {
char * ____BAH_COMPILER_VAR_47 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(flag->name);
unsigned int strLen_1 = strlen("' is not float.");
unsigned int strLen_2 = strlen("Flag '");
;                            
            ____BAH_COMPILER_VAR_47 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_47+currStrOff, "Flag '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_47+currStrOff, flag->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_47+currStrOff, "' is not float.", strLen_1);
            currStrOff += strLen_1;
        
        }__BAH_panic(____BAH_COMPILER_VAR_47,"/opt/bah/flags.bah:132");
}
return flag->cont_float;
};
long int flags__isSet(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_48 =string(name);struct flag* flag = flags__getFlag(this,____BAH_COMPILER_VAR_48);
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
char * ____BAH_COMPILER_VAR_49 =string__str(&argName);currentFlag->cont_int = strToInt(____BAH_COMPILER_VAR_49);
}
else if ((currentFlag->type==FLAG_TYPE_FLOAT)) {
char * ____BAH_COMPILER_VAR_50 =string__str(&argName);currentFlag->cont_float = strToFloat(____BAH_COMPILER_VAR_50);
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
struct timespec ____BAH_COMPILER_VAR_51 = {};
#define ts ____BAH_COMPILER_VAR_51
long int s = clock_gettime(CLOCK_REALTIME,&ts);
s = ts.tv_sec*1000000000+ts.tv_nsec;
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
struct rope* ____BAH_COMPILER_VAR_52 = memoryAlloc(sizeof(struct rope));
____BAH_COMPILER_VAR_52->left= null;
____BAH_COMPILER_VAR_52->right= null;
____BAH_COMPILER_VAR_52->str= null;
____BAH_COMPILER_VAR_52->len = 0;
struct rope* tmp = ____BAH_COMPILER_VAR_52;
tmp->left = this;
tmp->right = root2;
tmp->totalLen = this->totalLen+root2->totalLen;
tmp->str = null;
return tmp;
};
struct rope* createRopeStructure(struct rope* par,char * a,long int l,long int r){
struct rope* ____BAH_COMPILER_VAR_53 = memoryAlloc(sizeof(struct rope));
____BAH_COMPILER_VAR_53->left= null;
____BAH_COMPILER_VAR_53->right= null;
____BAH_COMPILER_VAR_53->str= null;
____BAH_COMPILER_VAR_53->len = 0;
struct rope* tmp = ____BAH_COMPILER_VAR_53;
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
struct rope* ____BAH_COMPILER_VAR_54 = memoryAlloc(sizeof(struct rope));
____BAH_COMPILER_VAR_54->left= null;
____BAH_COMPILER_VAR_54->right= null;
____BAH_COMPILER_VAR_54->str= null;
____BAH_COMPILER_VAR_54->len = 0;
struct rope* tmp = ____BAH_COMPILER_VAR_54;
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
char * ____BAH_COMPILER_VAR_55 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(cm);
unsigned int strLen_1 = strlen(" 2>/dev/null");
;                            
            ____BAH_COMPILER_VAR_55 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_55+currStrOff, cm, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_55+currStrOff, " 2>/dev/null", strLen_1);
            currStrOff += strLen_1;
        
        }cm = ____BAH_COMPILER_VAR_55;
}
else {
char * ____BAH_COMPILER_VAR_56 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(cm);
unsigned int strLen_1 = strlen(" 2>&1");
;                            
            ____BAH_COMPILER_VAR_56 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_56+currStrOff, cm, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_56+currStrOff, " 2>&1", strLen_1);
            currStrOff += strLen_1;
        
        }cm = ____BAH_COMPILER_VAR_56;
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
char * ____BAH_COMPILER_VAR_57 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(res);
unsigned int strLen_1 = strlen(buff);
;                            
            ____BAH_COMPILER_VAR_57 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_57+currStrOff, res, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_57+currStrOff, buff, strLen_1);
            currStrOff += strLen_1;
        
        }res = ____BAH_COMPILER_VAR_57;
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
char * ____BAH_COMPILER_VAR_58 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(cm);
unsigned int strLen_1 = strlen(" 2>/dev/null");
;                            
            ____BAH_COMPILER_VAR_58 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_58+currStrOff, cm, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_58+currStrOff, " 2>/dev/null", strLen_1);
            currStrOff += strLen_1;
        
        }cm = ____BAH_COMPILER_VAR_58;
}
else {
char * ____BAH_COMPILER_VAR_59 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(cm);
unsigned int strLen_1 = strlen(" 2>&1");
;                            
            ____BAH_COMPILER_VAR_59 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_59+currStrOff, cm, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_59+currStrOff, " 2>&1", strLen_1);
            currStrOff += strLen_1;
        
        }cm = ____BAH_COMPILER_VAR_59;
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
char * ____BAH_COMPILER_VAR_60 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(response);
unsigned int strLen_1 = strlen(buff);
;                            
            ____BAH_COMPILER_VAR_60 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_60+currStrOff, response, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_60+currStrOff, buff, strLen_1);
            currStrOff += strLen_1;
        
        }response = ____BAH_COMPILER_VAR_60;
res = fgets(buff,1023,this->handle);
};
this->status = pclose(this->handle);
arr->data=response;
arr->length=strlen(response);
return arr;
};
struct command command(char * s){
struct command ____BAH_COMPILER_VAR_61 = {};
____BAH_COMPILER_VAR_61.command= null;
____BAH_COMPILER_VAR_61.error = true;
____BAH_COMPILER_VAR_61.status = 0;
____BAH_COMPILER_VAR_61.input = null;
____BAH_COMPILER_VAR_61.handle= null;
#define cmd ____BAH_COMPILER_VAR_61
cmd.command = s;
return cmd;

#undef cmd
};
long int exec(char * s,__BAH_ARR_TYPE_cpstring args){
long int r;
array(char *)* nArgs = memoryAlloc(sizeof(array(char *)));

nArgs->length = 0;
nArgs->elemSize = sizeof(char *);

    {
        unsigned long nLength = 0;
        if (nLength >= nArgs->length) {
            if (nLength >= nArgs->realLength) {
                if (nArgs->realLength != 0) {
                    nArgs->realLength *= 2;
                } else {
                    nArgs->realLength = 50;
                }
                void * newPtr = memoryRealloc(nArgs->data, (nArgs->realLength)*sizeof(char *));
                nArgs->data = newPtr;
            }
            nArgs->data[0] = s;
            nArgs->length = nLength+1;
        } else {
            nArgs->data[0] = s;
        }
    }
    ;
register long int i = 0;
while ((i<len(args))) {

    {
        unsigned long nLength = i+1;
        if (nLength >= nArgs->length) {
            if (nLength >= nArgs->realLength) {
                if (nArgs->realLength != 0) {
                    nArgs->realLength *= 2;
                } else {
                    nArgs->realLength = 50;
                }
                void * newPtr = memoryRealloc(nArgs->data, (nArgs->realLength)*sizeof(char *));
                nArgs->data = newPtr;
            }
            nArgs->data[i+1] = args->data[i];
            nArgs->length = nLength+1;
        } else {
            nArgs->data[i+1] = args->data[i];
        }
    }
    ;
i = i+1;
};

    {
        unsigned long nLength = i+2;
        if (nLength >= nArgs->length) {
            if (nLength >= nArgs->realLength) {
                if (nArgs->realLength != 0) {
                    nArgs->realLength *= 2;
                } else {
                    nArgs->realLength = 50;
                }
                void * newPtr = memoryRealloc(nArgs->data, (nArgs->realLength)*sizeof(char *));
                nArgs->data = newPtr;
            }
            nArgs->data[i+2] = (char *)0;
            nArgs->length = nLength+1;
        } else {
            nArgs->data[i+2] = (char *)0;
        }
    }
    ;
r=execvp(s,nArgs->data);
return r;
};
char * BAH_DIR;
char * BAH_OS;
char * BAH_CC;
#define BAH_VERSION "v1.2 (build 110)"
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
struct Tok ____BAH_COMPILER_VAR_62 = {};
____BAH_COMPILER_VAR_62.cont = "";
____BAH_COMPILER_VAR_62.ogCont = "";
____BAH_COMPILER_VAR_62.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_62.pos = 0;
____BAH_COMPILER_VAR_62.line = 1;
____BAH_COMPILER_VAR_62.begLine = 1;
____BAH_COMPILER_VAR_62.bahType = "";
____BAH_COMPILER_VAR_62.isValue = false;
____BAH_COMPILER_VAR_62.isFunc = false;
____BAH_COMPILER_VAR_62.isOper = false;
____BAH_COMPILER_VAR_62.isEqual = false;
____BAH_COMPILER_VAR_62.pass = false;
____BAH_COMPILER_VAR_62.bahRef= null;
____BAH_COMPILER_VAR_62.parent= null;
#define t ____BAH_COMPILER_VAR_62
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
char * ____BAH_COMPILER_VAR_63 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("\n\e[0m\n");
unsigned int strLen_1 = strlen(msg);
unsigned int strLen_2 = strlen(posStr);
unsigned int strLen_3 = strlen(":");
unsigned int strLen_4 = strlen(lineStr);
unsigned int strLen_5 = strlen(":");
unsigned int strLen_6 = strlen(compilerState.currentFile);
unsigned int strLen_7 = strlen("\e[1;31m[LEXER-ERROR]\e[0m ");
;                            
            ____BAH_COMPILER_VAR_63 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7);
            
                    memcpy(____BAH_COMPILER_VAR_63+currStrOff, "\e[1;31m[LEXER-ERROR]\e[0m ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_63+currStrOff, compilerState.currentFile, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_63+currStrOff, ":", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_63+currStrOff, lineStr, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_63+currStrOff, ":", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_63+currStrOff, posStr, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_63+currStrOff, "\n\e[0m\n", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_63+currStrOff, msg, strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_63);
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

    {
        unsigned long nLength = 0;
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(char));
                memory->data = newPtr;
            }
            memory->data[0] = c;
            memory->length = nLength+1;
        } else {
            memory->data[0] = c;
        }
    }
    ;
i = i+1;
for (; (i<codeLength); ++i) {
c = s[i];
char pc = s[i-1];
if ((c==(char)34)) {
if ((pc!=(char)92)) {

    {
        unsigned long nLength = len(memory);
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(char));
                memory->data = newPtr;
            }
            memory->data[len(memory)] = c;
            memory->length = nLength+1;
        } else {
            memory->data[len(memory)] = c;
        }
    }
    ;
break;
}
}
if ((c==(char)10)) {
lineNb = lineNb+1;
if ((pc!=(char)92)) {

    {
        unsigned long nLength = len(memory);
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(char));
                memory->data = newPtr;
            }
            memory->data[len(memory)] = (char)92;
            memory->length = nLength+1;
        } else {
            memory->data[len(memory)] = (char)92;
        }
    }
    ;
c = 110;
}
}

    {
        unsigned long nLength = len(memory);
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(char));
                memory->data = newPtr;
            }
            memory->data[len(memory)] = c;
            memory->length = nLength+1;
        } else {
            memory->data[len(memory)] = c;
        }
    }
    ;
};

    {
        unsigned long nLength = len(tokens);
        if (nLength >= tokens->length) {
            if (nLength >= tokens->realLength) {
                if (tokens->realLength != 0) {
                    tokens->realLength *= 2;
                } else {
                    tokens->realLength = 50;
                }
                void * newPtr = memoryRealloc(tokens->data, (tokens->realLength)*sizeof(struct Tok));
                tokens->data = newPtr;
            }
            tokens->data[len(tokens)] = makeToken(pos,lineNb,memory,TOKEN_TYPE_STR);
            tokens->length = nLength+1;
        } else {
            tokens->data[len(tokens)] = makeToken(pos,lineNb,memory,TOKEN_TYPE_STR);
        }
    }
    ;
struct Tok lt = tokens->data[len(tokens)-1];
lt.begLine = begLine;

    {
        unsigned long nLength = len(tokens)-1;
        if (nLength >= tokens->length) {
            if (nLength >= tokens->realLength) {
                if (tokens->realLength != 0) {
                    tokens->realLength *= 2;
                } else {
                    tokens->realLength = 50;
                }
                void * newPtr = memoryRealloc(tokens->data, (tokens->realLength)*sizeof(struct Tok));
                tokens->data = newPtr;
            }
            tokens->data[len(tokens)-1] = lt;
            tokens->length = nLength+1;
        } else {
            tokens->data[len(tokens)-1] = lt;
        }
    }
    ;
}
else if (isNumber(c)||isMinus(c,nc)) {

    {
        unsigned long nLength = 0;
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(char));
                memory->data = newPtr;
            }
            memory->data[0] = c;
            memory->length = nLength+1;
        } else {
            memory->data[0] = c;
        }
    }
    ;
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

    {
        unsigned long nLength = len(memory);
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(char));
                memory->data = newPtr;
            }
            memory->data[len(memory)] = c;
            memory->length = nLength+1;
        } else {
            memory->data[len(memory)] = c;
        }
    }
    ;
};
--i;

    {
        unsigned long nLength = len(tokens);
        if (nLength >= tokens->length) {
            if (nLength >= tokens->realLength) {
                if (tokens->realLength != 0) {
                    tokens->realLength *= 2;
                } else {
                    tokens->realLength = 50;
                }
                void * newPtr = memoryRealloc(tokens->data, (tokens->realLength)*sizeof(struct Tok));
                tokens->data = newPtr;
            }
            tokens->data[len(tokens)] = makeToken(pos,lineNb,memory,currentType);
            tokens->length = nLength+1;
        } else {
            tokens->data[len(tokens)] = makeToken(pos,lineNb,memory,currentType);
        }
    }
    ;
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

    {
        unsigned long nLength = len(tokens);
        if (nLength >= tokens->length) {
            if (nLength >= tokens->realLength) {
                if (tokens->realLength != 0) {
                    tokens->realLength *= 2;
                } else {
                    tokens->realLength = 50;
                }
                void * newPtr = memoryRealloc(tokens->data, (tokens->realLength)*sizeof(struct Tok));
                tokens->data = newPtr;
            }
            tokens->data[len(tokens)] = makeToken(i-1,lineNb,memory,TOKEN_TYPE_CHAR);
            tokens->length = nLength+1;
        } else {
            tokens->data[len(tokens)] = makeToken(i-1,lineNb,memory,TOKEN_TYPE_CHAR);
        }
    }
    ;
}
else if ((c==(char)35)) {
long int pos = i;

    {
        unsigned long nLength = 0;
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(char));
                memory->data = newPtr;
            }
            memory->data[0] = c;
            memory->length = nLength+1;
        } else {
            memory->data[0] = c;
        }
    }
    ;
++i;
for (; (i<codeLength); ++i) {
c = s[i];
if ((isAlphaNumeric(c)==false)) {
break;
}

    {
        unsigned long nLength = len(memory);
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(char));
                memory->data = newPtr;
            }
            memory->data[len(memory)] = c;
            memory->length = nLength+1;
        } else {
            memory->data[len(memory)] = c;
        }
    }
    ;
};
--i;

    {
        unsigned long nLength = len(tokens);
        if (nLength >= tokens->length) {
            if (nLength >= tokens->realLength) {
                if (tokens->realLength != 0) {
                    tokens->realLength *= 2;
                } else {
                    tokens->realLength = 50;
                }
                void * newPtr = memoryRealloc(tokens->data, (tokens->realLength)*sizeof(struct Tok));
                tokens->data = newPtr;
            }
            tokens->data[len(tokens)] = makeToken(pos,lineNb,memory,TOKEN_TYPE_KEYWORD);
            tokens->length = nLength+1;
        } else {
            tokens->data[len(tokens)] = makeToken(pos,lineNb,memory,TOKEN_TYPE_KEYWORD);
        }
    }
    ;
}
else if (inArray(c,enclavers)) {

    {
        unsigned long nLength = 0;
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(char));
                memory->data = newPtr;
            }
            memory->data[0] = c;
            memory->length = nLength+1;
        } else {
            memory->data[0] = c;
        }
    }
    ;

    {
        unsigned long nLength = len(tokens);
        if (nLength >= tokens->length) {
            if (nLength >= tokens->realLength) {
                if (tokens->realLength != 0) {
                    tokens->realLength *= 2;
                } else {
                    tokens->realLength = 50;
                }
                void * newPtr = memoryRealloc(tokens->data, (tokens->realLength)*sizeof(struct Tok));
                tokens->data = newPtr;
            }
            tokens->data[len(tokens)] = makeToken(i,lineNb,memory,TOKEN_TYPE_ENCL);
            tokens->length = nLength+1;
        } else {
            tokens->data[len(tokens)] = makeToken(i,lineNb,memory,TOKEN_TYPE_ENCL);
        }
    }
    ;
}
else if (inArray(c,syntaxes)) {
if ((c==60)) {
long int pos = i;
char isCast = false;

    {
        unsigned long nLength = 0;
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(char));
                memory->data = newPtr;
            }
            memory->data[0] = c;
            memory->length = nLength+1;
        } else {
            memory->data[0] = c;
        }
    }
    ;
++i;
for (; (i<codeLength); ++i) {
c = s[i];
if ((c==62)) {
isCast = true;

    {
        unsigned long nLength = len(memory);
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(char));
                memory->data = newPtr;
            }
            memory->data[len(memory)] = c;
            memory->length = nLength+1;
        } else {
            memory->data[len(memory)] = c;
        }
    }
    ;
break;
}
if ((isAlphaNumeric(c)==false)&&(c!=42)&&(c!=58)&&(c!=95)&&(c!=91)&&(c!=93)) {
break;
}

    {
        unsigned long nLength = len(memory);
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(char));
                memory->data = newPtr;
            }
            memory->data[len(memory)] = c;
            memory->length = nLength+1;
        } else {
            memory->data[len(memory)] = c;
        }
    }
    ;
};
if ((isCast==true)) {

    {
        unsigned long nLength = len(tokens);
        if (nLength >= tokens->length) {
            if (nLength >= tokens->realLength) {
                if (tokens->realLength != 0) {
                    tokens->realLength *= 2;
                } else {
                    tokens->realLength = 50;
                }
                void * newPtr = memoryRealloc(tokens->data, (tokens->realLength)*sizeof(struct Tok));
                tokens->data = newPtr;
            }
            tokens->data[len(tokens)] = makeToken(pos,lineNb,memory,TOKEN_TYPE_CAST);
            tokens->length = nLength+1;
        } else {
            tokens->data[len(tokens)] = makeToken(pos,lineNb,memory,TOKEN_TYPE_CAST);
        }
    }
    ;
continue;
}
i = pos;
c = 60;
clear(memory);
}

    {
        unsigned long nLength = 0;
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(char));
                memory->data = newPtr;
            }
            memory->data[0] = c;
            memory->length = nLength+1;
        } else {
            memory->data[0] = c;
        }
    }
    ;
long int pos = i;
++i;
char fc = c;
for (; (i<codeLength); ++i) {
c = s[i];

        char ____BAH_COMPILER_VAR_64 = 0;
        for(int i=syntaxes->length-1; i!=-1;i--) {
            if (syntaxes->data[i] == c) {
                ____BAH_COMPILER_VAR_64=1;
                break;
            };
        }
        if ((____BAH_COMPILER_VAR_64==false)) {
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
        unsigned long nLength = len(memory);
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(char));
                memory->data = newPtr;
            }
            memory->data[len(memory)] = c;
            memory->length = nLength+1;
        } else {
            memory->data[len(memory)] = c;
        }
    }
    ;
};
--i;

    {
        unsigned long nLength = len(tokens);
        if (nLength >= tokens->length) {
            if (nLength >= tokens->realLength) {
                if (tokens->realLength != 0) {
                    tokens->realLength *= 2;
                } else {
                    tokens->realLength = 50;
                }
                void * newPtr = memoryRealloc(tokens->data, (tokens->realLength)*sizeof(struct Tok));
                tokens->data = newPtr;
            }
            tokens->data[len(tokens)] = makeToken(pos,lineNb,memory,TOKEN_TYPE_SYNTAX);
            tokens->length = nLength+1;
        } else {
            tokens->data[len(tokens)] = makeToken(pos,lineNb,memory,TOKEN_TYPE_SYNTAX);
        }
    }
    ;
}
else if ((c==46)) {

    {
        unsigned long nLength = 0;
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(char));
                memory->data = newPtr;
            }
            memory->data[0] = c;
            memory->length = nLength+1;
        } else {
            memory->data[0] = c;
        }
    }
    ;

    {
        unsigned long nLength = len(tokens);
        if (nLength >= tokens->length) {
            if (nLength >= tokens->realLength) {
                if (tokens->realLength != 0) {
                    tokens->realLength *= 2;
                } else {
                    tokens->realLength = 50;
                }
                void * newPtr = memoryRealloc(tokens->data, (tokens->realLength)*sizeof(struct Tok));
                tokens->data = newPtr;
            }
            tokens->data[len(tokens)] = makeToken(i,lineNb,memory,TOKEN_TYPE_SEP);
            tokens->length = nLength+1;
        } else {
            tokens->data[len(tokens)] = makeToken(i,lineNb,memory,TOKEN_TYPE_SEP);
        }
    }
    ;
}
else if (isAlphaNumeric(c)||(c==95)) {

    {
        unsigned long nLength = 0;
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(char));
                memory->data = newPtr;
            }
            memory->data[0] = c;
            memory->length = nLength+1;
        } else {
            memory->data[0] = c;
        }
    }
    ;
long int pos = i;
++i;
for (; (i<codeLength); ++i) {
c = s[i];
if ((isAlphaNumeric(c)==false)) {
if ((c!=95)) {
if ((c==62)) {
char lc = memory->data[len(memory)-1];
if ((lc==45)) {

    {
        unsigned long nLength = len(memory)-1;
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(char));
                memory->data = newPtr;
            }
            memory->data[len(memory)-1] = (char)0;
            memory->length = nLength+1;
        } else {
            memory->data[len(memory)-1] = (char)0;
        }
    }
    ;
--i;
break;
}
}
break;
}
}

    {
        unsigned long nLength = len(memory);
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(char));
                memory->data = newPtr;
            }
            memory->data[len(memory)] = c;
            memory->length = nLength+1;
        } else {
            memory->data[len(memory)] = c;
        }
    }
    ;
};
--i;
tokenType currentType = TOKEN_TYPE_VAR;
char * memstr = arrAsStr(memory);

        char ____BAH_COMPILER_VAR_65 = 0;
        for(int i=keywords->length-1; i!=-1;i--) {
            if (keywords->data[i] != 0 && strcmp(keywords->data[i], memstr) == 0) {
                ____BAH_COMPILER_VAR_65=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_65) {
currentType = TOKEN_TYPE_KEYWORD;
}

    {
        unsigned long nLength = len(tokens);
        if (nLength >= tokens->length) {
            if (nLength >= tokens->realLength) {
                if (tokens->realLength != 0) {
                    tokens->realLength *= 2;
                } else {
                    tokens->realLength = 50;
                }
                void * newPtr = memoryRealloc(tokens->data, (tokens->realLength)*sizeof(struct Tok));
                tokens->data = newPtr;
            }
            tokens->data[len(tokens)] = makeToken(pos,lineNb,memory,currentType);
            tokens->length = nLength+1;
        } else {
            tokens->data[len(tokens)] = makeToken(pos,lineNb,memory,currentType);
        }
    }
    ;
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
char * ____BAH_COMPILER_VAR_66 =splitStringBefore(*n,".");struct string res = string(____BAH_COMPILER_VAR_66);
return res;
}
if (string__count(n,"->")) {
char * ____BAH_COMPILER_VAR_67 =splitStringBefore(*n,"->");struct string res = string(____BAH_COMPILER_VAR_67);
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
struct structMemb* ____BAH_COMPILER_VAR_68 = memoryAlloc(sizeof(struct structMemb));
____BAH_COMPILER_VAR_68->name = "";
____BAH_COMPILER_VAR_68->type = "";
____BAH_COMPILER_VAR_68->isConst = false;
____BAH_COMPILER_VAR_68->constVal = "";
____BAH_COMPILER_VAR_68->isArray = false;
____BAH_COMPILER_VAR_68->from = "";
____BAH_COMPILER_VAR_68->declScope= null;
____BAH_COMPILER_VAR_68->isGlobal = false;
____BAH_COMPILER_VAR_68->declRope= null;
____BAH_COMPILER_VAR_68->canBeNull = false;
____BAH_COMPILER_VAR_68->isReg = false;
____BAH_COMPILER_VAR_68->lastSet= null;
____BAH_COMPILER_VAR_68->isArg = false;
____BAH_COMPILER_VAR_68->def = "";
____BAH_COMPILER_VAR_68->isFn = false;
struct structMemb* sm = ____BAH_COMPILER_VAR_68;
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
char * ____BAH_COMPILER_VAR_69 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("__");
unsigned int strLen_1 = strlen(name);
unsigned int strLen_2 = strlen(s->name);
;                            
            ____BAH_COMPILER_VAR_69 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_69+currStrOff, s->name, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_69+currStrOff, "__", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_69+currStrOff, name, strLen_1);
            currStrOff += strLen_1;
        
        }struct func* fn = searchFunc(____BAH_COMPILER_VAR_69,elems,true);
if ((fn!=null)) {
return fn;
}
register long int i = 0;
for (; (i<len(s->members)); ++i) {
if ((strcmp(s->members->data[i]->name, name) == 0)) {
struct string ____BAH_COMPILER_VAR_70 =string(s->members->data[i]->type);fn = parseFnType(____BAH_COMPILER_VAR_70);
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
char * ____BAH_COMPILER_VAR_71 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t);
unsigned int strLen_1 = strlen(")*");
unsigned int strLen_2 = strlen("array(");
;                            
            ____BAH_COMPILER_VAR_71 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_71+currStrOff, "array(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_71+currStrOff, t, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_71+currStrOff, ")*", strLen_1);
            currStrOff += strLen_1;
        
        }char * r = ____BAH_COMPILER_VAR_71;
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
char * ____BAH_COMPILER_VAR_72 =null;char * ____BAH_COMPILER_VAR_73 =cpstringSubsitute(a, 0, strlen(a)-1);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_73);
unsigned int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_72 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_72+currStrOff, ____BAH_COMPILER_VAR_73, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_72+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }a = ____BAH_COMPILER_VAR_72;
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

        char ____BAH_COMPILER_VAR_74 = 0;
        for(int i=intTypes->length-1; i!=-1;i--) {
            if (intTypes->data[i] != 0 && strcmp(intTypes->data[i], a) == 0) {
                ____BAH_COMPILER_VAR_74=1;
                break;
            };
        }
        
        char ____BAH_COMPILER_VAR_75 = 0;
        for(int i=intTypes->length-1; i!=-1;i--) {
            if (intTypes->data[i] != 0 && strcmp(intTypes->data[i], b) == 0) {
                ____BAH_COMPILER_VAR_75=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_74&&____BAH_COMPILER_VAR_75) {
return true;
}

        char ____BAH_COMPILER_VAR_76 = 0;
        for(int i=floatTypes->length-1; i!=-1;i--) {
            if (floatTypes->data[i] != 0 && strcmp(floatTypes->data[i], a) == 0) {
                ____BAH_COMPILER_VAR_76=1;
                break;
            };
        }
        
        char ____BAH_COMPILER_VAR_77 = 0;
        for(int i=floatTypes->length-1; i!=-1;i--) {
            if (floatTypes->data[i] != 0 && strcmp(floatTypes->data[i], b) == 0) {
                ____BAH_COMPILER_VAR_77=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_76&&____BAH_COMPILER_VAR_77) {
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
struct reflectElement ____BAH_COMPILER_VAR_78 = {};
____BAH_COMPILER_VAR_78.type= null;
____BAH_COMPILER_VAR_78.name= null;
____BAH_COMPILER_VAR_78.arrayElem= null;
____BAH_COMPILER_VAR_78.structLayout = memoryAlloc(sizeof(array(struct reflectElement)));
            ____BAH_COMPILER_VAR_78.structLayout->length = 0;
            ____BAH_COMPILER_VAR_78.structLayout->elemSize = sizeof(struct reflectElement);
            ____BAH_COMPILER_VAR_78.value= null;
#define re ____BAH_COMPILER_VAR_78
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
struct reflectElement ____BAH_COMPILER_VAR_79 = {};
____BAH_COMPILER_VAR_79.type= null;
____BAH_COMPILER_VAR_79.name= null;
____BAH_COMPILER_VAR_79.arrayElem= null;
____BAH_COMPILER_VAR_79.structLayout = memoryAlloc(sizeof(array(struct reflectElement)));
            ____BAH_COMPILER_VAR_79.structLayout->length = 0;
            ____BAH_COMPILER_VAR_79.structLayout->elemSize = sizeof(struct reflectElement);
            ____BAH_COMPILER_VAR_79.value= null;
#define ns ____BAH_COMPILER_VAR_79
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

    {
        unsigned long nLength = j-1;
        if (nLength >= nk->length) {
            if (nLength >= nk->realLength) {
                if (nk->realLength != 0) {
                    nk->realLength *= 2;
                } else {
                    nk->realLength = 50;
                }
                void * newPtr = memoryRealloc(nk->data, (nk->realLength)*sizeof(char));
                nk->data = newPtr;
            }
            nk->data[j-1] = c;
            nk->length = nLength+1;
        } else {
            nk->data[j-1] = c;
        }
    }
    ;
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
        unsigned long nLength = i;
        if (nLength >= arr->length) {
            if (nLength >= arr->realLength) {
                if (arr->realLength != 0) {
                    arr->realLength *= 2;
                } else {
                    arr->realLength = 50;
                }
                void * newPtr = memoryRealloc(arr->data, (arr->realLength)*sizeof(long int));
                arr->data = newPtr;
            }
            arr->data[i] = strToInt(c->content);
            arr->length = nLength+1;
        } else {
            arr->data[i] = strToInt(c->content);
        }
    }
    ;
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
        unsigned long nLength = i;
        if (nLength >= arr->length) {
            if (nLength >= arr->realLength) {
                if (arr->realLength != 0) {
                    arr->realLength *= 2;
                } else {
                    arr->realLength = 50;
                }
                void * newPtr = memoryRealloc(arr->data, (arr->realLength)*sizeof(double));
                arr->data = newPtr;
            }
            arr->data[i] = strToFloat(c->content);
            arr->length = nLength+1;
        } else {
            arr->data[i] = strToFloat(c->content);
        }
    }
    ;
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
        unsigned long nLength = i;
        if (nLength >= arr->length) {
            if (nLength >= arr->realLength) {
                if (arr->realLength != 0) {
                    arr->realLength *= 2;
                } else {
                    arr->realLength = 50;
                }
                void * newPtr = memoryRealloc(arr->data, (arr->realLength)*sizeof(char *));
                arr->data = newPtr;
            }
            arr->data[i] = memoryAlloc(strlen(c->content)+1);
            arr->length = nLength+1;
        } else {
            arr->data[i] = memoryAlloc(strlen(c->content)+1);
        }
    }
    ;
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
m.value = reflectElement__calculateOffset(&m,ne);
struct jsonElement* ov = jsonElement__get(c,m.name);
if ((ov!=null)) {
json_scan_inner(ov,m,true);
}
j = j+1;
};

    {
        unsigned long nLength = i;
        if (nLength >= arr->length) {
            if (nLength >= arr->realLength) {
                if (arr->realLength != 0) {
                    arr->realLength *= 2;
                } else {
                    arr->realLength = 50;
                }
                void * newPtr = memoryRealloc(arr->data, (arr->realLength)*sizeof(void *));
                arr->data = newPtr;
            }
            arr->data[i] = ne;
            arr->length = nLength+1;
        } else {
            arr->data[i] = ne;
        }
    }
    ;
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

    {
        unsigned long nLength = j;
        if (nLength >= ae->structLayout->length) {
            if (nLength >= ae->structLayout->realLength) {
                if (ae->structLayout->realLength != 0) {
                    ae->structLayout->realLength *= 2;
                } else {
                    ae->structLayout->realLength = 50;
                }
                void * newPtr = memoryRealloc(ae->structLayout->data, (ae->structLayout->realLength)*sizeof(struct reflectElement));
                ae->structLayout->data = newPtr;
            }
            ae->structLayout->data[j] = m;
            ae->structLayout->length = nLength+1;
        } else {
            ae->structLayout->data[j] = m;
        }
    }
    ;
};
json_scan_inner(c,*ae,true);
struct string k = string(c->key);
string__trimLeft(&k,1);
string__trimRight(&k,1);
if (strCount(ae->type,"*")||(strcmp(ae->type, "ptr") == 0)||(strcmp(ae->type, "cpstring") == 0)||strHasPrefix(ae->type,"[]")||strHasPrefix(ae->type,"map:")) {
char * ____BAH_COMPILER_VAR_80 =string__str(&k);mapWrapper__set(*p,____BAH_COMPILER_VAR_80,v);
}
else {
char * ____BAH_COMPILER_VAR_81 =string__str(&k);mapWrapper__set(*p,____BAH_COMPILER_VAR_81,&v);
}
};
}
};
struct jsonElement* parseJson(char * s){
struct jsonElement* ____BAH_COMPILER_VAR_82 = memoryAlloc(sizeof(struct jsonElement));
____BAH_COMPILER_VAR_82->key= null;
____BAH_COMPILER_VAR_82->content= null;
____BAH_COMPILER_VAR_82->children = memoryAlloc(sizeof(array(struct jsonElement*)));
            ____BAH_COMPILER_VAR_82->children->length = 0;
            ____BAH_COMPILER_VAR_82->children->elemSize = sizeof(struct jsonElement*);
            struct jsonElement* jsonElem = ____BAH_COMPILER_VAR_82;
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
        unsigned long nLength = len(ns)-1;
        if (nLength >= ns->length) {
            if (nLength >= ns->realLength) {
                if (ns->realLength != 0) {
                    ns->realLength *= 2;
                } else {
                    ns->realLength = 50;
                }
                void * newPtr = memoryRealloc(ns->data, (ns->realLength)*sizeof(char));
                ns->data = newPtr;
            }
            ns->data[len(ns)-1] = c;
            ns->length = nLength+1;
        } else {
            ns->data[len(ns)-1] = c;
        }
    }
    ;
}
else {

    {
        unsigned long nLength = len(ns);
        if (nLength >= ns->length) {
            if (nLength >= ns->realLength) {
                if (ns->realLength != 0) {
                    ns->realLength *= 2;
                } else {
                    ns->realLength = 50;
                }
                void * newPtr = memoryRealloc(ns->data, (ns->realLength)*sizeof(char));
                ns->data = newPtr;
            }
            ns->data[len(ns)] = c;
            ns->length = nLength+1;
        } else {
            ns->data[len(ns)] = c;
        }
    }
    ;
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
        unsigned long nLength = len(currentElem);
        if (nLength >= currentElem->length) {
            if (nLength >= currentElem->realLength) {
                if (currentElem->realLength != 0) {
                    currentElem->realLength *= 2;
                } else {
                    currentElem->realLength = 50;
                }
                void * newPtr = memoryRealloc(currentElem->data, (currentElem->realLength)*sizeof(char));
                currentElem->data = newPtr;
            }
            currentElem->data[len(currentElem)] = c;
            currentElem->length = nLength+1;
        } else {
            currentElem->data[len(currentElem)] = c;
        }
    }
    ;
i = i+1;
continue;
}
if ((c==44)) {
char * ____BAH_COMPILER_VAR_83 =arrToStr(currentElem);struct jsonElement* child = parseJson(____BAH_COMPILER_VAR_83);
if ((child!=null)) {

    {
        unsigned long nLength = elemIndex;
        if (nLength >= jsonElem->children->length) {
            if (nLength >= jsonElem->children->realLength) {
                if (jsonElem->children->realLength != 0) {
                    jsonElem->children->realLength *= 2;
                } else {
                    jsonElem->children->realLength = 50;
                }
                void * newPtr = memoryRealloc(jsonElem->children->data, (jsonElem->children->realLength)*sizeof(struct jsonElement*));
                jsonElem->children->data = newPtr;
            }
            jsonElem->children->data[elemIndex] = child;
            jsonElem->children->length = nLength+1;
        } else {
            jsonElem->children->data[elemIndex] = child;
        }
    }
    ;
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
        unsigned long nLength = len(currentElem);
        if (nLength >= currentElem->length) {
            if (nLength >= currentElem->realLength) {
                if (currentElem->realLength != 0) {
                    currentElem->realLength *= 2;
                } else {
                    currentElem->realLength = 50;
                }
                void * newPtr = memoryRealloc(currentElem->data, (currentElem->realLength)*sizeof(char));
                currentElem->data = newPtr;
            }
            currentElem->data[len(currentElem)] = c;
            currentElem->length = nLength+1;
        } else {
            currentElem->data[len(currentElem)] = c;
        }
    }
    ;
}
i = i+1;
};
char * ____BAH_COMPILER_VAR_84 =arrToStr(currentElem);struct jsonElement* child = parseJson(____BAH_COMPILER_VAR_84);
if ((child!=null)) {

    {
        unsigned long nLength = elemIndex;
        if (nLength >= jsonElem->children->length) {
            if (nLength >= jsonElem->children->realLength) {
                if (jsonElem->children->realLength != 0) {
                    jsonElem->children->realLength *= 2;
                } else {
                    jsonElem->children->realLength = 50;
                }
                void * newPtr = memoryRealloc(jsonElem->children->data, (jsonElem->children->realLength)*sizeof(struct jsonElement*));
                jsonElem->children->data = newPtr;
            }
            jsonElem->children->data[elemIndex] = child;
            jsonElem->children->length = nLength+1;
        } else {
            jsonElem->children->data[elemIndex] = child;
        }
    }
    ;
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
        unsigned long nLength = len(currentElem);
        if (nLength >= currentElem->length) {
            if (nLength >= currentElem->realLength) {
                if (currentElem->realLength != 0) {
                    currentElem->realLength *= 2;
                } else {
                    currentElem->realLength = 50;
                }
                void * newPtr = memoryRealloc(currentElem->data, (currentElem->realLength)*sizeof(char));
                currentElem->data = newPtr;
            }
            currentElem->data[len(currentElem)] = c;
            currentElem->length = nLength+1;
        } else {
            currentElem->data[len(currentElem)] = c;
        }
    }
    ;
}
else {

    {
        unsigned long nLength = len(currentKey);
        if (nLength >= currentKey->length) {
            if (nLength >= currentKey->realLength) {
                if (currentKey->realLength != 0) {
                    currentKey->realLength *= 2;
                } else {
                    currentKey->realLength = 50;
                }
                void * newPtr = memoryRealloc(currentKey->data, (currentKey->realLength)*sizeof(char));
                currentKey->data = newPtr;
            }
            currentKey->data[len(currentKey)] = c;
            currentKey->length = nLength+1;
        } else {
            currentKey->data[len(currentKey)] = c;
        }
    }
    ;
}
i = i+1;
continue;
}
if ((c==58)) {
isVal = 1;
}
else if ((c==44)) {
char * ____BAH_COMPILER_VAR_85 =arrToStr(currentElem);struct jsonElement* elem = parseJson(____BAH_COMPILER_VAR_85);
if ((elem!=null)) {
elem->key = arrToStr(currentKey);

    {
        unsigned long nLength = elemIndex;
        if (nLength >= jsonElem->children->length) {
            if (nLength >= jsonElem->children->realLength) {
                if (jsonElem->children->realLength != 0) {
                    jsonElem->children->realLength *= 2;
                } else {
                    jsonElem->children->realLength = 50;
                }
                void * newPtr = memoryRealloc(jsonElem->children->data, (jsonElem->children->realLength)*sizeof(struct jsonElement*));
                jsonElem->children->data = newPtr;
            }
            jsonElem->children->data[elemIndex] = elem;
            jsonElem->children->length = nLength+1;
        } else {
            jsonElem->children->data[elemIndex] = elem;
        }
    }
    ;
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
        unsigned long nLength = len(currentElem);
        if (nLength >= currentElem->length) {
            if (nLength >= currentElem->realLength) {
                if (currentElem->realLength != 0) {
                    currentElem->realLength *= 2;
                } else {
                    currentElem->realLength = 50;
                }
                void * newPtr = memoryRealloc(currentElem->data, (currentElem->realLength)*sizeof(char));
                currentElem->data = newPtr;
            }
            currentElem->data[len(currentElem)] = c;
            currentElem->length = nLength+1;
        } else {
            currentElem->data[len(currentElem)] = c;
        }
    }
    ;
}
else {

    {
        unsigned long nLength = len(currentKey);
        if (nLength >= currentKey->length) {
            if (nLength >= currentKey->realLength) {
                if (currentKey->realLength != 0) {
                    currentKey->realLength *= 2;
                } else {
                    currentKey->realLength = 50;
                }
                void * newPtr = memoryRealloc(currentKey->data, (currentKey->realLength)*sizeof(char));
                currentKey->data = newPtr;
            }
            currentKey->data[len(currentKey)] = c;
            currentKey->length = nLength+1;
        } else {
            currentKey->data[len(currentKey)] = c;
        }
    }
    ;
}
}
i = i+1;
};
char * ____BAH_COMPILER_VAR_86 =arrToStr(currentElem);struct jsonElement* elem = parseJson(____BAH_COMPILER_VAR_86);
if ((elem!=null)) {
elem->key = arrToStr(currentKey);

    {
        unsigned long nLength = elemIndex;
        if (nLength >= jsonElem->children->length) {
            if (nLength >= jsonElem->children->realLength) {
                if (jsonElem->children->realLength != 0) {
                    jsonElem->children->realLength *= 2;
                } else {
                    jsonElem->children->realLength = 50;
                }
                void * newPtr = memoryRealloc(jsonElem->children->data, (jsonElem->children->realLength)*sizeof(struct jsonElement*));
                jsonElem->children->data = newPtr;
            }
            jsonElem->children->data[elemIndex] = elem;
            jsonElem->children->length = nLength+1;
        } else {
            jsonElem->children->data[elemIndex] = elem;
        }
    }
    ;
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

    {
        unsigned long nLength = len(r);
        if (nLength >= r->length) {
            if (nLength >= r->realLength) {
                if (r->realLength != 0) {
                    r->realLength *= 2;
                } else {
                    r->realLength = 50;
                }
                void * newPtr = memoryRealloc(r->data, (r->realLength)*sizeof(char));
                r->data = newPtr;
            }
            r->data[len(r)] = (char)92;
            r->length = nLength+1;
        } else {
            r->data[len(r)] = (char)92;
        }
    }
    ;
}
else if ((c==(char)10)) {

    {
        unsigned long nLength = len(r);
        if (nLength >= r->length) {
            if (nLength >= r->realLength) {
                if (r->realLength != 0) {
                    r->realLength *= 2;
                } else {
                    r->realLength = 50;
                }
                void * newPtr = memoryRealloc(r->data, (r->realLength)*sizeof(char));
                r->data = newPtr;
            }
            r->data[len(r)] = (char)92;
            r->length = nLength+1;
        } else {
            r->data[len(r)] = (char)92;
        }
    }
    ;

    {
        unsigned long nLength = len(r);
        if (nLength >= r->length) {
            if (nLength >= r->realLength) {
                if (r->realLength != 0) {
                    r->realLength *= 2;
                } else {
                    r->realLength = 50;
                }
                void * newPtr = memoryRealloc(r->data, (r->realLength)*sizeof(char));
                r->data = newPtr;
            }
            r->data[len(r)] = 110;
            r->length = nLength+1;
        } else {
            r->data[len(r)] = 110;
        }
    }
    ;
i = i+1;
continue;
}
else if ((c==(char)13)) {

    {
        unsigned long nLength = len(r);
        if (nLength >= r->length) {
            if (nLength >= r->realLength) {
                if (r->realLength != 0) {
                    r->realLength *= 2;
                } else {
                    r->realLength = 50;
                }
                void * newPtr = memoryRealloc(r->data, (r->realLength)*sizeof(char));
                r->data = newPtr;
            }
            r->data[len(r)] = (char)92;
            r->length = nLength+1;
        } else {
            r->data[len(r)] = (char)92;
        }
    }
    ;

    {
        unsigned long nLength = len(r);
        if (nLength >= r->length) {
            if (nLength >= r->realLength) {
                if (r->realLength != 0) {
                    r->realLength *= 2;
                } else {
                    r->realLength = 50;
                }
                void * newPtr = memoryRealloc(r->data, (r->realLength)*sizeof(char));
                r->data = newPtr;
            }
            r->data[len(r)] = 114;
            r->length = nLength+1;
        } else {
            r->data[len(r)] = 114;
        }
    }
    ;
i = i+1;
continue;
}

    {
        unsigned long nLength = len(r);
        if (nLength >= r->length) {
            if (nLength >= r->realLength) {
                if (r->realLength != 0) {
                    r->realLength *= 2;
                } else {
                    r->realLength = 50;
                }
                void * newPtr = memoryRealloc(r->data, (r->realLength)*sizeof(char));
                r->data = newPtr;
            }
            r->data[len(r)] = c;
            r->length = nLength+1;
        } else {
            r->data[len(r)] = c;
        }
    }
    ;
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
char * ____BAH_COMPILER_VAR_87 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tabsStr);
unsigned int strLen_1 = strlen("\t");
;                            
            ____BAH_COMPILER_VAR_87 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_87+currStrOff, tabsStr, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_87+currStrOff, "\t", strLen_1);
            currStrOff += strLen_1;
        
        }tabsStr = ____BAH_COMPILER_VAR_87;
i = i+1;
};
char * s = "{\n";
i = 0;
while ((i<len(e.structLayout))) {
struct reflectElement m = e.structLayout->data[i];
i = i+1;
if ((i<len(e.structLayout))) {
char * ____BAH_COMPILER_VAR_88 =null;char * ____BAH_COMPILER_VAR_89 =toJson__inner(m,true,tabs);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_89);
unsigned int strLen_1 = strlen(",\n");
unsigned int strLen_2 = strlen("\": ");
unsigned int strLen_3 = strlen(m.name);
unsigned int strLen_4 = strlen("\"");
unsigned int strLen_5 = strlen(tabsStr);
unsigned int strLen_6 = strlen(s);
;                            
            ____BAH_COMPILER_VAR_88 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_88+currStrOff, s, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_88+currStrOff, tabsStr, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_88+currStrOff, "\"", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_88+currStrOff, m.name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_88+currStrOff, "\": ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_88+currStrOff, ____BAH_COMPILER_VAR_89, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_88+currStrOff, ",\n", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_88;
}
else {
char * ____BAH_COMPILER_VAR_90 =null;char * ____BAH_COMPILER_VAR_91 =toJson__inner(m,true,tabs);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_91);
unsigned int strLen_1 = strlen("\n");
unsigned int strLen_2 = strlen("\": ");
unsigned int strLen_3 = strlen(m.name);
unsigned int strLen_4 = strlen("\"");
unsigned int strLen_5 = strlen(tabsStr);
unsigned int strLen_6 = strlen(s);
;                            
            ____BAH_COMPILER_VAR_90 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_90+currStrOff, s, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_90+currStrOff, tabsStr, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_90+currStrOff, "\"", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_90+currStrOff, m.name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_90+currStrOff, "\": ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_90+currStrOff, ____BAH_COMPILER_VAR_91, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_90+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_90;
}
};
tabs = tabs-1;
tabsStr = "";
i = 0;
while ((i<tabs)) {
char * ____BAH_COMPILER_VAR_92 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tabsStr);
unsigned int strLen_1 = strlen("\t");
;                            
            ____BAH_COMPILER_VAR_92 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_92+currStrOff, tabsStr, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_92+currStrOff, "\t", strLen_1);
            currStrOff += strLen_1;
        
        }tabsStr = ____BAH_COMPILER_VAR_92;
i = i+1;
};
char * ____BAH_COMPILER_VAR_93 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tabsStr);
unsigned int strLen_1 = strlen("}");
unsigned int strLen_2 = strlen(s);
;                            
            ____BAH_COMPILER_VAR_93 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_93+currStrOff, s, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_93+currStrOff, tabsStr, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_93+currStrOff, "}", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_93;
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
char * ____BAH_COMPILER_VAR_94 =null;char * ____BAH_COMPILER_VAR_95 =jsonEscapeStr(s);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_95);
unsigned int strLen_1 = strlen("\"");
unsigned int strLen_2 = strlen("\"");
;                            
            ____BAH_COMPILER_VAR_94 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_94+currStrOff, "\"", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_94+currStrOff, ____BAH_COMPILER_VAR_95, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_94+currStrOff, "\"", strLen_1);
            currStrOff += strLen_1;
        
        }return ____BAH_COMPILER_VAR_94;
}
else {
char ** sp = e.value;
char * s = *sp;
char * ____BAH_COMPILER_VAR_96 =null;char * ____BAH_COMPILER_VAR_97 =jsonEscapeStr(s);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_97);
unsigned int strLen_1 = strlen("\"");
unsigned int strLen_2 = strlen("\"");
;                            
            ____BAH_COMPILER_VAR_96 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_96+currStrOff, "\"", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_96+currStrOff, ____BAH_COMPILER_VAR_97, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_96+currStrOff, "\"", strLen_1);
            currStrOff += strLen_1;
        
        }return ____BAH_COMPILER_VAR_96;
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
char * ____BAH_COMPILER_VAR_98 =null;char * ____BAH_COMPILER_VAR_99 =intToStr(arr->data[i]);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_99);
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
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s);
unsigned int strLen_1 = strlen(",");
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
else if ((strcmp(ae->type, "float") == 0)) {
array(double)* arr = memoryAlloc(sizeof(array(double)));

arr->length = 0;
arr->elemSize = sizeof(double);
void ** arrPtr = e.value;
arr = *arrPtr;
register long int i = 0;
while ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_101 =null;char * ____BAH_COMPILER_VAR_102 =floatToStr(arr->data[i]);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_102);
;                            
            ____BAH_COMPILER_VAR_101 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_101+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_101+currStrOff, ____BAH_COMPILER_VAR_102, strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_101;
i = i+1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_103 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s);
unsigned int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_103 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_103+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_103+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_103;
}
};
}
else if ((strcmp(ae->type, "cpstring") == 0)) {
array(char *)* arr = memoryAlloc(sizeof(array(char *)));

arr->length = 0;
arr->elemSize = sizeof(char *);
void ** arrPtr = e.value;
arr = *arrPtr;
char * ____BAH_COMPILER_VAR_104 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s);
unsigned int strLen_1 = strlen("\n");
;                            
            ____BAH_COMPILER_VAR_104 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_104+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_104+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_104;
register long int i = 0;
while ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_105 =null;char * ____BAH_COMPILER_VAR_106 =jsonEscapeStr(arr->data[i]);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_106);
unsigned int strLen_1 = strlen("\"");
unsigned int strLen_2 = strlen("\"");
unsigned int strLen_3 = strlen(s);
;                            
            ____BAH_COMPILER_VAR_105 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_105+currStrOff, s, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_105+currStrOff, "\"", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_105+currStrOff, ____BAH_COMPILER_VAR_106, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_105+currStrOff, "\"", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_105;
i = i+1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_107 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s);
unsigned int strLen_1 = strlen(",\n");
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
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s);
unsigned int strLen_1 = strlen("\n");
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

    {
        unsigned long nLength = j;
        if (nLength >= ae->structLayout->length) {
            if (nLength >= ae->structLayout->realLength) {
                if (ae->structLayout->realLength != 0) {
                    ae->structLayout->realLength *= 2;
                } else {
                    ae->structLayout->realLength = 50;
                }
                void * newPtr = memoryRealloc(ae->structLayout->data, (ae->structLayout->realLength)*sizeof(struct reflectElement));
                ae->structLayout->data = newPtr;
            }
            ae->structLayout->data[j] = m;
            ae->structLayout->length = nLength+1;
        } else {
            ae->structLayout->data[j] = m;
        }
    }
    ;
j = j+1;
};
char * ____BAH_COMPILER_VAR_109 =null;char * ____BAH_COMPILER_VAR_110 =toJson__inner(*ae,false,tabs);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_110);
;                            
            ____BAH_COMPILER_VAR_109 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_109+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_109+currStrOff, ____BAH_COMPILER_VAR_110, strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_109;
i = i+1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_111 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s);
unsigned int strLen_1 = strlen(",\n");
;                            
            ____BAH_COMPILER_VAR_111 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_111+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_111+currStrOff, ",\n", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_111;
}
else {
char * ____BAH_COMPILER_VAR_112 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s);
unsigned int strLen_1 = strlen("\n");
;                            
            ____BAH_COMPILER_VAR_112 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_112+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_112+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_112;
}
};
}
char * ____BAH_COMPILER_VAR_113 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s);
unsigned int strLen_1 = strlen("]");
;                            
            ____BAH_COMPILER_VAR_113 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_113+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_113+currStrOff, "]", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_113;
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
char * ____BAH_COMPILER_VAR_114 = name;
struct reflectElement ____BAH_COMPILER_VAR_115 = __reflect(____BAH_COMPILER_VAR_114, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, 0);
char * ____BAH_COMPILER_VAR_116 =null;char * ____BAH_COMPILER_VAR_117 =toJson(e);char * ____BAH_COMPILER_VAR_118 =intToStr(line);char * ____BAH_COMPILER_VAR_119 =toJson(____BAH_COMPILER_VAR_115);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_117);
unsigned int strLen_1 = strlen("\n    },\n    ");
unsigned int strLen_2 = strlen("\",\n        \"element\": ");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_118);
unsigned int strLen_4 = strlen(":");
unsigned int strLen_5 = strlen(compilerState.currentFile);
unsigned int strLen_6 = strlen(",\n        \"path\": \"");
unsigned int strLen_7 = strlen(____BAH_COMPILER_VAR_119);
unsigned int strLen_8 = strlen("\n    {\n        \"name\": ");
;                            
            ____BAH_COMPILER_VAR_116 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_116+currStrOff, "\n    {\n        \"name\": ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_116+currStrOff, ____BAH_COMPILER_VAR_119, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_116+currStrOff, ",\n        \"path\": \"", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_116+currStrOff, compilerState.currentFile, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_116+currStrOff, ":", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_116+currStrOff, ____BAH_COMPILER_VAR_118, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_116+currStrOff, "\",\n        \"element\": ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_116+currStrOff, ____BAH_COMPILER_VAR_117, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_116+currStrOff, "\n    },\n    ", strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_116);
};
void debugError(char * name,long int line,long int from,long int to,struct reflectElement e){
if ((debug==false)) {
return;
}
char * ____BAH_COMPILER_VAR_120 = name;
struct reflectElement ____BAH_COMPILER_VAR_121 = __reflect(____BAH_COMPILER_VAR_120, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, 0);
char * ____BAH_COMPILER_VAR_122 =null;char * ____BAH_COMPILER_VAR_123 =toJson(e);char * ____BAH_COMPILER_VAR_124 =intToStr(to);char * ____BAH_COMPILER_VAR_125 =intToStr(from);char * ____BAH_COMPILER_VAR_126 =intToStr(line);char * ____BAH_COMPILER_VAR_127 =toJson(____BAH_COMPILER_VAR_121);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_123);
unsigned int strLen_1 = strlen("\n    },\n    ");
unsigned int strLen_2 = strlen("\n        ],\n        \"element\": ");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_124);
unsigned int strLen_4 = strlen(",\n            ");
unsigned int strLen_5 = strlen(____BAH_COMPILER_VAR_125);
unsigned int strLen_6 = strlen("\",\n        \"range\": [\n            ");
unsigned int strLen_7 = strlen(____BAH_COMPILER_VAR_126);
unsigned int strLen_8 = strlen(":");
unsigned int strLen_9 = strlen(compilerState.currentFile);
unsigned int strLen_10 = strlen(",\n        \"path\": \"");
unsigned int strLen_11 = strlen(____BAH_COMPILER_VAR_127);
unsigned int strLen_12 = strlen("\n    {\n        \"name\": ");
;                            
            ____BAH_COMPILER_VAR_122 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12);
            
                    memcpy(____BAH_COMPILER_VAR_122+currStrOff, "\n    {\n        \"name\": ", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_122+currStrOff, ____BAH_COMPILER_VAR_127, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_122+currStrOff, ",\n        \"path\": \"", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_122+currStrOff, compilerState.currentFile, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_122+currStrOff, ":", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_122+currStrOff, ____BAH_COMPILER_VAR_126, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_122+currStrOff, "\",\n        \"range\": [\n            ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_122+currStrOff, ____BAH_COMPILER_VAR_125, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_122+currStrOff, ",\n            ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_122+currStrOff, ____BAH_COMPILER_VAR_124, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_122+currStrOff, "\n        ],\n        \"element\": ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_122+currStrOff, ____BAH_COMPILER_VAR_123, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_122+currStrOff, "\n    },\n    ", strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_122);
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
struct variable* ____BAH_COMPILER_VAR_128 = v;
char ** ____BAH_COMPILER_VAR_130 = (char **)((char*)(____BAH_COMPILER_VAR_128) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_131 = __reflect(____BAH_COMPILER_VAR_130, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_132 = (char **)((char*)(____BAH_COMPILER_VAR_128) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_133 = __reflect(____BAH_COMPILER_VAR_132, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_134 = (char*)((char*)(____BAH_COMPILER_VAR_128) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_135 = __reflect(____BAH_COMPILER_VAR_134, sizeof(char), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_136 = (char **)((char*)(____BAH_COMPILER_VAR_128) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_137 = __reflect(____BAH_COMPILER_VAR_136, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_138 = (char*)((char*)(____BAH_COMPILER_VAR_128) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_139 = __reflect(____BAH_COMPILER_VAR_138, sizeof(char), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_140 = (char **)((char*)(____BAH_COMPILER_VAR_128) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_141 = __reflect(____BAH_COMPILER_VAR_140, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
void ** ____BAH_COMPILER_VAR_142 = (void **)((char*)(____BAH_COMPILER_VAR_128) + offsetof(struct variable, declScope));
struct reflectElement ____BAH_COMPILER_VAR_143 = __reflect(____BAH_COMPILER_VAR_142, sizeof(void *), "ptr", "declScope", 0, 0, 0, 0, offsetof(struct variable, declScope));
char* ____BAH_COMPILER_VAR_144 = (char*)((char*)(____BAH_COMPILER_VAR_128) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_145 = __reflect(____BAH_COMPILER_VAR_144, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));
struct rope** ____BAH_COMPILER_VAR_146 = (struct rope**)((char*)(____BAH_COMPILER_VAR_128) + offsetof(struct variable, declRope));
void ** ____BAH_COMPILER_VAR_148 = (void **)((char*)(____BAH_COMPILER_VAR_146) + offsetof(struct rope, left));
struct reflectElement ____BAH_COMPILER_VAR_149 = __reflect(____BAH_COMPILER_VAR_148, sizeof(void *), "ptr", "left", 0, 0, 0, 0, offsetof(struct rope, left));
void ** ____BAH_COMPILER_VAR_150 = (void **)((char*)(____BAH_COMPILER_VAR_146) + offsetof(struct rope, right));
struct reflectElement ____BAH_COMPILER_VAR_151 = __reflect(____BAH_COMPILER_VAR_150, sizeof(void *), "ptr", "right", 0, 0, 0, 0, offsetof(struct rope, right));
char ** ____BAH_COMPILER_VAR_152 = (char **)((char*)(____BAH_COMPILER_VAR_146) + offsetof(struct rope, str));
struct reflectElement ____BAH_COMPILER_VAR_153 = __reflect(____BAH_COMPILER_VAR_152, sizeof(char *), "cpstring", "str", 0, 0, 0, 0, offsetof(struct rope, str));
int* ____BAH_COMPILER_VAR_154 = (int*)((char*)(____BAH_COMPILER_VAR_146) + offsetof(struct rope, lCount));
struct reflectElement ____BAH_COMPILER_VAR_155 = __reflect(____BAH_COMPILER_VAR_154, sizeof(int), "int32", "lCount", 0, 0, 0, 0, offsetof(struct rope, lCount));
int* ____BAH_COMPILER_VAR_156 = (int*)((char*)(____BAH_COMPILER_VAR_146) + offsetof(struct rope, len));
struct reflectElement ____BAH_COMPILER_VAR_157 = __reflect(____BAH_COMPILER_VAR_156, sizeof(int), "int32", "len", 0, 0, 0, 0, offsetof(struct rope, len));
int* ____BAH_COMPILER_VAR_158 = (int*)((char*)(____BAH_COMPILER_VAR_146) + offsetof(struct rope, totalLen));
struct reflectElement ____BAH_COMPILER_VAR_159 = __reflect(____BAH_COMPILER_VAR_158, sizeof(int), "int32", "totalLen", 0, 0, 0, 0, offsetof(struct rope, totalLen));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_147 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_147->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_147->length = 6;
        ____BAH_COMPILER_VAR_147->data = memoryAlloc(____BAH_COMPILER_VAR_147->length * ____BAH_COMPILER_VAR_147->elemSize);
        ____BAH_COMPILER_VAR_147->data[0] = ____BAH_COMPILER_VAR_149;
____BAH_COMPILER_VAR_147->data[1] = ____BAH_COMPILER_VAR_151;
____BAH_COMPILER_VAR_147->data[2] = ____BAH_COMPILER_VAR_153;
____BAH_COMPILER_VAR_147->data[3] = ____BAH_COMPILER_VAR_155;
____BAH_COMPILER_VAR_147->data[4] = ____BAH_COMPILER_VAR_157;
____BAH_COMPILER_VAR_147->data[5] = ____BAH_COMPILER_VAR_159;
struct reflectElement ____BAH_COMPILER_VAR_160 = __reflect(____BAH_COMPILER_VAR_146, sizeof(struct rope), "rope*", "declRope", 0, 0, 1, ____BAH_COMPILER_VAR_147, offsetof(struct variable, declRope));
char* ____BAH_COMPILER_VAR_161 = (char*)((char*)(____BAH_COMPILER_VAR_128) + offsetof(struct variable, canBeNull));
struct reflectElement ____BAH_COMPILER_VAR_162 = __reflect(____BAH_COMPILER_VAR_161, sizeof(char), "bool", "canBeNull", 0, 0, 0, 0, offsetof(struct variable, canBeNull));
char* ____BAH_COMPILER_VAR_163 = (char*)((char*)(____BAH_COMPILER_VAR_128) + offsetof(struct variable, canBeReg));
struct reflectElement ____BAH_COMPILER_VAR_164 = __reflect(____BAH_COMPILER_VAR_163, sizeof(char), "bool", "canBeReg", 0, 0, 0, 0, offsetof(struct variable, canBeReg));
char* ____BAH_COMPILER_VAR_165 = (char*)((char*)(____BAH_COMPILER_VAR_128) + offsetof(struct variable, isReg));
struct reflectElement ____BAH_COMPILER_VAR_166 = __reflect(____BAH_COMPILER_VAR_165, sizeof(char), "bool", "isReg", 0, 0, 0, 0, offsetof(struct variable, isReg));
void ** ____BAH_COMPILER_VAR_167 = (void **)((char*)(____BAH_COMPILER_VAR_128) + offsetof(struct variable, lastSet));
struct reflectElement ____BAH_COMPILER_VAR_168 = __reflect(____BAH_COMPILER_VAR_167, sizeof(void *), "ptr", "lastSet", 0, 0, 0, 0, offsetof(struct variable, lastSet));
char* ____BAH_COMPILER_VAR_169 = (char*)((char*)(____BAH_COMPILER_VAR_128) + offsetof(struct variable, isArg));
struct reflectElement ____BAH_COMPILER_VAR_170 = __reflect(____BAH_COMPILER_VAR_169, sizeof(char), "bool", "isArg", 0, 0, 0, 0, offsetof(struct variable, isArg));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_129 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_129->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_129->length = 14;
        ____BAH_COMPILER_VAR_129->data = memoryAlloc(____BAH_COMPILER_VAR_129->length * ____BAH_COMPILER_VAR_129->elemSize);
        ____BAH_COMPILER_VAR_129->data[0] = ____BAH_COMPILER_VAR_131;
____BAH_COMPILER_VAR_129->data[1] = ____BAH_COMPILER_VAR_133;
____BAH_COMPILER_VAR_129->data[2] = ____BAH_COMPILER_VAR_135;
____BAH_COMPILER_VAR_129->data[3] = ____BAH_COMPILER_VAR_137;
____BAH_COMPILER_VAR_129->data[4] = ____BAH_COMPILER_VAR_139;
____BAH_COMPILER_VAR_129->data[5] = ____BAH_COMPILER_VAR_141;
____BAH_COMPILER_VAR_129->data[6] = ____BAH_COMPILER_VAR_143;
____BAH_COMPILER_VAR_129->data[7] = ____BAH_COMPILER_VAR_145;
____BAH_COMPILER_VAR_129->data[8] = ____BAH_COMPILER_VAR_160;
____BAH_COMPILER_VAR_129->data[9] = ____BAH_COMPILER_VAR_162;
____BAH_COMPILER_VAR_129->data[10] = ____BAH_COMPILER_VAR_164;
____BAH_COMPILER_VAR_129->data[11] = ____BAH_COMPILER_VAR_166;
____BAH_COMPILER_VAR_129->data[12] = ____BAH_COMPILER_VAR_168;
____BAH_COMPILER_VAR_129->data[13] = ____BAH_COMPILER_VAR_170;
struct reflectElement ____BAH_COMPILER_VAR_171 = __reflect(____BAH_COMPILER_VAR_128, sizeof(struct variable), "variable*", "v", 0, 0, 1, ____BAH_COMPILER_VAR_129, 0);
debugPrint("var_end",line,____BAH_COMPILER_VAR_171);
}
i = i+1;
};
};
void throwErr(void * tp,char * format){
char * str = "";
char * info = "";
long int pos = 0;
if ((tp!=null)) {
struct fileMap ____BAH_COMPILER_VAR_172 = {};
____BAH_COMPILER_VAR_172.handle = -1;
____BAH_COMPILER_VAR_172.p= null;
#define fm ____BAH_COMPILER_VAR_172
char * fileSrcStr = fileMap__open(&fm,compilerState.currentFile);
struct Tok* t = tp;
struct string ffmt = string(format);
if ((strlen(t->ogCont)==0)) {
t->ogCont = t->cont;
}
char * ____BAH_COMPILER_VAR_173 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t->ogCont);
unsigned int strLen_1 = strlen("'");
unsigned int strLen_2 = strlen("'");
;                            
            ____BAH_COMPILER_VAR_173 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_173+currStrOff, "'", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_173+currStrOff, t->ogCont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_173+currStrOff, "'", strLen_1);
            currStrOff += strLen_1;
        
        }string__replace(&ffmt,"{TOKEN}",____BAH_COMPILER_VAR_173);
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

    {
        unsigned long nLength = len(errCont);
        if (nLength >= errCont->length) {
            if (nLength >= errCont->realLength) {
                if (errCont->realLength != 0) {
                    errCont->realLength *= 2;
                } else {
                    errCont->realLength = 50;
                }
                void * newPtr = memoryRealloc(errCont->data, (errCont->realLength)*sizeof(char));
                errCont->data = newPtr;
            }
            errCont->data[len(errCont)] = fileSrcStr[i];
            errCont->length = nLength+1;
        } else {
            errCont->data[len(errCont)] = fileSrcStr[i];
        }
    }
    ;
};
char * ____BAH_COMPILER_VAR_174 =null;char * ____BAH_COMPILER_VAR_175 =arrToStr(errCont);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_175);
unsigned int strLen_1 = strlen("\e[1;37m");
unsigned int strLen_2 = strlen("\e[1;31m");
;                            
            ____BAH_COMPILER_VAR_174 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_174+currStrOff, "\e[1;31m", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_174+currStrOff, ____BAH_COMPILER_VAR_175, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_174+currStrOff, "\e[1;37m", strLen_1);
            currStrOff += strLen_1;
        
        }array(char)* errTk = strToArr(____BAH_COMPILER_VAR_174);
register long int ii = 0;
for (; (ii<len(errTk)); ++ii) {

    {
        unsigned long nLength = len(line);
        if (nLength >= line->length) {
            if (nLength >= line->realLength) {
                if (line->realLength != 0) {
                    line->realLength *= 2;
                } else {
                    line->realLength = 50;
                }
                void * newPtr = memoryRealloc(line->data, (line->realLength)*sizeof(char));
                line->data = newPtr;
            }
            line->data[len(line)] = errTk->data[ii];
            line->length = nLength+1;
        } else {
            line->data[len(line)] = errTk->data[ii];
        }
    }
    ;
};
--i;
continue;
}

    {
        unsigned long nLength = len(line);
        if (nLength >= line->length) {
            if (nLength >= line->realLength) {
                if (line->realLength != 0) {
                    line->realLength *= 2;
                } else {
                    line->realLength = 50;
                }
                void * newPtr = memoryRealloc(line->data, (line->realLength)*sizeof(char));
                line->data = newPtr;
            }
            line->data[len(line)] = c;
            line->length = nLength+1;
        } else {
            line->data[len(line)] = c;
        }
    }
    ;
};
fileMap__close(&fm);
str = arrToStr(line);
char * ____BAH_COMPILER_VAR_176 =null;char * ____BAH_COMPILER_VAR_177 =intToStr(pos);char * ____BAH_COMPILER_VAR_178 =intToStr(t->line);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(":");
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_177);
unsigned int strLen_2 = strlen(____BAH_COMPILER_VAR_178);
;                            
            ____BAH_COMPILER_VAR_176 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_176+currStrOff, ____BAH_COMPILER_VAR_178, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_176+currStrOff, ":", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_176+currStrOff, ____BAH_COMPILER_VAR_177, strLen_1);
            currStrOff += strLen_1;
        
        }info = ____BAH_COMPILER_VAR_176;

#undef fm
}
if ((debug==true)) {
struct Tok* t = tp;
char * ____BAH_COMPILER_VAR_179 = format;
struct reflectElement ____BAH_COMPILER_VAR_180 = __reflect(____BAH_COMPILER_VAR_179, sizeof(char *), "cpstring", "format", 0, 0, 0, 0, 0);
debugError("error",t->line,pos,pos+strlen(t->ogCont),____BAH_COMPILER_VAR_180);
debugExit();
}
else {
char * ____BAH_COMPILER_VAR_181 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("\e[0m\n");
unsigned int strLen_1 = strlen(format);
unsigned int strLen_2 = strlen(str);
unsigned int strLen_3 = strlen("\n\e[1;37m\t");
unsigned int strLen_4 = strlen(info);
unsigned int strLen_5 = strlen(":");
unsigned int strLen_6 = strlen(compilerState.currentFile);
unsigned int strLen_7 = strlen("\e[1;31m[ERROR]\e[0m ");
;                            
            ____BAH_COMPILER_VAR_181 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7);
            
                    memcpy(____BAH_COMPILER_VAR_181+currStrOff, "\e[1;31m[ERROR]\e[0m ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_181+currStrOff, compilerState.currentFile, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_181+currStrOff, ":", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_181+currStrOff, info, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_181+currStrOff, "\n\e[1;37m\t", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_181+currStrOff, str, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_181+currStrOff, "\e[0m\n", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_181+currStrOff, format, strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_181);
}
exit(1);
};
void throwWarning(char * s){
char * ____BAH_COMPILER_VAR_182 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s);
unsigned int strLen_1 = strlen("\e[0m");
unsigned int strLen_2 = strlen("\n\e[0m\t");
unsigned int strLen_3 = strlen(compilerState.currentFile);
unsigned int strLen_4 = strlen("\e[1;33m[WARNING]\e[0m ");
;                            
            ____BAH_COMPILER_VAR_182 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_182+currStrOff, "\e[1;33m[WARNING]\e[0m ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_182+currStrOff, compilerState.currentFile, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_182+currStrOff, "\n\e[0m\t", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_182+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_182+currStrOff, "\e[0m", strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_182);
};
void throwWarningLine(char * s,long int l){
char * ____BAH_COMPILER_VAR_183 =null;char * ____BAH_COMPILER_VAR_184 =intToStr(l);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s);
unsigned int strLen_1 = strlen("\e[0m");
unsigned int strLen_2 = strlen("\n\e[0m\t");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_184);
unsigned int strLen_4 = strlen(":");
unsigned int strLen_5 = strlen(compilerState.currentFile);
unsigned int strLen_6 = strlen("\e[1;33m[WARNING]\e[0m ");
;                            
            ____BAH_COMPILER_VAR_183 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_183+currStrOff, "\e[1;33m[WARNING]\e[0m ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_183+currStrOff, compilerState.currentFile, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_183+currStrOff, ":", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_183+currStrOff, ____BAH_COMPILER_VAR_184, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_183+currStrOff, "\n\e[0m\t", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_183+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_183+currStrOff, "\e[0m", strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_183);
};
void throwNoticeLine(char * s,long int l){
if ((noticeEnabled==false)) {
return;
}
char * ____BAH_COMPILER_VAR_185 =null;char * ____BAH_COMPILER_VAR_186 =intToStr(l);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s);
unsigned int strLen_1 = strlen("\e[0m");
unsigned int strLen_2 = strlen("\n\e[0m\t");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_186);
unsigned int strLen_4 = strlen(":");
unsigned int strLen_5 = strlen(compilerState.currentFile);
unsigned int strLen_6 = strlen("\e[1;36m[NOTICE]\e[0m ");
;                            
            ____BAH_COMPILER_VAR_185 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_185+currStrOff, "\e[1;36m[NOTICE]\e[0m ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_185+currStrOff, compilerState.currentFile, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_185+currStrOff, ":", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_185+currStrOff, ____BAH_COMPILER_VAR_186, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_185+currStrOff, "\n\e[0m\t", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_185+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_185+currStrOff, "\e[0m", strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_185);
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

    {
        unsigned long nLength = i;
        if (nLength >= arr->length) {
            if (nLength >= arr->realLength) {
                if (arr->realLength != 0) {
                    arr->realLength *= 2;
                } else {
                    arr->realLength = 50;
                }
                void * newPtr = memoryRealloc(arr->data, (arr->realLength)*sizeof(char));
                arr->data = newPtr;
            }
            arr->data[i] = 47;
            arr->length = nLength+1;
        } else {
            arr->data[i] = 47;
        }
    }
    ;
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
else {
string__set(&vt,"char");
}
char * vtstr = string__str(&vt);
struct variable* ____BAH_COMPILER_VAR_187 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_187->name = "";
____BAH_COMPILER_VAR_187->type = "";
____BAH_COMPILER_VAR_187->isConst = false;
____BAH_COMPILER_VAR_187->constVal = "";
____BAH_COMPILER_VAR_187->isArray = false;
____BAH_COMPILER_VAR_187->from = "";
____BAH_COMPILER_VAR_187->declScope= null;
____BAH_COMPILER_VAR_187->isGlobal = false;
____BAH_COMPILER_VAR_187->declRope= null;
____BAH_COMPILER_VAR_187->canBeNull = false;
____BAH_COMPILER_VAR_187->isReg = false;
____BAH_COMPILER_VAR_187->lastSet= null;
____BAH_COMPILER_VAR_187->isArg = false;
struct variable* nv = ____BAH_COMPILER_VAR_187;
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
struct variable* ____BAH_COMPILER_VAR_188 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_188->name = "";
____BAH_COMPILER_VAR_188->type = "";
____BAH_COMPILER_VAR_188->isConst = false;
____BAH_COMPILER_VAR_188->constVal = "";
____BAH_COMPILER_VAR_188->isArray = false;
____BAH_COMPILER_VAR_188->from = "";
____BAH_COMPILER_VAR_188->declScope= null;
____BAH_COMPILER_VAR_188->isGlobal = false;
____BAH_COMPILER_VAR_188->declRope= null;
____BAH_COMPILER_VAR_188->canBeNull = false;
____BAH_COMPILER_VAR_188->isReg = false;
____BAH_COMPILER_VAR_188->lastSet= null;
____BAH_COMPILER_VAR_188->isArg = false;
struct variable* nv = ____BAH_COMPILER_VAR_188;
nv->from = memb->from;
nv->name = memb->name;
nv->type = memb->type;
nv->declScope = v->declScope;
nv->name = ogName;
char * r = nv->type;
struct string tcc = string(ogName);
if (string__count(&tcc,"&")) {
char * ____BAH_COMPILER_VAR_189 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(r);
unsigned int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_189 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_189+currStrOff, r, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_189+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }r = ____BAH_COMPILER_VAR_189;
}
long int nbUnaries = string__count(&tcc,"*");
if ((nbUnaries>0)) {
struct string ct = string(r);
long int pointerLevel = string__count(&ct,"*");
if ((pointerLevel<nbUnaries)) {
char * ____BAH_COMPILER_VAR_190 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nv->name);
unsigned int strLen_1 = strlen(" because it is not pointer.");
unsigned int strLen_2 = strlen("Cannot use '*' on ");
;                            
            ____BAH_COMPILER_VAR_190 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_190+currStrOff, "Cannot use '*' on ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_190+currStrOff, nv->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_190+currStrOff, " because it is not pointer.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(null,____BAH_COMPILER_VAR_190);
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
struct variable* ____BAH_COMPILER_VAR_191 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_191->name = "";
____BAH_COMPILER_VAR_191->type = "";
____BAH_COMPILER_VAR_191->isConst = false;
____BAH_COMPILER_VAR_191->constVal = "";
____BAH_COMPILER_VAR_191->isArray = false;
____BAH_COMPILER_VAR_191->from = "";
____BAH_COMPILER_VAR_191->declScope= null;
____BAH_COMPILER_VAR_191->isGlobal = false;
____BAH_COMPILER_VAR_191->declRope= null;
____BAH_COMPILER_VAR_191->canBeNull = false;
____BAH_COMPILER_VAR_191->isReg = false;
____BAH_COMPILER_VAR_191->lastSet= null;
____BAH_COMPILER_VAR_191->isArg = false;
struct variable* nv = ____BAH_COMPILER_VAR_191;
*nv = *v;
char * r = nv->type;
struct string tcc = string(ogName);
if (string__count(&tcc,"&")) {
char * ____BAH_COMPILER_VAR_192 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(r);
unsigned int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_192 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_192+currStrOff, r, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_192+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }r = ____BAH_COMPILER_VAR_192;
}
long int nbUnaries = string__count(&tcc,"*");
if ((nbUnaries>0)) {
struct string ct = string(r);
long int pointerLevel = string__count(&ct,"*");
if ((pointerLevel<nbUnaries)) {
char * ____BAH_COMPILER_VAR_193 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(v->name);
unsigned int strLen_1 = strlen(" because it is not pointer.");
unsigned int strLen_2 = strlen("Cannot use '*' on ");
;                            
            ____BAH_COMPILER_VAR_193 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_193+currStrOff, "Cannot use '*' on ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_193+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_193+currStrOff, " because it is not pointer.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(null,____BAH_COMPILER_VAR_193);
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
struct variable* ____BAH_COMPILER_VAR_194 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_194->name = "";
____BAH_COMPILER_VAR_194->type = "";
____BAH_COMPILER_VAR_194->isConst = false;
____BAH_COMPILER_VAR_194->constVal = "";
____BAH_COMPILER_VAR_194->isArray = false;
____BAH_COMPILER_VAR_194->from = "";
____BAH_COMPILER_VAR_194->declScope= null;
____BAH_COMPILER_VAR_194->isGlobal = false;
____BAH_COMPILER_VAR_194->declRope= null;
____BAH_COMPILER_VAR_194->canBeNull = false;
____BAH_COMPILER_VAR_194->isReg = false;
____BAH_COMPILER_VAR_194->lastSet= null;
____BAH_COMPILER_VAR_194->isArg = false;
struct variable* nv = ____BAH_COMPILER_VAR_194;
nv->name = name;
nv->type = "function(";
register long int j = 0;
while ((j<len(fn->args))) {
struct variable* arg = fn->args->data[j];
char * ____BAH_COMPILER_VAR_195 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nv->type);
unsigned int strLen_1 = strlen(arg->type);
;                            
            ____BAH_COMPILER_VAR_195 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_195+currStrOff, nv->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_195+currStrOff, arg->type, strLen_1);
            currStrOff += strLen_1;
        
        }nv->type = ____BAH_COMPILER_VAR_195;
j = j+1;
if ((j<len(fn->args))) {
char * ____BAH_COMPILER_VAR_196 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nv->type);
unsigned int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_196 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_196+currStrOff, nv->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_196+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }nv->type = ____BAH_COMPILER_VAR_196;
}
};
fn->used = true;
char * ____BAH_COMPILER_VAR_197 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(")");
unsigned int strLen_1 = strlen(fn->returns->type);
unsigned int strLen_2 = strlen(nv->type);
;                            
            ____BAH_COMPILER_VAR_197 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_197+currStrOff, nv->type, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_197+currStrOff, ")", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_197+currStrOff, fn->returns->type, strLen_1);
            currStrOff += strLen_1;
        
        }nv->type = ____BAH_COMPILER_VAR_197;
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
char * ____BAH_COMPILER_VAR_198 =string__str(&cont);return getRealVar(____BAH_COMPILER_VAR_198,elems);
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
char * ____BAH_COMPILER_VAR_199 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(" ");
unsigned int strLen_1 = strlen(v->name);
unsigned int strLen_2 = strlen(t);
;                            
            ____BAH_COMPILER_VAR_199 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_199+currStrOff, t, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_199+currStrOff, " ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_199+currStrOff, v->name, strLen_1);
            currStrOff += strLen_1;
        
        }t = ____BAH_COMPILER_VAR_199;
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
struct func* ____BAH_COMPILER_VAR_200 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_200->name = "";
____BAH_COMPILER_VAR_200->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_200->args->length = 0;
            ____BAH_COMPILER_VAR_200->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_200->returns= null;
____BAH_COMPILER_VAR_200->isBinding = false;
____BAH_COMPILER_VAR_200->from = "";
____BAH_COMPILER_VAR_200->file = "";
____BAH_COMPILER_VAR_200->line = 1;
____BAH_COMPILER_VAR_200->isVar = false;
____BAH_COMPILER_VAR_200->used = false;
____BAH_COMPILER_VAR_200->code = null;
____BAH_COMPILER_VAR_200->isMut = false;
____BAH_COMPILER_VAR_200->isImported = false;
____BAH_COMPILER_VAR_200->exits = false;
struct func* nf = ____BAH_COMPILER_VAR_200;
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
struct variable* ____BAH_COMPILER_VAR_201 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_201->name = "";
____BAH_COMPILER_VAR_201->type = "";
____BAH_COMPILER_VAR_201->isConst = false;
____BAH_COMPILER_VAR_201->constVal = "";
____BAH_COMPILER_VAR_201->isArray = false;
____BAH_COMPILER_VAR_201->from = "";
____BAH_COMPILER_VAR_201->declScope= null;
____BAH_COMPILER_VAR_201->isGlobal = false;
____BAH_COMPILER_VAR_201->declRope= null;
____BAH_COMPILER_VAR_201->canBeNull = false;
____BAH_COMPILER_VAR_201->isReg = false;
____BAH_COMPILER_VAR_201->lastSet= null;
____BAH_COMPILER_VAR_201->isArg = false;
struct variable* arg = ____BAH_COMPILER_VAR_201;
char * ____BAH_COMPILER_VAR_202 =null;char * ____BAH_COMPILER_VAR_203 =intToStr(len(nf->args));
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("arg_");
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_203);
;                            
            ____BAH_COMPILER_VAR_202 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_202+currStrOff, "arg_", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_202+currStrOff, ____BAH_COMPILER_VAR_203, strLen_1);
            currStrOff += strLen_1;
        
        }arg->name = ____BAH_COMPILER_VAR_202;
while ((j<cvt.length)) {
c = string__charAt(&cvt,j);
if ((c==44)||(c==41)) {
break;
}

    {
        unsigned long nLength = len(memory);
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(char));
                memory->data = newPtr;
            }
            memory->data[len(memory)] = c;
            memory->length = nLength+1;
        } else {
            memory->data[len(memory)] = c;
        }
    }
    ;
j = j+1;
};
arg->type = arrToStr(memory);
clear(memory);

    {
        unsigned long nLength = len(nf->args);
        if (nLength >= nf->args->length) {
            if (nLength >= nf->args->realLength) {
                if (nf->args->realLength != 0) {
                    nf->args->realLength *= 2;
                } else {
                    nf->args->realLength = 50;
                }
                void * newPtr = memoryRealloc(nf->args->data, (nf->args->realLength)*sizeof(struct variable*));
                nf->args->data = newPtr;
            }
            nf->args->data[len(nf->args)] = arg;
            nf->args->length = nLength+1;
        } else {
            nf->args->data[len(nf->args)] = arg;
        }
    }
    ;
if ((c==41)) {
break;
}
j = j+1;
};
j = j+1;
while ((j<cvt.length)) {
char c = string__charAt(&cvt,j);

    {
        unsigned long nLength = len(memory);
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(char));
                memory->data = newPtr;
            }
            memory->data[len(memory)] = c;
            memory->length = nLength+1;
        } else {
            memory->data[len(memory)] = c;
        }
    }
    ;
j = j+1;
};
struct variable* ____BAH_COMPILER_VAR_204 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_204->name = "";
____BAH_COMPILER_VAR_204->type = "";
____BAH_COMPILER_VAR_204->isConst = false;
____BAH_COMPILER_VAR_204->constVal = "";
____BAH_COMPILER_VAR_204->isArray = false;
____BAH_COMPILER_VAR_204->from = "";
____BAH_COMPILER_VAR_204->declScope= null;
____BAH_COMPILER_VAR_204->isGlobal = false;
____BAH_COMPILER_VAR_204->declRope= null;
____BAH_COMPILER_VAR_204->canBeNull = false;
____BAH_COMPILER_VAR_204->isReg = false;
____BAH_COMPILER_VAR_204->lastSet= null;
____BAH_COMPILER_VAR_204->isArg = false;
nf->returns = ____BAH_COMPILER_VAR_204;
nf->returns->name = "_return";
nf->returns->type = arrToStr(memory);
return nf;
};
struct func* searchFunc(char * name,struct Elems* elems,char inclCurr){
char * ogName = name;
if ((strcmp(name, "noCheck") == 0)) {
struct func* ____BAH_COMPILER_VAR_205 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_205->name = "";
____BAH_COMPILER_VAR_205->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_205->args->length = 0;
            ____BAH_COMPILER_VAR_205->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_205->returns= null;
____BAH_COMPILER_VAR_205->isBinding = false;
____BAH_COMPILER_VAR_205->from = "";
____BAH_COMPILER_VAR_205->file = "";
____BAH_COMPILER_VAR_205->line = 1;
____BAH_COMPILER_VAR_205->isVar = false;
____BAH_COMPILER_VAR_205->used = false;
____BAH_COMPILER_VAR_205->code = null;
____BAH_COMPILER_VAR_205->isMut = false;
____BAH_COMPILER_VAR_205->isImported = false;
____BAH_COMPILER_VAR_205->exits = false;
struct func* fn = ____BAH_COMPILER_VAR_205;
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
char * ____BAH_COMPILER_VAR_206 =string__str(&fnName);struct structMemb* memb = searchStructMemb(____BAH_COMPILER_VAR_206,s,elems);
if ((memb==null)) {
return null;
}
name = fnName.content;
char * ____BAH_COMPILER_VAR_207 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("__");
unsigned int strLen_1 = strlen(name);
unsigned int strLen_2 = strlen(memb->from);
;                            
            ____BAH_COMPILER_VAR_207 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_207+currStrOff, memb->from, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_207+currStrOff, "__", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_207+currStrOff, name, strLen_1);
            currStrOff += strLen_1;
        
        }name = ____BAH_COMPILER_VAR_207;
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
struct func* ____BAH_COMPILER_VAR_208 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_208->name = "";
____BAH_COMPILER_VAR_208->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_208->args->length = 0;
            ____BAH_COMPILER_VAR_208->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_208->returns= null;
____BAH_COMPILER_VAR_208->isBinding = false;
____BAH_COMPILER_VAR_208->from = "";
____BAH_COMPILER_VAR_208->file = "";
____BAH_COMPILER_VAR_208->line = 1;
____BAH_COMPILER_VAR_208->isVar = false;
____BAH_COMPILER_VAR_208->used = false;
____BAH_COMPILER_VAR_208->code = null;
____BAH_COMPILER_VAR_208->isMut = false;
____BAH_COMPILER_VAR_208->isImported = false;
____BAH_COMPILER_VAR_208->exits = false;
struct func* nf = ____BAH_COMPILER_VAR_208;
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
struct string ____BAH_COMPILER_VAR_209 =string(t->cont);char * fnName = splitStringBefore(____BAH_COMPILER_VAR_209,"(");
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
while ((i<len(members))) {
struct structMemb* m = members->data[i];
struct string cmpt = string(m->type);
char declared = false;
if ((strlen(m->def)>0)) {
char * ____BAH_COMPILER_VAR_210 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(m->def);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen(" = ");
unsigned int strLen_3 = strlen(m->name);
unsigned int strLen_4 = strlen(sep);
unsigned int strLen_5 = strlen(v->name);
unsigned int strLen_6 = strlen(code);
;                            
            ____BAH_COMPILER_VAR_210 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_210+currStrOff, code, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_210+currStrOff, v->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_210+currStrOff, sep, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_210+currStrOff, m->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_210+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_210+currStrOff, m->def, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_210+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_210;
declared = true;
}
if ((string__hasPrefix(&cmpt,"[]")==1)) {
string__trimLeft(&cmpt,2);
char * cmptstr = string__str(&cmpt);
struct string elemCType = getCType(cmptstr,elems);
char * elemCTypeStr = string__str(&elemCType);
char * ____BAH_COMPILER_VAR_211 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(elemCTypeStr);
unsigned int strLen_1 = strlen(");\n            ");
unsigned int strLen_2 = strlen("->elemSize = sizeof(");
unsigned int strLen_3 = strlen(m->name);
unsigned int strLen_4 = strlen(sep);
unsigned int strLen_5 = strlen(v->name);
unsigned int strLen_6 = strlen("->length = 0;\n            ");
unsigned int strLen_7 = strlen(m->name);
unsigned int strLen_8 = strlen(sep);
unsigned int strLen_9 = strlen(v->name);
unsigned int strLen_10 = strlen(")));\n            ");
unsigned int strLen_11 = strlen(elemCTypeStr);
unsigned int strLen_12 = strlen(" = memoryAlloc(sizeof(array(");
unsigned int strLen_13 = strlen(m->name);
unsigned int strLen_14 = strlen(sep);
unsigned int strLen_15 = strlen(v->name);
unsigned int strLen_16 = strlen(code);
;                            
            ____BAH_COMPILER_VAR_211 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13+strLen_14+strLen_15+strLen_16);
            
                    memcpy(____BAH_COMPILER_VAR_211+currStrOff, code, strLen_16);
                    currStrOff += strLen_16;
                    
                    memcpy(____BAH_COMPILER_VAR_211+currStrOff, v->name, strLen_15);
                    currStrOff += strLen_15;
                    
                    memcpy(____BAH_COMPILER_VAR_211+currStrOff, sep, strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_211+currStrOff, m->name, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_211+currStrOff, " = memoryAlloc(sizeof(array(", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_211+currStrOff, elemCTypeStr, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_211+currStrOff, ")));\n            ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_211+currStrOff, v->name, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_211+currStrOff, sep, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_211+currStrOff, m->name, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_211+currStrOff, "->length = 0;\n            ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_211+currStrOff, v->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_211+currStrOff, sep, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_211+currStrOff, m->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_211+currStrOff, "->elemSize = sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_211+currStrOff, elemCTypeStr, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_211+currStrOff, ");\n            ", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_211;
declared = true;
}
else if ((string__hasPrefix(&cmpt,"map:")==1)) {
string__trimLeft(&cmpt,4);
char * ____BAH_COMPILER_VAR_212 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(m->name);
unsigned int strLen_1 = strlen(" = mapWrapper();\n");
unsigned int strLen_2 = strlen(sep);
unsigned int strLen_3 = strlen(v->name);
;                            
            ____BAH_COMPILER_VAR_212 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_212+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_212+currStrOff, sep, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_212+currStrOff, m->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_212+currStrOff, " = mapWrapper();\n", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_213 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_212);
;                            
            ____BAH_COMPILER_VAR_213 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_213+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_213+currStrOff, ____BAH_COMPILER_VAR_212, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_213;
declared = true;
}
else if ((string__hasPrefix(&cmpt,"chan:")==1)) {
string__trimLeft(&cmpt,5);
char * ____BAH_COMPILER_VAR_214 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(m->name);
unsigned int strLen_1 = strlen(" = channel();\n");
unsigned int strLen_2 = strlen(sep);
unsigned int strLen_3 = strlen(v->name);
;                            
            ____BAH_COMPILER_VAR_214 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_214+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_214+currStrOff, sep, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_214+currStrOff, m->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_214+currStrOff, " = channel();\n", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_215 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_214);
;                            
            ____BAH_COMPILER_VAR_215 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_215+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_215+currStrOff, ____BAH_COMPILER_VAR_214, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_215;
declared = true;
}
if (isRCPpointerType(m->type)&&(declared==false)) {
char * ____BAH_COMPILER_VAR_216 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(m->name);
unsigned int strLen_1 = strlen("= null;\n");
unsigned int strLen_2 = strlen(sep);
unsigned int strLen_3 = strlen(v->name);
unsigned int strLen_4 = strlen(code);
;                            
            ____BAH_COMPILER_VAR_216 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_216+currStrOff, code, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_216+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_216+currStrOff, sep, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_216+currStrOff, m->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_216+currStrOff, "= null;\n", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_216;
}
i = i+1;
};
if ((s->isBinding==false)) {
long int found = 0;
i = 0;
for (; (i<len(s->methods)); ++i) {
struct func* m = s->methods->data[i];
if ((strcmp(m->name, "_init") == 0)) {
char * ____BAH_COMPILER_VAR_217 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(v->name);
unsigned int strLen_1 = strlen(");\n");
unsigned int strLen_2 = strlen(amp);
unsigned int strLen_3 = strlen("(");
unsigned int strLen_4 = strlen(m->name);
unsigned int strLen_5 = strlen(sep);
unsigned int strLen_6 = strlen(v->name);
;                            
            ____BAH_COMPILER_VAR_217 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_217+currStrOff, v->name, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_217+currStrOff, sep, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_217+currStrOff, m->name, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_217+currStrOff, "(", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_217+currStrOff, amp, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_217+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_217+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_218 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(NEXT_LINE);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_217);
;                            
            ____BAH_COMPILER_VAR_218 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_218+currStrOff, NEXT_LINE, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_218+currStrOff, ____BAH_COMPILER_VAR_217, strLen_1);
            currStrOff += strLen_1;
        
        }NEXT_LINE = ____BAH_COMPILER_VAR_218;
++found;
}
else if ((strcmp(m->name, "_end") == 0)) {
if ((strcmp(sep, "->") == 0)) {
char * ____BAH_COMPILER_VAR_219 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(m->name);
unsigned int strLen_1 = strlen(");\n");
unsigned int strLen_2 = strlen(sep);
unsigned int strLen_3 = strlen(v->name);
unsigned int strLen_4 = strlen(", ");
unsigned int strLen_5 = strlen(v->name);
unsigned int strLen_6 = strlen("memoryOnEnd(");
;                            
            ____BAH_COMPILER_VAR_219 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_219+currStrOff, "memoryOnEnd(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_219+currStrOff, v->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_219+currStrOff, ", ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_219+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_219+currStrOff, sep, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_219+currStrOff, m->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_219+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_220 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_219);
;                            
            ____BAH_COMPILER_VAR_220 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_220+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_220+currStrOff, ____BAH_COMPILER_VAR_219, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_220;
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
char * ____BAH_COMPILER_VAR_221 =null;char * ____BAH_COMPILER_VAR_222 =intToStr(NB_COMP_VAR);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("____BAH_COMPILER_VAR_");
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_222);
;                            
            ____BAH_COMPILER_VAR_221 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_221+currStrOff, "____BAH_COMPILER_VAR_", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_221+currStrOff, ____BAH_COMPILER_VAR_222, strLen_1);
            currStrOff += strLen_1;
        
        }char * name = ____BAH_COMPILER_VAR_221;
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

    {
        unsigned long nLength = i;
        if (nLength >= a->length) {
            if (nLength >= a->realLength) {
                if (a->realLength != 0) {
                    a->realLength *= 2;
                } else {
                    a->realLength = 50;
                }
                void * newPtr = memoryRealloc(a->data, (a->realLength)*sizeof(char));
                a->data = newPtr;
            }
            a->data[i] = (char)c;
            a->length = nLength+1;
        } else {
            a->data[i] = (char)c;
        }
    }
    ;
};
return arrToStr(a);
};
void makeInit(){
char * name = "__BAH_init";
if ((isObject==true)) {
char * ____BAH_COMPILER_VAR_223 =null;char * ____BAH_COMPILER_VAR_224 =pathToVarName(compilerState.currentFile);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(name);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_224);
;                            
            ____BAH_COMPILER_VAR_223 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_223+currStrOff, name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_223+currStrOff, ____BAH_COMPILER_VAR_224, strLen_1);
            currStrOff += strLen_1;
        
        }name = ____BAH_COMPILER_VAR_223;
}
char * evals = "";
char * ____BAH_COMPILER_VAR_225 =null;char * ____BAH_COMPILER_VAR_226 =intToStr(len(compilerState.evals));
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_226);
unsigned int strLen_1 = strlen("] = {");
unsigned int strLen_2 = strlen("volatile struct __eval_binding __tmp__evals_bindings[");
;                            
            ____BAH_COMPILER_VAR_225 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_225+currStrOff, "volatile struct __eval_binding __tmp__evals_bindings[", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_225+currStrOff, ____BAH_COMPILER_VAR_226, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_225+currStrOff, "] = {", strLen_1);
            currStrOff += strLen_1;
        
        }char * evalsTMPDecl = ____BAH_COMPILER_VAR_225;
register long int i = 0;
for (; (i<len(compilerState.evals)); ++i) {
char * e = compilerState.evals->data[i];
char * ____BAH_COMPILER_VAR_227 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(e);
unsigned int strLen_1 = strlen("\n        }");
unsigned int strLen_2 = strlen("\",\n            .evalFn = __Bah_eval_");
unsigned int strLen_3 = strlen(e);
unsigned int strLen_4 = strlen("{\n            .name = \"");
;                            
            ____BAH_COMPILER_VAR_227 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_227+currStrOff, "{\n            .name = \"", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_227+currStrOff, e, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_227+currStrOff, "\",\n            .evalFn = __Bah_eval_", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_227+currStrOff, e, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_227+currStrOff, "\n        }", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_228 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(evalsTMPDecl);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_227);
;                            
            ____BAH_COMPILER_VAR_228 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_228+currStrOff, evalsTMPDecl, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_228+currStrOff, ____BAH_COMPILER_VAR_227, strLen_1);
            currStrOff += strLen_1;
        
        }evalsTMPDecl = ____BAH_COMPILER_VAR_228;
if ((i+1!=len(compilerState.evals))) {
char * ____BAH_COMPILER_VAR_229 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(evalsTMPDecl);
unsigned int strLen_1 = strlen(",\n");
;                            
            ____BAH_COMPILER_VAR_229 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_229+currStrOff, evalsTMPDecl, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_229+currStrOff, ",\n", strLen_1);
            currStrOff += strLen_1;
        
        }evalsTMPDecl = ____BAH_COMPILER_VAR_229;
}
else {
char * ____BAH_COMPILER_VAR_230 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(evalsTMPDecl);
unsigned int strLen_1 = strlen("};");
;                            
            ____BAH_COMPILER_VAR_230 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_230+currStrOff, evalsTMPDecl, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_230+currStrOff, "};", strLen_1);
            currStrOff += strLen_1;
        
        }evalsTMPDecl = ____BAH_COMPILER_VAR_230;
}
};
if ((len(compilerState.evals)!=0)) {
char * ____BAH_COMPILER_VAR_231 =null;char * ____BAH_COMPILER_VAR_232 =intToStr(len(compilerState.evals));
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_232);
unsigned int strLen_1 = strlen(";");
unsigned int strLen_2 = strlen("__evals_bindings = __tmp__evals_bindings; __evals_length = ");
;                            
            ____BAH_COMPILER_VAR_231 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_231+currStrOff, "__evals_bindings = __tmp__evals_bindings; __evals_length = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_231+currStrOff, ____BAH_COMPILER_VAR_232, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_231+currStrOff, ";", strLen_1);
            currStrOff += strLen_1;
        
        }evals = ____BAH_COMPILER_VAR_231;
}
else {
evalsTMPDecl = "";
}
char * ____BAH_COMPILER_VAR_233 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(name);
unsigned int strLen_1 = strlen("() {\n        ");
unsigned int strLen_2 = strlen("\n    void __attribute__((optimize(\"O0\"))) ");
unsigned int strLen_3 = strlen(evalsTMPDecl);
unsigned int strLen_4 = strlen("\n    ");
;                            
            ____BAH_COMPILER_VAR_233 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_233+currStrOff, "\n    ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_233+currStrOff, evalsTMPDecl, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_233+currStrOff, "\n    void __attribute__((optimize(\"O0\"))) ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_233+currStrOff, name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_233+currStrOff, "() {\n        ", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_234 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(evals);
unsigned int strLen_1 = strlen("\n    };\n    ");
unsigned int strLen_2 = strlen("\n        ");
;                            
            ____BAH_COMPILER_VAR_234 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_234+currStrOff, "\n        ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_234+currStrOff, evals, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_234+currStrOff, "\n    };\n    ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope__add(rope(____BAH_COMPILER_VAR_233), rope__add(INIT, rope(____BAH_COMPILER_VAR_234))));
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
char * ____BAH_COMPILER_VAR_235 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(v->name);
unsigned int strLen_1 = strlen(");\n");
unsigned int strLen_2 = strlen("RCP_decr(");
;                            
            ____BAH_COMPILER_VAR_235 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_235+currStrOff, "RCP_decr(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_235+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_235+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }r = rope__add(r, rope(____BAH_COMPILER_VAR_235));
}
else if (strHasPrefix(v->type,"chan:")) {
char * ____BAH_COMPILER_VAR_236 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(v->name);
unsigned int strLen_1 = strlen(");\n");
unsigned int strLen_2 = strlen("RCP_decr(");
;                            
            ____BAH_COMPILER_VAR_236 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_236+currStrOff, "RCP_decr(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_236+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_236+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }r = rope__add(r, rope(____BAH_COMPILER_VAR_236));
}
else {
if (strHasPrefix(v->type,"map:")) {
struct variable* ____BAH_COMPILER_VAR_237 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_237->name = "";
____BAH_COMPILER_VAR_237->type = "";
____BAH_COMPILER_VAR_237->isConst = false;
____BAH_COMPILER_VAR_237->constVal = "";
____BAH_COMPILER_VAR_237->isArray = false;
____BAH_COMPILER_VAR_237->from = "";
____BAH_COMPILER_VAR_237->declScope= null;
____BAH_COMPILER_VAR_237->isGlobal = false;
____BAH_COMPILER_VAR_237->declRope= null;
____BAH_COMPILER_VAR_237->canBeNull = false;
____BAH_COMPILER_VAR_237->isReg = false;
____BAH_COMPILER_VAR_237->lastSet= null;
____BAH_COMPILER_VAR_237->isArg = false;
struct variable* nv = ____BAH_COMPILER_VAR_237;
*nv = *v;
v = nv;
v->type = "mapWrapper*";
}
char isPointer = isRCPpointerType(v->type);
struct cStruct* s = searchStruct(v->type,elems);
if ((s!=null)&&(s->isBinding==false)) {
if ((isPointer==true)) {
char * ____BAH_COMPILER_VAR_238 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(v->name);
unsigned int strLen_1 = strlen(");\n");
unsigned int strLen_2 = strlen("RCP_decr(");
;                            
            ____BAH_COMPILER_VAR_238 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_238+currStrOff, "RCP_decr(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_238+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_238+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }r = rope__add(r, rope(____BAH_COMPILER_VAR_238));
}
else {
char * ____BAH_COMPILER_VAR_239 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(v->name);
unsigned int strLen_1 = strlen("), 1);\n");
unsigned int strLen_2 = strlen(", sizeof(");
unsigned int strLen_3 = strlen(v->name);
unsigned int strLen_4 = strlen("RCP_scanStack(&");
;                            
            ____BAH_COMPILER_VAR_239 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_239+currStrOff, "RCP_scanStack(&", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_239+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_239+currStrOff, ", sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_239+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_239+currStrOff, "), 1);\n", strLen_1);
            currStrOff += strLen_1;
        
        }r = rope__add(r, rope(____BAH_COMPILER_VAR_239));
}
}
else if ((isPointer==true)) {
char * ____BAH_COMPILER_VAR_240 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(v->name);
unsigned int strLen_1 = strlen(");\n");
unsigned int strLen_2 = strlen("RCP_decr(");
;                            
            ____BAH_COMPILER_VAR_240 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_240+currStrOff, "RCP_decr(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_240+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_240+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }r = rope__add(r, rope(____BAH_COMPILER_VAR_240));
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
char * ____BAH_COMPILER_VAR_241 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(v->name);
unsigned int strLen_1 = strlen("), 0);");
unsigned int strLen_2 = strlen(", sizeof(");
unsigned int strLen_3 = strlen(v->name);
unsigned int strLen_4 = strlen("RCP_scanStack(&");
;                            
            ____BAH_COMPILER_VAR_241 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_241+currStrOff, "RCP_scanStack(&", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_241+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_241+currStrOff, ", sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_241+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_241+currStrOff, "), 0);", strLen_1);
            currStrOff += strLen_1;
        
        }return rope(____BAH_COMPILER_VAR_241);
}
char * ____BAH_COMPILER_VAR_242 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(v->name);
unsigned int strLen_1 = strlen(");");
unsigned int strLen_2 = strlen("RCP_incr(");
;                            
            ____BAH_COMPILER_VAR_242 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_242+currStrOff, "RCP_incr(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_242+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_242+currStrOff, ");", strLen_1);
            currStrOff += strLen_1;
        
        }return rope(____BAH_COMPILER_VAR_242);
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
char * ____BAH_COMPILER_VAR_243 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(elems->defined->data[i]);
unsigned int strLen_1 = strlen("\n");
unsigned int strLen_2 = strlen("\n#undef ");
;                            
            ____BAH_COMPILER_VAR_243 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_243+currStrOff, "\n#undef ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_243+currStrOff, elems->defined->data[i], strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_243+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_243));
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
struct variable* ____BAH_COMPILER_VAR_244 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_244->name = "";
____BAH_COMPILER_VAR_244->type = "";
____BAH_COMPILER_VAR_244->isConst = false;
____BAH_COMPILER_VAR_244->constVal = "";
____BAH_COMPILER_VAR_244->isArray = false;
____BAH_COMPILER_VAR_244->from = "";
____BAH_COMPILER_VAR_244->declScope= null;
____BAH_COMPILER_VAR_244->isGlobal = false;
____BAH_COMPILER_VAR_244->declRope= null;
____BAH_COMPILER_VAR_244->canBeNull = false;
____BAH_COMPILER_VAR_244->isReg = false;
____BAH_COMPILER_VAR_244->lastSet= null;
____BAH_COMPILER_VAR_244->isArg = false;
struct variable* av = ____BAH_COMPILER_VAR_244;
av->type = t;
av->declScope = elems;
av->name = genCompilerVar();

    {
        unsigned long nLength = len(elems->vars);
        if (nLength >= elems->vars->length) {
            if (nLength >= elems->vars->realLength) {
                if (elems->vars->realLength != 0) {
                    elems->vars->realLength *= 2;
                } else {
                    elems->vars->realLength = 50;
                }
                void * newPtr = memoryRealloc(elems->vars->data, (elems->vars->realLength)*sizeof(struct variable*));
                elems->vars->data = newPtr;
            }
            elems->vars->data[len(elems->vars)] = av;
            elems->vars->length = nLength+1;
        } else {
            elems->vars->data[len(elems->vars)] = av;
        }
    }
    ;
struct string cType = getCType(av->type,elems);
char * ____BAH_COMPILER_VAR_245 =null;char * ____BAH_COMPILER_VAR_246 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(c);
unsigned int strLen_1 = strlen(";");
unsigned int strLen_2 = strlen(" =");
unsigned int strLen_3 = strlen(av->name);
unsigned int strLen_4 = strlen(" ");
unsigned int strLen_5 = strlen(____BAH_COMPILER_VAR_246);
;                            
            ____BAH_COMPILER_VAR_245 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_245+currStrOff, ____BAH_COMPILER_VAR_246, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_245+currStrOff, " ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_245+currStrOff, av->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_245+currStrOff, " =", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_245+currStrOff, c, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_245+currStrOff, ";", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_245));
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

        char ____BAH_COMPILER_VAR_247 = 0;
        for(int i=noVOfns->length-1; i!=-1;i--) {
            if (noVOfns->data[i] != 0 && strcmp(noVOfns->data[i], currentFn->name) == 0) {
                ____BAH_COMPILER_VAR_247=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_247) {
return false;
}
}
return true;
};
struct verboseOutVar verboseOutTransformVar(struct variable* v,char * cont,struct Elems* elems){
struct verboseOutVar ____BAH_COMPILER_VAR_248 = {};
____BAH_COMPILER_VAR_248.markup= null;
____BAH_COMPILER_VAR_248.content= null;
#define rv ____BAH_COMPILER_VAR_248
char * ogCont = cont;
if ((strcmp(v->type, "cpstring") == 0)) {
char * ____BAH_COMPILER_VAR_249 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(cont);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen("__Bah_safe_string(");
;                            
            ____BAH_COMPILER_VAR_249 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_249+currStrOff, "__Bah_safe_string(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_249+currStrOff, cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_249+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }cont = ____BAH_COMPILER_VAR_249;
}
char * ____BAH_COMPILER_VAR_250 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(", ");
unsigned int strLen_1 = strlen(cont);
;                            
            ____BAH_COMPILER_VAR_250 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_250+currStrOff, ", ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_250+currStrOff, cont, strLen_1);
            currStrOff += strLen_1;
        
        }cont = ____BAH_COMPILER_VAR_250;
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
char * ____BAH_COMPILER_VAR_251 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ASCII_RESET);
unsigned int strLen_1 = strlen("{");
;                            
            ____BAH_COMPILER_VAR_251 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_251+currStrOff, ASCII_RESET, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_251+currStrOff, "{", strLen_1);
            currStrOff += strLen_1;
        
        }ct = ____BAH_COMPILER_VAR_251;
cont = "";
register long int i = 0;
for (; (i<len(s->members)); ++i) {
struct variable* m = s->members->data[i];
char * ____BAH_COMPILER_VAR_252 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(".");
unsigned int strLen_1 = strlen(m->name);
unsigned int strLen_2 = strlen(")");
unsigned int strLen_3 = strlen(ogCont);
unsigned int strLen_4 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_252 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_252+currStrOff, "(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_252+currStrOff, ogCont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_252+currStrOff, ")", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_252+currStrOff, ".", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_252+currStrOff, m->name, strLen_1);
            currStrOff += strLen_1;
        
        }struct verboseOutVar mv = verboseOutTransformVar(m,____BAH_COMPILER_VAR_252,elems);
if ((i!=0)) {
char * ____BAH_COMPILER_VAR_253 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ct);
unsigned int strLen_1 = strlen(", ");
;                            
            ____BAH_COMPILER_VAR_253 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_253+currStrOff, ct, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_253+currStrOff, ", ", strLen_1);
            currStrOff += strLen_1;
        
        }ct = ____BAH_COMPILER_VAR_253;
}
char * ____BAH_COMPILER_VAR_254 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ct);
unsigned int strLen_1 = strlen(mv.markup);
;                            
            ____BAH_COMPILER_VAR_254 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_254+currStrOff, ct, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_254+currStrOff, mv.markup, strLen_1);
            currStrOff += strLen_1;
        
        }ct = ____BAH_COMPILER_VAR_254;
char * ____BAH_COMPILER_VAR_255 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(cont);
unsigned int strLen_1 = strlen(mv.content);
;                            
            ____BAH_COMPILER_VAR_255 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_255+currStrOff, cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_255+currStrOff, mv.content, strLen_1);
            currStrOff += strLen_1;
        
        }cont = ____BAH_COMPILER_VAR_255;
};
char * ____BAH_COMPILER_VAR_256 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ct);
unsigned int strLen_1 = strlen("}");
;                            
            ____BAH_COMPILER_VAR_256 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_256+currStrOff, ct, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_256+currStrOff, "}", strLen_1);
            currStrOff += strLen_1;
        
        }ct = ____BAH_COMPILER_VAR_256;
}
}
char * ____BAH_COMPILER_VAR_257 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ct);
unsigned int strLen_1 = strlen(ASCII_RESET);
unsigned int strLen_2 = strlen(ASCII_MAGENTA);
unsigned int strLen_3 = strlen(" = ");
unsigned int strLen_4 = strlen(ASCII_RESET);
unsigned int strLen_5 = strlen(v->name);
unsigned int strLen_6 = strlen(ASCII_BLUE);
;                            
            ____BAH_COMPILER_VAR_257 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_257+currStrOff, ASCII_BLUE, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_257+currStrOff, v->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_257+currStrOff, ASCII_RESET, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_257+currStrOff, " = ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_257+currStrOff, ASCII_MAGENTA, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_257+currStrOff, ct, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_257+currStrOff, ASCII_RESET, strLen_1);
            currStrOff += strLen_1;
        
        }rv.markup = ____BAH_COMPILER_VAR_257;
rv.content = cont;
return rv;

#undef rv
};
struct verboseOutVar verboseOutTransformTok(struct Tok* t,struct Elems* elems){
if ((t->type==TOKEN_TYPE_VAR)&&(t->isOper==false)) {
struct variable* v = searchVar(t->cont,elems);
if ((v==null)) {
struct verboseOutVar ____BAH_COMPILER_VAR_258 = {};
____BAH_COMPILER_VAR_258.markup= null;
____BAH_COMPILER_VAR_258.content= null;
#define rv ____BAH_COMPILER_VAR_258
return rv;

#undef rv
}
}
struct variable ____BAH_COMPILER_VAR_259 = {};
____BAH_COMPILER_VAR_259.name = "";
____BAH_COMPILER_VAR_259.type = "";
____BAH_COMPILER_VAR_259.isConst = false;
____BAH_COMPILER_VAR_259.constVal = "";
____BAH_COMPILER_VAR_259.isArray = false;
____BAH_COMPILER_VAR_259.from = "";
____BAH_COMPILER_VAR_259.declScope= null;
____BAH_COMPILER_VAR_259.isGlobal = false;
____BAH_COMPILER_VAR_259.declRope= null;
____BAH_COMPILER_VAR_259.canBeNull = false;
____BAH_COMPILER_VAR_259.isReg = false;
____BAH_COMPILER_VAR_259.lastSet= null;
____BAH_COMPILER_VAR_259.isArg = false;
____BAH_COMPILER_VAR_259.name = "(value)";
____BAH_COMPILER_VAR_259.type = getTypeFromToken(t,true,elems);
#define v ____BAH_COMPILER_VAR_259
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
char * ____BAH_COMPILER_VAR_260 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnArgs);
unsigned int strLen_1 = strlen(", ");
;                            
            ____BAH_COMPILER_VAR_260 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_260+currStrOff, fnArgs, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_260+currStrOff, ", ", strLen_1);
            currStrOff += strLen_1;
        
        }fnArgs = ____BAH_COMPILER_VAR_260;
}
struct Tok t = args->data[j];
struct verboseOutVar v = verboseOutTransformVar(a,t.cont,elems);
char * ____BAH_COMPILER_VAR_261 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnArgs);
unsigned int strLen_1 = strlen(v.markup);
;                            
            ____BAH_COMPILER_VAR_261 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_261+currStrOff, fnArgs, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_261+currStrOff, v.markup, strLen_1);
            currStrOff += strLen_1;
        
        }fnArgs = ____BAH_COMPILER_VAR_261;
char * ____BAH_COMPILER_VAR_262 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnArgsValues);
unsigned int strLen_1 = strlen(v.content);
;                            
            ____BAH_COMPILER_VAR_262 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_262+currStrOff, fnArgsValues, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_262+currStrOff, v.content, strLen_1);
            currStrOff += strLen_1;
        
        }fnArgsValues = ____BAH_COMPILER_VAR_262;
};
char * ____BAH_COMPILER_VAR_263 =null;char * ____BAH_COMPILER_VAR_264 =intToStr(lineNb);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(":");
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_264);
unsigned int strLen_2 = strlen(compilerState.currentFile);
;                            
            ____BAH_COMPILER_VAR_263 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_263+currStrOff, compilerState.currentFile, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_263+currStrOff, ":", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_263+currStrOff, ____BAH_COMPILER_VAR_264, strLen_1);
            currStrOff += strLen_1;
        
        }char * line = ____BAH_COMPILER_VAR_263;
char * ____BAH_COMPILER_VAR_265 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnArgsValues);
unsigned int strLen_1 = strlen(");\n    //\n    ");
unsigned int strLen_2 = strlen("\\n\"");
unsigned int strLen_3 = strlen(ASCII_RESET);
unsigned int strLen_4 = strlen(line);
unsigned int strLen_5 = strlen(ASCII_GREEN);
unsigned int strLen_6 = strlen(") -> ");
unsigned int strLen_7 = strlen(fnArgs);
unsigned int strLen_8 = strlen("(");
unsigned int strLen_9 = strlen(ASCII_RESET);
unsigned int strLen_10 = strlen(fn->name);
unsigned int strLen_11 = strlen(nameColor);
unsigned int strLen_12 = strlen("\n    //Verbose Runtime\n        printf(\"[VO] calling: ");
;                            
            ____BAH_COMPILER_VAR_265 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12);
            
                    memcpy(____BAH_COMPILER_VAR_265+currStrOff, "\n    //Verbose Runtime\n        printf(\"[VO] calling: ", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_265+currStrOff, nameColor, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_265+currStrOff, fn->name, strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_265+currStrOff, ASCII_RESET, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_265+currStrOff, "(", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_265+currStrOff, fnArgs, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_265+currStrOff, ") -> ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_265+currStrOff, ASCII_GREEN, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_265+currStrOff, line, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_265+currStrOff, ASCII_RESET, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_265+currStrOff, "\\n\"", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_265+currStrOff, fnArgsValues, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_265+currStrOff, ");\n    //\n    ", strLen_1);
            currStrOff += strLen_1;
        
        }struct rope* verboseOut = rope(____BAH_COMPILER_VAR_265);
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
char * ____BAH_COMPILER_VAR_266 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(pvo.content);
unsigned int strLen_1 = strlen(nvo.content);
;                            
            ____BAH_COMPILER_VAR_266 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_266+currStrOff, pvo.content, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_266+currStrOff, nvo.content, strLen_1);
            currStrOff += strLen_1;
        
        }char * values = ____BAH_COMPILER_VAR_266;
char * ____BAH_COMPILER_VAR_267 =null;char * ____BAH_COMPILER_VAR_268 =intToStr(lineNb);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(":");
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_268);
unsigned int strLen_2 = strlen(compilerState.currentFile);
;                            
            ____BAH_COMPILER_VAR_267 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_267+currStrOff, compilerState.currentFile, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_267+currStrOff, ":", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_267+currStrOff, ____BAH_COMPILER_VAR_268, strLen_1);
            currStrOff += strLen_1;
        
        }char * line = ____BAH_COMPILER_VAR_267;
char * ____BAH_COMPILER_VAR_269 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(values);
unsigned int strLen_1 = strlen(");\n    //\n    ");
unsigned int strLen_2 = strlen("\\n\"");
unsigned int strLen_3 = strlen(ASCII_RESET);
unsigned int strLen_4 = strlen(line);
unsigned int strLen_5 = strlen(ASCII_GREEN);
unsigned int strLen_6 = strlen(" -> ");
unsigned int strLen_7 = strlen(nvo.markup);
unsigned int strLen_8 = strlen(" AND ");
unsigned int strLen_9 = strlen(pvo.markup);
unsigned int strLen_10 = strlen("\n    //Verbose Runtime\n        printf(\"[VO]    oper: ");
;                            
            ____BAH_COMPILER_VAR_269 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10);
            
                    memcpy(____BAH_COMPILER_VAR_269+currStrOff, "\n    //Verbose Runtime\n        printf(\"[VO]    oper: ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_269+currStrOff, pvo.markup, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_269+currStrOff, " AND ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_269+currStrOff, nvo.markup, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_269+currStrOff, " -> ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_269+currStrOff, ASCII_GREEN, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_269+currStrOff, line, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_269+currStrOff, ASCII_RESET, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_269+currStrOff, "\\n\"", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_269+currStrOff, values, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_269+currStrOff, ");\n    //\n    ", strLen_1);
            currStrOff += strLen_1;
        
        }struct rope* verboseOut = rope(____BAH_COMPILER_VAR_269);
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
struct fileStream ____BAH_COMPILER_VAR_270 = {};
____BAH_COMPILER_VAR_270.handle= null;
____BAH_COMPILER_VAR_270.name= null;
#define fs ____BAH_COMPILER_VAR_270
char * ____BAH_COMPILER_VAR_271 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(BAH_DIR);
unsigned int strLen_1 = strlen("cache/cache.json");
;                            
            ____BAH_COMPILER_VAR_271 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_271+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_271+currStrOff, "cache/cache.json", strLen_1);
            currStrOff += strLen_1;
        
        }fileStream__open(&fs,____BAH_COMPILER_VAR_271,"r");
if ((fileStream__isValid(&fs)==0)||(fileStream__getSize(&fs)==0)) {
char * ____BAH_COMPILER_VAR_272 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(BAH_DIR);
unsigned int strLen_1 = strlen("cache");
;                            
            ____BAH_COMPILER_VAR_272 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_272+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_272+currStrOff, "cache", strLen_1);
            currStrOff += strLen_1;
        
        }mkdir(____BAH_COMPILER_VAR_272,S_IRWXU);
char * ____BAH_COMPILER_VAR_273 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(BAH_DIR);
unsigned int strLen_1 = strlen("cache/cache.json");
;                            
            ____BAH_COMPILER_VAR_273 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_273+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_273+currStrOff, "cache/cache.json", strLen_1);
            currStrOff += strLen_1;
        
        }fileStream__createFile(&fs,____BAH_COMPILER_VAR_273);
return;
}
char * ____BAH_COMPILER_VAR_274 =fileStream__readContent(&fs);struct jsonElement* j = parseJson(____BAH_COMPILER_VAR_274);
fileStream__close(&fs);
array(struct cacheFile**)* ____BAH_COMPILER_VAR_275 = &cache;
struct cacheFile*** ____BAH_COMPILER_VAR_276 = 0;
char ** ____BAH_COMPILER_VAR_278 = (char **)((char*)(____BAH_COMPILER_VAR_276) + offsetof(struct cacheFile, file));
struct reflectElement ____BAH_COMPILER_VAR_279 = __reflect(____BAH_COMPILER_VAR_278, sizeof(char *), "cpstring", "file", 0, 0, 0, 0, offsetof(struct cacheFile, file));
long int* ____BAH_COMPILER_VAR_280 = (long int*)((char*)(____BAH_COMPILER_VAR_276) + offsetof(struct cacheFile, last));
struct reflectElement ____BAH_COMPILER_VAR_281 = __reflect(____BAH_COMPILER_VAR_280, sizeof(long int), "int", "last", 0, 0, 0, 0, offsetof(struct cacheFile, last));
char ** ____BAH_COMPILER_VAR_282 = (char **)((char*)(____BAH_COMPILER_VAR_276) + offsetof(struct cacheFile, ver));
struct reflectElement ____BAH_COMPILER_VAR_283 = __reflect(____BAH_COMPILER_VAR_282, sizeof(char *), "cpstring", "ver", 0, 0, 0, 0, offsetof(struct cacheFile, ver));
long int* ____BAH_COMPILER_VAR_284 = (long int*)((char*)(____BAH_COMPILER_VAR_276) + offsetof(struct cacheFile, date));
struct reflectElement ____BAH_COMPILER_VAR_285 = __reflect(____BAH_COMPILER_VAR_284, sizeof(long int), "int", "date", 0, 0, 0, 0, offsetof(struct cacheFile, date));
long int* ____BAH_COMPILER_VAR_286 = (long int*)((char*)(____BAH_COMPILER_VAR_276) + offsetof(struct cacheFile, mem));
struct reflectElement ____BAH_COMPILER_VAR_287 = __reflect(____BAH_COMPILER_VAR_286, sizeof(long int), "int", "mem", 0, 0, 0, 0, offsetof(struct cacheFile, mem));
long int* ____BAH_COMPILER_VAR_288 = (long int*)((char*)(____BAH_COMPILER_VAR_276) + offsetof(struct cacheFile, opti));
struct reflectElement ____BAH_COMPILER_VAR_289 = __reflect(____BAH_COMPILER_VAR_288, sizeof(long int), "int", "opti", 0, 0, 0, 0, offsetof(struct cacheFile, opti));
array(char *)** ____BAH_COMPILER_VAR_290 = (array(char *)**)((char*)(____BAH_COMPILER_VAR_276) + offsetof(struct cacheFile, files));
char ** ____BAH_COMPILER_VAR_291 = 0;
struct reflectElement ____BAH_COMPILER_VAR_292 = __reflect(____BAH_COMPILER_VAR_291, sizeof(char *), "cpstring", "", 0, 0, 0, 0, 0);

        struct reflectElement ____BAH_COMPILER_VAR_293 = ____BAH_COMPILER_VAR_292;
        struct reflectElement ____BAH_COMPILER_VAR_294 = __reflect(____BAH_COMPILER_VAR_290, sizeof(array(char *)*), "[]cpstring", "files", 1, &____BAH_COMPILER_VAR_293, 0, 0, offsetof(struct cacheFile, files));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_277 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_277->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_277->length = 7;
        ____BAH_COMPILER_VAR_277->data = memoryAlloc(____BAH_COMPILER_VAR_277->length * ____BAH_COMPILER_VAR_277->elemSize);
        ____BAH_COMPILER_VAR_277->data[0] = ____BAH_COMPILER_VAR_279;
____BAH_COMPILER_VAR_277->data[1] = ____BAH_COMPILER_VAR_281;
____BAH_COMPILER_VAR_277->data[2] = ____BAH_COMPILER_VAR_283;
____BAH_COMPILER_VAR_277->data[3] = ____BAH_COMPILER_VAR_285;
____BAH_COMPILER_VAR_277->data[4] = ____BAH_COMPILER_VAR_287;
____BAH_COMPILER_VAR_277->data[5] = ____BAH_COMPILER_VAR_289;
____BAH_COMPILER_VAR_277->data[6] = ____BAH_COMPILER_VAR_294;
struct reflectElement ____BAH_COMPILER_VAR_295 = __reflect(____BAH_COMPILER_VAR_276, sizeof(struct cacheFile), "cacheFile**", "", 0, 0, 1, ____BAH_COMPILER_VAR_277, 0);

        struct reflectElement ____BAH_COMPILER_VAR_296 = ____BAH_COMPILER_VAR_295;
        struct reflectElement ____BAH_COMPILER_VAR_297 = __reflect(____BAH_COMPILER_VAR_275, sizeof(array(struct cacheFile**)*), "[]cacheFile**", "&cache", 1, &____BAH_COMPILER_VAR_296, 0, 0, 0);
jsonElement__scan(j,____BAH_COMPILER_VAR_297);
if ((cache!=null)) {
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
struct cacheFile* ____BAH_COMPILER_VAR_298 = memoryAlloc(sizeof(struct cacheFile));
____BAH_COMPILER_VAR_298->file= null;
____BAH_COMPILER_VAR_298->ver= null;
____BAH_COMPILER_VAR_298->files = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_298->files->length = 0;
            ____BAH_COMPILER_VAR_298->files->elemSize = sizeof(char *);
            struct cacheFile* c = ____BAH_COMPILER_VAR_298;
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

    {
        unsigned long nLength = len(cache);
        if (nLength >= cache->length) {
            if (nLength >= cache->realLength) {
                if (cache->realLength != 0) {
                    cache->realLength *= 2;
                } else {
                    cache->realLength = 50;
                }
                void * newPtr = memoryRealloc(cache->data, (cache->realLength)*sizeof(struct cacheFile*));
                cache->data = newPtr;
            }
            cache->data[len(cache)] = c;
            cache->length = nLength+1;
        } else {
            cache->data[len(cache)] = c;
        }
    }
    ;
};
void writeCache(){
struct fileStream ____BAH_COMPILER_VAR_299 = {};
____BAH_COMPILER_VAR_299.handle= null;
____BAH_COMPILER_VAR_299.name= null;
#define fs ____BAH_COMPILER_VAR_299
char * ____BAH_COMPILER_VAR_300 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(BAH_DIR);
unsigned int strLen_1 = strlen("cache/cache.json");
;                            
            ____BAH_COMPILER_VAR_300 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_300+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_300+currStrOff, "cache/cache.json", strLen_1);
            currStrOff += strLen_1;
        
        }fileStream__open(&fs,____BAH_COMPILER_VAR_300,"w");
array(struct cacheFile*)* ____BAH_COMPILER_VAR_301 = cache;
struct cacheFile** ____BAH_COMPILER_VAR_302 = 0;
char ** ____BAH_COMPILER_VAR_304 = (char **)((char*)(____BAH_COMPILER_VAR_302) + offsetof(struct cacheFile, file));
struct reflectElement ____BAH_COMPILER_VAR_305 = __reflect(____BAH_COMPILER_VAR_304, sizeof(char *), "cpstring", "file", 0, 0, 0, 0, offsetof(struct cacheFile, file));
long int* ____BAH_COMPILER_VAR_306 = (long int*)((char*)(____BAH_COMPILER_VAR_302) + offsetof(struct cacheFile, last));
struct reflectElement ____BAH_COMPILER_VAR_307 = __reflect(____BAH_COMPILER_VAR_306, sizeof(long int), "int", "last", 0, 0, 0, 0, offsetof(struct cacheFile, last));
char ** ____BAH_COMPILER_VAR_308 = (char **)((char*)(____BAH_COMPILER_VAR_302) + offsetof(struct cacheFile, ver));
struct reflectElement ____BAH_COMPILER_VAR_309 = __reflect(____BAH_COMPILER_VAR_308, sizeof(char *), "cpstring", "ver", 0, 0, 0, 0, offsetof(struct cacheFile, ver));
long int* ____BAH_COMPILER_VAR_310 = (long int*)((char*)(____BAH_COMPILER_VAR_302) + offsetof(struct cacheFile, date));
struct reflectElement ____BAH_COMPILER_VAR_311 = __reflect(____BAH_COMPILER_VAR_310, sizeof(long int), "int", "date", 0, 0, 0, 0, offsetof(struct cacheFile, date));
long int* ____BAH_COMPILER_VAR_312 = (long int*)((char*)(____BAH_COMPILER_VAR_302) + offsetof(struct cacheFile, mem));
struct reflectElement ____BAH_COMPILER_VAR_313 = __reflect(____BAH_COMPILER_VAR_312, sizeof(long int), "int", "mem", 0, 0, 0, 0, offsetof(struct cacheFile, mem));
long int* ____BAH_COMPILER_VAR_314 = (long int*)((char*)(____BAH_COMPILER_VAR_302) + offsetof(struct cacheFile, opti));
struct reflectElement ____BAH_COMPILER_VAR_315 = __reflect(____BAH_COMPILER_VAR_314, sizeof(long int), "int", "opti", 0, 0, 0, 0, offsetof(struct cacheFile, opti));
array(char *)** ____BAH_COMPILER_VAR_316 = (array(char *)**)((char*)(____BAH_COMPILER_VAR_302) + offsetof(struct cacheFile, files));
char ** ____BAH_COMPILER_VAR_317 = 0;
struct reflectElement ____BAH_COMPILER_VAR_318 = __reflect(____BAH_COMPILER_VAR_317, sizeof(char *), "cpstring", "", 0, 0, 0, 0, 0);

        struct reflectElement ____BAH_COMPILER_VAR_319 = ____BAH_COMPILER_VAR_318;
        struct reflectElement ____BAH_COMPILER_VAR_320 = __reflect(____BAH_COMPILER_VAR_316, sizeof(array(char *)*), "[]cpstring", "files", 1, &____BAH_COMPILER_VAR_319, 0, 0, offsetof(struct cacheFile, files));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_303 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_303->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_303->length = 7;
        ____BAH_COMPILER_VAR_303->data = memoryAlloc(____BAH_COMPILER_VAR_303->length * ____BAH_COMPILER_VAR_303->elemSize);
        ____BAH_COMPILER_VAR_303->data[0] = ____BAH_COMPILER_VAR_305;
____BAH_COMPILER_VAR_303->data[1] = ____BAH_COMPILER_VAR_307;
____BAH_COMPILER_VAR_303->data[2] = ____BAH_COMPILER_VAR_309;
____BAH_COMPILER_VAR_303->data[3] = ____BAH_COMPILER_VAR_311;
____BAH_COMPILER_VAR_303->data[4] = ____BAH_COMPILER_VAR_313;
____BAH_COMPILER_VAR_303->data[5] = ____BAH_COMPILER_VAR_315;
____BAH_COMPILER_VAR_303->data[6] = ____BAH_COMPILER_VAR_320;
struct reflectElement ____BAH_COMPILER_VAR_321 = __reflect(____BAH_COMPILER_VAR_302, sizeof(struct cacheFile), "cacheFile*", "", 0, 0, 1, ____BAH_COMPILER_VAR_303, 0);

        struct reflectElement ____BAH_COMPILER_VAR_322 = ____BAH_COMPILER_VAR_321;
        struct reflectElement ____BAH_COMPILER_VAR_323 = __reflect(____BAH_COMPILER_VAR_301, sizeof(array(struct cacheFile*)*), "[]cacheFile*", "cache", 1, &____BAH_COMPILER_VAR_322, 0, 0, 0);
char * ____BAH_COMPILER_VAR_324 =toJson(____BAH_COMPILER_VAR_323);fileStream__writeFile(&fs,____BAH_COMPILER_VAR_324);
fileStream__close(&fs);

#undef fs
};
char isValidCacheFile(struct cacheFile* cf){
if ((cf==null)||(cf->last!=getLastModified(cf->file))) {
return false;
}
char * ____BAH_COMPILER_VAR_325 =null;char * ____BAH_COMPILER_VAR_326 =intToStr(cf->opti);char * ____BAH_COMPILER_VAR_327 =intToStr(cf->mem);char * ____BAH_COMPILER_VAR_328 =pathToVarName(cf->file);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_326);
unsigned int strLen_1 = strlen(".o.o");
unsigned int strLen_2 = strlen(____BAH_COMPILER_VAR_327);
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_328);
unsigned int strLen_4 = strlen("cache/");
unsigned int strLen_5 = strlen(BAH_DIR);
;                            
            ____BAH_COMPILER_VAR_325 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_325+currStrOff, BAH_DIR, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_325+currStrOff, "cache/", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_325+currStrOff, ____BAH_COMPILER_VAR_328, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_325+currStrOff, ____BAH_COMPILER_VAR_327, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_325+currStrOff, ____BAH_COMPILER_VAR_326, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_325+currStrOff, ".o.o", strLen_1);
            currStrOff += strLen_1;
        
        }if ((fileExists(____BAH_COMPILER_VAR_325)==0)) {
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

                struct string ____BAH_COMPILER_VAR_329 = getCType(v->type,elems);
                char * ____BAH_COMPILER_VAR_330 =null;char * ____BAH_COMPILER_VAR_331 =string__str(&____BAH_COMPILER_VAR_329);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(val);
unsigned int strLen_1 = strlen(";\n        }\n    }\n    ");
unsigned int strLen_2 = strlen(preVal);
unsigned int strLen_3 = strlen("->length = nLength+1;\n        } else {\n            ");
unsigned int strLen_4 = strlen(nstr);
unsigned int strLen_5 = strlen(";\n            ");
unsigned int strLen_6 = strlen(val);
unsigned int strLen_7 = strlen("->data = newPtr;\n            }\n            ");
unsigned int strLen_8 = strlen(nstr);
unsigned int strLen_9 = strlen("));\n                ");
unsigned int strLen_10 = strlen(____BAH_COMPILER_VAR_331);
unsigned int strLen_11 = strlen("->realLength)*sizeof(");
unsigned int strLen_12 = strlen(nstr);
unsigned int strLen_13 = strlen("->data, (");
unsigned int strLen_14 = strlen(nstr);
unsigned int strLen_15 = strlen("->realLength = 50;\n                }\n                void * newPtr = memoryRealloc(");
unsigned int strLen_16 = strlen(nstr);
unsigned int strLen_17 = strlen("->realLength *= 2;\n                } else {\n                    ");
unsigned int strLen_18 = strlen(nstr);
unsigned int strLen_19 = strlen("->realLength != 0) {\n                    ");
unsigned int strLen_20 = strlen(nstr);
unsigned int strLen_21 = strlen("->realLength) {\n                if (");
unsigned int strLen_22 = strlen(nstr);
unsigned int strLen_23 = strlen("->length) {\n            if (nLength >= ");
unsigned int strLen_24 = strlen(nstr);
unsigned int strLen_25 = strlen(";\n        if (nLength >= ");
unsigned int strLen_26 = strlen(nLengthStr);
unsigned int strLen_27 = strlen("\n    {\n        unsigned long nLength = ");
;                            
            ____BAH_COMPILER_VAR_330 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13+strLen_14+strLen_15+strLen_16+strLen_17+strLen_18+strLen_19+strLen_20+strLen_21+strLen_22+strLen_23+strLen_24+strLen_25+strLen_26+strLen_27);
            
                    memcpy(____BAH_COMPILER_VAR_330+currStrOff, "\n    {\n        unsigned long nLength = ", strLen_27);
                    currStrOff += strLen_27;
                    
                    memcpy(____BAH_COMPILER_VAR_330+currStrOff, nLengthStr, strLen_26);
                    currStrOff += strLen_26;
                    
                    memcpy(____BAH_COMPILER_VAR_330+currStrOff, ";\n        if (nLength >= ", strLen_25);
                    currStrOff += strLen_25;
                    
                    memcpy(____BAH_COMPILER_VAR_330+currStrOff, nstr, strLen_24);
                    currStrOff += strLen_24;
                    
                    memcpy(____BAH_COMPILER_VAR_330+currStrOff, "->length) {\n            if (nLength >= ", strLen_23);
                    currStrOff += strLen_23;
                    
                    memcpy(____BAH_COMPILER_VAR_330+currStrOff, nstr, strLen_22);
                    currStrOff += strLen_22;
                    
                    memcpy(____BAH_COMPILER_VAR_330+currStrOff, "->realLength) {\n                if (", strLen_21);
                    currStrOff += strLen_21;
                    
                    memcpy(____BAH_COMPILER_VAR_330+currStrOff, nstr, strLen_20);
                    currStrOff += strLen_20;
                    
                    memcpy(____BAH_COMPILER_VAR_330+currStrOff, "->realLength != 0) {\n                    ", strLen_19);
                    currStrOff += strLen_19;
                    
                    memcpy(____BAH_COMPILER_VAR_330+currStrOff, nstr, strLen_18);
                    currStrOff += strLen_18;
                    
                    memcpy(____BAH_COMPILER_VAR_330+currStrOff, "->realLength *= 2;\n                } else {\n                    ", strLen_17);
                    currStrOff += strLen_17;
                    
                    memcpy(____BAH_COMPILER_VAR_330+currStrOff, nstr, strLen_16);
                    currStrOff += strLen_16;
                    
                    memcpy(____BAH_COMPILER_VAR_330+currStrOff, "->realLength = 50;\n                }\n                void * newPtr = memoryRealloc(", strLen_15);
                    currStrOff += strLen_15;
                    
                    memcpy(____BAH_COMPILER_VAR_330+currStrOff, nstr, strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_330+currStrOff, "->data, (", strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_330+currStrOff, nstr, strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_330+currStrOff, "->realLength)*sizeof(", strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_330+currStrOff, ____BAH_COMPILER_VAR_331, strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_330+currStrOff, "));\n                ", strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_330+currStrOff, nstr, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_330+currStrOff, "->data = newPtr;\n            }\n            ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_330+currStrOff, val, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_330+currStrOff, ";\n            ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_330+currStrOff, nstr, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_330+currStrOff, "->length = nLength+1;\n        } else {\n            ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_330+currStrOff, preVal, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_330+currStrOff, val, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_330+currStrOff, ";\n        }\n    }\n    ", strLen_1);
            currStrOff += strLen_1;
        
        }return ____BAH_COMPILER_VAR_330;
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

                struct string ____BAH_COMPILER_VAR_332 = string(v->name);
                if ((isRCPpointerType(v->type)==false)&&(strcmp(v->type, "reflectElement") != 0)&&(string__hasPrefix(&____BAH_COMPILER_VAR_332,"____BAH_COMPILER_VAR_")==false)) {
struct cStruct* s = searchStruct(v->type,elems);
if ((s!=null)&&(currentFn!=null)) {
char * ____BAH_COMPILER_VAR_333 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(v->type);
unsigned int strLen_1 = strlen(") could be passed by reference.");
unsigned int strLen_2 = strlen("\e[0m (");
unsigned int strLen_3 = strlen(v->name);
unsigned int strLen_4 = strlen("()\e[0m: argument \e[1;37m");
unsigned int strLen_5 = strlen(currentFn->name);
unsigned int strLen_6 = strlen("in \e[1;37m");
;                            
            ____BAH_COMPILER_VAR_333 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_333+currStrOff, "in \e[1;37m", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_333+currStrOff, currentFn->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_333+currStrOff, "()\e[0m: argument \e[1;37m", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_333+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_333+currStrOff, "\e[0m (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_333+currStrOff, v->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_333+currStrOff, ") could be passed by reference.", strLen_1);
            currStrOff += strLen_1;
        
        }throwNoticeLine(____BAH_COMPILER_VAR_333,currentFn->line);
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
char * ____BAH_COMPILER_VAR_334 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t.cont);
unsigned int strLen_1 = strlen("'");
unsigned int strLen_2 = strlen(" '");
unsigned int strLen_3 = strlen(cont);
;                            
            ____BAH_COMPILER_VAR_334 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_334+currStrOff, cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_334+currStrOff, " '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_334+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_334+currStrOff, "'", strLen_1);
            currStrOff += strLen_1;
        
        }cont = ____BAH_COMPILER_VAR_334;
++i;
};
println(cont);
};
struct Elems* dupElems(struct Elems* elems){
struct Elems* ____BAH_COMPILER_VAR_335 = memoryAlloc(sizeof(struct Elems));
____BAH_COMPILER_VAR_335->vars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_335->vars->length = 0;
            ____BAH_COMPILER_VAR_335->vars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_335->structs = memoryAlloc(sizeof(array(struct cStruct*)));
            ____BAH_COMPILER_VAR_335->structs->length = 0;
            ____BAH_COMPILER_VAR_335->structs->elemSize = sizeof(struct cStruct*);
            ____BAH_COMPILER_VAR_335->types = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_335->types->length = 0;
            ____BAH_COMPILER_VAR_335->types->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_335->fns = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_335->fns->length = 0;
            ____BAH_COMPILER_VAR_335->fns->elemSize = sizeof(struct func*);
            ____BAH_COMPILER_VAR_335->defined = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_335->defined->length = 0;
            ____BAH_COMPILER_VAR_335->defined->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_335->parent= null;
____BAH_COMPILER_VAR_335->branchChecks = memoryAlloc(sizeof(array(struct varCheck)));
            ____BAH_COMPILER_VAR_335->branchChecks->length = 0;
            ____BAH_COMPILER_VAR_335->branchChecks->elemSize = sizeof(struct varCheck);
            struct Elems* nElems = ____BAH_COMPILER_VAR_335;
nElems->parent = elems;
allocateArray(nElems->vars,len(elems->vars));
register long int j = 0;
for (; (j<len(elems->vars)); ++j) {

    {
        unsigned long nLength = j;
        if (nLength >= nElems->vars->length) {
            if (nLength >= nElems->vars->realLength) {
                if (nElems->vars->realLength != 0) {
                    nElems->vars->realLength *= 2;
                } else {
                    nElems->vars->realLength = 50;
                }
                void * newPtr = memoryRealloc(nElems->vars->data, (nElems->vars->realLength)*sizeof(struct variable*));
                nElems->vars->data = newPtr;
            }
            nElems->vars->data[j] = elems->vars->data[j];
            nElems->vars->length = nLength+1;
        } else {
            nElems->vars->data[j] = elems->vars->data[j];
        }
    }
    ;
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

                struct string ____BAH_COMPILER_VAR_336 = string(compilerState.currentDir);
                if ((isUnsafe==false)&&(string__hasPrefix(&____BAH_COMPILER_VAR_336,BAH_DIR)==false)&&isRCPpointerType(tt)&&(t->cont[0]!=38)&&(t->cont[0]!=42)) {
struct variable* sv = searchVarByToken(t,elems);
if ((sv!=null)) {
if ((sv->canBeNull==true)&&(checkedNotNull(sv->name,elems)==false)) {
char * globCheck = "";
struct cStruct* s = searchStruct(sv->type,elems);
if ((sv->isGlobal==true)&&(s!=null)) {
char * ____BAH_COMPILER_VAR_337 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s->name);
unsigned int strLen_1 = strlen("'.");
unsigned int strLen_2 = strlen(" or declare the var as 'new ");
;                            
            ____BAH_COMPILER_VAR_337 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_337+currStrOff, " or declare the var as 'new ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_337+currStrOff, s->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_337+currStrOff, "'.", strLen_1);
            currStrOff += strLen_1;
        
        }globCheck = ____BAH_COMPILER_VAR_337;
}
char * ____BAH_COMPILER_VAR_338 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(globCheck);
unsigned int strLen_1 = strlen(".");
unsigned int strLen_2 = strlen("{TOKEN} can contain a null value. Check if the value is null");
;                            
            ____BAH_COMPILER_VAR_338 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_338+currStrOff, "{TOKEN} can contain a null value. Check if the value is null", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_338+currStrOff, globCheck, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_338+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(t,____BAH_COMPILER_VAR_338);
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

    {
        unsigned long nLength = i;
        if (nLength >= nl->length) {
            if (nLength >= nl->realLength) {
                if (nl->realLength != 0) {
                    nl->realLength *= 2;
                } else {
                    nl->realLength = 50;
                }
                void * newPtr = memoryRealloc(nl->data, (nl->realLength)*sizeof(struct Tok));
                nl->data = newPtr;
            }
            nl->data[i] = t;
            nl->length = nLength+1;
        } else {
            nl->data[i] = t;
        }
    }
    ;
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
char * ____BAH_COMPILER_VAR_339 =string__str(&tc);struct string cCast = getCType(____BAH_COMPILER_VAR_339,elems);
char * cCastStr = string__str(&cCast);
char * ____BAH_COMPILER_VAR_340 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(")");
unsigned int strLen_1 = strlen(nnnt.cont);
unsigned int strLen_2 = strlen(cCastStr);
unsigned int strLen_3 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_340 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_340+currStrOff, "(", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_340+currStrOff, cCastStr, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_340+currStrOff, ")", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_340+currStrOff, nnnt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }nnnt.cont = ____BAH_COMPILER_VAR_340;

    {
        unsigned long nLength = len(nl);
        if (nLength >= nl->length) {
            if (nLength >= nl->realLength) {
                if (nl->realLength != 0) {
                    nl->realLength *= 2;
                } else {
                    nl->realLength = 50;
                }
                void * newPtr = memoryRealloc(nl->data, (nl->realLength)*sizeof(struct Tok));
                nl->data = newPtr;
            }
            nl->data[len(nl)] = nnnt;
            nl->length = nLength+1;
        } else {
            nl->data[len(nl)] = nnnt;
        }
    }
    ;
i = i+2;
continue;
}
}

    {
        unsigned long nLength = len(nl);
        if (nLength >= nl->length) {
            if (nLength >= nl->realLength) {
                if (nl->realLength != 0) {
                    nl->realLength *= 2;
                } else {
                    nl->realLength = 50;
                }
                void * newPtr = memoryRealloc(nl->data, (nl->realLength)*sizeof(struct Tok));
                nl->data = newPtr;
            }
            nl->data[len(nl)] = t;
            nl->length = nLength+1;
        } else {
            nl->data[len(nl)] = t;
        }
    }
    ;
};
return nl;
};
char * getDirFromFile(char * f){
char * ____BAH_COMPILER_VAR_341 =__STR(f);array(char)* p = strAsArr(____BAH_COMPILER_VAR_341);
register long int i = len(p)-1;
while ((i>=0)) {
char c = p->data[i];
if ((c==47)) {

    {
        unsigned long nLength = i+1;
        if (nLength >= p->length) {
            if (nLength >= p->realLength) {
                if (p->realLength != 0) {
                    p->realLength *= 2;
                } else {
                    p->realLength = 50;
                }
                void * newPtr = memoryRealloc(p->data, (p->realLength)*sizeof(char));
                p->data = newPtr;
            }
            p->data[i+1] = (char)0;
            p->length = nLength+1;
        } else {
            p->data[i+1] = (char)0;
        }
    }
    ;
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

        char ____BAH_COMPILER_VAR_342 = 0;
        for(int i=compilerState.includes->length-1; i!=-1;i--) {
            if (compilerState.includes->data[i] != 0 && strcmp(compilerState.includes->data[i], ccstr) == 0) {
                ____BAH_COMPILER_VAR_342=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_342) {
return true;
}
struct fileMap ____BAH_COMPILER_VAR_343 = {};
____BAH_COMPILER_VAR_343.handle = -1;
____BAH_COMPILER_VAR_343.p= null;
#define fm ____BAH_COMPILER_VAR_343
char * ____BAH_COMPILER_VAR_344 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(BAH_DIR);
unsigned int strLen_1 = strlen(ccstr);
;                            
            ____BAH_COMPILER_VAR_344 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_344+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_344+currStrOff, ccstr, strLen_1);
            currStrOff += strLen_1;
        
        }char * fileName = ____BAH_COMPILER_VAR_344;
char isBahDir = true;
char * f = fileMap__open(&fm,fileName);
if ((fileMap__isValid(&fm)==0)) {
char * ____BAH_COMPILER_VAR_345 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(compilerState.currentDir);
unsigned int strLen_1 = strlen(ccstr);
;                            
            ____BAH_COMPILER_VAR_345 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_345+currStrOff, compilerState.currentDir, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_345+currStrOff, ccstr, strLen_1);
            currStrOff += strLen_1;
        
        }fileName = absPath(____BAH_COMPILER_VAR_345);
f = fileMap__open(&fm,fileName);
isBahDir = false;
if ((fileMap__isValid(&fm)==0)) {
return false;
}
}
char * oDir = compilerState.currentDir;
if ((isBahDir==false)) {
char * ____BAH_COMPILER_VAR_346 =null;char * ____BAH_COMPILER_VAR_347 =getDirFromFile(ccstr);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(compilerState.currentDir);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_347);
;                            
            ____BAH_COMPILER_VAR_346 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_346+currStrOff, compilerState.currentDir, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_346+currStrOff, ____BAH_COMPILER_VAR_347, strLen_1);
            currStrOff += strLen_1;
        
        }compilerState.currentDir = ____BAH_COMPILER_VAR_346;
}
else {
char * ____BAH_COMPILER_VAR_348 =null;char * ____BAH_COMPILER_VAR_349 =getDirFromFile(ccstr);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(BAH_DIR);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_349);
;                            
            ____BAH_COMPILER_VAR_348 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_348+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_348+currStrOff, ____BAH_COMPILER_VAR_349, strLen_1);
            currStrOff += strLen_1;
        
        }compilerState.currentDir = ____BAH_COMPILER_VAR_348;
}
char * oFile = compilerState.currentFile;
compilerState.currentFile = fileName;

    {
        unsigned long nLength = len(compilerState.includes);
        if (nLength >= compilerState.includes->length) {
            if (nLength >= compilerState.includes->realLength) {
                if (compilerState.includes->realLength != 0) {
                    compilerState.includes->realLength *= 2;
                } else {
                    compilerState.includes->realLength = 50;
                }
                void * newPtr = memoryRealloc(compilerState.includes->data, (compilerState.includes->realLength)*sizeof(char *));
                compilerState.includes->data = newPtr;
            }
            compilerState.includes->data[len(compilerState.includes)] = ccstr;
            compilerState.includes->length = nLength+1;
        } else {
            compilerState.includes->data[len(compilerState.includes)] = ccstr;
        }
    }
    ;
array(struct Tok)* tokens = lexer(f);
fileMap__close(&fm);
if ((len(tokens)==0)) {
char * ____BAH_COMPILER_VAR_350 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ccstr);
unsigned int strLen_1 = strlen("' not recognized.");
unsigned int strLen_2 = strlen("File '");
;                            
            ____BAH_COMPILER_VAR_350 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_350+currStrOff, "File '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_350+currStrOff, ccstr, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_350+currStrOff, "' not recognized.", strLen_1);
            currStrOff += strLen_1;
        
        }__BAH_panic(____BAH_COMPILER_VAR_350,"/home/alois/Documents/bah-bah/src/parser.bah:250");
}
char oshd = shouldOnlyDecl;
if ((isObject==true)) {

                struct string ____BAH_COMPILER_VAR_351 = string(compilerState.currentFile);
                if ((isBahDir==true)||(string__hasPrefix(&____BAH_COMPILER_VAR_351,oDir)==false)) {
shouldOnlyDecl = true;
}
else {
shouldOnlyDecl = false;
}
}
else if ((isSubObject==true)) {

                struct string ____BAH_COMPILER_VAR_352 = string(compilerState.currentFile);
                if ((isBahDir==true)||(string__hasPrefix(&____BAH_COMPILER_VAR_352,oDir)==false)) {
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
if ((cf!=null)&&(isValidCacheFile(cf)==false)) {
setCurrentPath(compilerState.currentDir);
char * verboseCC = "";
if ((flags__isSet(&flags,"verboseCC")==1)) {
verboseCC = "-verboseCC";
}
if ((debug==false)) {
char * ____BAH_COMPILER_VAR_353 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fn);
unsigned int strLen_1 = strlen("...");
unsigned int strLen_2 = strlen("compilling: ");
;                            
            ____BAH_COMPILER_VAR_353 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_353+currStrOff, "compilling: ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_353+currStrOff, fn, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_353+currStrOff, "...", strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_353);
}
char * opti = "";
if ((isOptimized==true)) {
opti = "-optimize";
}
char * ____BAH_COMPILER_VAR_354 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(" -o ");
unsigned int strLen_1 = strlen(oName);
unsigned int strLen_2 = strlen(verboseCC);
unsigned int strLen_3 = strlen(" -object ");
unsigned int strLen_4 = strlen(opti);
unsigned int strLen_5 = strlen(" ");
unsigned int strLen_6 = strlen(rcp);
unsigned int strLen_7 = strlen(" ");
unsigned int strLen_8 = strlen(fn);
unsigned int strLen_9 = strlen(" ");
unsigned int strLen_10 = strlen(execName);
;                            
            ____BAH_COMPILER_VAR_354 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10);
            
                    memcpy(____BAH_COMPILER_VAR_354+currStrOff, execName, strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_354+currStrOff, " ", strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_354+currStrOff, fn, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_354+currStrOff, " ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_354+currStrOff, rcp, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_354+currStrOff, " ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_354+currStrOff, opti, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_354+currStrOff, " -object ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_354+currStrOff, verboseCC, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_354+currStrOff, " -o ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_354+currStrOff, oName, strLen_1);
            currStrOff += strLen_1;
        
        }struct command cmd = command(____BAH_COMPILER_VAR_354);
array(char)* res = command__runBytes(&cmd);
if ((debug==false)) {
char * ____BAH_COMPILER_VAR_355 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("done: ");
unsigned int strLen_1 = strlen(fn);
;                            
            ____BAH_COMPILER_VAR_355 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_355+currStrOff, "done: ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_355+currStrOff, fn, strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_355);
}
setCurrentPath(wrkd);
if ((cmd.status!=0)) {
char * ____BAH_COMPILER_VAR_356 =arrToStr(res);print(____BAH_COMPILER_VAR_356);
exit(1);
}
if ((cf==null)) {
makeCacheFile(fn);
}
else {
updateCacheFile(cf);
}
}

        char ____BAH_COMPILER_VAR_357 = true;
        channel__sendAny(done, &____BAH_COMPILER_VAR_357, sizeof(____BAH_COMPILER_VAR_357));
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

        char ____BAH_COMPILER_VAR_358 = 0;
        for(int i=compilerState.includes->length-1; i!=-1;i--) {
            if (compilerState.includes->data[i] != 0 && strcmp(compilerState.includes->data[i], string__str(&fileName)) == 0) {
                ____BAH_COMPILER_VAR_358=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_358) {
return;
}

    {
        unsigned long nLength = len(compilerState.includes);
        if (nLength >= compilerState.includes->length) {
            if (nLength >= compilerState.includes->realLength) {
                if (compilerState.includes->realLength != 0) {
                    compilerState.includes->realLength *= 2;
                } else {
                    compilerState.includes->realLength = 50;
                }
                void * newPtr = memoryRealloc(compilerState.includes->data, (compilerState.includes->realLength)*sizeof(char *));
                compilerState.includes->data = newPtr;
            }
            compilerState.includes->data[len(compilerState.includes)] = string__str(&fileName);
            compilerState.includes->length = nLength+1;
        } else {
            compilerState.includes->data[len(compilerState.includes)] = string__str(&fileName);
        }
    }
    ;
char * ____BAH_COMPILER_VAR_359 =null;char * ____BAH_COMPILER_VAR_360 =string__str(&fileName);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(compilerState.currentDir);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_360);
;                            
            ____BAH_COMPILER_VAR_359 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_359+currStrOff, compilerState.currentDir, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_359+currStrOff, ____BAH_COMPILER_VAR_360, strLen_1);
            currStrOff += strLen_1;
        
        }char * fn = absPath(____BAH_COMPILER_VAR_359);
if (((void *)fn==null)) {
char * ____BAH_COMPILER_VAR_361 =null;char * ____BAH_COMPILER_VAR_362 =string__str(&fileName);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(BAH_DIR);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_362);
;                            
            ____BAH_COMPILER_VAR_361 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_361+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_361+currStrOff, ____BAH_COMPILER_VAR_362, strLen_1);
            currStrOff += strLen_1;
        
        }fn = absPath(____BAH_COMPILER_VAR_361);
if (((void *)fn==null)) {
throwErr(&strt,"Unknown file {TOKEN}.");
}
}
char * of = compilerState.currentFile;
char * od = compilerState.currentDir;
compilerState.currentFile = fn;
compilerState.currentDir = getDirFromFile(fn);
struct fileStream ____BAH_COMPILER_VAR_363 = {};
____BAH_COMPILER_VAR_363.handle= null;
____BAH_COMPILER_VAR_363.name= null;
#define fs ____BAH_COMPILER_VAR_363
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
char * ____BAH_COMPILER_VAR_364 =null;char * ____BAH_COMPILER_VAR_365 =intToStr(isOptimized);char * ____BAH_COMPILER_VAR_366 =intToStr(RCPlevel);char * ____BAH_COMPILER_VAR_367 =pathToVarName(fn);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_365);
unsigned int strLen_1 = strlen(".o");
unsigned int strLen_2 = strlen(____BAH_COMPILER_VAR_366);
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_367);
unsigned int strLen_4 = strlen("cache/");
unsigned int strLen_5 = strlen(BAH_DIR);
;                            
            ____BAH_COMPILER_VAR_364 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_364+currStrOff, BAH_DIR, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_364+currStrOff, "cache/", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_364+currStrOff, ____BAH_COMPILER_VAR_367, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_364+currStrOff, ____BAH_COMPILER_VAR_366, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_364+currStrOff, ____BAH_COMPILER_VAR_365, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_364+currStrOff, ".o", strLen_1);
            currStrOff += strLen_1;
        
        }char * oName = ____BAH_COMPILER_VAR_364;
char * ____BAH_COMPILER_VAR_368 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(oName);
unsigned int strLen_1 = strlen(".o");
unsigned int strLen_2 = strlen("w ");
;                            
            ____BAH_COMPILER_VAR_368 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_368+currStrOff, "w ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_368+currStrOff, oName, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_368+currStrOff, ".o", strLen_1);
            currStrOff += strLen_1;
        
        }
    {
        unsigned long nLength = len(compilerState.cLibs);
        if (nLength >= compilerState.cLibs->length) {
            if (nLength >= compilerState.cLibs->realLength) {
                if (compilerState.cLibs->realLength != 0) {
                    compilerState.cLibs->realLength *= 2;
                } else {
                    compilerState.cLibs->realLength = 50;
                }
                void * newPtr = memoryRealloc(compilerState.cLibs->data, (compilerState.cLibs->realLength)*sizeof(char *));
                compilerState.cLibs->data = newPtr;
            }
            compilerState.cLibs->data[len(compilerState.cLibs)] = ____BAH_COMPILER_VAR_368;
            compilerState.cLibs->length = nLength+1;
        } else {
            compilerState.cLibs->data[len(compilerState.cLibs)] = ____BAH_COMPILER_VAR_368;
        }
    }
    ;
struct channel * done = channel();
parallelObjCompile(fn,oName,done);
parseLines(tokens,elems);
char ok = *(char*)channel__receive(done);
char * ____BAH_COMPILER_VAR_369 =null;char * ____BAH_COMPILER_VAR_370 =pathToVarName(fn);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_370);
unsigned int strLen_1 = strlen("();\n");
unsigned int strLen_2 = strlen("__BAH_init");
;                            
            ____BAH_COMPILER_VAR_369 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_369+currStrOff, "__BAH_init", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_369+currStrOff, ____BAH_COMPILER_VAR_370, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_369+currStrOff, "();\n", strLen_1);
            currStrOff += strLen_1;
        
        }INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_369));
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
char * ____BAH_COMPILER_VAR_371 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(sc);
unsigned int strLen_1 = strlen("\n");
unsigned int strLen_2 = strlen("#include ");
;                            
            ____BAH_COMPILER_VAR_371 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_371+currStrOff, "#include ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_371+currStrOff, sc, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_371+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_371));

    {
        unsigned long nLength = len(compilerState.cIncludes);
        if (nLength >= compilerState.cIncludes->length) {
            if (nLength >= compilerState.cIncludes->realLength) {
                if (compilerState.cIncludes->realLength != 0) {
                    compilerState.cIncludes->realLength *= 2;
                } else {
                    compilerState.cIncludes->realLength = 50;
                }
                void * newPtr = memoryRealloc(compilerState.cIncludes->data, (compilerState.cIncludes->realLength)*sizeof(char *));
                compilerState.cIncludes->data = newPtr;
            }
            compilerState.cIncludes->data[len(compilerState.cIncludes)] = sc;
            compilerState.cIncludes->length = nLength+1;
        } else {
            compilerState.cIncludes->data[len(compilerState.cIncludes)] = sc;
        }
    }
    ;
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

    {
        unsigned long nLength = len(nl);
        if (nLength >= nl->length) {
            if (nLength >= nl->realLength) {
                if (nl->realLength != 0) {
                    nl->realLength *= 2;
                } else {
                    nl->realLength = 50;
                }
                void * newPtr = memoryRealloc(nl->data, (nl->realLength)*sizeof(struct Tok));
                nl->data = newPtr;
            }
            nl->data[len(nl)] = t;
            nl->length = nLength+1;
        } else {
            nl->data[len(nl)] = t;
        }
    }
    ;
++i;
continue;
}
++i;
struct Tok ____BAH_COMPILER_VAR_372 = {};
____BAH_COMPILER_VAR_372.cont = "";
____BAH_COMPILER_VAR_372.ogCont = "";
____BAH_COMPILER_VAR_372.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_372.pos = 0;
____BAH_COMPILER_VAR_372.line = 1;
____BAH_COMPILER_VAR_372.begLine = 1;
____BAH_COMPILER_VAR_372.bahType = "";
____BAH_COMPILER_VAR_372.isValue = false;
____BAH_COMPILER_VAR_372.isFunc = false;
____BAH_COMPILER_VAR_372.isOper = false;
____BAH_COMPILER_VAR_372.isEqual = false;
____BAH_COMPILER_VAR_372.pass = false;
____BAH_COMPILER_VAR_372.bahRef= null;
____BAH_COMPILER_VAR_372.parent= null;
____BAH_COMPILER_VAR_372.cont = "";
#define nt ____BAH_COMPILER_VAR_372
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
struct variable* ____BAH_COMPILER_VAR_373 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_373->name = "";
____BAH_COMPILER_VAR_373->type = "";
____BAH_COMPILER_VAR_373->isConst = false;
____BAH_COMPILER_VAR_373->constVal = "";
____BAH_COMPILER_VAR_373->isArray = false;
____BAH_COMPILER_VAR_373->from = "";
____BAH_COMPILER_VAR_373->declScope= null;
____BAH_COMPILER_VAR_373->isGlobal = false;
____BAH_COMPILER_VAR_373->declRope= null;
____BAH_COMPILER_VAR_373->canBeNull = false;
____BAH_COMPILER_VAR_373->isReg = false;
____BAH_COMPILER_VAR_373->lastSet= null;
____BAH_COMPILER_VAR_373->isArg = false;
struct variable* tmpV = ____BAH_COMPILER_VAR_373;
tmpV->name = t.cont;
char * ____BAH_COMPILER_VAR_374 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s->name);
unsigned int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_374 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_374+currStrOff, s->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_374+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }tmpV->type = ____BAH_COMPILER_VAR_374;
struct string cType = getCType(tmpV->type,elems);
struct string structType = getCType(s->name,elems);

    {
        unsigned long nLength = len(elems->vars);
        if (nLength >= elems->vars->length) {
            if (nLength >= elems->vars->realLength) {
                if (elems->vars->realLength != 0) {
                    elems->vars->realLength *= 2;
                } else {
                    elems->vars->realLength = 50;
                }
                void * newPtr = memoryRealloc(elems->vars->data, (elems->vars->realLength)*sizeof(struct variable*));
                elems->vars->data = newPtr;
            }
            elems->vars->data[len(elems->vars)] = tmpV;
            elems->vars->length = nLength+1;
        } else {
            elems->vars->data[len(elems->vars)] = tmpV;
        }
    }
    ;
char * ____BAH_COMPILER_VAR_375 =null;char * ____BAH_COMPILER_VAR_376 =declareStructMethods(tmpV,s,elems);char * ____BAH_COMPILER_VAR_377 =string__str(&structType);char * ____BAH_COMPILER_VAR_378 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("));\n");
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_376);
unsigned int strLen_2 = strlen(____BAH_COMPILER_VAR_377);
unsigned int strLen_3 = strlen(" = memoryAlloc(sizeof(");
unsigned int strLen_4 = strlen(t.cont);
unsigned int strLen_5 = strlen(" ");
unsigned int strLen_6 = strlen(____BAH_COMPILER_VAR_378);
;                            
            ____BAH_COMPILER_VAR_375 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_375+currStrOff, ____BAH_COMPILER_VAR_378, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_375+currStrOff, " ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_375+currStrOff, t.cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_375+currStrOff, " = memoryAlloc(sizeof(", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_375+currStrOff, ____BAH_COMPILER_VAR_377, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_375+currStrOff, "));\n", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_375+currStrOff, ____BAH_COMPILER_VAR_376, strLen_1);
            currStrOff += strLen_1;
        
        }struct rope* r = rope(____BAH_COMPILER_VAR_375);
if (isGlobal()) {
INIT = rope__add(INIT, r);
}
else {
OUTPUT = rope__add(OUTPUT, r);
}

    {
        unsigned long nLength = len(nl)-1;
        if (nLength >= nl->length) {
            if (nLength >= nl->realLength) {
                if (nl->realLength != 0) {
                    nl->realLength *= 2;
                } else {
                    nl->realLength = 50;
                }
                void * newPtr = memoryRealloc(nl->data, (nl->realLength)*sizeof(struct Tok));
                nl->data = newPtr;
            }
            nl->data[len(nl)-1] = t;
            nl->length = nLength+1;
        } else {
            nl->data[len(nl)-1] = t;
        }
    }
    ;
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

    {
        unsigned long nLength = len(memory);
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(struct Tok));
                memory->data = newPtr;
            }
            memory->data[len(memory)] = t;
            memory->length = nLength+1;
        } else {
            memory->data[len(memory)] = t;
        }
    }
    ;
};
if ((len(memory)>0)) {
memory = prePross(memory,(lineType)-1,elems);
}
long int declType = 0;
char * rvn = genCompilerVar();
struct variable* ____BAH_COMPILER_VAR_379 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_379->name = "";
____BAH_COMPILER_VAR_379->type = "";
____BAH_COMPILER_VAR_379->isConst = false;
____BAH_COMPILER_VAR_379->constVal = "";
____BAH_COMPILER_VAR_379->isArray = false;
____BAH_COMPILER_VAR_379->from = "";
____BAH_COMPILER_VAR_379->declScope= null;
____BAH_COMPILER_VAR_379->isGlobal = false;
____BAH_COMPILER_VAR_379->declRope= null;
____BAH_COMPILER_VAR_379->canBeNull = false;
____BAH_COMPILER_VAR_379->isReg = false;
____BAH_COMPILER_VAR_379->lastSet= null;
____BAH_COMPILER_VAR_379->isArg = false;
struct variable* tmpV = ____BAH_COMPILER_VAR_379;
tmpV->name = rvn;
if ((isHeap==true)) {
char * ____BAH_COMPILER_VAR_380 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s->name);
unsigned int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_380 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_380+currStrOff, s->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_380+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }tmpV->type = ____BAH_COMPILER_VAR_380;

    {
        unsigned long nLength = len(elems->vars);
        if (nLength >= elems->vars->length) {
            if (nLength >= elems->vars->realLength) {
                if (elems->vars->realLength != 0) {
                    elems->vars->realLength *= 2;
                } else {
                    elems->vars->realLength = 50;
                }
                void * newPtr = memoryRealloc(elems->vars->data, (elems->vars->realLength)*sizeof(struct variable*));
                elems->vars->data = newPtr;
            }
            elems->vars->data[len(elems->vars)] = tmpV;
            elems->vars->length = nLength+1;
        } else {
            elems->vars->data[len(elems->vars)] = tmpV;
        }
    }
    ;
}
else {
tmpV->type = s->name;
}
struct string rst = getCType(tmpV->type,elems);
struct rope* r= null;
if ((isHeap==true)) {
char * ____BAH_COMPILER_VAR_381 =string__str(&rst);struct string structType = string(____BAH_COMPILER_VAR_381);
string__trimRight(&structType,1);
char * ____BAH_COMPILER_VAR_382 =null;char * ____BAH_COMPILER_VAR_383 =declareStructMethods(tmpV,s,elems);char * ____BAH_COMPILER_VAR_384 =string__str(&structType);char * ____BAH_COMPILER_VAR_385 =string__str(&rst);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("));\n");
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_383);
unsigned int strLen_2 = strlen(____BAH_COMPILER_VAR_384);
unsigned int strLen_3 = strlen(" = memoryAlloc(sizeof(");
unsigned int strLen_4 = strlen(rvn);
unsigned int strLen_5 = strlen(" ");
unsigned int strLen_6 = strlen(____BAH_COMPILER_VAR_385);
;                            
            ____BAH_COMPILER_VAR_382 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_382+currStrOff, ____BAH_COMPILER_VAR_385, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_382+currStrOff, " ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_382+currStrOff, rvn, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_382+currStrOff, " = memoryAlloc(sizeof(", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_382+currStrOff, ____BAH_COMPILER_VAR_384, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_382+currStrOff, "));\n", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_382+currStrOff, ____BAH_COMPILER_VAR_383, strLen_1);
            currStrOff += strLen_1;
        
        }r = rope(____BAH_COMPILER_VAR_382);
}
else {
char * ____BAH_COMPILER_VAR_386 =null;char * ____BAH_COMPILER_VAR_387 =declareStructMethods(tmpV,s,elems);char * ____BAH_COMPILER_VAR_388 =string__str(&rst);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(" = {};\n");
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_387);
unsigned int strLen_2 = strlen(rvn);
unsigned int strLen_3 = strlen(" ");
unsigned int strLen_4 = strlen(____BAH_COMPILER_VAR_388);
;                            
            ____BAH_COMPILER_VAR_386 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_386+currStrOff, ____BAH_COMPILER_VAR_388, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_386+currStrOff, " ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_386+currStrOff, rvn, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_386+currStrOff, " = {};\n", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_386+currStrOff, ____BAH_COMPILER_VAR_387, strLen_1);
            currStrOff += strLen_1;
        
        }r = rope(____BAH_COMPILER_VAR_386);
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
char * ____BAH_COMPILER_VAR_389 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(m->type);
unsigned int strLen_1 = strlen("'.");
unsigned int strLen_2 = strlen(") as '");
unsigned int strLen_3 = strlen(vlt);
unsigned int strLen_4 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_389 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_389+currStrOff, "Cannot use {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_389+currStrOff, vlt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_389+currStrOff, ") as '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_389+currStrOff, m->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_389+currStrOff, "'.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&vl,____BAH_COMPILER_VAR_389);
}
char * ____BAH_COMPILER_VAR_390 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(vl.cont);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen(" = ");
unsigned int strLen_3 = strlen(m->name);
unsigned int strLen_4 = strlen(sep);
unsigned int strLen_5 = strlen(rvn);
;                            
            ____BAH_COMPILER_VAR_390 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_390+currStrOff, rvn, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_390+currStrOff, sep, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_390+currStrOff, m->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_390+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_390+currStrOff, vl.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_390+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }r = rope__add(r, rope(____BAH_COMPILER_VAR_390));
break;
};
if ((j==len(s->members))) {
char * ____BAH_COMPILER_VAR_391 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s->name);
unsigned int strLen_1 = strlen("' has no member called {TOKEN}.");
unsigned int strLen_2 = strlen("Struct '");
;                            
            ____BAH_COMPILER_VAR_391 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_391+currStrOff, "Struct '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_391+currStrOff, s->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_391+currStrOff, "' has no member called {TOKEN}.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&t,____BAH_COMPILER_VAR_391);
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
char * ____BAH_COMPILER_VAR_392 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(m->type);
unsigned int strLen_1 = strlen("'.");
unsigned int strLen_2 = strlen(") as '");
unsigned int strLen_3 = strlen(tt);
unsigned int strLen_4 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_392 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_392+currStrOff, "Cannot use {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_392+currStrOff, tt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_392+currStrOff, ") as '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_392+currStrOff, m->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_392+currStrOff, "'.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&t,____BAH_COMPILER_VAR_392);
}
char * ____BAH_COMPILER_VAR_393 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t.cont);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen(" = ");
unsigned int strLen_3 = strlen(m->name);
unsigned int strLen_4 = strlen(sep);
unsigned int strLen_5 = strlen(rvn);
;                            
            ____BAH_COMPILER_VAR_393 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_393+currStrOff, rvn, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_393+currStrOff, sep, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_393+currStrOff, m->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_393+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_393+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_393+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }r = rope__add(r, rope(____BAH_COMPILER_VAR_393));
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

    {
        unsigned long nLength = len(nl)-1;
        if (nLength >= nl->length) {
            if (nLength >= nl->realLength) {
                if (nl->realLength != 0) {
                    nl->realLength *= 2;
                } else {
                    nl->realLength = 50;
                }
                void * newPtr = memoryRealloc(nl->data, (nl->realLength)*sizeof(struct Tok));
                nl->data = newPtr;
            }
            nl->data[len(nl)-1] = t;
            nl->length = nLength+1;
        } else {
            nl->data[len(nl)-1] = t;
        }
    }
    ;
}
else {
t.isEqual = true;

    {
        unsigned long nLength = len(nl);
        if (nLength >= nl->length) {
            if (nLength >= nl->realLength) {
                if (nl->realLength != 0) {
                    nl->realLength *= 2;
                } else {
                    nl->realLength = 50;
                }
                void * newPtr = memoryRealloc(nl->data, (nl->realLength)*sizeof(struct Tok));
                nl->data = newPtr;
            }
            nl->data[len(nl)] = t;
            nl->length = nLength+1;
        } else {
            nl->data[len(nl)] = t;
        }
    }
    ;
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

    {
        unsigned long nLength = len(nl);
        if (nLength >= nl->length) {
            if (nLength >= nl->realLength) {
                if (nl->realLength != 0) {
                    nl->realLength *= 2;
                } else {
                    nl->realLength = 50;
                }
                void * newPtr = memoryRealloc(nl->data, (nl->realLength)*sizeof(struct Tok));
                nl->data = newPtr;
            }
            nl->data[len(nl)] = t;
            nl->length = nLength+1;
        } else {
            nl->data[len(nl)] = t;
        }
    }
    ;
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

    {
        unsigned long nLength = i;
        if (nLength >= nl->length) {
            if (nLength >= nl->realLength) {
                if (nl->realLength != 0) {
                    nl->realLength *= 2;
                } else {
                    nl->realLength = 50;
                }
                void * newPtr = memoryRealloc(nl->data, (nl->realLength)*sizeof(struct Tok));
                nl->data = newPtr;
            }
            nl->data[i] = t;
            nl->length = nLength+1;
        } else {
            nl->data[i] = t;
        }
    }
    ;
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
char * ____BAH_COMPILER_VAR_394 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(bracks);
unsigned int strLen_1 = strlen("[]");
;                            
            ____BAH_COMPILER_VAR_394 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_394+currStrOff, bracks, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_394+currStrOff, "[]", strLen_1);
            currStrOff += strLen_1;
        
        }bracks = ____BAH_COMPILER_VAR_394;
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
char * ____BAH_COMPILER_VAR_395 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(bracks);
unsigned int strLen_1 = strlen(arrElem);
;                            
            ____BAH_COMPILER_VAR_395 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_395+currStrOff, bracks, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_395+currStrOff, arrElem, strLen_1);
            currStrOff += strLen_1;
        
        }t.bahType = ____BAH_COMPILER_VAR_395;
t.cont = "";
t.isValue = true;

    {
        unsigned long nLength = len(nl);
        if (nLength >= nl->length) {
            if (nLength >= nl->realLength) {
                if (nl->realLength != 0) {
                    nl->realLength *= 2;
                } else {
                    nl->realLength = 50;
                }
                void * newPtr = memoryRealloc(nl->data, (nl->realLength)*sizeof(struct Tok));
                nl->data = newPtr;
            }
            nl->data[len(nl)] = t;
            nl->length = nLength+1;
        } else {
            nl->data[len(nl)] = t;
        }
    }
    ;
continue;
}
}
}
}

    {
        unsigned long nLength = len(nl);
        if (nLength >= nl->length) {
            if (nLength >= nl->realLength) {
                if (nl->realLength != 0) {
                    nl->realLength *= 2;
                } else {
                    nl->realLength = 50;
                }
                void * newPtr = memoryRealloc(nl->data, (nl->realLength)*sizeof(struct Tok));
                nl->data = newPtr;
            }
            nl->data[len(nl)] = t;
            nl->length = nLength+1;
        } else {
            nl->data[len(nl)] = t;
        }
    }
    ;
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
char * ____BAH_COMPILER_VAR_396 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(l->data[i-1].cont);
unsigned int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_396 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_396+currStrOff, l->data[i-1].cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_396+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }l->data[i-1].cont = ____BAH_COMPILER_VAR_396;
delete(l,i);
--i;
}
}
else {
char * ____BAH_COMPILER_VAR_397 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(l->data[i-1].cont);
unsigned int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_397 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_397+currStrOff, l->data[i-1].cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_397+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }l->data[i-1].cont = ____BAH_COMPILER_VAR_397;
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
char * ____BAH_COMPILER_VAR_398 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t.cont);
unsigned int strLen_1 = strlen(l->data[i+1].cont);
;                            
            ____BAH_COMPILER_VAR_398 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_398+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_398+currStrOff, l->data[i+1].cont, strLen_1);
            currStrOff += strLen_1;
        
        }l->data[i+1].cont = ____BAH_COMPILER_VAR_398;
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
char * ____BAH_COMPILER_VAR_399 =null;char * ____BAH_COMPILER_VAR_400 =string__str(&svt);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_400);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen("sizeof(struct ");
unsigned int strLen_3 = strlen(", ");
unsigned int strLen_4 = strlen(e->cont);
unsigned int strLen_5 = strlen("__serialize(&");
;                            
            ____BAH_COMPILER_VAR_399 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_399+currStrOff, "__serialize(&", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_399+currStrOff, e->cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_399+currStrOff, ", ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_399+currStrOff, "sizeof(struct ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_399+currStrOff, ____BAH_COMPILER_VAR_400, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_399+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_399;
}
else {
char * ptrRect = "";
while ((ptrLevel>1)) {
char * ____BAH_COMPILER_VAR_401 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ptrRect);
unsigned int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_401 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_401+currStrOff, ptrRect, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_401+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }ptrRect = ____BAH_COMPILER_VAR_401;
ptrLevel = ptrLevel-1;
};
char * ____BAH_COMPILER_VAR_402 =null;char * ____BAH_COMPILER_VAR_403 =string__str(&svt);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_403);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen("sizeof(struct ");
unsigned int strLen_3 = strlen(", ");
unsigned int strLen_4 = strlen(e->cont);
unsigned int strLen_5 = strlen(ptrRect);
unsigned int strLen_6 = strlen("__serialize(");
;                            
            ____BAH_COMPILER_VAR_402 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_402+currStrOff, "__serialize(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_402+currStrOff, ptrRect, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_402+currStrOff, e->cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_402+currStrOff, ", ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_402+currStrOff, "sizeof(struct ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_402+currStrOff, ____BAH_COMPILER_VAR_403, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_402+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_402;
register long int i = 0;
while ((i<len(s->members))) {
struct structMemb* m = s->members->data[i];
if ((strcmp(m->type, "cpstring") == 0)) {
char * ____BAH_COMPILER_VAR_404 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(m->name);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen("->");
unsigned int strLen_3 = strlen(e->cont);
unsigned int strLen_4 = strlen("+strlen(");
unsigned int strLen_5 = strlen(code);
;                            
            ____BAH_COMPILER_VAR_404 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_404+currStrOff, code, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_404+currStrOff, "+strlen(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_404+currStrOff, e->cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_404+currStrOff, "->", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_404+currStrOff, m->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_404+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_404;
}
i = i+1;
};
}
char * ____BAH_COMPILER_VAR_405 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(")");
;                            
            ____BAH_COMPILER_VAR_405 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_405+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_405+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }return ____BAH_COMPILER_VAR_405;
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
char * ____BAH_COMPILER_VAR_406 =null;char * ____BAH_COMPILER_VAR_407 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t.cont);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen(" = ");
unsigned int strLen_3 = strlen(v);
unsigned int strLen_4 = strlen(" ");
unsigned int strLen_5 = strlen(____BAH_COMPILER_VAR_407);
;                            
            ____BAH_COMPILER_VAR_406 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_406+currStrOff, ____BAH_COMPILER_VAR_407, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_406+currStrOff, " ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_406+currStrOff, v, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_406+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_406+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_406+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_406));
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
struct Tok ____BAH_COMPILER_VAR_408 = {};
____BAH_COMPILER_VAR_408.cont = "";
____BAH_COMPILER_VAR_408.ogCont = "";
____BAH_COMPILER_VAR_408.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_408.pos = 0;
____BAH_COMPILER_VAR_408.line = 1;
____BAH_COMPILER_VAR_408.begLine = 1;
____BAH_COMPILER_VAR_408.bahType = "";
____BAH_COMPILER_VAR_408.isValue = false;
____BAH_COMPILER_VAR_408.isFunc = false;
____BAH_COMPILER_VAR_408.isOper = false;
____BAH_COMPILER_VAR_408.isEqual = false;
____BAH_COMPILER_VAR_408.pass = false;
____BAH_COMPILER_VAR_408.bahRef= null;
____BAH_COMPILER_VAR_408.parent= null;
#define tmpT ____BAH_COMPILER_VAR_408
tmpT.type = TOKEN_TYPE_VAR;
tmpT.cont = "0";
char * ____BAH_COMPILER_VAR_409 =string__str(&aet);struct Tok rt = parseReflect(tmpT,____BAH_COMPILER_VAR_409,elems,true,"","0");
char * aev = genCompilerVar();
char * ____BAH_COMPILER_VAR_410 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(rt.cont);
unsigned int strLen_1 = strlen(";\n        ");
unsigned int strLen_2 = strlen(" = ");
unsigned int strLen_3 = strlen(aev);
unsigned int strLen_4 = strlen("\n        struct reflectElement ");
;                            
            ____BAH_COMPILER_VAR_410 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_410+currStrOff, "\n        struct reflectElement ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_410+currStrOff, aev, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_410+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_410+currStrOff, rt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_410+currStrOff, ";\n        ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_410));
char * ____BAH_COMPILER_VAR_411 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("&");
unsigned int strLen_1 = strlen(aev);
;                            
            ____BAH_COMPILER_VAR_411 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_411+currStrOff, "&", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_411+currStrOff, aev, strLen_1);
            currStrOff += strLen_1;
        
        }arrElem = ____BAH_COMPILER_VAR_411;

#undef tmpT
}
else if (strHasPrefix(tt,"map:")) {
struct string aet = string(tt);
string__trimLeft(&aet,4);
struct Tok ____BAH_COMPILER_VAR_412 = {};
____BAH_COMPILER_VAR_412.cont = "";
____BAH_COMPILER_VAR_412.ogCont = "";
____BAH_COMPILER_VAR_412.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_412.pos = 0;
____BAH_COMPILER_VAR_412.line = 1;
____BAH_COMPILER_VAR_412.begLine = 1;
____BAH_COMPILER_VAR_412.bahType = "";
____BAH_COMPILER_VAR_412.isValue = false;
____BAH_COMPILER_VAR_412.isFunc = false;
____BAH_COMPILER_VAR_412.isOper = false;
____BAH_COMPILER_VAR_412.isEqual = false;
____BAH_COMPILER_VAR_412.pass = false;
____BAH_COMPILER_VAR_412.bahRef= null;
____BAH_COMPILER_VAR_412.parent= null;
#define tmpT ____BAH_COMPILER_VAR_412
tmpT.type = TOKEN_TYPE_VAR;
tmpT.cont = "0";
char * ____BAH_COMPILER_VAR_413 =string__str(&aet);struct Tok rt = parseReflect(tmpT,____BAH_COMPILER_VAR_413,elems,true,"","0");
char * aev = genCompilerVar();
char * ____BAH_COMPILER_VAR_414 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(rt.cont);
unsigned int strLen_1 = strlen(";\n        ");
unsigned int strLen_2 = strlen(" = ");
unsigned int strLen_3 = strlen(aev);
unsigned int strLen_4 = strlen("\n        struct reflectElement ");
;                            
            ____BAH_COMPILER_VAR_414 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_414+currStrOff, "\n        struct reflectElement ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_414+currStrOff, aev, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_414+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_414+currStrOff, rt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_414+currStrOff, ";\n        ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_414));
char * ____BAH_COMPILER_VAR_415 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("&");
unsigned int strLen_1 = strlen(aev);
;                            
            ____BAH_COMPILER_VAR_415 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_415+currStrOff, "&", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_415+currStrOff, aev, strLen_1);
            currStrOff += strLen_1;
        
        }arrElem = ____BAH_COMPILER_VAR_415;

#undef tmpT
}
char * isStruct = "0";
struct cStruct* ts = searchStruct(tt,elems);
char * structLayout = "0";
if ((ts!=null)) {
isStruct = "1";
structLayout = genCompilerVar();
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
____BAH_COMPILER_VAR_416->canBeNull = false;
____BAH_COMPILER_VAR_416->isReg = false;
____BAH_COMPILER_VAR_416->lastSet= null;
____BAH_COMPILER_VAR_416->isArg = false;
struct variable* slv = ____BAH_COMPILER_VAR_416;
slv->name = structLayout;
slv->type = "[]reflectElement";

    {
        unsigned long nLength = len(elems->vars);
        if (nLength >= elems->vars->length) {
            if (nLength >= elems->vars->realLength) {
                if (elems->vars->realLength != 0) {
                    elems->vars->realLength *= 2;
                } else {
                    elems->vars->realLength = 50;
                }
                void * newPtr = memoryRealloc(elems->vars->data, (elems->vars->realLength)*sizeof(struct variable*));
                elems->vars->data = newPtr;
            }
            elems->vars->data[len(elems->vars)] = slv;
            elems->vars->length = nLength+1;
        } else {
            elems->vars->data[len(elems->vars)] = slv;
        }
    }
    ;
struct rope* dataLayout = rope("");
register long int i = 0;
for (; (i<len(ts->members)); ++i) {
struct structMemb* m = ts->members->data[i];
if ((strcmp(m->type, tt) == 0)) {
struct structMemb* ____BAH_COMPILER_VAR_417 = memoryAlloc(sizeof(struct structMemb));
____BAH_COMPILER_VAR_417->name = "";
____BAH_COMPILER_VAR_417->type = "";
____BAH_COMPILER_VAR_417->isConst = false;
____BAH_COMPILER_VAR_417->constVal = "";
____BAH_COMPILER_VAR_417->isArray = false;
____BAH_COMPILER_VAR_417->from = "";
____BAH_COMPILER_VAR_417->declScope= null;
____BAH_COMPILER_VAR_417->isGlobal = false;
____BAH_COMPILER_VAR_417->declRope= null;
____BAH_COMPILER_VAR_417->canBeNull = false;
____BAH_COMPILER_VAR_417->isReg = false;
____BAH_COMPILER_VAR_417->lastSet= null;
____BAH_COMPILER_VAR_417->isArg = false;
____BAH_COMPILER_VAR_417->def = "";
____BAH_COMPILER_VAR_417->isFn = false;
struct structMemb* nm = ____BAH_COMPILER_VAR_417;
*nm = *m;
m = nm;
m->type = "ptr";
}
struct Tok ____BAH_COMPILER_VAR_418 = {};
____BAH_COMPILER_VAR_418.cont = "";
____BAH_COMPILER_VAR_418.ogCont = "";
____BAH_COMPILER_VAR_418.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_418.pos = 0;
____BAH_COMPILER_VAR_418.line = 1;
____BAH_COMPILER_VAR_418.begLine = 1;
____BAH_COMPILER_VAR_418.bahType = "";
____BAH_COMPILER_VAR_418.isValue = false;
____BAH_COMPILER_VAR_418.isFunc = false;
____BAH_COMPILER_VAR_418.isOper = false;
____BAH_COMPILER_VAR_418.isEqual = false;
____BAH_COMPILER_VAR_418.pass = false;
____BAH_COMPILER_VAR_418.bahRef= null;
____BAH_COMPILER_VAR_418.parent= null;
#define tmpT ____BAH_COMPILER_VAR_418
tmpT.type = TOKEN_TYPE_VAR;
char * sep = "->";
if ((strCount(tt,"*")==0)) {
sep = ".";
}
struct string mCtype = getCType(m->type,elems);
struct string offsetTT = string(tt);
string__replace(&offsetTT,"*","");
char * ____BAH_COMPILER_VAR_419 =null;char * ____BAH_COMPILER_VAR_420 =string__str(&offsetTT);char * ____BAH_COMPILER_VAR_421 =string__str(&mCtype);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(m->name);
unsigned int strLen_1 = strlen("))");
unsigned int strLen_2 = strlen(", ");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_420);
unsigned int strLen_4 = strlen(") + offsetof(struct ");
unsigned int strLen_5 = strlen(t.cont);
unsigned int strLen_6 = strlen("*)((char*)(");
unsigned int strLen_7 = strlen(____BAH_COMPILER_VAR_421);
unsigned int strLen_8 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_419 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_419+currStrOff, "(", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_419+currStrOff, ____BAH_COMPILER_VAR_421, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_419+currStrOff, "*)((char*)(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_419+currStrOff, t.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_419+currStrOff, ") + offsetof(struct ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_419+currStrOff, ____BAH_COMPILER_VAR_420, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_419+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_419+currStrOff, m->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_419+currStrOff, "))", strLen_1);
            currStrOff += strLen_1;
        
        }tmpT.cont = ____BAH_COMPILER_VAR_419;
char * ____BAH_COMPILER_VAR_422 =null;char * ____BAH_COMPILER_VAR_423 =string__str(&offsetTT);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(m->name);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen(", ");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_423);
unsigned int strLen_4 = strlen("offsetof(struct ");
;                            
            ____BAH_COMPILER_VAR_422 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_422+currStrOff, "offsetof(struct ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_422+currStrOff, ____BAH_COMPILER_VAR_423, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_422+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_422+currStrOff, m->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_422+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }struct Tok rt = parseReflect(tmpT,m->type,elems,true,m->name,____BAH_COMPILER_VAR_422);
char * ____BAH_COMPILER_VAR_424 =null;char * ____BAH_COMPILER_VAR_425 =intToStr(i);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(rt.cont);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen("] = ");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_425);
unsigned int strLen_4 = strlen("->data[");
unsigned int strLen_5 = strlen(structLayout);
;                            
            ____BAH_COMPILER_VAR_424 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_424+currStrOff, structLayout, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_424+currStrOff, "->data[", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_424+currStrOff, ____BAH_COMPILER_VAR_425, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_424+currStrOff, "] = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_424+currStrOff, rt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_424+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }dataLayout = rope__add(dataLayout, rope(____BAH_COMPILER_VAR_424));

#undef tmpT
};
char * ____BAH_COMPILER_VAR_426 =null;char * ____BAH_COMPILER_VAR_427 =intToStr(len(ts->members));
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(structLayout);
unsigned int strLen_1 = strlen("->elemSize);\n        ");
unsigned int strLen_2 = strlen("->length * ");
unsigned int strLen_3 = strlen(structLayout);
unsigned int strLen_4 = strlen("->data = memoryAlloc(");
unsigned int strLen_5 = strlen(structLayout);
unsigned int strLen_6 = strlen(";\n        ");
unsigned int strLen_7 = strlen(____BAH_COMPILER_VAR_427);
unsigned int strLen_8 = strlen("->length = ");
unsigned int strLen_9 = strlen(structLayout);
unsigned int strLen_10 = strlen("->elemSize = sizeof(struct reflectElement);\n        ");
unsigned int strLen_11 = strlen(structLayout);
unsigned int strLen_12 = strlen(" = memoryAlloc(sizeof(array(struct reflectElement)));\n        ");
unsigned int strLen_13 = strlen(structLayout);
unsigned int strLen_14 = strlen("\n        array(struct reflectElement) * ");
;                            
            ____BAH_COMPILER_VAR_426 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13+strLen_14);
            
                    memcpy(____BAH_COMPILER_VAR_426+currStrOff, "\n        array(struct reflectElement) * ", strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_426+currStrOff, structLayout, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_426+currStrOff, " = memoryAlloc(sizeof(array(struct reflectElement)));\n        ", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_426+currStrOff, structLayout, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_426+currStrOff, "->elemSize = sizeof(struct reflectElement);\n        ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_426+currStrOff, structLayout, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_426+currStrOff, "->length = ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_426+currStrOff, ____BAH_COMPILER_VAR_427, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_426+currStrOff, ";\n        ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_426+currStrOff, structLayout, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_426+currStrOff, "->data = memoryAlloc(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_426+currStrOff, structLayout, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_426+currStrOff, "->length * ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_426+currStrOff, structLayout, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_426+currStrOff, "->elemSize);\n        ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope__add(rope(____BAH_COMPILER_VAR_426), dataLayout));
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
struct variable* ____BAH_COMPILER_VAR_428 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_428->name = "";
____BAH_COMPILER_VAR_428->type = "";
____BAH_COMPILER_VAR_428->isConst = false;
____BAH_COMPILER_VAR_428->constVal = "";
____BAH_COMPILER_VAR_428->isArray = false;
____BAH_COMPILER_VAR_428->from = "";
____BAH_COMPILER_VAR_428->declScope= null;
____BAH_COMPILER_VAR_428->isGlobal = false;
____BAH_COMPILER_VAR_428->declRope= null;
____BAH_COMPILER_VAR_428->canBeNull = false;
____BAH_COMPILER_VAR_428->isReg = false;
____BAH_COMPILER_VAR_428->lastSet= null;
____BAH_COMPILER_VAR_428->isArg = false;
struct variable* rv = ____BAH_COMPILER_VAR_428;
rv->name = genCompilerVar();
rv->type = "reflectElement";

    {
        unsigned long nLength = len(elems->vars);
        if (nLength >= elems->vars->length) {
            if (nLength >= elems->vars->realLength) {
                if (elems->vars->realLength != 0) {
                    elems->vars->realLength *= 2;
                } else {
                    elems->vars->realLength = 50;
                }
                void * newPtr = memoryRealloc(elems->vars->data, (elems->vars->realLength)*sizeof(struct variable*));
                elems->vars->data = newPtr;
            }
            elems->vars->data[len(elems->vars)] = rv;
            elems->vars->length = nLength+1;
        } else {
            elems->vars->data[len(elems->vars)] = rv;
        }
    }
    ;
char * ____BAH_COMPILER_VAR_429 =null;char * ____BAH_COMPILER_VAR_430 =string__str(&name);char * ____BAH_COMPILER_VAR_431 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(offset);
unsigned int strLen_1 = strlen(");\n");
unsigned int strLen_2 = strlen(", ");
unsigned int strLen_3 = strlen(structLayout);
unsigned int strLen_4 = strlen(", ");
unsigned int strLen_5 = strlen(isStruct);
unsigned int strLen_6 = strlen(", ");
unsigned int strLen_7 = strlen(arrElem);
unsigned int strLen_8 = strlen(", ");
unsigned int strLen_9 = strlen(isArr);
unsigned int strLen_10 = strlen("\", ");
unsigned int strLen_11 = strlen(____BAH_COMPILER_VAR_430);
unsigned int strLen_12 = strlen("\", \"");
unsigned int strLen_13 = strlen(tt);
unsigned int strLen_14 = strlen("), \"");
unsigned int strLen_15 = strlen(____BAH_COMPILER_VAR_431);
unsigned int strLen_16 = strlen(", sizeof(");
unsigned int strLen_17 = strlen(t.cont);
unsigned int strLen_18 = strlen(amp);
unsigned int strLen_19 = strlen(" = __reflect(");
unsigned int strLen_20 = strlen(rv->name);
unsigned int strLen_21 = strlen("struct reflectElement ");
;                            
            ____BAH_COMPILER_VAR_429 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13+strLen_14+strLen_15+strLen_16+strLen_17+strLen_18+strLen_19+strLen_20+strLen_21);
            
                    memcpy(____BAH_COMPILER_VAR_429+currStrOff, "struct reflectElement ", strLen_21);
                    currStrOff += strLen_21;
                    
                    memcpy(____BAH_COMPILER_VAR_429+currStrOff, rv->name, strLen_20);
                    currStrOff += strLen_20;
                    
                    memcpy(____BAH_COMPILER_VAR_429+currStrOff, " = __reflect(", strLen_19);
                    currStrOff += strLen_19;
                    
                    memcpy(____BAH_COMPILER_VAR_429+currStrOff, amp, strLen_18);
                    currStrOff += strLen_18;
                    
                    memcpy(____BAH_COMPILER_VAR_429+currStrOff, t.cont, strLen_17);
                    currStrOff += strLen_17;
                    
                    memcpy(____BAH_COMPILER_VAR_429+currStrOff, ", sizeof(", strLen_16);
                    currStrOff += strLen_16;
                    
                    memcpy(____BAH_COMPILER_VAR_429+currStrOff, ____BAH_COMPILER_VAR_431, strLen_15);
                    currStrOff += strLen_15;
                    
                    memcpy(____BAH_COMPILER_VAR_429+currStrOff, "), \"", strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_429+currStrOff, tt, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_429+currStrOff, "\", \"", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_429+currStrOff, ____BAH_COMPILER_VAR_430, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_429+currStrOff, "\", ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_429+currStrOff, isArr, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_429+currStrOff, ", ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_429+currStrOff, arrElem, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_429+currStrOff, ", ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_429+currStrOff, isStruct, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_429+currStrOff, ", ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_429+currStrOff, structLayout, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_429+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_429+currStrOff, offset, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_429+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_429));
t.cont = rv->name;
return t;
};
char * parseArrayDecl(struct variable* v,__BAH_ARR_TYPE_Tok l,long int i,long int max,struct Elems* elems){
long int arrayLength = 0;
struct string arrType = getCType(v->type,elems);
string__trimRight(&arrType,1);
char * ____BAH_COMPILER_VAR_432 =null;char * ____BAH_COMPILER_VAR_433 =string__str(&arrType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_433);
unsigned int strLen_1 = strlen("))");
unsigned int strLen_2 = strlen("memoryAlloc(sizeof(");
;                            
            ____BAH_COMPILER_VAR_432 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_432+currStrOff, "memoryAlloc(sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_432+currStrOff, ____BAH_COMPILER_VAR_433, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_432+currStrOff, "))", strLen_1);
            currStrOff += strLen_1;
        
        }char * code = ____BAH_COMPILER_VAR_432;
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

    {
        unsigned long nLength = len(memory);
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(struct Tok));
                memory->data = newPtr;
            }
            memory->data[len(memory)] = l->data[i];
            memory->length = nLength+1;
        } else {
            memory->data[len(memory)] = l->data[i];
        }
    }
    ;
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
struct variable* ____BAH_COMPILER_VAR_434 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_434->name = "";
____BAH_COMPILER_VAR_434->type = "";
____BAH_COMPILER_VAR_434->isConst = false;
____BAH_COMPILER_VAR_434->constVal = "";
____BAH_COMPILER_VAR_434->isArray = false;
____BAH_COMPILER_VAR_434->from = "";
____BAH_COMPILER_VAR_434->declScope= null;
____BAH_COMPILER_VAR_434->isGlobal = false;
____BAH_COMPILER_VAR_434->declRope= null;
____BAH_COMPILER_VAR_434->canBeNull = false;
____BAH_COMPILER_VAR_434->isReg = false;
____BAH_COMPILER_VAR_434->lastSet= null;
____BAH_COMPILER_VAR_434->isArg = false;
struct variable* tmpV = ____BAH_COMPILER_VAR_434;
tmpV->name = genCompilerVar();
struct string elemType = string(v->type);
string__trimLeft(&elemType,2);
tmpV->type = string__str(&elemType);

    {
        unsigned long nLength = len(elems->vars);
        if (nLength >= elems->vars->length) {
            if (nLength >= elems->vars->realLength) {
                if (elems->vars->realLength != 0) {
                    elems->vars->realLength *= 2;
                } else {
                    elems->vars->realLength = 50;
                }
                void * newPtr = memoryRealloc(elems->vars->data, (elems->vars->realLength)*sizeof(struct variable*));
                elems->vars->data = newPtr;
            }
            elems->vars->data[len(elems->vars)] = tmpV;
            elems->vars->length = nLength+1;
        } else {
            elems->vars->data[len(elems->vars)] = tmpV;
        }
    }
    ;
char * oldNL = NEXT_LINE;
NEXT_LINE = "";
char * innerCode = parseArrayDecl(tmpV,memory,j,i+1,elems);
char * ____BAH_COMPILER_VAR_435 =string__str(&elemType);struct string cType = getCType(____BAH_COMPILER_VAR_435,elems);
char * ____BAH_COMPILER_VAR_436 =null;char * ____BAH_COMPILER_VAR_437 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(NEXT_LINE);
unsigned int strLen_1 = strlen("\n                ");
unsigned int strLen_2 = strlen(";\n                ");
unsigned int strLen_3 = strlen(innerCode);
unsigned int strLen_4 = strlen(" = ");
unsigned int strLen_5 = strlen(tmpV->name);
unsigned int strLen_6 = strlen(") * ");
unsigned int strLen_7 = strlen(____BAH_COMPILER_VAR_437);
unsigned int strLen_8 = strlen("\n                array(");
;                            
            ____BAH_COMPILER_VAR_436 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_436+currStrOff, "\n                array(", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_436+currStrOff, ____BAH_COMPILER_VAR_437, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_436+currStrOff, ") * ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_436+currStrOff, tmpV->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_436+currStrOff, " = ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_436+currStrOff, innerCode, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_436+currStrOff, ";\n                ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_436+currStrOff, NEXT_LINE, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_436+currStrOff, "\n                ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_436));
NEXT_LINE = oldNL;
struct Tok ____BAH_COMPILER_VAR_438 = {};
____BAH_COMPILER_VAR_438.cont = "";
____BAH_COMPILER_VAR_438.ogCont = "";
____BAH_COMPILER_VAR_438.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_438.pos = 0;
____BAH_COMPILER_VAR_438.line = 1;
____BAH_COMPILER_VAR_438.begLine = 1;
____BAH_COMPILER_VAR_438.bahType = "";
____BAH_COMPILER_VAR_438.isValue = false;
____BAH_COMPILER_VAR_438.isFunc = false;
____BAH_COMPILER_VAR_438.isOper = false;
____BAH_COMPILER_VAR_438.isEqual = false;
____BAH_COMPILER_VAR_438.pass = false;
____BAH_COMPILER_VAR_438.bahRef= null;
____BAH_COMPILER_VAR_438.parent= null;
____BAH_COMPILER_VAR_438.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_438.cont = tmpV->name;
____BAH_COMPILER_VAR_438.bahType = string__str(&elemType);
____BAH_COMPILER_VAR_438.isValue = true;
t = ____BAH_COMPILER_VAR_438;
}
char * tt = getTypeFromToken(&t,true,elems);
if ((compTypes(tt,elemBahTypeStr)==false)) {
char * ____BAH_COMPILER_VAR_439 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(") as ");
unsigned int strLen_1 = strlen(elemBahTypeStr);
unsigned int strLen_2 = strlen(tt);
unsigned int strLen_3 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_439 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_439+currStrOff, "Cannot use {TOKEN} (", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_439+currStrOff, tt, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_439+currStrOff, ") as ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_439+currStrOff, elemBahTypeStr, strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&t,____BAH_COMPILER_VAR_439);
}
char * strArrayLength = intToStr(arrayLength);
arrayLength = arrayLength+1;
char * ____BAH_COMPILER_VAR_440 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t.cont);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen("] = ");
unsigned int strLen_3 = strlen(strArrayLength);
unsigned int strLen_4 = strlen("->data[");
unsigned int strLen_5 = strlen(v->name);
unsigned int strLen_6 = strlen(NEXT_LINE);
;                            
            ____BAH_COMPILER_VAR_440 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_440+currStrOff, NEXT_LINE, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_440+currStrOff, v->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_440+currStrOff, "->data[", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_440+currStrOff, strArrayLength, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_440+currStrOff, "] = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_440+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_440+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }NEXT_LINE = ____BAH_COMPILER_VAR_440;
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
char * ____BAH_COMPILER_VAR_441 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(";\n");
unsigned int strLen_1 = strlen(NEXT_LINE);
unsigned int strLen_2 = strlen(allocLengthStr);
unsigned int strLen_3 = strlen("->realLength = ");
unsigned int strLen_4 = strlen(v->name);
unsigned int strLen_5 = strlen(");\n                    ");
unsigned int strLen_6 = strlen(allocLengthStr);
unsigned int strLen_7 = strlen(") * ");
unsigned int strLen_8 = strlen(elemTypeStr);
unsigned int strLen_9 = strlen("->data = memoryAlloc(sizeof(");
unsigned int strLen_10 = strlen(v->name);
;                            
            ____BAH_COMPILER_VAR_441 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10);
            
                    memcpy(____BAH_COMPILER_VAR_441+currStrOff, v->name, strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_441+currStrOff, "->data = memoryAlloc(sizeof(", strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_441+currStrOff, elemTypeStr, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_441+currStrOff, ") * ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_441+currStrOff, allocLengthStr, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_441+currStrOff, ");\n                    ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_441+currStrOff, v->name, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_441+currStrOff, "->realLength = ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_441+currStrOff, allocLengthStr, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_441+currStrOff, ";\n", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_441+currStrOff, NEXT_LINE, strLen_1);
            currStrOff += strLen_1;
        
        }NEXT_LINE = ____BAH_COMPILER_VAR_441;
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
char * ____BAH_COMPILER_VAR_442 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(");\n");
unsigned int strLen_1 = strlen(NEXT_LINE);
unsigned int strLen_2 = strlen(elemTypeStr);
unsigned int strLen_3 = strlen("->elemSize = sizeof(");
unsigned int strLen_4 = strlen(v->name);
unsigned int strLen_5 = strlen(";\n");
unsigned int strLen_6 = strlen(strArrayLength);
unsigned int strLen_7 = strlen("->length = ");
unsigned int strLen_8 = strlen(v->name);
unsigned int strLen_9 = strlen("\n");
;                            
            ____BAH_COMPILER_VAR_442 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9);
            
                    memcpy(____BAH_COMPILER_VAR_442+currStrOff, "\n", strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_442+currStrOff, v->name, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_442+currStrOff, "->length = ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_442+currStrOff, strArrayLength, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_442+currStrOff, ";\n", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_442+currStrOff, v->name, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_442+currStrOff, "->elemSize = sizeof(", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_442+currStrOff, elemTypeStr, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_442+currStrOff, ");\n", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_442+currStrOff, NEXT_LINE, strLen_1);
            currStrOff += strLen_1;
        
        }NEXT_LINE = ____BAH_COMPILER_VAR_442;
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
char * ____BAH_COMPILER_VAR_443 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ft.cont);
unsigned int strLen_1 = strlen(";\n");
;                            
            ____BAH_COMPILER_VAR_443 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_443+currStrOff, ft.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_443+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_443));
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
____BAH_COMPILER_VAR_444->canBeNull = false;
____BAH_COMPILER_VAR_444->isReg = false;
____BAH_COMPILER_VAR_444->lastSet= null;
____BAH_COMPILER_VAR_444->isArg = false;
v = ____BAH_COMPILER_VAR_444;
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
char * ____BAH_COMPILER_VAR_445 =string__str(&c);v = searchVar(____BAH_COMPILER_VAR_445,elems);
if ((v==null)) {
throwErr(&t,"Cannot increase/decrease not declared variable {TOKEN}.");
}
char * ____BAH_COMPILER_VAR_446 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t.cont);
unsigned int strLen_1 = strlen(";\n");
;                            
            ____BAH_COMPILER_VAR_446 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_446+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_446+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_446));
return;
}
if ((len(l)<2)) {
throwErr(&ft,"Missing '=' after {TOKEN}.");
}
struct Tok operT = l->data[1];

        char ____BAH_COMPILER_VAR_447 = 0;
        for(int i=equalsTokens->length-1; i!=-1;i--) {
            if (equalsTokens->data[i] != 0 && strcmp(equalsTokens->data[i], operT.cont) == 0) {
                ____BAH_COMPILER_VAR_447=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_447&&(strcmp(operT.cont, "=") != 0)) {
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

    {
        unsigned long nLength = len(nl);
        if (nLength >= nl->length) {
            if (nLength >= nl->realLength) {
                if (nl->realLength != 0) {
                    nl->realLength *= 2;
                } else {
                    nl->realLength = 50;
                }
                void * newPtr = memoryRealloc(nl->data, (nl->realLength)*sizeof(struct Tok));
                nl->data = newPtr;
            }
            nl->data[len(nl)] = operT;
            nl->length = nLength+1;
        } else {
            nl->data[len(nl)] = operT;
        }
    }
    ;
register long int j = 0;
for (; (j<len(tmpL)); ++j) {

    {
        unsigned long nLength = len(nl);
        if (nLength >= nl->length) {
            if (nLength >= nl->realLength) {
                if (nl->realLength != 0) {
                    nl->realLength *= 2;
                } else {
                    nl->realLength = 50;
                }
                void * newPtr = memoryRealloc(nl->data, (nl->realLength)*sizeof(struct Tok));
                nl->data = newPtr;
            }
            nl->data[len(nl)] = tmpL->data[j];
            nl->length = nLength+1;
        } else {
            nl->data[len(nl)] = tmpL->data[j];
        }
    }
    ;
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
char * ____BAH_COMPILER_VAR_448 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(currentType);
unsigned int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_448 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_448+currStrOff, currentType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_448+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }currentType = ____BAH_COMPILER_VAR_448;
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
char * ____BAH_COMPILER_VAR_449 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("chan:");
unsigned int strLen_1 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_449 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_449+currStrOff, "chan:", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_449+currStrOff, nt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }v->type = ____BAH_COMPILER_VAR_449;
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
char * ____BAH_COMPILER_VAR_450 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("map:");
unsigned int strLen_1 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_450 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_450+currStrOff, "map:", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_450+currStrOff, nt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }v->type = ____BAH_COMPILER_VAR_450;
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
char * ____BAH_COMPILER_VAR_451 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("buffer:");
unsigned int strLen_1 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_451 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_451+currStrOff, "buffer:", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_451+currStrOff, nt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }v->type = ____BAH_COMPILER_VAR_451;
struct variable* ____BAH_COMPILER_VAR_452 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_452->name = "";
____BAH_COMPILER_VAR_452->type = "";
____BAH_COMPILER_VAR_452->isConst = false;
____BAH_COMPILER_VAR_452->constVal = "";
____BAH_COMPILER_VAR_452->isArray = false;
____BAH_COMPILER_VAR_452->from = "";
____BAH_COMPILER_VAR_452->declScope= null;
____BAH_COMPILER_VAR_452->isGlobal = false;
____BAH_COMPILER_VAR_452->declRope= null;
____BAH_COMPILER_VAR_452->canBeNull = false;
____BAH_COMPILER_VAR_452->isReg = false;
____BAH_COMPILER_VAR_452->lastSet= null;
____BAH_COMPILER_VAR_452->isArg = false;
struct variable* av = ____BAH_COMPILER_VAR_452;
av->type = "char*";
av->name = genCompilerVar();

    {
        unsigned long nLength = len(elems->vars);
        if (nLength >= elems->vars->length) {
            if (nLength >= elems->vars->realLength) {
                if (elems->vars->realLength != 0) {
                    elems->vars->realLength *= 2;
                } else {
                    elems->vars->realLength = 50;
                }
                void * newPtr = memoryRealloc(elems->vars->data, (elems->vars->realLength)*sizeof(struct variable*));
                elems->vars->data = newPtr;
            }
            elems->vars->data[len(elems->vars)] = av;
            elems->vars->length = nLength+1;
        } else {
            elems->vars->data[len(elems->vars)] = av;
        }
    }
    ;
struct string cType = getCType(av->type,elems);
char * ____BAH_COMPILER_VAR_453 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen("];");
unsigned int strLen_2 = strlen("[");
unsigned int strLen_3 = strlen(av->name);
unsigned int strLen_4 = strlen("char ");
;                            
            ____BAH_COMPILER_VAR_453 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_453+currStrOff, "char ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_453+currStrOff, av->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_453+currStrOff, "[", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_453+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_453+currStrOff, "];", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_453));
code = av->name;
if ((i+1!=len(l))) {
struct Tok errT = l->data[i+1];
throwErr(&errT,"{TOKEN} not expected after buffer declaration.");
}
break;
}
char * tp = getTypeFromToken(&t,true,elems);

                struct string ____BAH_COMPILER_VAR_454 = string(compilerState.currentDir);
                if ((isUnsafe==false)&&(string__hasPrefix(&____BAH_COMPILER_VAR_454,BAH_DIR)==false)&&isRCPpointerType(tp)) {
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
char * ____BAH_COMPILER_VAR_455 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(v->type);
unsigned int strLen_1 = strlen(".");
unsigned int strLen_2 = strlen(") as ");
unsigned int strLen_3 = strlen(tp);
unsigned int strLen_4 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_455 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_455+currStrOff, "Cannot use {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_455+currStrOff, tp, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_455+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_455+currStrOff, v->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_455+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&t,____BAH_COMPILER_VAR_455);
}
}
else {
if ((strcmp(currentType, "") == 0)) {
if ((strcmp(v->type, "") == 0)) {
v->type = tp;
}
else {
if ((compTypes(tp,v->type)==false)) {
char * ____BAH_COMPILER_VAR_456 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(v->type);
unsigned int strLen_1 = strlen(".");
unsigned int strLen_2 = strlen(") as ");
unsigned int strLen_3 = strlen(tp);
unsigned int strLen_4 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_456 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_456+currStrOff, "Cannot use {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_456+currStrOff, tp, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_456+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_456+currStrOff, v->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_456+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&t,____BAH_COMPILER_VAR_456);
}
}
}
}
if ((strcmp(t.cont, "") != 0)&&(strHasPrefix(t.cont,"{")==false)) {
char * ____BAH_COMPILER_VAR_457 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_457 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_457+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_457+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_457;
if ((t.isOper==false)&&(RCPavailable()==true)) {
struct variable* iv = searchVar(t.cont,elems);
if ((iv!=null)&&(iv->isConst==false)) {
toVar = true;
isPointedVar = strHasPrefix(t.cont,"&");
struct cStruct* s = searchStruct(iv->type,elems);
if ((s!=null)&&(strCount(iv->type,"*")==0)&&(s->isBinding==false)) {
if ((strCount(iv->name,"*")==0)) {
char * ____BAH_COMPILER_VAR_458 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(iv->name);
unsigned int strLen_1 = strlen("), 0)");
unsigned int strLen_2 = strlen(", sizeof(");
unsigned int strLen_3 = strlen(iv->name);
unsigned int strLen_4 = strlen("; RCP_scanStack(&");
unsigned int strLen_5 = strlen(code);
;                            
            ____BAH_COMPILER_VAR_458 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_458+currStrOff, code, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_458+currStrOff, "; RCP_scanStack(&", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_458+currStrOff, iv->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_458+currStrOff, ", sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_458+currStrOff, iv->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_458+currStrOff, "), 0)", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_458;
}
else {
struct string ivn = string(iv->name);
if ((string__count(&ivn,"*")>0)) {
string__replace(&ivn,"*","");
char * ____BAH_COMPILER_VAR_459 =null;char * ____BAH_COMPILER_VAR_460 =string__str(&ivn);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(iv->name);
unsigned int strLen_1 = strlen("), 0)");
unsigned int strLen_2 = strlen(", sizeof(");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_460);
unsigned int strLen_4 = strlen("; RCP_scanStack(");
;                            
            ____BAH_COMPILER_VAR_459 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_459+currStrOff, "; RCP_scanStack(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_459+currStrOff, ____BAH_COMPILER_VAR_460, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_459+currStrOff, ", sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_459+currStrOff, iv->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_459+currStrOff, "), 0)", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_461 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_459);
;                            
            ____BAH_COMPILER_VAR_461 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_461+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_461+currStrOff, ____BAH_COMPILER_VAR_459, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_461;
}
else {
char * ____BAH_COMPILER_VAR_462 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(iv->name);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen("; RCP_incr(");
unsigned int strLen_3 = strlen(code);
;                            
            ____BAH_COMPILER_VAR_462 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_462+currStrOff, code, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_462+currStrOff, "; RCP_incr(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_462+currStrOff, iv->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_462+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_462;
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
char * ____BAH_COMPILER_VAR_463 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_463 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_463+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_463+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_463;
}
++i;
};
if ((exists==true)) {
v->lastSet = elems;
if ((ft.parent!=null)) {
ft.parent->lastSet = elems;
}
if ((currentFn!=null)) {

                struct string ____BAH_COMPILER_VAR_464 = string(v->name);
                if ((strcmp(v->name, "this") == 0)||string__hasPrefix(&____BAH_COMPILER_VAR_464,"this->")) {
currentFn->isMut = true;
}
}
if ((strlen(code)==0)) {
throwErr(&ft,"Cannot re-declare {TOKEN}.");
}
if ((strlen(currentType)>0)) {
struct Tok st = l->data[1];
char * ____BAH_COMPILER_VAR_465 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ft.cont);
unsigned int strLen_1 = strlen("' to {TOKEN}.");
unsigned int strLen_2 = strlen("Cannot change the type of already declared var '");
;                            
            ____BAH_COMPILER_VAR_465 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_465+currStrOff, "Cannot change the type of already declared var '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_465+currStrOff, ft.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_465+currStrOff, "' to {TOKEN}.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&st,____BAH_COMPILER_VAR_465);
}
char * preCode = "";
if ((isStruct==false)) {
if (isRCPpointerType(v->type)&&(isPointedVar==false)&&(RCPavailable()==true)) {
struct string cType = getCType(v->type,elems);
if ((toVar==true)) {
if ((RCPselfRef(v)==false)) {
char * ____BAH_COMPILER_VAR_466 =null;char * ____BAH_COMPILER_VAR_467 =string__str(&cType);char * ____BAH_COMPILER_VAR_468 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen("*)RCP_incrIL(&");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_467);
unsigned int strLen_4 = strlen(") = *(");
unsigned int strLen_5 = strlen(v->name);
unsigned int strLen_6 = strlen("*)RCP_decrIL(&");
unsigned int strLen_7 = strlen(____BAH_COMPILER_VAR_468);
unsigned int strLen_8 = strlen("*(");
;                            
            ____BAH_COMPILER_VAR_466 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_466+currStrOff, "*(", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_466+currStrOff, ____BAH_COMPILER_VAR_468, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_466+currStrOff, "*)RCP_decrIL(&", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_466+currStrOff, v->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_466+currStrOff, ") = *(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_466+currStrOff, ____BAH_COMPILER_VAR_467, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_466+currStrOff, "*)RCP_incrIL(&", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_466+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_466+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_466;
}
else {
struct variable* ____BAH_COMPILER_VAR_469 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_469->name = "";
____BAH_COMPILER_VAR_469->type = "";
____BAH_COMPILER_VAR_469->isConst = false;
____BAH_COMPILER_VAR_469->constVal = "";
____BAH_COMPILER_VAR_469->isArray = false;
____BAH_COMPILER_VAR_469->from = "";
____BAH_COMPILER_VAR_469->declScope= null;
____BAH_COMPILER_VAR_469->isGlobal = false;
____BAH_COMPILER_VAR_469->declRope= null;
____BAH_COMPILER_VAR_469->canBeNull = false;
____BAH_COMPILER_VAR_469->isReg = false;
____BAH_COMPILER_VAR_469->lastSet= null;
____BAH_COMPILER_VAR_469->isArg = false;
struct variable* tmpV = ____BAH_COMPILER_VAR_469;
tmpV->name = genCompilerVar();
tmpV->type = v->type;
struct rope* dv = decrVar(tmpV,elems);
char * ____BAH_COMPILER_VAR_470 =null;char * ____BAH_COMPILER_VAR_471 =rope__toStr(dv);char * ____BAH_COMPILER_VAR_472 =string__str(&cType);char * ____BAH_COMPILER_VAR_473 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(");");
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_471);
unsigned int strLen_2 = strlen(code);
unsigned int strLen_3 = strlen("*)RCP_incrIL(&");
unsigned int strLen_4 = strlen(____BAH_COMPILER_VAR_472);
unsigned int strLen_5 = strlen(" = *(");
unsigned int strLen_6 = strlen(v->name);
unsigned int strLen_7 = strlen("; ");
unsigned int strLen_8 = strlen(v->name);
unsigned int strLen_9 = strlen(" = ");
unsigned int strLen_10 = strlen(tmpV->name);
unsigned int strLen_11 = strlen(" ");
unsigned int strLen_12 = strlen(____BAH_COMPILER_VAR_473);
;                            
            ____BAH_COMPILER_VAR_470 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12);
            
                    memcpy(____BAH_COMPILER_VAR_470+currStrOff, ____BAH_COMPILER_VAR_473, strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_470+currStrOff, " ", strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_470+currStrOff, tmpV->name, strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_470+currStrOff, " = ", strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_470+currStrOff, v->name, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_470+currStrOff, "; ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_470+currStrOff, v->name, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_470+currStrOff, " = *(", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_470+currStrOff, ____BAH_COMPILER_VAR_472, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_470+currStrOff, "*)RCP_incrIL(&", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_470+currStrOff, code, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_470+currStrOff, ");", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_470+currStrOff, ____BAH_COMPILER_VAR_471, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_470;
}
}
else {
struct variable* ____BAH_COMPILER_VAR_474 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_474->name = "";
____BAH_COMPILER_VAR_474->type = "";
____BAH_COMPILER_VAR_474->isConst = false;
____BAH_COMPILER_VAR_474->constVal = "";
____BAH_COMPILER_VAR_474->isArray = false;
____BAH_COMPILER_VAR_474->from = "";
____BAH_COMPILER_VAR_474->declScope= null;
____BAH_COMPILER_VAR_474->isGlobal = false;
____BAH_COMPILER_VAR_474->declRope= null;
____BAH_COMPILER_VAR_474->canBeNull = false;
____BAH_COMPILER_VAR_474->isReg = false;
____BAH_COMPILER_VAR_474->lastSet= null;
____BAH_COMPILER_VAR_474->isArg = false;
struct variable* tmpV = ____BAH_COMPILER_VAR_474;
tmpV->name = genCompilerVar();
tmpV->type = v->type;
struct rope* dv = decrVar(tmpV,elems);
char * ____BAH_COMPILER_VAR_475 =null;char * ____BAH_COMPILER_VAR_476 =rope__toStr(dv);char * ____BAH_COMPILER_VAR_477 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(";");
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_476);
unsigned int strLen_2 = strlen(code);
unsigned int strLen_3 = strlen(" = ");
unsigned int strLen_4 = strlen(v->name);
unsigned int strLen_5 = strlen("; ");
unsigned int strLen_6 = strlen(v->name);
unsigned int strLen_7 = strlen(" = ");
unsigned int strLen_8 = strlen(tmpV->name);
unsigned int strLen_9 = strlen(" ");
unsigned int strLen_10 = strlen(____BAH_COMPILER_VAR_477);
;                            
            ____BAH_COMPILER_VAR_475 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10);
            
                    memcpy(____BAH_COMPILER_VAR_475+currStrOff, ____BAH_COMPILER_VAR_477, strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_475+currStrOff, " ", strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_475+currStrOff, tmpV->name, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_475+currStrOff, " = ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_475+currStrOff, v->name, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_475+currStrOff, "; ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_475+currStrOff, v->name, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_475+currStrOff, " = ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_475+currStrOff, code, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_475+currStrOff, ";", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_475+currStrOff, ____BAH_COMPILER_VAR_476, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_475;
}
}
else {
struct cStruct* s = searchStruct(v->type,elems);
if ((s!=null)&&(RCPavailable()==true)&&(RCPselfRef(v)==false)&&(s->isBinding==false)) {
if ((strCount(v->name,"*")==0)) {
char * ____BAH_COMPILER_VAR_478 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(v->name);
unsigned int strLen_1 = strlen("), 1); ");
unsigned int strLen_2 = strlen(", sizeof(");
unsigned int strLen_3 = strlen(v->name);
unsigned int strLen_4 = strlen("RCP_scanStack(&");
;                            
            ____BAH_COMPILER_VAR_478 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_478+currStrOff, "RCP_scanStack(&", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_478+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_478+currStrOff, ", sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_478+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_478+currStrOff, "), 1); ", strLen_1);
            currStrOff += strLen_1;
        
        }preCode = ____BAH_COMPILER_VAR_478;
}
else {
struct string vn = string(v->name);
string__replace(&vn,"*","");
char * ____BAH_COMPILER_VAR_479 =null;char * ____BAH_COMPILER_VAR_480 =string__str(&vn);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(v->name);
unsigned int strLen_1 = strlen("), 1); ");
unsigned int strLen_2 = strlen(", sizeof(");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_480);
unsigned int strLen_4 = strlen("RCP_scanStack(");
;                            
            ____BAH_COMPILER_VAR_479 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_479+currStrOff, "RCP_scanStack(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_479+currStrOff, ____BAH_COMPILER_VAR_480, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_479+currStrOff, ", sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_479+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_479+currStrOff, "), 1); ", strLen_1);
            currStrOff += strLen_1;
        
        }preCode = ____BAH_COMPILER_VAR_479;
}
char * ____BAH_COMPILER_VAR_481 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(" = ");
unsigned int strLen_1 = strlen(code);
unsigned int strLen_2 = strlen(v->name);
;                            
            ____BAH_COMPILER_VAR_481 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_481+currStrOff, v->name, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_481+currStrOff, " = ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_481+currStrOff, code, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_481;
}
else {
char * ____BAH_COMPILER_VAR_482 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(" = ");
unsigned int strLen_1 = strlen(code);
unsigned int strLen_2 = strlen(v->name);
;                            
            ____BAH_COMPILER_VAR_482 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_482+currStrOff, v->name, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_482+currStrOff, " = ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_482+currStrOff, code, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_482;
}
}
}
else {
strTrim(&code);
if ((strHasPrefix(code,"{")==false)) {
char * ____BAH_COMPILER_VAR_483 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(" = ");
unsigned int strLen_1 = strlen(code);
unsigned int strLen_2 = strlen(v->name);
;                            
            ____BAH_COMPILER_VAR_483 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_483+currStrOff, v->name, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_483+currStrOff, " = ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_483+currStrOff, code, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_483;
}
}
if ((v->isArray==true)) {
code = genArrRealloc(v,preCode,code,elems);
}
else {
char * ____BAH_COMPILER_VAR_484 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(preCode);
unsigned int strLen_1 = strlen(code);
;                            
            ____BAH_COMPILER_VAR_484 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_484+currStrOff, preCode, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_484+currStrOff, code, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_484;
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
char * ____BAH_COMPILER_VAR_485 =null;char * ____BAH_COMPILER_VAR_486 =string__str(&ct);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpfnArgsCType);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_486);
;                            
            ____BAH_COMPILER_VAR_485 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_485+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_485+currStrOff, ____BAH_COMPILER_VAR_486, strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_485;
j = j+1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_487 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpfnArgsCType);
unsigned int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_487 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_487+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_487+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_487;
}
};
char * ____BAH_COMPILER_VAR_488 =null;char * ____BAH_COMPILER_VAR_489 =string__str(&tmpfnRetCType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpfnArgsCType);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen(")(");
unsigned int strLen_3 = strlen(v->name);
unsigned int strLen_4 = strlen(" (*");
unsigned int strLen_5 = strlen(____BAH_COMPILER_VAR_489);
;                            
            ____BAH_COMPILER_VAR_488 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_488+currStrOff, ____BAH_COMPILER_VAR_489, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_488+currStrOff, " (*", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_488+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_488+currStrOff, ")(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_488+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_488+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }vct = ____BAH_COMPILER_VAR_488;
}
else {
vct = setCType(v,elems);
}
if ((strcmp(code, "") != 0)&&(shouldOnlyDecl==false)) {
if (isRCPpointerType(v->type)&&(RCPavailable()==true)&&(toVar==true)&&(isPointedVar==false)) {
struct string cType = getCType(v->type,elems);
if (isGlobal()) {
char * ____BAH_COMPILER_VAR_490 =null;char * ____BAH_COMPILER_VAR_491 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(");\n");
unsigned int strLen_2 = strlen("*)RCP_incrIL(&");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_491);
unsigned int strLen_4 = strlen(" = *(");
unsigned int strLen_5 = strlen(v->name);
;                            
            ____BAH_COMPILER_VAR_490 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_490+currStrOff, v->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_490+currStrOff, " = *(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_490+currStrOff, ____BAH_COMPILER_VAR_491, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_490+currStrOff, "*)RCP_incrIL(&", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_490+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_490+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_490));
}
else {
char * ____BAH_COMPILER_VAR_492 =null;char * ____BAH_COMPILER_VAR_493 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen("*)RCP_incrIL(&");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_493);
unsigned int strLen_4 = strlen(" = *(");
unsigned int strLen_5 = strlen(vct);
;                            
            ____BAH_COMPILER_VAR_492 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_492+currStrOff, vct, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_492+currStrOff, " = *(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_492+currStrOff, ____BAH_COMPILER_VAR_493, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_492+currStrOff, "*)RCP_incrIL(&", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_492+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_492+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_492;
}
}
else {
if ((needsDefine==true)) {

    {
        unsigned long nLength = len(elems->defined);
        if (nLength >= elems->defined->length) {
            if (nLength >= elems->defined->realLength) {
                if (elems->defined->realLength != 0) {
                    elems->defined->realLength *= 2;
                } else {
                    elems->defined->realLength = 50;
                }
                void * newPtr = memoryRealloc(elems->defined->data, (elems->defined->realLength)*sizeof(char *));
                elems->defined->data = newPtr;
            }
            elems->defined->data[len(elems->defined)] = v->name;
            elems->defined->length = nLength+1;
        } else {
            elems->defined->data[len(elems->defined)] = v->name;
        }
    }
    ;
if (isGlobal()) {
char * ____BAH_COMPILER_VAR_494 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen("\n");
unsigned int strLen_2 = strlen(" ");
unsigned int strLen_3 = strlen(v->name);
unsigned int strLen_4 = strlen("#define ");
;                            
            ____BAH_COMPILER_VAR_494 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_494+currStrOff, "#define ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_494+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_494+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_494+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_494+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_494));
}
else {
char * ____BAH_COMPILER_VAR_495 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(" ");
unsigned int strLen_1 = strlen(code);
unsigned int strLen_2 = strlen(v->name);
unsigned int strLen_3 = strlen("#define ");
;                            
            ____BAH_COMPILER_VAR_495 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_495+currStrOff, "#define ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_495+currStrOff, v->name, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_495+currStrOff, " ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_495+currStrOff, code, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_495;
}
}
else {
if (isGlobal()) {
char * ____BAH_COMPILER_VAR_496 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen(" = ");
unsigned int strLen_3 = strlen(v->name);
;                            
            ____BAH_COMPILER_VAR_496 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_496+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_496+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_496+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_496+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_496));
}
else {
char * ____BAH_COMPILER_VAR_497 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(" = ");
unsigned int strLen_1 = strlen(code);
unsigned int strLen_2 = strlen(vct);
;                            
            ____BAH_COMPILER_VAR_497 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_497+currStrOff, vct, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_497+currStrOff, " = ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_497+currStrOff, code, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_497;
}
}
}
}
else {
if (isRCPpointerType(v->type)&&(shouldOnlyDecl==false)) {
char * ____BAH_COMPILER_VAR_498 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(vct);
unsigned int strLen_1 = strlen("= null");
;                            
            ____BAH_COMPILER_VAR_498 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_498+currStrOff, vct, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_498+currStrOff, "= null", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_498;
}
else {
code = vct;
}
}
if ((shouldOnlyDecl==true)) {
char * ____BAH_COMPILER_VAR_499 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("extern ");
unsigned int strLen_1 = strlen(vct);
;                            
            ____BAH_COMPILER_VAR_499 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_499+currStrOff, "extern ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_499+currStrOff, vct, strLen_1);
            currStrOff += strLen_1;
        
        }vct = ____BAH_COMPILER_VAR_499;
}
if (isGlobal()) {
v->isGlobal = true;
}
else {
v->isGlobal = false;
}
v->declScope = elems;

    {
        unsigned long nLength = len(elems->vars);
        if (nLength >= elems->vars->length) {
            if (nLength >= elems->vars->realLength) {
                if (elems->vars->realLength != 0) {
                    elems->vars->realLength *= 2;
                } else {
                    elems->vars->realLength = 50;
                }
                void * newPtr = memoryRealloc(elems->vars->data, (elems->vars->realLength)*sizeof(struct variable*));
                elems->vars->data = newPtr;
            }
            elems->vars->data[len(elems->vars)] = v;
            elems->vars->length = nLength+1;
        } else {
            elems->vars->data[len(elems->vars)] = v;
        }
    }
    ;
struct variable* ____BAH_COMPILER_VAR_500 = v;
char ** ____BAH_COMPILER_VAR_502 = (char **)((char*)(____BAH_COMPILER_VAR_500) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_503 = __reflect(____BAH_COMPILER_VAR_502, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_504 = (char **)((char*)(____BAH_COMPILER_VAR_500) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_505 = __reflect(____BAH_COMPILER_VAR_504, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_506 = (char*)((char*)(____BAH_COMPILER_VAR_500) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_507 = __reflect(____BAH_COMPILER_VAR_506, sizeof(char), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_508 = (char **)((char*)(____BAH_COMPILER_VAR_500) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_509 = __reflect(____BAH_COMPILER_VAR_508, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_510 = (char*)((char*)(____BAH_COMPILER_VAR_500) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_511 = __reflect(____BAH_COMPILER_VAR_510, sizeof(char), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_512 = (char **)((char*)(____BAH_COMPILER_VAR_500) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_513 = __reflect(____BAH_COMPILER_VAR_512, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
void ** ____BAH_COMPILER_VAR_514 = (void **)((char*)(____BAH_COMPILER_VAR_500) + offsetof(struct variable, declScope));
struct reflectElement ____BAH_COMPILER_VAR_515 = __reflect(____BAH_COMPILER_VAR_514, sizeof(void *), "ptr", "declScope", 0, 0, 0, 0, offsetof(struct variable, declScope));
char* ____BAH_COMPILER_VAR_516 = (char*)((char*)(____BAH_COMPILER_VAR_500) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_517 = __reflect(____BAH_COMPILER_VAR_516, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));
struct rope** ____BAH_COMPILER_VAR_518 = (struct rope**)((char*)(____BAH_COMPILER_VAR_500) + offsetof(struct variable, declRope));
void ** ____BAH_COMPILER_VAR_520 = (void **)((char*)(____BAH_COMPILER_VAR_518) + offsetof(struct rope, left));
struct reflectElement ____BAH_COMPILER_VAR_521 = __reflect(____BAH_COMPILER_VAR_520, sizeof(void *), "ptr", "left", 0, 0, 0, 0, offsetof(struct rope, left));
void ** ____BAH_COMPILER_VAR_522 = (void **)((char*)(____BAH_COMPILER_VAR_518) + offsetof(struct rope, right));
struct reflectElement ____BAH_COMPILER_VAR_523 = __reflect(____BAH_COMPILER_VAR_522, sizeof(void *), "ptr", "right", 0, 0, 0, 0, offsetof(struct rope, right));
char ** ____BAH_COMPILER_VAR_524 = (char **)((char*)(____BAH_COMPILER_VAR_518) + offsetof(struct rope, str));
struct reflectElement ____BAH_COMPILER_VAR_525 = __reflect(____BAH_COMPILER_VAR_524, sizeof(char *), "cpstring", "str", 0, 0, 0, 0, offsetof(struct rope, str));
int* ____BAH_COMPILER_VAR_526 = (int*)((char*)(____BAH_COMPILER_VAR_518) + offsetof(struct rope, lCount));
struct reflectElement ____BAH_COMPILER_VAR_527 = __reflect(____BAH_COMPILER_VAR_526, sizeof(int), "int32", "lCount", 0, 0, 0, 0, offsetof(struct rope, lCount));
int* ____BAH_COMPILER_VAR_528 = (int*)((char*)(____BAH_COMPILER_VAR_518) + offsetof(struct rope, len));
struct reflectElement ____BAH_COMPILER_VAR_529 = __reflect(____BAH_COMPILER_VAR_528, sizeof(int), "int32", "len", 0, 0, 0, 0, offsetof(struct rope, len));
int* ____BAH_COMPILER_VAR_530 = (int*)((char*)(____BAH_COMPILER_VAR_518) + offsetof(struct rope, totalLen));
struct reflectElement ____BAH_COMPILER_VAR_531 = __reflect(____BAH_COMPILER_VAR_530, sizeof(int), "int32", "totalLen", 0, 0, 0, 0, offsetof(struct rope, totalLen));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_519 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_519->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_519->length = 6;
        ____BAH_COMPILER_VAR_519->data = memoryAlloc(____BAH_COMPILER_VAR_519->length * ____BAH_COMPILER_VAR_519->elemSize);
        ____BAH_COMPILER_VAR_519->data[0] = ____BAH_COMPILER_VAR_521;
____BAH_COMPILER_VAR_519->data[1] = ____BAH_COMPILER_VAR_523;
____BAH_COMPILER_VAR_519->data[2] = ____BAH_COMPILER_VAR_525;
____BAH_COMPILER_VAR_519->data[3] = ____BAH_COMPILER_VAR_527;
____BAH_COMPILER_VAR_519->data[4] = ____BAH_COMPILER_VAR_529;
____BAH_COMPILER_VAR_519->data[5] = ____BAH_COMPILER_VAR_531;
struct reflectElement ____BAH_COMPILER_VAR_532 = __reflect(____BAH_COMPILER_VAR_518, sizeof(struct rope), "rope*", "declRope", 0, 0, 1, ____BAH_COMPILER_VAR_519, offsetof(struct variable, declRope));
char* ____BAH_COMPILER_VAR_533 = (char*)((char*)(____BAH_COMPILER_VAR_500) + offsetof(struct variable, canBeNull));
struct reflectElement ____BAH_COMPILER_VAR_534 = __reflect(____BAH_COMPILER_VAR_533, sizeof(char), "bool", "canBeNull", 0, 0, 0, 0, offsetof(struct variable, canBeNull));
char* ____BAH_COMPILER_VAR_535 = (char*)((char*)(____BAH_COMPILER_VAR_500) + offsetof(struct variable, canBeReg));
struct reflectElement ____BAH_COMPILER_VAR_536 = __reflect(____BAH_COMPILER_VAR_535, sizeof(char), "bool", "canBeReg", 0, 0, 0, 0, offsetof(struct variable, canBeReg));
char* ____BAH_COMPILER_VAR_537 = (char*)((char*)(____BAH_COMPILER_VAR_500) + offsetof(struct variable, isReg));
struct reflectElement ____BAH_COMPILER_VAR_538 = __reflect(____BAH_COMPILER_VAR_537, sizeof(char), "bool", "isReg", 0, 0, 0, 0, offsetof(struct variable, isReg));
void ** ____BAH_COMPILER_VAR_539 = (void **)((char*)(____BAH_COMPILER_VAR_500) + offsetof(struct variable, lastSet));
struct reflectElement ____BAH_COMPILER_VAR_540 = __reflect(____BAH_COMPILER_VAR_539, sizeof(void *), "ptr", "lastSet", 0, 0, 0, 0, offsetof(struct variable, lastSet));
char* ____BAH_COMPILER_VAR_541 = (char*)((char*)(____BAH_COMPILER_VAR_500) + offsetof(struct variable, isArg));
struct reflectElement ____BAH_COMPILER_VAR_542 = __reflect(____BAH_COMPILER_VAR_541, sizeof(char), "bool", "isArg", 0, 0, 0, 0, offsetof(struct variable, isArg));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_501 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_501->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_501->length = 14;
        ____BAH_COMPILER_VAR_501->data = memoryAlloc(____BAH_COMPILER_VAR_501->length * ____BAH_COMPILER_VAR_501->elemSize);
        ____BAH_COMPILER_VAR_501->data[0] = ____BAH_COMPILER_VAR_503;
____BAH_COMPILER_VAR_501->data[1] = ____BAH_COMPILER_VAR_505;
____BAH_COMPILER_VAR_501->data[2] = ____BAH_COMPILER_VAR_507;
____BAH_COMPILER_VAR_501->data[3] = ____BAH_COMPILER_VAR_509;
____BAH_COMPILER_VAR_501->data[4] = ____BAH_COMPILER_VAR_511;
____BAH_COMPILER_VAR_501->data[5] = ____BAH_COMPILER_VAR_513;
____BAH_COMPILER_VAR_501->data[6] = ____BAH_COMPILER_VAR_515;
____BAH_COMPILER_VAR_501->data[7] = ____BAH_COMPILER_VAR_517;
____BAH_COMPILER_VAR_501->data[8] = ____BAH_COMPILER_VAR_532;
____BAH_COMPILER_VAR_501->data[9] = ____BAH_COMPILER_VAR_534;
____BAH_COMPILER_VAR_501->data[10] = ____BAH_COMPILER_VAR_536;
____BAH_COMPILER_VAR_501->data[11] = ____BAH_COMPILER_VAR_538;
____BAH_COMPILER_VAR_501->data[12] = ____BAH_COMPILER_VAR_540;
____BAH_COMPILER_VAR_501->data[13] = ____BAH_COMPILER_VAR_542;
struct reflectElement ____BAH_COMPILER_VAR_543 = __reflect(____BAH_COMPILER_VAR_500, sizeof(struct variable), "variable*", "v", 0, 0, 1, ____BAH_COMPILER_VAR_501, 0);
debugPrint("var_declaration",ft.line,____BAH_COMPILER_VAR_543);
if (isGlobal()) {
char * ____BAH_COMPILER_VAR_544 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(vct);
unsigned int strLen_1 = strlen(";\n");
;                            
            ____BAH_COMPILER_VAR_544 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_544+currStrOff, vct, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_544+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_544));
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
char * ____BAH_COMPILER_VAR_545 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen("\n");
;                            
            ____BAH_COMPILER_VAR_545 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_545+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_545+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_545));
}
else {
char * ____BAH_COMPILER_VAR_546 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(";\n");
;                            
            ____BAH_COMPILER_VAR_546 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_546+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_546+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }struct rope* declR = rope(____BAH_COMPILER_VAR_546);
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
char * ____BAH_COMPILER_VAR_547 =null;char * ____BAH_COMPILER_VAR_548 =string__str(&ct);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpfnArgsCType);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_548);
;                            
            ____BAH_COMPILER_VAR_547 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_547+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_547+currStrOff, ____BAH_COMPILER_VAR_548, strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_547;
j = j+1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_549 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpfnArgsCType);
unsigned int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_549 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_549+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_549+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_549;
}
};
char * ____BAH_COMPILER_VAR_550 =null;char * ____BAH_COMPILER_VAR_551 =string__str(&tmpfnRetCType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpfnArgsCType);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen(")(");
unsigned int strLen_3 = strlen(elemName);
unsigned int strLen_4 = strlen(" (*");
unsigned int strLen_5 = strlen(____BAH_COMPILER_VAR_551);
;                            
            ____BAH_COMPILER_VAR_550 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_550+currStrOff, ____BAH_COMPILER_VAR_551, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_550+currStrOff, " (*", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_550+currStrOff, elemName, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_550+currStrOff, ")(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_550+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_550+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }return ____BAH_COMPILER_VAR_550;
};
char * parseFnHeader(char * prev,__BAH_ARR_TYPE_Tok l,long int* i,struct func* fn,struct Elems* elems){
register long int j = *i;
struct Tok ft = l->data[j];
char * tpdf = "";
if ((ft.type!=TOKEN_TYPE_VAR)) {
throwErr(&ft,"Cannot use {TOKEN} as function name.");
}
char * ____BAH_COMPILER_VAR_552 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(prev);
unsigned int strLen_1 = strlen(ft.cont);
;                            
            ____BAH_COMPILER_VAR_552 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_552+currStrOff, prev, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_552+currStrOff, ft.cont, strLen_1);
            currStrOff += strLen_1;
        
        }fn->name = ____BAH_COMPILER_VAR_552;
array(struct variable*)* arguments = memoryAlloc(sizeof(array(struct variable*)));

arguments->length = 0;
arguments->elemSize = sizeof(struct variable*);
char * ____BAH_COMPILER_VAR_553 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fn->name);
unsigned int strLen_1 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_553 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_553+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_553+currStrOff, "(", strLen_1);
            currStrOff += strLen_1;
        
        }char * code = ____BAH_COMPILER_VAR_553;
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
char * ____BAH_COMPILER_VAR_554 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(argType);
unsigned int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_554 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_554+currStrOff, argType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_554+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }argType = ____BAH_COMPILER_VAR_554;
}
}
else {
isComa = true;
break;
}
j = j+1;
};
struct variable* ____BAH_COMPILER_VAR_555 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_555->name = "";
____BAH_COMPILER_VAR_555->type = "";
____BAH_COMPILER_VAR_555->isConst = false;
____BAH_COMPILER_VAR_555->constVal = "";
____BAH_COMPILER_VAR_555->isArray = false;
____BAH_COMPILER_VAR_555->from = "";
____BAH_COMPILER_VAR_555->declScope= null;
____BAH_COMPILER_VAR_555->isGlobal = false;
____BAH_COMPILER_VAR_555->declRope= null;
____BAH_COMPILER_VAR_555->canBeNull = false;
____BAH_COMPILER_VAR_555->isReg = false;
____BAH_COMPILER_VAR_555->lastSet= null;
____BAH_COMPILER_VAR_555->isArg = false;
struct variable* argument = ____BAH_COMPILER_VAR_555;
argument->name = argName;
argument->type = argType;

    {
        unsigned long nLength = len(arguments);
        if (nLength >= arguments->length) {
            if (nLength >= arguments->realLength) {
                if (arguments->realLength != 0) {
                    arguments->realLength *= 2;
                } else {
                    arguments->realLength = 50;
                }
                void * newPtr = memoryRealloc(arguments->data, (arguments->realLength)*sizeof(struct variable*));
                arguments->data = newPtr;
            }
            arguments->data[len(arguments)] = argument;
            arguments->length = nLength+1;
        } else {
            arguments->data[len(arguments)] = argument;
        }
    }
    ;
struct string argCType = getCType(argType,elems);
struct string cfrt = string(argType);
char * newArgType = string__str(&argCType);
if ((string__hasPrefix(&cfrt,"[]")==1)) {
string__trimLeft(&cfrt,2);
if (string__hasSuffix(&cfrt,"*")) {
long int nbast = string__count(&cfrt,"*");
string__trimRight(&cfrt,nbast);
}
char * ____BAH_COMPILER_VAR_556 =null;char * ____BAH_COMPILER_VAR_557 =string__str(&cfrt);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("__BAH_ARR_TYPE_");
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_557);
;                            
            ____BAH_COMPILER_VAR_556 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_556+currStrOff, "__BAH_ARR_TYPE_", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_556+currStrOff, ____BAH_COMPILER_VAR_557, strLen_1);
            currStrOff += strLen_1;
        
        }newArgType = ____BAH_COMPILER_VAR_556;
array(char *)* csatd = compilerState.arrTypesDecl;
if ((inArrayStr(newArgType,csatd)==false)) {

    {
        unsigned long nLength = len(csatd);
        if (nLength >= csatd->length) {
            if (nLength >= csatd->realLength) {
                if (csatd->realLength != 0) {
                    csatd->realLength *= 2;
                } else {
                    csatd->realLength = 50;
                }
                void * newPtr = memoryRealloc(csatd->data, (csatd->realLength)*sizeof(char *));
                csatd->data = newPtr;
            }
            csatd->data[len(csatd)] = newArgType;
            csatd->length = nLength+1;
        } else {
            csatd->data[len(csatd)] = newArgType;
        }
    }
    ;
char * ____BAH_COMPILER_VAR_558 =null;char * ____BAH_COMPILER_VAR_559 =string__str(&argCType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(newArgType);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen(" ");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_559);
unsigned int strLen_4 = strlen("typedef ");
unsigned int strLen_5 = strlen(tpdf);
;                            
            ____BAH_COMPILER_VAR_558 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_558+currStrOff, tpdf, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_558+currStrOff, "typedef ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_558+currStrOff, ____BAH_COMPILER_VAR_559, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_558+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_558+currStrOff, newArgType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_558+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }tpdf = ____BAH_COMPILER_VAR_558;
}
}
if ((string__hasPrefix(&cfrt,"function(")==1)) {
char * ____BAH_COMPILER_VAR_560 =null;char * ____BAH_COMPILER_VAR_561 =getCfunctionType(&cfrt,argName,elems);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_561);
;                            
            ____BAH_COMPILER_VAR_560 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_560+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_560+currStrOff, ____BAH_COMPILER_VAR_561, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_560;
}
else {
char * ____BAH_COMPILER_VAR_562 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(" ");
unsigned int strLen_1 = strlen(argName);
unsigned int strLen_2 = strlen(newArgType);
unsigned int strLen_3 = strlen(code);
;                            
            ____BAH_COMPILER_VAR_562 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_562+currStrOff, code, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_562+currStrOff, newArgType, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_562+currStrOff, " ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_562+currStrOff, argName, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_562;
}
if ((isComa==true)) {
char * ____BAH_COMPILER_VAR_563 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_563 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_563+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_563+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_563;
}
else {
char * ____BAH_COMPILER_VAR_564 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(")");
;                            
            ____BAH_COMPILER_VAR_564 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_564+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_564+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_564;
break;
}
j = j+1;
};
}
else {
char * ____BAH_COMPILER_VAR_565 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(")");
;                            
            ____BAH_COMPILER_VAR_565 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_565+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_565+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_565;
}
j = j+1;
struct variable* ____BAH_COMPILER_VAR_566 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_566->name = "";
____BAH_COMPILER_VAR_566->type = "";
____BAH_COMPILER_VAR_566->isConst = false;
____BAH_COMPILER_VAR_566->constVal = "";
____BAH_COMPILER_VAR_566->isArray = false;
____BAH_COMPILER_VAR_566->from = "";
____BAH_COMPILER_VAR_566->declScope= null;
____BAH_COMPILER_VAR_566->isGlobal = false;
____BAH_COMPILER_VAR_566->declRope= null;
____BAH_COMPILER_VAR_566->canBeNull = false;
____BAH_COMPILER_VAR_566->isReg = false;
____BAH_COMPILER_VAR_566->lastSet= null;
____BAH_COMPILER_VAR_566->isArg = false;
struct variable* returns = ____BAH_COMPILER_VAR_566;
returns->type = "";
while ((j<len(l))) {
t = l->data[j];
if ((strcmp(t.cont, "{") == 0)) {
break;
}
char * ____BAH_COMPILER_VAR_567 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(returns->type);
unsigned int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_567 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_567+currStrOff, returns->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_567+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }returns->type = ____BAH_COMPILER_VAR_567;
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
char * ____BAH_COMPILER_VAR_568 =null;char * ____BAH_COMPILER_VAR_569 =string__str(&cfrt);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("__BAH_ARR_TYPE_");
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_569);
;                            
            ____BAH_COMPILER_VAR_568 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_568+currStrOff, "__BAH_ARR_TYPE_", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_568+currStrOff, ____BAH_COMPILER_VAR_569, strLen_1);
            currStrOff += strLen_1;
        
        }newFnRetType = ____BAH_COMPILER_VAR_568;
array(char *)* csatd = compilerState.arrTypesDecl;
if ((inArrayStr(newFnRetType,csatd)==false)) {

    {
        unsigned long nLength = len(csatd);
        if (nLength >= csatd->length) {
            if (nLength >= csatd->realLength) {
                if (csatd->realLength != 0) {
                    csatd->realLength *= 2;
                } else {
                    csatd->realLength = 50;
                }
                void * newPtr = memoryRealloc(csatd->data, (csatd->realLength)*sizeof(char *));
                csatd->data = newPtr;
            }
            csatd->data[len(csatd)] = newFnRetType;
            csatd->length = nLength+1;
        } else {
            csatd->data[len(csatd)] = newFnRetType;
        }
    }
    ;
char * ____BAH_COMPILER_VAR_570 =null;char * ____BAH_COMPILER_VAR_571 =string__str(&fnRetType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(newFnRetType);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen(" ");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_571);
unsigned int strLen_4 = strlen("typedef ");
unsigned int strLen_5 = strlen(tpdf);
;                            
            ____BAH_COMPILER_VAR_570 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_570+currStrOff, tpdf, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_570+currStrOff, "typedef ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_570+currStrOff, ____BAH_COMPILER_VAR_571, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_570+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_570+currStrOff, newFnRetType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_570+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }tpdf = ____BAH_COMPILER_VAR_570;
}
}
char * ____BAH_COMPILER_VAR_572 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(" ");
unsigned int strLen_1 = strlen(code);
unsigned int strLen_2 = strlen(newFnRetType);
unsigned int strLen_3 = strlen(tpdf);
;                            
            ____BAH_COMPILER_VAR_572 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_572+currStrOff, tpdf, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_572+currStrOff, newFnRetType, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_572+currStrOff, " ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_572+currStrOff, code, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_572;
return code;
};
void parseStruct(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
struct cStruct* ____BAH_COMPILER_VAR_573 = memoryAlloc(sizeof(struct cStruct));
____BAH_COMPILER_VAR_573->name = "";
____BAH_COMPILER_VAR_573->members = memoryAlloc(sizeof(array(struct structMemb*)));
            ____BAH_COMPILER_VAR_573->members->length = 0;
            ____BAH_COMPILER_VAR_573->members->elemSize = sizeof(struct structMemb*);
            ____BAH_COMPILER_VAR_573->methods = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_573->methods->length = 0;
            ____BAH_COMPILER_VAR_573->methods->elemSize = sizeof(struct func*);
            ____BAH_COMPILER_VAR_573->postCode = "";
____BAH_COMPILER_VAR_573->extendedFrom = "";
____BAH_COMPILER_VAR_573->isBinding = false;
____BAH_COMPILER_VAR_573->hasRCPmemb = false;
struct cStruct* s = ____BAH_COMPILER_VAR_573;
array(struct cStruct*)* structs = elems->structs;

    {
        unsigned long nLength = len(structs);
        if (nLength >= structs->length) {
            if (nLength >= structs->realLength) {
                if (structs->realLength != 0) {
                    structs->realLength *= 2;
                } else {
                    structs->realLength = 50;
                }
                void * newPtr = memoryRealloc(structs->data, (structs->realLength)*sizeof(struct cStruct*));
                structs->data = newPtr;
            }
            structs->data[len(structs)] = s;
            structs->length = nLength+1;
        } else {
            structs->data[len(structs)] = s;
        }
    }
    ;
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
char * ____BAH_COMPILER_VAR_574 =null;char * ____BAH_COMPILER_VAR_575 =string__str(&ct);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpfnArgsCType);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_575);
;                            
            ____BAH_COMPILER_VAR_574 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_574+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_574+currStrOff, ____BAH_COMPILER_VAR_575, strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_574;
j = j+1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_576 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpfnArgsCType);
unsigned int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_576 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_576+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_576+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_576;
}
};
char * ____BAH_COMPILER_VAR_577 =null;char * ____BAH_COMPILER_VAR_578 =string__str(&tmpfnRetCType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpfnArgsCType);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen(")(");
unsigned int strLen_3 = strlen(em->name);
unsigned int strLen_4 = strlen(" (*");
unsigned int strLen_5 = strlen(____BAH_COMPILER_VAR_578);
;                            
            ____BAH_COMPILER_VAR_577 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_577+currStrOff, ____BAH_COMPILER_VAR_578, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_577+currStrOff, " (*", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_577+currStrOff, em->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_577+currStrOff, ")(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_577+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_577+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }membDeclStr = ____BAH_COMPILER_VAR_577;
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

    {
        unsigned long nLength = len(allMembs);
        if (nLength >= allMembs->length) {
            if (nLength >= allMembs->realLength) {
                if (allMembs->realLength != 0) {
                    allMembs->realLength *= 2;
                } else {
                    allMembs->realLength = 50;
                }
                void * newPtr = memoryRealloc(allMembs->data, (allMembs->realLength)*sizeof(char *));
                allMembs->data = newPtr;
            }
            allMembs->data[len(allMembs)] = membDeclStr;
            allMembs->length = nLength+1;
        } else {
            allMembs->data[len(allMembs)] = membDeclStr;
        }
    }
    ;

    {
        unsigned long nLength = len(members);
        if (nLength >= members->length) {
            if (nLength >= members->realLength) {
                if (members->realLength != 0) {
                    members->realLength *= 2;
                } else {
                    members->realLength = 50;
                }
                void * newPtr = memoryRealloc(members->data, (members->realLength)*sizeof(struct structMemb*));
                members->data = newPtr;
            }
            members->data[len(members)] = em;
            members->length = nLength+1;
        } else {
            members->data[len(members)] = em;
        }
    }
    ;
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
struct structMemb* ____BAH_COMPILER_VAR_579 = memoryAlloc(sizeof(struct structMemb));
____BAH_COMPILER_VAR_579->name = "";
____BAH_COMPILER_VAR_579->type = "";
____BAH_COMPILER_VAR_579->isConst = false;
____BAH_COMPILER_VAR_579->constVal = "";
____BAH_COMPILER_VAR_579->isArray = false;
____BAH_COMPILER_VAR_579->from = "";
____BAH_COMPILER_VAR_579->declScope= null;
____BAH_COMPILER_VAR_579->isGlobal = false;
____BAH_COMPILER_VAR_579->declRope= null;
____BAH_COMPILER_VAR_579->canBeNull = false;
____BAH_COMPILER_VAR_579->isReg = false;
____BAH_COMPILER_VAR_579->lastSet= null;
____BAH_COMPILER_VAR_579->isArg = false;
____BAH_COMPILER_VAR_579->def = "";
____BAH_COMPILER_VAR_579->isFn = false;
struct structMemb* memb = ____BAH_COMPILER_VAR_579;
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
char * ____BAH_COMPILER_VAR_580 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s->name);
unsigned int strLen_1 = strlen("__");
;                            
            ____BAH_COMPILER_VAR_580 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_580+currStrOff, s->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_580+currStrOff, "__", strLen_1);
            currStrOff += strLen_1;
        
        }char * fnPrefix = ____BAH_COMPILER_VAR_580;
struct func* ____BAH_COMPILER_VAR_581 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_581->name = "";
____BAH_COMPILER_VAR_581->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_581->args->length = 0;
            ____BAH_COMPILER_VAR_581->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_581->returns= null;
____BAH_COMPILER_VAR_581->isBinding = false;
____BAH_COMPILER_VAR_581->from = "";
____BAH_COMPILER_VAR_581->file = "";
____BAH_COMPILER_VAR_581->line = 1;
____BAH_COMPILER_VAR_581->isVar = false;
____BAH_COMPILER_VAR_581->used = false;
____BAH_COMPILER_VAR_581->code = null;
____BAH_COMPILER_VAR_581->isMut = false;
____BAH_COMPILER_VAR_581->isImported = false;
____BAH_COMPILER_VAR_581->exits = false;
struct func* fn = ____BAH_COMPILER_VAR_581;
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
        unsigned long nLength = len(nl);
        if (nLength >= nl->length) {
            if (nLength >= nl->realLength) {
                if (nl->realLength != 0) {
                    nl->realLength *= 2;
                } else {
                    nl->realLength = 50;
                }
                void * newPtr = memoryRealloc(nl->data, (nl->realLength)*sizeof(struct Tok));
                nl->data = newPtr;
            }
            nl->data[len(nl)] = t;
            nl->length = nLength+1;
        } else {
            nl->data[len(nl)] = t;
        }
    }
    ;
if ((j==i)) {
t.type = TOKEN_TYPE_VAR;
t.cont = "this";
t.isValue = true;

    {
        unsigned long nLength = len(nl);
        if (nLength >= nl->length) {
            if (nLength >= nl->realLength) {
                if (nl->realLength != 0) {
                    nl->realLength *= 2;
                } else {
                    nl->realLength = 50;
                }
                void * newPtr = memoryRealloc(nl->data, (nl->realLength)*sizeof(struct Tok));
                nl->data = newPtr;
            }
            nl->data[len(nl)] = t;
            nl->length = nLength+1;
        } else {
            nl->data[len(nl)] = t;
        }
    }
    ;
t.type = TOKEN_TYPE_VAR;
char * ____BAH_COMPILER_VAR_582 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s->name);
unsigned int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_582 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_582+currStrOff, s->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_582+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_582;
t.isValue = true;

    {
        unsigned long nLength = len(nl);
        if (nLength >= nl->length) {
            if (nLength >= nl->realLength) {
                if (nl->realLength != 0) {
                    nl->realLength *= 2;
                } else {
                    nl->realLength = 50;
                }
                void * newPtr = memoryRealloc(nl->data, (nl->realLength)*sizeof(struct Tok));
                nl->data = newPtr;
            }
            nl->data[len(nl)] = t;
            nl->length = nLength+1;
        } else {
            nl->data[len(nl)] = t;
        }
    }
    ;
struct Tok nt = l->data[j+1];
if ((strcmp(nt.cont, ")") != 0)) {
t.type = TOKEN_TYPE_SYNTAX;
t.cont = ",";
t.isValue = false;

    {
        unsigned long nLength = len(nl);
        if (nLength >= nl->length) {
            if (nLength >= nl->realLength) {
                if (nl->realLength != 0) {
                    nl->realLength *= 2;
                } else {
                    nl->realLength = 50;
                }
                void * newPtr = memoryRealloc(nl->data, (nl->realLength)*sizeof(struct Tok));
                nl->data = newPtr;
            }
            nl->data[len(nl)] = t;
            nl->length = nLength+1;
        } else {
            nl->data[len(nl)] = t;
        }
    }
    ;
}
}
j = j+1;
};
--i;
long int nli = 0;
char * ____BAH_COMPILER_VAR_583 =parseFnHeader(fnPrefix,nl,&nli,fn,elems);struct rope* code = rope(____BAH_COMPILER_VAR_583);
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

    {
        unsigned long nLength = len(fnElems->vars);
        if (nLength >= fnElems->vars->length) {
            if (nLength >= fnElems->vars->realLength) {
                if (fnElems->vars->realLength != 0) {
                    fnElems->vars->realLength *= 2;
                } else {
                    fnElems->vars->realLength = 50;
                }
                void * newPtr = memoryRealloc(fnElems->vars->data, (fnElems->vars->realLength)*sizeof(struct variable*));
                fnElems->vars->data = newPtr;
            }
            fnElems->vars->data[len(fnElems->vars)] = a;
            fnElems->vars->length = nLength+1;
        } else {
            fnElems->vars->data[len(fnElems->vars)] = a;
        }
    }
    ;
};
array(struct func*)* fns = elems->fns;

    {
        unsigned long nLength = len(fns);
        if (nLength >= fns->length) {
            if (nLength >= fns->realLength) {
                if (fns->realLength != 0) {
                    fns->realLength *= 2;
                } else {
                    fns->realLength = 50;
                }
                void * newPtr = memoryRealloc(fns->data, (fns->realLength)*sizeof(struct func*));
                fns->data = newPtr;
            }
            fns->data[len(fns)] = fn;
            fns->length = nLength+1;
        } else {
            fns->data[len(fns)] = fn;
        }
    }
    ;
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

    {
        unsigned long nLength = len(tokens);
        if (nLength >= tokens->length) {
            if (nLength >= tokens->realLength) {
                if (tokens->realLength != 0) {
                    tokens->realLength *= 2;
                } else {
                    tokens->realLength = 50;
                }
                void * newPtr = memoryRealloc(tokens->data, (tokens->realLength)*sizeof(struct Tok));
                tokens->data = newPtr;
            }
            tokens->data[len(tokens)] = t;
            tokens->length = nLength+1;
        } else {
            tokens->data[len(tokens)] = t;
        }
    }
    ;
++i;
};
struct func* ____BAH_COMPILER_VAR_584 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_584->name = "";
____BAH_COMPILER_VAR_584->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_584->args->length = 0;
            ____BAH_COMPILER_VAR_584->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_584->returns= null;
____BAH_COMPILER_VAR_584->isBinding = false;
____BAH_COMPILER_VAR_584->from = "";
____BAH_COMPILER_VAR_584->file = "";
____BAH_COMPILER_VAR_584->line = 1;
____BAH_COMPILER_VAR_584->isVar = false;
____BAH_COMPILER_VAR_584->used = false;
____BAH_COMPILER_VAR_584->code = null;
____BAH_COMPILER_VAR_584->isMut = false;
____BAH_COMPILER_VAR_584->isImported = false;
____BAH_COMPILER_VAR_584->exits = false;
struct func* mfn = ____BAH_COMPILER_VAR_584;
mfn->args = fn->args;
mfn->name = fn->name;
mfn->returns = fn->returns;
mfn->from = s->name;
strTrimLeft(&mfn->name,strlen(fnPrefix));

    {
        unsigned long nLength = len(methds);
        if (nLength >= methds->length) {
            if (nLength >= methds->realLength) {
                if (methds->realLength != 0) {
                    methds->realLength *= 2;
                } else {
                    methds->realLength = 50;
                }
                void * newPtr = memoryRealloc(methds->data, (methds->realLength)*sizeof(struct func*));
                methds->data = newPtr;
            }
            methds->data[len(methds)] = mfn;
            methds->length = nLength+1;
        } else {
            methds->data[len(methds)] = mfn;
        }
    }
    ;
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
char * ____BAH_COMPILER_VAR_585 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fn->name);
unsigned int strLen_1 = strlen("' is not returned.");
unsigned int strLen_2 = strlen("Function '");
;                            
            ____BAH_COMPILER_VAR_585 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_585+currStrOff, "Function '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_585+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_585+currStrOff, "' is not returned.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&l->data[len(l)-1],____BAH_COMPILER_VAR_585);
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
char * ____BAH_COMPILER_VAR_586 =null;char * ____BAH_COMPILER_VAR_587 =rope__toStr(code);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nextLine);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_587);
;                            
            ____BAH_COMPILER_VAR_586 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_586+currStrOff, nextLine, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_586+currStrOff, ____BAH_COMPILER_VAR_587, strLen_1);
            currStrOff += strLen_1;
        
        }nextLine = ____BAH_COMPILER_VAR_586;
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
char * ____BAH_COMPILER_VAR_588 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(mbmType);
unsigned int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_588 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_588+currStrOff, mbmType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_588+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }mbmType = ____BAH_COMPILER_VAR_588;
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
char * ____BAH_COMPILER_VAR_589 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(memb->type);
unsigned int strLen_1 = strlen(" for member.");
unsigned int strLen_2 = strlen(") as ");
unsigned int strLen_3 = strlen(tt);
unsigned int strLen_4 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_589 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_589+currStrOff, "Cannot use {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_589+currStrOff, tt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_589+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_589+currStrOff, memb->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_589+currStrOff, " for member.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&t,____BAH_COMPILER_VAR_589);
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

    {
        unsigned long nLength = len(members);
        if (nLength >= members->length) {
            if (nLength >= members->realLength) {
                if (members->realLength != 0) {
                    members->realLength *= 2;
                } else {
                    members->realLength = 50;
                }
                void * newPtr = memoryRealloc(members->data, (members->realLength)*sizeof(struct structMemb*));
                members->data = newPtr;
            }
            members->data[len(members)] = memb;
            members->length = nLength+1;
        } else {
            members->data[len(members)] = memb;
        }
    }
    ;
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
char * ____BAH_COMPILER_VAR_590 =null;char * ____BAH_COMPILER_VAR_591 =string__str(&ct);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpfnArgsCType);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_591);
;                            
            ____BAH_COMPILER_VAR_590 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_590+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_590+currStrOff, ____BAH_COMPILER_VAR_591, strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_590;
j = j+1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_592 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpfnArgsCType);
unsigned int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_592 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_592+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_592+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_592;
}
};
char * ____BAH_COMPILER_VAR_593 =null;char * ____BAH_COMPILER_VAR_594 =string__str(&tmpfnRetCType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpfnArgsCType);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen(")(");
unsigned int strLen_3 = strlen(memb->name);
unsigned int strLen_4 = strlen(" (*");
unsigned int strLen_5 = strlen(____BAH_COMPILER_VAR_594);
;                            
            ____BAH_COMPILER_VAR_593 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_593+currStrOff, ____BAH_COMPILER_VAR_594, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_593+currStrOff, " (*", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_593+currStrOff, memb->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_593+currStrOff, ")(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_593+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_593+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }membDeclStr = ____BAH_COMPILER_VAR_593;
}
else {
struct string membDecl = getCType(memb->type,elems);
char * ____BAH_COMPILER_VAR_595 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(" ");
unsigned int strLen_1 = strlen(memb->name);
;                            
            ____BAH_COMPILER_VAR_595 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_595+currStrOff, " ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_595+currStrOff, memb->name, strLen_1);
            currStrOff += strLen_1;
        
        }string__append(&membDecl,____BAH_COMPILER_VAR_595);
membDeclStr = string__str(&membDecl);
}

    {
        unsigned long nLength = len(allMembs);
        if (nLength >= allMembs->length) {
            if (nLength >= allMembs->realLength) {
                if (allMembs->realLength != 0) {
                    allMembs->realLength *= 2;
                } else {
                    allMembs->realLength = 50;
                }
                void * newPtr = memoryRealloc(allMembs->data, (allMembs->realLength)*sizeof(char *));
                allMembs->data = newPtr;
            }
            allMembs->data[len(allMembs)] = membDeclStr;
            allMembs->length = nLength+1;
        } else {
            allMembs->data[len(allMembs)] = membDeclStr;
        }
    }
    ;
++i;
};
s->members = members;
if ((doesOutput==true)) {
OUTPUT = OOUT;
NEXT_LINE = nextLine;
char * ____BAH_COMPILER_VAR_596 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s->name);
unsigned int strLen_1 = strlen(" {\n");
unsigned int strLen_2 = strlen("struct ");
;                            
            ____BAH_COMPILER_VAR_596 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_596+currStrOff, "struct ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_596+currStrOff, s->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_596+currStrOff, " {\n", strLen_1);
            currStrOff += strLen_1;
        
        }struct rope* code = rope(____BAH_COMPILER_VAR_596);
i = 0;
while ((i<len(allMembs))) {
char * m = allMembs->data[i];
char * ____BAH_COMPILER_VAR_597 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(m);
unsigned int strLen_1 = strlen(";\n");
;                            
            ____BAH_COMPILER_VAR_597 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_597+currStrOff, m, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_597+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }code = rope__add(code, rope(____BAH_COMPILER_VAR_597));
++i;
};
code = rope__add(code, rope("};\n"));
OUTPUT = rope__add(OUTPUT, code);
}
if ((debug==true)) {
struct debugStruct* ____BAH_COMPILER_VAR_598 = memoryAlloc(sizeof(struct debugStruct));
____BAH_COMPILER_VAR_598->name= null;
____BAH_COMPILER_VAR_598->membs = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_598->membs->length = 0;
            ____BAH_COMPILER_VAR_598->membs->elemSize = sizeof(struct variable*);
            struct debugStruct* ds = ____BAH_COMPILER_VAR_598;
ds->name = s->name;
i = 0;
while ((i<len(s->members))) {
struct structMemb* m = s->members->data[i];
struct variable* ____BAH_COMPILER_VAR_599 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_599->name = "";
____BAH_COMPILER_VAR_599->type = "";
____BAH_COMPILER_VAR_599->isConst = false;
____BAH_COMPILER_VAR_599->constVal = "";
____BAH_COMPILER_VAR_599->isArray = false;
____BAH_COMPILER_VAR_599->from = "";
____BAH_COMPILER_VAR_599->declScope= null;
____BAH_COMPILER_VAR_599->isGlobal = false;
____BAH_COMPILER_VAR_599->declRope= null;
____BAH_COMPILER_VAR_599->canBeNull = false;
____BAH_COMPILER_VAR_599->isReg = false;
____BAH_COMPILER_VAR_599->lastSet= null;
____BAH_COMPILER_VAR_599->isArg = false;
struct variable* mv = ____BAH_COMPILER_VAR_599;
mv->name = m->name;
mv->type = m->type;
mv->isConst = false;
mv->isArray = m->isArray;

    {
        unsigned long nLength = i;
        if (nLength >= ds->membs->length) {
            if (nLength >= ds->membs->realLength) {
                if (ds->membs->realLength != 0) {
                    ds->membs->realLength *= 2;
                } else {
                    ds->membs->realLength = 50;
                }
                void * newPtr = memoryRealloc(ds->membs->data, (ds->membs->realLength)*sizeof(struct variable*));
                ds->membs->data = newPtr;
            }
            ds->membs->data[i] = mv;
            ds->membs->length = nLength+1;
        } else {
            ds->membs->data[i] = mv;
        }
    }
    ;
i = i+1;
};
struct debugStruct* ____BAH_COMPILER_VAR_600 = ds;
char ** ____BAH_COMPILER_VAR_602 = (char **)((char*)(____BAH_COMPILER_VAR_600) + offsetof(struct debugStruct, name));
struct reflectElement ____BAH_COMPILER_VAR_603 = __reflect(____BAH_COMPILER_VAR_602, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct debugStruct, name));
array(struct variable*)** ____BAH_COMPILER_VAR_604 = (array(struct variable*)**)((char*)(____BAH_COMPILER_VAR_600) + offsetof(struct debugStruct, membs));
struct variable** ____BAH_COMPILER_VAR_605 = 0;
char ** ____BAH_COMPILER_VAR_607 = (char **)((char*)(____BAH_COMPILER_VAR_605) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_608 = __reflect(____BAH_COMPILER_VAR_607, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_609 = (char **)((char*)(____BAH_COMPILER_VAR_605) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_610 = __reflect(____BAH_COMPILER_VAR_609, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_611 = (char*)((char*)(____BAH_COMPILER_VAR_605) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_612 = __reflect(____BAH_COMPILER_VAR_611, sizeof(char), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_613 = (char **)((char*)(____BAH_COMPILER_VAR_605) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_614 = __reflect(____BAH_COMPILER_VAR_613, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_615 = (char*)((char*)(____BAH_COMPILER_VAR_605) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_616 = __reflect(____BAH_COMPILER_VAR_615, sizeof(char), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_617 = (char **)((char*)(____BAH_COMPILER_VAR_605) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_618 = __reflect(____BAH_COMPILER_VAR_617, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
void ** ____BAH_COMPILER_VAR_619 = (void **)((char*)(____BAH_COMPILER_VAR_605) + offsetof(struct variable, declScope));
struct reflectElement ____BAH_COMPILER_VAR_620 = __reflect(____BAH_COMPILER_VAR_619, sizeof(void *), "ptr", "declScope", 0, 0, 0, 0, offsetof(struct variable, declScope));
char* ____BAH_COMPILER_VAR_621 = (char*)((char*)(____BAH_COMPILER_VAR_605) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_622 = __reflect(____BAH_COMPILER_VAR_621, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));
struct rope** ____BAH_COMPILER_VAR_623 = (struct rope**)((char*)(____BAH_COMPILER_VAR_605) + offsetof(struct variable, declRope));
void ** ____BAH_COMPILER_VAR_625 = (void **)((char*)(____BAH_COMPILER_VAR_623) + offsetof(struct rope, left));
struct reflectElement ____BAH_COMPILER_VAR_626 = __reflect(____BAH_COMPILER_VAR_625, sizeof(void *), "ptr", "left", 0, 0, 0, 0, offsetof(struct rope, left));
void ** ____BAH_COMPILER_VAR_627 = (void **)((char*)(____BAH_COMPILER_VAR_623) + offsetof(struct rope, right));
struct reflectElement ____BAH_COMPILER_VAR_628 = __reflect(____BAH_COMPILER_VAR_627, sizeof(void *), "ptr", "right", 0, 0, 0, 0, offsetof(struct rope, right));
char ** ____BAH_COMPILER_VAR_629 = (char **)((char*)(____BAH_COMPILER_VAR_623) + offsetof(struct rope, str));
struct reflectElement ____BAH_COMPILER_VAR_630 = __reflect(____BAH_COMPILER_VAR_629, sizeof(char *), "cpstring", "str", 0, 0, 0, 0, offsetof(struct rope, str));
int* ____BAH_COMPILER_VAR_631 = (int*)((char*)(____BAH_COMPILER_VAR_623) + offsetof(struct rope, lCount));
struct reflectElement ____BAH_COMPILER_VAR_632 = __reflect(____BAH_COMPILER_VAR_631, sizeof(int), "int32", "lCount", 0, 0, 0, 0, offsetof(struct rope, lCount));
int* ____BAH_COMPILER_VAR_633 = (int*)((char*)(____BAH_COMPILER_VAR_623) + offsetof(struct rope, len));
struct reflectElement ____BAH_COMPILER_VAR_634 = __reflect(____BAH_COMPILER_VAR_633, sizeof(int), "int32", "len", 0, 0, 0, 0, offsetof(struct rope, len));
int* ____BAH_COMPILER_VAR_635 = (int*)((char*)(____BAH_COMPILER_VAR_623) + offsetof(struct rope, totalLen));
struct reflectElement ____BAH_COMPILER_VAR_636 = __reflect(____BAH_COMPILER_VAR_635, sizeof(int), "int32", "totalLen", 0, 0, 0, 0, offsetof(struct rope, totalLen));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_624 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_624->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_624->length = 6;
        ____BAH_COMPILER_VAR_624->data = memoryAlloc(____BAH_COMPILER_VAR_624->length * ____BAH_COMPILER_VAR_624->elemSize);
        ____BAH_COMPILER_VAR_624->data[0] = ____BAH_COMPILER_VAR_626;
____BAH_COMPILER_VAR_624->data[1] = ____BAH_COMPILER_VAR_628;
____BAH_COMPILER_VAR_624->data[2] = ____BAH_COMPILER_VAR_630;
____BAH_COMPILER_VAR_624->data[3] = ____BAH_COMPILER_VAR_632;
____BAH_COMPILER_VAR_624->data[4] = ____BAH_COMPILER_VAR_634;
____BAH_COMPILER_VAR_624->data[5] = ____BAH_COMPILER_VAR_636;
struct reflectElement ____BAH_COMPILER_VAR_637 = __reflect(____BAH_COMPILER_VAR_623, sizeof(struct rope), "rope*", "declRope", 0, 0, 1, ____BAH_COMPILER_VAR_624, offsetof(struct variable, declRope));
char* ____BAH_COMPILER_VAR_638 = (char*)((char*)(____BAH_COMPILER_VAR_605) + offsetof(struct variable, canBeNull));
struct reflectElement ____BAH_COMPILER_VAR_639 = __reflect(____BAH_COMPILER_VAR_638, sizeof(char), "bool", "canBeNull", 0, 0, 0, 0, offsetof(struct variable, canBeNull));
char* ____BAH_COMPILER_VAR_640 = (char*)((char*)(____BAH_COMPILER_VAR_605) + offsetof(struct variable, canBeReg));
struct reflectElement ____BAH_COMPILER_VAR_641 = __reflect(____BAH_COMPILER_VAR_640, sizeof(char), "bool", "canBeReg", 0, 0, 0, 0, offsetof(struct variable, canBeReg));
char* ____BAH_COMPILER_VAR_642 = (char*)((char*)(____BAH_COMPILER_VAR_605) + offsetof(struct variable, isReg));
struct reflectElement ____BAH_COMPILER_VAR_643 = __reflect(____BAH_COMPILER_VAR_642, sizeof(char), "bool", "isReg", 0, 0, 0, 0, offsetof(struct variable, isReg));
void ** ____BAH_COMPILER_VAR_644 = (void **)((char*)(____BAH_COMPILER_VAR_605) + offsetof(struct variable, lastSet));
struct reflectElement ____BAH_COMPILER_VAR_645 = __reflect(____BAH_COMPILER_VAR_644, sizeof(void *), "ptr", "lastSet", 0, 0, 0, 0, offsetof(struct variable, lastSet));
char* ____BAH_COMPILER_VAR_646 = (char*)((char*)(____BAH_COMPILER_VAR_605) + offsetof(struct variable, isArg));
struct reflectElement ____BAH_COMPILER_VAR_647 = __reflect(____BAH_COMPILER_VAR_646, sizeof(char), "bool", "isArg", 0, 0, 0, 0, offsetof(struct variable, isArg));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_606 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_606->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_606->length = 14;
        ____BAH_COMPILER_VAR_606->data = memoryAlloc(____BAH_COMPILER_VAR_606->length * ____BAH_COMPILER_VAR_606->elemSize);
        ____BAH_COMPILER_VAR_606->data[0] = ____BAH_COMPILER_VAR_608;
____BAH_COMPILER_VAR_606->data[1] = ____BAH_COMPILER_VAR_610;
____BAH_COMPILER_VAR_606->data[2] = ____BAH_COMPILER_VAR_612;
____BAH_COMPILER_VAR_606->data[3] = ____BAH_COMPILER_VAR_614;
____BAH_COMPILER_VAR_606->data[4] = ____BAH_COMPILER_VAR_616;
____BAH_COMPILER_VAR_606->data[5] = ____BAH_COMPILER_VAR_618;
____BAH_COMPILER_VAR_606->data[6] = ____BAH_COMPILER_VAR_620;
____BAH_COMPILER_VAR_606->data[7] = ____BAH_COMPILER_VAR_622;
____BAH_COMPILER_VAR_606->data[8] = ____BAH_COMPILER_VAR_637;
____BAH_COMPILER_VAR_606->data[9] = ____BAH_COMPILER_VAR_639;
____BAH_COMPILER_VAR_606->data[10] = ____BAH_COMPILER_VAR_641;
____BAH_COMPILER_VAR_606->data[11] = ____BAH_COMPILER_VAR_643;
____BAH_COMPILER_VAR_606->data[12] = ____BAH_COMPILER_VAR_645;
____BAH_COMPILER_VAR_606->data[13] = ____BAH_COMPILER_VAR_647;
struct reflectElement ____BAH_COMPILER_VAR_648 = __reflect(____BAH_COMPILER_VAR_605, sizeof(struct variable), "variable*", "", 0, 0, 1, ____BAH_COMPILER_VAR_606, 0);

        struct reflectElement ____BAH_COMPILER_VAR_649 = ____BAH_COMPILER_VAR_648;
        struct reflectElement ____BAH_COMPILER_VAR_650 = __reflect(____BAH_COMPILER_VAR_604, sizeof(array(struct variable*)*), "[]variable*", "membs", 1, &____BAH_COMPILER_VAR_649, 0, 0, offsetof(struct debugStruct, membs));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_601 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_601->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_601->length = 2;
        ____BAH_COMPILER_VAR_601->data = memoryAlloc(____BAH_COMPILER_VAR_601->length * ____BAH_COMPILER_VAR_601->elemSize);
        ____BAH_COMPILER_VAR_601->data[0] = ____BAH_COMPILER_VAR_603;
____BAH_COMPILER_VAR_601->data[1] = ____BAH_COMPILER_VAR_650;
struct reflectElement ____BAH_COMPILER_VAR_651 = __reflect(____BAH_COMPILER_VAR_600, sizeof(struct debugStruct), "debugStruct*", "ds", 0, 0, 1, ____BAH_COMPILER_VAR_601, 0);
debugPrint("struct_declare",nameToken.line,____BAH_COMPILER_VAR_651);
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
struct func* ____BAH_COMPILER_VAR_652 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_652->name = "";
____BAH_COMPILER_VAR_652->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_652->args->length = 0;
            ____BAH_COMPILER_VAR_652->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_652->returns= null;
____BAH_COMPILER_VAR_652->isBinding = false;
____BAH_COMPILER_VAR_652->from = "";
____BAH_COMPILER_VAR_652->file = "";
____BAH_COMPILER_VAR_652->line = 1;
____BAH_COMPILER_VAR_652->isVar = false;
____BAH_COMPILER_VAR_652->used = false;
____BAH_COMPILER_VAR_652->code = null;
____BAH_COMPILER_VAR_652->isMut = false;
____BAH_COMPILER_VAR_652->isImported = false;
____BAH_COMPILER_VAR_652->exits = false;
struct func* fn = ____BAH_COMPILER_VAR_652;
char * code = parseFnHeader("",l,&i,fn,elems);
array(struct func*)* fns = elems->fns;
fn->isBinding = true;

    {
        unsigned long nLength = len(fns);
        if (nLength >= fns->length) {
            if (nLength >= fns->realLength) {
                if (fns->realLength != 0) {
                    fns->realLength *= 2;
                } else {
                    fns->realLength = 50;
                }
                void * newPtr = memoryRealloc(fns->data, (fns->realLength)*sizeof(struct func*));
                fns->data = newPtr;
            }
            fns->data[len(fns)] = fn;
            fns->length = nLength+1;
        } else {
            fns->data[len(fns)] = fn;
        }
    }
    ;
if ((doesOutput==true)) {
char * ____BAH_COMPILER_VAR_653 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(";\n");
;                            
            ____BAH_COMPILER_VAR_653 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_653+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_653+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_653));
}
}
else {
char * tp = "";
++i;
for (; (i<len(l)); ++i) {
struct Tok t = l->data[i];
char * ____BAH_COMPILER_VAR_654 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tp);
unsigned int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_654 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_654+currStrOff, tp, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_654+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }tp = ____BAH_COMPILER_VAR_654;
};
if ((ft.type!=TOKEN_TYPE_VAR)) {
throwErr(&ft,"Cannot use {TOKEN} as new type name.");
}
struct string cTypeNewType = getCType(tp,elems);
char * cTypeNewTypeStr = string__str(&cTypeNewType);
if ((doesOutput==true)) {
char * ____BAH_COMPILER_VAR_655 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ft.cont);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen(" ");
unsigned int strLen_3 = strlen(cTypeNewTypeStr);
unsigned int strLen_4 = strlen("typedef ");
;                            
            ____BAH_COMPILER_VAR_655 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_655+currStrOff, "typedef ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_655+currStrOff, cTypeNewTypeStr, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_655+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_655+currStrOff, ft.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_655+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_655));
}
if ((debug==true)) {
struct debugType* ____BAH_COMPILER_VAR_656 = memoryAlloc(sizeof(struct debugType));
____BAH_COMPILER_VAR_656->name= null;
____BAH_COMPILER_VAR_656->refers= null;
struct debugType* dt = ____BAH_COMPILER_VAR_656;
dt->name = ft.cont;
dt->refers = tp;
struct debugType* ____BAH_COMPILER_VAR_657 = dt;
char ** ____BAH_COMPILER_VAR_659 = (char **)((char*)(____BAH_COMPILER_VAR_657) + offsetof(struct debugType, name));
struct reflectElement ____BAH_COMPILER_VAR_660 = __reflect(____BAH_COMPILER_VAR_659, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct debugType, name));
char ** ____BAH_COMPILER_VAR_661 = (char **)((char*)(____BAH_COMPILER_VAR_657) + offsetof(struct debugType, refers));
struct reflectElement ____BAH_COMPILER_VAR_662 = __reflect(____BAH_COMPILER_VAR_661, sizeof(char *), "cpstring", "refers", 0, 0, 0, 0, offsetof(struct debugType, refers));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_658 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_658->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_658->length = 2;
        ____BAH_COMPILER_VAR_658->data = memoryAlloc(____BAH_COMPILER_VAR_658->length * ____BAH_COMPILER_VAR_658->elemSize);
        ____BAH_COMPILER_VAR_658->data[0] = ____BAH_COMPILER_VAR_660;
____BAH_COMPILER_VAR_658->data[1] = ____BAH_COMPILER_VAR_662;
struct reflectElement ____BAH_COMPILER_VAR_663 = __reflect(____BAH_COMPILER_VAR_657, sizeof(struct debugType), "debugType*", "dt", 0, 0, 1, ____BAH_COMPILER_VAR_658, 0);
debugPrint("type_declare",ft.line,____BAH_COMPILER_VAR_663);
}
array(char *)* tps = elems->types;

    {
        unsigned long nLength = len(tps);
        if (nLength >= tps->length) {
            if (nLength >= tps->realLength) {
                if (tps->realLength != 0) {
                    tps->realLength *= 2;
                } else {
                    tps->realLength = 50;
                }
                void * newPtr = memoryRealloc(tps->data, (tps->realLength)*sizeof(char *));
                tps->data = newPtr;
            }
            tps->data[len(tps)] = ft.cont;
            tps->length = nLength+1;
        } else {
            tps->data[len(tps)] = ft.cont;
        }
    }
    ;
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

    {
        unsigned long nLength = len(clibs);
        if (nLength >= clibs->length) {
            if (nLength >= clibs->realLength) {
                if (clibs->realLength != 0) {
                    clibs->realLength *= 2;
                } else {
                    clibs->realLength = 50;
                }
                void * newPtr = memoryRealloc(clibs->data, (clibs->realLength)*sizeof(char *));
                clibs->data = newPtr;
            }
            clibs->data[len(clibs)] = ccstr;
            clibs->length = nLength+1;
        } else {
            clibs->data[len(clibs)] = ccstr;
        }
    }
    ;
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
struct variable* ____BAH_COMPILER_VAR_664 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_664->name = "";
____BAH_COMPILER_VAR_664->type = "";
____BAH_COMPILER_VAR_664->isConst = false;
____BAH_COMPILER_VAR_664->constVal = "";
____BAH_COMPILER_VAR_664->isArray = false;
____BAH_COMPILER_VAR_664->from = "";
____BAH_COMPILER_VAR_664->declScope= null;
____BAH_COMPILER_VAR_664->isGlobal = false;
____BAH_COMPILER_VAR_664->declRope= null;
____BAH_COMPILER_VAR_664->canBeNull = false;
____BAH_COMPILER_VAR_664->isReg = false;
____BAH_COMPILER_VAR_664->lastSet= null;
____BAH_COMPILER_VAR_664->isArg = false;
struct variable* v = ____BAH_COMPILER_VAR_664;
if (isGlobal()) {
v->isGlobal = true;
}
v->isConst = true;
v->constVal = valt.cont;
v->name = vart.cont;
v->type = getTypeFromToken(&valt,true,elems);
array(struct variable*)* vars = elems->vars;

    {
        unsigned long nLength = len(vars);
        if (nLength >= vars->length) {
            if (nLength >= vars->realLength) {
                if (vars->realLength != 0) {
                    vars->realLength *= 2;
                } else {
                    vars->realLength = 50;
                }
                void * newPtr = memoryRealloc(vars->data, (vars->realLength)*sizeof(struct variable*));
                vars->data = newPtr;
            }
            vars->data[len(vars)] = v;
            vars->length = nLength+1;
        } else {
            vars->data[len(vars)] = v;
        }
    }
    ;
char * ____BAH_COMPILER_VAR_665 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(valt.cont);
unsigned int strLen_1 = strlen("\n");
unsigned int strLen_2 = strlen(" ");
unsigned int strLen_3 = strlen(v->name);
unsigned int strLen_4 = strlen("#define ");
;                            
            ____BAH_COMPILER_VAR_665 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_665+currStrOff, "#define ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_665+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_665+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_665+currStrOff, valt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_665+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_665));
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
char * ____BAH_COMPILER_VAR_666 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(currentFn->returns->type);
unsigned int strLen_1 = strlen(".");
unsigned int strLen_2 = strlen("Cannot return nothing as ");
;                            
            ____BAH_COMPILER_VAR_666 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_666+currStrOff, "Cannot return nothing as ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_666+currStrOff, currentFn->returns->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_666+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&l->data[0],____BAH_COMPILER_VAR_666);
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

                struct string ____BAH_COMPILER_VAR_667 = string(compilerState.currentDir);
                if ((isUnsafe==false)&&(string__hasPrefix(&____BAH_COMPILER_VAR_667,BAH_DIR)==false)&&(currentFn->returns->type[strlen(currentFn->returns->type)-1]!=33)) {
if ((tmpV->canBeNull==true)||(strcmp(rv, "null") == 0)) {
currentFn->returns->canBeNull = true;
char * ____BAH_COMPILER_VAR_668 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpV->name);
unsigned int strLen_1 = strlen("' that can be null as pointer.\n\tUse maybe values instead.");
unsigned int strLen_2 = strlen("Returning '");
;                            
            ____BAH_COMPILER_VAR_668 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_668+currStrOff, "Returning '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_668+currStrOff, tmpV->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_668+currStrOff, "' that can be null as pointer.\n\tUse maybe values instead.", strLen_1);
            currStrOff += strLen_1;
        
        }throwNoticeLine(____BAH_COMPILER_VAR_668,rvt.line);
}
}
}
}
else if (RCPavailable()&&(rvt.type==TOKEN_TYPE_FUNC)) {
rv = genCompilerVar();
struct string cType = getCType(tt,elems);
char * ____BAH_COMPILER_VAR_669 =null;char * ____BAH_COMPILER_VAR_670 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(rvt.cont);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen("=");
unsigned int strLen_3 = strlen(rv);
unsigned int strLen_4 = strlen(" ");
unsigned int strLen_5 = strlen(____BAH_COMPILER_VAR_670);
;                            
            ____BAH_COMPILER_VAR_669 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_669+currStrOff, ____BAH_COMPILER_VAR_670, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_669+currStrOff, " ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_669+currStrOff, rv, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_669+currStrOff, "=", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_669+currStrOff, rvt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_669+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_669));
}
if ((compTypes(tt,currentFn->returns->type)==false)) {
char * ____BAH_COMPILER_VAR_671 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(currentFn->returns->type);
unsigned int strLen_1 = strlen(".");
unsigned int strLen_2 = strlen(") as ");
unsigned int strLen_3 = strlen(tt);
unsigned int strLen_4 = strlen("Cannot return {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_671 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_671+currStrOff, "Cannot return {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_671+currStrOff, tt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_671+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_671+currStrOff, currentFn->returns->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_671+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&rvt,____BAH_COMPILER_VAR_671);
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
char * ____BAH_COMPILER_VAR_672 =null;char * ____BAH_COMPILER_VAR_673 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(rv);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen(" = ");
unsigned int strLen_3 = strlen(rvar);
unsigned int strLen_4 = strlen(" ");
unsigned int strLen_5 = strlen(____BAH_COMPILER_VAR_673);
;                            
            ____BAH_COMPILER_VAR_672 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_672+currStrOff, ____BAH_COMPILER_VAR_673, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_672+currStrOff, " ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_672+currStrOff, rvar, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_672+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_672+currStrOff, rv, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_672+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_672));
if ((tmpV!=null)&&(tmpV->declScope!=elems)) {
OUTPUT = rope__add(OUTPUT, incrVar(tmpV,elems));
}
}
if (strHasPrefix(tt,"buffer:")) {
char * ____BAH_COMPILER_VAR_674 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(rvar);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen("__STR(");
;                            
            ____BAH_COMPILER_VAR_674 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_674+currStrOff, "__STR(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_674+currStrOff, rvar, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_674+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }rvar = ____BAH_COMPILER_VAR_674;
}
if (RCPavailable()) {
array(struct variable*)* excl = memoryAlloc(sizeof(array(struct variable*)));

excl->length = 0;
excl->elemSize = sizeof(struct variable*);
register long int j = 0;
for (; (j<len(currentFn->args)); ++j) {

    {
        unsigned long nLength = j;
        if (nLength >= excl->length) {
            if (nLength >= excl->realLength) {
                if (excl->realLength != 0) {
                    excl->realLength *= 2;
                } else {
                    excl->realLength = 50;
                }
                void * newPtr = memoryRealloc(excl->data, (excl->realLength)*sizeof(struct variable*));
                excl->data = newPtr;
            }
            excl->data[j] = currentFn->args->data[j];
            excl->length = nLength+1;
        } else {
            excl->data[j] = currentFn->args->data[j];
        }
    }
    ;
};
if ((tmpV!=null)) {

    {
        unsigned long nLength = len(excl);
        if (nLength >= excl->length) {
            if (nLength >= excl->realLength) {
                if (excl->realLength != 0) {
                    excl->realLength *= 2;
                } else {
                    excl->realLength = 50;
                }
                void * newPtr = memoryRealloc(excl->data, (excl->realLength)*sizeof(struct variable*));
                excl->data = newPtr;
            }
            excl->data[len(excl)] = tmpV;
            excl->length = nLength+1;
        } else {
            excl->data[len(excl)] = tmpV;
        }
    }
    ;
}
endRCPscope(elems,excl);
}
char * ____BAH_COMPILER_VAR_675 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(rvar);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen("return ");
;                            
            ____BAH_COMPILER_VAR_675 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_675+currStrOff, "return ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_675+currStrOff, rvar, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_675+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_675));
}
else {
if (RCPavailable()) {
array(struct variable*)* excl = memoryAlloc(sizeof(array(struct variable*)));

excl->length = 0;
excl->elemSize = sizeof(struct variable*);
register long int j = 0;
for (; (j<len(currentFn->args)); ++j) {

    {
        unsigned long nLength = j;
        if (nLength >= excl->length) {
            if (nLength >= excl->realLength) {
                if (excl->realLength != 0) {
                    excl->realLength *= 2;
                } else {
                    excl->realLength = 50;
                }
                void * newPtr = memoryRealloc(excl->data, (excl->realLength)*sizeof(struct variable*));
                excl->data = newPtr;
            }
            excl->data[j] = currentFn->args->data[j];
            excl->length = nLength+1;
        } else {
            excl->data[j] = currentFn->args->data[j];
        }
    }
    ;
};
if ((tmpV!=null)) {

    {
        unsigned long nLength = len(excl);
        if (nLength >= excl->length) {
            if (nLength >= excl->realLength) {
                if (excl->realLength != 0) {
                    excl->realLength *= 2;
                } else {
                    excl->realLength = 50;
                }
                void * newPtr = memoryRealloc(excl->data, (excl->realLength)*sizeof(struct variable*));
                excl->data = newPtr;
            }
            excl->data[len(excl)] = tmpV;
            excl->length = nLength+1;
        } else {
            excl->data[len(excl)] = tmpV;
        }
    }
    ;
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

    {
        unsigned long nLength = len(tokens);
        if (nLength >= tokens->length) {
            if (nLength >= tokens->realLength) {
                if (tokens->realLength != 0) {
                    tokens->realLength *= 2;
                } else {
                    tokens->realLength = 50;
                }
                void * newPtr = memoryRealloc(tokens->data, (tokens->realLength)*sizeof(struct Tok));
                tokens->data = newPtr;
            }
            tokens->data[len(tokens)] = t;
            tokens->length = nLength+1;
        } else {
            tokens->data[len(tokens)] = t;
        }
    }
    ;
++i;
};
char * ____BAH_COMPILER_VAR_676 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(condt.cont);
unsigned int strLen_1 = strlen(") {\n");
unsigned int strLen_2 = strlen("if (");
;                            
            ____BAH_COMPILER_VAR_676 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_676+currStrOff, "if (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_676+currStrOff, condt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_676+currStrOff, ") {\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_676));
struct Elems* ifElems = dupElems(elems);
if ((fromElse==true)) {
i = 0;
for (; (i<len(prevIfChecks)); ++i) {
struct varCheck bc = prevIfChecks->data[i];
bc.checkNull = (bc.checkNull==false);

    {
        unsigned long nLength = i;
        if (nLength >= ifElems->branchChecks->length) {
            if (nLength >= ifElems->branchChecks->realLength) {
                if (ifElems->branchChecks->realLength != 0) {
                    ifElems->branchChecks->realLength *= 2;
                } else {
                    ifElems->branchChecks->realLength = 50;
                }
                void * newPtr = memoryRealloc(ifElems->branchChecks->data, (ifElems->branchChecks->realLength)*sizeof(struct varCheck));
                ifElems->branchChecks->data = newPtr;
            }
            ifElems->branchChecks->data[i] = bc;
            ifElems->branchChecks->length = nLength+1;
        } else {
            ifElems->branchChecks->data[i] = bc;
        }
    }
    ;
};
}
i = 0;
for (; (i<len(currChecks)); ++i) {

    {
        unsigned long nLength = len(ifElems->branchChecks);
        if (nLength >= ifElems->branchChecks->length) {
            if (nLength >= ifElems->branchChecks->realLength) {
                if (ifElems->branchChecks->realLength != 0) {
                    ifElems->branchChecks->realLength *= 2;
                } else {
                    ifElems->branchChecks->realLength = 50;
                }
                void * newPtr = memoryRealloc(ifElems->branchChecks->data, (ifElems->branchChecks->realLength)*sizeof(struct varCheck));
                ifElems->branchChecks->data = newPtr;
            }
            ifElems->branchChecks->data[len(ifElems->branchChecks)] = currChecks->data[i];
            ifElems->branchChecks->length = nLength+1;
        } else {
            ifElems->branchChecks->data[len(ifElems->branchChecks)] = currChecks->data[i];
        }
    }
    ;
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

    {
        unsigned long nLength = len(memory);
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(struct Tok));
                memory->data = newPtr;
            }
            memory->data[len(memory)] = l->data[i];
            memory->length = nLength+1;
        } else {
            memory->data[len(memory)] = l->data[i];
        }
    }
    ;
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

    {
        unsigned long nLength = len(memory);
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(struct Tok));
                memory->data = newPtr;
            }
            memory->data[len(memory)] = l->data[i];
            memory->length = nLength+1;
        } else {
            memory->data[len(memory)] = l->data[i];
        }
    }
    ;
++i;
};
OUTPUT = rope__add(OUTPUT, rope("{\n"));
struct Elems* ifElems = dupElems(elems);
i = 0;
for (; (i<len(prevIfChecks)); ++i) {
struct varCheck bc = prevIfChecks->data[i];
bc.checkNull = (bc.checkNull==false);

    {
        unsigned long nLength = i;
        if (nLength >= ifElems->branchChecks->length) {
            if (nLength >= ifElems->branchChecks->realLength) {
                if (ifElems->branchChecks->realLength != 0) {
                    ifElems->branchChecks->realLength *= 2;
                } else {
                    ifElems->branchChecks->realLength = 50;
                }
                void * newPtr = memoryRealloc(ifElems->branchChecks->data, (ifElems->branchChecks->realLength)*sizeof(struct varCheck));
                ifElems->branchChecks->data = newPtr;
            }
            ifElems->branchChecks->data[i] = bc;
            ifElems->branchChecks->length = nLength+1;
        } else {
            ifElems->branchChecks->data[i] = bc;
        }
    }
    ;
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

    {
        unsigned long nLength = len(inst);
        if (nLength >= inst->length) {
            if (nLength >= inst->realLength) {
                if (inst->realLength != 0) {
                    inst->realLength *= 2;
                } else {
                    inst->realLength = 50;
                }
                void * newPtr = memoryRealloc(inst->data, (inst->realLength)*sizeof(struct Tok));
                inst->data = newPtr;
            }
            inst->data[len(inst)] = t;
            inst->length = nLength+1;
        } else {
            inst->data[len(inst)] = t;
        }
    }
    ;
};
struct rope* oldOut = OUTPUT;
OUTPUT = rope("");
parseLine(inst,elems);
char * ____BAH_COMPILER_VAR_677 =rope__toStr(OUTPUT);struct string instC = string(____BAH_COMPILER_VAR_677);
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

    {
        unsigned long nLength = len(tokens);
        if (nLength >= tokens->length) {
            if (nLength >= tokens->realLength) {
                if (tokens->realLength != 0) {
                    tokens->realLength *= 2;
                } else {
                    tokens->realLength = 50;
                }
                void * newPtr = memoryRealloc(tokens->data, (tokens->realLength)*sizeof(struct Tok));
                tokens->data = newPtr;
            }
            tokens->data[len(tokens)] = t;
            tokens->length = nLength+1;
        } else {
            tokens->data[len(tokens)] = t;
        }
    }
    ;
};
char * ____BAH_COMPILER_VAR_678 =null;char * ____BAH_COMPILER_VAR_679 =string__str(&instC);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_679);
unsigned int strLen_1 = strlen(") {\n");
unsigned int strLen_2 = strlen("; ");
unsigned int strLen_3 = strlen(condt.cont);
unsigned int strLen_4 = strlen("for (; ");
;                            
            ____BAH_COMPILER_VAR_678 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_678+currStrOff, "for (; ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_678+currStrOff, condt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_678+currStrOff, "; ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_678+currStrOff, ____BAH_COMPILER_VAR_679, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_678+currStrOff, ") {\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_678));
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

    {
        unsigned long nLength = len(tokens);
        if (nLength >= tokens->length) {
            if (nLength >= tokens->realLength) {
                if (tokens->realLength != 0) {
                    tokens->realLength *= 2;
                } else {
                    tokens->realLength = 50;
                }
                void * newPtr = memoryRealloc(tokens->data, (tokens->realLength)*sizeof(struct Tok));
                tokens->data = newPtr;
            }
            tokens->data[len(tokens)] = t;
            tokens->length = nLength+1;
        } else {
            tokens->data[len(tokens)] = t;
        }
    }
    ;
};
char * ____BAH_COMPILER_VAR_680 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(condt.cont);
unsigned int strLen_1 = strlen(") {\n");
unsigned int strLen_2 = strlen("while (");
;                            
            ____BAH_COMPILER_VAR_680 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_680+currStrOff, "while (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_680+currStrOff, condt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_680+currStrOff, ") {\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_680));
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
char * ____BAH_COMPILER_VAR_681 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ft.cont);
unsigned int strLen_1 = strlen(";\n");
;                            
            ____BAH_COMPILER_VAR_681 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_681+currStrOff, ft.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_681+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_681));
};
void makeEvalFunc(struct func* fn,struct Elems* elems){

        char ____BAH_COMPILER_VAR_682 = 0;
        for(int i=compilerState.evals->length-1; i!=-1;i--) {
            if (compilerState.evals->data[i] != 0 && strcmp(compilerState.evals->data[i], fn->name) == 0) {
                ____BAH_COMPILER_VAR_682=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_682) {
return;
}
char * ____BAH_COMPILER_VAR_683 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("__Bah_eval_");
unsigned int strLen_1 = strlen(fn->name);
;                            
            ____BAH_COMPILER_VAR_683 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_683+currStrOff, "__Bah_eval_", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_683+currStrOff, fn->name, strLen_1);
            currStrOff += strLen_1;
        
        }struct func* ____BAH_COMPILER_VAR_684 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_684->name = "";
____BAH_COMPILER_VAR_684->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_684->args->length = 0;
            ____BAH_COMPILER_VAR_684->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_684->returns= null;
____BAH_COMPILER_VAR_684->isBinding = false;
____BAH_COMPILER_VAR_684->from = "";
____BAH_COMPILER_VAR_684->file = "";
____BAH_COMPILER_VAR_684->line = 1;
____BAH_COMPILER_VAR_684->isVar = false;
____BAH_COMPILER_VAR_684->used = false;
____BAH_COMPILER_VAR_684->code = null;
____BAH_COMPILER_VAR_684->isMut = false;
____BAH_COMPILER_VAR_684->isImported = false;
____BAH_COMPILER_VAR_684->exits = false;
____BAH_COMPILER_VAR_684->name = ____BAH_COMPILER_VAR_683;
struct func* efn = ____BAH_COMPILER_VAR_684;
struct variable* ____BAH_COMPILER_VAR_685 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_685->name = "";
____BAH_COMPILER_VAR_685->type = "";
____BAH_COMPILER_VAR_685->isConst = false;
____BAH_COMPILER_VAR_685->constVal = "";
____BAH_COMPILER_VAR_685->isArray = false;
____BAH_COMPILER_VAR_685->from = "";
____BAH_COMPILER_VAR_685->declScope= null;
____BAH_COMPILER_VAR_685->isGlobal = false;
____BAH_COMPILER_VAR_685->declRope= null;
____BAH_COMPILER_VAR_685->canBeNull = false;
____BAH_COMPILER_VAR_685->isReg = false;
____BAH_COMPILER_VAR_685->lastSet= null;
____BAH_COMPILER_VAR_685->isArg = false;
____BAH_COMPILER_VAR_685->type = "ptr";
efn->returns = ____BAH_COMPILER_VAR_685;
struct variable* ____BAH_COMPILER_VAR_686 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_686->name = "";
____BAH_COMPILER_VAR_686->type = "";
____BAH_COMPILER_VAR_686->isConst = false;
____BAH_COMPILER_VAR_686->constVal = "";
____BAH_COMPILER_VAR_686->isArray = false;
____BAH_COMPILER_VAR_686->from = "";
____BAH_COMPILER_VAR_686->declScope= null;
____BAH_COMPILER_VAR_686->isGlobal = false;
____BAH_COMPILER_VAR_686->declRope= null;
____BAH_COMPILER_VAR_686->canBeNull = false;
____BAH_COMPILER_VAR_686->isReg = false;
____BAH_COMPILER_VAR_686->lastSet= null;
____BAH_COMPILER_VAR_686->isArg = false;
____BAH_COMPILER_VAR_686->name = "fnArgs";
____BAH_COMPILER_VAR_686->type = "[]ptr";
efn->args = memoryAlloc(sizeof(array(struct variable*)));

efn->args->length = 1;
efn->args->elemSize = sizeof(struct variable*);
efn->args->data = memoryAlloc(sizeof(struct variable*) * 50);
                    efn->args->realLength = 50;
efn->args->data[0] = ____BAH_COMPILER_VAR_686;
char * fnBinding = "";
char * ____BAH_COMPILER_VAR_687 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fn->name);
unsigned int strLen_1 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_687 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_687+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_687+currStrOff, "(", strLen_1);
            currStrOff += strLen_1;
        
        }char * fnCall = ____BAH_COMPILER_VAR_687;
register long int i = 0;
for (; (i<len(fn->args)); ++i) {
struct variable* a = fn->args->data[i];
char * v = genCompilerVar();
struct string cType = getCType(a->type,elems);
if ((isRCPpointerType(a->type)==false)) {
string__append(&cType,"*");
}
char * ____BAH_COMPILER_VAR_688 =null;char * ____BAH_COMPILER_VAR_689 =intToStr(i);char * ____BAH_COMPILER_VAR_690 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_689);
unsigned int strLen_1 = strlen("];");
unsigned int strLen_2 = strlen(" = fnArgs->data[");
unsigned int strLen_3 = strlen(v);
unsigned int strLen_4 = strlen(" ");
unsigned int strLen_5 = strlen(____BAH_COMPILER_VAR_690);
;                            
            ____BAH_COMPILER_VAR_688 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_688+currStrOff, ____BAH_COMPILER_VAR_690, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_688+currStrOff, " ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_688+currStrOff, v, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_688+currStrOff, " = fnArgs->data[", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_688+currStrOff, ____BAH_COMPILER_VAR_689, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_688+currStrOff, "];", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_691 =null;char * ____BAH_COMPILER_VAR_692 =____BAH_COMPILER_VAR_688;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnBinding);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_692);
;                            
            ____BAH_COMPILER_VAR_691 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_691+currStrOff, fnBinding, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_691+currStrOff, ____BAH_COMPILER_VAR_692, strLen_1);
            currStrOff += strLen_1;
        
        }fnBinding = ____BAH_COMPILER_VAR_691;
if ((i!=0)) {
char * ____BAH_COMPILER_VAR_693 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnCall);
unsigned int strLen_1 = strlen(", ");
;                            
            ____BAH_COMPILER_VAR_693 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_693+currStrOff, fnCall, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_693+currStrOff, ", ", strLen_1);
            currStrOff += strLen_1;
        
        }fnCall = ____BAH_COMPILER_VAR_693;
}
if (isRCPpointerType(a->type)) {
char * ____BAH_COMPILER_VAR_694 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnCall);
unsigned int strLen_1 = strlen(v);
;                            
            ____BAH_COMPILER_VAR_694 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_694+currStrOff, fnCall, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_694+currStrOff, v, strLen_1);
            currStrOff += strLen_1;
        
        }fnCall = ____BAH_COMPILER_VAR_694;
}
else {
char * ____BAH_COMPILER_VAR_695 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("*");
unsigned int strLen_1 = strlen(v);
;                            
            ____BAH_COMPILER_VAR_695 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_695+currStrOff, "*", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_695+currStrOff, v, strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_696 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnCall);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_695);
;                            
            ____BAH_COMPILER_VAR_696 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_696+currStrOff, fnCall, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_696+currStrOff, ____BAH_COMPILER_VAR_695, strLen_1);
            currStrOff += strLen_1;
        
        }fnCall = ____BAH_COMPILER_VAR_696;
}
};
char * setReturnValue = "void* r = 0;";
if (isRCPpointerType(fn->returns->type)) {
setReturnValue = "void* r = ";
}
else {
struct string cType = getCType(fn->returns->type,elems);
if ((strcmp(string__str(&cType), "void") != 0)) {
char * ____BAH_COMPILER_VAR_697 =null;char * ____BAH_COMPILER_VAR_698 =string__str(&cType);char * ____BAH_COMPILER_VAR_699 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_698);
unsigned int strLen_1 = strlen("));*r = ");
unsigned int strLen_2 = strlen("* r = memoryAlloc(sizeof(");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_699);
;                            
            ____BAH_COMPILER_VAR_697 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_697+currStrOff, ____BAH_COMPILER_VAR_699, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_697+currStrOff, "* r = memoryAlloc(sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_697+currStrOff, ____BAH_COMPILER_VAR_698, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_697+currStrOff, "));*r = ", strLen_1);
            currStrOff += strLen_1;
        
        }setReturnValue = ____BAH_COMPILER_VAR_697;
}
}
char * ____BAH_COMPILER_VAR_700 =null;char * ____BAH_COMPILER_VAR_701 =intToStr(len(fn->args));
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnCall);
unsigned int strLen_1 = strlen(");\n        return (void*)r;\n    };");
unsigned int strLen_2 = strlen(setReturnValue);
unsigned int strLen_3 = strlen("\n        ");
unsigned int strLen_4 = strlen(fnBinding);
unsigned int strLen_5 = strlen("() with the wrong number of arguments.\", \"BAH_COMPILER_INTERNAL\");\n        }\n        ");
unsigned int strLen_6 = strlen(fn->name);
unsigned int strLen_7 = strlen(") {\n            __BAH_panic((char*)\"eval: calling function ");
unsigned int strLen_8 = strlen(____BAH_COMPILER_VAR_701);
unsigned int strLen_9 = strlen("(array(void*)* fnArgs) {\n        if (fnArgs->length != ");
unsigned int strLen_10 = strlen(efn->name);
unsigned int strLen_11 = strlen("void* __attribute__((optimize(\"O0\"))) ");
;                            
            ____BAH_COMPILER_VAR_700 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11);
            
                    memcpy(____BAH_COMPILER_VAR_700+currStrOff, "void* __attribute__((optimize(\"O0\"))) ", strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_700+currStrOff, efn->name, strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_700+currStrOff, "(array(void*)* fnArgs) {\n        if (fnArgs->length != ", strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_700+currStrOff, ____BAH_COMPILER_VAR_701, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_700+currStrOff, ") {\n            __BAH_panic((char*)\"eval: calling function ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_700+currStrOff, fn->name, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_700+currStrOff, "() with the wrong number of arguments.\", \"BAH_COMPILER_INTERNAL\");\n        }\n        ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_700+currStrOff, fnBinding, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_700+currStrOff, "\n        ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_700+currStrOff, setReturnValue, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_700+currStrOff, fnCall, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_700+currStrOff, ");\n        return (void*)r;\n    };", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_700));

    {
        unsigned long nLength = len(compilerState.evals);
        if (nLength >= compilerState.evals->length) {
            if (nLength >= compilerState.evals->realLength) {
                if (compilerState.evals->realLength != 0) {
                    compilerState.evals->realLength *= 2;
                } else {
                    compilerState.evals->realLength = 50;
                }
                void * newPtr = memoryRealloc(compilerState.evals->data, (compilerState.evals->realLength)*sizeof(char *));
                compilerState.evals->data = newPtr;
            }
            compilerState.evals->data[len(compilerState.evals)] = fn->name;
            compilerState.evals->length = nLength+1;
        } else {
            compilerState.evals->data[len(compilerState.evals)] = fn->name;
        }
    }
    ;

    {
        unsigned long nLength = len(elems->fns);
        if (nLength >= elems->fns->length) {
            if (nLength >= elems->fns->realLength) {
                if (elems->fns->realLength != 0) {
                    elems->fns->realLength *= 2;
                } else {
                    elems->fns->realLength = 50;
                }
                void * newPtr = memoryRealloc(elems->fns->data, (elems->fns->realLength)*sizeof(struct func*));
                elems->fns->data = newPtr;
            }
            elems->fns->data[len(elems->fns)] = efn;
            elems->fns->length = nLength+1;
        } else {
            elems->fns->data[len(elems->fns)] = efn;
        }
    }
    ;
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
char * ____BAH_COMPILER_VAR_702 =string__str(&msg);throwWarning(____BAH_COMPILER_VAR_702);
return;
}
if ((strcmp(ft.cont, "#eval") == 0)) {

        char ____BAH_COMPILER_VAR_703 = 0;
        for(int i=compilerState.includes->length-1; i!=-1;i--) {
            if (compilerState.includes->data[i] != 0 && strcmp(compilerState.includes->data[i], "eval.bah") == 0) {
                ____BAH_COMPILER_VAR_703=1;
                break;
            };
        }
        if ((____BAH_COMPILER_VAR_703==false)) {
if ((includeFile("eval.bah",elems)==false)) {
char * ____BAH_COMPILER_VAR_704 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(BAH_DIR);
unsigned int strLen_1 = strlen(").");
unsigned int strLen_2 = strlen("Could not find file 'eval.bah'. Check your bah directory (");
;                            
            ____BAH_COMPILER_VAR_704 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_704+currStrOff, "Could not find file 'eval.bah'. Check your bah directory (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_704+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_704+currStrOff, ").", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&l->data[0],____BAH_COMPILER_VAR_704);
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

    {
        unsigned long nLength = i-2;
        if (nLength >= nl->length) {
            if (nLength >= nl->realLength) {
                if (nl->realLength != 0) {
                    nl->realLength *= 2;
                } else {
                    nl->realLength = 50;
                }
                void * newPtr = memoryRealloc(nl->data, (nl->realLength)*sizeof(struct Tok));
                nl->data = newPtr;
            }
            nl->data[i-2] = l->data[i];
            nl->length = nLength+1;
        } else {
            nl->data[i-2] = l->data[i];
        }
    }
    ;
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
        unsigned long nLength = len(compilerState.cLibs);
        if (nLength >= compilerState.cLibs->length) {
            if (nLength >= compilerState.cLibs->realLength) {
                if (compilerState.cLibs->realLength != 0) {
                    compilerState.cLibs->realLength *= 2;
                } else {
                    compilerState.cLibs->realLength = 50;
                }
                void * newPtr = memoryRealloc(compilerState.cLibs->data, (compilerState.cLibs->realLength)*sizeof(char *));
                compilerState.cLibs->data = newPtr;
            }
            compilerState.cLibs->data[len(compilerState.cLibs)] = "lpthread";
            compilerState.cLibs->length = nLength+1;
        } else {
            compilerState.cLibs->data[len(compilerState.cLibs)] = "lpthread";
        }
    }
    ;
}
struct string sFnT = string(fnT.cont);
array(struct string)* fnNameParts = splitString(sFnT,"(");
struct string fnName = fnNameParts->data[0];
struct func* fn = searchFuncByToken(&fnT,elems);
if ((fn==null)) {
char * ____BAH_COMPILER_VAR_705 =null;char * ____BAH_COMPILER_VAR_706 =string__str(&fnName);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_706);
unsigned int strLen_1 = strlen("', arround {TOKEN}.");
unsigned int strLen_2 = strlen("Internal compiler error.\n Error parsing async call for function '");
;                            
            ____BAH_COMPILER_VAR_705 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_705+currStrOff, "Internal compiler error.\n Error parsing async call for function '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_705+currStrOff, ____BAH_COMPILER_VAR_706, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_705+currStrOff, "', arround {TOKEN}.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&fnT,____BAH_COMPILER_VAR_705);
}
fnName = string(fn->name);
char * sMembs = "";
char * unSerMembs = "";
i = 0;
while ((i<len(fn->args))) {
struct variable* a = fn->args->data[i];
struct string cType = getCType(a->type,elems);
char * ____BAH_COMPILER_VAR_707 =null;char * ____BAH_COMPILER_VAR_708 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(a->name);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen(" ");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_708);
unsigned int strLen_4 = strlen(sMembs);
;                            
            ____BAH_COMPILER_VAR_707 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_707+currStrOff, sMembs, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_707+currStrOff, ____BAH_COMPILER_VAR_708, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_707+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_707+currStrOff, a->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_707+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }sMembs = ____BAH_COMPILER_VAR_707;
char * ____BAH_COMPILER_VAR_709 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("args->");
unsigned int strLen_1 = strlen(a->name);
unsigned int strLen_2 = strlen(unSerMembs);
;                            
            ____BAH_COMPILER_VAR_709 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_709+currStrOff, unSerMembs, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_709+currStrOff, "args->", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_709+currStrOff, a->name, strLen_1);
            currStrOff += strLen_1;
        
        }unSerMembs = ____BAH_COMPILER_VAR_709;
i = i+1;
if ((i<len(fn->args))) {
char * ____BAH_COMPILER_VAR_710 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(unSerMembs);
unsigned int strLen_1 = strlen(", ");
;                            
            ____BAH_COMPILER_VAR_710 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_710+currStrOff, unSerMembs, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_710+currStrOff, ", ", strLen_1);
            currStrOff += strLen_1;
        
        }unSerMembs = ____BAH_COMPILER_VAR_710;
}
};
char * ____BAH_COMPILER_VAR_711 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(sMembs);
unsigned int strLen_1 = strlen("}");
unsigned int strLen_2 = strlen("struct {\n");
;                            
            ____BAH_COMPILER_VAR_711 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_711+currStrOff, "struct {\n", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_711+currStrOff, sMembs, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_711+currStrOff, "}", strLen_1);
            currStrOff += strLen_1;
        
        }char * tmpArgsStruct = ____BAH_COMPILER_VAR_711;
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
char * ____BAH_COMPILER_VAR_712 =null;char * ____BAH_COMPILER_VAR_713 =string__str(&sFnT);char * ____BAH_COMPILER_VAR_714 =string__str(&fnName);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpArgs);
unsigned int strLen_1 = strlen(");\n    }; \n    \n    ");
unsigned int strLen_2 = strlen(", &");
unsigned int strLen_3 = strlen(fnWrapper);
unsigned int strLen_4 = strlen("(&id, 0, ");
unsigned int strLen_5 = strlen(tCreate);
unsigned int strLen_6 = strlen("};\n        pthread_t id;\n        ");
unsigned int strLen_7 = strlen(____BAH_COMPILER_VAR_713);
unsigned int strLen_8 = strlen(" = {");
unsigned int strLen_9 = strlen(tmpArgs);
unsigned int strLen_10 = strlen(" ");
unsigned int strLen_11 = strlen(tmpArgsStruct);
unsigned int strLen_12 = strlen(");\n    };\n    {\n        ");
unsigned int strLen_13 = strlen(unSerMembs);
unsigned int strLen_14 = strlen("(");
unsigned int strLen_15 = strlen(____BAH_COMPILER_VAR_714);
unsigned int strLen_16 = strlen("* args) {\n        ");
unsigned int strLen_17 = strlen(tmpArgsStruct);
unsigned int strLen_18 = strlen("(");
unsigned int strLen_19 = strlen(fnWrapper);
unsigned int strLen_20 = strlen("\n    void ");
;                            
            ____BAH_COMPILER_VAR_712 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13+strLen_14+strLen_15+strLen_16+strLen_17+strLen_18+strLen_19+strLen_20);
            
                    memcpy(____BAH_COMPILER_VAR_712+currStrOff, "\n    void ", strLen_20);
                    currStrOff += strLen_20;
                    
                    memcpy(____BAH_COMPILER_VAR_712+currStrOff, fnWrapper, strLen_19);
                    currStrOff += strLen_19;
                    
                    memcpy(____BAH_COMPILER_VAR_712+currStrOff, "(", strLen_18);
                    currStrOff += strLen_18;
                    
                    memcpy(____BAH_COMPILER_VAR_712+currStrOff, tmpArgsStruct, strLen_17);
                    currStrOff += strLen_17;
                    
                    memcpy(____BAH_COMPILER_VAR_712+currStrOff, "* args) {\n        ", strLen_16);
                    currStrOff += strLen_16;
                    
                    memcpy(____BAH_COMPILER_VAR_712+currStrOff, ____BAH_COMPILER_VAR_714, strLen_15);
                    currStrOff += strLen_15;
                    
                    memcpy(____BAH_COMPILER_VAR_712+currStrOff, "(", strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_712+currStrOff, unSerMembs, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_712+currStrOff, ");\n    };\n    {\n        ", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_712+currStrOff, tmpArgsStruct, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_712+currStrOff, " ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_712+currStrOff, tmpArgs, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_712+currStrOff, " = {", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_712+currStrOff, ____BAH_COMPILER_VAR_713, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_712+currStrOff, "};\n        pthread_t id;\n        ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_712+currStrOff, tCreate, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_712+currStrOff, "(&id, 0, ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_712+currStrOff, fnWrapper, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_712+currStrOff, ", &", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_712+currStrOff, tmpArgs, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_712+currStrOff, ");\n    }; \n    \n    ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_712));
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

    {
        unsigned long nLength = len(compilerState.RCPvars);
        if (nLength >= compilerState.RCPvars->length) {
            if (nLength >= compilerState.RCPvars->realLength) {
                if (compilerState.RCPvars->realLength != 0) {
                    compilerState.RCPvars->realLength *= 2;
                } else {
                    compilerState.RCPvars->realLength = 50;
                }
                void * newPtr = memoryRealloc(compilerState.RCPvars->data, (compilerState.RCPvars->realLength)*sizeof(struct variable*));
                compilerState.RCPvars->data = newPtr;
            }
            compilerState.RCPvars->data[len(compilerState.RCPvars)] = v;
            compilerState.RCPvars->length = nLength+1;
        } else {
            compilerState.RCPvars->data[len(compilerState.RCPvars)] = v;
        }
    }
    ;
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
char * ____BAH_COMPILER_VAR_715 =getTypeFromToken(&nt,true,elems);struct string ntt = string(____BAH_COMPILER_VAR_715);
if ((string__hasPrefix(&ntt,"chan:")==0)) {
char * ____BAH_COMPILER_VAR_716 =null;char * ____BAH_COMPILER_VAR_717 =string__str(&ntt);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_717);
unsigned int strLen_1 = strlen(") as channel.");
unsigned int strLen_2 = strlen("Cannot use var {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_716 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_716+currStrOff, "Cannot use var {TOKEN} (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_716+currStrOff, ____BAH_COMPILER_VAR_717, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_716+currStrOff, ") as channel.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&nt,____BAH_COMPILER_VAR_716);
}
string__trimLeft(&ntt,5);
if (isGlobal()) {
throwErr(&t,"Cannot receive ({TOKEN}) from a channel outside of a function.");
}
char * tmpV = "";
char * ____BAH_COMPILER_VAR_718 =string__str(&ntt);if (isRCPpointerType(____BAH_COMPILER_VAR_718)) {
char * ____BAH_COMPILER_VAR_719 =string__str(&ntt);struct string ct = getCType(____BAH_COMPILER_VAR_719,elems);
char * ____BAH_COMPILER_VAR_720 =null;char * ____BAH_COMPILER_VAR_721 =string__str(&ct);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen("->receive(");
unsigned int strLen_3 = strlen(nt.cont);
unsigned int strLen_4 = strlen(")");
unsigned int strLen_5 = strlen(____BAH_COMPILER_VAR_721);
unsigned int strLen_6 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_720 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_720+currStrOff, "(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_720+currStrOff, ____BAH_COMPILER_VAR_721, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_720+currStrOff, ")", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_720+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_720+currStrOff, "->receive(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_720+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_720+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_720;
}
else {
char * ____BAH_COMPILER_VAR_722 =string__str(&ntt);struct string ct = getCType(____BAH_COMPILER_VAR_722,elems);
if (RCPavailable()) {
char * ____BAH_COMPILER_VAR_723 =null;char * ____BAH_COMPILER_VAR_724 =string__str(&ntt);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_724);
unsigned int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_723 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_723+currStrOff, ____BAH_COMPILER_VAR_724, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_723+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_725 =null;char * ____BAH_COMPILER_VAR_726 =string__str(&ct);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen("->receive(");
unsigned int strLen_3 = strlen(nt.cont);
unsigned int strLen_4 = strlen("*)");
unsigned int strLen_5 = strlen(____BAH_COMPILER_VAR_726);
unsigned int strLen_6 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_725 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_725+currStrOff, "(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_725+currStrOff, ____BAH_COMPILER_VAR_726, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_725+currStrOff, "*)", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_725+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_725+currStrOff, "->receive(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_725+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_725+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }tmpV = registerRCPvar(____BAH_COMPILER_VAR_723,____BAH_COMPILER_VAR_725,elems);
char * ____BAH_COMPILER_VAR_727 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("*");
unsigned int strLen_1 = strlen(tmpV);
;                            
            ____BAH_COMPILER_VAR_727 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_727+currStrOff, "*", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_727+currStrOff, tmpV, strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_727;
}
else {
char * ____BAH_COMPILER_VAR_728 =null;char * ____BAH_COMPILER_VAR_729 =string__str(&ct);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen("->receive(");
unsigned int strLen_3 = strlen(nt.cont);
unsigned int strLen_4 = strlen("*)");
unsigned int strLen_5 = strlen(____BAH_COMPILER_VAR_729);
unsigned int strLen_6 = strlen("*(");
;                            
            ____BAH_COMPILER_VAR_728 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_728+currStrOff, "*(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_728+currStrOff, ____BAH_COMPILER_VAR_729, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_728+currStrOff, "*)", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_728+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_728+currStrOff, "->receive(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_728+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_728+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_728;
}
}
t.type = TOKEN_TYPE_FUNC;
t.isFunc = true;
if (RCPavailable()) {
char * ____BAH_COMPILER_VAR_730 =string__str(&ntt);if (isRCPpointerType(____BAH_COMPILER_VAR_730)) {
char * ____BAH_COMPILER_VAR_731 =string__str(&ntt);tmpV = registerRCPvar(____BAH_COMPILER_VAR_731,t.cont,elems);
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
char * ____BAH_COMPILER_VAR_732 =getTypeFromToken(&pt,true,elems);struct string ptt = string(____BAH_COMPILER_VAR_732);
if ((string__hasPrefix(&ptt,"chan:")==0)) {
char * ____BAH_COMPILER_VAR_733 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ntt);
unsigned int strLen_1 = strlen(") as channel.");
unsigned int strLen_2 = strlen("Cannot use var {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_733 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_733+currStrOff, "Cannot use var {TOKEN} (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_733+currStrOff, ntt, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_733+currStrOff, ") as channel.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&pt,____BAH_COMPILER_VAR_733);
}
string__trimLeft(&ptt,5);
if (isGlobal()) {
throwErr(&t,"Cannot send ({TOKEN}) to a channel outside of a function.");
}
char * ____BAH_COMPILER_VAR_734 =string__str(&ptt);if ((compTypes(____BAH_COMPILER_VAR_734,ntt)==false)) {
char * ____BAH_COMPILER_VAR_735 =null;char * ____BAH_COMPILER_VAR_736 =string__str(&ptt);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_736);
unsigned int strLen_1 = strlen(".");
unsigned int strLen_2 = strlen(") to channel of type ");
unsigned int strLen_3 = strlen(ntt);
unsigned int strLen_4 = strlen("Cannot send {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_735 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_735+currStrOff, "Cannot send {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_735+currStrOff, ntt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_735+currStrOff, ") to channel of type ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_735+currStrOff, ____BAH_COMPILER_VAR_736, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_735+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&nt,____BAH_COMPILER_VAR_735);
}
++i;
char * ____BAH_COMPILER_VAR_737 =string__str(&ptt);if (isRCPpointerType(____BAH_COMPILER_VAR_737)) {
char * ____BAH_COMPILER_VAR_738 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen(");\n");
unsigned int strLen_2 = strlen(", ");
unsigned int strLen_3 = strlen(pt.cont);
unsigned int strLen_4 = strlen("->send(");
unsigned int strLen_5 = strlen(pt.cont);
;                            
            ____BAH_COMPILER_VAR_738 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_738+currStrOff, pt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_738+currStrOff, "->send(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_738+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_738+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_738+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_738+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_738));
}
else {
struct string ct = getCType(ntt,elems);
char * tmpV = genCompilerVar();
char * ____BAH_COMPILER_VAR_739 =null;char * ____BAH_COMPILER_VAR_740 =string__str(&ct);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpV);
unsigned int strLen_1 = strlen("));\n");
unsigned int strLen_2 = strlen(", sizeof(");
unsigned int strLen_3 = strlen(tmpV);
unsigned int strLen_4 = strlen(", &");
unsigned int strLen_5 = strlen(pt.cont);
unsigned int strLen_6 = strlen("->sendAny(");
unsigned int strLen_7 = strlen(pt.cont);
unsigned int strLen_8 = strlen(";\n                    ");
unsigned int strLen_9 = strlen(nt.cont);
unsigned int strLen_10 = strlen(" = ");
unsigned int strLen_11 = strlen(tmpV);
unsigned int strLen_12 = strlen(" ");
unsigned int strLen_13 = strlen(____BAH_COMPILER_VAR_740);
unsigned int strLen_14 = strlen("\n                    ");
;                            
            ____BAH_COMPILER_VAR_739 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13+strLen_14);
            
                    memcpy(____BAH_COMPILER_VAR_739+currStrOff, "\n                    ", strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_739+currStrOff, ____BAH_COMPILER_VAR_740, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_739+currStrOff, " ", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_739+currStrOff, tmpV, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_739+currStrOff, " = ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_739+currStrOff, nt.cont, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_739+currStrOff, ";\n                    ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_739+currStrOff, pt.cont, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_739+currStrOff, "->sendAny(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_739+currStrOff, pt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_739+currStrOff, ", &", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_739+currStrOff, tmpV, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_739+currStrOff, ", sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_739+currStrOff, tmpV, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_739+currStrOff, "));\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_739));
}
nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
return nl;
}
}

    {
        unsigned long nLength = len(nl);
        if (nLength >= nl->length) {
            if (nLength >= nl->realLength) {
                if (nl->realLength != 0) {
                    nl->realLength *= 2;
                } else {
                    nl->realLength = 50;
                }
                void * newPtr = memoryRealloc(nl->data, (nl->realLength)*sizeof(struct Tok));
                nl->data = newPtr;
            }
            nl->data[len(nl)] = t;
            nl->length = nLength+1;
        } else {
            nl->data[len(nl)] = t;
        }
    }
    ;
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
char * ____BAH_COMPILER_VAR_741 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnt.ogCont);
unsigned int strLen_1 = strlen(t.ogCont);
;                            
            ____BAH_COMPILER_VAR_741 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_741+currStrOff, fnt.ogCont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_741+currStrOff, t.ogCont, strLen_1);
            currStrOff += strLen_1;
        
        }fnt.ogCont = ____BAH_COMPILER_VAR_741;
if ((strcmp(t.cont, "(") == 0)||(strcmp(t.cont, "{") == 0)||(strcmp(t.cont, "[") == 0)) {
++nbEncls;
}
else if ((strcmp(t.cont, ")") == 0)||(strcmp(t.cont, "}") == 0)||(strcmp(t.cont, "]") == 0)) {
--nbEncls;
if ((nbEncls==0)) {
break;
}
}

    {
        unsigned long nLength = len(memory);
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(struct Tok));
                memory->data = newPtr;
            }
            memory->data[len(memory)] = t;
            memory->length = nLength+1;
        } else {
            memory->data[len(memory)] = t;
        }
    }
    ;
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
char * ____BAH_COMPILER_VAR_742 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnt.cont);
unsigned int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_742 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_742+currStrOff, fnt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_742+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_742;
};
char * ____BAH_COMPILER_VAR_743 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnt.cont);
unsigned int strLen_1 = strlen(")");
;                            
            ____BAH_COMPILER_VAR_743 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_743+currStrOff, fnt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_743+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_743;

    {
        unsigned long nLength = tokPos;
        if (nLength >= l->length) {
            if (nLength >= l->realLength) {
                if (l->realLength != 0) {
                    l->realLength *= 2;
                } else {
                    l->realLength = 50;
                }
                void * newPtr = memoryRealloc(l->data, (l->realLength)*sizeof(struct Tok));
                l->data = newPtr;
            }
            l->data[tokPos] = fnt;
            l->length = nLength+1;
        } else {
            l->data[tokPos] = fnt;
        }
    }
    ;
return tokPos;
}
if ((strcmp(fn->name, "exit") == 0)||(fn->exits==true)) {
setNullStateBranchFlowEnd(elems);
}
char * ____BAH_COMPILER_VAR_744 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fn->name);
unsigned int strLen_1 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_744 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_744+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_744+currStrOff, "(", strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_744;
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
char * ____BAH_COMPILER_VAR_745 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fn->name);
unsigned int strLen_1 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_745 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_745+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_745+currStrOff, "(", strLen_1);
            currStrOff += strLen_1;
        
        }fnt.ogCont = ____BAH_COMPILER_VAR_745;
for (; (i<len(l)); ++i) {
struct Tok t = l->data[i];
char * ____BAH_COMPILER_VAR_746 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnt.ogCont);
unsigned int strLen_1 = strlen(t.ogCont);
;                            
            ____BAH_COMPILER_VAR_746 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_746+currStrOff, fnt.ogCont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_746+currStrOff, t.ogCont, strLen_1);
            currStrOff += strLen_1;
        
        }fnt.ogCont = ____BAH_COMPILER_VAR_746;
if ((strcmp(t.cont, "(") == 0)||(strcmp(t.cont, "{") == 0)||(strcmp(t.cont, "[") == 0)) {
++nbEncls;
}
else if ((strcmp(t.cont, ")") == 0)||(strcmp(t.cont, "}") == 0)||(strcmp(t.cont, "]") == 0)) {
--nbEncls;
if ((nbEncls==0)) {
break;
}
}

    {
        unsigned long nLength = len(memory);
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(struct Tok));
                memory->data = newPtr;
            }
            memory->data[len(memory)] = t;
            memory->length = nLength+1;
        } else {
            memory->data[len(memory)] = t;
        }
    }
    ;
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
char * ____BAH_COMPILER_VAR_747 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnt.cont);
unsigned int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_747 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_747+currStrOff, fnt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_747+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_747;
};

    {
        unsigned long nLength = tokPos;
        if (nLength >= l->length) {
            if (nLength >= l->realLength) {
                if (l->realLength != 0) {
                    l->realLength *= 2;
                } else {
                    l->realLength = 50;
                }
                void * newPtr = memoryRealloc(l->data, (l->realLength)*sizeof(struct Tok));
                l->data = newPtr;
            }
            l->data[tokPos] = fnt;
            l->length = nLength+1;
        } else {
            l->data[tokPos] = fnt;
        }
    }
    ;
return tokPos;
}
char * ____BAH_COMPILER_VAR_748 =null;char * ____BAH_COMPILER_VAR_749 =intToStr(fnt.line);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_749);
unsigned int strLen_1 = strlen("\"");
unsigned int strLen_2 = strlen(":");
unsigned int strLen_3 = strlen(compilerState.currentFile);
unsigned int strLen_4 = strlen("\"");
;                            
            ____BAH_COMPILER_VAR_748 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_748+currStrOff, "\"", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_748+currStrOff, compilerState.currentFile, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_748+currStrOff, ":", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_748+currStrOff, ____BAH_COMPILER_VAR_749, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_748+currStrOff, "\"", strLen_1);
            currStrOff += strLen_1;
        
        }char * currLine = ____BAH_COMPILER_VAR_748;
if ((strcmp(fn->name, "panic") == 0)) {
struct Tok ____BAH_COMPILER_VAR_750 = {};
____BAH_COMPILER_VAR_750.cont = "";
____BAH_COMPILER_VAR_750.ogCont = "";
____BAH_COMPILER_VAR_750.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_750.pos = 0;
____BAH_COMPILER_VAR_750.line = 1;
____BAH_COMPILER_VAR_750.begLine = 1;
____BAH_COMPILER_VAR_750.bahType = "";
____BAH_COMPILER_VAR_750.isValue = false;
____BAH_COMPILER_VAR_750.isFunc = false;
____BAH_COMPILER_VAR_750.isOper = false;
____BAH_COMPILER_VAR_750.isEqual = false;
____BAH_COMPILER_VAR_750.pass = false;
____BAH_COMPILER_VAR_750.bahRef= null;
____BAH_COMPILER_VAR_750.parent= null;
____BAH_COMPILER_VAR_750.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_750.cont = ",";
____BAH_COMPILER_VAR_750.line = fnt.line;

    {
        unsigned long nLength = len(memory);
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(struct Tok));
                memory->data = newPtr;
            }
            memory->data[len(memory)] = ____BAH_COMPILER_VAR_750;
            memory->length = nLength+1;
        } else {
            memory->data[len(memory)] = ____BAH_COMPILER_VAR_750;
        }
    }
    ;
struct Tok ____BAH_COMPILER_VAR_751 = {};
____BAH_COMPILER_VAR_751.cont = "";
____BAH_COMPILER_VAR_751.ogCont = "";
____BAH_COMPILER_VAR_751.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_751.pos = 0;
____BAH_COMPILER_VAR_751.line = 1;
____BAH_COMPILER_VAR_751.begLine = 1;
____BAH_COMPILER_VAR_751.bahType = "";
____BAH_COMPILER_VAR_751.isValue = false;
____BAH_COMPILER_VAR_751.isFunc = false;
____BAH_COMPILER_VAR_751.isOper = false;
____BAH_COMPILER_VAR_751.isEqual = false;
____BAH_COMPILER_VAR_751.pass = false;
____BAH_COMPILER_VAR_751.bahRef= null;
____BAH_COMPILER_VAR_751.parent= null;
____BAH_COMPILER_VAR_751.type = TOKEN_TYPE_STR;
____BAH_COMPILER_VAR_751.cont = currLine;
____BAH_COMPILER_VAR_751.line = fnt.line;

    {
        unsigned long nLength = len(memory);
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(struct Tok));
                memory->data = newPtr;
            }
            memory->data[len(memory)] = ____BAH_COMPILER_VAR_751;
            memory->length = nLength+1;
        } else {
            memory->data[len(memory)] = ____BAH_COMPILER_VAR_751;
        }
    }
    ;
fn = searchFunc("__BAH_panic",elems,true);
char * ____BAH_COMPILER_VAR_752 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fn->name);
unsigned int strLen_1 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_752 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_752+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_752+currStrOff, "(", strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_752;
}
else if ((strcmp(fn->name, "__dumpSymbols") == 0)) {
array(struct variable*)* symbols = memoryAlloc(sizeof(array(struct variable*)));

symbols->length = 0;
symbols->elemSize = sizeof(struct variable*);
register long int j = 0;
for (; (j<len(elems->vars)); ++j) {
struct variable* v = elems->vars->data[j];
if ((v->isConst==false)) {

    {
        unsigned long nLength = len(symbols);
        if (nLength >= symbols->length) {
            if (nLength >= symbols->realLength) {
                if (symbols->realLength != 0) {
                    symbols->realLength *= 2;
                } else {
                    symbols->realLength = 50;
                }
                void * newPtr = memoryRealloc(symbols->data, (symbols->realLength)*sizeof(struct variable*));
                symbols->data = newPtr;
            }
            symbols->data[len(symbols)] = v;
            symbols->length = nLength+1;
        } else {
            symbols->data[len(symbols)] = v;
        }
    }
    ;
}
};
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
____BAH_COMPILER_VAR_753->canBeNull = false;
____BAH_COMPILER_VAR_753->isReg = false;
____BAH_COMPILER_VAR_753->lastSet= null;
____BAH_COMPILER_VAR_753->isArg = false;
____BAH_COMPILER_VAR_753->name = genCompilerVar();
____BAH_COMPILER_VAR_753->type = "[]reflectElement";
____BAH_COMPILER_VAR_753->isArray = true;
struct variable* tmpV = ____BAH_COMPILER_VAR_753;
char * decls = "";
j = 0;
for (; (j<len(symbols)); ++j) {
struct variable* v = symbols->data[j];
char * vname = v->name;
if ((strCount(v->type,"*")==0)) {
char * ____BAH_COMPILER_VAR_754 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("&");
unsigned int strLen_1 = strlen(v->name);
;                            
            ____BAH_COMPILER_VAR_754 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_754+currStrOff, "&", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_754+currStrOff, v->name, strLen_1);
            currStrOff += strLen_1;
        
        }vname = ____BAH_COMPILER_VAR_754;
}
struct Tok ____BAH_COMPILER_VAR_755 = {};
____BAH_COMPILER_VAR_755.cont = "";
____BAH_COMPILER_VAR_755.ogCont = "";
____BAH_COMPILER_VAR_755.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_755.pos = 0;
____BAH_COMPILER_VAR_755.line = 1;
____BAH_COMPILER_VAR_755.begLine = 1;
____BAH_COMPILER_VAR_755.bahType = "";
____BAH_COMPILER_VAR_755.isValue = false;
____BAH_COMPILER_VAR_755.isFunc = false;
____BAH_COMPILER_VAR_755.isOper = false;
____BAH_COMPILER_VAR_755.isEqual = false;
____BAH_COMPILER_VAR_755.pass = false;
____BAH_COMPILER_VAR_755.bahRef= null;
____BAH_COMPILER_VAR_755.parent= null;
____BAH_COMPILER_VAR_755.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_755.cont = vname;
____BAH_COMPILER_VAR_755.bahType = v->type;
____BAH_COMPILER_VAR_755.isValue = true;
#define tmpT ____BAH_COMPILER_VAR_755
tmpT = parseReflect(tmpT,v->type,elems,true,v->name,"0");
char * ____BAH_COMPILER_VAR_756 =null;char * ____BAH_COMPILER_VAR_757 =intToStr(j);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpT.cont);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen("] = ");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_757);
unsigned int strLen_4 = strlen("->data[");
unsigned int strLen_5 = strlen(tmpV->name);
;                            
            ____BAH_COMPILER_VAR_756 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_756+currStrOff, tmpV->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_756+currStrOff, "->data[", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_756+currStrOff, ____BAH_COMPILER_VAR_757, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_756+currStrOff, "] = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_756+currStrOff, tmpT.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_756+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_758 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(decls);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_756);
;                            
            ____BAH_COMPILER_VAR_758 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_758+currStrOff, decls, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_758+currStrOff, ____BAH_COMPILER_VAR_756, strLen_1);
            currStrOff += strLen_1;
        
        }decls = ____BAH_COMPILER_VAR_758;

#undef tmpT
};

    {
        unsigned long nLength = len(elems->vars);
        if (nLength >= elems->vars->length) {
            if (nLength >= elems->vars->realLength) {
                if (elems->vars->realLength != 0) {
                    elems->vars->realLength *= 2;
                } else {
                    elems->vars->realLength = 50;
                }
                void * newPtr = memoryRealloc(elems->vars->data, (elems->vars->realLength)*sizeof(struct variable*));
                elems->vars->data = newPtr;
            }
            elems->vars->data[len(elems->vars)] = tmpV;
            elems->vars->length = nLength+1;
        } else {
            elems->vars->data[len(elems->vars)] = tmpV;
        }
    }
    ;
char * ____BAH_COMPILER_VAR_759 =null;char * ____BAH_COMPILER_VAR_760 =intToStr(len(symbols));char * ____BAH_COMPILER_VAR_761 =intToStr(len(symbols));
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(decls);
unsigned int strLen_1 = strlen("\n        ");
unsigned int strLen_2 = strlen("->elemSize = sizeof(struct reflectElement);\n        ");
unsigned int strLen_3 = strlen(tmpV->name);
unsigned int strLen_4 = strlen(";\n        ");
unsigned int strLen_5 = strlen(____BAH_COMPILER_VAR_760);
unsigned int strLen_6 = strlen("->length = ");
unsigned int strLen_7 = strlen(tmpV->name);
unsigned int strLen_8 = strlen(");\n        ");
unsigned int strLen_9 = strlen(____BAH_COMPILER_VAR_761);
unsigned int strLen_10 = strlen("->data = memoryAlloc(sizeof(struct reflectElement) * ");
unsigned int strLen_11 = strlen(tmpV->name);
unsigned int strLen_12 = strlen(" = memoryAlloc(sizeof(array(struct reflectElement)));\n        ");
unsigned int strLen_13 = strlen(tmpV->name);
unsigned int strLen_14 = strlen("\n        array(struct reflectElement)* ");
;                            
            ____BAH_COMPILER_VAR_759 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13+strLen_14);
            
                    memcpy(____BAH_COMPILER_VAR_759+currStrOff, "\n        array(struct reflectElement)* ", strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_759+currStrOff, tmpV->name, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_759+currStrOff, " = memoryAlloc(sizeof(array(struct reflectElement)));\n        ", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_759+currStrOff, tmpV->name, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_759+currStrOff, "->data = memoryAlloc(sizeof(struct reflectElement) * ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_759+currStrOff, ____BAH_COMPILER_VAR_761, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_759+currStrOff, ");\n        ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_759+currStrOff, tmpV->name, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_759+currStrOff, "->length = ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_759+currStrOff, ____BAH_COMPILER_VAR_760, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_759+currStrOff, ";\n        ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_759+currStrOff, tmpV->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_759+currStrOff, "->elemSize = sizeof(struct reflectElement);\n        ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_759+currStrOff, decls, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_759+currStrOff, "\n        ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_759));
struct Tok ____BAH_COMPILER_VAR_762 = {};
____BAH_COMPILER_VAR_762.cont = "";
____BAH_COMPILER_VAR_762.ogCont = "";
____BAH_COMPILER_VAR_762.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_762.pos = 0;
____BAH_COMPILER_VAR_762.line = 1;
____BAH_COMPILER_VAR_762.begLine = 1;
____BAH_COMPILER_VAR_762.bahType = "";
____BAH_COMPILER_VAR_762.isValue = false;
____BAH_COMPILER_VAR_762.isFunc = false;
____BAH_COMPILER_VAR_762.isOper = false;
____BAH_COMPILER_VAR_762.isEqual = false;
____BAH_COMPILER_VAR_762.pass = false;
____BAH_COMPILER_VAR_762.bahRef= null;
____BAH_COMPILER_VAR_762.parent= null;
____BAH_COMPILER_VAR_762.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_762.cont = tmpV->name;
____BAH_COMPILER_VAR_762.line = fnt.line;
____BAH_COMPILER_VAR_762.isValue = true;

    {
        unsigned long nLength = 0;
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(struct Tok));
                memory->data = newPtr;
            }
            memory->data[0] = ____BAH_COMPILER_VAR_762;
            memory->length = nLength+1;
        } else {
            memory->data[0] = ____BAH_COMPILER_VAR_762;
        }
    }
    ;
}
else if ((strcmp(fn->name, "breakPoint") == 0)) {
struct Tok ____BAH_COMPILER_VAR_763 = {};
____BAH_COMPILER_VAR_763.cont = "";
____BAH_COMPILER_VAR_763.ogCont = "";
____BAH_COMPILER_VAR_763.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_763.pos = 0;
____BAH_COMPILER_VAR_763.line = 1;
____BAH_COMPILER_VAR_763.begLine = 1;
____BAH_COMPILER_VAR_763.bahType = "";
____BAH_COMPILER_VAR_763.isValue = false;
____BAH_COMPILER_VAR_763.isFunc = false;
____BAH_COMPILER_VAR_763.isOper = false;
____BAH_COMPILER_VAR_763.isEqual = false;
____BAH_COMPILER_VAR_763.pass = false;
____BAH_COMPILER_VAR_763.bahRef= null;
____BAH_COMPILER_VAR_763.parent= null;
____BAH_COMPILER_VAR_763.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_763.cont = "__dumpSymbols";
____BAH_COMPILER_VAR_763.line = fnt.line;
struct Tok ____BAH_COMPILER_VAR_764 = {};
____BAH_COMPILER_VAR_764.cont = "";
____BAH_COMPILER_VAR_764.ogCont = "";
____BAH_COMPILER_VAR_764.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_764.pos = 0;
____BAH_COMPILER_VAR_764.line = 1;
____BAH_COMPILER_VAR_764.begLine = 1;
____BAH_COMPILER_VAR_764.bahType = "";
____BAH_COMPILER_VAR_764.isValue = false;
____BAH_COMPILER_VAR_764.isFunc = false;
____BAH_COMPILER_VAR_764.isOper = false;
____BAH_COMPILER_VAR_764.isEqual = false;
____BAH_COMPILER_VAR_764.pass = false;
____BAH_COMPILER_VAR_764.bahRef= null;
____BAH_COMPILER_VAR_764.parent= null;
____BAH_COMPILER_VAR_764.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_764.cont = "(";
____BAH_COMPILER_VAR_764.line = fnt.line;
struct Tok ____BAH_COMPILER_VAR_765 = {};
____BAH_COMPILER_VAR_765.cont = "";
____BAH_COMPILER_VAR_765.ogCont = "";
____BAH_COMPILER_VAR_765.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_765.pos = 0;
____BAH_COMPILER_VAR_765.line = 1;
____BAH_COMPILER_VAR_765.begLine = 1;
____BAH_COMPILER_VAR_765.bahType = "";
____BAH_COMPILER_VAR_765.isValue = false;
____BAH_COMPILER_VAR_765.isFunc = false;
____BAH_COMPILER_VAR_765.isOper = false;
____BAH_COMPILER_VAR_765.isEqual = false;
____BAH_COMPILER_VAR_765.pass = false;
____BAH_COMPILER_VAR_765.bahRef= null;
____BAH_COMPILER_VAR_765.parent= null;
____BAH_COMPILER_VAR_765.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_765.cont = ")";
____BAH_COMPILER_VAR_765.line = fnt.line;
memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 3;
memory->elemSize = sizeof(struct Tok);
memory->data = memoryAlloc(sizeof(struct Tok) * 50);
                    memory->realLength = 50;
memory->data[0] = ____BAH_COMPILER_VAR_763;
memory->data[1] = ____BAH_COMPILER_VAR_764;
memory->data[2] = ____BAH_COMPILER_VAR_765;
memory = prePross(memory,LINE_TYPE_FN_CALL,elems);
struct Tok ____BAH_COMPILER_VAR_766 = {};
____BAH_COMPILER_VAR_766.cont = "";
____BAH_COMPILER_VAR_766.ogCont = "";
____BAH_COMPILER_VAR_766.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_766.pos = 0;
____BAH_COMPILER_VAR_766.line = 1;
____BAH_COMPILER_VAR_766.begLine = 1;
____BAH_COMPILER_VAR_766.bahType = "";
____BAH_COMPILER_VAR_766.isValue = false;
____BAH_COMPILER_VAR_766.isFunc = false;
____BAH_COMPILER_VAR_766.isOper = false;
____BAH_COMPILER_VAR_766.isEqual = false;
____BAH_COMPILER_VAR_766.pass = false;
____BAH_COMPILER_VAR_766.bahRef= null;
____BAH_COMPILER_VAR_766.parent= null;
____BAH_COMPILER_VAR_766.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_766.cont = ",";
____BAH_COMPILER_VAR_766.line = fnt.line;

    {
        unsigned long nLength = len(memory);
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(struct Tok));
                memory->data = newPtr;
            }
            memory->data[len(memory)] = ____BAH_COMPILER_VAR_766;
            memory->length = nLength+1;
        } else {
            memory->data[len(memory)] = ____BAH_COMPILER_VAR_766;
        }
    }
    ;
struct Tok ____BAH_COMPILER_VAR_767 = {};
____BAH_COMPILER_VAR_767.cont = "";
____BAH_COMPILER_VAR_767.ogCont = "";
____BAH_COMPILER_VAR_767.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_767.pos = 0;
____BAH_COMPILER_VAR_767.line = 1;
____BAH_COMPILER_VAR_767.begLine = 1;
____BAH_COMPILER_VAR_767.bahType = "";
____BAH_COMPILER_VAR_767.isValue = false;
____BAH_COMPILER_VAR_767.isFunc = false;
____BAH_COMPILER_VAR_767.isOper = false;
____BAH_COMPILER_VAR_767.isEqual = false;
____BAH_COMPILER_VAR_767.pass = false;
____BAH_COMPILER_VAR_767.bahRef= null;
____BAH_COMPILER_VAR_767.parent= null;
____BAH_COMPILER_VAR_767.type = TOKEN_TYPE_STR;
____BAH_COMPILER_VAR_767.cont = currLine;
____BAH_COMPILER_VAR_767.line = fnt.line;

    {
        unsigned long nLength = len(memory);
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(struct Tok));
                memory->data = newPtr;
            }
            memory->data[len(memory)] = ____BAH_COMPILER_VAR_767;
            memory->length = nLength+1;
        } else {
            memory->data[len(memory)] = ____BAH_COMPILER_VAR_767;
        }
    }
    ;
fn = searchFunc("breakPoint__inner",elems,true);
char * ____BAH_COMPILER_VAR_768 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fn->name);
unsigned int strLen_1 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_768 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_768+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_768+currStrOff, "(", strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_768;
}
else if ((strcmp(fn->name, "sizeof") == 0)) {
char * tp = "";
register long int j = 0;
for (; (j<len(memory)); ++j) {
struct Tok tmpT = memory->data[j];
char * ____BAH_COMPILER_VAR_769 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tp);
unsigned int strLen_1 = strlen(tmpT.cont);
;                            
            ____BAH_COMPILER_VAR_769 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_769+currStrOff, tp, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_769+currStrOff, tmpT.cont, strLen_1);
            currStrOff += strLen_1;
        
        }tp = ____BAH_COMPILER_VAR_769;
};
struct string cType = getCType(tp,elems);
char * ____BAH_COMPILER_VAR_770 =null;char * ____BAH_COMPILER_VAR_771 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_771);
unsigned int strLen_1 = strlen(")");
;                            
            ____BAH_COMPILER_VAR_770 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_770+currStrOff, ____BAH_COMPILER_VAR_771, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_770+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_772 =null;char * ____BAH_COMPILER_VAR_773 =____BAH_COMPILER_VAR_770;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnt.cont);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_773);
;                            
            ____BAH_COMPILER_VAR_772 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_772+currStrOff, fnt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_772+currStrOff, ____BAH_COMPILER_VAR_773, strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_772;
fnt.type = TOKEN_TYPE_FUNC;
fnt.isFunc = true;
fnt.bahType = "int";
fnt.bahRef = fn;

    {
        unsigned long nLength = tokPos;
        if (nLength >= l->length) {
            if (nLength >= l->realLength) {
                if (l->realLength != 0) {
                    l->realLength *= 2;
                } else {
                    l->realLength = 50;
                }
                void * newPtr = memoryRealloc(l->data, (l->realLength)*sizeof(struct Tok));
                l->data = newPtr;
            }
            l->data[tokPos] = fnt;
            l->length = nLength+1;
        } else {
            l->data[tokPos] = fnt;
        }
    }
    ;
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
char * ____BAH_COMPILER_VAR_774 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(amp);
unsigned int strLen_1 = strlen(parent->name);
;                            
            ____BAH_COMPILER_VAR_774 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_774+currStrOff, amp, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_774+currStrOff, parent->name, strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_775 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnt.cont);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_774);
;                            
            ____BAH_COMPILER_VAR_775 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_775+currStrOff, fnt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_775+currStrOff, ____BAH_COMPILER_VAR_774, strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_775;
++argIndex;
if ((len(fn->args)>argIndex)) {
char * ____BAH_COMPILER_VAR_776 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnt.cont);
unsigned int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_776 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_776+currStrOff, fnt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_776+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_776;
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
char * ____BAH_COMPILER_VAR_777 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(arg->type);
unsigned int strLen_1 = strlen(" in function call.");
unsigned int strLen_2 = strlen(") as ");
unsigned int strLen_3 = strlen(tt);
unsigned int strLen_4 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_777 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_777+currStrOff, "Cannot use {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_777+currStrOff, tt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_777+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_777+currStrOff, arg->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_777+currStrOff, " in function call.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&t,____BAH_COMPILER_VAR_777);
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
char * ____BAH_COMPILER_VAR_778 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnt.cont);
unsigned int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_778 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_778+currStrOff, fnt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_778+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_778;
++argIndex;
if ((j+1<len(memory))) {
++j;
t = memory->data[j];
if ((strcmp(t.cont, ",") != 0)) {
throwErr(&t,"Need separator between arguments, not {TOKEN}.");
}
char * ____BAH_COMPILER_VAR_779 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnt.cont);
unsigned int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_779 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_779+currStrOff, fnt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_779+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_779;
}
};
if ((argIndex!=len(fn->args))) {
struct Tok lt = l->data[tokPos];
char * ____BAH_COMPILER_VAR_780 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fn->name);
unsigned int strLen_1 = strlen("'.");
unsigned int strLen_2 = strlen("Not enough argument {TOKEN}, calling '");
;                            
            ____BAH_COMPILER_VAR_780 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_780+currStrOff, "Not enough argument {TOKEN}, calling '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_780+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_780+currStrOff, "'.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&lt,____BAH_COMPILER_VAR_780);
}
fnt.bahRef = fn;
char * ____BAH_COMPILER_VAR_781 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnt.cont);
unsigned int strLen_1 = strlen(")");
;                            
            ____BAH_COMPILER_VAR_781 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_781+currStrOff, fnt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_781+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_781;

    {
        unsigned long nLength = tokPos;
        if (nLength >= l->length) {
            if (nLength >= l->realLength) {
                if (l->realLength != 0) {
                    l->realLength *= 2;
                } else {
                    l->realLength = 50;
                }
                void * newPtr = memoryRealloc(l->data, (l->realLength)*sizeof(struct Tok));
                l->data = newPtr;
            }
            l->data[tokPos] = fnt;
            l->length = nLength+1;
        } else {
            l->data[tokPos] = fnt;
        }
    }
    ;
return tokPos;
};
long int valueStruct(__BAH_ARR_TYPE_Tok l,long int i,lineType ltp,struct Elems* elems){
long int tokPos = i-1;
struct Tok t = l->data[i-1];
char * tt = getTypeFromToken(&t,true,elems);
struct cStruct* s = searchStruct(tt,elems);
if ((s==null)) {
if ((tt[strlen(tt)-1]==33)) {
char * ____BAH_COMPILER_VAR_782 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tt);
unsigned int strLen_1 = strlen(") as structure.");
unsigned int strLen_2 = strlen("Cannot use maybe value {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_782 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_782+currStrOff, "Cannot use maybe value {TOKEN} (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_782+currStrOff, tt, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_782+currStrOff, ") as structure.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&t,____BAH_COMPILER_VAR_782);
}
else {
char * ____BAH_COMPILER_VAR_783 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tt);
unsigned int strLen_1 = strlen(").");
unsigned int strLen_2 = strlen("Unkown struct {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_783 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_783+currStrOff, "Unkown struct {TOKEN} (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_783+currStrOff, tt, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_783+currStrOff, ").", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&t,____BAH_COMPILER_VAR_783);
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
char * ____BAH_COMPILER_VAR_784 =null;char * ____BAH_COMPILER_VAR_785 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t.cont);
unsigned int strLen_1 = strlen(";\n                ");
unsigned int strLen_2 = strlen(" = ");
unsigned int strLen_3 = strlen(tmpV);
unsigned int strLen_4 = strlen(" ");
unsigned int strLen_5 = strlen(____BAH_COMPILER_VAR_785);
unsigned int strLen_6 = strlen("\n                ");
;                            
            ____BAH_COMPILER_VAR_784 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_784+currStrOff, "\n                ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_784+currStrOff, ____BAH_COMPILER_VAR_785, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_784+currStrOff, " ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_784+currStrOff, tmpV, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_784+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_784+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_784+currStrOff, ";\n                ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_784));
t.cont = tmpV;
struct variable* ____BAH_COMPILER_VAR_786 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_786->name = "";
____BAH_COMPILER_VAR_786->type = "";
____BAH_COMPILER_VAR_786->isConst = false;
____BAH_COMPILER_VAR_786->constVal = "";
____BAH_COMPILER_VAR_786->isArray = false;
____BAH_COMPILER_VAR_786->from = "";
____BAH_COMPILER_VAR_786->declScope= null;
____BAH_COMPILER_VAR_786->isGlobal = false;
____BAH_COMPILER_VAR_786->declRope= null;
____BAH_COMPILER_VAR_786->canBeNull = false;
____BAH_COMPILER_VAR_786->isReg = false;
____BAH_COMPILER_VAR_786->lastSet= null;
____BAH_COMPILER_VAR_786->isArg = false;
____BAH_COMPILER_VAR_786->name = tmpV;
____BAH_COMPILER_VAR_786->type = tt;
parent = ____BAH_COMPILER_VAR_786;
if (RCPavailable()) {

    {
        unsigned long nLength = len(elems->vars);
        if (nLength >= elems->vars->length) {
            if (nLength >= elems->vars->realLength) {
                if (elems->vars->realLength != 0) {
                    elems->vars->realLength *= 2;
                } else {
                    elems->vars->realLength = 50;
                }
                void * newPtr = memoryRealloc(elems->vars->data, (elems->vars->realLength)*sizeof(struct variable*));
                elems->vars->data = newPtr;
            }
            elems->vars->data[len(elems->vars)] = parent;
            elems->vars->length = nLength+1;
        } else {
            elems->vars->data[len(elems->vars)] = parent;
        }
    }
    ;
}
}
struct func* fn = searchStructMethod(nt.cont,s,elems);
if ((fn==null)) {
char * ____BAH_COMPILER_VAR_787 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s->name);
unsigned int strLen_1 = strlen(".");
unsigned int strLen_2 = strlen("Unknown method {TOKEN} in struct ");
;                            
            ____BAH_COMPILER_VAR_787 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_787+currStrOff, "Unknown method {TOKEN} in struct ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_787+currStrOff, s->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_787+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&nt,____BAH_COMPILER_VAR_787);
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
char * ____BAH_COMPILER_VAR_788 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(sep);
unsigned int strLen_1 = strlen(fn->name);
unsigned int strLen_2 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_788 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_788+currStrOff, t.cont, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_788+currStrOff, sep, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_788+currStrOff, fn->name, strLen_1);
            currStrOff += strLen_1;
        
        }fn->name = ____BAH_COMPILER_VAR_788;
}
if ((parent==null)) {
throwErr(&t,"Could not find structure {TOKEN}.");
}
valueFunc(fn,parent,l,i,ltp,elems);
struct Tok fnt = l->data[i];
delete(l,i);
char * ____BAH_COMPILER_VAR_789 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(".");
unsigned int strLen_1 = strlen(nt.ogCont);
unsigned int strLen_2 = strlen(t.ogCont);
;                            
            ____BAH_COMPILER_VAR_789 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_789+currStrOff, t.ogCont, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_789+currStrOff, ".", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_789+currStrOff, nt.ogCont, strLen_1);
            currStrOff += strLen_1;
        
        }fnt.ogCont = ____BAH_COMPILER_VAR_789;
fnt.pos = t.pos;

    {
        unsigned long nLength = tokPos;
        if (nLength >= l->length) {
            if (nLength >= l->realLength) {
                if (l->realLength != 0) {
                    l->realLength *= 2;
                } else {
                    l->realLength = 50;
                }
                void * newPtr = memoryRealloc(l->data, (l->realLength)*sizeof(struct Tok));
                l->data = newPtr;
            }
            l->data[tokPos] = fnt;
            l->length = nLength+1;
        } else {
            l->data[tokPos] = fnt;
        }
    }
    ;
return tokPos;
}
}
struct structMemb* m = searchStructMemb(nt.cont,s,elems);
if ((m==null)) {
char * ____BAH_COMPILER_VAR_790 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s->name);
unsigned int strLen_1 = strlen("'.");
unsigned int strLen_2 = strlen("Unknown struct member {TOKEN} in struct '");
;                            
            ____BAH_COMPILER_VAR_790 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_790+currStrOff, "Unknown struct member {TOKEN} in struct '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_790+currStrOff, s->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_790+currStrOff, "'.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&nt,____BAH_COMPILER_VAR_790);
}
if ((m->isFn==true)) {
char * ____BAH_COMPILER_VAR_791 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("__");
unsigned int strLen_1 = strlen(m->name);
unsigned int strLen_2 = strlen(s->name);
;                            
            ____BAH_COMPILER_VAR_791 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_791+currStrOff, s->name, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_791+currStrOff, "__", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_791+currStrOff, m->name, strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_791;
}
else {
if ((t.type==TOKEN_TYPE_VAR)) {
t.parent = searchVarByToken(&t,elems);
}
char * ____BAH_COMPILER_VAR_792 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(sep);
unsigned int strLen_1 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_792 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_792+currStrOff, sep, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_792+currStrOff, nt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_793 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t.cont);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_792);
;                            
            ____BAH_COMPILER_VAR_793 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_793+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_793+currStrOff, ____BAH_COMPILER_VAR_792, strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_793;
}
char * ____BAH_COMPILER_VAR_794 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(".");
unsigned int strLen_1 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_794 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_794+currStrOff, ".", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_794+currStrOff, nt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_795 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t.ogCont);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_794);
;                            
            ____BAH_COMPILER_VAR_795 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_795+currStrOff, t.ogCont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_795+currStrOff, ____BAH_COMPILER_VAR_794, strLen_1);
            currStrOff += strLen_1;
        
        }t.ogCont = ____BAH_COMPILER_VAR_795;
t.bahType = m->type;
struct variable* ____BAH_COMPILER_VAR_796 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_796->name = "";
____BAH_COMPILER_VAR_796->type = "";
____BAH_COMPILER_VAR_796->isConst = false;
____BAH_COMPILER_VAR_796->constVal = "";
____BAH_COMPILER_VAR_796->isArray = false;
____BAH_COMPILER_VAR_796->from = "";
____BAH_COMPILER_VAR_796->declScope= null;
____BAH_COMPILER_VAR_796->isGlobal = false;
____BAH_COMPILER_VAR_796->declRope= null;
____BAH_COMPILER_VAR_796->canBeNull = false;
____BAH_COMPILER_VAR_796->isReg = false;
____BAH_COMPILER_VAR_796->lastSet= null;
____BAH_COMPILER_VAR_796->isArg = false;
____BAH_COMPILER_VAR_796->name = t.cont;
____BAH_COMPILER_VAR_796->type = t.bahType;
t.bahRef = ____BAH_COMPILER_VAR_796;

    {
        unsigned long nLength = tokPos;
        if (nLength >= l->length) {
            if (nLength >= l->realLength) {
                if (l->realLength != 0) {
                    l->realLength *= 2;
                } else {
                    l->realLength = 50;
                }
                void * newPtr = memoryRealloc(l->data, (l->realLength)*sizeof(struct Tok));
                l->data = newPtr;
            }
            l->data[tokPos] = t;
            l->length = nLength+1;
        } else {
            l->data[tokPos] = t;
        }
    }
    ;
return tokPos;
};
long int valueArr(__BAH_ARR_TYPE_Tok l,long int i,lineType ltp,struct Elems* elems){
long int tokPos = i-1;
struct Tok pt = l->data[tokPos];
delete(l,tokPos);
if ((pt.isValue==false)) {
throwErr(&pt,"Cannot use {TOKEN} as value (array).");
}
char * ____BAH_COMPILER_VAR_797 =getTypeFromToken(&pt,true,elems);struct string ptt = string(____BAH_COMPILER_VAR_797);
struct Tok t = pt;
t.isValue = true;
char * ____BAH_COMPILER_VAR_798 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t.ogCont);
unsigned int strLen_1 = strlen("[");
;                            
            ____BAH_COMPILER_VAR_798 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_798+currStrOff, t.ogCont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_798+currStrOff, "[", strLen_1);
            currStrOff += strLen_1;
        
        }t.ogCont = ____BAH_COMPILER_VAR_798;
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
char * ____BAH_COMPILER_VAR_799 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t.ogCont);
unsigned int strLen_1 = strlen("]");
;                            
            ____BAH_COMPILER_VAR_799 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_799+currStrOff, t.ogCont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_799+currStrOff, "]", strLen_1);
            currStrOff += strLen_1;
        
        }t.ogCont = ____BAH_COMPILER_VAR_799;
if ((nbEncls==0)) {
break;
}
}
char * ____BAH_COMPILER_VAR_800 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t.ogCont);
unsigned int strLen_1 = strlen(tmpT.ogCont);
;                            
            ____BAH_COMPILER_VAR_800 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_800+currStrOff, t.ogCont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_800+currStrOff, tmpT.ogCont, strLen_1);
            currStrOff += strLen_1;
        
        }t.ogCont = ____BAH_COMPILER_VAR_800;

    {
        unsigned long nLength = len(memory);
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(struct Tok));
                memory->data = newPtr;
            }
            memory->data[len(memory)] = tmpT;
            memory->length = nLength+1;
        } else {
            memory->data[len(memory)] = tmpT;
        }
    }
    ;
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
char * ____BAH_COMPILER_VAR_801 =getTypeFromToken(&index,true,elems);if ((compTypes(____BAH_COMPILER_VAR_801,"int")==false)) {
throwErr(&index,"Cannot use {TOKEN} as array index (int).");
}
char * ____BAH_COMPILER_VAR_802 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(index.cont);
unsigned int strLen_1 = strlen("]");
unsigned int strLen_2 = strlen("->data[");
unsigned int strLen_3 = strlen(pt.cont);
;                            
            ____BAH_COMPILER_VAR_802 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_802+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_802+currStrOff, "->data[", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_802+currStrOff, index.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_802+currStrOff, "]", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_802;
string__trimLeft(&ptt,2);
t.bahType = string__str(&ptt);
}
else {
t.bahType = string__str(&ptt);
if ((strcmp(to, "") == 0)) {
char * ____BAH_COMPILER_VAR_803 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(pt.cont);
unsigned int strLen_1 = strlen("->length");
;                            
            ____BAH_COMPILER_VAR_803 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_803+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_803+currStrOff, "->length", strLen_1);
            currStrOff += strLen_1;
        
        }to = ____BAH_COMPILER_VAR_803;
}
char * ____BAH_COMPILER_VAR_804 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(to);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen(", ");
unsigned int strLen_3 = strlen(from);
unsigned int strLen_4 = strlen(", ");
unsigned int strLen_5 = strlen(pt.cont);
unsigned int strLen_6 = strlen("arraySubstitute(");
;                            
            ____BAH_COMPILER_VAR_804 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_804+currStrOff, "arraySubstitute(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_804+currStrOff, pt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_804+currStrOff, ", ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_804+currStrOff, from, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_804+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_804+currStrOff, to, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_804+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_804;
}
}
else if (string__hasPrefix(&ptt,"buffer:")) {
if ((split==false)) {
t.bahType = "char";
struct Tok index = memory->data[0];
char * ____BAH_COMPILER_VAR_805 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(index.cont);
unsigned int strLen_1 = strlen("]");
unsigned int strLen_2 = strlen("[");
unsigned int strLen_3 = strlen(pt.cont);
;                            
            ____BAH_COMPILER_VAR_805 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_805+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_805+currStrOff, "[", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_805+currStrOff, index.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_805+currStrOff, "]", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_805;
}
else {
t.bahType = "cpstring";
if ((strcmp(to, "") == 0)) {
char * ____BAH_COMPILER_VAR_806 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(pt.cont);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen("strlen(");
;                            
            ____BAH_COMPILER_VAR_806 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_806+currStrOff, "strlen(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_806+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_806+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }to = ____BAH_COMPILER_VAR_806;
}
char * ____BAH_COMPILER_VAR_807 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(to);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen(", ");
unsigned int strLen_3 = strlen(from);
unsigned int strLen_4 = strlen(", ");
unsigned int strLen_5 = strlen(pt.cont);
unsigned int strLen_6 = strlen("cpstringSubsitute(");
;                            
            ____BAH_COMPILER_VAR_807 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_807+currStrOff, "cpstringSubsitute(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_807+currStrOff, pt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_807+currStrOff, ", ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_807+currStrOff, from, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_807+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_807+currStrOff, to, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_807+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_807;
}
}
else if (string__hasPrefix(&ptt,"map:")) {
if ((split==true)) {
throwErr(&pt,"Cannot do substitution on a map {TOKEN}.");
}
string__trimLeft(&ptt,4);
char * ____BAH_COMPILER_VAR_808 =string__str(&ptt);struct string elemType = getCType(____BAH_COMPILER_VAR_808,elems);
struct Tok index = memory->data[0];
if ((tokPos==0)&&(ltp==LINE_TYPE_VAR)) {
struct variable* ____BAH_COMPILER_VAR_809 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_809->name = "";
____BAH_COMPILER_VAR_809->type = "";
____BAH_COMPILER_VAR_809->isConst = false;
____BAH_COMPILER_VAR_809->constVal = "";
____BAH_COMPILER_VAR_809->isArray = false;
____BAH_COMPILER_VAR_809->from = "";
____BAH_COMPILER_VAR_809->declScope= null;
____BAH_COMPILER_VAR_809->isGlobal = false;
____BAH_COMPILER_VAR_809->declRope= null;
____BAH_COMPILER_VAR_809->canBeNull = false;
____BAH_COMPILER_VAR_809->isReg = false;
____BAH_COMPILER_VAR_809->lastSet= null;
____BAH_COMPILER_VAR_809->isArg = false;
____BAH_COMPILER_VAR_809->name = genCompilerVar();
____BAH_COMPILER_VAR_809->type = string__str(&ptt);
struct variable* tmpV = ____BAH_COMPILER_VAR_809;

    {
        unsigned long nLength = len(elems->vars);
        if (nLength >= elems->vars->length) {
            if (nLength >= elems->vars->realLength) {
                if (elems->vars->realLength != 0) {
                    elems->vars->realLength *= 2;
                } else {
                    elems->vars->realLength = 50;
                }
                void * newPtr = memoryRealloc(elems->vars->data, (elems->vars->realLength)*sizeof(struct variable*));
                elems->vars->data = newPtr;
            }
            elems->vars->data[len(elems->vars)] = tmpV;
            elems->vars->length = nLength+1;
        } else {
            elems->vars->data[len(elems->vars)] = tmpV;
        }
    }
    ;
if (isGlobal()) {
char * ____BAH_COMPILER_VAR_810 =null;char * ____BAH_COMPILER_VAR_811 =string__str(&elemType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpV->name);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen(" ");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_811);
;                            
            ____BAH_COMPILER_VAR_810 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_810+currStrOff, ____BAH_COMPILER_VAR_811, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_810+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_810+currStrOff, tmpV->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_810+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_810));
}
else {
char * ____BAH_COMPILER_VAR_812 =null;char * ____BAH_COMPILER_VAR_813 =string__str(&elemType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpV->name);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen(" ");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_813);
;                            
            ____BAH_COMPILER_VAR_812 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_812+currStrOff, ____BAH_COMPILER_VAR_813, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_812+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_812+currStrOff, tmpV->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_812+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_812));
}
char * ____BAH_COMPILER_VAR_814 =string__str(&ptt);if (isRCPpointerType(____BAH_COMPILER_VAR_814)) {
char * ____BAH_COMPILER_VAR_815 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpV->name);
unsigned int strLen_1 = strlen(");\n");
unsigned int strLen_2 = strlen(", ");
unsigned int strLen_3 = strlen(index.cont);
unsigned int strLen_4 = strlen(", ");
unsigned int strLen_5 = strlen(pt.cont);
unsigned int strLen_6 = strlen("mapWrapper__set(");
;                            
            ____BAH_COMPILER_VAR_815 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_815+currStrOff, "mapWrapper__set(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_815+currStrOff, pt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_815+currStrOff, ", ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_815+currStrOff, index.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_815+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_815+currStrOff, tmpV->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_815+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }NEXT_LINE = ____BAH_COMPILER_VAR_815;
}
else {
char * ____BAH_COMPILER_VAR_816 =null;char * ____BAH_COMPILER_VAR_817 =string__str(&elemType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_817);
unsigned int strLen_1 = strlen("));\n");
unsigned int strLen_2 = strlen(", sizeof(");
unsigned int strLen_3 = strlen(tmpV->name);
unsigned int strLen_4 = strlen(", &");
unsigned int strLen_5 = strlen(index.cont);
unsigned int strLen_6 = strlen(", ");
unsigned int strLen_7 = strlen(pt.cont);
unsigned int strLen_8 = strlen("mapWrapper__setAny(");
;                            
            ____BAH_COMPILER_VAR_816 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_816+currStrOff, "mapWrapper__setAny(", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_816+currStrOff, pt.cont, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_816+currStrOff, ", ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_816+currStrOff, index.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_816+currStrOff, ", &", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_816+currStrOff, tmpV->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_816+currStrOff, ", sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_816+currStrOff, ____BAH_COMPILER_VAR_817, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_816+currStrOff, "));\n", strLen_1);
            currStrOff += strLen_1;
        
        }NEXT_LINE = ____BAH_COMPILER_VAR_816;
}
t.cont = tmpV->name;
t.bahType = string__str(&ptt);
}
else {
t.isFunc = true;
struct rope* res= null;
char * tmpV = genCompilerVar();
char * ____BAH_COMPILER_VAR_818 =string__str(&ptt);if (isRCPpointerType(____BAH_COMPILER_VAR_818)) {
char * ____BAH_COMPILER_VAR_819 =null;char * ____BAH_COMPILER_VAR_820 =string__str(&elemType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(index.cont);
unsigned int strLen_1 = strlen(");\n");
unsigned int strLen_2 = strlen(", ");
unsigned int strLen_3 = strlen(t.cont);
unsigned int strLen_4 = strlen("=mapWrapper__get(");
unsigned int strLen_5 = strlen(tmpV);
unsigned int strLen_6 = strlen(" ");
unsigned int strLen_7 = strlen(____BAH_COMPILER_VAR_820);
;                            
            ____BAH_COMPILER_VAR_819 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7);
            
                    memcpy(____BAH_COMPILER_VAR_819+currStrOff, ____BAH_COMPILER_VAR_820, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_819+currStrOff, " ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_819+currStrOff, tmpV, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_819+currStrOff, "=mapWrapper__get(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_819+currStrOff, t.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_819+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_819+currStrOff, index.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_819+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }res = rope(____BAH_COMPILER_VAR_819);
t.cont = tmpV;
}
else {
char * ____BAH_COMPILER_VAR_821 =null;char * ____BAH_COMPILER_VAR_822 =string__str(&elemType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(index.cont);
unsigned int strLen_1 = strlen(");\n");
unsigned int strLen_2 = strlen(", ");
unsigned int strLen_3 = strlen(pt.cont);
unsigned int strLen_4 = strlen("=mapWrapper__get(");
unsigned int strLen_5 = strlen(tmpV);
unsigned int strLen_6 = strlen("* ");
unsigned int strLen_7 = strlen(____BAH_COMPILER_VAR_822);
;                            
            ____BAH_COMPILER_VAR_821 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7);
            
                    memcpy(____BAH_COMPILER_VAR_821+currStrOff, ____BAH_COMPILER_VAR_822, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_821+currStrOff, "* ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_821+currStrOff, tmpV, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_821+currStrOff, "=mapWrapper__get(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_821+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_821+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_821+currStrOff, index.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_821+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }res = rope(____BAH_COMPILER_VAR_821);
char * ____BAH_COMPILER_VAR_823 =null;char * ____BAH_COMPILER_VAR_824 =string__str(&elemType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpV);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen(")(*");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_824);
unsigned int strLen_4 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_823 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_823+currStrOff, "(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_823+currStrOff, ____BAH_COMPILER_VAR_824, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_823+currStrOff, ")(*", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_823+currStrOff, tmpV, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_823+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_823;
}
if (RCPavailable()) {
struct variable* ____BAH_COMPILER_VAR_825 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_825->name = "";
____BAH_COMPILER_VAR_825->type = "";
____BAH_COMPILER_VAR_825->isConst = false;
____BAH_COMPILER_VAR_825->constVal = "";
____BAH_COMPILER_VAR_825->isArray = false;
____BAH_COMPILER_VAR_825->from = "";
____BAH_COMPILER_VAR_825->declScope= null;
____BAH_COMPILER_VAR_825->isGlobal = false;
____BAH_COMPILER_VAR_825->declRope= null;
____BAH_COMPILER_VAR_825->canBeNull = false;
____BAH_COMPILER_VAR_825->isReg = false;
____BAH_COMPILER_VAR_825->lastSet= null;
____BAH_COMPILER_VAR_825->isArg = false;
____BAH_COMPILER_VAR_825->name = tmpV;
____BAH_COMPILER_VAR_825->type = string__str(&ptt);

    {
        unsigned long nLength = len(elems->vars);
        if (nLength >= elems->vars->length) {
            if (nLength >= elems->vars->realLength) {
                if (elems->vars->realLength != 0) {
                    elems->vars->realLength *= 2;
                } else {
                    elems->vars->realLength = 50;
                }
                void * newPtr = memoryRealloc(elems->vars->data, (elems->vars->realLength)*sizeof(struct variable*));
                elems->vars->data = newPtr;
            }
            elems->vars->data[len(elems->vars)] = ____BAH_COMPILER_VAR_825;
            elems->vars->length = nLength+1;
        } else {
            elems->vars->data[len(elems->vars)] = ____BAH_COMPILER_VAR_825;
        }
    }
    ;
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
char * ____BAH_COMPILER_VAR_826 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(index.cont);
unsigned int strLen_1 = strlen("]");
unsigned int strLen_2 = strlen("[");
unsigned int strLen_3 = strlen(pt.cont);
;                            
            ____BAH_COMPILER_VAR_826 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_826+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_826+currStrOff, "[", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_826+currStrOff, index.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_826+currStrOff, "]", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_826;
}
else {
if ((strcmp(to, "") == 0)) {
char * ____BAH_COMPILER_VAR_827 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(pt.cont);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen("strlen(");
;                            
            ____BAH_COMPILER_VAR_827 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_827+currStrOff, "strlen(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_827+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_827+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }to = ____BAH_COMPILER_VAR_827;
}
char * ____BAH_COMPILER_VAR_828 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(to);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen(", ");
unsigned int strLen_3 = strlen(from);
unsigned int strLen_4 = strlen(", ");
unsigned int strLen_5 = strlen(pt.cont);
unsigned int strLen_6 = strlen("cpstringSubsitute(");
;                            
            ____BAH_COMPILER_VAR_828 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_828+currStrOff, "cpstringSubsitute(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_828+currStrOff, pt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_828+currStrOff, ", ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_828+currStrOff, from, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_828+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_828+currStrOff, to, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_828+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_828;
}
}
else {
char * ____BAH_COMPILER_VAR_829 =null;char * ____BAH_COMPILER_VAR_830 =string__str(&ptt);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_830);
unsigned int strLen_1 = strlen(") as array.");
unsigned int strLen_2 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_829 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_829+currStrOff, "Cannot use {TOKEN} (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_829+currStrOff, ____BAH_COMPILER_VAR_830, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_829+currStrOff, ") as array.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&pt,____BAH_COMPILER_VAR_829);
}
t.isValue = true;

    {
        unsigned long nLength = tokPos;
        if (nLength >= l->length) {
            if (nLength >= l->realLength) {
                if (l->realLength != 0) {
                    l->realLength *= 2;
                } else {
                    l->realLength = 50;
                }
                void * newPtr = memoryRealloc(l->data, (l->realLength)*sizeof(struct Tok));
                l->data = newPtr;
            }
            l->data[tokPos] = t;
            l->length = nLength+1;
        } else {
            l->data[tokPos] = t;
        }
    }
    ;
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
char * ____BAH_COMPILER_VAR_831 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("register ");
unsigned int strLen_1 = strlen(odecl);
;                            
            ____BAH_COMPILER_VAR_831 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_831+currStrOff, "register ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_831+currStrOff, odecl, strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT->totalLen = OUTPUT->totalLen+ropeSet(v->declRope,____BAH_COMPILER_VAR_831);
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
char * ____BAH_COMPILER_VAR_832 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ntt);
unsigned int strLen_1 = strlen(") as array.");
unsigned int strLen_2 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_832 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_832+currStrOff, "Cannot use {TOKEN} (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_832+currStrOff, ntt, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_832+currStrOff, ") as array.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&nt,____BAH_COMPILER_VAR_832);
}
string__trimLeft(&arrT,2);
char * ____BAH_COMPILER_VAR_833 =string__str(&arrT);if ((compTypes(ptt,____BAH_COMPILER_VAR_833)==false)) {
char * ____BAH_COMPILER_VAR_834 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ntt);
unsigned int strLen_1 = strlen(".");
unsigned int strLen_2 = strlen(") in ");
unsigned int strLen_3 = strlen(ptt);
unsigned int strLen_4 = strlen("Cannot search for {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_834 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_834+currStrOff, "Cannot search for {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_834+currStrOff, ptt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_834+currStrOff, ") in ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_834+currStrOff, ntt, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_834+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&pt,____BAH_COMPILER_VAR_834);
}
char * compVar = genCompilerVar();
char * comp = "";
if ((strcmp(ptt, "cpstring") == 0)) {
char * ____BAH_COMPILER_VAR_835 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(pt.cont);
unsigned int strLen_1 = strlen(") == 0");
unsigned int strLen_2 = strlen("->data[i], ");
unsigned int strLen_3 = strlen(nt.cont);
unsigned int strLen_4 = strlen("->data[i] != 0 && strcmp(");
unsigned int strLen_5 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_835 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_835+currStrOff, nt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_835+currStrOff, "->data[i] != 0 && strcmp(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_835+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_835+currStrOff, "->data[i], ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_835+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_835+currStrOff, ") == 0", strLen_1);
            currStrOff += strLen_1;
        
        }comp = ____BAH_COMPILER_VAR_835;
}
else {
char * ____BAH_COMPILER_VAR_836 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("->data[i] == ");
unsigned int strLen_1 = strlen(pt.cont);
unsigned int strLen_2 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_836 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_836+currStrOff, nt.cont, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_836+currStrOff, "->data[i] == ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_836+currStrOff, pt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }comp = ____BAH_COMPILER_VAR_836;
}
char * ____BAH_COMPILER_VAR_837 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(compVar);
unsigned int strLen_1 = strlen("=1;\n                break;\n            };\n        }\n        ");
unsigned int strLen_2 = strlen(") {\n                ");
unsigned int strLen_3 = strlen(comp);
unsigned int strLen_4 = strlen("->length-1; i!=-1;i--) {\n            if (");
unsigned int strLen_5 = strlen(nt.cont);
unsigned int strLen_6 = strlen(" = 0;\n        for(int i=");
unsigned int strLen_7 = strlen(compVar);
unsigned int strLen_8 = strlen("\n        char ");
;                            
            ____BAH_COMPILER_VAR_837 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_837+currStrOff, "\n        char ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_837+currStrOff, compVar, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_837+currStrOff, " = 0;\n        for(int i=", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_837+currStrOff, nt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_837+currStrOff, "->length-1; i!=-1;i--) {\n            if (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_837+currStrOff, comp, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_837+currStrOff, ") {\n                ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_837+currStrOff, compVar, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_837+currStrOff, "=1;\n                break;\n            };\n        }\n        ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_837));
pt.cont = compVar;
}
else {
if ((compTypes(ptt,ntt)==false)) {
char * ____BAH_COMPILER_VAR_838 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ptt);
unsigned int strLen_1 = strlen(".");
unsigned int strLen_2 = strlen(") with type ");
unsigned int strLen_3 = strlen(ntt);
unsigned int strLen_4 = strlen("Cannot compare {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_838 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_838+currStrOff, "Cannot compare {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_838+currStrOff, ntt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_838+currStrOff, ") with type ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_838+currStrOff, ptt, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_838+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&nt,____BAH_COMPILER_VAR_838);
}
if ((strcmp(ptt, "cpstring") == 0)) {
if ((strcmp(t.cont, "==") == 0)) {
char * ____BAH_COMPILER_VAR_839 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen(") == 0)");
unsigned int strLen_2 = strlen(", ");
unsigned int strLen_3 = strlen(pt.cont);
unsigned int strLen_4 = strlen("(strcmp(");
;                            
            ____BAH_COMPILER_VAR_839 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_839+currStrOff, "(strcmp(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_839+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_839+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_839+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_839+currStrOff, ") == 0)", strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_839;
}
else if ((strcmp(t.cont, "!=") == 0)) {
char * ____BAH_COMPILER_VAR_840 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen(") != 0)");
unsigned int strLen_2 = strlen(", ");
unsigned int strLen_3 = strlen(pt.cont);
unsigned int strLen_4 = strlen("(strcmp(");
;                            
            ____BAH_COMPILER_VAR_840 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_840+currStrOff, "(strcmp(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_840+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_840+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_840+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_840+currStrOff, ") != 0)", strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_840;
}
else if ((strcmp(t.cont, ">") == 0)) {
char * ____BAH_COMPILER_VAR_841 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen("))");
unsigned int strLen_2 = strlen(") > srtlen(");
unsigned int strLen_3 = strlen(pt.cont);
unsigned int strLen_4 = strlen("(strlen(");
;                            
            ____BAH_COMPILER_VAR_841 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_841+currStrOff, "(strlen(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_841+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_841+currStrOff, ") > srtlen(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_841+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_841+currStrOff, "))", strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_841;
}
else if ((strcmp(t.cont, "<") == 0)) {
char * ____BAH_COMPILER_VAR_842 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen("))");
unsigned int strLen_2 = strlen(") < srtlen(");
unsigned int strLen_3 = strlen(pt.cont);
unsigned int strLen_4 = strlen("(strlen(");
;                            
            ____BAH_COMPILER_VAR_842 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_842+currStrOff, "(strlen(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_842+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_842+currStrOff, ") < srtlen(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_842+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_842+currStrOff, "))", strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_842;
}
else if ((strcmp(t.cont, ">=") == 0)) {
char * ____BAH_COMPILER_VAR_843 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen("))");
unsigned int strLen_2 = strlen(") >= srtlen(");
unsigned int strLen_3 = strlen(pt.cont);
unsigned int strLen_4 = strlen("(strlen(");
;                            
            ____BAH_COMPILER_VAR_843 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_843+currStrOff, "(strlen(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_843+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_843+currStrOff, ") >= srtlen(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_843+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_843+currStrOff, "))", strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_843;
}
else if ((strcmp(t.cont, "<=") == 0)) {
char * ____BAH_COMPILER_VAR_844 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen("))");
unsigned int strLen_2 = strlen(") <= srtlen(");
unsigned int strLen_3 = strlen(pt.cont);
unsigned int strLen_4 = strlen("(strlen(");
;                            
            ____BAH_COMPILER_VAR_844 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_844+currStrOff, "(strlen(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_844+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_844+currStrOff, ") <= srtlen(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_844+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_844+currStrOff, "))", strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_844;
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
struct varCheck ____BAH_COMPILER_VAR_845 = {};
____BAH_COMPILER_VAR_845.v= null;
____BAH_COMPILER_VAR_845.v = ptV;
____BAH_COMPILER_VAR_845.checkNull = ntIsNull;

    {
        unsigned long nLength = len(currChecks);
        if (nLength >= currChecks->length) {
            if (nLength >= currChecks->realLength) {
                if (currChecks->realLength != 0) {
                    currChecks->realLength *= 2;
                } else {
                    currChecks->realLength = 50;
                }
                void * newPtr = memoryRealloc(currChecks->data, (currChecks->realLength)*sizeof(struct varCheck));
                currChecks->data = newPtr;
            }
            currChecks->data[len(currChecks)] = ____BAH_COMPILER_VAR_845;
            currChecks->length = nLength+1;
        } else {
            currChecks->data[len(currChecks)] = ____BAH_COMPILER_VAR_845;
        }
    }
    ;
}
else if ((strcmp(t.cont, "!=") == 0)) {
struct varCheck ____BAH_COMPILER_VAR_846 = {};
____BAH_COMPILER_VAR_846.v= null;
____BAH_COMPILER_VAR_846.v = ptV;
____BAH_COMPILER_VAR_846.checkNull = (ntIsNull==false);

    {
        unsigned long nLength = len(currChecks);
        if (nLength >= currChecks->length) {
            if (nLength >= currChecks->realLength) {
                if (currChecks->realLength != 0) {
                    currChecks->realLength *= 2;
                } else {
                    currChecks->realLength = 50;
                }
                void * newPtr = memoryRealloc(currChecks->data, (currChecks->realLength)*sizeof(struct varCheck));
                currChecks->data = newPtr;
            }
            currChecks->data[len(currChecks)] = ____BAH_COMPILER_VAR_846;
            currChecks->length = nLength+1;
        } else {
            currChecks->data[len(currChecks)] = ____BAH_COMPILER_VAR_846;
        }
    }
    ;
}
}
}
char * ____BAH_COMPILER_VAR_847 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen(t.cont);
unsigned int strLen_3 = strlen(pt.cont);
unsigned int strLen_4 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_847 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_847+currStrOff, "(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_847+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_847+currStrOff, t.cont, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_847+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_847+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_847;
}
}
pt.isOper = true;
pt.bahType = "bool";
pt.isValue = true;

    {
        unsigned long nLength = tokPos;
        if (nLength >= l->length) {
            if (nLength >= l->realLength) {
                if (l->realLength != 0) {
                    l->realLength *= 2;
                } else {
                    l->realLength = 50;
                }
                void * newPtr = memoryRealloc(l->data, (l->realLength)*sizeof(struct Tok));
                l->data = newPtr;
            }
            l->data[tokPos] = pt;
            l->length = nLength+1;
        } else {
            l->data[tokPos] = pt;
        }
    }
    ;
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
char * ____BAH_COMPILER_VAR_848 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t.cont);
unsigned int strLen_1 = strlen(pt.cont);
unsigned int strLen_2 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_848 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_848+currStrOff, t.cont, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_848+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_848+currStrOff, pt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_848;

    {
        unsigned long nLength = tokPos;
        if (nLength >= l->length) {
            if (nLength >= l->realLength) {
                if (l->realLength != 0) {
                    l->realLength *= 2;
                } else {
                    l->realLength = 50;
                }
                void * newPtr = memoryRealloc(l->data, (l->realLength)*sizeof(struct Tok));
                l->data = newPtr;
            }
            l->data[tokPos] = pt;
            l->length = nLength+1;
        } else {
            l->data[tokPos] = pt;
        }
    }
    ;
return tokPos;
}
char * ntt = getTypeFromToken(&nt,true,elems);
if ((compTypes(ptt,ntt)==false)) {
char * ____BAH_COMPILER_VAR_849 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ptt);
unsigned int strLen_1 = strlen(".");
unsigned int strLen_2 = strlen(") as ");
unsigned int strLen_3 = strlen(ntt);
unsigned int strLen_4 = strlen("Cannot compare {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_849 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_849+currStrOff, "Cannot compare {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_849+currStrOff, ntt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_849+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_849+currStrOff, ptt, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_849+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&nt,____BAH_COMPILER_VAR_849);
}
if ((strcmp(ptt, "cpstring") == 0)) {
char * lens = "";
char * totStrLen = "1+strLen_0+strLen_1";
struct rope* cats = rope("");
char * rstr = registerRCPvar("cpstring","null",elems);
if ((pt.isFunc==true)) {
pt.cont = registerRCPvar("cpstring",pt.cont,elems);
}
char * ____BAH_COMPILER_VAR_850 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(pt.cont);
unsigned int strLen_1 = strlen(");\n");
unsigned int strLen_2 = strlen("unsigned int strLen_0 = strlen(");
;                            
            ____BAH_COMPILER_VAR_850 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_850+currStrOff, "unsigned int strLen_0 = strlen(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_850+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_850+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_851 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(lens);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_850);
;                            
            ____BAH_COMPILER_VAR_851 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_851+currStrOff, lens, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_851+currStrOff, ____BAH_COMPILER_VAR_850, strLen_1);
            currStrOff += strLen_1;
        
        }lens = ____BAH_COMPILER_VAR_851;
char * ____BAH_COMPILER_VAR_852 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(pt.cont);
unsigned int strLen_1 = strlen(", strLen_0);\n            currStrOff += strLen_0;\n        ");
unsigned int strLen_2 = strlen("+currStrOff, ");
unsigned int strLen_3 = strlen(rstr);
unsigned int strLen_4 = strlen("\n            memcpy(");
;                            
            ____BAH_COMPILER_VAR_852 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_852+currStrOff, "\n            memcpy(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_852+currStrOff, rstr, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_852+currStrOff, "+currStrOff, ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_852+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_852+currStrOff, ", strLen_0);\n            currStrOff += strLen_0;\n        ", strLen_1);
            currStrOff += strLen_1;
        
        }cats = rope__add(cats, rope(____BAH_COMPILER_VAR_852));
if ((nt.isFunc==true)) {
nt.cont = registerRCPvar("cpstring",nt.cont,elems);
}
char * ____BAH_COMPILER_VAR_853 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen(");\n");
unsigned int strLen_2 = strlen("unsigned int strLen_1 = strlen(");
;                            
            ____BAH_COMPILER_VAR_853 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_853+currStrOff, "unsigned int strLen_1 = strlen(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_853+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_853+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_854 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(lens);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_853);
;                            
            ____BAH_COMPILER_VAR_854 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_854+currStrOff, lens, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_854+currStrOff, ____BAH_COMPILER_VAR_853, strLen_1);
            currStrOff += strLen_1;
        
        }lens = ____BAH_COMPILER_VAR_854;
char * ____BAH_COMPILER_VAR_855 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen(", strLen_1);\n            currStrOff += strLen_1;\n        ");
unsigned int strLen_2 = strlen("+currStrOff, ");
unsigned int strLen_3 = strlen(rstr);
unsigned int strLen_4 = strlen("\n            memcpy(");
;                            
            ____BAH_COMPILER_VAR_855 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_855+currStrOff, "\n            memcpy(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_855+currStrOff, rstr, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_855+currStrOff, "+currStrOff, ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_855+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_855+currStrOff, ", strLen_1);\n            currStrOff += strLen_1;\n        ", strLen_1);
            currStrOff += strLen_1;
        
        }cats = rope__add(cats, rope(____BAH_COMPILER_VAR_855));
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
char * ____BAH_COMPILER_VAR_856 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tt);
unsigned int strLen_1 = strlen(").");
unsigned int strLen_2 = strlen("Cannot concatenate cpstring with {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_856 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_856+currStrOff, "Cannot concatenate cpstring with {TOKEN} (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_856+currStrOff, tt, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_856+currStrOff, ").", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&currStrTk,____BAH_COMPILER_VAR_856);
}
if ((currStrTk.isFunc==true)) {
currStrTk.cont = registerRCPvar("cpstring",currStrTk.cont,elems);
}
char * is = intToStr(nb);
++nb;
char * ____BAH_COMPILER_VAR_857 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(currStrTk.cont);
unsigned int strLen_1 = strlen(");\n");
unsigned int strLen_2 = strlen(" = strlen(");
unsigned int strLen_3 = strlen(is);
unsigned int strLen_4 = strlen("unsigned int strLen_");
;                            
            ____BAH_COMPILER_VAR_857 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_857+currStrOff, "unsigned int strLen_", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_857+currStrOff, is, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_857+currStrOff, " = strlen(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_857+currStrOff, currStrTk.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_857+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_858 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(lens);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_857);
;                            
            ____BAH_COMPILER_VAR_858 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_858+currStrOff, lens, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_858+currStrOff, ____BAH_COMPILER_VAR_857, strLen_1);
            currStrOff += strLen_1;
        
        }lens = ____BAH_COMPILER_VAR_858;
char * ____BAH_COMPILER_VAR_859 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("+strLen_");
unsigned int strLen_1 = strlen(is);
;                            
            ____BAH_COMPILER_VAR_859 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_859+currStrOff, "+strLen_", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_859+currStrOff, is, strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_860 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(totStrLen);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_859);
;                            
            ____BAH_COMPILER_VAR_860 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_860+currStrOff, totStrLen, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_860+currStrOff, ____BAH_COMPILER_VAR_859, strLen_1);
            currStrOff += strLen_1;
        
        }totStrLen = ____BAH_COMPILER_VAR_860;
char * ____BAH_COMPILER_VAR_861 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(is);
unsigned int strLen_1 = strlen(";\n                    ");
unsigned int strLen_2 = strlen(");\n                    currStrOff += strLen_");
unsigned int strLen_3 = strlen(is);
unsigned int strLen_4 = strlen(", strLen_");
unsigned int strLen_5 = strlen(currStrTk.cont);
unsigned int strLen_6 = strlen("+currStrOff, ");
unsigned int strLen_7 = strlen(rstr);
unsigned int strLen_8 = strlen("\n                    memcpy(");
;                            
            ____BAH_COMPILER_VAR_861 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_861+currStrOff, "\n                    memcpy(", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_861+currStrOff, rstr, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_861+currStrOff, "+currStrOff, ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_861+currStrOff, currStrTk.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_861+currStrOff, ", strLen_", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_861+currStrOff, is, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_861+currStrOff, ");\n                    currStrOff += strLen_", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_861+currStrOff, is, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_861+currStrOff, ";\n                    ", strLen_1);
            currStrOff += strLen_1;
        
        }cats = rope__add(rope(____BAH_COMPILER_VAR_861), cats);
if ((i-1>=0)) {
--i;
t = l->data[i];
if ((strcmp(t.cont, "+") != 0)) {

        char ____BAH_COMPILER_VAR_862 = 0;
        for(int i=signs->length-1; i!=-1;i--) {
            if (signs->data[i] != 0 && strcmp(signs->data[i], t.cont) == 0) {
                ____BAH_COMPILER_VAR_862=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_862) {
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
char * ____BAH_COMPILER_VAR_863 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(totStrLen);
unsigned int strLen_1 = strlen(");\n            ");
unsigned int strLen_2 = strlen(" = memoryAllocSTR(");
unsigned int strLen_3 = strlen(rstr);
unsigned int strLen_4 = strlen(";                            \n            ");
unsigned int strLen_5 = strlen(lens);
unsigned int strLen_6 = strlen("\n        {\n            unsigned int currStrOff = 0;\n            ");
;                            
            ____BAH_COMPILER_VAR_863 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_863+currStrOff, "\n        {\n            unsigned int currStrOff = 0;\n            ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_863+currStrOff, lens, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_863+currStrOff, ";                            \n            ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_863+currStrOff, rstr, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_863+currStrOff, " = memoryAllocSTR(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_863+currStrOff, totStrLen, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_863+currStrOff, ");\n            ", strLen_1);
            currStrOff += strLen_1;
        
        }struct rope* res = rope__add(rope(____BAH_COMPILER_VAR_863), rope__add(cats, rope("\n        }")));
if (isGlobal()) {
INIT = rope__add(INIT, res);
}
else {
OUTPUT = rope__add(OUTPUT, res);
}
pt.type = TOKEN_TYPE_VAR;
pt.isValue = true;
pt.cont = rstr;
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
char * ____BAH_COMPILER_VAR_864 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ptt);
unsigned int strLen_1 = strlen(").");
unsigned int strLen_2 = strlen("Undefined operation on struct {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_864 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_864+currStrOff, "Undefined operation on struct {TOKEN} (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_864+currStrOff, ptt, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_864+currStrOff, ").", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&pt,____BAH_COMPILER_VAR_864);
}
struct structMemb* methd = searchStructMemb(mName,s,elems);
if ((methd!=null)&&(methd->isFn==true)) {
if (RCPavailable()) {
char * ____BAH_COMPILER_VAR_865 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen(", ");
unsigned int strLen_3 = strlen(pt.cont);
unsigned int strLen_4 = strlen(amp);
unsigned int strLen_5 = strlen("(");
unsigned int strLen_6 = strlen(mName);
unsigned int strLen_7 = strlen("__");
unsigned int strLen_8 = strlen(s->name);
;                            
            ____BAH_COMPILER_VAR_865 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_865+currStrOff, s->name, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_865+currStrOff, "__", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_865+currStrOff, mName, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_865+currStrOff, "(", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_865+currStrOff, amp, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_865+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_865+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_865+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_865+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = registerRCPvar(ptt,____BAH_COMPILER_VAR_865,elems);
pt.type = TOKEN_TYPE_VAR;
pt.isFunc = false;
pt.isOper = false;
}
else {
char * ____BAH_COMPILER_VAR_866 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen(", ");
unsigned int strLen_3 = strlen(pt.cont);
unsigned int strLen_4 = strlen(amp);
unsigned int strLen_5 = strlen("(");
unsigned int strLen_6 = strlen(mName);
unsigned int strLen_7 = strlen("__");
unsigned int strLen_8 = strlen(s->name);
;                            
            ____BAH_COMPILER_VAR_866 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_866+currStrOff, s->name, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_866+currStrOff, "__", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_866+currStrOff, mName, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_866+currStrOff, "(", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_866+currStrOff, amp, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_866+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_866+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_866+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_866+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_866;
pt.isFunc = true;
}
}
}
else {
char * ____BAH_COMPILER_VAR_867 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t.cont);
unsigned int strLen_1 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_867 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_867+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_867+currStrOff, nt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_868 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(pt.cont);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_867);
;                            
            ____BAH_COMPILER_VAR_868 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_868+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_868+currStrOff, ____BAH_COMPILER_VAR_867, strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_868;
}
pt.isOper = true;
}

    {
        unsigned long nLength = tokPos;
        if (nLength >= l->length) {
            if (nLength >= l->realLength) {
                if (l->realLength != 0) {
                    l->realLength *= 2;
                } else {
                    l->realLength = 50;
                }
                void * newPtr = memoryRealloc(l->data, (l->realLength)*sizeof(struct Tok));
                l->data = newPtr;
            }
            l->data[tokPos] = pt;
            l->length = nLength+1;
        } else {
            l->data[tokPos] = pt;
        }
    }
    ;
return tokPos;
};
long int valueSendChan(__BAH_ARR_TYPE_Tok l,long int i,struct Elems* elems){
long int posTok = i-2;
struct Tok nt = l->data[posTok];
struct Tok pt = l->data[posTok+2];
deleteRange(l,posTok,posTok+2);
char * ntt = getTypeFromToken(&nt,true,elems);
char * ____BAH_COMPILER_VAR_869 =getTypeFromToken(&pt,true,elems);struct string ptt = string(____BAH_COMPILER_VAR_869);
if ((string__hasPrefix(&ptt,"chan:")==0)) {
char * ____BAH_COMPILER_VAR_870 =null;char * ____BAH_COMPILER_VAR_871 =string__str(&ptt);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_871);
unsigned int strLen_1 = strlen(") as chan.");
unsigned int strLen_2 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_870 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_870+currStrOff, "Cannot use {TOKEN} (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_870+currStrOff, ____BAH_COMPILER_VAR_871, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_870+currStrOff, ") as chan.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&pt,____BAH_COMPILER_VAR_870);
}
string__trimLeft(&ptt,5);
if (isGlobal()) {
throwErr(&pt,"Cannot send to channel {TOKEN} of a function.");
}
char * ____BAH_COMPILER_VAR_872 =string__str(&ptt);if ((compTypes(ntt,____BAH_COMPILER_VAR_872)==false)) {
char * ____BAH_COMPILER_VAR_873 =null;char * ____BAH_COMPILER_VAR_874 =string__str(&ptt);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_874);
unsigned int strLen_1 = strlen(".");
unsigned int strLen_2 = strlen(") through chan:");
unsigned int strLen_3 = strlen(ntt);
unsigned int strLen_4 = strlen("Cannot send {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_873 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_873+currStrOff, "Cannot send {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_873+currStrOff, ntt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_873+currStrOff, ") through chan:", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_873+currStrOff, ____BAH_COMPILER_VAR_874, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_873+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&nt,____BAH_COMPILER_VAR_873);
}
char * ____BAH_COMPILER_VAR_875 =string__str(&ptt);if (isRCPpointerType(____BAH_COMPILER_VAR_875)) {
char * ____BAH_COMPILER_VAR_876 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen(");\n");
unsigned int strLen_2 = strlen(", ");
unsigned int strLen_3 = strlen(pt.cont);
unsigned int strLen_4 = strlen("channel__send(");
;                            
            ____BAH_COMPILER_VAR_876 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_876+currStrOff, "channel__send(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_876+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_876+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_876+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_876+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_876));
}
else {
struct string ct = getCType(ntt,elems);
char * tmpV = genCompilerVar();
char * ____BAH_COMPILER_VAR_877 =null;char * ____BAH_COMPILER_VAR_878 =string__str(&ct);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpV);
unsigned int strLen_1 = strlen("));\n        ");
unsigned int strLen_2 = strlen(", sizeof(");
unsigned int strLen_3 = strlen(tmpV);
unsigned int strLen_4 = strlen(", &");
unsigned int strLen_5 = strlen(pt.cont);
unsigned int strLen_6 = strlen(";\n        channel__sendAny(");
unsigned int strLen_7 = strlen(nt.cont);
unsigned int strLen_8 = strlen(" = ");
unsigned int strLen_9 = strlen(tmpV);
unsigned int strLen_10 = strlen(" ");
unsigned int strLen_11 = strlen(____BAH_COMPILER_VAR_878);
unsigned int strLen_12 = strlen("\n        ");
;                            
            ____BAH_COMPILER_VAR_877 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12);
            
                    memcpy(____BAH_COMPILER_VAR_877+currStrOff, "\n        ", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_877+currStrOff, ____BAH_COMPILER_VAR_878, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_877+currStrOff, " ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_877+currStrOff, tmpV, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_877+currStrOff, " = ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_877+currStrOff, nt.cont, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_877+currStrOff, ";\n        channel__sendAny(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_877+currStrOff, pt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_877+currStrOff, ", &", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_877+currStrOff, tmpV, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_877+currStrOff, ", sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_877+currStrOff, tmpV, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_877+currStrOff, "));\n        ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_877));
}
return posTok;
};
long int valueChan(__BAH_ARR_TYPE_Tok l,long int i,struct Elems* elems){
long int posTok = i-1;
delete(l,posTok);
struct Tok nt = l->data[posTok];
char * ____BAH_COMPILER_VAR_879 =getTypeFromToken(&nt,true,elems);struct string ntt = string(____BAH_COMPILER_VAR_879);
if ((string__hasPrefix(&ntt,"chan:")==0)) {
char * ____BAH_COMPILER_VAR_880 =null;char * ____BAH_COMPILER_VAR_881 =string__str(&ntt);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_881);
unsigned int strLen_1 = strlen(") as chan.");
unsigned int strLen_2 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_880 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_880+currStrOff, "Cannot use {TOKEN} (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_880+currStrOff, ____BAH_COMPILER_VAR_881, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_880+currStrOff, ") as chan.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&nt,____BAH_COMPILER_VAR_880);
}
string__trimLeft(&ntt,5);
if (isGlobal()) {
throwErr(&nt,"Cannot receive from chan {TOKEN} outside a function body.");
}
char * ____BAH_COMPILER_VAR_882 =string__str(&ntt);struct string ct = getCType(____BAH_COMPILER_VAR_882,elems);
char * ____BAH_COMPILER_VAR_883 =string__str(&ntt);if (isRCPpointerType(____BAH_COMPILER_VAR_883)) {
char * ____BAH_COMPILER_VAR_884 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen("channel__receive(");
;                            
            ____BAH_COMPILER_VAR_884 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_884+currStrOff, "channel__receive(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_884+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_884+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_885 =string__str(&ntt);char * tmpV = registerRCPvar(____BAH_COMPILER_VAR_885,____BAH_COMPILER_VAR_884,elems);
nt.cont = tmpV;
}
else {
if (RCPavailable()) {
char * ____BAH_COMPILER_VAR_886 =null;char * ____BAH_COMPILER_VAR_887 =string__str(&ntt);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_887);
unsigned int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_886 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_886+currStrOff, ____BAH_COMPILER_VAR_887, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_886+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_888 =null;char * ____BAH_COMPILER_VAR_889 =string__str(&ct);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen("*)channel__receive(");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_889);
unsigned int strLen_4 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_888 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_888+currStrOff, "(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_888+currStrOff, ____BAH_COMPILER_VAR_889, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_888+currStrOff, "*)channel__receive(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_888+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_888+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }char * tmpV = registerRCPvar(____BAH_COMPILER_VAR_886,____BAH_COMPILER_VAR_888,elems);
char * ____BAH_COMPILER_VAR_890 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("*");
unsigned int strLen_1 = strlen(tmpV);
;                            
            ____BAH_COMPILER_VAR_890 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_890+currStrOff, "*", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_890+currStrOff, tmpV, strLen_1);
            currStrOff += strLen_1;
        
        }nt.cont = ____BAH_COMPILER_VAR_890;
}
else {
char * ____BAH_COMPILER_VAR_891 =null;char * ____BAH_COMPILER_VAR_892 =string__str(&ct);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen("*)channel__receive(");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_892);
unsigned int strLen_4 = strlen("*(");
;                            
            ____BAH_COMPILER_VAR_891 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_891+currStrOff, "*(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_891+currStrOff, ____BAH_COMPILER_VAR_892, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_891+currStrOff, "*)channel__receive(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_891+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_891+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }nt.cont = ____BAH_COMPILER_VAR_891;
}
}
nt.type = TOKEN_TYPE_FUNC;
nt.isFunc = true;
nt.isValue = true;
nt.bahType = string__str(&ntt);

    {
        unsigned long nLength = posTok;
        if (nLength >= l->length) {
            if (nLength >= l->realLength) {
                if (l->realLength != 0) {
                    l->realLength *= 2;
                } else {
                    l->realLength = 50;
                }
                void * newPtr = memoryRealloc(l->data, (l->realLength)*sizeof(struct Tok));
                l->data = newPtr;
            }
            l->data[posTok] = nt;
            l->length = nLength+1;
        } else {
            l->data[posTok] = nt;
        }
    }
    ;
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
if ((nt.line!=t.line)) {
break;
}
}

    {
        unsigned long nLength = len(fl);
        if (nLength >= fl->length) {
            if (nLength >= fl->realLength) {
                if (fl->realLength != 0) {
                    fl->realLength *= 2;
                } else {
                    fl->realLength = 50;
                }
                void * newPtr = memoryRealloc(fl->data, (fl->realLength)*sizeof(struct Tok));
                fl->data = newPtr;
            }
            fl->data[len(fl)] = t;
            fl->length = nLength+1;
        } else {
            fl->data[len(fl)] = t;
        }
    }
    ;
++i;
};
sepI = i;
}
else {
fl = line;
}
struct Tok ____BAH_COMPILER_VAR_893 = {};
____BAH_COMPILER_VAR_893.cont = "";
____BAH_COMPILER_VAR_893.ogCont = "";
____BAH_COMPILER_VAR_893.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_893.pos = 0;
____BAH_COMPILER_VAR_893.line = 1;
____BAH_COMPILER_VAR_893.begLine = 1;
____BAH_COMPILER_VAR_893.bahType = "";
____BAH_COMPILER_VAR_893.isValue = false;
____BAH_COMPILER_VAR_893.isFunc = false;
____BAH_COMPILER_VAR_893.isOper = false;
____BAH_COMPILER_VAR_893.isEqual = false;
____BAH_COMPILER_VAR_893.pass = false;
____BAH_COMPILER_VAR_893.bahRef= null;
____BAH_COMPILER_VAR_893.parent= null;
#define pt ____BAH_COMPILER_VAR_893
long int l = len(fl);
i = 0;
for (; (i<len(fl)); ++i) {
struct Tok t = fl->data[i];
if ((t.type==TOKEN_TYPE_VAR)&&(t.isOper==false)&&(t.cont[0]==38)) {
struct string tc = string(t.cont);
string__trimLeft(&tc,1);
char * ____BAH_COMPILER_VAR_894 =string__str(&tc);struct variable* rv = getRealVar(____BAH_COMPILER_VAR_894,elems);
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
struct Tok ____BAH_COMPILER_VAR_895 = {};
____BAH_COMPILER_VAR_895.cont = "";
____BAH_COMPILER_VAR_895.ogCont = "";
____BAH_COMPILER_VAR_895.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_895.pos = 0;
____BAH_COMPILER_VAR_895.line = 1;
____BAH_COMPILER_VAR_895.begLine = 1;
____BAH_COMPILER_VAR_895.bahType = "";
____BAH_COMPILER_VAR_895.isValue = false;
____BAH_COMPILER_VAR_895.isFunc = false;
____BAH_COMPILER_VAR_895.isOper = false;
____BAH_COMPILER_VAR_895.isEqual = false;
____BAH_COMPILER_VAR_895.pass = false;
____BAH_COMPILER_VAR_895.bahRef= null;
____BAH_COMPILER_VAR_895.parent= null;
pt = ____BAH_COMPILER_VAR_895;
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
char * ____BAH_COMPILER_VAR_896 =string__str(&ptc);struct string cType = getCType(____BAH_COMPILER_VAR_896,elems);
char * ____BAH_COMPILER_VAR_897 =null;char * ____BAH_COMPILER_VAR_898 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(")");
unsigned int strLen_1 = strlen(t.cont);
unsigned int strLen_2 = strlen(____BAH_COMPILER_VAR_898);
unsigned int strLen_3 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_897 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_897+currStrOff, "(", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_897+currStrOff, ____BAH_COMPILER_VAR_898, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_897+currStrOff, ")", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_897+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_897;

    {
        unsigned long nLength = i-1;
        if (nLength >= fl->length) {
            if (nLength >= fl->realLength) {
                if (fl->realLength != 0) {
                    fl->realLength *= 2;
                } else {
                    fl->realLength = 50;
                }
                void * newPtr = memoryRealloc(fl->data, (fl->realLength)*sizeof(struct Tok));
                fl->data = newPtr;
            }
            fl->data[i-1] = t;
            fl->length = nLength+1;
        } else {
            fl->data[i-1] = t;
        }
    }
    ;
i = i-2;
}
else if (inArrayStr(pt.cont,signs)) {
if ((strcmp(t.cont, pt.cont) == 0)&&(i>1)) {
struct Tok ppt = fl->data[i-2];
if ((ppt.type==TOKEN_TYPE_VAR)) {
long int posTok = i-2;
deleteRange(fl,i-1,i);
char * ____BAH_COMPILER_VAR_899 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t.cont);
unsigned int strLen_1 = strlen(ppt.cont);
unsigned int strLen_2 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_899 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_899+currStrOff, t.cont, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_899+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_899+currStrOff, ppt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }ppt.cont = ____BAH_COMPILER_VAR_899;
ppt.isValue = true;
ppt.isOper = true;

    {
        unsigned long nLength = posTok;
        if (nLength >= fl->length) {
            if (nLength >= fl->realLength) {
                if (fl->realLength != 0) {
                    fl->realLength *= 2;
                } else {
                    fl->realLength = 50;
                }
                void * newPtr = memoryRealloc(fl->data, (fl->realLength)*sizeof(struct Tok));
                fl->data = newPtr;
            }
            fl->data[posTok] = ppt;
            fl->length = nLength+1;
        } else {
            fl->data[posTok] = ppt;
        }
    }
    ;
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
char * ____BAH_COMPILER_VAR_900 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(pt.cont);
unsigned int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_900 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_900+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_900+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_900;

    {
        unsigned long nLength = i-1;
        if (nLength >= fl->length) {
            if (nLength >= fl->realLength) {
                if (fl->realLength != 0) {
                    fl->realLength *= 2;
                } else {
                    fl->realLength = 50;
                }
                void * newPtr = memoryRealloc(fl->data, (fl->realLength)*sizeof(struct Tok));
                fl->data = newPtr;
            }
            fl->data[i-1] = pt;
            fl->length = nLength+1;
        } else {
            fl->data[i-1] = pt;
        }
    }
    ;
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
char * ____BAH_COMPILER_VAR_901 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ptt);
unsigned int strLen_1 = strlen(".");
unsigned int strLen_2 = strlen("Cannot use {TOKEN} on ");
;                            
            ____BAH_COMPILER_VAR_901 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_901+currStrOff, "Cannot use {TOKEN} on ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_901+currStrOff, ptt, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_901+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&t,____BAH_COMPILER_VAR_901);
}
char * ____BAH_COMPILER_VAR_902 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t.cont);
unsigned int strLen_1 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_902 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_902+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_902+currStrOff, nt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_903 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(pt.cont);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_902);
;                            
            ____BAH_COMPILER_VAR_903 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_903+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_903+currStrOff, ____BAH_COMPILER_VAR_902, strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_903;

    {
        unsigned long nLength = i-1;
        if (nLength >= fl->length) {
            if (nLength >= fl->realLength) {
                if (fl->realLength != 0) {
                    fl->realLength *= 2;
                } else {
                    fl->realLength = 50;
                }
                void * newPtr = memoryRealloc(fl->data, (fl->realLength)*sizeof(struct Tok));
                fl->data = newPtr;
            }
            fl->data[i-1] = pt;
            fl->length = nLength+1;
        } else {
            fl->data[i-1] = pt;
        }
    }
    ;
deleteRange(fl,i,i+1);
i = i-2;
}
else if ((t.type==TOKEN_TYPE_VAR)&&(strcmp(t.bahType, "") != 0)) {
if ((t.cont[0]==38)) {
char * ____BAH_COMPILER_VAR_904 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t.bahType);
unsigned int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_904 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_904+currStrOff, t.bahType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_904+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }t.bahType = ____BAH_COMPILER_VAR_904;

    {
        unsigned long nLength = i;
        if (nLength >= fl->length) {
            if (nLength >= fl->realLength) {
                if (fl->realLength != 0) {
                    fl->realLength *= 2;
                } else {
                    fl->realLength = 50;
                }
                void * newPtr = memoryRealloc(fl->data, (fl->realLength)*sizeof(struct Tok));
                fl->data = newPtr;
            }
            fl->data[i] = t;
            fl->length = nLength+1;
        } else {
            fl->data[i] = t;
        }
    }
    ;
}
else if ((t.cont[0]==42)) {
struct string tt = string(t.bahType);
string__replace(&tt,"*","");
t.bahType = string__str(&tt);

    {
        unsigned long nLength = i;
        if (nLength >= fl->length) {
            if (nLength >= fl->realLength) {
                if (fl->realLength != 0) {
                    fl->realLength *= 2;
                } else {
                    fl->realLength = 50;
                }
                void * newPtr = memoryRealloc(fl->data, (fl->realLength)*sizeof(struct Tok));
                fl->data = newPtr;
            }
            fl->data[i] = t;
            fl->length = nLength+1;
        } else {
            fl->data[i] = t;
        }
    }
    ;
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
        unsigned long nLength = len(fl);
        if (nLength >= fl->length) {
            if (nLength >= fl->realLength) {
                if (fl->realLength != 0) {
                    fl->realLength *= 2;
                } else {
                    fl->realLength = 50;
                }
                void * newPtr = memoryRealloc(fl->data, (fl->realLength)*sizeof(struct Tok));
                fl->data = newPtr;
            }
            fl->data[len(fl)] = line->data[sepI];
            fl->length = nLength+1;
        } else {
            fl->data[len(fl)] = line->data[sepI];
        }
    }
    ;
++sepI;
};
}
return fl;

#undef pt
};
void parseFnDeclare(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
long int i = 0;
struct func* ____BAH_COMPILER_VAR_905 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_905->name = "";
____BAH_COMPILER_VAR_905->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_905->args->length = 0;
            ____BAH_COMPILER_VAR_905->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_905->returns= null;
____BAH_COMPILER_VAR_905->isBinding = false;
____BAH_COMPILER_VAR_905->from = "";
____BAH_COMPILER_VAR_905->file = "";
____BAH_COMPILER_VAR_905->line = 1;
____BAH_COMPILER_VAR_905->isVar = false;
____BAH_COMPILER_VAR_905->used = false;
____BAH_COMPILER_VAR_905->code = null;
____BAH_COMPILER_VAR_905->isMut = false;
____BAH_COMPILER_VAR_905->isImported = false;
____BAH_COMPILER_VAR_905->exits = false;
struct func* fn = ____BAH_COMPILER_VAR_905;
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
char * ____BAH_COMPILER_VAR_906 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(lineStr);
unsigned int strLen_1 = strlen(".");
unsigned int strLen_2 = strlen(":");
unsigned int strLen_3 = strlen(ogFn->file);
unsigned int strLen_4 = strlen("Cannot redeclare function {TOKEN}, previous declaration: ");
;                            
            ____BAH_COMPILER_VAR_906 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_906+currStrOff, "Cannot redeclare function {TOKEN}, previous declaration: ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_906+currStrOff, ogFn->file, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_906+currStrOff, ":", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_906+currStrOff, lineStr, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_906+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&ft,____BAH_COMPILER_VAR_906);
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
struct debugFunction* ____BAH_COMPILER_VAR_907 = memoryAlloc(sizeof(struct debugFunction));
____BAH_COMPILER_VAR_907->name= null;
____BAH_COMPILER_VAR_907->returns= null;
____BAH_COMPILER_VAR_907->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_907->args->length = 0;
            ____BAH_COMPILER_VAR_907->args->elemSize = sizeof(struct variable*);
            struct debugFunction* df = ____BAH_COMPILER_VAR_907;
df->name = fn->name;
df->args = fn->args;
df->returns = fn->returns->type;
struct debugFunction* ____BAH_COMPILER_VAR_908 = df;
char ** ____BAH_COMPILER_VAR_910 = (char **)((char*)(____BAH_COMPILER_VAR_908) + offsetof(struct debugFunction, name));
struct reflectElement ____BAH_COMPILER_VAR_911 = __reflect(____BAH_COMPILER_VAR_910, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct debugFunction, name));
char ** ____BAH_COMPILER_VAR_912 = (char **)((char*)(____BAH_COMPILER_VAR_908) + offsetof(struct debugFunction, returns));
struct reflectElement ____BAH_COMPILER_VAR_913 = __reflect(____BAH_COMPILER_VAR_912, sizeof(char *), "cpstring", "returns", 0, 0, 0, 0, offsetof(struct debugFunction, returns));
array(struct variable*)** ____BAH_COMPILER_VAR_914 = (array(struct variable*)**)((char*)(____BAH_COMPILER_VAR_908) + offsetof(struct debugFunction, args));
struct variable** ____BAH_COMPILER_VAR_915 = 0;
char ** ____BAH_COMPILER_VAR_917 = (char **)((char*)(____BAH_COMPILER_VAR_915) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_918 = __reflect(____BAH_COMPILER_VAR_917, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_919 = (char **)((char*)(____BAH_COMPILER_VAR_915) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_920 = __reflect(____BAH_COMPILER_VAR_919, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_921 = (char*)((char*)(____BAH_COMPILER_VAR_915) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_922 = __reflect(____BAH_COMPILER_VAR_921, sizeof(char), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_923 = (char **)((char*)(____BAH_COMPILER_VAR_915) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_924 = __reflect(____BAH_COMPILER_VAR_923, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_925 = (char*)((char*)(____BAH_COMPILER_VAR_915) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_926 = __reflect(____BAH_COMPILER_VAR_925, sizeof(char), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_927 = (char **)((char*)(____BAH_COMPILER_VAR_915) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_928 = __reflect(____BAH_COMPILER_VAR_927, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
void ** ____BAH_COMPILER_VAR_929 = (void **)((char*)(____BAH_COMPILER_VAR_915) + offsetof(struct variable, declScope));
struct reflectElement ____BAH_COMPILER_VAR_930 = __reflect(____BAH_COMPILER_VAR_929, sizeof(void *), "ptr", "declScope", 0, 0, 0, 0, offsetof(struct variable, declScope));
char* ____BAH_COMPILER_VAR_931 = (char*)((char*)(____BAH_COMPILER_VAR_915) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_932 = __reflect(____BAH_COMPILER_VAR_931, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));
struct rope** ____BAH_COMPILER_VAR_933 = (struct rope**)((char*)(____BAH_COMPILER_VAR_915) + offsetof(struct variable, declRope));
void ** ____BAH_COMPILER_VAR_935 = (void **)((char*)(____BAH_COMPILER_VAR_933) + offsetof(struct rope, left));
struct reflectElement ____BAH_COMPILER_VAR_936 = __reflect(____BAH_COMPILER_VAR_935, sizeof(void *), "ptr", "left", 0, 0, 0, 0, offsetof(struct rope, left));
void ** ____BAH_COMPILER_VAR_937 = (void **)((char*)(____BAH_COMPILER_VAR_933) + offsetof(struct rope, right));
struct reflectElement ____BAH_COMPILER_VAR_938 = __reflect(____BAH_COMPILER_VAR_937, sizeof(void *), "ptr", "right", 0, 0, 0, 0, offsetof(struct rope, right));
char ** ____BAH_COMPILER_VAR_939 = (char **)((char*)(____BAH_COMPILER_VAR_933) + offsetof(struct rope, str));
struct reflectElement ____BAH_COMPILER_VAR_940 = __reflect(____BAH_COMPILER_VAR_939, sizeof(char *), "cpstring", "str", 0, 0, 0, 0, offsetof(struct rope, str));
int* ____BAH_COMPILER_VAR_941 = (int*)((char*)(____BAH_COMPILER_VAR_933) + offsetof(struct rope, lCount));
struct reflectElement ____BAH_COMPILER_VAR_942 = __reflect(____BAH_COMPILER_VAR_941, sizeof(int), "int32", "lCount", 0, 0, 0, 0, offsetof(struct rope, lCount));
int* ____BAH_COMPILER_VAR_943 = (int*)((char*)(____BAH_COMPILER_VAR_933) + offsetof(struct rope, len));
struct reflectElement ____BAH_COMPILER_VAR_944 = __reflect(____BAH_COMPILER_VAR_943, sizeof(int), "int32", "len", 0, 0, 0, 0, offsetof(struct rope, len));
int* ____BAH_COMPILER_VAR_945 = (int*)((char*)(____BAH_COMPILER_VAR_933) + offsetof(struct rope, totalLen));
struct reflectElement ____BAH_COMPILER_VAR_946 = __reflect(____BAH_COMPILER_VAR_945, sizeof(int), "int32", "totalLen", 0, 0, 0, 0, offsetof(struct rope, totalLen));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_934 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_934->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_934->length = 6;
        ____BAH_COMPILER_VAR_934->data = memoryAlloc(____BAH_COMPILER_VAR_934->length * ____BAH_COMPILER_VAR_934->elemSize);
        ____BAH_COMPILER_VAR_934->data[0] = ____BAH_COMPILER_VAR_936;
____BAH_COMPILER_VAR_934->data[1] = ____BAH_COMPILER_VAR_938;
____BAH_COMPILER_VAR_934->data[2] = ____BAH_COMPILER_VAR_940;
____BAH_COMPILER_VAR_934->data[3] = ____BAH_COMPILER_VAR_942;
____BAH_COMPILER_VAR_934->data[4] = ____BAH_COMPILER_VAR_944;
____BAH_COMPILER_VAR_934->data[5] = ____BAH_COMPILER_VAR_946;
struct reflectElement ____BAH_COMPILER_VAR_947 = __reflect(____BAH_COMPILER_VAR_933, sizeof(struct rope), "rope*", "declRope", 0, 0, 1, ____BAH_COMPILER_VAR_934, offsetof(struct variable, declRope));
char* ____BAH_COMPILER_VAR_948 = (char*)((char*)(____BAH_COMPILER_VAR_915) + offsetof(struct variable, canBeNull));
struct reflectElement ____BAH_COMPILER_VAR_949 = __reflect(____BAH_COMPILER_VAR_948, sizeof(char), "bool", "canBeNull", 0, 0, 0, 0, offsetof(struct variable, canBeNull));
char* ____BAH_COMPILER_VAR_950 = (char*)((char*)(____BAH_COMPILER_VAR_915) + offsetof(struct variable, canBeReg));
struct reflectElement ____BAH_COMPILER_VAR_951 = __reflect(____BAH_COMPILER_VAR_950, sizeof(char), "bool", "canBeReg", 0, 0, 0, 0, offsetof(struct variable, canBeReg));
char* ____BAH_COMPILER_VAR_952 = (char*)((char*)(____BAH_COMPILER_VAR_915) + offsetof(struct variable, isReg));
struct reflectElement ____BAH_COMPILER_VAR_953 = __reflect(____BAH_COMPILER_VAR_952, sizeof(char), "bool", "isReg", 0, 0, 0, 0, offsetof(struct variable, isReg));
void ** ____BAH_COMPILER_VAR_954 = (void **)((char*)(____BAH_COMPILER_VAR_915) + offsetof(struct variable, lastSet));
struct reflectElement ____BAH_COMPILER_VAR_955 = __reflect(____BAH_COMPILER_VAR_954, sizeof(void *), "ptr", "lastSet", 0, 0, 0, 0, offsetof(struct variable, lastSet));
char* ____BAH_COMPILER_VAR_956 = (char*)((char*)(____BAH_COMPILER_VAR_915) + offsetof(struct variable, isArg));
struct reflectElement ____BAH_COMPILER_VAR_957 = __reflect(____BAH_COMPILER_VAR_956, sizeof(char), "bool", "isArg", 0, 0, 0, 0, offsetof(struct variable, isArg));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_916 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_916->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_916->length = 14;
        ____BAH_COMPILER_VAR_916->data = memoryAlloc(____BAH_COMPILER_VAR_916->length * ____BAH_COMPILER_VAR_916->elemSize);
        ____BAH_COMPILER_VAR_916->data[0] = ____BAH_COMPILER_VAR_918;
____BAH_COMPILER_VAR_916->data[1] = ____BAH_COMPILER_VAR_920;
____BAH_COMPILER_VAR_916->data[2] = ____BAH_COMPILER_VAR_922;
____BAH_COMPILER_VAR_916->data[3] = ____BAH_COMPILER_VAR_924;
____BAH_COMPILER_VAR_916->data[4] = ____BAH_COMPILER_VAR_926;
____BAH_COMPILER_VAR_916->data[5] = ____BAH_COMPILER_VAR_928;
____BAH_COMPILER_VAR_916->data[6] = ____BAH_COMPILER_VAR_930;
____BAH_COMPILER_VAR_916->data[7] = ____BAH_COMPILER_VAR_932;
____BAH_COMPILER_VAR_916->data[8] = ____BAH_COMPILER_VAR_947;
____BAH_COMPILER_VAR_916->data[9] = ____BAH_COMPILER_VAR_949;
____BAH_COMPILER_VAR_916->data[10] = ____BAH_COMPILER_VAR_951;
____BAH_COMPILER_VAR_916->data[11] = ____BAH_COMPILER_VAR_953;
____BAH_COMPILER_VAR_916->data[12] = ____BAH_COMPILER_VAR_955;
____BAH_COMPILER_VAR_916->data[13] = ____BAH_COMPILER_VAR_957;
struct reflectElement ____BAH_COMPILER_VAR_958 = __reflect(____BAH_COMPILER_VAR_915, sizeof(struct variable), "variable*", "", 0, 0, 1, ____BAH_COMPILER_VAR_916, 0);

        struct reflectElement ____BAH_COMPILER_VAR_959 = ____BAH_COMPILER_VAR_958;
        struct reflectElement ____BAH_COMPILER_VAR_960 = __reflect(____BAH_COMPILER_VAR_914, sizeof(array(struct variable*)*), "[]variable*", "args", 1, &____BAH_COMPILER_VAR_959, 0, 0, offsetof(struct debugFunction, args));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_909 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_909->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_909->length = 3;
        ____BAH_COMPILER_VAR_909->data = memoryAlloc(____BAH_COMPILER_VAR_909->length * ____BAH_COMPILER_VAR_909->elemSize);
        ____BAH_COMPILER_VAR_909->data[0] = ____BAH_COMPILER_VAR_911;
____BAH_COMPILER_VAR_909->data[1] = ____BAH_COMPILER_VAR_913;
____BAH_COMPILER_VAR_909->data[2] = ____BAH_COMPILER_VAR_960;
struct reflectElement ____BAH_COMPILER_VAR_961 = __reflect(____BAH_COMPILER_VAR_908, sizeof(struct debugFunction), "debugFunction*", "df", 0, 0, 1, ____BAH_COMPILER_VAR_909, 0);
debugPrint("fn_declare",ft.line,____BAH_COMPILER_VAR_961);
}
if ((shouldOnlyDecl==true)) {
if ((ogFn!=null)) {
fn->isBinding = false;
}
fn->isImported = true;

    {
        unsigned long nLength = len(elems->fns);
        if (nLength >= elems->fns->length) {
            if (nLength >= elems->fns->realLength) {
                if (elems->fns->realLength != 0) {
                    elems->fns->realLength *= 2;
                } else {
                    elems->fns->realLength = 50;
                }
                void * newPtr = memoryRealloc(elems->fns->data, (elems->fns->realLength)*sizeof(struct func*));
                elems->fns->data = newPtr;
            }
            elems->fns->data[len(elems->fns)] = fn;
            elems->fns->length = nLength+1;
        } else {
            elems->fns->data[len(elems->fns)] = fn;
        }
    }
    ;
char * ____BAH_COMPILER_VAR_962 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(";\n");
;                            
            ____BAH_COMPILER_VAR_962 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_962+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_962+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_962));
return;
}
char * ____BAH_COMPILER_VAR_963 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen("{\n");
;                            
            ____BAH_COMPILER_VAR_963 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_963+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_963+currStrOff, "{\n", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_963;
fn->code = rope(code);
struct Elems* fnElems = dupElems(elems);
array(struct variable*)* vs = fnElems->vars;
register long int j = 0;
while ((j<len(fn->args))) {
struct variable* a = fn->args->data[j];
a->declScope = elems;
a->isArg = true;

    {
        unsigned long nLength = len(vs);
        if (nLength >= vs->length) {
            if (nLength >= vs->realLength) {
                if (vs->realLength != 0) {
                    vs->realLength *= 2;
                } else {
                    vs->realLength = 50;
                }
                void * newPtr = memoryRealloc(vs->data, (vs->realLength)*sizeof(struct variable*));
                vs->data = newPtr;
            }
            vs->data[len(vs)] = a;
            vs->length = nLength+1;
        } else {
            vs->data[len(vs)] = a;
        }
    }
    ;
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
        unsigned long nLength = len(fns);
        if (nLength >= fns->length) {
            if (nLength >= fns->realLength) {
                if (fns->realLength != 0) {
                    fns->realLength *= 2;
                } else {
                    fns->realLength = 50;
                }
                void * newPtr = memoryRealloc(fns->data, (fns->realLength)*sizeof(struct func*));
                fns->data = newPtr;
            }
            fns->data[len(fns)] = fn;
            fns->length = nLength+1;
        } else {
            fns->data[len(fns)] = fn;
        }
    }
    ;
}
array(struct Tok)* tokens = memoryAlloc(sizeof(array(struct Tok)));

tokens->length = 0;
tokens->elemSize = sizeof(struct Tok);
++i;
long int max = len(l)-1;
while ((i<max)) {
struct Tok t = l->data[i];

    {
        unsigned long nLength = len(tokens);
        if (nLength >= tokens->length) {
            if (nLength >= tokens->realLength) {
                if (tokens->realLength != 0) {
                    tokens->realLength *= 2;
                } else {
                    tokens->realLength = 50;
                }
                void * newPtr = memoryRealloc(tokens->data, (tokens->realLength)*sizeof(struct Tok));
                tokens->data = newPtr;
            }
            tokens->data[len(tokens)] = t;
            tokens->length = nLength+1;
        } else {
            tokens->data[len(tokens)] = t;
        }
    }
    ;
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
char * ____BAH_COMPILER_VAR_964 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fn->name);
unsigned int strLen_1 = strlen("' is not returned.");
unsigned int strLen_2 = strlen("Function '");
;                            
            ____BAH_COMPILER_VAR_964 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_964+currStrOff, "Function '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_964+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_964+currStrOff, "' is not returned.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&l->data[len(l)-1],____BAH_COMPILER_VAR_964);
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
char * ____BAH_COMPILER_VAR_965 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(valType);
unsigned int strLen_1 = strlen(") as maybe value.");
unsigned int strLen_2 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_965 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_965+currStrOff, "Cannot use {TOKEN} (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_965+currStrOff, valType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_965+currStrOff, ") as maybe value.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&valTok,____BAH_COMPILER_VAR_965);
}
char * ____BAH_COMPILER_VAR_966 =null;char * ____BAH_COMPILER_VAR_967 =cpstringSubsitute(valType, 0, strlen(valType)-1);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_967);
unsigned int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_966 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_966+currStrOff, ____BAH_COMPILER_VAR_967, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_966+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }char * newType = ____BAH_COMPILER_VAR_966;
if ((strcmp(line->data[4].cont, "else") != 0)&&(strcmp(line->data[4].cont, "then") != 0)) {
throwErr(&line->data[4],"Expected 'then' or 'else' got {TOKEN}.");
}
if ((strcmp(line->data[4].cont, "then") == 0)) {
isThen = true;
}
struct variable* v = searchVar(varTok.cont,elems);
char * code = "";
if ((v==null)) {
struct variable* ____BAH_COMPILER_VAR_968 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_968->name = "";
____BAH_COMPILER_VAR_968->type = "";
____BAH_COMPILER_VAR_968->isConst = false;
____BAH_COMPILER_VAR_968->constVal = "";
____BAH_COMPILER_VAR_968->isArray = false;
____BAH_COMPILER_VAR_968->from = "";
____BAH_COMPILER_VAR_968->declScope= null;
____BAH_COMPILER_VAR_968->isGlobal = false;
____BAH_COMPILER_VAR_968->declRope= null;
____BAH_COMPILER_VAR_968->canBeNull = false;
____BAH_COMPILER_VAR_968->isReg = false;
____BAH_COMPILER_VAR_968->lastSet= null;
____BAH_COMPILER_VAR_968->isArg = false;
____BAH_COMPILER_VAR_968->name = varTok.cont;
____BAH_COMPILER_VAR_968->type = newType;
v = ____BAH_COMPILER_VAR_968;

    {
        unsigned long nLength = len(elems->vars);
        if (nLength >= elems->vars->length) {
            if (nLength >= elems->vars->realLength) {
                if (elems->vars->realLength != 0) {
                    elems->vars->realLength *= 2;
                } else {
                    elems->vars->realLength = 50;
                }
                void * newPtr = memoryRealloc(elems->vars->data, (elems->vars->realLength)*sizeof(struct variable*));
                elems->vars->data = newPtr;
            }
            elems->vars->data[len(elems->vars)] = v;
            elems->vars->length = nLength+1;
        } else {
            elems->vars->data[len(elems->vars)] = v;
        }
    }
    ;

                struct string ____BAH_COMPILER_VAR_969 = getCType(v->type,elems);
                char * ____BAH_COMPILER_VAR_970 =null;char * ____BAH_COMPILER_VAR_971 =string__str(&____BAH_COMPILER_VAR_969);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_971);
unsigned int strLen_1 = strlen(" ");
;                            
            ____BAH_COMPILER_VAR_970 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_970+currStrOff, ____BAH_COMPILER_VAR_971, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_970+currStrOff, " ", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_970;
}
else {
if ((strcmp(v->type, newType) != 0)) {
char * ____BAH_COMPILER_VAR_972 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(newType);
unsigned int strLen_1 = strlen(".");
unsigned int strLen_2 = strlen(") as ");
unsigned int strLen_3 = strlen(v->type);
unsigned int strLen_4 = strlen("Cannot use var {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_972 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_972+currStrOff, "Cannot use var {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_972+currStrOff, v->type, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_972+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_972+currStrOff, newType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_972+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&varTok,____BAH_COMPILER_VAR_972);
}
}
char * ____BAH_COMPILER_VAR_973 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(valTok.cont);
unsigned int strLen_1 = strlen(";");
unsigned int strLen_2 = strlen(" = ");
unsigned int strLen_3 = strlen(v->name);
;                            
            ____BAH_COMPILER_VAR_973 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_973+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_973+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_973+currStrOff, valTok.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_973+currStrOff, ";", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_974 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_973);
;                            
            ____BAH_COMPILER_VAR_974 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_974+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_974+currStrOff, ____BAH_COMPILER_VAR_973, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_974;
if ((isThen==true)) {
char * ____BAH_COMPILER_VAR_975 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(v->name);
unsigned int strLen_1 = strlen(" != null) {");
unsigned int strLen_2 = strlen("if (");
;                            
            ____BAH_COMPILER_VAR_975 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_975+currStrOff, "if (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_975+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_975+currStrOff, " != null) {", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_976 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_975);
;                            
            ____BAH_COMPILER_VAR_976 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_976+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_976+currStrOff, ____BAH_COMPILER_VAR_975, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_976;
}
else {
char * ____BAH_COMPILER_VAR_977 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(v->name);
unsigned int strLen_1 = strlen(" == null) {");
unsigned int strLen_2 = strlen("if (");
;                            
            ____BAH_COMPILER_VAR_977 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_977+currStrOff, "if (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_977+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_977+currStrOff, " == null) {", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_978 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_977);
;                            
            ____BAH_COMPILER_VAR_978 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_978+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_978+currStrOff, ____BAH_COMPILER_VAR_977, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_978;
}
OUTPUT = rope__add(OUTPUT, rope(code));
array(struct Tok)* tokens = arraySubstitute(line, 6, len(line)-1);
struct Elems* CaptElems = dupElems(elems);
parseLines(tokens,CaptElems);
if ((isThen==true)) {
OUTPUT = rope__add(OUTPUT, rope("}\n"));
}
else {
char * ____BAH_COMPILER_VAR_979 =null;char * ____BAH_COMPILER_VAR_980 =intToStr(line->data[0].line);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_980);
unsigned int strLen_1 = strlen("\");}\n");
unsigned int strLen_2 = strlen(":");
unsigned int strLen_3 = strlen(compilerState.currentFile);
unsigned int strLen_4 = strlen("\n__BAH_panic(\"Undefined capture resolution.\", \"");
;                            
            ____BAH_COMPILER_VAR_979 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_979+currStrOff, "\n__BAH_panic(\"Undefined capture resolution.\", \"", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_979+currStrOff, compilerState.currentFile, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_979+currStrOff, ":", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_979+currStrOff, ____BAH_COMPILER_VAR_980, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_979+currStrOff, "\");}\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_979));
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
char * ____BAH_COMPILER_VAR_981 =registerRCPvar(fn->returns->type,ft.cont,elems);return;
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
char * ____BAH_COMPILER_VAR_982 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ft.cont);
unsigned int strLen_1 = strlen(";\n");
;                            
            ____BAH_COMPILER_VAR_982 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_982+currStrOff, ft.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_982+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_982));
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

    {
        unsigned long nLength = len(line);
        if (nLength >= line->length) {
            if (nLength >= line->realLength) {
                if (line->realLength != 0) {
                    line->realLength *= 2;
                } else {
                    line->realLength = 50;
                }
                void * newPtr = memoryRealloc(line->data, (line->realLength)*sizeof(struct Tok));
                line->data = newPtr;
            }
            line->data[len(line)] = t;
            line->length = nLength+1;
        } else {
            line->data[len(line)] = t;
        }
    }
    ;
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

    {
        unsigned long nLength = len(line);
        if (nLength >= line->length) {
            if (nLength >= line->realLength) {
                if (line->realLength != 0) {
                    line->realLength *= 2;
                } else {
                    line->realLength = 50;
                }
                void * newPtr = memoryRealloc(line->data, (line->realLength)*sizeof(struct Tok));
                line->data = newPtr;
            }
            line->data[len(line)] = t;
            line->length = nLength+1;
        } else {
            line->data[len(line)] = t;
        }
    }
    ;
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
char * ____BAH_COMPILER_VAR_983 =null;char * ____BAH_COMPILER_VAR_984 =string__str(&ct);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(" ");
unsigned int strLen_1 = strlen(arg->name);
unsigned int strLen_2 = strlen(____BAH_COMPILER_VAR_984);
unsigned int strLen_3 = strlen(tmpfnArgsCType);
;                            
            ____BAH_COMPILER_VAR_983 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_983+currStrOff, tmpfnArgsCType, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_983+currStrOff, ____BAH_COMPILER_VAR_984, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_983+currStrOff, " ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_983+currStrOff, arg->name, strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_983;
j = j+1;
if ((j<len(fn->args))) {
char * ____BAH_COMPILER_VAR_985 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpfnArgsCType);
unsigned int strLen_1 = strlen(", ");
;                            
            ____BAH_COMPILER_VAR_985 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_985+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_985+currStrOff, ", ", strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_985;
}
};
char * ____BAH_COMPILER_VAR_986 =null;char * ____BAH_COMPILER_VAR_987 =string__str(&tmpfnRetCType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpfnArgsCType);
unsigned int strLen_1 = strlen(");\n");
unsigned int strLen_2 = strlen("(");
unsigned int strLen_3 = strlen(fn->name);
unsigned int strLen_4 = strlen(" ");
unsigned int strLen_5 = strlen(____BAH_COMPILER_VAR_987);
;                            
            ____BAH_COMPILER_VAR_986 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_986+currStrOff, ____BAH_COMPILER_VAR_987, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_986+currStrOff, " ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_986+currStrOff, fn->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_986+currStrOff, "(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_986+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_986+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_986));
};
void declareVar(struct variable* v,struct Elems* elems){
if ((v->isConst==true)) {
char * ____BAH_COMPILER_VAR_988 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(v->constVal);
unsigned int strLen_1 = strlen("\n");
unsigned int strLen_2 = strlen(" ");
unsigned int strLen_3 = strlen(v->name);
unsigned int strLen_4 = strlen("#define ");
;                            
            ____BAH_COMPILER_VAR_988 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_988+currStrOff, "#define ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_988+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_988+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_988+currStrOff, v->constVal, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_988+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_988));
}
else {
struct string cType = getCType(v->type,elems);
char * ____BAH_COMPILER_VAR_989 =null;char * ____BAH_COMPILER_VAR_990 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(v->name);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen(" ");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_990);
;                            
            ____BAH_COMPILER_VAR_989 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_989+currStrOff, ____BAH_COMPILER_VAR_990, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_989+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_989+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_989+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_989));
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
char * ____BAH_COMPILER_VAR_991 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(compilerState.cIncludes->data[i]);
unsigned int strLen_1 = strlen("\n");
unsigned int strLen_2 = strlen("#include ");
;                            
            ____BAH_COMPILER_VAR_991 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_991+currStrOff, "#include ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_991+currStrOff, compilerState.cIncludes->data[i], strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_991+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_991));
};
i = 1;
for (; (i<len(compilerState.arrTypesDecl)); ++i) {
char * t = compilerState.arrTypesDecl->data[i];
struct string elemType = string(t);
string__trimLeft(&elemType,15);
char * ____BAH_COMPILER_VAR_992 =string__str(&elemType);struct string elemCtype = getCType(____BAH_COMPILER_VAR_992,elems);
char * ____BAH_COMPILER_VAR_993 =null;char * ____BAH_COMPILER_VAR_994 =string__str(&elemCtype);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen(")* ");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_994);
unsigned int strLen_4 = strlen("typedef array(");
;                            
            ____BAH_COMPILER_VAR_993 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_993+currStrOff, "typedef array(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_993+currStrOff, ____BAH_COMPILER_VAR_994, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_993+currStrOff, ")* ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_993+currStrOff, t, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_993+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_993));
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
char * ____BAH_COMPILER_VAR_995 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("file: ");
unsigned int strLen_1 = strlen(compilerState.currentFile);
;                            
            ____BAH_COMPILER_VAR_995 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_995+currStrOff, "file: ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_995+currStrOff, compilerState.currentFile, strLen_1);
            currStrOff += strLen_1;
        
        }char * r = ____BAH_COMPILER_VAR_995;
if ((currentFn!=null)) {
char * ____BAH_COMPILER_VAR_996 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(currentFn->name);
unsigned int strLen_1 = strlen("()");
unsigned int strLen_2 = strlen("\nfunction: ");
;                            
            ____BAH_COMPILER_VAR_996 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_996+currStrOff, "\nfunction: ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_996+currStrOff, currentFn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_996+currStrOff, "()", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_997 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(r);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_996);
;                            
            ____BAH_COMPILER_VAR_997 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_997+currStrOff, r, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_997+currStrOff, ____BAH_COMPILER_VAR_996, strLen_1);
            currStrOff += strLen_1;
        
        }r = ____BAH_COMPILER_VAR_997;
}
return r;
};
long int main(__BAH_ARR_TYPE_cpstring args){
onMemoryError = memErrHandle;
execName = args->data[0];
if ((execName[0]==46)||(execName[0]==47)) {
execName = absPath(execName);
}
struct flags ____BAH_COMPILER_VAR_998 = {};
____BAH_COMPILER_VAR_998.flags = memoryAlloc(sizeof(array(struct flag*)));
            ____BAH_COMPILER_VAR_998.flags->length = 0;
            ____BAH_COMPILER_VAR_998.flags->elemSize = sizeof(struct flag*);
            ____BAH_COMPILER_VAR_998.args = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_998.args->length = 0;
            ____BAH_COMPILER_VAR_998.args->elemSize = sizeof(char *);
            flags = ____BAH_COMPILER_VAR_998;
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
char * ____BAH_COMPILER_VAR_999 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(BAH_OS);
unsigned int strLen_1 = strlen(".");
unsigned int strLen_2 = strlen("Select the target OS for cross compilling (linux, windows, darwin), default: ");
;                            
            ____BAH_COMPILER_VAR_999 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_999+currStrOff, "Select the target OS for cross compilling (linux, windows, darwin), default: ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_999+currStrOff, BAH_OS, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_999+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }flags__addString(&flags,"target",____BAH_COMPILER_VAR_999);
char * ____BAH_COMPILER_VAR_1000 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(BAH_DIR);
unsigned int strLen_1 = strlen(").");
unsigned int strLen_2 = strlen("If your Bah directory is not the default one (");
;                            
            ____BAH_COMPILER_VAR_1000 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_1000+currStrOff, "If your Bah directory is not the default one (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_1000+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_1000+currStrOff, ").", strLen_1);
            currStrOff += strLen_1;
        
        }flags__addString(&flags,"bahDir",____BAH_COMPILER_VAR_1000);
char * ____BAH_COMPILER_VAR_1001 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(BAH_CC);
unsigned int strLen_1 = strlen(".");
unsigned int strLen_2 = strlen("To change the C compiler used, default: ");
;                            
            ____BAH_COMPILER_VAR_1001 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_1001+currStrOff, "To change the C compiler used, default: ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_1001+currStrOff, BAH_CC, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_1001+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }flags__addString(&flags,"CC",____BAH_COMPILER_VAR_1001);
flags__addBool(&flags,"object","Compile as an object.");
flags__addBool(&flags,"unsafe","Compile without safety checking. This will make for faster executable but if your program crashes, it will show less informations.");
flags__addBool(&flags,"nobuiltin","Does not include the builtin library (be really carefull, your program WILL break).");
flags__addBool(&flags,"optimize","Includes optimized functions");
flags__addBool(&flags,"n","Disables notices while keeping warnings enabled.");
flags__parse(&flags,args);
if ((flags__isSet(&flags,"target")==1)) {
BAH_OS = flags__get(&flags,"target");
char * ____BAH_COMPILER_VAR_1002 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("Build target: ");
unsigned int strLen_1 = strlen(BAH_OS);
;                            
            ____BAH_COMPILER_VAR_1002 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_1002+currStrOff, "Build target: ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_1002+currStrOff, BAH_OS, strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_1002);
}
if ((flags__isSet(&flags,"bahDir")==1)) {
BAH_DIR = flags__get(&flags,"bahDir");
array(char)* bahDirArr = strAsArr(BAH_DIR);
if ((bahDirArr->data[len(bahDirArr)-1]!=47)) {
char * ____BAH_COMPILER_VAR_1003 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(BAH_DIR);
unsigned int strLen_1 = strlen("/");
;                            
            ____BAH_COMPILER_VAR_1003 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_1003+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_1003+currStrOff, "/", strLen_1);
            currStrOff += strLen_1;
        
        }BAH_DIR = ____BAH_COMPILER_VAR_1003;
}
char * ____BAH_COMPILER_VAR_1004 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("Bah directory: ");
unsigned int strLen_1 = strlen(BAH_DIR);
;                            
            ____BAH_COMPILER_VAR_1004 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_1004+currStrOff, "Bah directory: ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_1004+currStrOff, BAH_DIR, strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_1004);
}
if ((flags__isSet(&flags,"CC")==1)) {
BAH_CC = flags__get(&flags,"CC");
char * ____BAH_COMPILER_VAR_1005 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("C compiler: ");
unsigned int strLen_1 = strlen(BAH_CC);
;                            
            ____BAH_COMPILER_VAR_1005 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_1005+currStrOff, "C compiler: ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_1005+currStrOff, BAH_CC, strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_1005);
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
char * ____BAH_COMPILER_VAR_1006 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(BAH_VERSION);
unsigned int strLen_1 = strlen(".\n© Alois Laurent Boe");
unsigned int strLen_2 = strlen("Bah compiler version: ");
;                            
            ____BAH_COMPILER_VAR_1006 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_1006+currStrOff, "Bah compiler version: ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_1006+currStrOff, BAH_VERSION, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_1006+currStrOff, ".\n© Alois Laurent Boe", strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_1006);
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
struct compilerStateTag ____BAH_COMPILER_VAR_1007 = {};
____BAH_COMPILER_VAR_1007.includes = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_1007.includes->length = 0;
            ____BAH_COMPILER_VAR_1007.includes->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_1007.cIncludes = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_1007.cIncludes->length = 0;
            ____BAH_COMPILER_VAR_1007.cIncludes->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_1007.cLibs = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_1007.cLibs->length = 0;
            ____BAH_COMPILER_VAR_1007.cLibs->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_1007.currentFile= null;
____BAH_COMPILER_VAR_1007.currentDir = "./";
____BAH_COMPILER_VAR_1007.isBranch = false;
____BAH_COMPILER_VAR_1007.isFor = false;
____BAH_COMPILER_VAR_1007.arrTypesDecl = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_1007.arrTypesDecl->length = 0;
            ____BAH_COMPILER_VAR_1007.arrTypesDecl->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_1007.haveEntryPoint = false;
____BAH_COMPILER_VAR_1007.RCPvars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_1007.RCPvars->length = 0;
            ____BAH_COMPILER_VAR_1007.RCPvars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_1007.evals = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_1007.evals->length = 0;
            ____BAH_COMPILER_VAR_1007.evals->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_1007.hasImports = false;
____BAH_COMPILER_VAR_1007.currForElems= null;
____BAH_COMPILER_VAR_1007.currFnElems= null;
compilerState = ____BAH_COMPILER_VAR_1007;

    {
        unsigned long nLength = 0;
        if (nLength >= compilerState.arrTypesDecl->length) {
            if (nLength >= compilerState.arrTypesDecl->realLength) {
                if (compilerState.arrTypesDecl->realLength != 0) {
                    compilerState.arrTypesDecl->realLength *= 2;
                } else {
                    compilerState.arrTypesDecl->realLength = 50;
                }
                void * newPtr = memoryRealloc(compilerState.arrTypesDecl->data, (compilerState.arrTypesDecl->realLength)*sizeof(char *));
                compilerState.arrTypesDecl->data = newPtr;
            }
            compilerState.arrTypesDecl->data[0] = "__BAH_ARR_TYPE_cpstring";
            compilerState.arrTypesDecl->length = nLength+1;
        } else {
            compilerState.arrTypesDecl->data[0] = "__BAH_ARR_TYPE_cpstring";
        }
    }
    ;
char * fileName = absPath(args->data[1]);
compilerState.currentFile = fileName;
struct fileMap ____BAH_COMPILER_VAR_1008 = {};
____BAH_COMPILER_VAR_1008.handle = -1;
____BAH_COMPILER_VAR_1008.p= null;
#define fm ____BAH_COMPILER_VAR_1008
char * f = fileMap__open(&fm,fileName);
if ((fileMap__isValid(&fm)==0)||(fm.size==0)) {
char * ____BAH_COMPILER_VAR_1009 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(args->data[1]);
unsigned int strLen_1 = strlen("'.");
unsigned int strLen_2 = strlen("Could not open file '");
;                            
            ____BAH_COMPILER_VAR_1009 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_1009+currStrOff, "Could not open file '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_1009+currStrOff, args->data[1], strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_1009+currStrOff, "'.", strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_1009);
exit(1);
}
long int startTime = getTimeUnix();
array(struct Tok)* tokens = lexer(f);
fileMap__close(&fm);
if ((len(tokens)==0)) {
char * ____BAH_COMPILER_VAR_1010 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fileName);
unsigned int strLen_1 = strlen("' not recognized.");
unsigned int strLen_2 = strlen("File '");
;                            
            ____BAH_COMPILER_VAR_1010 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_1010+currStrOff, "File '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_1010+currStrOff, fileName, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_1010+currStrOff, "' not recognized.", strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_1010);
exit(1);
}
struct Elems* ____BAH_COMPILER_VAR_1011 = memoryAlloc(sizeof(struct Elems));
____BAH_COMPILER_VAR_1011->vars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_1011->vars->length = 0;
            ____BAH_COMPILER_VAR_1011->vars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_1011->structs = memoryAlloc(sizeof(array(struct cStruct*)));
            ____BAH_COMPILER_VAR_1011->structs->length = 0;
            ____BAH_COMPILER_VAR_1011->structs->elemSize = sizeof(struct cStruct*);
            ____BAH_COMPILER_VAR_1011->types = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_1011->types->length = 0;
            ____BAH_COMPILER_VAR_1011->types->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_1011->fns = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_1011->fns->length = 0;
            ____BAH_COMPILER_VAR_1011->fns->elemSize = sizeof(struct func*);
            ____BAH_COMPILER_VAR_1011->defined = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_1011->defined->length = 0;
            ____BAH_COMPILER_VAR_1011->defined->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_1011->parent= null;
____BAH_COMPILER_VAR_1011->branchChecks = memoryAlloc(sizeof(array(struct varCheck)));
            ____BAH_COMPILER_VAR_1011->branchChecks->length = 0;
            ____BAH_COMPILER_VAR_1011->branchChecks->elemSize = sizeof(struct varCheck);
            struct Elems* elems = ____BAH_COMPILER_VAR_1011;
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

                struct string ____BAH_COMPILER_VAR_1012 = string(fileName);
                if ((flags__isSet(&flags,"nobuiltin")==0)&&(string__hasSuffix(&____BAH_COMPILER_VAR_1012,".bahstrp")==false)) {
if ((includeFile("builtin.bah",elems)==false)) {
char * ____BAH_COMPILER_VAR_1013 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(BAH_DIR);
unsigned int strLen_1 = strlen("'");
unsigned int strLen_2 = strlen("Could not find std-libs, please check '");
;                            
            ____BAH_COMPILER_VAR_1013 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_1013+currStrOff, "Could not find std-libs, please check '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_1013+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_1013+currStrOff, "'", strLen_1);
            currStrOff += strLen_1;
        
        }__BAH_panic(____BAH_COMPILER_VAR_1013,"/home/alois/Documents/bah-bah/src/main.bah:255");
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
char * ____BAH_COMPILER_VAR_1014 =null;char * ____BAH_COMPILER_VAR_1015 =intToStr(l);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_1015);
unsigned int strLen_1 = strlen("];");
unsigned int strLen_2 = strlen("volatile struct __Bah_fnName_mapper __tmp____Bah_fnNames[");
;                            
            ____BAH_COMPILER_VAR_1014 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_1014+currStrOff, "volatile struct __Bah_fnName_mapper __tmp____Bah_fnNames[", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_1014+currStrOff, ____BAH_COMPILER_VAR_1015, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_1014+currStrOff, "];", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1014));
long int j = 0;
i = 0;
for (; (i<len(elems->fns)); ++i) {
struct func* fn = elems->fns->data[i];
if ((fn->isBinding==true)) {
continue;
}
char * name = fn->name;
char * ____BAH_COMPILER_VAR_1016 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fn->from);
unsigned int strLen_1 = strlen("__");
;                            
            ____BAH_COMPILER_VAR_1016 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_1016+currStrOff, fn->from, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_1016+currStrOff, "__", strLen_1);
            currStrOff += strLen_1;
        
        }if ((strcmp(fn->from, "") != 0)&&strHasPrefix(name,____BAH_COMPILER_VAR_1016)) {
struct string n = string(name);
string__trimLeft(&n,strlen(fn->from)+2);
char * ____BAH_COMPILER_VAR_1017 =null;char * ____BAH_COMPILER_VAR_1018 =string__str(&n);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(".");
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_1018);
unsigned int strLen_2 = strlen(fn->from);
;                            
            ____BAH_COMPILER_VAR_1017 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_1017+currStrOff, fn->from, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_1017+currStrOff, ".", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_1017+currStrOff, ____BAH_COMPILER_VAR_1018, strLen_1);
            currStrOff += strLen_1;
        
        }name = ____BAH_COMPILER_VAR_1017;
}
char * ____BAH_COMPILER_VAR_1019 =null;char * ____BAH_COMPILER_VAR_1020 =intToStr(j);char * ____BAH_COMPILER_VAR_1021 =intToStr(j);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fn->name);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen("].p = ");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_1020);
unsigned int strLen_4 = strlen("\";\n            __tmp____Bah_fnNames[");
unsigned int strLen_5 = strlen(name);
unsigned int strLen_6 = strlen("].n = \"");
unsigned int strLen_7 = strlen(____BAH_COMPILER_VAR_1021);
unsigned int strLen_8 = strlen("\n            __tmp____Bah_fnNames[");
;                            
            ____BAH_COMPILER_VAR_1019 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_1019+currStrOff, "\n            __tmp____Bah_fnNames[", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_1019+currStrOff, ____BAH_COMPILER_VAR_1021, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_1019+currStrOff, "].n = \"", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_1019+currStrOff, name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_1019+currStrOff, "\";\n            __tmp____Bah_fnNames[", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_1019+currStrOff, ____BAH_COMPILER_VAR_1020, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_1019+currStrOff, "].p = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_1019+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_1019+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_1019));
++j;
};
char * ____BAH_COMPILER_VAR_1022 =null;char * ____BAH_COMPILER_VAR_1023 =intToStr(l);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_1023);
unsigned int strLen_1 = strlen(";");
unsigned int strLen_2 = strlen("\n        __Bah_fnNames->data = __tmp____Bah_fnNames;\n        __Bah_fnNames->length = ");
;                            
            ____BAH_COMPILER_VAR_1022 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_1022+currStrOff, "\n        __Bah_fnNames->data = __tmp____Bah_fnNames;\n        __Bah_fnNames->length = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_1022+currStrOff, ____BAH_COMPILER_VAR_1023, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_1022+currStrOff, ";", strLen_1);
            currStrOff += strLen_1;
        
        }INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_1022));
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
char * ____BAH_COMPILER_VAR_1024 =null;char * ____BAH_COMPILER_VAR_1025 =intToStr(totalLexerTime/1000000);char * ____BAH_COMPILER_VAR_1026 =intToStr(totalTime/1000000);char * ____BAH_COMPILER_VAR_1027 =intToStr(totalLines);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_1025);
unsigned int strLen_1 = strlen("ms)\e[0m");
unsigned int strLen_2 = strlen("ms, lexer time: ");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_1026);
unsigned int strLen_4 = strlen(" lines, total time: ");
unsigned int strLen_5 = strlen(____BAH_COMPILER_VAR_1027);
unsigned int strLen_6 = strlen("Parsed. (");
;                            
            ____BAH_COMPILER_VAR_1024 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_1024+currStrOff, "Parsed. (", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_1024+currStrOff, ____BAH_COMPILER_VAR_1027, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_1024+currStrOff, " lines, total time: ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_1024+currStrOff, ____BAH_COMPILER_VAR_1026, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_1024+currStrOff, "ms, lexer time: ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_1024+currStrOff, ____BAH_COMPILER_VAR_1025, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_1024+currStrOff, "ms)\e[0m", strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_1024);
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
char * ____BAH_COMPILER_VAR_1028 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fileName);
unsigned int strLen_1 = strlen(".o");
;                            
            ____BAH_COMPILER_VAR_1028 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_1028+currStrOff, fileName, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_1028+currStrOff, ".o", strLen_1);
            currStrOff += strLen_1;
        
        }fileName = ____BAH_COMPILER_VAR_1028;
obj = "-c";
}
char * randFileName = "-x c - -x none";
char * ____BAH_COMPILER_VAR_1029 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(" -w -O1 -o ");
unsigned int strLen_1 = strlen(fileName);
unsigned int strLen_2 = strlen(obj);
unsigned int strLen_3 = strlen(" ");
unsigned int strLen_4 = strlen(isStatic);
unsigned int strLen_5 = strlen(" ");
unsigned int strLen_6 = strlen(randFileName);
unsigned int strLen_7 = strlen("/\" ");
unsigned int strLen_8 = strlen(BAH_OS);
unsigned int strLen_9 = strlen("libs/");
unsigned int strLen_10 = strlen(BAH_DIR);
unsigned int strLen_11 = strlen("/include/\" -L \"");
unsigned int strLen_12 = strlen(BAH_OS);
unsigned int strLen_13 = strlen("libs/");
unsigned int strLen_14 = strlen(BAH_DIR);
unsigned int strLen_15 = strlen(" -I \"");
unsigned int strLen_16 = strlen(BAH_CC);
;                            
            ____BAH_COMPILER_VAR_1029 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13+strLen_14+strLen_15+strLen_16);
            
                    memcpy(____BAH_COMPILER_VAR_1029+currStrOff, BAH_CC, strLen_16);
                    currStrOff += strLen_16;
                    
                    memcpy(____BAH_COMPILER_VAR_1029+currStrOff, " -I \"", strLen_15);
                    currStrOff += strLen_15;
                    
                    memcpy(____BAH_COMPILER_VAR_1029+currStrOff, BAH_DIR, strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_1029+currStrOff, "libs/", strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_1029+currStrOff, BAH_OS, strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_1029+currStrOff, "/include/\" -L \"", strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_1029+currStrOff, BAH_DIR, strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_1029+currStrOff, "libs/", strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_1029+currStrOff, BAH_OS, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_1029+currStrOff, "/\" ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_1029+currStrOff, randFileName, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_1029+currStrOff, " ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_1029+currStrOff, isStatic, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_1029+currStrOff, " ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_1029+currStrOff, obj, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_1029+currStrOff, " -w -O1 -o ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_1029+currStrOff, fileName, strLen_1);
            currStrOff += strLen_1;
        
        }char * gccArgs = ____BAH_COMPILER_VAR_1029;
if ((flags__isSet(&flags,"l")==1)) {
char * ____BAH_COMPILER_VAR_1030 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(gccArgs);
unsigned int strLen_1 = strlen(" -c");
;                            
            ____BAH_COMPILER_VAR_1030 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_1030+currStrOff, gccArgs, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_1030+currStrOff, " -c", strLen_1);
            currStrOff += strLen_1;
        
        }gccArgs = ____BAH_COMPILER_VAR_1030;
}
array(char *)* cLibs = compilerState.cLibs;
register long int i = 0;
while ((i<len(cLibs))) {
char * l = cLibs->data[i];
char * ____BAH_COMPILER_VAR_1031 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(" -");
unsigned int strLen_1 = strlen(l);
unsigned int strLen_2 = strlen(gccArgs);
;                            
            ____BAH_COMPILER_VAR_1031 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_1031+currStrOff, gccArgs, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_1031+currStrOff, " -", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_1031+currStrOff, l, strLen_1);
            currStrOff += strLen_1;
        
        }gccArgs = ____BAH_COMPILER_VAR_1031;
i = i+1;
};
struct command cmd = command(gccArgs);
cmd.input = rope__toStr(OUTPUT);
if ((flags__isSet(&flags,"verboseCC")==1)) {
char * ____BAH_COMPILER_VAR_1032 =command__run(&cmd);println(____BAH_COMPILER_VAR_1032);
}
else {
char * ____BAH_COMPILER_VAR_1033 =command__run(&cmd);}
if ((cmd.status!=0)) {
println("\e[1;31m[CC-ERROR]\e[0m\nCould not compiled.");
return 1;
}
if ((flags__isSet(&flags,"l")==1)) {
char * ____BAH_COMPILER_VAR_1034 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(".a ");
unsigned int strLen_1 = strlen(fileName);
unsigned int strLen_2 = strlen(fileName);
unsigned int strLen_3 = strlen("ar rcs ");
;                            
            ____BAH_COMPILER_VAR_1034 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_1034+currStrOff, "ar rcs ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_1034+currStrOff, fileName, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_1034+currStrOff, ".a ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_1034+currStrOff, fileName, strLen_1);
            currStrOff += strLen_1;
        
        }cmd = command(____BAH_COMPILER_VAR_1034);
char * ____BAH_COMPILER_VAR_1035 =command__run(&cmd);}
}
else {
if ((flags__isSet(&flags,"o")==0)) {
char * ____BAH_COMPILER_VAR_1036 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fileName);
unsigned int strLen_1 = strlen(".c");
;                            
            ____BAH_COMPILER_VAR_1036 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_1036+currStrOff, fileName, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_1036+currStrOff, ".c", strLen_1);
            currStrOff += strLen_1;
        
        }fileName = ____BAH_COMPILER_VAR_1036;
}
char * ____BAH_COMPILER_VAR_1037 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(isStatic);
unsigned int strLen_1 = strlen(" -O1 -w ");
unsigned int strLen_2 = strlen(" ");
unsigned int strLen_3 = strlen(fileName);
unsigned int strLen_4 = strlen("/\" ");
unsigned int strLen_5 = strlen(BAH_OS);
unsigned int strLen_6 = strlen("libs/");
unsigned int strLen_7 = strlen(BAH_DIR);
unsigned int strLen_8 = strlen("/include/\" -L \"");
unsigned int strLen_9 = strlen(BAH_OS);
unsigned int strLen_10 = strlen("libs/");
unsigned int strLen_11 = strlen(BAH_DIR);
unsigned int strLen_12 = strlen(" -I \"");
unsigned int strLen_13 = strlen(BAH_CC);
;                            
            ____BAH_COMPILER_VAR_1037 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13);
            
                    memcpy(____BAH_COMPILER_VAR_1037+currStrOff, BAH_CC, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_1037+currStrOff, " -I \"", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_1037+currStrOff, BAH_DIR, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_1037+currStrOff, "libs/", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_1037+currStrOff, BAH_OS, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_1037+currStrOff, "/include/\" -L \"", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_1037+currStrOff, BAH_DIR, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_1037+currStrOff, "libs/", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_1037+currStrOff, BAH_OS, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_1037+currStrOff, "/\" ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_1037+currStrOff, fileName, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_1037+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_1037+currStrOff, isStatic, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_1037+currStrOff, " -O1 -w ", strLen_1);
            currStrOff += strLen_1;
        
        }char * gccArgs = ____BAH_COMPILER_VAR_1037;
array(char *)* cLibs = compilerState.cLibs;
register long int i = 0;
while ((i<len(cLibs))) {
char * l = cLibs->data[i];
char * ____BAH_COMPILER_VAR_1038 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(" -");
unsigned int strLen_1 = strlen(l);
unsigned int strLen_2 = strlen(gccArgs);
;                            
            ____BAH_COMPILER_VAR_1038 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_1038+currStrOff, gccArgs, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_1038+currStrOff, " -", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_1038+currStrOff, l, strLen_1);
            currStrOff += strLen_1;
        
        }gccArgs = ____BAH_COMPILER_VAR_1038;
i = i+1;
};
char * ____BAH_COMPILER_VAR_1039 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(gccArgs);
unsigned int strLen_1 = strlen("'\n");
unsigned int strLen_2 = strlen("//COMPILE WITH: '");
;                            
            ____BAH_COMPILER_VAR_1039 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_1039+currStrOff, "//COMPILE WITH: '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_1039+currStrOff, gccArgs, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_1039+currStrOff, "'\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(rope(____BAH_COMPILER_VAR_1039), OUTPUT);
struct fileStream ____BAH_COMPILER_VAR_1040 = {};
____BAH_COMPILER_VAR_1040.handle= null;
____BAH_COMPILER_VAR_1040.name= null;
#define fs ____BAH_COMPILER_VAR_1040
fileStream__open(&fs,fileName,"w");
char * ____BAH_COMPILER_VAR_1041 =rope__toStr(OUTPUT);fileStream__writeFile(&fs,____BAH_COMPILER_VAR_1041);
fileStream__close(&fs);

#undef fs
}
if ((isObject==false)) {
long int totalTime = getTimeUnix()-startTime;
char * ____BAH_COMPILER_VAR_1042 =null;char * ____BAH_COMPILER_VAR_1043 =intToStr(totalTime/1000000);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_1043);
unsigned int strLen_1 = strlen("ms)\e[0m");
unsigned int strLen_2 = strlen("\e[1;32mDone. (compiled in ");
;                            
            ____BAH_COMPILER_VAR_1042 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_1042+currStrOff, "\e[1;32mDone. (compiled in ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_1042+currStrOff, ____BAH_COMPILER_VAR_1043, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_1042+currStrOff, "ms)\e[0m", strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_1042);
}
return 0;

#undef fm
};
volatile struct __Bah_fnName_mapper __tmp____Bah_fnNames[314];
    
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

            __tmp____Bah_fnNames[30].n = "concatCPSTRING";
            __tmp____Bah_fnNames[30].p = concatCPSTRING;

            __tmp____Bah_fnNames[31].n = "__STR";
            __tmp____Bah_fnNames[31].p = __STR;

            __tmp____Bah_fnNames[32].n = "cArr";
            __tmp____Bah_fnNames[32].p = cArr;

            __tmp____Bah_fnNames[33].n = "__checkString";
            __tmp____Bah_fnNames[33].p = __checkString;

            __tmp____Bah_fnNames[34].n = "mutex.init";
            __tmp____Bah_fnNames[34].p = mutex__init;

            __tmp____Bah_fnNames[35].n = "mutex.lock";
            __tmp____Bah_fnNames[35].p = mutex__lock;

            __tmp____Bah_fnNames[36].n = "mutex.unlock";
            __tmp____Bah_fnNames[36].p = mutex__unlock;

            __tmp____Bah_fnNames[37].n = "mutex.destroy";
            __tmp____Bah_fnNames[37].p = mutex__destroy;

            __tmp____Bah_fnNames[38].n = "mutexCondition.init";
            __tmp____Bah_fnNames[38].p = mutexCondition__init;

            __tmp____Bah_fnNames[39].n = "mutexCondition.wait";
            __tmp____Bah_fnNames[39].p = mutexCondition__wait;

            __tmp____Bah_fnNames[40].n = "mutexCondition.send";
            __tmp____Bah_fnNames[40].p = mutexCondition__send;

            __tmp____Bah_fnNames[41].n = "mutexCondition.destroy";
            __tmp____Bah_fnNames[41].p = mutexCondition__destroy;

            __tmp____Bah_fnNames[42].n = "mutexCondition";
            __tmp____Bah_fnNames[42].p = mutexCondition;

            __tmp____Bah_fnNames[43].n = "thread.create";
            __tmp____Bah_fnNames[43].p = thread__create;

            __tmp____Bah_fnNames[44].n = "thread.createWithArg";
            __tmp____Bah_fnNames[44].p = thread__createWithArg;

            __tmp____Bah_fnNames[45].n = "thread.wait";
            __tmp____Bah_fnNames[45].p = thread__wait;

            __tmp____Bah_fnNames[46].n = "mutex";
            __tmp____Bah_fnNames[46].p = mutex;

            __tmp____Bah_fnNames[47].n = "queue.insert";
            __tmp____Bah_fnNames[47].p = queue__insert;

            __tmp____Bah_fnNames[48].n = "queue.delete";
            __tmp____Bah_fnNames[48].p = queue__delete;

            __tmp____Bah_fnNames[49].n = "queue.get";
            __tmp____Bah_fnNames[49].p = queue__get;

            __tmp____Bah_fnNames[50].n = "queue.set";
            __tmp____Bah_fnNames[50].p = queue__set;

            __tmp____Bah_fnNames[51].n = "queue.pop";
            __tmp____Bah_fnNames[51].p = queue__pop;

            __tmp____Bah_fnNames[52].n = "queue.clear";
            __tmp____Bah_fnNames[52].p = queue__clear;

            __tmp____Bah_fnNames[53].n = "channel.send";
            __tmp____Bah_fnNames[53].p = channel__send;

            __tmp____Bah_fnNames[54].n = "channel.sendAny";
            __tmp____Bah_fnNames[54].p = channel__sendAny;

            __tmp____Bah_fnNames[55].n = "channel.receive";
            __tmp____Bah_fnNames[55].p = channel__receive;

            __tmp____Bah_fnNames[56].n = "channel.destroy";
            __tmp____Bah_fnNames[56].p = channel__destroy;

            __tmp____Bah_fnNames[57].n = "channel.len";
            __tmp____Bah_fnNames[57].p = channel__len;

            __tmp____Bah_fnNames[58].n = "channel";
            __tmp____Bah_fnNames[58].p = channel;

            __tmp____Bah_fnNames[59].n = "setChanCap";
            __tmp____Bah_fnNames[59].p = setChanCap;

            __tmp____Bah_fnNames[60].n = "__Bah_common_panic";
            __tmp____Bah_fnNames[60].p = __Bah_common_panic;

            __tmp____Bah_fnNames[61].n = "__Bah_fnNames_append";
            __tmp____Bah_fnNames[61].p = __Bah_fnNames_append;

            __tmp____Bah_fnNames[62].n = "__Bah_segfault_handle";
            __tmp____Bah_fnNames[62].p = __Bah_segfault_handle;

            __tmp____Bah_fnNames[63].n = "__Bah_init_segfaultHandle";
            __tmp____Bah_fnNames[63].p = __Bah_init_segfaultHandle;

            __tmp____Bah_fnNames[64].n = "recover";
            __tmp____Bah_fnNames[64].p = recover;

            __tmp____Bah_fnNames[65].n = "cpstringCharAt";
            __tmp____Bah_fnNames[65].p = cpstringCharAt;

            __tmp____Bah_fnNames[66].n = "cpstringSubsitute";
            __tmp____Bah_fnNames[66].p = cpstringSubsitute;

            __tmp____Bah_fnNames[67].n = "arraySubstitute";
            __tmp____Bah_fnNames[67].p = arraySubstitute;

            __tmp____Bah_fnNames[68].n = "__Bah_map_hash";
            __tmp____Bah_fnNames[68].p = __Bah_map_hash;

            __tmp____Bah_fnNames[69].n = "mapWrapper.grow";
            __tmp____Bah_fnNames[69].p = mapWrapper__grow;

            __tmp____Bah_fnNames[70].n = "mapWrapper.set";
            __tmp____Bah_fnNames[70].p = mapWrapper__set;

            __tmp____Bah_fnNames[71].n = "mapWrapper.setAny";
            __tmp____Bah_fnNames[71].p = mapWrapper__setAny;

            __tmp____Bah_fnNames[72].n = "mapWrapper.delete";
            __tmp____Bah_fnNames[72].p = mapWrapper__delete;

            __tmp____Bah_fnNames[73].n = "mapWrapper.get";
            __tmp____Bah_fnNames[73].p = mapWrapper__get;

            __tmp____Bah_fnNames[74].n = "mapWrapper";
            __tmp____Bah_fnNames[74].p = mapWrapper;

            __tmp____Bah_fnNames[75].n = "stdinput";
            __tmp____Bah_fnNames[75].p = stdinput;

            __tmp____Bah_fnNames[76].n = "println";
            __tmp____Bah_fnNames[76].p = println;

            __tmp____Bah_fnNames[77].n = "fileStream.isValid";
            __tmp____Bah_fnNames[77].p = fileStream__isValid;

            __tmp____Bah_fnNames[78].n = "fileStream.open";
            __tmp____Bah_fnNames[78].p = fileStream__open;

            __tmp____Bah_fnNames[79].n = "fileStream.close";
            __tmp____Bah_fnNames[79].p = fileStream__close;

            __tmp____Bah_fnNames[80].n = "fileStream.getPos";
            __tmp____Bah_fnNames[80].p = fileStream__getPos;

            __tmp____Bah_fnNames[81].n = "fileStream.setPos";
            __tmp____Bah_fnNames[81].p = fileStream__setPos;

            __tmp____Bah_fnNames[82].n = "fileStream.getSize";
            __tmp____Bah_fnNames[82].p = fileStream__getSize;

            __tmp____Bah_fnNames[83].n = "fileStream.rewind";
            __tmp____Bah_fnNames[83].p = fileStream__rewind;

            __tmp____Bah_fnNames[84].n = "fileStream.getChar";
            __tmp____Bah_fnNames[84].p = fileStream__getChar;

            __tmp____Bah_fnNames[85].n = "fileStream.setChar";
            __tmp____Bah_fnNames[85].p = fileStream__setChar;

            __tmp____Bah_fnNames[86].n = "fileStream.createFile";
            __tmp____Bah_fnNames[86].p = fileStream__createFile;

            __tmp____Bah_fnNames[87].n = "fileStream.writeFile";
            __tmp____Bah_fnNames[87].p = fileStream__writeFile;

            __tmp____Bah_fnNames[88].n = "fileStream.writePtr";
            __tmp____Bah_fnNames[88].p = fileStream__writePtr;

            __tmp____Bah_fnNames[89].n = "fileStream.readPtr";
            __tmp____Bah_fnNames[89].p = fileStream__readPtr;

            __tmp____Bah_fnNames[90].n = "fileStream.readContent";
            __tmp____Bah_fnNames[90].p = fileStream__readContent;

            __tmp____Bah_fnNames[91].n = "fileStream.readBytes";
            __tmp____Bah_fnNames[91].p = fileStream__readBytes;

            __tmp____Bah_fnNames[92].n = "fileStream.writeBytes";
            __tmp____Bah_fnNames[92].p = fileStream__writeBytes;

            __tmp____Bah_fnNames[93].n = "fileStream._end";
            __tmp____Bah_fnNames[93].p = fileStream___end;

            __tmp____Bah_fnNames[94].n = "fileMap.open";
            __tmp____Bah_fnNames[94].p = fileMap__open;

            __tmp____Bah_fnNames[95].n = "fileMap.isValid";
            __tmp____Bah_fnNames[95].p = fileMap__isValid;

            __tmp____Bah_fnNames[96].n = "fileMap.close";
            __tmp____Bah_fnNames[96].p = fileMap__close;

            __tmp____Bah_fnNames[97].n = "listFiles";
            __tmp____Bah_fnNames[97].p = listFiles;

            __tmp____Bah_fnNames[98].n = "fileExists";
            __tmp____Bah_fnNames[98].p = fileExists;

            __tmp____Bah_fnNames[99].n = "isFolder";
            __tmp____Bah_fnNames[99].p = isFolder;

            __tmp____Bah_fnNames[100].n = "removeFile";
            __tmp____Bah_fnNames[100].p = removeFile;

            __tmp____Bah_fnNames[101].n = "getLastModified";
            __tmp____Bah_fnNames[101].p = getLastModified;

            __tmp____Bah_fnNames[102].n = "__windows_mkdir";
            __tmp____Bah_fnNames[102].p = __windows_mkdir;

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

            __tmp____Bah_fnNames[260].n = "OPTI_checkFuncScopeRef";
            __tmp____Bah_fnNames[260].p = OPTI_checkFuncScopeRef;

            __tmp____Bah_fnNames[261].n = "debugLine";
            __tmp____Bah_fnNames[261].p = debugLine;

            __tmp____Bah_fnNames[262].n = "dupElems";
            __tmp____Bah_fnNames[262].p = dupElems;

            __tmp____Bah_fnNames[263].n = "checkCanBeNull";
            __tmp____Bah_fnNames[263].p = checkCanBeNull;

            __tmp____Bah_fnNames[264].n = "setNullStateBranchFlowEnd";
            __tmp____Bah_fnNames[264].p = setNullStateBranchFlowEnd;

            __tmp____Bah_fnNames[265].n = "getLineType";
            __tmp____Bah_fnNames[265].p = getLineType;

            __tmp____Bah_fnNames[266].n = "parseCast";
            __tmp____Bah_fnNames[266].p = parseCast;

            __tmp____Bah_fnNames[267].n = "getDirFromFile";
            __tmp____Bah_fnNames[267].p = getDirFromFile;

            __tmp____Bah_fnNames[268].n = "parseLines";
            __tmp____Bah_fnNames[268].p = parseLines;

            __tmp____Bah_fnNames[269].n = "includeFile";
            __tmp____Bah_fnNames[269].p = includeFile;

            __tmp____Bah_fnNames[270].n = "parallelObjCompile";
            __tmp____Bah_fnNames[270].p = parallelObjCompile;

            __tmp____Bah_fnNames[271].n = "parseImport";
            __tmp____Bah_fnNames[271].p = parseImport;

            __tmp____Bah_fnNames[272].n = "parseInclude";
            __tmp____Bah_fnNames[272].p = parseInclude;

            __tmp____Bah_fnNames[273].n = "prePross";
            __tmp____Bah_fnNames[273].p = prePross;

            __tmp____Bah_fnNames[274].n = "parseStructType";
            __tmp____Bah_fnNames[274].p = parseStructType;

            __tmp____Bah_fnNames[275].n = "parseArrayType";
            __tmp____Bah_fnNames[275].p = parseArrayType;

            __tmp____Bah_fnNames[276].n = "parsePointers";
            __tmp____Bah_fnNames[276].p = parsePointers;

            __tmp____Bah_fnNames[277].n = "parseSerialize";
            __tmp____Bah_fnNames[277].p = parseSerialize;

            __tmp____Bah_fnNames[278].n = "parseReflect";
            __tmp____Bah_fnNames[278].p = parseReflect;

            __tmp____Bah_fnNames[279].n = "parseArrayDecl";
            __tmp____Bah_fnNames[279].p = parseArrayDecl;

            __tmp____Bah_fnNames[280].n = "parseVar";
            __tmp____Bah_fnNames[280].p = parseVar;

            __tmp____Bah_fnNames[281].n = "getCfunctionType";
            __tmp____Bah_fnNames[281].p = getCfunctionType;

            __tmp____Bah_fnNames[282].n = "parseFnHeader";
            __tmp____Bah_fnNames[282].p = parseFnHeader;

            __tmp____Bah_fnNames[283].n = "parseStruct";
            __tmp____Bah_fnNames[283].p = parseStruct;

            __tmp____Bah_fnNames[284].n = "parseDefine";
            __tmp____Bah_fnNames[284].p = parseDefine;

            __tmp____Bah_fnNames[285].n = "parseClib";
            __tmp____Bah_fnNames[285].p = parseClib;

            __tmp____Bah_fnNames[286].n = "parseConst";
            __tmp____Bah_fnNames[286].p = parseConst;

            __tmp____Bah_fnNames[287].n = "parseReturn";
            __tmp____Bah_fnNames[287].p = parseReturn;

            __tmp____Bah_fnNames[288].n = "parseIf";
            __tmp____Bah_fnNames[288].p = parseIf;

            __tmp____Bah_fnNames[289].n = "parseElse";
            __tmp____Bah_fnNames[289].p = parseElse;

            __tmp____Bah_fnNames[290].n = "parseLine";
            __tmp____Bah_fnNames[290].p = parseLine;

            __tmp____Bah_fnNames[291].n = "parseFor";
            __tmp____Bah_fnNames[291].p = parseFor;

            __tmp____Bah_fnNames[292].n = "parseForOp";
            __tmp____Bah_fnNames[292].p = parseForOp;

            __tmp____Bah_fnNames[293].n = "makeEvalFunc";
            __tmp____Bah_fnNames[293].p = makeEvalFunc;

            __tmp____Bah_fnNames[294].n = "parsePreKeyword";
            __tmp____Bah_fnNames[294].p = parsePreKeyword;

            __tmp____Bah_fnNames[295].n = "parseAsync";
            __tmp____Bah_fnNames[295].p = parseAsync;

            __tmp____Bah_fnNames[296].n = "addRCPvars";
            __tmp____Bah_fnNames[296].p = addRCPvars;

            __tmp____Bah_fnNames[297].n = "parseChan";
            __tmp____Bah_fnNames[297].p = parseChan;

            __tmp____Bah_fnNames[298].n = "valueFunc";
            __tmp____Bah_fnNames[298].p = valueFunc;

            __tmp____Bah_fnNames[299].n = "valueStruct";
            __tmp____Bah_fnNames[299].p = valueStruct;

            __tmp____Bah_fnNames[300].n = "valueArr";
            __tmp____Bah_fnNames[300].p = valueArr;

            __tmp____Bah_fnNames[301].n = "valueBool";
            __tmp____Bah_fnNames[301].p = valueBool;

            __tmp____Bah_fnNames[302].n = "valueOper";
            __tmp____Bah_fnNames[302].p = valueOper;

            __tmp____Bah_fnNames[303].n = "valueSendChan";
            __tmp____Bah_fnNames[303].p = valueSendChan;

            __tmp____Bah_fnNames[304].n = "valueChan";
            __tmp____Bah_fnNames[304].p = valueChan;

            __tmp____Bah_fnNames[305].n = "isSmallValue";
            __tmp____Bah_fnNames[305].p = isSmallValue;

            __tmp____Bah_fnNames[306].n = "isValue";
            __tmp____Bah_fnNames[306].p = isValue;

            __tmp____Bah_fnNames[307].n = "parseFnDeclare";
            __tmp____Bah_fnNames[307].p = parseFnDeclare;

            __tmp____Bah_fnNames[308].n = "parseCapture";
            __tmp____Bah_fnNames[308].p = parseCapture;

            __tmp____Bah_fnNames[309].n = "declareFunc";
            __tmp____Bah_fnNames[309].p = declareFunc;

            __tmp____Bah_fnNames[310].n = "declareVar";
            __tmp____Bah_fnNames[310].p = declareVar;

            __tmp____Bah_fnNames[311].n = "declareAll";
            __tmp____Bah_fnNames[311].p = declareAll;

            __tmp____Bah_fnNames[312].n = "memErrHandle";
            __tmp____Bah_fnNames[312].p = memErrHandle;

            __tmp____Bah_fnNames[313].n = "main";
            __tmp____Bah_fnNames[313].p = main;

        __Bah_fnNames->data = __tmp____Bah_fnNames;
        __Bah_fnNames->length = 314;
        
    };
    