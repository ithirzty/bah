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
destroy(arr->data);
arr->data=memoryAlloc(sizeof(0));
arr->length=0;
arr->realLength=0;
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
char * err = (char *)channel__receive(__BAH_panic_chan);
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
char * ____BAH_COMPILER_VAR_9 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s);
unsigned int strLen_1 = strlen("\"");
unsigned int strLen_2 = strlen("\"");
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
};
void mapWrapper__set(struct mapWrapper* this,char * k,void * e){
if ((this->length*2>=len(this->elems))) {
mapWrapper__grow(this,this->length);
}
struct mapElem* ____BAH_COMPILER_VAR_10 = memoryAlloc(sizeof(struct mapElem));
____BAH_COMPILER_VAR_10->key= null;
____BAH_COMPILER_VAR_10->val= null;
____BAH_COMPILER_VAR_10->key = k;
____BAH_COMPILER_VAR_10->val = e;
struct mapElem* elem = ____BAH_COMPILER_VAR_10;
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
struct mapElem* ____BAH_COMPILER_VAR_11 = memoryAlloc(sizeof(struct mapElem));
____BAH_COMPILER_VAR_11->key= null;
____BAH_COMPILER_VAR_11->val= null;
____BAH_COMPILER_VAR_11->key = k;
____BAH_COMPILER_VAR_11->val = p;
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
struct mapWrapper* ____BAH_COMPILER_VAR_12 = memoryAlloc(sizeof(struct mapWrapper));
____BAH_COMPILER_VAR_12->elems = memoryAlloc(sizeof(array(struct mapElem*)));
            ____BAH_COMPILER_VAR_12->elems->length = 0;
            ____BAH_COMPILER_VAR_12->elems->elemSize = sizeof(struct mapElem*);
            struct mapWrapper* m = ____BAH_COMPILER_VAR_12;
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
char * ____BAH_COMPILER_VAR_13 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(response);
unsigned int strLen_1 = strlen(buff);
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
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s);
unsigned int strLen_1 = strlen("\n");
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
char * ____BAH_COMPILER_VAR_16 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(this->name);
unsigned int strLen_1 = strlen("'.");
unsigned int strLen_2 = strlen("iostream: warning, auto-closing file: '");
;                            
            ____BAH_COMPILER_VAR_16 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_16+currStrOff, "iostream: warning, auto-closing file: '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_16+currStrOff, this->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_16+currStrOff, "'.", strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_16);
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
struct stat ____BAH_COMPILER_VAR_17 = {};
#define sb ____BAH_COMPILER_VAR_17
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
string__makeEditable(this);
}
struct string ____BAH_COMPILER_VAR_18 = {};
____BAH_COMPILER_VAR_18.content= null;
#define needle ____BAH_COMPILER_VAR_18
string__set(&needle,nd);
struct string ____BAH_COMPILER_VAR_19 = {};
____BAH_COMPILER_VAR_19.content= null;
#define repl ____BAH_COMPILER_VAR_19
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
char * ____BAH_COMPILER_VAR_20 =null;char * ____BAH_COMPILER_VAR_21 =arrAsStr(replbuffStr);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(r);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_21);
;                            
            ____BAH_COMPILER_VAR_20 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_20+currStrOff, r, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_20+currStrOff, ____BAH_COMPILER_VAR_21, strLen_1);
            currStrOff += strLen_1;
        
        }r = ____BAH_COMPILER_VAR_20;
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
struct string ____BAH_COMPILER_VAR_22 = {};
____BAH_COMPILER_VAR_22.content= null;
#define needle ____BAH_COMPILER_VAR_22
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
#define a ____BAH_COMPILER_VAR_24
string__set(&a,s);
return a;

#undef a
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
char c = string__charAt(&s,i);
char sepc = string__charAt(&sep,sepIndex);
if ((c==sepc)) {
sepIndex = sepIndex+1;
char * ____BAH_COMPILER_VAR_28 =charToString(c);string__append(&replcBuff,____BAH_COMPILER_VAR_28);
}
else {
if ((sepIndex>0)) {
sepIndex = 0;
char * ____BAH_COMPILER_VAR_29 =charToString(c);string__append(&replcBuff,____BAH_COMPILER_VAR_29);
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
struct string* ____BAH_COMPILER_VAR_30 = memoryAlloc(sizeof(struct string));
____BAH_COMPILER_VAR_30->content= null;
struct string* elem = ____BAH_COMPILER_VAR_30;
char * ____BAH_COMPILER_VAR_31 =arrToStr(tmpString);string__set(elem,____BAH_COMPILER_VAR_31);
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
struct string* ____BAH_COMPILER_VAR_32 = memoryAlloc(sizeof(struct string));
____BAH_COMPILER_VAR_32->content= null;
struct string* elem = ____BAH_COMPILER_VAR_32;
char * ____BAH_COMPILER_VAR_33 =arrToStr(tmpString);string__set(elem,____BAH_COMPILER_VAR_33);
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
char * ____BAH_COMPILER_VAR_34 =string__str(&e);struct string tmpS = string(____BAH_COMPILER_VAR_34);
if ((i!=max)) {
string__append(&tmpS,sep);
}
char * ____BAH_COMPILER_VAR_35 =string__str(&tmpS);string__append(&s,____BAH_COMPILER_VAR_35);
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
struct flag* ____BAH_COMPILER_VAR_41 = memoryAlloc(sizeof(struct flag));
____BAH_COMPILER_VAR_41->name= null;
____BAH_COMPILER_VAR_41->help= null;
____BAH_COMPILER_VAR_41->content= null;
struct flag* z = ____BAH_COMPILER_VAR_41;
z->isSet = 0;
return z;
};
char * flags__get(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_42 =string(name);struct flag* flag = flags__getFlag(this,____BAH_COMPILER_VAR_42);
char * ctn = flag->content;
return ctn;
};
long int flags__getInt(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_43 =string(name);struct flag* flag = flags__getFlag(this,____BAH_COMPILER_VAR_43);
if ((flag->type!=FLAG_TYPE_INT)) {
char * ____BAH_COMPILER_VAR_44 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(flag->name);
unsigned int strLen_1 = strlen("' is not int.");
unsigned int strLen_2 = strlen("Flag '");
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
struct string ____BAH_COMPILER_VAR_45 =string(name);struct flag* flag = flags__getFlag(this,____BAH_COMPILER_VAR_45);
if ((flag->type!=FLAG_TYPE_FLOAT)) {
char * ____BAH_COMPILER_VAR_46 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(flag->name);
unsigned int strLen_1 = strlen("' is not float.");
unsigned int strLen_2 = strlen("Flag '");
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
struct string ____BAH_COMPILER_VAR_47 =string(name);struct flag* flag = flags__getFlag(this,____BAH_COMPILER_VAR_47);
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
currentFlag->content = string__str(&argName);
if ((currentFlag->type==FLAG_TYPE_INT)) {
char * ____BAH_COMPILER_VAR_48 =string__str(&argName);currentFlag->cont_int = atoi(____BAH_COMPILER_VAR_48);
}
else if ((currentFlag->type==FLAG_TYPE_FLOAT)) {
char * ____BAH_COMPILER_VAR_49 =string__str(&argName);currentFlag->cont_float = strtod(____BAH_COMPILER_VAR_49,0);
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
struct timespec ____BAH_COMPILER_VAR_50 = {};
#define ts ____BAH_COMPILER_VAR_50
clock_serv_t cclock;
mach_timespec_t mts;
void * ____BAH_COMPILER_VAR_51 =mach_host_self();host_get_clock_service(____BAH_COMPILER_VAR_51,CALENDAR_CLOCK,&cclock);
clock_get_time(cclock,&mts);
void * ____BAH_COMPILER_VAR_52 =mach_task_self();mach_port_deallocate(____BAH_COMPILER_VAR_52,cclock);
mach_timespec_t* mtsp = &mts;
ts.tv_sec = mtsp->tv_sec;
ts.tv_nsec = mtsp->tv_nsec;
long int s = ts.tv_sec*1000000000+ts.tv_nsec;
return s;

#undef ts
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
struct fileStream ____BAH_COMPILER_VAR_53 = {};
____BAH_COMPILER_VAR_53.handle= null;
____BAH_COMPILER_VAR_53.name= null;
#define fs ____BAH_COMPILER_VAR_53
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
struct rope* ____BAH_COMPILER_VAR_54 = memoryAlloc(sizeof(struct rope));
____BAH_COMPILER_VAR_54->left= null;
____BAH_COMPILER_VAR_54->right= null;
____BAH_COMPILER_VAR_54->str= null;
____BAH_COMPILER_VAR_54->len = 0;
struct rope* tmp = ____BAH_COMPILER_VAR_54;
tmp->left = this;
tmp->right = root2;
tmp->totalLen = this->totalLen+root2->totalLen;
tmp->str = null;
return tmp;
};
struct rope* createRopeStructure(struct rope* par,char * a,long int l,long int r){
struct rope* ____BAH_COMPILER_VAR_55 = memoryAlloc(sizeof(struct rope));
____BAH_COMPILER_VAR_55->left= null;
____BAH_COMPILER_VAR_55->right= null;
____BAH_COMPILER_VAR_55->str= null;
____BAH_COMPILER_VAR_55->len = 0;
struct rope* tmp = ____BAH_COMPILER_VAR_55;
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
struct rope* ____BAH_COMPILER_VAR_56 = memoryAlloc(sizeof(struct rope));
____BAH_COMPILER_VAR_56->left= null;
____BAH_COMPILER_VAR_56->right= null;
____BAH_COMPILER_VAR_56->str= null;
____BAH_COMPILER_VAR_56->len = 0;
struct rope* tmp = ____BAH_COMPILER_VAR_56;
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
char * ____BAH_COMPILER_VAR_57 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(cm);
unsigned int strLen_1 = strlen(" 2>/dev/null");
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
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(cm);
unsigned int strLen_1 = strlen(" 2>&1");
;                            
            ____BAH_COMPILER_VAR_58 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_58+currStrOff, cm, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_58+currStrOff, " 2>&1", strLen_1);
            currStrOff += strLen_1;
        
        }cm = ____BAH_COMPILER_VAR_58;
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
char * ____BAH_COMPILER_VAR_59 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(res);
unsigned int strLen_1 = strlen(buff);
;                            
            ____BAH_COMPILER_VAR_59 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_59+currStrOff, res, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_59+currStrOff, buff, strLen_1);
            currStrOff += strLen_1;
        
        }res = ____BAH_COMPILER_VAR_59;
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
char * ____BAH_COMPILER_VAR_60 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(cm);
unsigned int strLen_1 = strlen(" 2>/dev/null");
;                            
            ____BAH_COMPILER_VAR_60 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_60+currStrOff, cm, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_60+currStrOff, " 2>/dev/null", strLen_1);
            currStrOff += strLen_1;
        
        }cm = ____BAH_COMPILER_VAR_60;
}
else {
char * ____BAH_COMPILER_VAR_61 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(cm);
unsigned int strLen_1 = strlen(" 2>&1");
;                            
            ____BAH_COMPILER_VAR_61 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_61+currStrOff, cm, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_61+currStrOff, " 2>&1", strLen_1);
            currStrOff += strLen_1;
        
        }cm = ____BAH_COMPILER_VAR_61;
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
char * ____BAH_COMPILER_VAR_62 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(response);
unsigned int strLen_1 = strlen(buff);
;                            
            ____BAH_COMPILER_VAR_62 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_62+currStrOff, response, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_62+currStrOff, buff, strLen_1);
            currStrOff += strLen_1;
        
        }response = ____BAH_COMPILER_VAR_62;
res = fgets(buff,1023,this->handle);
};
this->status = pclose(this->handle);
arr->data=response;
arr->length=strlen(response);
return arr;
};
struct command command(char * s){
struct command ____BAH_COMPILER_VAR_63 = {};
____BAH_COMPILER_VAR_63.command= null;
____BAH_COMPILER_VAR_63.error = true;
____BAH_COMPILER_VAR_63.status = 0;
____BAH_COMPILER_VAR_63.input = null;
____BAH_COMPILER_VAR_63.handle= null;
#define cmd ____BAH_COMPILER_VAR_63
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
#define BAH_VERSION "v1.2 (build 96)"
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
unsigned int id;
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
struct Tok ____BAH_COMPILER_VAR_64 = {};
____BAH_COMPILER_VAR_64.cont = "";
____BAH_COMPILER_VAR_64.ogCont = "";
____BAH_COMPILER_VAR_64.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_64.pos = 0;
____BAH_COMPILER_VAR_64.line = 1;
____BAH_COMPILER_VAR_64.begLine = 1;
____BAH_COMPILER_VAR_64.bahType = "";
____BAH_COMPILER_VAR_64.isValue = false;
____BAH_COMPILER_VAR_64.isFunc = false;
____BAH_COMPILER_VAR_64.isOper = false;
____BAH_COMPILER_VAR_64.isEqual = false;
____BAH_COMPILER_VAR_64.pass = false;
____BAH_COMPILER_VAR_64.bahRef= null;
____BAH_COMPILER_VAR_64.parent= null;
#define t ____BAH_COMPILER_VAR_64
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
char * ____BAH_COMPILER_VAR_65 =null;
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
            ____BAH_COMPILER_VAR_65 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7);
            
                    memcpy(____BAH_COMPILER_VAR_65+currStrOff, "\e[1;31m[LEXER-ERROR]\e[0m ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_65+currStrOff, compilerState.currentFile, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_65+currStrOff, ":", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_65+currStrOff, lineStr, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_65+currStrOff, ":", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_65+currStrOff, posStr, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_65+currStrOff, "\n\e[0m\n", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_65+currStrOff, msg, strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_65);
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

        char ____BAH_COMPILER_VAR_66 = 0;
        for(int i=syntaxes->length-1; i!=-1;i--) {
            if (syntaxes->data[i] == c) {
                ____BAH_COMPILER_VAR_66=1;
                break;
            };
        }
        if ((____BAH_COMPILER_VAR_66==false)) {
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

        char ____BAH_COMPILER_VAR_67 = 0;
        for(int i=keywords->length-1; i!=-1;i--) {
            if (keywords->data[i] != 0 && strcmp(keywords->data[i], memstr) == 0) {
                ____BAH_COMPILER_VAR_67=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_67) {
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
char * ____BAH_COMPILER_VAR_68 =splitStringBefore(*n,".");struct string res = string(____BAH_COMPILER_VAR_68);
return res;
}
if (string__count(n,"->")) {
char * ____BAH_COMPILER_VAR_69 =splitStringBefore(*n,"->");struct string res = string(____BAH_COMPILER_VAR_69);
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
struct structMemb* ____BAH_COMPILER_VAR_70 = memoryAlloc(sizeof(struct structMemb));
____BAH_COMPILER_VAR_70->name = "";
____BAH_COMPILER_VAR_70->type = "";
____BAH_COMPILER_VAR_70->isConst = false;
____BAH_COMPILER_VAR_70->constVal = "";
____BAH_COMPILER_VAR_70->isArray = false;
____BAH_COMPILER_VAR_70->from = "";
____BAH_COMPILER_VAR_70->declScope= null;
____BAH_COMPILER_VAR_70->isGlobal = false;
____BAH_COMPILER_VAR_70->declRope= null;
____BAH_COMPILER_VAR_70->isReg = false;
____BAH_COMPILER_VAR_70->lastSet= null;
____BAH_COMPILER_VAR_70->isArg = false;
____BAH_COMPILER_VAR_70->def = "";
____BAH_COMPILER_VAR_70->isFn = false;
struct structMemb* sm = ____BAH_COMPILER_VAR_70;
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
char * ____BAH_COMPILER_VAR_71 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("__");
unsigned int strLen_1 = strlen(name);
unsigned int strLen_2 = strlen(s->name);
;                            
            ____BAH_COMPILER_VAR_71 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_71+currStrOff, s->name, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_71+currStrOff, "__", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_71+currStrOff, name, strLen_1);
            currStrOff += strLen_1;
        
        }struct func* fn = searchFunc(____BAH_COMPILER_VAR_71,elems,true);
if ((fn!=null)) {
return fn;
}
register long int i = 0;
for (; (i<len(s->members)); ++i) {
if ((strcmp(s->members->data[i]->name, name) == 0)) {
struct string ____BAH_COMPILER_VAR_72 =string(s->members->data[i]->type);fn = parseFnType(____BAH_COMPILER_VAR_72);
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
string__replace(&tp," ","");
if (string__hasPrefix(&tp,"[]")) {
string__trimLeft(&tp,2);
char * tpstr = string__str(&tp);
tp = getCType(tpstr,elems);
t = string__str(&tp);
char * ____BAH_COMPILER_VAR_73 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t);
unsigned int strLen_1 = strlen(")*");
unsigned int strLen_2 = strlen("array(");
;                            
            ____BAH_COMPILER_VAR_73 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_73+currStrOff, "array(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_73+currStrOff, t, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_73+currStrOff, ")*", strLen_1);
            currStrOff += strLen_1;
        
        }char * r = ____BAH_COMPILER_VAR_73;
return string(r);
}
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
char compTypeEquiv(char * a,char * b,char first){
if ((strcmp(a, "cpstring") == 0)&&strHasPrefix(b,"buffer:")) {
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
char * ____BAH_COMPILER_VAR_105 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s);
unsigned int strLen_1 = strlen(arr->data[i]);
;                            
            ____BAH_COMPILER_VAR_105 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_105+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_105+currStrOff, arr->data[i], strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_105;
i = i+1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_106 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s);
unsigned int strLen_1 = strlen(",\n");
;                            
            ____BAH_COMPILER_VAR_106 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_106+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_106+currStrOff, ",\n", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_106;
}
else {
char * ____BAH_COMPILER_VAR_107 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s);
unsigned int strLen_1 = strlen("\n");
;                            
            ____BAH_COMPILER_VAR_107 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_107+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_107+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_107;
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
char * ____BAH_COMPILER_VAR_108 =null;char * ____BAH_COMPILER_VAR_109 =toJson__inner(*ae,false,tabs);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_109);
;                            
            ____BAH_COMPILER_VAR_108 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_108+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_108+currStrOff, ____BAH_COMPILER_VAR_109, strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_108;
i = i+1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_110 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s);
unsigned int strLen_1 = strlen(",\n");
;                            
            ____BAH_COMPILER_VAR_110 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_110+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_110+currStrOff, ",\n", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_110;
}
else {
char * ____BAH_COMPILER_VAR_111 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s);
unsigned int strLen_1 = strlen("\n");
;                            
            ____BAH_COMPILER_VAR_111 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_111+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_111+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_111;
}
};
}
char * ____BAH_COMPILER_VAR_112 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s);
unsigned int strLen_1 = strlen("]");
;                            
            ____BAH_COMPILER_VAR_112 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_112+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_112+currStrOff, "]", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_112;
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
char * ____BAH_COMPILER_VAR_113 = name;
struct reflectElement ____BAH_COMPILER_VAR_114 = __reflect(____BAH_COMPILER_VAR_113, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, 0);
char * ____BAH_COMPILER_VAR_115 =null;char * ____BAH_COMPILER_VAR_116 =toJson(e);char * ____BAH_COMPILER_VAR_117 =intToStr(line);char * ____BAH_COMPILER_VAR_118 =toJson(____BAH_COMPILER_VAR_114);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_116);
unsigned int strLen_1 = strlen("\n    },\n    ");
unsigned int strLen_2 = strlen("\",\n        \"element\": ");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_117);
unsigned int strLen_4 = strlen(":");
unsigned int strLen_5 = strlen(compilerState.currentFile);
unsigned int strLen_6 = strlen(",\n        \"path\": \"");
unsigned int strLen_7 = strlen(____BAH_COMPILER_VAR_118);
unsigned int strLen_8 = strlen("\n    {\n        \"name\": ");
;                            
            ____BAH_COMPILER_VAR_115 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_115+currStrOff, "\n    {\n        \"name\": ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_115+currStrOff, ____BAH_COMPILER_VAR_118, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_115+currStrOff, ",\n        \"path\": \"", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_115+currStrOff, compilerState.currentFile, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_115+currStrOff, ":", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_115+currStrOff, ____BAH_COMPILER_VAR_117, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_115+currStrOff, "\",\n        \"element\": ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_115+currStrOff, ____BAH_COMPILER_VAR_116, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_115+currStrOff, "\n    },\n    ", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_119 =____BAH_COMPILER_VAR_115;println(____BAH_COMPILER_VAR_119);
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
        
        }char * ____BAH_COMPILER_VAR_128 =____BAH_COMPILER_VAR_122;println(____BAH_COMPILER_VAR_128);
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
struct variable* ____BAH_COMPILER_VAR_129 = v;
char ** ____BAH_COMPILER_VAR_131 = (char **)((char*)(____BAH_COMPILER_VAR_129) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_132 = __reflect(____BAH_COMPILER_VAR_131, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_133 = (char **)((char*)(____BAH_COMPILER_VAR_129) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_134 = __reflect(____BAH_COMPILER_VAR_133, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_135 = (char*)((char*)(____BAH_COMPILER_VAR_129) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_136 = __reflect(____BAH_COMPILER_VAR_135, sizeof(char), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_137 = (char **)((char*)(____BAH_COMPILER_VAR_129) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_138 = __reflect(____BAH_COMPILER_VAR_137, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_139 = (char*)((char*)(____BAH_COMPILER_VAR_129) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_140 = __reflect(____BAH_COMPILER_VAR_139, sizeof(char), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_141 = (char **)((char*)(____BAH_COMPILER_VAR_129) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_142 = __reflect(____BAH_COMPILER_VAR_141, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
void ** ____BAH_COMPILER_VAR_143 = (void **)((char*)(____BAH_COMPILER_VAR_129) + offsetof(struct variable, declScope));
struct reflectElement ____BAH_COMPILER_VAR_144 = __reflect(____BAH_COMPILER_VAR_143, sizeof(void *), "ptr", "declScope", 0, 0, 0, 0, offsetof(struct variable, declScope));
char* ____BAH_COMPILER_VAR_145 = (char*)((char*)(____BAH_COMPILER_VAR_129) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_146 = __reflect(____BAH_COMPILER_VAR_145, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));
struct rope** ____BAH_COMPILER_VAR_147 = (struct rope**)((char*)(____BAH_COMPILER_VAR_129) + offsetof(struct variable, declRope));
void ** ____BAH_COMPILER_VAR_149 = (void **)((char*)(____BAH_COMPILER_VAR_147) + offsetof(struct rope, left));
struct reflectElement ____BAH_COMPILER_VAR_150 = __reflect(____BAH_COMPILER_VAR_149, sizeof(void *), "ptr", "left", 0, 0, 0, 0, offsetof(struct rope, left));
void ** ____BAH_COMPILER_VAR_151 = (void **)((char*)(____BAH_COMPILER_VAR_147) + offsetof(struct rope, right));
struct reflectElement ____BAH_COMPILER_VAR_152 = __reflect(____BAH_COMPILER_VAR_151, sizeof(void *), "ptr", "right", 0, 0, 0, 0, offsetof(struct rope, right));
char ** ____BAH_COMPILER_VAR_153 = (char **)((char*)(____BAH_COMPILER_VAR_147) + offsetof(struct rope, str));
struct reflectElement ____BAH_COMPILER_VAR_154 = __reflect(____BAH_COMPILER_VAR_153, sizeof(char *), "cpstring", "str", 0, 0, 0, 0, offsetof(struct rope, str));
int* ____BAH_COMPILER_VAR_155 = (int*)((char*)(____BAH_COMPILER_VAR_147) + offsetof(struct rope, lCount));
struct reflectElement ____BAH_COMPILER_VAR_156 = __reflect(____BAH_COMPILER_VAR_155, sizeof(int), "int32", "lCount", 0, 0, 0, 0, offsetof(struct rope, lCount));
int* ____BAH_COMPILER_VAR_157 = (int*)((char*)(____BAH_COMPILER_VAR_147) + offsetof(struct rope, len));
struct reflectElement ____BAH_COMPILER_VAR_158 = __reflect(____BAH_COMPILER_VAR_157, sizeof(int), "int32", "len", 0, 0, 0, 0, offsetof(struct rope, len));
int* ____BAH_COMPILER_VAR_159 = (int*)((char*)(____BAH_COMPILER_VAR_147) + offsetof(struct rope, totalLen));
struct reflectElement ____BAH_COMPILER_VAR_160 = __reflect(____BAH_COMPILER_VAR_159, sizeof(int), "int32", "totalLen", 0, 0, 0, 0, offsetof(struct rope, totalLen));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_148 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_148->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_148->length = 6;
        ____BAH_COMPILER_VAR_148->data = memoryAlloc(____BAH_COMPILER_VAR_148->length * ____BAH_COMPILER_VAR_148->elemSize);
        ____BAH_COMPILER_VAR_148->data[0] = ____BAH_COMPILER_VAR_150;
____BAH_COMPILER_VAR_148->data[1] = ____BAH_COMPILER_VAR_152;
____BAH_COMPILER_VAR_148->data[2] = ____BAH_COMPILER_VAR_154;
____BAH_COMPILER_VAR_148->data[3] = ____BAH_COMPILER_VAR_156;
____BAH_COMPILER_VAR_148->data[4] = ____BAH_COMPILER_VAR_158;
____BAH_COMPILER_VAR_148->data[5] = ____BAH_COMPILER_VAR_160;
struct reflectElement ____BAH_COMPILER_VAR_161 = __reflect(____BAH_COMPILER_VAR_147, sizeof(struct rope), "rope*", "declRope", 0, 0, 1, ____BAH_COMPILER_VAR_148, offsetof(struct variable, declRope));
char* ____BAH_COMPILER_VAR_162 = (char*)((char*)(____BAH_COMPILER_VAR_129) + offsetof(struct variable, canBeReg));
struct reflectElement ____BAH_COMPILER_VAR_163 = __reflect(____BAH_COMPILER_VAR_162, sizeof(char), "bool", "canBeReg", 0, 0, 0, 0, offsetof(struct variable, canBeReg));
char* ____BAH_COMPILER_VAR_164 = (char*)((char*)(____BAH_COMPILER_VAR_129) + offsetof(struct variable, isReg));
struct reflectElement ____BAH_COMPILER_VAR_165 = __reflect(____BAH_COMPILER_VAR_164, sizeof(char), "bool", "isReg", 0, 0, 0, 0, offsetof(struct variable, isReg));
void ** ____BAH_COMPILER_VAR_166 = (void **)((char*)(____BAH_COMPILER_VAR_129) + offsetof(struct variable, lastSet));
struct reflectElement ____BAH_COMPILER_VAR_167 = __reflect(____BAH_COMPILER_VAR_166, sizeof(void *), "ptr", "lastSet", 0, 0, 0, 0, offsetof(struct variable, lastSet));
char* ____BAH_COMPILER_VAR_168 = (char*)((char*)(____BAH_COMPILER_VAR_129) + offsetof(struct variable, isArg));
struct reflectElement ____BAH_COMPILER_VAR_169 = __reflect(____BAH_COMPILER_VAR_168, sizeof(char), "bool", "isArg", 0, 0, 0, 0, offsetof(struct variable, isArg));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_130 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_130->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_130->length = 13;
        ____BAH_COMPILER_VAR_130->data = memoryAlloc(____BAH_COMPILER_VAR_130->length * ____BAH_COMPILER_VAR_130->elemSize);
        ____BAH_COMPILER_VAR_130->data[0] = ____BAH_COMPILER_VAR_132;
____BAH_COMPILER_VAR_130->data[1] = ____BAH_COMPILER_VAR_134;
____BAH_COMPILER_VAR_130->data[2] = ____BAH_COMPILER_VAR_136;
____BAH_COMPILER_VAR_130->data[3] = ____BAH_COMPILER_VAR_138;
____BAH_COMPILER_VAR_130->data[4] = ____BAH_COMPILER_VAR_140;
____BAH_COMPILER_VAR_130->data[5] = ____BAH_COMPILER_VAR_142;
____BAH_COMPILER_VAR_130->data[6] = ____BAH_COMPILER_VAR_144;
____BAH_COMPILER_VAR_130->data[7] = ____BAH_COMPILER_VAR_146;
____BAH_COMPILER_VAR_130->data[8] = ____BAH_COMPILER_VAR_161;
____BAH_COMPILER_VAR_130->data[9] = ____BAH_COMPILER_VAR_163;
____BAH_COMPILER_VAR_130->data[10] = ____BAH_COMPILER_VAR_165;
____BAH_COMPILER_VAR_130->data[11] = ____BAH_COMPILER_VAR_167;
____BAH_COMPILER_VAR_130->data[12] = ____BAH_COMPILER_VAR_169;
struct reflectElement ____BAH_COMPILER_VAR_170 = __reflect(____BAH_COMPILER_VAR_129, sizeof(struct variable), "variable*", "v", 0, 0, 1, ____BAH_COMPILER_VAR_130, 0);
debugPrint("var_end",line,____BAH_COMPILER_VAR_170);
}
i = i+1;
};
};
void throwErr(void * tp,char * format){
char * str = "";
char * info = "";
long int pos = 0;
if ((tp!=null)) {
struct fileMap ____BAH_COMPILER_VAR_171 = {};
____BAH_COMPILER_VAR_171.handle = -1;
____BAH_COMPILER_VAR_171.p= null;
#define fm ____BAH_COMPILER_VAR_171
char * fileSrcStr = fileMap__open(&fm,compilerState.currentFile);
struct Tok* t = tp;
struct string ffmt = string(format);
if ((strlen(t->ogCont)==0)) {
t->ogCont = t->cont;
}
char * ____BAH_COMPILER_VAR_172 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t->ogCont);
unsigned int strLen_1 = strlen("'");
unsigned int strLen_2 = strlen("'");
;                            
            ____BAH_COMPILER_VAR_172 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_172+currStrOff, "'", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_172+currStrOff, t->ogCont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_172+currStrOff, "'", strLen_1);
            currStrOff += strLen_1;
        
        }string__replace(&ffmt,"{TOKEN}",____BAH_COMPILER_VAR_172);
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
char * ____BAH_COMPILER_VAR_173 =null;char * ____BAH_COMPILER_VAR_174 =arrToStr(errCont);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_174);
unsigned int strLen_1 = strlen("\e[1;37m");
unsigned int strLen_2 = strlen("\e[1;31m");
;                            
            ____BAH_COMPILER_VAR_173 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_173+currStrOff, "\e[1;31m", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_173+currStrOff, ____BAH_COMPILER_VAR_174, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_173+currStrOff, "\e[1;37m", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_175 =____BAH_COMPILER_VAR_173;array(char)* errTk = strToArr(____BAH_COMPILER_VAR_175);
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
struct variable* searchVar(char * name,struct Elems* elems){
char * ogName = name;
struct string n = string(name);
string__replace(&n,"&","");
string__replace(&n,"*","");
if (string__hasSuffix(&n,"]")) {
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
struct variable* ____BAH_COMPILER_VAR_185 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_185->name = "";
____BAH_COMPILER_VAR_185->type = "";
____BAH_COMPILER_VAR_185->isConst = false;
____BAH_COMPILER_VAR_185->constVal = "";
____BAH_COMPILER_VAR_185->isArray = false;
____BAH_COMPILER_VAR_185->from = "";
____BAH_COMPILER_VAR_185->declScope= null;
____BAH_COMPILER_VAR_185->isGlobal = false;
____BAH_COMPILER_VAR_185->declRope= null;
____BAH_COMPILER_VAR_185->isReg = false;
____BAH_COMPILER_VAR_185->lastSet= null;
____BAH_COMPILER_VAR_185->isArg = false;
struct variable* nv = ____BAH_COMPILER_VAR_185;
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
struct variable* ____BAH_COMPILER_VAR_186 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_186->name = "";
____BAH_COMPILER_VAR_186->type = "";
____BAH_COMPILER_VAR_186->isConst = false;
____BAH_COMPILER_VAR_186->constVal = "";
____BAH_COMPILER_VAR_186->isArray = false;
____BAH_COMPILER_VAR_186->from = "";
____BAH_COMPILER_VAR_186->declScope= null;
____BAH_COMPILER_VAR_186->isGlobal = false;
____BAH_COMPILER_VAR_186->declRope= null;
____BAH_COMPILER_VAR_186->isReg = false;
____BAH_COMPILER_VAR_186->lastSet= null;
____BAH_COMPILER_VAR_186->isArg = false;
struct variable* nv = ____BAH_COMPILER_VAR_186;
nv->from = memb->from;
nv->name = memb->name;
nv->type = memb->type;
nv->declScope = v->declScope;
nv->name = ogName;
char * r = nv->type;
struct string tcc = string(ogName);
if (string__count(&tcc,"&")) {
char * ____BAH_COMPILER_VAR_187 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(r);
unsigned int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_187 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_187+currStrOff, r, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_187+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }r = ____BAH_COMPILER_VAR_187;
}
long int nbUnaries = string__count(&tcc,"*");
if ((nbUnaries>0)) {
struct string ct = string(r);
long int pointerLevel = string__count(&ct,"*");
if ((pointerLevel<nbUnaries)) {
char * ____BAH_COMPILER_VAR_188 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nv->name);
unsigned int strLen_1 = strlen(" because it is not pointer.");
unsigned int strLen_2 = strlen("Cannot use '*' on ");
;                            
            ____BAH_COMPILER_VAR_188 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_188+currStrOff, "Cannot use '*' on ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_188+currStrOff, nv->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_188+currStrOff, " because it is not pointer.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(null,____BAH_COMPILER_VAR_188);
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
____BAH_COMPILER_VAR_189->lastSet= null;
____BAH_COMPILER_VAR_189->isArg = false;
struct variable* nv = ____BAH_COMPILER_VAR_189;
nv->type = v->type;
nv->name = v->name;
nv->isConst = v->isConst;
nv->constVal = v->constVal;
nv->declScope = v->declScope;
char * r = nv->type;
struct string tcc = string(ogName);
if (string__count(&tcc,"&")) {
char * ____BAH_COMPILER_VAR_190 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(r);
unsigned int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_190 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_190+currStrOff, r, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_190+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }r = ____BAH_COMPILER_VAR_190;
}
long int nbUnaries = string__count(&tcc,"*");
if ((nbUnaries>0)) {
struct string ct = string(r);
long int pointerLevel = string__count(&ct,"*");
if ((pointerLevel<nbUnaries)) {
char * ____BAH_COMPILER_VAR_191 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(v->name);
unsigned int strLen_1 = strlen(" because it is not pointer.");
unsigned int strLen_2 = strlen("Cannot use '*' on ");
;                            
            ____BAH_COMPILER_VAR_191 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_191+currStrOff, "Cannot use '*' on ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_191+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_191+currStrOff, " because it is not pointer.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(null,____BAH_COMPILER_VAR_191);
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
____BAH_COMPILER_VAR_192->lastSet= null;
____BAH_COMPILER_VAR_192->isArg = false;
struct variable* nv = ____BAH_COMPILER_VAR_192;
nv->name = name;
nv->type = "function(";
register long int j = 0;
while ((j<len(fn->args))) {
struct variable* arg = fn->args->data[j];
char * ____BAH_COMPILER_VAR_193 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nv->type);
unsigned int strLen_1 = strlen(arg->type);
;                            
            ____BAH_COMPILER_VAR_193 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_193+currStrOff, nv->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_193+currStrOff, arg->type, strLen_1);
            currStrOff += strLen_1;
        
        }nv->type = ____BAH_COMPILER_VAR_193;
j = j+1;
if ((j<len(fn->args))) {
char * ____BAH_COMPILER_VAR_194 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nv->type);
unsigned int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_194 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_194+currStrOff, nv->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_194+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }nv->type = ____BAH_COMPILER_VAR_194;
}
};
fn->used = true;
char * ____BAH_COMPILER_VAR_195 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(")");
unsigned int strLen_1 = strlen(fn->returns->type);
unsigned int strLen_2 = strlen(nv->type);
;                            
            ____BAH_COMPILER_VAR_195 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_195+currStrOff, nv->type, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_195+currStrOff, ")", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_195+currStrOff, fn->returns->type, strLen_1);
            currStrOff += strLen_1;
        
        }nv->type = ____BAH_COMPILER_VAR_195;
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
string__replace(&cont,"&","");
string__replace(&cont,"*","");
char * ____BAH_COMPILER_VAR_196 =string__str(&cont);return getRealVar(____BAH_COMPILER_VAR_196,elems);
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
char * ____BAH_COMPILER_VAR_197 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(" ");
unsigned int strLen_1 = strlen(v->name);
unsigned int strLen_2 = strlen(t);
;                            
            ____BAH_COMPILER_VAR_197 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_197+currStrOff, t, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_197+currStrOff, " ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_197+currStrOff, v->name, strLen_1);
            currStrOff += strLen_1;
        
        }t = ____BAH_COMPILER_VAR_197;
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
struct func* ____BAH_COMPILER_VAR_198 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_198->name = "";
____BAH_COMPILER_VAR_198->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_198->args->length = 0;
            ____BAH_COMPILER_VAR_198->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_198->returns= null;
____BAH_COMPILER_VAR_198->isBinding = false;
____BAH_COMPILER_VAR_198->from = "";
____BAH_COMPILER_VAR_198->file = "";
____BAH_COMPILER_VAR_198->line = 1;
____BAH_COMPILER_VAR_198->isVar = false;
____BAH_COMPILER_VAR_198->used = false;
____BAH_COMPILER_VAR_198->code = null;
____BAH_COMPILER_VAR_198->isMut = false;
____BAH_COMPILER_VAR_198->isImported = false;
struct func* nf = ____BAH_COMPILER_VAR_198;
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
struct variable* ____BAH_COMPILER_VAR_199 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_199->name = "";
____BAH_COMPILER_VAR_199->type = "";
____BAH_COMPILER_VAR_199->isConst = false;
____BAH_COMPILER_VAR_199->constVal = "";
____BAH_COMPILER_VAR_199->isArray = false;
____BAH_COMPILER_VAR_199->from = "";
____BAH_COMPILER_VAR_199->declScope= null;
____BAH_COMPILER_VAR_199->isGlobal = false;
____BAH_COMPILER_VAR_199->declRope= null;
____BAH_COMPILER_VAR_199->isReg = false;
____BAH_COMPILER_VAR_199->lastSet= null;
____BAH_COMPILER_VAR_199->isArg = false;
struct variable* arg = ____BAH_COMPILER_VAR_199;
char * ____BAH_COMPILER_VAR_200 =null;char * ____BAH_COMPILER_VAR_201 =intToStr(len(nf->args));
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("arg_");
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_201);
;                            
            ____BAH_COMPILER_VAR_200 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_200+currStrOff, "arg_", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_200+currStrOff, ____BAH_COMPILER_VAR_201, strLen_1);
            currStrOff += strLen_1;
        
        }arg->name = ____BAH_COMPILER_VAR_200;
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
struct variable* ____BAH_COMPILER_VAR_202 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_202->name = "";
____BAH_COMPILER_VAR_202->type = "";
____BAH_COMPILER_VAR_202->isConst = false;
____BAH_COMPILER_VAR_202->constVal = "";
____BAH_COMPILER_VAR_202->isArray = false;
____BAH_COMPILER_VAR_202->from = "";
____BAH_COMPILER_VAR_202->declScope= null;
____BAH_COMPILER_VAR_202->isGlobal = false;
____BAH_COMPILER_VAR_202->declRope= null;
____BAH_COMPILER_VAR_202->isReg = false;
____BAH_COMPILER_VAR_202->lastSet= null;
____BAH_COMPILER_VAR_202->isArg = false;
nf->returns = ____BAH_COMPILER_VAR_202;
nf->returns->name = "_return";
nf->returns->type = arrToStr(memory);
return nf;
};
struct func* searchFunc(char * name,struct Elems* elems,char inclCurr){
char * ogName = name;
if ((strcmp(name, "noCheck") == 0)) {
struct func* ____BAH_COMPILER_VAR_203 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_203->name = "";
____BAH_COMPILER_VAR_203->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_203->args->length = 0;
            ____BAH_COMPILER_VAR_203->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_203->returns= null;
____BAH_COMPILER_VAR_203->isBinding = false;
____BAH_COMPILER_VAR_203->from = "";
____BAH_COMPILER_VAR_203->file = "";
____BAH_COMPILER_VAR_203->line = 1;
____BAH_COMPILER_VAR_203->isVar = false;
____BAH_COMPILER_VAR_203->used = false;
____BAH_COMPILER_VAR_203->code = null;
____BAH_COMPILER_VAR_203->isMut = false;
____BAH_COMPILER_VAR_203->isImported = false;
struct func* fn = ____BAH_COMPILER_VAR_203;
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
struct cStruct* s = searchStruct(v->type,elems);
char * ____BAH_COMPILER_VAR_204 =string__str(&fnName);struct structMemb* memb = searchStructMemb(____BAH_COMPILER_VAR_204,s,elems);
name = fnName.content;
char * ____BAH_COMPILER_VAR_205 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("__");
unsigned int strLen_1 = strlen(name);
unsigned int strLen_2 = strlen(memb->from);
;                            
            ____BAH_COMPILER_VAR_205 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_205+currStrOff, memb->from, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_205+currStrOff, "__", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_205+currStrOff, name, strLen_1);
            currStrOff += strLen_1;
        
        }name = ____BAH_COMPILER_VAR_205;
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
struct func* ____BAH_COMPILER_VAR_206 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_206->name = "";
____BAH_COMPILER_VAR_206->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_206->args->length = 0;
            ____BAH_COMPILER_VAR_206->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_206->returns= null;
____BAH_COMPILER_VAR_206->isBinding = false;
____BAH_COMPILER_VAR_206->from = "";
____BAH_COMPILER_VAR_206->file = "";
____BAH_COMPILER_VAR_206->line = 1;
____BAH_COMPILER_VAR_206->isVar = false;
____BAH_COMPILER_VAR_206->used = false;
____BAH_COMPILER_VAR_206->code = null;
____BAH_COMPILER_VAR_206->isMut = false;
____BAH_COMPILER_VAR_206->isImported = false;
struct func* nf = ____BAH_COMPILER_VAR_206;
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
struct string ____BAH_COMPILER_VAR_207 =string(t->cont);char * fnName = splitStringBefore(____BAH_COMPILER_VAR_207,"(");
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
char * ____BAH_COMPILER_VAR_208 =null;
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
            ____BAH_COMPILER_VAR_208 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_208+currStrOff, code, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_208+currStrOff, v->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_208+currStrOff, sep, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_208+currStrOff, m->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_208+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_208+currStrOff, m->def, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_208+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_208;
declared = true;
}
if ((string__hasPrefix(&cmpt,"[]")==1)) {
string__trimLeft(&cmpt,2);
char * cmptstr = string__str(&cmpt);
struct string elemCType = getCType(cmptstr,elems);
char * elemCTypeStr = string__str(&elemCType);
char * ____BAH_COMPILER_VAR_209 =null;
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
            ____BAH_COMPILER_VAR_209 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13+strLen_14+strLen_15+strLen_16);
            
                    memcpy(____BAH_COMPILER_VAR_209+currStrOff, code, strLen_16);
                    currStrOff += strLen_16;
                    
                    memcpy(____BAH_COMPILER_VAR_209+currStrOff, v->name, strLen_15);
                    currStrOff += strLen_15;
                    
                    memcpy(____BAH_COMPILER_VAR_209+currStrOff, sep, strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_209+currStrOff, m->name, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_209+currStrOff, " = memoryAlloc(sizeof(array(", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_209+currStrOff, elemCTypeStr, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_209+currStrOff, ")));\n            ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_209+currStrOff, v->name, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_209+currStrOff, sep, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_209+currStrOff, m->name, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_209+currStrOff, "->length = 0;\n            ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_209+currStrOff, v->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_209+currStrOff, sep, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_209+currStrOff, m->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_209+currStrOff, "->elemSize = sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_209+currStrOff, elemCTypeStr, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_209+currStrOff, ");\n            ", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_209;
declared = true;
}
else if ((string__hasPrefix(&cmpt,"map:")==1)) {
string__trimLeft(&cmpt,4);
char * ____BAH_COMPILER_VAR_210 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(m->name);
unsigned int strLen_1 = strlen(" = mapWrapper();\n");
unsigned int strLen_2 = strlen(sep);
unsigned int strLen_3 = strlen(v->name);
;                            
            ____BAH_COMPILER_VAR_210 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_210+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_210+currStrOff, sep, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_210+currStrOff, m->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_210+currStrOff, " = mapWrapper();\n", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_211 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_210);
;                            
            ____BAH_COMPILER_VAR_211 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_211+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_211+currStrOff, ____BAH_COMPILER_VAR_210, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_211;
declared = true;
}
else if ((string__hasPrefix(&cmpt,"chan:")==1)) {
string__trimLeft(&cmpt,5);
char * ____BAH_COMPILER_VAR_212 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(m->name);
unsigned int strLen_1 = strlen(" = channel();\n");
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
        
            memcpy(____BAH_COMPILER_VAR_212+currStrOff, " = channel();\n", strLen_1);
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
if (isRCPpointerType(m->type)&&(declared==false)) {
char * ____BAH_COMPILER_VAR_214 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(m->name);
unsigned int strLen_1 = strlen("= null;\n");
unsigned int strLen_2 = strlen(sep);
unsigned int strLen_3 = strlen(v->name);
unsigned int strLen_4 = strlen(code);
;                            
            ____BAH_COMPILER_VAR_214 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_214+currStrOff, code, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_214+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_214+currStrOff, sep, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_214+currStrOff, m->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_214+currStrOff, "= null;\n", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_214;
}
i = i+1;
};
if ((s->isBinding==false)) {
long int found = 0;
i = 0;
for (; (i<len(s->methods)); ++i) {
struct func* m = s->methods->data[i];
if ((strcmp(m->name, "_init") == 0)) {
char * ____BAH_COMPILER_VAR_215 =null;
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
            ____BAH_COMPILER_VAR_215 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_215+currStrOff, v->name, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_215+currStrOff, sep, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_215+currStrOff, m->name, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_215+currStrOff, "(", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_215+currStrOff, amp, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_215+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_215+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_216 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(NEXT_LINE);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_215);
;                            
            ____BAH_COMPILER_VAR_216 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_216+currStrOff, NEXT_LINE, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_216+currStrOff, ____BAH_COMPILER_VAR_215, strLen_1);
            currStrOff += strLen_1;
        
        }NEXT_LINE = ____BAH_COMPILER_VAR_216;
++found;
}
else if ((strcmp(m->name, "_end") == 0)) {
if ((strcmp(sep, "->") == 0)) {
char * ____BAH_COMPILER_VAR_217 =null;
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
            ____BAH_COMPILER_VAR_217 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_217+currStrOff, "memoryOnEnd(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_217+currStrOff, v->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_217+currStrOff, ", ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_217+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_217+currStrOff, sep, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_217+currStrOff, m->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_217+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_218 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_217);
;                            
            ____BAH_COMPILER_VAR_218 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_218+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_218+currStrOff, ____BAH_COMPILER_VAR_217, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_218;
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
char * ____BAH_COMPILER_VAR_219 =null;char * ____BAH_COMPILER_VAR_220 =intToStr(NB_COMP_VAR);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("____BAH_COMPILER_VAR_");
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_220);
;                            
            ____BAH_COMPILER_VAR_219 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_219+currStrOff, "____BAH_COMPILER_VAR_", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_219+currStrOff, ____BAH_COMPILER_VAR_220, strLen_1);
            currStrOff += strLen_1;
        
        }char * name = ____BAH_COMPILER_VAR_219;
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
char * ____BAH_COMPILER_VAR_221 =null;char * ____BAH_COMPILER_VAR_222 =pathToVarName(compilerState.currentFile);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(name);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_222);
;                            
            ____BAH_COMPILER_VAR_221 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_221+currStrOff, name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_221+currStrOff, ____BAH_COMPILER_VAR_222, strLen_1);
            currStrOff += strLen_1;
        
        }name = ____BAH_COMPILER_VAR_221;
}
char * evals = "";
char * ____BAH_COMPILER_VAR_223 =null;char * ____BAH_COMPILER_VAR_224 =intToStr(len(compilerState.evals));
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_224);
unsigned int strLen_1 = strlen("] = {");
unsigned int strLen_2 = strlen("volatile struct __eval_binding __tmp__evals_bindings[");
;                            
            ____BAH_COMPILER_VAR_223 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_223+currStrOff, "volatile struct __eval_binding __tmp__evals_bindings[", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_223+currStrOff, ____BAH_COMPILER_VAR_224, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_223+currStrOff, "] = {", strLen_1);
            currStrOff += strLen_1;
        
        }char * evalsTMPDecl = ____BAH_COMPILER_VAR_223;
register long int i = 0;
for (; (i<len(compilerState.evals)); ++i) {
char * e = compilerState.evals->data[i];
char * ____BAH_COMPILER_VAR_225 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(e);
unsigned int strLen_1 = strlen("\n        }");
unsigned int strLen_2 = strlen("\",\n            .evalFn = __Bah_eval_");
unsigned int strLen_3 = strlen(e);
unsigned int strLen_4 = strlen("{\n            .name = \"");
;                            
            ____BAH_COMPILER_VAR_225 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_225+currStrOff, "{\n            .name = \"", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_225+currStrOff, e, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_225+currStrOff, "\",\n            .evalFn = __Bah_eval_", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_225+currStrOff, e, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_225+currStrOff, "\n        }", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_226 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(evalsTMPDecl);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_225);
;                            
            ____BAH_COMPILER_VAR_226 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_226+currStrOff, evalsTMPDecl, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_226+currStrOff, ____BAH_COMPILER_VAR_225, strLen_1);
            currStrOff += strLen_1;
        
        }evalsTMPDecl = ____BAH_COMPILER_VAR_226;
if ((i+1!=len(compilerState.evals))) {
char * ____BAH_COMPILER_VAR_227 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(evalsTMPDecl);
unsigned int strLen_1 = strlen(",\n");
;                            
            ____BAH_COMPILER_VAR_227 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_227+currStrOff, evalsTMPDecl, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_227+currStrOff, ",\n", strLen_1);
            currStrOff += strLen_1;
        
        }evalsTMPDecl = ____BAH_COMPILER_VAR_227;
}
else {
char * ____BAH_COMPILER_VAR_228 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(evalsTMPDecl);
unsigned int strLen_1 = strlen("};");
;                            
            ____BAH_COMPILER_VAR_228 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_228+currStrOff, evalsTMPDecl, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_228+currStrOff, "};", strLen_1);
            currStrOff += strLen_1;
        
        }evalsTMPDecl = ____BAH_COMPILER_VAR_228;
}
};
if ((len(compilerState.evals)!=0)) {
char * ____BAH_COMPILER_VAR_229 =null;char * ____BAH_COMPILER_VAR_230 =intToStr(len(compilerState.evals));
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_230);
unsigned int strLen_1 = strlen(";");
unsigned int strLen_2 = strlen("__evals_bindings = __tmp__evals_bindings; __evals_length = ");
;                            
            ____BAH_COMPILER_VAR_229 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_229+currStrOff, "__evals_bindings = __tmp__evals_bindings; __evals_length = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_229+currStrOff, ____BAH_COMPILER_VAR_230, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_229+currStrOff, ";", strLen_1);
            currStrOff += strLen_1;
        
        }evals = ____BAH_COMPILER_VAR_229;
}
else {
evalsTMPDecl = "";
}
char * ____BAH_COMPILER_VAR_231 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(name);
unsigned int strLen_1 = strlen("() {\n        ");
unsigned int strLen_2 = strlen("\n    void __attribute__((optimize(\"O0\"))) ");
unsigned int strLen_3 = strlen(evalsTMPDecl);
unsigned int strLen_4 = strlen("\n    ");
;                            
            ____BAH_COMPILER_VAR_231 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_231+currStrOff, "\n    ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_231+currStrOff, evalsTMPDecl, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_231+currStrOff, "\n    void __attribute__((optimize(\"O0\"))) ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_231+currStrOff, name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_231+currStrOff, "() {\n        ", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_232 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(evals);
unsigned int strLen_1 = strlen("\n    };\n    ");
unsigned int strLen_2 = strlen("\n        ");
;                            
            ____BAH_COMPILER_VAR_232 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_232+currStrOff, "\n        ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_232+currStrOff, evals, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_232+currStrOff, "\n    };\n    ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope__add(rope(____BAH_COMPILER_VAR_231), rope__add(INIT, rope(____BAH_COMPILER_VAR_232))));
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
char * ____BAH_COMPILER_VAR_233 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(v->name);
unsigned int strLen_1 = strlen(");\n");
unsigned int strLen_2 = strlen("RCP_decr(");
;                            
            ____BAH_COMPILER_VAR_233 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_233+currStrOff, "RCP_decr(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_233+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_233+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }r = rope__add(r, rope(____BAH_COMPILER_VAR_233));
}
else if (strHasPrefix(v->type,"chan:")) {
char * ____BAH_COMPILER_VAR_234 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(v->name);
unsigned int strLen_1 = strlen(");\n");
unsigned int strLen_2 = strlen("RCP_decr(");
;                            
            ____BAH_COMPILER_VAR_234 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_234+currStrOff, "RCP_decr(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_234+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_234+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }r = rope__add(r, rope(____BAH_COMPILER_VAR_234));
}
else {
if (strHasPrefix(v->type,"map:")) {
struct variable* ____BAH_COMPILER_VAR_235 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_235->name = "";
____BAH_COMPILER_VAR_235->type = "";
____BAH_COMPILER_VAR_235->isConst = false;
____BAH_COMPILER_VAR_235->constVal = "";
____BAH_COMPILER_VAR_235->isArray = false;
____BAH_COMPILER_VAR_235->from = "";
____BAH_COMPILER_VAR_235->declScope= null;
____BAH_COMPILER_VAR_235->isGlobal = false;
____BAH_COMPILER_VAR_235->declRope= null;
____BAH_COMPILER_VAR_235->isReg = false;
____BAH_COMPILER_VAR_235->lastSet= null;
____BAH_COMPILER_VAR_235->isArg = false;
struct variable* nv = ____BAH_COMPILER_VAR_235;
*nv = *v;
v = nv;
v->type = "mapWrapper*";
}
char isPointer = isRCPpointerType(v->type);
struct cStruct* s = searchStruct(v->type,elems);
if ((s!=null)&&(s->isBinding==false)) {
if ((isPointer==true)) {
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
char * ____BAH_COMPILER_VAR_237 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(v->name);
unsigned int strLen_1 = strlen("), 1);\n");
unsigned int strLen_2 = strlen(", sizeof(");
unsigned int strLen_3 = strlen(v->name);
unsigned int strLen_4 = strlen("RCP_scanStack(&");
;                            
            ____BAH_COMPILER_VAR_237 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_237+currStrOff, "RCP_scanStack(&", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_237+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_237+currStrOff, ", sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_237+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_237+currStrOff, "), 1);\n", strLen_1);
            currStrOff += strLen_1;
        
        }r = rope__add(r, rope(____BAH_COMPILER_VAR_237));
}
}
else if ((isPointer==true)) {
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
}
return r;
};
struct rope* incrVar(struct variable* v,struct Elems* elems){
if ((strCount(v->name,"*")>0)) {
return rope("");
}
struct cStruct* s = searchStruct(v->type,elems);
if ((s!=null)&&(isRCPpointerType(v->type)==false)&&(s->isBinding==false)) {
char * ____BAH_COMPILER_VAR_239 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(v->name);
unsigned int strLen_1 = strlen("), 0);");
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
        
            memcpy(____BAH_COMPILER_VAR_239+currStrOff, "), 0);", strLen_1);
            currStrOff += strLen_1;
        
        }return rope(____BAH_COMPILER_VAR_239);
}
char * ____BAH_COMPILER_VAR_240 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(v->name);
unsigned int strLen_1 = strlen(");");
unsigned int strLen_2 = strlen("RCP_incr(");
;                            
            ____BAH_COMPILER_VAR_240 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_240+currStrOff, "RCP_incr(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_240+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_240+currStrOff, ");", strLen_1);
            currStrOff += strLen_1;
        
        }return rope(____BAH_COMPILER_VAR_240);
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
char * ____BAH_COMPILER_VAR_241 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(elems->defined->data[i]);
unsigned int strLen_1 = strlen("\n");
unsigned int strLen_2 = strlen("\n#undef ");
;                            
            ____BAH_COMPILER_VAR_241 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_241+currStrOff, "\n#undef ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_241+currStrOff, elems->defined->data[i], strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_241+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_241));
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
void endRCPscopeLeaky(struct Elems* elems,struct variable* excl){
if ((RCPavailable()==false)) {
removeDefs(elems);
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
removeDefs(elems);
};
char * registerRCPvar(char * t,char * c,struct Elems* elems){
struct variable* ____BAH_COMPILER_VAR_242 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_242->name = "";
____BAH_COMPILER_VAR_242->type = "";
____BAH_COMPILER_VAR_242->isConst = false;
____BAH_COMPILER_VAR_242->constVal = "";
____BAH_COMPILER_VAR_242->isArray = false;
____BAH_COMPILER_VAR_242->from = "";
____BAH_COMPILER_VAR_242->declScope= null;
____BAH_COMPILER_VAR_242->isGlobal = false;
____BAH_COMPILER_VAR_242->declRope= null;
____BAH_COMPILER_VAR_242->isReg = false;
____BAH_COMPILER_VAR_242->lastSet= null;
____BAH_COMPILER_VAR_242->isArg = false;
struct variable* av = ____BAH_COMPILER_VAR_242;
av->type = t;
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
char * ____BAH_COMPILER_VAR_243 =null;char * ____BAH_COMPILER_VAR_244 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(c);
unsigned int strLen_1 = strlen(";");
unsigned int strLen_2 = strlen(" =");
unsigned int strLen_3 = strlen(av->name);
unsigned int strLen_4 = strlen(" ");
unsigned int strLen_5 = strlen(____BAH_COMPILER_VAR_244);
;                            
            ____BAH_COMPILER_VAR_243 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_243+currStrOff, ____BAH_COMPILER_VAR_244, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_243+currStrOff, " ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_243+currStrOff, av->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_243+currStrOff, " =", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_243+currStrOff, c, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_243+currStrOff, ";", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_243));
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

        char ____BAH_COMPILER_VAR_245 = 0;
        for(int i=noVOfns->length-1; i!=-1;i--) {
            if (noVOfns->data[i] != 0 && strcmp(noVOfns->data[i], currentFn->name) == 0) {
                ____BAH_COMPILER_VAR_245=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_245) {
return false;
}
}
return true;
};
struct verboseOutVar verboseOutTransformVar(struct variable* v,char * cont,struct Elems* elems){
struct verboseOutVar ____BAH_COMPILER_VAR_246 = {};
____BAH_COMPILER_VAR_246.markup= null;
____BAH_COMPILER_VAR_246.content= null;
#define rv ____BAH_COMPILER_VAR_246
char * ogCont = cont;
if ((strcmp(v->type, "cpstring") == 0)) {
char * ____BAH_COMPILER_VAR_247 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(cont);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen("__Bah_safe_string(");
;                            
            ____BAH_COMPILER_VAR_247 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_247+currStrOff, "__Bah_safe_string(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_247+currStrOff, cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_247+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }cont = ____BAH_COMPILER_VAR_247;
}
char * ____BAH_COMPILER_VAR_248 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(", ");
unsigned int strLen_1 = strlen(cont);
;                            
            ____BAH_COMPILER_VAR_248 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_248+currStrOff, ", ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_248+currStrOff, cont, strLen_1);
            currStrOff += strLen_1;
        
        }cont = ____BAH_COMPILER_VAR_248;
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
char * ____BAH_COMPILER_VAR_249 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ASCII_RESET);
unsigned int strLen_1 = strlen("{");
;                            
            ____BAH_COMPILER_VAR_249 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_249+currStrOff, ASCII_RESET, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_249+currStrOff, "{", strLen_1);
            currStrOff += strLen_1;
        
        }ct = ____BAH_COMPILER_VAR_249;
cont = "";
register long int i = 0;
for (; (i<len(s->members)); ++i) {
struct variable* m = s->members->data[i];
char * ____BAH_COMPILER_VAR_250 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(".");
unsigned int strLen_1 = strlen(m->name);
unsigned int strLen_2 = strlen(")");
unsigned int strLen_3 = strlen(ogCont);
unsigned int strLen_4 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_250 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_250+currStrOff, "(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_250+currStrOff, ogCont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_250+currStrOff, ")", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_250+currStrOff, ".", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_250+currStrOff, m->name, strLen_1);
            currStrOff += strLen_1;
        
        }struct verboseOutVar mv = verboseOutTransformVar(m,____BAH_COMPILER_VAR_250,elems);
if ((i!=0)) {
char * ____BAH_COMPILER_VAR_251 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ct);
unsigned int strLen_1 = strlen(", ");
;                            
            ____BAH_COMPILER_VAR_251 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_251+currStrOff, ct, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_251+currStrOff, ", ", strLen_1);
            currStrOff += strLen_1;
        
        }ct = ____BAH_COMPILER_VAR_251;
}
char * ____BAH_COMPILER_VAR_252 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ct);
unsigned int strLen_1 = strlen(mv.markup);
;                            
            ____BAH_COMPILER_VAR_252 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_252+currStrOff, ct, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_252+currStrOff, mv.markup, strLen_1);
            currStrOff += strLen_1;
        
        }ct = ____BAH_COMPILER_VAR_252;
char * ____BAH_COMPILER_VAR_253 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(cont);
unsigned int strLen_1 = strlen(mv.content);
;                            
            ____BAH_COMPILER_VAR_253 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_253+currStrOff, cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_253+currStrOff, mv.content, strLen_1);
            currStrOff += strLen_1;
        
        }cont = ____BAH_COMPILER_VAR_253;
};
char * ____BAH_COMPILER_VAR_254 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ct);
unsigned int strLen_1 = strlen("}");
;                            
            ____BAH_COMPILER_VAR_254 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_254+currStrOff, ct, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_254+currStrOff, "}", strLen_1);
            currStrOff += strLen_1;
        
        }ct = ____BAH_COMPILER_VAR_254;
}
}
char * ____BAH_COMPILER_VAR_255 =null;
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
            ____BAH_COMPILER_VAR_255 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_255+currStrOff, ASCII_BLUE, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_255+currStrOff, v->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_255+currStrOff, ASCII_RESET, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_255+currStrOff, " = ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_255+currStrOff, ASCII_MAGENTA, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_255+currStrOff, ct, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_255+currStrOff, ASCII_RESET, strLen_1);
            currStrOff += strLen_1;
        
        }rv.markup = ____BAH_COMPILER_VAR_255;
rv.content = cont;
return rv;

#undef rv
};
struct verboseOutVar verboseOutTransformTok(struct Tok* t,struct Elems* elems){
if ((t->type==TOKEN_TYPE_VAR)&&(t->isOper==false)) {
struct variable* v = searchVar(t->cont,elems);
if ((v==null)) {
return verboseOutTransformVar(v,t->cont,elems);
}
}
struct variable ____BAH_COMPILER_VAR_256 = {};
____BAH_COMPILER_VAR_256.name = "";
____BAH_COMPILER_VAR_256.type = "";
____BAH_COMPILER_VAR_256.isConst = false;
____BAH_COMPILER_VAR_256.constVal = "";
____BAH_COMPILER_VAR_256.isArray = false;
____BAH_COMPILER_VAR_256.from = "";
____BAH_COMPILER_VAR_256.declScope= null;
____BAH_COMPILER_VAR_256.isGlobal = false;
____BAH_COMPILER_VAR_256.declRope= null;
____BAH_COMPILER_VAR_256.isReg = false;
____BAH_COMPILER_VAR_256.lastSet= null;
____BAH_COMPILER_VAR_256.isArg = false;
____BAH_COMPILER_VAR_256.name = "(value)";
____BAH_COMPILER_VAR_256.type = getTypeFromToken(t,true,elems);
#define v ____BAH_COMPILER_VAR_256
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
char * ____BAH_COMPILER_VAR_257 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnArgs);
unsigned int strLen_1 = strlen(", ");
;                            
            ____BAH_COMPILER_VAR_257 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_257+currStrOff, fnArgs, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_257+currStrOff, ", ", strLen_1);
            currStrOff += strLen_1;
        
        }fnArgs = ____BAH_COMPILER_VAR_257;
}
struct Tok t = args->data[j];
struct verboseOutVar v = verboseOutTransformVar(a,t.cont,elems);
char * ____BAH_COMPILER_VAR_258 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnArgs);
unsigned int strLen_1 = strlen(v.markup);
;                            
            ____BAH_COMPILER_VAR_258 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_258+currStrOff, fnArgs, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_258+currStrOff, v.markup, strLen_1);
            currStrOff += strLen_1;
        
        }fnArgs = ____BAH_COMPILER_VAR_258;
char * ____BAH_COMPILER_VAR_259 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnArgsValues);
unsigned int strLen_1 = strlen(v.content);
;                            
            ____BAH_COMPILER_VAR_259 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_259+currStrOff, fnArgsValues, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_259+currStrOff, v.content, strLen_1);
            currStrOff += strLen_1;
        
        }fnArgsValues = ____BAH_COMPILER_VAR_259;
};
char * ____BAH_COMPILER_VAR_260 =null;char * ____BAH_COMPILER_VAR_261 =intToStr(lineNb);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(":");
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_261);
unsigned int strLen_2 = strlen(compilerState.currentFile);
;                            
            ____BAH_COMPILER_VAR_260 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_260+currStrOff, compilerState.currentFile, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_260+currStrOff, ":", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_260+currStrOff, ____BAH_COMPILER_VAR_261, strLen_1);
            currStrOff += strLen_1;
        
        }char * line = ____BAH_COMPILER_VAR_260;
char * ____BAH_COMPILER_VAR_262 =null;
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
            ____BAH_COMPILER_VAR_262 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12);
            
                    memcpy(____BAH_COMPILER_VAR_262+currStrOff, "\n    //Verbose Runtime\n        printf(\"[VO] calling: ", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_262+currStrOff, nameColor, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_262+currStrOff, fn->name, strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_262+currStrOff, ASCII_RESET, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_262+currStrOff, "(", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_262+currStrOff, fnArgs, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_262+currStrOff, ") -> ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_262+currStrOff, ASCII_GREEN, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_262+currStrOff, line, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_262+currStrOff, ASCII_RESET, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_262+currStrOff, "\\n\"", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_262+currStrOff, fnArgsValues, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_262+currStrOff, ");\n    //\n    ", strLen_1);
            currStrOff += strLen_1;
        
        }struct rope* verboseOut = rope(____BAH_COMPILER_VAR_262);
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
char * ____BAH_COMPILER_VAR_263 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(pvo.content);
unsigned int strLen_1 = strlen(nvo.content);
;                            
            ____BAH_COMPILER_VAR_263 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_263+currStrOff, pvo.content, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_263+currStrOff, nvo.content, strLen_1);
            currStrOff += strLen_1;
        
        }char * values = ____BAH_COMPILER_VAR_263;
char * ____BAH_COMPILER_VAR_264 =null;char * ____BAH_COMPILER_VAR_265 =intToStr(lineNb);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(":");
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_265);
unsigned int strLen_2 = strlen(compilerState.currentFile);
;                            
            ____BAH_COMPILER_VAR_264 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_264+currStrOff, compilerState.currentFile, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_264+currStrOff, ":", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_264+currStrOff, ____BAH_COMPILER_VAR_265, strLen_1);
            currStrOff += strLen_1;
        
        }char * line = ____BAH_COMPILER_VAR_264;
char * ____BAH_COMPILER_VAR_266 =null;
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
            ____BAH_COMPILER_VAR_266 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10);
            
                    memcpy(____BAH_COMPILER_VAR_266+currStrOff, "\n    //Verbose Runtime\n        printf(\"[VO]    oper: ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_266+currStrOff, pvo.markup, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_266+currStrOff, " AND ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_266+currStrOff, nvo.markup, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_266+currStrOff, " -> ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_266+currStrOff, ASCII_GREEN, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_266+currStrOff, line, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_266+currStrOff, ASCII_RESET, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_266+currStrOff, "\\n\"", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_266+currStrOff, values, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_266+currStrOff, ");\n    //\n    ", strLen_1);
            currStrOff += strLen_1;
        
        }struct rope* verboseOut = rope(____BAH_COMPILER_VAR_266);
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
array(char *)* files;
};
array(struct cacheFile*)* cache;
void readCache(){
struct fileStream ____BAH_COMPILER_VAR_267 = {};
____BAH_COMPILER_VAR_267.handle= null;
____BAH_COMPILER_VAR_267.name= null;
#define fs ____BAH_COMPILER_VAR_267
char * ____BAH_COMPILER_VAR_268 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(BAH_DIR);
unsigned int strLen_1 = strlen("cache/cache.json");
;                            
            ____BAH_COMPILER_VAR_268 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_268+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_268+currStrOff, "cache/cache.json", strLen_1);
            currStrOff += strLen_1;
        
        }fileStream__open(&fs,____BAH_COMPILER_VAR_268,"r");
if ((fileStream__isValid(&fs)==0)) {
char * ____BAH_COMPILER_VAR_269 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(BAH_DIR);
unsigned int strLen_1 = strlen("cache");
;                            
            ____BAH_COMPILER_VAR_269 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_269+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_269+currStrOff, "cache", strLen_1);
            currStrOff += strLen_1;
        
        }mkdir(____BAH_COMPILER_VAR_269,S_IRWXU);
char * ____BAH_COMPILER_VAR_270 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(BAH_DIR);
unsigned int strLen_1 = strlen("cache/cache.json");
;                            
            ____BAH_COMPILER_VAR_270 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_270+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_270+currStrOff, "cache/cache.json", strLen_1);
            currStrOff += strLen_1;
        
        }fileStream__createFile(&fs,____BAH_COMPILER_VAR_270);
return;
}
char * ____BAH_COMPILER_VAR_271 =fileStream__readContent(&fs);struct jsonElement* j = parseJson(____BAH_COMPILER_VAR_271);
fileStream__close(&fs);
array(struct cacheFile**)* ____BAH_COMPILER_VAR_272 = &cache;
struct cacheFile*** ____BAH_COMPILER_VAR_273 = 0;
char ** ____BAH_COMPILER_VAR_275 = (char **)((char*)(____BAH_COMPILER_VAR_273) + offsetof(struct cacheFile, file));
struct reflectElement ____BAH_COMPILER_VAR_276 = __reflect(____BAH_COMPILER_VAR_275, sizeof(char *), "cpstring", "file", 0, 0, 0, 0, offsetof(struct cacheFile, file));
long int* ____BAH_COMPILER_VAR_277 = (long int*)((char*)(____BAH_COMPILER_VAR_273) + offsetof(struct cacheFile, last));
struct reflectElement ____BAH_COMPILER_VAR_278 = __reflect(____BAH_COMPILER_VAR_277, sizeof(long int), "int", "last", 0, 0, 0, 0, offsetof(struct cacheFile, last));
char ** ____BAH_COMPILER_VAR_279 = (char **)((char*)(____BAH_COMPILER_VAR_273) + offsetof(struct cacheFile, ver));
struct reflectElement ____BAH_COMPILER_VAR_280 = __reflect(____BAH_COMPILER_VAR_279, sizeof(char *), "cpstring", "ver", 0, 0, 0, 0, offsetof(struct cacheFile, ver));
long int* ____BAH_COMPILER_VAR_281 = (long int*)((char*)(____BAH_COMPILER_VAR_273) + offsetof(struct cacheFile, date));
struct reflectElement ____BAH_COMPILER_VAR_282 = __reflect(____BAH_COMPILER_VAR_281, sizeof(long int), "int", "date", 0, 0, 0, 0, offsetof(struct cacheFile, date));
long int* ____BAH_COMPILER_VAR_283 = (long int*)((char*)(____BAH_COMPILER_VAR_273) + offsetof(struct cacheFile, mem));
struct reflectElement ____BAH_COMPILER_VAR_284 = __reflect(____BAH_COMPILER_VAR_283, sizeof(long int), "int", "mem", 0, 0, 0, 0, offsetof(struct cacheFile, mem));
array(char *)** ____BAH_COMPILER_VAR_285 = (array(char *)**)((char*)(____BAH_COMPILER_VAR_273) + offsetof(struct cacheFile, files));
char ** ____BAH_COMPILER_VAR_286 = 0;
struct reflectElement ____BAH_COMPILER_VAR_287 = __reflect(____BAH_COMPILER_VAR_286, sizeof(char *), "cpstring", "", 0, 0, 0, 0, 0);

        struct reflectElement ____BAH_COMPILER_VAR_288 = ____BAH_COMPILER_VAR_287;
        struct reflectElement ____BAH_COMPILER_VAR_289 = __reflect(____BAH_COMPILER_VAR_285, sizeof(array(char *)*), "[]cpstring", "files", 1, &____BAH_COMPILER_VAR_288, 0, 0, offsetof(struct cacheFile, files));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_274 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_274->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_274->length = 6;
        ____BAH_COMPILER_VAR_274->data = memoryAlloc(____BAH_COMPILER_VAR_274->length * ____BAH_COMPILER_VAR_274->elemSize);
        ____BAH_COMPILER_VAR_274->data[0] = ____BAH_COMPILER_VAR_276;
____BAH_COMPILER_VAR_274->data[1] = ____BAH_COMPILER_VAR_278;
____BAH_COMPILER_VAR_274->data[2] = ____BAH_COMPILER_VAR_280;
____BAH_COMPILER_VAR_274->data[3] = ____BAH_COMPILER_VAR_282;
____BAH_COMPILER_VAR_274->data[4] = ____BAH_COMPILER_VAR_284;
____BAH_COMPILER_VAR_274->data[5] = ____BAH_COMPILER_VAR_289;
struct reflectElement ____BAH_COMPILER_VAR_290 = __reflect(____BAH_COMPILER_VAR_273, sizeof(struct cacheFile), "cacheFile**", "", 0, 0, 1, ____BAH_COMPILER_VAR_274, 0);

        struct reflectElement ____BAH_COMPILER_VAR_291 = ____BAH_COMPILER_VAR_290;
        struct reflectElement ____BAH_COMPILER_VAR_292 = __reflect(____BAH_COMPILER_VAR_272, sizeof(array(struct cacheFile**)*), "[]cacheFile**", "&cache", 1, &____BAH_COMPILER_VAR_291, 0, 0, 0);
jsonElement__scan(j,____BAH_COMPILER_VAR_292);
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
struct cacheFile* ____BAH_COMPILER_VAR_293 = memoryAlloc(sizeof(struct cacheFile));
____BAH_COMPILER_VAR_293->file= null;
____BAH_COMPILER_VAR_293->ver= null;
____BAH_COMPILER_VAR_293->files = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_293->files->length = 0;
            ____BAH_COMPILER_VAR_293->files->elemSize = sizeof(char *);
            struct cacheFile* c = ____BAH_COMPILER_VAR_293;
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
struct fileStream ____BAH_COMPILER_VAR_294 = {};
____BAH_COMPILER_VAR_294.handle= null;
____BAH_COMPILER_VAR_294.name= null;
#define fs ____BAH_COMPILER_VAR_294
char * ____BAH_COMPILER_VAR_295 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(BAH_DIR);
unsigned int strLen_1 = strlen("cache/cache.json");
;                            
            ____BAH_COMPILER_VAR_295 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_295+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_295+currStrOff, "cache/cache.json", strLen_1);
            currStrOff += strLen_1;
        
        }fileStream__open(&fs,____BAH_COMPILER_VAR_295,"w");
array(struct cacheFile*)* ____BAH_COMPILER_VAR_296 = cache;
struct cacheFile** ____BAH_COMPILER_VAR_297 = 0;
char ** ____BAH_COMPILER_VAR_299 = (char **)((char*)(____BAH_COMPILER_VAR_297) + offsetof(struct cacheFile, file));
struct reflectElement ____BAH_COMPILER_VAR_300 = __reflect(____BAH_COMPILER_VAR_299, sizeof(char *), "cpstring", "file", 0, 0, 0, 0, offsetof(struct cacheFile, file));
long int* ____BAH_COMPILER_VAR_301 = (long int*)((char*)(____BAH_COMPILER_VAR_297) + offsetof(struct cacheFile, last));
struct reflectElement ____BAH_COMPILER_VAR_302 = __reflect(____BAH_COMPILER_VAR_301, sizeof(long int), "int", "last", 0, 0, 0, 0, offsetof(struct cacheFile, last));
char ** ____BAH_COMPILER_VAR_303 = (char **)((char*)(____BAH_COMPILER_VAR_297) + offsetof(struct cacheFile, ver));
struct reflectElement ____BAH_COMPILER_VAR_304 = __reflect(____BAH_COMPILER_VAR_303, sizeof(char *), "cpstring", "ver", 0, 0, 0, 0, offsetof(struct cacheFile, ver));
long int* ____BAH_COMPILER_VAR_305 = (long int*)((char*)(____BAH_COMPILER_VAR_297) + offsetof(struct cacheFile, date));
struct reflectElement ____BAH_COMPILER_VAR_306 = __reflect(____BAH_COMPILER_VAR_305, sizeof(long int), "int", "date", 0, 0, 0, 0, offsetof(struct cacheFile, date));
long int* ____BAH_COMPILER_VAR_307 = (long int*)((char*)(____BAH_COMPILER_VAR_297) + offsetof(struct cacheFile, mem));
struct reflectElement ____BAH_COMPILER_VAR_308 = __reflect(____BAH_COMPILER_VAR_307, sizeof(long int), "int", "mem", 0, 0, 0, 0, offsetof(struct cacheFile, mem));
array(char *)** ____BAH_COMPILER_VAR_309 = (array(char *)**)((char*)(____BAH_COMPILER_VAR_297) + offsetof(struct cacheFile, files));
char ** ____BAH_COMPILER_VAR_310 = 0;
struct reflectElement ____BAH_COMPILER_VAR_311 = __reflect(____BAH_COMPILER_VAR_310, sizeof(char *), "cpstring", "", 0, 0, 0, 0, 0);

        struct reflectElement ____BAH_COMPILER_VAR_312 = ____BAH_COMPILER_VAR_311;
        struct reflectElement ____BAH_COMPILER_VAR_313 = __reflect(____BAH_COMPILER_VAR_309, sizeof(array(char *)*), "[]cpstring", "files", 1, &____BAH_COMPILER_VAR_312, 0, 0, offsetof(struct cacheFile, files));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_298 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_298->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_298->length = 6;
        ____BAH_COMPILER_VAR_298->data = memoryAlloc(____BAH_COMPILER_VAR_298->length * ____BAH_COMPILER_VAR_298->elemSize);
        ____BAH_COMPILER_VAR_298->data[0] = ____BAH_COMPILER_VAR_300;
____BAH_COMPILER_VAR_298->data[1] = ____BAH_COMPILER_VAR_302;
____BAH_COMPILER_VAR_298->data[2] = ____BAH_COMPILER_VAR_304;
____BAH_COMPILER_VAR_298->data[3] = ____BAH_COMPILER_VAR_306;
____BAH_COMPILER_VAR_298->data[4] = ____BAH_COMPILER_VAR_308;
____BAH_COMPILER_VAR_298->data[5] = ____BAH_COMPILER_VAR_313;
struct reflectElement ____BAH_COMPILER_VAR_314 = __reflect(____BAH_COMPILER_VAR_297, sizeof(struct cacheFile), "cacheFile*", "", 0, 0, 1, ____BAH_COMPILER_VAR_298, 0);

        struct reflectElement ____BAH_COMPILER_VAR_315 = ____BAH_COMPILER_VAR_314;
        struct reflectElement ____BAH_COMPILER_VAR_316 = __reflect(____BAH_COMPILER_VAR_296, sizeof(array(struct cacheFile*)*), "[]cacheFile*", "cache", 1, &____BAH_COMPILER_VAR_315, 0, 0, 0);
char * ____BAH_COMPILER_VAR_317 =toJson(____BAH_COMPILER_VAR_316);fileStream__writeFile(&fs,____BAH_COMPILER_VAR_317);
fileStream__close(&fs);

#undef fs
};
char isValidCacheFile(struct cacheFile* cf){
if ((cf==null)||(cf->last!=getLastModified(cf->file))) {
return false;
}
char * ____BAH_COMPILER_VAR_318 =null;char * ____BAH_COMPILER_VAR_319 =intToStr(cf->mem);char * ____BAH_COMPILER_VAR_320 =pathToVarName(cf->file);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_319);
unsigned int strLen_1 = strlen(".o.o");
unsigned int strLen_2 = strlen(____BAH_COMPILER_VAR_320);
unsigned int strLen_3 = strlen("cache/");
unsigned int strLen_4 = strlen(BAH_DIR);
;                            
            ____BAH_COMPILER_VAR_318 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_318+currStrOff, BAH_DIR, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_318+currStrOff, "cache/", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_318+currStrOff, ____BAH_COMPILER_VAR_320, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_318+currStrOff, ____BAH_COMPILER_VAR_319, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_318+currStrOff, ".o.o", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_321 =____BAH_COMPILER_VAR_318;if ((fileExists(____BAH_COMPILER_VAR_321)==0)) {
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

                struct string ____BAH_COMPILER_VAR_322 = getCType(v->type,elems);
                char * ____BAH_COMPILER_VAR_323 =null;char * ____BAH_COMPILER_VAR_324 =string__str(&____BAH_COMPILER_VAR_322);
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
unsigned int strLen_10 = strlen(____BAH_COMPILER_VAR_324);
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
            ____BAH_COMPILER_VAR_323 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13+strLen_14+strLen_15+strLen_16+strLen_17+strLen_18+strLen_19+strLen_20+strLen_21+strLen_22+strLen_23+strLen_24+strLen_25+strLen_26+strLen_27);
            
                    memcpy(____BAH_COMPILER_VAR_323+currStrOff, "\n    {\n        unsigned long nLength = ", strLen_27);
                    currStrOff += strLen_27;
                    
                    memcpy(____BAH_COMPILER_VAR_323+currStrOff, nLengthStr, strLen_26);
                    currStrOff += strLen_26;
                    
                    memcpy(____BAH_COMPILER_VAR_323+currStrOff, ";\n        if (nLength >= ", strLen_25);
                    currStrOff += strLen_25;
                    
                    memcpy(____BAH_COMPILER_VAR_323+currStrOff, nstr, strLen_24);
                    currStrOff += strLen_24;
                    
                    memcpy(____BAH_COMPILER_VAR_323+currStrOff, "->length) {\n            if (nLength >= ", strLen_23);
                    currStrOff += strLen_23;
                    
                    memcpy(____BAH_COMPILER_VAR_323+currStrOff, nstr, strLen_22);
                    currStrOff += strLen_22;
                    
                    memcpy(____BAH_COMPILER_VAR_323+currStrOff, "->realLength) {\n                if (", strLen_21);
                    currStrOff += strLen_21;
                    
                    memcpy(____BAH_COMPILER_VAR_323+currStrOff, nstr, strLen_20);
                    currStrOff += strLen_20;
                    
                    memcpy(____BAH_COMPILER_VAR_323+currStrOff, "->realLength != 0) {\n                    ", strLen_19);
                    currStrOff += strLen_19;
                    
                    memcpy(____BAH_COMPILER_VAR_323+currStrOff, nstr, strLen_18);
                    currStrOff += strLen_18;
                    
                    memcpy(____BAH_COMPILER_VAR_323+currStrOff, "->realLength *= 2;\n                } else {\n                    ", strLen_17);
                    currStrOff += strLen_17;
                    
                    memcpy(____BAH_COMPILER_VAR_323+currStrOff, nstr, strLen_16);
                    currStrOff += strLen_16;
                    
                    memcpy(____BAH_COMPILER_VAR_323+currStrOff, "->realLength = 50;\n                }\n                void * newPtr = memoryRealloc(", strLen_15);
                    currStrOff += strLen_15;
                    
                    memcpy(____BAH_COMPILER_VAR_323+currStrOff, nstr, strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_323+currStrOff, "->data, (", strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_323+currStrOff, nstr, strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_323+currStrOff, "->realLength)*sizeof(", strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_323+currStrOff, ____BAH_COMPILER_VAR_324, strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_323+currStrOff, "));\n                ", strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_323+currStrOff, nstr, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_323+currStrOff, "->data = newPtr;\n            }\n            ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_323+currStrOff, val, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_323+currStrOff, ";\n            ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_323+currStrOff, nstr, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_323+currStrOff, "->length = nLength+1;\n        } else {\n            ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_323+currStrOff, preVal, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_323+currStrOff, val, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_323+currStrOff, ";\n        }\n    }\n    ", strLen_1);
            currStrOff += strLen_1;
        
        }return ____BAH_COMPILER_VAR_323;
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

                struct string ____BAH_COMPILER_VAR_325 = string(v->name);
                if ((isRCPpointerType(v->type)==false)&&(strcmp(v->type, "reflectElement") != 0)&&(string__hasPrefix(&____BAH_COMPILER_VAR_325,"____BAH_COMPILER_VAR_")==false)) {
struct cStruct* s = searchStruct(v->type,elems);
if ((s!=null)) {
char * ____BAH_COMPILER_VAR_326 =null;
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
            ____BAH_COMPILER_VAR_326 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_326+currStrOff, "in \e[1;37m", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_326+currStrOff, currentFn->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_326+currStrOff, "()\e[0m: argument \e[1;37m", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_326+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_326+currStrOff, "\e[0m (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_326+currStrOff, v->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_326+currStrOff, ") could be passed by reference.", strLen_1);
            currStrOff += strLen_1;
        
        }throwWarningLine(____BAH_COMPILER_VAR_326,currentFn->line);
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
char * ____BAH_COMPILER_VAR_327 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t.cont);
unsigned int strLen_1 = strlen("'");
unsigned int strLen_2 = strlen(" '");
unsigned int strLen_3 = strlen(cont);
;                            
            ____BAH_COMPILER_VAR_327 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_327+currStrOff, cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_327+currStrOff, " '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_327+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_327+currStrOff, "'", strLen_1);
            currStrOff += strLen_1;
        
        }cont = ____BAH_COMPILER_VAR_327;
++i;
};
println(cont);
};
struct Elems* dupElems(struct Elems* elems){
struct Elems* ____BAH_COMPILER_VAR_328 = memoryAlloc(sizeof(struct Elems));
____BAH_COMPILER_VAR_328->vars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_328->vars->length = 0;
            ____BAH_COMPILER_VAR_328->vars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_328->structs = memoryAlloc(sizeof(array(struct cStruct*)));
            ____BAH_COMPILER_VAR_328->structs->length = 0;
            ____BAH_COMPILER_VAR_328->structs->elemSize = sizeof(struct cStruct*);
            ____BAH_COMPILER_VAR_328->types = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_328->types->length = 0;
            ____BAH_COMPILER_VAR_328->types->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_328->fns = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_328->fns->length = 0;
            ____BAH_COMPILER_VAR_328->fns->elemSize = sizeof(struct func*);
            ____BAH_COMPILER_VAR_328->defined = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_328->defined->length = 0;
            ____BAH_COMPILER_VAR_328->defined->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_328->parent= null;
struct Elems* nElems = ____BAH_COMPILER_VAR_328;
nElems->parent = elems;
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
char * ____BAH_COMPILER_VAR_329 =string__str(&tc);struct string cCast = getCType(____BAH_COMPILER_VAR_329,elems);
char * cCastStr = string__str(&cCast);
char * ____BAH_COMPILER_VAR_330 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(")");
unsigned int strLen_1 = strlen(nnnt.cont);
unsigned int strLen_2 = strlen(cCastStr);
unsigned int strLen_3 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_330 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_330+currStrOff, "(", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_330+currStrOff, cCastStr, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_330+currStrOff, ")", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_330+currStrOff, nnnt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }nnnt.cont = ____BAH_COMPILER_VAR_330;

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
char * ____BAH_COMPILER_VAR_331 =__STR(f);array(char)* p = strAsArr(____BAH_COMPILER_VAR_331);
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

        char ____BAH_COMPILER_VAR_332 = 0;
        for(int i=compilerState.includes->length-1; i!=-1;i--) {
            if (compilerState.includes->data[i] != 0 && strcmp(compilerState.includes->data[i], ccstr) == 0) {
                ____BAH_COMPILER_VAR_332=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_332) {
return true;
}
struct fileMap ____BAH_COMPILER_VAR_333 = {};
____BAH_COMPILER_VAR_333.handle = -1;
____BAH_COMPILER_VAR_333.p= null;
#define fm ____BAH_COMPILER_VAR_333
char * ____BAH_COMPILER_VAR_334 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(BAH_DIR);
unsigned int strLen_1 = strlen(ccstr);
;                            
            ____BAH_COMPILER_VAR_334 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_334+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_334+currStrOff, ccstr, strLen_1);
            currStrOff += strLen_1;
        
        }char * fileName = ____BAH_COMPILER_VAR_334;
char isBahDir = true;
char * f = fileMap__open(&fm,fileName);
if ((fileMap__isValid(&fm)==0)) {
char * ____BAH_COMPILER_VAR_335 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(compilerState.currentDir);
unsigned int strLen_1 = strlen(ccstr);
;                            
            ____BAH_COMPILER_VAR_335 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_335+currStrOff, compilerState.currentDir, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_335+currStrOff, ccstr, strLen_1);
            currStrOff += strLen_1;
        
        }fileName = absPath(____BAH_COMPILER_VAR_335);
f = fileMap__open(&fm,fileName);
isBahDir = false;
if ((fileMap__isValid(&fm)==0)) {
return false;
}
}
char * oDir = compilerState.currentDir;
if ((isBahDir==false)) {
char * ____BAH_COMPILER_VAR_336 =null;char * ____BAH_COMPILER_VAR_337 =getDirFromFile(ccstr);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(compilerState.currentDir);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_337);
;                            
            ____BAH_COMPILER_VAR_336 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_336+currStrOff, compilerState.currentDir, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_336+currStrOff, ____BAH_COMPILER_VAR_337, strLen_1);
            currStrOff += strLen_1;
        
        }compilerState.currentDir = ____BAH_COMPILER_VAR_336;
}
else {
char * ____BAH_COMPILER_VAR_338 =null;char * ____BAH_COMPILER_VAR_339 =getDirFromFile(ccstr);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(BAH_DIR);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_339);
;                            
            ____BAH_COMPILER_VAR_338 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_338+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_338+currStrOff, ____BAH_COMPILER_VAR_339, strLen_1);
            currStrOff += strLen_1;
        
        }compilerState.currentDir = ____BAH_COMPILER_VAR_338;
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
char * ____BAH_COMPILER_VAR_340 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ccstr);
unsigned int strLen_1 = strlen("' not recognized.");
unsigned int strLen_2 = strlen("File '");
;                            
            ____BAH_COMPILER_VAR_340 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_340+currStrOff, "File '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_340+currStrOff, ccstr, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_340+currStrOff, "' not recognized.", strLen_1);
            currStrOff += strLen_1;
        
        }__BAH_panic(____BAH_COMPILER_VAR_340,"/home/alois/Documents/bah-bah/src/parser.bah:243");
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
if ((isValidCacheFile(cf)==false)) {
setCurrentPath(compilerState.currentDir);
char * verboseCC = "";
if ((flags__isSet(&flags,"verboseCC")==1)) {
verboseCC = "-verboseCC";
}
char * ____BAH_COMPILER_VAR_341 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fn);
unsigned int strLen_1 = strlen("...");
unsigned int strLen_2 = strlen("compilling: ");
;                            
            ____BAH_COMPILER_VAR_341 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_341+currStrOff, "compilling: ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_341+currStrOff, fn, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_341+currStrOff, "...", strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_341);
char * ____BAH_COMPILER_VAR_342 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(" -o ");
unsigned int strLen_1 = strlen(oName);
unsigned int strLen_2 = strlen(verboseCC);
unsigned int strLen_3 = strlen(" -object ");
unsigned int strLen_4 = strlen(rcp);
unsigned int strLen_5 = strlen(" ");
unsigned int strLen_6 = strlen(fn);
unsigned int strLen_7 = strlen(" ");
unsigned int strLen_8 = strlen(execName);
;                            
            ____BAH_COMPILER_VAR_342 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_342+currStrOff, execName, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_342+currStrOff, " ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_342+currStrOff, fn, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_342+currStrOff, " ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_342+currStrOff, rcp, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_342+currStrOff, " -object ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_342+currStrOff, verboseCC, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_342+currStrOff, " -o ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_342+currStrOff, oName, strLen_1);
            currStrOff += strLen_1;
        
        }struct command cmd = command(____BAH_COMPILER_VAR_342);
char * res = command__run(&cmd);
char * ____BAH_COMPILER_VAR_343 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("done: ");
unsigned int strLen_1 = strlen(fn);
;                            
            ____BAH_COMPILER_VAR_343 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_343+currStrOff, "done: ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_343+currStrOff, fn, strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_343);
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

        char ____BAH_COMPILER_VAR_344 = true;
        channel__sendAny(done, &____BAH_COMPILER_VAR_344, sizeof(____BAH_COMPILER_VAR_344));
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

        char ____BAH_COMPILER_VAR_345 = 0;
        for(int i=compilerState.includes->length-1; i!=-1;i--) {
            if (compilerState.includes->data[i] != 0 && strcmp(compilerState.includes->data[i], string__str(&fileName)) == 0) {
                ____BAH_COMPILER_VAR_345=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_345) {
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
char * ____BAH_COMPILER_VAR_346 =string__str(&fileName);char * fn = absPath(____BAH_COMPILER_VAR_346);
if (((void *)fn==null)) {
char * ____BAH_COMPILER_VAR_347 =null;char * ____BAH_COMPILER_VAR_348 =string__str(&fileName);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(BAH_DIR);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_348);
;                            
            ____BAH_COMPILER_VAR_347 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_347+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_347+currStrOff, ____BAH_COMPILER_VAR_348, strLen_1);
            currStrOff += strLen_1;
        
        }fn = absPath(____BAH_COMPILER_VAR_347);
if (((void *)fn==null)) {
throwErr(&strt,"Unknown file {TOKEN}.");
}
}
char * of = compilerState.currentFile;
char * od = compilerState.currentDir;
compilerState.currentFile = fn;
compilerState.currentDir = getDirFromFile(fn);
struct fileStream ____BAH_COMPILER_VAR_349 = {};
____BAH_COMPILER_VAR_349.handle= null;
____BAH_COMPILER_VAR_349.name= null;
#define fs ____BAH_COMPILER_VAR_349
fileStream__open(&fs,fn,"r");
char * f = fileStream__readContent(&fs);
fileStream__close(&fs);
array(struct Tok)* tokens = lexer(f);
char osod = shouldOnlyDecl;
shouldOnlyDecl = true;
char oiso = isSubObject;
isSubObject = true;
char * ____BAH_COMPILER_VAR_350 =null;char * ____BAH_COMPILER_VAR_351 =intToStr(RCPlevel);char * ____BAH_COMPILER_VAR_352 =pathToVarName(fn);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_351);
unsigned int strLen_1 = strlen(".o");
unsigned int strLen_2 = strlen(____BAH_COMPILER_VAR_352);
unsigned int strLen_3 = strlen("cache/");
unsigned int strLen_4 = strlen(BAH_DIR);
;                            
            ____BAH_COMPILER_VAR_350 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_350+currStrOff, BAH_DIR, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_350+currStrOff, "cache/", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_350+currStrOff, ____BAH_COMPILER_VAR_352, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_350+currStrOff, ____BAH_COMPILER_VAR_351, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_350+currStrOff, ".o", strLen_1);
            currStrOff += strLen_1;
        
        }char * oName = ____BAH_COMPILER_VAR_350;
char * ____BAH_COMPILER_VAR_353 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(oName);
unsigned int strLen_1 = strlen(".o");
unsigned int strLen_2 = strlen("w ");
;                            
            ____BAH_COMPILER_VAR_353 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_353+currStrOff, "w ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_353+currStrOff, oName, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_353+currStrOff, ".o", strLen_1);
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
            compilerState.cLibs->data[len(compilerState.cLibs)] = ____BAH_COMPILER_VAR_353;
            compilerState.cLibs->length = nLength+1;
        } else {
            compilerState.cLibs->data[len(compilerState.cLibs)] = ____BAH_COMPILER_VAR_353;
        }
    }
    ;
struct channel * done = channel();

    void ____BAH_COMPILER_VAR_354(struct {
char * fn;
char * oName;
struct channel * done;
}* args) {
        parallelObjCompile(args->fn, args->oName, args->done);
    };
    {
        struct {
char * fn;
char * oName;
struct channel * done;
} ____BAH_COMPILER_VAR_355 = {fn,oName,done};
        pthread_t id;
        GC_pthread_create(&id, 0, ____BAH_COMPILER_VAR_354, &____BAH_COMPILER_VAR_355);
    }; 
    
    parseLines(tokens,elems);
char ok = *(char*)channel__receive(done);
char * ____BAH_COMPILER_VAR_356 =null;char * ____BAH_COMPILER_VAR_357 =pathToVarName(fn);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_357);
unsigned int strLen_1 = strlen("();\n");
unsigned int strLen_2 = strlen("__BAH_init");
;                            
            ____BAH_COMPILER_VAR_356 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_356+currStrOff, "__BAH_init", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_356+currStrOff, ____BAH_COMPILER_VAR_357, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_356+currStrOff, "();\n", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_358 =____BAH_COMPILER_VAR_356;INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_358));
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
char * ____BAH_COMPILER_VAR_359 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(sc);
unsigned int strLen_1 = strlen("\n");
unsigned int strLen_2 = strlen("#include ");
;                            
            ____BAH_COMPILER_VAR_359 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_359+currStrOff, "#include ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_359+currStrOff, sc, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_359+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_359));

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
struct Tok ____BAH_COMPILER_VAR_360 = {};
____BAH_COMPILER_VAR_360.cont = "";
____BAH_COMPILER_VAR_360.ogCont = "";
____BAH_COMPILER_VAR_360.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_360.pos = 0;
____BAH_COMPILER_VAR_360.line = 1;
____BAH_COMPILER_VAR_360.begLine = 1;
____BAH_COMPILER_VAR_360.bahType = "";
____BAH_COMPILER_VAR_360.isValue = false;
____BAH_COMPILER_VAR_360.isFunc = false;
____BAH_COMPILER_VAR_360.isOper = false;
____BAH_COMPILER_VAR_360.isEqual = false;
____BAH_COMPILER_VAR_360.pass = false;
____BAH_COMPILER_VAR_360.bahRef= null;
____BAH_COMPILER_VAR_360.parent= null;
____BAH_COMPILER_VAR_360.cont = "";
#define nt ____BAH_COMPILER_VAR_360
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
struct variable* ____BAH_COMPILER_VAR_361 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_361->name = "";
____BAH_COMPILER_VAR_361->type = "";
____BAH_COMPILER_VAR_361->isConst = false;
____BAH_COMPILER_VAR_361->constVal = "";
____BAH_COMPILER_VAR_361->isArray = false;
____BAH_COMPILER_VAR_361->from = "";
____BAH_COMPILER_VAR_361->declScope= null;
____BAH_COMPILER_VAR_361->isGlobal = false;
____BAH_COMPILER_VAR_361->declRope= null;
____BAH_COMPILER_VAR_361->isReg = false;
____BAH_COMPILER_VAR_361->lastSet= null;
____BAH_COMPILER_VAR_361->isArg = false;
struct variable* tmpV = ____BAH_COMPILER_VAR_361;
tmpV->name = t.cont;
char * ____BAH_COMPILER_VAR_362 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s->name);
unsigned int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_362 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_362+currStrOff, s->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_362+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }tmpV->type = ____BAH_COMPILER_VAR_362;
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
char * ____BAH_COMPILER_VAR_363 =null;char * ____BAH_COMPILER_VAR_364 =declareStructMethods(tmpV,s,elems);char * ____BAH_COMPILER_VAR_365 =string__str(&structType);char * ____BAH_COMPILER_VAR_366 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("));\n");
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_364);
unsigned int strLen_2 = strlen(____BAH_COMPILER_VAR_365);
unsigned int strLen_3 = strlen(" = memoryAlloc(sizeof(");
unsigned int strLen_4 = strlen(t.cont);
unsigned int strLen_5 = strlen(" ");
unsigned int strLen_6 = strlen(____BAH_COMPILER_VAR_366);
;                            
            ____BAH_COMPILER_VAR_363 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_363+currStrOff, ____BAH_COMPILER_VAR_366, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_363+currStrOff, " ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_363+currStrOff, t.cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_363+currStrOff, " = memoryAlloc(sizeof(", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_363+currStrOff, ____BAH_COMPILER_VAR_365, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_363+currStrOff, "));\n", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_363+currStrOff, ____BAH_COMPILER_VAR_364, strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_363));

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
struct variable* ____BAH_COMPILER_VAR_367 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_367->name = "";
____BAH_COMPILER_VAR_367->type = "";
____BAH_COMPILER_VAR_367->isConst = false;
____BAH_COMPILER_VAR_367->constVal = "";
____BAH_COMPILER_VAR_367->isArray = false;
____BAH_COMPILER_VAR_367->from = "";
____BAH_COMPILER_VAR_367->declScope= null;
____BAH_COMPILER_VAR_367->isGlobal = false;
____BAH_COMPILER_VAR_367->declRope= null;
____BAH_COMPILER_VAR_367->isReg = false;
____BAH_COMPILER_VAR_367->lastSet= null;
____BAH_COMPILER_VAR_367->isArg = false;
struct variable* tmpV = ____BAH_COMPILER_VAR_367;
tmpV->name = rvn;
if ((isHeap==true)) {
char * ____BAH_COMPILER_VAR_368 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s->name);
unsigned int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_368 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_368+currStrOff, s->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_368+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }tmpV->type = ____BAH_COMPILER_VAR_368;

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
char * ____BAH_COMPILER_VAR_369 =string__str(&rst);struct string structType = string(____BAH_COMPILER_VAR_369);
string__trimRight(&structType,1);
char * ____BAH_COMPILER_VAR_370 =null;char * ____BAH_COMPILER_VAR_371 =declareStructMethods(tmpV,s,elems);char * ____BAH_COMPILER_VAR_372 =string__str(&structType);char * ____BAH_COMPILER_VAR_373 =string__str(&rst);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("));\n");
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_371);
unsigned int strLen_2 = strlen(____BAH_COMPILER_VAR_372);
unsigned int strLen_3 = strlen(" = memoryAlloc(sizeof(");
unsigned int strLen_4 = strlen(rvn);
unsigned int strLen_5 = strlen(" ");
unsigned int strLen_6 = strlen(____BAH_COMPILER_VAR_373);
;                            
            ____BAH_COMPILER_VAR_370 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_370+currStrOff, ____BAH_COMPILER_VAR_373, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_370+currStrOff, " ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_370+currStrOff, rvn, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_370+currStrOff, " = memoryAlloc(sizeof(", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_370+currStrOff, ____BAH_COMPILER_VAR_372, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_370+currStrOff, "));\n", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_370+currStrOff, ____BAH_COMPILER_VAR_371, strLen_1);
            currStrOff += strLen_1;
        
        }r = rope(____BAH_COMPILER_VAR_370);
}
else {
char * ____BAH_COMPILER_VAR_374 =null;char * ____BAH_COMPILER_VAR_375 =declareStructMethods(tmpV,s,elems);char * ____BAH_COMPILER_VAR_376 =string__str(&rst);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(" = {};\n");
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_375);
unsigned int strLen_2 = strlen(rvn);
unsigned int strLen_3 = strlen(" ");
unsigned int strLen_4 = strlen(____BAH_COMPILER_VAR_376);
;                            
            ____BAH_COMPILER_VAR_374 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_374+currStrOff, ____BAH_COMPILER_VAR_376, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_374+currStrOff, " ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_374+currStrOff, rvn, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_374+currStrOff, " = {};\n", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_374+currStrOff, ____BAH_COMPILER_VAR_375, strLen_1);
            currStrOff += strLen_1;
        
        }r = rope(____BAH_COMPILER_VAR_374);
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
char * ____BAH_COMPILER_VAR_377 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(m->type);
unsigned int strLen_1 = strlen("'.");
unsigned int strLen_2 = strlen(") as '");
unsigned int strLen_3 = strlen(vlt);
unsigned int strLen_4 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_377 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_377+currStrOff, "Cannot use {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_377+currStrOff, vlt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_377+currStrOff, ") as '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_377+currStrOff, m->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_377+currStrOff, "'.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&vl,____BAH_COMPILER_VAR_377);
}
char * ____BAH_COMPILER_VAR_378 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(vl.cont);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen(" = ");
unsigned int strLen_3 = strlen(m->name);
unsigned int strLen_4 = strlen(sep);
unsigned int strLen_5 = strlen(rvn);
;                            
            ____BAH_COMPILER_VAR_378 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_378+currStrOff, rvn, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_378+currStrOff, sep, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_378+currStrOff, m->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_378+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_378+currStrOff, vl.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_378+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }r = rope__add(r, rope(____BAH_COMPILER_VAR_378));
break;
};
if ((j==len(s->members))) {
char * ____BAH_COMPILER_VAR_379 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s->name);
unsigned int strLen_1 = strlen("' has no member called {TOKEN}.");
unsigned int strLen_2 = strlen("Struct '");
;                            
            ____BAH_COMPILER_VAR_379 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_379+currStrOff, "Struct '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_379+currStrOff, s->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_379+currStrOff, "' has no member called {TOKEN}.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&t,____BAH_COMPILER_VAR_379);
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
char * ____BAH_COMPILER_VAR_380 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(m->type);
unsigned int strLen_1 = strlen("'.");
unsigned int strLen_2 = strlen(") as '");
unsigned int strLen_3 = strlen(tt);
unsigned int strLen_4 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_380 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_380+currStrOff, "Cannot use {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_380+currStrOff, tt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_380+currStrOff, ") as '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_380+currStrOff, m->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_380+currStrOff, "'.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&t,____BAH_COMPILER_VAR_380);
}
char * ____BAH_COMPILER_VAR_381 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t.cont);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen(" = ");
unsigned int strLen_3 = strlen(m->name);
unsigned int strLen_4 = strlen(sep);
unsigned int strLen_5 = strlen(rvn);
;                            
            ____BAH_COMPILER_VAR_381 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_381+currStrOff, rvn, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_381+currStrOff, sep, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_381+currStrOff, m->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_381+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_381+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_381+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }r = rope__add(r, rope(____BAH_COMPILER_VAR_381));
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
char * ____BAH_COMPILER_VAR_382 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(bracks);
unsigned int strLen_1 = strlen("[]");
;                            
            ____BAH_COMPILER_VAR_382 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_382+currStrOff, bracks, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_382+currStrOff, "[]", strLen_1);
            currStrOff += strLen_1;
        
        }bracks = ____BAH_COMPILER_VAR_382;
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
char * ____BAH_COMPILER_VAR_383 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(bracks);
unsigned int strLen_1 = strlen(arrElem);
;                            
            ____BAH_COMPILER_VAR_383 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_383+currStrOff, bracks, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_383+currStrOff, arrElem, strLen_1);
            currStrOff += strLen_1;
        
        }t.bahType = ____BAH_COMPILER_VAR_383;
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
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
array(char *)* ptrOpers = memoryAlloc(sizeof(array(char *)));

ptrOpers->length = 2;
ptrOpers->elemSize = sizeof(char *);
ptrOpers->data = memoryAlloc(sizeof(char *) * 50);
                    ptrOpers->realLength = 50;
ptrOpers->data[0] = "&";
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
char * ____BAH_COMPILER_VAR_384 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(pt.cont);
unsigned int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_384 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_384+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_384+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_384;

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
            nl->data[len(nl)-1] = pt;
            nl->length = nLength+1;
        } else {
            nl->data[len(nl)-1] = pt;
        }
    }
    ;
i = i+1;
continue;
}
}
else {
char * ____BAH_COMPILER_VAR_385 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(pt.cont);
unsigned int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_385 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_385+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_385+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_385;

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
            nl->data[len(nl)-1] = pt;
            nl->length = nLength+1;
        } else {
            nl->data[len(nl)-1] = pt;
        }
    }
    ;
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
i = i+1;
continue;
}
}
i = i+1;
if ((i<len(l))) {
struct Tok nt = l->data[i];
if ((nt.type==TOKEN_TYPE_VAR)) {
char * ____BAH_COMPILER_VAR_386 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t.cont);
unsigned int strLen_1 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_386 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_386+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_386+currStrOff, nt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }nt.cont = ____BAH_COMPILER_VAR_386;

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
            nl->data[len(nl)] = nt;
            nl->length = nLength+1;
        } else {
            nl->data[len(nl)] = nt;
        }
    }
    ;
i = i+1;
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
i = i+1;
};
return nl;
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
char * ____BAH_COMPILER_VAR_387 =null;char * ____BAH_COMPILER_VAR_388 =string__str(&svt);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_388);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen("sizeof(struct ");
unsigned int strLen_3 = strlen(", ");
unsigned int strLen_4 = strlen(e->cont);
unsigned int strLen_5 = strlen("__serialize(&");
;                            
            ____BAH_COMPILER_VAR_387 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_387+currStrOff, "__serialize(&", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_387+currStrOff, e->cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_387+currStrOff, ", ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_387+currStrOff, "sizeof(struct ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_387+currStrOff, ____BAH_COMPILER_VAR_388, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_387+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_387;
}
else {
char * ptrRect = "";
while ((ptrLevel>1)) {
char * ____BAH_COMPILER_VAR_389 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ptrRect);
unsigned int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_389 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_389+currStrOff, ptrRect, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_389+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }ptrRect = ____BAH_COMPILER_VAR_389;
ptrLevel = ptrLevel-1;
};
char * ____BAH_COMPILER_VAR_390 =null;char * ____BAH_COMPILER_VAR_391 =string__str(&svt);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_391);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen("sizeof(struct ");
unsigned int strLen_3 = strlen(", ");
unsigned int strLen_4 = strlen(e->cont);
unsigned int strLen_5 = strlen(ptrRect);
unsigned int strLen_6 = strlen("__serialize(");
;                            
            ____BAH_COMPILER_VAR_390 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_390+currStrOff, "__serialize(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_390+currStrOff, ptrRect, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_390+currStrOff, e->cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_390+currStrOff, ", ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_390+currStrOff, "sizeof(struct ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_390+currStrOff, ____BAH_COMPILER_VAR_391, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_390+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_390;
register long int i = 0;
while ((i<len(s->members))) {
struct structMemb* m = s->members->data[i];
if ((strcmp(m->type, "cpstring") == 0)) {
char * ____BAH_COMPILER_VAR_392 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(m->name);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen("->");
unsigned int strLen_3 = strlen(e->cont);
unsigned int strLen_4 = strlen("+strlen(");
unsigned int strLen_5 = strlen(code);
;                            
            ____BAH_COMPILER_VAR_392 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_392+currStrOff, code, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_392+currStrOff, "+strlen(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_392+currStrOff, e->cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_392+currStrOff, "->", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_392+currStrOff, m->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_392+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_392;
}
i = i+1;
};
}
char * ____BAH_COMPILER_VAR_393 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(")");
;                            
            ____BAH_COMPILER_VAR_393 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_393+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_393+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }return ____BAH_COMPILER_VAR_393;
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
char * ____BAH_COMPILER_VAR_394 =null;char * ____BAH_COMPILER_VAR_395 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t.cont);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen(" = ");
unsigned int strLen_3 = strlen(v);
unsigned int strLen_4 = strlen(" ");
unsigned int strLen_5 = strlen(____BAH_COMPILER_VAR_395);
;                            
            ____BAH_COMPILER_VAR_394 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_394+currStrOff, ____BAH_COMPILER_VAR_395, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_394+currStrOff, " ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_394+currStrOff, v, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_394+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_394+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_394+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_394));
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
struct Tok ____BAH_COMPILER_VAR_396 = {};
____BAH_COMPILER_VAR_396.cont = "";
____BAH_COMPILER_VAR_396.ogCont = "";
____BAH_COMPILER_VAR_396.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_396.pos = 0;
____BAH_COMPILER_VAR_396.line = 1;
____BAH_COMPILER_VAR_396.begLine = 1;
____BAH_COMPILER_VAR_396.bahType = "";
____BAH_COMPILER_VAR_396.isValue = false;
____BAH_COMPILER_VAR_396.isFunc = false;
____BAH_COMPILER_VAR_396.isOper = false;
____BAH_COMPILER_VAR_396.isEqual = false;
____BAH_COMPILER_VAR_396.pass = false;
____BAH_COMPILER_VAR_396.bahRef= null;
____BAH_COMPILER_VAR_396.parent= null;
#define tmpT ____BAH_COMPILER_VAR_396
tmpT.type = TOKEN_TYPE_VAR;
tmpT.cont = "0";
char * ____BAH_COMPILER_VAR_397 =string__str(&aet);struct Tok rt = parseReflect(tmpT,____BAH_COMPILER_VAR_397,elems,true,"","0");
char * aev = genCompilerVar();
char * ____BAH_COMPILER_VAR_398 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(rt.cont);
unsigned int strLen_1 = strlen(";\n        ");
unsigned int strLen_2 = strlen(" = ");
unsigned int strLen_3 = strlen(aev);
unsigned int strLen_4 = strlen("\n        struct reflectElement ");
;                            
            ____BAH_COMPILER_VAR_398 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_398+currStrOff, "\n        struct reflectElement ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_398+currStrOff, aev, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_398+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_398+currStrOff, rt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_398+currStrOff, ";\n        ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_398));
char * ____BAH_COMPILER_VAR_399 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("&");
unsigned int strLen_1 = strlen(aev);
;                            
            ____BAH_COMPILER_VAR_399 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_399+currStrOff, "&", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_399+currStrOff, aev, strLen_1);
            currStrOff += strLen_1;
        
        }arrElem = ____BAH_COMPILER_VAR_399;

#undef tmpT
}
else if (strHasPrefix(tt,"map:")) {
struct string aet = string(tt);
string__trimLeft(&aet,4);
struct Tok ____BAH_COMPILER_VAR_400 = {};
____BAH_COMPILER_VAR_400.cont = "";
____BAH_COMPILER_VAR_400.ogCont = "";
____BAH_COMPILER_VAR_400.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_400.pos = 0;
____BAH_COMPILER_VAR_400.line = 1;
____BAH_COMPILER_VAR_400.begLine = 1;
____BAH_COMPILER_VAR_400.bahType = "";
____BAH_COMPILER_VAR_400.isValue = false;
____BAH_COMPILER_VAR_400.isFunc = false;
____BAH_COMPILER_VAR_400.isOper = false;
____BAH_COMPILER_VAR_400.isEqual = false;
____BAH_COMPILER_VAR_400.pass = false;
____BAH_COMPILER_VAR_400.bahRef= null;
____BAH_COMPILER_VAR_400.parent= null;
#define tmpT ____BAH_COMPILER_VAR_400
tmpT.type = TOKEN_TYPE_VAR;
tmpT.cont = "0";
char * ____BAH_COMPILER_VAR_401 =string__str(&aet);struct Tok rt = parseReflect(tmpT,____BAH_COMPILER_VAR_401,elems,true,"","0");
char * aev = genCompilerVar();
char * ____BAH_COMPILER_VAR_402 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(rt.cont);
unsigned int strLen_1 = strlen(";\n        ");
unsigned int strLen_2 = strlen(" = ");
unsigned int strLen_3 = strlen(aev);
unsigned int strLen_4 = strlen("\n        struct reflectElement ");
;                            
            ____BAH_COMPILER_VAR_402 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_402+currStrOff, "\n        struct reflectElement ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_402+currStrOff, aev, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_402+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_402+currStrOff, rt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_402+currStrOff, ";\n        ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_402));
char * ____BAH_COMPILER_VAR_403 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("&");
unsigned int strLen_1 = strlen(aev);
;                            
            ____BAH_COMPILER_VAR_403 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_403+currStrOff, "&", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_403+currStrOff, aev, strLen_1);
            currStrOff += strLen_1;
        
        }arrElem = ____BAH_COMPILER_VAR_403;

#undef tmpT
}
char * isStruct = "0";
struct cStruct* ts = searchStruct(tt,elems);
char * structLayout = "0";
if ((ts!=null)) {
isStruct = "1";
structLayout = genCompilerVar();
struct variable* ____BAH_COMPILER_VAR_404 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_404->name = "";
____BAH_COMPILER_VAR_404->type = "";
____BAH_COMPILER_VAR_404->isConst = false;
____BAH_COMPILER_VAR_404->constVal = "";
____BAH_COMPILER_VAR_404->isArray = false;
____BAH_COMPILER_VAR_404->from = "";
____BAH_COMPILER_VAR_404->declScope= null;
____BAH_COMPILER_VAR_404->isGlobal = false;
____BAH_COMPILER_VAR_404->declRope= null;
____BAH_COMPILER_VAR_404->isReg = false;
____BAH_COMPILER_VAR_404->lastSet= null;
____BAH_COMPILER_VAR_404->isArg = false;
struct variable* slv = ____BAH_COMPILER_VAR_404;
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
struct structMemb* ____BAH_COMPILER_VAR_405 = memoryAlloc(sizeof(struct structMemb));
____BAH_COMPILER_VAR_405->name = "";
____BAH_COMPILER_VAR_405->type = "";
____BAH_COMPILER_VAR_405->isConst = false;
____BAH_COMPILER_VAR_405->constVal = "";
____BAH_COMPILER_VAR_405->isArray = false;
____BAH_COMPILER_VAR_405->from = "";
____BAH_COMPILER_VAR_405->declScope= null;
____BAH_COMPILER_VAR_405->isGlobal = false;
____BAH_COMPILER_VAR_405->declRope= null;
____BAH_COMPILER_VAR_405->isReg = false;
____BAH_COMPILER_VAR_405->lastSet= null;
____BAH_COMPILER_VAR_405->isArg = false;
____BAH_COMPILER_VAR_405->def = "";
____BAH_COMPILER_VAR_405->isFn = false;
struct structMemb* nm = ____BAH_COMPILER_VAR_405;
*nm = *m;
m = nm;
m->type = "ptr";
}
struct Tok ____BAH_COMPILER_VAR_406 = {};
____BAH_COMPILER_VAR_406.cont = "";
____BAH_COMPILER_VAR_406.ogCont = "";
____BAH_COMPILER_VAR_406.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_406.pos = 0;
____BAH_COMPILER_VAR_406.line = 1;
____BAH_COMPILER_VAR_406.begLine = 1;
____BAH_COMPILER_VAR_406.bahType = "";
____BAH_COMPILER_VAR_406.isValue = false;
____BAH_COMPILER_VAR_406.isFunc = false;
____BAH_COMPILER_VAR_406.isOper = false;
____BAH_COMPILER_VAR_406.isEqual = false;
____BAH_COMPILER_VAR_406.pass = false;
____BAH_COMPILER_VAR_406.bahRef= null;
____BAH_COMPILER_VAR_406.parent= null;
#define tmpT ____BAH_COMPILER_VAR_406
tmpT.type = TOKEN_TYPE_VAR;
char * sep = "->";
if ((strCount(tt,"*")==0)) {
sep = ".";
}
struct string mCtype = getCType(m->type,elems);
struct string offsetTT = string(tt);
string__replace(&offsetTT,"*","");
char * ____BAH_COMPILER_VAR_407 =null;char * ____BAH_COMPILER_VAR_408 =string__str(&offsetTT);char * ____BAH_COMPILER_VAR_409 =string__str(&mCtype);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(m->name);
unsigned int strLen_1 = strlen("))");
unsigned int strLen_2 = strlen(", ");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_408);
unsigned int strLen_4 = strlen(") + offsetof(struct ");
unsigned int strLen_5 = strlen(t.cont);
unsigned int strLen_6 = strlen("*)((char*)(");
unsigned int strLen_7 = strlen(____BAH_COMPILER_VAR_409);
unsigned int strLen_8 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_407 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_407+currStrOff, "(", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_407+currStrOff, ____BAH_COMPILER_VAR_409, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_407+currStrOff, "*)((char*)(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_407+currStrOff, t.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_407+currStrOff, ") + offsetof(struct ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_407+currStrOff, ____BAH_COMPILER_VAR_408, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_407+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_407+currStrOff, m->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_407+currStrOff, "))", strLen_1);
            currStrOff += strLen_1;
        
        }tmpT.cont = ____BAH_COMPILER_VAR_407;
char * ____BAH_COMPILER_VAR_410 =null;char * ____BAH_COMPILER_VAR_411 =string__str(&offsetTT);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(m->name);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen(", ");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_411);
unsigned int strLen_4 = strlen("offsetof(struct ");
;                            
            ____BAH_COMPILER_VAR_410 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_410+currStrOff, "offsetof(struct ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_410+currStrOff, ____BAH_COMPILER_VAR_411, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_410+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_410+currStrOff, m->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_410+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }struct Tok rt = parseReflect(tmpT,m->type,elems,true,m->name,____BAH_COMPILER_VAR_410);
char * ____BAH_COMPILER_VAR_412 =null;char * ____BAH_COMPILER_VAR_413 =intToStr(i);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(rt.cont);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen("] = ");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_413);
unsigned int strLen_4 = strlen("->data[");
unsigned int strLen_5 = strlen(structLayout);
;                            
            ____BAH_COMPILER_VAR_412 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_412+currStrOff, structLayout, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_412+currStrOff, "->data[", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_412+currStrOff, ____BAH_COMPILER_VAR_413, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_412+currStrOff, "] = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_412+currStrOff, rt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_412+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }dataLayout = rope__add(dataLayout, rope(____BAH_COMPILER_VAR_412));

#undef tmpT
};
char * ____BAH_COMPILER_VAR_414 =null;char * ____BAH_COMPILER_VAR_415 =intToStr(len(ts->members));
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(structLayout);
unsigned int strLen_1 = strlen("->elemSize);\n        ");
unsigned int strLen_2 = strlen("->length * ");
unsigned int strLen_3 = strlen(structLayout);
unsigned int strLen_4 = strlen("->data = memoryAlloc(");
unsigned int strLen_5 = strlen(structLayout);
unsigned int strLen_6 = strlen(";\n        ");
unsigned int strLen_7 = strlen(____BAH_COMPILER_VAR_415);
unsigned int strLen_8 = strlen("->length = ");
unsigned int strLen_9 = strlen(structLayout);
unsigned int strLen_10 = strlen("->elemSize = sizeof(struct reflectElement);\n        ");
unsigned int strLen_11 = strlen(structLayout);
unsigned int strLen_12 = strlen(" = memoryAlloc(sizeof(array(struct reflectElement)));\n        ");
unsigned int strLen_13 = strlen(structLayout);
unsigned int strLen_14 = strlen("\n        array(struct reflectElement) * ");
;                            
            ____BAH_COMPILER_VAR_414 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13+strLen_14);
            
                    memcpy(____BAH_COMPILER_VAR_414+currStrOff, "\n        array(struct reflectElement) * ", strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_414+currStrOff, structLayout, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_414+currStrOff, " = memoryAlloc(sizeof(array(struct reflectElement)));\n        ", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_414+currStrOff, structLayout, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_414+currStrOff, "->elemSize = sizeof(struct reflectElement);\n        ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_414+currStrOff, structLayout, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_414+currStrOff, "->length = ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_414+currStrOff, ____BAH_COMPILER_VAR_415, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_414+currStrOff, ";\n        ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_414+currStrOff, structLayout, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_414+currStrOff, "->data = memoryAlloc(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_414+currStrOff, structLayout, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_414+currStrOff, "->length * ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_414+currStrOff, structLayout, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_414+currStrOff, "->elemSize);\n        ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope__add(rope(____BAH_COMPILER_VAR_414), dataLayout));
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
____BAH_COMPILER_VAR_416->lastSet= null;
____BAH_COMPILER_VAR_416->isArg = false;
struct variable* rv = ____BAH_COMPILER_VAR_416;
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
char * ____BAH_COMPILER_VAR_417 =null;char * ____BAH_COMPILER_VAR_418 =string__str(&name);char * ____BAH_COMPILER_VAR_419 =string__str(&cType);
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
unsigned int strLen_11 = strlen(____BAH_COMPILER_VAR_418);
unsigned int strLen_12 = strlen("\", \"");
unsigned int strLen_13 = strlen(tt);
unsigned int strLen_14 = strlen("), \"");
unsigned int strLen_15 = strlen(____BAH_COMPILER_VAR_419);
unsigned int strLen_16 = strlen(", sizeof(");
unsigned int strLen_17 = strlen(t.cont);
unsigned int strLen_18 = strlen(amp);
unsigned int strLen_19 = strlen(" = __reflect(");
unsigned int strLen_20 = strlen(rv->name);
unsigned int strLen_21 = strlen("struct reflectElement ");
;                            
            ____BAH_COMPILER_VAR_417 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13+strLen_14+strLen_15+strLen_16+strLen_17+strLen_18+strLen_19+strLen_20+strLen_21);
            
                    memcpy(____BAH_COMPILER_VAR_417+currStrOff, "struct reflectElement ", strLen_21);
                    currStrOff += strLen_21;
                    
                    memcpy(____BAH_COMPILER_VAR_417+currStrOff, rv->name, strLen_20);
                    currStrOff += strLen_20;
                    
                    memcpy(____BAH_COMPILER_VAR_417+currStrOff, " = __reflect(", strLen_19);
                    currStrOff += strLen_19;
                    
                    memcpy(____BAH_COMPILER_VAR_417+currStrOff, amp, strLen_18);
                    currStrOff += strLen_18;
                    
                    memcpy(____BAH_COMPILER_VAR_417+currStrOff, t.cont, strLen_17);
                    currStrOff += strLen_17;
                    
                    memcpy(____BAH_COMPILER_VAR_417+currStrOff, ", sizeof(", strLen_16);
                    currStrOff += strLen_16;
                    
                    memcpy(____BAH_COMPILER_VAR_417+currStrOff, ____BAH_COMPILER_VAR_419, strLen_15);
                    currStrOff += strLen_15;
                    
                    memcpy(____BAH_COMPILER_VAR_417+currStrOff, "), \"", strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_417+currStrOff, tt, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_417+currStrOff, "\", \"", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_417+currStrOff, ____BAH_COMPILER_VAR_418, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_417+currStrOff, "\", ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_417+currStrOff, isArr, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_417+currStrOff, ", ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_417+currStrOff, arrElem, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_417+currStrOff, ", ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_417+currStrOff, isStruct, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_417+currStrOff, ", ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_417+currStrOff, structLayout, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_417+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_417+currStrOff, offset, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_417+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_417));
t.cont = rv->name;
return t;
};
char * parseArrayDecl(struct variable* v,__BAH_ARR_TYPE_Tok l,long int i,long int max,struct Elems* elems){
long int arrayLength = 0;
struct string arrType = getCType(v->type,elems);
string__trimRight(&arrType,1);
char * ____BAH_COMPILER_VAR_420 =null;char * ____BAH_COMPILER_VAR_421 =string__str(&arrType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_421);
unsigned int strLen_1 = strlen("))");
unsigned int strLen_2 = strlen("memoryAlloc(sizeof(");
;                            
            ____BAH_COMPILER_VAR_420 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_420+currStrOff, "memoryAlloc(sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_420+currStrOff, ____BAH_COMPILER_VAR_421, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_420+currStrOff, "))", strLen_1);
            currStrOff += strLen_1;
        
        }char * code = ____BAH_COMPILER_VAR_420;
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
struct variable* ____BAH_COMPILER_VAR_422 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_422->name = "";
____BAH_COMPILER_VAR_422->type = "";
____BAH_COMPILER_VAR_422->isConst = false;
____BAH_COMPILER_VAR_422->constVal = "";
____BAH_COMPILER_VAR_422->isArray = false;
____BAH_COMPILER_VAR_422->from = "";
____BAH_COMPILER_VAR_422->declScope= null;
____BAH_COMPILER_VAR_422->isGlobal = false;
____BAH_COMPILER_VAR_422->declRope= null;
____BAH_COMPILER_VAR_422->isReg = false;
____BAH_COMPILER_VAR_422->lastSet= null;
____BAH_COMPILER_VAR_422->isArg = false;
struct variable* tmpV = ____BAH_COMPILER_VAR_422;
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
char * ____BAH_COMPILER_VAR_423 =string__str(&elemType);struct string cType = getCType(____BAH_COMPILER_VAR_423,elems);
char * ____BAH_COMPILER_VAR_424 =null;char * ____BAH_COMPILER_VAR_425 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(NEXT_LINE);
unsigned int strLen_1 = strlen("\n                ");
unsigned int strLen_2 = strlen(";\n                ");
unsigned int strLen_3 = strlen(innerCode);
unsigned int strLen_4 = strlen(" = ");
unsigned int strLen_5 = strlen(tmpV->name);
unsigned int strLen_6 = strlen(") * ");
unsigned int strLen_7 = strlen(____BAH_COMPILER_VAR_425);
unsigned int strLen_8 = strlen("\n                array(");
;                            
            ____BAH_COMPILER_VAR_424 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_424+currStrOff, "\n                array(", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_424+currStrOff, ____BAH_COMPILER_VAR_425, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_424+currStrOff, ") * ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_424+currStrOff, tmpV->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_424+currStrOff, " = ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_424+currStrOff, innerCode, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_424+currStrOff, ";\n                ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_424+currStrOff, NEXT_LINE, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_424+currStrOff, "\n                ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_424));
NEXT_LINE = oldNL;
struct Tok ____BAH_COMPILER_VAR_426 = {};
____BAH_COMPILER_VAR_426.cont = "";
____BAH_COMPILER_VAR_426.ogCont = "";
____BAH_COMPILER_VAR_426.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_426.pos = 0;
____BAH_COMPILER_VAR_426.line = 1;
____BAH_COMPILER_VAR_426.begLine = 1;
____BAH_COMPILER_VAR_426.bahType = "";
____BAH_COMPILER_VAR_426.isValue = false;
____BAH_COMPILER_VAR_426.isFunc = false;
____BAH_COMPILER_VAR_426.isOper = false;
____BAH_COMPILER_VAR_426.isEqual = false;
____BAH_COMPILER_VAR_426.pass = false;
____BAH_COMPILER_VAR_426.bahRef= null;
____BAH_COMPILER_VAR_426.parent= null;
____BAH_COMPILER_VAR_426.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_426.cont = tmpV->name;
____BAH_COMPILER_VAR_426.bahType = string__str(&elemType);
____BAH_COMPILER_VAR_426.isValue = true;
t = ____BAH_COMPILER_VAR_426;
}
char * tt = getTypeFromToken(&t,true,elems);
if ((compTypes(tt,elemBahTypeStr)==false)) {
char * ____BAH_COMPILER_VAR_427 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(") as ");
unsigned int strLen_1 = strlen(elemBahTypeStr);
unsigned int strLen_2 = strlen(tt);
unsigned int strLen_3 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_427 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_427+currStrOff, "Cannot use {TOKEN} (", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_427+currStrOff, tt, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_427+currStrOff, ") as ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_427+currStrOff, elemBahTypeStr, strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&t,____BAH_COMPILER_VAR_427);
}
char * strArrayLength = intToStr(arrayLength);
arrayLength = arrayLength+1;
char * ____BAH_COMPILER_VAR_428 =null;
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
            ____BAH_COMPILER_VAR_428 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_428+currStrOff, NEXT_LINE, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_428+currStrOff, v->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_428+currStrOff, "->data[", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_428+currStrOff, strArrayLength, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_428+currStrOff, "] = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_428+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_428+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }NEXT_LINE = ____BAH_COMPILER_VAR_428;
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
char * ____BAH_COMPILER_VAR_429 =null;
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
            ____BAH_COMPILER_VAR_429 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10);
            
                    memcpy(____BAH_COMPILER_VAR_429+currStrOff, v->name, strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_429+currStrOff, "->data = memoryAlloc(sizeof(", strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_429+currStrOff, elemTypeStr, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_429+currStrOff, ") * ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_429+currStrOff, allocLengthStr, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_429+currStrOff, ");\n                    ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_429+currStrOff, v->name, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_429+currStrOff, "->realLength = ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_429+currStrOff, allocLengthStr, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_429+currStrOff, ";\n", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_429+currStrOff, NEXT_LINE, strLen_1);
            currStrOff += strLen_1;
        
        }NEXT_LINE = ____BAH_COMPILER_VAR_429;
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
char * ____BAH_COMPILER_VAR_430 =null;
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
            ____BAH_COMPILER_VAR_430 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9);
            
                    memcpy(____BAH_COMPILER_VAR_430+currStrOff, "\n", strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_430+currStrOff, v->name, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_430+currStrOff, "->length = ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_430+currStrOff, strArrayLength, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_430+currStrOff, ";\n", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_430+currStrOff, v->name, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_430+currStrOff, "->elemSize = sizeof(", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_430+currStrOff, elemTypeStr, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_430+currStrOff, ");\n", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_430+currStrOff, NEXT_LINE, strLen_1);
            currStrOff += strLen_1;
        
        }NEXT_LINE = ____BAH_COMPILER_VAR_430;
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
char * ____BAH_COMPILER_VAR_431 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ft.cont);
unsigned int strLen_1 = strlen(";\n");
;                            
            ____BAH_COMPILER_VAR_431 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_431+currStrOff, ft.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_431+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_431));
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
struct variable* ____BAH_COMPILER_VAR_432 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_432->name = "";
____BAH_COMPILER_VAR_432->type = "";
____BAH_COMPILER_VAR_432->isConst = false;
____BAH_COMPILER_VAR_432->constVal = "";
____BAH_COMPILER_VAR_432->isArray = false;
____BAH_COMPILER_VAR_432->from = "";
____BAH_COMPILER_VAR_432->declScope= null;
____BAH_COMPILER_VAR_432->isGlobal = false;
____BAH_COMPILER_VAR_432->declRope= null;
____BAH_COMPILER_VAR_432->isReg = false;
____BAH_COMPILER_VAR_432->lastSet= null;
____BAH_COMPILER_VAR_432->isArg = false;
v = ____BAH_COMPILER_VAR_432;
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
char * ____BAH_COMPILER_VAR_433 =string__str(&c);v = searchVar(____BAH_COMPILER_VAR_433,elems);
if ((v==null)) {
throwErr(&t,"Cannot increase/decrease not declared variable {TOKEN}.");
}
char * ____BAH_COMPILER_VAR_434 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t.cont);
unsigned int strLen_1 = strlen(";\n");
;                            
            ____BAH_COMPILER_VAR_434 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_434+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_434+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_434));
return;
}
if ((len(l)<2)) {
throwErr(&ft,"Missing '=' after {TOKEN}.");
}
struct Tok operT = l->data[1];

        char ____BAH_COMPILER_VAR_435 = 0;
        for(int i=equalsTokens->length-1; i!=-1;i--) {
            if (equalsTokens->data[i] != 0 && strcmp(equalsTokens->data[i], operT.cont) == 0) {
                ____BAH_COMPILER_VAR_435=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_435&&(strcmp(operT.cont, "=") != 0)) {
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
char * ____BAH_COMPILER_VAR_436 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(currentType);
unsigned int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_436 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_436+currStrOff, currentType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_436+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }currentType = ____BAH_COMPILER_VAR_436;
}
else {
if ((t.isEqual==true)&&(exists==false)&&(isGlobal()==false)) {
needsDefine = true;
}
if ((strcmp(t.cont, "chan") == 0)) {
if ((i>=len(l))) {
throwErr(&t,"Cannot declare a {TOKEN} without a type (chan <type>).");
}
++i;
struct Tok nt = l->data[i];
char * ____BAH_COMPILER_VAR_437 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("chan:");
unsigned int strLen_1 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_437 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_437+currStrOff, "chan:", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_437+currStrOff, nt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }v->type = ____BAH_COMPILER_VAR_437;
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
char * ____BAH_COMPILER_VAR_438 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("map:");
unsigned int strLen_1 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_438 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_438+currStrOff, "map:", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_438+currStrOff, nt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }v->type = ____BAH_COMPILER_VAR_438;
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
char * ____BAH_COMPILER_VAR_439 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("buffer:");
unsigned int strLen_1 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_439 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_439+currStrOff, "buffer:", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_439+currStrOff, nt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }v->type = ____BAH_COMPILER_VAR_439;
struct variable* ____BAH_COMPILER_VAR_440 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_440->name = "";
____BAH_COMPILER_VAR_440->type = "";
____BAH_COMPILER_VAR_440->isConst = false;
____BAH_COMPILER_VAR_440->constVal = "";
____BAH_COMPILER_VAR_440->isArray = false;
____BAH_COMPILER_VAR_440->from = "";
____BAH_COMPILER_VAR_440->declScope= null;
____BAH_COMPILER_VAR_440->isGlobal = false;
____BAH_COMPILER_VAR_440->declRope= null;
____BAH_COMPILER_VAR_440->isReg = false;
____BAH_COMPILER_VAR_440->lastSet= null;
____BAH_COMPILER_VAR_440->isArg = false;
struct variable* av = ____BAH_COMPILER_VAR_440;
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
char * ____BAH_COMPILER_VAR_441 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen("];");
unsigned int strLen_2 = strlen("[");
unsigned int strLen_3 = strlen(av->name);
unsigned int strLen_4 = strlen("char ");
;                            
            ____BAH_COMPILER_VAR_441 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_441+currStrOff, "char ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_441+currStrOff, av->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_441+currStrOff, "[", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_441+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_441+currStrOff, "];", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_441));
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
char * ____BAH_COMPILER_VAR_442 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(v->type);
unsigned int strLen_1 = strlen(".");
unsigned int strLen_2 = strlen(") as ");
unsigned int strLen_3 = strlen(tp);
unsigned int strLen_4 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_442 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_442+currStrOff, "Cannot use {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_442+currStrOff, tp, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_442+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_442+currStrOff, v->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_442+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&t,____BAH_COMPILER_VAR_442);
}
}
else {
if ((strcmp(currentType, "") == 0)) {
if ((strcmp(v->type, "") == 0)) {
v->type = tp;
}
else {
if ((compTypes(tp,v->type)==false)) {
char * ____BAH_COMPILER_VAR_443 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(v->type);
unsigned int strLen_1 = strlen(".");
unsigned int strLen_2 = strlen(") as ");
unsigned int strLen_3 = strlen(tp);
unsigned int strLen_4 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_443 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_443+currStrOff, "Cannot use {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_443+currStrOff, tp, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_443+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_443+currStrOff, v->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_443+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&t,____BAH_COMPILER_VAR_443);
}
}
}
}
if ((strcmp(t.cont, "") != 0)&&(strHasPrefix(t.cont,"{")==false)) {
char * ____BAH_COMPILER_VAR_444 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_444 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_444+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_444+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_444;
if ((t.isOper==false)&&(RCPavailable()==true)) {
struct variable* iv = searchVar(t.cont,elems);
if ((iv!=null)&&(iv->isConst==false)) {
toVar = true;
isPointedVar = strHasPrefix(t.cont,"&");
struct cStruct* s = searchStruct(iv->type,elems);
if ((s!=null)&&(strCount(iv->type,"*")==0)&&(s->isBinding==false)) {
if ((strCount(iv->name,"*")==0)) {
char * ____BAH_COMPILER_VAR_445 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(iv->name);
unsigned int strLen_1 = strlen("), 0)");
unsigned int strLen_2 = strlen(", sizeof(");
unsigned int strLen_3 = strlen(iv->name);
unsigned int strLen_4 = strlen("; RCP_scanStack(&");
unsigned int strLen_5 = strlen(code);
;                            
            ____BAH_COMPILER_VAR_445 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_445+currStrOff, code, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_445+currStrOff, "; RCP_scanStack(&", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_445+currStrOff, iv->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_445+currStrOff, ", sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_445+currStrOff, iv->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_445+currStrOff, "), 0)", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_445;
}
else {
struct string ivn = string(iv->name);
if ((string__count(&ivn,"*")>0)) {
string__replace(&ivn,"*","");
char * ____BAH_COMPILER_VAR_446 =null;char * ____BAH_COMPILER_VAR_447 =string__str(&ivn);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(iv->name);
unsigned int strLen_1 = strlen("), 0)");
unsigned int strLen_2 = strlen(", sizeof(");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_447);
unsigned int strLen_4 = strlen("; RCP_scanStack(");
;                            
            ____BAH_COMPILER_VAR_446 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_446+currStrOff, "; RCP_scanStack(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_446+currStrOff, ____BAH_COMPILER_VAR_447, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_446+currStrOff, ", sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_446+currStrOff, iv->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_446+currStrOff, "), 0)", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_448 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_446);
;                            
            ____BAH_COMPILER_VAR_448 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_448+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_448+currStrOff, ____BAH_COMPILER_VAR_446, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_448;
}
else {
char * ____BAH_COMPILER_VAR_449 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(iv->name);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen("; RCP_incr(");
unsigned int strLen_3 = strlen(code);
;                            
            ____BAH_COMPILER_VAR_449 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_449+currStrOff, code, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_449+currStrOff, "; RCP_incr(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_449+currStrOff, iv->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_449+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_449;
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
char * ____BAH_COMPILER_VAR_450 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_450 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_450+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_450+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_450;
}
++i;
};
if ((exists==true)) {
v->lastSet = elems;
if ((ft.parent!=null)) {
ft.parent->lastSet = elems;
}
if ((currentFn!=null)) {

                struct string ____BAH_COMPILER_VAR_451 = string(v->name);
                if ((strcmp(v->name, "this") == 0)||string__hasPrefix(&____BAH_COMPILER_VAR_451,"this->")) {
currentFn->isMut = true;
}
}
if ((strlen(code)==0)) {
throwErr(&ft,"Cannot re-declare {TOKEN}.");
}
if ((strlen(currentType)>0)) {
struct Tok st = l->data[1];
char * ____BAH_COMPILER_VAR_452 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ft.cont);
unsigned int strLen_1 = strlen("' to {TOKEN}.");
unsigned int strLen_2 = strlen("Cannot change the type of already declared var '");
;                            
            ____BAH_COMPILER_VAR_452 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_452+currStrOff, "Cannot change the type of already declared var '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_452+currStrOff, ft.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_452+currStrOff, "' to {TOKEN}.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&st,____BAH_COMPILER_VAR_452);
}
char * preCode = "";
if ((isStruct==false)) {
if (isRCPpointerType(v->type)&&(isPointedVar==false)&&(RCPavailable()==true)) {
struct string cType = getCType(v->type,elems);
if ((toVar==true)) {
if ((RCPselfRef(v)==false)) {
char * ____BAH_COMPILER_VAR_453 =null;char * ____BAH_COMPILER_VAR_454 =string__str(&cType);char * ____BAH_COMPILER_VAR_455 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen("*)RCP_incrIL(&");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_454);
unsigned int strLen_4 = strlen(") = *(");
unsigned int strLen_5 = strlen(v->name);
unsigned int strLen_6 = strlen("*)RCP_decrIL(&");
unsigned int strLen_7 = strlen(____BAH_COMPILER_VAR_455);
unsigned int strLen_8 = strlen("*(");
;                            
            ____BAH_COMPILER_VAR_453 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_453+currStrOff, "*(", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_453+currStrOff, ____BAH_COMPILER_VAR_455, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_453+currStrOff, "*)RCP_decrIL(&", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_453+currStrOff, v->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_453+currStrOff, ") = *(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_453+currStrOff, ____BAH_COMPILER_VAR_454, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_453+currStrOff, "*)RCP_incrIL(&", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_453+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_453+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_453;
}
else {
struct variable* ____BAH_COMPILER_VAR_456 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_456->name = "";
____BAH_COMPILER_VAR_456->type = "";
____BAH_COMPILER_VAR_456->isConst = false;
____BAH_COMPILER_VAR_456->constVal = "";
____BAH_COMPILER_VAR_456->isArray = false;
____BAH_COMPILER_VAR_456->from = "";
____BAH_COMPILER_VAR_456->declScope= null;
____BAH_COMPILER_VAR_456->isGlobal = false;
____BAH_COMPILER_VAR_456->declRope= null;
____BAH_COMPILER_VAR_456->isReg = false;
____BAH_COMPILER_VAR_456->lastSet= null;
____BAH_COMPILER_VAR_456->isArg = false;
struct variable* tmpV = ____BAH_COMPILER_VAR_456;
tmpV->name = genCompilerVar();
tmpV->type = v->type;
struct rope* dv = decrVar(tmpV,elems);
char * ____BAH_COMPILER_VAR_457 =null;char * ____BAH_COMPILER_VAR_458 =rope__toStr(dv);char * ____BAH_COMPILER_VAR_459 =string__str(&cType);char * ____BAH_COMPILER_VAR_460 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(");");
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_458);
unsigned int strLen_2 = strlen(code);
unsigned int strLen_3 = strlen("*)RCP_incrIL(&");
unsigned int strLen_4 = strlen(____BAH_COMPILER_VAR_459);
unsigned int strLen_5 = strlen(" = *(");
unsigned int strLen_6 = strlen(v->name);
unsigned int strLen_7 = strlen("; ");
unsigned int strLen_8 = strlen(v->name);
unsigned int strLen_9 = strlen(" = ");
unsigned int strLen_10 = strlen(tmpV->name);
unsigned int strLen_11 = strlen(" ");
unsigned int strLen_12 = strlen(____BAH_COMPILER_VAR_460);
;                            
            ____BAH_COMPILER_VAR_457 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12);
            
                    memcpy(____BAH_COMPILER_VAR_457+currStrOff, ____BAH_COMPILER_VAR_460, strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_457+currStrOff, " ", strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_457+currStrOff, tmpV->name, strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_457+currStrOff, " = ", strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_457+currStrOff, v->name, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_457+currStrOff, "; ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_457+currStrOff, v->name, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_457+currStrOff, " = *(", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_457+currStrOff, ____BAH_COMPILER_VAR_459, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_457+currStrOff, "*)RCP_incrIL(&", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_457+currStrOff, code, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_457+currStrOff, ");", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_457+currStrOff, ____BAH_COMPILER_VAR_458, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_457;
}
}
else {
struct variable* ____BAH_COMPILER_VAR_461 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_461->name = "";
____BAH_COMPILER_VAR_461->type = "";
____BAH_COMPILER_VAR_461->isConst = false;
____BAH_COMPILER_VAR_461->constVal = "";
____BAH_COMPILER_VAR_461->isArray = false;
____BAH_COMPILER_VAR_461->from = "";
____BAH_COMPILER_VAR_461->declScope= null;
____BAH_COMPILER_VAR_461->isGlobal = false;
____BAH_COMPILER_VAR_461->declRope= null;
____BAH_COMPILER_VAR_461->isReg = false;
____BAH_COMPILER_VAR_461->lastSet= null;
____BAH_COMPILER_VAR_461->isArg = false;
struct variable* tmpV = ____BAH_COMPILER_VAR_461;
tmpV->name = genCompilerVar();
tmpV->type = v->type;
struct rope* dv = decrVar(tmpV,elems);
char * ____BAH_COMPILER_VAR_462 =null;char * ____BAH_COMPILER_VAR_463 =rope__toStr(dv);char * ____BAH_COMPILER_VAR_464 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(";");
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_463);
unsigned int strLen_2 = strlen(code);
unsigned int strLen_3 = strlen(" = ");
unsigned int strLen_4 = strlen(v->name);
unsigned int strLen_5 = strlen("; ");
unsigned int strLen_6 = strlen(v->name);
unsigned int strLen_7 = strlen(" = ");
unsigned int strLen_8 = strlen(tmpV->name);
unsigned int strLen_9 = strlen(" ");
unsigned int strLen_10 = strlen(____BAH_COMPILER_VAR_464);
;                            
            ____BAH_COMPILER_VAR_462 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10);
            
                    memcpy(____BAH_COMPILER_VAR_462+currStrOff, ____BAH_COMPILER_VAR_464, strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_462+currStrOff, " ", strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_462+currStrOff, tmpV->name, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_462+currStrOff, " = ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_462+currStrOff, v->name, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_462+currStrOff, "; ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_462+currStrOff, v->name, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_462+currStrOff, " = ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_462+currStrOff, code, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_462+currStrOff, ";", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_462+currStrOff, ____BAH_COMPILER_VAR_463, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_462;
}
}
else {
struct cStruct* s = searchStruct(v->type,elems);
if ((s!=null)&&(RCPavailable()==true)&&(RCPselfRef(v)==false)&&(s->isBinding==false)) {
if ((strCount(v->name,"*")==0)) {
char * ____BAH_COMPILER_VAR_465 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(v->name);
unsigned int strLen_1 = strlen("), 1); ");
unsigned int strLen_2 = strlen(", sizeof(");
unsigned int strLen_3 = strlen(v->name);
unsigned int strLen_4 = strlen("RCP_scanStack(&");
;                            
            ____BAH_COMPILER_VAR_465 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_465+currStrOff, "RCP_scanStack(&", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_465+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_465+currStrOff, ", sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_465+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_465+currStrOff, "), 1); ", strLen_1);
            currStrOff += strLen_1;
        
        }preCode = ____BAH_COMPILER_VAR_465;
}
else {
struct string vn = string(v->name);
string__replace(&vn,"*","");
char * ____BAH_COMPILER_VAR_466 =null;char * ____BAH_COMPILER_VAR_467 =string__str(&vn);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(v->name);
unsigned int strLen_1 = strlen("), 1); ");
unsigned int strLen_2 = strlen(", sizeof(");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_467);
unsigned int strLen_4 = strlen("RCP_scanStack(");
;                            
            ____BAH_COMPILER_VAR_466 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_466+currStrOff, "RCP_scanStack(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_466+currStrOff, ____BAH_COMPILER_VAR_467, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_466+currStrOff, ", sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_466+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_466+currStrOff, "), 1); ", strLen_1);
            currStrOff += strLen_1;
        
        }preCode = ____BAH_COMPILER_VAR_466;
}
char * ____BAH_COMPILER_VAR_468 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(" = ");
unsigned int strLen_1 = strlen(code);
unsigned int strLen_2 = strlen(v->name);
;                            
            ____BAH_COMPILER_VAR_468 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_468+currStrOff, v->name, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_468+currStrOff, " = ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_468+currStrOff, code, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_468;
}
else {
char * ____BAH_COMPILER_VAR_469 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(" = ");
unsigned int strLen_1 = strlen(code);
unsigned int strLen_2 = strlen(v->name);
;                            
            ____BAH_COMPILER_VAR_469 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_469+currStrOff, v->name, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_469+currStrOff, " = ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_469+currStrOff, code, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_469;
}
}
}
else {
strTrim(&code);
if ((strHasPrefix(code,"{")==false)) {
char * ____BAH_COMPILER_VAR_470 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(" = ");
unsigned int strLen_1 = strlen(code);
unsigned int strLen_2 = strlen(v->name);
;                            
            ____BAH_COMPILER_VAR_470 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_470+currStrOff, v->name, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_470+currStrOff, " = ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_470+currStrOff, code, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_470;
}
}
if ((v->isArray==true)) {
code = genArrRealloc(v,preCode,code,elems);
}
else {
char * ____BAH_COMPILER_VAR_471 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(preCode);
unsigned int strLen_1 = strlen(code);
;                            
            ____BAH_COMPILER_VAR_471 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_471+currStrOff, preCode, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_471+currStrOff, code, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_471;
}
}
else {
if ((strcmp(currentType, "") != 0)) {
v->type = currentType;
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
char * ____BAH_COMPILER_VAR_472 =null;char * ____BAH_COMPILER_VAR_473 =string__str(&ct);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpfnArgsCType);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_473);
;                            
            ____BAH_COMPILER_VAR_472 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_472+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_472+currStrOff, ____BAH_COMPILER_VAR_473, strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_472;
j = j+1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_474 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpfnArgsCType);
unsigned int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_474 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_474+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_474+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_474;
}
};
char * ____BAH_COMPILER_VAR_475 =null;char * ____BAH_COMPILER_VAR_476 =string__str(&tmpfnRetCType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpfnArgsCType);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen(")(");
unsigned int strLen_3 = strlen(v->name);
unsigned int strLen_4 = strlen(" (*");
unsigned int strLen_5 = strlen(____BAH_COMPILER_VAR_476);
;                            
            ____BAH_COMPILER_VAR_475 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_475+currStrOff, ____BAH_COMPILER_VAR_476, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_475+currStrOff, " (*", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_475+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_475+currStrOff, ")(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_475+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_475+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }vct = ____BAH_COMPILER_VAR_475;
}
else {
vct = setCType(v,elems);
}
if ((strcmp(code, "") != 0)&&(shouldOnlyDecl==false)) {
if (isRCPpointerType(v->type)&&(RCPavailable()==true)&&(toVar==true)&&(isPointedVar==false)) {
struct string cType = getCType(v->type,elems);
if (isGlobal()) {
char * ____BAH_COMPILER_VAR_477 =null;char * ____BAH_COMPILER_VAR_478 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(");\n");
unsigned int strLen_2 = strlen("*)RCP_incrIL(&");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_478);
unsigned int strLen_4 = strlen(" = *(");
unsigned int strLen_5 = strlen(v->name);
;                            
            ____BAH_COMPILER_VAR_477 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_477+currStrOff, v->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_477+currStrOff, " = *(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_477+currStrOff, ____BAH_COMPILER_VAR_478, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_477+currStrOff, "*)RCP_incrIL(&", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_477+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_477+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_477));
}
else {
char * ____BAH_COMPILER_VAR_479 =null;char * ____BAH_COMPILER_VAR_480 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen("*)RCP_incrIL(&");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_480);
unsigned int strLen_4 = strlen(" = *(");
unsigned int strLen_5 = strlen(vct);
;                            
            ____BAH_COMPILER_VAR_479 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_479+currStrOff, vct, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_479+currStrOff, " = *(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_479+currStrOff, ____BAH_COMPILER_VAR_480, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_479+currStrOff, "*)RCP_incrIL(&", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_479+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_479+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_479;
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
char * ____BAH_COMPILER_VAR_481 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen("\n");
unsigned int strLen_2 = strlen(" ");
unsigned int strLen_3 = strlen(v->name);
unsigned int strLen_4 = strlen("#define ");
;                            
            ____BAH_COMPILER_VAR_481 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_481+currStrOff, "#define ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_481+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_481+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_481+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_481+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_481));
}
else {
char * ____BAH_COMPILER_VAR_482 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(" ");
unsigned int strLen_1 = strlen(code);
unsigned int strLen_2 = strlen(v->name);
unsigned int strLen_3 = strlen("#define ");
;                            
            ____BAH_COMPILER_VAR_482 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_482+currStrOff, "#define ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_482+currStrOff, v->name, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_482+currStrOff, " ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_482+currStrOff, code, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_482;
}
}
else {
if (isGlobal()) {
char * ____BAH_COMPILER_VAR_483 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen(" = ");
unsigned int strLen_3 = strlen(v->name);
;                            
            ____BAH_COMPILER_VAR_483 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_483+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_483+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_483+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_483+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_483));
}
else {
char * ____BAH_COMPILER_VAR_484 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(" = ");
unsigned int strLen_1 = strlen(code);
unsigned int strLen_2 = strlen(vct);
;                            
            ____BAH_COMPILER_VAR_484 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_484+currStrOff, vct, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_484+currStrOff, " = ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_484+currStrOff, code, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_484;
}
}
}
}
else {
if (isRCPpointerType(v->type)&&(shouldOnlyDecl==false)) {
char * ____BAH_COMPILER_VAR_485 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(vct);
unsigned int strLen_1 = strlen("= null");
;                            
            ____BAH_COMPILER_VAR_485 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_485+currStrOff, vct, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_485+currStrOff, "= null", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_485;
}
else {
code = vct;
}
}
if ((shouldOnlyDecl==true)) {
char * ____BAH_COMPILER_VAR_486 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("extern ");
unsigned int strLen_1 = strlen(vct);
;                            
            ____BAH_COMPILER_VAR_486 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_486+currStrOff, "extern ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_486+currStrOff, vct, strLen_1);
            currStrOff += strLen_1;
        
        }vct = ____BAH_COMPILER_VAR_486;
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
struct variable* ____BAH_COMPILER_VAR_487 = v;
char ** ____BAH_COMPILER_VAR_489 = (char **)((char*)(____BAH_COMPILER_VAR_487) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_490 = __reflect(____BAH_COMPILER_VAR_489, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_491 = (char **)((char*)(____BAH_COMPILER_VAR_487) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_492 = __reflect(____BAH_COMPILER_VAR_491, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_493 = (char*)((char*)(____BAH_COMPILER_VAR_487) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_494 = __reflect(____BAH_COMPILER_VAR_493, sizeof(char), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_495 = (char **)((char*)(____BAH_COMPILER_VAR_487) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_496 = __reflect(____BAH_COMPILER_VAR_495, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_497 = (char*)((char*)(____BAH_COMPILER_VAR_487) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_498 = __reflect(____BAH_COMPILER_VAR_497, sizeof(char), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_499 = (char **)((char*)(____BAH_COMPILER_VAR_487) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_500 = __reflect(____BAH_COMPILER_VAR_499, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
void ** ____BAH_COMPILER_VAR_501 = (void **)((char*)(____BAH_COMPILER_VAR_487) + offsetof(struct variable, declScope));
struct reflectElement ____BAH_COMPILER_VAR_502 = __reflect(____BAH_COMPILER_VAR_501, sizeof(void *), "ptr", "declScope", 0, 0, 0, 0, offsetof(struct variable, declScope));
char* ____BAH_COMPILER_VAR_503 = (char*)((char*)(____BAH_COMPILER_VAR_487) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_504 = __reflect(____BAH_COMPILER_VAR_503, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));
struct rope** ____BAH_COMPILER_VAR_505 = (struct rope**)((char*)(____BAH_COMPILER_VAR_487) + offsetof(struct variable, declRope));
void ** ____BAH_COMPILER_VAR_507 = (void **)((char*)(____BAH_COMPILER_VAR_505) + offsetof(struct rope, left));
struct reflectElement ____BAH_COMPILER_VAR_508 = __reflect(____BAH_COMPILER_VAR_507, sizeof(void *), "ptr", "left", 0, 0, 0, 0, offsetof(struct rope, left));
void ** ____BAH_COMPILER_VAR_509 = (void **)((char*)(____BAH_COMPILER_VAR_505) + offsetof(struct rope, right));
struct reflectElement ____BAH_COMPILER_VAR_510 = __reflect(____BAH_COMPILER_VAR_509, sizeof(void *), "ptr", "right", 0, 0, 0, 0, offsetof(struct rope, right));
char ** ____BAH_COMPILER_VAR_511 = (char **)((char*)(____BAH_COMPILER_VAR_505) + offsetof(struct rope, str));
struct reflectElement ____BAH_COMPILER_VAR_512 = __reflect(____BAH_COMPILER_VAR_511, sizeof(char *), "cpstring", "str", 0, 0, 0, 0, offsetof(struct rope, str));
int* ____BAH_COMPILER_VAR_513 = (int*)((char*)(____BAH_COMPILER_VAR_505) + offsetof(struct rope, lCount));
struct reflectElement ____BAH_COMPILER_VAR_514 = __reflect(____BAH_COMPILER_VAR_513, sizeof(int), "int32", "lCount", 0, 0, 0, 0, offsetof(struct rope, lCount));
int* ____BAH_COMPILER_VAR_515 = (int*)((char*)(____BAH_COMPILER_VAR_505) + offsetof(struct rope, len));
struct reflectElement ____BAH_COMPILER_VAR_516 = __reflect(____BAH_COMPILER_VAR_515, sizeof(int), "int32", "len", 0, 0, 0, 0, offsetof(struct rope, len));
int* ____BAH_COMPILER_VAR_517 = (int*)((char*)(____BAH_COMPILER_VAR_505) + offsetof(struct rope, totalLen));
struct reflectElement ____BAH_COMPILER_VAR_518 = __reflect(____BAH_COMPILER_VAR_517, sizeof(int), "int32", "totalLen", 0, 0, 0, 0, offsetof(struct rope, totalLen));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_506 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_506->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_506->length = 6;
        ____BAH_COMPILER_VAR_506->data = memoryAlloc(____BAH_COMPILER_VAR_506->length * ____BAH_COMPILER_VAR_506->elemSize);
        ____BAH_COMPILER_VAR_506->data[0] = ____BAH_COMPILER_VAR_508;
____BAH_COMPILER_VAR_506->data[1] = ____BAH_COMPILER_VAR_510;
____BAH_COMPILER_VAR_506->data[2] = ____BAH_COMPILER_VAR_512;
____BAH_COMPILER_VAR_506->data[3] = ____BAH_COMPILER_VAR_514;
____BAH_COMPILER_VAR_506->data[4] = ____BAH_COMPILER_VAR_516;
____BAH_COMPILER_VAR_506->data[5] = ____BAH_COMPILER_VAR_518;
struct reflectElement ____BAH_COMPILER_VAR_519 = __reflect(____BAH_COMPILER_VAR_505, sizeof(struct rope), "rope*", "declRope", 0, 0, 1, ____BAH_COMPILER_VAR_506, offsetof(struct variable, declRope));
char* ____BAH_COMPILER_VAR_520 = (char*)((char*)(____BAH_COMPILER_VAR_487) + offsetof(struct variable, canBeReg));
struct reflectElement ____BAH_COMPILER_VAR_521 = __reflect(____BAH_COMPILER_VAR_520, sizeof(char), "bool", "canBeReg", 0, 0, 0, 0, offsetof(struct variable, canBeReg));
char* ____BAH_COMPILER_VAR_522 = (char*)((char*)(____BAH_COMPILER_VAR_487) + offsetof(struct variable, isReg));
struct reflectElement ____BAH_COMPILER_VAR_523 = __reflect(____BAH_COMPILER_VAR_522, sizeof(char), "bool", "isReg", 0, 0, 0, 0, offsetof(struct variable, isReg));
void ** ____BAH_COMPILER_VAR_524 = (void **)((char*)(____BAH_COMPILER_VAR_487) + offsetof(struct variable, lastSet));
struct reflectElement ____BAH_COMPILER_VAR_525 = __reflect(____BAH_COMPILER_VAR_524, sizeof(void *), "ptr", "lastSet", 0, 0, 0, 0, offsetof(struct variable, lastSet));
char* ____BAH_COMPILER_VAR_526 = (char*)((char*)(____BAH_COMPILER_VAR_487) + offsetof(struct variable, isArg));
struct reflectElement ____BAH_COMPILER_VAR_527 = __reflect(____BAH_COMPILER_VAR_526, sizeof(char), "bool", "isArg", 0, 0, 0, 0, offsetof(struct variable, isArg));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_488 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_488->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_488->length = 13;
        ____BAH_COMPILER_VAR_488->data = memoryAlloc(____BAH_COMPILER_VAR_488->length * ____BAH_COMPILER_VAR_488->elemSize);
        ____BAH_COMPILER_VAR_488->data[0] = ____BAH_COMPILER_VAR_490;
____BAH_COMPILER_VAR_488->data[1] = ____BAH_COMPILER_VAR_492;
____BAH_COMPILER_VAR_488->data[2] = ____BAH_COMPILER_VAR_494;
____BAH_COMPILER_VAR_488->data[3] = ____BAH_COMPILER_VAR_496;
____BAH_COMPILER_VAR_488->data[4] = ____BAH_COMPILER_VAR_498;
____BAH_COMPILER_VAR_488->data[5] = ____BAH_COMPILER_VAR_500;
____BAH_COMPILER_VAR_488->data[6] = ____BAH_COMPILER_VAR_502;
____BAH_COMPILER_VAR_488->data[7] = ____BAH_COMPILER_VAR_504;
____BAH_COMPILER_VAR_488->data[8] = ____BAH_COMPILER_VAR_519;
____BAH_COMPILER_VAR_488->data[9] = ____BAH_COMPILER_VAR_521;
____BAH_COMPILER_VAR_488->data[10] = ____BAH_COMPILER_VAR_523;
____BAH_COMPILER_VAR_488->data[11] = ____BAH_COMPILER_VAR_525;
____BAH_COMPILER_VAR_488->data[12] = ____BAH_COMPILER_VAR_527;
struct reflectElement ____BAH_COMPILER_VAR_528 = __reflect(____BAH_COMPILER_VAR_487, sizeof(struct variable), "variable*", "v", 0, 0, 1, ____BAH_COMPILER_VAR_488, 0);
debugPrint("var_declaration",ft.line,____BAH_COMPILER_VAR_528);
if (isGlobal()) {
char * ____BAH_COMPILER_VAR_529 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(vct);
unsigned int strLen_1 = strlen(";\n");
;                            
            ____BAH_COMPILER_VAR_529 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_529+currStrOff, vct, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_529+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_529));
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
char * ____BAH_COMPILER_VAR_530 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen("\n");
;                            
            ____BAH_COMPILER_VAR_530 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_530+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_530+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_530));
}
else {
char * ____BAH_COMPILER_VAR_531 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(";\n");
;                            
            ____BAH_COMPILER_VAR_531 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_531+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_531+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }struct rope* declR = rope(____BAH_COMPILER_VAR_531);
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
char * ____BAH_COMPILER_VAR_532 =null;char * ____BAH_COMPILER_VAR_533 =string__str(&ct);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpfnArgsCType);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_533);
;                            
            ____BAH_COMPILER_VAR_532 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_532+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_532+currStrOff, ____BAH_COMPILER_VAR_533, strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_532;
j = j+1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_534 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpfnArgsCType);
unsigned int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_534 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_534+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_534+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_534;
}
};
char * ____BAH_COMPILER_VAR_535 =null;char * ____BAH_COMPILER_VAR_536 =string__str(&tmpfnRetCType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpfnArgsCType);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen(")(");
unsigned int strLen_3 = strlen(elemName);
unsigned int strLen_4 = strlen(" (*");
unsigned int strLen_5 = strlen(____BAH_COMPILER_VAR_536);
;                            
            ____BAH_COMPILER_VAR_535 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_535+currStrOff, ____BAH_COMPILER_VAR_536, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_535+currStrOff, " (*", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_535+currStrOff, elemName, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_535+currStrOff, ")(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_535+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_535+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }return ____BAH_COMPILER_VAR_535;
};
char * parseFnHeader(char * prev,__BAH_ARR_TYPE_Tok l,long int* i,struct func* fn,struct Elems* elems){
register long int j = *i;
struct Tok ft = l->data[j];
char * tpdf = "";
if ((ft.type!=TOKEN_TYPE_VAR)) {
throwErr(&ft,"Cannot use {TOKEN} as function name.");
}
char * ____BAH_COMPILER_VAR_537 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(prev);
unsigned int strLen_1 = strlen(ft.cont);
;                            
            ____BAH_COMPILER_VAR_537 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_537+currStrOff, prev, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_537+currStrOff, ft.cont, strLen_1);
            currStrOff += strLen_1;
        
        }fn->name = ____BAH_COMPILER_VAR_537;
array(struct variable*)* arguments = memoryAlloc(sizeof(array(struct variable*)));

arguments->length = 0;
arguments->elemSize = sizeof(struct variable*);
char * ____BAH_COMPILER_VAR_538 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fn->name);
unsigned int strLen_1 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_538 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_538+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_538+currStrOff, "(", strLen_1);
            currStrOff += strLen_1;
        
        }char * code = ____BAH_COMPILER_VAR_538;
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
char * ____BAH_COMPILER_VAR_539 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(argType);
unsigned int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_539 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_539+currStrOff, argType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_539+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }argType = ____BAH_COMPILER_VAR_539;
}
}
else {
isComa = true;
break;
}
j = j+1;
};
struct variable* ____BAH_COMPILER_VAR_540 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_540->name = "";
____BAH_COMPILER_VAR_540->type = "";
____BAH_COMPILER_VAR_540->isConst = false;
____BAH_COMPILER_VAR_540->constVal = "";
____BAH_COMPILER_VAR_540->isArray = false;
____BAH_COMPILER_VAR_540->from = "";
____BAH_COMPILER_VAR_540->declScope= null;
____BAH_COMPILER_VAR_540->isGlobal = false;
____BAH_COMPILER_VAR_540->declRope= null;
____BAH_COMPILER_VAR_540->isReg = false;
____BAH_COMPILER_VAR_540->lastSet= null;
____BAH_COMPILER_VAR_540->isArg = false;
struct variable* argument = ____BAH_COMPILER_VAR_540;
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
char * ____BAH_COMPILER_VAR_541 =null;char * ____BAH_COMPILER_VAR_542 =string__str(&cfrt);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("__BAH_ARR_TYPE_");
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_542);
;                            
            ____BAH_COMPILER_VAR_541 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_541+currStrOff, "__BAH_ARR_TYPE_", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_541+currStrOff, ____BAH_COMPILER_VAR_542, strLen_1);
            currStrOff += strLen_1;
        
        }newArgType = ____BAH_COMPILER_VAR_541;
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
char * ____BAH_COMPILER_VAR_543 =null;char * ____BAH_COMPILER_VAR_544 =string__str(&argCType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(newArgType);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen(" ");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_544);
unsigned int strLen_4 = strlen("typedef ");
unsigned int strLen_5 = strlen(tpdf);
;                            
            ____BAH_COMPILER_VAR_543 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_543+currStrOff, tpdf, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_543+currStrOff, "typedef ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_543+currStrOff, ____BAH_COMPILER_VAR_544, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_543+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_543+currStrOff, newArgType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_543+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }tpdf = ____BAH_COMPILER_VAR_543;
}
}
if ((string__hasPrefix(&cfrt,"function(")==1)) {
char * ____BAH_COMPILER_VAR_545 =null;char * ____BAH_COMPILER_VAR_546 =getCfunctionType(&cfrt,argName,elems);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_546);
;                            
            ____BAH_COMPILER_VAR_545 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_545+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_545+currStrOff, ____BAH_COMPILER_VAR_546, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_545;
}
else {
char * ____BAH_COMPILER_VAR_547 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(" ");
unsigned int strLen_1 = strlen(argName);
unsigned int strLen_2 = strlen(newArgType);
unsigned int strLen_3 = strlen(code);
;                            
            ____BAH_COMPILER_VAR_547 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_547+currStrOff, code, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_547+currStrOff, newArgType, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_547+currStrOff, " ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_547+currStrOff, argName, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_547;
}
if ((isComa==true)) {
char * ____BAH_COMPILER_VAR_548 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_548 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_548+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_548+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_548;
}
else {
char * ____BAH_COMPILER_VAR_549 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(")");
;                            
            ____BAH_COMPILER_VAR_549 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_549+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_549+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_549;
break;
}
j = j+1;
};
}
else {
char * ____BAH_COMPILER_VAR_550 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(")");
;                            
            ____BAH_COMPILER_VAR_550 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_550+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_550+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_550;
}
j = j+1;
struct variable* ____BAH_COMPILER_VAR_551 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_551->name = "";
____BAH_COMPILER_VAR_551->type = "";
____BAH_COMPILER_VAR_551->isConst = false;
____BAH_COMPILER_VAR_551->constVal = "";
____BAH_COMPILER_VAR_551->isArray = false;
____BAH_COMPILER_VAR_551->from = "";
____BAH_COMPILER_VAR_551->declScope= null;
____BAH_COMPILER_VAR_551->isGlobal = false;
____BAH_COMPILER_VAR_551->declRope= null;
____BAH_COMPILER_VAR_551->isReg = false;
____BAH_COMPILER_VAR_551->lastSet= null;
____BAH_COMPILER_VAR_551->isArg = false;
struct variable* returns = ____BAH_COMPILER_VAR_551;
returns->type = "";
while ((j<len(l))) {
t = l->data[j];
if ((strcmp(t.cont, "{") == 0)) {
break;
}
char * ____BAH_COMPILER_VAR_552 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(returns->type);
unsigned int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_552 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_552+currStrOff, returns->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_552+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }returns->type = ____BAH_COMPILER_VAR_552;
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
char * ____BAH_COMPILER_VAR_553 =null;char * ____BAH_COMPILER_VAR_554 =string__str(&cfrt);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("__BAH_ARR_TYPE_");
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_554);
;                            
            ____BAH_COMPILER_VAR_553 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_553+currStrOff, "__BAH_ARR_TYPE_", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_553+currStrOff, ____BAH_COMPILER_VAR_554, strLen_1);
            currStrOff += strLen_1;
        
        }newFnRetType = ____BAH_COMPILER_VAR_553;
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
char * ____BAH_COMPILER_VAR_555 =null;char * ____BAH_COMPILER_VAR_556 =string__str(&fnRetType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(newFnRetType);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen(" ");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_556);
unsigned int strLen_4 = strlen("typedef ");
unsigned int strLen_5 = strlen(tpdf);
;                            
            ____BAH_COMPILER_VAR_555 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_555+currStrOff, tpdf, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_555+currStrOff, "typedef ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_555+currStrOff, ____BAH_COMPILER_VAR_556, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_555+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_555+currStrOff, newFnRetType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_555+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }tpdf = ____BAH_COMPILER_VAR_555;
}
}
char * ____BAH_COMPILER_VAR_557 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(" ");
unsigned int strLen_1 = strlen(code);
unsigned int strLen_2 = strlen(newFnRetType);
unsigned int strLen_3 = strlen(tpdf);
;                            
            ____BAH_COMPILER_VAR_557 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_557+currStrOff, tpdf, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_557+currStrOff, newFnRetType, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_557+currStrOff, " ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_557+currStrOff, code, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_557;
return code;
};
void parseStruct(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
struct cStruct* ____BAH_COMPILER_VAR_558 = memoryAlloc(sizeof(struct cStruct));
____BAH_COMPILER_VAR_558->name = "";
____BAH_COMPILER_VAR_558->members = memoryAlloc(sizeof(array(struct structMemb*)));
            ____BAH_COMPILER_VAR_558->members->length = 0;
            ____BAH_COMPILER_VAR_558->members->elemSize = sizeof(struct structMemb*);
            ____BAH_COMPILER_VAR_558->methods = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_558->methods->length = 0;
            ____BAH_COMPILER_VAR_558->methods->elemSize = sizeof(struct func*);
            ____BAH_COMPILER_VAR_558->postCode = "";
____BAH_COMPILER_VAR_558->extendedFrom = "";
____BAH_COMPILER_VAR_558->isBinding = false;
____BAH_COMPILER_VAR_558->hasRCPmemb = false;
struct cStruct* s = ____BAH_COMPILER_VAR_558;
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
if ((string__hasPrefix(&cemt,"function(")==1)) {
struct func* tmpfn = parseFnType(cemt);
struct string tmpfnRetCType = getCType(tmpfn->returns->type,elems);
char * tmpfnArgsCType = "";
j = 0;
while ((j<len(tmpfn->args))) {
struct variable* arg = tmpfn->args->data[j];
struct string ct = getCType(arg->type,elems);
char * ____BAH_COMPILER_VAR_559 =null;char * ____BAH_COMPILER_VAR_560 =string__str(&ct);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpfnArgsCType);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_560);
;                            
            ____BAH_COMPILER_VAR_559 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_559+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_559+currStrOff, ____BAH_COMPILER_VAR_560, strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_559;
j = j+1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_561 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpfnArgsCType);
unsigned int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_561 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_561+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_561+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_561;
}
};
char * ____BAH_COMPILER_VAR_562 =null;char * ____BAH_COMPILER_VAR_563 =string__str(&tmpfnRetCType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpfnArgsCType);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen(")(");
unsigned int strLen_3 = strlen(em->name);
unsigned int strLen_4 = strlen(" (*");
unsigned int strLen_5 = strlen(____BAH_COMPILER_VAR_563);
;                            
            ____BAH_COMPILER_VAR_562 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_562+currStrOff, ____BAH_COMPILER_VAR_563, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_562+currStrOff, " (*", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_562+currStrOff, em->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_562+currStrOff, ")(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_562+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_562+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }membDeclStr = ____BAH_COMPILER_VAR_562;
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
struct structMemb* ____BAH_COMPILER_VAR_564 = memoryAlloc(sizeof(struct structMemb));
____BAH_COMPILER_VAR_564->name = "";
____BAH_COMPILER_VAR_564->type = "";
____BAH_COMPILER_VAR_564->isConst = false;
____BAH_COMPILER_VAR_564->constVal = "";
____BAH_COMPILER_VAR_564->isArray = false;
____BAH_COMPILER_VAR_564->from = "";
____BAH_COMPILER_VAR_564->declScope= null;
____BAH_COMPILER_VAR_564->isGlobal = false;
____BAH_COMPILER_VAR_564->declRope= null;
____BAH_COMPILER_VAR_564->isReg = false;
____BAH_COMPILER_VAR_564->lastSet= null;
____BAH_COMPILER_VAR_564->isArg = false;
____BAH_COMPILER_VAR_564->def = "";
____BAH_COMPILER_VAR_564->isFn = false;
struct structMemb* memb = ____BAH_COMPILER_VAR_564;
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
char * ____BAH_COMPILER_VAR_565 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s->name);
unsigned int strLen_1 = strlen("__");
;                            
            ____BAH_COMPILER_VAR_565 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_565+currStrOff, s->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_565+currStrOff, "__", strLen_1);
            currStrOff += strLen_1;
        
        }char * fnPrefix = ____BAH_COMPILER_VAR_565;
struct func* ____BAH_COMPILER_VAR_566 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_566->name = "";
____BAH_COMPILER_VAR_566->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_566->args->length = 0;
            ____BAH_COMPILER_VAR_566->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_566->returns= null;
____BAH_COMPILER_VAR_566->isBinding = false;
____BAH_COMPILER_VAR_566->from = "";
____BAH_COMPILER_VAR_566->file = "";
____BAH_COMPILER_VAR_566->line = 1;
____BAH_COMPILER_VAR_566->isVar = false;
____BAH_COMPILER_VAR_566->used = false;
____BAH_COMPILER_VAR_566->code = null;
____BAH_COMPILER_VAR_566->isMut = false;
____BAH_COMPILER_VAR_566->isImported = false;
struct func* fn = ____BAH_COMPILER_VAR_566;
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
char * ____BAH_COMPILER_VAR_567 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s->name);
unsigned int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_567 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_567+currStrOff, s->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_567+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_567;
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
char * ____BAH_COMPILER_VAR_568 =parseFnHeader(fnPrefix,nl,&nli,fn,elems);struct rope* code = rope(____BAH_COMPILER_VAR_568);
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
struct func* ____BAH_COMPILER_VAR_569 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_569->name = "";
____BAH_COMPILER_VAR_569->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_569->args->length = 0;
            ____BAH_COMPILER_VAR_569->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_569->returns= null;
____BAH_COMPILER_VAR_569->isBinding = false;
____BAH_COMPILER_VAR_569->from = "";
____BAH_COMPILER_VAR_569->file = "";
____BAH_COMPILER_VAR_569->line = 1;
____BAH_COMPILER_VAR_569->isVar = false;
____BAH_COMPILER_VAR_569->used = false;
____BAH_COMPILER_VAR_569->code = null;
____BAH_COMPILER_VAR_569->isMut = false;
____BAH_COMPILER_VAR_569->isImported = false;
struct func* mfn = ____BAH_COMPILER_VAR_569;
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
char * ____BAH_COMPILER_VAR_570 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fn->name);
unsigned int strLen_1 = strlen("' is not returned.");
unsigned int strLen_2 = strlen("Function '");
;                            
            ____BAH_COMPILER_VAR_570 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_570+currStrOff, "Function '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_570+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_570+currStrOff, "' is not returned.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&l->data[len(l)-1],____BAH_COMPILER_VAR_570);
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
char * ____BAH_COMPILER_VAR_571 =null;char * ____BAH_COMPILER_VAR_572 =rope__toStr(code);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nextLine);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_572);
;                            
            ____BAH_COMPILER_VAR_571 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_571+currStrOff, nextLine, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_571+currStrOff, ____BAH_COMPILER_VAR_572, strLen_1);
            currStrOff += strLen_1;
        
        }nextLine = ____BAH_COMPILER_VAR_571;
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
char * ____BAH_COMPILER_VAR_573 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(mbmType);
unsigned int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_573 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_573+currStrOff, mbmType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_573+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }mbmType = ____BAH_COMPILER_VAR_573;
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
char * ____BAH_COMPILER_VAR_574 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(memb->type);
unsigned int strLen_1 = strlen(" for member.");
unsigned int strLen_2 = strlen(") as ");
unsigned int strLen_3 = strlen(tt);
unsigned int strLen_4 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_574 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_574+currStrOff, "Cannot use {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_574+currStrOff, tt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_574+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_574+currStrOff, memb->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_574+currStrOff, " for member.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&t,____BAH_COMPILER_VAR_574);
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
char * ____BAH_COMPILER_VAR_575 =null;char * ____BAH_COMPILER_VAR_576 =string__str(&ct);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpfnArgsCType);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_576);
;                            
            ____BAH_COMPILER_VAR_575 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_575+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_575+currStrOff, ____BAH_COMPILER_VAR_576, strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_575;
j = j+1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_577 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpfnArgsCType);
unsigned int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_577 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_577+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_577+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_577;
}
};
char * ____BAH_COMPILER_VAR_578 =null;char * ____BAH_COMPILER_VAR_579 =string__str(&tmpfnRetCType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpfnArgsCType);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen(")(");
unsigned int strLen_3 = strlen(memb->name);
unsigned int strLen_4 = strlen(" (*");
unsigned int strLen_5 = strlen(____BAH_COMPILER_VAR_579);
;                            
            ____BAH_COMPILER_VAR_578 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_578+currStrOff, ____BAH_COMPILER_VAR_579, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_578+currStrOff, " (*", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_578+currStrOff, memb->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_578+currStrOff, ")(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_578+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_578+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }membDeclStr = ____BAH_COMPILER_VAR_578;
}
else {
struct string membDecl = getCType(memb->type,elems);
char * ____BAH_COMPILER_VAR_580 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(" ");
unsigned int strLen_1 = strlen(memb->name);
;                            
            ____BAH_COMPILER_VAR_580 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_580+currStrOff, " ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_580+currStrOff, memb->name, strLen_1);
            currStrOff += strLen_1;
        
        }string__append(&membDecl,____BAH_COMPILER_VAR_580);
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
char * ____BAH_COMPILER_VAR_581 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s->name);
unsigned int strLen_1 = strlen(" {\n");
unsigned int strLen_2 = strlen("struct ");
;                            
            ____BAH_COMPILER_VAR_581 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_581+currStrOff, "struct ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_581+currStrOff, s->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_581+currStrOff, " {\n", strLen_1);
            currStrOff += strLen_1;
        
        }struct rope* code = rope(____BAH_COMPILER_VAR_581);
i = 0;
while ((i<len(allMembs))) {
char * m = allMembs->data[i];
char * ____BAH_COMPILER_VAR_582 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(m);
unsigned int strLen_1 = strlen(";\n");
;                            
            ____BAH_COMPILER_VAR_582 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_582+currStrOff, m, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_582+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }code = rope__add(code, rope(____BAH_COMPILER_VAR_582));
++i;
};
code = rope__add(code, rope("};\n"));
OUTPUT = rope__add(OUTPUT, code);
}
if ((debug==true)) {
struct debugStruct* ____BAH_COMPILER_VAR_583 = memoryAlloc(sizeof(struct debugStruct));
____BAH_COMPILER_VAR_583->name= null;
____BAH_COMPILER_VAR_583->membs = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_583->membs->length = 0;
            ____BAH_COMPILER_VAR_583->membs->elemSize = sizeof(struct variable*);
            struct debugStruct* ds = ____BAH_COMPILER_VAR_583;
ds->name = s->name;
i = 0;
while ((i<len(s->members))) {
struct structMemb* m = s->members->data[i];
struct variable* ____BAH_COMPILER_VAR_584 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_584->name = "";
____BAH_COMPILER_VAR_584->type = "";
____BAH_COMPILER_VAR_584->isConst = false;
____BAH_COMPILER_VAR_584->constVal = "";
____BAH_COMPILER_VAR_584->isArray = false;
____BAH_COMPILER_VAR_584->from = "";
____BAH_COMPILER_VAR_584->declScope= null;
____BAH_COMPILER_VAR_584->isGlobal = false;
____BAH_COMPILER_VAR_584->declRope= null;
____BAH_COMPILER_VAR_584->isReg = false;
____BAH_COMPILER_VAR_584->lastSet= null;
____BAH_COMPILER_VAR_584->isArg = false;
struct variable* mv = ____BAH_COMPILER_VAR_584;
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
struct debugStruct* ____BAH_COMPILER_VAR_585 = ds;
char ** ____BAH_COMPILER_VAR_587 = (char **)((char*)(____BAH_COMPILER_VAR_585) + offsetof(struct debugStruct, name));
struct reflectElement ____BAH_COMPILER_VAR_588 = __reflect(____BAH_COMPILER_VAR_587, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct debugStruct, name));
array(struct variable*)** ____BAH_COMPILER_VAR_589 = (array(struct variable*)**)((char*)(____BAH_COMPILER_VAR_585) + offsetof(struct debugStruct, membs));
struct variable** ____BAH_COMPILER_VAR_590 = 0;
char ** ____BAH_COMPILER_VAR_592 = (char **)((char*)(____BAH_COMPILER_VAR_590) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_593 = __reflect(____BAH_COMPILER_VAR_592, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_594 = (char **)((char*)(____BAH_COMPILER_VAR_590) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_595 = __reflect(____BAH_COMPILER_VAR_594, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_596 = (char*)((char*)(____BAH_COMPILER_VAR_590) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_597 = __reflect(____BAH_COMPILER_VAR_596, sizeof(char), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_598 = (char **)((char*)(____BAH_COMPILER_VAR_590) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_599 = __reflect(____BAH_COMPILER_VAR_598, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_600 = (char*)((char*)(____BAH_COMPILER_VAR_590) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_601 = __reflect(____BAH_COMPILER_VAR_600, sizeof(char), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_602 = (char **)((char*)(____BAH_COMPILER_VAR_590) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_603 = __reflect(____BAH_COMPILER_VAR_602, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
void ** ____BAH_COMPILER_VAR_604 = (void **)((char*)(____BAH_COMPILER_VAR_590) + offsetof(struct variable, declScope));
struct reflectElement ____BAH_COMPILER_VAR_605 = __reflect(____BAH_COMPILER_VAR_604, sizeof(void *), "ptr", "declScope", 0, 0, 0, 0, offsetof(struct variable, declScope));
char* ____BAH_COMPILER_VAR_606 = (char*)((char*)(____BAH_COMPILER_VAR_590) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_607 = __reflect(____BAH_COMPILER_VAR_606, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));
struct rope** ____BAH_COMPILER_VAR_608 = (struct rope**)((char*)(____BAH_COMPILER_VAR_590) + offsetof(struct variable, declRope));
void ** ____BAH_COMPILER_VAR_610 = (void **)((char*)(____BAH_COMPILER_VAR_608) + offsetof(struct rope, left));
struct reflectElement ____BAH_COMPILER_VAR_611 = __reflect(____BAH_COMPILER_VAR_610, sizeof(void *), "ptr", "left", 0, 0, 0, 0, offsetof(struct rope, left));
void ** ____BAH_COMPILER_VAR_612 = (void **)((char*)(____BAH_COMPILER_VAR_608) + offsetof(struct rope, right));
struct reflectElement ____BAH_COMPILER_VAR_613 = __reflect(____BAH_COMPILER_VAR_612, sizeof(void *), "ptr", "right", 0, 0, 0, 0, offsetof(struct rope, right));
char ** ____BAH_COMPILER_VAR_614 = (char **)((char*)(____BAH_COMPILER_VAR_608) + offsetof(struct rope, str));
struct reflectElement ____BAH_COMPILER_VAR_615 = __reflect(____BAH_COMPILER_VAR_614, sizeof(char *), "cpstring", "str", 0, 0, 0, 0, offsetof(struct rope, str));
int* ____BAH_COMPILER_VAR_616 = (int*)((char*)(____BAH_COMPILER_VAR_608) + offsetof(struct rope, lCount));
struct reflectElement ____BAH_COMPILER_VAR_617 = __reflect(____BAH_COMPILER_VAR_616, sizeof(int), "int32", "lCount", 0, 0, 0, 0, offsetof(struct rope, lCount));
int* ____BAH_COMPILER_VAR_618 = (int*)((char*)(____BAH_COMPILER_VAR_608) + offsetof(struct rope, len));
struct reflectElement ____BAH_COMPILER_VAR_619 = __reflect(____BAH_COMPILER_VAR_618, sizeof(int), "int32", "len", 0, 0, 0, 0, offsetof(struct rope, len));
int* ____BAH_COMPILER_VAR_620 = (int*)((char*)(____BAH_COMPILER_VAR_608) + offsetof(struct rope, totalLen));
struct reflectElement ____BAH_COMPILER_VAR_621 = __reflect(____BAH_COMPILER_VAR_620, sizeof(int), "int32", "totalLen", 0, 0, 0, 0, offsetof(struct rope, totalLen));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_609 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_609->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_609->length = 6;
        ____BAH_COMPILER_VAR_609->data = memoryAlloc(____BAH_COMPILER_VAR_609->length * ____BAH_COMPILER_VAR_609->elemSize);
        ____BAH_COMPILER_VAR_609->data[0] = ____BAH_COMPILER_VAR_611;
____BAH_COMPILER_VAR_609->data[1] = ____BAH_COMPILER_VAR_613;
____BAH_COMPILER_VAR_609->data[2] = ____BAH_COMPILER_VAR_615;
____BAH_COMPILER_VAR_609->data[3] = ____BAH_COMPILER_VAR_617;
____BAH_COMPILER_VAR_609->data[4] = ____BAH_COMPILER_VAR_619;
____BAH_COMPILER_VAR_609->data[5] = ____BAH_COMPILER_VAR_621;
struct reflectElement ____BAH_COMPILER_VAR_622 = __reflect(____BAH_COMPILER_VAR_608, sizeof(struct rope), "rope*", "declRope", 0, 0, 1, ____BAH_COMPILER_VAR_609, offsetof(struct variable, declRope));
char* ____BAH_COMPILER_VAR_623 = (char*)((char*)(____BAH_COMPILER_VAR_590) + offsetof(struct variable, canBeReg));
struct reflectElement ____BAH_COMPILER_VAR_624 = __reflect(____BAH_COMPILER_VAR_623, sizeof(char), "bool", "canBeReg", 0, 0, 0, 0, offsetof(struct variable, canBeReg));
char* ____BAH_COMPILER_VAR_625 = (char*)((char*)(____BAH_COMPILER_VAR_590) + offsetof(struct variable, isReg));
struct reflectElement ____BAH_COMPILER_VAR_626 = __reflect(____BAH_COMPILER_VAR_625, sizeof(char), "bool", "isReg", 0, 0, 0, 0, offsetof(struct variable, isReg));
void ** ____BAH_COMPILER_VAR_627 = (void **)((char*)(____BAH_COMPILER_VAR_590) + offsetof(struct variable, lastSet));
struct reflectElement ____BAH_COMPILER_VAR_628 = __reflect(____BAH_COMPILER_VAR_627, sizeof(void *), "ptr", "lastSet", 0, 0, 0, 0, offsetof(struct variable, lastSet));
char* ____BAH_COMPILER_VAR_629 = (char*)((char*)(____BAH_COMPILER_VAR_590) + offsetof(struct variable, isArg));
struct reflectElement ____BAH_COMPILER_VAR_630 = __reflect(____BAH_COMPILER_VAR_629, sizeof(char), "bool", "isArg", 0, 0, 0, 0, offsetof(struct variable, isArg));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_591 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_591->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_591->length = 13;
        ____BAH_COMPILER_VAR_591->data = memoryAlloc(____BAH_COMPILER_VAR_591->length * ____BAH_COMPILER_VAR_591->elemSize);
        ____BAH_COMPILER_VAR_591->data[0] = ____BAH_COMPILER_VAR_593;
____BAH_COMPILER_VAR_591->data[1] = ____BAH_COMPILER_VAR_595;
____BAH_COMPILER_VAR_591->data[2] = ____BAH_COMPILER_VAR_597;
____BAH_COMPILER_VAR_591->data[3] = ____BAH_COMPILER_VAR_599;
____BAH_COMPILER_VAR_591->data[4] = ____BAH_COMPILER_VAR_601;
____BAH_COMPILER_VAR_591->data[5] = ____BAH_COMPILER_VAR_603;
____BAH_COMPILER_VAR_591->data[6] = ____BAH_COMPILER_VAR_605;
____BAH_COMPILER_VAR_591->data[7] = ____BAH_COMPILER_VAR_607;
____BAH_COMPILER_VAR_591->data[8] = ____BAH_COMPILER_VAR_622;
____BAH_COMPILER_VAR_591->data[9] = ____BAH_COMPILER_VAR_624;
____BAH_COMPILER_VAR_591->data[10] = ____BAH_COMPILER_VAR_626;
____BAH_COMPILER_VAR_591->data[11] = ____BAH_COMPILER_VAR_628;
____BAH_COMPILER_VAR_591->data[12] = ____BAH_COMPILER_VAR_630;
struct reflectElement ____BAH_COMPILER_VAR_631 = __reflect(____BAH_COMPILER_VAR_590, sizeof(struct variable), "variable*", "", 0, 0, 1, ____BAH_COMPILER_VAR_591, 0);

        struct reflectElement ____BAH_COMPILER_VAR_632 = ____BAH_COMPILER_VAR_631;
        struct reflectElement ____BAH_COMPILER_VAR_633 = __reflect(____BAH_COMPILER_VAR_589, sizeof(array(struct variable*)*), "[]variable*", "membs", 1, &____BAH_COMPILER_VAR_632, 0, 0, offsetof(struct debugStruct, membs));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_586 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_586->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_586->length = 2;
        ____BAH_COMPILER_VAR_586->data = memoryAlloc(____BAH_COMPILER_VAR_586->length * ____BAH_COMPILER_VAR_586->elemSize);
        ____BAH_COMPILER_VAR_586->data[0] = ____BAH_COMPILER_VAR_588;
____BAH_COMPILER_VAR_586->data[1] = ____BAH_COMPILER_VAR_633;
struct reflectElement ____BAH_COMPILER_VAR_634 = __reflect(____BAH_COMPILER_VAR_585, sizeof(struct debugStruct), "debugStruct*", "ds", 0, 0, 1, ____BAH_COMPILER_VAR_586, 0);
debugPrint("struct_declare",nameToken.line,____BAH_COMPILER_VAR_634);
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
struct func* ____BAH_COMPILER_VAR_635 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_635->name = "";
____BAH_COMPILER_VAR_635->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_635->args->length = 0;
            ____BAH_COMPILER_VAR_635->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_635->returns= null;
____BAH_COMPILER_VAR_635->isBinding = false;
____BAH_COMPILER_VAR_635->from = "";
____BAH_COMPILER_VAR_635->file = "";
____BAH_COMPILER_VAR_635->line = 1;
____BAH_COMPILER_VAR_635->isVar = false;
____BAH_COMPILER_VAR_635->used = false;
____BAH_COMPILER_VAR_635->code = null;
____BAH_COMPILER_VAR_635->isMut = false;
____BAH_COMPILER_VAR_635->isImported = false;
struct func* fn = ____BAH_COMPILER_VAR_635;
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
char * ____BAH_COMPILER_VAR_636 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(";\n");
;                            
            ____BAH_COMPILER_VAR_636 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_636+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_636+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_636));
}
}
else {
char * tp = "";
++i;
for (; (i<len(l)); ++i) {
struct Tok t = l->data[i];
char * ____BAH_COMPILER_VAR_637 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tp);
unsigned int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_637 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_637+currStrOff, tp, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_637+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }tp = ____BAH_COMPILER_VAR_637;
};
if ((ft.type!=TOKEN_TYPE_VAR)) {
throwErr(&ft,"Cannot use {TOKEN} as new type name.");
}
struct string cTypeNewType = getCType(tp,elems);
char * cTypeNewTypeStr = string__str(&cTypeNewType);
if ((doesOutput==true)) {
char * ____BAH_COMPILER_VAR_638 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ft.cont);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen(" ");
unsigned int strLen_3 = strlen(cTypeNewTypeStr);
unsigned int strLen_4 = strlen("typedef ");
;                            
            ____BAH_COMPILER_VAR_638 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_638+currStrOff, "typedef ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_638+currStrOff, cTypeNewTypeStr, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_638+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_638+currStrOff, ft.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_638+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_638));
}
if ((debug==true)) {
struct debugType* ____BAH_COMPILER_VAR_639 = memoryAlloc(sizeof(struct debugType));
____BAH_COMPILER_VAR_639->name= null;
____BAH_COMPILER_VAR_639->refers= null;
struct debugType* dt = ____BAH_COMPILER_VAR_639;
dt->name = ft.cont;
dt->refers = tp;
struct debugType* ____BAH_COMPILER_VAR_640 = dt;
char ** ____BAH_COMPILER_VAR_642 = (char **)((char*)(____BAH_COMPILER_VAR_640) + offsetof(struct debugType, name));
struct reflectElement ____BAH_COMPILER_VAR_643 = __reflect(____BAH_COMPILER_VAR_642, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct debugType, name));
char ** ____BAH_COMPILER_VAR_644 = (char **)((char*)(____BAH_COMPILER_VAR_640) + offsetof(struct debugType, refers));
struct reflectElement ____BAH_COMPILER_VAR_645 = __reflect(____BAH_COMPILER_VAR_644, sizeof(char *), "cpstring", "refers", 0, 0, 0, 0, offsetof(struct debugType, refers));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_641 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_641->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_641->length = 2;
        ____BAH_COMPILER_VAR_641->data = memoryAlloc(____BAH_COMPILER_VAR_641->length * ____BAH_COMPILER_VAR_641->elemSize);
        ____BAH_COMPILER_VAR_641->data[0] = ____BAH_COMPILER_VAR_643;
____BAH_COMPILER_VAR_641->data[1] = ____BAH_COMPILER_VAR_645;
struct reflectElement ____BAH_COMPILER_VAR_646 = __reflect(____BAH_COMPILER_VAR_640, sizeof(struct debugType), "debugType*", "dt", 0, 0, 1, ____BAH_COMPILER_VAR_641, 0);
debugPrint("type_declare",ft.line,____BAH_COMPILER_VAR_646);
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
struct variable* ____BAH_COMPILER_VAR_647 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_647->name = "";
____BAH_COMPILER_VAR_647->type = "";
____BAH_COMPILER_VAR_647->isConst = false;
____BAH_COMPILER_VAR_647->constVal = "";
____BAH_COMPILER_VAR_647->isArray = false;
____BAH_COMPILER_VAR_647->from = "";
____BAH_COMPILER_VAR_647->declScope= null;
____BAH_COMPILER_VAR_647->isGlobal = false;
____BAH_COMPILER_VAR_647->declRope= null;
____BAH_COMPILER_VAR_647->isReg = false;
____BAH_COMPILER_VAR_647->lastSet= null;
____BAH_COMPILER_VAR_647->isArg = false;
struct variable* v = ____BAH_COMPILER_VAR_647;
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
char * ____BAH_COMPILER_VAR_648 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(valt.cont);
unsigned int strLen_1 = strlen("\n");
unsigned int strLen_2 = strlen(" ");
unsigned int strLen_3 = strlen(v->name);
unsigned int strLen_4 = strlen("#define ");
;                            
            ____BAH_COMPILER_VAR_648 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_648+currStrOff, "#define ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_648+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_648+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_648+currStrOff, valt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_648+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_648));
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
char * ____BAH_COMPILER_VAR_649 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(currentFn->returns->type);
unsigned int strLen_1 = strlen(".");
unsigned int strLen_2 = strlen("Cannot return nothing as ");
;                            
            ____BAH_COMPILER_VAR_649 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_649+currStrOff, "Cannot return nothing as ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_649+currStrOff, currentFn->returns->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_649+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&l->data[0],____BAH_COMPILER_VAR_649);
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
char * ____BAH_COMPILER_VAR_650 =null;char * ____BAH_COMPILER_VAR_651 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(rvt.cont);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen("=");
unsigned int strLen_3 = strlen(rv);
unsigned int strLen_4 = strlen(" ");
unsigned int strLen_5 = strlen(____BAH_COMPILER_VAR_651);
;                            
            ____BAH_COMPILER_VAR_650 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_650+currStrOff, ____BAH_COMPILER_VAR_651, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_650+currStrOff, " ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_650+currStrOff, rv, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_650+currStrOff, "=", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_650+currStrOff, rvt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_650+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_650));
}
if ((compTypes(tt,currentFn->returns->type)==false)) {
char * ____BAH_COMPILER_VAR_652 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(currentFn->returns->type);
unsigned int strLen_1 = strlen(".");
unsigned int strLen_2 = strlen(") as ");
unsigned int strLen_3 = strlen(tt);
unsigned int strLen_4 = strlen("Cannot return {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_652 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_652+currStrOff, "Cannot return {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_652+currStrOff, tt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_652+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_652+currStrOff, currentFn->returns->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_652+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&rvt,____BAH_COMPILER_VAR_652);
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
char * ____BAH_COMPILER_VAR_653 =null;char * ____BAH_COMPILER_VAR_654 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(rv);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen(" = ");
unsigned int strLen_3 = strlen(rvar);
unsigned int strLen_4 = strlen(" ");
unsigned int strLen_5 = strlen(____BAH_COMPILER_VAR_654);
;                            
            ____BAH_COMPILER_VAR_653 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_653+currStrOff, ____BAH_COMPILER_VAR_654, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_653+currStrOff, " ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_653+currStrOff, rvar, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_653+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_653+currStrOff, rv, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_653+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_653));
if ((tmpV!=null)&&(tmpV->declScope!=elems)) {
OUTPUT = rope__add(OUTPUT, incrVar(tmpV,elems));
}
}
if (strHasPrefix(tt,"buffer:")) {
char * ____BAH_COMPILER_VAR_655 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(rvar);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen("__STR(");
;                            
            ____BAH_COMPILER_VAR_655 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_655+currStrOff, "__STR(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_655+currStrOff, rvar, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_655+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }rvar = ____BAH_COMPILER_VAR_655;
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
char * ____BAH_COMPILER_VAR_656 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(rvar);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen("return ");
;                            
            ____BAH_COMPILER_VAR_656 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_656+currStrOff, "return ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_656+currStrOff, rvar, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_656+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_656));
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
char * ____BAH_COMPILER_VAR_657 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(condt.cont);
unsigned int strLen_1 = strlen(") {\n");
unsigned int strLen_2 = strlen("if (");
;                            
            ____BAH_COMPILER_VAR_657 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_657+currStrOff, "if (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_657+currStrOff, condt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_657+currStrOff, ") {\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_657));
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
OUTPUT = rope__add(OUTPUT, rope("}\n"));
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
char * ____BAH_COMPILER_VAR_658 =rope__toStr(OUTPUT);struct string instC = string(____BAH_COMPILER_VAR_658);
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
char * ____BAH_COMPILER_VAR_659 =null;char * ____BAH_COMPILER_VAR_660 =string__str(&instC);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_660);
unsigned int strLen_1 = strlen(") {\n");
unsigned int strLen_2 = strlen("; ");
unsigned int strLen_3 = strlen(condt.cont);
unsigned int strLen_4 = strlen("for (; ");
;                            
            ____BAH_COMPILER_VAR_659 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_659+currStrOff, "for (; ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_659+currStrOff, condt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_659+currStrOff, "; ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_659+currStrOff, ____BAH_COMPILER_VAR_660, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_659+currStrOff, ") {\n", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_661 =____BAH_COMPILER_VAR_659;OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_661));
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
char * ____BAH_COMPILER_VAR_662 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(condt.cont);
unsigned int strLen_1 = strlen(") {\n");
unsigned int strLen_2 = strlen("while (");
;                            
            ____BAH_COMPILER_VAR_662 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_662+currStrOff, "while (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_662+currStrOff, condt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_662+currStrOff, ") {\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_662));
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
endRCPscopeLeaky(elems,null);
endRCPscopeLeaky(compilerState.currForElems,null);
char * ____BAH_COMPILER_VAR_663 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ft.cont);
unsigned int strLen_1 = strlen(";\n");
;                            
            ____BAH_COMPILER_VAR_663 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_663+currStrOff, ft.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_663+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_663));
};
void makeEvalFunc(struct func* fn,struct Elems* elems){

        char ____BAH_COMPILER_VAR_664 = 0;
        for(int i=compilerState.evals->length-1; i!=-1;i--) {
            if (compilerState.evals->data[i] != 0 && strcmp(compilerState.evals->data[i], fn->name) == 0) {
                ____BAH_COMPILER_VAR_664=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_664) {
return;
}
char * ____BAH_COMPILER_VAR_665 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("__Bah_eval_");
unsigned int strLen_1 = strlen(fn->name);
;                            
            ____BAH_COMPILER_VAR_665 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_665+currStrOff, "__Bah_eval_", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_665+currStrOff, fn->name, strLen_1);
            currStrOff += strLen_1;
        
        }struct func* ____BAH_COMPILER_VAR_666 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_666->name = "";
____BAH_COMPILER_VAR_666->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_666->args->length = 0;
            ____BAH_COMPILER_VAR_666->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_666->returns= null;
____BAH_COMPILER_VAR_666->isBinding = false;
____BAH_COMPILER_VAR_666->from = "";
____BAH_COMPILER_VAR_666->file = "";
____BAH_COMPILER_VAR_666->line = 1;
____BAH_COMPILER_VAR_666->isVar = false;
____BAH_COMPILER_VAR_666->used = false;
____BAH_COMPILER_VAR_666->code = null;
____BAH_COMPILER_VAR_666->isMut = false;
____BAH_COMPILER_VAR_666->isImported = false;
____BAH_COMPILER_VAR_666->name = ____BAH_COMPILER_VAR_665;
struct func* efn = ____BAH_COMPILER_VAR_666;
struct variable* ____BAH_COMPILER_VAR_667 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_667->name = "";
____BAH_COMPILER_VAR_667->type = "";
____BAH_COMPILER_VAR_667->isConst = false;
____BAH_COMPILER_VAR_667->constVal = "";
____BAH_COMPILER_VAR_667->isArray = false;
____BAH_COMPILER_VAR_667->from = "";
____BAH_COMPILER_VAR_667->declScope= null;
____BAH_COMPILER_VAR_667->isGlobal = false;
____BAH_COMPILER_VAR_667->declRope= null;
____BAH_COMPILER_VAR_667->isReg = false;
____BAH_COMPILER_VAR_667->lastSet= null;
____BAH_COMPILER_VAR_667->isArg = false;
____BAH_COMPILER_VAR_667->type = "ptr";
efn->returns = ____BAH_COMPILER_VAR_667;
struct variable* ____BAH_COMPILER_VAR_668 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_668->name = "";
____BAH_COMPILER_VAR_668->type = "";
____BAH_COMPILER_VAR_668->isConst = false;
____BAH_COMPILER_VAR_668->constVal = "";
____BAH_COMPILER_VAR_668->isArray = false;
____BAH_COMPILER_VAR_668->from = "";
____BAH_COMPILER_VAR_668->declScope= null;
____BAH_COMPILER_VAR_668->isGlobal = false;
____BAH_COMPILER_VAR_668->declRope= null;
____BAH_COMPILER_VAR_668->isReg = false;
____BAH_COMPILER_VAR_668->lastSet= null;
____BAH_COMPILER_VAR_668->isArg = false;
____BAH_COMPILER_VAR_668->name = "fnArgs";
____BAH_COMPILER_VAR_668->type = "[]ptr";
efn->args = memoryAlloc(sizeof(array(struct variable*)));

efn->args->length = 1;
efn->args->elemSize = sizeof(struct variable*);
efn->args->data = memoryAlloc(sizeof(struct variable*) * 50);
                    efn->args->realLength = 50;
efn->args->data[0] = ____BAH_COMPILER_VAR_668;
char * fnBinding = "";
char * ____BAH_COMPILER_VAR_669 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fn->name);
unsigned int strLen_1 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_669 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_669+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_669+currStrOff, "(", strLen_1);
            currStrOff += strLen_1;
        
        }char * fnCall = ____BAH_COMPILER_VAR_669;
register long int i = 0;
for (; (i<len(fn->args)); ++i) {
struct variable* a = fn->args->data[i];
char * v = genCompilerVar();
struct string cType = getCType(a->type,elems);
if ((isRCPpointerType(a->type)==false)) {
string__append(&cType,"*");
}
char * ____BAH_COMPILER_VAR_670 =null;char * ____BAH_COMPILER_VAR_671 =intToStr(i);char * ____BAH_COMPILER_VAR_672 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_671);
unsigned int strLen_1 = strlen("];");
unsigned int strLen_2 = strlen(" = fnArgs->data[");
unsigned int strLen_3 = strlen(v);
unsigned int strLen_4 = strlen(" ");
unsigned int strLen_5 = strlen(____BAH_COMPILER_VAR_672);
;                            
            ____BAH_COMPILER_VAR_670 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_670+currStrOff, ____BAH_COMPILER_VAR_672, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_670+currStrOff, " ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_670+currStrOff, v, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_670+currStrOff, " = fnArgs->data[", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_670+currStrOff, ____BAH_COMPILER_VAR_671, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_670+currStrOff, "];", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_673 =null;char * ____BAH_COMPILER_VAR_674 =____BAH_COMPILER_VAR_670;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnBinding);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_674);
;                            
            ____BAH_COMPILER_VAR_673 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_673+currStrOff, fnBinding, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_673+currStrOff, ____BAH_COMPILER_VAR_674, strLen_1);
            currStrOff += strLen_1;
        
        }fnBinding = ____BAH_COMPILER_VAR_673;
if ((i!=0)) {
char * ____BAH_COMPILER_VAR_675 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnCall);
unsigned int strLen_1 = strlen(", ");
;                            
            ____BAH_COMPILER_VAR_675 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_675+currStrOff, fnCall, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_675+currStrOff, ", ", strLen_1);
            currStrOff += strLen_1;
        
        }fnCall = ____BAH_COMPILER_VAR_675;
}
if (isRCPpointerType(a->type)) {
char * ____BAH_COMPILER_VAR_676 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnCall);
unsigned int strLen_1 = strlen(v);
;                            
            ____BAH_COMPILER_VAR_676 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_676+currStrOff, fnCall, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_676+currStrOff, v, strLen_1);
            currStrOff += strLen_1;
        
        }fnCall = ____BAH_COMPILER_VAR_676;
}
else {
char * ____BAH_COMPILER_VAR_677 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("*");
unsigned int strLen_1 = strlen(v);
;                            
            ____BAH_COMPILER_VAR_677 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_677+currStrOff, "*", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_677+currStrOff, v, strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_678 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnCall);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_677);
;                            
            ____BAH_COMPILER_VAR_678 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_678+currStrOff, fnCall, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_678+currStrOff, ____BAH_COMPILER_VAR_677, strLen_1);
            currStrOff += strLen_1;
        
        }fnCall = ____BAH_COMPILER_VAR_678;
}
};
char * setReturnValue = "void* r = 0;";
if (isRCPpointerType(fn->returns->type)) {
setReturnValue = "void* r = ";
}
else {
struct string cType = getCType(fn->returns->type,elems);
if ((strcmp(string__str(&cType), "void") != 0)) {
char * ____BAH_COMPILER_VAR_679 =null;char * ____BAH_COMPILER_VAR_680 =string__str(&cType);char * ____BAH_COMPILER_VAR_681 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_680);
unsigned int strLen_1 = strlen("));*r = ");
unsigned int strLen_2 = strlen("* r = memoryAlloc(sizeof(");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_681);
;                            
            ____BAH_COMPILER_VAR_679 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_679+currStrOff, ____BAH_COMPILER_VAR_681, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_679+currStrOff, "* r = memoryAlloc(sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_679+currStrOff, ____BAH_COMPILER_VAR_680, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_679+currStrOff, "));*r = ", strLen_1);
            currStrOff += strLen_1;
        
        }setReturnValue = ____BAH_COMPILER_VAR_679;
}
}
char * ____BAH_COMPILER_VAR_682 =null;char * ____BAH_COMPILER_VAR_683 =intToStr(len(fn->args));
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
unsigned int strLen_8 = strlen(____BAH_COMPILER_VAR_683);
unsigned int strLen_9 = strlen("(array(void*)* fnArgs) {\n        if (fnArgs->length != ");
unsigned int strLen_10 = strlen(efn->name);
unsigned int strLen_11 = strlen("void* __attribute__((optimize(\"O0\"))) ");
;                            
            ____BAH_COMPILER_VAR_682 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11);
            
                    memcpy(____BAH_COMPILER_VAR_682+currStrOff, "void* __attribute__((optimize(\"O0\"))) ", strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_682+currStrOff, efn->name, strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_682+currStrOff, "(array(void*)* fnArgs) {\n        if (fnArgs->length != ", strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_682+currStrOff, ____BAH_COMPILER_VAR_683, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_682+currStrOff, ") {\n            __BAH_panic((char*)\"eval: calling function ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_682+currStrOff, fn->name, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_682+currStrOff, "() with the wrong number of arguments.\", \"BAH_COMPILER_INTERNAL\");\n        }\n        ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_682+currStrOff, fnBinding, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_682+currStrOff, "\n        ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_682+currStrOff, setReturnValue, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_682+currStrOff, fnCall, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_682+currStrOff, ");\n        return (void*)r;\n    };", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_682));

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
char * ____BAH_COMPILER_VAR_684 =string__str(&msg);throwWarning(____BAH_COMPILER_VAR_684);
return;
}
if ((strcmp(ft.cont, "#eval") == 0)) {

        char ____BAH_COMPILER_VAR_685 = 0;
        for(int i=compilerState.includes->length-1; i!=-1;i--) {
            if (compilerState.includes->data[i] != 0 && strcmp(compilerState.includes->data[i], "eval.bah") == 0) {
                ____BAH_COMPILER_VAR_685=1;
                break;
            };
        }
        if ((____BAH_COMPILER_VAR_685==false)) {
if ((includeFile("eval.bah",elems)==false)) {
char * ____BAH_COMPILER_VAR_686 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(BAH_DIR);
unsigned int strLen_1 = strlen(").");
unsigned int strLen_2 = strlen("Could not find file 'eval.bah'. Check your bah directory (");
;                            
            ____BAH_COMPILER_VAR_686 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_686+currStrOff, "Could not find file 'eval.bah'. Check your bah directory (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_686+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_686+currStrOff, ").", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&l->data[0],____BAH_COMPILER_VAR_686);
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
char * ____BAH_COMPILER_VAR_687 =null;char * ____BAH_COMPILER_VAR_688 =string__str(&fnName);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_688);
unsigned int strLen_1 = strlen("', arround {TOKEN}.");
unsigned int strLen_2 = strlen("Internal compiler error.\n Error parsing async call for function '");
;                            
            ____BAH_COMPILER_VAR_687 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_687+currStrOff, "Internal compiler error.\n Error parsing async call for function '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_687+currStrOff, ____BAH_COMPILER_VAR_688, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_687+currStrOff, "', arround {TOKEN}.", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_689 =____BAH_COMPILER_VAR_687;throwErr(&fnT,____BAH_COMPILER_VAR_689);
}
fnName = string(fn->name);
char * sMembs = "";
char * unSerMembs = "";
i = 0;
while ((i<len(fn->args))) {
struct variable* a = fn->args->data[i];
struct string cType = getCType(a->type,elems);
char * ____BAH_COMPILER_VAR_690 =null;char * ____BAH_COMPILER_VAR_691 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(a->name);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen(" ");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_691);
unsigned int strLen_4 = strlen(sMembs);
;                            
            ____BAH_COMPILER_VAR_690 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_690+currStrOff, sMembs, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_690+currStrOff, ____BAH_COMPILER_VAR_691, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_690+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_690+currStrOff, a->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_690+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }sMembs = ____BAH_COMPILER_VAR_690;
char * ____BAH_COMPILER_VAR_692 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("args->");
unsigned int strLen_1 = strlen(a->name);
unsigned int strLen_2 = strlen(unSerMembs);
;                            
            ____BAH_COMPILER_VAR_692 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_692+currStrOff, unSerMembs, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_692+currStrOff, "args->", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_692+currStrOff, a->name, strLen_1);
            currStrOff += strLen_1;
        
        }unSerMembs = ____BAH_COMPILER_VAR_692;
i = i+1;
if ((i<len(fn->args))) {
char * ____BAH_COMPILER_VAR_693 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(unSerMembs);
unsigned int strLen_1 = strlen(", ");
;                            
            ____BAH_COMPILER_VAR_693 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_693+currStrOff, unSerMembs, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_693+currStrOff, ", ", strLen_1);
            currStrOff += strLen_1;
        
        }unSerMembs = ____BAH_COMPILER_VAR_693;
}
};
char * ____BAH_COMPILER_VAR_694 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(sMembs);
unsigned int strLen_1 = strlen("}");
unsigned int strLen_2 = strlen("struct {\n");
;                            
            ____BAH_COMPILER_VAR_694 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_694+currStrOff, "struct {\n", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_694+currStrOff, sMembs, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_694+currStrOff, "}", strLen_1);
            currStrOff += strLen_1;
        
        }char * tmpArgsStruct = ____BAH_COMPILER_VAR_694;
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
char * ____BAH_COMPILER_VAR_695 =null;char * ____BAH_COMPILER_VAR_696 =string__str(&sFnT);char * ____BAH_COMPILER_VAR_697 =string__str(&fnName);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpArgs);
unsigned int strLen_1 = strlen(");\n    }; \n    \n    ");
unsigned int strLen_2 = strlen(", &");
unsigned int strLen_3 = strlen(fnWrapper);
unsigned int strLen_4 = strlen("(&id, 0, ");
unsigned int strLen_5 = strlen(tCreate);
unsigned int strLen_6 = strlen("};\n        pthread_t id;\n        ");
unsigned int strLen_7 = strlen(____BAH_COMPILER_VAR_696);
unsigned int strLen_8 = strlen(" = {");
unsigned int strLen_9 = strlen(tmpArgs);
unsigned int strLen_10 = strlen(" ");
unsigned int strLen_11 = strlen(tmpArgsStruct);
unsigned int strLen_12 = strlen(");\n    };\n    {\n        ");
unsigned int strLen_13 = strlen(unSerMembs);
unsigned int strLen_14 = strlen("(");
unsigned int strLen_15 = strlen(____BAH_COMPILER_VAR_697);
unsigned int strLen_16 = strlen("* args) {\n        ");
unsigned int strLen_17 = strlen(tmpArgsStruct);
unsigned int strLen_18 = strlen("(");
unsigned int strLen_19 = strlen(fnWrapper);
unsigned int strLen_20 = strlen("\n    void ");
;                            
            ____BAH_COMPILER_VAR_695 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13+strLen_14+strLen_15+strLen_16+strLen_17+strLen_18+strLen_19+strLen_20);
            
                    memcpy(____BAH_COMPILER_VAR_695+currStrOff, "\n    void ", strLen_20);
                    currStrOff += strLen_20;
                    
                    memcpy(____BAH_COMPILER_VAR_695+currStrOff, fnWrapper, strLen_19);
                    currStrOff += strLen_19;
                    
                    memcpy(____BAH_COMPILER_VAR_695+currStrOff, "(", strLen_18);
                    currStrOff += strLen_18;
                    
                    memcpy(____BAH_COMPILER_VAR_695+currStrOff, tmpArgsStruct, strLen_17);
                    currStrOff += strLen_17;
                    
                    memcpy(____BAH_COMPILER_VAR_695+currStrOff, "* args) {\n        ", strLen_16);
                    currStrOff += strLen_16;
                    
                    memcpy(____BAH_COMPILER_VAR_695+currStrOff, ____BAH_COMPILER_VAR_697, strLen_15);
                    currStrOff += strLen_15;
                    
                    memcpy(____BAH_COMPILER_VAR_695+currStrOff, "(", strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_695+currStrOff, unSerMembs, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_695+currStrOff, ");\n    };\n    {\n        ", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_695+currStrOff, tmpArgsStruct, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_695+currStrOff, " ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_695+currStrOff, tmpArgs, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_695+currStrOff, " = {", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_695+currStrOff, ____BAH_COMPILER_VAR_696, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_695+currStrOff, "};\n        pthread_t id;\n        ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_695+currStrOff, tCreate, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_695+currStrOff, "(&id, 0, ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_695+currStrOff, fnWrapper, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_695+currStrOff, ", &", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_695+currStrOff, tmpArgs, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_695+currStrOff, ");\n    }; \n    \n    ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_695));
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
char * ____BAH_COMPILER_VAR_698 =getTypeFromToken(&nt,true,elems);struct string ntt = string(____BAH_COMPILER_VAR_698);
if ((string__hasPrefix(&ntt,"chan:")==0)) {
char * ____BAH_COMPILER_VAR_699 =null;char * ____BAH_COMPILER_VAR_700 =string__str(&ntt);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_700);
unsigned int strLen_1 = strlen(") as channel.");
unsigned int strLen_2 = strlen("Cannot use var {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_699 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_699+currStrOff, "Cannot use var {TOKEN} (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_699+currStrOff, ____BAH_COMPILER_VAR_700, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_699+currStrOff, ") as channel.", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_701 =____BAH_COMPILER_VAR_699;throwErr(&nt,____BAH_COMPILER_VAR_701);
}
string__trimLeft(&ntt,5);
if (isGlobal()) {
throwErr(&t,"Cannot receive ({TOKEN}) from a channel outside of a function.");
}
char * tmpV = "";
char * ____BAH_COMPILER_VAR_702 =string__str(&ntt);if (isRCPpointerType(____BAH_COMPILER_VAR_702)) {
char * ____BAH_COMPILER_VAR_703 =string__str(&ntt);struct string ct = getCType(____BAH_COMPILER_VAR_703,elems);
char * ____BAH_COMPILER_VAR_704 =null;char * ____BAH_COMPILER_VAR_705 =string__str(&ct);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen("->receive(");
unsigned int strLen_3 = strlen(nt.cont);
unsigned int strLen_4 = strlen(")");
unsigned int strLen_5 = strlen(____BAH_COMPILER_VAR_705);
unsigned int strLen_6 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_704 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_704+currStrOff, "(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_704+currStrOff, ____BAH_COMPILER_VAR_705, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_704+currStrOff, ")", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_704+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_704+currStrOff, "->receive(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_704+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_704+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_704;
}
else {
char * ____BAH_COMPILER_VAR_706 =string__str(&ntt);struct string ct = getCType(____BAH_COMPILER_VAR_706,elems);
if (RCPavailable()) {
char * ____BAH_COMPILER_VAR_707 =null;char * ____BAH_COMPILER_VAR_708 =string__str(&ntt);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_708);
unsigned int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_707 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_707+currStrOff, ____BAH_COMPILER_VAR_708, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_707+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_709 =null;char * ____BAH_COMPILER_VAR_710 =string__str(&ct);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen("->receive(");
unsigned int strLen_3 = strlen(nt.cont);
unsigned int strLen_4 = strlen("*)");
unsigned int strLen_5 = strlen(____BAH_COMPILER_VAR_710);
unsigned int strLen_6 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_709 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_709+currStrOff, "(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_709+currStrOff, ____BAH_COMPILER_VAR_710, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_709+currStrOff, "*)", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_709+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_709+currStrOff, "->receive(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_709+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_709+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_711 =____BAH_COMPILER_VAR_707;tmpV = registerRCPvar(____BAH_COMPILER_VAR_711,____BAH_COMPILER_VAR_709,elems);
char * ____BAH_COMPILER_VAR_712 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("*");
unsigned int strLen_1 = strlen(tmpV);
;                            
            ____BAH_COMPILER_VAR_712 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_712+currStrOff, "*", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_712+currStrOff, tmpV, strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_712;
}
else {
char * ____BAH_COMPILER_VAR_713 =null;char * ____BAH_COMPILER_VAR_714 =string__str(&ct);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen("->receive(");
unsigned int strLen_3 = strlen(nt.cont);
unsigned int strLen_4 = strlen("*)");
unsigned int strLen_5 = strlen(____BAH_COMPILER_VAR_714);
unsigned int strLen_6 = strlen("*(");
;                            
            ____BAH_COMPILER_VAR_713 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_713+currStrOff, "*(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_713+currStrOff, ____BAH_COMPILER_VAR_714, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_713+currStrOff, "*)", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_713+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_713+currStrOff, "->receive(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_713+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_713+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_713;
}
}
t.type = TOKEN_TYPE_FUNC;
t.isFunc = true;
if (RCPavailable()) {
char * ____BAH_COMPILER_VAR_715 =string__str(&ntt);if (isRCPpointerType(____BAH_COMPILER_VAR_715)) {
char * ____BAH_COMPILER_VAR_716 =string__str(&ntt);tmpV = registerRCPvar(____BAH_COMPILER_VAR_716,t.cont,elems);
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
char * ____BAH_COMPILER_VAR_717 =getTypeFromToken(&pt,true,elems);struct string ptt = string(____BAH_COMPILER_VAR_717);
if ((string__hasPrefix(&ptt,"chan:")==0)) {
char * ____BAH_COMPILER_VAR_718 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ntt);
unsigned int strLen_1 = strlen(") as channel.");
unsigned int strLen_2 = strlen("Cannot use var {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_718 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_718+currStrOff, "Cannot use var {TOKEN} (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_718+currStrOff, ntt, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_718+currStrOff, ") as channel.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&pt,____BAH_COMPILER_VAR_718);
}
string__trimLeft(&ptt,5);
if (isGlobal()) {
throwErr(&t,"Cannot send ({TOKEN}) to a channel outside of a function.");
}
char * ____BAH_COMPILER_VAR_719 =string__str(&ptt);if ((compTypes(____BAH_COMPILER_VAR_719,ntt)==false)) {
char * ____BAH_COMPILER_VAR_720 =null;char * ____BAH_COMPILER_VAR_721 =string__str(&ptt);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_721);
unsigned int strLen_1 = strlen(".");
unsigned int strLen_2 = strlen(") to channel of type ");
unsigned int strLen_3 = strlen(ntt);
unsigned int strLen_4 = strlen("Cannot send {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_720 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_720+currStrOff, "Cannot send {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_720+currStrOff, ntt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_720+currStrOff, ") to channel of type ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_720+currStrOff, ____BAH_COMPILER_VAR_721, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_720+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_722 =____BAH_COMPILER_VAR_720;throwErr(&nt,____BAH_COMPILER_VAR_722);
}
++i;
char * ____BAH_COMPILER_VAR_723 =string__str(&ptt);if (isRCPpointerType(____BAH_COMPILER_VAR_723)) {
char * ____BAH_COMPILER_VAR_724 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen(");\n");
unsigned int strLen_2 = strlen(", ");
unsigned int strLen_3 = strlen(pt.cont);
unsigned int strLen_4 = strlen("->send(");
unsigned int strLen_5 = strlen(pt.cont);
;                            
            ____BAH_COMPILER_VAR_724 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_724+currStrOff, pt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_724+currStrOff, "->send(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_724+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_724+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_724+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_724+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_724));
}
else {
struct string ct = getCType(ntt,elems);
char * tmpV = genCompilerVar();
char * ____BAH_COMPILER_VAR_725 =null;char * ____BAH_COMPILER_VAR_726 =string__str(&ct);
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
unsigned int strLen_13 = strlen(____BAH_COMPILER_VAR_726);
unsigned int strLen_14 = strlen("\n                    ");
;                            
            ____BAH_COMPILER_VAR_725 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13+strLen_14);
            
                    memcpy(____BAH_COMPILER_VAR_725+currStrOff, "\n                    ", strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_725+currStrOff, ____BAH_COMPILER_VAR_726, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_725+currStrOff, " ", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_725+currStrOff, tmpV, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_725+currStrOff, " = ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_725+currStrOff, nt.cont, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_725+currStrOff, ";\n                    ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_725+currStrOff, pt.cont, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_725+currStrOff, "->sendAny(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_725+currStrOff, pt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_725+currStrOff, ", &", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_725+currStrOff, tmpV, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_725+currStrOff, ", sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_725+currStrOff, tmpV, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_725+currStrOff, "));\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_725));
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
char * ____BAH_COMPILER_VAR_727 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnt.ogCont);
unsigned int strLen_1 = strlen(t.ogCont);
;                            
            ____BAH_COMPILER_VAR_727 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_727+currStrOff, fnt.ogCont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_727+currStrOff, t.ogCont, strLen_1);
            currStrOff += strLen_1;
        
        }fnt.ogCont = ____BAH_COMPILER_VAR_727;
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
char * ____BAH_COMPILER_VAR_728 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnt.cont);
unsigned int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_728 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_728+currStrOff, fnt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_728+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_728;
};
char * ____BAH_COMPILER_VAR_729 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnt.cont);
unsigned int strLen_1 = strlen(")");
;                            
            ____BAH_COMPILER_VAR_729 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_729+currStrOff, fnt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_729+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_729;

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
char * ____BAH_COMPILER_VAR_730 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fn->name);
unsigned int strLen_1 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_730 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_730+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_730+currStrOff, "(", strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_730;
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
char * ____BAH_COMPILER_VAR_731 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fn->name);
unsigned int strLen_1 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_731 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_731+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_731+currStrOff, "(", strLen_1);
            currStrOff += strLen_1;
        
        }fnt.ogCont = ____BAH_COMPILER_VAR_731;
for (; (i<len(l)); ++i) {
struct Tok t = l->data[i];
char * ____BAH_COMPILER_VAR_732 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnt.ogCont);
unsigned int strLen_1 = strlen(t.ogCont);
;                            
            ____BAH_COMPILER_VAR_732 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_732+currStrOff, fnt.ogCont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_732+currStrOff, t.ogCont, strLen_1);
            currStrOff += strLen_1;
        
        }fnt.ogCont = ____BAH_COMPILER_VAR_732;
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
char * ____BAH_COMPILER_VAR_733 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnt.cont);
unsigned int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_733 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_733+currStrOff, fnt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_733+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_733;
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
char * ____BAH_COMPILER_VAR_734 =null;char * ____BAH_COMPILER_VAR_735 =intToStr(fnt.line);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_735);
unsigned int strLen_1 = strlen("\"");
unsigned int strLen_2 = strlen(":");
unsigned int strLen_3 = strlen(compilerState.currentFile);
unsigned int strLen_4 = strlen("\"");
;                            
            ____BAH_COMPILER_VAR_734 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_734+currStrOff, "\"", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_734+currStrOff, compilerState.currentFile, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_734+currStrOff, ":", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_734+currStrOff, ____BAH_COMPILER_VAR_735, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_734+currStrOff, "\"", strLen_1);
            currStrOff += strLen_1;
        
        }char * currLine = ____BAH_COMPILER_VAR_734;
if ((strcmp(fn->name, "panic") == 0)) {
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
____BAH_COMPILER_VAR_736.parent= null;
____BAH_COMPILER_VAR_736.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_736.cont = ",";
____BAH_COMPILER_VAR_736.line = fnt.line;

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
            memory->data[len(memory)] = ____BAH_COMPILER_VAR_736;
            memory->length = nLength+1;
        } else {
            memory->data[len(memory)] = ____BAH_COMPILER_VAR_736;
        }
    }
    ;
struct Tok ____BAH_COMPILER_VAR_737 = {};
____BAH_COMPILER_VAR_737.cont = "";
____BAH_COMPILER_VAR_737.ogCont = "";
____BAH_COMPILER_VAR_737.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_737.pos = 0;
____BAH_COMPILER_VAR_737.line = 1;
____BAH_COMPILER_VAR_737.begLine = 1;
____BAH_COMPILER_VAR_737.bahType = "";
____BAH_COMPILER_VAR_737.isValue = false;
____BAH_COMPILER_VAR_737.isFunc = false;
____BAH_COMPILER_VAR_737.isOper = false;
____BAH_COMPILER_VAR_737.isEqual = false;
____BAH_COMPILER_VAR_737.pass = false;
____BAH_COMPILER_VAR_737.bahRef= null;
____BAH_COMPILER_VAR_737.parent= null;
____BAH_COMPILER_VAR_737.type = TOKEN_TYPE_STR;
____BAH_COMPILER_VAR_737.cont = currLine;
____BAH_COMPILER_VAR_737.line = fnt.line;

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
            memory->data[len(memory)] = ____BAH_COMPILER_VAR_737;
            memory->length = nLength+1;
        } else {
            memory->data[len(memory)] = ____BAH_COMPILER_VAR_737;
        }
    }
    ;
fn = searchFunc("__BAH_panic",elems,true);
char * ____BAH_COMPILER_VAR_738 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fn->name);
unsigned int strLen_1 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_738 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_738+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_738+currStrOff, "(", strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_738;
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
struct variable* ____BAH_COMPILER_VAR_739 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_739->name = "";
____BAH_COMPILER_VAR_739->type = "";
____BAH_COMPILER_VAR_739->isConst = false;
____BAH_COMPILER_VAR_739->constVal = "";
____BAH_COMPILER_VAR_739->isArray = false;
____BAH_COMPILER_VAR_739->from = "";
____BAH_COMPILER_VAR_739->declScope= null;
____BAH_COMPILER_VAR_739->isGlobal = false;
____BAH_COMPILER_VAR_739->declRope= null;
____BAH_COMPILER_VAR_739->isReg = false;
____BAH_COMPILER_VAR_739->lastSet= null;
____BAH_COMPILER_VAR_739->isArg = false;
____BAH_COMPILER_VAR_739->name = genCompilerVar();
____BAH_COMPILER_VAR_739->type = "[]reflectElement";
____BAH_COMPILER_VAR_739->isArray = true;
struct variable* tmpV = ____BAH_COMPILER_VAR_739;
char * decls = "";
j = 0;
for (; (j<len(symbols)); ++j) {
struct variable* v = symbols->data[j];
char * vname = v->name;
if ((strCount(v->type,"*")==0)) {
char * ____BAH_COMPILER_VAR_740 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("&");
unsigned int strLen_1 = strlen(v->name);
;                            
            ____BAH_COMPILER_VAR_740 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_740+currStrOff, "&", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_740+currStrOff, v->name, strLen_1);
            currStrOff += strLen_1;
        
        }vname = ____BAH_COMPILER_VAR_740;
}
struct Tok ____BAH_COMPILER_VAR_741 = {};
____BAH_COMPILER_VAR_741.cont = "";
____BAH_COMPILER_VAR_741.ogCont = "";
____BAH_COMPILER_VAR_741.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_741.pos = 0;
____BAH_COMPILER_VAR_741.line = 1;
____BAH_COMPILER_VAR_741.begLine = 1;
____BAH_COMPILER_VAR_741.bahType = "";
____BAH_COMPILER_VAR_741.isValue = false;
____BAH_COMPILER_VAR_741.isFunc = false;
____BAH_COMPILER_VAR_741.isOper = false;
____BAH_COMPILER_VAR_741.isEqual = false;
____BAH_COMPILER_VAR_741.pass = false;
____BAH_COMPILER_VAR_741.bahRef= null;
____BAH_COMPILER_VAR_741.parent= null;
____BAH_COMPILER_VAR_741.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_741.cont = vname;
____BAH_COMPILER_VAR_741.bahType = v->type;
____BAH_COMPILER_VAR_741.isValue = true;
#define tmpT ____BAH_COMPILER_VAR_741
tmpT = parseReflect(tmpT,v->type,elems,true,v->name,"0");
char * ____BAH_COMPILER_VAR_742 =null;char * ____BAH_COMPILER_VAR_743 =intToStr(j);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpT.cont);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen("] = ");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_743);
unsigned int strLen_4 = strlen("->data[");
unsigned int strLen_5 = strlen(tmpV->name);
;                            
            ____BAH_COMPILER_VAR_742 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_742+currStrOff, tmpV->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_742+currStrOff, "->data[", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_742+currStrOff, ____BAH_COMPILER_VAR_743, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_742+currStrOff, "] = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_742+currStrOff, tmpT.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_742+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_744 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(decls);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_742);
;                            
            ____BAH_COMPILER_VAR_744 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_744+currStrOff, decls, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_744+currStrOff, ____BAH_COMPILER_VAR_742, strLen_1);
            currStrOff += strLen_1;
        
        }decls = ____BAH_COMPILER_VAR_744;

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
char * ____BAH_COMPILER_VAR_745 =null;char * ____BAH_COMPILER_VAR_746 =intToStr(len(symbols));char * ____BAH_COMPILER_VAR_747 =intToStr(len(symbols));
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(decls);
unsigned int strLen_1 = strlen("\n        ");
unsigned int strLen_2 = strlen("->elemSize = sizeof(struct reflectElement);\n        ");
unsigned int strLen_3 = strlen(tmpV->name);
unsigned int strLen_4 = strlen(";\n        ");
unsigned int strLen_5 = strlen(____BAH_COMPILER_VAR_746);
unsigned int strLen_6 = strlen("->length = ");
unsigned int strLen_7 = strlen(tmpV->name);
unsigned int strLen_8 = strlen(");\n        ");
unsigned int strLen_9 = strlen(____BAH_COMPILER_VAR_747);
unsigned int strLen_10 = strlen("->data = memoryAlloc(sizeof(struct reflectElement) * ");
unsigned int strLen_11 = strlen(tmpV->name);
unsigned int strLen_12 = strlen(" = memoryAlloc(sizeof(array(struct reflectElement)));\n        ");
unsigned int strLen_13 = strlen(tmpV->name);
unsigned int strLen_14 = strlen("\n        array(struct reflectElement)* ");
;                            
            ____BAH_COMPILER_VAR_745 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13+strLen_14);
            
                    memcpy(____BAH_COMPILER_VAR_745+currStrOff, "\n        array(struct reflectElement)* ", strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_745+currStrOff, tmpV->name, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_745+currStrOff, " = memoryAlloc(sizeof(array(struct reflectElement)));\n        ", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_745+currStrOff, tmpV->name, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_745+currStrOff, "->data = memoryAlloc(sizeof(struct reflectElement) * ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_745+currStrOff, ____BAH_COMPILER_VAR_747, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_745+currStrOff, ");\n        ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_745+currStrOff, tmpV->name, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_745+currStrOff, "->length = ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_745+currStrOff, ____BAH_COMPILER_VAR_746, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_745+currStrOff, ";\n        ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_745+currStrOff, tmpV->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_745+currStrOff, "->elemSize = sizeof(struct reflectElement);\n        ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_745+currStrOff, decls, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_745+currStrOff, "\n        ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_745));
struct Tok ____BAH_COMPILER_VAR_748 = {};
____BAH_COMPILER_VAR_748.cont = "";
____BAH_COMPILER_VAR_748.ogCont = "";
____BAH_COMPILER_VAR_748.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_748.pos = 0;
____BAH_COMPILER_VAR_748.line = 1;
____BAH_COMPILER_VAR_748.begLine = 1;
____BAH_COMPILER_VAR_748.bahType = "";
____BAH_COMPILER_VAR_748.isValue = false;
____BAH_COMPILER_VAR_748.isFunc = false;
____BAH_COMPILER_VAR_748.isOper = false;
____BAH_COMPILER_VAR_748.isEqual = false;
____BAH_COMPILER_VAR_748.pass = false;
____BAH_COMPILER_VAR_748.bahRef= null;
____BAH_COMPILER_VAR_748.parent= null;
____BAH_COMPILER_VAR_748.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_748.cont = tmpV->name;
____BAH_COMPILER_VAR_748.line = fnt.line;
____BAH_COMPILER_VAR_748.isValue = true;

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
            memory->data[0] = ____BAH_COMPILER_VAR_748;
            memory->length = nLength+1;
        } else {
            memory->data[0] = ____BAH_COMPILER_VAR_748;
        }
    }
    ;
}
else if ((strcmp(fn->name, "breakPoint") == 0)) {
struct Tok ____BAH_COMPILER_VAR_749 = {};
____BAH_COMPILER_VAR_749.cont = "";
____BAH_COMPILER_VAR_749.ogCont = "";
____BAH_COMPILER_VAR_749.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_749.pos = 0;
____BAH_COMPILER_VAR_749.line = 1;
____BAH_COMPILER_VAR_749.begLine = 1;
____BAH_COMPILER_VAR_749.bahType = "";
____BAH_COMPILER_VAR_749.isValue = false;
____BAH_COMPILER_VAR_749.isFunc = false;
____BAH_COMPILER_VAR_749.isOper = false;
____BAH_COMPILER_VAR_749.isEqual = false;
____BAH_COMPILER_VAR_749.pass = false;
____BAH_COMPILER_VAR_749.bahRef= null;
____BAH_COMPILER_VAR_749.parent= null;
____BAH_COMPILER_VAR_749.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_749.cont = "__dumpSymbols";
____BAH_COMPILER_VAR_749.line = fnt.line;
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
____BAH_COMPILER_VAR_750.cont = "(";
____BAH_COMPILER_VAR_750.line = fnt.line;
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
____BAH_COMPILER_VAR_751.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_751.cont = ")";
____BAH_COMPILER_VAR_751.line = fnt.line;
memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 3;
memory->elemSize = sizeof(struct Tok);
memory->data = memoryAlloc(sizeof(struct Tok) * 50);
                    memory->realLength = 50;
memory->data[0] = ____BAH_COMPILER_VAR_749;
memory->data[1] = ____BAH_COMPILER_VAR_750;
memory->data[2] = ____BAH_COMPILER_VAR_751;
memory = prePross(memory,LINE_TYPE_FN_CALL,elems);
struct Tok ____BAH_COMPILER_VAR_752 = {};
____BAH_COMPILER_VAR_752.cont = "";
____BAH_COMPILER_VAR_752.ogCont = "";
____BAH_COMPILER_VAR_752.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_752.pos = 0;
____BAH_COMPILER_VAR_752.line = 1;
____BAH_COMPILER_VAR_752.begLine = 1;
____BAH_COMPILER_VAR_752.bahType = "";
____BAH_COMPILER_VAR_752.isValue = false;
____BAH_COMPILER_VAR_752.isFunc = false;
____BAH_COMPILER_VAR_752.isOper = false;
____BAH_COMPILER_VAR_752.isEqual = false;
____BAH_COMPILER_VAR_752.pass = false;
____BAH_COMPILER_VAR_752.bahRef= null;
____BAH_COMPILER_VAR_752.parent= null;
____BAH_COMPILER_VAR_752.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_752.cont = ",";
____BAH_COMPILER_VAR_752.line = fnt.line;

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
            memory->data[len(memory)] = ____BAH_COMPILER_VAR_752;
            memory->length = nLength+1;
        } else {
            memory->data[len(memory)] = ____BAH_COMPILER_VAR_752;
        }
    }
    ;
struct Tok ____BAH_COMPILER_VAR_753 = {};
____BAH_COMPILER_VAR_753.cont = "";
____BAH_COMPILER_VAR_753.ogCont = "";
____BAH_COMPILER_VAR_753.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_753.pos = 0;
____BAH_COMPILER_VAR_753.line = 1;
____BAH_COMPILER_VAR_753.begLine = 1;
____BAH_COMPILER_VAR_753.bahType = "";
____BAH_COMPILER_VAR_753.isValue = false;
____BAH_COMPILER_VAR_753.isFunc = false;
____BAH_COMPILER_VAR_753.isOper = false;
____BAH_COMPILER_VAR_753.isEqual = false;
____BAH_COMPILER_VAR_753.pass = false;
____BAH_COMPILER_VAR_753.bahRef= null;
____BAH_COMPILER_VAR_753.parent= null;
____BAH_COMPILER_VAR_753.type = TOKEN_TYPE_STR;
____BAH_COMPILER_VAR_753.cont = currLine;
____BAH_COMPILER_VAR_753.line = fnt.line;

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
            memory->data[len(memory)] = ____BAH_COMPILER_VAR_753;
            memory->length = nLength+1;
        } else {
            memory->data[len(memory)] = ____BAH_COMPILER_VAR_753;
        }
    }
    ;
fn = searchFunc("breakPoint__inner",elems,true);
char * ____BAH_COMPILER_VAR_754 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fn->name);
unsigned int strLen_1 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_754 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_754+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_754+currStrOff, "(", strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_754;
}
else if ((strcmp(fn->name, "sizeof") == 0)) {
char * tp = "";
register long int j = 0;
for (; (j<len(memory)); ++j) {
struct Tok tmpT = memory->data[j];
char * ____BAH_COMPILER_VAR_755 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tp);
unsigned int strLen_1 = strlen(tmpT.cont);
;                            
            ____BAH_COMPILER_VAR_755 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_755+currStrOff, tp, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_755+currStrOff, tmpT.cont, strLen_1);
            currStrOff += strLen_1;
        
        }tp = ____BAH_COMPILER_VAR_755;
};
struct string cType = getCType(tp,elems);
char * ____BAH_COMPILER_VAR_756 =null;char * ____BAH_COMPILER_VAR_757 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_757);
unsigned int strLen_1 = strlen(")");
;                            
            ____BAH_COMPILER_VAR_756 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_756+currStrOff, ____BAH_COMPILER_VAR_757, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_756+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_758 =null;char * ____BAH_COMPILER_VAR_759 =____BAH_COMPILER_VAR_756;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnt.cont);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_759);
;                            
            ____BAH_COMPILER_VAR_758 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_758+currStrOff, fnt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_758+currStrOff, ____BAH_COMPILER_VAR_759, strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_758;
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
char * ____BAH_COMPILER_VAR_760 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(amp);
unsigned int strLen_1 = strlen(parent->name);
;                            
            ____BAH_COMPILER_VAR_760 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_760+currStrOff, amp, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_760+currStrOff, parent->name, strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_761 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnt.cont);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_760);
;                            
            ____BAH_COMPILER_VAR_761 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_761+currStrOff, fnt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_761+currStrOff, ____BAH_COMPILER_VAR_760, strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_761;
++argIndex;
if ((len(fn->args)>argIndex)) {
char * ____BAH_COMPILER_VAR_762 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnt.cont);
unsigned int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_762 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_762+currStrOff, fnt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_762+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_762;
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
char * ____BAH_COMPILER_VAR_763 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(arg->type);
unsigned int strLen_1 = strlen(" in function call.");
unsigned int strLen_2 = strlen(") as ");
unsigned int strLen_3 = strlen(tt);
unsigned int strLen_4 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_763 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_763+currStrOff, "Cannot use {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_763+currStrOff, tt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_763+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_763+currStrOff, arg->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_763+currStrOff, " in function call.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&t,____BAH_COMPILER_VAR_763);
}
if ((RCPavailable()==true)&&(ltp==LINE_TYPE_VAR)&&(t.type==TOKEN_TYPE_VAR)&&(t.isOper==false)&&(currSetVar!=null)&&(strcmp(t.cont, currSetVar->name) == 0)&&isRCPtype(currSetVar->type,elems)) {
OUTPUT = rope__add(OUTPUT, incrVar(currSetVar,elems));
}
if ((t.type==TOKEN_TYPE_FUNC)) {
struct func* afn = searchFuncByToken(&t,elems);
if ((afn!=null)&&(isRCPtype(afn->returns->type,elems)==true)) {
t.cont = registerRCPvar(afn->returns->type,t.cont,elems);
}
}
char * ____BAH_COMPILER_VAR_764 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnt.cont);
unsigned int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_764 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_764+currStrOff, fnt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_764+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_764;
++argIndex;
if ((j+1<len(memory))) {
++j;
t = memory->data[j];
if ((strcmp(t.cont, ",") != 0)) {
throwErr(&t,"Need separator between arguments, not {TOKEN}.");
}
char * ____BAH_COMPILER_VAR_765 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnt.cont);
unsigned int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_765 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_765+currStrOff, fnt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_765+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_765;
}
};
if ((argIndex!=len(fn->args))) {
struct Tok lt = l->data[tokPos];
char * ____BAH_COMPILER_VAR_766 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fn->name);
unsigned int strLen_1 = strlen("'.");
unsigned int strLen_2 = strlen("Not enough argument {TOKEN}, calling '");
;                            
            ____BAH_COMPILER_VAR_766 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_766+currStrOff, "Not enough argument {TOKEN}, calling '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_766+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_766+currStrOff, "'.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&lt,____BAH_COMPILER_VAR_766);
}
fnt.bahRef = fn;
char * ____BAH_COMPILER_VAR_767 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnt.cont);
unsigned int strLen_1 = strlen(")");
;                            
            ____BAH_COMPILER_VAR_767 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_767+currStrOff, fnt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_767+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_767;

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
if ((t.type==TOKEN_TYPE_VAR)) {
parent = searchVar(t.cont,elems);
}
else {
char * tmpV = genCompilerVar();
struct string cType = getCType(tt,elems);
char * ____BAH_COMPILER_VAR_768 =null;char * ____BAH_COMPILER_VAR_769 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t.cont);
unsigned int strLen_1 = strlen(";\n                ");
unsigned int strLen_2 = strlen(" = ");
unsigned int strLen_3 = strlen(tmpV);
unsigned int strLen_4 = strlen(" ");
unsigned int strLen_5 = strlen(____BAH_COMPILER_VAR_769);
unsigned int strLen_6 = strlen("\n                ");
;                            
            ____BAH_COMPILER_VAR_768 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_768+currStrOff, "\n                ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_768+currStrOff, ____BAH_COMPILER_VAR_769, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_768+currStrOff, " ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_768+currStrOff, tmpV, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_768+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_768+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_768+currStrOff, ";\n                ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_768));
t.cont = tmpV;
struct variable* ____BAH_COMPILER_VAR_770 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_770->name = "";
____BAH_COMPILER_VAR_770->type = "";
____BAH_COMPILER_VAR_770->isConst = false;
____BAH_COMPILER_VAR_770->constVal = "";
____BAH_COMPILER_VAR_770->isArray = false;
____BAH_COMPILER_VAR_770->from = "";
____BAH_COMPILER_VAR_770->declScope= null;
____BAH_COMPILER_VAR_770->isGlobal = false;
____BAH_COMPILER_VAR_770->declRope= null;
____BAH_COMPILER_VAR_770->isReg = false;
____BAH_COMPILER_VAR_770->lastSet= null;
____BAH_COMPILER_VAR_770->isArg = false;
____BAH_COMPILER_VAR_770->name = tmpV;
____BAH_COMPILER_VAR_770->type = tt;
parent = ____BAH_COMPILER_VAR_770;
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
char * ____BAH_COMPILER_VAR_771 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s->name);
unsigned int strLen_1 = strlen(".");
unsigned int strLen_2 = strlen("Unknown method {TOKEN} in struct ");
;                            
            ____BAH_COMPILER_VAR_771 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_771+currStrOff, "Unknown method {TOKEN} in struct ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_771+currStrOff, s->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_771+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&nt,____BAH_COMPILER_VAR_771);
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
char * ____BAH_COMPILER_VAR_772 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(sep);
unsigned int strLen_1 = strlen(fn->name);
unsigned int strLen_2 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_772 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_772+currStrOff, t.cont, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_772+currStrOff, sep, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_772+currStrOff, fn->name, strLen_1);
            currStrOff += strLen_1;
        
        }fn->name = ____BAH_COMPILER_VAR_772;
}
valueFunc(fn,parent,l,i,ltp,elems);
struct Tok fnt = l->data[i];
delete(l,i);
char * ____BAH_COMPILER_VAR_773 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(".");
unsigned int strLen_1 = strlen(nt.ogCont);
unsigned int strLen_2 = strlen(t.ogCont);
;                            
            ____BAH_COMPILER_VAR_773 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_773+currStrOff, t.ogCont, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_773+currStrOff, ".", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_773+currStrOff, nt.ogCont, strLen_1);
            currStrOff += strLen_1;
        
        }fnt.ogCont = ____BAH_COMPILER_VAR_773;
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
char * ____BAH_COMPILER_VAR_774 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s->name);
unsigned int strLen_1 = strlen("'.");
unsigned int strLen_2 = strlen("Unknown struct member {TOKEN} in struct '");
;                            
            ____BAH_COMPILER_VAR_774 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_774+currStrOff, "Unknown struct member {TOKEN} in struct '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_774+currStrOff, s->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_774+currStrOff, "'.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&nt,____BAH_COMPILER_VAR_774);
}
if ((m->isFn==true)) {
char * ____BAH_COMPILER_VAR_775 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("__");
unsigned int strLen_1 = strlen(m->name);
unsigned int strLen_2 = strlen(s->name);
;                            
            ____BAH_COMPILER_VAR_775 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_775+currStrOff, s->name, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_775+currStrOff, "__", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_775+currStrOff, m->name, strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_775;
}
else {
if ((t.type==TOKEN_TYPE_VAR)) {
t.parent = searchVarByToken(&t,elems);
}
char * ____BAH_COMPILER_VAR_776 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(sep);
unsigned int strLen_1 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_776 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_776+currStrOff, sep, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_776+currStrOff, nt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_777 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t.cont);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_776);
;                            
            ____BAH_COMPILER_VAR_777 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_777+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_777+currStrOff, ____BAH_COMPILER_VAR_776, strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_777;
}
char * ____BAH_COMPILER_VAR_778 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(".");
unsigned int strLen_1 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_778 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_778+currStrOff, ".", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_778+currStrOff, nt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_779 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t.ogCont);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_778);
;                            
            ____BAH_COMPILER_VAR_779 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_779+currStrOff, t.ogCont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_779+currStrOff, ____BAH_COMPILER_VAR_778, strLen_1);
            currStrOff += strLen_1;
        
        }t.ogCont = ____BAH_COMPILER_VAR_779;
t.bahType = m->type;
struct variable* ____BAH_COMPILER_VAR_780 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_780->name = "";
____BAH_COMPILER_VAR_780->type = "";
____BAH_COMPILER_VAR_780->isConst = false;
____BAH_COMPILER_VAR_780->constVal = "";
____BAH_COMPILER_VAR_780->isArray = false;
____BAH_COMPILER_VAR_780->from = "";
____BAH_COMPILER_VAR_780->declScope= null;
____BAH_COMPILER_VAR_780->isGlobal = false;
____BAH_COMPILER_VAR_780->declRope= null;
____BAH_COMPILER_VAR_780->isReg = false;
____BAH_COMPILER_VAR_780->lastSet= null;
____BAH_COMPILER_VAR_780->isArg = false;
____BAH_COMPILER_VAR_780->name = t.cont;
____BAH_COMPILER_VAR_780->type = t.bahType;
t.bahRef = ____BAH_COMPILER_VAR_780;

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
char * ____BAH_COMPILER_VAR_781 =getTypeFromToken(&pt,true,elems);struct string ptt = string(____BAH_COMPILER_VAR_781);
struct Tok t = pt;
t.isValue = true;
char * ____BAH_COMPILER_VAR_782 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t.ogCont);
unsigned int strLen_1 = strlen("[");
;                            
            ____BAH_COMPILER_VAR_782 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_782+currStrOff, t.ogCont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_782+currStrOff, "[", strLen_1);
            currStrOff += strLen_1;
        
        }t.ogCont = ____BAH_COMPILER_VAR_782;
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
char * ____BAH_COMPILER_VAR_783 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t.ogCont);
unsigned int strLen_1 = strlen("]");
;                            
            ____BAH_COMPILER_VAR_783 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_783+currStrOff, t.ogCont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_783+currStrOff, "]", strLen_1);
            currStrOff += strLen_1;
        
        }t.ogCont = ____BAH_COMPILER_VAR_783;
if ((nbEncls==0)) {
break;
}
}
char * ____BAH_COMPILER_VAR_784 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t.ogCont);
unsigned int strLen_1 = strlen(tmpT.ogCont);
;                            
            ____BAH_COMPILER_VAR_784 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_784+currStrOff, t.ogCont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_784+currStrOff, tmpT.ogCont, strLen_1);
            currStrOff += strLen_1;
        
        }t.ogCont = ____BAH_COMPILER_VAR_784;

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
char * ____BAH_COMPILER_VAR_785 =getTypeFromToken(&index,true,elems);if ((compTypes(____BAH_COMPILER_VAR_785,"int")==false)) {
throwErr(&index,"Cannot use {TOKEN} as array index (int).");
}
char * ____BAH_COMPILER_VAR_786 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(index.cont);
unsigned int strLen_1 = strlen("]");
unsigned int strLen_2 = strlen("->data[");
unsigned int strLen_3 = strlen(pt.cont);
;                            
            ____BAH_COMPILER_VAR_786 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_786+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_786+currStrOff, "->data[", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_786+currStrOff, index.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_786+currStrOff, "]", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_786;
string__trimLeft(&ptt,2);
t.bahType = string__str(&ptt);
}
else {
t.bahType = string__str(&ptt);
if ((strcmp(to, "") == 0)) {
char * ____BAH_COMPILER_VAR_787 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(pt.cont);
unsigned int strLen_1 = strlen("->length");
;                            
            ____BAH_COMPILER_VAR_787 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_787+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_787+currStrOff, "->length", strLen_1);
            currStrOff += strLen_1;
        
        }to = ____BAH_COMPILER_VAR_787;
}
char * ____BAH_COMPILER_VAR_788 =null;
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
            ____BAH_COMPILER_VAR_788 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_788+currStrOff, "arraySubstitute(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_788+currStrOff, pt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_788+currStrOff, ", ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_788+currStrOff, from, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_788+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_788+currStrOff, to, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_788+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_788;
}
}
else if (string__hasPrefix(&ptt,"buffer:")) {
if ((split==false)) {
t.bahType = "char";
struct Tok index = memory->data[0];
char * ____BAH_COMPILER_VAR_789 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(index.cont);
unsigned int strLen_1 = strlen("]");
unsigned int strLen_2 = strlen("[");
unsigned int strLen_3 = strlen(pt.cont);
;                            
            ____BAH_COMPILER_VAR_789 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_789+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_789+currStrOff, "[", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_789+currStrOff, index.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_789+currStrOff, "]", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_789;
}
else {
t.bahType = "cpstring";
if ((strcmp(to, "") == 0)) {
char * ____BAH_COMPILER_VAR_790 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(pt.cont);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen("strlen(");
;                            
            ____BAH_COMPILER_VAR_790 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_790+currStrOff, "strlen(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_790+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_790+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }to = ____BAH_COMPILER_VAR_790;
}
char * ____BAH_COMPILER_VAR_791 =null;
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
            ____BAH_COMPILER_VAR_791 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_791+currStrOff, "cpstringSubsitute(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_791+currStrOff, pt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_791+currStrOff, ", ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_791+currStrOff, from, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_791+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_791+currStrOff, to, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_791+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_791;
}
}
else if (string__hasPrefix(&ptt,"map:")) {
if ((split==true)) {
throwErr(&pt,"Cannot do substitution on a map {TOKEN}.");
}
string__trimLeft(&ptt,4);
char * ____BAH_COMPILER_VAR_792 =string__str(&ptt);struct string elemType = getCType(____BAH_COMPILER_VAR_792,elems);
struct Tok index = memory->data[0];
if ((tokPos==0)&&(ltp==LINE_TYPE_VAR)) {
struct variable* ____BAH_COMPILER_VAR_793 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_793->name = "";
____BAH_COMPILER_VAR_793->type = "";
____BAH_COMPILER_VAR_793->isConst = false;
____BAH_COMPILER_VAR_793->constVal = "";
____BAH_COMPILER_VAR_793->isArray = false;
____BAH_COMPILER_VAR_793->from = "";
____BAH_COMPILER_VAR_793->declScope= null;
____BAH_COMPILER_VAR_793->isGlobal = false;
____BAH_COMPILER_VAR_793->declRope= null;
____BAH_COMPILER_VAR_793->isReg = false;
____BAH_COMPILER_VAR_793->lastSet= null;
____BAH_COMPILER_VAR_793->isArg = false;
____BAH_COMPILER_VAR_793->name = genCompilerVar();
____BAH_COMPILER_VAR_793->type = string__str(&ptt);
struct variable* tmpV = ____BAH_COMPILER_VAR_793;

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
char * ____BAH_COMPILER_VAR_794 =null;char * ____BAH_COMPILER_VAR_795 =string__str(&elemType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpV->name);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen(" ");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_795);
;                            
            ____BAH_COMPILER_VAR_794 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_794+currStrOff, ____BAH_COMPILER_VAR_795, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_794+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_794+currStrOff, tmpV->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_794+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_794));
}
else {
char * ____BAH_COMPILER_VAR_796 =null;char * ____BAH_COMPILER_VAR_797 =string__str(&elemType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpV->name);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen(" ");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_797);
;                            
            ____BAH_COMPILER_VAR_796 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_796+currStrOff, ____BAH_COMPILER_VAR_797, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_796+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_796+currStrOff, tmpV->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_796+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_796));
}
char * ____BAH_COMPILER_VAR_798 =string__str(&ptt);if (isRCPpointerType(____BAH_COMPILER_VAR_798)) {
char * ____BAH_COMPILER_VAR_799 =null;
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
            ____BAH_COMPILER_VAR_799 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_799+currStrOff, "mapWrapper__set(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_799+currStrOff, pt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_799+currStrOff, ", ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_799+currStrOff, index.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_799+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_799+currStrOff, tmpV->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_799+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }NEXT_LINE = ____BAH_COMPILER_VAR_799;
}
else {
char * ____BAH_COMPILER_VAR_800 =null;char * ____BAH_COMPILER_VAR_801 =string__str(&elemType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_801);
unsigned int strLen_1 = strlen("));\n");
unsigned int strLen_2 = strlen(", sizeof(");
unsigned int strLen_3 = strlen(tmpV->name);
unsigned int strLen_4 = strlen(", &");
unsigned int strLen_5 = strlen(index.cont);
unsigned int strLen_6 = strlen(", ");
unsigned int strLen_7 = strlen(pt.cont);
unsigned int strLen_8 = strlen("mapWrapper__setAny(");
;                            
            ____BAH_COMPILER_VAR_800 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_800+currStrOff, "mapWrapper__setAny(", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_800+currStrOff, pt.cont, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_800+currStrOff, ", ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_800+currStrOff, index.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_800+currStrOff, ", &", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_800+currStrOff, tmpV->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_800+currStrOff, ", sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_800+currStrOff, ____BAH_COMPILER_VAR_801, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_800+currStrOff, "));\n", strLen_1);
            currStrOff += strLen_1;
        
        }NEXT_LINE = ____BAH_COMPILER_VAR_800;
}
t.cont = tmpV->name;
t.bahType = string__str(&ptt);
}
else {
t.isFunc = true;
char * ____BAH_COMPILER_VAR_802 =string__str(&ptt);if (isRCPpointerType(____BAH_COMPILER_VAR_802)) {
char * ____BAH_COMPILER_VAR_803 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(index.cont);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen(", ");
unsigned int strLen_3 = strlen(t.cont);
unsigned int strLen_4 = strlen("mapWrapper__get(");
;                            
            ____BAH_COMPILER_VAR_803 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_803+currStrOff, "mapWrapper__get(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_803+currStrOff, t.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_803+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_803+currStrOff, index.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_803+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_803;
}
else {
char * tmpV = genCompilerVar();
char * ____BAH_COMPILER_VAR_804 =null;char * ____BAH_COMPILER_VAR_805 =string__str(&elemType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(index.cont);
unsigned int strLen_1 = strlen(");\n");
unsigned int strLen_2 = strlen(", ");
unsigned int strLen_3 = strlen(pt.cont);
unsigned int strLen_4 = strlen("=mapWrapper__get(");
unsigned int strLen_5 = strlen(tmpV);
unsigned int strLen_6 = strlen("* ");
unsigned int strLen_7 = strlen(____BAH_COMPILER_VAR_805);
;                            
            ____BAH_COMPILER_VAR_804 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7);
            
                    memcpy(____BAH_COMPILER_VAR_804+currStrOff, ____BAH_COMPILER_VAR_805, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_804+currStrOff, "* ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_804+currStrOff, tmpV, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_804+currStrOff, "=mapWrapper__get(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_804+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_804+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_804+currStrOff, index.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_804+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }struct rope* res = rope(____BAH_COMPILER_VAR_804);
char * ____BAH_COMPILER_VAR_806 =null;char * ____BAH_COMPILER_VAR_807 =string__str(&elemType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpV);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen(")(*");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_807);
unsigned int strLen_4 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_806 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_806+currStrOff, "(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_806+currStrOff, ____BAH_COMPILER_VAR_807, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_806+currStrOff, ")(*", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_806+currStrOff, tmpV, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_806+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_806;
if (isGlobal()) {
INIT = rope__add(INIT, res);
}
else {
OUTPUT = rope__add(OUTPUT, res);
}
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
char * ____BAH_COMPILER_VAR_808 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(index.cont);
unsigned int strLen_1 = strlen("]");
unsigned int strLen_2 = strlen("[");
unsigned int strLen_3 = strlen(pt.cont);
;                            
            ____BAH_COMPILER_VAR_808 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_808+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_808+currStrOff, "[", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_808+currStrOff, index.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_808+currStrOff, "]", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_808;
}
else {
if ((strcmp(to, "") == 0)) {
char * ____BAH_COMPILER_VAR_809 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(pt.cont);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen("strlen(");
;                            
            ____BAH_COMPILER_VAR_809 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_809+currStrOff, "strlen(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_809+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_809+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }to = ____BAH_COMPILER_VAR_809;
}
char * ____BAH_COMPILER_VAR_810 =null;
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
            ____BAH_COMPILER_VAR_810 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_810+currStrOff, "cpstringSubsitute(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_810+currStrOff, pt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_810+currStrOff, ", ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_810+currStrOff, from, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_810+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_810+currStrOff, to, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_810+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_810;
}
}
else {
char * ____BAH_COMPILER_VAR_811 =null;char * ____BAH_COMPILER_VAR_812 =string__str(&ptt);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_812);
unsigned int strLen_1 = strlen(") as array.");
unsigned int strLen_2 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_811 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_811+currStrOff, "Cannot use {TOKEN} (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_811+currStrOff, ____BAH_COMPILER_VAR_812, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_811+currStrOff, ") as array.", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_813 =____BAH_COMPILER_VAR_811;throwErr(&pt,____BAH_COMPILER_VAR_813);
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
char * ____BAH_COMPILER_VAR_814 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("register ");
unsigned int strLen_1 = strlen(odecl);
;                            
            ____BAH_COMPILER_VAR_814 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_814+currStrOff, "register ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_814+currStrOff, odecl, strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT->totalLen = OUTPUT->totalLen+ropeSet(v->declRope,____BAH_COMPILER_VAR_814);
}
v->isReg = true;
}
}
struct Tok nt = l->data[tokPos];
char * ntt = getTypeFromToken(&nt,true,elems);
if ((strcmp(t.cont, "in") == 0)) {
struct string arrT = string(ntt);
if ((string__hasPrefix(&arrT,"[]")==0)) {
char * ____BAH_COMPILER_VAR_815 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ntt);
unsigned int strLen_1 = strlen(") as array.");
unsigned int strLen_2 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_815 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_815+currStrOff, "Cannot use {TOKEN} (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_815+currStrOff, ntt, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_815+currStrOff, ") as array.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&nt,____BAH_COMPILER_VAR_815);
}
string__trimLeft(&arrT,2);
char * ____BAH_COMPILER_VAR_816 =string__str(&arrT);if ((compTypes(ptt,____BAH_COMPILER_VAR_816)==false)) {
char * ____BAH_COMPILER_VAR_817 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ntt);
unsigned int strLen_1 = strlen(".");
unsigned int strLen_2 = strlen(") in ");
unsigned int strLen_3 = strlen(ptt);
unsigned int strLen_4 = strlen("Cannot search for {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_817 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_817+currStrOff, "Cannot search for {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_817+currStrOff, ptt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_817+currStrOff, ") in ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_817+currStrOff, ntt, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_817+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&pt,____BAH_COMPILER_VAR_817);
}
char * compVar = genCompilerVar();
char * comp = "";
if ((strcmp(ptt, "cpstring") == 0)) {
char * ____BAH_COMPILER_VAR_818 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(pt.cont);
unsigned int strLen_1 = strlen(") == 0");
unsigned int strLen_2 = strlen("->data[i], ");
unsigned int strLen_3 = strlen(nt.cont);
unsigned int strLen_4 = strlen("->data[i] != 0 && strcmp(");
unsigned int strLen_5 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_818 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_818+currStrOff, nt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_818+currStrOff, "->data[i] != 0 && strcmp(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_818+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_818+currStrOff, "->data[i], ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_818+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_818+currStrOff, ") == 0", strLen_1);
            currStrOff += strLen_1;
        
        }comp = ____BAH_COMPILER_VAR_818;
}
else {
char * ____BAH_COMPILER_VAR_819 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("->data[i] == ");
unsigned int strLen_1 = strlen(pt.cont);
unsigned int strLen_2 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_819 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_819+currStrOff, nt.cont, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_819+currStrOff, "->data[i] == ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_819+currStrOff, pt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }comp = ____BAH_COMPILER_VAR_819;
}
char * ____BAH_COMPILER_VAR_820 =null;
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
            ____BAH_COMPILER_VAR_820 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_820+currStrOff, "\n        char ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_820+currStrOff, compVar, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_820+currStrOff, " = 0;\n        for(int i=", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_820+currStrOff, nt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_820+currStrOff, "->length-1; i!=-1;i--) {\n            if (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_820+currStrOff, comp, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_820+currStrOff, ") {\n                ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_820+currStrOff, compVar, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_820+currStrOff, "=1;\n                break;\n            };\n        }\n        ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_820));
pt.cont = compVar;
}
else {
if ((compTypes(ptt,ntt)==false)) {
char * ____BAH_COMPILER_VAR_821 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ptt);
unsigned int strLen_1 = strlen(".");
unsigned int strLen_2 = strlen(") with type ");
unsigned int strLen_3 = strlen(ntt);
unsigned int strLen_4 = strlen("Cannot compare {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_821 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_821+currStrOff, "Cannot compare {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_821+currStrOff, ntt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_821+currStrOff, ") with type ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_821+currStrOff, ptt, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_821+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&nt,____BAH_COMPILER_VAR_821);
}
if ((strcmp(ptt, "cpstring") == 0)) {
if ((strcmp(t.cont, "==") == 0)) {
char * ____BAH_COMPILER_VAR_822 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen(") == 0)");
unsigned int strLen_2 = strlen(", ");
unsigned int strLen_3 = strlen(pt.cont);
unsigned int strLen_4 = strlen("(strcmp(");
;                            
            ____BAH_COMPILER_VAR_822 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_822+currStrOff, "(strcmp(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_822+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_822+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_822+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_822+currStrOff, ") == 0)", strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_822;
}
else if ((strcmp(t.cont, "!=") == 0)) {
char * ____BAH_COMPILER_VAR_823 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen(") != 0)");
unsigned int strLen_2 = strlen(", ");
unsigned int strLen_3 = strlen(pt.cont);
unsigned int strLen_4 = strlen("(strcmp(");
;                            
            ____BAH_COMPILER_VAR_823 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_823+currStrOff, "(strcmp(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_823+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_823+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_823+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_823+currStrOff, ") != 0)", strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_823;
}
else if ((strcmp(t.cont, ">") == 0)) {
char * ____BAH_COMPILER_VAR_824 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen("))");
unsigned int strLen_2 = strlen(") > srtlen(");
unsigned int strLen_3 = strlen(pt.cont);
unsigned int strLen_4 = strlen("(strlen(");
;                            
            ____BAH_COMPILER_VAR_824 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_824+currStrOff, "(strlen(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_824+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_824+currStrOff, ") > srtlen(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_824+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_824+currStrOff, "))", strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_824;
}
else if ((strcmp(t.cont, "<") == 0)) {
char * ____BAH_COMPILER_VAR_825 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen("))");
unsigned int strLen_2 = strlen(") < srtlen(");
unsigned int strLen_3 = strlen(pt.cont);
unsigned int strLen_4 = strlen("(strlen(");
;                            
            ____BAH_COMPILER_VAR_825 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_825+currStrOff, "(strlen(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_825+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_825+currStrOff, ") < srtlen(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_825+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_825+currStrOff, "))", strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_825;
}
else if ((strcmp(t.cont, ">=") == 0)) {
char * ____BAH_COMPILER_VAR_826 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen("))");
unsigned int strLen_2 = strlen(") >= srtlen(");
unsigned int strLen_3 = strlen(pt.cont);
unsigned int strLen_4 = strlen("(strlen(");
;                            
            ____BAH_COMPILER_VAR_826 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_826+currStrOff, "(strlen(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_826+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_826+currStrOff, ") >= srtlen(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_826+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_826+currStrOff, "))", strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_826;
}
else if ((strcmp(t.cont, "<=") == 0)) {
char * ____BAH_COMPILER_VAR_827 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen("))");
unsigned int strLen_2 = strlen(") <= srtlen(");
unsigned int strLen_3 = strlen(pt.cont);
unsigned int strLen_4 = strlen("(strlen(");
;                            
            ____BAH_COMPILER_VAR_827 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_827+currStrOff, "(strlen(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_827+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_827+currStrOff, ") <= srtlen(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_827+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_827+currStrOff, "))", strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_827;
}
}
else {
char * ____BAH_COMPILER_VAR_828 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen(t.cont);
unsigned int strLen_3 = strlen(pt.cont);
unsigned int strLen_4 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_828 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_828+currStrOff, "(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_828+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_828+currStrOff, t.cont, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_828+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_828+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_828;
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
char * ____BAH_COMPILER_VAR_829 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t.cont);
unsigned int strLen_1 = strlen(pt.cont);
unsigned int strLen_2 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_829 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_829+currStrOff, t.cont, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_829+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_829+currStrOff, pt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_829;

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
char * ____BAH_COMPILER_VAR_830 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ptt);
unsigned int strLen_1 = strlen(".");
unsigned int strLen_2 = strlen(") as ");
unsigned int strLen_3 = strlen(ntt);
unsigned int strLen_4 = strlen("Cannot compare {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_830 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_830+currStrOff, "Cannot compare {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_830+currStrOff, ntt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_830+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_830+currStrOff, ptt, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_830+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&nt,____BAH_COMPILER_VAR_830);
}
if ((strcmp(ptt, "cpstring") == 0)) {
char * lens = "";
char * totStrLen = "1+strLen_0+strLen_1";
struct rope* cats = rope("");
char * rstr = registerRCPvar("cpstring","null",elems);
if ((pt.isFunc==true)) {
pt.cont = registerRCPvar("cpstring",pt.cont,elems);
}
char * ____BAH_COMPILER_VAR_831 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(pt.cont);
unsigned int strLen_1 = strlen(");\n");
unsigned int strLen_2 = strlen("unsigned int strLen_0 = strlen(");
;                            
            ____BAH_COMPILER_VAR_831 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_831+currStrOff, "unsigned int strLen_0 = strlen(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_831+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_831+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_832 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(lens);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_831);
;                            
            ____BAH_COMPILER_VAR_832 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_832+currStrOff, lens, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_832+currStrOff, ____BAH_COMPILER_VAR_831, strLen_1);
            currStrOff += strLen_1;
        
        }lens = ____BAH_COMPILER_VAR_832;
char * ____BAH_COMPILER_VAR_833 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(pt.cont);
unsigned int strLen_1 = strlen(", strLen_0);\n            currStrOff += strLen_0;\n        ");
unsigned int strLen_2 = strlen("+currStrOff, ");
unsigned int strLen_3 = strlen(rstr);
unsigned int strLen_4 = strlen("\n            memcpy(");
;                            
            ____BAH_COMPILER_VAR_833 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_833+currStrOff, "\n            memcpy(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_833+currStrOff, rstr, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_833+currStrOff, "+currStrOff, ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_833+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_833+currStrOff, ", strLen_0);\n            currStrOff += strLen_0;\n        ", strLen_1);
            currStrOff += strLen_1;
        
        }cats = rope__add(cats, rope(____BAH_COMPILER_VAR_833));
if ((nt.isFunc==true)) {
nt.cont = registerRCPvar("cpstring",nt.cont,elems);
}
char * ____BAH_COMPILER_VAR_834 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen(");\n");
unsigned int strLen_2 = strlen("unsigned int strLen_1 = strlen(");
;                            
            ____BAH_COMPILER_VAR_834 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_834+currStrOff, "unsigned int strLen_1 = strlen(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_834+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_834+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_835 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(lens);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_834);
;                            
            ____BAH_COMPILER_VAR_835 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_835+currStrOff, lens, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_835+currStrOff, ____BAH_COMPILER_VAR_834, strLen_1);
            currStrOff += strLen_1;
        
        }lens = ____BAH_COMPILER_VAR_835;
char * ____BAH_COMPILER_VAR_836 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen(", strLen_1);\n            currStrOff += strLen_1;\n        ");
unsigned int strLen_2 = strlen("+currStrOff, ");
unsigned int strLen_3 = strlen(rstr);
unsigned int strLen_4 = strlen("\n            memcpy(");
;                            
            ____BAH_COMPILER_VAR_836 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_836+currStrOff, "\n            memcpy(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_836+currStrOff, rstr, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_836+currStrOff, "+currStrOff, ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_836+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_836+currStrOff, ", strLen_1);\n            currStrOff += strLen_1;\n        ", strLen_1);
            currStrOff += strLen_1;
        
        }cats = rope__add(cats, rope(____BAH_COMPILER_VAR_836));
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
char * ____BAH_COMPILER_VAR_837 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tt);
unsigned int strLen_1 = strlen(").");
unsigned int strLen_2 = strlen("Cannot concatenate cpstring with {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_837 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_837+currStrOff, "Cannot concatenate cpstring with {TOKEN} (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_837+currStrOff, tt, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_837+currStrOff, ").", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&currStrTk,____BAH_COMPILER_VAR_837);
}
if ((currStrTk.isFunc==true)) {
currStrTk.cont = registerRCPvar("cpstring",currStrTk.cont,elems);
}
char * is = intToStr(nb);
++nb;
char * ____BAH_COMPILER_VAR_838 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(currStrTk.cont);
unsigned int strLen_1 = strlen(");\n");
unsigned int strLen_2 = strlen(" = strlen(");
unsigned int strLen_3 = strlen(is);
unsigned int strLen_4 = strlen("unsigned int strLen_");
;                            
            ____BAH_COMPILER_VAR_838 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_838+currStrOff, "unsigned int strLen_", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_838+currStrOff, is, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_838+currStrOff, " = strlen(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_838+currStrOff, currStrTk.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_838+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_839 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(lens);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_838);
;                            
            ____BAH_COMPILER_VAR_839 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_839+currStrOff, lens, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_839+currStrOff, ____BAH_COMPILER_VAR_838, strLen_1);
            currStrOff += strLen_1;
        
        }lens = ____BAH_COMPILER_VAR_839;
char * ____BAH_COMPILER_VAR_840 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("+strLen_");
unsigned int strLen_1 = strlen(is);
;                            
            ____BAH_COMPILER_VAR_840 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_840+currStrOff, "+strLen_", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_840+currStrOff, is, strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_841 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(totStrLen);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_840);
;                            
            ____BAH_COMPILER_VAR_841 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_841+currStrOff, totStrLen, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_841+currStrOff, ____BAH_COMPILER_VAR_840, strLen_1);
            currStrOff += strLen_1;
        
        }totStrLen = ____BAH_COMPILER_VAR_841;
char * ____BAH_COMPILER_VAR_842 =null;
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
            ____BAH_COMPILER_VAR_842 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_842+currStrOff, "\n                    memcpy(", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_842+currStrOff, rstr, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_842+currStrOff, "+currStrOff, ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_842+currStrOff, currStrTk.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_842+currStrOff, ", strLen_", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_842+currStrOff, is, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_842+currStrOff, ");\n                    currStrOff += strLen_", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_842+currStrOff, is, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_842+currStrOff, ";\n                    ", strLen_1);
            currStrOff += strLen_1;
        
        }cats = rope__add(rope(____BAH_COMPILER_VAR_842), cats);
if ((i-1>=0)) {
--i;
t = l->data[i];
if ((strcmp(t.cont, "+") != 0)) {

        char ____BAH_COMPILER_VAR_843 = 0;
        for(int i=signs->length-1; i!=-1;i--) {
            if (signs->data[i] != 0 && strcmp(signs->data[i], t.cont) == 0) {
                ____BAH_COMPILER_VAR_843=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_843) {
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
char * ____BAH_COMPILER_VAR_844 =null;
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
            ____BAH_COMPILER_VAR_844 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_844+currStrOff, "\n        {\n            unsigned int currStrOff = 0;\n            ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_844+currStrOff, lens, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_844+currStrOff, ";                            \n            ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_844+currStrOff, rstr, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_844+currStrOff, " = memoryAllocSTR(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_844+currStrOff, totStrLen, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_844+currStrOff, ");\n            ", strLen_1);
            currStrOff += strLen_1;
        
        }struct rope* res = rope__add(rope(____BAH_COMPILER_VAR_844), rope__add(cats, rope("\n        }")));
if (isGlobal()) {
INIT = rope__add(INIT, res);
}
else {
OUTPUT = rope__add(OUTPUT, res);
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
char * ____BAH_COMPILER_VAR_845 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ptt);
unsigned int strLen_1 = strlen(").");
unsigned int strLen_2 = strlen("Undefined operation on struct {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_845 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_845+currStrOff, "Undefined operation on struct {TOKEN} (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_845+currStrOff, ptt, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_845+currStrOff, ").", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&pt,____BAH_COMPILER_VAR_845);
}
struct structMemb* methd = searchStructMemb(mName,s,elems);
if ((methd!=null)&&(methd->isFn==true)) {
char * ____BAH_COMPILER_VAR_846 =null;
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
            ____BAH_COMPILER_VAR_846 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_846+currStrOff, s->name, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_846+currStrOff, "__", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_846+currStrOff, mName, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_846+currStrOff, "(", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_846+currStrOff, amp, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_846+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_846+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_846+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_846+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_846;
pt.isFunc = true;
}
}
else {
char * ____BAH_COMPILER_VAR_847 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t.cont);
unsigned int strLen_1 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_847 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_847+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_847+currStrOff, nt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_848 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(pt.cont);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_847);
;                            
            ____BAH_COMPILER_VAR_848 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_848+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_848+currStrOff, ____BAH_COMPILER_VAR_847, strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_848;
}
}
pt.isOper = true;

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
char * ____BAH_COMPILER_VAR_849 =getTypeFromToken(&pt,true,elems);struct string ptt = string(____BAH_COMPILER_VAR_849);
if ((string__hasPrefix(&ptt,"chan:")==0)) {
char * ____BAH_COMPILER_VAR_850 =null;char * ____BAH_COMPILER_VAR_851 =string__str(&ptt);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_851);
unsigned int strLen_1 = strlen(") as chan.");
unsigned int strLen_2 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_850 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_850+currStrOff, "Cannot use {TOKEN} (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_850+currStrOff, ____BAH_COMPILER_VAR_851, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_850+currStrOff, ") as chan.", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_852 =____BAH_COMPILER_VAR_850;throwErr(&pt,____BAH_COMPILER_VAR_852);
}
string__trimLeft(&ptt,5);
if (isGlobal()) {
throwErr(&pt,"Cannot send to channel {TOKEN} of a function.");
}
char * ____BAH_COMPILER_VAR_853 =string__str(&ptt);if ((compTypes(ntt,____BAH_COMPILER_VAR_853)==false)) {
char * ____BAH_COMPILER_VAR_854 =null;char * ____BAH_COMPILER_VAR_855 =string__str(&ptt);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_855);
unsigned int strLen_1 = strlen(".");
unsigned int strLen_2 = strlen(") through chan:");
unsigned int strLen_3 = strlen(ntt);
unsigned int strLen_4 = strlen("Cannot send {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_854 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_854+currStrOff, "Cannot send {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_854+currStrOff, ntt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_854+currStrOff, ") through chan:", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_854+currStrOff, ____BAH_COMPILER_VAR_855, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_854+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_856 =____BAH_COMPILER_VAR_854;throwErr(&nt,____BAH_COMPILER_VAR_856);
}
char * ____BAH_COMPILER_VAR_857 =string__str(&ptt);if (isRCPpointerType(____BAH_COMPILER_VAR_857)) {
char * ____BAH_COMPILER_VAR_858 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen(");\n");
unsigned int strLen_2 = strlen(", ");
unsigned int strLen_3 = strlen(pt.cont);
unsigned int strLen_4 = strlen("channel__send(");
;                            
            ____BAH_COMPILER_VAR_858 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_858+currStrOff, "channel__send(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_858+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_858+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_858+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_858+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_858));
}
else {
struct string ct = getCType(ntt,elems);
char * tmpV = genCompilerVar();
char * ____BAH_COMPILER_VAR_859 =null;char * ____BAH_COMPILER_VAR_860 =string__str(&ct);
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
unsigned int strLen_11 = strlen(____BAH_COMPILER_VAR_860);
unsigned int strLen_12 = strlen("\n        ");
;                            
            ____BAH_COMPILER_VAR_859 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12);
            
                    memcpy(____BAH_COMPILER_VAR_859+currStrOff, "\n        ", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_859+currStrOff, ____BAH_COMPILER_VAR_860, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_859+currStrOff, " ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_859+currStrOff, tmpV, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_859+currStrOff, " = ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_859+currStrOff, nt.cont, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_859+currStrOff, ";\n        channel__sendAny(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_859+currStrOff, pt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_859+currStrOff, ", &", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_859+currStrOff, tmpV, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_859+currStrOff, ", sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_859+currStrOff, tmpV, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_859+currStrOff, "));\n        ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_859));
}
return posTok;
};
long int valueChan(__BAH_ARR_TYPE_Tok l,long int i,struct Elems* elems){
long int posTok = i-1;
delete(l,posTok);
struct Tok nt = l->data[posTok];
char * ____BAH_COMPILER_VAR_861 =getTypeFromToken(&nt,true,elems);struct string ntt = string(____BAH_COMPILER_VAR_861);
if ((string__hasPrefix(&ntt,"chan:")==0)) {
char * ____BAH_COMPILER_VAR_862 =null;char * ____BAH_COMPILER_VAR_863 =string__str(&ntt);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_863);
unsigned int strLen_1 = strlen(") as chan.");
unsigned int strLen_2 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_862 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_862+currStrOff, "Cannot use {TOKEN} (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_862+currStrOff, ____BAH_COMPILER_VAR_863, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_862+currStrOff, ") as chan.", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_864 =____BAH_COMPILER_VAR_862;throwErr(&nt,____BAH_COMPILER_VAR_864);
}
string__trimLeft(&ntt,5);
if (isGlobal()) {
throwErr(&nt,"Cannot receive from chan {TOKEN} outside a function body.");
}
char * tmpV = "";
char * ____BAH_COMPILER_VAR_865 =string__str(&ntt);struct string ct = getCType(____BAH_COMPILER_VAR_865,elems);
char * ____BAH_COMPILER_VAR_866 =string__str(&ntt);if (isRCPpointerType(____BAH_COMPILER_VAR_866)) {
char * ____BAH_COMPILER_VAR_867 =null;char * ____BAH_COMPILER_VAR_868 =string__str(&ct);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen(")channel__receive(");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_868);
unsigned int strLen_4 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_867 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_867+currStrOff, "(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_867+currStrOff, ____BAH_COMPILER_VAR_868, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_867+currStrOff, ")channel__receive(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_867+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_867+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }nt.cont = ____BAH_COMPILER_VAR_867;
}
else {
if (RCPavailable()) {
char * ____BAH_COMPILER_VAR_869 =null;char * ____BAH_COMPILER_VAR_870 =string__str(&ntt);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_870);
unsigned int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_869 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_869+currStrOff, ____BAH_COMPILER_VAR_870, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_869+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_871 =null;char * ____BAH_COMPILER_VAR_872 =string__str(&ct);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen("*)channel__receive(");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_872);
unsigned int strLen_4 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_871 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_871+currStrOff, "(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_871+currStrOff, ____BAH_COMPILER_VAR_872, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_871+currStrOff, "*)channel__receive(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_871+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_871+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_873 =____BAH_COMPILER_VAR_869;tmpV = registerRCPvar(____BAH_COMPILER_VAR_873,____BAH_COMPILER_VAR_871,elems);
char * ____BAH_COMPILER_VAR_874 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("*");
unsigned int strLen_1 = strlen(tmpV);
;                            
            ____BAH_COMPILER_VAR_874 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_874+currStrOff, "*", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_874+currStrOff, tmpV, strLen_1);
            currStrOff += strLen_1;
        
        }nt.cont = ____BAH_COMPILER_VAR_874;
}
else {
char * ____BAH_COMPILER_VAR_875 =null;char * ____BAH_COMPILER_VAR_876 =string__str(&ct);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen("*)channel__receive(");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_876);
unsigned int strLen_4 = strlen("*(");
;                            
            ____BAH_COMPILER_VAR_875 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_875+currStrOff, "*(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_875+currStrOff, ____BAH_COMPILER_VAR_876, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_875+currStrOff, "*)channel__receive(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_875+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_875+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }nt.cont = ____BAH_COMPILER_VAR_875;
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
struct Tok ____BAH_COMPILER_VAR_877 = {};
____BAH_COMPILER_VAR_877.cont = "";
____BAH_COMPILER_VAR_877.ogCont = "";
____BAH_COMPILER_VAR_877.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_877.pos = 0;
____BAH_COMPILER_VAR_877.line = 1;
____BAH_COMPILER_VAR_877.begLine = 1;
____BAH_COMPILER_VAR_877.bahType = "";
____BAH_COMPILER_VAR_877.isValue = false;
____BAH_COMPILER_VAR_877.isFunc = false;
____BAH_COMPILER_VAR_877.isOper = false;
____BAH_COMPILER_VAR_877.isEqual = false;
____BAH_COMPILER_VAR_877.pass = false;
____BAH_COMPILER_VAR_877.bahRef= null;
____BAH_COMPILER_VAR_877.parent= null;
#define pt ____BAH_COMPILER_VAR_877
long int l = len(fl);
i = 0;
for (; (i<len(fl)); ++i) {
struct Tok t = fl->data[i];
if ((t.type==TOKEN_TYPE_VAR)&&(t.isOper==false)&&(t.cont[0]==38)) {
struct string tc = string(t.cont);
string__trimLeft(&tc,1);
char * ____BAH_COMPILER_VAR_878 =string__str(&tc);struct variable* rv = getRealVar(____BAH_COMPILER_VAR_878,elems);
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
struct Tok ____BAH_COMPILER_VAR_879 = {};
____BAH_COMPILER_VAR_879.cont = "";
____BAH_COMPILER_VAR_879.ogCont = "";
____BAH_COMPILER_VAR_879.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_879.pos = 0;
____BAH_COMPILER_VAR_879.line = 1;
____BAH_COMPILER_VAR_879.begLine = 1;
____BAH_COMPILER_VAR_879.bahType = "";
____BAH_COMPILER_VAR_879.isValue = false;
____BAH_COMPILER_VAR_879.isFunc = false;
____BAH_COMPILER_VAR_879.isOper = false;
____BAH_COMPILER_VAR_879.isEqual = false;
____BAH_COMPILER_VAR_879.pass = false;
____BAH_COMPILER_VAR_879.bahRef= null;
____BAH_COMPILER_VAR_879.parent= null;
pt = ____BAH_COMPILER_VAR_879;
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
char * ____BAH_COMPILER_VAR_880 =string__str(&ptc);struct string cType = getCType(____BAH_COMPILER_VAR_880,elems);
char * ____BAH_COMPILER_VAR_881 =null;char * ____BAH_COMPILER_VAR_882 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(")");
unsigned int strLen_1 = strlen(t.cont);
unsigned int strLen_2 = strlen(____BAH_COMPILER_VAR_882);
unsigned int strLen_3 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_881 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_881+currStrOff, "(", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_881+currStrOff, ____BAH_COMPILER_VAR_882, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_881+currStrOff, ")", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_881+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_881;

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
char * ____BAH_COMPILER_VAR_883 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t.cont);
unsigned int strLen_1 = strlen(ppt.cont);
unsigned int strLen_2 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_883 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_883+currStrOff, t.cont, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_883+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_883+currStrOff, ppt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }ppt.cont = ____BAH_COMPILER_VAR_883;
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
char * ____BAH_COMPILER_VAR_884 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(pt.cont);
unsigned int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_884 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_884+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_884+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_884;

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
char * ____BAH_COMPILER_VAR_885 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ptt);
unsigned int strLen_1 = strlen(".");
unsigned int strLen_2 = strlen("Cannot use {TOKEN} on ");
;                            
            ____BAH_COMPILER_VAR_885 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_885+currStrOff, "Cannot use {TOKEN} on ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_885+currStrOff, ptt, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_885+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&t,____BAH_COMPILER_VAR_885);
}
char * ____BAH_COMPILER_VAR_886 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t.cont);
unsigned int strLen_1 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_886 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_886+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_886+currStrOff, nt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_887 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(pt.cont);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_886);
;                            
            ____BAH_COMPILER_VAR_887 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_887+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_887+currStrOff, ____BAH_COMPILER_VAR_886, strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_887;

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
char * ____BAH_COMPILER_VAR_888 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t.bahType);
unsigned int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_888 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_888+currStrOff, t.bahType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_888+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }t.bahType = ____BAH_COMPILER_VAR_888;

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
struct func* ____BAH_COMPILER_VAR_889 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_889->name = "";
____BAH_COMPILER_VAR_889->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_889->args->length = 0;
            ____BAH_COMPILER_VAR_889->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_889->returns= null;
____BAH_COMPILER_VAR_889->isBinding = false;
____BAH_COMPILER_VAR_889->from = "";
____BAH_COMPILER_VAR_889->file = "";
____BAH_COMPILER_VAR_889->line = 1;
____BAH_COMPILER_VAR_889->isVar = false;
____BAH_COMPILER_VAR_889->used = false;
____BAH_COMPILER_VAR_889->code = null;
____BAH_COMPILER_VAR_889->isMut = false;
____BAH_COMPILER_VAR_889->isImported = false;
struct func* fn = ____BAH_COMPILER_VAR_889;
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
char * ____BAH_COMPILER_VAR_890 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(lineStr);
unsigned int strLen_1 = strlen(".");
unsigned int strLen_2 = strlen(":");
unsigned int strLen_3 = strlen(ogFn->file);
unsigned int strLen_4 = strlen("Cannot redeclare function {TOKEN}, previous declaration: ");
;                            
            ____BAH_COMPILER_VAR_890 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_890+currStrOff, "Cannot redeclare function {TOKEN}, previous declaration: ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_890+currStrOff, ogFn->file, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_890+currStrOff, ":", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_890+currStrOff, lineStr, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_890+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&ft,____BAH_COMPILER_VAR_890);
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
char * ____BAH_COMPILER_VAR_891 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(";\n");
;                            
            ____BAH_COMPILER_VAR_891 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_891+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_891+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_891));
return;
}
char * ____BAH_COMPILER_VAR_892 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen("{\n");
;                            
            ____BAH_COMPILER_VAR_892 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_892+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_892+currStrOff, "{\n", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_892;
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
char * ____BAH_COMPILER_VAR_893 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fn->name);
unsigned int strLen_1 = strlen("' is not returned.");
unsigned int strLen_2 = strlen("Function '");
;                            
            ____BAH_COMPILER_VAR_893 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_893+currStrOff, "Function '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_893+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_893+currStrOff, "' is not returned.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&l->data[len(l)-1],____BAH_COMPILER_VAR_893);
}
endRCPscope(fnElems,fn->args);
}
else {
removeDefs(fnElems);
}
fn->code = rope__add(fn->code, OUTPUT);
OUTPUT = oOut;
fn->code = rope__add(fn->code, rope("};\n"));
OUTPUT = rope__add(OUTPUT, fn->code);
if ((debug==true)) {
struct debugFunction* ____BAH_COMPILER_VAR_894 = memoryAlloc(sizeof(struct debugFunction));
____BAH_COMPILER_VAR_894->name= null;
____BAH_COMPILER_VAR_894->returns= null;
____BAH_COMPILER_VAR_894->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_894->args->length = 0;
            ____BAH_COMPILER_VAR_894->args->elemSize = sizeof(struct variable*);
            struct debugFunction* df = ____BAH_COMPILER_VAR_894;
df->name = fn->name;
df->args = fn->args;
df->returns = fn->returns->type;
struct debugFunction* ____BAH_COMPILER_VAR_895 = df;
char ** ____BAH_COMPILER_VAR_897 = (char **)((char*)(____BAH_COMPILER_VAR_895) + offsetof(struct debugFunction, name));
struct reflectElement ____BAH_COMPILER_VAR_898 = __reflect(____BAH_COMPILER_VAR_897, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct debugFunction, name));
char ** ____BAH_COMPILER_VAR_899 = (char **)((char*)(____BAH_COMPILER_VAR_895) + offsetof(struct debugFunction, returns));
struct reflectElement ____BAH_COMPILER_VAR_900 = __reflect(____BAH_COMPILER_VAR_899, sizeof(char *), "cpstring", "returns", 0, 0, 0, 0, offsetof(struct debugFunction, returns));
array(struct variable*)** ____BAH_COMPILER_VAR_901 = (array(struct variable*)**)((char*)(____BAH_COMPILER_VAR_895) + offsetof(struct debugFunction, args));
struct variable** ____BAH_COMPILER_VAR_902 = 0;
char ** ____BAH_COMPILER_VAR_904 = (char **)((char*)(____BAH_COMPILER_VAR_902) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_905 = __reflect(____BAH_COMPILER_VAR_904, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_906 = (char **)((char*)(____BAH_COMPILER_VAR_902) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_907 = __reflect(____BAH_COMPILER_VAR_906, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_908 = (char*)((char*)(____BAH_COMPILER_VAR_902) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_909 = __reflect(____BAH_COMPILER_VAR_908, sizeof(char), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_910 = (char **)((char*)(____BAH_COMPILER_VAR_902) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_911 = __reflect(____BAH_COMPILER_VAR_910, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_912 = (char*)((char*)(____BAH_COMPILER_VAR_902) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_913 = __reflect(____BAH_COMPILER_VAR_912, sizeof(char), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_914 = (char **)((char*)(____BAH_COMPILER_VAR_902) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_915 = __reflect(____BAH_COMPILER_VAR_914, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
void ** ____BAH_COMPILER_VAR_916 = (void **)((char*)(____BAH_COMPILER_VAR_902) + offsetof(struct variable, declScope));
struct reflectElement ____BAH_COMPILER_VAR_917 = __reflect(____BAH_COMPILER_VAR_916, sizeof(void *), "ptr", "declScope", 0, 0, 0, 0, offsetof(struct variable, declScope));
char* ____BAH_COMPILER_VAR_918 = (char*)((char*)(____BAH_COMPILER_VAR_902) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_919 = __reflect(____BAH_COMPILER_VAR_918, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));
struct rope** ____BAH_COMPILER_VAR_920 = (struct rope**)((char*)(____BAH_COMPILER_VAR_902) + offsetof(struct variable, declRope));
void ** ____BAH_COMPILER_VAR_922 = (void **)((char*)(____BAH_COMPILER_VAR_920) + offsetof(struct rope, left));
struct reflectElement ____BAH_COMPILER_VAR_923 = __reflect(____BAH_COMPILER_VAR_922, sizeof(void *), "ptr", "left", 0, 0, 0, 0, offsetof(struct rope, left));
void ** ____BAH_COMPILER_VAR_924 = (void **)((char*)(____BAH_COMPILER_VAR_920) + offsetof(struct rope, right));
struct reflectElement ____BAH_COMPILER_VAR_925 = __reflect(____BAH_COMPILER_VAR_924, sizeof(void *), "ptr", "right", 0, 0, 0, 0, offsetof(struct rope, right));
char ** ____BAH_COMPILER_VAR_926 = (char **)((char*)(____BAH_COMPILER_VAR_920) + offsetof(struct rope, str));
struct reflectElement ____BAH_COMPILER_VAR_927 = __reflect(____BAH_COMPILER_VAR_926, sizeof(char *), "cpstring", "str", 0, 0, 0, 0, offsetof(struct rope, str));
int* ____BAH_COMPILER_VAR_928 = (int*)((char*)(____BAH_COMPILER_VAR_920) + offsetof(struct rope, lCount));
struct reflectElement ____BAH_COMPILER_VAR_929 = __reflect(____BAH_COMPILER_VAR_928, sizeof(int), "int32", "lCount", 0, 0, 0, 0, offsetof(struct rope, lCount));
int* ____BAH_COMPILER_VAR_930 = (int*)((char*)(____BAH_COMPILER_VAR_920) + offsetof(struct rope, len));
struct reflectElement ____BAH_COMPILER_VAR_931 = __reflect(____BAH_COMPILER_VAR_930, sizeof(int), "int32", "len", 0, 0, 0, 0, offsetof(struct rope, len));
int* ____BAH_COMPILER_VAR_932 = (int*)((char*)(____BAH_COMPILER_VAR_920) + offsetof(struct rope, totalLen));
struct reflectElement ____BAH_COMPILER_VAR_933 = __reflect(____BAH_COMPILER_VAR_932, sizeof(int), "int32", "totalLen", 0, 0, 0, 0, offsetof(struct rope, totalLen));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_921 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_921->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_921->length = 6;
        ____BAH_COMPILER_VAR_921->data = memoryAlloc(____BAH_COMPILER_VAR_921->length * ____BAH_COMPILER_VAR_921->elemSize);
        ____BAH_COMPILER_VAR_921->data[0] = ____BAH_COMPILER_VAR_923;
____BAH_COMPILER_VAR_921->data[1] = ____BAH_COMPILER_VAR_925;
____BAH_COMPILER_VAR_921->data[2] = ____BAH_COMPILER_VAR_927;
____BAH_COMPILER_VAR_921->data[3] = ____BAH_COMPILER_VAR_929;
____BAH_COMPILER_VAR_921->data[4] = ____BAH_COMPILER_VAR_931;
____BAH_COMPILER_VAR_921->data[5] = ____BAH_COMPILER_VAR_933;
struct reflectElement ____BAH_COMPILER_VAR_934 = __reflect(____BAH_COMPILER_VAR_920, sizeof(struct rope), "rope*", "declRope", 0, 0, 1, ____BAH_COMPILER_VAR_921, offsetof(struct variable, declRope));
char* ____BAH_COMPILER_VAR_935 = (char*)((char*)(____BAH_COMPILER_VAR_902) + offsetof(struct variable, canBeReg));
struct reflectElement ____BAH_COMPILER_VAR_936 = __reflect(____BAH_COMPILER_VAR_935, sizeof(char), "bool", "canBeReg", 0, 0, 0, 0, offsetof(struct variable, canBeReg));
char* ____BAH_COMPILER_VAR_937 = (char*)((char*)(____BAH_COMPILER_VAR_902) + offsetof(struct variable, isReg));
struct reflectElement ____BAH_COMPILER_VAR_938 = __reflect(____BAH_COMPILER_VAR_937, sizeof(char), "bool", "isReg", 0, 0, 0, 0, offsetof(struct variable, isReg));
void ** ____BAH_COMPILER_VAR_939 = (void **)((char*)(____BAH_COMPILER_VAR_902) + offsetof(struct variable, lastSet));
struct reflectElement ____BAH_COMPILER_VAR_940 = __reflect(____BAH_COMPILER_VAR_939, sizeof(void *), "ptr", "lastSet", 0, 0, 0, 0, offsetof(struct variable, lastSet));
char* ____BAH_COMPILER_VAR_941 = (char*)((char*)(____BAH_COMPILER_VAR_902) + offsetof(struct variable, isArg));
struct reflectElement ____BAH_COMPILER_VAR_942 = __reflect(____BAH_COMPILER_VAR_941, sizeof(char), "bool", "isArg", 0, 0, 0, 0, offsetof(struct variable, isArg));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_903 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_903->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_903->length = 13;
        ____BAH_COMPILER_VAR_903->data = memoryAlloc(____BAH_COMPILER_VAR_903->length * ____BAH_COMPILER_VAR_903->elemSize);
        ____BAH_COMPILER_VAR_903->data[0] = ____BAH_COMPILER_VAR_905;
____BAH_COMPILER_VAR_903->data[1] = ____BAH_COMPILER_VAR_907;
____BAH_COMPILER_VAR_903->data[2] = ____BAH_COMPILER_VAR_909;
____BAH_COMPILER_VAR_903->data[3] = ____BAH_COMPILER_VAR_911;
____BAH_COMPILER_VAR_903->data[4] = ____BAH_COMPILER_VAR_913;
____BAH_COMPILER_VAR_903->data[5] = ____BAH_COMPILER_VAR_915;
____BAH_COMPILER_VAR_903->data[6] = ____BAH_COMPILER_VAR_917;
____BAH_COMPILER_VAR_903->data[7] = ____BAH_COMPILER_VAR_919;
____BAH_COMPILER_VAR_903->data[8] = ____BAH_COMPILER_VAR_934;
____BAH_COMPILER_VAR_903->data[9] = ____BAH_COMPILER_VAR_936;
____BAH_COMPILER_VAR_903->data[10] = ____BAH_COMPILER_VAR_938;
____BAH_COMPILER_VAR_903->data[11] = ____BAH_COMPILER_VAR_940;
____BAH_COMPILER_VAR_903->data[12] = ____BAH_COMPILER_VAR_942;
struct reflectElement ____BAH_COMPILER_VAR_943 = __reflect(____BAH_COMPILER_VAR_902, sizeof(struct variable), "variable*", "", 0, 0, 1, ____BAH_COMPILER_VAR_903, 0);

        struct reflectElement ____BAH_COMPILER_VAR_944 = ____BAH_COMPILER_VAR_943;
        struct reflectElement ____BAH_COMPILER_VAR_945 = __reflect(____BAH_COMPILER_VAR_901, sizeof(array(struct variable*)*), "[]variable*", "args", 1, &____BAH_COMPILER_VAR_944, 0, 0, offsetof(struct debugFunction, args));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_896 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_896->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_896->length = 3;
        ____BAH_COMPILER_VAR_896->data = memoryAlloc(____BAH_COMPILER_VAR_896->length * ____BAH_COMPILER_VAR_896->elemSize);
        ____BAH_COMPILER_VAR_896->data[0] = ____BAH_COMPILER_VAR_898;
____BAH_COMPILER_VAR_896->data[1] = ____BAH_COMPILER_VAR_900;
____BAH_COMPILER_VAR_896->data[2] = ____BAH_COMPILER_VAR_945;
struct reflectElement ____BAH_COMPILER_VAR_946 = __reflect(____BAH_COMPILER_VAR_895, sizeof(struct debugFunction), "debugFunction*", "df", 0, 0, 1, ____BAH_COMPILER_VAR_896, 0);
debugPrint("fn_declare",ft.line,____BAH_COMPILER_VAR_946);
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
struct func* fn = searchFuncByToken(&ft,elems);
if ((fn!=null)&&(fn->returns!=null)&&isRCPtype(fn->returns->type,elems)) {
char * ____BAH_COMPILER_VAR_947 =registerRCPvar(fn->returns->type,ft.cont,elems);return;
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
char * ____BAH_COMPILER_VAR_948 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ft.cont);
unsigned int strLen_1 = strlen(";\n");
;                            
            ____BAH_COMPILER_VAR_948 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_948+currStrOff, ft.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_948+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_948));
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
char * ____BAH_COMPILER_VAR_949 =null;char * ____BAH_COMPILER_VAR_950 =string__str(&ct);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(" ");
unsigned int strLen_1 = strlen(arg->name);
unsigned int strLen_2 = strlen(____BAH_COMPILER_VAR_950);
unsigned int strLen_3 = strlen(tmpfnArgsCType);
;                            
            ____BAH_COMPILER_VAR_949 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_949+currStrOff, tmpfnArgsCType, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_949+currStrOff, ____BAH_COMPILER_VAR_950, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_949+currStrOff, " ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_949+currStrOff, arg->name, strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_949;
j = j+1;
if ((j<len(fn->args))) {
char * ____BAH_COMPILER_VAR_951 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpfnArgsCType);
unsigned int strLen_1 = strlen(", ");
;                            
            ____BAH_COMPILER_VAR_951 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_951+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_951+currStrOff, ", ", strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_951;
}
};
char * ____BAH_COMPILER_VAR_952 =null;char * ____BAH_COMPILER_VAR_953 =string__str(&tmpfnRetCType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpfnArgsCType);
unsigned int strLen_1 = strlen(");\n");
unsigned int strLen_2 = strlen("(");
unsigned int strLen_3 = strlen(fn->name);
unsigned int strLen_4 = strlen(" ");
unsigned int strLen_5 = strlen(____BAH_COMPILER_VAR_953);
;                            
            ____BAH_COMPILER_VAR_952 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_952+currStrOff, ____BAH_COMPILER_VAR_953, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_952+currStrOff, " ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_952+currStrOff, fn->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_952+currStrOff, "(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_952+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_952+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_952));
};
void declareVar(struct variable* v,struct Elems* elems){
if ((v->isConst==true)) {
char * ____BAH_COMPILER_VAR_954 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(v->constVal);
unsigned int strLen_1 = strlen("\n");
unsigned int strLen_2 = strlen(" ");
unsigned int strLen_3 = strlen(v->name);
unsigned int strLen_4 = strlen("#define ");
;                            
            ____BAH_COMPILER_VAR_954 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_954+currStrOff, "#define ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_954+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_954+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_954+currStrOff, v->constVal, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_954+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_954));
}
else {
struct string cType = getCType(v->type,elems);
char * ____BAH_COMPILER_VAR_955 =null;char * ____BAH_COMPILER_VAR_956 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(v->name);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen(" ");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_956);
;                            
            ____BAH_COMPILER_VAR_955 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_955+currStrOff, ____BAH_COMPILER_VAR_956, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_955+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_955+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_955+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_955));
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
char * ____BAH_COMPILER_VAR_957 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(compilerState.cIncludes->data[i]);
unsigned int strLen_1 = strlen("\n");
unsigned int strLen_2 = strlen("#include ");
;                            
            ____BAH_COMPILER_VAR_957 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_957+currStrOff, "#include ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_957+currStrOff, compilerState.cIncludes->data[i], strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_957+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_957));
};
i = 1;
for (; (i<len(compilerState.arrTypesDecl)); ++i) {
char * t = compilerState.arrTypesDecl->data[i];
struct string elemType = string(t);
string__trimLeft(&elemType,15);
char * ____BAH_COMPILER_VAR_958 =string__str(&elemType);struct string elemCtype = getCType(____BAH_COMPILER_VAR_958,elems);
char * ____BAH_COMPILER_VAR_959 =null;char * ____BAH_COMPILER_VAR_960 =string__str(&elemCtype);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen(")* ");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_960);
unsigned int strLen_4 = strlen("typedef array(");
;                            
            ____BAH_COMPILER_VAR_959 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_959+currStrOff, "typedef array(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_959+currStrOff, ____BAH_COMPILER_VAR_960, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_959+currStrOff, ")* ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_959+currStrOff, t, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_959+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_959));
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
char * ____BAH_COMPILER_VAR_961 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("file: ");
unsigned int strLen_1 = strlen(compilerState.currentFile);
;                            
            ____BAH_COMPILER_VAR_961 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_961+currStrOff, "file: ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_961+currStrOff, compilerState.currentFile, strLen_1);
            currStrOff += strLen_1;
        
        }char * r = ____BAH_COMPILER_VAR_961;
if ((currentFn!=null)) {
char * ____BAH_COMPILER_VAR_962 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(currentFn->name);
unsigned int strLen_1 = strlen("()");
unsigned int strLen_2 = strlen("\nfunction: ");
;                            
            ____BAH_COMPILER_VAR_962 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_962+currStrOff, "\nfunction: ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_962+currStrOff, currentFn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_962+currStrOff, "()", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_963 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(r);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_962);
;                            
            ____BAH_COMPILER_VAR_963 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_963+currStrOff, r, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_963+currStrOff, ____BAH_COMPILER_VAR_962, strLen_1);
            currStrOff += strLen_1;
        
        }r = ____BAH_COMPILER_VAR_963;
}
return r;
};
long int main(__BAH_ARR_TYPE_cpstring args){
onMemoryError = memErrHandle;
execName = args->data[0];
if ((execName[0]==46)||(execName[0]==47)) {
execName = absPath(execName);
}
struct flags ____BAH_COMPILER_VAR_964 = {};
____BAH_COMPILER_VAR_964.flags = memoryAlloc(sizeof(array(struct flag*)));
            ____BAH_COMPILER_VAR_964.flags->length = 0;
            ____BAH_COMPILER_VAR_964.flags->elemSize = sizeof(struct flag*);
            ____BAH_COMPILER_VAR_964.args = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_964.args->length = 0;
            ____BAH_COMPILER_VAR_964.args->elemSize = sizeof(char *);
            flags = ____BAH_COMPILER_VAR_964;
flags__addString(&flags,"o","Name of the file to output.");
flags__addBool(&flags,"c","Translate bah file to C instead of compiling it.");
flags__addBool(&flags,"v","Show version of the compiler.");
flags__addBool(&flags,"l","Compile as a library.");
flags__addBool(&flags,"rcp","Enables RCP (reference counter) instead of the garbage collector. Warning: if you are using self-reference, this will lead to memory leaks!");
flags__addBool(&flags,"fastrcp","Enables RCP without leak detection. It is recommended to test you programs with the -rcp flag to test for leak detection before using this flag.");
flags__addBool(&flags,"debug","Enables verbose json output.");
flags__addBool(&flags,"verboseRuntime","Enables verbose runtime, a debug mode of the compiled program. (obsolete)");
flags__addBool(&flags,"verboseCC","Enables verbose C compiler output, USE IN LAST RESORT.");
char * ____BAH_COMPILER_VAR_965 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(BAH_OS);
unsigned int strLen_1 = strlen(".");
unsigned int strLen_2 = strlen("Select the target OS for cross compilling (linux, windows, darwin), default: ");
;                            
            ____BAH_COMPILER_VAR_965 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_965+currStrOff, "Select the target OS for cross compilling (linux, windows, darwin), default: ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_965+currStrOff, BAH_OS, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_965+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }flags__addString(&flags,"target",____BAH_COMPILER_VAR_965);
char * ____BAH_COMPILER_VAR_966 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(BAH_DIR);
unsigned int strLen_1 = strlen(").");
unsigned int strLen_2 = strlen("If your Bah directory is not the default one (");
;                            
            ____BAH_COMPILER_VAR_966 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_966+currStrOff, "If your Bah directory is not the default one (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_966+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_966+currStrOff, ").", strLen_1);
            currStrOff += strLen_1;
        
        }flags__addString(&flags,"bahDir",____BAH_COMPILER_VAR_966);
char * ____BAH_COMPILER_VAR_967 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(BAH_CC);
unsigned int strLen_1 = strlen(".");
unsigned int strLen_2 = strlen("To change the C compiler used, default: ");
;                            
            ____BAH_COMPILER_VAR_967 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_967+currStrOff, "To change the C compiler used, default: ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_967+currStrOff, BAH_CC, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_967+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }flags__addString(&flags,"CC",____BAH_COMPILER_VAR_967);
flags__addBool(&flags,"object","Compile as an object.");
flags__addBool(&flags,"unsafe","Compile without safety checking. This will make for faster executable but if your program crashes, it will show less informations.");
flags__parse(&flags,args);
if ((flags__isSet(&flags,"target")==1)) {
BAH_OS = flags__get(&flags,"target");
char * ____BAH_COMPILER_VAR_968 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("Build target: ");
unsigned int strLen_1 = strlen(BAH_OS);
;                            
            ____BAH_COMPILER_VAR_968 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_968+currStrOff, "Build target: ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_968+currStrOff, BAH_OS, strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_968);
}
if ((flags__isSet(&flags,"bahDir")==1)) {
BAH_DIR = flags__get(&flags,"bahDir");
array(char)* bahDirArr = strAsArr(BAH_DIR);
if ((bahDirArr->data[len(bahDirArr)-1]!=47)) {
char * ____BAH_COMPILER_VAR_969 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(BAH_DIR);
unsigned int strLen_1 = strlen("/");
;                            
            ____BAH_COMPILER_VAR_969 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_969+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_969+currStrOff, "/", strLen_1);
            currStrOff += strLen_1;
        
        }BAH_DIR = ____BAH_COMPILER_VAR_969;
}
char * ____BAH_COMPILER_VAR_970 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("Bah directory: ");
unsigned int strLen_1 = strlen(BAH_DIR);
;                            
            ____BAH_COMPILER_VAR_970 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_970+currStrOff, "Bah directory: ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_970+currStrOff, BAH_DIR, strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_970);
}
if ((flags__isSet(&flags,"CC")==1)) {
BAH_CC = flags__get(&flags,"CC");
char * ____BAH_COMPILER_VAR_971 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("C compiler: ");
unsigned int strLen_1 = strlen(BAH_CC);
;                            
            ____BAH_COMPILER_VAR_971 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_971+currStrOff, "C compiler: ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_971+currStrOff, BAH_CC, strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_971);
}
if (flags__isSet(&flags,"verboseRuntime")) {
println("-verboseRuntime is obsolete.");
exit(1);
}
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
if ((debug==true)) {
debugStart();
}
RCPenabled = (flags__isSet(&flags,"rcp")==1)||flags__isSet(&flags,"fastrcp");
if ((flags__isSet(&flags,"v")==1)) {
char * ____BAH_COMPILER_VAR_972 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(BAH_VERSION);
unsigned int strLen_1 = strlen(".\n© Alois Laurent Boe");
unsigned int strLen_2 = strlen("Bah compiler version: ");
;                            
            ____BAH_COMPILER_VAR_972 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_972+currStrOff, "Bah compiler version: ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_972+currStrOff, BAH_VERSION, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_972+currStrOff, ".\n© Alois Laurent Boe", strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_972);
return 0;
}
if ((flags__isSet(&flags,"c")==1)&&(flags__isSet(&flags,"l")==1)) {
__BAH_panic("Cannot use -c (to translate to C code) and -l (to compile as a library) at the same time.","/home/alois/Documents/bah-bah/src/main.bah:135");
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
struct compilerStateTag ____BAH_COMPILER_VAR_973 = {};
____BAH_COMPILER_VAR_973.includes = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_973.includes->length = 0;
            ____BAH_COMPILER_VAR_973.includes->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_973.cIncludes = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_973.cIncludes->length = 0;
            ____BAH_COMPILER_VAR_973.cIncludes->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_973.cLibs = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_973.cLibs->length = 0;
            ____BAH_COMPILER_VAR_973.cLibs->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_973.currentFile= null;
____BAH_COMPILER_VAR_973.currentDir = "./";
____BAH_COMPILER_VAR_973.isBranch = false;
____BAH_COMPILER_VAR_973.isFor = false;
____BAH_COMPILER_VAR_973.arrTypesDecl = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_973.arrTypesDecl->length = 0;
            ____BAH_COMPILER_VAR_973.arrTypesDecl->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_973.haveEntryPoint = false;
____BAH_COMPILER_VAR_973.RCPvars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_973.RCPvars->length = 0;
            ____BAH_COMPILER_VAR_973.RCPvars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_973.evals = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_973.evals->length = 0;
            ____BAH_COMPILER_VAR_973.evals->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_973.hasImports = false;
____BAH_COMPILER_VAR_973.currForElems= null;
____BAH_COMPILER_VAR_973.currFnElems= null;
compilerState = ____BAH_COMPILER_VAR_973;

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
struct fileMap ____BAH_COMPILER_VAR_974 = {};
____BAH_COMPILER_VAR_974.handle = -1;
____BAH_COMPILER_VAR_974.p= null;
#define fm ____BAH_COMPILER_VAR_974
char * f = fileMap__open(&fm,fileName);
if ((fileMap__isValid(&fm)==0)||(fm.size==0)) {
char * ____BAH_COMPILER_VAR_975 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(args->data[1]);
unsigned int strLen_1 = strlen("'.");
unsigned int strLen_2 = strlen("Could not open file '");
;                            
            ____BAH_COMPILER_VAR_975 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_975+currStrOff, "Could not open file '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_975+currStrOff, args->data[1], strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_975+currStrOff, "'.", strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_975);
exit(1);
}
long int startTime = getTimeUnix();
array(struct Tok)* tokens = lexer(f);
fileMap__close(&fm);
if ((len(tokens)==0)) {
char * ____BAH_COMPILER_VAR_976 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fileName);
unsigned int strLen_1 = strlen("' not recognized.");
unsigned int strLen_2 = strlen("File '");
;                            
            ____BAH_COMPILER_VAR_976 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_976+currStrOff, "File '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_976+currStrOff, fileName, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_976+currStrOff, "' not recognized.", strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_976);
exit(1);
}
struct Elems* ____BAH_COMPILER_VAR_977 = memoryAlloc(sizeof(struct Elems));
____BAH_COMPILER_VAR_977->vars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_977->vars->length = 0;
            ____BAH_COMPILER_VAR_977->vars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_977->structs = memoryAlloc(sizeof(array(struct cStruct*)));
            ____BAH_COMPILER_VAR_977->structs->length = 0;
            ____BAH_COMPILER_VAR_977->structs->elemSize = sizeof(struct cStruct*);
            ____BAH_COMPILER_VAR_977->types = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_977->types->length = 0;
            ____BAH_COMPILER_VAR_977->types->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_977->fns = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_977->fns->length = 0;
            ____BAH_COMPILER_VAR_977->fns->elemSize = sizeof(struct func*);
            ____BAH_COMPILER_VAR_977->defined = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_977->defined->length = 0;
            ____BAH_COMPILER_VAR_977->defined->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_977->parent= null;
struct Elems* elems = ____BAH_COMPILER_VAR_977;
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
if ((includeFile("builtin.bah",elems)==false)) {
char * ____BAH_COMPILER_VAR_978 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(BAH_DIR);
unsigned int strLen_1 = strlen("'");
unsigned int strLen_2 = strlen("Could not find std-libs, please check '");
;                            
            ____BAH_COMPILER_VAR_978 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_978+currStrOff, "Could not find std-libs, please check '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_978+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_978+currStrOff, "'", strLen_1);
            currStrOff += strLen_1;
        
        }__BAH_panic(____BAH_COMPILER_VAR_978,"/home/alois/Documents/bah-bah/src/main.bah:245");
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
char * ____BAH_COMPILER_VAR_979 =null;char * ____BAH_COMPILER_VAR_980 =intToStr(l);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_980);
unsigned int strLen_1 = strlen("];");
unsigned int strLen_2 = strlen("volatile struct __Bah_fnName_mapper __tmp____Bah_fnNames[");
;                            
            ____BAH_COMPILER_VAR_979 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_979+currStrOff, "volatile struct __Bah_fnName_mapper __tmp____Bah_fnNames[", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_979+currStrOff, ____BAH_COMPILER_VAR_980, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_979+currStrOff, "];", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_981 =____BAH_COMPILER_VAR_979;OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_981));
long int j = 0;
i = 0;
for (; (i<len(elems->fns)); ++i) {
struct func* fn = elems->fns->data[i];
if ((fn->isBinding==true)) {
continue;
}
char * name = fn->name;
char * ____BAH_COMPILER_VAR_982 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fn->from);
unsigned int strLen_1 = strlen("__");
;                            
            ____BAH_COMPILER_VAR_982 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_982+currStrOff, fn->from, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_982+currStrOff, "__", strLen_1);
            currStrOff += strLen_1;
        
        }if ((strcmp(fn->from, "") != 0)&&strHasPrefix(name,____BAH_COMPILER_VAR_982)) {
struct string n = string(name);
string__trimLeft(&n,strlen(fn->from)+2);
char * ____BAH_COMPILER_VAR_983 =null;char * ____BAH_COMPILER_VAR_984 =string__str(&n);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(".");
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_984);
unsigned int strLen_2 = strlen(fn->from);
;                            
            ____BAH_COMPILER_VAR_983 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_983+currStrOff, fn->from, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_983+currStrOff, ".", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_983+currStrOff, ____BAH_COMPILER_VAR_984, strLen_1);
            currStrOff += strLen_1;
        
        }name = ____BAH_COMPILER_VAR_983;
}
char * ____BAH_COMPILER_VAR_985 =null;char * ____BAH_COMPILER_VAR_986 =intToStr(j);char * ____BAH_COMPILER_VAR_987 =intToStr(j);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fn->name);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen("].p = ");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_986);
unsigned int strLen_4 = strlen("\";\n            __tmp____Bah_fnNames[");
unsigned int strLen_5 = strlen(name);
unsigned int strLen_6 = strlen("].n = \"");
unsigned int strLen_7 = strlen(____BAH_COMPILER_VAR_987);
unsigned int strLen_8 = strlen("\n            __tmp____Bah_fnNames[");
;                            
            ____BAH_COMPILER_VAR_985 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_985+currStrOff, "\n            __tmp____Bah_fnNames[", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_985+currStrOff, ____BAH_COMPILER_VAR_987, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_985+currStrOff, "].n = \"", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_985+currStrOff, name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_985+currStrOff, "\";\n            __tmp____Bah_fnNames[", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_985+currStrOff, ____BAH_COMPILER_VAR_986, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_985+currStrOff, "].p = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_985+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_985+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_985));
++j;
};
char * ____BAH_COMPILER_VAR_988 =null;char * ____BAH_COMPILER_VAR_989 =intToStr(l);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_989);
unsigned int strLen_1 = strlen(";");
unsigned int strLen_2 = strlen("\n        __Bah_fnNames->data = __tmp____Bah_fnNames;\n        __Bah_fnNames->length = ");
;                            
            ____BAH_COMPILER_VAR_988 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_988+currStrOff, "\n        __Bah_fnNames->data = __tmp____Bah_fnNames;\n        __Bah_fnNames->length = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_988+currStrOff, ____BAH_COMPILER_VAR_989, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_988+currStrOff, ";", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_990 =____BAH_COMPILER_VAR_988;INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_990));
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
char * ____BAH_COMPILER_VAR_991 =null;char * ____BAH_COMPILER_VAR_992 =intToStr(totalLexerTime/1000000);char * ____BAH_COMPILER_VAR_993 =intToStr(totalTime/1000000);char * ____BAH_COMPILER_VAR_994 =intToStr(totalLines);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_992);
unsigned int strLen_1 = strlen("ms)\e[0m");
unsigned int strLen_2 = strlen("ms, lexer time: ");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_993);
unsigned int strLen_4 = strlen(" lines, total time: ");
unsigned int strLen_5 = strlen(____BAH_COMPILER_VAR_994);
unsigned int strLen_6 = strlen("Parsed. (");
;                            
            ____BAH_COMPILER_VAR_991 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_991+currStrOff, "Parsed. (", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_991+currStrOff, ____BAH_COMPILER_VAR_994, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_991+currStrOff, " lines, total time: ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_991+currStrOff, ____BAH_COMPILER_VAR_993, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_991+currStrOff, "ms, lexer time: ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_991+currStrOff, ____BAH_COMPILER_VAR_992, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_991+currStrOff, "ms)\e[0m", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_995 =____BAH_COMPILER_VAR_991;println(____BAH_COMPILER_VAR_995);
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
char * ____BAH_COMPILER_VAR_996 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fileName);
unsigned int strLen_1 = strlen(".o");
;                            
            ____BAH_COMPILER_VAR_996 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_996+currStrOff, fileName, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_996+currStrOff, ".o", strLen_1);
            currStrOff += strLen_1;
        
        }fileName = ____BAH_COMPILER_VAR_996;
obj = "-c";
}
char * randFileName = "-x c - -x none";
char * ____BAH_COMPILER_VAR_997 =null;
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
            ____BAH_COMPILER_VAR_997 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13+strLen_14+strLen_15+strLen_16);
            
                    memcpy(____BAH_COMPILER_VAR_997+currStrOff, BAH_CC, strLen_16);
                    currStrOff += strLen_16;
                    
                    memcpy(____BAH_COMPILER_VAR_997+currStrOff, " -I \"", strLen_15);
                    currStrOff += strLen_15;
                    
                    memcpy(____BAH_COMPILER_VAR_997+currStrOff, BAH_DIR, strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_997+currStrOff, "libs/", strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_997+currStrOff, BAH_OS, strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_997+currStrOff, "/include/\" -L \"", strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_997+currStrOff, BAH_DIR, strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_997+currStrOff, "libs/", strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_997+currStrOff, BAH_OS, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_997+currStrOff, "/\" ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_997+currStrOff, randFileName, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_997+currStrOff, " ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_997+currStrOff, isStatic, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_997+currStrOff, " ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_997+currStrOff, obj, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_997+currStrOff, " -w -O1 -o ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_997+currStrOff, fileName, strLen_1);
            currStrOff += strLen_1;
        
        }char * gccArgs = ____BAH_COMPILER_VAR_997;
if ((flags__isSet(&flags,"l")==1)) {
char * ____BAH_COMPILER_VAR_998 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(gccArgs);
unsigned int strLen_1 = strlen(" -c");
;                            
            ____BAH_COMPILER_VAR_998 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_998+currStrOff, gccArgs, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_998+currStrOff, " -c", strLen_1);
            currStrOff += strLen_1;
        
        }gccArgs = ____BAH_COMPILER_VAR_998;
}
array(char *)* cLibs = compilerState.cLibs;
register long int i = 0;
while ((i<len(cLibs))) {
char * l = cLibs->data[i];
char * ____BAH_COMPILER_VAR_999 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(" -");
unsigned int strLen_1 = strlen(l);
unsigned int strLen_2 = strlen(gccArgs);
;                            
            ____BAH_COMPILER_VAR_999 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_999+currStrOff, gccArgs, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_999+currStrOff, " -", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_999+currStrOff, l, strLen_1);
            currStrOff += strLen_1;
        
        }gccArgs = ____BAH_COMPILER_VAR_999;
i = i+1;
};
struct command cmd = command(gccArgs);
cmd.input = rope__toStr(OUTPUT);
if ((flags__isSet(&flags,"verboseCC")==1)) {
char * ____BAH_COMPILER_VAR_1000 =command__run(&cmd);println(____BAH_COMPILER_VAR_1000);
}
else {
char * ____BAH_COMPILER_VAR_1001 =command__run(&cmd);}
if ((cmd.status!=0)) {
println("\e[1;31m[CC-ERROR]\e[0m\nCould not compiled.");
return 1;
}
if ((flags__isSet(&flags,"l")==1)) {
char * ____BAH_COMPILER_VAR_1002 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(".a ");
unsigned int strLen_1 = strlen(fileName);
unsigned int strLen_2 = strlen(fileName);
unsigned int strLen_3 = strlen("ar rcs ");
;                            
            ____BAH_COMPILER_VAR_1002 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_1002+currStrOff, "ar rcs ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_1002+currStrOff, fileName, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_1002+currStrOff, ".a ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_1002+currStrOff, fileName, strLen_1);
            currStrOff += strLen_1;
        
        }cmd = command(____BAH_COMPILER_VAR_1002);
char * ____BAH_COMPILER_VAR_1003 =command__run(&cmd);}
}
else {
if ((flags__isSet(&flags,"o")==0)) {
char * ____BAH_COMPILER_VAR_1004 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fileName);
unsigned int strLen_1 = strlen(".c");
;                            
            ____BAH_COMPILER_VAR_1004 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_1004+currStrOff, fileName, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_1004+currStrOff, ".c", strLen_1);
            currStrOff += strLen_1;
        
        }fileName = ____BAH_COMPILER_VAR_1004;
}
char * ____BAH_COMPILER_VAR_1005 =null;
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
            ____BAH_COMPILER_VAR_1005 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13);
            
                    memcpy(____BAH_COMPILER_VAR_1005+currStrOff, BAH_CC, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_1005+currStrOff, " -I \"", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_1005+currStrOff, BAH_DIR, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_1005+currStrOff, "libs/", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_1005+currStrOff, BAH_OS, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_1005+currStrOff, "/include/\" -L \"", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_1005+currStrOff, BAH_DIR, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_1005+currStrOff, "libs/", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_1005+currStrOff, BAH_OS, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_1005+currStrOff, "/\" ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_1005+currStrOff, fileName, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_1005+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_1005+currStrOff, isStatic, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_1005+currStrOff, " -O1 -w ", strLen_1);
            currStrOff += strLen_1;
        
        }char * gccArgs = ____BAH_COMPILER_VAR_1005;
array(char *)* cLibs = compilerState.cLibs;
register long int i = 0;
while ((i<len(cLibs))) {
char * l = cLibs->data[i];
char * ____BAH_COMPILER_VAR_1006 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(" -");
unsigned int strLen_1 = strlen(l);
unsigned int strLen_2 = strlen(gccArgs);
;                            
            ____BAH_COMPILER_VAR_1006 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_1006+currStrOff, gccArgs, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_1006+currStrOff, " -", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_1006+currStrOff, l, strLen_1);
            currStrOff += strLen_1;
        
        }gccArgs = ____BAH_COMPILER_VAR_1006;
i = i+1;
};
char * ____BAH_COMPILER_VAR_1007 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(gccArgs);
unsigned int strLen_1 = strlen("'\n");
unsigned int strLen_2 = strlen("//COMPILE WITH: '");
;                            
            ____BAH_COMPILER_VAR_1007 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_1007+currStrOff, "//COMPILE WITH: '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_1007+currStrOff, gccArgs, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_1007+currStrOff, "'\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(rope(____BAH_COMPILER_VAR_1007), OUTPUT);
struct fileStream ____BAH_COMPILER_VAR_1008 = {};
____BAH_COMPILER_VAR_1008.handle= null;
____BAH_COMPILER_VAR_1008.name= null;
#define fs ____BAH_COMPILER_VAR_1008
fileStream__open(&fs,fileName,"w");
char * ____BAH_COMPILER_VAR_1009 =rope__toStr(OUTPUT);fileStream__writeFile(&fs,____BAH_COMPILER_VAR_1009);
fileStream__close(&fs);

#undef fs
}
if ((isObject==false)) {
long int totalTime = getTimeUnix()-startTime;
char * ____BAH_COMPILER_VAR_1010 =null;char * ____BAH_COMPILER_VAR_1011 =intToStr(totalTime/1000000);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_1011);
unsigned int strLen_1 = strlen("ms)\e[0m");
unsigned int strLen_2 = strlen("\e[1;32mDone. (compiled in ");
;                            
            ____BAH_COMPILER_VAR_1010 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_1010+currStrOff, "\e[1;32mDone. (compiled in ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_1010+currStrOff, ____BAH_COMPILER_VAR_1011, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_1010+currStrOff, "ms)\e[0m", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_1012 =____BAH_COMPILER_VAR_1010;println(____BAH_COMPILER_VAR_1012);
}
return 0;

#undef fm
};
volatile struct __Bah_fnName_mapper __tmp____Bah_fnNames[300];
    
    void __attribute__((optimize("O0"))) __BAH_init() {
        __BAH_panic_chan = null;
__Bah_fnNames = memoryAlloc(sizeof(array(struct __Bah_fnName_mapper)));

__Bah_fnNames->length = 0;
__Bah_fnNames->elemSize = sizeof(struct __Bah_fnName_mapper);
onMemoryError = null;
__Bah_init_segfaultHandle_OK = __Bah_init_segfaultHandle();
RAND_SEEDED = 0;
BAH_DIR = "/opt/bah/";
BAH_OS = "darwin";
BAH_CC = "clang";
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

keywords->length = 21;
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

            __tmp____Bah_fnNames[4].n = "__BAH_memcpy";
            __tmp____Bah_fnNames[4].p = __BAH_memcpy;

            __tmp____Bah_fnNames[5].n = "len";
            __tmp____Bah_fnNames[5].p = len;

            __tmp____Bah_fnNames[6].n = "memoryAlloc";
            __tmp____Bah_fnNames[6].p = memoryAlloc;

            __tmp____Bah_fnNames[7].n = "destroy";
            __tmp____Bah_fnNames[7].p = destroy;

            __tmp____Bah_fnNames[8].n = "clear";
            __tmp____Bah_fnNames[8].p = clear;

            __tmp____Bah_fnNames[9].n = "memoryRealloc";
            __tmp____Bah_fnNames[9].p = memoryRealloc;

            __tmp____Bah_fnNames[10].n = "cleanShutDown";
            __tmp____Bah_fnNames[10].p = cleanShutDown;

            __tmp____Bah_fnNames[11].n = "memoryOnEnd";
            __tmp____Bah_fnNames[11].p = memoryOnEnd;

            __tmp____Bah_fnNames[12].n = "append";
            __tmp____Bah_fnNames[12].p = append;

            __tmp____Bah_fnNames[13].n = "copy";
            __tmp____Bah_fnNames[13].p = copy;

            __tmp____Bah_fnNames[14].n = "sharedMemory";
            __tmp____Bah_fnNames[14].p = sharedMemory;

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

            __tmp____Bah_fnNames[100].n = "strCatOffset";
            __tmp____Bah_fnNames[100].p = strCatOffset;

            __tmp____Bah_fnNames[101].n = "charToString";
            __tmp____Bah_fnNames[101].p = charToString;

            __tmp____Bah_fnNames[102].n = "isUpper";
            __tmp____Bah_fnNames[102].p = isUpper;

            __tmp____Bah_fnNames[103].n = "isLower";
            __tmp____Bah_fnNames[103].p = isLower;

            __tmp____Bah_fnNames[104].n = "isLetter";
            __tmp____Bah_fnNames[104].p = isLetter;

            __tmp____Bah_fnNames[105].n = "isNumber";
            __tmp____Bah_fnNames[105].p = isNumber;

            __tmp____Bah_fnNames[106].n = "isAlphaNumeric";
            __tmp____Bah_fnNames[106].p = isAlphaNumeric;

            __tmp____Bah_fnNames[107].n = "isSpace";
            __tmp____Bah_fnNames[107].p = isSpace;

            __tmp____Bah_fnNames[108].n = "string.set";
            __tmp____Bah_fnNames[108].p = string__set;

            __tmp____Bah_fnNames[109].n = "string.makeEditable";
            __tmp____Bah_fnNames[109].p = string__makeEditable;

            __tmp____Bah_fnNames[110].n = "string.append";
            __tmp____Bah_fnNames[110].p = string__append;

            __tmp____Bah_fnNames[111].n = "string.prepend";
            __tmp____Bah_fnNames[111].p = string__prepend;

            __tmp____Bah_fnNames[112].n = "string.charAt";
            __tmp____Bah_fnNames[112].p = string__charAt;

            __tmp____Bah_fnNames[113].n = "string.compare";
            __tmp____Bah_fnNames[113].p = string__compare;

            __tmp____Bah_fnNames[114].n = "string.str";
            __tmp____Bah_fnNames[114].p = string__str;

            __tmp____Bah_fnNames[115].n = "string.replace";
            __tmp____Bah_fnNames[115].p = string__replace;

            __tmp____Bah_fnNames[116].n = "string.countChar";
            __tmp____Bah_fnNames[116].p = string__countChar;

            __tmp____Bah_fnNames[117].n = "string.count";
            __tmp____Bah_fnNames[117].p = string__count;

            __tmp____Bah_fnNames[118].n = "string.hasPrefix";
            __tmp____Bah_fnNames[118].p = string__hasPrefix;

            __tmp____Bah_fnNames[119].n = "string.hasSuffix";
            __tmp____Bah_fnNames[119].p = string__hasSuffix;

            __tmp____Bah_fnNames[120].n = "string.trim";
            __tmp____Bah_fnNames[120].p = string__trim;

            __tmp____Bah_fnNames[121].n = "string.trimLeft";
            __tmp____Bah_fnNames[121].p = string__trimLeft;

            __tmp____Bah_fnNames[122].n = "string.trimRight";
            __tmp____Bah_fnNames[122].p = string__trimRight;

            __tmp____Bah_fnNames[123].n = "string.add";
            __tmp____Bah_fnNames[123].p = string__add;

            __tmp____Bah_fnNames[124].n = "string";
            __tmp____Bah_fnNames[124].p = string;

            __tmp____Bah_fnNames[125].n = "intToStr";
            __tmp____Bah_fnNames[125].p = intToStr;

            __tmp____Bah_fnNames[126].n = "intToString";
            __tmp____Bah_fnNames[126].p = intToString;

            __tmp____Bah_fnNames[127].n = "floatToStr";
            __tmp____Bah_fnNames[127].p = floatToStr;

            __tmp____Bah_fnNames[128].n = "strToInt";
            __tmp____Bah_fnNames[128].p = strToInt;

            __tmp____Bah_fnNames[129].n = "strToFloat";
            __tmp____Bah_fnNames[129].p = strToFloat;

            __tmp____Bah_fnNames[130].n = "stringToInt";
            __tmp____Bah_fnNames[130].p = stringToInt;

            __tmp____Bah_fnNames[131].n = "splitString";
            __tmp____Bah_fnNames[131].p = splitString;

            __tmp____Bah_fnNames[132].n = "joinString";
            __tmp____Bah_fnNames[132].p = joinString;

            __tmp____Bah_fnNames[133].n = "splitStringBefore";
            __tmp____Bah_fnNames[133].p = splitStringBefore;

            __tmp____Bah_fnNames[134].n = "toLower";
            __tmp____Bah_fnNames[134].p = toLower;

            __tmp____Bah_fnNames[135].n = "strHasPrefix";
            __tmp____Bah_fnNames[135].p = strHasPrefix;

            __tmp____Bah_fnNames[136].n = "strHasSuffix";
            __tmp____Bah_fnNames[136].p = strHasSuffix;

            __tmp____Bah_fnNames[137].n = "strTrim";
            __tmp____Bah_fnNames[137].p = strTrim;

            __tmp____Bah_fnNames[138].n = "strCount";
            __tmp____Bah_fnNames[138].p = strCount;

            __tmp____Bah_fnNames[139].n = "flags.addString";
            __tmp____Bah_fnNames[139].p = flags__addString;

            __tmp____Bah_fnNames[140].n = "flags.addBool";
            __tmp____Bah_fnNames[140].p = flags__addBool;

            __tmp____Bah_fnNames[141].n = "flags.addInt";
            __tmp____Bah_fnNames[141].p = flags__addInt;

            __tmp____Bah_fnNames[142].n = "flags.addFloat";
            __tmp____Bah_fnNames[142].p = flags__addFloat;

            __tmp____Bah_fnNames[143].n = "flags.invalidate";
            __tmp____Bah_fnNames[143].p = flags__invalidate;

            __tmp____Bah_fnNames[144].n = "flags.getFlag";
            __tmp____Bah_fnNames[144].p = flags__getFlag;

            __tmp____Bah_fnNames[145].n = "flags.get";
            __tmp____Bah_fnNames[145].p = flags__get;

            __tmp____Bah_fnNames[146].n = "flags.getInt";
            __tmp____Bah_fnNames[146].p = flags__getInt;

            __tmp____Bah_fnNames[147].n = "flags.getFloat";
            __tmp____Bah_fnNames[147].p = flags__getFloat;

            __tmp____Bah_fnNames[148].n = "flags.isSet";
            __tmp____Bah_fnNames[148].p = flags__isSet;

            __tmp____Bah_fnNames[149].n = "flags.parse";
            __tmp____Bah_fnNames[149].p = flags__parse;

            __tmp____Bah_fnNames[150].n = "time.now";
            __tmp____Bah_fnNames[150].p = time__now;

            __tmp____Bah_fnNames[151].n = "time.format";
            __tmp____Bah_fnNames[151].p = time__format;

            __tmp____Bah_fnNames[152].n = "time.since";
            __tmp____Bah_fnNames[152].p = time__since;

            __tmp____Bah_fnNames[153].n = "getTimeUnix";
            __tmp____Bah_fnNames[153].p = getTimeUnix;

            __tmp____Bah_fnNames[154].n = "seedRandom";
            __tmp____Bah_fnNames[154].p = seedRandom;

            __tmp____Bah_fnNames[155].n = "randomInRange";
            __tmp____Bah_fnNames[155].p = randomInRange;

            __tmp____Bah_fnNames[156].n = "cryptoRand";
            __tmp____Bah_fnNames[156].p = cryptoRand;

            __tmp____Bah_fnNames[157].n = "rope.addStr";
            __tmp____Bah_fnNames[157].p = rope__addStr;

            __tmp____Bah_fnNames[158].n = "rope.toStr";
            __tmp____Bah_fnNames[158].p = rope__toStr;

            __tmp____Bah_fnNames[159].n = "rope.add";
            __tmp____Bah_fnNames[159].p = rope__add;

            __tmp____Bah_fnNames[160].n = "createRopeStructure";
            __tmp____Bah_fnNames[160].p = createRopeStructure;

            __tmp____Bah_fnNames[161].n = "ropeSet";
            __tmp____Bah_fnNames[161].p = ropeSet;

            __tmp____Bah_fnNames[162].n = "concatenateRopes";
            __tmp____Bah_fnNames[162].p = concatenateRopes;

            __tmp____Bah_fnNames[163].n = "rope";
            __tmp____Bah_fnNames[163].p = rope;

            __tmp____Bah_fnNames[164].n = "command.run";
            __tmp____Bah_fnNames[164].p = command__run;

            __tmp____Bah_fnNames[165].n = "command.runBytes";
            __tmp____Bah_fnNames[165].p = command__runBytes;

            __tmp____Bah_fnNames[166].n = "command";
            __tmp____Bah_fnNames[166].p = command;

            __tmp____Bah_fnNames[167].n = "exec";
            __tmp____Bah_fnNames[167].p = exec;

            __tmp____Bah_fnNames[168].n = "inArray";
            __tmp____Bah_fnNames[168].p = inArray;

            __tmp____Bah_fnNames[169].n = "inArrayStr";
            __tmp____Bah_fnNames[169].p = inArrayStr;

            __tmp____Bah_fnNames[170].n = "makeToken";
            __tmp____Bah_fnNames[170].p = makeToken;

            __tmp____Bah_fnNames[171].n = "isMinus";
            __tmp____Bah_fnNames[171].p = isMinus;

            __tmp____Bah_fnNames[172].n = "lexerErr";
            __tmp____Bah_fnNames[172].p = lexerErr;

            __tmp____Bah_fnNames[173].n = "lexer";
            __tmp____Bah_fnNames[173].p = lexer;

            __tmp____Bah_fnNames[174].n = "hasStructSep";
            __tmp____Bah_fnNames[174].p = hasStructSep;

            __tmp____Bah_fnNames[175].n = "splitStructSepBefore";
            __tmp____Bah_fnNames[175].p = splitStructSepBefore;

            __tmp____Bah_fnNames[176].n = "splitStructSepAfter";
            __tmp____Bah_fnNames[176].p = splitStructSepAfter;

            __tmp____Bah_fnNames[177].n = "searchStruct";
            __tmp____Bah_fnNames[177].p = searchStruct;

            __tmp____Bah_fnNames[178].n = "searchStructMemb";
            __tmp____Bah_fnNames[178].p = searchStructMemb;

            __tmp____Bah_fnNames[179].n = "searchFunc";
            __tmp____Bah_fnNames[179].p = searchFunc;

            __tmp____Bah_fnNames[180].n = "parseFnType";
            __tmp____Bah_fnNames[180].p = parseFnType;

            __tmp____Bah_fnNames[181].n = "searchStructMethod";
            __tmp____Bah_fnNames[181].p = searchStructMethod;

            __tmp____Bah_fnNames[182].n = "typeAsStar";
            __tmp____Bah_fnNames[182].p = typeAsStar;

            __tmp____Bah_fnNames[183].n = "isRCPpointerType";
            __tmp____Bah_fnNames[183].p = isRCPpointerType;

            __tmp____Bah_fnNames[184].n = "isRCPtype";
            __tmp____Bah_fnNames[184].p = isRCPtype;

            __tmp____Bah_fnNames[185].n = "getCType";
            __tmp____Bah_fnNames[185].p = getCType;

            __tmp____Bah_fnNames[186].n = "compTypeEquiv";
            __tmp____Bah_fnNames[186].p = compTypeEquiv;

            __tmp____Bah_fnNames[187].n = "compTypes";
            __tmp____Bah_fnNames[187].p = compTypes;

            __tmp____Bah_fnNames[188].n = "reflectElement.calculateOffset";
            __tmp____Bah_fnNames[188].p = reflectElement__calculateOffset;

            __tmp____Bah_fnNames[189].n = "__reflect";
            __tmp____Bah_fnNames[189].p = __reflect;

            __tmp____Bah_fnNames[190].n = "__dumpSymbols";
            __tmp____Bah_fnNames[190].p = __dumpSymbols;

            __tmp____Bah_fnNames[191].n = "__debug_get_sym";
            __tmp____Bah_fnNames[191].p = __debug_get_sym;

            __tmp____Bah_fnNames[192].n = "toJson";
            __tmp____Bah_fnNames[192].p = toJson;

            __tmp____Bah_fnNames[193].n = "json_scan_inner";
            __tmp____Bah_fnNames[193].p = json_scan_inner;

            __tmp____Bah_fnNames[194].n = "jsonElement.get";
            __tmp____Bah_fnNames[194].p = jsonElement__get;

            __tmp____Bah_fnNames[195].n = "jsonElement.str";
            __tmp____Bah_fnNames[195].p = jsonElement__str;

            __tmp____Bah_fnNames[196].n = "jsonElement.scan";
            __tmp____Bah_fnNames[196].p = jsonElement__scan;

            __tmp____Bah_fnNames[197].n = "parseJson";
            __tmp____Bah_fnNames[197].p = parseJson;

            __tmp____Bah_fnNames[198].n = "jsonEscapeStr";
            __tmp____Bah_fnNames[198].p = jsonEscapeStr;

            __tmp____Bah_fnNames[199].n = "toJson__inner";
            __tmp____Bah_fnNames[199].p = toJson__inner;

            __tmp____Bah_fnNames[200].n = "debugStart";
            __tmp____Bah_fnNames[200].p = debugStart;

            __tmp____Bah_fnNames[201].n = "debugPrint";
            __tmp____Bah_fnNames[201].p = debugPrint;

            __tmp____Bah_fnNames[202].n = "debugError";
            __tmp____Bah_fnNames[202].p = debugError;

            __tmp____Bah_fnNames[203].n = "debugEnd";
            __tmp____Bah_fnNames[203].p = debugEnd;

            __tmp____Bah_fnNames[204].n = "debugExit";
            __tmp____Bah_fnNames[204].p = debugExit;

            __tmp____Bah_fnNames[205].n = "debugEndScope";
            __tmp____Bah_fnNames[205].p = debugEndScope;

            __tmp____Bah_fnNames[206].n = "throwErr";
            __tmp____Bah_fnNames[206].p = throwErr;

            __tmp____Bah_fnNames[207].n = "throwWarning";
            __tmp____Bah_fnNames[207].p = throwWarning;

            __tmp____Bah_fnNames[208].n = "throwWarningLine";
            __tmp____Bah_fnNames[208].p = throwWarningLine;

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

            __tmp____Bah_fnNames[217].n = "searchVirtVarByToken";
            __tmp____Bah_fnNames[217].p = searchVirtVarByToken;

            __tmp____Bah_fnNames[218].n = "setCType";
            __tmp____Bah_fnNames[218].p = setCType;

            __tmp____Bah_fnNames[219].n = "getTypeFromToken";
            __tmp____Bah_fnNames[219].p = getTypeFromToken;

            __tmp____Bah_fnNames[220].n = "searchFuncByToken";
            __tmp____Bah_fnNames[220].p = searchFuncByToken;

            __tmp____Bah_fnNames[221].n = "RCPavailable";
            __tmp____Bah_fnNames[221].p = RCPavailable;

            __tmp____Bah_fnNames[222].n = "declareStructMethods";
            __tmp____Bah_fnNames[222].p = declareStructMethods;

            __tmp____Bah_fnNames[223].n = "genCompilerVar";
            __tmp____Bah_fnNames[223].p = genCompilerVar;

            __tmp____Bah_fnNames[224].n = "varInArr";
            __tmp____Bah_fnNames[224].p = varInArr;

            __tmp____Bah_fnNames[225].n = "pathToVarName";
            __tmp____Bah_fnNames[225].p = pathToVarName;

            __tmp____Bah_fnNames[226].n = "makeInit";
            __tmp____Bah_fnNames[226].p = makeInit;

            __tmp____Bah_fnNames[227].n = "isOutterScope";
            __tmp____Bah_fnNames[227].p = isOutterScope;

            __tmp____Bah_fnNames[228].n = "decrVar";
            __tmp____Bah_fnNames[228].p = decrVar;

            __tmp____Bah_fnNames[229].n = "incrVar";
            __tmp____Bah_fnNames[229].p = incrVar;

            __tmp____Bah_fnNames[230].n = "beginRCPscope";
            __tmp____Bah_fnNames[230].p = beginRCPscope;

            __tmp____Bah_fnNames[231].n = "beginRCPscopeLeaky";
            __tmp____Bah_fnNames[231].p = beginRCPscopeLeaky;

            __tmp____Bah_fnNames[232].n = "removeDefs";
            __tmp____Bah_fnNames[232].p = removeDefs;

            __tmp____Bah_fnNames[233].n = "endRCPscope";
            __tmp____Bah_fnNames[233].p = endRCPscope;

            __tmp____Bah_fnNames[234].n = "endRCPscopeLeaky";
            __tmp____Bah_fnNames[234].p = endRCPscopeLeaky;

            __tmp____Bah_fnNames[235].n = "registerRCPvar";
            __tmp____Bah_fnNames[235].p = registerRCPvar;

            __tmp____Bah_fnNames[236].n = "RCPselfRef";
            __tmp____Bah_fnNames[236].p = RCPselfRef;

            __tmp____Bah_fnNames[237].n = "verboseOutGuard";
            __tmp____Bah_fnNames[237].p = verboseOutGuard;

            __tmp____Bah_fnNames[238].n = "verboseOutTransformVar";
            __tmp____Bah_fnNames[238].p = verboseOutTransformVar;

            __tmp____Bah_fnNames[239].n = "verboseOutTransformTok";
            __tmp____Bah_fnNames[239].p = verboseOutTransformTok;

            __tmp____Bah_fnNames[240].n = "verboseOutFunc";
            __tmp____Bah_fnNames[240].p = verboseOutFunc;

            __tmp____Bah_fnNames[241].n = "verboseOutOper";
            __tmp____Bah_fnNames[241].p = verboseOutOper;

            __tmp____Bah_fnNames[242].n = "readCache";
            __tmp____Bah_fnNames[242].p = readCache;

            __tmp____Bah_fnNames[243].n = "getCacheFile";
            __tmp____Bah_fnNames[243].p = getCacheFile;

            __tmp____Bah_fnNames[244].n = "updateCacheFile";
            __tmp____Bah_fnNames[244].p = updateCacheFile;

            __tmp____Bah_fnNames[245].n = "makeCacheFile";
            __tmp____Bah_fnNames[245].p = makeCacheFile;

            __tmp____Bah_fnNames[246].n = "writeCache";
            __tmp____Bah_fnNames[246].p = writeCache;

            __tmp____Bah_fnNames[247].n = "isValidCacheFile";
            __tmp____Bah_fnNames[247].p = isValidCacheFile;

            __tmp____Bah_fnNames[248].n = "genArrRealloc";
            __tmp____Bah_fnNames[248].p = genArrRealloc;

            __tmp____Bah_fnNames[249].n = "OPTI_checkFuncScopeRef";
            __tmp____Bah_fnNames[249].p = OPTI_checkFuncScopeRef;

            __tmp____Bah_fnNames[250].n = "debugLine";
            __tmp____Bah_fnNames[250].p = debugLine;

            __tmp____Bah_fnNames[251].n = "dupElems";
            __tmp____Bah_fnNames[251].p = dupElems;

            __tmp____Bah_fnNames[252].n = "getLineType";
            __tmp____Bah_fnNames[252].p = getLineType;

            __tmp____Bah_fnNames[253].n = "parseCast";
            __tmp____Bah_fnNames[253].p = parseCast;

            __tmp____Bah_fnNames[254].n = "getDirFromFile";
            __tmp____Bah_fnNames[254].p = getDirFromFile;

            __tmp____Bah_fnNames[255].n = "parseLines";
            __tmp____Bah_fnNames[255].p = parseLines;

            __tmp____Bah_fnNames[256].n = "includeFile";
            __tmp____Bah_fnNames[256].p = includeFile;

            __tmp____Bah_fnNames[257].n = "parallelObjCompile";
            __tmp____Bah_fnNames[257].p = parallelObjCompile;

            __tmp____Bah_fnNames[258].n = "parseImport";
            __tmp____Bah_fnNames[258].p = parseImport;

            __tmp____Bah_fnNames[259].n = "parseInclude";
            __tmp____Bah_fnNames[259].p = parseInclude;

            __tmp____Bah_fnNames[260].n = "prePross";
            __tmp____Bah_fnNames[260].p = prePross;

            __tmp____Bah_fnNames[261].n = "parseStructType";
            __tmp____Bah_fnNames[261].p = parseStructType;

            __tmp____Bah_fnNames[262].n = "parseArrayType";
            __tmp____Bah_fnNames[262].p = parseArrayType;

            __tmp____Bah_fnNames[263].n = "parsePointers";
            __tmp____Bah_fnNames[263].p = parsePointers;

            __tmp____Bah_fnNames[264].n = "parseSerialize";
            __tmp____Bah_fnNames[264].p = parseSerialize;

            __tmp____Bah_fnNames[265].n = "parseReflect";
            __tmp____Bah_fnNames[265].p = parseReflect;

            __tmp____Bah_fnNames[266].n = "parseArrayDecl";
            __tmp____Bah_fnNames[266].p = parseArrayDecl;

            __tmp____Bah_fnNames[267].n = "parseVar";
            __tmp____Bah_fnNames[267].p = parseVar;

            __tmp____Bah_fnNames[268].n = "getCfunctionType";
            __tmp____Bah_fnNames[268].p = getCfunctionType;

            __tmp____Bah_fnNames[269].n = "parseFnHeader";
            __tmp____Bah_fnNames[269].p = parseFnHeader;

            __tmp____Bah_fnNames[270].n = "parseStruct";
            __tmp____Bah_fnNames[270].p = parseStruct;

            __tmp____Bah_fnNames[271].n = "parseDefine";
            __tmp____Bah_fnNames[271].p = parseDefine;

            __tmp____Bah_fnNames[272].n = "parseClib";
            __tmp____Bah_fnNames[272].p = parseClib;

            __tmp____Bah_fnNames[273].n = "parseConst";
            __tmp____Bah_fnNames[273].p = parseConst;

            __tmp____Bah_fnNames[274].n = "parseReturn";
            __tmp____Bah_fnNames[274].p = parseReturn;

            __tmp____Bah_fnNames[275].n = "parseIf";
            __tmp____Bah_fnNames[275].p = parseIf;

            __tmp____Bah_fnNames[276].n = "parseElse";
            __tmp____Bah_fnNames[276].p = parseElse;

            __tmp____Bah_fnNames[277].n = "parseLine";
            __tmp____Bah_fnNames[277].p = parseLine;

            __tmp____Bah_fnNames[278].n = "parseFor";
            __tmp____Bah_fnNames[278].p = parseFor;

            __tmp____Bah_fnNames[279].n = "parseForOp";
            __tmp____Bah_fnNames[279].p = parseForOp;

            __tmp____Bah_fnNames[280].n = "makeEvalFunc";
            __tmp____Bah_fnNames[280].p = makeEvalFunc;

            __tmp____Bah_fnNames[281].n = "parsePreKeyword";
            __tmp____Bah_fnNames[281].p = parsePreKeyword;

            __tmp____Bah_fnNames[282].n = "parseAsync";
            __tmp____Bah_fnNames[282].p = parseAsync;

            __tmp____Bah_fnNames[283].n = "addRCPvars";
            __tmp____Bah_fnNames[283].p = addRCPvars;

            __tmp____Bah_fnNames[284].n = "parseChan";
            __tmp____Bah_fnNames[284].p = parseChan;

            __tmp____Bah_fnNames[285].n = "valueFunc";
            __tmp____Bah_fnNames[285].p = valueFunc;

            __tmp____Bah_fnNames[286].n = "valueStruct";
            __tmp____Bah_fnNames[286].p = valueStruct;

            __tmp____Bah_fnNames[287].n = "valueArr";
            __tmp____Bah_fnNames[287].p = valueArr;

            __tmp____Bah_fnNames[288].n = "valueBool";
            __tmp____Bah_fnNames[288].p = valueBool;

            __tmp____Bah_fnNames[289].n = "valueOper";
            __tmp____Bah_fnNames[289].p = valueOper;

            __tmp____Bah_fnNames[290].n = "valueSendChan";
            __tmp____Bah_fnNames[290].p = valueSendChan;

            __tmp____Bah_fnNames[291].n = "valueChan";
            __tmp____Bah_fnNames[291].p = valueChan;

            __tmp____Bah_fnNames[292].n = "isSmallValue";
            __tmp____Bah_fnNames[292].p = isSmallValue;

            __tmp____Bah_fnNames[293].n = "isValue";
            __tmp____Bah_fnNames[293].p = isValue;

            __tmp____Bah_fnNames[294].n = "parseFnDeclare";
            __tmp____Bah_fnNames[294].p = parseFnDeclare;

            __tmp____Bah_fnNames[295].n = "declareFunc";
            __tmp____Bah_fnNames[295].p = declareFunc;

            __tmp____Bah_fnNames[296].n = "declareVar";
            __tmp____Bah_fnNames[296].p = declareVar;

            __tmp____Bah_fnNames[297].n = "declareAll";
            __tmp____Bah_fnNames[297].p = declareAll;

            __tmp____Bah_fnNames[298].n = "memErrHandle";
            __tmp____Bah_fnNames[298].p = memErrHandle;

            __tmp____Bah_fnNames[299].n = "main";
            __tmp____Bah_fnNames[299].p = main;

        __Bah_fnNames->data = __tmp____Bah_fnNames;
        __Bah_fnNames->length = 300;
        
    };
    