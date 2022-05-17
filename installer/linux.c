//COMPILE WITH: 'gcc -I "/opt/bah/libs/linux/include/" -L "/opt/bah/libs/linux/" ../installer/linux.c -static -O1 -w  -lgc -lpthread -lm'

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
#define __thread_create GC_pthread_create
#define __thread_join GC_pthread_join
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
long int backtrace(void * arr,long int l);
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
array(void *)* arr = memoryAlloc(sizeof(array(void *)));

arr->length = 0;
arr->elemSize = sizeof(void *);
allocateArray(arr,10);
long int size = backtrace(arr->data,10);
print("Backtrace:\n");
long int min = -1;
long int max = -1;
register long int i = 1;
for (; (i<size); i++) {
long int p = arr->data[i];
struct __Bah_fnName_mapper closest;
long int dist = -1;
register long int j = 0;
for (; (j<len(__Bah_fnNames)); j++) {
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
char * ____BAH_COMPILER_VAR_8 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(status);
long int strLen_1 = strlen(" \n");
long int strLen_2 = strlen("() ");
long int strLen_3 = strlen(closest.n);
long int strLen_4 = strlen("\t");
;                            
            ____BAH_COMPILER_VAR_8 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_8+currStrOff, "\t", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_8+currStrOff, closest.n, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_8+currStrOff, "() ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_8+currStrOff, status, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_8+currStrOff, " \n", strLen_1);
            currStrOff += strLen_1;
        
        }print(____BAH_COMPILER_VAR_8);
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
char * ____BAH_COMPILER_VAR_9 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("Memory error (segfault).\n");
long int strLen_1 = strlen(res);
;                            
            ____BAH_COMPILER_VAR_9 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_9+currStrOff, "Memory error (segfault).\n", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_9+currStrOff, res, strLen_1);
            currStrOff += strLen_1;
        
        }__BAH_panic(____BAH_COMPILER_VAR_9,"???");
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
char * ____BAH_COMPILER_VAR_10 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s);
long int strLen_1 = strlen("\"");
long int strLen_2 = strlen("\"");
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
struct mapElem* ____BAH_COMPILER_VAR_11 = memoryAlloc(sizeof(struct mapElem));
____BAH_COMPILER_VAR_11->key= null;
____BAH_COMPILER_VAR_11->val= null;
____BAH_COMPILER_VAR_11->key = k;
____BAH_COMPILER_VAR_11->val = e;
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
void mapWrapper__setAny(struct mapWrapper* this,char * k,void * e,long int s){
if ((this->length==0)) {
this->grow(this,50);
}
if ((this->length*2>=len(this->elems))) {
this->grow(this,this->length);
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
struct mapWrapper* ____BAH_COMPILER_VAR_13 = memoryAlloc(sizeof(struct mapWrapper));
____BAH_COMPILER_VAR_13->elems = memoryAlloc(sizeof(array(struct mapElem*)));
            ____BAH_COMPILER_VAR_13->elems->length = 0;
            ____BAH_COMPILER_VAR_13->elems->elemSize = sizeof(struct mapElem*);
            ____BAH_COMPILER_VAR_13->grow = mapWrapper__grow;
____BAH_COMPILER_VAR_13->set = mapWrapper__set;
____BAH_COMPILER_VAR_13->setAny = mapWrapper__setAny;
____BAH_COMPILER_VAR_13->delete = mapWrapper__delete;
____BAH_COMPILER_VAR_13->get = mapWrapper__get;
struct mapWrapper* m = ____BAH_COMPILER_VAR_13;
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
}
else {
while ((nDataLength>0)) {
char * ____BAH_COMPILER_VAR_15 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(response);
long int strLen_1 = strlen(buff);
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
            long int currStrOff = 0;
            long int strLen_0 = strlen(s);
long int strLen_1 = strlen("\n");
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
char * ____BAH_COMPILER_VAR_17 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(this->name);
long int strLen_1 = strlen("'.");
long int strLen_2 = strlen("iostream: warning, auto-closing file: '");
;                            
            ____BAH_COMPILER_VAR_17 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_17+currStrOff, "iostream: warning, auto-closing file: '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_17+currStrOff, this->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_17+currStrOff, "'.", strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_17);
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
this->handle = open(fileName,O_RDWR,S_IRUSR|S_IWUSR);
struct stat ____BAH_COMPILER_VAR_18 = {};
#define sb ____BAH_COMPILER_VAR_18
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
#define needle ____BAH_COMPILER_VAR_19
needle.set(&needle,nd);
struct string ____BAH_COMPILER_VAR_20 = {};
____BAH_COMPILER_VAR_20.content= null;
____BAH_COMPILER_VAR_20.set = string__set;
____BAH_COMPILER_VAR_20.makeEditable = string__makeEditable;
____BAH_COMPILER_VAR_20.append = string__append;
____BAH_COMPILER_VAR_20.prepend = string__prepend;
____BAH_COMPILER_VAR_20.charAt = string__charAt;
____BAH_COMPILER_VAR_20.compare = string__compare;
____BAH_COMPILER_VAR_20.str = string__str;
____BAH_COMPILER_VAR_20.replace = string__replace;
#define repl ____BAH_COMPILER_VAR_20
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
char * ____BAH_COMPILER_VAR_21 =null;char * ____BAH_COMPILER_VAR_22 =arrAsStr(replbuffStr);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(r);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_22);
;                            
            ____BAH_COMPILER_VAR_21 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_21+currStrOff, r, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_21+currStrOff, ____BAH_COMPILER_VAR_22, strLen_1);
            currStrOff += strLen_1;
        
        }r = ____BAH_COMPILER_VAR_21;
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
#define needle ____BAH_COMPILER_VAR_23
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
#define r ____BAH_COMPILER_VAR_24
r.length = this->length+s2.length;
r.content = memoryAlloc(r.length+1);
strncpy(r.content,this->content,this->length);
strCatOffset(r.content,this->length,s2.content,s2.length);
return r;
};
struct string string(char * s){
struct string ____BAH_COMPILER_VAR_25 = {};
____BAH_COMPILER_VAR_25.content= null;
____BAH_COMPILER_VAR_25.set = string__set;
____BAH_COMPILER_VAR_25.makeEditable = string__makeEditable;
____BAH_COMPILER_VAR_25.append = string__append;
____BAH_COMPILER_VAR_25.prepend = string__prepend;
____BAH_COMPILER_VAR_25.charAt = string__charAt;
____BAH_COMPILER_VAR_25.compare = string__compare;
____BAH_COMPILER_VAR_25.str = string__str;
____BAH_COMPILER_VAR_25.replace = string__replace;
____BAH_COMPILER_VAR_25.countChar = string__countChar;
____BAH_COMPILER_VAR_25.count = string__count;
____BAH_COMPILER_VAR_25.hasPrefix = string__hasPrefix;
____BAH_COMPILER_VAR_25.hasSuffix = string__hasSuffix;
____BAH_COMPILER_VAR_25.trim = string__trim;
____BAH_COMPILER_VAR_25.trimLeft = string__trimLeft;
____BAH_COMPILER_VAR_25.trimRight = string__trimRight;
____BAH_COMPILER_VAR_25.add = string__add;
#define a ____BAH_COMPILER_VAR_25
a.set(&a,s);
return a;
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
char * ____BAH_COMPILER_VAR_27 =intToStr(i);struct string r = string(____BAH_COMPILER_VAR_27);
return r;
};
char * floatToStr(double f){
char ____BAH_COMPILER_VAR_28[50];char* buff = ____BAH_COMPILER_VAR_28;
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
char * ____BAH_COMPILER_VAR_29 =charToString(c);replcBuff.append(&replcBuff,____BAH_COMPILER_VAR_29);
}
else {
if ((sepIndex>0)) {
sepIndex = 0;
char * ____BAH_COMPILER_VAR_30 =charToString(c);replcBuff.append(&replcBuff,____BAH_COMPILER_VAR_30);
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
struct string* ____BAH_COMPILER_VAR_31 = memoryAlloc(sizeof(struct string));
____BAH_COMPILER_VAR_31->content= null;
____BAH_COMPILER_VAR_31->set = string__set;
____BAH_COMPILER_VAR_31->makeEditable = string__makeEditable;
____BAH_COMPILER_VAR_31->append = string__append;
____BAH_COMPILER_VAR_31->prepend = string__prepend;
____BAH_COMPILER_VAR_31->charAt = string__charAt;
____BAH_COMPILER_VAR_31->compare = string__compare;
____BAH_COMPILER_VAR_31->str = string__str;
____BAH_COMPILER_VAR_31->replace = string__replace;
____BAH_COMPILER_VAR_31->countChar = string__countChar;
____BAH_COMPILER_VAR_31->count = string__count;
____BAH_COMPILER_VAR_31->hasPrefix = string__hasPrefix;
____BAH_COMPILER_VAR_31->hasSuffix = string__hasSuffix;
____BAH_COMPILER_VAR_31->trim = string__trim;
____BAH_COMPILER_VAR_31->trimLeft = string__trimLeft;
____BAH_COMPILER_VAR_31->trimRight = string__trimRight;
____BAH_COMPILER_VAR_31->add = string__add;
struct string* elem = ____BAH_COMPILER_VAR_31;
char * ____BAH_COMPILER_VAR_32 =arrToStr(tmpString);elem->set(elem,____BAH_COMPILER_VAR_32);
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
struct string* ____BAH_COMPILER_VAR_33 = memoryAlloc(sizeof(struct string));
____BAH_COMPILER_VAR_33->content= null;
____BAH_COMPILER_VAR_33->set = string__set;
____BAH_COMPILER_VAR_33->makeEditable = string__makeEditable;
____BAH_COMPILER_VAR_33->append = string__append;
____BAH_COMPILER_VAR_33->prepend = string__prepend;
____BAH_COMPILER_VAR_33->charAt = string__charAt;
____BAH_COMPILER_VAR_33->compare = string__compare;
____BAH_COMPILER_VAR_33->str = string__str;
____BAH_COMPILER_VAR_33->replace = string__replace;
____BAH_COMPILER_VAR_33->countChar = string__countChar;
____BAH_COMPILER_VAR_33->count = string__count;
____BAH_COMPILER_VAR_33->hasPrefix = string__hasPrefix;
____BAH_COMPILER_VAR_33->hasSuffix = string__hasSuffix;
____BAH_COMPILER_VAR_33->trim = string__trim;
____BAH_COMPILER_VAR_33->trimLeft = string__trimLeft;
____BAH_COMPILER_VAR_33->trimRight = string__trimRight;
____BAH_COMPILER_VAR_33->add = string__add;
struct string* elem = ____BAH_COMPILER_VAR_33;
char * ____BAH_COMPILER_VAR_34 =arrToStr(tmpString);elem->set(elem,____BAH_COMPILER_VAR_34);
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
char * ____BAH_COMPILER_VAR_35 =e.str(&e);struct string tmpS = string(____BAH_COMPILER_VAR_35);
if ((i!=max)) {
tmpS.append(&tmpS,sep);
}
char * ____BAH_COMPILER_VAR_36 =tmpS.str(&tmpS);s.append(&s,____BAH_COMPILER_VAR_36);
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
struct flag* ____BAH_COMPILER_VAR_42 = memoryAlloc(sizeof(struct flag));
____BAH_COMPILER_VAR_42->name= null;
____BAH_COMPILER_VAR_42->help= null;
____BAH_COMPILER_VAR_42->content= null;
struct flag* z = ____BAH_COMPILER_VAR_42;
z->isSet = 0;
return z;
};
char * flags__get(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_43 =string(name);struct flag* flag = this->getFlag(this,____BAH_COMPILER_VAR_43);
char * ctn = flag->content;
return ctn;
};
long int flags__getInt(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_44 =string(name);struct flag* flag = this->getFlag(this,____BAH_COMPILER_VAR_44);
if ((flag->type!=FLAG_TYPE_INT)) {
char * ____BAH_COMPILER_VAR_45 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(flag->name);
long int strLen_1 = strlen("' is not int.");
long int strLen_2 = strlen("Flag '");
;                            
            ____BAH_COMPILER_VAR_45 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_45+currStrOff, "Flag '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_45+currStrOff, flag->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_45+currStrOff, "' is not int.", strLen_1);
            currStrOff += strLen_1;
        
        }char * error = ____BAH_COMPILER_VAR_45;
__BAH_panic(error,"/opt/bah/flags.bah:124");
}
long int ctn = flag->cont_int;
return ctn;
};
double flags__getFloat(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_46 =string(name);struct flag* flag = this->getFlag(this,____BAH_COMPILER_VAR_46);
if ((flag->type!=FLAG_TYPE_FLOAT)) {
char * ____BAH_COMPILER_VAR_47 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(flag->name);
long int strLen_1 = strlen("' is not float.");
long int strLen_2 = strlen("Flag '");
;                            
            ____BAH_COMPILER_VAR_47 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_47+currStrOff, "Flag '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_47+currStrOff, flag->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_47+currStrOff, "' is not float.", strLen_1);
            currStrOff += strLen_1;
        
        }char * error = ____BAH_COMPILER_VAR_47;
__BAH_panic(error,"/opt/bah/flags.bah:136");
}
double ctn = flag->cont_float;
return ctn;
};
long int flags__isSet(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_48 =string(name);struct flag* flag = this->getFlag(this,____BAH_COMPILER_VAR_48);
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
char * ____BAH_COMPILER_VAR_49 =argName.str(&argName);currentFlag->cont_int = atoi(____BAH_COMPILER_VAR_49);
}
else if ((currentFlag->type==FLAG_TYPE_FLOAT)) {
char * ____BAH_COMPILER_VAR_50 =argName.str(&argName);currentFlag->cont_float = strtod(____BAH_COMPILER_VAR_50,0);
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
struct timespec ____BAH_COMPILER_VAR_51 = {};
#define ts ____BAH_COMPILER_VAR_51
timespec_get(&ts,TIME_UTC);
long int s = ts.tv_sec*1000000000+ts.tv_nsec;
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
struct fileStream ____BAH_COMPILER_VAR_52 = {};
____BAH_COMPILER_VAR_52.handle= null;
____BAH_COMPILER_VAR_52.name= null;
____BAH_COMPILER_VAR_52.isValid = fileStream__isValid;
____BAH_COMPILER_VAR_52.open = fileStream__open;
____BAH_COMPILER_VAR_52.close = fileStream__close;
____BAH_COMPILER_VAR_52.getPos = fileStream__getPos;
____BAH_COMPILER_VAR_52.setPos = fileStream__setPos;
____BAH_COMPILER_VAR_52.getSize = fileStream__getSize;
____BAH_COMPILER_VAR_52.rewind = fileStream__rewind;
____BAH_COMPILER_VAR_52.getChar = fileStream__getChar;
____BAH_COMPILER_VAR_52.setChar = fileStream__setChar;
____BAH_COMPILER_VAR_52.createFile = fileStream__createFile;
____BAH_COMPILER_VAR_52.writeFile = fileStream__writeFile;
____BAH_COMPILER_VAR_52.writePtr = fileStream__writePtr;
____BAH_COMPILER_VAR_52.readPtr = fileStream__readPtr;
____BAH_COMPILER_VAR_52.readContent = fileStream__readContent;
____BAH_COMPILER_VAR_52.readBytes = fileStream__readBytes;
____BAH_COMPILER_VAR_52.writeBytes = fileStream__writeBytes;
____BAH_COMPILER_VAR_52._end = fileStream___end;
#define fs ____BAH_COMPILER_VAR_52
fs.open(&fs,"/dev/urandom","r");
char c = fs.getChar(&fs);
fs.close(&fs);
long int i = (long int)c;
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
struct rope* ____BAH_COMPILER_VAR_53 = memoryAlloc(sizeof(struct rope));
____BAH_COMPILER_VAR_53->left= null;
____BAH_COMPILER_VAR_53->right= null;
____BAH_COMPILER_VAR_53->str= null;
____BAH_COMPILER_VAR_53->len = 0;
____BAH_COMPILER_VAR_53->addStr = rope__addStr;
____BAH_COMPILER_VAR_53->toStr = rope__toStr;
____BAH_COMPILER_VAR_53->add = rope__add;
struct rope* tmp = ____BAH_COMPILER_VAR_53;
tmp->left = this;
tmp->right = root2;
tmp->totalLen = this->totalLen+root2->totalLen;
tmp->str = null;
return tmp;
};
struct rope* createRopeStructure(struct rope* par,char * a,long int l,long int r){
struct rope* ____BAH_COMPILER_VAR_54 = memoryAlloc(sizeof(struct rope));
____BAH_COMPILER_VAR_54->left= null;
____BAH_COMPILER_VAR_54->right= null;
____BAH_COMPILER_VAR_54->str= null;
____BAH_COMPILER_VAR_54->len = 0;
____BAH_COMPILER_VAR_54->addStr = rope__addStr;
____BAH_COMPILER_VAR_54->toStr = rope__toStr;
____BAH_COMPILER_VAR_54->add = rope__add;
struct rope* tmp = ____BAH_COMPILER_VAR_54;
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
struct rope* ____BAH_COMPILER_VAR_55 = memoryAlloc(sizeof(struct rope));
____BAH_COMPILER_VAR_55->left= null;
____BAH_COMPILER_VAR_55->right= null;
____BAH_COMPILER_VAR_55->str= null;
____BAH_COMPILER_VAR_55->len = 0;
____BAH_COMPILER_VAR_55->addStr = rope__addStr;
____BAH_COMPILER_VAR_55->toStr = rope__toStr;
____BAH_COMPILER_VAR_55->add = rope__add;
struct rope* tmp = ____BAH_COMPILER_VAR_55;
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
char * ____BAH_COMPILER_VAR_56 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(cm);
long int strLen_1 = strlen(" 2>/dev/null");
;                            
            ____BAH_COMPILER_VAR_56 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_56+currStrOff, cm, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_56+currStrOff, " 2>/dev/null", strLen_1);
            currStrOff += strLen_1;
        
        }cm = ____BAH_COMPILER_VAR_56;
}
else {
char * ____BAH_COMPILER_VAR_57 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(cm);
long int strLen_1 = strlen(" 2>&1");
;                            
            ____BAH_COMPILER_VAR_57 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_57+currStrOff, cm, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_57+currStrOff, " 2>&1", strLen_1);
            currStrOff += strLen_1;
        
        }cm = ____BAH_COMPILER_VAR_57;
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
char * ____BAH_COMPILER_VAR_58 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(res);
long int strLen_1 = strlen(buff);
;                            
            ____BAH_COMPILER_VAR_58 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_58+currStrOff, res, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_58+currStrOff, buff, strLen_1);
            currStrOff += strLen_1;
        
        }res = ____BAH_COMPILER_VAR_58;
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
char * ____BAH_COMPILER_VAR_59 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(cm);
long int strLen_1 = strlen(" 2>/dev/null");
;                            
            ____BAH_COMPILER_VAR_59 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_59+currStrOff, cm, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_59+currStrOff, " 2>/dev/null", strLen_1);
            currStrOff += strLen_1;
        
        }cm = ____BAH_COMPILER_VAR_59;
}
else {
char * ____BAH_COMPILER_VAR_60 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(cm);
long int strLen_1 = strlen(" 2>&1");
;                            
            ____BAH_COMPILER_VAR_60 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_60+currStrOff, cm, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_60+currStrOff, " 2>&1", strLen_1);
            currStrOff += strLen_1;
        
        }cm = ____BAH_COMPILER_VAR_60;
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
char * ____BAH_COMPILER_VAR_61 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(response);
long int strLen_1 = strlen(buff);
;                            
            ____BAH_COMPILER_VAR_61 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_61+currStrOff, response, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_61+currStrOff, buff, strLen_1);
            currStrOff += strLen_1;
        
        }response = ____BAH_COMPILER_VAR_61;
res = fgets(buff,1023,this->handle);
};
this->status = pclose(this->handle);
arr->data=response;
arr->length=strlen(response);
return arr;
};
struct command command(char * s){
struct command ____BAH_COMPILER_VAR_62 = {};
____BAH_COMPILER_VAR_62.command= null;
____BAH_COMPILER_VAR_62.error = true;
____BAH_COMPILER_VAR_62.status = 0;
____BAH_COMPILER_VAR_62.input = null;
____BAH_COMPILER_VAR_62.handle= null;
____BAH_COMPILER_VAR_62.run = command__run;
____BAH_COMPILER_VAR_62.runBytes = command__runBytes;
#define cmd ____BAH_COMPILER_VAR_62
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
struct Tok ____BAH_COMPILER_VAR_63 = {};
____BAH_COMPILER_VAR_63.cont = "";
____BAH_COMPILER_VAR_63.ogCont = "";
____BAH_COMPILER_VAR_63.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_63.pos = 0;
____BAH_COMPILER_VAR_63.line = 1;
____BAH_COMPILER_VAR_63.begLine = 1;
____BAH_COMPILER_VAR_63.bahType = "";
____BAH_COMPILER_VAR_63.isValue = false;
____BAH_COMPILER_VAR_63.isFunc = false;
____BAH_COMPILER_VAR_63.isOper = false;
____BAH_COMPILER_VAR_63.isEqual = false;
____BAH_COMPILER_VAR_63.pass = false;
____BAH_COMPILER_VAR_63.bahRef= null;
#define t ____BAH_COMPILER_VAR_63
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
char * ____BAH_COMPILER_VAR_64 =null;
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
            ____BAH_COMPILER_VAR_64 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7);
            
                    memcpy(____BAH_COMPILER_VAR_64+currStrOff, "\e[1;31m[LEXER-ERROR]\e[0m ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_64+currStrOff, compilerState.currentFile, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_64+currStrOff, ":", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_64+currStrOff, lineStr, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_64+currStrOff, ":", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_64+currStrOff, posStr, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_64+currStrOff, "\n\e[0m\n", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_64+currStrOff, msg, strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_64);
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

        char ____BAH_COMPILER_VAR_65 = 0;
        for(int i=syntaxes->length-1; i!=-1;i--) {
            if (syntaxes->data[i] == c) {
                ____BAH_COMPILER_VAR_65=1;
                break;
            };
        }
        if ((____BAH_COMPILER_VAR_65==false)) {
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

        char ____BAH_COMPILER_VAR_66 = 0;
        for(int i=keywords->length-1; i!=-1;i--) {
            if (keywords->data[i] != 0 && strcmp(keywords->data[i], memstr) == 0) {
                ____BAH_COMPILER_VAR_66=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_66) {
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
char * ____BAH_COMPILER_VAR_67 =splitStringBefore(n,".");struct string res = string(____BAH_COMPILER_VAR_67);
return res;
}
if (n.count(&n,"->")) {
char * ____BAH_COMPILER_VAR_68 =splitStringBefore(n,"->");struct string res = string(____BAH_COMPILER_VAR_68);
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
struct structMemb* ____BAH_COMPILER_VAR_69 = memoryAlloc(sizeof(struct structMemb));
____BAH_COMPILER_VAR_69->name = "";
____BAH_COMPILER_VAR_69->type = "";
____BAH_COMPILER_VAR_69->isConst = false;
____BAH_COMPILER_VAR_69->constVal = "";
____BAH_COMPILER_VAR_69->isArray = false;
____BAH_COMPILER_VAR_69->from = "";
____BAH_COMPILER_VAR_69->declScope= null;
____BAH_COMPILER_VAR_69->isGlobal = false;
____BAH_COMPILER_VAR_69->declRope= null;
____BAH_COMPILER_VAR_69->isReg = false;
____BAH_COMPILER_VAR_69->def = "";
____BAH_COMPILER_VAR_69->isFn = false;
struct structMemb* sm = ____BAH_COMPILER_VAR_69;
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
char * ____BAH_COMPILER_VAR_70 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("__");
long int strLen_1 = strlen(name);
long int strLen_2 = strlen(s->name);
;                            
            ____BAH_COMPILER_VAR_70 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_70+currStrOff, s->name, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_70+currStrOff, "__", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_70+currStrOff, name, strLen_1);
            currStrOff += strLen_1;
        
        }struct func* fn = searchFunc(____BAH_COMPILER_VAR_70,elems,true);
if ((fn!=null)) {
return fn;
}
register long int i = 0;
for (; (i<len(s->members)); i++) {
if ((strcmp(s->members->data[i]->name, name) == 0)) {
struct string ____BAH_COMPILER_VAR_71 =string(s->members->data[i]->type);fn = parseFnType(____BAH_COMPILER_VAR_71);
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
char * ____BAH_COMPILER_VAR_72 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t);
long int strLen_1 = strlen(")*");
long int strLen_2 = strlen("array(");
;                            
            ____BAH_COMPILER_VAR_72 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_72+currStrOff, "array(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_72+currStrOff, t, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_72+currStrOff, ")*", strLen_1);
            currStrOff += strLen_1;
        
        }char * r = ____BAH_COMPILER_VAR_72;
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

        char ____BAH_COMPILER_VAR_73 = 0;
        for(int i=intTypes->length-1; i!=-1;i--) {
            if (intTypes->data[i] != 0 && strcmp(intTypes->data[i], a) == 0) {
                ____BAH_COMPILER_VAR_73=1;
                break;
            };
        }
        
        char ____BAH_COMPILER_VAR_74 = 0;
        for(int i=intTypes->length-1; i!=-1;i--) {
            if (intTypes->data[i] != 0 && strcmp(intTypes->data[i], b) == 0) {
                ____BAH_COMPILER_VAR_74=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_73&&____BAH_COMPILER_VAR_74) {
return true;
}

        char ____BAH_COMPILER_VAR_75 = 0;
        for(int i=floatTypes->length-1; i!=-1;i--) {
            if (floatTypes->data[i] != 0 && strcmp(floatTypes->data[i], a) == 0) {
                ____BAH_COMPILER_VAR_75=1;
                break;
            };
        }
        
        char ____BAH_COMPILER_VAR_76 = 0;
        for(int i=floatTypes->length-1; i!=-1;i--) {
            if (floatTypes->data[i] != 0 && strcmp(floatTypes->data[i], b) == 0) {
                ____BAH_COMPILER_VAR_76=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_75&&____BAH_COMPILER_VAR_76) {
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
struct reflectElement ____BAH_COMPILER_VAR_77 = {};
____BAH_COMPILER_VAR_77.type= null;
____BAH_COMPILER_VAR_77.name= null;
____BAH_COMPILER_VAR_77.arrayElem= null;
____BAH_COMPILER_VAR_77.structLayout = memoryAlloc(sizeof(array(struct reflectElement)));
            ____BAH_COMPILER_VAR_77.structLayout->length = 0;
            ____BAH_COMPILER_VAR_77.structLayout->elemSize = sizeof(struct reflectElement);
            ____BAH_COMPILER_VAR_77.value= null;
____BAH_COMPILER_VAR_77.calculateOffset = reflectElement__calculateOffset;
#define re ____BAH_COMPILER_VAR_77
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
struct reflectElement ____BAH_COMPILER_VAR_78 = {};
____BAH_COMPILER_VAR_78.type= null;
____BAH_COMPILER_VAR_78.name= null;
____BAH_COMPILER_VAR_78.arrayElem= null;
____BAH_COMPILER_VAR_78.structLayout = memoryAlloc(sizeof(array(struct reflectElement)));
            ____BAH_COMPILER_VAR_78.structLayout->length = 0;
            ____BAH_COMPILER_VAR_78.structLayout->elemSize = sizeof(struct reflectElement);
            ____BAH_COMPILER_VAR_78.value= null;
____BAH_COMPILER_VAR_78.calculateOffset = reflectElement__calculateOffset;
#define ns ____BAH_COMPILER_VAR_78
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
char * ____BAH_COMPILER_VAR_79 =k.str(&k);mapWrapper__set(*p,____BAH_COMPILER_VAR_79,v);
}
else {
char * ____BAH_COMPILER_VAR_80 =k.str(&k);mapWrapper__set(*p,____BAH_COMPILER_VAR_80,&v);
}
};
}
};
struct jsonElement* parseJson(char * s){
struct jsonElement* ____BAH_COMPILER_VAR_81 = memoryAlloc(sizeof(struct jsonElement));
____BAH_COMPILER_VAR_81->key= null;
____BAH_COMPILER_VAR_81->content= null;
____BAH_COMPILER_VAR_81->children = memoryAlloc(sizeof(array(struct jsonElement*)));
            ____BAH_COMPILER_VAR_81->children->length = 0;
            ____BAH_COMPILER_VAR_81->children->elemSize = sizeof(struct jsonElement*);
            ____BAH_COMPILER_VAR_81->get = jsonElement__get;
____BAH_COMPILER_VAR_81->str = jsonElement__str;
____BAH_COMPILER_VAR_81->scan = jsonElement__scan;
struct jsonElement* jsonElem = ____BAH_COMPILER_VAR_81;
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
char * ____BAH_COMPILER_VAR_82 =arrToStr(currentElem);struct jsonElement* child = parseJson(____BAH_COMPILER_VAR_82);
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
char * ____BAH_COMPILER_VAR_83 =arrToStr(currentElem);struct jsonElement* child = parseJson(____BAH_COMPILER_VAR_83);
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
char * ____BAH_COMPILER_VAR_84 =arrToStr(currentElem);struct jsonElement* elem = parseJson(____BAH_COMPILER_VAR_84);
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
char * ____BAH_COMPILER_VAR_85 =arrToStr(currentElem);struct jsonElement* elem = parseJson(____BAH_COMPILER_VAR_85);
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
char * ____BAH_COMPILER_VAR_86 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tabsStr);
long int strLen_1 = strlen("\t");
;                            
            ____BAH_COMPILER_VAR_86 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_86+currStrOff, tabsStr, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_86+currStrOff, "\t", strLen_1);
            currStrOff += strLen_1;
        
        }tabsStr = ____BAH_COMPILER_VAR_86;
i = i+1;
};
char * s = "{\n";
i = 0;
while ((i<len(e.structLayout))) {
struct reflectElement m = e.structLayout->data[i];
i = i+1;
if ((i<len(e.structLayout))) {
char * ____BAH_COMPILER_VAR_87 =null;char * ____BAH_COMPILER_VAR_88 =toJson__inner(m,true,tabs);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_88);
long int strLen_1 = strlen(",\n");
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
        
            memcpy(____BAH_COMPILER_VAR_87+currStrOff, ",\n", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_87;
}
else {
char * ____BAH_COMPILER_VAR_89 =null;char * ____BAH_COMPILER_VAR_90 =toJson__inner(m,true,tabs);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_90);
long int strLen_1 = strlen("\n");
long int strLen_2 = strlen("\": ");
long int strLen_3 = strlen(m.name);
long int strLen_4 = strlen("\"");
long int strLen_5 = strlen(tabsStr);
long int strLen_6 = strlen(s);
;                            
            ____BAH_COMPILER_VAR_89 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_89+currStrOff, s, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_89+currStrOff, tabsStr, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_89+currStrOff, "\"", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_89+currStrOff, m.name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_89+currStrOff, "\": ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_89+currStrOff, ____BAH_COMPILER_VAR_90, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_89+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_89;
}
};
tabs = tabs-1;
tabsStr = "";
i = 0;
while ((i<tabs)) {
char * ____BAH_COMPILER_VAR_91 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tabsStr);
long int strLen_1 = strlen("\t");
;                            
            ____BAH_COMPILER_VAR_91 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_91+currStrOff, tabsStr, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_91+currStrOff, "\t", strLen_1);
            currStrOff += strLen_1;
        
        }tabsStr = ____BAH_COMPILER_VAR_91;
i = i+1;
};
char * ____BAH_COMPILER_VAR_92 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tabsStr);
long int strLen_1 = strlen("}");
long int strLen_2 = strlen(s);
;                            
            ____BAH_COMPILER_VAR_92 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_92+currStrOff, s, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_92+currStrOff, tabsStr, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_92+currStrOff, "}", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_92;
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
else {
char ** sp = e.value;
char * s = *sp;
char * ____BAH_COMPILER_VAR_95 =null;char * ____BAH_COMPILER_VAR_96 =jsonEscapeStr(s);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_96);
long int strLen_1 = strlen("\"");
long int strLen_2 = strlen("\"");
;                            
            ____BAH_COMPILER_VAR_95 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_95+currStrOff, "\"", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_95+currStrOff, ____BAH_COMPILER_VAR_96, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_95+currStrOff, "\"", strLen_1);
            currStrOff += strLen_1;
        
        }return ____BAH_COMPILER_VAR_95;
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
char * ____BAH_COMPILER_VAR_97 =null;char * ____BAH_COMPILER_VAR_98 =intToStr(arr->data[i]);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_98);
;                            
            ____BAH_COMPILER_VAR_97 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_97+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_97+currStrOff, ____BAH_COMPILER_VAR_98, strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_97;
i = i+1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_99 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s);
long int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_99 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_99+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_99+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_99;
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
char * ____BAH_COMPILER_VAR_100 =null;char * ____BAH_COMPILER_VAR_101 =floatToStr(arr->data[i]);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_101);
;                            
            ____BAH_COMPILER_VAR_100 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_100+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_100+currStrOff, ____BAH_COMPILER_VAR_101, strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_100;
i = i+1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_102 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s);
long int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_102 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_102+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_102+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_102;
}
};
}
else if ((strcmp(ae->type, "cpstring") == 0)) {
array(char *)* arr = memoryAlloc(sizeof(array(char *)));

arr->length = 0;
arr->elemSize = sizeof(char *);
void ** arrPtr = e.value;
arr = *arrPtr;
char * ____BAH_COMPILER_VAR_103 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s);
long int strLen_1 = strlen("\n");
;                            
            ____BAH_COMPILER_VAR_103 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_103+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_103+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_103;
register long int i = 0;
while ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_104 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s);
long int strLen_1 = strlen(arr->data[i]);
;                            
            ____BAH_COMPILER_VAR_104 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_104+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_104+currStrOff, arr->data[i], strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_104;
i = i+1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_105 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s);
long int strLen_1 = strlen(",\n");
;                            
            ____BAH_COMPILER_VAR_105 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_105+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_105+currStrOff, ",\n", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_105;
}
else {
char * ____BAH_COMPILER_VAR_106 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s);
long int strLen_1 = strlen("\n");
;                            
            ____BAH_COMPILER_VAR_106 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_106+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_106+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_106;
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
char * ____BAH_COMPILER_VAR_107 =null;char * ____BAH_COMPILER_VAR_108 =toJson__inner(*ae,false,tabs);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_108);
;                            
            ____BAH_COMPILER_VAR_107 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_107+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_107+currStrOff, ____BAH_COMPILER_VAR_108, strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_107;
i = i+1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_109 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s);
long int strLen_1 = strlen(",\n");
;                            
            ____BAH_COMPILER_VAR_109 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_109+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_109+currStrOff, ",\n", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_109;
}
else {
char * ____BAH_COMPILER_VAR_110 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s);
long int strLen_1 = strlen("\n");
;                            
            ____BAH_COMPILER_VAR_110 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_110+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_110+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_110;
}
};
}
char * ____BAH_COMPILER_VAR_111 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s);
long int strLen_1 = strlen("]");
;                            
            ____BAH_COMPILER_VAR_111 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_111+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_111+currStrOff, "]", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_111;
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
char * ____BAH_COMPILER_VAR_112 = name;
struct reflectElement ____BAH_COMPILER_VAR_113 = __reflect(____BAH_COMPILER_VAR_112, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, 0);
char * ____BAH_COMPILER_VAR_114 =null;char * ____BAH_COMPILER_VAR_115 =toJson(e);char * ____BAH_COMPILER_VAR_116 =intToStr(line);char * ____BAH_COMPILER_VAR_117 =toJson(____BAH_COMPILER_VAR_113);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_115);
long int strLen_1 = strlen("\n    },\n    ");
long int strLen_2 = strlen("\",\n        \"element\": ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_116);
long int strLen_4 = strlen(":");
long int strLen_5 = strlen(compilerState.currentFile);
long int strLen_6 = strlen(",\n        \"path\": \"");
long int strLen_7 = strlen(____BAH_COMPILER_VAR_117);
long int strLen_8 = strlen("\n    {\n        \"name\": ");
;                            
            ____BAH_COMPILER_VAR_114 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_114+currStrOff, "\n    {\n        \"name\": ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_114+currStrOff, ____BAH_COMPILER_VAR_117, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_114+currStrOff, ",\n        \"path\": \"", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_114+currStrOff, compilerState.currentFile, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_114+currStrOff, ":", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_114+currStrOff, ____BAH_COMPILER_VAR_116, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_114+currStrOff, "\",\n        \"element\": ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_114+currStrOff, ____BAH_COMPILER_VAR_115, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_114+currStrOff, "\n    },\n    ", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_118 =____BAH_COMPILER_VAR_114;println(____BAH_COMPILER_VAR_118);
};
void debugError(char * name,long int line,long int from,long int to,struct reflectElement e){
if ((debug==false)) {
return;
}
char * ____BAH_COMPILER_VAR_119 = name;
struct reflectElement ____BAH_COMPILER_VAR_120 = __reflect(____BAH_COMPILER_VAR_119, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, 0);
char * ____BAH_COMPILER_VAR_121 =null;char * ____BAH_COMPILER_VAR_122 =toJson(e);char * ____BAH_COMPILER_VAR_123 =intToStr(to);char * ____BAH_COMPILER_VAR_124 =intToStr(from);char * ____BAH_COMPILER_VAR_125 =intToStr(line);char * ____BAH_COMPILER_VAR_126 =toJson(____BAH_COMPILER_VAR_120);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_122);
long int strLen_1 = strlen("\n    },\n    ");
long int strLen_2 = strlen("\n        ],\n        \"element\": ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_123);
long int strLen_4 = strlen(",\n            ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_124);
long int strLen_6 = strlen("\",\n        \"range\": [\n            ");
long int strLen_7 = strlen(____BAH_COMPILER_VAR_125);
long int strLen_8 = strlen(":");
long int strLen_9 = strlen(compilerState.currentFile);
long int strLen_10 = strlen(",\n        \"path\": \"");
long int strLen_11 = strlen(____BAH_COMPILER_VAR_126);
long int strLen_12 = strlen("\n    {\n        \"name\": ");
;                            
            ____BAH_COMPILER_VAR_121 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12);
            
                    memcpy(____BAH_COMPILER_VAR_121+currStrOff, "\n    {\n        \"name\": ", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_121+currStrOff, ____BAH_COMPILER_VAR_126, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_121+currStrOff, ",\n        \"path\": \"", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_121+currStrOff, compilerState.currentFile, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_121+currStrOff, ":", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_121+currStrOff, ____BAH_COMPILER_VAR_125, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_121+currStrOff, "\",\n        \"range\": [\n            ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_121+currStrOff, ____BAH_COMPILER_VAR_124, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_121+currStrOff, ",\n            ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_121+currStrOff, ____BAH_COMPILER_VAR_123, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_121+currStrOff, "\n        ],\n        \"element\": ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_121+currStrOff, ____BAH_COMPILER_VAR_122, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_121+currStrOff, "\n    },\n    ", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_127 =____BAH_COMPILER_VAR_121;println(____BAH_COMPILER_VAR_127);
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
long int* ____BAH_COMPILER_VAR_154 = (long int*)((char*)(____BAH_COMPILER_VAR_146) + offsetof(struct rope, lCount));
struct reflectElement ____BAH_COMPILER_VAR_155 = __reflect(____BAH_COMPILER_VAR_154, sizeof(long int), "int", "lCount", 0, 0, 0, 0, offsetof(struct rope, lCount));
long int* ____BAH_COMPILER_VAR_156 = (long int*)((char*)(____BAH_COMPILER_VAR_146) + offsetof(struct rope, len));
struct reflectElement ____BAH_COMPILER_VAR_157 = __reflect(____BAH_COMPILER_VAR_156, sizeof(long int), "int", "len", 0, 0, 0, 0, offsetof(struct rope, len));
long int* ____BAH_COMPILER_VAR_158 = (long int*)((char*)(____BAH_COMPILER_VAR_146) + offsetof(struct rope, totalLen));
struct reflectElement ____BAH_COMPILER_VAR_159 = __reflect(____BAH_COMPILER_VAR_158, sizeof(long int), "int", "totalLen", 0, 0, 0, 0, offsetof(struct rope, totalLen));

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
char* ____BAH_COMPILER_VAR_161 = (char*)((char*)(____BAH_COMPILER_VAR_128) + offsetof(struct variable, canBeReg));
struct reflectElement ____BAH_COMPILER_VAR_162 = __reflect(____BAH_COMPILER_VAR_161, sizeof(char), "bool", "canBeReg", 0, 0, 0, 0, offsetof(struct variable, canBeReg));
char* ____BAH_COMPILER_VAR_163 = (char*)((char*)(____BAH_COMPILER_VAR_128) + offsetof(struct variable, isReg));
struct reflectElement ____BAH_COMPILER_VAR_164 = __reflect(____BAH_COMPILER_VAR_163, sizeof(char), "bool", "isReg", 0, 0, 0, 0, offsetof(struct variable, isReg));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_129 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_129->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_129->length = 11;
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
struct reflectElement ____BAH_COMPILER_VAR_165 = __reflect(____BAH_COMPILER_VAR_128, sizeof(struct variable), "variable*", "v", 0, 0, 1, ____BAH_COMPILER_VAR_129, 0);
debugPrint("var_end",line,____BAH_COMPILER_VAR_165);
}
i = i+1;
};
};
void throwErr(void * tp,char * format){
char * str = "";
char * info = "";
long int pos = 0;
if ((tp!=null)) {
struct fileMap ____BAH_COMPILER_VAR_166 = {};
____BAH_COMPILER_VAR_166.handle = -1;
____BAH_COMPILER_VAR_166.p= null;
____BAH_COMPILER_VAR_166.open = fileMap__open;
____BAH_COMPILER_VAR_166.isValid = fileMap__isValid;
____BAH_COMPILER_VAR_166.close = fileMap__close;
#define fm ____BAH_COMPILER_VAR_166
char * fileSrcStr = fm.open(&fm,compilerState.currentFile);
struct Tok* t = tp;
struct string ffmt = string(format);
if ((strlen(t->ogCont)==0)) {
t->ogCont = t->cont;
}
char * ____BAH_COMPILER_VAR_167 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t->ogCont);
long int strLen_1 = strlen("'");
long int strLen_2 = strlen("'");
;                            
            ____BAH_COMPILER_VAR_167 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_167+currStrOff, "'", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_167+currStrOff, t->ogCont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_167+currStrOff, "'", strLen_1);
            currStrOff += strLen_1;
        
        }ffmt.replace(&ffmt,"{TOKEN}",____BAH_COMPILER_VAR_167);
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
char * ____BAH_COMPILER_VAR_168 =null;char * ____BAH_COMPILER_VAR_169 =arrToStr(errCont);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_169);
long int strLen_1 = strlen("\e[1;37m");
long int strLen_2 = strlen("\e[1;31m");
;                            
            ____BAH_COMPILER_VAR_168 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_168+currStrOff, "\e[1;31m", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_168+currStrOff, ____BAH_COMPILER_VAR_169, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_168+currStrOff, "\e[1;37m", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_170 =____BAH_COMPILER_VAR_168;array(char)* errTk = strToArr(____BAH_COMPILER_VAR_170);
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
char * ____BAH_COMPILER_VAR_171 =null;char * ____BAH_COMPILER_VAR_172 =intToStr(pos);char * ____BAH_COMPILER_VAR_173 =intToStr(t->line);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(":");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_172);
long int strLen_2 = strlen(____BAH_COMPILER_VAR_173);
;                            
            ____BAH_COMPILER_VAR_171 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_171+currStrOff, ____BAH_COMPILER_VAR_173, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_171+currStrOff, ":", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_171+currStrOff, ____BAH_COMPILER_VAR_172, strLen_1);
            currStrOff += strLen_1;
        
        }info = ____BAH_COMPILER_VAR_171;

#undef fm
}
if ((debug==true)) {
struct Tok* t = tp;
char * ____BAH_COMPILER_VAR_174 = format;
struct reflectElement ____BAH_COMPILER_VAR_175 = __reflect(____BAH_COMPILER_VAR_174, sizeof(char *), "cpstring", "format", 0, 0, 0, 0, 0);
debugError("error",t->line,pos,pos+strlen(t->ogCont),____BAH_COMPILER_VAR_175);
debugExit();
}
else {
char * ____BAH_COMPILER_VAR_176 =null;
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
            ____BAH_COMPILER_VAR_176 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7);
            
                    memcpy(____BAH_COMPILER_VAR_176+currStrOff, "\e[1;31m[ERROR]\e[0m ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_176+currStrOff, compilerState.currentFile, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_176+currStrOff, ":", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_176+currStrOff, info, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_176+currStrOff, "\n\e[1;37m\t", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_176+currStrOff, str, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_176+currStrOff, "\e[0m\n", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_176+currStrOff, format, strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_176);
}
exit(1);
};
void throwWarning(char * s){
char * ____BAH_COMPILER_VAR_177 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s);
long int strLen_1 = strlen("\e[0m");
long int strLen_2 = strlen("\n\e[1;37m\t");
long int strLen_3 = strlen(compilerState.currentFile);
long int strLen_4 = strlen("\e[1;33m[WARNING]\e[0m ");
;                            
            ____BAH_COMPILER_VAR_177 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_177+currStrOff, "\e[1;33m[WARNING]\e[0m ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_177+currStrOff, compilerState.currentFile, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_177+currStrOff, "\n\e[1;37m\t", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_177+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_177+currStrOff, "\e[0m", strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_177);
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
struct variable* ____BAH_COMPILER_VAR_178 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_178->name = "";
____BAH_COMPILER_VAR_178->type = "";
____BAH_COMPILER_VAR_178->isConst = false;
____BAH_COMPILER_VAR_178->constVal = "";
____BAH_COMPILER_VAR_178->isArray = false;
____BAH_COMPILER_VAR_178->from = "";
____BAH_COMPILER_VAR_178->declScope= null;
____BAH_COMPILER_VAR_178->isGlobal = false;
____BAH_COMPILER_VAR_178->declRope= null;
____BAH_COMPILER_VAR_178->isReg = false;
struct variable* nv = ____BAH_COMPILER_VAR_178;
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
struct variable* ____BAH_COMPILER_VAR_179 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_179->name = "";
____BAH_COMPILER_VAR_179->type = "";
____BAH_COMPILER_VAR_179->isConst = false;
____BAH_COMPILER_VAR_179->constVal = "";
____BAH_COMPILER_VAR_179->isArray = false;
____BAH_COMPILER_VAR_179->from = "";
____BAH_COMPILER_VAR_179->declScope= null;
____BAH_COMPILER_VAR_179->isGlobal = false;
____BAH_COMPILER_VAR_179->declRope= null;
____BAH_COMPILER_VAR_179->isReg = false;
struct variable* nv = ____BAH_COMPILER_VAR_179;
nv->from = memb->from;
nv->name = memb->name;
nv->type = memb->type;
nv->declScope = v->declScope;
nv->name = ogName;
char * r = nv->type;
struct string tcc = string(ogName);
if (tcc.count(&tcc,"&")) {
char * ____BAH_COMPILER_VAR_180 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(r);
long int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_180 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_180+currStrOff, r, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_180+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }r = ____BAH_COMPILER_VAR_180;
}
long int nbUnaries = tcc.count(&tcc,"*");
if ((nbUnaries>0)) {
struct string ct = string(r);
long int pointerLevel = ct.count(&ct,"*");
if ((pointerLevel<nbUnaries)) {
char * ____BAH_COMPILER_VAR_181 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nv->name);
long int strLen_1 = strlen(" because it is not pointer.");
long int strLen_2 = strlen("Cannot use '*' on ");
;                            
            ____BAH_COMPILER_VAR_181 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_181+currStrOff, "Cannot use '*' on ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_181+currStrOff, nv->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_181+currStrOff, " because it is not pointer.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(null,____BAH_COMPILER_VAR_181);
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
struct variable* ____BAH_COMPILER_VAR_182 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_182->name = "";
____BAH_COMPILER_VAR_182->type = "";
____BAH_COMPILER_VAR_182->isConst = false;
____BAH_COMPILER_VAR_182->constVal = "";
____BAH_COMPILER_VAR_182->isArray = false;
____BAH_COMPILER_VAR_182->from = "";
____BAH_COMPILER_VAR_182->declScope= null;
____BAH_COMPILER_VAR_182->isGlobal = false;
____BAH_COMPILER_VAR_182->declRope= null;
____BAH_COMPILER_VAR_182->isReg = false;
struct variable* nv = ____BAH_COMPILER_VAR_182;
nv->type = v->type;
nv->name = v->name;
nv->isConst = v->isConst;
nv->constVal = v->constVal;
nv->declScope = v->declScope;
char * r = nv->type;
struct string tcc = string(ogName);
if (tcc.count(&tcc,"&")) {
char * ____BAH_COMPILER_VAR_183 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(r);
long int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_183 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_183+currStrOff, r, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_183+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }r = ____BAH_COMPILER_VAR_183;
}
long int nbUnaries = tcc.count(&tcc,"*");
if ((nbUnaries>0)) {
struct string ct = string(r);
long int pointerLevel = ct.count(&ct,"*");
if ((pointerLevel<nbUnaries)) {
char * ____BAH_COMPILER_VAR_184 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen(" because it is not pointer.");
long int strLen_2 = strlen("Cannot use '*' on ");
;                            
            ____BAH_COMPILER_VAR_184 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_184+currStrOff, "Cannot use '*' on ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_184+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_184+currStrOff, " because it is not pointer.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(null,____BAH_COMPILER_VAR_184);
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
struct variable* nv = ____BAH_COMPILER_VAR_185;
nv->name = name;
nv->type = "function(";
register long int j = 0;
while ((j<len(fn->args))) {
struct variable* arg = fn->args->data[j];
char * ____BAH_COMPILER_VAR_186 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nv->type);
long int strLen_1 = strlen(arg->type);
;                            
            ____BAH_COMPILER_VAR_186 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_186+currStrOff, nv->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_186+currStrOff, arg->type, strLen_1);
            currStrOff += strLen_1;
        
        }nv->type = ____BAH_COMPILER_VAR_186;
j = j+1;
if ((j<len(fn->args))) {
char * ____BAH_COMPILER_VAR_187 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nv->type);
long int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_187 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_187+currStrOff, nv->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_187+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }nv->type = ____BAH_COMPILER_VAR_187;
}
};
fn->used = true;
char * ____BAH_COMPILER_VAR_188 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(")");
long int strLen_1 = strlen(fn->returns->type);
long int strLen_2 = strlen(nv->type);
;                            
            ____BAH_COMPILER_VAR_188 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_188+currStrOff, nv->type, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_188+currStrOff, ")", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_188+currStrOff, fn->returns->type, strLen_1);
            currStrOff += strLen_1;
        
        }nv->type = ____BAH_COMPILER_VAR_188;
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
char * ____BAH_COMPILER_VAR_189 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(" ");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(t);
;                            
            ____BAH_COMPILER_VAR_189 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_189+currStrOff, t, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_189+currStrOff, " ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_189+currStrOff, v->name, strLen_1);
            currStrOff += strLen_1;
        
        }t = ____BAH_COMPILER_VAR_189;
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
struct func* ____BAH_COMPILER_VAR_190 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_190->name = "";
____BAH_COMPILER_VAR_190->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_190->args->length = 0;
            ____BAH_COMPILER_VAR_190->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_190->returns= null;
____BAH_COMPILER_VAR_190->isBinding = false;
____BAH_COMPILER_VAR_190->from = "";
____BAH_COMPILER_VAR_190->file = "";
____BAH_COMPILER_VAR_190->line = 1;
____BAH_COMPILER_VAR_190->used = false;
____BAH_COMPILER_VAR_190->code = null;
struct func* nf = ____BAH_COMPILER_VAR_190;
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
____BAH_COMPILER_VAR_191->isReg = false;
struct variable* arg = ____BAH_COMPILER_VAR_191;
char * ____BAH_COMPILER_VAR_192 =null;char * ____BAH_COMPILER_VAR_193 =intToStr(len(nf->args));
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("arg_");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_193);
;                            
            ____BAH_COMPILER_VAR_192 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_192+currStrOff, "arg_", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_192+currStrOff, ____BAH_COMPILER_VAR_193, strLen_1);
            currStrOff += strLen_1;
        
        }arg->name = ____BAH_COMPILER_VAR_192;
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
____BAH_COMPILER_VAR_194->isReg = false;
nf->returns = ____BAH_COMPILER_VAR_194;
nf->returns->name = "_return";
nf->returns->type = arrToStr(memory);
return nf;
};
struct func* searchFunc(char * name,struct Elems* elems,char inclCurr){
char * ogName = name;
if ((strcmp(name, "noCheck") == 0)) {
struct func* ____BAH_COMPILER_VAR_195 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_195->name = "";
____BAH_COMPILER_VAR_195->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_195->args->length = 0;
            ____BAH_COMPILER_VAR_195->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_195->returns= null;
____BAH_COMPILER_VAR_195->isBinding = false;
____BAH_COMPILER_VAR_195->from = "";
____BAH_COMPILER_VAR_195->file = "";
____BAH_COMPILER_VAR_195->line = 1;
____BAH_COMPILER_VAR_195->used = false;
____BAH_COMPILER_VAR_195->code = null;
struct func* fn = ____BAH_COMPILER_VAR_195;
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
char * ____BAH_COMPILER_VAR_196 =fnName.str(&fnName);struct structMemb* memb = searchStructMemb(____BAH_COMPILER_VAR_196,s,elems);
name = fnName.content;
char * ____BAH_COMPILER_VAR_197 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("__");
long int strLen_1 = strlen(name);
long int strLen_2 = strlen(memb->from);
;                            
            ____BAH_COMPILER_VAR_197 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_197+currStrOff, memb->from, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_197+currStrOff, "__", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_197+currStrOff, name, strLen_1);
            currStrOff += strLen_1;
        
        }name = ____BAH_COMPILER_VAR_197;
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
____BAH_COMPILER_VAR_198->used = false;
____BAH_COMPILER_VAR_198->code = null;
struct func* nf = ____BAH_COMPILER_VAR_198;
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
struct string ____BAH_COMPILER_VAR_199 =string(t.cont);char * fnName = splitStringBefore(____BAH_COMPILER_VAR_199,"(");
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
char * ____BAH_COMPILER_VAR_200 =null;
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
            ____BAH_COMPILER_VAR_200 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_200+currStrOff, code, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_200+currStrOff, v->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_200+currStrOff, sep, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_200+currStrOff, m->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_200+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_200+currStrOff, m->def, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_200+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_200;
declared = true;
}
if ((cmpt.hasPrefix(&cmpt,"[]")==1)) {
cmpt.trimLeft(&cmpt,2);
char * cmptstr = cmpt.str(&cmpt);
struct string elemCType = getCType(cmptstr,elems);
char * elemCTypeStr = elemCType.str(&elemCType);
char * ____BAH_COMPILER_VAR_201 =null;
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
            ____BAH_COMPILER_VAR_201 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13+strLen_14+strLen_15+strLen_16);
            
                    memcpy(____BAH_COMPILER_VAR_201+currStrOff, code, strLen_16);
                    currStrOff += strLen_16;
                    
                    memcpy(____BAH_COMPILER_VAR_201+currStrOff, v->name, strLen_15);
                    currStrOff += strLen_15;
                    
                    memcpy(____BAH_COMPILER_VAR_201+currStrOff, sep, strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_201+currStrOff, m->name, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_201+currStrOff, " = memoryAlloc(sizeof(array(", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_201+currStrOff, elemCTypeStr, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_201+currStrOff, ")));\n            ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_201+currStrOff, v->name, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_201+currStrOff, sep, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_201+currStrOff, m->name, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_201+currStrOff, "->length = 0;\n            ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_201+currStrOff, v->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_201+currStrOff, sep, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_201+currStrOff, m->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_201+currStrOff, "->elemSize = sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_201+currStrOff, elemCTypeStr, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_201+currStrOff, ");\n            ", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_201;
declared = true;
}
else if ((cmpt.hasPrefix(&cmpt,"map:")==1)) {
cmpt.trimLeft(&cmpt,4);
char * ____BAH_COMPILER_VAR_202 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(m->name);
long int strLen_1 = strlen(" = mapWrapper();\n");
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
        
            memcpy(____BAH_COMPILER_VAR_202+currStrOff, " = mapWrapper();\n", strLen_1);
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
else if ((cmpt.hasPrefix(&cmpt,"chan:")==1)) {
cmpt.trimLeft(&cmpt,5);
char * ____BAH_COMPILER_VAR_204 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(m->name);
long int strLen_1 = strlen(" = channel();\n");
long int strLen_2 = strlen(sep);
long int strLen_3 = strlen(v->name);
;                            
            ____BAH_COMPILER_VAR_204 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_204+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_204+currStrOff, sep, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_204+currStrOff, m->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_204+currStrOff, " = channel();\n", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_205 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_204);
;                            
            ____BAH_COMPILER_VAR_205 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_205+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_205+currStrOff, ____BAH_COMPILER_VAR_204, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_205;
declared = true;
}
if (isRCPpointerType(m->type)&&(declared==false)) {
char * ____BAH_COMPILER_VAR_206 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(m->name);
long int strLen_1 = strlen("= null;\n");
long int strLen_2 = strlen(sep);
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen(code);
;                            
            ____BAH_COMPILER_VAR_206 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_206+currStrOff, code, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_206+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_206+currStrOff, sep, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_206+currStrOff, m->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_206+currStrOff, "= null;\n", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_206;
}
i = i+1;
};
if ((strlen(s->extendedFrom)>0)) {
struct cStruct* es = searchStruct(s->extendedFrom,elems);
i = 0;
while ((i<len(es->methods))) {
struct func* m = es->methods->data[i];
char * ____BAH_COMPILER_VAR_207 =null;
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
            ____BAH_COMPILER_VAR_207 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_207+currStrOff, code, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_207+currStrOff, v->name, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_207+currStrOff, sep, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_207+currStrOff, m->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_207+currStrOff, " = ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_207+currStrOff, es->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_207+currStrOff, "__", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_207+currStrOff, m->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_207+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_207;
i = i+1;
};
}
array(struct func*)* methods = s->methods;
i = 0;
while ((i<len(methods))) {
struct func* m = methods->data[i];
char * ____BAH_COMPILER_VAR_208 =null;
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
            ____BAH_COMPILER_VAR_208 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_208+currStrOff, code, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_208+currStrOff, v->name, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_208+currStrOff, sep, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_208+currStrOff, m->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_208+currStrOff, " = ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_208+currStrOff, s->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_208+currStrOff, "__", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_208+currStrOff, m->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_208+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_208;
i = i+1;
};
if ((s->isBinding==false)) {
long int found = 0;
i = 0;
for (; (i<len(s->methods)); i++) {
struct func* m = s->methods->data[i];
if ((strcmp(m->name, "_init") == 0)) {
char * ____BAH_COMPILER_VAR_209 =null;
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
            ____BAH_COMPILER_VAR_209 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_209+currStrOff, v->name, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_209+currStrOff, sep, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_209+currStrOff, m->name, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_209+currStrOff, "(", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_209+currStrOff, amp, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_209+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_209+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_210 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(NEXT_LINE);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_209);
;                            
            ____BAH_COMPILER_VAR_210 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_210+currStrOff, NEXT_LINE, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_210+currStrOff, ____BAH_COMPILER_VAR_209, strLen_1);
            currStrOff += strLen_1;
        
        }NEXT_LINE = ____BAH_COMPILER_VAR_210;
found++;
}
else if ((strcmp(m->name, "_end") == 0)) {
if ((strcmp(sep, "->") == 0)) {
char * ____BAH_COMPILER_VAR_211 =null;
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
            ____BAH_COMPILER_VAR_211 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_211+currStrOff, "memoryOnEnd(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_211+currStrOff, v->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_211+currStrOff, ", ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_211+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_211+currStrOff, sep, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_211+currStrOff, m->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_211+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_212 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_211);
;                            
            ____BAH_COMPILER_VAR_212 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_212+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_212+currStrOff, ____BAH_COMPILER_VAR_211, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_212;
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
char * ____BAH_COMPILER_VAR_213 =null;char * ____BAH_COMPILER_VAR_214 =intToStr(NB_COMP_VAR);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("____BAH_COMPILER_VAR_");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_214);
;                            
            ____BAH_COMPILER_VAR_213 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_213+currStrOff, "____BAH_COMPILER_VAR_", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_213+currStrOff, ____BAH_COMPILER_VAR_214, strLen_1);
            currStrOff += strLen_1;
        
        }char * name = ____BAH_COMPILER_VAR_213;
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
char * ____BAH_COMPILER_VAR_215 =null;char * ____BAH_COMPILER_VAR_216 =pathToVarName(compilerState.currentFile);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(name);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_216);
;                            
            ____BAH_COMPILER_VAR_215 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_215+currStrOff, name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_215+currStrOff, ____BAH_COMPILER_VAR_216, strLen_1);
            currStrOff += strLen_1;
        
        }name = ____BAH_COMPILER_VAR_215;
}
char * evals = "";
char * ____BAH_COMPILER_VAR_217 =null;char * ____BAH_COMPILER_VAR_218 =intToStr(len(compilerState.evals));
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_218);
long int strLen_1 = strlen("] = {");
long int strLen_2 = strlen("volatile struct __eval_binding __tmp__evals_bindings[");
;                            
            ____BAH_COMPILER_VAR_217 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_217+currStrOff, "volatile struct __eval_binding __tmp__evals_bindings[", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_217+currStrOff, ____BAH_COMPILER_VAR_218, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_217+currStrOff, "] = {", strLen_1);
            currStrOff += strLen_1;
        
        }char * evalsTMPDecl = ____BAH_COMPILER_VAR_217;
register long int i = 0;
for (; (i<len(compilerState.evals)); i++) {
char * e = compilerState.evals->data[i];
char * ____BAH_COMPILER_VAR_219 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(e);
long int strLen_1 = strlen("\n        }");
long int strLen_2 = strlen("\",\n            .evalFn = __Bah_eval_");
long int strLen_3 = strlen(e);
long int strLen_4 = strlen("{\n            .name = \"");
;                            
            ____BAH_COMPILER_VAR_219 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_219+currStrOff, "{\n            .name = \"", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_219+currStrOff, e, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_219+currStrOff, "\",\n            .evalFn = __Bah_eval_", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_219+currStrOff, e, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_219+currStrOff, "\n        }", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_220 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(evalsTMPDecl);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_219);
;                            
            ____BAH_COMPILER_VAR_220 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_220+currStrOff, evalsTMPDecl, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_220+currStrOff, ____BAH_COMPILER_VAR_219, strLen_1);
            currStrOff += strLen_1;
        
        }evalsTMPDecl = ____BAH_COMPILER_VAR_220;
if ((i+1!=len(compilerState.evals))) {
char * ____BAH_COMPILER_VAR_221 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(evalsTMPDecl);
long int strLen_1 = strlen(",\n");
;                            
            ____BAH_COMPILER_VAR_221 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_221+currStrOff, evalsTMPDecl, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_221+currStrOff, ",\n", strLen_1);
            currStrOff += strLen_1;
        
        }evalsTMPDecl = ____BAH_COMPILER_VAR_221;
}
else {
char * ____BAH_COMPILER_VAR_222 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(evalsTMPDecl);
long int strLen_1 = strlen("};");
;                            
            ____BAH_COMPILER_VAR_222 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_222+currStrOff, evalsTMPDecl, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_222+currStrOff, "};", strLen_1);
            currStrOff += strLen_1;
        
        }evalsTMPDecl = ____BAH_COMPILER_VAR_222;
}
};
if ((len(compilerState.evals)!=0)) {
char * ____BAH_COMPILER_VAR_223 =null;char * ____BAH_COMPILER_VAR_224 =intToStr(len(compilerState.evals));
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_224);
long int strLen_1 = strlen(";");
long int strLen_2 = strlen("__evals_bindings = __tmp__evals_bindings; __evals_length = ");
;                            
            ____BAH_COMPILER_VAR_223 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_223+currStrOff, "__evals_bindings = __tmp__evals_bindings; __evals_length = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_223+currStrOff, ____BAH_COMPILER_VAR_224, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_223+currStrOff, ";", strLen_1);
            currStrOff += strLen_1;
        
        }evals = ____BAH_COMPILER_VAR_223;
}
else {
evalsTMPDecl = "";
}
char * ____BAH_COMPILER_VAR_225 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(name);
long int strLen_1 = strlen("() {\n        ");
long int strLen_2 = strlen("\n    void __attribute__((optimize(\"O0\"))) ");
long int strLen_3 = strlen(evalsTMPDecl);
long int strLen_4 = strlen("\n    ");
;                            
            ____BAH_COMPILER_VAR_225 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_225+currStrOff, "\n    ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_225+currStrOff, evalsTMPDecl, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_225+currStrOff, "\n    void __attribute__((optimize(\"O0\"))) ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_225+currStrOff, name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_225+currStrOff, "() {\n        ", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_226 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(evals);
long int strLen_1 = strlen("\n    };\n    ");
long int strLen_2 = strlen("\n        ");
;                            
            ____BAH_COMPILER_VAR_226 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_226+currStrOff, "\n        ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_226+currStrOff, evals, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_226+currStrOff, "\n    };\n    ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_225)->add(rope(____BAH_COMPILER_VAR_225), INIT->add(INIT, rope(____BAH_COMPILER_VAR_226))));
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
char * ____BAH_COMPILER_VAR_227 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen(");\n");
long int strLen_2 = strlen("RCP_decr(");
;                            
            ____BAH_COMPILER_VAR_227 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_227+currStrOff, "RCP_decr(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_227+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_227+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }r = r->add(r, rope(____BAH_COMPILER_VAR_227));
}
else if (strHasPrefix(v->type,"chan:")) {
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
if (strHasPrefix(v->type,"map:")) {
struct variable* ____BAH_COMPILER_VAR_229 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_229->name = "";
____BAH_COMPILER_VAR_229->type = "";
____BAH_COMPILER_VAR_229->isConst = false;
____BAH_COMPILER_VAR_229->constVal = "";
____BAH_COMPILER_VAR_229->isArray = false;
____BAH_COMPILER_VAR_229->from = "";
____BAH_COMPILER_VAR_229->declScope= null;
____BAH_COMPILER_VAR_229->isGlobal = false;
____BAH_COMPILER_VAR_229->declRope= null;
____BAH_COMPILER_VAR_229->isReg = false;
struct variable* nv = ____BAH_COMPILER_VAR_229;
*nv = *v;
v = nv;
v->type = "mapWrapper*";
}
char isPointer = isRCPpointerType(v->type);
struct cStruct* s = searchStruct(v->type,elems);
if ((s!=null)&&(s->isBinding==false)) {
if ((isPointer==true)) {
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
else {
char * ____BAH_COMPILER_VAR_231 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen("), 1);\n");
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
        
            memcpy(____BAH_COMPILER_VAR_231+currStrOff, "), 1);\n", strLen_1);
            currStrOff += strLen_1;
        
        }r = r->add(r, rope(____BAH_COMPILER_VAR_231));
}
}
else if ((isPointer==true)) {
char * ____BAH_COMPILER_VAR_232 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen(");\n");
long int strLen_2 = strlen("RCP_decr(");
;                            
            ____BAH_COMPILER_VAR_232 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_232+currStrOff, "RCP_decr(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_232+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_232+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }r = r->add(r, rope(____BAH_COMPILER_VAR_232));
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
char * ____BAH_COMPILER_VAR_233 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen("), 0);");
long int strLen_2 = strlen(", sizeof(");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen("RCP_scanStack(&");
;                            
            ____BAH_COMPILER_VAR_233 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_233+currStrOff, "RCP_scanStack(&", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_233+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_233+currStrOff, ", sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_233+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_233+currStrOff, "), 0);", strLen_1);
            currStrOff += strLen_1;
        
        }return rope(____BAH_COMPILER_VAR_233);
}
char * ____BAH_COMPILER_VAR_234 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen(");");
long int strLen_2 = strlen("RCP_incr(");
;                            
            ____BAH_COMPILER_VAR_234 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_234+currStrOff, "RCP_incr(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_234+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_234+currStrOff, ");", strLen_1);
            currStrOff += strLen_1;
        
        }return rope(____BAH_COMPILER_VAR_234);
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
char * ____BAH_COMPILER_VAR_235 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(elems->defined->data[i]);
long int strLen_1 = strlen("\n");
long int strLen_2 = strlen("\n#undef ");
;                            
            ____BAH_COMPILER_VAR_235 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_235+currStrOff, "\n#undef ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_235+currStrOff, elems->defined->data[i], strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_235+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_235));
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
struct variable* ____BAH_COMPILER_VAR_236 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_236->name = "";
____BAH_COMPILER_VAR_236->type = "";
____BAH_COMPILER_VAR_236->isConst = false;
____BAH_COMPILER_VAR_236->constVal = "";
____BAH_COMPILER_VAR_236->isArray = false;
____BAH_COMPILER_VAR_236->from = "";
____BAH_COMPILER_VAR_236->declScope= null;
____BAH_COMPILER_VAR_236->isGlobal = false;
____BAH_COMPILER_VAR_236->declRope= null;
____BAH_COMPILER_VAR_236->isReg = false;
struct variable* av = ____BAH_COMPILER_VAR_236;
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
char * ____BAH_COMPILER_VAR_237 =null;char * ____BAH_COMPILER_VAR_238 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(c);
long int strLen_1 = strlen(";");
long int strLen_2 = strlen(" =");
long int strLen_3 = strlen(av->name);
long int strLen_4 = strlen(" ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_238);
;                            
            ____BAH_COMPILER_VAR_237 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_237+currStrOff, ____BAH_COMPILER_VAR_238, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_237+currStrOff, " ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_237+currStrOff, av->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_237+currStrOff, " =", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_237+currStrOff, c, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_237+currStrOff, ";", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_237));
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

        char ____BAH_COMPILER_VAR_239 = 0;
        for(int i=noVOfns->length-1; i!=-1;i--) {
            if (noVOfns->data[i] != 0 && strcmp(noVOfns->data[i], currentFn->name) == 0) {
                ____BAH_COMPILER_VAR_239=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_239) {
return false;
}
}
return true;
};
struct verboseOutVar verboseOutTransformVar(struct variable* v,char * cont,struct Elems* elems){
struct verboseOutVar ____BAH_COMPILER_VAR_240 = {};
____BAH_COMPILER_VAR_240.markup= null;
____BAH_COMPILER_VAR_240.content= null;
#define rv ____BAH_COMPILER_VAR_240
char * ogCont = cont;
if ((strcmp(v->type, "cpstring") == 0)) {
char * ____BAH_COMPILER_VAR_241 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(cont);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen("__Bah_safe_string(");
;                            
            ____BAH_COMPILER_VAR_241 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_241+currStrOff, "__Bah_safe_string(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_241+currStrOff, cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_241+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }cont = ____BAH_COMPILER_VAR_241;
}
char * ____BAH_COMPILER_VAR_242 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(", ");
long int strLen_1 = strlen(cont);
;                            
            ____BAH_COMPILER_VAR_242 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_242+currStrOff, ", ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_242+currStrOff, cont, strLen_1);
            currStrOff += strLen_1;
        
        }cont = ____BAH_COMPILER_VAR_242;
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
char * ____BAH_COMPILER_VAR_243 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ASCII_RESET);
long int strLen_1 = strlen("{");
;                            
            ____BAH_COMPILER_VAR_243 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_243+currStrOff, ASCII_RESET, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_243+currStrOff, "{", strLen_1);
            currStrOff += strLen_1;
        
        }ct = ____BAH_COMPILER_VAR_243;
cont = "";
register long int i = 0;
for (; (i<len(s->members)); i++) {
struct variable* m = s->members->data[i];
char * ____BAH_COMPILER_VAR_244 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(".");
long int strLen_1 = strlen(m->name);
long int strLen_2 = strlen(")");
long int strLen_3 = strlen(ogCont);
long int strLen_4 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_244 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_244+currStrOff, "(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_244+currStrOff, ogCont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_244+currStrOff, ")", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_244+currStrOff, ".", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_244+currStrOff, m->name, strLen_1);
            currStrOff += strLen_1;
        
        }struct verboseOutVar mv = verboseOutTransformVar(m,____BAH_COMPILER_VAR_244,elems);
if ((i!=0)) {
char * ____BAH_COMPILER_VAR_245 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ct);
long int strLen_1 = strlen(", ");
;                            
            ____BAH_COMPILER_VAR_245 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_245+currStrOff, ct, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_245+currStrOff, ", ", strLen_1);
            currStrOff += strLen_1;
        
        }ct = ____BAH_COMPILER_VAR_245;
}
char * ____BAH_COMPILER_VAR_246 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ct);
long int strLen_1 = strlen(mv.markup);
;                            
            ____BAH_COMPILER_VAR_246 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_246+currStrOff, ct, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_246+currStrOff, mv.markup, strLen_1);
            currStrOff += strLen_1;
        
        }ct = ____BAH_COMPILER_VAR_246;
char * ____BAH_COMPILER_VAR_247 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(cont);
long int strLen_1 = strlen(mv.content);
;                            
            ____BAH_COMPILER_VAR_247 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_247+currStrOff, cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_247+currStrOff, mv.content, strLen_1);
            currStrOff += strLen_1;
        
        }cont = ____BAH_COMPILER_VAR_247;
};
char * ____BAH_COMPILER_VAR_248 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ct);
long int strLen_1 = strlen("}");
;                            
            ____BAH_COMPILER_VAR_248 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_248+currStrOff, ct, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_248+currStrOff, "}", strLen_1);
            currStrOff += strLen_1;
        
        }ct = ____BAH_COMPILER_VAR_248;
}
}
char * ____BAH_COMPILER_VAR_249 =null;
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
            ____BAH_COMPILER_VAR_249 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_249+currStrOff, ASCII_BLUE, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_249+currStrOff, v->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_249+currStrOff, ASCII_RESET, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_249+currStrOff, " = ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_249+currStrOff, ASCII_MAGENTA, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_249+currStrOff, ct, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_249+currStrOff, ASCII_RESET, strLen_1);
            currStrOff += strLen_1;
        
        }rv.markup = ____BAH_COMPILER_VAR_249;
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
struct variable ____BAH_COMPILER_VAR_250 = {};
____BAH_COMPILER_VAR_250.name = "";
____BAH_COMPILER_VAR_250.type = "";
____BAH_COMPILER_VAR_250.isConst = false;
____BAH_COMPILER_VAR_250.constVal = "";
____BAH_COMPILER_VAR_250.isArray = false;
____BAH_COMPILER_VAR_250.from = "";
____BAH_COMPILER_VAR_250.declScope= null;
____BAH_COMPILER_VAR_250.isGlobal = false;
____BAH_COMPILER_VAR_250.declRope= null;
____BAH_COMPILER_VAR_250.isReg = false;
____BAH_COMPILER_VAR_250.name = "(value)";
____BAH_COMPILER_VAR_250.type = getTypeFromToken(&t,true,elems);
#define v ____BAH_COMPILER_VAR_250
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
char * ____BAH_COMPILER_VAR_251 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnArgs);
long int strLen_1 = strlen(", ");
;                            
            ____BAH_COMPILER_VAR_251 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_251+currStrOff, fnArgs, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_251+currStrOff, ", ", strLen_1);
            currStrOff += strLen_1;
        
        }fnArgs = ____BAH_COMPILER_VAR_251;
}
struct Tok t = args->data[j];
struct verboseOutVar v = verboseOutTransformVar(a,t.cont,elems);
char * ____BAH_COMPILER_VAR_252 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnArgs);
long int strLen_1 = strlen(v.markup);
;                            
            ____BAH_COMPILER_VAR_252 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_252+currStrOff, fnArgs, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_252+currStrOff, v.markup, strLen_1);
            currStrOff += strLen_1;
        
        }fnArgs = ____BAH_COMPILER_VAR_252;
char * ____BAH_COMPILER_VAR_253 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnArgsValues);
long int strLen_1 = strlen(v.content);
;                            
            ____BAH_COMPILER_VAR_253 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_253+currStrOff, fnArgsValues, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_253+currStrOff, v.content, strLen_1);
            currStrOff += strLen_1;
        
        }fnArgsValues = ____BAH_COMPILER_VAR_253;
};
char * ____BAH_COMPILER_VAR_254 =null;char * ____BAH_COMPILER_VAR_255 =intToStr(lineNb);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(":");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_255);
long int strLen_2 = strlen(compilerState.currentFile);
;                            
            ____BAH_COMPILER_VAR_254 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_254+currStrOff, compilerState.currentFile, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_254+currStrOff, ":", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_254+currStrOff, ____BAH_COMPILER_VAR_255, strLen_1);
            currStrOff += strLen_1;
        
        }char * line = ____BAH_COMPILER_VAR_254;
char * ____BAH_COMPILER_VAR_256 =null;
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
            ____BAH_COMPILER_VAR_256 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12);
            
                    memcpy(____BAH_COMPILER_VAR_256+currStrOff, "\n    //Verbose Runtime\n        printf(\"[VO] calling: ", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_256+currStrOff, nameColor, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_256+currStrOff, fn->name, strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_256+currStrOff, ASCII_RESET, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_256+currStrOff, "(", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_256+currStrOff, fnArgs, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_256+currStrOff, ") -> ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_256+currStrOff, ASCII_GREEN, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_256+currStrOff, line, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_256+currStrOff, ASCII_RESET, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_256+currStrOff, "\\n\"", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_256+currStrOff, fnArgsValues, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_256+currStrOff, ");\n    //\n    ", strLen_1);
            currStrOff += strLen_1;
        
        }struct rope* verboseOut = rope(____BAH_COMPILER_VAR_256);
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
char * ____BAH_COMPILER_VAR_257 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(pvo.content);
long int strLen_1 = strlen(nvo.content);
;                            
            ____BAH_COMPILER_VAR_257 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_257+currStrOff, pvo.content, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_257+currStrOff, nvo.content, strLen_1);
            currStrOff += strLen_1;
        
        }char * values = ____BAH_COMPILER_VAR_257;
char * ____BAH_COMPILER_VAR_258 =null;char * ____BAH_COMPILER_VAR_259 =intToStr(lineNb);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(":");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_259);
long int strLen_2 = strlen(compilerState.currentFile);
;                            
            ____BAH_COMPILER_VAR_258 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_258+currStrOff, compilerState.currentFile, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_258+currStrOff, ":", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_258+currStrOff, ____BAH_COMPILER_VAR_259, strLen_1);
            currStrOff += strLen_1;
        
        }char * line = ____BAH_COMPILER_VAR_258;
char * ____BAH_COMPILER_VAR_260 =null;
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
            ____BAH_COMPILER_VAR_260 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10);
            
                    memcpy(____BAH_COMPILER_VAR_260+currStrOff, "\n    //Verbose Runtime\n        printf(\"[VO]    oper: ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_260+currStrOff, pvo.markup, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_260+currStrOff, " AND ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_260+currStrOff, nvo.markup, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_260+currStrOff, " -> ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_260+currStrOff, ASCII_GREEN, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_260+currStrOff, line, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_260+currStrOff, ASCII_RESET, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_260+currStrOff, "\\n\"", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_260+currStrOff, values, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_260+currStrOff, ");\n    //\n    ", strLen_1);
            currStrOff += strLen_1;
        
        }struct rope* verboseOut = rope(____BAH_COMPILER_VAR_260);
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
struct fileStream ____BAH_COMPILER_VAR_261 = {};
____BAH_COMPILER_VAR_261.handle= null;
____BAH_COMPILER_VAR_261.name= null;
____BAH_COMPILER_VAR_261.isValid = fileStream__isValid;
____BAH_COMPILER_VAR_261.open = fileStream__open;
____BAH_COMPILER_VAR_261.close = fileStream__close;
____BAH_COMPILER_VAR_261.getPos = fileStream__getPos;
____BAH_COMPILER_VAR_261.setPos = fileStream__setPos;
____BAH_COMPILER_VAR_261.getSize = fileStream__getSize;
____BAH_COMPILER_VAR_261.rewind = fileStream__rewind;
____BAH_COMPILER_VAR_261.getChar = fileStream__getChar;
____BAH_COMPILER_VAR_261.setChar = fileStream__setChar;
____BAH_COMPILER_VAR_261.createFile = fileStream__createFile;
____BAH_COMPILER_VAR_261.writeFile = fileStream__writeFile;
____BAH_COMPILER_VAR_261.writePtr = fileStream__writePtr;
____BAH_COMPILER_VAR_261.readPtr = fileStream__readPtr;
____BAH_COMPILER_VAR_261.readContent = fileStream__readContent;
____BAH_COMPILER_VAR_261.readBytes = fileStream__readBytes;
____BAH_COMPILER_VAR_261.writeBytes = fileStream__writeBytes;
____BAH_COMPILER_VAR_261._end = fileStream___end;
#define fs ____BAH_COMPILER_VAR_261
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
        
        }fs.open(&fs,____BAH_COMPILER_VAR_262,"r");
if ((fs.isValid(&fs)==0)) {
char * ____BAH_COMPILER_VAR_263 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen("cache");
;                            
            ____BAH_COMPILER_VAR_263 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_263+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_263+currStrOff, "cache", strLen_1);
            currStrOff += strLen_1;
        
        }mkdir(____BAH_COMPILER_VAR_263,S_IRWXU);
char * ____BAH_COMPILER_VAR_264 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen("cache/cache.json");
;                            
            ____BAH_COMPILER_VAR_264 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_264+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_264+currStrOff, "cache/cache.json", strLen_1);
            currStrOff += strLen_1;
        
        }fs.createFile(&fs,____BAH_COMPILER_VAR_264);
return;
}
char * ____BAH_COMPILER_VAR_265 =fs.readContent(&fs);struct jsonElement* j = parseJson(____BAH_COMPILER_VAR_265);
fs.close(&fs);
array(struct cacheFile**)* ____BAH_COMPILER_VAR_266 = &cache;
struct cacheFile*** ____BAH_COMPILER_VAR_267 = 0;
char ** ____BAH_COMPILER_VAR_269 = (char **)((char*)(____BAH_COMPILER_VAR_267) + offsetof(struct cacheFile, file));
struct reflectElement ____BAH_COMPILER_VAR_270 = __reflect(____BAH_COMPILER_VAR_269, sizeof(char *), "cpstring", "file", 0, 0, 0, 0, offsetof(struct cacheFile, file));
long int* ____BAH_COMPILER_VAR_271 = (long int*)((char*)(____BAH_COMPILER_VAR_267) + offsetof(struct cacheFile, last));
struct reflectElement ____BAH_COMPILER_VAR_272 = __reflect(____BAH_COMPILER_VAR_271, sizeof(long int), "int", "last", 0, 0, 0, 0, offsetof(struct cacheFile, last));
char ** ____BAH_COMPILER_VAR_273 = (char **)((char*)(____BAH_COMPILER_VAR_267) + offsetof(struct cacheFile, ver));
struct reflectElement ____BAH_COMPILER_VAR_274 = __reflect(____BAH_COMPILER_VAR_273, sizeof(char *), "cpstring", "ver", 0, 0, 0, 0, offsetof(struct cacheFile, ver));
long int* ____BAH_COMPILER_VAR_275 = (long int*)((char*)(____BAH_COMPILER_VAR_267) + offsetof(struct cacheFile, date));
struct reflectElement ____BAH_COMPILER_VAR_276 = __reflect(____BAH_COMPILER_VAR_275, sizeof(long int), "int", "date", 0, 0, 0, 0, offsetof(struct cacheFile, date));
long int* ____BAH_COMPILER_VAR_277 = (long int*)((char*)(____BAH_COMPILER_VAR_267) + offsetof(struct cacheFile, mem));
struct reflectElement ____BAH_COMPILER_VAR_278 = __reflect(____BAH_COMPILER_VAR_277, sizeof(long int), "int", "mem", 0, 0, 0, 0, offsetof(struct cacheFile, mem));
array(char *)** ____BAH_COMPILER_VAR_279 = (array(char *)**)((char*)(____BAH_COMPILER_VAR_267) + offsetof(struct cacheFile, files));
char ** ____BAH_COMPILER_VAR_280 = 0;
struct reflectElement ____BAH_COMPILER_VAR_281 = __reflect(____BAH_COMPILER_VAR_280, sizeof(char *), "cpstring", "", 0, 0, 0, 0, 0);

        struct reflectElement ____BAH_COMPILER_VAR_282 = ____BAH_COMPILER_VAR_281;
        struct reflectElement ____BAH_COMPILER_VAR_283 = __reflect(____BAH_COMPILER_VAR_279, sizeof(array(char *)*), "[]cpstring", "files", 1, &____BAH_COMPILER_VAR_282, 0, 0, offsetof(struct cacheFile, files));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_268 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_268->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_268->length = 6;
        ____BAH_COMPILER_VAR_268->data = memoryAlloc(____BAH_COMPILER_VAR_268->length * ____BAH_COMPILER_VAR_268->elemSize);
        ____BAH_COMPILER_VAR_268->data[0] = ____BAH_COMPILER_VAR_270;
____BAH_COMPILER_VAR_268->data[1] = ____BAH_COMPILER_VAR_272;
____BAH_COMPILER_VAR_268->data[2] = ____BAH_COMPILER_VAR_274;
____BAH_COMPILER_VAR_268->data[3] = ____BAH_COMPILER_VAR_276;
____BAH_COMPILER_VAR_268->data[4] = ____BAH_COMPILER_VAR_278;
____BAH_COMPILER_VAR_268->data[5] = ____BAH_COMPILER_VAR_283;
struct reflectElement ____BAH_COMPILER_VAR_284 = __reflect(____BAH_COMPILER_VAR_267, sizeof(struct cacheFile), "cacheFile**", "", 0, 0, 1, ____BAH_COMPILER_VAR_268, 0);

        struct reflectElement ____BAH_COMPILER_VAR_285 = ____BAH_COMPILER_VAR_284;
        struct reflectElement ____BAH_COMPILER_VAR_286 = __reflect(____BAH_COMPILER_VAR_266, sizeof(array(struct cacheFile**)*), "[]cacheFile**", "&cache", 1, &____BAH_COMPILER_VAR_285, 0, 0, 0);
j->scan(j,____BAH_COMPILER_VAR_286);
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
struct cacheFile* ____BAH_COMPILER_VAR_287 = memoryAlloc(sizeof(struct cacheFile));
____BAH_COMPILER_VAR_287->file= null;
____BAH_COMPILER_VAR_287->ver= null;
____BAH_COMPILER_VAR_287->files = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_287->files->length = 0;
            ____BAH_COMPILER_VAR_287->files->elemSize = sizeof(char *);
            struct cacheFile* c = ____BAH_COMPILER_VAR_287;
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
struct fileStream ____BAH_COMPILER_VAR_288 = {};
____BAH_COMPILER_VAR_288.handle= null;
____BAH_COMPILER_VAR_288.name= null;
____BAH_COMPILER_VAR_288.isValid = fileStream__isValid;
____BAH_COMPILER_VAR_288.open = fileStream__open;
____BAH_COMPILER_VAR_288.close = fileStream__close;
____BAH_COMPILER_VAR_288.getPos = fileStream__getPos;
____BAH_COMPILER_VAR_288.setPos = fileStream__setPos;
____BAH_COMPILER_VAR_288.getSize = fileStream__getSize;
____BAH_COMPILER_VAR_288.rewind = fileStream__rewind;
____BAH_COMPILER_VAR_288.getChar = fileStream__getChar;
____BAH_COMPILER_VAR_288.setChar = fileStream__setChar;
____BAH_COMPILER_VAR_288.createFile = fileStream__createFile;
____BAH_COMPILER_VAR_288.writeFile = fileStream__writeFile;
____BAH_COMPILER_VAR_288.writePtr = fileStream__writePtr;
____BAH_COMPILER_VAR_288.readPtr = fileStream__readPtr;
____BAH_COMPILER_VAR_288.readContent = fileStream__readContent;
____BAH_COMPILER_VAR_288.readBytes = fileStream__readBytes;
____BAH_COMPILER_VAR_288.writeBytes = fileStream__writeBytes;
____BAH_COMPILER_VAR_288._end = fileStream___end;
#define fs ____BAH_COMPILER_VAR_288
char * ____BAH_COMPILER_VAR_289 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen("cache/cache.json");
;                            
            ____BAH_COMPILER_VAR_289 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_289+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_289+currStrOff, "cache/cache.json", strLen_1);
            currStrOff += strLen_1;
        
        }fs.open(&fs,____BAH_COMPILER_VAR_289,"w");
array(struct cacheFile*)* ____BAH_COMPILER_VAR_290 = cache;
struct cacheFile** ____BAH_COMPILER_VAR_291 = 0;
char ** ____BAH_COMPILER_VAR_293 = (char **)((char*)(____BAH_COMPILER_VAR_291) + offsetof(struct cacheFile, file));
struct reflectElement ____BAH_COMPILER_VAR_294 = __reflect(____BAH_COMPILER_VAR_293, sizeof(char *), "cpstring", "file", 0, 0, 0, 0, offsetof(struct cacheFile, file));
long int* ____BAH_COMPILER_VAR_295 = (long int*)((char*)(____BAH_COMPILER_VAR_291) + offsetof(struct cacheFile, last));
struct reflectElement ____BAH_COMPILER_VAR_296 = __reflect(____BAH_COMPILER_VAR_295, sizeof(long int), "int", "last", 0, 0, 0, 0, offsetof(struct cacheFile, last));
char ** ____BAH_COMPILER_VAR_297 = (char **)((char*)(____BAH_COMPILER_VAR_291) + offsetof(struct cacheFile, ver));
struct reflectElement ____BAH_COMPILER_VAR_298 = __reflect(____BAH_COMPILER_VAR_297, sizeof(char *), "cpstring", "ver", 0, 0, 0, 0, offsetof(struct cacheFile, ver));
long int* ____BAH_COMPILER_VAR_299 = (long int*)((char*)(____BAH_COMPILER_VAR_291) + offsetof(struct cacheFile, date));
struct reflectElement ____BAH_COMPILER_VAR_300 = __reflect(____BAH_COMPILER_VAR_299, sizeof(long int), "int", "date", 0, 0, 0, 0, offsetof(struct cacheFile, date));
long int* ____BAH_COMPILER_VAR_301 = (long int*)((char*)(____BAH_COMPILER_VAR_291) + offsetof(struct cacheFile, mem));
struct reflectElement ____BAH_COMPILER_VAR_302 = __reflect(____BAH_COMPILER_VAR_301, sizeof(long int), "int", "mem", 0, 0, 0, 0, offsetof(struct cacheFile, mem));
array(char *)** ____BAH_COMPILER_VAR_303 = (array(char *)**)((char*)(____BAH_COMPILER_VAR_291) + offsetof(struct cacheFile, files));
char ** ____BAH_COMPILER_VAR_304 = 0;
struct reflectElement ____BAH_COMPILER_VAR_305 = __reflect(____BAH_COMPILER_VAR_304, sizeof(char *), "cpstring", "", 0, 0, 0, 0, 0);

        struct reflectElement ____BAH_COMPILER_VAR_306 = ____BAH_COMPILER_VAR_305;
        struct reflectElement ____BAH_COMPILER_VAR_307 = __reflect(____BAH_COMPILER_VAR_303, sizeof(array(char *)*), "[]cpstring", "files", 1, &____BAH_COMPILER_VAR_306, 0, 0, offsetof(struct cacheFile, files));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_292 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_292->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_292->length = 6;
        ____BAH_COMPILER_VAR_292->data = memoryAlloc(____BAH_COMPILER_VAR_292->length * ____BAH_COMPILER_VAR_292->elemSize);
        ____BAH_COMPILER_VAR_292->data[0] = ____BAH_COMPILER_VAR_294;
____BAH_COMPILER_VAR_292->data[1] = ____BAH_COMPILER_VAR_296;
____BAH_COMPILER_VAR_292->data[2] = ____BAH_COMPILER_VAR_298;
____BAH_COMPILER_VAR_292->data[3] = ____BAH_COMPILER_VAR_300;
____BAH_COMPILER_VAR_292->data[4] = ____BAH_COMPILER_VAR_302;
____BAH_COMPILER_VAR_292->data[5] = ____BAH_COMPILER_VAR_307;
struct reflectElement ____BAH_COMPILER_VAR_308 = __reflect(____BAH_COMPILER_VAR_291, sizeof(struct cacheFile), "cacheFile*", "", 0, 0, 1, ____BAH_COMPILER_VAR_292, 0);

        struct reflectElement ____BAH_COMPILER_VAR_309 = ____BAH_COMPILER_VAR_308;
        struct reflectElement ____BAH_COMPILER_VAR_310 = __reflect(____BAH_COMPILER_VAR_290, sizeof(array(struct cacheFile*)*), "[]cacheFile*", "cache", 1, &____BAH_COMPILER_VAR_309, 0, 0, 0);
char * ____BAH_COMPILER_VAR_311 =toJson(____BAH_COMPILER_VAR_310);fs.writeFile(&fs,____BAH_COMPILER_VAR_311);
fs.close(&fs);

#undef fs
};
char isValidCacheFile(struct cacheFile* cf){
if ((cf==null)||(cf->last!=getLastModified(cf->file))) {
return false;
}
char * ____BAH_COMPILER_VAR_312 =null;char * ____BAH_COMPILER_VAR_313 =intToStr(cf->mem);char * ____BAH_COMPILER_VAR_314 =pathToVarName(cf->file);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_313);
long int strLen_1 = strlen(".o.o");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_314);
long int strLen_3 = strlen("cache/");
long int strLen_4 = strlen(BAH_DIR);
;                            
            ____BAH_COMPILER_VAR_312 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_312+currStrOff, BAH_DIR, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_312+currStrOff, "cache/", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_312+currStrOff, ____BAH_COMPILER_VAR_314, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_312+currStrOff, ____BAH_COMPILER_VAR_313, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_312+currStrOff, ".o.o", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_315 =____BAH_COMPILER_VAR_312;if ((fileExists(____BAH_COMPILER_VAR_315)==0)) {
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
char * ____BAH_COMPILER_VAR_316 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen("'");
long int strLen_2 = strlen(" '");
long int strLen_3 = strlen(cont);
;                            
            ____BAH_COMPILER_VAR_316 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_316+currStrOff, cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_316+currStrOff, " '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_316+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_316+currStrOff, "'", strLen_1);
            currStrOff += strLen_1;
        
        }cont = ____BAH_COMPILER_VAR_316;
i++;
};
println(cont);
};
struct Elems* dupElems(struct Elems* elems){
struct Elems* ____BAH_COMPILER_VAR_317 = memoryAlloc(sizeof(struct Elems));
____BAH_COMPILER_VAR_317->vars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_317->vars->length = 0;
            ____BAH_COMPILER_VAR_317->vars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_317->structs = memoryAlloc(sizeof(array(struct cStruct*)));
            ____BAH_COMPILER_VAR_317->structs->length = 0;
            ____BAH_COMPILER_VAR_317->structs->elemSize = sizeof(struct cStruct*);
            ____BAH_COMPILER_VAR_317->types = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_317->types->length = 0;
            ____BAH_COMPILER_VAR_317->types->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_317->fns = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_317->fns->length = 0;
            ____BAH_COMPILER_VAR_317->fns->elemSize = sizeof(struct func*);
            ____BAH_COMPILER_VAR_317->defined = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_317->defined->length = 0;
            ____BAH_COMPILER_VAR_317->defined->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_317->parent= null;
struct Elems* nElems = ____BAH_COMPILER_VAR_317;
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
char * ____BAH_COMPILER_VAR_318 =tc.str(&tc);struct string cCast = getCType(____BAH_COMPILER_VAR_318,elems);
char * cCastStr = cCast.str(&cCast);
char * ____BAH_COMPILER_VAR_319 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(")");
long int strLen_1 = strlen(nnnt.cont);
long int strLen_2 = strlen(cCastStr);
long int strLen_3 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_319 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_319+currStrOff, "(", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_319+currStrOff, cCastStr, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_319+currStrOff, ")", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_319+currStrOff, nnnt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }nnnt.cont = ____BAH_COMPILER_VAR_319;

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
char * ____BAH_COMPILER_VAR_320 =__STR(f);array(char)* p = strAsArr(____BAH_COMPILER_VAR_320);
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

        char ____BAH_COMPILER_VAR_321 = 0;
        for(int i=compilerState.includes->length-1; i!=-1;i--) {
            if (compilerState.includes->data[i] != 0 && strcmp(compilerState.includes->data[i], ccstr) == 0) {
                ____BAH_COMPILER_VAR_321=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_321) {
return true;
}
struct fileMap ____BAH_COMPILER_VAR_322 = {};
____BAH_COMPILER_VAR_322.handle = -1;
____BAH_COMPILER_VAR_322.p= null;
____BAH_COMPILER_VAR_322.open = fileMap__open;
____BAH_COMPILER_VAR_322.isValid = fileMap__isValid;
____BAH_COMPILER_VAR_322.close = fileMap__close;
#define fm ____BAH_COMPILER_VAR_322
char * ____BAH_COMPILER_VAR_323 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen(ccstr);
;                            
            ____BAH_COMPILER_VAR_323 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_323+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_323+currStrOff, ccstr, strLen_1);
            currStrOff += strLen_1;
        
        }char * fileName = ____BAH_COMPILER_VAR_323;
char isBahDir = true;
char * f = fm.open(&fm,fileName);
if ((fm.isValid(&fm)==0)) {
char * ____BAH_COMPILER_VAR_324 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(compilerState.currentDir);
long int strLen_1 = strlen(ccstr);
;                            
            ____BAH_COMPILER_VAR_324 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_324+currStrOff, compilerState.currentDir, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_324+currStrOff, ccstr, strLen_1);
            currStrOff += strLen_1;
        
        }fileName = absPath(____BAH_COMPILER_VAR_324);
f = fm.open(&fm,fileName);
isBahDir = false;
if ((fm.isValid(&fm)==0)) {
return false;
}
}
char * oDir = compilerState.currentDir;
if ((isBahDir==false)) {
char * ____BAH_COMPILER_VAR_325 =null;char * ____BAH_COMPILER_VAR_326 =getDirFromFile(ccstr);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(compilerState.currentDir);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_326);
;                            
            ____BAH_COMPILER_VAR_325 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_325+currStrOff, compilerState.currentDir, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_325+currStrOff, ____BAH_COMPILER_VAR_326, strLen_1);
            currStrOff += strLen_1;
        
        }compilerState.currentDir = ____BAH_COMPILER_VAR_325;
}
else {
char * ____BAH_COMPILER_VAR_327 =null;char * ____BAH_COMPILER_VAR_328 =getDirFromFile(ccstr);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_328);
;                            
            ____BAH_COMPILER_VAR_327 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_327+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_327+currStrOff, ____BAH_COMPILER_VAR_328, strLen_1);
            currStrOff += strLen_1;
        
        }compilerState.currentDir = ____BAH_COMPILER_VAR_327;
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
char * ____BAH_COMPILER_VAR_329 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ccstr);
long int strLen_1 = strlen("' not recognized.");
long int strLen_2 = strlen("File '");
;                            
            ____BAH_COMPILER_VAR_329 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_329+currStrOff, "File '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_329+currStrOff, ccstr, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_329+currStrOff, "' not recognized.", strLen_1);
            currStrOff += strLen_1;
        
        }__BAH_panic(____BAH_COMPILER_VAR_329,"/home/alois/Documents/bah-bah/src/parser.bah:242");
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
char * ____BAH_COMPILER_VAR_330 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fn);
long int strLen_1 = strlen("... ");
long int strLen_2 = strlen("compilling: ");
;                            
            ____BAH_COMPILER_VAR_330 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_330+currStrOff, "compilling: ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_330+currStrOff, fn, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_330+currStrOff, "... ", strLen_1);
            currStrOff += strLen_1;
        
        }print(____BAH_COMPILER_VAR_330);
char * ____BAH_COMPILER_VAR_331 =null;
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
            ____BAH_COMPILER_VAR_331 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_331+currStrOff, execName, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_331+currStrOff, " ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_331+currStrOff, fn, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_331+currStrOff, " ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_331+currStrOff, rcp, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_331+currStrOff, " -object ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_331+currStrOff, verboseCC, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_331+currStrOff, " -o ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_331+currStrOff, oName, strLen_1);
            currStrOff += strLen_1;
        
        }struct command cmd = command(____BAH_COMPILER_VAR_331);
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

        char ____BAH_COMPILER_VAR_332 = true;
        done->sendAny(done, &____BAH_COMPILER_VAR_332, sizeof(____BAH_COMPILER_VAR_332));
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

        char ____BAH_COMPILER_VAR_333 = 0;
        for(int i=compilerState.includes->length-1; i!=-1;i--) {
            if (compilerState.includes->data[i] != 0 && strcmp(compilerState.includes->data[i], fileName.str(&fileName)) == 0) {
                ____BAH_COMPILER_VAR_333=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_333) {
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
char * ____BAH_COMPILER_VAR_334 =fileName.str(&fileName);char * fn = absPath(____BAH_COMPILER_VAR_334);
if (((void *)fn==null)) {
char * ____BAH_COMPILER_VAR_335 =null;char * ____BAH_COMPILER_VAR_336 =fileName.str(&fileName);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_336);
;                            
            ____BAH_COMPILER_VAR_335 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_335+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_335+currStrOff, ____BAH_COMPILER_VAR_336, strLen_1);
            currStrOff += strLen_1;
        
        }fn = absPath(____BAH_COMPILER_VAR_335);
if (((void *)fn==null)) {
throwErr(&strt,"Unknown file {TOKEN}.");
}
}
char * of = compilerState.currentFile;
char * od = compilerState.currentDir;
compilerState.currentFile = fn;
compilerState.currentDir = getDirFromFile(fn);
struct fileStream ____BAH_COMPILER_VAR_337 = {};
____BAH_COMPILER_VAR_337.handle= null;
____BAH_COMPILER_VAR_337.name= null;
____BAH_COMPILER_VAR_337.isValid = fileStream__isValid;
____BAH_COMPILER_VAR_337.open = fileStream__open;
____BAH_COMPILER_VAR_337.close = fileStream__close;
____BAH_COMPILER_VAR_337.getPos = fileStream__getPos;
____BAH_COMPILER_VAR_337.setPos = fileStream__setPos;
____BAH_COMPILER_VAR_337.getSize = fileStream__getSize;
____BAH_COMPILER_VAR_337.rewind = fileStream__rewind;
____BAH_COMPILER_VAR_337.getChar = fileStream__getChar;
____BAH_COMPILER_VAR_337.setChar = fileStream__setChar;
____BAH_COMPILER_VAR_337.createFile = fileStream__createFile;
____BAH_COMPILER_VAR_337.writeFile = fileStream__writeFile;
____BAH_COMPILER_VAR_337.writePtr = fileStream__writePtr;
____BAH_COMPILER_VAR_337.readPtr = fileStream__readPtr;
____BAH_COMPILER_VAR_337.readContent = fileStream__readContent;
____BAH_COMPILER_VAR_337.readBytes = fileStream__readBytes;
____BAH_COMPILER_VAR_337.writeBytes = fileStream__writeBytes;
____BAH_COMPILER_VAR_337._end = fileStream___end;
#define fs ____BAH_COMPILER_VAR_337
fs.open(&fs,fn,"r");
char * f = fs.readContent(&fs);
fs.close(&fs);
array(struct Tok)* tokens = lexer(f);
char osod = shouldOnlyDecl;
shouldOnlyDecl = true;
char oiso = isSubObject;
isSubObject = true;
char * ____BAH_COMPILER_VAR_338 =null;char * ____BAH_COMPILER_VAR_339 =intToStr(RCPlevel);char * ____BAH_COMPILER_VAR_340 =pathToVarName(fn);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_339);
long int strLen_1 = strlen(".o");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_340);
long int strLen_3 = strlen("cache/");
long int strLen_4 = strlen(BAH_DIR);
;                            
            ____BAH_COMPILER_VAR_338 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_338+currStrOff, BAH_DIR, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_338+currStrOff, "cache/", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_338+currStrOff, ____BAH_COMPILER_VAR_340, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_338+currStrOff, ____BAH_COMPILER_VAR_339, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_338+currStrOff, ".o", strLen_1);
            currStrOff += strLen_1;
        
        }char * oName = ____BAH_COMPILER_VAR_338;
char * ____BAH_COMPILER_VAR_341 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(oName);
long int strLen_1 = strlen(".o");
long int strLen_2 = strlen("w ");
;                            
            ____BAH_COMPILER_VAR_341 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_341+currStrOff, "w ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_341+currStrOff, oName, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_341+currStrOff, ".o", strLen_1);
            currStrOff += strLen_1;
        
        }
{
long nLength = len(compilerState.cLibs);
if (compilerState.cLibs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(compilerState.cLibs->data, (nLength+50)*sizeof(char *));
compilerState.cLibs->data = newPtr;
}
compilerState.cLibs->data[len(compilerState.cLibs)] = ____BAH_COMPILER_VAR_341;
compilerState.cLibs->length = nLength+1;
} else {
compilerState.cLibs->data[len(compilerState.cLibs)] = ____BAH_COMPILER_VAR_341;
}
};
struct channel * done = channel();
parallelObjCompile(fn,oName,done);
parseLines(tokens,elems);
char ok = *(char*)done->receive(done);
char * ____BAH_COMPILER_VAR_342 =null;char * ____BAH_COMPILER_VAR_343 =pathToVarName(fn);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_343);
long int strLen_1 = strlen("();\n");
long int strLen_2 = strlen("__BAH_init");
;                            
            ____BAH_COMPILER_VAR_342 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_342+currStrOff, "__BAH_init", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_342+currStrOff, ____BAH_COMPILER_VAR_343, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_342+currStrOff, "();\n", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_344 =____BAH_COMPILER_VAR_342;INIT = INIT->add(INIT, rope(____BAH_COMPILER_VAR_344));
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
char * ____BAH_COMPILER_VAR_345 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(sc);
long int strLen_1 = strlen("\n");
long int strLen_2 = strlen("#include ");
;                            
            ____BAH_COMPILER_VAR_345 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_345+currStrOff, "#include ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_345+currStrOff, sc, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_345+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_345));

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
struct Tok ____BAH_COMPILER_VAR_346 = {};
____BAH_COMPILER_VAR_346.cont = "";
____BAH_COMPILER_VAR_346.ogCont = "";
____BAH_COMPILER_VAR_346.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_346.pos = 0;
____BAH_COMPILER_VAR_346.line = 1;
____BAH_COMPILER_VAR_346.begLine = 1;
____BAH_COMPILER_VAR_346.bahType = "";
____BAH_COMPILER_VAR_346.isValue = false;
____BAH_COMPILER_VAR_346.isFunc = false;
____BAH_COMPILER_VAR_346.isOper = false;
____BAH_COMPILER_VAR_346.isEqual = false;
____BAH_COMPILER_VAR_346.pass = false;
____BAH_COMPILER_VAR_346.bahRef= null;
____BAH_COMPILER_VAR_346.cont = "";
#define nt ____BAH_COMPILER_VAR_346
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
struct variable* ____BAH_COMPILER_VAR_347 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_347->name = "";
____BAH_COMPILER_VAR_347->type = "";
____BAH_COMPILER_VAR_347->isConst = false;
____BAH_COMPILER_VAR_347->constVal = "";
____BAH_COMPILER_VAR_347->isArray = false;
____BAH_COMPILER_VAR_347->from = "";
____BAH_COMPILER_VAR_347->declScope= null;
____BAH_COMPILER_VAR_347->isGlobal = false;
____BAH_COMPILER_VAR_347->declRope= null;
____BAH_COMPILER_VAR_347->isReg = false;
struct variable* tmpV = ____BAH_COMPILER_VAR_347;
tmpV->name = t.cont;
char * ____BAH_COMPILER_VAR_348 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s->name);
long int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_348 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_348+currStrOff, s->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_348+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }tmpV->type = ____BAH_COMPILER_VAR_348;
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
char * ____BAH_COMPILER_VAR_349 =null;char * ____BAH_COMPILER_VAR_350 =declareStructMethods(tmpV,s,elems);char * ____BAH_COMPILER_VAR_351 =structType.str(&structType);char * ____BAH_COMPILER_VAR_352 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("));\n");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_350);
long int strLen_2 = strlen(____BAH_COMPILER_VAR_351);
long int strLen_3 = strlen(" = memoryAlloc(sizeof(");
long int strLen_4 = strlen(t.cont);
long int strLen_5 = strlen(" ");
long int strLen_6 = strlen(____BAH_COMPILER_VAR_352);
;                            
            ____BAH_COMPILER_VAR_349 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_349+currStrOff, ____BAH_COMPILER_VAR_352, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_349+currStrOff, " ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_349+currStrOff, t.cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_349+currStrOff, " = memoryAlloc(sizeof(", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_349+currStrOff, ____BAH_COMPILER_VAR_351, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_349+currStrOff, "));\n", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_349+currStrOff, ____BAH_COMPILER_VAR_350, strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_349));

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
struct variable* ____BAH_COMPILER_VAR_353 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_353->name = "";
____BAH_COMPILER_VAR_353->type = "";
____BAH_COMPILER_VAR_353->isConst = false;
____BAH_COMPILER_VAR_353->constVal = "";
____BAH_COMPILER_VAR_353->isArray = false;
____BAH_COMPILER_VAR_353->from = "";
____BAH_COMPILER_VAR_353->declScope= null;
____BAH_COMPILER_VAR_353->isGlobal = false;
____BAH_COMPILER_VAR_353->declRope= null;
____BAH_COMPILER_VAR_353->isReg = false;
struct variable* tmpV = ____BAH_COMPILER_VAR_353;
tmpV->name = rvn;
if ((isHeap==true)) {
char * ____BAH_COMPILER_VAR_354 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s->name);
long int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_354 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_354+currStrOff, s->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_354+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }tmpV->type = ____BAH_COMPILER_VAR_354;

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
char * ____BAH_COMPILER_VAR_355 =rst.str(&rst);struct string structType = string(____BAH_COMPILER_VAR_355);
structType.trimRight(&structType,1);
char * ____BAH_COMPILER_VAR_356 =null;char * ____BAH_COMPILER_VAR_357 =declareStructMethods(tmpV,s,elems);char * ____BAH_COMPILER_VAR_358 =structType.str(&structType);char * ____BAH_COMPILER_VAR_359 =rst.str(&rst);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("));\n");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_357);
long int strLen_2 = strlen(____BAH_COMPILER_VAR_358);
long int strLen_3 = strlen(" = memoryAlloc(sizeof(");
long int strLen_4 = strlen(rvn);
long int strLen_5 = strlen(" ");
long int strLen_6 = strlen(____BAH_COMPILER_VAR_359);
;                            
            ____BAH_COMPILER_VAR_356 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_356+currStrOff, ____BAH_COMPILER_VAR_359, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_356+currStrOff, " ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_356+currStrOff, rvn, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_356+currStrOff, " = memoryAlloc(sizeof(", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_356+currStrOff, ____BAH_COMPILER_VAR_358, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_356+currStrOff, "));\n", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_356+currStrOff, ____BAH_COMPILER_VAR_357, strLen_1);
            currStrOff += strLen_1;
        
        }r = rope(____BAH_COMPILER_VAR_356);
}
else {
char * ____BAH_COMPILER_VAR_360 =null;char * ____BAH_COMPILER_VAR_361 =declareStructMethods(tmpV,s,elems);char * ____BAH_COMPILER_VAR_362 =rst.str(&rst);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(" = {};\n");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_361);
long int strLen_2 = strlen(rvn);
long int strLen_3 = strlen(" ");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_362);
;                            
            ____BAH_COMPILER_VAR_360 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_360+currStrOff, ____BAH_COMPILER_VAR_362, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_360+currStrOff, " ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_360+currStrOff, rvn, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_360+currStrOff, " = {};\n", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_360+currStrOff, ____BAH_COMPILER_VAR_361, strLen_1);
            currStrOff += strLen_1;
        
        }r = rope(____BAH_COMPILER_VAR_360);
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
char * ____BAH_COMPILER_VAR_363 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(m->type);
long int strLen_1 = strlen("'.");
long int strLen_2 = strlen(") as '");
long int strLen_3 = strlen(vlt);
long int strLen_4 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_363 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_363+currStrOff, "Cannot use {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_363+currStrOff, vlt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_363+currStrOff, ") as '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_363+currStrOff, m->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_363+currStrOff, "'.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&vl,____BAH_COMPILER_VAR_363);
}
char * ____BAH_COMPILER_VAR_364 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(vl.cont);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen(" = ");
long int strLen_3 = strlen(m->name);
long int strLen_4 = strlen(sep);
long int strLen_5 = strlen(rvn);
;                            
            ____BAH_COMPILER_VAR_364 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_364+currStrOff, rvn, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_364+currStrOff, sep, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_364+currStrOff, m->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_364+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_364+currStrOff, vl.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_364+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }r = r->add(r, rope(____BAH_COMPILER_VAR_364));
break;
};
if ((j==len(s->members))) {
char * ____BAH_COMPILER_VAR_365 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s->name);
long int strLen_1 = strlen("' has no member called {TOKEN}.");
long int strLen_2 = strlen("Struct '");
;                            
            ____BAH_COMPILER_VAR_365 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_365+currStrOff, "Struct '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_365+currStrOff, s->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_365+currStrOff, "' has no member called {TOKEN}.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&t,____BAH_COMPILER_VAR_365);
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
char * ____BAH_COMPILER_VAR_366 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(m->type);
long int strLen_1 = strlen("'.");
long int strLen_2 = strlen(") as '");
long int strLen_3 = strlen(tt);
long int strLen_4 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_366 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_366+currStrOff, "Cannot use {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_366+currStrOff, tt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_366+currStrOff, ") as '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_366+currStrOff, m->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_366+currStrOff, "'.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&t,____BAH_COMPILER_VAR_366);
}
char * ____BAH_COMPILER_VAR_367 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen(" = ");
long int strLen_3 = strlen(m->name);
long int strLen_4 = strlen(sep);
long int strLen_5 = strlen(rvn);
;                            
            ____BAH_COMPILER_VAR_367 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_367+currStrOff, rvn, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_367+currStrOff, sep, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_367+currStrOff, m->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_367+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_367+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_367+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }r = r->add(r, rope(____BAH_COMPILER_VAR_367));
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
char * ____BAH_COMPILER_VAR_368 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(bracks);
long int strLen_1 = strlen("[]");
;                            
            ____BAH_COMPILER_VAR_368 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_368+currStrOff, bracks, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_368+currStrOff, "[]", strLen_1);
            currStrOff += strLen_1;
        
        }bracks = ____BAH_COMPILER_VAR_368;
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
char * ____BAH_COMPILER_VAR_369 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(bracks);
long int strLen_1 = strlen(arrElem);
;                            
            ____BAH_COMPILER_VAR_369 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_369+currStrOff, bracks, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_369+currStrOff, arrElem, strLen_1);
            currStrOff += strLen_1;
        
        }t.bahType = ____BAH_COMPILER_VAR_369;
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
char * ____BAH_COMPILER_VAR_370 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_370 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_370+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_370+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_370;

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
char * ____BAH_COMPILER_VAR_371 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_371 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_371+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_371+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_371;

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
char * ____BAH_COMPILER_VAR_372 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_372 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_372+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_372+currStrOff, nt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }nt.cont = ____BAH_COMPILER_VAR_372;

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
char * ____BAH_COMPILER_VAR_373 =null;char * ____BAH_COMPILER_VAR_374 =svt.str(&svt);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_374);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen("sizeof(struct ");
long int strLen_3 = strlen(", ");
long int strLen_4 = strlen(e.cont);
long int strLen_5 = strlen("__serialize(&");
;                            
            ____BAH_COMPILER_VAR_373 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_373+currStrOff, "__serialize(&", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_373+currStrOff, e.cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_373+currStrOff, ", ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_373+currStrOff, "sizeof(struct ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_373+currStrOff, ____BAH_COMPILER_VAR_374, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_373+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_373;
}
else {
char * ptrRect = "";
while ((ptrLevel>1)) {
char * ____BAH_COMPILER_VAR_375 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ptrRect);
long int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_375 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_375+currStrOff, ptrRect, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_375+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }ptrRect = ____BAH_COMPILER_VAR_375;
ptrLevel = ptrLevel-1;
};
char * ____BAH_COMPILER_VAR_376 =null;char * ____BAH_COMPILER_VAR_377 =svt.str(&svt);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_377);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen("sizeof(struct ");
long int strLen_3 = strlen(", ");
long int strLen_4 = strlen(e.cont);
long int strLen_5 = strlen(ptrRect);
long int strLen_6 = strlen("__serialize(");
;                            
            ____BAH_COMPILER_VAR_376 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_376+currStrOff, "__serialize(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_376+currStrOff, ptrRect, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_376+currStrOff, e.cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_376+currStrOff, ", ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_376+currStrOff, "sizeof(struct ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_376+currStrOff, ____BAH_COMPILER_VAR_377, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_376+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_376;
register long int i = 0;
while ((i<len(s->members))) {
struct structMemb* m = s->members->data[i];
if ((strcmp(m->type, "cpstring") == 0)) {
char * ____BAH_COMPILER_VAR_378 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(m->name);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen("->");
long int strLen_3 = strlen(e.cont);
long int strLen_4 = strlen("+strlen(");
long int strLen_5 = strlen(code);
;                            
            ____BAH_COMPILER_VAR_378 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_378+currStrOff, code, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_378+currStrOff, "+strlen(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_378+currStrOff, e.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_378+currStrOff, "->", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_378+currStrOff, m->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_378+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_378;
}
i = i+1;
};
}
char * ____BAH_COMPILER_VAR_379 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(")");
;                            
            ____BAH_COMPILER_VAR_379 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_379+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_379+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }return ____BAH_COMPILER_VAR_379;
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
char * ____BAH_COMPILER_VAR_380 =null;char * ____BAH_COMPILER_VAR_381 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen(" = ");
long int strLen_3 = strlen(v);
long int strLen_4 = strlen(" ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_381);
;                            
            ____BAH_COMPILER_VAR_380 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_380+currStrOff, ____BAH_COMPILER_VAR_381, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_380+currStrOff, " ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_380+currStrOff, v, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_380+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_380+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_380+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_380));
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
struct Tok ____BAH_COMPILER_VAR_382 = {};
____BAH_COMPILER_VAR_382.cont = "";
____BAH_COMPILER_VAR_382.ogCont = "";
____BAH_COMPILER_VAR_382.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_382.pos = 0;
____BAH_COMPILER_VAR_382.line = 1;
____BAH_COMPILER_VAR_382.begLine = 1;
____BAH_COMPILER_VAR_382.bahType = "";
____BAH_COMPILER_VAR_382.isValue = false;
____BAH_COMPILER_VAR_382.isFunc = false;
____BAH_COMPILER_VAR_382.isOper = false;
____BAH_COMPILER_VAR_382.isEqual = false;
____BAH_COMPILER_VAR_382.pass = false;
____BAH_COMPILER_VAR_382.bahRef= null;
#define tmpT ____BAH_COMPILER_VAR_382
tmpT.type = TOKEN_TYPE_VAR;
tmpT.cont = "0";
char * ____BAH_COMPILER_VAR_383 =aet.str(&aet);struct Tok rt = parseReflect(tmpT,____BAH_COMPILER_VAR_383,elems,true,"","0");
char * aev = genCompilerVar();
char * ____BAH_COMPILER_VAR_384 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(rt.cont);
long int strLen_1 = strlen(";\n        ");
long int strLen_2 = strlen(" = ");
long int strLen_3 = strlen(aev);
long int strLen_4 = strlen("\n        struct reflectElement ");
;                            
            ____BAH_COMPILER_VAR_384 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_384+currStrOff, "\n        struct reflectElement ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_384+currStrOff, aev, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_384+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_384+currStrOff, rt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_384+currStrOff, ";\n        ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_384));
char * ____BAH_COMPILER_VAR_385 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("&");
long int strLen_1 = strlen(aev);
;                            
            ____BAH_COMPILER_VAR_385 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_385+currStrOff, "&", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_385+currStrOff, aev, strLen_1);
            currStrOff += strLen_1;
        
        }arrElem = ____BAH_COMPILER_VAR_385;

#undef tmpT
}
else if (strHasPrefix(tt,"map:")) {
struct string aet = string(tt);
aet.trimLeft(&aet,4);
struct Tok ____BAH_COMPILER_VAR_386 = {};
____BAH_COMPILER_VAR_386.cont = "";
____BAH_COMPILER_VAR_386.ogCont = "";
____BAH_COMPILER_VAR_386.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_386.pos = 0;
____BAH_COMPILER_VAR_386.line = 1;
____BAH_COMPILER_VAR_386.begLine = 1;
____BAH_COMPILER_VAR_386.bahType = "";
____BAH_COMPILER_VAR_386.isValue = false;
____BAH_COMPILER_VAR_386.isFunc = false;
____BAH_COMPILER_VAR_386.isOper = false;
____BAH_COMPILER_VAR_386.isEqual = false;
____BAH_COMPILER_VAR_386.pass = false;
____BAH_COMPILER_VAR_386.bahRef= null;
#define tmpT ____BAH_COMPILER_VAR_386
tmpT.type = TOKEN_TYPE_VAR;
tmpT.cont = "0";
char * ____BAH_COMPILER_VAR_387 =aet.str(&aet);struct Tok rt = parseReflect(tmpT,____BAH_COMPILER_VAR_387,elems,true,"","0");
char * aev = genCompilerVar();
char * ____BAH_COMPILER_VAR_388 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(rt.cont);
long int strLen_1 = strlen(";\n        ");
long int strLen_2 = strlen(" = ");
long int strLen_3 = strlen(aev);
long int strLen_4 = strlen("\n        struct reflectElement ");
;                            
            ____BAH_COMPILER_VAR_388 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_388+currStrOff, "\n        struct reflectElement ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_388+currStrOff, aev, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_388+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_388+currStrOff, rt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_388+currStrOff, ";\n        ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_388));
char * ____BAH_COMPILER_VAR_389 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("&");
long int strLen_1 = strlen(aev);
;                            
            ____BAH_COMPILER_VAR_389 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_389+currStrOff, "&", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_389+currStrOff, aev, strLen_1);
            currStrOff += strLen_1;
        
        }arrElem = ____BAH_COMPILER_VAR_389;

#undef tmpT
}
char * isStruct = "0";
struct cStruct* ts = searchStruct(tt,elems);
char * structLayout = "0";
if ((ts!=null)) {
isStruct = "1";
structLayout = genCompilerVar();
struct variable* ____BAH_COMPILER_VAR_390 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_390->name = "";
____BAH_COMPILER_VAR_390->type = "";
____BAH_COMPILER_VAR_390->isConst = false;
____BAH_COMPILER_VAR_390->constVal = "";
____BAH_COMPILER_VAR_390->isArray = false;
____BAH_COMPILER_VAR_390->from = "";
____BAH_COMPILER_VAR_390->declScope= null;
____BAH_COMPILER_VAR_390->isGlobal = false;
____BAH_COMPILER_VAR_390->declRope= null;
____BAH_COMPILER_VAR_390->isReg = false;
struct variable* slv = ____BAH_COMPILER_VAR_390;
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
struct structMemb* ____BAH_COMPILER_VAR_391 = memoryAlloc(sizeof(struct structMemb));
____BAH_COMPILER_VAR_391->name = "";
____BAH_COMPILER_VAR_391->type = "";
____BAH_COMPILER_VAR_391->isConst = false;
____BAH_COMPILER_VAR_391->constVal = "";
____BAH_COMPILER_VAR_391->isArray = false;
____BAH_COMPILER_VAR_391->from = "";
____BAH_COMPILER_VAR_391->declScope= null;
____BAH_COMPILER_VAR_391->isGlobal = false;
____BAH_COMPILER_VAR_391->declRope= null;
____BAH_COMPILER_VAR_391->isReg = false;
____BAH_COMPILER_VAR_391->def = "";
____BAH_COMPILER_VAR_391->isFn = false;
struct structMemb* nm = ____BAH_COMPILER_VAR_391;
*nm = *m;
m = nm;
m->type = "ptr";
}
struct Tok ____BAH_COMPILER_VAR_392 = {};
____BAH_COMPILER_VAR_392.cont = "";
____BAH_COMPILER_VAR_392.ogCont = "";
____BAH_COMPILER_VAR_392.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_392.pos = 0;
____BAH_COMPILER_VAR_392.line = 1;
____BAH_COMPILER_VAR_392.begLine = 1;
____BAH_COMPILER_VAR_392.bahType = "";
____BAH_COMPILER_VAR_392.isValue = false;
____BAH_COMPILER_VAR_392.isFunc = false;
____BAH_COMPILER_VAR_392.isOper = false;
____BAH_COMPILER_VAR_392.isEqual = false;
____BAH_COMPILER_VAR_392.pass = false;
____BAH_COMPILER_VAR_392.bahRef= null;
#define tmpT ____BAH_COMPILER_VAR_392
tmpT.type = TOKEN_TYPE_VAR;
char * sep = "->";
if ((strCount(tt,"*")==0)) {
sep = ".";
}
struct string mCtype = getCType(m->type,elems);
struct string offsetTT = string(tt);
offsetTT.replace(&offsetTT,"*","");
char * ____BAH_COMPILER_VAR_393 =null;char * ____BAH_COMPILER_VAR_394 =offsetTT.str(&offsetTT);char * ____BAH_COMPILER_VAR_395 =mCtype.str(&mCtype);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(m->name);
long int strLen_1 = strlen("))");
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_394);
long int strLen_4 = strlen(") + offsetof(struct ");
long int strLen_5 = strlen(t.cont);
long int strLen_6 = strlen("*)((char*)(");
long int strLen_7 = strlen(____BAH_COMPILER_VAR_395);
long int strLen_8 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_393 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_393+currStrOff, "(", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_393+currStrOff, ____BAH_COMPILER_VAR_395, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_393+currStrOff, "*)((char*)(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_393+currStrOff, t.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_393+currStrOff, ") + offsetof(struct ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_393+currStrOff, ____BAH_COMPILER_VAR_394, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_393+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_393+currStrOff, m->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_393+currStrOff, "))", strLen_1);
            currStrOff += strLen_1;
        
        }tmpT.cont = ____BAH_COMPILER_VAR_393;
char * ____BAH_COMPILER_VAR_396 =null;char * ____BAH_COMPILER_VAR_397 =offsetTT.str(&offsetTT);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(m->name);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_397);
long int strLen_4 = strlen("offsetof(struct ");
;                            
            ____BAH_COMPILER_VAR_396 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_396+currStrOff, "offsetof(struct ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_396+currStrOff, ____BAH_COMPILER_VAR_397, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_396+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_396+currStrOff, m->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_396+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }struct Tok rt = parseReflect(tmpT,m->type,elems,true,m->name,____BAH_COMPILER_VAR_396);
char * ____BAH_COMPILER_VAR_398 =null;char * ____BAH_COMPILER_VAR_399 =intToStr(i);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(rt.cont);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen("] = ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_399);
long int strLen_4 = strlen("->data[");
long int strLen_5 = strlen(structLayout);
;                            
            ____BAH_COMPILER_VAR_398 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_398+currStrOff, structLayout, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_398+currStrOff, "->data[", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_398+currStrOff, ____BAH_COMPILER_VAR_399, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_398+currStrOff, "] = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_398+currStrOff, rt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_398+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }dataLayout = dataLayout->add(dataLayout, rope(____BAH_COMPILER_VAR_398));

#undef tmpT
};
char * ____BAH_COMPILER_VAR_400 =null;char * ____BAH_COMPILER_VAR_401 =intToStr(len(ts->members));
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(structLayout);
long int strLen_1 = strlen("->elemSize);\n        ");
long int strLen_2 = strlen("->length * ");
long int strLen_3 = strlen(structLayout);
long int strLen_4 = strlen("->data = memoryAlloc(");
long int strLen_5 = strlen(structLayout);
long int strLen_6 = strlen(";\n        ");
long int strLen_7 = strlen(____BAH_COMPILER_VAR_401);
long int strLen_8 = strlen("->length = ");
long int strLen_9 = strlen(structLayout);
long int strLen_10 = strlen("->elemSize = sizeof(struct reflectElement);\n        ");
long int strLen_11 = strlen(structLayout);
long int strLen_12 = strlen(" = memoryAlloc(sizeof(array(struct reflectElement)));\n        ");
long int strLen_13 = strlen(structLayout);
long int strLen_14 = strlen("\n        array(struct reflectElement) * ");
;                            
            ____BAH_COMPILER_VAR_400 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13+strLen_14);
            
                    memcpy(____BAH_COMPILER_VAR_400+currStrOff, "\n        array(struct reflectElement) * ", strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_400+currStrOff, structLayout, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_400+currStrOff, " = memoryAlloc(sizeof(array(struct reflectElement)));\n        ", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_400+currStrOff, structLayout, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_400+currStrOff, "->elemSize = sizeof(struct reflectElement);\n        ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_400+currStrOff, structLayout, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_400+currStrOff, "->length = ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_400+currStrOff, ____BAH_COMPILER_VAR_401, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_400+currStrOff, ";\n        ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_400+currStrOff, structLayout, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_400+currStrOff, "->data = memoryAlloc(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_400+currStrOff, structLayout, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_400+currStrOff, "->length * ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_400+currStrOff, structLayout, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_400+currStrOff, "->elemSize);\n        ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_400)->add(rope(____BAH_COMPILER_VAR_400), dataLayout));
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
struct variable* ____BAH_COMPILER_VAR_402 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_402->name = "";
____BAH_COMPILER_VAR_402->type = "";
____BAH_COMPILER_VAR_402->isConst = false;
____BAH_COMPILER_VAR_402->constVal = "";
____BAH_COMPILER_VAR_402->isArray = false;
____BAH_COMPILER_VAR_402->from = "";
____BAH_COMPILER_VAR_402->declScope= null;
____BAH_COMPILER_VAR_402->isGlobal = false;
____BAH_COMPILER_VAR_402->declRope= null;
____BAH_COMPILER_VAR_402->isReg = false;
struct variable* rv = ____BAH_COMPILER_VAR_402;
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
char * ____BAH_COMPILER_VAR_403 =null;char * ____BAH_COMPILER_VAR_404 =name.str(&name);char * ____BAH_COMPILER_VAR_405 =cType.str(&cType);
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
long int strLen_11 = strlen(____BAH_COMPILER_VAR_404);
long int strLen_12 = strlen("\", \"");
long int strLen_13 = strlen(tt);
long int strLen_14 = strlen("), \"");
long int strLen_15 = strlen(____BAH_COMPILER_VAR_405);
long int strLen_16 = strlen(", sizeof(");
long int strLen_17 = strlen(t.cont);
long int strLen_18 = strlen(amp);
long int strLen_19 = strlen(" = __reflect(");
long int strLen_20 = strlen(rv->name);
long int strLen_21 = strlen("struct reflectElement ");
;                            
            ____BAH_COMPILER_VAR_403 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13+strLen_14+strLen_15+strLen_16+strLen_17+strLen_18+strLen_19+strLen_20+strLen_21);
            
                    memcpy(____BAH_COMPILER_VAR_403+currStrOff, "struct reflectElement ", strLen_21);
                    currStrOff += strLen_21;
                    
                    memcpy(____BAH_COMPILER_VAR_403+currStrOff, rv->name, strLen_20);
                    currStrOff += strLen_20;
                    
                    memcpy(____BAH_COMPILER_VAR_403+currStrOff, " = __reflect(", strLen_19);
                    currStrOff += strLen_19;
                    
                    memcpy(____BAH_COMPILER_VAR_403+currStrOff, amp, strLen_18);
                    currStrOff += strLen_18;
                    
                    memcpy(____BAH_COMPILER_VAR_403+currStrOff, t.cont, strLen_17);
                    currStrOff += strLen_17;
                    
                    memcpy(____BAH_COMPILER_VAR_403+currStrOff, ", sizeof(", strLen_16);
                    currStrOff += strLen_16;
                    
                    memcpy(____BAH_COMPILER_VAR_403+currStrOff, ____BAH_COMPILER_VAR_405, strLen_15);
                    currStrOff += strLen_15;
                    
                    memcpy(____BAH_COMPILER_VAR_403+currStrOff, "), \"", strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_403+currStrOff, tt, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_403+currStrOff, "\", \"", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_403+currStrOff, ____BAH_COMPILER_VAR_404, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_403+currStrOff, "\", ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_403+currStrOff, isArr, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_403+currStrOff, ", ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_403+currStrOff, arrElem, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_403+currStrOff, ", ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_403+currStrOff, isStruct, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_403+currStrOff, ", ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_403+currStrOff, structLayout, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_403+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_403+currStrOff, offset, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_403+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_403));
t.cont = rv->name;
return t;
};
char * parseArrayDecl(struct variable* v,__BAH_ARR_TYPE_Tok l,long int i,long int max,struct Elems* elems){
long int arrayLength = 0;
struct string arrType = getCType(v->type,elems);
arrType.trimRight(&arrType,1);
char * ____BAH_COMPILER_VAR_406 =null;char * ____BAH_COMPILER_VAR_407 =arrType.str(&arrType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_407);
long int strLen_1 = strlen("))");
long int strLen_2 = strlen("memoryAlloc(sizeof(");
;                            
            ____BAH_COMPILER_VAR_406 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_406+currStrOff, "memoryAlloc(sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_406+currStrOff, ____BAH_COMPILER_VAR_407, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_406+currStrOff, "))", strLen_1);
            currStrOff += strLen_1;
        
        }char * code = ____BAH_COMPILER_VAR_406;
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
struct variable* ____BAH_COMPILER_VAR_408 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_408->name = "";
____BAH_COMPILER_VAR_408->type = "";
____BAH_COMPILER_VAR_408->isConst = false;
____BAH_COMPILER_VAR_408->constVal = "";
____BAH_COMPILER_VAR_408->isArray = false;
____BAH_COMPILER_VAR_408->from = "";
____BAH_COMPILER_VAR_408->declScope= null;
____BAH_COMPILER_VAR_408->isGlobal = false;
____BAH_COMPILER_VAR_408->declRope= null;
____BAH_COMPILER_VAR_408->isReg = false;
struct variable* tmpV = ____BAH_COMPILER_VAR_408;
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
char * ____BAH_COMPILER_VAR_409 =elemType.str(&elemType);struct string cType = getCType(____BAH_COMPILER_VAR_409,elems);
char * ____BAH_COMPILER_VAR_410 =null;char * ____BAH_COMPILER_VAR_411 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(NEXT_LINE);
long int strLen_1 = strlen("\n                ");
long int strLen_2 = strlen(";\n                ");
long int strLen_3 = strlen(innerCode);
long int strLen_4 = strlen(" = ");
long int strLen_5 = strlen(tmpV->name);
long int strLen_6 = strlen(") * ");
long int strLen_7 = strlen(____BAH_COMPILER_VAR_411);
long int strLen_8 = strlen("\n                array(");
;                            
            ____BAH_COMPILER_VAR_410 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_410+currStrOff, "\n                array(", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_410+currStrOff, ____BAH_COMPILER_VAR_411, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_410+currStrOff, ") * ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_410+currStrOff, tmpV->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_410+currStrOff, " = ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_410+currStrOff, innerCode, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_410+currStrOff, ";\n                ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_410+currStrOff, NEXT_LINE, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_410+currStrOff, "\n                ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_410));
NEXT_LINE = oldNL;
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
____BAH_COMPILER_VAR_412.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_412.cont = tmpV->name;
____BAH_COMPILER_VAR_412.bahType = elemType.str(&elemType);
____BAH_COMPILER_VAR_412.isValue = true;
t = ____BAH_COMPILER_VAR_412;
}
char * tt = getTypeFromToken(&t,true,elems);
if ((compTypes(tt,elemBahTypeStr)==false)) {
char * ____BAH_COMPILER_VAR_413 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(") as ");
long int strLen_1 = strlen(elemBahTypeStr);
long int strLen_2 = strlen(tt);
long int strLen_3 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_413 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_413+currStrOff, "Cannot use {TOKEN} (", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_413+currStrOff, tt, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_413+currStrOff, ") as ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_413+currStrOff, elemBahTypeStr, strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&t,____BAH_COMPILER_VAR_413);
}
char * strArrayLength = intToStr(arrayLength);
arrayLength = arrayLength+1;
char * ____BAH_COMPILER_VAR_414 =null;
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
            ____BAH_COMPILER_VAR_414 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_414+currStrOff, NEXT_LINE, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_414+currStrOff, v->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_414+currStrOff, "->data[", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_414+currStrOff, strArrayLength, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_414+currStrOff, "] = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_414+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_414+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }NEXT_LINE = ____BAH_COMPILER_VAR_414;
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
char * ____BAH_COMPILER_VAR_415 =null;
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
            ____BAH_COMPILER_VAR_415 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_415+currStrOff, v->name, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_415+currStrOff, "->data = memoryAlloc(sizeof(", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_415+currStrOff, elemTypeStr, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_415+currStrOff, ") * ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_415+currStrOff, allocLengthStr, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_415+currStrOff, ");", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_415+currStrOff, NEXT_LINE, strLen_1);
            currStrOff += strLen_1;
        
        }NEXT_LINE = ____BAH_COMPILER_VAR_415;
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
char * ____BAH_COMPILER_VAR_416 =null;
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
            ____BAH_COMPILER_VAR_416 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9);
            
                    memcpy(____BAH_COMPILER_VAR_416+currStrOff, "\n", strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_416+currStrOff, v->name, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_416+currStrOff, "->length = ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_416+currStrOff, strArrayLength, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_416+currStrOff, ";\n", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_416+currStrOff, v->name, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_416+currStrOff, "->elemSize = sizeof(", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_416+currStrOff, elemTypeStr, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_416+currStrOff, ");\n", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_416+currStrOff, NEXT_LINE, strLen_1);
            currStrOff += strLen_1;
        
        }NEXT_LINE = ____BAH_COMPILER_VAR_416;
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
char * ____BAH_COMPILER_VAR_417 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ft.cont);
long int strLen_1 = strlen(";\n");
;                            
            ____BAH_COMPILER_VAR_417 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_417+currStrOff, ft.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_417+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_417));
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
struct variable* ____BAH_COMPILER_VAR_418 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_418->name = "";
____BAH_COMPILER_VAR_418->type = "";
____BAH_COMPILER_VAR_418->isConst = false;
____BAH_COMPILER_VAR_418->constVal = "";
____BAH_COMPILER_VAR_418->isArray = false;
____BAH_COMPILER_VAR_418->from = "";
____BAH_COMPILER_VAR_418->declScope= null;
____BAH_COMPILER_VAR_418->isGlobal = false;
____BAH_COMPILER_VAR_418->declRope= null;
____BAH_COMPILER_VAR_418->isReg = false;
v = ____BAH_COMPILER_VAR_418;
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
char * ____BAH_COMPILER_VAR_419 =c.str(&c);v = searchVar(____BAH_COMPILER_VAR_419,elems);
if ((v==null)) {
throwErr(&t,"Cannot increase/decrease not declared variable {TOKEN}.");
}
char * ____BAH_COMPILER_VAR_420 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(";\n");
;                            
            ____BAH_COMPILER_VAR_420 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_420+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_420+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_420));
return;
}
if ((len(l)<2)) {
throwErr(&ft,"Missing '=' after {TOKEN}.");
}
struct Tok operT = l->data[1];

        char ____BAH_COMPILER_VAR_421 = 0;
        for(int i=equalsTokens->length-1; i!=-1;i--) {
            if (equalsTokens->data[i] != 0 && strcmp(equalsTokens->data[i], operT.cont) == 0) {
                ____BAH_COMPILER_VAR_421=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_421&&(strcmp(operT.cont, "=") != 0)) {
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
char * ____BAH_COMPILER_VAR_422 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(currentType);
long int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_422 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_422+currStrOff, currentType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_422+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }currentType = ____BAH_COMPILER_VAR_422;
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
char * ____BAH_COMPILER_VAR_423 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("chan:");
long int strLen_1 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_423 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_423+currStrOff, "chan:", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_423+currStrOff, nt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }v->type = ____BAH_COMPILER_VAR_423;
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
char * ____BAH_COMPILER_VAR_424 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("map:");
long int strLen_1 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_424 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_424+currStrOff, "map:", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_424+currStrOff, nt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }v->type = ____BAH_COMPILER_VAR_424;
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
char * ____BAH_COMPILER_VAR_425 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("buffer:");
long int strLen_1 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_425 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_425+currStrOff, "buffer:", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_425+currStrOff, nt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }v->type = ____BAH_COMPILER_VAR_425;
struct variable* ____BAH_COMPILER_VAR_426 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_426->name = "";
____BAH_COMPILER_VAR_426->type = "";
____BAH_COMPILER_VAR_426->isConst = false;
____BAH_COMPILER_VAR_426->constVal = "";
____BAH_COMPILER_VAR_426->isArray = false;
____BAH_COMPILER_VAR_426->from = "";
____BAH_COMPILER_VAR_426->declScope= null;
____BAH_COMPILER_VAR_426->isGlobal = false;
____BAH_COMPILER_VAR_426->declRope= null;
____BAH_COMPILER_VAR_426->isReg = false;
struct variable* av = ____BAH_COMPILER_VAR_426;
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
char * ____BAH_COMPILER_VAR_427 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen("];");
long int strLen_2 = strlen("[");
long int strLen_3 = strlen(av->name);
long int strLen_4 = strlen("char ");
;                            
            ____BAH_COMPILER_VAR_427 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_427+currStrOff, "char ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_427+currStrOff, av->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_427+currStrOff, "[", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_427+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_427+currStrOff, "];", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_427));
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
char * ____BAH_COMPILER_VAR_428 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(v->type);
long int strLen_1 = strlen(".");
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(tp);
long int strLen_4 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_428 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_428+currStrOff, "Cannot use {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_428+currStrOff, tp, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_428+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_428+currStrOff, v->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_428+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&t,____BAH_COMPILER_VAR_428);
}
}
else {
if ((strcmp(currentType, "") == 0)) {
if ((strcmp(v->type, "") == 0)) {
v->type = tp;
}
else {
if ((compTypes(tp,v->type)==false)) {
char * ____BAH_COMPILER_VAR_429 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(v->type);
long int strLen_1 = strlen(".");
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(tp);
long int strLen_4 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_429 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_429+currStrOff, "Cannot use {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_429+currStrOff, tp, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_429+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_429+currStrOff, v->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_429+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&t,____BAH_COMPILER_VAR_429);
}
}
}
}
if ((strcmp(t.cont, "") != 0)&&(strHasPrefix(t.cont,"{")==false)) {
char * ____BAH_COMPILER_VAR_430 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_430 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_430+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_430+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_430;
if ((t.isOper==false)&&(RCPavailable()==true)) {
struct variable* iv = searchVar(t.cont,elems);
if ((iv!=null)&&(iv->isConst==false)) {
toVar = true;
isPointedVar = strHasPrefix(t.cont,"&");
struct cStruct* s = searchStruct(iv->type,elems);
if ((s!=null)&&(strCount(iv->type,"*")==0)&&(s->isBinding==false)) {
if ((strCount(iv->name,"*")==0)) {
char * ____BAH_COMPILER_VAR_431 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(iv->name);
long int strLen_1 = strlen("), 0)");
long int strLen_2 = strlen(", sizeof(");
long int strLen_3 = strlen(iv->name);
long int strLen_4 = strlen("; RCP_scanStack(&");
long int strLen_5 = strlen(code);
;                            
            ____BAH_COMPILER_VAR_431 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_431+currStrOff, code, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_431+currStrOff, "; RCP_scanStack(&", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_431+currStrOff, iv->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_431+currStrOff, ", sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_431+currStrOff, iv->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_431+currStrOff, "), 0)", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_431;
}
else {
struct string ivn = string(iv->name);
if ((ivn.count(&ivn,"*")>0)) {
ivn.replace(&ivn,"*","");
char * ____BAH_COMPILER_VAR_432 =null;char * ____BAH_COMPILER_VAR_433 =ivn.str(&ivn);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(iv->name);
long int strLen_1 = strlen("), 0)");
long int strLen_2 = strlen(", sizeof(");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_433);
long int strLen_4 = strlen("; RCP_scanStack(");
;                            
            ____BAH_COMPILER_VAR_432 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_432+currStrOff, "; RCP_scanStack(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_432+currStrOff, ____BAH_COMPILER_VAR_433, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_432+currStrOff, ", sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_432+currStrOff, iv->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_432+currStrOff, "), 0)", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_434 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_432);
;                            
            ____BAH_COMPILER_VAR_434 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_434+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_434+currStrOff, ____BAH_COMPILER_VAR_432, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_434;
}
else {
char * ____BAH_COMPILER_VAR_435 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(iv->name);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen("; RCP_incr(");
long int strLen_3 = strlen(code);
;                            
            ____BAH_COMPILER_VAR_435 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_435+currStrOff, code, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_435+currStrOff, "; RCP_incr(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_435+currStrOff, iv->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_435+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_435;
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
char * ____BAH_COMPILER_VAR_436 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_436 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_436+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_436+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_436;
}
i++;
};
if ((exists==true)) {
if ((strlen(code)==0)) {
throwErr(&ft,"Cannot re-declare {TOKEN}.");
}
if ((strlen(currentType)>0)) {
struct Tok st = l->data[1];
char * ____BAH_COMPILER_VAR_437 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ft.cont);
long int strLen_1 = strlen("' to {TOKEN}.");
long int strLen_2 = strlen("Cannot change the type of already declared var '");
;                            
            ____BAH_COMPILER_VAR_437 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_437+currStrOff, "Cannot change the type of already declared var '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_437+currStrOff, ft.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_437+currStrOff, "' to {TOKEN}.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&st,____BAH_COMPILER_VAR_437);
}
char * preCode = "";
if ((isStruct==false)) {
if (isRCPpointerType(v->type)&&(isPointedVar==false)&&(RCPavailable()==true)) {
struct string cType = getCType(v->type,elems);
if ((toVar==true)) {
if ((RCPselfRef(v)==false)) {
char * ____BAH_COMPILER_VAR_438 =null;char * ____BAH_COMPILER_VAR_439 =cType.str(&cType);char * ____BAH_COMPILER_VAR_440 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen("*)RCP_incrIL(&");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_439);
long int strLen_4 = strlen(") = *(");
long int strLen_5 = strlen(v->name);
long int strLen_6 = strlen("*)RCP_decrIL(&");
long int strLen_7 = strlen(____BAH_COMPILER_VAR_440);
long int strLen_8 = strlen("*(");
;                            
            ____BAH_COMPILER_VAR_438 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_438+currStrOff, "*(", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_438+currStrOff, ____BAH_COMPILER_VAR_440, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_438+currStrOff, "*)RCP_decrIL(&", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_438+currStrOff, v->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_438+currStrOff, ") = *(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_438+currStrOff, ____BAH_COMPILER_VAR_439, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_438+currStrOff, "*)RCP_incrIL(&", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_438+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_438+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_438;
}
else {
struct variable* ____BAH_COMPILER_VAR_441 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_441->name = "";
____BAH_COMPILER_VAR_441->type = "";
____BAH_COMPILER_VAR_441->isConst = false;
____BAH_COMPILER_VAR_441->constVal = "";
____BAH_COMPILER_VAR_441->isArray = false;
____BAH_COMPILER_VAR_441->from = "";
____BAH_COMPILER_VAR_441->declScope= null;
____BAH_COMPILER_VAR_441->isGlobal = false;
____BAH_COMPILER_VAR_441->declRope= null;
____BAH_COMPILER_VAR_441->isReg = false;
struct variable* tmpV = ____BAH_COMPILER_VAR_441;
tmpV->name = genCompilerVar();
tmpV->type = v->type;
struct rope* dv = decrVar(tmpV,elems);
char * ____BAH_COMPILER_VAR_442 =null;char * ____BAH_COMPILER_VAR_443 =dv->toStr(dv);char * ____BAH_COMPILER_VAR_444 =cType.str(&cType);char * ____BAH_COMPILER_VAR_445 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(");");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_443);
long int strLen_2 = strlen(code);
long int strLen_3 = strlen("*)RCP_incrIL(&");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_444);
long int strLen_5 = strlen(" = *(");
long int strLen_6 = strlen(v->name);
long int strLen_7 = strlen("; ");
long int strLen_8 = strlen(v->name);
long int strLen_9 = strlen(" = ");
long int strLen_10 = strlen(tmpV->name);
long int strLen_11 = strlen(" ");
long int strLen_12 = strlen(____BAH_COMPILER_VAR_445);
;                            
            ____BAH_COMPILER_VAR_442 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12);
            
                    memcpy(____BAH_COMPILER_VAR_442+currStrOff, ____BAH_COMPILER_VAR_445, strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_442+currStrOff, " ", strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_442+currStrOff, tmpV->name, strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_442+currStrOff, " = ", strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_442+currStrOff, v->name, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_442+currStrOff, "; ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_442+currStrOff, v->name, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_442+currStrOff, " = *(", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_442+currStrOff, ____BAH_COMPILER_VAR_444, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_442+currStrOff, "*)RCP_incrIL(&", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_442+currStrOff, code, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_442+currStrOff, ");", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_442+currStrOff, ____BAH_COMPILER_VAR_443, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_442;
}
}
else {
struct variable* ____BAH_COMPILER_VAR_446 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_446->name = "";
____BAH_COMPILER_VAR_446->type = "";
____BAH_COMPILER_VAR_446->isConst = false;
____BAH_COMPILER_VAR_446->constVal = "";
____BAH_COMPILER_VAR_446->isArray = false;
____BAH_COMPILER_VAR_446->from = "";
____BAH_COMPILER_VAR_446->declScope= null;
____BAH_COMPILER_VAR_446->isGlobal = false;
____BAH_COMPILER_VAR_446->declRope= null;
____BAH_COMPILER_VAR_446->isReg = false;
struct variable* tmpV = ____BAH_COMPILER_VAR_446;
tmpV->name = genCompilerVar();
tmpV->type = v->type;
struct rope* dv = decrVar(tmpV,elems);
char * ____BAH_COMPILER_VAR_447 =null;char * ____BAH_COMPILER_VAR_448 =dv->toStr(dv);char * ____BAH_COMPILER_VAR_449 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(";");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_448);
long int strLen_2 = strlen(code);
long int strLen_3 = strlen(" = ");
long int strLen_4 = strlen(v->name);
long int strLen_5 = strlen("; ");
long int strLen_6 = strlen(v->name);
long int strLen_7 = strlen(" = ");
long int strLen_8 = strlen(tmpV->name);
long int strLen_9 = strlen(" ");
long int strLen_10 = strlen(____BAH_COMPILER_VAR_449);
;                            
            ____BAH_COMPILER_VAR_447 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10);
            
                    memcpy(____BAH_COMPILER_VAR_447+currStrOff, ____BAH_COMPILER_VAR_449, strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_447+currStrOff, " ", strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_447+currStrOff, tmpV->name, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_447+currStrOff, " = ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_447+currStrOff, v->name, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_447+currStrOff, "; ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_447+currStrOff, v->name, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_447+currStrOff, " = ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_447+currStrOff, code, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_447+currStrOff, ";", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_447+currStrOff, ____BAH_COMPILER_VAR_448, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_447;
}
}
else {
struct cStruct* s = searchStruct(v->type,elems);
if ((s!=null)&&(RCPavailable()==true)&&(RCPselfRef(v)==false)&&(s->isBinding==false)) {
if ((strCount(v->name,"*")==0)) {
char * ____BAH_COMPILER_VAR_450 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen("), 1); ");
long int strLen_2 = strlen(", sizeof(");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen("RCP_scanStack(&");
;                            
            ____BAH_COMPILER_VAR_450 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_450+currStrOff, "RCP_scanStack(&", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_450+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_450+currStrOff, ", sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_450+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_450+currStrOff, "), 1); ", strLen_1);
            currStrOff += strLen_1;
        
        }preCode = ____BAH_COMPILER_VAR_450;
}
else {
struct string vn = string(v->name);
vn.replace(&vn,"*","");
char * ____BAH_COMPILER_VAR_451 =null;char * ____BAH_COMPILER_VAR_452 =vn.str(&vn);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen("), 1); ");
long int strLen_2 = strlen(", sizeof(");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_452);
long int strLen_4 = strlen("RCP_scanStack(");
;                            
            ____BAH_COMPILER_VAR_451 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_451+currStrOff, "RCP_scanStack(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_451+currStrOff, ____BAH_COMPILER_VAR_452, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_451+currStrOff, ", sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_451+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_451+currStrOff, "), 1); ", strLen_1);
            currStrOff += strLen_1;
        
        }preCode = ____BAH_COMPILER_VAR_451;
}
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
else {
char * ____BAH_COMPILER_VAR_454 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(" = ");
long int strLen_1 = strlen(code);
long int strLen_2 = strlen(v->name);
;                            
            ____BAH_COMPILER_VAR_454 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_454+currStrOff, v->name, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_454+currStrOff, " = ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_454+currStrOff, code, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_454;
}
}
}
else {
strTrim(&code);
if ((strHasPrefix(code,"{")==false)) {
char * ____BAH_COMPILER_VAR_455 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(" = ");
long int strLen_1 = strlen(code);
long int strLen_2 = strlen(v->name);
;                            
            ____BAH_COMPILER_VAR_455 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_455+currStrOff, v->name, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_455+currStrOff, " = ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_455+currStrOff, code, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_455;
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
char * ____BAH_COMPILER_VAR_456 =null;
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
            ____BAH_COMPILER_VAR_456 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13+strLen_14+strLen_15+strLen_16+strLen_17);
            
                    memcpy(____BAH_COMPILER_VAR_456+currStrOff, "\n{\nlong nLength = ", strLen_17);
                    currStrOff += strLen_17;
                    
                    memcpy(____BAH_COMPILER_VAR_456+currStrOff, nLengthStr, strLen_16);
                    currStrOff += strLen_16;
                    
                    memcpy(____BAH_COMPILER_VAR_456+currStrOff, ";\nif (", strLen_15);
                    currStrOff += strLen_15;
                    
                    memcpy(____BAH_COMPILER_VAR_456+currStrOff, nstr, strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_456+currStrOff, "->length < nLength+1) {\nif ((nLength+1) % 50 == 0 || nLength == 0) {\nvoid * newPtr = memoryRealloc(", strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_456+currStrOff, nstr, strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_456+currStrOff, "->data, (nLength+50)*sizeof(", strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_456+currStrOff, elemTypeStr, strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_456+currStrOff, "));\n", strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_456+currStrOff, nstr, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_456+currStrOff, "->data = newPtr;\n}\n", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_456+currStrOff, code, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_456+currStrOff, ";\n", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_456+currStrOff, nstr, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_456+currStrOff, "->length = nLength+1;\n} else {\n", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_456+currStrOff, preCode, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_456+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_456+currStrOff, ";\n}\n}", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_456;
}
else {
char * ____BAH_COMPILER_VAR_457 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(preCode);
long int strLen_1 = strlen(code);
;                            
            ____BAH_COMPILER_VAR_457 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_457+currStrOff, preCode, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_457+currStrOff, code, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_457;
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
char * ____BAH_COMPILER_VAR_458 =null;char * ____BAH_COMPILER_VAR_459 =ct.str(&ct);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_459);
;                            
            ____BAH_COMPILER_VAR_458 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_458+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_458+currStrOff, ____BAH_COMPILER_VAR_459, strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_458;
j = j+1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_460 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_460 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_460+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_460+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_460;
}
};
char * ____BAH_COMPILER_VAR_461 =null;char * ____BAH_COMPILER_VAR_462 =tmpfnRetCType.str(&tmpfnRetCType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen(")(");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen(" (*");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_462);
;                            
            ____BAH_COMPILER_VAR_461 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_461+currStrOff, ____BAH_COMPILER_VAR_462, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_461+currStrOff, " (*", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_461+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_461+currStrOff, ")(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_461+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_461+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }vct = ____BAH_COMPILER_VAR_461;
}
else {
vct = setCType(v,elems);
}
if ((strcmp(code, "") != 0)&&(shouldOnlyDecl==false)) {
if (isRCPpointerType(v->type)&&(RCPavailable()==true)&&(toVar==true)&&(isPointedVar==false)) {
struct string cType = getCType(v->type,elems);
if (isGlobal()) {
char * ____BAH_COMPILER_VAR_463 =null;char * ____BAH_COMPILER_VAR_464 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(");\n");
long int strLen_2 = strlen("*)RCP_incrIL(&");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_464);
long int strLen_4 = strlen(" = *(");
long int strLen_5 = strlen(v->name);
;                            
            ____BAH_COMPILER_VAR_463 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_463+currStrOff, v->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_463+currStrOff, " = *(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_463+currStrOff, ____BAH_COMPILER_VAR_464, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_463+currStrOff, "*)RCP_incrIL(&", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_463+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_463+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }INIT = INIT->add(INIT, rope(____BAH_COMPILER_VAR_463));
}
else {
char * ____BAH_COMPILER_VAR_465 =null;char * ____BAH_COMPILER_VAR_466 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen("*)RCP_incrIL(&");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_466);
long int strLen_4 = strlen(" = *(");
long int strLen_5 = strlen(vct);
;                            
            ____BAH_COMPILER_VAR_465 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_465+currStrOff, vct, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_465+currStrOff, " = *(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_465+currStrOff, ____BAH_COMPILER_VAR_466, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_465+currStrOff, "*)RCP_incrIL(&", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_465+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_465+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_465;
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
char * ____BAH_COMPILER_VAR_467 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen("\n");
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen("#define ");
;                            
            ____BAH_COMPILER_VAR_467 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_467+currStrOff, "#define ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_467+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_467+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_467+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_467+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }INIT = INIT->add(INIT, rope(____BAH_COMPILER_VAR_467));
}
else {
char * ____BAH_COMPILER_VAR_468 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(" ");
long int strLen_1 = strlen(code);
long int strLen_2 = strlen(v->name);
long int strLen_3 = strlen("#define ");
;                            
            ____BAH_COMPILER_VAR_468 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_468+currStrOff, "#define ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_468+currStrOff, v->name, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_468+currStrOff, " ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_468+currStrOff, code, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_468;
}
}
else {
if (isGlobal()) {
char * ____BAH_COMPILER_VAR_469 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen(" = ");
long int strLen_3 = strlen(v->name);
;                            
            ____BAH_COMPILER_VAR_469 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_469+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_469+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_469+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_469+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }INIT = INIT->add(INIT, rope(____BAH_COMPILER_VAR_469));
}
else {
char * ____BAH_COMPILER_VAR_470 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(" = ");
long int strLen_1 = strlen(code);
long int strLen_2 = strlen(vct);
;                            
            ____BAH_COMPILER_VAR_470 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_470+currStrOff, vct, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_470+currStrOff, " = ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_470+currStrOff, code, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_470;
}
}
}
}
else {
if (isRCPpointerType(v->type)&&(shouldOnlyDecl==false)) {
char * ____BAH_COMPILER_VAR_471 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(vct);
long int strLen_1 = strlen("= null");
;                            
            ____BAH_COMPILER_VAR_471 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_471+currStrOff, vct, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_471+currStrOff, "= null", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_471;
}
else {
code = vct;
}
}
if ((shouldOnlyDecl==true)) {
char * ____BAH_COMPILER_VAR_472 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("extern ");
long int strLen_1 = strlen(vct);
;                            
            ____BAH_COMPILER_VAR_472 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_472+currStrOff, "extern ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_472+currStrOff, vct, strLen_1);
            currStrOff += strLen_1;
        
        }vct = ____BAH_COMPILER_VAR_472;
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
struct variable* ____BAH_COMPILER_VAR_473 = v;
char ** ____BAH_COMPILER_VAR_475 = (char **)((char*)(____BAH_COMPILER_VAR_473) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_476 = __reflect(____BAH_COMPILER_VAR_475, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_477 = (char **)((char*)(____BAH_COMPILER_VAR_473) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_478 = __reflect(____BAH_COMPILER_VAR_477, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_479 = (char*)((char*)(____BAH_COMPILER_VAR_473) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_480 = __reflect(____BAH_COMPILER_VAR_479, sizeof(char), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_481 = (char **)((char*)(____BAH_COMPILER_VAR_473) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_482 = __reflect(____BAH_COMPILER_VAR_481, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_483 = (char*)((char*)(____BAH_COMPILER_VAR_473) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_484 = __reflect(____BAH_COMPILER_VAR_483, sizeof(char), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_485 = (char **)((char*)(____BAH_COMPILER_VAR_473) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_486 = __reflect(____BAH_COMPILER_VAR_485, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
void ** ____BAH_COMPILER_VAR_487 = (void **)((char*)(____BAH_COMPILER_VAR_473) + offsetof(struct variable, declScope));
struct reflectElement ____BAH_COMPILER_VAR_488 = __reflect(____BAH_COMPILER_VAR_487, sizeof(void *), "ptr", "declScope", 0, 0, 0, 0, offsetof(struct variable, declScope));
char* ____BAH_COMPILER_VAR_489 = (char*)((char*)(____BAH_COMPILER_VAR_473) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_490 = __reflect(____BAH_COMPILER_VAR_489, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));
struct rope** ____BAH_COMPILER_VAR_491 = (struct rope**)((char*)(____BAH_COMPILER_VAR_473) + offsetof(struct variable, declRope));
void ** ____BAH_COMPILER_VAR_493 = (void **)((char*)(____BAH_COMPILER_VAR_491) + offsetof(struct rope, left));
struct reflectElement ____BAH_COMPILER_VAR_494 = __reflect(____BAH_COMPILER_VAR_493, sizeof(void *), "ptr", "left", 0, 0, 0, 0, offsetof(struct rope, left));
void ** ____BAH_COMPILER_VAR_495 = (void **)((char*)(____BAH_COMPILER_VAR_491) + offsetof(struct rope, right));
struct reflectElement ____BAH_COMPILER_VAR_496 = __reflect(____BAH_COMPILER_VAR_495, sizeof(void *), "ptr", "right", 0, 0, 0, 0, offsetof(struct rope, right));
char ** ____BAH_COMPILER_VAR_497 = (char **)((char*)(____BAH_COMPILER_VAR_491) + offsetof(struct rope, str));
struct reflectElement ____BAH_COMPILER_VAR_498 = __reflect(____BAH_COMPILER_VAR_497, sizeof(char *), "cpstring", "str", 0, 0, 0, 0, offsetof(struct rope, str));
long int* ____BAH_COMPILER_VAR_499 = (long int*)((char*)(____BAH_COMPILER_VAR_491) + offsetof(struct rope, lCount));
struct reflectElement ____BAH_COMPILER_VAR_500 = __reflect(____BAH_COMPILER_VAR_499, sizeof(long int), "int", "lCount", 0, 0, 0, 0, offsetof(struct rope, lCount));
long int* ____BAH_COMPILER_VAR_501 = (long int*)((char*)(____BAH_COMPILER_VAR_491) + offsetof(struct rope, len));
struct reflectElement ____BAH_COMPILER_VAR_502 = __reflect(____BAH_COMPILER_VAR_501, sizeof(long int), "int", "len", 0, 0, 0, 0, offsetof(struct rope, len));
long int* ____BAH_COMPILER_VAR_503 = (long int*)((char*)(____BAH_COMPILER_VAR_491) + offsetof(struct rope, totalLen));
struct reflectElement ____BAH_COMPILER_VAR_504 = __reflect(____BAH_COMPILER_VAR_503, sizeof(long int), "int", "totalLen", 0, 0, 0, 0, offsetof(struct rope, totalLen));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_492 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_492->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_492->length = 6;
        ____BAH_COMPILER_VAR_492->data = memoryAlloc(____BAH_COMPILER_VAR_492->length * ____BAH_COMPILER_VAR_492->elemSize);
        ____BAH_COMPILER_VAR_492->data[0] = ____BAH_COMPILER_VAR_494;
____BAH_COMPILER_VAR_492->data[1] = ____BAH_COMPILER_VAR_496;
____BAH_COMPILER_VAR_492->data[2] = ____BAH_COMPILER_VAR_498;
____BAH_COMPILER_VAR_492->data[3] = ____BAH_COMPILER_VAR_500;
____BAH_COMPILER_VAR_492->data[4] = ____BAH_COMPILER_VAR_502;
____BAH_COMPILER_VAR_492->data[5] = ____BAH_COMPILER_VAR_504;
struct reflectElement ____BAH_COMPILER_VAR_505 = __reflect(____BAH_COMPILER_VAR_491, sizeof(struct rope), "rope*", "declRope", 0, 0, 1, ____BAH_COMPILER_VAR_492, offsetof(struct variable, declRope));
char* ____BAH_COMPILER_VAR_506 = (char*)((char*)(____BAH_COMPILER_VAR_473) + offsetof(struct variable, canBeReg));
struct reflectElement ____BAH_COMPILER_VAR_507 = __reflect(____BAH_COMPILER_VAR_506, sizeof(char), "bool", "canBeReg", 0, 0, 0, 0, offsetof(struct variable, canBeReg));
char* ____BAH_COMPILER_VAR_508 = (char*)((char*)(____BAH_COMPILER_VAR_473) + offsetof(struct variable, isReg));
struct reflectElement ____BAH_COMPILER_VAR_509 = __reflect(____BAH_COMPILER_VAR_508, sizeof(char), "bool", "isReg", 0, 0, 0, 0, offsetof(struct variable, isReg));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_474 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_474->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_474->length = 11;
        ____BAH_COMPILER_VAR_474->data = memoryAlloc(____BAH_COMPILER_VAR_474->length * ____BAH_COMPILER_VAR_474->elemSize);
        ____BAH_COMPILER_VAR_474->data[0] = ____BAH_COMPILER_VAR_476;
____BAH_COMPILER_VAR_474->data[1] = ____BAH_COMPILER_VAR_478;
____BAH_COMPILER_VAR_474->data[2] = ____BAH_COMPILER_VAR_480;
____BAH_COMPILER_VAR_474->data[3] = ____BAH_COMPILER_VAR_482;
____BAH_COMPILER_VAR_474->data[4] = ____BAH_COMPILER_VAR_484;
____BAH_COMPILER_VAR_474->data[5] = ____BAH_COMPILER_VAR_486;
____BAH_COMPILER_VAR_474->data[6] = ____BAH_COMPILER_VAR_488;
____BAH_COMPILER_VAR_474->data[7] = ____BAH_COMPILER_VAR_490;
____BAH_COMPILER_VAR_474->data[8] = ____BAH_COMPILER_VAR_505;
____BAH_COMPILER_VAR_474->data[9] = ____BAH_COMPILER_VAR_507;
____BAH_COMPILER_VAR_474->data[10] = ____BAH_COMPILER_VAR_509;
struct reflectElement ____BAH_COMPILER_VAR_510 = __reflect(____BAH_COMPILER_VAR_473, sizeof(struct variable), "variable*", "v", 0, 0, 1, ____BAH_COMPILER_VAR_474, 0);
debugPrint("var_declaration",ft.line,____BAH_COMPILER_VAR_510);
if (isGlobal()) {
char * ____BAH_COMPILER_VAR_511 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(vct);
long int strLen_1 = strlen(";\n");
;                            
            ____BAH_COMPILER_VAR_511 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_511+currStrOff, vct, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_511+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_511));
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
char * ____BAH_COMPILER_VAR_512 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen("\n");
;                            
            ____BAH_COMPILER_VAR_512 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_512+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_512+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_512));
}
else {
char * ____BAH_COMPILER_VAR_513 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(";\n");
;                            
            ____BAH_COMPILER_VAR_513 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_513+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_513+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }struct rope* declR = rope(____BAH_COMPILER_VAR_513);
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
char * ____BAH_COMPILER_VAR_514 =null;char * ____BAH_COMPILER_VAR_515 =ct.str(&ct);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_515);
;                            
            ____BAH_COMPILER_VAR_514 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_514+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_514+currStrOff, ____BAH_COMPILER_VAR_515, strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_514;
j = j+1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_516 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_516 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_516+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_516+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_516;
}
};
char * ____BAH_COMPILER_VAR_517 =null;char * ____BAH_COMPILER_VAR_518 =tmpfnRetCType.str(&tmpfnRetCType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen(")(");
long int strLen_3 = strlen(elemName);
long int strLen_4 = strlen(" (*");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_518);
;                            
            ____BAH_COMPILER_VAR_517 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_517+currStrOff, ____BAH_COMPILER_VAR_518, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_517+currStrOff, " (*", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_517+currStrOff, elemName, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_517+currStrOff, ")(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_517+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_517+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }return ____BAH_COMPILER_VAR_517;
};
char * parseFnHeader(char * prev,__BAH_ARR_TYPE_Tok l,long int* i,struct func* fn,struct Elems* elems){
register long int j = *i;
struct Tok ft = l->data[j];
char * tpdf = "";
if ((ft.type!=TOKEN_TYPE_VAR)) {
throwErr(&ft,"Cannot use {TOKEN} as function name.");
}
char * ____BAH_COMPILER_VAR_519 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(prev);
long int strLen_1 = strlen(ft.cont);
;                            
            ____BAH_COMPILER_VAR_519 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_519+currStrOff, prev, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_519+currStrOff, ft.cont, strLen_1);
            currStrOff += strLen_1;
        
        }fn->name = ____BAH_COMPILER_VAR_519;
array(struct variable*)* arguments = memoryAlloc(sizeof(array(struct variable*)));

arguments->length = 0;
arguments->elemSize = sizeof(struct variable*);
char * ____BAH_COMPILER_VAR_520 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fn->name);
long int strLen_1 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_520 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_520+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_520+currStrOff, "(", strLen_1);
            currStrOff += strLen_1;
        
        }char * code = ____BAH_COMPILER_VAR_520;
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
char * ____BAH_COMPILER_VAR_521 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(argType);
long int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_521 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_521+currStrOff, argType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_521+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }argType = ____BAH_COMPILER_VAR_521;
}
}
else {
isComa = true;
break;
}
j = j+1;
};
struct variable* ____BAH_COMPILER_VAR_522 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_522->name = "";
____BAH_COMPILER_VAR_522->type = "";
____BAH_COMPILER_VAR_522->isConst = false;
____BAH_COMPILER_VAR_522->constVal = "";
____BAH_COMPILER_VAR_522->isArray = false;
____BAH_COMPILER_VAR_522->from = "";
____BAH_COMPILER_VAR_522->declScope= null;
____BAH_COMPILER_VAR_522->isGlobal = false;
____BAH_COMPILER_VAR_522->declRope= null;
____BAH_COMPILER_VAR_522->isReg = false;
struct variable* argument = ____BAH_COMPILER_VAR_522;
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
char * ____BAH_COMPILER_VAR_523 =null;char * ____BAH_COMPILER_VAR_524 =cfrt.str(&cfrt);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("__BAH_ARR_TYPE_");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_524);
;                            
            ____BAH_COMPILER_VAR_523 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_523+currStrOff, "__BAH_ARR_TYPE_", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_523+currStrOff, ____BAH_COMPILER_VAR_524, strLen_1);
            currStrOff += strLen_1;
        
        }newArgType = ____BAH_COMPILER_VAR_523;
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
char * ____BAH_COMPILER_VAR_525 =null;char * ____BAH_COMPILER_VAR_526 =argCType.str(&argCType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(newArgType);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_526);
long int strLen_4 = strlen("typedef ");
long int strLen_5 = strlen(tpdf);
;                            
            ____BAH_COMPILER_VAR_525 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_525+currStrOff, tpdf, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_525+currStrOff, "typedef ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_525+currStrOff, ____BAH_COMPILER_VAR_526, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_525+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_525+currStrOff, newArgType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_525+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }tpdf = ____BAH_COMPILER_VAR_525;
}
}
if ((cfrt.hasPrefix(&cfrt,"function(")==1)) {
char * ____BAH_COMPILER_VAR_527 =null;char * ____BAH_COMPILER_VAR_528 =getCfunctionType(cfrt,argName,elems);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_528);
;                            
            ____BAH_COMPILER_VAR_527 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_527+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_527+currStrOff, ____BAH_COMPILER_VAR_528, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_527;
}
else {
char * ____BAH_COMPILER_VAR_529 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(" ");
long int strLen_1 = strlen(argName);
long int strLen_2 = strlen(newArgType);
long int strLen_3 = strlen(code);
;                            
            ____BAH_COMPILER_VAR_529 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_529+currStrOff, code, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_529+currStrOff, newArgType, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_529+currStrOff, " ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_529+currStrOff, argName, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_529;
}
if ((isComa==true)) {
char * ____BAH_COMPILER_VAR_530 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_530 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_530+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_530+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_530;
}
else {
char * ____BAH_COMPILER_VAR_531 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(")");
;                            
            ____BAH_COMPILER_VAR_531 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_531+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_531+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_531;
break;
}
j = j+1;
};
}
else {
char * ____BAH_COMPILER_VAR_532 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(")");
;                            
            ____BAH_COMPILER_VAR_532 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_532+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_532+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_532;
}
j = j+1;
struct variable* ____BAH_COMPILER_VAR_533 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_533->name = "";
____BAH_COMPILER_VAR_533->type = "";
____BAH_COMPILER_VAR_533->isConst = false;
____BAH_COMPILER_VAR_533->constVal = "";
____BAH_COMPILER_VAR_533->isArray = false;
____BAH_COMPILER_VAR_533->from = "";
____BAH_COMPILER_VAR_533->declScope= null;
____BAH_COMPILER_VAR_533->isGlobal = false;
____BAH_COMPILER_VAR_533->declRope= null;
____BAH_COMPILER_VAR_533->isReg = false;
struct variable* returns = ____BAH_COMPILER_VAR_533;
returns->type = "";
while ((j<len(l))) {
t = l->data[j];
if ((strcmp(t.cont, "{") == 0)) {
break;
}
char * ____BAH_COMPILER_VAR_534 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(returns->type);
long int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_534 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_534+currStrOff, returns->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_534+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }returns->type = ____BAH_COMPILER_VAR_534;
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
char * ____BAH_COMPILER_VAR_535 =null;char * ____BAH_COMPILER_VAR_536 =cfrt.str(&cfrt);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("__BAH_ARR_TYPE_");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_536);
;                            
            ____BAH_COMPILER_VAR_535 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_535+currStrOff, "__BAH_ARR_TYPE_", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_535+currStrOff, ____BAH_COMPILER_VAR_536, strLen_1);
            currStrOff += strLen_1;
        
        }newFnRetType = ____BAH_COMPILER_VAR_535;
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
char * ____BAH_COMPILER_VAR_537 =null;char * ____BAH_COMPILER_VAR_538 =fnRetType.str(&fnRetType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(newFnRetType);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_538);
long int strLen_4 = strlen("typedef ");
long int strLen_5 = strlen(tpdf);
;                            
            ____BAH_COMPILER_VAR_537 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_537+currStrOff, tpdf, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_537+currStrOff, "typedef ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_537+currStrOff, ____BAH_COMPILER_VAR_538, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_537+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_537+currStrOff, newFnRetType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_537+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }tpdf = ____BAH_COMPILER_VAR_537;
}
}
char * ____BAH_COMPILER_VAR_539 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(" ");
long int strLen_1 = strlen(code);
long int strLen_2 = strlen(newFnRetType);
long int strLen_3 = strlen(tpdf);
;                            
            ____BAH_COMPILER_VAR_539 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_539+currStrOff, tpdf, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_539+currStrOff, newFnRetType, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_539+currStrOff, " ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_539+currStrOff, code, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_539;
return code;
};
void parseStruct(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
struct cStruct* ____BAH_COMPILER_VAR_540 = memoryAlloc(sizeof(struct cStruct));
____BAH_COMPILER_VAR_540->name = "";
____BAH_COMPILER_VAR_540->members = memoryAlloc(sizeof(array(struct structMemb*)));
            ____BAH_COMPILER_VAR_540->members->length = 0;
            ____BAH_COMPILER_VAR_540->members->elemSize = sizeof(struct structMemb*);
            ____BAH_COMPILER_VAR_540->methods = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_540->methods->length = 0;
            ____BAH_COMPILER_VAR_540->methods->elemSize = sizeof(struct func*);
            ____BAH_COMPILER_VAR_540->postCode = "";
____BAH_COMPILER_VAR_540->extendedFrom = "";
____BAH_COMPILER_VAR_540->isBinding = false;
____BAH_COMPILER_VAR_540->hasRCPmemb = false;
struct cStruct* s = ____BAH_COMPILER_VAR_540;
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
char * ____BAH_COMPILER_VAR_541 =null;char * ____BAH_COMPILER_VAR_542 =ct.str(&ct);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_542);
;                            
            ____BAH_COMPILER_VAR_541 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_541+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_541+currStrOff, ____BAH_COMPILER_VAR_542, strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_541;
j = j+1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_543 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_543 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_543+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_543+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_543;
}
};
char * ____BAH_COMPILER_VAR_544 =null;char * ____BAH_COMPILER_VAR_545 =tmpfnRetCType.str(&tmpfnRetCType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen(")(");
long int strLen_3 = strlen(em->name);
long int strLen_4 = strlen(" (*");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_545);
;                            
            ____BAH_COMPILER_VAR_544 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_544+currStrOff, ____BAH_COMPILER_VAR_545, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_544+currStrOff, " (*", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_544+currStrOff, em->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_544+currStrOff, ")(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_544+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_544+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }membDeclStr = ____BAH_COMPILER_VAR_544;
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
char * ____BAH_COMPILER_VAR_546 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(emt->name);
long int strLen_1 = strlen(")(");
long int strLen_2 = strlen("(*");
;                            
            ____BAH_COMPILER_VAR_546 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_546+currStrOff, "(*", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_546+currStrOff, emt->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_546+currStrOff, ")(", strLen_1);
            currStrOff += strLen_1;
        
        }mthdDecl.append(&mthdDecl,____BAH_COMPILER_VAR_546);
j = 0;
while ((j<len(emt->args))) {
struct variable* a = emt->args->data[j];
struct string tp = getCType(a->type,elems);
char * ____BAH_COMPILER_VAR_547 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(" ");
long int strLen_1 = strlen(a->name);
;                            
            ____BAH_COMPILER_VAR_547 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_547+currStrOff, " ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_547+currStrOff, a->name, strLen_1);
            currStrOff += strLen_1;
        
        }tp.append(&tp,____BAH_COMPILER_VAR_547);
long int max = len(emt->args)-1;
if ((j!=max)) {
tp.append(&tp,",");
}
char * ____BAH_COMPILER_VAR_548 =tp.str(&tp);mthdDecl.append(&mthdDecl,____BAH_COMPILER_VAR_548);
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
struct structMemb* ____BAH_COMPILER_VAR_549 = memoryAlloc(sizeof(struct structMemb));
____BAH_COMPILER_VAR_549->name = "";
____BAH_COMPILER_VAR_549->type = "";
____BAH_COMPILER_VAR_549->isConst = false;
____BAH_COMPILER_VAR_549->constVal = "";
____BAH_COMPILER_VAR_549->isArray = false;
____BAH_COMPILER_VAR_549->from = "";
____BAH_COMPILER_VAR_549->declScope= null;
____BAH_COMPILER_VAR_549->isGlobal = false;
____BAH_COMPILER_VAR_549->declRope= null;
____BAH_COMPILER_VAR_549->isReg = false;
____BAH_COMPILER_VAR_549->def = "";
____BAH_COMPILER_VAR_549->isFn = false;
struct structMemb* memb = ____BAH_COMPILER_VAR_549;
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
char * ____BAH_COMPILER_VAR_550 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s->name);
long int strLen_1 = strlen("__");
;                            
            ____BAH_COMPILER_VAR_550 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_550+currStrOff, s->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_550+currStrOff, "__", strLen_1);
            currStrOff += strLen_1;
        
        }char * fnPrefix = ____BAH_COMPILER_VAR_550;
struct func* ____BAH_COMPILER_VAR_551 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_551->name = "";
____BAH_COMPILER_VAR_551->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_551->args->length = 0;
            ____BAH_COMPILER_VAR_551->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_551->returns= null;
____BAH_COMPILER_VAR_551->isBinding = false;
____BAH_COMPILER_VAR_551->from = "";
____BAH_COMPILER_VAR_551->file = "";
____BAH_COMPILER_VAR_551->line = 1;
____BAH_COMPILER_VAR_551->used = false;
____BAH_COMPILER_VAR_551->code = null;
struct func* fn = ____BAH_COMPILER_VAR_551;
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
char * ____BAH_COMPILER_VAR_552 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s->name);
long int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_552 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_552+currStrOff, s->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_552+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_552;
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
char * ____BAH_COMPILER_VAR_553 =parseFnHeader(fnPrefix,nl,&nli,fn,elems);struct rope* code = rope(____BAH_COMPILER_VAR_553);
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
struct func* ____BAH_COMPILER_VAR_554 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_554->name = "";
____BAH_COMPILER_VAR_554->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_554->args->length = 0;
            ____BAH_COMPILER_VAR_554->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_554->returns= null;
____BAH_COMPILER_VAR_554->isBinding = false;
____BAH_COMPILER_VAR_554->from = "";
____BAH_COMPILER_VAR_554->file = "";
____BAH_COMPILER_VAR_554->line = 1;
____BAH_COMPILER_VAR_554->used = false;
____BAH_COMPILER_VAR_554->code = null;
struct func* mfn = ____BAH_COMPILER_VAR_554;
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
char * ____BAH_COMPILER_VAR_555 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fn->name);
long int strLen_1 = strlen("' is not returned.");
long int strLen_2 = strlen("Function '");
;                            
            ____BAH_COMPILER_VAR_555 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_555+currStrOff, "Function '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_555+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_555+currStrOff, "' is not returned.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&l->data[len(l)-1],____BAH_COMPILER_VAR_555);
}
endRCPscope(fnElems,fn->args);
}
code = code->add(code, OUTPUT->add(OUTPUT, rope("};\n")));
}
}
if ((doesOutput==true)) {
char * ____BAH_COMPILER_VAR_556 =null;char * ____BAH_COMPILER_VAR_557 =code->toStr(code);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nextLine);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_557);
;                            
            ____BAH_COMPILER_VAR_556 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_556+currStrOff, nextLine, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_556+currStrOff, ____BAH_COMPILER_VAR_557, strLen_1);
            currStrOff += strLen_1;
        
        }nextLine = ____BAH_COMPILER_VAR_556;
}
struct string mthdDecl = getCType(fn->returns->type,elems);
char * ____BAH_COMPILER_VAR_558 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(mfn->name);
long int strLen_1 = strlen(")(");
long int strLen_2 = strlen("(*");
;                            
            ____BAH_COMPILER_VAR_558 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_558+currStrOff, "(*", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_558+currStrOff, mfn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_558+currStrOff, ")(", strLen_1);
            currStrOff += strLen_1;
        
        }mthdDecl.append(&mthdDecl,____BAH_COMPILER_VAR_558);
j = 0;
while ((j<len(arguments))) {
struct variable* a = arguments->data[j];
struct string tp = getCType(a->type,elems);
char * ____BAH_COMPILER_VAR_559 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(" ");
long int strLen_1 = strlen(a->name);
;                            
            ____BAH_COMPILER_VAR_559 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_559+currStrOff, " ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_559+currStrOff, a->name, strLen_1);
            currStrOff += strLen_1;
        
        }tp.append(&tp,____BAH_COMPILER_VAR_559);
max = len(arguments)-1;
if ((j!=max)) {
tp.append(&tp,",");
}
char * ____BAH_COMPILER_VAR_560 =tp.str(&tp);mthdDecl.append(&mthdDecl,____BAH_COMPILER_VAR_560);
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
char * ____BAH_COMPILER_VAR_561 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(mbmType);
long int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_561 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_561+currStrOff, mbmType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_561+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }mbmType = ____BAH_COMPILER_VAR_561;
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
char * ____BAH_COMPILER_VAR_562 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(memb->type);
long int strLen_1 = strlen(" for member.");
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(tt);
long int strLen_4 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_562 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_562+currStrOff, "Cannot use {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_562+currStrOff, tt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_562+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_562+currStrOff, memb->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_562+currStrOff, " for member.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&t,____BAH_COMPILER_VAR_562);
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
char * ____BAH_COMPILER_VAR_563 =null;char * ____BAH_COMPILER_VAR_564 =ct.str(&ct);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_564);
;                            
            ____BAH_COMPILER_VAR_563 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_563+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_563+currStrOff, ____BAH_COMPILER_VAR_564, strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_563;
j = j+1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_565 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_565 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_565+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_565+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_565;
}
};
char * ____BAH_COMPILER_VAR_566 =null;char * ____BAH_COMPILER_VAR_567 =tmpfnRetCType.str(&tmpfnRetCType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen(")(");
long int strLen_3 = strlen(memb->name);
long int strLen_4 = strlen(" (*");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_567);
;                            
            ____BAH_COMPILER_VAR_566 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_566+currStrOff, ____BAH_COMPILER_VAR_567, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_566+currStrOff, " (*", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_566+currStrOff, memb->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_566+currStrOff, ")(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_566+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_566+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }membDeclStr = ____BAH_COMPILER_VAR_566;
}
else {
struct string membDecl = getCType(memb->type,elems);
char * ____BAH_COMPILER_VAR_568 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(" ");
long int strLen_1 = strlen(memb->name);
;                            
            ____BAH_COMPILER_VAR_568 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_568+currStrOff, " ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_568+currStrOff, memb->name, strLen_1);
            currStrOff += strLen_1;
        
        }membDecl.append(&membDecl,____BAH_COMPILER_VAR_568);
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
char * ____BAH_COMPILER_VAR_569 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s->name);
long int strLen_1 = strlen(" {\n");
long int strLen_2 = strlen("struct ");
;                            
            ____BAH_COMPILER_VAR_569 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_569+currStrOff, "struct ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_569+currStrOff, s->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_569+currStrOff, " {\n", strLen_1);
            currStrOff += strLen_1;
        
        }struct rope* code = rope(____BAH_COMPILER_VAR_569);
i = 0;
while ((i<len(allMembs))) {
char * m = allMembs->data[i];
char * ____BAH_COMPILER_VAR_570 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(m);
long int strLen_1 = strlen(";\n");
;                            
            ____BAH_COMPILER_VAR_570 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_570+currStrOff, m, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_570+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }code = code->add(code, rope(____BAH_COMPILER_VAR_570));
i++;
};
code = code->add(code, rope("};\n"));
OUTPUT = OUTPUT->add(OUTPUT, code);
}
if ((debug==true)) {
struct debugStruct* ____BAH_COMPILER_VAR_571 = memoryAlloc(sizeof(struct debugStruct));
____BAH_COMPILER_VAR_571->name= null;
____BAH_COMPILER_VAR_571->membs = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_571->membs->length = 0;
            ____BAH_COMPILER_VAR_571->membs->elemSize = sizeof(struct variable*);
            struct debugStruct* ds = ____BAH_COMPILER_VAR_571;
ds->name = s->name;
i = 0;
while ((i<len(s->members))) {
struct structMemb* m = s->members->data[i];
struct variable* ____BAH_COMPILER_VAR_572 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_572->name = "";
____BAH_COMPILER_VAR_572->type = "";
____BAH_COMPILER_VAR_572->isConst = false;
____BAH_COMPILER_VAR_572->constVal = "";
____BAH_COMPILER_VAR_572->isArray = false;
____BAH_COMPILER_VAR_572->from = "";
____BAH_COMPILER_VAR_572->declScope= null;
____BAH_COMPILER_VAR_572->isGlobal = false;
____BAH_COMPILER_VAR_572->declRope= null;
____BAH_COMPILER_VAR_572->isReg = false;
struct variable* mv = ____BAH_COMPILER_VAR_572;
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
struct debugStruct* ____BAH_COMPILER_VAR_573 = ds;
char ** ____BAH_COMPILER_VAR_575 = (char **)((char*)(____BAH_COMPILER_VAR_573) + offsetof(struct debugStruct, name));
struct reflectElement ____BAH_COMPILER_VAR_576 = __reflect(____BAH_COMPILER_VAR_575, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct debugStruct, name));
array(struct variable*)** ____BAH_COMPILER_VAR_577 = (array(struct variable*)**)((char*)(____BAH_COMPILER_VAR_573) + offsetof(struct debugStruct, membs));
struct variable** ____BAH_COMPILER_VAR_578 = 0;
char ** ____BAH_COMPILER_VAR_580 = (char **)((char*)(____BAH_COMPILER_VAR_578) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_581 = __reflect(____BAH_COMPILER_VAR_580, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_582 = (char **)((char*)(____BAH_COMPILER_VAR_578) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_583 = __reflect(____BAH_COMPILER_VAR_582, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_584 = (char*)((char*)(____BAH_COMPILER_VAR_578) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_585 = __reflect(____BAH_COMPILER_VAR_584, sizeof(char), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_586 = (char **)((char*)(____BAH_COMPILER_VAR_578) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_587 = __reflect(____BAH_COMPILER_VAR_586, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_588 = (char*)((char*)(____BAH_COMPILER_VAR_578) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_589 = __reflect(____BAH_COMPILER_VAR_588, sizeof(char), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_590 = (char **)((char*)(____BAH_COMPILER_VAR_578) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_591 = __reflect(____BAH_COMPILER_VAR_590, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
void ** ____BAH_COMPILER_VAR_592 = (void **)((char*)(____BAH_COMPILER_VAR_578) + offsetof(struct variable, declScope));
struct reflectElement ____BAH_COMPILER_VAR_593 = __reflect(____BAH_COMPILER_VAR_592, sizeof(void *), "ptr", "declScope", 0, 0, 0, 0, offsetof(struct variable, declScope));
char* ____BAH_COMPILER_VAR_594 = (char*)((char*)(____BAH_COMPILER_VAR_578) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_595 = __reflect(____BAH_COMPILER_VAR_594, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));
struct rope** ____BAH_COMPILER_VAR_596 = (struct rope**)((char*)(____BAH_COMPILER_VAR_578) + offsetof(struct variable, declRope));
void ** ____BAH_COMPILER_VAR_598 = (void **)((char*)(____BAH_COMPILER_VAR_596) + offsetof(struct rope, left));
struct reflectElement ____BAH_COMPILER_VAR_599 = __reflect(____BAH_COMPILER_VAR_598, sizeof(void *), "ptr", "left", 0, 0, 0, 0, offsetof(struct rope, left));
void ** ____BAH_COMPILER_VAR_600 = (void **)((char*)(____BAH_COMPILER_VAR_596) + offsetof(struct rope, right));
struct reflectElement ____BAH_COMPILER_VAR_601 = __reflect(____BAH_COMPILER_VAR_600, sizeof(void *), "ptr", "right", 0, 0, 0, 0, offsetof(struct rope, right));
char ** ____BAH_COMPILER_VAR_602 = (char **)((char*)(____BAH_COMPILER_VAR_596) + offsetof(struct rope, str));
struct reflectElement ____BAH_COMPILER_VAR_603 = __reflect(____BAH_COMPILER_VAR_602, sizeof(char *), "cpstring", "str", 0, 0, 0, 0, offsetof(struct rope, str));
long int* ____BAH_COMPILER_VAR_604 = (long int*)((char*)(____BAH_COMPILER_VAR_596) + offsetof(struct rope, lCount));
struct reflectElement ____BAH_COMPILER_VAR_605 = __reflect(____BAH_COMPILER_VAR_604, sizeof(long int), "int", "lCount", 0, 0, 0, 0, offsetof(struct rope, lCount));
long int* ____BAH_COMPILER_VAR_606 = (long int*)((char*)(____BAH_COMPILER_VAR_596) + offsetof(struct rope, len));
struct reflectElement ____BAH_COMPILER_VAR_607 = __reflect(____BAH_COMPILER_VAR_606, sizeof(long int), "int", "len", 0, 0, 0, 0, offsetof(struct rope, len));
long int* ____BAH_COMPILER_VAR_608 = (long int*)((char*)(____BAH_COMPILER_VAR_596) + offsetof(struct rope, totalLen));
struct reflectElement ____BAH_COMPILER_VAR_609 = __reflect(____BAH_COMPILER_VAR_608, sizeof(long int), "int", "totalLen", 0, 0, 0, 0, offsetof(struct rope, totalLen));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_597 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_597->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_597->length = 6;
        ____BAH_COMPILER_VAR_597->data = memoryAlloc(____BAH_COMPILER_VAR_597->length * ____BAH_COMPILER_VAR_597->elemSize);
        ____BAH_COMPILER_VAR_597->data[0] = ____BAH_COMPILER_VAR_599;
____BAH_COMPILER_VAR_597->data[1] = ____BAH_COMPILER_VAR_601;
____BAH_COMPILER_VAR_597->data[2] = ____BAH_COMPILER_VAR_603;
____BAH_COMPILER_VAR_597->data[3] = ____BAH_COMPILER_VAR_605;
____BAH_COMPILER_VAR_597->data[4] = ____BAH_COMPILER_VAR_607;
____BAH_COMPILER_VAR_597->data[5] = ____BAH_COMPILER_VAR_609;
struct reflectElement ____BAH_COMPILER_VAR_610 = __reflect(____BAH_COMPILER_VAR_596, sizeof(struct rope), "rope*", "declRope", 0, 0, 1, ____BAH_COMPILER_VAR_597, offsetof(struct variable, declRope));
char* ____BAH_COMPILER_VAR_611 = (char*)((char*)(____BAH_COMPILER_VAR_578) + offsetof(struct variable, canBeReg));
struct reflectElement ____BAH_COMPILER_VAR_612 = __reflect(____BAH_COMPILER_VAR_611, sizeof(char), "bool", "canBeReg", 0, 0, 0, 0, offsetof(struct variable, canBeReg));
char* ____BAH_COMPILER_VAR_613 = (char*)((char*)(____BAH_COMPILER_VAR_578) + offsetof(struct variable, isReg));
struct reflectElement ____BAH_COMPILER_VAR_614 = __reflect(____BAH_COMPILER_VAR_613, sizeof(char), "bool", "isReg", 0, 0, 0, 0, offsetof(struct variable, isReg));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_579 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_579->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_579->length = 11;
        ____BAH_COMPILER_VAR_579->data = memoryAlloc(____BAH_COMPILER_VAR_579->length * ____BAH_COMPILER_VAR_579->elemSize);
        ____BAH_COMPILER_VAR_579->data[0] = ____BAH_COMPILER_VAR_581;
____BAH_COMPILER_VAR_579->data[1] = ____BAH_COMPILER_VAR_583;
____BAH_COMPILER_VAR_579->data[2] = ____BAH_COMPILER_VAR_585;
____BAH_COMPILER_VAR_579->data[3] = ____BAH_COMPILER_VAR_587;
____BAH_COMPILER_VAR_579->data[4] = ____BAH_COMPILER_VAR_589;
____BAH_COMPILER_VAR_579->data[5] = ____BAH_COMPILER_VAR_591;
____BAH_COMPILER_VAR_579->data[6] = ____BAH_COMPILER_VAR_593;
____BAH_COMPILER_VAR_579->data[7] = ____BAH_COMPILER_VAR_595;
____BAH_COMPILER_VAR_579->data[8] = ____BAH_COMPILER_VAR_610;
____BAH_COMPILER_VAR_579->data[9] = ____BAH_COMPILER_VAR_612;
____BAH_COMPILER_VAR_579->data[10] = ____BAH_COMPILER_VAR_614;
struct reflectElement ____BAH_COMPILER_VAR_615 = __reflect(____BAH_COMPILER_VAR_578, sizeof(struct variable), "variable*", "", 0, 0, 1, ____BAH_COMPILER_VAR_579, 0);

        struct reflectElement ____BAH_COMPILER_VAR_616 = ____BAH_COMPILER_VAR_615;
        struct reflectElement ____BAH_COMPILER_VAR_617 = __reflect(____BAH_COMPILER_VAR_577, sizeof(array(struct variable*)*), "[]variable*", "membs", 1, &____BAH_COMPILER_VAR_616, 0, 0, offsetof(struct debugStruct, membs));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_574 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_574->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_574->length = 2;
        ____BAH_COMPILER_VAR_574->data = memoryAlloc(____BAH_COMPILER_VAR_574->length * ____BAH_COMPILER_VAR_574->elemSize);
        ____BAH_COMPILER_VAR_574->data[0] = ____BAH_COMPILER_VAR_576;
____BAH_COMPILER_VAR_574->data[1] = ____BAH_COMPILER_VAR_617;
struct reflectElement ____BAH_COMPILER_VAR_618 = __reflect(____BAH_COMPILER_VAR_573, sizeof(struct debugStruct), "debugStruct*", "ds", 0, 0, 1, ____BAH_COMPILER_VAR_574, 0);
debugPrint("struct_declare",nameToken.line,____BAH_COMPILER_VAR_618);
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
struct func* ____BAH_COMPILER_VAR_619 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_619->name = "";
____BAH_COMPILER_VAR_619->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_619->args->length = 0;
            ____BAH_COMPILER_VAR_619->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_619->returns= null;
____BAH_COMPILER_VAR_619->isBinding = false;
____BAH_COMPILER_VAR_619->from = "";
____BAH_COMPILER_VAR_619->file = "";
____BAH_COMPILER_VAR_619->line = 1;
____BAH_COMPILER_VAR_619->used = false;
____BAH_COMPILER_VAR_619->code = null;
struct func* fn = ____BAH_COMPILER_VAR_619;
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
char * ____BAH_COMPILER_VAR_620 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(";\n");
;                            
            ____BAH_COMPILER_VAR_620 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_620+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_620+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_620));
}
}
else {
char * tp = "";
i++;
for (; (i<len(l)); i++) {
struct Tok t = l->data[i];
char * ____BAH_COMPILER_VAR_621 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tp);
long int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_621 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_621+currStrOff, tp, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_621+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }tp = ____BAH_COMPILER_VAR_621;
};
if ((ft.type!=TOKEN_TYPE_VAR)) {
throwErr(&ft,"Cannot use {TOKEN} as new type name.");
}
struct string cTypeNewType = getCType(tp,elems);
char * cTypeNewTypeStr = cTypeNewType.str(&cTypeNewType);
if ((doesOutput==true)) {
char * ____BAH_COMPILER_VAR_622 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ft.cont);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(cTypeNewTypeStr);
long int strLen_4 = strlen("typedef ");
;                            
            ____BAH_COMPILER_VAR_622 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_622+currStrOff, "typedef ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_622+currStrOff, cTypeNewTypeStr, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_622+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_622+currStrOff, ft.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_622+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_622));
}
if ((debug==true)) {
struct debugType* ____BAH_COMPILER_VAR_623 = memoryAlloc(sizeof(struct debugType));
____BAH_COMPILER_VAR_623->name= null;
____BAH_COMPILER_VAR_623->refers= null;
struct debugType* dt = ____BAH_COMPILER_VAR_623;
dt->name = ft.cont;
dt->refers = tp;
struct debugType* ____BAH_COMPILER_VAR_624 = dt;
char ** ____BAH_COMPILER_VAR_626 = (char **)((char*)(____BAH_COMPILER_VAR_624) + offsetof(struct debugType, name));
struct reflectElement ____BAH_COMPILER_VAR_627 = __reflect(____BAH_COMPILER_VAR_626, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct debugType, name));
char ** ____BAH_COMPILER_VAR_628 = (char **)((char*)(____BAH_COMPILER_VAR_624) + offsetof(struct debugType, refers));
struct reflectElement ____BAH_COMPILER_VAR_629 = __reflect(____BAH_COMPILER_VAR_628, sizeof(char *), "cpstring", "refers", 0, 0, 0, 0, offsetof(struct debugType, refers));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_625 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_625->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_625->length = 2;
        ____BAH_COMPILER_VAR_625->data = memoryAlloc(____BAH_COMPILER_VAR_625->length * ____BAH_COMPILER_VAR_625->elemSize);
        ____BAH_COMPILER_VAR_625->data[0] = ____BAH_COMPILER_VAR_627;
____BAH_COMPILER_VAR_625->data[1] = ____BAH_COMPILER_VAR_629;
struct reflectElement ____BAH_COMPILER_VAR_630 = __reflect(____BAH_COMPILER_VAR_624, sizeof(struct debugType), "debugType*", "dt", 0, 0, 1, ____BAH_COMPILER_VAR_625, 0);
debugPrint("type_declare",ft.line,____BAH_COMPILER_VAR_630);
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
struct variable* ____BAH_COMPILER_VAR_631 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_631->name = "";
____BAH_COMPILER_VAR_631->type = "";
____BAH_COMPILER_VAR_631->isConst = false;
____BAH_COMPILER_VAR_631->constVal = "";
____BAH_COMPILER_VAR_631->isArray = false;
____BAH_COMPILER_VAR_631->from = "";
____BAH_COMPILER_VAR_631->declScope= null;
____BAH_COMPILER_VAR_631->isGlobal = false;
____BAH_COMPILER_VAR_631->declRope= null;
____BAH_COMPILER_VAR_631->isReg = false;
struct variable* v = ____BAH_COMPILER_VAR_631;
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
char * ____BAH_COMPILER_VAR_632 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(valt.cont);
long int strLen_1 = strlen("\n");
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen("#define ");
;                            
            ____BAH_COMPILER_VAR_632 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_632+currStrOff, "#define ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_632+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_632+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_632+currStrOff, valt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_632+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_632));
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
char * ____BAH_COMPILER_VAR_633 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(currentFn->returns->type);
long int strLen_1 = strlen(".");
long int strLen_2 = strlen("Cannot return nothing as ");
;                            
            ____BAH_COMPILER_VAR_633 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_633+currStrOff, "Cannot return nothing as ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_633+currStrOff, currentFn->returns->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_633+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&l->data[0],____BAH_COMPILER_VAR_633);
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
char * ____BAH_COMPILER_VAR_634 =null;char * ____BAH_COMPILER_VAR_635 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(rvt.cont);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen("=");
long int strLen_3 = strlen(rv);
long int strLen_4 = strlen(" ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_635);
;                            
            ____BAH_COMPILER_VAR_634 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_634+currStrOff, ____BAH_COMPILER_VAR_635, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_634+currStrOff, " ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_634+currStrOff, rv, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_634+currStrOff, "=", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_634+currStrOff, rvt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_634+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_634));
}
if ((compTypes(tt,currentFn->returns->type)==false)) {
char * ____BAH_COMPILER_VAR_636 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(currentFn->returns->type);
long int strLen_1 = strlen(".");
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(tt);
long int strLen_4 = strlen("Cannot return {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_636 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_636+currStrOff, "Cannot return {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_636+currStrOff, tt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_636+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_636+currStrOff, currentFn->returns->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_636+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&rvt,____BAH_COMPILER_VAR_636);
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
char * ____BAH_COMPILER_VAR_637 =null;char * ____BAH_COMPILER_VAR_638 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(rv);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen(" = ");
long int strLen_3 = strlen(rvar);
long int strLen_4 = strlen(" ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_638);
;                            
            ____BAH_COMPILER_VAR_637 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_637+currStrOff, ____BAH_COMPILER_VAR_638, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_637+currStrOff, " ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_637+currStrOff, rvar, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_637+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_637+currStrOff, rv, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_637+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_637));
if ((tmpV!=null)&&(tmpV->declScope!=elems)) {
OUTPUT = OUTPUT->add(OUTPUT, incrVar(tmpV,elems));
}
}
if (strHasPrefix(tt,"buffer:")) {
char * ____BAH_COMPILER_VAR_639 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(rvar);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen("__STR(");
;                            
            ____BAH_COMPILER_VAR_639 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_639+currStrOff, "__STR(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_639+currStrOff, rvar, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_639+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }rvar = ____BAH_COMPILER_VAR_639;
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
char * ____BAH_COMPILER_VAR_640 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(rvar);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen("return ");
;                            
            ____BAH_COMPILER_VAR_640 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_640+currStrOff, "return ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_640+currStrOff, rvar, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_640+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_640));
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
char * ____BAH_COMPILER_VAR_641 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(condt.cont);
long int strLen_1 = strlen(") {\n");
long int strLen_2 = strlen("if (");
;                            
            ____BAH_COMPILER_VAR_641 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_641+currStrOff, "if (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_641+currStrOff, condt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_641+currStrOff, ") {\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_641));
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
char * ____BAH_COMPILER_VAR_642 =OUTPUT->toStr(OUTPUT);struct string instC = string(____BAH_COMPILER_VAR_642);
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
char * ____BAH_COMPILER_VAR_643 =null;char * ____BAH_COMPILER_VAR_644 =instC.str(&instC);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_644);
long int strLen_1 = strlen(") {\n");
long int strLen_2 = strlen("; ");
long int strLen_3 = strlen(condt.cont);
long int strLen_4 = strlen("for (; ");
;                            
            ____BAH_COMPILER_VAR_643 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_643+currStrOff, "for (; ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_643+currStrOff, condt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_643+currStrOff, "; ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_643+currStrOff, ____BAH_COMPILER_VAR_644, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_643+currStrOff, ") {\n", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_645 =____BAH_COMPILER_VAR_643;OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_645));
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
char * ____BAH_COMPILER_VAR_646 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(condt.cont);
long int strLen_1 = strlen(") {\n");
long int strLen_2 = strlen("while (");
;                            
            ____BAH_COMPILER_VAR_646 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_646+currStrOff, "while (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_646+currStrOff, condt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_646+currStrOff, ") {\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_646));
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
char * ____BAH_COMPILER_VAR_647 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ft.cont);
long int strLen_1 = strlen(";\n");
;                            
            ____BAH_COMPILER_VAR_647 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_647+currStrOff, ft.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_647+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_647));
};
void makeEvalFunc(struct func* fn,struct Elems* elems){

        char ____BAH_COMPILER_VAR_648 = 0;
        for(int i=compilerState.evals->length-1; i!=-1;i--) {
            if (compilerState.evals->data[i] != 0 && strcmp(compilerState.evals->data[i], fn->name) == 0) {
                ____BAH_COMPILER_VAR_648=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_648) {
return;
}
char * ____BAH_COMPILER_VAR_649 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("__Bah_eval_");
long int strLen_1 = strlen(fn->name);
;                            
            ____BAH_COMPILER_VAR_649 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_649+currStrOff, "__Bah_eval_", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_649+currStrOff, fn->name, strLen_1);
            currStrOff += strLen_1;
        
        }struct func* ____BAH_COMPILER_VAR_650 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_650->name = "";
____BAH_COMPILER_VAR_650->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_650->args->length = 0;
            ____BAH_COMPILER_VAR_650->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_650->returns= null;
____BAH_COMPILER_VAR_650->isBinding = false;
____BAH_COMPILER_VAR_650->from = "";
____BAH_COMPILER_VAR_650->file = "";
____BAH_COMPILER_VAR_650->line = 1;
____BAH_COMPILER_VAR_650->used = false;
____BAH_COMPILER_VAR_650->code = null;
____BAH_COMPILER_VAR_650->name = ____BAH_COMPILER_VAR_649;
struct func* efn = ____BAH_COMPILER_VAR_650;
struct variable* ____BAH_COMPILER_VAR_651 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_651->name = "";
____BAH_COMPILER_VAR_651->type = "";
____BAH_COMPILER_VAR_651->isConst = false;
____BAH_COMPILER_VAR_651->constVal = "";
____BAH_COMPILER_VAR_651->isArray = false;
____BAH_COMPILER_VAR_651->from = "";
____BAH_COMPILER_VAR_651->declScope= null;
____BAH_COMPILER_VAR_651->isGlobal = false;
____BAH_COMPILER_VAR_651->declRope= null;
____BAH_COMPILER_VAR_651->isReg = false;
____BAH_COMPILER_VAR_651->type = "ptr";
efn->returns = ____BAH_COMPILER_VAR_651;
struct variable* ____BAH_COMPILER_VAR_652 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_652->name = "";
____BAH_COMPILER_VAR_652->type = "";
____BAH_COMPILER_VAR_652->isConst = false;
____BAH_COMPILER_VAR_652->constVal = "";
____BAH_COMPILER_VAR_652->isArray = false;
____BAH_COMPILER_VAR_652->from = "";
____BAH_COMPILER_VAR_652->declScope= null;
____BAH_COMPILER_VAR_652->isGlobal = false;
____BAH_COMPILER_VAR_652->declRope= null;
____BAH_COMPILER_VAR_652->isReg = false;
____BAH_COMPILER_VAR_652->name = "fnArgs";
____BAH_COMPILER_VAR_652->type = "[]ptr";
efn->args = memoryAlloc(sizeof(array(struct variable*)));

efn->args->length = 1;
efn->args->elemSize = sizeof(struct variable*);
efn->args->data = memoryAlloc(sizeof(struct variable*) * 50);efn->args->data[0] = ____BAH_COMPILER_VAR_652;
char * fnBinding = "";
char * ____BAH_COMPILER_VAR_653 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fn->name);
long int strLen_1 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_653 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_653+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_653+currStrOff, "(", strLen_1);
            currStrOff += strLen_1;
        
        }char * fnCall = ____BAH_COMPILER_VAR_653;
register long int i = 0;
for (; (i<len(fn->args)); i++) {
struct variable* a = fn->args->data[i];
char * v = genCompilerVar();
struct string cType = getCType(a->type,elems);
if ((isRCPpointerType(a->type)==false)) {
cType.append(&cType,"*");
}
char * ____BAH_COMPILER_VAR_654 =null;char * ____BAH_COMPILER_VAR_655 =intToStr(i);char * ____BAH_COMPILER_VAR_656 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_655);
long int strLen_1 = strlen("];");
long int strLen_2 = strlen(" = fnArgs->data[");
long int strLen_3 = strlen(v);
long int strLen_4 = strlen(" ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_656);
;                            
            ____BAH_COMPILER_VAR_654 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_654+currStrOff, ____BAH_COMPILER_VAR_656, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_654+currStrOff, " ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_654+currStrOff, v, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_654+currStrOff, " = fnArgs->data[", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_654+currStrOff, ____BAH_COMPILER_VAR_655, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_654+currStrOff, "];", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_657 =null;char * ____BAH_COMPILER_VAR_658 =____BAH_COMPILER_VAR_654;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnBinding);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_658);
;                            
            ____BAH_COMPILER_VAR_657 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_657+currStrOff, fnBinding, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_657+currStrOff, ____BAH_COMPILER_VAR_658, strLen_1);
            currStrOff += strLen_1;
        
        }fnBinding = ____BAH_COMPILER_VAR_657;
if ((i!=0)) {
char * ____BAH_COMPILER_VAR_659 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnCall);
long int strLen_1 = strlen(", ");
;                            
            ____BAH_COMPILER_VAR_659 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_659+currStrOff, fnCall, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_659+currStrOff, ", ", strLen_1);
            currStrOff += strLen_1;
        
        }fnCall = ____BAH_COMPILER_VAR_659;
}
if (isRCPpointerType(a->type)) {
char * ____BAH_COMPILER_VAR_660 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnCall);
long int strLen_1 = strlen(v);
;                            
            ____BAH_COMPILER_VAR_660 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_660+currStrOff, fnCall, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_660+currStrOff, v, strLen_1);
            currStrOff += strLen_1;
        
        }fnCall = ____BAH_COMPILER_VAR_660;
}
else {
char * ____BAH_COMPILER_VAR_661 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("*");
long int strLen_1 = strlen(v);
;                            
            ____BAH_COMPILER_VAR_661 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_661+currStrOff, "*", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_661+currStrOff, v, strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_662 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnCall);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_661);
;                            
            ____BAH_COMPILER_VAR_662 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_662+currStrOff, fnCall, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_662+currStrOff, ____BAH_COMPILER_VAR_661, strLen_1);
            currStrOff += strLen_1;
        
        }fnCall = ____BAH_COMPILER_VAR_662;
}
};
char * setReturnValue = "void* r = 0;";
if (isRCPpointerType(fn->returns->type)) {
setReturnValue = "void* r = ";
}
else {
struct string cType = getCType(fn->returns->type,elems);
if ((strcmp(cType.str(&cType), "void") != 0)) {
char * ____BAH_COMPILER_VAR_663 =null;char * ____BAH_COMPILER_VAR_664 =cType.str(&cType);char * ____BAH_COMPILER_VAR_665 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_664);
long int strLen_1 = strlen("));*r = ");
long int strLen_2 = strlen("* r = memoryAlloc(sizeof(");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_665);
;                            
            ____BAH_COMPILER_VAR_663 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_663+currStrOff, ____BAH_COMPILER_VAR_665, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_663+currStrOff, "* r = memoryAlloc(sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_663+currStrOff, ____BAH_COMPILER_VAR_664, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_663+currStrOff, "));*r = ", strLen_1);
            currStrOff += strLen_1;
        
        }setReturnValue = ____BAH_COMPILER_VAR_663;
}
}
char * ____BAH_COMPILER_VAR_666 =null;char * ____BAH_COMPILER_VAR_667 =intToStr(len(fn->args));
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
long int strLen_8 = strlen(____BAH_COMPILER_VAR_667);
long int strLen_9 = strlen("(array(void*)* fnArgs) {\n        if (fnArgs->length != ");
long int strLen_10 = strlen(efn->name);
long int strLen_11 = strlen("void* __attribute__((optimize(\"O0\"))) ");
;                            
            ____BAH_COMPILER_VAR_666 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11);
            
                    memcpy(____BAH_COMPILER_VAR_666+currStrOff, "void* __attribute__((optimize(\"O0\"))) ", strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_666+currStrOff, efn->name, strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_666+currStrOff, "(array(void*)* fnArgs) {\n        if (fnArgs->length != ", strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_666+currStrOff, ____BAH_COMPILER_VAR_667, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_666+currStrOff, ") {\n            __BAH_panic((char*)\"eval: calling function ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_666+currStrOff, fn->name, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_666+currStrOff, "() with the wrong number of arguments.\", \"BAH_COMPILER_INTERNAL\");\n        }\n        ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_666+currStrOff, fnBinding, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_666+currStrOff, "\n        ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_666+currStrOff, setReturnValue, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_666+currStrOff, fnCall, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_666+currStrOff, ");\n        return (void*)r;\n    };", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_666));

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
char * ____BAH_COMPILER_VAR_668 =msg.str(&msg);throwWarning(____BAH_COMPILER_VAR_668);
return;
}
if ((strcmp(ft.cont, "#eval") == 0)) {

        char ____BAH_COMPILER_VAR_669 = 0;
        for(int i=compilerState.includes->length-1; i!=-1;i--) {
            if (compilerState.includes->data[i] != 0 && strcmp(compilerState.includes->data[i], "eval.bah") == 0) {
                ____BAH_COMPILER_VAR_669=1;
                break;
            };
        }
        if ((____BAH_COMPILER_VAR_669==false)) {
if ((includeFile("eval.bah",elems)==false)) {
char * ____BAH_COMPILER_VAR_670 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen(").");
long int strLen_2 = strlen("Could not find file 'eval.bah'. Check your bah directory (");
;                            
            ____BAH_COMPILER_VAR_670 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_670+currStrOff, "Could not find file 'eval.bah'. Check your bah directory (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_670+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_670+currStrOff, ").", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&l->data[0],____BAH_COMPILER_VAR_670);
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
char * ____BAH_COMPILER_VAR_671 =fnName.str(&fnName);struct func* fn = searchFunc(____BAH_COMPILER_VAR_671,elems,true);
if ((fn==null)) {
char * ____BAH_COMPILER_VAR_672 =null;char * ____BAH_COMPILER_VAR_673 =fnName.str(&fnName);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_673);
long int strLen_1 = strlen("', arround {TOKEN}.");
long int strLen_2 = strlen("Internal compiler error.\n Error parsing async call for function '");
;                            
            ____BAH_COMPILER_VAR_672 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_672+currStrOff, "Internal compiler error.\n Error parsing async call for function '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_672+currStrOff, ____BAH_COMPILER_VAR_673, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_672+currStrOff, "', arround {TOKEN}.", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_674 =____BAH_COMPILER_VAR_672;throwErr(&fnT,____BAH_COMPILER_VAR_674);
}
char * sMembs = "";
char * unSerMembs = "";
i = 0;
while ((i<len(fn->args))) {
struct variable* a = fn->args->data[i];
struct string cType = getCType(a->type,elems);
char * ____BAH_COMPILER_VAR_675 =null;char * ____BAH_COMPILER_VAR_676 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(a->name);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_676);
long int strLen_4 = strlen(sMembs);
;                            
            ____BAH_COMPILER_VAR_675 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_675+currStrOff, sMembs, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_675+currStrOff, ____BAH_COMPILER_VAR_676, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_675+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_675+currStrOff, a->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_675+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }sMembs = ____BAH_COMPILER_VAR_675;
char * ____BAH_COMPILER_VAR_677 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("args->");
long int strLen_1 = strlen(a->name);
long int strLen_2 = strlen(unSerMembs);
;                            
            ____BAH_COMPILER_VAR_677 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_677+currStrOff, unSerMembs, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_677+currStrOff, "args->", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_677+currStrOff, a->name, strLen_1);
            currStrOff += strLen_1;
        
        }unSerMembs = ____BAH_COMPILER_VAR_677;
i = i+1;
if ((i<len(fn->args))) {
char * ____BAH_COMPILER_VAR_678 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(unSerMembs);
long int strLen_1 = strlen(", ");
;                            
            ____BAH_COMPILER_VAR_678 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_678+currStrOff, unSerMembs, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_678+currStrOff, ", ", strLen_1);
            currStrOff += strLen_1;
        
        }unSerMembs = ____BAH_COMPILER_VAR_678;
}
};
char * ____BAH_COMPILER_VAR_679 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(sMembs);
long int strLen_1 = strlen("}");
long int strLen_2 = strlen("struct {\n");
;                            
            ____BAH_COMPILER_VAR_679 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_679+currStrOff, "struct {\n", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_679+currStrOff, sMembs, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_679+currStrOff, "}", strLen_1);
            currStrOff += strLen_1;
        
        }char * tmpArgsStruct = ____BAH_COMPILER_VAR_679;
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
char * ____BAH_COMPILER_VAR_680 =null;char * ____BAH_COMPILER_VAR_681 =sFnT.str(&sFnT);char * ____BAH_COMPILER_VAR_682 =fnName.str(&fnName);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpArgs);
long int strLen_1 = strlen(");\n    }; \n    \n    ");
long int strLen_2 = strlen(", &");
long int strLen_3 = strlen(fnWrapper);
long int strLen_4 = strlen("(&id, 0, ");
long int strLen_5 = strlen(tCreate);
long int strLen_6 = strlen("};\n        pthread_t id;\n        ");
long int strLen_7 = strlen(____BAH_COMPILER_VAR_681);
long int strLen_8 = strlen(" = {");
long int strLen_9 = strlen(tmpArgs);
long int strLen_10 = strlen(" ");
long int strLen_11 = strlen(tmpArgsStruct);
long int strLen_12 = strlen(");\n    };\n    {\n        ");
long int strLen_13 = strlen(unSerMembs);
long int strLen_14 = strlen("(");
long int strLen_15 = strlen(____BAH_COMPILER_VAR_682);
long int strLen_16 = strlen("* args) {\n        ");
long int strLen_17 = strlen(tmpArgsStruct);
long int strLen_18 = strlen("(");
long int strLen_19 = strlen(fnWrapper);
long int strLen_20 = strlen("\n    void ");
;                            
            ____BAH_COMPILER_VAR_680 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13+strLen_14+strLen_15+strLen_16+strLen_17+strLen_18+strLen_19+strLen_20);
            
                    memcpy(____BAH_COMPILER_VAR_680+currStrOff, "\n    void ", strLen_20);
                    currStrOff += strLen_20;
                    
                    memcpy(____BAH_COMPILER_VAR_680+currStrOff, fnWrapper, strLen_19);
                    currStrOff += strLen_19;
                    
                    memcpy(____BAH_COMPILER_VAR_680+currStrOff, "(", strLen_18);
                    currStrOff += strLen_18;
                    
                    memcpy(____BAH_COMPILER_VAR_680+currStrOff, tmpArgsStruct, strLen_17);
                    currStrOff += strLen_17;
                    
                    memcpy(____BAH_COMPILER_VAR_680+currStrOff, "* args) {\n        ", strLen_16);
                    currStrOff += strLen_16;
                    
                    memcpy(____BAH_COMPILER_VAR_680+currStrOff, ____BAH_COMPILER_VAR_682, strLen_15);
                    currStrOff += strLen_15;
                    
                    memcpy(____BAH_COMPILER_VAR_680+currStrOff, "(", strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_680+currStrOff, unSerMembs, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_680+currStrOff, ");\n    };\n    {\n        ", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_680+currStrOff, tmpArgsStruct, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_680+currStrOff, " ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_680+currStrOff, tmpArgs, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_680+currStrOff, " = {", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_680+currStrOff, ____BAH_COMPILER_VAR_681, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_680+currStrOff, "};\n        pthread_t id;\n        ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_680+currStrOff, tCreate, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_680+currStrOff, "(&id, 0, ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_680+currStrOff, fnWrapper, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_680+currStrOff, ", &", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_680+currStrOff, tmpArgs, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_680+currStrOff, ");\n    }; \n    \n    ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_680));
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
char * ____BAH_COMPILER_VAR_683 =getTypeFromToken(&nt,true,elems);struct string ntt = string(____BAH_COMPILER_VAR_683);
if ((ntt.hasPrefix(&ntt,"chan:")==0)) {
char * ____BAH_COMPILER_VAR_684 =null;char * ____BAH_COMPILER_VAR_685 =ntt.str(&ntt);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_685);
long int strLen_1 = strlen(") as channel.");
long int strLen_2 = strlen("Cannot use var {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_684 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_684+currStrOff, "Cannot use var {TOKEN} (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_684+currStrOff, ____BAH_COMPILER_VAR_685, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_684+currStrOff, ") as channel.", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_686 =____BAH_COMPILER_VAR_684;throwErr(&nt,____BAH_COMPILER_VAR_686);
}
ntt.trimLeft(&ntt,5);
if (isGlobal()) {
throwErr(&t,"Cannot receive ({TOKEN}) from a channel outside of a function.");
}
char * tmpV = "";
char * ____BAH_COMPILER_VAR_687 =ntt.str(&ntt);if (isRCPpointerType(____BAH_COMPILER_VAR_687)) {
char * ____BAH_COMPILER_VAR_688 =ntt.str(&ntt);struct string ct = getCType(____BAH_COMPILER_VAR_688,elems);
char * ____BAH_COMPILER_VAR_689 =null;char * ____BAH_COMPILER_VAR_690 =ct.str(&ct);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen("->receive(");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen(")");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_690);
long int strLen_6 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_689 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_689+currStrOff, "(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_689+currStrOff, ____BAH_COMPILER_VAR_690, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_689+currStrOff, ")", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_689+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_689+currStrOff, "->receive(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_689+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_689+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_689;
}
else {
char * ____BAH_COMPILER_VAR_691 =ntt.str(&ntt);struct string ct = getCType(____BAH_COMPILER_VAR_691,elems);
if (RCPavailable()) {
char * ____BAH_COMPILER_VAR_692 =null;char * ____BAH_COMPILER_VAR_693 =ntt.str(&ntt);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_693);
long int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_692 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_692+currStrOff, ____BAH_COMPILER_VAR_693, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_692+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_694 =null;char * ____BAH_COMPILER_VAR_695 =ct.str(&ct);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen("->receive(");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen("*)");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_695);
long int strLen_6 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_694 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_694+currStrOff, "(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_694+currStrOff, ____BAH_COMPILER_VAR_695, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_694+currStrOff, "*)", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_694+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_694+currStrOff, "->receive(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_694+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_694+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_696 =____BAH_COMPILER_VAR_692;tmpV = registerRCPvar(____BAH_COMPILER_VAR_696,____BAH_COMPILER_VAR_694,elems);
char * ____BAH_COMPILER_VAR_697 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("*");
long int strLen_1 = strlen(tmpV);
;                            
            ____BAH_COMPILER_VAR_697 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_697+currStrOff, "*", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_697+currStrOff, tmpV, strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_697;
}
else {
char * ____BAH_COMPILER_VAR_698 =null;char * ____BAH_COMPILER_VAR_699 =ct.str(&ct);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen("->receive(");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen("*)");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_699);
long int strLen_6 = strlen("*(");
;                            
            ____BAH_COMPILER_VAR_698 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_698+currStrOff, "*(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_698+currStrOff, ____BAH_COMPILER_VAR_699, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_698+currStrOff, "*)", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_698+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_698+currStrOff, "->receive(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_698+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_698+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_698;
}
}
t.type = TOKEN_TYPE_FUNC;
t.isFunc = true;
if (RCPavailable()) {
char * ____BAH_COMPILER_VAR_700 =ntt.str(&ntt);if (isRCPpointerType(____BAH_COMPILER_VAR_700)) {
char * ____BAH_COMPILER_VAR_701 =ntt.str(&ntt);tmpV = registerRCPvar(____BAH_COMPILER_VAR_701,t.cont,elems);
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
char * ____BAH_COMPILER_VAR_702 =getTypeFromToken(&pt,true,elems);struct string ptt = string(____BAH_COMPILER_VAR_702);
if ((ptt.hasPrefix(&ptt,"chan:")==0)) {
char * ____BAH_COMPILER_VAR_703 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ntt);
long int strLen_1 = strlen(") as channel.");
long int strLen_2 = strlen("Cannot use var {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_703 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_703+currStrOff, "Cannot use var {TOKEN} (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_703+currStrOff, ntt, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_703+currStrOff, ") as channel.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&pt,____BAH_COMPILER_VAR_703);
}
ptt.trimLeft(&ptt,5);
if (isGlobal()) {
throwErr(&t,"Cannot send ({TOKEN}) to a channel outside of a function.");
}
char * ____BAH_COMPILER_VAR_704 =ptt.str(&ptt);if ((compTypes(____BAH_COMPILER_VAR_704,ntt)==false)) {
char * ____BAH_COMPILER_VAR_705 =null;char * ____BAH_COMPILER_VAR_706 =ptt.str(&ptt);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_706);
long int strLen_1 = strlen(".");
long int strLen_2 = strlen(") to channel of type ");
long int strLen_3 = strlen(ntt);
long int strLen_4 = strlen("Cannot send {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_705 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_705+currStrOff, "Cannot send {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_705+currStrOff, ntt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_705+currStrOff, ") to channel of type ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_705+currStrOff, ____BAH_COMPILER_VAR_706, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_705+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_707 =____BAH_COMPILER_VAR_705;throwErr(&nt,____BAH_COMPILER_VAR_707);
}
i++;
char * ____BAH_COMPILER_VAR_708 =ptt.str(&ptt);if (isRCPpointerType(____BAH_COMPILER_VAR_708)) {
char * ____BAH_COMPILER_VAR_709 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen(");\n");
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(pt.cont);
long int strLen_4 = strlen("->send(");
long int strLen_5 = strlen(pt.cont);
;                            
            ____BAH_COMPILER_VAR_709 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_709+currStrOff, pt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_709+currStrOff, "->send(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_709+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_709+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_709+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_709+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_709));
}
else {
struct string ct = getCType(ntt,elems);
char * tmpV = genCompilerVar();
char * ____BAH_COMPILER_VAR_710 =null;char * ____BAH_COMPILER_VAR_711 =ct.str(&ct);
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
long int strLen_13 = strlen(____BAH_COMPILER_VAR_711);
long int strLen_14 = strlen("\n                    ");
;                            
            ____BAH_COMPILER_VAR_710 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13+strLen_14);
            
                    memcpy(____BAH_COMPILER_VAR_710+currStrOff, "\n                    ", strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_710+currStrOff, ____BAH_COMPILER_VAR_711, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_710+currStrOff, " ", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_710+currStrOff, tmpV, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_710+currStrOff, " = ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_710+currStrOff, nt.cont, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_710+currStrOff, ";\n                    ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_710+currStrOff, pt.cont, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_710+currStrOff, "->sendAny(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_710+currStrOff, pt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_710+currStrOff, ", &", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_710+currStrOff, tmpV, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_710+currStrOff, ", sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_710+currStrOff, tmpV, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_710+currStrOff, "));\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_710));
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
char * ____BAH_COMPILER_VAR_712 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnt.ogCont);
long int strLen_1 = strlen(t.ogCont);
;                            
            ____BAH_COMPILER_VAR_712 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_712+currStrOff, fnt.ogCont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_712+currStrOff, t.ogCont, strLen_1);
            currStrOff += strLen_1;
        
        }fnt.ogCont = ____BAH_COMPILER_VAR_712;
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
char * ____BAH_COMPILER_VAR_713 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnt.cont);
long int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_713 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_713+currStrOff, fnt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_713+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_713;
};
char * ____BAH_COMPILER_VAR_714 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnt.cont);
long int strLen_1 = strlen(")");
;                            
            ____BAH_COMPILER_VAR_714 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_714+currStrOff, fnt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_714+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_714;

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
char * ____BAH_COMPILER_VAR_715 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fn->name);
long int strLen_1 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_715 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_715+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_715+currStrOff, "(", strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_715;
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
char * ____BAH_COMPILER_VAR_716 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fn->name);
long int strLen_1 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_716 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_716+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_716+currStrOff, "(", strLen_1);
            currStrOff += strLen_1;
        
        }fnt.ogCont = ____BAH_COMPILER_VAR_716;
for (; (i<len(l)); i++) {
struct Tok t = l->data[i];
char * ____BAH_COMPILER_VAR_717 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnt.ogCont);
long int strLen_1 = strlen(t.ogCont);
;                            
            ____BAH_COMPILER_VAR_717 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_717+currStrOff, fnt.ogCont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_717+currStrOff, t.ogCont, strLen_1);
            currStrOff += strLen_1;
        
        }fnt.ogCont = ____BAH_COMPILER_VAR_717;
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
char * ____BAH_COMPILER_VAR_718 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnt.cont);
long int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_718 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_718+currStrOff, fnt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_718+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_718;
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
char * ____BAH_COMPILER_VAR_719 =null;char * ____BAH_COMPILER_VAR_720 =intToStr(fnt.line);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_720);
long int strLen_1 = strlen("\"");
long int strLen_2 = strlen(":");
long int strLen_3 = strlen(compilerState.currentFile);
long int strLen_4 = strlen("\"");
;                            
            ____BAH_COMPILER_VAR_719 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_719+currStrOff, "\"", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_719+currStrOff, compilerState.currentFile, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_719+currStrOff, ":", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_719+currStrOff, ____BAH_COMPILER_VAR_720, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_719+currStrOff, "\"", strLen_1);
            currStrOff += strLen_1;
        
        }char * currLine = ____BAH_COMPILER_VAR_719;
if ((strcmp(fn->name, "panic") == 0)) {
struct Tok ____BAH_COMPILER_VAR_721 = {};
____BAH_COMPILER_VAR_721.cont = "";
____BAH_COMPILER_VAR_721.ogCont = "";
____BAH_COMPILER_VAR_721.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_721.pos = 0;
____BAH_COMPILER_VAR_721.line = 1;
____BAH_COMPILER_VAR_721.begLine = 1;
____BAH_COMPILER_VAR_721.bahType = "";
____BAH_COMPILER_VAR_721.isValue = false;
____BAH_COMPILER_VAR_721.isFunc = false;
____BAH_COMPILER_VAR_721.isOper = false;
____BAH_COMPILER_VAR_721.isEqual = false;
____BAH_COMPILER_VAR_721.pass = false;
____BAH_COMPILER_VAR_721.bahRef= null;
____BAH_COMPILER_VAR_721.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_721.cont = ",";
____BAH_COMPILER_VAR_721.line = fnt.line;

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] = ____BAH_COMPILER_VAR_721;
memory->length = nLength+1;
} else {
memory->data[len(memory)] = ____BAH_COMPILER_VAR_721;
}
};
struct Tok ____BAH_COMPILER_VAR_722 = {};
____BAH_COMPILER_VAR_722.cont = "";
____BAH_COMPILER_VAR_722.ogCont = "";
____BAH_COMPILER_VAR_722.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_722.pos = 0;
____BAH_COMPILER_VAR_722.line = 1;
____BAH_COMPILER_VAR_722.begLine = 1;
____BAH_COMPILER_VAR_722.bahType = "";
____BAH_COMPILER_VAR_722.isValue = false;
____BAH_COMPILER_VAR_722.isFunc = false;
____BAH_COMPILER_VAR_722.isOper = false;
____BAH_COMPILER_VAR_722.isEqual = false;
____BAH_COMPILER_VAR_722.pass = false;
____BAH_COMPILER_VAR_722.bahRef= null;
____BAH_COMPILER_VAR_722.type = TOKEN_TYPE_STR;
____BAH_COMPILER_VAR_722.cont = currLine;
____BAH_COMPILER_VAR_722.line = fnt.line;

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] = ____BAH_COMPILER_VAR_722;
memory->length = nLength+1;
} else {
memory->data[len(memory)] = ____BAH_COMPILER_VAR_722;
}
};
fn = searchFunc("__BAH_panic",elems,true);
char * ____BAH_COMPILER_VAR_723 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fn->name);
long int strLen_1 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_723 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_723+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_723+currStrOff, "(", strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_723;
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
struct variable* ____BAH_COMPILER_VAR_724 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_724->name = "";
____BAH_COMPILER_VAR_724->type = "";
____BAH_COMPILER_VAR_724->isConst = false;
____BAH_COMPILER_VAR_724->constVal = "";
____BAH_COMPILER_VAR_724->isArray = false;
____BAH_COMPILER_VAR_724->from = "";
____BAH_COMPILER_VAR_724->declScope= null;
____BAH_COMPILER_VAR_724->isGlobal = false;
____BAH_COMPILER_VAR_724->declRope= null;
____BAH_COMPILER_VAR_724->isReg = false;
____BAH_COMPILER_VAR_724->name = genCompilerVar();
____BAH_COMPILER_VAR_724->type = "[]reflectElement";
____BAH_COMPILER_VAR_724->isArray = true;
struct variable* tmpV = ____BAH_COMPILER_VAR_724;
char * decls = "";
j = 0;
for (; (j<len(symbols)); j++) {
struct variable* v = symbols->data[j];
char * vname = v->name;
if ((strCount(v->type,"*")==0)) {
char * ____BAH_COMPILER_VAR_725 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("&");
long int strLen_1 = strlen(v->name);
;                            
            ____BAH_COMPILER_VAR_725 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_725+currStrOff, "&", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_725+currStrOff, v->name, strLen_1);
            currStrOff += strLen_1;
        
        }vname = ____BAH_COMPILER_VAR_725;
}
struct Tok ____BAH_COMPILER_VAR_726 = {};
____BAH_COMPILER_VAR_726.cont = "";
____BAH_COMPILER_VAR_726.ogCont = "";
____BAH_COMPILER_VAR_726.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_726.pos = 0;
____BAH_COMPILER_VAR_726.line = 1;
____BAH_COMPILER_VAR_726.begLine = 1;
____BAH_COMPILER_VAR_726.bahType = "";
____BAH_COMPILER_VAR_726.isValue = false;
____BAH_COMPILER_VAR_726.isFunc = false;
____BAH_COMPILER_VAR_726.isOper = false;
____BAH_COMPILER_VAR_726.isEqual = false;
____BAH_COMPILER_VAR_726.pass = false;
____BAH_COMPILER_VAR_726.bahRef= null;
____BAH_COMPILER_VAR_726.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_726.cont = vname;
____BAH_COMPILER_VAR_726.bahType = v->type;
____BAH_COMPILER_VAR_726.isValue = true;
#define tmpT ____BAH_COMPILER_VAR_726
tmpT = parseReflect(tmpT,v->type,elems,true,v->name,"0");
char * ____BAH_COMPILER_VAR_727 =null;char * ____BAH_COMPILER_VAR_728 =intToStr(j);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpT.cont);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen("] = ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_728);
long int strLen_4 = strlen("->data[");
long int strLen_5 = strlen(tmpV->name);
;                            
            ____BAH_COMPILER_VAR_727 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_727+currStrOff, tmpV->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_727+currStrOff, "->data[", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_727+currStrOff, ____BAH_COMPILER_VAR_728, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_727+currStrOff, "] = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_727+currStrOff, tmpT.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_727+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_729 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(decls);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_727);
;                            
            ____BAH_COMPILER_VAR_729 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_729+currStrOff, decls, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_729+currStrOff, ____BAH_COMPILER_VAR_727, strLen_1);
            currStrOff += strLen_1;
        
        }decls = ____BAH_COMPILER_VAR_729;

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
char * ____BAH_COMPILER_VAR_730 =null;char * ____BAH_COMPILER_VAR_731 =intToStr(len(symbols));char * ____BAH_COMPILER_VAR_732 =intToStr(len(symbols));
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(decls);
long int strLen_1 = strlen("\n        ");
long int strLen_2 = strlen("->elemSize = sizeof(struct reflectElement);\n        ");
long int strLen_3 = strlen(tmpV->name);
long int strLen_4 = strlen(";\n        ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_731);
long int strLen_6 = strlen("->length = ");
long int strLen_7 = strlen(tmpV->name);
long int strLen_8 = strlen(");\n        ");
long int strLen_9 = strlen(____BAH_COMPILER_VAR_732);
long int strLen_10 = strlen("->data = memoryAlloc(sizeof(struct reflectElement) * ");
long int strLen_11 = strlen(tmpV->name);
long int strLen_12 = strlen(" = memoryAlloc(sizeof(array(struct reflectElement)));\n        ");
long int strLen_13 = strlen(tmpV->name);
long int strLen_14 = strlen("\n        array(struct reflectElement)* ");
;                            
            ____BAH_COMPILER_VAR_730 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13+strLen_14);
            
                    memcpy(____BAH_COMPILER_VAR_730+currStrOff, "\n        array(struct reflectElement)* ", strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_730+currStrOff, tmpV->name, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_730+currStrOff, " = memoryAlloc(sizeof(array(struct reflectElement)));\n        ", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_730+currStrOff, tmpV->name, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_730+currStrOff, "->data = memoryAlloc(sizeof(struct reflectElement) * ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_730+currStrOff, ____BAH_COMPILER_VAR_732, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_730+currStrOff, ");\n        ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_730+currStrOff, tmpV->name, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_730+currStrOff, "->length = ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_730+currStrOff, ____BAH_COMPILER_VAR_731, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_730+currStrOff, ";\n        ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_730+currStrOff, tmpV->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_730+currStrOff, "->elemSize = sizeof(struct reflectElement);\n        ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_730+currStrOff, decls, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_730+currStrOff, "\n        ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_730));
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
____BAH_COMPILER_VAR_733.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_733.cont = tmpV->name;
____BAH_COMPILER_VAR_733.line = fnt.line;
____BAH_COMPILER_VAR_733.isValue = true;

{
long nLength = 0;
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[0] = ____BAH_COMPILER_VAR_733;
memory->length = nLength+1;
} else {
memory->data[0] = ____BAH_COMPILER_VAR_733;
}
};
}
else if ((strcmp(fn->name, "breakPoint") == 0)) {
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
____BAH_COMPILER_VAR_734.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_734.cont = "__dumpSymbols";
____BAH_COMPILER_VAR_734.line = fnt.line;
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
____BAH_COMPILER_VAR_735.cont = "(";
____BAH_COMPILER_VAR_735.line = fnt.line;
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
____BAH_COMPILER_VAR_736.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_736.cont = ")";
____BAH_COMPILER_VAR_736.line = fnt.line;
memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 3;
memory->elemSize = sizeof(struct Tok);
memory->data = memoryAlloc(sizeof(struct Tok) * 50);memory->data[0] = ____BAH_COMPILER_VAR_734;
memory->data[1] = ____BAH_COMPILER_VAR_735;
memory->data[2] = ____BAH_COMPILER_VAR_736;
memory = prePross(memory,LINE_TYPE_FN_CALL,elems);
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
____BAH_COMPILER_VAR_737.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_737.cont = ",";
____BAH_COMPILER_VAR_737.line = fnt.line;

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] = ____BAH_COMPILER_VAR_737;
memory->length = nLength+1;
} else {
memory->data[len(memory)] = ____BAH_COMPILER_VAR_737;
}
};
struct Tok ____BAH_COMPILER_VAR_738 = {};
____BAH_COMPILER_VAR_738.cont = "";
____BAH_COMPILER_VAR_738.ogCont = "";
____BAH_COMPILER_VAR_738.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_738.pos = 0;
____BAH_COMPILER_VAR_738.line = 1;
____BAH_COMPILER_VAR_738.begLine = 1;
____BAH_COMPILER_VAR_738.bahType = "";
____BAH_COMPILER_VAR_738.isValue = false;
____BAH_COMPILER_VAR_738.isFunc = false;
____BAH_COMPILER_VAR_738.isOper = false;
____BAH_COMPILER_VAR_738.isEqual = false;
____BAH_COMPILER_VAR_738.pass = false;
____BAH_COMPILER_VAR_738.bahRef= null;
____BAH_COMPILER_VAR_738.type = TOKEN_TYPE_STR;
____BAH_COMPILER_VAR_738.cont = currLine;
____BAH_COMPILER_VAR_738.line = fnt.line;

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] = ____BAH_COMPILER_VAR_738;
memory->length = nLength+1;
} else {
memory->data[len(memory)] = ____BAH_COMPILER_VAR_738;
}
};
fn = searchFunc("breakPoint__inner",elems,true);
char * ____BAH_COMPILER_VAR_739 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fn->name);
long int strLen_1 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_739 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_739+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_739+currStrOff, "(", strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_739;
}
else if ((strcmp(fn->name, "sizeof") == 0)) {
char * tp = "";
register long int j = 0;
for (; (j<len(memory)); j++) {
struct Tok tmpT = memory->data[j];
char * ____BAH_COMPILER_VAR_740 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tp);
long int strLen_1 = strlen(tmpT.cont);
;                            
            ____BAH_COMPILER_VAR_740 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_740+currStrOff, tp, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_740+currStrOff, tmpT.cont, strLen_1);
            currStrOff += strLen_1;
        
        }tp = ____BAH_COMPILER_VAR_740;
};
struct string cType = getCType(tp,elems);
char * ____BAH_COMPILER_VAR_741 =null;char * ____BAH_COMPILER_VAR_742 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_742);
long int strLen_1 = strlen(")");
;                            
            ____BAH_COMPILER_VAR_741 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_741+currStrOff, ____BAH_COMPILER_VAR_742, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_741+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_743 =null;char * ____BAH_COMPILER_VAR_744 =____BAH_COMPILER_VAR_741;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnt.cont);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_744);
;                            
            ____BAH_COMPILER_VAR_743 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_743+currStrOff, fnt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_743+currStrOff, ____BAH_COMPILER_VAR_744, strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_743;
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
char * ____BAH_COMPILER_VAR_745 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(amp);
long int strLen_1 = strlen(parent->name);
;                            
            ____BAH_COMPILER_VAR_745 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_745+currStrOff, amp, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_745+currStrOff, parent->name, strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_746 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnt.cont);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_745);
;                            
            ____BAH_COMPILER_VAR_746 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_746+currStrOff, fnt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_746+currStrOff, ____BAH_COMPILER_VAR_745, strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_746;
argIndex++;
if ((len(fn->args)>argIndex)) {
char * ____BAH_COMPILER_VAR_747 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnt.cont);
long int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_747 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_747+currStrOff, fnt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_747+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_747;
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
char * ____BAH_COMPILER_VAR_748 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(arg->type);
long int strLen_1 = strlen(" in function call.");
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(tt);
long int strLen_4 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_748 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_748+currStrOff, "Cannot use {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_748+currStrOff, tt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_748+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_748+currStrOff, arg->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_748+currStrOff, " in function call.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&t,____BAH_COMPILER_VAR_748);
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
char * ____BAH_COMPILER_VAR_749 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnt.cont);
long int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_749 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_749+currStrOff, fnt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_749+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_749;
argIndex++;
if ((j+1<len(memory))) {
j++;
t = memory->data[j];
if ((strcmp(t.cont, ",") != 0)) {
throwErr(&t,"Need separator between arguments, not {TOKEN}.");
}
char * ____BAH_COMPILER_VAR_750 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnt.cont);
long int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_750 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_750+currStrOff, fnt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_750+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_750;
}
};
if ((argIndex!=len(fn->args))) {
struct Tok lt = l->data[tokPos];
char * ____BAH_COMPILER_VAR_751 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fn->name);
long int strLen_1 = strlen("'.");
long int strLen_2 = strlen("Not enough argument {TOKEN}, calling '");
;                            
            ____BAH_COMPILER_VAR_751 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_751+currStrOff, "Not enough argument {TOKEN}, calling '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_751+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_751+currStrOff, "'.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&lt,____BAH_COMPILER_VAR_751);
}
fnt.bahRef = fn;
char * ____BAH_COMPILER_VAR_752 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnt.cont);
long int strLen_1 = strlen(")");
;                            
            ____BAH_COMPILER_VAR_752 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_752+currStrOff, fnt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_752+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_752;

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
char * ____BAH_COMPILER_VAR_753 =null;char * ____BAH_COMPILER_VAR_754 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(";\n                ");
long int strLen_2 = strlen(" = ");
long int strLen_3 = strlen(tmpV);
long int strLen_4 = strlen(" ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_754);
long int strLen_6 = strlen("\n                ");
;                            
            ____BAH_COMPILER_VAR_753 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_753+currStrOff, "\n                ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_753+currStrOff, ____BAH_COMPILER_VAR_754, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_753+currStrOff, " ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_753+currStrOff, tmpV, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_753+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_753+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_753+currStrOff, ";\n                ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_753));
t.cont = tmpV;
struct variable* ____BAH_COMPILER_VAR_755 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_755->name = "";
____BAH_COMPILER_VAR_755->type = "";
____BAH_COMPILER_VAR_755->isConst = false;
____BAH_COMPILER_VAR_755->constVal = "";
____BAH_COMPILER_VAR_755->isArray = false;
____BAH_COMPILER_VAR_755->from = "";
____BAH_COMPILER_VAR_755->declScope= null;
____BAH_COMPILER_VAR_755->isGlobal = false;
____BAH_COMPILER_VAR_755->declRope= null;
____BAH_COMPILER_VAR_755->isReg = false;
____BAH_COMPILER_VAR_755->name = tmpV;
____BAH_COMPILER_VAR_755->type = tt;
parent = ____BAH_COMPILER_VAR_755;
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
char * ____BAH_COMPILER_VAR_756 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s->name);
long int strLen_1 = strlen(".");
long int strLen_2 = strlen("Unknown method {TOKEN} in struct ");
;                            
            ____BAH_COMPILER_VAR_756 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_756+currStrOff, "Unknown method {TOKEN} in struct ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_756+currStrOff, s->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_756+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&nt,____BAH_COMPILER_VAR_756);
}
struct func* ____BAH_COMPILER_VAR_757 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_757->name = "";
____BAH_COMPILER_VAR_757->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_757->args->length = 0;
            ____BAH_COMPILER_VAR_757->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_757->returns= null;
____BAH_COMPILER_VAR_757->isBinding = false;
____BAH_COMPILER_VAR_757->from = "";
____BAH_COMPILER_VAR_757->file = "";
____BAH_COMPILER_VAR_757->line = 1;
____BAH_COMPILER_VAR_757->used = false;
____BAH_COMPILER_VAR_757->code = null;
struct func* nfn = ____BAH_COMPILER_VAR_757;
*nfn = *fn;
nfn->name = nt.cont;
valueFunc(nfn,parent,l,i,ltp,elems);
struct Tok fnt = l->data[i];
delete(l,i);
char * ____BAH_COMPILER_VAR_758 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(".");
long int strLen_1 = strlen(nt.ogCont);
long int strLen_2 = strlen(t.ogCont);
;                            
            ____BAH_COMPILER_VAR_758 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_758+currStrOff, t.ogCont, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_758+currStrOff, ".", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_758+currStrOff, nt.ogCont, strLen_1);
            currStrOff += strLen_1;
        
        }fnt.ogCont = ____BAH_COMPILER_VAR_758;
fnt.pos = t.pos;
char * ____BAH_COMPILER_VAR_759 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(sep);
long int strLen_1 = strlen(fnt.cont);
long int strLen_2 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_759 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_759+currStrOff, t.cont, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_759+currStrOff, sep, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_759+currStrOff, fnt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_759;

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
char * ____BAH_COMPILER_VAR_760 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s->name);
long int strLen_1 = strlen("'.");
long int strLen_2 = strlen("Unknown struct member {TOKEN} in struct '");
;                            
            ____BAH_COMPILER_VAR_760 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_760+currStrOff, "Unknown struct member {TOKEN} in struct '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_760+currStrOff, s->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_760+currStrOff, "'.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&nt,____BAH_COMPILER_VAR_760);
}
char * ____BAH_COMPILER_VAR_761 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(sep);
long int strLen_1 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_761 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_761+currStrOff, sep, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_761+currStrOff, nt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_762 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_761);
;                            
            ____BAH_COMPILER_VAR_762 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_762+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_762+currStrOff, ____BAH_COMPILER_VAR_761, strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_762;
char * ____BAH_COMPILER_VAR_763 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(".");
long int strLen_1 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_763 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_763+currStrOff, ".", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_763+currStrOff, nt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_764 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t.ogCont);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_763);
;                            
            ____BAH_COMPILER_VAR_764 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_764+currStrOff, t.ogCont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_764+currStrOff, ____BAH_COMPILER_VAR_763, strLen_1);
            currStrOff += strLen_1;
        
        }t.ogCont = ____BAH_COMPILER_VAR_764;
t.bahType = m->type;
struct variable* ____BAH_COMPILER_VAR_765 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_765->name = "";
____BAH_COMPILER_VAR_765->type = "";
____BAH_COMPILER_VAR_765->isConst = false;
____BAH_COMPILER_VAR_765->constVal = "";
____BAH_COMPILER_VAR_765->isArray = false;
____BAH_COMPILER_VAR_765->from = "";
____BAH_COMPILER_VAR_765->declScope= null;
____BAH_COMPILER_VAR_765->isGlobal = false;
____BAH_COMPILER_VAR_765->declRope= null;
____BAH_COMPILER_VAR_765->isReg = false;
____BAH_COMPILER_VAR_765->name = t.cont;
____BAH_COMPILER_VAR_765->type = t.bahType;
t.bahRef = ____BAH_COMPILER_VAR_765;

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
char * ____BAH_COMPILER_VAR_766 =getTypeFromToken(&pt,true,elems);struct string ptt = string(____BAH_COMPILER_VAR_766);
struct Tok t = pt;
t.isValue = true;
char * ____BAH_COMPILER_VAR_767 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t.ogCont);
long int strLen_1 = strlen("[");
;                            
            ____BAH_COMPILER_VAR_767 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_767+currStrOff, t.ogCont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_767+currStrOff, "[", strLen_1);
            currStrOff += strLen_1;
        
        }t.ogCont = ____BAH_COMPILER_VAR_767;
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
char * ____BAH_COMPILER_VAR_768 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t.ogCont);
long int strLen_1 = strlen("]");
;                            
            ____BAH_COMPILER_VAR_768 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_768+currStrOff, t.ogCont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_768+currStrOff, "]", strLen_1);
            currStrOff += strLen_1;
        
        }t.ogCont = ____BAH_COMPILER_VAR_768;
if ((nbEncls==0)) {
break;
}
}
char * ____BAH_COMPILER_VAR_769 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t.ogCont);
long int strLen_1 = strlen(tmpT.ogCont);
;                            
            ____BAH_COMPILER_VAR_769 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_769+currStrOff, t.ogCont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_769+currStrOff, tmpT.ogCont, strLen_1);
            currStrOff += strLen_1;
        
        }t.ogCont = ____BAH_COMPILER_VAR_769;

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
char * ____BAH_COMPILER_VAR_770 =getTypeFromToken(&index,true,elems);if ((compTypes(____BAH_COMPILER_VAR_770,"int")==false)) {
throwErr(&index,"Cannot use {TOKEN} as array index (int).");
}
char * ____BAH_COMPILER_VAR_771 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(index.cont);
long int strLen_1 = strlen("]");
long int strLen_2 = strlen("->data[");
long int strLen_3 = strlen(pt.cont);
;                            
            ____BAH_COMPILER_VAR_771 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_771+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_771+currStrOff, "->data[", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_771+currStrOff, index.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_771+currStrOff, "]", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_771;
ptt.trimLeft(&ptt,2);
t.bahType = ptt.str(&ptt);
}
else {
t.bahType = ptt.str(&ptt);
if ((strcmp(to, "") == 0)) {
char * ____BAH_COMPILER_VAR_772 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen("->length");
;                            
            ____BAH_COMPILER_VAR_772 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_772+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_772+currStrOff, "->length", strLen_1);
            currStrOff += strLen_1;
        
        }to = ____BAH_COMPILER_VAR_772;
}
char * ____BAH_COMPILER_VAR_773 =null;
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
            ____BAH_COMPILER_VAR_773 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_773+currStrOff, "arraySubstitute(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_773+currStrOff, pt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_773+currStrOff, ", ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_773+currStrOff, from, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_773+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_773+currStrOff, to, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_773+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_773;
}
}
else if (ptt.hasPrefix(&ptt,"buffer:")) {
if ((split==false)) {
t.bahType = "char";
struct Tok index = memory->data[0];
char * ____BAH_COMPILER_VAR_774 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(index.cont);
long int strLen_1 = strlen("]");
long int strLen_2 = strlen("[");
long int strLen_3 = strlen(pt.cont);
;                            
            ____BAH_COMPILER_VAR_774 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_774+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_774+currStrOff, "[", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_774+currStrOff, index.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_774+currStrOff, "]", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_774;
}
else {
t.bahType = "cpstring";
if ((strcmp(to, "") == 0)) {
char * ____BAH_COMPILER_VAR_775 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen("strlen(");
;                            
            ____BAH_COMPILER_VAR_775 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_775+currStrOff, "strlen(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_775+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_775+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }to = ____BAH_COMPILER_VAR_775;
}
char * ____BAH_COMPILER_VAR_776 =null;
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
            ____BAH_COMPILER_VAR_776 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_776+currStrOff, "cpstringSubsitute(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_776+currStrOff, pt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_776+currStrOff, ", ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_776+currStrOff, from, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_776+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_776+currStrOff, to, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_776+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_776;
}
}
else if (ptt.hasPrefix(&ptt,"map:")) {
if ((split==true)) {
throwErr(&pt,"Cannot do substitution on a map {TOKEN}.");
}
ptt.trimLeft(&ptt,4);
char * ____BAH_COMPILER_VAR_777 =ptt.str(&ptt);struct string elemType = getCType(____BAH_COMPILER_VAR_777,elems);
struct Tok index = memory->data[0];
if ((tokPos==0)&&(ltp==LINE_TYPE_VAR)) {
struct variable* ____BAH_COMPILER_VAR_778 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_778->name = "";
____BAH_COMPILER_VAR_778->type = "";
____BAH_COMPILER_VAR_778->isConst = false;
____BAH_COMPILER_VAR_778->constVal = "";
____BAH_COMPILER_VAR_778->isArray = false;
____BAH_COMPILER_VAR_778->from = "";
____BAH_COMPILER_VAR_778->declScope= null;
____BAH_COMPILER_VAR_778->isGlobal = false;
____BAH_COMPILER_VAR_778->declRope= null;
____BAH_COMPILER_VAR_778->isReg = false;
____BAH_COMPILER_VAR_778->name = genCompilerVar();
____BAH_COMPILER_VAR_778->type = ptt.str(&ptt);
struct variable* tmpV = ____BAH_COMPILER_VAR_778;

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
        
        }INIT = INIT->add(INIT, rope(____BAH_COMPILER_VAR_779));
}
else {
char * ____BAH_COMPILER_VAR_781 =null;char * ____BAH_COMPILER_VAR_782 =elemType.str(&elemType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpV->name);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_782);
;                            
            ____BAH_COMPILER_VAR_781 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_781+currStrOff, ____BAH_COMPILER_VAR_782, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_781+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_781+currStrOff, tmpV->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_781+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_781));
}
char * ____BAH_COMPILER_VAR_783 =ptt.str(&ptt);if (isRCPpointerType(____BAH_COMPILER_VAR_783)) {
char * ____BAH_COMPILER_VAR_784 =null;
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
            ____BAH_COMPILER_VAR_784 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7);
            
                    memcpy(____BAH_COMPILER_VAR_784+currStrOff, t.cont, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_784+currStrOff, "->set(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_784+currStrOff, pt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_784+currStrOff, ", ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_784+currStrOff, index.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_784+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_784+currStrOff, tmpV->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_784+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }NEXT_LINE = ____BAH_COMPILER_VAR_784;
}
else {
char * ____BAH_COMPILER_VAR_785 =null;char * ____BAH_COMPILER_VAR_786 =elemType.str(&elemType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_786);
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
            ____BAH_COMPILER_VAR_785 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9);
            
                    memcpy(____BAH_COMPILER_VAR_785+currStrOff, t.cont, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_785+currStrOff, "->setAny(", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_785+currStrOff, pt.cont, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_785+currStrOff, ", ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_785+currStrOff, index.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_785+currStrOff, ", &", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_785+currStrOff, tmpV->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_785+currStrOff, ", sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_785+currStrOff, ____BAH_COMPILER_VAR_786, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_785+currStrOff, "));\n", strLen_1);
            currStrOff += strLen_1;
        
        }NEXT_LINE = ____BAH_COMPILER_VAR_785;
}
t.cont = tmpV->name;
t.bahType = ptt.str(&ptt);
}
else {
t.isFunc = true;
char * ____BAH_COMPILER_VAR_787 =ptt.str(&ptt);if (isRCPpointerType(____BAH_COMPILER_VAR_787)) {
char * ____BAH_COMPILER_VAR_788 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(index.cont);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(t.cont);
long int strLen_4 = strlen("->get(");
;                            
            ____BAH_COMPILER_VAR_788 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_788+currStrOff, "->get(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_788+currStrOff, t.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_788+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_788+currStrOff, index.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_788+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_789 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_788);
;                            
            ____BAH_COMPILER_VAR_789 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_789+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_789+currStrOff, ____BAH_COMPILER_VAR_788, strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_789;
}
else {
char * tmpV = genCompilerVar();
char * ____BAH_COMPILER_VAR_790 =null;char * ____BAH_COMPILER_VAR_791 =elemType.str(&elemType);
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
long int strLen_9 = strlen(____BAH_COMPILER_VAR_791);
;                            
            ____BAH_COMPILER_VAR_790 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9);
            
                    memcpy(____BAH_COMPILER_VAR_790+currStrOff, ____BAH_COMPILER_VAR_791, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_790+currStrOff, "* ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_790+currStrOff, tmpV, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_790+currStrOff, "=", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_790+currStrOff, pt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_790+currStrOff, "->get(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_790+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_790+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_790+currStrOff, index.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_790+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }struct rope* res = rope(____BAH_COMPILER_VAR_790);
char * ____BAH_COMPILER_VAR_792 =null;char * ____BAH_COMPILER_VAR_793 =elemType.str(&elemType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpV);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen(")(*");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_793);
long int strLen_4 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_792 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_792+currStrOff, "(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_792+currStrOff, ____BAH_COMPILER_VAR_793, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_792+currStrOff, ")(*", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_792+currStrOff, tmpV, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_792+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_792;
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
char * ____BAH_COMPILER_VAR_794 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(index.cont);
long int strLen_1 = strlen("]");
long int strLen_2 = strlen("[");
long int strLen_3 = strlen(pt.cont);
;                            
            ____BAH_COMPILER_VAR_794 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_794+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_794+currStrOff, "[", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_794+currStrOff, index.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_794+currStrOff, "]", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_794;
}
else {
if ((strcmp(to, "") == 0)) {
char * ____BAH_COMPILER_VAR_795 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen("strlen(");
;                            
            ____BAH_COMPILER_VAR_795 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_795+currStrOff, "strlen(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_795+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_795+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }to = ____BAH_COMPILER_VAR_795;
}
char * ____BAH_COMPILER_VAR_796 =null;
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
            ____BAH_COMPILER_VAR_796 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_796+currStrOff, "cpstringSubsitute(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_796+currStrOff, pt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_796+currStrOff, ", ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_796+currStrOff, from, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_796+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_796+currStrOff, to, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_796+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_796;
}
}
else {
char * ____BAH_COMPILER_VAR_797 =null;char * ____BAH_COMPILER_VAR_798 =ptt.str(&ptt);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_798);
long int strLen_1 = strlen(") as array.");
long int strLen_2 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_797 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_797+currStrOff, "Cannot use {TOKEN} (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_797+currStrOff, ____BAH_COMPILER_VAR_798, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_797+currStrOff, ") as array.", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_799 =____BAH_COMPILER_VAR_797;throwErr(&pt,____BAH_COMPILER_VAR_799);
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
char * ____BAH_COMPILER_VAR_800 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("register ");
long int strLen_1 = strlen(odecl);
;                            
            ____BAH_COMPILER_VAR_800 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_800+currStrOff, "register ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_800+currStrOff, odecl, strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT->totalLen = OUTPUT->totalLen+ropeSet(v->declRope,____BAH_COMPILER_VAR_800);
}
v->isReg = true;
}
}
struct Tok nt = l->data[tokPos];
char * ntt = getTypeFromToken(&nt,true,elems);
if ((strcmp(t.cont, "in") == 0)) {
struct string arrT = string(ntt);
if ((arrT.hasPrefix(&arrT,"[]")==0)) {
char * ____BAH_COMPILER_VAR_801 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ntt);
long int strLen_1 = strlen(") as array.");
long int strLen_2 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_801 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_801+currStrOff, "Cannot use {TOKEN} (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_801+currStrOff, ntt, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_801+currStrOff, ") as array.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&nt,____BAH_COMPILER_VAR_801);
}
arrT.trimLeft(&arrT,2);
char * ____BAH_COMPILER_VAR_802 =arrT.str(&arrT);if ((compTypes(ptt,____BAH_COMPILER_VAR_802)==false)) {
char * ____BAH_COMPILER_VAR_803 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ntt);
long int strLen_1 = strlen(".");
long int strLen_2 = strlen(") in ");
long int strLen_3 = strlen(ptt);
long int strLen_4 = strlen("Cannot search for {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_803 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_803+currStrOff, "Cannot search for {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_803+currStrOff, ptt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_803+currStrOff, ") in ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_803+currStrOff, ntt, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_803+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&pt,____BAH_COMPILER_VAR_803);
}
char * compVar = genCompilerVar();
char * comp = "";
if ((strcmp(ptt, "cpstring") == 0)) {
char * ____BAH_COMPILER_VAR_804 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(") == 0");
long int strLen_2 = strlen("->data[i], ");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen("->data[i] != 0 && strcmp(");
long int strLen_5 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_804 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_804+currStrOff, nt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_804+currStrOff, "->data[i] != 0 && strcmp(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_804+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_804+currStrOff, "->data[i], ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_804+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_804+currStrOff, ") == 0", strLen_1);
            currStrOff += strLen_1;
        
        }comp = ____BAH_COMPILER_VAR_804;
}
else {
char * ____BAH_COMPILER_VAR_805 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("->data[i] == ");
long int strLen_1 = strlen(pt.cont);
long int strLen_2 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_805 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_805+currStrOff, nt.cont, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_805+currStrOff, "->data[i] == ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_805+currStrOff, pt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }comp = ____BAH_COMPILER_VAR_805;
}
char * ____BAH_COMPILER_VAR_806 =null;
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
            ____BAH_COMPILER_VAR_806 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_806+currStrOff, "\n        char ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_806+currStrOff, compVar, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_806+currStrOff, " = 0;\n        for(int i=", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_806+currStrOff, nt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_806+currStrOff, "->length-1; i!=-1;i--) {\n            if (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_806+currStrOff, comp, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_806+currStrOff, ") {\n                ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_806+currStrOff, compVar, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_806+currStrOff, "=1;\n                break;\n            };\n        }\n        ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_806));
pt.cont = compVar;
}
else {
if ((compTypes(ptt,ntt)==false)) {
char * ____BAH_COMPILER_VAR_807 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ptt);
long int strLen_1 = strlen(".");
long int strLen_2 = strlen(") with type ");
long int strLen_3 = strlen(ntt);
long int strLen_4 = strlen("Cannot compare {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_807 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_807+currStrOff, "Cannot compare {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_807+currStrOff, ntt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_807+currStrOff, ") with type ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_807+currStrOff, ptt, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_807+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&nt,____BAH_COMPILER_VAR_807);
}
if ((strcmp(ptt, "cpstring") == 0)) {
if ((strcmp(t.cont, "==") == 0)) {
char * ____BAH_COMPILER_VAR_808 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen(") == 0)");
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(pt.cont);
long int strLen_4 = strlen("(strcmp(");
;                            
            ____BAH_COMPILER_VAR_808 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_808+currStrOff, "(strcmp(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_808+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_808+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_808+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_808+currStrOff, ") == 0)", strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_808;
}
else if ((strcmp(t.cont, "!=") == 0)) {
char * ____BAH_COMPILER_VAR_809 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen(") != 0)");
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(pt.cont);
long int strLen_4 = strlen("(strcmp(");
;                            
            ____BAH_COMPILER_VAR_809 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_809+currStrOff, "(strcmp(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_809+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_809+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_809+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_809+currStrOff, ") != 0)", strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_809;
}
else if ((strcmp(t.cont, ">") == 0)) {
char * ____BAH_COMPILER_VAR_810 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen("))");
long int strLen_2 = strlen(") > srtlen(");
long int strLen_3 = strlen(pt.cont);
long int strLen_4 = strlen("(strlen(");
;                            
            ____BAH_COMPILER_VAR_810 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_810+currStrOff, "(strlen(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_810+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_810+currStrOff, ") > srtlen(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_810+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_810+currStrOff, "))", strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_810;
}
else if ((strcmp(t.cont, "<") == 0)) {
char * ____BAH_COMPILER_VAR_811 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen("))");
long int strLen_2 = strlen(") < srtlen(");
long int strLen_3 = strlen(pt.cont);
long int strLen_4 = strlen("(strlen(");
;                            
            ____BAH_COMPILER_VAR_811 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_811+currStrOff, "(strlen(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_811+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_811+currStrOff, ") < srtlen(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_811+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_811+currStrOff, "))", strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_811;
}
else if ((strcmp(t.cont, ">=") == 0)) {
char * ____BAH_COMPILER_VAR_812 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen("))");
long int strLen_2 = strlen(") >= srtlen(");
long int strLen_3 = strlen(pt.cont);
long int strLen_4 = strlen("(strlen(");
;                            
            ____BAH_COMPILER_VAR_812 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_812+currStrOff, "(strlen(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_812+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_812+currStrOff, ") >= srtlen(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_812+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_812+currStrOff, "))", strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_812;
}
else if ((strcmp(t.cont, "<=") == 0)) {
char * ____BAH_COMPILER_VAR_813 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen("))");
long int strLen_2 = strlen(") <= srtlen(");
long int strLen_3 = strlen(pt.cont);
long int strLen_4 = strlen("(strlen(");
;                            
            ____BAH_COMPILER_VAR_813 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_813+currStrOff, "(strlen(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_813+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_813+currStrOff, ") <= srtlen(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_813+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_813+currStrOff, "))", strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_813;
}
}
else {
char * ____BAH_COMPILER_VAR_814 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen(t.cont);
long int strLen_3 = strlen(pt.cont);
long int strLen_4 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_814 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_814+currStrOff, "(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_814+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_814+currStrOff, t.cont, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_814+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_814+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_814;
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
char * ____BAH_COMPILER_VAR_815 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_815 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_815+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_815+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_816 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_815);
;                            
            ____BAH_COMPILER_VAR_816 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_816+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_816+currStrOff, ____BAH_COMPILER_VAR_815, strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_816;

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
char * ____BAH_COMPILER_VAR_817 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ptt);
long int strLen_1 = strlen(".");
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(ntt);
long int strLen_4 = strlen("Cannot compare {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_817 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_817+currStrOff, "Cannot compare {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_817+currStrOff, ntt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_817+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_817+currStrOff, ptt, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_817+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&nt,____BAH_COMPILER_VAR_817);
}
if ((strcmp(ptt, "cpstring") == 0)) {
char * lens = "";
char * totStrLen = "1+strLen_0+strLen_1";
struct rope* cats = rope("");
char * rstr = registerRCPvar("cpstring","null",elems);
if ((pt.isFunc==true)) {
pt.cont = registerRCPvar("cpstring",pt.cont,elems);
}
char * ____BAH_COMPILER_VAR_818 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(");\n");
long int strLen_2 = strlen("long int strLen_0 = strlen(");
;                            
            ____BAH_COMPILER_VAR_818 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_818+currStrOff, "long int strLen_0 = strlen(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_818+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_818+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_819 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(lens);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_818);
;                            
            ____BAH_COMPILER_VAR_819 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_819+currStrOff, lens, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_819+currStrOff, ____BAH_COMPILER_VAR_818, strLen_1);
            currStrOff += strLen_1;
        
        }lens = ____BAH_COMPILER_VAR_819;
char * ____BAH_COMPILER_VAR_820 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(", strLen_0);\n            currStrOff += strLen_0;\n        ");
long int strLen_2 = strlen("+currStrOff, ");
long int strLen_3 = strlen(rstr);
long int strLen_4 = strlen("\n            memcpy(");
;                            
            ____BAH_COMPILER_VAR_820 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_820+currStrOff, "\n            memcpy(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_820+currStrOff, rstr, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_820+currStrOff, "+currStrOff, ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_820+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_820+currStrOff, ", strLen_0);\n            currStrOff += strLen_0;\n        ", strLen_1);
            currStrOff += strLen_1;
        
        }cats = cats->add(cats, rope(____BAH_COMPILER_VAR_820));
if ((nt.isFunc==true)) {
nt.cont = registerRCPvar("cpstring",nt.cont,elems);
}
char * ____BAH_COMPILER_VAR_821 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen(");\n");
long int strLen_2 = strlen("long int strLen_1 = strlen(");
;                            
            ____BAH_COMPILER_VAR_821 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_821+currStrOff, "long int strLen_1 = strlen(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_821+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_821+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_822 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(lens);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_821);
;                            
            ____BAH_COMPILER_VAR_822 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_822+currStrOff, lens, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_822+currStrOff, ____BAH_COMPILER_VAR_821, strLen_1);
            currStrOff += strLen_1;
        
        }lens = ____BAH_COMPILER_VAR_822;
char * ____BAH_COMPILER_VAR_823 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen(", strLen_1);\n            currStrOff += strLen_1;\n        ");
long int strLen_2 = strlen("+currStrOff, ");
long int strLen_3 = strlen(rstr);
long int strLen_4 = strlen("\n            memcpy(");
;                            
            ____BAH_COMPILER_VAR_823 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_823+currStrOff, "\n            memcpy(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_823+currStrOff, rstr, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_823+currStrOff, "+currStrOff, ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_823+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_823+currStrOff, ", strLen_1);\n            currStrOff += strLen_1;\n        ", strLen_1);
            currStrOff += strLen_1;
        
        }cats = cats->add(cats, rope(____BAH_COMPILER_VAR_823));
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
char * ____BAH_COMPILER_VAR_824 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tt);
long int strLen_1 = strlen(").");
long int strLen_2 = strlen("Cannot concatenate cpstring with {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_824 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_824+currStrOff, "Cannot concatenate cpstring with {TOKEN} (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_824+currStrOff, tt, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_824+currStrOff, ").", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&currStrTk,____BAH_COMPILER_VAR_824);
}
if ((currStrTk.isFunc==true)) {
currStrTk.cont = registerRCPvar("cpstring",currStrTk.cont,elems);
}
char * is = intToStr(nb);
nb++;
char * ____BAH_COMPILER_VAR_825 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(currStrTk.cont);
long int strLen_1 = strlen(");\n");
long int strLen_2 = strlen(" = strlen(");
long int strLen_3 = strlen(is);
long int strLen_4 = strlen("long int strLen_");
;                            
            ____BAH_COMPILER_VAR_825 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_825+currStrOff, "long int strLen_", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_825+currStrOff, is, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_825+currStrOff, " = strlen(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_825+currStrOff, currStrTk.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_825+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_826 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(lens);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_825);
;                            
            ____BAH_COMPILER_VAR_826 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_826+currStrOff, lens, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_826+currStrOff, ____BAH_COMPILER_VAR_825, strLen_1);
            currStrOff += strLen_1;
        
        }lens = ____BAH_COMPILER_VAR_826;
char * ____BAH_COMPILER_VAR_827 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("+strLen_");
long int strLen_1 = strlen(is);
;                            
            ____BAH_COMPILER_VAR_827 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_827+currStrOff, "+strLen_", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_827+currStrOff, is, strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_828 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(totStrLen);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_827);
;                            
            ____BAH_COMPILER_VAR_828 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_828+currStrOff, totStrLen, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_828+currStrOff, ____BAH_COMPILER_VAR_827, strLen_1);
            currStrOff += strLen_1;
        
        }totStrLen = ____BAH_COMPILER_VAR_828;
char * ____BAH_COMPILER_VAR_829 =null;
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
            ____BAH_COMPILER_VAR_829 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_829+currStrOff, "\n                    memcpy(", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_829+currStrOff, rstr, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_829+currStrOff, "+currStrOff, ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_829+currStrOff, currStrTk.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_829+currStrOff, ", strLen_", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_829+currStrOff, is, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_829+currStrOff, ");\n                    currStrOff += strLen_", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_829+currStrOff, is, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_829+currStrOff, ";\n                    ", strLen_1);
            currStrOff += strLen_1;
        
        }cats = rope(____BAH_COMPILER_VAR_829)->add(rope(____BAH_COMPILER_VAR_829), cats);
if ((i-1>=0)) {
i--;
t = l->data[i];
if ((strcmp(t.cont, "+") != 0)) {

        char ____BAH_COMPILER_VAR_830 = 0;
        for(int i=signs->length-1; i!=-1;i--) {
            if (signs->data[i] != 0 && strcmp(signs->data[i], t.cont) == 0) {
                ____BAH_COMPILER_VAR_830=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_830) {
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
char * ____BAH_COMPILER_VAR_831 =null;
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
            ____BAH_COMPILER_VAR_831 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_831+currStrOff, "\n        {\n            long int currStrOff = 0;\n            ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_831+currStrOff, lens, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_831+currStrOff, ";                            \n            ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_831+currStrOff, rstr, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_831+currStrOff, " = memoryAllocSTR(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_831+currStrOff, totStrLen, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_831+currStrOff, ");\n            ", strLen_1);
            currStrOff += strLen_1;
        
        }struct rope* res = rope(____BAH_COMPILER_VAR_831)->add(rope(____BAH_COMPILER_VAR_831), cats->add(cats, rope("\n        }")));
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
char * ____BAH_COMPILER_VAR_832 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ptt);
long int strLen_1 = strlen(").");
long int strLen_2 = strlen("Undefined operation on struct {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_832 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_832+currStrOff, "Undefined operation on struct {TOKEN} (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_832+currStrOff, ptt, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_832+currStrOff, ").", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&pt,____BAH_COMPILER_VAR_832);
}
struct structMemb* methd = searchStructMemb(mName,s,elems);
if ((methd!=null)&&(methd->isFn==true)) {
char * ____BAH_COMPILER_VAR_833 =null;
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
            ____BAH_COMPILER_VAR_833 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7);
            
                    memcpy(____BAH_COMPILER_VAR_833+currStrOff, sep, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_833+currStrOff, mName, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_833+currStrOff, "(", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_833+currStrOff, amp, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_833+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_833+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_833+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_833+currStrOff, ")", strLen_1);
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
pt.isFunc = true;
}
}
else {
char * ____BAH_COMPILER_VAR_835 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_835 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_835+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_835+currStrOff, nt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_836 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_835);
;                            
            ____BAH_COMPILER_VAR_836 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_836+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_836+currStrOff, ____BAH_COMPILER_VAR_835, strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_836;
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
char * ____BAH_COMPILER_VAR_837 =getTypeFromToken(&pt,true,elems);struct string ptt = string(____BAH_COMPILER_VAR_837);
if ((ptt.hasPrefix(&ptt,"chan:")==0)) {
char * ____BAH_COMPILER_VAR_838 =null;char * ____BAH_COMPILER_VAR_839 =ptt.str(&ptt);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_839);
long int strLen_1 = strlen(") as chan.");
long int strLen_2 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_838 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_838+currStrOff, "Cannot use {TOKEN} (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_838+currStrOff, ____BAH_COMPILER_VAR_839, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_838+currStrOff, ") as chan.", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_840 =____BAH_COMPILER_VAR_838;throwErr(&pt,____BAH_COMPILER_VAR_840);
}
ptt.trimLeft(&ptt,5);
if (isGlobal()) {
throwErr(&pt,"Cannot send to channel {TOKEN} of a function.");
}
char * ____BAH_COMPILER_VAR_841 =ptt.str(&ptt);if ((compTypes(ntt,____BAH_COMPILER_VAR_841)==false)) {
char * ____BAH_COMPILER_VAR_842 =null;char * ____BAH_COMPILER_VAR_843 =ptt.str(&ptt);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_843);
long int strLen_1 = strlen(".");
long int strLen_2 = strlen(") through chan:");
long int strLen_3 = strlen(ntt);
long int strLen_4 = strlen("Cannot send {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_842 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_842+currStrOff, "Cannot send {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_842+currStrOff, ntt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_842+currStrOff, ") through chan:", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_842+currStrOff, ____BAH_COMPILER_VAR_843, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_842+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_844 =____BAH_COMPILER_VAR_842;throwErr(&nt,____BAH_COMPILER_VAR_844);
}
char * ____BAH_COMPILER_VAR_845 =ptt.str(&ptt);if (isRCPpointerType(____BAH_COMPILER_VAR_845)) {
char * ____BAH_COMPILER_VAR_846 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen(");\n");
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(pt.cont);
long int strLen_4 = strlen("->send(");
long int strLen_5 = strlen(pt.cont);
;                            
            ____BAH_COMPILER_VAR_846 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_846+currStrOff, pt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_846+currStrOff, "->send(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_846+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_846+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_846+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_846+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_846));
}
else {
struct string ct = getCType(ntt,elems);
char * tmpV = genCompilerVar();
char * ____BAH_COMPILER_VAR_847 =null;char * ____BAH_COMPILER_VAR_848 =ct.str(&ct);
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
long int strLen_13 = strlen(____BAH_COMPILER_VAR_848);
long int strLen_14 = strlen("\n        ");
;                            
            ____BAH_COMPILER_VAR_847 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13+strLen_14);
            
                    memcpy(____BAH_COMPILER_VAR_847+currStrOff, "\n        ", strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_847+currStrOff, ____BAH_COMPILER_VAR_848, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_847+currStrOff, " ", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_847+currStrOff, tmpV, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_847+currStrOff, " = ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_847+currStrOff, nt.cont, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_847+currStrOff, ";\n        ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_847+currStrOff, pt.cont, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_847+currStrOff, "->sendAny(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_847+currStrOff, pt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_847+currStrOff, ", &", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_847+currStrOff, tmpV, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_847+currStrOff, ", sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_847+currStrOff, tmpV, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_847+currStrOff, "));\n        ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_847));
}
return posTok;
};
long int valueChan(__BAH_ARR_TYPE_Tok l,long int i,struct Elems* elems){
long int posTok = i-1;
delete(l,posTok);
struct Tok nt = l->data[posTok];
char * ____BAH_COMPILER_VAR_849 =getTypeFromToken(&nt,true,elems);struct string ntt = string(____BAH_COMPILER_VAR_849);
if ((ntt.hasPrefix(&ntt,"chan:")==0)) {
char * ____BAH_COMPILER_VAR_850 =null;char * ____BAH_COMPILER_VAR_851 =ntt.str(&ntt);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_851);
long int strLen_1 = strlen(") as chan.");
long int strLen_2 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_850 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_850+currStrOff, "Cannot use {TOKEN} (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_850+currStrOff, ____BAH_COMPILER_VAR_851, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_850+currStrOff, ") as chan.", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_852 =____BAH_COMPILER_VAR_850;throwErr(&nt,____BAH_COMPILER_VAR_852);
}
ntt.trimLeft(&ntt,5);
if (isGlobal()) {
throwErr(&nt,"Cannot receive from chan {TOKEN} outside a function body.");
}
char * tmpV = "";
char * ____BAH_COMPILER_VAR_853 =ntt.str(&ntt);struct string ct = getCType(____BAH_COMPILER_VAR_853,elems);
char * ____BAH_COMPILER_VAR_854 =ntt.str(&ntt);if (isRCPpointerType(____BAH_COMPILER_VAR_854)) {
char * ____BAH_COMPILER_VAR_855 =null;char * ____BAH_COMPILER_VAR_856 =ct.str(&ct);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen("->receive(");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen(")");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_856);
long int strLen_6 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_855 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_855+currStrOff, "(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_855+currStrOff, ____BAH_COMPILER_VAR_856, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_855+currStrOff, ")", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_855+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_855+currStrOff, "->receive(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_855+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_855+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }nt.cont = ____BAH_COMPILER_VAR_855;
}
else {
if (RCPavailable()) {
char * ____BAH_COMPILER_VAR_857 =null;char * ____BAH_COMPILER_VAR_858 =ntt.str(&ntt);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_858);
long int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_857 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_857+currStrOff, ____BAH_COMPILER_VAR_858, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_857+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_859 =null;char * ____BAH_COMPILER_VAR_860 =ct.str(&ct);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen("->receive(");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen("*)");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_860);
long int strLen_6 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_859 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_859+currStrOff, "(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_859+currStrOff, ____BAH_COMPILER_VAR_860, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_859+currStrOff, "*)", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_859+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_859+currStrOff, "->receive(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_859+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_859+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_861 =____BAH_COMPILER_VAR_857;tmpV = registerRCPvar(____BAH_COMPILER_VAR_861,____BAH_COMPILER_VAR_859,elems);
char * ____BAH_COMPILER_VAR_862 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("*");
long int strLen_1 = strlen(tmpV);
;                            
            ____BAH_COMPILER_VAR_862 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_862+currStrOff, "*", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_862+currStrOff, tmpV, strLen_1);
            currStrOff += strLen_1;
        
        }nt.cont = ____BAH_COMPILER_VAR_862;
}
else {
char * ____BAH_COMPILER_VAR_863 =null;char * ____BAH_COMPILER_VAR_864 =ct.str(&ct);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen("->receive(");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen("*)");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_864);
long int strLen_6 = strlen("*(");
;                            
            ____BAH_COMPILER_VAR_863 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_863+currStrOff, "*(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_863+currStrOff, ____BAH_COMPILER_VAR_864, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_863+currStrOff, "*)", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_863+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_863+currStrOff, "->receive(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_863+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_863+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }nt.cont = ____BAH_COMPILER_VAR_863;
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
#define pt ____BAH_COMPILER_VAR_865
long int l = len(fl);
i = 0;
for (; (i<len(fl)); i++) {
struct Tok t = fl->data[i];
if ((t.type==TOKEN_TYPE_VAR)&&(t.isOper==false)&&(t.cont[0]==38)) {
struct string tc = string(t.cont);
tc.trimLeft(&tc,1);
char * ____BAH_COMPILER_VAR_866 =tc.str(&tc);struct variable* rv = getRealVar(____BAH_COMPILER_VAR_866,elems);
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
struct Tok ____BAH_COMPILER_VAR_867 = {};
____BAH_COMPILER_VAR_867.cont = "";
____BAH_COMPILER_VAR_867.ogCont = "";
____BAH_COMPILER_VAR_867.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_867.pos = 0;
____BAH_COMPILER_VAR_867.line = 1;
____BAH_COMPILER_VAR_867.begLine = 1;
____BAH_COMPILER_VAR_867.bahType = "";
____BAH_COMPILER_VAR_867.isValue = false;
____BAH_COMPILER_VAR_867.isFunc = false;
____BAH_COMPILER_VAR_867.isOper = false;
____BAH_COMPILER_VAR_867.isEqual = false;
____BAH_COMPILER_VAR_867.pass = false;
____BAH_COMPILER_VAR_867.bahRef= null;
pt = ____BAH_COMPILER_VAR_867;
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
char * ____BAH_COMPILER_VAR_868 =ptc.str(&ptc);struct string cType = getCType(____BAH_COMPILER_VAR_868,elems);
char * ____BAH_COMPILER_VAR_869 =null;char * ____BAH_COMPILER_VAR_870 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(")");
long int strLen_1 = strlen(t.cont);
long int strLen_2 = strlen(____BAH_COMPILER_VAR_870);
long int strLen_3 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_869 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_869+currStrOff, "(", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_869+currStrOff, ____BAH_COMPILER_VAR_870, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_869+currStrOff, ")", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_869+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_869;

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
char * ____BAH_COMPILER_VAR_871 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_871 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_871+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_871+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_872 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ppt.cont);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_871);
;                            
            ____BAH_COMPILER_VAR_872 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_872+currStrOff, ppt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_872+currStrOff, ____BAH_COMPILER_VAR_871, strLen_1);
            currStrOff += strLen_1;
        
        }ppt.cont = ____BAH_COMPILER_VAR_872;
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
char * ____BAH_COMPILER_VAR_873 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_873 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_873+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_873+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_873;

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
char * ____BAH_COMPILER_VAR_874 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ptt);
long int strLen_1 = strlen(".");
long int strLen_2 = strlen("Cannot use {TOKEN} on ");
;                            
            ____BAH_COMPILER_VAR_874 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_874+currStrOff, "Cannot use {TOKEN} on ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_874+currStrOff, ptt, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_874+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&t,____BAH_COMPILER_VAR_874);
}
char * ____BAH_COMPILER_VAR_875 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_875 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_875+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_875+currStrOff, nt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_876 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_875);
;                            
            ____BAH_COMPILER_VAR_876 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_876+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_876+currStrOff, ____BAH_COMPILER_VAR_875, strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_876;

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
char * ____BAH_COMPILER_VAR_877 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t.bahType);
long int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_877 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_877+currStrOff, t.bahType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_877+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }t.bahType = ____BAH_COMPILER_VAR_877;

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
struct func* ____BAH_COMPILER_VAR_878 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_878->name = "";
____BAH_COMPILER_VAR_878->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_878->args->length = 0;
            ____BAH_COMPILER_VAR_878->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_878->returns= null;
____BAH_COMPILER_VAR_878->isBinding = false;
____BAH_COMPILER_VAR_878->from = "";
____BAH_COMPILER_VAR_878->file = "";
____BAH_COMPILER_VAR_878->line = 1;
____BAH_COMPILER_VAR_878->used = false;
____BAH_COMPILER_VAR_878->code = null;
struct func* fn = ____BAH_COMPILER_VAR_878;
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
char * ____BAH_COMPILER_VAR_879 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(lineStr);
long int strLen_1 = strlen(".");
long int strLen_2 = strlen(":");
long int strLen_3 = strlen(ogFn->file);
long int strLen_4 = strlen("Cannot redeclare function {TOKEN}, previous declaration: ");
;                            
            ____BAH_COMPILER_VAR_879 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_879+currStrOff, "Cannot redeclare function {TOKEN}, previous declaration: ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_879+currStrOff, ogFn->file, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_879+currStrOff, ":", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_879+currStrOff, lineStr, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_879+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&ft,____BAH_COMPILER_VAR_879);
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
char * ____BAH_COMPILER_VAR_880 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(";\n");
;                            
            ____BAH_COMPILER_VAR_880 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_880+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_880+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_880));
return;
}
char * ____BAH_COMPILER_VAR_881 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen("{\n");
;                            
            ____BAH_COMPILER_VAR_881 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_881+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_881+currStrOff, "{\n", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_881;
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
char * ____BAH_COMPILER_VAR_882 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fn->name);
long int strLen_1 = strlen("' is not returned.");
long int strLen_2 = strlen("Function '");
;                            
            ____BAH_COMPILER_VAR_882 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_882+currStrOff, "Function '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_882+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_882+currStrOff, "' is not returned.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&l->data[len(l)-1],____BAH_COMPILER_VAR_882);
}
endRCPscope(fnElems,fn->args);
}
fn->code = fn->code->add(fn->code, OUTPUT);
OUTPUT = oOut;
fn->code = fn->code->add(fn->code, rope("};\n"));
OUTPUT = OUTPUT->add(OUTPUT, fn->code);
if ((debug==true)) {
struct debugFunction* ____BAH_COMPILER_VAR_883 = memoryAlloc(sizeof(struct debugFunction));
____BAH_COMPILER_VAR_883->name= null;
____BAH_COMPILER_VAR_883->returns= null;
____BAH_COMPILER_VAR_883->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_883->args->length = 0;
            ____BAH_COMPILER_VAR_883->args->elemSize = sizeof(struct variable*);
            struct debugFunction* df = ____BAH_COMPILER_VAR_883;
df->name = fn->name;
df->args = fn->args;
df->returns = fn->returns->type;
struct debugFunction* ____BAH_COMPILER_VAR_884 = df;
char ** ____BAH_COMPILER_VAR_886 = (char **)((char*)(____BAH_COMPILER_VAR_884) + offsetof(struct debugFunction, name));
struct reflectElement ____BAH_COMPILER_VAR_887 = __reflect(____BAH_COMPILER_VAR_886, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct debugFunction, name));
char ** ____BAH_COMPILER_VAR_888 = (char **)((char*)(____BAH_COMPILER_VAR_884) + offsetof(struct debugFunction, returns));
struct reflectElement ____BAH_COMPILER_VAR_889 = __reflect(____BAH_COMPILER_VAR_888, sizeof(char *), "cpstring", "returns", 0, 0, 0, 0, offsetof(struct debugFunction, returns));
array(struct variable*)** ____BAH_COMPILER_VAR_890 = (array(struct variable*)**)((char*)(____BAH_COMPILER_VAR_884) + offsetof(struct debugFunction, args));
struct variable** ____BAH_COMPILER_VAR_891 = 0;
char ** ____BAH_COMPILER_VAR_893 = (char **)((char*)(____BAH_COMPILER_VAR_891) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_894 = __reflect(____BAH_COMPILER_VAR_893, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_895 = (char **)((char*)(____BAH_COMPILER_VAR_891) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_896 = __reflect(____BAH_COMPILER_VAR_895, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_897 = (char*)((char*)(____BAH_COMPILER_VAR_891) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_898 = __reflect(____BAH_COMPILER_VAR_897, sizeof(char), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_899 = (char **)((char*)(____BAH_COMPILER_VAR_891) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_900 = __reflect(____BAH_COMPILER_VAR_899, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_901 = (char*)((char*)(____BAH_COMPILER_VAR_891) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_902 = __reflect(____BAH_COMPILER_VAR_901, sizeof(char), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_903 = (char **)((char*)(____BAH_COMPILER_VAR_891) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_904 = __reflect(____BAH_COMPILER_VAR_903, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
void ** ____BAH_COMPILER_VAR_905 = (void **)((char*)(____BAH_COMPILER_VAR_891) + offsetof(struct variable, declScope));
struct reflectElement ____BAH_COMPILER_VAR_906 = __reflect(____BAH_COMPILER_VAR_905, sizeof(void *), "ptr", "declScope", 0, 0, 0, 0, offsetof(struct variable, declScope));
char* ____BAH_COMPILER_VAR_907 = (char*)((char*)(____BAH_COMPILER_VAR_891) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_908 = __reflect(____BAH_COMPILER_VAR_907, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));
struct rope** ____BAH_COMPILER_VAR_909 = (struct rope**)((char*)(____BAH_COMPILER_VAR_891) + offsetof(struct variable, declRope));
void ** ____BAH_COMPILER_VAR_911 = (void **)((char*)(____BAH_COMPILER_VAR_909) + offsetof(struct rope, left));
struct reflectElement ____BAH_COMPILER_VAR_912 = __reflect(____BAH_COMPILER_VAR_911, sizeof(void *), "ptr", "left", 0, 0, 0, 0, offsetof(struct rope, left));
void ** ____BAH_COMPILER_VAR_913 = (void **)((char*)(____BAH_COMPILER_VAR_909) + offsetof(struct rope, right));
struct reflectElement ____BAH_COMPILER_VAR_914 = __reflect(____BAH_COMPILER_VAR_913, sizeof(void *), "ptr", "right", 0, 0, 0, 0, offsetof(struct rope, right));
char ** ____BAH_COMPILER_VAR_915 = (char **)((char*)(____BAH_COMPILER_VAR_909) + offsetof(struct rope, str));
struct reflectElement ____BAH_COMPILER_VAR_916 = __reflect(____BAH_COMPILER_VAR_915, sizeof(char *), "cpstring", "str", 0, 0, 0, 0, offsetof(struct rope, str));
long int* ____BAH_COMPILER_VAR_917 = (long int*)((char*)(____BAH_COMPILER_VAR_909) + offsetof(struct rope, lCount));
struct reflectElement ____BAH_COMPILER_VAR_918 = __reflect(____BAH_COMPILER_VAR_917, sizeof(long int), "int", "lCount", 0, 0, 0, 0, offsetof(struct rope, lCount));
long int* ____BAH_COMPILER_VAR_919 = (long int*)((char*)(____BAH_COMPILER_VAR_909) + offsetof(struct rope, len));
struct reflectElement ____BAH_COMPILER_VAR_920 = __reflect(____BAH_COMPILER_VAR_919, sizeof(long int), "int", "len", 0, 0, 0, 0, offsetof(struct rope, len));
long int* ____BAH_COMPILER_VAR_921 = (long int*)((char*)(____BAH_COMPILER_VAR_909) + offsetof(struct rope, totalLen));
struct reflectElement ____BAH_COMPILER_VAR_922 = __reflect(____BAH_COMPILER_VAR_921, sizeof(long int), "int", "totalLen", 0, 0, 0, 0, offsetof(struct rope, totalLen));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_910 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_910->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_910->length = 6;
        ____BAH_COMPILER_VAR_910->data = memoryAlloc(____BAH_COMPILER_VAR_910->length * ____BAH_COMPILER_VAR_910->elemSize);
        ____BAH_COMPILER_VAR_910->data[0] = ____BAH_COMPILER_VAR_912;
____BAH_COMPILER_VAR_910->data[1] = ____BAH_COMPILER_VAR_914;
____BAH_COMPILER_VAR_910->data[2] = ____BAH_COMPILER_VAR_916;
____BAH_COMPILER_VAR_910->data[3] = ____BAH_COMPILER_VAR_918;
____BAH_COMPILER_VAR_910->data[4] = ____BAH_COMPILER_VAR_920;
____BAH_COMPILER_VAR_910->data[5] = ____BAH_COMPILER_VAR_922;
struct reflectElement ____BAH_COMPILER_VAR_923 = __reflect(____BAH_COMPILER_VAR_909, sizeof(struct rope), "rope*", "declRope", 0, 0, 1, ____BAH_COMPILER_VAR_910, offsetof(struct variable, declRope));
char* ____BAH_COMPILER_VAR_924 = (char*)((char*)(____BAH_COMPILER_VAR_891) + offsetof(struct variable, canBeReg));
struct reflectElement ____BAH_COMPILER_VAR_925 = __reflect(____BAH_COMPILER_VAR_924, sizeof(char), "bool", "canBeReg", 0, 0, 0, 0, offsetof(struct variable, canBeReg));
char* ____BAH_COMPILER_VAR_926 = (char*)((char*)(____BAH_COMPILER_VAR_891) + offsetof(struct variable, isReg));
struct reflectElement ____BAH_COMPILER_VAR_927 = __reflect(____BAH_COMPILER_VAR_926, sizeof(char), "bool", "isReg", 0, 0, 0, 0, offsetof(struct variable, isReg));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_892 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_892->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_892->length = 11;
        ____BAH_COMPILER_VAR_892->data = memoryAlloc(____BAH_COMPILER_VAR_892->length * ____BAH_COMPILER_VAR_892->elemSize);
        ____BAH_COMPILER_VAR_892->data[0] = ____BAH_COMPILER_VAR_894;
____BAH_COMPILER_VAR_892->data[1] = ____BAH_COMPILER_VAR_896;
____BAH_COMPILER_VAR_892->data[2] = ____BAH_COMPILER_VAR_898;
____BAH_COMPILER_VAR_892->data[3] = ____BAH_COMPILER_VAR_900;
____BAH_COMPILER_VAR_892->data[4] = ____BAH_COMPILER_VAR_902;
____BAH_COMPILER_VAR_892->data[5] = ____BAH_COMPILER_VAR_904;
____BAH_COMPILER_VAR_892->data[6] = ____BAH_COMPILER_VAR_906;
____BAH_COMPILER_VAR_892->data[7] = ____BAH_COMPILER_VAR_908;
____BAH_COMPILER_VAR_892->data[8] = ____BAH_COMPILER_VAR_923;
____BAH_COMPILER_VAR_892->data[9] = ____BAH_COMPILER_VAR_925;
____BAH_COMPILER_VAR_892->data[10] = ____BAH_COMPILER_VAR_927;
struct reflectElement ____BAH_COMPILER_VAR_928 = __reflect(____BAH_COMPILER_VAR_891, sizeof(struct variable), "variable*", "", 0, 0, 1, ____BAH_COMPILER_VAR_892, 0);

        struct reflectElement ____BAH_COMPILER_VAR_929 = ____BAH_COMPILER_VAR_928;
        struct reflectElement ____BAH_COMPILER_VAR_930 = __reflect(____BAH_COMPILER_VAR_890, sizeof(array(struct variable*)*), "[]variable*", "args", 1, &____BAH_COMPILER_VAR_929, 0, 0, offsetof(struct debugFunction, args));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_885 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_885->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_885->length = 3;
        ____BAH_COMPILER_VAR_885->data = memoryAlloc(____BAH_COMPILER_VAR_885->length * ____BAH_COMPILER_VAR_885->elemSize);
        ____BAH_COMPILER_VAR_885->data[0] = ____BAH_COMPILER_VAR_887;
____BAH_COMPILER_VAR_885->data[1] = ____BAH_COMPILER_VAR_889;
____BAH_COMPILER_VAR_885->data[2] = ____BAH_COMPILER_VAR_930;
struct reflectElement ____BAH_COMPILER_VAR_931 = __reflect(____BAH_COMPILER_VAR_884, sizeof(struct debugFunction), "debugFunction*", "df", 0, 0, 1, ____BAH_COMPILER_VAR_885, 0);
debugPrint("fn_declare",ft.line,____BAH_COMPILER_VAR_931);
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
char * ____BAH_COMPILER_VAR_932 =registerRCPvar(fn->returns->type,ft.cont,elems);return;
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
char * ____BAH_COMPILER_VAR_933 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ft.cont);
long int strLen_1 = strlen(";\n");
;                            
            ____BAH_COMPILER_VAR_933 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_933+currStrOff, ft.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_933+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_933));
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
char * ____BAH_COMPILER_VAR_934 =null;char * ____BAH_COMPILER_VAR_935 =ct.str(&ct);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(" ");
long int strLen_1 = strlen(arg->name);
long int strLen_2 = strlen(____BAH_COMPILER_VAR_935);
long int strLen_3 = strlen(tmpfnArgsCType);
;                            
            ____BAH_COMPILER_VAR_934 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_934+currStrOff, tmpfnArgsCType, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_934+currStrOff, ____BAH_COMPILER_VAR_935, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_934+currStrOff, " ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_934+currStrOff, arg->name, strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_934;
j = j+1;
if ((j<len(fn->args))) {
char * ____BAH_COMPILER_VAR_936 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(", ");
;                            
            ____BAH_COMPILER_VAR_936 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_936+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_936+currStrOff, ", ", strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_936;
}
};
char * ____BAH_COMPILER_VAR_937 =null;char * ____BAH_COMPILER_VAR_938 =tmpfnRetCType.str(&tmpfnRetCType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(");\n");
long int strLen_2 = strlen("(");
long int strLen_3 = strlen(fn->name);
long int strLen_4 = strlen(" ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_938);
;                            
            ____BAH_COMPILER_VAR_937 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_937+currStrOff, ____BAH_COMPILER_VAR_938, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_937+currStrOff, " ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_937+currStrOff, fn->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_937+currStrOff, "(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_937+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_937+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_937));
};
void declareVar(struct variable* v,struct Elems* elems){
if ((v->isConst==true)) {
char * ____BAH_COMPILER_VAR_939 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(v->constVal);
long int strLen_1 = strlen("\n");
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen("#define ");
;                            
            ____BAH_COMPILER_VAR_939 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_939+currStrOff, "#define ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_939+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_939+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_939+currStrOff, v->constVal, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_939+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_939));
}
else {
struct string cType = getCType(v->type,elems);
char * ____BAH_COMPILER_VAR_940 =null;char * ____BAH_COMPILER_VAR_941 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_941);
;                            
            ____BAH_COMPILER_VAR_940 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_940+currStrOff, ____BAH_COMPILER_VAR_941, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_940+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_940+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_940+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_940));
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
char * ____BAH_COMPILER_VAR_942 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(compilerState.cIncludes->data[i]);
long int strLen_1 = strlen("\n");
long int strLen_2 = strlen("#include ");
;                            
            ____BAH_COMPILER_VAR_942 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_942+currStrOff, "#include ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_942+currStrOff, compilerState.cIncludes->data[i], strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_942+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_942));
};
i = 1;
for (; (i<len(compilerState.arrTypesDecl)); i++) {
char * t = compilerState.arrTypesDecl->data[i];
struct string elemType = string(t);
elemType.trimLeft(&elemType,15);
char * ____BAH_COMPILER_VAR_943 =elemType.str(&elemType);struct string elemCtype = getCType(____BAH_COMPILER_VAR_943,elems);
char * ____BAH_COMPILER_VAR_944 =null;char * ____BAH_COMPILER_VAR_945 =elemCtype.str(&elemCtype);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen(")* ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_945);
long int strLen_4 = strlen("typedef array(");
;                            
            ____BAH_COMPILER_VAR_944 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_944+currStrOff, "typedef array(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_944+currStrOff, ____BAH_COMPILER_VAR_945, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_944+currStrOff, ")* ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_944+currStrOff, t, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_944+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_944));
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
char * ____BAH_COMPILER_VAR_946 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("file: ");
long int strLen_1 = strlen(compilerState.currentFile);
;                            
            ____BAH_COMPILER_VAR_946 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_946+currStrOff, "file: ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_946+currStrOff, compilerState.currentFile, strLen_1);
            currStrOff += strLen_1;
        
        }char * r = ____BAH_COMPILER_VAR_946;
if ((currentFn!=null)) {
char * ____BAH_COMPILER_VAR_947 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(currentFn->name);
long int strLen_1 = strlen("()");
long int strLen_2 = strlen("\nfunction: ");
;                            
            ____BAH_COMPILER_VAR_947 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_947+currStrOff, "\nfunction: ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_947+currStrOff, currentFn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_947+currStrOff, "()", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_948 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(r);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_947);
;                            
            ____BAH_COMPILER_VAR_948 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_948+currStrOff, r, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_948+currStrOff, ____BAH_COMPILER_VAR_947, strLen_1);
            currStrOff += strLen_1;
        
        }r = ____BAH_COMPILER_VAR_948;
}
return r;
};
long int main(__BAH_ARR_TYPE_cpstring args){
onMemoryError = memErrHandle;
execName = args->data[0];
if ((execName[0]==46)||(execName[0]==47)) {
execName = absPath(execName);
}
struct flags ____BAH_COMPILER_VAR_949 = {};
____BAH_COMPILER_VAR_949.flags = memoryAlloc(sizeof(array(struct flag*)));
            ____BAH_COMPILER_VAR_949.flags->length = 0;
            ____BAH_COMPILER_VAR_949.flags->elemSize = sizeof(struct flag*);
            ____BAH_COMPILER_VAR_949.args = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_949.args->length = 0;
            ____BAH_COMPILER_VAR_949.args->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_949.addString = flags__addString;
____BAH_COMPILER_VAR_949.addBool = flags__addBool;
____BAH_COMPILER_VAR_949.addInt = flags__addInt;
____BAH_COMPILER_VAR_949.addFloat = flags__addFloat;
____BAH_COMPILER_VAR_949.invalidate = flags__invalidate;
____BAH_COMPILER_VAR_949.getFlag = flags__getFlag;
____BAH_COMPILER_VAR_949.get = flags__get;
____BAH_COMPILER_VAR_949.getInt = flags__getInt;
____BAH_COMPILER_VAR_949.getFloat = flags__getFloat;
____BAH_COMPILER_VAR_949.isSet = flags__isSet;
____BAH_COMPILER_VAR_949.parse = flags__parse;
flags = ____BAH_COMPILER_VAR_949;
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
char * ____BAH_COMPILER_VAR_950 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(BAH_OS);
long int strLen_1 = strlen(".");
long int strLen_2 = strlen("Select the target OS for cross compilling (linux, windows, darwin), default: ");
;                            
            ____BAH_COMPILER_VAR_950 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_950+currStrOff, "Select the target OS for cross compilling (linux, windows, darwin), default: ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_950+currStrOff, BAH_OS, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_950+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }flags.addString(&flags,"target",____BAH_COMPILER_VAR_950);
char * ____BAH_COMPILER_VAR_951 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen(").");
long int strLen_2 = strlen("If your Bah directory is not the default one (");
;                            
            ____BAH_COMPILER_VAR_951 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_951+currStrOff, "If your Bah directory is not the default one (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_951+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_951+currStrOff, ").", strLen_1);
            currStrOff += strLen_1;
        
        }flags.addString(&flags,"bahDir",____BAH_COMPILER_VAR_951);
char * ____BAH_COMPILER_VAR_952 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(BAH_CC);
long int strLen_1 = strlen(".");
long int strLen_2 = strlen("To change the C compiler used, default: ");
;                            
            ____BAH_COMPILER_VAR_952 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_952+currStrOff, "To change the C compiler used, default: ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_952+currStrOff, BAH_CC, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_952+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }flags.addString(&flags,"CC",____BAH_COMPILER_VAR_952);
flags.addBool(&flags,"object","Compile as an object.");
flags.addBool(&flags,"unsafe","Compile without safety checking. This will make for faster executable but if your program crashes, it will show less informations.");
flags.parse(&flags,args);
if ((flags.isSet(&flags,"target")==1)) {
BAH_OS = flags.get(&flags,"target");
char * ____BAH_COMPILER_VAR_953 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("Build target: ");
long int strLen_1 = strlen(BAH_OS);
;                            
            ____BAH_COMPILER_VAR_953 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_953+currStrOff, "Build target: ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_953+currStrOff, BAH_OS, strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_953);
}
if ((flags.isSet(&flags,"bahDir")==1)) {
BAH_DIR = flags.get(&flags,"bahDir");
array(char)* bahDirArr = strAsArr(BAH_DIR);
if ((bahDirArr->data[len(bahDirArr)-1]!=47)) {
char * ____BAH_COMPILER_VAR_954 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen("/");
;                            
            ____BAH_COMPILER_VAR_954 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_954+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_954+currStrOff, "/", strLen_1);
            currStrOff += strLen_1;
        
        }BAH_DIR = ____BAH_COMPILER_VAR_954;
}
char * ____BAH_COMPILER_VAR_955 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("Bah directory: ");
long int strLen_1 = strlen(BAH_DIR);
;                            
            ____BAH_COMPILER_VAR_955 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_955+currStrOff, "Bah directory: ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_955+currStrOff, BAH_DIR, strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_955);
}
if ((flags.isSet(&flags,"CC")==1)) {
BAH_CC = flags.get(&flags,"CC");
char * ____BAH_COMPILER_VAR_956 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("C compiler: ");
long int strLen_1 = strlen(BAH_CC);
;                            
            ____BAH_COMPILER_VAR_956 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_956+currStrOff, "C compiler: ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_956+currStrOff, BAH_CC, strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_956);
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
char * ____BAH_COMPILER_VAR_957 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(BAH_VERSION);
long int strLen_1 = strlen(".\n© Alois Laurent Boe");
long int strLen_2 = strlen("Bah compiler version: ");
;                            
            ____BAH_COMPILER_VAR_957 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_957+currStrOff, "Bah compiler version: ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_957+currStrOff, BAH_VERSION, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_957+currStrOff, ".\n© Alois Laurent Boe", strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_957);
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
struct compilerStateTag ____BAH_COMPILER_VAR_958 = {};
____BAH_COMPILER_VAR_958.includes = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_958.includes->length = 0;
            ____BAH_COMPILER_VAR_958.includes->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_958.cIncludes = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_958.cIncludes->length = 0;
            ____BAH_COMPILER_VAR_958.cIncludes->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_958.cLibs = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_958.cLibs->length = 0;
            ____BAH_COMPILER_VAR_958.cLibs->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_958.currentFile= null;
____BAH_COMPILER_VAR_958.currentDir = "./";
____BAH_COMPILER_VAR_958.isBranch = false;
____BAH_COMPILER_VAR_958.isFor = false;
____BAH_COMPILER_VAR_958.arrTypesDecl = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_958.arrTypesDecl->length = 0;
            ____BAH_COMPILER_VAR_958.arrTypesDecl->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_958.haveEntryPoint = false;
____BAH_COMPILER_VAR_958.RCPvars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_958.RCPvars->length = 0;
            ____BAH_COMPILER_VAR_958.RCPvars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_958.evals = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_958.evals->length = 0;
            ____BAH_COMPILER_VAR_958.evals->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_958.hasImports = false;
____BAH_COMPILER_VAR_958.currForElems= null;
____BAH_COMPILER_VAR_958.currFnElems= null;
compilerState = ____BAH_COMPILER_VAR_958;

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
struct fileMap ____BAH_COMPILER_VAR_959 = {};
____BAH_COMPILER_VAR_959.handle = -1;
____BAH_COMPILER_VAR_959.p= null;
____BAH_COMPILER_VAR_959.open = fileMap__open;
____BAH_COMPILER_VAR_959.isValid = fileMap__isValid;
____BAH_COMPILER_VAR_959.close = fileMap__close;
#define fm ____BAH_COMPILER_VAR_959
char * f = fm.open(&fm,fileName);
if ((fm.isValid(&fm)==0)||(fm.size==0)) {
char * ____BAH_COMPILER_VAR_960 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(args->data[1]);
long int strLen_1 = strlen("'.");
long int strLen_2 = strlen("Could not open file '");
;                            
            ____BAH_COMPILER_VAR_960 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_960+currStrOff, "Could not open file '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_960+currStrOff, args->data[1], strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_960+currStrOff, "'.", strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_960);
exit(1);
}
long int startTime = getTimeUnix();
array(struct Tok)* tokens = lexer(f);
fm.close(&fm);
if ((len(tokens)==0)) {
char * ____BAH_COMPILER_VAR_961 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fileName);
long int strLen_1 = strlen("' not recognized.");
long int strLen_2 = strlen("File '");
;                            
            ____BAH_COMPILER_VAR_961 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_961+currStrOff, "File '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_961+currStrOff, fileName, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_961+currStrOff, "' not recognized.", strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_961);
exit(1);
}
struct Elems* ____BAH_COMPILER_VAR_962 = memoryAlloc(sizeof(struct Elems));
____BAH_COMPILER_VAR_962->vars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_962->vars->length = 0;
            ____BAH_COMPILER_VAR_962->vars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_962->structs = memoryAlloc(sizeof(array(struct cStruct*)));
            ____BAH_COMPILER_VAR_962->structs->length = 0;
            ____BAH_COMPILER_VAR_962->structs->elemSize = sizeof(struct cStruct*);
            ____BAH_COMPILER_VAR_962->types = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_962->types->length = 0;
            ____BAH_COMPILER_VAR_962->types->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_962->fns = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_962->fns->length = 0;
            ____BAH_COMPILER_VAR_962->fns->elemSize = sizeof(struct func*);
            ____BAH_COMPILER_VAR_962->defined = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_962->defined->length = 0;
            ____BAH_COMPILER_VAR_962->defined->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_962->parent= null;
struct Elems* elems = ____BAH_COMPILER_VAR_962;
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
char * ____BAH_COMPILER_VAR_963 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen("'");
long int strLen_2 = strlen("Could not find std-libs, please check '");
;                            
            ____BAH_COMPILER_VAR_963 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_963+currStrOff, "Could not find std-libs, please check '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_963+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_963+currStrOff, "'", strLen_1);
            currStrOff += strLen_1;
        
        }__BAH_panic(____BAH_COMPILER_VAR_963,"/home/alois/Documents/bah-bah/src/main.bah:243");
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
char * ____BAH_COMPILER_VAR_964 =null;char * ____BAH_COMPILER_VAR_965 =intToStr(l);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_965);
long int strLen_1 = strlen("];");
long int strLen_2 = strlen("volatile struct __Bah_fnName_mapper __tmp____Bah_fnNames[");
;                            
            ____BAH_COMPILER_VAR_964 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_964+currStrOff, "volatile struct __Bah_fnName_mapper __tmp____Bah_fnNames[", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_964+currStrOff, ____BAH_COMPILER_VAR_965, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_964+currStrOff, "];", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_966 =____BAH_COMPILER_VAR_964;OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_966));
long int j = 0;
i = 0;
for (; (i<len(elems->fns)); i++) {
struct func* fn = elems->fns->data[i];
if ((fn->isBinding==true)) {
continue;
}
char * name = fn->name;
char * ____BAH_COMPILER_VAR_967 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fn->from);
long int strLen_1 = strlen("__");
;                            
            ____BAH_COMPILER_VAR_967 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_967+currStrOff, fn->from, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_967+currStrOff, "__", strLen_1);
            currStrOff += strLen_1;
        
        }if ((strcmp(fn->from, "") != 0)&&strHasPrefix(name,____BAH_COMPILER_VAR_967)) {
struct string n = string(name);
n.trimLeft(&n,strlen(fn->from)+2);
char * ____BAH_COMPILER_VAR_968 =null;char * ____BAH_COMPILER_VAR_969 =n.str(&n);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(".");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_969);
long int strLen_2 = strlen(fn->from);
;                            
            ____BAH_COMPILER_VAR_968 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_968+currStrOff, fn->from, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_968+currStrOff, ".", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_968+currStrOff, ____BAH_COMPILER_VAR_969, strLen_1);
            currStrOff += strLen_1;
        
        }name = ____BAH_COMPILER_VAR_968;
}
char * ____BAH_COMPILER_VAR_970 =null;char * ____BAH_COMPILER_VAR_971 =intToStr(j);char * ____BAH_COMPILER_VAR_972 =intToStr(j);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fn->name);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen("].p = ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_971);
long int strLen_4 = strlen("\";\n            __tmp____Bah_fnNames[");
long int strLen_5 = strlen(name);
long int strLen_6 = strlen("].n = \"");
long int strLen_7 = strlen(____BAH_COMPILER_VAR_972);
long int strLen_8 = strlen("\n            __tmp____Bah_fnNames[");
;                            
            ____BAH_COMPILER_VAR_970 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_970+currStrOff, "\n            __tmp____Bah_fnNames[", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_970+currStrOff, ____BAH_COMPILER_VAR_972, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_970+currStrOff, "].n = \"", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_970+currStrOff, name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_970+currStrOff, "\";\n            __tmp____Bah_fnNames[", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_970+currStrOff, ____BAH_COMPILER_VAR_971, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_970+currStrOff, "].p = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_970+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_970+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }INIT = INIT->add(INIT, rope(____BAH_COMPILER_VAR_970));
j++;
};
char * ____BAH_COMPILER_VAR_973 =null;char * ____BAH_COMPILER_VAR_974 =intToStr(l);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_974);
long int strLen_1 = strlen(";");
long int strLen_2 = strlen("\n        __Bah_fnNames->data = __tmp____Bah_fnNames;\n        __Bah_fnNames->length = ");
;                            
            ____BAH_COMPILER_VAR_973 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_973+currStrOff, "\n        __Bah_fnNames->data = __tmp____Bah_fnNames;\n        __Bah_fnNames->length = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_973+currStrOff, ____BAH_COMPILER_VAR_974, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_973+currStrOff, ";", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_975 =____BAH_COMPILER_VAR_973;INIT = INIT->add(INIT, rope(____BAH_COMPILER_VAR_975));
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
char * ____BAH_COMPILER_VAR_976 =null;char * ____BAH_COMPILER_VAR_977 =intToStr(totalLexerTime/1000000);char * ____BAH_COMPILER_VAR_978 =intToStr(totalTime/1000000);char * ____BAH_COMPILER_VAR_979 =intToStr(totalLines);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_977);
long int strLen_1 = strlen("ms)\e[0m");
long int strLen_2 = strlen("ms, lexer time: ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_978);
long int strLen_4 = strlen(" lines, total time: ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_979);
long int strLen_6 = strlen("Parsed. (");
;                            
            ____BAH_COMPILER_VAR_976 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_976+currStrOff, "Parsed. (", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_976+currStrOff, ____BAH_COMPILER_VAR_979, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_976+currStrOff, " lines, total time: ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_976+currStrOff, ____BAH_COMPILER_VAR_978, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_976+currStrOff, "ms, lexer time: ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_976+currStrOff, ____BAH_COMPILER_VAR_977, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_976+currStrOff, "ms)\e[0m", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_980 =____BAH_COMPILER_VAR_976;println(____BAH_COMPILER_VAR_980);
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
char * ____BAH_COMPILER_VAR_981 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fileName);
long int strLen_1 = strlen(".o");
;                            
            ____BAH_COMPILER_VAR_981 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_981+currStrOff, fileName, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_981+currStrOff, ".o", strLen_1);
            currStrOff += strLen_1;
        
        }fileName = ____BAH_COMPILER_VAR_981;
obj = "-c";
}
char * randFileName = "-x c - -x none";
char * ____BAH_COMPILER_VAR_982 =null;
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
            ____BAH_COMPILER_VAR_982 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13+strLen_14+strLen_15+strLen_16);
            
                    memcpy(____BAH_COMPILER_VAR_982+currStrOff, BAH_CC, strLen_16);
                    currStrOff += strLen_16;
                    
                    memcpy(____BAH_COMPILER_VAR_982+currStrOff, " -I \"", strLen_15);
                    currStrOff += strLen_15;
                    
                    memcpy(____BAH_COMPILER_VAR_982+currStrOff, BAH_DIR, strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_982+currStrOff, "libs/", strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_982+currStrOff, BAH_OS, strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_982+currStrOff, "/include/\" -L \"", strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_982+currStrOff, BAH_DIR, strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_982+currStrOff, "libs/", strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_982+currStrOff, BAH_OS, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_982+currStrOff, "/\" ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_982+currStrOff, randFileName, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_982+currStrOff, " ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_982+currStrOff, isStatic, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_982+currStrOff, " ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_982+currStrOff, obj, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_982+currStrOff, " -w -O1 -o ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_982+currStrOff, fileName, strLen_1);
            currStrOff += strLen_1;
        
        }char * gccArgs = ____BAH_COMPILER_VAR_982;
if ((flags.isSet(&flags,"l")==1)) {
char * ____BAH_COMPILER_VAR_983 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(gccArgs);
long int strLen_1 = strlen(" -c");
;                            
            ____BAH_COMPILER_VAR_983 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_983+currStrOff, gccArgs, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_983+currStrOff, " -c", strLen_1);
            currStrOff += strLen_1;
        
        }gccArgs = ____BAH_COMPILER_VAR_983;
}
array(char *)* cLibs = compilerState.cLibs;
register long int i = 0;
while ((i<len(cLibs))) {
char * l = cLibs->data[i];
char * ____BAH_COMPILER_VAR_984 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(" -");
long int strLen_1 = strlen(l);
long int strLen_2 = strlen(gccArgs);
;                            
            ____BAH_COMPILER_VAR_984 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_984+currStrOff, gccArgs, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_984+currStrOff, " -", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_984+currStrOff, l, strLen_1);
            currStrOff += strLen_1;
        
        }gccArgs = ____BAH_COMPILER_VAR_984;
i = i+1;
};
struct command cmd = command(gccArgs);
cmd.input = OUTPUT->toStr(OUTPUT);
if ((flags.isSet(&flags,"verboseCC")==0)) {
cmd.error = false;
}
if ((flags.isSet(&flags,"verboseCC")==1)) {
char * ____BAH_COMPILER_VAR_985 =cmd.run(&cmd);println(____BAH_COMPILER_VAR_985);
}
else {
char * ____BAH_COMPILER_VAR_986 =cmd.run(&cmd);}
if ((cmd.status!=0)) {
println("\e[1;31m[CC-ERROR]\e[0m\nCould not compiled.");
return 1;
}
if ((flags.isSet(&flags,"l")==1)) {
char * ____BAH_COMPILER_VAR_987 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(".a ");
long int strLen_1 = strlen(fileName);
long int strLen_2 = strlen(fileName);
long int strLen_3 = strlen("ar rcs ");
;                            
            ____BAH_COMPILER_VAR_987 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_987+currStrOff, "ar rcs ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_987+currStrOff, fileName, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_987+currStrOff, ".a ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_987+currStrOff, fileName, strLen_1);
            currStrOff += strLen_1;
        
        }cmd = command(____BAH_COMPILER_VAR_987);
char * ____BAH_COMPILER_VAR_988 =cmd.run(&cmd);}
}
else {
if ((flags.isSet(&flags,"o")==0)) {
char * ____BAH_COMPILER_VAR_989 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fileName);
long int strLen_1 = strlen(".c");
;                            
            ____BAH_COMPILER_VAR_989 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_989+currStrOff, fileName, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_989+currStrOff, ".c", strLen_1);
            currStrOff += strLen_1;
        
        }fileName = ____BAH_COMPILER_VAR_989;
}
char * ____BAH_COMPILER_VAR_990 =null;
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
            ____BAH_COMPILER_VAR_990 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13);
            
                    memcpy(____BAH_COMPILER_VAR_990+currStrOff, BAH_CC, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_990+currStrOff, " -I \"", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_990+currStrOff, BAH_DIR, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_990+currStrOff, "libs/", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_990+currStrOff, BAH_OS, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_990+currStrOff, "/include/\" -L \"", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_990+currStrOff, BAH_DIR, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_990+currStrOff, "libs/", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_990+currStrOff, BAH_OS, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_990+currStrOff, "/\" ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_990+currStrOff, fileName, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_990+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_990+currStrOff, isStatic, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_990+currStrOff, " -O1 -w ", strLen_1);
            currStrOff += strLen_1;
        
        }char * gccArgs = ____BAH_COMPILER_VAR_990;
array(char *)* cLibs = compilerState.cLibs;
register long int i = 0;
while ((i<len(cLibs))) {
char * l = cLibs->data[i];
char * ____BAH_COMPILER_VAR_991 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(" -");
long int strLen_1 = strlen(l);
long int strLen_2 = strlen(gccArgs);
;                            
            ____BAH_COMPILER_VAR_991 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_991+currStrOff, gccArgs, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_991+currStrOff, " -", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_991+currStrOff, l, strLen_1);
            currStrOff += strLen_1;
        
        }gccArgs = ____BAH_COMPILER_VAR_991;
i = i+1;
};
char * ____BAH_COMPILER_VAR_992 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(gccArgs);
long int strLen_1 = strlen("'\n");
long int strLen_2 = strlen("//COMPILE WITH: '");
;                            
            ____BAH_COMPILER_VAR_992 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_992+currStrOff, "//COMPILE WITH: '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_992+currStrOff, gccArgs, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_992+currStrOff, "'\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope(____BAH_COMPILER_VAR_992)->add(rope(____BAH_COMPILER_VAR_992), OUTPUT);
struct fileStream ____BAH_COMPILER_VAR_993 = {};
____BAH_COMPILER_VAR_993.handle= null;
____BAH_COMPILER_VAR_993.name= null;
____BAH_COMPILER_VAR_993.isValid = fileStream__isValid;
____BAH_COMPILER_VAR_993.open = fileStream__open;
____BAH_COMPILER_VAR_993.close = fileStream__close;
____BAH_COMPILER_VAR_993.getPos = fileStream__getPos;
____BAH_COMPILER_VAR_993.setPos = fileStream__setPos;
____BAH_COMPILER_VAR_993.getSize = fileStream__getSize;
____BAH_COMPILER_VAR_993.rewind = fileStream__rewind;
____BAH_COMPILER_VAR_993.getChar = fileStream__getChar;
____BAH_COMPILER_VAR_993.setChar = fileStream__setChar;
____BAH_COMPILER_VAR_993.createFile = fileStream__createFile;
____BAH_COMPILER_VAR_993.writeFile = fileStream__writeFile;
____BAH_COMPILER_VAR_993.writePtr = fileStream__writePtr;
____BAH_COMPILER_VAR_993.readPtr = fileStream__readPtr;
____BAH_COMPILER_VAR_993.readContent = fileStream__readContent;
____BAH_COMPILER_VAR_993.readBytes = fileStream__readBytes;
____BAH_COMPILER_VAR_993.writeBytes = fileStream__writeBytes;
____BAH_COMPILER_VAR_993._end = fileStream___end;
#define fs ____BAH_COMPILER_VAR_993
fs.open(&fs,fileName,"w");
char * ____BAH_COMPILER_VAR_994 =OUTPUT->toStr(OUTPUT);fs.writeFile(&fs,____BAH_COMPILER_VAR_994);
fs.close(&fs);

#undef fs
}
if ((isObject==false)) {
long int totalTime = getTimeUnix()-startTime;
char * ____BAH_COMPILER_VAR_995 =null;char * ____BAH_COMPILER_VAR_996 =intToStr(totalTime/1000000);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_996);
long int strLen_1 = strlen("ms)\e[0m");
long int strLen_2 = strlen("\e[1;32mDone. (compiled in ");
;                            
            ____BAH_COMPILER_VAR_995 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_995+currStrOff, "\e[1;32mDone. (compiled in ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_995+currStrOff, ____BAH_COMPILER_VAR_996, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_995+currStrOff, "ms)\e[0m", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_997 =____BAH_COMPILER_VAR_995;println(____BAH_COMPILER_VAR_997);
}
return 0;
};
volatile struct __Bah_fnName_mapper __tmp____Bah_fnNames[295];
    
    void __attribute__((optimize("O0"))) __BAH_init() {
        __BAH_panic_chan = null;
__Bah_fnNames = memoryAlloc(sizeof(array(struct __Bah_fnName_mapper)));

__Bah_fnNames->length = 0;
__Bah_fnNames->elemSize = sizeof(struct __Bah_fnName_mapper);
onMemoryError = null;
__Bah_init_segfaultHandle_OK = __Bah_init_segfaultHandle();
RAND_SEEDED = 0;
BAH_DIR = "/opt/bah/";
BAH_OS = "linux";
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

            __tmp____Bah_fnNames[14].n = "allocateArray";
            __tmp____Bah_fnNames[14].p = allocateArray;

            __tmp____Bah_fnNames[15].n = "__serialize";
            __tmp____Bah_fnNames[15].p = __serialize;

            __tmp____Bah_fnNames[16].n = "serlen";
            __tmp____Bah_fnNames[16].p = serlen;

            __tmp____Bah_fnNames[17].n = "unser";
            __tmp____Bah_fnNames[17].p = unser;

            __tmp____Bah_fnNames[18].n = "memoryAllocSTR";
            __tmp____Bah_fnNames[18].p = memoryAllocSTR;

            __tmp____Bah_fnNames[19].n = "delete";
            __tmp____Bah_fnNames[19].p = delete;

            __tmp____Bah_fnNames[20].n = "deleteRange";
            __tmp____Bah_fnNames[20].p = deleteRange;

            __tmp____Bah_fnNames[21].n = "arrToStr";
            __tmp____Bah_fnNames[21].p = arrToStr;

            __tmp____Bah_fnNames[22].n = "strToArr";
            __tmp____Bah_fnNames[22].p = strToArr;

            __tmp____Bah_fnNames[23].n = "arrAsStr";
            __tmp____Bah_fnNames[23].p = arrAsStr;

            __tmp____Bah_fnNames[24].n = "strAsArr";
            __tmp____Bah_fnNames[24].p = strAsArr;

            __tmp____Bah_fnNames[25].n = "strTrimLeft";
            __tmp____Bah_fnNames[25].p = strTrimLeft;

            __tmp____Bah_fnNames[26].n = "strTrimRight";
            __tmp____Bah_fnNames[26].p = strTrimRight;

            __tmp____Bah_fnNames[27].n = "concatCPSTRING";
            __tmp____Bah_fnNames[27].p = concatCPSTRING;

            __tmp____Bah_fnNames[28].n = "__STR";
            __tmp____Bah_fnNames[28].p = __STR;

            __tmp____Bah_fnNames[29].n = "print";
            __tmp____Bah_fnNames[29].p = print;

            __tmp____Bah_fnNames[30].n = "cArr";
            __tmp____Bah_fnNames[30].p = cArr;

            __tmp____Bah_fnNames[31].n = "__checkString";
            __tmp____Bah_fnNames[31].p = __checkString;

            __tmp____Bah_fnNames[32].n = "mutex.init";
            __tmp____Bah_fnNames[32].p = mutex__init;

            __tmp____Bah_fnNames[33].n = "mutex.lock";
            __tmp____Bah_fnNames[33].p = mutex__lock;

            __tmp____Bah_fnNames[34].n = "mutex.unlock";
            __tmp____Bah_fnNames[34].p = mutex__unlock;

            __tmp____Bah_fnNames[35].n = "mutex.destroy";
            __tmp____Bah_fnNames[35].p = mutex__destroy;

            __tmp____Bah_fnNames[36].n = "mutexCondition.init";
            __tmp____Bah_fnNames[36].p = mutexCondition__init;

            __tmp____Bah_fnNames[37].n = "mutexCondition.wait";
            __tmp____Bah_fnNames[37].p = mutexCondition__wait;

            __tmp____Bah_fnNames[38].n = "mutexCondition.send";
            __tmp____Bah_fnNames[38].p = mutexCondition__send;

            __tmp____Bah_fnNames[39].n = "mutexCondition.destroy";
            __tmp____Bah_fnNames[39].p = mutexCondition__destroy;

            __tmp____Bah_fnNames[40].n = "mutexCondition";
            __tmp____Bah_fnNames[40].p = mutexCondition;

            __tmp____Bah_fnNames[41].n = "thread.create";
            __tmp____Bah_fnNames[41].p = thread__create;

            __tmp____Bah_fnNames[42].n = "thread.createWithArg";
            __tmp____Bah_fnNames[42].p = thread__createWithArg;

            __tmp____Bah_fnNames[43].n = "thread.wait";
            __tmp____Bah_fnNames[43].p = thread__wait;

            __tmp____Bah_fnNames[44].n = "mutex";
            __tmp____Bah_fnNames[44].p = mutex;

            __tmp____Bah_fnNames[45].n = "queue.insert";
            __tmp____Bah_fnNames[45].p = queue__insert;

            __tmp____Bah_fnNames[46].n = "queue.delete";
            __tmp____Bah_fnNames[46].p = queue__delete;

            __tmp____Bah_fnNames[47].n = "queue.get";
            __tmp____Bah_fnNames[47].p = queue__get;

            __tmp____Bah_fnNames[48].n = "queue.set";
            __tmp____Bah_fnNames[48].p = queue__set;

            __tmp____Bah_fnNames[49].n = "queue.pop";
            __tmp____Bah_fnNames[49].p = queue__pop;

            __tmp____Bah_fnNames[50].n = "queue.clear";
            __tmp____Bah_fnNames[50].p = queue__clear;

            __tmp____Bah_fnNames[51].n = "channel.send";
            __tmp____Bah_fnNames[51].p = channel__send;

            __tmp____Bah_fnNames[52].n = "channel.sendAny";
            __tmp____Bah_fnNames[52].p = channel__sendAny;

            __tmp____Bah_fnNames[53].n = "channel.receive";
            __tmp____Bah_fnNames[53].p = channel__receive;

            __tmp____Bah_fnNames[54].n = "channel.destroy";
            __tmp____Bah_fnNames[54].p = channel__destroy;

            __tmp____Bah_fnNames[55].n = "channel.len";
            __tmp____Bah_fnNames[55].p = channel__len;

            __tmp____Bah_fnNames[56].n = "channel";
            __tmp____Bah_fnNames[56].p = channel;

            __tmp____Bah_fnNames[57].n = "setChanCap";
            __tmp____Bah_fnNames[57].p = setChanCap;

            __tmp____Bah_fnNames[58].n = "__Bah_common_panic";
            __tmp____Bah_fnNames[58].p = __Bah_common_panic;

            __tmp____Bah_fnNames[59].n = "__Bah_fnNames_append";
            __tmp____Bah_fnNames[59].p = __Bah_fnNames_append;

            __tmp____Bah_fnNames[60].n = "__Bah_segfault_handle";
            __tmp____Bah_fnNames[60].p = __Bah_segfault_handle;

            __tmp____Bah_fnNames[61].n = "__Bah_init_segfaultHandle";
            __tmp____Bah_fnNames[61].p = __Bah_init_segfaultHandle;

            __tmp____Bah_fnNames[62].n = "recover";
            __tmp____Bah_fnNames[62].p = recover;

            __tmp____Bah_fnNames[63].n = "cpstringCharAt";
            __tmp____Bah_fnNames[63].p = cpstringCharAt;

            __tmp____Bah_fnNames[64].n = "cpstringSubsitute";
            __tmp____Bah_fnNames[64].p = cpstringSubsitute;

            __tmp____Bah_fnNames[65].n = "arraySubstitute";
            __tmp____Bah_fnNames[65].p = arraySubstitute;

            __tmp____Bah_fnNames[66].n = "__Bah_map_hash";
            __tmp____Bah_fnNames[66].p = __Bah_map_hash;

            __tmp____Bah_fnNames[67].n = "mapWrapper.grow";
            __tmp____Bah_fnNames[67].p = mapWrapper__grow;

            __tmp____Bah_fnNames[68].n = "mapWrapper.set";
            __tmp____Bah_fnNames[68].p = mapWrapper__set;

            __tmp____Bah_fnNames[69].n = "mapWrapper.setAny";
            __tmp____Bah_fnNames[69].p = mapWrapper__setAny;

            __tmp____Bah_fnNames[70].n = "mapWrapper.delete";
            __tmp____Bah_fnNames[70].p = mapWrapper__delete;

            __tmp____Bah_fnNames[71].n = "mapWrapper.get";
            __tmp____Bah_fnNames[71].p = mapWrapper__get;

            __tmp____Bah_fnNames[72].n = "mapWrapper";
            __tmp____Bah_fnNames[72].p = mapWrapper;

            __tmp____Bah_fnNames[73].n = "stdinput";
            __tmp____Bah_fnNames[73].p = stdinput;

            __tmp____Bah_fnNames[74].n = "println";
            __tmp____Bah_fnNames[74].p = println;

            __tmp____Bah_fnNames[75].n = "fileStream.isValid";
            __tmp____Bah_fnNames[75].p = fileStream__isValid;

            __tmp____Bah_fnNames[76].n = "fileStream.open";
            __tmp____Bah_fnNames[76].p = fileStream__open;

            __tmp____Bah_fnNames[77].n = "fileStream.close";
            __tmp____Bah_fnNames[77].p = fileStream__close;

            __tmp____Bah_fnNames[78].n = "fileStream.getPos";
            __tmp____Bah_fnNames[78].p = fileStream__getPos;

            __tmp____Bah_fnNames[79].n = "fileStream.setPos";
            __tmp____Bah_fnNames[79].p = fileStream__setPos;

            __tmp____Bah_fnNames[80].n = "fileStream.getSize";
            __tmp____Bah_fnNames[80].p = fileStream__getSize;

            __tmp____Bah_fnNames[81].n = "fileStream.rewind";
            __tmp____Bah_fnNames[81].p = fileStream__rewind;

            __tmp____Bah_fnNames[82].n = "fileStream.getChar";
            __tmp____Bah_fnNames[82].p = fileStream__getChar;

            __tmp____Bah_fnNames[83].n = "fileStream.setChar";
            __tmp____Bah_fnNames[83].p = fileStream__setChar;

            __tmp____Bah_fnNames[84].n = "fileStream.createFile";
            __tmp____Bah_fnNames[84].p = fileStream__createFile;

            __tmp____Bah_fnNames[85].n = "fileStream.writeFile";
            __tmp____Bah_fnNames[85].p = fileStream__writeFile;

            __tmp____Bah_fnNames[86].n = "fileStream.writePtr";
            __tmp____Bah_fnNames[86].p = fileStream__writePtr;

            __tmp____Bah_fnNames[87].n = "fileStream.readPtr";
            __tmp____Bah_fnNames[87].p = fileStream__readPtr;

            __tmp____Bah_fnNames[88].n = "fileStream.readContent";
            __tmp____Bah_fnNames[88].p = fileStream__readContent;

            __tmp____Bah_fnNames[89].n = "fileStream.readBytes";
            __tmp____Bah_fnNames[89].p = fileStream__readBytes;

            __tmp____Bah_fnNames[90].n = "fileStream.writeBytes";
            __tmp____Bah_fnNames[90].p = fileStream__writeBytes;

            __tmp____Bah_fnNames[91].n = "fileStream._end";
            __tmp____Bah_fnNames[91].p = fileStream___end;

            __tmp____Bah_fnNames[92].n = "fileMap.open";
            __tmp____Bah_fnNames[92].p = fileMap__open;

            __tmp____Bah_fnNames[93].n = "fileMap.isValid";
            __tmp____Bah_fnNames[93].p = fileMap__isValid;

            __tmp____Bah_fnNames[94].n = "fileMap.close";
            __tmp____Bah_fnNames[94].p = fileMap__close;

            __tmp____Bah_fnNames[95].n = "listFiles";
            __tmp____Bah_fnNames[95].p = listFiles;

            __tmp____Bah_fnNames[96].n = "fileExists";
            __tmp____Bah_fnNames[96].p = fileExists;

            __tmp____Bah_fnNames[97].n = "removeFile";
            __tmp____Bah_fnNames[97].p = removeFile;

            __tmp____Bah_fnNames[98].n = "getLastModified";
            __tmp____Bah_fnNames[98].p = getLastModified;

            __tmp____Bah_fnNames[99].n = "strCatOffset";
            __tmp____Bah_fnNames[99].p = strCatOffset;

            __tmp____Bah_fnNames[100].n = "charToString";
            __tmp____Bah_fnNames[100].p = charToString;

            __tmp____Bah_fnNames[101].n = "isUpper";
            __tmp____Bah_fnNames[101].p = isUpper;

            __tmp____Bah_fnNames[102].n = "isLower";
            __tmp____Bah_fnNames[102].p = isLower;

            __tmp____Bah_fnNames[103].n = "isLetter";
            __tmp____Bah_fnNames[103].p = isLetter;

            __tmp____Bah_fnNames[104].n = "isNumber";
            __tmp____Bah_fnNames[104].p = isNumber;

            __tmp____Bah_fnNames[105].n = "isAlphaNumeric";
            __tmp____Bah_fnNames[105].p = isAlphaNumeric;

            __tmp____Bah_fnNames[106].n = "isSpace";
            __tmp____Bah_fnNames[106].p = isSpace;

            __tmp____Bah_fnNames[107].n = "string.set";
            __tmp____Bah_fnNames[107].p = string__set;

            __tmp____Bah_fnNames[108].n = "string.makeEditable";
            __tmp____Bah_fnNames[108].p = string__makeEditable;

            __tmp____Bah_fnNames[109].n = "string.append";
            __tmp____Bah_fnNames[109].p = string__append;

            __tmp____Bah_fnNames[110].n = "string.prepend";
            __tmp____Bah_fnNames[110].p = string__prepend;

            __tmp____Bah_fnNames[111].n = "string.charAt";
            __tmp____Bah_fnNames[111].p = string__charAt;

            __tmp____Bah_fnNames[112].n = "string.compare";
            __tmp____Bah_fnNames[112].p = string__compare;

            __tmp____Bah_fnNames[113].n = "string.str";
            __tmp____Bah_fnNames[113].p = string__str;

            __tmp____Bah_fnNames[114].n = "string.replace";
            __tmp____Bah_fnNames[114].p = string__replace;

            __tmp____Bah_fnNames[115].n = "string.countChar";
            __tmp____Bah_fnNames[115].p = string__countChar;

            __tmp____Bah_fnNames[116].n = "string.count";
            __tmp____Bah_fnNames[116].p = string__count;

            __tmp____Bah_fnNames[117].n = "string.hasPrefix";
            __tmp____Bah_fnNames[117].p = string__hasPrefix;

            __tmp____Bah_fnNames[118].n = "string.hasSuffix";
            __tmp____Bah_fnNames[118].p = string__hasSuffix;

            __tmp____Bah_fnNames[119].n = "string.trim";
            __tmp____Bah_fnNames[119].p = string__trim;

            __tmp____Bah_fnNames[120].n = "string.trimLeft";
            __tmp____Bah_fnNames[120].p = string__trimLeft;

            __tmp____Bah_fnNames[121].n = "string.trimRight";
            __tmp____Bah_fnNames[121].p = string__trimRight;

            __tmp____Bah_fnNames[122].n = "string.add";
            __tmp____Bah_fnNames[122].p = string__add;

            __tmp____Bah_fnNames[123].n = "string";
            __tmp____Bah_fnNames[123].p = string;

            __tmp____Bah_fnNames[124].n = "intToStr";
            __tmp____Bah_fnNames[124].p = intToStr;

            __tmp____Bah_fnNames[125].n = "intToString";
            __tmp____Bah_fnNames[125].p = intToString;

            __tmp____Bah_fnNames[126].n = "floatToStr";
            __tmp____Bah_fnNames[126].p = floatToStr;

            __tmp____Bah_fnNames[127].n = "strToInt";
            __tmp____Bah_fnNames[127].p = strToInt;

            __tmp____Bah_fnNames[128].n = "strToFloat";
            __tmp____Bah_fnNames[128].p = strToFloat;

            __tmp____Bah_fnNames[129].n = "stringToInt";
            __tmp____Bah_fnNames[129].p = stringToInt;

            __tmp____Bah_fnNames[130].n = "splitString";
            __tmp____Bah_fnNames[130].p = splitString;

            __tmp____Bah_fnNames[131].n = "joinString";
            __tmp____Bah_fnNames[131].p = joinString;

            __tmp____Bah_fnNames[132].n = "splitStringBefore";
            __tmp____Bah_fnNames[132].p = splitStringBefore;

            __tmp____Bah_fnNames[133].n = "toLower";
            __tmp____Bah_fnNames[133].p = toLower;

            __tmp____Bah_fnNames[134].n = "strHasPrefix";
            __tmp____Bah_fnNames[134].p = strHasPrefix;

            __tmp____Bah_fnNames[135].n = "strHasSuffix";
            __tmp____Bah_fnNames[135].p = strHasSuffix;

            __tmp____Bah_fnNames[136].n = "strTrim";
            __tmp____Bah_fnNames[136].p = strTrim;

            __tmp____Bah_fnNames[137].n = "strCount";
            __tmp____Bah_fnNames[137].p = strCount;

            __tmp____Bah_fnNames[138].n = "flags.addString";
            __tmp____Bah_fnNames[138].p = flags__addString;

            __tmp____Bah_fnNames[139].n = "flags.addBool";
            __tmp____Bah_fnNames[139].p = flags__addBool;

            __tmp____Bah_fnNames[140].n = "flags.addInt";
            __tmp____Bah_fnNames[140].p = flags__addInt;

            __tmp____Bah_fnNames[141].n = "flags.addFloat";
            __tmp____Bah_fnNames[141].p = flags__addFloat;

            __tmp____Bah_fnNames[142].n = "flags.invalidate";
            __tmp____Bah_fnNames[142].p = flags__invalidate;

            __tmp____Bah_fnNames[143].n = "flags.getFlag";
            __tmp____Bah_fnNames[143].p = flags__getFlag;

            __tmp____Bah_fnNames[144].n = "flags.get";
            __tmp____Bah_fnNames[144].p = flags__get;

            __tmp____Bah_fnNames[145].n = "flags.getInt";
            __tmp____Bah_fnNames[145].p = flags__getInt;

            __tmp____Bah_fnNames[146].n = "flags.getFloat";
            __tmp____Bah_fnNames[146].p = flags__getFloat;

            __tmp____Bah_fnNames[147].n = "flags.isSet";
            __tmp____Bah_fnNames[147].p = flags__isSet;

            __tmp____Bah_fnNames[148].n = "flags.parse";
            __tmp____Bah_fnNames[148].p = flags__parse;

            __tmp____Bah_fnNames[149].n = "time.now";
            __tmp____Bah_fnNames[149].p = time__now;

            __tmp____Bah_fnNames[150].n = "time.format";
            __tmp____Bah_fnNames[150].p = time__format;

            __tmp____Bah_fnNames[151].n = "time.since";
            __tmp____Bah_fnNames[151].p = time__since;

            __tmp____Bah_fnNames[152].n = "getTimeUnix";
            __tmp____Bah_fnNames[152].p = getTimeUnix;

            __tmp____Bah_fnNames[153].n = "seedRandom";
            __tmp____Bah_fnNames[153].p = seedRandom;

            __tmp____Bah_fnNames[154].n = "randomInRange";
            __tmp____Bah_fnNames[154].p = randomInRange;

            __tmp____Bah_fnNames[155].n = "cryptoRand";
            __tmp____Bah_fnNames[155].p = cryptoRand;

            __tmp____Bah_fnNames[156].n = "rope.addStr";
            __tmp____Bah_fnNames[156].p = rope__addStr;

            __tmp____Bah_fnNames[157].n = "rope.toStr";
            __tmp____Bah_fnNames[157].p = rope__toStr;

            __tmp____Bah_fnNames[158].n = "rope.add";
            __tmp____Bah_fnNames[158].p = rope__add;

            __tmp____Bah_fnNames[159].n = "createRopeStructure";
            __tmp____Bah_fnNames[159].p = createRopeStructure;

            __tmp____Bah_fnNames[160].n = "ropeSet";
            __tmp____Bah_fnNames[160].p = ropeSet;

            __tmp____Bah_fnNames[161].n = "concatenateRopes";
            __tmp____Bah_fnNames[161].p = concatenateRopes;

            __tmp____Bah_fnNames[162].n = "rope";
            __tmp____Bah_fnNames[162].p = rope;

            __tmp____Bah_fnNames[163].n = "command.run";
            __tmp____Bah_fnNames[163].p = command__run;

            __tmp____Bah_fnNames[164].n = "command.runBytes";
            __tmp____Bah_fnNames[164].p = command__runBytes;

            __tmp____Bah_fnNames[165].n = "command";
            __tmp____Bah_fnNames[165].p = command;

            __tmp____Bah_fnNames[166].n = "exec";
            __tmp____Bah_fnNames[166].p = exec;

            __tmp____Bah_fnNames[167].n = "inArray";
            __tmp____Bah_fnNames[167].p = inArray;

            __tmp____Bah_fnNames[168].n = "inArrayStr";
            __tmp____Bah_fnNames[168].p = inArrayStr;

            __tmp____Bah_fnNames[169].n = "makeToken";
            __tmp____Bah_fnNames[169].p = makeToken;

            __tmp____Bah_fnNames[170].n = "isMinus";
            __tmp____Bah_fnNames[170].p = isMinus;

            __tmp____Bah_fnNames[171].n = "lexerErr";
            __tmp____Bah_fnNames[171].p = lexerErr;

            __tmp____Bah_fnNames[172].n = "lexer";
            __tmp____Bah_fnNames[172].p = lexer;

            __tmp____Bah_fnNames[173].n = "hasStructSep";
            __tmp____Bah_fnNames[173].p = hasStructSep;

            __tmp____Bah_fnNames[174].n = "splitStructSepBefore";
            __tmp____Bah_fnNames[174].p = splitStructSepBefore;

            __tmp____Bah_fnNames[175].n = "splitStructSepAfter";
            __tmp____Bah_fnNames[175].p = splitStructSepAfter;

            __tmp____Bah_fnNames[176].n = "searchStruct";
            __tmp____Bah_fnNames[176].p = searchStruct;

            __tmp____Bah_fnNames[177].n = "searchStructMemb";
            __tmp____Bah_fnNames[177].p = searchStructMemb;

            __tmp____Bah_fnNames[178].n = "searchFunc";
            __tmp____Bah_fnNames[178].p = searchFunc;

            __tmp____Bah_fnNames[179].n = "parseFnType";
            __tmp____Bah_fnNames[179].p = parseFnType;

            __tmp____Bah_fnNames[180].n = "searchStructMethod";
            __tmp____Bah_fnNames[180].p = searchStructMethod;

            __tmp____Bah_fnNames[181].n = "typeAsStar";
            __tmp____Bah_fnNames[181].p = typeAsStar;

            __tmp____Bah_fnNames[182].n = "isRCPpointerType";
            __tmp____Bah_fnNames[182].p = isRCPpointerType;

            __tmp____Bah_fnNames[183].n = "isRCPtype";
            __tmp____Bah_fnNames[183].p = isRCPtype;

            __tmp____Bah_fnNames[184].n = "getCType";
            __tmp____Bah_fnNames[184].p = getCType;

            __tmp____Bah_fnNames[185].n = "compTypeEquiv";
            __tmp____Bah_fnNames[185].p = compTypeEquiv;

            __tmp____Bah_fnNames[186].n = "compTypes";
            __tmp____Bah_fnNames[186].p = compTypes;

            __tmp____Bah_fnNames[187].n = "reflectElement.calculateOffset";
            __tmp____Bah_fnNames[187].p = reflectElement__calculateOffset;

            __tmp____Bah_fnNames[188].n = "__reflect";
            __tmp____Bah_fnNames[188].p = __reflect;

            __tmp____Bah_fnNames[189].n = "__dumpSymbols";
            __tmp____Bah_fnNames[189].p = __dumpSymbols;

            __tmp____Bah_fnNames[190].n = "__debug_get_sym";
            __tmp____Bah_fnNames[190].p = __debug_get_sym;

            __tmp____Bah_fnNames[191].n = "toJson";
            __tmp____Bah_fnNames[191].p = toJson;

            __tmp____Bah_fnNames[192].n = "json_scan_inner";
            __tmp____Bah_fnNames[192].p = json_scan_inner;

            __tmp____Bah_fnNames[193].n = "jsonElement.get";
            __tmp____Bah_fnNames[193].p = jsonElement__get;

            __tmp____Bah_fnNames[194].n = "jsonElement.str";
            __tmp____Bah_fnNames[194].p = jsonElement__str;

            __tmp____Bah_fnNames[195].n = "jsonElement.scan";
            __tmp____Bah_fnNames[195].p = jsonElement__scan;

            __tmp____Bah_fnNames[196].n = "parseJson";
            __tmp____Bah_fnNames[196].p = parseJson;

            __tmp____Bah_fnNames[197].n = "jsonEscapeStr";
            __tmp____Bah_fnNames[197].p = jsonEscapeStr;

            __tmp____Bah_fnNames[198].n = "toJson__inner";
            __tmp____Bah_fnNames[198].p = toJson__inner;

            __tmp____Bah_fnNames[199].n = "debugStart";
            __tmp____Bah_fnNames[199].p = debugStart;

            __tmp____Bah_fnNames[200].n = "debugPrint";
            __tmp____Bah_fnNames[200].p = debugPrint;

            __tmp____Bah_fnNames[201].n = "debugError";
            __tmp____Bah_fnNames[201].p = debugError;

            __tmp____Bah_fnNames[202].n = "debugEnd";
            __tmp____Bah_fnNames[202].p = debugEnd;

            __tmp____Bah_fnNames[203].n = "debugExit";
            __tmp____Bah_fnNames[203].p = debugExit;

            __tmp____Bah_fnNames[204].n = "debugEndScope";
            __tmp____Bah_fnNames[204].p = debugEndScope;

            __tmp____Bah_fnNames[205].n = "throwErr";
            __tmp____Bah_fnNames[205].p = throwErr;

            __tmp____Bah_fnNames[206].n = "throwWarning";
            __tmp____Bah_fnNames[206].p = throwWarning;

            __tmp____Bah_fnNames[207].n = "absPath";
            __tmp____Bah_fnNames[207].p = absPath;

            __tmp____Bah_fnNames[208].n = "getCurrentPath";
            __tmp____Bah_fnNames[208].p = getCurrentPath;

            __tmp____Bah_fnNames[209].n = "isInside";
            __tmp____Bah_fnNames[209].p = isInside;

            __tmp____Bah_fnNames[210].n = "setCurrentPath";
            __tmp____Bah_fnNames[210].p = setCurrentPath;

            __tmp____Bah_fnNames[211].n = "isGlobal";
            __tmp____Bah_fnNames[211].p = isGlobal;

            __tmp____Bah_fnNames[212].n = "getRealVar";
            __tmp____Bah_fnNames[212].p = getRealVar;

            __tmp____Bah_fnNames[213].n = "searchVar";
            __tmp____Bah_fnNames[213].p = searchVar;

            __tmp____Bah_fnNames[214].n = "searchVarByToken";
            __tmp____Bah_fnNames[214].p = searchVarByToken;

            __tmp____Bah_fnNames[215].n = "setCType";
            __tmp____Bah_fnNames[215].p = setCType;

            __tmp____Bah_fnNames[216].n = "getTypeFromToken";
            __tmp____Bah_fnNames[216].p = getTypeFromToken;

            __tmp____Bah_fnNames[217].n = "searchFuncByToken";
            __tmp____Bah_fnNames[217].p = searchFuncByToken;

            __tmp____Bah_fnNames[218].n = "RCPavailable";
            __tmp____Bah_fnNames[218].p = RCPavailable;

            __tmp____Bah_fnNames[219].n = "declareStructMethods";
            __tmp____Bah_fnNames[219].p = declareStructMethods;

            __tmp____Bah_fnNames[220].n = "genCompilerVar";
            __tmp____Bah_fnNames[220].p = genCompilerVar;

            __tmp____Bah_fnNames[221].n = "varInArr";
            __tmp____Bah_fnNames[221].p = varInArr;

            __tmp____Bah_fnNames[222].n = "pathToVarName";
            __tmp____Bah_fnNames[222].p = pathToVarName;

            __tmp____Bah_fnNames[223].n = "makeInit";
            __tmp____Bah_fnNames[223].p = makeInit;

            __tmp____Bah_fnNames[224].n = "isOutterScope";
            __tmp____Bah_fnNames[224].p = isOutterScope;

            __tmp____Bah_fnNames[225].n = "decrVar";
            __tmp____Bah_fnNames[225].p = decrVar;

            __tmp____Bah_fnNames[226].n = "incrVar";
            __tmp____Bah_fnNames[226].p = incrVar;

            __tmp____Bah_fnNames[227].n = "beginRCPscope";
            __tmp____Bah_fnNames[227].p = beginRCPscope;

            __tmp____Bah_fnNames[228].n = "beginRCPscopeLeaky";
            __tmp____Bah_fnNames[228].p = beginRCPscopeLeaky;

            __tmp____Bah_fnNames[229].n = "removeDefs";
            __tmp____Bah_fnNames[229].p = removeDefs;

            __tmp____Bah_fnNames[230].n = "endRCPscope";
            __tmp____Bah_fnNames[230].p = endRCPscope;

            __tmp____Bah_fnNames[231].n = "endRCPscopeLeaky";
            __tmp____Bah_fnNames[231].p = endRCPscopeLeaky;

            __tmp____Bah_fnNames[232].n = "registerRCPvar";
            __tmp____Bah_fnNames[232].p = registerRCPvar;

            __tmp____Bah_fnNames[233].n = "RCPselfRef";
            __tmp____Bah_fnNames[233].p = RCPselfRef;

            __tmp____Bah_fnNames[234].n = "verboseOutGuard";
            __tmp____Bah_fnNames[234].p = verboseOutGuard;

            __tmp____Bah_fnNames[235].n = "verboseOutTransformVar";
            __tmp____Bah_fnNames[235].p = verboseOutTransformVar;

            __tmp____Bah_fnNames[236].n = "verboseOutTransformTok";
            __tmp____Bah_fnNames[236].p = verboseOutTransformTok;

            __tmp____Bah_fnNames[237].n = "verboseOutFunc";
            __tmp____Bah_fnNames[237].p = verboseOutFunc;

            __tmp____Bah_fnNames[238].n = "verboseOutOper";
            __tmp____Bah_fnNames[238].p = verboseOutOper;

            __tmp____Bah_fnNames[239].n = "readCache";
            __tmp____Bah_fnNames[239].p = readCache;

            __tmp____Bah_fnNames[240].n = "getCacheFile";
            __tmp____Bah_fnNames[240].p = getCacheFile;

            __tmp____Bah_fnNames[241].n = "updateCacheFile";
            __tmp____Bah_fnNames[241].p = updateCacheFile;

            __tmp____Bah_fnNames[242].n = "makeCacheFile";
            __tmp____Bah_fnNames[242].p = makeCacheFile;

            __tmp____Bah_fnNames[243].n = "writeCache";
            __tmp____Bah_fnNames[243].p = writeCache;

            __tmp____Bah_fnNames[244].n = "isValidCacheFile";
            __tmp____Bah_fnNames[244].p = isValidCacheFile;

            __tmp____Bah_fnNames[245].n = "debugLine";
            __tmp____Bah_fnNames[245].p = debugLine;

            __tmp____Bah_fnNames[246].n = "dupElems";
            __tmp____Bah_fnNames[246].p = dupElems;

            __tmp____Bah_fnNames[247].n = "getLineType";
            __tmp____Bah_fnNames[247].p = getLineType;

            __tmp____Bah_fnNames[248].n = "parseCast";
            __tmp____Bah_fnNames[248].p = parseCast;

            __tmp____Bah_fnNames[249].n = "getDirFromFile";
            __tmp____Bah_fnNames[249].p = getDirFromFile;

            __tmp____Bah_fnNames[250].n = "parseLines";
            __tmp____Bah_fnNames[250].p = parseLines;

            __tmp____Bah_fnNames[251].n = "includeFile";
            __tmp____Bah_fnNames[251].p = includeFile;

            __tmp____Bah_fnNames[252].n = "parallelObjCompile";
            __tmp____Bah_fnNames[252].p = parallelObjCompile;

            __tmp____Bah_fnNames[253].n = "parseImport";
            __tmp____Bah_fnNames[253].p = parseImport;

            __tmp____Bah_fnNames[254].n = "parseInclude";
            __tmp____Bah_fnNames[254].p = parseInclude;

            __tmp____Bah_fnNames[255].n = "prePross";
            __tmp____Bah_fnNames[255].p = prePross;

            __tmp____Bah_fnNames[256].n = "parseStructType";
            __tmp____Bah_fnNames[256].p = parseStructType;

            __tmp____Bah_fnNames[257].n = "parseArrayType";
            __tmp____Bah_fnNames[257].p = parseArrayType;

            __tmp____Bah_fnNames[258].n = "parsePointers";
            __tmp____Bah_fnNames[258].p = parsePointers;

            __tmp____Bah_fnNames[259].n = "parseSerialize";
            __tmp____Bah_fnNames[259].p = parseSerialize;

            __tmp____Bah_fnNames[260].n = "parseReflect";
            __tmp____Bah_fnNames[260].p = parseReflect;

            __tmp____Bah_fnNames[261].n = "parseArrayDecl";
            __tmp____Bah_fnNames[261].p = parseArrayDecl;

            __tmp____Bah_fnNames[262].n = "parseVar";
            __tmp____Bah_fnNames[262].p = parseVar;

            __tmp____Bah_fnNames[263].n = "getCfunctionType";
            __tmp____Bah_fnNames[263].p = getCfunctionType;

            __tmp____Bah_fnNames[264].n = "parseFnHeader";
            __tmp____Bah_fnNames[264].p = parseFnHeader;

            __tmp____Bah_fnNames[265].n = "parseStruct";
            __tmp____Bah_fnNames[265].p = parseStruct;

            __tmp____Bah_fnNames[266].n = "parseDefine";
            __tmp____Bah_fnNames[266].p = parseDefine;

            __tmp____Bah_fnNames[267].n = "parseClib";
            __tmp____Bah_fnNames[267].p = parseClib;

            __tmp____Bah_fnNames[268].n = "parseConst";
            __tmp____Bah_fnNames[268].p = parseConst;

            __tmp____Bah_fnNames[269].n = "parseReturn";
            __tmp____Bah_fnNames[269].p = parseReturn;

            __tmp____Bah_fnNames[270].n = "parseIf";
            __tmp____Bah_fnNames[270].p = parseIf;

            __tmp____Bah_fnNames[271].n = "parseElse";
            __tmp____Bah_fnNames[271].p = parseElse;

            __tmp____Bah_fnNames[272].n = "parseLine";
            __tmp____Bah_fnNames[272].p = parseLine;

            __tmp____Bah_fnNames[273].n = "parseFor";
            __tmp____Bah_fnNames[273].p = parseFor;

            __tmp____Bah_fnNames[274].n = "parseForOp";
            __tmp____Bah_fnNames[274].p = parseForOp;

            __tmp____Bah_fnNames[275].n = "makeEvalFunc";
            __tmp____Bah_fnNames[275].p = makeEvalFunc;

            __tmp____Bah_fnNames[276].n = "parsePreKeyword";
            __tmp____Bah_fnNames[276].p = parsePreKeyword;

            __tmp____Bah_fnNames[277].n = "parseAsync";
            __tmp____Bah_fnNames[277].p = parseAsync;

            __tmp____Bah_fnNames[278].n = "addRCPvars";
            __tmp____Bah_fnNames[278].p = addRCPvars;

            __tmp____Bah_fnNames[279].n = "parseChan";
            __tmp____Bah_fnNames[279].p = parseChan;

            __tmp____Bah_fnNames[280].n = "valueFunc";
            __tmp____Bah_fnNames[280].p = valueFunc;

            __tmp____Bah_fnNames[281].n = "valueStruct";
            __tmp____Bah_fnNames[281].p = valueStruct;

            __tmp____Bah_fnNames[282].n = "valueArr";
            __tmp____Bah_fnNames[282].p = valueArr;

            __tmp____Bah_fnNames[283].n = "valueBool";
            __tmp____Bah_fnNames[283].p = valueBool;

            __tmp____Bah_fnNames[284].n = "valueOper";
            __tmp____Bah_fnNames[284].p = valueOper;

            __tmp____Bah_fnNames[285].n = "valueSendChan";
            __tmp____Bah_fnNames[285].p = valueSendChan;

            __tmp____Bah_fnNames[286].n = "valueChan";
            __tmp____Bah_fnNames[286].p = valueChan;

            __tmp____Bah_fnNames[287].n = "isSmallValue";
            __tmp____Bah_fnNames[287].p = isSmallValue;

            __tmp____Bah_fnNames[288].n = "isValue";
            __tmp____Bah_fnNames[288].p = isValue;

            __tmp____Bah_fnNames[289].n = "parseFnDeclare";
            __tmp____Bah_fnNames[289].p = parseFnDeclare;

            __tmp____Bah_fnNames[290].n = "declareFunc";
            __tmp____Bah_fnNames[290].p = declareFunc;

            __tmp____Bah_fnNames[291].n = "declareVar";
            __tmp____Bah_fnNames[291].p = declareVar;

            __tmp____Bah_fnNames[292].n = "declareAll";
            __tmp____Bah_fnNames[292].p = declareAll;

            __tmp____Bah_fnNames[293].n = "memErrHandle";
            __tmp____Bah_fnNames[293].p = memErrHandle;

            __tmp____Bah_fnNames[294].n = "main";
            __tmp____Bah_fnNames[294].p = main;

        __Bah_fnNames->data = __tmp____Bah_fnNames;
        __Bah_fnNames->length = 295;
        
    };
    