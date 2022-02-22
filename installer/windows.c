//COMPILE WITH: 'x86_64-w64-mingw32-gcc -I "/opt/bah/libs/windows/include/" -L "/opt/bah/libs/windows/" ../installer/windows.c -static -O1 -w  -l:gc.a -lpthread -lm'

void __BAH_init();
#define noCheck(v) v
#define array(type)	struct{	type *data; long int length; long int elemSize; }
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
#define true (int)1
#define false (int)0
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
long int ____BAH_COMPILER_VAR_0 = 0;
return ____BAH_COMPILER_VAR_0;
}
long int i =  0;
noCheck( array ( void* ) *arr = a );
noCheck( i = arr -> length );
long int ____BAH_COMPILER_VAR_1 = i;
return ____BAH_COMPILER_VAR_1;
};
#include <gc.h>
void * memoryAlloc(long int s){
void * ____BAH_COMPILER_VAR_2 = GC_MALLOC(s);
return ____BAH_COMPILER_VAR_2;
};
void destroy(void * a){
GC_FREE(a);
};
void clear(void * a){
noCheck( array ( void* ) *arr = a );
noCheck( destroy ( arr -> data ) );
noCheck( arr -> data = memoryAlloc ( sizeof ( 0 ) ) );
noCheck( arr -> length = 0 );
};
void * memoryRealloc(void * p,long int s){
void * ____BAH_COMPILER_VAR_3 = GC_REALLOC(p,s);
return ____BAH_COMPILER_VAR_3;
};
void cleanShutDown(){
exit(1);
return;
};
void append(void * a,void * b){
noCheck( array ( void* ) *arrA = a );
noCheck( array ( void* ) *arrB = b );
long int lenA =  0;
long int lenB =  0;
long int realSizeA =  0;
long int realSizeB =  0;
noCheck( lenA = len ( arrA ) );
noCheck( lenB = len ( arrB ) );
if ((lenB==0)) {
return;
}
if ((lenA==0)) {
noCheck( arrA -> data = arrB -> data );
noCheck( arrA -> length = arrB -> length );
return;
}
noCheck( realSizeA = lenA * arrA -> elemSize );
noCheck( realSizeB = lenB * arrB -> elemSize );
void * buff =  memoryAlloc(realSizeA + realSizeB + 32);
noCheck( memcpy ( buff , arrA -> data , realSizeA ) );
noCheck( memcpy ( buff + lenA , arrB -> data , realSizeB ) );
noCheck( arrA -> length = lenA + lenB );
noCheck( arrA -> data = buff );
};
void copy(void * a,void * b){
noCheck( array ( void* ) *arrA = a );
noCheck( array ( void* ) *arrB = b );
long int lenB =  0;
long int realSizeB =  0;
noCheck( lenB = len ( arrB ) );
noCheck( realSizeB = lenB * arrB -> elemSize );
noCheck( arrA -> data = memoryAlloc ( realSizeB ) );
noCheck( memcpy ( arrA -> data , arrB -> data , realSizeB ) );
noCheck( arrA -> length = arrB -> length );
};
#define PROT_READ 2
#define PROT_READWRITE 4
void * GLOBAL_MAPPED_MEMORY_FILE;
void * sharedMemory(long int size){
if ((size==0)) {
size =  4096;
}
if ((GLOBAL_MAPPED_MEMORY_FILE==null)) {
GLOBAL_MAPPED_MEMORY_FILE =  CreateFileMapping(-1,0,PROT_READWRITE,0,size,"Global\\BahFileMap");
}
if ((GLOBAL_MAPPED_MEMORY_FILE==null)) {
printf("sharedMemory: could not make map file.");
exit(1);
}
void * r =  MapViewOfFile(GLOBAL_MAPPED_MEMORY_FILE,noCheck( FILE_MAP_ALL_ACCESS ),0,0,size);
void * ____BAH_COMPILER_VAR_7 = r;
return ____BAH_COMPILER_VAR_7;
};
void closeSharedMemory(){
CloseHandle(GLOBAL_MAPPED_MEMORY_FILE);
};
void allocateArray(void * arr,long int nbElems){
noCheck( array ( void* ) *a = arr );
noCheck( a -> length = nbElems );
noCheck( a -> data = memoryAlloc ( nbElems * a -> elemSize ) );
};
typedef array(char)* __BAH_ARR_TYPE_char;
__BAH_ARR_TYPE_char ser(void * a);
__BAH_ARR_TYPE_char __serialize(void * a,long int s){
char * r =  memoryAlloc(s + 9);
memcpy(r,&s,8);
memcpy(noCheck( r + 8 ),a,s);
long int l =  s + 1;
array(char)* arr = memoryAlloc(sizeof(array(char)));

arr->length = 0;
arr->elemSize = sizeof(char);
noCheck( arr -> length = s + 8 );
noCheck( arr -> elemSize = 1 );
noCheck( arr -> data = r );
array(char)* ____BAH_COMPILER_VAR_8 = arr;
return ____BAH_COMPILER_VAR_8;
};
long int serlen(__BAH_ARR_TYPE_char data){

                if (data->length <= 0) {
                    printf("array (/opt/bah/memory.bah:192): data[%d] with length %d\n", 0, data->length);
                    exit(1);
                };
                
                if (data->length <= 1) {
                    printf("array (/opt/bah/memory.bah:192): data[%d] with length %d\n", 1, data->length);
                    exit(1);
                };
                
                if (data->length <= 2) {
                    printf("array (/opt/bah/memory.bah:192): data[%d] with length %d\n", 2, data->length);
                    exit(1);
                };
                
                if (data->length <= 3) {
                    printf("array (/opt/bah/memory.bah:192): data[%d] with length %d\n", 3, data->length);
                    exit(1);
                };
                
                if (data->length <= 4) {
                    printf("array (/opt/bah/memory.bah:192): data[%d] with length %d\n", 4, data->length);
                    exit(1);
                };
                
                if (data->length <= 5) {
                    printf("array (/opt/bah/memory.bah:192): data[%d] with length %d\n", 5, data->length);
                    exit(1);
                };
                
                if (data->length <= 6) {
                    printf("array (/opt/bah/memory.bah:192): data[%d] with length %d\n", 6, data->length);
                    exit(1);
                };
                
                if (data->length <= 7) {
                    printf("array (/opt/bah/memory.bah:192): data[%d] with length %d\n", 7, data->length);
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
long int ____BAH_COMPILER_VAR_9 = noCheck( *sarr -> data );
return ____BAH_COMPILER_VAR_9;
};
void * unser(__BAH_ARR_TYPE_char data){
long int sptr =  serlen(data);
void * r =  memoryAlloc(sptr);
memcpy(r,noCheck( data -> data + 8 ),sptr);
void * ____BAH_COMPILER_VAR_10 = r;
return ____BAH_COMPILER_VAR_10;
};
char * memoryAllocSTR(long int s){
void * r =  GC_malloc_atomic(s);
memset(r,0,s);
char * ____BAH_COMPILER_VAR_11 = r;
return ____BAH_COMPILER_VAR_11;
};
char * concatCPSTRING(char * a,char * b){
long int lenA =  strlen(a);
long int lenB =  strlen(b);
char * r =  memoryAlloc(lenA + lenB + 1);
strncpy(r,a,lenA);
strcat(r,b);
char * ____BAH_COMPILER_VAR_12 = r;
return ____BAH_COMPILER_VAR_12;
};
char * __STR(char * a){
long int lenA =  strlen(a);
char * r =  memoryAlloc(lenA + 1);
strncpy(r,a,lenA);
char * ____BAH_COMPILER_VAR_13 = r;
return ____BAH_COMPILER_VAR_13;
};
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
void print(char * s){
write((void *)1,s,strlen(s));
};
void * cArr(void * arr){
noCheck( array ( void* ) *a = arr );
void * ____BAH_COMPILER_VAR_14 = noCheck( a -> data );
return ____BAH_COMPILER_VAR_14;
};
int __checkString(char * s,char * l){
if (((void *)s==null)) {
char * ____BAH_COMPILER_VAR_15 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("cpstring (");
long int strLen_1 = strlen(l);
long int strLen_2 = strlen(") is null \n");
;                            
                        ____BAH_COMPILER_VAR_15 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_15+currStrOff, "cpstring (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_15+currStrOff, l, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_15+currStrOff, ") is null \n", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    print(____BAH_COMPILER_VAR_15);
exit(1);
}
int ____BAH_COMPILER_VAR_16 = true;
return ____BAH_COMPILER_VAR_16;
};
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
struct mutexCondition ____BAH_COMPILER_VAR_17 = {};
____BAH_COMPILER_VAR_17.init = mutexCondition__init;
____BAH_COMPILER_VAR_17.wait = mutexCondition__wait;
____BAH_COMPILER_VAR_17.send = mutexCondition__send;
____BAH_COMPILER_VAR_17.destroy = mutexCondition__destroy;
struct mutexCondition m =  ____BAH_COMPILER_VAR_17;
m.init((struct mutexCondition*)&m);
struct mutexCondition ____BAH_COMPILER_VAR_18 = m;
return ____BAH_COMPILER_VAR_18;
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
struct mutex ____BAH_COMPILER_VAR_19 = {};
____BAH_COMPILER_VAR_19.init = mutex__init;
____BAH_COMPILER_VAR_19.lock = mutex__lock;
____BAH_COMPILER_VAR_19.unlock = mutex__unlock;
____BAH_COMPILER_VAR_19.destroy = mutex__destroy;
struct mutex m =  ____BAH_COMPILER_VAR_19;
m.init((struct mutex*)&m);
struct mutex ____BAH_COMPILER_VAR_20 = m;
return ____BAH_COMPILER_VAR_20;
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
struct queueNode* ____BAH_COMPILER_VAR_21 = memoryAlloc(sizeof(struct queueNode));
____BAH_COMPILER_VAR_21->data= null;
____BAH_COMPILER_VAR_21->next= null;
struct queueNode* node =  ____BAH_COMPILER_VAR_21;
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
void * ____BAH_COMPILER_VAR_24 = zp;
return ____BAH_COMPILER_VAR_24;
}
struct queueNode* ptr =  this->head;
while ((ptr->key!=key)) {
if ((ptr->next==null)) {
void * ____BAH_COMPILER_VAR_25 = zp;
return ____BAH_COMPILER_VAR_25;
}
ptr =  ptr->next;
};
void * data =  ptr->data;
void * ____BAH_COMPILER_VAR_26 = data;
return ____BAH_COMPILER_VAR_26;
};
void queue__set(struct queue* this,long int key,void * data){
this->delete((struct queue*)this,key);
struct queueNode* ____BAH_COMPILER_VAR_27 = memoryAlloc(sizeof(struct queueNode));
____BAH_COMPILER_VAR_27->data= null;
____BAH_COMPILER_VAR_27->next= null;
struct queueNode* node =  ____BAH_COMPILER_VAR_27;
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
void * ____BAH_COMPILER_VAR_28 = data;
return ____BAH_COMPILER_VAR_28;
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
void * ____BAH_COMPILER_VAR_29 = data;
return ____BAH_COMPILER_VAR_29;
};
void channel__destroy(struct channel* this){
pthread_mutex_destroy(&this->m_mut);
pthread_cond_destroy(&this->w_cond);
pthread_cond_destroy(&this->r_cond);
};
long int channel__len(struct channel* this){
long int l =  this->queue->length;
long int ____BAH_COMPILER_VAR_30 = l;
return ____BAH_COMPILER_VAR_30;
};
struct channel* channel(){
struct channel* ____BAH_COMPILER_VAR_31 = memoryAlloc(sizeof(struct channel));
____BAH_COMPILER_VAR_31->w_waitting = 0;
____BAH_COMPILER_VAR_31->r_waitting = 0;
____BAH_COMPILER_VAR_31->queue= null;
____BAH_COMPILER_VAR_31->cap = -1;
____BAH_COMPILER_VAR_31->send = channel__send;
____BAH_COMPILER_VAR_31->sendAny = channel__sendAny;
____BAH_COMPILER_VAR_31->receive = channel__receive;
____BAH_COMPILER_VAR_31->destroy = channel__destroy;
____BAH_COMPILER_VAR_31->len = channel__len;
struct channel* c =  ____BAH_COMPILER_VAR_31;
pthread_mutex_init(&c->m_mut,0);
pthread_cond_init(&c->w_cond,0);
pthread_cond_init(&c->r_cond,0);
struct queue* ____BAH_COMPILER_VAR_32 = memoryAlloc(sizeof(struct queue));
____BAH_COMPILER_VAR_32->length = 0;
____BAH_COMPILER_VAR_32->head= null;
____BAH_COMPILER_VAR_32->insert = queue__insert;
____BAH_COMPILER_VAR_32->delete = queue__delete;
____BAH_COMPILER_VAR_32->get = queue__get;
____BAH_COMPILER_VAR_32->set = queue__set;
____BAH_COMPILER_VAR_32->pop = queue__pop;
____BAH_COMPILER_VAR_32->clear = queue__clear;
c->queue =  ____BAH_COMPILER_VAR_32;
struct channel* ____BAH_COMPILER_VAR_33 = c;
return ____BAH_COMPILER_VAR_33;
};
void setChanCap(void * c,long int cap){
struct channel* cp =  c;
cp->cap =  cap;
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
void __BAH_panic(char * e,char * line){
if ((__BAH_panic_chan!=null)) {
__BAH_panic_chan->send(__BAH_panic_chan, e);
return;
}
char * ____BAH_COMPILER_VAR_35 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("panic (");
long int strLen_1 = strlen(line);
long int strLen_2 = strlen("): ");
long int strLen_3 = strlen(e);
long int strLen_4 = strlen("\n");
;                            
                        ____BAH_COMPILER_VAR_35 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_35+currStrOff, "panic (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_35+currStrOff, line, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_35+currStrOff, "): ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_35+currStrOff, e, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_35+currStrOff, "\n", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    print(____BAH_COMPILER_VAR_35);
cleanShutDown();
};
int recover(char ** s){
__BAH_panic_chan = channel();
char * err =  (char *)__BAH_panic_chan->receive(__BAH_panic_chan);
*s =  err;
int ____BAH_COMPILER_VAR_36 = true;
return ____BAH_COMPILER_VAR_36;
};
__BAH_ARR_TYPE_char strAsArr(char * s);
char * __Bah_safe_string(char * s){
if (((void *)s==null)) {
char * ____BAH_COMPILER_VAR_37 = "(nil)";
return ____BAH_COMPILER_VAR_37;
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
char * ____BAH_COMPILER_VAR_38 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\"");
long int strLen_1 = strlen(s);
long int strLen_2 = strlen("\"");
;                            
                        ____BAH_COMPILER_VAR_38 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_38+currStrOff, "\"", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_38+currStrOff, s, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_38+currStrOff, "\"", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    char * ____BAH_COMPILER_VAR_39 = ____BAH_COMPILER_VAR_38;
return ____BAH_COMPILER_VAR_39;
};
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <math.h>
void strCatOffset(char * dest,long int destLen,char * src,long int srcLen){
memcpy(noCheck( dest + destLen ),src,srcLen);
};
char cpstringCharAt(char * s,long int i){
char c =  (char)0;
noCheck( c = s [ i ] );
char ____BAH_COMPILER_VAR_40 = c;
return ____BAH_COMPILER_VAR_40;
};
char * charToString(char c){
char * s =  memoryAlloc(2);
strncpy(s,(char *)&c,1);
char * ____BAH_COMPILER_VAR_41 = s;
return ____BAH_COMPILER_VAR_41;
};
long int isUpper(char c){
if ((c>(char)64)) {
if ((c<(char)91)) {
long int ____BAH_COMPILER_VAR_42 = 1;
return ____BAH_COMPILER_VAR_42;
}
}
long int ____BAH_COMPILER_VAR_43 = 0;
return ____BAH_COMPILER_VAR_43;
};
long int isLower(char c){
if ((c>(char)96)) {
if ((c<(char)123)) {
long int ____BAH_COMPILER_VAR_44 = 1;
return ____BAH_COMPILER_VAR_44;
}
}
long int ____BAH_COMPILER_VAR_45 = 0;
return ____BAH_COMPILER_VAR_45;
};
long int isLetter(char s){
if (isUpper(s)) {
long int ____BAH_COMPILER_VAR_46 = 1;
return ____BAH_COMPILER_VAR_46;
}
if (isLower(s)) {
long int ____BAH_COMPILER_VAR_47 = 1;
return ____BAH_COMPILER_VAR_47;
}
long int ____BAH_COMPILER_VAR_48 = 0;
return ____BAH_COMPILER_VAR_48;
};
long int isNumber(char c){
if ((c>(char)47)) {
if ((c<(char)58)) {
long int ____BAH_COMPILER_VAR_49 = 1;
return ____BAH_COMPILER_VAR_49;
}
}
long int ____BAH_COMPILER_VAR_50 = 0;
return ____BAH_COMPILER_VAR_50;
};
long int isAlphaNumeric(char s){
if (isLetter(s)) {
long int ____BAH_COMPILER_VAR_51 = 1;
return ____BAH_COMPILER_VAR_51;
}
if (isNumber(s)) {
long int ____BAH_COMPILER_VAR_52 = 1;
return ____BAH_COMPILER_VAR_52;
}
long int ____BAH_COMPILER_VAR_53 = 0;
return ____BAH_COMPILER_VAR_53;
};
long int isSpace(char c){
if ((c==(char)32)) {
long int ____BAH_COMPILER_VAR_54 = 1;
return ____BAH_COMPILER_VAR_54;
}
if ((c==(char)9)) {
long int ____BAH_COMPILER_VAR_55 = 1;
return ____BAH_COMPILER_VAR_55;
}
if ((c==(char)10)) {
long int ____BAH_COMPILER_VAR_56 = 1;
return ____BAH_COMPILER_VAR_56;
}
if ((c==(char)11)) {
long int ____BAH_COMPILER_VAR_57 = 1;
return ____BAH_COMPILER_VAR_57;
}
if ((c==(char)13)) {
long int ____BAH_COMPILER_VAR_58 = 1;
return ____BAH_COMPILER_VAR_58;
}
long int ____BAH_COMPILER_VAR_59 = 0;
return ____BAH_COMPILER_VAR_59;
};
char * arrAsStr(__BAH_ARR_TYPE_char arr);
void println(char * s);
struct string {
char * content;
long int length;
void(*set)(struct string* this,char * s);
void(*append)(struct string* this,char * s);
void(*prepend)(struct string* this,char * s);
char(*charAt)(struct string* this,long int i);
long int(*compare)(struct string* this,char * s);
char *(*str)(struct string* this);
void(*replace)(struct string* this,char * nd,char * rl);
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
this->content =  (char *)memoryAlloc(this->length + 1);
strncpy(this->content,s,this->length);
};
void string__append(struct string* this,char * s){
long int sl =  strlen(s);
long int nl =  sl + this->length;
void * nc =  memoryRealloc(this->content,nl + 1);
if ((nc==null)) {
__BAH_panic("Error appending to string, possibly due to memory shortage.","/opt/bah/string.bah:133");
}
this->content =  nc;
strCatOffset(this->content,this->length,s,sl);
this->length =  nl;
};
void string__prepend(struct string* this,char * s){
long int sl =  strlen(s);
long int nl =  this->length + sl;
char * tmpS =  this->content;
void * nc =  memoryAlloc(nl + 1);
if ((nc==null)) {
__BAH_panic("Error appending to string, possibly due to memory shortage.","/opt/bah/string.bah:147");
}
this->content =  nc;
strncpy(this->content,s,sl);
strCatOffset(this->content,sl,tmpS,this->length);
destroy(tmpS);
this->length =  nl;
};
char string__charAt(struct string* this,long int i){
char c =  (char)0;
if ((i<this->length)) {
noCheck( c = this -> content [ i ] );
char ____BAH_COMPILER_VAR_60 = c;
return ____BAH_COMPILER_VAR_60;
}
char ____BAH_COMPILER_VAR_61 = c;
return ____BAH_COMPILER_VAR_61;
};
long int string__compare(struct string* this,char * s){
long int r =  strcmp(this->content,s);
if ((r==0)) {
long int ____BAH_COMPILER_VAR_62 = 1;
return ____BAH_COMPILER_VAR_62;
}
long int ____BAH_COMPILER_VAR_63 = 0;
return ____BAH_COMPILER_VAR_63;
};
char * string__str(struct string* this){
char * s =  this->content;
char * ____BAH_COMPILER_VAR_64 = s;
return ____BAH_COMPILER_VAR_64;
};
void string__replace(struct string* this,char * nd,char * rl){
struct string ____BAH_COMPILER_VAR_65 = {};
____BAH_COMPILER_VAR_65.content= null;
____BAH_COMPILER_VAR_65.set = string__set;
____BAH_COMPILER_VAR_65.append = string__append;
____BAH_COMPILER_VAR_65.prepend = string__prepend;
____BAH_COMPILER_VAR_65.charAt = string__charAt;
____BAH_COMPILER_VAR_65.compare = string__compare;
____BAH_COMPILER_VAR_65.str = string__str;
____BAH_COMPILER_VAR_65.replace = string__replace;
struct string needle =  ____BAH_COMPILER_VAR_65;
needle.set((struct string*)&needle,nd);
struct string ____BAH_COMPILER_VAR_66 = {};
____BAH_COMPILER_VAR_66.content= null;
____BAH_COMPILER_VAR_66.set = string__set;
____BAH_COMPILER_VAR_66.append = string__append;
____BAH_COMPILER_VAR_66.prepend = string__prepend;
____BAH_COMPILER_VAR_66.charAt = string__charAt;
____BAH_COMPILER_VAR_66.compare = string__compare;
____BAH_COMPILER_VAR_66.str = string__str;
____BAH_COMPILER_VAR_66.replace = string__replace;
struct string repl =  ____BAH_COMPILER_VAR_66;
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
char * ____BAH_COMPILER_VAR_67 =arrAsStr(replbuffStr);char * ____BAH_COMPILER_VAR_68 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(r);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_67);
;                            
                        ____BAH_COMPILER_VAR_68 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_68+currStrOff, r, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_68+currStrOff, ____BAH_COMPILER_VAR_67, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    r =  ____BAH_COMPILER_VAR_68;
}
if (((void *)r!=null)) {
this->set((struct string*)this,r);
}
};
long int string__count(struct string* this,char * need){
long int i =  0;
long int count =  0;
struct string ____BAH_COMPILER_VAR_69 = {};
____BAH_COMPILER_VAR_69.content= null;
____BAH_COMPILER_VAR_69.set = string__set;
____BAH_COMPILER_VAR_69.append = string__append;
____BAH_COMPILER_VAR_69.prepend = string__prepend;
____BAH_COMPILER_VAR_69.charAt = string__charAt;
____BAH_COMPILER_VAR_69.compare = string__compare;
____BAH_COMPILER_VAR_69.str = string__str;
____BAH_COMPILER_VAR_69.replace = string__replace;
____BAH_COMPILER_VAR_69.count = string__count;
struct string needle =  ____BAH_COMPILER_VAR_69;
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
long int ____BAH_COMPILER_VAR_70 = count;
return ____BAH_COMPILER_VAR_70;
};
long int string__hasPrefix(struct string* this,char * need){
long int i =  0;
long int nl =  strlen(need);
if ((this->length<nl)) {
long int ____BAH_COMPILER_VAR_71 = 0;
return ____BAH_COMPILER_VAR_71;
}
while ((i<nl)) {
char c =  this->charAt((struct string*)this,i);
char sc =  cpstringCharAt(need,i);
if ((c!=sc)) {
long int ____BAH_COMPILER_VAR_72 = 0;
return ____BAH_COMPILER_VAR_72;
}
i =  i + 1;
};
long int ____BAH_COMPILER_VAR_73 = 1;
return ____BAH_COMPILER_VAR_73;
};
long int string__hasSuffix(struct string* this,char * need){
long int nl =  strlen(need);
if ((this->length<nl)) {
long int ____BAH_COMPILER_VAR_74 = 0;
return ____BAH_COMPILER_VAR_74;
}
long int i =  this->length - nl;
long int needleIndex =  0;
while ((i<this->length)) {
char c =  this->charAt((struct string*)this,i);
char sc =  cpstringCharAt(need,needleIndex);
if ((c!=sc)) {
long int ____BAH_COMPILER_VAR_75 = 0;
return ____BAH_COMPILER_VAR_75;
}
needleIndex =  needleIndex + 1;
i =  i + 1;
};
long int ____BAH_COMPILER_VAR_76 = 1;
return ____BAH_COMPILER_VAR_76;
};
void string__trim(struct string* this){
if ((this->length==0)) {
return;
}
char fc =  this->charAt((struct string*)this,0);
if ((isSpace(fc)==0)) {
return;
}
long int i =  0;
while ((i<this->length)) {
char c =  this->charAt((struct string*)this,i);
if ((isSpace(c)==0)) {
break;
}
i =  i + 1;
};
if ((i>0)) {
this->length =  this->length - i;
char * tmpS =  memoryAlloc(this->length + 1);
memcpy(tmpS,noCheck( this->content + i ),this->length + 1);
this->content =  tmpS;
}
};
void string__trimLeft(struct string* this,long int s){
long int nSize =  this->length - s;
void * tmpS =  memoryAlloc(nSize);
memcpy(tmpS,noCheck( this->content + s ),nSize);
this->content =  tmpS;
this->length =  nSize;
};
void string__trimRight(struct string* this,long int s){
long int nSize =  this->length - s;
void * tmpS =  memoryAlloc(nSize);
memcpy(tmpS,this->content,nSize);
this->content =  tmpS;
this->length =  nSize;
};
struct string string__add(struct string* this,struct string s2){
struct string ____BAH_COMPILER_VAR_79 = {};
____BAH_COMPILER_VAR_79.content= null;
____BAH_COMPILER_VAR_79.set = string__set;
____BAH_COMPILER_VAR_79.append = string__append;
____BAH_COMPILER_VAR_79.prepend = string__prepend;
____BAH_COMPILER_VAR_79.charAt = string__charAt;
____BAH_COMPILER_VAR_79.compare = string__compare;
____BAH_COMPILER_VAR_79.str = string__str;
____BAH_COMPILER_VAR_79.replace = string__replace;
____BAH_COMPILER_VAR_79.count = string__count;
____BAH_COMPILER_VAR_79.hasPrefix = string__hasPrefix;
____BAH_COMPILER_VAR_79.hasSuffix = string__hasSuffix;
____BAH_COMPILER_VAR_79.trim = string__trim;
____BAH_COMPILER_VAR_79.trimLeft = string__trimLeft;
____BAH_COMPILER_VAR_79.trimRight = string__trimRight;
____BAH_COMPILER_VAR_79.add = string__add;
struct string r =  ____BAH_COMPILER_VAR_79;
r.length =  this->length + s2.length;
r.content =  memoryAlloc(r.length + 1);
strncpy(r.content,this->content,this->length);
strCatOffset(r.content,this->length,s2.content,s2.length);
struct string ____BAH_COMPILER_VAR_80 = r;
return ____BAH_COMPILER_VAR_80;
};
struct string string(char * s){
struct string ____BAH_COMPILER_VAR_81 = {};
____BAH_COMPILER_VAR_81.content= null;
____BAH_COMPILER_VAR_81.set = string__set;
____BAH_COMPILER_VAR_81.append = string__append;
____BAH_COMPILER_VAR_81.prepend = string__prepend;
____BAH_COMPILER_VAR_81.charAt = string__charAt;
____BAH_COMPILER_VAR_81.compare = string__compare;
____BAH_COMPILER_VAR_81.str = string__str;
____BAH_COMPILER_VAR_81.replace = string__replace;
____BAH_COMPILER_VAR_81.count = string__count;
____BAH_COMPILER_VAR_81.hasPrefix = string__hasPrefix;
____BAH_COMPILER_VAR_81.hasSuffix = string__hasSuffix;
____BAH_COMPILER_VAR_81.trim = string__trim;
____BAH_COMPILER_VAR_81.trimLeft = string__trimLeft;
____BAH_COMPILER_VAR_81.trimRight = string__trimRight;
____BAH_COMPILER_VAR_81.add = string__add;
struct string a =  ____BAH_COMPILER_VAR_81;
a.set((struct string*)&a,s);
struct string ____BAH_COMPILER_VAR_82 = a;
return ____BAH_COMPILER_VAR_82;
};
char * arrToStr(__BAH_ARR_TYPE_char arr){
long int strLen =  len(arr);
char * str =  memoryAlloc(strLen + 1);
noCheck( memcpy ( str , arr -> data , strLen ) );
char * ____BAH_COMPILER_VAR_83 = str;
return ____BAH_COMPILER_VAR_83;
};
__BAH_ARR_TYPE_char strToArr(char * str){
long int strLen =  strlen(str);
array(char)* arr = memoryAlloc(sizeof(array(char)));

arr->length = 0;
arr->elemSize = sizeof(char);
noCheck( arr -> data = memoryAlloc ( strLen + 1 ) );
noCheck( memcpy ( arr -> data , str , strLen ) );
noCheck( arr -> length = strLen );
array(char)* ____BAH_COMPILER_VAR_84 = arr;
return ____BAH_COMPILER_VAR_84;
};
char * arrAsStr(__BAH_ARR_TYPE_char arr){
char * ____BAH_COMPILER_VAR_85 = noCheck( arr -> data );
return ____BAH_COMPILER_VAR_85;
};
__BAH_ARR_TYPE_char strAsArr(char * str){
long int l =  strlen(str);
array(char)* arr = memoryAlloc(sizeof(array(char)));

arr->length = 0;
arr->elemSize = sizeof(char);
noCheck( arr -> length = l );
noCheck( arr -> data = str );
array(char)* ____BAH_COMPILER_VAR_86 = arr;
return ____BAH_COMPILER_VAR_86;
};
char * intToStr(long int i){
if ((i==0)) {
char * ____BAH_COMPILER_VAR_87 = "0";
return ____BAH_COMPILER_VAR_87;
}
array(char)* s = memoryAlloc(sizeof(array(char)));

s->length = 0;
s->elemSize = sizeof(char);
int subZero =  (i<0);
if ((subZero==true)) {
i =  0 - i;
}
for (; (i!=0); i =  i / 10) {
long int conv =  i % 10;
conv =  conv + 48;

{
long nLength = len(s);
if (s->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(s->data, (nLength+50)*sizeof(char));
s->data = newPtr;
}
s->data[len(s)] =  (char)conv;
s->length = nLength+1;
} else {
s->data[len(s)] =  (char)conv;
}
};
};
if ((subZero==true)) {

{
long nLength = len(s);
if (s->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(s->data, (nLength+50)*sizeof(char));
s->data = newPtr;
}
s->data[len(s)] =  45;
s->length = nLength+1;
} else {
s->data[len(s)] =  45;
}
};
}
long int ls =  len(s);
i =  0;
for (; (i<ls / 2); i =  i+1) {
long int ii =  ls - i-1;

                if (s->length <= i) {
                    printf("array (/opt/bah/string.bah:442): s[%d] with length %d\n", i, s->length);
                    exit(1);
                };
                char osi =  s->data[i];

                if (s->length <= ii) {
                    printf("array (/opt/bah/string.bah:443): s[%d] with length %d\n", ii, s->length);
                    exit(1);
                };
                
{
long nLength = i;
if (s->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(s->data, (nLength+50)*sizeof(char));
s->data = newPtr;
}
s->data[i] =  s->data[ii];
s->length = nLength+1;
} else {
s->data[i] =  s->data[ii];
}
};

{
long nLength = ii;
if (s->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(s->data, (nLength+50)*sizeof(char));
s->data = newPtr;
}
s->data[ii] =  osi;
s->length = nLength+1;
} else {
s->data[ii] =  osi;
}
};
};

{
long nLength = len(s);
if (s->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(s->data, (nLength+50)*sizeof(char));
s->data = newPtr;
}
s->data[len(s)] =  (char)0;
s->length = nLength+1;
} else {
s->data[len(s)] =  (char)0;
}
};
char * ____BAH_COMPILER_VAR_88 = arrAsStr(s);
return ____BAH_COMPILER_VAR_88;
};
struct string intToString(long int i){
char * ____BAH_COMPILER_VAR_89 =intToStr(i);struct string r =  string(____BAH_COMPILER_VAR_89);
struct string ____BAH_COMPILER_VAR_90 = r;
return ____BAH_COMPILER_VAR_90;
};
char * floatToStr(double f){
char * buff =  memoryAlloc(50);
sprintf(buff,"%lf",f);
char * ____BAH_COMPILER_VAR_91 = buff;
return ____BAH_COMPILER_VAR_91;
};
long int strToInt(char * s){
long int ____BAH_COMPILER_VAR_92 = atol(s);
return ____BAH_COMPILER_VAR_92;
};
double strToFloat(char * s){
double ____BAH_COMPILER_VAR_93 = strtod(s,null);
return ____BAH_COMPILER_VAR_93;
};
long int stringToInt(struct string s){
long int i =  atol(s.content);
long int ____BAH_COMPILER_VAR_94 = i;
return ____BAH_COMPILER_VAR_94;
};
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
char * ____BAH_COMPILER_VAR_95 =charToString(c);replcBuff.append((struct string*)&replcBuff,____BAH_COMPILER_VAR_95);
}
else {
if ((sepIndex>0)) {
sepIndex =  0;
char * ____BAH_COMPILER_VAR_96 =charToString(c);replcBuff.append((struct string*)&replcBuff,____BAH_COMPILER_VAR_96);
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
struct string* ____BAH_COMPILER_VAR_97 = memoryAlloc(sizeof(struct string));
____BAH_COMPILER_VAR_97->content= null;
____BAH_COMPILER_VAR_97->set = string__set;
____BAH_COMPILER_VAR_97->append = string__append;
____BAH_COMPILER_VAR_97->prepend = string__prepend;
____BAH_COMPILER_VAR_97->charAt = string__charAt;
____BAH_COMPILER_VAR_97->compare = string__compare;
____BAH_COMPILER_VAR_97->str = string__str;
____BAH_COMPILER_VAR_97->replace = string__replace;
____BAH_COMPILER_VAR_97->count = string__count;
____BAH_COMPILER_VAR_97->hasPrefix = string__hasPrefix;
____BAH_COMPILER_VAR_97->hasSuffix = string__hasSuffix;
____BAH_COMPILER_VAR_97->trim = string__trim;
____BAH_COMPILER_VAR_97->trimLeft = string__trimLeft;
____BAH_COMPILER_VAR_97->trimRight = string__trimRight;
____BAH_COMPILER_VAR_97->add = string__add;
struct string* elem =  ____BAH_COMPILER_VAR_97;
char * ____BAH_COMPILER_VAR_98 =arrToStr(tmpString);elem->set((struct string*)elem,____BAH_COMPILER_VAR_98);
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
struct string* ____BAH_COMPILER_VAR_99 = memoryAlloc(sizeof(struct string));
____BAH_COMPILER_VAR_99->content= null;
____BAH_COMPILER_VAR_99->set = string__set;
____BAH_COMPILER_VAR_99->append = string__append;
____BAH_COMPILER_VAR_99->prepend = string__prepend;
____BAH_COMPILER_VAR_99->charAt = string__charAt;
____BAH_COMPILER_VAR_99->compare = string__compare;
____BAH_COMPILER_VAR_99->str = string__str;
____BAH_COMPILER_VAR_99->replace = string__replace;
____BAH_COMPILER_VAR_99->count = string__count;
____BAH_COMPILER_VAR_99->hasPrefix = string__hasPrefix;
____BAH_COMPILER_VAR_99->hasSuffix = string__hasSuffix;
____BAH_COMPILER_VAR_99->trim = string__trim;
____BAH_COMPILER_VAR_99->trimLeft = string__trimLeft;
____BAH_COMPILER_VAR_99->trimRight = string__trimRight;
____BAH_COMPILER_VAR_99->add = string__add;
struct string* elem =  ____BAH_COMPILER_VAR_99;
char * ____BAH_COMPILER_VAR_100 =arrToStr(tmpString);elem->set((struct string*)elem,____BAH_COMPILER_VAR_100);
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
array(struct string)* ____BAH_COMPILER_VAR_101 = res;
return ____BAH_COMPILER_VAR_101;
};
struct string joinString(__BAH_ARR_TYPE_string a,char * sep){
long int i =  0;
struct string s =  string("");
long int max =  len(a) - 1;
while ((i<len(a))) {

                if (a->length <= i) {
                    printf("array (/opt/bah/string.bah:555): a[%d] with length %d\n", i, a->length);
                    exit(1);
                };
                struct string e =  a->data[i];
if ((e.length==0)) {
i =  i + 1;
continue;
}
char * ____BAH_COMPILER_VAR_102 =e.str((struct string*)&e);struct string tmpS =  string(____BAH_COMPILER_VAR_102);
if ((i!=max)) {
tmpS.append((struct string*)&tmpS,sep);
}
char * ____BAH_COMPILER_VAR_103 =tmpS.str((struct string*)&tmpS);s.append((struct string*)&s,____BAH_COMPILER_VAR_103);
i =  i + 1;
};
struct string ____BAH_COMPILER_VAR_104 = s;
return ____BAH_COMPILER_VAR_104;
};
char * splitStringBefore(struct string s,char * sp){
struct string sep =  string(sp);
if ((sep.length>=s.length)) {
char * ____BAH_COMPILER_VAR_105 = "";
return ____BAH_COMPILER_VAR_105;
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
char * ____BAH_COMPILER_VAR_106 = s.str((struct string*)&s);
return ____BAH_COMPILER_VAR_106;
}
}
else {
foundIndex =  0;
sepIndex =  0;
}
i =  i + 1;
};
char * ____BAH_COMPILER_VAR_107 = "";
return ____BAH_COMPILER_VAR_107;
};
struct string toLower(struct string s){
array(char)* ns = memoryAlloc(sizeof(array(char)));

ns->length = 0;
ns->elemSize = sizeof(char);
long int i =  0;
while ((i<s.length)) {
char c =  s.charAt((struct string*)&s,i);
if (isUpper(c)) {
c =  c + (char)32;
}

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
i =  i + 1;
};
char * ____BAH_COMPILER_VAR_108 =arrToStr(ns);struct string ____BAH_COMPILER_VAR_109 = string(____BAH_COMPILER_VAR_108);
return ____BAH_COMPILER_VAR_109;
};
int strHasPrefix(char * s,char * need){
long int i =  0;
long int nl =  strlen(need);
long int sl =  strlen(s);
if ((sl<nl)) {
int ____BAH_COMPILER_VAR_110 = false;
return ____BAH_COMPILER_VAR_110;
}
while ((i<nl)) {
if ((cpstringCharAt(s,i)!=cpstringCharAt(need,i))) {
int ____BAH_COMPILER_VAR_111 = false;
return ____BAH_COMPILER_VAR_111;
}
i =  i + 1;
};
int ____BAH_COMPILER_VAR_112 = true;
return ____BAH_COMPILER_VAR_112;
};
int strHasSuffix(char * s,char * need){
long int sl =  strlen(s);
long int nl =  strlen(need);
if ((nl>sl)) {
int ____BAH_COMPILER_VAR_113 = false;
return ____BAH_COMPILER_VAR_113;
}
long int i =  sl - nl;
while ((i<sl)) {
if ((cpstringCharAt(s,i)!=cpstringCharAt(need,i))) {
int ____BAH_COMPILER_VAR_114 = false;
return ____BAH_COMPILER_VAR_114;
}
i =  i + 1;
};
int ____BAH_COMPILER_VAR_115 = true;
return ____BAH_COMPILER_VAR_115;
};
void strTrimLeft(char ** s,long int i){
long int ls =  strlen(*s);
char * ns =  memoryAlloc(ls - i + 1);
memcpy(ns,noCheck( *s + i ),ls - i);
*s =  ns;
};
void strTrimRight(char ** s,long int i){
long int ls =  strlen(*s);
char * ns =  memoryAlloc(ls - i + 1);
memcpy(ns,*s,ls - i);
*s =  ns;
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
*s =  noCheck( *s + i );
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
long int ____BAH_COMPILER_VAR_116 = count;
return ____BAH_COMPILER_VAR_116;
};
char * stdinput(){
char * buffer =  memoryAlloc(1025);
struct string response =  string("");
long int nDataLength =  read((void *)0,buffer,1024);
if ((nDataLength<1024)) {
response.append((struct string*)&response,buffer);
}
else {
while ((nDataLength>0)) {
response.append((struct string*)&response,buffer);
if ((nDataLength<1024)) {
long int trimAmm =  1024 - nDataLength;
response.trimRight((struct string*)&response,trimAmm);
break;
}
else {
nDataLength =  read((void *)0,buffer,1024);
}
};
}
response.trimRight((struct string*)&response,1);
char * ____BAH_COMPILER_VAR_117 = response.str((struct string*)&response);
return ____BAH_COMPILER_VAR_117;
};
void println(char * s){
char * ____BAH_COMPILER_VAR_118 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen("\n");
;                            
                        ____BAH_COMPILER_VAR_118 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_118+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_118+currStrOff, "\n", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    write((void *)1,____BAH_COMPILER_VAR_118,strlen(s) + 1);
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
long int ____BAH_COMPILER_VAR_119 = 0;
return ____BAH_COMPILER_VAR_119;
}
long int ____BAH_COMPILER_VAR_120 = 1;
return ____BAH_COMPILER_VAR_120;
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
long int ____BAH_COMPILER_VAR_122 = 0;
return ____BAH_COMPILER_VAR_122;
}
long int ____BAH_COMPILER_VAR_123 = ftell(this->handle);
return ____BAH_COMPILER_VAR_123;
};
void fileStream__setPos(struct fileStream* this,long int i){
if ((this->isValid((struct fileStream*)this)==0)) {
return;
}
fseek(this->handle,i,0);
};
long int fileStream__getSize(struct fileStream* this){
if ((this->isValid((struct fileStream*)this)==0)) {
long int ____BAH_COMPILER_VAR_125 = -1;
return ____BAH_COMPILER_VAR_125;
}
long int oldPos =  this->getPos((struct fileStream*)this);
fseek(this->handle,0,2);
long int size =  ftell(this->handle);
this->setPos((struct fileStream*)this,oldPos);
long int ____BAH_COMPILER_VAR_126 = size;
return ____BAH_COMPILER_VAR_126;
};
void fileStream__rewind(struct fileStream* this){
rewind(this->handle);
};
char fileStream__getChar(struct fileStream* this){
char c =  getc(this->handle);
char ____BAH_COMPILER_VAR_127 = c;
return ____BAH_COMPILER_VAR_127;
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
long int ____BAH_COMPILER_VAR_128 = -1;
return ____BAH_COMPILER_VAR_128;
}
fputs(content,this->handle);
long int ____BAH_COMPILER_VAR_129 = 1;
return ____BAH_COMPILER_VAR_129;
};
void fileStream__writePtr(struct fileStream* this,void * a,long int s){
fwrite(a,s,1,this->handle);
};
long int fileStream__readPtr(struct fileStream* this,void * a,long int s){
long int ____BAH_COMPILER_VAR_130 = fread(a,s,1,this->handle);
return ____BAH_COMPILER_VAR_130;
};
char * fileStream__readContent(struct fileStream* this){
if ((this->isValid((struct fileStream*)this)==0)) {
char * ____BAH_COMPILER_VAR_131 = "invalid";
return ____BAH_COMPILER_VAR_131;
}
long int sz =  this->getSize((struct fileStream*)this);
char * r =  memoryAlloc(sz + 1);
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
char * ____BAH_COMPILER_VAR_132 = r;
return ____BAH_COMPILER_VAR_132;
};
__BAH_ARR_TYPE_char fileStream__readBytes(struct fileStream* this){
array(char)* r = memoryAlloc(sizeof(array(char)));

r->length = 0;
r->elemSize = sizeof(char);
allocateArray(r,this->getSize((struct fileStream*)this));
this->readPtr((struct fileStream*)this,noCheck( r -> data ),len(r));
array(char)* ____BAH_COMPILER_VAR_133 = r;
return ____BAH_COMPILER_VAR_133;
};
void fileStream__writeBytes(struct fileStream* this,__BAH_ARR_TYPE_char d){
this->writePtr((struct fileStream*)this,noCheck( d -> data ),len(d));
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
struct fileStream ____BAH_COMPILER_VAR_134 = {};
____BAH_COMPILER_VAR_134.handle= null;
____BAH_COMPILER_VAR_134.isValid = fileStream__isValid;
____BAH_COMPILER_VAR_134.open = fileStream__open;
____BAH_COMPILER_VAR_134.close = fileStream__close;
____BAH_COMPILER_VAR_134.getPos = fileStream__getPos;
____BAH_COMPILER_VAR_134.setPos = fileStream__setPos;
____BAH_COMPILER_VAR_134.getSize = fileStream__getSize;
____BAH_COMPILER_VAR_134.rewind = fileStream__rewind;
____BAH_COMPILER_VAR_134.getChar = fileStream__getChar;
____BAH_COMPILER_VAR_134.setChar = fileStream__setChar;
____BAH_COMPILER_VAR_134.createFile = fileStream__createFile;
____BAH_COMPILER_VAR_134.writeFile = fileStream__writeFile;
____BAH_COMPILER_VAR_134.writePtr = fileStream__writePtr;
____BAH_COMPILER_VAR_134.readPtr = fileStream__readPtr;
____BAH_COMPILER_VAR_134.readContent = fileStream__readContent;
____BAH_COMPILER_VAR_134.readBytes = fileStream__readBytes;
____BAH_COMPILER_VAR_134.writeBytes = fileStream__writeBytes;
struct fileStream fs =  ____BAH_COMPILER_VAR_134;
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
char * ____BAH_COMPILER_VAR_135 = file;
return ____BAH_COMPILER_VAR_135;
};
long int fileMap__isValid(struct fileMap* this){
if ((this->handle<0)) {
long int ____BAH_COMPILER_VAR_136 = 0;
return ____BAH_COMPILER_VAR_136;
}
long int ____BAH_COMPILER_VAR_137 = 1;
return ____BAH_COMPILER_VAR_137;
};
void fileMap__close(struct fileMap* this){
};
__BAH_ARR_TYPE_cpstring listFiles(char * dir){
array(char *)* files = memoryAlloc(sizeof(array(char *)));

files->length = 0;
files->elemSize = sizeof(char *);
DIR* d =  opendir(dir);
struct dirent* file =  readdir(d);
while ((file!=null)) {
long int lf =  len(files);
if ((strcmp(file->d_name,".")==0)) {
file =  readdir(d);
continue;
}
if ((strcmp(file->d_name,"..")==0)) {
file =  readdir(d);
continue;
}

{
long nLength = lf;
if (files->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(files->data, (nLength+50)*sizeof(char *));
files->data = newPtr;
}
files->data[lf] =  __STR(file->d_name);
files->length = nLength+1;
} else {
files->data[lf] =  __STR(file->d_name);
}
};
file =  readdir(d);
};
closedir(d);
array(char *)* ____BAH_COMPILER_VAR_138 = files;
return ____BAH_COMPILER_VAR_138;
};
long int fileExists(char * path){
long int is =  access(path,0);
if ((is==0)) {
long int ____BAH_COMPILER_VAR_139 = 1;
return ____BAH_COMPILER_VAR_139;
}
long int ____BAH_COMPILER_VAR_140 = 0;
return ____BAH_COMPILER_VAR_140;
};
int removeFile(char * name){
if ((remove(name)==0)) {
int ____BAH_COMPILER_VAR_141 = true;
return ____BAH_COMPILER_VAR_141;
}
int ____BAH_COMPILER_VAR_142 = false;
return ____BAH_COMPILER_VAR_142;
};
long int getLastModified(char * name){
struct stat attr;
stat(name,&attr);
long int ____BAH_COMPILER_VAR_143 = attr.st_ctime;
return ____BAH_COMPILER_VAR_143;
};
long int __windows_mkdir(char * s,long int m){
long int ____BAH_COMPILER_VAR_144 = noCheck( mkdir ( s ) );
return ____BAH_COMPILER_VAR_144;
};
#define mkdir __windows_mkdir
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
struct flag* ____BAH_COMPILER_VAR_145 = memoryAlloc(sizeof(struct flag));
____BAH_COMPILER_VAR_145->name= null;
____BAH_COMPILER_VAR_145->help= null;
____BAH_COMPILER_VAR_145->content= null;
struct flag* f =  ____BAH_COMPILER_VAR_145;
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
struct flag* ____BAH_COMPILER_VAR_146 = memoryAlloc(sizeof(struct flag));
____BAH_COMPILER_VAR_146->name= null;
____BAH_COMPILER_VAR_146->help= null;
____BAH_COMPILER_VAR_146->content= null;
struct flag* f =  ____BAH_COMPILER_VAR_146;
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
struct flag* ____BAH_COMPILER_VAR_147 = memoryAlloc(sizeof(struct flag));
____BAH_COMPILER_VAR_147->name= null;
____BAH_COMPILER_VAR_147->help= null;
____BAH_COMPILER_VAR_147->content= null;
struct flag* f =  ____BAH_COMPILER_VAR_147;
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
struct flag* ____BAH_COMPILER_VAR_148 = memoryAlloc(sizeof(struct flag));
____BAH_COMPILER_VAR_148->name= null;
____BAH_COMPILER_VAR_148->help= null;
____BAH_COMPILER_VAR_148->content= null;
struct flag* f =  ____BAH_COMPILER_VAR_148;
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
struct flag* ____BAH_COMPILER_VAR_149 = flag;
return ____BAH_COMPILER_VAR_149;
}
i =  i + 1;
};
struct flag* ____BAH_COMPILER_VAR_150 = memoryAlloc(sizeof(struct flag));
____BAH_COMPILER_VAR_150->name= null;
____BAH_COMPILER_VAR_150->help= null;
____BAH_COMPILER_VAR_150->content= null;
struct flag* z =  ____BAH_COMPILER_VAR_150;
z->isSet =  0;
struct flag* ____BAH_COMPILER_VAR_151 = z;
return ____BAH_COMPILER_VAR_151;
};
char * flags__get(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_152 =string(name);struct flag* flag =  this->getFlag((struct flags*)this,____BAH_COMPILER_VAR_152);
char * ctn =  flag->content;
char * ____BAH_COMPILER_VAR_153 = ctn;
return ____BAH_COMPILER_VAR_153;
};
long int flags__getInt(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_154 =string(name);struct flag* flag =  this->getFlag((struct flags*)this,____BAH_COMPILER_VAR_154);
if ((flag->type!=FLAG_TYPE_INT)) {
char * ____BAH_COMPILER_VAR_155 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Flag '");
long int strLen_1 = strlen(flag->name);
long int strLen_2 = strlen("' is not int.");
;                            
                        ____BAH_COMPILER_VAR_155 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_155+currStrOff, "Flag '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_155+currStrOff, flag->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_155+currStrOff, "' is not int.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    char * error =  ____BAH_COMPILER_VAR_155;
__BAH_panic(error,"/opt/bah/flags.bah:124");
}
long int ctn =  flag->cont_int;
long int ____BAH_COMPILER_VAR_156 = ctn;
return ____BAH_COMPILER_VAR_156;
};
double flags__getFloat(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_157 =string(name);struct flag* flag =  this->getFlag((struct flags*)this,____BAH_COMPILER_VAR_157);
if ((flag->type!=FLAG_TYPE_FLOAT)) {
char * ____BAH_COMPILER_VAR_158 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Flag '");
long int strLen_1 = strlen(flag->name);
long int strLen_2 = strlen("' is not float.");
;                            
                        ____BAH_COMPILER_VAR_158 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_158+currStrOff, "Flag '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_158+currStrOff, flag->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_158+currStrOff, "' is not float.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    char * error =  ____BAH_COMPILER_VAR_158;
__BAH_panic(error,"/opt/bah/flags.bah:136");
}
double ctn =  flag->cont_float;
double ____BAH_COMPILER_VAR_159 = ctn;
return ____BAH_COMPILER_VAR_159;
};
long int flags__isSet(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_160 =string(name);struct flag* flag =  this->getFlag((struct flags*)this,____BAH_COMPILER_VAR_160);
long int ctn =  flag->isSet;
long int ____BAH_COMPILER_VAR_161 = ctn;
return ____BAH_COMPILER_VAR_161;
};
void flags__parse(struct flags* this,__BAH_ARR_TYPE_cpstring args){
struct flag* currentFlag= null;
int isVal =  false;
this->args =  args;
long int i =  1;
while ((i<len(args))) {
struct string argName =  string(args->data[i]);
if ((isVal==true)) {
currentFlag->content =  argName.str((struct string*)&argName);
if ((currentFlag->type==FLAG_TYPE_INT)) {
char * ____BAH_COMPILER_VAR_162 =argName.str((struct string*)&argName);currentFlag->cont_int =  atoi(____BAH_COMPILER_VAR_162);
}
else if ((currentFlag->type==FLAG_TYPE_FLOAT)) {
char * ____BAH_COMPILER_VAR_163 =argName.str((struct string*)&argName);currentFlag->cont_float =  strtod(____BAH_COMPILER_VAR_163,0);
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
char * ____BAH_COMPILER_VAR_164 = date;
return ____BAH_COMPILER_VAR_164;
};
long int time__since(struct time* this){
long int nt =  time(0);
long int r =  nt - this->timestamp;
long int ____BAH_COMPILER_VAR_165 = r;
return ____BAH_COMPILER_VAR_165;
};
long int getTimeUnix(){
struct timespec ____BAH_COMPILER_VAR_166 = {};
struct timespec ts =  ____BAH_COMPILER_VAR_166;
long int s =  clock_gettime(noCheck( CLOCK_REALTIME ),&ts);
s =  ts.tv_sec * 1000000000 + ts.tv_nsec;
long int ____BAH_COMPILER_VAR_167 = s;
return ____BAH_COMPILER_VAR_167;
};
long int RAND_SEEDED;
void seedRandom(long int i){
srand(i);
RAND_SEEDED =  1;
};
long int randomInRange(long int min,long int max){
if ((RAND_SEEDED==0)) {
srand(time(0) + getTimeUnix());
RAND_SEEDED =  1;
}
long int range =  max - min;
long int i =  rand() % range + 1;
i =  i + min;
long int ____BAH_COMPILER_VAR_168 = i;
return ____BAH_COMPILER_VAR_168;
};
long int cryptoRand(){
HCRYPTPROV hp;
long int* buff =  memoryAlloc(SIZE_OF_INT);
CryptGenRandom(hp,1,buff);
long int i =  *buff;
long int ____BAH_COMPILER_VAR_169 = i;
return ____BAH_COMPILER_VAR_169;
};
struct command {
char * command;
int error;
long int status;
FILE* handle;
char *(*run)(struct command* this);
array(char)*(*runBytes)(struct command* this);
};
char * command__run(struct command* this){
char * cm =  this->command;
if ((this->error==false)) {
char * ____BAH_COMPILER_VAR_170 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(cm);
long int strLen_1 = strlen(" 2>/dev/null");
;                            
                        ____BAH_COMPILER_VAR_170 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_170+currStrOff, cm, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_170+currStrOff, " 2>/dev/null", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    cm =  ____BAH_COMPILER_VAR_170;
}
else {
char * ____BAH_COMPILER_VAR_171 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(cm);
long int strLen_1 = strlen(" 2>&1");
;                            
                        ____BAH_COMPILER_VAR_171 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_171+currStrOff, cm, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_171+currStrOff, " 2>&1", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    cm =  ____BAH_COMPILER_VAR_171;
}
this->handle =  popen(cm,"r");
if ((this->handle==null)) {
char * ____BAH_COMPILER_VAR_172 = "";
return ____BAH_COMPILER_VAR_172;
}
char * buff =  memoryAlloc(1025);
char * res =  "";
while (((void *)fgets(buff,1024,this->handle)!=null)) {
char * ____BAH_COMPILER_VAR_173 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(res);
long int strLen_1 = strlen(buff);
;                            
                        ____BAH_COMPILER_VAR_173 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_173+currStrOff, res, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_173+currStrOff, buff, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    res =  ____BAH_COMPILER_VAR_173;
};
this->status =  pclose(this->handle);
char * ____BAH_COMPILER_VAR_174 = res;
return ____BAH_COMPILER_VAR_174;
};
__BAH_ARR_TYPE_char command__runBytes(struct command* this){
array(char)* arr = memoryAlloc(sizeof(array(char)));

arr->length = 0;
arr->elemSize = sizeof(char);
char * cm =  this->command;
if ((this->error==false)) {
char * ____BAH_COMPILER_VAR_175 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(cm);
long int strLen_1 = strlen(" 2>/dev/null");
;                            
                        ____BAH_COMPILER_VAR_175 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_175+currStrOff, cm, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_175+currStrOff, " 2>/dev/null", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    cm =  ____BAH_COMPILER_VAR_175;
}
else {
char * ____BAH_COMPILER_VAR_176 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(cm);
long int strLen_1 = strlen(" 2>&1");
;                            
                        ____BAH_COMPILER_VAR_176 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_176+currStrOff, cm, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_176+currStrOff, " 2>&1", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    cm =  ____BAH_COMPILER_VAR_176;
}
this->handle =  popen(cm,"r");
if ((this->handle==null)) {
array(char)* ____BAH_COMPILER_VAR_177 = arr;
return ____BAH_COMPILER_VAR_177;
}
char * buffer =  memoryAlloc(1025);
struct string response =  string("");
long int total =  0;
long int fd =  fileno(this->handle);
long int nDataLength =  read((void *)fd,buffer,1024);
if ((nDataLength<1024)) {
total =  nDataLength;
response.append((struct string*)&response,buffer);
}
else {
while ((nDataLength>0)) {
total =  total + nDataLength;
response.append((struct string*)&response,buffer);
if ((nDataLength<1024)) {
long int trimAmm =  1024 - nDataLength;
response.trimRight((struct string*)&response,trimAmm);
break;
}
else {
nDataLength =  read((void *)fd,buffer,1024);
}
};
}
this->status =  pclose(this->handle);
noCheck( arr -> data = response.content );
noCheck( arr -> length = total );
array(char)* ____BAH_COMPILER_VAR_178 = arr;
return ____BAH_COMPILER_VAR_178;
};
struct command command(char * s){
struct command ____BAH_COMPILER_VAR_179 = {};
____BAH_COMPILER_VAR_179.command= null;
____BAH_COMPILER_VAR_179.error = true;
____BAH_COMPILER_VAR_179.status = 0;
____BAH_COMPILER_VAR_179.handle= null;
____BAH_COMPILER_VAR_179.run = command__run;
____BAH_COMPILER_VAR_179.runBytes = command__runBytes;
struct command cmd =  ____BAH_COMPILER_VAR_179;
cmd.command =  s;
struct command ____BAH_COMPILER_VAR_180 = cmd;
return ____BAH_COMPILER_VAR_180;
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
nArgs->data[0] =  s;
nArgs->length = nLength+1;
} else {
nArgs->data[0] =  s;
}
};
long int i =  0;
while ((i<len(args))) {

                if (args->length <= i) {
                    printf("array (/opt/bah/exec.bah:100): args[%d] with length %d\n", i, args->length);
                    exit(1);
                };
                
{
long nLength = i + 1;
if (nArgs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nArgs->data, (nLength+50)*sizeof(char *));
nArgs->data = newPtr;
}
nArgs->data[i + 1] =  args->data[i];
nArgs->length = nLength+1;
} else {
nArgs->data[i + 1] =  args->data[i];
}
};
i =  i + 1;
};

{
long nLength = i + 2;
if (nArgs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nArgs->data, (nLength+50)*sizeof(char *));
nArgs->data = newPtr;
}
nArgs->data[i + 2] =  (char *)0;
nArgs->length = nLength+1;
} else {
nArgs->data[i + 2] =  (char *)0;
}
};
noCheck( r = execvp ( s , nArgs -> data ) );
long int ____BAH_COMPILER_VAR_181 = r;
return ____BAH_COMPILER_VAR_181;
};
#define ROPE_LEAF_LEN 50
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
struct rope* ____BAH_COMPILER_VAR_182 = this;
return ____BAH_COMPILER_VAR_182;
}
struct rope* ____BAH_COMPILER_VAR_183 = this->parent->getParent((struct rope*)this->parent);
return ____BAH_COMPILER_VAR_183;
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
char * ____BAH_COMPILER_VAR_185 = this->str;
return ____BAH_COMPILER_VAR_185;
}
char * s =  memoryAlloc(this->totalLen + 1);
this->left->addStr((struct rope*)this->left,&s);
this->right->addStr((struct rope*)this->right,&s);
char * ____BAH_COMPILER_VAR_186 = s;
return ____BAH_COMPILER_VAR_186;
};
struct rope* rope__add(struct rope* this,struct rope* root2){
long int n1 =  this->len;
struct rope* ____BAH_COMPILER_VAR_187 = memoryAlloc(sizeof(struct rope));
____BAH_COMPILER_VAR_187->left= null;
____BAH_COMPILER_VAR_187->right= null;
____BAH_COMPILER_VAR_187->parent= null;
____BAH_COMPILER_VAR_187->str= null;
____BAH_COMPILER_VAR_187->getParent = rope__getParent;
____BAH_COMPILER_VAR_187->addStr = rope__addStr;
____BAH_COMPILER_VAR_187->toStr = rope__toStr;
____BAH_COMPILER_VAR_187->add = rope__add;
struct rope* tmp =  ____BAH_COMPILER_VAR_187;
tmp->parent =  null;
tmp->left =  this;
tmp->right =  root2;
root2->parent =  tmp;
this->parent =  root2->parent;
tmp->totalLen =  this->totalLen + root2->totalLen;
tmp->str =  null;
struct rope* ____BAH_COMPILER_VAR_188 = tmp;
return ____BAH_COMPILER_VAR_188;
};
struct rope* createRopeStructure(struct rope* par,char * a,long int l,long int r){
struct rope* ____BAH_COMPILER_VAR_189 = memoryAlloc(sizeof(struct rope));
____BAH_COMPILER_VAR_189->left= null;
____BAH_COMPILER_VAR_189->right= null;
____BAH_COMPILER_VAR_189->parent= null;
____BAH_COMPILER_VAR_189->str= null;
____BAH_COMPILER_VAR_189->getParent = rope__getParent;
____BAH_COMPILER_VAR_189->addStr = rope__addStr;
____BAH_COMPILER_VAR_189->toStr = rope__toStr;
____BAH_COMPILER_VAR_189->add = rope__add;
struct rope* tmp =  ____BAH_COMPILER_VAR_189;
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
char * arr =  memoryAlloc(ROPE_LEAF_LEN + 1);
while ((i<=r)) {
noCheck( arr [ j ] = a [ i ] );
j =  j + 1;
i =  i + 1;
};
tmp->str =  arr;
}
struct rope* ____BAH_COMPILER_VAR_190 = tmp;
return ____BAH_COMPILER_VAR_190;
};
struct rope* concatenateRopes(struct rope* root1,struct rope* root2){
long int n1 =  root1->len;
struct rope* ____BAH_COMPILER_VAR_191 = memoryAlloc(sizeof(struct rope));
____BAH_COMPILER_VAR_191->left= null;
____BAH_COMPILER_VAR_191->right= null;
____BAH_COMPILER_VAR_191->parent= null;
____BAH_COMPILER_VAR_191->str= null;
____BAH_COMPILER_VAR_191->getParent = rope__getParent;
____BAH_COMPILER_VAR_191->addStr = rope__addStr;
____BAH_COMPILER_VAR_191->toStr = rope__toStr;
____BAH_COMPILER_VAR_191->add = rope__add;
struct rope* tmp =  ____BAH_COMPILER_VAR_191;
tmp->parent =  null;
tmp->left =  root1;
tmp->right =  root2;
root2->parent =  tmp;
root1->parent =  root2->parent;
tmp->totalLen =  root1->totalLen + root2->totalLen;
tmp->str =  null;
struct rope* ____BAH_COMPILER_VAR_192 = tmp;
return ____BAH_COMPILER_VAR_192;
};
struct rope* rope(char * a){
long int n1 =  strlen(a);
struct rope* r =  createRopeStructure(null,a,0,n1-1);
r->totalLen =  n1;
r->len =  n1;
struct rope* ____BAH_COMPILER_VAR_193 = r;
return ____BAH_COMPILER_VAR_193;
};
char * BAH_DIR;
char * BAH_OS;
char * BAH_CC;
#define BAH_VERSION "v1.1 (build 56)"
int debug;
int verboseRuntime;
struct rope* OUTPUT;
char * NEXT_LINE;
struct rope* INIT;
struct variable {
char * name;
char * type;
int isConst;
char * constVal;
int isArray;
char * from;
int outterScope;
};
struct structMemb {
char * name;
char * type;
int isConst;
char * constVal;
int isArray;
char * from;
int outterScope;
char * def;
int isFn;
};
struct func {
char * name;
array(struct variable*)* args;
struct variable* returns;
int returned;
int isBinding;
char * from;
char * file;
long int line;
};
struct cStruct {
char * name;
array(struct structMemb*)* members;
array(struct func*)* methods;
char * postCode;
int print;
char * extendedFrom;
int isBinding;
int hasRCPmemb;
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
int isBranch;
int isFor;
array(char *)* arrTypesDecl;
int haveEntryPoint;
array(struct variable*)* RCPvars;
};
struct compilerStateTag compilerState;
struct cStruct* currentCStruct;
long int threadCount;
struct func* currentFn;
long int totalLines;
long int totalLexerTime;
int RCPenabled;
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
int isValue;
int isFunc;
int isOper;
};
int inArray(char needle,__BAH_ARR_TYPE_char arr){
long int i =  0;
while ((i<len(arr))) {

                if (arr->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:37): arr[%d] with length %d\n", i, arr->length);
                    exit(1);
                };
                if ((needle==arr->data[i])) {
int ____BAH_COMPILER_VAR_194 = true;
return ____BAH_COMPILER_VAR_194;
}
i =  i + 1;
};
int ____BAH_COMPILER_VAR_195 = false;
return ____BAH_COMPILER_VAR_195;
};
int inArrayStr(char * needle,__BAH_ARR_TYPE_cpstring arr){
long int i =  0;
while ((i<len(arr))) {

                if (arr->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:47): arr[%d] with length %d\n", i, arr->length);
                    exit(1);
                };
                if ((__checkString(needle, "/home/alois/Documents/bah-bah/src/lexer.bah:47 needle ")==1&&__checkString(arr->data[i], "/home/alois/Documents/bah-bah/src/lexer.bah:47 arr->data[i]")==1&&strcmp(needle, arr->data[i]) == 0)) {
int ____BAH_COMPILER_VAR_196 = true;
return ____BAH_COMPILER_VAR_196;
}
i =  i + 1;
};
int ____BAH_COMPILER_VAR_197 = false;
return ____BAH_COMPILER_VAR_197;
};
struct Tok makeToken(long int pos,long int lineNb,__BAH_ARR_TYPE_char cont,tokenType type){
struct Tok ____BAH_COMPILER_VAR_198 = {};
____BAH_COMPILER_VAR_198.cont = "";
____BAH_COMPILER_VAR_198.ogCont = "";
____BAH_COMPILER_VAR_198.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_198.pos = 0;
____BAH_COMPILER_VAR_198.line = 1;
____BAH_COMPILER_VAR_198.begLine = 1;
____BAH_COMPILER_VAR_198.bahType = "";
____BAH_COMPILER_VAR_198.isValue = false;
____BAH_COMPILER_VAR_198.isFunc = false;
____BAH_COMPILER_VAR_198.isOper = false;
struct Tok t =  ____BAH_COMPILER_VAR_198;
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
struct Tok ____BAH_COMPILER_VAR_199 = t;
return ____BAH_COMPILER_VAR_199;
};
int isMinus(char c,char nc){
if ((c==45)) {
if (isNumber(nc)) {
int ____BAH_COMPILER_VAR_200 = true;
return ____BAH_COMPILER_VAR_200;
}
}
int ____BAH_COMPILER_VAR_201 = false;
return ____BAH_COMPILER_VAR_201;
};
void lexerErr(long int line,long int pos,char * msg){
char * lineStr =  intToStr(line);
char * posStr =  intToStr(pos);
char * ____BAH_COMPILER_VAR_202 =null;
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
                        ____BAH_COMPILER_VAR_202 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7);
                        
                        strncpy(____BAH_COMPILER_VAR_202+currStrOff, "\e[1;31m[LEXER-ERROR]\e[0m ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_202+currStrOff, compilerState.currentFile, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_202+currStrOff, ":", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_202+currStrOff, lineStr, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_202+currStrOff, ":", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_202+currStrOff, posStr, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_202+currStrOff, "\n\e[0m\n", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_202+currStrOff, msg, strLen_7);
                        currStrOff += strLen_7;
                        
                    }
                    println(____BAH_COMPILER_VAR_202);
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
while ((i<codeLength)) {

                if (s->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:121): s[%d] with length %d\n", i, s->length);
                    exit(1);
                };
                char c =  s->data[i];
long int nci =  i + 1;
char nc =  (char)0;
if ((nci<codeLength)) {

                if (s->length <= i + 1) {
                    printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:125): s[%d] with length %d\n", i + 1, s->length);
                    exit(1);
                };
                nc =  s->data[i + 1];
}
if ((c==47)) {

                if (s->length <= i + 1) {
                    printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:128): s[%d] with length %d\n", i + 1, s->length);
                    exit(1);
                };
                nc =  s->data[i + 1];
if ((nc==47)) {
while ((i<codeLength)) {

                if (s->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:131): s[%d] with length %d\n", i, s->length);
                    exit(1);
                };
                c =  s->data[i];
if ((c==(char)10)) {
break;
}
i =  i + 1;
};
long int max =  codeLength - 1;
if ((i>=max)) {
break;
}
}
}
if ((c==(char)10)) {
lineNb =  lineNb + 1;
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
while ((i<codeLength)) {

                if (s->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:155): s[%d] with length %d\n", i, s->length);
                    exit(1);
                };
                c =  s->data[i];

                if (s->length <= i-1) {
                    printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:156): s[%d] with length %d\n", i-1, s->length);
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
i =  i + 1;
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
                    printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:174): tokens[%d] with length %d\n", len(tokens) - 1, tokens->length);
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
while ((i<codeLength)) {

                if (s->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:184): s[%d] with length %d\n", i, s->length);
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
i =  i + 1;
};
i =  i - 1;

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
i =  i + 1;

                if (s->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:198): s[%d] with length %d\n", i, s->length);
                    exit(1);
                };
                char n =  s->data[i];
char * toInt =  intToStr((long int)nc);
memory =  strToArr(toInt);
i =  i + 1;

                if (s->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:202): s[%d] with length %d\n", i, s->length);
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
i =  i + 1;
while ((i<codeLength)) {

                if (s->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:214): s[%d] with length %d\n", i, s->length);
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
i =  i + 1;
};
i =  i - 1;

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
i =  i + 1;
char fc =  c;
while ((i<codeLength)) {

                if (s->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:234): s[%d] with length %d\n", i, s->length);
                    exit(1);
                };
                c =  s->data[i];
if ((inArray(c,syntaxes)==false)) {
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
i =  i + 1;
};
i =  i - 1;

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
i =  i + 1;
while ((i<codeLength)) {

                if (s->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:268): s[%d] with length %d\n", i, s->length);
                    exit(1);
                };
                c =  s->data[i];
if ((isAlphaNumeric(c)==0)) {
if ((inArray(c,varChars)==false)) {
if ((c==62)) {

                if (memory->length <= len(memory)-1) {
                    printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:273): memory[%d] with length %d\n", len(memory)-1, memory->length);
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
i =  i - 1;
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
i =  i + 1;
};
i =  i - 1;
tokenType currentType =  TOKEN_TYPE_VAR;
char * memstr =  arrAsStr(memory);
if (inArrayStr(memstr,keywords)) {
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
i =  i + 1;
};
totalLines =  totalLines + lineNb - 1;
dur =  getTimeUnix() - dur;
totalLexerTime =  totalLexerTime + dur;
array(struct Tok)* ____BAH_COMPILER_VAR_203 = tokens;
return ____BAH_COMPILER_VAR_203;
};
int hasStructSep(struct string n){
if (n.count((struct string*)&n,".")) {
int ____BAH_COMPILER_VAR_204 = true;
return ____BAH_COMPILER_VAR_204;
}
if (n.count((struct string*)&n,"->")) {
int ____BAH_COMPILER_VAR_205 = true;
return ____BAH_COMPILER_VAR_205;
}
int ____BAH_COMPILER_VAR_206 = false;
return ____BAH_COMPILER_VAR_206;
};
struct string splitStructSepBefore(struct string n){
if (n.count((struct string*)&n,".")) {
char * ____BAH_COMPILER_VAR_207 =splitStringBefore(n,".");struct string res =  string(____BAH_COMPILER_VAR_207);
struct string ____BAH_COMPILER_VAR_208 = res;
return ____BAH_COMPILER_VAR_208;
}
if (n.count((struct string*)&n,"->")) {
char * ____BAH_COMPILER_VAR_209 =splitStringBefore(n,"->");struct string res =  string(____BAH_COMPILER_VAR_209);
struct string ____BAH_COMPILER_VAR_210 = res;
return ____BAH_COMPILER_VAR_210;
}
struct string ____BAH_COMPILER_VAR_211 = string("");
return ____BAH_COMPILER_VAR_211;
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
struct string ____BAH_COMPILER_VAR_212 = n;
return ____BAH_COMPILER_VAR_212;
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
if ((__checkString(s->name, "/home/alois/Documents/bah-bah/src/struct.bah:55 s->name ")==1&&__checkString(name, "/home/alois/Documents/bah-bah/src/struct.bah:55 name")==1&&strcmp(s->name, name) == 0)) {
struct cStruct* ____BAH_COMPILER_VAR_213 = s;
return ____BAH_COMPILER_VAR_213;
}
i =  i + 1;
};
struct cStruct* ____BAH_COMPILER_VAR_214 = null;
return ____BAH_COMPILER_VAR_214;
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
struct structMemb* ____BAH_COMPILER_VAR_215 = memb;
return ____BAH_COMPILER_VAR_215;
}
array(struct structMemb*)* members =  s->members;
long int i =  0;
while ((i<len(members))) {

                if (members->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/struct.bah:86): members[%d] with length %d\n", i, members->length);
                    exit(1);
                };
                struct structMemb* m =  members->data[i];
if ((__checkString(m->name, "/home/alois/Documents/bah-bah/src/struct.bah:87 m->name ")==1&&__checkString(name, "/home/alois/Documents/bah-bah/src/struct.bah:87 name")==1&&strcmp(m->name, name) == 0)) {
struct structMemb* ____BAH_COMPILER_VAR_216 = m;
return ____BAH_COMPILER_VAR_216;
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
if ((__checkString(m->name, "/home/alois/Documents/bah-bah/src/struct.bah:95 m->name ")==1&&__checkString(name, "/home/alois/Documents/bah-bah/src/struct.bah:95 name")==1&&strcmp(m->name, name) == 0)) {
struct structMemb* ____BAH_COMPILER_VAR_217 = memoryAlloc(sizeof(struct structMemb));
____BAH_COMPILER_VAR_217->name = "";
____BAH_COMPILER_VAR_217->type = "";
____BAH_COMPILER_VAR_217->isConst = false;
____BAH_COMPILER_VAR_217->constVal = "";
____BAH_COMPILER_VAR_217->isArray = false;
____BAH_COMPILER_VAR_217->from = "";
____BAH_COMPILER_VAR_217->outterScope = false;
____BAH_COMPILER_VAR_217->def = "";
____BAH_COMPILER_VAR_217->isFn = false;
struct structMemb* sm =  ____BAH_COMPILER_VAR_217;
sm->name =  m->name;
sm->from =  m->from;
sm->type =  m->returns->type;
sm->isFn =  true;
struct structMemb* ____BAH_COMPILER_VAR_218 = sm;
return ____BAH_COMPILER_VAR_218;
}
i =  i + 1;
};
if ((strlen(s->extendedFrom)==0)) {
struct structMemb* ____BAH_COMPILER_VAR_219 = null;
return ____BAH_COMPILER_VAR_219;
}
struct cStruct* es =  searchStruct(s->extendedFrom,elems);
struct structMemb* ____BAH_COMPILER_VAR_220 = searchStructMemb(name,es,elems);
return ____BAH_COMPILER_VAR_220;
};
int isRCPpointerType(char * t){
if (strHasPrefix(t,"function(")) {
int ____BAH_COMPILER_VAR_221 = false;
return ____BAH_COMPILER_VAR_221;
}
if (((((__checkString(t, "/home/alois/Documents/bah-bah/src/type.bah:11 t ")==1&&strcmp(t, "cpstring") == 0)||(__checkString(t, "/home/alois/Documents/bah-bah/src/type.bah:11 t ")==1&&strcmp(t, "ptr") == 0))||(strCount(t,"*")>0))||(strHasPrefix(t,"[]")==true))) {
int ____BAH_COMPILER_VAR_222 = true;
return ____BAH_COMPILER_VAR_222;
}
int ____BAH_COMPILER_VAR_223 = false;
return ____BAH_COMPILER_VAR_223;
};
int isRCPtype(char * t,struct Elems* elems){
if ((isRCPpointerType(t)==true)) {
int ____BAH_COMPILER_VAR_224 = true;
return ____BAH_COMPILER_VAR_224;
}
struct cStruct* s =  searchStruct(t,elems);
if ((((s!=null)&&(s->isBinding==false))&&(s->hasRCPmemb==true))) {
int ____BAH_COMPILER_VAR_225 = true;
return ____BAH_COMPILER_VAR_225;
}
int ____BAH_COMPILER_VAR_226 = false;
return ____BAH_COMPILER_VAR_226;
};
struct string getCType(char * t,struct Elems* elems){
if ((strlen(t)==0)) {
struct string ____BAH_COMPILER_VAR_227 = string("void");
return ____BAH_COMPILER_VAR_227;
}
struct string tp =  string(t);
tp.replace((struct string*)&tp," ","");
if (tp.hasPrefix((struct string*)&tp,"[]")) {
tp.trimLeft((struct string*)&tp,2);
char * tpstr =  tp.str((struct string*)&tp);
tp =  getCType(tpstr,elems);
t =  tp.str((struct string*)&tp);
char * ____BAH_COMPILER_VAR_228 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("array(");
long int strLen_1 = strlen(t);
long int strLen_2 = strlen(")*");
;                            
                        ____BAH_COMPILER_VAR_228 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_228+currStrOff, "array(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_228+currStrOff, t, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_228+currStrOff, ")*", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    char * r =  ____BAH_COMPILER_VAR_228;
struct string ____BAH_COMPILER_VAR_229 = string(r);
return ____BAH_COMPILER_VAR_229;
}
struct string ctp =  tp;
ctp.replace((struct string*)&ctp,"*","");
if ((tp.hasPrefix((struct string*)&tp,"chan:")==1)) {
tp.set((struct string*)&tp,"struct channel *");
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
tp.replace((struct string*)&tp,"bool","int");
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
                    printf("array (/home/alois/Documents/bah-bah/src/type.bah:93): elems->types[%d] with length %d\n", i, elems->types->length);
                    exit(1);
                };
                char * ct =  elems->types->data[i];
if (ctp.compare((struct string*)&ctp,ct)) {
struct string ____BAH_COMPILER_VAR_230 = tp;
return ____BAH_COMPILER_VAR_230;
}
i =  i + 1;
};
struct string ____BAH_COMPILER_VAR_231 = string("");
return ____BAH_COMPILER_VAR_231;
}
}
struct string ____BAH_COMPILER_VAR_232 = tp;
return ____BAH_COMPILER_VAR_232;
};
int compTypes(char * a,char * b){
if ((__checkString(a, "/home/alois/Documents/bah-bah/src/type.bah:109 a ")==1&&strcmp(a, "ptr") == 0)) {
int ____BAH_COMPILER_VAR_233 = true;
return ____BAH_COMPILER_VAR_233;
}
if ((__checkString(b, "/home/alois/Documents/bah-bah/src/type.bah:112 b ")==1&&strcmp(b, "ptr") == 0)) {
int ____BAH_COMPILER_VAR_234 = true;
return ____BAH_COMPILER_VAR_234;
}
if ((__checkString(a, "/home/alois/Documents/bah-bah/src/type.bah:115 a ")==1&&__checkString(b, "/home/alois/Documents/bah-bah/src/type.bah:115 b")==1&&strcmp(a, b) == 0)) {
int ____BAH_COMPILER_VAR_235 = true;
return ____BAH_COMPILER_VAR_235;
}
int ____BAH_COMPILER_VAR_236 = false;
return ____BAH_COMPILER_VAR_236;
};
#include <stddef.h>
struct reflectElement {
long int size;
char * type;
char * name;
int isArray;
struct reflectElement* arrayElem;
int isStruct;
array(struct reflectElement)* structLayout;
long int offset;
void * value;
void *(*calculateOffset)(struct reflectElement* this,void * origin);
};
void * reflectElement__calculateOffset(struct reflectElement* this,void * origin){
char * base =  origin;
void * ____BAH_COMPILER_VAR_237 = noCheck( base + this->offset );
return ____BAH_COMPILER_VAR_237;
};
typedef array(struct reflectElement)* __BAH_ARR_TYPE_reflectElement;
struct reflectElement __reflect(void * v,long int s,char * t,char * n,int isArr,struct reflectElement* ae,int isStruct,__BAH_ARR_TYPE_reflectElement sl,long int offset){
struct reflectElement ____BAH_COMPILER_VAR_238 = {};
____BAH_COMPILER_VAR_238.type= null;
____BAH_COMPILER_VAR_238.name= null;
____BAH_COMPILER_VAR_238.arrayElem= null;
____BAH_COMPILER_VAR_238.structLayout = memoryAlloc(sizeof(array(struct reflectElement)));
            ____BAH_COMPILER_VAR_238.structLayout->length = 0;
            ____BAH_COMPILER_VAR_238.structLayout->elemSize = sizeof(struct reflectElement);
            ____BAH_COMPILER_VAR_238.value= null;
____BAH_COMPILER_VAR_238.calculateOffset = reflectElement__calculateOffset;
struct reflectElement re =  ____BAH_COMPILER_VAR_238;
re.size =  s;
re.type =  t;
re.name =  n;
re.isArray =  isArr;
re.arrayElem =  ae;
re.isStruct =  isStruct;
re.structLayout =  sl;
re.value =  v;
re.offset =  offset;
struct reflectElement ____BAH_COMPILER_VAR_239 = re;
return ____BAH_COMPILER_VAR_239;
};
#define JSON_TYPE_STRING 0
#define JSON_TYPE_INT 1
#define JSON_TYPE_FLOAT 2
#define JSON_TYPE_ARRAY 3
#define JSON_TYPE_MAP 4
char * toJson(struct reflectElement e);
void json_scan_inner(void * this,struct reflectElement e,int isMember);
struct jsonElement {
long int type;
char * key;
char * content;
array(struct jsonElement*)* children;
struct jsonElement*(*map)(struct jsonElement* this,char * key);
char *(*str)(struct jsonElement* this);
void(*scan)(struct jsonElement* this,struct reflectElement e);
};
struct jsonElement* jsonElement__map(struct jsonElement* this,char * key){
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
if ((__checkString(arrAsStr(nk), "/opt/bah/json.bah:39 arrAsStr(nk) ")==1&&__checkString(key, "/opt/bah/json.bah:39 key")==1&&strcmp(arrAsStr(nk), key) == 0)) {
struct jsonElement* ____BAH_COMPILER_VAR_240 = elem;
return ____BAH_COMPILER_VAR_240;
}
}
else {
if ((__checkString(elem->key, "/opt/bah/json.bah:43 elem->key ")==1&&__checkString(key, "/opt/bah/json.bah:43 key")==1&&strcmp(elem->key, key) == 0)) {
struct jsonElement* ____BAH_COMPILER_VAR_241 = elem;
return ____BAH_COMPILER_VAR_241;
}
}
i =  i + 1;
};
void * z =  (void *)0;
struct jsonElement* ____BAH_COMPILER_VAR_242 = z;
return ____BAH_COMPILER_VAR_242;
};
char * jsonElement__str(struct jsonElement* this){
char * ctn =  this->content;
char * ____BAH_COMPILER_VAR_243 = ctn;
return ____BAH_COMPILER_VAR_243;
};
void jsonElement__scan(struct jsonElement* this,struct reflectElement e){
json_scan_inner(this,e,false);
};
void json_scan_inner(void * thisp,struct reflectElement e,int isMember){
struct jsonElement* this =  thisp;
if ((e.isStruct==true)) {
long int i =  0;
while ((i<len(e.structLayout))) {

                if (e.structLayout->length <= i) {
                    printf("array (/opt/bah/json.bah:71): e.structLayout[%d] with length %d\n", i, e.structLayout->length);
                    exit(1);
                };
                struct reflectElement m =  e.structLayout->data[i];
struct jsonElement* ov =  this->map((struct jsonElement*)this,m.name);
if ((ov!=null)) {
json_scan_inner(ov,m,true);
}
i =  i + 1;
};
}
else if ((__checkString(e.type, "/opt/bah/json.bah:78 e.type ")==1&&strcmp(e.type, "int") == 0)) {
long int* ep =  e.value;
*ep =  strToInt(this->content);
}
else if ((__checkString(e.type, "/opt/bah/json.bah:81 e.type ")==1&&strcmp(e.type, "cpstring") == 0)) {
char ** ep =  e.value;
*ep =  memoryAlloc(strlen(this->content) + 1);
strcpy(*ep,this->content);
}
else if ((__checkString(e.type, "/opt/bah/json.bah:85 e.type ")==1&&strcmp(e.type, "float") == 0)) {
double* ep =  e.value;
*ep =  strToFloat(this->content);
}
else if ((__checkString(e.type, "/opt/bah/json.bah:88 e.type ")==1&&strcmp(e.type, "bool") == 0)) {
int* ep =  e.value;
if (((__checkString(this->content, "/opt/bah/json.bah:90 this->content ")==1&&strcmp(this->content, "1") == 0)||(__checkString(this->content, "/opt/bah/json.bah:90 this->content ")==1&&strcmp(this->content, "true") == 0))) {
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
if ((__checkString(ae->type, "/opt/bah/json.bah:101 ae->type ")==1&&strcmp(ae->type, "int") == 0)) {
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
else if ((__checkString(ae->type, "/opt/bah/json.bah:110 ae->type ")==1&&strcmp(ae->type, "float") == 0)) {
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
else if ((__checkString(ae->type, "/opt/bah/json.bah:123 ae->type ")==1&&strcmp(ae->type, "cpstring") == 0)) {
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
struct jsonElement* ov =  c->map((struct jsonElement*)c,m.name);
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
};
struct jsonElement* parseJson(char * s){
struct jsonElement* ____BAH_COMPILER_VAR_245 = memoryAlloc(sizeof(struct jsonElement));
____BAH_COMPILER_VAR_245->key= null;
____BAH_COMPILER_VAR_245->content= null;
____BAH_COMPILER_VAR_245->children = memoryAlloc(sizeof(array(struct jsonElement*)));
            ____BAH_COMPILER_VAR_245->children->length = 0;
            ____BAH_COMPILER_VAR_245->children->elemSize = sizeof(struct jsonElement*);
            ____BAH_COMPILER_VAR_245->map = jsonElement__map;
____BAH_COMPILER_VAR_245->str = jsonElement__str;
____BAH_COMPILER_VAR_245->scan = jsonElement__scan;
struct jsonElement* jsonElem =  ____BAH_COMPILER_VAR_245;
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
int isFloat =  false;
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
struct jsonElement* ____BAH_COMPILER_VAR_246 = null;
return ____BAH_COMPILER_VAR_246;
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
char * ____BAH_COMPILER_VAR_247 =arrToStr(currentElem);struct jsonElement* child =  parseJson(____BAH_COMPILER_VAR_247);
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
char * ____BAH_COMPILER_VAR_248 =arrToStr(currentElem);struct jsonElement* child =  parseJson(____BAH_COMPILER_VAR_248);
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
char * ____BAH_COMPILER_VAR_249 =arrToStr(currentElem);struct jsonElement* elem =  parseJson(____BAH_COMPILER_VAR_249);
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
char * ____BAH_COMPILER_VAR_250 =arrToStr(currentElem);struct jsonElement* elem =  parseJson(____BAH_COMPILER_VAR_250);
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
struct jsonElement* ____BAH_COMPILER_VAR_251 = jsonElem;
return ____BAH_COMPILER_VAR_251;
};
char * jsonEscapeStr(char * s){
array(char)* a =  strAsArr(s);
array(char)* r = memoryAlloc(sizeof(array(char)));

r->length = 0;
r->elemSize = sizeof(char);
long int i =  0;
while ((i<len(a))) {

                if (a->length <= i) {
                    printf("array (/opt/bah/json.bah:377): a[%d] with length %d\n", i, a->length);
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
char * ____BAH_COMPILER_VAR_252 = arrToStr(r);
return ____BAH_COMPILER_VAR_252;
};
char * toJson__inner(struct reflectElement e,int isMember,long int tabs){
void ** v =  e.value;
if (((e.value==null)||(*v==null))) {
if (((__checkString(e.type, "/opt/bah/json.bah:403 e.type ")==1&&strcmp(e.type, "int") == 0)||(__checkString(e.type, "/opt/bah/json.bah:403 e.type ")==1&&strcmp(e.type, "float") == 0))) {
char * ____BAH_COMPILER_VAR_253 = "0";
return ____BAH_COMPILER_VAR_253;
}
if ((__checkString(e.type, "/opt/bah/json.bah:406 e.type ")==1&&strcmp(e.type, "bool") == 0)) {
char * ____BAH_COMPILER_VAR_254 = "false";
return ____BAH_COMPILER_VAR_254;
}
if ((((__checkString(e.type, "/opt/bah/json.bah:409 e.type ")==1&&strcmp(e.type, "ptr") == 0)||(__checkString(e.type, "/opt/bah/json.bah:409 e.type ")==1&&strcmp(e.type, "cpstring") == 0))||(strCount(e.type,"*")!=0))) {
char * ____BAH_COMPILER_VAR_255 = "null";
return ____BAH_COMPILER_VAR_255;
}
}
if ((e.isStruct==true)) {
tabs =  tabs + 1;
char * tabsStr =  "";
long int i =  0;
while ((i<tabs)) {
char * ____BAH_COMPILER_VAR_256 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(tabsStr);
long int strLen_1 = strlen("\t");
;                            
                        ____BAH_COMPILER_VAR_256 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_256+currStrOff, tabsStr, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_256+currStrOff, "\t", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    tabsStr =  ____BAH_COMPILER_VAR_256;
i =  i + 1;
};
char * s =  "{\n";
i =  0;
while ((i<len(e.structLayout))) {

                if (e.structLayout->length <= i) {
                    printf("array (/opt/bah/json.bah:422): e.structLayout[%d] with length %d\n", i, e.structLayout->length);
                    exit(1);
                };
                struct reflectElement m =  e.structLayout->data[i];
i =  i + 1;
if ((i<len(e.structLayout))) {
char * ____BAH_COMPILER_VAR_257 =toJson__inner(m,true,tabs);char * ____BAH_COMPILER_VAR_258 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen(tabsStr);
long int strLen_2 = strlen("\"");
long int strLen_3 = strlen(m.name);
long int strLen_4 = strlen("\": ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_257);
long int strLen_6 = strlen(",\n");
;                            
                        ____BAH_COMPILER_VAR_258 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                        
                        strncpy(____BAH_COMPILER_VAR_258+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_258+currStrOff, tabsStr, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_258+currStrOff, "\"", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_258+currStrOff, m.name, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_258+currStrOff, "\": ", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_258+currStrOff, ____BAH_COMPILER_VAR_257, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_258+currStrOff, ",\n", strLen_6);
                        currStrOff += strLen_6;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_258;
}
else {
char * ____BAH_COMPILER_VAR_259 =toJson__inner(m,true,tabs);char * ____BAH_COMPILER_VAR_260 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen(tabsStr);
long int strLen_2 = strlen("\"");
long int strLen_3 = strlen(m.name);
long int strLen_4 = strlen("\": ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_259);
long int strLen_6 = strlen("\n");
;                            
                        ____BAH_COMPILER_VAR_260 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                        
                        strncpy(____BAH_COMPILER_VAR_260+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_260+currStrOff, tabsStr, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_260+currStrOff, "\"", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_260+currStrOff, m.name, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_260+currStrOff, "\": ", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_260+currStrOff, ____BAH_COMPILER_VAR_259, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_260+currStrOff, "\n", strLen_6);
                        currStrOff += strLen_6;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_260;
}
};
tabs =  tabs - 1;
tabsStr =  "";
i =  0;
while ((i<tabs)) {
char * ____BAH_COMPILER_VAR_261 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(tabsStr);
long int strLen_1 = strlen("\t");
;                            
                        ____BAH_COMPILER_VAR_261 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_261+currStrOff, tabsStr, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_261+currStrOff, "\t", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    tabsStr =  ____BAH_COMPILER_VAR_261;
i =  i + 1;
};
char * ____BAH_COMPILER_VAR_262 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen(tabsStr);
long int strLen_2 = strlen("}");
;                            
                        ____BAH_COMPILER_VAR_262 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_262+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_262+currStrOff, tabsStr, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_262+currStrOff, "}", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_262;
char * ____BAH_COMPILER_VAR_263 = s;
return ____BAH_COMPILER_VAR_263;
}
else if ((__checkString(e.type, "/opt/bah/json.bah:438 e.type ")==1&&strcmp(e.type, "int") == 0)) {
long int* ip =  e.value;
char * ____BAH_COMPILER_VAR_264 = intToStr(*ip);
return ____BAH_COMPILER_VAR_264;
}
else if ((__checkString(e.type, "/opt/bah/json.bah:441 e.type ")==1&&strcmp(e.type, "float") == 0)) {
double* fp =  e.value;
char * ____BAH_COMPILER_VAR_265 = floatToStr(*fp);
return ____BAH_COMPILER_VAR_265;
}
else if ((__checkString(e.type, "/opt/bah/json.bah:444 e.type ")==1&&strcmp(e.type, "cpstring") == 0)) {
if ((isMember==false)) {
void * s =  e.value;
char * ____BAH_COMPILER_VAR_266 =jsonEscapeStr(s);char * ____BAH_COMPILER_VAR_267 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\"");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_266);
long int strLen_2 = strlen("\"");
;                            
                        ____BAH_COMPILER_VAR_267 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_267+currStrOff, "\"", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_267+currStrOff, ____BAH_COMPILER_VAR_266, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_267+currStrOff, "\"", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    char * ____BAH_COMPILER_VAR_268 = ____BAH_COMPILER_VAR_267;
return ____BAH_COMPILER_VAR_268;
}
else {
char ** sp =  e.value;
char * s =  *sp;
char * ____BAH_COMPILER_VAR_269 =jsonEscapeStr(s);char * ____BAH_COMPILER_VAR_270 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\"");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_269);
long int strLen_2 = strlen("\"");
;                            
                        ____BAH_COMPILER_VAR_270 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_270+currStrOff, "\"", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_270+currStrOff, ____BAH_COMPILER_VAR_269, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_270+currStrOff, "\"", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    char * ____BAH_COMPILER_VAR_271 = ____BAH_COMPILER_VAR_270;
return ____BAH_COMPILER_VAR_271;
}
}
else if ((__checkString(e.type, "/opt/bah/json.bah:453 e.type ")==1&&strcmp(e.type, "bool") == 0)) {
int* bp =  e.value;
if ((*bp==true)) {
char * ____BAH_COMPILER_VAR_272 = "true";
return ____BAH_COMPILER_VAR_272;
}
char * ____BAH_COMPILER_VAR_273 = "false";
return ____BAH_COMPILER_VAR_273;
}
else if ((e.isArray==true)) {
char * s =  "[";
struct reflectElement* ae =  e.arrayElem;
if ((__checkString(ae->type, "/opt/bah/json.bah:462 ae->type ")==1&&strcmp(ae->type, "int") == 0)) {
array(long int)* arr = memoryAlloc(sizeof(array(long int)));

arr->length = 0;
arr->elemSize = sizeof(long int);
void ** arrPtr =  e.value;
arr =  *arrPtr;
long int i =  0;
while ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_274 =intToStr(arr->data[i]);char * ____BAH_COMPILER_VAR_275 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_274);
;                            
                        ____BAH_COMPILER_VAR_275 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_275+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_275+currStrOff, ____BAH_COMPILER_VAR_274, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_275;
i =  i + 1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_276 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen(",");
;                            
                        ____BAH_COMPILER_VAR_276 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_276+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_276+currStrOff, ",", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_276;
}
};
}
else if ((__checkString(ae->type, "/opt/bah/json.bah:473 ae->type ")==1&&strcmp(ae->type, "float") == 0)) {
array(double)* arr = memoryAlloc(sizeof(array(double)));

arr->length = 0;
arr->elemSize = sizeof(double);
void ** arrPtr =  e.value;
arr =  *arrPtr;
long int i =  0;
while ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_277 =floatToStr(arr->data[i]);char * ____BAH_COMPILER_VAR_278 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_277);
;                            
                        ____BAH_COMPILER_VAR_278 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_278+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_278+currStrOff, ____BAH_COMPILER_VAR_277, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_278;
i =  i + 1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_279 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen(",");
;                            
                        ____BAH_COMPILER_VAR_279 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_279+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_279+currStrOff, ",", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_279;
}
};
}
else if ((__checkString(ae->type, "/opt/bah/json.bah:484 ae->type ")==1&&strcmp(ae->type, "cpstring") == 0)) {
array(char *)* arr = memoryAlloc(sizeof(array(char *)));

arr->length = 0;
arr->elemSize = sizeof(char *);
void ** arrPtr =  e.value;
arr =  *arrPtr;
char * ____BAH_COMPILER_VAR_280 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen("\n");
;                            
                        ____BAH_COMPILER_VAR_280 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_280+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_280+currStrOff, "\n", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_280;
long int i =  0;
while ((i<len(arr))) {

                if (arr->length <= i) {
                    printf("array (/opt/bah/json.bah:490): arr[%d] with length %d\n", i, arr->length);
                    exit(1);
                };
                char * ____BAH_COMPILER_VAR_281 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen(arr->data[i]);
;                            
                        ____BAH_COMPILER_VAR_281 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_281+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_281+currStrOff, arr->data[i], strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_281;
i =  i + 1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_282 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen(",\n");
;                            
                        ____BAH_COMPILER_VAR_282 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_282+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_282+currStrOff, ",\n", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_282;
}
else {
char * ____BAH_COMPILER_VAR_283 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen("\n");
;                            
                        ____BAH_COMPILER_VAR_283 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_283+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_283+currStrOff, "\n", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_283;
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
                    printf("array (/opt/bah/json.bah:510): arr[%d] with length %d\n", i, arr->length);
                    exit(1);
                };
                void * arrElem =  arr->data[i];
ae->value =  arrElem;
long int j =  0;
while ((j<len(ae->structLayout))) {

                if (ae->structLayout->length <= j) {
                    printf("array (/opt/bah/json.bah:513): ae->structLayout[%d] with length %d\n", j, ae->structLayout->length);
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
char * ____BAH_COMPILER_VAR_284 =toJson__inner(*ae,false,tabs);char * ____BAH_COMPILER_VAR_285 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_284);
;                            
                        ____BAH_COMPILER_VAR_285 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_285+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_285+currStrOff, ____BAH_COMPILER_VAR_284, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_285;
i =  i + 1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_286 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen(",\n");
;                            
                        ____BAH_COMPILER_VAR_286 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_286+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_286+currStrOff, ",\n", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_286;
}
else {
char * ____BAH_COMPILER_VAR_287 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen("\n");
;                            
                        ____BAH_COMPILER_VAR_287 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_287+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_287+currStrOff, "\n", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_287;
}
};
}
char * ____BAH_COMPILER_VAR_288 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen("]");
;                            
                        ____BAH_COMPILER_VAR_288 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_288+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_288+currStrOff, "]", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_288;
char * ____BAH_COMPILER_VAR_289 = s;
return ____BAH_COMPILER_VAR_289;
}
char * ____BAH_COMPILER_VAR_290 = "";
return ____BAH_COMPILER_VAR_290;
};
char * toJson(struct reflectElement e){
char * ____BAH_COMPILER_VAR_291 = toJson__inner(e,false,0);
return ____BAH_COMPILER_VAR_291;
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
char * ____BAH_COMPILER_VAR_293 = name;
struct reflectElement ____BAH_COMPILER_VAR_294 = __reflect(____BAH_COMPILER_VAR_293, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, 0);
char * ____BAH_COMPILER_VAR_295 =toJson(____BAH_COMPILER_VAR_294);char * ____BAH_COMPILER_VAR_296 =intToStr(line);char * ____BAH_COMPILER_VAR_297 =toJson(e);char * ____BAH_COMPILER_VAR_298 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\n    {\n        \"name\": ");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_295);
long int strLen_2 = strlen(",\n        \"path\": \"");
long int strLen_3 = strlen(compilerState.currentFile);
long int strLen_4 = strlen(":");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_296);
long int strLen_6 = strlen("\",\n        \"element\": ");
long int strLen_7 = strlen(____BAH_COMPILER_VAR_297);
long int strLen_8 = strlen("\n    },\n    ");
;                            
                        ____BAH_COMPILER_VAR_298 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                        
                        strncpy(____BAH_COMPILER_VAR_298+currStrOff, "\n    {\n        \"name\": ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_298+currStrOff, ____BAH_COMPILER_VAR_295, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_298+currStrOff, ",\n        \"path\": \"", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_298+currStrOff, compilerState.currentFile, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_298+currStrOff, ":", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_298+currStrOff, ____BAH_COMPILER_VAR_296, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_298+currStrOff, "\",\n        \"element\": ", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_298+currStrOff, ____BAH_COMPILER_VAR_297, strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_298+currStrOff, "\n    },\n    ", strLen_8);
                        currStrOff += strLen_8;
                        
                    }
                    println(____BAH_COMPILER_VAR_298);
};
void debugError(char * name,long int line,long int from,long int to,struct reflectElement e){
if ((debug==false)) {
return;
}
char * ____BAH_COMPILER_VAR_300 = name;
struct reflectElement ____BAH_COMPILER_VAR_301 = __reflect(____BAH_COMPILER_VAR_300, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, 0);
char * ____BAH_COMPILER_VAR_302 =toJson(____BAH_COMPILER_VAR_301);char * ____BAH_COMPILER_VAR_303 =intToStr(line);char * ____BAH_COMPILER_VAR_304 =intToStr(from);char * ____BAH_COMPILER_VAR_305 =intToStr(to);char * ____BAH_COMPILER_VAR_306 =toJson(e);char * ____BAH_COMPILER_VAR_307 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\n    {\n        \"name\": ");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_302);
long int strLen_2 = strlen(",\n        \"path\": \"");
long int strLen_3 = strlen(compilerState.currentFile);
long int strLen_4 = strlen(":");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_303);
long int strLen_6 = strlen("\",\n        \"range\": [\n            ");
long int strLen_7 = strlen(____BAH_COMPILER_VAR_304);
long int strLen_8 = strlen(",\n            ");
long int strLen_9 = strlen(____BAH_COMPILER_VAR_305);
long int strLen_10 = strlen("\n        ],\n        \"element\": ");
long int strLen_11 = strlen(____BAH_COMPILER_VAR_306);
long int strLen_12 = strlen("\n    },\n    ");
;                            
                        ____BAH_COMPILER_VAR_307 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12);
                        
                        strncpy(____BAH_COMPILER_VAR_307+currStrOff, "\n    {\n        \"name\": ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_307+currStrOff, ____BAH_COMPILER_VAR_302, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_307+currStrOff, ",\n        \"path\": \"", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_307+currStrOff, compilerState.currentFile, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_307+currStrOff, ":", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_307+currStrOff, ____BAH_COMPILER_VAR_303, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_307+currStrOff, "\",\n        \"range\": [\n            ", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_307+currStrOff, ____BAH_COMPILER_VAR_304, strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_307+currStrOff, ",\n            ", strLen_8);
                        currStrOff += strLen_8;
                        
                        strncpy(____BAH_COMPILER_VAR_307+currStrOff, ____BAH_COMPILER_VAR_305, strLen_9);
                        currStrOff += strLen_9;
                        
                        strncpy(____BAH_COMPILER_VAR_307+currStrOff, "\n        ],\n        \"element\": ", strLen_10);
                        currStrOff += strLen_10;
                        
                        strncpy(____BAH_COMPILER_VAR_307+currStrOff, ____BAH_COMPILER_VAR_306, strLen_11);
                        currStrOff += strLen_11;
                        
                        strncpy(____BAH_COMPILER_VAR_307+currStrOff, "\n    },\n    ", strLen_12);
                        currStrOff += strLen_12;
                        
                    }
                    println(____BAH_COMPILER_VAR_307);
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
struct variable* ____BAH_COMPILER_VAR_309 = v;
char ** ____BAH_COMPILER_VAR_311 = (char **)((char*)(____BAH_COMPILER_VAR_309) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_312 = __reflect(____BAH_COMPILER_VAR_311, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_313 = (char **)((char*)(____BAH_COMPILER_VAR_309) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_314 = __reflect(____BAH_COMPILER_VAR_313, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
int* ____BAH_COMPILER_VAR_315 = (int*)((char*)(____BAH_COMPILER_VAR_309) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_316 = __reflect(____BAH_COMPILER_VAR_315, sizeof(int), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_317 = (char **)((char*)(____BAH_COMPILER_VAR_309) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_318 = __reflect(____BAH_COMPILER_VAR_317, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
int* ____BAH_COMPILER_VAR_319 = (int*)((char*)(____BAH_COMPILER_VAR_309) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_320 = __reflect(____BAH_COMPILER_VAR_319, sizeof(int), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_321 = (char **)((char*)(____BAH_COMPILER_VAR_309) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_322 = __reflect(____BAH_COMPILER_VAR_321, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
int* ____BAH_COMPILER_VAR_323 = (int*)((char*)(____BAH_COMPILER_VAR_309) + offsetof(struct variable, outterScope));
struct reflectElement ____BAH_COMPILER_VAR_324 = __reflect(____BAH_COMPILER_VAR_323, sizeof(int), "bool", "outterScope", 0, 0, 0, 0, offsetof(struct variable, outterScope));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_310 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_310->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_310->length = 7;
        ____BAH_COMPILER_VAR_310->data = memoryAlloc(____BAH_COMPILER_VAR_310->length * ____BAH_COMPILER_VAR_310->elemSize);
        ____BAH_COMPILER_VAR_310->data[0] = ____BAH_COMPILER_VAR_312;
____BAH_COMPILER_VAR_310->data[1] = ____BAH_COMPILER_VAR_314;
____BAH_COMPILER_VAR_310->data[2] = ____BAH_COMPILER_VAR_316;
____BAH_COMPILER_VAR_310->data[3] = ____BAH_COMPILER_VAR_318;
____BAH_COMPILER_VAR_310->data[4] = ____BAH_COMPILER_VAR_320;
____BAH_COMPILER_VAR_310->data[5] = ____BAH_COMPILER_VAR_322;
____BAH_COMPILER_VAR_310->data[6] = ____BAH_COMPILER_VAR_324;
struct reflectElement ____BAH_COMPILER_VAR_325 = __reflect(____BAH_COMPILER_VAR_309, sizeof(struct variable), "variable*", "v", 0, 0, 1, ____BAH_COMPILER_VAR_310, 0);
debugPrint("var_end",line,____BAH_COMPILER_VAR_325);
}
i =  i + 1;
};
};
void throwErr(void * tp,char * format){
char * str =  "";
char * info =  "";
long int pos =  0;
if ((tp!=null)) {
struct fileMap ____BAH_COMPILER_VAR_326 = {};
____BAH_COMPILER_VAR_326.handle = -1;
____BAH_COMPILER_VAR_326.p= null;
____BAH_COMPILER_VAR_326.open = fileMap__open;
____BAH_COMPILER_VAR_326.isValid = fileMap__isValid;
____BAH_COMPILER_VAR_326.close = fileMap__close;
struct fileMap fm =  ____BAH_COMPILER_VAR_326;
char * fileSrcStr =  fm.open((struct fileMap*)&fm,compilerState.currentFile);
struct string fileSrc =  string(fileSrcStr);
fm.close((struct fileMap*)&fm);
struct Tok* t =  tp;
struct string ffmt =  string(format);
if ((strlen(t->ogCont)==0)) {
t->ogCont =  t->cont;
}
char * ____BAH_COMPILER_VAR_327 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("'");
long int strLen_1 = strlen(t->ogCont);
long int strLen_2 = strlen("'");
;                            
                        ____BAH_COMPILER_VAR_327 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_327+currStrOff, "'", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_327+currStrOff, t->ogCont, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_327+currStrOff, "'", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    ffmt.replace((struct string*)&ffmt,"{TOKEN}",____BAH_COMPILER_VAR_327);
format =  ffmt.str((struct string*)&ffmt);
array(char)* line = memoryAlloc(sizeof(array(char)));

line->length = 0;
line->elemSize = sizeof(char);
long int beg =  t->pos;
while ((beg>0)) {
char c =  fileSrc.charAt((struct string*)&fileSrc,beg);
if ((c==(char)10)) {
beg =  beg + 1;
break;
}
beg =  beg - 1;
};
pos =  t->pos - beg + 1;
long int i =  beg;
while ((i<fileSrc.length)) {
char c =  fileSrc.charAt((struct string*)&fileSrc,i);
if ((c==(char)10)) {
break;
}
if ((i==t->pos)) {
char * ____BAH_COMPILER_VAR_328 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\e[1;31m");
long int strLen_1 = strlen(t->ogCont);
long int strLen_2 = strlen("\e[1;37m");
;                            
                        ____BAH_COMPILER_VAR_328 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_328+currStrOff, "\e[1;31m", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_328+currStrOff, t->ogCont, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_328+currStrOff, "\e[1;37m", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    array(char)* errTk =  strToArr(____BAH_COMPILER_VAR_328);
long int ii =  0;
while ((ii<len(errTk))) {

                if (errTk->length <= ii) {
                    printf("array (/home/alois/Documents/bah-bah/src/errors.bah:46): errTk[%d] with length %d\n", ii, errTk->length);
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
str =  arrToStr(line);
char * ____BAH_COMPILER_VAR_329 =intToStr(t->line);char * ____BAH_COMPILER_VAR_330 =intToStr(pos);char * ____BAH_COMPILER_VAR_331 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(____BAH_COMPILER_VAR_329);
long int strLen_1 = strlen(":");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_330);
;                            
                        ____BAH_COMPILER_VAR_331 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_331+currStrOff, ____BAH_COMPILER_VAR_329, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_331+currStrOff, ":", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_331+currStrOff, ____BAH_COMPILER_VAR_330, strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    info =  ____BAH_COMPILER_VAR_331;
}
if ((debug==true)) {
struct Tok* t =  tp;
char * ____BAH_COMPILER_VAR_332 = format;
struct reflectElement ____BAH_COMPILER_VAR_333 = __reflect(____BAH_COMPILER_VAR_332, sizeof(char *), "cpstring", "format", 0, 0, 0, 0, 0);
debugError("error",t->line,pos,pos + strlen(t->ogCont),____BAH_COMPILER_VAR_333);
debugExit();
}
else {
char * ____BAH_COMPILER_VAR_334 =null;
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
                        ____BAH_COMPILER_VAR_334 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7);
                        
                        strncpy(____BAH_COMPILER_VAR_334+currStrOff, "\e[1;31m[ERROR]\e[0m ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_334+currStrOff, compilerState.currentFile, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_334+currStrOff, ":", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_334+currStrOff, info, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_334+currStrOff, "\n\e[1;37m\t", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_334+currStrOff, str, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_334+currStrOff, "\e[0m\n", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_334+currStrOff, format, strLen_7);
                        currStrOff += strLen_7;
                        
                    }
                    println(____BAH_COMPILER_VAR_334);
}
exit(1);
};
void throwWarning(char * s){
char * ____BAH_COMPILER_VAR_335 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\e[1;33m[WARNING]\e[0m ");
long int strLen_1 = strlen(compilerState.currentFile);
long int strLen_2 = strlen("\n\e[1;37m\t");
long int strLen_3 = strlen(s);
long int strLen_4 = strlen("\e[0m");
;                            
                        ____BAH_COMPILER_VAR_335 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_335+currStrOff, "\e[1;33m[WARNING]\e[0m ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_335+currStrOff, compilerState.currentFile, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_335+currStrOff, "\n\e[1;37m\t", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_335+currStrOff, s, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_335+currStrOff, "\e[0m", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    println(____BAH_COMPILER_VAR_335);
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
char * ____BAH_COMPILER_VAR_336 = p;
return ____BAH_COMPILER_VAR_336;
};
char * getCurrentPath(){
char * cwd =  memoryAlloc(4096);
getcwd(cwd,4096);
char * ____BAH_COMPILER_VAR_337 = cwd;
return ____BAH_COMPILER_VAR_337;
};
int isInside(char * basePath,char * subPath){
char * abs1 =  absPath(basePath);
char * abs2 =  absPath(subPath);
int ____BAH_COMPILER_VAR_338 = (strHasPrefix(subPath,basePath)==true);
return ____BAH_COMPILER_VAR_338;
};
void setCurrentPath(char * s){
chdir(s);
};
int isGlobal(){
int ____BAH_COMPILER_VAR_339 = (currentFn==null);
return ____BAH_COMPILER_VAR_339;
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
n.trimRight((struct string*)&n,tamm + 6);
name =  n.str((struct string*)&n);
struct variable* v =  searchVar(name,elems);
struct string vt =  string(v->type);
vt.trimLeft((struct string*)&vt,2);
char * vtstr =  vt.str((struct string*)&vt);
struct variable* ____BAH_COMPILER_VAR_340 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_340->name = "";
____BAH_COMPILER_VAR_340->type = "";
____BAH_COMPILER_VAR_340->isConst = false;
____BAH_COMPILER_VAR_340->constVal = "";
____BAH_COMPILER_VAR_340->isArray = false;
____BAH_COMPILER_VAR_340->from = "";
____BAH_COMPILER_VAR_340->outterScope = false;
struct variable* nv =  ____BAH_COMPILER_VAR_340;
nv->type =  vtstr;
nv->name =  ogName;
nv->isArray =  true;
struct variable* ____BAH_COMPILER_VAR_341 = nv;
return ____BAH_COMPILER_VAR_341;
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
struct variable* ____BAH_COMPILER_VAR_342 = null;
return ____BAH_COMPILER_VAR_342;
}
struct cStruct* s =  searchStruct(v->type,elems);
if ((s==null)) {
struct variable* ____BAH_COMPILER_VAR_343 = null;
return ____BAH_COMPILER_VAR_343;
}
struct structMemb* memb =  searchStructMemb(membs,s,elems);
if ((memb==null)) {
struct variable* ____BAH_COMPILER_VAR_344 = null;
return ____BAH_COMPILER_VAR_344;
}
struct variable* ____BAH_COMPILER_VAR_345 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_345->name = "";
____BAH_COMPILER_VAR_345->type = "";
____BAH_COMPILER_VAR_345->isConst = false;
____BAH_COMPILER_VAR_345->constVal = "";
____BAH_COMPILER_VAR_345->isArray = false;
____BAH_COMPILER_VAR_345->from = "";
____BAH_COMPILER_VAR_345->outterScope = false;
struct variable* nv =  ____BAH_COMPILER_VAR_345;
nv->from =  memb->from;
nv->name =  memb->name;
nv->type =  memb->type;
nv->name =  ogName;
char * r =  nv->type;
struct string tcc =  string(ogName);
if (tcc.count((struct string*)&tcc,"&")) {
char * ____BAH_COMPILER_VAR_346 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(r);
long int strLen_1 = strlen("*");
;                            
                        ____BAH_COMPILER_VAR_346 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_346+currStrOff, r, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_346+currStrOff, "*", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    r =  ____BAH_COMPILER_VAR_346;
}
long int nbUnaries =  tcc.count((struct string*)&tcc,"*");
if ((nbUnaries>0)) {
struct string ct =  string(r);
long int pointerLevel =  ct.count((struct string*)&ct,"*");
if ((pointerLevel<nbUnaries)) {
char * ____BAH_COMPILER_VAR_347 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot use '*' on ");
long int strLen_1 = strlen(nv->name);
long int strLen_2 = strlen(" because it is not pointer.");
;                            
                        ____BAH_COMPILER_VAR_347 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_347+currStrOff, "Cannot use '*' on ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_347+currStrOff, nv->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_347+currStrOff, " because it is not pointer.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    throwErr(null,____BAH_COMPILER_VAR_347);
}
ct.trimRight((struct string*)&ct,nbUnaries);
r =  ct.str((struct string*)&ct);
}
nv->type =  r;
nv->name =  ogName;
struct variable* ____BAH_COMPILER_VAR_348 = nv;
return ____BAH_COMPILER_VAR_348;
}
long int i =  0;
while ((i<len(elems->vars))) {

                if (elems->vars->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/var.bah:95): elems->vars[%d] with length %d\n", i, elems->vars->length);
                    exit(1);
                };
                struct variable* v =  elems->vars->data[i];
if ((v==null)) {
char * ____BAH_COMPILER_VAR_349 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\e[1;31m[INTERNAL COMPILER ERROR]\e[0m\n Please report the bug as 'compiler searching '");
long int strLen_1 = strlen(name);
long int strLen_2 = strlen("' resulting in null var'.");
;                            
                        ____BAH_COMPILER_VAR_349 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_349+currStrOff, "\e[1;31m[INTERNAL COMPILER ERROR]\e[0m\n Please report the bug as 'compiler searching '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_349+currStrOff, name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_349+currStrOff, "' resulting in null var'.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    __BAH_panic(____BAH_COMPILER_VAR_349,"/home/alois/Documents/bah-bah/src/var.bah:97");
}
if ((__checkString(v->name, "/home/alois/Documents/bah-bah/src/var.bah:99 v->name ")==1&&__checkString(name, "/home/alois/Documents/bah-bah/src/var.bah:99 name")==1&&strcmp(v->name, name) == 0)) {
struct variable* ____BAH_COMPILER_VAR_350 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_350->name = "";
____BAH_COMPILER_VAR_350->type = "";
____BAH_COMPILER_VAR_350->isConst = false;
____BAH_COMPILER_VAR_350->constVal = "";
____BAH_COMPILER_VAR_350->isArray = false;
____BAH_COMPILER_VAR_350->from = "";
____BAH_COMPILER_VAR_350->outterScope = false;
struct variable* nv =  ____BAH_COMPILER_VAR_350;
nv->type =  v->type;
nv->name =  v->name;
nv->isConst =  v->isConst;
char * r =  nv->type;
struct string tcc =  string(ogName);
if (tcc.count((struct string*)&tcc,"&")) {
char * ____BAH_COMPILER_VAR_351 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(r);
long int strLen_1 = strlen("*");
;                            
                        ____BAH_COMPILER_VAR_351 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_351+currStrOff, r, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_351+currStrOff, "*", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    r =  ____BAH_COMPILER_VAR_351;
}
long int nbUnaries =  tcc.count((struct string*)&tcc,"*");
if ((nbUnaries>0)) {
struct string ct =  string(r);
long int pointerLevel =  ct.count((struct string*)&ct,"*");
if ((pointerLevel<nbUnaries)) {
char * ____BAH_COMPILER_VAR_352 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot use '*' on ");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(" because it is not pointer.");
;                            
                        ____BAH_COMPILER_VAR_352 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_352+currStrOff, "Cannot use '*' on ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_352+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_352+currStrOff, " because it is not pointer.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    throwErr(null,____BAH_COMPILER_VAR_352);
}
ct.trimRight((struct string*)&ct,nbUnaries);
r =  ct.str((struct string*)&ct);
}
nv->type =  r;
nv->name =  ogName;
struct variable* ____BAH_COMPILER_VAR_353 = nv;
return ____BAH_COMPILER_VAR_353;
}
i =  i + 1;
};
i =  0;
while ((i<len(elems->fns))) {

                if (elems->fns->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/var.bah:132): elems->fns[%d] with length %d\n", i, elems->fns->length);
                    exit(1);
                };
                struct func* fn =  elems->fns->data[i];
if ((__checkString(fn->name, "/home/alois/Documents/bah-bah/src/var.bah:133 fn->name ")==1&&__checkString(name, "/home/alois/Documents/bah-bah/src/var.bah:133 name")==1&&strcmp(fn->name, name) == 0)) {
struct variable* ____BAH_COMPILER_VAR_354 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_354->name = "";
____BAH_COMPILER_VAR_354->type = "";
____BAH_COMPILER_VAR_354->isConst = false;
____BAH_COMPILER_VAR_354->constVal = "";
____BAH_COMPILER_VAR_354->isArray = false;
____BAH_COMPILER_VAR_354->from = "";
____BAH_COMPILER_VAR_354->outterScope = false;
struct variable* nv =  ____BAH_COMPILER_VAR_354;
nv->name =  name;
nv->type =  "function(";
long int j =  0;
while ((j<len(fn->args))) {

                if (fn->args->length <= j) {
                    printf("array (/home/alois/Documents/bah-bah/src/var.bah:138): fn->args[%d] with length %d\n", j, fn->args->length);
                    exit(1);
                };
                struct variable* arg =  fn->args->data[j];
char * ____BAH_COMPILER_VAR_355 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(nv->type);
long int strLen_1 = strlen(arg->type);
;                            
                        ____BAH_COMPILER_VAR_355 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_355+currStrOff, nv->type, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_355+currStrOff, arg->type, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    nv->type =  ____BAH_COMPILER_VAR_355;
j =  j + 1;
if ((j<len(fn->args))) {
char * ____BAH_COMPILER_VAR_356 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(nv->type);
long int strLen_1 = strlen(",");
;                            
                        ____BAH_COMPILER_VAR_356 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_356+currStrOff, nv->type, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_356+currStrOff, ",", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    nv->type =  ____BAH_COMPILER_VAR_356;
}
};
char * ____BAH_COMPILER_VAR_357 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(nv->type);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen(fn->returns->type);
;                            
                        ____BAH_COMPILER_VAR_357 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_357+currStrOff, nv->type, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_357+currStrOff, ")", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_357+currStrOff, fn->returns->type, strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    nv->type =  ____BAH_COMPILER_VAR_357;
struct variable* ____BAH_COMPILER_VAR_358 = nv;
return ____BAH_COMPILER_VAR_358;
}
i =  i + 1;
};
struct variable* ____BAH_COMPILER_VAR_359 = null;
return ____BAH_COMPILER_VAR_359;
};
char * setCType(struct variable* v,struct Elems* elems){
struct string tp =  getCType(v->type,elems);
char * t =  tp.str((struct string*)&tp);
char * ____BAH_COMPILER_VAR_360 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(t);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(v->name);
;                            
                        ____BAH_COMPILER_VAR_360 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_360+currStrOff, t, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_360+currStrOff, " ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_360+currStrOff, v->name, strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    t =  ____BAH_COMPILER_VAR_360;
char * ____BAH_COMPILER_VAR_361 = t;
return ____BAH_COMPILER_VAR_361;
};
char * getTypeFromToken(struct Tok* t,int strict,struct Elems* elems){
if ((strlen(t->bahType)>0)) {
char * r =  t->bahType;
char * ____BAH_COMPILER_VAR_362 = r;
return ____BAH_COMPILER_VAR_362;
}
if ((t->type==TOKEN_TYPE_VAR)) {
struct variable* v =  searchVar(t->cont,elems);
if ((v==null)) {
if ((strict==true)) {
throwErr(t,"Unknown var {TOKEN}.");
}
else {
char * ____BAH_COMPILER_VAR_363 = "";
return ____BAH_COMPILER_VAR_363;
}
}
if ((strict==true)) {
if ((strlen(v->type)==0)) {
throwErr(t,"Cannot use {TOKEN} because it does not have any type.");
}
}
char * r =  v->type;
char * ____BAH_COMPILER_VAR_364 = r;
return ____BAH_COMPILER_VAR_364;
}
if ((t->type==TOKEN_TYPE_FLOAT)) {
char * ____BAH_COMPILER_VAR_365 = "float";
return ____BAH_COMPILER_VAR_365;
}
if ((t->type==TOKEN_TYPE_INT)) {
char * ____BAH_COMPILER_VAR_366 = "int";
return ____BAH_COMPILER_VAR_366;
}
if ((t->type==TOKEN_TYPE_STR)) {
char * ____BAH_COMPILER_VAR_367 = "cpstring";
return ____BAH_COMPILER_VAR_367;
}
if ((t->type==TOKEN_TYPE_CHAR)) {
char * ____BAH_COMPILER_VAR_368 = "char";
return ____BAH_COMPILER_VAR_368;
}
if ((t->type==TOKEN_TYPE_BOOL)) {
char * ____BAH_COMPILER_VAR_369 = "bool";
return ____BAH_COMPILER_VAR_369;
}
throwErr(t,"Cannot use {TOKEN} as value.");
char * ____BAH_COMPILER_VAR_370 = "";
return ____BAH_COMPILER_VAR_370;
};
struct func* parseFnType(struct string cvt){
struct func* ____BAH_COMPILER_VAR_371 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_371->name = "";
____BAH_COMPILER_VAR_371->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_371->args->length = 0;
            ____BAH_COMPILER_VAR_371->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_371->returns= null;
____BAH_COMPILER_VAR_371->isBinding = false;
____BAH_COMPILER_VAR_371->from = "";
____BAH_COMPILER_VAR_371->file = "";
____BAH_COMPILER_VAR_371->line = 1;
struct func* nf =  ____BAH_COMPILER_VAR_371;
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
struct variable* ____BAH_COMPILER_VAR_372 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_372->name = "";
____BAH_COMPILER_VAR_372->type = "";
____BAH_COMPILER_VAR_372->isConst = false;
____BAH_COMPILER_VAR_372->constVal = "";
____BAH_COMPILER_VAR_372->isArray = false;
____BAH_COMPILER_VAR_372->from = "";
____BAH_COMPILER_VAR_372->outterScope = false;
struct variable* arg =  ____BAH_COMPILER_VAR_372;
char * ____BAH_COMPILER_VAR_373 =intToStr(len(nf->args));char * ____BAH_COMPILER_VAR_374 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("arg_");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_373);
;                            
                        ____BAH_COMPILER_VAR_374 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_374+currStrOff, "arg_", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_374+currStrOff, ____BAH_COMPILER_VAR_373, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    arg->name =  ____BAH_COMPILER_VAR_374;
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
struct variable* ____BAH_COMPILER_VAR_375 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_375->name = "";
____BAH_COMPILER_VAR_375->type = "";
____BAH_COMPILER_VAR_375->isConst = false;
____BAH_COMPILER_VAR_375->constVal = "";
____BAH_COMPILER_VAR_375->isArray = false;
____BAH_COMPILER_VAR_375->from = "";
____BAH_COMPILER_VAR_375->outterScope = false;
nf->returns =  ____BAH_COMPILER_VAR_375;
nf->returns->name =  "_return";
nf->returns->type =  arrToStr(memory);
struct func* ____BAH_COMPILER_VAR_376 = nf;
return ____BAH_COMPILER_VAR_376;
};
struct func* searchFunc(char * name,struct Elems* elems,int inclCurr){
char * ogName =  name;
if ((__checkString(name, "/home/alois/Documents/bah-bah/src/var.bah:250 name ")==1&&strcmp(name, "noCheck") == 0)) {
struct func* ____BAH_COMPILER_VAR_377 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_377->name = "";
____BAH_COMPILER_VAR_377->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_377->args->length = 0;
            ____BAH_COMPILER_VAR_377->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_377->returns= null;
____BAH_COMPILER_VAR_377->isBinding = false;
____BAH_COMPILER_VAR_377->from = "";
____BAH_COMPILER_VAR_377->file = "";
____BAH_COMPILER_VAR_377->line = 1;
struct func* fn =  ____BAH_COMPILER_VAR_377;
fn->name =  "noCheck";
struct func* ____BAH_COMPILER_VAR_378 = fn;
return ____BAH_COMPILER_VAR_378;
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
char * ____BAH_COMPILER_VAR_379 =fnName.str((struct string*)&fnName);struct structMemb* memb =  searchStructMemb(____BAH_COMPILER_VAR_379,s,elems);
name =  fnName.content;
char * ____BAH_COMPILER_VAR_380 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(memb->from);
long int strLen_1 = strlen("__");
long int strLen_2 = strlen(name);
;                            
                        ____BAH_COMPILER_VAR_380 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_380+currStrOff, memb->from, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_380+currStrOff, "__", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_380+currStrOff, name, strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    name =  ____BAH_COMPILER_VAR_380;
}
array(struct func*)* fns =  elems->fns;
long int i =  0;
while ((i<len(fns))) {

                if (fns->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/var.bah:276): fns[%d] with length %d\n", i, fns->length);
                    exit(1);
                };
                struct func* fn =  fns->data[i];
if ((fn==null)) {
char * ____BAH_COMPILER_VAR_381 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\e[1;31m[INTERNAL COMPILER ERROR]\e[0m\n Please report the bug as 'compiler searching '");
long int strLen_1 = strlen(name);
long int strLen_2 = strlen("' resulting in null func'.");
;                            
                        ____BAH_COMPILER_VAR_381 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_381+currStrOff, "\e[1;31m[INTERNAL COMPILER ERROR]\e[0m\n Please report the bug as 'compiler searching '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_381+currStrOff, name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_381+currStrOff, "' resulting in null func'.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    __BAH_panic(____BAH_COMPILER_VAR_381,"/home/alois/Documents/bah-bah/src/var.bah:278");
}
if ((__checkString(fn->name, "/home/alois/Documents/bah-bah/src/var.bah:280 fn->name ")==1&&__checkString(name, "/home/alois/Documents/bah-bah/src/var.bah:280 name")==1&&strcmp(fn->name, name) == 0)) {
struct func* ____BAH_COMPILER_VAR_382 = fn;
return ____BAH_COMPILER_VAR_382;
}
i =  i + 1;
};
if ((inclCurr==true)) {
if ((__checkString(currentFn->name, "/home/alois/Documents/bah-bah/src/var.bah:287 currentFn->name ")==1&&__checkString(name, "/home/alois/Documents/bah-bah/src/var.bah:287 name")==1&&strcmp(currentFn->name, name) == 0)) {
struct func* ____BAH_COMPILER_VAR_383 = currentFn;
return ____BAH_COMPILER_VAR_383;
}
}
struct variable* v =  searchVar(ogName,elems);
if ((v==null)) {
struct func* ____BAH_COMPILER_VAR_384 = null;
return ____BAH_COMPILER_VAR_384;
}
struct func* ____BAH_COMPILER_VAR_385 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_385->name = "";
____BAH_COMPILER_VAR_385->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_385->args->length = 0;
            ____BAH_COMPILER_VAR_385->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_385->returns= null;
____BAH_COMPILER_VAR_385->isBinding = false;
____BAH_COMPILER_VAR_385->from = "";
____BAH_COMPILER_VAR_385->file = "";
____BAH_COMPILER_VAR_385->line = 1;
struct func* nf =  ____BAH_COMPILER_VAR_385;
nf->name =  ogName;
struct string cvt =  string(v->type);
if ((cvt.hasPrefix((struct string*)&cvt,"function(")==0)) {
struct func* ____BAH_COMPILER_VAR_386 = null;
return ____BAH_COMPILER_VAR_386;
}
struct func* pfn =  parseFnType(cvt);
nf->returns =  pfn->returns;
nf->args =  pfn->args;
struct func* ____BAH_COMPILER_VAR_387 = nf;
return ____BAH_COMPILER_VAR_387;
};
int RCPavailable();
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
                    printf("array (/home/alois/Documents/bah-bah/src/var.bah:319): members[%d] with length %d\n", i, members->length);
                    exit(1);
                };
                struct structMemb* m =  members->data[i];
struct string cmpt =  string(m->type);
int declared =  false;
if ((strlen(m->def)>0)) {
char * ____BAH_COMPILER_VAR_388 =null;
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
                        ____BAH_COMPILER_VAR_388 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                        
                        strncpy(____BAH_COMPILER_VAR_388+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_388+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_388+currStrOff, sep, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_388+currStrOff, m->name, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_388+currStrOff, " = ", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_388+currStrOff, m->def, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_388+currStrOff, ";\n", strLen_6);
                        currStrOff += strLen_6;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_388;
declared =  true;
}
if ((cmpt.hasPrefix((struct string*)&cmpt,"[]")==1)) {
cmpt.trimLeft((struct string*)&cmpt,2);
char * cmptstr =  cmpt.str((struct string*)&cmpt);
struct string elemCType =  getCType(cmptstr,elems);
char * elemCTypeStr =  elemCType.str((struct string*)&elemCType);
char * ____BAH_COMPILER_VAR_389 =null;
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
                        ____BAH_COMPILER_VAR_389 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14 + strLen_15 + strLen_16);
                        
                        strncpy(____BAH_COMPILER_VAR_389+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_389+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_389+currStrOff, sep, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_389+currStrOff, m->name, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_389+currStrOff, " = memoryAlloc(sizeof(array(", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_389+currStrOff, elemCTypeStr, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_389+currStrOff, ")));\n            ", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_389+currStrOff, v->name, strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_389+currStrOff, sep, strLen_8);
                        currStrOff += strLen_8;
                        
                        strncpy(____BAH_COMPILER_VAR_389+currStrOff, m->name, strLen_9);
                        currStrOff += strLen_9;
                        
                        strncpy(____BAH_COMPILER_VAR_389+currStrOff, "->length = 0;\n            ", strLen_10);
                        currStrOff += strLen_10;
                        
                        strncpy(____BAH_COMPILER_VAR_389+currStrOff, v->name, strLen_11);
                        currStrOff += strLen_11;
                        
                        strncpy(____BAH_COMPILER_VAR_389+currStrOff, sep, strLen_12);
                        currStrOff += strLen_12;
                        
                        strncpy(____BAH_COMPILER_VAR_389+currStrOff, m->name, strLen_13);
                        currStrOff += strLen_13;
                        
                        strncpy(____BAH_COMPILER_VAR_389+currStrOff, "->elemSize = sizeof(", strLen_14);
                        currStrOff += strLen_14;
                        
                        strncpy(____BAH_COMPILER_VAR_389+currStrOff, elemCTypeStr, strLen_15);
                        currStrOff += strLen_15;
                        
                        strncpy(____BAH_COMPILER_VAR_389+currStrOff, ");\n            ", strLen_16);
                        currStrOff += strLen_16;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_389;
declared =  true;
}
if ((isRCPpointerType(m->type)&&(declared==false))) {
char * ____BAH_COMPILER_VAR_390 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(code);
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(sep);
long int strLen_3 = strlen(m->name);
long int strLen_4 = strlen("= null;\n");
;                            
                        ____BAH_COMPILER_VAR_390 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_390+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_390+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_390+currStrOff, sep, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_390+currStrOff, m->name, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_390+currStrOff, "= null;\n", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_390;
}
i =  i + 1;
};
if ((strlen(s->extendedFrom)>0)) {
struct cStruct* es =  searchStruct(s->extendedFrom,elems);
i =  0;
while ((i<len(es->methods))) {

                if (es->methods->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/var.bah:348): es->methods[%d] with length %d\n", i, es->methods->length);
                    exit(1);
                };
                struct func* m =  es->methods->data[i];
char * ____BAH_COMPILER_VAR_391 =null;
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
                        ____BAH_COMPILER_VAR_391 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                        
                        strncpy(____BAH_COMPILER_VAR_391+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_391+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_391+currStrOff, sep, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_391+currStrOff, m->name, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_391+currStrOff, " = ", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_391+currStrOff, es->name, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_391+currStrOff, "__", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_391+currStrOff, m->name, strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_391+currStrOff, ";\n", strLen_8);
                        currStrOff += strLen_8;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_391;
i =  i + 1;
};
}
array(struct func*)* methods =  s->methods;
i =  0;
while ((i<len(methods))) {

                if (methods->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/var.bah:356): methods[%d] with length %d\n", i, methods->length);
                    exit(1);
                };
                struct func* m =  methods->data[i];
char * ____BAH_COMPILER_VAR_392 =null;
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
                        ____BAH_COMPILER_VAR_392 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                        
                        strncpy(____BAH_COMPILER_VAR_392+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_392+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_392+currStrOff, sep, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_392+currStrOff, m->name, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_392+currStrOff, " = ", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_392+currStrOff, s->name, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_392+currStrOff, "__", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_392+currStrOff, m->name, strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_392+currStrOff, ";\n", strLen_8);
                        currStrOff += strLen_8;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_392;
i =  i + 1;
};
if ((((s->isBinding==false)&&RCPavailable())&&(s->hasRCPmemb==true))) {
if ((strCount(v->type,"*")==0)) {
char * ____BAH_COMPILER_VAR_393 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(code);
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(".__RCP_counter = malloc(sizeof(int));*(int*)");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen(".__RCP_counter = 1;\n");
;                            
                        ____BAH_COMPILER_VAR_393 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_393+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_393+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_393+currStrOff, ".__RCP_counter = malloc(sizeof(int));*(int*)", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_393+currStrOff, v->name, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_393+currStrOff, ".__RCP_counter = 1;\n", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_393;
}
else {
char * ____BAH_COMPILER_VAR_394 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(code);
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen("->__RCP_counter = RCP_request(");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen(");\n");
;                            
                        ____BAH_COMPILER_VAR_394 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_394+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_394+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_394+currStrOff, "->__RCP_counter = RCP_request(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_394+currStrOff, v->name, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_394+currStrOff, ");\n", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_394;
}
}
char * ____BAH_COMPILER_VAR_395 = code;
return ____BAH_COMPILER_VAR_395;
};
long int NB_COMP_VAR;
char * genCompilerVar(){
char * ____BAH_COMPILER_VAR_396 =intToStr(NB_COMP_VAR);char * ____BAH_COMPILER_VAR_397 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("____BAH_COMPILER_VAR_");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_396);
;                            
                        ____BAH_COMPILER_VAR_397 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_397+currStrOff, "____BAH_COMPILER_VAR_", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_397+currStrOff, ____BAH_COMPILER_VAR_396, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    char * name =  ____BAH_COMPILER_VAR_397;
NB_COMP_VAR =  NB_COMP_VAR + 1;
char * ____BAH_COMPILER_VAR_398 = name;
return ____BAH_COMPILER_VAR_398;
};
typedef array(struct variable*)* __BAH_ARR_TYPE_variable;
int varInArr(struct variable* v,__BAH_ARR_TYPE_variable arr){
if ((arr==null)) {
int ____BAH_COMPILER_VAR_399 = false;
return ____BAH_COMPILER_VAR_399;
}
long int j =  0;
while ((j<len(arr))) {

                if (arr->length <= j) {
                    printf("array (/home/alois/Documents/bah-bah/src/var.bah:385): arr[%d] with length %d\n", j, arr->length);
                    exit(1);
                };
                struct variable* ev =  arr->data[j];
if ((__checkString(ev->name, "/home/alois/Documents/bah-bah/src/var.bah:386 ev->name ")==1&&__checkString(v->name, "/home/alois/Documents/bah-bah/src/var.bah:386 v->name")==1&&strcmp(ev->name, v->name) == 0)) {
int ____BAH_COMPILER_VAR_400 = true;
return ____BAH_COMPILER_VAR_400;
}
j =  j + 1;
};
int ____BAH_COMPILER_VAR_401 = false;
return ____BAH_COMPILER_VAR_401;
};
void makeInit(){
OUTPUT =  OUTPUT->add(OUTPUT, rope("\n    void __BAH_init() {\n\n        "))->add(OUTPUT->add(OUTPUT, rope("\n    void __BAH_init() {\n\n        ")), INIT)->add(OUTPUT->add(OUTPUT, rope("\n    void __BAH_init() {\n\n        "))->add(OUTPUT->add(OUTPUT, rope("\n    void __BAH_init() {\n\n        ")), INIT), rope("\n\n    };\n    "));
};
struct rope* decrVar(struct variable* v,struct Elems* elems){
struct rope* r =  rope("");
if (strHasPrefix(v->type,"[]")) {
struct string at =  string(v->type);
at.trimLeft((struct string*)&at,2);
char * ____BAH_COMPILER_VAR_402 =at.str((struct string*)&at);if (isRCPtype(____BAH_COMPILER_VAR_402,elems)) {
struct variable* ____BAH_COMPILER_VAR_403 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_403->name = "";
____BAH_COMPILER_VAR_403->type = "";
____BAH_COMPILER_VAR_403->isConst = false;
____BAH_COMPILER_VAR_403->constVal = "";
____BAH_COMPILER_VAR_403->isArray = false;
____BAH_COMPILER_VAR_403->from = "";
____BAH_COMPILER_VAR_403->outterScope = false;
struct variable* arrElem =  ____BAH_COMPILER_VAR_403;
arrElem->type =  at.str((struct string*)&at);
char * ____BAH_COMPILER_VAR_404 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen("->data[arrElemIndex]");
;                            
                        ____BAH_COMPILER_VAR_404 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_404+currStrOff, v->name, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_404+currStrOff, "->data[arrElemIndex]", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    arrElem->name =  ____BAH_COMPILER_VAR_404;
char * ____BAH_COMPILER_VAR_405 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\n            {//////////RCP//////////\n            struct RCP * arrRCP = RCP_request(");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(");\n            if (arrRCP != null && arrRCP->c == 1) {\n                struct RCP * arrDataRCP = RCP_request(");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen("->data);\n                if (arrDataRCP != null && arrDataRCP->c == 1) {\n                    for(int arrElemIndex=len(");
long int strLen_5 = strlen(v->name);
long int strLen_6 = strlen(")-1; arrElemIndex >= 0; arrElemIndex--) {\n                        ");
;                            
                        ____BAH_COMPILER_VAR_405 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                        
                        strncpy(____BAH_COMPILER_VAR_405+currStrOff, "\n            {//////////RCP//////////\n            struct RCP * arrRCP = RCP_request(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_405+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_405+currStrOff, ");\n            if (arrRCP != null && arrRCP->c == 1) {\n                struct RCP * arrDataRCP = RCP_request(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_405+currStrOff, v->name, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_405+currStrOff, "->data);\n                if (arrDataRCP != null && arrDataRCP->c == 1) {\n                    for(int arrElemIndex=len(", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_405+currStrOff, v->name, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_405+currStrOff, ")-1; arrElemIndex >= 0; arrElemIndex--) {\n                        ", strLen_6);
                        currStrOff += strLen_6;
                        
                    }
                    r =  rope(____BAH_COMPILER_VAR_405)->add(rope(____BAH_COMPILER_VAR_405), decrVar(arrElem,elems))->add(rope(____BAH_COMPILER_VAR_405)->add(rope(____BAH_COMPILER_VAR_405), decrVar(arrElem,elems)), rope("\n                    };\n                }\n                RCP_decrRCP(arrDataRCP);\n            }\n            RCP_decrRCP(arrRCP);\n            };//////////////////////\n            "));
}
else {
char * ____BAH_COMPILER_VAR_406 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\n            {//////////RCP//////////\n            struct RCP * arrRCP = RCP_request(");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(");\n            if (arrRCP != null) {\n                if (arrRCP->c == 1) {\n                    struct RCP * arrDataRCP = RCP_request(");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen("->data);\n                    RCP_decrRCP(arrDataRCP);\n                }\n                RCP_decrRCP(arrRCP);\n            }\n            };//////////////////////\n            ");
;                            
                        ____BAH_COMPILER_VAR_406 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_406+currStrOff, "\n            {//////////RCP//////////\n            struct RCP * arrRCP = RCP_request(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_406+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_406+currStrOff, ");\n            if (arrRCP != null) {\n                if (arrRCP->c == 1) {\n                    struct RCP * arrDataRCP = RCP_request(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_406+currStrOff, v->name, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_406+currStrOff, "->data);\n                    RCP_decrRCP(arrDataRCP);\n                }\n                RCP_decrRCP(arrRCP);\n            }\n            };//////////////////////\n            ", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    r =  rope(____BAH_COMPILER_VAR_406);
}
}
else {
int isPointer =  isRCPpointerType(v->type);
struct cStruct* s =  searchStruct(v->type,elems);
if (((s!=null)&&(s->isBinding==false))) {
char * amp =  "&";
char * heap =  "0";
if ((isPointer==true)) {
amp =  "";
heap =  "1";
}
char * ____BAH_COMPILER_VAR_407 =null;
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
                        ____BAH_COMPILER_VAR_407 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7);
                        
                        strncpy(____BAH_COMPILER_VAR_407+currStrOff, "__RCP_clean_", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_407+currStrOff, s->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_407+currStrOff, "(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_407+currStrOff, amp, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_407+currStrOff, v->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_407+currStrOff, ", ", strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_407+currStrOff, heap, strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_407+currStrOff, ");\n", strLen_7);
                        currStrOff += strLen_7;
                        
                    }
                    r =  r->add(r, rope(____BAH_COMPILER_VAR_407));
}
else if ((isPointer==true)) {
char * ____BAH_COMPILER_VAR_408 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("RCP_decr(");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(");\n");
;                            
                        ____BAH_COMPILER_VAR_408 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_408+currStrOff, "RCP_decr(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_408+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_408+currStrOff, ");\n", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    r =  r->add(r, rope(____BAH_COMPILER_VAR_408));
}
}
struct rope* ____BAH_COMPILER_VAR_409 = r;
return ____BAH_COMPILER_VAR_409;
};
struct rope* incrVar(struct variable* v,struct Elems* elems){
if ((strCount(v->name,"*")>0)) {
struct rope* ____BAH_COMPILER_VAR_410 = rope("");
return ____BAH_COMPILER_VAR_410;
}
struct cStruct* s =  searchStruct(v->type,elems);
if ((((s!=null)&&(isRCPpointerType(v->type)==false))&&(s->isBinding==false))) {
char * ____BAH_COMPILER_VAR_411 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("RCP_incrCounter(");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(".__RCP_counter);");
;                            
                        ____BAH_COMPILER_VAR_411 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_411+currStrOff, "RCP_incrCounter(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_411+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_411+currStrOff, ".__RCP_counter);", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    struct rope* ____BAH_COMPILER_VAR_412 = rope(____BAH_COMPILER_VAR_411);
return ____BAH_COMPILER_VAR_412;
}
char * ____BAH_COMPILER_VAR_413 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("RCP_incr(");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(");");
;                            
                        ____BAH_COMPILER_VAR_413 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_413+currStrOff, "RCP_incr(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_413+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_413+currStrOff, ");", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    struct rope* ____BAH_COMPILER_VAR_414 = rope(____BAH_COMPILER_VAR_413);
return ____BAH_COMPILER_VAR_414;
};
int RCPavailable(){
char * ____BAH_COMPILER_VAR_415 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen("rcp.bah");
;                            
                        ____BAH_COMPILER_VAR_415 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_415+currStrOff, BAH_DIR, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_415+currStrOff, "rcp.bah", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    char * ____BAH_COMPILER_VAR_416 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen("fastrcp.bah");
;                            
                        ____BAH_COMPILER_VAR_416 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_416+currStrOff, BAH_DIR, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_416+currStrOff, "fastrcp.bah", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    int ____BAH_COMPILER_VAR_417 = (((__checkString(compilerState.currentFile, "/home/alois/Documents/bah-bah/src/mem.bah:76 compilerState.currentFile ")==1&&__checkString(____BAH_COMPILER_VAR_415, "/home/alois/Documents/bah-bah/src/mem.bah:76 ____BAH_COMPILER_VAR_415")==1&&strcmp(compilerState.currentFile, ____BAH_COMPILER_VAR_415) != 0)&&(__checkString(compilerState.currentFile, "/home/alois/Documents/bah-bah/src/mem.bah:76 compilerState.currentFile ")==1&&__checkString(____BAH_COMPILER_VAR_416, "/home/alois/Documents/bah-bah/src/mem.bah:76 ____BAH_COMPILER_VAR_416")==1&&strcmp(compilerState.currentFile, ____BAH_COMPILER_VAR_416) != 0))&&(RCPenabled==true));
return ____BAH_COMPILER_VAR_417;
};
void endRCPscope(struct Elems* elems,__BAH_ARR_TYPE_variable exc){
if ((RCPavailable()==false)) {
return;
}
long int i =  0;
while ((i<len(elems->vars))) {

                if (elems->vars->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/mem.bah:85): elems->vars[%d] with length %d\n", i, elems->vars->length);
                    exit(1);
                };
                struct variable* v =  elems->vars->data[i];
if (((v->outterScope==false)&&(isRCPtype(v->type,elems)==true))) {
if ((varInArr(v,exc)==false)) {
OUTPUT =  OUTPUT->add(OUTPUT, decrVar(v,elems));
}
}
i =  i + 1;
};
};
char * registerRCPvar(char * t,char * c,struct Elems* elems){
struct variable* ____BAH_COMPILER_VAR_419 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_419->name = "";
____BAH_COMPILER_VAR_419->type = "";
____BAH_COMPILER_VAR_419->isConst = false;
____BAH_COMPILER_VAR_419->constVal = "";
____BAH_COMPILER_VAR_419->isArray = false;
____BAH_COMPILER_VAR_419->from = "";
____BAH_COMPILER_VAR_419->outterScope = false;
struct variable* av =  ____BAH_COMPILER_VAR_419;
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
char * ____BAH_COMPILER_VAR_420 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_421 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(____BAH_COMPILER_VAR_420);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(av->name);
long int strLen_3 = strlen(" =");
long int strLen_4 = strlen(c);
long int strLen_5 = strlen(";");
;                            
                        ____BAH_COMPILER_VAR_421 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_421+currStrOff, ____BAH_COMPILER_VAR_420, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_421+currStrOff, " ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_421+currStrOff, av->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_421+currStrOff, " =", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_421+currStrOff, c, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_421+currStrOff, ";", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_421));
char * ____BAH_COMPILER_VAR_422 = av->name;
return ____BAH_COMPILER_VAR_422;
};
struct rope* makeRCPfuncFromStruct(struct cStruct* s,struct Elems* elems){
if (((s->isBinding==true)||(RCPavailable()==false))) {
struct rope* ____BAH_COMPILER_VAR_423 = rope("");
return ____BAH_COMPILER_VAR_423;
}
struct rope* decrMembs =  rope("");
long int i =  0;
while ((i<len(s->members))) {

                if (s->members->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/mem.bah:113): s->members[%d] with length %d\n", i, s->members->length);
                    exit(1);
                };
                struct structMemb* m =  s->members->data[i];
struct string rm =  string(m->type);
rm.replace((struct string*)&rm,"*","");
if (isRCPtype(m->type,elems)) {
if ((__checkString(rm.str((struct string*)&rm), "/home/alois/Documents/bah-bah/src/mem.bah:117 rm.str((struct string*)&rm) ")==1&&__checkString(s->name, "/home/alois/Documents/bah-bah/src/mem.bah:117 s->name")==1&&strcmp(rm.str((struct string*)&rm), s->name) != 0)) {
struct variable* ____BAH_COMPILER_VAR_424 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_424->name = "";
____BAH_COMPILER_VAR_424->type = "";
____BAH_COMPILER_VAR_424->isConst = false;
____BAH_COMPILER_VAR_424->constVal = "";
____BAH_COMPILER_VAR_424->isArray = false;
____BAH_COMPILER_VAR_424->from = "";
____BAH_COMPILER_VAR_424->outterScope = false;
struct variable* mv =  ____BAH_COMPILER_VAR_424;
char * ____BAH_COMPILER_VAR_425 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("e->");
long int strLen_1 = strlen(m->name);
;                            
                        ____BAH_COMPILER_VAR_425 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_425+currStrOff, "e->", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_425+currStrOff, m->name, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    mv->name =  ____BAH_COMPILER_VAR_425;
mv->type =  m->type;
decrMembs =  decrMembs->add(decrMembs, decrVar(mv,elems));
}
else {
char * ____BAH_COMPILER_VAR_426 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Strcture '");
long int strLen_1 = strlen(s->name);
long int strLen_2 = strlen("' has a self-referenced member '");
long int strLen_3 = strlen(m->name);
long int strLen_4 = strlen("'. May lead to memory leaks, recompile the program without the '-rcp' flag if memory leaks happens.");
;                            
                        ____BAH_COMPILER_VAR_426 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_426+currStrOff, "Strcture '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_426+currStrOff, s->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_426+currStrOff, "' has a self-referenced member '", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_426+currStrOff, m->name, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_426+currStrOff, "'. May lead to memory leaks, recompile the program without the '-rcp' flag if memory leaks happens.", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    throwWarning(____BAH_COMPILER_VAR_426);
char * amp =  "&";
char * heap =  "0";
if ((strCount(m->type,"*")>0)) {
amp =  "";
heap =  "1";
}
char * ____BAH_COMPILER_VAR_427 =null;
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
                        ____BAH_COMPILER_VAR_427 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                        
                        strncpy(____BAH_COMPILER_VAR_427+currStrOff, "__RCP_clean_", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_427+currStrOff, s->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_427+currStrOff, "(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_427+currStrOff, amp, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_427+currStrOff, "e->", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_427+currStrOff, m->name, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_427+currStrOff, ", ", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_427+currStrOff, heap, strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_427+currStrOff, ");\n", strLen_8);
                        currStrOff += strLen_8;
                        
                    }
                    decrMembs =  decrMembs->add(decrMembs, rope(____BAH_COMPILER_VAR_427));
}
}
i =  i + 1;
};
char * ____BAH_COMPILER_VAR_428 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("void* __RCP_clean_");
long int strLen_1 = strlen(s->name);
long int strLen_2 = strlen("(struct ");
long int strLen_3 = strlen(s->name);
long int strLen_4 = strlen("* e, int heap) {\n        if(heap == 1) {\n            struct RCP* srcp = RCP_request(e);\n            if (srcp != null) {\n                if (srcp->c == 1) {\n                    ");
;                            
                        ____BAH_COMPILER_VAR_428 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_428+currStrOff, "void* __RCP_clean_", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_428+currStrOff, s->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_428+currStrOff, "(struct ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_428+currStrOff, s->name, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_428+currStrOff, "* e, int heap) {\n        if(heap == 1) {\n            struct RCP* srcp = RCP_request(e);\n            if (srcp != null) {\n                if (srcp->c == 1) {\n                    ", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    struct rope* r =  rope(____BAH_COMPILER_VAR_428)->add(rope(____BAH_COMPILER_VAR_428), decrMembs)->add(rope(____BAH_COMPILER_VAR_428)->add(rope(____BAH_COMPILER_VAR_428), decrMembs), rope("\n                }\n                RCP_decrRCP(srcp);\n            }\n        } else if(RCP_decrCounter((void*)e->__RCP_counter)==0) {\n            "))->add(rope(____BAH_COMPILER_VAR_428)->add(rope(____BAH_COMPILER_VAR_428), decrMembs)->add(rope(____BAH_COMPILER_VAR_428)->add(rope(____BAH_COMPILER_VAR_428), decrMembs), rope("\n                }\n                RCP_decrRCP(srcp);\n            }\n        } else if(RCP_decrCounter((void*)e->__RCP_counter)==0) {\n            ")), decrMembs)->add(rope(____BAH_COMPILER_VAR_428)->add(rope(____BAH_COMPILER_VAR_428), decrMembs)->add(rope(____BAH_COMPILER_VAR_428)->add(rope(____BAH_COMPILER_VAR_428), decrMembs), rope("\n                }\n                RCP_decrRCP(srcp);\n            }\n        } else if(RCP_decrCounter((void*)e->__RCP_counter)==0) {\n            "))->add(rope(____BAH_COMPILER_VAR_428)->add(rope(____BAH_COMPILER_VAR_428), decrMembs)->add(rope(____BAH_COMPILER_VAR_428)->add(rope(____BAH_COMPILER_VAR_428), decrMembs), rope("\n                }\n                RCP_decrRCP(srcp);\n            }\n        } else if(RCP_decrCounter((void*)e->__RCP_counter)==0) {\n            ")), decrMembs), rope("\n        }\n    };\n"));
struct rope* ____BAH_COMPILER_VAR_429 = r;
return ____BAH_COMPILER_VAR_429;
};
int RCPselfRef(struct variable* v){
long int i =  0;
while ((i<len(compilerState.RCPvars))) {

                if (compilerState.RCPvars->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/mem.bah:155): compilerState.RCPvars[%d] with length %d\n", i, compilerState.RCPvars->length);
                    exit(1);
                };
                struct variable* r =  compilerState.RCPvars->data[i];
if ((__checkString(r->name, "/home/alois/Documents/bah-bah/src/mem.bah:156 r->name ")==1&&__checkString(v->name, "/home/alois/Documents/bah-bah/src/mem.bah:156 v->name")==1&&strcmp(r->name, v->name) == 0)) {
int ____BAH_COMPILER_VAR_430 = true;
return ____BAH_COMPILER_VAR_430;
}
i =  i + 1;
};
int ____BAH_COMPILER_VAR_431 = false;
return ____BAH_COMPILER_VAR_431;
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
int verboseOutGuard(){
if ((currentFn!=null)) {

                int ____BAH_COMPILER_VAR_432 = 0;
                for(int i=len(noVOfns)-1; i != -1; i--) {
                    if (noVOfns->data[i] != 0 && strcmp(noVOfns->data[i], currentFn->name) == 0) {
                        ____BAH_COMPILER_VAR_432 = 1;
                        break;
                    };
                };
                if (____BAH_COMPILER_VAR_432) {
int ____BAH_COMPILER_VAR_433 = false;
return ____BAH_COMPILER_VAR_433;
}
}
int ____BAH_COMPILER_VAR_434 = true;
return ____BAH_COMPILER_VAR_434;
};
struct verboseOutVar verboseOutTransformVar(struct variable* v,char * cont,struct Elems* elems){
struct verboseOutVar ____BAH_COMPILER_VAR_435 = {};
____BAH_COMPILER_VAR_435.markup= null;
____BAH_COMPILER_VAR_435.content= null;
struct verboseOutVar rv =  ____BAH_COMPILER_VAR_435;
char * ogCont =  cont;
if ((__checkString(v->type, "/home/alois/Documents/bah-bah/src/verboseOut.bah:32 v->type ")==1&&strcmp(v->type, "cpstring") == 0)) {
char * ____BAH_COMPILER_VAR_436 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("__Bah_safe_string(");
long int strLen_1 = strlen(cont);
long int strLen_2 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_436 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_436+currStrOff, "__Bah_safe_string(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_436+currStrOff, cont, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_436+currStrOff, ")", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    cont =  ____BAH_COMPILER_VAR_436;
}
char * ____BAH_COMPILER_VAR_437 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(", ");
long int strLen_1 = strlen(cont);
;                            
                        ____BAH_COMPILER_VAR_437 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_437+currStrOff, ", ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_437+currStrOff, cont, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    cont =  ____BAH_COMPILER_VAR_437;
char * ct =  "";
if ((__checkString(v->type, "/home/alois/Documents/bah-bah/src/verboseOut.bah:37 v->type ")==1&&strcmp(v->type, "cpstring") == 0)) {
ct =  "%s";
}
else if ((__checkString(v->type, "/home/alois/Documents/bah-bah/src/verboseOut.bah:39 v->type ")==1&&strcmp(v->type, "int") == 0)) {
ct =  "%li";
}
else if ((__checkString(v->type, "/home/alois/Documents/bah-bah/src/verboseOut.bah:41 v->type ")==1&&strcmp(v->type, "float") == 0)) {
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
char * ____BAH_COMPILER_VAR_438 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(ASCII_RESET);
long int strLen_1 = strlen("{");
;                            
                        ____BAH_COMPILER_VAR_438 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_438+currStrOff, ASCII_RESET, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_438+currStrOff, "{", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    ct =  ____BAH_COMPILER_VAR_438;
cont =  "";
long int i =  0;
for (; (i<len(s->members)); i =  i+1) {

                if (s->members->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/verboseOut.bah:53): s->members[%d] with length %d\n", i, s->members->length);
                    exit(1);
                };
                struct variable* m =  s->members->data[i];
char * ____BAH_COMPILER_VAR_439 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("(");
long int strLen_1 = strlen(ogCont);
long int strLen_2 = strlen(")");
long int strLen_3 = strlen(".");
long int strLen_4 = strlen(m->name);
;                            
                        ____BAH_COMPILER_VAR_439 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_439+currStrOff, "(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_439+currStrOff, ogCont, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_439+currStrOff, ")", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_439+currStrOff, ".", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_439+currStrOff, m->name, strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    struct verboseOutVar mv =  verboseOutTransformVar(m,____BAH_COMPILER_VAR_439,elems);
if ((i!=0)) {
char * ____BAH_COMPILER_VAR_440 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(ct);
long int strLen_1 = strlen(", ");
;                            
                        ____BAH_COMPILER_VAR_440 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_440+currStrOff, ct, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_440+currStrOff, ", ", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    ct =  ____BAH_COMPILER_VAR_440;
}
char * ____BAH_COMPILER_VAR_441 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(ct);
long int strLen_1 = strlen(mv.markup);
;                            
                        ____BAH_COMPILER_VAR_441 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_441+currStrOff, ct, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_441+currStrOff, mv.markup, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    ct =  ____BAH_COMPILER_VAR_441;
char * ____BAH_COMPILER_VAR_442 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(cont);
long int strLen_1 = strlen(mv.content);
;                            
                        ____BAH_COMPILER_VAR_442 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_442+currStrOff, cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_442+currStrOff, mv.content, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    cont =  ____BAH_COMPILER_VAR_442;
};
char * ____BAH_COMPILER_VAR_443 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(ct);
long int strLen_1 = strlen("}");
;                            
                        ____BAH_COMPILER_VAR_443 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_443+currStrOff, ct, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_443+currStrOff, "}", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    ct =  ____BAH_COMPILER_VAR_443;
}
}
char * ____BAH_COMPILER_VAR_444 =null;
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
                        ____BAH_COMPILER_VAR_444 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                        
                        strncpy(____BAH_COMPILER_VAR_444+currStrOff, ASCII_BLUE, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_444+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_444+currStrOff, ASCII_RESET, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_444+currStrOff, " = ", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_444+currStrOff, ASCII_MAGENTA, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_444+currStrOff, ct, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_444+currStrOff, ASCII_RESET, strLen_6);
                        currStrOff += strLen_6;
                        
                    }
                    rv.markup =  ____BAH_COMPILER_VAR_444;
rv.content =  cont;
struct verboseOutVar ____BAH_COMPILER_VAR_445 = rv;
return ____BAH_COMPILER_VAR_445;
};
struct verboseOutVar verboseOutTransformTok(struct Tok t,struct Elems* elems){
if (((t.type==TOKEN_TYPE_VAR)&&(t.isOper==false))) {
struct variable* v =  searchVar(t.cont,elems);
if ((v==null)) {
struct verboseOutVar ____BAH_COMPILER_VAR_446 = verboseOutTransformVar(v,t.cont,elems);
return ____BAH_COMPILER_VAR_446;
}
}
struct variable ____BAH_COMPILER_VAR_447 = {};
____BAH_COMPILER_VAR_447.name = "";
____BAH_COMPILER_VAR_447.type = "";
____BAH_COMPILER_VAR_447.isConst = false;
____BAH_COMPILER_VAR_447.constVal = "";
____BAH_COMPILER_VAR_447.isArray = false;
____BAH_COMPILER_VAR_447.from = "";
____BAH_COMPILER_VAR_447.outterScope = false;
____BAH_COMPILER_VAR_447.name = "(value)";
____BAH_COMPILER_VAR_447.type = getTypeFromToken(&t,true,elems);
struct variable v =  ____BAH_COMPILER_VAR_447;
struct verboseOutVar ____BAH_COMPILER_VAR_448 = verboseOutTransformVar(&v,t.cont,elems);
return ____BAH_COMPILER_VAR_448;
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
int hasPtr =  false;
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
char * ____BAH_COMPILER_VAR_452 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(fnArgs);
long int strLen_1 = strlen(", ");
;                            
                        ____BAH_COMPILER_VAR_452 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_452+currStrOff, fnArgs, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_452+currStrOff, ", ", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    fnArgs =  ____BAH_COMPILER_VAR_452;
}

                if (args->length <= j) {
                    printf("array (/home/alois/Documents/bah-bah/src/verboseOut.bah:120): args[%d] with length %d\n", j, args->length);
                    exit(1);
                };
                struct Tok t =  args->data[j];
struct verboseOutVar v =  verboseOutTransformVar(a,t.cont,elems);
char * ____BAH_COMPILER_VAR_453 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(fnArgs);
long int strLen_1 = strlen(v.markup);
;                            
                        ____BAH_COMPILER_VAR_453 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_453+currStrOff, fnArgs, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_453+currStrOff, v.markup, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    fnArgs =  ____BAH_COMPILER_VAR_453;
char * ____BAH_COMPILER_VAR_454 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(fnArgsValues);
long int strLen_1 = strlen(v.content);
;                            
                        ____BAH_COMPILER_VAR_454 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_454+currStrOff, fnArgsValues, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_454+currStrOff, v.content, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    fnArgsValues =  ____BAH_COMPILER_VAR_454;
};
char * ____BAH_COMPILER_VAR_455 =intToStr(lineNb);char * ____BAH_COMPILER_VAR_456 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(compilerState.currentFile);
long int strLen_1 = strlen(":");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_455);
;                            
                        ____BAH_COMPILER_VAR_456 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_456+currStrOff, compilerState.currentFile, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_456+currStrOff, ":", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_456+currStrOff, ____BAH_COMPILER_VAR_455, strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    char * line =  ____BAH_COMPILER_VAR_456;
char * ____BAH_COMPILER_VAR_457 =null;
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
                        ____BAH_COMPILER_VAR_457 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12);
                        
                        strncpy(____BAH_COMPILER_VAR_457+currStrOff, "\n    //Verbose Runtime\n        printf(\"[VO] calling: ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_457+currStrOff, nameColor, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_457+currStrOff, fn->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_457+currStrOff, ASCII_RESET, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_457+currStrOff, "(", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_457+currStrOff, fnArgs, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_457+currStrOff, ") -> ", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_457+currStrOff, ASCII_GREEN, strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_457+currStrOff, line, strLen_8);
                        currStrOff += strLen_8;
                        
                        strncpy(____BAH_COMPILER_VAR_457+currStrOff, ASCII_RESET, strLen_9);
                        currStrOff += strLen_9;
                        
                        strncpy(____BAH_COMPILER_VAR_457+currStrOff, "\\n\"", strLen_10);
                        currStrOff += strLen_10;
                        
                        strncpy(____BAH_COMPILER_VAR_457+currStrOff, fnArgsValues, strLen_11);
                        currStrOff += strLen_11;
                        
                        strncpy(____BAH_COMPILER_VAR_457+currStrOff, ");\n    //\n    ", strLen_12);
                        currStrOff += strLen_12;
                        
                    }
                    struct rope* verboseOut =  rope(____BAH_COMPILER_VAR_457);
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
char * ____BAH_COMPILER_VAR_459 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(pvo.content);
long int strLen_1 = strlen(nvo.content);
;                            
                        ____BAH_COMPILER_VAR_459 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_459+currStrOff, pvo.content, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_459+currStrOff, nvo.content, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    char * values =  ____BAH_COMPILER_VAR_459;
char * ____BAH_COMPILER_VAR_460 =intToStr(lineNb);char * ____BAH_COMPILER_VAR_461 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(compilerState.currentFile);
long int strLen_1 = strlen(":");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_460);
;                            
                        ____BAH_COMPILER_VAR_461 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_461+currStrOff, compilerState.currentFile, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_461+currStrOff, ":", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_461+currStrOff, ____BAH_COMPILER_VAR_460, strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    char * line =  ____BAH_COMPILER_VAR_461;
char * ____BAH_COMPILER_VAR_462 =null;
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
                        ____BAH_COMPILER_VAR_462 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10);
                        
                        strncpy(____BAH_COMPILER_VAR_462+currStrOff, "\n    //Verbose Runtime\n        printf(\"[VO]    oper: ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_462+currStrOff, pvo.markup, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_462+currStrOff, " AND ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_462+currStrOff, nvo.markup, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_462+currStrOff, " -> ", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_462+currStrOff, ASCII_GREEN, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_462+currStrOff, line, strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_462+currStrOff, ASCII_RESET, strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_462+currStrOff, "\\n\"", strLen_8);
                        currStrOff += strLen_8;
                        
                        strncpy(____BAH_COMPILER_VAR_462+currStrOff, values, strLen_9);
                        currStrOff += strLen_9;
                        
                        strncpy(____BAH_COMPILER_VAR_462+currStrOff, ");\n    //\n    ", strLen_10);
                        currStrOff += strLen_10;
                        
                    }
                    struct rope* verboseOut =  rope(____BAH_COMPILER_VAR_462);
if (isGlobal()) {
INIT =  INIT->add(INIT, verboseOut);
}
else {
OUTPUT =  OUTPUT->add(OUTPUT, verboseOut);
}
};
void debugLine(__BAH_ARR_TYPE_Tok line){
char * cont =  "";
long int i =  0;
while ((i<len(line))) {

                if (line->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:14): line[%d] with length %d\n", i, line->length);
                    exit(1);
                };
                struct Tok t =  line->data[i];
char * ____BAH_COMPILER_VAR_463 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(cont);
long int strLen_1 = strlen(" '");
long int strLen_2 = strlen(t.cont);
long int strLen_3 = strlen("'");
;                            
                        ____BAH_COMPILER_VAR_463 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                        
                        strncpy(____BAH_COMPILER_VAR_463+currStrOff, cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_463+currStrOff, " '", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_463+currStrOff, t.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_463+currStrOff, "'", strLen_3);
                        currStrOff += strLen_3;
                        
                    }
                    cont =  ____BAH_COMPILER_VAR_463;
i =  i + 1;
};
println(cont);
};
struct Elems* dupElems(struct Elems* elems){
struct Elems* ____BAH_COMPILER_VAR_464 = memoryAlloc(sizeof(struct Elems));
____BAH_COMPILER_VAR_464->vars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_464->vars->length = 0;
            ____BAH_COMPILER_VAR_464->vars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_464->structs = memoryAlloc(sizeof(array(struct cStruct*)));
            ____BAH_COMPILER_VAR_464->structs->length = 0;
            ____BAH_COMPILER_VAR_464->structs->elemSize = sizeof(struct cStruct*);
            ____BAH_COMPILER_VAR_464->types = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_464->types->length = 0;
            ____BAH_COMPILER_VAR_464->types->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_464->fns = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_464->fns->length = 0;
            ____BAH_COMPILER_VAR_464->fns->elemSize = sizeof(struct func*);
            struct Elems* nElems =  ____BAH_COMPILER_VAR_464;
long int j =  0;
while ((j<len(elems->vars))) {

                if (elems->vars->length <= j) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:28): elems->vars[%d] with length %d\n", j, elems->vars->length);
                    exit(1);
                };
                struct variable* v =  elems->vars->data[j];
struct variable* ____BAH_COMPILER_VAR_465 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_465->name = "";
____BAH_COMPILER_VAR_465->type = "";
____BAH_COMPILER_VAR_465->isConst = false;
____BAH_COMPILER_VAR_465->constVal = "";
____BAH_COMPILER_VAR_465->isArray = false;
____BAH_COMPILER_VAR_465->from = "";
____BAH_COMPILER_VAR_465->outterScope = false;
struct variable* nv =  ____BAH_COMPILER_VAR_465;
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
j =  j + 1;
};
j =  0;
while ((j<len(elems->structs))) {

                if (elems->structs->length <= j) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:38): elems->structs[%d] with length %d\n", j, elems->structs->length);
                    exit(1);
                };
                struct cStruct* s =  elems->structs->data[j];
struct cStruct* ____BAH_COMPILER_VAR_466 = memoryAlloc(sizeof(struct cStruct));
____BAH_COMPILER_VAR_466->name = "";
____BAH_COMPILER_VAR_466->members = memoryAlloc(sizeof(array(struct structMemb*)));
            ____BAH_COMPILER_VAR_466->members->length = 0;
            ____BAH_COMPILER_VAR_466->members->elemSize = sizeof(struct structMemb*);
            ____BAH_COMPILER_VAR_466->methods = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_466->methods->length = 0;
            ____BAH_COMPILER_VAR_466->methods->elemSize = sizeof(struct func*);
            ____BAH_COMPILER_VAR_466->postCode = "";
____BAH_COMPILER_VAR_466->extendedFrom = "";
____BAH_COMPILER_VAR_466->isBinding = false;
____BAH_COMPILER_VAR_466->hasRCPmemb = false;
struct cStruct* ns =  ____BAH_COMPILER_VAR_466;
*ns =  *s;

{
long nLength = j;
if (nElems->structs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nElems->structs->data, (nLength+50)*sizeof(struct cStruct*));
nElems->structs->data = newPtr;
}
nElems->structs->data[j] =  ns;
nElems->structs->length = nLength+1;
} else {
nElems->structs->data[j] =  ns;
}
};
j =  j + 1;
};
j =  0;
while ((j<len(elems->types))) {

                if (elems->types->length <= j) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:47): elems->types[%d] with length %d\n", j, elems->types->length);
                    exit(1);
                };
                char * t =  elems->types->data[j];
char * nt =  t;

{
long nLength = j;
if (nElems->types->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nElems->types->data, (nLength+50)*sizeof(char *));
nElems->types->data = newPtr;
}
nElems->types->data[j] =  nt;
nElems->types->length = nLength+1;
} else {
nElems->types->data[j] =  nt;
}
};
j =  j + 1;
};
j =  0;
while ((j<len(elems->fns))) {

                if (elems->fns->length <= j) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:55): elems->fns[%d] with length %d\n", j, elems->fns->length);
                    exit(1);
                };
                struct func* f =  elems->fns->data[j];
struct func* ____BAH_COMPILER_VAR_467 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_467->name = "";
____BAH_COMPILER_VAR_467->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_467->args->length = 0;
            ____BAH_COMPILER_VAR_467->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_467->returns= null;
____BAH_COMPILER_VAR_467->isBinding = false;
____BAH_COMPILER_VAR_467->from = "";
____BAH_COMPILER_VAR_467->file = "";
____BAH_COMPILER_VAR_467->line = 1;
struct func* nf =  ____BAH_COMPILER_VAR_467;
*nf =  *f;

{
long nLength = j;
if (nElems->fns->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nElems->fns->data, (nLength+50)*sizeof(struct func*));
nElems->fns->data = newPtr;
}
nElems->fns->data[j] =  nf;
nElems->fns->length = nLength+1;
} else {
nElems->fns->data[j] =  nf;
}
};
j =  j + 1;
};
struct Elems* ____BAH_COMPILER_VAR_468 = nElems;
return ____BAH_COMPILER_VAR_468;
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
lineType prevLine;
lineType getLineType(__BAH_ARR_TYPE_Tok line){

                if (line->length <= 0) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:89): line[%d] with length %d\n", 0, line->length);
                    exit(1);
                };
                struct Tok ft =  line->data[0];
if ((ft.type==TOKEN_TYPE_FUNC)) {
lineType ____BAH_COMPILER_VAR_469 = LINE_TYPE_FN_CALL;
return ____BAH_COMPILER_VAR_469;
}
if ((ft.type==TOKEN_TYPE_KEYWORD)) {
if ((__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:95 ft.cont ")==1&&strcmp(ft.cont, "#include") == 0)) {
lineType ____BAH_COMPILER_VAR_470 = LINE_TYPE_INCLUDE;
return ____BAH_COMPILER_VAR_470;
}
else if ((__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:97 ft.cont ")==1&&strcmp(ft.cont, "#define") == 0)) {
lineType ____BAH_COMPILER_VAR_471 = LINE_TYPE_DEFINE;
return ____BAH_COMPILER_VAR_471;
}
else if ((__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:99 ft.cont ")==1&&strcmp(ft.cont, "const") == 0)) {
lineType ____BAH_COMPILER_VAR_472 = LINE_TYPE_CONST;
return ____BAH_COMPILER_VAR_472;
}
else if ((__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:101 ft.cont ")==1&&strcmp(ft.cont, "struct") == 0)) {
lineType ____BAH_COMPILER_VAR_473 = LINE_TYPE_STRUCT;
return ____BAH_COMPILER_VAR_473;
}
else if ((__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:103 ft.cont ")==1&&strcmp(ft.cont, "#cLib") == 0)) {
lineType ____BAH_COMPILER_VAR_474 = LINE_TYPE_CLIB;
return ____BAH_COMPILER_VAR_474;
}
else if ((__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:105 ft.cont ")==1&&strcmp(ft.cont, "return") == 0)) {
lineType ____BAH_COMPILER_VAR_475 = LINE_TYPE_RETURN;
return ____BAH_COMPILER_VAR_475;
}
else if ((__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:107 ft.cont ")==1&&strcmp(ft.cont, "if") == 0)) {
lineType ____BAH_COMPILER_VAR_476 = LINE_TYPE_IF;
return ____BAH_COMPILER_VAR_476;
}
else if ((__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:109 ft.cont ")==1&&strcmp(ft.cont, "else") == 0)) {
lineType ____BAH_COMPILER_VAR_477 = LINE_TYPE_ELSE;
return ____BAH_COMPILER_VAR_477;
}
else if ((__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:111 ft.cont ")==1&&strcmp(ft.cont, "#macro") == 0)) {
lineType ____BAH_COMPILER_VAR_478 = LINE_TYPE_MACRO;
return ____BAH_COMPILER_VAR_478;
}
else if ((__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:113 ft.cont ")==1&&strcmp(ft.cont, "for") == 0)) {
lineType ____BAH_COMPILER_VAR_479 = LINE_TYPE_FOR;
return ____BAH_COMPILER_VAR_479;
}
else if ((__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:115 ft.cont ")==1&&strcmp(ft.cont, "async") == 0)) {
lineType ____BAH_COMPILER_VAR_480 = LINE_TYPE_ASYNC;
return ____BAH_COMPILER_VAR_480;
}
else if (((__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:117 ft.cont ")==1&&strcmp(ft.cont, "continue") == 0)||(__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:117 ft.cont ")==1&&strcmp(ft.cont, "break") == 0))) {
lineType ____BAH_COMPILER_VAR_481 = LINE_TYPE_FOR_OPERATOR;
return ____BAH_COMPILER_VAR_481;
}
else {
lineType ____BAH_COMPILER_VAR_482 = LINE_TYPE_PRE_KEYWORD;
return ____BAH_COMPILER_VAR_482;
}
}
else if ((ft.type==TOKEN_TYPE_VAR)) {
if ((len(line)==1)) {
throwErr(&ft,"Cannot declare var {TOKEN} without a type.");
}

                if (line->length <= 1) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:126): line[%d] with length %d\n", 1, line->length);
                    exit(1);
                };
                struct Tok st =  line->data[1];
if (((st.type==TOKEN_TYPE_ENCL)&&(__checkString(st.cont, "/home/alois/Documents/bah-bah/src/parser.bah:127 st.cont ")==1&&strcmp(st.cont, "(") == 0))) {

                if (line->length <= len(line)-1) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:128): line[%d] with length %d\n", len(line)-1, line->length);
                    exit(1);
                };
                struct Tok lt =  line->data[len(line)-1];
if (((lt.type==TOKEN_TYPE_ENCL)&&(__checkString(lt.cont, "/home/alois/Documents/bah-bah/src/parser.bah:129 lt.cont ")==1&&strcmp(lt.cont, "}") == 0))) {
lineType ____BAH_COMPILER_VAR_483 = LINE_TYPE_FN_DECL;
return ____BAH_COMPILER_VAR_483;
}
lineType ____BAH_COMPILER_VAR_484 = LINE_TYPE_FN_CALL;
return ____BAH_COMPILER_VAR_484;
}
lineType ____BAH_COMPILER_VAR_485 = LINE_TYPE_VAR;
return ____BAH_COMPILER_VAR_485;
}
lineType ____BAH_COMPILER_VAR_486 = (lineType)-1;
return ____BAH_COMPILER_VAR_486;
};
__BAH_ARR_TYPE_Tok parseCast(__BAH_ARR_TYPE_Tok line,struct Elems* elems){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
long int i =  0;
while ((i<len(line))) {

                if (line->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:148): line[%d] with length %d\n", i, line->length);
                    exit(1);
                };
                struct Tok t =  line->data[i];
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:149 t.cont ")==1&&strcmp(t.cont, "<") == 0)) {
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
array(struct Tok)* ____BAH_COMPILER_VAR_487 = line;
return ____BAH_COMPILER_VAR_487;
}
while ((i<len(line))) {

                if (line->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:160): line[%d] with length %d\n", i, line->length);
                    exit(1);
                };
                struct Tok t =  line->data[i];
if ((t.type==TOKEN_TYPE_SYNTAX)) {
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:162 t.cont ")==1&&strcmp(t.cont, "<") == 0)) {
long int max =  i + 3;
if ((max<len(line))) {

                if (line->length <= i + 1) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:165): line[%d] with length %d\n", i + 1, line->length);
                    exit(1);
                };
                struct Tok nt =  line->data[i + 1];

                if (line->length <= i + 2) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:166): line[%d] with length %d\n", i + 2, line->length);
                    exit(1);
                };
                struct Tok nnt =  line->data[i + 2];

                if (line->length <= i + 3) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:167): line[%d] with length %d\n", i + 3, line->length);
                    exit(1);
                };
                struct Tok nnnt =  line->data[i + 3];
if ((nt.type==TOKEN_TYPE_VAR)) {
if ((nnt.type==TOKEN_TYPE_SYNTAX)) {
if ((__checkString(nnt.cont, "/home/alois/Documents/bah-bah/src/parser.bah:170 nnt.cont ")==1&&strcmp(nnt.cont, ">") == 0)) {
nnnt.bahType =  nt.cont;
struct string cCast =  getCType(nt.cont,elems);
char * cCastStr =  cCast.str((struct string*)&cCast);
char * ____BAH_COMPILER_VAR_488 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("(");
long int strLen_1 = strlen(cCastStr);
long int strLen_2 = strlen(")");
long int strLen_3 = strlen(nnnt.cont);
;                            
                        ____BAH_COMPILER_VAR_488 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                        
                        strncpy(____BAH_COMPILER_VAR_488+currStrOff, "(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_488+currStrOff, cCastStr, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_488+currStrOff, ")", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_488+currStrOff, nnnt.cont, strLen_3);
                        currStrOff += strLen_3;
                        
                    }
                    nnnt.cont =  ____BAH_COMPILER_VAR_488;

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
i =  i + 4;
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
i =  i + 1;
};
array(struct Tok)* ____BAH_COMPILER_VAR_489 = nl;
return ____BAH_COMPILER_VAR_489;
};
char * getDirFromFile(char * f){
char * ____BAH_COMPILER_VAR_490 =__STR(f);array(char)* p =  strAsArr(____BAH_COMPILER_VAR_490);
long int i =  len(p)-1;
while ((i>=0)) {

                if (p->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:197): p[%d] with length %d\n", i, p->length);
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
char * ____BAH_COMPILER_VAR_491 = "";
return ____BAH_COMPILER_VAR_491;
}
char * ____BAH_COMPILER_VAR_492 = arrAsStr(p);
return ____BAH_COMPILER_VAR_492;
};
void parseLines(__BAH_ARR_TYPE_Tok ts,struct Elems* elems);
int includeFile(char * ccstr,struct Elems* elems){
if ((__checkString(ccstr, "/home/alois/Documents/bah-bah/src/parser.bah:215 ccstr ")==1&&strcmp(ccstr, "BAH_MEM_COLLECTOR") == 0)) {
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
array(char *)* includes =  compilerState.includes;
long int i =  0;
while ((i<len(includes))) {

                if (includes->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:229): includes[%d] with length %d\n", i, includes->length);
                    exit(1);
                };
                if ((__checkString(includes->data[i], "/home/alois/Documents/bah-bah/src/parser.bah:229 includes->data[i] ")==1&&__checkString(ccstr, "/home/alois/Documents/bah-bah/src/parser.bah:229 ccstr")==1&&strcmp(includes->data[i], ccstr) == 0)) {
int ____BAH_COMPILER_VAR_493 = true;
return ____BAH_COMPILER_VAR_493;
}
i =  i + 1;
};
struct fileMap ____BAH_COMPILER_VAR_494 = {};
____BAH_COMPILER_VAR_494.handle = -1;
____BAH_COMPILER_VAR_494.p= null;
____BAH_COMPILER_VAR_494.open = fileMap__open;
____BAH_COMPILER_VAR_494.isValid = fileMap__isValid;
____BAH_COMPILER_VAR_494.close = fileMap__close;
struct fileMap fm =  ____BAH_COMPILER_VAR_494;
char * ____BAH_COMPILER_VAR_495 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen(ccstr);
;                            
                        ____BAH_COMPILER_VAR_495 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_495+currStrOff, BAH_DIR, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_495+currStrOff, ccstr, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    char * fileName =  ____BAH_COMPILER_VAR_495;
int isBahDir =  true;
char * f =  fm.open((struct fileMap*)&fm,fileName);
if ((fm.isValid((struct fileMap*)&fm)==0)) {
char * ____BAH_COMPILER_VAR_496 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(compilerState.currentDir);
long int strLen_1 = strlen(ccstr);
;                            
                        ____BAH_COMPILER_VAR_496 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_496+currStrOff, compilerState.currentDir, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_496+currStrOff, ccstr, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    fileName =  absPath(____BAH_COMPILER_VAR_496);
f =  fm.open((struct fileMap*)&fm,fileName);
isBahDir =  false;
if ((fm.isValid((struct fileMap*)&fm)==0)) {
int ____BAH_COMPILER_VAR_497 = false;
return ____BAH_COMPILER_VAR_497;
}
}
char * oDir =  compilerState.currentDir;
if ((isBahDir==false)) {
char * ____BAH_COMPILER_VAR_498 =getDirFromFile(ccstr);char * ____BAH_COMPILER_VAR_499 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(compilerState.currentDir);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_498);
;                            
                        ____BAH_COMPILER_VAR_499 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_499+currStrOff, compilerState.currentDir, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_499+currStrOff, ____BAH_COMPILER_VAR_498, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    compilerState.currentDir =  ____BAH_COMPILER_VAR_499;
}
else {
char * ____BAH_COMPILER_VAR_500 =getDirFromFile(ccstr);char * ____BAH_COMPILER_VAR_501 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_500);
;                            
                        ____BAH_COMPILER_VAR_501 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_501+currStrOff, BAH_DIR, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_501+currStrOff, ____BAH_COMPILER_VAR_500, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    compilerState.currentDir =  ____BAH_COMPILER_VAR_501;
}
char * oFile =  compilerState.currentFile;
compilerState.currentFile =  fileName;

{
long nLength = len(includes);
if (includes->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(includes->data, (nLength+50)*sizeof(char *));
includes->data = newPtr;
}
includes->data[len(includes)] =  ccstr;
includes->length = nLength+1;
} else {
includes->data[len(includes)] =  ccstr;
}
};
array(struct Tok)* tokens =  lexer(f);
fm.close((struct fileMap*)&fm);
if ((len(tokens)==0)) {
char * ____BAH_COMPILER_VAR_502 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("File '");
long int strLen_1 = strlen(ccstr);
long int strLen_2 = strlen("' not recognized.");
;                            
                        ____BAH_COMPILER_VAR_502 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_502+currStrOff, "File '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_502+currStrOff, ccstr, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_502+currStrOff, "' not recognized.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    __BAH_panic(____BAH_COMPILER_VAR_502,"/home/alois/Documents/bah-bah/src/parser.bah:258");
}
parseLines(tokens,elems);
compilerState.currentFile =  oFile;
compilerState.currentDir =  oDir;
int ____BAH_COMPILER_VAR_503 = true;
return ____BAH_COMPILER_VAR_503;
};
void parseInclude(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
if ((len(l)>2)) {
throwErr(&l->data[len(l)-1],"Invalid usage of include, ending by {TOKEN}.");
}

                if (l->length <= 1) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:272): l[%d] with length %d\n", 1, l->length);
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
char * ____BAH_COMPILER_VAR_504 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("#include ");
long int strLen_1 = strlen(sc);
long int strLen_2 = strlen("\n");
;                            
                        ____BAH_COMPILER_VAR_504 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_504+currStrOff, "#include ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_504+currStrOff, sc, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_504+currStrOff, "\n", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_504));

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
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:293): line[%d] with length %d\n", 0, line->length);
                    exit(1);
                };
                array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 1;
nl->elemSize = sizeof(struct Tok);
nl->data = memoryAlloc(sizeof(struct Tok) * 50);nl->data[0] = line->data[0];

                if (line->length <= 0) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:295): line[%d] with length %d\n", 0, line->length);
                    exit(1);
                };
                array(struct Tok)* unNestedLine = memoryAlloc(sizeof(array(struct Tok)));

unNestedLine->length = 1;
unNestedLine->elemSize = sizeof(struct Tok);
unNestedLine->data = memoryAlloc(sizeof(struct Tok) * 50);unNestedLine->data[0] = line->data[0];
long int i =  1;
for (; (i<len(line)); i =  i+1) {

                if (line->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:297): line[%d] with length %d\n", i, line->length);
                    exit(1);
                };
                struct Tok t =  line->data[i];
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:298 t.cont ")==1&&strcmp(t.cont, "(") == 0)) {
long int nbPars =  1;
i =  i+1;
array(struct Tok)* mem = memoryAlloc(sizeof(array(struct Tok)));

mem->length = 0;
mem->elemSize = sizeof(struct Tok);
struct Tok ft =  t;
for (; (i<len(line)); i =  i+1) {

                if (line->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:304): line[%d] with length %d\n", i, line->length);
                    exit(1);
                };
                t =  line->data[i];
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:305 t.cont ")==1&&strcmp(t.cont, "(") == 0)) {
nbPars =  nbPars+1;
}
else if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:307 t.cont ")==1&&strcmp(t.cont, ")") == 0)) {
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
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:322): tmpL[%d] with length %d\n", 0, tmpL->length);
                    exit(1);
                };
                struct Tok nestedT =  tmpL->data[0];
char * ____BAH_COMPILER_VAR_505 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("(");
long int strLen_1 = strlen(nestedT.cont);
long int strLen_2 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_505 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_505+currStrOff, "(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_505+currStrOff, nestedT.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_505+currStrOff, ")", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    nestedT.cont =  ____BAH_COMPILER_VAR_505;

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
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:332): line[%d] with length %d\n", i, line->length);
                    exit(1);
                };
                struct Tok t =  line->data[i];
if (((t.type==TOKEN_TYPE_SYNTAX)&&inArrayStr(t.cont,signs))) {
if ((i + 1>=len(line))) {
throwErr(&t,"Cannot use {TOKEN} on nothing.");
}

                if (nl->length <= len(nl)-1) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:337): nl[%d] with length %d\n", len(nl)-1, nl->length);
                    exit(1);
                };
                struct Tok pt =  nl->data[len(nl)-1];

                if (line->length <= i + 1) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:338): line[%d] with length %d\n", i + 1, line->length);
                    exit(1);
                };
                struct Tok nt =  line->data[i + 1];
if ((((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:339 t.cont ")==1&&strcmp(t.cont, "-") == 0)&&(pt.isValue==false))&&(nt.type==TOKEN_TYPE_INT))) {
char * ____BAH_COMPILER_VAR_506 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(nt.cont);
;                            
                        ____BAH_COMPILER_VAR_506 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_506+currStrOff, t.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_506+currStrOff, nt.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    nt.cont =  ____BAH_COMPILER_VAR_506;

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
if (((nt.type==TOKEN_TYPE_SYNTAX)&&(__checkString(nt.cont, "/home/alois/Documents/bah-bah/src/parser.bah:346 nt.cont ")==1&&__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:346 t.cont")==1&&strcmp(nt.cont, t.cont) == 0))) {
char * ____BAH_COMPILER_VAR_507 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(nt.cont);
;                            
                        ____BAH_COMPILER_VAR_507 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_507+currStrOff, t.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_507+currStrOff, nt.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    char * c =  ____BAH_COMPILER_VAR_507;
long int tl =  t.line;
long int tp =  t.pos;
struct Tok ____BAH_COMPILER_VAR_508 = {};
____BAH_COMPILER_VAR_508.cont = "";
____BAH_COMPILER_VAR_508.ogCont = "";
____BAH_COMPILER_VAR_508.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_508.pos = 0;
____BAH_COMPILER_VAR_508.line = 1;
____BAH_COMPILER_VAR_508.begLine = 1;
____BAH_COMPILER_VAR_508.bahType = "";
____BAH_COMPILER_VAR_508.isValue = false;
____BAH_COMPILER_VAR_508.isFunc = false;
____BAH_COMPILER_VAR_508.isOper = false;
____BAH_COMPILER_VAR_508.cont = c;
____BAH_COMPILER_VAR_508.ogCont = c;
____BAH_COMPILER_VAR_508.isValue = false;
____BAH_COMPILER_VAR_508.line = tl;
____BAH_COMPILER_VAR_508.pos = tp;
____BAH_COMPILER_VAR_508.type = TOKEN_TYPE_SYNTAX;
struct Tok tmpT =  ____BAH_COMPILER_VAR_508;

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
char * ____BAH_COMPILER_VAR_509 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(ntt);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(ptt);
long int strLen_4 = strlen(".");
;                            
                        ____BAH_COMPILER_VAR_509 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_509+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_509+currStrOff, ntt, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_509+currStrOff, ") as ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_509+currStrOff, ptt, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_509+currStrOff, ".", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    throwErr(&nt,____BAH_COMPILER_VAR_509);
}
t.isValue =  true;
if (((verboseRuntime==true)&&(ltp!=LINE_TYPE_ELSE))) {
if ((isRCPpointerType(ntt)||isRCPpointerType(ptt))) {
verboseOutOper(pt,nt,pt.line,elems);
}
}
if (compTypes(ptt,"cpstring")) {
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:377 t.cont ")==1&&strcmp(t.cont, "+") != 0)) {
throwErr(&t,"Can only do concatenation (+) on cpstrings, not {TOKEN}.");
}
long int j =  i - 1;
int wasAdd =  true;
array(char *)* strConts = memoryAlloc(sizeof(array(char *)));

strConts->length = 0;
strConts->elemSize = sizeof(char *);
while ((j<len(line))) {

                if (line->length <= j) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:384): line[%d] with length %d\n", j, line->length);
                    exit(1);
                };
                struct Tok strAddTk =  line->data[j];
if ((wasAdd==false)) {
if ((__checkString(strAddTk.cont, "/home/alois/Documents/bah-bah/src/parser.bah:386 strAddTk.cont ")==1&&strcmp(strAddTk.cont, "+") != 0)) {
break;
}
wasAdd =  true;
}
else {
char * strAddTkT =  getTypeFromToken(&strAddTk,true,elems);
if ((compTypes(strAddTkT,"cpstring")==false)) {
char * ____BAH_COMPILER_VAR_510 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(ntt);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(ptt);
long int strLen_4 = strlen(".");
;                            
                        ____BAH_COMPILER_VAR_510 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_510+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_510+currStrOff, ntt, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_510+currStrOff, ") as ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_510+currStrOff, ptt, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_510+currStrOff, ".", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    throwErr(&strAddTkT,____BAH_COMPILER_VAR_510);
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
j =  j + 1;
};
i =  j;
char * rstr =  registerRCPvar("cpstring","null",elems);
char * lens =  "";
char * totStrLen =  "1";
j =  0;
while ((j<len(strConts))) {
char * js =  intToStr(j);

                if (strConts->length <= j) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:415): strConts[%d] with length %d\n", j, strConts->length);
                    exit(1);
                };
                char * ____BAH_COMPILER_VAR_511 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(lens);
long int strLen_1 = strlen("long int strLen_");
long int strLen_2 = strlen(js);
long int strLen_3 = strlen(" = strlen(");
long int strLen_4 = strlen(strConts->data[j]);
long int strLen_5 = strlen(");\n");
;                            
                        ____BAH_COMPILER_VAR_511 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_511+currStrOff, lens, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_511+currStrOff, "long int strLen_", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_511+currStrOff, js, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_511+currStrOff, " = strlen(", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_511+currStrOff, strConts->data[j], strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_511+currStrOff, ");\n", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    lens =  ____BAH_COMPILER_VAR_511;
char * ____BAH_COMPILER_VAR_512 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(totStrLen);
long int strLen_1 = strlen(" + strLen_");
long int strLen_2 = strlen(js);
;                            
                        ____BAH_COMPILER_VAR_512 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_512+currStrOff, totStrLen, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_512+currStrOff, " + strLen_", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_512+currStrOff, js, strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    totStrLen =  ____BAH_COMPILER_VAR_512;
j =  j + 1;
};
struct rope* cats =  rope("");
j =  0;
while ((j<len(strConts))) {
char * js =  intToStr(j);

                if (strConts->length <= j) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:423): strConts[%d] with length %d\n", j, strConts->length);
                    exit(1);
                };
                char * ____BAH_COMPILER_VAR_513 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\n                        strncpy(");
long int strLen_1 = strlen(rstr);
long int strLen_2 = strlen("+currStrOff, ");
long int strLen_3 = strlen(strConts->data[j]);
long int strLen_4 = strlen(", strLen_");
long int strLen_5 = strlen(js);
long int strLen_6 = strlen(");\n                        currStrOff += strLen_");
long int strLen_7 = strlen(js);
long int strLen_8 = strlen(";\n                        ");
;                            
                        ____BAH_COMPILER_VAR_513 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                        
                        strncpy(____BAH_COMPILER_VAR_513+currStrOff, "\n                        strncpy(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_513+currStrOff, rstr, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_513+currStrOff, "+currStrOff, ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_513+currStrOff, strConts->data[j], strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_513+currStrOff, ", strLen_", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_513+currStrOff, js, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_513+currStrOff, ");\n                        currStrOff += strLen_", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_513+currStrOff, js, strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_513+currStrOff, ";\n                        ", strLen_8);
                        currStrOff += strLen_8;
                        
                    }
                    cats =  cats->add(cats, rope(____BAH_COMPILER_VAR_513));
j =  j + 1;
};
char * ____BAH_COMPILER_VAR_514 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\n                    {\n                        long int currStrOff = 0;\n                        ");
long int strLen_1 = strlen(lens);
long int strLen_2 = strlen(";                            \n                        ");
long int strLen_3 = strlen(rstr);
long int strLen_4 = strlen(" = memoryAllocSTR(");
long int strLen_5 = strlen(totStrLen);
long int strLen_6 = strlen(");\n                        ");
;                            
                        ____BAH_COMPILER_VAR_514 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                        
                        strncpy(____BAH_COMPILER_VAR_514+currStrOff, "\n                    {\n                        long int currStrOff = 0;\n                        ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_514+currStrOff, lens, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_514+currStrOff, ";                            \n                        ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_514+currStrOff, rstr, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_514+currStrOff, " = memoryAllocSTR(", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_514+currStrOff, totStrLen, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_514+currStrOff, ");\n                        ", strLen_6);
                        currStrOff += strLen_6;
                        
                    }
                    struct rope* res =  rope(____BAH_COMPILER_VAR_514)->add(rope(____BAH_COMPILER_VAR_514), cats)->add(rope(____BAH_COMPILER_VAR_514)->add(rope(____BAH_COMPILER_VAR_514), cats), rope("\n                    }\n                    "));
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
if ((((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:468 t.cont ")==1&&strcmp(t.cont, "+") == 0)&&(addMthd!=null))&&(addMthd->isFn==true))) {
char * ____BAH_COMPILER_VAR_515 =null;
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
                        ____BAH_COMPILER_VAR_515 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7);
                        
                        strncpy(____BAH_COMPILER_VAR_515+currStrOff, pt.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_515+currStrOff, sep, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_515+currStrOff, "add(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_515+currStrOff, amp, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_515+currStrOff, pt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_515+currStrOff, ", ", strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_515+currStrOff, nt.cont, strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_515+currStrOff, ")", strLen_7);
                        currStrOff += strLen_7;
                        
                    }
                    t.cont =  ____BAH_COMPILER_VAR_515;
}
else if ((((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:470 t.cont ")==1&&strcmp(t.cont, "-") == 0)&&(subMthd!=null))&&(subMthd->isFn==true))) {
char * ____BAH_COMPILER_VAR_516 =null;
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
                        ____BAH_COMPILER_VAR_516 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7);
                        
                        strncpy(____BAH_COMPILER_VAR_516+currStrOff, pt.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_516+currStrOff, sep, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_516+currStrOff, "sub(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_516+currStrOff, amp, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_516+currStrOff, pt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_516+currStrOff, ", ", strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_516+currStrOff, nt.cont, strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_516+currStrOff, ")", strLen_7);
                        currStrOff += strLen_7;
                        
                    }
                    t.cont =  ____BAH_COMPILER_VAR_516;
}
else if ((((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:472 t.cont ")==1&&strcmp(t.cont, "*") == 0)&&(multMthd!=null))&&(multMthd->isFn==true))) {
char * ____BAH_COMPILER_VAR_517 =null;
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
                        ____BAH_COMPILER_VAR_517 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7);
                        
                        strncpy(____BAH_COMPILER_VAR_517+currStrOff, pt.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_517+currStrOff, sep, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_517+currStrOff, "mult(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_517+currStrOff, amp, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_517+currStrOff, pt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_517+currStrOff, ", ", strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_517+currStrOff, nt.cont, strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_517+currStrOff, ")", strLen_7);
                        currStrOff += strLen_7;
                        
                    }
                    t.cont =  ____BAH_COMPILER_VAR_517;
}
else if ((((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:474 t.cont ")==1&&strcmp(t.cont, "/") == 0)&&(divMthd!=null))&&(divMthd->isFn==true))) {
char * ____BAH_COMPILER_VAR_518 =null;
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
                        ____BAH_COMPILER_VAR_518 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7);
                        
                        strncpy(____BAH_COMPILER_VAR_518+currStrOff, pt.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_518+currStrOff, sep, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_518+currStrOff, "div(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_518+currStrOff, amp, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_518+currStrOff, pt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_518+currStrOff, ", ", strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_518+currStrOff, nt.cont, strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_518+currStrOff, ")", strLen_7);
                        currStrOff += strLen_7;
                        
                    }
                    t.cont =  ____BAH_COMPILER_VAR_518;
}
else {
char * ____BAH_COMPILER_VAR_519 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Undefined operation on {TOKEN} (");
long int strLen_1 = strlen(ptt);
long int strLen_2 = strlen(").");
;                            
                        ____BAH_COMPILER_VAR_519 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_519+currStrOff, "Undefined operation on {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_519+currStrOff, ptt, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_519+currStrOff, ").", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    throwErr(&pt,____BAH_COMPILER_VAR_519);
}
}
else {
char * ____BAH_COMPILER_VAR_520 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(t.cont);
long int strLen_3 = strlen(" ");
long int strLen_4 = strlen(nt.cont);
;                            
                        ____BAH_COMPILER_VAR_520 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_520+currStrOff, pt.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_520+currStrOff, " ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_520+currStrOff, t.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_520+currStrOff, " ", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_520+currStrOff, nt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    t.cont =  ____BAH_COMPILER_VAR_520;
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
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:494): nl[%d] with length %d\n", len(nl)-1, nl->length);
                    exit(1);
                };
                struct Tok pt =  nl->data[len(nl)-1];
if ((pt.isValue==true)) {
char * ptt =  getTypeFromToken(&pt,true,elems);
char * ntt =  getTypeFromToken(&t,true,elems);
if ((compTypes(ptt,ntt)==false)) {
char * ____BAH_COMPILER_VAR_521 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(ntt);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(ptt);
long int strLen_4 = strlen(".");
;                            
                        ____BAH_COMPILER_VAR_521 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_521+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_521+currStrOff, ntt, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_521+currStrOff, ") as ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_521+currStrOff, ptt, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_521+currStrOff, ".", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    throwErr(&t,____BAH_COMPILER_VAR_521);
}
t.type =  TOKEN_TYPE_VAR;
t.isOper =  true;
char * ____BAH_COMPILER_VAR_522 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(t.cont);
;                            
                        ____BAH_COMPILER_VAR_522 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_522+currStrOff, pt.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_522+currStrOff, t.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    t.cont =  ____BAH_COMPILER_VAR_522;
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
i =  i + 1;
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
i =  i + 1;
};
array(struct Tok)* ____BAH_COMPILER_VAR_523 = nl;
return ____BAH_COMPILER_VAR_523;
};
__BAH_ARR_TYPE_Tok prePross(__BAH_ARR_TYPE_Tok line,lineType ltp,struct Elems* elems);
__BAH_ARR_TYPE_Tok parseStructType(__BAH_ARR_TYPE_Tok line,lineType ltp,struct Elems* elems){
if ((ltp==LINE_TYPE_VAR)) {
array(struct Tok)* ____BAH_COMPILER_VAR_524 = line;
return ____BAH_COMPILER_VAR_524;
}
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
long int i =  0;
while ((i<len(line))) {

                if (line->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:531): line[%d] with length %d\n", i, line->length);
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
i =  i + 1;
continue;
}
i =  i + 1;
struct Tok ____BAH_COMPILER_VAR_525 = {};
____BAH_COMPILER_VAR_525.cont = "";
____BAH_COMPILER_VAR_525.ogCont = "";
____BAH_COMPILER_VAR_525.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_525.pos = 0;
____BAH_COMPILER_VAR_525.line = 1;
____BAH_COMPILER_VAR_525.begLine = 1;
____BAH_COMPILER_VAR_525.bahType = "";
____BAH_COMPILER_VAR_525.isValue = false;
____BAH_COMPILER_VAR_525.isFunc = false;
____BAH_COMPILER_VAR_525.isOper = false;
____BAH_COMPILER_VAR_525.cont = "";
struct Tok nt =  ____BAH_COMPILER_VAR_525;
if ((i<len(line))) {

                if (line->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:543): line[%d] with length %d\n", i, line->length);
                    exit(1);
                };
                nt =  line->data[i];
}
if (((i==len(line))||(__checkString(nt.cont, "/home/alois/Documents/bah-bah/src/parser.bah:545 nt.cont ")==1&&strcmp(nt.cont, "{") != 0))) {
if ((i-2>=0)) {

                if (line->length <= i-2) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:547): line[%d] with length %d\n", i-2, line->length);
                    exit(1);
                };
                struct Tok newTk =  line->data[i-2];
if ((__checkString(newTk.cont, "/home/alois/Documents/bah-bah/src/parser.bah:548 newTk.cont ")==1&&strcmp(newTk.cont, "new") == 0)) {
struct cStruct* s =  searchStruct(t.cont,elems);
if ((s==null)) {
throwErr(&t,"Cannot initialize new unknown struct {TOKEN}.");
}
t.cont =  genCompilerVar();
struct variable* ____BAH_COMPILER_VAR_526 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_526->name = "";
____BAH_COMPILER_VAR_526->type = "";
____BAH_COMPILER_VAR_526->isConst = false;
____BAH_COMPILER_VAR_526->constVal = "";
____BAH_COMPILER_VAR_526->isArray = false;
____BAH_COMPILER_VAR_526->from = "";
____BAH_COMPILER_VAR_526->outterScope = false;
struct variable* tmpV =  ____BAH_COMPILER_VAR_526;
tmpV->name =  t.cont;
char * ____BAH_COMPILER_VAR_527 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s->name);
long int strLen_1 = strlen("*");
;                            
                        ____BAH_COMPILER_VAR_527 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_527+currStrOff, s->name, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_527+currStrOff, "*", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    tmpV->type =  ____BAH_COMPILER_VAR_527;
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
char * ____BAH_COMPILER_VAR_528 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_529 =structType.str((struct string*)&structType);char * ____BAH_COMPILER_VAR_530 =declareStructMethods(tmpV,s,elems);char * ____BAH_COMPILER_VAR_531 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(____BAH_COMPILER_VAR_528);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(t.cont);
long int strLen_3 = strlen(" = memoryAlloc(sizeof(");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_529);
long int strLen_5 = strlen("));\n");
long int strLen_6 = strlen(____BAH_COMPILER_VAR_530);
;                            
                        ____BAH_COMPILER_VAR_531 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                        
                        strncpy(____BAH_COMPILER_VAR_531+currStrOff, ____BAH_COMPILER_VAR_528, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_531+currStrOff, " ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_531+currStrOff, t.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_531+currStrOff, " = memoryAlloc(sizeof(", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_531+currStrOff, ____BAH_COMPILER_VAR_529, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_531+currStrOff, "));\n", strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_531+currStrOff, ____BAH_COMPILER_VAR_530, strLen_6);
                        currStrOff += strLen_6;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_531));

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
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:569): line[%d] with length %d\n", i, line->length);
                    exit(1);
                };
                nt =  line->data[i];
if ((__checkString(nt.cont, "/home/alois/Documents/bah-bah/src/parser.bah:570 nt.cont ")==1&&strcmp(nt.cont, "{") == 0)) {
int isHeap =  false;
char * sep =  ".";
if ((i-2>=0)) {

                if (line->length <= i-2) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:574): line[%d] with length %d\n", i-2, line->length);
                    exit(1);
                };
                struct Tok newTk =  line->data[i-2];
if ((__checkString(newTk.cont, "/home/alois/Documents/bah-bah/src/parser.bah:575 newTk.cont ")==1&&strcmp(newTk.cont, "new") == 0)) {
isHeap =  true;
sep =  "->";
}
}
i =  i + 1;
struct cStruct* s =  searchStruct(t.cont,elems);
if ((s==null)) {
throwErr(&t,"Unknown struct name {TOKEN}.");
}
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
while ((i<len(line))) {

                if (line->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:587): line[%d] with length %d\n", i, line->length);
                    exit(1);
                };
                t =  line->data[i];
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:588 t.cont ")==1&&strcmp(t.cont, "}") == 0)) {
break;
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
i =  i + 1;
};
if ((len(memory)>0)) {
memory =  prePross(memory,(lineType)-1,elems);
}
long int declType =  0;
char * rvn =  genCompilerVar();
struct variable* ____BAH_COMPILER_VAR_532 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_532->name = "";
____BAH_COMPILER_VAR_532->type = "";
____BAH_COMPILER_VAR_532->isConst = false;
____BAH_COMPILER_VAR_532->constVal = "";
____BAH_COMPILER_VAR_532->isArray = false;
____BAH_COMPILER_VAR_532->from = "";
____BAH_COMPILER_VAR_532->outterScope = false;
struct variable* tmpV =  ____BAH_COMPILER_VAR_532;
tmpV->name =  rvn;
if ((isHeap==true)) {
char * ____BAH_COMPILER_VAR_533 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s->name);
long int strLen_1 = strlen("*");
;                            
                        ____BAH_COMPILER_VAR_533 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_533+currStrOff, s->name, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_533+currStrOff, "*", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    tmpV->type =  ____BAH_COMPILER_VAR_533;

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
char * ____BAH_COMPILER_VAR_534 =rst.str((struct string*)&rst);struct string structType =  string(____BAH_COMPILER_VAR_534);
structType.trimRight((struct string*)&structType,1);
char * ____BAH_COMPILER_VAR_535 =rst.str((struct string*)&rst);char * ____BAH_COMPILER_VAR_536 =structType.str((struct string*)&structType);char * ____BAH_COMPILER_VAR_537 =declareStructMethods(tmpV,s,elems);char * ____BAH_COMPILER_VAR_538 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(____BAH_COMPILER_VAR_535);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(rvn);
long int strLen_3 = strlen(" = memoryAlloc(sizeof(");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_536);
long int strLen_5 = strlen("));\n");
long int strLen_6 = strlen(____BAH_COMPILER_VAR_537);
;                            
                        ____BAH_COMPILER_VAR_538 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                        
                        strncpy(____BAH_COMPILER_VAR_538+currStrOff, ____BAH_COMPILER_VAR_535, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_538+currStrOff, " ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_538+currStrOff, rvn, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_538+currStrOff, " = memoryAlloc(sizeof(", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_538+currStrOff, ____BAH_COMPILER_VAR_536, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_538+currStrOff, "));\n", strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_538+currStrOff, ____BAH_COMPILER_VAR_537, strLen_6);
                        currStrOff += strLen_6;
                        
                    }
                    r =  rope(____BAH_COMPILER_VAR_538);
}
else {
char * ____BAH_COMPILER_VAR_539 =rst.str((struct string*)&rst);char * ____BAH_COMPILER_VAR_540 =declareStructMethods(tmpV,s,elems);char * ____BAH_COMPILER_VAR_541 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(____BAH_COMPILER_VAR_539);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(rvn);
long int strLen_3 = strlen(" = {};\n");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_540);
;                            
                        ____BAH_COMPILER_VAR_541 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_541+currStrOff, ____BAH_COMPILER_VAR_539, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_541+currStrOff, " ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_541+currStrOff, rvn, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_541+currStrOff, " = {};\n", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_541+currStrOff, ____BAH_COMPILER_VAR_540, strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    r =  rope(____BAH_COMPILER_VAR_541);
}
long int j =  0;
long int k =  0;
while ((k<len(memory))) {

                if (memory->length <= k) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:619): memory[%d] with length %d\n", k, memory->length);
                    exit(1);
                };
                t =  memory->data[k];
if ((k + 2<len(memory))) {

                if (memory->length <= k + 1) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:621): memory[%d] with length %d\n", k + 1, memory->length);
                    exit(1);
                };
                struct Tok st =  memory->data[k + 1];

                if (memory->length <= k + 2) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:622): memory[%d] with length %d\n", k + 2, memory->length);
                    exit(1);
                };
                struct Tok vl =  memory->data[k + 2];
if ((__checkString(st.cont, "/home/alois/Documents/bah-bah/src/parser.bah:623 st.cont ")==1&&strcmp(st.cont, ":") == 0)) {
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
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:632): s->members[%d] with length %d\n", j, s->members->length);
                    exit(1);
                };
                struct structMemb* m =  s->members->data[j];
if ((__checkString(m->name, "/home/alois/Documents/bah-bah/src/parser.bah:633 m->name ")==1&&__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:633 t.cont")==1&&strcmp(m->name, t.cont) != 0)) {
j =  j + 1;
continue;
}
char * vlt =  getTypeFromToken(&vl,true,elems);
if ((compTypes(vlt,m->type)==false)) {
char * ____BAH_COMPILER_VAR_542 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(vlt);
long int strLen_2 = strlen(") as '");
long int strLen_3 = strlen(m->type);
long int strLen_4 = strlen("'.");
;                            
                        ____BAH_COMPILER_VAR_542 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_542+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_542+currStrOff, vlt, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_542+currStrOff, ") as '", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_542+currStrOff, m->type, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_542+currStrOff, "'.", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    throwErr(&vl,____BAH_COMPILER_VAR_542);
}
char * ____BAH_COMPILER_VAR_543 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(rvn);
long int strLen_1 = strlen(sep);
long int strLen_2 = strlen(m->name);
long int strLen_3 = strlen(" = ");
long int strLen_4 = strlen(vl.cont);
long int strLen_5 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_543 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_543+currStrOff, rvn, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_543+currStrOff, sep, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_543+currStrOff, m->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_543+currStrOff, " = ", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_543+currStrOff, vl.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_543+currStrOff, ";\n", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    r =  r->add(r, rope(____BAH_COMPILER_VAR_543));
break;
};
if ((j==len(s->members))) {
char * ____BAH_COMPILER_VAR_544 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Struct '");
long int strLen_1 = strlen(s->name);
long int strLen_2 = strlen("' has no member called {TOKEN}.");
;                            
                        ____BAH_COMPILER_VAR_544 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_544+currStrOff, "Struct '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_544+currStrOff, s->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_544+currStrOff, "' has no member called {TOKEN}.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    throwErr(&t,____BAH_COMPILER_VAR_544);
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
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:659): s->members[%d] with length %d\n", j, s->members->length);
                    exit(1);
                };
                struct structMemb* m =  s->members->data[j];
j =  j + 1;
char * tt =  getTypeFromToken(&t,true,elems);
if ((compTypes(tt,m->type)==false)) {
char * ____BAH_COMPILER_VAR_545 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(tt);
long int strLen_2 = strlen(") as '");
long int strLen_3 = strlen(m->type);
long int strLen_4 = strlen("'.");
;                            
                        ____BAH_COMPILER_VAR_545 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_545+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_545+currStrOff, tt, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_545+currStrOff, ") as '", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_545+currStrOff, m->type, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_545+currStrOff, "'.", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    throwErr(&t,____BAH_COMPILER_VAR_545);
}
char * ____BAH_COMPILER_VAR_546 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(rvn);
long int strLen_1 = strlen(sep);
long int strLen_2 = strlen(m->name);
long int strLen_3 = strlen(" = ");
long int strLen_4 = strlen(t.cont);
long int strLen_5 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_546 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_546+currStrOff, rvn, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_546+currStrOff, sep, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_546+currStrOff, m->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_546+currStrOff, " = ", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_546+currStrOff, t.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_546+currStrOff, ";\n", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    r =  r->add(r, rope(____BAH_COMPILER_VAR_546));
if ((k + 1<len(memory))) {
k =  k + 1;

                if (memory->length <= k) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:671): memory[%d] with length %d\n", k, memory->length);
                    exit(1);
                };
                struct Tok st =  memory->data[k];
if ((__checkString(st.cont, "/home/alois/Documents/bah-bah/src/parser.bah:672 st.cont ")==1&&strcmp(st.cont, ",") != 0)) {
throwErr(&st,"Need ',' separator between two values, not {TOKEN}.");
}
}
k =  k + 1;
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
i =  i + 1;
continue;
}
else {
i =  i - 1;
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
array(struct Tok)* ____BAH_COMPILER_VAR_547 = nl;
return ____BAH_COMPILER_VAR_547;
};
__BAH_ARR_TYPE_Tok parseStructVars(__BAH_ARR_TYPE_Tok line,struct Elems* elems){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
long int i =  0;
while ((i<len(line))) {

                if (line->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:713): line[%d] with length %d\n", i, line->length);
                    exit(1);
                };
                struct Tok t =  line->data[i];
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:714 t.cont ")==1&&strcmp(t.cont, ".") == 0)) {
break;
}
i =  i + 1;
};
if ((i==len(line))) {
array(struct Tok)* ____BAH_COMPILER_VAR_548 = line;
return ____BAH_COMPILER_VAR_548;
}
i =  0;
while ((i<len(line))) {

                if (line->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:725): line[%d] with length %d\n", i, line->length);
                    exit(1);
                };
                struct Tok t =  line->data[i];
if ((t.type==TOKEN_TYPE_VAR)) {
i =  i + 1;
while ((i<len(line))) {

                if (line->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:729): line[%d] with length %d\n", i, line->length);
                    exit(1);
                };
                struct Tok it =  line->data[i];
if ((__checkString(it.cont, "/home/alois/Documents/bah-bah/src/parser.bah:730 it.cont ")==1&&strcmp(it.cont, ".") != 0)) {
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
char * ____BAH_COMPILER_VAR_549 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(v->type);
long int strLen_2 = strlen(") as a structure.");
;                            
                        ____BAH_COMPILER_VAR_549 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_549+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_549+currStrOff, v->type, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_549+currStrOff, ") as a structure.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    throwErr(&t,____BAH_COMPILER_VAR_549);
}
i =  i + 1;

                if (line->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:746): line[%d] with length %d\n", i, line->length);
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
char * ____BAH_COMPILER_VAR_550 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(sep);
long int strLen_2 = strlen(memb->name);
;                            
                        ____BAH_COMPILER_VAR_550 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_550+currStrOff, t.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_550+currStrOff, sep, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_550+currStrOff, memb->name, strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    t.cont =  ____BAH_COMPILER_VAR_550;
i =  i + 1;
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
i =  i + 1;
};
array(struct Tok)* ____BAH_COMPILER_VAR_551 = nl;
return ____BAH_COMPILER_VAR_551;
};
__BAH_ARR_TYPE_Tok parseArrayType(__BAH_ARR_TYPE_Tok line,struct Elems* elems){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
long int i =  0;
for (; (i<len(line)); i =  i+1) {

                if (line->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:774): line[%d] with length %d\n", i, line->length);
                    exit(1);
                };
                struct Tok t =  line->data[i];
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:775 t.cont ")==1&&strcmp(t.cont, "[") == 0)) {
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
array(struct Tok)* ____BAH_COMPILER_VAR_552 = line;
return ____BAH_COMPILER_VAR_552;
}
for (; (i<len(line)); i =  i+1) {

                if (line->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:785): line[%d] with length %d\n", i, line->length);
                    exit(1);
                };
                struct Tok t =  line->data[i];
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:786 t.cont ")==1&&strcmp(t.cont, "[") == 0)) {
i =  i+1;
if ((i<len(line))) {

                if (line->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:789): line[%d] with length %d\n", i, line->length);
                    exit(1);
                };
                t =  line->data[i];
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:790 t.cont ")==1&&strcmp(t.cont, "]") == 0)) {
i =  i+1;
long int depth =  1;
char * bracks =  "[]";
for (; (i<len(line) - 1); i =  i+1) {

                if (line->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:795): line[%d] with length %d\n", i, line->length);
                    exit(1);
                };
                t =  line->data[i];

                if (line->length <= i + 1) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:796): line[%d] with length %d\n", i + 1, line->length);
                    exit(1);
                };
                struct Tok nt =  line->data[i + 1];
if (((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:797 t.cont ")==1&&strcmp(t.cont, "[") == 0)&&(__checkString(nt.cont, "/home/alois/Documents/bah-bah/src/parser.bah:797 nt.cont ")==1&&strcmp(nt.cont, "]") == 0))) {
depth =  depth+1;
char * ____BAH_COMPILER_VAR_553 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(bracks);
long int strLen_1 = strlen("[]");
;                            
                        ____BAH_COMPILER_VAR_553 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_553+currStrOff, bracks, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_553+currStrOff, "[]", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    bracks =  ____BAH_COMPILER_VAR_553;
i =  i+1;
}
else {
break;
}
};
if ((i<len(line))) {

                if (line->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:806): line[%d] with length %d\n", i, line->length);
                    exit(1);
                };
                t =  line->data[i];
if ((t.type!=TOKEN_TYPE_VAR)) {
throwErr(&t,"Cannot use {TOKEN} as array type.");
}
char * arrElem =  t.cont;
char * ____BAH_COMPILER_VAR_554 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(bracks);
long int strLen_1 = strlen(arrElem);
;                            
                        ____BAH_COMPILER_VAR_554 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_554+currStrOff, bracks, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_554+currStrOff, arrElem, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    t.bahType =  ____BAH_COMPILER_VAR_554;
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
array(struct Tok)* ____BAH_COMPILER_VAR_555 = nl;
return ____BAH_COMPILER_VAR_555;
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
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:836): line[%d] with length %d\n", i, line->length);
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
array(struct Tok)* ____BAH_COMPILER_VAR_556 = line;
return ____BAH_COMPILER_VAR_556;
}
while ((i<len(line))) {

                if (line->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:848): line[%d] with length %d\n", i, line->length);
                    exit(1);
                };
                struct Tok t =  line->data[i];
if (inArrayStr(t.cont,comparators)) {
if ((i==0)) {
throwErr(&t,"Cannot use {TOKEN} to compare with nothing.");
}

                if (nl->length <= len(nl)-1) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:854): nl[%d] with length %d\n", len(nl)-1, nl->length);
                    exit(1);
                };
                struct Tok pt =  nl->data[len(nl)-1];
long int max =  i + 1;
if ((max>=len(line))) {
throwErr(&t,"Cannot use {TOKEN} to compare with nothing.");
}

                if (line->length <= i + 1) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:859): line[%d] with length %d\n", i + 1, line->length);
                    exit(1);
                };
                struct Tok nt =  line->data[i + 1];
char * ptt =  getTypeFromToken(&pt,true,elems);
char * ntt =  getTypeFromToken(&nt,true,elems);
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:863 t.cont ")==1&&strcmp(t.cont, "in") == 0)) {
struct string arrT =  string(ntt);
if ((arrT.hasPrefix((struct string*)&arrT,"[]")==0)) {
char * ____BAH_COMPILER_VAR_557 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(ntt);
long int strLen_2 = strlen(") as an array.");
;                            
                        ____BAH_COMPILER_VAR_557 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_557+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_557+currStrOff, ntt, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_557+currStrOff, ") as an array.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    throwErr(&nt,____BAH_COMPILER_VAR_557);
}
arrT.trimLeft((struct string*)&arrT,2);
char * ____BAH_COMPILER_VAR_558 =arrT.str((struct string*)&arrT);if ((compTypes(ptt,____BAH_COMPILER_VAR_558)==false)) {
char * ____BAH_COMPILER_VAR_559 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot search for {TOKEN} (");
long int strLen_1 = strlen(ptt);
long int strLen_2 = strlen(") inside array of type ");
long int strLen_3 = strlen(ntt);
long int strLen_4 = strlen(".");
;                            
                        ____BAH_COMPILER_VAR_559 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_559+currStrOff, "Cannot search for {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_559+currStrOff, ptt, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_559+currStrOff, ") inside array of type ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_559+currStrOff, ntt, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_559+currStrOff, ".", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    throwErr(&pt,____BAH_COMPILER_VAR_559);
}
char * compVar =  genCompilerVar();
char * comp =  "";
if ((__checkString(ptt, "/home/alois/Documents/bah-bah/src/parser.bah:876 ptt ")==1&&strcmp(ptt, "cpstring") == 0)) {
char * ____BAH_COMPILER_VAR_560 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen("->data[i] != 0 && strcmp(");
long int strLen_2 = strlen(nt.cont);
long int strLen_3 = strlen("->data[i], ");
long int strLen_4 = strlen(pt.cont);
long int strLen_5 = strlen(") == 0");
;                            
                        ____BAH_COMPILER_VAR_560 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_560+currStrOff, nt.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_560+currStrOff, "->data[i] != 0 && strcmp(", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_560+currStrOff, nt.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_560+currStrOff, "->data[i], ", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_560+currStrOff, pt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_560+currStrOff, ") == 0", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    comp =  ____BAH_COMPILER_VAR_560;
}
else {
char * ____BAH_COMPILER_VAR_561 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen("->data[i] == ");
long int strLen_2 = strlen(pt.cont);
;                            
                        ____BAH_COMPILER_VAR_561 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_561+currStrOff, nt.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_561+currStrOff, "->data[i] == ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_561+currStrOff, pt.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    comp =  ____BAH_COMPILER_VAR_561;
}
char * ____BAH_COMPILER_VAR_562 =null;
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
                        ____BAH_COMPILER_VAR_562 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                        
                        strncpy(____BAH_COMPILER_VAR_562+currStrOff, "\n                int ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_562+currStrOff, compVar, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_562+currStrOff, " = 0;\n                for(int i=len(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_562+currStrOff, nt.cont, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_562+currStrOff, ")-1; i != -1; i--) {\n                    if (", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_562+currStrOff, comp, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_562+currStrOff, ") {\n                        ", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_562+currStrOff, compVar, strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_562+currStrOff, " = 1;\n                        break;\n                    };\n                };\n                ", strLen_8);
                        currStrOff += strLen_8;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_562));
pt.cont =  compVar;
}
else {
if ((compTypes(ptt,ntt)==false)) {
char * ____BAH_COMPILER_VAR_563 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot compare {TOKEN} (");
long int strLen_1 = strlen(ntt);
long int strLen_2 = strlen(") to ");
long int strLen_3 = strlen(ptt);
long int strLen_4 = strlen(".");
;                            
                        ____BAH_COMPILER_VAR_563 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_563+currStrOff, "Cannot compare {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_563+currStrOff, ntt, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_563+currStrOff, ") to ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_563+currStrOff, ptt, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_563+currStrOff, ".", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    throwErr(&nt,____BAH_COMPILER_VAR_563);
}
if ((__checkString(ptt, "/home/alois/Documents/bah-bah/src/parser.bah:896 ptt ")==1&&strcmp(ptt, "cpstring") == 0)) {
char * check =  "";
if ((pt.type!=TOKEN_TYPE_STR)) {
char * ____BAH_COMPILER_VAR_564 =intToStr(t.line);char * ____BAH_COMPILER_VAR_565 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("__checkString(");
long int strLen_1 = strlen(pt.cont);
long int strLen_2 = strlen(", \"");
long int strLen_3 = strlen(compilerState.currentFile);
long int strLen_4 = strlen(":");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_564);
long int strLen_6 = strlen(" ");
long int strLen_7 = strlen(pt.cont);
long int strLen_8 = strlen(" \")==1&&");
;                            
                        ____BAH_COMPILER_VAR_565 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                        
                        strncpy(____BAH_COMPILER_VAR_565+currStrOff, "__checkString(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_565+currStrOff, pt.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_565+currStrOff, ", \"", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_565+currStrOff, compilerState.currentFile, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_565+currStrOff, ":", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_565+currStrOff, ____BAH_COMPILER_VAR_564, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_565+currStrOff, " ", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_565+currStrOff, pt.cont, strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_565+currStrOff, " \")==1&&", strLen_8);
                        currStrOff += strLen_8;
                        
                    }
                    check =  ____BAH_COMPILER_VAR_565;
}
if ((nt.type!=TOKEN_TYPE_STR)) {
char * ____BAH_COMPILER_VAR_566 =intToStr(t.line);char * ____BAH_COMPILER_VAR_567 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(check);
long int strLen_1 = strlen("__checkString(");
long int strLen_2 = strlen(nt.cont);
long int strLen_3 = strlen(", \"");
long int strLen_4 = strlen(compilerState.currentFile);
long int strLen_5 = strlen(":");
long int strLen_6 = strlen(____BAH_COMPILER_VAR_566);
long int strLen_7 = strlen(" ");
long int strLen_8 = strlen(nt.cont);
long int strLen_9 = strlen("\")==1&&");
;                            
                        ____BAH_COMPILER_VAR_567 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9);
                        
                        strncpy(____BAH_COMPILER_VAR_567+currStrOff, check, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_567+currStrOff, "__checkString(", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_567+currStrOff, nt.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_567+currStrOff, ", \"", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_567+currStrOff, compilerState.currentFile, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_567+currStrOff, ":", strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_567+currStrOff, ____BAH_COMPILER_VAR_566, strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_567+currStrOff, " ", strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_567+currStrOff, nt.cont, strLen_8);
                        currStrOff += strLen_8;
                        
                        strncpy(____BAH_COMPILER_VAR_567+currStrOff, "\")==1&&", strLen_9);
                        currStrOff += strLen_9;
                        
                    }
                    check =  ____BAH_COMPILER_VAR_567;
}
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:904 t.cont ")==1&&strcmp(t.cont, "==") == 0)) {
char * ____BAH_COMPILER_VAR_568 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("(");
long int strLen_1 = strlen(check);
long int strLen_2 = strlen("strcmp(");
long int strLen_3 = strlen(pt.cont);
long int strLen_4 = strlen(", ");
long int strLen_5 = strlen(nt.cont);
long int strLen_6 = strlen(") == 0)");
;                            
                        ____BAH_COMPILER_VAR_568 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                        
                        strncpy(____BAH_COMPILER_VAR_568+currStrOff, "(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_568+currStrOff, check, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_568+currStrOff, "strcmp(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_568+currStrOff, pt.cont, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_568+currStrOff, ", ", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_568+currStrOff, nt.cont, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_568+currStrOff, ") == 0)", strLen_6);
                        currStrOff += strLen_6;
                        
                    }
                    pt.cont =  ____BAH_COMPILER_VAR_568;
}
else if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:906 t.cont ")==1&&strcmp(t.cont, "!=") == 0)) {
char * ____BAH_COMPILER_VAR_569 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("(");
long int strLen_1 = strlen(check);
long int strLen_2 = strlen("strcmp(");
long int strLen_3 = strlen(pt.cont);
long int strLen_4 = strlen(", ");
long int strLen_5 = strlen(nt.cont);
long int strLen_6 = strlen(") != 0)");
;                            
                        ____BAH_COMPILER_VAR_569 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                        
                        strncpy(____BAH_COMPILER_VAR_569+currStrOff, "(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_569+currStrOff, check, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_569+currStrOff, "strcmp(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_569+currStrOff, pt.cont, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_569+currStrOff, ", ", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_569+currStrOff, nt.cont, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_569+currStrOff, ") != 0)", strLen_6);
                        currStrOff += strLen_6;
                        
                    }
                    pt.cont =  ____BAH_COMPILER_VAR_569;
}
else if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:908 t.cont ")==1&&strcmp(t.cont, ">") == 0)) {
char * ____BAH_COMPILER_VAR_570 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("(");
long int strLen_1 = strlen(check);
long int strLen_2 = strlen("strlen(");
long int strLen_3 = strlen(pt.cont);
long int strLen_4 = strlen(") > srtlen(");
long int strLen_5 = strlen(nt.cont);
long int strLen_6 = strlen("))");
;                            
                        ____BAH_COMPILER_VAR_570 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                        
                        strncpy(____BAH_COMPILER_VAR_570+currStrOff, "(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_570+currStrOff, check, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_570+currStrOff, "strlen(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_570+currStrOff, pt.cont, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_570+currStrOff, ") > srtlen(", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_570+currStrOff, nt.cont, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_570+currStrOff, "))", strLen_6);
                        currStrOff += strLen_6;
                        
                    }
                    pt.cont =  ____BAH_COMPILER_VAR_570;
}
else if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:910 t.cont ")==1&&strcmp(t.cont, "<") == 0)) {
char * ____BAH_COMPILER_VAR_571 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("(");
long int strLen_1 = strlen(check);
long int strLen_2 = strlen("strlen(");
long int strLen_3 = strlen(pt.cont);
long int strLen_4 = strlen(") < srtlen(");
long int strLen_5 = strlen(nt.cont);
long int strLen_6 = strlen("))");
;                            
                        ____BAH_COMPILER_VAR_571 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                        
                        strncpy(____BAH_COMPILER_VAR_571+currStrOff, "(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_571+currStrOff, check, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_571+currStrOff, "strlen(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_571+currStrOff, pt.cont, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_571+currStrOff, ") < srtlen(", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_571+currStrOff, nt.cont, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_571+currStrOff, "))", strLen_6);
                        currStrOff += strLen_6;
                        
                    }
                    pt.cont =  ____BAH_COMPILER_VAR_571;
}
else if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:912 t.cont ")==1&&strcmp(t.cont, ">=") == 0)) {
char * ____BAH_COMPILER_VAR_572 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("(");
long int strLen_1 = strlen(check);
long int strLen_2 = strlen("strlen(");
long int strLen_3 = strlen(pt.cont);
long int strLen_4 = strlen(") >= srtlen(");
long int strLen_5 = strlen(nt.cont);
long int strLen_6 = strlen("))");
;                            
                        ____BAH_COMPILER_VAR_572 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                        
                        strncpy(____BAH_COMPILER_VAR_572+currStrOff, "(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_572+currStrOff, check, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_572+currStrOff, "strlen(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_572+currStrOff, pt.cont, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_572+currStrOff, ") >= srtlen(", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_572+currStrOff, nt.cont, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_572+currStrOff, "))", strLen_6);
                        currStrOff += strLen_6;
                        
                    }
                    pt.cont =  ____BAH_COMPILER_VAR_572;
}
else if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:914 t.cont ")==1&&strcmp(t.cont, "<=") == 0)) {
char * ____BAH_COMPILER_VAR_573 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("(");
long int strLen_1 = strlen(check);
long int strLen_2 = strlen("strlen(");
long int strLen_3 = strlen(pt.cont);
long int strLen_4 = strlen(") <= srtlen(");
long int strLen_5 = strlen(nt.cont);
long int strLen_6 = strlen("))");
;                            
                        ____BAH_COMPILER_VAR_573 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                        
                        strncpy(____BAH_COMPILER_VAR_573+currStrOff, "(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_573+currStrOff, check, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_573+currStrOff, "strlen(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_573+currStrOff, pt.cont, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_573+currStrOff, ") <= srtlen(", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_573+currStrOff, nt.cont, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_573+currStrOff, "))", strLen_6);
                        currStrOff += strLen_6;
                        
                    }
                    pt.cont =  ____BAH_COMPILER_VAR_573;
}
}
else {
char * ____BAH_COMPILER_VAR_574 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("(");
long int strLen_1 = strlen(pt.cont);
long int strLen_2 = strlen(t.cont);
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_574 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_574+currStrOff, "(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_574+currStrOff, pt.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_574+currStrOff, t.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_574+currStrOff, nt.cont, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_574+currStrOff, ")", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    pt.cont =  ____BAH_COMPILER_VAR_574;
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
i =  i + 1;
};
line =  nl;
nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
i =  0;
while ((i<len(line))) {

                if (line->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:935): line[%d] with length %d\n", i, line->length);
                    exit(1);
                };
                struct Tok t =  line->data[i];
if (inArrayStr(t.cont,compSep)) {
if ((i==0)) {
throwErr(&t,"Cannot use {TOKEN} to compare with nothing.");
}

                if (nl->length <= len(nl)-1) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:940): nl[%d] with length %d\n", len(nl)-1, nl->length);
                    exit(1);
                };
                struct Tok pt =  nl->data[len(nl)-1];
long int max =  i + 1;
if ((max>=len(line))) {
throwErr(&t,"Cannot use {TOKEN} to compare with nothing.");
}

                if (line->length <= i + 1) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:945): line[%d] with length %d\n", i + 1, line->length);
                    exit(1);
                };
                struct Tok nt =  line->data[i + 1];
char * ptt =  getTypeFromToken(&pt,true,elems);
char * ntt =  getTypeFromToken(&nt,true,elems);
if ((__checkString(ptt, "/home/alois/Documents/bah-bah/src/parser.bah:948 ptt ")==1&&strcmp(ptt, "bool") != 0)) {
if ((__checkString(ptt, "/home/alois/Documents/bah-bah/src/parser.bah:949 ptt ")==1&&strcmp(ptt, "int") != 0)) {
throwErr(&pt,"Cannot compare {TOKEN} that is not a bool.");
}
}
if ((__checkString(ntt, "/home/alois/Documents/bah-bah/src/parser.bah:953 ntt ")==1&&strcmp(ntt, "bool") != 0)) {
if ((__checkString(ntt, "/home/alois/Documents/bah-bah/src/parser.bah:954 ntt ")==1&&strcmp(ntt, "int") != 0)) {
throwErr(&nt,"Cannot compare {TOKEN} that is not a bool.");
}
}
char * ____BAH_COMPILER_VAR_575 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("(");
long int strLen_1 = strlen(pt.cont);
long int strLen_2 = strlen(t.cont);
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_575 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_575+currStrOff, "(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_575+currStrOff, pt.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_575+currStrOff, t.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_575+currStrOff, nt.cont, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_575+currStrOff, ")", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    pt.cont =  ____BAH_COMPILER_VAR_575;
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
i =  i + 1;
};
array(struct Tok)* ____BAH_COMPILER_VAR_576 = nl;
return ____BAH_COMPILER_VAR_576;
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
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:981): l[%d] with length %d\n", i, l->length);
                    exit(1);
                };
                struct Tok t =  l->data[i];
if ((t.type==TOKEN_TYPE_SYNTAX)) {
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:984 t.cont ")==1&&strcmp(t.cont, "*") == 0)) {
if ((i>0)) {

                if (nl->length <= len(nl)-1) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:986): nl[%d] with length %d\n", len(nl)-1, nl->length);
                    exit(1);
                };
                struct Tok pt =  nl->data[len(nl)-1];
if ((pt.type==TOKEN_TYPE_VAR)) {
if ((i + 1<len(l))) {

                if (l->length <= i + 1) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:989): l[%d] with length %d\n", i + 1, l->length);
                    exit(1);
                };
                struct Tok nt =  l->data[i + 1];
if ((nt.isValue==false)) {
char * ____BAH_COMPILER_VAR_577 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(t.cont);
;                            
                        ____BAH_COMPILER_VAR_577 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_577+currStrOff, pt.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_577+currStrOff, t.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    pt.cont =  ____BAH_COMPILER_VAR_577;

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
char * ____BAH_COMPILER_VAR_578 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(t.cont);
;                            
                        ____BAH_COMPILER_VAR_578 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_578+currStrOff, pt.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_578+currStrOff, t.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    pt.cont =  ____BAH_COMPILER_VAR_578;

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
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1008): nl[%d] with length %d\n", len(nl)-1, nl->length);
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
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1017): l[%d] with length %d\n", i, l->length);
                    exit(1);
                };
                struct Tok nt =  l->data[i];
if ((nt.type==TOKEN_TYPE_VAR)) {
char * ____BAH_COMPILER_VAR_579 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(nt.cont);
;                            
                        ____BAH_COMPILER_VAR_579 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_579+currStrOff, t.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_579+currStrOff, nt.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    nt.cont =  ____BAH_COMPILER_VAR_579;

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
array(struct Tok)* ____BAH_COMPILER_VAR_580 = nl;
return ____BAH_COMPILER_VAR_580;
};
__BAH_ARR_TYPE_Tok parseArrayVars(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
int found =  false;
long int i =  0;
while ((i<len(l))) {

                if (l->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1043): l[%d] with length %d\n", i, l->length);
                    exit(1);
                };
                struct Tok t =  l->data[i];
if ((t.type==TOKEN_TYPE_VAR)) {
i =  i + 1;
if ((i<len(l))) {

                if (l->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1047): l[%d] with length %d\n", i, l->length);
                    exit(1);
                };
                t =  l->data[i];
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:1048 t.cont ")==1&&strcmp(t.cont, "[") == 0)) {
found =  true;
break;
}
}
}
i =  i + 1;
};
if ((found==false)) {
array(struct Tok)* ____BAH_COMPILER_VAR_581 = l;
return ____BAH_COMPILER_VAR_581;
}

                if (l->length <= 0) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1060): l[%d] with length %d\n", 0, l->length);
                    exit(1);
                };
                struct Tok ft =  l->data[0];
i =  0;
for (; (i<len(l)); i =  i+1) {

                if (l->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1063): l[%d] with length %d\n", i, l->length);
                    exit(1);
                };
                struct Tok t =  l->data[i];
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:1065 t.cont ")==1&&strcmp(t.cont, "[") == 0)) {
long int ti =  i-1;

                if (nl->length <= len(nl)-1) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1067): nl[%d] with length %d\n", len(nl)-1, nl->length);
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
if ((strHasPrefix(tt,"[]")==false)) {
char * ____BAH_COMPILER_VAR_582 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(tt);
long int strLen_2 = strlen(") as an array.");
;                            
                        ____BAH_COMPILER_VAR_582 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_582+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_582+currStrOff, tt, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_582+currStrOff, ") as an array.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    throwErr(&lt,____BAH_COMPILER_VAR_582);
}
strTrimLeft(&tt,2);
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
i =  i + 1;
long int nbBracks =  1;
for (; (i<len(l)); i =  i+1) {

                if (l->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1082): l[%d] with length %d\n", i, l->length);
                    exit(1);
                };
                struct Tok it =  l->data[i];
if ((__checkString(it.cont, "/home/alois/Documents/bah-bah/src/parser.bah:1083 it.cont ")==1&&strcmp(it.cont, "[") == 0)) {
nbBracks =  nbBracks + 1;
}
else if ((__checkString(it.cont, "/home/alois/Documents/bah-bah/src/parser.bah:1085 it.cont ")==1&&strcmp(it.cont, "]") == 0)) {
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
char * cont =  "";
long int j =  0;
for (; (j<len(memory)); j =  j+1) {

                if (memory->length <= j) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1101): memory[%d] with length %d\n", j, memory->length);
                    exit(1);
                };
                struct Tok mt =  memory->data[j];
char * ____BAH_COMPILER_VAR_583 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(cont);
long int strLen_1 = strlen(mt.cont);
;                            
                        ____BAH_COMPILER_VAR_583 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_583+currStrOff, cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_583+currStrOff, mt.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    cont =  ____BAH_COMPILER_VAR_583;
};
if (((ti>0)&&(__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:1105 ft.cont ")==1&&strcmp(ft.cont, "else") != 0))) {
char * ____BAH_COMPILER_VAR_584 =intToStr(lt.line);char * ____BAH_COMPILER_VAR_585 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\n                if (");
long int strLen_1 = strlen(lt.cont);
long int strLen_2 = strlen("->length <= ");
long int strLen_3 = strlen(cont);
long int strLen_4 = strlen(") {\n                    printf(\"array (");
long int strLen_5 = strlen(compilerState.currentFile);
long int strLen_6 = strlen(":");
long int strLen_7 = strlen(____BAH_COMPILER_VAR_584);
long int strLen_8 = strlen("): ");
long int strLen_9 = strlen(lt.cont);
long int strLen_10 = strlen("[%d] with length %d\\n\", ");
long int strLen_11 = strlen(cont);
long int strLen_12 = strlen(", ");
long int strLen_13 = strlen(lt.cont);
long int strLen_14 = strlen("->length);\n                    exit(1);\n                };\n                ");
;                            
                        ____BAH_COMPILER_VAR_585 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14);
                        
                        strncpy(____BAH_COMPILER_VAR_585+currStrOff, "\n                if (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_585+currStrOff, lt.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_585+currStrOff, "->length <= ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_585+currStrOff, cont, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_585+currStrOff, ") {\n                    printf(\"array (", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_585+currStrOff, compilerState.currentFile, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_585+currStrOff, ":", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_585+currStrOff, ____BAH_COMPILER_VAR_584, strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_585+currStrOff, "): ", strLen_8);
                        currStrOff += strLen_8;
                        
                        strncpy(____BAH_COMPILER_VAR_585+currStrOff, lt.cont, strLen_9);
                        currStrOff += strLen_9;
                        
                        strncpy(____BAH_COMPILER_VAR_585+currStrOff, "[%d] with length %d\\n\", ", strLen_10);
                        currStrOff += strLen_10;
                        
                        strncpy(____BAH_COMPILER_VAR_585+currStrOff, cont, strLen_11);
                        currStrOff += strLen_11;
                        
                        strncpy(____BAH_COMPILER_VAR_585+currStrOff, ", ", strLen_12);
                        currStrOff += strLen_12;
                        
                        strncpy(____BAH_COMPILER_VAR_585+currStrOff, lt.cont, strLen_13);
                        currStrOff += strLen_13;
                        
                        strncpy(____BAH_COMPILER_VAR_585+currStrOff, "->length);\n                    exit(1);\n                };\n                ", strLen_14);
                        currStrOff += strLen_14;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_585));
}
char * ____BAH_COMPILER_VAR_586 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(lt.cont);
long int strLen_1 = strlen("->data[");
long int strLen_2 = strlen(cont);
long int strLen_3 = strlen("]");
;                            
                        ____BAH_COMPILER_VAR_586 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                        
                        strncpy(____BAH_COMPILER_VAR_586+currStrOff, lt.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_586+currStrOff, "->data[", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_586+currStrOff, cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_586+currStrOff, "]", strLen_3);
                        currStrOff += strLen_3;
                        
                    }
                    lt.cont =  ____BAH_COMPILER_VAR_586;
lt.bahType =  tt;

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
array(struct Tok)* ____BAH_COMPILER_VAR_587 = nl;
return ____BAH_COMPILER_VAR_587;
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
char * ____BAH_COMPILER_VAR_588 =svt.str((struct string*)&svt);char * ____BAH_COMPILER_VAR_589 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("__serialize(&");
long int strLen_1 = strlen(e.cont);
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen("sizeof(struct ");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_588);
long int strLen_5 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_589 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_589+currStrOff, "__serialize(&", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_589+currStrOff, e.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_589+currStrOff, ", ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_589+currStrOff, "sizeof(struct ", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_589+currStrOff, ____BAH_COMPILER_VAR_588, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_589+currStrOff, ")", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_589;
}
else {
char * ptrRect =  "";
while ((ptrLevel>1)) {
char * ____BAH_COMPILER_VAR_590 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(ptrRect);
long int strLen_1 = strlen("*");
;                            
                        ____BAH_COMPILER_VAR_590 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_590+currStrOff, ptrRect, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_590+currStrOff, "*", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    ptrRect =  ____BAH_COMPILER_VAR_590;
ptrLevel =  ptrLevel - 1;
};
char * ____BAH_COMPILER_VAR_591 =svt.str((struct string*)&svt);char * ____BAH_COMPILER_VAR_592 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("__serialize(");
long int strLen_1 = strlen(ptrRect);
long int strLen_2 = strlen(e.cont);
long int strLen_3 = strlen(", ");
long int strLen_4 = strlen("sizeof(struct ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_591);
long int strLen_6 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_592 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                        
                        strncpy(____BAH_COMPILER_VAR_592+currStrOff, "__serialize(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_592+currStrOff, ptrRect, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_592+currStrOff, e.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_592+currStrOff, ", ", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_592+currStrOff, "sizeof(struct ", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_592+currStrOff, ____BAH_COMPILER_VAR_591, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_592+currStrOff, ")", strLen_6);
                        currStrOff += strLen_6;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_592;
long int i =  0;
while ((i<len(s->members))) {

                if (s->members->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1158): s->members[%d] with length %d\n", i, s->members->length);
                    exit(1);
                };
                struct structMemb* m =  s->members->data[i];
if ((__checkString(m->type, "/home/alois/Documents/bah-bah/src/parser.bah:1159 m->type ")==1&&strcmp(m->type, "cpstring") == 0)) {
char * ____BAH_COMPILER_VAR_593 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(code);
long int strLen_1 = strlen("+strlen(");
long int strLen_2 = strlen(e.cont);
long int strLen_3 = strlen("->");
long int strLen_4 = strlen(m->name);
long int strLen_5 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_593 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_593+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_593+currStrOff, "+strlen(", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_593+currStrOff, e.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_593+currStrOff, "->", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_593+currStrOff, m->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_593+currStrOff, ")", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_593;
}
i =  i + 1;
};
}
char * ____BAH_COMPILER_VAR_594 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(code);
long int strLen_1 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_594 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_594+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_594+currStrOff, ")", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    char * ____BAH_COMPILER_VAR_595 = ____BAH_COMPILER_VAR_594;
return ____BAH_COMPILER_VAR_595;
};
struct Tok parseReflect(struct Tok t,char * tt,struct Elems* elems,int parsedPointer,char * ogName,char * offset){
char * isArr =  "0";
if (((t.type!=TOKEN_TYPE_VAR)||(t.type!=TOKEN_TYPE_FUNC))) {
struct string cType =  getCType(tt,elems);
char * v =  genCompilerVar();
if ((parsedPointer==true)) {
cType.append((struct string*)&cType,"*");
}
char * ____BAH_COMPILER_VAR_596 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_597 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(____BAH_COMPILER_VAR_596);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(v);
long int strLen_3 = strlen(" = ");
long int strLen_4 = strlen(t.cont);
long int strLen_5 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_597 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_597+currStrOff, ____BAH_COMPILER_VAR_596, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_597+currStrOff, " ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_597+currStrOff, v, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_597+currStrOff, " = ", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_597+currStrOff, t.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_597+currStrOff, ";\n", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_597));
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
struct Tok ____BAH_COMPILER_VAR_598 = {};
____BAH_COMPILER_VAR_598.cont = "";
____BAH_COMPILER_VAR_598.ogCont = "";
____BAH_COMPILER_VAR_598.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_598.pos = 0;
____BAH_COMPILER_VAR_598.line = 1;
____BAH_COMPILER_VAR_598.begLine = 1;
____BAH_COMPILER_VAR_598.bahType = "";
____BAH_COMPILER_VAR_598.isValue = false;
____BAH_COMPILER_VAR_598.isFunc = false;
____BAH_COMPILER_VAR_598.isOper = false;
struct Tok tmpT =  ____BAH_COMPILER_VAR_598;
tmpT.type =  TOKEN_TYPE_VAR;
tmpT.cont =  "0";
char * ____BAH_COMPILER_VAR_599 =aet.str((struct string*)&aet);struct Tok rt =  parseReflect(tmpT,____BAH_COMPILER_VAR_599,elems,true,"","0");
char * aev =  genCompilerVar();
char * ____BAH_COMPILER_VAR_600 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\n        struct reflectElement ");
long int strLen_1 = strlen(aev);
long int strLen_2 = strlen(" = ");
long int strLen_3 = strlen(rt.cont);
long int strLen_4 = strlen(";\n        ");
;                            
                        ____BAH_COMPILER_VAR_600 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_600+currStrOff, "\n        struct reflectElement ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_600+currStrOff, aev, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_600+currStrOff, " = ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_600+currStrOff, rt.cont, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_600+currStrOff, ";\n        ", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_600));
char * ____BAH_COMPILER_VAR_601 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("&");
long int strLen_1 = strlen(aev);
;                            
                        ____BAH_COMPILER_VAR_601 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_601+currStrOff, "&", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_601+currStrOff, aev, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    arrElem =  ____BAH_COMPILER_VAR_601;
}
char * isStruct =  "0";
struct cStruct* ts =  searchStruct(tt,elems);
char * structLayout =  "0";
if ((ts!=null)) {
isStruct =  "1";
structLayout =  genCompilerVar();
struct variable* ____BAH_COMPILER_VAR_602 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_602->name = "";
____BAH_COMPILER_VAR_602->type = "";
____BAH_COMPILER_VAR_602->isConst = false;
____BAH_COMPILER_VAR_602->constVal = "";
____BAH_COMPILER_VAR_602->isArray = false;
____BAH_COMPILER_VAR_602->from = "";
____BAH_COMPILER_VAR_602->outterScope = false;
struct variable* slv =  ____BAH_COMPILER_VAR_602;
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
while ((i<len(ts->members))) {

                if (ts->members->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1224): ts->members[%d] with length %d\n", i, ts->members->length);
                    exit(1);
                };
                struct structMemb* m =  ts->members->data[i];
struct Tok ____BAH_COMPILER_VAR_603 = {};
____BAH_COMPILER_VAR_603.cont = "";
____BAH_COMPILER_VAR_603.ogCont = "";
____BAH_COMPILER_VAR_603.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_603.pos = 0;
____BAH_COMPILER_VAR_603.line = 1;
____BAH_COMPILER_VAR_603.begLine = 1;
____BAH_COMPILER_VAR_603.bahType = "";
____BAH_COMPILER_VAR_603.isValue = false;
____BAH_COMPILER_VAR_603.isFunc = false;
____BAH_COMPILER_VAR_603.isOper = false;
struct Tok tmpT =  ____BAH_COMPILER_VAR_603;
tmpT.type =  TOKEN_TYPE_VAR;
char * sep =  "->";
if ((strCount(tt,"*")==0)) {
sep =  ".";
}
struct string mCtype =  getCType(m->type,elems);
struct string offsetTT =  string(tt);
offsetTT.replace((struct string*)&offsetTT,"*","");
char * ____BAH_COMPILER_VAR_604 =mCtype.str((struct string*)&mCtype);char * ____BAH_COMPILER_VAR_605 =offsetTT.str((struct string*)&offsetTT);char * ____BAH_COMPILER_VAR_606 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("(");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_604);
long int strLen_2 = strlen("*)((char*)(");
long int strLen_3 = strlen(t.cont);
long int strLen_4 = strlen(") + offsetof(struct ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_605);
long int strLen_6 = strlen(", ");
long int strLen_7 = strlen(m->name);
long int strLen_8 = strlen("))");
;                            
                        ____BAH_COMPILER_VAR_606 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                        
                        strncpy(____BAH_COMPILER_VAR_606+currStrOff, "(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_606+currStrOff, ____BAH_COMPILER_VAR_604, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_606+currStrOff, "*)((char*)(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_606+currStrOff, t.cont, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_606+currStrOff, ") + offsetof(struct ", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_606+currStrOff, ____BAH_COMPILER_VAR_605, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_606+currStrOff, ", ", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_606+currStrOff, m->name, strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_606+currStrOff, "))", strLen_8);
                        currStrOff += strLen_8;
                        
                    }
                    tmpT.cont =  ____BAH_COMPILER_VAR_606;
char * ____BAH_COMPILER_VAR_607 =offsetTT.str((struct string*)&offsetTT);char * ____BAH_COMPILER_VAR_608 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("offsetof(struct ");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_607);
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(m->name);
long int strLen_4 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_608 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_608+currStrOff, "offsetof(struct ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_608+currStrOff, ____BAH_COMPILER_VAR_607, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_608+currStrOff, ", ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_608+currStrOff, m->name, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_608+currStrOff, ")", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    struct Tok rt =  parseReflect(tmpT,m->type,elems,true,m->name,____BAH_COMPILER_VAR_608);
char * ____BAH_COMPILER_VAR_609 =intToStr(i);char * ____BAH_COMPILER_VAR_610 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(structLayout);
long int strLen_1 = strlen("->data[");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_609);
long int strLen_3 = strlen("] = ");
long int strLen_4 = strlen(rt.cont);
long int strLen_5 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_610 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_610+currStrOff, structLayout, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_610+currStrOff, "->data[", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_610+currStrOff, ____BAH_COMPILER_VAR_609, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_610+currStrOff, "] = ", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_610+currStrOff, rt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_610+currStrOff, ";\n", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    dataLayout =  dataLayout->add(dataLayout, rope(____BAH_COMPILER_VAR_610));
i =  i + 1;
};
char * ____BAH_COMPILER_VAR_611 =intToStr(len(ts->members));char * ____BAH_COMPILER_VAR_612 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\n        array(struct reflectElement) * ");
long int strLen_1 = strlen(structLayout);
long int strLen_2 = strlen(" = memoryAlloc(sizeof(array(struct reflectElement)));\n        ");
long int strLen_3 = strlen(structLayout);
long int strLen_4 = strlen("->elemSize = sizeof(struct reflectElement);\n        ");
long int strLen_5 = strlen(structLayout);
long int strLen_6 = strlen("->length = ");
long int strLen_7 = strlen(____BAH_COMPILER_VAR_611);
long int strLen_8 = strlen(";\n        ");
long int strLen_9 = strlen(structLayout);
long int strLen_10 = strlen("->data = memoryAlloc(");
long int strLen_11 = strlen(structLayout);
long int strLen_12 = strlen("->length * ");
long int strLen_13 = strlen(structLayout);
long int strLen_14 = strlen("->elemSize);\n        ");
;                            
                        ____BAH_COMPILER_VAR_612 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14);
                        
                        strncpy(____BAH_COMPILER_VAR_612+currStrOff, "\n        array(struct reflectElement) * ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_612+currStrOff, structLayout, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_612+currStrOff, " = memoryAlloc(sizeof(array(struct reflectElement)));\n        ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_612+currStrOff, structLayout, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_612+currStrOff, "->elemSize = sizeof(struct reflectElement);\n        ", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_612+currStrOff, structLayout, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_612+currStrOff, "->length = ", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_612+currStrOff, ____BAH_COMPILER_VAR_611, strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_612+currStrOff, ";\n        ", strLen_8);
                        currStrOff += strLen_8;
                        
                        strncpy(____BAH_COMPILER_VAR_612+currStrOff, structLayout, strLen_9);
                        currStrOff += strLen_9;
                        
                        strncpy(____BAH_COMPILER_VAR_612+currStrOff, "->data = memoryAlloc(", strLen_10);
                        currStrOff += strLen_10;
                        
                        strncpy(____BAH_COMPILER_VAR_612+currStrOff, structLayout, strLen_11);
                        currStrOff += strLen_11;
                        
                        strncpy(____BAH_COMPILER_VAR_612+currStrOff, "->length * ", strLen_12);
                        currStrOff += strLen_12;
                        
                        strncpy(____BAH_COMPILER_VAR_612+currStrOff, structLayout, strLen_13);
                        currStrOff += strLen_13;
                        
                        strncpy(____BAH_COMPILER_VAR_612+currStrOff, "->elemSize);\n        ", strLen_14);
                        currStrOff += strLen_14;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_612))->add(OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_612)), dataLayout);
}
char * amp =  "";
if (((((strCount(tt,"*")==0)&&(__checkString(tt, "/home/alois/Documents/bah-bah/src/parser.bah:1249 tt ")==1&&strcmp(tt, "cpstring") != 0))&&(__checkString(tt, "/home/alois/Documents/bah-bah/src/parser.bah:1249 tt ")==1&&strcmp(tt, "ptr") != 0))&&(parsedPointer==false))) {
amp =  "&";
}
struct string name =  string(ogName);
if ((hasStructSep(name)==true)) {
name =  splitStructSepAfter(name);
}
struct string cType =  getCType(tt,elems);
if (cType.hasPrefix((struct string*)&cType,"struct ")) {
cType.replace((struct string*)&cType,"*","");
}
if ((cType.length==0)) {
cType.set((struct string*)&cType,"0");
}
struct variable* ____BAH_COMPILER_VAR_613 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_613->name = "";
____BAH_COMPILER_VAR_613->type = "";
____BAH_COMPILER_VAR_613->isConst = false;
____BAH_COMPILER_VAR_613->constVal = "";
____BAH_COMPILER_VAR_613->isArray = false;
____BAH_COMPILER_VAR_613->from = "";
____BAH_COMPILER_VAR_613->outterScope = false;
struct variable* rv =  ____BAH_COMPILER_VAR_613;
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
char * ____BAH_COMPILER_VAR_614 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_615 =name.str((struct string*)&name);char * ____BAH_COMPILER_VAR_616 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("struct reflectElement ");
long int strLen_1 = strlen(rv->name);
long int strLen_2 = strlen(" = __reflect(");
long int strLen_3 = strlen(amp);
long int strLen_4 = strlen(t.cont);
long int strLen_5 = strlen(", sizeof(");
long int strLen_6 = strlen(____BAH_COMPILER_VAR_614);
long int strLen_7 = strlen("), \"");
long int strLen_8 = strlen(tt);
long int strLen_9 = strlen("\", \"");
long int strLen_10 = strlen(____BAH_COMPILER_VAR_615);
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
                        ____BAH_COMPILER_VAR_616 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14 + strLen_15 + strLen_16 + strLen_17 + strLen_18 + strLen_19 + strLen_20 + strLen_21);
                        
                        strncpy(____BAH_COMPILER_VAR_616+currStrOff, "struct reflectElement ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_616+currStrOff, rv->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_616+currStrOff, " = __reflect(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_616+currStrOff, amp, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_616+currStrOff, t.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_616+currStrOff, ", sizeof(", strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_616+currStrOff, ____BAH_COMPILER_VAR_614, strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_616+currStrOff, "), \"", strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_616+currStrOff, tt, strLen_8);
                        currStrOff += strLen_8;
                        
                        strncpy(____BAH_COMPILER_VAR_616+currStrOff, "\", \"", strLen_9);
                        currStrOff += strLen_9;
                        
                        strncpy(____BAH_COMPILER_VAR_616+currStrOff, ____BAH_COMPILER_VAR_615, strLen_10);
                        currStrOff += strLen_10;
                        
                        strncpy(____BAH_COMPILER_VAR_616+currStrOff, "\", ", strLen_11);
                        currStrOff += strLen_11;
                        
                        strncpy(____BAH_COMPILER_VAR_616+currStrOff, isArr, strLen_12);
                        currStrOff += strLen_12;
                        
                        strncpy(____BAH_COMPILER_VAR_616+currStrOff, ", ", strLen_13);
                        currStrOff += strLen_13;
                        
                        strncpy(____BAH_COMPILER_VAR_616+currStrOff, arrElem, strLen_14);
                        currStrOff += strLen_14;
                        
                        strncpy(____BAH_COMPILER_VAR_616+currStrOff, ", ", strLen_15);
                        currStrOff += strLen_15;
                        
                        strncpy(____BAH_COMPILER_VAR_616+currStrOff, isStruct, strLen_16);
                        currStrOff += strLen_16;
                        
                        strncpy(____BAH_COMPILER_VAR_616+currStrOff, ", ", strLen_17);
                        currStrOff += strLen_17;
                        
                        strncpy(____BAH_COMPILER_VAR_616+currStrOff, structLayout, strLen_18);
                        currStrOff += strLen_18;
                        
                        strncpy(____BAH_COMPILER_VAR_616+currStrOff, ", ", strLen_19);
                        currStrOff += strLen_19;
                        
                        strncpy(____BAH_COMPILER_VAR_616+currStrOff, offset, strLen_20);
                        currStrOff += strLen_20;
                        
                        strncpy(____BAH_COMPILER_VAR_616+currStrOff, ");\n", strLen_21);
                        currStrOff += strLen_21;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_616));
t.cont =  rv->name;
struct Tok ____BAH_COMPILER_VAR_617 = t;
return ____BAH_COMPILER_VAR_617;
};
__BAH_ARR_TYPE_Tok parseFnCall(__BAH_ARR_TYPE_Tok l,lineType ltp,struct Elems* elems){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
int found =  false;
long int i =  0;
while ((i<len(l))) {

                if (l->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1287): l[%d] with length %d\n", i, l->length);
                    exit(1);
                };
                struct Tok t =  l->data[i];
if ((t.type==TOKEN_TYPE_VAR)) {
i =  i + 1;
if ((i<len(l))) {

                if (l->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1291): l[%d] with length %d\n", i, l->length);
                    exit(1);
                };
                t =  l->data[i];
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:1292 t.cont ")==1&&strcmp(t.cont, "(") == 0)) {
found =  true;
break;
}
}
}
i =  i + 1;
};
if ((found==false)) {
array(struct Tok)* ____BAH_COMPILER_VAR_618 = l;
return ____BAH_COMPILER_VAR_618;
}
i =  0;
while ((i<len(l))) {

                if (l->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1306): l[%d] with length %d\n", i, l->length);
                    exit(1);
                };
                struct Tok ot =  l->data[i];
if ((ot.type==TOKEN_TYPE_VAR)) {
i =  i + 1;
if ((i<len(l))) {

                if (l->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1311): l[%d] with length %d\n", i, l->length);
                    exit(1);
                };
                struct Tok nt =  l->data[i];
if ((__checkString(nt.cont, "/home/alois/Documents/bah-bah/src/parser.bah:1312 nt.cont ")==1&&strcmp(nt.cont, "(") == 0)) {
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
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1324): fn->args[%d] with length %d\n", 0, fn->args->length);
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
char * ____BAH_COMPILER_VAR_619 =fnarg1t.str((struct string*)&fnarg1t);char * ____BAH_COMPILER_VAR_620 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("(");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_619);
long int strLen_2 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_620 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_620+currStrOff, "(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_620+currStrOff, ____BAH_COMPILER_VAR_619, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_620+currStrOff, ")", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    varName.prepend((struct string*)&varName,____BAH_COMPILER_VAR_620);
}
char * ____BAH_COMPILER_VAR_621 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(fnName);
long int strLen_1 = strlen("(");
;                            
                        ____BAH_COMPILER_VAR_621 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_621+currStrOff, fnName, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_621+currStrOff, "(", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    ot.cont =  ____BAH_COMPILER_VAR_621;
long int paramIndex =  0;
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
if ((varName.length>0)) {
struct Tok ____BAH_COMPILER_VAR_622 = {};
____BAH_COMPILER_VAR_622.cont = "";
____BAH_COMPILER_VAR_622.ogCont = "";
____BAH_COMPILER_VAR_622.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_622.pos = 0;
____BAH_COMPILER_VAR_622.line = 1;
____BAH_COMPILER_VAR_622.begLine = 1;
____BAH_COMPILER_VAR_622.bahType = "";
____BAH_COMPILER_VAR_622.isValue = false;
____BAH_COMPILER_VAR_622.isFunc = false;
____BAH_COMPILER_VAR_622.isOper = false;
struct Tok tk =  ____BAH_COMPILER_VAR_622;
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
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1357): l[%d] with length %d\n", i, l->length);
                    exit(1);
                };
                nt =  l->data[i];
if ((__checkString(nt.cont, "/home/alois/Documents/bah-bah/src/parser.bah:1358 nt.cont ")==1&&strcmp(nt.cont, ")") != 0)) {
struct Tok ____BAH_COMPILER_VAR_623 = {};
____BAH_COMPILER_VAR_623.cont = "";
____BAH_COMPILER_VAR_623.ogCont = "";
____BAH_COMPILER_VAR_623.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_623.pos = 0;
____BAH_COMPILER_VAR_623.line = 1;
____BAH_COMPILER_VAR_623.begLine = 1;
____BAH_COMPILER_VAR_623.bahType = "";
____BAH_COMPILER_VAR_623.isValue = false;
____BAH_COMPILER_VAR_623.isFunc = false;
____BAH_COMPILER_VAR_623.isOper = false;
tk =  ____BAH_COMPILER_VAR_623;
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
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1367): l[%d] with length %d\n", i, l->length);
                    exit(1);
                };
                struct Tok t =  l->data[i];
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:1368 t.cont ")==1&&strcmp(t.cont, "(") == 0)) {
nbPar =  nbPar + 1;
}
else if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:1370 t.cont ")==1&&strcmp(t.cont, ")") == 0)) {
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
if ((__checkString(fnName, "/home/alois/Documents/bah-bah/src/parser.bah:1381 fnName ")==1&&strcmp(fnName, "noCheck") == 0)) {
long int j =  0;
while ((j<len(memory))) {

                if (memory->length <= j) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1383): memory[%d] with length %d\n", j, memory->length);
                    exit(1);
                };
                struct Tok t =  memory->data[j];
char * ____BAH_COMPILER_VAR_624 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(ot.cont);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(t.cont);
;                            
                        ____BAH_COMPILER_VAR_624 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_624+currStrOff, ot.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_624+currStrOff, " ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_624+currStrOff, t.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    ot.cont =  ____BAH_COMPILER_VAR_624;
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
if ((__checkString(fnName, "/home/alois/Documents/bah-bah/src/parser.bah:1395 fnName ")==1&&strcmp(fnName, "panic") == 0)) {
char * ____BAH_COMPILER_VAR_625 =intToStr(ot.line);char * ____BAH_COMPILER_VAR_626 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\"");
long int strLen_1 = strlen(compilerState.currentFile);
long int strLen_2 = strlen(":");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_625);
long int strLen_4 = strlen("\"");
;                            
                        ____BAH_COMPILER_VAR_626 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_626+currStrOff, "\"", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_626+currStrOff, compilerState.currentFile, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_626+currStrOff, ":", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_626+currStrOff, ____BAH_COMPILER_VAR_625, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_626+currStrOff, "\"", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    char * currLine =  ____BAH_COMPILER_VAR_626;

                if (memory->length <= len(memory)-1) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1397): memory[%d] with length %d\n", len(memory)-1, memory->length);
                    exit(1);
                };
                struct Tok par =  memory->data[len(memory)-1];
long int cl =  par.line;
struct Tok ____BAH_COMPILER_VAR_627 = {};
____BAH_COMPILER_VAR_627.cont = "";
____BAH_COMPILER_VAR_627.ogCont = "";
____BAH_COMPILER_VAR_627.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_627.pos = 0;
____BAH_COMPILER_VAR_627.line = 1;
____BAH_COMPILER_VAR_627.begLine = 1;
____BAH_COMPILER_VAR_627.bahType = "";
____BAH_COMPILER_VAR_627.isValue = false;
____BAH_COMPILER_VAR_627.isFunc = false;
____BAH_COMPILER_VAR_627.isOper = false;
____BAH_COMPILER_VAR_627.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_627.cont = ",";
____BAH_COMPILER_VAR_627.line = cl;

{
long nLength = len(memory)-1;
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)-1] =  ____BAH_COMPILER_VAR_627;
memory->length = nLength+1;
} else {
memory->data[len(memory)-1] =  ____BAH_COMPILER_VAR_627;
}
};
struct Tok ____BAH_COMPILER_VAR_628 = {};
____BAH_COMPILER_VAR_628.cont = "";
____BAH_COMPILER_VAR_628.ogCont = "";
____BAH_COMPILER_VAR_628.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_628.pos = 0;
____BAH_COMPILER_VAR_628.line = 1;
____BAH_COMPILER_VAR_628.begLine = 1;
____BAH_COMPILER_VAR_628.bahType = "";
____BAH_COMPILER_VAR_628.isValue = false;
____BAH_COMPILER_VAR_628.isFunc = false;
____BAH_COMPILER_VAR_628.isOper = false;
____BAH_COMPILER_VAR_628.type = TOKEN_TYPE_STR;
____BAH_COMPILER_VAR_628.cont = currLine;
____BAH_COMPILER_VAR_628.line = cl;

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] =  ____BAH_COMPILER_VAR_628;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  ____BAH_COMPILER_VAR_628;
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
char * ____BAH_COMPILER_VAR_629 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(fnName);
long int strLen_1 = strlen("(");
;                            
                        ____BAH_COMPILER_VAR_629 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_629+currStrOff, fnName, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_629+currStrOff, "(", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    ot.cont =  ____BAH_COMPILER_VAR_629;
fn =  searchFunc(fnName,elems,true);
}
memory =  prePross(memory,ltp,elems);

                if (memory->length <= 0) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1417): memory[%d] with length %d\n", 0, memory->length);
                    exit(1);
                };
                struct Tok ft =  memory->data[0];
array(struct Tok)* fnArgs = memoryAlloc(sizeof(array(struct Tok)));

fnArgs->length = 0;
fnArgs->elemSize = sizeof(struct Tok);
if ((__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:1421 ft.cont ")==1&&strcmp(ft.cont, ")") != 0)) {
long int j =  0;
while ((j<len(memory))) {

                if (memory->length <= j) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1424): memory[%d] with length %d\n", j, memory->length);
                    exit(1);
                };
                struct Tok t =  memory->data[j];
if ((paramIndex>=len(fn->args))) {
throwErr(&t,"Too many arguments in function call.");
}

                if (fn->args->length <= paramIndex) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1429): fn->args[%d] with length %d\n", paramIndex, fn->args->length);
                    exit(1);
                };
                struct variable* arg =  fn->args->data[paramIndex];
char * tt =  getTypeFromToken(&t,true,elems);
if (((__checkString(arg->type, "/home/alois/Documents/bah-bah/src/parser.bah:1432 arg->type ")==1&&strcmp(arg->type, "reflectElement") == 0)&&(__checkString(tt, "/home/alois/Documents/bah-bah/src/parser.bah:1432 tt ")==1&&strcmp(tt, "reflectElement") != 0))) {
t =  parseReflect(t,tt,elems,false,t.cont,"0");
tt =  "reflectElement";
}
if ((compTypes(tt,arg->type)==false)) {
char * ____BAH_COMPILER_VAR_630 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(tt);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(arg->type);
long int strLen_4 = strlen(" in function call.");
;                            
                        ____BAH_COMPILER_VAR_630 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_630+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_630+currStrOff, tt, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_630+currStrOff, ") as ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_630+currStrOff, arg->type, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_630+currStrOff, " in function call.", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    throwErr(&t,____BAH_COMPILER_VAR_630);
}
if (((t.type==TOKEN_TYPE_FUNC)&&(strHasPrefix(t.cont,"noCheck(")==false))) {
struct string ____BAH_COMPILER_VAR_631 =string(t.cont);char * afnName =  splitStringBefore(____BAH_COMPILER_VAR_631,"(");
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
char * ____BAH_COMPILER_VAR_632 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(ot.cont);
long int strLen_1 = strlen(t.cont);
;                            
                        ____BAH_COMPILER_VAR_632 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_632+currStrOff, ot.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_632+currStrOff, t.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    ot.cont =  ____BAH_COMPILER_VAR_632;
j =  j + 1;

                if (memory->length <= j) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1455): memory[%d] with length %d\n", j, memory->length);
                    exit(1);
                };
                t =  memory->data[j];
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:1456 t.cont ")==1&&strcmp(t.cont, ",") != 0)) {
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:1457 t.cont ")==1&&strcmp(t.cont, ")") == 0)) {
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
char * ____BAH_COMPILER_VAR_633 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(ot.cont);
long int strLen_1 = strlen(",");
;                            
                        ____BAH_COMPILER_VAR_633 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_633+currStrOff, ot.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_633+currStrOff, ",", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    ot.cont =  ____BAH_COMPILER_VAR_633;
}
j =  j + 1;
};
}
if ((paramIndex<len(fn->args))) {
ot.cont =  fnName;
throwErr(&ot,"Not enough arguments in function call, ending by {TOKEN}.");
}
if ((__checkString(fn->name, "/home/alois/Documents/bah-bah/src/parser.bah:1478 fn->name ")==1&&strcmp(fn->name, "ser") == 0)) {
ot.cont =  parseSerialize(memory->data[0],elems);
}
else {
char * ____BAH_COMPILER_VAR_634 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(ot.cont);
long int strLen_1 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_634 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_634+currStrOff, ot.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_634+currStrOff, ")", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    ot.cont =  ____BAH_COMPILER_VAR_634;
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
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1488): l[%d] with length %d\n", 0, l->length);
                    exit(1);
                };
                ft =  l->data[0];
if (((verboseRuntime==true)&&(ltp!=LINE_TYPE_ELSE))) {
verboseOutFunc(fn,fnArgs,ft.line,elems);
}
continue;
}
}
i =  i - 1;
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
i =  i + 1;
};
array(struct Tok)* ____BAH_COMPILER_VAR_635 = nl;
return ____BAH_COMPILER_VAR_635;
};
char * parseArrayDecl(struct variable* v,__BAH_ARR_TYPE_Tok l,long int i,long int max,struct Elems* elems){
long int arrayLength =  0;
struct string arrType =  getCType(v->type,elems);
arrType.trimRight((struct string*)&arrType,1);
char * ____BAH_COMPILER_VAR_636 =arrType.str((struct string*)&arrType);char * ____BAH_COMPILER_VAR_637 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("memoryAlloc(sizeof(");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_636);
long int strLen_2 = strlen("))");
;                            
                        ____BAH_COMPILER_VAR_637 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_637+currStrOff, "memoryAlloc(sizeof(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_637+currStrOff, ____BAH_COMPILER_VAR_636, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_637+currStrOff, "))", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    char * code =  ____BAH_COMPILER_VAR_637;
arrType.trimLeft((struct string*)&arrType,6);
arrType.trimRight((struct string*)&arrType,1);
char * elemTypeStr =  arrType.str((struct string*)&arrType);
if ((i + 1!=max)) {
i =  i + 1;

                if (l->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1518): l[%d] with length %d\n", i, l->length);
                    exit(1);
                };
                struct Tok nt =  l->data[i];
if ((__checkString(nt.cont, "/home/alois/Documents/bah-bah/src/parser.bah:1519 nt.cont ")==1&&strcmp(nt.cont, "{") != 0)) {
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
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1528): l[%d] with length %d\n", i, l->length);
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
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1533): memory[%d] with length %d\n", i, memory->length);
                    exit(1);
                };
                struct Tok t =  memory->data[i];
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:1534 t.cont ")==1&&strcmp(t.cont, "{") == 0)) {
long int j =  i-1;
long int nbBraces =  0;
for (; (i<len(memory)); i =  i+1) {

                if (memory->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1539): memory[%d] with length %d\n", i, memory->length);
                    exit(1);
                };
                struct Tok tmpT =  memory->data[i];
if ((__checkString(tmpT.cont, "/home/alois/Documents/bah-bah/src/parser.bah:1540 tmpT.cont ")==1&&strcmp(tmpT.cont, "{") == 0)) {
nbBraces =  nbBraces+1;
}
else if ((__checkString(tmpT.cont, "/home/alois/Documents/bah-bah/src/parser.bah:1542 tmpT.cont ")==1&&strcmp(tmpT.cont, "}") == 0)) {
nbBraces =  nbBraces-1;
}
if ((nbBraces==0)) {
break;
}
};
struct variable* ____BAH_COMPILER_VAR_638 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_638->name = "";
____BAH_COMPILER_VAR_638->type = "";
____BAH_COMPILER_VAR_638->isConst = false;
____BAH_COMPILER_VAR_638->constVal = "";
____BAH_COMPILER_VAR_638->isArray = false;
____BAH_COMPILER_VAR_638->from = "";
____BAH_COMPILER_VAR_638->outterScope = false;
struct variable* tmpV =  ____BAH_COMPILER_VAR_638;
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
char * ____BAH_COMPILER_VAR_639 =elemType.str((struct string*)&elemType);struct string cType =  getCType(____BAH_COMPILER_VAR_639,elems);
char * ____BAH_COMPILER_VAR_640 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_641 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\n                array(");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_640);
long int strLen_2 = strlen(") * ");
long int strLen_3 = strlen(tmpV->name);
long int strLen_4 = strlen(" = ");
long int strLen_5 = strlen(innerCode);
long int strLen_6 = strlen(";\n                ");
long int strLen_7 = strlen(NEXT_LINE);
long int strLen_8 = strlen("\n                ");
;                            
                        ____BAH_COMPILER_VAR_641 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                        
                        strncpy(____BAH_COMPILER_VAR_641+currStrOff, "\n                array(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_641+currStrOff, ____BAH_COMPILER_VAR_640, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_641+currStrOff, ") * ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_641+currStrOff, tmpV->name, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_641+currStrOff, " = ", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_641+currStrOff, innerCode, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_641+currStrOff, ";\n                ", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_641+currStrOff, NEXT_LINE, strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_641+currStrOff, "\n                ", strLen_8);
                        currStrOff += strLen_8;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_641));
NEXT_LINE =  oldNL;
struct Tok ____BAH_COMPILER_VAR_642 = {};
____BAH_COMPILER_VAR_642.cont = "";
____BAH_COMPILER_VAR_642.ogCont = "";
____BAH_COMPILER_VAR_642.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_642.pos = 0;
____BAH_COMPILER_VAR_642.line = 1;
____BAH_COMPILER_VAR_642.begLine = 1;
____BAH_COMPILER_VAR_642.bahType = "";
____BAH_COMPILER_VAR_642.isValue = false;
____BAH_COMPILER_VAR_642.isFunc = false;
____BAH_COMPILER_VAR_642.isOper = false;
____BAH_COMPILER_VAR_642.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_642.cont = tmpV->name;
____BAH_COMPILER_VAR_642.bahType = elemType.str((struct string*)&elemType);
____BAH_COMPILER_VAR_642.isValue = true;
t =  ____BAH_COMPILER_VAR_642;
}
char * tt =  getTypeFromToken(&t,true,elems);
if ((compTypes(tt,elemBahTypeStr)==false)) {
char * ____BAH_COMPILER_VAR_643 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(tt);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(elemBahTypeStr);
;                            
                        ____BAH_COMPILER_VAR_643 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                        
                        strncpy(____BAH_COMPILER_VAR_643+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_643+currStrOff, tt, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_643+currStrOff, ") as ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_643+currStrOff, elemBahTypeStr, strLen_3);
                        currStrOff += strLen_3;
                        
                    }
                    throwErr(&t,____BAH_COMPILER_VAR_643);
}
char * strArrayLength =  intToStr(arrayLength);
arrayLength =  arrayLength + 1;
char * ____BAH_COMPILER_VAR_644 =null;
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
                        ____BAH_COMPILER_VAR_644 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                        
                        strncpy(____BAH_COMPILER_VAR_644+currStrOff, NEXT_LINE, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_644+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_644+currStrOff, "->data[", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_644+currStrOff, strArrayLength, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_644+currStrOff, "] = ", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_644+currStrOff, t.cont, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_644+currStrOff, ";\n", strLen_6);
                        currStrOff += strLen_6;
                        
                    }
                    NEXT_LINE =  ____BAH_COMPILER_VAR_644;
i =  i+1;

                if (memory->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1584): memory[%d] with length %d\n", i, memory->length);
                    exit(1);
                };
                t =  memory->data[i];
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:1586 t.cont ")==1&&strcmp(t.cont, ",") != 0)) {
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:1587 t.cont ")==1&&strcmp(t.cont, "}") == 0)) {
long int allocLength =  arrayLength;
if ((allocLength>50)) {
long int modAllocAmm =  allocLength % 50;
allocLength =  allocLength + modAllocAmm;
}
else {
allocLength =  50;
}
char * allocLengthStr =  intToStr(allocLength);
char * ____BAH_COMPILER_VAR_645 =null;
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
                        ____BAH_COMPILER_VAR_645 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                        
                        strncpy(____BAH_COMPILER_VAR_645+currStrOff, v->name, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_645+currStrOff, "->data = memoryAlloc(sizeof(", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_645+currStrOff, elemTypeStr, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_645+currStrOff, ") * ", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_645+currStrOff, allocLengthStr, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_645+currStrOff, ");", strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_645+currStrOff, NEXT_LINE, strLen_6);
                        currStrOff += strLen_6;
                        
                    }
                    NEXT_LINE =  ____BAH_COMPILER_VAR_645;
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
char * ____BAH_COMPILER_VAR_646 =null;
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
                        ____BAH_COMPILER_VAR_646 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9);
                        
                        strncpy(____BAH_COMPILER_VAR_646+currStrOff, "\n", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_646+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_646+currStrOff, "->length = ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_646+currStrOff, strArrayLength, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_646+currStrOff, ";\n", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_646+currStrOff, v->name, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_646+currStrOff, "->elemSize = sizeof(", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_646+currStrOff, elemTypeStr, strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_646+currStrOff, ");\n", strLen_8);
                        currStrOff += strLen_8;
                        
                        strncpy(____BAH_COMPILER_VAR_646+currStrOff, NEXT_LINE, strLen_9);
                        currStrOff += strLen_9;
                        
                    }
                    NEXT_LINE =  ____BAH_COMPILER_VAR_646;
char * ____BAH_COMPILER_VAR_647 = code;
return ____BAH_COMPILER_VAR_647;
};
array(char *)* equalsTokens;
void parseVar(__BAH_ARR_TYPE_Tok l,struct Elems* elems){

                if (l->length <= 0) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1616): l[%d] with length %d\n", 0, l->length);
                    exit(1);
                };
                struct Tok ft =  l->data[0];
if ((ft.isFunc==true)) {
if ((len(l)>1)) {
throwErr(&l->data[len(l)-1],"Not expecting {TOKEN} after function call.");
}

                if (l->length <= 0) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1621): l[%d] with length %d\n", 0, l->length);
                    exit(1);
                };
                ft =  l->data[0];
int parsed =  true;
char * ____BAH_COMPILER_VAR_648 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(ft.cont);
long int strLen_1 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_648 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_648+currStrOff, ft.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_648+currStrOff, ";\n", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_648));
return;
}
l =  parseStructType(l,(lineType)-1,elems);
int isEqual =  false;
int toVar =  false;
int isPointedVar =  false;
int isStruct =  false;
char * currentType =  "";

                if (l->length <= 0) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1632): l[%d] with length %d\n", 0, l->length);
                    exit(1);
                };
                ft =  l->data[0];
struct variable* v =  searchVar(ft.cont,elems);
int exists =  true;
char * ogName= null;
if ((v==null)) {
exists =  false;
struct variable* ____BAH_COMPILER_VAR_650 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_650->name = "";
____BAH_COMPILER_VAR_650->type = "";
____BAH_COMPILER_VAR_650->isConst = false;
____BAH_COMPILER_VAR_650->constVal = "";
____BAH_COMPILER_VAR_650->isArray = false;
____BAH_COMPILER_VAR_650->from = "";
____BAH_COMPILER_VAR_650->outterScope = false;
v =  ____BAH_COMPILER_VAR_650;
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
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1654): l[%d] with length %d\n", 1, l->length);
                    exit(1);
                };
                struct Tok lt =  l->data[1];
if ((((lt.type==TOKEN_TYPE_SYNTAX)&&(__checkString(lt.cont, "/home/alois/Documents/bah-bah/src/parser.bah:1655 lt.cont ")==1&&strcmp(lt.cont, "++") == 0))||(__checkString(lt.cont, "/home/alois/Documents/bah-bah/src/parser.bah:1655 lt.cont ")==1&&strcmp(lt.cont, "--") == 0))) {
if ((exists==false)) {
char * ____BAH_COMPILER_VAR_651 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot use '");
long int strLen_1 = strlen(lt.cont);
long int strLen_2 = strlen("' on non declared {TOKEN} variable.");
;                            
                        ____BAH_COMPILER_VAR_651 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_651+currStrOff, "Cannot use '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_651+currStrOff, lt.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_651+currStrOff, "' on non declared {TOKEN} variable.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    throwErr(&ft,____BAH_COMPILER_VAR_651);
}
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);

                if (l->length <= 0) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1660): l[%d] with length %d\n", 0, l->length);
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
struct Tok ____BAH_COMPILER_VAR_652 = {};
____BAH_COMPILER_VAR_652.cont = "";
____BAH_COMPILER_VAR_652.ogCont = "";
____BAH_COMPILER_VAR_652.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_652.pos = 0;
____BAH_COMPILER_VAR_652.line = 1;
____BAH_COMPILER_VAR_652.begLine = 1;
____BAH_COMPILER_VAR_652.bahType = "";
____BAH_COMPILER_VAR_652.isValue = false;
____BAH_COMPILER_VAR_652.isFunc = false;
____BAH_COMPILER_VAR_652.isOper = false;
____BAH_COMPILER_VAR_652.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_652.cont = "=";
____BAH_COMPILER_VAR_652.isValue = false;

{
long nLength = 1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[1] =  ____BAH_COMPILER_VAR_652;
nl->length = nLength+1;
} else {
nl->data[1] =  ____BAH_COMPILER_VAR_652;
}
};
char * c =  "";
if ((__checkString(lt.cont, "/home/alois/Documents/bah-bah/src/parser.bah:1669 lt.cont ")==1&&strcmp(lt.cont, "++") == 0)) {
char * ____BAH_COMPILER_VAR_653 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(ft.cont);
long int strLen_1 = strlen("+1");
;                            
                        ____BAH_COMPILER_VAR_653 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_653+currStrOff, ft.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_653+currStrOff, "+1", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    c =  ____BAH_COMPILER_VAR_653;
}
else if ((__checkString(lt.cont, "/home/alois/Documents/bah-bah/src/parser.bah:1671 lt.cont ")==1&&strcmp(lt.cont, "--") == 0)) {
char * ____BAH_COMPILER_VAR_654 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(ft.cont);
long int strLen_1 = strlen("-1");
;                            
                        ____BAH_COMPILER_VAR_654 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_654+currStrOff, ft.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_654+currStrOff, "-1", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    c =  ____BAH_COMPILER_VAR_654;
}
long int ltl =  lt.line;
long int ltp =  lt.pos;
char * ltc =  lt.cont;
struct Tok ____BAH_COMPILER_VAR_655 = {};
____BAH_COMPILER_VAR_655.cont = "";
____BAH_COMPILER_VAR_655.ogCont = "";
____BAH_COMPILER_VAR_655.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_655.pos = 0;
____BAH_COMPILER_VAR_655.line = 1;
____BAH_COMPILER_VAR_655.begLine = 1;
____BAH_COMPILER_VAR_655.bahType = "";
____BAH_COMPILER_VAR_655.isValue = false;
____BAH_COMPILER_VAR_655.isFunc = false;
____BAH_COMPILER_VAR_655.isOper = false;
____BAH_COMPILER_VAR_655.type = TOKEN_TYPE_INT;
____BAH_COMPILER_VAR_655.cont = c;
____BAH_COMPILER_VAR_655.line = ltl;
____BAH_COMPILER_VAR_655.ogCont = ltc;
____BAH_COMPILER_VAR_655.pos = ltp;
____BAH_COMPILER_VAR_655.isOper = true;
____BAH_COMPILER_VAR_655.isValue = true;

{
long nLength = 2;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[2] =  ____BAH_COMPILER_VAR_655;
nl->length = nLength+1;
} else {
nl->data[2] =  ____BAH_COMPILER_VAR_655;
}
};
l =  nl;
}
}

                if (l->length <= 1) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1692): l[%d] with length %d\n", 1, l->length);
                    exit(1);
                };
                struct Tok operT =  l->data[1];

                int ____BAH_COMPILER_VAR_656 = 0;
                for(int i=len(equalsTokens)-1; i != -1; i--) {
                    if (equalsTokens->data[i] != 0 && strcmp(equalsTokens->data[i], operT.cont) == 0) {
                        ____BAH_COMPILER_VAR_656 = 1;
                        break;
                    };
                };
                if ((____BAH_COMPILER_VAR_656&&(__checkString(operT.cont, "/home/alois/Documents/bah-bah/src/parser.bah:1693 operT.cont ")==1&&strcmp(operT.cont, "=") != 0))) {

                if (l->length <= 0) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1694): l[%d] with length %d\n", 0, l->length);
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
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1706): l[%d] with length %d\n", 2, l->length);
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
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1715): tmpL[%d] with length %d\n", j, tmpL->length);
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
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1762): l[%d] with length %d\n", i, l->length);
                    exit(1);
                };
                struct Tok t =  l->data[i];
if ((t.type==TOKEN_TYPE_SYNTAX)) {
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:1764 t.cont ")==1&&strcmp(t.cont, "=") == 0)) {
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
char * ____BAH_COMPILER_VAR_657 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(currentType);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(t.cont);
;                            
                        ____BAH_COMPILER_VAR_657 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_657+currStrOff, currentType, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_657+currStrOff, " ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_657+currStrOff, t.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    currentType =  ____BAH_COMPILER_VAR_657;
}
else {
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:1804 t.cont ")==1&&strcmp(t.cont, "chan") == 0)) {
if ((i>=len(l))) {
throwErr(&t,"Cannot declare a {TOKEN} without a type (chan <type>).");
}
i =  i+1;

                if (l->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1809): l[%d] with length %d\n", i, l->length);
                    exit(1);
                };
                struct Tok nt =  l->data[i];
char * ____BAH_COMPILER_VAR_658 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("chan:");
long int strLen_1 = strlen(nt.cont);
;                            
                        ____BAH_COMPILER_VAR_658 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_658+currStrOff, "chan:", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_658+currStrOff, nt.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    v->type =  ____BAH_COMPILER_VAR_658;
code =  "channel()";
if ((i + 1!=len(l))) {

                if (l->length <= i + 1) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1813): l[%d] with length %d\n", i + 1, l->length);
                    exit(1);
                };
                struct Tok errT =  l->data[i + 1];
throwErr(&errT,"{TOKEN} not expected after channel declaration.");
}
break;
}
if ((t.isValue==false)) {
throwErr(&t,"Cannot use {TOKEN} as value in var declaration.");
}
char * tp =  getTypeFromToken(&t,true,elems);
if ((exists==true)) {
if ((compTypes(tp,v->type)==false)) {
char * ____BAH_COMPILER_VAR_659 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(tp);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(v->type);
long int strLen_4 = strlen(".");
;                            
                        ____BAH_COMPILER_VAR_659 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_659+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_659+currStrOff, tp, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_659+currStrOff, ") as ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_659+currStrOff, v->type, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_659+currStrOff, ".", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    throwErr(&t,____BAH_COMPILER_VAR_659);
}
}
else {
if ((strlen(currentType)==0)) {
if ((strlen(v->type)==0)) {
v->type =  tp;
}
else {
if ((compTypes(tp,v->type)==false)) {
char * ____BAH_COMPILER_VAR_660 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(tp);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(v->type);
long int strLen_4 = strlen(".");
;                            
                        ____BAH_COMPILER_VAR_660 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_660+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_660+currStrOff, tp, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_660+currStrOff, ") as ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_660+currStrOff, v->type, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_660+currStrOff, ".", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    throwErr(&t,____BAH_COMPILER_VAR_660);
}
}
}
}
if (((strlen(t.cont)>0)&&(strHasPrefix(t.cont,"{")==false))) {
char * ____BAH_COMPILER_VAR_661 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(code);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(t.cont);
;                            
                        ____BAH_COMPILER_VAR_661 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_661+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_661+currStrOff, " ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_661+currStrOff, t.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_661;
if (((t.isOper==false)&&(RCPavailable()==true))) {
struct variable* iv =  searchVar(t.cont,elems);
if (((iv!=null)&&(iv->isConst==false))) {
toVar =  true;
isPointedVar =  strHasPrefix(t.cont,"&");
struct cStruct* s =  searchStruct(iv->type,elems);
if ((((s!=null)&&(strCount(iv->type,"*")==0))&&(s->isBinding==false))) {
if ((strCount(iv->name,"*")==0)) {
char * ____BAH_COMPILER_VAR_662 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(code);
long int strLen_1 = strlen("; RCP_incrCounter(");
long int strLen_2 = strlen(iv->name);
long int strLen_3 = strlen(".__RCP_counter)");
;                            
                        ____BAH_COMPILER_VAR_662 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                        
                        strncpy(____BAH_COMPILER_VAR_662+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_662+currStrOff, "; RCP_incrCounter(", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_662+currStrOff, iv->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_662+currStrOff, ".__RCP_counter)", strLen_3);
                        currStrOff += strLen_3;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_662;
}
else {
struct string ivn =  string(iv->name);
ivn.replace((struct string*)&ivn,"*","");
char * ____BAH_COMPILER_VAR_663 =ivn.str((struct string*)&ivn);char * ____BAH_COMPILER_VAR_664 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(code);
long int strLen_1 = strlen("; RCP_incr(");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_663);
long int strLen_3 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_664 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                        
                        strncpy(____BAH_COMPILER_VAR_664+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_664+currStrOff, "; RCP_incr(", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_664+currStrOff, ____BAH_COMPILER_VAR_663, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_664+currStrOff, ")", strLen_3);
                        currStrOff += strLen_3;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_664;
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
char * ____BAH_COMPILER_VAR_665 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(code);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(t.cont);
;                            
                        ____BAH_COMPILER_VAR_665 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_665+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_665+currStrOff, " ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_665+currStrOff, t.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_665;
}
i =  i + 1;
};
if ((exists==true)) {
if ((strlen(code)==0)) {
throwErr(&ft,"Cannot re-declare {TOKEN}.");
}
if ((strlen(currentType)>0)) {

                if (l->length <= 1) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1884): l[%d] with length %d\n", 1, l->length);
                    exit(1);
                };
                struct Tok st =  l->data[1];
char * ____BAH_COMPILER_VAR_666 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot change the type of already declared var '");
long int strLen_1 = strlen(ft.cont);
long int strLen_2 = strlen("' to {TOKEN}.");
;                            
                        ____BAH_COMPILER_VAR_666 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_666+currStrOff, "Cannot change the type of already declared var '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_666+currStrOff, ft.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_666+currStrOff, "' to {TOKEN}.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    throwErr(&st,____BAH_COMPILER_VAR_666);
}
if ((isStruct==false)) {
if (((isRCPpointerType(v->type)&&(isPointedVar==false))&&(RCPavailable()==true))) {
struct string cType =  getCType(v->type,elems);
if ((toVar==true)) {
if ((RCPselfRef(v)==false)) {
char * ____BAH_COMPILER_VAR_667 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_668 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_669 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("*(");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_667);
long int strLen_2 = strlen("*)RCP_decrIL(&");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen(") = *(");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_668);
long int strLen_6 = strlen("*)RCP_incrIL(&");
long int strLen_7 = strlen(code);
long int strLen_8 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_669 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                        
                        strncpy(____BAH_COMPILER_VAR_669+currStrOff, "*(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_669+currStrOff, ____BAH_COMPILER_VAR_667, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_669+currStrOff, "*)RCP_decrIL(&", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_669+currStrOff, v->name, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_669+currStrOff, ") = *(", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_669+currStrOff, ____BAH_COMPILER_VAR_668, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_669+currStrOff, "*)RCP_incrIL(&", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_669+currStrOff, code, strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_669+currStrOff, ")", strLen_8);
                        currStrOff += strLen_8;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_669;
}
else {
struct variable* ____BAH_COMPILER_VAR_670 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_670->name = "";
____BAH_COMPILER_VAR_670->type = "";
____BAH_COMPILER_VAR_670->isConst = false;
____BAH_COMPILER_VAR_670->constVal = "";
____BAH_COMPILER_VAR_670->isArray = false;
____BAH_COMPILER_VAR_670->from = "";
____BAH_COMPILER_VAR_670->outterScope = false;
struct variable* tmpV =  ____BAH_COMPILER_VAR_670;
tmpV->name =  genCompilerVar();
tmpV->type =  v->type;
struct rope* dv =  decrVar(tmpV,elems);
char * ____BAH_COMPILER_VAR_671 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_672 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_673 =dv->toStr((struct rope*)dv);char * ____BAH_COMPILER_VAR_674 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(____BAH_COMPILER_VAR_671);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(tmpV->name);
long int strLen_3 = strlen(" = ");
long int strLen_4 = strlen(v->name);
long int strLen_5 = strlen("; ");
long int strLen_6 = strlen(v->name);
long int strLen_7 = strlen(" = *(");
long int strLen_8 = strlen(____BAH_COMPILER_VAR_672);
long int strLen_9 = strlen("*)RCP_incrIL(&");
long int strLen_10 = strlen(code);
long int strLen_11 = strlen(");");
long int strLen_12 = strlen(____BAH_COMPILER_VAR_673);
;                            
                        ____BAH_COMPILER_VAR_674 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12);
                        
                        strncpy(____BAH_COMPILER_VAR_674+currStrOff, ____BAH_COMPILER_VAR_671, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_674+currStrOff, " ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_674+currStrOff, tmpV->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_674+currStrOff, " = ", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_674+currStrOff, v->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_674+currStrOff, "; ", strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_674+currStrOff, v->name, strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_674+currStrOff, " = *(", strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_674+currStrOff, ____BAH_COMPILER_VAR_672, strLen_8);
                        currStrOff += strLen_8;
                        
                        strncpy(____BAH_COMPILER_VAR_674+currStrOff, "*)RCP_incrIL(&", strLen_9);
                        currStrOff += strLen_9;
                        
                        strncpy(____BAH_COMPILER_VAR_674+currStrOff, code, strLen_10);
                        currStrOff += strLen_10;
                        
                        strncpy(____BAH_COMPILER_VAR_674+currStrOff, ");", strLen_11);
                        currStrOff += strLen_11;
                        
                        strncpy(____BAH_COMPILER_VAR_674+currStrOff, ____BAH_COMPILER_VAR_673, strLen_12);
                        currStrOff += strLen_12;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_674;
}
}
else {
struct variable* ____BAH_COMPILER_VAR_675 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_675->name = "";
____BAH_COMPILER_VAR_675->type = "";
____BAH_COMPILER_VAR_675->isConst = false;
____BAH_COMPILER_VAR_675->constVal = "";
____BAH_COMPILER_VAR_675->isArray = false;
____BAH_COMPILER_VAR_675->from = "";
____BAH_COMPILER_VAR_675->outterScope = false;
struct variable* tmpV =  ____BAH_COMPILER_VAR_675;
tmpV->name =  genCompilerVar();
tmpV->type =  v->type;
struct rope* dv =  decrVar(tmpV,elems);
char * ____BAH_COMPILER_VAR_676 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_677 =dv->toStr((struct rope*)dv);char * ____BAH_COMPILER_VAR_678 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(____BAH_COMPILER_VAR_676);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(tmpV->name);
long int strLen_3 = strlen(" = ");
long int strLen_4 = strlen(v->name);
long int strLen_5 = strlen("; ");
long int strLen_6 = strlen(v->name);
long int strLen_7 = strlen(" = ");
long int strLen_8 = strlen(code);
long int strLen_9 = strlen(";");
long int strLen_10 = strlen(____BAH_COMPILER_VAR_677);
;                            
                        ____BAH_COMPILER_VAR_678 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10);
                        
                        strncpy(____BAH_COMPILER_VAR_678+currStrOff, ____BAH_COMPILER_VAR_676, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_678+currStrOff, " ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_678+currStrOff, tmpV->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_678+currStrOff, " = ", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_678+currStrOff, v->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_678+currStrOff, "; ", strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_678+currStrOff, v->name, strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_678+currStrOff, " = ", strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_678+currStrOff, code, strLen_8);
                        currStrOff += strLen_8;
                        
                        strncpy(____BAH_COMPILER_VAR_678+currStrOff, ";", strLen_9);
                        currStrOff += strLen_9;
                        
                        strncpy(____BAH_COMPILER_VAR_678+currStrOff, ____BAH_COMPILER_VAR_677, strLen_10);
                        currStrOff += strLen_10;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_678;
}
}
else {
struct cStruct* s =  searchStruct(v->type,elems);
if ((((((s!=null)&&(RCPavailable()==true))&&(RCPselfRef(v)==false))&&(s->isBinding==false))&&(strCount(v->name,"*")==0))) {
char * ____BAH_COMPILER_VAR_679 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("RCP_decrCounter(");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(".__RCP_counter); ");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen(" = ");
long int strLen_5 = strlen(code);
;                            
                        ____BAH_COMPILER_VAR_679 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_679+currStrOff, "RCP_decrCounter(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_679+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_679+currStrOff, ".__RCP_counter); ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_679+currStrOff, v->name, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_679+currStrOff, " = ", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_679+currStrOff, code, strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_679;
}
else {
char * ____BAH_COMPILER_VAR_680 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen(" = ");
long int strLen_2 = strlen(code);
;                            
                        ____BAH_COMPILER_VAR_680 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_680+currStrOff, v->name, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_680+currStrOff, " = ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_680+currStrOff, code, strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_680;
}
}
}
else {
strTrim(&code);
if ((strHasPrefix(code,"{")==false)) {
char * ____BAH_COMPILER_VAR_681 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen(" = ");
long int strLen_2 = strlen(code);
;                            
                        ____BAH_COMPILER_VAR_681 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_681+currStrOff, v->name, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_681+currStrOff, " = ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_681+currStrOff, code, strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_681;
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
i =  i + 1;
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
i =  i - 1;
};
long int tamm =  n.length - i;
n.trimRight((struct string*)&n,tamm + 6);
char * nstr =  n.str((struct string*)&n);
struct string elemType =  getCType(v->type,elems);
char * elemTypeStr =  elemType.str((struct string*)&elemType);
char * ____BAH_COMPILER_VAR_682 =null;
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
                        ____BAH_COMPILER_VAR_682 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14 + strLen_15 + strLen_16);
                        
                        strncpy(____BAH_COMPILER_VAR_682+currStrOff, "\n{\nlong nLength = ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_682+currStrOff, nLengthStr, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_682+currStrOff, ";\nif (", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_682+currStrOff, nstr, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_682+currStrOff, "->length < nLength+1) {\nif ((nLength+1) % 50 == 0 || nLength == 0) {\nvoid * newPtr = memoryRealloc(", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_682+currStrOff, nstr, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_682+currStrOff, "->data, (nLength+50)*sizeof(", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_682+currStrOff, elemTypeStr, strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_682+currStrOff, "));\n", strLen_8);
                        currStrOff += strLen_8;
                        
                        strncpy(____BAH_COMPILER_VAR_682+currStrOff, nstr, strLen_9);
                        currStrOff += strLen_9;
                        
                        strncpy(____BAH_COMPILER_VAR_682+currStrOff, "->data = newPtr;\n}\n", strLen_10);
                        currStrOff += strLen_10;
                        
                        strncpy(____BAH_COMPILER_VAR_682+currStrOff, code, strLen_11);
                        currStrOff += strLen_11;
                        
                        strncpy(____BAH_COMPILER_VAR_682+currStrOff, ";\n", strLen_12);
                        currStrOff += strLen_12;
                        
                        strncpy(____BAH_COMPILER_VAR_682+currStrOff, nstr, strLen_13);
                        currStrOff += strLen_13;
                        
                        strncpy(____BAH_COMPILER_VAR_682+currStrOff, "->length = nLength+1;\n} else {\n", strLen_14);
                        currStrOff += strLen_14;
                        
                        strncpy(____BAH_COMPILER_VAR_682+currStrOff, code, strLen_15);
                        currStrOff += strLen_15;
                        
                        strncpy(____BAH_COMPILER_VAR_682+currStrOff, ";\n}\n}", strLen_16);
                        currStrOff += strLen_16;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_682;
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
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1983): tmpfn->args[%d] with length %d\n", j, tmpfn->args->length);
                    exit(1);
                };
                struct variable* arg =  tmpfn->args->data[j];
struct string ct =  getCType(arg->type,elems);
char * ____BAH_COMPILER_VAR_683 =ct.str((struct string*)&ct);char * ____BAH_COMPILER_VAR_684 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_683);
;                            
                        ____BAH_COMPILER_VAR_684 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_684+currStrOff, tmpfnArgsCType, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_684+currStrOff, ____BAH_COMPILER_VAR_683, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    tmpfnArgsCType =  ____BAH_COMPILER_VAR_684;
j =  j + 1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_685 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(",");
;                            
                        ____BAH_COMPILER_VAR_685 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_685+currStrOff, tmpfnArgsCType, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_685+currStrOff, ",", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    tmpfnArgsCType =  ____BAH_COMPILER_VAR_685;
}
};
char * ____BAH_COMPILER_VAR_686 =tmpfnRetCType.str((struct string*)&tmpfnRetCType);char * ____BAH_COMPILER_VAR_687 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(____BAH_COMPILER_VAR_686);
long int strLen_1 = strlen(" (*");
long int strLen_2 = strlen(v->name);
long int strLen_3 = strlen(")(");
long int strLen_4 = strlen(tmpfnArgsCType);
long int strLen_5 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_687 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_687+currStrOff, ____BAH_COMPILER_VAR_686, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_687+currStrOff, " (*", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_687+currStrOff, v->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_687+currStrOff, ")(", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_687+currStrOff, tmpfnArgsCType, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_687+currStrOff, ")", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    vct =  ____BAH_COMPILER_VAR_687;
}
else {
vct =  setCType(v,elems);
}
if ((strlen(code)>0)) {
if ((((isRCPpointerType(v->type)&&(RCPavailable()==true))&&(toVar==true))&&(isPointedVar==false))) {
struct string cType =  getCType(v->type,elems);
if (isGlobal()) {
char * ____BAH_COMPILER_VAR_688 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_689 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen(" = *(");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_688);
long int strLen_3 = strlen("*)RCP_incrIL(&");
long int strLen_4 = strlen(code);
long int strLen_5 = strlen(");\n");
;                            
                        ____BAH_COMPILER_VAR_689 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_689+currStrOff, v->name, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_689+currStrOff, " = *(", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_689+currStrOff, ____BAH_COMPILER_VAR_688, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_689+currStrOff, "*)RCP_incrIL(&", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_689+currStrOff, code, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_689+currStrOff, ");\n", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    INIT =  INIT->add(INIT, rope(____BAH_COMPILER_VAR_689));
}
else {
char * ____BAH_COMPILER_VAR_690 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_691 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(vct);
long int strLen_1 = strlen(" = *(");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_690);
long int strLen_3 = strlen("*)RCP_incrIL(&");
long int strLen_4 = strlen(code);
long int strLen_5 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_691 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_691+currStrOff, vct, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_691+currStrOff, " = *(", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_691+currStrOff, ____BAH_COMPILER_VAR_690, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_691+currStrOff, "*)RCP_incrIL(&", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_691+currStrOff, code, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_691+currStrOff, ")", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_691;
}
}
else {
if (isGlobal()) {
char * ____BAH_COMPILER_VAR_692 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen(" = ");
long int strLen_2 = strlen(code);
long int strLen_3 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_692 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                        
                        strncpy(____BAH_COMPILER_VAR_692+currStrOff, v->name, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_692+currStrOff, " = ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_692+currStrOff, code, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_692+currStrOff, ";\n", strLen_3);
                        currStrOff += strLen_3;
                        
                    }
                    INIT =  INIT->add(INIT, rope(____BAH_COMPILER_VAR_692));
}
else {
char * ____BAH_COMPILER_VAR_693 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(vct);
long int strLen_1 = strlen(" = ");
long int strLen_2 = strlen(code);
;                            
                        ____BAH_COMPILER_VAR_693 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_693+currStrOff, vct, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_693+currStrOff, " = ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_693+currStrOff, code, strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_693;
}
}
}
else {
if (isRCPpointerType(v->type)) {
char * ____BAH_COMPILER_VAR_694 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(vct);
long int strLen_1 = strlen("= null");
;                            
                        ____BAH_COMPILER_VAR_694 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_694+currStrOff, vct, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_694+currStrOff, "= null", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_694;
}
else {
code =  vct;
}
}
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
struct variable* ____BAH_COMPILER_VAR_695 = v;
char ** ____BAH_COMPILER_VAR_697 = (char **)((char*)(____BAH_COMPILER_VAR_695) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_698 = __reflect(____BAH_COMPILER_VAR_697, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_699 = (char **)((char*)(____BAH_COMPILER_VAR_695) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_700 = __reflect(____BAH_COMPILER_VAR_699, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
int* ____BAH_COMPILER_VAR_701 = (int*)((char*)(____BAH_COMPILER_VAR_695) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_702 = __reflect(____BAH_COMPILER_VAR_701, sizeof(int), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_703 = (char **)((char*)(____BAH_COMPILER_VAR_695) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_704 = __reflect(____BAH_COMPILER_VAR_703, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
int* ____BAH_COMPILER_VAR_705 = (int*)((char*)(____BAH_COMPILER_VAR_695) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_706 = __reflect(____BAH_COMPILER_VAR_705, sizeof(int), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_707 = (char **)((char*)(____BAH_COMPILER_VAR_695) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_708 = __reflect(____BAH_COMPILER_VAR_707, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
int* ____BAH_COMPILER_VAR_709 = (int*)((char*)(____BAH_COMPILER_VAR_695) + offsetof(struct variable, outterScope));
struct reflectElement ____BAH_COMPILER_VAR_710 = __reflect(____BAH_COMPILER_VAR_709, sizeof(int), "bool", "outterScope", 0, 0, 0, 0, offsetof(struct variable, outterScope));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_696 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_696->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_696->length = 7;
        ____BAH_COMPILER_VAR_696->data = memoryAlloc(____BAH_COMPILER_VAR_696->length * ____BAH_COMPILER_VAR_696->elemSize);
        ____BAH_COMPILER_VAR_696->data[0] = ____BAH_COMPILER_VAR_698;
____BAH_COMPILER_VAR_696->data[1] = ____BAH_COMPILER_VAR_700;
____BAH_COMPILER_VAR_696->data[2] = ____BAH_COMPILER_VAR_702;
____BAH_COMPILER_VAR_696->data[3] = ____BAH_COMPILER_VAR_704;
____BAH_COMPILER_VAR_696->data[4] = ____BAH_COMPILER_VAR_706;
____BAH_COMPILER_VAR_696->data[5] = ____BAH_COMPILER_VAR_708;
____BAH_COMPILER_VAR_696->data[6] = ____BAH_COMPILER_VAR_710;
struct reflectElement ____BAH_COMPILER_VAR_711 = __reflect(____BAH_COMPILER_VAR_695, sizeof(struct variable), "variable*", "v", 0, 0, 1, ____BAH_COMPILER_VAR_696, 0);
debugPrint("var_declaration",ft.line,____BAH_COMPILER_VAR_711);
if (isGlobal()) {
char * ____BAH_COMPILER_VAR_712 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(vct);
long int strLen_1 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_712 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_712+currStrOff, vct, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_712+currStrOff, ";\n", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_712));
}
}
if (isGlobal()) {
INIT =  INIT->add(INIT, rope(NEXT_LINE));
NEXT_LINE =  "";
}
else {
char * ____BAH_COMPILER_VAR_713 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(code);
long int strLen_1 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_713 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_713+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_713+currStrOff, ";\n", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_713));
}
};
char * getCfunctionType(struct string cfrt,char * elemName,struct Elems* elems){
struct func* tmpfn =  parseFnType(cfrt);
struct string tmpfnRetCType =  getCType(tmpfn->returns->type,elems);
char * tmpfnArgsCType =  "";
long int j =  0;
while ((j<len(tmpfn->args))) {

                if (tmpfn->args->length <= j) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2045): tmpfn->args[%d] with length %d\n", j, tmpfn->args->length);
                    exit(1);
                };
                struct variable* arg =  tmpfn->args->data[j];
struct string ct =  getCType(arg->type,elems);
char * ____BAH_COMPILER_VAR_714 =ct.str((struct string*)&ct);char * ____BAH_COMPILER_VAR_715 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_714);
;                            
                        ____BAH_COMPILER_VAR_715 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_715+currStrOff, tmpfnArgsCType, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_715+currStrOff, ____BAH_COMPILER_VAR_714, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    tmpfnArgsCType =  ____BAH_COMPILER_VAR_715;
j =  j + 1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_716 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(",");
;                            
                        ____BAH_COMPILER_VAR_716 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_716+currStrOff, tmpfnArgsCType, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_716+currStrOff, ",", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    tmpfnArgsCType =  ____BAH_COMPILER_VAR_716;
}
};
char * ____BAH_COMPILER_VAR_717 =tmpfnRetCType.str((struct string*)&tmpfnRetCType);char * ____BAH_COMPILER_VAR_718 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(____BAH_COMPILER_VAR_717);
long int strLen_1 = strlen(" (*");
long int strLen_2 = strlen(elemName);
long int strLen_3 = strlen(")(");
long int strLen_4 = strlen(tmpfnArgsCType);
long int strLen_5 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_718 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_718+currStrOff, ____BAH_COMPILER_VAR_717, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_718+currStrOff, " (*", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_718+currStrOff, elemName, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_718+currStrOff, ")(", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_718+currStrOff, tmpfnArgsCType, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_718+currStrOff, ")", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    char * ____BAH_COMPILER_VAR_719 = ____BAH_COMPILER_VAR_718;
return ____BAH_COMPILER_VAR_719;
};
char * parseFnHeader(char * prev,__BAH_ARR_TYPE_Tok l,long int* i,struct func* fn,struct Elems* elems){
long int j =  *i;

                if (l->length <= j) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2061): l[%d] with length %d\n", j, l->length);
                    exit(1);
                };
                struct Tok ft =  l->data[j];
char * tpdf =  "";
if ((ft.type!=TOKEN_TYPE_VAR)) {
throwErr(&ft,"Cannot use {TOKEN} as function name.");
}
char * ____BAH_COMPILER_VAR_720 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(prev);
long int strLen_1 = strlen(ft.cont);
;                            
                        ____BAH_COMPILER_VAR_720 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_720+currStrOff, prev, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_720+currStrOff, ft.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    fn->name =  ____BAH_COMPILER_VAR_720;
array(struct variable*)* arguments = memoryAlloc(sizeof(array(struct variable*)));

arguments->length = 0;
arguments->elemSize = sizeof(struct variable*);
char * ____BAH_COMPILER_VAR_721 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(fn->name);
long int strLen_1 = strlen("(");
;                            
                        ____BAH_COMPILER_VAR_721 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_721+currStrOff, fn->name, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_721+currStrOff, "(", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    char * code =  ____BAH_COMPILER_VAR_721;
j =  j + 2;

                if (l->length <= j) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2075): l[%d] with length %d\n", j, l->length);
                    exit(1);
                };
                struct Tok t =  l->data[j];
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2076 t.cont ")==1&&strcmp(t.cont, ")") != 0)) {
while ((j<len(l))) {

                if (l->length <= j) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2079): l[%d] with length %d\n", j, l->length);
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
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2089): l[%d] with length %d\n", j, l->length);
                    exit(1);
                };
                t =  l->data[j];
char * argType =  t.cont;
j =  j + 1;
int isComa =  false;
long int nbPars =  1;
while ((j<len(l))) {

                if (l->length <= j) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2096): l[%d] with length %d\n", j, l->length);
                    exit(1);
                };
                t =  l->data[j];
isComa =  false;
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2098 t.cont ")==1&&strcmp(t.cont, ",") != 0)) {
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2099 t.cont ")==1&&strcmp(t.cont, "(") == 0)) {
nbPars =  nbPars + 1;
}
else if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2101 t.cont ")==1&&strcmp(t.cont, ")") == 0)) {
nbPars =  nbPars - 1;
}
if (((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2104 t.cont ")==1&&strcmp(t.cont, ")") == 0)&&(nbPars==0))) {
break;
}
else {
char * ____BAH_COMPILER_VAR_722 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(argType);
long int strLen_1 = strlen(t.cont);
;                            
                        ____BAH_COMPILER_VAR_722 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_722+currStrOff, argType, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_722+currStrOff, t.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    argType =  ____BAH_COMPILER_VAR_722;
}
}
else {
isComa =  true;
break;
}
j =  j + 1;
};
struct variable* ____BAH_COMPILER_VAR_723 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_723->name = "";
____BAH_COMPILER_VAR_723->type = "";
____BAH_COMPILER_VAR_723->isConst = false;
____BAH_COMPILER_VAR_723->constVal = "";
____BAH_COMPILER_VAR_723->isArray = false;
____BAH_COMPILER_VAR_723->from = "";
____BAH_COMPILER_VAR_723->outterScope = false;
struct variable* argument =  ____BAH_COMPILER_VAR_723;
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
char * ____BAH_COMPILER_VAR_724 =cfrt.str((struct string*)&cfrt);char * ____BAH_COMPILER_VAR_725 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("__BAH_ARR_TYPE_");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_724);
;                            
                        ____BAH_COMPILER_VAR_725 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_725+currStrOff, "__BAH_ARR_TYPE_", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_725+currStrOff, ____BAH_COMPILER_VAR_724, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    newArgType =  ____BAH_COMPILER_VAR_725;
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
char * ____BAH_COMPILER_VAR_726 =argCType.str((struct string*)&argCType);char * ____BAH_COMPILER_VAR_727 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(tpdf);
long int strLen_1 = strlen("typedef ");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_726);
long int strLen_3 = strlen(" ");
long int strLen_4 = strlen(newArgType);
long int strLen_5 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_727 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_727+currStrOff, tpdf, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_727+currStrOff, "typedef ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_727+currStrOff, ____BAH_COMPILER_VAR_726, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_727+currStrOff, " ", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_727+currStrOff, newArgType, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_727+currStrOff, ";\n", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    tpdf =  ____BAH_COMPILER_VAR_727;
}
}
if ((cfrt.hasPrefix((struct string*)&cfrt,"function(")==1)) {
char * ____BAH_COMPILER_VAR_728 =getCfunctionType(cfrt,argName,elems);char * ____BAH_COMPILER_VAR_729 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(code);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_728);
;                            
                        ____BAH_COMPILER_VAR_729 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_729+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_729+currStrOff, ____BAH_COMPILER_VAR_728, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_729;
}
else {
char * ____BAH_COMPILER_VAR_730 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(code);
long int strLen_1 = strlen(newArgType);
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(argName);
;                            
                        ____BAH_COMPILER_VAR_730 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                        
                        strncpy(____BAH_COMPILER_VAR_730+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_730+currStrOff, newArgType, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_730+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_730+currStrOff, argName, strLen_3);
                        currStrOff += strLen_3;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_730;
}
if ((isComa==true)) {
char * ____BAH_COMPILER_VAR_731 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(code);
long int strLen_1 = strlen(",");
;                            
                        ____BAH_COMPILER_VAR_731 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_731+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_731+currStrOff, ",", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_731;
}
else {
char * ____BAH_COMPILER_VAR_732 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(code);
long int strLen_1 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_732 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_732+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_732+currStrOff, ")", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_732;
break;
}
j =  j + 1;
};
}
else {
char * ____BAH_COMPILER_VAR_733 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(code);
long int strLen_1 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_733 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_733+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_733+currStrOff, ")", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_733;
}
j =  j + 1;
struct variable* ____BAH_COMPILER_VAR_734 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_734->name = "";
____BAH_COMPILER_VAR_734->type = "";
____BAH_COMPILER_VAR_734->isConst = false;
____BAH_COMPILER_VAR_734->constVal = "";
____BAH_COMPILER_VAR_734->isArray = false;
____BAH_COMPILER_VAR_734->from = "";
____BAH_COMPILER_VAR_734->outterScope = false;
struct variable* returns =  ____BAH_COMPILER_VAR_734;
returns->type =  "";
while ((j<len(l))) {

                if (l->length <= j) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2161): l[%d] with length %d\n", j, l->length);
                    exit(1);
                };
                t =  l->data[j];
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2162 t.cont ")==1&&strcmp(t.cont, "{") == 0)) {
break;
}
char * ____BAH_COMPILER_VAR_735 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(returns->type);
long int strLen_1 = strlen(t.cont);
;                            
                        ____BAH_COMPILER_VAR_735 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_735+currStrOff, returns->type, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_735+currStrOff, t.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    returns->type =  ____BAH_COMPILER_VAR_735;
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
char * ____BAH_COMPILER_VAR_736 =cfrt.str((struct string*)&cfrt);char * ____BAH_COMPILER_VAR_737 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("__BAH_ARR_TYPE_");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_736);
;                            
                        ____BAH_COMPILER_VAR_737 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_737+currStrOff, "__BAH_ARR_TYPE_", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_737+currStrOff, ____BAH_COMPILER_VAR_736, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    newFnRetType =  ____BAH_COMPILER_VAR_737;
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
char * ____BAH_COMPILER_VAR_738 =fnRetType.str((struct string*)&fnRetType);char * ____BAH_COMPILER_VAR_739 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(tpdf);
long int strLen_1 = strlen("typedef ");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_738);
long int strLen_3 = strlen(" ");
long int strLen_4 = strlen(newFnRetType);
long int strLen_5 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_739 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_739+currStrOff, tpdf, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_739+currStrOff, "typedef ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_739+currStrOff, ____BAH_COMPILER_VAR_738, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_739+currStrOff, " ", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_739+currStrOff, newFnRetType, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_739+currStrOff, ";\n", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    tpdf =  ____BAH_COMPILER_VAR_739;
}
}
char * ____BAH_COMPILER_VAR_740 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(tpdf);
long int strLen_1 = strlen(newFnRetType);
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(code);
;                            
                        ____BAH_COMPILER_VAR_740 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                        
                        strncpy(____BAH_COMPILER_VAR_740+currStrOff, tpdf, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_740+currStrOff, newFnRetType, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_740+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_740+currStrOff, code, strLen_3);
                        currStrOff += strLen_3;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_740;
char * ____BAH_COMPILER_VAR_741 = code;
return ____BAH_COMPILER_VAR_741;
};
void parseStruct(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
struct cStruct* ____BAH_COMPILER_VAR_742 = memoryAlloc(sizeof(struct cStruct));
____BAH_COMPILER_VAR_742->name = "";
____BAH_COMPILER_VAR_742->members = memoryAlloc(sizeof(array(struct structMemb*)));
            ____BAH_COMPILER_VAR_742->members->length = 0;
            ____BAH_COMPILER_VAR_742->members->elemSize = sizeof(struct structMemb*);
            ____BAH_COMPILER_VAR_742->methods = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_742->methods->length = 0;
            ____BAH_COMPILER_VAR_742->methods->elemSize = sizeof(struct func*);
            ____BAH_COMPILER_VAR_742->postCode = "";
____BAH_COMPILER_VAR_742->extendedFrom = "";
____BAH_COMPILER_VAR_742->isBinding = false;
____BAH_COMPILER_VAR_742->hasRCPmemb = false;
struct cStruct* s =  ____BAH_COMPILER_VAR_742;
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
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2211): l[%d] with length %d\n", 1, l->length);
                    exit(1);
                };
                struct Tok nameToken =  l->data[1];
long int i =  2;
int doesOutput =  true;
if ((__checkString(nameToken.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2214 nameToken.cont ")==1&&strcmp(nameToken.cont, "!") == 0)) {

                if (l->length <= 2) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2215): l[%d] with length %d\n", 2, l->length);
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
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2231): l[%d] with length %d\n", i, l->length);
                    exit(1);
                };
                struct Tok st =  l->data[i];
if ((st.type==TOKEN_TYPE_KEYWORD)) {
if ((__checkString(st.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2233 st.cont ")==1&&strcmp(st.cont, "extend") == 0)) {
i =  i + 1;

                if (l->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2235): l[%d] with length %d\n", i, l->length);
                    exit(1);
                };
                struct Tok extdSNameTk =  l->data[i];
i =  i + 1;
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
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2247): extdsmbs[%d] with length %d\n", j, extdsmbs->length);
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
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2255): tmpfn->args[%d] with length %d\n", j, tmpfn->args->length);
                    exit(1);
                };
                struct variable* arg =  tmpfn->args->data[j];
struct string ct =  getCType(arg->type,elems);
char * ____BAH_COMPILER_VAR_743 =ct.str((struct string*)&ct);char * ____BAH_COMPILER_VAR_744 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_743);
;                            
                        ____BAH_COMPILER_VAR_744 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_744+currStrOff, tmpfnArgsCType, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_744+currStrOff, ____BAH_COMPILER_VAR_743, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    tmpfnArgsCType =  ____BAH_COMPILER_VAR_744;
j =  j + 1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_745 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(",");
;                            
                        ____BAH_COMPILER_VAR_745 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_745+currStrOff, tmpfnArgsCType, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_745+currStrOff, ",", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    tmpfnArgsCType =  ____BAH_COMPILER_VAR_745;
}
};
char * ____BAH_COMPILER_VAR_746 =tmpfnRetCType.str((struct string*)&tmpfnRetCType);char * ____BAH_COMPILER_VAR_747 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(____BAH_COMPILER_VAR_746);
long int strLen_1 = strlen(" (*");
long int strLen_2 = strlen(em->name);
long int strLen_3 = strlen(")(");
long int strLen_4 = strlen(tmpfnArgsCType);
long int strLen_5 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_747 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_747+currStrOff, ____BAH_COMPILER_VAR_746, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_747+currStrOff, " (*", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_747+currStrOff, em->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_747+currStrOff, ")(", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_747+currStrOff, tmpfnArgsCType, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_747+currStrOff, ")", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    membDeclStr =  ____BAH_COMPILER_VAR_747;
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
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2278): extdS->methods[%d] with length %d\n", k, extdS->methods->length);
                    exit(1);
                };
                struct func* emt =  extdS->methods->data[k];
struct string mthdDecl =  getCType(emt->returns->type,elems);
char * ____BAH_COMPILER_VAR_748 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("(*");
long int strLen_1 = strlen(emt->name);
long int strLen_2 = strlen(")(");
;                            
                        ____BAH_COMPILER_VAR_748 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_748+currStrOff, "(*", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_748+currStrOff, emt->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_748+currStrOff, ")(", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    mthdDecl.append((struct string*)&mthdDecl,____BAH_COMPILER_VAR_748);
j =  0;
while ((j<len(emt->args))) {

                if (emt->args->length <= j) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2283): emt->args[%d] with length %d\n", j, emt->args->length);
                    exit(1);
                };
                struct variable* a =  emt->args->data[j];
struct string tp =  getCType(a->type,elems);
char * ____BAH_COMPILER_VAR_749 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(" ");
long int strLen_1 = strlen(a->name);
;                            
                        ____BAH_COMPILER_VAR_749 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_749+currStrOff, " ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_749+currStrOff, a->name, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    tp.append((struct string*)&tp,____BAH_COMPILER_VAR_749);
long int max =  len(emt->args) - 1;
if ((j!=max)) {
tp.append((struct string*)&tp,",");
}
char * ____BAH_COMPILER_VAR_750 =tp.str((struct string*)&tp);mthdDecl.append((struct string*)&mthdDecl,____BAH_COMPILER_VAR_750);
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
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2302): l[%d] with length %d\n", i, l->length);
                    exit(1);
                };
                struct Tok braceTk =  l->data[i];
i =  i + 1;
if ((__checkString(braceTk.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2304 braceTk.cont ")==1&&strcmp(braceTk.cont, "{") != 0)) {
throwErr(&braceTk,"Cannot use {TOKEN} in struct declaration.");
}
struct rope* OOUT =  OUTPUT;
char * nextLine =  "";
while ((i<len(l))) {

                if (l->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2310): l[%d] with length %d\n", i, l->length);
                    exit(1);
                };
                struct Tok t =  l->data[i];
long int max =  i + 2;
if ((max>=len(l))) {
if (((t.type==TOKEN_TYPE_ENCL)&&(__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2313 t.cont ")==1&&strcmp(t.cont, "}") == 0))) {
break;
}
throwErr(&l->data[len(l)-1],"Not enough argument in member declaration, ending by {TOKEN}.");
}
struct structMemb* ____BAH_COMPILER_VAR_751 = memoryAlloc(sizeof(struct structMemb));
____BAH_COMPILER_VAR_751->name = "";
____BAH_COMPILER_VAR_751->type = "";
____BAH_COMPILER_VAR_751->isConst = false;
____BAH_COMPILER_VAR_751->constVal = "";
____BAH_COMPILER_VAR_751->isArray = false;
____BAH_COMPILER_VAR_751->from = "";
____BAH_COMPILER_VAR_751->outterScope = false;
____BAH_COMPILER_VAR_751->def = "";
____BAH_COMPILER_VAR_751->isFn = false;
struct structMemb* memb =  ____BAH_COMPILER_VAR_751;
if ((t.type!=TOKEN_TYPE_VAR)) {
throwErr(&t,"Cannot use {TOKEN} as member name.");
}
memb->name =  t.cont;
long int ii =  0;
while ((ii<len(members))) {

                if (members->length <= ii) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2324): members[%d] with length %d\n", ii, members->length);
                    exit(1);
                };
                struct structMemb* m =  members->data[ii];
if ((__checkString(m->name, "/home/alois/Documents/bah-bah/src/parser.bah:2325 m->name ")==1&&__checkString(memb->name, "/home/alois/Documents/bah-bah/src/parser.bah:2325 memb->name")==1&&strcmp(m->name, memb->name) == 0)) {
throwErr(&t,"Member {TOKEN} has already been declared.");
}
ii =  ii + 1;
};
i =  i + 1;

                if (l->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2331): l[%d] with length %d\n", i, l->length);
                    exit(1);
                };
                t =  l->data[i];
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2332 t.cont ")==1&&strcmp(t.cont, ":") != 0)) {
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2333 t.cont ")==1&&strcmp(t.cont, "(") != 0)) {
throwErr(&t,"Member name should be followed by ':' not {TOKEN}.");
}
else {
char * ____BAH_COMPILER_VAR_752 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s->name);
long int strLen_1 = strlen("__");
;                            
                        ____BAH_COMPILER_VAR_752 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_752+currStrOff, s->name, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_752+currStrOff, "__", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    char * fnPrefix =  ____BAH_COMPILER_VAR_752;
struct func* ____BAH_COMPILER_VAR_753 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_753->name = "";
____BAH_COMPILER_VAR_753->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_753->args->length = 0;
            ____BAH_COMPILER_VAR_753->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_753->returns= null;
____BAH_COMPILER_VAR_753->isBinding = false;
____BAH_COMPILER_VAR_753->from = "";
____BAH_COMPILER_VAR_753->file = "";
____BAH_COMPILER_VAR_753->line = 1;
struct func* fn =  ____BAH_COMPILER_VAR_753;
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
long int j =  i-1;
while ((j<len(l))) {

                if (l->length <= j) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2340): l[%d] with length %d\n", j, l->length);
                    exit(1);
                };
                t =  l->data[j];
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2341 t.cont ")==1&&strcmp(t.cont, "{") == 0)) {
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
char * ____BAH_COMPILER_VAR_754 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s->name);
long int strLen_1 = strlen("*");
;                            
                        ____BAH_COMPILER_VAR_754 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_754+currStrOff, s->name, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_754+currStrOff, "*", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    t.cont =  ____BAH_COMPILER_VAR_754;
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
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2356): l[%d] with length %d\n", j + 1, l->length);
                    exit(1);
                };
                struct Tok nt =  l->data[j + 1];
if ((__checkString(nt.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2357 nt.cont ")==1&&strcmp(nt.cont, ")") != 0)) {
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
i =  i - 1;
long int nli =  0;
char * ____BAH_COMPILER_VAR_755 =parseFnHeader(fnPrefix,nl,&nli,fn,elems);struct rope* code =  rope(____BAH_COMPILER_VAR_755);
i =  i + nli;
i =  i - 2;
struct variable* returns =  fn->returns;
array(struct variable*)* arguments =  fn->args;
fn->from =  s->name;
code =  code->add(code, rope("{\n"));
struct Elems* fnElems =  dupElems(elems);
j =  0;
while ((j<len(arguments))) {

                if (arguments->length <= j) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2381): arguments[%d] with length %d\n", j, arguments->length);
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
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2392): l[%d] with length %d\n", i, l->length);
                    exit(1);
                };
                t =  l->data[i];
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2393 t.cont ")==1&&strcmp(t.cont, "{") == 0)) {
i =  i + 1;
}
while ((i<len(l))) {

                if (l->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2397): l[%d] with length %d\n", i, l->length);
                    exit(1);
                };
                t =  l->data[i];
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2398 t.cont ")==1&&strcmp(t.cont, "{") == 0)) {
nbBraces =  nbBraces + 1;
}
else if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2400 t.cont ")==1&&strcmp(t.cont, "}") == 0)) {
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
i =  i + 1;
};
struct func* ____BAH_COMPILER_VAR_756 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_756->name = "";
____BAH_COMPILER_VAR_756->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_756->args->length = 0;
            ____BAH_COMPILER_VAR_756->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_756->returns= null;
____BAH_COMPILER_VAR_756->isBinding = false;
____BAH_COMPILER_VAR_756->from = "";
____BAH_COMPILER_VAR_756->file = "";
____BAH_COMPILER_VAR_756->line = 1;
struct func* mfn =  ____BAH_COMPILER_VAR_756;
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
char * ____BAH_COMPILER_VAR_757 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Function '");
long int strLen_1 = strlen(fn->name);
long int strLen_2 = strlen("' is not returned.");
;                            
                        ____BAH_COMPILER_VAR_757 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_757+currStrOff, "Function '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_757+currStrOff, fn->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_757+currStrOff, "' is not returned.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    throwErr(&l->data[len(l)-1],____BAH_COMPILER_VAR_757);
}
endRCPscope(fnElems,null);
}
code =  code->add(code, OUTPUT)->add(code->add(code, OUTPUT), rope("};\n"));
}
if ((doesOutput==true)) {
char * ____BAH_COMPILER_VAR_758 =code->toStr((struct rope*)code);char * ____BAH_COMPILER_VAR_759 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(nextLine);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_758);
;                            
                        ____BAH_COMPILER_VAR_759 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_759+currStrOff, nextLine, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_759+currStrOff, ____BAH_COMPILER_VAR_758, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    nextLine =  ____BAH_COMPILER_VAR_759;
}
struct string mthdDecl =  getCType(fn->returns->type,elems);
char * ____BAH_COMPILER_VAR_760 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("(*");
long int strLen_1 = strlen(mfn->name);
long int strLen_2 = strlen(")(");
;                            
                        ____BAH_COMPILER_VAR_760 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_760+currStrOff, "(*", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_760+currStrOff, mfn->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_760+currStrOff, ")(", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    mthdDecl.append((struct string*)&mthdDecl,____BAH_COMPILER_VAR_760);
j =  0;
while ((j<len(arguments))) {

                if (arguments->length <= j) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2443): arguments[%d] with length %d\n", j, arguments->length);
                    exit(1);
                };
                struct variable* a =  arguments->data[j];
struct string tp =  getCType(a->type,elems);
char * ____BAH_COMPILER_VAR_761 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(" ");
long int strLen_1 = strlen(a->name);
;                            
                        ____BAH_COMPILER_VAR_761 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_761+currStrOff, " ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_761+currStrOff, a->name, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    tp.append((struct string*)&tp,____BAH_COMPILER_VAR_761);
max =  len(arguments) - 1;
if ((j!=max)) {
tp.append((struct string*)&tp,",");
}
char * ____BAH_COMPILER_VAR_762 =tp.str((struct string*)&tp);mthdDecl.append((struct string*)&mthdDecl,____BAH_COMPILER_VAR_762);
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
i =  i + 1;
continue;
}
}
i =  i + 1;
char * mbmType =  "";
long int currentLine =  t.line;
while ((i<len(l))) {

                if (l->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2465): l[%d] with length %d\n", i, l->length);
                    exit(1);
                };
                t =  l->data[i];
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2466 t.cont ")==1&&strcmp(t.cont, "=") == 0)) {
i =  i - 1;
break;
}
if ((t.line!=currentLine)) {
i =  i - 1;
break;
}
char * ____BAH_COMPILER_VAR_763 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(mbmType);
long int strLen_1 = strlen(t.cont);
;                            
                        ____BAH_COMPILER_VAR_763 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_763+currStrOff, mbmType, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_763+currStrOff, t.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    mbmType =  ____BAH_COMPILER_VAR_763;
i =  i + 1;
};
memb->type =  mbmType;
i =  i + 1;

                if (l->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2480): l[%d] with length %d\n", i, l->length);
                    exit(1);
                };
                t =  l->data[i];
if ((i<len(l))) {
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2482 t.cont ")==1&&strcmp(t.cont, "=") == 0)) {
i =  i + 1;

                if (l->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2484): l[%d] with length %d\n", i, l->length);
                    exit(1);
                };
                t =  l->data[i];
if ((t.isValue==false)) {
throwErr(&t,"Cannot use {TOKEN} as default value for member.");
}
char * tt =  getTypeFromToken(&t,true,elems);
if ((compTypes(tt,memb->type)==false)) {
char * ____BAH_COMPILER_VAR_764 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(tt);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(memb->type);
long int strLen_4 = strlen(" for member.");
;                            
                        ____BAH_COMPILER_VAR_764 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_764+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_764+currStrOff, tt, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_764+currStrOff, ") as ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_764+currStrOff, memb->type, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_764+currStrOff, " for member.", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    throwErr(&t,____BAH_COMPILER_VAR_764);
}
memb->def =  t.cont;
}
else {
i =  i - 1;
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
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2509): tmpfn->args[%d] with length %d\n", j, tmpfn->args->length);
                    exit(1);
                };
                struct variable* arg =  tmpfn->args->data[j];
struct string ct =  getCType(arg->type,elems);
char * ____BAH_COMPILER_VAR_765 =ct.str((struct string*)&ct);char * ____BAH_COMPILER_VAR_766 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_765);
;                            
                        ____BAH_COMPILER_VAR_766 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_766+currStrOff, tmpfnArgsCType, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_766+currStrOff, ____BAH_COMPILER_VAR_765, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    tmpfnArgsCType =  ____BAH_COMPILER_VAR_766;
j =  j + 1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_767 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(",");
;                            
                        ____BAH_COMPILER_VAR_767 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_767+currStrOff, tmpfnArgsCType, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_767+currStrOff, ",", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    tmpfnArgsCType =  ____BAH_COMPILER_VAR_767;
}
};
char * ____BAH_COMPILER_VAR_768 =tmpfnRetCType.str((struct string*)&tmpfnRetCType);char * ____BAH_COMPILER_VAR_769 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(____BAH_COMPILER_VAR_768);
long int strLen_1 = strlen(" (*");
long int strLen_2 = strlen(memb->name);
long int strLen_3 = strlen(")(");
long int strLen_4 = strlen(tmpfnArgsCType);
long int strLen_5 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_769 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_769+currStrOff, ____BAH_COMPILER_VAR_768, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_769+currStrOff, " (*", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_769+currStrOff, memb->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_769+currStrOff, ")(", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_769+currStrOff, tmpfnArgsCType, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_769+currStrOff, ")", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    membDeclStr =  ____BAH_COMPILER_VAR_769;
}
else {
struct string membDecl =  getCType(memb->type,elems);
char * ____BAH_COMPILER_VAR_770 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(" ");
long int strLen_1 = strlen(memb->name);
;                            
                        ____BAH_COMPILER_VAR_770 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_770+currStrOff, " ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_770+currStrOff, memb->name, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    membDecl.append((struct string*)&membDecl,____BAH_COMPILER_VAR_770);
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
i =  i + 1;
};
s->members =  members;
if ((doesOutput==true)) {
OUTPUT =  OOUT;
NEXT_LINE =  nextLine;
char * ____BAH_COMPILER_VAR_771 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("struct ");
long int strLen_1 = strlen(s->name);
long int strLen_2 = strlen(" {\n");
;                            
                        ____BAH_COMPILER_VAR_771 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_771+currStrOff, "struct ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_771+currStrOff, s->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_771+currStrOff, " {\n", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    struct rope* code =  rope(____BAH_COMPILER_VAR_771);
i =  0;
while ((i<len(allMembs))) {

                if (allMembs->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2532): allMembs[%d] with length %d\n", i, allMembs->length);
                    exit(1);
                };
                char * m =  allMembs->data[i];
char * ____BAH_COMPILER_VAR_772 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(m);
long int strLen_1 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_772 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_772+currStrOff, m, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_772+currStrOff, ";\n", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    code =  code->add(code, rope(____BAH_COMPILER_VAR_772));
i =  i + 1;
};
if ((RCPavailable()==true)) {
code =  code->add(code, rope("void * __RCP_counter;\n"));
}
code =  code->add(code, rope("};\n"));
OUTPUT =  OUTPUT->add(OUTPUT, code)->add(OUTPUT->add(OUTPUT, code), makeRCPfuncFromStruct(s,elems));
}
if ((debug==true)) {
struct debugStruct* ____BAH_COMPILER_VAR_773 = memoryAlloc(sizeof(struct debugStruct));
____BAH_COMPILER_VAR_773->name= null;
____BAH_COMPILER_VAR_773->membs = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_773->membs->length = 0;
            ____BAH_COMPILER_VAR_773->membs->elemSize = sizeof(struct variable*);
            struct debugStruct* ds =  ____BAH_COMPILER_VAR_773;
ds->name =  s->name;
i =  0;
while ((i<len(s->members))) {

                if (s->members->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2549): s->members[%d] with length %d\n", i, s->members->length);
                    exit(1);
                };
                struct structMemb* m =  s->members->data[i];
struct variable* ____BAH_COMPILER_VAR_774 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_774->name = "";
____BAH_COMPILER_VAR_774->type = "";
____BAH_COMPILER_VAR_774->isConst = false;
____BAH_COMPILER_VAR_774->constVal = "";
____BAH_COMPILER_VAR_774->isArray = false;
____BAH_COMPILER_VAR_774->from = "";
____BAH_COMPILER_VAR_774->outterScope = false;
struct variable* mv =  ____BAH_COMPILER_VAR_774;
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
struct debugStruct* ____BAH_COMPILER_VAR_775 = ds;
char ** ____BAH_COMPILER_VAR_777 = (char **)((char*)(____BAH_COMPILER_VAR_775) + offsetof(struct debugStruct, name));
struct reflectElement ____BAH_COMPILER_VAR_778 = __reflect(____BAH_COMPILER_VAR_777, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct debugStruct, name));
array(struct variable*)** ____BAH_COMPILER_VAR_779 = (array(struct variable*)**)((char*)(____BAH_COMPILER_VAR_775) + offsetof(struct debugStruct, membs));
struct variable** ____BAH_COMPILER_VAR_780 = 0;
char ** ____BAH_COMPILER_VAR_782 = (char **)((char*)(____BAH_COMPILER_VAR_780) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_783 = __reflect(____BAH_COMPILER_VAR_782, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_784 = (char **)((char*)(____BAH_COMPILER_VAR_780) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_785 = __reflect(____BAH_COMPILER_VAR_784, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
int* ____BAH_COMPILER_VAR_786 = (int*)((char*)(____BAH_COMPILER_VAR_780) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_787 = __reflect(____BAH_COMPILER_VAR_786, sizeof(int), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_788 = (char **)((char*)(____BAH_COMPILER_VAR_780) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_789 = __reflect(____BAH_COMPILER_VAR_788, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
int* ____BAH_COMPILER_VAR_790 = (int*)((char*)(____BAH_COMPILER_VAR_780) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_791 = __reflect(____BAH_COMPILER_VAR_790, sizeof(int), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_792 = (char **)((char*)(____BAH_COMPILER_VAR_780) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_793 = __reflect(____BAH_COMPILER_VAR_792, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
int* ____BAH_COMPILER_VAR_794 = (int*)((char*)(____BAH_COMPILER_VAR_780) + offsetof(struct variable, outterScope));
struct reflectElement ____BAH_COMPILER_VAR_795 = __reflect(____BAH_COMPILER_VAR_794, sizeof(int), "bool", "outterScope", 0, 0, 0, 0, offsetof(struct variable, outterScope));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_781 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_781->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_781->length = 7;
        ____BAH_COMPILER_VAR_781->data = memoryAlloc(____BAH_COMPILER_VAR_781->length * ____BAH_COMPILER_VAR_781->elemSize);
        ____BAH_COMPILER_VAR_781->data[0] = ____BAH_COMPILER_VAR_783;
____BAH_COMPILER_VAR_781->data[1] = ____BAH_COMPILER_VAR_785;
____BAH_COMPILER_VAR_781->data[2] = ____BAH_COMPILER_VAR_787;
____BAH_COMPILER_VAR_781->data[3] = ____BAH_COMPILER_VAR_789;
____BAH_COMPILER_VAR_781->data[4] = ____BAH_COMPILER_VAR_791;
____BAH_COMPILER_VAR_781->data[5] = ____BAH_COMPILER_VAR_793;
____BAH_COMPILER_VAR_781->data[6] = ____BAH_COMPILER_VAR_795;
struct reflectElement ____BAH_COMPILER_VAR_796 = __reflect(____BAH_COMPILER_VAR_780, sizeof(struct variable), "variable*", "", 0, 0, 1, ____BAH_COMPILER_VAR_781, 0);

        struct reflectElement ____BAH_COMPILER_VAR_797 = ____BAH_COMPILER_VAR_796;
        struct reflectElement ____BAH_COMPILER_VAR_798 = __reflect(____BAH_COMPILER_VAR_779, sizeof(array(struct variable*)*), "[]variable*", "membs", 1, &____BAH_COMPILER_VAR_797, 0, 0, offsetof(struct debugStruct, membs));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_776 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_776->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_776->length = 2;
        ____BAH_COMPILER_VAR_776->data = memoryAlloc(____BAH_COMPILER_VAR_776->length * ____BAH_COMPILER_VAR_776->elemSize);
        ____BAH_COMPILER_VAR_776->data[0] = ____BAH_COMPILER_VAR_778;
____BAH_COMPILER_VAR_776->data[1] = ____BAH_COMPILER_VAR_798;
struct reflectElement ____BAH_COMPILER_VAR_799 = __reflect(____BAH_COMPILER_VAR_775, sizeof(struct debugStruct), "debugStruct*", "ds", 0, 0, 1, ____BAH_COMPILER_VAR_776, 0);
debugPrint("struct_declare",nameToken.line,____BAH_COMPILER_VAR_799);
}
};
void parseDefine(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
if ((len(l)<3)) {
throwErr(&l->data[len(l)-1],"Invalid usage of define, cannot end on {TOKEN}.");
}

                if (l->length <= 1) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2571): l[%d] with length %d\n", 1, l->length);
                    exit(1);
                };
                struct Tok ft =  l->data[1];

                if (l->length <= 2) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2572): l[%d] with length %d\n", 2, l->length);
                    exit(1);
                };
                struct Tok st =  l->data[2];
long int i =  1;
int doesOutput =  true;
if ((__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2576 ft.cont ")==1&&strcmp(ft.cont, "!") == 0)) {

                if (l->length <= 2) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2577): l[%d] with length %d\n", 2, l->length);
                    exit(1);
                };
                ft =  l->data[2];

                if (l->length <= 3) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2578): l[%d] with length %d\n", 3, l->length);
                    exit(1);
                };
                st =  l->data[3];
i =  2;
doesOutput =  false;
}
if ((__checkString(st.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2583 st.cont ")==1&&strcmp(st.cont, "(") == 0)) {
struct func* ____BAH_COMPILER_VAR_800 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_800->name = "";
____BAH_COMPILER_VAR_800->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_800->args->length = 0;
            ____BAH_COMPILER_VAR_800->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_800->returns= null;
____BAH_COMPILER_VAR_800->isBinding = false;
____BAH_COMPILER_VAR_800->from = "";
____BAH_COMPILER_VAR_800->file = "";
____BAH_COMPILER_VAR_800->line = 1;
struct func* fn =  ____BAH_COMPILER_VAR_800;
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
char * ____BAH_COMPILER_VAR_801 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(code);
long int strLen_1 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_801 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_801+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_801+currStrOff, ";\n", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_801));
}
}
else {
char * tp =  "";
i =  i+1;
for (; (i<len(l)); i =  i+1) {

                if (l->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2597): l[%d] with length %d\n", i, l->length);
                    exit(1);
                };
                struct Tok t =  l->data[i];
char * ____BAH_COMPILER_VAR_802 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(tp);
long int strLen_1 = strlen(t.cont);
;                            
                        ____BAH_COMPILER_VAR_802 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_802+currStrOff, tp, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_802+currStrOff, t.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    tp =  ____BAH_COMPILER_VAR_802;
};
if ((ft.type!=TOKEN_TYPE_VAR)) {
throwErr(&ft,"Cannot use {TOKEN} as new type name.");
}
struct string cTypeNewType =  getCType(tp,elems);
char * cTypeNewTypeStr =  cTypeNewType.str((struct string*)&cTypeNewType);
if ((doesOutput==true)) {
char * ____BAH_COMPILER_VAR_803 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("typedef ");
long int strLen_1 = strlen(cTypeNewTypeStr);
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(ft.cont);
long int strLen_4 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_803 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_803+currStrOff, "typedef ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_803+currStrOff, cTypeNewTypeStr, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_803+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_803+currStrOff, ft.cont, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_803+currStrOff, ";\n", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_803));
}
if ((debug==true)) {
struct debugType* ____BAH_COMPILER_VAR_804 = memoryAlloc(sizeof(struct debugType));
____BAH_COMPILER_VAR_804->name= null;
____BAH_COMPILER_VAR_804->refers= null;
struct debugType* dt =  ____BAH_COMPILER_VAR_804;
dt->name =  ft.cont;
dt->refers =  tp;
struct debugType* ____BAH_COMPILER_VAR_805 = dt;
char ** ____BAH_COMPILER_VAR_807 = (char **)((char*)(____BAH_COMPILER_VAR_805) + offsetof(struct debugType, name));
struct reflectElement ____BAH_COMPILER_VAR_808 = __reflect(____BAH_COMPILER_VAR_807, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct debugType, name));
char ** ____BAH_COMPILER_VAR_809 = (char **)((char*)(____BAH_COMPILER_VAR_805) + offsetof(struct debugType, refers));
struct reflectElement ____BAH_COMPILER_VAR_810 = __reflect(____BAH_COMPILER_VAR_809, sizeof(char *), "cpstring", "refers", 0, 0, 0, 0, offsetof(struct debugType, refers));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_806 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_806->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_806->length = 2;
        ____BAH_COMPILER_VAR_806->data = memoryAlloc(____BAH_COMPILER_VAR_806->length * ____BAH_COMPILER_VAR_806->elemSize);
        ____BAH_COMPILER_VAR_806->data[0] = ____BAH_COMPILER_VAR_808;
____BAH_COMPILER_VAR_806->data[1] = ____BAH_COMPILER_VAR_810;
struct reflectElement ____BAH_COMPILER_VAR_811 = __reflect(____BAH_COMPILER_VAR_805, sizeof(struct debugType), "debugType*", "dt", 0, 0, 1, ____BAH_COMPILER_VAR_806, 0);
debugPrint("type_declare",ft.line,____BAH_COMPILER_VAR_811);
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
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2627): line[%d] with length %d\n", i, line->length);
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
int found =  false;
long int j =  0;
while ((j<len(clibs))) {

                if (clibs->length <= j) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2639): clibs[%d] with length %d\n", j, clibs->length);
                    exit(1);
                };
                char * l =  clibs->data[j];
if ((__checkString(l, "/home/alois/Documents/bah-bah/src/parser.bah:2640 l ")==1&&__checkString(ccstr, "/home/alois/Documents/bah-bah/src/parser.bah:2640 ccstr")==1&&strcmp(l, ccstr) == 0)) {
found =  true;
break;
}
j =  j + 1;
};
if ((found==true)) {
i =  i + 1;
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
i =  i + 1;
};
};
void parseConst(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
l =  parseCast(l,elems);
if ((len(l)!=4)) {
throwErr(&l->data[0],"Invalid usage of {TOKEN}, must be 'const <constName> = <constValue>'. ");
}

                if (l->length <= 1) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2662): l[%d] with length %d\n", 1, l->length);
                    exit(1);
                };
                struct Tok vart =  l->data[1];

                if (l->length <= 2) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2663): l[%d] with length %d\n", 2, l->length);
                    exit(1);
                };
                struct Tok equt =  l->data[2];

                if (l->length <= 3) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2664): l[%d] with length %d\n", 3, l->length);
                    exit(1);
                };
                struct Tok valt =  l->data[3];
if ((vart.type!=TOKEN_TYPE_VAR)) {
throwErr(&vart,"Cannot take {TOKEN} as const name.");
}
if ((__checkString(equt.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2668 equt.cont ")==1&&strcmp(equt.cont, "=") != 0)) {
throwErr(&equt,"Expected '=' not {TOKEN}.");
}
if ((valt.isValue==false)) {
throwErr(&equt,"Must be a value, not {TOKEN}.");
}
struct variable* ____BAH_COMPILER_VAR_812 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_812->name = "";
____BAH_COMPILER_VAR_812->type = "";
____BAH_COMPILER_VAR_812->isConst = false;
____BAH_COMPILER_VAR_812->constVal = "";
____BAH_COMPILER_VAR_812->isArray = false;
____BAH_COMPILER_VAR_812->from = "";
____BAH_COMPILER_VAR_812->outterScope = false;
struct variable* v =  ____BAH_COMPILER_VAR_812;
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
char * ____BAH_COMPILER_VAR_813 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("#define ");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(valt.cont);
long int strLen_4 = strlen("\n");
;                            
                        ____BAH_COMPILER_VAR_813 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_813+currStrOff, "#define ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_813+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_813+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_813+currStrOff, valt.cont, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_813+currStrOff, "\n", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_813));
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
char * ____BAH_COMPILER_VAR_814 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot return nothing as ");
long int strLen_1 = strlen(currentFn->returns->type);
long int strLen_2 = strlen(".");
;                            
                        ____BAH_COMPILER_VAR_814 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_814+currStrOff, "Cannot return nothing as ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_814+currStrOff, currentFn->returns->type, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_814+currStrOff, ".", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    throwErr(&l->data[0],____BAH_COMPILER_VAR_814);
}
}
else {

                if (l->length <= 1) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2701): l[%d] with length %d\n", 1, l->length);
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
char * ____BAH_COMPILER_VAR_815 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot return {TOKEN} (");
long int strLen_1 = strlen(tt);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(currentFn->returns->type);
long int strLen_4 = strlen(".");
;                            
                        ____BAH_COMPILER_VAR_815 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_815+currStrOff, "Cannot return {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_815+currStrOff, tt, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_815+currStrOff, ") as ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_815+currStrOff, currentFn->returns->type, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_815+currStrOff, ".", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    throwErr(&rvt,____BAH_COMPILER_VAR_815);
}
}
if ((compilerState.isBranch==false)) {
currentFn->returned =  true;
}
char * rvar =  genCompilerVar();
struct string cType =  getCType(currentFn->returns->type,elems);
if ((strlen(rv)>0)) {
char * ____BAH_COMPILER_VAR_816 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_817 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(____BAH_COMPILER_VAR_816);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(rvar);
long int strLen_3 = strlen(" = ");
long int strLen_4 = strlen(rv);
long int strLen_5 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_817 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_817+currStrOff, ____BAH_COMPILER_VAR_816, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_817+currStrOff, " ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_817+currStrOff, rvar, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_817+currStrOff, " = ", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_817+currStrOff, rv, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_817+currStrOff, ";\n", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_817));
endRCPscope(elems,null);
char * ____BAH_COMPILER_VAR_818 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("return ");
long int strLen_1 = strlen(rvar);
long int strLen_2 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_818 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_818+currStrOff, "return ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_818+currStrOff, rvar, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_818+currStrOff, ";\n", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_818));
}
else {
endRCPscope(elems,null);
OUTPUT =  OUTPUT->add(OUTPUT, rope("return;\n"));
}
};
void parseIf(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
if ((len(l)<4)) {

                if (l->length <= 0) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2735): l[%d] with length %d\n", 0, l->length);
                    exit(1);
                };
                struct Tok ft =  l->data[0];
throwErr(&ft,"Invalid usage of {TOKEN}, must be 'if <condition> {<code>}'");
}

                if (l->length <= 1) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2738): l[%d] with length %d\n", 1, l->length);
                    exit(1);
                };
                struct Tok condt =  l->data[1];
if ((__checkString(condt.bahType, "/home/alois/Documents/bah-bah/src/parser.bah:2739 condt.bahType ")==1&&strcmp(condt.bahType, "bool") != 0)) {
if ((__checkString(condt.bahType, "/home/alois/Documents/bah-bah/src/parser.bah:2740 condt.bahType ")==1&&strcmp(condt.bahType, "int") != 0)) {
throwErr(&condt,"Cannot use {TOKEN} as condition in if statement.");
}
}

                if (l->length <= 2) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2744): l[%d] with length %d\n", 2, l->length);
                    exit(1);
                };
                struct Tok t =  l->data[2];
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2745 t.cont ")==1&&strcmp(t.cont, "{") != 0)) {
throwErr(&t,"Expected '{' not {TOKEN} after condtition in if statement.");
}
array(struct Tok)* tokens = memoryAlloc(sizeof(array(struct Tok)));

tokens->length = 0;
tokens->elemSize = sizeof(struct Tok);
long int max =  len(l) - 1;
long int i =  3;
while ((i<max)) {

                if (l->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2751): l[%d] with length %d\n", i, l->length);
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
i =  i + 1;
};
char * ____BAH_COMPILER_VAR_819 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("if (");
long int strLen_1 = strlen(condt.cont);
long int strLen_2 = strlen(") {\n");
;                            
                        ____BAH_COMPILER_VAR_819 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_819+currStrOff, "if (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_819+currStrOff, condt.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_819+currStrOff, ") {\n", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_819));
struct Elems* ifElems =  dupElems(elems);
int oldIB =  compilerState.isBranch;
compilerState.isBranch =  true;
parseLines(tokens,ifElems);
endRCPscope(ifElems,null);
if ((debug==true)) {

                if (l->length <= len(l)-1) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2764): l[%d] with length %d\n", len(l)-1, l->length);
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
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2783): l[%d] with length %d\n", 1, l->length);
                    exit(1);
                };
                struct Tok ft =  l->data[1];
OUTPUT =  OUTPUT->add(OUTPUT, rope("else "));
if ((__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2785 ft.cont ")==1&&strcmp(ft.cont, "if") == 0)) {
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
long int i =  1;
while ((i<len(l))) {

                if (l->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2788): l[%d] with length %d\n", i, l->length);
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
parseIf(memory,elems);
prevLine =  LINE_TYPE_IF;
}
else {
if ((__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2795 ft.cont ")==1&&strcmp(ft.cont, "{") != 0)) {
throwErr(&ft,"Expected 'if' or '{' not {TOKEN}.");
}
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
long int max =  len(l) - 1;
long int i =  2;
while ((i<max)) {

                if (l->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2801): l[%d] with length %d\n", i, l->length);
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
OUTPUT =  OUTPUT->add(OUTPUT, rope("{\n"));
struct Elems* ifElems =  dupElems(elems);
int oldIB =  compilerState.isBranch;
compilerState.isBranch =  true;
parseLines(memory,ifElems);
endRCPscope(ifElems,null);
if ((debug==true)) {

                if (l->length <= len(l)-1) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2812): l[%d] with length %d\n", len(l)-1, l->length);
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
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2831): l[%d] with length %d\n", i, l->length);
                    exit(1);
                };
                struct Tok t =  l->data[i];
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2832 t.cont ")==1&&strcmp(t.cont, "{") == 0)) {
break;
}
if (((t.type==TOKEN_TYPE_SYNTAX)&&(__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2835 t.cont ")==1&&strcmp(t.cont, ",") == 0))) {
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
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2847): l[%d] with length %d\n", 0, l->length);
                    exit(1);
                };
                struct Tok t =  l->data[0];
throwErr(&t,"Invalid usage of {TOKEN}, can only partition line in 2 using 'for <condition>, <insctruction> {<code>}'.");
}
array(struct Tok)* inst = memoryAlloc(sizeof(array(struct Tok)));

inst->length = 0;
inst->elemSize = sizeof(struct Tok);

                if (l->length <= 1) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2852): l[%d] with length %d\n", 1, l->length);
                    exit(1);
                };
                struct Tok condt =  l->data[1];
if ((__checkString(condt.bahType, "/home/alois/Documents/bah-bah/src/parser.bah:2854 condt.bahType ")==1&&strcmp(condt.bahType, "bool") != 0)) {
if ((__checkString(condt.bahType, "/home/alois/Documents/bah-bah/src/parser.bah:2855 condt.bahType ")==1&&strcmp(condt.bahType, "int") != 0)) {
throwErr(&condt,"Cannot use {TOKEN} as condition in for statement.");
}
}

                if (l->length <= 2) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2860): l[%d] with length %d\n", 2, l->length);
                    exit(1);
                };
                struct Tok st =  l->data[2];
if (((st.type!=TOKEN_TYPE_SYNTAX)||(__checkString(st.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2862 st.cont ")==1&&strcmp(st.cont, ",") != 0))) {
throwErr(&st,"Cannot use {TOKEN}, need ',' to split for loop instructions.");
}
i =  3;
for (; (i<len(l)); i =  i+1) {

                if (l->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2867): l[%d] with length %d\n", i, l->length);
                    exit(1);
                };
                struct Tok t =  l->data[i];
if (((t.type==TOKEN_TYPE_ENCL)&&(__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2868 t.cont ")==1&&strcmp(t.cont, "{") == 0))) {
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
char * ____BAH_COMPILER_VAR_820 =OUTPUT->toStr((struct rope*)OUTPUT);struct string instC =  string(____BAH_COMPILER_VAR_820);
OUTPUT =  oldOut;
instC.trimRight((struct string*)&instC,2);

                if (l->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2883): l[%d] with length %d\n", i, l->length);
                    exit(1);
                };
                struct Tok t =  l->data[i];
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2884 t.cont ")==1&&strcmp(t.cont, "{") != 0)) {
throwErr(&t,"Expected '{' not {TOKEN} after '<condition>,<instruction>' in for statement.");
}
long int max =  len(l) - 1;
i =  i + 1;
for (; (i<max); i =  i+1) {

                if (l->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2890): l[%d] with length %d\n", i, l->length);
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
char * ____BAH_COMPILER_VAR_821 =instC.str((struct string*)&instC);char * ____BAH_COMPILER_VAR_822 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("for (; ");
long int strLen_1 = strlen(condt.cont);
long int strLen_2 = strlen("; ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_821);
long int strLen_4 = strlen(") {\n");
;                            
                        ____BAH_COMPILER_VAR_822 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_822+currStrOff, "for (; ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_822+currStrOff, condt.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_822+currStrOff, "; ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_822+currStrOff, ____BAH_COMPILER_VAR_821, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_822+currStrOff, ") {\n", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_822));
}
else {

                if (l->length <= 1) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2897): l[%d] with length %d\n", 1, l->length);
                    exit(1);
                };
                struct Tok condt =  l->data[1];
if ((__checkString(condt.bahType, "/home/alois/Documents/bah-bah/src/parser.bah:2898 condt.bahType ")==1&&strcmp(condt.bahType, "bool") != 0)) {
if ((__checkString(condt.bahType, "/home/alois/Documents/bah-bah/src/parser.bah:2899 condt.bahType ")==1&&strcmp(condt.bahType, "int") != 0)) {
throwErr(&condt,"Cannot use {TOKEN} as condition in for statement.");
}
}

                if (l->length <= 2) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2903): l[%d] with length %d\n", 2, l->length);
                    exit(1);
                };
                struct Tok t =  l->data[2];
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2904 t.cont ")==1&&strcmp(t.cont, "{") != 0)) {
throwErr(&t,"Expected '{' not {TOKEN} after condtition in for statement.");
}
long int max =  len(l) - 1;
i =  3;
for (; (i<max); i =  i+1) {

                if (l->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2909): l[%d] with length %d\n", i, l->length);
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
char * ____BAH_COMPILER_VAR_823 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("while (");
long int strLen_1 = strlen(condt.cont);
long int strLen_2 = strlen(") {\n");
;                            
                        ____BAH_COMPILER_VAR_823 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_823+currStrOff, "while (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_823+currStrOff, condt.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_823+currStrOff, ") {\n", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_823));
}
struct Elems* ifElems =  dupElems(elems);
int oldIB =  compilerState.isBranch;
int oldIF =  compilerState.isFor;
compilerState.isBranch =  true;
compilerState.isFor =  true;
parseLines(tokens,ifElems);
endRCPscope(ifElems,null);
if ((debug==true)) {

                if (l->length <= len(l)-1) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2923): l[%d] with length %d\n", len(l)-1, l->length);
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
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2934): l[%d] with length %d\n", 0, l->length);
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
char * ____BAH_COMPILER_VAR_824 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(ft.cont);
long int strLen_1 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_824 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_824+currStrOff, ft.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_824+currStrOff, ";\n", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_824));
};
void parsePreKeyword(__BAH_ARR_TYPE_Tok l,struct Elems* elems){

                if (l->length <= 0) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2949): l[%d] with length %d\n", 0, l->length);
                    exit(1);
                };
                struct Tok ft =  l->data[0];
if ((__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2951 ft.cont ")==1&&strcmp(ft.cont, "#warning") == 0)) {
if ((len(l)!=2)) {
throwErr(&ft,"Invalid usage of {TOKEN} '#warning \"message\"'.");
}

                if (l->length <= 1) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2955): l[%d] with length %d\n", 1, l->length);
                    exit(1);
                };
                struct Tok mt =  l->data[1];
if ((mt.type!=TOKEN_TYPE_STR)) {
throwErr(&mt,"Cannot use {TOKEN} as a string.");
}
struct string msg =  string(mt.cont);
msg.trimLeft((struct string*)&msg,1);
msg.trimRight((struct string*)&msg,1);
char * ____BAH_COMPILER_VAR_825 =msg.str((struct string*)&msg);throwWarning(____BAH_COMPILER_VAR_825);
return;
}
if ((len(l)<3)) {
throwErr(&ft,"Invalid usage of keyword {TOKEN}.");
}
if ((((__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2973 ft.cont ")==1&&strcmp(ft.cont, "#linux") == 0)||(__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2973 ft.cont ")==1&&strcmp(ft.cont, "#windows") == 0))||(__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2973 ft.cont ")==1&&strcmp(ft.cont, "#darwin") == 0))) {
struct string isOS =  string(ft.cont);
isOS.trimLeft((struct string*)&isOS,1);
if ((__checkString(isOS.str((struct string*)&isOS), "/home/alois/Documents/bah-bah/src/parser.bah:2976 isOS.str((struct string*)&isOS) ")==1&&__checkString(BAH_OS, "/home/alois/Documents/bah-bah/src/parser.bah:2976 BAH_OS")==1&&strcmp(isOS.str((struct string*)&isOS), BAH_OS) != 0)) {
return;
}
}
else if ((__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2979 ft.cont ")==1&&strcmp(ft.cont, "#static") == 0)) {
if ((flags.isSet((struct flags*)&flags,"d")==1)) {
return;
}
}
else if ((__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2983 ft.cont ")==1&&strcmp(ft.cont, "#dynamic") == 0)) {
if ((flags.isSet((struct flags*)&flags,"d")==0)) {
return;
}
}
else if ((__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2987 ft.cont ")==1&&strcmp(ft.cont, "#gc") == 0)) {
if ((RCPavailable()==true)) {
return;
}
}
else if ((__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2991 ft.cont ")==1&&strcmp(ft.cont, "#rcp") == 0)) {
if ((RCPavailable()==false)) {
return;
}
}
else if ((__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2995 ft.cont ")==1&&strcmp(ft.cont, "#lib") == 0)) {
if ((flags.isSet((struct flags*)&flags,"l")==0)) {
return;
}
}
else if ((__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2999 ft.cont ")==1&&strcmp(ft.cont, "#exec") == 0)) {
if ((flags.isSet((struct flags*)&flags,"l")==1)) {
return;
}
}
else {
throwErr(&ft,"Undefined token {TOKEN}.");
}

                if (l->length <= 1) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3007): l[%d] with length %d\n", 1, l->length);
                    exit(1);
                };
                struct Tok st =  l->data[1];

                if (l->length <= len(l)-1) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3008): l[%d] with length %d\n", len(l)-1, l->length);
                    exit(1);
                };
                struct Tok lt =  l->data[len(l)-1];
if (((__checkString(st.cont, "/home/alois/Documents/bah-bah/src/parser.bah:3009 st.cont ")==1&&strcmp(st.cont, "{") != 0)||(__checkString(lt.cont, "/home/alois/Documents/bah-bah/src/parser.bah:3009 lt.cont ")==1&&strcmp(lt.cont, "}") != 0))) {
throwErr(&st,"Expected code block after keyword {TOKEN}.");
}
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
long int i =  2;
while ((i<len(l) - 1)) {

                if (l->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3015): l[%d] with length %d\n", i, l->length);
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
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3025): l[%d] with length %d\n", 0, l->length);
                    exit(1);
                };
                struct Tok ft =  l->data[0];
throwErr(&ft,"Cannot use keyword {TOKEN} on a function call 'async <function call>'.");
}

                if (l->length <= 1) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3028): l[%d] with length %d\n", 1, l->length);
                    exit(1);
                };
                struct Tok fnT =  l->data[1];
if ((fnT.isFunc==false)) {
throwErr(&fnT,"Cannot use keyword async on {TOKEN}. Usage: 'async <function call>'.");
}
int found =  false;
long int i =  0;
while ((i<len(compilerState.cLibs))) {

                if (compilerState.cLibs->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3035): compilerState.cLibs[%d] with length %d\n", i, compilerState.cLibs->length);
                    exit(1);
                };
                if ((__checkString(compilerState.cLibs->data[i], "/home/alois/Documents/bah-bah/src/parser.bah:3035 compilerState.cLibs->data[i] ")==1&&strcmp(compilerState.cLibs->data[i], "lpthread") == 0)) {
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
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3048): fnNameParts[%d] with length %d\n", 0, fnNameParts->length);
                    exit(1);
                };
                struct string fnName =  fnNameParts->data[0];
char * ____BAH_COMPILER_VAR_834 =fnName.str((struct string*)&fnName);struct func* fn =  searchFunc(____BAH_COMPILER_VAR_834,elems,true);
if ((fn==null)) {
throwErr(&fnT,"Internal compiler error.\n Error in async parsing, arround {TOKEN}.");
}
char * sMembs =  "";
char * unSerMembs =  "";
i =  0;
while ((i<len(fn->args))) {

                if (fn->args->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3059): fn->args[%d] with length %d\n", i, fn->args->length);
                    exit(1);
                };
                struct variable* a =  fn->args->data[i];
struct string cType =  getCType(a->type,elems);
char * ____BAH_COMPILER_VAR_835 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_836 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(sMembs);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_835);
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(a->name);
long int strLen_4 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_836 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_836+currStrOff, sMembs, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_836+currStrOff, ____BAH_COMPILER_VAR_835, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_836+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_836+currStrOff, a->name, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_836+currStrOff, ";\n", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    sMembs =  ____BAH_COMPILER_VAR_836;
char * ____BAH_COMPILER_VAR_837 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(unSerMembs);
long int strLen_1 = strlen("args->");
long int strLen_2 = strlen(a->name);
;                            
                        ____BAH_COMPILER_VAR_837 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_837+currStrOff, unSerMembs, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_837+currStrOff, "args->", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_837+currStrOff, a->name, strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    unSerMembs =  ____BAH_COMPILER_VAR_837;
i =  i + 1;
if ((i<len(fn->args))) {
char * ____BAH_COMPILER_VAR_838 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(unSerMembs);
long int strLen_1 = strlen(", ");
;                            
                        ____BAH_COMPILER_VAR_838 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_838+currStrOff, unSerMembs, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_838+currStrOff, ", ", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    unSerMembs =  ____BAH_COMPILER_VAR_838;
}
};
char * ____BAH_COMPILER_VAR_839 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("struct {\n");
long int strLen_1 = strlen(sMembs);
long int strLen_2 = strlen("}");
;                            
                        ____BAH_COMPILER_VAR_839 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_839+currStrOff, "struct {\n", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_839+currStrOff, sMembs, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_839+currStrOff, "}", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    char * tmpArgsStruct =  ____BAH_COMPILER_VAR_839;
char * fnWrapper =  genCompilerVar();
char * tmpArgs =  genCompilerVar();
sFnT.trimLeft((struct string*)&sFnT,fnName.length + 1);
sFnT.trimRight((struct string*)&sFnT,1);
char * tCreate =  "";
if ((__checkString(BAH_OS, "/home/alois/Documents/bah-bah/src/parser.bah:3077 BAH_OS ")==1&&strcmp(BAH_OS, "windows") == 0)) {
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
char * ____BAH_COMPILER_VAR_840 =fnName.str((struct string*)&fnName);char * ____BAH_COMPILER_VAR_841 =sFnT.str((struct string*)&sFnT);char * ____BAH_COMPILER_VAR_842 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\n    void ");
long int strLen_1 = strlen(fnWrapper);
long int strLen_2 = strlen("(");
long int strLen_3 = strlen(tmpArgsStruct);
long int strLen_4 = strlen("* args) {\n        ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_840);
long int strLen_6 = strlen("(");
long int strLen_7 = strlen(unSerMembs);
long int strLen_8 = strlen(");\n    };\n    {\n        ");
long int strLen_9 = strlen(tmpArgsStruct);
long int strLen_10 = strlen(" ");
long int strLen_11 = strlen(tmpArgs);
long int strLen_12 = strlen(" = {");
long int strLen_13 = strlen(____BAH_COMPILER_VAR_841);
long int strLen_14 = strlen("};\n        pthread_t id;\n        ");
long int strLen_15 = strlen(tCreate);
long int strLen_16 = strlen("(&id, 0, ");
long int strLen_17 = strlen(fnWrapper);
long int strLen_18 = strlen(", &");
long int strLen_19 = strlen(tmpArgs);
long int strLen_20 = strlen(");\n    }; \n    \n    ");
;                            
                        ____BAH_COMPILER_VAR_842 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14 + strLen_15 + strLen_16 + strLen_17 + strLen_18 + strLen_19 + strLen_20);
                        
                        strncpy(____BAH_COMPILER_VAR_842+currStrOff, "\n    void ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_842+currStrOff, fnWrapper, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_842+currStrOff, "(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_842+currStrOff, tmpArgsStruct, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_842+currStrOff, "* args) {\n        ", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_842+currStrOff, ____BAH_COMPILER_VAR_840, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_842+currStrOff, "(", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_842+currStrOff, unSerMembs, strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_842+currStrOff, ");\n    };\n    {\n        ", strLen_8);
                        currStrOff += strLen_8;
                        
                        strncpy(____BAH_COMPILER_VAR_842+currStrOff, tmpArgsStruct, strLen_9);
                        currStrOff += strLen_9;
                        
                        strncpy(____BAH_COMPILER_VAR_842+currStrOff, " ", strLen_10);
                        currStrOff += strLen_10;
                        
                        strncpy(____BAH_COMPILER_VAR_842+currStrOff, tmpArgs, strLen_11);
                        currStrOff += strLen_11;
                        
                        strncpy(____BAH_COMPILER_VAR_842+currStrOff, " = {", strLen_12);
                        currStrOff += strLen_12;
                        
                        strncpy(____BAH_COMPILER_VAR_842+currStrOff, ____BAH_COMPILER_VAR_841, strLen_13);
                        currStrOff += strLen_13;
                        
                        strncpy(____BAH_COMPILER_VAR_842+currStrOff, "};\n        pthread_t id;\n        ", strLen_14);
                        currStrOff += strLen_14;
                        
                        strncpy(____BAH_COMPILER_VAR_842+currStrOff, tCreate, strLen_15);
                        currStrOff += strLen_15;
                        
                        strncpy(____BAH_COMPILER_VAR_842+currStrOff, "(&id, 0, ", strLen_16);
                        currStrOff += strLen_16;
                        
                        strncpy(____BAH_COMPILER_VAR_842+currStrOff, fnWrapper, strLen_17);
                        currStrOff += strLen_17;
                        
                        strncpy(____BAH_COMPILER_VAR_842+currStrOff, ", &", strLen_18);
                        currStrOff += strLen_18;
                        
                        strncpy(____BAH_COMPILER_VAR_842+currStrOff, tmpArgs, strLen_19);
                        currStrOff += strLen_19;
                        
                        strncpy(____BAH_COMPILER_VAR_842+currStrOff, ");\n    }; \n    \n    ", strLen_20);
                        currStrOff += strLen_20;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_842));
};
void addRCPvars(__BAH_ARR_TYPE_Tok l,lineType ltp,struct Elems* elems){
long int i =  0;
if ((ltp==LINE_TYPE_VAR)) {
i =  1;
}
while ((i<len(l))) {

                if (l->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3106): l[%d] with length %d\n", i, l->length);
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
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3122): l[%d] with length %d\n", i, l->length);
                    exit(1);
                };
                struct Tok t =  l->data[i];
if ((((t.type==TOKEN_TYPE_SYNTAX)&&(__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:3123 t.cont ")==1&&strcmp(t.cont, "->") == 0))||(__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:3123 t.cont ")==1&&strcmp(t.cont, "<-") == 0))) {
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:3125 t.cont ")==1&&strcmp(t.cont, "<-") == 0)) {
i =  i+1;
if ((i<len(l))) {

                if (l->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3128): l[%d] with length %d\n", i, l->length);
                    exit(1);
                };
                struct Tok nt =  l->data[i];
if ((nt.type!=TOKEN_TYPE_VAR)) {
throwErr(&nt,"Cannot use {TOKEN} as channel.");
}
char * ____BAH_COMPILER_VAR_843 =getTypeFromToken(&nt,true,elems);struct string ntt =  string(____BAH_COMPILER_VAR_843);
if ((ntt.hasPrefix((struct string*)&ntt,"chan:")==0)) {
char * ____BAH_COMPILER_VAR_844 =ntt.str((struct string*)&ntt);char * ____BAH_COMPILER_VAR_845 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot use var {TOKEN} (");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_844);
long int strLen_2 = strlen(") as channel.");
;                            
                        ____BAH_COMPILER_VAR_845 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_845+currStrOff, "Cannot use var {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_845+currStrOff, ____BAH_COMPILER_VAR_844, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_845+currStrOff, ") as channel.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    throwErr(&nt,____BAH_COMPILER_VAR_845);
}
ntt.trimLeft((struct string*)&ntt,5);
if (isGlobal()) {
throwErr(&t,"Cannot receive ({TOKEN}) from a channel outside of a function.");
}
char * ____BAH_COMPILER_VAR_846 =ntt.str((struct string*)&ntt);if (isRCPpointerType(____BAH_COMPILER_VAR_846)) {
char * ____BAH_COMPILER_VAR_847 =ntt.str((struct string*)&ntt);struct string ct =  getCType(____BAH_COMPILER_VAR_847,elems);
char * ____BAH_COMPILER_VAR_848 =ct.str((struct string*)&ct);char * ____BAH_COMPILER_VAR_849 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("(");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_848);
long int strLen_2 = strlen(")");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen("->receive(");
long int strLen_5 = strlen(nt.cont);
long int strLen_6 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_849 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                        
                        strncpy(____BAH_COMPILER_VAR_849+currStrOff, "(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_849+currStrOff, ____BAH_COMPILER_VAR_848, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_849+currStrOff, ")", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_849+currStrOff, nt.cont, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_849+currStrOff, "->receive(", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_849+currStrOff, nt.cont, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_849+currStrOff, ")", strLen_6);
                        currStrOff += strLen_6;
                        
                    }
                    t.cont =  ____BAH_COMPILER_VAR_849;
}
else {
char * ____BAH_COMPILER_VAR_850 =ntt.str((struct string*)&ntt);struct string ct =  getCType(____BAH_COMPILER_VAR_850,elems);
char * ____BAH_COMPILER_VAR_851 =ct.str((struct string*)&ct);char * ____BAH_COMPILER_VAR_852 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("*(");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_851);
long int strLen_2 = strlen("*)");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen("->receive(");
long int strLen_5 = strlen(nt.cont);
long int strLen_6 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_852 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                        
                        strncpy(____BAH_COMPILER_VAR_852+currStrOff, "*(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_852+currStrOff, ____BAH_COMPILER_VAR_851, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_852+currStrOff, "*)", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_852+currStrOff, nt.cont, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_852+currStrOff, "->receive(", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_852+currStrOff, nt.cont, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_852+currStrOff, ")", strLen_6);
                        currStrOff += strLen_6;
                        
                    }
                    t.cont =  ____BAH_COMPILER_VAR_852;
}
t.isFunc =  true;
t.type =  TOKEN_TYPE_FUNC;
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
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3163): l[%d] with length %d\n", i + 1, l->length);
                    exit(1);
                };
                struct Tok pt =  l->data[i + 1];

                if (l->length <= i-1) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3164): l[%d] with length %d\n", i-1, l->length);
                    exit(1);
                };
                struct Tok nt =  l->data[i-1];
char * ntt =  getTypeFromToken(&nt,true,elems);
if ((pt.type!=TOKEN_TYPE_VAR)) {
throwErr(&pt,"Cannot use {TOKEN} as channel.");
}
char * ____BAH_COMPILER_VAR_853 =getTypeFromToken(&pt,true,elems);struct string ptt =  string(____BAH_COMPILER_VAR_853);
if ((ptt.hasPrefix((struct string*)&ptt,"chan:")==0)) {
char * ____BAH_COMPILER_VAR_854 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot use var {TOKEN} (");
long int strLen_1 = strlen(ntt);
long int strLen_2 = strlen(") as channel.");
;                            
                        ____BAH_COMPILER_VAR_854 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_854+currStrOff, "Cannot use var {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_854+currStrOff, ntt, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_854+currStrOff, ") as channel.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    throwErr(&pt,____BAH_COMPILER_VAR_854);
}
ptt.trimLeft((struct string*)&ptt,5);
if (isGlobal()) {
throwErr(&t,"Cannot send ({TOKEN}) to a channel outside of a function.");
}
char * ____BAH_COMPILER_VAR_855 =ptt.str((struct string*)&ptt);if ((compTypes(____BAH_COMPILER_VAR_855,ntt)==false)) {
char * ____BAH_COMPILER_VAR_856 =ptt.str((struct string*)&ptt);char * ____BAH_COMPILER_VAR_857 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot send {TOKEN} (");
long int strLen_1 = strlen(ntt);
long int strLen_2 = strlen(") to channel of type ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_856);
long int strLen_4 = strlen(".");
;                            
                        ____BAH_COMPILER_VAR_857 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_857+currStrOff, "Cannot send {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_857+currStrOff, ntt, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_857+currStrOff, ") to channel of type ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_857+currStrOff, ____BAH_COMPILER_VAR_856, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_857+currStrOff, ".", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    throwErr(&nt,____BAH_COMPILER_VAR_857);
}
i =  i+1;
char * ____BAH_COMPILER_VAR_858 =ptt.str((struct string*)&ptt);if (isRCPpointerType(____BAH_COMPILER_VAR_858)) {
char * ____BAH_COMPILER_VAR_859 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen("->send(");
long int strLen_2 = strlen(pt.cont);
long int strLen_3 = strlen(", ");
long int strLen_4 = strlen(nt.cont);
long int strLen_5 = strlen(");\n");
;                            
                        ____BAH_COMPILER_VAR_859 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_859+currStrOff, pt.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_859+currStrOff, "->send(", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_859+currStrOff, pt.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_859+currStrOff, ", ", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_859+currStrOff, nt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_859+currStrOff, ");\n", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_859));
}
else {
struct string ct =  getCType(ntt,elems);
char * tmpV =  genCompilerVar();
char * ____BAH_COMPILER_VAR_860 =ct.str((struct string*)&ct);char * ____BAH_COMPILER_VAR_861 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\n                    ");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_860);
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
                        ____BAH_COMPILER_VAR_861 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14);
                        
                        strncpy(____BAH_COMPILER_VAR_861+currStrOff, "\n                    ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_861+currStrOff, ____BAH_COMPILER_VAR_860, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_861+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_861+currStrOff, tmpV, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_861+currStrOff, " = ", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_861+currStrOff, nt.cont, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_861+currStrOff, ";\n                    ", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_861+currStrOff, pt.cont, strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_861+currStrOff, "->sendAny(", strLen_8);
                        currStrOff += strLen_8;
                        
                        strncpy(____BAH_COMPILER_VAR_861+currStrOff, pt.cont, strLen_9);
                        currStrOff += strLen_9;
                        
                        strncpy(____BAH_COMPILER_VAR_861+currStrOff, ", &", strLen_10);
                        currStrOff += strLen_10;
                        
                        strncpy(____BAH_COMPILER_VAR_861+currStrOff, tmpV, strLen_11);
                        currStrOff += strLen_11;
                        
                        strncpy(____BAH_COMPILER_VAR_861+currStrOff, ", sizeof(", strLen_12);
                        currStrOff += strLen_12;
                        
                        strncpy(____BAH_COMPILER_VAR_861+currStrOff, tmpV, strLen_13);
                        currStrOff += strLen_13;
                        
                        strncpy(____BAH_COMPILER_VAR_861+currStrOff, "));\n", strLen_14);
                        currStrOff += strLen_14;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_861));
}
nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
array(struct Tok)* ____BAH_COMPILER_VAR_862 = nl;
return ____BAH_COMPILER_VAR_862;
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
array(struct Tok)* ____BAH_COMPILER_VAR_863 = nl;
return ____BAH_COMPILER_VAR_863;
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
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3211): line[%d] with length %d\n", i, line->length);
                    exit(1);
                };
                struct Tok t =  line->data[i];
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:3212 t.cont ")==1&&strcmp(t.cont, "(") == 0)) {
nbPar =  nbPar + 1;
}
else if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:3214 t.cont ")==1&&strcmp(t.cont, ")") == 0)) {
nbPar =  nbPar - 1;
}
else if (((nbPar==0)&&(__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:3216 t.cont ")==1&&strcmp(t.cont, "{") == 0))) {

                if (line->length <= i + 1) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3217): line[%d] with length %d\n", i + 1, line->length);
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
i =  i + 1;
};
}
else {
fl =  line;
}
fl =  parseStructVars(fl,elems);
fl =  parseFnCall(fl,ltp,elems);
fl =  parseArrayVars(fl,elems);
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
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3242): line[%d] with length %d\n", i, line->length);
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
i =  i + 1;
};
}
array(struct Tok)* ____BAH_COMPILER_VAR_864 = fl;
return ____BAH_COMPILER_VAR_864;
};
void parseFnDeclare(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
long int i =  0;
struct func* ____BAH_COMPILER_VAR_865 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_865->name = "";
____BAH_COMPILER_VAR_865->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_865->args->length = 0;
            ____BAH_COMPILER_VAR_865->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_865->returns= null;
____BAH_COMPILER_VAR_865->isBinding = false;
____BAH_COMPILER_VAR_865->from = "";
____BAH_COMPILER_VAR_865->file = "";
____BAH_COMPILER_VAR_865->line = 1;
struct func* fn =  ____BAH_COMPILER_VAR_865;

                if (l->length <= 0) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3254): l[%d] with length %d\n", 0, l->length);
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
char * ____BAH_COMPILER_VAR_866 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot redeclare function {TOKEN}, previous declaration: ");
long int strLen_1 = strlen(ogFn->file);
long int strLen_2 = strlen(":");
long int strLen_3 = strlen(lineStr);
long int strLen_4 = strlen(".");
;                            
                        ____BAH_COMPILER_VAR_866 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_866+currStrOff, "Cannot redeclare function {TOKEN}, previous declaration: ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_866+currStrOff, ogFn->file, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_866+currStrOff, ":", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_866+currStrOff, lineStr, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_866+currStrOff, ".", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    throwErr(&ft,____BAH_COMPILER_VAR_866);
}
}
if ((__checkString(fn->name, "/home/alois/Documents/bah-bah/src/parser.bah:3266 fn->name ")==1&&strcmp(fn->name, "main") == 0)) {
compilerState.haveEntryPoint =  true;
if ((compTypes(fn->returns->type,"int")==false)) {
throwErr(&ft,"{TOKEN} function should return 'int'.");
}
if ((len(fn->args)!=1)) {
throwErr(&ft,"{TOKEN} function should take one []cpstring argument. Should be: \n            'main(args []cpstring) int'");
}

                if (fn->args->length <= 0) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3275): fn->args[%d] with length %d\n", 0, fn->args->length);
                    exit(1);
                };
                struct variable* fa =  fn->args->data[0];
if ((compTypes(fa->type,"[]cpstring")==false)) {
throwErr(&ft,"{TOKEN} function should take []cpstring as argument. Should be: \n            'main(args []cpstring) int'");
}
}
char * ____BAH_COMPILER_VAR_867 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(code);
long int strLen_1 = strlen("{\n");
;                            
                        ____BAH_COMPILER_VAR_867 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_867+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_867+currStrOff, "{\n", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_867;
OUTPUT =  OUTPUT->add(OUTPUT, rope(code));
struct Elems* fnElems =  dupElems(elems);
array(struct variable*)* vs =  fnElems->vars;
long int j =  0;
while ((j<len(fn->args))) {

                if (fn->args->length <= j) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3289): fn->args[%d] with length %d\n", j, fn->args->length);
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
i =  i + 1;
long int max =  len(l)-1;
while ((i<max)) {

                if (l->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3308): l[%d] with length %d\n", i, l->length);
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
i =  i + 1;
};
if ((len(tokens)==0)) {
OUTPUT =  OUTPUT->add(OUTPUT, rope("};\n"));
return;
}
currentFn =  fn;
parseLines(tokens,fnElems);
currentFn =  null;
if ((fn->returned==false)) {
if ((strlen(fn->returns->type)>0)) {
char * ____BAH_COMPILER_VAR_869 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Function '");
long int strLen_1 = strlen(fn->name);
long int strLen_2 = strlen("' is not returned.");
;                            
                        ____BAH_COMPILER_VAR_869 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_869+currStrOff, "Function '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_869+currStrOff, fn->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_869+currStrOff, "' is not returned.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    throwErr(&l->data[len(l)-1],____BAH_COMPILER_VAR_869);
}
endRCPscope(fnElems,null);
}
OUTPUT =  OUTPUT->add(OUTPUT, rope("};\n"));
if ((debug==true)) {
struct debugFunction* ____BAH_COMPILER_VAR_870 = memoryAlloc(sizeof(struct debugFunction));
____BAH_COMPILER_VAR_870->name= null;
____BAH_COMPILER_VAR_870->returns= null;
____BAH_COMPILER_VAR_870->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_870->args->length = 0;
            ____BAH_COMPILER_VAR_870->args->elemSize = sizeof(struct variable*);
            struct debugFunction* df =  ____BAH_COMPILER_VAR_870;
df->name =  fn->name;
df->args =  fn->args;
df->returns =  fn->returns->type;
struct debugFunction* ____BAH_COMPILER_VAR_871 = df;
char ** ____BAH_COMPILER_VAR_873 = (char **)((char*)(____BAH_COMPILER_VAR_871) + offsetof(struct debugFunction, name));
struct reflectElement ____BAH_COMPILER_VAR_874 = __reflect(____BAH_COMPILER_VAR_873, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct debugFunction, name));
char ** ____BAH_COMPILER_VAR_875 = (char **)((char*)(____BAH_COMPILER_VAR_871) + offsetof(struct debugFunction, returns));
struct reflectElement ____BAH_COMPILER_VAR_876 = __reflect(____BAH_COMPILER_VAR_875, sizeof(char *), "cpstring", "returns", 0, 0, 0, 0, offsetof(struct debugFunction, returns));
array(struct variable*)** ____BAH_COMPILER_VAR_877 = (array(struct variable*)**)((char*)(____BAH_COMPILER_VAR_871) + offsetof(struct debugFunction, args));
struct variable** ____BAH_COMPILER_VAR_878 = 0;
char ** ____BAH_COMPILER_VAR_880 = (char **)((char*)(____BAH_COMPILER_VAR_878) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_881 = __reflect(____BAH_COMPILER_VAR_880, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_882 = (char **)((char*)(____BAH_COMPILER_VAR_878) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_883 = __reflect(____BAH_COMPILER_VAR_882, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
int* ____BAH_COMPILER_VAR_884 = (int*)((char*)(____BAH_COMPILER_VAR_878) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_885 = __reflect(____BAH_COMPILER_VAR_884, sizeof(int), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_886 = (char **)((char*)(____BAH_COMPILER_VAR_878) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_887 = __reflect(____BAH_COMPILER_VAR_886, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
int* ____BAH_COMPILER_VAR_888 = (int*)((char*)(____BAH_COMPILER_VAR_878) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_889 = __reflect(____BAH_COMPILER_VAR_888, sizeof(int), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_890 = (char **)((char*)(____BAH_COMPILER_VAR_878) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_891 = __reflect(____BAH_COMPILER_VAR_890, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
int* ____BAH_COMPILER_VAR_892 = (int*)((char*)(____BAH_COMPILER_VAR_878) + offsetof(struct variable, outterScope));
struct reflectElement ____BAH_COMPILER_VAR_893 = __reflect(____BAH_COMPILER_VAR_892, sizeof(int), "bool", "outterScope", 0, 0, 0, 0, offsetof(struct variable, outterScope));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_879 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_879->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_879->length = 7;
        ____BAH_COMPILER_VAR_879->data = memoryAlloc(____BAH_COMPILER_VAR_879->length * ____BAH_COMPILER_VAR_879->elemSize);
        ____BAH_COMPILER_VAR_879->data[0] = ____BAH_COMPILER_VAR_881;
____BAH_COMPILER_VAR_879->data[1] = ____BAH_COMPILER_VAR_883;
____BAH_COMPILER_VAR_879->data[2] = ____BAH_COMPILER_VAR_885;
____BAH_COMPILER_VAR_879->data[3] = ____BAH_COMPILER_VAR_887;
____BAH_COMPILER_VAR_879->data[4] = ____BAH_COMPILER_VAR_889;
____BAH_COMPILER_VAR_879->data[5] = ____BAH_COMPILER_VAR_891;
____BAH_COMPILER_VAR_879->data[6] = ____BAH_COMPILER_VAR_893;
struct reflectElement ____BAH_COMPILER_VAR_894 = __reflect(____BAH_COMPILER_VAR_878, sizeof(struct variable), "variable*", "", 0, 0, 1, ____BAH_COMPILER_VAR_879, 0);

        struct reflectElement ____BAH_COMPILER_VAR_895 = ____BAH_COMPILER_VAR_894;
        struct reflectElement ____BAH_COMPILER_VAR_896 = __reflect(____BAH_COMPILER_VAR_877, sizeof(array(struct variable*)*), "[]variable*", "args", 1, &____BAH_COMPILER_VAR_895, 0, 0, offsetof(struct debugFunction, args));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_872 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_872->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_872->length = 3;
        ____BAH_COMPILER_VAR_872->data = memoryAlloc(____BAH_COMPILER_VAR_872->length * ____BAH_COMPILER_VAR_872->elemSize);
        ____BAH_COMPILER_VAR_872->data[0] = ____BAH_COMPILER_VAR_874;
____BAH_COMPILER_VAR_872->data[1] = ____BAH_COMPILER_VAR_876;
____BAH_COMPILER_VAR_872->data[2] = ____BAH_COMPILER_VAR_896;
struct reflectElement ____BAH_COMPILER_VAR_897 = __reflect(____BAH_COMPILER_VAR_871, sizeof(struct debugFunction), "debugFunction*", "df", 0, 0, 1, ____BAH_COMPILER_VAR_872, 0);
debugPrint("fn_declare",ft.line,____BAH_COMPILER_VAR_897);

                if (l->length <= len(l)-1) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3337): l[%d] with length %d\n", len(l)-1, l->length);
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
int parsed =  false;
if ((ltp==LINE_TYPE_INCLUDE)) {
parsed =  true;
parseInclude(line,elems);
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
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3388): line[%d] with length %d\n", 0, line->length);
                    exit(1);
                };
                struct Tok ft =  line->data[0];
parsed =  true;
char * ____BAH_COMPILER_VAR_901 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(ft.cont);
long int strLen_1 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_901 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_901+currStrOff, ft.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_901+currStrOff, ";\n", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_901));
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
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3418): line[%d] with length %d\n", 0, line->length);
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
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3437): tokens[%d] with length %d\n", 0, tokens->length);
                    exit(1);
                };
                struct Tok ft =  tokens->data[0];
long int currentLine =  ft.line;
long int nbEncl =  0;
long int i =  0;
while ((i<len(tokens))) {

                if (tokens->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3441): tokens[%d] with length %d\n", i, tokens->length);
                    exit(1);
                };
                struct Tok t =  tokens->data[i];
if ((t.type==TOKEN_TYPE_ENCL)) {
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:3444 t.cont ")==1&&strcmp(t.cont, "(") == 0)) {
nbEncl =  nbEncl + 1;
}
else if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:3446 t.cont ")==1&&strcmp(t.cont, ")") == 0)) {
nbEncl =  nbEncl - 1;
}
else if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:3448 t.cont ")==1&&strcmp(t.cont, "{") == 0)) {
nbEncl =  nbEncl + 1;
}
else if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:3450 t.cont ")==1&&strcmp(t.cont, "}") == 0)) {
nbEncl =  nbEncl - 1;
}
else if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:3452 t.cont ")==1&&strcmp(t.cont, "[") == 0)) {
nbEncl =  nbEncl + 1;
}
else if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:3454 t.cont ")==1&&strcmp(t.cont, "]") == 0)) {
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
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3467): tokens[%d] with length %d\n", i-1, tokens->length);
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
i =  i + 1;
continue;
}
}
else if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:3478 t.cont ")==1&&strcmp(t.cont, ";") == 0)) {
currentLine =  t.line;
parseLine(line,elems);
clear(line);
i =  i + 1;
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
i =  i + 1;
};
if ((len(line)>0)) {
if ((nbEncl==0)) {
parseLine(line,elems);
clear(line);
}
else {

                if (line->length <= len(line)-1) {
                    printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3496): line[%d] with length %d\n", len(line)-1, line->length);
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
char * ____BAH_COMPILER_VAR_903 =ct.str((struct string*)&ct);char * ____BAH_COMPILER_VAR_904 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_903);
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(arg->name);
;                            
                        ____BAH_COMPILER_VAR_904 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                        
                        strncpy(____BAH_COMPILER_VAR_904+currStrOff, tmpfnArgsCType, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_904+currStrOff, ____BAH_COMPILER_VAR_903, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_904+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_904+currStrOff, arg->name, strLen_3);
                        currStrOff += strLen_3;
                        
                    }
                    tmpfnArgsCType =  ____BAH_COMPILER_VAR_904;
j =  j + 1;
if ((j<len(fn->args))) {
char * ____BAH_COMPILER_VAR_905 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(", ");
;                            
                        ____BAH_COMPILER_VAR_905 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_905+currStrOff, tmpfnArgsCType, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_905+currStrOff, ", ", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    tmpfnArgsCType =  ____BAH_COMPILER_VAR_905;
}
};
char * ____BAH_COMPILER_VAR_906 =tmpfnRetCType.str((struct string*)&tmpfnRetCType);char * ____BAH_COMPILER_VAR_907 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(____BAH_COMPILER_VAR_906);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(fn->name);
long int strLen_3 = strlen("(");
long int strLen_4 = strlen(tmpfnArgsCType);
long int strLen_5 = strlen(");\n");
;                            
                        ____BAH_COMPILER_VAR_907 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_907+currStrOff, ____BAH_COMPILER_VAR_906, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_907+currStrOff, " ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_907+currStrOff, fn->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_907+currStrOff, "(", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_907+currStrOff, tmpfnArgsCType, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_907+currStrOff, ");\n", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_907));
};
void declareVar(struct variable* v,struct Elems* elems){
if ((v->isConst==true)) {
char * ____BAH_COMPILER_VAR_908 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("#define ");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(v->constVal);
long int strLen_4 = strlen("\n");
;                            
                        ____BAH_COMPILER_VAR_908 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_908+currStrOff, "#define ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_908+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_908+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_908+currStrOff, v->constVal, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_908+currStrOff, "\n", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_908));
}
else {
struct string cType =  getCType(v->type,elems);
char * ____BAH_COMPILER_VAR_909 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_910 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(____BAH_COMPILER_VAR_909);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(v->name);
long int strLen_3 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_910 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                        
                        strncpy(____BAH_COMPILER_VAR_910+currStrOff, ____BAH_COMPILER_VAR_909, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_910+currStrOff, " ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_910+currStrOff, v->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_910+currStrOff, ";\n", strLen_3);
                        currStrOff += strLen_3;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_910));
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
                char * ____BAH_COMPILER_VAR_911 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("#include ");
long int strLen_1 = strlen(compilerState.cIncludes->data[i]);
long int strLen_2 = strlen("\n");
;                            
                        ____BAH_COMPILER_VAR_911 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_911+currStrOff, "#include ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_911+currStrOff, compilerState.cIncludes->data[i], strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_911+currStrOff, "\n", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_911));
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
char * ____BAH_COMPILER_VAR_912 =elemType.str((struct string*)&elemType);struct string elemCtype =  getCType(____BAH_COMPILER_VAR_912,elems);
char * ____BAH_COMPILER_VAR_913 =elemCtype.str((struct string*)&elemCtype);char * ____BAH_COMPILER_VAR_914 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("typedef array(");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_913);
long int strLen_2 = strlen(")* ");
long int strLen_3 = strlen(t);
long int strLen_4 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_914 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_914+currStrOff, "typedef array(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_914+currStrOff, ____BAH_COMPILER_VAR_913, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_914+currStrOff, ")* ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_914+currStrOff, t, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_914+currStrOff, ";\n", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_914));
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
struct flags ____BAH_COMPILER_VAR_915 = {};
____BAH_COMPILER_VAR_915.flags = memoryAlloc(sizeof(array(struct flag*)));
            ____BAH_COMPILER_VAR_915.flags->length = 0;
            ____BAH_COMPILER_VAR_915.flags->elemSize = sizeof(struct flag*);
            ____BAH_COMPILER_VAR_915.args = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_915.args->length = 0;
            ____BAH_COMPILER_VAR_915.args->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_915.addString = flags__addString;
____BAH_COMPILER_VAR_915.addBool = flags__addBool;
____BAH_COMPILER_VAR_915.addInt = flags__addInt;
____BAH_COMPILER_VAR_915.addFloat = flags__addFloat;
____BAH_COMPILER_VAR_915.invalidate = flags__invalidate;
____BAH_COMPILER_VAR_915.getFlag = flags__getFlag;
____BAH_COMPILER_VAR_915.get = flags__get;
____BAH_COMPILER_VAR_915.getInt = flags__getInt;
____BAH_COMPILER_VAR_915.getFloat = flags__getFloat;
____BAH_COMPILER_VAR_915.isSet = flags__isSet;
____BAH_COMPILER_VAR_915.parse = flags__parse;
flags =  ____BAH_COMPILER_VAR_915;
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
char * ____BAH_COMPILER_VAR_916 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Select the target OS for cross compilling (linux, windows, darwin), default: ");
long int strLen_1 = strlen(BAH_OS);
long int strLen_2 = strlen(".");
;                            
                        ____BAH_COMPILER_VAR_916 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_916+currStrOff, "Select the target OS for cross compilling (linux, windows, darwin), default: ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_916+currStrOff, BAH_OS, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_916+currStrOff, ".", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    flags.addString((struct flags*)&flags,"target",____BAH_COMPILER_VAR_916);
char * ____BAH_COMPILER_VAR_917 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("If your Bah directory is not the default one (");
long int strLen_1 = strlen(BAH_DIR);
long int strLen_2 = strlen(").");
;                            
                        ____BAH_COMPILER_VAR_917 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_917+currStrOff, "If your Bah directory is not the default one (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_917+currStrOff, BAH_DIR, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_917+currStrOff, ").", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    flags.addString((struct flags*)&flags,"bahDir",____BAH_COMPILER_VAR_917);
char * ____BAH_COMPILER_VAR_918 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("To change the C compiler used, default: ");
long int strLen_1 = strlen(BAH_CC);
long int strLen_2 = strlen(".");
;                            
                        ____BAH_COMPILER_VAR_918 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_918+currStrOff, "To change the C compiler used, default: ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_918+currStrOff, BAH_CC, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_918+currStrOff, ".", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    flags.addString((struct flags*)&flags,"CC",____BAH_COMPILER_VAR_918);
flags.parse((struct flags*)&flags,args);
if ((flags.isSet((struct flags*)&flags,"target")==1)) {
BAH_OS =  flags.get((struct flags*)&flags,"target");
char * ____BAH_COMPILER_VAR_919 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Build target: ");
long int strLen_1 = strlen(BAH_OS);
;                            
                        ____BAH_COMPILER_VAR_919 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_919+currStrOff, "Build target: ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_919+currStrOff, BAH_OS, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    println(____BAH_COMPILER_VAR_919);
}
if ((flags.isSet((struct flags*)&flags,"bahDir")==1)) {
BAH_DIR =  flags.get((struct flags*)&flags,"bahDir");
array(char)* bahDirArr =  strAsArr(BAH_DIR);

                if (bahDirArr->length <= len(bahDirArr)-1) {
                    printf("array (/home/alois/Documents/bah-bah/src/main.bah:73): bahDirArr[%d] with length %d\n", len(bahDirArr)-1, bahDirArr->length);
                    exit(1);
                };
                if ((bahDirArr->data[len(bahDirArr)-1]!=47)) {
char * ____BAH_COMPILER_VAR_920 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen("/");
;                            
                        ____BAH_COMPILER_VAR_920 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_920+currStrOff, BAH_DIR, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_920+currStrOff, "/", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    BAH_DIR =  ____BAH_COMPILER_VAR_920;
}
char * ____BAH_COMPILER_VAR_921 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Bah directory: ");
long int strLen_1 = strlen(BAH_DIR);
;                            
                        ____BAH_COMPILER_VAR_921 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_921+currStrOff, "Bah directory: ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_921+currStrOff, BAH_DIR, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    println(____BAH_COMPILER_VAR_921);
}
if ((flags.isSet((struct flags*)&flags,"CC")==1)) {
BAH_CC =  flags.get((struct flags*)&flags,"CC");
char * ____BAH_COMPILER_VAR_922 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("C compiler: ");
long int strLen_1 = strlen(BAH_CC);
;                            
                        ____BAH_COMPILER_VAR_922 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_922+currStrOff, "C compiler: ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_922+currStrOff, BAH_CC, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    println(____BAH_COMPILER_VAR_922);
}
verboseRuntime =  (flags.isSet((struct flags*)&flags,"verboseRuntime")==1);
debug =  (flags.isSet((struct flags*)&flags,"debug")==1);
if ((debug==true)) {
debugStart();
}
RCPenabled =  ((flags.isSet((struct flags*)&flags,"rcp")==1)||flags.isSet((struct flags*)&flags,"fastrcp"));
if ((flags.isSet((struct flags*)&flags,"v")==1)) {
char * ____BAH_COMPILER_VAR_923 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Bah compiler version: ");
long int strLen_1 = strlen(BAH_VERSION);
long int strLen_2 = strlen(".\n© Alois Laurent Boe");
;                            
                        ____BAH_COMPILER_VAR_923 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_923+currStrOff, "Bah compiler version: ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_923+currStrOff, BAH_VERSION, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_923+currStrOff, ".\n© Alois Laurent Boe", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    println(____BAH_COMPILER_VAR_923);
long int ____BAH_COMPILER_VAR_924 = 0;
return ____BAH_COMPILER_VAR_924;
}
if (((flags.isSet((struct flags*)&flags,"c")==1)&&(flags.isSet((struct flags*)&flags,"l")==1))) {
__BAH_panic("Cannot use -c (to translate to C code) and -l (to compile as a library) at the same time.","/home/alois/Documents/bah-bah/src/main.bah:99");
}
INIT =  rope("");
OUTPUT =  rope("\nvoid __BAH_init();\n#define noCheck(v) v\n#define array(type)	\
struct{	\
type *data; \
long int length; \
long int elemSize; \
}\ntypedef array(char*)* __BAH_ARR_TYPE_cpstring;\nlong int __BAH__main(__BAH_ARR_TYPE_cpstring);\n");
if ((flags.isSet((struct flags*)&flags,"l")==0)) {
if ((RCPenabled==true)) {
OUTPUT =  OUTPUT->add(OUTPUT, rope("\n\n        void RCP_init();\n        void RCP_shutdown();\n        void free(void*);\n        \n        int main(int argc, char ** argv) {\n        RCP_init();\n        array(char*) * args = malloc(sizeof(array(char*)));\n        args->data = malloc(sizeof(char*)*argc);\n        memcpy(args->data, argv, sizeof(char*)*argc);\n        args->elemSize = sizeof(char*);\n        args->length = argc;\n        __BAH_init();\n        long int r =  __BAH__main((__BAH_ARR_TYPE_cpstring)args);\n        free(args->data);\n        free(args);\n        RCP_shutdown();\n        return r;\n        };\n        #define main(v) __BAH__main(v)\n        "));
}
else {
OUTPUT =  OUTPUT->add(OUTPUT, rope("\n        #include <gc.h>\n        int main(int argc, char ** argv) {\n        GC_INIT();\n        array(char*) * args = GC_MALLOC(sizeof(array(char*)));\n        args->data = GC_MALLOC(sizeof(char*)*argc);\n        memcpy(args->data, argv, sizeof(char*)*argc);\n        args->elemSize = sizeof(char*);\n        args->length = argc;\n        __BAH_init();\n        long int r =  __BAH__main((__BAH_ARR_TYPE_cpstring)args);\n        GC_FREE(args->data);\n        GC_FREE(args);\n        return r;\n        };\n        #define main(v) __BAH__main(v)\n        "));
}
}
struct compilerStateTag ____BAH_COMPILER_VAR_925 = {};
____BAH_COMPILER_VAR_925.includes = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_925.includes->length = 0;
            ____BAH_COMPILER_VAR_925.includes->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_925.cIncludes = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_925.cIncludes->length = 0;
            ____BAH_COMPILER_VAR_925.cIncludes->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_925.cLibs = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_925.cLibs->length = 0;
            ____BAH_COMPILER_VAR_925.cLibs->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_925.currentFile= null;
____BAH_COMPILER_VAR_925.currentDir = "./";
____BAH_COMPILER_VAR_925.isBranch = false;
____BAH_COMPILER_VAR_925.isFor = false;
____BAH_COMPILER_VAR_925.arrTypesDecl = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_925.arrTypesDecl->length = 0;
            ____BAH_COMPILER_VAR_925.arrTypesDecl->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_925.haveEntryPoint = false;
____BAH_COMPILER_VAR_925.RCPvars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_925.RCPvars->length = 0;
            ____BAH_COMPILER_VAR_925.RCPvars->elemSize = sizeof(struct variable*);
            compilerState =  ____BAH_COMPILER_VAR_925;

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
struct fileMap ____BAH_COMPILER_VAR_926 = {};
____BAH_COMPILER_VAR_926.handle = -1;
____BAH_COMPILER_VAR_926.p= null;
____BAH_COMPILER_VAR_926.open = fileMap__open;
____BAH_COMPILER_VAR_926.isValid = fileMap__isValid;
____BAH_COMPILER_VAR_926.close = fileMap__close;
struct fileMap fm =  ____BAH_COMPILER_VAR_926;
char * f =  fm.open((struct fileMap*)&fm,fileName);
if ((fm.isValid((struct fileMap*)&fm)==0)) {
char * ____BAH_COMPILER_VAR_927 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Could not open file '");
long int strLen_1 = strlen(fileName);
long int strLen_2 = strlen("'.");
;                            
                        ____BAH_COMPILER_VAR_927 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_927+currStrOff, "Could not open file '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_927+currStrOff, fileName, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_927+currStrOff, "'.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    __BAH_panic(____BAH_COMPILER_VAR_927,"/home/alois/Documents/bah-bah/src/main.bah:175");
}
long int startTime =  getTimeUnix();
array(struct Tok)* tokens =  lexer(f);
fm.close((struct fileMap*)&fm);
if ((len(tokens)==0)) {
char * ____BAH_COMPILER_VAR_928 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("File '");
long int strLen_1 = strlen(fileName);
long int strLen_2 = strlen("' not recognized.");
;                            
                        ____BAH_COMPILER_VAR_928 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_928+currStrOff, "File '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_928+currStrOff, fileName, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_928+currStrOff, "' not recognized.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    __BAH_panic(____BAH_COMPILER_VAR_928,"/home/alois/Documents/bah-bah/src/main.bah:183");
}
struct Elems* ____BAH_COMPILER_VAR_929 = memoryAlloc(sizeof(struct Elems));
____BAH_COMPILER_VAR_929->vars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_929->vars->length = 0;
            ____BAH_COMPILER_VAR_929->vars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_929->structs = memoryAlloc(sizeof(array(struct cStruct*)));
            ____BAH_COMPILER_VAR_929->structs->length = 0;
            ____BAH_COMPILER_VAR_929->structs->elemSize = sizeof(struct cStruct*);
            ____BAH_COMPILER_VAR_929->types = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_929->types->length = 0;
            ____BAH_COMPILER_VAR_929->types->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_929->fns = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_929->fns->length = 0;
            ____BAH_COMPILER_VAR_929->fns->elemSize = sizeof(struct func*);
            struct Elems* elems =  ____BAH_COMPILER_VAR_929;
if ((includeFile("builtin.bah",elems)==false)) {
char * ____BAH_COMPILER_VAR_930 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Could not find std-libs, please check '");
long int strLen_1 = strlen(BAH_DIR);
long int strLen_2 = strlen("'");
;                            
                        ____BAH_COMPILER_VAR_930 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_930+currStrOff, "Could not find std-libs, please check '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_930+currStrOff, BAH_DIR, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_930+currStrOff, "'", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    __BAH_panic(____BAH_COMPILER_VAR_930,"/home/alois/Documents/bah-bah/src/main.bah:188");
}
if ((flags.isSet((struct flags*)&flags,"l")==1)) {
OUTPUT =  rope("");
declareAll(elems);
}
compilerState.currentDir =  getDirFromFile(fileName);
parseLines(tokens,elems);
makeInit();
if ((debug==false)) {
long int totalTime =  getTimeUnix() - startTime;
char * ____BAH_COMPILER_VAR_931 =intToStr(totalLines);char * ____BAH_COMPILER_VAR_932 =intToStr(totalTime / 1000000);char * ____BAH_COMPILER_VAR_933 =intToStr(totalLexerTime / 1000000);char * ____BAH_COMPILER_VAR_934 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Parsed. (");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_931);
long int strLen_2 = strlen(" lines, total time: ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_932);
long int strLen_4 = strlen("ms, lexer time: ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_933);
long int strLen_6 = strlen("ms)\e[0m");
;                            
                        ____BAH_COMPILER_VAR_934 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                        
                        strncpy(____BAH_COMPILER_VAR_934+currStrOff, "Parsed. (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_934+currStrOff, ____BAH_COMPILER_VAR_931, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_934+currStrOff, " lines, total time: ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_934+currStrOff, ____BAH_COMPILER_VAR_932, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_934+currStrOff, "ms, lexer time: ", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_934+currStrOff, ____BAH_COMPILER_VAR_933, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_934+currStrOff, "ms)\e[0m", strLen_6);
                        currStrOff += strLen_6;
                        
                    }
                    println(____BAH_COMPILER_VAR_934);
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
if (((flags.isSet((struct flags*)&flags,"d")==1)||(__checkString(BAH_OS, "/home/alois/Documents/bah-bah/src/main.bah:215 BAH_OS ")==1&&strcmp(BAH_OS, "darwin") == 0))) {
isStatic =  "";
}
if ((flags.isSet((struct flags*)&flags,"c")==0)) {
char * randFileName =  "TMP_C_FILE_";
long int i =  0;
while ((i<9)) {
long int nb =  randomInRange(0,99);
char * s =  intToStr(nb);
char * ____BAH_COMPILER_VAR_935 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(randFileName);
long int strLen_1 = strlen(s);
;                            
                        ____BAH_COMPILER_VAR_935 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_935+currStrOff, randFileName, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_935+currStrOff, s, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    randFileName =  ____BAH_COMPILER_VAR_935;
i =  i + 1;
};
char * ____BAH_COMPILER_VAR_936 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(randFileName);
long int strLen_1 = strlen(".c");
;                            
                        ____BAH_COMPILER_VAR_936 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_936+currStrOff, randFileName, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_936+currStrOff, ".c", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    randFileName =  ____BAH_COMPILER_VAR_936;
struct fileStream ____BAH_COMPILER_VAR_937 = {};
____BAH_COMPILER_VAR_937.handle= null;
____BAH_COMPILER_VAR_937.isValid = fileStream__isValid;
____BAH_COMPILER_VAR_937.open = fileStream__open;
____BAH_COMPILER_VAR_937.close = fileStream__close;
____BAH_COMPILER_VAR_937.getPos = fileStream__getPos;
____BAH_COMPILER_VAR_937.setPos = fileStream__setPos;
____BAH_COMPILER_VAR_937.getSize = fileStream__getSize;
____BAH_COMPILER_VAR_937.rewind = fileStream__rewind;
____BAH_COMPILER_VAR_937.getChar = fileStream__getChar;
____BAH_COMPILER_VAR_937.setChar = fileStream__setChar;
____BAH_COMPILER_VAR_937.createFile = fileStream__createFile;
____BAH_COMPILER_VAR_937.writeFile = fileStream__writeFile;
____BAH_COMPILER_VAR_937.writePtr = fileStream__writePtr;
____BAH_COMPILER_VAR_937.readPtr = fileStream__readPtr;
____BAH_COMPILER_VAR_937.readContent = fileStream__readContent;
____BAH_COMPILER_VAR_937.readBytes = fileStream__readBytes;
____BAH_COMPILER_VAR_937.writeBytes = fileStream__writeBytes;
struct fileStream fs =  ____BAH_COMPILER_VAR_937;
fs.open((struct fileStream*)&fs,randFileName,"w");
char * ____BAH_COMPILER_VAR_938 =OUTPUT->toStr((struct rope*)OUTPUT);fs.writeFile((struct fileStream*)&fs,____BAH_COMPILER_VAR_938);
fs.close((struct fileStream*)&fs);
char * ____BAH_COMPILER_VAR_939 =null;
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
long int strLen_13 = strlen(" -w -O1 -o ");
long int strLen_14 = strlen(fileName);
;                            
                        ____BAH_COMPILER_VAR_939 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14);
                        
                        strncpy(____BAH_COMPILER_VAR_939+currStrOff, BAH_CC, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_939+currStrOff, " -I \"", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_939+currStrOff, BAH_DIR, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_939+currStrOff, "libs/", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_939+currStrOff, BAH_OS, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_939+currStrOff, "/include/\" -L \"", strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_939+currStrOff, BAH_DIR, strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_939+currStrOff, "libs/", strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_939+currStrOff, BAH_OS, strLen_8);
                        currStrOff += strLen_8;
                        
                        strncpy(____BAH_COMPILER_VAR_939+currStrOff, "/\" ", strLen_9);
                        currStrOff += strLen_9;
                        
                        strncpy(____BAH_COMPILER_VAR_939+currStrOff, randFileName, strLen_10);
                        currStrOff += strLen_10;
                        
                        strncpy(____BAH_COMPILER_VAR_939+currStrOff, " ", strLen_11);
                        currStrOff += strLen_11;
                        
                        strncpy(____BAH_COMPILER_VAR_939+currStrOff, isStatic, strLen_12);
                        currStrOff += strLen_12;
                        
                        strncpy(____BAH_COMPILER_VAR_939+currStrOff, " -w -O1 -o ", strLen_13);
                        currStrOff += strLen_13;
                        
                        strncpy(____BAH_COMPILER_VAR_939+currStrOff, fileName, strLen_14);
                        currStrOff += strLen_14;
                        
                    }
                    char * gccArgs =  ____BAH_COMPILER_VAR_939;
if ((flags.isSet((struct flags*)&flags,"l")==1)) {
char * ____BAH_COMPILER_VAR_940 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(gccArgs);
long int strLen_1 = strlen(" -c");
;                            
                        ____BAH_COMPILER_VAR_940 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_940+currStrOff, gccArgs, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_940+currStrOff, " -c", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    gccArgs =  ____BAH_COMPILER_VAR_940;
}
array(char *)* cLibs =  compilerState.cLibs;
i =  0;
while ((i<len(cLibs))) {

                if (cLibs->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/main.bah:243): cLibs[%d] with length %d\n", i, cLibs->length);
                    exit(1);
                };
                char * l =  cLibs->data[i];
char * ____BAH_COMPILER_VAR_941 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(gccArgs);
long int strLen_1 = strlen(" -");
long int strLen_2 = strlen(l);
;                            
                        ____BAH_COMPILER_VAR_941 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_941+currStrOff, gccArgs, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_941+currStrOff, " -", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_941+currStrOff, l, strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    gccArgs =  ____BAH_COMPILER_VAR_941;
i =  i + 1;
};
struct command cmd =  command(gccArgs);
if ((flags.isSet((struct flags*)&flags,"verboseCC")==1)) {
char * ____BAH_COMPILER_VAR_942 =cmd.run((struct command*)&cmd);println(____BAH_COMPILER_VAR_942);
}
else {
cmd.run((struct command*)&cmd);
}
removeFile(randFileName);
if ((cmd.status!=0)) {
println("\e[1;31m[GCC-ERROR]\e[0m\nCould not compiled.");
exit(1);
}
if ((flags.isSet((struct flags*)&flags,"l")==1)) {
char * ____BAH_COMPILER_VAR_943 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("ar rcs ");
long int strLen_1 = strlen(fileName);
long int strLen_2 = strlen(".a ");
long int strLen_3 = strlen(fileName);
;                            
                        ____BAH_COMPILER_VAR_943 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                        
                        strncpy(____BAH_COMPILER_VAR_943+currStrOff, "ar rcs ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_943+currStrOff, fileName, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_943+currStrOff, ".a ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_943+currStrOff, fileName, strLen_3);
                        currStrOff += strLen_3;
                        
                    }
                    cmd =  command(____BAH_COMPILER_VAR_943);
cmd.run((struct command*)&cmd);
}
}
else {
if ((flags.isSet((struct flags*)&flags,"o")==0)) {
char * ____BAH_COMPILER_VAR_944 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(fileName);
long int strLen_1 = strlen(".c");
;                            
                        ____BAH_COMPILER_VAR_944 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_944+currStrOff, fileName, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_944+currStrOff, ".c", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    fileName =  ____BAH_COMPILER_VAR_944;
}
char * ____BAH_COMPILER_VAR_945 =null;
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
                        ____BAH_COMPILER_VAR_945 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13);
                        
                        strncpy(____BAH_COMPILER_VAR_945+currStrOff, BAH_CC, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_945+currStrOff, " -I \"", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_945+currStrOff, BAH_DIR, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_945+currStrOff, "libs/", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_945+currStrOff, BAH_OS, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_945+currStrOff, "/include/\" -L \"", strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_945+currStrOff, BAH_DIR, strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_945+currStrOff, "libs/", strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_945+currStrOff, BAH_OS, strLen_8);
                        currStrOff += strLen_8;
                        
                        strncpy(____BAH_COMPILER_VAR_945+currStrOff, "/\" ", strLen_9);
                        currStrOff += strLen_9;
                        
                        strncpy(____BAH_COMPILER_VAR_945+currStrOff, fileName, strLen_10);
                        currStrOff += strLen_10;
                        
                        strncpy(____BAH_COMPILER_VAR_945+currStrOff, " ", strLen_11);
                        currStrOff += strLen_11;
                        
                        strncpy(____BAH_COMPILER_VAR_945+currStrOff, isStatic, strLen_12);
                        currStrOff += strLen_12;
                        
                        strncpy(____BAH_COMPILER_VAR_945+currStrOff, " -O1 -w ", strLen_13);
                        currStrOff += strLen_13;
                        
                    }
                    char * gccArgs =  ____BAH_COMPILER_VAR_945;
array(char *)* cLibs =  compilerState.cLibs;
long int i =  0;
while ((i<len(cLibs))) {

                if (cLibs->length <= i) {
                    printf("array (/home/alois/Documents/bah-bah/src/main.bah:278): cLibs[%d] with length %d\n", i, cLibs->length);
                    exit(1);
                };
                char * l =  cLibs->data[i];
char * ____BAH_COMPILER_VAR_946 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(gccArgs);
long int strLen_1 = strlen(" -");
long int strLen_2 = strlen(l);
;                            
                        ____BAH_COMPILER_VAR_946 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_946+currStrOff, gccArgs, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_946+currStrOff, " -", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_946+currStrOff, l, strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    gccArgs =  ____BAH_COMPILER_VAR_946;
i =  i + 1;
};
char * ____BAH_COMPILER_VAR_947 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("//COMPILE WITH: '");
long int strLen_1 = strlen(gccArgs);
long int strLen_2 = strlen("'\n");
;                            
                        ____BAH_COMPILER_VAR_947 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_947+currStrOff, "//COMPILE WITH: '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_947+currStrOff, gccArgs, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_947+currStrOff, "'\n", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    struct rope* ____BAH_COMPILER_VAR_948 =rope(____BAH_COMPILER_VAR_947);OUTPUT =  concatenateRopes(____BAH_COMPILER_VAR_948,OUTPUT);
struct fileStream ____BAH_COMPILER_VAR_949 = {};
____BAH_COMPILER_VAR_949.handle= null;
____BAH_COMPILER_VAR_949.isValid = fileStream__isValid;
____BAH_COMPILER_VAR_949.open = fileStream__open;
____BAH_COMPILER_VAR_949.close = fileStream__close;
____BAH_COMPILER_VAR_949.getPos = fileStream__getPos;
____BAH_COMPILER_VAR_949.setPos = fileStream__setPos;
____BAH_COMPILER_VAR_949.getSize = fileStream__getSize;
____BAH_COMPILER_VAR_949.rewind = fileStream__rewind;
____BAH_COMPILER_VAR_949.getChar = fileStream__getChar;
____BAH_COMPILER_VAR_949.setChar = fileStream__setChar;
____BAH_COMPILER_VAR_949.createFile = fileStream__createFile;
____BAH_COMPILER_VAR_949.writeFile = fileStream__writeFile;
____BAH_COMPILER_VAR_949.writePtr = fileStream__writePtr;
____BAH_COMPILER_VAR_949.readPtr = fileStream__readPtr;
____BAH_COMPILER_VAR_949.readContent = fileStream__readContent;
____BAH_COMPILER_VAR_949.readBytes = fileStream__readBytes;
____BAH_COMPILER_VAR_949.writeBytes = fileStream__writeBytes;
struct fileStream fs =  ____BAH_COMPILER_VAR_949;
fs.open((struct fileStream*)&fs,fileName,"w");
char * ____BAH_COMPILER_VAR_950 =OUTPUT->toStr((struct rope*)OUTPUT);fs.writeFile((struct fileStream*)&fs,____BAH_COMPILER_VAR_950);
fs.close((struct fileStream*)&fs);
}
if ((debug==false)) {
long int totalTime =  getTimeUnix() - startTime;
char * ____BAH_COMPILER_VAR_951 =intToStr(totalTime / 1000000);char * ____BAH_COMPILER_VAR_952 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\e[1;32mDone. (compiled in ");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_951);
long int strLen_2 = strlen("ms)\e[0m");
;                            
                        ____BAH_COMPILER_VAR_952 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_952+currStrOff, "\e[1;32mDone. (compiled in ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_952+currStrOff, ____BAH_COMPILER_VAR_951, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_952+currStrOff, "ms)\e[0m", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    println(____BAH_COMPILER_VAR_952);
}
else {
debugEnd();
}
long int ____BAH_COMPILER_VAR_953 = 0;
return ____BAH_COMPILER_VAR_953;
};

    void __BAH_init() {

        __BAH_panic_chan =  null;
RAND_SEEDED =  0;
BAH_DIR =  "C:/Bah/";
BAH_OS =  "windows";
BAH_CC =  "gcc";
debug =  false;
verboseRuntime =  false;
NEXT_LINE =  "";
threadCount =  0;
currentFn =  null;
totalLines =  0;
totalLexerTime =  0;
RCPenabled =  false;
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

keywords->length = 19;
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
    