//COMPILE WITH: 'gcc -I "/opt/bah/libs/linux/include/" -L "/opt/bah/libs/linux/" ../installer/linux.c -static -O1 -w  -lgc -lpthread -lm'

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
#define PROT_READ 1
#define PROT_WRITE 2
#define PROT_READWRITE 3
#define MAP_SHARED 1
#define MAP_ANONYMOUS 32
//optimized out: sharedMemory
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
#define __thread_create GC_pthread_create
#define __thread_join GC_pthread_join
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
this->handle =  open(fileName,O_RDWR,S_IRUSR|S_IWUSR);
struct stat ____BAH_COMPILER_VAR_15 = {};
struct stat sb =  ____BAH_COMPILER_VAR_15;
fstat(this->handle,&sb);
this->size =  sb.st_size;
this->p =  mmap(0,sb.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,this->handle,0);
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
timespec_get(&ts,TIME_UTC);
long int s =  ts.tv_sec * 1000000000 + ts.tv_nsec;
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
struct rope* ____BAH_COMPILER_VAR_50 = memoryAlloc(sizeof(struct rope));
____BAH_COMPILER_VAR_50->left= null;
____BAH_COMPILER_VAR_50->right= null;
____BAH_COMPILER_VAR_50->parent= null;
____BAH_COMPILER_VAR_50->str= null;
____BAH_COMPILER_VAR_50->getParent = rope__getParent;
____BAH_COMPILER_VAR_50->addStr = rope__addStr;
____BAH_COMPILER_VAR_50->toStr = rope__toStr;
____BAH_COMPILER_VAR_50->add = rope__add;
struct rope* tmp =  ____BAH_COMPILER_VAR_50;
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
char * ____BAH_COMPILER_VAR_52 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(cm);
long int strLen_1 = strlen(" 2>/dev/null");
;                            
                    ____BAH_COMPILER_VAR_52 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_52+currStrOff, cm, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_52+currStrOff, " 2>/dev/null", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_52[currStrOff] = 0;
                }
                cm =  ____BAH_COMPILER_VAR_52;
}
else {
char * ____BAH_COMPILER_VAR_53 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(cm);
long int strLen_1 = strlen(" 2>&1");
;                            
                    ____BAH_COMPILER_VAR_53 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_53+currStrOff, cm, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_53+currStrOff, " 2>&1", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_53[currStrOff] = 0;
                }
                cm =  ____BAH_COMPILER_VAR_53;
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
char * ____BAH_COMPILER_VAR_54 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(res);
long int strLen_1 = strlen(buff);
;                            
                    ____BAH_COMPILER_VAR_54 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_54+currStrOff, res, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_54+currStrOff, buff, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_54[currStrOff] = 0;
                }
                res =  ____BAH_COMPILER_VAR_54;
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
char * ____BAH_COMPILER_VAR_55 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(cm);
long int strLen_1 = strlen(" 2>/dev/null");
;                            
                    ____BAH_COMPILER_VAR_55 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_55+currStrOff, cm, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_55+currStrOff, " 2>/dev/null", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_55[currStrOff] = 0;
                }
                cm =  ____BAH_COMPILER_VAR_55;
}
else {
char * ____BAH_COMPILER_VAR_56 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(cm);
long int strLen_1 = strlen(" 2>&1");
;                            
                    ____BAH_COMPILER_VAR_56 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_56+currStrOff, cm, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_56+currStrOff, " 2>&1", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_56[currStrOff] = 0;
                }
                cm =  ____BAH_COMPILER_VAR_56;
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
char * ____BAH_COMPILER_VAR_57 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(response);
long int strLen_1 = strlen(buff);
;                            
                    ____BAH_COMPILER_VAR_57 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_57+currStrOff, response, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_57+currStrOff, buff, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_57[currStrOff] = 0;
                }
                response =  ____BAH_COMPILER_VAR_57;
res =  fgets(buff,1023,this->handle);
};
this->status =  pclose(this->handle);
arr->data=response;
arr->length=strlen(response);
return arr;
};
struct command command(char * s){
struct command ____BAH_COMPILER_VAR_58 = {};
____BAH_COMPILER_VAR_58.command= null;
____BAH_COMPILER_VAR_58.error = true;
____BAH_COMPILER_VAR_58.status = 0;
____BAH_COMPILER_VAR_58.input = null;
____BAH_COMPILER_VAR_58.handle= null;
____BAH_COMPILER_VAR_58.run = command__run;
____BAH_COMPILER_VAR_58.runBytes = command__runBytes;
struct command cmd =  ____BAH_COMPILER_VAR_58;
cmd.command =  s;
return cmd;
};
//optimized out: exec
char * BAH_DIR;
char * BAH_OS;
char * BAH_CC;
#define BAH_VERSION "v1.1 (build 75)"
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
struct Tok ____BAH_COMPILER_VAR_59 = {};
____BAH_COMPILER_VAR_59.cont = "";
____BAH_COMPILER_VAR_59.ogCont = "";
____BAH_COMPILER_VAR_59.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_59.pos = 0;
____BAH_COMPILER_VAR_59.line = 1;
____BAH_COMPILER_VAR_59.begLine = 1;
____BAH_COMPILER_VAR_59.bahType = "";
____BAH_COMPILER_VAR_59.isValue = false;
____BAH_COMPILER_VAR_59.isFunc = false;
____BAH_COMPILER_VAR_59.isOper = false;
struct Tok t =  ____BAH_COMPILER_VAR_59;
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
char * ____BAH_COMPILER_VAR_60 =null;
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
                    ____BAH_COMPILER_VAR_60 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7);
                    
                    memcpy(____BAH_COMPILER_VAR_60+currStrOff, "\e[1;31m[LEXER-ERROR]\e[0m ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_60+currStrOff, compilerState.currentFile, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_60+currStrOff, ":", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_60+currStrOff, lineStr, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_60+currStrOff, ":", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_60+currStrOff, posStr, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_60+currStrOff, "\n\e[0m\n", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_60+currStrOff, msg, strLen_7);
                    currStrOff += strLen_7;
                    
                    ____BAH_COMPILER_VAR_60[currStrOff] = 0;
                }
                println(____BAH_COMPILER_VAR_60);
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
char isHex =  false;
for (; (i<codeLength); i =  i+1) {

                    if (s->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:180): s[%d] with length %d\n", i, s->length);
                        exit(1);
                    };
                    c =  s->data[i];
if ((c==(char)46)) {
currentType =  TOKEN_TYPE_FLOAT;
}
else if ((isNumber(c)==0)) {
if ((isHex==false)) {
if ((c==120)) {
isHex =  true;
}
else {
break;
}
}
else {
if (isUpper(c)) {
c =  c + (char)32;
}
if (((c<97)||(c>102))) {
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
                        printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:208): s[%d] with length %d\n", i, s->length);
                        exit(1);
                    };
                    char n =  s->data[i];
char * toInt =  intToStr((long int)nc);
memory =  strToArr(toInt);
i =  i+1;

                    if (s->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:212): s[%d] with length %d\n", i, s->length);
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
                        printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:222): s[%d] with length %d\n", i, s->length);
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
                        printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:239): s[%d] with length %d\n", i, s->length);
                        exit(1);
                    };
                    c =  s->data[i];

                int ____BAH_COMPILER_VAR_61 = 0;
                for(int i=len(syntaxes)-1; i != -1; i--) {
                    if (syntaxes->data[i] == c) {
                        ____BAH_COMPILER_VAR_61 = 1;
                        break;
                    };
                };
                if ((____BAH_COMPILER_VAR_61==false)) {
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
                        printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:274): s[%d] with length %d\n", i, s->length);
                        exit(1);
                    };
                    c =  s->data[i];
if ((isAlphaNumeric(c)==0)) {

                int ____BAH_COMPILER_VAR_62 = 0;
                for(int i=len(varChars)-1; i != -1; i--) {
                    if (varChars->data[i] == c) {
                        ____BAH_COMPILER_VAR_62 = 1;
                        break;
                    };
                };
                if ((____BAH_COMPILER_VAR_62==false)) {
if ((c==62)) {

                    if (memory->length <= len(memory)-1) {
                        printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:278): memory[%d] with length %d\n", len(memory)-1, memory->length);
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

                int ____BAH_COMPILER_VAR_63 = 0;
                for(int i=len(keywords)-1; i != -1; i--) {
                    if (keywords->data[i] != 0 && strcmp(keywords->data[i], memstr) == 0) {
                        ____BAH_COMPILER_VAR_63 = 1;
                        break;
                    };
                };
                if (____BAH_COMPILER_VAR_63) {
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
char * ____BAH_COMPILER_VAR_64 =splitStringBefore(n,".");struct string res =  string(____BAH_COMPILER_VAR_64);
return res;
}
if (n.count((struct string*)&n,"->")) {
char * ____BAH_COMPILER_VAR_65 =splitStringBefore(n,"->");struct string res =  string(____BAH_COMPILER_VAR_65);
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
struct structMemb* ____BAH_COMPILER_VAR_66 = memoryAlloc(sizeof(struct structMemb));
____BAH_COMPILER_VAR_66->name = "";
____BAH_COMPILER_VAR_66->type = "";
____BAH_COMPILER_VAR_66->isConst = false;
____BAH_COMPILER_VAR_66->constVal = "";
____BAH_COMPILER_VAR_66->isArray = false;
____BAH_COMPILER_VAR_66->from = "";
____BAH_COMPILER_VAR_66->outterScope = false;
____BAH_COMPILER_VAR_66->isGlobal = false;
____BAH_COMPILER_VAR_66->def = "";
____BAH_COMPILER_VAR_66->isFn = false;
struct structMemb* sm =  ____BAH_COMPILER_VAR_66;
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
char * ____BAH_COMPILER_VAR_67 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("array(");
long int strLen_1 = strlen(t);
long int strLen_2 = strlen(")*");
;                            
                    ____BAH_COMPILER_VAR_67 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_67+currStrOff, "array(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_67+currStrOff, t, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_67+currStrOff, ")*", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_67[currStrOff] = 0;
                }
                char * r =  ____BAH_COMPILER_VAR_67;
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
struct reflectElement ____BAH_COMPILER_VAR_68 = {};
____BAH_COMPILER_VAR_68.type= null;
____BAH_COMPILER_VAR_68.name= null;
____BAH_COMPILER_VAR_68.arrayElem= null;
____BAH_COMPILER_VAR_68.structLayout = memoryAlloc(sizeof(array(struct reflectElement)));
            ____BAH_COMPILER_VAR_68.structLayout->length = 0;
            ____BAH_COMPILER_VAR_68.structLayout->elemSize = sizeof(struct reflectElement);
            ____BAH_COMPILER_VAR_68.value= null;
____BAH_COMPILER_VAR_68.calculateOffset = reflectElement__calculateOffset;
struct reflectElement re =  ____BAH_COMPILER_VAR_68;
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
struct reflectElement ____BAH_COMPILER_VAR_69 = {};
____BAH_COMPILER_VAR_69.type= null;
____BAH_COMPILER_VAR_69.name= null;
____BAH_COMPILER_VAR_69.arrayElem= null;
____BAH_COMPILER_VAR_69.structLayout = memoryAlloc(sizeof(array(struct reflectElement)));
            ____BAH_COMPILER_VAR_69.structLayout->length = 0;
            ____BAH_COMPILER_VAR_69.structLayout->elemSize = sizeof(struct reflectElement);
            ____BAH_COMPILER_VAR_69.value= null;
____BAH_COMPILER_VAR_69.calculateOffset = reflectElement__calculateOffset;
struct reflectElement ns =  ____BAH_COMPILER_VAR_69;
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
char * ____BAH_COMPILER_VAR_70 =k.str((struct string*)&k);mapWrapper__set(*p,____BAH_COMPILER_VAR_70,v);
}
else {
char * ____BAH_COMPILER_VAR_71 =k.str((struct string*)&k);mapWrapper__set(*p,____BAH_COMPILER_VAR_71,&v);
}
};
}
};
struct jsonElement* parseJson(char * s){
struct jsonElement* ____BAH_COMPILER_VAR_72 = memoryAlloc(sizeof(struct jsonElement));
____BAH_COMPILER_VAR_72->key= null;
____BAH_COMPILER_VAR_72->content= null;
____BAH_COMPILER_VAR_72->children = memoryAlloc(sizeof(array(struct jsonElement*)));
            ____BAH_COMPILER_VAR_72->children->length = 0;
            ____BAH_COMPILER_VAR_72->children->elemSize = sizeof(struct jsonElement*);
            ____BAH_COMPILER_VAR_72->get = jsonElement__get;
____BAH_COMPILER_VAR_72->str = jsonElement__str;
____BAH_COMPILER_VAR_72->scan = jsonElement__scan;
struct jsonElement* jsonElem =  ____BAH_COMPILER_VAR_72;
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
char * ____BAH_COMPILER_VAR_74 =arrToStr(currentElem);struct jsonElement* child =  parseJson(____BAH_COMPILER_VAR_74);
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
char * ____BAH_COMPILER_VAR_76 =arrToStr(currentElem);struct jsonElement* elem =  parseJson(____BAH_COMPILER_VAR_76);
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
char * ____BAH_COMPILER_VAR_77 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tabsStr);
long int strLen_1 = strlen("\t");
;                            
                    ____BAH_COMPILER_VAR_77 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_77+currStrOff, tabsStr, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_77+currStrOff, "\t", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_77[currStrOff] = 0;
                }
                tabsStr =  ____BAH_COMPILER_VAR_77;
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
char * ____BAH_COMPILER_VAR_78 =toJson__inner(m,true,tabs);char * ____BAH_COMPILER_VAR_79 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s);
long int strLen_1 = strlen(tabsStr);
long int strLen_2 = strlen("\"");
long int strLen_3 = strlen(m.name);
long int strLen_4 = strlen("\": ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_78);
long int strLen_6 = strlen(",\n");
;                            
                    ____BAH_COMPILER_VAR_79 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                    
                    memcpy(____BAH_COMPILER_VAR_79+currStrOff, s, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_79+currStrOff, tabsStr, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_79+currStrOff, "\"", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_79+currStrOff, m.name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_79+currStrOff, "\": ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_79+currStrOff, ____BAH_COMPILER_VAR_78, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_79+currStrOff, ",\n", strLen_6);
                    currStrOff += strLen_6;
                    
                    ____BAH_COMPILER_VAR_79[currStrOff] = 0;
                }
                s =  ____BAH_COMPILER_VAR_79;
}
else {
char * ____BAH_COMPILER_VAR_80 =toJson__inner(m,true,tabs);char * ____BAH_COMPILER_VAR_81 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s);
long int strLen_1 = strlen(tabsStr);
long int strLen_2 = strlen("\"");
long int strLen_3 = strlen(m.name);
long int strLen_4 = strlen("\": ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_80);
long int strLen_6 = strlen("\n");
;                            
                    ____BAH_COMPILER_VAR_81 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                    
                    memcpy(____BAH_COMPILER_VAR_81+currStrOff, s, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_81+currStrOff, tabsStr, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_81+currStrOff, "\"", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_81+currStrOff, m.name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_81+currStrOff, "\": ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_81+currStrOff, ____BAH_COMPILER_VAR_80, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_81+currStrOff, "\n", strLen_6);
                    currStrOff += strLen_6;
                    
                    ____BAH_COMPILER_VAR_81[currStrOff] = 0;
                }
                s =  ____BAH_COMPILER_VAR_81;
}
};
tabs =  tabs - 1;
tabsStr =  "";
i =  0;
while ((i<tabs)) {
char * ____BAH_COMPILER_VAR_82 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tabsStr);
long int strLen_1 = strlen("\t");
;                            
                    ____BAH_COMPILER_VAR_82 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_82+currStrOff, tabsStr, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_82+currStrOff, "\t", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_82[currStrOff] = 0;
                }
                tabsStr =  ____BAH_COMPILER_VAR_82;
i =  i + 1;
};
char * ____BAH_COMPILER_VAR_83 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s);
long int strLen_1 = strlen(tabsStr);
long int strLen_2 = strlen("}");
;                            
                    ____BAH_COMPILER_VAR_83 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_83+currStrOff, s, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_83+currStrOff, tabsStr, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_83+currStrOff, "}", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_83[currStrOff] = 0;
                }
                s =  ____BAH_COMPILER_VAR_83;
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
char * ____BAH_COMPILER_VAR_84 =jsonEscapeStr(s);char * ____BAH_COMPILER_VAR_85 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\"");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_84);
long int strLen_2 = strlen("\"");
;                            
                    ____BAH_COMPILER_VAR_85 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_85+currStrOff, "\"", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_85+currStrOff, ____BAH_COMPILER_VAR_84, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_85+currStrOff, "\"", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_85[currStrOff] = 0;
                }
                return ____BAH_COMPILER_VAR_85;
}
else {
char ** sp =  e.value;
char * s =  *sp;
char * ____BAH_COMPILER_VAR_86 =jsonEscapeStr(s);char * ____BAH_COMPILER_VAR_87 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\"");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_86);
long int strLen_2 = strlen("\"");
;                            
                    ____BAH_COMPILER_VAR_87 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_87+currStrOff, "\"", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_87+currStrOff, ____BAH_COMPILER_VAR_86, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_87+currStrOff, "\"", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_87[currStrOff] = 0;
                }
                return ____BAH_COMPILER_VAR_87;
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
char * ____BAH_COMPILER_VAR_88 =intToStr(arr->data[i]);char * ____BAH_COMPILER_VAR_89 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_88);
;                            
                    ____BAH_COMPILER_VAR_89 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_89+currStrOff, s, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_89+currStrOff, ____BAH_COMPILER_VAR_88, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_89[currStrOff] = 0;
                }
                s =  ____BAH_COMPILER_VAR_89;
i =  i + 1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_90 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s);
long int strLen_1 = strlen(",");
;                            
                    ____BAH_COMPILER_VAR_90 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_90+currStrOff, s, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_90+currStrOff, ",", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_90[currStrOff] = 0;
                }
                s =  ____BAH_COMPILER_VAR_90;
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
char * ____BAH_COMPILER_VAR_91 =floatToStr(arr->data[i]);char * ____BAH_COMPILER_VAR_92 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_91);
;                            
                    ____BAH_COMPILER_VAR_92 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_92+currStrOff, s, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_92+currStrOff, ____BAH_COMPILER_VAR_91, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_92[currStrOff] = 0;
                }
                s =  ____BAH_COMPILER_VAR_92;
i =  i + 1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_93 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s);
long int strLen_1 = strlen(",");
;                            
                    ____BAH_COMPILER_VAR_93 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_93+currStrOff, s, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_93+currStrOff, ",", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_93[currStrOff] = 0;
                }
                s =  ____BAH_COMPILER_VAR_93;
}
};
}
else if ((strcmp(ae->type, "cpstring") == 0)) {
array(char *)* arr = memoryAlloc(sizeof(array(char *)));

arr->length = 0;
arr->elemSize = sizeof(char *);
void ** arrPtr =  e.value;
arr =  *arrPtr;
char * ____BAH_COMPILER_VAR_94 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s);
long int strLen_1 = strlen("\n");
;                            
                    ____BAH_COMPILER_VAR_94 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_94+currStrOff, s, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_94+currStrOff, "\n", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_94[currStrOff] = 0;
                }
                s =  ____BAH_COMPILER_VAR_94;
long int i =  0;
while ((i<len(arr))) {

                    if (arr->length <= i) {
                        printf("array (/opt/bah/json.bah:512): arr[%d] with length %d\n", i, arr->length);
                        exit(1);
                    };
                    char * ____BAH_COMPILER_VAR_95 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s);
long int strLen_1 = strlen(arr->data[i]);
;                            
                    ____BAH_COMPILER_VAR_95 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_95+currStrOff, s, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_95+currStrOff, arr->data[i], strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_95[currStrOff] = 0;
                }
                s =  ____BAH_COMPILER_VAR_95;
i =  i + 1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_96 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s);
long int strLen_1 = strlen(",\n");
;                            
                    ____BAH_COMPILER_VAR_96 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_96+currStrOff, s, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_96+currStrOff, ",\n", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_96[currStrOff] = 0;
                }
                s =  ____BAH_COMPILER_VAR_96;
}
else {
char * ____BAH_COMPILER_VAR_97 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s);
long int strLen_1 = strlen("\n");
;                            
                    ____BAH_COMPILER_VAR_97 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_97+currStrOff, s, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_97+currStrOff, "\n", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_97[currStrOff] = 0;
                }
                s =  ____BAH_COMPILER_VAR_97;
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
char * ____BAH_COMPILER_VAR_98 =toJson__inner(*ae,false,tabs);char * ____BAH_COMPILER_VAR_99 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_98);
;                            
                    ____BAH_COMPILER_VAR_99 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_99+currStrOff, s, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_99+currStrOff, ____BAH_COMPILER_VAR_98, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_99[currStrOff] = 0;
                }
                s =  ____BAH_COMPILER_VAR_99;
i =  i + 1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_100 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s);
long int strLen_1 = strlen(",\n");
;                            
                    ____BAH_COMPILER_VAR_100 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_100+currStrOff, s, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_100+currStrOff, ",\n", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_100[currStrOff] = 0;
                }
                s =  ____BAH_COMPILER_VAR_100;
}
else {
char * ____BAH_COMPILER_VAR_101 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s);
long int strLen_1 = strlen("\n");
;                            
                    ____BAH_COMPILER_VAR_101 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_101+currStrOff, s, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_101+currStrOff, "\n", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_101[currStrOff] = 0;
                }
                s =  ____BAH_COMPILER_VAR_101;
}
};
}
char * ____BAH_COMPILER_VAR_102 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s);
long int strLen_1 = strlen("]");
;                            
                    ____BAH_COMPILER_VAR_102 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_102+currStrOff, s, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_102+currStrOff, "]", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_102[currStrOff] = 0;
                }
                s =  ____BAH_COMPILER_VAR_102;
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
char * ____BAH_COMPILER_VAR_103 = name;
struct reflectElement ____BAH_COMPILER_VAR_104 = __reflect(____BAH_COMPILER_VAR_103, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, 0);
char * ____BAH_COMPILER_VAR_105 =toJson(____BAH_COMPILER_VAR_104);char * ____BAH_COMPILER_VAR_106 =intToStr(line);char * ____BAH_COMPILER_VAR_107 =toJson(e);char * ____BAH_COMPILER_VAR_108 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n    {\n        \"name\": ");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_105);
long int strLen_2 = strlen(",\n        \"path\": \"");
long int strLen_3 = strlen(compilerState.currentFile);
long int strLen_4 = strlen(":");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_106);
long int strLen_6 = strlen("\",\n        \"element\": ");
long int strLen_7 = strlen(____BAH_COMPILER_VAR_107);
long int strLen_8 = strlen("\n    },\n    ");
;                            
                    ____BAH_COMPILER_VAR_108 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                    
                    memcpy(____BAH_COMPILER_VAR_108+currStrOff, "\n    {\n        \"name\": ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_108+currStrOff, ____BAH_COMPILER_VAR_105, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_108+currStrOff, ",\n        \"path\": \"", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_108+currStrOff, compilerState.currentFile, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_108+currStrOff, ":", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_108+currStrOff, ____BAH_COMPILER_VAR_106, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_108+currStrOff, "\",\n        \"element\": ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_108+currStrOff, ____BAH_COMPILER_VAR_107, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_108+currStrOff, "\n    },\n    ", strLen_8);
                    currStrOff += strLen_8;
                    
                    ____BAH_COMPILER_VAR_108[currStrOff] = 0;
                }
                println(____BAH_COMPILER_VAR_108);
};
void debugError(char * name,long int line,long int from,long int to,struct reflectElement e){
if ((debug==false)) {
return;
}
char * ____BAH_COMPILER_VAR_109 = name;
struct reflectElement ____BAH_COMPILER_VAR_110 = __reflect(____BAH_COMPILER_VAR_109, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, 0);
char * ____BAH_COMPILER_VAR_111 =toJson(____BAH_COMPILER_VAR_110);char * ____BAH_COMPILER_VAR_112 =intToStr(line);char * ____BAH_COMPILER_VAR_113 =intToStr(from);char * ____BAH_COMPILER_VAR_114 =intToStr(to);char * ____BAH_COMPILER_VAR_115 =toJson(e);char * ____BAH_COMPILER_VAR_116 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n    {\n        \"name\": ");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_111);
long int strLen_2 = strlen(",\n        \"path\": \"");
long int strLen_3 = strlen(compilerState.currentFile);
long int strLen_4 = strlen(":");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_112);
long int strLen_6 = strlen("\",\n        \"range\": [\n            ");
long int strLen_7 = strlen(____BAH_COMPILER_VAR_113);
long int strLen_8 = strlen(",\n            ");
long int strLen_9 = strlen(____BAH_COMPILER_VAR_114);
long int strLen_10 = strlen("\n        ],\n        \"element\": ");
long int strLen_11 = strlen(____BAH_COMPILER_VAR_115);
long int strLen_12 = strlen("\n    },\n    ");
;                            
                    ____BAH_COMPILER_VAR_116 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12);
                    
                    memcpy(____BAH_COMPILER_VAR_116+currStrOff, "\n    {\n        \"name\": ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_116+currStrOff, ____BAH_COMPILER_VAR_111, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_116+currStrOff, ",\n        \"path\": \"", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_116+currStrOff, compilerState.currentFile, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_116+currStrOff, ":", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_116+currStrOff, ____BAH_COMPILER_VAR_112, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_116+currStrOff, "\",\n        \"range\": [\n            ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_116+currStrOff, ____BAH_COMPILER_VAR_113, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_116+currStrOff, ",\n            ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_116+currStrOff, ____BAH_COMPILER_VAR_114, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_116+currStrOff, "\n        ],\n        \"element\": ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_116+currStrOff, ____BAH_COMPILER_VAR_115, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_116+currStrOff, "\n    },\n    ", strLen_12);
                    currStrOff += strLen_12;
                    
                    ____BAH_COMPILER_VAR_116[currStrOff] = 0;
                }
                println(____BAH_COMPILER_VAR_116);
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
struct variable* ____BAH_COMPILER_VAR_117 = v;
char ** ____BAH_COMPILER_VAR_119 = (char **)((char*)(____BAH_COMPILER_VAR_117) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_120 = __reflect(____BAH_COMPILER_VAR_119, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_121 = (char **)((char*)(____BAH_COMPILER_VAR_117) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_122 = __reflect(____BAH_COMPILER_VAR_121, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_123 = (char*)((char*)(____BAH_COMPILER_VAR_117) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_124 = __reflect(____BAH_COMPILER_VAR_123, sizeof(char), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_125 = (char **)((char*)(____BAH_COMPILER_VAR_117) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_126 = __reflect(____BAH_COMPILER_VAR_125, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_127 = (char*)((char*)(____BAH_COMPILER_VAR_117) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_128 = __reflect(____BAH_COMPILER_VAR_127, sizeof(char), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_129 = (char **)((char*)(____BAH_COMPILER_VAR_117) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_130 = __reflect(____BAH_COMPILER_VAR_129, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
char* ____BAH_COMPILER_VAR_131 = (char*)((char*)(____BAH_COMPILER_VAR_117) + offsetof(struct variable, outterScope));
struct reflectElement ____BAH_COMPILER_VAR_132 = __reflect(____BAH_COMPILER_VAR_131, sizeof(char), "bool", "outterScope", 0, 0, 0, 0, offsetof(struct variable, outterScope));
char* ____BAH_COMPILER_VAR_133 = (char*)((char*)(____BAH_COMPILER_VAR_117) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_134 = __reflect(____BAH_COMPILER_VAR_133, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_118 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_118->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_118->length = 8;
        ____BAH_COMPILER_VAR_118->data = memoryAlloc(____BAH_COMPILER_VAR_118->length * ____BAH_COMPILER_VAR_118->elemSize);
        ____BAH_COMPILER_VAR_118->data[0] = ____BAH_COMPILER_VAR_120;
____BAH_COMPILER_VAR_118->data[1] = ____BAH_COMPILER_VAR_122;
____BAH_COMPILER_VAR_118->data[2] = ____BAH_COMPILER_VAR_124;
____BAH_COMPILER_VAR_118->data[3] = ____BAH_COMPILER_VAR_126;
____BAH_COMPILER_VAR_118->data[4] = ____BAH_COMPILER_VAR_128;
____BAH_COMPILER_VAR_118->data[5] = ____BAH_COMPILER_VAR_130;
____BAH_COMPILER_VAR_118->data[6] = ____BAH_COMPILER_VAR_132;
____BAH_COMPILER_VAR_118->data[7] = ____BAH_COMPILER_VAR_134;
struct reflectElement ____BAH_COMPILER_VAR_135 = __reflect(____BAH_COMPILER_VAR_117, sizeof(struct variable), "variable*", "v", 0, 0, 1, ____BAH_COMPILER_VAR_118, 0);
debugPrint("var_end",line,____BAH_COMPILER_VAR_135);
}
i =  i + 1;
};
};
void throwErr(void * tp,char * format){
char * str =  "";
char * info =  "";
long int pos =  0;
if ((tp!=null)) {
struct fileMap ____BAH_COMPILER_VAR_136 = {};
____BAH_COMPILER_VAR_136.handle = -1;
____BAH_COMPILER_VAR_136.p= null;
____BAH_COMPILER_VAR_136.open = fileMap__open;
____BAH_COMPILER_VAR_136.isValid = fileMap__isValid;
____BAH_COMPILER_VAR_136.close = fileMap__close;
struct fileMap fm =  ____BAH_COMPILER_VAR_136;
char * fileSrcStr =  fm.open((struct fileMap*)&fm,compilerState.currentFile);
struct Tok* t =  tp;
struct string ffmt =  string(format);
if ((strlen(t->ogCont)==0)) {
t->ogCont =  t->cont;
}
char * ____BAH_COMPILER_VAR_137 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("'");
long int strLen_1 = strlen(t->ogCont);
long int strLen_2 = strlen("'");
;                            
                    ____BAH_COMPILER_VAR_137 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_137+currStrOff, "'", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_137+currStrOff, t->ogCont, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_137+currStrOff, "'", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_137[currStrOff] = 0;
                }
                ffmt.replace((struct string*)&ffmt,"{TOKEN}",____BAH_COMPILER_VAR_137);
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
char * ____BAH_COMPILER_VAR_138 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\e[1;31m");
long int strLen_1 = strlen(t->ogCont);
long int strLen_2 = strlen("\e[1;37m");
;                            
                    ____BAH_COMPILER_VAR_138 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_138+currStrOff, "\e[1;31m", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_138+currStrOff, t->ogCont, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_138+currStrOff, "\e[1;37m", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_138[currStrOff] = 0;
                }
                array(char)* errTk =  strToArr(____BAH_COMPILER_VAR_138);
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
char * ____BAH_COMPILER_VAR_139 =intToStr(t->line);char * ____BAH_COMPILER_VAR_140 =intToStr(pos);char * ____BAH_COMPILER_VAR_141 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_139);
long int strLen_1 = strlen(":");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_140);
;                            
                    ____BAH_COMPILER_VAR_141 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_141+currStrOff, ____BAH_COMPILER_VAR_139, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_141+currStrOff, ":", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_141+currStrOff, ____BAH_COMPILER_VAR_140, strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_141[currStrOff] = 0;
                }
                info =  ____BAH_COMPILER_VAR_141;
}
if ((debug==true)) {
struct Tok* t =  tp;
char * ____BAH_COMPILER_VAR_142 = format;
struct reflectElement ____BAH_COMPILER_VAR_143 = __reflect(____BAH_COMPILER_VAR_142, sizeof(char *), "cpstring", "format", 0, 0, 0, 0, 0);
debugError("error",t->line,pos,pos + strlen(t->ogCont),____BAH_COMPILER_VAR_143);
debugExit();
}
else {
char * ____BAH_COMPILER_VAR_144 =null;
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
                    ____BAH_COMPILER_VAR_144 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7);
                    
                    memcpy(____BAH_COMPILER_VAR_144+currStrOff, "\e[1;31m[ERROR]\e[0m ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_144+currStrOff, compilerState.currentFile, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_144+currStrOff, ":", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_144+currStrOff, info, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_144+currStrOff, "\n\e[1;37m\t", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_144+currStrOff, str, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_144+currStrOff, "\e[0m\n", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_144+currStrOff, format, strLen_7);
                    currStrOff += strLen_7;
                    
                    ____BAH_COMPILER_VAR_144[currStrOff] = 0;
                }
                println(____BAH_COMPILER_VAR_144);
}
exit(1);
};
void throwWarning(char * s){
char * ____BAH_COMPILER_VAR_145 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\e[1;33m[WARNING]\e[0m ");
long int strLen_1 = strlen(compilerState.currentFile);
long int strLen_2 = strlen("\n\e[1;37m\t");
long int strLen_3 = strlen(s);
long int strLen_4 = strlen("\e[0m");
;                            
                    ____BAH_COMPILER_VAR_145 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_145+currStrOff, "\e[1;33m[WARNING]\e[0m ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_145+currStrOff, compilerState.currentFile, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_145+currStrOff, "\n\e[1;37m\t", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_145+currStrOff, s, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_145+currStrOff, "\e[0m", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_145[currStrOff] = 0;
                }
                println(____BAH_COMPILER_VAR_145);
};
#include <stdlib.h>
char * absPath(char * path){
char * p =  realpath(path,null);
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
struct variable* ____BAH_COMPILER_VAR_147 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_147->name = "";
____BAH_COMPILER_VAR_147->type = "";
____BAH_COMPILER_VAR_147->isConst = false;
____BAH_COMPILER_VAR_147->constVal = "";
____BAH_COMPILER_VAR_147->isArray = false;
____BAH_COMPILER_VAR_147->from = "";
____BAH_COMPILER_VAR_147->outterScope = false;
____BAH_COMPILER_VAR_147->isGlobal = false;
struct variable* nv =  ____BAH_COMPILER_VAR_147;
nv->from =  memb->from;
nv->name =  memb->name;
nv->type =  memb->type;
nv->name =  ogName;
char * r =  nv->type;
struct string tcc =  string(ogName);
if (tcc.count((struct string*)&tcc,"&")) {
char * ____BAH_COMPILER_VAR_148 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(r);
long int strLen_1 = strlen("*");
;                            
                    ____BAH_COMPILER_VAR_148 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_148+currStrOff, r, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_148+currStrOff, "*", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_148[currStrOff] = 0;
                }
                r =  ____BAH_COMPILER_VAR_148;
}
long int nbUnaries =  tcc.count((struct string*)&tcc,"*");
if ((nbUnaries>0)) {
struct string ct =  string(r);
long int pointerLevel =  ct.count((struct string*)&ct,"*");
if ((pointerLevel<nbUnaries)) {
char * ____BAH_COMPILER_VAR_149 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot use '*' on ");
long int strLen_1 = strlen(nv->name);
long int strLen_2 = strlen(" because it is not pointer.");
;                            
                    ____BAH_COMPILER_VAR_149 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_149+currStrOff, "Cannot use '*' on ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_149+currStrOff, nv->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_149+currStrOff, " because it is not pointer.", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_149[currStrOff] = 0;
                }
                throwErr(null,____BAH_COMPILER_VAR_149);
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
char * ____BAH_COMPILER_VAR_150 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\e[1;31m[INTERNAL COMPILER ERROR]\e[0m\n Please report the bug as 'compiler searching '");
long int strLen_1 = strlen(name);
long int strLen_2 = strlen("' resulting in null var'.");
;                            
                    ____BAH_COMPILER_VAR_150 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_150+currStrOff, "\e[1;31m[INTERNAL COMPILER ERROR]\e[0m\n Please report the bug as 'compiler searching '", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_150+currStrOff, name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_150+currStrOff, "' resulting in null var'.", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_150[currStrOff] = 0;
                }
                __BAH_panic(____BAH_COMPILER_VAR_150,"/home/alois/Documents/bah-bah/src/var.bah:106");
}
if ((strcmp(v->name, name) == 0)) {
struct variable* ____BAH_COMPILER_VAR_151 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_151->name = "";
____BAH_COMPILER_VAR_151->type = "";
____BAH_COMPILER_VAR_151->isConst = false;
____BAH_COMPILER_VAR_151->constVal = "";
____BAH_COMPILER_VAR_151->isArray = false;
____BAH_COMPILER_VAR_151->from = "";
____BAH_COMPILER_VAR_151->outterScope = false;
____BAH_COMPILER_VAR_151->isGlobal = false;
struct variable* nv =  ____BAH_COMPILER_VAR_151;
nv->type =  v->type;
nv->name =  v->name;
nv->isConst =  v->isConst;
char * r =  nv->type;
struct string tcc =  string(ogName);
if (tcc.count((struct string*)&tcc,"&")) {
char * ____BAH_COMPILER_VAR_152 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(r);
long int strLen_1 = strlen("*");
;                            
                    ____BAH_COMPILER_VAR_152 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_152+currStrOff, r, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_152+currStrOff, "*", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_152[currStrOff] = 0;
                }
                r =  ____BAH_COMPILER_VAR_152;
}
long int nbUnaries =  tcc.count((struct string*)&tcc,"*");
if ((nbUnaries>0)) {
struct string ct =  string(r);
long int pointerLevel =  ct.count((struct string*)&ct,"*");
if ((pointerLevel<nbUnaries)) {
char * ____BAH_COMPILER_VAR_153 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot use '*' on ");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(" because it is not pointer.");
;                            
                    ____BAH_COMPILER_VAR_153 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_153+currStrOff, "Cannot use '*' on ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_153+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_153+currStrOff, " because it is not pointer.", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_153[currStrOff] = 0;
                }
                throwErr(null,____BAH_COMPILER_VAR_153);
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
struct variable* ____BAH_COMPILER_VAR_154 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_154->name = "";
____BAH_COMPILER_VAR_154->type = "";
____BAH_COMPILER_VAR_154->isConst = false;
____BAH_COMPILER_VAR_154->constVal = "";
____BAH_COMPILER_VAR_154->isArray = false;
____BAH_COMPILER_VAR_154->from = "";
____BAH_COMPILER_VAR_154->outterScope = false;
____BAH_COMPILER_VAR_154->isGlobal = false;
struct variable* nv =  ____BAH_COMPILER_VAR_154;
nv->name =  name;
nv->type =  "function(";
long int j =  0;
while ((j<len(fn->args))) {

                    if (fn->args->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/var.bah:143): fn->args[%d] with length %d\n", j, fn->args->length);
                        exit(1);
                    };
                    struct variable* arg =  fn->args->data[j];
char * ____BAH_COMPILER_VAR_155 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(nv->type);
long int strLen_1 = strlen(arg->type);
;                            
                    ____BAH_COMPILER_VAR_155 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_155+currStrOff, nv->type, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_155+currStrOff, arg->type, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_155[currStrOff] = 0;
                }
                nv->type =  ____BAH_COMPILER_VAR_155;
j =  j + 1;
if ((j<len(fn->args))) {
char * ____BAH_COMPILER_VAR_156 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(nv->type);
long int strLen_1 = strlen(",");
;                            
                    ____BAH_COMPILER_VAR_156 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_156+currStrOff, nv->type, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_156+currStrOff, ",", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_156[currStrOff] = 0;
                }
                nv->type =  ____BAH_COMPILER_VAR_156;
}
};
fn->used =  true;
char * ____BAH_COMPILER_VAR_157 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(nv->type);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen(fn->returns->type);
;                            
                    ____BAH_COMPILER_VAR_157 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_157+currStrOff, nv->type, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_157+currStrOff, ")", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_157+currStrOff, fn->returns->type, strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_157[currStrOff] = 0;
                }
                nv->type =  ____BAH_COMPILER_VAR_157;
return nv;
}
i =  i + 1;
};
return null;
};
char * setCType(struct variable* v,struct Elems* elems){
struct string tp =  getCType(v->type,elems);
char * t =  tp.str((struct string*)&tp);
char * ____BAH_COMPILER_VAR_158 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(t);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(v->name);
;                            
                    ____BAH_COMPILER_VAR_158 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_158+currStrOff, t, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_158+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_158+currStrOff, v->name, strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_158[currStrOff] = 0;
                }
                t =  ____BAH_COMPILER_VAR_158;
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
struct func* ____BAH_COMPILER_VAR_159 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_159->name = "";
____BAH_COMPILER_VAR_159->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_159->args->length = 0;
            ____BAH_COMPILER_VAR_159->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_159->returns= null;
____BAH_COMPILER_VAR_159->isBinding = false;
____BAH_COMPILER_VAR_159->from = "";
____BAH_COMPILER_VAR_159->file = "";
____BAH_COMPILER_VAR_159->line = 1;
____BAH_COMPILER_VAR_159->used = false;
____BAH_COMPILER_VAR_159->code = null;
struct func* nf =  ____BAH_COMPILER_VAR_159;
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
struct variable* ____BAH_COMPILER_VAR_160 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_160->name = "";
____BAH_COMPILER_VAR_160->type = "";
____BAH_COMPILER_VAR_160->isConst = false;
____BAH_COMPILER_VAR_160->constVal = "";
____BAH_COMPILER_VAR_160->isArray = false;
____BAH_COMPILER_VAR_160->from = "";
____BAH_COMPILER_VAR_160->outterScope = false;
____BAH_COMPILER_VAR_160->isGlobal = false;
struct variable* arg =  ____BAH_COMPILER_VAR_160;
char * ____BAH_COMPILER_VAR_161 =intToStr(len(nf->args));char * ____BAH_COMPILER_VAR_162 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("arg_");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_161);
;                            
                    ____BAH_COMPILER_VAR_162 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_162+currStrOff, "arg_", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_162+currStrOff, ____BAH_COMPILER_VAR_161, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_162[currStrOff] = 0;
                }
                arg->name =  ____BAH_COMPILER_VAR_162;
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
struct variable* ____BAH_COMPILER_VAR_163 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_163->name = "";
____BAH_COMPILER_VAR_163->type = "";
____BAH_COMPILER_VAR_163->isConst = false;
____BAH_COMPILER_VAR_163->constVal = "";
____BAH_COMPILER_VAR_163->isArray = false;
____BAH_COMPILER_VAR_163->from = "";
____BAH_COMPILER_VAR_163->outterScope = false;
____BAH_COMPILER_VAR_163->isGlobal = false;
nf->returns =  ____BAH_COMPILER_VAR_163;
nf->returns->name =  "_return";
nf->returns->type =  arrToStr(memory);
return nf;
};
struct func* searchFunc(char * name,struct Elems* elems,char inclCurr){
char * ogName =  name;
if ((strcmp(name, "noCheck") == 0)) {
struct func* ____BAH_COMPILER_VAR_164 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_164->name = "";
____BAH_COMPILER_VAR_164->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_164->args->length = 0;
            ____BAH_COMPILER_VAR_164->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_164->returns= null;
____BAH_COMPILER_VAR_164->isBinding = false;
____BAH_COMPILER_VAR_164->from = "";
____BAH_COMPILER_VAR_164->file = "";
____BAH_COMPILER_VAR_164->line = 1;
____BAH_COMPILER_VAR_164->used = false;
____BAH_COMPILER_VAR_164->code = null;
struct func* fn =  ____BAH_COMPILER_VAR_164;
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
char * ____BAH_COMPILER_VAR_165 =fnName.str((struct string*)&fnName);struct structMemb* memb =  searchStructMemb(____BAH_COMPILER_VAR_165,s,elems);
name =  fnName.content;
char * ____BAH_COMPILER_VAR_166 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(memb->from);
long int strLen_1 = strlen("__");
long int strLen_2 = strlen(name);
;                            
                    ____BAH_COMPILER_VAR_166 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_166+currStrOff, memb->from, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_166+currStrOff, "__", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_166+currStrOff, name, strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_166[currStrOff] = 0;
                }
                name =  ____BAH_COMPILER_VAR_166;
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
char * ____BAH_COMPILER_VAR_167 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\e[1;31m[INTERNAL COMPILER ERROR]\e[0m\n Please report the bug as 'compiler searching '");
long int strLen_1 = strlen(name);
long int strLen_2 = strlen("' resulting in null func'.");
;                            
                    ____BAH_COMPILER_VAR_167 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_167+currStrOff, "\e[1;31m[INTERNAL COMPILER ERROR]\e[0m\n Please report the bug as 'compiler searching '", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_167+currStrOff, name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_167+currStrOff, "' resulting in null func'.", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_167[currStrOff] = 0;
                }
                __BAH_panic(____BAH_COMPILER_VAR_167,"/home/alois/Documents/bah-bah/src/var.bah:284");
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
struct func* ____BAH_COMPILER_VAR_168 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_168->name = "";
____BAH_COMPILER_VAR_168->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_168->args->length = 0;
            ____BAH_COMPILER_VAR_168->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_168->returns= null;
____BAH_COMPILER_VAR_168->isBinding = false;
____BAH_COMPILER_VAR_168->from = "";
____BAH_COMPILER_VAR_168->file = "";
____BAH_COMPILER_VAR_168->line = 1;
____BAH_COMPILER_VAR_168->used = false;
____BAH_COMPILER_VAR_168->code = null;
struct func* nf =  ____BAH_COMPILER_VAR_168;
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
char * ____BAH_COMPILER_VAR_169 =null;
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
                    ____BAH_COMPILER_VAR_169 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                    
                    memcpy(____BAH_COMPILER_VAR_169+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_169+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_169+currStrOff, sep, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_169+currStrOff, m->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_169+currStrOff, " = ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_169+currStrOff, m->def, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_169+currStrOff, ";\n", strLen_6);
                    currStrOff += strLen_6;
                    
                    ____BAH_COMPILER_VAR_169[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_169;
declared =  true;
}
if ((cmpt.hasPrefix((struct string*)&cmpt,"[]")==1)) {
cmpt.trimLeft((struct string*)&cmpt,2);
char * cmptstr =  cmpt.str((struct string*)&cmpt);
struct string elemCType =  getCType(cmptstr,elems);
char * elemCTypeStr =  elemCType.str((struct string*)&elemCType);
char * ____BAH_COMPILER_VAR_170 =null;
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
                    ____BAH_COMPILER_VAR_170 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14 + strLen_15 + strLen_16);
                    
                    memcpy(____BAH_COMPILER_VAR_170+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_170+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_170+currStrOff, sep, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_170+currStrOff, m->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_170+currStrOff, " = memoryAlloc(sizeof(array(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_170+currStrOff, elemCTypeStr, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_170+currStrOff, ")));\n            ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_170+currStrOff, v->name, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_170+currStrOff, sep, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_170+currStrOff, m->name, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_170+currStrOff, "->length = 0;\n            ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_170+currStrOff, v->name, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_170+currStrOff, sep, strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_170+currStrOff, m->name, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_170+currStrOff, "->elemSize = sizeof(", strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_170+currStrOff, elemCTypeStr, strLen_15);
                    currStrOff += strLen_15;
                    
                    memcpy(____BAH_COMPILER_VAR_170+currStrOff, ");\n            ", strLen_16);
                    currStrOff += strLen_16;
                    
                    ____BAH_COMPILER_VAR_170[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_170;
declared =  true;
}
else if ((cmpt.hasPrefix((struct string*)&cmpt,"map:")==1)) {
cmpt.trimLeft((struct string*)&cmpt,4);
char * ____BAH_COMPILER_VAR_171 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen(sep);
long int strLen_2 = strlen(m->name);
long int strLen_3 = strlen(" = mapWrapper();\n");
;                            
                    ____BAH_COMPILER_VAR_171 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                    
                    memcpy(____BAH_COMPILER_VAR_171+currStrOff, v->name, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_171+currStrOff, sep, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_171+currStrOff, m->name, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_171+currStrOff, " = mapWrapper();\n", strLen_3);
                    currStrOff += strLen_3;
                    
                    ____BAH_COMPILER_VAR_171[currStrOff] = 0;
                }
                char * ____BAH_COMPILER_VAR_172 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_171);
;                            
                    ____BAH_COMPILER_VAR_172 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_172+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_172+currStrOff, ____BAH_COMPILER_VAR_171, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_172[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_172;
declared =  true;
}
else if ((cmpt.hasPrefix((struct string*)&cmpt,"chan:")==1)) {
cmpt.trimLeft((struct string*)&cmpt,5);
char * ____BAH_COMPILER_VAR_173 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen(sep);
long int strLen_2 = strlen(m->name);
long int strLen_3 = strlen(" = channel();\n");
;                            
                    ____BAH_COMPILER_VAR_173 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                    
                    memcpy(____BAH_COMPILER_VAR_173+currStrOff, v->name, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_173+currStrOff, sep, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_173+currStrOff, m->name, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_173+currStrOff, " = channel();\n", strLen_3);
                    currStrOff += strLen_3;
                    
                    ____BAH_COMPILER_VAR_173[currStrOff] = 0;
                }
                char * ____BAH_COMPILER_VAR_174 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_173);
;                            
                    ____BAH_COMPILER_VAR_174 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_174+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_174+currStrOff, ____BAH_COMPILER_VAR_173, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_174[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_174;
declared =  true;
}
if ((isRCPpointerType(m->type)&&(declared==false))) {
char * ____BAH_COMPILER_VAR_175 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(sep);
long int strLen_3 = strlen(m->name);
long int strLen_4 = strlen("= null;\n");
;                            
                    ____BAH_COMPILER_VAR_175 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_175+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_175+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_175+currStrOff, sep, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_175+currStrOff, m->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_175+currStrOff, "= null;\n", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_175[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_175;
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
char * ____BAH_COMPILER_VAR_176 =null;
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
                    
                    memcpy(____BAH_COMPILER_VAR_176+currStrOff, es->name, strLen_5);
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
}
array(struct func*)* methods =  s->methods;
i =  0;
while ((i<len(methods))) {

                    if (methods->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/var.bah:372): methods[%d] with length %d\n", i, methods->length);
                        exit(1);
                    };
                    struct func* m =  methods->data[i];
char * ____BAH_COMPILER_VAR_177 =null;
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
                    ____BAH_COMPILER_VAR_177 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                    
                    memcpy(____BAH_COMPILER_VAR_177+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_177+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_177+currStrOff, sep, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_177+currStrOff, m->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_177+currStrOff, " = ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_177+currStrOff, s->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_177+currStrOff, "__", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_177+currStrOff, m->name, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_177+currStrOff, ";\n", strLen_8);
                    currStrOff += strLen_8;
                    
                    ____BAH_COMPILER_VAR_177[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_177;
i =  i + 1;
};
if ((((s->isBinding==false)&&RCPavailable())&&(s->hasRCPmemb==true))) {
if ((strCount(v->type,"*")==0)) {
char * ____BAH_COMPILER_VAR_178 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(".__RCP_counter = malloc(sizeof(int));*(int*)");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen(".__RCP_counter = 1;\n");
;                            
                    ____BAH_COMPILER_VAR_178 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_178+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_178+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_178+currStrOff, ".__RCP_counter = malloc(sizeof(int));*(int*)", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_178+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_178+currStrOff, ".__RCP_counter = 1;\n", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_178[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_178;
}
else {
char * ____BAH_COMPILER_VAR_179 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen("->__RCP_counter = RCP_request(");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen(");\n");
;                            
                    ____BAH_COMPILER_VAR_179 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_179+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_179+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_179+currStrOff, "->__RCP_counter = RCP_request(", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_179+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_179+currStrOff, ");\n", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_179[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_179;
}
}
return code;
};
long int NB_COMP_VAR;
char * genCompilerVar(){
char * ____BAH_COMPILER_VAR_180 =intToStr(NB_COMP_VAR);char * ____BAH_COMPILER_VAR_181 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("____BAH_COMPILER_VAR_");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_180);
;                            
                    ____BAH_COMPILER_VAR_181 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_181+currStrOff, "____BAH_COMPILER_VAR_", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_181+currStrOff, ____BAH_COMPILER_VAR_180, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_181[currStrOff] = 0;
                }
                char * name =  ____BAH_COMPILER_VAR_181;
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
char * ____BAH_COMPILER_VAR_182 =pathToVarName(compilerState.currentFile);char * ____BAH_COMPILER_VAR_183 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(name);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_182);
;                            
                    ____BAH_COMPILER_VAR_183 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_183+currStrOff, name, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_183+currStrOff, ____BAH_COMPILER_VAR_182, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_183[currStrOff] = 0;
                }
                name =  ____BAH_COMPILER_VAR_183;
}
char * evals =  "";
char * ____BAH_COMPILER_VAR_184 =intToStr(len(compilerState.evals));char * ____BAH_COMPILER_VAR_185 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("volatile struct __eval_binding __tmp__evals_bindings[");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_184);
long int strLen_2 = strlen("] = {");
;                            
                    ____BAH_COMPILER_VAR_185 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_185+currStrOff, "volatile struct __eval_binding __tmp__evals_bindings[", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_185+currStrOff, ____BAH_COMPILER_VAR_184, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_185+currStrOff, "] = {", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_185[currStrOff] = 0;
                }
                char * evalsTMPDecl =  ____BAH_COMPILER_VAR_185;
long int i =  0;
for (; (i<len(compilerState.evals)); i =  i+1) {

                    if (compilerState.evals->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/var.bah:435): compilerState.evals[%d] with length %d\n", i, compilerState.evals->length);
                        exit(1);
                    };
                    char * e =  compilerState.evals->data[i];
char * ____BAH_COMPILER_VAR_186 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("{\n            .name = \"");
long int strLen_1 = strlen(e);
long int strLen_2 = strlen("\",\n            .evalFn = __Bah_eval_");
long int strLen_3 = strlen(e);
long int strLen_4 = strlen("\n        }");
;                            
                    ____BAH_COMPILER_VAR_186 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_186+currStrOff, "{\n            .name = \"", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_186+currStrOff, e, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_186+currStrOff, "\",\n            .evalFn = __Bah_eval_", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_186+currStrOff, e, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_186+currStrOff, "\n        }", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_186[currStrOff] = 0;
                }
                char * ____BAH_COMPILER_VAR_187 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(evalsTMPDecl);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_186);
;                            
                    ____BAH_COMPILER_VAR_187 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_187+currStrOff, evalsTMPDecl, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_187+currStrOff, ____BAH_COMPILER_VAR_186, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_187[currStrOff] = 0;
                }
                evalsTMPDecl =  ____BAH_COMPILER_VAR_187;
if ((i + 1!=len(compilerState.evals))) {
char * ____BAH_COMPILER_VAR_188 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(evalsTMPDecl);
long int strLen_1 = strlen(",\n");
;                            
                    ____BAH_COMPILER_VAR_188 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_188+currStrOff, evalsTMPDecl, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_188+currStrOff, ",\n", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_188[currStrOff] = 0;
                }
                evalsTMPDecl =  ____BAH_COMPILER_VAR_188;
}
else {
char * ____BAH_COMPILER_VAR_189 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(evalsTMPDecl);
long int strLen_1 = strlen("};");
;                            
                    ____BAH_COMPILER_VAR_189 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_189+currStrOff, evalsTMPDecl, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_189+currStrOff, "};", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_189[currStrOff] = 0;
                }
                evalsTMPDecl =  ____BAH_COMPILER_VAR_189;
}
};
if ((len(compilerState.evals)!=0)) {
char * ____BAH_COMPILER_VAR_190 =intToStr(len(compilerState.evals));char * ____BAH_COMPILER_VAR_191 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("__evals_bindings = __tmp__evals_bindings; __evals_length = ");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_190);
long int strLen_2 = strlen(";");
;                            
                    ____BAH_COMPILER_VAR_191 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_191+currStrOff, "__evals_bindings = __tmp__evals_bindings; __evals_length = ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_191+currStrOff, ____BAH_COMPILER_VAR_190, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_191+currStrOff, ";", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_191[currStrOff] = 0;
                }
                evals =  ____BAH_COMPILER_VAR_191;
}
else {
evalsTMPDecl =  "";
}
char * ____BAH_COMPILER_VAR_192 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n    ");
long int strLen_1 = strlen(evalsTMPDecl);
long int strLen_2 = strlen("\n    void __attribute__((optimize(\"O0\"))) ");
long int strLen_3 = strlen(name);
long int strLen_4 = strlen("() {\n        ");
;                            
                    ____BAH_COMPILER_VAR_192 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_192+currStrOff, "\n    ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_192+currStrOff, evalsTMPDecl, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_192+currStrOff, "\n    void __attribute__((optimize(\"O0\"))) ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_192+currStrOff, name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_192+currStrOff, "() {\n        ", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_192[currStrOff] = 0;
                }
                char * ____BAH_COMPILER_VAR_193 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n        ");
long int strLen_1 = strlen(evals);
long int strLen_2 = strlen("\n    };\n    ");
;                            
                    ____BAH_COMPILER_VAR_193 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_193+currStrOff, "\n        ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_193+currStrOff, evals, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_193+currStrOff, "\n    };\n    ", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_193[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_192))->add(OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_192)), INIT)->add(OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_192))->add(OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_192)), INIT), rope(____BAH_COMPILER_VAR_193));
};
struct rope* decrVar(struct variable* v,struct Elems* elems){
struct rope* r =  rope("");
if (strHasPrefix(v->type,"[]")) {
struct string at =  string(v->type);
at.trimLeft((struct string*)&at,2);
char * ____BAH_COMPILER_VAR_194 =at.str((struct string*)&at);if (isRCPtype(____BAH_COMPILER_VAR_194,elems)) {
struct variable* ____BAH_COMPILER_VAR_195 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_195->name = "";
____BAH_COMPILER_VAR_195->type = "";
____BAH_COMPILER_VAR_195->isConst = false;
____BAH_COMPILER_VAR_195->constVal = "";
____BAH_COMPILER_VAR_195->isArray = false;
____BAH_COMPILER_VAR_195->from = "";
____BAH_COMPILER_VAR_195->outterScope = false;
____BAH_COMPILER_VAR_195->isGlobal = false;
struct variable* arrElem =  ____BAH_COMPILER_VAR_195;
arrElem->type =  at.str((struct string*)&at);
char * ____BAH_COMPILER_VAR_196 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen("->data[arrElemIndex]");
;                            
                    ____BAH_COMPILER_VAR_196 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_196+currStrOff, v->name, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_196+currStrOff, "->data[arrElemIndex]", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_196[currStrOff] = 0;
                }
                arrElem->name =  ____BAH_COMPILER_VAR_196;
char * ____BAH_COMPILER_VAR_197 =null;
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
                    ____BAH_COMPILER_VAR_197 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                    
                    memcpy(____BAH_COMPILER_VAR_197+currStrOff, "\n            {\n            struct RCP * arrRCP = RCP_request(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_197+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_197+currStrOff, ");\n            if (arrRCP != null && arrRCP->c == 1) {\n                struct RCP * arrDataRCP = RCP_request(", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_197+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_197+currStrOff, "->data);\n                if (arrDataRCP != null && arrDataRCP->c == 1) {\n                    for(int arrElemIndex=len(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_197+currStrOff, v->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_197+currStrOff, ")-1; arrElemIndex >= 0; arrElemIndex--) {\n                        ", strLen_6);
                    currStrOff += strLen_6;
                    
                    ____BAH_COMPILER_VAR_197[currStrOff] = 0;
                }
                r =  rope(____BAH_COMPILER_VAR_197)->add(rope(____BAH_COMPILER_VAR_197), decrVar(arrElem,elems))->add(rope(____BAH_COMPILER_VAR_197)->add(rope(____BAH_COMPILER_VAR_197), decrVar(arrElem,elems)), rope("\n                    };\n                }\n                RCP_decrRCP(arrDataRCP);\n            }\n            RCP_decrRCP(arrRCP);\n            };\n            "));
}
else {
char * ____BAH_COMPILER_VAR_198 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n            {\n            struct RCP * arrRCP = RCP_request(");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(");\n            if (arrRCP != null) {\n                if (arrRCP->c == 1) {\n                    struct RCP * arrDataRCP = RCP_request(");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen("->data);\n                    RCP_decrRCP(arrDataRCP);\n                }\n                RCP_decrRCP(arrRCP);\n            }\n            };\n            ");
;                            
                    ____BAH_COMPILER_VAR_198 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_198+currStrOff, "\n            {\n            struct RCP * arrRCP = RCP_request(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_198+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_198+currStrOff, ");\n            if (arrRCP != null) {\n                if (arrRCP->c == 1) {\n                    struct RCP * arrDataRCP = RCP_request(", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_198+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_198+currStrOff, "->data);\n                    RCP_decrRCP(arrDataRCP);\n                }\n                RCP_decrRCP(arrRCP);\n            }\n            };\n            ", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_198[currStrOff] = 0;
                }
                r =  rope(____BAH_COMPILER_VAR_198);
}
}
else if (strHasPrefix(v->type,"chan:")) {
char * ____BAH_COMPILER_VAR_199 =null;
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
                    ____BAH_COMPILER_VAR_199 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                    
                    memcpy(____BAH_COMPILER_VAR_199+currStrOff, "{\n            struct RCP * chanRCP = RCP_request(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_199+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_199+currStrOff, ");\n            if (chanRCP != null && chanRCP->c == 1) {\n                ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_199+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_199+currStrOff, "->destroy(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_199+currStrOff, v->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_199+currStrOff, ");\n                RCP_decr(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_199+currStrOff, v->name, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_199+currStrOff, "->queue);\n            };\n            RCP_decrRCP(chanRCP);\n        };", strLen_8);
                    currStrOff += strLen_8;
                    
                    ____BAH_COMPILER_VAR_199[currStrOff] = 0;
                }
                r =  rope(____BAH_COMPILER_VAR_199);
}
else {
if (strHasPrefix(v->type,"map:")) {
struct variable* ____BAH_COMPILER_VAR_200 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_200->name = "";
____BAH_COMPILER_VAR_200->type = "";
____BAH_COMPILER_VAR_200->isConst = false;
____BAH_COMPILER_VAR_200->constVal = "";
____BAH_COMPILER_VAR_200->isArray = false;
____BAH_COMPILER_VAR_200->from = "";
____BAH_COMPILER_VAR_200->outterScope = false;
____BAH_COMPILER_VAR_200->isGlobal = false;
struct variable* nv =  ____BAH_COMPILER_VAR_200;
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
char * ____BAH_COMPILER_VAR_201 =null;
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
                    ____BAH_COMPILER_VAR_201 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7);
                    
                    memcpy(____BAH_COMPILER_VAR_201+currStrOff, "__RCP_clean_", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_201+currStrOff, s->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_201+currStrOff, "(", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_201+currStrOff, amp, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_201+currStrOff, v->name, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_201+currStrOff, ", ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_201+currStrOff, heap, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_201+currStrOff, ");\n", strLen_7);
                    currStrOff += strLen_7;
                    
                    ____BAH_COMPILER_VAR_201[currStrOff] = 0;
                }
                r =  r->add(r, rope(____BAH_COMPILER_VAR_201));
}
else if ((isPointer==true)) {
char * ____BAH_COMPILER_VAR_202 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("RCP_decr(");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(");\n");
;                            
                    ____BAH_COMPILER_VAR_202 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_202+currStrOff, "RCP_decr(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_202+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_202+currStrOff, ");\n", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_202[currStrOff] = 0;
                }
                r =  r->add(r, rope(____BAH_COMPILER_VAR_202));
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
char * ____BAH_COMPILER_VAR_203 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("RCP_incrCounter(");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(".__RCP_counter);");
;                            
                    ____BAH_COMPILER_VAR_203 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_203+currStrOff, "RCP_incrCounter(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_203+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_203+currStrOff, ".__RCP_counter);", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_203[currStrOff] = 0;
                }
                return rope(____BAH_COMPILER_VAR_203);
}
char * ____BAH_COMPILER_VAR_204 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("RCP_incr(");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(");");
;                            
                    ____BAH_COMPILER_VAR_204 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_204+currStrOff, "RCP_incr(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_204+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_204+currStrOff, ");", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_204[currStrOff] = 0;
                }
                return rope(____BAH_COMPILER_VAR_204);
};
char RCPavailable(){
char * ____BAH_COMPILER_VAR_205 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen("rcp.bah");
;                            
                    ____BAH_COMPILER_VAR_205 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_205+currStrOff, BAH_DIR, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_205+currStrOff, "rcp.bah", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_205[currStrOff] = 0;
                }
                char * ____BAH_COMPILER_VAR_206 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen("fastrcp.bah");
;                            
                    ____BAH_COMPILER_VAR_206 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_206+currStrOff, BAH_DIR, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_206+currStrOff, "fastrcp.bah", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_206[currStrOff] = 0;
                }
                return (((strcmp(absPath(compilerState.currentFile), absPath(____BAH_COMPILER_VAR_205)) != 0)&&(strcmp(absPath(compilerState.currentFile), absPath(____BAH_COMPILER_VAR_206)) != 0))&&(RCPenabled==true));
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
struct variable* ____BAH_COMPILER_VAR_207 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_207->name = "";
____BAH_COMPILER_VAR_207->type = "";
____BAH_COMPILER_VAR_207->isConst = false;
____BAH_COMPILER_VAR_207->constVal = "";
____BAH_COMPILER_VAR_207->isArray = false;
____BAH_COMPILER_VAR_207->from = "";
____BAH_COMPILER_VAR_207->outterScope = false;
____BAH_COMPILER_VAR_207->isGlobal = false;
struct variable* av =  ____BAH_COMPILER_VAR_207;
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
char * ____BAH_COMPILER_VAR_208 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_209 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_208);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(av->name);
long int strLen_3 = strlen(" =");
long int strLen_4 = strlen(c);
long int strLen_5 = strlen(";");
;                            
                    ____BAH_COMPILER_VAR_209 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    memcpy(____BAH_COMPILER_VAR_209+currStrOff, ____BAH_COMPILER_VAR_208, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_209+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_209+currStrOff, av->name, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_209+currStrOff, " =", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_209+currStrOff, c, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_209+currStrOff, ";", strLen_5);
                    currStrOff += strLen_5;
                    
                    ____BAH_COMPILER_VAR_209[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_209));
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
struct variable* ____BAH_COMPILER_VAR_210 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_210->name = "";
____BAH_COMPILER_VAR_210->type = "";
____BAH_COMPILER_VAR_210->isConst = false;
____BAH_COMPILER_VAR_210->constVal = "";
____BAH_COMPILER_VAR_210->isArray = false;
____BAH_COMPILER_VAR_210->from = "";
____BAH_COMPILER_VAR_210->outterScope = false;
____BAH_COMPILER_VAR_210->isGlobal = false;
struct variable* mv =  ____BAH_COMPILER_VAR_210;
char * ____BAH_COMPILER_VAR_211 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("e->");
long int strLen_1 = strlen(m->name);
;                            
                    ____BAH_COMPILER_VAR_211 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_211+currStrOff, "e->", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_211+currStrOff, m->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_211[currStrOff] = 0;
                }
                mv->name =  ____BAH_COMPILER_VAR_211;
mv->type =  m->type;
decrMembs =  decrMembs->add(decrMembs, decrVar(mv,elems));
}
else {
char * ____BAH_COMPILER_VAR_212 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Strcture '");
long int strLen_1 = strlen(s->name);
long int strLen_2 = strlen("' has a self-referenced member '");
long int strLen_3 = strlen(m->name);
long int strLen_4 = strlen("'. May lead to memory leaks, recompile the program without the '-rcp' flag if memory leaks happens.");
;                            
                    ____BAH_COMPILER_VAR_212 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_212+currStrOff, "Strcture '", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_212+currStrOff, s->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_212+currStrOff, "' has a self-referenced member '", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_212+currStrOff, m->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_212+currStrOff, "'. May lead to memory leaks, recompile the program without the '-rcp' flag if memory leaks happens.", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_212[currStrOff] = 0;
                }
                throwWarning(____BAH_COMPILER_VAR_212);
char * amp =  "&";
char * heap =  "0";
if ((strCount(m->type,"*")>0)) {
amp =  "";
heap =  "1";
}
char * ____BAH_COMPILER_VAR_213 =null;
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
                    ____BAH_COMPILER_VAR_213 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                    
                    memcpy(____BAH_COMPILER_VAR_213+currStrOff, "__RCP_clean_", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_213+currStrOff, s->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_213+currStrOff, "(", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_213+currStrOff, amp, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_213+currStrOff, "e->", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_213+currStrOff, m->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_213+currStrOff, ", ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_213+currStrOff, heap, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_213+currStrOff, ");\n", strLen_8);
                    currStrOff += strLen_8;
                    
                    ____BAH_COMPILER_VAR_213[currStrOff] = 0;
                }
                decrMembs =  decrMembs->add(decrMembs, rope(____BAH_COMPILER_VAR_213));
}
}
i =  i + 1;
};
char * ____BAH_COMPILER_VAR_214 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("void* __RCP_clean_");
long int strLen_1 = strlen(s->name);
long int strLen_2 = strlen("(struct ");
long int strLen_3 = strlen(s->name);
long int strLen_4 = strlen("* e, int heap) {\n        if(heap == 1) {\n            struct RCP* srcp = RCP_request(e);\n            if (srcp != null) {\n                if (srcp->c == 1) {\n                    ");
;                            
                    ____BAH_COMPILER_VAR_214 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_214+currStrOff, "void* __RCP_clean_", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_214+currStrOff, s->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_214+currStrOff, "(struct ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_214+currStrOff, s->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_214+currStrOff, "* e, int heap) {\n        if(heap == 1) {\n            struct RCP* srcp = RCP_request(e);\n            if (srcp != null) {\n                if (srcp->c == 1) {\n                    ", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_214[currStrOff] = 0;
                }
                struct rope* r =  rope(____BAH_COMPILER_VAR_214)->add(rope(____BAH_COMPILER_VAR_214), decrMembs)->add(rope(____BAH_COMPILER_VAR_214)->add(rope(____BAH_COMPILER_VAR_214), decrMembs), rope("\n                }\n                RCP_decrRCP(srcp);\n            }\n        } else if(RCP_decrCounter((void*)e->__RCP_counter)==0) {\n            "))->add(rope(____BAH_COMPILER_VAR_214)->add(rope(____BAH_COMPILER_VAR_214), decrMembs)->add(rope(____BAH_COMPILER_VAR_214)->add(rope(____BAH_COMPILER_VAR_214), decrMembs), rope("\n                }\n                RCP_decrRCP(srcp);\n            }\n        } else if(RCP_decrCounter((void*)e->__RCP_counter)==0) {\n            ")), decrMembs)->add(rope(____BAH_COMPILER_VAR_214)->add(rope(____BAH_COMPILER_VAR_214), decrMembs)->add(rope(____BAH_COMPILER_VAR_214)->add(rope(____BAH_COMPILER_VAR_214), decrMembs), rope("\n                }\n                RCP_decrRCP(srcp);\n            }\n        } else if(RCP_decrCounter((void*)e->__RCP_counter)==0) {\n            "))->add(rope(____BAH_COMPILER_VAR_214)->add(rope(____BAH_COMPILER_VAR_214), decrMembs)->add(rope(____BAH_COMPILER_VAR_214)->add(rope(____BAH_COMPILER_VAR_214), decrMembs), rope("\n                }\n                RCP_decrRCP(srcp);\n            }\n        } else if(RCP_decrCounter((void*)e->__RCP_counter)==0) {\n            ")), decrMembs), rope("\n        }\n    };\n"));
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

                int ____BAH_COMPILER_VAR_215 = 0;
                for(int i=len(noVOfns)-1; i != -1; i--) {
                    if (noVOfns->data[i] != 0 && strcmp(noVOfns->data[i], currentFn->name) == 0) {
                        ____BAH_COMPILER_VAR_215 = 1;
                        break;
                    };
                };
                if (____BAH_COMPILER_VAR_215) {
return false;
}
}
return true;
};
struct verboseOutVar verboseOutTransformVar(struct variable* v,char * cont,struct Elems* elems){
struct verboseOutVar ____BAH_COMPILER_VAR_216 = {};
____BAH_COMPILER_VAR_216.markup= null;
____BAH_COMPILER_VAR_216.content= null;
struct verboseOutVar rv =  ____BAH_COMPILER_VAR_216;
char * ogCont =  cont;
if ((strcmp(v->type, "cpstring") == 0)) {
char * ____BAH_COMPILER_VAR_217 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("__Bah_safe_string(");
long int strLen_1 = strlen(cont);
long int strLen_2 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_217 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_217+currStrOff, "__Bah_safe_string(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_217+currStrOff, cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_217+currStrOff, ")", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_217[currStrOff] = 0;
                }
                cont =  ____BAH_COMPILER_VAR_217;
}
char * ____BAH_COMPILER_VAR_218 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(", ");
long int strLen_1 = strlen(cont);
;                            
                    ____BAH_COMPILER_VAR_218 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_218+currStrOff, ", ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_218+currStrOff, cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_218[currStrOff] = 0;
                }
                cont =  ____BAH_COMPILER_VAR_218;
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
char * ____BAH_COMPILER_VAR_219 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ASCII_RESET);
long int strLen_1 = strlen("{");
;                            
                    ____BAH_COMPILER_VAR_219 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_219+currStrOff, ASCII_RESET, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_219+currStrOff, "{", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_219[currStrOff] = 0;
                }
                ct =  ____BAH_COMPILER_VAR_219;
cont =  "";
long int i =  0;
for (; (i<len(s->members)); i =  i+1) {

                    if (s->members->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/verboseOut.bah:53): s->members[%d] with length %d\n", i, s->members->length);
                        exit(1);
                    };
                    struct variable* m =  s->members->data[i];
char * ____BAH_COMPILER_VAR_220 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("(");
long int strLen_1 = strlen(ogCont);
long int strLen_2 = strlen(")");
long int strLen_3 = strlen(".");
long int strLen_4 = strlen(m->name);
;                            
                    ____BAH_COMPILER_VAR_220 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_220+currStrOff, "(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_220+currStrOff, ogCont, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_220+currStrOff, ")", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_220+currStrOff, ".", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_220+currStrOff, m->name, strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_220[currStrOff] = 0;
                }
                struct verboseOutVar mv =  verboseOutTransformVar(m,____BAH_COMPILER_VAR_220,elems);
if ((i!=0)) {
char * ____BAH_COMPILER_VAR_221 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ct);
long int strLen_1 = strlen(", ");
;                            
                    ____BAH_COMPILER_VAR_221 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_221+currStrOff, ct, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_221+currStrOff, ", ", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_221[currStrOff] = 0;
                }
                ct =  ____BAH_COMPILER_VAR_221;
}
char * ____BAH_COMPILER_VAR_222 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ct);
long int strLen_1 = strlen(mv.markup);
;                            
                    ____BAH_COMPILER_VAR_222 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_222+currStrOff, ct, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_222+currStrOff, mv.markup, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_222[currStrOff] = 0;
                }
                ct =  ____BAH_COMPILER_VAR_222;
char * ____BAH_COMPILER_VAR_223 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(cont);
long int strLen_1 = strlen(mv.content);
;                            
                    ____BAH_COMPILER_VAR_223 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_223+currStrOff, cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_223+currStrOff, mv.content, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_223[currStrOff] = 0;
                }
                cont =  ____BAH_COMPILER_VAR_223;
};
char * ____BAH_COMPILER_VAR_224 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ct);
long int strLen_1 = strlen("}");
;                            
                    ____BAH_COMPILER_VAR_224 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_224+currStrOff, ct, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_224+currStrOff, "}", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_224[currStrOff] = 0;
                }
                ct =  ____BAH_COMPILER_VAR_224;
}
}
char * ____BAH_COMPILER_VAR_225 =null;
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
                    ____BAH_COMPILER_VAR_225 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                    
                    memcpy(____BAH_COMPILER_VAR_225+currStrOff, ASCII_BLUE, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_225+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_225+currStrOff, ASCII_RESET, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_225+currStrOff, " = ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_225+currStrOff, ASCII_MAGENTA, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_225+currStrOff, ct, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_225+currStrOff, ASCII_RESET, strLen_6);
                    currStrOff += strLen_6;
                    
                    ____BAH_COMPILER_VAR_225[currStrOff] = 0;
                }
                rv.markup =  ____BAH_COMPILER_VAR_225;
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
struct variable ____BAH_COMPILER_VAR_226 = {};
____BAH_COMPILER_VAR_226.name = "";
____BAH_COMPILER_VAR_226.type = "";
____BAH_COMPILER_VAR_226.isConst = false;
____BAH_COMPILER_VAR_226.constVal = "";
____BAH_COMPILER_VAR_226.isArray = false;
____BAH_COMPILER_VAR_226.from = "";
____BAH_COMPILER_VAR_226.outterScope = false;
____BAH_COMPILER_VAR_226.isGlobal = false;
____BAH_COMPILER_VAR_226.name = "(value)";
____BAH_COMPILER_VAR_226.type = getTypeFromToken(&t,true,elems);
struct variable v =  ____BAH_COMPILER_VAR_226;
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
char * ____BAH_COMPILER_VAR_227 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(fnArgs);
long int strLen_1 = strlen(", ");
;                            
                    ____BAH_COMPILER_VAR_227 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_227+currStrOff, fnArgs, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_227+currStrOff, ", ", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_227[currStrOff] = 0;
                }
                fnArgs =  ____BAH_COMPILER_VAR_227;
}

                    if (args->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/verboseOut.bah:120): args[%d] with length %d\n", j, args->length);
                        exit(1);
                    };
                    struct Tok t =  args->data[j];
struct verboseOutVar v =  verboseOutTransformVar(a,t.cont,elems);
char * ____BAH_COMPILER_VAR_228 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(fnArgs);
long int strLen_1 = strlen(v.markup);
;                            
                    ____BAH_COMPILER_VAR_228 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_228+currStrOff, fnArgs, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_228+currStrOff, v.markup, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_228[currStrOff] = 0;
                }
                fnArgs =  ____BAH_COMPILER_VAR_228;
char * ____BAH_COMPILER_VAR_229 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(fnArgsValues);
long int strLen_1 = strlen(v.content);
;                            
                    ____BAH_COMPILER_VAR_229 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_229+currStrOff, fnArgsValues, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_229+currStrOff, v.content, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_229[currStrOff] = 0;
                }
                fnArgsValues =  ____BAH_COMPILER_VAR_229;
};
char * ____BAH_COMPILER_VAR_230 =intToStr(lineNb);char * ____BAH_COMPILER_VAR_231 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(compilerState.currentFile);
long int strLen_1 = strlen(":");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_230);
;                            
                    ____BAH_COMPILER_VAR_231 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_231+currStrOff, compilerState.currentFile, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_231+currStrOff, ":", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_231+currStrOff, ____BAH_COMPILER_VAR_230, strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_231[currStrOff] = 0;
                }
                char * line =  ____BAH_COMPILER_VAR_231;
char * ____BAH_COMPILER_VAR_232 =null;
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
                    ____BAH_COMPILER_VAR_232 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12);
                    
                    memcpy(____BAH_COMPILER_VAR_232+currStrOff, "\n    //Verbose Runtime\n        printf(\"[VO] calling: ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_232+currStrOff, nameColor, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_232+currStrOff, fn->name, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_232+currStrOff, ASCII_RESET, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_232+currStrOff, "(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_232+currStrOff, fnArgs, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_232+currStrOff, ") -> ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_232+currStrOff, ASCII_GREEN, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_232+currStrOff, line, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_232+currStrOff, ASCII_RESET, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_232+currStrOff, "\\n\"", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_232+currStrOff, fnArgsValues, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_232+currStrOff, ");\n    //\n    ", strLen_12);
                    currStrOff += strLen_12;
                    
                    ____BAH_COMPILER_VAR_232[currStrOff] = 0;
                }
                struct rope* verboseOut =  rope(____BAH_COMPILER_VAR_232);
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
char * ____BAH_COMPILER_VAR_233 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(pvo.content);
long int strLen_1 = strlen(nvo.content);
;                            
                    ____BAH_COMPILER_VAR_233 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_233+currStrOff, pvo.content, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_233+currStrOff, nvo.content, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_233[currStrOff] = 0;
                }
                char * values =  ____BAH_COMPILER_VAR_233;
char * ____BAH_COMPILER_VAR_234 =intToStr(lineNb);char * ____BAH_COMPILER_VAR_235 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(compilerState.currentFile);
long int strLen_1 = strlen(":");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_234);
;                            
                    ____BAH_COMPILER_VAR_235 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_235+currStrOff, compilerState.currentFile, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_235+currStrOff, ":", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_235+currStrOff, ____BAH_COMPILER_VAR_234, strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_235[currStrOff] = 0;
                }
                char * line =  ____BAH_COMPILER_VAR_235;
char * ____BAH_COMPILER_VAR_236 =null;
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
                    ____BAH_COMPILER_VAR_236 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10);
                    
                    memcpy(____BAH_COMPILER_VAR_236+currStrOff, "\n    //Verbose Runtime\n        printf(\"[VO]    oper: ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_236+currStrOff, pvo.markup, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_236+currStrOff, " AND ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_236+currStrOff, nvo.markup, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_236+currStrOff, " -> ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_236+currStrOff, ASCII_GREEN, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_236+currStrOff, line, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_236+currStrOff, ASCII_RESET, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_236+currStrOff, "\\n\"", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_236+currStrOff, values, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_236+currStrOff, ");\n    //\n    ", strLen_10);
                    currStrOff += strLen_10;
                    
                    ____BAH_COMPILER_VAR_236[currStrOff] = 0;
                }
                struct rope* verboseOut =  rope(____BAH_COMPILER_VAR_236);
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
struct fileStream ____BAH_COMPILER_VAR_237 = {};
____BAH_COMPILER_VAR_237.handle= null;
____BAH_COMPILER_VAR_237.isValid = fileStream__isValid;
____BAH_COMPILER_VAR_237.open = fileStream__open;
____BAH_COMPILER_VAR_237.close = fileStream__close;
____BAH_COMPILER_VAR_237.getPos = fileStream__getPos;
____BAH_COMPILER_VAR_237.setPos = fileStream__setPos;
____BAH_COMPILER_VAR_237.getSize = fileStream__getSize;
____BAH_COMPILER_VAR_237.rewind = fileStream__rewind;
____BAH_COMPILER_VAR_237.getChar = fileStream__getChar;
____BAH_COMPILER_VAR_237.setChar = fileStream__setChar;
____BAH_COMPILER_VAR_237.createFile = fileStream__createFile;
____BAH_COMPILER_VAR_237.writeFile = fileStream__writeFile;
____BAH_COMPILER_VAR_237.writePtr = fileStream__writePtr;
____BAH_COMPILER_VAR_237.readPtr = fileStream__readPtr;
____BAH_COMPILER_VAR_237.readContent = fileStream__readContent;
____BAH_COMPILER_VAR_237.readBytes = fileStream__readBytes;
____BAH_COMPILER_VAR_237.writeBytes = fileStream__writeBytes;
struct fileStream fs =  ____BAH_COMPILER_VAR_237;
char * ____BAH_COMPILER_VAR_238 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen("cache/cache.json");
;                            
                    ____BAH_COMPILER_VAR_238 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_238+currStrOff, BAH_DIR, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_238+currStrOff, "cache/cache.json", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_238[currStrOff] = 0;
                }
                fs.open((struct fileStream*)&fs,____BAH_COMPILER_VAR_238,"r");
if ((fs.isValid((struct fileStream*)&fs)==0)) {
char * ____BAH_COMPILER_VAR_239 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen("cache");
;                            
                    ____BAH_COMPILER_VAR_239 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_239+currStrOff, BAH_DIR, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_239+currStrOff, "cache", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_239[currStrOff] = 0;
                }
                mkdir(____BAH_COMPILER_VAR_239,S_IRWXU);
char * ____BAH_COMPILER_VAR_240 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen("cache/cache.json");
;                            
                    ____BAH_COMPILER_VAR_240 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_240+currStrOff, BAH_DIR, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_240+currStrOff, "cache/cache.json", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_240[currStrOff] = 0;
                }
                fs.createFile((struct fileStream*)&fs,____BAH_COMPILER_VAR_240);
return;
}
char * ____BAH_COMPILER_VAR_241 =fs.readContent((struct fileStream*)&fs);struct jsonElement* j =  parseJson(____BAH_COMPILER_VAR_241);
fs.close((struct fileStream*)&fs);
array(struct cacheFile**)* ____BAH_COMPILER_VAR_242 = &cache;
struct cacheFile*** ____BAH_COMPILER_VAR_243 = 0;
char ** ____BAH_COMPILER_VAR_245 = (char **)((char*)(____BAH_COMPILER_VAR_243) + offsetof(struct cacheFile, file));
struct reflectElement ____BAH_COMPILER_VAR_246 = __reflect(____BAH_COMPILER_VAR_245, sizeof(char *), "cpstring", "file", 0, 0, 0, 0, offsetof(struct cacheFile, file));
long int* ____BAH_COMPILER_VAR_247 = (long int*)((char*)(____BAH_COMPILER_VAR_243) + offsetof(struct cacheFile, last));
struct reflectElement ____BAH_COMPILER_VAR_248 = __reflect(____BAH_COMPILER_VAR_247, sizeof(long int), "int", "last", 0, 0, 0, 0, offsetof(struct cacheFile, last));
char ** ____BAH_COMPILER_VAR_249 = (char **)((char*)(____BAH_COMPILER_VAR_243) + offsetof(struct cacheFile, ver));
struct reflectElement ____BAH_COMPILER_VAR_250 = __reflect(____BAH_COMPILER_VAR_249, sizeof(char *), "cpstring", "ver", 0, 0, 0, 0, offsetof(struct cacheFile, ver));
long int* ____BAH_COMPILER_VAR_251 = (long int*)((char*)(____BAH_COMPILER_VAR_243) + offsetof(struct cacheFile, date));
struct reflectElement ____BAH_COMPILER_VAR_252 = __reflect(____BAH_COMPILER_VAR_251, sizeof(long int), "int", "date", 0, 0, 0, 0, offsetof(struct cacheFile, date));
long int* ____BAH_COMPILER_VAR_253 = (long int*)((char*)(____BAH_COMPILER_VAR_243) + offsetof(struct cacheFile, mem));
struct reflectElement ____BAH_COMPILER_VAR_254 = __reflect(____BAH_COMPILER_VAR_253, sizeof(long int), "int", "mem", 0, 0, 0, 0, offsetof(struct cacheFile, mem));
array(char *)** ____BAH_COMPILER_VAR_255 = (array(char *)**)((char*)(____BAH_COMPILER_VAR_243) + offsetof(struct cacheFile, files));
char ** ____BAH_COMPILER_VAR_256 = 0;
struct reflectElement ____BAH_COMPILER_VAR_257 = __reflect(____BAH_COMPILER_VAR_256, sizeof(char *), "cpstring", "", 0, 0, 0, 0, 0);

        struct reflectElement ____BAH_COMPILER_VAR_258 = ____BAH_COMPILER_VAR_257;
        struct reflectElement ____BAH_COMPILER_VAR_259 = __reflect(____BAH_COMPILER_VAR_255, sizeof(array(char *)*), "[]cpstring", "files", 1, &____BAH_COMPILER_VAR_258, 0, 0, offsetof(struct cacheFile, files));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_244 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_244->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_244->length = 6;
        ____BAH_COMPILER_VAR_244->data = memoryAlloc(____BAH_COMPILER_VAR_244->length * ____BAH_COMPILER_VAR_244->elemSize);
        ____BAH_COMPILER_VAR_244->data[0] = ____BAH_COMPILER_VAR_246;
____BAH_COMPILER_VAR_244->data[1] = ____BAH_COMPILER_VAR_248;
____BAH_COMPILER_VAR_244->data[2] = ____BAH_COMPILER_VAR_250;
____BAH_COMPILER_VAR_244->data[3] = ____BAH_COMPILER_VAR_252;
____BAH_COMPILER_VAR_244->data[4] = ____BAH_COMPILER_VAR_254;
____BAH_COMPILER_VAR_244->data[5] = ____BAH_COMPILER_VAR_259;
struct reflectElement ____BAH_COMPILER_VAR_260 = __reflect(____BAH_COMPILER_VAR_243, sizeof(struct cacheFile), "cacheFile**", "", 0, 0, 1, ____BAH_COMPILER_VAR_244, 0);

        struct reflectElement ____BAH_COMPILER_VAR_261 = ____BAH_COMPILER_VAR_260;
        struct reflectElement ____BAH_COMPILER_VAR_262 = __reflect(____BAH_COMPILER_VAR_242, sizeof(array(struct cacheFile**)*), "[]cacheFile**", "&cache", 1, &____BAH_COMPILER_VAR_261, 0, 0, 0);
j->scan((struct jsonElement*)j,____BAH_COMPILER_VAR_262);
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
struct cacheFile* ____BAH_COMPILER_VAR_263 = memoryAlloc(sizeof(struct cacheFile));
____BAH_COMPILER_VAR_263->file= null;
____BAH_COMPILER_VAR_263->ver= null;
____BAH_COMPILER_VAR_263->files = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_263->files->length = 0;
            ____BAH_COMPILER_VAR_263->files->elemSize = sizeof(char *);
            struct cacheFile* c =  ____BAH_COMPILER_VAR_263;
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
struct fileStream ____BAH_COMPILER_VAR_264 = {};
____BAH_COMPILER_VAR_264.handle= null;
____BAH_COMPILER_VAR_264.isValid = fileStream__isValid;
____BAH_COMPILER_VAR_264.open = fileStream__open;
____BAH_COMPILER_VAR_264.close = fileStream__close;
____BAH_COMPILER_VAR_264.getPos = fileStream__getPos;
____BAH_COMPILER_VAR_264.setPos = fileStream__setPos;
____BAH_COMPILER_VAR_264.getSize = fileStream__getSize;
____BAH_COMPILER_VAR_264.rewind = fileStream__rewind;
____BAH_COMPILER_VAR_264.getChar = fileStream__getChar;
____BAH_COMPILER_VAR_264.setChar = fileStream__setChar;
____BAH_COMPILER_VAR_264.createFile = fileStream__createFile;
____BAH_COMPILER_VAR_264.writeFile = fileStream__writeFile;
____BAH_COMPILER_VAR_264.writePtr = fileStream__writePtr;
____BAH_COMPILER_VAR_264.readPtr = fileStream__readPtr;
____BAH_COMPILER_VAR_264.readContent = fileStream__readContent;
____BAH_COMPILER_VAR_264.readBytes = fileStream__readBytes;
____BAH_COMPILER_VAR_264.writeBytes = fileStream__writeBytes;
struct fileStream fs =  ____BAH_COMPILER_VAR_264;
char * ____BAH_COMPILER_VAR_265 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen("cache/cache.json");
;                            
                    ____BAH_COMPILER_VAR_265 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_265+currStrOff, BAH_DIR, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_265+currStrOff, "cache/cache.json", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_265[currStrOff] = 0;
                }
                fs.open((struct fileStream*)&fs,____BAH_COMPILER_VAR_265,"w");
array(struct cacheFile*)* ____BAH_COMPILER_VAR_266 = cache;
struct cacheFile** ____BAH_COMPILER_VAR_267 = 0;
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
struct reflectElement ____BAH_COMPILER_VAR_284 = __reflect(____BAH_COMPILER_VAR_267, sizeof(struct cacheFile), "cacheFile*", "", 0, 0, 1, ____BAH_COMPILER_VAR_268, 0);

        struct reflectElement ____BAH_COMPILER_VAR_285 = ____BAH_COMPILER_VAR_284;
        struct reflectElement ____BAH_COMPILER_VAR_286 = __reflect(____BAH_COMPILER_VAR_266, sizeof(array(struct cacheFile*)*), "[]cacheFile*", "cache", 1, &____BAH_COMPILER_VAR_285, 0, 0, 0);
char * ____BAH_COMPILER_VAR_287 =toJson(____BAH_COMPILER_VAR_286);fs.writeFile((struct fileStream*)&fs,____BAH_COMPILER_VAR_287);
fs.close((struct fileStream*)&fs);
};
char isValidCacheFile(struct cacheFile* cf){
if (((cf==null)||(cf->last!=getLastModified(cf->file)))) {
return false;
}
char * ____BAH_COMPILER_VAR_288 =pathToVarName(cf->file);char * ____BAH_COMPILER_VAR_289 =intToStr(cf->mem);char * ____BAH_COMPILER_VAR_290 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen("cache/");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_288);
long int strLen_3 = strlen(____BAH_COMPILER_VAR_289);
long int strLen_4 = strlen(".o.o");
;                            
                    ____BAH_COMPILER_VAR_290 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_290+currStrOff, BAH_DIR, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_290+currStrOff, "cache/", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_290+currStrOff, ____BAH_COMPILER_VAR_288, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_290+currStrOff, ____BAH_COMPILER_VAR_289, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_290+currStrOff, ".o.o", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_290[currStrOff] = 0;
                }
                if ((fileExists(____BAH_COMPILER_VAR_290)==0)) {
return false;
}
if ((strcmp(cf->ver, BAH_VERSION) != 0)) {
return false;
}
return true;
};
//optimized out: debugLine
struct Elems* dupElems(struct Elems* elems){
struct Elems* ____BAH_COMPILER_VAR_292 = memoryAlloc(sizeof(struct Elems));
____BAH_COMPILER_VAR_292->vars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_292->vars->length = 0;
            ____BAH_COMPILER_VAR_292->vars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_292->structs = memoryAlloc(sizeof(array(struct cStruct*)));
            ____BAH_COMPILER_VAR_292->structs->length = 0;
            ____BAH_COMPILER_VAR_292->structs->elemSize = sizeof(struct cStruct*);
            ____BAH_COMPILER_VAR_292->types = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_292->types->length = 0;
            ____BAH_COMPILER_VAR_292->types->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_292->fns = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_292->fns->length = 0;
            ____BAH_COMPILER_VAR_292->fns->elemSize = sizeof(struct func*);
            struct Elems* nElems =  ____BAH_COMPILER_VAR_292;
long int j =  0;
for (; (j<len(elems->vars)); j =  j+1) {

                    if (elems->vars->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:29): elems->vars[%d] with length %d\n", j, elems->vars->length);
                        exit(1);
                    };
                    struct variable* v =  elems->vars->data[j];
struct variable* ____BAH_COMPILER_VAR_293 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_293->name = "";
____BAH_COMPILER_VAR_293->type = "";
____BAH_COMPILER_VAR_293->isConst = false;
____BAH_COMPILER_VAR_293->constVal = "";
____BAH_COMPILER_VAR_293->isArray = false;
____BAH_COMPILER_VAR_293->from = "";
____BAH_COMPILER_VAR_293->outterScope = false;
____BAH_COMPILER_VAR_293->isGlobal = false;
struct variable* nv =  ____BAH_COMPILER_VAR_293;
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
char * ____BAH_COMPILER_VAR_294 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("(");
long int strLen_1 = strlen(cCastStr);
long int strLen_2 = strlen(")");
long int strLen_3 = strlen(nnnt.cont);
;                            
                    ____BAH_COMPILER_VAR_294 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                    
                    memcpy(____BAH_COMPILER_VAR_294+currStrOff, "(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_294+currStrOff, cCastStr, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_294+currStrOff, ")", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_294+currStrOff, nnnt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    ____BAH_COMPILER_VAR_294[currStrOff] = 0;
                }
                nnnt.cont =  ____BAH_COMPILER_VAR_294;

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
char * ____BAH_COMPILER_VAR_295 =__STR(f);array(char)* p =  strAsArr(____BAH_COMPILER_VAR_295);
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

                int ____BAH_COMPILER_VAR_296 = 0;
                for(int i=len(compilerState.includes)-1; i != -1; i--) {
                    if (compilerState.includes->data[i] != 0 && strcmp(compilerState.includes->data[i], ccstr) == 0) {
                        ____BAH_COMPILER_VAR_296 = 1;
                        break;
                    };
                };
                if (____BAH_COMPILER_VAR_296) {
return true;
}
struct fileMap ____BAH_COMPILER_VAR_297 = {};
____BAH_COMPILER_VAR_297.handle = -1;
____BAH_COMPILER_VAR_297.p= null;
____BAH_COMPILER_VAR_297.open = fileMap__open;
____BAH_COMPILER_VAR_297.isValid = fileMap__isValid;
____BAH_COMPILER_VAR_297.close = fileMap__close;
struct fileMap fm =  ____BAH_COMPILER_VAR_297;
char * ____BAH_COMPILER_VAR_298 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen(ccstr);
;                            
                    ____BAH_COMPILER_VAR_298 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_298+currStrOff, BAH_DIR, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_298+currStrOff, ccstr, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_298[currStrOff] = 0;
                }
                char * fileName =  ____BAH_COMPILER_VAR_298;
char isBahDir =  true;
char * f =  fm.open((struct fileMap*)&fm,fileName);
if ((fm.isValid((struct fileMap*)&fm)==0)) {
char * ____BAH_COMPILER_VAR_299 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(compilerState.currentDir);
long int strLen_1 = strlen(ccstr);
;                            
                    ____BAH_COMPILER_VAR_299 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_299+currStrOff, compilerState.currentDir, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_299+currStrOff, ccstr, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_299[currStrOff] = 0;
                }
                fileName =  absPath(____BAH_COMPILER_VAR_299);
f =  fm.open((struct fileMap*)&fm,fileName);
isBahDir =  false;
if ((fm.isValid((struct fileMap*)&fm)==0)) {
return false;
}
}
char * oDir =  compilerState.currentDir;
if ((isBahDir==false)) {
char * ____BAH_COMPILER_VAR_300 =getDirFromFile(ccstr);char * ____BAH_COMPILER_VAR_301 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(compilerState.currentDir);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_300);
;                            
                    ____BAH_COMPILER_VAR_301 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_301+currStrOff, compilerState.currentDir, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_301+currStrOff, ____BAH_COMPILER_VAR_300, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_301[currStrOff] = 0;
                }
                compilerState.currentDir =  ____BAH_COMPILER_VAR_301;
}
else {
char * ____BAH_COMPILER_VAR_302 =getDirFromFile(ccstr);char * ____BAH_COMPILER_VAR_303 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_302);
;                            
                    ____BAH_COMPILER_VAR_303 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_303+currStrOff, BAH_DIR, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_303+currStrOff, ____BAH_COMPILER_VAR_302, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_303[currStrOff] = 0;
                }
                compilerState.currentDir =  ____BAH_COMPILER_VAR_303;
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
char * ____BAH_COMPILER_VAR_304 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("File '");
long int strLen_1 = strlen(ccstr);
long int strLen_2 = strlen("' not recognized.");
;                            
                    ____BAH_COMPILER_VAR_304 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_304+currStrOff, "File '", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_304+currStrOff, ccstr, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_304+currStrOff, "' not recognized.", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_304[currStrOff] = 0;
                }
                __BAH_panic(____BAH_COMPILER_VAR_304,"/home/alois/Documents/bah-bah/src/parser.bah:246");
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
char * ____BAH_COMPILER_VAR_305 =null;
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
                    ____BAH_COMPILER_VAR_305 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                    
                    memcpy(____BAH_COMPILER_VAR_305+currStrOff, execName, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_305+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_305+currStrOff, fn, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_305+currStrOff, " ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_305+currStrOff, rcp, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_305+currStrOff, " -object ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_305+currStrOff, verboseCC, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_305+currStrOff, " -o ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_305+currStrOff, oName, strLen_8);
                    currStrOff += strLen_8;
                    
                    ____BAH_COMPILER_VAR_305[currStrOff] = 0;
                }
                struct command cmd =  command(____BAH_COMPILER_VAR_305);
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

                    char ____BAH_COMPILER_VAR_306 = true;
                    done->sendAny(done, &____BAH_COMPILER_VAR_306, sizeof(____BAH_COMPILER_VAR_306));
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

                int ____BAH_COMPILER_VAR_307 = 0;
                for(int i=len(compilerState.includes)-1; i != -1; i--) {
                    if (compilerState.includes->data[i] != 0 && strcmp(compilerState.includes->data[i], fileName.str((struct string*)&fileName)) == 0) {
                        ____BAH_COMPILER_VAR_307 = 1;
                        break;
                    };
                };
                if (____BAH_COMPILER_VAR_307) {
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
char * ____BAH_COMPILER_VAR_308 =fileName.str((struct string*)&fileName);char * fn =  absPath(____BAH_COMPILER_VAR_308);
if (((void *)fn==null)) {
char * ____BAH_COMPILER_VAR_309 =fileName.str((struct string*)&fileName);char * ____BAH_COMPILER_VAR_310 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_309);
;                            
                    ____BAH_COMPILER_VAR_310 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_310+currStrOff, BAH_DIR, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_310+currStrOff, ____BAH_COMPILER_VAR_309, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_310[currStrOff] = 0;
                }
                fn =  absPath(____BAH_COMPILER_VAR_310);
if (((void *)fn==null)) {
throwErr(&strt,"Unknown file {TOKEN}.");
}
}
char * of =  compilerState.currentFile;
char * od =  compilerState.currentDir;
compilerState.currentFile =  fn;
compilerState.currentDir =  getDirFromFile(fn);
struct fileStream ____BAH_COMPILER_VAR_311 = {};
____BAH_COMPILER_VAR_311.handle= null;
____BAH_COMPILER_VAR_311.isValid = fileStream__isValid;
____BAH_COMPILER_VAR_311.open = fileStream__open;
____BAH_COMPILER_VAR_311.close = fileStream__close;
____BAH_COMPILER_VAR_311.getPos = fileStream__getPos;
____BAH_COMPILER_VAR_311.setPos = fileStream__setPos;
____BAH_COMPILER_VAR_311.getSize = fileStream__getSize;
____BAH_COMPILER_VAR_311.rewind = fileStream__rewind;
____BAH_COMPILER_VAR_311.getChar = fileStream__getChar;
____BAH_COMPILER_VAR_311.setChar = fileStream__setChar;
____BAH_COMPILER_VAR_311.createFile = fileStream__createFile;
____BAH_COMPILER_VAR_311.writeFile = fileStream__writeFile;
____BAH_COMPILER_VAR_311.writePtr = fileStream__writePtr;
____BAH_COMPILER_VAR_311.readPtr = fileStream__readPtr;
____BAH_COMPILER_VAR_311.readContent = fileStream__readContent;
____BAH_COMPILER_VAR_311.readBytes = fileStream__readBytes;
____BAH_COMPILER_VAR_311.writeBytes = fileStream__writeBytes;
struct fileStream fs =  ____BAH_COMPILER_VAR_311;
fs.open((struct fileStream*)&fs,fn,"r");
char * f =  fs.readContent((struct fileStream*)&fs);
fs.close((struct fileStream*)&fs);
array(struct Tok)* tokens =  lexer(f);
char osod =  shouldOnlyDecl;
shouldOnlyDecl =  true;
char oiso =  isSubObject;
isSubObject =  true;
char * ____BAH_COMPILER_VAR_312 =pathToVarName(fn);char * ____BAH_COMPILER_VAR_313 =intToStr(RCPlevel);char * ____BAH_COMPILER_VAR_314 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen("cache/");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_312);
long int strLen_3 = strlen(____BAH_COMPILER_VAR_313);
long int strLen_4 = strlen(".o");
;                            
                    ____BAH_COMPILER_VAR_314 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_314+currStrOff, BAH_DIR, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_314+currStrOff, "cache/", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_314+currStrOff, ____BAH_COMPILER_VAR_312, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_314+currStrOff, ____BAH_COMPILER_VAR_313, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_314+currStrOff, ".o", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_314[currStrOff] = 0;
                }
                char * oName =  ____BAH_COMPILER_VAR_314;
char * ____BAH_COMPILER_VAR_315 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("w ");
long int strLen_1 = strlen(oName);
long int strLen_2 = strlen(".o");
;                            
                    ____BAH_COMPILER_VAR_315 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_315+currStrOff, "w ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_315+currStrOff, oName, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_315+currStrOff, ".o", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_315[currStrOff] = 0;
                }
                
{
long nLength = len(compilerState.cLibs);
if (compilerState.cLibs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(compilerState.cLibs->data, (nLength+50)*sizeof(char *));
compilerState.cLibs->data = newPtr;
}
compilerState.cLibs->data[len(compilerState.cLibs)] =  ____BAH_COMPILER_VAR_315;
compilerState.cLibs->length = nLength+1;
} else {
compilerState.cLibs->data[len(compilerState.cLibs)] =  ____BAH_COMPILER_VAR_315;
}
};
struct channel * done = channel();

    void ____BAH_COMPILER_VAR_316(struct {
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
} ____BAH_COMPILER_VAR_317 = {fn,oName,done};
        pthread_t id;
        GC_pthread_create(&id, 0, ____BAH_COMPILER_VAR_316, &____BAH_COMPILER_VAR_317);
    }; 
    
    parseLines(tokens,elems);
char ok =  *(char*)done->receive(done);
char * ____BAH_COMPILER_VAR_318 =pathToVarName(fn);char * ____BAH_COMPILER_VAR_319 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("__BAH_init");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_318);
long int strLen_2 = strlen("();\n");
;                            
                    ____BAH_COMPILER_VAR_319 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_319+currStrOff, "__BAH_init", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_319+currStrOff, ____BAH_COMPILER_VAR_318, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_319+currStrOff, "();\n", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_319[currStrOff] = 0;
                }
                INIT =  INIT->add(INIT, rope(____BAH_COMPILER_VAR_319));
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
char * ____BAH_COMPILER_VAR_320 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("#include ");
long int strLen_1 = strlen(sc);
long int strLen_2 = strlen("\n");
;                            
                    ____BAH_COMPILER_VAR_320 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_320+currStrOff, "#include ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_320+currStrOff, sc, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_320+currStrOff, "\n", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_320[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_320));

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
char * ____BAH_COMPILER_VAR_321 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("(");
long int strLen_1 = strlen(nestedT.cont);
long int strLen_2 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_321 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_321+currStrOff, "(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_321+currStrOff, nestedT.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_321+currStrOff, ")", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_321[currStrOff] = 0;
                }
                nestedT.cont =  ____BAH_COMPILER_VAR_321;

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

                int ____BAH_COMPILER_VAR_322 = 0;
                for(int i=len(signs)-1; i != -1; i--) {
                    if (signs->data[i] != 0 && strcmp(signs->data[i], t.cont) == 0) {
                        ____BAH_COMPILER_VAR_322 = 1;
                        break;
                    };
                };
                if (((t.type==TOKEN_TYPE_SYNTAX)&&____BAH_COMPILER_VAR_322)) {
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
char * ____BAH_COMPILER_VAR_323 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(nt.cont);
;                            
                    ____BAH_COMPILER_VAR_323 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_323+currStrOff, t.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_323+currStrOff, nt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_323[currStrOff] = 0;
                }
                nt.cont =  ____BAH_COMPILER_VAR_323;

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
char * ____BAH_COMPILER_VAR_324 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(nt.cont);
;                            
                    ____BAH_COMPILER_VAR_324 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_324+currStrOff, t.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_324+currStrOff, nt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_324[currStrOff] = 0;
                }
                char * c =  ____BAH_COMPILER_VAR_324;
long int tl =  t.line;
long int tp =  t.pos;
struct Tok ____BAH_COMPILER_VAR_325 = {};
____BAH_COMPILER_VAR_325.cont = "";
____BAH_COMPILER_VAR_325.ogCont = "";
____BAH_COMPILER_VAR_325.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_325.pos = 0;
____BAH_COMPILER_VAR_325.line = 1;
____BAH_COMPILER_VAR_325.begLine = 1;
____BAH_COMPILER_VAR_325.bahType = "";
____BAH_COMPILER_VAR_325.isValue = false;
____BAH_COMPILER_VAR_325.isFunc = false;
____BAH_COMPILER_VAR_325.isOper = false;
____BAH_COMPILER_VAR_325.cont = c;
____BAH_COMPILER_VAR_325.ogCont = c;
____BAH_COMPILER_VAR_325.isValue = false;
____BAH_COMPILER_VAR_325.line = tl;
____BAH_COMPILER_VAR_325.pos = tp;
____BAH_COMPILER_VAR_325.type = TOKEN_TYPE_SYNTAX;
struct Tok tmpT =  ____BAH_COMPILER_VAR_325;

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
char * ____BAH_COMPILER_VAR_326 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(ntt);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(ptt);
long int strLen_4 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_326 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_326+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_326+currStrOff, ntt, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_326+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_326+currStrOff, ptt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_326+currStrOff, ".", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_326[currStrOff] = 0;
                }
                throwErr(&nt,____BAH_COMPILER_VAR_326);
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
char * ____BAH_COMPILER_VAR_327 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(ntt);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(ptt);
long int strLen_4 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_327 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_327+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_327+currStrOff, ntt, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_327+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_327+currStrOff, ptt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_327+currStrOff, ".", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_327[currStrOff] = 0;
                }
                throwErr(&strAddTkT,____BAH_COMPILER_VAR_327);
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
                    char * ____BAH_COMPILER_VAR_328 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(lens);
long int strLen_1 = strlen("long int strLen_");
long int strLen_2 = strlen(js);
long int strLen_3 = strlen(" = strlen(");
long int strLen_4 = strlen(strConts->data[j]);
long int strLen_5 = strlen(");\n");
;                            
                    ____BAH_COMPILER_VAR_328 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    memcpy(____BAH_COMPILER_VAR_328+currStrOff, lens, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_328+currStrOff, "long int strLen_", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_328+currStrOff, js, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_328+currStrOff, " = strlen(", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_328+currStrOff, strConts->data[j], strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_328+currStrOff, ");\n", strLen_5);
                    currStrOff += strLen_5;
                    
                    ____BAH_COMPILER_VAR_328[currStrOff] = 0;
                }
                lens =  ____BAH_COMPILER_VAR_328;
char * ____BAH_COMPILER_VAR_329 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(totStrLen);
long int strLen_1 = strlen(" + strLen_");
long int strLen_2 = strlen(js);
;                            
                    ____BAH_COMPILER_VAR_329 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_329+currStrOff, totStrLen, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_329+currStrOff, " + strLen_", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_329+currStrOff, js, strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_329[currStrOff] = 0;
                }
                totStrLen =  ____BAH_COMPILER_VAR_329;
};
struct rope* cats =  rope("");
j =  0;
for (; (j<len(strConts)); j =  j+1) {
char * js =  intToStr(j);

                    if (strConts->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:554): strConts[%d] with length %d\n", j, strConts->length);
                        exit(1);
                    };
                    char * ____BAH_COMPILER_VAR_330 =null;
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
                    ____BAH_COMPILER_VAR_330 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                    
                    memcpy(____BAH_COMPILER_VAR_330+currStrOff, "\n                    memcpy(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_330+currStrOff, rstr, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_330+currStrOff, "+currStrOff, ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_330+currStrOff, strConts->data[j], strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_330+currStrOff, ", strLen_", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_330+currStrOff, js, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_330+currStrOff, ");\n                    currStrOff += strLen_", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_330+currStrOff, js, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_330+currStrOff, ";\n                    ", strLen_8);
                    currStrOff += strLen_8;
                    
                    ____BAH_COMPILER_VAR_330[currStrOff] = 0;
                }
                cats =  cats->add(cats, rope(____BAH_COMPILER_VAR_330));
};
char * ____BAH_COMPILER_VAR_331 =null;
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
                    ____BAH_COMPILER_VAR_331 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                    
                    memcpy(____BAH_COMPILER_VAR_331+currStrOff, "\n                {\n                    long int currStrOff = 0;\n                    ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_331+currStrOff, lens, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_331+currStrOff, ";                            \n                    ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_331+currStrOff, rstr, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_331+currStrOff, " = memoryAllocSTR(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_331+currStrOff, totStrLen, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_331+currStrOff, ");\n                    ", strLen_6);
                    currStrOff += strLen_6;
                    
                    ____BAH_COMPILER_VAR_331[currStrOff] = 0;
                }
                char * ____BAH_COMPILER_VAR_332 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n                    ");
long int strLen_1 = strlen(rstr);
long int strLen_2 = strlen("[currStrOff] = 0;\n                }\n                ");
;                            
                    ____BAH_COMPILER_VAR_332 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_332+currStrOff, "\n                    ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_332+currStrOff, rstr, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_332+currStrOff, "[currStrOff] = 0;\n                }\n                ", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_332[currStrOff] = 0;
                }
                struct rope* res =  rope(____BAH_COMPILER_VAR_331)->add(rope(____BAH_COMPILER_VAR_331), cats)->add(rope(____BAH_COMPILER_VAR_331)->add(rope(____BAH_COMPILER_VAR_331), cats), rope(____BAH_COMPILER_VAR_332));
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
char * ____BAH_COMPILER_VAR_333 =null;
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
                    ____BAH_COMPILER_VAR_333 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7);
                    
                    memcpy(____BAH_COMPILER_VAR_333+currStrOff, pt.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_333+currStrOff, sep, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_333+currStrOff, "add(", strLen_2);
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
else if ((((strcmp(t.cont, "-") == 0)&&(subMthd!=null))&&(subMthd->isFn==true))) {
char * ____BAH_COMPILER_VAR_334 =null;
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
                    ____BAH_COMPILER_VAR_334 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7);
                    
                    memcpy(____BAH_COMPILER_VAR_334+currStrOff, pt.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_334+currStrOff, sep, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_334+currStrOff, "sub(", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_334+currStrOff, amp, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_334+currStrOff, pt.cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_334+currStrOff, ", ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_334+currStrOff, nt.cont, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_334+currStrOff, ")", strLen_7);
                    currStrOff += strLen_7;
                    
                    ____BAH_COMPILER_VAR_334[currStrOff] = 0;
                }
                t.cont =  ____BAH_COMPILER_VAR_334;
}
else if ((((strcmp(t.cont, "*") == 0)&&(multMthd!=null))&&(multMthd->isFn==true))) {
char * ____BAH_COMPILER_VAR_335 =null;
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
                    ____BAH_COMPILER_VAR_335 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7);
                    
                    memcpy(____BAH_COMPILER_VAR_335+currStrOff, pt.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_335+currStrOff, sep, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_335+currStrOff, "mult(", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_335+currStrOff, amp, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_335+currStrOff, pt.cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_335+currStrOff, ", ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_335+currStrOff, nt.cont, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_335+currStrOff, ")", strLen_7);
                    currStrOff += strLen_7;
                    
                    ____BAH_COMPILER_VAR_335[currStrOff] = 0;
                }
                t.cont =  ____BAH_COMPILER_VAR_335;
}
else if ((((strcmp(t.cont, "/") == 0)&&(divMthd!=null))&&(divMthd->isFn==true))) {
char * ____BAH_COMPILER_VAR_336 =null;
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
                    ____BAH_COMPILER_VAR_336 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7);
                    
                    memcpy(____BAH_COMPILER_VAR_336+currStrOff, pt.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_336+currStrOff, sep, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_336+currStrOff, "div(", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_336+currStrOff, amp, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_336+currStrOff, pt.cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_336+currStrOff, ", ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_336+currStrOff, nt.cont, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_336+currStrOff, ")", strLen_7);
                    currStrOff += strLen_7;
                    
                    ____BAH_COMPILER_VAR_336[currStrOff] = 0;
                }
                t.cont =  ____BAH_COMPILER_VAR_336;
}
else {
char * ____BAH_COMPILER_VAR_337 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Undefined operation on {TOKEN} (");
long int strLen_1 = strlen(ptt);
long int strLen_2 = strlen(").");
;                            
                    ____BAH_COMPILER_VAR_337 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_337+currStrOff, "Undefined operation on {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_337+currStrOff, ptt, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_337+currStrOff, ").", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_337[currStrOff] = 0;
                }
                throwErr(&pt,____BAH_COMPILER_VAR_337);
}
}
else {
char * ____BAH_COMPILER_VAR_338 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(t.cont);
long int strLen_3 = strlen(" ");
long int strLen_4 = strlen(nt.cont);
;                            
                    ____BAH_COMPILER_VAR_338 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_338+currStrOff, pt.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_338+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_338+currStrOff, t.cont, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_338+currStrOff, " ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_338+currStrOff, nt.cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_338[currStrOff] = 0;
                }
                t.cont =  ____BAH_COMPILER_VAR_338;
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
char * ____BAH_COMPILER_VAR_339 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(ntt);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(ptt);
long int strLen_4 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_339 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_339+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_339+currStrOff, ntt, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_339+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_339+currStrOff, ptt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_339+currStrOff, ".", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_339[currStrOff] = 0;
                }
                throwErr(&t,____BAH_COMPILER_VAR_339);
}
t.type =  TOKEN_TYPE_VAR;
t.isOper =  true;
char * ____BAH_COMPILER_VAR_340 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_340 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_340+currStrOff, pt.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_340+currStrOff, t.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_340[currStrOff] = 0;
                }
                t.cont =  ____BAH_COMPILER_VAR_340;
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
struct Tok ____BAH_COMPILER_VAR_341 = {};
____BAH_COMPILER_VAR_341.cont = "";
____BAH_COMPILER_VAR_341.ogCont = "";
____BAH_COMPILER_VAR_341.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_341.pos = 0;
____BAH_COMPILER_VAR_341.line = 1;
____BAH_COMPILER_VAR_341.begLine = 1;
____BAH_COMPILER_VAR_341.bahType = "";
____BAH_COMPILER_VAR_341.isValue = false;
____BAH_COMPILER_VAR_341.isFunc = false;
____BAH_COMPILER_VAR_341.isOper = false;
____BAH_COMPILER_VAR_341.cont = "";
struct Tok nt =  ____BAH_COMPILER_VAR_341;
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
struct variable* ____BAH_COMPILER_VAR_342 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_342->name = "";
____BAH_COMPILER_VAR_342->type = "";
____BAH_COMPILER_VAR_342->isConst = false;
____BAH_COMPILER_VAR_342->constVal = "";
____BAH_COMPILER_VAR_342->isArray = false;
____BAH_COMPILER_VAR_342->from = "";
____BAH_COMPILER_VAR_342->outterScope = false;
____BAH_COMPILER_VAR_342->isGlobal = false;
struct variable* tmpV =  ____BAH_COMPILER_VAR_342;
tmpV->name =  t.cont;
char * ____BAH_COMPILER_VAR_343 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s->name);
long int strLen_1 = strlen("*");
;                            
                    ____BAH_COMPILER_VAR_343 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_343+currStrOff, s->name, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_343+currStrOff, "*", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_343[currStrOff] = 0;
                }
                tmpV->type =  ____BAH_COMPILER_VAR_343;
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
char * ____BAH_COMPILER_VAR_344 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_345 =structType.str((struct string*)&structType);char * ____BAH_COMPILER_VAR_346 =declareStructMethods(tmpV,s,elems);char * ____BAH_COMPILER_VAR_347 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_344);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(t.cont);
long int strLen_3 = strlen(" = memoryAlloc(sizeof(");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_345);
long int strLen_5 = strlen("));\n");
long int strLen_6 = strlen(____BAH_COMPILER_VAR_346);
;                            
                    ____BAH_COMPILER_VAR_347 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                    
                    memcpy(____BAH_COMPILER_VAR_347+currStrOff, ____BAH_COMPILER_VAR_344, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_347+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_347+currStrOff, t.cont, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_347+currStrOff, " = memoryAlloc(sizeof(", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_347+currStrOff, ____BAH_COMPILER_VAR_345, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_347+currStrOff, "));\n", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_347+currStrOff, ____BAH_COMPILER_VAR_346, strLen_6);
                    currStrOff += strLen_6;
                    
                    ____BAH_COMPILER_VAR_347[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_347));

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
struct variable* ____BAH_COMPILER_VAR_348 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_348->name = "";
____BAH_COMPILER_VAR_348->type = "";
____BAH_COMPILER_VAR_348->isConst = false;
____BAH_COMPILER_VAR_348->constVal = "";
____BAH_COMPILER_VAR_348->isArray = false;
____BAH_COMPILER_VAR_348->from = "";
____BAH_COMPILER_VAR_348->outterScope = false;
____BAH_COMPILER_VAR_348->isGlobal = false;
struct variable* tmpV =  ____BAH_COMPILER_VAR_348;
tmpV->name =  rvn;
if ((isHeap==true)) {
char * ____BAH_COMPILER_VAR_349 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s->name);
long int strLen_1 = strlen("*");
;                            
                    ____BAH_COMPILER_VAR_349 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_349+currStrOff, s->name, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_349+currStrOff, "*", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_349[currStrOff] = 0;
                }
                tmpV->type =  ____BAH_COMPILER_VAR_349;

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
char * ____BAH_COMPILER_VAR_350 =rst.str((struct string*)&rst);struct string structType =  string(____BAH_COMPILER_VAR_350);
structType.trimRight((struct string*)&structType,1);
char * ____BAH_COMPILER_VAR_351 =rst.str((struct string*)&rst);char * ____BAH_COMPILER_VAR_352 =structType.str((struct string*)&structType);char * ____BAH_COMPILER_VAR_353 =declareStructMethods(tmpV,s,elems);char * ____BAH_COMPILER_VAR_354 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_351);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(rvn);
long int strLen_3 = strlen(" = memoryAlloc(sizeof(");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_352);
long int strLen_5 = strlen("));\n");
long int strLen_6 = strlen(____BAH_COMPILER_VAR_353);
;                            
                    ____BAH_COMPILER_VAR_354 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                    
                    memcpy(____BAH_COMPILER_VAR_354+currStrOff, ____BAH_COMPILER_VAR_351, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_354+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_354+currStrOff, rvn, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_354+currStrOff, " = memoryAlloc(sizeof(", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_354+currStrOff, ____BAH_COMPILER_VAR_352, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_354+currStrOff, "));\n", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_354+currStrOff, ____BAH_COMPILER_VAR_353, strLen_6);
                    currStrOff += strLen_6;
                    
                    ____BAH_COMPILER_VAR_354[currStrOff] = 0;
                }
                r =  rope(____BAH_COMPILER_VAR_354);
}
else {
char * ____BAH_COMPILER_VAR_355 =rst.str((struct string*)&rst);char * ____BAH_COMPILER_VAR_356 =declareStructMethods(tmpV,s,elems);char * ____BAH_COMPILER_VAR_357 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_355);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(rvn);
long int strLen_3 = strlen(" = {};\n");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_356);
;                            
                    ____BAH_COMPILER_VAR_357 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_357+currStrOff, ____BAH_COMPILER_VAR_355, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_357+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_357+currStrOff, rvn, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_357+currStrOff, " = {};\n", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_357+currStrOff, ____BAH_COMPILER_VAR_356, strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_357[currStrOff] = 0;
                }
                r =  rope(____BAH_COMPILER_VAR_357);
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
char * ____BAH_COMPILER_VAR_358 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(vlt);
long int strLen_2 = strlen(") as '");
long int strLen_3 = strlen(m->type);
long int strLen_4 = strlen("'.");
;                            
                    ____BAH_COMPILER_VAR_358 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_358+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_358+currStrOff, vlt, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_358+currStrOff, ") as '", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_358+currStrOff, m->type, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_358+currStrOff, "'.", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_358[currStrOff] = 0;
                }
                throwErr(&vl,____BAH_COMPILER_VAR_358);
}
char * ____BAH_COMPILER_VAR_359 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(rvn);
long int strLen_1 = strlen(sep);
long int strLen_2 = strlen(m->name);
long int strLen_3 = strlen(" = ");
long int strLen_4 = strlen(vl.cont);
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
                    
                    memcpy(____BAH_COMPILER_VAR_359+currStrOff, vl.cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_359+currStrOff, ";\n", strLen_5);
                    currStrOff += strLen_5;
                    
                    ____BAH_COMPILER_VAR_359[currStrOff] = 0;
                }
                r =  r->add(r, rope(____BAH_COMPILER_VAR_359));
break;
};
if ((j==len(s->members))) {
char * ____BAH_COMPILER_VAR_360 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Struct '");
long int strLen_1 = strlen(s->name);
long int strLen_2 = strlen("' has no member called {TOKEN}.");
;                            
                    ____BAH_COMPILER_VAR_360 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_360+currStrOff, "Struct '", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_360+currStrOff, s->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_360+currStrOff, "' has no member called {TOKEN}.", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_360[currStrOff] = 0;
                }
                throwErr(&t,____BAH_COMPILER_VAR_360);
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
char * ____BAH_COMPILER_VAR_361 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(tt);
long int strLen_2 = strlen(") as '");
long int strLen_3 = strlen(m->type);
long int strLen_4 = strlen("'.");
;                            
                    ____BAH_COMPILER_VAR_361 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_361+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_361+currStrOff, tt, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_361+currStrOff, ") as '", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_361+currStrOff, m->type, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_361+currStrOff, "'.", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_361[currStrOff] = 0;
                }
                throwErr(&t,____BAH_COMPILER_VAR_361);
}
char * ____BAH_COMPILER_VAR_362 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(rvn);
long int strLen_1 = strlen(sep);
long int strLen_2 = strlen(m->name);
long int strLen_3 = strlen(" = ");
long int strLen_4 = strlen(t.cont);
long int strLen_5 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_362 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    memcpy(____BAH_COMPILER_VAR_362+currStrOff, rvn, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_362+currStrOff, sep, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_362+currStrOff, m->name, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_362+currStrOff, " = ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_362+currStrOff, t.cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_362+currStrOff, ";\n", strLen_5);
                    currStrOff += strLen_5;
                    
                    ____BAH_COMPILER_VAR_362[currStrOff] = 0;
                }
                r =  r->add(r, rope(____BAH_COMPILER_VAR_362));
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
char * ____BAH_COMPILER_VAR_363 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(v->type);
long int strLen_2 = strlen(") as a structure.");
;                            
                    ____BAH_COMPILER_VAR_363 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_363+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_363+currStrOff, v->type, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_363+currStrOff, ") as a structure.", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_363[currStrOff] = 0;
                }
                throwErr(&t,____BAH_COMPILER_VAR_363);
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
char * ____BAH_COMPILER_VAR_364 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(sep);
long int strLen_2 = strlen(memb->name);
;                            
                    ____BAH_COMPILER_VAR_364 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_364+currStrOff, t.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_364+currStrOff, sep, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_364+currStrOff, memb->name, strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_364[currStrOff] = 0;
                }
                t.cont =  ____BAH_COMPILER_VAR_364;
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
char * ____BAH_COMPILER_VAR_365 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(bracks);
long int strLen_1 = strlen("[]");
;                            
                    ____BAH_COMPILER_VAR_365 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_365+currStrOff, bracks, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_365+currStrOff, "[]", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_365[currStrOff] = 0;
                }
                bracks =  ____BAH_COMPILER_VAR_365;
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
char * ____BAH_COMPILER_VAR_366 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(bracks);
long int strLen_1 = strlen(arrElem);
;                            
                    ____BAH_COMPILER_VAR_366 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_366+currStrOff, bracks, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_366+currStrOff, arrElem, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_366[currStrOff] = 0;
                }
                t.bahType =  ____BAH_COMPILER_VAR_366;
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
char * ____BAH_COMPILER_VAR_367 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(ntt);
long int strLen_2 = strlen(") as an array.");
;                            
                    ____BAH_COMPILER_VAR_367 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_367+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_367+currStrOff, ntt, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_367+currStrOff, ") as an array.", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_367[currStrOff] = 0;
                }
                throwErr(&nt,____BAH_COMPILER_VAR_367);
}
arrT.trimLeft((struct string*)&arrT,2);
char * ____BAH_COMPILER_VAR_368 =arrT.str((struct string*)&arrT);if ((compTypes(ptt,____BAH_COMPILER_VAR_368)==false)) {
char * ____BAH_COMPILER_VAR_369 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot search for {TOKEN} (");
long int strLen_1 = strlen(ptt);
long int strLen_2 = strlen(") inside array of type ");
long int strLen_3 = strlen(ntt);
long int strLen_4 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_369 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_369+currStrOff, "Cannot search for {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_369+currStrOff, ptt, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_369+currStrOff, ") inside array of type ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_369+currStrOff, ntt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_369+currStrOff, ".", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_369[currStrOff] = 0;
                }
                throwErr(&pt,____BAH_COMPILER_VAR_369);
}
char * compVar =  genCompilerVar();
char * comp =  "";
if ((strcmp(ptt, "cpstring") == 0)) {
char * ____BAH_COMPILER_VAR_370 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen("->data[i] != 0 && strcmp(");
long int strLen_2 = strlen(nt.cont);
long int strLen_3 = strlen("->data[i], ");
long int strLen_4 = strlen(pt.cont);
long int strLen_5 = strlen(") == 0");
;                            
                    ____BAH_COMPILER_VAR_370 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    memcpy(____BAH_COMPILER_VAR_370+currStrOff, nt.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_370+currStrOff, "->data[i] != 0 && strcmp(", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_370+currStrOff, nt.cont, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_370+currStrOff, "->data[i], ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_370+currStrOff, pt.cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_370+currStrOff, ") == 0", strLen_5);
                    currStrOff += strLen_5;
                    
                    ____BAH_COMPILER_VAR_370[currStrOff] = 0;
                }
                comp =  ____BAH_COMPILER_VAR_370;
}
else {
char * ____BAH_COMPILER_VAR_371 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen("->data[i] == ");
long int strLen_2 = strlen(pt.cont);
;                            
                    ____BAH_COMPILER_VAR_371 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_371+currStrOff, nt.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_371+currStrOff, "->data[i] == ", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_371+currStrOff, pt.cont, strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_371[currStrOff] = 0;
                }
                comp =  ____BAH_COMPILER_VAR_371;
}
char * ____BAH_COMPILER_VAR_372 =null;
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
                    ____BAH_COMPILER_VAR_372 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                    
                    memcpy(____BAH_COMPILER_VAR_372+currStrOff, "\n                int ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_372+currStrOff, compVar, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_372+currStrOff, " = 0;\n                for(int i=len(", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_372+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_372+currStrOff, ")-1; i != -1; i--) {\n                    if (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_372+currStrOff, comp, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_372+currStrOff, ") {\n                        ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_372+currStrOff, compVar, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_372+currStrOff, " = 1;\n                        break;\n                    };\n                };\n                ", strLen_8);
                    currStrOff += strLen_8;
                    
                    ____BAH_COMPILER_VAR_372[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_372));
pt.cont =  compVar;
}
else {
if ((compTypes(ptt,ntt)==false)) {
char * ____BAH_COMPILER_VAR_373 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot compare {TOKEN} (");
long int strLen_1 = strlen(ntt);
long int strLen_2 = strlen(") to ");
long int strLen_3 = strlen(ptt);
long int strLen_4 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_373 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_373+currStrOff, "Cannot compare {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_373+currStrOff, ntt, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_373+currStrOff, ") to ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_373+currStrOff, ptt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_373+currStrOff, ".", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_373[currStrOff] = 0;
                }
                throwErr(&nt,____BAH_COMPILER_VAR_373);
}
if ((strcmp(ptt, "cpstring") == 0)) {
if ((strcmp(t.cont, "==") == 0)) {
char * ____BAH_COMPILER_VAR_374 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("(strcmp(");
long int strLen_1 = strlen(pt.cont);
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen(") == 0)");
;                            
                    ____BAH_COMPILER_VAR_374 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_374+currStrOff, "(strcmp(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_374+currStrOff, pt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_374+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_374+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_374+currStrOff, ") == 0)", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_374[currStrOff] = 0;
                }
                pt.cont =  ____BAH_COMPILER_VAR_374;
}
else if ((strcmp(t.cont, "!=") == 0)) {
char * ____BAH_COMPILER_VAR_375 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("(strcmp(");
long int strLen_1 = strlen(pt.cont);
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen(") != 0)");
;                            
                    ____BAH_COMPILER_VAR_375 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_375+currStrOff, "(strcmp(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_375+currStrOff, pt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_375+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_375+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_375+currStrOff, ") != 0)", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_375[currStrOff] = 0;
                }
                pt.cont =  ____BAH_COMPILER_VAR_375;
}
else if ((strcmp(t.cont, ">") == 0)) {
char * ____BAH_COMPILER_VAR_376 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("(strlen(");
long int strLen_1 = strlen(pt.cont);
long int strLen_2 = strlen(") > srtlen(");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen("))");
;                            
                    ____BAH_COMPILER_VAR_376 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_376+currStrOff, "(strlen(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_376+currStrOff, pt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_376+currStrOff, ") > srtlen(", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_376+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_376+currStrOff, "))", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_376[currStrOff] = 0;
                }
                pt.cont =  ____BAH_COMPILER_VAR_376;
}
else if ((strcmp(t.cont, "<") == 0)) {
char * ____BAH_COMPILER_VAR_377 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("(strlen(");
long int strLen_1 = strlen(pt.cont);
long int strLen_2 = strlen(") < srtlen(");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen("))");
;                            
                    ____BAH_COMPILER_VAR_377 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_377+currStrOff, "(strlen(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_377+currStrOff, pt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_377+currStrOff, ") < srtlen(", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_377+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_377+currStrOff, "))", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_377[currStrOff] = 0;
                }
                pt.cont =  ____BAH_COMPILER_VAR_377;
}
else if ((strcmp(t.cont, ">=") == 0)) {
char * ____BAH_COMPILER_VAR_378 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("(strlen(");
long int strLen_1 = strlen(pt.cont);
long int strLen_2 = strlen(") >= srtlen(");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen("))");
;                            
                    ____BAH_COMPILER_VAR_378 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_378+currStrOff, "(strlen(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_378+currStrOff, pt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_378+currStrOff, ") >= srtlen(", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_378+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_378+currStrOff, "))", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_378[currStrOff] = 0;
                }
                pt.cont =  ____BAH_COMPILER_VAR_378;
}
else if ((strcmp(t.cont, "<=") == 0)) {
char * ____BAH_COMPILER_VAR_379 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("(strlen(");
long int strLen_1 = strlen(pt.cont);
long int strLen_2 = strlen(") <= srtlen(");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen("))");
;                            
                    ____BAH_COMPILER_VAR_379 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_379+currStrOff, "(strlen(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_379+currStrOff, pt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_379+currStrOff, ") <= srtlen(", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_379+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_379+currStrOff, "))", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_379[currStrOff] = 0;
                }
                pt.cont =  ____BAH_COMPILER_VAR_379;
}
}
else {
char * ____BAH_COMPILER_VAR_380 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("(");
long int strLen_1 = strlen(pt.cont);
long int strLen_2 = strlen(t.cont);
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_380 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_380+currStrOff, "(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_380+currStrOff, pt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_380+currStrOff, t.cont, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_380+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_380+currStrOff, ")", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_380[currStrOff] = 0;
                }
                pt.cont =  ____BAH_COMPILER_VAR_380;
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
char * ____BAH_COMPILER_VAR_381 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("(");
long int strLen_1 = strlen(pt.cont);
long int strLen_2 = strlen(t.cont);
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_381 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_381+currStrOff, "(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_381+currStrOff, pt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_381+currStrOff, t.cont, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_381+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_381+currStrOff, ")", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_381[currStrOff] = 0;
                }
                pt.cont =  ____BAH_COMPILER_VAR_381;
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
char * ____BAH_COMPILER_VAR_382 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_382 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_382+currStrOff, pt.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_382+currStrOff, t.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_382[currStrOff] = 0;
                }
                pt.cont =  ____BAH_COMPILER_VAR_382;

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
char * ____BAH_COMPILER_VAR_383 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_383 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_383+currStrOff, pt.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_383+currStrOff, t.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_383[currStrOff] = 0;
                }
                pt.cont =  ____BAH_COMPILER_VAR_383;

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
char * ____BAH_COMPILER_VAR_384 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(nt.cont);
;                            
                    ____BAH_COMPILER_VAR_384 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_384+currStrOff, t.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_384+currStrOff, nt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_384[currStrOff] = 0;
                }
                nt.cont =  ____BAH_COMPILER_VAR_384;

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
char * ____BAH_COMPILER_VAR_385 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(cont);
long int strLen_1 = strlen(mt.cont);
;                            
                    ____BAH_COMPILER_VAR_385 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_385+currStrOff, cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_385+currStrOff, mt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_385[currStrOff] = 0;
                }
                cont =  ____BAH_COMPILER_VAR_385;
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
char * ____BAH_COMPILER_VAR_386 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(from);
long int strLen_1 = strlen(mt.cont);
;                            
                    ____BAH_COMPILER_VAR_386 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_386+currStrOff, from, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_386+currStrOff, mt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_386[currStrOff] = 0;
                }
                from =  ____BAH_COMPILER_VAR_386;
};
}
if ((sepPos==len(memory) - 1)) {
char * ____BAH_COMPILER_VAR_387 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("strlen(");
long int strLen_1 = strlen(lt.cont);
long int strLen_2 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_387 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_387+currStrOff, "strlen(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_387+currStrOff, lt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_387+currStrOff, ")", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_387[currStrOff] = 0;
                }
                to =  ____BAH_COMPILER_VAR_387;
}
else {
j =  sepPos + 1;
for (; (j<len(memory)); j =  j+1) {

                    if (memory->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1274): memory[%d] with length %d\n", j, memory->length);
                        exit(1);
                    };
                    struct Tok mt =  memory->data[j];
char * ____BAH_COMPILER_VAR_388 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(to);
long int strLen_1 = strlen(mt.cont);
;                            
                    ____BAH_COMPILER_VAR_388 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_388+currStrOff, to, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_388+currStrOff, mt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_388[currStrOff] = 0;
                }
                to =  ____BAH_COMPILER_VAR_388;
};
}
}
if ((strcmp(tt, "cpstring") == 0)) {
if ((split==false)) {
char * ____BAH_COMPILER_VAR_389 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("cpstringCharAt(");
long int strLen_1 = strlen(lt.cont);
long int strLen_2 = strlen(",");
long int strLen_3 = strlen(cont);
long int strLen_4 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_389 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_389+currStrOff, "cpstringCharAt(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_389+currStrOff, lt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_389+currStrOff, ",", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_389+currStrOff, cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_389+currStrOff, ")", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_389[currStrOff] = 0;
                }
                lt.cont =  ____BAH_COMPILER_VAR_389;
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
char * ____BAH_COMPILER_VAR_390 =null;
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
                    ____BAH_COMPILER_VAR_390 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                    
                    memcpy(____BAH_COMPILER_VAR_390+currStrOff, "cpstringSubsitute(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_390+currStrOff, lt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_390+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_390+currStrOff, from, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_390+currStrOff, ", ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_390+currStrOff, to, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_390+currStrOff, ")", strLen_6);
                    currStrOff += strLen_6;
                    
                    ____BAH_COMPILER_VAR_390[currStrOff] = 0;
                }
                lt.cont =  ____BAH_COMPILER_VAR_390;
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
struct variable* ____BAH_COMPILER_VAR_391 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_391->name = "";
____BAH_COMPILER_VAR_391->type = "";
____BAH_COMPILER_VAR_391->isConst = false;
____BAH_COMPILER_VAR_391->constVal = "";
____BAH_COMPILER_VAR_391->isArray = false;
____BAH_COMPILER_VAR_391->from = "";
____BAH_COMPILER_VAR_391->outterScope = false;
____BAH_COMPILER_VAR_391->isGlobal = false;
____BAH_COMPILER_VAR_391->name = genCompilerVar();
____BAH_COMPILER_VAR_391->type = tt;
struct variable* tmpV =  ____BAH_COMPILER_VAR_391;

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
char * ____BAH_COMPILER_VAR_392 =elemType.str((struct string*)&elemType);char * ____BAH_COMPILER_VAR_393 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_392);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(tmpV->name);
long int strLen_3 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_393 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                    
                    memcpy(____BAH_COMPILER_VAR_393+currStrOff, ____BAH_COMPILER_VAR_392, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_393+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_393+currStrOff, tmpV->name, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_393+currStrOff, ";\n", strLen_3);
                    currStrOff += strLen_3;
                    
                    ____BAH_COMPILER_VAR_393[currStrOff] = 0;
                }
                INIT =  INIT->add(INIT, rope(____BAH_COMPILER_VAR_393));
}
else {
char * ____BAH_COMPILER_VAR_394 =elemType.str((struct string*)&elemType);char * ____BAH_COMPILER_VAR_395 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_394);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(tmpV->name);
long int strLen_3 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_395 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                    
                    memcpy(____BAH_COMPILER_VAR_395+currStrOff, ____BAH_COMPILER_VAR_394, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_395+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_395+currStrOff, tmpV->name, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_395+currStrOff, ";\n", strLen_3);
                    currStrOff += strLen_3;
                    
                    ____BAH_COMPILER_VAR_395[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_395));
}
if (isRCPpointerType(tt)) {
char * ____BAH_COMPILER_VAR_396 =null;
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
                    ____BAH_COMPILER_VAR_396 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7);
                    
                    memcpy(____BAH_COMPILER_VAR_396+currStrOff, lt.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_396+currStrOff, "->set(", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_396+currStrOff, lt.cont, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_396+currStrOff, ", ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_396+currStrOff, cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_396+currStrOff, ", ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_396+currStrOff, tmpV->name, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_396+currStrOff, ");\n", strLen_7);
                    currStrOff += strLen_7;
                    
                    ____BAH_COMPILER_VAR_396[currStrOff] = 0;
                }
                NEXT_LINE =  ____BAH_COMPILER_VAR_396;
}
else {
char * ____BAH_COMPILER_VAR_397 =null;
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
                    ____BAH_COMPILER_VAR_397 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9);
                    
                    memcpy(____BAH_COMPILER_VAR_397+currStrOff, lt.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_397+currStrOff, "->setAny(", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_397+currStrOff, lt.cont, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_397+currStrOff, ", ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_397+currStrOff, cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_397+currStrOff, ", &", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_397+currStrOff, tmpV->name, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_397+currStrOff, ", sizeof(", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_397+currStrOff, tmpV->name, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_397+currStrOff, "));\n", strLen_9);
                    currStrOff += strLen_9;
                    
                    ____BAH_COMPILER_VAR_397[currStrOff] = 0;
                }
                NEXT_LINE =  ____BAH_COMPILER_VAR_397;
}
lt.cont =  tmpV->name;
}
else {
if (isRCPpointerType(tt)) {
char * ____BAH_COMPILER_VAR_398 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(lt.cont);
long int strLen_1 = strlen("->get(");
long int strLen_2 = strlen(lt.cont);
long int strLen_3 = strlen(", ");
long int strLen_4 = strlen(cont);
long int strLen_5 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_398 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    memcpy(____BAH_COMPILER_VAR_398+currStrOff, lt.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_398+currStrOff, "->get(", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_398+currStrOff, lt.cont, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_398+currStrOff, ", ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_398+currStrOff, cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_398+currStrOff, ")", strLen_5);
                    currStrOff += strLen_5;
                    
                    ____BAH_COMPILER_VAR_398[currStrOff] = 0;
                }
                lt.cont =  ____BAH_COMPILER_VAR_398;
}
else {
char * tmpV =  genCompilerVar();
char * ____BAH_COMPILER_VAR_399 =elemType.str((struct string*)&elemType);char * ____BAH_COMPILER_VAR_400 =intToStr(lt.line);char * ____BAH_COMPILER_VAR_401 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_399);
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
long int strLen_14 = strlen(____BAH_COMPILER_VAR_400);
long int strLen_15 = strlen("): ");
long int strLen_16 = strlen(lt.cont);
long int strLen_17 = strlen("[\\\"%s\\\"] does not exist\\n\", ");
long int strLen_18 = strlen(cont);
long int strLen_19 = strlen(");\n                            exit(1);\n                        };");
;                            
                    ____BAH_COMPILER_VAR_401 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14 + strLen_15 + strLen_16 + strLen_17 + strLen_18 + strLen_19);
                    
                    memcpy(____BAH_COMPILER_VAR_401+currStrOff, ____BAH_COMPILER_VAR_399, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_401+currStrOff, "* ", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_401+currStrOff, tmpV, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_401+currStrOff, " = ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_401+currStrOff, lt.cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_401+currStrOff, "->get(", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_401+currStrOff, lt.cont, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_401+currStrOff, ", ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_401+currStrOff, cont, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_401+currStrOff, ");\n                        if(", strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_401+currStrOff, tmpV, strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_401+currStrOff, " == null) {\n                            printf(\"map (", strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_401+currStrOff, compilerState.currentFile, strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_401+currStrOff, ":", strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_401+currStrOff, ____BAH_COMPILER_VAR_400, strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_401+currStrOff, "): ", strLen_15);
                    currStrOff += strLen_15;
                    
                    memcpy(____BAH_COMPILER_VAR_401+currStrOff, lt.cont, strLen_16);
                    currStrOff += strLen_16;
                    
                    memcpy(____BAH_COMPILER_VAR_401+currStrOff, "[\\\"%s\\\"] does not exist\\n\", ", strLen_17);
                    currStrOff += strLen_17;
                    
                    memcpy(____BAH_COMPILER_VAR_401+currStrOff, cont, strLen_18);
                    currStrOff += strLen_18;
                    
                    memcpy(____BAH_COMPILER_VAR_401+currStrOff, ");\n                            exit(1);\n                        };", strLen_19);
                    currStrOff += strLen_19;
                    
                    ____BAH_COMPILER_VAR_401[currStrOff] = 0;
                }
                struct rope* res =  rope(____BAH_COMPILER_VAR_401);
char * ____BAH_COMPILER_VAR_402 =elemType.str((struct string*)&elemType);char * ____BAH_COMPILER_VAR_403 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("(");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_402);
long int strLen_2 = strlen(")(*");
long int strLen_3 = strlen(tmpV);
long int strLen_4 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_403 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_403+currStrOff, "(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_403+currStrOff, ____BAH_COMPILER_VAR_402, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_403+currStrOff, ")(*", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_403+currStrOff, tmpV, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_403+currStrOff, ")", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_403[currStrOff] = 0;
                }
                lt.cont =  ____BAH_COMPILER_VAR_403;
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
char * ____BAH_COMPILER_VAR_404 =intToStr(lt.line);char * ____BAH_COMPILER_VAR_405 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n                    if (");
long int strLen_1 = strlen(cont);
long int strLen_2 = strlen(" >= ");
long int strLen_3 = strlen(amm);
long int strLen_4 = strlen(") {\n                        printf(\"buffer (");
long int strLen_5 = strlen(compilerState.currentFile);
long int strLen_6 = strlen(":");
long int strLen_7 = strlen(____BAH_COMPILER_VAR_404);
long int strLen_8 = strlen("): ");
long int strLen_9 = strlen(lt.cont);
long int strLen_10 = strlen("[%d] with length %d\\n\", ");
long int strLen_11 = strlen(cont);
long int strLen_12 = strlen(", ");
long int strLen_13 = strlen(amm);
long int strLen_14 = strlen(");\n                        exit(1);\n                    };\n                    ");
;                            
                    ____BAH_COMPILER_VAR_405 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14);
                    
                    memcpy(____BAH_COMPILER_VAR_405+currStrOff, "\n                    if (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_405+currStrOff, cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_405+currStrOff, " >= ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_405+currStrOff, amm, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_405+currStrOff, ") {\n                        printf(\"buffer (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_405+currStrOff, compilerState.currentFile, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_405+currStrOff, ":", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_405+currStrOff, ____BAH_COMPILER_VAR_404, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_405+currStrOff, "): ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_405+currStrOff, lt.cont, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_405+currStrOff, "[%d] with length %d\\n\", ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_405+currStrOff, cont, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_405+currStrOff, ", ", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_405+currStrOff, amm, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_405+currStrOff, ");\n                        exit(1);\n                    };\n                    ", strLen_14);
                    currStrOff += strLen_14;
                    
                    ____BAH_COMPILER_VAR_405[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_405));
char * ____BAH_COMPILER_VAR_406 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(lt.cont);
long int strLen_1 = strlen("[");
long int strLen_2 = strlen(cont);
long int strLen_3 = strlen("]");
;                            
                    ____BAH_COMPILER_VAR_406 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                    
                    memcpy(____BAH_COMPILER_VAR_406+currStrOff, lt.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_406+currStrOff, "[", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_406+currStrOff, cont, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_406+currStrOff, "]", strLen_3);
                    currStrOff += strLen_3;
                    
                    ____BAH_COMPILER_VAR_406[currStrOff] = 0;
                }
                lt.cont =  ____BAH_COMPILER_VAR_406;
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
char * ____BAH_COMPILER_VAR_407 =null;
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
                    ____BAH_COMPILER_VAR_407 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                    
                    memcpy(____BAH_COMPILER_VAR_407+currStrOff, "cpstringSubsitute(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_407+currStrOff, lt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_407+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_407+currStrOff, from, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_407+currStrOff, ", ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_407+currStrOff, to, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_407+currStrOff, ")", strLen_6);
                    currStrOff += strLen_6;
                    
                    ____BAH_COMPILER_VAR_407[currStrOff] = 0;
                }
                lt.cont =  ____BAH_COMPILER_VAR_407;
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
char * ____BAH_COMPILER_VAR_408 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(tt);
long int strLen_2 = strlen(") as an array.");
;                            
                    ____BAH_COMPILER_VAR_408 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_408+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_408+currStrOff, tt, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_408+currStrOff, ") as an array.", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_408[currStrOff] = 0;
                }
                throwErr(&lt,____BAH_COMPILER_VAR_408);
}
strTrimLeft(&tt,2);
if ((split==false)) {
if (((ti>0)&&(strcmp(ft.cont, "else") != 0))) {
char * ____BAH_COMPILER_VAR_409 =intToStr(lt.line);char * ____BAH_COMPILER_VAR_410 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n                    if (");
long int strLen_1 = strlen(lt.cont);
long int strLen_2 = strlen("->length <= ");
long int strLen_3 = strlen(cont);
long int strLen_4 = strlen(") {\n                        printf(\"array (");
long int strLen_5 = strlen(compilerState.currentFile);
long int strLen_6 = strlen(":");
long int strLen_7 = strlen(____BAH_COMPILER_VAR_409);
long int strLen_8 = strlen("): ");
long int strLen_9 = strlen(lt.cont);
long int strLen_10 = strlen("[%d] with length %d\\n\", ");
long int strLen_11 = strlen(cont);
long int strLen_12 = strlen(", ");
long int strLen_13 = strlen(lt.cont);
long int strLen_14 = strlen("->length);\n                        exit(1);\n                    };\n                    ");
;                            
                    ____BAH_COMPILER_VAR_410 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14);
                    
                    memcpy(____BAH_COMPILER_VAR_410+currStrOff, "\n                    if (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_410+currStrOff, lt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_410+currStrOff, "->length <= ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_410+currStrOff, cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_410+currStrOff, ") {\n                        printf(\"array (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_410+currStrOff, compilerState.currentFile, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_410+currStrOff, ":", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_410+currStrOff, ____BAH_COMPILER_VAR_409, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_410+currStrOff, "): ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_410+currStrOff, lt.cont, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_410+currStrOff, "[%d] with length %d\\n\", ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_410+currStrOff, cont, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_410+currStrOff, ", ", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_410+currStrOff, lt.cont, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_410+currStrOff, "->length);\n                        exit(1);\n                    };\n                    ", strLen_14);
                    currStrOff += strLen_14;
                    
                    ____BAH_COMPILER_VAR_410[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_410));
}
char * ____BAH_COMPILER_VAR_411 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(lt.cont);
long int strLen_1 = strlen("->data[");
long int strLen_2 = strlen(cont);
long int strLen_3 = strlen("]");
;                            
                    ____BAH_COMPILER_VAR_411 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                    
                    memcpy(____BAH_COMPILER_VAR_411+currStrOff, lt.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_411+currStrOff, "->data[", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_411+currStrOff, cont, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_411+currStrOff, "]", strLen_3);
                    currStrOff += strLen_3;
                    
                    ____BAH_COMPILER_VAR_411[currStrOff] = 0;
                }
                lt.cont =  ____BAH_COMPILER_VAR_411;
lt.bahType =  tt;
}
else {
char * ____BAH_COMPILER_VAR_412 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("[]");
long int strLen_1 = strlen(tt);
;                            
                    ____BAH_COMPILER_VAR_412 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_412+currStrOff, "[]", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_412+currStrOff, tt, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_412[currStrOff] = 0;
                }
                lt.bahType =  ____BAH_COMPILER_VAR_412;
char * ____BAH_COMPILER_VAR_413 =null;
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
                    ____BAH_COMPILER_VAR_413 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                    
                    memcpy(____BAH_COMPILER_VAR_413+currStrOff, "arraySubstitute(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_413+currStrOff, lt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_413+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_413+currStrOff, from, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_413+currStrOff, ", ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_413+currStrOff, to, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_413+currStrOff, ")", strLen_6);
                    currStrOff += strLen_6;
                    
                    ____BAH_COMPILER_VAR_413[currStrOff] = 0;
                }
                lt.cont =  ____BAH_COMPILER_VAR_413;
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
char * ____BAH_COMPILER_VAR_414 =svt.str((struct string*)&svt);char * ____BAH_COMPILER_VAR_415 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("__serialize(&");
long int strLen_1 = strlen(e.cont);
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen("sizeof(struct ");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_414);
long int strLen_5 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_415 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    memcpy(____BAH_COMPILER_VAR_415+currStrOff, "__serialize(&", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_415+currStrOff, e.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_415+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_415+currStrOff, "sizeof(struct ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_415+currStrOff, ____BAH_COMPILER_VAR_414, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_415+currStrOff, ")", strLen_5);
                    currStrOff += strLen_5;
                    
                    ____BAH_COMPILER_VAR_415[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_415;
}
else {
char * ptrRect =  "";
while ((ptrLevel>1)) {
char * ____BAH_COMPILER_VAR_416 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ptrRect);
long int strLen_1 = strlen("*");
;                            
                    ____BAH_COMPILER_VAR_416 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_416+currStrOff, ptrRect, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_416+currStrOff, "*", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_416[currStrOff] = 0;
                }
                ptrRect =  ____BAH_COMPILER_VAR_416;
ptrLevel =  ptrLevel - 1;
};
char * ____BAH_COMPILER_VAR_417 =svt.str((struct string*)&svt);char * ____BAH_COMPILER_VAR_418 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("__serialize(");
long int strLen_1 = strlen(ptrRect);
long int strLen_2 = strlen(e.cont);
long int strLen_3 = strlen(", ");
long int strLen_4 = strlen("sizeof(struct ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_417);
long int strLen_6 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_418 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                    
                    memcpy(____BAH_COMPILER_VAR_418+currStrOff, "__serialize(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_418+currStrOff, ptrRect, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_418+currStrOff, e.cont, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_418+currStrOff, ", ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_418+currStrOff, "sizeof(struct ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_418+currStrOff, ____BAH_COMPILER_VAR_417, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_418+currStrOff, ")", strLen_6);
                    currStrOff += strLen_6;
                    
                    ____BAH_COMPILER_VAR_418[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_418;
long int i =  0;
while ((i<len(s->members))) {

                    if (s->members->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1422): s->members[%d] with length %d\n", i, s->members->length);
                        exit(1);
                    };
                    struct structMemb* m =  s->members->data[i];
if ((strcmp(m->type, "cpstring") == 0)) {
char * ____BAH_COMPILER_VAR_419 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen("+strlen(");
long int strLen_2 = strlen(e.cont);
long int strLen_3 = strlen("->");
long int strLen_4 = strlen(m->name);
long int strLen_5 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_419 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    memcpy(____BAH_COMPILER_VAR_419+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_419+currStrOff, "+strlen(", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_419+currStrOff, e.cont, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_419+currStrOff, "->", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_419+currStrOff, m->name, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_419+currStrOff, ")", strLen_5);
                    currStrOff += strLen_5;
                    
                    ____BAH_COMPILER_VAR_419[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_419;
}
i =  i + 1;
};
}
char * ____BAH_COMPILER_VAR_420 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_420 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_420+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_420+currStrOff, ")", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_420[currStrOff] = 0;
                }
                return ____BAH_COMPILER_VAR_420;
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
char * ____BAH_COMPILER_VAR_421 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_422 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_421);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(v);
long int strLen_3 = strlen(" = ");
long int strLen_4 = strlen(t.cont);
long int strLen_5 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_422 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    memcpy(____BAH_COMPILER_VAR_422+currStrOff, ____BAH_COMPILER_VAR_421, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_422+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_422+currStrOff, v, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_422+currStrOff, " = ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_422+currStrOff, t.cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_422+currStrOff, ";\n", strLen_5);
                    currStrOff += strLen_5;
                    
                    ____BAH_COMPILER_VAR_422[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_422));
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
struct Tok ____BAH_COMPILER_VAR_423 = {};
____BAH_COMPILER_VAR_423.cont = "";
____BAH_COMPILER_VAR_423.ogCont = "";
____BAH_COMPILER_VAR_423.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_423.pos = 0;
____BAH_COMPILER_VAR_423.line = 1;
____BAH_COMPILER_VAR_423.begLine = 1;
____BAH_COMPILER_VAR_423.bahType = "";
____BAH_COMPILER_VAR_423.isValue = false;
____BAH_COMPILER_VAR_423.isFunc = false;
____BAH_COMPILER_VAR_423.isOper = false;
struct Tok tmpT =  ____BAH_COMPILER_VAR_423;
tmpT.type =  TOKEN_TYPE_VAR;
tmpT.cont =  "0";
char * ____BAH_COMPILER_VAR_424 =aet.str((struct string*)&aet);struct Tok rt =  parseReflect(tmpT,____BAH_COMPILER_VAR_424,elems,true,"","0");
char * aev =  genCompilerVar();
char * ____BAH_COMPILER_VAR_425 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n        struct reflectElement ");
long int strLen_1 = strlen(aev);
long int strLen_2 = strlen(" = ");
long int strLen_3 = strlen(rt.cont);
long int strLen_4 = strlen(";\n        ");
;                            
                    ____BAH_COMPILER_VAR_425 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_425+currStrOff, "\n        struct reflectElement ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_425+currStrOff, aev, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_425+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_425+currStrOff, rt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_425+currStrOff, ";\n        ", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_425[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_425));
char * ____BAH_COMPILER_VAR_426 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("&");
long int strLen_1 = strlen(aev);
;                            
                    ____BAH_COMPILER_VAR_426 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_426+currStrOff, "&", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_426+currStrOff, aev, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_426[currStrOff] = 0;
                }
                arrElem =  ____BAH_COMPILER_VAR_426;
}
else if (strHasPrefix(tt,"map:")) {
struct string aet =  string(tt);
aet.trimLeft((struct string*)&aet,4);
struct Tok ____BAH_COMPILER_VAR_427 = {};
____BAH_COMPILER_VAR_427.cont = "";
____BAH_COMPILER_VAR_427.ogCont = "";
____BAH_COMPILER_VAR_427.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_427.pos = 0;
____BAH_COMPILER_VAR_427.line = 1;
____BAH_COMPILER_VAR_427.begLine = 1;
____BAH_COMPILER_VAR_427.bahType = "";
____BAH_COMPILER_VAR_427.isValue = false;
____BAH_COMPILER_VAR_427.isFunc = false;
____BAH_COMPILER_VAR_427.isOper = false;
struct Tok tmpT =  ____BAH_COMPILER_VAR_427;
tmpT.type =  TOKEN_TYPE_VAR;
tmpT.cont =  "0";
char * ____BAH_COMPILER_VAR_428 =aet.str((struct string*)&aet);struct Tok rt =  parseReflect(tmpT,____BAH_COMPILER_VAR_428,elems,true,"","0");
char * aev =  genCompilerVar();
char * ____BAH_COMPILER_VAR_429 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n        struct reflectElement ");
long int strLen_1 = strlen(aev);
long int strLen_2 = strlen(" = ");
long int strLen_3 = strlen(rt.cont);
long int strLen_4 = strlen(";\n        ");
;                            
                    ____BAH_COMPILER_VAR_429 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_429+currStrOff, "\n        struct reflectElement ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_429+currStrOff, aev, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_429+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_429+currStrOff, rt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_429+currStrOff, ";\n        ", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_429[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_429));
char * ____BAH_COMPILER_VAR_430 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("&");
long int strLen_1 = strlen(aev);
;                            
                    ____BAH_COMPILER_VAR_430 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_430+currStrOff, "&", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_430+currStrOff, aev, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_430[currStrOff] = 0;
                }
                arrElem =  ____BAH_COMPILER_VAR_430;
}
char * isStruct =  "0";
struct cStruct* ts =  searchStruct(tt,elems);
char * structLayout =  "0";
if ((ts!=null)) {
isStruct =  "1";
structLayout =  genCompilerVar();
struct variable* ____BAH_COMPILER_VAR_431 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_431->name = "";
____BAH_COMPILER_VAR_431->type = "";
____BAH_COMPILER_VAR_431->isConst = false;
____BAH_COMPILER_VAR_431->constVal = "";
____BAH_COMPILER_VAR_431->isArray = false;
____BAH_COMPILER_VAR_431->from = "";
____BAH_COMPILER_VAR_431->outterScope = false;
____BAH_COMPILER_VAR_431->isGlobal = false;
struct variable* slv =  ____BAH_COMPILER_VAR_431;
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
struct structMemb* ____BAH_COMPILER_VAR_432 = memoryAlloc(sizeof(struct structMemb));
____BAH_COMPILER_VAR_432->name = "";
____BAH_COMPILER_VAR_432->type = "";
____BAH_COMPILER_VAR_432->isConst = false;
____BAH_COMPILER_VAR_432->constVal = "";
____BAH_COMPILER_VAR_432->isArray = false;
____BAH_COMPILER_VAR_432->from = "";
____BAH_COMPILER_VAR_432->outterScope = false;
____BAH_COMPILER_VAR_432->isGlobal = false;
____BAH_COMPILER_VAR_432->def = "";
____BAH_COMPILER_VAR_432->isFn = false;
struct structMemb* nm =  ____BAH_COMPILER_VAR_432;
*nm =  *m;
m =  nm;
m->type =  "ptr";
}
struct Tok ____BAH_COMPILER_VAR_433 = {};
____BAH_COMPILER_VAR_433.cont = "";
____BAH_COMPILER_VAR_433.ogCont = "";
____BAH_COMPILER_VAR_433.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_433.pos = 0;
____BAH_COMPILER_VAR_433.line = 1;
____BAH_COMPILER_VAR_433.begLine = 1;
____BAH_COMPILER_VAR_433.bahType = "";
____BAH_COMPILER_VAR_433.isValue = false;
____BAH_COMPILER_VAR_433.isFunc = false;
____BAH_COMPILER_VAR_433.isOper = false;
struct Tok tmpT =  ____BAH_COMPILER_VAR_433;
tmpT.type =  TOKEN_TYPE_VAR;
char * sep =  "->";
if ((strCount(tt,"*")==0)) {
sep =  ".";
}
struct string mCtype =  getCType(m->type,elems);
struct string offsetTT =  string(tt);
offsetTT.replace((struct string*)&offsetTT,"*","");
char * ____BAH_COMPILER_VAR_434 =mCtype.str((struct string*)&mCtype);char * ____BAH_COMPILER_VAR_435 =offsetTT.str((struct string*)&offsetTT);char * ____BAH_COMPILER_VAR_436 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("(");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_434);
long int strLen_2 = strlen("*)((char*)(");
long int strLen_3 = strlen(t.cont);
long int strLen_4 = strlen(") + offsetof(struct ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_435);
long int strLen_6 = strlen(", ");
long int strLen_7 = strlen(m->name);
long int strLen_8 = strlen("))");
;                            
                    ____BAH_COMPILER_VAR_436 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                    
                    memcpy(____BAH_COMPILER_VAR_436+currStrOff, "(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_436+currStrOff, ____BAH_COMPILER_VAR_434, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_436+currStrOff, "*)((char*)(", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_436+currStrOff, t.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_436+currStrOff, ") + offsetof(struct ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_436+currStrOff, ____BAH_COMPILER_VAR_435, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_436+currStrOff, ", ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_436+currStrOff, m->name, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_436+currStrOff, "))", strLen_8);
                    currStrOff += strLen_8;
                    
                    ____BAH_COMPILER_VAR_436[currStrOff] = 0;
                }
                tmpT.cont =  ____BAH_COMPILER_VAR_436;
char * ____BAH_COMPILER_VAR_437 =offsetTT.str((struct string*)&offsetTT);char * ____BAH_COMPILER_VAR_438 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("offsetof(struct ");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_437);
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(m->name);
long int strLen_4 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_438 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_438+currStrOff, "offsetof(struct ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_438+currStrOff, ____BAH_COMPILER_VAR_437, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_438+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_438+currStrOff, m->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_438+currStrOff, ")", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_438[currStrOff] = 0;
                }
                struct Tok rt =  parseReflect(tmpT,m->type,elems,true,m->name,____BAH_COMPILER_VAR_438);
char * ____BAH_COMPILER_VAR_439 =intToStr(i);char * ____BAH_COMPILER_VAR_440 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(structLayout);
long int strLen_1 = strlen("->data[");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_439);
long int strLen_3 = strlen("] = ");
long int strLen_4 = strlen(rt.cont);
long int strLen_5 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_440 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    memcpy(____BAH_COMPILER_VAR_440+currStrOff, structLayout, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_440+currStrOff, "->data[", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_440+currStrOff, ____BAH_COMPILER_VAR_439, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_440+currStrOff, "] = ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_440+currStrOff, rt.cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_440+currStrOff, ";\n", strLen_5);
                    currStrOff += strLen_5;
                    
                    ____BAH_COMPILER_VAR_440[currStrOff] = 0;
                }
                dataLayout =  dataLayout->add(dataLayout, rope(____BAH_COMPILER_VAR_440));
};
char * ____BAH_COMPILER_VAR_441 =intToStr(len(ts->members));char * ____BAH_COMPILER_VAR_442 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n        array(struct reflectElement) * ");
long int strLen_1 = strlen(structLayout);
long int strLen_2 = strlen(" = memoryAlloc(sizeof(array(struct reflectElement)));\n        ");
long int strLen_3 = strlen(structLayout);
long int strLen_4 = strlen("->elemSize = sizeof(struct reflectElement);\n        ");
long int strLen_5 = strlen(structLayout);
long int strLen_6 = strlen("->length = ");
long int strLen_7 = strlen(____BAH_COMPILER_VAR_441);
long int strLen_8 = strlen(";\n        ");
long int strLen_9 = strlen(structLayout);
long int strLen_10 = strlen("->data = memoryAlloc(");
long int strLen_11 = strlen(structLayout);
long int strLen_12 = strlen("->length * ");
long int strLen_13 = strlen(structLayout);
long int strLen_14 = strlen("->elemSize);\n        ");
;                            
                    ____BAH_COMPILER_VAR_442 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14);
                    
                    memcpy(____BAH_COMPILER_VAR_442+currStrOff, "\n        array(struct reflectElement) * ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_442+currStrOff, structLayout, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_442+currStrOff, " = memoryAlloc(sizeof(array(struct reflectElement)));\n        ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_442+currStrOff, structLayout, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_442+currStrOff, "->elemSize = sizeof(struct reflectElement);\n        ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_442+currStrOff, structLayout, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_442+currStrOff, "->length = ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_442+currStrOff, ____BAH_COMPILER_VAR_441, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_442+currStrOff, ";\n        ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_442+currStrOff, structLayout, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_442+currStrOff, "->data = memoryAlloc(", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_442+currStrOff, structLayout, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_442+currStrOff, "->length * ", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_442+currStrOff, structLayout, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_442+currStrOff, "->elemSize);\n        ", strLen_14);
                    currStrOff += strLen_14;
                    
                    ____BAH_COMPILER_VAR_442[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_442))->add(OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_442)), dataLayout);
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
struct variable* ____BAH_COMPILER_VAR_443 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_443->name = "";
____BAH_COMPILER_VAR_443->type = "";
____BAH_COMPILER_VAR_443->isConst = false;
____BAH_COMPILER_VAR_443->constVal = "";
____BAH_COMPILER_VAR_443->isArray = false;
____BAH_COMPILER_VAR_443->from = "";
____BAH_COMPILER_VAR_443->outterScope = false;
____BAH_COMPILER_VAR_443->isGlobal = false;
struct variable* rv =  ____BAH_COMPILER_VAR_443;
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
char * ____BAH_COMPILER_VAR_444 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_445 =name.str((struct string*)&name);char * ____BAH_COMPILER_VAR_446 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("struct reflectElement ");
long int strLen_1 = strlen(rv->name);
long int strLen_2 = strlen(" = __reflect(");
long int strLen_3 = strlen(amp);
long int strLen_4 = strlen(t.cont);
long int strLen_5 = strlen(", sizeof(");
long int strLen_6 = strlen(____BAH_COMPILER_VAR_444);
long int strLen_7 = strlen("), \"");
long int strLen_8 = strlen(tt);
long int strLen_9 = strlen("\", \"");
long int strLen_10 = strlen(____BAH_COMPILER_VAR_445);
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
                    ____BAH_COMPILER_VAR_446 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14 + strLen_15 + strLen_16 + strLen_17 + strLen_18 + strLen_19 + strLen_20 + strLen_21);
                    
                    memcpy(____BAH_COMPILER_VAR_446+currStrOff, "struct reflectElement ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_446+currStrOff, rv->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_446+currStrOff, " = __reflect(", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_446+currStrOff, amp, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_446+currStrOff, t.cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_446+currStrOff, ", sizeof(", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_446+currStrOff, ____BAH_COMPILER_VAR_444, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_446+currStrOff, "), \"", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_446+currStrOff, tt, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_446+currStrOff, "\", \"", strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_446+currStrOff, ____BAH_COMPILER_VAR_445, strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_446+currStrOff, "\", ", strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_446+currStrOff, isArr, strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_446+currStrOff, ", ", strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_446+currStrOff, arrElem, strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_446+currStrOff, ", ", strLen_15);
                    currStrOff += strLen_15;
                    
                    memcpy(____BAH_COMPILER_VAR_446+currStrOff, isStruct, strLen_16);
                    currStrOff += strLen_16;
                    
                    memcpy(____BAH_COMPILER_VAR_446+currStrOff, ", ", strLen_17);
                    currStrOff += strLen_17;
                    
                    memcpy(____BAH_COMPILER_VAR_446+currStrOff, structLayout, strLen_18);
                    currStrOff += strLen_18;
                    
                    memcpy(____BAH_COMPILER_VAR_446+currStrOff, ", ", strLen_19);
                    currStrOff += strLen_19;
                    
                    memcpy(____BAH_COMPILER_VAR_446+currStrOff, offset, strLen_20);
                    currStrOff += strLen_20;
                    
                    memcpy(____BAH_COMPILER_VAR_446+currStrOff, ");\n", strLen_21);
                    currStrOff += strLen_21;
                    
                    ____BAH_COMPILER_VAR_446[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_446));
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
char * ____BAH_COMPILER_VAR_447 =fnarg1t.str((struct string*)&fnarg1t);char * ____BAH_COMPILER_VAR_448 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("(");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_447);
long int strLen_2 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_448 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_448+currStrOff, "(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_448+currStrOff, ____BAH_COMPILER_VAR_447, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_448+currStrOff, ")", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_448[currStrOff] = 0;
                }
                varName.prepend((struct string*)&varName,____BAH_COMPILER_VAR_448);
}
char * ____BAH_COMPILER_VAR_449 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(fnName);
long int strLen_1 = strlen("(");
;                            
                    ____BAH_COMPILER_VAR_449 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_449+currStrOff, fnName, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_449+currStrOff, "(", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_449[currStrOff] = 0;
                }
                ot.cont =  ____BAH_COMPILER_VAR_449;
long int paramIndex =  0;
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
if ((varName.length>0)) {
struct Tok ____BAH_COMPILER_VAR_450 = {};
____BAH_COMPILER_VAR_450.cont = "";
____BAH_COMPILER_VAR_450.ogCont = "";
____BAH_COMPILER_VAR_450.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_450.pos = 0;
____BAH_COMPILER_VAR_450.line = 1;
____BAH_COMPILER_VAR_450.begLine = 1;
____BAH_COMPILER_VAR_450.bahType = "";
____BAH_COMPILER_VAR_450.isValue = false;
____BAH_COMPILER_VAR_450.isFunc = false;
____BAH_COMPILER_VAR_450.isOper = false;
struct Tok tk =  ____BAH_COMPILER_VAR_450;
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
struct Tok ____BAH_COMPILER_VAR_451 = {};
____BAH_COMPILER_VAR_451.cont = "";
____BAH_COMPILER_VAR_451.ogCont = "";
____BAH_COMPILER_VAR_451.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_451.pos = 0;
____BAH_COMPILER_VAR_451.line = 1;
____BAH_COMPILER_VAR_451.begLine = 1;
____BAH_COMPILER_VAR_451.bahType = "";
____BAH_COMPILER_VAR_451.isValue = false;
____BAH_COMPILER_VAR_451.isFunc = false;
____BAH_COMPILER_VAR_451.isOper = false;
tk =  ____BAH_COMPILER_VAR_451;
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
char * ____BAH_COMPILER_VAR_452 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ot.cont);
long int strLen_1 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_452 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_452+currStrOff, ot.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_452+currStrOff, t.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_452[currStrOff] = 0;
                }
                ot.cont =  ____BAH_COMPILER_VAR_452;
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
char * ____BAH_COMPILER_VAR_453 =intToStr(ot.line);char * ____BAH_COMPILER_VAR_454 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\"");
long int strLen_1 = strlen(compilerState.currentFile);
long int strLen_2 = strlen(":");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_453);
long int strLen_4 = strlen("\"");
;                            
                    ____BAH_COMPILER_VAR_454 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_454+currStrOff, "\"", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_454+currStrOff, compilerState.currentFile, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_454+currStrOff, ":", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_454+currStrOff, ____BAH_COMPILER_VAR_453, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_454+currStrOff, "\"", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_454[currStrOff] = 0;
                }
                char * currLine =  ____BAH_COMPILER_VAR_454;

                    if (memory->length <= len(memory)-1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1691): memory[%d] with length %d\n", len(memory)-1, memory->length);
                        exit(1);
                    };
                    struct Tok par =  memory->data[len(memory)-1];
long int cl =  par.line;
struct Tok ____BAH_COMPILER_VAR_455 = {};
____BAH_COMPILER_VAR_455.cont = "";
____BAH_COMPILER_VAR_455.ogCont = "";
____BAH_COMPILER_VAR_455.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_455.pos = 0;
____BAH_COMPILER_VAR_455.line = 1;
____BAH_COMPILER_VAR_455.begLine = 1;
____BAH_COMPILER_VAR_455.bahType = "";
____BAH_COMPILER_VAR_455.isValue = false;
____BAH_COMPILER_VAR_455.isFunc = false;
____BAH_COMPILER_VAR_455.isOper = false;
____BAH_COMPILER_VAR_455.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_455.cont = ",";
____BAH_COMPILER_VAR_455.line = cl;

{
long nLength = len(memory)-1;
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)-1] =  ____BAH_COMPILER_VAR_455;
memory->length = nLength+1;
} else {
memory->data[len(memory)-1] =  ____BAH_COMPILER_VAR_455;
}
};
struct Tok ____BAH_COMPILER_VAR_456 = {};
____BAH_COMPILER_VAR_456.cont = "";
____BAH_COMPILER_VAR_456.ogCont = "";
____BAH_COMPILER_VAR_456.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_456.pos = 0;
____BAH_COMPILER_VAR_456.line = 1;
____BAH_COMPILER_VAR_456.begLine = 1;
____BAH_COMPILER_VAR_456.bahType = "";
____BAH_COMPILER_VAR_456.isValue = false;
____BAH_COMPILER_VAR_456.isFunc = false;
____BAH_COMPILER_VAR_456.isOper = false;
____BAH_COMPILER_VAR_456.type = TOKEN_TYPE_STR;
____BAH_COMPILER_VAR_456.cont = currLine;
____BAH_COMPILER_VAR_456.line = cl;

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] =  ____BAH_COMPILER_VAR_456;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  ____BAH_COMPILER_VAR_456;
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
char * ____BAH_COMPILER_VAR_457 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(fnName);
long int strLen_1 = strlen("(");
;                            
                    ____BAH_COMPILER_VAR_457 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_457+currStrOff, fnName, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_457+currStrOff, "(", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_457[currStrOff] = 0;
                }
                ot.cont =  ____BAH_COMPILER_VAR_457;
fn =  searchFunc(fnName,elems,true);
}
else if ((strcmp(fnName, "__dumpSymbols") == 0)) {
char * ____BAH_COMPILER_VAR_458 =intToStr(ot.line);char * ____BAH_COMPILER_VAR_459 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\"");
long int strLen_1 = strlen(compilerState.currentFile);
long int strLen_2 = strlen(":");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_458);
long int strLen_4 = strlen("\"");
;                            
                    ____BAH_COMPILER_VAR_459 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_459+currStrOff, "\"", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_459+currStrOff, compilerState.currentFile, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_459+currStrOff, ":", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_459+currStrOff, ____BAH_COMPILER_VAR_458, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_459+currStrOff, "\"", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_459[currStrOff] = 0;
                }
                char * currLine =  ____BAH_COMPILER_VAR_459;

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
struct variable* ____BAH_COMPILER_VAR_460 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_460->name = "";
____BAH_COMPILER_VAR_460->type = "";
____BAH_COMPILER_VAR_460->isConst = false;
____BAH_COMPILER_VAR_460->constVal = "";
____BAH_COMPILER_VAR_460->isArray = false;
____BAH_COMPILER_VAR_460->from = "";
____BAH_COMPILER_VAR_460->outterScope = false;
____BAH_COMPILER_VAR_460->isGlobal = false;
____BAH_COMPILER_VAR_460->name = genCompilerVar();
____BAH_COMPILER_VAR_460->type = "[]reflectElement";
____BAH_COMPILER_VAR_460->isArray = true;
struct variable* tmpV =  ____BAH_COMPILER_VAR_460;

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
char * ____BAH_COMPILER_VAR_461 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("&");
long int strLen_1 = strlen(v->name);
;                            
                    ____BAH_COMPILER_VAR_461 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_461+currStrOff, "&", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_461+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_461[currStrOff] = 0;
                }
                vname =  ____BAH_COMPILER_VAR_461;
}
struct Tok ____BAH_COMPILER_VAR_462 = {};
____BAH_COMPILER_VAR_462.cont = "";
____BAH_COMPILER_VAR_462.ogCont = "";
____BAH_COMPILER_VAR_462.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_462.pos = 0;
____BAH_COMPILER_VAR_462.line = 1;
____BAH_COMPILER_VAR_462.begLine = 1;
____BAH_COMPILER_VAR_462.bahType = "";
____BAH_COMPILER_VAR_462.isValue = false;
____BAH_COMPILER_VAR_462.isFunc = false;
____BAH_COMPILER_VAR_462.isOper = false;
____BAH_COMPILER_VAR_462.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_462.cont = vname;
____BAH_COMPILER_VAR_462.bahType = v->type;
____BAH_COMPILER_VAR_462.isValue = true;
struct Tok tmpT =  ____BAH_COMPILER_VAR_462;
tmpT =  parseReflect(tmpT,v->type,elems,true,v->name,"0");
char * ____BAH_COMPILER_VAR_463 =intToStr(j);char * ____BAH_COMPILER_VAR_464 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tmpV->name);
long int strLen_1 = strlen("->data[");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_463);
long int strLen_3 = strlen("] = ");
long int strLen_4 = strlen(tmpT.cont);
long int strLen_5 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_464 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    memcpy(____BAH_COMPILER_VAR_464+currStrOff, tmpV->name, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_464+currStrOff, "->data[", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_464+currStrOff, ____BAH_COMPILER_VAR_463, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_464+currStrOff, "] = ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_464+currStrOff, tmpT.cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_464+currStrOff, ";\n", strLen_5);
                    currStrOff += strLen_5;
                    
                    ____BAH_COMPILER_VAR_464[currStrOff] = 0;
                }
                char * ____BAH_COMPILER_VAR_465 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(decls);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_464);
;                            
                    ____BAH_COMPILER_VAR_465 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_465+currStrOff, decls, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_465+currStrOff, ____BAH_COMPILER_VAR_464, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_465[currStrOff] = 0;
                }
                decls =  ____BAH_COMPILER_VAR_465;
};
char * ____BAH_COMPILER_VAR_466 =intToStr(len(symbols));char * ____BAH_COMPILER_VAR_467 =intToStr(len(symbols));char * ____BAH_COMPILER_VAR_468 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n                        array(struct reflectElement)* ");
long int strLen_1 = strlen(tmpV->name);
long int strLen_2 = strlen(" = memoryAlloc(sizeof(array(struct reflectElement)));\n                        ");
long int strLen_3 = strlen(tmpV->name);
long int strLen_4 = strlen("->data = memoryAlloc(sizeof(struct reflectElement) * ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_466);
long int strLen_6 = strlen(");\n                        ");
long int strLen_7 = strlen(tmpV->name);
long int strLen_8 = strlen("->length = ");
long int strLen_9 = strlen(____BAH_COMPILER_VAR_467);
long int strLen_10 = strlen(";\n                        ");
long int strLen_11 = strlen(tmpV->name);
long int strLen_12 = strlen("->elemSize = sizeof(struct reflectElement);\n                        ");
long int strLen_13 = strlen(decls);
long int strLen_14 = strlen("\n                        ");
;                            
                    ____BAH_COMPILER_VAR_468 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14);
                    
                    memcpy(____BAH_COMPILER_VAR_468+currStrOff, "\n                        array(struct reflectElement)* ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_468+currStrOff, tmpV->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_468+currStrOff, " = memoryAlloc(sizeof(array(struct reflectElement)));\n                        ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_468+currStrOff, tmpV->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_468+currStrOff, "->data = memoryAlloc(sizeof(struct reflectElement) * ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_468+currStrOff, ____BAH_COMPILER_VAR_466, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_468+currStrOff, ");\n                        ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_468+currStrOff, tmpV->name, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_468+currStrOff, "->length = ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_468+currStrOff, ____BAH_COMPILER_VAR_467, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_468+currStrOff, ";\n                        ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_468+currStrOff, tmpV->name, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_468+currStrOff, "->elemSize = sizeof(struct reflectElement);\n                        ", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_468+currStrOff, decls, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_468+currStrOff, "\n                        ", strLen_14);
                    currStrOff += strLen_14;
                    
                    ____BAH_COMPILER_VAR_468[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_468));
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
____BAH_COMPILER_VAR_469.cont = tmpV->name;
____BAH_COMPILER_VAR_469.line = cl;
____BAH_COMPILER_VAR_469.isValue = true;

{
long nLength = 0;
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[0] =  ____BAH_COMPILER_VAR_469;
memory->length = nLength+1;
} else {
memory->data[0] =  ____BAH_COMPILER_VAR_469;
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
char * ____BAH_COMPILER_VAR_470 =intToStr(ot.line);char * ____BAH_COMPILER_VAR_471 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\"");
long int strLen_1 = strlen(compilerState.currentFile);
long int strLen_2 = strlen(":");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_470);
long int strLen_4 = strlen("\"");
;                            
                    ____BAH_COMPILER_VAR_471 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_471+currStrOff, "\"", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_471+currStrOff, compilerState.currentFile, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_471+currStrOff, ":", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_471+currStrOff, ____BAH_COMPILER_VAR_470, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_471+currStrOff, "\"", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_471[currStrOff] = 0;
                }
                char * currLine =  ____BAH_COMPILER_VAR_471;

                    if (memory->length <= len(memory)-1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1764): memory[%d] with length %d\n", len(memory)-1, memory->length);
                        exit(1);
                    };
                    struct Tok par =  memory->data[len(memory)-1];
long int cl =  par.line;
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
____BAH_COMPILER_VAR_472.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_472.cont = "__dumpSymbols";
____BAH_COMPILER_VAR_472.line = cl;
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
____BAH_COMPILER_VAR_473.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_473.cont = "(";
____BAH_COMPILER_VAR_473.line = cl;
struct Tok ____BAH_COMPILER_VAR_474 = {};
____BAH_COMPILER_VAR_474.cont = "";
____BAH_COMPILER_VAR_474.ogCont = "";
____BAH_COMPILER_VAR_474.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_474.pos = 0;
____BAH_COMPILER_VAR_474.line = 1;
____BAH_COMPILER_VAR_474.begLine = 1;
____BAH_COMPILER_VAR_474.bahType = "";
____BAH_COMPILER_VAR_474.isValue = false;
____BAH_COMPILER_VAR_474.isFunc = false;
____BAH_COMPILER_VAR_474.isOper = false;
____BAH_COMPILER_VAR_474.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_474.cont = ")";
____BAH_COMPILER_VAR_474.line = cl;
memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 3;
memory->elemSize = sizeof(struct Tok);
memory->data = memoryAlloc(sizeof(struct Tok) * 50);memory->data[0] = ____BAH_COMPILER_VAR_472;
memory->data[1] = ____BAH_COMPILER_VAR_473;
memory->data[2] = ____BAH_COMPILER_VAR_474;
memory =  parseFnCall(memory,(lineType)-1,elems);
struct Tok ____BAH_COMPILER_VAR_475 = {};
____BAH_COMPILER_VAR_475.cont = "";
____BAH_COMPILER_VAR_475.ogCont = "";
____BAH_COMPILER_VAR_475.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_475.pos = 0;
____BAH_COMPILER_VAR_475.line = 1;
____BAH_COMPILER_VAR_475.begLine = 1;
____BAH_COMPILER_VAR_475.bahType = "";
____BAH_COMPILER_VAR_475.isValue = false;
____BAH_COMPILER_VAR_475.isFunc = false;
____BAH_COMPILER_VAR_475.isOper = false;
____BAH_COMPILER_VAR_475.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_475.cont = ",";
____BAH_COMPILER_VAR_475.line = cl;

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] =  ____BAH_COMPILER_VAR_475;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  ____BAH_COMPILER_VAR_475;
}
};
struct Tok ____BAH_COMPILER_VAR_476 = {};
____BAH_COMPILER_VAR_476.cont = "";
____BAH_COMPILER_VAR_476.ogCont = "";
____BAH_COMPILER_VAR_476.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_476.pos = 0;
____BAH_COMPILER_VAR_476.line = 1;
____BAH_COMPILER_VAR_476.begLine = 1;
____BAH_COMPILER_VAR_476.bahType = "";
____BAH_COMPILER_VAR_476.isValue = false;
____BAH_COMPILER_VAR_476.isFunc = false;
____BAH_COMPILER_VAR_476.isOper = false;
____BAH_COMPILER_VAR_476.type = TOKEN_TYPE_STR;
____BAH_COMPILER_VAR_476.cont = currLine;
____BAH_COMPILER_VAR_476.line = cl;

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] =  ____BAH_COMPILER_VAR_476;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  ____BAH_COMPILER_VAR_476;
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
char * ____BAH_COMPILER_VAR_477 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(fnName);
long int strLen_1 = strlen("(");
;                            
                    ____BAH_COMPILER_VAR_477 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_477+currStrOff, fnName, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_477+currStrOff, "(", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_477[currStrOff] = 0;
                }
                ot.cont =  ____BAH_COMPILER_VAR_477;
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
char * ____BAH_COMPILER_VAR_478 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tp);
long int strLen_1 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_478 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_478+currStrOff, tp, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_478+currStrOff, t.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_478[currStrOff] = 0;
                }
                tp =  ____BAH_COMPILER_VAR_478;
};
struct string cType =  getCType(tp,elems);
char * ____BAH_COMPILER_VAR_479 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_480 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_479);
long int strLen_1 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_480 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_480+currStrOff, ____BAH_COMPILER_VAR_479, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_480+currStrOff, ")", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_480[currStrOff] = 0;
                }
                char * ____BAH_COMPILER_VAR_481 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ot.cont);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_480);
;                            
                    ____BAH_COMPILER_VAR_481 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_481+currStrOff, ot.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_481+currStrOff, ____BAH_COMPILER_VAR_480, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_481[currStrOff] = 0;
                }
                ot.cont =  ____BAH_COMPILER_VAR_481;
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
char * ____BAH_COMPILER_VAR_482 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(tt);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(arg->type);
long int strLen_4 = strlen(" in function call.");
;                            
                    ____BAH_COMPILER_VAR_482 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_482+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_482+currStrOff, tt, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_482+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_482+currStrOff, arg->type, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_482+currStrOff, " in function call.", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_482[currStrOff] = 0;
                }
                throwErr(&t,____BAH_COMPILER_VAR_482);
}
if (((t.type==TOKEN_TYPE_FUNC)&&(strHasPrefix(t.cont,"noCheck(")==false))) {
struct string ____BAH_COMPILER_VAR_483 =string(t.cont);char * afnName =  splitStringBefore(____BAH_COMPILER_VAR_483,"(");
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
char * ____BAH_COMPILER_VAR_484 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ot.cont);
long int strLen_1 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_484 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_484+currStrOff, ot.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_484+currStrOff, t.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_484[currStrOff] = 0;
                }
                ot.cont =  ____BAH_COMPILER_VAR_484;
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
char * ____BAH_COMPILER_VAR_485 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ot.cont);
long int strLen_1 = strlen(",");
;                            
                    ____BAH_COMPILER_VAR_485 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_485+currStrOff, ot.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_485+currStrOff, ",", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_485[currStrOff] = 0;
                }
                ot.cont =  ____BAH_COMPILER_VAR_485;
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
char * ____BAH_COMPILER_VAR_486 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ot.cont);
long int strLen_1 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_486 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_486+currStrOff, ot.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_486+currStrOff, ")", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_486[currStrOff] = 0;
                }
                ot.cont =  ____BAH_COMPILER_VAR_486;
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
char * ____BAH_COMPILER_VAR_487 =arrType.str((struct string*)&arrType);char * ____BAH_COMPILER_VAR_488 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("memoryAlloc(sizeof(");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_487);
long int strLen_2 = strlen("))");
;                            
                    ____BAH_COMPILER_VAR_488 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_488+currStrOff, "memoryAlloc(sizeof(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_488+currStrOff, ____BAH_COMPILER_VAR_487, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_488+currStrOff, "))", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_488[currStrOff] = 0;
                }
                char * code =  ____BAH_COMPILER_VAR_488;
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
struct variable* ____BAH_COMPILER_VAR_489 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_489->name = "";
____BAH_COMPILER_VAR_489->type = "";
____BAH_COMPILER_VAR_489->isConst = false;
____BAH_COMPILER_VAR_489->constVal = "";
____BAH_COMPILER_VAR_489->isArray = false;
____BAH_COMPILER_VAR_489->from = "";
____BAH_COMPILER_VAR_489->outterScope = false;
____BAH_COMPILER_VAR_489->isGlobal = false;
struct variable* tmpV =  ____BAH_COMPILER_VAR_489;
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
char * ____BAH_COMPILER_VAR_490 =elemType.str((struct string*)&elemType);struct string cType =  getCType(____BAH_COMPILER_VAR_490,elems);
char * ____BAH_COMPILER_VAR_491 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_492 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n                array(");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_491);
long int strLen_2 = strlen(") * ");
long int strLen_3 = strlen(tmpV->name);
long int strLen_4 = strlen(" = ");
long int strLen_5 = strlen(innerCode);
long int strLen_6 = strlen(";\n                ");
long int strLen_7 = strlen(NEXT_LINE);
long int strLen_8 = strlen("\n                ");
;                            
                    ____BAH_COMPILER_VAR_492 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                    
                    memcpy(____BAH_COMPILER_VAR_492+currStrOff, "\n                array(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_492+currStrOff, ____BAH_COMPILER_VAR_491, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_492+currStrOff, ") * ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_492+currStrOff, tmpV->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_492+currStrOff, " = ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_492+currStrOff, innerCode, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_492+currStrOff, ";\n                ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_492+currStrOff, NEXT_LINE, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_492+currStrOff, "\n                ", strLen_8);
                    currStrOff += strLen_8;
                    
                    ____BAH_COMPILER_VAR_492[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_492));
NEXT_LINE =  oldNL;
struct Tok ____BAH_COMPILER_VAR_493 = {};
____BAH_COMPILER_VAR_493.cont = "";
____BAH_COMPILER_VAR_493.ogCont = "";
____BAH_COMPILER_VAR_493.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_493.pos = 0;
____BAH_COMPILER_VAR_493.line = 1;
____BAH_COMPILER_VAR_493.begLine = 1;
____BAH_COMPILER_VAR_493.bahType = "";
____BAH_COMPILER_VAR_493.isValue = false;
____BAH_COMPILER_VAR_493.isFunc = false;
____BAH_COMPILER_VAR_493.isOper = false;
____BAH_COMPILER_VAR_493.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_493.cont = tmpV->name;
____BAH_COMPILER_VAR_493.bahType = elemType.str((struct string*)&elemType);
____BAH_COMPILER_VAR_493.isValue = true;
t =  ____BAH_COMPILER_VAR_493;
}
char * tt =  getTypeFromToken(&t,true,elems);
if ((compTypes(tt,elemBahTypeStr)==false)) {
char * ____BAH_COMPILER_VAR_494 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(tt);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(elemBahTypeStr);
;                            
                    ____BAH_COMPILER_VAR_494 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                    
                    memcpy(____BAH_COMPILER_VAR_494+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_494+currStrOff, tt, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_494+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_494+currStrOff, elemBahTypeStr, strLen_3);
                    currStrOff += strLen_3;
                    
                    ____BAH_COMPILER_VAR_494[currStrOff] = 0;
                }
                throwErr(&t,____BAH_COMPILER_VAR_494);
}
char * strArrayLength =  intToStr(arrayLength);
arrayLength =  arrayLength + 1;
char * ____BAH_COMPILER_VAR_495 =null;
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
                    ____BAH_COMPILER_VAR_495 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                    
                    memcpy(____BAH_COMPILER_VAR_495+currStrOff, NEXT_LINE, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_495+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_495+currStrOff, "->data[", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_495+currStrOff, strArrayLength, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_495+currStrOff, "] = ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_495+currStrOff, t.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_495+currStrOff, ";\n", strLen_6);
                    currStrOff += strLen_6;
                    
                    ____BAH_COMPILER_VAR_495[currStrOff] = 0;
                }
                NEXT_LINE =  ____BAH_COMPILER_VAR_495;
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
char * ____BAH_COMPILER_VAR_496 =null;
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
                    ____BAH_COMPILER_VAR_496 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                    
                    memcpy(____BAH_COMPILER_VAR_496+currStrOff, v->name, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_496+currStrOff, "->data = memoryAlloc(sizeof(", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_496+currStrOff, elemTypeStr, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_496+currStrOff, ") * ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_496+currStrOff, allocLengthStr, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_496+currStrOff, ");", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_496+currStrOff, NEXT_LINE, strLen_6);
                    currStrOff += strLen_6;
                    
                    ____BAH_COMPILER_VAR_496[currStrOff] = 0;
                }
                NEXT_LINE =  ____BAH_COMPILER_VAR_496;
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
char * ____BAH_COMPILER_VAR_497 =null;
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
                    ____BAH_COMPILER_VAR_497 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9);
                    
                    memcpy(____BAH_COMPILER_VAR_497+currStrOff, "\n", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_497+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_497+currStrOff, "->length = ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_497+currStrOff, strArrayLength, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_497+currStrOff, ";\n", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_497+currStrOff, v->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_497+currStrOff, "->elemSize = sizeof(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_497+currStrOff, elemTypeStr, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_497+currStrOff, ");\n", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_497+currStrOff, NEXT_LINE, strLen_9);
                    currStrOff += strLen_9;
                    
                    ____BAH_COMPILER_VAR_497[currStrOff] = 0;
                }
                NEXT_LINE =  ____BAH_COMPILER_VAR_497;
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
char * ____BAH_COMPILER_VAR_498 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ft.cont);
long int strLen_1 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_498 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_498+currStrOff, ft.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_498+currStrOff, ";\n", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_498[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_498));
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
struct variable* ____BAH_COMPILER_VAR_499 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_499->name = "";
____BAH_COMPILER_VAR_499->type = "";
____BAH_COMPILER_VAR_499->isConst = false;
____BAH_COMPILER_VAR_499->constVal = "";
____BAH_COMPILER_VAR_499->isArray = false;
____BAH_COMPILER_VAR_499->from = "";
____BAH_COMPILER_VAR_499->outterScope = false;
____BAH_COMPILER_VAR_499->isGlobal = false;
v =  ____BAH_COMPILER_VAR_499;
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
char * ____BAH_COMPILER_VAR_500 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot use '");
long int strLen_1 = strlen(lt.cont);
long int strLen_2 = strlen("' on non declared {TOKEN} variable.");
;                            
                    ____BAH_COMPILER_VAR_500 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_500+currStrOff, "Cannot use '", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_500+currStrOff, lt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_500+currStrOff, "' on non declared {TOKEN} variable.", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_500[currStrOff] = 0;
                }
                throwErr(&ft,____BAH_COMPILER_VAR_500);
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
____BAH_COMPILER_VAR_501.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_501.cont = "=";
____BAH_COMPILER_VAR_501.isValue = false;

{
long nLength = 1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[1] =  ____BAH_COMPILER_VAR_501;
nl->length = nLength+1;
} else {
nl->data[1] =  ____BAH_COMPILER_VAR_501;
}
};
char * c =  "";
if ((strcmp(lt.cont, "++") == 0)) {
char * ____BAH_COMPILER_VAR_502 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ft.cont);
long int strLen_1 = strlen("+1");
;                            
                    ____BAH_COMPILER_VAR_502 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_502+currStrOff, ft.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_502+currStrOff, "+1", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_502[currStrOff] = 0;
                }
                c =  ____BAH_COMPILER_VAR_502;
}
else if ((strcmp(lt.cont, "--") == 0)) {
char * ____BAH_COMPILER_VAR_503 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ft.cont);
long int strLen_1 = strlen("-1");
;                            
                    ____BAH_COMPILER_VAR_503 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_503+currStrOff, ft.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_503+currStrOff, "-1", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_503[currStrOff] = 0;
                }
                c =  ____BAH_COMPILER_VAR_503;
}
long int ltl =  lt.line;
long int ltp =  lt.pos;
char * ltc =  lt.cont;
struct Tok ____BAH_COMPILER_VAR_504 = {};
____BAH_COMPILER_VAR_504.cont = "";
____BAH_COMPILER_VAR_504.ogCont = "";
____BAH_COMPILER_VAR_504.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_504.pos = 0;
____BAH_COMPILER_VAR_504.line = 1;
____BAH_COMPILER_VAR_504.begLine = 1;
____BAH_COMPILER_VAR_504.bahType = "";
____BAH_COMPILER_VAR_504.isValue = false;
____BAH_COMPILER_VAR_504.isFunc = false;
____BAH_COMPILER_VAR_504.isOper = false;
____BAH_COMPILER_VAR_504.type = TOKEN_TYPE_INT;
____BAH_COMPILER_VAR_504.cont = c;
____BAH_COMPILER_VAR_504.line = ltl;
____BAH_COMPILER_VAR_504.ogCont = ltc;
____BAH_COMPILER_VAR_504.pos = ltp;
____BAH_COMPILER_VAR_504.isOper = true;
____BAH_COMPILER_VAR_504.isValue = true;

{
long nLength = 2;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[2] =  ____BAH_COMPILER_VAR_504;
nl->length = nLength+1;
} else {
nl->data[2] =  ____BAH_COMPILER_VAR_504;
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

                int ____BAH_COMPILER_VAR_505 = 0;
                for(int i=len(equalsTokens)-1; i != -1; i--) {
                    if (equalsTokens->data[i] != 0 && strcmp(equalsTokens->data[i], operT.cont) == 0) {
                        ____BAH_COMPILER_VAR_505 = 1;
                        break;
                    };
                };
                if ((____BAH_COMPILER_VAR_505&&(strcmp(operT.cont, "=") != 0))) {

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
char * ____BAH_COMPILER_VAR_506 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(currentType);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_506 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_506+currStrOff, currentType, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_506+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_506+currStrOff, t.cont, strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_506[currStrOff] = 0;
                }
                currentType =  ____BAH_COMPILER_VAR_506;
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
char * ____BAH_COMPILER_VAR_507 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("chan:");
long int strLen_1 = strlen(nt.cont);
;                            
                    ____BAH_COMPILER_VAR_507 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_507+currStrOff, "chan:", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_507+currStrOff, nt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_507[currStrOff] = 0;
                }
                v->type =  ____BAH_COMPILER_VAR_507;
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
char * ____BAH_COMPILER_VAR_508 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("map:");
long int strLen_1 = strlen(nt.cont);
;                            
                    ____BAH_COMPILER_VAR_508 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_508+currStrOff, "map:", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_508+currStrOff, nt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_508[currStrOff] = 0;
                }
                v->type =  ____BAH_COMPILER_VAR_508;
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
char * ____BAH_COMPILER_VAR_509 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("buffer:");
long int strLen_1 = strlen(nt.cont);
;                            
                    ____BAH_COMPILER_VAR_509 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_509+currStrOff, "buffer:", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_509+currStrOff, nt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_509[currStrOff] = 0;
                }
                v->type =  ____BAH_COMPILER_VAR_509;
struct variable* ____BAH_COMPILER_VAR_510 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_510->name = "";
____BAH_COMPILER_VAR_510->type = "";
____BAH_COMPILER_VAR_510->isConst = false;
____BAH_COMPILER_VAR_510->constVal = "";
____BAH_COMPILER_VAR_510->isArray = false;
____BAH_COMPILER_VAR_510->from = "";
____BAH_COMPILER_VAR_510->outterScope = false;
____BAH_COMPILER_VAR_510->isGlobal = false;
struct variable* av =  ____BAH_COMPILER_VAR_510;
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
char * ____BAH_COMPILER_VAR_511 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("char ");
long int strLen_1 = strlen(av->name);
long int strLen_2 = strlen("[");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen("];");
;                            
                    ____BAH_COMPILER_VAR_511 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_511+currStrOff, "char ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_511+currStrOff, av->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_511+currStrOff, "[", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_511+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_511+currStrOff, "];", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_511[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_511));
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
char * ____BAH_COMPILER_VAR_512 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(tp);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(v->type);
long int strLen_4 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_512 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_512+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_512+currStrOff, tp, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_512+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_512+currStrOff, v->type, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_512+currStrOff, ".", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_512[currStrOff] = 0;
                }
                throwErr(&t,____BAH_COMPILER_VAR_512);
}
}
else {
if ((strlen(currentType)==0)) {
if ((strlen(v->type)==0)) {
v->type =  tp;
}
else {
if ((compTypes(tp,v->type)==false)) {
char * ____BAH_COMPILER_VAR_513 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(tp);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(v->type);
long int strLen_4 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_513 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_513+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_513+currStrOff, tp, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_513+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_513+currStrOff, v->type, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_513+currStrOff, ".", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_513[currStrOff] = 0;
                }
                throwErr(&t,____BAH_COMPILER_VAR_513);
}
}
}
}
if (((strlen(t.cont)>0)&&(strHasPrefix(t.cont,"{")==false))) {
char * ____BAH_COMPILER_VAR_514 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_514 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_514+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_514+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_514+currStrOff, t.cont, strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_514[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_514;
if (((t.isOper==false)&&(RCPavailable()==true))) {
struct variable* iv =  searchVar(t.cont,elems);
if (((iv!=null)&&(iv->isConst==false))) {
toVar =  true;
isPointedVar =  strHasPrefix(t.cont,"&");
struct cStruct* s =  searchStruct(iv->type,elems);
if ((((s!=null)&&(strCount(iv->type,"*")==0))&&(s->isBinding==false))) {
if ((strCount(iv->name,"*")==0)) {
char * ____BAH_COMPILER_VAR_515 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen("; RCP_incrCounter(");
long int strLen_2 = strlen(iv->name);
long int strLen_3 = strlen(".__RCP_counter)");
;                            
                    ____BAH_COMPILER_VAR_515 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                    
                    memcpy(____BAH_COMPILER_VAR_515+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_515+currStrOff, "; RCP_incrCounter(", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_515+currStrOff, iv->name, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_515+currStrOff, ".__RCP_counter)", strLen_3);
                    currStrOff += strLen_3;
                    
                    ____BAH_COMPILER_VAR_515[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_515;
}
else {
struct string ivn =  string(iv->name);
ivn.replace((struct string*)&ivn,"*","");
char * ____BAH_COMPILER_VAR_516 =ivn.str((struct string*)&ivn);char * ____BAH_COMPILER_VAR_517 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen("; RCP_incr(");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_516);
long int strLen_3 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_517 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                    
                    memcpy(____BAH_COMPILER_VAR_517+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_517+currStrOff, "; RCP_incr(", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_517+currStrOff, ____BAH_COMPILER_VAR_516, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_517+currStrOff, ")", strLen_3);
                    currStrOff += strLen_3;
                    
                    ____BAH_COMPILER_VAR_517[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_517;
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
char * ____BAH_COMPILER_VAR_518 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_518 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_518+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_518+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_518+currStrOff, t.cont, strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_518[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_518;
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
char * ____BAH_COMPILER_VAR_519 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot change the type of already declared var '");
long int strLen_1 = strlen(ft.cont);
long int strLen_2 = strlen("' to {TOKEN}.");
;                            
                    ____BAH_COMPILER_VAR_519 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_519+currStrOff, "Cannot change the type of already declared var '", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_519+currStrOff, ft.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_519+currStrOff, "' to {TOKEN}.", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_519[currStrOff] = 0;
                }
                throwErr(&st,____BAH_COMPILER_VAR_519);
}
if ((isStruct==false)) {
if (((isRCPpointerType(v->type)&&(isPointedVar==false))&&(RCPavailable()==true))) {
struct string cType =  getCType(v->type,elems);
if ((toVar==true)) {
if ((RCPselfRef(v)==false)) {
char * ____BAH_COMPILER_VAR_520 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_521 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_522 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("*(");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_520);
long int strLen_2 = strlen("*)RCP_decrIL(&");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen(") = *(");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_521);
long int strLen_6 = strlen("*)RCP_incrIL(&");
long int strLen_7 = strlen(code);
long int strLen_8 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_522 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                    
                    memcpy(____BAH_COMPILER_VAR_522+currStrOff, "*(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_522+currStrOff, ____BAH_COMPILER_VAR_520, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_522+currStrOff, "*)RCP_decrIL(&", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_522+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_522+currStrOff, ") = *(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_522+currStrOff, ____BAH_COMPILER_VAR_521, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_522+currStrOff, "*)RCP_incrIL(&", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_522+currStrOff, code, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_522+currStrOff, ")", strLen_8);
                    currStrOff += strLen_8;
                    
                    ____BAH_COMPILER_VAR_522[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_522;
}
else {
struct variable* ____BAH_COMPILER_VAR_523 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_523->name = "";
____BAH_COMPILER_VAR_523->type = "";
____BAH_COMPILER_VAR_523->isConst = false;
____BAH_COMPILER_VAR_523->constVal = "";
____BAH_COMPILER_VAR_523->isArray = false;
____BAH_COMPILER_VAR_523->from = "";
____BAH_COMPILER_VAR_523->outterScope = false;
____BAH_COMPILER_VAR_523->isGlobal = false;
struct variable* tmpV =  ____BAH_COMPILER_VAR_523;
tmpV->name =  genCompilerVar();
tmpV->type =  v->type;
struct rope* dv =  decrVar(tmpV,elems);
char * ____BAH_COMPILER_VAR_524 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_525 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_526 =dv->toStr((struct rope*)dv);char * ____BAH_COMPILER_VAR_527 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_524);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(tmpV->name);
long int strLen_3 = strlen(" = ");
long int strLen_4 = strlen(v->name);
long int strLen_5 = strlen("; ");
long int strLen_6 = strlen(v->name);
long int strLen_7 = strlen(" = *(");
long int strLen_8 = strlen(____BAH_COMPILER_VAR_525);
long int strLen_9 = strlen("*)RCP_incrIL(&");
long int strLen_10 = strlen(code);
long int strLen_11 = strlen(");");
long int strLen_12 = strlen(____BAH_COMPILER_VAR_526);
;                            
                    ____BAH_COMPILER_VAR_527 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12);
                    
                    memcpy(____BAH_COMPILER_VAR_527+currStrOff, ____BAH_COMPILER_VAR_524, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_527+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_527+currStrOff, tmpV->name, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_527+currStrOff, " = ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_527+currStrOff, v->name, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_527+currStrOff, "; ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_527+currStrOff, v->name, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_527+currStrOff, " = *(", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_527+currStrOff, ____BAH_COMPILER_VAR_525, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_527+currStrOff, "*)RCP_incrIL(&", strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_527+currStrOff, code, strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_527+currStrOff, ");", strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_527+currStrOff, ____BAH_COMPILER_VAR_526, strLen_12);
                    currStrOff += strLen_12;
                    
                    ____BAH_COMPILER_VAR_527[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_527;
}
}
else {
struct variable* ____BAH_COMPILER_VAR_528 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_528->name = "";
____BAH_COMPILER_VAR_528->type = "";
____BAH_COMPILER_VAR_528->isConst = false;
____BAH_COMPILER_VAR_528->constVal = "";
____BAH_COMPILER_VAR_528->isArray = false;
____BAH_COMPILER_VAR_528->from = "";
____BAH_COMPILER_VAR_528->outterScope = false;
____BAH_COMPILER_VAR_528->isGlobal = false;
struct variable* tmpV =  ____BAH_COMPILER_VAR_528;
tmpV->name =  genCompilerVar();
tmpV->type =  v->type;
struct rope* dv =  decrVar(tmpV,elems);
char * ____BAH_COMPILER_VAR_529 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_530 =dv->toStr((struct rope*)dv);char * ____BAH_COMPILER_VAR_531 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_529);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(tmpV->name);
long int strLen_3 = strlen(" = ");
long int strLen_4 = strlen(v->name);
long int strLen_5 = strlen("; ");
long int strLen_6 = strlen(v->name);
long int strLen_7 = strlen(" = ");
long int strLen_8 = strlen(code);
long int strLen_9 = strlen(";");
long int strLen_10 = strlen(____BAH_COMPILER_VAR_530);
;                            
                    ____BAH_COMPILER_VAR_531 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10);
                    
                    memcpy(____BAH_COMPILER_VAR_531+currStrOff, ____BAH_COMPILER_VAR_529, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_531+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_531+currStrOff, tmpV->name, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_531+currStrOff, " = ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_531+currStrOff, v->name, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_531+currStrOff, "; ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_531+currStrOff, v->name, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_531+currStrOff, " = ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_531+currStrOff, code, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_531+currStrOff, ";", strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_531+currStrOff, ____BAH_COMPILER_VAR_530, strLen_10);
                    currStrOff += strLen_10;
                    
                    ____BAH_COMPILER_VAR_531[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_531;
}
}
else {
struct cStruct* s =  searchStruct(v->type,elems);
if ((((((s!=null)&&(RCPavailable()==true))&&(RCPselfRef(v)==false))&&(s->isBinding==false))&&(strCount(v->name,"*")==0))) {
char * ____BAH_COMPILER_VAR_532 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("RCP_decrCounter(");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(".__RCP_counter); ");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen(" = ");
long int strLen_5 = strlen(code);
;                            
                    ____BAH_COMPILER_VAR_532 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    memcpy(____BAH_COMPILER_VAR_532+currStrOff, "RCP_decrCounter(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_532+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_532+currStrOff, ".__RCP_counter); ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_532+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_532+currStrOff, " = ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_532+currStrOff, code, strLen_5);
                    currStrOff += strLen_5;
                    
                    ____BAH_COMPILER_VAR_532[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_532;
}
else {
char * ____BAH_COMPILER_VAR_533 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen(" = ");
long int strLen_2 = strlen(code);
;                            
                    ____BAH_COMPILER_VAR_533 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_533+currStrOff, v->name, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_533+currStrOff, " = ", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_533+currStrOff, code, strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_533[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_533;
}
}
}
else {
strTrim(&code);
if ((strHasPrefix(code,"{")==false)) {
char * ____BAH_COMPILER_VAR_534 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen(" = ");
long int strLen_2 = strlen(code);
;                            
                    ____BAH_COMPILER_VAR_534 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_534+currStrOff, v->name, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_534+currStrOff, " = ", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_534+currStrOff, code, strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_534[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_534;
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
char * ____BAH_COMPILER_VAR_535 =null;
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
                    ____BAH_COMPILER_VAR_535 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14 + strLen_15 + strLen_16);
                    
                    memcpy(____BAH_COMPILER_VAR_535+currStrOff, "\n{\nlong nLength = ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_535+currStrOff, nLengthStr, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_535+currStrOff, ";\nif (", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_535+currStrOff, nstr, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_535+currStrOff, "->length < nLength+1) {\nif ((nLength+1) % 50 == 0 || nLength == 0) {\nvoid * newPtr = memoryRealloc(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_535+currStrOff, nstr, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_535+currStrOff, "->data, (nLength+50)*sizeof(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_535+currStrOff, elemTypeStr, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_535+currStrOff, "));\n", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_535+currStrOff, nstr, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_535+currStrOff, "->data = newPtr;\n}\n", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_535+currStrOff, code, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_535+currStrOff, ";\n", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_535+currStrOff, nstr, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_535+currStrOff, "->length = nLength+1;\n} else {\n", strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_535+currStrOff, code, strLen_15);
                    currStrOff += strLen_15;
                    
                    memcpy(____BAH_COMPILER_VAR_535+currStrOff, ";\n}\n}", strLen_16);
                    currStrOff += strLen_16;
                    
                    ____BAH_COMPILER_VAR_535[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_535;
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
char * ____BAH_COMPILER_VAR_536 =ct.str((struct string*)&ct);char * ____BAH_COMPILER_VAR_537 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_536);
;                            
                    ____BAH_COMPILER_VAR_537 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_537+currStrOff, tmpfnArgsCType, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_537+currStrOff, ____BAH_COMPILER_VAR_536, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_537[currStrOff] = 0;
                }
                tmpfnArgsCType =  ____BAH_COMPILER_VAR_537;
j =  j + 1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_538 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(",");
;                            
                    ____BAH_COMPILER_VAR_538 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_538+currStrOff, tmpfnArgsCType, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_538+currStrOff, ",", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_538[currStrOff] = 0;
                }
                tmpfnArgsCType =  ____BAH_COMPILER_VAR_538;
}
};
char * ____BAH_COMPILER_VAR_539 =tmpfnRetCType.str((struct string*)&tmpfnRetCType);char * ____BAH_COMPILER_VAR_540 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_539);
long int strLen_1 = strlen(" (*");
long int strLen_2 = strlen(v->name);
long int strLen_3 = strlen(")(");
long int strLen_4 = strlen(tmpfnArgsCType);
long int strLen_5 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_540 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    memcpy(____BAH_COMPILER_VAR_540+currStrOff, ____BAH_COMPILER_VAR_539, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_540+currStrOff, " (*", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_540+currStrOff, v->name, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_540+currStrOff, ")(", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_540+currStrOff, tmpfnArgsCType, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_540+currStrOff, ")", strLen_5);
                    currStrOff += strLen_5;
                    
                    ____BAH_COMPILER_VAR_540[currStrOff] = 0;
                }
                vct =  ____BAH_COMPILER_VAR_540;
}
else {
vct =  setCType(v,elems);
}
if (((strlen(code)>0)&&(shouldOnlyDecl==false))) {
if ((((isRCPpointerType(v->type)&&(RCPavailable()==true))&&(toVar==true))&&(isPointedVar==false))) {
struct string cType =  getCType(v->type,elems);
if (isGlobal()) {
char * ____BAH_COMPILER_VAR_541 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_542 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen(" = *(");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_541);
long int strLen_3 = strlen("*)RCP_incrIL(&");
long int strLen_4 = strlen(code);
long int strLen_5 = strlen(");\n");
;                            
                    ____BAH_COMPILER_VAR_542 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    memcpy(____BAH_COMPILER_VAR_542+currStrOff, v->name, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_542+currStrOff, " = *(", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_542+currStrOff, ____BAH_COMPILER_VAR_541, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_542+currStrOff, "*)RCP_incrIL(&", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_542+currStrOff, code, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_542+currStrOff, ");\n", strLen_5);
                    currStrOff += strLen_5;
                    
                    ____BAH_COMPILER_VAR_542[currStrOff] = 0;
                }
                INIT =  INIT->add(INIT, rope(____BAH_COMPILER_VAR_542));
}
else {
char * ____BAH_COMPILER_VAR_543 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_544 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(vct);
long int strLen_1 = strlen(" = *(");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_543);
long int strLen_3 = strlen("*)RCP_incrIL(&");
long int strLen_4 = strlen(code);
long int strLen_5 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_544 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    memcpy(____BAH_COMPILER_VAR_544+currStrOff, vct, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_544+currStrOff, " = *(", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_544+currStrOff, ____BAH_COMPILER_VAR_543, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_544+currStrOff, "*)RCP_incrIL(&", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_544+currStrOff, code, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_544+currStrOff, ")", strLen_5);
                    currStrOff += strLen_5;
                    
                    ____BAH_COMPILER_VAR_544[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_544;
}
}
else {
if (isGlobal()) {
char * ____BAH_COMPILER_VAR_545 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen(" = ");
long int strLen_2 = strlen(code);
long int strLen_3 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_545 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                    
                    memcpy(____BAH_COMPILER_VAR_545+currStrOff, v->name, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_545+currStrOff, " = ", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_545+currStrOff, code, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_545+currStrOff, ";\n", strLen_3);
                    currStrOff += strLen_3;
                    
                    ____BAH_COMPILER_VAR_545[currStrOff] = 0;
                }
                INIT =  INIT->add(INIT, rope(____BAH_COMPILER_VAR_545));
}
else {
char * ____BAH_COMPILER_VAR_546 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(vct);
long int strLen_1 = strlen(" = ");
long int strLen_2 = strlen(code);
;                            
                    ____BAH_COMPILER_VAR_546 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_546+currStrOff, vct, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_546+currStrOff, " = ", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_546+currStrOff, code, strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_546[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_546;
}
}
}
else {
if ((isRCPpointerType(v->type)&&(shouldOnlyDecl==false))) {
char * ____BAH_COMPILER_VAR_547 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(vct);
long int strLen_1 = strlen("= null");
;                            
                    ____BAH_COMPILER_VAR_547 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_547+currStrOff, vct, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_547+currStrOff, "= null", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_547[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_547;
}
else {
code =  vct;
}
}
if ((shouldOnlyDecl==true)) {
char * ____BAH_COMPILER_VAR_548 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("extern ");
long int strLen_1 = strlen(vct);
;                            
                    ____BAH_COMPILER_VAR_548 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_548+currStrOff, "extern ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_548+currStrOff, vct, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_548[currStrOff] = 0;
                }
                vct =  ____BAH_COMPILER_VAR_548;
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
struct variable* ____BAH_COMPILER_VAR_549 = v;
char ** ____BAH_COMPILER_VAR_551 = (char **)((char*)(____BAH_COMPILER_VAR_549) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_552 = __reflect(____BAH_COMPILER_VAR_551, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_553 = (char **)((char*)(____BAH_COMPILER_VAR_549) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_554 = __reflect(____BAH_COMPILER_VAR_553, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_555 = (char*)((char*)(____BAH_COMPILER_VAR_549) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_556 = __reflect(____BAH_COMPILER_VAR_555, sizeof(char), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_557 = (char **)((char*)(____BAH_COMPILER_VAR_549) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_558 = __reflect(____BAH_COMPILER_VAR_557, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_559 = (char*)((char*)(____BAH_COMPILER_VAR_549) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_560 = __reflect(____BAH_COMPILER_VAR_559, sizeof(char), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_561 = (char **)((char*)(____BAH_COMPILER_VAR_549) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_562 = __reflect(____BAH_COMPILER_VAR_561, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
char* ____BAH_COMPILER_VAR_563 = (char*)((char*)(____BAH_COMPILER_VAR_549) + offsetof(struct variable, outterScope));
struct reflectElement ____BAH_COMPILER_VAR_564 = __reflect(____BAH_COMPILER_VAR_563, sizeof(char), "bool", "outterScope", 0, 0, 0, 0, offsetof(struct variable, outterScope));
char* ____BAH_COMPILER_VAR_565 = (char*)((char*)(____BAH_COMPILER_VAR_549) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_566 = __reflect(____BAH_COMPILER_VAR_565, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_550 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_550->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_550->length = 8;
        ____BAH_COMPILER_VAR_550->data = memoryAlloc(____BAH_COMPILER_VAR_550->length * ____BAH_COMPILER_VAR_550->elemSize);
        ____BAH_COMPILER_VAR_550->data[0] = ____BAH_COMPILER_VAR_552;
____BAH_COMPILER_VAR_550->data[1] = ____BAH_COMPILER_VAR_554;
____BAH_COMPILER_VAR_550->data[2] = ____BAH_COMPILER_VAR_556;
____BAH_COMPILER_VAR_550->data[3] = ____BAH_COMPILER_VAR_558;
____BAH_COMPILER_VAR_550->data[4] = ____BAH_COMPILER_VAR_560;
____BAH_COMPILER_VAR_550->data[5] = ____BAH_COMPILER_VAR_562;
____BAH_COMPILER_VAR_550->data[6] = ____BAH_COMPILER_VAR_564;
____BAH_COMPILER_VAR_550->data[7] = ____BAH_COMPILER_VAR_566;
struct reflectElement ____BAH_COMPILER_VAR_567 = __reflect(____BAH_COMPILER_VAR_549, sizeof(struct variable), "variable*", "v", 0, 0, 1, ____BAH_COMPILER_VAR_550, 0);
debugPrint("var_declaration",ft.line,____BAH_COMPILER_VAR_567);
if (isGlobal()) {
char * ____BAH_COMPILER_VAR_568 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(vct);
long int strLen_1 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_568 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_568+currStrOff, vct, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_568+currStrOff, ";\n", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_568[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_568));
}
}
if (isGlobal()) {
if ((isSubObject==false)) {
INIT =  INIT->add(INIT, rope(NEXT_LINE));
}
NEXT_LINE =  "";
}
else {
char * ____BAH_COMPILER_VAR_569 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_569 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_569+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_569+currStrOff, ";\n", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_569[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_569));
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
char * ____BAH_COMPILER_VAR_570 =ct.str((struct string*)&ct);char * ____BAH_COMPILER_VAR_571 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_570);
;                            
                    ____BAH_COMPILER_VAR_571 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_571+currStrOff, tmpfnArgsCType, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_571+currStrOff, ____BAH_COMPILER_VAR_570, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_571[currStrOff] = 0;
                }
                tmpfnArgsCType =  ____BAH_COMPILER_VAR_571;
j =  j + 1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_572 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(",");
;                            
                    ____BAH_COMPILER_VAR_572 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_572+currStrOff, tmpfnArgsCType, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_572+currStrOff, ",", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_572[currStrOff] = 0;
                }
                tmpfnArgsCType =  ____BAH_COMPILER_VAR_572;
}
};
char * ____BAH_COMPILER_VAR_573 =tmpfnRetCType.str((struct string*)&tmpfnRetCType);char * ____BAH_COMPILER_VAR_574 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_573);
long int strLen_1 = strlen(" (*");
long int strLen_2 = strlen(elemName);
long int strLen_3 = strlen(")(");
long int strLen_4 = strlen(tmpfnArgsCType);
long int strLen_5 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_574 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    memcpy(____BAH_COMPILER_VAR_574+currStrOff, ____BAH_COMPILER_VAR_573, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_574+currStrOff, " (*", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_574+currStrOff, elemName, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_574+currStrOff, ")(", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_574+currStrOff, tmpfnArgsCType, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_574+currStrOff, ")", strLen_5);
                    currStrOff += strLen_5;
                    
                    ____BAH_COMPILER_VAR_574[currStrOff] = 0;
                }
                return ____BAH_COMPILER_VAR_574;
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
char * ____BAH_COMPILER_VAR_575 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(prev);
long int strLen_1 = strlen(ft.cont);
;                            
                    ____BAH_COMPILER_VAR_575 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_575+currStrOff, prev, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_575+currStrOff, ft.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_575[currStrOff] = 0;
                }
                fn->name =  ____BAH_COMPILER_VAR_575;
array(struct variable*)* arguments = memoryAlloc(sizeof(array(struct variable*)));

arguments->length = 0;
arguments->elemSize = sizeof(struct variable*);
char * ____BAH_COMPILER_VAR_576 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(fn->name);
long int strLen_1 = strlen("(");
;                            
                    ____BAH_COMPILER_VAR_576 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_576+currStrOff, fn->name, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_576+currStrOff, "(", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_576[currStrOff] = 0;
                }
                char * code =  ____BAH_COMPILER_VAR_576;
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
char * ____BAH_COMPILER_VAR_577 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(argType);
long int strLen_1 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_577 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_577+currStrOff, argType, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_577+currStrOff, t.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_577[currStrOff] = 0;
                }
                argType =  ____BAH_COMPILER_VAR_577;
}
}
else {
isComa =  true;
break;
}
j =  j + 1;
};
struct variable* ____BAH_COMPILER_VAR_578 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_578->name = "";
____BAH_COMPILER_VAR_578->type = "";
____BAH_COMPILER_VAR_578->isConst = false;
____BAH_COMPILER_VAR_578->constVal = "";
____BAH_COMPILER_VAR_578->isArray = false;
____BAH_COMPILER_VAR_578->from = "";
____BAH_COMPILER_VAR_578->outterScope = false;
____BAH_COMPILER_VAR_578->isGlobal = false;
struct variable* argument =  ____BAH_COMPILER_VAR_578;
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
char * ____BAH_COMPILER_VAR_579 =cfrt.str((struct string*)&cfrt);char * ____BAH_COMPILER_VAR_580 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("__BAH_ARR_TYPE_");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_579);
;                            
                    ____BAH_COMPILER_VAR_580 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_580+currStrOff, "__BAH_ARR_TYPE_", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_580+currStrOff, ____BAH_COMPILER_VAR_579, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_580[currStrOff] = 0;
                }
                newArgType =  ____BAH_COMPILER_VAR_580;
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
char * ____BAH_COMPILER_VAR_581 =argCType.str((struct string*)&argCType);char * ____BAH_COMPILER_VAR_582 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tpdf);
long int strLen_1 = strlen("typedef ");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_581);
long int strLen_3 = strlen(" ");
long int strLen_4 = strlen(newArgType);
long int strLen_5 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_582 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    memcpy(____BAH_COMPILER_VAR_582+currStrOff, tpdf, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_582+currStrOff, "typedef ", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_582+currStrOff, ____BAH_COMPILER_VAR_581, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_582+currStrOff, " ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_582+currStrOff, newArgType, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_582+currStrOff, ";\n", strLen_5);
                    currStrOff += strLen_5;
                    
                    ____BAH_COMPILER_VAR_582[currStrOff] = 0;
                }
                tpdf =  ____BAH_COMPILER_VAR_582;
}
}
if ((cfrt.hasPrefix((struct string*)&cfrt,"function(")==1)) {
char * ____BAH_COMPILER_VAR_583 =getCfunctionType(cfrt,argName,elems);char * ____BAH_COMPILER_VAR_584 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_583);
;                            
                    ____BAH_COMPILER_VAR_584 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_584+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_584+currStrOff, ____BAH_COMPILER_VAR_583, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_584[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_584;
}
else {
char * ____BAH_COMPILER_VAR_585 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(newArgType);
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(argName);
;                            
                    ____BAH_COMPILER_VAR_585 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                    
                    memcpy(____BAH_COMPILER_VAR_585+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_585+currStrOff, newArgType, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_585+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_585+currStrOff, argName, strLen_3);
                    currStrOff += strLen_3;
                    
                    ____BAH_COMPILER_VAR_585[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_585;
}
if ((isComa==true)) {
char * ____BAH_COMPILER_VAR_586 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(",");
;                            
                    ____BAH_COMPILER_VAR_586 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_586+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_586+currStrOff, ",", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_586[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_586;
}
else {
char * ____BAH_COMPILER_VAR_587 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_587 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_587+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_587+currStrOff, ")", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_587[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_587;
break;
}
j =  j + 1;
};
}
else {
char * ____BAH_COMPILER_VAR_588 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_588 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_588+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_588+currStrOff, ")", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_588[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_588;
}
j =  j + 1;
struct variable* ____BAH_COMPILER_VAR_589 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_589->name = "";
____BAH_COMPILER_VAR_589->type = "";
____BAH_COMPILER_VAR_589->isConst = false;
____BAH_COMPILER_VAR_589->constVal = "";
____BAH_COMPILER_VAR_589->isArray = false;
____BAH_COMPILER_VAR_589->from = "";
____BAH_COMPILER_VAR_589->outterScope = false;
____BAH_COMPILER_VAR_589->isGlobal = false;
struct variable* returns =  ____BAH_COMPILER_VAR_589;
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
char * ____BAH_COMPILER_VAR_590 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(returns->type);
long int strLen_1 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_590 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_590+currStrOff, returns->type, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_590+currStrOff, t.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_590[currStrOff] = 0;
                }
                returns->type =  ____BAH_COMPILER_VAR_590;
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
char * ____BAH_COMPILER_VAR_591 =cfrt.str((struct string*)&cfrt);char * ____BAH_COMPILER_VAR_592 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("__BAH_ARR_TYPE_");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_591);
;                            
                    ____BAH_COMPILER_VAR_592 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_592+currStrOff, "__BAH_ARR_TYPE_", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_592+currStrOff, ____BAH_COMPILER_VAR_591, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_592[currStrOff] = 0;
                }
                newFnRetType =  ____BAH_COMPILER_VAR_592;
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
char * ____BAH_COMPILER_VAR_593 =fnRetType.str((struct string*)&fnRetType);char * ____BAH_COMPILER_VAR_594 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tpdf);
long int strLen_1 = strlen("typedef ");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_593);
long int strLen_3 = strlen(" ");
long int strLen_4 = strlen(newFnRetType);
long int strLen_5 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_594 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    memcpy(____BAH_COMPILER_VAR_594+currStrOff, tpdf, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_594+currStrOff, "typedef ", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_594+currStrOff, ____BAH_COMPILER_VAR_593, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_594+currStrOff, " ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_594+currStrOff, newFnRetType, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_594+currStrOff, ";\n", strLen_5);
                    currStrOff += strLen_5;
                    
                    ____BAH_COMPILER_VAR_594[currStrOff] = 0;
                }
                tpdf =  ____BAH_COMPILER_VAR_594;
}
}
char * ____BAH_COMPILER_VAR_595 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tpdf);
long int strLen_1 = strlen(newFnRetType);
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(code);
;                            
                    ____BAH_COMPILER_VAR_595 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                    
                    memcpy(____BAH_COMPILER_VAR_595+currStrOff, tpdf, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_595+currStrOff, newFnRetType, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_595+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_595+currStrOff, code, strLen_3);
                    currStrOff += strLen_3;
                    
                    ____BAH_COMPILER_VAR_595[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_595;
return code;
};
void parseStruct(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
struct cStruct* ____BAH_COMPILER_VAR_596 = memoryAlloc(sizeof(struct cStruct));
____BAH_COMPILER_VAR_596->name = "";
____BAH_COMPILER_VAR_596->members = memoryAlloc(sizeof(array(struct structMemb*)));
            ____BAH_COMPILER_VAR_596->members->length = 0;
            ____BAH_COMPILER_VAR_596->members->elemSize = sizeof(struct structMemb*);
            ____BAH_COMPILER_VAR_596->methods = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_596->methods->length = 0;
            ____BAH_COMPILER_VAR_596->methods->elemSize = sizeof(struct func*);
            ____BAH_COMPILER_VAR_596->postCode = "";
____BAH_COMPILER_VAR_596->extendedFrom = "";
____BAH_COMPILER_VAR_596->isBinding = false;
____BAH_COMPILER_VAR_596->hasRCPmemb = false;
struct cStruct* s =  ____BAH_COMPILER_VAR_596;
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
char * ____BAH_COMPILER_VAR_597 =ct.str((struct string*)&ct);char * ____BAH_COMPILER_VAR_598 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_597);
;                            
                    ____BAH_COMPILER_VAR_598 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_598+currStrOff, tmpfnArgsCType, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_598+currStrOff, ____BAH_COMPILER_VAR_597, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_598[currStrOff] = 0;
                }
                tmpfnArgsCType =  ____BAH_COMPILER_VAR_598;
j =  j + 1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_599 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(",");
;                            
                    ____BAH_COMPILER_VAR_599 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_599+currStrOff, tmpfnArgsCType, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_599+currStrOff, ",", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_599[currStrOff] = 0;
                }
                tmpfnArgsCType =  ____BAH_COMPILER_VAR_599;
}
};
char * ____BAH_COMPILER_VAR_600 =tmpfnRetCType.str((struct string*)&tmpfnRetCType);char * ____BAH_COMPILER_VAR_601 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_600);
long int strLen_1 = strlen(" (*");
long int strLen_2 = strlen(em->name);
long int strLen_3 = strlen(")(");
long int strLen_4 = strlen(tmpfnArgsCType);
long int strLen_5 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_601 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    memcpy(____BAH_COMPILER_VAR_601+currStrOff, ____BAH_COMPILER_VAR_600, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_601+currStrOff, " (*", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_601+currStrOff, em->name, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_601+currStrOff, ")(", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_601+currStrOff, tmpfnArgsCType, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_601+currStrOff, ")", strLen_5);
                    currStrOff += strLen_5;
                    
                    ____BAH_COMPILER_VAR_601[currStrOff] = 0;
                }
                membDeclStr =  ____BAH_COMPILER_VAR_601;
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
char * ____BAH_COMPILER_VAR_602 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("(*");
long int strLen_1 = strlen(emt->name);
long int strLen_2 = strlen(")(");
;                            
                    ____BAH_COMPILER_VAR_602 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_602+currStrOff, "(*", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_602+currStrOff, emt->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_602+currStrOff, ")(", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_602[currStrOff] = 0;
                }
                mthdDecl.append((struct string*)&mthdDecl,____BAH_COMPILER_VAR_602);
j =  0;
while ((j<len(emt->args))) {

                    if (emt->args->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2685): emt->args[%d] with length %d\n", j, emt->args->length);
                        exit(1);
                    };
                    struct variable* a =  emt->args->data[j];
struct string tp =  getCType(a->type,elems);
char * ____BAH_COMPILER_VAR_603 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(" ");
long int strLen_1 = strlen(a->name);
;                            
                    ____BAH_COMPILER_VAR_603 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_603+currStrOff, " ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_603+currStrOff, a->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_603[currStrOff] = 0;
                }
                tp.append((struct string*)&tp,____BAH_COMPILER_VAR_603);
long int max =  len(emt->args) - 1;
if ((j!=max)) {
tp.append((struct string*)&tp,",");
}
char * ____BAH_COMPILER_VAR_604 =tp.str((struct string*)&tp);mthdDecl.append((struct string*)&mthdDecl,____BAH_COMPILER_VAR_604);
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
struct structMemb* ____BAH_COMPILER_VAR_605 = memoryAlloc(sizeof(struct structMemb));
____BAH_COMPILER_VAR_605->name = "";
____BAH_COMPILER_VAR_605->type = "";
____BAH_COMPILER_VAR_605->isConst = false;
____BAH_COMPILER_VAR_605->constVal = "";
____BAH_COMPILER_VAR_605->isArray = false;
____BAH_COMPILER_VAR_605->from = "";
____BAH_COMPILER_VAR_605->outterScope = false;
____BAH_COMPILER_VAR_605->isGlobal = false;
____BAH_COMPILER_VAR_605->def = "";
____BAH_COMPILER_VAR_605->isFn = false;
struct structMemb* memb =  ____BAH_COMPILER_VAR_605;
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
char * ____BAH_COMPILER_VAR_606 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s->name);
long int strLen_1 = strlen("__");
;                            
                    ____BAH_COMPILER_VAR_606 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_606+currStrOff, s->name, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_606+currStrOff, "__", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_606[currStrOff] = 0;
                }
                char * fnPrefix =  ____BAH_COMPILER_VAR_606;
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
struct func* fn =  ____BAH_COMPILER_VAR_607;
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
char * ____BAH_COMPILER_VAR_608 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s->name);
long int strLen_1 = strlen("*");
;                            
                    ____BAH_COMPILER_VAR_608 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_608+currStrOff, s->name, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_608+currStrOff, "*", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_608[currStrOff] = 0;
                }
                t.cont =  ____BAH_COMPILER_VAR_608;
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
char * ____BAH_COMPILER_VAR_609 =parseFnHeader(fnPrefix,nl,&nli,fn,elems);struct rope* code =  rope(____BAH_COMPILER_VAR_609);
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
struct func* ____BAH_COMPILER_VAR_610 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_610->name = "";
____BAH_COMPILER_VAR_610->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_610->args->length = 0;
            ____BAH_COMPILER_VAR_610->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_610->returns= null;
____BAH_COMPILER_VAR_610->isBinding = false;
____BAH_COMPILER_VAR_610->from = "";
____BAH_COMPILER_VAR_610->file = "";
____BAH_COMPILER_VAR_610->line = 1;
____BAH_COMPILER_VAR_610->used = false;
____BAH_COMPILER_VAR_610->code = null;
struct func* mfn =  ____BAH_COMPILER_VAR_610;
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
char * ____BAH_COMPILER_VAR_611 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Function '");
long int strLen_1 = strlen(fn->name);
long int strLen_2 = strlen("' is not returned.");
;                            
                    ____BAH_COMPILER_VAR_611 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_611+currStrOff, "Function '", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_611+currStrOff, fn->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_611+currStrOff, "' is not returned.", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_611[currStrOff] = 0;
                }
                throwErr(&l->data[len(l)-1],____BAH_COMPILER_VAR_611);
}
endRCPscope(fnElems,null);
}
code =  code->add(code, OUTPUT)->add(code->add(code, OUTPUT), rope("};\n"));
}
}
if ((doesOutput==true)) {
char * ____BAH_COMPILER_VAR_612 =code->toStr((struct rope*)code);char * ____BAH_COMPILER_VAR_613 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(nextLine);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_612);
;                            
                    ____BAH_COMPILER_VAR_613 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_613+currStrOff, nextLine, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_613+currStrOff, ____BAH_COMPILER_VAR_612, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_613[currStrOff] = 0;
                }
                nextLine =  ____BAH_COMPILER_VAR_613;
}
struct string mthdDecl =  getCType(fn->returns->type,elems);
char * ____BAH_COMPILER_VAR_614 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("(*");
long int strLen_1 = strlen(mfn->name);
long int strLen_2 = strlen(")(");
;                            
                    ____BAH_COMPILER_VAR_614 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_614+currStrOff, "(*", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_614+currStrOff, mfn->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_614+currStrOff, ")(", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_614[currStrOff] = 0;
                }
                mthdDecl.append((struct string*)&mthdDecl,____BAH_COMPILER_VAR_614);
j =  0;
while ((j<len(arguments))) {

                    if (arguments->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2853): arguments[%d] with length %d\n", j, arguments->length);
                        exit(1);
                    };
                    struct variable* a =  arguments->data[j];
struct string tp =  getCType(a->type,elems);
char * ____BAH_COMPILER_VAR_615 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(" ");
long int strLen_1 = strlen(a->name);
;                            
                    ____BAH_COMPILER_VAR_615 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_615+currStrOff, " ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_615+currStrOff, a->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_615[currStrOff] = 0;
                }
                tp.append((struct string*)&tp,____BAH_COMPILER_VAR_615);
max =  len(arguments) - 1;
if ((j!=max)) {
tp.append((struct string*)&tp,",");
}
char * ____BAH_COMPILER_VAR_616 =tp.str((struct string*)&tp);mthdDecl.append((struct string*)&mthdDecl,____BAH_COMPILER_VAR_616);
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
char * ____BAH_COMPILER_VAR_617 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(mbmType);
long int strLen_1 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_617 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_617+currStrOff, mbmType, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_617+currStrOff, t.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_617[currStrOff] = 0;
                }
                mbmType =  ____BAH_COMPILER_VAR_617;
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
char * ____BAH_COMPILER_VAR_618 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(tt);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(memb->type);
long int strLen_4 = strlen(" for member.");
;                            
                    ____BAH_COMPILER_VAR_618 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_618+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_618+currStrOff, tt, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_618+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_618+currStrOff, memb->type, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_618+currStrOff, " for member.", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_618[currStrOff] = 0;
                }
                throwErr(&t,____BAH_COMPILER_VAR_618);
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
char * ____BAH_COMPILER_VAR_619 =ct.str((struct string*)&ct);char * ____BAH_COMPILER_VAR_620 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_619);
;                            
                    ____BAH_COMPILER_VAR_620 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_620+currStrOff, tmpfnArgsCType, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_620+currStrOff, ____BAH_COMPILER_VAR_619, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_620[currStrOff] = 0;
                }
                tmpfnArgsCType =  ____BAH_COMPILER_VAR_620;
j =  j + 1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_621 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(",");
;                            
                    ____BAH_COMPILER_VAR_621 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_621+currStrOff, tmpfnArgsCType, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_621+currStrOff, ",", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_621[currStrOff] = 0;
                }
                tmpfnArgsCType =  ____BAH_COMPILER_VAR_621;
}
};
char * ____BAH_COMPILER_VAR_622 =tmpfnRetCType.str((struct string*)&tmpfnRetCType);char * ____BAH_COMPILER_VAR_623 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_622);
long int strLen_1 = strlen(" (*");
long int strLen_2 = strlen(memb->name);
long int strLen_3 = strlen(")(");
long int strLen_4 = strlen(tmpfnArgsCType);
long int strLen_5 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_623 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    memcpy(____BAH_COMPILER_VAR_623+currStrOff, ____BAH_COMPILER_VAR_622, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_623+currStrOff, " (*", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_623+currStrOff, memb->name, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_623+currStrOff, ")(", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_623+currStrOff, tmpfnArgsCType, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_623+currStrOff, ")", strLen_5);
                    currStrOff += strLen_5;
                    
                    ____BAH_COMPILER_VAR_623[currStrOff] = 0;
                }
                membDeclStr =  ____BAH_COMPILER_VAR_623;
}
else {
struct string membDecl =  getCType(memb->type,elems);
char * ____BAH_COMPILER_VAR_624 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(" ");
long int strLen_1 = strlen(memb->name);
;                            
                    ____BAH_COMPILER_VAR_624 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_624+currStrOff, " ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_624+currStrOff, memb->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_624[currStrOff] = 0;
                }
                membDecl.append((struct string*)&membDecl,____BAH_COMPILER_VAR_624);
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
char * ____BAH_COMPILER_VAR_625 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("struct ");
long int strLen_1 = strlen(s->name);
long int strLen_2 = strlen(" {\n");
;                            
                    ____BAH_COMPILER_VAR_625 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_625+currStrOff, "struct ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_625+currStrOff, s->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_625+currStrOff, " {\n", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_625[currStrOff] = 0;
                }
                struct rope* code =  rope(____BAH_COMPILER_VAR_625);
i =  0;
while ((i<len(allMembs))) {

                    if (allMembs->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2943): allMembs[%d] with length %d\n", i, allMembs->length);
                        exit(1);
                    };
                    char * m =  allMembs->data[i];
char * ____BAH_COMPILER_VAR_626 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(m);
long int strLen_1 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_626 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_626+currStrOff, m, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_626+currStrOff, ";\n", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_626[currStrOff] = 0;
                }
                code =  code->add(code, rope(____BAH_COMPILER_VAR_626));
i =  i+1;
};
if ((RCPavailable()==true)) {
code =  code->add(code, rope("void * __RCP_counter;\n"));
}
code =  code->add(code, rope("};\n"));
OUTPUT =  OUTPUT->add(OUTPUT, code)->add(OUTPUT->add(OUTPUT, code), makeRCPfuncFromStruct(s,elems));
}
if ((debug==true)) {
struct debugStruct* ____BAH_COMPILER_VAR_627 = memoryAlloc(sizeof(struct debugStruct));
____BAH_COMPILER_VAR_627->name= null;
____BAH_COMPILER_VAR_627->membs = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_627->membs->length = 0;
            ____BAH_COMPILER_VAR_627->membs->elemSize = sizeof(struct variable*);
            struct debugStruct* ds =  ____BAH_COMPILER_VAR_627;
ds->name =  s->name;
i =  0;
while ((i<len(s->members))) {

                    if (s->members->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2960): s->members[%d] with length %d\n", i, s->members->length);
                        exit(1);
                    };
                    struct structMemb* m =  s->members->data[i];
struct variable* ____BAH_COMPILER_VAR_628 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_628->name = "";
____BAH_COMPILER_VAR_628->type = "";
____BAH_COMPILER_VAR_628->isConst = false;
____BAH_COMPILER_VAR_628->constVal = "";
____BAH_COMPILER_VAR_628->isArray = false;
____BAH_COMPILER_VAR_628->from = "";
____BAH_COMPILER_VAR_628->outterScope = false;
____BAH_COMPILER_VAR_628->isGlobal = false;
struct variable* mv =  ____BAH_COMPILER_VAR_628;
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
struct debugStruct* ____BAH_COMPILER_VAR_629 = ds;
char ** ____BAH_COMPILER_VAR_631 = (char **)((char*)(____BAH_COMPILER_VAR_629) + offsetof(struct debugStruct, name));
struct reflectElement ____BAH_COMPILER_VAR_632 = __reflect(____BAH_COMPILER_VAR_631, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct debugStruct, name));
array(struct variable*)** ____BAH_COMPILER_VAR_633 = (array(struct variable*)**)((char*)(____BAH_COMPILER_VAR_629) + offsetof(struct debugStruct, membs));
struct variable** ____BAH_COMPILER_VAR_634 = 0;
char ** ____BAH_COMPILER_VAR_636 = (char **)((char*)(____BAH_COMPILER_VAR_634) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_637 = __reflect(____BAH_COMPILER_VAR_636, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_638 = (char **)((char*)(____BAH_COMPILER_VAR_634) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_639 = __reflect(____BAH_COMPILER_VAR_638, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_640 = (char*)((char*)(____BAH_COMPILER_VAR_634) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_641 = __reflect(____BAH_COMPILER_VAR_640, sizeof(char), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_642 = (char **)((char*)(____BAH_COMPILER_VAR_634) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_643 = __reflect(____BAH_COMPILER_VAR_642, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_644 = (char*)((char*)(____BAH_COMPILER_VAR_634) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_645 = __reflect(____BAH_COMPILER_VAR_644, sizeof(char), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_646 = (char **)((char*)(____BAH_COMPILER_VAR_634) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_647 = __reflect(____BAH_COMPILER_VAR_646, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
char* ____BAH_COMPILER_VAR_648 = (char*)((char*)(____BAH_COMPILER_VAR_634) + offsetof(struct variable, outterScope));
struct reflectElement ____BAH_COMPILER_VAR_649 = __reflect(____BAH_COMPILER_VAR_648, sizeof(char), "bool", "outterScope", 0, 0, 0, 0, offsetof(struct variable, outterScope));
char* ____BAH_COMPILER_VAR_650 = (char*)((char*)(____BAH_COMPILER_VAR_634) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_651 = __reflect(____BAH_COMPILER_VAR_650, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_635 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_635->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_635->length = 8;
        ____BAH_COMPILER_VAR_635->data = memoryAlloc(____BAH_COMPILER_VAR_635->length * ____BAH_COMPILER_VAR_635->elemSize);
        ____BAH_COMPILER_VAR_635->data[0] = ____BAH_COMPILER_VAR_637;
____BAH_COMPILER_VAR_635->data[1] = ____BAH_COMPILER_VAR_639;
____BAH_COMPILER_VAR_635->data[2] = ____BAH_COMPILER_VAR_641;
____BAH_COMPILER_VAR_635->data[3] = ____BAH_COMPILER_VAR_643;
____BAH_COMPILER_VAR_635->data[4] = ____BAH_COMPILER_VAR_645;
____BAH_COMPILER_VAR_635->data[5] = ____BAH_COMPILER_VAR_647;
____BAH_COMPILER_VAR_635->data[6] = ____BAH_COMPILER_VAR_649;
____BAH_COMPILER_VAR_635->data[7] = ____BAH_COMPILER_VAR_651;
struct reflectElement ____BAH_COMPILER_VAR_652 = __reflect(____BAH_COMPILER_VAR_634, sizeof(struct variable), "variable*", "", 0, 0, 1, ____BAH_COMPILER_VAR_635, 0);

        struct reflectElement ____BAH_COMPILER_VAR_653 = ____BAH_COMPILER_VAR_652;
        struct reflectElement ____BAH_COMPILER_VAR_654 = __reflect(____BAH_COMPILER_VAR_633, sizeof(array(struct variable*)*), "[]variable*", "membs", 1, &____BAH_COMPILER_VAR_653, 0, 0, offsetof(struct debugStruct, membs));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_630 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_630->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_630->length = 2;
        ____BAH_COMPILER_VAR_630->data = memoryAlloc(____BAH_COMPILER_VAR_630->length * ____BAH_COMPILER_VAR_630->elemSize);
        ____BAH_COMPILER_VAR_630->data[0] = ____BAH_COMPILER_VAR_632;
____BAH_COMPILER_VAR_630->data[1] = ____BAH_COMPILER_VAR_654;
struct reflectElement ____BAH_COMPILER_VAR_655 = __reflect(____BAH_COMPILER_VAR_629, sizeof(struct debugStruct), "debugStruct*", "ds", 0, 0, 1, ____BAH_COMPILER_VAR_630, 0);
debugPrint("struct_declare",nameToken.line,____BAH_COMPILER_VAR_655);
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
struct func* ____BAH_COMPILER_VAR_656 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_656->name = "";
____BAH_COMPILER_VAR_656->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_656->args->length = 0;
            ____BAH_COMPILER_VAR_656->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_656->returns= null;
____BAH_COMPILER_VAR_656->isBinding = false;
____BAH_COMPILER_VAR_656->from = "";
____BAH_COMPILER_VAR_656->file = "";
____BAH_COMPILER_VAR_656->line = 1;
____BAH_COMPILER_VAR_656->used = false;
____BAH_COMPILER_VAR_656->code = null;
struct func* fn =  ____BAH_COMPILER_VAR_656;
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
char * ____BAH_COMPILER_VAR_657 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_657 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_657+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_657+currStrOff, ";\n", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_657[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_657));
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
char * ____BAH_COMPILER_VAR_658 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tp);
long int strLen_1 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_658 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_658+currStrOff, tp, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_658+currStrOff, t.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_658[currStrOff] = 0;
                }
                tp =  ____BAH_COMPILER_VAR_658;
};
if ((ft.type!=TOKEN_TYPE_VAR)) {
throwErr(&ft,"Cannot use {TOKEN} as new type name.");
}
struct string cTypeNewType =  getCType(tp,elems);
char * cTypeNewTypeStr =  cTypeNewType.str((struct string*)&cTypeNewType);
if ((doesOutput==true)) {
char * ____BAH_COMPILER_VAR_659 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("typedef ");
long int strLen_1 = strlen(cTypeNewTypeStr);
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(ft.cont);
long int strLen_4 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_659 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_659+currStrOff, "typedef ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_659+currStrOff, cTypeNewTypeStr, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_659+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_659+currStrOff, ft.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_659+currStrOff, ";\n", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_659[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_659));
}
if ((debug==true)) {
struct debugType* ____BAH_COMPILER_VAR_660 = memoryAlloc(sizeof(struct debugType));
____BAH_COMPILER_VAR_660->name= null;
____BAH_COMPILER_VAR_660->refers= null;
struct debugType* dt =  ____BAH_COMPILER_VAR_660;
dt->name =  ft.cont;
dt->refers =  tp;
struct debugType* ____BAH_COMPILER_VAR_661 = dt;
char ** ____BAH_COMPILER_VAR_663 = (char **)((char*)(____BAH_COMPILER_VAR_661) + offsetof(struct debugType, name));
struct reflectElement ____BAH_COMPILER_VAR_664 = __reflect(____BAH_COMPILER_VAR_663, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct debugType, name));
char ** ____BAH_COMPILER_VAR_665 = (char **)((char*)(____BAH_COMPILER_VAR_661) + offsetof(struct debugType, refers));
struct reflectElement ____BAH_COMPILER_VAR_666 = __reflect(____BAH_COMPILER_VAR_665, sizeof(char *), "cpstring", "refers", 0, 0, 0, 0, offsetof(struct debugType, refers));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_662 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_662->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_662->length = 2;
        ____BAH_COMPILER_VAR_662->data = memoryAlloc(____BAH_COMPILER_VAR_662->length * ____BAH_COMPILER_VAR_662->elemSize);
        ____BAH_COMPILER_VAR_662->data[0] = ____BAH_COMPILER_VAR_664;
____BAH_COMPILER_VAR_662->data[1] = ____BAH_COMPILER_VAR_666;
struct reflectElement ____BAH_COMPILER_VAR_667 = __reflect(____BAH_COMPILER_VAR_661, sizeof(struct debugType), "debugType*", "dt", 0, 0, 1, ____BAH_COMPILER_VAR_662, 0);
debugPrint("type_declare",ft.line,____BAH_COMPILER_VAR_667);
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
struct variable* ____BAH_COMPILER_VAR_668 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_668->name = "";
____BAH_COMPILER_VAR_668->type = "";
____BAH_COMPILER_VAR_668->isConst = false;
____BAH_COMPILER_VAR_668->constVal = "";
____BAH_COMPILER_VAR_668->isArray = false;
____BAH_COMPILER_VAR_668->from = "";
____BAH_COMPILER_VAR_668->outterScope = false;
____BAH_COMPILER_VAR_668->isGlobal = false;
struct variable* v =  ____BAH_COMPILER_VAR_668;
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
char * ____BAH_COMPILER_VAR_669 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("#define ");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(valt.cont);
long int strLen_4 = strlen("\n");
;                            
                    ____BAH_COMPILER_VAR_669 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_669+currStrOff, "#define ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_669+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_669+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_669+currStrOff, valt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_669+currStrOff, "\n", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_669[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_669));
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
char * ____BAH_COMPILER_VAR_670 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot return nothing as ");
long int strLen_1 = strlen(currentFn->returns->type);
long int strLen_2 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_670 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_670+currStrOff, "Cannot return nothing as ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_670+currStrOff, currentFn->returns->type, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_670+currStrOff, ".", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_670[currStrOff] = 0;
                }
                throwErr(&l->data[0],____BAH_COMPILER_VAR_670);
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
char * ____BAH_COMPILER_VAR_671 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot return {TOKEN} (");
long int strLen_1 = strlen(tt);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(currentFn->returns->type);
long int strLen_4 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_671 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_671+currStrOff, "Cannot return {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_671+currStrOff, tt, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_671+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_671+currStrOff, currentFn->returns->type, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_671+currStrOff, ".", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_671[currStrOff] = 0;
                }
                throwErr(&rvt,____BAH_COMPILER_VAR_671);
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
char * ____BAH_COMPILER_VAR_672 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_673 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_672);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(rvar);
long int strLen_3 = strlen(" = ");
long int strLen_4 = strlen(rv);
long int strLen_5 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_673 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    memcpy(____BAH_COMPILER_VAR_673+currStrOff, ____BAH_COMPILER_VAR_672, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_673+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_673+currStrOff, rvar, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_673+currStrOff, " = ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_673+currStrOff, rv, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_673+currStrOff, ";\n", strLen_5);
                    currStrOff += strLen_5;
                    
                    ____BAH_COMPILER_VAR_673[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_673));
}
endRCPnonGlobScope(elems,currentFn->args);
char * ____BAH_COMPILER_VAR_674 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("return ");
long int strLen_1 = strlen(rvar);
long int strLen_2 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_674 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_674+currStrOff, "return ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_674+currStrOff, rvar, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_674+currStrOff, ";\n", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_674[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_674));
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
char * ____BAH_COMPILER_VAR_675 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("if (");
long int strLen_1 = strlen(condt.cont);
long int strLen_2 = strlen(") {\n");
;                            
                    ____BAH_COMPILER_VAR_675 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_675+currStrOff, "if (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_675+currStrOff, condt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_675+currStrOff, ") {\n", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_675[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_675));
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
char * ____BAH_COMPILER_VAR_676 =OUTPUT->toStr((struct rope*)OUTPUT);struct string instC =  string(____BAH_COMPILER_VAR_676);
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
char * ____BAH_COMPILER_VAR_677 =instC.str((struct string*)&instC);char * ____BAH_COMPILER_VAR_678 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("for (; ");
long int strLen_1 = strlen(condt.cont);
long int strLen_2 = strlen("; ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_677);
long int strLen_4 = strlen(") {\n");
;                            
                    ____BAH_COMPILER_VAR_678 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_678+currStrOff, "for (; ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_678+currStrOff, condt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_678+currStrOff, "; ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_678+currStrOff, ____BAH_COMPILER_VAR_677, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_678+currStrOff, ") {\n", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_678[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_678));
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
char * ____BAH_COMPILER_VAR_679 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("while (");
long int strLen_1 = strlen(condt.cont);
long int strLen_2 = strlen(") {\n");
;                            
                    ____BAH_COMPILER_VAR_679 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_679+currStrOff, "while (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_679+currStrOff, condt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_679+currStrOff, ") {\n", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_679[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_679));
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
char * ____BAH_COMPILER_VAR_680 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ft.cont);
long int strLen_1 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_680 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_680+currStrOff, ft.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_680+currStrOff, ";\n", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_680[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_680));
};
void makeEvalFunc(struct func* fn,struct Elems* elems){

                int ____BAH_COMPILER_VAR_681 = 0;
                for(int i=len(compilerState.evals)-1; i != -1; i--) {
                    if (compilerState.evals->data[i] != 0 && strcmp(compilerState.evals->data[i], fn->name) == 0) {
                        ____BAH_COMPILER_VAR_681 = 1;
                        break;
                    };
                };
                if (____BAH_COMPILER_VAR_681) {
return;
}
char * ____BAH_COMPILER_VAR_682 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("__Bah_eval_");
long int strLen_1 = strlen(fn->name);
;                            
                    ____BAH_COMPILER_VAR_682 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_682+currStrOff, "__Bah_eval_", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_682+currStrOff, fn->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_682[currStrOff] = 0;
                }
                struct func* ____BAH_COMPILER_VAR_683 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_683->name = "";
____BAH_COMPILER_VAR_683->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_683->args->length = 0;
            ____BAH_COMPILER_VAR_683->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_683->returns= null;
____BAH_COMPILER_VAR_683->isBinding = false;
____BAH_COMPILER_VAR_683->from = "";
____BAH_COMPILER_VAR_683->file = "";
____BAH_COMPILER_VAR_683->line = 1;
____BAH_COMPILER_VAR_683->used = false;
____BAH_COMPILER_VAR_683->code = null;
____BAH_COMPILER_VAR_683->name = ____BAH_COMPILER_VAR_682;
struct func* efn =  ____BAH_COMPILER_VAR_683;
struct variable* ____BAH_COMPILER_VAR_684 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_684->name = "";
____BAH_COMPILER_VAR_684->type = "";
____BAH_COMPILER_VAR_684->isConst = false;
____BAH_COMPILER_VAR_684->constVal = "";
____BAH_COMPILER_VAR_684->isArray = false;
____BAH_COMPILER_VAR_684->from = "";
____BAH_COMPILER_VAR_684->outterScope = false;
____BAH_COMPILER_VAR_684->isGlobal = false;
____BAH_COMPILER_VAR_684->type = "ptr";
efn->returns =  ____BAH_COMPILER_VAR_684;
struct variable* ____BAH_COMPILER_VAR_685 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_685->name = "";
____BAH_COMPILER_VAR_685->type = "";
____BAH_COMPILER_VAR_685->isConst = false;
____BAH_COMPILER_VAR_685->constVal = "";
____BAH_COMPILER_VAR_685->isArray = false;
____BAH_COMPILER_VAR_685->from = "";
____BAH_COMPILER_VAR_685->outterScope = false;
____BAH_COMPILER_VAR_685->isGlobal = false;
____BAH_COMPILER_VAR_685->name = "fnArgs";
____BAH_COMPILER_VAR_685->type = "[]ptr";
efn->args = memoryAlloc(sizeof(array(struct variable*)));

efn->args->length = 1;
efn->args->elemSize = sizeof(struct variable*);
efn->args->data = memoryAlloc(sizeof(struct variable*) * 50);efn->args->data[0] = ____BAH_COMPILER_VAR_685;
char * fnBinding =  "";
char * ____BAH_COMPILER_VAR_686 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(fn->name);
long int strLen_1 = strlen("(");
;                            
                    ____BAH_COMPILER_VAR_686 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_686+currStrOff, fn->name, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_686+currStrOff, "(", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_686[currStrOff] = 0;
                }
                char * fnCall =  ____BAH_COMPILER_VAR_686;
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
char * ____BAH_COMPILER_VAR_687 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_688 =intToStr(i);char * ____BAH_COMPILER_VAR_689 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_687);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(v);
long int strLen_3 = strlen(" = fnArgs->data[");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_688);
long int strLen_5 = strlen("];");
;                            
                    ____BAH_COMPILER_VAR_689 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    memcpy(____BAH_COMPILER_VAR_689+currStrOff, ____BAH_COMPILER_VAR_687, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_689+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_689+currStrOff, v, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_689+currStrOff, " = fnArgs->data[", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_689+currStrOff, ____BAH_COMPILER_VAR_688, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_689+currStrOff, "];", strLen_5);
                    currStrOff += strLen_5;
                    
                    ____BAH_COMPILER_VAR_689[currStrOff] = 0;
                }
                char * ____BAH_COMPILER_VAR_690 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(fnBinding);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_689);
;                            
                    ____BAH_COMPILER_VAR_690 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_690+currStrOff, fnBinding, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_690+currStrOff, ____BAH_COMPILER_VAR_689, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_690[currStrOff] = 0;
                }
                fnBinding =  ____BAH_COMPILER_VAR_690;
if ((i!=0)) {
char * ____BAH_COMPILER_VAR_691 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(fnCall);
long int strLen_1 = strlen(", ");
;                            
                    ____BAH_COMPILER_VAR_691 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_691+currStrOff, fnCall, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_691+currStrOff, ", ", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_691[currStrOff] = 0;
                }
                fnCall =  ____BAH_COMPILER_VAR_691;
}
if (isRCPpointerType(a->type)) {
char * ____BAH_COMPILER_VAR_692 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(fnCall);
long int strLen_1 = strlen(v);
;                            
                    ____BAH_COMPILER_VAR_692 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_692+currStrOff, fnCall, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_692+currStrOff, v, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_692[currStrOff] = 0;
                }
                fnCall =  ____BAH_COMPILER_VAR_692;
}
else {
char * ____BAH_COMPILER_VAR_693 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("*");
long int strLen_1 = strlen(v);
;                            
                    ____BAH_COMPILER_VAR_693 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_693+currStrOff, "*", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_693+currStrOff, v, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_693[currStrOff] = 0;
                }
                char * ____BAH_COMPILER_VAR_694 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(fnCall);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_693);
;                            
                    ____BAH_COMPILER_VAR_694 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_694+currStrOff, fnCall, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_694+currStrOff, ____BAH_COMPILER_VAR_693, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_694[currStrOff] = 0;
                }
                fnCall =  ____BAH_COMPILER_VAR_694;
}
};
char * setReturnValue =  "void* r = 0;";
if (isRCPpointerType(fn->returns->type)) {
setReturnValue =  "void* r = ";
}
else {
struct string cType =  getCType(fn->returns->type,elems);
if ((strcmp(cType.str((struct string*)&cType), "void") != 0)) {
char * ____BAH_COMPILER_VAR_695 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_696 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_697 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_695);
long int strLen_1 = strlen("* r = memoryAlloc(sizeof(");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_696);
long int strLen_3 = strlen("));*r = ");
;                            
                    ____BAH_COMPILER_VAR_697 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                    
                    memcpy(____BAH_COMPILER_VAR_697+currStrOff, ____BAH_COMPILER_VAR_695, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_697+currStrOff, "* r = memoryAlloc(sizeof(", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_697+currStrOff, ____BAH_COMPILER_VAR_696, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_697+currStrOff, "));*r = ", strLen_3);
                    currStrOff += strLen_3;
                    
                    ____BAH_COMPILER_VAR_697[currStrOff] = 0;
                }
                setReturnValue =  ____BAH_COMPILER_VAR_697;
}
}
char * ____BAH_COMPILER_VAR_698 =intToStr(len(fn->args));char * ____BAH_COMPILER_VAR_699 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("void* __attribute__((optimize(\"O0\"))) ");
long int strLen_1 = strlen(efn->name);
long int strLen_2 = strlen("(array(void*)* fnArgs) {\n        if (fnArgs->length != ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_698);
long int strLen_4 = strlen(") {\n            __BAH_panic(\"eval: calling function ");
long int strLen_5 = strlen(fn->name);
long int strLen_6 = strlen("() with the wrong number of arguments.\", \"BAH_COMPILER_INTERNAL\");\n        }\n        ");
long int strLen_7 = strlen(fnBinding);
long int strLen_8 = strlen("\n        ");
long int strLen_9 = strlen(setReturnValue);
long int strLen_10 = strlen(fnCall);
long int strLen_11 = strlen(");\n        return (void*)r;\n    };");
;                            
                    ____BAH_COMPILER_VAR_699 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11);
                    
                    memcpy(____BAH_COMPILER_VAR_699+currStrOff, "void* __attribute__((optimize(\"O0\"))) ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_699+currStrOff, efn->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_699+currStrOff, "(array(void*)* fnArgs) {\n        if (fnArgs->length != ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_699+currStrOff, ____BAH_COMPILER_VAR_698, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_699+currStrOff, ") {\n            __BAH_panic(\"eval: calling function ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_699+currStrOff, fn->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_699+currStrOff, "() with the wrong number of arguments.\", \"BAH_COMPILER_INTERNAL\");\n        }\n        ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_699+currStrOff, fnBinding, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_699+currStrOff, "\n        ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_699+currStrOff, setReturnValue, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_699+currStrOff, fnCall, strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_699+currStrOff, ");\n        return (void*)r;\n    };", strLen_11);
                    currStrOff += strLen_11;
                    
                    ____BAH_COMPILER_VAR_699[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_699));

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
char * ____BAH_COMPILER_VAR_700 =msg.str((struct string*)&msg);throwWarning(____BAH_COMPILER_VAR_700);
return;
}
if ((strcmp(ft.cont, "#eval") == 0)) {

                int ____BAH_COMPILER_VAR_701 = 0;
                for(int i=len(compilerState.includes)-1; i != -1; i--) {
                    if (compilerState.includes->data[i] != 0 && strcmp(compilerState.includes->data[i], "eval.bah") == 0) {
                        ____BAH_COMPILER_VAR_701 = 1;
                        break;
                    };
                };
                if ((____BAH_COMPILER_VAR_701==false)) {
if ((includeFile("eval.bah",elems)==false)) {
char * ____BAH_COMPILER_VAR_702 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Could not find file 'eval.bah'. Check your bah directory (");
long int strLen_1 = strlen(BAH_DIR);
long int strLen_2 = strlen(").");
;                            
                    ____BAH_COMPILER_VAR_702 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_702+currStrOff, "Could not find file 'eval.bah'. Check your bah directory (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_702+currStrOff, BAH_DIR, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_702+currStrOff, ").", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_702[currStrOff] = 0;
                }
                throwErr(&l->data[0],____BAH_COMPILER_VAR_702);
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
char * ____BAH_COMPILER_VAR_703 =fnName.str((struct string*)&fnName);struct func* fn =  searchFunc(____BAH_COMPILER_VAR_703,elems,true);
if ((fn==null)) {
char * ____BAH_COMPILER_VAR_704 =fnName.str((struct string*)&fnName);char * ____BAH_COMPILER_VAR_705 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Internal compiler error.\n Error parsing async call for function '");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_704);
long int strLen_2 = strlen("', arround {TOKEN}.");
;                            
                    ____BAH_COMPILER_VAR_705 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_705+currStrOff, "Internal compiler error.\n Error parsing async call for function '", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_705+currStrOff, ____BAH_COMPILER_VAR_704, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_705+currStrOff, "', arround {TOKEN}.", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_705[currStrOff] = 0;
                }
                throwErr(&fnT,____BAH_COMPILER_VAR_705);
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
char * ____BAH_COMPILER_VAR_706 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_707 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(sMembs);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_706);
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(a->name);
long int strLen_4 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_707 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_707+currStrOff, sMembs, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_707+currStrOff, ____BAH_COMPILER_VAR_706, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_707+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_707+currStrOff, a->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_707+currStrOff, ";\n", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_707[currStrOff] = 0;
                }
                sMembs =  ____BAH_COMPILER_VAR_707;
char * ____BAH_COMPILER_VAR_708 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(unSerMembs);
long int strLen_1 = strlen("args->");
long int strLen_2 = strlen(a->name);
;                            
                    ____BAH_COMPILER_VAR_708 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_708+currStrOff, unSerMembs, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_708+currStrOff, "args->", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_708+currStrOff, a->name, strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_708[currStrOff] = 0;
                }
                unSerMembs =  ____BAH_COMPILER_VAR_708;
i =  i + 1;
if ((i<len(fn->args))) {
char * ____BAH_COMPILER_VAR_709 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(unSerMembs);
long int strLen_1 = strlen(", ");
;                            
                    ____BAH_COMPILER_VAR_709 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_709+currStrOff, unSerMembs, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_709+currStrOff, ", ", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_709[currStrOff] = 0;
                }
                unSerMembs =  ____BAH_COMPILER_VAR_709;
}
};
char * ____BAH_COMPILER_VAR_710 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("struct {\n");
long int strLen_1 = strlen(sMembs);
long int strLen_2 = strlen("}");
;                            
                    ____BAH_COMPILER_VAR_710 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_710+currStrOff, "struct {\n", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_710+currStrOff, sMembs, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_710+currStrOff, "}", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_710[currStrOff] = 0;
                }
                char * tmpArgsStruct =  ____BAH_COMPILER_VAR_710;
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
char * ____BAH_COMPILER_VAR_711 =fnName.str((struct string*)&fnName);char * ____BAH_COMPILER_VAR_712 =sFnT.str((struct string*)&sFnT);char * ____BAH_COMPILER_VAR_713 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n    void ");
long int strLen_1 = strlen(fnWrapper);
long int strLen_2 = strlen("(");
long int strLen_3 = strlen(tmpArgsStruct);
long int strLen_4 = strlen("* args) {\n        ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_711);
long int strLen_6 = strlen("(");
long int strLen_7 = strlen(unSerMembs);
long int strLen_8 = strlen(");\n    };\n    {\n        ");
long int strLen_9 = strlen(tmpArgsStruct);
long int strLen_10 = strlen(" ");
long int strLen_11 = strlen(tmpArgs);
long int strLen_12 = strlen(" = {");
long int strLen_13 = strlen(____BAH_COMPILER_VAR_712);
long int strLen_14 = strlen("};\n        pthread_t id;\n        ");
long int strLen_15 = strlen(tCreate);
long int strLen_16 = strlen("(&id, 0, ");
long int strLen_17 = strlen(fnWrapper);
long int strLen_18 = strlen(", &");
long int strLen_19 = strlen(tmpArgs);
long int strLen_20 = strlen(");\n    }; \n    \n    ");
;                            
                    ____BAH_COMPILER_VAR_713 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14 + strLen_15 + strLen_16 + strLen_17 + strLen_18 + strLen_19 + strLen_20);
                    
                    memcpy(____BAH_COMPILER_VAR_713+currStrOff, "\n    void ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_713+currStrOff, fnWrapper, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_713+currStrOff, "(", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_713+currStrOff, tmpArgsStruct, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_713+currStrOff, "* args) {\n        ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_713+currStrOff, ____BAH_COMPILER_VAR_711, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_713+currStrOff, "(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_713+currStrOff, unSerMembs, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_713+currStrOff, ");\n    };\n    {\n        ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_713+currStrOff, tmpArgsStruct, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_713+currStrOff, " ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_713+currStrOff, tmpArgs, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_713+currStrOff, " = {", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_713+currStrOff, ____BAH_COMPILER_VAR_712, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_713+currStrOff, "};\n        pthread_t id;\n        ", strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_713+currStrOff, tCreate, strLen_15);
                    currStrOff += strLen_15;
                    
                    memcpy(____BAH_COMPILER_VAR_713+currStrOff, "(&id, 0, ", strLen_16);
                    currStrOff += strLen_16;
                    
                    memcpy(____BAH_COMPILER_VAR_713+currStrOff, fnWrapper, strLen_17);
                    currStrOff += strLen_17;
                    
                    memcpy(____BAH_COMPILER_VAR_713+currStrOff, ", &", strLen_18);
                    currStrOff += strLen_18;
                    
                    memcpy(____BAH_COMPILER_VAR_713+currStrOff, tmpArgs, strLen_19);
                    currStrOff += strLen_19;
                    
                    memcpy(____BAH_COMPILER_VAR_713+currStrOff, ");\n    }; \n    \n    ", strLen_20);
                    currStrOff += strLen_20;
                    
                    ____BAH_COMPILER_VAR_713[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_713));
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
char * ____BAH_COMPILER_VAR_714 =getTypeFromToken(&nt,true,elems);struct string ntt =  string(____BAH_COMPILER_VAR_714);
if ((ntt.hasPrefix((struct string*)&ntt,"chan:")==0)) {
char * ____BAH_COMPILER_VAR_715 =ntt.str((struct string*)&ntt);char * ____BAH_COMPILER_VAR_716 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot use var {TOKEN} (");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_715);
long int strLen_2 = strlen(") as channel.");
;                            
                    ____BAH_COMPILER_VAR_716 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_716+currStrOff, "Cannot use var {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_716+currStrOff, ____BAH_COMPILER_VAR_715, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_716+currStrOff, ") as channel.", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_716[currStrOff] = 0;
                }
                throwErr(&nt,____BAH_COMPILER_VAR_716);
}
ntt.trimLeft((struct string*)&ntt,5);
if (isGlobal()) {
throwErr(&t,"Cannot receive ({TOKEN}) from a channel outside of a function.");
}
char * tmpV =  "";
char * ____BAH_COMPILER_VAR_717 =ntt.str((struct string*)&ntt);if (isRCPpointerType(____BAH_COMPILER_VAR_717)) {
char * ____BAH_COMPILER_VAR_718 =ntt.str((struct string*)&ntt);struct string ct =  getCType(____BAH_COMPILER_VAR_718,elems);
char * ____BAH_COMPILER_VAR_719 =ct.str((struct string*)&ct);char * ____BAH_COMPILER_VAR_720 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("(");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_719);
long int strLen_2 = strlen(")");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen("->receive(");
long int strLen_5 = strlen(nt.cont);
long int strLen_6 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_720 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                    
                    memcpy(____BAH_COMPILER_VAR_720+currStrOff, "(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_720+currStrOff, ____BAH_COMPILER_VAR_719, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_720+currStrOff, ")", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_720+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_720+currStrOff, "->receive(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_720+currStrOff, nt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_720+currStrOff, ")", strLen_6);
                    currStrOff += strLen_6;
                    
                    ____BAH_COMPILER_VAR_720[currStrOff] = 0;
                }
                t.cont =  ____BAH_COMPILER_VAR_720;
}
else {
char * ____BAH_COMPILER_VAR_721 =ntt.str((struct string*)&ntt);struct string ct =  getCType(____BAH_COMPILER_VAR_721,elems);
if (RCPavailable()) {
char * ____BAH_COMPILER_VAR_722 =ntt.str((struct string*)&ntt);char * ____BAH_COMPILER_VAR_723 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_722);
long int strLen_1 = strlen("*");
;                            
                    ____BAH_COMPILER_VAR_723 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_723+currStrOff, ____BAH_COMPILER_VAR_722, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_723+currStrOff, "*", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_723[currStrOff] = 0;
                }
                char * ____BAH_COMPILER_VAR_724 =ct.str((struct string*)&ct);char * ____BAH_COMPILER_VAR_725 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("(");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_724);
long int strLen_2 = strlen("*)");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen("->receive(");
long int strLen_5 = strlen(nt.cont);
long int strLen_6 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_725 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                    
                    memcpy(____BAH_COMPILER_VAR_725+currStrOff, "(", strLen_0);
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
                tmpV =  registerRCPvar(____BAH_COMPILER_VAR_723,____BAH_COMPILER_VAR_725,elems);
char * ____BAH_COMPILER_VAR_726 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("*");
long int strLen_1 = strlen(tmpV);
;                            
                    ____BAH_COMPILER_VAR_726 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_726+currStrOff, "*", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_726+currStrOff, tmpV, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_726[currStrOff] = 0;
                }
                t.cont =  ____BAH_COMPILER_VAR_726;
}
else {
char * ____BAH_COMPILER_VAR_727 =ct.str((struct string*)&ct);char * ____BAH_COMPILER_VAR_728 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("*(");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_727);
long int strLen_2 = strlen("*)");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen("->receive(");
long int strLen_5 = strlen(nt.cont);
long int strLen_6 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_728 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                    
                    memcpy(____BAH_COMPILER_VAR_728+currStrOff, "*(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_728+currStrOff, ____BAH_COMPILER_VAR_727, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_728+currStrOff, "*)", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_728+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_728+currStrOff, "->receive(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_728+currStrOff, nt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_728+currStrOff, ")", strLen_6);
                    currStrOff += strLen_6;
                    
                    ____BAH_COMPILER_VAR_728[currStrOff] = 0;
                }
                t.cont =  ____BAH_COMPILER_VAR_728;
}
}
t.type =  TOKEN_TYPE_FUNC;
t.isFunc =  true;
if (RCPavailable()) {
char * ____BAH_COMPILER_VAR_729 =ntt.str((struct string*)&ntt);if (isRCPpointerType(____BAH_COMPILER_VAR_729)) {
char * ____BAH_COMPILER_VAR_730 =ntt.str((struct string*)&ntt);tmpV =  registerRCPvar(____BAH_COMPILER_VAR_730,t.cont,elems);
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
char * ____BAH_COMPILER_VAR_731 =getTypeFromToken(&pt,true,elems);struct string ptt =  string(____BAH_COMPILER_VAR_731);
if ((ptt.hasPrefix((struct string*)&ptt,"chan:")==0)) {
char * ____BAH_COMPILER_VAR_732 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot use var {TOKEN} (");
long int strLen_1 = strlen(ntt);
long int strLen_2 = strlen(") as channel.");
;                            
                    ____BAH_COMPILER_VAR_732 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_732+currStrOff, "Cannot use var {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_732+currStrOff, ntt, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_732+currStrOff, ") as channel.", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_732[currStrOff] = 0;
                }
                throwErr(&pt,____BAH_COMPILER_VAR_732);
}
ptt.trimLeft((struct string*)&ptt,5);
if (isGlobal()) {
throwErr(&t,"Cannot send ({TOKEN}) to a channel outside of a function.");
}
char * ____BAH_COMPILER_VAR_733 =ptt.str((struct string*)&ptt);if ((compTypes(____BAH_COMPILER_VAR_733,ntt)==false)) {
char * ____BAH_COMPILER_VAR_734 =ptt.str((struct string*)&ptt);char * ____BAH_COMPILER_VAR_735 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot send {TOKEN} (");
long int strLen_1 = strlen(ntt);
long int strLen_2 = strlen(") to channel of type ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_734);
long int strLen_4 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_735 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_735+currStrOff, "Cannot send {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_735+currStrOff, ntt, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_735+currStrOff, ") to channel of type ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_735+currStrOff, ____BAH_COMPILER_VAR_734, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_735+currStrOff, ".", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_735[currStrOff] = 0;
                }
                throwErr(&nt,____BAH_COMPILER_VAR_735);
}
i =  i+1;
char * ____BAH_COMPILER_VAR_736 =ptt.str((struct string*)&ptt);if (isRCPpointerType(____BAH_COMPILER_VAR_736)) {
char * ____BAH_COMPILER_VAR_737 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen("->send(");
long int strLen_2 = strlen(pt.cont);
long int strLen_3 = strlen(", ");
long int strLen_4 = strlen(nt.cont);
long int strLen_5 = strlen(");\n");
;                            
                    ____BAH_COMPILER_VAR_737 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    memcpy(____BAH_COMPILER_VAR_737+currStrOff, pt.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_737+currStrOff, "->send(", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_737+currStrOff, pt.cont, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_737+currStrOff, ", ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_737+currStrOff, nt.cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_737+currStrOff, ");\n", strLen_5);
                    currStrOff += strLen_5;
                    
                    ____BAH_COMPILER_VAR_737[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_737));
}
else {
struct string ct =  getCType(ntt,elems);
char * tmpV =  genCompilerVar();
char * ____BAH_COMPILER_VAR_738 =ct.str((struct string*)&ct);char * ____BAH_COMPILER_VAR_739 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n                    ");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_738);
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
                    ____BAH_COMPILER_VAR_739 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14);
                    
                    memcpy(____BAH_COMPILER_VAR_739+currStrOff, "\n                    ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_739+currStrOff, ____BAH_COMPILER_VAR_738, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_739+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_739+currStrOff, tmpV, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_739+currStrOff, " = ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_739+currStrOff, nt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_739+currStrOff, ";\n                    ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_739+currStrOff, pt.cont, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_739+currStrOff, "->sendAny(", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_739+currStrOff, pt.cont, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_739+currStrOff, ", &", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_739+currStrOff, tmpV, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_739+currStrOff, ", sizeof(", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_739+currStrOff, tmpV, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_739+currStrOff, "));\n", strLen_14);
                    currStrOff += strLen_14;
                    
                    ____BAH_COMPILER_VAR_739[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_739));
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
struct func* ____BAH_COMPILER_VAR_740 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_740->name = "";
____BAH_COMPILER_VAR_740->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_740->args->length = 0;
            ____BAH_COMPILER_VAR_740->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_740->returns= null;
____BAH_COMPILER_VAR_740->isBinding = false;
____BAH_COMPILER_VAR_740->from = "";
____BAH_COMPILER_VAR_740->file = "";
____BAH_COMPILER_VAR_740->line = 1;
____BAH_COMPILER_VAR_740->used = false;
____BAH_COMPILER_VAR_740->code = null;
struct func* fn =  ____BAH_COMPILER_VAR_740;
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
char * ____BAH_COMPILER_VAR_741 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot redeclare function {TOKEN}, previous declaration: ");
long int strLen_1 = strlen(ogFn->file);
long int strLen_2 = strlen(":");
long int strLen_3 = strlen(lineStr);
long int strLen_4 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_741 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_741+currStrOff, "Cannot redeclare function {TOKEN}, previous declaration: ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_741+currStrOff, ogFn->file, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_741+currStrOff, ":", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_741+currStrOff, lineStr, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_741+currStrOff, ".", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_741[currStrOff] = 0;
                }
                throwErr(&ft,____BAH_COMPILER_VAR_741);
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
char * ____BAH_COMPILER_VAR_742 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_742 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_742+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_742+currStrOff, ";\n", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_742[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_742));
return;
}
char * ____BAH_COMPILER_VAR_743 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen("{\n");
;                            
                    ____BAH_COMPILER_VAR_743 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_743+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_743+currStrOff, "{\n", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_743[currStrOff] = 0;
                }
                code =  ____BAH_COMPILER_VAR_743;
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
char * ____BAH_COMPILER_VAR_744 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Function '");
long int strLen_1 = strlen(fn->name);
long int strLen_2 = strlen("' is not returned.");
;                            
                    ____BAH_COMPILER_VAR_744 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_744+currStrOff, "Function '", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_744+currStrOff, fn->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_744+currStrOff, "' is not returned.", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_744[currStrOff] = 0;
                }
                throwErr(&l->data[len(l)-1],____BAH_COMPILER_VAR_744);
}
endRCPscope(fnElems,null);
}
fn->code =  fn->code->add(fn->code, OUTPUT);
OUTPUT =  oOut;
fn->code =  fn->code->add(fn->code, rope("};\n"));
OUTPUT =  OUTPUT->add(OUTPUT, fn->code);
if ((debug==true)) {
struct debugFunction* ____BAH_COMPILER_VAR_745 = memoryAlloc(sizeof(struct debugFunction));
____BAH_COMPILER_VAR_745->name= null;
____BAH_COMPILER_VAR_745->returns= null;
____BAH_COMPILER_VAR_745->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_745->args->length = 0;
            ____BAH_COMPILER_VAR_745->args->elemSize = sizeof(struct variable*);
            struct debugFunction* df =  ____BAH_COMPILER_VAR_745;
df->name =  fn->name;
df->args =  fn->args;
df->returns =  fn->returns->type;
struct debugFunction* ____BAH_COMPILER_VAR_746 = df;
char ** ____BAH_COMPILER_VAR_748 = (char **)((char*)(____BAH_COMPILER_VAR_746) + offsetof(struct debugFunction, name));
struct reflectElement ____BAH_COMPILER_VAR_749 = __reflect(____BAH_COMPILER_VAR_748, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct debugFunction, name));
char ** ____BAH_COMPILER_VAR_750 = (char **)((char*)(____BAH_COMPILER_VAR_746) + offsetof(struct debugFunction, returns));
struct reflectElement ____BAH_COMPILER_VAR_751 = __reflect(____BAH_COMPILER_VAR_750, sizeof(char *), "cpstring", "returns", 0, 0, 0, 0, offsetof(struct debugFunction, returns));
array(struct variable*)** ____BAH_COMPILER_VAR_752 = (array(struct variable*)**)((char*)(____BAH_COMPILER_VAR_746) + offsetof(struct debugFunction, args));
struct variable** ____BAH_COMPILER_VAR_753 = 0;
char ** ____BAH_COMPILER_VAR_755 = (char **)((char*)(____BAH_COMPILER_VAR_753) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_756 = __reflect(____BAH_COMPILER_VAR_755, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_757 = (char **)((char*)(____BAH_COMPILER_VAR_753) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_758 = __reflect(____BAH_COMPILER_VAR_757, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_759 = (char*)((char*)(____BAH_COMPILER_VAR_753) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_760 = __reflect(____BAH_COMPILER_VAR_759, sizeof(char), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_761 = (char **)((char*)(____BAH_COMPILER_VAR_753) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_762 = __reflect(____BAH_COMPILER_VAR_761, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_763 = (char*)((char*)(____BAH_COMPILER_VAR_753) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_764 = __reflect(____BAH_COMPILER_VAR_763, sizeof(char), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_765 = (char **)((char*)(____BAH_COMPILER_VAR_753) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_766 = __reflect(____BAH_COMPILER_VAR_765, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
char* ____BAH_COMPILER_VAR_767 = (char*)((char*)(____BAH_COMPILER_VAR_753) + offsetof(struct variable, outterScope));
struct reflectElement ____BAH_COMPILER_VAR_768 = __reflect(____BAH_COMPILER_VAR_767, sizeof(char), "bool", "outterScope", 0, 0, 0, 0, offsetof(struct variable, outterScope));
char* ____BAH_COMPILER_VAR_769 = (char*)((char*)(____BAH_COMPILER_VAR_753) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_770 = __reflect(____BAH_COMPILER_VAR_769, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_754 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_754->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_754->length = 8;
        ____BAH_COMPILER_VAR_754->data = memoryAlloc(____BAH_COMPILER_VAR_754->length * ____BAH_COMPILER_VAR_754->elemSize);
        ____BAH_COMPILER_VAR_754->data[0] = ____BAH_COMPILER_VAR_756;
____BAH_COMPILER_VAR_754->data[1] = ____BAH_COMPILER_VAR_758;
____BAH_COMPILER_VAR_754->data[2] = ____BAH_COMPILER_VAR_760;
____BAH_COMPILER_VAR_754->data[3] = ____BAH_COMPILER_VAR_762;
____BAH_COMPILER_VAR_754->data[4] = ____BAH_COMPILER_VAR_764;
____BAH_COMPILER_VAR_754->data[5] = ____BAH_COMPILER_VAR_766;
____BAH_COMPILER_VAR_754->data[6] = ____BAH_COMPILER_VAR_768;
____BAH_COMPILER_VAR_754->data[7] = ____BAH_COMPILER_VAR_770;
struct reflectElement ____BAH_COMPILER_VAR_771 = __reflect(____BAH_COMPILER_VAR_753, sizeof(struct variable), "variable*", "", 0, 0, 1, ____BAH_COMPILER_VAR_754, 0);

        struct reflectElement ____BAH_COMPILER_VAR_772 = ____BAH_COMPILER_VAR_771;
        struct reflectElement ____BAH_COMPILER_VAR_773 = __reflect(____BAH_COMPILER_VAR_752, sizeof(array(struct variable*)*), "[]variable*", "args", 1, &____BAH_COMPILER_VAR_772, 0, 0, offsetof(struct debugFunction, args));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_747 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_747->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_747->length = 3;
        ____BAH_COMPILER_VAR_747->data = memoryAlloc(____BAH_COMPILER_VAR_747->length * ____BAH_COMPILER_VAR_747->elemSize);
        ____BAH_COMPILER_VAR_747->data[0] = ____BAH_COMPILER_VAR_749;
____BAH_COMPILER_VAR_747->data[1] = ____BAH_COMPILER_VAR_751;
____BAH_COMPILER_VAR_747->data[2] = ____BAH_COMPILER_VAR_773;
struct reflectElement ____BAH_COMPILER_VAR_774 = __reflect(____BAH_COMPILER_VAR_746, sizeof(struct debugFunction), "debugFunction*", "df", 0, 0, 1, ____BAH_COMPILER_VAR_747, 0);
debugPrint("fn_declare",ft.line,____BAH_COMPILER_VAR_774);

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
char * ____BAH_COMPILER_VAR_775 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ft.cont);
long int strLen_1 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_775 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_775+currStrOff, ft.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_775+currStrOff, ";\n", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_775[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_775));
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
char * ____BAH_COMPILER_VAR_776 =ct.str((struct string*)&ct);char * ____BAH_COMPILER_VAR_777 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_776);
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(arg->name);
;                            
                    ____BAH_COMPILER_VAR_777 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                    
                    memcpy(____BAH_COMPILER_VAR_777+currStrOff, tmpfnArgsCType, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_777+currStrOff, ____BAH_COMPILER_VAR_776, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_777+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_777+currStrOff, arg->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    ____BAH_COMPILER_VAR_777[currStrOff] = 0;
                }
                tmpfnArgsCType =  ____BAH_COMPILER_VAR_777;
j =  j + 1;
if ((j<len(fn->args))) {
char * ____BAH_COMPILER_VAR_778 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(", ");
;                            
                    ____BAH_COMPILER_VAR_778 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_778+currStrOff, tmpfnArgsCType, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_778+currStrOff, ", ", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_778[currStrOff] = 0;
                }
                tmpfnArgsCType =  ____BAH_COMPILER_VAR_778;
}
};
char * ____BAH_COMPILER_VAR_779 =tmpfnRetCType.str((struct string*)&tmpfnRetCType);char * ____BAH_COMPILER_VAR_780 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_779);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(fn->name);
long int strLen_3 = strlen("(");
long int strLen_4 = strlen(tmpfnArgsCType);
long int strLen_5 = strlen(");\n");
;                            
                    ____BAH_COMPILER_VAR_780 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    memcpy(____BAH_COMPILER_VAR_780+currStrOff, ____BAH_COMPILER_VAR_779, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_780+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_780+currStrOff, fn->name, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_780+currStrOff, "(", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_780+currStrOff, tmpfnArgsCType, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_780+currStrOff, ");\n", strLen_5);
                    currStrOff += strLen_5;
                    
                    ____BAH_COMPILER_VAR_780[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_780));
};
void declareVar(struct variable* v,struct Elems* elems){
if ((v->isConst==true)) {
char * ____BAH_COMPILER_VAR_781 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("#define ");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(v->constVal);
long int strLen_4 = strlen("\n");
;                            
                    ____BAH_COMPILER_VAR_781 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_781+currStrOff, "#define ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_781+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_781+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_781+currStrOff, v->constVal, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_781+currStrOff, "\n", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_781[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_781));
}
else {
struct string cType =  getCType(v->type,elems);
char * ____BAH_COMPILER_VAR_782 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_783 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_782);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(v->name);
long int strLen_3 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_783 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                    
                    memcpy(____BAH_COMPILER_VAR_783+currStrOff, ____BAH_COMPILER_VAR_782, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_783+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_783+currStrOff, v->name, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_783+currStrOff, ";\n", strLen_3);
                    currStrOff += strLen_3;
                    
                    ____BAH_COMPILER_VAR_783[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_783));
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
                    char * ____BAH_COMPILER_VAR_784 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("#include ");
long int strLen_1 = strlen(compilerState.cIncludes->data[i]);
long int strLen_2 = strlen("\n");
;                            
                    ____BAH_COMPILER_VAR_784 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_784+currStrOff, "#include ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_784+currStrOff, compilerState.cIncludes->data[i], strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_784+currStrOff, "\n", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_784[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_784));
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
char * ____BAH_COMPILER_VAR_785 =elemType.str((struct string*)&elemType);struct string elemCtype =  getCType(____BAH_COMPILER_VAR_785,elems);
char * ____BAH_COMPILER_VAR_786 =elemCtype.str((struct string*)&elemCtype);char * ____BAH_COMPILER_VAR_787 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("typedef array(");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_786);
long int strLen_2 = strlen(")* ");
long int strLen_3 = strlen(t);
long int strLen_4 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_787 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    memcpy(____BAH_COMPILER_VAR_787+currStrOff, "typedef array(", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_787+currStrOff, ____BAH_COMPILER_VAR_786, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_787+currStrOff, ")* ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_787+currStrOff, t, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_787+currStrOff, ";\n", strLen_4);
                    currStrOff += strLen_4;
                    
                    ____BAH_COMPILER_VAR_787[currStrOff] = 0;
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_787));
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
struct flags ____BAH_COMPILER_VAR_788 = {};
____BAH_COMPILER_VAR_788.flags = memoryAlloc(sizeof(array(struct flag*)));
            ____BAH_COMPILER_VAR_788.flags->length = 0;
            ____BAH_COMPILER_VAR_788.flags->elemSize = sizeof(struct flag*);
            ____BAH_COMPILER_VAR_788.args = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_788.args->length = 0;
            ____BAH_COMPILER_VAR_788.args->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_788.addString = flags__addString;
____BAH_COMPILER_VAR_788.addBool = flags__addBool;
____BAH_COMPILER_VAR_788.addInt = flags__addInt;
____BAH_COMPILER_VAR_788.addFloat = flags__addFloat;
____BAH_COMPILER_VAR_788.invalidate = flags__invalidate;
____BAH_COMPILER_VAR_788.getFlag = flags__getFlag;
____BAH_COMPILER_VAR_788.get = flags__get;
____BAH_COMPILER_VAR_788.getInt = flags__getInt;
____BAH_COMPILER_VAR_788.getFloat = flags__getFloat;
____BAH_COMPILER_VAR_788.isSet = flags__isSet;
____BAH_COMPILER_VAR_788.parse = flags__parse;
flags =  ____BAH_COMPILER_VAR_788;
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
char * ____BAH_COMPILER_VAR_789 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Select the target OS for cross compilling (linux, windows, darwin), default: ");
long int strLen_1 = strlen(BAH_OS);
long int strLen_2 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_789 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_789+currStrOff, "Select the target OS for cross compilling (linux, windows, darwin), default: ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_789+currStrOff, BAH_OS, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_789+currStrOff, ".", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_789[currStrOff] = 0;
                }
                flags.addString((struct flags*)&flags,"target",____BAH_COMPILER_VAR_789);
char * ____BAH_COMPILER_VAR_790 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("If your Bah directory is not the default one (");
long int strLen_1 = strlen(BAH_DIR);
long int strLen_2 = strlen(").");
;                            
                    ____BAH_COMPILER_VAR_790 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_790+currStrOff, "If your Bah directory is not the default one (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_790+currStrOff, BAH_DIR, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_790+currStrOff, ").", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_790[currStrOff] = 0;
                }
                flags.addString((struct flags*)&flags,"bahDir",____BAH_COMPILER_VAR_790);
char * ____BAH_COMPILER_VAR_791 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("To change the C compiler used, default: ");
long int strLen_1 = strlen(BAH_CC);
long int strLen_2 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_791 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_791+currStrOff, "To change the C compiler used, default: ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_791+currStrOff, BAH_CC, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_791+currStrOff, ".", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_791[currStrOff] = 0;
                }
                flags.addString((struct flags*)&flags,"CC",____BAH_COMPILER_VAR_791);
flags.addBool((struct flags*)&flags,"object","Compile as an object.");
flags.parse((struct flags*)&flags,args);
if ((flags.isSet((struct flags*)&flags,"target")==1)) {
BAH_OS =  flags.get((struct flags*)&flags,"target");
char * ____BAH_COMPILER_VAR_792 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Build target: ");
long int strLen_1 = strlen(BAH_OS);
;                            
                    ____BAH_COMPILER_VAR_792 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_792+currStrOff, "Build target: ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_792+currStrOff, BAH_OS, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_792[currStrOff] = 0;
                }
                println(____BAH_COMPILER_VAR_792);
}
if ((flags.isSet((struct flags*)&flags,"bahDir")==1)) {
BAH_DIR =  flags.get((struct flags*)&flags,"bahDir");
array(char)* bahDirArr =  strAsArr(BAH_DIR);

                    if (bahDirArr->length <= len(bahDirArr)-1) {
                        printf("array (/home/alois/Documents/bah-bah/src/main.bah:79): bahDirArr[%d] with length %d\n", len(bahDirArr)-1, bahDirArr->length);
                        exit(1);
                    };
                    if ((bahDirArr->data[len(bahDirArr)-1]!=47)) {
char * ____BAH_COMPILER_VAR_793 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen("/");
;                            
                    ____BAH_COMPILER_VAR_793 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_793+currStrOff, BAH_DIR, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_793+currStrOff, "/", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_793[currStrOff] = 0;
                }
                BAH_DIR =  ____BAH_COMPILER_VAR_793;
}
char * ____BAH_COMPILER_VAR_794 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Bah directory: ");
long int strLen_1 = strlen(BAH_DIR);
;                            
                    ____BAH_COMPILER_VAR_794 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_794+currStrOff, "Bah directory: ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_794+currStrOff, BAH_DIR, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_794[currStrOff] = 0;
                }
                println(____BAH_COMPILER_VAR_794);
}
if ((flags.isSet((struct flags*)&flags,"CC")==1)) {
BAH_CC =  flags.get((struct flags*)&flags,"CC");
char * ____BAH_COMPILER_VAR_795 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("C compiler: ");
long int strLen_1 = strlen(BAH_CC);
;                            
                    ____BAH_COMPILER_VAR_795 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_795+currStrOff, "C compiler: ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_795+currStrOff, BAH_CC, strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_795[currStrOff] = 0;
                }
                println(____BAH_COMPILER_VAR_795);
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
char * ____BAH_COMPILER_VAR_796 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Bah compiler version: ");
long int strLen_1 = strlen(BAH_VERSION);
long int strLen_2 = strlen(".\n© Alois Laurent Boe");
;                            
                    ____BAH_COMPILER_VAR_796 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_796+currStrOff, "Bah compiler version: ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_796+currStrOff, BAH_VERSION, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_796+currStrOff, ".\n© Alois Laurent Boe", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_796[currStrOff] = 0;
                }
                println(____BAH_COMPILER_VAR_796);
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
struct compilerStateTag ____BAH_COMPILER_VAR_797 = {};
____BAH_COMPILER_VAR_797.includes = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_797.includes->length = 0;
            ____BAH_COMPILER_VAR_797.includes->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_797.cIncludes = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_797.cIncludes->length = 0;
            ____BAH_COMPILER_VAR_797.cIncludes->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_797.cLibs = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_797.cLibs->length = 0;
            ____BAH_COMPILER_VAR_797.cLibs->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_797.currentFile= null;
____BAH_COMPILER_VAR_797.currentDir = "./";
____BAH_COMPILER_VAR_797.isBranch = false;
____BAH_COMPILER_VAR_797.isFor = false;
____BAH_COMPILER_VAR_797.arrTypesDecl = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_797.arrTypesDecl->length = 0;
            ____BAH_COMPILER_VAR_797.arrTypesDecl->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_797.haveEntryPoint = false;
____BAH_COMPILER_VAR_797.RCPvars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_797.RCPvars->length = 0;
            ____BAH_COMPILER_VAR_797.RCPvars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_797.evals = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_797.evals->length = 0;
            ____BAH_COMPILER_VAR_797.evals->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_797.hasImports = false;
compilerState =  ____BAH_COMPILER_VAR_797;

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
struct fileMap ____BAH_COMPILER_VAR_798 = {};
____BAH_COMPILER_VAR_798.handle = -1;
____BAH_COMPILER_VAR_798.p= null;
____BAH_COMPILER_VAR_798.open = fileMap__open;
____BAH_COMPILER_VAR_798.isValid = fileMap__isValid;
____BAH_COMPILER_VAR_798.close = fileMap__close;
struct fileMap fm =  ____BAH_COMPILER_VAR_798;
char * f =  fm.open((struct fileMap*)&fm,fileName);
if ((fm.isValid((struct fileMap*)&fm)==0)) {
char * ____BAH_COMPILER_VAR_799 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Could not open file '");
long int strLen_1 = strlen(fileName);
long int strLen_2 = strlen("'.");
;                            
                    ____BAH_COMPILER_VAR_799 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_799+currStrOff, "Could not open file '", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_799+currStrOff, fileName, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_799+currStrOff, "'.", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_799[currStrOff] = 0;
                }
                __BAH_panic(____BAH_COMPILER_VAR_799,"/home/alois/Documents/bah-bah/src/main.bah:185");
}
long int startTime =  getTimeUnix();
array(struct Tok)* tokens =  lexer(f);
fm.close((struct fileMap*)&fm);
if ((len(tokens)==0)) {
char * ____BAH_COMPILER_VAR_800 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("File '");
long int strLen_1 = strlen(fileName);
long int strLen_2 = strlen("' not recognized.");
;                            
                    ____BAH_COMPILER_VAR_800 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_800+currStrOff, "File '", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_800+currStrOff, fileName, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_800+currStrOff, "' not recognized.", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_800[currStrOff] = 0;
                }
                __BAH_panic(____BAH_COMPILER_VAR_800,"/home/alois/Documents/bah-bah/src/main.bah:193");
}
struct Elems* ____BAH_COMPILER_VAR_801 = memoryAlloc(sizeof(struct Elems));
____BAH_COMPILER_VAR_801->vars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_801->vars->length = 0;
            ____BAH_COMPILER_VAR_801->vars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_801->structs = memoryAlloc(sizeof(array(struct cStruct*)));
            ____BAH_COMPILER_VAR_801->structs->length = 0;
            ____BAH_COMPILER_VAR_801->structs->elemSize = sizeof(struct cStruct*);
            ____BAH_COMPILER_VAR_801->types = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_801->types->length = 0;
            ____BAH_COMPILER_VAR_801->types->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_801->fns = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_801->fns->length = 0;
            ____BAH_COMPILER_VAR_801->fns->elemSize = sizeof(struct func*);
            struct Elems* elems =  ____BAH_COMPILER_VAR_801;
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
char * ____BAH_COMPILER_VAR_802 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Could not find std-libs, please check '");
long int strLen_1 = strlen(BAH_DIR);
long int strLen_2 = strlen("'");
;                            
                    ____BAH_COMPILER_VAR_802 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_802+currStrOff, "Could not find std-libs, please check '", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_802+currStrOff, BAH_DIR, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_802+currStrOff, "'", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_802[currStrOff] = 0;
                }
                __BAH_panic(____BAH_COMPILER_VAR_802,"/home/alois/Documents/bah-bah/src/main.bah:216");
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

                int ____BAH_COMPILER_VAR_803 = 0;
                for(int i=len(excludeFns)-1; i != -1; i--) {
                    if (excludeFns->data[i] != 0 && strcmp(excludeFns->data[i], fn->name) == 0) {
                        ____BAH_COMPILER_VAR_803 = 1;
                        break;
                    };
                };
                if ((((fn->used==false)&&(fn->code!=null))&&(____BAH_COMPILER_VAR_803==false))) {
char * ____BAH_COMPILER_VAR_804 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("//optimized out: ");
long int strLen_1 = strlen(fn->name);
long int strLen_2 = strlen("\n");
;                            
                    ____BAH_COMPILER_VAR_804 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_804+currStrOff, "//optimized out: ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_804+currStrOff, fn->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_804+currStrOff, "\n", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_804[currStrOff] = 0;
                }
                ropeSet(fn->code,____BAH_COMPILER_VAR_804);
}
};
}
if ((debug==true)) {
debugEnd();
return 0;
}
if ((isObject==false)) {
long int totalTime =  getTimeUnix() - startTime;
char * ____BAH_COMPILER_VAR_805 =intToStr(totalLines);char * ____BAH_COMPILER_VAR_806 =intToStr(totalTime / 1000000);char * ____BAH_COMPILER_VAR_807 =intToStr(totalLexerTime / 1000000);char * ____BAH_COMPILER_VAR_808 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Parsed. (");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_805);
long int strLen_2 = strlen(" lines, total time: ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_806);
long int strLen_4 = strlen("ms, lexer time: ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_807);
long int strLen_6 = strlen("ms)\e[0m");
;                            
                    ____BAH_COMPILER_VAR_808 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                    
                    memcpy(____BAH_COMPILER_VAR_808+currStrOff, "Parsed. (", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_808+currStrOff, ____BAH_COMPILER_VAR_805, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_808+currStrOff, " lines, total time: ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_808+currStrOff, ____BAH_COMPILER_VAR_806, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_808+currStrOff, "ms, lexer time: ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_808+currStrOff, ____BAH_COMPILER_VAR_807, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_808+currStrOff, "ms)\e[0m", strLen_6);
                    currStrOff += strLen_6;
                    
                    ____BAH_COMPILER_VAR_808[currStrOff] = 0;
                }
                println(____BAH_COMPILER_VAR_808);
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
char * ____BAH_COMPILER_VAR_809 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(fileName);
long int strLen_1 = strlen(".o");
;                            
                    ____BAH_COMPILER_VAR_809 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_809+currStrOff, fileName, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_809+currStrOff, ".o", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_809[currStrOff] = 0;
                }
                fileName =  ____BAH_COMPILER_VAR_809;
obj =  "-c";
}
char * randFileName =  "-x c - -x none";
char * ____BAH_COMPILER_VAR_810 =null;
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
                    ____BAH_COMPILER_VAR_810 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14 + strLen_15 + strLen_16);
                    
                    memcpy(____BAH_COMPILER_VAR_810+currStrOff, BAH_CC, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_810+currStrOff, " -I \"", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_810+currStrOff, BAH_DIR, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_810+currStrOff, "libs/", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_810+currStrOff, BAH_OS, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_810+currStrOff, "/include/\" -L \"", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_810+currStrOff, BAH_DIR, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_810+currStrOff, "libs/", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_810+currStrOff, BAH_OS, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_810+currStrOff, "/\" ", strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_810+currStrOff, randFileName, strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_810+currStrOff, " ", strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_810+currStrOff, isStatic, strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_810+currStrOff, " ", strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_810+currStrOff, obj, strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_810+currStrOff, " -w -O1 -o ", strLen_15);
                    currStrOff += strLen_15;
                    
                    memcpy(____BAH_COMPILER_VAR_810+currStrOff, fileName, strLen_16);
                    currStrOff += strLen_16;
                    
                    ____BAH_COMPILER_VAR_810[currStrOff] = 0;
                }
                char * gccArgs =  ____BAH_COMPILER_VAR_810;
if ((flags.isSet((struct flags*)&flags,"l")==1)) {
char * ____BAH_COMPILER_VAR_811 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(gccArgs);
long int strLen_1 = strlen(" -c");
;                            
                    ____BAH_COMPILER_VAR_811 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_811+currStrOff, gccArgs, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_811+currStrOff, " -c", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_811[currStrOff] = 0;
                }
                gccArgs =  ____BAH_COMPILER_VAR_811;
}
array(char *)* cLibs =  compilerState.cLibs;
long int i =  0;
while ((i<len(cLibs))) {

                    if (cLibs->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/main.bah:296): cLibs[%d] with length %d\n", i, cLibs->length);
                        exit(1);
                    };
                    char * l =  cLibs->data[i];
char * ____BAH_COMPILER_VAR_812 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(gccArgs);
long int strLen_1 = strlen(" -");
long int strLen_2 = strlen(l);
;                            
                    ____BAH_COMPILER_VAR_812 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_812+currStrOff, gccArgs, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_812+currStrOff, " -", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_812+currStrOff, l, strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_812[currStrOff] = 0;
                }
                gccArgs =  ____BAH_COMPILER_VAR_812;
i =  i + 1;
};
struct command cmd =  command(gccArgs);
cmd.input =  OUTPUT->toStr((struct rope*)OUTPUT);
if ((flags.isSet((struct flags*)&flags,"verboseCC")==0)) {
cmd.error =  false;
}
if ((flags.isSet((struct flags*)&flags,"verboseCC")==1)) {
char * ____BAH_COMPILER_VAR_813 =cmd.run((struct command*)&cmd);println(____BAH_COMPILER_VAR_813);
}
else {
cmd.run((struct command*)&cmd);
}
if ((cmd.status!=0)) {
println("\e[1;31m[CC-ERROR]\e[0m\nCould not compiled.");
return 1;
}
if ((flags.isSet((struct flags*)&flags,"l")==1)) {
char * ____BAH_COMPILER_VAR_814 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("ar rcs ");
long int strLen_1 = strlen(fileName);
long int strLen_2 = strlen(".a ");
long int strLen_3 = strlen(fileName);
;                            
                    ____BAH_COMPILER_VAR_814 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                    
                    memcpy(____BAH_COMPILER_VAR_814+currStrOff, "ar rcs ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_814+currStrOff, fileName, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_814+currStrOff, ".a ", strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_814+currStrOff, fileName, strLen_3);
                    currStrOff += strLen_3;
                    
                    ____BAH_COMPILER_VAR_814[currStrOff] = 0;
                }
                cmd =  command(____BAH_COMPILER_VAR_814);
cmd.run((struct command*)&cmd);
}
}
else {
if ((flags.isSet((struct flags*)&flags,"o")==0)) {
char * ____BAH_COMPILER_VAR_815 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(fileName);
long int strLen_1 = strlen(".c");
;                            
                    ____BAH_COMPILER_VAR_815 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    memcpy(____BAH_COMPILER_VAR_815+currStrOff, fileName, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_815+currStrOff, ".c", strLen_1);
                    currStrOff += strLen_1;
                    
                    ____BAH_COMPILER_VAR_815[currStrOff] = 0;
                }
                fileName =  ____BAH_COMPILER_VAR_815;
}
char * ____BAH_COMPILER_VAR_816 =null;
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
                    ____BAH_COMPILER_VAR_816 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13);
                    
                    memcpy(____BAH_COMPILER_VAR_816+currStrOff, BAH_CC, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_816+currStrOff, " -I \"", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_816+currStrOff, BAH_DIR, strLen_2);
                    currStrOff += strLen_2;
                    
                    memcpy(____BAH_COMPILER_VAR_816+currStrOff, "libs/", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_816+currStrOff, BAH_OS, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_816+currStrOff, "/include/\" -L \"", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_816+currStrOff, BAH_DIR, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_816+currStrOff, "libs/", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_816+currStrOff, BAH_OS, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_816+currStrOff, "/\" ", strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_816+currStrOff, fileName, strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_816+currStrOff, " ", strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_816+currStrOff, isStatic, strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_816+currStrOff, " -O1 -w ", strLen_13);
                    currStrOff += strLen_13;
                    
                    ____BAH_COMPILER_VAR_816[currStrOff] = 0;
                }
                char * gccArgs =  ____BAH_COMPILER_VAR_816;
array(char *)* cLibs =  compilerState.cLibs;
long int i =  0;
while ((i<len(cLibs))) {

                    if (cLibs->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/main.bah:334): cLibs[%d] with length %d\n", i, cLibs->length);
                        exit(1);
                    };
                    char * l =  cLibs->data[i];
char * ____BAH_COMPILER_VAR_817 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(gccArgs);
long int strLen_1 = strlen(" -");
long int strLen_2 = strlen(l);
;                            
                    ____BAH_COMPILER_VAR_817 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_817+currStrOff, gccArgs, strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_817+currStrOff, " -", strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_817+currStrOff, l, strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_817[currStrOff] = 0;
                }
                gccArgs =  ____BAH_COMPILER_VAR_817;
i =  i + 1;
};
char * ____BAH_COMPILER_VAR_818 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("//COMPILE WITH: '");
long int strLen_1 = strlen(gccArgs);
long int strLen_2 = strlen("'\n");
;                            
                    ____BAH_COMPILER_VAR_818 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_818+currStrOff, "//COMPILE WITH: '", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_818+currStrOff, gccArgs, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_818+currStrOff, "'\n", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_818[currStrOff] = 0;
                }
                OUTPUT =  rope(____BAH_COMPILER_VAR_818)->add(rope(____BAH_COMPILER_VAR_818), OUTPUT);
struct fileStream ____BAH_COMPILER_VAR_819 = {};
____BAH_COMPILER_VAR_819.handle= null;
____BAH_COMPILER_VAR_819.isValid = fileStream__isValid;
____BAH_COMPILER_VAR_819.open = fileStream__open;
____BAH_COMPILER_VAR_819.close = fileStream__close;
____BAH_COMPILER_VAR_819.getPos = fileStream__getPos;
____BAH_COMPILER_VAR_819.setPos = fileStream__setPos;
____BAH_COMPILER_VAR_819.getSize = fileStream__getSize;
____BAH_COMPILER_VAR_819.rewind = fileStream__rewind;
____BAH_COMPILER_VAR_819.getChar = fileStream__getChar;
____BAH_COMPILER_VAR_819.setChar = fileStream__setChar;
____BAH_COMPILER_VAR_819.createFile = fileStream__createFile;
____BAH_COMPILER_VAR_819.writeFile = fileStream__writeFile;
____BAH_COMPILER_VAR_819.writePtr = fileStream__writePtr;
____BAH_COMPILER_VAR_819.readPtr = fileStream__readPtr;
____BAH_COMPILER_VAR_819.readContent = fileStream__readContent;
____BAH_COMPILER_VAR_819.readBytes = fileStream__readBytes;
____BAH_COMPILER_VAR_819.writeBytes = fileStream__writeBytes;
struct fileStream fs =  ____BAH_COMPILER_VAR_819;
fs.open((struct fileStream*)&fs,fileName,"w");
char * ____BAH_COMPILER_VAR_820 =OUTPUT->toStr((struct rope*)OUTPUT);fs.writeFile((struct fileStream*)&fs,____BAH_COMPILER_VAR_820);
fs.close((struct fileStream*)&fs);
}
if ((isObject==false)) {
long int totalTime =  getTimeUnix() - startTime;
char * ____BAH_COMPILER_VAR_821 =intToStr(totalTime / 1000000);char * ____BAH_COMPILER_VAR_822 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\e[1;32mDone. (compiled in ");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_821);
long int strLen_2 = strlen("ms)\e[0m");
;                            
                    ____BAH_COMPILER_VAR_822 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    memcpy(____BAH_COMPILER_VAR_822+currStrOff, "\e[1;32mDone. (compiled in ", strLen_0);
                    currStrOff += strLen_0;
                    
                    memcpy(____BAH_COMPILER_VAR_822+currStrOff, ____BAH_COMPILER_VAR_821, strLen_1);
                    currStrOff += strLen_1;
                    
                    memcpy(____BAH_COMPILER_VAR_822+currStrOff, "ms)\e[0m", strLen_2);
                    currStrOff += strLen_2;
                    
                    ____BAH_COMPILER_VAR_822[currStrOff] = 0;
                }
                println(____BAH_COMPILER_VAR_822);
}
return 0;
};

    
    void __attribute__((optimize("O0"))) __BAH_init() {
        __BAH_panic_chan =  null;
RAND_SEEDED =  0;
BAH_DIR =  "/opt/bah/";
BAH_OS =  "linux";
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
    