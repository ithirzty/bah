//COMPILE WITH: 'x86_64-w64-mingw32-gcc -I "/opt/bah/libs/windows/include/" -L "/opt/bah/libs/windows/" ../installer/windows.c -static -O1 -w  -l:gc.a -lpthread -lm'

    void __BAH_init();
    #define noCheck(v) v
    #define array(type)	    struct{	    type *data;     long int length;     long int elemSize;     }
    typedef array(char*)* __BAH_ARR_TYPE_cpstring;
    long int __BAH__main(__BAH_ARR_TYPE_cpstring);
    
            #include <gc.h>
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
char * __Bah_safe_string(char * s);
#define null (void *)0
#define true (char)1
#define false (char)0
long int __bah_strcmp(char * a,char * b){
if (((void *)a==null)) {
a =  "";
}
if (((void *)b==null)) {
b =  "";
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
long int i =  0;
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
//optimized out: append
//optimized out: copy
#define PROT_READ 2
#define PROT_READWRITE 4
void * GLOBAL_MAPPED_MEMORY_FILE;
//optimized out: sharedMemory
//optimized out: closeSharedMemory
void allocateArray(void * arr,long int nbElems){
array(void*)*a=arr;
a->length=nbElems;
a->data=memoryAlloc(nbElems*a->elemSize);
};
typedef array(char)* __BAH_ARR_TYPE_char;
__BAH_ARR_TYPE_char ser(void * a);
//optimized out: __serialize
long int serlen(__BAH_ARR_TYPE_char data){

                    if (data->length <= 0) {
                        printf("array (/opt/bah/memory.bah:194): data[%d] with length %d\n", 0, data->length);
                        exit(1);
                    };
                    
                    if (data->length <= 1) {
                        printf("array (/opt/bah/memory.bah:194): data[%d] with length %d\n", 1, data->length);
                        exit(1);
                    };
                    
                    if (data->length <= 2) {
                        printf("array (/opt/bah/memory.bah:194): data[%d] with length %d\n", 2, data->length);
                        exit(1);
                    };
                    
                    if (data->length <= 3) {
                        printf("array (/opt/bah/memory.bah:194): data[%d] with length %d\n", 3, data->length);
                        exit(1);
                    };
                    
                    if (data->length <= 4) {
                        printf("array (/opt/bah/memory.bah:194): data[%d] with length %d\n", 4, data->length);
                        exit(1);
                    };
                    
                    if (data->length <= 5) {
                        printf("array (/opt/bah/memory.bah:194): data[%d] with length %d\n", 5, data->length);
                        exit(1);
                    };
                    
                    if (data->length <= 6) {
                        printf("array (/opt/bah/memory.bah:194): data[%d] with length %d\n", 6, data->length);
                        exit(1);
                    };
                    
                    if (data->length <= 7) {
                        printf("array (/opt/bah/memory.bah:194): data[%d] with length %d\n", 7, data->length);
                        exit(1);
                    };
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
//optimized out: unser
char * memoryAllocSTR(long int s){
char * r =  GC_malloc_atomic(s);
r[s-1]=0;
return r;
};
//optimized out: delete
char * arrToStr(__BAH_ARR_TYPE_char arr){
long int strLen =  len(arr);
char * str =  memoryAlloc(strLen + 1);
memcpy(str,arr->data,strLen);
return str;
};
__BAH_ARR_TYPE_char strToArr(char * str){
long int strLen =  strlen(str);
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
long int l =  strlen(str);
array(char)* arr = memoryAlloc(sizeof(array(char)));

arr->length = 0;
arr->elemSize = sizeof(char);
arr->length=l;
arr->data=str;
return arr;
};
void strTrimLeft(char ** s,long int i){
long int ls =  strlen(*s);
char * ns =  memoryAlloc(ls - i + 1);
memcpy(ns,*s+i,ls - i);
*s =  ns;
};
void strTrimRight(char ** s,long int i){
long int ls =  strlen(*s);
char * ns =  memoryAlloc(ls - i + 1);
memcpy(ns,*s,ls - i);
*s =  ns;
};
#define __bah_memory_realloc memoryRealloc
#define __bah_memory_str memoryAllocSTR
//optimized out: concatCPSTRING
char * __STR(char * a){
long int lenA =  strlen(a);
char * r =  memoryAllocSTR(lenA + 1);
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
//optimized out: cArr
//optimized out: __checkString
#include <pthread.h>
#define __thread_create pthread_create
#define __thread_join pthread_join
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
pthread_mutex_t mid =  m.id;
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
struct mutexCondition m =  ____BAH_COMPILER_VAR_1;
m.init((struct mutexCondition*)&m);
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
struct mutex m =  ____BAH_COMPILER_VAR_2;
m.init((struct mutex*)&m);
return m;
};
struct queueNode {
long int key;
void * data;
struct queueNode* next;
};
struct queue {
long int length;
struct queueNode* head;
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
struct queueNode* node =  ____BAH_COMPILER_VAR_3;
node->key =  this->length;
node->data =  data;
node->next =  this->head;
this->length =  this->length + 1;
this->head =  node;
};
void queue__delete(struct queue* this,long int key){
if ((this->length==0)) {
return;
}
struct queueNode* current =  this->head;
struct queueNode* previous= null;
while ((current->key!=key)) {
if ((current->next==null)) {
return;
}
previous =  current;
current =  current->next;
};
if ((current==this->head)) {
this->head =  current->next;
}
else {
previous->next =  current->next;
}
this->length =  this->length - 1;
};
void * queue__get(struct queue* this,long int key){
long int z =  0;
void * zp =  (void *)z;
if ((this->length==0)) {
return zp;
}
struct queueNode* ptr =  this->head;
while ((ptr->key!=key)) {
if ((ptr->next==null)) {
return zp;
}
ptr =  ptr->next;
};
void * data =  ptr->data;
return data;
};
void queue__set(struct queue* this,long int key,void * data){
this->delete((struct queue*)this,key);
struct queueNode* ____BAH_COMPILER_VAR_4 = memoryAlloc(sizeof(struct queueNode));
____BAH_COMPILER_VAR_4->data= null;
____BAH_COMPILER_VAR_4->next= null;
struct queueNode* node =  ____BAH_COMPILER_VAR_4;
node->key =  key;
node->data =  data;
node->next =  this->head;
this->length =  this->length + 1;
this->head =  node;
};
void * queue__pop(struct queue* this){
long int lastIndex =  this->length - 1;
void * data =  this->get((struct queue*)this,lastIndex);
this->delete((struct queue*)this,lastIndex);
return data;
};
void queue__clear(struct queue* this){
this->head =  (void *)0;
this->length =  0;
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
this->w_waitting =  this->w_waitting+1;
pthread_cond_wait(&this->w_cond,&this->m_mut);
this->w_waitting =  this->w_waitting-1;
};
}
this->queue->insert((struct queue*)this->queue,data);
if ((this->r_waitting>0)) {
pthread_cond_signal(&this->r_cond);
}
pthread_mutex_unlock(&this->m_mut);
};
void channel__sendAny(struct channel* this,void * data,long int len){
pthread_mutex_lock(&this->m_mut);
if ((this->cap!=-1)) {
while ((this->queue->length==this->cap)) {
this->w_waitting =  this->w_waitting+1;
pthread_cond_wait(&this->w_cond,&this->m_mut);
this->w_waitting =  this->w_waitting-1;
};
}
void * p =  memoryAlloc(len);
memcpy(p,data,len);
this->queue->insert((struct queue*)this->queue,p);
if ((this->r_waitting>0)) {
pthread_cond_signal(&this->r_cond);
}
pthread_mutex_unlock(&this->m_mut);
};
void * channel__receive(struct channel* this){
pthread_mutex_lock(&this->m_mut);
while ((this->queue->length==0)) {
this->r_waitting =  this->r_waitting+1;
pthread_cond_wait(&this->r_cond,&this->m_mut);
this->r_waitting =  this->r_waitting-1;
};
void * data =  this->queue->pop((struct queue*)this->queue);
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
long int l =  this->queue->length;
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
struct channel* c =  ____BAH_COMPILER_VAR_5;
pthread_mutex_init(&c->m_mut,0);
pthread_cond_init(&c->w_cond,0);
pthread_cond_init(&c->r_cond,0);
struct queue* ____BAH_COMPILER_VAR_6 = memoryAlloc(sizeof(struct queue));
____BAH_COMPILER_VAR_6->length = 0;
____BAH_COMPILER_VAR_6->head= null;
____BAH_COMPILER_VAR_6->insert = queue__insert;
____BAH_COMPILER_VAR_6->delete = queue__delete;
____BAH_COMPILER_VAR_6->get = queue__get;
____BAH_COMPILER_VAR_6->set = queue__set;
____BAH_COMPILER_VAR_6->pop = queue__pop;
____BAH_COMPILER_VAR_6->clear = queue__clear;
c->queue =  ____BAH_COMPILER_VAR_6;
return c;
};
//optimized out: setChanCap
struct channel * __BAH_panic_chan;
void __Bah_common_panic(char * e){
if (strlen(e)) {
print(e);
print("\n");
cleanShutDown();
}
};
#define panic __Bah_common_panic
void __BAH_panic(char * e,char * line){
if ((__BAH_panic_chan!=null)) {
__BAH_panic_chan->send(__BAH_panic_chan, e);
return;
}
char * ____BAH_COMPILER_VAR_7 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("panic (");
long int strLen_1 = strlen(line);
long int strLen_2 = strlen("): ");
long int strLen_3 = strlen(e);
long int strLen_4 = strlen("\n");
;                            
                    ____BAH_COMPILER_VAR_7 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_7+currStrOff, "panic (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_7+currStrOff, line, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_7+currStrOff, "): ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_7+currStrOff, e, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_7+currStrOff, "\n", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_7[currStrOff] = 0;
                }
                print(____BAH_COMPILER_VAR_7);
cleanShutDown();
};
//optimized out: recover
char * __Bah_safe_string(char * s){
if (((void *)s==null)) {
return "(nil)";
}
if ((strlen(s)>50)) {
s =  __STR(s);
array(char)* a =  strAsArr(s);

{
long nLength = 47;
if (a->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(a->data, (nLength+50)*sizeof(char));
a->data = newPtr;
}
a->data[47] =  46;
a->length = nLength+1;
} else {
a->data[47] =  46;
}
};

{
long nLength = 48;
if (a->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(a->data, (nLength+50)*sizeof(char));
a->data = newPtr;
}
a->data[48] =  46;
a->length = nLength+1;
} else {
a->data[48] =  46;
}
};

{
long nLength = 49;
if (a->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(a->data, (nLength+50)*sizeof(char));
a->data = newPtr;
}
a->data[49] =  46;
a->length = nLength+1;
} else {
a->data[49] =  46;
}
};

{
long nLength = 50;
if (a->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(a->data, (nLength+50)*sizeof(char));
a->data = newPtr;
}
a->data[50] =  (char)0;
a->length = nLength+1;
} else {
a->data[50] =  (char)0;
}
};
}
char * ____BAH_COMPILER_VAR_8 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\"");
long int strLen_1 = strlen(s);
long int strLen_2 = strlen("\"");
;                            
                    ____BAH_COMPILER_VAR_8 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_8+currStrOff, "\"", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_8+currStrOff, s, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_8+currStrOff, "\"", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_8[currStrOff] = 0;
                }
                return ____BAH_COMPILER_VAR_8;
};
char cpstringCharAt(char * s,long int i){
char c =  (char)0;
c=s[i];
return c;
};
char * cpstringSubsitute(char * s,long int i,long int l){
long int size =  l - i;
char * ns =  memoryAllocSTR(size + 1);
memcpy(ns,s+i,size);
return ns;
};
typedef array(void *)* __BAH_ARR_TYPE_ptr;
void * arraySubstitute(__BAH_ARR_TYPE_ptr arr,long int i,long int l){
long int length =  l - i;
long int offset =  i * arr->elemSize;
array(void *)* na = memoryAlloc(sizeof(array(void *)));

na->length = 0;
na->elemSize = sizeof(void *);
na->elemSize=arr->elemSize;
na->length=length;
long int allocLength =  length;
if ((length>50)) {
allocLength =  allocLength + allocLength % 50;
}
else {
allocLength =  50;
}
long int size =  allocLength * arr->elemSize;
long int realSize =  length * arr->elemSize;
void * data =  memoryAlloc(size);
char * oData =  arr->data;
memcpy(data,oData+offset,realSize);
na->data=data;
return na;
};
long int __Bah_map_hash(char * s,long int l){
long int hash =  5381;
long int i =  0;
for (; (i<strlen(s)); i =  i+1) {
hash =  ((long int)hash<<5 + 0) + hash + (long int)cpstringCharAt(s,i);
};
return hash % l;
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
long int l =  len(this->elems);
long int i =  l;
for (; (i<l + nb); i =  i+1) {

{
long nLength = i;
if (this->elems->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(this->elems->data, (nLength+50)*sizeof(struct mapElem*));
this->elems->data = newPtr;
}
this->elems->data[i] =  null;
this->elems->length = nLength+1;
} else {
this->elems->data[i] =  null;
}
};
};
};
void mapWrapper__set(struct mapWrapper* this,char * k,void * e){
if ((this->length * 2>=len(this->elems))) {
this->grow((struct mapWrapper*)this,this->length);
}
struct mapElem* ____BAH_COMPILER_VAR_9 = memoryAlloc(sizeof(struct mapElem));
____BAH_COMPILER_VAR_9->key= null;
____BAH_COMPILER_VAR_9->val= null;
____BAH_COMPILER_VAR_9->key = k;
____BAH_COMPILER_VAR_9->val = e;
struct mapElem* elem =  ____BAH_COMPILER_VAR_9;
long int ind =  __Bah_map_hash(k,len(this->elems));
long int i =  0;
for (; (i<len(this->elems)); i =  i+1) {
long int j =  (i + ind) % len(this->elems);

                    if (this->elems->length <= j) {
                        printf("array (/opt/bah/map.bah:37): this->elems[%d] with length %d\n", j, this->elems->length);
                        exit(1);
                    };
                    struct mapElem* ce =  this->elems->data[j];
if ((ce==null)) {

{
long nLength = j;
if (this->elems->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(this->elems->data, (nLength+50)*sizeof(struct mapElem*));
this->elems->data = newPtr;
}
this->elems->data[j] =  elem;
this->elems->length = nLength+1;
} else {
this->elems->data[j] =  elem;
}
};
this->length =  this->length+1;
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
this->elems->data[j] =  elem;
this->elems->length = nLength+1;
} else {
this->elems->data[j] =  elem;
}
};
break;
}
};
};
void mapWrapper__setAny(struct mapWrapper* this,char * k,void * e,long int s){
if ((this->length==0)) {
this->grow((struct mapWrapper*)this,50);
}
if ((this->length * 2>=len(this->elems))) {
this->grow((struct mapWrapper*)this,this->length);
}
void * p =  memoryAlloc(s);
memcpy(p,e,s);
struct mapElem* ____BAH_COMPILER_VAR_10 = memoryAlloc(sizeof(struct mapElem));
____BAH_COMPILER_VAR_10->key= null;
____BAH_COMPILER_VAR_10->val= null;
____BAH_COMPILER_VAR_10->key = k;
____BAH_COMPILER_VAR_10->val = p;
struct mapElem* elem =  ____BAH_COMPILER_VAR_10;
long int ind =  __Bah_map_hash(k,len(this->elems));
long int i =  0;
for (; (i<len(this->elems)); i =  i+1) {
long int j =  (i + ind) % len(this->elems);

                    if (this->elems->length <= j) {
                        printf("array (/opt/bah/map.bah:65): this->elems[%d] with length %d\n", j, this->elems->length);
                        exit(1);
                    };
                    struct mapElem* ce =  this->elems->data[j];
if ((ce==null)) {

{
long nLength = j;
if (this->elems->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(this->elems->data, (nLength+50)*sizeof(struct mapElem*));
this->elems->data = newPtr;
}
this->elems->data[j] =  elem;
this->elems->length = nLength+1;
} else {
this->elems->data[j] =  elem;
}
};
this->length =  this->length+1;
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
this->elems->data[j] =  elem;
this->elems->length = nLength+1;
} else {
this->elems->data[j] =  elem;
}
};
break;
}
};
};
void mapWrapper__delete(struct mapWrapper* this,char * k){
long int ind =  __Bah_map_hash(k,len(this->elems));
long int i =  0;
for (; (i<len(this->elems)); i =  i+1) {
long int j =  (i + ind) % len(this->elems);

                    if (this->elems->length <= j) {
                        printf("array (/opt/bah/map.bah:81): this->elems[%d] with length %d\n", j, this->elems->length);
                        exit(1);
                    };
                    struct mapElem* e =  this->elems->data[j];
if (((e!=null)&&(strcmp(e->key, k) == 0))) {

{
long nLength = j;
if (this->elems->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(this->elems->data, (nLength+50)*sizeof(struct mapElem*));
this->elems->data = newPtr;
}
this->elems->data[j] =  null;
this->elems->length = nLength+1;
} else {
this->elems->data[j] =  null;
}
};
}
};
};
void * mapWrapper__get(struct mapWrapper* this,char * k){
long int ind =  __Bah_map_hash(k,len(this->elems));
long int i =  0;
for (; (i<len(this->elems)); i =  i+1) {
long int j =  (i + ind) % len(this->elems);

                    if (this->elems->length <= j) {
                        printf("array (/opt/bah/map.bah:92): this->elems[%d] with length %d\n", j, this->elems->length);
                        exit(1);
                    };
                    struct mapElem* e =  this->elems->data[j];
if (((e!=null)&&(strcmp(e->key, k) == 0))) {
return e->val;
}
};
return null;
};
struct mapWrapper* mapWrapper(){
struct mapWrapper* ____BAH_COMPILER_VAR_11 = memoryAlloc(sizeof(struct mapWrapper));
____BAH_COMPILER_VAR_11->elems = memoryAlloc(sizeof(array(struct mapElem*)));
            ____BAH_COMPILER_VAR_11->elems->length = 0;
            ____BAH_COMPILER_VAR_11->elems->elemSize = sizeof(struct mapElem*);
            ____BAH_COMPILER_VAR_11->grow = mapWrapper__grow;
____BAH_COMPILER_VAR_11->set = mapWrapper__set;
____BAH_COMPILER_VAR_11->setAny = mapWrapper__setAny;
____BAH_COMPILER_VAR_11->delete = mapWrapper__delete;
____BAH_COMPILER_VAR_11->get = mapWrapper__get;
struct mapWrapper* m =  ____BAH_COMPILER_VAR_11;
m->grow((struct mapWrapper*)m,50);
return m;
};
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
//optimized out: stdinput
void println(char * s){
char * ____BAH_COMPILER_VAR_14 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s);
long int strLen_1 = strlen("\n");
;                            
                    ____BAH_COMPILER_VAR_14 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_14+currStrOff, s, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_14+currStrOff, "\n", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_14[currStrOff] = 0;
                }
                write((void *)1,____BAH_COMPILER_VAR_14,strlen(s) + 1);
};
struct fileStream {
FILE* handle;
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
};
long int fileStream__isValid(struct fileStream* this){
if ((this->handle==null)) {
return 0;
}
return 1;
};
void fileStream__open(struct fileStream* this,char * path,char * mode){
this->handle =  fopen(path,mode);
};
void fileStream__close(struct fileStream* this){
if ((this->isValid((struct fileStream*)this)==0)) {
return;
}
fclose(this->handle);
};
long int fileStream__getPos(struct fileStream* this){
if ((this->isValid((struct fileStream*)this)==0)) {
return 0;
}
return ftell(this->handle);
};
void fileStream__setPos(struct fileStream* this,long int i){
if ((this->isValid((struct fileStream*)this)==0)) {
return;
}
fseek(this->handle,i,0);
};
long int fileStream__getSize(struct fileStream* this){
if ((this->isValid((struct fileStream*)this)==0)) {
return -1;
}
long int oldPos =  this->getPos((struct fileStream*)this);
fseek(this->handle,0,2);
long int size =  ftell(this->handle);
this->setPos((struct fileStream*)this,oldPos);
return size;
};
void fileStream__rewind(struct fileStream* this){
rewind(this->handle);
};
char fileStream__getChar(struct fileStream* this){
char c =  getc(this->handle);
return c;
};
void fileStream__setChar(struct fileStream* this,char c){
fputc(c,this->handle);
};
void fileStream__createFile(struct fileStream* this,char * path){
this->open((struct fileStream*)this,path,"w");
this->close((struct fileStream*)this);
};
long int fileStream__writeFile(struct fileStream* this,char * content){
if ((this->isValid((struct fileStream*)this)==0)) {
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
if ((this->isValid((struct fileStream*)this)==0)) {
return "invalid";
}
long int sz =  this->getSize((struct fileStream*)this);
char * r =  memoryAllocSTR(sz + 1);
long int l =  fread(r,1,sz,this->handle);
if ((sz!=l)) {
array(char)* rarr =  strAsArr(r);

{
long nLength = l;
if (rarr->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(rarr->data, (nLength+50)*sizeof(char));
rarr->data = newPtr;
}
rarr->data[l] =  (char)0;
rarr->length = nLength+1;
} else {
rarr->data[l] =  (char)0;
}
};
}
return r;
};
__BAH_ARR_TYPE_char fileStream__readBytes(struct fileStream* this){
array(char)* r = memoryAlloc(sizeof(array(char)));

r->length = 0;
r->elemSize = sizeof(char);
allocateArray(r,this->getSize((struct fileStream*)this));
this->readPtr((struct fileStream*)this,r->data,len(r));
return r;
};
void fileStream__writeBytes(struct fileStream* this,__BAH_ARR_TYPE_char d){
this->writePtr((struct fileStream*)this,d->data,len(d));
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
struct fileStream ____BAH_COMPILER_VAR_15 = {};
____BAH_COMPILER_VAR_15.handle= null;
____BAH_COMPILER_VAR_15.isValid = fileStream__isValid;
____BAH_COMPILER_VAR_15.open = fileStream__open;
____BAH_COMPILER_VAR_15.close = fileStream__close;
____BAH_COMPILER_VAR_15.getPos = fileStream__getPos;
____BAH_COMPILER_VAR_15.setPos = fileStream__setPos;
____BAH_COMPILER_VAR_15.getSize = fileStream__getSize;
____BAH_COMPILER_VAR_15.rewind = fileStream__rewind;
____BAH_COMPILER_VAR_15.getChar = fileStream__getChar;
____BAH_COMPILER_VAR_15.setChar = fileStream__setChar;
____BAH_COMPILER_VAR_15.createFile = fileStream__createFile;
____BAH_COMPILER_VAR_15.writeFile = fileStream__writeFile;
____BAH_COMPILER_VAR_15.writePtr = fileStream__writePtr;
____BAH_COMPILER_VAR_15.readPtr = fileStream__readPtr;
____BAH_COMPILER_VAR_15.readContent = fileStream__readContent;
____BAH_COMPILER_VAR_15.readBytes = fileStream__readBytes;
____BAH_COMPILER_VAR_15.writeBytes = fileStream__writeBytes;
struct fileStream fs =  ____BAH_COMPILER_VAR_15;
fs.open((struct fileStream*)&fs,fileName,"r+");
long int iv =  fs.isValid((struct fileStream*)&fs);
if ((iv==1)) {
this->handle =  0;
}
else {
this->handle =  -1;
}
char * file =  fs.readContent((struct fileStream*)&fs);
fs.close((struct fileStream*)&fs);
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
//optimized out: listFiles
long int fileExists(char * path){
long int is =  access(path,0);
if ((is==0)) {
return 1;
}
return 0;
};
//optimized out: removeFile
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
char * s =  memoryAlloc(2);
strncpy(s,(char *)&c,1);
return s;
};
long int isUpper(char c){
if ((c>(char)64)) {
if ((c<(char)91)) {
return 1;
}
}
return 0;
};
long int isLower(char c){
if ((c>(char)96)) {
if ((c<(char)123)) {
return 1;
}
}
return 0;
};
long int isLetter(char s){
if (isUpper(s)) {
return 1;
}
if (isLower(s)) {
return 1;
}
return 0;
};
long int isNumber(char c){
if ((c>(char)47)) {
if ((c<(char)58)) {
return 1;
}
}
return 0;
};
long int isAlphaNumeric(char s){
if (isLetter(s)) {
return 1;
}
if (isNumber(s)) {
return 1;
}
return 0;
};
long int isSpace(char c){
if ((c==(char)32)) {
return 1;
}
if ((c==(char)9)) {
return 1;
}
if ((c==(char)10)) {
return 1;
}
if ((c==(char)11)) {
return 1;
}
if ((c==(char)13)) {
return 1;
}
return 0;
};
char * arrAsStr(__BAH_ARR_TYPE_char arr);
void println(char * s);
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
this->length =  strlen(s);
this->editable =  false;
this->content =  s;
};
void string__makeEditable(struct string* this){
this->editable =  true;
char * old =  this->content;
this->content =  (char *)memoryAlloc(this->length + 1);
strncpy(this->content,old,this->length);
};
void string__append(struct string* this,char * s){
if ((this->editable==false)) {
this->makeEditable((struct string*)this);
}
long int sl =  strlen(s);
long int nl =  sl + this->length;
void * nc =  memoryRealloc(this->content,nl + 1);
if ((nc==null)) {
__BAH_panic("Error appending to string, possibly due to memory shortage.","/opt/bah/string.bah:139");
}
this->content =  nc;
strCatOffset(this->content,this->length,s,sl);
this->length =  nl;
};
void string__prepend(struct string* this,char * s){
this->editable =  true;
long int sl =  strlen(s);
long int nl =  this->length + sl;
char * tmpS =  this->content;
void * nc =  memoryAlloc(nl + 1);
if ((nc==null)) {
__BAH_panic("Error appending to string, possibly due to memory shortage.","/opt/bah/string.bah:154");
}
this->content =  nc;
strncpy(this->content,s,sl);
strCatOffset(this->content,sl,tmpS,this->length);
destroy(tmpS);
this->length =  nl;
};
char string__charAt(struct string* this,long int i){
if (((void *)this->content==null)) {
return null;
}
if (((i<this->length)&&(i>=0))) {
return cpstringCharAt(this->content,i);
}
return null;
};
long int string__compare(struct string* this,char * s){
long int r =  strcmp(this->content,s);
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
this->makeEditable((struct string*)this);
}
struct string ____BAH_COMPILER_VAR_16 = {};
____BAH_COMPILER_VAR_16.content= null;
____BAH_COMPILER_VAR_16.set = string__set;
____BAH_COMPILER_VAR_16.makeEditable = string__makeEditable;
____BAH_COMPILER_VAR_16.append = string__append;
____BAH_COMPILER_VAR_16.prepend = string__prepend;
____BAH_COMPILER_VAR_16.charAt = string__charAt;
____BAH_COMPILER_VAR_16.compare = string__compare;
____BAH_COMPILER_VAR_16.str = string__str;
____BAH_COMPILER_VAR_16.replace = string__replace;
struct string needle =  ____BAH_COMPILER_VAR_16;
needle.set((struct string*)&needle,nd);
struct string ____BAH_COMPILER_VAR_17 = {};
____BAH_COMPILER_VAR_17.content= null;
____BAH_COMPILER_VAR_17.set = string__set;
____BAH_COMPILER_VAR_17.makeEditable = string__makeEditable;
____BAH_COMPILER_VAR_17.append = string__append;
____BAH_COMPILER_VAR_17.prepend = string__prepend;
____BAH_COMPILER_VAR_17.charAt = string__charAt;
____BAH_COMPILER_VAR_17.compare = string__compare;
____BAH_COMPILER_VAR_17.str = string__str;
____BAH_COMPILER_VAR_17.replace = string__replace;
struct string repl =  ____BAH_COMPILER_VAR_17;
repl.set((struct string*)&repl,rl);
long int i =  0;
long int si =  0;
long int replcBuffSart =  0;
long int replcBuffLength =  0;
array(char)* buff = memoryAlloc(sizeof(array(char)));

buff->length = 0;
buff->elemSize = sizeof(char);
while ((i<this->length)) {
char c =  this->charAt((struct string*)this,i);
char rc =  needle.charAt((struct string*)&needle,si);
if ((c==rc)) {
si =  si + 1;
if ((replcBuffLength==0)) {
replcBuffSart =  i;
}
replcBuffLength =  replcBuffLength + 1;
}
else {
if ((replcBuffLength>0)) {
si =  0;
long int j =  0;
while ((j<replcBuffLength)) {

{
long nLength = len(buff);
if (buff->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(buff->data, (nLength+50)*sizeof(char));
buff->data = newPtr;
}
buff->data[len(buff)] =  this->charAt((struct string*)this,j + replcBuffSart);
buff->length = nLength+1;
} else {
buff->data[len(buff)] =  this->charAt((struct string*)this,j + replcBuffSart);
}
};
j =  j + 1;
};
replcBuffLength =  0;
}

{
long nLength = len(buff);
if (buff->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(buff->data, (nLength+50)*sizeof(char));
buff->data = newPtr;
}
buff->data[len(buff)] =  c;
buff->length = nLength+1;
} else {
buff->data[len(buff)] =  c;
}
};
}
if ((si==needle.length)) {
replcBuffLength =  0;
long int ii =  0;
while ((ii<repl.length)) {
long int a =  ii;

{
long nLength = len(buff);
if (buff->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(buff->data, (nLength+50)*sizeof(char));
buff->data = newPtr;
}
buff->data[len(buff)] =  repl.charAt((struct string*)&repl,ii);
buff->length = nLength+1;
} else {
buff->data[len(buff)] =  repl.charAt((struct string*)&repl,ii);
}
};
ii =  ii + 1;
};
si =  0;
}
i =  i + 1;
};
char * r =  arrAsStr(buff);
if ((replcBuffLength>0)) {
array(char)* replbuffStr = memoryAlloc(sizeof(array(char)));

replbuffStr->length = 0;
replbuffStr->elemSize = sizeof(char);
allocateArray(replbuffStr,replcBuffLength + 1);
long int j =  0;
while ((j<replcBuffLength)) {

{
long nLength = j;
if (replbuffStr->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(replbuffStr->data, (nLength+50)*sizeof(char));
replbuffStr->data = newPtr;
}
replbuffStr->data[j] =  this->charAt((struct string*)this,j + replcBuffSart);
replbuffStr->length = nLength+1;
} else {
replbuffStr->data[j] =  this->charAt((struct string*)this,j + replcBuffSart);
}
};
j =  j + 1;
};
char * ____BAH_COMPILER_VAR_18 =arrAsStr(replbuffStr);char * ____BAH_COMPILER_VAR_19 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(r);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_18);
;                            
                    ____BAH_COMPILER_VAR_19 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_19+currStrOff, r, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_19+currStrOff, ____BAH_COMPILER_VAR_18, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_19[currStrOff] = 0;
                }
                r =  ____BAH_COMPILER_VAR_19;
}
if (((void *)r!=null)) {
this->set((struct string*)this,r);
}
};
long int string__countChar(struct string* this,char need){
long int c =  0;
long int i =  0;
for (; (i<this->length); i =  i+1) {
if ((this->charAt((struct string*)this,i)==need)) {
c =  c+1;
}
};
return c;
};
long int string__count(struct string* this,char * need){
if ((strlen(need)==1)) {
return this->countChar((struct string*)this,cpstringCharAt(need,0));
}
long int i =  0;
long int count =  0;
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
____BAH_COMPILER_VAR_20.countChar = string__countChar;
____BAH_COMPILER_VAR_20.count = string__count;
struct string needle =  ____BAH_COMPILER_VAR_20;
needle.set((struct string*)&needle,need);
long int countIndex =  0;
while ((i<this->length)) {
char c =  this->charAt((struct string*)this,i);
char sc =  needle.charAt((struct string*)&needle,countIndex);
if ((c==sc)) {
countIndex =  countIndex + 1;
}
else {
countIndex =  0;
}
if ((countIndex==needle.length)) {
count =  count + 1;
countIndex =  0;
}
i =  i + 1;
};
return count;
};
long int string__hasPrefix(struct string* this,char * need){
long int i =  0;
long int nl =  strlen(need);
if ((this->length<nl)) {
return 0;
}
while ((i<nl)) {
char c =  this->charAt((struct string*)this,i);
char sc =  cpstringCharAt(need,i);
if ((c!=sc)) {
return 0;
}
i =  i + 1;
};
return 1;
};
long int string__hasSuffix(struct string* this,char * need){
long int nl =  strlen(need);
if ((this->length<nl)) {
return 0;
}
long int i =  this->length - nl;
long int needleIndex =  0;
while ((i<this->length)) {
char c =  this->charAt((struct string*)this,i);
char sc =  cpstringCharAt(need,needleIndex);
if ((c!=sc)) {
return 0;
}
needleIndex =  needleIndex + 1;
i =  i + 1;
};
return 1;
};
void string__trim(struct string* this){
if ((this->length==0)) {
return;
}
char fc =  this->charAt((struct string*)this,0);
if ((isSpace(fc)==0)) {
return;
}
if ((this->editable==false)) {
this->makeEditable((struct string*)this);
}
long int i =  0;
for (; (i<this->length); i =  i+1) {
if ((isSpace(this->charAt((struct string*)this,i))==0)) {
break;
}
};
if ((i>0)) {
this->length =  this->length - i;
char * tmpS =  memoryAlloc(this->length + 1);
memcpy(tmpS,this->content+i,this->length + 1);
this->content =  tmpS;
}
};
void string__trimLeft(struct string* this,long int s){
if ((this->editable==false)) {
this->makeEditable((struct string*)this);
}
long int nSize =  this->length - s;
void * tmpS =  memoryAlloc(nSize);
memcpy(tmpS,this->content+s,nSize);
this->content =  tmpS;
this->length =  nSize;
};
void string__trimRight(struct string* this,long int s){
if ((this->editable==false)) {
this->makeEditable((struct string*)this);
}
long int nSize =  this->length - s;
void * tmpS =  memoryAlloc(nSize);
memcpy(tmpS,this->content,nSize);
this->content =  tmpS;
this->length =  nSize;
};
struct string string__add(struct string* this,struct string s2){
struct string ____BAH_COMPILER_VAR_21 = {};
____BAH_COMPILER_VAR_21.content= null;
____BAH_COMPILER_VAR_21.set = string__set;
____BAH_COMPILER_VAR_21.makeEditable = string__makeEditable;
____BAH_COMPILER_VAR_21.append = string__append;
____BAH_COMPILER_VAR_21.prepend = string__prepend;
____BAH_COMPILER_VAR_21.charAt = string__charAt;
____BAH_COMPILER_VAR_21.compare = string__compare;
____BAH_COMPILER_VAR_21.str = string__str;
____BAH_COMPILER_VAR_21.replace = string__replace;
____BAH_COMPILER_VAR_21.countChar = string__countChar;
____BAH_COMPILER_VAR_21.count = string__count;
____BAH_COMPILER_VAR_21.hasPrefix = string__hasPrefix;
____BAH_COMPILER_VAR_21.hasSuffix = string__hasSuffix;
____BAH_COMPILER_VAR_21.trim = string__trim;
____BAH_COMPILER_VAR_21.trimLeft = string__trimLeft;
____BAH_COMPILER_VAR_21.trimRight = string__trimRight;
____BAH_COMPILER_VAR_21.add = string__add;
struct string r =  ____BAH_COMPILER_VAR_21;
r.length =  this->length + s2.length;
r.content =  memoryAlloc(r.length + 1);
strncpy(r.content,this->content,this->length);
strCatOffset(r.content,this->length,s2.content,s2.length);
return r;
};
struct string string(char * s){
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
____BAH_COMPILER_VAR_22.hasPrefix = string__hasPrefix;
____BAH_COMPILER_VAR_22.hasSuffix = string__hasSuffix;
____BAH_COMPILER_VAR_22.trim = string__trim;
____BAH_COMPILER_VAR_22.trimLeft = string__trimLeft;
____BAH_COMPILER_VAR_22.trimRight = string__trimRight;
____BAH_COMPILER_VAR_22.add = string__add;
struct string a =  ____BAH_COMPILER_VAR_22;
a.set((struct string*)&a,s);
return a;
};
char * intToStr(long int i){
if ((i==0)) {
return "0";
}
char ____BAH_COMPILER_VAR_23[66];char* s = ____BAH_COMPILER_VAR_23;
long int ind =  -1;
char subZero =  (i<0);
if ((subZero==true)) {
i =  0 - i;
}
for (; (i!=0); i =  i / 10) {
long int conv =  i % 10;
conv =  conv + 48;

                    if (ind + 1 >= 66) {
                        printf("buffer (/opt/bah/string.bah:418): s[%d] with length %d\n", ind + 1, 66);
                        exit(1);
                    };
                    s[ind + 1] =  (char)conv;
ind =  ind+1;
};
if ((subZero==true)) {

                    if (ind + 1 >= 66) {
                        printf("buffer (/opt/bah/string.bah:423): s[%d] with length %d\n", ind + 1, 66);
                        exit(1);
                    };
                    s[ind + 1] =  45;
ind =  ind+1;
}
long int ls =  ind + 1;
i =  0;
for (; (i<ls / 2); i =  i+1) {
long int ii =  ls - i-1;

                    if (i >= 66) {
                        printf("buffer (/opt/bah/string.bah:429): s[%d] with length %d\n", i, 66);
                        exit(1);
                    };
                    char osi =  s[i];

                    if (i >= 66) {
                        printf("buffer (/opt/bah/string.bah:430): s[%d] with length %d\n", i, 66);
                        exit(1);
                    };
                    
                    if (ii >= 66) {
                        printf("buffer (/opt/bah/string.bah:430): s[%d] with length %d\n", ii, 66);
                        exit(1);
                    };
                    s[i] =  s[ii];

                    if (ii >= 66) {
                        printf("buffer (/opt/bah/string.bah:431): s[%d] with length %d\n", ii, 66);
                        exit(1);
                    };
                    s[ii] =  osi;
};

                    if (ind + 1 >= 66) {
                        printf("buffer (/opt/bah/string.bah:434): s[%d] with length %d\n", ind + 1, 66);
                        exit(1);
                    };
                    s[ind + 1] =  (char)0;
return __STR(s);
};
//optimized out: intToString
char * floatToStr(double f){
char * buff =  memoryAlloc(50);
sprintf(buff,"%lf",f);
return buff;
};
long int strToInt(char * s){
return atol(s);
};
double strToFloat(char * s){
return strtod(s,null);
};
//optimized out: stringToInt
typedef array(struct string)* __BAH_ARR_TYPE_string;
__BAH_ARR_TYPE_string splitString(struct string s,char * sp){
struct string sep =  string(sp);
array(struct string)* res = memoryAlloc(sizeof(array(struct string)));

res->length = 0;
res->elemSize = sizeof(struct string);
struct string sepBuffer =  string("");
long int sepIndex =  0;
long int i =  0;
struct string replcBuff =  string("");
array(char)* tmpString = memoryAlloc(sizeof(array(char)));

tmpString->length = 0;
tmpString->elemSize = sizeof(char);
while ((i<s.length)) {
char c =  s.charAt((struct string*)&s,i);
char sepc =  sep.charAt((struct string*)&sep,sepIndex);
if ((c==sepc)) {
sepIndex =  sepIndex + 1;
char * ____BAH_COMPILER_VAR_25 =charToString(c);replcBuff.append((struct string*)&replcBuff,____BAH_COMPILER_VAR_25);
}
else {
if ((sepIndex>0)) {
sepIndex =  0;
char * ____BAH_COMPILER_VAR_26 =charToString(c);replcBuff.append((struct string*)&replcBuff,____BAH_COMPILER_VAR_26);
long int ii =  0;
while ((ii<replcBuff.length)) {

{
long nLength = len(tmpString);
if (tmpString->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tmpString->data, (nLength+50)*sizeof(char));
tmpString->data = newPtr;
}
tmpString->data[len(tmpString)] =  replcBuff.charAt((struct string*)&replcBuff,ii);
tmpString->length = nLength+1;
} else {
tmpString->data[len(tmpString)] =  replcBuff.charAt((struct string*)&replcBuff,ii);
}
};
ii =  ii + 1;
};
replcBuff.set((struct string*)&replcBuff,"");
}
else {

{
long nLength = len(tmpString);
if (tmpString->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tmpString->data, (nLength+50)*sizeof(char));
tmpString->data = newPtr;
}
tmpString->data[len(tmpString)] =  c;
tmpString->length = nLength+1;
} else {
tmpString->data[len(tmpString)] =  c;
}
};
}
}
if ((sepIndex==sep.length)) {
replcBuff.set((struct string*)&replcBuff,"");
struct string* ____BAH_COMPILER_VAR_27 = memoryAlloc(sizeof(struct string));
____BAH_COMPILER_VAR_27->content= null;
____BAH_COMPILER_VAR_27->set = string__set;
____BAH_COMPILER_VAR_27->makeEditable = string__makeEditable;
____BAH_COMPILER_VAR_27->append = string__append;
____BAH_COMPILER_VAR_27->prepend = string__prepend;
____BAH_COMPILER_VAR_27->charAt = string__charAt;
____BAH_COMPILER_VAR_27->compare = string__compare;
____BAH_COMPILER_VAR_27->str = string__str;
____BAH_COMPILER_VAR_27->replace = string__replace;
____BAH_COMPILER_VAR_27->countChar = string__countChar;
____BAH_COMPILER_VAR_27->count = string__count;
____BAH_COMPILER_VAR_27->hasPrefix = string__hasPrefix;
____BAH_COMPILER_VAR_27->hasSuffix = string__hasSuffix;
____BAH_COMPILER_VAR_27->trim = string__trim;
____BAH_COMPILER_VAR_27->trimLeft = string__trimLeft;
____BAH_COMPILER_VAR_27->trimRight = string__trimRight;
____BAH_COMPILER_VAR_27->add = string__add;
struct string* elem =  ____BAH_COMPILER_VAR_27;
char * ____BAH_COMPILER_VAR_28 =arrToStr(tmpString);elem->set((struct string*)elem,____BAH_COMPILER_VAR_28);
long int lenRes =  len(res);

{
long nLength = lenRes;
if (res->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(res->data, (nLength+50)*sizeof(struct string));
res->data = newPtr;
}
res->data[lenRes] =  *elem;
res->length = nLength+1;
} else {
res->data[lenRes] =  *elem;
}
};
clear(tmpString);
sepIndex =  0;
}
i =  i + 1;
};
if ((replcBuff.length>0)) {
long int ii =  0;
while ((ii<replcBuff.length)) {

{
long nLength = len(tmpString);
if (tmpString->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tmpString->data, (nLength+50)*sizeof(char));
tmpString->data = newPtr;
}
tmpString->data[len(tmpString)] =  replcBuff.charAt((struct string*)&replcBuff,ii);
tmpString->length = nLength+1;
} else {
tmpString->data[len(tmpString)] =  replcBuff.charAt((struct string*)&replcBuff,ii);
}
};
ii =  ii + 1;
};
}
if ((len(tmpString)>0)) {
struct string* ____BAH_COMPILER_VAR_29 = memoryAlloc(sizeof(struct string));
____BAH_COMPILER_VAR_29->content= null;
____BAH_COMPILER_VAR_29->set = string__set;
____BAH_COMPILER_VAR_29->makeEditable = string__makeEditable;
____BAH_COMPILER_VAR_29->append = string__append;
____BAH_COMPILER_VAR_29->prepend = string__prepend;
____BAH_COMPILER_VAR_29->charAt = string__charAt;
____BAH_COMPILER_VAR_29->compare = string__compare;
____BAH_COMPILER_VAR_29->str = string__str;
____BAH_COMPILER_VAR_29->replace = string__replace;
____BAH_COMPILER_VAR_29->countChar = string__countChar;
____BAH_COMPILER_VAR_29->count = string__count;
____BAH_COMPILER_VAR_29->hasPrefix = string__hasPrefix;
____BAH_COMPILER_VAR_29->hasSuffix = string__hasSuffix;
____BAH_COMPILER_VAR_29->trim = string__trim;
____BAH_COMPILER_VAR_29->trimLeft = string__trimLeft;
____BAH_COMPILER_VAR_29->trimRight = string__trimRight;
____BAH_COMPILER_VAR_29->add = string__add;
struct string* elem =  ____BAH_COMPILER_VAR_29;
char * ____BAH_COMPILER_VAR_30 =arrToStr(tmpString);elem->set((struct string*)elem,____BAH_COMPILER_VAR_30);
long int lenRes =  len(res);

{
long nLength = lenRes;
if (res->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(res->data, (nLength+50)*sizeof(struct string));
res->data = newPtr;
}
res->data[lenRes] =  *elem;
res->length = nLength+1;
} else {
res->data[lenRes] =  *elem;
}
};
}
return res;
};
//optimized out: joinString
char * splitStringBefore(struct string s,char * sp){
struct string sep =  string(sp);
if ((sep.length>=s.length)) {
return "";
}
long int sepIndex =  0;
long int foundIndex =  0;
long int i =  0;
while ((i<s.length)) {
char c =  s.charAt((struct string*)&s,i);
char sc =  sep.charAt((struct string*)&sep,sepIndex);
if ((c==sc)) {
if ((sepIndex==0)) {
foundIndex =  i - 1;
}
sepIndex =  sepIndex + 1;
if ((sepIndex==sep.length)) {
long int max =  s.length - foundIndex - 1;
s.trimRight((struct string*)&s,max);
return s.str((struct string*)&s);
}
}
else {
foundIndex =  0;
sepIndex =  0;
}
i =  i + 1;
};
return "";
};
//optimized out: toLower
char strHasPrefix(char * s,char * need){
long int i =  0;
long int nl =  strlen(need);
long int sl =  strlen(s);
if ((sl<nl)) {
return false;
}
while ((i<nl)) {
if ((cpstringCharAt(s,i)!=cpstringCharAt(need,i))) {
return false;
}
i =  i + 1;
};
return true;
};
char strHasSuffix(char * s,char * need){
long int sl =  strlen(s);
long int nl =  strlen(need);
if ((nl>sl)) {
return false;
}
long int i =  sl - nl;
while ((i<sl)) {
if ((cpstringCharAt(s,i)!=cpstringCharAt(need,i))) {
return false;
}
i =  i + 1;
};
return true;
};
void strTrim(char ** s){
long int l =  strlen(*s);
long int i =  0;
while ((i<l)) {
char c =  cpstringCharAt(*s,i);
if ((isSpace(c)==0)) {
break;
}
i =  i + 1;
};
*s =  *s+i;
};
long int strCount(char * src,char * needle){
long int i =  0;
long int count =  0;
long int countIndex =  0;
long int sl =  strlen(src);
long int nl =  strlen(needle);
while ((i<sl)) {
char c =  cpstringCharAt(src,i);
char sc =  cpstringCharAt(needle,countIndex);
if ((c==sc)) {
countIndex =  countIndex + 1;
}
else {
countIndex =  0;
}
if ((countIndex==nl)) {
count =  count + 1;
countIndex =  0;
}
i =  i + 1;
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
struct flag* ____BAH_COMPILER_VAR_34 = memoryAlloc(sizeof(struct flag));
____BAH_COMPILER_VAR_34->name= null;
____BAH_COMPILER_VAR_34->help= null;
____BAH_COMPILER_VAR_34->content= null;
struct flag* f =  ____BAH_COMPILER_VAR_34;
f->name =  name;
f->help =  help;
f->type =  FLAG_TYPE_CPSTRING;
long int lf =  len(this->flags);

{
long nLength = lf;
if (this->flags->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(this->flags->data, (nLength+50)*sizeof(struct flag*));
this->flags->data = newPtr;
}
this->flags->data[lf] =  f;
this->flags->length = nLength+1;
} else {
this->flags->data[lf] =  f;
}
};
};
void flags__addBool(struct flags* this,char * name,char * help){
struct flag* ____BAH_COMPILER_VAR_35 = memoryAlloc(sizeof(struct flag));
____BAH_COMPILER_VAR_35->name= null;
____BAH_COMPILER_VAR_35->help= null;
____BAH_COMPILER_VAR_35->content= null;
struct flag* f =  ____BAH_COMPILER_VAR_35;
f->name =  name;
f->help =  help;
f->type =  FLAG_TYPE_BOOL;
long int lf =  len(this->flags);

{
long nLength = lf;
if (this->flags->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(this->flags->data, (nLength+50)*sizeof(struct flag*));
this->flags->data = newPtr;
}
this->flags->data[lf] =  f;
this->flags->length = nLength+1;
} else {
this->flags->data[lf] =  f;
}
};
};
void flags__addInt(struct flags* this,char * name,char * help){
struct flag* ____BAH_COMPILER_VAR_36 = memoryAlloc(sizeof(struct flag));
____BAH_COMPILER_VAR_36->name= null;
____BAH_COMPILER_VAR_36->help= null;
____BAH_COMPILER_VAR_36->content= null;
struct flag* f =  ____BAH_COMPILER_VAR_36;
f->name =  name;
f->help =  help;
f->type =  FLAG_TYPE_INT;
long int lf =  len(this->flags);

{
long nLength = lf;
if (this->flags->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(this->flags->data, (nLength+50)*sizeof(struct flag*));
this->flags->data = newPtr;
}
this->flags->data[lf] =  f;
this->flags->length = nLength+1;
} else {
this->flags->data[lf] =  f;
}
};
};
void flags__addFloat(struct flags* this,char * name,char * help){
struct flag* ____BAH_COMPILER_VAR_37 = memoryAlloc(sizeof(struct flag));
____BAH_COMPILER_VAR_37->name= null;
____BAH_COMPILER_VAR_37->help= null;
____BAH_COMPILER_VAR_37->content= null;
struct flag* f =  ____BAH_COMPILER_VAR_37;
f->name =  name;
f->help =  help;
f->type =  FLAG_TYPE_FLOAT;
long int lf =  len(this->flags);

{
long nLength = lf;
if (this->flags->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(this->flags->data, (nLength+50)*sizeof(struct flag*));
this->flags->data = newPtr;
}
this->flags->data[lf] =  f;
this->flags->length = nLength+1;
} else {
this->flags->data[lf] =  f;
}
};
};
void flags__invalidate(struct flags* this){
print("Usage of ");
print(this->args->data[0]);
println(":");
long int i =  0;
while ((i<len(this->flags))) {

                    if (this->flags->length <= i) {
                        printf("array (/opt/bah/flags.bah:75): this->flags[%d] with length %d\n", i, this->flags->length);
                        exit(1);
                    };
                    struct flag* flag =  this->flags->data[i];
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
i =  i + 1;
};
exit(1);
};
struct flag* flags__getFlag(struct flags* this,struct string name){
long int i =  0;
while ((i<len(this->flags))) {

                    if (this->flags->length <= i) {
                        printf("array (/opt/bah/flags.bah:98): this->flags[%d] with length %d\n", i, this->flags->length);
                        exit(1);
                    };
                    struct flag* flag =  this->flags->data[i];
if (name.compare((struct string*)&name,flag->name)) {
return flag;
}
i =  i + 1;
};
struct flag* ____BAH_COMPILER_VAR_38 = memoryAlloc(sizeof(struct flag));
____BAH_COMPILER_VAR_38->name= null;
____BAH_COMPILER_VAR_38->help= null;
____BAH_COMPILER_VAR_38->content= null;
struct flag* z =  ____BAH_COMPILER_VAR_38;
z->isSet =  0;
return z;
};
char * flags__get(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_39 =string(name);struct flag* flag =  this->getFlag((struct flags*)this,____BAH_COMPILER_VAR_39);
char * ctn =  flag->content;
return ctn;
};
long int flags__getInt(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_40 =string(name);struct flag* flag =  this->getFlag((struct flags*)this,____BAH_COMPILER_VAR_40);
if ((flag->type!=FLAG_TYPE_INT)) {
char * ____BAH_COMPILER_VAR_41 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Flag '");
long int strLen_1 = strlen(flag->name);
long int strLen_2 = strlen("' is not int.");
;                            
                    ____BAH_COMPILER_VAR_41 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_41+currStrOff, "Flag '", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_41+currStrOff, flag->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_41+currStrOff, "' is not int.", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_41[currStrOff] = 0;
                }
                char * error =  ____BAH_COMPILER_VAR_41;
__BAH_panic(error,"/opt/bah/flags.bah:124");
}
long int ctn =  flag->cont_int;
return ctn;
};
double flags__getFloat(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_42 =string(name);struct flag* flag =  this->getFlag((struct flags*)this,____BAH_COMPILER_VAR_42);
if ((flag->type!=FLAG_TYPE_FLOAT)) {
char * ____BAH_COMPILER_VAR_43 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Flag '");
long int strLen_1 = strlen(flag->name);
long int strLen_2 = strlen("' is not float.");
;                            
                    ____BAH_COMPILER_VAR_43 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_43+currStrOff, "Flag '", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_43+currStrOff, flag->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_43+currStrOff, "' is not float.", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_43[currStrOff] = 0;
                }
                char * error =  ____BAH_COMPILER_VAR_43;
__BAH_panic(error,"/opt/bah/flags.bah:136");
}
double ctn =  flag->cont_float;
return ctn;
};
long int flags__isSet(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_44 =string(name);struct flag* flag =  this->getFlag((struct flags*)this,____BAH_COMPILER_VAR_44);
long int ctn =  flag->isSet;
return ctn;
};
void flags__parse(struct flags* this,__BAH_ARR_TYPE_cpstring args){
struct flag* currentFlag= null;
char isVal =  false;
this->args =  args;
long int i =  1;
while ((i<len(args))) {
struct string argName =  string(args->data[i]);
if ((isVal==true)) {
currentFlag->content =  argName.str((struct string*)&argName);
if ((currentFlag->type==FLAG_TYPE_INT)) {
char * ____BAH_COMPILER_VAR_45 =argName.str((struct string*)&argName);currentFlag->cont_int =  atoi(____BAH_COMPILER_VAR_45);
}
else if ((currentFlag->type==FLAG_TYPE_FLOAT)) {
char * ____BAH_COMPILER_VAR_46 =argName.str((struct string*)&argName);currentFlag->cont_float =  strtod(____BAH_COMPILER_VAR_46,0);
}
isVal =  false;
}
else {
if ((argName.charAt((struct string*)&argName,0)!=45)) {
i =  i + 1;
continue;
}
argName.trimLeft((struct string*)&argName,1);
if (argName.compare((struct string*)&argName,"help")) {
this->invalidate((struct flags*)this);
}
else if (argName.compare((struct string*)&argName,"h")) {
this->invalidate((struct flags*)this);
}
currentFlag =  this->getFlag((struct flags*)this,argName);
if ((currentFlag==null)) {
this->invalidate((struct flags*)this);
}
currentFlag->isSet =  1;
if ((currentFlag->type!=FLAG_TYPE_BOOL)) {
isVal =  true;
}
}
i =  i + 1;
};
if ((isVal==true)) {
if ((currentFlag->type!=FLAG_TYPE_BOOL)) {
this->invalidate((struct flags*)this);
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
this->timestamp =  time(0);
};
char * time__format(struct time* this,char * a){
long int lt =  localtime(&this->timestamp);
char * date =  memoryAlloc(1024);
strftime(date,1024,a,lt);
return date;
};
long int time__since(struct time* this){
long int nt =  time(0);
long int r =  nt - this->timestamp;
return r;
};
long int getTimeUnix(){
struct timespec ____BAH_COMPILER_VAR_47 = {};
struct timespec ts =  ____BAH_COMPILER_VAR_47;
long int s =  clock_gettime(CLOCK_REALTIME,&ts);
s =  ts.tv_sec * 1000000000 + ts.tv_nsec;
return s;
};
long int RAND_SEEDED;
//optimized out: seedRandom
//optimized out: randomInRange
//optimized out: cryptoRand
#define ROPE_LEAF_LEN 200
struct rope {
struct rope* left;
struct rope* right;
struct rope* parent;
char * str;
long int lCount;
long int len;
long int totalLen;
struct rope*(*getParent)(struct rope* this);
void(*addStr)(struct rope* this,char ** s);
char *(*toStr)(struct rope* this);
struct rope*(*add)(struct rope* this,struct rope* root2);
};
struct rope* rope__getParent(struct rope* this){
if ((this->parent==null)) {
return this;
}
return this->parent->getParent((struct rope*)this->parent);
};
void rope__addStr(struct rope* this,char ** s){
if (((this->left==null)&&(this->right==null))) {
strcat(*s,this->str);
return;
}
this->left->addStr((struct rope*)this->left,s);
this->right->addStr((struct rope*)this->right,s);
};
char * rope__toStr(struct rope* this){
if (((this->left==null)&&(this->right==null))) {
return this->str;
}
char * s =  memoryAlloc(this->totalLen + 1);
this->left->addStr((struct rope*)this->left,&s);
this->right->addStr((struct rope*)this->right,&s);
return s;
};
struct rope* rope__add(struct rope* this,struct rope* root2){
long int n1 =  this->len;
struct rope* ____BAH_COMPILER_VAR_48 = memoryAlloc(sizeof(struct rope));
____BAH_COMPILER_VAR_48->left= null;
____BAH_COMPILER_VAR_48->right= null;
____BAH_COMPILER_VAR_48->parent= null;
____BAH_COMPILER_VAR_48->str= null;
____BAH_COMPILER_VAR_48->getParent = rope__getParent;
____BAH_COMPILER_VAR_48->addStr = rope__addStr;
____BAH_COMPILER_VAR_48->toStr = rope__toStr;
____BAH_COMPILER_VAR_48->add = rope__add;
struct rope* tmp =  ____BAH_COMPILER_VAR_48;
tmp->parent =  null;
tmp->left =  this;
tmp->right =  root2;
root2->parent =  tmp;
this->parent =  root2->parent;
tmp->totalLen =  this->totalLen + root2->totalLen;
tmp->str =  null;
return tmp;
};
struct rope* createRopeStructure(struct rope* par,char * a,long int l,long int r){
struct rope* ____BAH_COMPILER_VAR_49 = memoryAlloc(sizeof(struct rope));
____BAH_COMPILER_VAR_49->left= null;
____BAH_COMPILER_VAR_49->right= null;
____BAH_COMPILER_VAR_49->parent= null;
____BAH_COMPILER_VAR_49->str= null;
____BAH_COMPILER_VAR_49->getParent = rope__getParent;
____BAH_COMPILER_VAR_49->addStr = rope__addStr;
____BAH_COMPILER_VAR_49->toStr = rope__toStr;
____BAH_COMPILER_VAR_49->add = rope__add;
struct rope* tmp =  ____BAH_COMPILER_VAR_49;
tmp->left =  null;
tmp->right =  null;
tmp->parent =  par;
if ((r - l>ROPE_LEAF_LEN)) {
tmp->str =  null;
tmp->lCount =  r - l;
tmp->lCount =  tmp->lCount / 2;
struct rope* node =  tmp;
long int m =  l + r;
m =  m / 2;
node->left =  createRopeStructure(node,a,l,m);
node->right =  createRopeStructure(node,a,m + 1,r);
}
else {
struct rope* node =  tmp;
tmp->lCount =  r - l;
long int j =  0;
long int i =  l;
char * arr =  memoryAlloc(r + 1);
while ((i<=r)) {
arr[j]=a[i];
j =  j+1;
i =  i+1;
};
tmp->str =  arr;
}
return tmp;
};
void ropeSet(struct rope* r,char * a){
long int n1 =  strlen(a);
struct rope* nr =  createRopeStructure(null,a,0,n1-1);
nr->totalLen =  n1;
nr->len =  n1;
*r =  *nr;
};
//optimized out: concatenateRopes
struct rope* rope(char * a){
long int n1 =  strlen(a);
struct rope* r =  createRopeStructure(null,a,0,n1-1);
r->totalLen =  n1;
r->len =  n1;
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
char * cm =  this->command;
if ((this->error==false)) {
char * ____BAH_COMPILER_VAR_51 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(cm);
long int strLen_1 = strlen(" 2>/dev/null");
;                            
                    ____BAH_COMPILER_VAR_51 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_51+currStrOff, cm, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_51+currStrOff, " 2>/dev/null", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_51[currStrOff] = 0;
                }
                cm =  ____BAH_COMPILER_VAR_51;
}
else {
char * ____BAH_COMPILER_VAR_52 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(cm);
long int strLen_1 = strlen(" 2>&1");
;                            
                    ____BAH_COMPILER_VAR_52 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_52+currStrOff, cm, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_52+currStrOff, " 2>&1", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_52[currStrOff] = 0;
                }
                cm =  ____BAH_COMPILER_VAR_52;
}
this->handle =  popen(cm,"w");
if ((this->handle==null)) {
return "";
}
if ((strcmp(this->input, null) != 0)) {
fputs(this->input,(void *)this->handle);
}
char * buff =  memoryAlloc(1025);
char * res =  "";
while (((void *)fgets(buff,1024,this->handle)!=null)) {
char * ____BAH_COMPILER_VAR_53 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(res);
long int strLen_1 = strlen(buff);
;                            
                    ____BAH_COMPILER_VAR_53 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_53+currStrOff, res, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_53+currStrOff, buff, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_53[currStrOff] = 0;
                }
                res =  ____BAH_COMPILER_VAR_53;
};
this->status =  pclose(this->handle);
return res;
};
__BAH_ARR_TYPE_char command__runBytes(struct command* this){
array(char)* arr = memoryAlloc(sizeof(array(char)));

arr->length = 0;
arr->elemSize = sizeof(char);
char * cm =  this->command;
if ((this->error==false)) {
char * ____BAH_COMPILER_VAR_54 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(cm);
long int strLen_1 = strlen(" 2>/dev/null");
;                            
                    ____BAH_COMPILER_VAR_54 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_54+currStrOff, cm, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_54+currStrOff, " 2>/dev/null", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_54[currStrOff] = 0;
                }
                cm =  ____BAH_COMPILER_VAR_54;
}
else {
char * ____BAH_COMPILER_VAR_55 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(cm);
long int strLen_1 = strlen(" 2>&1");
;                            
                    ____BAH_COMPILER_VAR_55 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_55+currStrOff, cm, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_55+currStrOff, " 2>&1", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_55[currStrOff] = 0;
                }
                cm =  ____BAH_COMPILER_VAR_55;
}
this->handle =  popen(cm,"r");
if ((this->handle==null)) {
return arr;
}
long int total =  0;
long int fd =  fileno(this->handle);
char * buff =  memoryAlloc(1024);
char * response =  "";
void * res =  fgets(buff,1023,this->handle);
while ((res!=null)) {
char * ____BAH_COMPILER_VAR_56 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(response);
long int strLen_1 = strlen(buff);
;                            
                    ____BAH_COMPILER_VAR_56 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_56+currStrOff, response, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_56+currStrOff, buff, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_56[currStrOff] = 0;
                }
                response =  ____BAH_COMPILER_VAR_56;
res =  fgets(buff,1023,this->handle);
};
this->status =  pclose(this->handle);
arr->data=response;
arr->length=strlen(response);
return arr;
};
struct command command(char * s){
struct command ____BAH_COMPILER_VAR_57 = {};
____BAH_COMPILER_VAR_57.command= null;
____BAH_COMPILER_VAR_57.error = true;
____BAH_COMPILER_VAR_57.status = 0;
____BAH_COMPILER_VAR_57.input = null;
____BAH_COMPILER_VAR_57.handle= null;
____BAH_COMPILER_VAR_57.run = command__run;
____BAH_COMPILER_VAR_57.runBytes = command__runBytes;
struct command cmd =  ____BAH_COMPILER_VAR_57;
cmd.command =  s;
return cmd;
};
//optimized out: exec
char * BAH_DIR;
char * BAH_OS;
char * BAH_CC;
#define BAH_VERSION "v1.1 (build 74)"
char debug;
char verboseRuntime;
char isObject;
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
char outterScope;
char isGlobal;
};
struct structMemb {
char * name;
char * type;
char isConst;
char * constVal;
char isArray;
char * from;
char outterScope;
char isGlobal;
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
};
char inArray(char needle,__BAH_ARR_TYPE_char arr){
long int i =  0;
while ((i<len(arr))) {

                    if (arr->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:38): arr[%d] with length %d\n", i, arr->length);
                        exit(1);
                    };
                    if ((needle==arr->data[i])) {
return true;
}
i =  i + 1;
};
return false;
};
char inArrayStr(char * needle,__BAH_ARR_TYPE_cpstring arr){
long int i =  0;
while ((i<len(arr))) {

                    if (arr->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:48): arr[%d] with length %d\n", i, arr->length);
                        exit(1);
                    };
                    if ((strcmp(needle, arr->data[i]) == 0)) {
return true;
}
i =  i + 1;
};
return false;
};
struct Tok makeToken(long int pos,long int lineNb,__BAH_ARR_TYPE_char cont,tokenType type){
struct Tok ____BAH_COMPILER_VAR_58 = {};
____BAH_COMPILER_VAR_58.cont = "";
____BAH_COMPILER_VAR_58.ogCont = "";
____BAH_COMPILER_VAR_58.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_58.pos = 0;
____BAH_COMPILER_VAR_58.line = 1;
____BAH_COMPILER_VAR_58.begLine = 1;
____BAH_COMPILER_VAR_58.bahType = "";
____BAH_COMPILER_VAR_58.isValue = false;
____BAH_COMPILER_VAR_58.isFunc = false;
____BAH_COMPILER_VAR_58.isOper = false;
struct Tok t =  ____BAH_COMPILER_VAR_58;
t.cont =  arrToStr(cont);
t.ogCont =  t.cont;
clear(cont);
t.pos =  pos;
t.line =  lineNb;
t.type =  type;
if ((type==TOKEN_TYPE_INT)) {
t.isValue =  true;
}
else if ((type==TOKEN_TYPE_STR)) {
t.isValue =  true;
}
else if ((type==TOKEN_TYPE_FLOAT)) {
t.isValue =  true;
}
else if ((type==TOKEN_TYPE_VAR)) {
t.isValue =  true;
}
if ((type==TOKEN_TYPE_BOOL)) {
t.isValue =  true;
}
else if ((type==TOKEN_TYPE_CHAR)) {
t.isValue =  true;
}
return t;
};
char isMinus(char c,char nc){
return ((c==45)&&isNumber(nc));
};
void lexerErr(long int line,long int pos,char * msg){
char * lineStr =  intToStr(line);
char * posStr =  intToStr(pos);
char * ____BAH_COMPILER_VAR_59 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\e[1;31m[LEXER-ERROR]\e[0m ");
long int strLen_1 = strlen(compilerState.currentFile);
long int strLen_2 = strlen(":");
long int strLen_3 = strlen(lineStr);
long int strLen_4 = strlen(":");
long int strLen_5 = strlen(posStr);
long int strLen_6 = strlen("\n\e[0m\n");
long int strLen_7 = strlen(msg);
;                            
                    ____BAH_COMPILER_VAR_59 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7);
                    
                    memcpy(____BAH_COMPILER_VAR_59+currStrOff, "\e[1;31m[LEXER-ERROR]\e[0m ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_59+currStrOff, compilerState.currentFile, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_59+currStrOff, ":", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_59+currStrOff, lineStr, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_59+currStrOff, ":", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_59+currStrOff, posStr, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_59+currStrOff, "\n\e[0m\n", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_59+currStrOff, msg, strLen_7);
                    currStrOff += strLen_7;
                    
                    ____BAH_COMPILER_VAR_59[currStrOff] = 0;
                }
                println(____BAH_COMPILER_VAR_59);
exit(1);
};
array(char)* enclavers;
array(char)* syntaxes;
array(char *)* keywords;
array(char)* varChars;
array(char)* seps;
typedef array(struct Tok)* __BAH_ARR_TYPE_Tok;
__BAH_ARR_TYPE_Tok lexer(char * os){
long int dur =  getTimeUnix();
array(char)* s =  strAsArr(os);
array(struct Tok)* tokens = memoryAlloc(sizeof(array(struct Tok)));

tokens->length = 0;
tokens->elemSize = sizeof(struct Tok);
long int codeLength =  len(s);
array(char)* memory = memoryAlloc(sizeof(array(char)));

memory->length = 0;
memory->elemSize = sizeof(char);
long int lineNb =  1;
long int i =  0;
for (; (i<codeLength); i =  i+1) {

                    if (s->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:114): s[%d] with length %d\n", i, s->length);
                        exit(1);
                    };
                    char c =  s->data[i];
char nc =  (char)0;
if ((i + 1<codeLength)) {

                    if (s->length <= i + 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:117): s[%d] with length %d\n", i + 1, s->length);
                        exit(1);
                    };
                    nc =  s->data[i + 1];
}
if ((c==47)) {

                    if (s->length <= i + 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:121): s[%d] with length %d\n", i + 1, s->length);
                        exit(1);
                    };
                    nc =  s->data[i + 1];
if ((nc==47)) {
for (; (i<codeLength); i =  i+1) {

                    if (s->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:125): s[%d] with length %d\n", i, s->length);
                        exit(1);
                    };
                    c =  s->data[i];
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
lineNb =  lineNb+1;
}
if ((c==(char)34)) {
long int pos =  i;
long int begLine =  lineNb;

{
long nLength = 0;
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[0] =  c;
memory->length = nLength+1;
} else {
memory->data[0] =  c;
}
};
i =  i + 1;
for (; (i<codeLength); i =  i+1) {

                    if (s->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:149): s[%d] with length %d\n", i, s->length);
                        exit(1);
                    };
                    c =  s->data[i];

                    if (s->length <= i-1) {
                        printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:150): s[%d] with length %d\n", i-1, s->length);
                        exit(1);
                    };
                    char pc =  s->data[i-1];
if ((c==(char)34)) {
if ((pc!=(char)92)) {

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[len(memory)] =  c;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  c;
}
};
break;
}
}
if ((c==(char)10)) {
lineNb =  lineNb + 1;
if ((pc!=(char)92)) {

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[len(memory)] =  (char)92;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  (char)92;
}
};
c =  110;
}
}

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[len(memory)] =  c;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  c;
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
tokens->data[len(tokens)] =  makeToken(pos,lineNb,memory,TOKEN_TYPE_STR);
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] =  makeToken(pos,lineNb,memory,TOKEN_TYPE_STR);
}
};

                    if (tokens->length <= len(tokens) - 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:170): tokens[%d] with length %d\n", len(tokens) - 1, tokens->length);
                        exit(1);
                    };
                    struct Tok lt =  tokens->data[len(tokens) - 1];
lt.begLine =  begLine;

{
long nLength = len(tokens) - 1;
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens) - 1] =  lt;
tokens->length = nLength+1;
} else {
tokens->data[len(tokens) - 1] =  lt;
}
};
}
else if ((isNumber(c)||isMinus(c,nc))) {

{
long nLength = 0;
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[0] =  c;
memory->length = nLength+1;
} else {
memory->data[0] =  c;
}
};
long int pos =  i;
i =  i + 1;
tokenType currentType =  TOKEN_TYPE_INT;
for (; (i<codeLength); i =  i+1) {

                    if (s->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:179): s[%d] with length %d\n", i, s->length);
                        exit(1);
                    };
                    c =  s->data[i];
if ((c==(char)46)) {
currentType =  TOKEN_TYPE_FLOAT;
}
else if ((isNumber(c)==0)) {
break;
}

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[len(memory)] =  c;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  c;
}
};
};
i =  i-1;

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] =  makeToken(pos,lineNb,memory,currentType);
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] =  makeToken(pos,lineNb,memory,currentType);
}
};
}
else if ((c==(char)39)) {
i =  i+1;

                    if (s->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:191): s[%d] with length %d\n", i, s->length);
                        exit(1);
                    };
                    char n =  s->data[i];
char * toInt =  intToStr((long int)nc);
memory =  strToArr(toInt);
i =  i+1;

                    if (s->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:195): s[%d] with length %d\n", i, s->length);
                        exit(1);
                    };
                    c =  s->data[i];
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
tokens->data[len(tokens)] =  makeToken(i-1,lineNb,memory,TOKEN_TYPE_CHAR);
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] =  makeToken(i-1,lineNb,memory,TOKEN_TYPE_CHAR);
}
};
}
else if ((c==(char)35)) {
long int pos =  i;

{
long nLength = 0;
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[0] =  c;
memory->length = nLength+1;
} else {
memory->data[0] =  c;
}
};
i =  i+1;
for (; (i<codeLength); i =  i+1) {

                    if (s->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:205): s[%d] with length %d\n", i, s->length);
                        exit(1);
                    };
                    c =  s->data[i];
if ((isAlphaNumeric(c)==0)) {
break;
}

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[len(memory)] =  c;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  c;
}
};
};
i =  i-1;

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] =  makeToken(pos,lineNb,memory,TOKEN_TYPE_KEYWORD);
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] =  makeToken(pos,lineNb,memory,TOKEN_TYPE_KEYWORD);
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
memory->data[0] =  c;
memory->length = nLength+1;
} else {
memory->data[0] =  c;
}
};

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] =  makeToken(i,lineNb,memory,TOKEN_TYPE_ENCL);
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] =  makeToken(i,lineNb,memory,TOKEN_TYPE_ENCL);
}
};
}
else if (inArray(c,syntaxes)) {

{
long nLength = 0;
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[0] =  c;
memory->length = nLength+1;
} else {
memory->data[0] =  c;
}
};
long int pos =  i;
i =  i+1;
char fc =  c;
for (; (i<codeLength); i =  i+1) {

                    if (s->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:222): s[%d] with length %d\n", i, s->length);
                        exit(1);
                    };
                    c =  s->data[i];

                int ____BAH_COMPILER_VAR_60 = 0;
                for(int i=len(syntaxes)-1; i != -1; i--) {
                    if (syntaxes->data[i] == c) {
                        ____BAH_COMPILER_VAR_60 = 1;
                        break;
                    };
                };
                if ((____BAH_COMPILER_VAR_60==false)) {
break;
}
if ((fc==60)) {
if (((c!=45)&&(c!=61))) {
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
memory->data[len(memory)] =  c;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  c;
}
};
};
i =  i-1;

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] =  makeToken(pos,lineNb,memory,TOKEN_TYPE_SYNTAX);
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] =  makeToken(pos,lineNb,memory,TOKEN_TYPE_SYNTAX);
}
};
}
else if (inArray(c,seps)) {

{
long nLength = 0;
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[0] =  c;
memory->length = nLength+1;
} else {
memory->data[0] =  c;
}
};

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] =  makeToken(i,lineNb,memory,TOKEN_TYPE_SEP);
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] =  makeToken(i,lineNb,memory,TOKEN_TYPE_SEP);
}
};
}
else if ((isAlphaNumeric(c)||inArray(c,varChars))) {

{
long nLength = 0;
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[0] =  c;
memory->length = nLength+1;
} else {
memory->data[0] =  c;
}
};
long int pos =  i;
i =  i+1;
for (; (i<codeLength); i =  i+1) {

                    if (s->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:257): s[%d] with length %d\n", i, s->length);
                        exit(1);
                    };
                    c =  s->data[i];
if ((isAlphaNumeric(c)==0)) {

                int ____BAH_COMPILER_VAR_61 = 0;
                for(int i=len(varChars)-1; i != -1; i--) {
                    if (varChars->data[i] == c) {
                        ____BAH_COMPILER_VAR_61 = 1;
                        break;
                    };
                };
                if ((____BAH_COMPILER_VAR_61==false)) {
if ((c==62)) {

                    if (memory->length <= len(memory)-1) {
                        printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:261): memory[%d] with length %d\n", len(memory)-1, memory->length);
                        exit(1);
                    };
                    char lc =  memory->data[len(memory)-1];
if ((lc==45)) {

{
long nLength = len(memory)-1;
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[len(memory)-1] =  (char)0;
memory->length = nLength+1;
} else {
memory->data[len(memory)-1] =  (char)0;
}
};
i =  i-1;
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
memory->data[len(memory)] =  c;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  c;
}
};
};
i =  i-1;
tokenType currentType =  TOKEN_TYPE_VAR;
char * memstr =  arrAsStr(memory);

                int ____BAH_COMPILER_VAR_62 = 0;
                for(int i=len(keywords)-1; i != -1; i--) {
                    if (keywords->data[i] != 0 && strcmp(keywords->data[i], memstr) == 0) {
                        ____BAH_COMPILER_VAR_62 = 1;
                        break;
                    };
                };
                if (____BAH_COMPILER_VAR_62) {
currentType =  TOKEN_TYPE_KEYWORD;
}

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] =  makeToken(pos,lineNb,memory,currentType);
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] =  makeToken(pos,lineNb,memory,currentType);
}
};
}
};
totalLines =  totalLines + lineNb - 1;
dur =  getTimeUnix() - dur;
totalLexerTime =  totalLexerTime + dur;
return tokens;
};
char hasStructSep(struct string n){
if (n.count((struct string*)&n,".")) {
return true;
}
if (n.count((struct string*)&n,"->")) {
return true;
}
return false;
};
struct string splitStructSepBefore(struct string n){
if (n.count((struct string*)&n,".")) {
char * ____BAH_COMPILER_VAR_63 =splitStringBefore(n,".");struct string res =  string(____BAH_COMPILER_VAR_63);
return res;
}
if (n.count((struct string*)&n,"->")) {
char * ____BAH_COMPILER_VAR_64 =splitStringBefore(n,"->");struct string res =  string(____BAH_COMPILER_VAR_64);
return res;
}
return string("");
};
struct string splitStructSepAfter(struct string n){
long int i =  n.length;
while ((i>0)) {
char c =  n.charAt((struct string*)&n,i);
if ((c==46)) {
break;
}
else if ((c==62)) {
char pc =  n.charAt((struct string*)&n,i-1);
if ((pc==45)) {
break;
}
}
i =  i - 1;
};
i =  i + 1;
n.trimLeft((struct string*)&n,i);
return n;
};
struct cStruct* searchStruct(char * name,struct Elems* elems){
struct string n =  string(name);
n.replace((struct string*)&n,"&","");
n.replace((struct string*)&n,"*","");
name =  n.content;
long int i =  0;
while ((i<len(elems->structs))) {

                    if (elems->structs->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/struct.bah:54): elems->structs[%d] with length %d\n", i, elems->structs->length);
                        exit(1);
                    };
                    struct cStruct* s =  elems->structs->data[i];
if ((strcmp(s->name, name) == 0)) {
return s;
}
i =  i + 1;
};
return null;
};
struct structMemb* searchStructMemb(char * name,struct cStruct* s,struct Elems* elems){
struct string n =  string(name);
if (hasStructSep(n)) {
struct string rn =  splitStructSepBefore(n);
name =  rn.content;
n.trimLeft((struct string*)&n,rn.length);
if (n.hasPrefix((struct string*)&n,".")) {
n.trimLeft((struct string*)&n,1);
}
else {
n.trimLeft((struct string*)&n,2);
}
char * membs =  n.content;
struct structMemb* memb =  searchStructMemb(name,s,elems);
if ((n.length>0)) {
s =  searchStruct(memb->type,elems);
char * nstr =  n.str((struct string*)&n);
memb =  searchStructMemb(nstr,s,elems);
}
return memb;
}
array(struct structMemb*)* members =  s->members;
long int i =  0;
while ((i<len(members))) {

                    if (members->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/struct.bah:86): members[%d] with length %d\n", i, members->length);
                        exit(1);
                    };
                    struct structMemb* m =  members->data[i];
if ((strcmp(m->name, name) == 0)) {
return m;
}
i =  i + 1;
};
array(struct func*)* mthds =  s->methods;
i =  0;
while ((i<len(mthds))) {

                    if (mthds->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/struct.bah:94): mthds[%d] with length %d\n", i, mthds->length);
                        exit(1);
                    };
                    struct func* m =  mthds->data[i];
if ((strcmp(m->name, name) == 0)) {
struct structMemb* ____BAH_COMPILER_VAR_65 = memoryAlloc(sizeof(struct structMemb));
____BAH_COMPILER_VAR_65->name = "";
____BAH_COMPILER_VAR_65->type = "";
____BAH_COMPILER_VAR_65->isConst = false;
____BAH_COMPILER_VAR_65->constVal = "";
____BAH_COMPILER_VAR_65->isArray = false;
____BAH_COMPILER_VAR_65->from = "";
____BAH_COMPILER_VAR_65->outterScope = false;
____BAH_COMPILER_VAR_65->isGlobal = false;
____BAH_COMPILER_VAR_65->def = "";
____BAH_COMPILER_VAR_65->isFn = false;
struct structMemb* sm =  ____BAH_COMPILER_VAR_65;
sm->name =  m->name;
sm->from =  m->from;
sm->type =  m->returns->type;
sm->isFn =  true;
return sm;
}
i =  i + 1;
};
if ((strlen(s->extendedFrom)==0)) {
return null;
}
struct cStruct* es =  searchStruct(s->extendedFrom,elems);
return searchStructMemb(name,es,elems);
};
char isRCPpointerType(char * t){
if (strHasPrefix(t,"function(")) {
return false;
}
if (((((((strcmp(t, "cpstring") == 0)||(strcmp(t, "ptr") == 0))||(strCount(t,"*")>0))||(strHasPrefix(t,"[]")==true))||(strHasPrefix(t,"chan:")==true))||(strHasPrefix(t,"map:")==true))) {
return true;
}
return false;
};
char isRCPtype(char * t,struct Elems* elems){
if ((isRCPpointerType(t)==true)) {
return true;
}
struct cStruct* s =  searchStruct(t,elems);
if ((((s!=null)&&(s->isBinding==false))&&(s->hasRCPmemb==true))) {
return true;
}
return false;
};
struct string getCType(char * t,struct Elems* elems){
if ((strlen(t)==0)) {
return string("void");
}
struct string tp =  string(t);
tp.replace((struct string*)&tp," ","");
if (tp.hasPrefix((struct string*)&tp,"[]")) {
tp.trimLeft((struct string*)&tp,2);
char * tpstr =  tp.str((struct string*)&tp);
tp =  getCType(tpstr,elems);
t =  tp.str((struct string*)&tp);
char * ____BAH_COMPILER_VAR_66 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("array(");
long int strLen_1 = strlen(t);
long int strLen_2 = strlen(")*");
;                            
                    ____BAH_COMPILER_VAR_66 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_66+currStrOff, "array(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_66+currStrOff, t, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_66+currStrOff, ")*", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_66[currStrOff] = 0;
                }
                char * r =  ____BAH_COMPILER_VAR_66;
return string(r);
}
struct string ctp =  tp;
ctp.replace((struct string*)&ctp,"*","");
if ((tp.hasPrefix((struct string*)&tp,"chan:")==1)) {
tp.set((struct string*)&tp,"struct channel *");
}
else if ((tp.hasPrefix((struct string*)&tp,"map:")==1)) {
tp.set((struct string*)&tp,"struct mapWrapper *");
}
else if ((tp.hasPrefix((struct string*)&tp,"buffer:")==1)) {
tp.set((struct string*)&tp,"char*");
}
else if (ctp.compare((struct string*)&ctp,"int")) {
tp.replace((struct string*)&tp,"int","long int");
}
else if (ctp.compare((struct string*)&ctp,"int32")) {
tp.replace((struct string*)&tp,"int32","int");
}
else if (ctp.compare((struct string*)&ctp,"uint32")) {
tp.replace((struct string*)&tp,"uint32","unsigned int");
}
else if (ctp.compare((struct string*)&ctp,"uint")) {
tp.replace((struct string*)&tp,"uint","unsigned long int");
}
else if (ctp.compare((struct string*)&ctp,"float32")) {
tp.replace((struct string*)&tp,"float32","float");
}
else if (ctp.compare((struct string*)&ctp,"ufloat32")) {
tp.replace((struct string*)&tp,"ufloat32","unsigned float");
}
else if (ctp.compare((struct string*)&ctp,"ufloat")) {
tp.replace((struct string*)&tp,"ufloat","unsigned double");
}
else if (ctp.compare((struct string*)&ctp,"float")) {
tp.replace((struct string*)&tp,"float","double");
}
else if (ctp.compare((struct string*)&ctp,"long")) {
tp.replace((struct string*)&tp,"long","long long");
}
else if (ctp.compare((struct string*)&ctp,"ulong")) {
tp.replace((struct string*)&tp,"ulong","unsigned long long");
}
else if (ctp.compare((struct string*)&ctp,"cpstring")) {
tp.replace((struct string*)&tp,"cpstring","char *");
}
else if (ctp.compare((struct string*)&ctp,"ptr")) {
tp.replace((struct string*)&tp,"ptr","void *");
}
else if (ctp.compare((struct string*)&ctp,"ushort")) {
tp.replace((struct string*)&tp,"ushort","unsigned short");
}
else if (ctp.compare((struct string*)&ctp,"byte")) {
tp.replace((struct string*)&tp,"byte","unsigned char");
}
else if (ctp.compare((struct string*)&ctp,"bool")) {
tp.replace((struct string*)&tp,"bool","char");
}
else if (ctp.compare((struct string*)&ctp,"char")) {
}
else {
char * ctpstr =  ctp.str((struct string*)&ctp);
struct cStruct* s =  searchStruct(ctpstr,elems);
if ((s!=null)) {
tp.prepend((struct string*)&tp,"struct ");
}
else {
long int i =  0;
while ((i<len(elems->types))) {

                    if (elems->types->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/type.bah:97): elems->types[%d] with length %d\n", i, elems->types->length);
                        exit(1);
                    };
                    char * ct =  elems->types->data[i];
if (ctp.compare((struct string*)&ctp,ct)) {
return tp;
}
i =  i + 1;
};
return string("");
}
}
return tp;
};
char compTypes(char * a,char * b){
if (((strcmp(a, "ptr") == 0)||(strcmp(b, "ptr") == 0))) {
return true;
}
if (((strcmp(a, "cpstring") == 0)&&strHasPrefix(b,"buffer:"))) {
return true;
}
if (((strcmp(b, "cpstring") == 0)&&strHasPrefix(a,"buffer:"))) {
return true;
}
return (strcmp(a, b) == 0);
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
char * base =  origin;
return base+this->offset;
};
typedef array(struct reflectElement)* __BAH_ARR_TYPE_reflectElement;
struct reflectElement __reflect(void * v,long int s,char * t,char * n,char isArr,struct reflectElement* ae,char isStruct,__BAH_ARR_TYPE_reflectElement sl,long int offset){
struct reflectElement ____BAH_COMPILER_VAR_67 = {};
____BAH_COMPILER_VAR_67.type= null;
____BAH_COMPILER_VAR_67.name= null;
____BAH_COMPILER_VAR_67.arrayElem= null;
____BAH_COMPILER_VAR_67.structLayout = memoryAlloc(sizeof(array(struct reflectElement)));
            ____BAH_COMPILER_VAR_67.structLayout->length = 0;
            ____BAH_COMPILER_VAR_67.structLayout->elemSize = sizeof(struct reflectElement);
            ____BAH_COMPILER_VAR_67.value= null;
____BAH_COMPILER_VAR_67.calculateOffset = reflectElement__calculateOffset;
struct reflectElement re =  ____BAH_COMPILER_VAR_67;
re.size =  s;
re.type =  t;
re.name =  n;
re.isArray =  isArr;
re.arrayElem =  ae;
re.isStruct =  isStruct;
re.structLayout =  sl;
re.value =  v;
re.offset =  offset;
return re;
};
typedef void * reflectSymbols;
__BAH_ARR_TYPE_reflectElement __dumpSymbols(__BAH_ARR_TYPE_reflectElement syms){
return syms;
};
struct reflectElement __debug_get_sym(__BAH_ARR_TYPE_reflectElement syms,struct string a){
if ((a.count((struct string*)&a,".")>0)) {
array(struct string)* parts =  splitString(a,".");

                    if (parts->length <= 0) {
                        printf("array (/opt/bah/reflect.bah:63): parts[%d] with length %d\n", 0, parts->length);
                        exit(1);
                    };
                    struct string p1 =  parts->data[0];

                    if (parts->length <= 1) {
                        printf("array (/opt/bah/reflect.bah:64): parts[%d] with length %d\n", 1, parts->length);
                        exit(1);
                    };
                    struct string p2 =  parts->data[1];
long int j =  0;
for (; (j<len(syms)); j =  j+1) {

                    if (syms->length <= j) {
                        printf("array (/opt/bah/reflect.bah:66): syms[%d] with length %d\n", j, syms->length);
                        exit(1);
                    };
                    struct reflectElement s =  syms->data[j];
if ((strcmp(s.name, p1.str((struct string*)&p1)) == 0)) {
long int k =  0;
for (; (k<len(s.structLayout)); k =  k+1) {

                    if (s.structLayout->length <= k) {
                        printf("array (/opt/bah/reflect.bah:69): s.structLayout[%d] with length %d\n", k, s.structLayout->length);
                        exit(1);
                    };
                    struct reflectElement m =  s.structLayout->data[k];
if ((strcmp(m.name, p2.str((struct string*)&p2)) == 0)) {
m.value =  m.calculateOffset((struct reflectElement*)&m,s.value);
return m;
}
};
break;
}
};
}
else {
long int j =  0;
for (; (j<len(syms)); j =  j+1) {

                    if (syms->length <= j) {
                        printf("array (/opt/bah/reflect.bah:80): syms[%d] with length %d\n", j, syms->length);
                        exit(1);
                    };
                    struct reflectElement s =  syms->data[j];
if ((strcmp(s.name, a.str((struct string*)&a)) == 0)) {
return s;
}
};
}
struct reflectElement ____BAH_COMPILER_VAR_68 = {};
____BAH_COMPILER_VAR_68.type= null;
____BAH_COMPILER_VAR_68.name= null;
____BAH_COMPILER_VAR_68.arrayElem= null;
____BAH_COMPILER_VAR_68.structLayout = memoryAlloc(sizeof(array(struct reflectElement)));
            ____BAH_COMPILER_VAR_68.structLayout->length = 0;
            ____BAH_COMPILER_VAR_68.structLayout->elemSize = sizeof(struct reflectElement);
            ____BAH_COMPILER_VAR_68.value= null;
____BAH_COMPILER_VAR_68.calculateOffset = reflectElement__calculateOffset;
struct reflectElement ns =  ____BAH_COMPILER_VAR_68;
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
long int l =  len(this->children);
long int i =  0;
while ((i<l)) {

                    if (this->children->length <= i) {
                        printf("array (/opt/bah/json.bah:29): this->children[%d] with length %d\n", i, this->children->length);
                        exit(1);
                    };
                    struct jsonElement* elem =  this->children->data[i];
char fc =  cpstringCharAt(elem->key,0);
if ((fc==(char)34)) {
array(char)* nk = memoryAlloc(sizeof(array(char)));

nk->length = 0;
nk->elemSize = sizeof(char);
long int lk =  strlen(elem->key);
long int j =  1;
while ((j<lk - 1)) {
char c =  cpstringCharAt(elem->key,j);

{
long nLength = j-1;
if (nk->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nk->data, (nLength+50)*sizeof(char));
nk->data = newPtr;
}
nk->data[j-1] =  c;
nk->length = nLength+1;
} else {
nk->data[j-1] =  c;
}
};
j =  j + 1;
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
i =  i + 1;
};
void * z =  (void *)0;
return z;
};
char * jsonElement__str(struct jsonElement* this){
char * ctn =  this->content;
return ctn;
};
void jsonElement__scan(struct jsonElement* this,struct reflectElement e){
json_scan_inner(this,e,false);
};
void json_scan_inner(void * thisp,struct reflectElement e,char isMember){
struct jsonElement* this =  thisp;
if ((e.isStruct==true)) {
long int i =  0;
while ((i<len(e.structLayout))) {

                    if (e.structLayout->length <= i) {
                        printf("array (/opt/bah/json.bah:71): e.structLayout[%d] with length %d\n", i, e.structLayout->length);
                        exit(1);
                    };
                    struct reflectElement m =  e.structLayout->data[i];
struct jsonElement* ov =  this->get((struct jsonElement*)this,m.name);
if ((ov!=null)) {
json_scan_inner(ov,m,true);
}
i =  i + 1;
};
}
else if ((strcmp(e.type, "int") == 0)) {
long int* ep =  e.value;
*ep =  strToInt(this->content);
}
else if ((strcmp(e.type, "cpstring") == 0)) {
char ** ep =  e.value;
*ep =  memoryAlloc(strlen(this->content) + 1);
strcpy(*ep,this->content);
}
else if ((strcmp(e.type, "float") == 0)) {
double* ep =  e.value;
*ep =  strToFloat(this->content);
}
else if ((strcmp(e.type, "bool") == 0)) {
char* ep =  e.value;
if (((strcmp(this->content, "1") == 0)||(strcmp(this->content, "true") == 0))) {
*ep =  true;
}
else {
*ep =  false;
}
}
else if ((e.isArray==true)) {
if ((len(this->children)==0)) {
return;
}
struct reflectElement* ae =  e.arrayElem;
if ((strcmp(ae->type, "int") == 0)) {
array(long int)* arr = memoryAlloc(sizeof(array(long int)));

arr->length = 0;
arr->elemSize = sizeof(long int);
void ** arrPtr =  e.value;
arr =  *arrPtr;
long int i =  0;
while ((i<len(this->children))) {

                    if (this->children->length <= i) {
                        printf("array (/opt/bah/json.bah:106): this->children[%d] with length %d\n", i, this->children->length);
                        exit(1);
                    };
                    struct jsonElement* c =  this->children->data[i];

{
long nLength = i;
if (arr->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(arr->data, (nLength+50)*sizeof(long int));
arr->data = newPtr;
}
arr->data[i] =  strToInt(c->content);
arr->length = nLength+1;
} else {
arr->data[i] =  strToInt(c->content);
}
};
i =  i + 1;
};
}
else if ((strcmp(ae->type, "float") == 0)) {
array(double)* arr = memoryAlloc(sizeof(array(double)));

arr->length = 0;
arr->elemSize = sizeof(double);
if ((isMember==true)) {
void ** arrPtr =  e.value;
arr =  *arrPtr;
}
else {
arr =  e.value;
}
long int i =  0;
while ((i<len(this->children))) {

                    if (this->children->length <= i) {
                        printf("array (/opt/bah/json.bah:119): this->children[%d] with length %d\n", i, this->children->length);
                        exit(1);
                    };
                    struct jsonElement* c =  this->children->data[i];

{
long nLength = i;
if (arr->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(arr->data, (nLength+50)*sizeof(double));
arr->data = newPtr;
}
arr->data[i] =  strToFloat(c->content);
arr->length = nLength+1;
} else {
arr->data[i] =  strToFloat(c->content);
}
};
i =  i + 1;
};
}
else if ((strcmp(ae->type, "cpstring") == 0)) {
array(char *)* arr = memoryAlloc(sizeof(array(char *)));

arr->length = 0;
arr->elemSize = sizeof(char *);
void ** arrPtr =  e.value;
arr =  *arrPtr;
long int i =  0;
while ((i<len(this->children))) {

                    if (this->children->length <= i) {
                        printf("array (/opt/bah/json.bah:128): this->children[%d] with length %d\n", i, this->children->length);
                        exit(1);
                    };
                    struct jsonElement* c =  this->children->data[i];

{
long nLength = i;
if (arr->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(arr->data, (nLength+50)*sizeof(char *));
arr->data = newPtr;
}
arr->data[i] =  memoryAlloc(strlen(c->content) + 1);
arr->length = nLength+1;
} else {
arr->data[i] =  memoryAlloc(strlen(c->content) + 1);
}
};
strcpy(arr->data[i],c->content);
i =  i + 1;
};
}
else if ((ae->isStruct==true)) {
array(void *)* arr = memoryAlloc(sizeof(array(void *)));

arr->length = 0;
arr->elemSize = sizeof(void *);
void ** arrPtr =  e.value;
arr =  *arrPtr;
long int i =  0;
while ((i<len(this->children))) {

                    if (this->children->length <= i) {
                        printf("array (/opt/bah/json.bah:138): this->children[%d] with length %d\n", i, this->children->length);
                        exit(1);
                    };
                    struct jsonElement* c =  this->children->data[i];
void * ne =  memoryAlloc(ae->size);
long int j =  0;
while ((j<len(ae->structLayout))) {

                    if (ae->structLayout->length <= j) {
                        printf("array (/opt/bah/json.bah:141): ae->structLayout[%d] with length %d\n", j, ae->structLayout->length);
                        exit(1);
                    };
                    struct reflectElement m =  ae->structLayout->data[j];
m.value =  m.calculateOffset((struct reflectElement*)&m,ne);
struct jsonElement* ov =  c->get((struct jsonElement*)c,m.name);
if ((ov!=null)) {
json_scan_inner(ov,m,true);
}
j =  j + 1;
};

{
long nLength = i;
if (arr->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(arr->data, (nLength+50)*sizeof(void *));
arr->data = newPtr;
}
arr->data[i] =  ne;
arr->length = nLength+1;
} else {
arr->data[i] =  ne;
}
};
i =  i + 1;
};
}
}
else if (strHasPrefix(e.type,"map:")) {
struct mapWrapper** p =  e.value;
long int i =  0;
for (; (i<len(this->children)); i =  i+1) {

                    if (this->children->length <= i) {
                        printf("array (/opt/bah/json.bah:156): this->children[%d] with length %d\n", i, this->children->length);
                        exit(1);
                    };
                    struct jsonElement* c =  this->children->data[i];
struct reflectElement* ae =  e.arrayElem;
void * v =  memoryAlloc(ae->size);
ae->value =  &v;
long int j =  0;
for (; (j<len(ae->structLayout)); j =  j+1) {

                    if (ae->structLayout->length <= j) {
                        printf("array (/opt/bah/json.bah:161): ae->structLayout[%d] with length %d\n", j, ae->structLayout->length);
                        exit(1);
                    };
                    struct reflectElement m =  ae->structLayout->data[j];
m.value =  m.calculateOffset((struct reflectElement*)&m,&v);

{
long nLength = j;
if (ae->structLayout->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(ae->structLayout->data, (nLength+50)*sizeof(struct reflectElement));
ae->structLayout->data = newPtr;
}
ae->structLayout->data[j] =  m;
ae->structLayout->length = nLength+1;
} else {
ae->structLayout->data[j] =  m;
}
};
};
json_scan_inner(c,*ae,true);
struct string k =  string(c->key);
k.trimLeft((struct string*)&k,1);
k.trimRight((struct string*)&k,1);
if (((((strCount(ae->type,"*")||(strcmp(ae->type, "ptr") == 0))||(strcmp(ae->type, "cpstring") == 0))||strHasPrefix(ae->type,"[]"))||strHasPrefix(ae->type,"map:"))) {
char * ____BAH_COMPILER_VAR_69 =k.str((struct string*)&k);mapWrapper__set(*p,____BAH_COMPILER_VAR_69,v);
}
else {
char * ____BAH_COMPILER_VAR_70 =k.str((struct string*)&k);mapWrapper__set(*p,____BAH_COMPILER_VAR_70,&v);
}
};
}
};
struct jsonElement* parseJson(char * s){
struct jsonElement* ____BAH_COMPILER_VAR_71 = memoryAlloc(sizeof(struct jsonElement));
____BAH_COMPILER_VAR_71->key= null;
____BAH_COMPILER_VAR_71->content= null;
____BAH_COMPILER_VAR_71->children = memoryAlloc(sizeof(array(struct jsonElement*)));
            ____BAH_COMPILER_VAR_71->children->length = 0;
            ____BAH_COMPILER_VAR_71->children->elemSize = sizeof(struct jsonElement*);
            ____BAH_COMPILER_VAR_71->get = jsonElement__get;
____BAH_COMPILER_VAR_71->str = jsonElement__str;
____BAH_COMPILER_VAR_71->scan = jsonElement__scan;
struct jsonElement* jsonElem =  ____BAH_COMPILER_VAR_71;
long int lenS =  strlen(s);
long int i =  0;
while ((i<lenS)) {
if ((isSpace(cpstringCharAt(s,i))==0)) {
break;
}
i =  i + 1;
};
char fc =  cpstringCharAt(s,i);
if ((fc==91)) {
jsonElem->type =  JSON_TYPE_ARRAY;
}
else if ((fc==123)) {
jsonElem->type =  JSON_TYPE_MAP;
}
else if ((fc==(char)34)) {
jsonElem->type =  JSON_TYPE_STRING;
array(char)* ns = memoryAlloc(sizeof(array(char)));

ns->length = 0;
ns->elemSize = sizeof(char);
i =  i + 1;
long int start =  i;
while ((i<lenS - 1)) {
char c =  cpstringCharAt(s,i);
if (((i>start)&&(cpstringCharAt(s,i-1)==(char)92))) {
if ((c==110)) {
c =  (char)10;
}
else if ((c==114)) {
c =  (char)13;
}

{
long nLength = len(ns)-1;
if (ns->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(ns->data, (nLength+50)*sizeof(char));
ns->data = newPtr;
}
ns->data[len(ns)-1] =  c;
ns->length = nLength+1;
} else {
ns->data[len(ns)-1] =  c;
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
ns->data[len(ns)] =  c;
ns->length = nLength+1;
} else {
ns->data[len(ns)] =  c;
}
};
}
i =  i + 1;
};
jsonElem->content =  arrToStr(ns);
}
else if (isNumber(cpstringCharAt(s,strlen(s)-1))) {
char isFloat =  false;
while ((i<lenS)) {
if ((cpstringCharAt(s,i)==46)) {
isFloat =  true;
break;
}
i =  i + 1;
};
if ((isFloat==true)) {
jsonElem->type =  JSON_TYPE_FLOAT;
}
else {
jsonElem->type =  JSON_TYPE_INT;
}
jsonElem->content =  s;
}
else {
return null;
}
if ((jsonElem->type==JSON_TYPE_ARRAY)) {
i =  i + 1;
long int trim =  1;
long int j =  lenS-1;
while ((j>=0)) {
char c =  cpstringCharAt(s,j);
if (isSpace(c)) {
trim =  trim + 1;
}
else {
break;
}
j =  j - 1;
};
while ((i<lenS - 1)) {
char c =  cpstringCharAt(s,i);
if ((isSpace(c)==0)) {
break;
}
i =  i + 1;
};
array(char)* currentElem = memoryAlloc(sizeof(array(char)));

currentElem->length = 0;
currentElem->elemSize = sizeof(char);
long int currentBracks =  0;
long int currentBraces =  0;
long int currentQuotes =  0;
long int elemIndex =  0;
while ((i<lenS - trim)) {
char c =  cpstringCharAt(s,i);
if ((c==(char)34)) {
if ((currentQuotes==0)) {
currentQuotes =  1;
}
else {
currentQuotes =  0;
}
}
else if ((c==91)) {
currentBracks =  currentBracks + 1;
}
else if ((c==93)) {
currentBracks =  currentBracks - 1;
}
else if ((c==123)) {
currentBraces =  currentBraces + 1;
}
else if ((c==125)) {
currentBraces =  currentBraces - 1;
}
long int total =  currentBracks + currentBraces + currentQuotes;
if ((total>0)) {

{
long nLength = len(currentElem);
if (currentElem->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(currentElem->data, (nLength+50)*sizeof(char));
currentElem->data = newPtr;
}
currentElem->data[len(currentElem)] =  c;
currentElem->length = nLength+1;
} else {
currentElem->data[len(currentElem)] =  c;
}
};
i =  i + 1;
continue;
}
if ((c==44)) {
char * ____BAH_COMPILER_VAR_72 =arrToStr(currentElem);struct jsonElement* child =  parseJson(____BAH_COMPILER_VAR_72);
if ((child!=null)) {

{
long nLength = elemIndex;
if (jsonElem->children->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(jsonElem->children->data, (nLength+50)*sizeof(struct jsonElement*));
jsonElem->children->data = newPtr;
}
jsonElem->children->data[elemIndex] =  child;
jsonElem->children->length = nLength+1;
} else {
jsonElem->children->data[elemIndex] =  child;
}
};
}
clear(currentElem);
elemIndex =  elemIndex + 1;
}
else {
if (isSpace(c)) {
i =  i + 1;
continue;
}

{
long nLength = len(currentElem);
if (currentElem->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(currentElem->data, (nLength+50)*sizeof(char));
currentElem->data = newPtr;
}
currentElem->data[len(currentElem)] =  c;
currentElem->length = nLength+1;
} else {
currentElem->data[len(currentElem)] =  c;
}
};
}
i =  i + 1;
};
char * ____BAH_COMPILER_VAR_73 =arrToStr(currentElem);struct jsonElement* child =  parseJson(____BAH_COMPILER_VAR_73);
if ((child!=null)) {

{
long nLength = elemIndex;
if (jsonElem->children->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(jsonElem->children->data, (nLength+50)*sizeof(struct jsonElement*));
jsonElem->children->data = newPtr;
}
jsonElem->children->data[elemIndex] =  child;
jsonElem->children->length = nLength+1;
} else {
jsonElem->children->data[elemIndex] =  child;
}
};
}
}
else if ((jsonElem->type==JSON_TYPE_MAP)) {
i =  i + 1;
long int trim =  1;
long int j =  lenS-1;
while ((j>=0)) {
char c =  cpstringCharAt(s,j);
if (isSpace(c)) {
trim =  trim + 1;
}
else {
break;
}
j =  j - 1;
};
while ((i<lenS - 1)) {
char c =  cpstringCharAt(s,i);
if ((isSpace(c)==0)) {
break;
}
i =  i + 1;
};
array(char)* currentElem = memoryAlloc(sizeof(array(char)));

currentElem->length = 0;
currentElem->elemSize = sizeof(char);
array(char)* currentKey = memoryAlloc(sizeof(array(char)));

currentKey->length = 0;
currentKey->elemSize = sizeof(char);
long int isVal =  0;
long int currentBracks =  0;
long int currentBraces =  0;
long int currentQuotes =  0;
long int elemIndex =  0;
while ((i<lenS - trim)) {
char c =  cpstringCharAt(s,i);
if ((c==(char)34)) {
if ((currentQuotes==0)) {
currentQuotes =  1;
}
else {
currentQuotes =  0;
}
}
else if ((c==91)) {
currentBracks =  currentBracks + 1;
}
else if ((c==93)) {
currentBracks =  currentBracks - 1;
}
else if ((c==123)) {
currentBraces =  currentBraces + 1;
}
else if ((c==125)) {
currentBraces =  currentBraces - 1;
}
long int total =  currentBracks + currentBraces + currentQuotes;
if ((total>0)) {
if ((isVal==1)) {

{
long nLength = len(currentElem);
if (currentElem->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(currentElem->data, (nLength+50)*sizeof(char));
currentElem->data = newPtr;
}
currentElem->data[len(currentElem)] =  c;
currentElem->length = nLength+1;
} else {
currentElem->data[len(currentElem)] =  c;
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
currentKey->data[len(currentKey)] =  c;
currentKey->length = nLength+1;
} else {
currentKey->data[len(currentKey)] =  c;
}
};
}
i =  i + 1;
continue;
}
if ((c==58)) {
isVal =  1;
}
else if ((c==44)) {
char * ____BAH_COMPILER_VAR_74 =arrToStr(currentElem);struct jsonElement* elem =  parseJson(____BAH_COMPILER_VAR_74);
if ((elem!=null)) {
elem->key =  arrToStr(currentKey);

{
long nLength = elemIndex;
if (jsonElem->children->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(jsonElem->children->data, (nLength+50)*sizeof(struct jsonElement*));
jsonElem->children->data = newPtr;
}
jsonElem->children->data[elemIndex] =  elem;
jsonElem->children->length = nLength+1;
} else {
jsonElem->children->data[elemIndex] =  elem;
}
};
elemIndex =  elemIndex + 1;
}
clear(currentElem);
clear(currentKey);
isVal =  0;
}
else {
if (isSpace(c)) {
i =  i + 1;
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
currentElem->data[len(currentElem)] =  c;
currentElem->length = nLength+1;
} else {
currentElem->data[len(currentElem)] =  c;
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
currentKey->data[len(currentKey)] =  c;
currentKey->length = nLength+1;
} else {
currentKey->data[len(currentKey)] =  c;
}
};
}
}
i =  i + 1;
};
char * ____BAH_COMPILER_VAR_75 =arrToStr(currentElem);struct jsonElement* elem =  parseJson(____BAH_COMPILER_VAR_75);
if ((elem!=null)) {
elem->key =  arrToStr(currentKey);

{
long nLength = elemIndex;
if (jsonElem->children->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(jsonElem->children->data, (nLength+50)*sizeof(struct jsonElement*));
jsonElem->children->data = newPtr;
}
jsonElem->children->data[elemIndex] =  elem;
jsonElem->children->length = nLength+1;
} else {
jsonElem->children->data[elemIndex] =  elem;
}
};
}
}
return jsonElem;
};
char * jsonEscapeStr(char * s){
array(char)* a =  strAsArr(s);
array(char)* r = memoryAlloc(sizeof(array(char)));

r->length = 0;
r->elemSize = sizeof(char);
long int i =  0;
while ((i<len(a))) {

                    if (a->length <= i) {
                        printf("array (/opt/bah/json.bah:399): a[%d] with length %d\n", i, a->length);
                        exit(1);
                    };
                    char c =  a->data[i];
if ((c==(char)34)) {

{
long nLength = len(r);
if (r->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(r->data, (nLength+50)*sizeof(char));
r->data = newPtr;
}
r->data[len(r)] =  (char)92;
r->length = nLength+1;
} else {
r->data[len(r)] =  (char)92;
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
r->data[len(r)] =  (char)92;
r->length = nLength+1;
} else {
r->data[len(r)] =  (char)92;
}
};

{
long nLength = len(r);
if (r->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(r->data, (nLength+50)*sizeof(char));
r->data = newPtr;
}
r->data[len(r)] =  110;
r->length = nLength+1;
} else {
r->data[len(r)] =  110;
}
};
i =  i + 1;
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
r->data[len(r)] =  (char)92;
r->length = nLength+1;
} else {
r->data[len(r)] =  (char)92;
}
};

{
long nLength = len(r);
if (r->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(r->data, (nLength+50)*sizeof(char));
r->data = newPtr;
}
r->data[len(r)] =  114;
r->length = nLength+1;
} else {
r->data[len(r)] =  114;
}
};
i =  i + 1;
continue;
}

{
long nLength = len(r);
if (r->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(r->data, (nLength+50)*sizeof(char));
r->data = newPtr;
}
r->data[len(r)] =  c;
r->length = nLength+1;
} else {
r->data[len(r)] =  c;
}
};
i =  i + 1;
};
return arrToStr(r);
};
char * toJson__inner(struct reflectElement e,char isMember,long int tabs){
void ** v =  e.value;
if (((e.value==null)||(*v==null))) {
if (((strcmp(e.type, "int") == 0)||(strcmp(e.type, "float") == 0))) {
return "0";
}
if ((strcmp(e.type, "bool") == 0)) {
return "false";
}
if ((((strcmp(e.type, "ptr") == 0)||(strcmp(e.type, "cpstring") == 0))||(strCount(e.type,"*")!=0))) {
return "null";
}
}
if ((e.isStruct==true)) {
tabs =  tabs + 1;
char * tabsStr =  "";
long int i =  0;
while ((i<tabs)) {
char * ____BAH_COMPILER_VAR_76 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tabsStr);
long int strLen_1 = strlen("\t");
;                            
                    ____BAH_COMPILER_VAR_76 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_76+currStrOff, tabsStr, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_76+currStrOff, "\t", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_76[currStrOff] = 0;
                }
                tabsStr =  ____BAH_COMPILER_VAR_76;
i =  i + 1;
};
char * s =  "{\n";
i =  0;
while ((i<len(e.structLayout))) {

                    if (e.structLayout->length <= i) {
                        printf("array (/opt/bah/json.bah:444): e.structLayout[%d] with length %d\n", i, e.structLayout->length);
                        exit(1);
                    };
                    struct reflectElement m =  e.structLayout->data[i];
i =  i + 1;
if ((i<len(e.structLayout))) {
char * ____BAH_COMPILER_VAR_77 =toJson__inner(m,true,tabs);char * ____BAH_COMPILER_VAR_78 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s);
long int strLen_1 = strlen(tabsStr);
long int strLen_2 = strlen("\"");
long int strLen_3 = strlen(m.name);
long int strLen_4 = strlen("\": ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_77);
long int strLen_6 = strlen(",\n");
;                            
                    ____BAH_COMPILER_VAR_78 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                    
                    memcpy(____BAH_COMPILER_VAR_78+currStrOff, s, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_78+currStrOff, tabsStr, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_78+currStrOff, "\"", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_78+currStrOff, m.name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_78+currStrOff, "\": ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_78+currStrOff, ____BAH_COMPILER_VAR_77, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_78+currStrOff, ",\n", strLen_6);
                    currStrOff += strLen_6;
                    
                    ____BAH_COMPILER_VAR_78[currStrOff] = 0;
                }
                s =  ____BAH_COMPILER_VAR_78;
}
else {
char * ____BAH_COMPILER_VAR_79 =toJson__inner(m,true,tabs);char * ____BAH_COMPILER_VAR_80 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s);
long int strLen_1 = strlen(tabsStr);
long int strLen_2 = strlen("\"");
long int strLen_3 = strlen(m.name);
long int strLen_4 = strlen("\": ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_79);
long int strLen_6 = strlen("\n");
;                            
                    ____BAH_COMPILER_VAR_80 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                    
                    memcpy(____BAH_COMPILER_VAR_80+currStrOff, s, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_80+currStrOff, tabsStr, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_80+currStrOff, "\"", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_80+currStrOff, m.name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_80+currStrOff, "\": ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_80+currStrOff, ____BAH_COMPILER_VAR_79, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_80+currStrOff, "\n", strLen_6);
                    currStrOff += strLen_6;
                    
                    ____BAH_COMPILER_VAR_80[currStrOff] = 0;
                }
                s =  ____BAH_COMPILER_VAR_80;
}
};
tabs =  tabs - 1;
tabsStr =  "";
i =  0;
while ((i<tabs)) {
char * ____BAH_COMPILER_VAR_81 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tabsStr);
long int strLen_1 = strlen("\t");
;                            
                    ____BAH_COMPILER_VAR_81 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_81+currStrOff, tabsStr, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_81+currStrOff, "\t", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_81[currStrOff] = 0;
                }
                tabsStr =  ____BAH_COMPILER_VAR_81;
i =  i + 1;
};
char * ____BAH_COMPILER_VAR_82 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s);
long int strLen_1 = strlen(tabsStr);
long int strLen_2 = strlen("}");
;                            
                    ____BAH_COMPILER_VAR_82 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_82+currStrOff, s, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_82+currStrOff, tabsStr, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_82+currStrOff, "}", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_82[currStrOff] = 0;
                }
                s =  ____BAH_COMPILER_VAR_82;
return s;
}
else if ((strcmp(e.type, "int") == 0)) {
long int* ip =  e.value;
return intToStr(*ip);
}
else if ((strcmp(e.type, "float") == 0)) {
double* fp =  e.value;
return floatToStr(*fp);
}
else if ((strcmp(e.type, "cpstring") == 0)) {
if ((isMember==false)) {
void * s =  e.value;
char * ____BAH_COMPILER_VAR_83 =jsonEscapeStr(s);char * ____BAH_COMPILER_VAR_84 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\"");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_83);
long int strLen_2 = strlen("\"");
;                            
                    ____BAH_COMPILER_VAR_84 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_84+currStrOff, "\"", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_84+currStrOff, ____BAH_COMPILER_VAR_83, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_84+currStrOff, "\"", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_84[currStrOff] = 0;
                }
                return ____BAH_COMPILER_VAR_84;
}
else {
char ** sp =  e.value;
char * s =  *sp;
char * ____BAH_COMPILER_VAR_85 =jsonEscapeStr(s);char * ____BAH_COMPILER_VAR_86 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\"");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_85);
long int strLen_2 = strlen("\"");
;                            
                    ____BAH_COMPILER_VAR_86 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_86+currStrOff, "\"", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_86+currStrOff, ____BAH_COMPILER_VAR_85, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_86+currStrOff, "\"", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_86[currStrOff] = 0;
                }
                return ____BAH_COMPILER_VAR_86;
}
}
else if ((strcmp(e.type, "bool") == 0)) {
char* bp =  e.value;
if ((*bp==true)) {
return "true";
}
return "false";
}
else if ((e.isArray==true)) {
char * s =  "[";
struct reflectElement* ae =  e.arrayElem;
if ((strcmp(ae->type, "int") == 0)) {
array(long int)* arr = memoryAlloc(sizeof(array(long int)));

arr->length = 0;
arr->elemSize = sizeof(long int);
void ** arrPtr =  e.value;
arr =  *arrPtr;
long int i =  0;
while ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_87 =intToStr(arr->data[i]);char * ____BAH_COMPILER_VAR_88 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_87);
;                            
                    ____BAH_COMPILER_VAR_88 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_88+currStrOff, s, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_88+currStrOff, ____BAH_COMPILER_VAR_87, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_88[currStrOff] = 0;
                }
                s =  ____BAH_COMPILER_VAR_88;
i =  i + 1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_89 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s);
long int strLen_1 = strlen(",");
;                            
                    ____BAH_COMPILER_VAR_89 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_89+currStrOff, s, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_89+currStrOff, ",", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_89[currStrOff] = 0;
                }
                s =  ____BAH_COMPILER_VAR_89;
}
};
}
else if ((strcmp(ae->type, "float") == 0)) {
array(double)* arr = memoryAlloc(sizeof(array(double)));

arr->length = 0;
arr->elemSize = sizeof(double);
void ** arrPtr =  e.value;
arr =  *arrPtr;
long int i =  0;
while ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_90 =floatToStr(arr->data[i]);char * ____BAH_COMPILER_VAR_91 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_90);
;                            
                    ____BAH_COMPILER_VAR_91 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_91+currStrOff, s, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_91+currStrOff, ____BAH_COMPILER_VAR_90, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_91[currStrOff] = 0;
                }
                s =  ____BAH_COMPILER_VAR_91;
i =  i + 1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_92 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s);
long int strLen_1 = strlen(",");
;                            
                    ____BAH_COMPILER_VAR_92 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_92+currStrOff, s, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_92+currStrOff, ",", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_92[currStrOff] = 0;
                }
                s =  ____BAH_COMPILER_VAR_92;
}
};
}
else if ((strcmp(ae->type, "cpstring") == 0)) {
array(char *)* arr = memoryAlloc(sizeof(array(char *)));

arr->length = 0;
arr->elemSize = sizeof(char *);
void ** arrPtr =  e.value;
arr =  *arrPtr;
char * ____BAH_COMPILER_VAR_93 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s);
long int strLen_1 = strlen("\n");
;                            
                    ____BAH_COMPILER_VAR_93 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_93+currStrOff, s, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_93+currStrOff, "\n", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_93[currStrOff] = 0;
                }
                s =  ____BAH_COMPILER_VAR_93;
long int i =  0;
while ((i<len(arr))) {

                    if (arr->length <= i) {
                        printf("array (/opt/bah/json.bah:512): arr[%d] with length %d\n", i, arr->length);
                        exit(1);
                    };
                    char * ____BAH_COMPILER_VAR_94 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s);
long int strLen_1 = strlen(arr->data[i]);
;                            
                    ____BAH_COMPILER_VAR_94 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_94+currStrOff, s, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_94+currStrOff, arr->data[i], strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_94[currStrOff] = 0;
                }
                s =  ____BAH_COMPILER_VAR_94;
i =  i + 1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_95 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s);
long int strLen_1 = strlen(",\n");
;                            
                    ____BAH_COMPILER_VAR_95 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_95+currStrOff, s, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_95+currStrOff, ",\n", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_95[currStrOff] = 0;
                }
                s =  ____BAH_COMPILER_VAR_95;
}
else {
char * ____BAH_COMPILER_VAR_96 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s);
long int strLen_1 = strlen("\n");
;                            
                    ____BAH_COMPILER_VAR_96 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_96+currStrOff, s, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_96+currStrOff, "\n", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_96[currStrOff] = 0;
                }
                s =  ____BAH_COMPILER_VAR_96;
}
};
}
else if ((ae->isStruct==true)) {
array(void *)* arr = memoryAlloc(sizeof(array(void *)));

arr->length = 0;
arr->elemSize = sizeof(void *);
if ((isMember==false)) {
arr =  e.value;
}
else {
void ** ev =  e.value;
arr =  *ev;
}
long int i =  0;
while ((i<len(arr))) {

                    if (arr->length <= i) {
                        printf("array (/opt/bah/json.bah:532): arr[%d] with length %d\n", i, arr->length);
                        exit(1);
                    };
                    void * arrElem =  arr->data[i];
ae->value =  arrElem;
long int j =  0;
while ((j<len(ae->structLayout))) {

                    if (ae->structLayout->length <= j) {
                        printf("array (/opt/bah/json.bah:535): ae->structLayout[%d] with length %d\n", j, ae->structLayout->length);
                        exit(1);
                    };
                    struct reflectElement m =  ae->structLayout->data[j];
m.value =  m.calculateOffset((struct reflectElement*)&m,ae->value);

{
long nLength = j;
if (ae->structLayout->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(ae->structLayout->data, (nLength+50)*sizeof(struct reflectElement));
ae->structLayout->data = newPtr;
}
ae->structLayout->data[j] =  m;
ae->structLayout->length = nLength+1;
} else {
ae->structLayout->data[j] =  m;
}
};
j =  j + 1;
};
char * ____BAH_COMPILER_VAR_97 =toJson__inner(*ae,false,tabs);char * ____BAH_COMPILER_VAR_98 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_97);
;                            
                    ____BAH_COMPILER_VAR_98 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_98+currStrOff, s, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_98+currStrOff, ____BAH_COMPILER_VAR_97, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_98[currStrOff] = 0;
                }
                s =  ____BAH_COMPILER_VAR_98;
i =  i + 1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_99 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s);
long int strLen_1 = strlen(",\n");
;                            
                    ____BAH_COMPILER_VAR_99 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_99+currStrOff, s, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_99+currStrOff, ",\n", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_99[currStrOff] = 0;
                }
                s =  ____BAH_COMPILER_VAR_99;
}
else {
char * ____BAH_COMPILER_VAR_100 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s);
long int strLen_1 = strlen("\n");
;                            
                    ____BAH_COMPILER_VAR_100 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_100+currStrOff, s, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_100+currStrOff, "\n", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_100[currStrOff] = 0;
                }
                s =  ____BAH_COMPILER_VAR_100;
}
};
}
char * ____BAH_COMPILER_VAR_101 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s);
long int strLen_1 = strlen("]");
;                            
                    ____BAH_COMPILER_VAR_101 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_101+currStrOff, s, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_101+currStrOff, "]", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_101[currStrOff] = 0;
                }
                s =  ____BAH_COMPILER_VAR_101;
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
char * ____BAH_COMPILER_VAR_102 = name;
struct reflectElement ____BAH_COMPILER_VAR_103 = __reflect(____BAH_COMPILER_VAR_102, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, 0);
char * ____BAH_COMPILER_VAR_104 =toJson(____BAH_COMPILER_VAR_103);char * ____BAH_COMPILER_VAR_105 =intToStr(line);char * ____BAH_COMPILER_VAR_106 =toJson(e);char * ____BAH_COMPILER_VAR_107 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n    {\n        \"name\": ");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_104);
long int strLen_2 = strlen(",\n        \"path\": \"");
long int strLen_3 = strlen(compilerState.currentFile);
long int strLen_4 = strlen(":");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_105);
long int strLen_6 = strlen("\",\n        \"element\": ");
long int strLen_7 = strlen(____BAH_COMPILER_VAR_106);
long int strLen_8 = strlen("\n    },\n    ");
;                            
                    ____BAH_COMPILER_VAR_107 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                    
                    memcpy(____BAH_COMPILER_VAR_107+currStrOff, "\n    {\n        \"name\": ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_107+currStrOff, ____BAH_COMPILER_VAR_104, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_107+currStrOff, ",\n        \"path\": \"", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_107+currStrOff, compilerState.currentFile, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_107+currStrOff, ":", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_107+currStrOff, ____BAH_COMPILER_VAR_105, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_107+currStrOff, "\",\n        \"element\": ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_107+currStrOff, ____BAH_COMPILER_VAR_106, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_107+currStrOff, "\n    },\n    ", strLen_8);
                    currStrOff += strLen_8;
                    
                    ____BAH_COMPILER_VAR_107[currStrOff] = 0;
                }
                println(____BAH_COMPILER_VAR_107);
};
void debugError(char * name,long int line,long int from,long int to,struct reflectElement e){
if ((debug==false)) {
return;
}
char * ____BAH_COMPILER_VAR_108 = name;
struct reflectElement ____BAH_COMPILER_VAR_109 = __reflect(____BAH_COMPILER_VAR_108, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, 0);
char * ____BAH_COMPILER_VAR_110 =toJson(____BAH_COMPILER_VAR_109);char * ____BAH_COMPILER_VAR_111 =intToStr(line);char * ____BAH_COMPILER_VAR_112 =intToStr(from);char * ____BAH_COMPILER_VAR_113 =intToStr(to);char * ____BAH_COMPILER_VAR_114 =toJson(e);char * ____BAH_COMPILER_VAR_115 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n    {\n        \"name\": ");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_110);
long int strLen_2 = strlen(",\n        \"path\": \"");
long int strLen_3 = strlen(compilerState.currentFile);
long int strLen_4 = strlen(":");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_111);
long int strLen_6 = strlen("\",\n        \"range\": [\n            ");
long int strLen_7 = strlen(____BAH_COMPILER_VAR_112);
long int strLen_8 = strlen(",\n            ");
long int strLen_9 = strlen(____BAH_COMPILER_VAR_113);
long int strLen_10 = strlen("\n        ],\n        \"element\": ");
long int strLen_11 = strlen(____BAH_COMPILER_VAR_114);
long int strLen_12 = strlen("\n    },\n    ");
;                            
                    ____BAH_COMPILER_VAR_115 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12);
                    
                    memcpy(____BAH_COMPILER_VAR_115+currStrOff, "\n    {\n        \"name\": ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_115+currStrOff, ____BAH_COMPILER_VAR_110, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_115+currStrOff, ",\n        \"path\": \"", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_115+currStrOff, compilerState.currentFile, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_115+currStrOff, ":", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_115+currStrOff, ____BAH_COMPILER_VAR_111, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_115+currStrOff, "\",\n        \"range\": [\n            ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_115+currStrOff, ____BAH_COMPILER_VAR_112, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_115+currStrOff, ",\n            ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_115+currStrOff, ____BAH_COMPILER_VAR_113, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_115+currStrOff, "\n        ],\n        \"element\": ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_115+currStrOff, ____BAH_COMPILER_VAR_114, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_115+currStrOff, "\n    },\n    ", strLen_12);
                    currStrOff += strLen_12;
                    
                    ____BAH_COMPILER_VAR_115[currStrOff] = 0;
                }
                println(____BAH_COMPILER_VAR_115);
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
long int i =  0;
while ((i<len(elems->vars))) {

                    if (elems->vars->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/logger.bah:83): elems->vars[%d] with length %d\n", i, elems->vars->length);
                        exit(1);
                    };
                    struct variable* v =  elems->vars->data[i];
if (((v->outterScope==false)&&(v->isConst==false))) {
struct variable* ____BAH_COMPILER_VAR_116 = v;
char ** ____BAH_COMPILER_VAR_118 = (char **)((char*)(____BAH_COMPILER_VAR_116) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_119 = __reflect(____BAH_COMPILER_VAR_118, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_120 = (char **)((char*)(____BAH_COMPILER_VAR_116) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_121 = __reflect(____BAH_COMPILER_VAR_120, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_122 = (char*)((char*)(____BAH_COMPILER_VAR_116) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_123 = __reflect(____BAH_COMPILER_VAR_122, sizeof(char), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_124 = (char **)((char*)(____BAH_COMPILER_VAR_116) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_125 = __reflect(____BAH_COMPILER_VAR_124, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_126 = (char*)((char*)(____BAH_COMPILER_VAR_116) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_127 = __reflect(____BAH_COMPILER_VAR_126, sizeof(char), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_128 = (char **)((char*)(____BAH_COMPILER_VAR_116) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_129 = __reflect(____BAH_COMPILER_VAR_128, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
char* ____BAH_COMPILER_VAR_130 = (char*)((char*)(____BAH_COMPILER_VAR_116) + offsetof(struct variable, outterScope));
struct reflectElement ____BAH_COMPILER_VAR_131 = __reflect(____BAH_COMPILER_VAR_130, sizeof(char), "bool", "outterScope", 0, 0, 0, 0, offsetof(struct variable, outterScope));
char* ____BAH_COMPILER_VAR_132 = (char*)((char*)(____BAH_COMPILER_VAR_116) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_133 = __reflect(____BAH_COMPILER_VAR_132, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_117 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_117->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_117->length = 8;
        ____BAH_COMPILER_VAR_117->data = memoryAlloc(____BAH_COMPILER_VAR_117->length * ____BAH_COMPILER_VAR_117->elemSize);
        ____BAH_COMPILER_VAR_117->data[0] = ____BAH_COMPILER_VAR_119;
____BAH_COMPILER_VAR_117->data[1] = ____BAH_COMPILER_VAR_121;
____BAH_COMPILER_VAR_117->data[2] = ____BAH_COMPILER_VAR_123;
____BAH_COMPILER_VAR_117->data[3] = ____BAH_COMPILER_VAR_125;
____BAH_COMPILER_VAR_117->data[4] = ____BAH_COMPILER_VAR_127;
____BAH_COMPILER_VAR_117->data[5] = ____BAH_COMPILER_VAR_129;
____BAH_COMPILER_VAR_117->data[6] = ____BAH_COMPILER_VAR_131;
____BAH_COMPILER_VAR_117->data[7] = ____BAH_COMPILER_VAR_133;
struct reflectElement ____BAH_COMPILER_VAR_134 = __reflect(____BAH_COMPILER_VAR_116, sizeof(struct variable), "variable*", "v", 0, 0, 1, ____BAH_COMPILER_VAR_117, 0);
debugPrint("var_end",line,____BAH_COMPILER_VAR_134);
}
i =  i + 1;
};
};
void throwErr(void * tp,char * format){
char * str =  "";
char * info =  "";
long int pos =  0;
if ((tp!=null)) {
struct fileMap ____BAH_COMPILER_VAR_135 = {};
____BAH_COMPILER_VAR_135.handle = -1;
____BAH_COMPILER_VAR_135.p= null;
____BAH_COMPILER_VAR_135.open = fileMap__open;
____BAH_COMPILER_VAR_135.isValid = fileMap__isValid;
____BAH_COMPILER_VAR_135.close = fileMap__close;
struct fileMap fm =  ____BAH_COMPILER_VAR_135;
char * fileSrcStr =  fm.open((struct fileMap*)&fm,compilerState.currentFile);
struct Tok* t =  tp;
struct string ffmt =  string(format);
if ((strlen(t->ogCont)==0)) {
t->ogCont =  t->cont;
}
char * ____BAH_COMPILER_VAR_136 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("'");
long int strLen_1 = strlen(t->ogCont);
long int strLen_2 = strlen("'");
;                            
                    ____BAH_COMPILER_VAR_136 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_136+currStrOff, "'", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_136+currStrOff, t->ogCont, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_136+currStrOff, "'", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_136[currStrOff] = 0;
                }
                ffmt.replace((struct string*)&ffmt,"{TOKEN}",____BAH_COMPILER_VAR_136);
format =  ffmt.str((struct string*)&ffmt);
array(char)* line = memoryAlloc(sizeof(array(char)));

line->length = 0;
line->elemSize = sizeof(char);
long int beg =  t->pos;
while ((beg>0)) {
char c =  cpstringCharAt(fileSrcStr,beg);
if ((c==(char)10)) {
beg =  beg + 1;
break;
}
beg =  beg - 1;
};
pos =  t->pos - beg + 1;
long int i =  beg;
while ((i<fm.size)) {
char c =  cpstringCharAt(fileSrcStr,i);
if ((c==(char)10)) {
break;
}
if ((i==t->pos)) {
char * ____BAH_COMPILER_VAR_137 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\e[1;31m");
long int strLen_1 = strlen(t->ogCont);
long int strLen_2 = strlen("\e[1;37m");
;                            
                    ____BAH_COMPILER_VAR_137 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_137+currStrOff, "\e[1;31m", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_137+currStrOff, t->ogCont, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_137+currStrOff, "\e[1;37m", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_137[currStrOff] = 0;
                }
                array(char)* errTk =  strToArr(____BAH_COMPILER_VAR_137);
long int ii =  0;
while ((ii<len(errTk))) {

                    if (errTk->length <= ii) {
                        printf("array (/home/alois/Documents/bah-bah/src/errors.bah:44): errTk[%d] with length %d\n", ii, errTk->length);
                        exit(1);
                    };
                    
{
long nLength = len(line);
if (line->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(line->data, (nLength+50)*sizeof(char));
line->data = newPtr;
}
line->data[len(line)] =  errTk->data[ii];
line->length = nLength+1;
} else {
line->data[len(line)] =  errTk->data[ii];
}
};
ii =  ii + 1;
};
i =  i + strlen(t->ogCont);
continue;
}

{
long nLength = len(line);
if (line->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(line->data, (nLength+50)*sizeof(char));
line->data = newPtr;
}
line->data[len(line)] =  c;
line->length = nLength+1;
} else {
line->data[len(line)] =  c;
}
};
i =  i + 1;
};
fm.close((struct fileMap*)&fm);
str =  arrToStr(line);
char * ____BAH_COMPILER_VAR_138 =intToStr(t->line);char * ____BAH_COMPILER_VAR_139 =intToStr(pos);char * ____BAH_COMPILER_VAR_140 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_138);
long int strLen_1 = strlen(":");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_139);
;                            
                    ____BAH_COMPILER_VAR_140 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_140+currStrOff, ____BAH_COMPILER_VAR_138, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_140+currStrOff, ":", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_140+currStrOff, ____BAH_COMPILER_VAR_139, strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_140[currStrOff] = 0;
                }
                info =  ____BAH_COMPILER_VAR_140;
}
if ((debug==true)) {
struct Tok* t =  tp;
char * ____BAH_COMPILER_VAR_141 = format;
struct reflectElement ____BAH_COMPILER_VAR_142 = __reflect(____BAH_COMPILER_VAR_141, sizeof(char *), "cpstring", "format", 0, 0, 0, 0, 0);
debugError("error",t->line,pos,pos + strlen(t->ogCont),____BAH_COMPILER_VAR_142);
debugExit();
}
else {
char * ____BAH_COMPILER_VAR_143 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\e[1;31m[ERROR]\e[0m ");
long int strLen_1 = strlen(compilerState.currentFile);
long int strLen_2 = strlen(":");
long int strLen_3 = strlen(info);
long int strLen_4 = strlen("\n\e[1;37m\t");
long int strLen_5 = strlen(str);
long int strLen_6 = strlen("\e[0m\n");
long int strLen_7 = strlen(format);
;                            
                    ____BAH_COMPILER_VAR_143 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7);
                    
                    memcpy(____BAH_COMPILER_VAR_143+currStrOff, "\e[1;31m[ERROR]\e[0m ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_143+currStrOff, compilerState.currentFile, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_143+currStrOff, ":", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_143+currStrOff, info, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_143+currStrOff, "\n\e[1;37m\t", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_143+currStrOff, str, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_143+currStrOff, "\e[0m\n", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_143+currStrOff, format, strLen_7);
                    currStrOff += strLen_7;
                    
                    ____BAH_COMPILER_VAR_143[currStrOff] = 0;
                }
                println(____BAH_COMPILER_VAR_143);
}
exit(1);
};
void throwWarning(char * s){
char * ____BAH_COMPILER_VAR_144 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\e[1;33m[WARNING]\e[0m ");
long int strLen_1 = strlen(compilerState.currentFile);
long int strLen_2 = strlen("\n\e[1;37m\t");
long int strLen_3 = strlen(s);
long int strLen_4 = strlen("\e[0m");
;                            
                    ____BAH_COMPILER_VAR_144 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_144+currStrOff, "\e[1;33m[WARNING]\e[0m ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_144+currStrOff, compilerState.currentFile, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_144+currStrOff, "\n\e[1;37m\t", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_144+currStrOff, s, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_144+currStrOff, "\e[0m", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_144[currStrOff] = 0;
                }
                println(____BAH_COMPILER_VAR_144);
};
#include <stdlib.h>
char * absPath(char * path){
char * buff =  memoryAlloc(4096);
char * p =  _fullpath(buff,path,4095);
if (((void *)p!=null)) {
array(char)* arr =  strAsArr(p);
long int i =  0;
for (; (i<len(arr)); i =  i+1) {

                    if (arr->length <= i) {
                        printf("array (/opt/bah/path.bah:23): arr[%d] with length %d\n", i, arr->length);
                        exit(1);
                    };
                    char c =  arr->data[i];
if ((c==(char)92)) {

{
long nLength = i;
if (arr->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(arr->data, (nLength+50)*sizeof(char));
arr->data = newPtr;
}
arr->data[i] =  47;
arr->length = nLength+1;
} else {
arr->data[i] =  47;
}
};
}
};
}
return p;
};
char * getCurrentPath(){
char * cwd =  memoryAlloc(4096);
getcwd(cwd,4096);
return cwd;
};
//optimized out: isInside
void setCurrentPath(char * s){
chdir(s);
};
char isGlobal(){
return (currentFn==null);
};
struct variable* searchVar(char * name,struct Elems* elems){
char * ogName =  name;
struct string n =  string(name);
n.replace((struct string*)&n,"&","");
n.replace((struct string*)&n,"*","");
if (n.hasSuffix((struct string*)&n,"]")) {
long int i =  n.length;
while ((i>0)) {
char c =  n.charAt((struct string*)&n,i);
if ((c==91)) {
break;
}
i =  i - 1;
};
long int tamm =  n.length - i;
n.trimRight((struct string*)&n,tamm);
char isArr =  (n.hasSuffix((struct string*)&n,"->data")==1);
if ((isArr==true)) {
n.trimRight((struct string*)&n,6);
}
name =  n.str((struct string*)&n);
struct variable* v =  searchVar(name,elems);
struct string vt =  string(v->type);
if ((isArr==true)) {
vt.trimLeft((struct string*)&vt,2);
}
else {
vt.set((struct string*)&vt,"char");
}
char * vtstr =  vt.str((struct string*)&vt);
struct variable* ____BAH_COMPILER_VAR_145 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_145->name = "";
____BAH_COMPILER_VAR_145->type = "";
____BAH_COMPILER_VAR_145->isConst = false;
____BAH_COMPILER_VAR_145->constVal = "";
____BAH_COMPILER_VAR_145->isArray = false;
____BAH_COMPILER_VAR_145->from = "";
____BAH_COMPILER_VAR_145->outterScope = false;
____BAH_COMPILER_VAR_145->isGlobal = false;
struct variable* nv =  ____BAH_COMPILER_VAR_145;
nv->type =  vtstr;
nv->name =  ogName;
nv->isArray =  isArr;
return nv;
}
name =  n.content;
if ((hasStructSep(n)&&(n.count((struct string*)&n,")")==0))) {
struct string rn =  splitStructSepBefore(n);
name =  rn.content;
n.trimLeft((struct string*)&n,rn.length);
if (n.hasPrefix((struct string*)&n,".")) {
n.trimLeft((struct string*)&n,1);
}
else {
n.trimLeft((struct string*)&n,2);
}
char * membs =  n.content;
struct variable* v =  searchVar(name,elems);
if ((v==null)) {
return null;
}
struct cStruct* s =  searchStruct(v->type,elems);
if ((s==null)) {
return null;
}
struct structMemb* memb =  searchStructMemb(membs,s,elems);
if ((memb==null)) {
return null;
}
struct variable* ____BAH_COMPILER_VAR_146 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_146->name = "";
____BAH_COMPILER_VAR_146->type = "";
____BAH_COMPILER_VAR_146->isConst = false;
____BAH_COMPILER_VAR_146->constVal = "";
____BAH_COMPILER_VAR_146->isArray = false;
____BAH_COMPILER_VAR_146->from = "";
____BAH_COMPILER_VAR_146->outterScope = false;
____BAH_COMPILER_VAR_146->isGlobal = false;
struct variable* nv =  ____BAH_COMPILER_VAR_146;
nv->from =  memb->from;
nv->name =  memb->name;
nv->type =  memb->type;
nv->name =  ogName;
char * r =  nv->type;
struct string tcc =  string(ogName);
if (tcc.count((struct string*)&tcc,"&")) {
char * ____BAH_COMPILER_VAR_147 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(r);
long int strLen_1 = strlen("*");
;                            
                    ____BAH_COMPILER_VAR_147 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_147+currStrOff, r, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_147+currStrOff, "*", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_147[currStrOff] = 0;
                }
                r =  ____BAH_COMPILER_VAR_147;
}
long int nbUnaries =  tcc.count((struct string*)&tcc,"*");
if ((nbUnaries>0)) {
struct string ct =  string(r);
long int pointerLevel =  ct.count((struct string*)&ct,"*");
if ((pointerLevel<nbUnaries)) {
char * ____BAH_COMPILER_VAR_148 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot use '*' on ");
long int strLen_1 = strlen(nv->name);
long int strLen_2 = strlen(" because it is not pointer.");
;                            
                    ____BAH_COMPILER_VAR_148 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_148+currStrOff, "Cannot use '*' on ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_148+currStrOff, nv->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_148+currStrOff, " because it is not pointer.", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_148[currStrOff] = 0;
                }
                throwErr(null,____BAH_COMPILER_VAR_148);
}
ct.trimRight((struct string*)&ct,nbUnaries);
r =  ct.str((struct string*)&ct);
}
nv->type =  r;
nv->name =  ogName;
return nv;
}
long int i =  len(elems->vars)-1;
for (; (i!=-1); i =  i-1) {

                    if (elems->vars->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/var.bah:104): elems->vars[%d] with length %d\n", i, elems->vars->length);
                        exit(1);
                    };
                    struct variable* v =  elems->vars->data[i];
if ((v==null)) {
char * ____BAH_COMPILER_VAR_149 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\e[1;31m[INTERNAL COMPILER ERROR]\e[0m\n Please report the bug as 'compiler searching '");
long int strLen_1 = strlen(name);
long int strLen_2 = strlen("' resulting in null var'.");
;                            
                    ____BAH_COMPILER_VAR_149 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_149+currStrOff, "\e[1;31m[INTERNAL COMPILER ERROR]\e[0m\n Please report the bug as 'compiler searching '", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_149+currStrOff, name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_149+currStrOff, "' resulting in null var'.", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_149[currStrOff] = 0;
                }
                __BAH_panic(____BAH_COMPILER_VAR_149,"/home/alois/Documents/bah-bah/src/var.bah:106");
}
if ((strcmp(v->name, name) == 0)) {
struct variable* ____BAH_COMPILER_VAR_150 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_150->name = "";
____BAH_COMPILER_VAR_150->type = "";
____BAH_COMPILER_VAR_150->isConst = false;
____BAH_COMPILER_VAR_150->constVal = "";
____BAH_COMPILER_VAR_150->isArray = false;
____BAH_COMPILER_VAR_150->from = "";
____BAH_COMPILER_VAR_150->outterScope = false;
____BAH_COMPILER_VAR_150->isGlobal = false;
struct variable* nv =  ____BAH_COMPILER_VAR_150;
nv->type =  v->type;
nv->name =  v->name;
nv->isConst =  v->isConst;
char * r =  nv->type;
struct string tcc =  string(ogName);
if (tcc.count((struct string*)&tcc,"&")) {
char * ____BAH_COMPILER_VAR_151 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(r);
long int strLen_1 = strlen("*");
;                            
                    ____BAH_COMPILER_VAR_151 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_151+currStrOff, r, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_151+currStrOff, "*", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_151[currStrOff] = 0;
                }
                r =  ____BAH_COMPILER_VAR_151;
}
long int nbUnaries =  tcc.count((struct string*)&tcc,"*");
if ((nbUnaries>0)) {
struct string ct =  string(r);
long int pointerLevel =  ct.count((struct string*)&ct,"*");
if ((pointerLevel<nbUnaries)) {
char * ____BAH_COMPILER_VAR_152 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot use '*' on ");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(" because it is not pointer.");
;                            
                    ____BAH_COMPILER_VAR_152 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_152+currStrOff, "Cannot use '*' on ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_152+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_152+currStrOff, " because it is not pointer.", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_152[currStrOff] = 0;
                }
                throwErr(null,____BAH_COMPILER_VAR_152);
}
ct.trimRight((struct string*)&ct,nbUnaries);
r =  ct.str((struct string*)&ct);
}
nv->type =  r;
nv->name =  ogName;
return nv;
}
};
i =  0;
while ((i<len(elems->fns))) {

                    if (elems->fns->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/var.bah:137): elems->fns[%d] with length %d\n", i, elems->fns->length);
                        exit(1);
                    };
                    struct func* fn =  elems->fns->data[i];
if ((strcmp(fn->name, name) == 0)) {
struct variable* ____BAH_COMPILER_VAR_153 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_153->name = "";
____BAH_COMPILER_VAR_153->type = "";
____BAH_COMPILER_VAR_153->isConst = false;
____BAH_COMPILER_VAR_153->constVal = "";
____BAH_COMPILER_VAR_153->isArray = false;
____BAH_COMPILER_VAR_153->from = "";
____BAH_COMPILER_VAR_153->outterScope = false;
____BAH_COMPILER_VAR_153->isGlobal = false;
struct variable* nv =  ____BAH_COMPILER_VAR_153;
nv->name =  name;
nv->type =  "function(";
long int j =  0;
while ((j<len(fn->args))) {

                    if (fn->args->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/var.bah:143): fn->args[%d] with length %d\n", j, fn->args->length);
                        exit(1);
                    };
                    struct variable* arg =  fn->args->data[j];
char * ____BAH_COMPILER_VAR_154 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(nv->type);
long int strLen_1 = strlen(arg->type);
;                            
                    ____BAH_COMPILER_VAR_154 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_154+currStrOff, nv->type, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_154+currStrOff, arg->type, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_154[currStrOff] = 0;
                }
                nv->type =  ____BAH_COMPILER_VAR_154;
j =  j + 1;
if ((j<len(fn->args))) {
char * ____BAH_COMPILER_VAR_155 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(nv->type);
long int strLen_1 = strlen(",");
;                            
                    ____BAH_COMPILER_VAR_155 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_155+currStrOff, nv->type, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_155+currStrOff, ",", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_155[currStrOff] = 0;
                }
                nv->type =  ____BAH_COMPILER_VAR_155;
}
};
fn->used =  true;
char * ____BAH_COMPILER_VAR_156 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(nv->type);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen(fn->returns->type);
;                            
                    ____BAH_COMPILER_VAR_156 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_156+currStrOff, nv->type, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_156+currStrOff, ")", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_156+currStrOff, fn->returns->type, strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_156[currStrOff] = 0;
                }
                nv->type =  ____BAH_COMPILER_VAR_156;
return nv;
}
i =  i + 1;
};
return null;
};
char * setCType(struct variable* v,struct Elems* elems){
struct string tp =  getCType(v->type,elems);
char * t =  tp.str((struct string*)&tp);
char * ____BAH_COMPILER_VAR_157 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(t);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(v->name);
;                            
                    ____BAH_COMPILER_VAR_157 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_157+currStrOff, t, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_157+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_157+currStrOff, v->name, strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_157[currStrOff] = 0;
                }
                t =  ____BAH_COMPILER_VAR_157;
return t;
};
char * getTypeFromToken(struct Tok* t,char strict,struct Elems* elems){
if ((strlen(t->bahType)>0)) {
char * r =  t->bahType;
return r;
}
if ((t->type==TOKEN_TYPE_VAR)) {
struct variable* v =  searchVar(t->cont,elems);
if ((v==null)) {
if ((strict==true)) {
throwErr(t,"Unknown var {TOKEN}.");
}
else {
return "";
}
}
if ((strict==true)) {
if ((strlen(v->type)==0)) {
throwErr(t,"Cannot use {TOKEN} because it does not have any type.");
}
}
char * r =  v->type;
return r;
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
struct func* ____BAH_COMPILER_VAR_158 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_158->name = "";
____BAH_COMPILER_VAR_158->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_158->args->length = 0;
            ____BAH_COMPILER_VAR_158->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_158->returns= null;
____BAH_COMPILER_VAR_158->isBinding = false;
____BAH_COMPILER_VAR_158->from = "";
____BAH_COMPILER_VAR_158->file = "";
____BAH_COMPILER_VAR_158->line = 1;
____BAH_COMPILER_VAR_158->used = false;
____BAH_COMPILER_VAR_158->code = null;
struct func* nf =  ____BAH_COMPILER_VAR_158;
cvt.trimLeft((struct string*)&cvt,9);
array(char)* memory = memoryAlloc(sizeof(array(char)));

memory->length = 0;
memory->elemSize = sizeof(char);
long int j =  0;
while ((j<cvt.length)) {
char c =  cvt.charAt((struct string*)&cvt,j);
if ((c==41)) {
break;
}
struct variable* ____BAH_COMPILER_VAR_159 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_159->name = "";
____BAH_COMPILER_VAR_159->type = "";
____BAH_COMPILER_VAR_159->isConst = false;
____BAH_COMPILER_VAR_159->constVal = "";
____BAH_COMPILER_VAR_159->isArray = false;
____BAH_COMPILER_VAR_159->from = "";
____BAH_COMPILER_VAR_159->outterScope = false;
____BAH_COMPILER_VAR_159->isGlobal = false;
struct variable* arg =  ____BAH_COMPILER_VAR_159;
char * ____BAH_COMPILER_VAR_160 =intToStr(len(nf->args));char * ____BAH_COMPILER_VAR_161 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("arg_");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_160);
;                            
                    ____BAH_COMPILER_VAR_161 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_161+currStrOff, "arg_", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_161+currStrOff, ____BAH_COMPILER_VAR_160, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_161[currStrOff] = 0;
                }
                arg->name =  ____BAH_COMPILER_VAR_161;
while ((j<cvt.length)) {
c =  cvt.charAt((struct string*)&cvt,j);
if (((c==44)||(c==41))) {
break;
}

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[len(memory)] =  c;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  c;
}
};
j =  j + 1;
};
arg->type =  arrToStr(memory);
clear(memory);

{
long nLength = len(nf->args);
if (nf->args->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nf->args->data, (nLength+50)*sizeof(struct variable*));
nf->args->data = newPtr;
}
nf->args->data[len(nf->args)] =  arg;
nf->args->length = nLength+1;
} else {
nf->args->data[len(nf->args)] =  arg;
}
};
if ((c==41)) {
break;
}
j =  j + 1;
};
j =  j + 1;
while ((j<cvt.length)) {
char c =  cvt.charAt((struct string*)&cvt,j);

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[len(memory)] =  c;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  c;
}
};
j =  j + 1;
};
struct variable* ____BAH_COMPILER_VAR_162 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_162->name = "";
____BAH_COMPILER_VAR_162->type = "";
____BAH_COMPILER_VAR_162->isConst = false;
____BAH_COMPILER_VAR_162->constVal = "";
____BAH_COMPILER_VAR_162->isArray = false;
____BAH_COMPILER_VAR_162->from = "";
____BAH_COMPILER_VAR_162->outterScope = false;
____BAH_COMPILER_VAR_162->isGlobal = false;
nf->returns =  ____BAH_COMPILER_VAR_162;
nf->returns->name =  "_return";
nf->returns->type =  arrToStr(memory);
return nf;
};
struct func* searchFunc(char * name,struct Elems* elems,char inclCurr){
char * ogName =  name;
if ((strcmp(name, "noCheck") == 0)) {
struct func* ____BAH_COMPILER_VAR_163 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_163->name = "";
____BAH_COMPILER_VAR_163->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_163->args->length = 0;
            ____BAH_COMPILER_VAR_163->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_163->returns= null;
____BAH_COMPILER_VAR_163->isBinding = false;
____BAH_COMPILER_VAR_163->from = "";
____BAH_COMPILER_VAR_163->file = "";
____BAH_COMPILER_VAR_163->line = 1;
____BAH_COMPILER_VAR_163->used = false;
____BAH_COMPILER_VAR_163->code = null;
struct func* fn =  ____BAH_COMPILER_VAR_163;
fn->name =  "noCheck";
return fn;
}
struct string n =  string(name);
if (hasStructSep(n)) {
struct string fnName =  splitStructSepAfter(n);
n.trimRight((struct string*)&n,fnName.length);
char c =  n.charAt((struct string*)&n,n.length-1);
if ((c==46)) {
n.trimRight((struct string*)&n,1);
}
else {
n.trimRight((struct string*)&n,2);
}
name =  n.str((struct string*)&n);
struct variable* v =  searchVar(name,elems);
struct cStruct* s =  searchStruct(v->type,elems);
char * ____BAH_COMPILER_VAR_164 =fnName.str((struct string*)&fnName);struct structMemb* memb =  searchStructMemb(____BAH_COMPILER_VAR_164,s,elems);
name =  fnName.content;
char * ____BAH_COMPILER_VAR_165 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(memb->from);
long int strLen_1 = strlen("__");
long int strLen_2 = strlen(name);
;                            
                    ____BAH_COMPILER_VAR_165 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_165+currStrOff, memb->from, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_165+currStrOff, "__", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_165+currStrOff, name, strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_165[currStrOff] = 0;
                }
                name =  ____BAH_COMPILER_VAR_165;
}
array(struct func*)* fns =  elems->fns;
long int i =  0;
while ((i<len(fns))) {

                    if (fns->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/var.bah:282): fns[%d] with length %d\n", i, fns->length);
                        exit(1);
                    };
                    struct func* fn =  fns->data[i];
if ((fn==null)) {
char * ____BAH_COMPILER_VAR_166 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\e[1;31m[INTERNAL COMPILER ERROR]\e[0m\n Please report the bug as 'compiler searching '");
long int strLen_1 = strlen(name);
long int strLen_2 = strlen("' resulting in null func'.");
;                            
                    ____BAH_COMPILER_VAR_166 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_166+currStrOff, "\e[1;31m[INTERNAL COMPILER ERROR]\e[0m\n Please report the bug as 'compiler searching '", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_166+currStrOff, name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_166+currStrOff, "' resulting in null func'.", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_166[currStrOff] = 0;
                }
                __BAH_panic(____BAH_COMPILER_VAR_166,"/home/alois/Documents/bah-bah/src/var.bah:284");
}
if ((strcmp(fn->name, name) == 0)) {
fn->used =  true;
return fn;
}
i =  i + 1;
};
if ((inclCurr==true)) {
if ((strcmp(currentFn->name, name) == 0)) {
currentFn->used =  true;
return currentFn;
}
}
struct variable* v =  searchVar(ogName,elems);
if ((v==null)) {
return null;
}
struct func* ____BAH_COMPILER_VAR_167 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_167->name = "";
____BAH_COMPILER_VAR_167->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_167->args->length = 0;
            ____BAH_COMPILER_VAR_167->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_167->returns= null;
____BAH_COMPILER_VAR_167->isBinding = false;
____BAH_COMPILER_VAR_167->from = "";
____BAH_COMPILER_VAR_167->file = "";
____BAH_COMPILER_VAR_167->line = 1;
____BAH_COMPILER_VAR_167->used = false;
____BAH_COMPILER_VAR_167->code = null;
struct func* nf =  ____BAH_COMPILER_VAR_167;
nf->name =  ogName;
struct string cvt =  string(v->type);
if ((cvt.hasPrefix((struct string*)&cvt,"function(")==0)) {
return null;
}
struct func* pfn =  parseFnType(cvt);
nf->returns =  pfn->returns;
nf->args =  pfn->args;
return nf;
};
char RCPavailable();
char * declareStructMethods(struct variable* v,struct cStruct* s,struct Elems* elems){
char * code =  "";
array(struct structMemb*)* members =  s->members;
struct string typec =  string(v->type);
char * sep =  ".";
if (typec.count((struct string*)&typec,"*")) {
sep =  "->";
}
long int i =  0;
while ((i<len(members))) {

                    if (members->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/var.bah:327): members[%d] with length %d\n", i, members->length);
                        exit(1);
                    };
                    struct structMemb* m =  members->data[i];
struct string cmpt =  string(m->type);
char declared =  false;
if ((strlen(m->def)>0)) {
char * ____BAH_COMPILER_VAR_168 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(sep);
long int strLen_3 = strlen(m->name);
long int strLen_4 = strlen(" = ");
long int strLen_5 = strlen(m->def);
long int strLen_6 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_168 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                    
                    memcpy(____BAH_COMPILER_VAR_168+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_168+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_168+currStrOff, sep, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_168+currStrOff, m->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_168+currStrOff, " = ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_168+currStrOff, m->def, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_168+currStrOff, ";\n", strLen_6);
                    currStrOff += strLen_6;
                    
                    ____BAH_COMPILER_VAR_168[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_168;
declared =  true;
}
if ((cmpt.hasPrefix((struct string*)&cmpt,"[]")==1)) {
cmpt.trimLeft((struct string*)&cmpt,2);
char * cmptstr =  cmpt.str((struct string*)&cmpt);
struct string elemCType =  getCType(cmptstr,elems);
char * elemCTypeStr =  elemCType.str((struct string*)&elemCType);
char * ____BAH_COMPILER_VAR_169 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(sep);
long int strLen_3 = strlen(m->name);
long int strLen_4 = strlen(" = memoryAlloc(sizeof(array(");
long int strLen_5 = strlen(elemCTypeStr);
long int strLen_6 = strlen(")));\n            ");
long int strLen_7 = strlen(v->name);
long int strLen_8 = strlen(sep);
long int strLen_9 = strlen(m->name);
long int strLen_10 = strlen("->length = 0;\n            ");
long int strLen_11 = strlen(v->name);
long int strLen_12 = strlen(sep);
long int strLen_13 = strlen(m->name);
long int strLen_14 = strlen("->elemSize = sizeof(");
long int strLen_15 = strlen(elemCTypeStr);
long int strLen_16 = strlen(");\n            ");
;                            
                    ____BAH_COMPILER_VAR_169 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14 + strLen_15 + strLen_16);
                    
                    memcpy(____BAH_COMPILER_VAR_169+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_169+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_169+currStrOff, sep, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_169+currStrOff, m->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_169+currStrOff, " = memoryAlloc(sizeof(array(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_169+currStrOff, elemCTypeStr, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_169+currStrOff, ")));\n            ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_169+currStrOff, v->name, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_169+currStrOff, sep, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_169+currStrOff, m->name, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_169+currStrOff, "->length = 0;\n            ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_169+currStrOff, v->name, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_169+currStrOff, sep, strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_169+currStrOff, m->name, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_169+currStrOff, "->elemSize = sizeof(", strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_169+currStrOff, elemCTypeStr, strLen_15);
                    currStrOff += strLen_15;
                    
                    memcpy(____BAH_COMPILER_VAR_169+currStrOff, ");\n            ", strLen_16);
                    currStrOff += strLen_16;
                    
                    ____BAH_COMPILER_VAR_169[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_169;
declared =  true;
}
else if ((cmpt.hasPrefix((struct string*)&cmpt,"map:")==1)) {
cmpt.trimLeft((struct string*)&cmpt,4);
char * ____BAH_COMPILER_VAR_170 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen(sep);
long int strLen_2 = strlen(m->name);
long int strLen_3 = strlen(" = mapWrapper();\n");
;                            
                    ____BAH_COMPILER_VAR_170 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                    
                    memcpy(____BAH_COMPILER_VAR_170+currStrOff, v->name, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_170+currStrOff, sep, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_170+currStrOff, m->name, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_170+currStrOff, " = mapWrapper();\n", strLen_3);
                    currStrOff += strLen_3;
                    
                    ____BAH_COMPILER_VAR_170[currStrOff] = 0;
                }
                char * ____BAH_COMPILER_VAR_171 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_170);
;                            
                    ____BAH_COMPILER_VAR_171 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_171+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_171+currStrOff, ____BAH_COMPILER_VAR_170, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_171[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_171;
declared =  true;
}
else if ((cmpt.hasPrefix((struct string*)&cmpt,"chan:")==1)) {
cmpt.trimLeft((struct string*)&cmpt,5);
char * ____BAH_COMPILER_VAR_172 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen(sep);
long int strLen_2 = strlen(m->name);
long int strLen_3 = strlen(" = channel();\n");
;                            
                    ____BAH_COMPILER_VAR_172 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                    
                    memcpy(____BAH_COMPILER_VAR_172+currStrOff, v->name, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_172+currStrOff, sep, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_172+currStrOff, m->name, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_172+currStrOff, " = channel();\n", strLen_3);
                    currStrOff += strLen_3;
                    
                    ____BAH_COMPILER_VAR_172[currStrOff] = 0;
                }
                char * ____BAH_COMPILER_VAR_173 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_172);
;                            
                    ____BAH_COMPILER_VAR_173 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_173+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_173+currStrOff, ____BAH_COMPILER_VAR_172, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_173[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_173;
declared =  true;
}
if ((isRCPpointerType(m->type)&&(declared==false))) {
char * ____BAH_COMPILER_VAR_174 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(sep);
long int strLen_3 = strlen(m->name);
long int strLen_4 = strlen("= null;\n");
;                            
                    ____BAH_COMPILER_VAR_174 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_174+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_174+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_174+currStrOff, sep, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_174+currStrOff, m->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_174+currStrOff, "= null;\n", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_174[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_174;
}
i =  i + 1;
};
if ((strlen(s->extendedFrom)>0)) {
struct cStruct* es =  searchStruct(s->extendedFrom,elems);
i =  0;
while ((i<len(es->methods))) {

                    if (es->methods->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/var.bah:364): es->methods[%d] with length %d\n", i, es->methods->length);
                        exit(1);
                    };
                    struct func* m =  es->methods->data[i];
char * ____BAH_COMPILER_VAR_175 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(sep);
long int strLen_3 = strlen(m->name);
long int strLen_4 = strlen(" = ");
long int strLen_5 = strlen(es->name);
long int strLen_6 = strlen("__");
long int strLen_7 = strlen(m->name);
long int strLen_8 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_175 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                    
                    memcpy(____BAH_COMPILER_VAR_175+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_175+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_175+currStrOff, sep, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_175+currStrOff, m->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_175+currStrOff, " = ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_175+currStrOff, es->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_175+currStrOff, "__", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_175+currStrOff, m->name, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_175+currStrOff, ";\n", strLen_8);
                    currStrOff += strLen_8;
                    
                    ____BAH_COMPILER_VAR_175[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_175;
i =  i + 1;
};
}
array(struct func*)* methods =  s->methods;
i =  0;
while ((i<len(methods))) {

                    if (methods->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/var.bah:372): methods[%d] with length %d\n", i, methods->length);
                        exit(1);
                    };
                    struct func* m =  methods->data[i];
char * ____BAH_COMPILER_VAR_176 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(sep);
long int strLen_3 = strlen(m->name);
long int strLen_4 = strlen(" = ");
long int strLen_5 = strlen(s->name);
long int strLen_6 = strlen("__");
long int strLen_7 = strlen(m->name);
long int strLen_8 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_176 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                    
                    memcpy(____BAH_COMPILER_VAR_176+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_176+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_176+currStrOff, sep, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_176+currStrOff, m->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_176+currStrOff, " = ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_176+currStrOff, s->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_176+currStrOff, "__", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_176+currStrOff, m->name, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_176+currStrOff, ";\n", strLen_8);
                    currStrOff += strLen_8;
                    
                    ____BAH_COMPILER_VAR_176[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_176;
i =  i + 1;
};
if ((((s->isBinding==false)&&RCPavailable())&&(s->hasRCPmemb==true))) {
if ((strCount(v->type,"*")==0)) {
char * ____BAH_COMPILER_VAR_177 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(".__RCP_counter = malloc(sizeof(int));*(int*)");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen(".__RCP_counter = 1;\n");
;                            
                    ____BAH_COMPILER_VAR_177 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_177+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_177+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_177+currStrOff, ".__RCP_counter = malloc(sizeof(int));*(int*)", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_177+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_177+currStrOff, ".__RCP_counter = 1;\n", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_177[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_177;
}
else {
char * ____BAH_COMPILER_VAR_178 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen("->__RCP_counter = RCP_request(");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen(");\n");
;                            
                    ____BAH_COMPILER_VAR_178 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_178+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_178+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_178+currStrOff, "->__RCP_counter = RCP_request(", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_178+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_178+currStrOff, ");\n", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_178[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_178;
}
}
return code;
};
long int NB_COMP_VAR;
char * genCompilerVar(){
char * ____BAH_COMPILER_VAR_179 =intToStr(NB_COMP_VAR);char * ____BAH_COMPILER_VAR_180 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("____BAH_COMPILER_VAR_");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_179);
;                            
                    ____BAH_COMPILER_VAR_180 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_180+currStrOff, "____BAH_COMPILER_VAR_", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_180+currStrOff, ____BAH_COMPILER_VAR_179, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_180[currStrOff] = 0;
                }
                char * name =  ____BAH_COMPILER_VAR_180;
NB_COMP_VAR =  NB_COMP_VAR + 1;
return name;
};
typedef array(struct variable*)* __BAH_ARR_TYPE_variable;
char varInArr(struct variable* v,__BAH_ARR_TYPE_variable arr){
if ((arr==null)) {
return false;
}
long int j =  0;
while ((j<len(arr))) {

                    if (arr->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/var.bah:401): arr[%d] with length %d\n", j, arr->length);
                        exit(1);
                    };
                    struct variable* ev =  arr->data[j];
if ((strcmp(ev->name, v->name) == 0)) {
return true;
}
j =  j + 1;
};
return false;
};
char * pathToVarName(char * p){
array(char)* a =  strToArr(p);
long int i =  0;
for (; (i<len(a)); i =  i+1) {

                    if (a->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/var.bah:413): a[%d] with length %d\n", i, a->length);
                        exit(1);
                    };
                    long int c =  a->data[i];
c =  c - (long int)97;
if ((c<0)) {
c =  0 - c;
}
c =  c % ((long int)122 - (long int)97);
c =  c + (long int)97;

{
long nLength = i;
if (a->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(a->data, (nLength+50)*sizeof(char));
a->data = newPtr;
}
a->data[i] =  (char)c;
a->length = nLength+1;
} else {
a->data[i] =  (char)c;
}
};
};
return arrToStr(a);
};
void makeInit(){
char * name =  "__BAH_init";
if ((isObject==true)) {
char * ____BAH_COMPILER_VAR_181 =pathToVarName(compilerState.currentFile);char * ____BAH_COMPILER_VAR_182 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(name);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_181);
;                            
                    ____BAH_COMPILER_VAR_182 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_182+currStrOff, name, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_182+currStrOff, ____BAH_COMPILER_VAR_181, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_182[currStrOff] = 0;
                }
                name =  ____BAH_COMPILER_VAR_182;
}
char * evals =  "";
char * ____BAH_COMPILER_VAR_183 =intToStr(len(compilerState.evals));char * ____BAH_COMPILER_VAR_184 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("volatile struct __eval_binding __tmp__evals_bindings[");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_183);
long int strLen_2 = strlen("] = {");
;                            
                    ____BAH_COMPILER_VAR_184 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_184+currStrOff, "volatile struct __eval_binding __tmp__evals_bindings[", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_184+currStrOff, ____BAH_COMPILER_VAR_183, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_184+currStrOff, "] = {", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_184[currStrOff] = 0;
                }
                char * evalsTMPDecl =  ____BAH_COMPILER_VAR_184;
long int i =  0;
for (; (i<len(compilerState.evals)); i =  i+1) {

                    if (compilerState.evals->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/var.bah:435): compilerState.evals[%d] with length %d\n", i, compilerState.evals->length);
                        exit(1);
                    };
                    char * e =  compilerState.evals->data[i];
char * ____BAH_COMPILER_VAR_185 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("{\n            .name = \"");
long int strLen_1 = strlen(e);
long int strLen_2 = strlen("\",\n            .evalFn = __Bah_eval_");
long int strLen_3 = strlen(e);
long int strLen_4 = strlen("\n        }");
;                            
                    ____BAH_COMPILER_VAR_185 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_185+currStrOff, "{\n            .name = \"", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_185+currStrOff, e, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_185+currStrOff, "\",\n            .evalFn = __Bah_eval_", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_185+currStrOff, e, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_185+currStrOff, "\n        }", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_185[currStrOff] = 0;
                }
                char * ____BAH_COMPILER_VAR_186 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(evalsTMPDecl);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_185);
;                            
                    ____BAH_COMPILER_VAR_186 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_186+currStrOff, evalsTMPDecl, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_186+currStrOff, ____BAH_COMPILER_VAR_185, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_186[currStrOff] = 0;
                }
                evalsTMPDecl =  ____BAH_COMPILER_VAR_186;
if ((i + 1!=len(compilerState.evals))) {
char * ____BAH_COMPILER_VAR_187 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(evalsTMPDecl);
long int strLen_1 = strlen(",\n");
;                            
                    ____BAH_COMPILER_VAR_187 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_187+currStrOff, evalsTMPDecl, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_187+currStrOff, ",\n", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_187[currStrOff] = 0;
                }
                evalsTMPDecl =  ____BAH_COMPILER_VAR_187;
}
else {
char * ____BAH_COMPILER_VAR_188 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(evalsTMPDecl);
long int strLen_1 = strlen("};");
;                            
                    ____BAH_COMPILER_VAR_188 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_188+currStrOff, evalsTMPDecl, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_188+currStrOff, "};", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_188[currStrOff] = 0;
                }
                evalsTMPDecl =  ____BAH_COMPILER_VAR_188;
}
};
if ((len(compilerState.evals)!=0)) {
char * ____BAH_COMPILER_VAR_189 =intToStr(len(compilerState.evals));char * ____BAH_COMPILER_VAR_190 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("__evals_bindings = __tmp__evals_bindings; __evals_length = ");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_189);
long int strLen_2 = strlen(";");
;                            
                    ____BAH_COMPILER_VAR_190 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_190+currStrOff, "__evals_bindings = __tmp__evals_bindings; __evals_length = ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_190+currStrOff, ____BAH_COMPILER_VAR_189, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_190+currStrOff, ";", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_190[currStrOff] = 0;
                }
                evals =  ____BAH_COMPILER_VAR_190;
}
else {
evalsTMPDecl =  "";
}
char * ____BAH_COMPILER_VAR_191 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n    ");
long int strLen_1 = strlen(evalsTMPDecl);
long int strLen_2 = strlen("\n    void __attribute__((optimize(\"O0\"))) ");
long int strLen_3 = strlen(name);
long int strLen_4 = strlen("() {\n        ");
;                            
                    ____BAH_COMPILER_VAR_191 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_191+currStrOff, "\n    ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_191+currStrOff, evalsTMPDecl, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_191+currStrOff, "\n    void __attribute__((optimize(\"O0\"))) ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_191+currStrOff, name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_191+currStrOff, "() {\n        ", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_191[currStrOff] = 0;
                }
                char * ____BAH_COMPILER_VAR_192 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n        ");
long int strLen_1 = strlen(evals);
long int strLen_2 = strlen("\n    };\n    ");
;                            
                    ____BAH_COMPILER_VAR_192 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_192+currStrOff, "\n        ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_192+currStrOff, evals, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_192+currStrOff, "\n    };\n    ", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_192[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_191))->add(OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_191)), INIT)->add(OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_191))->add(OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_191)), INIT), rope(____BAH_COMPILER_VAR_192));
};
struct rope* decrVar(struct variable* v,struct Elems* elems){
struct rope* r =  rope("");
if (strHasPrefix(v->type,"[]")) {
struct string at =  string(v->type);
at.trimLeft((struct string*)&at,2);
char * ____BAH_COMPILER_VAR_193 =at.str((struct string*)&at);if (isRCPtype(____BAH_COMPILER_VAR_193,elems)) {
struct variable* ____BAH_COMPILER_VAR_194 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_194->name = "";
____BAH_COMPILER_VAR_194->type = "";
____BAH_COMPILER_VAR_194->isConst = false;
____BAH_COMPILER_VAR_194->constVal = "";
____BAH_COMPILER_VAR_194->isArray = false;
____BAH_COMPILER_VAR_194->from = "";
____BAH_COMPILER_VAR_194->outterScope = false;
____BAH_COMPILER_VAR_194->isGlobal = false;
struct variable* arrElem =  ____BAH_COMPILER_VAR_194;
arrElem->type =  at.str((struct string*)&at);
char * ____BAH_COMPILER_VAR_195 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen("->data[arrElemIndex]");
;                            
                    ____BAH_COMPILER_VAR_195 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_195+currStrOff, v->name, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_195+currStrOff, "->data[arrElemIndex]", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_195[currStrOff] = 0;
                }
                arrElem->name =  ____BAH_COMPILER_VAR_195;
char * ____BAH_COMPILER_VAR_196 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n            {\n            struct RCP * arrRCP = RCP_request(");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(");\n            if (arrRCP != null && arrRCP->c == 1) {\n                struct RCP * arrDataRCP = RCP_request(");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen("->data);\n                if (arrDataRCP != null && arrDataRCP->c == 1) {\n                    for(int arrElemIndex=len(");
long int strLen_5 = strlen(v->name);
long int strLen_6 = strlen(")-1; arrElemIndex >= 0; arrElemIndex--) {\n                        ");
;                            
                    ____BAH_COMPILER_VAR_196 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                    
                    memcpy(____BAH_COMPILER_VAR_196+currStrOff, "\n            {\n            struct RCP * arrRCP = RCP_request(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_196+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_196+currStrOff, ");\n            if (arrRCP != null && arrRCP->c == 1) {\n                struct RCP * arrDataRCP = RCP_request(", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_196+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_196+currStrOff, "->data);\n                if (arrDataRCP != null && arrDataRCP->c == 1) {\n                    for(int arrElemIndex=len(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_196+currStrOff, v->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_196+currStrOff, ")-1; arrElemIndex >= 0; arrElemIndex--) {\n                        ", strLen_6);
                    currStrOff += strLen_6;
                    
                    ____BAH_COMPILER_VAR_196[currStrOff] = 0;
                }
                r =  rope(____BAH_COMPILER_VAR_196)->add(rope(____BAH_COMPILER_VAR_196), decrVar(arrElem,elems))->add(rope(____BAH_COMPILER_VAR_196)->add(rope(____BAH_COMPILER_VAR_196), decrVar(arrElem,elems)), rope("\n                    };\n                }\n                RCP_decrRCP(arrDataRCP);\n            }\n            RCP_decrRCP(arrRCP);\n            };\n            "));
}
else {
char * ____BAH_COMPILER_VAR_197 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n            {\n            struct RCP * arrRCP = RCP_request(");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(");\n            if (arrRCP != null) {\n                if (arrRCP->c == 1) {\n                    struct RCP * arrDataRCP = RCP_request(");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen("->data);\n                    RCP_decrRCP(arrDataRCP);\n                }\n                RCP_decrRCP(arrRCP);\n            }\n            };\n            ");
;                            
                    ____BAH_COMPILER_VAR_197 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_197+currStrOff, "\n            {\n            struct RCP * arrRCP = RCP_request(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_197+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_197+currStrOff, ");\n            if (arrRCP != null) {\n                if (arrRCP->c == 1) {\n                    struct RCP * arrDataRCP = RCP_request(", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_197+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_197+currStrOff, "->data);\n                    RCP_decrRCP(arrDataRCP);\n                }\n                RCP_decrRCP(arrRCP);\n            }\n            };\n            ", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_197[currStrOff] = 0;
                }
                r =  rope(____BAH_COMPILER_VAR_197);
}
}
else if (strHasPrefix(v->type,"chan:")) {
char * ____BAH_COMPILER_VAR_198 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("{\n            struct RCP * chanRCP = RCP_request(");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(");\n            if (chanRCP != null && chanRCP->c == 1) {\n                ");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen("->destroy(");
long int strLen_5 = strlen(v->name);
long int strLen_6 = strlen(");\n                RCP_decr(");
long int strLen_7 = strlen(v->name);
long int strLen_8 = strlen("->queue);\n            };\n            RCP_decrRCP(chanRCP);\n        };");
;                            
                    ____BAH_COMPILER_VAR_198 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                    
                    memcpy(____BAH_COMPILER_VAR_198+currStrOff, "{\n            struct RCP * chanRCP = RCP_request(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_198+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_198+currStrOff, ");\n            if (chanRCP != null && chanRCP->c == 1) {\n                ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_198+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_198+currStrOff, "->destroy(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_198+currStrOff, v->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_198+currStrOff, ");\n                RCP_decr(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_198+currStrOff, v->name, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_198+currStrOff, "->queue);\n            };\n            RCP_decrRCP(chanRCP);\n        };", strLen_8);
                    currStrOff += strLen_8;
                    
                    ____BAH_COMPILER_VAR_198[currStrOff] = 0;
                }
                r =  rope(____BAH_COMPILER_VAR_198);
}
else {
if (strHasPrefix(v->type,"map:")) {
struct variable* ____BAH_COMPILER_VAR_199 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_199->name = "";
____BAH_COMPILER_VAR_199->type = "";
____BAH_COMPILER_VAR_199->isConst = false;
____BAH_COMPILER_VAR_199->constVal = "";
____BAH_COMPILER_VAR_199->isArray = false;
____BAH_COMPILER_VAR_199->from = "";
____BAH_COMPILER_VAR_199->outterScope = false;
____BAH_COMPILER_VAR_199->isGlobal = false;
struct variable* nv =  ____BAH_COMPILER_VAR_199;
*nv =  *v;
v =  nv;
v->type =  "mapWrapper*";
}
char isPointer =  isRCPpointerType(v->type);
struct cStruct* s =  searchStruct(v->type,elems);
if (((s!=null)&&(s->isBinding==false))) {
char * amp =  "&";
char * heap =  "0";
if ((isPointer==true)) {
amp =  "";
heap =  "1";
}
char * ____BAH_COMPILER_VAR_200 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("__RCP_clean_");
long int strLen_1 = strlen(s->name);
long int strLen_2 = strlen("(");
long int strLen_3 = strlen(amp);
long int strLen_4 = strlen(v->name);
long int strLen_5 = strlen(", ");
long int strLen_6 = strlen(heap);
long int strLen_7 = strlen(");\n");
;                            
                    ____BAH_COMPILER_VAR_200 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7);
                    
                    memcpy(____BAH_COMPILER_VAR_200+currStrOff, "__RCP_clean_", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_200+currStrOff, s->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_200+currStrOff, "(", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_200+currStrOff, amp, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_200+currStrOff, v->name, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_200+currStrOff, ", ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_200+currStrOff, heap, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_200+currStrOff, ");\n", strLen_7);
                    currStrOff += strLen_7;
                    
                    ____BAH_COMPILER_VAR_200[currStrOff] = 0;
                }
                r =  r->add(r, rope(____BAH_COMPILER_VAR_200));
}
else if ((isPointer==true)) {
char * ____BAH_COMPILER_VAR_201 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("RCP_decr(");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(");\n");
;                            
                    ____BAH_COMPILER_VAR_201 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_201+currStrOff, "RCP_decr(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_201+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_201+currStrOff, ");\n", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_201[currStrOff] = 0;
                }
                r =  r->add(r, rope(____BAH_COMPILER_VAR_201));
}
}
return r;
};
struct rope* incrVar(struct variable* v,struct Elems* elems){
if ((strCount(v->name,"*")>0)) {
return rope("");
}
struct cStruct* s =  searchStruct(v->type,elems);
if ((((s!=null)&&(isRCPpointerType(v->type)==false))&&(s->isBinding==false))) {
char * ____BAH_COMPILER_VAR_202 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("RCP_incrCounter(");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(".__RCP_counter);");
;                            
                    ____BAH_COMPILER_VAR_202 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_202+currStrOff, "RCP_incrCounter(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_202+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_202+currStrOff, ".__RCP_counter);", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_202[currStrOff] = 0;
                }
                return rope(____BAH_COMPILER_VAR_202);
}
char * ____BAH_COMPILER_VAR_203 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("RCP_incr(");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(");");
;                            
                    ____BAH_COMPILER_VAR_203 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_203+currStrOff, "RCP_incr(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_203+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_203+currStrOff, ");", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_203[currStrOff] = 0;
                }
                return rope(____BAH_COMPILER_VAR_203);
};
char RCPavailable(){
char * ____BAH_COMPILER_VAR_204 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen("rcp.bah");
;                            
                    ____BAH_COMPILER_VAR_204 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_204+currStrOff, BAH_DIR, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_204+currStrOff, "rcp.bah", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_204[currStrOff] = 0;
                }
                char * ____BAH_COMPILER_VAR_205 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen("fastrcp.bah");
;                            
                    ____BAH_COMPILER_VAR_205 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_205+currStrOff, BAH_DIR, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_205+currStrOff, "fastrcp.bah", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_205[currStrOff] = 0;
                }
                return (((strcmp(absPath(compilerState.currentFile), absPath(____BAH_COMPILER_VAR_204)) != 0)&&(strcmp(absPath(compilerState.currentFile), absPath(____BAH_COMPILER_VAR_205)) != 0))&&(RCPenabled==true));
};
void endRCPscope(struct Elems* elems,__BAH_ARR_TYPE_variable exc){
if ((RCPavailable()==false)) {
return;
}
long int i =  0;
for (; (i<len(elems->vars)); i =  i+1) {

                    if (elems->vars->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/mem.bah:100): elems->vars[%d] with length %d\n", i, elems->vars->length);
                        exit(1);
                    };
                    struct variable* v =  elems->vars->data[i];
if (((v->outterScope==false)&&(isRCPtype(v->type,elems)==true))) {
if ((varInArr(v,exc)==false)) {
OUTPUT =  OUTPUT->add(OUTPUT, decrVar(v,elems));
}
}
};
};
void endRCPnonGlobScope(struct Elems* elems,__BAH_ARR_TYPE_variable exc){
if ((RCPavailable()==false)) {
return;
}
long int i =  0;
for (; (i<len(elems->vars)); i =  i+1) {

                    if (elems->vars->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/mem.bah:114): elems->vars[%d] with length %d\n", i, elems->vars->length);
                        exit(1);
                    };
                    struct variable* v =  elems->vars->data[i];
if ((isRCPtype(v->type,elems)==true)) {
if (((v->isGlobal==false)&&(varInArr(v,exc)==false))) {
OUTPUT =  OUTPUT->add(OUTPUT, decrVar(v,elems));
}
}
};
};
char * registerRCPvar(char * t,char * c,struct Elems* elems){
struct variable* ____BAH_COMPILER_VAR_206 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_206->name = "";
____BAH_COMPILER_VAR_206->type = "";
____BAH_COMPILER_VAR_206->isConst = false;
____BAH_COMPILER_VAR_206->constVal = "";
____BAH_COMPILER_VAR_206->isArray = false;
____BAH_COMPILER_VAR_206->from = "";
____BAH_COMPILER_VAR_206->outterScope = false;
____BAH_COMPILER_VAR_206->isGlobal = false;
struct variable* av =  ____BAH_COMPILER_VAR_206;
av->type =  t;
av->name =  genCompilerVar();

{
long nLength = len(elems->vars);
if (elems->vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(elems->vars->data, (nLength+50)*sizeof(struct variable*));
elems->vars->data = newPtr;
}
elems->vars->data[len(elems->vars)] =  av;
elems->vars->length = nLength+1;
} else {
elems->vars->data[len(elems->vars)] =  av;
}
};
struct string cType =  getCType(av->type,elems);
char * ____BAH_COMPILER_VAR_207 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_208 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_207);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(av->name);
long int strLen_3 = strlen(" =");
long int strLen_4 = strlen(c);
long int strLen_5 = strlen(";");
;                            
                    ____BAH_COMPILER_VAR_208 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    memcpy(____BAH_COMPILER_VAR_208+currStrOff, ____BAH_COMPILER_VAR_207, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_208+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_208+currStrOff, av->name, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_208+currStrOff, " =", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_208+currStrOff, c, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_208+currStrOff, ";", strLen_5);
                    currStrOff += strLen_5;
                    
                    ____BAH_COMPILER_VAR_208[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_208));
return av->name;
};
struct rope* makeRCPfuncFromStruct(struct cStruct* s,struct Elems* elems){
if (((s->isBinding==true)||(RCPavailable()==false))) {
return rope("");
}
struct rope* decrMembs =  rope("");
long int i =  0;
while ((i<len(s->members))) {

                    if (s->members->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/mem.bah:141): s->members[%d] with length %d\n", i, s->members->length);
                        exit(1);
                    };
                    struct structMemb* m =  s->members->data[i];
struct string rm =  string(m->type);
rm.replace((struct string*)&rm,"*","");
if (isRCPtype(m->type,elems)) {
if ((strcmp(rm.str((struct string*)&rm), s->name) != 0)) {
struct variable* ____BAH_COMPILER_VAR_209 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_209->name = "";
____BAH_COMPILER_VAR_209->type = "";
____BAH_COMPILER_VAR_209->isConst = false;
____BAH_COMPILER_VAR_209->constVal = "";
____BAH_COMPILER_VAR_209->isArray = false;
____BAH_COMPILER_VAR_209->from = "";
____BAH_COMPILER_VAR_209->outterScope = false;
____BAH_COMPILER_VAR_209->isGlobal = false;
struct variable* mv =  ____BAH_COMPILER_VAR_209;
char * ____BAH_COMPILER_VAR_210 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("e->");
long int strLen_1 = strlen(m->name);
;                            
                    ____BAH_COMPILER_VAR_210 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_210+currStrOff, "e->", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_210+currStrOff, m->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_210[currStrOff] = 0;
                }
                mv->name =  ____BAH_COMPILER_VAR_210;
mv->type =  m->type;
decrMembs =  decrMembs->add(decrMembs, decrVar(mv,elems));
}
else {
char * ____BAH_COMPILER_VAR_211 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Strcture '");
long int strLen_1 = strlen(s->name);
long int strLen_2 = strlen("' has a self-referenced member '");
long int strLen_3 = strlen(m->name);
long int strLen_4 = strlen("'. May lead to memory leaks, recompile the program without the '-rcp' flag if memory leaks happens.");
;                            
                    ____BAH_COMPILER_VAR_211 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_211+currStrOff, "Strcture '", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_211+currStrOff, s->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_211+currStrOff, "' has a self-referenced member '", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_211+currStrOff, m->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_211+currStrOff, "'. May lead to memory leaks, recompile the program without the '-rcp' flag if memory leaks happens.", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_211[currStrOff] = 0;
                }
                throwWarning(____BAH_COMPILER_VAR_211);
char * amp =  "&";
char * heap =  "0";
if ((strCount(m->type,"*")>0)) {
amp =  "";
heap =  "1";
}
char * ____BAH_COMPILER_VAR_212 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("__RCP_clean_");
long int strLen_1 = strlen(s->name);
long int strLen_2 = strlen("(");
long int strLen_3 = strlen(amp);
long int strLen_4 = strlen("e->");
long int strLen_5 = strlen(m->name);
long int strLen_6 = strlen(", ");
long int strLen_7 = strlen(heap);
long int strLen_8 = strlen(");\n");
;                            
                    ____BAH_COMPILER_VAR_212 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                    
                    memcpy(____BAH_COMPILER_VAR_212+currStrOff, "__RCP_clean_", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_212+currStrOff, s->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_212+currStrOff, "(", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_212+currStrOff, amp, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_212+currStrOff, "e->", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_212+currStrOff, m->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_212+currStrOff, ", ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_212+currStrOff, heap, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_212+currStrOff, ");\n", strLen_8);
                    currStrOff += strLen_8;
                    
                    ____BAH_COMPILER_VAR_212[currStrOff] = 0;
                }
                decrMembs =  decrMembs->add(decrMembs, rope(____BAH_COMPILER_VAR_212));
}
}
i =  i + 1;
};
char * ____BAH_COMPILER_VAR_213 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("void* __RCP_clean_");
long int strLen_1 = strlen(s->name);
long int strLen_2 = strlen("(struct ");
long int strLen_3 = strlen(s->name);
long int strLen_4 = strlen("* e, int heap) {\n        if(heap == 1) {\n            struct RCP* srcp = RCP_request(e);\n            if (srcp != null) {\n                if (srcp->c == 1) {\n                    ");
;                            
                    ____BAH_COMPILER_VAR_213 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_213+currStrOff, "void* __RCP_clean_", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_213+currStrOff, s->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_213+currStrOff, "(struct ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_213+currStrOff, s->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_213+currStrOff, "* e, int heap) {\n        if(heap == 1) {\n            struct RCP* srcp = RCP_request(e);\n            if (srcp != null) {\n                if (srcp->c == 1) {\n                    ", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_213[currStrOff] = 0;
                }
                struct rope* r =  rope(____BAH_COMPILER_VAR_213)->add(rope(____BAH_COMPILER_VAR_213), decrMembs)->add(rope(____BAH_COMPILER_VAR_213)->add(rope(____BAH_COMPILER_VAR_213), decrMembs), rope("\n                }\n                RCP_decrRCP(srcp);\n            }\n        } else if(RCP_decrCounter((void*)e->__RCP_counter)==0) {\n            "))->add(rope(____BAH_COMPILER_VAR_213)->add(rope(____BAH_COMPILER_VAR_213), decrMembs)->add(rope(____BAH_COMPILER_VAR_213)->add(rope(____BAH_COMPILER_VAR_213), decrMembs), rope("\n                }\n                RCP_decrRCP(srcp);\n            }\n        } else if(RCP_decrCounter((void*)e->__RCP_counter)==0) {\n            ")), decrMembs)->add(rope(____BAH_COMPILER_VAR_213)->add(rope(____BAH_COMPILER_VAR_213), decrMembs)->add(rope(____BAH_COMPILER_VAR_213)->add(rope(____BAH_COMPILER_VAR_213), decrMembs), rope("\n                }\n                RCP_decrRCP(srcp);\n            }\n        } else if(RCP_decrCounter((void*)e->__RCP_counter)==0) {\n            "))->add(rope(____BAH_COMPILER_VAR_213)->add(rope(____BAH_COMPILER_VAR_213), decrMembs)->add(rope(____BAH_COMPILER_VAR_213)->add(rope(____BAH_COMPILER_VAR_213), decrMembs), rope("\n                }\n                RCP_decrRCP(srcp);\n            }\n        } else if(RCP_decrCounter((void*)e->__RCP_counter)==0) {\n            ")), decrMembs), rope("\n        }\n    };\n"));
return r;
};
char RCPselfRef(struct variable* v){
long int i =  0;
while ((i<len(compilerState.RCPvars))) {

                    if (compilerState.RCPvars->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/mem.bah:183): compilerState.RCPvars[%d] with length %d\n", i, compilerState.RCPvars->length);
                        exit(1);
                    };
                    struct variable* r =  compilerState.RCPvars->data[i];
if ((strcmp(r->name, v->name) == 0)) {
return true;
}
i =  i + 1;
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

                int ____BAH_COMPILER_VAR_214 = 0;
                for(int i=len(noVOfns)-1; i != -1; i--) {
                    if (noVOfns->data[i] != 0 && strcmp(noVOfns->data[i], currentFn->name) == 0) {
                        ____BAH_COMPILER_VAR_214 = 1;
                        break;
                    };
                };
                if (____BAH_COMPILER_VAR_214) {
return false;
}
}
return true;
};
struct verboseOutVar verboseOutTransformVar(struct variable* v,char * cont,struct Elems* elems){
struct verboseOutVar ____BAH_COMPILER_VAR_215 = {};
____BAH_COMPILER_VAR_215.markup= null;
____BAH_COMPILER_VAR_215.content= null;
struct verboseOutVar rv =  ____BAH_COMPILER_VAR_215;
char * ogCont =  cont;
if ((strcmp(v->type, "cpstring") == 0)) {
char * ____BAH_COMPILER_VAR_216 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("__Bah_safe_string(");
long int strLen_1 = strlen(cont);
long int strLen_2 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_216 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_216+currStrOff, "__Bah_safe_string(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_216+currStrOff, cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_216+currStrOff, ")", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_216[currStrOff] = 0;
                }
                cont =  ____BAH_COMPILER_VAR_216;
}
char * ____BAH_COMPILER_VAR_217 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(", ");
long int strLen_1 = strlen(cont);
;                            
                    ____BAH_COMPILER_VAR_217 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_217+currStrOff, ", ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_217+currStrOff, cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_217[currStrOff] = 0;
                }
                cont =  ____BAH_COMPILER_VAR_217;
char * ct =  "";
if ((strcmp(v->type, "cpstring") == 0)) {
ct =  "%s";
}
else if ((strcmp(v->type, "int") == 0)) {
ct =  "%li";
}
else if ((strcmp(v->type, "float") == 0)) {
ct =  "%d";
}
else if ((isRCPpointerType(v->type)==true)) {
ct =  "%p";
}
else {
struct cStruct* s =  searchStruct(v->type,elems);
if ((s==null)) {
ct =  "%li";
}
else {
char * ____BAH_COMPILER_VAR_218 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ASCII_RESET);
long int strLen_1 = strlen("{");
;                            
                    ____BAH_COMPILER_VAR_218 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_218+currStrOff, ASCII_RESET, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_218+currStrOff, "{", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_218[currStrOff] = 0;
                }
                ct =  ____BAH_COMPILER_VAR_218;
cont =  "";
long int i =  0;
for (; (i<len(s->members)); i =  i+1) {

                    if (s->members->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/verboseOut.bah:53): s->members[%d] with length %d\n", i, s->members->length);
                        exit(1);
                    };
                    struct variable* m =  s->members->data[i];
char * ____BAH_COMPILER_VAR_219 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("(");
long int strLen_1 = strlen(ogCont);
long int strLen_2 = strlen(")");
long int strLen_3 = strlen(".");
long int strLen_4 = strlen(m->name);
;                            
                    ____BAH_COMPILER_VAR_219 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_219+currStrOff, "(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_219+currStrOff, ogCont, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_219+currStrOff, ")", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_219+currStrOff, ".", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_219+currStrOff, m->name, strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_219[currStrOff] = 0;
                }
                struct verboseOutVar mv =  verboseOutTransformVar(m,____BAH_COMPILER_VAR_219,elems);
if ((i!=0)) {
char * ____BAH_COMPILER_VAR_220 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ct);
long int strLen_1 = strlen(", ");
;                            
                    ____BAH_COMPILER_VAR_220 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_220+currStrOff, ct, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_220+currStrOff, ", ", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_220[currStrOff] = 0;
                }
                ct =  ____BAH_COMPILER_VAR_220;
}
char * ____BAH_COMPILER_VAR_221 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ct);
long int strLen_1 = strlen(mv.markup);
;                            
                    ____BAH_COMPILER_VAR_221 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_221+currStrOff, ct, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_221+currStrOff, mv.markup, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_221[currStrOff] = 0;
                }
                ct =  ____BAH_COMPILER_VAR_221;
char * ____BAH_COMPILER_VAR_222 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(cont);
long int strLen_1 = strlen(mv.content);
;                            
                    ____BAH_COMPILER_VAR_222 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_222+currStrOff, cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_222+currStrOff, mv.content, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_222[currStrOff] = 0;
                }
                cont =  ____BAH_COMPILER_VAR_222;
};
char * ____BAH_COMPILER_VAR_223 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ct);
long int strLen_1 = strlen("}");
;                            
                    ____BAH_COMPILER_VAR_223 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_223+currStrOff, ct, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_223+currStrOff, "}", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_223[currStrOff] = 0;
                }
                ct =  ____BAH_COMPILER_VAR_223;
}
}
char * ____BAH_COMPILER_VAR_224 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ASCII_BLUE);
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(ASCII_RESET);
long int strLen_3 = strlen(" = ");
long int strLen_4 = strlen(ASCII_MAGENTA);
long int strLen_5 = strlen(ct);
long int strLen_6 = strlen(ASCII_RESET);
;                            
                    ____BAH_COMPILER_VAR_224 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                    
                    memcpy(____BAH_COMPILER_VAR_224+currStrOff, ASCII_BLUE, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_224+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_224+currStrOff, ASCII_RESET, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_224+currStrOff, " = ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_224+currStrOff, ASCII_MAGENTA, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_224+currStrOff, ct, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_224+currStrOff, ASCII_RESET, strLen_6);
                    currStrOff += strLen_6;
                    
                    ____BAH_COMPILER_VAR_224[currStrOff] = 0;
                }
                rv.markup =  ____BAH_COMPILER_VAR_224;
rv.content =  cont;
return rv;
};
struct verboseOutVar verboseOutTransformTok(struct Tok t,struct Elems* elems){
if (((t.type==TOKEN_TYPE_VAR)&&(t.isOper==false))) {
struct variable* v =  searchVar(t.cont,elems);
if ((v==null)) {
return verboseOutTransformVar(v,t.cont,elems);
}
}
struct variable ____BAH_COMPILER_VAR_225 = {};
____BAH_COMPILER_VAR_225.name = "";
____BAH_COMPILER_VAR_225.type = "";
____BAH_COMPILER_VAR_225.isConst = false;
____BAH_COMPILER_VAR_225.constVal = "";
____BAH_COMPILER_VAR_225.isArray = false;
____BAH_COMPILER_VAR_225.from = "";
____BAH_COMPILER_VAR_225.outterScope = false;
____BAH_COMPILER_VAR_225.isGlobal = false;
____BAH_COMPILER_VAR_225.name = "(value)";
____BAH_COMPILER_VAR_225.type = getTypeFromToken(&t,true,elems);
struct variable v =  ____BAH_COMPILER_VAR_225;
return verboseOutTransformVar(&v,t.cont,elems);
};
void verboseOutFunc(struct func* fn,__BAH_ARR_TYPE_Tok args,long int lineNb,struct Elems* elems){
if ((verboseOutGuard()==false)) {
return;
}
char * nameColor =  ASCII_YELLOW;
if ((fn->isBinding==true)) {
if (strHasPrefix(compilerState.currentFile,BAH_DIR)) {
return;
}
nameColor =  ASCII_GREY;
}
if (strHasPrefix(fn->file,BAH_DIR)) {
char hasPtr =  false;
long int i =  0;
for (; (i<len(fn->args)); i =  i+1) {

                    if (fn->args->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/verboseOut.bah:101): fn->args[%d] with length %d\n", i, fn->args->length);
                        exit(1);
                    };
                    struct variable* a =  fn->args->data[i];
if ((isRCPpointerType(a->type)==true)) {
hasPtr =  true;
break;
}
};
if ((hasPtr==false)) {
return;
}
}
char * fnArgs =  "";
char * fnArgsValues =  "";
long int j =  0;
for (; (j<len(fn->args)); j =  j+1) {

                    if (fn->args->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/verboseOut.bah:115): fn->args[%d] with length %d\n", j, fn->args->length);
                        exit(1);
                    };
                    struct variable* a =  fn->args->data[j];
if ((j!=0)) {
char * ____BAH_COMPILER_VAR_226 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(fnArgs);
long int strLen_1 = strlen(", ");
;                            
                    ____BAH_COMPILER_VAR_226 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_226+currStrOff, fnArgs, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_226+currStrOff, ", ", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_226[currStrOff] = 0;
                }
                fnArgs =  ____BAH_COMPILER_VAR_226;
}

                    if (args->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/verboseOut.bah:120): args[%d] with length %d\n", j, args->length);
                        exit(1);
                    };
                    struct Tok t =  args->data[j];
struct verboseOutVar v =  verboseOutTransformVar(a,t.cont,elems);
char * ____BAH_COMPILER_VAR_227 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(fnArgs);
long int strLen_1 = strlen(v.markup);
;                            
                    ____BAH_COMPILER_VAR_227 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_227+currStrOff, fnArgs, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_227+currStrOff, v.markup, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_227[currStrOff] = 0;
                }
                fnArgs =  ____BAH_COMPILER_VAR_227;
char * ____BAH_COMPILER_VAR_228 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(fnArgsValues);
long int strLen_1 = strlen(v.content);
;                            
                    ____BAH_COMPILER_VAR_228 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_228+currStrOff, fnArgsValues, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_228+currStrOff, v.content, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_228[currStrOff] = 0;
                }
                fnArgsValues =  ____BAH_COMPILER_VAR_228;
};
char * ____BAH_COMPILER_VAR_229 =intToStr(lineNb);char * ____BAH_COMPILER_VAR_230 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(compilerState.currentFile);
long int strLen_1 = strlen(":");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_229);
;                            
                    ____BAH_COMPILER_VAR_230 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_230+currStrOff, compilerState.currentFile, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_230+currStrOff, ":", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_230+currStrOff, ____BAH_COMPILER_VAR_229, strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_230[currStrOff] = 0;
                }
                char * line =  ____BAH_COMPILER_VAR_230;
char * ____BAH_COMPILER_VAR_231 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n    //Verbose Runtime\n        printf(\"[VO] calling: ");
long int strLen_1 = strlen(nameColor);
long int strLen_2 = strlen(fn->name);
long int strLen_3 = strlen(ASCII_RESET);
long int strLen_4 = strlen("(");
long int strLen_5 = strlen(fnArgs);
long int strLen_6 = strlen(") -> ");
long int strLen_7 = strlen(ASCII_GREEN);
long int strLen_8 = strlen(line);
long int strLen_9 = strlen(ASCII_RESET);
long int strLen_10 = strlen("\\n\"");
long int strLen_11 = strlen(fnArgsValues);
long int strLen_12 = strlen(");\n    //\n    ");
;                            
                    ____BAH_COMPILER_VAR_231 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12);
                    
                    memcpy(____BAH_COMPILER_VAR_231+currStrOff, "\n    //Verbose Runtime\n        printf(\"[VO] calling: ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_231+currStrOff, nameColor, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_231+currStrOff, fn->name, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_231+currStrOff, ASCII_RESET, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_231+currStrOff, "(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_231+currStrOff, fnArgs, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_231+currStrOff, ") -> ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_231+currStrOff, ASCII_GREEN, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_231+currStrOff, line, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_231+currStrOff, ASCII_RESET, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_231+currStrOff, "\\n\"", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_231+currStrOff, fnArgsValues, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_231+currStrOff, ");\n    //\n    ", strLen_12);
                    currStrOff += strLen_12;
                    
                    ____BAH_COMPILER_VAR_231[currStrOff] = 0;
                }
                struct rope* verboseOut =  rope(____BAH_COMPILER_VAR_231);
if (isGlobal()) {
INIT =  INIT->add(INIT, verboseOut);
}
else {
OUTPUT =  OUTPUT->add(OUTPUT, verboseOut);
}
};
void verboseOutOper(struct Tok pt,struct Tok nt,long int lineNb,struct Elems* elems){
if ((verboseOutGuard()==false)) {
return;
}
struct verboseOutVar pvo =  verboseOutTransformTok(pt,elems);
struct verboseOutVar nvo =  verboseOutTransformTok(nt,elems);
char * ____BAH_COMPILER_VAR_232 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(pvo.content);
long int strLen_1 = strlen(nvo.content);
;                            
                    ____BAH_COMPILER_VAR_232 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_232+currStrOff, pvo.content, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_232+currStrOff, nvo.content, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_232[currStrOff] = 0;
                }
                char * values =  ____BAH_COMPILER_VAR_232;
char * ____BAH_COMPILER_VAR_233 =intToStr(lineNb);char * ____BAH_COMPILER_VAR_234 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(compilerState.currentFile);
long int strLen_1 = strlen(":");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_233);
;                            
                    ____BAH_COMPILER_VAR_234 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_234+currStrOff, compilerState.currentFile, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_234+currStrOff, ":", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_234+currStrOff, ____BAH_COMPILER_VAR_233, strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_234[currStrOff] = 0;
                }
                char * line =  ____BAH_COMPILER_VAR_234;
char * ____BAH_COMPILER_VAR_235 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n    //Verbose Runtime\n        printf(\"[VO]    oper: ");
long int strLen_1 = strlen(pvo.markup);
long int strLen_2 = strlen(" AND ");
long int strLen_3 = strlen(nvo.markup);
long int strLen_4 = strlen(" -> ");
long int strLen_5 = strlen(ASCII_GREEN);
long int strLen_6 = strlen(line);
long int strLen_7 = strlen(ASCII_RESET);
long int strLen_8 = strlen("\\n\"");
long int strLen_9 = strlen(values);
long int strLen_10 = strlen(");\n    //\n    ");
;                            
                    ____BAH_COMPILER_VAR_235 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10);
                    
                    memcpy(____BAH_COMPILER_VAR_235+currStrOff, "\n    //Verbose Runtime\n        printf(\"[VO]    oper: ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_235+currStrOff, pvo.markup, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_235+currStrOff, " AND ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_235+currStrOff, nvo.markup, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_235+currStrOff, " -> ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_235+currStrOff, ASCII_GREEN, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_235+currStrOff, line, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_235+currStrOff, ASCII_RESET, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_235+currStrOff, "\\n\"", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_235+currStrOff, values, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_235+currStrOff, ");\n    //\n    ", strLen_10);
                    currStrOff += strLen_10;
                    
                    ____BAH_COMPILER_VAR_235[currStrOff] = 0;
                }
                struct rope* verboseOut =  rope(____BAH_COMPILER_VAR_235);
if (isGlobal()) {
INIT =  INIT->add(INIT, verboseOut);
}
else {
OUTPUT =  OUTPUT->add(OUTPUT, verboseOut);
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
struct fileStream ____BAH_COMPILER_VAR_236 = {};
____BAH_COMPILER_VAR_236.handle= null;
____BAH_COMPILER_VAR_236.isValid = fileStream__isValid;
____BAH_COMPILER_VAR_236.open = fileStream__open;
____BAH_COMPILER_VAR_236.close = fileStream__close;
____BAH_COMPILER_VAR_236.getPos = fileStream__getPos;
____BAH_COMPILER_VAR_236.setPos = fileStream__setPos;
____BAH_COMPILER_VAR_236.getSize = fileStream__getSize;
____BAH_COMPILER_VAR_236.rewind = fileStream__rewind;
____BAH_COMPILER_VAR_236.getChar = fileStream__getChar;
____BAH_COMPILER_VAR_236.setChar = fileStream__setChar;
____BAH_COMPILER_VAR_236.createFile = fileStream__createFile;
____BAH_COMPILER_VAR_236.writeFile = fileStream__writeFile;
____BAH_COMPILER_VAR_236.writePtr = fileStream__writePtr;
____BAH_COMPILER_VAR_236.readPtr = fileStream__readPtr;
____BAH_COMPILER_VAR_236.readContent = fileStream__readContent;
____BAH_COMPILER_VAR_236.readBytes = fileStream__readBytes;
____BAH_COMPILER_VAR_236.writeBytes = fileStream__writeBytes;
struct fileStream fs =  ____BAH_COMPILER_VAR_236;
char * ____BAH_COMPILER_VAR_237 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen("cache/cache.json");
;                            
                    ____BAH_COMPILER_VAR_237 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_237+currStrOff, BAH_DIR, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_237+currStrOff, "cache/cache.json", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_237[currStrOff] = 0;
                }
                fs.open((struct fileStream*)&fs,____BAH_COMPILER_VAR_237,"r");
if ((fs.isValid((struct fileStream*)&fs)==0)) {
char * ____BAH_COMPILER_VAR_238 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen("cache");
;                            
                    ____BAH_COMPILER_VAR_238 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_238+currStrOff, BAH_DIR, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_238+currStrOff, "cache", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_238[currStrOff] = 0;
                }
                mkdir(____BAH_COMPILER_VAR_238,S_IRWXU);
char * ____BAH_COMPILER_VAR_239 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen("cache/cache.json");
;                            
                    ____BAH_COMPILER_VAR_239 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_239+currStrOff, BAH_DIR, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_239+currStrOff, "cache/cache.json", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_239[currStrOff] = 0;
                }
                fs.createFile((struct fileStream*)&fs,____BAH_COMPILER_VAR_239);
return;
}
char * ____BAH_COMPILER_VAR_240 =fs.readContent((struct fileStream*)&fs);struct jsonElement* j =  parseJson(____BAH_COMPILER_VAR_240);
fs.close((struct fileStream*)&fs);
array(struct cacheFile**)* ____BAH_COMPILER_VAR_241 = &cache;
struct cacheFile*** ____BAH_COMPILER_VAR_242 = 0;
char ** ____BAH_COMPILER_VAR_244 = (char **)((char*)(____BAH_COMPILER_VAR_242) + offsetof(struct cacheFile, file));
struct reflectElement ____BAH_COMPILER_VAR_245 = __reflect(____BAH_COMPILER_VAR_244, sizeof(char *), "cpstring", "file", 0, 0, 0, 0, offsetof(struct cacheFile, file));
long int* ____BAH_COMPILER_VAR_246 = (long int*)((char*)(____BAH_COMPILER_VAR_242) + offsetof(struct cacheFile, last));
struct reflectElement ____BAH_COMPILER_VAR_247 = __reflect(____BAH_COMPILER_VAR_246, sizeof(long int), "int", "last", 0, 0, 0, 0, offsetof(struct cacheFile, last));
char ** ____BAH_COMPILER_VAR_248 = (char **)((char*)(____BAH_COMPILER_VAR_242) + offsetof(struct cacheFile, ver));
struct reflectElement ____BAH_COMPILER_VAR_249 = __reflect(____BAH_COMPILER_VAR_248, sizeof(char *), "cpstring", "ver", 0, 0, 0, 0, offsetof(struct cacheFile, ver));
long int* ____BAH_COMPILER_VAR_250 = (long int*)((char*)(____BAH_COMPILER_VAR_242) + offsetof(struct cacheFile, date));
struct reflectElement ____BAH_COMPILER_VAR_251 = __reflect(____BAH_COMPILER_VAR_250, sizeof(long int), "int", "date", 0, 0, 0, 0, offsetof(struct cacheFile, date));
long int* ____BAH_COMPILER_VAR_252 = (long int*)((char*)(____BAH_COMPILER_VAR_242) + offsetof(struct cacheFile, mem));
struct reflectElement ____BAH_COMPILER_VAR_253 = __reflect(____BAH_COMPILER_VAR_252, sizeof(long int), "int", "mem", 0, 0, 0, 0, offsetof(struct cacheFile, mem));
array(char *)** ____BAH_COMPILER_VAR_254 = (array(char *)**)((char*)(____BAH_COMPILER_VAR_242) + offsetof(struct cacheFile, files));
char ** ____BAH_COMPILER_VAR_255 = 0;
struct reflectElement ____BAH_COMPILER_VAR_256 = __reflect(____BAH_COMPILER_VAR_255, sizeof(char *), "cpstring", "", 0, 0, 0, 0, 0);

        struct reflectElement ____BAH_COMPILER_VAR_257 = ____BAH_COMPILER_VAR_256;
        struct reflectElement ____BAH_COMPILER_VAR_258 = __reflect(____BAH_COMPILER_VAR_254, sizeof(array(char *)*), "[]cpstring", "files", 1, &____BAH_COMPILER_VAR_257, 0, 0, offsetof(struct cacheFile, files));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_243 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_243->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_243->length = 6;
        ____BAH_COMPILER_VAR_243->data = memoryAlloc(____BAH_COMPILER_VAR_243->length * ____BAH_COMPILER_VAR_243->elemSize);
        ____BAH_COMPILER_VAR_243->data[0] = ____BAH_COMPILER_VAR_245;
____BAH_COMPILER_VAR_243->data[1] = ____BAH_COMPILER_VAR_247;
____BAH_COMPILER_VAR_243->data[2] = ____BAH_COMPILER_VAR_249;
____BAH_COMPILER_VAR_243->data[3] = ____BAH_COMPILER_VAR_251;
____BAH_COMPILER_VAR_243->data[4] = ____BAH_COMPILER_VAR_253;
____BAH_COMPILER_VAR_243->data[5] = ____BAH_COMPILER_VAR_258;
struct reflectElement ____BAH_COMPILER_VAR_259 = __reflect(____BAH_COMPILER_VAR_242, sizeof(struct cacheFile), "cacheFile**", "", 0, 0, 1, ____BAH_COMPILER_VAR_243, 0);

        struct reflectElement ____BAH_COMPILER_VAR_260 = ____BAH_COMPILER_VAR_259;
        struct reflectElement ____BAH_COMPILER_VAR_261 = __reflect(____BAH_COMPILER_VAR_241, sizeof(array(struct cacheFile**)*), "[]cacheFile**", "&cache", 1, &____BAH_COMPILER_VAR_260, 0, 0, 0);
j->scan((struct jsonElement*)j,____BAH_COMPILER_VAR_261);
if ((cache!=null)) {
}
};
struct cacheFile* getCacheFile(char * s){
if ((cache==null)) {
return null;
}
long int i =  0;
for (; (i<len(cache)); i =  i+1) {

                    if (cache->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/cache.bah:44): cache[%d] with length %d\n", i, cache->length);
                        exit(1);
                    };
                    struct cacheFile* c =  cache->data[i];
if (((strcmp(c->file, s) == 0)&&(c->mem==RCPlevel))) {
return c;
}
};
return null;
};
void updateCacheFile(struct cacheFile* c){
c->last =  getLastModified(c->file);
c->ver =  BAH_VERSION;
c->date =  getTimeUnix();
};
void makeCacheFile(char * f){
struct cacheFile* ____BAH_COMPILER_VAR_262 = memoryAlloc(sizeof(struct cacheFile));
____BAH_COMPILER_VAR_262->file= null;
____BAH_COMPILER_VAR_262->ver= null;
____BAH_COMPILER_VAR_262->files = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_262->files->length = 0;
            ____BAH_COMPILER_VAR_262->files->elemSize = sizeof(char *);
            struct cacheFile* c =  ____BAH_COMPILER_VAR_262;
c->file =  f;
c->ver =  BAH_VERSION;
c->mem =  RCPlevel;
c->date =  getTimeUnix();
c->last =  getLastModified(f);
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
cache->data[len(cache)] =  c;
cache->length = nLength+1;
} else {
cache->data[len(cache)] =  c;
}
};
};
void writeCache(){
struct fileStream ____BAH_COMPILER_VAR_263 = {};
____BAH_COMPILER_VAR_263.handle= null;
____BAH_COMPILER_VAR_263.isValid = fileStream__isValid;
____BAH_COMPILER_VAR_263.open = fileStream__open;
____BAH_COMPILER_VAR_263.close = fileStream__close;
____BAH_COMPILER_VAR_263.getPos = fileStream__getPos;
____BAH_COMPILER_VAR_263.setPos = fileStream__setPos;
____BAH_COMPILER_VAR_263.getSize = fileStream__getSize;
____BAH_COMPILER_VAR_263.rewind = fileStream__rewind;
____BAH_COMPILER_VAR_263.getChar = fileStream__getChar;
____BAH_COMPILER_VAR_263.setChar = fileStream__setChar;
____BAH_COMPILER_VAR_263.createFile = fileStream__createFile;
____BAH_COMPILER_VAR_263.writeFile = fileStream__writeFile;
____BAH_COMPILER_VAR_263.writePtr = fileStream__writePtr;
____BAH_COMPILER_VAR_263.readPtr = fileStream__readPtr;
____BAH_COMPILER_VAR_263.readContent = fileStream__readContent;
____BAH_COMPILER_VAR_263.readBytes = fileStream__readBytes;
____BAH_COMPILER_VAR_263.writeBytes = fileStream__writeBytes;
struct fileStream fs =  ____BAH_COMPILER_VAR_263;
char * ____BAH_COMPILER_VAR_264 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen("cache/cache.json");
;                            
                    ____BAH_COMPILER_VAR_264 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_264+currStrOff, BAH_DIR, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_264+currStrOff, "cache/cache.json", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_264[currStrOff] = 0;
                }
                fs.open((struct fileStream*)&fs,____BAH_COMPILER_VAR_264,"w");
array(struct cacheFile*)* ____BAH_COMPILER_VAR_265 = cache;
struct cacheFile** ____BAH_COMPILER_VAR_266 = 0;
char ** ____BAH_COMPILER_VAR_268 = (char **)((char*)(____BAH_COMPILER_VAR_266) + offsetof(struct cacheFile, file));
struct reflectElement ____BAH_COMPILER_VAR_269 = __reflect(____BAH_COMPILER_VAR_268, sizeof(char *), "cpstring", "file", 0, 0, 0, 0, offsetof(struct cacheFile, file));
long int* ____BAH_COMPILER_VAR_270 = (long int*)((char*)(____BAH_COMPILER_VAR_266) + offsetof(struct cacheFile, last));
struct reflectElement ____BAH_COMPILER_VAR_271 = __reflect(____BAH_COMPILER_VAR_270, sizeof(long int), "int", "last", 0, 0, 0, 0, offsetof(struct cacheFile, last));
char ** ____BAH_COMPILER_VAR_272 = (char **)((char*)(____BAH_COMPILER_VAR_266) + offsetof(struct cacheFile, ver));
struct reflectElement ____BAH_COMPILER_VAR_273 = __reflect(____BAH_COMPILER_VAR_272, sizeof(char *), "cpstring", "ver", 0, 0, 0, 0, offsetof(struct cacheFile, ver));
long int* ____BAH_COMPILER_VAR_274 = (long int*)((char*)(____BAH_COMPILER_VAR_266) + offsetof(struct cacheFile, date));
struct reflectElement ____BAH_COMPILER_VAR_275 = __reflect(____BAH_COMPILER_VAR_274, sizeof(long int), "int", "date", 0, 0, 0, 0, offsetof(struct cacheFile, date));
long int* ____BAH_COMPILER_VAR_276 = (long int*)((char*)(____BAH_COMPILER_VAR_266) + offsetof(struct cacheFile, mem));
struct reflectElement ____BAH_COMPILER_VAR_277 = __reflect(____BAH_COMPILER_VAR_276, sizeof(long int), "int", "mem", 0, 0, 0, 0, offsetof(struct cacheFile, mem));
array(char *)** ____BAH_COMPILER_VAR_278 = (array(char *)**)((char*)(____BAH_COMPILER_VAR_266) + offsetof(struct cacheFile, files));
char ** ____BAH_COMPILER_VAR_279 = 0;
struct reflectElement ____BAH_COMPILER_VAR_280 = __reflect(____BAH_COMPILER_VAR_279, sizeof(char *), "cpstring", "", 0, 0, 0, 0, 0);

        struct reflectElement ____BAH_COMPILER_VAR_281 = ____BAH_COMPILER_VAR_280;
        struct reflectElement ____BAH_COMPILER_VAR_282 = __reflect(____BAH_COMPILER_VAR_278, sizeof(array(char *)*), "[]cpstring", "files", 1, &____BAH_COMPILER_VAR_281, 0, 0, offsetof(struct cacheFile, files));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_267 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_267->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_267->length = 6;
        ____BAH_COMPILER_VAR_267->data = memoryAlloc(____BAH_COMPILER_VAR_267->length * ____BAH_COMPILER_VAR_267->elemSize);
        ____BAH_COMPILER_VAR_267->data[0] = ____BAH_COMPILER_VAR_269;
____BAH_COMPILER_VAR_267->data[1] = ____BAH_COMPILER_VAR_271;
____BAH_COMPILER_VAR_267->data[2] = ____BAH_COMPILER_VAR_273;
____BAH_COMPILER_VAR_267->data[3] = ____BAH_COMPILER_VAR_275;
____BAH_COMPILER_VAR_267->data[4] = ____BAH_COMPILER_VAR_277;
____BAH_COMPILER_VAR_267->data[5] = ____BAH_COMPILER_VAR_282;
struct reflectElement ____BAH_COMPILER_VAR_283 = __reflect(____BAH_COMPILER_VAR_266, sizeof(struct cacheFile), "cacheFile*", "", 0, 0, 1, ____BAH_COMPILER_VAR_267, 0);

        struct reflectElement ____BAH_COMPILER_VAR_284 = ____BAH_COMPILER_VAR_283;
        struct reflectElement ____BAH_COMPILER_VAR_285 = __reflect(____BAH_COMPILER_VAR_265, sizeof(array(struct cacheFile*)*), "[]cacheFile*", "cache", 1, &____BAH_COMPILER_VAR_284, 0, 0, 0);
char * ____BAH_COMPILER_VAR_286 =toJson(____BAH_COMPILER_VAR_285);fs.writeFile((struct fileStream*)&fs,____BAH_COMPILER_VAR_286);
fs.close((struct fileStream*)&fs);
};
char isValidCacheFile(struct cacheFile* cf){
if (((cf==null)||(cf->last!=getLastModified(cf->file)))) {
return false;
}
char * ____BAH_COMPILER_VAR_287 =pathToVarName(cf->file);char * ____BAH_COMPILER_VAR_288 =intToStr(cf->mem);char * ____BAH_COMPILER_VAR_289 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen("cache/");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_287);
long int strLen_3 = strlen(____BAH_COMPILER_VAR_288);
long int strLen_4 = strlen(".o.o");
;                            
                    ____BAH_COMPILER_VAR_289 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_289+currStrOff, BAH_DIR, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_289+currStrOff, "cache/", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_289+currStrOff, ____BAH_COMPILER_VAR_287, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_289+currStrOff, ____BAH_COMPILER_VAR_288, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_289+currStrOff, ".o.o", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_289[currStrOff] = 0;
                }
                if ((fileExists(____BAH_COMPILER_VAR_289)==0)) {
return false;
}
if ((strcmp(cf->ver, BAH_VERSION) != 0)) {
return false;
}
return true;
};
//optimized out: debugLine
struct Elems* dupElems(struct Elems* elems){
struct Elems* ____BAH_COMPILER_VAR_291 = memoryAlloc(sizeof(struct Elems));
____BAH_COMPILER_VAR_291->vars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_291->vars->length = 0;
            ____BAH_COMPILER_VAR_291->vars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_291->structs = memoryAlloc(sizeof(array(struct cStruct*)));
            ____BAH_COMPILER_VAR_291->structs->length = 0;
            ____BAH_COMPILER_VAR_291->structs->elemSize = sizeof(struct cStruct*);
            ____BAH_COMPILER_VAR_291->types = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_291->types->length = 0;
            ____BAH_COMPILER_VAR_291->types->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_291->fns = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_291->fns->length = 0;
            ____BAH_COMPILER_VAR_291->fns->elemSize = sizeof(struct func*);
            struct Elems* nElems =  ____BAH_COMPILER_VAR_291;
long int j =  0;
for (; (j<len(elems->vars)); j =  j+1) {

                    if (elems->vars->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:29): elems->vars[%d] with length %d\n", j, elems->vars->length);
                        exit(1);
                    };
                    struct variable* v =  elems->vars->data[j];
struct variable* ____BAH_COMPILER_VAR_292 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_292->name = "";
____BAH_COMPILER_VAR_292->type = "";
____BAH_COMPILER_VAR_292->isConst = false;
____BAH_COMPILER_VAR_292->constVal = "";
____BAH_COMPILER_VAR_292->isArray = false;
____BAH_COMPILER_VAR_292->from = "";
____BAH_COMPILER_VAR_292->outterScope = false;
____BAH_COMPILER_VAR_292->isGlobal = false;
struct variable* nv =  ____BAH_COMPILER_VAR_292;
*nv =  *v;
nv->outterScope =  true;

{
long nLength = j;
if (nElems->vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nElems->vars->data, (nLength+50)*sizeof(struct variable*));
nElems->vars->data = newPtr;
}
nElems->vars->data[j] =  nv;
nElems->vars->length = nLength+1;
} else {
nElems->vars->data[j] =  nv;
}
};
};
nElems->structs =  elems->structs;
nElems->types =  elems->types;
nElems->fns =  elems->fns;
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

                    if (line->length <= 0) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:73): line[%d] with length %d\n", 0, line->length);
                        exit(1);
                    };
                    struct Tok ft =  line->data[0];
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
else if (((strcmp(ft.cont, "continue") == 0)||(strcmp(ft.cont, "break") == 0))) {
return LINE_TYPE_FOR_OPERATOR;
}
else {
return LINE_TYPE_PRE_KEYWORD;
}
}
else if ((ft.type==TOKEN_TYPE_VAR)) {
if ((len(line)==1)) {
throwErr(&ft,"Cannot declare var {TOKEN} without a type.");
}

                    if (line->length <= 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:112): line[%d] with length %d\n", 1, line->length);
                        exit(1);
                    };
                    struct Tok st =  line->data[1];
if (((st.type==TOKEN_TYPE_ENCL)&&(strcmp(st.cont, "(") == 0))) {

                    if (line->length <= len(line)-1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:114): line[%d] with length %d\n", len(line)-1, line->length);
                        exit(1);
                    };
                    struct Tok lt =  line->data[len(line)-1];
if (((lt.type==TOKEN_TYPE_ENCL)&&(strcmp(lt.cont, "}") == 0))) {
return LINE_TYPE_FN_DECL;
}
return LINE_TYPE_FN_CALL;
}
return LINE_TYPE_VAR;
}
return (lineType)-1;
};
__BAH_ARR_TYPE_Tok parseCast(__BAH_ARR_TYPE_Tok line,struct Elems* elems){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
long int i =  0;
while ((i<len(line))) {

                    if (line->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:133): line[%d] with length %d\n", i, line->length);
                        exit(1);
                    };
                    struct Tok t =  line->data[i];
if ((strcmp(t.cont, "<") == 0)) {
break;
}

{
long nLength = i;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[i] =  t;
nl->length = nLength+1;
} else {
nl->data[i] =  t;
}
};
i =  i + 1;
};
if ((i==len(line))) {
return line;
}
for (; (i<len(line)); i =  i+1) {

                    if (line->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:145): line[%d] with length %d\n", i, line->length);
                        exit(1);
                    };
                    struct Tok t =  line->data[i];
if ((t.type==TOKEN_TYPE_SYNTAX)) {
if ((strcmp(t.cont, "<") == 0)) {
if ((i + 3<len(line))) {

                    if (line->length <= i + 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:149): line[%d] with length %d\n", i + 1, line->length);
                        exit(1);
                    };
                    struct Tok nt =  line->data[i + 1];

                    if (line->length <= i + 2) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:150): line[%d] with length %d\n", i + 2, line->length);
                        exit(1);
                    };
                    struct Tok nnt =  line->data[i + 2];

                    if (line->length <= i + 3) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:151): line[%d] with length %d\n", i + 3, line->length);
                        exit(1);
                    };
                    struct Tok nnnt =  line->data[i + 3];
if ((nt.type==TOKEN_TYPE_VAR)) {
if ((nnt.type==TOKEN_TYPE_SYNTAX)) {
if ((strcmp(nnt.cont, ">") == 0)) {
nnnt.bahType =  nt.cont;
struct string cCast =  getCType(nt.cont,elems);
char * cCastStr =  cCast.str((struct string*)&cCast);
char * ____BAH_COMPILER_VAR_293 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("(");
long int strLen_1 = strlen(cCastStr);
long int strLen_2 = strlen(")");
long int strLen_3 = strlen(nnnt.cont);
;                            
                    ____BAH_COMPILER_VAR_293 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                    
                    memcpy(____BAH_COMPILER_VAR_293+currStrOff, "(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_293+currStrOff, cCastStr, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_293+currStrOff, ")", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_293+currStrOff, nnnt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    ____BAH_COMPILER_VAR_293[currStrOff] = 0;
                }
                nnnt.cont =  ____BAH_COMPILER_VAR_293;

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  nnnt;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  nnnt;
}
};
i =  i + 3;
continue;
}
}
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
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
}
};
};
return nl;
};
char * getDirFromFile(char * f){
char * ____BAH_COMPILER_VAR_294 =__STR(f);array(char)* p =  strAsArr(____BAH_COMPILER_VAR_294);
long int i =  len(p)-1;
while ((i>=0)) {

                    if (p->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:179): p[%d] with length %d\n", i, p->length);
                        exit(1);
                    };
                    char c =  p->data[i];
if ((c==47)) {

{
long nLength = i + 1;
if (p->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(p->data, (nLength+50)*sizeof(char));
p->data = newPtr;
}
p->data[i + 1] =  (char)0;
p->length = nLength+1;
} else {
p->data[i + 1] =  (char)0;
}
};
break;
}
i =  i - 1;
};
if ((i<=0)) {
return "";
}
return arrAsStr(p);
};
void parseLines(__BAH_ARR_TYPE_Tok ts,struct Elems* elems);
char includeFile(char * ccstr,struct Elems* elems){
if ((strcmp(ccstr, "BAH_MEM_COLLECTOR") == 0)) {
if ((RCPenabled==true)) {
if (flags.isSet((struct flags*)&flags,"rcp")) {
ccstr =  "rcp.bah";
}
else if (flags.isSet((struct flags*)&flags,"fastrcp")) {
ccstr =  "fastrcp.bah";
}
}
else {
ccstr =  "gc.bah";
}
}

                int ____BAH_COMPILER_VAR_295 = 0;
                for(int i=len(compilerState.includes)-1; i != -1; i--) {
                    if (compilerState.includes->data[i] != 0 && strcmp(compilerState.includes->data[i], ccstr) == 0) {
                        ____BAH_COMPILER_VAR_295 = 1;
                        break;
                    };
                };
                if (____BAH_COMPILER_VAR_295) {
return true;
}
struct fileMap ____BAH_COMPILER_VAR_296 = {};
____BAH_COMPILER_VAR_296.handle = -1;
____BAH_COMPILER_VAR_296.p= null;
____BAH_COMPILER_VAR_296.open = fileMap__open;
____BAH_COMPILER_VAR_296.isValid = fileMap__isValid;
____BAH_COMPILER_VAR_296.close = fileMap__close;
struct fileMap fm =  ____BAH_COMPILER_VAR_296;
char * ____BAH_COMPILER_VAR_297 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen(ccstr);
;                            
                    ____BAH_COMPILER_VAR_297 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_297+currStrOff, BAH_DIR, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_297+currStrOff, ccstr, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_297[currStrOff] = 0;
                }
                char * fileName =  ____BAH_COMPILER_VAR_297;
char isBahDir =  true;
char * f =  fm.open((struct fileMap*)&fm,fileName);
if ((fm.isValid((struct fileMap*)&fm)==0)) {
char * ____BAH_COMPILER_VAR_298 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(compilerState.currentDir);
long int strLen_1 = strlen(ccstr);
;                            
                    ____BAH_COMPILER_VAR_298 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_298+currStrOff, compilerState.currentDir, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_298+currStrOff, ccstr, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_298[currStrOff] = 0;
                }
                fileName =  absPath(____BAH_COMPILER_VAR_298);
f =  fm.open((struct fileMap*)&fm,fileName);
isBahDir =  false;
if ((fm.isValid((struct fileMap*)&fm)==0)) {
return false;
}
}
char * oDir =  compilerState.currentDir;
if ((isBahDir==false)) {
char * ____BAH_COMPILER_VAR_299 =getDirFromFile(ccstr);char * ____BAH_COMPILER_VAR_300 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(compilerState.currentDir);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_299);
;                            
                    ____BAH_COMPILER_VAR_300 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_300+currStrOff, compilerState.currentDir, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_300+currStrOff, ____BAH_COMPILER_VAR_299, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_300[currStrOff] = 0;
                }
                compilerState.currentDir =  ____BAH_COMPILER_VAR_300;
}
else {
char * ____BAH_COMPILER_VAR_301 =getDirFromFile(ccstr);char * ____BAH_COMPILER_VAR_302 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_301);
;                            
                    ____BAH_COMPILER_VAR_302 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_302+currStrOff, BAH_DIR, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_302+currStrOff, ____BAH_COMPILER_VAR_301, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_302[currStrOff] = 0;
                }
                compilerState.currentDir =  ____BAH_COMPILER_VAR_302;
}
char * oFile =  compilerState.currentFile;
compilerState.currentFile =  fileName;

{
long nLength = len(compilerState.includes);
if (compilerState.includes->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(compilerState.includes->data, (nLength+50)*sizeof(char *));
compilerState.includes->data = newPtr;
}
compilerState.includes->data[len(compilerState.includes)] =  ccstr;
compilerState.includes->length = nLength+1;
} else {
compilerState.includes->data[len(compilerState.includes)] =  ccstr;
}
};
array(struct Tok)* tokens =  lexer(f);
fm.close((struct fileMap*)&fm);
if ((len(tokens)==0)) {
char * ____BAH_COMPILER_VAR_303 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("File '");
long int strLen_1 = strlen(ccstr);
long int strLen_2 = strlen("' not recognized.");
;                            
                    ____BAH_COMPILER_VAR_303 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_303+currStrOff, "File '", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_303+currStrOff, ccstr, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_303+currStrOff, "' not recognized.", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_303[currStrOff] = 0;
                }
                __BAH_panic(____BAH_COMPILER_VAR_303,"/home/alois/Documents/bah-bah/src/parser.bah:246");
}
char oshd =  shouldOnlyDecl;
if ((isObject==true)) {
shouldOnlyDecl =  true;
}
else if ((isSubObject==true)) {
shouldOnlyDecl =  false;
}
parseLines(tokens,elems);
shouldOnlyDecl =  oshd;
compilerState.currentFile =  oFile;
compilerState.currentDir =  oDir;
return true;
};
void parallelObjCompile(char * fn,char * oName,struct channel * done){
readCache();
struct cacheFile* cf =  getCacheFile(fn);
char * wrkd =  getCurrentPath();
char * rcp =  "";
if ((RCPlevel==1)) {
rcp =  "-rcp";
}
else if ((RCPlevel==2)) {
rcp =  "-fastrcp";
}
if ((isValidCacheFile(cf)==false)) {
setCurrentPath(compilerState.currentDir);
char * verboseCC =  "";
if ((flags.isSet((struct flags*)&flags,"verboseCC")==1)) {
verboseCC =  "-verboseCC";
}
char * ____BAH_COMPILER_VAR_304 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(execName);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(fn);
long int strLen_3 = strlen(" ");
long int strLen_4 = strlen(rcp);
long int strLen_5 = strlen(" -object ");
long int strLen_6 = strlen(verboseCC);
long int strLen_7 = strlen(" -o ");
long int strLen_8 = strlen(oName);
;                            
                    ____BAH_COMPILER_VAR_304 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                    
                    memcpy(____BAH_COMPILER_VAR_304+currStrOff, execName, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_304+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_304+currStrOff, fn, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_304+currStrOff, " ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_304+currStrOff, rcp, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_304+currStrOff, " -object ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_304+currStrOff, verboseCC, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_304+currStrOff, " -o ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_304+currStrOff, oName, strLen_8);
                    currStrOff += strLen_8;
                    
                    ____BAH_COMPILER_VAR_304[currStrOff] = 0;
                }
                struct command cmd =  command(____BAH_COMPILER_VAR_304);
char * res =  cmd.run((struct command*)&cmd);
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

                    char ____BAH_COMPILER_VAR_305 = true;
                    done->sendAny(done, &____BAH_COMPILER_VAR_305, sizeof(____BAH_COMPILER_VAR_305));
};
void parseImport(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
compilerState.hasImports =  true;
if ((len(l)!=2)) {
throwErr(&l->data[0],"Invalid usage of {TOKEN}.");
}

                    if (l->length <= 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:308): l[%d] with length %d\n", 1, l->length);
                        exit(1);
                    };
                    struct Tok strt =  l->data[1];
if ((strt.type!=TOKEN_TYPE_STR)) {
throwErr(&strt,"Cannot use {TOKEN} as file name (#import \"file\")");
}
struct string fileName =  string(strt.cont);
fileName.trimLeft((struct string*)&fileName,1);
fileName.trimRight((struct string*)&fileName,1);

                int ____BAH_COMPILER_VAR_306 = 0;
                for(int i=len(compilerState.includes)-1; i != -1; i--) {
                    if (compilerState.includes->data[i] != 0 && strcmp(compilerState.includes->data[i], fileName.str((struct string*)&fileName)) == 0) {
                        ____BAH_COMPILER_VAR_306 = 1;
                        break;
                    };
                };
                if (____BAH_COMPILER_VAR_306) {
return;
}

{
long nLength = len(compilerState.includes);
if (compilerState.includes->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(compilerState.includes->data, (nLength+50)*sizeof(char *));
compilerState.includes->data = newPtr;
}
compilerState.includes->data[len(compilerState.includes)] =  fileName.str((struct string*)&fileName);
compilerState.includes->length = nLength+1;
} else {
compilerState.includes->data[len(compilerState.includes)] =  fileName.str((struct string*)&fileName);
}
};
char * ____BAH_COMPILER_VAR_307 =fileName.str((struct string*)&fileName);char * fn =  absPath(____BAH_COMPILER_VAR_307);
if (((void *)fn==null)) {
char * ____BAH_COMPILER_VAR_308 =fileName.str((struct string*)&fileName);char * ____BAH_COMPILER_VAR_309 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_308);
;                            
                    ____BAH_COMPILER_VAR_309 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_309+currStrOff, BAH_DIR, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_309+currStrOff, ____BAH_COMPILER_VAR_308, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_309[currStrOff] = 0;
                }
                fn =  absPath(____BAH_COMPILER_VAR_309);
if (((void *)fn==null)) {
throwErr(&strt,"Unknown file {TOKEN}.");
}
}
char * of =  compilerState.currentFile;
char * od =  compilerState.currentDir;
compilerState.currentFile =  fn;
compilerState.currentDir =  getDirFromFile(fn);
struct fileStream ____BAH_COMPILER_VAR_310 = {};
____BAH_COMPILER_VAR_310.handle= null;
____BAH_COMPILER_VAR_310.isValid = fileStream__isValid;
____BAH_COMPILER_VAR_310.open = fileStream__open;
____BAH_COMPILER_VAR_310.close = fileStream__close;
____BAH_COMPILER_VAR_310.getPos = fileStream__getPos;
____BAH_COMPILER_VAR_310.setPos = fileStream__setPos;
____BAH_COMPILER_VAR_310.getSize = fileStream__getSize;
____BAH_COMPILER_VAR_310.rewind = fileStream__rewind;
____BAH_COMPILER_VAR_310.getChar = fileStream__getChar;
____BAH_COMPILER_VAR_310.setChar = fileStream__setChar;
____BAH_COMPILER_VAR_310.createFile = fileStream__createFile;
____BAH_COMPILER_VAR_310.writeFile = fileStream__writeFile;
____BAH_COMPILER_VAR_310.writePtr = fileStream__writePtr;
____BAH_COMPILER_VAR_310.readPtr = fileStream__readPtr;
____BAH_COMPILER_VAR_310.readContent = fileStream__readContent;
____BAH_COMPILER_VAR_310.readBytes = fileStream__readBytes;
____BAH_COMPILER_VAR_310.writeBytes = fileStream__writeBytes;
struct fileStream fs =  ____BAH_COMPILER_VAR_310;
fs.open((struct fileStream*)&fs,fn,"r");
char * f =  fs.readContent((struct fileStream*)&fs);
fs.close((struct fileStream*)&fs);
array(struct Tok)* tokens =  lexer(f);
char osod =  shouldOnlyDecl;
shouldOnlyDecl =  true;
char oiso =  isSubObject;
isSubObject =  true;
char * ____BAH_COMPILER_VAR_311 =pathToVarName(fn);char * ____BAH_COMPILER_VAR_312 =intToStr(RCPlevel);char * ____BAH_COMPILER_VAR_313 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen("cache/");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_311);
long int strLen_3 = strlen(____BAH_COMPILER_VAR_312);
long int strLen_4 = strlen(".o");
;                            
                    ____BAH_COMPILER_VAR_313 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_313+currStrOff, BAH_DIR, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_313+currStrOff, "cache/", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_313+currStrOff, ____BAH_COMPILER_VAR_311, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_313+currStrOff, ____BAH_COMPILER_VAR_312, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_313+currStrOff, ".o", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_313[currStrOff] = 0;
                }
                char * oName =  ____BAH_COMPILER_VAR_313;
char * ____BAH_COMPILER_VAR_314 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("w ");
long int strLen_1 = strlen(oName);
long int strLen_2 = strlen(".o");
;                            
                    ____BAH_COMPILER_VAR_314 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_314+currStrOff, "w ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_314+currStrOff, oName, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_314+currStrOff, ".o", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_314[currStrOff] = 0;
                }
                
{
long nLength = len(compilerState.cLibs);
if (compilerState.cLibs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(compilerState.cLibs->data, (nLength+50)*sizeof(char *));
compilerState.cLibs->data = newPtr;
}
compilerState.cLibs->data[len(compilerState.cLibs)] =  ____BAH_COMPILER_VAR_314;
compilerState.cLibs->length = nLength+1;
} else {
compilerState.cLibs->data[len(compilerState.cLibs)] =  ____BAH_COMPILER_VAR_314;
}
};
struct channel * done = channel();
parallelObjCompile(fn,oName,done);
parseLines(tokens,elems);
char ok =  *(char*)done->receive(done);
char * ____BAH_COMPILER_VAR_315 =pathToVarName(fn);char * ____BAH_COMPILER_VAR_316 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("__BAH_init");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_315);
long int strLen_2 = strlen("();\n");
;                            
                    ____BAH_COMPILER_VAR_316 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_316+currStrOff, "__BAH_init", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_316+currStrOff, ____BAH_COMPILER_VAR_315, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_316+currStrOff, "();\n", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_316[currStrOff] = 0;
                }
                INIT =  INIT->add(INIT, rope(____BAH_COMPILER_VAR_316));
writeCache();
shouldOnlyDecl =  osod;
isSubObject =  oiso;
compilerState.currentFile =  of;
compilerState.currentDir =  od;
};
void parseInclude(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
if ((len(l)>2)) {
throwErr(&l->data[len(l)-1],"Invalid usage of include, ending by {TOKEN}.");
}

                    if (l->length <= 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:392): l[%d] with length %d\n", 1, l->length);
                        exit(1);
                    };
                    struct Tok strt =  l->data[1];
if ((strt.type!=TOKEN_TYPE_STR)) {
throwErr(&strt,"Cannot use {TOKEN} as string in include.");
}
char * sc =  strt.cont;
strTrimLeft(&sc,1);
strTrimRight(&sc,1);
if (((strHasPrefix(sc,"<")||strHasSuffix(sc,".h"))||strHasSuffix(sc,".c"))) {
char * ____BAH_COMPILER_VAR_317 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("#include ");
long int strLen_1 = strlen(sc);
long int strLen_2 = strlen("\n");
;                            
                    ____BAH_COMPILER_VAR_317 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_317+currStrOff, "#include ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_317+currStrOff, sc, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_317+currStrOff, "\n", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_317[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_317));

{
long nLength = len(compilerState.cIncludes);
if (compilerState.cIncludes->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(compilerState.cIncludes->data, (nLength+50)*sizeof(char *));
compilerState.cIncludes->data = newPtr;
}
compilerState.cIncludes->data[len(compilerState.cIncludes)] =  sc;
compilerState.cIncludes->length = nLength+1;
} else {
compilerState.cIncludes->data[len(compilerState.cIncludes)] =  sc;
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
__BAH_ARR_TYPE_Tok parseOperations(__BAH_ARR_TYPE_Tok line,lineType ltp,struct Elems* elems){

                    if (line->length <= 0) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:414): line[%d] with length %d\n", 0, line->length);
                        exit(1);
                    };
                    array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 1;
nl->elemSize = sizeof(struct Tok);
nl->data = memoryAlloc(sizeof(struct Tok) * 50);nl->data[0] = line->data[0];

                    if (line->length <= 0) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:415): line[%d] with length %d\n", 0, line->length);
                        exit(1);
                    };
                    array(struct Tok)* unNestedLine = memoryAlloc(sizeof(array(struct Tok)));

unNestedLine->length = 1;
unNestedLine->elemSize = sizeof(struct Tok);
unNestedLine->data = memoryAlloc(sizeof(struct Tok) * 50);unNestedLine->data[0] = line->data[0];
long int i =  1;
for (; (i<len(line)); i =  i+1) {

                    if (line->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:418): line[%d] with length %d\n", i, line->length);
                        exit(1);
                    };
                    struct Tok t =  line->data[i];

                    if (line->length <= i-1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:419): line[%d] with length %d\n", i-1, line->length);
                        exit(1);
                    };
                    struct Tok pt =  line->data[i-1];
if (((strcmp(t.cont, "(") == 0)&&(pt.type!=TOKEN_TYPE_KEYWORD))) {
long int nbPars =  1;
i =  i+1;
array(struct Tok)* mem = memoryAlloc(sizeof(array(struct Tok)));

mem->length = 0;
mem->elemSize = sizeof(struct Tok);
struct Tok ft =  t;
for (; (i<len(line)); i =  i+1) {

                    if (line->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:427): line[%d] with length %d\n", i, line->length);
                        exit(1);
                    };
                    t =  line->data[i];

                    if (line->length <= i-1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:428): line[%d] with length %d\n", i-1, line->length);
                        exit(1);
                    };
                    pt =  line->data[i-1];
if (((strcmp(t.cont, "(") == 0)&&(pt.type!=TOKEN_TYPE_KEYWORD))) {
nbPars =  nbPars+1;
}
else if ((strcmp(t.cont, ")") == 0)) {
nbPars =  nbPars-1;
}
if ((nbPars==0)) {
break;
}

{
long nLength = len(mem);
if (mem->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(mem->data, (nLength+50)*sizeof(struct Tok));
mem->data = newPtr;
}
mem->data[len(mem)] =  t;
mem->length = nLength+1;
} else {
mem->data[len(mem)] =  t;
}
};
};
if ((len(mem)==0)) {

{
long nLength = len(unNestedLine);
if (unNestedLine->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(unNestedLine->data, (nLength+50)*sizeof(struct Tok));
unNestedLine->data = newPtr;
}
unNestedLine->data[len(unNestedLine)] =  ft;
unNestedLine->length = nLength+1;
} else {
unNestedLine->data[len(unNestedLine)] =  ft;
}
};

{
long nLength = len(unNestedLine);
if (unNestedLine->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(unNestedLine->data, (nLength+50)*sizeof(struct Tok));
unNestedLine->data = newPtr;
}
unNestedLine->data[len(unNestedLine)] =  t;
unNestedLine->length = nLength+1;
} else {
unNestedLine->data[len(unNestedLine)] =  t;
}
};
continue;
}
array(struct Tok)* tmpL =  parseOperations(mem,ltp,elems);

                    if (tmpL->length <= 0) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:447): tmpL[%d] with length %d\n", 0, tmpL->length);
                        exit(1);
                    };
                    struct Tok nestedT =  tmpL->data[0];
char * ____BAH_COMPILER_VAR_318 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("(");
long int strLen_1 = strlen(nestedT.cont);
long int strLen_2 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_318 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_318+currStrOff, "(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_318+currStrOff, nestedT.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_318+currStrOff, ")", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_318[currStrOff] = 0;
                }
                nestedT.cont =  ____BAH_COMPILER_VAR_318;

{
long nLength = len(unNestedLine);
if (unNestedLine->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(unNestedLine->data, (nLength+50)*sizeof(struct Tok));
unNestedLine->data = newPtr;
}
unNestedLine->data[len(unNestedLine)] =  nestedT;
unNestedLine->length = nLength+1;
} else {
unNestedLine->data[len(unNestedLine)] =  nestedT;
}
};
continue;
}

{
long nLength = len(unNestedLine);
if (unNestedLine->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(unNestedLine->data, (nLength+50)*sizeof(struct Tok));
unNestedLine->data = newPtr;
}
unNestedLine->data[len(unNestedLine)] =  t;
unNestedLine->length = nLength+1;
} else {
unNestedLine->data[len(unNestedLine)] =  t;
}
};
};
line =  unNestedLine;
i =  1;
while ((i<len(line))) {

                    if (line->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:457): line[%d] with length %d\n", i, line->length);
                        exit(1);
                    };
                    struct Tok t =  line->data[i];

                int ____BAH_COMPILER_VAR_319 = 0;
                for(int i=len(signs)-1; i != -1; i--) {
                    if (signs->data[i] != 0 && strcmp(signs->data[i], t.cont) == 0) {
                        ____BAH_COMPILER_VAR_319 = 1;
                        break;
                    };
                };
                if (((t.type==TOKEN_TYPE_SYNTAX)&&____BAH_COMPILER_VAR_319)) {
if ((i + 1>=len(line))) {
throwErr(&t,"Cannot use {TOKEN} on nothing.");
}

                    if (nl->length <= len(nl)-1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:463): nl[%d] with length %d\n", len(nl)-1, nl->length);
                        exit(1);
                    };
                    struct Tok pt =  nl->data[len(nl)-1];

                    if (line->length <= i + 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:464): line[%d] with length %d\n", i + 1, line->length);
                        exit(1);
                    };
                    struct Tok nt =  line->data[i + 1];
if ((((strcmp(t.cont, "-") == 0)&&(pt.isValue==false))&&(nt.type==TOKEN_TYPE_INT))) {
char * ____BAH_COMPILER_VAR_320 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(nt.cont);
;                            
                    ____BAH_COMPILER_VAR_320 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_320+currStrOff, t.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_320+currStrOff, nt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_320[currStrOff] = 0;
                }
                nt.cont =  ____BAH_COMPILER_VAR_320;

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  nt;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  nt;
}
};
i =  i + 2;
continue;
}
if (((nt.type==TOKEN_TYPE_SYNTAX)&&(strcmp(nt.cont, t.cont) == 0))) {
char * ____BAH_COMPILER_VAR_321 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(nt.cont);
;                            
                    ____BAH_COMPILER_VAR_321 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_321+currStrOff, t.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_321+currStrOff, nt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_321[currStrOff] = 0;
                }
                char * c =  ____BAH_COMPILER_VAR_321;
long int tl =  t.line;
long int tp =  t.pos;
struct Tok ____BAH_COMPILER_VAR_322 = {};
____BAH_COMPILER_VAR_322.cont = "";
____BAH_COMPILER_VAR_322.ogCont = "";
____BAH_COMPILER_VAR_322.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_322.pos = 0;
____BAH_COMPILER_VAR_322.line = 1;
____BAH_COMPILER_VAR_322.begLine = 1;
____BAH_COMPILER_VAR_322.bahType = "";
____BAH_COMPILER_VAR_322.isValue = false;
____BAH_COMPILER_VAR_322.isFunc = false;
____BAH_COMPILER_VAR_322.isOper = false;
____BAH_COMPILER_VAR_322.cont = c;
____BAH_COMPILER_VAR_322.ogCont = c;
____BAH_COMPILER_VAR_322.isValue = false;
____BAH_COMPILER_VAR_322.line = tl;
____BAH_COMPILER_VAR_322.pos = tp;
____BAH_COMPILER_VAR_322.type = TOKEN_TYPE_SYNTAX;
struct Tok tmpT =  ____BAH_COMPILER_VAR_322;

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  tmpT;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  tmpT;
}
};
i =  i + 2;
continue;
}
char * ptt =  getTypeFromToken(&pt,true,elems);
char * ntt =  getTypeFromToken(&nt,true,elems);
if ((compTypes(ptt,ntt)==false)) {
char * ____BAH_COMPILER_VAR_323 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(ntt);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(ptt);
long int strLen_4 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_323 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_323+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_323+currStrOff, ntt, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_323+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_323+currStrOff, ptt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_323+currStrOff, ".", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_323[currStrOff] = 0;
                }
                throwErr(&nt,____BAH_COMPILER_VAR_323);
}
t.isValue =  true;
if (((verboseRuntime==true)&&(ltp!=LINE_TYPE_ELSE))) {
if ((isRCPpointerType(ntt)||isRCPpointerType(ptt))) {
verboseOutOper(pt,nt,pt.line,elems);
}
}
if (compTypes(ptt,"cpstring")) {
if ((strcmp(t.cont, "+") != 0)) {
throwErr(&t,"Can only do concatenation (+) on cpstrings, not {TOKEN}.");
}
long int j =  i - 1;
char wasAdd =  true;
array(char *)* strConts = memoryAlloc(sizeof(array(char *)));

strConts->length = 0;
strConts->elemSize = sizeof(char *);
for (; (j<len(line)); j =  j+1) {

                    if (line->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:516): line[%d] with length %d\n", j, line->length);
                        exit(1);
                    };
                    struct Tok strAddTk =  line->data[j];
if ((wasAdd==false)) {
if ((strcmp(strAddTk.cont, "+") != 0)) {
break;
}
wasAdd =  true;
}
else {
char * strAddTkT =  getTypeFromToken(&strAddTk,true,elems);
if ((compTypes(strAddTkT,"cpstring")==false)) {
char * ____BAH_COMPILER_VAR_324 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(ntt);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(ptt);
long int strLen_4 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_324 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_324+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_324+currStrOff, ntt, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_324+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_324+currStrOff, ptt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_324+currStrOff, ".", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_324[currStrOff] = 0;
                }
                throwErr(&strAddTkT,____BAH_COMPILER_VAR_324);
break;
}
if ((((strAddTk.type==TOKEN_TYPE_FUNC)&&(strHasPrefix(strAddTk.cont,"noCheck(")==false))&&(isRCPtype(strAddTkT,elems)==true))) {

{
long nLength = len(strConts);
if (strConts->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(strConts->data, (nLength+50)*sizeof(char *));
strConts->data = newPtr;
}
strConts->data[len(strConts)] =  registerRCPvar(strAddTkT,strAddTk.cont,elems);
strConts->length = nLength+1;
} else {
strConts->data[len(strConts)] =  registerRCPvar(strAddTkT,strAddTk.cont,elems);
}
};
}
else {

{
long nLength = len(strConts);
if (strConts->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(strConts->data, (nLength+50)*sizeof(char *));
strConts->data = newPtr;
}
strConts->data[len(strConts)] =  strAddTk.cont;
strConts->length = nLength+1;
} else {
strConts->data[len(strConts)] =  strAddTk.cont;
}
};
}
wasAdd =  false;
}
};
i =  j;
char * rstr =  registerRCPvar("cpstring","null",elems);
char * lens =  "";
char * totStrLen =  "1";
j =  0;
for (; (j<len(strConts)); j =  j+1) {
char * js =  intToStr(j);

                    if (strConts->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:546): strConts[%d] with length %d\n", j, strConts->length);
                        exit(1);
                    };
                    char * ____BAH_COMPILER_VAR_325 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(lens);
long int strLen_1 = strlen("long int strLen_");
long int strLen_2 = strlen(js);
long int strLen_3 = strlen(" = strlen(");
long int strLen_4 = strlen(strConts->data[j]);
long int strLen_5 = strlen(");\n");
;                            
                    ____BAH_COMPILER_VAR_325 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    memcpy(____BAH_COMPILER_VAR_325+currStrOff, lens, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_325+currStrOff, "long int strLen_", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_325+currStrOff, js, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_325+currStrOff, " = strlen(", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_325+currStrOff, strConts->data[j], strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_325+currStrOff, ");\n", strLen_5);
                    currStrOff += strLen_5;
                    
                    ____BAH_COMPILER_VAR_325[currStrOff] = 0;
                }
                lens =  ____BAH_COMPILER_VAR_325;
char * ____BAH_COMPILER_VAR_326 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(totStrLen);
long int strLen_1 = strlen(" + strLen_");
long int strLen_2 = strlen(js);
;                            
                    ____BAH_COMPILER_VAR_326 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_326+currStrOff, totStrLen, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_326+currStrOff, " + strLen_", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_326+currStrOff, js, strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_326[currStrOff] = 0;
                }
                totStrLen =  ____BAH_COMPILER_VAR_326;
};
struct rope* cats =  rope("");
j =  0;
for (; (j<len(strConts)); j =  j+1) {
char * js =  intToStr(j);

                    if (strConts->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:554): strConts[%d] with length %d\n", j, strConts->length);
                        exit(1);
                    };
                    char * ____BAH_COMPILER_VAR_327 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n                    memcpy(");
long int strLen_1 = strlen(rstr);
long int strLen_2 = strlen("+currStrOff, ");
long int strLen_3 = strlen(strConts->data[j]);
long int strLen_4 = strlen(", strLen_");
long int strLen_5 = strlen(js);
long int strLen_6 = strlen(");\n                    currStrOff += strLen_");
long int strLen_7 = strlen(js);
long int strLen_8 = strlen(";\n                    ");
;                            
                    ____BAH_COMPILER_VAR_327 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                    
                    memcpy(____BAH_COMPILER_VAR_327+currStrOff, "\n                    memcpy(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_327+currStrOff, rstr, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_327+currStrOff, "+currStrOff, ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_327+currStrOff, strConts->data[j], strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_327+currStrOff, ", strLen_", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_327+currStrOff, js, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_327+currStrOff, ");\n                    currStrOff += strLen_", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_327+currStrOff, js, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_327+currStrOff, ";\n                    ", strLen_8);
                    currStrOff += strLen_8;
                    
                    ____BAH_COMPILER_VAR_327[currStrOff] = 0;
                }
                cats =  cats->add(cats, rope(____BAH_COMPILER_VAR_327));
};
char * ____BAH_COMPILER_VAR_328 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n                {\n                    long int currStrOff = 0;\n                    ");
long int strLen_1 = strlen(lens);
long int strLen_2 = strlen(";                            \n                    ");
long int strLen_3 = strlen(rstr);
long int strLen_4 = strlen(" = memoryAllocSTR(");
long int strLen_5 = strlen(totStrLen);
long int strLen_6 = strlen(");\n                    ");
;                            
                    ____BAH_COMPILER_VAR_328 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                    
                    memcpy(____BAH_COMPILER_VAR_328+currStrOff, "\n                {\n                    long int currStrOff = 0;\n                    ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_328+currStrOff, lens, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_328+currStrOff, ";                            \n                    ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_328+currStrOff, rstr, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_328+currStrOff, " = memoryAllocSTR(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_328+currStrOff, totStrLen, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_328+currStrOff, ");\n                    ", strLen_6);
                    currStrOff += strLen_6;
                    
                    ____BAH_COMPILER_VAR_328[currStrOff] = 0;
                }
                char * ____BAH_COMPILER_VAR_329 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n                    ");
long int strLen_1 = strlen(rstr);
long int strLen_2 = strlen("[currStrOff] = 0;\n                }\n                ");
;                            
                    ____BAH_COMPILER_VAR_329 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_329+currStrOff, "\n                    ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_329+currStrOff, rstr, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_329+currStrOff, "[currStrOff] = 0;\n                }\n                ", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_329[currStrOff] = 0;
                }
                struct rope* res =  rope(____BAH_COMPILER_VAR_328)->add(rope(____BAH_COMPILER_VAR_328), cats)->add(rope(____BAH_COMPILER_VAR_328)->add(rope(____BAH_COMPILER_VAR_328), cats), rope(____BAH_COMPILER_VAR_329));
if (isGlobal()) {
INIT =  INIT->add(INIT, res);
}
else {
OUTPUT =  OUTPUT->add(OUTPUT, res);
}
t.cont =  rstr;
t.type =  TOKEN_TYPE_VAR;
t.bahType =  ptt;
t.isOper =  false;
t.pos =  pt.pos;
t.ogCont =  pt.cont;

{
long nLength = len(nl)-1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)-1] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)-1] =  t;
}
};
continue;
}
else {
struct cStruct* s =  searchStruct(ptt,elems);
if ((s!=null)) {
struct structMemb* addMthd =  searchStructMemb("add",s,elems);
struct structMemb* subMthd =  searchStructMemb("sub",s,elems);
struct structMemb* multMthd =  searchStructMemb("mult",s,elems);
struct structMemb* divMthd =  searchStructMemb("div",s,elems);
char * sep =  ".";
char * amp =  "&";
if ((strCount(ptt,"*")>0)) {
sep =  "->";
amp =  "";
}
if ((((strcmp(t.cont, "+") == 0)&&(addMthd!=null))&&(addMthd->isFn==true))) {
char * ____BAH_COMPILER_VAR_330 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(sep);
long int strLen_2 = strlen("add(");
long int strLen_3 = strlen(amp);
long int strLen_4 = strlen(pt.cont);
long int strLen_5 = strlen(", ");
long int strLen_6 = strlen(nt.cont);
long int strLen_7 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_330 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7);
                    
                    memcpy(____BAH_COMPILER_VAR_330+currStrOff, pt.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_330+currStrOff, sep, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_330+currStrOff, "add(", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_330+currStrOff, amp, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_330+currStrOff, pt.cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_330+currStrOff, ", ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_330+currStrOff, nt.cont, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_330+currStrOff, ")", strLen_7);
                    currStrOff += strLen_7;
                    
                    ____BAH_COMPILER_VAR_330[currStrOff] = 0;
                }
                t.cont =  ____BAH_COMPILER_VAR_330;
}
else if ((((strcmp(t.cont, "-") == 0)&&(subMthd!=null))&&(subMthd->isFn==true))) {
char * ____BAH_COMPILER_VAR_331 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(sep);
long int strLen_2 = strlen("sub(");
long int strLen_3 = strlen(amp);
long int strLen_4 = strlen(pt.cont);
long int strLen_5 = strlen(", ");
long int strLen_6 = strlen(nt.cont);
long int strLen_7 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_331 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7);
                    
                    memcpy(____BAH_COMPILER_VAR_331+currStrOff, pt.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_331+currStrOff, sep, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_331+currStrOff, "sub(", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_331+currStrOff, amp, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_331+currStrOff, pt.cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_331+currStrOff, ", ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_331+currStrOff, nt.cont, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_331+currStrOff, ")", strLen_7);
                    currStrOff += strLen_7;
                    
                    ____BAH_COMPILER_VAR_331[currStrOff] = 0;
                }
                t.cont =  ____BAH_COMPILER_VAR_331;
}
else if ((((strcmp(t.cont, "*") == 0)&&(multMthd!=null))&&(multMthd->isFn==true))) {
char * ____BAH_COMPILER_VAR_332 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(sep);
long int strLen_2 = strlen("mult(");
long int strLen_3 = strlen(amp);
long int strLen_4 = strlen(pt.cont);
long int strLen_5 = strlen(", ");
long int strLen_6 = strlen(nt.cont);
long int strLen_7 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_332 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7);
                    
                    memcpy(____BAH_COMPILER_VAR_332+currStrOff, pt.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_332+currStrOff, sep, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_332+currStrOff, "mult(", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_332+currStrOff, amp, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_332+currStrOff, pt.cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_332+currStrOff, ", ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_332+currStrOff, nt.cont, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_332+currStrOff, ")", strLen_7);
                    currStrOff += strLen_7;
                    
                    ____BAH_COMPILER_VAR_332[currStrOff] = 0;
                }
                t.cont =  ____BAH_COMPILER_VAR_332;
}
else if ((((strcmp(t.cont, "/") == 0)&&(divMthd!=null))&&(divMthd->isFn==true))) {
char * ____BAH_COMPILER_VAR_333 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(sep);
long int strLen_2 = strlen("div(");
long int strLen_3 = strlen(amp);
long int strLen_4 = strlen(pt.cont);
long int strLen_5 = strlen(", ");
long int strLen_6 = strlen(nt.cont);
long int strLen_7 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_333 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7);
                    
                    memcpy(____BAH_COMPILER_VAR_333+currStrOff, pt.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_333+currStrOff, sep, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_333+currStrOff, "div(", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_333+currStrOff, amp, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_333+currStrOff, pt.cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_333+currStrOff, ", ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_333+currStrOff, nt.cont, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_333+currStrOff, ")", strLen_7);
                    currStrOff += strLen_7;
                    
                    ____BAH_COMPILER_VAR_333[currStrOff] = 0;
                }
                t.cont =  ____BAH_COMPILER_VAR_333;
}
else {
char * ____BAH_COMPILER_VAR_334 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Undefined operation on {TOKEN} (");
long int strLen_1 = strlen(ptt);
long int strLen_2 = strlen(").");
;                            
                    ____BAH_COMPILER_VAR_334 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_334+currStrOff, "Undefined operation on {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_334+currStrOff, ptt, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_334+currStrOff, ").", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_334[currStrOff] = 0;
                }
                throwErr(&pt,____BAH_COMPILER_VAR_334);
}
}
else {
char * ____BAH_COMPILER_VAR_335 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(t.cont);
long int strLen_3 = strlen(" ");
long int strLen_4 = strlen(nt.cont);
;                            
                    ____BAH_COMPILER_VAR_335 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_335+currStrOff, pt.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_335+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_335+currStrOff, t.cont, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_335+currStrOff, " ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_335+currStrOff, nt.cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_335[currStrOff] = 0;
                }
                t.cont =  ____BAH_COMPILER_VAR_335;
}
}
t.type =  TOKEN_TYPE_VAR;
t.bahType =  ptt;
t.pos =  pt.pos;
t.isOper =  true;
t.ogCont =  pt.cont;

{
long nLength = len(nl)-1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)-1] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)-1] =  t;
}
};
i =  i + 2;
continue;
}
else if ((t.isValue==true)) {
if (strHasPrefix(t.cont,"-")) {

                    if (nl->length <= len(nl)-1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:630): nl[%d] with length %d\n", len(nl)-1, nl->length);
                        exit(1);
                    };
                    struct Tok pt =  nl->data[len(nl)-1];
if ((pt.isValue==true)) {
char * ptt =  getTypeFromToken(&pt,true,elems);
char * ntt =  getTypeFromToken(&t,true,elems);
if ((compTypes(ptt,ntt)==false)) {
char * ____BAH_COMPILER_VAR_336 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(ntt);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(ptt);
long int strLen_4 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_336 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_336+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_336+currStrOff, ntt, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_336+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_336+currStrOff, ptt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_336+currStrOff, ".", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_336[currStrOff] = 0;
                }
                throwErr(&t,____BAH_COMPILER_VAR_336);
}
t.type =  TOKEN_TYPE_VAR;
t.isOper =  true;
char * ____BAH_COMPILER_VAR_337 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_337 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_337+currStrOff, pt.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_337+currStrOff, t.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_337[currStrOff] = 0;
                }
                t.cont =  ____BAH_COMPILER_VAR_337;
t.bahType =  ptt;
t.pos =  pt.pos;

{
long nLength = len(nl)-1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)-1] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)-1] =  t;
}
};
i =  i+1;
continue;
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
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
}
};
i =  i+1;
};
return nl;
};
__BAH_ARR_TYPE_Tok prePross(__BAH_ARR_TYPE_Tok line,lineType ltp,struct Elems* elems);
__BAH_ARR_TYPE_Tok parseStructType(__BAH_ARR_TYPE_Tok line,lineType ltp,struct Elems* elems){
if ((ltp==LINE_TYPE_VAR)) {
return line;
}
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
long int i =  0;
while ((i<len(line))) {

                    if (line->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:666): line[%d] with length %d\n", i, line->length);
                        exit(1);
                    };
                    struct Tok t =  line->data[i];
if ((t.type==TOKEN_TYPE_VAR)) {
if (strHasPrefix(t.bahType,"[]")) {

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
}
};
i =  i+1;
continue;
}
i =  i+1;
struct Tok ____BAH_COMPILER_VAR_338 = {};
____BAH_COMPILER_VAR_338.cont = "";
____BAH_COMPILER_VAR_338.ogCont = "";
____BAH_COMPILER_VAR_338.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_338.pos = 0;
____BAH_COMPILER_VAR_338.line = 1;
____BAH_COMPILER_VAR_338.begLine = 1;
____BAH_COMPILER_VAR_338.bahType = "";
____BAH_COMPILER_VAR_338.isValue = false;
____BAH_COMPILER_VAR_338.isFunc = false;
____BAH_COMPILER_VAR_338.isOper = false;
____BAH_COMPILER_VAR_338.cont = "";
struct Tok nt =  ____BAH_COMPILER_VAR_338;
if ((i<len(line))) {

                    if (line->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:679): line[%d] with length %d\n", i, line->length);
                        exit(1);
                    };
                    nt =  line->data[i];
}
if (((i==len(line))||(strcmp(nt.cont, "{") != 0))) {
if ((i-2>=0)) {

                    if (line->length <= i-2) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:683): line[%d] with length %d\n", i-2, line->length);
                        exit(1);
                    };
                    struct Tok newTk =  line->data[i-2];
if ((strcmp(newTk.cont, "new") == 0)) {
struct cStruct* s =  searchStruct(t.cont,elems);
if ((s==null)) {
throwErr(&t,"Cannot initialize new unknown struct {TOKEN}.");
}
t.cont =  genCompilerVar();
struct variable* ____BAH_COMPILER_VAR_339 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_339->name = "";
____BAH_COMPILER_VAR_339->type = "";
____BAH_COMPILER_VAR_339->isConst = false;
____BAH_COMPILER_VAR_339->constVal = "";
____BAH_COMPILER_VAR_339->isArray = false;
____BAH_COMPILER_VAR_339->from = "";
____BAH_COMPILER_VAR_339->outterScope = false;
____BAH_COMPILER_VAR_339->isGlobal = false;
struct variable* tmpV =  ____BAH_COMPILER_VAR_339;
tmpV->name =  t.cont;
char * ____BAH_COMPILER_VAR_340 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s->name);
long int strLen_1 = strlen("*");
;                            
                    ____BAH_COMPILER_VAR_340 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_340+currStrOff, s->name, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_340+currStrOff, "*", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_340[currStrOff] = 0;
                }
                tmpV->type =  ____BAH_COMPILER_VAR_340;
struct string cType =  getCType(tmpV->type,elems);
struct string structType =  getCType(s->name,elems);

{
long nLength = len(elems->vars);
if (elems->vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(elems->vars->data, (nLength+50)*sizeof(struct variable*));
elems->vars->data = newPtr;
}
elems->vars->data[len(elems->vars)] =  tmpV;
elems->vars->length = nLength+1;
} else {
elems->vars->data[len(elems->vars)] =  tmpV;
}
};
char * ____BAH_COMPILER_VAR_341 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_342 =structType.str((struct string*)&structType);char * ____BAH_COMPILER_VAR_343 =declareStructMethods(tmpV,s,elems);char * ____BAH_COMPILER_VAR_344 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_341);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(t.cont);
long int strLen_3 = strlen(" = memoryAlloc(sizeof(");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_342);
long int strLen_5 = strlen("));\n");
long int strLen_6 = strlen(____BAH_COMPILER_VAR_343);
;                            
                    ____BAH_COMPILER_VAR_344 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                    
                    memcpy(____BAH_COMPILER_VAR_344+currStrOff, ____BAH_COMPILER_VAR_341, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_344+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_344+currStrOff, t.cont, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_344+currStrOff, " = memoryAlloc(sizeof(", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_344+currStrOff, ____BAH_COMPILER_VAR_342, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_344+currStrOff, "));\n", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_344+currStrOff, ____BAH_COMPILER_VAR_343, strLen_6);
                    currStrOff += strLen_6;
                    
                    ____BAH_COMPILER_VAR_344[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_344));

{
long nLength = len(nl)-1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)-1] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)-1] =  t;
}
};
continue;
}
}
}
if ((i<len(line))) {

                    if (line->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:707): line[%d] with length %d\n", i, line->length);
                        exit(1);
                    };
                    nt =  line->data[i];
if ((strcmp(nt.cont, "{") == 0)) {
char isHeap =  false;
char * sep =  ".";
if ((i-2>=0)) {

                    if (line->length <= i-2) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:712): line[%d] with length %d\n", i-2, line->length);
                        exit(1);
                    };
                    struct Tok newTk =  line->data[i-2];
if ((strcmp(newTk.cont, "new") == 0)) {
isHeap =  true;
sep =  "->";
}
}
i =  i+1;
struct cStruct* s =  searchStruct(t.cont,elems);
if ((s==null)) {
throwErr(&t,"Unknown struct name {TOKEN}.");
}
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
long int nbBraces =  1;
for (; (i<len(line)); i =  i+1) {

                    if (line->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:727): line[%d] with length %d\n", i, line->length);
                        exit(1);
                    };
                    t =  line->data[i];
if ((strcmp(t.cont, "{") == 0)) {
nbBraces =  nbBraces+1;
}
else if ((strcmp(t.cont, "}") == 0)) {
nbBraces =  nbBraces-1;
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
memory->data[len(memory)] =  t;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  t;
}
};
};
if ((len(memory)>0)) {
memory =  prePross(memory,(lineType)-1,elems);
}
long int declType =  0;
char * rvn =  genCompilerVar();
struct variable* ____BAH_COMPILER_VAR_345 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_345->name = "";
____BAH_COMPILER_VAR_345->type = "";
____BAH_COMPILER_VAR_345->isConst = false;
____BAH_COMPILER_VAR_345->constVal = "";
____BAH_COMPILER_VAR_345->isArray = false;
____BAH_COMPILER_VAR_345->from = "";
____BAH_COMPILER_VAR_345->outterScope = false;
____BAH_COMPILER_VAR_345->isGlobal = false;
struct variable* tmpV =  ____BAH_COMPILER_VAR_345;
tmpV->name =  rvn;
if ((isHeap==true)) {
char * ____BAH_COMPILER_VAR_346 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s->name);
long int strLen_1 = strlen("*");
;                            
                    ____BAH_COMPILER_VAR_346 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_346+currStrOff, s->name, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_346+currStrOff, "*", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_346[currStrOff] = 0;
                }
                tmpV->type =  ____BAH_COMPILER_VAR_346;

{
long nLength = len(elems->vars);
if (elems->vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(elems->vars->data, (nLength+50)*sizeof(struct variable*));
elems->vars->data = newPtr;
}
elems->vars->data[len(elems->vars)] =  tmpV;
elems->vars->length = nLength+1;
} else {
elems->vars->data[len(elems->vars)] =  tmpV;
}
};
}
else {
tmpV->type =  s->name;
}
struct string rst =  getCType(tmpV->type,elems);
struct rope* r= null;
if ((isHeap==true)) {
char * ____BAH_COMPILER_VAR_347 =rst.str((struct string*)&rst);struct string structType =  string(____BAH_COMPILER_VAR_347);
structType.trimRight((struct string*)&structType,1);
char * ____BAH_COMPILER_VAR_348 =rst.str((struct string*)&rst);char * ____BAH_COMPILER_VAR_349 =structType.str((struct string*)&structType);char * ____BAH_COMPILER_VAR_350 =declareStructMethods(tmpV,s,elems);char * ____BAH_COMPILER_VAR_351 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_348);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(rvn);
long int strLen_3 = strlen(" = memoryAlloc(sizeof(");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_349);
long int strLen_5 = strlen("));\n");
long int strLen_6 = strlen(____BAH_COMPILER_VAR_350);
;                            
                    ____BAH_COMPILER_VAR_351 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                    
                    memcpy(____BAH_COMPILER_VAR_351+currStrOff, ____BAH_COMPILER_VAR_348, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_351+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_351+currStrOff, rvn, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_351+currStrOff, " = memoryAlloc(sizeof(", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_351+currStrOff, ____BAH_COMPILER_VAR_349, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_351+currStrOff, "));\n", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_351+currStrOff, ____BAH_COMPILER_VAR_350, strLen_6);
                    currStrOff += strLen_6;
                    
                    ____BAH_COMPILER_VAR_351[currStrOff] = 0;
                }
                r =  rope(____BAH_COMPILER_VAR_351);
}
else {
char * ____BAH_COMPILER_VAR_352 =rst.str((struct string*)&rst);char * ____BAH_COMPILER_VAR_353 =declareStructMethods(tmpV,s,elems);char * ____BAH_COMPILER_VAR_354 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_352);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(rvn);
long int strLen_3 = strlen(" = {};\n");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_353);
;                            
                    ____BAH_COMPILER_VAR_354 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_354+currStrOff, ____BAH_COMPILER_VAR_352, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_354+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_354+currStrOff, rvn, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_354+currStrOff, " = {};\n", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_354+currStrOff, ____BAH_COMPILER_VAR_353, strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_354[currStrOff] = 0;
                }
                r =  rope(____BAH_COMPILER_VAR_354);
}
long int j =  0;
long int k =  0;
while ((k<len(memory))) {

                    if (memory->length <= k) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:768): memory[%d] with length %d\n", k, memory->length);
                        exit(1);
                    };
                    t =  memory->data[k];
if ((k + 2<len(memory))) {

                    if (memory->length <= k + 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:771): memory[%d] with length %d\n", k + 1, memory->length);
                        exit(1);
                    };
                    struct Tok st =  memory->data[k + 1];

                    if (memory->length <= k + 2) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:772): memory[%d] with length %d\n", k + 2, memory->length);
                        exit(1);
                    };
                    struct Tok vl =  memory->data[k + 2];
if ((strcmp(st.cont, ":") == 0)) {
if (((declType!=0)&&(declType!=1))) {
throwErr(&t,"Cannot declare member {TOKEN} by name in list declaration.");
}
declType =  1;
if ((t.type!=TOKEN_TYPE_VAR)) {
throwErr(&t,"Cannot use {TOKEN} as struct member name.");
}
j =  0;
while ((j<len(s->members))) {

                    if (s->members->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:782): s->members[%d] with length %d\n", j, s->members->length);
                        exit(1);
                    };
                    struct structMemb* m =  s->members->data[j];
if ((strcmp(m->name, t.cont) != 0)) {
j =  j + 1;
continue;
}
char * vlt =  getTypeFromToken(&vl,true,elems);
if ((compTypes(vlt,m->type)==false)) {
char * ____BAH_COMPILER_VAR_355 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(vlt);
long int strLen_2 = strlen(") as '");
long int strLen_3 = strlen(m->type);
long int strLen_4 = strlen("'.");
;                            
                    ____BAH_COMPILER_VAR_355 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_355+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_355+currStrOff, vlt, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_355+currStrOff, ") as '", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_355+currStrOff, m->type, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_355+currStrOff, "'.", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_355[currStrOff] = 0;
                }
                throwErr(&vl,____BAH_COMPILER_VAR_355);
}
char * ____BAH_COMPILER_VAR_356 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(rvn);
long int strLen_1 = strlen(sep);
long int strLen_2 = strlen(m->name);
long int strLen_3 = strlen(" = ");
long int strLen_4 = strlen(vl.cont);
long int strLen_5 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_356 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    memcpy(____BAH_COMPILER_VAR_356+currStrOff, rvn, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_356+currStrOff, sep, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_356+currStrOff, m->name, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_356+currStrOff, " = ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_356+currStrOff, vl.cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_356+currStrOff, ";\n", strLen_5);
                    currStrOff += strLen_5;
                    
                    ____BAH_COMPILER_VAR_356[currStrOff] = 0;
                }
                r =  r->add(r, rope(____BAH_COMPILER_VAR_356));
break;
};
if ((j==len(s->members))) {
char * ____BAH_COMPILER_VAR_357 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Struct '");
long int strLen_1 = strlen(s->name);
long int strLen_2 = strlen("' has no member called {TOKEN}.");
;                            
                    ____BAH_COMPILER_VAR_357 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_357+currStrOff, "Struct '", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_357+currStrOff, s->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_357+currStrOff, "' has no member called {TOKEN}.", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_357[currStrOff] = 0;
                }
                throwErr(&t,____BAH_COMPILER_VAR_357);
}
k =  k + 3;
continue;
}
}
if (((declType!=0)&&(declType!=2))) {
throwErr(&t,"Cannot declare member {TOKEN} without specifying its name.");
}
declType =  2;
if ((j>len(s->members))) {
throwErr(&t,"Too many members {TOKEN}.");
}

                    if (s->members->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:809): s->members[%d] with length %d\n", j, s->members->length);
                        exit(1);
                    };
                    struct structMemb* m =  s->members->data[j];
j =  j+1;
char * tt =  getTypeFromToken(&t,true,elems);
if ((compTypes(tt,m->type)==false)) {
char * ____BAH_COMPILER_VAR_358 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(tt);
long int strLen_2 = strlen(") as '");
long int strLen_3 = strlen(m->type);
long int strLen_4 = strlen("'.");
;                            
                    ____BAH_COMPILER_VAR_358 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_358+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_358+currStrOff, tt, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_358+currStrOff, ") as '", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_358+currStrOff, m->type, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_358+currStrOff, "'.", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_358[currStrOff] = 0;
                }
                throwErr(&t,____BAH_COMPILER_VAR_358);
}
char * ____BAH_COMPILER_VAR_359 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(rvn);
long int strLen_1 = strlen(sep);
long int strLen_2 = strlen(m->name);
long int strLen_3 = strlen(" = ");
long int strLen_4 = strlen(t.cont);
long int strLen_5 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_359 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    memcpy(____BAH_COMPILER_VAR_359+currStrOff, rvn, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_359+currStrOff, sep, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_359+currStrOff, m->name, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_359+currStrOff, " = ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_359+currStrOff, t.cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_359+currStrOff, ";\n", strLen_5);
                    currStrOff += strLen_5;
                    
                    ____BAH_COMPILER_VAR_359[currStrOff] = 0;
                }
                r =  r->add(r, rope(____BAH_COMPILER_VAR_359));
if ((k + 1<len(memory))) {
k =  k+1;

                    if (memory->length <= k) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:821): memory[%d] with length %d\n", k, memory->length);
                        exit(1);
                    };
                    struct Tok st =  memory->data[k];
if ((strcmp(st.cont, ",") != 0)) {
throwErr(&st,"Need ',' separator between two values, not {TOKEN}.");
}
}
k =  k+1;
};
if (isGlobal()) {
INIT =  INIT->add(INIT, r);
}
else {
OUTPUT =  OUTPUT->add(OUTPUT, r);
}
t.bahType =  tmpV->type;
t.cont =  rvn;
t.isValue =  true;
if ((isHeap==true)) {

{
long nLength = len(nl)-1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)-1] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)-1] =  t;
}
};
}
else {

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
}
};
}
i =  i+1;
continue;
}
else {
i =  i-1;
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
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
}
};
i =  i+1;
};
return nl;
};
__BAH_ARR_TYPE_Tok parseStructVars(__BAH_ARR_TYPE_Tok line,struct Elems* elems){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
long int i =  0;
while ((i<len(line))) {

                    if (line->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:865): line[%d] with length %d\n", i, line->length);
                        exit(1);
                    };
                    struct Tok t =  line->data[i];
if ((strcmp(t.cont, ".") == 0)) {
break;
}
i =  i + 1;
};
if ((i==len(line))) {
return line;
}
i =  0;
while ((i<len(line))) {

                    if (line->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:877): line[%d] with length %d\n", i, line->length);
                        exit(1);
                    };
                    struct Tok t =  line->data[i];
if ((t.type==TOKEN_TYPE_VAR)) {
i =  i+1;
while ((i<len(line))) {

                    if (line->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:881): line[%d] with length %d\n", i, line->length);
                        exit(1);
                    };
                    struct Tok it =  line->data[i];
if ((strcmp(it.cont, ".") != 0)) {
break;
}
struct variable* v =  searchVar(t.cont,elems);
if ((v==null)) {
throwErr(&t,"Unknown var {TOKEN}.");
}
char * sep =  ".";
if (strCount(v->type,"*")) {
sep =  "->";
}
struct cStruct* s =  searchStruct(v->type,elems);
if ((s==null)) {
char * ____BAH_COMPILER_VAR_360 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(v->type);
long int strLen_2 = strlen(") as a structure.");
;                            
                    ____BAH_COMPILER_VAR_360 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_360+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_360+currStrOff, v->type, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_360+currStrOff, ") as a structure.", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_360[currStrOff] = 0;
                }
                throwErr(&t,____BAH_COMPILER_VAR_360);
}
i =  i+1;

                    if (line->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:898): line[%d] with length %d\n", i, line->length);
                        exit(1);
                    };
                    struct Tok nt =  line->data[i];
if ((nt.type!=TOKEN_TYPE_VAR)) {
throwErr(&nt,"Cannot use {TOKEN} as struct member name.");
}
struct structMemb* memb =  searchStructMemb(nt.cont,s,elems);
if ((memb==null)) {
throwErr(&nt,"Unknown struct member {TOKEN}.");
}
char * ____BAH_COMPILER_VAR_361 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(sep);
long int strLen_2 = strlen(memb->name);
;                            
                    ____BAH_COMPILER_VAR_361 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_361+currStrOff, t.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_361+currStrOff, sep, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_361+currStrOff, memb->name, strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_361[currStrOff] = 0;
                }
                t.cont =  ____BAH_COMPILER_VAR_361;
i =  i+1;
};

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
}
};
continue;
}

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
}
};
i =  i+1;
};
return nl;
};
__BAH_ARR_TYPE_Tok parseArrayType(__BAH_ARR_TYPE_Tok line,struct Elems* elems){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
long int i =  0;
for (; (i<len(line)); i =  i+1) {

                    if (line->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:926): line[%d] with length %d\n", i, line->length);
                        exit(1);
                    };
                    struct Tok t =  line->data[i];
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
nl->data[i] =  t;
nl->length = nLength+1;
} else {
nl->data[i] =  t;
}
};
};
if ((i==len(line))) {
return line;
}
for (; (i<len(line)); i =  i+1) {

                    if (line->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:937): line[%d] with length %d\n", i, line->length);
                        exit(1);
                    };
                    struct Tok t =  line->data[i];
if ((strcmp(t.cont, "[") == 0)) {
i =  i+1;
if ((i<len(line))) {

                    if (line->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:941): line[%d] with length %d\n", i, line->length);
                        exit(1);
                    };
                    t =  line->data[i];
if ((strcmp(t.cont, "]") == 0)) {
i =  i+1;
long int depth =  1;
char * bracks =  "[]";
for (; (i<len(line) - 1); i =  i+1) {

                    if (line->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:947): line[%d] with length %d\n", i, line->length);
                        exit(1);
                    };
                    t =  line->data[i];

                    if (line->length <= i + 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:948): line[%d] with length %d\n", i + 1, line->length);
                        exit(1);
                    };
                    struct Tok nt =  line->data[i + 1];
if (((strcmp(t.cont, "[") == 0)&&(strcmp(nt.cont, "]") == 0))) {
depth =  depth+1;
char * ____BAH_COMPILER_VAR_362 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(bracks);
long int strLen_1 = strlen("[]");
;                            
                    ____BAH_COMPILER_VAR_362 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_362+currStrOff, bracks, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_362+currStrOff, "[]", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_362[currStrOff] = 0;
                }
                bracks =  ____BAH_COMPILER_VAR_362;
i =  i+1;
}
else {
break;
}
};
if ((i<len(line))) {

                    if (line->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:958): line[%d] with length %d\n", i, line->length);
                        exit(1);
                    };
                    t =  line->data[i];
if ((t.type!=TOKEN_TYPE_VAR)) {
throwErr(&t,"Cannot use {TOKEN} as array type.");
}
char * arrElem =  t.cont;
char * ____BAH_COMPILER_VAR_363 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(bracks);
long int strLen_1 = strlen(arrElem);
;                            
                    ____BAH_COMPILER_VAR_363 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_363+currStrOff, bracks, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_363+currStrOff, arrElem, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_363[currStrOff] = 0;
                }
                t.bahType =  ____BAH_COMPILER_VAR_363;
t.cont =  "";
t.isValue =  true;

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
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
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
}
};
};
return nl;
};
array(char *)* comparators;
array(char *)* compSep;
__BAH_ARR_TYPE_Tok parseBool(__BAH_ARR_TYPE_Tok line,struct Elems* elems){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
long int i =  0;
while ((i<len(line))) {

                    if (line->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:988): line[%d] with length %d\n", i, line->length);
                        exit(1);
                    };
                    struct Tok t =  line->data[i];
if ((inArrayStr(t.cont,comparators)||inArrayStr(t.cont,compSep))) {
break;
}

{
long nLength = i;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[i] =  t;
nl->length = nLength+1;
} else {
nl->data[i] =  t;
}
};
i =  i + 1;
};
if ((i==len(line))) {
return line;
}
while ((i<len(line))) {

                    if (line->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1000): line[%d] with length %d\n", i, line->length);
                        exit(1);
                    };
                    struct Tok t =  line->data[i];
if (inArrayStr(t.cont,comparators)) {
if ((i==0)) {
throwErr(&t,"Cannot use {TOKEN} to compare with nothing.");
}

                    if (nl->length <= len(nl)-1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1006): nl[%d] with length %d\n", len(nl)-1, nl->length);
                        exit(1);
                    };
                    struct Tok pt =  nl->data[len(nl)-1];
long int max =  i + 1;
if ((max>=len(line))) {
throwErr(&t,"Cannot use {TOKEN} to compare with nothing.");
}

                    if (line->length <= i + 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1011): line[%d] with length %d\n", i + 1, line->length);
                        exit(1);
                    };
                    struct Tok nt =  line->data[i + 1];
char * ptt =  getTypeFromToken(&pt,true,elems);
char * ntt =  getTypeFromToken(&nt,true,elems);
if ((strcmp(t.cont, "in") == 0)) {
struct string arrT =  string(ntt);
if ((arrT.hasPrefix((struct string*)&arrT,"[]")==0)) {
char * ____BAH_COMPILER_VAR_364 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(ntt);
long int strLen_2 = strlen(") as an array.");
;                            
                    ____BAH_COMPILER_VAR_364 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_364+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_364+currStrOff, ntt, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_364+currStrOff, ") as an array.", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_364[currStrOff] = 0;
                }
                throwErr(&nt,____BAH_COMPILER_VAR_364);
}
arrT.trimLeft((struct string*)&arrT,2);
char * ____BAH_COMPILER_VAR_365 =arrT.str((struct string*)&arrT);if ((compTypes(ptt,____BAH_COMPILER_VAR_365)==false)) {
char * ____BAH_COMPILER_VAR_366 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot search for {TOKEN} (");
long int strLen_1 = strlen(ptt);
long int strLen_2 = strlen(") inside array of type ");
long int strLen_3 = strlen(ntt);
long int strLen_4 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_366 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_366+currStrOff, "Cannot search for {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_366+currStrOff, ptt, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_366+currStrOff, ") inside array of type ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_366+currStrOff, ntt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_366+currStrOff, ".", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_366[currStrOff] = 0;
                }
                throwErr(&pt,____BAH_COMPILER_VAR_366);
}
char * compVar =  genCompilerVar();
char * comp =  "";
if ((strcmp(ptt, "cpstring") == 0)) {
char * ____BAH_COMPILER_VAR_367 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen("->data[i] != 0 && strcmp(");
long int strLen_2 = strlen(nt.cont);
long int strLen_3 = strlen("->data[i], ");
long int strLen_4 = strlen(pt.cont);
long int strLen_5 = strlen(") == 0");
;                            
                    ____BAH_COMPILER_VAR_367 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    memcpy(____BAH_COMPILER_VAR_367+currStrOff, nt.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_367+currStrOff, "->data[i] != 0 && strcmp(", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_367+currStrOff, nt.cont, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_367+currStrOff, "->data[i], ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_367+currStrOff, pt.cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_367+currStrOff, ") == 0", strLen_5);
                    currStrOff += strLen_5;
                    
                    ____BAH_COMPILER_VAR_367[currStrOff] = 0;
                }
                comp =  ____BAH_COMPILER_VAR_367;
}
else {
char * ____BAH_COMPILER_VAR_368 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen("->data[i] == ");
long int strLen_2 = strlen(pt.cont);
;                            
                    ____BAH_COMPILER_VAR_368 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_368+currStrOff, nt.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_368+currStrOff, "->data[i] == ", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_368+currStrOff, pt.cont, strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_368[currStrOff] = 0;
                }
                comp =  ____BAH_COMPILER_VAR_368;
}
char * ____BAH_COMPILER_VAR_369 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n                int ");
long int strLen_1 = strlen(compVar);
long int strLen_2 = strlen(" = 0;\n                for(int i=len(");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen(")-1; i != -1; i--) {\n                    if (");
long int strLen_5 = strlen(comp);
long int strLen_6 = strlen(") {\n                        ");
long int strLen_7 = strlen(compVar);
long int strLen_8 = strlen(" = 1;\n                        break;\n                    };\n                };\n                ");
;                            
                    ____BAH_COMPILER_VAR_369 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                    
                    memcpy(____BAH_COMPILER_VAR_369+currStrOff, "\n                int ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_369+currStrOff, compVar, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_369+currStrOff, " = 0;\n                for(int i=len(", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_369+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_369+currStrOff, ")-1; i != -1; i--) {\n                    if (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_369+currStrOff, comp, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_369+currStrOff, ") {\n                        ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_369+currStrOff, compVar, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_369+currStrOff, " = 1;\n                        break;\n                    };\n                };\n                ", strLen_8);
                    currStrOff += strLen_8;
                    
                    ____BAH_COMPILER_VAR_369[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_369));
pt.cont =  compVar;
}
else {
if ((compTypes(ptt,ntt)==false)) {
char * ____BAH_COMPILER_VAR_370 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot compare {TOKEN} (");
long int strLen_1 = strlen(ntt);
long int strLen_2 = strlen(") to ");
long int strLen_3 = strlen(ptt);
long int strLen_4 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_370 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_370+currStrOff, "Cannot compare {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_370+currStrOff, ntt, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_370+currStrOff, ") to ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_370+currStrOff, ptt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_370+currStrOff, ".", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_370[currStrOff] = 0;
                }
                throwErr(&nt,____BAH_COMPILER_VAR_370);
}
if ((strcmp(ptt, "cpstring") == 0)) {
if ((strcmp(t.cont, "==") == 0)) {
char * ____BAH_COMPILER_VAR_371 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("(strcmp(");
long int strLen_1 = strlen(pt.cont);
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen(") == 0)");
;                            
                    ____BAH_COMPILER_VAR_371 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_371+currStrOff, "(strcmp(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_371+currStrOff, pt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_371+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_371+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_371+currStrOff, ") == 0)", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_371[currStrOff] = 0;
                }
                pt.cont =  ____BAH_COMPILER_VAR_371;
}
else if ((strcmp(t.cont, "!=") == 0)) {
char * ____BAH_COMPILER_VAR_372 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("(strcmp(");
long int strLen_1 = strlen(pt.cont);
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen(") != 0)");
;                            
                    ____BAH_COMPILER_VAR_372 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_372+currStrOff, "(strcmp(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_372+currStrOff, pt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_372+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_372+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_372+currStrOff, ") != 0)", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_372[currStrOff] = 0;
                }
                pt.cont =  ____BAH_COMPILER_VAR_372;
}
else if ((strcmp(t.cont, ">") == 0)) {
char * ____BAH_COMPILER_VAR_373 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("(strlen(");
long int strLen_1 = strlen(pt.cont);
long int strLen_2 = strlen(") > srtlen(");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen("))");
;                            
                    ____BAH_COMPILER_VAR_373 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_373+currStrOff, "(strlen(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_373+currStrOff, pt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_373+currStrOff, ") > srtlen(", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_373+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_373+currStrOff, "))", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_373[currStrOff] = 0;
                }
                pt.cont =  ____BAH_COMPILER_VAR_373;
}
else if ((strcmp(t.cont, "<") == 0)) {
char * ____BAH_COMPILER_VAR_374 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("(strlen(");
long int strLen_1 = strlen(pt.cont);
long int strLen_2 = strlen(") < srtlen(");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen("))");
;                            
                    ____BAH_COMPILER_VAR_374 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_374+currStrOff, "(strlen(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_374+currStrOff, pt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_374+currStrOff, ") < srtlen(", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_374+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_374+currStrOff, "))", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_374[currStrOff] = 0;
                }
                pt.cont =  ____BAH_COMPILER_VAR_374;
}
else if ((strcmp(t.cont, ">=") == 0)) {
char * ____BAH_COMPILER_VAR_375 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("(strlen(");
long int strLen_1 = strlen(pt.cont);
long int strLen_2 = strlen(") >= srtlen(");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen("))");
;                            
                    ____BAH_COMPILER_VAR_375 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_375+currStrOff, "(strlen(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_375+currStrOff, pt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_375+currStrOff, ") >= srtlen(", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_375+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_375+currStrOff, "))", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_375[currStrOff] = 0;
                }
                pt.cont =  ____BAH_COMPILER_VAR_375;
}
else if ((strcmp(t.cont, "<=") == 0)) {
char * ____BAH_COMPILER_VAR_376 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("(strlen(");
long int strLen_1 = strlen(pt.cont);
long int strLen_2 = strlen(") <= srtlen(");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen("))");
;                            
                    ____BAH_COMPILER_VAR_376 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_376+currStrOff, "(strlen(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_376+currStrOff, pt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_376+currStrOff, ") <= srtlen(", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_376+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_376+currStrOff, "))", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_376[currStrOff] = 0;
                }
                pt.cont =  ____BAH_COMPILER_VAR_376;
}
}
else {
char * ____BAH_COMPILER_VAR_377 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("(");
long int strLen_1 = strlen(pt.cont);
long int strLen_2 = strlen(t.cont);
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_377 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_377+currStrOff, "(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_377+currStrOff, pt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_377+currStrOff, t.cont, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_377+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_377+currStrOff, ")", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_377[currStrOff] = 0;
                }
                pt.cont =  ____BAH_COMPILER_VAR_377;
}
}
pt.bahType =  "bool";

{
long nLength = len(nl)-1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)-1] =  pt;
nl->length = nLength+1;
} else {
nl->data[len(nl)-1] =  pt;
}
};
i =  i + 2;
continue;
}

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
}
};
i =  i+1;
};
line =  nl;
nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
i =  0;
while ((i<len(line))) {

                    if (line->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1087): line[%d] with length %d\n", i, line->length);
                        exit(1);
                    };
                    struct Tok t =  line->data[i];
if (inArrayStr(t.cont,compSep)) {
if ((i==0)) {
throwErr(&t,"Cannot use {TOKEN} to compare with nothing.");
}

                    if (nl->length <= len(nl)-1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1092): nl[%d] with length %d\n", len(nl)-1, nl->length);
                        exit(1);
                    };
                    struct Tok pt =  nl->data[len(nl)-1];
long int max =  i + 1;
if ((max>=len(line))) {
throwErr(&t,"Cannot use {TOKEN} to compare with nothing.");
}

                    if (line->length <= i + 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1097): line[%d] with length %d\n", i + 1, line->length);
                        exit(1);
                    };
                    struct Tok nt =  line->data[i + 1];
char * ptt =  getTypeFromToken(&pt,true,elems);
char * ntt =  getTypeFromToken(&nt,true,elems);
if ((strcmp(ptt, "bool") != 0)) {
if ((strcmp(ptt, "int") != 0)) {
throwErr(&pt,"Cannot compare {TOKEN} that is not a bool.");
}
}
if ((strcmp(ntt, "bool") != 0)) {
if ((strcmp(ntt, "int") != 0)) {
throwErr(&nt,"Cannot compare {TOKEN} that is not a bool.");
}
}
char * ____BAH_COMPILER_VAR_378 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("(");
long int strLen_1 = strlen(pt.cont);
long int strLen_2 = strlen(t.cont);
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_378 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_378+currStrOff, "(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_378+currStrOff, pt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_378+currStrOff, t.cont, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_378+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_378+currStrOff, ")", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_378[currStrOff] = 0;
                }
                pt.cont =  ____BAH_COMPILER_VAR_378;
pt.bahType =  "bool";

{
long nLength = len(nl)-1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)-1] =  pt;
nl->length = nLength+1;
} else {
nl->data[len(nl)-1] =  pt;
}
};
i =  i + 2;
continue;
}

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
}
};
i =  i+1;
};
return nl;
};
__BAH_ARR_TYPE_Tok parsePointers(__BAH_ARR_TYPE_Tok l){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
array(char *)* ptrOpers = memoryAlloc(sizeof(array(char *)));

ptrOpers->length = 2;
ptrOpers->elemSize = sizeof(char *);
ptrOpers->data = memoryAlloc(sizeof(char *) * 50);ptrOpers->data[0] = "&";
ptrOpers->data[1] = "*";
long int i =  0;
while ((i<len(l))) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1133): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    struct Tok t =  l->data[i];
if ((t.type==TOKEN_TYPE_SYNTAX)) {
if ((strcmp(t.cont, "*") == 0)) {
if ((i>0)) {

                    if (nl->length <= len(nl)-1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1138): nl[%d] with length %d\n", len(nl)-1, nl->length);
                        exit(1);
                    };
                    struct Tok pt =  nl->data[len(nl)-1];
if ((pt.type==TOKEN_TYPE_VAR)) {
if ((i + 1<len(l))) {

                    if (l->length <= i + 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1141): l[%d] with length %d\n", i + 1, l->length);
                        exit(1);
                    };
                    struct Tok nt =  l->data[i + 1];
if ((nt.isValue==false)) {
char * ____BAH_COMPILER_VAR_379 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_379 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_379+currStrOff, pt.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_379+currStrOff, t.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_379[currStrOff] = 0;
                }
                pt.cont =  ____BAH_COMPILER_VAR_379;

{
long nLength = len(nl)-1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)-1] =  pt;
nl->length = nLength+1;
} else {
nl->data[len(nl)-1] =  pt;
}
};
i =  i + 1;
continue;
}
}
else {
char * ____BAH_COMPILER_VAR_380 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_380 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_380+currStrOff, pt.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_380+currStrOff, t.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_380[currStrOff] = 0;
                }
                pt.cont =  ____BAH_COMPILER_VAR_380;

{
long nLength = len(nl)-1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)-1] =  pt;
nl->length = nLength+1;
} else {
nl->data[len(nl)-1] =  pt;
}
};
i =  i + 1;
continue;
}
}
}
}
if (inArrayStr(t.cont,ptrOpers)) {
if ((i>0)) {

                    if (nl->length <= len(nl)-1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1160): nl[%d] with length %d\n", len(nl)-1, nl->length);
                        exit(1);
                    };
                    struct Tok pt =  nl->data[len(nl)-1];
if ((pt.isValue==true)) {

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
}
};
i =  i + 1;
continue;
}
}
i =  i + 1;
if ((i<len(l))) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1169): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    struct Tok nt =  l->data[i];
if ((nt.type==TOKEN_TYPE_VAR)) {
char * ____BAH_COMPILER_VAR_381 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(nt.cont);
;                            
                    ____BAH_COMPILER_VAR_381 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_381+currStrOff, t.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_381+currStrOff, nt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_381[currStrOff] = 0;
                }
                nt.cont =  ____BAH_COMPILER_VAR_381;

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  nt;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  nt;
}
};
i =  i + 1;
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
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
}
};
i =  i + 1;
};
return nl;
};
__BAH_ARR_TYPE_Tok parseArrayVars(__BAH_ARR_TYPE_Tok l,lineType ltp,struct Elems* elems){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
char found =  false;
long int i =  0;
while ((i<len(l))) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1195): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    struct Tok t =  l->data[i];
if ((t.type==TOKEN_TYPE_VAR)) {
i =  i + 1;
if ((i<len(l))) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1199): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    t =  l->data[i];
if ((strcmp(t.cont, "[") == 0)) {
found =  true;
break;
}
}
}
i =  i + 1;
};
if ((found==false)) {
return l;
}

                    if (l->length <= 0) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1212): l[%d] with length %d\n", 0, l->length);
                        exit(1);
                    };
                    struct Tok ft =  l->data[0];
i =  0;
for (; (i<len(l)); i =  i+1) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1215): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    struct Tok t =  l->data[i];
if ((strcmp(t.cont, "[") == 0)) {
long int ti =  i-1;

                    if (nl->length <= len(nl)-1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1219): nl[%d] with length %d\n", len(nl)-1, nl->length);
                        exit(1);
                    };
                    struct Tok lt =  nl->data[len(nl)-1];
if (((lt.type!=TOKEN_TYPE_VAR)&&(lt.type!=TOKEN_TYPE_FUNC))) {

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
}
};
continue;
}
char * tt =  getTypeFromToken(&lt,true,elems);
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
i =  i+1;
long int nbBracks =  1;
for (; (i<len(l)); i =  i+1) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1231): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    struct Tok it =  l->data[i];
if ((strcmp(it.cont, "[") == 0)) {
nbBracks =  nbBracks + 1;
}
else if ((strcmp(it.cont, "]") == 0)) {
nbBracks =  nbBracks - 1;
if ((nbBracks==0)) {
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
memory->data[len(memory)] =  it;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  it;
}
};
};
if ((len(memory)==0)) {
throwErr(&l->data[i],"Expected index not {TOKEN}.");
}
memory =  prePross(memory,(lineType)-1,elems);
char split =  false;
long int sepPos =  0;
char * cont =  "";
long int j =  0;
for (; (j<len(memory)); j =  j+1) {

                    if (memory->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1252): memory[%d] with length %d\n", j, memory->length);
                        exit(1);
                    };
                    struct Tok mt =  memory->data[j];
if ((strcmp(mt.cont, ":") == 0)) {
sepPos =  j;
split =  true;
}
char * ____BAH_COMPILER_VAR_382 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(cont);
long int strLen_1 = strlen(mt.cont);
;                            
                    ____BAH_COMPILER_VAR_382 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_382+currStrOff, cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_382+currStrOff, mt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_382[currStrOff] = 0;
                }
                cont =  ____BAH_COMPILER_VAR_382;
};
char * from =  "";
char * to =  "";
if ((split==true)) {
if ((sepPos==0)) {
from =  "0";
}
else {
j =  0;
for (; (j<sepPos); j =  j+1) {

                    if (memory->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1266): memory[%d] with length %d\n", j, memory->length);
                        exit(1);
                    };
                    struct Tok mt =  memory->data[j];
char * ____BAH_COMPILER_VAR_383 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(from);
long int strLen_1 = strlen(mt.cont);
;                            
                    ____BAH_COMPILER_VAR_383 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_383+currStrOff, from, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_383+currStrOff, mt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_383[currStrOff] = 0;
                }
                from =  ____BAH_COMPILER_VAR_383;
};
}
if ((sepPos==len(memory) - 1)) {
char * ____BAH_COMPILER_VAR_384 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("strlen(");
long int strLen_1 = strlen(lt.cont);
long int strLen_2 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_384 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_384+currStrOff, "strlen(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_384+currStrOff, lt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_384+currStrOff, ")", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_384[currStrOff] = 0;
                }
                to =  ____BAH_COMPILER_VAR_384;
}
else {
j =  sepPos + 1;
for (; (j<len(memory)); j =  j+1) {

                    if (memory->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1274): memory[%d] with length %d\n", j, memory->length);
                        exit(1);
                    };
                    struct Tok mt =  memory->data[j];
char * ____BAH_COMPILER_VAR_385 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(to);
long int strLen_1 = strlen(mt.cont);
;                            
                    ____BAH_COMPILER_VAR_385 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_385+currStrOff, to, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_385+currStrOff, mt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_385[currStrOff] = 0;
                }
                to =  ____BAH_COMPILER_VAR_385;
};
}
}
if ((strcmp(tt, "cpstring") == 0)) {
if ((split==false)) {
char * ____BAH_COMPILER_VAR_386 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("cpstringCharAt(");
long int strLen_1 = strlen(lt.cont);
long int strLen_2 = strlen(",");
long int strLen_3 = strlen(cont);
long int strLen_4 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_386 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_386+currStrOff, "cpstringCharAt(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_386+currStrOff, lt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_386+currStrOff, ",", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_386+currStrOff, cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_386+currStrOff, ")", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_386[currStrOff] = 0;
                }
                lt.cont =  ____BAH_COMPILER_VAR_386;
lt.isFunc =  true;
lt.bahType =  "char";

{
long nLength = len(nl)-1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)-1] =  lt;
nl->length = nLength+1;
} else {
nl->data[len(nl)-1] =  lt;
}
};
}
else {
char * ____BAH_COMPILER_VAR_387 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("cpstringSubsitute(");
long int strLen_1 = strlen(lt.cont);
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(from);
long int strLen_4 = strlen(", ");
long int strLen_5 = strlen(to);
long int strLen_6 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_387 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                    
                    memcpy(____BAH_COMPILER_VAR_387+currStrOff, "cpstringSubsitute(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_387+currStrOff, lt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_387+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_387+currStrOff, from, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_387+currStrOff, ", ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_387+currStrOff, to, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_387+currStrOff, ")", strLen_6);
                    currStrOff += strLen_6;
                    
                    ____BAH_COMPILER_VAR_387[currStrOff] = 0;
                }
                lt.cont =  ____BAH_COMPILER_VAR_387;
lt.isFunc =  true;
lt.bahType =  "cpstring";

{
long nLength = len(nl)-1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)-1] =  lt;
nl->length = nLength+1;
} else {
nl->data[len(nl)-1] =  lt;
}
};
}
continue;
}
if (strHasPrefix(tt,"map:")) {
strTrimLeft(&tt,4);
struct string elemType =  getCType(tt,elems);
if (((ti==0)&&(ltp==LINE_TYPE_VAR))) {
struct variable* ____BAH_COMPILER_VAR_388 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_388->name = "";
____BAH_COMPILER_VAR_388->type = "";
____BAH_COMPILER_VAR_388->isConst = false;
____BAH_COMPILER_VAR_388->constVal = "";
____BAH_COMPILER_VAR_388->isArray = false;
____BAH_COMPILER_VAR_388->from = "";
____BAH_COMPILER_VAR_388->outterScope = false;
____BAH_COMPILER_VAR_388->isGlobal = false;
____BAH_COMPILER_VAR_388->name = genCompilerVar();
____BAH_COMPILER_VAR_388->type = tt;
struct variable* tmpV =  ____BAH_COMPILER_VAR_388;

{
long nLength = len(elems->vars);
if (elems->vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(elems->vars->data, (nLength+50)*sizeof(struct variable*));
elems->vars->data = newPtr;
}
elems->vars->data[len(elems->vars)] =  tmpV;
elems->vars->length = nLength+1;
} else {
elems->vars->data[len(elems->vars)] =  tmpV;
}
};
if (isGlobal()) {
char * ____BAH_COMPILER_VAR_389 =elemType.str((struct string*)&elemType);char * ____BAH_COMPILER_VAR_390 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_389);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(tmpV->name);
long int strLen_3 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_390 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                    
                    memcpy(____BAH_COMPILER_VAR_390+currStrOff, ____BAH_COMPILER_VAR_389, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_390+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_390+currStrOff, tmpV->name, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_390+currStrOff, ";\n", strLen_3);
                    currStrOff += strLen_3;
                    
                    ____BAH_COMPILER_VAR_390[currStrOff] = 0;
                }
                INIT =  INIT->add(INIT, rope(____BAH_COMPILER_VAR_390));
}
else {
char * ____BAH_COMPILER_VAR_391 =elemType.str((struct string*)&elemType);char * ____BAH_COMPILER_VAR_392 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_391);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(tmpV->name);
long int strLen_3 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_392 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                    
                    memcpy(____BAH_COMPILER_VAR_392+currStrOff, ____BAH_COMPILER_VAR_391, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_392+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_392+currStrOff, tmpV->name, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_392+currStrOff, ";\n", strLen_3);
                    currStrOff += strLen_3;
                    
                    ____BAH_COMPILER_VAR_392[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_392));
}
if (isRCPpointerType(tt)) {
char * ____BAH_COMPILER_VAR_393 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(lt.cont);
long int strLen_1 = strlen("->set(");
long int strLen_2 = strlen(lt.cont);
long int strLen_3 = strlen(", ");
long int strLen_4 = strlen(cont);
long int strLen_5 = strlen(", ");
long int strLen_6 = strlen(tmpV->name);
long int strLen_7 = strlen(");\n");
;                            
                    ____BAH_COMPILER_VAR_393 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7);
                    
                    memcpy(____BAH_COMPILER_VAR_393+currStrOff, lt.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_393+currStrOff, "->set(", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_393+currStrOff, lt.cont, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_393+currStrOff, ", ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_393+currStrOff, cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_393+currStrOff, ", ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_393+currStrOff, tmpV->name, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_393+currStrOff, ");\n", strLen_7);
                    currStrOff += strLen_7;
                    
                    ____BAH_COMPILER_VAR_393[currStrOff] = 0;
                }
                NEXT_LINE =  ____BAH_COMPILER_VAR_393;
}
else {
char * ____BAH_COMPILER_VAR_394 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(lt.cont);
long int strLen_1 = strlen("->setAny(");
long int strLen_2 = strlen(lt.cont);
long int strLen_3 = strlen(", ");
long int strLen_4 = strlen(cont);
long int strLen_5 = strlen(", &");
long int strLen_6 = strlen(tmpV->name);
long int strLen_7 = strlen(", sizeof(");
long int strLen_8 = strlen(tmpV->name);
long int strLen_9 = strlen("));\n");
;                            
                    ____BAH_COMPILER_VAR_394 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9);
                    
                    memcpy(____BAH_COMPILER_VAR_394+currStrOff, lt.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_394+currStrOff, "->setAny(", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_394+currStrOff, lt.cont, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_394+currStrOff, ", ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_394+currStrOff, cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_394+currStrOff, ", &", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_394+currStrOff, tmpV->name, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_394+currStrOff, ", sizeof(", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_394+currStrOff, tmpV->name, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_394+currStrOff, "));\n", strLen_9);
                    currStrOff += strLen_9;
                    
                    ____BAH_COMPILER_VAR_394[currStrOff] = 0;
                }
                NEXT_LINE =  ____BAH_COMPILER_VAR_394;
}
lt.cont =  tmpV->name;
}
else {
if (isRCPpointerType(tt)) {
char * ____BAH_COMPILER_VAR_395 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(lt.cont);
long int strLen_1 = strlen("->get(");
long int strLen_2 = strlen(lt.cont);
long int strLen_3 = strlen(", ");
long int strLen_4 = strlen(cont);
long int strLen_5 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_395 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    memcpy(____BAH_COMPILER_VAR_395+currStrOff, lt.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_395+currStrOff, "->get(", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_395+currStrOff, lt.cont, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_395+currStrOff, ", ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_395+currStrOff, cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_395+currStrOff, ")", strLen_5);
                    currStrOff += strLen_5;
                    
                    ____BAH_COMPILER_VAR_395[currStrOff] = 0;
                }
                lt.cont =  ____BAH_COMPILER_VAR_395;
}
else {
char * tmpV =  genCompilerVar();
char * ____BAH_COMPILER_VAR_396 =elemType.str((struct string*)&elemType);char * ____BAH_COMPILER_VAR_397 =intToStr(lt.line);char * ____BAH_COMPILER_VAR_398 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_396);
long int strLen_1 = strlen("* ");
long int strLen_2 = strlen(tmpV);
long int strLen_3 = strlen(" = ");
long int strLen_4 = strlen(lt.cont);
long int strLen_5 = strlen("->get(");
long int strLen_6 = strlen(lt.cont);
long int strLen_7 = strlen(", ");
long int strLen_8 = strlen(cont);
long int strLen_9 = strlen(");\n                        if(");
long int strLen_10 = strlen(tmpV);
long int strLen_11 = strlen(" == null) {\n                            printf(\"map (");
long int strLen_12 = strlen(compilerState.currentFile);
long int strLen_13 = strlen(":");
long int strLen_14 = strlen(____BAH_COMPILER_VAR_397);
long int strLen_15 = strlen("): ");
long int strLen_16 = strlen(lt.cont);
long int strLen_17 = strlen("[\\\"%s\\\"] does not exist\\n\", ");
long int strLen_18 = strlen(cont);
long int strLen_19 = strlen(");\n                            exit(1);\n                        };");
;                            
                    ____BAH_COMPILER_VAR_398 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14 + strLen_15 + strLen_16 + strLen_17 + strLen_18 + strLen_19);
                    
                    memcpy(____BAH_COMPILER_VAR_398+currStrOff, ____BAH_COMPILER_VAR_396, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_398+currStrOff, "* ", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_398+currStrOff, tmpV, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_398+currStrOff, " = ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_398+currStrOff, lt.cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_398+currStrOff, "->get(", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_398+currStrOff, lt.cont, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_398+currStrOff, ", ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_398+currStrOff, cont, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_398+currStrOff, ");\n                        if(", strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_398+currStrOff, tmpV, strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_398+currStrOff, " == null) {\n                            printf(\"map (", strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_398+currStrOff, compilerState.currentFile, strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_398+currStrOff, ":", strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_398+currStrOff, ____BAH_COMPILER_VAR_397, strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_398+currStrOff, "): ", strLen_15);
                    currStrOff += strLen_15;
                    
                    memcpy(____BAH_COMPILER_VAR_398+currStrOff, lt.cont, strLen_16);
                    currStrOff += strLen_16;
                    
                    memcpy(____BAH_COMPILER_VAR_398+currStrOff, "[\\\"%s\\\"] does not exist\\n\", ", strLen_17);
                    currStrOff += strLen_17;
                    
                    memcpy(____BAH_COMPILER_VAR_398+currStrOff, cont, strLen_18);
                    currStrOff += strLen_18;
                    
                    memcpy(____BAH_COMPILER_VAR_398+currStrOff, ");\n                            exit(1);\n                        };", strLen_19);
                    currStrOff += strLen_19;
                    
                    ____BAH_COMPILER_VAR_398[currStrOff] = 0;
                }
                struct rope* res =  rope(____BAH_COMPILER_VAR_398);
char * ____BAH_COMPILER_VAR_399 =elemType.str((struct string*)&elemType);char * ____BAH_COMPILER_VAR_400 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("(");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_399);
long int strLen_2 = strlen(")(*");
long int strLen_3 = strlen(tmpV);
long int strLen_4 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_400 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_400+currStrOff, "(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_400+currStrOff, ____BAH_COMPILER_VAR_399, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_400+currStrOff, ")(*", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_400+currStrOff, tmpV, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_400+currStrOff, ")", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_400[currStrOff] = 0;
                }
                lt.cont =  ____BAH_COMPILER_VAR_400;
if (isGlobal()) {
INIT =  INIT->add(INIT, res);
}
else {
OUTPUT =  OUTPUT->add(OUTPUT, res);
}
}
lt.bahType =  tt;
}

{
long nLength = len(nl)-1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)-1] =  lt;
nl->length = nLength+1;
} else {
nl->data[len(nl)-1] =  lt;
}
};
continue;
}
if (strHasPrefix(tt,"buffer:")) {
if ((split==false)) {
char * amm =  cpstringSubsitute(tt, 7, strlen(tt));
char * ____BAH_COMPILER_VAR_401 =intToStr(lt.line);char * ____BAH_COMPILER_VAR_402 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n                    if (");
long int strLen_1 = strlen(cont);
long int strLen_2 = strlen(" >= ");
long int strLen_3 = strlen(amm);
long int strLen_4 = strlen(") {\n                        printf(\"buffer (");
long int strLen_5 = strlen(compilerState.currentFile);
long int strLen_6 = strlen(":");
long int strLen_7 = strlen(____BAH_COMPILER_VAR_401);
long int strLen_8 = strlen("): ");
long int strLen_9 = strlen(lt.cont);
long int strLen_10 = strlen("[%d] with length %d\\n\", ");
long int strLen_11 = strlen(cont);
long int strLen_12 = strlen(", ");
long int strLen_13 = strlen(amm);
long int strLen_14 = strlen(");\n                        exit(1);\n                    };\n                    ");
;                            
                    ____BAH_COMPILER_VAR_402 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14);
                    
                    memcpy(____BAH_COMPILER_VAR_402+currStrOff, "\n                    if (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_402+currStrOff, cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_402+currStrOff, " >= ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_402+currStrOff, amm, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_402+currStrOff, ") {\n                        printf(\"buffer (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_402+currStrOff, compilerState.currentFile, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_402+currStrOff, ":", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_402+currStrOff, ____BAH_COMPILER_VAR_401, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_402+currStrOff, "): ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_402+currStrOff, lt.cont, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_402+currStrOff, "[%d] with length %d\\n\", ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_402+currStrOff, cont, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_402+currStrOff, ", ", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_402+currStrOff, amm, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_402+currStrOff, ");\n                        exit(1);\n                    };\n                    ", strLen_14);
                    currStrOff += strLen_14;
                    
                    ____BAH_COMPILER_VAR_402[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_402));
char * ____BAH_COMPILER_VAR_403 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(lt.cont);
long int strLen_1 = strlen("[");
long int strLen_2 = strlen(cont);
long int strLen_3 = strlen("]");
;                            
                    ____BAH_COMPILER_VAR_403 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                    
                    memcpy(____BAH_COMPILER_VAR_403+currStrOff, lt.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_403+currStrOff, "[", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_403+currStrOff, cont, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_403+currStrOff, "]", strLen_3);
                    currStrOff += strLen_3;
                    
                    ____BAH_COMPILER_VAR_403[currStrOff] = 0;
                }
                lt.cont =  ____BAH_COMPILER_VAR_403;
lt.isFunc =  false;
lt.bahType =  "char";

{
long nLength = len(nl)-1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)-1] =  lt;
nl->length = nLength+1;
} else {
nl->data[len(nl)-1] =  lt;
}
};
}
else {
char * ____BAH_COMPILER_VAR_404 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("cpstringSubsitute(");
long int strLen_1 = strlen(lt.cont);
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(from);
long int strLen_4 = strlen(", ");
long int strLen_5 = strlen(to);
long int strLen_6 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_404 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                    
                    memcpy(____BAH_COMPILER_VAR_404+currStrOff, "cpstringSubsitute(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_404+currStrOff, lt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_404+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_404+currStrOff, from, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_404+currStrOff, ", ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_404+currStrOff, to, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_404+currStrOff, ")", strLen_6);
                    currStrOff += strLen_6;
                    
                    ____BAH_COMPILER_VAR_404[currStrOff] = 0;
                }
                lt.cont =  ____BAH_COMPILER_VAR_404;
lt.isFunc =  true;
lt.bahType =  "cpstring";

{
long nLength = len(nl)-1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)-1] =  lt;
nl->length = nLength+1;
} else {
nl->data[len(nl)-1] =  lt;
}
};
}
continue;
}
else if ((strHasPrefix(tt,"[]")==false)) {
char * ____BAH_COMPILER_VAR_405 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(tt);
long int strLen_2 = strlen(") as an array.");
;                            
                    ____BAH_COMPILER_VAR_405 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_405+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_405+currStrOff, tt, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_405+currStrOff, ") as an array.", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_405[currStrOff] = 0;
                }
                throwErr(&lt,____BAH_COMPILER_VAR_405);
}
strTrimLeft(&tt,2);
if ((split==false)) {
if (((ti>0)&&(strcmp(ft.cont, "else") != 0))) {
char * ____BAH_COMPILER_VAR_406 =intToStr(lt.line);char * ____BAH_COMPILER_VAR_407 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n                    if (");
long int strLen_1 = strlen(lt.cont);
long int strLen_2 = strlen("->length <= ");
long int strLen_3 = strlen(cont);
long int strLen_4 = strlen(") {\n                        printf(\"array (");
long int strLen_5 = strlen(compilerState.currentFile);
long int strLen_6 = strlen(":");
long int strLen_7 = strlen(____BAH_COMPILER_VAR_406);
long int strLen_8 = strlen("): ");
long int strLen_9 = strlen(lt.cont);
long int strLen_10 = strlen("[%d] with length %d\\n\", ");
long int strLen_11 = strlen(cont);
long int strLen_12 = strlen(", ");
long int strLen_13 = strlen(lt.cont);
long int strLen_14 = strlen("->length);\n                        exit(1);\n                    };\n                    ");
;                            
                    ____BAH_COMPILER_VAR_407 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14);
                    
                    memcpy(____BAH_COMPILER_VAR_407+currStrOff, "\n                    if (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_407+currStrOff, lt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_407+currStrOff, "->length <= ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_407+currStrOff, cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_407+currStrOff, ") {\n                        printf(\"array (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_407+currStrOff, compilerState.currentFile, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_407+currStrOff, ":", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_407+currStrOff, ____BAH_COMPILER_VAR_406, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_407+currStrOff, "): ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_407+currStrOff, lt.cont, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_407+currStrOff, "[%d] with length %d\\n\", ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_407+currStrOff, cont, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_407+currStrOff, ", ", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_407+currStrOff, lt.cont, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_407+currStrOff, "->length);\n                        exit(1);\n                    };\n                    ", strLen_14);
                    currStrOff += strLen_14;
                    
                    ____BAH_COMPILER_VAR_407[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_407));
}
char * ____BAH_COMPILER_VAR_408 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(lt.cont);
long int strLen_1 = strlen("->data[");
long int strLen_2 = strlen(cont);
long int strLen_3 = strlen("]");
;                            
                    ____BAH_COMPILER_VAR_408 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                    
                    memcpy(____BAH_COMPILER_VAR_408+currStrOff, lt.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_408+currStrOff, "->data[", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_408+currStrOff, cont, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_408+currStrOff, "]", strLen_3);
                    currStrOff += strLen_3;
                    
                    ____BAH_COMPILER_VAR_408[currStrOff] = 0;
                }
                lt.cont =  ____BAH_COMPILER_VAR_408;
lt.bahType =  tt;
}
else {
char * ____BAH_COMPILER_VAR_409 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("[]");
long int strLen_1 = strlen(tt);
;                            
                    ____BAH_COMPILER_VAR_409 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_409+currStrOff, "[]", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_409+currStrOff, tt, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_409[currStrOff] = 0;
                }
                lt.bahType =  ____BAH_COMPILER_VAR_409;
char * ____BAH_COMPILER_VAR_410 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("arraySubstitute(");
long int strLen_1 = strlen(lt.cont);
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(from);
long int strLen_4 = strlen(", ");
long int strLen_5 = strlen(to);
long int strLen_6 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_410 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                    
                    memcpy(____BAH_COMPILER_VAR_410+currStrOff, "arraySubstitute(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_410+currStrOff, lt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_410+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_410+currStrOff, from, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_410+currStrOff, ", ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_410+currStrOff, to, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_410+currStrOff, ")", strLen_6);
                    currStrOff += strLen_6;
                    
                    ____BAH_COMPILER_VAR_410[currStrOff] = 0;
                }
                lt.cont =  ____BAH_COMPILER_VAR_410;
}

{
long nLength = len(nl)-1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)-1] =  lt;
nl->length = nLength+1;
} else {
nl->data[len(nl)-1] =  lt;
}
};
continue;
}

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
}
};
};
return nl;
};
char * parseSerialize(struct Tok e,struct Elems* elems){
struct variable* v =  searchVar(e.cont,elems);
if ((v==null)) {
throwErr(&e,"Must be a var, not {TOKEN}.");
}
struct cStruct* s =  searchStruct(v->type,elems);
if ((s==null)) {
throwErr(&e,"Must be a struct, not {TOKEN}.");
}
struct string svt =  string(v->type);
long int ptrLevel =  svt.count((struct string*)&svt,"*");
svt.replace((struct string*)&svt,"*","");
char * code= null;
if ((ptrLevel==0)) {
char * ____BAH_COMPILER_VAR_411 =svt.str((struct string*)&svt);char * ____BAH_COMPILER_VAR_412 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("__serialize(&");
long int strLen_1 = strlen(e.cont);
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen("sizeof(struct ");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_411);
long int strLen_5 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_412 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    memcpy(____BAH_COMPILER_VAR_412+currStrOff, "__serialize(&", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_412+currStrOff, e.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_412+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_412+currStrOff, "sizeof(struct ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_412+currStrOff, ____BAH_COMPILER_VAR_411, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_412+currStrOff, ")", strLen_5);
                    currStrOff += strLen_5;
                    
                    ____BAH_COMPILER_VAR_412[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_412;
}
else {
char * ptrRect =  "";
while ((ptrLevel>1)) {
char * ____BAH_COMPILER_VAR_413 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ptrRect);
long int strLen_1 = strlen("*");
;                            
                    ____BAH_COMPILER_VAR_413 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_413+currStrOff, ptrRect, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_413+currStrOff, "*", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_413[currStrOff] = 0;
                }
                ptrRect =  ____BAH_COMPILER_VAR_413;
ptrLevel =  ptrLevel - 1;
};
char * ____BAH_COMPILER_VAR_414 =svt.str((struct string*)&svt);char * ____BAH_COMPILER_VAR_415 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("__serialize(");
long int strLen_1 = strlen(ptrRect);
long int strLen_2 = strlen(e.cont);
long int strLen_3 = strlen(", ");
long int strLen_4 = strlen("sizeof(struct ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_414);
long int strLen_6 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_415 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                    
                    memcpy(____BAH_COMPILER_VAR_415+currStrOff, "__serialize(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_415+currStrOff, ptrRect, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_415+currStrOff, e.cont, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_415+currStrOff, ", ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_415+currStrOff, "sizeof(struct ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_415+currStrOff, ____BAH_COMPILER_VAR_414, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_415+currStrOff, ")", strLen_6);
                    currStrOff += strLen_6;
                    
                    ____BAH_COMPILER_VAR_415[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_415;
long int i =  0;
while ((i<len(s->members))) {

                    if (s->members->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1422): s->members[%d] with length %d\n", i, s->members->length);
                        exit(1);
                    };
                    struct structMemb* m =  s->members->data[i];
if ((strcmp(m->type, "cpstring") == 0)) {
char * ____BAH_COMPILER_VAR_416 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen("+strlen(");
long int strLen_2 = strlen(e.cont);
long int strLen_3 = strlen("->");
long int strLen_4 = strlen(m->name);
long int strLen_5 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_416 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    memcpy(____BAH_COMPILER_VAR_416+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_416+currStrOff, "+strlen(", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_416+currStrOff, e.cont, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_416+currStrOff, "->", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_416+currStrOff, m->name, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_416+currStrOff, ")", strLen_5);
                    currStrOff += strLen_5;
                    
                    ____BAH_COMPILER_VAR_416[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_416;
}
i =  i + 1;
};
}
char * ____BAH_COMPILER_VAR_417 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_417 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_417+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_417+currStrOff, ")", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_417[currStrOff] = 0;
                }
                return ____BAH_COMPILER_VAR_417;
};
struct Tok parseReflect(struct Tok t,char * tt,struct Elems* elems,char parsedPointer,char * ogName,char * offset){
char * isArr =  "0";
if (((t.type!=TOKEN_TYPE_VAR)||(t.type!=TOKEN_TYPE_FUNC))) {
struct string cType;
if (strHasPrefix(tt,"function(")) {
cType =  string("void*");
}
else {
cType =  getCType(tt,elems);
}
char * v =  genCompilerVar();
if ((parsedPointer==true)) {
cType.append((struct string*)&cType,"*");
}
char * ____BAH_COMPILER_VAR_418 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_419 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_418);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(v);
long int strLen_3 = strlen(" = ");
long int strLen_4 = strlen(t.cont);
long int strLen_5 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_419 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    memcpy(____BAH_COMPILER_VAR_419+currStrOff, ____BAH_COMPILER_VAR_418, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_419+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_419+currStrOff, v, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_419+currStrOff, " = ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_419+currStrOff, t.cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_419+currStrOff, ";\n", strLen_5);
                    currStrOff += strLen_5;
                    
                    ____BAH_COMPILER_VAR_419[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_419));
t.cont =  v;
if ((t.type==TOKEN_TYPE_STR)) {
ogName =  "[bah cpstring]";
}
}
char * arrElem =  "0";
if (strHasPrefix(tt,"[]")) {
isArr =  "1";
struct string aet =  string(tt);
aet.trimLeft((struct string*)&aet,2);
struct Tok ____BAH_COMPILER_VAR_420 = {};
____BAH_COMPILER_VAR_420.cont = "";
____BAH_COMPILER_VAR_420.ogCont = "";
____BAH_COMPILER_VAR_420.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_420.pos = 0;
____BAH_COMPILER_VAR_420.line = 1;
____BAH_COMPILER_VAR_420.begLine = 1;
____BAH_COMPILER_VAR_420.bahType = "";
____BAH_COMPILER_VAR_420.isValue = false;
____BAH_COMPILER_VAR_420.isFunc = false;
____BAH_COMPILER_VAR_420.isOper = false;
struct Tok tmpT =  ____BAH_COMPILER_VAR_420;
tmpT.type =  TOKEN_TYPE_VAR;
tmpT.cont =  "0";
char * ____BAH_COMPILER_VAR_421 =aet.str((struct string*)&aet);struct Tok rt =  parseReflect(tmpT,____BAH_COMPILER_VAR_421,elems,true,"","0");
char * aev =  genCompilerVar();
char * ____BAH_COMPILER_VAR_422 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n        struct reflectElement ");
long int strLen_1 = strlen(aev);
long int strLen_2 = strlen(" = ");
long int strLen_3 = strlen(rt.cont);
long int strLen_4 = strlen(";\n        ");
;                            
                    ____BAH_COMPILER_VAR_422 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_422+currStrOff, "\n        struct reflectElement ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_422+currStrOff, aev, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_422+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_422+currStrOff, rt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_422+currStrOff, ";\n        ", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_422[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_422));
char * ____BAH_COMPILER_VAR_423 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("&");
long int strLen_1 = strlen(aev);
;                            
                    ____BAH_COMPILER_VAR_423 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_423+currStrOff, "&", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_423+currStrOff, aev, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_423[currStrOff] = 0;
                }
                arrElem =  ____BAH_COMPILER_VAR_423;
}
else if (strHasPrefix(tt,"map:")) {
struct string aet =  string(tt);
aet.trimLeft((struct string*)&aet,4);
struct Tok ____BAH_COMPILER_VAR_424 = {};
____BAH_COMPILER_VAR_424.cont = "";
____BAH_COMPILER_VAR_424.ogCont = "";
____BAH_COMPILER_VAR_424.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_424.pos = 0;
____BAH_COMPILER_VAR_424.line = 1;
____BAH_COMPILER_VAR_424.begLine = 1;
____BAH_COMPILER_VAR_424.bahType = "";
____BAH_COMPILER_VAR_424.isValue = false;
____BAH_COMPILER_VAR_424.isFunc = false;
____BAH_COMPILER_VAR_424.isOper = false;
struct Tok tmpT =  ____BAH_COMPILER_VAR_424;
tmpT.type =  TOKEN_TYPE_VAR;
tmpT.cont =  "0";
char * ____BAH_COMPILER_VAR_425 =aet.str((struct string*)&aet);struct Tok rt =  parseReflect(tmpT,____BAH_COMPILER_VAR_425,elems,true,"","0");
char * aev =  genCompilerVar();
char * ____BAH_COMPILER_VAR_426 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n        struct reflectElement ");
long int strLen_1 = strlen(aev);
long int strLen_2 = strlen(" = ");
long int strLen_3 = strlen(rt.cont);
long int strLen_4 = strlen(";\n        ");
;                            
                    ____BAH_COMPILER_VAR_426 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_426+currStrOff, "\n        struct reflectElement ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_426+currStrOff, aev, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_426+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_426+currStrOff, rt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_426+currStrOff, ";\n        ", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_426[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_426));
char * ____BAH_COMPILER_VAR_427 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("&");
long int strLen_1 = strlen(aev);
;                            
                    ____BAH_COMPILER_VAR_427 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_427+currStrOff, "&", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_427+currStrOff, aev, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_427[currStrOff] = 0;
                }
                arrElem =  ____BAH_COMPILER_VAR_427;
}
char * isStruct =  "0";
struct cStruct* ts =  searchStruct(tt,elems);
char * structLayout =  "0";
if ((ts!=null)) {
isStruct =  "1";
structLayout =  genCompilerVar();
struct variable* ____BAH_COMPILER_VAR_428 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_428->name = "";
____BAH_COMPILER_VAR_428->type = "";
____BAH_COMPILER_VAR_428->isConst = false;
____BAH_COMPILER_VAR_428->constVal = "";
____BAH_COMPILER_VAR_428->isArray = false;
____BAH_COMPILER_VAR_428->from = "";
____BAH_COMPILER_VAR_428->outterScope = false;
____BAH_COMPILER_VAR_428->isGlobal = false;
struct variable* slv =  ____BAH_COMPILER_VAR_428;
slv->name =  structLayout;
slv->type =  "[]reflectElement";

{
long nLength = len(elems->vars);
if (elems->vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(elems->vars->data, (nLength+50)*sizeof(struct variable*));
elems->vars->data = newPtr;
}
elems->vars->data[len(elems->vars)] =  slv;
elems->vars->length = nLength+1;
} else {
elems->vars->data[len(elems->vars)] =  slv;
}
};
struct rope* dataLayout =  rope("");
long int i =  0;
for (; (i<len(ts->members)); i =  i+1) {

                    if (ts->members->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1505): ts->members[%d] with length %d\n", i, ts->members->length);
                        exit(1);
                    };
                    struct structMemb* m =  ts->members->data[i];
if ((strcmp(m->type, tt) == 0)) {
struct structMemb* ____BAH_COMPILER_VAR_429 = memoryAlloc(sizeof(struct structMemb));
____BAH_COMPILER_VAR_429->name = "";
____BAH_COMPILER_VAR_429->type = "";
____BAH_COMPILER_VAR_429->isConst = false;
____BAH_COMPILER_VAR_429->constVal = "";
____BAH_COMPILER_VAR_429->isArray = false;
____BAH_COMPILER_VAR_429->from = "";
____BAH_COMPILER_VAR_429->outterScope = false;
____BAH_COMPILER_VAR_429->isGlobal = false;
____BAH_COMPILER_VAR_429->def = "";
____BAH_COMPILER_VAR_429->isFn = false;
struct structMemb* nm =  ____BAH_COMPILER_VAR_429;
*nm =  *m;
m =  nm;
m->type =  "ptr";
}
struct Tok ____BAH_COMPILER_VAR_430 = {};
____BAH_COMPILER_VAR_430.cont = "";
____BAH_COMPILER_VAR_430.ogCont = "";
____BAH_COMPILER_VAR_430.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_430.pos = 0;
____BAH_COMPILER_VAR_430.line = 1;
____BAH_COMPILER_VAR_430.begLine = 1;
____BAH_COMPILER_VAR_430.bahType = "";
____BAH_COMPILER_VAR_430.isValue = false;
____BAH_COMPILER_VAR_430.isFunc = false;
____BAH_COMPILER_VAR_430.isOper = false;
struct Tok tmpT =  ____BAH_COMPILER_VAR_430;
tmpT.type =  TOKEN_TYPE_VAR;
char * sep =  "->";
if ((strCount(tt,"*")==0)) {
sep =  ".";
}
struct string mCtype =  getCType(m->type,elems);
struct string offsetTT =  string(tt);
offsetTT.replace((struct string*)&offsetTT,"*","");
char * ____BAH_COMPILER_VAR_431 =mCtype.str((struct string*)&mCtype);char * ____BAH_COMPILER_VAR_432 =offsetTT.str((struct string*)&offsetTT);char * ____BAH_COMPILER_VAR_433 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("(");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_431);
long int strLen_2 = strlen("*)((char*)(");
long int strLen_3 = strlen(t.cont);
long int strLen_4 = strlen(") + offsetof(struct ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_432);
long int strLen_6 = strlen(", ");
long int strLen_7 = strlen(m->name);
long int strLen_8 = strlen("))");
;                            
                    ____BAH_COMPILER_VAR_433 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                    
                    memcpy(____BAH_COMPILER_VAR_433+currStrOff, "(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_433+currStrOff, ____BAH_COMPILER_VAR_431, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_433+currStrOff, "*)((char*)(", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_433+currStrOff, t.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_433+currStrOff, ") + offsetof(struct ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_433+currStrOff, ____BAH_COMPILER_VAR_432, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_433+currStrOff, ", ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_433+currStrOff, m->name, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_433+currStrOff, "))", strLen_8);
                    currStrOff += strLen_8;
                    
                    ____BAH_COMPILER_VAR_433[currStrOff] = 0;
                }
                tmpT.cont =  ____BAH_COMPILER_VAR_433;
char * ____BAH_COMPILER_VAR_434 =offsetTT.str((struct string*)&offsetTT);char * ____BAH_COMPILER_VAR_435 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("offsetof(struct ");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_434);
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(m->name);
long int strLen_4 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_435 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_435+currStrOff, "offsetof(struct ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_435+currStrOff, ____BAH_COMPILER_VAR_434, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_435+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_435+currStrOff, m->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_435+currStrOff, ")", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_435[currStrOff] = 0;
                }
                struct Tok rt =  parseReflect(tmpT,m->type,elems,true,m->name,____BAH_COMPILER_VAR_435);
char * ____BAH_COMPILER_VAR_436 =intToStr(i);char * ____BAH_COMPILER_VAR_437 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(structLayout);
long int strLen_1 = strlen("->data[");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_436);
long int strLen_3 = strlen("] = ");
long int strLen_4 = strlen(rt.cont);
long int strLen_5 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_437 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    memcpy(____BAH_COMPILER_VAR_437+currStrOff, structLayout, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_437+currStrOff, "->data[", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_437+currStrOff, ____BAH_COMPILER_VAR_436, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_437+currStrOff, "] = ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_437+currStrOff, rt.cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_437+currStrOff, ";\n", strLen_5);
                    currStrOff += strLen_5;
                    
                    ____BAH_COMPILER_VAR_437[currStrOff] = 0;
                }
                dataLayout =  dataLayout->add(dataLayout, rope(____BAH_COMPILER_VAR_437));
};
char * ____BAH_COMPILER_VAR_438 =intToStr(len(ts->members));char * ____BAH_COMPILER_VAR_439 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n        array(struct reflectElement) * ");
long int strLen_1 = strlen(structLayout);
long int strLen_2 = strlen(" = memoryAlloc(sizeof(array(struct reflectElement)));\n        ");
long int strLen_3 = strlen(structLayout);
long int strLen_4 = strlen("->elemSize = sizeof(struct reflectElement);\n        ");
long int strLen_5 = strlen(structLayout);
long int strLen_6 = strlen("->length = ");
long int strLen_7 = strlen(____BAH_COMPILER_VAR_438);
long int strLen_8 = strlen(";\n        ");
long int strLen_9 = strlen(structLayout);
long int strLen_10 = strlen("->data = memoryAlloc(");
long int strLen_11 = strlen(structLayout);
long int strLen_12 = strlen("->length * ");
long int strLen_13 = strlen(structLayout);
long int strLen_14 = strlen("->elemSize);\n        ");
;                            
                    ____BAH_COMPILER_VAR_439 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14);
                    
                    memcpy(____BAH_COMPILER_VAR_439+currStrOff, "\n        array(struct reflectElement) * ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_439+currStrOff, structLayout, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_439+currStrOff, " = memoryAlloc(sizeof(array(struct reflectElement)));\n        ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_439+currStrOff, structLayout, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_439+currStrOff, "->elemSize = sizeof(struct reflectElement);\n        ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_439+currStrOff, structLayout, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_439+currStrOff, "->length = ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_439+currStrOff, ____BAH_COMPILER_VAR_438, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_439+currStrOff, ";\n        ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_439+currStrOff, structLayout, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_439+currStrOff, "->data = memoryAlloc(", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_439+currStrOff, structLayout, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_439+currStrOff, "->length * ", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_439+currStrOff, structLayout, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_439+currStrOff, "->elemSize);\n        ", strLen_14);
                    currStrOff += strLen_14;
                    
                    ____BAH_COMPILER_VAR_439[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_439))->add(OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_439)), dataLayout);
}
char * amp =  "";
if (((((strCount(tt,"*")==0)&&(strcmp(tt, "cpstring") != 0))&&(strcmp(tt, "ptr") != 0))&&(parsedPointer==false))) {
amp =  "&";
}
struct string name =  string(ogName);
if ((hasStructSep(name)==true)) {
name =  splitStructSepAfter(name);
}
struct string cType;
if (strHasPrefix(tt,"function(")) {
cType =  string("void*");
}
else {
cType =  getCType(tt,elems);
}
if (cType.hasPrefix((struct string*)&cType,"struct ")) {
cType.replace((struct string*)&cType,"*","");
}
if ((cType.length==0)) {
cType.set((struct string*)&cType,"0");
}
struct variable* ____BAH_COMPILER_VAR_440 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_440->name = "";
____BAH_COMPILER_VAR_440->type = "";
____BAH_COMPILER_VAR_440->isConst = false;
____BAH_COMPILER_VAR_440->constVal = "";
____BAH_COMPILER_VAR_440->isArray = false;
____BAH_COMPILER_VAR_440->from = "";
____BAH_COMPILER_VAR_440->outterScope = false;
____BAH_COMPILER_VAR_440->isGlobal = false;
struct variable* rv =  ____BAH_COMPILER_VAR_440;
rv->name =  genCompilerVar();
rv->type =  "reflectElement";

{
long nLength = len(elems->vars);
if (elems->vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(elems->vars->data, (nLength+50)*sizeof(struct variable*));
elems->vars->data = newPtr;
}
elems->vars->data[len(elems->vars)] =  rv;
elems->vars->length = nLength+1;
} else {
elems->vars->data[len(elems->vars)] =  rv;
}
};
char * ____BAH_COMPILER_VAR_441 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_442 =name.str((struct string*)&name);char * ____BAH_COMPILER_VAR_443 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("struct reflectElement ");
long int strLen_1 = strlen(rv->name);
long int strLen_2 = strlen(" = __reflect(");
long int strLen_3 = strlen(amp);
long int strLen_4 = strlen(t.cont);
long int strLen_5 = strlen(", sizeof(");
long int strLen_6 = strlen(____BAH_COMPILER_VAR_441);
long int strLen_7 = strlen("), \"");
long int strLen_8 = strlen(tt);
long int strLen_9 = strlen("\", \"");
long int strLen_10 = strlen(____BAH_COMPILER_VAR_442);
long int strLen_11 = strlen("\", ");
long int strLen_12 = strlen(isArr);
long int strLen_13 = strlen(", ");
long int strLen_14 = strlen(arrElem);
long int strLen_15 = strlen(", ");
long int strLen_16 = strlen(isStruct);
long int strLen_17 = strlen(", ");
long int strLen_18 = strlen(structLayout);
long int strLen_19 = strlen(", ");
long int strLen_20 = strlen(offset);
long int strLen_21 = strlen(");\n");
;                            
                    ____BAH_COMPILER_VAR_443 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14 + strLen_15 + strLen_16 + strLen_17 + strLen_18 + strLen_19 + strLen_20 + strLen_21);
                    
                    memcpy(____BAH_COMPILER_VAR_443+currStrOff, "struct reflectElement ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_443+currStrOff, rv->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_443+currStrOff, " = __reflect(", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_443+currStrOff, amp, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_443+currStrOff, t.cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_443+currStrOff, ", sizeof(", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_443+currStrOff, ____BAH_COMPILER_VAR_441, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_443+currStrOff, "), \"", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_443+currStrOff, tt, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_443+currStrOff, "\", \"", strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_443+currStrOff, ____BAH_COMPILER_VAR_442, strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_443+currStrOff, "\", ", strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_443+currStrOff, isArr, strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_443+currStrOff, ", ", strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_443+currStrOff, arrElem, strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_443+currStrOff, ", ", strLen_15);
                    currStrOff += strLen_15;
                    
                    memcpy(____BAH_COMPILER_VAR_443+currStrOff, isStruct, strLen_16);
                    currStrOff += strLen_16;
                    
                    memcpy(____BAH_COMPILER_VAR_443+currStrOff, ", ", strLen_17);
                    currStrOff += strLen_17;
                    
                    memcpy(____BAH_COMPILER_VAR_443+currStrOff, structLayout, strLen_18);
                    currStrOff += strLen_18;
                    
                    memcpy(____BAH_COMPILER_VAR_443+currStrOff, ", ", strLen_19);
                    currStrOff += strLen_19;
                    
                    memcpy(____BAH_COMPILER_VAR_443+currStrOff, offset, strLen_20);
                    currStrOff += strLen_20;
                    
                    memcpy(____BAH_COMPILER_VAR_443+currStrOff, ");\n", strLen_21);
                    currStrOff += strLen_21;
                    
                    ____BAH_COMPILER_VAR_443[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_443));
t.cont =  rv->name;
return t;
};
__BAH_ARR_TYPE_Tok parseFnCall(__BAH_ARR_TYPE_Tok l,lineType ltp,struct Elems* elems){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
char found =  false;
long int i =  0;
while ((i<len(l))) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1580): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    struct Tok t =  l->data[i];
if ((t.type==TOKEN_TYPE_VAR)) {
i =  i+1;
if ((i<len(l))) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1584): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    t =  l->data[i];
if ((strcmp(t.cont, "(") == 0)) {
found =  true;
break;
}
}
}
i =  i+1;
};
if ((found==false)) {
return l;
}
i =  0;
while ((i<len(l))) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1599): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    struct Tok ot =  l->data[i];
if ((ot.type==TOKEN_TYPE_VAR)) {
i =  i + 1;
if ((i<len(l))) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1604): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    struct Tok nt =  l->data[i];
if ((strcmp(nt.cont, "(") == 0)) {
long int nbPar =  1;
i =  i + 1;
char * fnName =  ot.cont;
struct func* fn =  searchFunc(fnName,elems,true);
if ((fn==null)) {
throwErr(&ot,"Unknown function {TOKEN}.");
}
struct string varName =  string("");
struct string fnStr =  string(fnName);
struct variable* arg1= null;
if (hasStructSep(fnStr)) {

                    if (fn->args->length <= 0) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1617): fn->args[%d] with length %d\n", 0, fn->args->length);
                        exit(1);
                    };
                    arg1 =  fn->args->data[0];
struct string fnarg1t =  getCType(arg1->type,elems);
varName =  fnStr;
struct string realFn =  splitStructSepAfter(fnStr);
varName.trimRight((struct string*)&varName,realFn.length);
char c =  varName.charAt((struct string*)&varName,varName.length - 1);
if ((c==46)) {
varName.trimRight((struct string*)&varName,1);
}
else {
varName.trimRight((struct string*)&varName,2);
}
char * varNameStr =  varName.str((struct string*)&varName);
struct variable* v =  searchVar(varNameStr,elems);
if ((v==null)) {
throwErr(&ot,"Cannot use {TOKEN} as a struct.");
}
if ((strCount(v->type,"*")==0)) {
varName.prepend((struct string*)&varName,"&");
}
char * ____BAH_COMPILER_VAR_444 =fnarg1t.str((struct string*)&fnarg1t);char * ____BAH_COMPILER_VAR_445 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("(");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_444);
long int strLen_2 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_445 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_445+currStrOff, "(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_445+currStrOff, ____BAH_COMPILER_VAR_444, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_445+currStrOff, ")", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_445[currStrOff] = 0;
                }
                varName.prepend((struct string*)&varName,____BAH_COMPILER_VAR_445);
}
char * ____BAH_COMPILER_VAR_446 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(fnName);
long int strLen_1 = strlen("(");
;                            
                    ____BAH_COMPILER_VAR_446 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_446+currStrOff, fnName, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_446+currStrOff, "(", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_446[currStrOff] = 0;
                }
                ot.cont =  ____BAH_COMPILER_VAR_446;
long int paramIndex =  0;
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
if ((varName.length>0)) {
struct Tok ____BAH_COMPILER_VAR_447 = {};
____BAH_COMPILER_VAR_447.cont = "";
____BAH_COMPILER_VAR_447.ogCont = "";
____BAH_COMPILER_VAR_447.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_447.pos = 0;
____BAH_COMPILER_VAR_447.line = 1;
____BAH_COMPILER_VAR_447.begLine = 1;
____BAH_COMPILER_VAR_447.bahType = "";
____BAH_COMPILER_VAR_447.isValue = false;
____BAH_COMPILER_VAR_447.isFunc = false;
____BAH_COMPILER_VAR_447.isOper = false;
struct Tok tk =  ____BAH_COMPILER_VAR_447;
tk.cont =  varName.str((struct string*)&varName);
tk.bahType =  arg1->type;
tk.type =  TOKEN_TYPE_VAR;
tk.isValue =  true;

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] =  tk;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  tk;
}
};

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1650): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    nt =  l->data[i];
if ((strcmp(nt.cont, ")") != 0)) {
struct Tok ____BAH_COMPILER_VAR_448 = {};
____BAH_COMPILER_VAR_448.cont = "";
____BAH_COMPILER_VAR_448.ogCont = "";
____BAH_COMPILER_VAR_448.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_448.pos = 0;
____BAH_COMPILER_VAR_448.line = 1;
____BAH_COMPILER_VAR_448.begLine = 1;
____BAH_COMPILER_VAR_448.bahType = "";
____BAH_COMPILER_VAR_448.isValue = false;
____BAH_COMPILER_VAR_448.isFunc = false;
____BAH_COMPILER_VAR_448.isOper = false;
tk =  ____BAH_COMPILER_VAR_448;
tk.cont =  ",";
tk.type =  TOKEN_TYPE_SYNTAX;
tk.isValue =  false;

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] =  tk;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  tk;
}
};
}
}
while ((i<len(l))) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1660): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    struct Tok t =  l->data[i];
if ((strcmp(t.cont, "(") == 0)) {
nbPar =  nbPar + 1;
}
else if ((strcmp(t.cont, ")") == 0)) {
nbPar =  nbPar - 1;
}

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] =  t;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  t;
}
};
if ((nbPar==0)) {
i =  i + 1;
break;
}
i =  i + 1;
};
if ((strcmp(fnName, "noCheck") == 0)) {
ot.cont =  "";
long int j =  0;
while ((j<len(memory)-1)) {

                    if (memory->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1677): memory[%d] with length %d\n", j, memory->length);
                        exit(1);
                    };
                    struct Tok t =  memory->data[j];
char * ____BAH_COMPILER_VAR_449 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ot.cont);
long int strLen_1 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_449 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_449+currStrOff, ot.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_449+currStrOff, t.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_449[currStrOff] = 0;
                }
                ot.cont =  ____BAH_COMPILER_VAR_449;
j =  j + 1;
};
ot.cont =  ot.cont;
ot.type =  TOKEN_TYPE_FUNC;
ot.isFunc =  true;
ot.bahType =  "ptr";

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  ot;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  ot;
}
};
continue;
}
if ((strcmp(fnName, "panic") == 0)) {
char * ____BAH_COMPILER_VAR_450 =intToStr(ot.line);char * ____BAH_COMPILER_VAR_451 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\"");
long int strLen_1 = strlen(compilerState.currentFile);
long int strLen_2 = strlen(":");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_450);
long int strLen_4 = strlen("\"");
;                            
                    ____BAH_COMPILER_VAR_451 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_451+currStrOff, "\"", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_451+currStrOff, compilerState.currentFile, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_451+currStrOff, ":", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_451+currStrOff, ____BAH_COMPILER_VAR_450, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_451+currStrOff, "\"", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_451[currStrOff] = 0;
                }
                char * currLine =  ____BAH_COMPILER_VAR_451;

                    if (memory->length <= len(memory)-1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1691): memory[%d] with length %d\n", len(memory)-1, memory->length);
                        exit(1);
                    };
                    struct Tok par =  memory->data[len(memory)-1];
long int cl =  par.line;
struct Tok ____BAH_COMPILER_VAR_452 = {};
____BAH_COMPILER_VAR_452.cont = "";
____BAH_COMPILER_VAR_452.ogCont = "";
____BAH_COMPILER_VAR_452.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_452.pos = 0;
____BAH_COMPILER_VAR_452.line = 1;
____BAH_COMPILER_VAR_452.begLine = 1;
____BAH_COMPILER_VAR_452.bahType = "";
____BAH_COMPILER_VAR_452.isValue = false;
____BAH_COMPILER_VAR_452.isFunc = false;
____BAH_COMPILER_VAR_452.isOper = false;
____BAH_COMPILER_VAR_452.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_452.cont = ",";
____BAH_COMPILER_VAR_452.line = cl;

{
long nLength = len(memory)-1;
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)-1] =  ____BAH_COMPILER_VAR_452;
memory->length = nLength+1;
} else {
memory->data[len(memory)-1] =  ____BAH_COMPILER_VAR_452;
}
};
struct Tok ____BAH_COMPILER_VAR_453 = {};
____BAH_COMPILER_VAR_453.cont = "";
____BAH_COMPILER_VAR_453.ogCont = "";
____BAH_COMPILER_VAR_453.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_453.pos = 0;
____BAH_COMPILER_VAR_453.line = 1;
____BAH_COMPILER_VAR_453.begLine = 1;
____BAH_COMPILER_VAR_453.bahType = "";
____BAH_COMPILER_VAR_453.isValue = false;
____BAH_COMPILER_VAR_453.isFunc = false;
____BAH_COMPILER_VAR_453.isOper = false;
____BAH_COMPILER_VAR_453.type = TOKEN_TYPE_STR;
____BAH_COMPILER_VAR_453.cont = currLine;
____BAH_COMPILER_VAR_453.line = cl;

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] =  ____BAH_COMPILER_VAR_453;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  ____BAH_COMPILER_VAR_453;
}
};

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] =  par;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  par;
}
};
fnName =  "__BAH_panic";
char * ____BAH_COMPILER_VAR_454 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(fnName);
long int strLen_1 = strlen("(");
;                            
                    ____BAH_COMPILER_VAR_454 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_454+currStrOff, fnName, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_454+currStrOff, "(", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_454[currStrOff] = 0;
                }
                ot.cont =  ____BAH_COMPILER_VAR_454;
fn =  searchFunc(fnName,elems,true);
}
else if ((strcmp(fnName, "__dumpSymbols") == 0)) {
char * ____BAH_COMPILER_VAR_455 =intToStr(ot.line);char * ____BAH_COMPILER_VAR_456 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\"");
long int strLen_1 = strlen(compilerState.currentFile);
long int strLen_2 = strlen(":");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_455);
long int strLen_4 = strlen("\"");
;                            
                    ____BAH_COMPILER_VAR_456 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_456+currStrOff, "\"", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_456+currStrOff, compilerState.currentFile, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_456+currStrOff, ":", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_456+currStrOff, ____BAH_COMPILER_VAR_455, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_456+currStrOff, "\"", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_456[currStrOff] = 0;
                }
                char * currLine =  ____BAH_COMPILER_VAR_456;

                    if (memory->length <= len(memory)-1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1709): memory[%d] with length %d\n", len(memory)-1, memory->length);
                        exit(1);
                    };
                    struct Tok par =  memory->data[len(memory)-1];
long int cl =  par.line;
memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
array(struct variable*)* symbols = memoryAlloc(sizeof(array(struct variable*)));

symbols->length = 0;
symbols->elemSize = sizeof(struct variable*);
long int j =  0;
for (; (j<len(elems->vars)); j =  j+1) {

                    if (elems->vars->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1715): elems->vars[%d] with length %d\n", j, elems->vars->length);
                        exit(1);
                    };
                    struct variable* v =  elems->vars->data[j];
if ((v->isConst==false)) {

{
long nLength = len(symbols);
if (symbols->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(symbols->data, (nLength+50)*sizeof(struct variable*));
symbols->data = newPtr;
}
symbols->data[len(symbols)] =  v;
symbols->length = nLength+1;
} else {
symbols->data[len(symbols)] =  v;
}
};
}
};
struct variable* ____BAH_COMPILER_VAR_457 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_457->name = "";
____BAH_COMPILER_VAR_457->type = "";
____BAH_COMPILER_VAR_457->isConst = false;
____BAH_COMPILER_VAR_457->constVal = "";
____BAH_COMPILER_VAR_457->isArray = false;
____BAH_COMPILER_VAR_457->from = "";
____BAH_COMPILER_VAR_457->outterScope = false;
____BAH_COMPILER_VAR_457->isGlobal = false;
____BAH_COMPILER_VAR_457->name = genCompilerVar();
____BAH_COMPILER_VAR_457->type = "[]reflectElement";
____BAH_COMPILER_VAR_457->isArray = true;
struct variable* tmpV =  ____BAH_COMPILER_VAR_457;

{
long nLength = len(elems->vars);
if (elems->vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(elems->vars->data, (nLength+50)*sizeof(struct variable*));
elems->vars->data = newPtr;
}
elems->vars->data[len(elems->vars)] =  tmpV;
elems->vars->length = nLength+1;
} else {
elems->vars->data[len(elems->vars)] =  tmpV;
}
};
char * decls =  "";
j =  0;
for (; (j<len(symbols)); j =  j+1) {

                    if (symbols->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1730): symbols[%d] with length %d\n", j, symbols->length);
                        exit(1);
                    };
                    struct variable* v =  symbols->data[j];
char * vname =  v->name;
if ((strCount(v->type,"*")==0)) {
char * ____BAH_COMPILER_VAR_458 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("&");
long int strLen_1 = strlen(v->name);
;                            
                    ____BAH_COMPILER_VAR_458 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_458+currStrOff, "&", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_458+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_458[currStrOff] = 0;
                }
                vname =  ____BAH_COMPILER_VAR_458;
}
struct Tok ____BAH_COMPILER_VAR_459 = {};
____BAH_COMPILER_VAR_459.cont = "";
____BAH_COMPILER_VAR_459.ogCont = "";
____BAH_COMPILER_VAR_459.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_459.pos = 0;
____BAH_COMPILER_VAR_459.line = 1;
____BAH_COMPILER_VAR_459.begLine = 1;
____BAH_COMPILER_VAR_459.bahType = "";
____BAH_COMPILER_VAR_459.isValue = false;
____BAH_COMPILER_VAR_459.isFunc = false;
____BAH_COMPILER_VAR_459.isOper = false;
____BAH_COMPILER_VAR_459.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_459.cont = vname;
____BAH_COMPILER_VAR_459.bahType = v->type;
____BAH_COMPILER_VAR_459.isValue = true;
struct Tok tmpT =  ____BAH_COMPILER_VAR_459;
tmpT =  parseReflect(tmpT,v->type,elems,true,v->name,"0");
char * ____BAH_COMPILER_VAR_460 =intToStr(j);char * ____BAH_COMPILER_VAR_461 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tmpV->name);
long int strLen_1 = strlen("->data[");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_460);
long int strLen_3 = strlen("] = ");
long int strLen_4 = strlen(tmpT.cont);
long int strLen_5 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_461 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    memcpy(____BAH_COMPILER_VAR_461+currStrOff, tmpV->name, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_461+currStrOff, "->data[", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_461+currStrOff, ____BAH_COMPILER_VAR_460, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_461+currStrOff, "] = ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_461+currStrOff, tmpT.cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_461+currStrOff, ";\n", strLen_5);
                    currStrOff += strLen_5;
                    
                    ____BAH_COMPILER_VAR_461[currStrOff] = 0;
                }
                char * ____BAH_COMPILER_VAR_462 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(decls);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_461);
;                            
                    ____BAH_COMPILER_VAR_462 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_462+currStrOff, decls, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_462+currStrOff, ____BAH_COMPILER_VAR_461, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_462[currStrOff] = 0;
                }
                decls =  ____BAH_COMPILER_VAR_462;
};
char * ____BAH_COMPILER_VAR_463 =intToStr(len(symbols));char * ____BAH_COMPILER_VAR_464 =intToStr(len(symbols));char * ____BAH_COMPILER_VAR_465 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n                        array(struct reflectElement)* ");
long int strLen_1 = strlen(tmpV->name);
long int strLen_2 = strlen(" = memoryAlloc(sizeof(array(struct reflectElement)));\n                        ");
long int strLen_3 = strlen(tmpV->name);
long int strLen_4 = strlen("->data = memoryAlloc(sizeof(struct reflectElement) * ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_463);
long int strLen_6 = strlen(");\n                        ");
long int strLen_7 = strlen(tmpV->name);
long int strLen_8 = strlen("->length = ");
long int strLen_9 = strlen(____BAH_COMPILER_VAR_464);
long int strLen_10 = strlen(";\n                        ");
long int strLen_11 = strlen(tmpV->name);
long int strLen_12 = strlen("->elemSize = sizeof(struct reflectElement);\n                        ");
long int strLen_13 = strlen(decls);
long int strLen_14 = strlen("\n                        ");
;                            
                    ____BAH_COMPILER_VAR_465 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14);
                    
                    memcpy(____BAH_COMPILER_VAR_465+currStrOff, "\n                        array(struct reflectElement)* ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_465+currStrOff, tmpV->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_465+currStrOff, " = memoryAlloc(sizeof(array(struct reflectElement)));\n                        ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_465+currStrOff, tmpV->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_465+currStrOff, "->data = memoryAlloc(sizeof(struct reflectElement) * ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_465+currStrOff, ____BAH_COMPILER_VAR_463, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_465+currStrOff, ");\n                        ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_465+currStrOff, tmpV->name, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_465+currStrOff, "->length = ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_465+currStrOff, ____BAH_COMPILER_VAR_464, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_465+currStrOff, ";\n                        ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_465+currStrOff, tmpV->name, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_465+currStrOff, "->elemSize = sizeof(struct reflectElement);\n                        ", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_465+currStrOff, decls, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_465+currStrOff, "\n                        ", strLen_14);
                    currStrOff += strLen_14;
                    
                    ____BAH_COMPILER_VAR_465[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_465));
struct Tok ____BAH_COMPILER_VAR_466 = {};
____BAH_COMPILER_VAR_466.cont = "";
____BAH_COMPILER_VAR_466.ogCont = "";
____BAH_COMPILER_VAR_466.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_466.pos = 0;
____BAH_COMPILER_VAR_466.line = 1;
____BAH_COMPILER_VAR_466.begLine = 1;
____BAH_COMPILER_VAR_466.bahType = "";
____BAH_COMPILER_VAR_466.isValue = false;
____BAH_COMPILER_VAR_466.isFunc = false;
____BAH_COMPILER_VAR_466.isOper = false;
____BAH_COMPILER_VAR_466.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_466.cont = tmpV->name;
____BAH_COMPILER_VAR_466.line = cl;
____BAH_COMPILER_VAR_466.isValue = true;

{
long nLength = 0;
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[0] =  ____BAH_COMPILER_VAR_466;
memory->length = nLength+1;
} else {
memory->data[0] =  ____BAH_COMPILER_VAR_466;
}
};

{
long nLength = 1;
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[1] =  par;
memory->length = nLength+1;
} else {
memory->data[1] =  par;
}
};
}
else if ((strcmp(fnName, "breakPoint") == 0)) {
char * ____BAH_COMPILER_VAR_467 =intToStr(ot.line);char * ____BAH_COMPILER_VAR_468 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\"");
long int strLen_1 = strlen(compilerState.currentFile);
long int strLen_2 = strlen(":");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_467);
long int strLen_4 = strlen("\"");
;                            
                    ____BAH_COMPILER_VAR_468 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_468+currStrOff, "\"", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_468+currStrOff, compilerState.currentFile, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_468+currStrOff, ":", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_468+currStrOff, ____BAH_COMPILER_VAR_467, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_468+currStrOff, "\"", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_468[currStrOff] = 0;
                }
                char * currLine =  ____BAH_COMPILER_VAR_468;

                    if (memory->length <= len(memory)-1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1764): memory[%d] with length %d\n", len(memory)-1, memory->length);
                        exit(1);
                    };
                    struct Tok par =  memory->data[len(memory)-1];
long int cl =  par.line;
struct Tok ____BAH_COMPILER_VAR_469 = {};
____BAH_COMPILER_VAR_469.cont = "";
____BAH_COMPILER_VAR_469.ogCont = "";
____BAH_COMPILER_VAR_469.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_469.pos = 0;
____BAH_COMPILER_VAR_469.line = 1;
____BAH_COMPILER_VAR_469.begLine = 1;
____BAH_COMPILER_VAR_469.bahType = "";
____BAH_COMPILER_VAR_469.isValue = false;
____BAH_COMPILER_VAR_469.isFunc = false;
____BAH_COMPILER_VAR_469.isOper = false;
____BAH_COMPILER_VAR_469.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_469.cont = "__dumpSymbols";
____BAH_COMPILER_VAR_469.line = cl;
struct Tok ____BAH_COMPILER_VAR_470 = {};
____BAH_COMPILER_VAR_470.cont = "";
____BAH_COMPILER_VAR_470.ogCont = "";
____BAH_COMPILER_VAR_470.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_470.pos = 0;
____BAH_COMPILER_VAR_470.line = 1;
____BAH_COMPILER_VAR_470.begLine = 1;
____BAH_COMPILER_VAR_470.bahType = "";
____BAH_COMPILER_VAR_470.isValue = false;
____BAH_COMPILER_VAR_470.isFunc = false;
____BAH_COMPILER_VAR_470.isOper = false;
____BAH_COMPILER_VAR_470.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_470.cont = "(";
____BAH_COMPILER_VAR_470.line = cl;
struct Tok ____BAH_COMPILER_VAR_471 = {};
____BAH_COMPILER_VAR_471.cont = "";
____BAH_COMPILER_VAR_471.ogCont = "";
____BAH_COMPILER_VAR_471.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_471.pos = 0;
____BAH_COMPILER_VAR_471.line = 1;
____BAH_COMPILER_VAR_471.begLine = 1;
____BAH_COMPILER_VAR_471.bahType = "";
____BAH_COMPILER_VAR_471.isValue = false;
____BAH_COMPILER_VAR_471.isFunc = false;
____BAH_COMPILER_VAR_471.isOper = false;
____BAH_COMPILER_VAR_471.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_471.cont = ")";
____BAH_COMPILER_VAR_471.line = cl;
memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 3;
memory->elemSize = sizeof(struct Tok);
memory->data = memoryAlloc(sizeof(struct Tok) * 50);memory->data[0] = ____BAH_COMPILER_VAR_469;
memory->data[1] = ____BAH_COMPILER_VAR_470;
memory->data[2] = ____BAH_COMPILER_VAR_471;
memory =  parseFnCall(memory,(lineType)-1,elems);
struct Tok ____BAH_COMPILER_VAR_472 = {};
____BAH_COMPILER_VAR_472.cont = "";
____BAH_COMPILER_VAR_472.ogCont = "";
____BAH_COMPILER_VAR_472.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_472.pos = 0;
____BAH_COMPILER_VAR_472.line = 1;
____BAH_COMPILER_VAR_472.begLine = 1;
____BAH_COMPILER_VAR_472.bahType = "";
____BAH_COMPILER_VAR_472.isValue = false;
____BAH_COMPILER_VAR_472.isFunc = false;
____BAH_COMPILER_VAR_472.isOper = false;
____BAH_COMPILER_VAR_472.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_472.cont = ",";
____BAH_COMPILER_VAR_472.line = cl;

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] =  ____BAH_COMPILER_VAR_472;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  ____BAH_COMPILER_VAR_472;
}
};
struct Tok ____BAH_COMPILER_VAR_473 = {};
____BAH_COMPILER_VAR_473.cont = "";
____BAH_COMPILER_VAR_473.ogCont = "";
____BAH_COMPILER_VAR_473.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_473.pos = 0;
____BAH_COMPILER_VAR_473.line = 1;
____BAH_COMPILER_VAR_473.begLine = 1;
____BAH_COMPILER_VAR_473.bahType = "";
____BAH_COMPILER_VAR_473.isValue = false;
____BAH_COMPILER_VAR_473.isFunc = false;
____BAH_COMPILER_VAR_473.isOper = false;
____BAH_COMPILER_VAR_473.type = TOKEN_TYPE_STR;
____BAH_COMPILER_VAR_473.cont = currLine;
____BAH_COMPILER_VAR_473.line = cl;

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] =  ____BAH_COMPILER_VAR_473;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  ____BAH_COMPILER_VAR_473;
}
};

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] =  par;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  par;
}
};
fnName =  "breakPoint__inner";
char * ____BAH_COMPILER_VAR_474 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(fnName);
long int strLen_1 = strlen("(");
;                            
                    ____BAH_COMPILER_VAR_474 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_474+currStrOff, fnName, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_474+currStrOff, "(", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_474[currStrOff] = 0;
                }
                ot.cont =  ____BAH_COMPILER_VAR_474;
fn =  searchFunc(fnName,elems,true);
}
else if ((strcmp(fnName, "sizeof") == 0)) {
char * tp =  "";
long int j =  0;
for (; (j<len(memory)-1); j =  j+1) {

                    if (memory->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1805): memory[%d] with length %d\n", j, memory->length);
                        exit(1);
                    };
                    struct Tok t =  memory->data[j];
char * ____BAH_COMPILER_VAR_475 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tp);
long int strLen_1 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_475 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_475+currStrOff, tp, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_475+currStrOff, t.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_475[currStrOff] = 0;
                }
                tp =  ____BAH_COMPILER_VAR_475;
};
struct string cType =  getCType(tp,elems);
char * ____BAH_COMPILER_VAR_476 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_477 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_476);
long int strLen_1 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_477 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_477+currStrOff, ____BAH_COMPILER_VAR_476, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_477+currStrOff, ")", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_477[currStrOff] = 0;
                }
                char * ____BAH_COMPILER_VAR_478 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ot.cont);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_477);
;                            
                    ____BAH_COMPILER_VAR_478 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_478+currStrOff, ot.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_478+currStrOff, ____BAH_COMPILER_VAR_477, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_478[currStrOff] = 0;
                }
                ot.cont =  ____BAH_COMPILER_VAR_478;
ot.type =  TOKEN_TYPE_FUNC;
ot.isFunc =  true;
ot.bahType =  "int";

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  ot;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  ot;
}
};
continue;
}
memory =  prePross(memory,ltp,elems);

                    if (memory->length <= 0) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1830): memory[%d] with length %d\n", 0, memory->length);
                        exit(1);
                    };
                    struct Tok ft =  memory->data[0];
array(struct Tok)* fnArgs = memoryAlloc(sizeof(array(struct Tok)));

fnArgs->length = 0;
fnArgs->elemSize = sizeof(struct Tok);
if ((strcmp(ft.cont, ")") != 0)) {
long int j =  0;
while ((j<len(memory))) {

                    if (memory->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1837): memory[%d] with length %d\n", j, memory->length);
                        exit(1);
                    };
                    struct Tok t =  memory->data[j];
if ((paramIndex>=len(fn->args))) {
throwErr(&t,"Too many arguments in function call.");
}

                    if (fn->args->length <= paramIndex) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1842): fn->args[%d] with length %d\n", paramIndex, fn->args->length);
                        exit(1);
                    };
                    struct variable* arg =  fn->args->data[paramIndex];
char * tt =  getTypeFromToken(&t,true,elems);
if (((strcmp(arg->type, "reflectElement") == 0)&&(strcmp(tt, "reflectElement") != 0))) {
t =  parseReflect(t,tt,elems,false,t.cont,"0");
tt =  "reflectElement";
}
if ((compTypes(tt,arg->type)==false)) {
char * ____BAH_COMPILER_VAR_479 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(tt);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(arg->type);
long int strLen_4 = strlen(" in function call.");
;                            
                    ____BAH_COMPILER_VAR_479 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_479+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_479+currStrOff, tt, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_479+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_479+currStrOff, arg->type, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_479+currStrOff, " in function call.", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_479[currStrOff] = 0;
                }
                throwErr(&t,____BAH_COMPILER_VAR_479);
}
if (((t.type==TOKEN_TYPE_FUNC)&&(strHasPrefix(t.cont,"noCheck(")==false))) {
struct string ____BAH_COMPILER_VAR_480 =string(t.cont);char * afnName =  splitStringBefore(____BAH_COMPILER_VAR_480,"(");
struct func* afn =  searchFunc(afnName,elems,true);
if (((afn!=null)&&(isRCPtype(afn->returns->type,elems)==true))) {
t.cont =  registerRCPvar(afn->returns->type,t.cont,elems);
}
}
if ((verboseRuntime==true)) {

{
long nLength = len(fnArgs);
if (fnArgs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(fnArgs->data, (nLength+50)*sizeof(struct Tok));
fnArgs->data = newPtr;
}
fnArgs->data[len(fnArgs)] =  t;
fnArgs->length = nLength+1;
} else {
fnArgs->data[len(fnArgs)] =  t;
}
};
}
char * ____BAH_COMPILER_VAR_481 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ot.cont);
long int strLen_1 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_481 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_481+currStrOff, ot.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_481+currStrOff, t.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_481[currStrOff] = 0;
                }
                ot.cont =  ____BAH_COMPILER_VAR_481;
j =  j + 1;

                    if (memory->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1868): memory[%d] with length %d\n", j, memory->length);
                        exit(1);
                    };
                    t =  memory->data[j];
if ((strcmp(t.cont, ",") != 0)) {
if ((strcmp(t.cont, ")") == 0)) {
j =  j + 1;
paramIndex =  paramIndex + 1;
break;
}
else {
throwErr(&t,"Expected separator between values, not {TOKEN} in function call.");
}
}
else {
paramIndex =  paramIndex + 1;
char * ____BAH_COMPILER_VAR_482 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ot.cont);
long int strLen_1 = strlen(",");
;                            
                    ____BAH_COMPILER_VAR_482 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_482+currStrOff, ot.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_482+currStrOff, ",", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_482[currStrOff] = 0;
                }
                ot.cont =  ____BAH_COMPILER_VAR_482;
}
j =  j + 1;
};
}
if ((paramIndex<len(fn->args))) {
ot.cont =  fnName;
throwErr(&ot,"Not enough arguments in function call, ending by {TOKEN}.");
}
if ((strcmp(fn->name, "ser") == 0)) {
ot.cont =  parseSerialize(memory->data[0],elems);
}
else {
char * ____BAH_COMPILER_VAR_483 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ot.cont);
long int strLen_1 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_483 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_483+currStrOff, ot.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_483+currStrOff, ")", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_483[currStrOff] = 0;
                }
                ot.cont =  ____BAH_COMPILER_VAR_483;
}
ot.type =  TOKEN_TYPE_FUNC;
ot.bahType =  fn->returns->type;
ot.isFunc =  true;

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  ot;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  ot;
}
};

                    if (l->length <= 0) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1904): l[%d] with length %d\n", 0, l->length);
                        exit(1);
                    };
                    ft =  l->data[0];
if (((verboseRuntime==true)&&(ltp!=LINE_TYPE_ELSE))) {
verboseOutFunc(fn,fnArgs,ft.line,elems);
}
continue;
}
}
i =  i-1;
}

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  ot;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  ot;
}
};
i =  i+1;
};
return nl;
};
char * parseArrayDecl(struct variable* v,__BAH_ARR_TYPE_Tok l,long int i,long int max,struct Elems* elems){
long int arrayLength =  0;
struct string arrType =  getCType(v->type,elems);
arrType.trimRight((struct string*)&arrType,1);
char * ____BAH_COMPILER_VAR_484 =arrType.str((struct string*)&arrType);char * ____BAH_COMPILER_VAR_485 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("memoryAlloc(sizeof(");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_484);
long int strLen_2 = strlen("))");
;                            
                    ____BAH_COMPILER_VAR_485 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_485+currStrOff, "memoryAlloc(sizeof(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_485+currStrOff, ____BAH_COMPILER_VAR_484, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_485+currStrOff, "))", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_485[currStrOff] = 0;
                }
                char * code =  ____BAH_COMPILER_VAR_485;
arrType.trimLeft((struct string*)&arrType,6);
arrType.trimRight((struct string*)&arrType,1);
char * elemTypeStr =  arrType.str((struct string*)&arrType);
if ((i + 1!=max)) {
i =  i+1;

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1934): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    struct Tok nt =  l->data[i];
if ((strcmp(nt.cont, "{") != 0)) {
throwErr(&l->data[i + 1],"{TOKEN} not expected after array initialization.");
}
struct string elemBahType =  string(v->type);
elemBahType.trimLeft((struct string*)&elemBahType,2);
char * elemBahTypeStr =  elemBahType.str((struct string*)&elemBahType);
i =  i + 1;
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
while ((i<max)) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1944): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    
{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] =  l->data[i];
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  l->data[i];
}
};
i =  i + 1;
};
memory =  prePross(memory,(lineType)-1,elems);
i =  0;
while ((i<len(memory))) {

                    if (memory->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1949): memory[%d] with length %d\n", i, memory->length);
                        exit(1);
                    };
                    struct Tok t =  memory->data[i];
if ((strcmp(t.cont, "{") == 0)) {
long int j =  i-1;
long int nbBraces =  0;
for (; (i<len(memory)); i =  i+1) {

                    if (memory->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1955): memory[%d] with length %d\n", i, memory->length);
                        exit(1);
                    };
                    struct Tok tmpT =  memory->data[i];
if ((strcmp(tmpT.cont, "{") == 0)) {
nbBraces =  nbBraces+1;
}
else if ((strcmp(tmpT.cont, "}") == 0)) {
nbBraces =  nbBraces-1;
}
if ((nbBraces==0)) {
break;
}
};
struct variable* ____BAH_COMPILER_VAR_486 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_486->name = "";
____BAH_COMPILER_VAR_486->type = "";
____BAH_COMPILER_VAR_486->isConst = false;
____BAH_COMPILER_VAR_486->constVal = "";
____BAH_COMPILER_VAR_486->isArray = false;
____BAH_COMPILER_VAR_486->from = "";
____BAH_COMPILER_VAR_486->outterScope = false;
____BAH_COMPILER_VAR_486->isGlobal = false;
struct variable* tmpV =  ____BAH_COMPILER_VAR_486;
tmpV->name =  genCompilerVar();
struct string elemType =  string(v->type);
elemType.trimLeft((struct string*)&elemType,2);
tmpV->type =  elemType.str((struct string*)&elemType);

{
long nLength = len(elems->vars);
if (elems->vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(elems->vars->data, (nLength+50)*sizeof(struct variable*));
elems->vars->data = newPtr;
}
elems->vars->data[len(elems->vars)] =  tmpV;
elems->vars->length = nLength+1;
} else {
elems->vars->data[len(elems->vars)] =  tmpV;
}
};
char * oldNL =  NEXT_LINE;
NEXT_LINE =  "";
char * innerCode =  parseArrayDecl(tmpV,memory,j,i + 1,elems);
char * ____BAH_COMPILER_VAR_487 =elemType.str((struct string*)&elemType);struct string cType =  getCType(____BAH_COMPILER_VAR_487,elems);
char * ____BAH_COMPILER_VAR_488 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_489 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n                array(");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_488);
long int strLen_2 = strlen(") * ");
long int strLen_3 = strlen(tmpV->name);
long int strLen_4 = strlen(" = ");
long int strLen_5 = strlen(innerCode);
long int strLen_6 = strlen(";\n                ");
long int strLen_7 = strlen(NEXT_LINE);
long int strLen_8 = strlen("\n                ");
;                            
                    ____BAH_COMPILER_VAR_489 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                    
                    memcpy(____BAH_COMPILER_VAR_489+currStrOff, "\n                array(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_489+currStrOff, ____BAH_COMPILER_VAR_488, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_489+currStrOff, ") * ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_489+currStrOff, tmpV->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_489+currStrOff, " = ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_489+currStrOff, innerCode, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_489+currStrOff, ";\n                ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_489+currStrOff, NEXT_LINE, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_489+currStrOff, "\n                ", strLen_8);
                    currStrOff += strLen_8;
                    
                    ____BAH_COMPILER_VAR_489[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_489));
NEXT_LINE =  oldNL;
struct Tok ____BAH_COMPILER_VAR_490 = {};
____BAH_COMPILER_VAR_490.cont = "";
____BAH_COMPILER_VAR_490.ogCont = "";
____BAH_COMPILER_VAR_490.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_490.pos = 0;
____BAH_COMPILER_VAR_490.line = 1;
____BAH_COMPILER_VAR_490.begLine = 1;
____BAH_COMPILER_VAR_490.bahType = "";
____BAH_COMPILER_VAR_490.isValue = false;
____BAH_COMPILER_VAR_490.isFunc = false;
____BAH_COMPILER_VAR_490.isOper = false;
____BAH_COMPILER_VAR_490.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_490.cont = tmpV->name;
____BAH_COMPILER_VAR_490.bahType = elemType.str((struct string*)&elemType);
____BAH_COMPILER_VAR_490.isValue = true;
t =  ____BAH_COMPILER_VAR_490;
}
char * tt =  getTypeFromToken(&t,true,elems);
if ((compTypes(tt,elemBahTypeStr)==false)) {
char * ____BAH_COMPILER_VAR_491 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(tt);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(elemBahTypeStr);
;                            
                    ____BAH_COMPILER_VAR_491 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                    
                    memcpy(____BAH_COMPILER_VAR_491+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_491+currStrOff, tt, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_491+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_491+currStrOff, elemBahTypeStr, strLen_3);
                    currStrOff += strLen_3;
                    
                    ____BAH_COMPILER_VAR_491[currStrOff] = 0;
                }
                throwErr(&t,____BAH_COMPILER_VAR_491);
}
char * strArrayLength =  intToStr(arrayLength);
arrayLength =  arrayLength + 1;
char * ____BAH_COMPILER_VAR_492 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(NEXT_LINE);
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen("->data[");
long int strLen_3 = strlen(strArrayLength);
long int strLen_4 = strlen("] = ");
long int strLen_5 = strlen(t.cont);
long int strLen_6 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_492 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                    
                    memcpy(____BAH_COMPILER_VAR_492+currStrOff, NEXT_LINE, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_492+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_492+currStrOff, "->data[", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_492+currStrOff, strArrayLength, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_492+currStrOff, "] = ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_492+currStrOff, t.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_492+currStrOff, ";\n", strLen_6);
                    currStrOff += strLen_6;
                    
                    ____BAH_COMPILER_VAR_492[currStrOff] = 0;
                }
                NEXT_LINE =  ____BAH_COMPILER_VAR_492;
i =  i+1;

                    if (memory->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2000): memory[%d] with length %d\n", i, memory->length);
                        exit(1);
                    };
                    t =  memory->data[i];
if ((strcmp(t.cont, ",") != 0)) {
if ((strcmp(t.cont, "}") == 0)) {
long int allocLength =  arrayLength;
if ((allocLength>50)) {
long int modAllocAmm =  allocLength % 50;
allocLength =  allocLength + modAllocAmm;
}
else {
allocLength =  50;
}
char * allocLengthStr =  intToStr(allocLength);
char * ____BAH_COMPILER_VAR_493 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen("->data = memoryAlloc(sizeof(");
long int strLen_2 = strlen(elemTypeStr);
long int strLen_3 = strlen(") * ");
long int strLen_4 = strlen(allocLengthStr);
long int strLen_5 = strlen(");");
long int strLen_6 = strlen(NEXT_LINE);
;                            
                    ____BAH_COMPILER_VAR_493 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                    
                    memcpy(____BAH_COMPILER_VAR_493+currStrOff, v->name, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_493+currStrOff, "->data = memoryAlloc(sizeof(", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_493+currStrOff, elemTypeStr, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_493+currStrOff, ") * ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_493+currStrOff, allocLengthStr, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_493+currStrOff, ");", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_493+currStrOff, NEXT_LINE, strLen_6);
                    currStrOff += strLen_6;
                    
                    ____BAH_COMPILER_VAR_493[currStrOff] = 0;
                }
                NEXT_LINE =  ____BAH_COMPILER_VAR_493;
break;
}
else {
throwErr(&t,"Expected ',' got {TOKEN}.");
}
}
i =  i + 1;
};
}
char * strArrayLength =  intToStr(arrayLength);
char * ____BAH_COMPILER_VAR_494 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen("->length = ");
long int strLen_3 = strlen(strArrayLength);
long int strLen_4 = strlen(";\n");
long int strLen_5 = strlen(v->name);
long int strLen_6 = strlen("->elemSize = sizeof(");
long int strLen_7 = strlen(elemTypeStr);
long int strLen_8 = strlen(");\n");
long int strLen_9 = strlen(NEXT_LINE);
;                            
                    ____BAH_COMPILER_VAR_494 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9);
                    
                    memcpy(____BAH_COMPILER_VAR_494+currStrOff, "\n", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_494+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_494+currStrOff, "->length = ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_494+currStrOff, strArrayLength, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_494+currStrOff, ";\n", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_494+currStrOff, v->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_494+currStrOff, "->elemSize = sizeof(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_494+currStrOff, elemTypeStr, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_494+currStrOff, ");\n", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_494+currStrOff, NEXT_LINE, strLen_9);
                    currStrOff += strLen_9;
                    
                    ____BAH_COMPILER_VAR_494[currStrOff] = 0;
                }
                NEXT_LINE =  ____BAH_COMPILER_VAR_494;
return code;
};
array(char *)* equalsTokens;
void parseVar(__BAH_ARR_TYPE_Tok l,struct Elems* elems){

                    if (l->length <= 0) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2032): l[%d] with length %d\n", 0, l->length);
                        exit(1);
                    };
                    struct Tok ft =  l->data[0];
if ((ft.isFunc==true)) {
if ((len(l)>1)) {
throwErr(&l->data[len(l)-1],"Not expecting {TOKEN} after function call.");
}

                    if (l->length <= 0) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2037): l[%d] with length %d\n", 0, l->length);
                        exit(1);
                    };
                    ft =  l->data[0];
char parsed =  true;
char * ____BAH_COMPILER_VAR_495 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ft.cont);
long int strLen_1 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_495 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_495+currStrOff, ft.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_495+currStrOff, ";\n", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_495[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_495));
return;
}
l =  parseStructType(l,(lineType)-1,elems);
char isEqual =  false;
char toVar =  false;
char isPointedVar =  false;
char isStruct =  false;
char * currentType =  "";

                    if (l->length <= 0) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2048): l[%d] with length %d\n", 0, l->length);
                        exit(1);
                    };
                    ft =  l->data[0];
struct variable* v =  searchVar(ft.cont,elems);
char exists =  true;
char * ogName= null;
if ((v==null)) {
exists =  false;
struct variable* ____BAH_COMPILER_VAR_496 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_496->name = "";
____BAH_COMPILER_VAR_496->type = "";
____BAH_COMPILER_VAR_496->isConst = false;
____BAH_COMPILER_VAR_496->constVal = "";
____BAH_COMPILER_VAR_496->isArray = false;
____BAH_COMPILER_VAR_496->from = "";
____BAH_COMPILER_VAR_496->outterScope = false;
____BAH_COMPILER_VAR_496->isGlobal = false;
v =  ____BAH_COMPILER_VAR_496;
v->name =  ft.cont;
v->type =  "";
}
else {
ogName =  v->name;
}
if ((v->isConst==true)) {
throwErr(&ft,"Cannot set the value of const {TOKEN}.");
}
char * code =  "";
if (((exists==true)&&isGlobal())) {
throwErr(&ft,"Cannot redeclare global variable {TOKEN}.");
}
if ((len(l)==2)) {

                    if (l->length <= 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2070): l[%d] with length %d\n", 1, l->length);
                        exit(1);
                    };
                    struct Tok lt =  l->data[1];
if ((((lt.type==TOKEN_TYPE_SYNTAX)&&(strcmp(lt.cont, "++") == 0))||(strcmp(lt.cont, "--") == 0))) {
if ((exists==false)) {
char * ____BAH_COMPILER_VAR_497 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot use '");
long int strLen_1 = strlen(lt.cont);
long int strLen_2 = strlen("' on non declared {TOKEN} variable.");
;                            
                    ____BAH_COMPILER_VAR_497 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_497+currStrOff, "Cannot use '", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_497+currStrOff, lt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_497+currStrOff, "' on non declared {TOKEN} variable.", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_497[currStrOff] = 0;
                }
                throwErr(&ft,____BAH_COMPILER_VAR_497);
}
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);

                    if (l->length <= 0) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2076): l[%d] with length %d\n", 0, l->length);
                        exit(1);
                    };
                    
{
long nLength = 0;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[0] =  l->data[0];
nl->length = nLength+1;
} else {
nl->data[0] =  l->data[0];
}
};
struct Tok ____BAH_COMPILER_VAR_498 = {};
____BAH_COMPILER_VAR_498.cont = "";
____BAH_COMPILER_VAR_498.ogCont = "";
____BAH_COMPILER_VAR_498.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_498.pos = 0;
____BAH_COMPILER_VAR_498.line = 1;
____BAH_COMPILER_VAR_498.begLine = 1;
____BAH_COMPILER_VAR_498.bahType = "";
____BAH_COMPILER_VAR_498.isValue = false;
____BAH_COMPILER_VAR_498.isFunc = false;
____BAH_COMPILER_VAR_498.isOper = false;
____BAH_COMPILER_VAR_498.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_498.cont = "=";
____BAH_COMPILER_VAR_498.isValue = false;

{
long nLength = 1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[1] =  ____BAH_COMPILER_VAR_498;
nl->length = nLength+1;
} else {
nl->data[1] =  ____BAH_COMPILER_VAR_498;
}
};
char * c =  "";
if ((strcmp(lt.cont, "++") == 0)) {
char * ____BAH_COMPILER_VAR_499 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ft.cont);
long int strLen_1 = strlen("+1");
;                            
                    ____BAH_COMPILER_VAR_499 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_499+currStrOff, ft.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_499+currStrOff, "+1", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_499[currStrOff] = 0;
                }
                c =  ____BAH_COMPILER_VAR_499;
}
else if ((strcmp(lt.cont, "--") == 0)) {
char * ____BAH_COMPILER_VAR_500 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ft.cont);
long int strLen_1 = strlen("-1");
;                            
                    ____BAH_COMPILER_VAR_500 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_500+currStrOff, ft.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_500+currStrOff, "-1", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_500[currStrOff] = 0;
                }
                c =  ____BAH_COMPILER_VAR_500;
}
long int ltl =  lt.line;
long int ltp =  lt.pos;
char * ltc =  lt.cont;
struct Tok ____BAH_COMPILER_VAR_501 = {};
____BAH_COMPILER_VAR_501.cont = "";
____BAH_COMPILER_VAR_501.ogCont = "";
____BAH_COMPILER_VAR_501.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_501.pos = 0;
____BAH_COMPILER_VAR_501.line = 1;
____BAH_COMPILER_VAR_501.begLine = 1;
____BAH_COMPILER_VAR_501.bahType = "";
____BAH_COMPILER_VAR_501.isValue = false;
____BAH_COMPILER_VAR_501.isFunc = false;
____BAH_COMPILER_VAR_501.isOper = false;
____BAH_COMPILER_VAR_501.type = TOKEN_TYPE_INT;
____BAH_COMPILER_VAR_501.cont = c;
____BAH_COMPILER_VAR_501.line = ltl;
____BAH_COMPILER_VAR_501.ogCont = ltc;
____BAH_COMPILER_VAR_501.pos = ltp;
____BAH_COMPILER_VAR_501.isOper = true;
____BAH_COMPILER_VAR_501.isValue = true;

{
long nLength = 2;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[2] =  ____BAH_COMPILER_VAR_501;
nl->length = nLength+1;
} else {
nl->data[2] =  ____BAH_COMPILER_VAR_501;
}
};
l =  nl;
}
}

                    if (l->length <= 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2108): l[%d] with length %d\n", 1, l->length);
                        exit(1);
                    };
                    struct Tok operT =  l->data[1];

                int ____BAH_COMPILER_VAR_502 = 0;
                for(int i=len(equalsTokens)-1; i != -1; i--) {
                    if (equalsTokens->data[i] != 0 && strcmp(equalsTokens->data[i], operT.cont) == 0) {
                        ____BAH_COMPILER_VAR_502 = 1;
                        break;
                    };
                };
                if ((____BAH_COMPILER_VAR_502&&(strcmp(operT.cont, "=") != 0))) {

                    if (l->length <= 0) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2110): l[%d] with length %d\n", 0, l->length);
                        exit(1);
                    };
                    array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 1;
nl->elemSize = sizeof(struct Tok);
nl->data = memoryAlloc(sizeof(struct Tok) * 50);nl->data[0] = l->data[0];
if ((2==len(l))) {
throwErr(&operT,"Cannot use {TOKEN} on nothing.");
}
struct string oper =  string(operT.cont);
oper.trimRight((struct string*)&oper,1);
struct Tok operTok =  operT;
operTok.cont =  oper.str((struct string*)&oper);

                    if (l->length <= 2) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2122): l[%d] with length %d\n", 2, l->length);
                        exit(1);
                    };
                    array(struct Tok)* tmpL = memoryAlloc(sizeof(array(struct Tok)));

tmpL->length = 3;
tmpL->elemSize = sizeof(struct Tok);
tmpL->data = memoryAlloc(sizeof(struct Tok) * 50);tmpL->data[0] = ft;
tmpL->data[1] = operTok;
tmpL->data[2] = l->data[2];
tmpL =  parseOperations(tmpL,LINE_TYPE_VAR,elems);
operT.cont =  "=";

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  operT;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  operT;
}
};
long int j =  0;
for (; (j<len(tmpL)); j =  j+1) {

                    if (tmpL->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2131): tmpL[%d] with length %d\n", j, tmpL->length);
                        exit(1);
                    };
                    
{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  tmpL->data[j];
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  tmpL->data[j];
}
};
};
l =  nl;
}
long int i =  1;
while ((i<len(l))) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2139): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    struct Tok t =  l->data[i];
if ((t.type==TOKEN_TYPE_SYNTAX)) {
if ((strcmp(t.cont, "=") == 0)) {
if ((strlen(currentType)>0)) {
struct string sct =  string(currentType);
sct.replace((struct string*)&sct," ","");
v->type =  sct.str((struct string*)&sct);
}
isEqual =  true;
i =  i + 1;
continue;
}
}
if ((isEqual==false)) {
char * ____BAH_COMPILER_VAR_503 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(currentType);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_503 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_503+currStrOff, currentType, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_503+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_503+currStrOff, t.cont, strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_503[currStrOff] = 0;
                }
                currentType =  ____BAH_COMPILER_VAR_503;
}
else {
if ((strcmp(t.cont, "chan") == 0)) {
if ((i>=len(l))) {
throwErr(&t,"Cannot declare a {TOKEN} without a type (chan <type>).");
}
i =  i+1;

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2160): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    struct Tok nt =  l->data[i];
char * ____BAH_COMPILER_VAR_504 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("chan:");
long int strLen_1 = strlen(nt.cont);
;                            
                    ____BAH_COMPILER_VAR_504 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_504+currStrOff, "chan:", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_504+currStrOff, nt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_504[currStrOff] = 0;
                }
                v->type =  ____BAH_COMPILER_VAR_504;
code =  "channel()";
if ((i + 1!=len(l))) {

                    if (l->length <= i + 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2164): l[%d] with length %d\n", i + 1, l->length);
                        exit(1);
                    };
                    struct Tok errT =  l->data[i + 1];
throwErr(&errT,"{TOKEN} not expected after channel declaration.");
}
break;
}
else if ((strcmp(t.cont, "map") == 0)) {
if ((i>=len(l))) {
throwErr(&t,"Cannot declare a {TOKEN} without a type (map <type>).");
}
i =  i+1;

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2174): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    struct Tok nt =  l->data[i];
char * ____BAH_COMPILER_VAR_505 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("map:");
long int strLen_1 = strlen(nt.cont);
;                            
                    ____BAH_COMPILER_VAR_505 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_505+currStrOff, "map:", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_505+currStrOff, nt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_505[currStrOff] = 0;
                }
                v->type =  ____BAH_COMPILER_VAR_505;
code =  "mapWrapper()";
if ((i + 1!=len(l))) {

                    if (l->length <= i + 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2178): l[%d] with length %d\n", i + 1, l->length);
                        exit(1);
                    };
                    struct Tok errT =  l->data[i + 1];
throwErr(&errT,"{TOKEN} not expected after map declaration.");
}
break;
}
else if ((strcmp(t.cont, "buffer") == 0)) {
if ((i>=len(l))) {
throwErr(&t,"Cannot declare a {TOKEN} without a length (buffer <length>).");
}
i =  i+1;

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2187): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    struct Tok nt =  l->data[i];
if ((nt.type!=TOKEN_TYPE_INT)) {
throwErr(&nt,"Expected buffer length, not {TOKEN}.");
}
char * ____BAH_COMPILER_VAR_506 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("buffer:");
long int strLen_1 = strlen(nt.cont);
;                            
                    ____BAH_COMPILER_VAR_506 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_506+currStrOff, "buffer:", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_506+currStrOff, nt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_506[currStrOff] = 0;
                }
                v->type =  ____BAH_COMPILER_VAR_506;
struct variable* ____BAH_COMPILER_VAR_507 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_507->name = "";
____BAH_COMPILER_VAR_507->type = "";
____BAH_COMPILER_VAR_507->isConst = false;
____BAH_COMPILER_VAR_507->constVal = "";
____BAH_COMPILER_VAR_507->isArray = false;
____BAH_COMPILER_VAR_507->from = "";
____BAH_COMPILER_VAR_507->outterScope = false;
____BAH_COMPILER_VAR_507->isGlobal = false;
struct variable* av =  ____BAH_COMPILER_VAR_507;
av->type =  "char*";
av->name =  genCompilerVar();

{
long nLength = len(elems->vars);
if (elems->vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(elems->vars->data, (nLength+50)*sizeof(struct variable*));
elems->vars->data = newPtr;
}
elems->vars->data[len(elems->vars)] =  av;
elems->vars->length = nLength+1;
} else {
elems->vars->data[len(elems->vars)] =  av;
}
};
struct string cType =  getCType(av->type,elems);
char * ____BAH_COMPILER_VAR_508 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("char ");
long int strLen_1 = strlen(av->name);
long int strLen_2 = strlen("[");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen("];");
;                            
                    ____BAH_COMPILER_VAR_508 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_508+currStrOff, "char ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_508+currStrOff, av->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_508+currStrOff, "[", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_508+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_508+currStrOff, "];", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_508[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_508));
code =  av->name;
if ((i + 1!=len(l))) {

                    if (l->length <= i + 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2200): l[%d] with length %d\n", i + 1, l->length);
                        exit(1);
                    };
                    struct Tok errT =  l->data[i + 1];
throwErr(&errT,"{TOKEN} not expected after buffer declaration.");
}
break;
}
if ((t.isValue==false)) {
throwErr(&t,"Cannot use {TOKEN} as value in var declaration.");
}
char * tp =  getTypeFromToken(&t,true,elems);
if ((exists==true)) {
if ((compTypes(tp,v->type)==false)) {
char * ____BAH_COMPILER_VAR_509 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(tp);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(v->type);
long int strLen_4 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_509 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_509+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_509+currStrOff, tp, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_509+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_509+currStrOff, v->type, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_509+currStrOff, ".", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_509[currStrOff] = 0;
                }
                throwErr(&t,____BAH_COMPILER_VAR_509);
}
}
else {
if ((strlen(currentType)==0)) {
if ((strlen(v->type)==0)) {
v->type =  tp;
}
else {
if ((compTypes(tp,v->type)==false)) {
char * ____BAH_COMPILER_VAR_510 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(tp);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(v->type);
long int strLen_4 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_510 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_510+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_510+currStrOff, tp, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_510+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_510+currStrOff, v->type, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_510+currStrOff, ".", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_510[currStrOff] = 0;
                }
                throwErr(&t,____BAH_COMPILER_VAR_510);
}
}
}
}
if (((strlen(t.cont)>0)&&(strHasPrefix(t.cont,"{")==false))) {
char * ____BAH_COMPILER_VAR_511 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_511 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_511+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_511+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_511+currStrOff, t.cont, strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_511[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_511;
if (((t.isOper==false)&&(RCPavailable()==true))) {
struct variable* iv =  searchVar(t.cont,elems);
if (((iv!=null)&&(iv->isConst==false))) {
toVar =  true;
isPointedVar =  strHasPrefix(t.cont,"&");
struct cStruct* s =  searchStruct(iv->type,elems);
if ((((s!=null)&&(strCount(iv->type,"*")==0))&&(s->isBinding==false))) {
if ((strCount(iv->name,"*")==0)) {
char * ____BAH_COMPILER_VAR_512 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen("; RCP_incrCounter(");
long int strLen_2 = strlen(iv->name);
long int strLen_3 = strlen(".__RCP_counter)");
;                            
                    ____BAH_COMPILER_VAR_512 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                    
                    memcpy(____BAH_COMPILER_VAR_512+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_512+currStrOff, "; RCP_incrCounter(", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_512+currStrOff, iv->name, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_512+currStrOff, ".__RCP_counter)", strLen_3);
                    currStrOff += strLen_3;
                    
                    ____BAH_COMPILER_VAR_512[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_512;
}
else {
struct string ivn =  string(iv->name);
ivn.replace((struct string*)&ivn,"*","");
char * ____BAH_COMPILER_VAR_513 =ivn.str((struct string*)&ivn);char * ____BAH_COMPILER_VAR_514 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen("; RCP_incr(");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_513);
long int strLen_3 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_514 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                    
                    memcpy(____BAH_COMPILER_VAR_514+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_514+currStrOff, "; RCP_incr(", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_514+currStrOff, ____BAH_COMPILER_VAR_513, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_514+currStrOff, ")", strLen_3);
                    currStrOff += strLen_3;
                    
                    ____BAH_COMPILER_VAR_514[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_514;
}
}
}
}
break;
}
if (strHasPrefix(v->type,"[]")) {
code =  parseArrayDecl(v,l,i,len(l),elems);
break;
}
isStruct =  true;
long int max =  i + 1;
if ((max!=len(l))) {
throwErr(&l->data[i + 1],"{TOKEN} not expected after struct initialization.");
}
char * ____BAH_COMPILER_VAR_515 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_515 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_515+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_515+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_515+currStrOff, t.cont, strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_515[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_515;
}
i =  i+1;
};
if ((exists==true)) {
if ((strlen(code)==0)) {
throwErr(&ft,"Cannot re-declare {TOKEN}.");
}
if ((strlen(currentType)>0)) {

                    if (l->length <= 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2270): l[%d] with length %d\n", 1, l->length);
                        exit(1);
                    };
                    struct Tok st =  l->data[1];
char * ____BAH_COMPILER_VAR_516 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot change the type of already declared var '");
long int strLen_1 = strlen(ft.cont);
long int strLen_2 = strlen("' to {TOKEN}.");
;                            
                    ____BAH_COMPILER_VAR_516 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_516+currStrOff, "Cannot change the type of already declared var '", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_516+currStrOff, ft.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_516+currStrOff, "' to {TOKEN}.", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_516[currStrOff] = 0;
                }
                throwErr(&st,____BAH_COMPILER_VAR_516);
}
if ((isStruct==false)) {
if (((isRCPpointerType(v->type)&&(isPointedVar==false))&&(RCPavailable()==true))) {
struct string cType =  getCType(v->type,elems);
if ((toVar==true)) {
if ((RCPselfRef(v)==false)) {
char * ____BAH_COMPILER_VAR_517 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_518 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_519 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("*(");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_517);
long int strLen_2 = strlen("*)RCP_decrIL(&");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen(") = *(");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_518);
long int strLen_6 = strlen("*)RCP_incrIL(&");
long int strLen_7 = strlen(code);
long int strLen_8 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_519 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                    
                    memcpy(____BAH_COMPILER_VAR_519+currStrOff, "*(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_519+currStrOff, ____BAH_COMPILER_VAR_517, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_519+currStrOff, "*)RCP_decrIL(&", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_519+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_519+currStrOff, ") = *(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_519+currStrOff, ____BAH_COMPILER_VAR_518, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_519+currStrOff, "*)RCP_incrIL(&", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_519+currStrOff, code, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_519+currStrOff, ")", strLen_8);
                    currStrOff += strLen_8;
                    
                    ____BAH_COMPILER_VAR_519[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_519;
}
else {
struct variable* ____BAH_COMPILER_VAR_520 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_520->name = "";
____BAH_COMPILER_VAR_520->type = "";
____BAH_COMPILER_VAR_520->isConst = false;
____BAH_COMPILER_VAR_520->constVal = "";
____BAH_COMPILER_VAR_520->isArray = false;
____BAH_COMPILER_VAR_520->from = "";
____BAH_COMPILER_VAR_520->outterScope = false;
____BAH_COMPILER_VAR_520->isGlobal = false;
struct variable* tmpV =  ____BAH_COMPILER_VAR_520;
tmpV->name =  genCompilerVar();
tmpV->type =  v->type;
struct rope* dv =  decrVar(tmpV,elems);
char * ____BAH_COMPILER_VAR_521 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_522 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_523 =dv->toStr((struct rope*)dv);char * ____BAH_COMPILER_VAR_524 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_521);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(tmpV->name);
long int strLen_3 = strlen(" = ");
long int strLen_4 = strlen(v->name);
long int strLen_5 = strlen("; ");
long int strLen_6 = strlen(v->name);
long int strLen_7 = strlen(" = *(");
long int strLen_8 = strlen(____BAH_COMPILER_VAR_522);
long int strLen_9 = strlen("*)RCP_incrIL(&");
long int strLen_10 = strlen(code);
long int strLen_11 = strlen(");");
long int strLen_12 = strlen(____BAH_COMPILER_VAR_523);
;                            
                    ____BAH_COMPILER_VAR_524 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12);
                    
                    memcpy(____BAH_COMPILER_VAR_524+currStrOff, ____BAH_COMPILER_VAR_521, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_524+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_524+currStrOff, tmpV->name, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_524+currStrOff, " = ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_524+currStrOff, v->name, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_524+currStrOff, "; ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_524+currStrOff, v->name, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_524+currStrOff, " = *(", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_524+currStrOff, ____BAH_COMPILER_VAR_522, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_524+currStrOff, "*)RCP_incrIL(&", strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_524+currStrOff, code, strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_524+currStrOff, ");", strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_524+currStrOff, ____BAH_COMPILER_VAR_523, strLen_12);
                    currStrOff += strLen_12;
                    
                    ____BAH_COMPILER_VAR_524[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_524;
}
}
else {
struct variable* ____BAH_COMPILER_VAR_525 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_525->name = "";
____BAH_COMPILER_VAR_525->type = "";
____BAH_COMPILER_VAR_525->isConst = false;
____BAH_COMPILER_VAR_525->constVal = "";
____BAH_COMPILER_VAR_525->isArray = false;
____BAH_COMPILER_VAR_525->from = "";
____BAH_COMPILER_VAR_525->outterScope = false;
____BAH_COMPILER_VAR_525->isGlobal = false;
struct variable* tmpV =  ____BAH_COMPILER_VAR_525;
tmpV->name =  genCompilerVar();
tmpV->type =  v->type;
struct rope* dv =  decrVar(tmpV,elems);
char * ____BAH_COMPILER_VAR_526 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_527 =dv->toStr((struct rope*)dv);char * ____BAH_COMPILER_VAR_528 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_526);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(tmpV->name);
long int strLen_3 = strlen(" = ");
long int strLen_4 = strlen(v->name);
long int strLen_5 = strlen("; ");
long int strLen_6 = strlen(v->name);
long int strLen_7 = strlen(" = ");
long int strLen_8 = strlen(code);
long int strLen_9 = strlen(";");
long int strLen_10 = strlen(____BAH_COMPILER_VAR_527);
;                            
                    ____BAH_COMPILER_VAR_528 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10);
                    
                    memcpy(____BAH_COMPILER_VAR_528+currStrOff, ____BAH_COMPILER_VAR_526, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_528+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_528+currStrOff, tmpV->name, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_528+currStrOff, " = ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_528+currStrOff, v->name, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_528+currStrOff, "; ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_528+currStrOff, v->name, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_528+currStrOff, " = ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_528+currStrOff, code, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_528+currStrOff, ";", strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_528+currStrOff, ____BAH_COMPILER_VAR_527, strLen_10);
                    currStrOff += strLen_10;
                    
                    ____BAH_COMPILER_VAR_528[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_528;
}
}
else {
struct cStruct* s =  searchStruct(v->type,elems);
if ((((((s!=null)&&(RCPavailable()==true))&&(RCPselfRef(v)==false))&&(s->isBinding==false))&&(strCount(v->name,"*")==0))) {
char * ____BAH_COMPILER_VAR_529 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("RCP_decrCounter(");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(".__RCP_counter); ");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen(" = ");
long int strLen_5 = strlen(code);
;                            
                    ____BAH_COMPILER_VAR_529 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    memcpy(____BAH_COMPILER_VAR_529+currStrOff, "RCP_decrCounter(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_529+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_529+currStrOff, ".__RCP_counter); ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_529+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_529+currStrOff, " = ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_529+currStrOff, code, strLen_5);
                    currStrOff += strLen_5;
                    
                    ____BAH_COMPILER_VAR_529[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_529;
}
else {
char * ____BAH_COMPILER_VAR_530 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen(" = ");
long int strLen_2 = strlen(code);
;                            
                    ____BAH_COMPILER_VAR_530 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_530+currStrOff, v->name, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_530+currStrOff, " = ", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_530+currStrOff, code, strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_530[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_530;
}
}
}
else {
strTrim(&code);
if ((strHasPrefix(code,"{")==false)) {
char * ____BAH_COMPILER_VAR_531 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen(" = ");
long int strLen_2 = strlen(code);
;                            
                    ____BAH_COMPILER_VAR_531 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_531+currStrOff, v->name, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_531+currStrOff, " = ", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_531+currStrOff, code, strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_531[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_531;
}
}
if ((v->isArray==true)) {
struct string nLength =  string(v->name);
struct string n =  string(v->name);
i =  0;
while ((i<nLength.length)) {
char c =  nLength.charAt((struct string*)&nLength,i);
if ((c==91)) {
break;
}
i =  i+1;
};
nLength.trimLeft((struct string*)&nLength,i + 1);
nLength.trimRight((struct string*)&nLength,1);
char * nLengthStr =  nLength.str((struct string*)&nLength);
i =  n.length;
while ((i>0)) {
char c =  n.charAt((struct string*)&n,i);
if ((c==91)) {
break;
}
i =  i-1;
};
long int tamm =  n.length - i;
n.trimRight((struct string*)&n,tamm + 6);
char * nstr =  n.str((struct string*)&n);
struct string elemType =  getCType(v->type,elems);
char * elemTypeStr =  elemType.str((struct string*)&elemType);
char * ____BAH_COMPILER_VAR_532 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n{\nlong nLength = ");
long int strLen_1 = strlen(nLengthStr);
long int strLen_2 = strlen(";\nif (");
long int strLen_3 = strlen(nstr);
long int strLen_4 = strlen("->length < nLength+1) {\nif ((nLength+1) % 50 == 0 || nLength == 0) {\nvoid * newPtr = memoryRealloc(");
long int strLen_5 = strlen(nstr);
long int strLen_6 = strlen("->data, (nLength+50)*sizeof(");
long int strLen_7 = strlen(elemTypeStr);
long int strLen_8 = strlen("));\n");
long int strLen_9 = strlen(nstr);
long int strLen_10 = strlen("->data = newPtr;\n}\n");
long int strLen_11 = strlen(code);
long int strLen_12 = strlen(";\n");
long int strLen_13 = strlen(nstr);
long int strLen_14 = strlen("->length = nLength+1;\n} else {\n");
long int strLen_15 = strlen(code);
long int strLen_16 = strlen(";\n}\n}");
;                            
                    ____BAH_COMPILER_VAR_532 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14 + strLen_15 + strLen_16);
                    
                    memcpy(____BAH_COMPILER_VAR_532+currStrOff, "\n{\nlong nLength = ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_532+currStrOff, nLengthStr, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_532+currStrOff, ";\nif (", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_532+currStrOff, nstr, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_532+currStrOff, "->length < nLength+1) {\nif ((nLength+1) % 50 == 0 || nLength == 0) {\nvoid * newPtr = memoryRealloc(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_532+currStrOff, nstr, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_532+currStrOff, "->data, (nLength+50)*sizeof(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_532+currStrOff, elemTypeStr, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_532+currStrOff, "));\n", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_532+currStrOff, nstr, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_532+currStrOff, "->data = newPtr;\n}\n", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_532+currStrOff, code, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_532+currStrOff, ";\n", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_532+currStrOff, nstr, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_532+currStrOff, "->length = nLength+1;\n} else {\n", strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_532+currStrOff, code, strLen_15);
                    currStrOff += strLen_15;
                    
                    memcpy(____BAH_COMPILER_VAR_532+currStrOff, ";\n}\n}", strLen_16);
                    currStrOff += strLen_16;
                    
                    ____BAH_COMPILER_VAR_532[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_532;
}
}
else {
if ((strlen(currentType)>0)) {
v->type =  currentType;
}
struct string vts =  string(v->type);
vts.replace((struct string*)&vts," ","");
v->type =  vts.content;
if ((strlen(v->type)==0)) {
throwErr(&ft,"Cannot declare {TOKEN} without a type.");
}
char * vct= null;
if (vts.hasPrefix((struct string*)&vts,"function(")) {
struct func* tmpfn =  parseFnType(vts);
struct string tmpfnRetCType =  getCType(tmpfn->returns->type,elems);
char * tmpfnArgsCType =  "";
long int j =  0;
while ((j<len(tmpfn->args))) {

                    if (tmpfn->args->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2370): tmpfn->args[%d] with length %d\n", j, tmpfn->args->length);
                        exit(1);
                    };
                    struct variable* arg =  tmpfn->args->data[j];
struct string ct =  getCType(arg->type,elems);
char * ____BAH_COMPILER_VAR_533 =ct.str((struct string*)&ct);char * ____BAH_COMPILER_VAR_534 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_533);
;                            
                    ____BAH_COMPILER_VAR_534 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_534+currStrOff, tmpfnArgsCType, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_534+currStrOff, ____BAH_COMPILER_VAR_533, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_534[currStrOff] = 0;
                }
                tmpfnArgsCType =  ____BAH_COMPILER_VAR_534;
j =  j + 1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_535 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(",");
;                            
                    ____BAH_COMPILER_VAR_535 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_535+currStrOff, tmpfnArgsCType, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_535+currStrOff, ",", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_535[currStrOff] = 0;
                }
                tmpfnArgsCType =  ____BAH_COMPILER_VAR_535;
}
};
char * ____BAH_COMPILER_VAR_536 =tmpfnRetCType.str((struct string*)&tmpfnRetCType);char * ____BAH_COMPILER_VAR_537 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_536);
long int strLen_1 = strlen(" (*");
long int strLen_2 = strlen(v->name);
long int strLen_3 = strlen(")(");
long int strLen_4 = strlen(tmpfnArgsCType);
long int strLen_5 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_537 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    memcpy(____BAH_COMPILER_VAR_537+currStrOff, ____BAH_COMPILER_VAR_536, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_537+currStrOff, " (*", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_537+currStrOff, v->name, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_537+currStrOff, ")(", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_537+currStrOff, tmpfnArgsCType, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_537+currStrOff, ")", strLen_5);
                    currStrOff += strLen_5;
                    
                    ____BAH_COMPILER_VAR_537[currStrOff] = 0;
                }
                vct =  ____BAH_COMPILER_VAR_537;
}
else {
vct =  setCType(v,elems);
}
if (((strlen(code)>0)&&(shouldOnlyDecl==false))) {
if ((((isRCPpointerType(v->type)&&(RCPavailable()==true))&&(toVar==true))&&(isPointedVar==false))) {
struct string cType =  getCType(v->type,elems);
if (isGlobal()) {
char * ____BAH_COMPILER_VAR_538 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_539 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen(" = *(");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_538);
long int strLen_3 = strlen("*)RCP_incrIL(&");
long int strLen_4 = strlen(code);
long int strLen_5 = strlen(");\n");
;                            
                    ____BAH_COMPILER_VAR_539 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    memcpy(____BAH_COMPILER_VAR_539+currStrOff, v->name, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_539+currStrOff, " = *(", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_539+currStrOff, ____BAH_COMPILER_VAR_538, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_539+currStrOff, "*)RCP_incrIL(&", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_539+currStrOff, code, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_539+currStrOff, ");\n", strLen_5);
                    currStrOff += strLen_5;
                    
                    ____BAH_COMPILER_VAR_539[currStrOff] = 0;
                }
                INIT =  INIT->add(INIT, rope(____BAH_COMPILER_VAR_539));
}
else {
char * ____BAH_COMPILER_VAR_540 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_541 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(vct);
long int strLen_1 = strlen(" = *(");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_540);
long int strLen_3 = strlen("*)RCP_incrIL(&");
long int strLen_4 = strlen(code);
long int strLen_5 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_541 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    memcpy(____BAH_COMPILER_VAR_541+currStrOff, vct, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_541+currStrOff, " = *(", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_541+currStrOff, ____BAH_COMPILER_VAR_540, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_541+currStrOff, "*)RCP_incrIL(&", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_541+currStrOff, code, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_541+currStrOff, ")", strLen_5);
                    currStrOff += strLen_5;
                    
                    ____BAH_COMPILER_VAR_541[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_541;
}
}
else {
if (isGlobal()) {
char * ____BAH_COMPILER_VAR_542 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen(" = ");
long int strLen_2 = strlen(code);
long int strLen_3 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_542 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                    
                    memcpy(____BAH_COMPILER_VAR_542+currStrOff, v->name, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_542+currStrOff, " = ", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_542+currStrOff, code, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_542+currStrOff, ";\n", strLen_3);
                    currStrOff += strLen_3;
                    
                    ____BAH_COMPILER_VAR_542[currStrOff] = 0;
                }
                INIT =  INIT->add(INIT, rope(____BAH_COMPILER_VAR_542));
}
else {
char * ____BAH_COMPILER_VAR_543 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(vct);
long int strLen_1 = strlen(" = ");
long int strLen_2 = strlen(code);
;                            
                    ____BAH_COMPILER_VAR_543 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_543+currStrOff, vct, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_543+currStrOff, " = ", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_543+currStrOff, code, strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_543[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_543;
}
}
}
else {
if ((isRCPpointerType(v->type)&&(shouldOnlyDecl==false))) {
char * ____BAH_COMPILER_VAR_544 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(vct);
long int strLen_1 = strlen("= null");
;                            
                    ____BAH_COMPILER_VAR_544 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_544+currStrOff, vct, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_544+currStrOff, "= null", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_544[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_544;
}
else {
code =  vct;
}
}
if ((shouldOnlyDecl==true)) {
char * ____BAH_COMPILER_VAR_545 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("extern ");
long int strLen_1 = strlen(vct);
;                            
                    ____BAH_COMPILER_VAR_545 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_545+currStrOff, "extern ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_545+currStrOff, vct, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_545[currStrOff] = 0;
                }
                vct =  ____BAH_COMPILER_VAR_545;
}
if (isGlobal()) {
v->isGlobal =  true;
}
else {
v->isGlobal =  false;
}

{
long nLength = len(elems->vars);
if (elems->vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(elems->vars->data, (nLength+50)*sizeof(struct variable*));
elems->vars->data = newPtr;
}
elems->vars->data[len(elems->vars)] =  v;
elems->vars->length = nLength+1;
} else {
elems->vars->data[len(elems->vars)] =  v;
}
};
struct variable* ____BAH_COMPILER_VAR_546 = v;
char ** ____BAH_COMPILER_VAR_548 = (char **)((char*)(____BAH_COMPILER_VAR_546) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_549 = __reflect(____BAH_COMPILER_VAR_548, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_550 = (char **)((char*)(____BAH_COMPILER_VAR_546) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_551 = __reflect(____BAH_COMPILER_VAR_550, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_552 = (char*)((char*)(____BAH_COMPILER_VAR_546) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_553 = __reflect(____BAH_COMPILER_VAR_552, sizeof(char), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_554 = (char **)((char*)(____BAH_COMPILER_VAR_546) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_555 = __reflect(____BAH_COMPILER_VAR_554, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_556 = (char*)((char*)(____BAH_COMPILER_VAR_546) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_557 = __reflect(____BAH_COMPILER_VAR_556, sizeof(char), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_558 = (char **)((char*)(____BAH_COMPILER_VAR_546) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_559 = __reflect(____BAH_COMPILER_VAR_558, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
char* ____BAH_COMPILER_VAR_560 = (char*)((char*)(____BAH_COMPILER_VAR_546) + offsetof(struct variable, outterScope));
struct reflectElement ____BAH_COMPILER_VAR_561 = __reflect(____BAH_COMPILER_VAR_560, sizeof(char), "bool", "outterScope", 0, 0, 0, 0, offsetof(struct variable, outterScope));
char* ____BAH_COMPILER_VAR_562 = (char*)((char*)(____BAH_COMPILER_VAR_546) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_563 = __reflect(____BAH_COMPILER_VAR_562, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_547 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_547->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_547->length = 8;
        ____BAH_COMPILER_VAR_547->data = memoryAlloc(____BAH_COMPILER_VAR_547->length * ____BAH_COMPILER_VAR_547->elemSize);
        ____BAH_COMPILER_VAR_547->data[0] = ____BAH_COMPILER_VAR_549;
____BAH_COMPILER_VAR_547->data[1] = ____BAH_COMPILER_VAR_551;
____BAH_COMPILER_VAR_547->data[2] = ____BAH_COMPILER_VAR_553;
____BAH_COMPILER_VAR_547->data[3] = ____BAH_COMPILER_VAR_555;
____BAH_COMPILER_VAR_547->data[4] = ____BAH_COMPILER_VAR_557;
____BAH_COMPILER_VAR_547->data[5] = ____BAH_COMPILER_VAR_559;
____BAH_COMPILER_VAR_547->data[6] = ____BAH_COMPILER_VAR_561;
____BAH_COMPILER_VAR_547->data[7] = ____BAH_COMPILER_VAR_563;
struct reflectElement ____BAH_COMPILER_VAR_564 = __reflect(____BAH_COMPILER_VAR_546, sizeof(struct variable), "variable*", "v", 0, 0, 1, ____BAH_COMPILER_VAR_547, 0);
debugPrint("var_declaration",ft.line,____BAH_COMPILER_VAR_564);
if (isGlobal()) {
char * ____BAH_COMPILER_VAR_565 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(vct);
long int strLen_1 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_565 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_565+currStrOff, vct, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_565+currStrOff, ";\n", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_565[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_565));
}
}
if (isGlobal()) {
if ((isSubObject==false)) {
INIT =  INIT->add(INIT, rope(NEXT_LINE));
}
NEXT_LINE =  "";
}
else {
char * ____BAH_COMPILER_VAR_566 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_566 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_566+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_566+currStrOff, ";\n", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_566[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_566));
}
};
char * getCfunctionType(struct string cfrt,char * elemName,struct Elems* elems){
struct func* tmpfn =  parseFnType(cfrt);
struct string tmpfnRetCType =  getCType(tmpfn->returns->type,elems);
char * tmpfnArgsCType =  "";
long int j =  0;
while ((j<len(tmpfn->args))) {

                    if (tmpfn->args->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2446): tmpfn->args[%d] with length %d\n", j, tmpfn->args->length);
                        exit(1);
                    };
                    struct variable* arg =  tmpfn->args->data[j];
struct string ct =  getCType(arg->type,elems);
char * ____BAH_COMPILER_VAR_567 =ct.str((struct string*)&ct);char * ____BAH_COMPILER_VAR_568 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_567);
;                            
                    ____BAH_COMPILER_VAR_568 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_568+currStrOff, tmpfnArgsCType, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_568+currStrOff, ____BAH_COMPILER_VAR_567, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_568[currStrOff] = 0;
                }
                tmpfnArgsCType =  ____BAH_COMPILER_VAR_568;
j =  j + 1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_569 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(",");
;                            
                    ____BAH_COMPILER_VAR_569 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_569+currStrOff, tmpfnArgsCType, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_569+currStrOff, ",", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_569[currStrOff] = 0;
                }
                tmpfnArgsCType =  ____BAH_COMPILER_VAR_569;
}
};
char * ____BAH_COMPILER_VAR_570 =tmpfnRetCType.str((struct string*)&tmpfnRetCType);char * ____BAH_COMPILER_VAR_571 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_570);
long int strLen_1 = strlen(" (*");
long int strLen_2 = strlen(elemName);
long int strLen_3 = strlen(")(");
long int strLen_4 = strlen(tmpfnArgsCType);
long int strLen_5 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_571 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    memcpy(____BAH_COMPILER_VAR_571+currStrOff, ____BAH_COMPILER_VAR_570, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_571+currStrOff, " (*", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_571+currStrOff, elemName, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_571+currStrOff, ")(", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_571+currStrOff, tmpfnArgsCType, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_571+currStrOff, ")", strLen_5);
                    currStrOff += strLen_5;
                    
                    ____BAH_COMPILER_VAR_571[currStrOff] = 0;
                }
                return ____BAH_COMPILER_VAR_571;
};
char * parseFnHeader(char * prev,__BAH_ARR_TYPE_Tok l,long int* i,struct func* fn,struct Elems* elems){
long int j =  *i;

                    if (l->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2462): l[%d] with length %d\n", j, l->length);
                        exit(1);
                    };
                    struct Tok ft =  l->data[j];
char * tpdf =  "";
if ((ft.type!=TOKEN_TYPE_VAR)) {
throwErr(&ft,"Cannot use {TOKEN} as function name.");
}
char * ____BAH_COMPILER_VAR_572 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(prev);
long int strLen_1 = strlen(ft.cont);
;                            
                    ____BAH_COMPILER_VAR_572 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_572+currStrOff, prev, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_572+currStrOff, ft.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_572[currStrOff] = 0;
                }
                fn->name =  ____BAH_COMPILER_VAR_572;
array(struct variable*)* arguments = memoryAlloc(sizeof(array(struct variable*)));

arguments->length = 0;
arguments->elemSize = sizeof(struct variable*);
char * ____BAH_COMPILER_VAR_573 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(fn->name);
long int strLen_1 = strlen("(");
;                            
                    ____BAH_COMPILER_VAR_573 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_573+currStrOff, fn->name, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_573+currStrOff, "(", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_573[currStrOff] = 0;
                }
                char * code =  ____BAH_COMPILER_VAR_573;
j =  j + 2;

                    if (l->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2476): l[%d] with length %d\n", j, l->length);
                        exit(1);
                    };
                    struct Tok t =  l->data[j];
if ((strcmp(t.cont, ")") != 0)) {
while ((j<len(l))) {

                    if (l->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2480): l[%d] with length %d\n", j, l->length);
                        exit(1);
                    };
                    t =  l->data[j];
if ((t.type!=TOKEN_TYPE_VAR)) {
throwErr(&t,"Cannot use {TOKEN} as argument name.");
}
char * argName =  t.cont;
j =  j + 1;
if ((j>=len(l))) {
throwErr(&t,"Cannot declare argument {TOKEN} without a type.");
}

                    if (l->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2490): l[%d] with length %d\n", j, l->length);
                        exit(1);
                    };
                    t =  l->data[j];
char * argType =  t.cont;
j =  j + 1;
char isComa =  false;
long int nbPars =  1;
while ((j<len(l))) {

                    if (l->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2497): l[%d] with length %d\n", j, l->length);
                        exit(1);
                    };
                    t =  l->data[j];
isComa =  false;
if ((strcmp(t.cont, ",") != 0)) {
if ((strcmp(t.cont, "(") == 0)) {
nbPars =  nbPars + 1;
}
else if ((strcmp(t.cont, ")") == 0)) {
nbPars =  nbPars - 1;
}
if (((strcmp(t.cont, ")") == 0)&&(nbPars==0))) {
break;
}
else {
char * ____BAH_COMPILER_VAR_574 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(argType);
long int strLen_1 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_574 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_574+currStrOff, argType, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_574+currStrOff, t.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_574[currStrOff] = 0;
                }
                argType =  ____BAH_COMPILER_VAR_574;
}
}
else {
isComa =  true;
break;
}
j =  j + 1;
};
struct variable* ____BAH_COMPILER_VAR_575 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_575->name = "";
____BAH_COMPILER_VAR_575->type = "";
____BAH_COMPILER_VAR_575->isConst = false;
____BAH_COMPILER_VAR_575->constVal = "";
____BAH_COMPILER_VAR_575->isArray = false;
____BAH_COMPILER_VAR_575->from = "";
____BAH_COMPILER_VAR_575->outterScope = false;
____BAH_COMPILER_VAR_575->isGlobal = false;
struct variable* argument =  ____BAH_COMPILER_VAR_575;
argument->name =  argName;
argument->type =  argType;

{
long nLength = len(arguments);
if (arguments->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(arguments->data, (nLength+50)*sizeof(struct variable*));
arguments->data = newPtr;
}
arguments->data[len(arguments)] =  argument;
arguments->length = nLength+1;
} else {
arguments->data[len(arguments)] =  argument;
}
};
struct string argCType =  getCType(argType,elems);
struct string cfrt =  string(argType);
char * newArgType =  argCType.str((struct string*)&argCType);
if ((cfrt.hasPrefix((struct string*)&cfrt,"[]")==1)) {
cfrt.trimLeft((struct string*)&cfrt,2);
if (cfrt.hasSuffix((struct string*)&cfrt,"*")) {
long int nbast =  cfrt.count((struct string*)&cfrt,"*");
cfrt.trimRight((struct string*)&cfrt,nbast);
}
char * ____BAH_COMPILER_VAR_576 =cfrt.str((struct string*)&cfrt);char * ____BAH_COMPILER_VAR_577 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("__BAH_ARR_TYPE_");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_576);
;                            
                    ____BAH_COMPILER_VAR_577 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_577+currStrOff, "__BAH_ARR_TYPE_", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_577+currStrOff, ____BAH_COMPILER_VAR_576, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_577[currStrOff] = 0;
                }
                newArgType =  ____BAH_COMPILER_VAR_577;
array(char *)* csatd =  compilerState.arrTypesDecl;
if ((inArrayStr(newArgType,csatd)==false)) {

{
long nLength = len(csatd);
if (csatd->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(csatd->data, (nLength+50)*sizeof(char *));
csatd->data = newPtr;
}
csatd->data[len(csatd)] =  newArgType;
csatd->length = nLength+1;
} else {
csatd->data[len(csatd)] =  newArgType;
}
};
char * ____BAH_COMPILER_VAR_578 =argCType.str((struct string*)&argCType);char * ____BAH_COMPILER_VAR_579 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tpdf);
long int strLen_1 = strlen("typedef ");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_578);
long int strLen_3 = strlen(" ");
long int strLen_4 = strlen(newArgType);
long int strLen_5 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_579 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    memcpy(____BAH_COMPILER_VAR_579+currStrOff, tpdf, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_579+currStrOff, "typedef ", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_579+currStrOff, ____BAH_COMPILER_VAR_578, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_579+currStrOff, " ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_579+currStrOff, newArgType, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_579+currStrOff, ";\n", strLen_5);
                    currStrOff += strLen_5;
                    
                    ____BAH_COMPILER_VAR_579[currStrOff] = 0;
                }
                tpdf =  ____BAH_COMPILER_VAR_579;
}
}
if ((cfrt.hasPrefix((struct string*)&cfrt,"function(")==1)) {
char * ____BAH_COMPILER_VAR_580 =getCfunctionType(cfrt,argName,elems);char * ____BAH_COMPILER_VAR_581 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_580);
;                            
                    ____BAH_COMPILER_VAR_581 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_581+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_581+currStrOff, ____BAH_COMPILER_VAR_580, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_581[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_581;
}
else {
char * ____BAH_COMPILER_VAR_582 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(newArgType);
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(argName);
;                            
                    ____BAH_COMPILER_VAR_582 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                    
                    memcpy(____BAH_COMPILER_VAR_582+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_582+currStrOff, newArgType, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_582+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_582+currStrOff, argName, strLen_3);
                    currStrOff += strLen_3;
                    
                    ____BAH_COMPILER_VAR_582[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_582;
}
if ((isComa==true)) {
char * ____BAH_COMPILER_VAR_583 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(",");
;                            
                    ____BAH_COMPILER_VAR_583 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_583+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_583+currStrOff, ",", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_583[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_583;
}
else {
char * ____BAH_COMPILER_VAR_584 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_584 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_584+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_584+currStrOff, ")", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_584[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_584;
break;
}
j =  j + 1;
};
}
else {
char * ____BAH_COMPILER_VAR_585 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_585 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_585+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_585+currStrOff, ")", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_585[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_585;
}
j =  j + 1;
struct variable* ____BAH_COMPILER_VAR_586 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_586->name = "";
____BAH_COMPILER_VAR_586->type = "";
____BAH_COMPILER_VAR_586->isConst = false;
____BAH_COMPILER_VAR_586->constVal = "";
____BAH_COMPILER_VAR_586->isArray = false;
____BAH_COMPILER_VAR_586->from = "";
____BAH_COMPILER_VAR_586->outterScope = false;
____BAH_COMPILER_VAR_586->isGlobal = false;
struct variable* returns =  ____BAH_COMPILER_VAR_586;
returns->type =  "";
while ((j<len(l))) {

                    if (l->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2562): l[%d] with length %d\n", j, l->length);
                        exit(1);
                    };
                    t =  l->data[j];
if ((strcmp(t.cont, "{") == 0)) {
break;
}
char * ____BAH_COMPILER_VAR_587 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(returns->type);
long int strLen_1 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_587 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_587+currStrOff, returns->type, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_587+currStrOff, t.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_587[currStrOff] = 0;
                }
                returns->type =  ____BAH_COMPILER_VAR_587;
j =  j + 1;
};
if (strlen(returns->type)) {
struct string rts =  string(returns->type);
rts.replace((struct string*)&rts," ","");
returns->type =  rts.content;
}
*i =  j;
returns->name =  fn->name;
fn->returns =  returns;
fn->args =  arguments;
struct string fnRetType =  getCType(returns->type,elems);
char * newFnRetType =  fnRetType.str((struct string*)&fnRetType);
struct string cfrt =  string(returns->type);
if ((cfrt.hasPrefix((struct string*)&cfrt,"[]")==1)) {
cfrt.trimLeft((struct string*)&cfrt,2);
if (cfrt.hasSuffix((struct string*)&cfrt,"*")) {
long int nbast =  cfrt.count((struct string*)&cfrt,"*");
cfrt.trimRight((struct string*)&cfrt,nbast);
}
char * ____BAH_COMPILER_VAR_588 =cfrt.str((struct string*)&cfrt);char * ____BAH_COMPILER_VAR_589 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("__BAH_ARR_TYPE_");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_588);
;                            
                    ____BAH_COMPILER_VAR_589 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_589+currStrOff, "__BAH_ARR_TYPE_", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_589+currStrOff, ____BAH_COMPILER_VAR_588, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_589[currStrOff] = 0;
                }
                newFnRetType =  ____BAH_COMPILER_VAR_589;
array(char *)* csatd =  compilerState.arrTypesDecl;
if ((inArrayStr(newFnRetType,csatd)==false)) {

{
long nLength = len(csatd);
if (csatd->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(csatd->data, (nLength+50)*sizeof(char *));
csatd->data = newPtr;
}
csatd->data[len(csatd)] =  newFnRetType;
csatd->length = nLength+1;
} else {
csatd->data[len(csatd)] =  newFnRetType;
}
};
char * ____BAH_COMPILER_VAR_590 =fnRetType.str((struct string*)&fnRetType);char * ____BAH_COMPILER_VAR_591 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tpdf);
long int strLen_1 = strlen("typedef ");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_590);
long int strLen_3 = strlen(" ");
long int strLen_4 = strlen(newFnRetType);
long int strLen_5 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_591 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    memcpy(____BAH_COMPILER_VAR_591+currStrOff, tpdf, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_591+currStrOff, "typedef ", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_591+currStrOff, ____BAH_COMPILER_VAR_590, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_591+currStrOff, " ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_591+currStrOff, newFnRetType, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_591+currStrOff, ";\n", strLen_5);
                    currStrOff += strLen_5;
                    
                    ____BAH_COMPILER_VAR_591[currStrOff] = 0;
                }
                tpdf =  ____BAH_COMPILER_VAR_591;
}
}
char * ____BAH_COMPILER_VAR_592 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tpdf);
long int strLen_1 = strlen(newFnRetType);
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(code);
;                            
                    ____BAH_COMPILER_VAR_592 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                    
                    memcpy(____BAH_COMPILER_VAR_592+currStrOff, tpdf, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_592+currStrOff, newFnRetType, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_592+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_592+currStrOff, code, strLen_3);
                    currStrOff += strLen_3;
                    
                    ____BAH_COMPILER_VAR_592[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_592;
return code;
};
void parseStruct(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
struct cStruct* ____BAH_COMPILER_VAR_593 = memoryAlloc(sizeof(struct cStruct));
____BAH_COMPILER_VAR_593->name = "";
____BAH_COMPILER_VAR_593->members = memoryAlloc(sizeof(array(struct structMemb*)));
            ____BAH_COMPILER_VAR_593->members->length = 0;
            ____BAH_COMPILER_VAR_593->members->elemSize = sizeof(struct structMemb*);
            ____BAH_COMPILER_VAR_593->methods = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_593->methods->length = 0;
            ____BAH_COMPILER_VAR_593->methods->elemSize = sizeof(struct func*);
            ____BAH_COMPILER_VAR_593->postCode = "";
____BAH_COMPILER_VAR_593->extendedFrom = "";
____BAH_COMPILER_VAR_593->isBinding = false;
____BAH_COMPILER_VAR_593->hasRCPmemb = false;
struct cStruct* s =  ____BAH_COMPILER_VAR_593;
array(struct cStruct*)* structs =  elems->structs;

{
long nLength = len(structs);
if (structs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(structs->data, (nLength+50)*sizeof(struct cStruct*));
structs->data = newPtr;
}
structs->data[len(structs)] =  s;
structs->length = nLength+1;
} else {
structs->data[len(structs)] =  s;
}
};
array(struct func*)* methds =  s->methods;
if ((len(l)<4)) {
throwErr(&l->data[len(l)-1],"Cannot declare struct has such, please do 'struct <name> { <memberName>:<memberType> }'.");
}

                    if (l->length <= 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2612): l[%d] with length %d\n", 1, l->length);
                        exit(1);
                    };
                    struct Tok nameToken =  l->data[1];
long int i =  2;
char doesOutput =  true;
if ((strcmp(nameToken.cont, "!") == 0)) {

                    if (l->length <= 2) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2616): l[%d] with length %d\n", 2, l->length);
                        exit(1);
                    };
                    nameToken =  l->data[2];
i =  3;
doesOutput =  false;
s->isBinding =  true;
}
if ((nameToken.type!=TOKEN_TYPE_VAR)) {
throwErr(&nameToken,"Cannot use {TOKEN} as struct name.");
}
struct cStruct* os =  searchStruct(nameToken.cont,elems);
if ((os!=null)) {
throwErr(&nameToken,"Struct {TOKEN} already exists.");
}
s->name =  nameToken.cont;
array(struct structMemb*)* members =  s->members;
currentCStruct =  s;
array(char *)* allMembs = memoryAlloc(sizeof(array(char *)));

allMembs->length = 0;
allMembs->elemSize = sizeof(char *);

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2632): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    struct Tok st =  l->data[i];
if ((st.type==TOKEN_TYPE_KEYWORD)) {
if ((strcmp(st.cont, "extend") == 0)) {
i =  i+1;

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2636): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    struct Tok extdSNameTk =  l->data[i];
i =  i+1;
if ((extdSNameTk.type!=TOKEN_TYPE_VAR)) {
throwErr(&extdSNameTk,"Cannot use {TOKEN} as struct name.");
}
struct cStruct* extdS =  searchStruct(extdSNameTk.cont,elems);
s->extendedFrom =  extdS->name;
if ((extdS==null)) {
throwErr(&extdSNameTk,"Struct {TOKEN} does not exist.");
}
array(struct structMemb*)* extdsmbs =  extdS->members;
long int j =  0;
while ((j<len(extdsmbs))) {

                    if (extdsmbs->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2648): extdsmbs[%d] with length %d\n", j, extdsmbs->length);
                        exit(1);
                    };
                    struct structMemb* em =  extdsmbs->data[j];
struct string cemt =  string(em->type);
char * membDeclStr= null;
if ((cemt.hasPrefix((struct string*)&cemt,"function(")==1)) {
struct func* tmpfn =  parseFnType(cemt);
struct string tmpfnRetCType =  getCType(tmpfn->returns->type,elems);
char * tmpfnArgsCType =  "";
j =  0;
while ((j<len(tmpfn->args))) {

                    if (tmpfn->args->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2656): tmpfn->args[%d] with length %d\n", j, tmpfn->args->length);
                        exit(1);
                    };
                    struct variable* arg =  tmpfn->args->data[j];
struct string ct =  getCType(arg->type,elems);
char * ____BAH_COMPILER_VAR_594 =ct.str((struct string*)&ct);char * ____BAH_COMPILER_VAR_595 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_594);
;                            
                    ____BAH_COMPILER_VAR_595 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_595+currStrOff, tmpfnArgsCType, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_595+currStrOff, ____BAH_COMPILER_VAR_594, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_595[currStrOff] = 0;
                }
                tmpfnArgsCType =  ____BAH_COMPILER_VAR_595;
j =  j + 1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_596 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(",");
;                            
                    ____BAH_COMPILER_VAR_596 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_596+currStrOff, tmpfnArgsCType, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_596+currStrOff, ",", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_596[currStrOff] = 0;
                }
                tmpfnArgsCType =  ____BAH_COMPILER_VAR_596;
}
};
char * ____BAH_COMPILER_VAR_597 =tmpfnRetCType.str((struct string*)&tmpfnRetCType);char * ____BAH_COMPILER_VAR_598 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_597);
long int strLen_1 = strlen(" (*");
long int strLen_2 = strlen(em->name);
long int strLen_3 = strlen(")(");
long int strLen_4 = strlen(tmpfnArgsCType);
long int strLen_5 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_598 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    memcpy(____BAH_COMPILER_VAR_598+currStrOff, ____BAH_COMPILER_VAR_597, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_598+currStrOff, " (*", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_598+currStrOff, em->name, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_598+currStrOff, ")(", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_598+currStrOff, tmpfnArgsCType, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_598+currStrOff, ")", strLen_5);
                    currStrOff += strLen_5;
                    
                    ____BAH_COMPILER_VAR_598[currStrOff] = 0;
                }
                membDeclStr =  ____BAH_COMPILER_VAR_598;
}
else {
if (isRCPpointerType(em->type)) {
s->hasRCPmemb =  true;
}
struct string membDecl =  getCType(em->type,elems);
membDecl.append((struct string*)&membDecl," ");
membDecl.append((struct string*)&membDecl,em->name);
membDeclStr =  membDecl.content;
}

{
long nLength = len(allMembs);
if (allMembs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(allMembs->data, (nLength+50)*sizeof(char *));
allMembs->data = newPtr;
}
allMembs->data[len(allMembs)] =  membDeclStr;
allMembs->length = nLength+1;
} else {
allMembs->data[len(allMembs)] =  membDeclStr;
}
};

{
long nLength = len(members);
if (members->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(members->data, (nLength+50)*sizeof(struct structMemb*));
members->data = newPtr;
}
members->data[len(members)] =  em;
members->length = nLength+1;
} else {
members->data[len(members)] =  em;
}
};
j =  j + 1;
};
long int k =  0;
while ((k<len(extdS->methods))) {

                    if (extdS->methods->length <= k) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2680): extdS->methods[%d] with length %d\n", k, extdS->methods->length);
                        exit(1);
                    };
                    struct func* emt =  extdS->methods->data[k];
struct string mthdDecl =  getCType(emt->returns->type,elems);
char * ____BAH_COMPILER_VAR_599 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("(*");
long int strLen_1 = strlen(emt->name);
long int strLen_2 = strlen(")(");
;                            
                    ____BAH_COMPILER_VAR_599 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_599+currStrOff, "(*", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_599+currStrOff, emt->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_599+currStrOff, ")(", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_599[currStrOff] = 0;
                }
                mthdDecl.append((struct string*)&mthdDecl,____BAH_COMPILER_VAR_599);
j =  0;
while ((j<len(emt->args))) {

                    if (emt->args->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2685): emt->args[%d] with length %d\n", j, emt->args->length);
                        exit(1);
                    };
                    struct variable* a =  emt->args->data[j];
struct string tp =  getCType(a->type,elems);
char * ____BAH_COMPILER_VAR_600 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(" ");
long int strLen_1 = strlen(a->name);
;                            
                    ____BAH_COMPILER_VAR_600 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_600+currStrOff, " ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_600+currStrOff, a->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_600[currStrOff] = 0;
                }
                tp.append((struct string*)&tp,____BAH_COMPILER_VAR_600);
long int max =  len(emt->args) - 1;
if ((j!=max)) {
tp.append((struct string*)&tp,",");
}
char * ____BAH_COMPILER_VAR_601 =tp.str((struct string*)&tp);mthdDecl.append((struct string*)&mthdDecl,____BAH_COMPILER_VAR_601);
j =  j + 1;
};
mthdDecl.append((struct string*)&mthdDecl,")");

{
long nLength = len(allMembs);
if (allMembs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(allMembs->data, (nLength+50)*sizeof(char *));
allMembs->data = newPtr;
}
allMembs->data[len(allMembs)] =  mthdDecl.str((struct string*)&mthdDecl);
allMembs->length = nLength+1;
} else {
allMembs->data[len(allMembs)] =  mthdDecl.str((struct string*)&mthdDecl);
}
};
k =  k + 1;
};
}
else {
throwErr(&st,"Cannot use keyword {TOKEN} in struct declaration.");
}
}

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2704): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    struct Tok braceTk =  l->data[i];
i =  i+1;
if ((strcmp(braceTk.cont, "{") != 0)) {
throwErr(&braceTk,"Cannot use {TOKEN} in struct declaration.");
}
struct rope* OOUT =  OUTPUT;
char * nextLine =  "";
while ((i<len(l))) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2712): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    struct Tok t =  l->data[i];
long int max =  i + 2;
if ((max>=len(l))) {
if (((t.type==TOKEN_TYPE_ENCL)&&(strcmp(t.cont, "}") == 0))) {
break;
}
throwErr(&l->data[len(l)-1],"Not enough argument in member declaration, ending by {TOKEN}.");
}
struct structMemb* ____BAH_COMPILER_VAR_602 = memoryAlloc(sizeof(struct structMemb));
____BAH_COMPILER_VAR_602->name = "";
____BAH_COMPILER_VAR_602->type = "";
____BAH_COMPILER_VAR_602->isConst = false;
____BAH_COMPILER_VAR_602->constVal = "";
____BAH_COMPILER_VAR_602->isArray = false;
____BAH_COMPILER_VAR_602->from = "";
____BAH_COMPILER_VAR_602->outterScope = false;
____BAH_COMPILER_VAR_602->isGlobal = false;
____BAH_COMPILER_VAR_602->def = "";
____BAH_COMPILER_VAR_602->isFn = false;
struct structMemb* memb =  ____BAH_COMPILER_VAR_602;
if ((t.type!=TOKEN_TYPE_VAR)) {
throwErr(&t,"Cannot use {TOKEN} as member name.");
}
memb->name =  t.cont;
long int ii =  0;
while ((ii<len(members))) {

                    if (members->length <= ii) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2726): members[%d] with length %d\n", ii, members->length);
                        exit(1);
                    };
                    struct structMemb* m =  members->data[ii];
if ((strcmp(m->name, memb->name) == 0)) {
throwErr(&t,"Member {TOKEN} has already been declared.");
}
ii =  ii + 1;
};
i =  i+1;

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2733): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    t =  l->data[i];
if ((strcmp(t.cont, ":") != 0)) {
if ((strcmp(t.cont, "(") != 0)) {
throwErr(&t,"Member name should be followed by ':' not {TOKEN}.");
}
else {
char * ____BAH_COMPILER_VAR_603 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s->name);
long int strLen_1 = strlen("__");
;                            
                    ____BAH_COMPILER_VAR_603 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_603+currStrOff, s->name, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_603+currStrOff, "__", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_603[currStrOff] = 0;
                }
                char * fnPrefix =  ____BAH_COMPILER_VAR_603;
struct func* ____BAH_COMPILER_VAR_604 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_604->name = "";
____BAH_COMPILER_VAR_604->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_604->args->length = 0;
            ____BAH_COMPILER_VAR_604->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_604->returns= null;
____BAH_COMPILER_VAR_604->isBinding = false;
____BAH_COMPILER_VAR_604->from = "";
____BAH_COMPILER_VAR_604->file = "";
____BAH_COMPILER_VAR_604->line = 1;
____BAH_COMPILER_VAR_604->used = false;
____BAH_COMPILER_VAR_604->code = null;
struct func* fn =  ____BAH_COMPILER_VAR_604;
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
long int j =  i-1;
while ((j<len(l))) {

                    if (l->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2742): l[%d] with length %d\n", j, l->length);
                        exit(1);
                    };
                    t =  l->data[j];
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
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
}
};
if ((j==i)) {
t.type =  TOKEN_TYPE_VAR;
t.cont =  "this";
t.isValue =  true;

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
}
};
t.type =  TOKEN_TYPE_VAR;
char * ____BAH_COMPILER_VAR_605 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s->name);
long int strLen_1 = strlen("*");
;                            
                    ____BAH_COMPILER_VAR_605 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_605+currStrOff, s->name, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_605+currStrOff, "*", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_605[currStrOff] = 0;
                }
                t.cont =  ____BAH_COMPILER_VAR_605;
t.isValue =  true;

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
}
};

                    if (l->length <= j + 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2758): l[%d] with length %d\n", j + 1, l->length);
                        exit(1);
                    };
                    struct Tok nt =  l->data[j + 1];
if ((strcmp(nt.cont, ")") != 0)) {
t.type =  TOKEN_TYPE_SYNTAX;
t.cont =  ",";
t.isValue =  false;

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
}
};
}
}
j =  j + 1;
};
i =  i-1;
long int nli =  0;
char * ____BAH_COMPILER_VAR_606 =parseFnHeader(fnPrefix,nl,&nli,fn,elems);struct rope* code =  rope(____BAH_COMPILER_VAR_606);
i =  i + nli;
i =  i - 2;
struct variable* returns =  fn->returns;
array(struct variable*)* arguments =  fn->args;
fn->from =  s->name;
if ((shouldOnlyDecl==true)) {
code =  code->add(code, rope(";\n"));
}
else {
code =  code->add(code, rope("{\n"));
}
struct Elems* fnElems =  dupElems(elems);
j =  0;
while ((j<len(arguments))) {

                    if (arguments->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2787): arguments[%d] with length %d\n", j, arguments->length);
                        exit(1);
                    };
                    struct variable* a =  arguments->data[j];
a->outterScope =  true;

{
long nLength = len(fnElems->vars);
if (fnElems->vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(fnElems->vars->data, (nLength+50)*sizeof(struct variable*));
fnElems->vars->data = newPtr;
}
fnElems->vars->data[len(fnElems->vars)] =  a;
fnElems->vars->length = nLength+1;
} else {
fnElems->vars->data[len(fnElems->vars)] =  a;
}
};
j =  j + 1;
};
array(struct func*)* fns =  elems->fns;

{
long nLength = len(fns);
if (fns->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(fns->data, (nLength+50)*sizeof(struct func*));
fns->data = newPtr;
}
fns->data[len(fns)] =  fn;
fns->length = nLength+1;
} else {
fns->data[len(fns)] =  fn;
}
};
array(struct Tok)* tokens = memoryAlloc(sizeof(array(struct Tok)));

tokens->length = 0;
tokens->elemSize = sizeof(struct Tok);
long int nbBraces =  1;

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2798): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    t =  l->data[i];
if ((strcmp(t.cont, "{") == 0)) {
i =  i+1;
}
while ((i<len(l))) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2803): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    t =  l->data[i];
if ((strcmp(t.cont, "{") == 0)) {
nbBraces =  nbBraces + 1;
}
else if ((strcmp(t.cont, "}") == 0)) {
nbBraces =  nbBraces - 1;
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
tokens->data[len(tokens)] =  t;
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] =  t;
}
};
i =  i+1;
};
struct func* ____BAH_COMPILER_VAR_607 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_607->name = "";
____BAH_COMPILER_VAR_607->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_607->args->length = 0;
            ____BAH_COMPILER_VAR_607->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_607->returns= null;
____BAH_COMPILER_VAR_607->isBinding = false;
____BAH_COMPILER_VAR_607->from = "";
____BAH_COMPILER_VAR_607->file = "";
____BAH_COMPILER_VAR_607->line = 1;
____BAH_COMPILER_VAR_607->used = false;
____BAH_COMPILER_VAR_607->code = null;
struct func* mfn =  ____BAH_COMPILER_VAR_607;
mfn->args =  fn->args;
mfn->name =  fn->name;
mfn->returns =  fn->returns;
mfn->from =  s->name;
strTrimLeft(&mfn->name,strlen(fnPrefix));

{
long nLength = len(methds);
if (methds->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(methds->data, (nLength+50)*sizeof(struct func*));
methds->data = newPtr;
}
methds->data[len(methds)] =  mfn;
methds->length = nLength+1;
} else {
methds->data[len(methds)] =  mfn;
}
};
if ((shouldOnlyDecl==false)) {
if ((len(tokens)==0)) {
code =  code->add(code, rope("};\n"));
}
else {
OUTPUT =  rope("");
currentFn =  fn;
parseLines(tokens,fnElems);
currentFn =  null;
if ((fn->returned==false)) {
if ((strlen(fn->returns->type)>0)) {
char * ____BAH_COMPILER_VAR_608 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Function '");
long int strLen_1 = strlen(fn->name);
long int strLen_2 = strlen("' is not returned.");
;                            
                    ____BAH_COMPILER_VAR_608 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_608+currStrOff, "Function '", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_608+currStrOff, fn->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_608+currStrOff, "' is not returned.", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_608[currStrOff] = 0;
                }
                throwErr(&l->data[len(l)-1],____BAH_COMPILER_VAR_608);
}
endRCPscope(fnElems,null);
}
code =  code->add(code, OUTPUT)->add(code->add(code, OUTPUT), rope("};\n"));
}
}
if ((doesOutput==true)) {
char * ____BAH_COMPILER_VAR_609 =code->toStr((struct rope*)code);char * ____BAH_COMPILER_VAR_610 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(nextLine);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_609);
;                            
                    ____BAH_COMPILER_VAR_610 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_610+currStrOff, nextLine, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_610+currStrOff, ____BAH_COMPILER_VAR_609, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_610[currStrOff] = 0;
                }
                nextLine =  ____BAH_COMPILER_VAR_610;
}
struct string mthdDecl =  getCType(fn->returns->type,elems);
char * ____BAH_COMPILER_VAR_611 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("(*");
long int strLen_1 = strlen(mfn->name);
long int strLen_2 = strlen(")(");
;                            
                    ____BAH_COMPILER_VAR_611 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_611+currStrOff, "(*", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_611+currStrOff, mfn->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_611+currStrOff, ")(", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_611[currStrOff] = 0;
                }
                mthdDecl.append((struct string*)&mthdDecl,____BAH_COMPILER_VAR_611);
j =  0;
while ((j<len(arguments))) {

                    if (arguments->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2853): arguments[%d] with length %d\n", j, arguments->length);
                        exit(1);
                    };
                    struct variable* a =  arguments->data[j];
struct string tp =  getCType(a->type,elems);
char * ____BAH_COMPILER_VAR_612 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(" ");
long int strLen_1 = strlen(a->name);
;                            
                    ____BAH_COMPILER_VAR_612 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_612+currStrOff, " ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_612+currStrOff, a->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_612[currStrOff] = 0;
                }
                tp.append((struct string*)&tp,____BAH_COMPILER_VAR_612);
max =  len(arguments) - 1;
if ((j!=max)) {
tp.append((struct string*)&tp,",");
}
char * ____BAH_COMPILER_VAR_613 =tp.str((struct string*)&tp);mthdDecl.append((struct string*)&mthdDecl,____BAH_COMPILER_VAR_613);
j =  j + 1;
};
mthdDecl.append((struct string*)&mthdDecl,")");

{
long nLength = len(allMembs);
if (allMembs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(allMembs->data, (nLength+50)*sizeof(char *));
allMembs->data = newPtr;
}
allMembs->data[len(allMembs)] =  mthdDecl.str((struct string*)&mthdDecl);
allMembs->length = nLength+1;
} else {
allMembs->data[len(allMembs)] =  mthdDecl.str((struct string*)&mthdDecl);
}
};
i =  i+1;
continue;
}
}
i =  i+1;
char * mbmType =  "";
long int currentLine =  t.line;
while ((i<len(l))) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2875): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    t =  l->data[i];
if ((strcmp(t.cont, "=") == 0)) {
i =  i-1;
break;
}
if ((t.line!=currentLine)) {
i =  i-1;
break;
}
char * ____BAH_COMPILER_VAR_614 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(mbmType);
long int strLen_1 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_614 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_614+currStrOff, mbmType, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_614+currStrOff, t.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_614[currStrOff] = 0;
                }
                mbmType =  ____BAH_COMPILER_VAR_614;
i =  i+1;
};
memb->type =  mbmType;
i =  i+1;

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2890): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    t =  l->data[i];
if ((i<len(l))) {
if ((strcmp(t.cont, "=") == 0)) {
i =  i+1;

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2894): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    t =  l->data[i];
if ((t.isValue==false)) {
throwErr(&t,"Cannot use {TOKEN} as default value for member.");
}
char * tt =  getTypeFromToken(&t,true,elems);
if ((compTypes(tt,memb->type)==false)) {
char * ____BAH_COMPILER_VAR_615 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(tt);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(memb->type);
long int strLen_4 = strlen(" for member.");
;                            
                    ____BAH_COMPILER_VAR_615 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_615+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_615+currStrOff, tt, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_615+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_615+currStrOff, memb->type, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_615+currStrOff, " for member.", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_615[currStrOff] = 0;
                }
                throwErr(&t,____BAH_COMPILER_VAR_615);
}
memb->def =  t.cont;
}
else {
i =  i-1;
}
}
if (isRCPpointerType(memb->type)) {
s->hasRCPmemb =  true;
}

{
long nLength = len(members);
if (members->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(members->data, (nLength+50)*sizeof(struct structMemb*));
members->data = newPtr;
}
members->data[len(members)] =  memb;
members->length = nLength+1;
} else {
members->data[len(members)] =  memb;
}
};
char * membDeclStr= null;
struct string cmt =  string(memb->type);
if ((cmt.hasPrefix((struct string*)&cmt,"function(")==1)) {
struct func* tmpfn =  parseFnType(cmt);
struct string tmpfnRetCType =  getCType(tmpfn->returns->type,elems);
char * tmpfnArgsCType =  "";
long int j =  0;
while ((j<len(tmpfn->args))) {

                    if (tmpfn->args->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2920): tmpfn->args[%d] with length %d\n", j, tmpfn->args->length);
                        exit(1);
                    };
                    struct variable* arg =  tmpfn->args->data[j];
struct string ct =  getCType(arg->type,elems);
char * ____BAH_COMPILER_VAR_616 =ct.str((struct string*)&ct);char * ____BAH_COMPILER_VAR_617 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_616);
;                            
                    ____BAH_COMPILER_VAR_617 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_617+currStrOff, tmpfnArgsCType, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_617+currStrOff, ____BAH_COMPILER_VAR_616, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_617[currStrOff] = 0;
                }
                tmpfnArgsCType =  ____BAH_COMPILER_VAR_617;
j =  j + 1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_618 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(",");
;                            
                    ____BAH_COMPILER_VAR_618 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_618+currStrOff, tmpfnArgsCType, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_618+currStrOff, ",", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_618[currStrOff] = 0;
                }
                tmpfnArgsCType =  ____BAH_COMPILER_VAR_618;
}
};
char * ____BAH_COMPILER_VAR_619 =tmpfnRetCType.str((struct string*)&tmpfnRetCType);char * ____BAH_COMPILER_VAR_620 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_619);
long int strLen_1 = strlen(" (*");
long int strLen_2 = strlen(memb->name);
long int strLen_3 = strlen(")(");
long int strLen_4 = strlen(tmpfnArgsCType);
long int strLen_5 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_620 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    memcpy(____BAH_COMPILER_VAR_620+currStrOff, ____BAH_COMPILER_VAR_619, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_620+currStrOff, " (*", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_620+currStrOff, memb->name, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_620+currStrOff, ")(", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_620+currStrOff, tmpfnArgsCType, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_620+currStrOff, ")", strLen_5);
                    currStrOff += strLen_5;
                    
                    ____BAH_COMPILER_VAR_620[currStrOff] = 0;
                }
                membDeclStr =  ____BAH_COMPILER_VAR_620;
}
else {
struct string membDecl =  getCType(memb->type,elems);
char * ____BAH_COMPILER_VAR_621 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(" ");
long int strLen_1 = strlen(memb->name);
;                            
                    ____BAH_COMPILER_VAR_621 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_621+currStrOff, " ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_621+currStrOff, memb->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_621[currStrOff] = 0;
                }
                membDecl.append((struct string*)&membDecl,____BAH_COMPILER_VAR_621);
membDeclStr =  membDecl.str((struct string*)&membDecl);
}

{
long nLength = len(allMembs);
if (allMembs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(allMembs->data, (nLength+50)*sizeof(char *));
allMembs->data = newPtr;
}
allMembs->data[len(allMembs)] =  membDeclStr;
allMembs->length = nLength+1;
} else {
allMembs->data[len(allMembs)] =  membDeclStr;
}
};
i =  i+1;
};
s->members =  members;
if ((doesOutput==true)) {
OUTPUT =  OOUT;
NEXT_LINE =  nextLine;
char * ____BAH_COMPILER_VAR_622 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("struct ");
long int strLen_1 = strlen(s->name);
long int strLen_2 = strlen(" {\n");
;                            
                    ____BAH_COMPILER_VAR_622 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_622+currStrOff, "struct ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_622+currStrOff, s->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_622+currStrOff, " {\n", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_622[currStrOff] = 0;
                }
                struct rope* code =  rope(____BAH_COMPILER_VAR_622);
i =  0;
while ((i<len(allMembs))) {

                    if (allMembs->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2943): allMembs[%d] with length %d\n", i, allMembs->length);
                        exit(1);
                    };
                    char * m =  allMembs->data[i];
char * ____BAH_COMPILER_VAR_623 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(m);
long int strLen_1 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_623 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_623+currStrOff, m, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_623+currStrOff, ";\n", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_623[currStrOff] = 0;
                }
                code =  code->add(code, rope(____BAH_COMPILER_VAR_623));
i =  i+1;
};
if ((RCPavailable()==true)) {
code =  code->add(code, rope("void * __RCP_counter;\n"));
}
code =  code->add(code, rope("};\n"));
OUTPUT =  OUTPUT->add(OUTPUT, code)->add(OUTPUT->add(OUTPUT, code), makeRCPfuncFromStruct(s,elems));
}
if ((debug==true)) {
struct debugStruct* ____BAH_COMPILER_VAR_624 = memoryAlloc(sizeof(struct debugStruct));
____BAH_COMPILER_VAR_624->name= null;
____BAH_COMPILER_VAR_624->membs = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_624->membs->length = 0;
            ____BAH_COMPILER_VAR_624->membs->elemSize = sizeof(struct variable*);
            struct debugStruct* ds =  ____BAH_COMPILER_VAR_624;
ds->name =  s->name;
i =  0;
while ((i<len(s->members))) {

                    if (s->members->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2960): s->members[%d] with length %d\n", i, s->members->length);
                        exit(1);
                    };
                    struct structMemb* m =  s->members->data[i];
struct variable* ____BAH_COMPILER_VAR_625 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_625->name = "";
____BAH_COMPILER_VAR_625->type = "";
____BAH_COMPILER_VAR_625->isConst = false;
____BAH_COMPILER_VAR_625->constVal = "";
____BAH_COMPILER_VAR_625->isArray = false;
____BAH_COMPILER_VAR_625->from = "";
____BAH_COMPILER_VAR_625->outterScope = false;
____BAH_COMPILER_VAR_625->isGlobal = false;
struct variable* mv =  ____BAH_COMPILER_VAR_625;
mv->name =  m->name;
mv->type =  m->type;
mv->isConst =  false;
mv->isArray =  m->isArray;

{
long nLength = i;
if (ds->membs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(ds->membs->data, (nLength+50)*sizeof(struct variable*));
ds->membs->data = newPtr;
}
ds->membs->data[i] =  mv;
ds->membs->length = nLength+1;
} else {
ds->membs->data[i] =  mv;
}
};
i =  i + 1;
};
struct debugStruct* ____BAH_COMPILER_VAR_626 = ds;
char ** ____BAH_COMPILER_VAR_628 = (char **)((char*)(____BAH_COMPILER_VAR_626) + offsetof(struct debugStruct, name));
struct reflectElement ____BAH_COMPILER_VAR_629 = __reflect(____BAH_COMPILER_VAR_628, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct debugStruct, name));
array(struct variable*)** ____BAH_COMPILER_VAR_630 = (array(struct variable*)**)((char*)(____BAH_COMPILER_VAR_626) + offsetof(struct debugStruct, membs));
struct variable** ____BAH_COMPILER_VAR_631 = 0;
char ** ____BAH_COMPILER_VAR_633 = (char **)((char*)(____BAH_COMPILER_VAR_631) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_634 = __reflect(____BAH_COMPILER_VAR_633, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_635 = (char **)((char*)(____BAH_COMPILER_VAR_631) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_636 = __reflect(____BAH_COMPILER_VAR_635, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_637 = (char*)((char*)(____BAH_COMPILER_VAR_631) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_638 = __reflect(____BAH_COMPILER_VAR_637, sizeof(char), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_639 = (char **)((char*)(____BAH_COMPILER_VAR_631) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_640 = __reflect(____BAH_COMPILER_VAR_639, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_641 = (char*)((char*)(____BAH_COMPILER_VAR_631) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_642 = __reflect(____BAH_COMPILER_VAR_641, sizeof(char), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_643 = (char **)((char*)(____BAH_COMPILER_VAR_631) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_644 = __reflect(____BAH_COMPILER_VAR_643, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
char* ____BAH_COMPILER_VAR_645 = (char*)((char*)(____BAH_COMPILER_VAR_631) + offsetof(struct variable, outterScope));
struct reflectElement ____BAH_COMPILER_VAR_646 = __reflect(____BAH_COMPILER_VAR_645, sizeof(char), "bool", "outterScope", 0, 0, 0, 0, offsetof(struct variable, outterScope));
char* ____BAH_COMPILER_VAR_647 = (char*)((char*)(____BAH_COMPILER_VAR_631) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_648 = __reflect(____BAH_COMPILER_VAR_647, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_632 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_632->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_632->length = 8;
        ____BAH_COMPILER_VAR_632->data = memoryAlloc(____BAH_COMPILER_VAR_632->length * ____BAH_COMPILER_VAR_632->elemSize);
        ____BAH_COMPILER_VAR_632->data[0] = ____BAH_COMPILER_VAR_634;
____BAH_COMPILER_VAR_632->data[1] = ____BAH_COMPILER_VAR_636;
____BAH_COMPILER_VAR_632->data[2] = ____BAH_COMPILER_VAR_638;
____BAH_COMPILER_VAR_632->data[3] = ____BAH_COMPILER_VAR_640;
____BAH_COMPILER_VAR_632->data[4] = ____BAH_COMPILER_VAR_642;
____BAH_COMPILER_VAR_632->data[5] = ____BAH_COMPILER_VAR_644;
____BAH_COMPILER_VAR_632->data[6] = ____BAH_COMPILER_VAR_646;
____BAH_COMPILER_VAR_632->data[7] = ____BAH_COMPILER_VAR_648;
struct reflectElement ____BAH_COMPILER_VAR_649 = __reflect(____BAH_COMPILER_VAR_631, sizeof(struct variable), "variable*", "", 0, 0, 1, ____BAH_COMPILER_VAR_632, 0);

        struct reflectElement ____BAH_COMPILER_VAR_650 = ____BAH_COMPILER_VAR_649;
        struct reflectElement ____BAH_COMPILER_VAR_651 = __reflect(____BAH_COMPILER_VAR_630, sizeof(array(struct variable*)*), "[]variable*", "membs", 1, &____BAH_COMPILER_VAR_650, 0, 0, offsetof(struct debugStruct, membs));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_627 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_627->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_627->length = 2;
        ____BAH_COMPILER_VAR_627->data = memoryAlloc(____BAH_COMPILER_VAR_627->length * ____BAH_COMPILER_VAR_627->elemSize);
        ____BAH_COMPILER_VAR_627->data[0] = ____BAH_COMPILER_VAR_629;
____BAH_COMPILER_VAR_627->data[1] = ____BAH_COMPILER_VAR_651;
struct reflectElement ____BAH_COMPILER_VAR_652 = __reflect(____BAH_COMPILER_VAR_626, sizeof(struct debugStruct), "debugStruct*", "ds", 0, 0, 1, ____BAH_COMPILER_VAR_627, 0);
debugPrint("struct_declare",nameToken.line,____BAH_COMPILER_VAR_652);
}
};
void parseDefine(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
if ((len(l)<3)) {
throwErr(&l->data[len(l)-1],"Invalid usage of define, cannot end on {TOKEN}.");
}

                    if (l->length <= 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2982): l[%d] with length %d\n", 1, l->length);
                        exit(1);
                    };
                    struct Tok ft =  l->data[1];

                    if (l->length <= 2) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2983): l[%d] with length %d\n", 2, l->length);
                        exit(1);
                    };
                    struct Tok st =  l->data[2];
long int i =  1;
char doesOutput =  true;
if ((strcmp(ft.cont, "!") == 0)) {

                    if (l->length <= 2) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2988): l[%d] with length %d\n", 2, l->length);
                        exit(1);
                    };
                    ft =  l->data[2];

                    if (l->length <= 3) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2989): l[%d] with length %d\n", 3, l->length);
                        exit(1);
                    };
                    st =  l->data[3];
i =  2;
doesOutput =  false;
}
if ((strcmp(st.cont, "(") == 0)) {
struct func* ____BAH_COMPILER_VAR_653 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_653->name = "";
____BAH_COMPILER_VAR_653->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_653->args->length = 0;
            ____BAH_COMPILER_VAR_653->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_653->returns= null;
____BAH_COMPILER_VAR_653->isBinding = false;
____BAH_COMPILER_VAR_653->from = "";
____BAH_COMPILER_VAR_653->file = "";
____BAH_COMPILER_VAR_653->line = 1;
____BAH_COMPILER_VAR_653->used = false;
____BAH_COMPILER_VAR_653->code = null;
struct func* fn =  ____BAH_COMPILER_VAR_653;
char * code =  parseFnHeader("",l,&i,fn,elems);
array(struct func*)* fns =  elems->fns;
fn->isBinding =  true;

{
long nLength = len(fns);
if (fns->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(fns->data, (nLength+50)*sizeof(struct func*));
fns->data = newPtr;
}
fns->data[len(fns)] =  fn;
fns->length = nLength+1;
} else {
fns->data[len(fns)] =  fn;
}
};
if ((doesOutput==true)) {
char * ____BAH_COMPILER_VAR_654 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_654 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_654+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_654+currStrOff, ";\n", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_654[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_654));
}
}
else {
char * tp =  "";
i =  i+1;
for (; (i<len(l)); i =  i+1) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3008): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    struct Tok t =  l->data[i];
char * ____BAH_COMPILER_VAR_655 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tp);
long int strLen_1 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_655 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_655+currStrOff, tp, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_655+currStrOff, t.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_655[currStrOff] = 0;
                }
                tp =  ____BAH_COMPILER_VAR_655;
};
if ((ft.type!=TOKEN_TYPE_VAR)) {
throwErr(&ft,"Cannot use {TOKEN} as new type name.");
}
struct string cTypeNewType =  getCType(tp,elems);
char * cTypeNewTypeStr =  cTypeNewType.str((struct string*)&cTypeNewType);
if ((doesOutput==true)) {
char * ____BAH_COMPILER_VAR_656 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("typedef ");
long int strLen_1 = strlen(cTypeNewTypeStr);
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(ft.cont);
long int strLen_4 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_656 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_656+currStrOff, "typedef ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_656+currStrOff, cTypeNewTypeStr, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_656+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_656+currStrOff, ft.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_656+currStrOff, ";\n", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_656[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_656));
}
if ((debug==true)) {
struct debugType* ____BAH_COMPILER_VAR_657 = memoryAlloc(sizeof(struct debugType));
____BAH_COMPILER_VAR_657->name= null;
____BAH_COMPILER_VAR_657->refers= null;
struct debugType* dt =  ____BAH_COMPILER_VAR_657;
dt->name =  ft.cont;
dt->refers =  tp;
struct debugType* ____BAH_COMPILER_VAR_658 = dt;
char ** ____BAH_COMPILER_VAR_660 = (char **)((char*)(____BAH_COMPILER_VAR_658) + offsetof(struct debugType, name));
struct reflectElement ____BAH_COMPILER_VAR_661 = __reflect(____BAH_COMPILER_VAR_660, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct debugType, name));
char ** ____BAH_COMPILER_VAR_662 = (char **)((char*)(____BAH_COMPILER_VAR_658) + offsetof(struct debugType, refers));
struct reflectElement ____BAH_COMPILER_VAR_663 = __reflect(____BAH_COMPILER_VAR_662, sizeof(char *), "cpstring", "refers", 0, 0, 0, 0, offsetof(struct debugType, refers));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_659 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_659->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_659->length = 2;
        ____BAH_COMPILER_VAR_659->data = memoryAlloc(____BAH_COMPILER_VAR_659->length * ____BAH_COMPILER_VAR_659->elemSize);
        ____BAH_COMPILER_VAR_659->data[0] = ____BAH_COMPILER_VAR_661;
____BAH_COMPILER_VAR_659->data[1] = ____BAH_COMPILER_VAR_663;
struct reflectElement ____BAH_COMPILER_VAR_664 = __reflect(____BAH_COMPILER_VAR_658, sizeof(struct debugType), "debugType*", "dt", 0, 0, 1, ____BAH_COMPILER_VAR_659, 0);
debugPrint("type_declare",ft.line,____BAH_COMPILER_VAR_664);
}
array(char *)* tps =  elems->types;

{
long nLength = len(tps);
if (tps->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tps->data, (nLength+50)*sizeof(char *));
tps->data = newPtr;
}
tps->data[len(tps)] =  ft.cont;
tps->length = nLength+1;
} else {
tps->data[len(tps)] =  ft.cont;
}
};
}
};
void parseClib(__BAH_ARR_TYPE_Tok line){
array(char *)* clibs =  compilerState.cLibs;
long int i =  1;
while ((i<len(line))) {

                    if (line->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3038): line[%d] with length %d\n", i, line->length);
                        exit(1);
                    };
                    struct Tok t =  line->data[i];
if ((t.type!=TOKEN_TYPE_STR)) {
throwErr(&t,"Cannot use {TOKEN} as C library name.");
}
struct string cc =  string(t.cont);
cc.trimLeft((struct string*)&cc,1);
cc.trimRight((struct string*)&cc,1);
char * ccstr =  cc.str((struct string*)&cc);
char found =  false;
long int j =  0;
while ((j<len(clibs))) {

                    if (clibs->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3050): clibs[%d] with length %d\n", j, clibs->length);
                        exit(1);
                    };
                    char * l =  clibs->data[j];
if ((strcmp(l, ccstr) == 0)) {
found =  true;
break;
}
j =  j + 1;
};
if ((found==true)) {
i =  i+1;
continue;
}

{
long nLength = len(clibs);
if (clibs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(clibs->data, (nLength+50)*sizeof(char *));
clibs->data = newPtr;
}
clibs->data[len(clibs)] =  ccstr;
clibs->length = nLength+1;
} else {
clibs->data[len(clibs)] =  ccstr;
}
};
i =  i+1;
};
};
void parseConst(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
l =  parseCast(l,elems);
if ((len(l)!=4)) {
throwErr(&l->data[0],"Invalid usage of {TOKEN}, must be 'const <constName> = <constValue>'. ");
}

                    if (l->length <= 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3073): l[%d] with length %d\n", 1, l->length);
                        exit(1);
                    };
                    struct Tok vart =  l->data[1];

                    if (l->length <= 2) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3074): l[%d] with length %d\n", 2, l->length);
                        exit(1);
                    };
                    struct Tok equt =  l->data[2];

                    if (l->length <= 3) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3075): l[%d] with length %d\n", 3, l->length);
                        exit(1);
                    };
                    struct Tok valt =  l->data[3];
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
struct func* fn =  searchFunc(valt.cont,elems,true);
if ((fn!=null)) {
fn->used =  true;
}
}
struct variable* ____BAH_COMPILER_VAR_665 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_665->name = "";
____BAH_COMPILER_VAR_665->type = "";
____BAH_COMPILER_VAR_665->isConst = false;
____BAH_COMPILER_VAR_665->constVal = "";
____BAH_COMPILER_VAR_665->isArray = false;
____BAH_COMPILER_VAR_665->from = "";
____BAH_COMPILER_VAR_665->outterScope = false;
____BAH_COMPILER_VAR_665->isGlobal = false;
struct variable* v =  ____BAH_COMPILER_VAR_665;
if (isGlobal()) {
v->isGlobal =  true;
}
v->isConst =  true;
v->constVal =  valt.cont;
v->name =  vart.cont;
v->type =  getTypeFromToken(&valt,true,elems);
array(struct variable*)* vars =  elems->vars;

{
long nLength = len(vars);
if (vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(vars->data, (nLength+50)*sizeof(struct variable*));
vars->data = newPtr;
}
vars->data[len(vars)] =  v;
vars->length = nLength+1;
} else {
vars->data[len(vars)] =  v;
}
};
char * ____BAH_COMPILER_VAR_666 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("#define ");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(valt.cont);
long int strLen_4 = strlen("\n");
;                            
                    ____BAH_COMPILER_VAR_666 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_666+currStrOff, "#define ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_666+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_666+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_666+currStrOff, valt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_666+currStrOff, "\n", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_666[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_666));
};
void parseReturn(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
if ((len(l)>2)) {
throwErr(&l->data[0],"Invalid usage of {TOKEN}, must be 'return <returnValue>'");
}
if ((currentFn==null)) {
throwErr(&l->data[0],"Cannot return a value outside of a function.");
}
char * rv =  "";
if ((len(l)==1)) {
if ((strlen(currentFn->returns->type)!=0)) {
char * ____BAH_COMPILER_VAR_667 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot return nothing as ");
long int strLen_1 = strlen(currentFn->returns->type);
long int strLen_2 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_667 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_667+currStrOff, "Cannot return nothing as ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_667+currStrOff, currentFn->returns->type, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_667+currStrOff, ".", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_667[currStrOff] = 0;
                }
                throwErr(&l->data[0],____BAH_COMPILER_VAR_667);
}
}
else {

                    if (l->length <= 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3125): l[%d] with length %d\n", 1, l->length);
                        exit(1);
                    };
                    struct Tok rvt =  l->data[1];
if ((rvt.isValue==false)) {
throwErr(&rvt,"Must be a value, not {TOKEN}.");
}
else if (((rvt.type==TOKEN_TYPE_VAR)&&(rvt.isOper==false))) {
struct variable* v =  searchVar(rvt.cont,elems);
if (((((v!=null)&&(isRCPtype(v->type,elems)==true))&&(v->outterScope==false))&&(RCPavailable()==true))) {
OUTPUT =  OUTPUT->add(OUTPUT, incrVar(v,elems));
}
}
rv =  rvt.cont;
char * tt =  getTypeFromToken(&rvt,true,elems);
if ((compTypes(tt,currentFn->returns->type)==false)) {
char * ____BAH_COMPILER_VAR_668 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot return {TOKEN} (");
long int strLen_1 = strlen(tt);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(currentFn->returns->type);
long int strLen_4 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_668 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_668+currStrOff, "Cannot return {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_668+currStrOff, tt, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_668+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_668+currStrOff, currentFn->returns->type, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_668+currStrOff, ".", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_668[currStrOff] = 0;
                }
                throwErr(&rvt,____BAH_COMPILER_VAR_668);
}
}
if ((compilerState.isBranch==false)) {
currentFn->returned =  true;
}
if ((strlen(rv)>0)) {
char * rvar =  rv;
if (((RCPavailable()==true)&&isRCPpointerType(currentFn->returns->type))) {
rvar =  genCompilerVar();
struct string cType =  getCType(currentFn->returns->type,elems);
char * ____BAH_COMPILER_VAR_669 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_670 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_669);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(rvar);
long int strLen_3 = strlen(" = ");
long int strLen_4 = strlen(rv);
long int strLen_5 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_670 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    memcpy(____BAH_COMPILER_VAR_670+currStrOff, ____BAH_COMPILER_VAR_669, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_670+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_670+currStrOff, rvar, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_670+currStrOff, " = ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_670+currStrOff, rv, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_670+currStrOff, ";\n", strLen_5);
                    currStrOff += strLen_5;
                    
                    ____BAH_COMPILER_VAR_670[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_670));
}
endRCPnonGlobScope(elems,currentFn->args);
char * ____BAH_COMPILER_VAR_671 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("return ");
long int strLen_1 = strlen(rvar);
long int strLen_2 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_671 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_671+currStrOff, "return ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_671+currStrOff, rvar, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_671+currStrOff, ";\n", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_671[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_671));
}
else {
endRCPnonGlobScope(elems,currentFn->args);
OUTPUT =  OUTPUT->add(OUTPUT, rope("return;\n"));
}
};
void parseIf(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
if ((len(l)<4)) {

                    if (l->length <= 0) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3162): l[%d] with length %d\n", 0, l->length);
                        exit(1);
                    };
                    struct Tok ft =  l->data[0];
throwErr(&ft,"Invalid usage of {TOKEN}, must be 'if <condition> {<code>}'");
}

                    if (l->length <= 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3165): l[%d] with length %d\n", 1, l->length);
                        exit(1);
                    };
                    struct Tok condt =  l->data[1];
if ((strcmp(condt.bahType, "bool") != 0)) {
if ((strcmp(condt.bahType, "int") != 0)) {
throwErr(&condt,"Cannot use {TOKEN} as condition in if statement.");
}
}

                    if (l->length <= 2) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3171): l[%d] with length %d\n", 2, l->length);
                        exit(1);
                    };
                    struct Tok t =  l->data[2];
if ((strcmp(t.cont, "{") != 0)) {
throwErr(&t,"Expected '{' not {TOKEN} after condtition in if statement.");
}
array(struct Tok)* tokens = memoryAlloc(sizeof(array(struct Tok)));

tokens->length = 0;
tokens->elemSize = sizeof(struct Tok);
long int max =  len(l) - 1;
long int i =  3;
while ((i<max)) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3178): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    t =  l->data[i];

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] =  t;
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] =  t;
}
};
i =  i+1;
};
char * ____BAH_COMPILER_VAR_672 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("if (");
long int strLen_1 = strlen(condt.cont);
long int strLen_2 = strlen(") {\n");
;                            
                    ____BAH_COMPILER_VAR_672 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_672+currStrOff, "if (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_672+currStrOff, condt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_672+currStrOff, ") {\n", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_672[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_672));
struct Elems* ifElems =  dupElems(elems);
char oldIB =  compilerState.isBranch;
compilerState.isBranch =  true;
parseLines(tokens,ifElems);
endRCPscope(ifElems,null);
if ((debug==true)) {

                    if (l->length <= len(l)-1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3191): l[%d] with length %d\n", len(l)-1, l->length);
                        exit(1);
                    };
                    struct Tok lt =  l->data[len(l)-1];
debugEndScope(lt.line,ifElems);
}
compilerState.isBranch =  oldIB;
OUTPUT =  OUTPUT->add(OUTPUT, rope("}\n"));
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

                    if (l->length <= 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3210): l[%d] with length %d\n", 1, l->length);
                        exit(1);
                    };
                    struct Tok ft =  l->data[1];
OUTPUT =  OUTPUT->add(OUTPUT, rope("else "));
if ((strcmp(ft.cont, "if") == 0)) {
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
long int i =  1;
while ((i<len(l))) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3215): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    
{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] =  l->data[i];
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  l->data[i];
}
};
i =  i+1;
};
parseIf(memory,elems);
prevLine =  LINE_TYPE_IF;
}
else {
if ((strcmp(ft.cont, "{") != 0)) {
throwErr(&ft,"Expected 'if' or '{' not {TOKEN}.");
}
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
long int max =  len(l) - 1;
long int i =  2;
while ((i<max)) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3228): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    
{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] =  l->data[i];
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  l->data[i];
}
};
i =  i+1;
};
OUTPUT =  OUTPUT->add(OUTPUT, rope("{\n"));
struct Elems* ifElems =  dupElems(elems);
char oldIB =  compilerState.isBranch;
compilerState.isBranch =  true;
parseLines(memory,ifElems);
endRCPscope(ifElems,null);
if ((debug==true)) {

                    if (l->length <= len(l)-1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3239): l[%d] with length %d\n", len(l)-1, l->length);
                        exit(1);
                    };
                    struct Tok lt =  l->data[len(l)-1];
debugEndScope(lt.line,ifElems);
}
compilerState.isBranch =  oldIB;
OUTPUT =  OUTPUT->add(OUTPUT, rope("}\n"));
}
};
void parseLine(__BAH_ARR_TYPE_Tok l,struct Elems* elems);
void parseFor(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
if ((len(l)<4)) {
throwErr(&l->data[0],"Invalid usage of {TOKEN}.");
}
long int nbComas =  0;
long int i =  1;
while ((i<len(l))) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3258): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    struct Tok t =  l->data[i];
if ((strcmp(t.cont, "{") == 0)) {
break;
}
if (((t.type==TOKEN_TYPE_SYNTAX)&&(strcmp(t.cont, ",") == 0))) {
if ((nbComas==1)) {
throwErr(&t,"Invalid line separation of for, cannot set more than 2 lines: {TOKEN}.");
}
nbComas =  nbComas + 1;
}
i =  i + 1;
};
array(struct Tok)* tokens = memoryAlloc(sizeof(array(struct Tok)));

tokens->length = 0;
tokens->elemSize = sizeof(struct Tok);
if ((nbComas>0)) {
if ((nbComas!=1)) {

                    if (l->length <= 0) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3274): l[%d] with length %d\n", 0, l->length);
                        exit(1);
                    };
                    struct Tok t =  l->data[0];
throwErr(&t,"Invalid usage of {TOKEN}, can only partition line in 2 using 'for <condition>, <insctruction> {<code>}'.");
}
array(struct Tok)* inst = memoryAlloc(sizeof(array(struct Tok)));

inst->length = 0;
inst->elemSize = sizeof(struct Tok);

                    if (l->length <= 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3279): l[%d] with length %d\n", 1, l->length);
                        exit(1);
                    };
                    struct Tok condt =  l->data[1];
if ((strcmp(condt.bahType, "bool") != 0)) {
if ((strcmp(condt.bahType, "int") != 0)) {
throwErr(&condt,"Cannot use {TOKEN} as condition in for statement.");
}
}

                    if (l->length <= 2) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3287): l[%d] with length %d\n", 2, l->length);
                        exit(1);
                    };
                    struct Tok st =  l->data[2];
if (((st.type!=TOKEN_TYPE_SYNTAX)||(strcmp(st.cont, ",") != 0))) {
throwErr(&st,"Cannot use {TOKEN}, need ',' to split for loop instructions.");
}
i =  3;
for (; (i<len(l)); i =  i+1) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3294): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    struct Tok t =  l->data[i];
if (((t.type==TOKEN_TYPE_ENCL)&&(strcmp(t.cont, "{") == 0))) {
break;
}

{
long nLength = len(inst);
if (inst->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(inst->data, (nLength+50)*sizeof(struct Tok));
inst->data = newPtr;
}
inst->data[len(inst)] =  t;
inst->length = nLength+1;
} else {
inst->data[len(inst)] =  t;
}
};
};
struct rope* oldOut =  OUTPUT;
OUTPUT =  rope("");
parseLine(inst,elems);
char * ____BAH_COMPILER_VAR_673 =OUTPUT->toStr((struct rope*)OUTPUT);struct string instC =  string(____BAH_COMPILER_VAR_673);
OUTPUT =  oldOut;
instC.trimRight((struct string*)&instC,2);

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3310): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    struct Tok t =  l->data[i];
if ((strcmp(t.cont, "{") != 0)) {
throwErr(&t,"Expected '{' not {TOKEN} after '<condition>,<instruction>' in for statement.");
}
long int max =  len(l) - 1;
i =  i + 1;
for (; (i<max); i =  i+1) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3317): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    t =  l->data[i];

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] =  t;
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] =  t;
}
};
};
char * ____BAH_COMPILER_VAR_674 =instC.str((struct string*)&instC);char * ____BAH_COMPILER_VAR_675 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("for (; ");
long int strLen_1 = strlen(condt.cont);
long int strLen_2 = strlen("; ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_674);
long int strLen_4 = strlen(") {\n");
;                            
                    ____BAH_COMPILER_VAR_675 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_675+currStrOff, "for (; ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_675+currStrOff, condt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_675+currStrOff, "; ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_675+currStrOff, ____BAH_COMPILER_VAR_674, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_675+currStrOff, ") {\n", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_675[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_675));
}
else {

                    if (l->length <= 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3324): l[%d] with length %d\n", 1, l->length);
                        exit(1);
                    };
                    struct Tok condt =  l->data[1];
if ((strcmp(condt.bahType, "bool") != 0)) {
if ((strcmp(condt.bahType, "int") != 0)) {
throwErr(&condt,"Cannot use {TOKEN} as condition in for statement.");
}
}

                    if (l->length <= 2) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3330): l[%d] with length %d\n", 2, l->length);
                        exit(1);
                    };
                    struct Tok t =  l->data[2];
if ((strcmp(t.cont, "{") != 0)) {
throwErr(&t,"Expected '{' not {TOKEN} after condtition in for statement.");
}
long int max =  len(l) - 1;
i =  3;
for (; (i<max); i =  i+1) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3336): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    t =  l->data[i];

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] =  t;
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] =  t;
}
};
};
char * ____BAH_COMPILER_VAR_676 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("while (");
long int strLen_1 = strlen(condt.cont);
long int strLen_2 = strlen(") {\n");
;                            
                    ____BAH_COMPILER_VAR_676 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_676+currStrOff, "while (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_676+currStrOff, condt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_676+currStrOff, ") {\n", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_676[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_676));
}
struct Elems* ifElems =  dupElems(elems);
char oldIB =  compilerState.isBranch;
char oldIF =  compilerState.isFor;
compilerState.isBranch =  true;
compilerState.isFor =  true;
parseLines(tokens,ifElems);
endRCPscope(ifElems,null);
if ((debug==true)) {

                    if (l->length <= len(l)-1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3350): l[%d] with length %d\n", len(l)-1, l->length);
                        exit(1);
                    };
                    struct Tok lt =  l->data[len(l)-1];
debugEndScope(lt.line,ifElems);
}
compilerState.isFor =  oldIF;
compilerState.isBranch =  oldIB;
OUTPUT =  OUTPUT->add(OUTPUT, rope("};\n"));
};
void parseForOp(__BAH_ARR_TYPE_Tok l,struct Elems* elems){

                    if (l->length <= 0) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3361): l[%d] with length %d\n", 0, l->length);
                        exit(1);
                    };
                    struct Tok ft =  l->data[0];
if ((compilerState.isFor==false)) {
throwErr(&ft,"Cannot {TOKEN} outside of for statement.");
}
if ((len(l)!=1)) {
throwErr(&ft,"Nothing expected after {TOKEN}.");
}
endRCPscope(elems,null);
char * ____BAH_COMPILER_VAR_677 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ft.cont);
long int strLen_1 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_677 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_677+currStrOff, ft.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_677+currStrOff, ";\n", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_677[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_677));
};
void makeEvalFunc(struct func* fn,struct Elems* elems){

                int ____BAH_COMPILER_VAR_678 = 0;
                for(int i=len(compilerState.evals)-1; i != -1; i--) {
                    if (compilerState.evals->data[i] != 0 && strcmp(compilerState.evals->data[i], fn->name) == 0) {
                        ____BAH_COMPILER_VAR_678 = 1;
                        break;
                    };
                };
                if (____BAH_COMPILER_VAR_678) {
return;
}
char * ____BAH_COMPILER_VAR_679 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("__Bah_eval_");
long int strLen_1 = strlen(fn->name);
;                            
                    ____BAH_COMPILER_VAR_679 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_679+currStrOff, "__Bah_eval_", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_679+currStrOff, fn->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_679[currStrOff] = 0;
                }
                struct func* ____BAH_COMPILER_VAR_680 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_680->name = "";
____BAH_COMPILER_VAR_680->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_680->args->length = 0;
            ____BAH_COMPILER_VAR_680->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_680->returns= null;
____BAH_COMPILER_VAR_680->isBinding = false;
____BAH_COMPILER_VAR_680->from = "";
____BAH_COMPILER_VAR_680->file = "";
____BAH_COMPILER_VAR_680->line = 1;
____BAH_COMPILER_VAR_680->used = false;
____BAH_COMPILER_VAR_680->code = null;
____BAH_COMPILER_VAR_680->name = ____BAH_COMPILER_VAR_679;
struct func* efn =  ____BAH_COMPILER_VAR_680;
struct variable* ____BAH_COMPILER_VAR_681 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_681->name = "";
____BAH_COMPILER_VAR_681->type = "";
____BAH_COMPILER_VAR_681->isConst = false;
____BAH_COMPILER_VAR_681->constVal = "";
____BAH_COMPILER_VAR_681->isArray = false;
____BAH_COMPILER_VAR_681->from = "";
____BAH_COMPILER_VAR_681->outterScope = false;
____BAH_COMPILER_VAR_681->isGlobal = false;
____BAH_COMPILER_VAR_681->type = "ptr";
efn->returns =  ____BAH_COMPILER_VAR_681;
struct variable* ____BAH_COMPILER_VAR_682 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_682->name = "";
____BAH_COMPILER_VAR_682->type = "";
____BAH_COMPILER_VAR_682->isConst = false;
____BAH_COMPILER_VAR_682->constVal = "";
____BAH_COMPILER_VAR_682->isArray = false;
____BAH_COMPILER_VAR_682->from = "";
____BAH_COMPILER_VAR_682->outterScope = false;
____BAH_COMPILER_VAR_682->isGlobal = false;
____BAH_COMPILER_VAR_682->name = "fnArgs";
____BAH_COMPILER_VAR_682->type = "[]ptr";
efn->args = memoryAlloc(sizeof(array(struct variable*)));

efn->args->length = 1;
efn->args->elemSize = sizeof(struct variable*);
efn->args->data = memoryAlloc(sizeof(struct variable*) * 50);efn->args->data[0] = ____BAH_COMPILER_VAR_682;
char * fnBinding =  "";
char * ____BAH_COMPILER_VAR_683 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(fn->name);
long int strLen_1 = strlen("(");
;                            
                    ____BAH_COMPILER_VAR_683 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_683+currStrOff, fn->name, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_683+currStrOff, "(", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_683[currStrOff] = 0;
                }
                char * fnCall =  ____BAH_COMPILER_VAR_683;
long int i =  0;
for (; (i<len(fn->args)); i =  i+1) {

                    if (fn->args->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3396): fn->args[%d] with length %d\n", i, fn->args->length);
                        exit(1);
                    };
                    struct variable* a =  fn->args->data[i];
char * v =  genCompilerVar();
struct string cType =  getCType(a->type,elems);
if ((isRCPpointerType(a->type)==false)) {
cType.append((struct string*)&cType,"*");
}
char * ____BAH_COMPILER_VAR_684 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_685 =intToStr(i);char * ____BAH_COMPILER_VAR_686 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_684);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(v);
long int strLen_3 = strlen(" = fnArgs->data[");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_685);
long int strLen_5 = strlen("];");
;                            
                    ____BAH_COMPILER_VAR_686 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    memcpy(____BAH_COMPILER_VAR_686+currStrOff, ____BAH_COMPILER_VAR_684, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_686+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_686+currStrOff, v, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_686+currStrOff, " = fnArgs->data[", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_686+currStrOff, ____BAH_COMPILER_VAR_685, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_686+currStrOff, "];", strLen_5);
                    currStrOff += strLen_5;
                    
                    ____BAH_COMPILER_VAR_686[currStrOff] = 0;
                }
                char * ____BAH_COMPILER_VAR_687 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(fnBinding);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_686);
;                            
                    ____BAH_COMPILER_VAR_687 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_687+currStrOff, fnBinding, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_687+currStrOff, ____BAH_COMPILER_VAR_686, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_687[currStrOff] = 0;
                }
                fnBinding =  ____BAH_COMPILER_VAR_687;
if ((i!=0)) {
char * ____BAH_COMPILER_VAR_688 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(fnCall);
long int strLen_1 = strlen(", ");
;                            
                    ____BAH_COMPILER_VAR_688 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_688+currStrOff, fnCall, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_688+currStrOff, ", ", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_688[currStrOff] = 0;
                }
                fnCall =  ____BAH_COMPILER_VAR_688;
}
if (isRCPpointerType(a->type)) {
char * ____BAH_COMPILER_VAR_689 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(fnCall);
long int strLen_1 = strlen(v);
;                            
                    ____BAH_COMPILER_VAR_689 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_689+currStrOff, fnCall, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_689+currStrOff, v, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_689[currStrOff] = 0;
                }
                fnCall =  ____BAH_COMPILER_VAR_689;
}
else {
char * ____BAH_COMPILER_VAR_690 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("*");
long int strLen_1 = strlen(v);
;                            
                    ____BAH_COMPILER_VAR_690 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_690+currStrOff, "*", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_690+currStrOff, v, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_690[currStrOff] = 0;
                }
                char * ____BAH_COMPILER_VAR_691 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(fnCall);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_690);
;                            
                    ____BAH_COMPILER_VAR_691 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_691+currStrOff, fnCall, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_691+currStrOff, ____BAH_COMPILER_VAR_690, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_691[currStrOff] = 0;
                }
                fnCall =  ____BAH_COMPILER_VAR_691;
}
};
char * setReturnValue =  "void* r = 0;";
if (isRCPpointerType(fn->returns->type)) {
setReturnValue =  "void* r = ";
}
else {
struct string cType =  getCType(fn->returns->type,elems);
if ((strcmp(cType.str((struct string*)&cType), "void") != 0)) {
char * ____BAH_COMPILER_VAR_692 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_693 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_694 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_692);
long int strLen_1 = strlen("* r = memoryAlloc(sizeof(");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_693);
long int strLen_3 = strlen("));*r = ");
;                            
                    ____BAH_COMPILER_VAR_694 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                    
                    memcpy(____BAH_COMPILER_VAR_694+currStrOff, ____BAH_COMPILER_VAR_692, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_694+currStrOff, "* r = memoryAlloc(sizeof(", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_694+currStrOff, ____BAH_COMPILER_VAR_693, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_694+currStrOff, "));*r = ", strLen_3);
                    currStrOff += strLen_3;
                    
                    ____BAH_COMPILER_VAR_694[currStrOff] = 0;
                }
                setReturnValue =  ____BAH_COMPILER_VAR_694;
}
}
char * ____BAH_COMPILER_VAR_695 =intToStr(len(fn->args));char * ____BAH_COMPILER_VAR_696 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("void* __attribute__((optimize(\"O0\"))) ");
long int strLen_1 = strlen(efn->name);
long int strLen_2 = strlen("(array(void*)* fnArgs) {\n        if (fnArgs->length != ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_695);
long int strLen_4 = strlen(") {\n            __BAH_panic(\"eval: calling function ");
long int strLen_5 = strlen(fn->name);
long int strLen_6 = strlen("() with the wrong number of arguments.\", \"BAH_COMPILER_INTERNAL\");\n        }\n        ");
long int strLen_7 = strlen(fnBinding);
long int strLen_8 = strlen("\n        ");
long int strLen_9 = strlen(setReturnValue);
long int strLen_10 = strlen(fnCall);
long int strLen_11 = strlen(");\n        return (void*)r;\n    };");
;                            
                    ____BAH_COMPILER_VAR_696 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11);
                    
                    memcpy(____BAH_COMPILER_VAR_696+currStrOff, "void* __attribute__((optimize(\"O0\"))) ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_696+currStrOff, efn->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_696+currStrOff, "(array(void*)* fnArgs) {\n        if (fnArgs->length != ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_696+currStrOff, ____BAH_COMPILER_VAR_695, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_696+currStrOff, ") {\n            __BAH_panic(\"eval: calling function ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_696+currStrOff, fn->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_696+currStrOff, "() with the wrong number of arguments.\", \"BAH_COMPILER_INTERNAL\");\n        }\n        ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_696+currStrOff, fnBinding, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_696+currStrOff, "\n        ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_696+currStrOff, setReturnValue, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_696+currStrOff, fnCall, strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_696+currStrOff, ");\n        return (void*)r;\n    };", strLen_11);
                    currStrOff += strLen_11;
                    
                    ____BAH_COMPILER_VAR_696[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_696));

{
long nLength = len(compilerState.evals);
if (compilerState.evals->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(compilerState.evals->data, (nLength+50)*sizeof(char *));
compilerState.evals->data = newPtr;
}
compilerState.evals->data[len(compilerState.evals)] =  fn->name;
compilerState.evals->length = nLength+1;
} else {
compilerState.evals->data[len(compilerState.evals)] =  fn->name;
}
};

{
long nLength = len(elems->fns);
if (elems->fns->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(elems->fns->data, (nLength+50)*sizeof(struct func*));
elems->fns->data = newPtr;
}
elems->fns->data[len(elems->fns)] =  efn;
elems->fns->length = nLength+1;
} else {
elems->fns->data[len(elems->fns)] =  efn;
}
};
};
void parsePreKeyword(__BAH_ARR_TYPE_Tok l,struct Elems* elems){

                    if (l->length <= 0) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3438): l[%d] with length %d\n", 0, l->length);
                        exit(1);
                    };
                    struct Tok ft =  l->data[0];
if ((strcmp(ft.cont, "#warning") == 0)) {
if ((len(l)!=2)) {
throwErr(&ft,"Invalid usage of {TOKEN} '#warning \"message\"'.");
}

                    if (l->length <= 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3444): l[%d] with length %d\n", 1, l->length);
                        exit(1);
                    };
                    struct Tok mt =  l->data[1];
if ((mt.type!=TOKEN_TYPE_STR)) {
throwErr(&mt,"Cannot use {TOKEN} as a string.");
}
struct string msg =  string(mt.cont);
msg.trimLeft((struct string*)&msg,1);
msg.trimRight((struct string*)&msg,1);
char * ____BAH_COMPILER_VAR_697 =msg.str((struct string*)&msg);throwWarning(____BAH_COMPILER_VAR_697);
return;
}
if ((strcmp(ft.cont, "#eval") == 0)) {

                int ____BAH_COMPILER_VAR_698 = 0;
                for(int i=len(compilerState.includes)-1; i != -1; i--) {
                    if (compilerState.includes->data[i] != 0 && strcmp(compilerState.includes->data[i], "eval.bah") == 0) {
                        ____BAH_COMPILER_VAR_698 = 1;
                        break;
                    };
                };
                if ((____BAH_COMPILER_VAR_698==false)) {
if ((includeFile("eval.bah",elems)==false)) {
char * ____BAH_COMPILER_VAR_699 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Could not find file 'eval.bah'. Check your bah directory (");
long int strLen_1 = strlen(BAH_DIR);
long int strLen_2 = strlen(").");
;                            
                    ____BAH_COMPILER_VAR_699 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_699+currStrOff, "Could not find file 'eval.bah'. Check your bah directory (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_699+currStrOff, BAH_DIR, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_699+currStrOff, ").", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_699[currStrOff] = 0;
                }
                throwErr(&l->data[0],____BAH_COMPILER_VAR_699);
}
}
if (((len(l)!=2)||(isGlobal()==false))) {
throwErr(&l->data[0],"Invalid usage of {TOKEN} <#eval fnName>.");
}

                    if (l->length <= 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3471): l[%d] with length %d\n", 1, l->length);
                        exit(1);
                    };
                    struct Tok fnT =  l->data[1];
struct func* fn =  searchFunc(fnT.cont,elems,false);
if ((fn==null)) {
throwErr(&fnT,"Unknown function {TOKEN}.");
}
fn->used =  true;
makeEvalFunc(fn,elems);
return;
}
if ((strcmp(ft.cont, "#evalAll") == 0)) {
long int i =  0;
for (; (i<len(elems->fns)); i =  i+1) {

                    if (elems->fns->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3485): elems->fns[%d] with length %d\n", i, elems->fns->length);
                        exit(1);
                    };
                    struct func* fn =  elems->fns->data[i];
fn->used =  true;
if (((fn->isBinding==false)&&(strHasPrefix(fn->name,"__Bah_eval_")==false))) {
makeEvalFunc(fn,elems);
}
};
return;
}
if ((len(l)<3)) {
throwErr(&ft,"Invalid usage of keyword {TOKEN}.");
}
if ((((strcmp(ft.cont, "#linux") == 0)||(strcmp(ft.cont, "#windows") == 0))||(strcmp(ft.cont, "#darwin") == 0))) {
struct string isOS =  string(ft.cont);
isOS.trimLeft((struct string*)&isOS,1);
if ((strcmp(isOS.str((struct string*)&isOS), BAH_OS) != 0)) {
return;
}
}
else if ((strcmp(ft.cont, "#static") == 0)) {
if ((flags.isSet((struct flags*)&flags,"d")==1)) {
return;
}
}
else if ((strcmp(ft.cont, "#dynamic") == 0)) {
if ((flags.isSet((struct flags*)&flags,"d")==0)) {
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
if ((flags.isSet((struct flags*)&flags,"l")==0)) {
return;
}
}
else if ((strcmp(ft.cont, "#exec") == 0)) {
if ((flags.isSet((struct flags*)&flags,"l")==1)) {
return;
}
}
else if ((strcmp(ft.cont, "#imported") == 0)) {
if (((isSubObject==false)||(isObject==false))) {
return;
}
}
else if ((strcmp(ft.cont, "#included") == 0)) {
if (((isSubObject==true)||(isObject==true))) {
return;
}
}
else {
throwErr(&ft,"Undefined token {TOKEN}.");
}

                    if (l->length <= 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3540): l[%d] with length %d\n", 1, l->length);
                        exit(1);
                    };
                    struct Tok st =  l->data[1];

                    if (l->length <= len(l)-1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3541): l[%d] with length %d\n", len(l)-1, l->length);
                        exit(1);
                    };
                    struct Tok lt =  l->data[len(l)-1];
if (((strcmp(st.cont, "{") != 0)||(strcmp(lt.cont, "}") != 0))) {
throwErr(&st,"Expected code block after keyword {TOKEN}.");
}
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
long int i =  2;
while ((i<len(l) - 1)) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3548): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    
{
long nLength = i-2;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[i-2] =  l->data[i];
nl->length = nLength+1;
} else {
nl->data[i-2] =  l->data[i];
}
};
i =  i + 1;
};
parseLines(nl,elems);
};
void parseAsync(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
if ((len(l)!=2)) {

                    if (l->length <= 0) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3558): l[%d] with length %d\n", 0, l->length);
                        exit(1);
                    };
                    struct Tok ft =  l->data[0];
throwErr(&ft,"Cannot use keyword {TOKEN} on a function call 'async <function call>'.");
}

                    if (l->length <= 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3561): l[%d] with length %d\n", 1, l->length);
                        exit(1);
                    };
                    struct Tok fnT =  l->data[1];
if ((fnT.isFunc==false)) {
throwErr(&fnT,"Cannot use keyword async on {TOKEN}. Usage: 'async <function call>'.");
}
char found =  false;
long int i =  0;
while ((i<len(compilerState.cLibs))) {

                    if (compilerState.cLibs->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3568): compilerState.cLibs[%d] with length %d\n", i, compilerState.cLibs->length);
                        exit(1);
                    };
                    if ((strcmp(compilerState.cLibs->data[i], "lpthread") == 0)) {
found =  true;
break;
}
i =  i + 1;
};
if ((found==false)) {

{
long nLength = len(compilerState.cLibs);
if (compilerState.cLibs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(compilerState.cLibs->data, (nLength+50)*sizeof(char *));
compilerState.cLibs->data = newPtr;
}
compilerState.cLibs->data[len(compilerState.cLibs)] =  "lpthread";
compilerState.cLibs->length = nLength+1;
} else {
compilerState.cLibs->data[len(compilerState.cLibs)] =  "lpthread";
}
};
}
struct string sFnT =  string(fnT.cont);
array(struct string)* fnNameParts =  splitString(sFnT,"(");

                    if (fnNameParts->length <= 0) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3581): fnNameParts[%d] with length %d\n", 0, fnNameParts->length);
                        exit(1);
                    };
                    struct string fnName =  fnNameParts->data[0];
char * ____BAH_COMPILER_VAR_700 =fnName.str((struct string*)&fnName);struct func* fn =  searchFunc(____BAH_COMPILER_VAR_700,elems,true);
if ((fn==null)) {
char * ____BAH_COMPILER_VAR_701 =fnName.str((struct string*)&fnName);char * ____BAH_COMPILER_VAR_702 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Internal compiler error.\n Error parsing async call for function '");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_701);
long int strLen_2 = strlen("', arround {TOKEN}.");
;                            
                    ____BAH_COMPILER_VAR_702 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_702+currStrOff, "Internal compiler error.\n Error parsing async call for function '", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_702+currStrOff, ____BAH_COMPILER_VAR_701, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_702+currStrOff, "', arround {TOKEN}.", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_702[currStrOff] = 0;
                }
                throwErr(&fnT,____BAH_COMPILER_VAR_702);
}
char * sMembs =  "";
char * unSerMembs =  "";
i =  0;
while ((i<len(fn->args))) {

                    if (fn->args->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3592): fn->args[%d] with length %d\n", i, fn->args->length);
                        exit(1);
                    };
                    struct variable* a =  fn->args->data[i];
struct string cType =  getCType(a->type,elems);
char * ____BAH_COMPILER_VAR_703 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_704 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(sMembs);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_703);
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(a->name);
long int strLen_4 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_704 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_704+currStrOff, sMembs, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_704+currStrOff, ____BAH_COMPILER_VAR_703, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_704+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_704+currStrOff, a->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_704+currStrOff, ";\n", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_704[currStrOff] = 0;
                }
                sMembs =  ____BAH_COMPILER_VAR_704;
char * ____BAH_COMPILER_VAR_705 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(unSerMembs);
long int strLen_1 = strlen("args->");
long int strLen_2 = strlen(a->name);
;                            
                    ____BAH_COMPILER_VAR_705 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_705+currStrOff, unSerMembs, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_705+currStrOff, "args->", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_705+currStrOff, a->name, strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_705[currStrOff] = 0;
                }
                unSerMembs =  ____BAH_COMPILER_VAR_705;
i =  i + 1;
if ((i<len(fn->args))) {
char * ____BAH_COMPILER_VAR_706 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(unSerMembs);
long int strLen_1 = strlen(", ");
;                            
                    ____BAH_COMPILER_VAR_706 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_706+currStrOff, unSerMembs, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_706+currStrOff, ", ", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_706[currStrOff] = 0;
                }
                unSerMembs =  ____BAH_COMPILER_VAR_706;
}
};
char * ____BAH_COMPILER_VAR_707 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("struct {\n");
long int strLen_1 = strlen(sMembs);
long int strLen_2 = strlen("}");
;                            
                    ____BAH_COMPILER_VAR_707 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_707+currStrOff, "struct {\n", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_707+currStrOff, sMembs, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_707+currStrOff, "}", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_707[currStrOff] = 0;
                }
                char * tmpArgsStruct =  ____BAH_COMPILER_VAR_707;
char * fnWrapper =  genCompilerVar();
char * tmpArgs =  genCompilerVar();
sFnT.trimLeft((struct string*)&sFnT,fnName.length + 1);
sFnT.trimRight((struct string*)&sFnT,1);
char * tCreate =  "";
if ((strcmp(BAH_OS, "windows") == 0)) {
tCreate =  "pthread_create";
}
else {
if (RCPavailable()) {
tCreate =  "pthread_create";
}
else {
tCreate =  "GC_pthread_create";
}
}
char * ____BAH_COMPILER_VAR_708 =fnName.str((struct string*)&fnName);char * ____BAH_COMPILER_VAR_709 =sFnT.str((struct string*)&sFnT);char * ____BAH_COMPILER_VAR_710 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n    void ");
long int strLen_1 = strlen(fnWrapper);
long int strLen_2 = strlen("(");
long int strLen_3 = strlen(tmpArgsStruct);
long int strLen_4 = strlen("* args) {\n        ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_708);
long int strLen_6 = strlen("(");
long int strLen_7 = strlen(unSerMembs);
long int strLen_8 = strlen(");\n    };\n    {\n        ");
long int strLen_9 = strlen(tmpArgsStruct);
long int strLen_10 = strlen(" ");
long int strLen_11 = strlen(tmpArgs);
long int strLen_12 = strlen(" = {");
long int strLen_13 = strlen(____BAH_COMPILER_VAR_709);
long int strLen_14 = strlen("};\n        pthread_t id;\n        ");
long int strLen_15 = strlen(tCreate);
long int strLen_16 = strlen("(&id, 0, ");
long int strLen_17 = strlen(fnWrapper);
long int strLen_18 = strlen(", &");
long int strLen_19 = strlen(tmpArgs);
long int strLen_20 = strlen(");\n    }; \n    \n    ");
;                            
                    ____BAH_COMPILER_VAR_710 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14 + strLen_15 + strLen_16 + strLen_17 + strLen_18 + strLen_19 + strLen_20);
                    
                    memcpy(____BAH_COMPILER_VAR_710+currStrOff, "\n    void ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_710+currStrOff, fnWrapper, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_710+currStrOff, "(", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_710+currStrOff, tmpArgsStruct, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_710+currStrOff, "* args) {\n        ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_710+currStrOff, ____BAH_COMPILER_VAR_708, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_710+currStrOff, "(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_710+currStrOff, unSerMembs, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_710+currStrOff, ");\n    };\n    {\n        ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_710+currStrOff, tmpArgsStruct, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_710+currStrOff, " ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_710+currStrOff, tmpArgs, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_710+currStrOff, " = {", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_710+currStrOff, ____BAH_COMPILER_VAR_709, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_710+currStrOff, "};\n        pthread_t id;\n        ", strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_710+currStrOff, tCreate, strLen_15);
                    currStrOff += strLen_15;
                    
                    memcpy(____BAH_COMPILER_VAR_710+currStrOff, "(&id, 0, ", strLen_16);
                    currStrOff += strLen_16;
                    
                    memcpy(____BAH_COMPILER_VAR_710+currStrOff, fnWrapper, strLen_17);
                    currStrOff += strLen_17;
                    
                    memcpy(____BAH_COMPILER_VAR_710+currStrOff, ", &", strLen_18);
                    currStrOff += strLen_18;
                    
                    memcpy(____BAH_COMPILER_VAR_710+currStrOff, tmpArgs, strLen_19);
                    currStrOff += strLen_19;
                    
                    memcpy(____BAH_COMPILER_VAR_710+currStrOff, ");\n    }; \n    \n    ", strLen_20);
                    currStrOff += strLen_20;
                    
                    ____BAH_COMPILER_VAR_710[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_710));
};
void addRCPvars(__BAH_ARR_TYPE_Tok l,lineType ltp,struct Elems* elems){
long int i =  0;
if ((ltp==LINE_TYPE_VAR)) {
i =  1;
}
while ((i<len(l))) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3639): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    struct Tok t =  l->data[i];
if ((t.type==TOKEN_TYPE_VAR)) {
struct variable* v =  searchVar(t.cont,elems);
if ((v!=null)) {

{
long nLength = len(compilerState.RCPvars);
if (compilerState.RCPvars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(compilerState.RCPvars->data, (nLength+50)*sizeof(struct variable*));
compilerState.RCPvars->data = newPtr;
}
compilerState.RCPvars->data[len(compilerState.RCPvars)] =  v;
compilerState.RCPvars->length = nLength+1;
} else {
compilerState.RCPvars->data[len(compilerState.RCPvars)] =  v;
}
};
}
}
i =  i + 1;
};
};
__BAH_ARR_TYPE_Tok parseChan(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
long int i =  0;
for (; (i<len(l)); i =  i+1) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3655): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    struct Tok t =  l->data[i];
if ((((t.type==TOKEN_TYPE_SYNTAX)&&(strcmp(t.cont, "->") == 0))||(strcmp(t.cont, "<-") == 0))) {
if ((strcmp(t.cont, "<-") == 0)) {
i =  i+1;
if ((i<len(l))) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3661): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    struct Tok nt =  l->data[i];
if ((nt.type!=TOKEN_TYPE_VAR)) {
throwErr(&nt,"Cannot use {TOKEN} as channel.");
}
char * ____BAH_COMPILER_VAR_711 =getTypeFromToken(&nt,true,elems);struct string ntt =  string(____BAH_COMPILER_VAR_711);
if ((ntt.hasPrefix((struct string*)&ntt,"chan:")==0)) {
char * ____BAH_COMPILER_VAR_712 =ntt.str((struct string*)&ntt);char * ____BAH_COMPILER_VAR_713 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot use var {TOKEN} (");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_712);
long int strLen_2 = strlen(") as channel.");
;                            
                    ____BAH_COMPILER_VAR_713 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_713+currStrOff, "Cannot use var {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_713+currStrOff, ____BAH_COMPILER_VAR_712, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_713+currStrOff, ") as channel.", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_713[currStrOff] = 0;
                }
                throwErr(&nt,____BAH_COMPILER_VAR_713);
}
ntt.trimLeft((struct string*)&ntt,5);
if (isGlobal()) {
throwErr(&t,"Cannot receive ({TOKEN}) from a channel outside of a function.");
}
char * tmpV =  "";
char * ____BAH_COMPILER_VAR_714 =ntt.str((struct string*)&ntt);if (isRCPpointerType(____BAH_COMPILER_VAR_714)) {
char * ____BAH_COMPILER_VAR_715 =ntt.str((struct string*)&ntt);struct string ct =  getCType(____BAH_COMPILER_VAR_715,elems);
char * ____BAH_COMPILER_VAR_716 =ct.str((struct string*)&ct);char * ____BAH_COMPILER_VAR_717 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("(");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_716);
long int strLen_2 = strlen(")");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen("->receive(");
long int strLen_5 = strlen(nt.cont);
long int strLen_6 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_717 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                    
                    memcpy(____BAH_COMPILER_VAR_717+currStrOff, "(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_717+currStrOff, ____BAH_COMPILER_VAR_716, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_717+currStrOff, ")", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_717+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_717+currStrOff, "->receive(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_717+currStrOff, nt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_717+currStrOff, ")", strLen_6);
                    currStrOff += strLen_6;
                    
                    ____BAH_COMPILER_VAR_717[currStrOff] = 0;
                }
                t.cont =  ____BAH_COMPILER_VAR_717;
}
else {
char * ____BAH_COMPILER_VAR_718 =ntt.str((struct string*)&ntt);struct string ct =  getCType(____BAH_COMPILER_VAR_718,elems);
if (RCPavailable()) {
char * ____BAH_COMPILER_VAR_719 =ntt.str((struct string*)&ntt);char * ____BAH_COMPILER_VAR_720 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_719);
long int strLen_1 = strlen("*");
;                            
                    ____BAH_COMPILER_VAR_720 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_720+currStrOff, ____BAH_COMPILER_VAR_719, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_720+currStrOff, "*", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_720[currStrOff] = 0;
                }
                char * ____BAH_COMPILER_VAR_721 =ct.str((struct string*)&ct);char * ____BAH_COMPILER_VAR_722 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("(");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_721);
long int strLen_2 = strlen("*)");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen("->receive(");
long int strLen_5 = strlen(nt.cont);
long int strLen_6 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_722 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                    
                    memcpy(____BAH_COMPILER_VAR_722+currStrOff, "(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_722+currStrOff, ____BAH_COMPILER_VAR_721, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_722+currStrOff, "*)", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_722+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_722+currStrOff, "->receive(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_722+currStrOff, nt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_722+currStrOff, ")", strLen_6);
                    currStrOff += strLen_6;
                    
                    ____BAH_COMPILER_VAR_722[currStrOff] = 0;
                }
                tmpV =  registerRCPvar(____BAH_COMPILER_VAR_720,____BAH_COMPILER_VAR_722,elems);
char * ____BAH_COMPILER_VAR_723 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("*");
long int strLen_1 = strlen(tmpV);
;                            
                    ____BAH_COMPILER_VAR_723 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_723+currStrOff, "*", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_723+currStrOff, tmpV, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_723[currStrOff] = 0;
                }
                t.cont =  ____BAH_COMPILER_VAR_723;
}
else {
char * ____BAH_COMPILER_VAR_724 =ct.str((struct string*)&ct);char * ____BAH_COMPILER_VAR_725 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("*(");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_724);
long int strLen_2 = strlen("*)");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen("->receive(");
long int strLen_5 = strlen(nt.cont);
long int strLen_6 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_725 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                    
                    memcpy(____BAH_COMPILER_VAR_725+currStrOff, "*(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_725+currStrOff, ____BAH_COMPILER_VAR_724, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_725+currStrOff, "*)", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_725+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_725+currStrOff, "->receive(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_725+currStrOff, nt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_725+currStrOff, ")", strLen_6);
                    currStrOff += strLen_6;
                    
                    ____BAH_COMPILER_VAR_725[currStrOff] = 0;
                }
                t.cont =  ____BAH_COMPILER_VAR_725;
}
}
t.type =  TOKEN_TYPE_FUNC;
t.isFunc =  true;
if (RCPavailable()) {
char * ____BAH_COMPILER_VAR_726 =ntt.str((struct string*)&ntt);if (isRCPpointerType(____BAH_COMPILER_VAR_726)) {
char * ____BAH_COMPILER_VAR_727 =ntt.str((struct string*)&ntt);tmpV =  registerRCPvar(____BAH_COMPILER_VAR_727,t.cont,elems);
t.type =  TOKEN_TYPE_VAR;
t.isFunc =  false;
t.cont =  tmpV;
}
else {
}
}
t.isValue =  true;
t.bahType =  ntt.str((struct string*)&ntt);
}
else {
throwErr(&t,"Cannot use {TOKEN} on nothing");
}
}
else {
if ((i==0)) {
throwErr(&t,"Cannot une {TOKEN} on nothing.");
}
if ((i + 1>=len(l))) {
throwErr(&t,"Cannot send ({TOKEN}) to nothing.");
}

                    if (l->length <= i + 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3715): l[%d] with length %d\n", i + 1, l->length);
                        exit(1);
                    };
                    struct Tok pt =  l->data[i + 1];

                    if (l->length <= i-1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3716): l[%d] with length %d\n", i-1, l->length);
                        exit(1);
                    };
                    struct Tok nt =  l->data[i-1];
char * ntt =  getTypeFromToken(&nt,true,elems);
if ((pt.type!=TOKEN_TYPE_VAR)) {
throwErr(&pt,"Cannot use {TOKEN} as channel.");
}
char * ____BAH_COMPILER_VAR_728 =getTypeFromToken(&pt,true,elems);struct string ptt =  string(____BAH_COMPILER_VAR_728);
if ((ptt.hasPrefix((struct string*)&ptt,"chan:")==0)) {
char * ____BAH_COMPILER_VAR_729 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot use var {TOKEN} (");
long int strLen_1 = strlen(ntt);
long int strLen_2 = strlen(") as channel.");
;                            
                    ____BAH_COMPILER_VAR_729 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_729+currStrOff, "Cannot use var {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_729+currStrOff, ntt, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_729+currStrOff, ") as channel.", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_729[currStrOff] = 0;
                }
                throwErr(&pt,____BAH_COMPILER_VAR_729);
}
ptt.trimLeft((struct string*)&ptt,5);
if (isGlobal()) {
throwErr(&t,"Cannot send ({TOKEN}) to a channel outside of a function.");
}
char * ____BAH_COMPILER_VAR_730 =ptt.str((struct string*)&ptt);if ((compTypes(____BAH_COMPILER_VAR_730,ntt)==false)) {
char * ____BAH_COMPILER_VAR_731 =ptt.str((struct string*)&ptt);char * ____BAH_COMPILER_VAR_732 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot send {TOKEN} (");
long int strLen_1 = strlen(ntt);
long int strLen_2 = strlen(") to channel of type ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_731);
long int strLen_4 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_732 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_732+currStrOff, "Cannot send {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_732+currStrOff, ntt, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_732+currStrOff, ") to channel of type ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_732+currStrOff, ____BAH_COMPILER_VAR_731, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_732+currStrOff, ".", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_732[currStrOff] = 0;
                }
                throwErr(&nt,____BAH_COMPILER_VAR_732);
}
i =  i+1;
char * ____BAH_COMPILER_VAR_733 =ptt.str((struct string*)&ptt);if (isRCPpointerType(____BAH_COMPILER_VAR_733)) {
char * ____BAH_COMPILER_VAR_734 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen("->send(");
long int strLen_2 = strlen(pt.cont);
long int strLen_3 = strlen(", ");
long int strLen_4 = strlen(nt.cont);
long int strLen_5 = strlen(");\n");
;                            
                    ____BAH_COMPILER_VAR_734 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    memcpy(____BAH_COMPILER_VAR_734+currStrOff, pt.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_734+currStrOff, "->send(", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_734+currStrOff, pt.cont, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_734+currStrOff, ", ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_734+currStrOff, nt.cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_734+currStrOff, ");\n", strLen_5);
                    currStrOff += strLen_5;
                    
                    ____BAH_COMPILER_VAR_734[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_734));
}
else {
struct string ct =  getCType(ntt,elems);
char * tmpV =  genCompilerVar();
char * ____BAH_COMPILER_VAR_735 =ct.str((struct string*)&ct);char * ____BAH_COMPILER_VAR_736 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n                    ");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_735);
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(tmpV);
long int strLen_4 = strlen(" = ");
long int strLen_5 = strlen(nt.cont);
long int strLen_6 = strlen(";\n                    ");
long int strLen_7 = strlen(pt.cont);
long int strLen_8 = strlen("->sendAny(");
long int strLen_9 = strlen(pt.cont);
long int strLen_10 = strlen(", &");
long int strLen_11 = strlen(tmpV);
long int strLen_12 = strlen(", sizeof(");
long int strLen_13 = strlen(tmpV);
long int strLen_14 = strlen("));\n");
;                            
                    ____BAH_COMPILER_VAR_736 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14);
                    
                    memcpy(____BAH_COMPILER_VAR_736+currStrOff, "\n                    ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_736+currStrOff, ____BAH_COMPILER_VAR_735, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_736+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_736+currStrOff, tmpV, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_736+currStrOff, " = ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_736+currStrOff, nt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_736+currStrOff, ";\n                    ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_736+currStrOff, pt.cont, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_736+currStrOff, "->sendAny(", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_736+currStrOff, pt.cont, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_736+currStrOff, ", &", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_736+currStrOff, tmpV, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_736+currStrOff, ", sizeof(", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_736+currStrOff, tmpV, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_736+currStrOff, "));\n", strLen_14);
                    currStrOff += strLen_14;
                    
                    ____BAH_COMPILER_VAR_736[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_736));
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
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
}
};
};
return nl;
};
__BAH_ARR_TYPE_Tok prePross(__BAH_ARR_TYPE_Tok line,lineType ltp,struct Elems* elems){
array(struct Tok)* fl = memoryAlloc(sizeof(array(struct Tok)));

fl->length = 0;
fl->elemSize = sizeof(struct Tok);
long int i =  0;
long int nbPar =  0;
if ((ltp!=(lineType)-1)) {
while ((i<len(line))) {

                    if (line->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3763): line[%d] with length %d\n", i, line->length);
                        exit(1);
                    };
                    struct Tok t =  line->data[i];
if ((strcmp(t.cont, "(") == 0)) {
nbPar =  nbPar + 1;
}
else if ((strcmp(t.cont, ")") == 0)) {
nbPar =  nbPar - 1;
}
else if (((nbPar==0)&&(strcmp(t.cont, "{") == 0))) {

                    if (line->length <= i + 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3769): line[%d] with length %d\n", i + 1, line->length);
                        exit(1);
                    };
                    struct Tok nt =  line->data[i + 1];
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
fl->data[len(fl)] =  t;
fl->length = nLength+1;
} else {
fl->data[len(fl)] =  t;
}
};
i =  i+1;
};
}
else {
fl =  line;
}
fl =  parseStructVars(fl,elems);
fl =  parseFnCall(fl,ltp,elems);
fl =  parseArrayVars(fl,ltp,elems);
fl =  parseArrayType(fl,elems);
fl =  parseStructType(fl,ltp,elems);
fl =  parseCast(fl,elems);
addRCPvars(fl,ltp,elems);
fl =  parseOperations(fl,ltp,elems);
fl =  parseBool(fl,elems);
fl =  parseChan(fl,elems);
if ((ltp!=(lineType)-1)) {
while ((i<len(line))) {

                    if (line->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3794): line[%d] with length %d\n", i, line->length);
                        exit(1);
                    };
                    
{
long nLength = len(fl);
if (fl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(fl->data, (nLength+50)*sizeof(struct Tok));
fl->data = newPtr;
}
fl->data[len(fl)] =  line->data[i];
fl->length = nLength+1;
} else {
fl->data[len(fl)] =  line->data[i];
}
};
i =  i+1;
};
}
return fl;
};
void parseFnDeclare(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
long int i =  0;
struct func* ____BAH_COMPILER_VAR_737 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_737->name = "";
____BAH_COMPILER_VAR_737->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_737->args->length = 0;
            ____BAH_COMPILER_VAR_737->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_737->returns= null;
____BAH_COMPILER_VAR_737->isBinding = false;
____BAH_COMPILER_VAR_737->from = "";
____BAH_COMPILER_VAR_737->file = "";
____BAH_COMPILER_VAR_737->line = 1;
____BAH_COMPILER_VAR_737->used = false;
____BAH_COMPILER_VAR_737->code = null;
struct func* fn =  ____BAH_COMPILER_VAR_737;
if (((RCPavailable()==false)&&(RCPenabled==true))) {
fn->used =  true;
}

                    if (l->length <= 0) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3811): l[%d] with length %d\n", 0, l->length);
                        exit(1);
                    };
                    struct Tok ft =  l->data[0];
char * code =  parseFnHeader("",l,&i,fn,elems);
fn->line =  ft.line;
fn->file =  compilerState.currentFile;
struct func* ogFn =  searchFunc(fn->name,elems,false);
if ((ogFn!=null)) {
if ((ogFn->isBinding==false)) {
char * lineStr =  intToStr(ogFn->line);
char * ____BAH_COMPILER_VAR_738 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot redeclare function {TOKEN}, previous declaration: ");
long int strLen_1 = strlen(ogFn->file);
long int strLen_2 = strlen(":");
long int strLen_3 = strlen(lineStr);
long int strLen_4 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_738 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_738+currStrOff, "Cannot redeclare function {TOKEN}, previous declaration: ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_738+currStrOff, ogFn->file, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_738+currStrOff, ":", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_738+currStrOff, lineStr, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_738+currStrOff, ".", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_738[currStrOff] = 0;
                }
                throwErr(&ft,____BAH_COMPILER_VAR_738);
}
}
if ((strcmp(fn->name, "main") == 0)) {
compilerState.haveEntryPoint =  true;
if ((compTypes(fn->returns->type,"int")==false)) {
throwErr(&ft,"{TOKEN} function should return 'int'.");
}
if ((len(fn->args)!=1)) {
throwErr(&ft,"{TOKEN} function should take one []cpstring argument. Should be: \n            'main(args []cpstring) int'");
}

                    if (fn->args->length <= 0) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3832): fn->args[%d] with length %d\n", 0, fn->args->length);
                        exit(1);
                    };
                    struct variable* fa =  fn->args->data[0];
if ((compTypes(fa->type,"[]cpstring")==false)) {
throwErr(&ft,"{TOKEN} function should take []cpstring as argument. Should be: \n            'main(args []cpstring) int'");
}
}
if ((shouldOnlyDecl==true)) {
if ((ogFn!=null)) {
fn->isBinding =  false;
}

{
long nLength = len(elems->fns);
if (elems->fns->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(elems->fns->data, (nLength+50)*sizeof(struct func*));
elems->fns->data = newPtr;
}
elems->fns->data[len(elems->fns)] =  fn;
elems->fns->length = nLength+1;
} else {
elems->fns->data[len(elems->fns)] =  fn;
}
};
char * ____BAH_COMPILER_VAR_739 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_739 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_739+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_739+currStrOff, ";\n", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_739[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_739));
return;
}
char * ____BAH_COMPILER_VAR_740 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen("{\n");
;                            
                    ____BAH_COMPILER_VAR_740 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_740+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_740+currStrOff, "{\n", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_740[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_740;
fn->code =  rope(code);
struct Elems* fnElems =  dupElems(elems);
array(struct variable*)* vs =  fnElems->vars;
long int j =  0;
while ((j<len(fn->args))) {

                    if (fn->args->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3857): fn->args[%d] with length %d\n", j, fn->args->length);
                        exit(1);
                    };
                    struct variable* a =  fn->args->data[j];
a->outterScope =  true;

{
long nLength = len(vs);
if (vs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(vs->data, (nLength+50)*sizeof(struct variable*));
vs->data = newPtr;
}
vs->data[len(vs)] =  a;
vs->length = nLength+1;
} else {
vs->data[len(vs)] =  a;
}
};
j =  j + 1;
};
fnElems->vars =  vs;
if ((ogFn!=null)) {
ogFn->isBinding =  false;
ogFn->used =  true;
ogFn =  fn;
}
else {
array(struct func*)* fns =  elems->fns;

{
long nLength = len(fns);
if (fns->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(fns->data, (nLength+50)*sizeof(struct func*));
fns->data = newPtr;
}
fns->data[len(fns)] =  fn;
fns->length = nLength+1;
} else {
fns->data[len(fns)] =  fn;
}
};
}
array(struct Tok)* tokens = memoryAlloc(sizeof(array(struct Tok)));

tokens->length = 0;
tokens->elemSize = sizeof(struct Tok);
i =  i+1;
long int max =  len(l)-1;
while ((i<max)) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3877): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    struct Tok t =  l->data[i];

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] =  t;
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] =  t;
}
};
i =  i+1;
};
if ((len(tokens)==0)) {
fn->code =  fn->code->add(fn->code, rope("};\n"));
OUTPUT =  OUTPUT->add(OUTPUT, fn->code);
return;
}
currentFn =  fn;
struct rope* oOut =  OUTPUT;
OUTPUT =  rope("");
parseLines(tokens,fnElems);
currentFn =  null;
if ((fn->returned==false)) {
if ((strlen(fn->returns->type)>0)) {
char * ____BAH_COMPILER_VAR_741 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Function '");
long int strLen_1 = strlen(fn->name);
long int strLen_2 = strlen("' is not returned.");
;                            
                    ____BAH_COMPILER_VAR_741 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_741+currStrOff, "Function '", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_741+currStrOff, fn->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_741+currStrOff, "' is not returned.", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_741[currStrOff] = 0;
                }
                throwErr(&l->data[len(l)-1],____BAH_COMPILER_VAR_741);
}
endRCPscope(fnElems,null);
}
fn->code =  fn->code->add(fn->code, OUTPUT);
OUTPUT =  oOut;
fn->code =  fn->code->add(fn->code, rope("};\n"));
OUTPUT =  OUTPUT->add(OUTPUT, fn->code);
if ((debug==true)) {
struct debugFunction* ____BAH_COMPILER_VAR_742 = memoryAlloc(sizeof(struct debugFunction));
____BAH_COMPILER_VAR_742->name= null;
____BAH_COMPILER_VAR_742->returns= null;
____BAH_COMPILER_VAR_742->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_742->args->length = 0;
            ____BAH_COMPILER_VAR_742->args->elemSize = sizeof(struct variable*);
            struct debugFunction* df =  ____BAH_COMPILER_VAR_742;
df->name =  fn->name;
df->args =  fn->args;
df->returns =  fn->returns->type;
struct debugFunction* ____BAH_COMPILER_VAR_743 = df;
char ** ____BAH_COMPILER_VAR_745 = (char **)((char*)(____BAH_COMPILER_VAR_743) + offsetof(struct debugFunction, name));
struct reflectElement ____BAH_COMPILER_VAR_746 = __reflect(____BAH_COMPILER_VAR_745, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct debugFunction, name));
char ** ____BAH_COMPILER_VAR_747 = (char **)((char*)(____BAH_COMPILER_VAR_743) + offsetof(struct debugFunction, returns));
struct reflectElement ____BAH_COMPILER_VAR_748 = __reflect(____BAH_COMPILER_VAR_747, sizeof(char *), "cpstring", "returns", 0, 0, 0, 0, offsetof(struct debugFunction, returns));
array(struct variable*)** ____BAH_COMPILER_VAR_749 = (array(struct variable*)**)((char*)(____BAH_COMPILER_VAR_743) + offsetof(struct debugFunction, args));
struct variable** ____BAH_COMPILER_VAR_750 = 0;
char ** ____BAH_COMPILER_VAR_752 = (char **)((char*)(____BAH_COMPILER_VAR_750) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_753 = __reflect(____BAH_COMPILER_VAR_752, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_754 = (char **)((char*)(____BAH_COMPILER_VAR_750) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_755 = __reflect(____BAH_COMPILER_VAR_754, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_756 = (char*)((char*)(____BAH_COMPILER_VAR_750) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_757 = __reflect(____BAH_COMPILER_VAR_756, sizeof(char), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_758 = (char **)((char*)(____BAH_COMPILER_VAR_750) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_759 = __reflect(____BAH_COMPILER_VAR_758, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_760 = (char*)((char*)(____BAH_COMPILER_VAR_750) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_761 = __reflect(____BAH_COMPILER_VAR_760, sizeof(char), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_762 = (char **)((char*)(____BAH_COMPILER_VAR_750) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_763 = __reflect(____BAH_COMPILER_VAR_762, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
char* ____BAH_COMPILER_VAR_764 = (char*)((char*)(____BAH_COMPILER_VAR_750) + offsetof(struct variable, outterScope));
struct reflectElement ____BAH_COMPILER_VAR_765 = __reflect(____BAH_COMPILER_VAR_764, sizeof(char), "bool", "outterScope", 0, 0, 0, 0, offsetof(struct variable, outterScope));
char* ____BAH_COMPILER_VAR_766 = (char*)((char*)(____BAH_COMPILER_VAR_750) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_767 = __reflect(____BAH_COMPILER_VAR_766, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_751 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_751->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_751->length = 8;
        ____BAH_COMPILER_VAR_751->data = memoryAlloc(____BAH_COMPILER_VAR_751->length * ____BAH_COMPILER_VAR_751->elemSize);
        ____BAH_COMPILER_VAR_751->data[0] = ____BAH_COMPILER_VAR_753;
____BAH_COMPILER_VAR_751->data[1] = ____BAH_COMPILER_VAR_755;
____BAH_COMPILER_VAR_751->data[2] = ____BAH_COMPILER_VAR_757;
____BAH_COMPILER_VAR_751->data[3] = ____BAH_COMPILER_VAR_759;
____BAH_COMPILER_VAR_751->data[4] = ____BAH_COMPILER_VAR_761;
____BAH_COMPILER_VAR_751->data[5] = ____BAH_COMPILER_VAR_763;
____BAH_COMPILER_VAR_751->data[6] = ____BAH_COMPILER_VAR_765;
____BAH_COMPILER_VAR_751->data[7] = ____BAH_COMPILER_VAR_767;
struct reflectElement ____BAH_COMPILER_VAR_768 = __reflect(____BAH_COMPILER_VAR_750, sizeof(struct variable), "variable*", "", 0, 0, 1, ____BAH_COMPILER_VAR_751, 0);

        struct reflectElement ____BAH_COMPILER_VAR_769 = ____BAH_COMPILER_VAR_768;
        struct reflectElement ____BAH_COMPILER_VAR_770 = __reflect(____BAH_COMPILER_VAR_749, sizeof(array(struct variable*)*), "[]variable*", "args", 1, &____BAH_COMPILER_VAR_769, 0, 0, offsetof(struct debugFunction, args));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_744 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_744->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_744->length = 3;
        ____BAH_COMPILER_VAR_744->data = memoryAlloc(____BAH_COMPILER_VAR_744->length * ____BAH_COMPILER_VAR_744->elemSize);
        ____BAH_COMPILER_VAR_744->data[0] = ____BAH_COMPILER_VAR_746;
____BAH_COMPILER_VAR_744->data[1] = ____BAH_COMPILER_VAR_748;
____BAH_COMPILER_VAR_744->data[2] = ____BAH_COMPILER_VAR_770;
struct reflectElement ____BAH_COMPILER_VAR_771 = __reflect(____BAH_COMPILER_VAR_743, sizeof(struct debugFunction), "debugFunction*", "df", 0, 0, 1, ____BAH_COMPILER_VAR_744, 0);
debugPrint("fn_declare",ft.line,____BAH_COMPILER_VAR_771);

                    if (l->length <= len(l)-1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3917): l[%d] with length %d\n", len(l)-1, l->length);
                        exit(1);
                    };
                    struct Tok lt =  l->data[len(l)-1];
debugEndScope(lt.line,fnElems);
}
};
void parseLine(__BAH_ARR_TYPE_Tok line,struct Elems* elems){
if ((len(line)==0)) {
return;
}
line =  parsePointers(line);
lineType ltp =  getLineType(line);
compilerState.RCPvars = memoryAlloc(sizeof(array(struct variable*)));

compilerState.RCPvars->length = 0;
compilerState.RCPvars->elemSize = sizeof(struct variable*);
char parsed =  false;
if ((ltp==LINE_TYPE_INCLUDE)) {
parsed =  true;
parseInclude(line,elems);
}
else if ((ltp==LINE_TYPE_IMPORT)) {
parsed =  true;
parseImport(line,elems);
}
else if ((ltp==LINE_TYPE_DEFINE)) {
parsed =  true;
parseDefine(line,elems);
}
else if ((ltp==LINE_TYPE_CLIB)) {
parsed =  true;
parseClib(line);
}
else if ((ltp==LINE_TYPE_STRUCT)) {
parsed =  true;
parseStruct(line,elems);
}
else if ((ltp==LINE_TYPE_CONST)) {
parsed =  true;
parseConst(line,elems);
}
else if ((ltp==LINE_TYPE_MACRO)) {
return;
}
else if ((ltp!=LINE_TYPE_FN_DECL)) {
line =  prePross(line,ltp,elems);
if ((len(line)==0)) {
return;
}
}
if ((ltp==LINE_TYPE_VAR)) {
parsed =  true;
parseVar(line,elems);
}
else if ((ltp==LINE_TYPE_FN_CALL)) {
if ((len(line)>1)) {
throwErr(&line->data[len(line)-1],"Not expecting {TOKEN} after function call.");
}

                    if (line->length <= 0) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3971): line[%d] with length %d\n", 0, line->length);
                        exit(1);
                    };
                    struct Tok ft =  line->data[0];
parsed =  true;
char * ____BAH_COMPILER_VAR_772 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ft.cont);
long int strLen_1 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_772 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_772+currStrOff, ft.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_772+currStrOff, ";\n", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_772[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_772));
}
else if ((ltp==LINE_TYPE_FN_DECL)) {
parsed =  true;
parseFnDeclare(line,elems);
}
else if ((ltp==LINE_TYPE_RETURN)) {
parsed =  true;
parseReturn(line,elems);
}
else if ((ltp==LINE_TYPE_IF)) {
parsed =  true;
parseIf(line,elems);
}
else if ((ltp==LINE_TYPE_ELSE)) {
parsed =  true;
parseElse(line,elems);
}
else if ((ltp==LINE_TYPE_FOR)) {
parsed =  true;
parseFor(line,elems);
}
else if ((ltp==LINE_TYPE_FOR_OPERATOR)) {
parsed =  true;
parseForOp(line,elems);
}
else if ((ltp==LINE_TYPE_PRE_KEYWORD)) {
parsePreKeyword(line,elems);
parsed =  true;
}
else if ((ltp==LINE_TYPE_ASYNC)) {
parseAsync(line,elems);
parsed =  true;
}
if ((parsed==false)) {

                    if (line->length <= 0) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:4001): line[%d] with length %d\n", 0, line->length);
                        exit(1);
                    };
                    struct Tok ft =  line->data[0];
throwErr(&ft,"{TOKEN} not expected.");
}
if ((strlen(NEXT_LINE)>0)) {
OUTPUT =  OUTPUT->add(OUTPUT, rope(NEXT_LINE));
NEXT_LINE =  "";
}
prevLine =  ltp;
};
void parseLines(__BAH_ARR_TYPE_Tok tokens,struct Elems* elems){
if ((len(tokens)==0)) {
return;
}
array(struct Tok)* line = memoryAlloc(sizeof(array(struct Tok)));

line->length = 0;
line->elemSize = sizeof(struct Tok);

                    if (tokens->length <= 0) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:4020): tokens[%d] with length %d\n", 0, tokens->length);
                        exit(1);
                    };
                    struct Tok ft =  tokens->data[0];
long int currentLine =  ft.line;
long int nbEncl =  0;
long int i =  0;
while ((i<len(tokens))) {

                    if (tokens->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:4024): tokens[%d] with length %d\n", i, tokens->length);
                        exit(1);
                    };
                    struct Tok t =  tokens->data[i];
if ((t.type==TOKEN_TYPE_ENCL)) {
if ((strcmp(t.cont, "(") == 0)) {
nbEncl =  nbEncl + 1;
}
else if ((strcmp(t.cont, ")") == 0)) {
nbEncl =  nbEncl - 1;
}
else if ((strcmp(t.cont, "{") == 0)) {
nbEncl =  nbEncl + 1;
}
else if ((strcmp(t.cont, "}") == 0)) {
nbEncl =  nbEncl - 1;
}
else if ((strcmp(t.cont, "[") == 0)) {
nbEncl =  nbEncl + 1;
}
else if ((strcmp(t.cont, "]") == 0)) {
nbEncl =  nbEncl - 1;
}
}
if (((t.type==TOKEN_TYPE_STR)&&(t.begLine==currentLine))) {
currentLine =  t.line;
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
line->data[len(line)] =  t;
line->length = nLength+1;
} else {
line->data[len(line)] =  t;
}
};

                    if (tokens->length <= i-1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:4050): tokens[%d] with length %d\n", i-1, tokens->length);
                        exit(1);
                    };
                    struct Tok pt =  tokens->data[i-1];
currentLine =  pt.line;
}
else {
currentLine =  t.line;
}
parseLine(line,elems);
clear(line);
if ((t.type==TOKEN_TYPE_ENCL)) {
i =  i+1;
continue;
}
}
else if ((strcmp(t.cont, ";") == 0)) {
currentLine =  t.line;
parseLine(line,elems);
clear(line);
i =  i+1;
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
line->data[len(line)] =  t;
line->length = nLength+1;
} else {
line->data[len(line)] =  t;
}
};
i =  i+1;
};
if ((len(line)>0)) {
if ((nbEncl==0)) {
parseLine(line,elems);
clear(line);
}
else {

                    if (line->length <= len(line)-1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:4079): line[%d] with length %d\n", len(line)-1, line->length);
                        exit(1);
                    };
                    ft =  line->data[len(line)-1];
throwErr(&ft,"Missing closing token, line ending by {TOKEN}.");
}
}
};
void declareFunc(struct func* fn,struct Elems* elems){
struct string tmpfnRetCType =  getCType(fn->returns->type,elems);
char * tmpfnArgsCType =  "";
long int j =  0;
while ((j<len(fn->args))) {

                    if (fn->args->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/declarative.bah:6): fn->args[%d] with length %d\n", j, fn->args->length);
                        exit(1);
                    };
                    struct variable* arg =  fn->args->data[j];
struct string ct =  getCType(arg->type,elems);
char * ____BAH_COMPILER_VAR_773 =ct.str((struct string*)&ct);char * ____BAH_COMPILER_VAR_774 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_773);
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(arg->name);
;                            
                    ____BAH_COMPILER_VAR_774 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                    
                    memcpy(____BAH_COMPILER_VAR_774+currStrOff, tmpfnArgsCType, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_774+currStrOff, ____BAH_COMPILER_VAR_773, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_774+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_774+currStrOff, arg->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    ____BAH_COMPILER_VAR_774[currStrOff] = 0;
                }
                tmpfnArgsCType =  ____BAH_COMPILER_VAR_774;
j =  j + 1;
if ((j<len(fn->args))) {
char * ____BAH_COMPILER_VAR_775 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(", ");
;                            
                    ____BAH_COMPILER_VAR_775 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_775+currStrOff, tmpfnArgsCType, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_775+currStrOff, ", ", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_775[currStrOff] = 0;
                }
                tmpfnArgsCType =  ____BAH_COMPILER_VAR_775;
}
};
char * ____BAH_COMPILER_VAR_776 =tmpfnRetCType.str((struct string*)&tmpfnRetCType);char * ____BAH_COMPILER_VAR_777 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_776);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(fn->name);
long int strLen_3 = strlen("(");
long int strLen_4 = strlen(tmpfnArgsCType);
long int strLen_5 = strlen(");\n");
;                            
                    ____BAH_COMPILER_VAR_777 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    memcpy(____BAH_COMPILER_VAR_777+currStrOff, ____BAH_COMPILER_VAR_776, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_777+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_777+currStrOff, fn->name, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_777+currStrOff, "(", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_777+currStrOff, tmpfnArgsCType, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_777+currStrOff, ");\n", strLen_5);
                    currStrOff += strLen_5;
                    
                    ____BAH_COMPILER_VAR_777[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_777));
};
void declareVar(struct variable* v,struct Elems* elems){
if ((v->isConst==true)) {
char * ____BAH_COMPILER_VAR_778 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("#define ");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(v->constVal);
long int strLen_4 = strlen("\n");
;                            
                    ____BAH_COMPILER_VAR_778 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_778+currStrOff, "#define ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_778+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_778+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_778+currStrOff, v->constVal, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_778+currStrOff, "\n", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_778[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_778));
}
else {
struct string cType =  getCType(v->type,elems);
char * ____BAH_COMPILER_VAR_779 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_780 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_779);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(v->name);
long int strLen_3 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_780 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                    
                    memcpy(____BAH_COMPILER_VAR_780+currStrOff, ____BAH_COMPILER_VAR_779, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_780+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_780+currStrOff, v->name, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_780+currStrOff, ";\n", strLen_3);
                    currStrOff += strLen_3;
                    
                    ____BAH_COMPILER_VAR_780[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_780));
}
};
void declareAll(struct Elems* elems){
OUTPUT =  rope("\n#define noCheck(v) v\n#define array(type)	\
struct{	\
type *data; \
long int length; \
long int elemSize; \
}\ntypedef array(char*)* __BAH_ARR_TYPE_cpstring;\nlong int __BAH__main(__BAH_ARR_TYPE_cpstring);\n");
long int i =  0;
for (; (i<len(compilerState.cIncludes)); i =  i+1) {

                    if (compilerState.cIncludes->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/declarative.bah:42): compilerState.cIncludes[%d] with length %d\n", i, compilerState.cIncludes->length);
                        exit(1);
                    };
                    char * ____BAH_COMPILER_VAR_781 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("#include ");
long int strLen_1 = strlen(compilerState.cIncludes->data[i]);
long int strLen_2 = strlen("\n");
;                            
                    ____BAH_COMPILER_VAR_781 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_781+currStrOff, "#include ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_781+currStrOff, compilerState.cIncludes->data[i], strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_781+currStrOff, "\n", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_781[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_781));
};
i =  1;
for (; (i<len(compilerState.arrTypesDecl)); i =  i+1) {

                    if (compilerState.arrTypesDecl->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/declarative.bah:46): compilerState.arrTypesDecl[%d] with length %d\n", i, compilerState.arrTypesDecl->length);
                        exit(1);
                    };
                    char * t =  compilerState.arrTypesDecl->data[i];
struct string elemType =  string(t);
elemType.trimLeft((struct string*)&elemType,15);
char * ____BAH_COMPILER_VAR_782 =elemType.str((struct string*)&elemType);struct string elemCtype =  getCType(____BAH_COMPILER_VAR_782,elems);
char * ____BAH_COMPILER_VAR_783 =elemCtype.str((struct string*)&elemCtype);char * ____BAH_COMPILER_VAR_784 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("typedef array(");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_783);
long int strLen_2 = strlen(")* ");
long int strLen_3 = strlen(t);
long int strLen_4 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_784 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_784+currStrOff, "typedef array(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_784+currStrOff, ____BAH_COMPILER_VAR_783, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_784+currStrOff, ")* ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_784+currStrOff, t, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_784+currStrOff, ";\n", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_784[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_784));
};
i =  0;
for (; (i<len(elems->vars)); i =  i+1) {

                    if (elems->vars->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/declarative.bah:54): elems->vars[%d] with length %d\n", i, elems->vars->length);
                        exit(1);
                    };
                    struct variable* v =  elems->vars->data[i];
declareVar(v,elems);
};
i =  0;
for (; (i<len(elems->fns)); i =  i+1) {

                    if (elems->fns->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/declarative.bah:59): elems->fns[%d] with length %d\n", i, elems->fns->length);
                        exit(1);
                    };
                    struct func* fn =  elems->fns->data[i];
if ((fn->isBinding==true)) {
continue;
}
declareFunc(fn,elems);
};
};
long int main(__BAH_ARR_TYPE_cpstring args){

                    if (args->length <= 0) {
                        printf("array (/home/alois/Documents/bah-bah/src/main.bah:46): args[%d] with length %d\n", 0, args->length);
                        exit(1);
                    };
                    execName =  args->data[0];
struct flags ____BAH_COMPILER_VAR_785 = {};
____BAH_COMPILER_VAR_785.flags = memoryAlloc(sizeof(array(struct flag*)));
            ____BAH_COMPILER_VAR_785.flags->length = 0;
            ____BAH_COMPILER_VAR_785.flags->elemSize = sizeof(struct flag*);
            ____BAH_COMPILER_VAR_785.args = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_785.args->length = 0;
            ____BAH_COMPILER_VAR_785.args->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_785.addString = flags__addString;
____BAH_COMPILER_VAR_785.addBool = flags__addBool;
____BAH_COMPILER_VAR_785.addInt = flags__addInt;
____BAH_COMPILER_VAR_785.addFloat = flags__addFloat;
____BAH_COMPILER_VAR_785.invalidate = flags__invalidate;
____BAH_COMPILER_VAR_785.getFlag = flags__getFlag;
____BAH_COMPILER_VAR_785.get = flags__get;
____BAH_COMPILER_VAR_785.getInt = flags__getInt;
____BAH_COMPILER_VAR_785.getFloat = flags__getFloat;
____BAH_COMPILER_VAR_785.isSet = flags__isSet;
____BAH_COMPILER_VAR_785.parse = flags__parse;
flags =  ____BAH_COMPILER_VAR_785;
flags.addString((struct flags*)&flags,"o","Name of the file to output.");
flags.addBool((struct flags*)&flags,"c","Translate bah file to C instead of compiling it.");
flags.addBool((struct flags*)&flags,"v","Show version of the compiler.");
flags.addBool((struct flags*)&flags,"l","Compile as a library.");
flags.addBool((struct flags*)&flags,"d","Compile as a dynamic executable. (useful if you are using a library that is only available shared but might reduce portability).");
flags.addBool((struct flags*)&flags,"rcp","Enables RCP (reference counter) instead of the garbage collector. Warning: if you are using self-reference, this will lead to memory leaks!");
flags.addBool((struct flags*)&flags,"fastrcp","Enables RCP without leak detection. It is recommended to test you programs with the -rcp flag to test for leak detection before using this flag.");
flags.addBool((struct flags*)&flags,"debug","Enables verbose json output.");
flags.addBool((struct flags*)&flags,"verboseRuntime","Enables verbose runtime, a debug mode of the compiled program.");
flags.addBool((struct flags*)&flags,"verboseCC","Enables verbose C compiler output, USE IN LAST RESORT.");
char * ____BAH_COMPILER_VAR_786 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Select the target OS for cross compilling (linux, windows, darwin), default: ");
long int strLen_1 = strlen(BAH_OS);
long int strLen_2 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_786 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_786+currStrOff, "Select the target OS for cross compilling (linux, windows, darwin), default: ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_786+currStrOff, BAH_OS, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_786+currStrOff, ".", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_786[currStrOff] = 0;
                }
                flags.addString((struct flags*)&flags,"target",____BAH_COMPILER_VAR_786);
char * ____BAH_COMPILER_VAR_787 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("If your Bah directory is not the default one (");
long int strLen_1 = strlen(BAH_DIR);
long int strLen_2 = strlen(").");
;                            
                    ____BAH_COMPILER_VAR_787 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_787+currStrOff, "If your Bah directory is not the default one (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_787+currStrOff, BAH_DIR, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_787+currStrOff, ").", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_787[currStrOff] = 0;
                }
                flags.addString((struct flags*)&flags,"bahDir",____BAH_COMPILER_VAR_787);
char * ____BAH_COMPILER_VAR_788 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("To change the C compiler used, default: ");
long int strLen_1 = strlen(BAH_CC);
long int strLen_2 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_788 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_788+currStrOff, "To change the C compiler used, default: ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_788+currStrOff, BAH_CC, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_788+currStrOff, ".", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_788[currStrOff] = 0;
                }
                flags.addString((struct flags*)&flags,"CC",____BAH_COMPILER_VAR_788);
flags.addBool((struct flags*)&flags,"object","Compile as an object.");
flags.parse((struct flags*)&flags,args);
if ((flags.isSet((struct flags*)&flags,"target")==1)) {
BAH_OS =  flags.get((struct flags*)&flags,"target");
char * ____BAH_COMPILER_VAR_789 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Build target: ");
long int strLen_1 = strlen(BAH_OS);
;                            
                    ____BAH_COMPILER_VAR_789 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_789+currStrOff, "Build target: ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_789+currStrOff, BAH_OS, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_789[currStrOff] = 0;
                }
                println(____BAH_COMPILER_VAR_789);
}
if ((flags.isSet((struct flags*)&flags,"bahDir")==1)) {
BAH_DIR =  flags.get((struct flags*)&flags,"bahDir");
array(char)* bahDirArr =  strAsArr(BAH_DIR);

                    if (bahDirArr->length <= len(bahDirArr)-1) {
                        printf("array (/home/alois/Documents/bah-bah/src/main.bah:79): bahDirArr[%d] with length %d\n", len(bahDirArr)-1, bahDirArr->length);
                        exit(1);
                    };
                    if ((bahDirArr->data[len(bahDirArr)-1]!=47)) {
char * ____BAH_COMPILER_VAR_790 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen("/");
;                            
                    ____BAH_COMPILER_VAR_790 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_790+currStrOff, BAH_DIR, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_790+currStrOff, "/", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_790[currStrOff] = 0;
                }
                BAH_DIR =  ____BAH_COMPILER_VAR_790;
}
char * ____BAH_COMPILER_VAR_791 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Bah directory: ");
long int strLen_1 = strlen(BAH_DIR);
;                            
                    ____BAH_COMPILER_VAR_791 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_791+currStrOff, "Bah directory: ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_791+currStrOff, BAH_DIR, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_791[currStrOff] = 0;
                }
                println(____BAH_COMPILER_VAR_791);
}
if ((flags.isSet((struct flags*)&flags,"CC")==1)) {
BAH_CC =  flags.get((struct flags*)&flags,"CC");
char * ____BAH_COMPILER_VAR_792 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("C compiler: ");
long int strLen_1 = strlen(BAH_CC);
;                            
                    ____BAH_COMPILER_VAR_792 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_792+currStrOff, "C compiler: ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_792+currStrOff, BAH_CC, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_792[currStrOff] = 0;
                }
                println(____BAH_COMPILER_VAR_792);
}
RCPlevel =  0;
if (flags.isSet((struct flags*)&flags,"rcp")) {
RCPlevel =  1;
}
else if (flags.isSet((struct flags*)&flags,"fastrcp")) {
RCPlevel =  2;
}
verboseRuntime =  (flags.isSet((struct flags*)&flags,"verboseRuntime")==1);
debug =  (flags.isSet((struct flags*)&flags,"debug")==1);
isObject =  (flags.isSet((struct flags*)&flags,"object")==1);
if ((debug==true)) {
debugStart();
}
RCPenabled =  ((flags.isSet((struct flags*)&flags,"rcp")==1)||flags.isSet((struct flags*)&flags,"fastrcp"));
if ((flags.isSet((struct flags*)&flags,"v")==1)) {
char * ____BAH_COMPILER_VAR_793 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Bah compiler version: ");
long int strLen_1 = strlen(BAH_VERSION);
long int strLen_2 = strlen(".\n© Alois Laurent Boe");
;                            
                    ____BAH_COMPILER_VAR_793 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_793+currStrOff, "Bah compiler version: ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_793+currStrOff, BAH_VERSION, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_793+currStrOff, ".\n© Alois Laurent Boe", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_793[currStrOff] = 0;
                }
                println(____BAH_COMPILER_VAR_793);
return 0;
}
if (((flags.isSet((struct flags*)&flags,"c")==1)&&(flags.isSet((struct flags*)&flags,"l")==1))) {
__BAH_panic("Cannot use -c (to translate to C code) and -l (to compile as a library) at the same time.","/home/alois/Documents/bah-bah/src/main.bah:112");
}
INIT =  rope("");
OUTPUT =  rope("\n    void __BAH_init();\n    #define noCheck(v) v\n    #define array(type)	\
    struct{	\
    type *data; \
    long int length; \
    long int elemSize; \
    }\n    typedef array(char*)* __BAH_ARR_TYPE_cpstring;\n    long int __BAH__main(__BAH_ARR_TYPE_cpstring);\n    ");
if ((flags.isSet((struct flags*)&flags,"l")==0)) {
if ((RCPenabled==true)) {
OUTPUT =  OUTPUT->add(OUTPUT, rope("\n            void RCP_init();\n            void RCP_shutdown();\n            void free(void*);\n            int main(int argc, char ** argv) {\n            RCP_init();\n            array(char*) * args = malloc(sizeof(array(char*)));\n            args->data = malloc(sizeof(char*)*argc);\n            memcpy(args->data, argv, sizeof(char*)*argc);\n            args->elemSize = sizeof(char*);\n            args->length = argc;\n            __BAH_init();\n            long int r =  __BAH__main((__BAH_ARR_TYPE_cpstring)args);\n            free(args->data);\n            free(args);\n            RCP_shutdown();\n            return r;\n            };\n            #define main(v) __BAH__main(v)\n            "));
}
else {
OUTPUT =  OUTPUT->add(OUTPUT, rope("\n            #include <gc.h>\n            int main(int argc, char ** argv) {\n            GC_INIT();\n            array(char*) * args = GC_MALLOC(sizeof(array(char*)));\n            args->data = GC_MALLOC(sizeof(char*)*argc);\n            memcpy(args->data, argv, sizeof(char*)*argc);\n            args->elemSize = sizeof(char*);\n            args->length = argc;\n            __BAH_init();\n            long int r =  __BAH__main((__BAH_ARR_TYPE_cpstring)args);\n            GC_FREE(args->data);\n            GC_FREE(args);\n            return r;\n            };\n            #define main(v) __BAH__main(v)\n            "));
}
}
struct compilerStateTag ____BAH_COMPILER_VAR_794 = {};
____BAH_COMPILER_VAR_794.includes = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_794.includes->length = 0;
            ____BAH_COMPILER_VAR_794.includes->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_794.cIncludes = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_794.cIncludes->length = 0;
            ____BAH_COMPILER_VAR_794.cIncludes->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_794.cLibs = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_794.cLibs->length = 0;
            ____BAH_COMPILER_VAR_794.cLibs->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_794.currentFile= null;
____BAH_COMPILER_VAR_794.currentDir = "./";
____BAH_COMPILER_VAR_794.isBranch = false;
____BAH_COMPILER_VAR_794.isFor = false;
____BAH_COMPILER_VAR_794.arrTypesDecl = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_794.arrTypesDecl->length = 0;
            ____BAH_COMPILER_VAR_794.arrTypesDecl->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_794.haveEntryPoint = false;
____BAH_COMPILER_VAR_794.RCPvars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_794.RCPvars->length = 0;
            ____BAH_COMPILER_VAR_794.RCPvars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_794.evals = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_794.evals->length = 0;
            ____BAH_COMPILER_VAR_794.evals->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_794.hasImports = false;
compilerState =  ____BAH_COMPILER_VAR_794;

{
long nLength = 0;
if (compilerState.arrTypesDecl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(compilerState.arrTypesDecl->data, (nLength+50)*sizeof(char *));
compilerState.arrTypesDecl->data = newPtr;
}
compilerState.arrTypesDecl->data[0] =  "__BAH_ARR_TYPE_cpstring";
compilerState.arrTypesDecl->length = nLength+1;
} else {
compilerState.arrTypesDecl->data[0] =  "__BAH_ARR_TYPE_cpstring";
}
};
char * fileName =  absPath(args->data[1]);
compilerState.currentFile =  fileName;
struct fileMap ____BAH_COMPILER_VAR_795 = {};
____BAH_COMPILER_VAR_795.handle = -1;
____BAH_COMPILER_VAR_795.p= null;
____BAH_COMPILER_VAR_795.open = fileMap__open;
____BAH_COMPILER_VAR_795.isValid = fileMap__isValid;
____BAH_COMPILER_VAR_795.close = fileMap__close;
struct fileMap fm =  ____BAH_COMPILER_VAR_795;
char * f =  fm.open((struct fileMap*)&fm,fileName);
if ((fm.isValid((struct fileMap*)&fm)==0)) {
char * ____BAH_COMPILER_VAR_796 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Could not open file '");
long int strLen_1 = strlen(fileName);
long int strLen_2 = strlen("'.");
;                            
                    ____BAH_COMPILER_VAR_796 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_796+currStrOff, "Could not open file '", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_796+currStrOff, fileName, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_796+currStrOff, "'.", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_796[currStrOff] = 0;
                }
                __BAH_panic(____BAH_COMPILER_VAR_796,"/home/alois/Documents/bah-bah/src/main.bah:185");
}
long int startTime =  getTimeUnix();
array(struct Tok)* tokens =  lexer(f);
fm.close((struct fileMap*)&fm);
if ((len(tokens)==0)) {
char * ____BAH_COMPILER_VAR_797 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("File '");
long int strLen_1 = strlen(fileName);
long int strLen_2 = strlen("' not recognized.");
;                            
                    ____BAH_COMPILER_VAR_797 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_797+currStrOff, "File '", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_797+currStrOff, fileName, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_797+currStrOff, "' not recognized.", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_797[currStrOff] = 0;
                }
                __BAH_panic(____BAH_COMPILER_VAR_797,"/home/alois/Documents/bah-bah/src/main.bah:193");
}
struct Elems* ____BAH_COMPILER_VAR_798 = memoryAlloc(sizeof(struct Elems));
____BAH_COMPILER_VAR_798->vars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_798->vars->length = 0;
            ____BAH_COMPILER_VAR_798->vars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_798->structs = memoryAlloc(sizeof(array(struct cStruct*)));
            ____BAH_COMPILER_VAR_798->structs->length = 0;
            ____BAH_COMPILER_VAR_798->structs->elemSize = sizeof(struct cStruct*);
            ____BAH_COMPILER_VAR_798->types = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_798->types->length = 0;
            ____BAH_COMPILER_VAR_798->types->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_798->fns = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_798->fns->length = 0;
            ____BAH_COMPILER_VAR_798->fns->elemSize = sizeof(struct func*);
            struct Elems* elems =  ____BAH_COMPILER_VAR_798;
if ((isObject==true)) {
OUTPUT =  rope("\n        #define noCheck(v) v\n        #define array(type)	\
        struct{	\
        type *data; \
        long int length; \
        long int elemSize; \
        }\n        typedef array(char*)* __BAH_ARR_TYPE_cpstring;\n        long int __BAH__main(__BAH_ARR_TYPE_cpstring);\n        ");
shouldOnlyDecl =  true;
}
if ((includeFile("builtin.bah",elems)==false)) {
char * ____BAH_COMPILER_VAR_799 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Could not find std-libs, please check '");
long int strLen_1 = strlen(BAH_DIR);
long int strLen_2 = strlen("'");
;                            
                    ____BAH_COMPILER_VAR_799 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_799+currStrOff, "Could not find std-libs, please check '", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_799+currStrOff, BAH_DIR, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_799+currStrOff, "'", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_799[currStrOff] = 0;
                }
                __BAH_panic(____BAH_COMPILER_VAR_799,"/home/alois/Documents/bah-bah/src/main.bah:216");
}
shouldOnlyDecl =  false;
if ((flags.isSet((struct flags*)&flags,"l")==1)) {
OUTPUT =  rope("");
declareAll(elems);
}
compilerState.currentDir =  getDirFromFile(fileName);
parseLines(tokens,elems);
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
if (((isObject==false)&&(compilerState.hasImports==false))) {
long int i =  0;
for (; (i<len(elems->fns)); i =  i+1) {

                    if (elems->fns->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/main.bah:243): elems->fns[%d] with length %d\n", i, elems->fns->length);
                        exit(1);
                    };
                    struct func* fn =  elems->fns->data[i];

                int ____BAH_COMPILER_VAR_800 = 0;
                for(int i=len(excludeFns)-1; i != -1; i--) {
                    if (excludeFns->data[i] != 0 && strcmp(excludeFns->data[i], fn->name) == 0) {
                        ____BAH_COMPILER_VAR_800 = 1;
                        break;
                    };
                };
                if ((((fn->used==false)&&(fn->code!=null))&&(____BAH_COMPILER_VAR_800==false))) {
char * ____BAH_COMPILER_VAR_801 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("//optimized out: ");
long int strLen_1 = strlen(fn->name);
long int strLen_2 = strlen("\n");
;                            
                    ____BAH_COMPILER_VAR_801 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_801+currStrOff, "//optimized out: ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_801+currStrOff, fn->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_801+currStrOff, "\n", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_801[currStrOff] = 0;
                }
                ropeSet(fn->code,____BAH_COMPILER_VAR_801);
}
};
}
if ((debug==true)) {
debugEnd();
return 0;
}
if ((isObject==false)) {
long int totalTime =  getTimeUnix() - startTime;
char * ____BAH_COMPILER_VAR_802 =intToStr(totalLines);char * ____BAH_COMPILER_VAR_803 =intToStr(totalTime / 1000000);char * ____BAH_COMPILER_VAR_804 =intToStr(totalLexerTime / 1000000);char * ____BAH_COMPILER_VAR_805 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Parsed. (");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_802);
long int strLen_2 = strlen(" lines, total time: ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_803);
long int strLen_4 = strlen("ms, lexer time: ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_804);
long int strLen_6 = strlen("ms)\e[0m");
;                            
                    ____BAH_COMPILER_VAR_805 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                    
                    memcpy(____BAH_COMPILER_VAR_805+currStrOff, "Parsed. (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_805+currStrOff, ____BAH_COMPILER_VAR_802, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_805+currStrOff, " lines, total time: ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_805+currStrOff, ____BAH_COMPILER_VAR_803, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_805+currStrOff, "ms, lexer time: ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_805+currStrOff, ____BAH_COMPILER_VAR_804, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_805+currStrOff, "ms)\e[0m", strLen_6);
                    currStrOff += strLen_6;
                    
                    ____BAH_COMPILER_VAR_805[currStrOff] = 0;
                }
                println(____BAH_COMPILER_VAR_805);
}
if ((flags.isSet((struct flags*)&flags,"o")==1)) {
fileName =  flags.get((struct flags*)&flags,"o");
}
else {
struct string outFileName =  string(args->data[1]);
outFileName.trimRight((struct string*)&outFileName,4);
fileName =  outFileName.str((struct string*)&outFileName);
}
char * isStatic =  "-static";
if (((flags.isSet((struct flags*)&flags,"d")==1)||(strcmp(BAH_OS, "darwin") == 0))) {
isStatic =  "";
}
if ((flags.isSet((struct flags*)&flags,"c")==0)) {
char * obj =  "";
if ((flags.isSet((struct flags*)&flags,"object")==1)) {
char * ____BAH_COMPILER_VAR_806 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(fileName);
long int strLen_1 = strlen(".o");
;                            
                    ____BAH_COMPILER_VAR_806 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_806+currStrOff, fileName, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_806+currStrOff, ".o", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_806[currStrOff] = 0;
                }
                fileName =  ____BAH_COMPILER_VAR_806;
obj =  "-c";
}
char * randFileName =  "-x c - -x none";
char * ____BAH_COMPILER_VAR_807 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(BAH_CC);
long int strLen_1 = strlen(" -I \"");
long int strLen_2 = strlen(BAH_DIR);
long int strLen_3 = strlen("libs/");
long int strLen_4 = strlen(BAH_OS);
long int strLen_5 = strlen("/include/\" -L \"");
long int strLen_6 = strlen(BAH_DIR);
long int strLen_7 = strlen("libs/");
long int strLen_8 = strlen(BAH_OS);
long int strLen_9 = strlen("/\" ");
long int strLen_10 = strlen(randFileName);
long int strLen_11 = strlen(" ");
long int strLen_12 = strlen(isStatic);
long int strLen_13 = strlen(" ");
long int strLen_14 = strlen(obj);
long int strLen_15 = strlen(" -w -O1 -o ");
long int strLen_16 = strlen(fileName);
;                            
                    ____BAH_COMPILER_VAR_807 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14 + strLen_15 + strLen_16);
                    
                    memcpy(____BAH_COMPILER_VAR_807+currStrOff, BAH_CC, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_807+currStrOff, " -I \"", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_807+currStrOff, BAH_DIR, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_807+currStrOff, "libs/", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_807+currStrOff, BAH_OS, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_807+currStrOff, "/include/\" -L \"", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_807+currStrOff, BAH_DIR, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_807+currStrOff, "libs/", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_807+currStrOff, BAH_OS, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_807+currStrOff, "/\" ", strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_807+currStrOff, randFileName, strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_807+currStrOff, " ", strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_807+currStrOff, isStatic, strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_807+currStrOff, " ", strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_807+currStrOff, obj, strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_807+currStrOff, " -w -O1 -o ", strLen_15);
                    currStrOff += strLen_15;
                    
                    memcpy(____BAH_COMPILER_VAR_807+currStrOff, fileName, strLen_16);
                    currStrOff += strLen_16;
                    
                    ____BAH_COMPILER_VAR_807[currStrOff] = 0;
                }
                char * gccArgs =  ____BAH_COMPILER_VAR_807;
if ((flags.isSet((struct flags*)&flags,"l")==1)) {
char * ____BAH_COMPILER_VAR_808 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(gccArgs);
long int strLen_1 = strlen(" -c");
;                            
                    ____BAH_COMPILER_VAR_808 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_808+currStrOff, gccArgs, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_808+currStrOff, " -c", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_808[currStrOff] = 0;
                }
                gccArgs =  ____BAH_COMPILER_VAR_808;
}
array(char *)* cLibs =  compilerState.cLibs;
long int i =  0;
while ((i<len(cLibs))) {

                    if (cLibs->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/main.bah:296): cLibs[%d] with length %d\n", i, cLibs->length);
                        exit(1);
                    };
                    char * l =  cLibs->data[i];
char * ____BAH_COMPILER_VAR_809 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(gccArgs);
long int strLen_1 = strlen(" -");
long int strLen_2 = strlen(l);
;                            
                    ____BAH_COMPILER_VAR_809 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_809+currStrOff, gccArgs, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_809+currStrOff, " -", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_809+currStrOff, l, strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_809[currStrOff] = 0;
                }
                gccArgs =  ____BAH_COMPILER_VAR_809;
i =  i + 1;
};
struct command cmd =  command(gccArgs);
cmd.input =  OUTPUT->toStr((struct rope*)OUTPUT);
if ((flags.isSet((struct flags*)&flags,"verboseCC")==1)) {
char * ____BAH_COMPILER_VAR_810 =cmd.run((struct command*)&cmd);println(____BAH_COMPILER_VAR_810);
}
else {
cmd.run((struct command*)&cmd);
}
if ((cmd.status!=0)) {
println("\e[1;31m[CC-ERROR]\e[0m\nCould not compiled.");
return 1;
}
if ((flags.isSet((struct flags*)&flags,"l")==1)) {
char * ____BAH_COMPILER_VAR_811 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("ar rcs ");
long int strLen_1 = strlen(fileName);
long int strLen_2 = strlen(".a ");
long int strLen_3 = strlen(fileName);
;                            
                    ____BAH_COMPILER_VAR_811 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                    
                    memcpy(____BAH_COMPILER_VAR_811+currStrOff, "ar rcs ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_811+currStrOff, fileName, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_811+currStrOff, ".a ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_811+currStrOff, fileName, strLen_3);
                    currStrOff += strLen_3;
                    
                    ____BAH_COMPILER_VAR_811[currStrOff] = 0;
                }
                cmd =  command(____BAH_COMPILER_VAR_811);
cmd.run((struct command*)&cmd);
}
}
else {
if ((flags.isSet((struct flags*)&flags,"o")==0)) {
char * ____BAH_COMPILER_VAR_812 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(fileName);
long int strLen_1 = strlen(".c");
;                            
                    ____BAH_COMPILER_VAR_812 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_812+currStrOff, fileName, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_812+currStrOff, ".c", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_812[currStrOff] = 0;
                }
                fileName =  ____BAH_COMPILER_VAR_812;
}
char * ____BAH_COMPILER_VAR_813 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(BAH_CC);
long int strLen_1 = strlen(" -I \"");
long int strLen_2 = strlen(BAH_DIR);
long int strLen_3 = strlen("libs/");
long int strLen_4 = strlen(BAH_OS);
long int strLen_5 = strlen("/include/\" -L \"");
long int strLen_6 = strlen(BAH_DIR);
long int strLen_7 = strlen("libs/");
long int strLen_8 = strlen(BAH_OS);
long int strLen_9 = strlen("/\" ");
long int strLen_10 = strlen(fileName);
long int strLen_11 = strlen(" ");
long int strLen_12 = strlen(isStatic);
long int strLen_13 = strlen(" -O1 -w ");
;                            
                    ____BAH_COMPILER_VAR_813 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13);
                    
                    memcpy(____BAH_COMPILER_VAR_813+currStrOff, BAH_CC, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_813+currStrOff, " -I \"", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_813+currStrOff, BAH_DIR, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_813+currStrOff, "libs/", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_813+currStrOff, BAH_OS, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_813+currStrOff, "/include/\" -L \"", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_813+currStrOff, BAH_DIR, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_813+currStrOff, "libs/", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_813+currStrOff, BAH_OS, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_813+currStrOff, "/\" ", strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_813+currStrOff, fileName, strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_813+currStrOff, " ", strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_813+currStrOff, isStatic, strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_813+currStrOff, " -O1 -w ", strLen_13);
                    currStrOff += strLen_13;
                    
                    ____BAH_COMPILER_VAR_813[currStrOff] = 0;
                }
                char * gccArgs =  ____BAH_COMPILER_VAR_813;
array(char *)* cLibs =  compilerState.cLibs;
long int i =  0;
while ((i<len(cLibs))) {

                    if (cLibs->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/main.bah:334): cLibs[%d] with length %d\n", i, cLibs->length);
                        exit(1);
                    };
                    char * l =  cLibs->data[i];
char * ____BAH_COMPILER_VAR_814 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(gccArgs);
long int strLen_1 = strlen(" -");
long int strLen_2 = strlen(l);
;                            
                    ____BAH_COMPILER_VAR_814 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_814+currStrOff, gccArgs, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_814+currStrOff, " -", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_814+currStrOff, l, strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_814[currStrOff] = 0;
                }
                gccArgs =  ____BAH_COMPILER_VAR_814;
i =  i + 1;
};
char * ____BAH_COMPILER_VAR_815 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("//COMPILE WITH: '");
long int strLen_1 = strlen(gccArgs);
long int strLen_2 = strlen("'\n");
;                            
                    ____BAH_COMPILER_VAR_815 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_815+currStrOff, "//COMPILE WITH: '", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_815+currStrOff, gccArgs, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_815+currStrOff, "'\n", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_815[currStrOff] = 0;
                }
                OUTPUT =  rope(____BAH_COMPILER_VAR_815)->add(rope(____BAH_COMPILER_VAR_815), OUTPUT);
struct fileStream ____BAH_COMPILER_VAR_816 = {};
____BAH_COMPILER_VAR_816.handle= null;
____BAH_COMPILER_VAR_816.isValid = fileStream__isValid;
____BAH_COMPILER_VAR_816.open = fileStream__open;
____BAH_COMPILER_VAR_816.close = fileStream__close;
____BAH_COMPILER_VAR_816.getPos = fileStream__getPos;
____BAH_COMPILER_VAR_816.setPos = fileStream__setPos;
____BAH_COMPILER_VAR_816.getSize = fileStream__getSize;
____BAH_COMPILER_VAR_816.rewind = fileStream__rewind;
____BAH_COMPILER_VAR_816.getChar = fileStream__getChar;
____BAH_COMPILER_VAR_816.setChar = fileStream__setChar;
____BAH_COMPILER_VAR_816.createFile = fileStream__createFile;
____BAH_COMPILER_VAR_816.writeFile = fileStream__writeFile;
____BAH_COMPILER_VAR_816.writePtr = fileStream__writePtr;
____BAH_COMPILER_VAR_816.readPtr = fileStream__readPtr;
____BAH_COMPILER_VAR_816.readContent = fileStream__readContent;
____BAH_COMPILER_VAR_816.readBytes = fileStream__readBytes;
____BAH_COMPILER_VAR_816.writeBytes = fileStream__writeBytes;
struct fileStream fs =  ____BAH_COMPILER_VAR_816;
fs.open((struct fileStream*)&fs,fileName,"w");
char * ____BAH_COMPILER_VAR_817 =OUTPUT->toStr((struct rope*)OUTPUT);fs.writeFile((struct fileStream*)&fs,____BAH_COMPILER_VAR_817);
fs.close((struct fileStream*)&fs);
}
if ((isObject==false)) {
long int totalTime =  getTimeUnix() - startTime;
char * ____BAH_COMPILER_VAR_818 =intToStr(totalTime / 1000000);char * ____BAH_COMPILER_VAR_819 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\e[1;32mDone. (compiled in ");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_818);
long int strLen_2 = strlen("ms)\e[0m");
;                            
                    ____BAH_COMPILER_VAR_819 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_819+currStrOff, "\e[1;32mDone. (compiled in ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_819+currStrOff, ____BAH_COMPILER_VAR_818, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_819+currStrOff, "ms)\e[0m", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_819[currStrOff] = 0;
                }
                println(____BAH_COMPILER_VAR_819);
}
return 0;
};

    
    void __attribute__((optimize("O0"))) __BAH_init() {
        __BAH_panic_chan =  null;
RAND_SEEDED =  0;
BAH_DIR =  "C:/Bah/";
BAH_OS =  "windows";
BAH_CC =  "gcc";
debug =  false;
verboseRuntime =  false;
isObject =  false;
execName =  "bah";
isSubObject =  false;
NEXT_LINE =  "";
shouldOnlyDecl =  false;
threadCount =  0;
currentFn =  null;
totalLines =  0;
totalLexerTime =  0;
RCPenabled =  false;
RCPlevel =  0;
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
varChars = memoryAlloc(sizeof(array(char)));

varChars->length = 1;
varChars->elemSize = sizeof(char);
varChars->data = memoryAlloc(sizeof(char) * 50);varChars->data[0] = 95;
seps = memoryAlloc(sizeof(array(char)));

seps->length = 1;
seps->elemSize = sizeof(char);
seps->data = memoryAlloc(sizeof(char) * 50);seps->data[0] = 46;
NB_COMP_VAR =  0;
noVOfns = memoryAlloc(sizeof(array(char *)));

noVOfns->length = 1;
noVOfns->elemSize = sizeof(char *);
noVOfns->data = memoryAlloc(sizeof(char *) * 50);noVOfns->data[0] = "__Bah_safe_string";
cache = memoryAlloc(sizeof(array(struct cacheFile*)));

cache->length = 0;
cache->elemSize = sizeof(struct cacheFile*);
prevLine =  (lineType)-1;
signs = memoryAlloc(sizeof(array(char *)));

signs->length = 7;
signs->elemSize = sizeof(char *);
signs->data = memoryAlloc(sizeof(char *) * 50);signs->data[0] = "|";
signs->data[1] = "&";
signs->data[2] = "%";
signs->data[3] = "+";
signs->data[4] = "-";
signs->data[5] = "*";
signs->data[6] = "/";
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

        
    };
    