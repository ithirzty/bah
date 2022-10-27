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
            
#line 1 "/opt/bah/builtin.bah"
#include <signal.h>

#line 2 "/opt/bah/builtin.bah"
#include <string.h>

#line 4 "/opt/bah/builtin.bah"

#line 9 "/opt/bah/builtin.bah"

#line 13 "/opt/bah/builtin.bah"
void __BAH_panic(char * e,char * l);

#line 15 "/opt/bah/builtin.bah"
char * __Bah_safe_string(char * s);

#line 17 "/opt/bah/builtin.bah"
#define null (void *)0

#line 19 "/opt/bah/builtin.bah"
#define true (char)1

#line 20 "/opt/bah/builtin.bah"
#define false (char)0

#line 22 "/opt/bah/builtin.bah"

#line 23 "/opt/bah/builtin.bah"

#line 24 "/opt/bah/builtin.bah"

#line 25 "/opt/bah/builtin.bah"

#line 29 "/opt/bah/builtin.bah"
long int __bah_strcmp(char * a,char * b){

#line 30 "/opt/bah/builtin.bah"
long int ai = (long int)a;

#line 31 "/opt/bah/builtin.bah"
long int bi = (long int)b;

#line 32 "/opt/bah/builtin.bah"
if ((ai*bi==0)) {

#line 33 "/opt/bah/builtin.bah"
return 1;
}

#line 35 "/opt/bah/builtin.bah"
return strcmp(a,b);
};

#line 38 "/opt/bah/builtin.bah"
#define strcmp __bah_strcmp

#line 42 "/opt/bah/builtin.bah"
long int __bah_strlen(char * s){

#line 43 "/opt/bah/builtin.bah"
if (((void *)s==null)) {

#line 44 "/opt/bah/builtin.bah"
return 0;
}

#line 46 "/opt/bah/builtin.bah"
return strlen(s);
};

#line 49 "/opt/bah/builtin.bah"
#define strlen __bah_strlen

#line 51 "/opt/bah/builtin.bah"
#include <stdio.h>

#line 52 "/opt/bah/builtin.bah"
#include <unistd.h>

#line 53 "/opt/bah/builtin.bah"
#include <sys/types.h>

#line 54 "/opt/bah/builtin.bah"
#include <sys/stat.h>

#line 55 "/opt/bah/builtin.bah"
#include <fcntl.h>

#line 57 "/opt/bah/builtin.bah"

#line 58 "/opt/bah/builtin.bah"

#line 61 "/opt/bah/builtin.bah"
void print(char * s){

#line 62 "/opt/bah/builtin.bah"
write((void *)1,s,strlen(s));
};

#line 65 "/opt/bah/builtin.bah"

#line 66 "/opt/bah/builtin.bah"
void __BAH_memcpy(char * dest,char * source,long int l);

#line 67 "/opt/bah/builtin.bah"
#define memcpy __BAH_memcpy

#line 70 "/opt/bah/builtin.bah"

#line 75 "/opt/bah/builtin.bah"

#line 1 "/opt/bah/memory.bah"

#line 2 "/opt/bah/memory.bah"
#include <sys/mman.h>

#line 5 "/opt/bah/memory.bah"

#line 9 "/opt/bah/memory.bah"

#line 17 "/opt/bah/memory.bah"

#line 20 "/opt/bah/memory.bah"
#define SIZE_OF_INT 8

#line 21 "/opt/bah/memory.bah"
#define SIZE_OF_CHAR 1

#line 22 "/opt/bah/memory.bah"
#define SIZE_OF_INT32 4

#line 23 "/opt/bah/memory.bah"
#define SIZE_OF_FLOAT32 4

#line 24 "/opt/bah/memory.bah"
#define SIZE_OF_FLOAT 8

#line 29 "/opt/bah/memory.bah"
long int len(void * a){

#line 30 "/opt/bah/memory.bah"
if ((a==null)) {

#line 31 "/opt/bah/memory.bah"
return 0;
}

#line 33 "/opt/bah/memory.bah"
array(void*)*arr=a;

#line 34 "/opt/bah/memory.bah"
return arr->length;
};

#line 37 "/opt/bah/memory.bah"

#line 39 "/opt/bah/memory.bah"

#line 41 "/opt/bah/memory.bah"

#line 2 "/opt/bah/gc.bah"

#line 3 "/opt/bah/gc.bah"
#include <gc.h>

#line 4 "/opt/bah/gc.bah"

#line 7 "/opt/bah/gc.bah"

#line 12 "/opt/bah/gc.bah"

#line 17 "/opt/bah/gc.bah"

#line 18 "/opt/bah/gc.bah"

#line 19 "/opt/bah/gc.bah"

#line 20 "/opt/bah/gc.bah"

#line 21 "/opt/bah/gc.bah"

#line 28 "/opt/bah/gc.bah"
void * memoryAlloc(long int s){

#line 29 "/opt/bah/gc.bah"
return GC_MALLOC(s);
};

#line 33 "/opt/bah/gc.bah"
void destroy(void * a){

#line 34 "/opt/bah/gc.bah"
GC_FREE(a);
};

#line 38 "/opt/bah/gc.bah"
void clear(void * a){

#line 39 "/opt/bah/gc.bah"
array(void*)*arr=a;

#line 40 "/opt/bah/gc.bah"
memset(arr->data,null,arr->realLength*arr->elemSize);

#line 41 "/opt/bah/gc.bah"
arr->length=0;
};

#line 46 "/opt/bah/gc.bah"
void * memoryRealloc(void * p,long int s){

#line 47 "/opt/bah/gc.bah"
return GC_REALLOC(p,s);
};

#line 51 "/opt/bah/gc.bah"
void cleanShutDown(){

#line 52 "/opt/bah/gc.bah"
exit(1);

#line 53 "/opt/bah/gc.bah"
return;
};

#line 57 "/opt/bah/gc.bah"
void memoryOnEnd(void * obj,void * fn){

#line 58 "/opt/bah/gc.bah"
GC_REGISTER_FINALIZER_IGNORE_SELF(obj,fn,null,null,null);
};

#line 65 "/opt/bah/gc.bah"
void __BAH_memcpy(char * dest,char * source,long int l){

#line 66 "/opt/bah/gc.bah"
register long int lm = l%sizeof(long int);

#line 67 "/opt/bah/gc.bah"
if ((lm!=0)) {

#line 68 "/opt/bah/gc.bah"
for (; (lm!=0); 
#line 68 "/opt/bah/gc.bah"
--lm) {

#line 69 "/opt/bah/gc.bah"
long int i = l-lm;

#line 70 "/opt/bah/gc.bah"
dest[i]=source[i];
};
}

#line 73 "/opt/bah/gc.bah"
long int* destI = (void *)((long int)dest-sizeof(long int));

#line 74 "/opt/bah/gc.bah"
long int* sourceI = (void *)((long int)source-sizeof(long int));

#line 75 "/opt/bah/gc.bah"
register long int i = l/sizeof(long int);

#line 75 "/opt/bah/gc.bah"
for (; (i!=0); 
#line 75 "/opt/bah/gc.bah"
--i) {

#line 76 "/opt/bah/gc.bah"
destI[i]=sourceI[i];
};
};

#line 45 "/opt/bah/memory.bah"
void append(void * a,void * b){

#line 46 "/opt/bah/memory.bah"
array(void*)*arrA=a;

#line 47 "/opt/bah/memory.bah"
array(void*)*arrB=b;

#line 48 "/opt/bah/memory.bah"
long int lenA = 0;

#line 49 "/opt/bah/memory.bah"
long int lenB = 0;

#line 50 "/opt/bah/memory.bah"
long int realSizeA = 0;

#line 51 "/opt/bah/memory.bah"
long int realSizeB = 0;

#line 52 "/opt/bah/memory.bah"
lenA=len(arrA);

#line 53 "/opt/bah/memory.bah"
lenB=len(arrB);

#line 55 "/opt/bah/memory.bah"
if ((lenB==0)) {

#line 56 "/opt/bah/memory.bah"
return;
}

#line 59 "/opt/bah/memory.bah"
if ((lenA==0)) {

#line 60 "/opt/bah/memory.bah"
arrA->data=arrB->data;

#line 61 "/opt/bah/memory.bah"
arrA->length=arrB->length;

#line 62 "/opt/bah/memory.bah"
return;
}

#line 65 "/opt/bah/memory.bah"
realSizeA=lenA*arrA->elemSize;

#line 66 "/opt/bah/memory.bah"
realSizeB=lenB*arrB->elemSize;

#line 69 "/opt/bah/memory.bah"
void * buff = memoryAlloc(realSizeA+realSizeB+32);

#line 70 "/opt/bah/memory.bah"
memcpy(buff,arrA->data,realSizeA);

#line 71 "/opt/bah/memory.bah"
memcpy(buff+lenA,arrB->data,realSizeB);

#line 72 "/opt/bah/memory.bah"
arrA->length=lenA+lenB;

#line 73 "/opt/bah/memory.bah"
arrA->data=buff;
};

#line 77 "/opt/bah/memory.bah"
void copy(void * a,void * b){

#line 78 "/opt/bah/memory.bah"
array(void*)*arrA=a;

#line 79 "/opt/bah/memory.bah"
array(void*)*arrB=b;

#line 80 "/opt/bah/memory.bah"
long int lenB = 0;

#line 81 "/opt/bah/memory.bah"
long int realSizeB = 0;

#line 82 "/opt/bah/memory.bah"
lenB=len(arrB);

#line 83 "/opt/bah/memory.bah"
realSizeB=lenB*arrB->elemSize;

#line 84 "/opt/bah/memory.bah"
arrA->data=memoryAlloc(realSizeB);

#line 85 "/opt/bah/memory.bah"
memcpy(arrA->data,arrB->data,realSizeB);

#line 86 "/opt/bah/memory.bah"
arrA->length=arrB->length;
};

#line 89 "/opt/bah/memory.bah"

#line 103 "/opt/bah/memory.bah"

#line 104 "/opt/bah/memory.bah"

#line 105 "/opt/bah/memory.bah"
#define PROT_READ 1

#line 106 "/opt/bah/memory.bah"
#define PROT_WRITE 2

#line 107 "/opt/bah/memory.bah"
#define PROT_READWRITE 3

#line 108 "/opt/bah/memory.bah"
#define MAP_SHARED 1

#line 109 "/opt/bah/memory.bah"
#define MAP_ANONYMOUS 32

#line 112 "/opt/bah/memory.bah"

#line 126 "/opt/bah/memory.bah"
void * sharedMemory(long int size){

#line 127 "/opt/bah/memory.bah"
if ((size==0)) {

#line 128 "/opt/bah/memory.bah"
size = 4096;
}

#line 130 "/opt/bah/memory.bah"

#line 131 "/opt/bah/memory.bah"
void * r = mmap(0,size,PROT_READ+PROT_WRITE,MAP_SHARED+MAP_ANONYMOUS,-1,0);

#line 133 "/opt/bah/memory.bah"

#line 136 "/opt/bah/memory.bah"

#line 146 "/opt/bah/memory.bah"
return r;
};

#line 149 "/opt/bah/memory.bah"

#line 159 "/opt/bah/memory.bah"
void allocateArray(void * arr,long int nbElems){

#line 160 "/opt/bah/memory.bah"
array(void*)*a=arr;

#line 161 "/opt/bah/memory.bah"
a->length=nbElems;

#line 162 "/opt/bah/memory.bah"
a->realLength=nbElems;

#line 163 "/opt/bah/memory.bah"
a->data=memoryAlloc(nbElems*a->elemSize);
};

#line 175 "/opt/bah/memory.bah"

#line 177 "/opt/bah/memory.bah"
typedef array(char)* __BAH_ARR_TYPE_char;
__BAH_ARR_TYPE_char ser(void * a);

#line 181 "/opt/bah/memory.bah"
__BAH_ARR_TYPE_char __serialize(void * a,long int s){

#line 182 "/opt/bah/memory.bah"
char * r = memoryAlloc(s+9);

#line 183 "/opt/bah/memory.bah"
memcpy(r,&s,8);

#line 184 "/opt/bah/memory.bah"
memcpy(r+8,a,s);

#line 185 "/opt/bah/memory.bah"
long int l = s+1;

#line 186 "/opt/bah/memory.bah"
array(char)* arr = memoryAlloc(sizeof(array(char)));

arr->length = 0;
arr->elemSize = sizeof(char);

#line 187 "/opt/bah/memory.bah"
arr->length=s+8;

#line 188 "/opt/bah/memory.bah"
arr->elemSize=1;

#line 189 "/opt/bah/memory.bah"
arr->data=r;

#line 190 "/opt/bah/memory.bah"
return arr;
};

#line 195 "/opt/bah/memory.bah"
long int serlen(__BAH_ARR_TYPE_char data){

#line 196 "/opt/bah/memory.bah"
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

#line 197 "/opt/bah/memory.bah"
return *sarr->data;
};

#line 202 "/opt/bah/memory.bah"
void * unser(__BAH_ARR_TYPE_char data){

#line 203 "/opt/bah/memory.bah"
long int sptr = serlen(data);

#line 204 "/opt/bah/memory.bah"
void * r = memoryAlloc(sptr);

#line 205 "/opt/bah/memory.bah"
memcpy(r,data->data+8,sptr);

#line 206 "/opt/bah/memory.bah"
return r;
};

#line 209 "/opt/bah/memory.bah"

#line 210 "/opt/bah/memory.bah"

#line 214 "/opt/bah/memory.bah"
char * memoryAllocSTR(long int s){

#line 215 "/opt/bah/memory.bah"
char * r = memoryAlloc(s);

#line 216 "/opt/bah/memory.bah"
r[s-1]=0;

#line 218 "/opt/bah/memory.bah"
return r;
};

#line 224 "/opt/bah/memory.bah"
void delete(void * a,long int i){

#line 225 "/opt/bah/memory.bah"
array(void *)* arr = (array(void *)*)a;

#line 226 "/opt/bah/memory.bah"
long int length = len(arr);

#line 227 "/opt/bah/memory.bah"
if ((i>=length)||(i<0)) {

#line 228 "/opt/bah/memory.bah"
return;
}

#line 230 "/opt/bah/memory.bah"
if ((length==1)) {

#line 231 "/opt/bah/memory.bah"
arr->length=0;

#line 232 "/opt/bah/memory.bah"
return;
}

#line 234 "/opt/bah/memory.bah"
long int elemSize = arr->elemSize;

#line 235 "/opt/bah/memory.bah"
char* data = arr->data;

#line 236 "/opt/bah/memory.bah"
void * destOffset = elemSize*i;

#line 237 "/opt/bah/memory.bah"
++i;

#line 238 "/opt/bah/memory.bah"
void * offset = elemSize*i;

#line 239 "/opt/bah/memory.bah"
char* src = (long int)data+(long int)offset;

#line 240 "/opt/bah/memory.bah"
char* dest = (long int)data+(long int)destOffset;

#line 241 "/opt/bah/memory.bah"
long int rightNB = length-(i-1);

#line 242 "/opt/bah/memory.bah"
memmove(dest,src,rightNB*elemSize);

#line 243 "/opt/bah/memory.bah"
arr->length=length-1;
};

#line 248 "/opt/bah/memory.bah"
void deleteRange(void * a,long int from,long int to){

#line 249 "/opt/bah/memory.bah"
if ((from==to)) {

#line 250 "/opt/bah/memory.bah"
delete(a,from);

#line 251 "/opt/bah/memory.bah"
return;
}

#line 254 "/opt/bah/memory.bah"
array(void *)* arr = (array(void *)*)a;

#line 255 "/opt/bah/memory.bah"
long int length = len(arr);

#line 257 "/opt/bah/memory.bah"
long int elemSize = arr->elemSize;

#line 258 "/opt/bah/memory.bah"
char* data = arr->data;

#line 259 "/opt/bah/memory.bah"
long int size = elemSize*(to-from);

#line 260 "/opt/bah/memory.bah"
void * dest = (long int)data+elemSize*from;

#line 261 "/opt/bah/memory.bah"
void * src = (long int)dest+size+elemSize;

#line 262 "/opt/bah/memory.bah"
long int rightNB = length-to;

#line 263 "/opt/bah/memory.bah"
memmove(dest,src,rightNB*elemSize);

#line 264 "/opt/bah/memory.bah"
arr->length=length-(to-from+1);
};

#line 269 "/opt/bah/memory.bah"
char * arrToStr(__BAH_ARR_TYPE_char arr){

#line 270 "/opt/bah/memory.bah"
long int strLen = len(arr);

#line 271 "/opt/bah/memory.bah"
char * str = memoryAllocSTR(strLen+1);

#line 272 "/opt/bah/memory.bah"
memcpy(str,arr->data,strLen);

#line 273 "/opt/bah/memory.bah"
return str;
};

#line 277 "/opt/bah/memory.bah"
__BAH_ARR_TYPE_char strToArr(char * str){

#line 278 "/opt/bah/memory.bah"
long int strLen = strlen(str);

#line 279 "/opt/bah/memory.bah"
array(char)* arr = memoryAlloc(sizeof(array(char)));

arr->length = 0;
arr->elemSize = sizeof(char);

#line 280 "/opt/bah/memory.bah"
arr->data=memoryAlloc(strLen+1);

#line 281 "/opt/bah/memory.bah"
memcpy(arr->data,str,strLen);

#line 282 "/opt/bah/memory.bah"
arr->length=strLen;

#line 284 "/opt/bah/memory.bah"
return arr;
};

#line 291 "/opt/bah/memory.bah"
char * arrAsStr(__BAH_ARR_TYPE_char arr){

#line 292 "/opt/bah/memory.bah"

#line 295 "/opt/bah/memory.bah"
return arr->data;
};

#line 302 "/opt/bah/memory.bah"
__BAH_ARR_TYPE_char strAsArr(char * str){

#line 303 "/opt/bah/memory.bah"

#line 306 "/opt/bah/memory.bah"
long int l = strlen(str);

#line 307 "/opt/bah/memory.bah"
array(char)* arr = memoryAlloc(sizeof(array(char)));

arr->length = 0;
arr->elemSize = sizeof(char);

#line 308 "/opt/bah/memory.bah"
arr->length=l;

#line 309 "/opt/bah/memory.bah"
arr->data=str;

#line 310 "/opt/bah/memory.bah"
return arr;
};

#line 315 "/opt/bah/memory.bah"
void strTrimLeft(char ** s,long int i){

#line 316 "/opt/bah/memory.bah"
long int ls = strlen(*s);

#line 317 "/opt/bah/memory.bah"
char * ns = memoryAlloc(ls-i+1);

#line 318 "/opt/bah/memory.bah"
memcpy(ns,*s+i,ls-i);

#line 319 "/opt/bah/memory.bah"
*s = ns;
};

#line 323 "/opt/bah/memory.bah"
void strTrimRight(char ** s,long int i){

#line 324 "/opt/bah/memory.bah"
long int ls = strlen(*s);

#line 325 "/opt/bah/memory.bah"
char * ns = memoryAlloc(ls-i+1);

#line 326 "/opt/bah/memory.bah"
memcpy(ns,*s,ls-i);

#line 327 "/opt/bah/memory.bah"
*s = ns;
};

#line 330 "/opt/bah/memory.bah"
#define __bah_memory_realloc memoryRealloc

#line 331 "/opt/bah/memory.bah"
#define __bah_memory_str memoryAllocSTR

#line 77 "/opt/bah/builtin.bah"
typedef array(void *)* __BAH_ARR_TYPE_ptr;
void __Bah_realocate_arr(__BAH_ARR_TYPE_ptr arr,unsigned int nLength){

#line 78 "/opt/bah/builtin.bah"
if ((nLength<arr->length)) {

#line 79 "/opt/bah/builtin.bah"
return;
}

#line 81 "/opt/bah/builtin.bah"
if ((nLength>=arr->realLength)) {

#line 82 "/opt/bah/builtin.bah"
if ((arr->realLength!=0)) {

#line 83 "/opt/bah/builtin.bah"
arr->realLength*=2;
}

#line 84 "/opt/bah/builtin.bah"
else {

#line 85 "/opt/bah/builtin.bah"
arr->realLength=50;
}

#line 87 "/opt/bah/builtin.bah"
void * newPtr = memoryRealloc(arr->data,arr->realLength*arr->elemSize);

#line 88 "/opt/bah/builtin.bah"
arr->data=newPtr;

#line 89 "/opt/bah/builtin.bah"
}

#line 93 "/opt/bah/builtin.bah"
arr->length=arr->length+1;

#line 94 "/opt/bah/builtin.bah"
return;
};

#line 98 "/opt/bah/builtin.bah"

#line 99 "/opt/bah/builtin.bah"
char * __Bah_multiple_concat(char ** b,unsigned int l){

#line 100 "/opt/bah/builtin.bah"
unsigned int* lens = alloca(l*sizeof(unsigned int));

#line 101 "/opt/bah/builtin.bah"
unsigned int tot = 0;

#line 102 "/opt/bah/builtin.bah"
int offset = 0;

#line 105 "/opt/bah/builtin.bah"
register long int i = 0;

#line 105 "/opt/bah/builtin.bah"
for (; (i<l); 
#line 105 "/opt/bah/builtin.bah"
++i) {

#line 106 "/opt/bah/builtin.bah"
long int sl = strlen(b[i]);

#line 107 "/opt/bah/builtin.bah"
tot = tot+sl;

#line 108 "/opt/bah/builtin.bah"
lens[i]=sl;
};

#line 112 "/opt/bah/builtin.bah"
char * r = memoryAllocSTR(tot+1);

#line 115 "/opt/bah/builtin.bah"
i = 0;

#line 115 "/opt/bah/builtin.bah"
for (; (i<l); 
#line 115 "/opt/bah/builtin.bah"
++i) {

#line 116 "/opt/bah/builtin.bah"
memcpy((void *)((long int)r+offset),b[i],lens[i]);

#line 117 "/opt/bah/builtin.bah"
offset = offset+(lens[i]);
};

#line 120 "/opt/bah/builtin.bah"
return r;
};

#line 123 "/opt/bah/builtin.bah"

#line 125 "/opt/bah/builtin.bah"

#line 127 "/opt/bah/builtin.bah"

#line 128 "/opt/bah/builtin.bah"

#line 129 "/opt/bah/builtin.bah"

#line 133 "/opt/bah/builtin.bah"
char * concatCPSTRING(char * a,char * b){

#line 134 "/opt/bah/builtin.bah"
long int lenA = strlen(a);

#line 135 "/opt/bah/builtin.bah"
long int lenB = strlen(b);

#line 136 "/opt/bah/builtin.bah"
char * r = memoryAlloc(lenA+lenB+1);

#line 137 "/opt/bah/builtin.bah"
strncpy(r,a,lenA);

#line 138 "/opt/bah/builtin.bah"
strcat(r,b);

#line 139 "/opt/bah/builtin.bah"
return r;
};

#line 144 "/opt/bah/builtin.bah"
char * __STR(char * a){

#line 145 "/opt/bah/builtin.bah"
long int lenA = strlen(a);

#line 146 "/opt/bah/builtin.bah"
char * r = memoryAllocSTR(lenA+1);

#line 147 "/opt/bah/builtin.bah"
memcpy(r,a,lenA);

#line 148 "/opt/bah/builtin.bah"
return r;
};

#line 152 "/opt/bah/builtin.bah"
void * cArr(void * arr){

#line 153 "/opt/bah/builtin.bah"
array(void*)*a=arr;

#line 154 "/opt/bah/builtin.bah"
return a->data;
};

#line 159 "/opt/bah/builtin.bah"
char __checkString(char * s,char * l){

#line 161 "/opt/bah/builtin.bah"
if (__builtin_expect(((void *)s==null), 0)) {

#line 162 "/opt/bah/builtin.bah"
char** ____BAH_COMPILER_VAR_0 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_0[2] = ") is null \n";____BAH_COMPILER_VAR_0[1] = l;____BAH_COMPILER_VAR_0[0] = "cpstring (";char * ____BAH_COMPILER_VAR_1 =__Bah_multiple_concat(____BAH_COMPILER_VAR_0, 3);print(____BAH_COMPILER_VAR_1);

#line 163 "/opt/bah/builtin.bah"
exit(1);
}

#line 166 "/opt/bah/builtin.bah"
return true;
};

#line 169 "/opt/bah/builtin.bah"

#line 1 "/opt/bah/channel.bah"

#line 1 "/opt/bah/thread.bah"
#include <pthread.h>

#line 3 "/opt/bah/thread.bah"

#line 5 "/opt/bah/thread.bah"

#line 6 "/opt/bah/thread.bah"

#line 7 "/opt/bah/thread.bah"

#line 9 "/opt/bah/thread.bah"

#line 10 "/opt/bah/thread.bah"

#line 11 "/opt/bah/thread.bah"

#line 12 "/opt/bah/thread.bah"

#line 13 "/opt/bah/thread.bah"
#define __thread_create GC_pthread_create

#line 14 "/opt/bah/thread.bah"
#define __thread_join GC_pthread_join

#line 16 "/opt/bah/thread.bah"

#line 22 "/opt/bah/thread.bah"

#line 30 "/opt/bah/thread.bah"

#line 38 "/opt/bah/thread.bah"

#line 39 "/opt/bah/thread.bah"

#line 40 "/opt/bah/thread.bah"

#line 41 "/opt/bah/thread.bah"

#line 43 "/opt/bah/thread.bah"

#line 44 "/opt/bah/thread.bah"

#line 45 "/opt/bah/thread.bah"

#line 46 "/opt/bah/thread.bah"

#line 48 "/opt/bah/thread.bah"

#line 50 "/opt/bah/thread.bah"
#define currentThread pthread_self

#line 55 "/opt/bah/thread.bah"
struct mutex {
pthread_mutex_t* id;
};
void mutex__init(struct mutex* this){

#line 61 "/opt/bah/thread.bah"
this->id = memoryAlloc(sizeof(pthread_mutex_t));

#line 62 "/opt/bah/thread.bah"
pthread_mutex_init(this->id,0);
};
void mutex__lock(struct mutex* this){

#line 68 "/opt/bah/thread.bah"
pthread_mutex_lock(this->id);
};
void mutex__unlock(struct mutex* this){

#line 73 "/opt/bah/thread.bah"
pthread_mutex_unlock(this->id);
};
void mutex__destroy(struct mutex* this){

#line 78 "/opt/bah/thread.bah"
pthread_mutex_destroy(this->id);
};

#line 84 "/opt/bah/thread.bah"
struct mutexCondition {
pthread_cond_t id;
};
void mutexCondition__init(struct mutexCondition* this){

#line 90 "/opt/bah/thread.bah"
pthread_cond_init(&this->id,0);
};
void mutexCondition__wait(struct mutexCondition* this,struct mutex m){

#line 99 "/opt/bah/thread.bah"
pthread_mutex_t* mid = m.id;

#line 100 "/opt/bah/thread.bah"
pthread_cond_wait(&this->id,mid);
};
void mutexCondition__send(struct mutexCondition* this){

#line 105 "/opt/bah/thread.bah"
pthread_cond_signal(&this->id);
};
void mutexCondition__destroy(struct mutexCondition* this){

#line 110 "/opt/bah/thread.bah"
pthread_cond_destroy(&this->id);
};

#line 116 "/opt/bah/thread.bah"
struct mutexCondition mutexCondition(){

#line 117 "/opt/bah/thread.bah"
struct mutexCondition ____BAH_COMPILER_VAR_2 = {};
struct mutexCondition m = ____BAH_COMPILER_VAR_2;

#line 118 "/opt/bah/thread.bah"
mutexCondition__init(&m);

#line 119 "/opt/bah/thread.bah"
return m;
};

#line 124 "/opt/bah/thread.bah"
struct thread {
pthread_t id;
void (*handle)(void *);
};
void thread__create(struct thread* this){

#line 133 "/opt/bah/thread.bah"
__thread_create(&this->id,null,this->handle,null);
};
void thread__createWithArg(struct thread* this,void * arg){

#line 139 "/opt/bah/thread.bah"
__thread_create(&this->id,null,this->handle,arg);
};
void thread__wait(struct thread* this){

#line 144 "/opt/bah/thread.bah"
__thread_join(this->id,null);
};

#line 149 "/opt/bah/thread.bah"
struct mutex mutex(){

#line 150 "/opt/bah/thread.bah"
struct mutex ____BAH_COMPILER_VAR_3 = {};
struct mutex m = ____BAH_COMPILER_VAR_3;

#line 151 "/opt/bah/thread.bah"
mutex__init(&m);

#line 152 "/opt/bah/thread.bah"
return m;
};

#line 2 "/opt/bah/channel.bah"

#line 1 "/opt/bah/queue.bah"

#line 4 "/opt/bah/queue.bah"
struct queueNode {
long int key;
void * data;
struct queueNode* next;
struct queueNode* prev;
};

#line 18 "/opt/bah/queue.bah"
struct queue {
long int length;
struct queueNode* head;
struct queueNode* end;
};
void queue__insert(struct queue* this,void * data){

#line 25 "/opt/bah/queue.bah"
struct queueNode* ____BAH_COMPILER_VAR_4 = memoryAlloc(sizeof(struct queueNode));
____BAH_COMPILER_VAR_4->key = this->length;
____BAH_COMPILER_VAR_4->data = data;
____BAH_COMPILER_VAR_4->prev = this->end;
struct queueNode* node = ____BAH_COMPILER_VAR_4;

#line 32 "/opt/bah/queue.bah"
++this->length;

#line 33 "/opt/bah/queue.bah"
if ((this->end==null)) {

#line 34 "/opt/bah/queue.bah"
this->head = node;

#line 35 "/opt/bah/queue.bah"
this->end = this->head;
}

#line 36 "/opt/bah/queue.bah"
else {

#line 37 "/opt/bah/queue.bah"
this->end->next = node;

#line 38 "/opt/bah/queue.bah"
this->end = node;
}
};
void queue__delete(struct queue* this,long int key){

#line 44 "/opt/bah/queue.bah"
if ((this->length==0)) {

#line 45 "/opt/bah/queue.bah"
return;
}

#line 47 "/opt/bah/queue.bah"
struct queueNode* current = this->head;

#line 48 "/opt/bah/queue.bah"
struct queueNode* previous= null;

#line 49 "/opt/bah/queue.bah"
while ((current->key!=key)) {

#line 50 "/opt/bah/queue.bah"
if ((current->next==null)) {

#line 51 "/opt/bah/queue.bah"
return;
}

#line 53 "/opt/bah/queue.bah"
previous = current;

#line 54 "/opt/bah/queue.bah"
current = current->next;
};

#line 56 "/opt/bah/queue.bah"
if ((current==this->head)) {

#line 57 "/opt/bah/queue.bah"
this->head = current->next;
}

#line 58 "/opt/bah/queue.bah"
else {

#line 59 "/opt/bah/queue.bah"
previous->next = current->next;
}

#line 61 "/opt/bah/queue.bah"
this->length = this->length-1;
};
void * queue__get(struct queue* this,long int key){

#line 66 "/opt/bah/queue.bah"
long int z = 0;

#line 67 "/opt/bah/queue.bah"
void * zp = (void *)z;

#line 68 "/opt/bah/queue.bah"
if ((this->length==0)) {

#line 69 "/opt/bah/queue.bah"
return zp;
}

#line 72 "/opt/bah/queue.bah"
struct queueNode* ptr = this->head;

#line 73 "/opt/bah/queue.bah"
while ((ptr->key!=key)) {

#line 74 "/opt/bah/queue.bah"
if ((ptr->next==null)) {

#line 75 "/opt/bah/queue.bah"
return zp;
}

#line 77 "/opt/bah/queue.bah"
ptr = ptr->next;
};

#line 80 "/opt/bah/queue.bah"
void * data = ptr->data;

#line 81 "/opt/bah/queue.bah"
return data;
};
void queue__set(struct queue* this,long int key,void * data){

#line 86 "/opt/bah/queue.bah"
queue__delete(this,key);

#line 88 "/opt/bah/queue.bah"
struct queueNode* ____BAH_COMPILER_VAR_5 = memoryAlloc(sizeof(struct queueNode));
struct queueNode* node = ____BAH_COMPILER_VAR_5;

#line 89 "/opt/bah/queue.bah"
node->key = key;

#line 90 "/opt/bah/queue.bah"
node->data = data;

#line 91 "/opt/bah/queue.bah"
node->next = this->head;

#line 93 "/opt/bah/queue.bah"
this->length = this->length+1;

#line 94 "/opt/bah/queue.bah"
this->head = node;
};
void * queue__pop(struct queue* this){

#line 101 "/opt/bah/queue.bah"
if ((this->head==null)) {

#line 102 "/opt/bah/queue.bah"
return null;
}

#line 104 "/opt/bah/queue.bah"
void * data = this->head->data;

#line 105 "/opt/bah/queue.bah"
this->head = this->head->next;

#line 106 "/opt/bah/queue.bah"
if ((this->head==null)) {

#line 107 "/opt/bah/queue.bah"
this->end = null;
}

#line 109 "/opt/bah/queue.bah"
--this->length;

#line 111 "/opt/bah/queue.bah"
return data;
};
void queue__clear(struct queue* this){

#line 116 "/opt/bah/queue.bah"
this->head = (void *)0;

#line 117 "/opt/bah/queue.bah"
this->length = 0;
};

#line 9 "/opt/bah/channel.bah"
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

#line 24 "/opt/bah/channel.bah"
pthread_mutex_lock(&this->m_mut);

#line 25 "/opt/bah/channel.bah"
if ((this->cap!=-1)) {

#line 26 "/opt/bah/channel.bah"
while ((this->queue->length==this->cap)) {

#line 27 "/opt/bah/channel.bah"
++this->w_waitting;

#line 28 "/opt/bah/channel.bah"
pthread_cond_wait(&this->w_cond,&this->m_mut);

#line 29 "/opt/bah/channel.bah"
--this->w_waitting;
};
}

#line 32 "/opt/bah/channel.bah"
queue__insert(this->queue,data);

#line 33 "/opt/bah/channel.bah"
if ((this->r_waitting>0)) {

#line 34 "/opt/bah/channel.bah"
pthread_cond_signal(&this->r_cond);
}

#line 36 "/opt/bah/channel.bah"
pthread_mutex_unlock(&this->m_mut);
};
void channel__sendAny(struct channel* this,void * data,long int len){

#line 40 "/opt/bah/channel.bah"
pthread_mutex_lock(&this->m_mut);

#line 41 "/opt/bah/channel.bah"
if ((this->cap!=-1)) {

#line 42 "/opt/bah/channel.bah"
while ((this->queue->length==this->cap)) {

#line 43 "/opt/bah/channel.bah"
++this->w_waitting;

#line 44 "/opt/bah/channel.bah"
pthread_cond_wait(&this->w_cond,&this->m_mut);

#line 45 "/opt/bah/channel.bah"
--this->w_waitting;
};
}

#line 48 "/opt/bah/channel.bah"
void * p = memoryAlloc(len);

#line 49 "/opt/bah/channel.bah"
memcpy(p,data,len);

#line 50 "/opt/bah/channel.bah"
queue__insert(this->queue,p);

#line 51 "/opt/bah/channel.bah"
if ((this->r_waitting>0)) {

#line 52 "/opt/bah/channel.bah"
pthread_cond_signal(&this->r_cond);
}

#line 54 "/opt/bah/channel.bah"
pthread_mutex_unlock(&this->m_mut);
};
void * channel__receive(struct channel* this){

#line 61 "/opt/bah/channel.bah"
pthread_mutex_lock(&this->m_mut);

#line 62 "/opt/bah/channel.bah"
while ((this->queue->length==0)) {

#line 63 "/opt/bah/channel.bah"
++this->r_waitting;

#line 64 "/opt/bah/channel.bah"
pthread_cond_wait(&this->r_cond,&this->m_mut);

#line 65 "/opt/bah/channel.bah"
--this->r_waitting;
};

#line 67 "/opt/bah/channel.bah"
void * data = queue__pop(this->queue);

#line 68 "/opt/bah/channel.bah"
if ((this->w_waitting>0)) {

#line 69 "/opt/bah/channel.bah"
pthread_cond_signal(&this->w_cond);
}

#line 71 "/opt/bah/channel.bah"
pthread_mutex_unlock(&this->m_mut);

#line 76 "/opt/bah/channel.bah"
return data;
};
void channel__destroy(struct channel* this){

#line 81 "/opt/bah/channel.bah"
pthread_mutex_destroy(&this->m_mut);

#line 82 "/opt/bah/channel.bah"
pthread_cond_destroy(&this->w_cond);

#line 83 "/opt/bah/channel.bah"
pthread_cond_destroy(&this->r_cond);
};
long int channel__len(struct channel* this){

#line 89 "/opt/bah/channel.bah"
long int l = this->queue->length;

#line 90 "/opt/bah/channel.bah"
return l;
};

#line 97 "/opt/bah/channel.bah"
struct channel* channel(){

#line 98 "/opt/bah/channel.bah"
struct channel* ____BAH_COMPILER_VAR_6 = memoryAlloc(sizeof(struct channel));
____BAH_COMPILER_VAR_6->cap = -1;
struct channel* c = ____BAH_COMPILER_VAR_6;

#line 99 "/opt/bah/channel.bah"
pthread_mutex_init(&c->m_mut,0);

#line 100 "/opt/bah/channel.bah"
pthread_cond_init(&c->w_cond,0);

#line 101 "/opt/bah/channel.bah"
pthread_cond_init(&c->r_cond,0);

#line 102 "/opt/bah/channel.bah"
struct queue* ____BAH_COMPILER_VAR_7 = memoryAlloc(sizeof(struct queue));
c->queue = ____BAH_COMPILER_VAR_7;

#line 104 "/opt/bah/channel.bah"
return c;
};

#line 108 "/opt/bah/channel.bah"
void setChanCap(void * c,long int cap){

#line 109 "/opt/bah/channel.bah"
struct channel* cp = c;

#line 110 "/opt/bah/channel.bah"
cp->cap = cap;
};

#line 170 "/opt/bah/builtin.bah"
struct channel * __BAH_panic_chan;

#line 174 "/opt/bah/builtin.bah"
void __Bah_common_panic(char * e){

#line 175 "/opt/bah/builtin.bah"
if (__builtin_expect(strlen(e), 0)) {

#line 176 "/opt/bah/builtin.bah"
print(e);

#line 177 "/opt/bah/builtin.bah"
print("\n");

#line 178 "/opt/bah/builtin.bah"
cleanShutDown();
}
};

#line 182 "/opt/bah/builtin.bah"
#define panic __Bah_common_panic

#line 184 "/opt/bah/builtin.bah"
struct __Bah_fnName_mapper {
void * p;
char * n;
};

#line 189 "/opt/bah/builtin.bah"
array(struct __Bah_fnName_mapper)* __Bah_fnNames;

#line 192 "/opt/bah/builtin.bah"
void __Bah_fnNames_append(struct __Bah_fnName_mapper fnn){

#line 193 "/opt/bah/builtin.bah"

    unsigned int ____BAH_COMPILER_VAR_8 = len(__Bah_fnNames);
    __Bah_realocate_arr(__Bah_fnNames, ____BAH_COMPILER_VAR_8);
    __Bah_fnNames->data[____BAH_COMPILER_VAR_8] = fnn;
};

#line 196 "/opt/bah/builtin.bah"

#line 197 "/opt/bah/builtin.bah"
long int backtrace(void * arr,long int l);

#line 198 "/opt/bah/builtin.bah"

#line 201 "/opt/bah/builtin.bah"

#line 202 "/opt/bah/builtin.bah"

#line 203 "/opt/bah/builtin.bah"

#line 205 "/opt/bah/builtin.bah"
char * fastExec(char * s){

#line 206 "/opt/bah/builtin.bah"
void * hdl = popen(s,"r");

#line 208 "/opt/bah/builtin.bah"
char ____BAH_COMPILER_VAR_9[1024];char* buff = ____BAH_COMPILER_VAR_9;

#line 209 "/opt/bah/builtin.bah"
char * response = "";

#line 210 "/opt/bah/builtin.bah"
void * res = fgets(buff,1023,hdl);

#line 211 "/opt/bah/builtin.bah"
while ((res!=null)) {

#line 212 "/opt/bah/builtin.bah"
char** ____BAH_COMPILER_VAR_10 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_10[1] = buff;____BAH_COMPILER_VAR_10[0] = response;char * ____BAH_COMPILER_VAR_11 =__Bah_multiple_concat(____BAH_COMPILER_VAR_10, 2);response = ____BAH_COMPILER_VAR_11;

#line 213 "/opt/bah/builtin.bah"
res = fgets(buff,1023,hdl);
};

#line 216 "/opt/bah/builtin.bah"
pclose(hdl);

#line 217 "/opt/bah/builtin.bah"
return response;
};

#line 221 "/opt/bah/builtin.bah"
void __BAH_panic(char * e,char * line){

#line 222 "/opt/bah/builtin.bah"
if ((__BAH_panic_chan!=null)) {

#line 223 "/opt/bah/builtin.bah"
channel__send(__BAH_panic_chan, e);

#line 224 "/opt/bah/builtin.bah"
return;
}

#line 227 "/opt/bah/builtin.bah"
char** ____BAH_COMPILER_VAR_12 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_12[4] = "\n";____BAH_COMPILER_VAR_12[3] = e;____BAH_COMPILER_VAR_12[2] = "): ";____BAH_COMPILER_VAR_12[1] = line;____BAH_COMPILER_VAR_12[0] = "panic (";char * ____BAH_COMPILER_VAR_13 =__Bah_multiple_concat(____BAH_COMPILER_VAR_12, 5);print(____BAH_COMPILER_VAR_13);

#line 229 "/opt/bah/builtin.bah"

#line 230 "/opt/bah/builtin.bah"
array(void *)* arr = memoryAlloc(sizeof(array(void *)));

arr->length = 0;
arr->elemSize = sizeof(void *);

#line 231 "/opt/bah/builtin.bah"
allocateArray(arr,10);

#line 232 "/opt/bah/builtin.bah"
long int size = backtrace(arr->data,10);

#line 234 "/opt/bah/builtin.bah"
print("Backtrace:\n");

#line 236 "/opt/bah/builtin.bah"
long int min = -1;

#line 237 "/opt/bah/builtin.bah"
long int max = -1;

#line 239 "/opt/bah/builtin.bah"
char ____BAH_COMPILER_VAR_14[4096];char* selfPath = ____BAH_COMPILER_VAR_14;

#line 240 "/opt/bah/builtin.bah"
readlink("/proc/self/exe",selfPath,4096);

#line 242 "/opt/bah/builtin.bah"
register long int i = 1;

#line 242 "/opt/bah/builtin.bah"
for (; (i<size); 
#line 242 "/opt/bah/builtin.bah"
++i) {

#line 243 "/opt/bah/builtin.bah"
long int p = arr->data[i];

#line 244 "/opt/bah/builtin.bah"
struct __Bah_fnName_mapper closest;

#line 245 "/opt/bah/builtin.bah"
long int dist = -1;

#line 246 "/opt/bah/builtin.bah"
register long int j = 0;

#line 246 "/opt/bah/builtin.bah"
for (; (j<len(__Bah_fnNames)); 
#line 246 "/opt/bah/builtin.bah"
++j) {

#line 247 "/opt/bah/builtin.bah"
struct __Bah_fnName_mapper fnn = __Bah_fnNames->data[j];

#line 248 "/opt/bah/builtin.bah"
long int fnp = fnn.p;

#line 249 "/opt/bah/builtin.bah"
if ((fnp<min)||(min==-1)) {

#line 250 "/opt/bah/builtin.bah"
min = fnp;
}

#line 252 "/opt/bah/builtin.bah"
if ((fnp>max)||(max==-1)) {

#line 253 "/opt/bah/builtin.bah"
max = fnp;
}

#line 255 "/opt/bah/builtin.bah"
if ((p>fnp)) {

#line 256 "/opt/bah/builtin.bah"
if ((dist==-1)||(p-fnp<dist)) {

#line 257 "/opt/bah/builtin.bah"
dist = p-fnp;

#line 258 "/opt/bah/builtin.bah"
closest = fnn;
}
}
};

#line 262 "/opt/bah/builtin.bah"
char ____BAH_COMPILER_VAR_15[2048];char* buff = ____BAH_COMPILER_VAR_15;

#line 263 "/opt/bah/builtin.bah"
memset(buff,0,2048);

#line 264 "/opt/bah/builtin.bah"
sprintf(buff,"addr2line %p -f -i -e %s",p,selfPath);

#line 265 "/opt/bah/builtin.bah"
char * s = fastExec(buff);

#line 266 "/opt/bah/builtin.bah"
char ____BAH_COMPILER_VAR_16[255];char* name = ____BAH_COMPILER_VAR_16;

#line 267 "/opt/bah/builtin.bah"
char ____BAH_COMPILER_VAR_17[2048];char* path = ____BAH_COMPILER_VAR_17;

#line 268 "/opt/bah/builtin.bah"
j = 0;

#line 268 "/opt/bah/builtin.bah"
for (; (s[j]!=null); 
#line 268 "/opt/bah/builtin.bah"
++j) {

#line 269 "/opt/bah/builtin.bah"
if ((s[j]==(char)10)) {

#line 270 "/opt/bah/builtin.bah"
name[j] = null;

#line 271 "/opt/bah/builtin.bah"
++j;

#line 272 "/opt/bah/builtin.bah"
break;
}

#line 274 "/opt/bah/builtin.bah"
name[j] = s[j];
};

#line 277 "/opt/bah/builtin.bah"
long int start = j;

#line 278 "/opt/bah/builtin.bah"
for (; (s[j]!=null); 
#line 278 "/opt/bah/builtin.bah"
++j) {

#line 279 "/opt/bah/builtin.bah"
if ((s[j]==(char)10)) {

#line 280 "/opt/bah/builtin.bah"
path[j-start] = null;

#line 281 "/opt/bah/builtin.bah"
break;
}

#line 283 "/opt/bah/builtin.bah"
path[j-start] = s[j];
};

#line 286 "/opt/bah/builtin.bah"
if ((strcmp(closest.n, "main") == 0)) {

#line 287 "/opt/bah/builtin.bah"
path = "<internal>";
}

#line 290 "/opt/bah/builtin.bah"
char** ____BAH_COMPILER_VAR_18 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_18[4] = "\033[m \n";____BAH_COMPILER_VAR_18[3] = (char *)path;____BAH_COMPILER_VAR_18[2] = "\033[m() \033[32m";____BAH_COMPILER_VAR_18[1] = (char *)name;____BAH_COMPILER_VAR_18[0] = "\t\033[33m";char * ____BAH_COMPILER_VAR_19 =__Bah_multiple_concat(____BAH_COMPILER_VAR_18, 5);print(____BAH_COMPILER_VAR_19);

#line 292 "/opt/bah/builtin.bah"
if ((strcmp(closest.n, "main") == 0)) {

#line 293 "/opt/bah/builtin.bah"
break;
}
};

#line 298 "/opt/bah/builtin.bah"
cleanShutDown();
};

#line 301 "/opt/bah/builtin.bah"
char * (*onMemoryError)();

#line 304 "/opt/bah/builtin.bah"
void __Bah_segfault_handle(long int sig){

#line 305 "/opt/bah/builtin.bah"
char * res = "";

#line 306 "/opt/bah/builtin.bah"
if ((onMemoryError!=null)) {

#line 307 "/opt/bah/builtin.bah"
res = onMemoryError();
}

#line 309 "/opt/bah/builtin.bah"
char** ____BAH_COMPILER_VAR_20 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_20[1] = res;____BAH_COMPILER_VAR_20[0] = "Memory error (segfault).\n";char * ____BAH_COMPILER_VAR_21 =__Bah_multiple_concat(____BAH_COMPILER_VAR_20, 2);__BAH_panic(____BAH_COMPILER_VAR_21,"???");
};

#line 313 "/opt/bah/builtin.bah"
char __Bah_init_segfaultHandle(){

#line 314 "/opt/bah/builtin.bah"
signal(SIGSEGV,__Bah_segfault_handle);

#line 315 "/opt/bah/builtin.bah"
return true;
};

#line 318 "/opt/bah/builtin.bah"
char __Bah_init_segfaultHandle_OK;

#line 323 "/opt/bah/builtin.bah"
char recover(char ** s){

#line 324 "/opt/bah/builtin.bah"
__BAH_panic_chan = channel();

#line 325 "/opt/bah/builtin.bah"
char * ____BAH_COMPILER_VAR_22 =channel__receive(__BAH_panic_chan);char * err = ____BAH_COMPILER_VAR_22;

#line 326 "/opt/bah/builtin.bah"
if ((s!=null)) {

#line 327 "/opt/bah/builtin.bah"
*s = err;
}

#line 329 "/opt/bah/builtin.bah"
return true;
};

#line 334 "/opt/bah/builtin.bah"
char * __Bah_safe_string(char * s){

#line 335 "/opt/bah/builtin.bah"
if (((void *)s==null)) {

#line 336 "/opt/bah/builtin.bah"
return "(nil)";
}

#line 338 "/opt/bah/builtin.bah"
if ((strlen(s)>50)) {

#line 339 "/opt/bah/builtin.bah"
s = __STR(s);

#line 340 "/opt/bah/builtin.bah"
array(char)* a = strAsArr(s);

#line 341 "/opt/bah/builtin.bah"

    unsigned int ____BAH_COMPILER_VAR_23 = 47;
    __Bah_realocate_arr(a, ____BAH_COMPILER_VAR_23);
    a->data[____BAH_COMPILER_VAR_23] = 46;

#line 342 "/opt/bah/builtin.bah"

    unsigned int ____BAH_COMPILER_VAR_24 = 48;
    __Bah_realocate_arr(a, ____BAH_COMPILER_VAR_24);
    a->data[____BAH_COMPILER_VAR_24] = 46;

#line 343 "/opt/bah/builtin.bah"

    unsigned int ____BAH_COMPILER_VAR_25 = 49;
    __Bah_realocate_arr(a, ____BAH_COMPILER_VAR_25);
    a->data[____BAH_COMPILER_VAR_25] = 46;

#line 344 "/opt/bah/builtin.bah"

    unsigned int ____BAH_COMPILER_VAR_26 = 50;
    __Bah_realocate_arr(a, ____BAH_COMPILER_VAR_26);
    a->data[____BAH_COMPILER_VAR_26] = (char)0;
}

#line 347 "/opt/bah/builtin.bah"
char** ____BAH_COMPILER_VAR_27 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_27[2] = "\"";____BAH_COMPILER_VAR_27[1] = s;____BAH_COMPILER_VAR_27[0] = "\"";char * ____BAH_COMPILER_VAR_28 =__Bah_multiple_concat(____BAH_COMPILER_VAR_27, 3);return ____BAH_COMPILER_VAR_28;
};

#line 353 "/opt/bah/builtin.bah"
char cpstringCharAt(char * s,long int i){

#line 354 "/opt/bah/builtin.bah"
char c = (char)0;

#line 355 "/opt/bah/builtin.bah"
c=s[i];

#line 356 "/opt/bah/builtin.bah"
return c;
};

#line 360 "/opt/bah/builtin.bah"
char * cpstringSubsitute(char * s,long int i,long int l){

#line 361 "/opt/bah/builtin.bah"
long int size = l-i;

#line 362 "/opt/bah/builtin.bah"
char * ns = memoryAllocSTR(size+1);

#line 363 "/opt/bah/builtin.bah"
memcpy(ns,s+i,size);

#line 364 "/opt/bah/builtin.bah"
return ns;
};

#line 368 "/opt/bah/builtin.bah"
void * arraySubstitute(__BAH_ARR_TYPE_ptr arr,long int i,long int l){

#line 369 "/opt/bah/builtin.bah"
long int length = l-i;

#line 370 "/opt/bah/builtin.bah"
long int offset = i*arr->elemSize;

#line 371 "/opt/bah/builtin.bah"
array(void *)* na = memoryAlloc(sizeof(array(void *)));

na->length = 0;
na->elemSize = sizeof(void *);

#line 372 "/opt/bah/builtin.bah"
na->elemSize=arr->elemSize;

#line 373 "/opt/bah/builtin.bah"
na->length=length;

#line 375 "/opt/bah/builtin.bah"
long int allocLength = length;

#line 376 "/opt/bah/builtin.bah"
if ((length>50)) {

#line 377 "/opt/bah/builtin.bah"
allocLength = allocLength+(allocLength%50);
}

#line 378 "/opt/bah/builtin.bah"
else {

#line 379 "/opt/bah/builtin.bah"
allocLength = 50;
}

#line 381 "/opt/bah/builtin.bah"
long int size = allocLength*arr->elemSize;

#line 382 "/opt/bah/builtin.bah"
long int realSize = length*arr->elemSize;

#line 383 "/opt/bah/builtin.bah"
void * data = memoryAlloc(size);

#line 384 "/opt/bah/builtin.bah"
char * oData = arr->data;

#line 385 "/opt/bah/builtin.bah"
memcpy(data,oData+offset,realSize);

#line 386 "/opt/bah/builtin.bah"
na->data=data;

#line 387 "/opt/bah/builtin.bah"
return na;
};

#line 390 "/opt/bah/builtin.bah"

#line 2 "/opt/bah/map.bah"
long int __Bah_map_hash(char * s,long int l){

#line 3 "/opt/bah/map.bah"
long int hash = 5381;

#line 5 "/opt/bah/map.bah"
register long int i = 0;

#line 5 "/opt/bah/map.bah"
for (; (i<strlen(s)); 
#line 5 "/opt/bah/map.bah"
++i) {

#line 6 "/opt/bah/map.bah"
hash = ((long int)hash<<5+0)+hash+(long int)s[i];
};

#line 9 "/opt/bah/map.bah"
if ((hash<0)) {

#line 10 "/opt/bah/map.bah"
hash = 0-hash;
}

#line 13 "/opt/bah/map.bah"
return hash%l;
};

#line 17 "/opt/bah/map.bah"
struct mapElem {
char * key;
void * val;
};

#line 24 "/opt/bah/map.bah"
struct mapSearchRes {
char found;
void * res;
unsigned int l;
};

#line 31 "/opt/bah/map.bah"
struct mapNode {
char * str;
unsigned int strL;
struct mapNode* left;
struct mapNode* right;
void * value;
};
int mapNode__calc(struct mapNode* this,char * s,unsigned int i){

#line 40 "/opt/bah/map.bah"
for (; (i<this->strL); 
#line 40 "/opt/bah/map.bah"
++i) {

#line 41 "/opt/bah/map.bah"
if ((s[i]==null)||(this->str[i]!=s[i])) {

#line 42 "/opt/bah/map.bah"
break;
}
};

#line 45 "/opt/bah/map.bah"
if ((i==this->strL)&&(s[i]==null)) {

#line 46 "/opt/bah/map.bah"
return -1;
}

#line 48 "/opt/bah/map.bah"
return i;
};
void mapNode__getFast(struct mapNode* this,char * s,int r,struct mapSearchRes* msr){

#line 55 "/opt/bah/map.bah"
if ((r==-1)) {

#line 56 "/opt/bah/map.bah"
msr->found = true;

#line 57 "/opt/bah/map.bah"
msr->res = this;

#line 58 "/opt/bah/map.bah"
return;
}

#line 61 "/opt/bah/map.bah"
if ((r==0)&&(this->strL!=0)) {

#line 62 "/opt/bah/map.bah"
msr->found = false;

#line 63 "/opt/bah/map.bah"
msr->res = null;

#line 64 "/opt/bah/map.bah"
return;
}

#line 67 "/opt/bah/map.bah"
long int lr = 0;

#line 67 "/opt/bah/map.bah"
long int rr = 0;

#line 70 "/opt/bah/map.bah"
if ((this->left!=null)) {

#line 71 "/opt/bah/map.bah"
lr = mapNode__calc(this->left,s,r);
}

#line 74 "/opt/bah/map.bah"
if ((this->right!=null)) {

#line 75 "/opt/bah/map.bah"
rr = mapNode__calc(this->right,s,r);
}

#line 78 "/opt/bah/map.bah"
if ((lr==-1)) {

#line 79 "/opt/bah/map.bah"
msr->found = true;

#line 80 "/opt/bah/map.bah"
msr->res = this->left;

#line 81 "/opt/bah/map.bah"
return;
}

#line 83 "/opt/bah/map.bah"
if ((rr==-1)) {

#line 84 "/opt/bah/map.bah"
msr->found = true;

#line 85 "/opt/bah/map.bah"
msr->res = this->right;

#line 86 "/opt/bah/map.bah"
return;
}

#line 90 "/opt/bah/map.bah"
if ((lr>r)&&(lr>rr)) {

#line 91 "/opt/bah/map.bah"
mapNode__getFast(this->left,s,lr,msr);

#line 92 "/opt/bah/map.bah"
return;
}

#line 95 "/opt/bah/map.bah"
if ((rr>r)&&(rr>lr)) {

#line 96 "/opt/bah/map.bah"
mapNode__getFast(this->right,s,rr,msr);

#line 97 "/opt/bah/map.bah"
return;
}

#line 100 "/opt/bah/map.bah"
if ((this->left!=null)&&(this->left->strL==this->strL)) {

#line 101 "/opt/bah/map.bah"
mapNode__getFast(this->left,s,lr,msr);

#line 102 "/opt/bah/map.bah"
if ((msr->l==r)&&(msr->found==false)) {

#line 103 "/opt/bah/map.bah"
msr->res = this;
}

#line 105 "/opt/bah/map.bah"
return;
}

#line 109 "/opt/bah/map.bah"
msr->found = false;

#line 110 "/opt/bah/map.bah"
msr->res = this;

#line 111 "/opt/bah/map.bah"
msr->l = r;

#line 112 "/opt/bah/map.bah"
return;
};
void mapNode__append(struct mapNode* this,char * k,void * e,unsigned int l){

#line 117 "/opt/bah/map.bah"
struct mapNode* ____BAH_COMPILER_VAR_29 = memoryAlloc(sizeof(struct mapNode));
____BAH_COMPILER_VAR_29->str = k;
____BAH_COMPILER_VAR_29->strL = strlen(k);
____BAH_COMPILER_VAR_29->value = e;
struct mapNode* ne = ____BAH_COMPILER_VAR_29;

#line 123 "/opt/bah/map.bah"
if ((l!=this->strL)) {

#line 124 "/opt/bah/map.bah"
struct mapNode* ____BAH_COMPILER_VAR_30 = memoryAlloc(sizeof(struct mapNode));
____BAH_COMPILER_VAR_30->value = this->value;
____BAH_COMPILER_VAR_30->right = this->right;
____BAH_COMPILER_VAR_30->left = this->left;
____BAH_COMPILER_VAR_30->str = this->str;
____BAH_COMPILER_VAR_30->strL = this->strL;
this->right = ____BAH_COMPILER_VAR_30;

#line 131 "/opt/bah/map.bah"
this->str = cpstringSubsitute(this->str, 0, l);

#line 132 "/opt/bah/map.bah"
this->value = null;

#line 133 "/opt/bah/map.bah"
this->strL = l;

#line 134 "/opt/bah/map.bah"
this->left = ne;

#line 135 "/opt/bah/map.bah"
return;
}

#line 138 "/opt/bah/map.bah"
if ((this->left==null)) {

#line 139 "/opt/bah/map.bah"
this->left = ne;

#line 140 "/opt/bah/map.bah"
return;
}

#line 143 "/opt/bah/map.bah"
if ((this->right==null)) {

#line 144 "/opt/bah/map.bah"
this->right = ne;

#line 145 "/opt/bah/map.bah"
return;
}

#line 148 "/opt/bah/map.bah"
struct mapNode* ol = this->left;

#line 149 "/opt/bah/map.bah"
struct mapNode* ____BAH_COMPILER_VAR_31 = memoryAlloc(sizeof(struct mapNode));
____BAH_COMPILER_VAR_31->str = this->str;
____BAH_COMPILER_VAR_31->strL = this->strL;
____BAH_COMPILER_VAR_31->value = null;
____BAH_COMPILER_VAR_31->left = ol;
____BAH_COMPILER_VAR_31->right = ne;
this->left = ____BAH_COMPILER_VAR_31;
};

#line 160 "/opt/bah/map.bah"
void mapWrapperSetAlgo(void * p,unsigned int nb);

#line 163 "/opt/bah/map.bah"
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

#line 186 "/opt/bah/map.bah"
if ((this->nbDelete<this->length)&&((this->length>=40000)||((double)this->nbMisses/(double)this->nbTotal>=20.0))) {

#line 187 "/opt/bah/map.bah"
mapWrapperSetAlgo(this,1);
}

#line 188 "/opt/bah/map.bah"
else if ((this->nbDelete>=this->length*2)||(this->length<500)) {

#line 189 "/opt/bah/map.bah"
mapWrapperSetAlgo(this,2);
}
};
void mapWrapper__grow(struct mapWrapper* this,long int nb){

#line 196 "/opt/bah/map.bah"
long int l = len(this->elems);

#line 197 "/opt/bah/map.bah"
register long int i = l;

#line 197 "/opt/bah/map.bah"
for (; (i<l+nb); 
#line 197 "/opt/bah/map.bah"
++i) {

#line 198 "/opt/bah/map.bah"

    unsigned int ____BAH_COMPILER_VAR_32 = i;
    __Bah_realocate_arr(this->elems, ____BAH_COMPILER_VAR_32);
    this->elems->data[____BAH_COMPILER_VAR_32] = null;
};

#line 202 "/opt/bah/map.bah"
i = 0;

#line 202 "/opt/bah/map.bah"
for (; (i<l); 
#line 202 "/opt/bah/map.bah"
++i) {

#line 203 "/opt/bah/map.bah"
struct mapElem* e = this->elems->data[i];

#line 204 "/opt/bah/map.bah"
if ((e==null)) {

#line 205 "/opt/bah/map.bah"
continue;
}

#line 207 "/opt/bah/map.bah"
long int ind = __Bah_map_hash(e->key,len(this->elems));

#line 208 "/opt/bah/map.bah"
if ((ind!=i)) {

#line 209 "/opt/bah/map.bah"
register long int j = ind;

#line 209 "/opt/bah/map.bah"
for (; (j<len(this->elems)); 
#line 209 "/opt/bah/map.bah"
++j) {

#line 210 "/opt/bah/map.bah"
if ((this->elems->data[j]==null)) {

#line 211 "/opt/bah/map.bah"

    unsigned int ____BAH_COMPILER_VAR_33 = i;
    __Bah_realocate_arr(this->elems, ____BAH_COMPILER_VAR_33);
    this->elems->data[____BAH_COMPILER_VAR_33] = null;

#line 212 "/opt/bah/map.bah"

    unsigned int ____BAH_COMPILER_VAR_34 = j;
    __Bah_realocate_arr(this->elems, ____BAH_COMPILER_VAR_34);
    this->elems->data[____BAH_COMPILER_VAR_34] = e;

#line 213 "/opt/bah/map.bah"
break;
}
};
}
};
};
void mapWrapper__set2(struct mapWrapper* this,char * k,void * e){

#line 222 "/opt/bah/map.bah"
if ((this->length==0)) {

#line 223 "/opt/bah/map.bah"
mapWrapper__grow(this,50);
}

#line 225 "/opt/bah/map.bah"
if ((this->length*2>=len(this->elems))) {

#line 226 "/opt/bah/map.bah"
mapWrapper__grow(this,this->length);
}

#line 228 "/opt/bah/map.bah"
struct mapElem* ____BAH_COMPILER_VAR_35 = memoryAlloc(sizeof(struct mapElem));
____BAH_COMPILER_VAR_35->key = k;
____BAH_COMPILER_VAR_35->val = e;
struct mapElem* elem = ____BAH_COMPILER_VAR_35;

#line 232 "/opt/bah/map.bah"
long int ind = __Bah_map_hash(k,len(this->elems));

#line 233 "/opt/bah/map.bah"
register long int i = 0;

#line 233 "/opt/bah/map.bah"
for (; (i<len(this->elems)); 
#line 233 "/opt/bah/map.bah"
++i) {

#line 234 "/opt/bah/map.bah"
long int j = (i+ind)%len(this->elems);

#line 235 "/opt/bah/map.bah"
struct mapElem* ce = this->elems->data[j];

#line 236 "/opt/bah/map.bah"
if ((ce==null)) {

#line 237 "/opt/bah/map.bah"

    unsigned int ____BAH_COMPILER_VAR_36 = j;
    __Bah_realocate_arr(this->elems, ____BAH_COMPILER_VAR_36);
    this->elems->data[____BAH_COMPILER_VAR_36] = elem;

#line 238 "/opt/bah/map.bah"
++this->length;

#line 239 "/opt/bah/map.bah"
break;
}

#line 240 "/opt/bah/map.bah"
else if ((strcmp(ce->key, k) == 0)) {

#line 241 "/opt/bah/map.bah"

    unsigned int ____BAH_COMPILER_VAR_37 = j;
    __Bah_realocate_arr(this->elems, ____BAH_COMPILER_VAR_37);
    this->elems->data[____BAH_COMPILER_VAR_37] = elem;

#line 242 "/opt/bah/map.bah"
break;
}
};

#line 245 "/opt/bah/map.bah"
this->nbMisses = this->nbMisses+i;

#line 246 "/opt/bah/map.bah"
++this->nbTotal;

#line 247 "/opt/bah/map.bah"
if ((this->length%1000==0)) {

#line 248 "/opt/bah/map.bah"
mapWrapper__algoChecks(this);
}
};
void mapWrapper__delete2(struct mapWrapper* this,char * k){

#line 254 "/opt/bah/map.bah"
long int ind = __Bah_map_hash(k,len(this->elems));

#line 255 "/opt/bah/map.bah"
register long int i = 0;

#line 255 "/opt/bah/map.bah"
for (; (i<len(this->elems)); 
#line 255 "/opt/bah/map.bah"
++i) {

#line 256 "/opt/bah/map.bah"
long int j = (i+ind)%len(this->elems);

#line 257 "/opt/bah/map.bah"
struct mapElem* e = this->elems->data[j];

#line 258 "/opt/bah/map.bah"
if ((e!=null)&&(strcmp(e->key, k) == 0)) {

#line 259 "/opt/bah/map.bah"
this->nbMisses = this->nbMisses+i;

#line 260 "/opt/bah/map.bah"
++this->nbTotal;

#line 261 "/opt/bah/map.bah"
++this->nbDelete;

#line 262 "/opt/bah/map.bah"

    unsigned int ____BAH_COMPILER_VAR_38 = j;
    __Bah_realocate_arr(this->elems, ____BAH_COMPILER_VAR_38);
    this->elems->data[____BAH_COMPILER_VAR_38] = null;

#line 263 "/opt/bah/map.bah"
if ((this->length%1000==0)) {

#line 264 "/opt/bah/map.bah"
mapWrapper__algoChecks(this);
}
}
};
};
void * mapWrapper__get2(struct mapWrapper* this,char * k){

#line 272 "/opt/bah/map.bah"
long int ind = __Bah_map_hash(k,len(this->elems));

#line 273 "/opt/bah/map.bah"
register long int i = 0;

#line 273 "/opt/bah/map.bah"
for (; (i<len(this->elems)); 
#line 273 "/opt/bah/map.bah"
++i) {

#line 274 "/opt/bah/map.bah"
long int j = (i+ind)%len(this->elems);

#line 275 "/opt/bah/map.bah"
struct mapElem* e = this->elems->data[j];

#line 276 "/opt/bah/map.bah"
if ((e!=null)&&(strcmp(e->key, k) == 0)) {

#line 277 "/opt/bah/map.bah"
this->nbMisses = this->nbMisses+i;

#line 278 "/opt/bah/map.bah"
++this->nbTotal;

#line 279 "/opt/bah/map.bah"
return e->val;
}
};

#line 282 "/opt/bah/map.bah"
return null;
};
void mapWrapper__clearMsr(struct mapWrapper* this){

#line 288 "/opt/bah/map.bah"
this->msr.found = false;

#line 289 "/opt/bah/map.bah"
this->msr.res = null;

#line 290 "/opt/bah/map.bah"
this->msr.l = 0;
};
void * mapWrapper__get1(struct mapWrapper* this,char * k){

#line 295 "/opt/bah/map.bah"
mapWrapper__clearMsr(this);

#line 296 "/opt/bah/map.bah"
if ((this->nodes==null)) {

#line 297 "/opt/bah/map.bah"
return null;
}

#line 299 "/opt/bah/map.bah"
mapNode__getFast(this->nodes,k,mapNode__calc(this->nodes,k,0),&this->msr);

#line 300 "/opt/bah/map.bah"
if (this->msr.found) {

#line 301 "/opt/bah/map.bah"
struct mapNode* n = this->msr.res;

#line 302 "/opt/bah/map.bah"
return n->value;
}

#line 304 "/opt/bah/map.bah"
return null;
};
void mapWrapper__set1(struct mapWrapper* this,char * k,void * e){

#line 309 "/opt/bah/map.bah"
mapWrapper__clearMsr(this);

#line 310 "/opt/bah/map.bah"
if ((this->nodes==null)) {

#line 311 "/opt/bah/map.bah"
struct mapNode* ____BAH_COMPILER_VAR_39 = memoryAlloc(sizeof(struct mapNode));
____BAH_COMPILER_VAR_39->str = k;
____BAH_COMPILER_VAR_39->strL = strlen(k);
____BAH_COMPILER_VAR_39->value = e;
this->nodes = ____BAH_COMPILER_VAR_39;

#line 316 "/opt/bah/map.bah"
this->length = 1;

#line 317 "/opt/bah/map.bah"
return;
}

#line 319 "/opt/bah/map.bah"
struct mapSearchRes* n = &this->msr;

#line 320 "/opt/bah/map.bah"
n->res = null;

#line 321 "/opt/bah/map.bah"
n->found = false;

#line 322 "/opt/bah/map.bah"
mapNode__getFast(this->nodes,k,mapNode__calc(this->nodes,k,0),&this->msr);

#line 323 "/opt/bah/map.bah"
if ((n->res==null)) {

#line 324 "/opt/bah/map.bah"
struct mapNode* ____BAH_COMPILER_VAR_40 = memoryAlloc(sizeof(struct mapNode));
____BAH_COMPILER_VAR_40->str = k;
____BAH_COMPILER_VAR_40->strL = strlen(k);
____BAH_COMPILER_VAR_40->value = e;
struct mapNode* ne = ____BAH_COMPILER_VAR_40;

#line 329 "/opt/bah/map.bah"
struct mapNode* ____BAH_COMPILER_VAR_41 = memoryAlloc(sizeof(struct mapNode));
____BAH_COMPILER_VAR_41->str = "";
____BAH_COMPILER_VAR_41->strL = 0;
____BAH_COMPILER_VAR_41->left = ne;
____BAH_COMPILER_VAR_41->right = this->nodes;
struct mapNode* nh = ____BAH_COMPILER_VAR_41;

#line 335 "/opt/bah/map.bah"
this->nodes = nh;

#line 336 "/opt/bah/map.bah"
struct mapNode* nodesP = this->nodes;

#line 337 "/opt/bah/map.bah"
++this->length;

#line 338 "/opt/bah/map.bah"
return;
}

#line 340 "/opt/bah/map.bah"
struct mapNode* nn = n->res;

#line 341 "/opt/bah/map.bah"
if ((n->found==true)) {

#line 342 "/opt/bah/map.bah"
nn->str = k;

#line 343 "/opt/bah/map.bah"
nn->strL = strlen(k);

#line 344 "/opt/bah/map.bah"
nn->value = e;

#line 345 "/opt/bah/map.bah"
return;
}

#line 348 "/opt/bah/map.bah"
++this->length;

#line 349 "/opt/bah/map.bah"
mapNode__append(nn,k,e,n->l);

#line 350 "/opt/bah/map.bah"
if ((this->length%1000==0)) {

#line 351 "/opt/bah/map.bah"
mapWrapper__algoChecks(this);
}
};
void mapWrapper__delete1(struct mapWrapper* this,char * k){

#line 357 "/opt/bah/map.bah"
mapWrapper__clearMsr(this);

#line 358 "/opt/bah/map.bah"
mapNode__getFast(this->nodes,k,mapNode__calc(this->nodes,k,0),&this->msr);

#line 359 "/opt/bah/map.bah"
if (this->msr.found) {

#line 360 "/opt/bah/map.bah"
struct mapNode* n = this->msr.res;

#line 361 "/opt/bah/map.bah"
n->value = null;

#line 362 "/opt/bah/map.bah"
++this->nbDelete;

#line 363 "/opt/bah/map.bah"
--this->length;

#line 364 "/opt/bah/map.bah"
if ((this->length%1000==0)) {

#line 365 "/opt/bah/map.bah"
mapWrapper__algoChecks(this);
}
}
};
void mapWrapper__setAny(struct mapWrapper* this,char * k,void * e,long int s){

#line 373 "/opt/bah/map.bah"
void * p = memoryAlloc(s);

#line 374 "/opt/bah/map.bah"
memcpy(p,e,s);

#line 375 "/opt/bah/map.bah"
this->set(this,k,p);
};

#line 380 "/opt/bah/map.bah"
void mapWrapperSetAlgo(void * p,unsigned int nb){

#line 381 "/opt/bah/map.bah"
struct mapWrapper* this = p;

#line 382 "/opt/bah/map.bah"
if ((nb==this->algo)||(this->changingAlgo==true)) {

#line 383 "/opt/bah/map.bah"
return;
}

#line 385 "/opt/bah/map.bah"
this->changingAlgo = true;

#line 386 "/opt/bah/map.bah"
if ((nb==1)) {

#line 387 "/opt/bah/map.bah"
this->set = mapWrapper__set1;

#line 388 "/opt/bah/map.bah"
this->get = mapWrapper__get1;

#line 389 "/opt/bah/map.bah"
this->delete = mapWrapper__delete1;

#line 390 "/opt/bah/map.bah"
this->algo = 1;

#line 391 "/opt/bah/map.bah"
this->length = 0;

#line 392 "/opt/bah/map.bah"
register long int i = 0;

#line 392 "/opt/bah/map.bah"
for (; (i<len(this->elems)); 
#line 392 "/opt/bah/map.bah"
++i) {

#line 393 "/opt/bah/map.bah"
struct mapElem* e = this->elems->data[i];

#line 394 "/opt/bah/map.bah"
if ((e!=null)) {

#line 395 "/opt/bah/map.bah"
this->set(this,e->key,e->val);
}
};

#line 398 "/opt/bah/map.bah"
this->elems = memoryAlloc(sizeof(array(struct mapElem*)));

this->elems->length = 0;
this->elems->elemSize = sizeof(struct mapElem*);
}

#line 399 "/opt/bah/map.bah"
else if ((nb==2)) {

#line 400 "/opt/bah/map.bah"
this->nbDelete = 0;

#line 401 "/opt/bah/map.bah"
mapWrapper__grow(this,this->length);

#line 402 "/opt/bah/map.bah"
this->set = mapWrapper__set2;

#line 403 "/opt/bah/map.bah"
this->get = mapWrapper__get2;

#line 404 "/opt/bah/map.bah"
this->delete = mapWrapper__delete2;

#line 405 "/opt/bah/map.bah"
this->algo = 2;

#line 406 "/opt/bah/map.bah"
this->length = 0;

#line 407 "/opt/bah/map.bah"
struct mapNode* current = this->nodes;

#line 408 "/opt/bah/map.bah"
array(struct mapNode*)* stack = memoryAlloc(sizeof(array(struct mapNode*)));

stack->length = 0;
stack->elemSize = sizeof(struct mapNode*);

#line 409 "/opt/bah/map.bah"
while ((current!=null)) {

#line 410 "/opt/bah/map.bah"
while ((current->left!=null)) {

#line 411 "/opt/bah/map.bah"

    unsigned int ____BAH_COMPILER_VAR_42 = len(stack);
    __Bah_realocate_arr(stack, ____BAH_COMPILER_VAR_42);
    stack->data[____BAH_COMPILER_VAR_42] = current;

#line 412 "/opt/bah/map.bah"
current = current->left;
};

#line 414 "/opt/bah/map.bah"
if ((current->value!=null)) {

#line 415 "/opt/bah/map.bah"
this->set(this,current->str,current->value);
}

#line 417 "/opt/bah/map.bah"
while ((current->right==null)&&(len(stack)>0)) {

#line 418 "/opt/bah/map.bah"
current = stack->data[len(stack)-1];

#line 419 "/opt/bah/map.bah"
delete(stack,len(stack)-1);

#line 420 "/opt/bah/map.bah"
if ((current->value!=null)) {

#line 421 "/opt/bah/map.bah"
this->set(this,current->str,current->value);
}
};

#line 424 "/opt/bah/map.bah"
current = current->right;
};

#line 426 "/opt/bah/map.bah"
this->nodes = null;
}

#line 428 "/opt/bah/map.bah"
this->changingAlgo = false;
};

#line 433 "/opt/bah/map.bah"
struct mapWrapper* mapWrapper(){

#line 434 "/opt/bah/map.bah"
struct mapWrapper* ____BAH_COMPILER_VAR_43 = memoryAlloc(sizeof(struct mapWrapper));
____BAH_COMPILER_VAR_43->algo = 2;
____BAH_COMPILER_VAR_43->elems = memoryAlloc(sizeof(array(struct mapElem*)));
            ____BAH_COMPILER_VAR_43->elems->length = 0;
            ____BAH_COMPILER_VAR_43->elems->elemSize = sizeof(struct mapElem*);
            ____BAH_COMPILER_VAR_43->nbTotal = 1;
struct mapWrapper* m = ____BAH_COMPILER_VAR_43;

#line 435 "/opt/bah/map.bah"
m->algo = 2;

#line 436 "/opt/bah/map.bah"
m->set = mapWrapper__set2;

#line 437 "/opt/bah/map.bah"
m->get = mapWrapper__get2;

#line 438 "/opt/bah/map.bah"
m->delete = mapWrapper__delete2;

#line 439 "/opt/bah/map.bah"
mapWrapper__grow(m,50);

#line 440 "/opt/bah/map.bah"
return m;
};

#line 444 "/opt/bah/map.bah"
void deleteMap(void * m,char * k){

#line 445 "/opt/bah/map.bah"
struct mapWrapper* mm = m;

#line 446 "/opt/bah/map.bah"
mm->delete(mm,k);
};

#line 1 "/home/alois/Documents/bah-bah/src/main.bah"

#line 1 "/opt/bah/iostream.bah"
#include <stdlib.h>

#line 2 "/opt/bah/iostream.bah"
#include <stdio.h>

#line 3 "/opt/bah/iostream.bah"
#include <dirent.h>

#line 6 "/opt/bah/iostream.bah"

#line 1 "/opt/bah/cBinds.bah"

#line 2 "/opt/bah/cBinds.bah"

#line 3 "/opt/bah/cBinds.bah"

#line 4 "/opt/bah/cBinds.bah"

#line 5 "/opt/bah/cBinds.bah"

#line 6 "/opt/bah/cBinds.bah"

#line 7 "/opt/bah/cBinds.bah"

#line 8 "/opt/bah/cBinds.bah"

#line 9 "/opt/bah/cBinds.bah"

#line 10 "/opt/bah/cBinds.bah"

#line 11 "/opt/bah/cBinds.bah"

#line 14 "/opt/bah/cBinds.bah"

#line 16 "/opt/bah/cBinds.bah"

#line 17 "/opt/bah/cBinds.bah"

#line 18 "/opt/bah/cBinds.bah"

#line 19 "/opt/bah/cBinds.bah"

#line 20 "/opt/bah/cBinds.bah"

#line 21 "/opt/bah/cBinds.bah"

#line 22 "/opt/bah/cBinds.bah"

#line 23 "/opt/bah/cBinds.bah"

#line 24 "/opt/bah/cBinds.bah"

#line 25 "/opt/bah/cBinds.bah"

#line 26 "/opt/bah/cBinds.bah"

#line 27 "/opt/bah/cBinds.bah"

#line 28 "/opt/bah/cBinds.bah"

#line 29 "/opt/bah/cBinds.bah"

#line 7 "/opt/bah/iostream.bah"

#line 10 "/opt/bah/iostream.bah"

#line 12 "/opt/bah/iostream.bah"
char * __Bah_iostream_stdinputBuffer;

#line 13 "/opt/bah/iostream.bah"
long int __Bah_iostream_stdinputBufferLength;

#line 16 "/opt/bah/iostream.bah"
char * stdinput(){

#line 17 "/opt/bah/iostream.bah"
char * response = "";

#line 18 "/opt/bah/iostream.bah"
register long int nDataLength = 0;

#line 19 "/opt/bah/iostream.bah"
if ((__Bah_iostream_stdinputBufferLength>0)) {

#line 20 "/opt/bah/iostream.bah"
response = __Bah_iostream_stdinputBuffer;

#line 21 "/opt/bah/iostream.bah"
nDataLength = __Bah_iostream_stdinputBufferLength;
}

#line 22 "/opt/bah/iostream.bah"
else {

#line 23 "/opt/bah/iostream.bah"
char * buff = memoryAlloc(1025);

#line 24 "/opt/bah/iostream.bah"
nDataLength = read((void *)0,buff,1024);

#line 25 "/opt/bah/iostream.bah"
if ((nDataLength<1024)) {

#line 26 "/opt/bah/iostream.bah"
char** ____BAH_COMPILER_VAR_44 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_44[1] = buff;____BAH_COMPILER_VAR_44[0] = response;char * ____BAH_COMPILER_VAR_45 =__Bah_multiple_concat(____BAH_COMPILER_VAR_44, 2);response = ____BAH_COMPILER_VAR_45;
}

#line 27 "/opt/bah/iostream.bah"
else {

#line 28 "/opt/bah/iostream.bah"
while ((nDataLength>0)) {

#line 29 "/opt/bah/iostream.bah"
char** ____BAH_COMPILER_VAR_46 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_46[1] = buff;____BAH_COMPILER_VAR_46[0] = response;char * ____BAH_COMPILER_VAR_47 =__Bah_multiple_concat(____BAH_COMPILER_VAR_46, 2);response = ____BAH_COMPILER_VAR_47;

#line 30 "/opt/bah/iostream.bah"
if ((nDataLength<1024)) {

#line 31 "/opt/bah/iostream.bah"
long int trimAmm = 1024-nDataLength;

#line 32 "/opt/bah/iostream.bah"
strTrimRight(&response,trimAmm);

#line 33 "/opt/bah/iostream.bah"
break;
}

#line 34 "/opt/bah/iostream.bah"
else {

#line 35 "/opt/bah/iostream.bah"
nDataLength = read((void *)0,buff,1024);
}
};
}
}

#line 40 "/opt/bah/iostream.bah"
if ((response[nDataLength-1]==(char)10)) {

#line 41 "/opt/bah/iostream.bah"
strTrimRight(&response,1);
}

#line 44 "/opt/bah/iostream.bah"
register long int i = 0;

#line 44 "/opt/bah/iostream.bah"
for (; (i<nDataLength); 
#line 44 "/opt/bah/iostream.bah"
++i) {

#line 45 "/opt/bah/iostream.bah"
if ((response[i]==(char)10)) {

#line 46 "/opt/bah/iostream.bah"
__Bah_iostream_stdinputBuffer = cpstringSubsitute(response, i+1, strlen(response));

#line 47 "/opt/bah/iostream.bah"
__Bah_iostream_stdinputBufferLength = nDataLength-i;

#line 48 "/opt/bah/iostream.bah"
return cpstringSubsitute(response, 0, i);
}
};

#line 52 "/opt/bah/iostream.bah"
__Bah_iostream_stdinputBuffer = "";

#line 53 "/opt/bah/iostream.bah"
__Bah_iostream_stdinputBufferLength = 0;

#line 55 "/opt/bah/iostream.bah"
return response;
};

#line 59 "/opt/bah/iostream.bah"
void println(char * s){

#line 60 "/opt/bah/iostream.bah"
char** ____BAH_COMPILER_VAR_48 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_48[1] = "\n";____BAH_COMPILER_VAR_48[0] = s;char * ____BAH_COMPILER_VAR_49 =__Bah_multiple_concat(____BAH_COMPILER_VAR_48, 2);write((void *)1,____BAH_COMPILER_VAR_49,strlen(s)+1);
};

#line 63 "/opt/bah/iostream.bah"

#line 64 "/opt/bah/iostream.bah"

#line 65 "/opt/bah/iostream.bah"

#line 66 "/opt/bah/iostream.bah"

#line 67 "/opt/bah/iostream.bah"

#line 73 "/opt/bah/iostream.bah"
struct fileStream {
FILE* handle;
char * name;
};
long int fileStream__isValid(struct fileStream* this){

#line 79 "/opt/bah/iostream.bah"
if ((this->handle==null)) {

#line 80 "/opt/bah/iostream.bah"
return 0;
}

#line 82 "/opt/bah/iostream.bah"
return 1;
};
void fileStream__open(struct fileStream* this,char * path,char * mode){

#line 88 "/opt/bah/iostream.bah"
this->name = path;

#line 89 "/opt/bah/iostream.bah"
this->handle = fopen(path,mode);
};
void fileStream__close(struct fileStream* this){

#line 94 "/opt/bah/iostream.bah"
if ((fileStream__isValid(this)==0)) {

#line 95 "/opt/bah/iostream.bah"
return;
}

#line 97 "/opt/bah/iostream.bah"
fclose(this->handle);

#line 98 "/opt/bah/iostream.bah"
this->handle = null;
};
long int fileStream__getPos(struct fileStream* this){

#line 103 "/opt/bah/iostream.bah"
if ((fileStream__isValid(this)==0)) {

#line 104 "/opt/bah/iostream.bah"
return 0;
}

#line 106 "/opt/bah/iostream.bah"
return ftell(this->handle);
};
void fileStream__setPos(struct fileStream* this,long int i){

#line 111 "/opt/bah/iostream.bah"
if ((fileStream__isValid(this)==0)) {

#line 112 "/opt/bah/iostream.bah"
return;
}

#line 114 "/opt/bah/iostream.bah"
fseek(this->handle,i,0);
};
long int fileStream__getSize(struct fileStream* this){

#line 119 "/opt/bah/iostream.bah"
if ((fileStream__isValid(this)==0)) {

#line 120 "/opt/bah/iostream.bah"
return -1;
}

#line 122 "/opt/bah/iostream.bah"
long int oldPos = fileStream__getPos(this);

#line 123 "/opt/bah/iostream.bah"
fseek(this->handle,0,2);

#line 124 "/opt/bah/iostream.bah"
long int size = ftell(this->handle);

#line 125 "/opt/bah/iostream.bah"
fileStream__setPos(this,oldPos);

#line 126 "/opt/bah/iostream.bah"
return size;
};
void fileStream__rewind(struct fileStream* this){

#line 131 "/opt/bah/iostream.bah"
rewind(this->handle);
};
char fileStream__getChar(struct fileStream* this){

#line 136 "/opt/bah/iostream.bah"
char c = getc(this->handle);

#line 137 "/opt/bah/iostream.bah"
return c;
};
void fileStream__setChar(struct fileStream* this,char c){

#line 142 "/opt/bah/iostream.bah"
fputc(c,this->handle);
};
void fileStream__createFile(struct fileStream* this,char * path){

#line 147 "/opt/bah/iostream.bah"
fileStream__open(this,path,"w");

#line 148 "/opt/bah/iostream.bah"
fileStream__close(this);
};
long int fileStream__writeFile(struct fileStream* this,char * content){

#line 153 "/opt/bah/iostream.bah"
if ((fileStream__isValid(this)==0)) {

#line 154 "/opt/bah/iostream.bah"
return -1;
}

#line 157 "/opt/bah/iostream.bah"
fputs(content,this->handle);

#line 159 "/opt/bah/iostream.bah"
return 1;
};
void fileStream__writePtr(struct fileStream* this,void * a,long int s){

#line 166 "/opt/bah/iostream.bah"
fwrite(a,s,1,this->handle);
};
long int fileStream__readPtr(struct fileStream* this,void * a,long int s){

#line 173 "/opt/bah/iostream.bah"
return fread(a,s,1,this->handle);
};
char * fileStream__readContent(struct fileStream* this){

#line 178 "/opt/bah/iostream.bah"
if ((fileStream__isValid(this)==0)) {

#line 179 "/opt/bah/iostream.bah"
return "invalid";
}

#line 182 "/opt/bah/iostream.bah"
long int sz = fileStream__getSize(this);

#line 183 "/opt/bah/iostream.bah"
char * r = memoryAllocSTR(sz+1);

#line 184 "/opt/bah/iostream.bah"
long int l = fread(r,1,sz,this->handle);

#line 185 "/opt/bah/iostream.bah"
if ((sz!=l)) {

#line 186 "/opt/bah/iostream.bah"
array(char)* rarr = strAsArr(r);

#line 187 "/opt/bah/iostream.bah"

    unsigned int ____BAH_COMPILER_VAR_50 = l;
    __Bah_realocate_arr(rarr, ____BAH_COMPILER_VAR_50);
    rarr->data[____BAH_COMPILER_VAR_50] = (char)0;
}

#line 189 "/opt/bah/iostream.bah"
return r;
};
__BAH_ARR_TYPE_char fileStream__readBytes(struct fileStream* this){

#line 194 "/opt/bah/iostream.bah"
array(char)* r = memoryAlloc(sizeof(array(char)));

r->length = 0;
r->elemSize = sizeof(char);

#line 195 "/opt/bah/iostream.bah"
allocateArray(r,fileStream__getSize(this));

#line 197 "/opt/bah/iostream.bah"
fileStream__readPtr(this,r->data,len(r));

#line 199 "/opt/bah/iostream.bah"
return r;
};
void fileStream__writeBytes(struct fileStream* this,__BAH_ARR_TYPE_char d){

#line 204 "/opt/bah/iostream.bah"
fileStream__writePtr(this,d->data,len(d));
};
void fileStream___end(struct fileStream* this){

#line 208 "/opt/bah/iostream.bah"
if (fileStream__isValid(this)) {

#line 209 "/opt/bah/iostream.bah"
char** ____BAH_COMPILER_VAR_51 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_51[2] = "'.";____BAH_COMPILER_VAR_51[1] = this->name;____BAH_COMPILER_VAR_51[0] = "iostream: warning, auto-closing file: '";char * ____BAH_COMPILER_VAR_52 =__Bah_multiple_concat(____BAH_COMPILER_VAR_51, 3);println(____BAH_COMPILER_VAR_52);

#line 210 "/opt/bah/iostream.bah"
fileStream__close(this);
}
};

#line 216 "/opt/bah/iostream.bah"

#line 222 "/opt/bah/iostream.bah"

#line 223 "/opt/bah/iostream.bah"

#line 224 "/opt/bah/iostream.bah"

#line 225 "/opt/bah/iostream.bah"

#line 226 "/opt/bah/iostream.bah"

#line 227 "/opt/bah/iostream.bah"

#line 229 "/opt/bah/iostream.bah"

#line 235 "/opt/bah/iostream.bah"
struct fileMap {
long int handle;
long int size;
void * p;
};
char * fileMap__open(struct fileMap* this,char * fileName){

#line 243 "/opt/bah/iostream.bah"

#line 244 "/opt/bah/iostream.bah"
this->handle = open(fileName,O_RDWR,S_IRUSR|S_IWUSR);

#line 245 "/opt/bah/iostream.bah"
struct stat ____BAH_COMPILER_VAR_53 = {};
struct stat sb = ____BAH_COMPILER_VAR_53;

#line 246 "/opt/bah/iostream.bah"
fstat(this->handle,&sb);

#line 247 "/opt/bah/iostream.bah"
this->size = sb.st_size;

#line 248 "/opt/bah/iostream.bah"
this->p = mmap(0,sb.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,this->handle,0);

#line 249 "/opt/bah/iostream.bah"
return this->p;

#line 251 "/opt/bah/iostream.bah"

#line 260 "/opt/bah/iostream.bah"
};
long int fileMap__isValid(struct fileMap* this){

#line 279 "/opt/bah/iostream.bah"
if ((this->handle<0)) {

#line 280 "/opt/bah/iostream.bah"
return 0;
}

#line 282 "/opt/bah/iostream.bah"
return 1;
};
void fileMap__close(struct fileMap* this){

#line 287 "/opt/bah/iostream.bah"

#line 288 "/opt/bah/iostream.bah"
if ((this->handle==-1)) {

#line 289 "/opt/bah/iostream.bah"
return;
}

#line 291 "/opt/bah/iostream.bah"
munmap(this->p,this->size);

#line 292 "/opt/bah/iostream.bah"
close(this->handle);

#line 294 "/opt/bah/iostream.bah"
};

#line 304 "/opt/bah/iostream.bah"

#line 306 "/opt/bah/iostream.bah"

#line 310 "/opt/bah/iostream.bah"

#line 311 "/opt/bah/iostream.bah"

#line 312 "/opt/bah/iostream.bah"

#line 315 "/opt/bah/iostream.bah"
__BAH_ARR_TYPE_cpstring listFiles(char * dir){

#line 316 "/opt/bah/iostream.bah"
array(char *)* files = memoryAlloc(sizeof(array(char *)));

files->length = 0;
files->elemSize = sizeof(char *);

#line 317 "/opt/bah/iostream.bah"
DIR* d = opendir(dir);

#line 318 "/opt/bah/iostream.bah"
struct dirent* file = readdir(d);

#line 319 "/opt/bah/iostream.bah"
while ((file!=null)) {

#line 320 "/opt/bah/iostream.bah"
long int lf = len(files);

#line 321 "/opt/bah/iostream.bah"
if ((strcmp(file->d_name,".")==0)) {

#line 322 "/opt/bah/iostream.bah"
file = readdir(d);

#line 323 "/opt/bah/iostream.bah"
continue;
}

#line 325 "/opt/bah/iostream.bah"
if ((strcmp(file->d_name,"..")==0)) {

#line 326 "/opt/bah/iostream.bah"
file = readdir(d);

#line 327 "/opt/bah/iostream.bah"
continue;
}

#line 329 "/opt/bah/iostream.bah"

    unsigned int ____BAH_COMPILER_VAR_54 = lf;
    __Bah_realocate_arr(files, ____BAH_COMPILER_VAR_54);
    files->data[____BAH_COMPILER_VAR_54] = __STR(file->d_name);

#line 330 "/opt/bah/iostream.bah"
file = readdir(d);
};

#line 332 "/opt/bah/iostream.bah"
closedir(d);

#line 333 "/opt/bah/iostream.bah"
return files;
};

#line 336 "/opt/bah/iostream.bah"

#line 339 "/opt/bah/iostream.bah"
long int fileExists(char * path){

#line 340 "/opt/bah/iostream.bah"
long int is = access(path,0);

#line 341 "/opt/bah/iostream.bah"
if ((is==0)) {

#line 342 "/opt/bah/iostream.bah"
return 1;
}

#line 344 "/opt/bah/iostream.bah"
return 0;
};

#line 347 "/opt/bah/iostream.bah"
char isFolder(char * path){

#line 348 "/opt/bah/iostream.bah"
struct stat s;

#line 349 "/opt/bah/iostream.bah"
if ((stat(path,&s)!=0)) {

#line 350 "/opt/bah/iostream.bah"
return false;
}

#line 352 "/opt/bah/iostream.bah"
if (s.st_mode&S_IFDIR) {

#line 353 "/opt/bah/iostream.bah"
return true;
}

#line 355 "/opt/bah/iostream.bah"
return false;
};

#line 358 "/opt/bah/iostream.bah"

#line 361 "/opt/bah/iostream.bah"
char removeFile(char * name){

#line 362 "/opt/bah/iostream.bah"
if ((remove(name)==0)) {

#line 363 "/opt/bah/iostream.bah"
return true;
}

#line 365 "/opt/bah/iostream.bah"
return false;
};

#line 369 "/opt/bah/iostream.bah"
long int getLastModified(char * name){

#line 370 "/opt/bah/iostream.bah"
struct stat attr;

#line 371 "/opt/bah/iostream.bah"
stat(name,&attr);

#line 372 "/opt/bah/iostream.bah"
return attr.st_ctime;
};

#line 375 "/opt/bah/iostream.bah"

#line 376 "/opt/bah/iostream.bah"

#line 377 "/opt/bah/iostream.bah"

#line 380 "/opt/bah/iostream.bah"

#line 2 "/home/alois/Documents/bah-bah/src/main.bah"

#line 1 "/opt/bah/flags.bah"

#line 2 "/opt/bah/flags.bah"

#line 3 "/opt/bah/flags.bah"

#line 1 "/opt/bah/string.bah"
#include <string.h>

#line 2 "/opt/bah/string.bah"
#include <math.h>

#line 3 "/opt/bah/string.bah"
#include <stdlib.h>

#line 5 "/opt/bah/string.bah"

#line 7 "/opt/bah/string.bah"

#line 9 "/opt/bah/string.bah"

#line 10 "/opt/bah/string.bah"

#line 11 "/opt/bah/string.bah"

#line 12 "/opt/bah/string.bah"

#line 13 "/opt/bah/string.bah"

#line 14 "/opt/bah/string.bah"

#line 15 "/opt/bah/string.bah"

#line 18 "/opt/bah/string.bah"
void strCatOffset(char * dest,long int destLen,char * src,long int srcLen){

#line 19 "/opt/bah/string.bah"
memcpy(dest+destLen,src,srcLen);
};

#line 23 "/opt/bah/string.bah"
char * charToString(char c){

#line 24 "/opt/bah/string.bah"
char * s = memoryAlloc(2);

#line 25 "/opt/bah/string.bah"
strncpy(s,(char *)&c,1);

#line 26 "/opt/bah/string.bah"
return s;
};

#line 30 "/opt/bah/string.bah"
char isUpper(char c){

#line 31 "/opt/bah/string.bah"
return (c>=65)&&(c<=90);
};

#line 35 "/opt/bah/string.bah"
char isLower(char c){

#line 36 "/opt/bah/string.bah"
return (c>=97)&&(c<=122);
};

#line 40 "/opt/bah/string.bah"
char isLetter(char s){

#line 41 "/opt/bah/string.bah"
return isLower(s)||isUpper(s);
};

#line 45 "/opt/bah/string.bah"
char isNumber(char c){

#line 46 "/opt/bah/string.bah"
return (c>=48)&&(c<=57);
};

#line 51 "/opt/bah/string.bah"
char isAlphaNumeric(char s){

#line 52 "/opt/bah/string.bah"
return isLetter(s)||isNumber(s);
};

#line 56 "/opt/bah/string.bah"
char isSpace(char c){

#line 57 "/opt/bah/string.bah"
return (c==(char)32)||(c==(char)9)||(c==(char)10)||(c==(char)11)||(c==(char)13);
};

#line 61 "/opt/bah/string.bah"
struct string {
char * content;
char editable;
long int length;
};
void string__set(struct string* this,char * s){

#line 71 "/opt/bah/string.bah"
this->length = strlen(s);

#line 72 "/opt/bah/string.bah"
this->editable = false;

#line 73 "/opt/bah/string.bah"
this->content = s;
};
void string__makeEditable(struct string* this){

#line 80 "/opt/bah/string.bah"
this->editable = true;

#line 81 "/opt/bah/string.bah"
char * old = this->content;

#line 82 "/opt/bah/string.bah"
this->content = (char *)memoryAlloc(this->length+1);

#line 83 "/opt/bah/string.bah"
strncpy(this->content,old,this->length);
};
void string__append(struct string* this,char * s){

#line 88 "/opt/bah/string.bah"
if ((this->editable==false)) {

#line 89 "/opt/bah/string.bah"
string__makeEditable(this);
}

#line 91 "/opt/bah/string.bah"
long int sl = strlen(s);

#line 92 "/opt/bah/string.bah"
long int nl = sl+this->length;

#line 93 "/opt/bah/string.bah"
void * nc = memoryRealloc(this->content,nl+1);

#line 94 "/opt/bah/string.bah"
if (__builtin_expect((nc==null), 0)) {

#line 95 "/opt/bah/string.bah"
__BAH_panic("Error appending to string, possibly due to memory shortage.","/opt/bah/string.bah:95");
}

#line 97 "/opt/bah/string.bah"
this->content = nc;

#line 98 "/opt/bah/string.bah"
strCatOffset(this->content,this->length,s,sl+1);

#line 99 "/opt/bah/string.bah"
this->length = nl;
};
void string__prepend(struct string* this,char * s){

#line 104 "/opt/bah/string.bah"
this->editable = true;

#line 105 "/opt/bah/string.bah"
long int sl = strlen(s);

#line 106 "/opt/bah/string.bah"
long int nl = this->length+sl;

#line 107 "/opt/bah/string.bah"
char * tmpS = this->content;

#line 108 "/opt/bah/string.bah"
void * nc = memoryAlloc(nl+1);

#line 109 "/opt/bah/string.bah"
if (__builtin_expect((nc==null), 0)) {

#line 110 "/opt/bah/string.bah"
__BAH_panic("Error appending to string, possibly due to memory shortage.","/opt/bah/string.bah:110");
}

#line 112 "/opt/bah/string.bah"
this->content = nc;

#line 113 "/opt/bah/string.bah"
strncpy(this->content,s,sl);

#line 114 "/opt/bah/string.bah"
strCatOffset(this->content,sl,tmpS,this->length+1);

#line 115 "/opt/bah/string.bah"
this->length = nl;
};
char string__charAt(struct string* this,long int i){

#line 120 "/opt/bah/string.bah"
return this->content[i];
};
long int string__compare(struct string* this,char * s){

#line 125 "/opt/bah/string.bah"
return (strcmp(this->content,s)==0);
};
char * string__str(struct string* this){

#line 130 "/opt/bah/string.bah"
return this->content;
};
void string__replace(struct string* this,char * nd,char * rl){

#line 135 "/opt/bah/string.bah"
if ((this->editable==false)) {

#line 136 "/opt/bah/string.bah"
string__makeEditable(this);
}

#line 138 "/opt/bah/string.bah"
struct string ____BAH_COMPILER_VAR_55 = {};
struct string needle = ____BAH_COMPILER_VAR_55;

#line 139 "/opt/bah/string.bah"
string__set(&needle,nd);

#line 140 "/opt/bah/string.bah"
struct string ____BAH_COMPILER_VAR_56 = {};
struct string repl = ____BAH_COMPILER_VAR_56;

#line 141 "/opt/bah/string.bah"
string__set(&repl,rl);

#line 142 "/opt/bah/string.bah"
register long int i = 0;

#line 143 "/opt/bah/string.bah"
long int si = 0;

#line 145 "/opt/bah/string.bah"
long int replcBuffSart = 0;

#line 146 "/opt/bah/string.bah"
long int replcBuffLength = 0;

#line 148 "/opt/bah/string.bah"
array(char)* buff = memoryAlloc(sizeof(array(char)));

buff->length = 0;
buff->elemSize = sizeof(char);

#line 150 "/opt/bah/string.bah"
while ((i<this->length)) {

#line 151 "/opt/bah/string.bah"
char c = string__charAt(this,i);

#line 152 "/opt/bah/string.bah"
char rc = string__charAt(&needle,si);

#line 154 "/opt/bah/string.bah"
if ((c==rc)) {

#line 155 "/opt/bah/string.bah"
si = si+1;

#line 156 "/opt/bah/string.bah"
if ((replcBuffLength==0)) {

#line 157 "/opt/bah/string.bah"
replcBuffSart = i;
}

#line 159 "/opt/bah/string.bah"
replcBuffLength = replcBuffLength+1;
}

#line 160 "/opt/bah/string.bah"
else {

#line 161 "/opt/bah/string.bah"
if ((replcBuffLength>0)) {

#line 162 "/opt/bah/string.bah"
si = 0;

#line 163 "/opt/bah/string.bah"
register long int j = 0;

#line 163 "/opt/bah/string.bah"
while ((j<replcBuffLength)) {

#line 164 "/opt/bah/string.bah"

    unsigned int ____BAH_COMPILER_VAR_57 = len(buff);
    __Bah_realocate_arr(buff, ____BAH_COMPILER_VAR_57);
    buff->data[____BAH_COMPILER_VAR_57] = string__charAt(this,j+replcBuffSart);

#line 165 "/opt/bah/string.bah"
j = j+1;
};

#line 167 "/opt/bah/string.bah"
replcBuffLength = 0;
}

#line 169 "/opt/bah/string.bah"

    unsigned int ____BAH_COMPILER_VAR_58 = len(buff);
    __Bah_realocate_arr(buff, ____BAH_COMPILER_VAR_58);
    buff->data[____BAH_COMPILER_VAR_58] = c;
}

#line 172 "/opt/bah/string.bah"
if ((si==needle.length)) {

#line 173 "/opt/bah/string.bah"
replcBuffLength = 0;

#line 174 "/opt/bah/string.bah"
register long int ii = 0;

#line 174 "/opt/bah/string.bah"
while ((ii<repl.length)) {

#line 175 "/opt/bah/string.bah"
long int a = ii;

#line 176 "/opt/bah/string.bah"

    unsigned int ____BAH_COMPILER_VAR_59 = len(buff);
    __Bah_realocate_arr(buff, ____BAH_COMPILER_VAR_59);
    buff->data[____BAH_COMPILER_VAR_59] = string__charAt(&repl,ii);

#line 177 "/opt/bah/string.bah"
ii = ii+1;
};

#line 179 "/opt/bah/string.bah"
si = 0;
}

#line 182 "/opt/bah/string.bah"
i = i+1;
};

#line 185 "/opt/bah/string.bah"
char * r = arrToStr(buff);

#line 186 "/opt/bah/string.bah"
if ((replcBuffLength>0)) {

#line 187 "/opt/bah/string.bah"
array(char)* replbuffStr = memoryAlloc(sizeof(array(char)));

replbuffStr->length = 0;
replbuffStr->elemSize = sizeof(char);

#line 188 "/opt/bah/string.bah"
allocateArray(replbuffStr,replcBuffLength+1);

#line 189 "/opt/bah/string.bah"
register long int j = 0;

#line 189 "/opt/bah/string.bah"
while ((j<replcBuffLength)) {

#line 190 "/opt/bah/string.bah"

    unsigned int ____BAH_COMPILER_VAR_60 = j;
    __Bah_realocate_arr(replbuffStr, ____BAH_COMPILER_VAR_60);
    replbuffStr->data[____BAH_COMPILER_VAR_60] = string__charAt(this,j+replcBuffSart);

#line 191 "/opt/bah/string.bah"
j = j+1;
};

#line 193 "/opt/bah/string.bah"
char** ____BAH_COMPILER_VAR_61 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_61[1] = arrAsStr(replbuffStr);____BAH_COMPILER_VAR_61[0] = r;char * ____BAH_COMPILER_VAR_62 =__Bah_multiple_concat(____BAH_COMPILER_VAR_61, 2);r = ____BAH_COMPILER_VAR_62;
}

#line 195 "/opt/bah/string.bah"
if (((void *)r!=null)) {

#line 196 "/opt/bah/string.bah"
string__set(this,r);
}
};
long int string__countChar(struct string* this,char need){

#line 202 "/opt/bah/string.bah"
long int c = 0;

#line 203 "/opt/bah/string.bah"
register long int i = 0;

#line 203 "/opt/bah/string.bah"
for (; (i<this->length); 
#line 203 "/opt/bah/string.bah"
++i) {

#line 204 "/opt/bah/string.bah"
if ((string__charAt(this,i)==need)) {

#line 205 "/opt/bah/string.bah"
++c;
}
};

#line 208 "/opt/bah/string.bah"
return c;
};
long int string__count(struct string* this,char * need){

#line 213 "/opt/bah/string.bah"
if ((strlen(need)==1)) {

#line 214 "/opt/bah/string.bah"
return string__countChar(this,need[0]);
}

#line 216 "/opt/bah/string.bah"
register long int i = 0;

#line 217 "/opt/bah/string.bah"
long int count = 0;

#line 218 "/opt/bah/string.bah"
struct string ____BAH_COMPILER_VAR_63 = {};
struct string needle = ____BAH_COMPILER_VAR_63;

#line 219 "/opt/bah/string.bah"
string__set(&needle,need);

#line 220 "/opt/bah/string.bah"
long int countIndex = 0;

#line 221 "/opt/bah/string.bah"
while ((i<this->length)) {

#line 222 "/opt/bah/string.bah"
char c = string__charAt(this,i);

#line 223 "/opt/bah/string.bah"
char sc = string__charAt(&needle,countIndex);

#line 224 "/opt/bah/string.bah"
if ((c==sc)) {

#line 225 "/opt/bah/string.bah"
countIndex = countIndex+1;
}

#line 226 "/opt/bah/string.bah"
else {

#line 227 "/opt/bah/string.bah"
countIndex = 0;
}

#line 229 "/opt/bah/string.bah"
if ((countIndex==needle.length)) {

#line 230 "/opt/bah/string.bah"
count = count+1;

#line 231 "/opt/bah/string.bah"
countIndex = 0;
}

#line 233 "/opt/bah/string.bah"
i = i+1;
};

#line 235 "/opt/bah/string.bah"
return count;
};
long int string__hasPrefix(struct string* this,char * need){

#line 240 "/opt/bah/string.bah"
register long int i = 0;

#line 241 "/opt/bah/string.bah"
long int nl = strlen(need);

#line 242 "/opt/bah/string.bah"
if ((this->length<nl)) {

#line 243 "/opt/bah/string.bah"
return 0;
}

#line 245 "/opt/bah/string.bah"
while ((i<nl)) {

#line 246 "/opt/bah/string.bah"
char c = string__charAt(this,i);

#line 247 "/opt/bah/string.bah"
char sc = cpstringCharAt(need,i);

#line 248 "/opt/bah/string.bah"
if ((c!=sc)) {

#line 249 "/opt/bah/string.bah"
return 0;
}

#line 251 "/opt/bah/string.bah"
i = i+1;
};

#line 253 "/opt/bah/string.bah"
return 1;
};
long int string__hasSuffix(struct string* this,char * need){

#line 258 "/opt/bah/string.bah"
long int nl = strlen(need);

#line 259 "/opt/bah/string.bah"
if ((this->length<nl)) {

#line 260 "/opt/bah/string.bah"
return 0;
}

#line 262 "/opt/bah/string.bah"
register long int i = this->length-nl;

#line 263 "/opt/bah/string.bah"
long int needleIndex = 0;

#line 264 "/opt/bah/string.bah"
while ((i<this->length)) {

#line 265 "/opt/bah/string.bah"
char c = string__charAt(this,i);

#line 266 "/opt/bah/string.bah"
char sc = cpstringCharAt(need,needleIndex);

#line 267 "/opt/bah/string.bah"
if ((c!=sc)) {

#line 268 "/opt/bah/string.bah"
return 0;
}

#line 270 "/opt/bah/string.bah"
needleIndex = needleIndex+1;

#line 271 "/opt/bah/string.bah"
i = i+1;
};

#line 274 "/opt/bah/string.bah"
return 1;
};
void string__trim(struct string* this){

#line 280 "/opt/bah/string.bah"
if ((this->length==0)) {

#line 281 "/opt/bah/string.bah"
return;
}

#line 283 "/opt/bah/string.bah"
char fc = string__charAt(this,0);

#line 284 "/opt/bah/string.bah"
if ((isSpace(fc)==false)) {

#line 285 "/opt/bah/string.bah"
return;
}

#line 287 "/opt/bah/string.bah"
register long int i = 0;

#line 287 "/opt/bah/string.bah"
for (; (i<this->length); 
#line 287 "/opt/bah/string.bah"
++i) {

#line 288 "/opt/bah/string.bah"
if ((isSpace(string__charAt(this,i))==false)) {

#line 289 "/opt/bah/string.bah"
break;
}
};

#line 292 "/opt/bah/string.bah"
if ((i>0)) {

#line 293 "/opt/bah/string.bah"
this->length = this->length-i;

#line 294 "/opt/bah/string.bah"
char * tmpS = memoryAlloc(this->length+1);

#line 295 "/opt/bah/string.bah"
memcpy(tmpS,this->content+i,this->length+1);

#line 296 "/opt/bah/string.bah"
this->content = tmpS;

#line 297 "/opt/bah/string.bah"
this->editable = true;
}
};
void string__trimLeft(struct string* this,long int s){

#line 303 "/opt/bah/string.bah"
if ((s>this->length)) {

#line 304 "/opt/bah/string.bah"
return;
}

#line 306 "/opt/bah/string.bah"
long int nSize = this->length-s;

#line 307 "/opt/bah/string.bah"
void * tmpS = memoryAlloc(nSize+1);

#line 308 "/opt/bah/string.bah"
memcpy(tmpS,this->content+s,nSize);

#line 309 "/opt/bah/string.bah"
this->content = tmpS;

#line 310 "/opt/bah/string.bah"
this->editable = true;

#line 311 "/opt/bah/string.bah"
this->length = nSize;
};
void string__trimRight(struct string* this,long int s){

#line 316 "/opt/bah/string.bah"
if ((s>this->length)) {

#line 317 "/opt/bah/string.bah"
return;
}

#line 319 "/opt/bah/string.bah"
long int nSize = this->length-s;

#line 320 "/opt/bah/string.bah"
void * tmpS = memoryAlloc(nSize+1);

#line 321 "/opt/bah/string.bah"
memcpy(tmpS,this->content,nSize);

#line 322 "/opt/bah/string.bah"
this->content = tmpS;

#line 323 "/opt/bah/string.bah"
this->editable = true;

#line 324 "/opt/bah/string.bah"
this->length = nSize;
};
struct string string__add(struct string* this,struct string s2){

#line 330 "/opt/bah/string.bah"
struct string ____BAH_COMPILER_VAR_64 = {};
struct string r = ____BAH_COMPILER_VAR_64;

#line 331 "/opt/bah/string.bah"
r.length = this->length+s2.length;

#line 332 "/opt/bah/string.bah"
r.content = memoryAlloc(r.length+1);

#line 333 "/opt/bah/string.bah"
strncpy(r.content,this->content,this->length);

#line 334 "/opt/bah/string.bah"
strCatOffset(r.content,this->length,s2.content,s2.length);

#line 335 "/opt/bah/string.bah"
return r;
};
__BAH_ARR_TYPE_char string__asArr(struct string* this){

#line 340 "/opt/bah/string.bah"
if ((this->editable==false)) {

#line 341 "/opt/bah/string.bah"
string__makeEditable(this);
}

#line 343 "/opt/bah/string.bah"
array(char)* arr = memoryAlloc(sizeof(array(char)));

arr->length = 0;
arr->elemSize = sizeof(char);

#line 344 "/opt/bah/string.bah"
arr->data=this->content;

#line 345 "/opt/bah/string.bah"
arr->length=this->length;

#line 346 "/opt/bah/string.bah"
arr->realLength=this->length;

#line 347 "/opt/bah/string.bah"
return arr;
};

#line 353 "/opt/bah/string.bah"
struct string string(char * s){

#line 354 "/opt/bah/string.bah"
struct string ____BAH_COMPILER_VAR_65 = {};
struct string a = ____BAH_COMPILER_VAR_65;

#line 355 "/opt/bah/string.bah"
string__set(&a,s);

#line 356 "/opt/bah/string.bah"
return a;
};

#line 360 "/opt/bah/string.bah"
char * intToStr(long int i){

#line 361 "/opt/bah/string.bah"
if ((i==0)) {

#line 362 "/opt/bah/string.bah"
return "0";
}

#line 365 "/opt/bah/string.bah"
char ____BAH_COMPILER_VAR_66[66];char* s = ____BAH_COMPILER_VAR_66;

#line 366 "/opt/bah/string.bah"
long int ind = -1;

#line 368 "/opt/bah/string.bah"
char subZero = (i<0);

#line 370 "/opt/bah/string.bah"
if ((subZero==true)) {

#line 371 "/opt/bah/string.bah"
i = 0-i;
}

#line 374 "/opt/bah/string.bah"
for (; (i!=0); 
#line 374 "/opt/bah/string.bah"
i = i/10) {

#line 375 "/opt/bah/string.bah"
long int conv = i%10;

#line 376 "/opt/bah/string.bah"
conv = conv+48;

#line 377 "/opt/bah/string.bah"
s[ind+1] = (char)conv;

#line 378 "/opt/bah/string.bah"
++ind;
};

#line 381 "/opt/bah/string.bah"
if ((subZero==true)) {

#line 382 "/opt/bah/string.bah"
s[ind+1] = 45;

#line 383 "/opt/bah/string.bah"
++ind;
}

#line 385 "/opt/bah/string.bah"
long int ls = ind+1;

#line 386 "/opt/bah/string.bah"
i = 0;

#line 386 "/opt/bah/string.bah"
for (; (i<ls/2); 
#line 386 "/opt/bah/string.bah"
++i) {

#line 387 "/opt/bah/string.bah"
long int ii = ls-i-1;

#line 388 "/opt/bah/string.bah"
char osi = s[i];

#line 389 "/opt/bah/string.bah"
s[i] = s[ii];

#line 390 "/opt/bah/string.bah"
s[ii] = osi;
};

#line 393 "/opt/bah/string.bah"
s[ind+1] = (char)0;

#line 395 "/opt/bah/string.bah"
return __STR(s);
};

#line 400 "/opt/bah/string.bah"
struct string intToString(long int i){

#line 401 "/opt/bah/string.bah"
char * ____BAH_COMPILER_VAR_67 =intToStr(i);struct string r = string(____BAH_COMPILER_VAR_67);

#line 402 "/opt/bah/string.bah"
return r;
};

#line 406 "/opt/bah/string.bah"
char * floatToStr(double f){

#line 407 "/opt/bah/string.bah"
char ____BAH_COMPILER_VAR_68[50];char* buff = ____BAH_COMPILER_VAR_68;

#line 408 "/opt/bah/string.bah"
sprintf(buff,"%lf",f);

#line 409 "/opt/bah/string.bah"
return __STR(buff);
};

#line 413 "/opt/bah/string.bah"
long int strToInt(char * s){

#line 414 "/opt/bah/string.bah"
register long int l = strlen(s)-1;

#line 415 "/opt/bah/string.bah"
long int offset = 1;

#line 416 "/opt/bah/string.bah"
long int r = 0;

#line 417 "/opt/bah/string.bah"
long int end = 0;

#line 418 "/opt/bah/string.bah"
if ((s[0]==45)) {

#line 419 "/opt/bah/string.bah"
end = 1;
}

#line 421 "/opt/bah/string.bah"
for (; (l>=end); 
#line 421 "/opt/bah/string.bah"
--l) {

#line 422 "/opt/bah/string.bah"
if ((s[l]<48)||(s[l]>57)) {

#line 423 "/opt/bah/string.bah"
continue;
}

#line 425 "/opt/bah/string.bah"
r = r+(((long int)s[l]-48)*offset);

#line 426 "/opt/bah/string.bah"
offset = offset*10;
};

#line 428 "/opt/bah/string.bah"
if ((end==1)) {

#line 429 "/opt/bah/string.bah"
r = 0-r;
}

#line 431 "/opt/bah/string.bah"
return r;
};

#line 435 "/opt/bah/string.bah"
double strToFloat(char * s){

#line 436 "/opt/bah/string.bah"
return strtod(s,null);
};

#line 442 "/opt/bah/string.bah"
long int stringToInt(struct string s){

#line 443 "/opt/bah/string.bah"
long int i = atol(s.content);

#line 444 "/opt/bah/string.bah"
return i;
};

#line 448 "/opt/bah/string.bah"
typedef array(struct string)* __BAH_ARR_TYPE_string;
__BAH_ARR_TYPE_string splitString(struct string s,char * sp){

#line 449 "/opt/bah/string.bah"
struct string sep = string(sp);

#line 450 "/opt/bah/string.bah"
array(struct string)* res = memoryAlloc(sizeof(array(struct string)));

res->length = 0;
res->elemSize = sizeof(struct string);

#line 451 "/opt/bah/string.bah"
struct string sepBuffer = string("");

#line 452 "/opt/bah/string.bah"
long int sepIndex = 0;

#line 453 "/opt/bah/string.bah"
register long int i = 0;

#line 454 "/opt/bah/string.bah"
struct string replcBuff = string("");

#line 455 "/opt/bah/string.bah"
array(char)* tmpString = memoryAlloc(sizeof(array(char)));

tmpString->length = 0;
tmpString->elemSize = sizeof(char);

#line 458 "/opt/bah/string.bah"
while ((i<s.length)) {

#line 459 "/opt/bah/string.bah"
char c = string__charAt(&s,i);

#line 460 "/opt/bah/string.bah"
char sepc = string__charAt(&sep,sepIndex);

#line 462 "/opt/bah/string.bah"
if ((c==sepc)) {

#line 463 "/opt/bah/string.bah"
sepIndex = sepIndex+1;

#line 464 "/opt/bah/string.bah"
char * ____BAH_COMPILER_VAR_69 =charToString(c);string__append(&replcBuff,____BAH_COMPILER_VAR_69);
}

#line 465 "/opt/bah/string.bah"
else {

#line 466 "/opt/bah/string.bah"
if ((sepIndex>0)) {

#line 467 "/opt/bah/string.bah"
sepIndex = 0;

#line 468 "/opt/bah/string.bah"
char * ____BAH_COMPILER_VAR_70 =charToString(c);string__append(&replcBuff,____BAH_COMPILER_VAR_70);

#line 469 "/opt/bah/string.bah"
register long int ii = 0;

#line 469 "/opt/bah/string.bah"
while ((ii<replcBuff.length)) {

#line 470 "/opt/bah/string.bah"

    unsigned int ____BAH_COMPILER_VAR_71 = len(tmpString);
    __Bah_realocate_arr(tmpString, ____BAH_COMPILER_VAR_71);
    tmpString->data[____BAH_COMPILER_VAR_71] = string__charAt(&replcBuff,ii);

#line 471 "/opt/bah/string.bah"
ii = ii+1;
};

#line 473 "/opt/bah/string.bah"
string__set(&replcBuff,"");
}

#line 474 "/opt/bah/string.bah"
else {

#line 475 "/opt/bah/string.bah"

    unsigned int ____BAH_COMPILER_VAR_72 = len(tmpString);
    __Bah_realocate_arr(tmpString, ____BAH_COMPILER_VAR_72);
    tmpString->data[____BAH_COMPILER_VAR_72] = c;
}
}

#line 478 "/opt/bah/string.bah"
if ((sepIndex==sep.length)) {

#line 479 "/opt/bah/string.bah"
string__set(&replcBuff,"");

#line 480 "/opt/bah/string.bah"
struct string* ____BAH_COMPILER_VAR_73 = memoryAlloc(sizeof(struct string));
struct string* elem = ____BAH_COMPILER_VAR_73;

#line 481 "/opt/bah/string.bah"
char * ____BAH_COMPILER_VAR_74 =arrToStr(tmpString);string__set(elem,____BAH_COMPILER_VAR_74);

#line 482 "/opt/bah/string.bah"
long int lenRes = len(res);

#line 483 "/opt/bah/string.bah"

    unsigned int ____BAH_COMPILER_VAR_75 = lenRes;
    __Bah_realocate_arr(res, ____BAH_COMPILER_VAR_75);
    res->data[____BAH_COMPILER_VAR_75] = *elem;

#line 484 "/opt/bah/string.bah"
clear(tmpString);

#line 485 "/opt/bah/string.bah"
sepIndex = 0;
}

#line 489 "/opt/bah/string.bah"
i = i+1;
};

#line 492 "/opt/bah/string.bah"
if ((replcBuff.length>0)) {

#line 493 "/opt/bah/string.bah"
register long int ii = 0;

#line 493 "/opt/bah/string.bah"
while ((ii<replcBuff.length)) {

#line 494 "/opt/bah/string.bah"

    unsigned int ____BAH_COMPILER_VAR_76 = len(tmpString);
    __Bah_realocate_arr(tmpString, ____BAH_COMPILER_VAR_76);
    tmpString->data[____BAH_COMPILER_VAR_76] = string__charAt(&replcBuff,ii);

#line 495 "/opt/bah/string.bah"
ii = ii+1;
};
}

#line 500 "/opt/bah/string.bah"
if ((len(tmpString)>0)) {

#line 501 "/opt/bah/string.bah"
struct string* ____BAH_COMPILER_VAR_77 = memoryAlloc(sizeof(struct string));
struct string* elem = ____BAH_COMPILER_VAR_77;

#line 502 "/opt/bah/string.bah"
char * ____BAH_COMPILER_VAR_78 =arrToStr(tmpString);string__set(elem,____BAH_COMPILER_VAR_78);

#line 503 "/opt/bah/string.bah"
long int lenRes = len(res);

#line 504 "/opt/bah/string.bah"

    unsigned int ____BAH_COMPILER_VAR_79 = lenRes;
    __Bah_realocate_arr(res, ____BAH_COMPILER_VAR_79);
    res->data[____BAH_COMPILER_VAR_79] = *elem;
}

#line 507 "/opt/bah/string.bah"
return res;
};

#line 511 "/opt/bah/string.bah"
struct string joinString(__BAH_ARR_TYPE_string a,char * sep){

#line 512 "/opt/bah/string.bah"
register long int i = 0;

#line 513 "/opt/bah/string.bah"
struct string s = string("");

#line 514 "/opt/bah/string.bah"
long int max = len(a)-1;

#line 515 "/opt/bah/string.bah"
while ((i<len(a))) {

#line 516 "/opt/bah/string.bah"
struct string e = a->data[i];

#line 517 "/opt/bah/string.bah"
if ((e.length==0)) {

#line 518 "/opt/bah/string.bah"
i = i+1;

#line 519 "/opt/bah/string.bah"
continue;
}

#line 521 "/opt/bah/string.bah"
char * ____BAH_COMPILER_VAR_80 =string__str(&e);struct string tmpS = string(____BAH_COMPILER_VAR_80);

#line 522 "/opt/bah/string.bah"
if ((i!=max)) {

#line 523 "/opt/bah/string.bah"
string__append(&tmpS,sep);
}

#line 525 "/opt/bah/string.bah"
char * ____BAH_COMPILER_VAR_81 =string__str(&tmpS);string__append(&s,____BAH_COMPILER_VAR_81);

#line 526 "/opt/bah/string.bah"
i = i+1;
};

#line 528 "/opt/bah/string.bah"
return s;
};

#line 532 "/opt/bah/string.bah"
char * splitStringBefore(struct string s,char * sp){

#line 533 "/opt/bah/string.bah"
struct string sep = string(sp);

#line 534 "/opt/bah/string.bah"
if ((sep.length>=s.length)) {

#line 535 "/opt/bah/string.bah"
return "";
}

#line 537 "/opt/bah/string.bah"
long int sepIndex = 0;

#line 538 "/opt/bah/string.bah"
long int foundIndex = 0;

#line 539 "/opt/bah/string.bah"
register long int i = 0;

#line 539 "/opt/bah/string.bah"
while ((i<s.length)) {

#line 540 "/opt/bah/string.bah"
char c = string__charAt(&s,i);

#line 541 "/opt/bah/string.bah"
char sc = string__charAt(&sep,sepIndex);

#line 542 "/opt/bah/string.bah"
if ((c==sc)) {

#line 543 "/opt/bah/string.bah"
if ((sepIndex==0)) {

#line 544 "/opt/bah/string.bah"
foundIndex = i-1;
}

#line 546 "/opt/bah/string.bah"
sepIndex = sepIndex+1;

#line 547 "/opt/bah/string.bah"
if ((sepIndex==sep.length)) {

#line 548 "/opt/bah/string.bah"
long int max = s.length-foundIndex-1;

#line 549 "/opt/bah/string.bah"
string__trimRight(&s,max);

#line 550 "/opt/bah/string.bah"
return string__str(&s);
}
}

#line 552 "/opt/bah/string.bah"
else {

#line 553 "/opt/bah/string.bah"
foundIndex = 0;

#line 554 "/opt/bah/string.bah"
sepIndex = 0;
}

#line 557 "/opt/bah/string.bah"
i = i+1;
};

#line 560 "/opt/bah/string.bah"
return "";
};

#line 565 "/opt/bah/string.bah"
struct string toLower(struct string s){

#line 566 "/opt/bah/string.bah"
array(char)* ns = memoryAlloc(sizeof(array(char)));

ns->length = 0;
ns->elemSize = sizeof(char);

#line 567 "/opt/bah/string.bah"
register long int i = 0;

#line 567 "/opt/bah/string.bah"
while ((i<s.length)) {

#line 568 "/opt/bah/string.bah"
char c = string__charAt(&s,i);

#line 569 "/opt/bah/string.bah"
if (isUpper(c)) {

#line 570 "/opt/bah/string.bah"
c = c+(char)32;
}

#line 572 "/opt/bah/string.bah"

    unsigned int ____BAH_COMPILER_VAR_82 = len(ns);
    __Bah_realocate_arr(ns, ____BAH_COMPILER_VAR_82);
    ns->data[____BAH_COMPILER_VAR_82] = c;

#line 573 "/opt/bah/string.bah"
i = i+1;
};

#line 575 "/opt/bah/string.bah"
char * ____BAH_COMPILER_VAR_83 =arrToStr(ns);return string(____BAH_COMPILER_VAR_83);
};

#line 580 "/opt/bah/string.bah"
char strHasPrefix(char * s,char * need){

#line 581 "/opt/bah/string.bah"
register long int i = 0;

#line 582 "/opt/bah/string.bah"
long int nl = strlen(need);

#line 583 "/opt/bah/string.bah"
long int sl = strlen(s);

#line 584 "/opt/bah/string.bah"
if ((sl<nl)) {

#line 585 "/opt/bah/string.bah"
return false;
}

#line 587 "/opt/bah/string.bah"
while ((i<nl)) {

#line 588 "/opt/bah/string.bah"
if ((cpstringCharAt(s,i)!=cpstringCharAt(need,i))) {

#line 589 "/opt/bah/string.bah"
return false;
}

#line 591 "/opt/bah/string.bah"
i = i+1;
};

#line 593 "/opt/bah/string.bah"
return true;
};

#line 598 "/opt/bah/string.bah"
char strHasSuffix(char * s,char * need){

#line 599 "/opt/bah/string.bah"
long int sl = strlen(s);

#line 600 "/opt/bah/string.bah"
long int nl = strlen(need);

#line 601 "/opt/bah/string.bah"
if ((nl>sl)) {

#line 602 "/opt/bah/string.bah"
return false;
}

#line 604 "/opt/bah/string.bah"
register long int i = sl-nl;

#line 604 "/opt/bah/string.bah"
while ((i<sl)) {

#line 605 "/opt/bah/string.bah"
if ((cpstringCharAt(s,i)!=cpstringCharAt(need,i))) {

#line 606 "/opt/bah/string.bah"
return false;
}

#line 608 "/opt/bah/string.bah"
i = i+1;
};

#line 610 "/opt/bah/string.bah"
return true;
};

#line 615 "/opt/bah/string.bah"
void strTrim(char ** s){

#line 616 "/opt/bah/string.bah"
long int l = strlen(*s);

#line 617 "/opt/bah/string.bah"
register long int i = 0;

#line 617 "/opt/bah/string.bah"
while ((i<l)) {

#line 618 "/opt/bah/string.bah"
char c = cpstringCharAt(*s,i);

#line 619 "/opt/bah/string.bah"
if ((isSpace(c)==false)) {

#line 620 "/opt/bah/string.bah"
break;
}

#line 622 "/opt/bah/string.bah"
i = i+1;
};

#line 624 "/opt/bah/string.bah"
*s = *s+i;
};

#line 629 "/opt/bah/string.bah"
long int strCount(char * src,char * needle){

#line 630 "/opt/bah/string.bah"
register long int i = 0;

#line 631 "/opt/bah/string.bah"
long int count = 0;

#line 632 "/opt/bah/string.bah"
long int countIndex = 0;

#line 633 "/opt/bah/string.bah"
long int sl = strlen(src);

#line 634 "/opt/bah/string.bah"
long int nl = strlen(needle);

#line 635 "/opt/bah/string.bah"
while ((i<sl)) {

#line 636 "/opt/bah/string.bah"
char c = cpstringCharAt(src,i);

#line 637 "/opt/bah/string.bah"
char sc = cpstringCharAt(needle,countIndex);

#line 638 "/opt/bah/string.bah"
if ((c==sc)) {

#line 639 "/opt/bah/string.bah"
countIndex = countIndex+1;
}

#line 640 "/opt/bah/string.bah"
else {

#line 641 "/opt/bah/string.bah"
countIndex = 0;
}

#line 643 "/opt/bah/string.bah"
if ((countIndex==nl)) {

#line 644 "/opt/bah/string.bah"
count = count+1;

#line 645 "/opt/bah/string.bah"
countIndex = 0;
}

#line 647 "/opt/bah/string.bah"
i = i+1;
};

#line 649 "/opt/bah/string.bah"
return count;
};

#line 5 "/opt/bah/flags.bah"
#define FLAG_TYPE_CPSTRING 0

#line 6 "/opt/bah/flags.bah"
#define FLAG_TYPE_INT 1

#line 7 "/opt/bah/flags.bah"
#define FLAG_TYPE_FLOAT 2

#line 8 "/opt/bah/flags.bah"
#define FLAG_TYPE_BOOL 3

#line 13 "/opt/bah/flags.bah"
struct flag {
char * name;
char * help;
char * content;
long int cont_int;
double cont_float;
long int isSet;
long int type;
};

#line 23 "/opt/bah/flags.bah"
struct flags {
array(struct flag*)* flags;
array(char *)* args;
};
void flags__addString(struct flags* this,char * name,char * help){

#line 29 "/opt/bah/flags.bah"
struct flag* ____BAH_COMPILER_VAR_84 = memoryAlloc(sizeof(struct flag));
struct flag* f = ____BAH_COMPILER_VAR_84;

#line 30 "/opt/bah/flags.bah"
f->name = name;

#line 31 "/opt/bah/flags.bah"
f->help = help;

#line 32 "/opt/bah/flags.bah"
f->type = FLAG_TYPE_CPSTRING;

#line 33 "/opt/bah/flags.bah"
long int lf = len(this->flags);

#line 34 "/opt/bah/flags.bah"

    unsigned int ____BAH_COMPILER_VAR_85 = lf;
    __Bah_realocate_arr(this->flags, ____BAH_COMPILER_VAR_85);
    this->flags->data[____BAH_COMPILER_VAR_85] = f;
};
void flags__addBool(struct flags* this,char * name,char * help){

#line 40 "/opt/bah/flags.bah"
struct flag* ____BAH_COMPILER_VAR_86 = memoryAlloc(sizeof(struct flag));
struct flag* f = ____BAH_COMPILER_VAR_86;

#line 41 "/opt/bah/flags.bah"
f->name = name;

#line 42 "/opt/bah/flags.bah"
f->help = help;

#line 43 "/opt/bah/flags.bah"
f->type = FLAG_TYPE_BOOL;

#line 44 "/opt/bah/flags.bah"
long int lf = len(this->flags);

#line 45 "/opt/bah/flags.bah"

    unsigned int ____BAH_COMPILER_VAR_87 = lf;
    __Bah_realocate_arr(this->flags, ____BAH_COMPILER_VAR_87);
    this->flags->data[____BAH_COMPILER_VAR_87] = f;
};
void flags__addInt(struct flags* this,char * name,char * help){

#line 50 "/opt/bah/flags.bah"
struct flag* ____BAH_COMPILER_VAR_88 = memoryAlloc(sizeof(struct flag));
struct flag* f = ____BAH_COMPILER_VAR_88;

#line 51 "/opt/bah/flags.bah"
f->name = name;

#line 52 "/opt/bah/flags.bah"
f->help = help;

#line 53 "/opt/bah/flags.bah"
f->type = FLAG_TYPE_INT;

#line 54 "/opt/bah/flags.bah"
long int lf = len(this->flags);

#line 55 "/opt/bah/flags.bah"

    unsigned int ____BAH_COMPILER_VAR_89 = lf;
    __Bah_realocate_arr(this->flags, ____BAH_COMPILER_VAR_89);
    this->flags->data[____BAH_COMPILER_VAR_89] = f;
};
void flags__addFloat(struct flags* this,char * name,char * help){

#line 60 "/opt/bah/flags.bah"
struct flag* ____BAH_COMPILER_VAR_90 = memoryAlloc(sizeof(struct flag));
struct flag* f = ____BAH_COMPILER_VAR_90;

#line 61 "/opt/bah/flags.bah"
f->name = name;

#line 62 "/opt/bah/flags.bah"
f->help = help;

#line 63 "/opt/bah/flags.bah"
f->type = FLAG_TYPE_FLOAT;

#line 64 "/opt/bah/flags.bah"
long int lf = len(this->flags);

#line 65 "/opt/bah/flags.bah"

    unsigned int ____BAH_COMPILER_VAR_91 = lf;
    __Bah_realocate_arr(this->flags, ____BAH_COMPILER_VAR_91);
    this->flags->data[____BAH_COMPILER_VAR_91] = f;
};
void flags__invalidate(struct flags* this){

#line 71 "/opt/bah/flags.bah"
print("Usage of ");

#line 72 "/opt/bah/flags.bah"
print(this->args->data[0]);

#line 73 "/opt/bah/flags.bah"
println(":");

#line 74 "/opt/bah/flags.bah"
register long int i = 0;

#line 74 "/opt/bah/flags.bah"
while ((i<len(this->flags))) {

#line 75 "/opt/bah/flags.bah"
struct flag* flag = this->flags->data[i];

#line 76 "/opt/bah/flags.bah"
print("    -");

#line 77 "/opt/bah/flags.bah"
print(flag->name);

#line 78 "/opt/bah/flags.bah"
if ((flag->type==FLAG_TYPE_CPSTRING)) {

#line 79 "/opt/bah/flags.bah"
println(" (string)");
}

#line 80 "/opt/bah/flags.bah"
else if ((flag->type==FLAG_TYPE_BOOL)) {

#line 81 "/opt/bah/flags.bah"
println(" (bool)");
}

#line 82 "/opt/bah/flags.bah"
else if ((flag->type==FLAG_TYPE_INT)) {

#line 83 "/opt/bah/flags.bah"
println(" (int)");
}

#line 84 "/opt/bah/flags.bah"
else if ((flag->type==FLAG_TYPE_FLOAT)) {

#line 85 "/opt/bah/flags.bah"
println(" (float)");
}

#line 87 "/opt/bah/flags.bah"
print("\t");

#line 88 "/opt/bah/flags.bah"
println(flag->help);

#line 89 "/opt/bah/flags.bah"
i = i+1;
};

#line 91 "/opt/bah/flags.bah"
exit(1);
};
struct flag* flags__getFlag(struct flags* this,struct string name){

#line 97 "/opt/bah/flags.bah"
register long int i = 0;

#line 97 "/opt/bah/flags.bah"
while ((i<len(this->flags))) {

#line 98 "/opt/bah/flags.bah"
struct flag* flag = this->flags->data[i];

#line 99 "/opt/bah/flags.bah"
if (string__compare(&name,flag->name)) {

#line 100 "/opt/bah/flags.bah"
return flag;
}

#line 102 "/opt/bah/flags.bah"
i = i+1;
};

#line 104 "/opt/bah/flags.bah"
struct flag* ____BAH_COMPILER_VAR_92 = memoryAlloc(sizeof(struct flag));
struct flag* z = ____BAH_COMPILER_VAR_92;

#line 105 "/opt/bah/flags.bah"
z->isSet = 0;

#line 106 "/opt/bah/flags.bah"
return z;
};
char * flags__get(struct flags* this,char * name){

#line 113 "/opt/bah/flags.bah"
struct string ____BAH_COMPILER_VAR_93 =string(name);struct flag* flag = flags__getFlag(this,____BAH_COMPILER_VAR_93);

#line 114 "/opt/bah/flags.bah"
return flag->content;
};
long int flags__getInt(struct flags* this,char * name){

#line 120 "/opt/bah/flags.bah"
struct string ____BAH_COMPILER_VAR_94 =string(name);struct flag* flag = flags__getFlag(this,____BAH_COMPILER_VAR_94);

#line 121 "/opt/bah/flags.bah"
if (__builtin_expect((flag->type!=FLAG_TYPE_INT), 0)) {

#line 122 "/opt/bah/flags.bah"
char** ____BAH_COMPILER_VAR_95 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_95[2] = "' is not int.";____BAH_COMPILER_VAR_95[1] = flag->name;____BAH_COMPILER_VAR_95[0] = "Flag '";char * ____BAH_COMPILER_VAR_96 =__Bah_multiple_concat(____BAH_COMPILER_VAR_95, 3);__BAH_panic(____BAH_COMPILER_VAR_96,"/opt/bah/flags.bah:122");
}

#line 124 "/opt/bah/flags.bah"
return flag->cont_int;
};
double flags__getFloat(struct flags* this,char * name){

#line 130 "/opt/bah/flags.bah"
struct string ____BAH_COMPILER_VAR_97 =string(name);struct flag* flag = flags__getFlag(this,____BAH_COMPILER_VAR_97);

#line 131 "/opt/bah/flags.bah"
if (__builtin_expect((flag->type!=FLAG_TYPE_FLOAT), 0)) {

#line 132 "/opt/bah/flags.bah"
char** ____BAH_COMPILER_VAR_98 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_98[2] = "' is not float.";____BAH_COMPILER_VAR_98[1] = flag->name;____BAH_COMPILER_VAR_98[0] = "Flag '";char * ____BAH_COMPILER_VAR_99 =__Bah_multiple_concat(____BAH_COMPILER_VAR_98, 3);__BAH_panic(____BAH_COMPILER_VAR_99,"/opt/bah/flags.bah:132");
}

#line 134 "/opt/bah/flags.bah"
return flag->cont_float;
};
long int flags__isSet(struct flags* this,char * name){

#line 140 "/opt/bah/flags.bah"
struct string ____BAH_COMPILER_VAR_100 =string(name);struct flag* flag = flags__getFlag(this,____BAH_COMPILER_VAR_100);

#line 141 "/opt/bah/flags.bah"
return flag->isSet;
};
void flags__parse(struct flags* this,__BAH_ARR_TYPE_cpstring args){

#line 147 "/opt/bah/flags.bah"
struct flag* currentFlag= null;

#line 148 "/opt/bah/flags.bah"
char isVal = false;

#line 149 "/opt/bah/flags.bah"
this->args = args;

#line 150 "/opt/bah/flags.bah"
register long int i = 1;

#line 150 "/opt/bah/flags.bah"
while ((i<len(args))) {

#line 151 "/opt/bah/flags.bah"
struct string argName = string(args->data[i]);

#line 152 "/opt/bah/flags.bah"
if ((isVal==true)) {

#line 153 "/opt/bah/flags.bah"
currentFlag->content = string__str(&argName);

#line 154 "/opt/bah/flags.bah"
if ((currentFlag->type==FLAG_TYPE_INT)) {

#line 155 "/opt/bah/flags.bah"
char * ____BAH_COMPILER_VAR_101 =string__str(&argName);currentFlag->cont_int = strToInt(____BAH_COMPILER_VAR_101);
}

#line 156 "/opt/bah/flags.bah"
else if ((currentFlag->type==FLAG_TYPE_FLOAT)) {

#line 157 "/opt/bah/flags.bah"
char * ____BAH_COMPILER_VAR_102 =string__str(&argName);currentFlag->cont_float = strToFloat(____BAH_COMPILER_VAR_102);
}

#line 159 "/opt/bah/flags.bah"
isVal = false;
}

#line 160 "/opt/bah/flags.bah"
else {

#line 161 "/opt/bah/flags.bah"
if ((string__charAt(&argName,0)!=45)) {

#line 162 "/opt/bah/flags.bah"
i = i+1;

#line 163 "/opt/bah/flags.bah"
continue;
}

#line 165 "/opt/bah/flags.bah"
string__trimLeft(&argName,1);

#line 166 "/opt/bah/flags.bah"
if (__builtin_expect(string__compare(&argName,"help"), 0)) {

#line 167 "/opt/bah/flags.bah"
flags__invalidate(this);
}

#line 168 "/opt/bah/flags.bah"
else if (__builtin_expect(string__compare(&argName,"h"), 0)) {

#line 169 "/opt/bah/flags.bah"
flags__invalidate(this);
}

#line 171 "/opt/bah/flags.bah"
currentFlag = flags__getFlag(this,argName);

#line 172 "/opt/bah/flags.bah"
if (__builtin_expect((currentFlag==null), 0)) {

#line 173 "/opt/bah/flags.bah"
flags__invalidate(this);
}

#line 175 "/opt/bah/flags.bah"
currentFlag->isSet = 1;

#line 176 "/opt/bah/flags.bah"
if ((currentFlag->type!=FLAG_TYPE_BOOL)) {

#line 177 "/opt/bah/flags.bah"
isVal = true;
}
}

#line 180 "/opt/bah/flags.bah"
i = i+1;
};

#line 182 "/opt/bah/flags.bah"
if ((isVal==true)) {

#line 183 "/opt/bah/flags.bah"
if (__builtin_expect((currentFlag->type!=FLAG_TYPE_BOOL), 0)) {

#line 184 "/opt/bah/flags.bah"
flags__invalidate(this);
}
}
};

#line 3 "/home/alois/Documents/bah-bah/src/main.bah"

#line 1 "/opt/bah/rand.bah"
#include <stdlib.h>

#line 2 "/opt/bah/rand.bah"

#line 6 "/opt/bah/rand.bah"

#line 1 "/opt/bah/time.bah"

#line 2 "/opt/bah/time.bah"

#line 3 "/opt/bah/time.bah"
#include <time.h>

#line 5 "/opt/bah/time.bah"

#line 11 "/opt/bah/time.bah"
#define TIME_MS 1000000

#line 13 "/opt/bah/time.bah"
#define TIME_S 1000000000

#line 15 "/opt/bah/time.bah"
#define TIME_MIN 60000000000

#line 19 "/opt/bah/time.bah"
struct time {
long int timestamp;
};
void time__now(struct time* this){

#line 24 "/opt/bah/time.bah"
this->timestamp = time(0);
};
char * time__format(struct time* this,char * a){

#line 31 "/opt/bah/time.bah"
long int lt = localtime(&this->timestamp);

#line 33 "/opt/bah/time.bah"
char * date = memoryAlloc(1024);

#line 34 "/opt/bah/time.bah"
strftime(date,1024,a,lt);

#line 35 "/opt/bah/time.bah"
return date;
};
long int time__since(struct time* this){

#line 40 "/opt/bah/time.bah"
long int nt = time(0);

#line 41 "/opt/bah/time.bah"
long int r = nt-this->timestamp;

#line 42 "/opt/bah/time.bah"
return r;
};

#line 46 "/opt/bah/time.bah"

#line 51 "/opt/bah/time.bah"

#line 52 "/opt/bah/time.bah"

#line 55 "/opt/bah/time.bah"

#line 65 "/opt/bah/time.bah"

#line 72 "/opt/bah/time.bah"
long int getTimeUnix(){

#line 73 "/opt/bah/time.bah"
struct timespec ____BAH_COMPILER_VAR_103 = {};
struct timespec ts = ____BAH_COMPILER_VAR_103;

#line 74 "/opt/bah/time.bah"

#line 75 "/opt/bah/time.bah"
timespec_get(&ts,TIME_UTC);

#line 77 "/opt/bah/time.bah"

#line 87 "/opt/bah/time.bah"

#line 90 "/opt/bah/time.bah"
long int s = ts.tv_sec*1000000000+ts.tv_nsec;

#line 91 "/opt/bah/time.bah"
return s;
};

#line 95 "/opt/bah/time.bah"

#line 7 "/opt/bah/rand.bah"

#line 9 "/opt/bah/rand.bah"

#line 10 "/opt/bah/rand.bah"

#line 11 "/opt/bah/rand.bah"
char RAND_SEEDED;

#line 15 "/opt/bah/rand.bah"
void seedRandom(long int i){

#line 16 "/opt/bah/rand.bah"
srand(i);

#line 17 "/opt/bah/rand.bah"
RAND_SEEDED = 1;
};

#line 23 "/opt/bah/rand.bah"
long int randomInRange(long int min,long int max){

#line 24 "/opt/bah/rand.bah"
if ((RAND_SEEDED==false)) {

#line 25 "/opt/bah/rand.bah"
srand(time(0)+getTimeUnix());

#line 26 "/opt/bah/rand.bah"
RAND_SEEDED = true;
}

#line 29 "/opt/bah/rand.bah"
long int range = max-min;

#line 30 "/opt/bah/rand.bah"
long int i = rand()%range+1;

#line 32 "/opt/bah/rand.bah"
i = i+min;

#line 34 "/opt/bah/rand.bah"
return i;
};

#line 37 "/opt/bah/rand.bah"

#line 45 "/opt/bah/rand.bah"
long int cryptoRand(){

#line 46 "/opt/bah/rand.bah"

#line 47 "/opt/bah/rand.bah"
struct fileStream ____BAH_COMPILER_VAR_104 = {};
struct fileStream fs = ____BAH_COMPILER_VAR_104;

#line 48 "/opt/bah/rand.bah"
fileStream__open(&fs,"/dev/urandom","r");

#line 49 "/opt/bah/rand.bah"
char c = fileStream__getChar(&fs);

#line 50 "/opt/bah/rand.bah"
fileStream__close(&fs);

#line 51 "/opt/bah/rand.bah"
long int i = (long int)c;

#line 53 "/opt/bah/rand.bah"

#line 60 "/opt/bah/rand.bah"

#line 66 "/opt/bah/rand.bah"
return i;
};

#line 4 "/home/alois/Documents/bah-bah/src/main.bah"

#line 1 "/opt/bah/exec.bah"

#line 2 "/opt/bah/exec.bah"

#line 3 "/opt/bah/exec.bah"

#line 1 "/opt/bah/rope.bah"
#define ROPE_LEAF_LEN 200

#line 6 "/opt/bah/rope.bah"
struct rope {
struct rope* left;
struct rope* right;
char * str;
int lCount;
int len;
int totalLen;
};
void rope__addStr(struct rope* this,char * s,long int* offset){

#line 17 "/opt/bah/rope.bah"
if ((this->left==null)&&(this->right==null)) {

#line 18 "/opt/bah/rope.bah"
long int off = *offset;

#line 19 "/opt/bah/rope.bah"
memcpy(s+off,this->str,this->lCount+1);

#line 20 "/opt/bah/rope.bah"
*offset = *offset+(this->lCount+1);

#line 21 "/opt/bah/rope.bah"
return;
}

#line 23 "/opt/bah/rope.bah"
long int l = *offset;

#line 24 "/opt/bah/rope.bah"
rope__addStr(this->left,s,offset);

#line 25 "/opt/bah/rope.bah"
rope__addStr(this->right,s,offset);
};
char * rope__toStr(struct rope* this){

#line 30 "/opt/bah/rope.bah"
if ((this->left==null)&&(this->right==null)) {

#line 31 "/opt/bah/rope.bah"
return this->str;
}

#line 33 "/opt/bah/rope.bah"
char * s = memoryAlloc(this->totalLen+1);

#line 34 "/opt/bah/rope.bah"
long int offset = 0;

#line 35 "/opt/bah/rope.bah"
rope__addStr(this->left,s,&offset);

#line 36 "/opt/bah/rope.bah"
rope__addStr(this->right,s,&offset);

#line 38 "/opt/bah/rope.bah"
return s;
};
struct rope* rope__add(struct rope* this,struct rope* root2){

#line 44 "/opt/bah/rope.bah"
int n1 = this->len;

#line 45 "/opt/bah/rope.bah"
struct rope* ____BAH_COMPILER_VAR_105 = memoryAlloc(sizeof(struct rope));
struct rope* tmp = ____BAH_COMPILER_VAR_105;

#line 47 "/opt/bah/rope.bah"
tmp->left = this;

#line 48 "/opt/bah/rope.bah"
tmp->right = root2;

#line 51 "/opt/bah/rope.bah"
tmp->totalLen = this->totalLen+root2->totalLen;

#line 52 "/opt/bah/rope.bah"
tmp->str = null;

#line 53 "/opt/bah/rope.bah"
return tmp;
};

#line 62 "/opt/bah/rope.bah"
struct rope* createRopeStructure(struct rope* par,char * a,long int l,long int r){

#line 63 "/opt/bah/rope.bah"
struct rope* ____BAH_COMPILER_VAR_106 = memoryAlloc(sizeof(struct rope));
struct rope* tmp = ____BAH_COMPILER_VAR_106;

#line 65 "/opt/bah/rope.bah"
tmp->left = null;

#line 66 "/opt/bah/rope.bah"
tmp->right = null;

#line 70 "/opt/bah/rope.bah"
if ((r-l>ROPE_LEAF_LEN)) {

#line 71 "/opt/bah/rope.bah"
tmp->str = null;

#line 72 "/opt/bah/rope.bah"
tmp->lCount = r-l;

#line 73 "/opt/bah/rope.bah"
tmp->lCount = tmp->lCount/2;

#line 74 "/opt/bah/rope.bah"
struct rope* node = tmp;

#line 75 "/opt/bah/rope.bah"
long int m = l+r;

#line 76 "/opt/bah/rope.bah"
m = m/2;

#line 77 "/opt/bah/rope.bah"
node->left = createRopeStructure(node,a,l,m);

#line 78 "/opt/bah/rope.bah"
node->right = createRopeStructure(node,a,m+1,r);
}

#line 79 "/opt/bah/rope.bah"
else {

#line 80 "/opt/bah/rope.bah"
struct rope* node = tmp;

#line 81 "/opt/bah/rope.bah"
tmp->lCount = r-l;

#line 82 "/opt/bah/rope.bah"
long int j = 0;

#line 83 "/opt/bah/rope.bah"
register long int i = l;

#line 84 "/opt/bah/rope.bah"
char * arr = memoryAlloc(r+1);

#line 85 "/opt/bah/rope.bah"
while ((i<=r)) {

#line 86 "/opt/bah/rope.bah"
arr[j]=a[i];

#line 87 "/opt/bah/rope.bah"
++j;

#line 87 "/opt/bah/rope.bah"
++i;
};

#line 89 "/opt/bah/rope.bah"
tmp->str = arr;
}

#line 91 "/opt/bah/rope.bah"
return tmp;
};

#line 97 "/opt/bah/rope.bah"
long int ropeSet(struct rope* r,char * a){

#line 98 "/opt/bah/rope.bah"
long int n1 = strlen(a);

#line 99 "/opt/bah/rope.bah"
long int diff = n1-r->totalLen;

#line 100 "/opt/bah/rope.bah"
struct rope* nr = createRopeStructure(null,a,0,n1-1);

#line 101 "/opt/bah/rope.bah"
nr->totalLen = n1;

#line 102 "/opt/bah/rope.bah"
nr->len = n1;

#line 103 "/opt/bah/rope.bah"
*r = *nr;

#line 104 "/opt/bah/rope.bah"
return diff;
};

#line 108 "/opt/bah/rope.bah"
struct rope* concatenateRopes(struct rope* root1,struct rope* root2){

#line 109 "/opt/bah/rope.bah"
int n1 = root1->len;

#line 110 "/opt/bah/rope.bah"
struct rope* ____BAH_COMPILER_VAR_107 = memoryAlloc(sizeof(struct rope));
struct rope* tmp = ____BAH_COMPILER_VAR_107;

#line 111 "/opt/bah/rope.bah"
tmp->left = root1;

#line 112 "/opt/bah/rope.bah"
tmp->right = root2;

#line 113 "/opt/bah/rope.bah"
tmp->totalLen = root1->totalLen+root2->totalLen;

#line 114 "/opt/bah/rope.bah"
tmp->str = null;

#line 115 "/opt/bah/rope.bah"
return tmp;
};

#line 119 "/opt/bah/rope.bah"
struct rope* rope(char * a){

#line 120 "/opt/bah/rope.bah"
long int n1 = strlen(a);

#line 121 "/opt/bah/rope.bah"
struct rope* r = createRopeStructure(null,a,0,n1-1);

#line 122 "/opt/bah/rope.bah"
r->totalLen = n1;

#line 123 "/opt/bah/rope.bah"
r->len = n1;

#line 124 "/opt/bah/rope.bah"
return r;
};

#line 5 "/opt/bah/exec.bah"

#line 11 "/opt/bah/exec.bah"
struct command {
char * command;
char error;
long int status;
char * input;
FILE* handle;
};
char * command__run(struct command* this){

#line 25 "/opt/bah/exec.bah"
char * cm = this->command;

#line 26 "/opt/bah/exec.bah"
if ((this->error==false)) {

#line 27 "/opt/bah/exec.bah"
char** ____BAH_COMPILER_VAR_108 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_108[1] = " 2>/dev/null";____BAH_COMPILER_VAR_108[0] = cm;char * ____BAH_COMPILER_VAR_109 =__Bah_multiple_concat(____BAH_COMPILER_VAR_108, 2);cm = ____BAH_COMPILER_VAR_109;
}

#line 28 "/opt/bah/exec.bah"
else {

#line 29 "/opt/bah/exec.bah"
char** ____BAH_COMPILER_VAR_110 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_110[1] = " 2>&1";____BAH_COMPILER_VAR_110[0] = cm;char * ____BAH_COMPILER_VAR_111 =__Bah_multiple_concat(____BAH_COMPILER_VAR_110, 2);cm = ____BAH_COMPILER_VAR_111;
}

#line 31 "/opt/bah/exec.bah"
this->handle = popen(cm,"w");

#line 32 "/opt/bah/exec.bah"
if ((this->handle==null)) {

#line 33 "/opt/bah/exec.bah"
return "";
}

#line 35 "/opt/bah/exec.bah"
if ((strcmp(this->input, null) != 0)) {

#line 36 "/opt/bah/exec.bah"
fputs(this->input,(void *)this->handle);
}

#line 38 "/opt/bah/exec.bah"
char * buff = memoryAlloc(1025);

#line 39 "/opt/bah/exec.bah"
char * res = "";

#line 40 "/opt/bah/exec.bah"
while (((void *)fgets(buff,1024,this->handle)!=null)) {

#line 41 "/opt/bah/exec.bah"
char** ____BAH_COMPILER_VAR_112 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_112[1] = buff;____BAH_COMPILER_VAR_112[0] = res;char * ____BAH_COMPILER_VAR_113 =__Bah_multiple_concat(____BAH_COMPILER_VAR_112, 2);res = ____BAH_COMPILER_VAR_113;
};

#line 43 "/opt/bah/exec.bah"
this->status = pclose(this->handle);

#line 44 "/opt/bah/exec.bah"
return res;
};
__BAH_ARR_TYPE_char command__runBytes(struct command* this){

#line 50 "/opt/bah/exec.bah"
array(char)* arr = memoryAlloc(sizeof(array(char)));

arr->length = 0;
arr->elemSize = sizeof(char);

#line 51 "/opt/bah/exec.bah"
char * cm = this->command;

#line 52 "/opt/bah/exec.bah"
if ((this->error==false)) {

#line 53 "/opt/bah/exec.bah"
char** ____BAH_COMPILER_VAR_114 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_114[1] = " 2>/dev/null";____BAH_COMPILER_VAR_114[0] = cm;char * ____BAH_COMPILER_VAR_115 =__Bah_multiple_concat(____BAH_COMPILER_VAR_114, 2);cm = ____BAH_COMPILER_VAR_115;
}

#line 54 "/opt/bah/exec.bah"
else {

#line 55 "/opt/bah/exec.bah"
char** ____BAH_COMPILER_VAR_116 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_116[1] = " 2>&1";____BAH_COMPILER_VAR_116[0] = cm;char * ____BAH_COMPILER_VAR_117 =__Bah_multiple_concat(____BAH_COMPILER_VAR_116, 2);cm = ____BAH_COMPILER_VAR_117;
}

#line 57 "/opt/bah/exec.bah"
this->handle = popen(cm,"r");

#line 58 "/opt/bah/exec.bah"
if ((this->handle==null)) {

#line 59 "/opt/bah/exec.bah"
return arr;
}

#line 62 "/opt/bah/exec.bah"
long int total = 0;

#line 63 "/opt/bah/exec.bah"
long int fd = fileno(this->handle);

#line 65 "/opt/bah/exec.bah"
char * buff = memoryAlloc(1024);

#line 67 "/opt/bah/exec.bah"
char * response = "";

#line 68 "/opt/bah/exec.bah"
void * res = fgets(buff,1023,this->handle);

#line 69 "/opt/bah/exec.bah"
while ((res!=null)) {

#line 70 "/opt/bah/exec.bah"
char** ____BAH_COMPILER_VAR_118 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_118[1] = buff;____BAH_COMPILER_VAR_118[0] = response;char * ____BAH_COMPILER_VAR_119 =__Bah_multiple_concat(____BAH_COMPILER_VAR_118, 2);response = ____BAH_COMPILER_VAR_119;

#line 71 "/opt/bah/exec.bah"
res = fgets(buff,1023,this->handle);
};

#line 74 "/opt/bah/exec.bah"
this->status = pclose(this->handle);

#line 75 "/opt/bah/exec.bah"
arr->data=response;

#line 76 "/opt/bah/exec.bah"
arr->length=strlen(response);

#line 77 "/opt/bah/exec.bah"
return arr;
};

#line 84 "/opt/bah/exec.bah"
struct command command(char * s){

#line 85 "/opt/bah/exec.bah"
struct command ____BAH_COMPILER_VAR_120 = {};
____BAH_COMPILER_VAR_120.error = true;
struct command cmd = ____BAH_COMPILER_VAR_120;

#line 86 "/opt/bah/exec.bah"
cmd.command = s;

#line 87 "/opt/bah/exec.bah"
return cmd;
};

#line 90 "/opt/bah/exec.bah"

#line 94 "/opt/bah/exec.bah"
long int exec(char * s,__BAH_ARR_TYPE_cpstring args){

#line 95 "/opt/bah/exec.bah"
long int r;

#line 96 "/opt/bah/exec.bah"
array(char *)* nArgs = memoryAlloc(sizeof(array(char *)));

nArgs->length = 0;
nArgs->elemSize = sizeof(char *);

#line 97 "/opt/bah/exec.bah"

    unsigned int ____BAH_COMPILER_VAR_121 = 0;
    __Bah_realocate_arr(nArgs, ____BAH_COMPILER_VAR_121);
    nArgs->data[____BAH_COMPILER_VAR_121] = s;

#line 98 "/opt/bah/exec.bah"
register long int i = 0;

#line 98 "/opt/bah/exec.bah"
while ((i<len(args))) {

#line 99 "/opt/bah/exec.bah"

    unsigned int ____BAH_COMPILER_VAR_122 = i+1;
    __Bah_realocate_arr(nArgs, ____BAH_COMPILER_VAR_122);
    nArgs->data[____BAH_COMPILER_VAR_122] = args->data[i];

#line 100 "/opt/bah/exec.bah"
i = i+1;
};

#line 102 "/opt/bah/exec.bah"

    unsigned int ____BAH_COMPILER_VAR_123 = i+2;
    __Bah_realocate_arr(nArgs, ____BAH_COMPILER_VAR_123);
    nArgs->data[____BAH_COMPILER_VAR_123] = (char *)0;

#line 103 "/opt/bah/exec.bah"
r=execvp(s,nArgs->data);

#line 104 "/opt/bah/exec.bah"
return r;
};

#line 5 "/home/alois/Documents/bah-bah/src/main.bah"

#line 6 "/home/alois/Documents/bah-bah/src/main.bah"

#line 9 "/home/alois/Documents/bah-bah/src/main.bah"

#line 10 "/home/alois/Documents/bah-bah/src/main.bah"
char * BAH_DIR;

#line 11 "/home/alois/Documents/bah-bah/src/main.bah"
char * BAH_OS;

#line 12 "/home/alois/Documents/bah-bah/src/main.bah"
char * BAH_CC;

#line 14 "/home/alois/Documents/bah-bah/src/main.bah"

#line 20 "/home/alois/Documents/bah-bah/src/main.bah"

#line 26 "/home/alois/Documents/bah-bah/src/main.bah"
#define BAH_VERSION "v1.2 (build 130)"

#line 28 "/home/alois/Documents/bah-bah/src/main.bah"
char debug;

#line 29 "/home/alois/Documents/bah-bah/src/main.bah"
char verboseRuntime;

#line 30 "/home/alois/Documents/bah-bah/src/main.bah"
char isObject;

#line 31 "/home/alois/Documents/bah-bah/src/main.bah"
char isUnsafe;

#line 32 "/home/alois/Documents/bah-bah/src/main.bah"
char isOptimized;

#line 33 "/home/alois/Documents/bah-bah/src/main.bah"
char noticeEnabled;

#line 34 "/home/alois/Documents/bah-bah/src/main.bah"
char RAIIenabled;

#line 35 "/home/alois/Documents/bah-bah/src/main.bah"
char isFixMeEnabled;

#line 37 "/home/alois/Documents/bah-bah/src/main.bah"
char * execName;

#line 38 "/home/alois/Documents/bah-bah/src/main.bah"
char isSubObject;

#line 39 "/home/alois/Documents/bah-bah/src/main.bah"
char isImportedSubObject;

#line 41 "/home/alois/Documents/bah-bah/src/main.bah"

#line 1 "/home/alois/Documents/bah-bah/src/globals.bah"

#line 2 "/home/alois/Documents/bah-bah/src/globals.bah"

#line 4 "/home/alois/Documents/bah-bah/src/globals.bah"
struct rope* OUTPUT;

#line 5 "/home/alois/Documents/bah-bah/src/globals.bah"
char * NEXT_LINE;

#line 7 "/home/alois/Documents/bah-bah/src/globals.bah"
struct rope* INIT;

#line 9 "/home/alois/Documents/bah-bah/src/globals.bah"
struct rope* postDeclHandle;

#line 12 "/home/alois/Documents/bah-bah/src/globals.bah"
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
void * iterScope;
char canBeReg;
char isReg;
void * lastSet;
char isArg;
};

#line 33 "/home/alois/Documents/bah-bah/src/globals.bah"
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
void * iterScope;
char canBeReg;
char isReg;
void * lastSet;
char isArg;
char * def;
char isFn;
};

#line 39 "/home/alois/Documents/bah-bah/src/globals.bah"
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

#line 60 "/home/alois/Documents/bah-bah/src/globals.bah"
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

#line 71 "/home/alois/Documents/bah-bah/src/globals.bah"
struct varCheck {
struct variable* v;
char checkNull;
};

#line 77 "/home/alois/Documents/bah-bah/src/globals.bah"
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
char Elems__isChildren(struct Elems* this,struct Elems* e){

#line 91 "/home/alois/Documents/bah-bah/src/globals.bah"
if ((e==null)) {

#line 92 "/home/alois/Documents/bah-bah/src/globals.bah"
return false;
}

#line 94 "/home/alois/Documents/bah-bah/src/globals.bah"
while ((e->parent!=null)) {

#line 95 "/home/alois/Documents/bah-bah/src/globals.bah"
if ((e->parent==this)) {

#line 96 "/home/alois/Documents/bah-bah/src/globals.bah"
return true;
}

#line 98 "/home/alois/Documents/bah-bah/src/globals.bah"
e = e->parent;
};

#line 100 "/home/alois/Documents/bah-bah/src/globals.bah"
return false;
};

#line 106 "/home/alois/Documents/bah-bah/src/globals.bah"
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

#line 123 "/home/alois/Documents/bah-bah/src/globals.bah"
char shouldOnlyDecl;

#line 125 "/home/alois/Documents/bah-bah/src/globals.bah"
struct compilerStateTag compilerState;

#line 127 "/home/alois/Documents/bah-bah/src/globals.bah"
struct cStruct* currentCStruct;

#line 129 "/home/alois/Documents/bah-bah/src/globals.bah"
long int threadCount;

#line 131 "/home/alois/Documents/bah-bah/src/globals.bah"
struct func* currentFn;

#line 133 "/home/alois/Documents/bah-bah/src/globals.bah"
long int totalLines;

#line 135 "/home/alois/Documents/bah-bah/src/globals.bah"
long int totalSize;

#line 137 "/home/alois/Documents/bah-bah/src/globals.bah"
long int totalLexerTime;

#line 139 "/home/alois/Documents/bah-bah/src/globals.bah"
char RCPenabled;

#line 141 "/home/alois/Documents/bah-bah/src/globals.bah"
long int RCPlevel;

#line 143 "/home/alois/Documents/bah-bah/src/globals.bah"
struct flags flags;

#line 145 "/home/alois/Documents/bah-bah/src/globals.bah"
struct variable* currSetVar;

#line 148 "/home/alois/Documents/bah-bah/src/globals.bah"
array(struct varCheck)* currChecks;

#line 150 "/home/alois/Documents/bah-bah/src/globals.bah"
char prevIfExits;

#line 152 "/home/alois/Documents/bah-bah/src/globals.bah"
array(struct varCheck)* prevIfChecks;

#line 154 "/home/alois/Documents/bah-bah/src/globals.bah"
char * prevIfShortcut;

#line 43 "/home/alois/Documents/bah-bah/src/main.bah"

#line 1 "/home/alois/Documents/bah-bah/src/lexer.bah"

#line 3 "/home/alois/Documents/bah-bah/src/lexer.bah"

#line 6 "/home/alois/Documents/bah-bah/src/lexer.bah"
typedef char tokenType;

#line 8 "/home/alois/Documents/bah-bah/src/lexer.bah"
#define TOKEN_NO_TYPE (tokenType)-1

#line 9 "/home/alois/Documents/bah-bah/src/lexer.bah"
#define TOKEN_TYPE_INT (tokenType)0

#line 10 "/home/alois/Documents/bah-bah/src/lexer.bah"
#define TOKEN_TYPE_FLOAT (tokenType)1

#line 11 "/home/alois/Documents/bah-bah/src/lexer.bah"
#define TOKEN_TYPE_VAR (tokenType)2

#line 12 "/home/alois/Documents/bah-bah/src/lexer.bah"
#define TOKEN_TYPE_ENCL (tokenType)3

#line 13 "/home/alois/Documents/bah-bah/src/lexer.bah"
#define TOKEN_TYPE_SEP (tokenType)4

#line 14 "/home/alois/Documents/bah-bah/src/lexer.bah"
#define TOKEN_TYPE_STR (tokenType)5

#line 15 "/home/alois/Documents/bah-bah/src/lexer.bah"
#define TOKEN_TYPE_KEYWORD (tokenType)6

#line 16 "/home/alois/Documents/bah-bah/src/lexer.bah"
#define TOKEN_TYPE_CHAR (tokenType)7

#line 17 "/home/alois/Documents/bah-bah/src/lexer.bah"
#define TOKEN_TYPE_BOOL (tokenType)8

#line 18 "/home/alois/Documents/bah-bah/src/lexer.bah"
#define TOKEN_TYPE_SYNTAX (tokenType)10

#line 19 "/home/alois/Documents/bah-bah/src/lexer.bah"
#define TOKEN_TYPE_FUNC (tokenType)11

#line 20 "/home/alois/Documents/bah-bah/src/lexer.bah"
#define TOKEN_TYPE_CAST (tokenType)12

#line 23 "/home/alois/Documents/bah-bah/src/lexer.bah"
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

#line 45 "/home/alois/Documents/bah-bah/src/lexer.bah"
char inArray(char needle,__BAH_ARR_TYPE_char arr){

#line 46 "/home/alois/Documents/bah-bah/src/lexer.bah"
register long int i = 0;

#line 46 "/home/alois/Documents/bah-bah/src/lexer.bah"
while ((i<len(arr))) {

#line 47 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((needle==arr->data[i])) {

#line 48 "/home/alois/Documents/bah-bah/src/lexer.bah"
return true;
}

#line 50 "/home/alois/Documents/bah-bah/src/lexer.bah"
i = i+1;
};

#line 52 "/home/alois/Documents/bah-bah/src/lexer.bah"
return false;
};

#line 55 "/home/alois/Documents/bah-bah/src/lexer.bah"
char inArrayStr(char * needle,__BAH_ARR_TYPE_cpstring arr){

#line 56 "/home/alois/Documents/bah-bah/src/lexer.bah"
register long int i = 0;

#line 56 "/home/alois/Documents/bah-bah/src/lexer.bah"
while ((i<len(arr))) {

#line 57 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((strcmp(needle, arr->data[i]) == 0)) {

#line 58 "/home/alois/Documents/bah-bah/src/lexer.bah"
return true;
}

#line 60 "/home/alois/Documents/bah-bah/src/lexer.bah"
i = i+1;
};

#line 62 "/home/alois/Documents/bah-bah/src/lexer.bah"
return false;
};

#line 65 "/home/alois/Documents/bah-bah/src/lexer.bah"
struct Tok makeToken(long int pos,long int lineNb,__BAH_ARR_TYPE_char cont,tokenType type){

#line 66 "/home/alois/Documents/bah-bah/src/lexer.bah"
struct Tok ____BAH_COMPILER_VAR_124 = {};
____BAH_COMPILER_VAR_124.cont = "";
____BAH_COMPILER_VAR_124.ogCont = "";
____BAH_COMPILER_VAR_124.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_124.line = 1;
____BAH_COMPILER_VAR_124.begLine = 1;
____BAH_COMPILER_VAR_124.bahType = "";
struct Tok t = ____BAH_COMPILER_VAR_124;

#line 67 "/home/alois/Documents/bah-bah/src/lexer.bah"
t.cont = arrToStr(cont);

#line 68 "/home/alois/Documents/bah-bah/src/lexer.bah"
t.ogCont = t.cont;

#line 69 "/home/alois/Documents/bah-bah/src/lexer.bah"
clear(cont);

#line 70 "/home/alois/Documents/bah-bah/src/lexer.bah"
t.pos = pos;

#line 71 "/home/alois/Documents/bah-bah/src/lexer.bah"
t.line = lineNb;

#line 72 "/home/alois/Documents/bah-bah/src/lexer.bah"
t.type = type;

#line 73 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((type==TOKEN_TYPE_INT)||(type==TOKEN_TYPE_STR)||(type==TOKEN_TYPE_FLOAT)||(type==TOKEN_TYPE_VAR)||(type==TOKEN_TYPE_BOOL)||(type==TOKEN_TYPE_CHAR)) {

#line 74 "/home/alois/Documents/bah-bah/src/lexer.bah"
t.isValue = true;
}

#line 76 "/home/alois/Documents/bah-bah/src/lexer.bah"
return t;
};

#line 79 "/home/alois/Documents/bah-bah/src/lexer.bah"
char isMinus(char c,char nc){

#line 80 "/home/alois/Documents/bah-bah/src/lexer.bah"
return (c==45)&&isNumber(nc);
};

#line 83 "/home/alois/Documents/bah-bah/src/lexer.bah"
void lexerErr(long int line,long int pos,char * msg){

#line 84 "/home/alois/Documents/bah-bah/src/lexer.bah"
char * lineStr = intToStr(line);

#line 85 "/home/alois/Documents/bah-bah/src/lexer.bah"
char * posStr = intToStr(pos);

#line 86 "/home/alois/Documents/bah-bah/src/lexer.bah"
char** ____BAH_COMPILER_VAR_125 = alloca(8 * sizeof(char*));____BAH_COMPILER_VAR_125[7] = msg;____BAH_COMPILER_VAR_125[6] = "\n\e[0m\n";____BAH_COMPILER_VAR_125[5] = posStr;____BAH_COMPILER_VAR_125[4] = ":";____BAH_COMPILER_VAR_125[3] = lineStr;____BAH_COMPILER_VAR_125[2] = ":";____BAH_COMPILER_VAR_125[1] = compilerState.currentFile;____BAH_COMPILER_VAR_125[0] = "\e[1;31m[LEXER-ERROR]\e[0m ";char * ____BAH_COMPILER_VAR_126 =__Bah_multiple_concat(____BAH_COMPILER_VAR_125, 8);println(____BAH_COMPILER_VAR_126);

#line 87 "/home/alois/Documents/bah-bah/src/lexer.bah"
exit(1);
};

#line 90 "/home/alois/Documents/bah-bah/src/lexer.bah"
array(char)* enclavers;

#line 91 "/home/alois/Documents/bah-bah/src/lexer.bah"
array(char)* syntaxes;

#line 93 "/home/alois/Documents/bah-bah/src/lexer.bah"
array(char *)* keywords;

#line 99 "/home/alois/Documents/bah-bah/src/lexer.bah"
char ____BAH_COMPILER_VAR_147(array(char)* arr, char el) {
        if (arr == 0) {
            return 0;
        };
        for(int i=arr->length-1; i!=-1;i--) {
            if (arr->data[i] == el) {
                return 1;
            };
        }
        return 0;
        }
char ____BAH_COMPILER_VAR_155(array(char *)* arr, char * el) {
        if (arr == 0) {
            return 0;
        };
        for(int i=arr->length-1; i!=-1;i--) {
            if (arr->data[i] != 0 && strcmp(arr->data[i], el) == 0) {
                return 1;
            };
        }
        return 0;
        }
typedef array(struct Tok)* __BAH_ARR_TYPE_Tok;
__BAH_ARR_TYPE_Tok lexer(char * s,unsigned long int codeLength){

#line 101 "/home/alois/Documents/bah-bah/src/lexer.bah"
long int dur = getTimeUnix();

#line 102 "/home/alois/Documents/bah-bah/src/lexer.bah"
array(struct Tok)* tokens = memoryAlloc(sizeof(array(struct Tok)));

tokens->length = 0;
tokens->elemSize = sizeof(struct Tok);

#line 104 "/home/alois/Documents/bah-bah/src/lexer.bah"
totalSize = totalSize+codeLength;

#line 106 "/home/alois/Documents/bah-bah/src/lexer.bah"
array(char)* memory = memoryAlloc(sizeof(array(char)));

memory->length = 0;
memory->elemSize = sizeof(char);

#line 108 "/home/alois/Documents/bah-bah/src/lexer.bah"
long int lineNb = 1;

#line 110 "/home/alois/Documents/bah-bah/src/lexer.bah"
register long int i = 0;

#line 110 "/home/alois/Documents/bah-bah/src/lexer.bah"
for (; (i<codeLength); 
#line 110 "/home/alois/Documents/bah-bah/src/lexer.bah"
++i) {

#line 111 "/home/alois/Documents/bah-bah/src/lexer.bah"
char c = s[i];

#line 112 "/home/alois/Documents/bah-bah/src/lexer.bah"
char nc = (char)0;

#line 113 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((i+1<codeLength)) {

#line 114 "/home/alois/Documents/bah-bah/src/lexer.bah"
nc = s[i+1];
}

#line 117 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((c==47)) {

#line 119 "/home/alois/Documents/bah-bah/src/lexer.bah"
nc = s[i+1];

#line 120 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((nc==47)) {

#line 122 "/home/alois/Documents/bah-bah/src/lexer.bah"
for (; (i<codeLength); 
#line 122 "/home/alois/Documents/bah-bah/src/lexer.bah"
++i) {

#line 123 "/home/alois/Documents/bah-bah/src/lexer.bah"
c = s[i];

#line 124 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((c==(char)10)) {

#line 125 "/home/alois/Documents/bah-bah/src/lexer.bah"
break;
}
};

#line 129 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((i==codeLength)) {

#line 130 "/home/alois/Documents/bah-bah/src/lexer.bah"
break;
}
}
}

#line 136 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((c==(char)10)) {

#line 137 "/home/alois/Documents/bah-bah/src/lexer.bah"
++lineNb;
}

#line 141 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((c==(char)34)) {

#line 143 "/home/alois/Documents/bah-bah/src/lexer.bah"
long int pos = i;

#line 144 "/home/alois/Documents/bah-bah/src/lexer.bah"
long int begLine = lineNb;

#line 145 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_127 = 0;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_127);
    memory->data[____BAH_COMPILER_VAR_127] = c;

#line 146 "/home/alois/Documents/bah-bah/src/lexer.bah"
i = i+1;

#line 147 "/home/alois/Documents/bah-bah/src/lexer.bah"
for (; (i<codeLength); 
#line 147 "/home/alois/Documents/bah-bah/src/lexer.bah"
++i) {

#line 148 "/home/alois/Documents/bah-bah/src/lexer.bah"
c = s[i];

#line 149 "/home/alois/Documents/bah-bah/src/lexer.bah"
char pc = s[i-1];

#line 151 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((c==(char)34)) {

#line 153 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((pc!=(char)92)) {

#line 154 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_128 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_128);
    memory->data[____BAH_COMPILER_VAR_128] = c;

#line 155 "/home/alois/Documents/bah-bah/src/lexer.bah"
break;
}
}

#line 159 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((c==(char)10)) {

#line 160 "/home/alois/Documents/bah-bah/src/lexer.bah"
lineNb = lineNb+1;

#line 161 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((pc!=(char)92)) {

#line 162 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_129 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_129);
    memory->data[____BAH_COMPILER_VAR_129] = (char)92;

#line 163 "/home/alois/Documents/bah-bah/src/lexer.bah"
c = 110;
}
}

#line 166 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_130 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_130);
    memory->data[____BAH_COMPILER_VAR_130] = c;
};

#line 168 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_131 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_131);
    tokens->data[____BAH_COMPILER_VAR_131] = makeToken(pos,lineNb,memory,TOKEN_TYPE_STR);

#line 169 "/home/alois/Documents/bah-bah/src/lexer.bah"
struct Tok lt = tokens->data[len(tokens)-1];

#line 170 "/home/alois/Documents/bah-bah/src/lexer.bah"
lt.begLine = begLine;

#line 171 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_132 = len(tokens)-1;
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_132);
    tokens->data[____BAH_COMPILER_VAR_132] = lt;
}

#line 172 "/home/alois/Documents/bah-bah/src/lexer.bah"
else if (isNumber(c)||isMinus(c,nc)) {

#line 174 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_133 = 0;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_133);
    memory->data[____BAH_COMPILER_VAR_133] = c;

#line 175 "/home/alois/Documents/bah-bah/src/lexer.bah"
long int pos = i;

#line 176 "/home/alois/Documents/bah-bah/src/lexer.bah"
i = i+1;

#line 177 "/home/alois/Documents/bah-bah/src/lexer.bah"
tokenType currentType = TOKEN_TYPE_INT;

#line 178 "/home/alois/Documents/bah-bah/src/lexer.bah"
char isHex = false;

#line 179 "/home/alois/Documents/bah-bah/src/lexer.bah"
for (; (i<codeLength); 
#line 179 "/home/alois/Documents/bah-bah/src/lexer.bah"
++i) {

#line 180 "/home/alois/Documents/bah-bah/src/lexer.bah"
c = s[i];

#line 181 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((c==(char)46)) {

#line 182 "/home/alois/Documents/bah-bah/src/lexer.bah"
currentType = TOKEN_TYPE_FLOAT;
}

#line 183 "/home/alois/Documents/bah-bah/src/lexer.bah"
else if ((isNumber(c)==false)) {

#line 184 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((isHex==false)) {

#line 185 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((c==120)) {

#line 186 "/home/alois/Documents/bah-bah/src/lexer.bah"
isHex = true;
}

#line 187 "/home/alois/Documents/bah-bah/src/lexer.bah"
else {

#line 188 "/home/alois/Documents/bah-bah/src/lexer.bah"
break;
}
}

#line 190 "/home/alois/Documents/bah-bah/src/lexer.bah"
else {

#line 191 "/home/alois/Documents/bah-bah/src/lexer.bah"
if (isUpper(c)) {

#line 192 "/home/alois/Documents/bah-bah/src/lexer.bah"
c = c+(char)32;
}

#line 194 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((c<97)||(c>102)) {

#line 195 "/home/alois/Documents/bah-bah/src/lexer.bah"
break;
}
}

#line 198 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((isHex==false)) {

#line 199 "/home/alois/Documents/bah-bah/src/lexer.bah"
break;
}
}

#line 202 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_134 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_134);
    memory->data[____BAH_COMPILER_VAR_134] = c;
};

#line 204 "/home/alois/Documents/bah-bah/src/lexer.bah"
--i;

#line 205 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_135 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_135);
    tokens->data[____BAH_COMPILER_VAR_135] = makeToken(pos,lineNb,memory,currentType);
}

#line 206 "/home/alois/Documents/bah-bah/src/lexer.bah"
else if ((c==(char)39)) {

#line 208 "/home/alois/Documents/bah-bah/src/lexer.bah"
++i;

#line 209 "/home/alois/Documents/bah-bah/src/lexer.bah"
char n = s[i];

#line 210 "/home/alois/Documents/bah-bah/src/lexer.bah"
char * toInt = intToStr((long int)nc);

#line 211 "/home/alois/Documents/bah-bah/src/lexer.bah"
memory = strToArr(toInt);

#line 212 "/home/alois/Documents/bah-bah/src/lexer.bah"
++i;

#line 213 "/home/alois/Documents/bah-bah/src/lexer.bah"
c = s[i];

#line 214 "/home/alois/Documents/bah-bah/src/lexer.bah"
if (__builtin_expect((c!=(char)39), 0)) {

#line 215 "/home/alois/Documents/bah-bah/src/lexer.bah"
lexerErr(lineNb,i,"Missing closing tag in char declaration.");
}

#line 217 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_136 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_136);
    tokens->data[____BAH_COMPILER_VAR_136] = makeToken(i-1,lineNb,memory,TOKEN_TYPE_CHAR);
}

#line 218 "/home/alois/Documents/bah-bah/src/lexer.bah"
else if ((c==(char)35)) {

#line 220 "/home/alois/Documents/bah-bah/src/lexer.bah"
long int pos = i;

#line 221 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_137 = 0;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_137);
    memory->data[____BAH_COMPILER_VAR_137] = c;

#line 222 "/home/alois/Documents/bah-bah/src/lexer.bah"
++i;

#line 223 "/home/alois/Documents/bah-bah/src/lexer.bah"
for (; (i<codeLength); 
#line 223 "/home/alois/Documents/bah-bah/src/lexer.bah"
++i) {

#line 224 "/home/alois/Documents/bah-bah/src/lexer.bah"
c = s[i];

#line 225 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((isAlphaNumeric(c)==false)) {

#line 226 "/home/alois/Documents/bah-bah/src/lexer.bah"
break;
}

#line 228 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_138 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_138);
    memory->data[____BAH_COMPILER_VAR_138] = c;
};

#line 230 "/home/alois/Documents/bah-bah/src/lexer.bah"
--i;

#line 231 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_139 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_139);
    tokens->data[____BAH_COMPILER_VAR_139] = makeToken(pos,lineNb,memory,TOKEN_TYPE_KEYWORD);
}

#line 232 "/home/alois/Documents/bah-bah/src/lexer.bah"
else if (inArray(c,enclavers)) {

#line 234 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_140 = 0;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_140);
    memory->data[____BAH_COMPILER_VAR_140] = c;

#line 235 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_141 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_141);
    tokens->data[____BAH_COMPILER_VAR_141] = makeToken(i,lineNb,memory,TOKEN_TYPE_ENCL);
}

#line 236 "/home/alois/Documents/bah-bah/src/lexer.bah"
else if (inArray(c,syntaxes)) {

#line 240 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((c==60)) {

#line 241 "/home/alois/Documents/bah-bah/src/lexer.bah"
long int pos = i;

#line 242 "/home/alois/Documents/bah-bah/src/lexer.bah"
char isCast = false;

#line 243 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_142 = 0;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_142);
    memory->data[____BAH_COMPILER_VAR_142] = c;

#line 244 "/home/alois/Documents/bah-bah/src/lexer.bah"
++i;

#line 245 "/home/alois/Documents/bah-bah/src/lexer.bah"
for (; (i<codeLength); 
#line 245 "/home/alois/Documents/bah-bah/src/lexer.bah"
++i) {

#line 246 "/home/alois/Documents/bah-bah/src/lexer.bah"
c = s[i];

#line 247 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((c==62)) {

#line 248 "/home/alois/Documents/bah-bah/src/lexer.bah"
isCast = true;

#line 249 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_143 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_143);
    memory->data[____BAH_COMPILER_VAR_143] = c;

#line 250 "/home/alois/Documents/bah-bah/src/lexer.bah"
break;
}

#line 252 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((isAlphaNumeric(c)==false)&&(c!=42)&&(c!=58)&&(c!=95)&&(c!=91)&&(c!=93)) {

#line 253 "/home/alois/Documents/bah-bah/src/lexer.bah"
break;
}

#line 255 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_144 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_144);
    memory->data[____BAH_COMPILER_VAR_144] = c;
};

#line 257 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((isCast==true)) {

#line 258 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_145 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_145);
    tokens->data[____BAH_COMPILER_VAR_145] = makeToken(pos,lineNb,memory,TOKEN_TYPE_CAST);

#line 259 "/home/alois/Documents/bah-bah/src/lexer.bah"
continue;
}

#line 261 "/home/alois/Documents/bah-bah/src/lexer.bah"
i = pos;

#line 262 "/home/alois/Documents/bah-bah/src/lexer.bah"
c = 60;

#line 263 "/home/alois/Documents/bah-bah/src/lexer.bah"
clear(memory);
}

#line 266 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_146 = 0;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_146);
    memory->data[____BAH_COMPILER_VAR_146] = c;

#line 267 "/home/alois/Documents/bah-bah/src/lexer.bah"
long int pos = i;

#line 268 "/home/alois/Documents/bah-bah/src/lexer.bah"
++i;

#line 269 "/home/alois/Documents/bah-bah/src/lexer.bah"
char fc = c;

#line 270 "/home/alois/Documents/bah-bah/src/lexer.bah"
for (; (i<codeLength); 
#line 270 "/home/alois/Documents/bah-bah/src/lexer.bah"
++i) {

#line 271 "/home/alois/Documents/bah-bah/src/lexer.bah"
c = s[i];

#line 272 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((____BAH_COMPILER_VAR_147(syntaxes, c)==false)) {

#line 273 "/home/alois/Documents/bah-bah/src/lexer.bah"
break;
}

#line 276 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((fc==60)) {

#line 277 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((c!=45)&&(c!=61)&&(c!=60)) {

#line 278 "/home/alois/Documents/bah-bah/src/lexer.bah"
break;
}
}

#line 280 "/home/alois/Documents/bah-bah/src/lexer.bah"
else if ((c==124)) {

#line 281 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((fc!=c)) {

#line 282 "/home/alois/Documents/bah-bah/src/lexer.bah"
break;
}
}

#line 284 "/home/alois/Documents/bah-bah/src/lexer.bah"
else if ((c==38)) {

#line 285 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((fc!=c)) {

#line 286 "/home/alois/Documents/bah-bah/src/lexer.bah"
break;
}
}

#line 288 "/home/alois/Documents/bah-bah/src/lexer.bah"
else if ((c!=61)) {

#line 289 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((c!=62)) {

#line 290 "/home/alois/Documents/bah-bah/src/lexer.bah"
break;
}
}

#line 293 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_148 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_148);
    memory->data[____BAH_COMPILER_VAR_148] = c;
};

#line 295 "/home/alois/Documents/bah-bah/src/lexer.bah"
--i;

#line 296 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_149 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_149);
    tokens->data[____BAH_COMPILER_VAR_149] = makeToken(pos,lineNb,memory,TOKEN_TYPE_SYNTAX);
}

#line 297 "/home/alois/Documents/bah-bah/src/lexer.bah"
else if ((c==46)) {

#line 299 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_150 = 0;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_150);
    memory->data[____BAH_COMPILER_VAR_150] = c;

#line 300 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_151 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_151);
    tokens->data[____BAH_COMPILER_VAR_151] = makeToken(i,lineNb,memory,TOKEN_TYPE_SEP);
}

#line 301 "/home/alois/Documents/bah-bah/src/lexer.bah"
else if (isAlphaNumeric(c)||(c==95)) {

#line 303 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_152 = 0;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_152);
    memory->data[____BAH_COMPILER_VAR_152] = c;

#line 304 "/home/alois/Documents/bah-bah/src/lexer.bah"
long int pos = i;

#line 305 "/home/alois/Documents/bah-bah/src/lexer.bah"
++i;

#line 307 "/home/alois/Documents/bah-bah/src/lexer.bah"
for (; (i<codeLength); 
#line 307 "/home/alois/Documents/bah-bah/src/lexer.bah"
++i) {

#line 308 "/home/alois/Documents/bah-bah/src/lexer.bah"
c = s[i];

#line 309 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((isAlphaNumeric(c)==false)) {

#line 310 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((c!=95)) {

#line 311 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((c==62)) {

#line 312 "/home/alois/Documents/bah-bah/src/lexer.bah"
char lc = memory->data[len(memory)-1];

#line 313 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((lc==45)) {

#line 314 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_153 = len(memory)-1;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_153);
    memory->data[____BAH_COMPILER_VAR_153] = (char)0;

#line 315 "/home/alois/Documents/bah-bah/src/lexer.bah"
--i;

#line 316 "/home/alois/Documents/bah-bah/src/lexer.bah"
break;
}
}

#line 319 "/home/alois/Documents/bah-bah/src/lexer.bah"
break;
}
}

#line 323 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_154 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_154);
    memory->data[____BAH_COMPILER_VAR_154] = c;
};

#line 325 "/home/alois/Documents/bah-bah/src/lexer.bah"
--i;

#line 326 "/home/alois/Documents/bah-bah/src/lexer.bah"
tokenType currentType = TOKEN_TYPE_VAR;

#line 328 "/home/alois/Documents/bah-bah/src/lexer.bah"
char * memstr = arrAsStr(memory);

#line 331 "/home/alois/Documents/bah-bah/src/lexer.bah"
if (____BAH_COMPILER_VAR_155(keywords, memstr)) {

#line 332 "/home/alois/Documents/bah-bah/src/lexer.bah"
currentType = TOKEN_TYPE_KEYWORD;
}

#line 335 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_156 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_156);
    tokens->data[____BAH_COMPILER_VAR_156] = makeToken(pos,lineNb,memory,currentType);
}
};

#line 339 "/home/alois/Documents/bah-bah/src/lexer.bah"
totalLines = totalLines+lineNb-1;

#line 340 "/home/alois/Documents/bah-bah/src/lexer.bah"
dur = getTimeUnix()-dur;

#line 341 "/home/alois/Documents/bah-bah/src/lexer.bah"
totalLexerTime = totalLexerTime+dur;

#line 342 "/home/alois/Documents/bah-bah/src/lexer.bah"
return tokens;
};

#line 44 "/home/alois/Documents/bah-bah/src/main.bah"

#line 1 "/home/alois/Documents/bah-bah/src/type.bah"

#line 2 "/home/alois/Documents/bah-bah/src/type.bah"

#line 4 "/home/alois/Documents/bah-bah/src/type.bah"

#line 5 "/home/alois/Documents/bah-bah/src/type.bah"

#line 1 "/home/alois/Documents/bah-bah/src/struct.bah"

#line 2 "/home/alois/Documents/bah-bah/src/struct.bah"

#line 4 "/home/alois/Documents/bah-bah/src/struct.bah"

#line 6 "/home/alois/Documents/bah-bah/src/struct.bah"
char hasStructSep(struct string* n){

#line 7 "/home/alois/Documents/bah-bah/src/struct.bah"
if (string__count(n,".")) {

#line 8 "/home/alois/Documents/bah-bah/src/struct.bah"
return true;
}

#line 10 "/home/alois/Documents/bah-bah/src/struct.bah"
if (string__count(n,"->")) {

#line 11 "/home/alois/Documents/bah-bah/src/struct.bah"
return true;
}

#line 13 "/home/alois/Documents/bah-bah/src/struct.bah"
return false;
};

#line 16 "/home/alois/Documents/bah-bah/src/struct.bah"
struct string splitStructSepBefore(struct string* n){

#line 18 "/home/alois/Documents/bah-bah/src/struct.bah"
if (string__count(n,".")) {

#line 19 "/home/alois/Documents/bah-bah/src/struct.bah"
char * ____BAH_COMPILER_VAR_157 =splitStringBefore(*n,".");struct string res = string(____BAH_COMPILER_VAR_157);

#line 20 "/home/alois/Documents/bah-bah/src/struct.bah"
return res;
}

#line 22 "/home/alois/Documents/bah-bah/src/struct.bah"
if (string__count(n,"->")) {

#line 23 "/home/alois/Documents/bah-bah/src/struct.bah"
char * ____BAH_COMPILER_VAR_158 =splitStringBefore(*n,"->");struct string res = string(____BAH_COMPILER_VAR_158);

#line 24 "/home/alois/Documents/bah-bah/src/struct.bah"
return res;
}

#line 27 "/home/alois/Documents/bah-bah/src/struct.bah"
return string("");
};

#line 30 "/home/alois/Documents/bah-bah/src/struct.bah"
struct string splitStructSepAfter(struct string n){

#line 31 "/home/alois/Documents/bah-bah/src/struct.bah"
register long int i = n.length;

#line 31 "/home/alois/Documents/bah-bah/src/struct.bah"
while ((i>0)) {

#line 32 "/home/alois/Documents/bah-bah/src/struct.bah"
char c = string__charAt(&n,i);

#line 33 "/home/alois/Documents/bah-bah/src/struct.bah"
if ((c==46)) {

#line 34 "/home/alois/Documents/bah-bah/src/struct.bah"
break;
}

#line 35 "/home/alois/Documents/bah-bah/src/struct.bah"
else if ((c==62)) {

#line 36 "/home/alois/Documents/bah-bah/src/struct.bah"
char pc = string__charAt(&n,i-1);

#line 37 "/home/alois/Documents/bah-bah/src/struct.bah"
if ((pc==45)) {

#line 38 "/home/alois/Documents/bah-bah/src/struct.bah"
break;
}
}

#line 41 "/home/alois/Documents/bah-bah/src/struct.bah"
i = i-1;
};

#line 43 "/home/alois/Documents/bah-bah/src/struct.bah"
i = i+1;

#line 44 "/home/alois/Documents/bah-bah/src/struct.bah"
string__trimLeft(&n,i);

#line 45 "/home/alois/Documents/bah-bah/src/struct.bah"
return n;
};

#line 49 "/home/alois/Documents/bah-bah/src/struct.bah"
struct cStruct* searchStruct(char * name,struct Elems* elems){

#line 51 "/home/alois/Documents/bah-bah/src/struct.bah"
struct string n = string(name);

#line 52 "/home/alois/Documents/bah-bah/src/struct.bah"
string__replace(&n,"&","");

#line 53 "/home/alois/Documents/bah-bah/src/struct.bah"
string__replace(&n,"*","");

#line 54 "/home/alois/Documents/bah-bah/src/struct.bah"
name = n.content;

#line 56 "/home/alois/Documents/bah-bah/src/struct.bah"
register long int i = len(elems->structs)-1;

#line 56 "/home/alois/Documents/bah-bah/src/struct.bah"
for (; (i!=-1); 
#line 56 "/home/alois/Documents/bah-bah/src/struct.bah"
--i) {

#line 57 "/home/alois/Documents/bah-bah/src/struct.bah"
struct cStruct* s = elems->structs->data[i];

#line 58 "/home/alois/Documents/bah-bah/src/struct.bah"
if ((strcmp(s->name, name) == 0)) {

#line 59 "/home/alois/Documents/bah-bah/src/struct.bah"
return s;
}
};

#line 62 "/home/alois/Documents/bah-bah/src/struct.bah"
return null;
};

#line 65 "/home/alois/Documents/bah-bah/src/struct.bah"
struct structMemb* searchStructMemb(char * name,struct cStruct* s,struct Elems* elems){

#line 66 "/home/alois/Documents/bah-bah/src/struct.bah"
struct string n = string(name);

#line 67 "/home/alois/Documents/bah-bah/src/struct.bah"
if (hasStructSep(&n)) {

#line 68 "/home/alois/Documents/bah-bah/src/struct.bah"
struct string rn = splitStructSepBefore(&n);

#line 69 "/home/alois/Documents/bah-bah/src/struct.bah"
name = rn.content;

#line 70 "/home/alois/Documents/bah-bah/src/struct.bah"
string__trimLeft(&n,rn.length);

#line 71 "/home/alois/Documents/bah-bah/src/struct.bah"
if (string__hasPrefix(&n,".")) {

#line 72 "/home/alois/Documents/bah-bah/src/struct.bah"
string__trimLeft(&n,1);
}

#line 73 "/home/alois/Documents/bah-bah/src/struct.bah"
else {

#line 74 "/home/alois/Documents/bah-bah/src/struct.bah"
string__trimLeft(&n,2);
}

#line 76 "/home/alois/Documents/bah-bah/src/struct.bah"
char * membs = n.content;

#line 77 "/home/alois/Documents/bah-bah/src/struct.bah"
struct structMemb* memb = searchStructMemb(name,s,elems);

#line 78 "/home/alois/Documents/bah-bah/src/struct.bah"
if ((n.length>0)) {

#line 79 "/home/alois/Documents/bah-bah/src/struct.bah"
s = searchStruct(memb->type,elems);

#line 80 "/home/alois/Documents/bah-bah/src/struct.bah"
char * nstr = string__str(&n);

#line 81 "/home/alois/Documents/bah-bah/src/struct.bah"
memb = searchStructMemb(nstr,s,elems);
}

#line 83 "/home/alois/Documents/bah-bah/src/struct.bah"
return memb;
}

#line 86 "/home/alois/Documents/bah-bah/src/struct.bah"
array(struct structMemb*)* members = s->members;

#line 87 "/home/alois/Documents/bah-bah/src/struct.bah"
register long int i = 0;

#line 87 "/home/alois/Documents/bah-bah/src/struct.bah"
while ((i<len(members))) {

#line 88 "/home/alois/Documents/bah-bah/src/struct.bah"
struct structMemb* m = members->data[i];

#line 89 "/home/alois/Documents/bah-bah/src/struct.bah"
if ((strcmp(m->name, name) == 0)) {

#line 90 "/home/alois/Documents/bah-bah/src/struct.bah"
return m;
}

#line 92 "/home/alois/Documents/bah-bah/src/struct.bah"
i = i+1;
};

#line 94 "/home/alois/Documents/bah-bah/src/struct.bah"
array(struct func*)* mthds = s->methods;

#line 95 "/home/alois/Documents/bah-bah/src/struct.bah"
i = 0;

#line 95 "/home/alois/Documents/bah-bah/src/struct.bah"
while ((i<len(mthds))) {

#line 96 "/home/alois/Documents/bah-bah/src/struct.bah"
struct func* m = mthds->data[i];

#line 97 "/home/alois/Documents/bah-bah/src/struct.bah"
if ((strcmp(m->name, name) == 0)) {

#line 98 "/home/alois/Documents/bah-bah/src/struct.bah"
struct structMemb* ____BAH_COMPILER_VAR_159 = memoryAlloc(sizeof(struct structMemb));
____BAH_COMPILER_VAR_159->name = "";
____BAH_COMPILER_VAR_159->type = "";
____BAH_COMPILER_VAR_159->constVal = "";
____BAH_COMPILER_VAR_159->from = "";
____BAH_COMPILER_VAR_159->def = "";
struct structMemb* sm = ____BAH_COMPILER_VAR_159;

#line 99 "/home/alois/Documents/bah-bah/src/struct.bah"
sm->name = m->name;

#line 100 "/home/alois/Documents/bah-bah/src/struct.bah"
sm->from = m->from;

#line 101 "/home/alois/Documents/bah-bah/src/struct.bah"
sm->type = m->returns->type;

#line 102 "/home/alois/Documents/bah-bah/src/struct.bah"
sm->isFn = true;

#line 103 "/home/alois/Documents/bah-bah/src/struct.bah"
return sm;
}

#line 105 "/home/alois/Documents/bah-bah/src/struct.bah"
i = i+1;
};

#line 108 "/home/alois/Documents/bah-bah/src/struct.bah"
if ((strlen(s->extendedFrom)==0)) {

#line 109 "/home/alois/Documents/bah-bah/src/struct.bah"
return null;
}

#line 112 "/home/alois/Documents/bah-bah/src/struct.bah"
struct cStruct* es = searchStruct(s->extendedFrom,elems);

#line 113 "/home/alois/Documents/bah-bah/src/struct.bah"
if ((es==null)) {

#line 114 "/home/alois/Documents/bah-bah/src/struct.bah"
return null;
}

#line 117 "/home/alois/Documents/bah-bah/src/struct.bah"
return searchStructMemb(name,es,elems);
};

#line 120 "/home/alois/Documents/bah-bah/src/struct.bah"
struct func* searchFunc(char * n,struct Elems* e,char c);

#line 121 "/home/alois/Documents/bah-bah/src/struct.bah"
struct func* parseFnType(struct string n);

#line 123 "/home/alois/Documents/bah-bah/src/struct.bah"
struct func* searchStructMethod(char * name,struct cStruct* s,struct Elems* elems){

#line 124 "/home/alois/Documents/bah-bah/src/struct.bah"
if ((s==null)) {

#line 125 "/home/alois/Documents/bah-bah/src/struct.bah"
return null;
}

#line 128 "/home/alois/Documents/bah-bah/src/struct.bah"
char** ____BAH_COMPILER_VAR_160 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_160[2] = name;____BAH_COMPILER_VAR_160[1] = "__";____BAH_COMPILER_VAR_160[0] = s->name;char * ____BAH_COMPILER_VAR_161 =__Bah_multiple_concat(____BAH_COMPILER_VAR_160, 3);struct func* fn = searchFunc(____BAH_COMPILER_VAR_161,elems,true);

#line 129 "/home/alois/Documents/bah-bah/src/struct.bah"
if ((fn!=null)) {

#line 130 "/home/alois/Documents/bah-bah/src/struct.bah"
return fn;
}

#line 133 "/home/alois/Documents/bah-bah/src/struct.bah"
register long int i = 0;

#line 133 "/home/alois/Documents/bah-bah/src/struct.bah"
for (; (i<len(s->members)); 
#line 133 "/home/alois/Documents/bah-bah/src/struct.bah"
++i) {

#line 135 "/home/alois/Documents/bah-bah/src/struct.bah"
if ((strcmp(s->members->data[i]->name, name) == 0)) {

#line 136 "/home/alois/Documents/bah-bah/src/struct.bah"
struct string ____BAH_COMPILER_VAR_162 =string(s->members->data[i]->type);fn = parseFnType(____BAH_COMPILER_VAR_162);

#line 137 "/home/alois/Documents/bah-bah/src/struct.bah"
fn->name = name;

#line 138 "/home/alois/Documents/bah-bah/src/struct.bah"
fn->isVar = true;

#line 139 "/home/alois/Documents/bah-bah/src/struct.bah"
return fn;
}
};

#line 143 "/home/alois/Documents/bah-bah/src/struct.bah"
s = searchStruct(s->extendedFrom,elems);

#line 145 "/home/alois/Documents/bah-bah/src/struct.bah"
return searchStructMethod(name,s,elems);
};

#line 7 "/home/alois/Documents/bah-bah/src/type.bah"
char typeAsStar(char * t){

#line 8 "/home/alois/Documents/bah-bah/src/type.bah"
return (t[strlen(t)-1]==42);
};

#line 11 "/home/alois/Documents/bah-bah/src/type.bah"
char isRCPpointerType(char * t){

#line 12 "/home/alois/Documents/bah-bah/src/type.bah"
if (strHasPrefix(t,"function(")) {

#line 13 "/home/alois/Documents/bah-bah/src/type.bah"
return false;
}

#line 15 "/home/alois/Documents/bah-bah/src/type.bah"
return (strcmp(t, "cpstring") == 0)||(strcmp(t, "ptr") == 0)||typeAsStar(t)||strHasPrefix(t,"[]")||strHasPrefix(t,"chan:")||strHasPrefix(t,"map:");
};

#line 18 "/home/alois/Documents/bah-bah/src/type.bah"
char isRCPtype(char * t,struct Elems* elems){

#line 19 "/home/alois/Documents/bah-bah/src/type.bah"
if ((isRCPpointerType(t)==true)) {

#line 20 "/home/alois/Documents/bah-bah/src/type.bah"
return true;
}

#line 22 "/home/alois/Documents/bah-bah/src/type.bah"
struct cStruct* s = searchStruct(t,elems);

#line 23 "/home/alois/Documents/bah-bah/src/type.bah"
return (s!=null)&&(s->isBinding==false);
};

#line 27 "/home/alois/Documents/bah-bah/src/type.bah"
struct string getCType(char * t,struct Elems* elems){

#line 28 "/home/alois/Documents/bah-bah/src/type.bah"
if ((strlen(t)==0)) {

#line 29 "/home/alois/Documents/bah-bah/src/type.bah"
return string("void");
}

#line 32 "/home/alois/Documents/bah-bah/src/type.bah"
struct string tp = string(t);

#line 33 "/home/alois/Documents/bah-bah/src/type.bah"
string__replace(&tp," ","");

#line 34 "/home/alois/Documents/bah-bah/src/type.bah"
if (string__hasPrefix(&tp,"[]")) {

#line 35 "/home/alois/Documents/bah-bah/src/type.bah"
string__trimLeft(&tp,2);

#line 36 "/home/alois/Documents/bah-bah/src/type.bah"
char * tpstr = string__str(&tp);

#line 37 "/home/alois/Documents/bah-bah/src/type.bah"
tp = getCType(tpstr,elems);

#line 38 "/home/alois/Documents/bah-bah/src/type.bah"
t = string__str(&tp);

#line 39 "/home/alois/Documents/bah-bah/src/type.bah"
char** ____BAH_COMPILER_VAR_163 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_163[2] = ")*";____BAH_COMPILER_VAR_163[1] = t;____BAH_COMPILER_VAR_163[0] = "array(";char * ____BAH_COMPILER_VAR_164 =__Bah_multiple_concat(____BAH_COMPILER_VAR_163, 3);char * r = ____BAH_COMPILER_VAR_164;

#line 40 "/home/alois/Documents/bah-bah/src/type.bah"
return string(r);
}

#line 42 "/home/alois/Documents/bah-bah/src/type.bah"
string__replace(&tp,"!","*");

#line 45 "/home/alois/Documents/bah-bah/src/type.bah"
struct string ctp = tp;

#line 46 "/home/alois/Documents/bah-bah/src/type.bah"
string__replace(&ctp,"*","");

#line 48 "/home/alois/Documents/bah-bah/src/type.bah"
if (string__hasPrefix(&tp,"tuple:")) {

#line 49 "/home/alois/Documents/bah-bah/src/type.bah"
array(struct string)* parts = splitString(tp,":");

#line 50 "/home/alois/Documents/bah-bah/src/type.bah"
char * ____BAH_COMPILER_VAR_165 =string__str(&parts->data[2]);
                struct string ____BAH_COMPILER_VAR_166 = getCType(____BAH_COMPILER_VAR_165,elems);
                char** ____BAH_COMPILER_VAR_167 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_167[1] = "*";____BAH_COMPILER_VAR_167[0] = string__str(&____BAH_COMPILER_VAR_166);char * ____BAH_COMPILER_VAR_168 =__Bah_multiple_concat(____BAH_COMPILER_VAR_167, 2);string__set(&tp,____BAH_COMPILER_VAR_168);
}

#line 51 "/home/alois/Documents/bah-bah/src/type.bah"
else if ((string__hasPrefix(&tp,"chan:")==1)) {

#line 52 "/home/alois/Documents/bah-bah/src/type.bah"
string__set(&tp,"struct channel *");
}

#line 53 "/home/alois/Documents/bah-bah/src/type.bah"
else if ((string__hasPrefix(&tp,"map:")==1)) {

#line 54 "/home/alois/Documents/bah-bah/src/type.bah"
string__set(&tp,"struct mapWrapper *");
}

#line 55 "/home/alois/Documents/bah-bah/src/type.bah"
else if ((string__hasPrefix(&tp,"buffer:")==1)) {

#line 56 "/home/alois/Documents/bah-bah/src/type.bah"
string__set(&tp,"char*");
}

#line 57 "/home/alois/Documents/bah-bah/src/type.bah"
else if ((strcmp(string__str(&ctp), "int") == 0)) {

#line 58 "/home/alois/Documents/bah-bah/src/type.bah"
string__replace(&tp,"int","long int");
}

#line 59 "/home/alois/Documents/bah-bah/src/type.bah"
else if ((strcmp(string__str(&ctp), "int32") == 0)) {

#line 60 "/home/alois/Documents/bah-bah/src/type.bah"
string__replace(&tp,"int32","int");
}

#line 61 "/home/alois/Documents/bah-bah/src/type.bah"
else if ((strcmp(string__str(&ctp), "uint32") == 0)) {

#line 62 "/home/alois/Documents/bah-bah/src/type.bah"
string__replace(&tp,"uint32","unsigned int");
}

#line 63 "/home/alois/Documents/bah-bah/src/type.bah"
else if ((strcmp(string__str(&ctp), "uint") == 0)) {

#line 64 "/home/alois/Documents/bah-bah/src/type.bah"
string__replace(&tp,"uint","unsigned long int");
}

#line 65 "/home/alois/Documents/bah-bah/src/type.bah"
else if ((strcmp(string__str(&ctp), "float32") == 0)) {

#line 66 "/home/alois/Documents/bah-bah/src/type.bah"
string__replace(&tp,"float32","float");
}

#line 67 "/home/alois/Documents/bah-bah/src/type.bah"
else if ((strcmp(string__str(&ctp), "ufloat32") == 0)) {

#line 68 "/home/alois/Documents/bah-bah/src/type.bah"
string__replace(&tp,"ufloat32","unsigned float");
}

#line 69 "/home/alois/Documents/bah-bah/src/type.bah"
else if ((strcmp(string__str(&ctp), "ufloat") == 0)) {

#line 70 "/home/alois/Documents/bah-bah/src/type.bah"
string__replace(&tp,"ufloat","unsigned double");
}

#line 71 "/home/alois/Documents/bah-bah/src/type.bah"
else if ((strcmp(string__str(&ctp), "float") == 0)) {

#line 72 "/home/alois/Documents/bah-bah/src/type.bah"
string__replace(&tp,"float","double");
}

#line 73 "/home/alois/Documents/bah-bah/src/type.bah"
else if ((strcmp(string__str(&ctp), "long") == 0)) {

#line 74 "/home/alois/Documents/bah-bah/src/type.bah"
string__replace(&tp,"long","long long");
}

#line 75 "/home/alois/Documents/bah-bah/src/type.bah"
else if ((strcmp(string__str(&ctp), "ulong") == 0)) {

#line 76 "/home/alois/Documents/bah-bah/src/type.bah"
string__replace(&tp,"ulong","unsigned long long");
}

#line 77 "/home/alois/Documents/bah-bah/src/type.bah"
else if ((strcmp(string__str(&ctp), "cpstring") == 0)) {

#line 78 "/home/alois/Documents/bah-bah/src/type.bah"
string__replace(&tp,"cpstring","char *");
}

#line 79 "/home/alois/Documents/bah-bah/src/type.bah"
else if ((strcmp(string__str(&ctp), "ptr") == 0)) {

#line 80 "/home/alois/Documents/bah-bah/src/type.bah"
string__replace(&tp,"ptr","void *");
}

#line 81 "/home/alois/Documents/bah-bah/src/type.bah"
else if ((strcmp(string__str(&ctp), "ushort") == 0)) {

#line 82 "/home/alois/Documents/bah-bah/src/type.bah"
string__replace(&tp,"ushort","unsigned short");
}

#line 83 "/home/alois/Documents/bah-bah/src/type.bah"
else if ((strcmp(string__str(&ctp), "byte") == 0)) {

#line 84 "/home/alois/Documents/bah-bah/src/type.bah"
string__replace(&tp,"byte","unsigned char");
}

#line 85 "/home/alois/Documents/bah-bah/src/type.bah"
else if ((strcmp(string__str(&ctp), "bool") == 0)) {

#line 86 "/home/alois/Documents/bah-bah/src/type.bah"
string__replace(&tp,"bool","char");
}

#line 87 "/home/alois/Documents/bah-bah/src/type.bah"
else if ((strcmp(string__str(&ctp), "char") == 0)) {
}

#line 89 "/home/alois/Documents/bah-bah/src/type.bah"
else {

#line 91 "/home/alois/Documents/bah-bah/src/type.bah"
char * ctpstr = string__str(&ctp);

#line 92 "/home/alois/Documents/bah-bah/src/type.bah"
struct cStruct* s = searchStruct(ctpstr,elems);

#line 93 "/home/alois/Documents/bah-bah/src/type.bah"
if ((s!=null)) {

#line 94 "/home/alois/Documents/bah-bah/src/type.bah"
string__prepend(&tp,"struct ");
}

#line 95 "/home/alois/Documents/bah-bah/src/type.bah"
else {

#line 96 "/home/alois/Documents/bah-bah/src/type.bah"
register long int i = 0;

#line 96 "/home/alois/Documents/bah-bah/src/type.bah"
while ((i<len(elems->types))) {

#line 97 "/home/alois/Documents/bah-bah/src/type.bah"
char * ct = elems->types->data[i];

#line 98 "/home/alois/Documents/bah-bah/src/type.bah"
if (string__compare(&ctp,ct)) {

#line 99 "/home/alois/Documents/bah-bah/src/type.bah"
return tp;
}

#line 101 "/home/alois/Documents/bah-bah/src/type.bah"
i = i+1;
};

#line 103 "/home/alois/Documents/bah-bah/src/type.bah"
return string("");
}
}

#line 108 "/home/alois/Documents/bah-bah/src/type.bah"
return tp;
};

#line 112 "/home/alois/Documents/bah-bah/src/type.bah"
array(char *)* intTypes;

#line 120 "/home/alois/Documents/bah-bah/src/type.bah"
array(char *)* floatTypes;

#line 127 "/home/alois/Documents/bah-bah/src/type.bah"
char * maybeToPtr(char * a){

#line 128 "/home/alois/Documents/bah-bah/src/type.bah"
if ((a[strlen(a)-1]!=33)) {

#line 129 "/home/alois/Documents/bah-bah/src/type.bah"
return a;
}

#line 131 "/home/alois/Documents/bah-bah/src/type.bah"
char** ____BAH_COMPILER_VAR_169 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_169[1] = "*";____BAH_COMPILER_VAR_169[0] = cpstringSubsitute(a, 0, strlen(a)-1);char * ____BAH_COMPILER_VAR_170 =__Bah_multiple_concat(____BAH_COMPILER_VAR_169, 2);a = ____BAH_COMPILER_VAR_170;

#line 132 "/home/alois/Documents/bah-bah/src/type.bah"
return a;
};

#line 135 "/home/alois/Documents/bah-bah/src/type.bah"
char compTypeEquiv(char * a,char * b,char first){

#line 137 "/home/alois/Documents/bah-bah/src/type.bah"
if ((strcmp(a, "cpstring") == 0)&&strHasPrefix(b,"buffer:")) {

#line 138 "/home/alois/Documents/bah-bah/src/type.bah"
return true;
}

#line 141 "/home/alois/Documents/bah-bah/src/type.bah"
if ((first==false)) {

#line 142 "/home/alois/Documents/bah-bah/src/type.bah"
return false;
}

#line 145 "/home/alois/Documents/bah-bah/src/type.bah"
if (compTypeEquiv(b,a,false)) {

#line 146 "/home/alois/Documents/bah-bah/src/type.bah"
return true;
}

#line 150 "/home/alois/Documents/bah-bah/src/type.bah"
return (strcmp(a, b) == 0);
};

#line 153 "/home/alois/Documents/bah-bah/src/type.bah"
char ____BAH_COMPILER_VAR_171(array(char *)* arr, char * el) {
        if (arr == 0) {
            return 0;
        };
        for(int i=arr->length-1; i!=-1;i--) {
            if (arr->data[i] != 0 && strcmp(arr->data[i], el) == 0) {
                return 1;
            };
        }
        return 0;
        }
char ____BAH_COMPILER_VAR_172(array(char *)* arr, char * el) {
        if (arr == 0) {
            return 0;
        };
        for(int i=arr->length-1; i!=-1;i--) {
            if (arr->data[i] != 0 && strcmp(arr->data[i], el) == 0) {
                return 1;
            };
        }
        return 0;
        }
char ____BAH_COMPILER_VAR_173(array(char *)* arr, char * el) {
        if (arr == 0) {
            return 0;
        };
        for(int i=arr->length-1; i!=-1;i--) {
            if (arr->data[i] != 0 && strcmp(arr->data[i], el) == 0) {
                return 1;
            };
        }
        return 0;
        }
char ____BAH_COMPILER_VAR_174(array(char *)* arr, char * el) {
        if (arr == 0) {
            return 0;
        };
        for(int i=arr->length-1; i!=-1;i--) {
            if (arr->data[i] != 0 && strcmp(arr->data[i], el) == 0) {
                return 1;
            };
        }
        return 0;
        }
char compTypes(char * a,char * b){

#line 154 "/home/alois/Documents/bah-bah/src/type.bah"
a = maybeToPtr(a);

#line 155 "/home/alois/Documents/bah-bah/src/type.bah"
b = maybeToPtr(b);

#line 156 "/home/alois/Documents/bah-bah/src/type.bah"
if ((strcmp(a, b) == 0)||(strcmp(a, "ptr") == 0)||(strcmp(b, "ptr") == 0)) {

#line 157 "/home/alois/Documents/bah-bah/src/type.bah"
return true;
}

#line 160 "/home/alois/Documents/bah-bah/src/type.bah"
if (____BAH_COMPILER_VAR_171(intTypes, a)&&____BAH_COMPILER_VAR_172(intTypes, b)) {

#line 161 "/home/alois/Documents/bah-bah/src/type.bah"
return true;
}

#line 163 "/home/alois/Documents/bah-bah/src/type.bah"
if (____BAH_COMPILER_VAR_173(floatTypes, a)&&____BAH_COMPILER_VAR_174(floatTypes, b)) {

#line 164 "/home/alois/Documents/bah-bah/src/type.bah"
return true;
}

#line 167 "/home/alois/Documents/bah-bah/src/type.bah"
return compTypeEquiv(a,b,true);
};

#line 45 "/home/alois/Documents/bah-bah/src/main.bah"

#line 1 "/home/alois/Documents/bah-bah/src/errors.bah"

#line 2 "/home/alois/Documents/bah-bah/src/errors.bah"

#line 4 "/home/alois/Documents/bah-bah/src/errors.bah"

#line 5 "/home/alois/Documents/bah-bah/src/errors.bah"

#line 1 "/home/alois/Documents/bah-bah/src/logger.bah"

#line 2 "/home/alois/Documents/bah-bah/src/logger.bah"

#line 1 "/opt/bah/json.bah"

#line 2 "/opt/bah/json.bah"

#line 3 "/opt/bah/json.bah"

#line 1 "/opt/bah/reflect.bah"

#line 2 "/opt/bah/reflect.bah"

#line 4 "/opt/bah/reflect.bah"
#include <stddef.h>

#line 12 "/opt/bah/reflect.bah"
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

#line 33 "/opt/bah/reflect.bah"
char * base = origin;

#line 34 "/opt/bah/reflect.bah"
return base+this->offset;
};

#line 40 "/opt/bah/reflect.bah"
typedef array(struct reflectElement)* __BAH_ARR_TYPE_reflectElement;
struct reflectElement __reflect(void * v,long int s,char * t,char * n,char isArr,struct reflectElement* ae,char isStruct,__BAH_ARR_TYPE_reflectElement sl,long int offset){

#line 41 "/opt/bah/reflect.bah"
struct reflectElement ____BAH_COMPILER_VAR_175 = {};
____BAH_COMPILER_VAR_175.structLayout = memoryAlloc(sizeof(array(struct reflectElement)));
            ____BAH_COMPILER_VAR_175.structLayout->length = 0;
            ____BAH_COMPILER_VAR_175.structLayout->elemSize = sizeof(struct reflectElement);
            struct reflectElement re = ____BAH_COMPILER_VAR_175;

#line 42 "/opt/bah/reflect.bah"
re.size = s;

#line 43 "/opt/bah/reflect.bah"
re.type = t;

#line 44 "/opt/bah/reflect.bah"
re.name = n;

#line 45 "/opt/bah/reflect.bah"
re.isArray = isArr;

#line 46 "/opt/bah/reflect.bah"
re.arrayElem = ae;

#line 47 "/opt/bah/reflect.bah"
re.isStruct = isStruct;

#line 48 "/opt/bah/reflect.bah"
re.structLayout = sl;

#line 49 "/opt/bah/reflect.bah"
re.value = v;

#line 50 "/opt/bah/reflect.bah"
re.offset = offset;

#line 51 "/opt/bah/reflect.bah"
return re;
};

#line 54 "/opt/bah/reflect.bah"
typedef void * reflectSymbols;

#line 59 "/opt/bah/reflect.bah"
__BAH_ARR_TYPE_reflectElement __dumpSymbols(__BAH_ARR_TYPE_reflectElement syms){

#line 60 "/opt/bah/reflect.bah"
return syms;
};

#line 64 "/opt/bah/reflect.bah"
struct reflectElement __debug_get_sym(__BAH_ARR_TYPE_reflectElement syms,struct string a){

#line 65 "/opt/bah/reflect.bah"
if ((string__count(&a,".")>0)) {

#line 66 "/opt/bah/reflect.bah"
array(struct string)* parts = splitString(a,".");

#line 67 "/opt/bah/reflect.bah"
struct string p1 = parts->data[0];

#line 68 "/opt/bah/reflect.bah"
struct string p2 = parts->data[1];

#line 69 "/opt/bah/reflect.bah"
register long int j = 0;

#line 69 "/opt/bah/reflect.bah"
for (; (j<len(syms)); 
#line 69 "/opt/bah/reflect.bah"
++j) {

#line 70 "/opt/bah/reflect.bah"
struct reflectElement s = syms->data[j];

#line 71 "/opt/bah/reflect.bah"
if ((strcmp(s.name, string__str(&p1)) == 0)) {

#line 72 "/opt/bah/reflect.bah"
register long int k = 0;

#line 72 "/opt/bah/reflect.bah"
for (; (k<len(s.structLayout)); 
#line 72 "/opt/bah/reflect.bah"
++k) {

#line 73 "/opt/bah/reflect.bah"
struct reflectElement m = s.structLayout->data[k];

#line 74 "/opt/bah/reflect.bah"
if ((strcmp(m.name, string__str(&p2)) == 0)) {

#line 75 "/opt/bah/reflect.bah"
m.value = reflectElement__calculateOffset(&m,s.value);

#line 76 "/opt/bah/reflect.bah"
return m;
}
};

#line 79 "/opt/bah/reflect.bah"
break;
}
};
}

#line 82 "/opt/bah/reflect.bah"
else {

#line 83 "/opt/bah/reflect.bah"
register long int j = 0;

#line 83 "/opt/bah/reflect.bah"
for (; (j<len(syms)); 
#line 83 "/opt/bah/reflect.bah"
++j) {

#line 84 "/opt/bah/reflect.bah"
struct reflectElement s = syms->data[j];

#line 85 "/opt/bah/reflect.bah"
if ((strcmp(s.name, string__str(&a)) == 0)) {

#line 86 "/opt/bah/reflect.bah"
return s;
}
};
}

#line 90 "/opt/bah/reflect.bah"
struct reflectElement ____BAH_COMPILER_VAR_176 = {};
____BAH_COMPILER_VAR_176.structLayout = memoryAlloc(sizeof(array(struct reflectElement)));
            ____BAH_COMPILER_VAR_176.structLayout->length = 0;
            ____BAH_COMPILER_VAR_176.structLayout->elemSize = sizeof(struct reflectElement);
            struct reflectElement ns = ____BAH_COMPILER_VAR_176;

#line 91 "/opt/bah/reflect.bah"
return ns;
};

#line 94 "/opt/bah/reflect.bah"
#define __bah_reflect __reflect

#line 95 "/opt/bah/reflect.bah"
#define __bah_dump_symbols __dumpSymbols

#line 96 "/opt/bah/reflect.bah"
#define __bah_debug_get_sym __debug_get_sym

#line 6 "/opt/bah/json.bah"
#define JSON_TYPE_STRING 0

#line 7 "/opt/bah/json.bah"
#define JSON_TYPE_INT 1

#line 8 "/opt/bah/json.bah"
#define JSON_TYPE_FLOAT 2

#line 9 "/opt/bah/json.bah"
#define JSON_TYPE_ARRAY 3

#line 10 "/opt/bah/json.bah"
#define JSON_TYPE_MAP 4

#line 12 "/opt/bah/json.bah"
char * toJson(struct reflectElement e);

#line 14 "/opt/bah/json.bah"
void json_scan_inner(void * this,struct reflectElement e,char isMember);

#line 19 "/opt/bah/json.bah"
struct jsonElement {
long int type;
char * key;
char * content;
array(struct jsonElement*)* children;
};
struct jsonElement* jsonElement__get(struct jsonElement* this,char * key){

#line 27 "/opt/bah/json.bah"
long int l = len(this->children);

#line 28 "/opt/bah/json.bah"
register long int i = 0;

#line 28 "/opt/bah/json.bah"
while ((i<l)) {

#line 29 "/opt/bah/json.bah"
struct jsonElement* elem = this->children->data[i];

#line 30 "/opt/bah/json.bah"
char fc = cpstringCharAt(elem->key,0);

#line 31 "/opt/bah/json.bah"
if ((fc==(char)34)) {

#line 32 "/opt/bah/json.bah"
array(char)* nk = memoryAlloc(sizeof(array(char)));

nk->length = 0;
nk->elemSize = sizeof(char);

#line 33 "/opt/bah/json.bah"
long int lk = strlen(elem->key);

#line 34 "/opt/bah/json.bah"
register long int j = 1;

#line 34 "/opt/bah/json.bah"
while ((j<lk-1)) {

#line 35 "/opt/bah/json.bah"
char c = cpstringCharAt(elem->key,j);

#line 36 "/opt/bah/json.bah"

    unsigned int ____BAH_COMPILER_VAR_177 = j-1;
    __Bah_realocate_arr(nk, ____BAH_COMPILER_VAR_177);
    nk->data[____BAH_COMPILER_VAR_177] = c;

#line 37 "/opt/bah/json.bah"
j = j+1;
};

#line 39 "/opt/bah/json.bah"
if ((strcmp(arrAsStr(nk), key) == 0)) {

#line 40 "/opt/bah/json.bah"
return elem;
}
}

#line 42 "/opt/bah/json.bah"
else {

#line 43 "/opt/bah/json.bah"
if ((strcmp(elem->key, key) == 0)) {

#line 44 "/opt/bah/json.bah"
return elem;
}
}

#line 47 "/opt/bah/json.bah"
i = i+1;
};

#line 49 "/opt/bah/json.bah"
void * z = (void *)0;

#line 50 "/opt/bah/json.bah"
return z;
};
char * jsonElement__str(struct jsonElement* this){

#line 55 "/opt/bah/json.bah"
char * ctn = this->content;

#line 56 "/opt/bah/json.bah"
return ctn;
};
void jsonElement__scan(struct jsonElement* this,struct reflectElement e){

#line 62 "/opt/bah/json.bah"
json_scan_inner(this,e,false);
};

#line 67 "/opt/bah/json.bah"
void json_scan_inner(void * thisp,struct reflectElement e,char isMember){

#line 68 "/opt/bah/json.bah"
struct jsonElement* this = thisp;

#line 69 "/opt/bah/json.bah"
if ((e.isStruct==true)) {

#line 70 "/opt/bah/json.bah"
register long int i = 0;

#line 70 "/opt/bah/json.bah"
while ((i<len(e.structLayout))) {

#line 71 "/opt/bah/json.bah"
struct reflectElement m = e.structLayout->data[i];

#line 72 "/opt/bah/json.bah"
m.value = reflectElement__calculateOffset(&m,e.value);

#line 73 "/opt/bah/json.bah"
struct jsonElement* ov = jsonElement__get(this,m.name);

#line 74 "/opt/bah/json.bah"
if ((ov!=null)) {

#line 75 "/opt/bah/json.bah"
json_scan_inner(ov,m,true);
}

#line 77 "/opt/bah/json.bah"
i = i+1;
};
}

#line 79 "/opt/bah/json.bah"
else if ((strcmp(e.type, "int") == 0)) {

#line 80 "/opt/bah/json.bah"
long int* ep = e.value;

#line 81 "/opt/bah/json.bah"
*ep = strToInt(this->content);
}

#line 82 "/opt/bah/json.bah"
else if ((strcmp(e.type, "cpstring") == 0)) {

#line 83 "/opt/bah/json.bah"
char ** ep = e.value;

#line 84 "/opt/bah/json.bah"
*ep = this->content;
}

#line 85 "/opt/bah/json.bah"
else if ((strcmp(e.type, "float") == 0)) {

#line 86 "/opt/bah/json.bah"
double* ep = e.value;

#line 87 "/opt/bah/json.bah"
*ep = strToFloat(this->content);
}

#line 88 "/opt/bah/json.bah"
else if ((strcmp(e.type, "bool") == 0)) {

#line 89 "/opt/bah/json.bah"
char* ep = e.value;

#line 90 "/opt/bah/json.bah"
if ((strcmp(this->content, "1") == 0)||(strcmp(this->content, "true") == 0)) {

#line 91 "/opt/bah/json.bah"
*ep = true;
}

#line 92 "/opt/bah/json.bah"
else {

#line 93 "/opt/bah/json.bah"
*ep = false;
}
}

#line 95 "/opt/bah/json.bah"
else if ((e.isArray==true)) {

#line 96 "/opt/bah/json.bah"
if ((len(this->children)==0)) {

#line 97 "/opt/bah/json.bah"
return;
}

#line 100 "/opt/bah/json.bah"
struct reflectElement* ae = e.arrayElem;

#line 101 "/opt/bah/json.bah"
if ((strcmp(ae->type, "int") == 0)) {

#line 102 "/opt/bah/json.bah"
array(long int)* arr = memoryAlloc(sizeof(array(long int)));

arr->length = 0;
arr->elemSize = sizeof(long int);

#line 103 "/opt/bah/json.bah"
void ** arrPtr = e.value;

#line 104 "/opt/bah/json.bah"
if ((isMember==true)) {

#line 105 "/opt/bah/json.bah"
*arrPtr = arr;
}

#line 106 "/opt/bah/json.bah"
else {

#line 107 "/opt/bah/json.bah"
arr = *arrPtr;
}

#line 109 "/opt/bah/json.bah"
register long int i = 0;

#line 109 "/opt/bah/json.bah"
while ((i<len(this->children))) {

#line 110 "/opt/bah/json.bah"
struct jsonElement* c = this->children->data[i];

#line 111 "/opt/bah/json.bah"

    unsigned int ____BAH_COMPILER_VAR_178 = i;
    __Bah_realocate_arr(arr, ____BAH_COMPILER_VAR_178);
    arr->data[____BAH_COMPILER_VAR_178] = strToInt(c->content);

#line 112 "/opt/bah/json.bah"
i = i+1;
};
}

#line 114 "/opt/bah/json.bah"
else if ((strcmp(ae->type, "float") == 0)) {

#line 115 "/opt/bah/json.bah"
array(double)* arr = memoryAlloc(sizeof(array(double)));

arr->length = 0;
arr->elemSize = sizeof(double);

#line 116 "/opt/bah/json.bah"
void ** arrPtr = e.value;

#line 117 "/opt/bah/json.bah"
if ((isMember==true)) {

#line 118 "/opt/bah/json.bah"
*arrPtr = arr;
}

#line 119 "/opt/bah/json.bah"
else {

#line 120 "/opt/bah/json.bah"
arr = *arrPtr;
}

#line 122 "/opt/bah/json.bah"
register long int i = 0;

#line 122 "/opt/bah/json.bah"
while ((i<len(this->children))) {

#line 123 "/opt/bah/json.bah"
struct jsonElement* c = this->children->data[i];

#line 124 "/opt/bah/json.bah"

    unsigned int ____BAH_COMPILER_VAR_179 = i;
    __Bah_realocate_arr(arr, ____BAH_COMPILER_VAR_179);
    arr->data[____BAH_COMPILER_VAR_179] = strToFloat(c->content);

#line 125 "/opt/bah/json.bah"
i = i+1;
};
}

#line 127 "/opt/bah/json.bah"
else if ((strcmp(ae->type, "cpstring") == 0)) {

#line 128 "/opt/bah/json.bah"
array(char *)* arr = memoryAlloc(sizeof(array(char *)));

arr->length = 0;
arr->elemSize = sizeof(char *);

#line 129 "/opt/bah/json.bah"
void ** arrPtr = e.value;

#line 130 "/opt/bah/json.bah"
if ((isMember==true)) {

#line 131 "/opt/bah/json.bah"
*arrPtr = arr;
}

#line 132 "/opt/bah/json.bah"
else {

#line 133 "/opt/bah/json.bah"
arr = *arrPtr;
}

#line 135 "/opt/bah/json.bah"
register long int i = 0;

#line 135 "/opt/bah/json.bah"
while ((i<len(this->children))) {

#line 136 "/opt/bah/json.bah"
struct jsonElement* c = this->children->data[i];

#line 137 "/opt/bah/json.bah"

    unsigned int ____BAH_COMPILER_VAR_180 = i;
    __Bah_realocate_arr(arr, ____BAH_COMPILER_VAR_180);
    arr->data[____BAH_COMPILER_VAR_180] = c->content;

#line 138 "/opt/bah/json.bah"
i = i+1;
};
}

#line 140 "/opt/bah/json.bah"
else if ((ae->isStruct==true)) {

#line 141 "/opt/bah/json.bah"
array(void *)* arr = memoryAlloc(sizeof(array(void *)));

arr->length = 0;
arr->elemSize = sizeof(void *);

#line 142 "/opt/bah/json.bah"
void ** arrPtr = e.value;

#line 143 "/opt/bah/json.bah"
if ((isMember==true)) {

#line 144 "/opt/bah/json.bah"
*arrPtr = arr;
}

#line 145 "/opt/bah/json.bah"
else {

#line 146 "/opt/bah/json.bah"
arr = *arrPtr;
}

#line 148 "/opt/bah/json.bah"
register long int i = 0;

#line 148 "/opt/bah/json.bah"
while ((i<len(this->children))) {

#line 149 "/opt/bah/json.bah"
struct jsonElement* c = this->children->data[i];

#line 150 "/opt/bah/json.bah"
void * ne = memoryAlloc(ae->size);

#line 151 "/opt/bah/json.bah"
register long int j = 0;

#line 151 "/opt/bah/json.bah"
while ((j<len(ae->structLayout))) {

#line 152 "/opt/bah/json.bah"
struct reflectElement m = ae->structLayout->data[j];

#line 153 "/opt/bah/json.bah"
m.value = reflectElement__calculateOffset(&m,ne);

#line 154 "/opt/bah/json.bah"
struct jsonElement* ov = jsonElement__get(c,m.name);

#line 155 "/opt/bah/json.bah"
if ((ov!=null)) {

#line 156 "/opt/bah/json.bah"
json_scan_inner(ov,m,true);
}

#line 158 "/opt/bah/json.bah"
j = j+1;
};

#line 160 "/opt/bah/json.bah"

    unsigned int ____BAH_COMPILER_VAR_181 = i;
    __Bah_realocate_arr(arr, ____BAH_COMPILER_VAR_181);
    arr->data[____BAH_COMPILER_VAR_181] = ne;

#line 161 "/opt/bah/json.bah"
i = i+1;
};
}
}

#line 164 "/opt/bah/json.bah"
else if (strHasPrefix(e.type,"map:")) {

#line 165 "/opt/bah/json.bah"
struct mapWrapper** p = e.value;

#line 166 "/opt/bah/json.bah"
register long int i = 0;

#line 166 "/opt/bah/json.bah"
for (; (i<len(this->children)); 
#line 166 "/opt/bah/json.bah"
++i) {

#line 167 "/opt/bah/json.bah"
struct jsonElement* c = this->children->data[i];

#line 168 "/opt/bah/json.bah"
struct reflectElement* ae = e.arrayElem;

#line 169 "/opt/bah/json.bah"
void * v = memoryAlloc(ae->size);

#line 170 "/opt/bah/json.bah"
ae->value = &v;

#line 171 "/opt/bah/json.bah"
register long int j = 0;

#line 171 "/opt/bah/json.bah"
for (; (j<len(ae->structLayout)); 
#line 171 "/opt/bah/json.bah"
++j) {

#line 172 "/opt/bah/json.bah"
struct reflectElement m = ae->structLayout->data[j];

#line 173 "/opt/bah/json.bah"
m.value = reflectElement__calculateOffset(&m,&v);

#line 174 "/opt/bah/json.bah"

    unsigned int ____BAH_COMPILER_VAR_182 = j;
    __Bah_realocate_arr(ae->structLayout, ____BAH_COMPILER_VAR_182);
    ae->structLayout->data[____BAH_COMPILER_VAR_182] = m;
};

#line 176 "/opt/bah/json.bah"
json_scan_inner(c,*ae,true);

#line 177 "/opt/bah/json.bah"
struct string k = string(c->key);

#line 178 "/opt/bah/json.bah"
string__trimLeft(&k,1);

#line 179 "/opt/bah/json.bah"
string__trimRight(&k,1);

#line 180 "/opt/bah/json.bah"
if (strCount(ae->type,"*")||(strcmp(ae->type, "ptr") == 0)||(strcmp(ae->type, "cpstring") == 0)||strHasPrefix(ae->type,"[]")||strHasPrefix(ae->type,"map:")) {

#line 181 "/opt/bah/json.bah"
struct mapWrapper* m = *p;

#line 182 "/opt/bah/json.bah"
char * ____BAH_COMPILER_VAR_183 =string__str(&k);m->set(m,____BAH_COMPILER_VAR_183,v);
}

#line 183 "/opt/bah/json.bah"
else {

#line 184 "/opt/bah/json.bah"
struct mapWrapper* m = *p;

#line 185 "/opt/bah/json.bah"
char * ____BAH_COMPILER_VAR_184 =string__str(&k);m->set(m,____BAH_COMPILER_VAR_184,&v);
}
};
}
};

#line 193 "/opt/bah/json.bah"
struct jsonElement* parseJson(char * s){

#line 194 "/opt/bah/json.bah"
struct jsonElement* ____BAH_COMPILER_VAR_185 = memoryAlloc(sizeof(struct jsonElement));
____BAH_COMPILER_VAR_185->children = memoryAlloc(sizeof(array(struct jsonElement*)));
            ____BAH_COMPILER_VAR_185->children->length = 0;
            ____BAH_COMPILER_VAR_185->children->elemSize = sizeof(struct jsonElement*);
            struct jsonElement* jsonElem = ____BAH_COMPILER_VAR_185;

#line 195 "/opt/bah/json.bah"
long int lenS = strlen(s);

#line 197 "/opt/bah/json.bah"
register long int i = 0;

#line 197 "/opt/bah/json.bah"
while ((i<lenS)) {

#line 198 "/opt/bah/json.bah"
if ((isSpace(cpstringCharAt(s,i))==false)) {

#line 199 "/opt/bah/json.bah"
break;
}

#line 201 "/opt/bah/json.bah"
i = i+1;
};

#line 204 "/opt/bah/json.bah"
char fc = cpstringCharAt(s,i);

#line 205 "/opt/bah/json.bah"
if ((fc==91)) {

#line 206 "/opt/bah/json.bah"
jsonElem->type = JSON_TYPE_ARRAY;
}

#line 207 "/opt/bah/json.bah"
else if ((fc==123)) {

#line 208 "/opt/bah/json.bah"
jsonElem->type = JSON_TYPE_MAP;
}

#line 209 "/opt/bah/json.bah"
else if ((fc==(char)34)) {

#line 210 "/opt/bah/json.bah"
jsonElem->type = JSON_TYPE_STRING;

#line 211 "/opt/bah/json.bah"
array(char)* ns = memoryAlloc(sizeof(array(char)));

ns->length = 0;
ns->elemSize = sizeof(char);

#line 212 "/opt/bah/json.bah"
i = i+1;

#line 213 "/opt/bah/json.bah"
long int start = i;

#line 214 "/opt/bah/json.bah"
while ((i<lenS-1)) {

#line 215 "/opt/bah/json.bah"
char c = cpstringCharAt(s,i);

#line 216 "/opt/bah/json.bah"
if ((i>start)&&(cpstringCharAt(s,i-1)==(char)92)) {

#line 217 "/opt/bah/json.bah"
if ((c==110)) {

#line 218 "/opt/bah/json.bah"
c = (char)10;
}

#line 219 "/opt/bah/json.bah"
else if ((c==114)) {

#line 220 "/opt/bah/json.bah"
c = (char)13;
}

#line 222 "/opt/bah/json.bah"

    unsigned int ____BAH_COMPILER_VAR_186 = len(ns)-1;
    __Bah_realocate_arr(ns, ____BAH_COMPILER_VAR_186);
    ns->data[____BAH_COMPILER_VAR_186] = c;
}

#line 223 "/opt/bah/json.bah"
else {

#line 224 "/opt/bah/json.bah"

    unsigned int ____BAH_COMPILER_VAR_187 = len(ns);
    __Bah_realocate_arr(ns, ____BAH_COMPILER_VAR_187);
    ns->data[____BAH_COMPILER_VAR_187] = c;
}

#line 226 "/opt/bah/json.bah"
i = i+1;
};

#line 228 "/opt/bah/json.bah"
jsonElem->content = arrToStr(ns);
}

#line 229 "/opt/bah/json.bah"
else if (isNumber(cpstringCharAt(s,strlen(s)-1))) {

#line 230 "/opt/bah/json.bah"
char isFloat = false;

#line 231 "/opt/bah/json.bah"
while ((i<lenS)) {

#line 232 "/opt/bah/json.bah"
if ((cpstringCharAt(s,i)==46)) {

#line 233 "/opt/bah/json.bah"
isFloat = true;

#line 234 "/opt/bah/json.bah"
break;
}

#line 236 "/opt/bah/json.bah"
i = i+1;
};

#line 239 "/opt/bah/json.bah"
if ((isFloat==true)) {

#line 240 "/opt/bah/json.bah"
jsonElem->type = JSON_TYPE_FLOAT;
}

#line 241 "/opt/bah/json.bah"
else {

#line 242 "/opt/bah/json.bah"
jsonElem->type = JSON_TYPE_INT;
}

#line 244 "/opt/bah/json.bah"
jsonElem->content = s;
}

#line 245 "/opt/bah/json.bah"
else {

#line 246 "/opt/bah/json.bah"
return null;
}

#line 249 "/opt/bah/json.bah"
if ((jsonElem->type==JSON_TYPE_ARRAY)) {

#line 250 "/opt/bah/json.bah"
i = i+1;

#line 252 "/opt/bah/json.bah"
long int trim = 1;

#line 253 "/opt/bah/json.bah"
register long int j = lenS-1;

#line 253 "/opt/bah/json.bah"
while ((j>=0)) {

#line 254 "/opt/bah/json.bah"
char c = cpstringCharAt(s,j);

#line 255 "/opt/bah/json.bah"
if (isSpace(c)) {

#line 256 "/opt/bah/json.bah"
trim = trim+1;
}

#line 257 "/opt/bah/json.bah"
else {

#line 258 "/opt/bah/json.bah"
break;
}

#line 260 "/opt/bah/json.bah"
j = j-1;
};

#line 263 "/opt/bah/json.bah"
while ((i<lenS-1)) {

#line 264 "/opt/bah/json.bah"
char c = cpstringCharAt(s,i);

#line 265 "/opt/bah/json.bah"
if ((isSpace(c)==false)) {

#line 266 "/opt/bah/json.bah"
break;
}

#line 268 "/opt/bah/json.bah"
i = i+1;
};

#line 270 "/opt/bah/json.bah"
array(char)* currentElem = memoryAlloc(sizeof(array(char)));

currentElem->length = 0;
currentElem->elemSize = sizeof(char);

#line 271 "/opt/bah/json.bah"
long int currentBracks = 0;

#line 272 "/opt/bah/json.bah"
long int currentBraces = 0;

#line 273 "/opt/bah/json.bah"
long int currentQuotes = 0;

#line 274 "/opt/bah/json.bah"
long int elemIndex = 0;

#line 275 "/opt/bah/json.bah"
while ((i<lenS-trim)) {

#line 276 "/opt/bah/json.bah"
char c = cpstringCharAt(s,i);

#line 277 "/opt/bah/json.bah"
if ((c==(char)34)) {

#line 278 "/opt/bah/json.bah"
if ((currentQuotes==0)) {

#line 279 "/opt/bah/json.bah"
currentQuotes = 1;
}

#line 280 "/opt/bah/json.bah"
else {

#line 281 "/opt/bah/json.bah"
currentQuotes = 0;
}
}

#line 283 "/opt/bah/json.bah"
else if ((c==91)) {

#line 284 "/opt/bah/json.bah"
currentBracks = currentBracks+1;
}

#line 285 "/opt/bah/json.bah"
else if ((c==93)) {

#line 286 "/opt/bah/json.bah"
currentBracks = currentBracks-1;
}

#line 287 "/opt/bah/json.bah"
else if ((c==123)) {

#line 288 "/opt/bah/json.bah"
currentBraces = currentBraces+1;
}

#line 289 "/opt/bah/json.bah"
else if ((c==125)) {

#line 290 "/opt/bah/json.bah"
currentBraces = currentBraces-1;
}

#line 292 "/opt/bah/json.bah"
long int total = currentBracks+currentBraces+currentQuotes;

#line 293 "/opt/bah/json.bah"
if ((total>0)) {

#line 294 "/opt/bah/json.bah"

    unsigned int ____BAH_COMPILER_VAR_188 = len(currentElem);
    __Bah_realocate_arr(currentElem, ____BAH_COMPILER_VAR_188);
    currentElem->data[____BAH_COMPILER_VAR_188] = c;

#line 295 "/opt/bah/json.bah"
i = i+1;

#line 296 "/opt/bah/json.bah"
continue;
}

#line 298 "/opt/bah/json.bah"
if ((c==44)) {

#line 299 "/opt/bah/json.bah"
char * ____BAH_COMPILER_VAR_189 =arrToStr(currentElem);struct jsonElement* child = parseJson(____BAH_COMPILER_VAR_189);

#line 300 "/opt/bah/json.bah"
if ((child!=null)) {

#line 301 "/opt/bah/json.bah"

    unsigned int ____BAH_COMPILER_VAR_190 = elemIndex;
    __Bah_realocate_arr(jsonElem->children, ____BAH_COMPILER_VAR_190);
    jsonElem->children->data[____BAH_COMPILER_VAR_190] = child;
}

#line 303 "/opt/bah/json.bah"
clear(currentElem);

#line 304 "/opt/bah/json.bah"
elemIndex = elemIndex+1;
}

#line 305 "/opt/bah/json.bah"
else {

#line 306 "/opt/bah/json.bah"
if (isSpace(c)) {

#line 307 "/opt/bah/json.bah"
i = i+1;

#line 308 "/opt/bah/json.bah"
continue;
}

#line 310 "/opt/bah/json.bah"

    unsigned int ____BAH_COMPILER_VAR_191 = len(currentElem);
    __Bah_realocate_arr(currentElem, ____BAH_COMPILER_VAR_191);
    currentElem->data[____BAH_COMPILER_VAR_191] = c;
}

#line 312 "/opt/bah/json.bah"
i = i+1;
};

#line 314 "/opt/bah/json.bah"
char * ____BAH_COMPILER_VAR_192 =arrToStr(currentElem);struct jsonElement* child = parseJson(____BAH_COMPILER_VAR_192);

#line 315 "/opt/bah/json.bah"
if ((child!=null)) {

#line 316 "/opt/bah/json.bah"

    unsigned int ____BAH_COMPILER_VAR_193 = elemIndex;
    __Bah_realocate_arr(jsonElem->children, ____BAH_COMPILER_VAR_193);
    jsonElem->children->data[____BAH_COMPILER_VAR_193] = child;
}
}

#line 319 "/opt/bah/json.bah"
else if ((jsonElem->type==JSON_TYPE_MAP)) {

#line 320 "/opt/bah/json.bah"
i = i+1;

#line 321 "/opt/bah/json.bah"
long int trim = 1;

#line 322 "/opt/bah/json.bah"
register long int j = lenS-1;

#line 322 "/opt/bah/json.bah"
while ((j>=0)) {

#line 323 "/opt/bah/json.bah"
char c = cpstringCharAt(s,j);

#line 324 "/opt/bah/json.bah"
if (isSpace(c)) {

#line 325 "/opt/bah/json.bah"
trim = trim+1;
}

#line 326 "/opt/bah/json.bah"
else {

#line 327 "/opt/bah/json.bah"
break;
}

#line 329 "/opt/bah/json.bah"
j = j-1;
};

#line 331 "/opt/bah/json.bah"
while ((i<lenS-1)) {

#line 332 "/opt/bah/json.bah"
char c = cpstringCharAt(s,i);

#line 333 "/opt/bah/json.bah"
if ((isSpace(c)==false)) {

#line 334 "/opt/bah/json.bah"
break;
}

#line 336 "/opt/bah/json.bah"
i = i+1;
};

#line 338 "/opt/bah/json.bah"
array(char)* currentElem = memoryAlloc(sizeof(array(char)));

currentElem->length = 0;
currentElem->elemSize = sizeof(char);

#line 339 "/opt/bah/json.bah"
array(char)* currentKey = memoryAlloc(sizeof(array(char)));

currentKey->length = 0;
currentKey->elemSize = sizeof(char);

#line 340 "/opt/bah/json.bah"
long int isVal = 0;

#line 341 "/opt/bah/json.bah"
long int currentBracks = 0;

#line 342 "/opt/bah/json.bah"
long int currentBraces = 0;

#line 343 "/opt/bah/json.bah"
long int currentQuotes = 0;

#line 344 "/opt/bah/json.bah"
long int elemIndex = 0;

#line 345 "/opt/bah/json.bah"
while ((i<lenS-trim)) {

#line 346 "/opt/bah/json.bah"
char c = cpstringCharAt(s,i);

#line 347 "/opt/bah/json.bah"
if ((c==(char)34)) {

#line 348 "/opt/bah/json.bah"
if ((currentQuotes==0)) {

#line 349 "/opt/bah/json.bah"
currentQuotes = 1;
}

#line 350 "/opt/bah/json.bah"
else {

#line 351 "/opt/bah/json.bah"
currentQuotes = 0;
}
}

#line 353 "/opt/bah/json.bah"
else if ((c==91)) {

#line 354 "/opt/bah/json.bah"
currentBracks = currentBracks+1;
}

#line 355 "/opt/bah/json.bah"
else if ((c==93)) {

#line 356 "/opt/bah/json.bah"
currentBracks = currentBracks-1;
}

#line 357 "/opt/bah/json.bah"
else if ((c==123)) {

#line 358 "/opt/bah/json.bah"
currentBraces = currentBraces+1;
}

#line 359 "/opt/bah/json.bah"
else if ((c==125)) {

#line 360 "/opt/bah/json.bah"
currentBraces = currentBraces-1;
}

#line 362 "/opt/bah/json.bah"
long int total = currentBracks+currentBraces+currentQuotes;

#line 363 "/opt/bah/json.bah"
if ((total>0)) {

#line 364 "/opt/bah/json.bah"
if ((isVal==1)) {

#line 365 "/opt/bah/json.bah"

    unsigned int ____BAH_COMPILER_VAR_194 = len(currentElem);
    __Bah_realocate_arr(currentElem, ____BAH_COMPILER_VAR_194);
    currentElem->data[____BAH_COMPILER_VAR_194] = c;
}

#line 366 "/opt/bah/json.bah"
else {

#line 367 "/opt/bah/json.bah"

    unsigned int ____BAH_COMPILER_VAR_195 = len(currentKey);
    __Bah_realocate_arr(currentKey, ____BAH_COMPILER_VAR_195);
    currentKey->data[____BAH_COMPILER_VAR_195] = c;
}

#line 369 "/opt/bah/json.bah"
i = i+1;

#line 370 "/opt/bah/json.bah"
continue;
}

#line 372 "/opt/bah/json.bah"
if ((c==58)) {

#line 373 "/opt/bah/json.bah"
isVal = 1;
}

#line 374 "/opt/bah/json.bah"
else if ((c==44)) {

#line 375 "/opt/bah/json.bah"
char * ____BAH_COMPILER_VAR_196 =arrToStr(currentElem);struct jsonElement* elem = parseJson(____BAH_COMPILER_VAR_196);

#line 376 "/opt/bah/json.bah"
if ((elem!=null)) {

#line 377 "/opt/bah/json.bah"
elem->key = arrToStr(currentKey);

#line 378 "/opt/bah/json.bah"

    unsigned int ____BAH_COMPILER_VAR_197 = elemIndex;
    __Bah_realocate_arr(jsonElem->children, ____BAH_COMPILER_VAR_197);
    jsonElem->children->data[____BAH_COMPILER_VAR_197] = elem;

#line 379 "/opt/bah/json.bah"
elemIndex = elemIndex+1;
}

#line 381 "/opt/bah/json.bah"
clear(currentElem);

#line 382 "/opt/bah/json.bah"
clear(currentKey);

#line 383 "/opt/bah/json.bah"
isVal = 0;
}

#line 384 "/opt/bah/json.bah"
else {

#line 385 "/opt/bah/json.bah"
if (isSpace(c)) {

#line 386 "/opt/bah/json.bah"
i = i+1;

#line 387 "/opt/bah/json.bah"
continue;
}

#line 389 "/opt/bah/json.bah"
if ((isVal==1)) {

#line 390 "/opt/bah/json.bah"

    unsigned int ____BAH_COMPILER_VAR_198 = len(currentElem);
    __Bah_realocate_arr(currentElem, ____BAH_COMPILER_VAR_198);
    currentElem->data[____BAH_COMPILER_VAR_198] = c;
}

#line 391 "/opt/bah/json.bah"
else {

#line 392 "/opt/bah/json.bah"

    unsigned int ____BAH_COMPILER_VAR_199 = len(currentKey);
    __Bah_realocate_arr(currentKey, ____BAH_COMPILER_VAR_199);
    currentKey->data[____BAH_COMPILER_VAR_199] = c;
}
}

#line 395 "/opt/bah/json.bah"
i = i+1;
};

#line 397 "/opt/bah/json.bah"
char * ____BAH_COMPILER_VAR_200 =arrToStr(currentElem);struct jsonElement* elem = parseJson(____BAH_COMPILER_VAR_200);

#line 398 "/opt/bah/json.bah"
if ((elem!=null)) {

#line 399 "/opt/bah/json.bah"
elem->key = arrToStr(currentKey);

#line 400 "/opt/bah/json.bah"

    unsigned int ____BAH_COMPILER_VAR_201 = elemIndex;
    __Bah_realocate_arr(jsonElem->children, ____BAH_COMPILER_VAR_201);
    jsonElem->children->data[____BAH_COMPILER_VAR_201] = elem;
}
}

#line 404 "/opt/bah/json.bah"
return jsonElem;
};

#line 408 "/opt/bah/json.bah"
char json_isPrintable(unsigned int c){

#line 409 "/opt/bah/json.bah"
if ((c<32)||(c>255)) {

#line 410 "/opt/bah/json.bah"
return false;
}

#line 412 "/opt/bah/json.bah"
return (c!=127)&&(c!=129)&&(c!=141)&&(c!=143)&&(c!=144)&&(c!=157);
};

#line 416 "/opt/bah/json.bah"
char * jsonEscapeStr(char * s){

#line 417 "/opt/bah/json.bah"
array(char)* a = strAsArr(s);

#line 418 "/opt/bah/json.bah"
array(char)* r = memoryAlloc(sizeof(array(char)));

r->length = 0;
r->elemSize = sizeof(char);

#line 420 "/opt/bah/json.bah"
register long int i = 0;

#line 420 "/opt/bah/json.bah"
while ((i<len(a))) {

#line 421 "/opt/bah/json.bah"
char c = a->data[i];

#line 422 "/opt/bah/json.bah"
if ((json_isPrintable((unsigned int)c)==false)) {

#line 423 "/opt/bah/json.bah"
if (((unsigned char)c==(unsigned char)195)) {

#line 424 "/opt/bah/json.bah"

    unsigned int ____BAH_COMPILER_VAR_202 = len(r);
    __Bah_realocate_arr(r, ____BAH_COMPILER_VAR_202);
    r->data[____BAH_COMPILER_VAR_202] = c;

#line 425 "/opt/bah/json.bah"

    unsigned int ____BAH_COMPILER_VAR_203 = len(r);
    __Bah_realocate_arr(r, ____BAH_COMPILER_VAR_203);
    r->data[____BAH_COMPILER_VAR_203] = a->data[i+1];

#line 426 "/opt/bah/json.bah"
++i;
}

#line 428 "/opt/bah/json.bah"
++i;

#line 429 "/opt/bah/json.bah"
continue;
}

#line 431 "/opt/bah/json.bah"
if ((c==(char)34)) {

#line 432 "/opt/bah/json.bah"

    unsigned int ____BAH_COMPILER_VAR_204 = len(r);
    __Bah_realocate_arr(r, ____BAH_COMPILER_VAR_204);
    r->data[____BAH_COMPILER_VAR_204] = (char)92;
}

#line 433 "/opt/bah/json.bah"
else if ((c==(char)10)) {

#line 434 "/opt/bah/json.bah"

    unsigned int ____BAH_COMPILER_VAR_205 = len(r);
    __Bah_realocate_arr(r, ____BAH_COMPILER_VAR_205);
    r->data[____BAH_COMPILER_VAR_205] = (char)92;

#line 435 "/opt/bah/json.bah"

    unsigned int ____BAH_COMPILER_VAR_206 = len(r);
    __Bah_realocate_arr(r, ____BAH_COMPILER_VAR_206);
    r->data[____BAH_COMPILER_VAR_206] = 110;

#line 436 "/opt/bah/json.bah"
i = i+1;

#line 437 "/opt/bah/json.bah"
continue;
}

#line 438 "/opt/bah/json.bah"
else if ((c==(char)13)) {

#line 439 "/opt/bah/json.bah"

    unsigned int ____BAH_COMPILER_VAR_207 = len(r);
    __Bah_realocate_arr(r, ____BAH_COMPILER_VAR_207);
    r->data[____BAH_COMPILER_VAR_207] = (char)92;

#line 440 "/opt/bah/json.bah"

    unsigned int ____BAH_COMPILER_VAR_208 = len(r);
    __Bah_realocate_arr(r, ____BAH_COMPILER_VAR_208);
    r->data[____BAH_COMPILER_VAR_208] = 114;

#line 441 "/opt/bah/json.bah"
i = i+1;

#line 442 "/opt/bah/json.bah"
continue;
}

#line 444 "/opt/bah/json.bah"

    unsigned int ____BAH_COMPILER_VAR_209 = len(r);
    __Bah_realocate_arr(r, ____BAH_COMPILER_VAR_209);
    r->data[____BAH_COMPILER_VAR_209] = c;

#line 445 "/opt/bah/json.bah"
i = i+1;
};

#line 448 "/opt/bah/json.bah"

    unsigned int ____BAH_COMPILER_VAR_210 = len(r);
    __Bah_realocate_arr(r, ____BAH_COMPILER_VAR_210);
    r->data[____BAH_COMPILER_VAR_210] = null;

#line 450 "/opt/bah/json.bah"
return arrAsStr(r);
};

#line 455 "/opt/bah/json.bah"
char * oldToJson__inner(struct reflectElement e,char isMember,long int tabs){

#line 456 "/opt/bah/json.bah"
void ** v = e.value;

#line 457 "/opt/bah/json.bah"
if ((e.value==null)) {

#line 458 "/opt/bah/json.bah"
if ((strcmp(e.type, "int") == 0)||(strcmp(e.type, "float") == 0)) {

#line 459 "/opt/bah/json.bah"
return "0";
}

#line 461 "/opt/bah/json.bah"
if ((strcmp(e.type, "bool") == 0)) {

#line 462 "/opt/bah/json.bah"
return "false";
}

#line 464 "/opt/bah/json.bah"
if ((strcmp(e.type, "ptr") == 0)||(strcmp(e.type, "cpstring") == 0)||(strCount(e.type,"*")!=0)) {

#line 465 "/opt/bah/json.bah"
return "null";
}
}

#line 468 "/opt/bah/json.bah"
if ((e.isStruct==true)) {

#line 469 "/opt/bah/json.bah"
tabs = tabs+1;

#line 470 "/opt/bah/json.bah"
char * tabsStr = "";

#line 471 "/opt/bah/json.bah"
register long int i = 0;

#line 471 "/opt/bah/json.bah"
while ((i<tabs)) {

#line 472 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_211 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_211[1] = "\t";____BAH_COMPILER_VAR_211[0] = tabsStr;char * ____BAH_COMPILER_VAR_212 =__Bah_multiple_concat(____BAH_COMPILER_VAR_211, 2);tabsStr = ____BAH_COMPILER_VAR_212;

#line 473 "/opt/bah/json.bah"
i = i+1;
};

#line 475 "/opt/bah/json.bah"
char * s = "{\n";

#line 476 "/opt/bah/json.bah"
i = 0;

#line 476 "/opt/bah/json.bah"
while ((i<len(e.structLayout))) {

#line 477 "/opt/bah/json.bah"
struct reflectElement m = e.structLayout->data[i];

#line 478 "/opt/bah/json.bah"
i = i+1;

#line 479 "/opt/bah/json.bah"
m.value = reflectElement__calculateOffset(&m,e.value);

#line 480 "/opt/bah/json.bah"
if ((i<len(e.structLayout))) {

#line 481 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_213 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_213[6] = ",\n";____BAH_COMPILER_VAR_213[5] = oldToJson__inner(m,true,tabs);____BAH_COMPILER_VAR_213[4] = "\": ";____BAH_COMPILER_VAR_213[3] = m.name;____BAH_COMPILER_VAR_213[2] = "\"";____BAH_COMPILER_VAR_213[1] = tabsStr;____BAH_COMPILER_VAR_213[0] = s;char * ____BAH_COMPILER_VAR_214 =__Bah_multiple_concat(____BAH_COMPILER_VAR_213, 7);s = ____BAH_COMPILER_VAR_214;
}

#line 482 "/opt/bah/json.bah"
else {

#line 483 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_215 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_215[6] = "\n";____BAH_COMPILER_VAR_215[5] = oldToJson__inner(m,true,tabs);____BAH_COMPILER_VAR_215[4] = "\": ";____BAH_COMPILER_VAR_215[3] = m.name;____BAH_COMPILER_VAR_215[2] = "\"";____BAH_COMPILER_VAR_215[1] = tabsStr;____BAH_COMPILER_VAR_215[0] = s;char * ____BAH_COMPILER_VAR_216 =__Bah_multiple_concat(____BAH_COMPILER_VAR_215, 7);s = ____BAH_COMPILER_VAR_216;
}
};

#line 486 "/opt/bah/json.bah"
tabs = tabs-1;

#line 487 "/opt/bah/json.bah"
tabsStr = "";

#line 488 "/opt/bah/json.bah"
i = 0;

#line 488 "/opt/bah/json.bah"
while ((i<tabs)) {

#line 489 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_217 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_217[1] = "\t";____BAH_COMPILER_VAR_217[0] = tabsStr;char * ____BAH_COMPILER_VAR_218 =__Bah_multiple_concat(____BAH_COMPILER_VAR_217, 2);tabsStr = ____BAH_COMPILER_VAR_218;

#line 490 "/opt/bah/json.bah"
i = i+1;
};

#line 492 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_219 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_219[2] = "}";____BAH_COMPILER_VAR_219[1] = tabsStr;____BAH_COMPILER_VAR_219[0] = s;char * ____BAH_COMPILER_VAR_220 =__Bah_multiple_concat(____BAH_COMPILER_VAR_219, 3);s = ____BAH_COMPILER_VAR_220;

#line 493 "/opt/bah/json.bah"
return s;
}

#line 494 "/opt/bah/json.bah"
else if ((strcmp(e.type, "int") == 0)) {

#line 495 "/opt/bah/json.bah"
long int* ip = e.value;

#line 496 "/opt/bah/json.bah"
return intToStr(*ip);
}

#line 497 "/opt/bah/json.bah"
else if ((strcmp(e.type, "float") == 0)) {

#line 498 "/opt/bah/json.bah"
double* fp = e.value;

#line 499 "/opt/bah/json.bah"
return floatToStr(*fp);
}

#line 500 "/opt/bah/json.bah"
else if ((strcmp(e.type, "cpstring") == 0)) {

#line 501 "/opt/bah/json.bah"
if ((isMember==false)) {

#line 502 "/opt/bah/json.bah"
void * s = e.value;

#line 503 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_221 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_221[2] = "\"";____BAH_COMPILER_VAR_221[1] = jsonEscapeStr(s);____BAH_COMPILER_VAR_221[0] = "\"";char * ____BAH_COMPILER_VAR_222 =__Bah_multiple_concat(____BAH_COMPILER_VAR_221, 3);return ____BAH_COMPILER_VAR_222;
}

#line 504 "/opt/bah/json.bah"
else {

#line 505 "/opt/bah/json.bah"
char ** sp = e.value;

#line 506 "/opt/bah/json.bah"
char * s = *sp;

#line 507 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_223 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_223[2] = "\"";____BAH_COMPILER_VAR_223[1] = jsonEscapeStr(s);____BAH_COMPILER_VAR_223[0] = "\"";char * ____BAH_COMPILER_VAR_224 =__Bah_multiple_concat(____BAH_COMPILER_VAR_223, 3);return ____BAH_COMPILER_VAR_224;
}
}

#line 509 "/opt/bah/json.bah"
else if ((strcmp(e.type, "bool") == 0)) {

#line 510 "/opt/bah/json.bah"
char* bp = e.value;

#line 511 "/opt/bah/json.bah"
if ((*bp==true)) {

#line 512 "/opt/bah/json.bah"
return "true";
}

#line 514 "/opt/bah/json.bah"
return "false";
}

#line 515 "/opt/bah/json.bah"
else if ((e.isArray==true)) {

#line 516 "/opt/bah/json.bah"
char * s = "[";

#line 517 "/opt/bah/json.bah"
struct reflectElement* ae = e.arrayElem;

#line 518 "/opt/bah/json.bah"
if ((e.value==null)) {

#line 519 "/opt/bah/json.bah"
return "null";
}

#line 521 "/opt/bah/json.bah"
if ((strcmp(ae->type, "int") == 0)) {

#line 522 "/opt/bah/json.bah"
array(long int)* arr = memoryAlloc(sizeof(array(long int)));

arr->length = 0;
arr->elemSize = sizeof(long int);

#line 523 "/opt/bah/json.bah"
void ** arrPtr = e.value;

#line 524 "/opt/bah/json.bah"
arr = *arrPtr;

#line 525 "/opt/bah/json.bah"
register long int i = 0;

#line 525 "/opt/bah/json.bah"
while ((i<len(arr))) {

#line 526 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_225 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_225[1] = intToStr(arr->data[i]);____BAH_COMPILER_VAR_225[0] = s;char * ____BAH_COMPILER_VAR_226 =__Bah_multiple_concat(____BAH_COMPILER_VAR_225, 2);s = ____BAH_COMPILER_VAR_226;

#line 527 "/opt/bah/json.bah"
i = i+1;

#line 528 "/opt/bah/json.bah"
if ((i<len(arr))) {

#line 529 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_227 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_227[1] = ",";____BAH_COMPILER_VAR_227[0] = s;char * ____BAH_COMPILER_VAR_228 =__Bah_multiple_concat(____BAH_COMPILER_VAR_227, 2);s = ____BAH_COMPILER_VAR_228;
}
};
}

#line 532 "/opt/bah/json.bah"
else if ((strcmp(ae->type, "float") == 0)) {

#line 533 "/opt/bah/json.bah"
array(double)* arr = memoryAlloc(sizeof(array(double)));

arr->length = 0;
arr->elemSize = sizeof(double);

#line 534 "/opt/bah/json.bah"
void ** arrPtr = e.value;

#line 535 "/opt/bah/json.bah"
arr = *arrPtr;

#line 536 "/opt/bah/json.bah"
register long int i = 0;

#line 536 "/opt/bah/json.bah"
while ((i<len(arr))) {

#line 537 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_229 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_229[1] = floatToStr(arr->data[i]);____BAH_COMPILER_VAR_229[0] = s;char * ____BAH_COMPILER_VAR_230 =__Bah_multiple_concat(____BAH_COMPILER_VAR_229, 2);s = ____BAH_COMPILER_VAR_230;

#line 538 "/opt/bah/json.bah"
i = i+1;

#line 539 "/opt/bah/json.bah"
if ((i<len(arr))) {

#line 540 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_231 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_231[1] = ",";____BAH_COMPILER_VAR_231[0] = s;char * ____BAH_COMPILER_VAR_232 =__Bah_multiple_concat(____BAH_COMPILER_VAR_231, 2);s = ____BAH_COMPILER_VAR_232;
}
};
}

#line 543 "/opt/bah/json.bah"
else if ((strcmp(ae->type, "cpstring") == 0)) {

#line 544 "/opt/bah/json.bah"
array(char *)* arr = memoryAlloc(sizeof(array(char *)));

arr->length = 0;
arr->elemSize = sizeof(char *);

#line 545 "/opt/bah/json.bah"
void ** arrPtr = e.value;

#line 546 "/opt/bah/json.bah"
arr = *arrPtr;

#line 547 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_233 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_233[1] = "\n";____BAH_COMPILER_VAR_233[0] = s;char * ____BAH_COMPILER_VAR_234 =__Bah_multiple_concat(____BAH_COMPILER_VAR_233, 2);s = ____BAH_COMPILER_VAR_234;

#line 548 "/opt/bah/json.bah"
register long int i = 0;

#line 548 "/opt/bah/json.bah"
while ((i<len(arr))) {

#line 549 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_235 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_235[3] = "\"";____BAH_COMPILER_VAR_235[2] = jsonEscapeStr(arr->data[i]);____BAH_COMPILER_VAR_235[1] = "\"";____BAH_COMPILER_VAR_235[0] = s;char * ____BAH_COMPILER_VAR_236 =__Bah_multiple_concat(____BAH_COMPILER_VAR_235, 4);s = ____BAH_COMPILER_VAR_236;

#line 550 "/opt/bah/json.bah"
i = i+1;

#line 551 "/opt/bah/json.bah"
if ((i<len(arr))) {

#line 552 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_237 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_237[1] = ",\n";____BAH_COMPILER_VAR_237[0] = s;char * ____BAH_COMPILER_VAR_238 =__Bah_multiple_concat(____BAH_COMPILER_VAR_237, 2);s = ____BAH_COMPILER_VAR_238;
}

#line 553 "/opt/bah/json.bah"
else {

#line 554 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_239 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_239[1] = "\n";____BAH_COMPILER_VAR_239[0] = s;char * ____BAH_COMPILER_VAR_240 =__Bah_multiple_concat(____BAH_COMPILER_VAR_239, 2);s = ____BAH_COMPILER_VAR_240;
}
};
}

#line 557 "/opt/bah/json.bah"
else if ((ae->isStruct==true)) {

#line 558 "/opt/bah/json.bah"
array(void *)* arr = memoryAlloc(sizeof(array(void *)));

arr->length = 0;
arr->elemSize = sizeof(void *);

#line 559 "/opt/bah/json.bah"
if ((isMember==false)) {

#line 560 "/opt/bah/json.bah"
arr = e.value;
}

#line 561 "/opt/bah/json.bah"
else {

#line 562 "/opt/bah/json.bah"
void ** ev = e.value;

#line 563 "/opt/bah/json.bah"
arr = *ev;
}

#line 566 "/opt/bah/json.bah"
register long int i = 0;

#line 566 "/opt/bah/json.bah"
while ((i<len(arr))) {

#line 567 "/opt/bah/json.bah"
void * arrElem = arr->data[i];

#line 568 "/opt/bah/json.bah"
ae->value = arrElem;

#line 569 "/opt/bah/json.bah"
register long int j = 0;

#line 569 "/opt/bah/json.bah"
while ((j<len(ae->structLayout))) {

#line 570 "/opt/bah/json.bah"
struct reflectElement m = ae->structLayout->data[j];

#line 571 "/opt/bah/json.bah"
m.value = reflectElement__calculateOffset(&m,ae->value);

#line 572 "/opt/bah/json.bah"

    unsigned int ____BAH_COMPILER_VAR_241 = j;
    __Bah_realocate_arr(ae->structLayout, ____BAH_COMPILER_VAR_241);
    ae->structLayout->data[____BAH_COMPILER_VAR_241] = m;

#line 573 "/opt/bah/json.bah"
j = j+1;
};

#line 575 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_242 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_242[1] = oldToJson__inner(*ae,false,tabs);____BAH_COMPILER_VAR_242[0] = s;char * ____BAH_COMPILER_VAR_243 =__Bah_multiple_concat(____BAH_COMPILER_VAR_242, 2);s = ____BAH_COMPILER_VAR_243;

#line 576 "/opt/bah/json.bah"
i = i+1;

#line 577 "/opt/bah/json.bah"
if ((i<len(arr))) {

#line 578 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_244 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_244[1] = ",\n";____BAH_COMPILER_VAR_244[0] = s;char * ____BAH_COMPILER_VAR_245 =__Bah_multiple_concat(____BAH_COMPILER_VAR_244, 2);s = ____BAH_COMPILER_VAR_245;
}

#line 579 "/opt/bah/json.bah"
else {

#line 580 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_246 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_246[1] = "\n";____BAH_COMPILER_VAR_246[0] = s;char * ____BAH_COMPILER_VAR_247 =__Bah_multiple_concat(____BAH_COMPILER_VAR_246, 2);s = ____BAH_COMPILER_VAR_247;
}
};
}

#line 584 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_248 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_248[1] = "]";____BAH_COMPILER_VAR_248[0] = s;char * ____BAH_COMPILER_VAR_249 =__Bah_multiple_concat(____BAH_COMPILER_VAR_248, 2);s = ____BAH_COMPILER_VAR_249;

#line 585 "/opt/bah/json.bah"
return s;
}

#line 587 "/opt/bah/json.bah"
return "0";
};

#line 592 "/opt/bah/json.bah"
char * oldToJson(struct reflectElement e){

#line 593 "/opt/bah/json.bah"
return oldToJson__inner(e,false,0);
};

#line 601 "/opt/bah/json.bah"
char * toJson(struct reflectElement e){

#line 602 "/opt/bah/json.bah"
register long int l = strlen(e.type);

#line 604 "/opt/bah/json.bah"
if (__builtin_expect((e.isArray==false)&&(e.type[l-1]!=42), 0)) {

#line 605 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_250 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_250[6] = ").";____BAH_COMPILER_VAR_250[5] = e.name;____BAH_COMPILER_VAR_250[4] = " but a pointer is required, try: toJson(&";____BAH_COMPILER_VAR_250[3] = e.type;____BAH_COMPILER_VAR_250[2] = ") of type ";____BAH_COMPILER_VAR_250[1] = e.name;____BAH_COMPILER_VAR_250[0] = "toJson(";char * ____BAH_COMPILER_VAR_251 =__Bah_multiple_concat(____BAH_COMPILER_VAR_250, 7);__BAH_panic(____BAH_COMPILER_VAR_251,"/opt/bah/json.bah:605");
}

#line 608 "/opt/bah/json.bah"
if ((e.isArray==false)) {

#line 609 "/opt/bah/json.bah"
long int ol = l;

#line 610 "/opt/bah/json.bah"
for (; (l>=2)&&(e.type[l-1]==42)&&(e.type[l-2]==42); 
#line 610 "/opt/bah/json.bah"
--l) {

#line 611 "/opt/bah/json.bah"
if ((e.value==null)) {

#line 612 "/opt/bah/json.bah"
return "0";
}

#line 614 "/opt/bah/json.bah"
void ** v = e.value;

#line 615 "/opt/bah/json.bah"
e.value = *v;
};

#line 617 "/opt/bah/json.bah"
if ((l!=ol)) {

#line 618 "/opt/bah/json.bah"
e.type = cpstringSubsitute(e.type, 0, l);
}
}

#line 622 "/opt/bah/json.bah"
if ((e.value==null)) {

#line 623 "/opt/bah/json.bah"
return "0";
}

#line 626 "/opt/bah/json.bah"
if ((e.isStruct==true)) {

#line 627 "/opt/bah/json.bah"
char * s = "{";

#line 628 "/opt/bah/json.bah"
register long int i = 0;

#line 628 "/opt/bah/json.bah"
for (; (i<len(e.structLayout)); 
#line 628 "/opt/bah/json.bah"
++i) {

#line 629 "/opt/bah/json.bah"
struct reflectElement m = e.structLayout->data[i];

#line 630 "/opt/bah/json.bah"
void * v = e.value;

#line 631 "/opt/bah/json.bah"
if ((m.isArray==true)) {

#line 632 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_252 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_252[1] = "*";____BAH_COMPILER_VAR_252[0] = m.arrayElem->type;char * ____BAH_COMPILER_VAR_253 =__Bah_multiple_concat(____BAH_COMPILER_VAR_252, 2);m.arrayElem->type = ____BAH_COMPILER_VAR_253;
}

#line 633 "/opt/bah/json.bah"
else if ((m.type[strlen(m.type)-1]!=42)) {

#line 634 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_254 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_254[1] = "*";____BAH_COMPILER_VAR_254[0] = m.type;char * ____BAH_COMPILER_VAR_255 =__Bah_multiple_concat(____BAH_COMPILER_VAR_254, 2);m.type = ____BAH_COMPILER_VAR_255;
}

#line 636 "/opt/bah/json.bah"
m.value = reflectElement__calculateOffset(&m,e.value);

#line 637 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_256 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_256[3] = toJson(m);____BAH_COMPILER_VAR_256[2] = "\": ";____BAH_COMPILER_VAR_256[1] = m.name;____BAH_COMPILER_VAR_256[0] = "\"";char * ____BAH_COMPILER_VAR_257 =__Bah_multiple_concat(____BAH_COMPILER_VAR_256, 4);char** ____BAH_COMPILER_VAR_258 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_258[1] = ____BAH_COMPILER_VAR_257;____BAH_COMPILER_VAR_258[0] = s;char * ____BAH_COMPILER_VAR_259 =__Bah_multiple_concat(____BAH_COMPILER_VAR_258, 2);s = ____BAH_COMPILER_VAR_259;

#line 638 "/opt/bah/json.bah"
if ((i+1<len(e.structLayout))) {

#line 639 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_260 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_260[1] = ", ";____BAH_COMPILER_VAR_260[0] = s;char * ____BAH_COMPILER_VAR_261 =__Bah_multiple_concat(____BAH_COMPILER_VAR_260, 2);s = ____BAH_COMPILER_VAR_261;
}
};

#line 642 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_262 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_262[1] = "}";____BAH_COMPILER_VAR_262[0] = s;char * ____BAH_COMPILER_VAR_263 =__Bah_multiple_concat(____BAH_COMPILER_VAR_262, 2);s = ____BAH_COMPILER_VAR_263;

#line 643 "/opt/bah/json.bah"
return s;
}

#line 646 "/opt/bah/json.bah"
if ((e.isArray==true)) {

#line 647 "/opt/bah/json.bah"
char * s = "[";

#line 648 "/opt/bah/json.bah"
void ** arrp = e.value;

#line 649 "/opt/bah/json.bah"
array(void *)* arr = (array(void *)*)*arrp;

#line 650 "/opt/bah/json.bah"
if ((arr==null)) {

#line 651 "/opt/bah/json.bah"
return "[]";
}

#line 653 "/opt/bah/json.bah"
void * base = cArr(arr);

#line 654 "/opt/bah/json.bah"
l = len(arr);

#line 655 "/opt/bah/json.bah"
long int es = arr->elemSize;

#line 656 "/opt/bah/json.bah"
struct reflectElement* ae = e.arrayElem;

#line 657 "/opt/bah/json.bah"
if ((ae->type[strlen(ae->type)-1]!=42)&&(ae->isArray==false)) {

#line 658 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_264 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_264[1] = "*";____BAH_COMPILER_VAR_264[0] = ae->type;char * ____BAH_COMPILER_VAR_265 =__Bah_multiple_concat(____BAH_COMPILER_VAR_264, 2);ae->type = ____BAH_COMPILER_VAR_265;
}

#line 660 "/opt/bah/json.bah"
register long int i = 0;

#line 660 "/opt/bah/json.bah"
for (; (i<l); 
#line 660 "/opt/bah/json.bah"
++i) {

#line 661 "/opt/bah/json.bah"
struct reflectElement m = *ae;

#line 662 "/opt/bah/json.bah"
m.value = (void *)((long int)base+es*i);

#line 663 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_266 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_266[1] = toJson(m);____BAH_COMPILER_VAR_266[0] = s;char * ____BAH_COMPILER_VAR_267 =__Bah_multiple_concat(____BAH_COMPILER_VAR_266, 2);s = ____BAH_COMPILER_VAR_267;

#line 664 "/opt/bah/json.bah"
if ((i+1<l)) {

#line 665 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_268 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_268[1] = ", ";____BAH_COMPILER_VAR_268[0] = s;char * ____BAH_COMPILER_VAR_269 =__Bah_multiple_concat(____BAH_COMPILER_VAR_268, 2);s = ____BAH_COMPILER_VAR_269;
}
};

#line 668 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_270 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_270[1] = "]";____BAH_COMPILER_VAR_270[0] = s;char * ____BAH_COMPILER_VAR_271 =__Bah_multiple_concat(____BAH_COMPILER_VAR_270, 2);s = ____BAH_COMPILER_VAR_271;

#line 669 "/opt/bah/json.bah"
return s;
}

#line 672 "/opt/bah/json.bah"
if ((strcmp(e.type, "int*") == 0)||(strcmp(e.type, "int32*") == 0)) {

#line 673 "/opt/bah/json.bah"
long int* j = e.value;

#line 674 "/opt/bah/json.bah"
return intToStr(*j);
}

#line 677 "/opt/bah/json.bah"
if ((strcmp(e.type, "cpstring*") == 0)) {

#line 678 "/opt/bah/json.bah"
char ** s = e.value;

#line 679 "/opt/bah/json.bah"
if ((s==null)) {

#line 680 "/opt/bah/json.bah"
return "\"\"";
}

#line 682 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_272 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_272[2] = "\"";____BAH_COMPILER_VAR_272[1] = jsonEscapeStr(*s);____BAH_COMPILER_VAR_272[0] = "\"";char * ____BAH_COMPILER_VAR_273 =__Bah_multiple_concat(____BAH_COMPILER_VAR_272, 3);return ____BAH_COMPILER_VAR_273;
}

#line 685 "/opt/bah/json.bah"
if ((strcmp(e.type, "float*") == 0)||(strcmp(e.type, "float32*") == 0)) {

#line 686 "/opt/bah/json.bah"
double* f = e.value;

#line 687 "/opt/bah/json.bah"
return floatToStr(*f);
}

#line 690 "/opt/bah/json.bah"
if ((strcmp(e.type, "uint*") == 0)||(strcmp(e.type, "uint32*") == 0)) {

#line 691 "/opt/bah/json.bah"
unsigned long int* uj = e.value;

#line 692 "/opt/bah/json.bah"
return intToStr(*uj);
}

#line 695 "/opt/bah/json.bah"
if ((strcmp(e.type, "char*") == 0)) {

#line 696 "/opt/bah/json.bah"
char* c = e.value;

#line 697 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_274 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_274[2] = "\"";____BAH_COMPILER_VAR_274[1] = charToString(*c);____BAH_COMPILER_VAR_274[0] = "\"";char * ____BAH_COMPILER_VAR_275 =__Bah_multiple_concat(____BAH_COMPILER_VAR_274, 3);return ____BAH_COMPILER_VAR_275;
}

#line 700 "/opt/bah/json.bah"
if ((strcmp(e.type, "bool*") == 0)) {

#line 701 "/opt/bah/json.bah"
char* b = e.value;

#line 702 "/opt/bah/json.bah"
if ((*b==true)) {

#line 703 "/opt/bah/json.bah"
return "true";
}

#line 705 "/opt/bah/json.bah"
return "false";
}

#line 708 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_276 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_276[2] = "\"";____BAH_COMPILER_VAR_276[1] = e.type;____BAH_COMPILER_VAR_276[0] = "\"invalid: ";char * ____BAH_COMPILER_VAR_277 =__Bah_multiple_concat(____BAH_COMPILER_VAR_276, 3);return ____BAH_COMPILER_VAR_277;
};

#line 4 "/home/alois/Documents/bah-bah/src/logger.bah"
struct debugFunctionArgument {
char * name;
char * type;
};

#line 9 "/home/alois/Documents/bah-bah/src/logger.bah"
struct debugFunction {
char * name;
char * returns;
array(struct variable*)* args;
};

#line 15 "/home/alois/Documents/bah-bah/src/logger.bah"
struct debugStruct {
char * name;
array(struct variable*)* membs;
};

#line 20 "/home/alois/Documents/bah-bah/src/logger.bah"
struct debugType {
char * name;
char * refers;
};

#line 25 "/home/alois/Documents/bah-bah/src/logger.bah"
void debugStart(){

#line 26 "/home/alois/Documents/bah-bah/src/logger.bah"
println("[");
};

#line 29 "/home/alois/Documents/bah-bah/src/logger.bah"
void debugPrint(char * name,long int line,struct reflectElement e){

#line 30 "/home/alois/Documents/bah-bah/src/logger.bah"
if ((debug==false)) {

#line 31 "/home/alois/Documents/bah-bah/src/logger.bah"
return;
}

#line 33 "/home/alois/Documents/bah-bah/src/logger.bah"
char ** ____BAH_COMPILER_VAR_278 = &name;
struct reflectElement ____BAH_COMPILER_VAR_279 = __reflect(____BAH_COMPILER_VAR_278, sizeof(char **), "cpstring*", "&name", 0, 0, 0, 0, 0);
char** ____BAH_COMPILER_VAR_280 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_280[8] = "\n    },\n    ";____BAH_COMPILER_VAR_280[7] = toJson(e);____BAH_COMPILER_VAR_280[6] = "\",\n        \"element\": ";____BAH_COMPILER_VAR_280[5] = intToStr(line);____BAH_COMPILER_VAR_280[4] = ":";____BAH_COMPILER_VAR_280[3] = compilerState.currentFile;____BAH_COMPILER_VAR_280[2] = ",\n        \"path\": \"";____BAH_COMPILER_VAR_280[1] = toJson(____BAH_COMPILER_VAR_279);____BAH_COMPILER_VAR_280[0] = "\n    {\n        \"name\": ";char * ____BAH_COMPILER_VAR_281 =__Bah_multiple_concat(____BAH_COMPILER_VAR_280, 9);println(____BAH_COMPILER_VAR_281);
};

#line 42 "/home/alois/Documents/bah-bah/src/logger.bah"
void debugError(char * name,long int line,long int from,long int to,struct reflectElement e){

#line 43 "/home/alois/Documents/bah-bah/src/logger.bah"
if ((debug==false)) {

#line 44 "/home/alois/Documents/bah-bah/src/logger.bah"
return;
}

#line 46 "/home/alois/Documents/bah-bah/src/logger.bah"
char ** ____BAH_COMPILER_VAR_282 = &name;
struct reflectElement ____BAH_COMPILER_VAR_283 = __reflect(____BAH_COMPILER_VAR_282, sizeof(char **), "cpstring*", "&name", 0, 0, 0, 0, 0);
char** ____BAH_COMPILER_VAR_284 = alloca(13 * sizeof(char*));____BAH_COMPILER_VAR_284[12] = "\n    },\n    ";____BAH_COMPILER_VAR_284[11] = toJson(e);____BAH_COMPILER_VAR_284[10] = "\n        ],\n        \"element\": ";____BAH_COMPILER_VAR_284[9] = intToStr(to);____BAH_COMPILER_VAR_284[8] = ",\n            ";____BAH_COMPILER_VAR_284[7] = intToStr(from);____BAH_COMPILER_VAR_284[6] = "\",\n        \"range\": [\n            ";____BAH_COMPILER_VAR_284[5] = intToStr(line);____BAH_COMPILER_VAR_284[4] = ":";____BAH_COMPILER_VAR_284[3] = compilerState.currentFile;____BAH_COMPILER_VAR_284[2] = ",\n        \"path\": \"";____BAH_COMPILER_VAR_284[1] = toJson(____BAH_COMPILER_VAR_283);____BAH_COMPILER_VAR_284[0] = "\n    {\n        \"name\": ";char * ____BAH_COMPILER_VAR_285 =__Bah_multiple_concat(____BAH_COMPILER_VAR_284, 13);println(____BAH_COMPILER_VAR_285);
};

#line 59 "/home/alois/Documents/bah-bah/src/logger.bah"
void debugEnd(){

#line 60 "/home/alois/Documents/bah-bah/src/logger.bah"
println("\n    {\n        \"name\": \"file_end\"\n    }\n    ]\n    ");
};

#line 69 "/home/alois/Documents/bah-bah/src/logger.bah"
void debugExit(){

#line 70 "/home/alois/Documents/bah-bah/src/logger.bah"
println("\n    {\n        \"name\": \"error_end\"\n    }\n    ]\n    ");
};

#line 78 "/home/alois/Documents/bah-bah/src/logger.bah"
void debugEndScope(long int line,struct Elems* elems){

#line 79 "/home/alois/Documents/bah-bah/src/logger.bah"
if ((debug==false)) {

#line 80 "/home/alois/Documents/bah-bah/src/logger.bah"
return;
}

#line 82 "/home/alois/Documents/bah-bah/src/logger.bah"
register long int i = 0;

#line 82 "/home/alois/Documents/bah-bah/src/logger.bah"
while ((i<len(elems->vars))) {

#line 83 "/home/alois/Documents/bah-bah/src/logger.bah"
struct variable* v = elems->vars->data[i];

#line 84 "/home/alois/Documents/bah-bah/src/logger.bah"
if ((v->declScope==elems)&&(v->isConst==false)) {

#line 85 "/home/alois/Documents/bah-bah/src/logger.bah"
struct variable* ____BAH_COMPILER_VAR_286 = v;
char ** ____BAH_COMPILER_VAR_288 = (char **)((char*)(____BAH_COMPILER_VAR_286) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_289 = __reflect(____BAH_COMPILER_VAR_288, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_290 = (char **)((char*)(____BAH_COMPILER_VAR_286) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_291 = __reflect(____BAH_COMPILER_VAR_290, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_292 = (char*)((char*)(____BAH_COMPILER_VAR_286) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_293 = __reflect(____BAH_COMPILER_VAR_292, sizeof(char), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_294 = (char **)((char*)(____BAH_COMPILER_VAR_286) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_295 = __reflect(____BAH_COMPILER_VAR_294, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_296 = (char*)((char*)(____BAH_COMPILER_VAR_286) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_297 = __reflect(____BAH_COMPILER_VAR_296, sizeof(char), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_298 = (char **)((char*)(____BAH_COMPILER_VAR_286) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_299 = __reflect(____BAH_COMPILER_VAR_298, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
void ** ____BAH_COMPILER_VAR_300 = (void **)((char*)(____BAH_COMPILER_VAR_286) + offsetof(struct variable, declScope));
struct reflectElement ____BAH_COMPILER_VAR_301 = __reflect(____BAH_COMPILER_VAR_300, sizeof(void *), "ptr", "declScope", 0, 0, 0, 0, offsetof(struct variable, declScope));
char* ____BAH_COMPILER_VAR_302 = (char*)((char*)(____BAH_COMPILER_VAR_286) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_303 = __reflect(____BAH_COMPILER_VAR_302, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));
struct rope** ____BAH_COMPILER_VAR_304 = (struct rope**)((char*)(____BAH_COMPILER_VAR_286) + offsetof(struct variable, declRope));
void ** ____BAH_COMPILER_VAR_306 = (void **)((char*)(____BAH_COMPILER_VAR_304) + offsetof(struct rope, left));
struct reflectElement ____BAH_COMPILER_VAR_307 = __reflect(____BAH_COMPILER_VAR_306, sizeof(void *), "ptr", "left", 0, 0, 0, 0, offsetof(struct rope, left));
void ** ____BAH_COMPILER_VAR_308 = (void **)((char*)(____BAH_COMPILER_VAR_304) + offsetof(struct rope, right));
struct reflectElement ____BAH_COMPILER_VAR_309 = __reflect(____BAH_COMPILER_VAR_308, sizeof(void *), "ptr", "right", 0, 0, 0, 0, offsetof(struct rope, right));
char ** ____BAH_COMPILER_VAR_310 = (char **)((char*)(____BAH_COMPILER_VAR_304) + offsetof(struct rope, str));
struct reflectElement ____BAH_COMPILER_VAR_311 = __reflect(____BAH_COMPILER_VAR_310, sizeof(char *), "cpstring", "str", 0, 0, 0, 0, offsetof(struct rope, str));
int* ____BAH_COMPILER_VAR_312 = (int*)((char*)(____BAH_COMPILER_VAR_304) + offsetof(struct rope, lCount));
struct reflectElement ____BAH_COMPILER_VAR_313 = __reflect(____BAH_COMPILER_VAR_312, sizeof(int), "int32", "lCount", 0, 0, 0, 0, offsetof(struct rope, lCount));
int* ____BAH_COMPILER_VAR_314 = (int*)((char*)(____BAH_COMPILER_VAR_304) + offsetof(struct rope, len));
struct reflectElement ____BAH_COMPILER_VAR_315 = __reflect(____BAH_COMPILER_VAR_314, sizeof(int), "int32", "len", 0, 0, 0, 0, offsetof(struct rope, len));
int* ____BAH_COMPILER_VAR_316 = (int*)((char*)(____BAH_COMPILER_VAR_304) + offsetof(struct rope, totalLen));
struct reflectElement ____BAH_COMPILER_VAR_317 = __reflect(____BAH_COMPILER_VAR_316, sizeof(int), "int32", "totalLen", 0, 0, 0, 0, offsetof(struct rope, totalLen));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_305 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_305->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_305->length = 6;
        ____BAH_COMPILER_VAR_305->data = memoryAlloc(____BAH_COMPILER_VAR_305->length * ____BAH_COMPILER_VAR_305->elemSize);
        ____BAH_COMPILER_VAR_305->data[0] = ____BAH_COMPILER_VAR_307;
____BAH_COMPILER_VAR_305->data[1] = ____BAH_COMPILER_VAR_309;
____BAH_COMPILER_VAR_305->data[2] = ____BAH_COMPILER_VAR_311;
____BAH_COMPILER_VAR_305->data[3] = ____BAH_COMPILER_VAR_313;
____BAH_COMPILER_VAR_305->data[4] = ____BAH_COMPILER_VAR_315;
____BAH_COMPILER_VAR_305->data[5] = ____BAH_COMPILER_VAR_317;
struct reflectElement ____BAH_COMPILER_VAR_318 = __reflect(____BAH_COMPILER_VAR_304, sizeof(struct rope), "rope*", "declRope", 0, 0, 1, ____BAH_COMPILER_VAR_305, offsetof(struct variable, declRope));
char* ____BAH_COMPILER_VAR_319 = (char*)((char*)(____BAH_COMPILER_VAR_286) + offsetof(struct variable, canBeNull));
struct reflectElement ____BAH_COMPILER_VAR_320 = __reflect(____BAH_COMPILER_VAR_319, sizeof(char), "bool", "canBeNull", 0, 0, 0, 0, offsetof(struct variable, canBeNull));
void ** ____BAH_COMPILER_VAR_321 = (void **)((char*)(____BAH_COMPILER_VAR_286) + offsetof(struct variable, iterScope));
struct reflectElement ____BAH_COMPILER_VAR_322 = __reflect(____BAH_COMPILER_VAR_321, sizeof(void *), "ptr", "iterScope", 0, 0, 0, 0, offsetof(struct variable, iterScope));
char* ____BAH_COMPILER_VAR_323 = (char*)((char*)(____BAH_COMPILER_VAR_286) + offsetof(struct variable, canBeReg));
struct reflectElement ____BAH_COMPILER_VAR_324 = __reflect(____BAH_COMPILER_VAR_323, sizeof(char), "bool", "canBeReg", 0, 0, 0, 0, offsetof(struct variable, canBeReg));
char* ____BAH_COMPILER_VAR_325 = (char*)((char*)(____BAH_COMPILER_VAR_286) + offsetof(struct variable, isReg));
struct reflectElement ____BAH_COMPILER_VAR_326 = __reflect(____BAH_COMPILER_VAR_325, sizeof(char), "bool", "isReg", 0, 0, 0, 0, offsetof(struct variable, isReg));
void ** ____BAH_COMPILER_VAR_327 = (void **)((char*)(____BAH_COMPILER_VAR_286) + offsetof(struct variable, lastSet));
struct reflectElement ____BAH_COMPILER_VAR_328 = __reflect(____BAH_COMPILER_VAR_327, sizeof(void *), "ptr", "lastSet", 0, 0, 0, 0, offsetof(struct variable, lastSet));
char* ____BAH_COMPILER_VAR_329 = (char*)((char*)(____BAH_COMPILER_VAR_286) + offsetof(struct variable, isArg));
struct reflectElement ____BAH_COMPILER_VAR_330 = __reflect(____BAH_COMPILER_VAR_329, sizeof(char), "bool", "isArg", 0, 0, 0, 0, offsetof(struct variable, isArg));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_287 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_287->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_287->length = 15;
        ____BAH_COMPILER_VAR_287->data = memoryAlloc(____BAH_COMPILER_VAR_287->length * ____BAH_COMPILER_VAR_287->elemSize);
        ____BAH_COMPILER_VAR_287->data[0] = ____BAH_COMPILER_VAR_289;
____BAH_COMPILER_VAR_287->data[1] = ____BAH_COMPILER_VAR_291;
____BAH_COMPILER_VAR_287->data[2] = ____BAH_COMPILER_VAR_293;
____BAH_COMPILER_VAR_287->data[3] = ____BAH_COMPILER_VAR_295;
____BAH_COMPILER_VAR_287->data[4] = ____BAH_COMPILER_VAR_297;
____BAH_COMPILER_VAR_287->data[5] = ____BAH_COMPILER_VAR_299;
____BAH_COMPILER_VAR_287->data[6] = ____BAH_COMPILER_VAR_301;
____BAH_COMPILER_VAR_287->data[7] = ____BAH_COMPILER_VAR_303;
____BAH_COMPILER_VAR_287->data[8] = ____BAH_COMPILER_VAR_318;
____BAH_COMPILER_VAR_287->data[9] = ____BAH_COMPILER_VAR_320;
____BAH_COMPILER_VAR_287->data[10] = ____BAH_COMPILER_VAR_322;
____BAH_COMPILER_VAR_287->data[11] = ____BAH_COMPILER_VAR_324;
____BAH_COMPILER_VAR_287->data[12] = ____BAH_COMPILER_VAR_326;
____BAH_COMPILER_VAR_287->data[13] = ____BAH_COMPILER_VAR_328;
____BAH_COMPILER_VAR_287->data[14] = ____BAH_COMPILER_VAR_330;
struct reflectElement ____BAH_COMPILER_VAR_331 = __reflect(____BAH_COMPILER_VAR_286, sizeof(struct variable), "variable*", "v", 0, 0, 1, ____BAH_COMPILER_VAR_287, 0);
debugPrint("var_end",line,____BAH_COMPILER_VAR_331);
}

#line 87 "/home/alois/Documents/bah-bah/src/logger.bah"
i = i+1;
};
};

#line 7 "/home/alois/Documents/bah-bah/src/errors.bah"
void advertiseGeneric();

#line 9 "/home/alois/Documents/bah-bah/src/errors.bah"
void throwErr(void * tp,char * format){

#line 11 "/home/alois/Documents/bah-bah/src/errors.bah"
char * str = "";

#line 12 "/home/alois/Documents/bah-bah/src/errors.bah"
char * info = "";

#line 13 "/home/alois/Documents/bah-bah/src/errors.bah"
long int pos = 0;

#line 14 "/home/alois/Documents/bah-bah/src/errors.bah"
if ((tp!=null)) {

#line 15 "/home/alois/Documents/bah-bah/src/errors.bah"
struct fileMap ____BAH_COMPILER_VAR_332 = {};
____BAH_COMPILER_VAR_332.handle = -1;
struct fileMap fm = ____BAH_COMPILER_VAR_332;

#line 16 "/home/alois/Documents/bah-bah/src/errors.bah"
char * fileSrcStr = fileMap__open(&fm,compilerState.currentFile);

#line 17 "/home/alois/Documents/bah-bah/src/errors.bah"
struct Tok* t = tp;

#line 18 "/home/alois/Documents/bah-bah/src/errors.bah"
struct string ffmt = string(format);

#line 19 "/home/alois/Documents/bah-bah/src/errors.bah"
if ((strlen(t->ogCont)==0)) {

#line 20 "/home/alois/Documents/bah-bah/src/errors.bah"
t->ogCont = t->cont;
}

#line 22 "/home/alois/Documents/bah-bah/src/errors.bah"
char** ____BAH_COMPILER_VAR_333 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_333[2] = "'";____BAH_COMPILER_VAR_333[1] = t->ogCont;____BAH_COMPILER_VAR_333[0] = "'";char * ____BAH_COMPILER_VAR_334 =__Bah_multiple_concat(____BAH_COMPILER_VAR_333, 3);string__replace(&ffmt,"{TOKEN}",____BAH_COMPILER_VAR_334);

#line 23 "/home/alois/Documents/bah-bah/src/errors.bah"
format = string__str(&ffmt);

#line 25 "/home/alois/Documents/bah-bah/src/errors.bah"
array(char)* line = memoryAlloc(sizeof(array(char)));

line->length = 0;
line->elemSize = sizeof(char);

#line 27 "/home/alois/Documents/bah-bah/src/errors.bah"
unsigned int beg = t->pos;

#line 27 "/home/alois/Documents/bah-bah/src/errors.bah"
while ((beg>0)) {

#line 28 "/home/alois/Documents/bah-bah/src/errors.bah"
char c = fileSrcStr[beg];

#line 29 "/home/alois/Documents/bah-bah/src/errors.bah"
if ((c==(char)10)) {

#line 30 "/home/alois/Documents/bah-bah/src/errors.bah"
beg = beg+1;

#line 31 "/home/alois/Documents/bah-bah/src/errors.bah"
break;
}

#line 33 "/home/alois/Documents/bah-bah/src/errors.bah"
beg = beg-1;
};

#line 36 "/home/alois/Documents/bah-bah/src/errors.bah"
pos = t->pos-beg+1;

#line 38 "/home/alois/Documents/bah-bah/src/errors.bah"
unsigned int i = beg;

#line 38 "/home/alois/Documents/bah-bah/src/errors.bah"
for (; (i<fm.size); 
#line 38 "/home/alois/Documents/bah-bah/src/errors.bah"
++i) {

#line 39 "/home/alois/Documents/bah-bah/src/errors.bah"
char c = fileSrcStr[i];

#line 40 "/home/alois/Documents/bah-bah/src/errors.bah"
if ((c==(char)10)) {

#line 41 "/home/alois/Documents/bah-bah/src/errors.bah"
break;
}

#line 43 "/home/alois/Documents/bah-bah/src/errors.bah"
if ((i==t->pos)) {

#line 44 "/home/alois/Documents/bah-bah/src/errors.bah"
array(char)* errCont = memoryAlloc(sizeof(array(char)));

errCont->length = 0;
errCont->elemSize = sizeof(char);

#line 45 "/home/alois/Documents/bah-bah/src/errors.bah"
unsigned int offset = i;

#line 46 "/home/alois/Documents/bah-bah/src/errors.bah"
for (; (i<fm.size); 
#line 46 "/home/alois/Documents/bah-bah/src/errors.bah"
++i) {

#line 47 "/home/alois/Documents/bah-bah/src/errors.bah"
if ((i-offset>=strlen(t->ogCont))) {

#line 48 "/home/alois/Documents/bah-bah/src/errors.bah"
break;
}

#line 50 "/home/alois/Documents/bah-bah/src/errors.bah"
if ((fileSrcStr[i]!=t->ogCont[i-offset])) {

#line 51 "/home/alois/Documents/bah-bah/src/errors.bah"
if ((isSpace(fileSrcStr[i])==false)) {

#line 52 "/home/alois/Documents/bah-bah/src/errors.bah"
break;
}

#line 54 "/home/alois/Documents/bah-bah/src/errors.bah"
++offset;
}

#line 56 "/home/alois/Documents/bah-bah/src/errors.bah"

    unsigned int ____BAH_COMPILER_VAR_335 = len(errCont);
    __Bah_realocate_arr(errCont, ____BAH_COMPILER_VAR_335);
    errCont->data[____BAH_COMPILER_VAR_335] = fileSrcStr[i];
};

#line 58 "/home/alois/Documents/bah-bah/src/errors.bah"
char** ____BAH_COMPILER_VAR_336 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_336[2] = "\e[1;37m";____BAH_COMPILER_VAR_336[1] = arrToStr(errCont);____BAH_COMPILER_VAR_336[0] = "\e[1;31m";char * ____BAH_COMPILER_VAR_337 =__Bah_multiple_concat(____BAH_COMPILER_VAR_336, 3);array(char)* errTk = strToArr(____BAH_COMPILER_VAR_337);

#line 59 "/home/alois/Documents/bah-bah/src/errors.bah"
register long int ii = 0;

#line 59 "/home/alois/Documents/bah-bah/src/errors.bah"
for (; (ii<len(errTk)); 
#line 59 "/home/alois/Documents/bah-bah/src/errors.bah"
++ii) {

#line 60 "/home/alois/Documents/bah-bah/src/errors.bah"

    unsigned int ____BAH_COMPILER_VAR_338 = len(line);
    __Bah_realocate_arr(line, ____BAH_COMPILER_VAR_338);
    line->data[____BAH_COMPILER_VAR_338] = errTk->data[ii];
};

#line 62 "/home/alois/Documents/bah-bah/src/errors.bah"
--i;

#line 63 "/home/alois/Documents/bah-bah/src/errors.bah"
continue;
}

#line 65 "/home/alois/Documents/bah-bah/src/errors.bah"

    unsigned int ____BAH_COMPILER_VAR_339 = len(line);
    __Bah_realocate_arr(line, ____BAH_COMPILER_VAR_339);
    line->data[____BAH_COMPILER_VAR_339] = c;
};

#line 68 "/home/alois/Documents/bah-bah/src/errors.bah"
fileMap__close(&fm);

#line 69 "/home/alois/Documents/bah-bah/src/errors.bah"
str = arrToStr(line);

#line 70 "/home/alois/Documents/bah-bah/src/errors.bah"
char** ____BAH_COMPILER_VAR_340 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_340[2] = intToStr(pos);____BAH_COMPILER_VAR_340[1] = ":";____BAH_COMPILER_VAR_340[0] = intToStr(t->line);char * ____BAH_COMPILER_VAR_341 =__Bah_multiple_concat(____BAH_COMPILER_VAR_340, 3);info = ____BAH_COMPILER_VAR_341;
}

#line 73 "/home/alois/Documents/bah-bah/src/errors.bah"
if (debug) {

#line 74 "/home/alois/Documents/bah-bah/src/errors.bah"
struct Tok* t = tp;

#line 75 "/home/alois/Documents/bah-bah/src/errors.bah"
char ** ____BAH_COMPILER_VAR_342 = &format;
struct reflectElement ____BAH_COMPILER_VAR_343 = __reflect(____BAH_COMPILER_VAR_342, sizeof(char **), "cpstring*", "&format", 0, 0, 0, 0, 0);
debugError("error",t->line,pos,pos+strlen(t->ogCont),____BAH_COMPILER_VAR_343);

#line 76 "/home/alois/Documents/bah-bah/src/errors.bah"
debugExit();
}

#line 77 "/home/alois/Documents/bah-bah/src/errors.bah"
else {

#line 78 "/home/alois/Documents/bah-bah/src/errors.bah"
advertiseGeneric();

#line 79 "/home/alois/Documents/bah-bah/src/errors.bah"
char** ____BAH_COMPILER_VAR_344 = alloca(8 * sizeof(char*));____BAH_COMPILER_VAR_344[7] = format;____BAH_COMPILER_VAR_344[6] = "\e[0m\n";____BAH_COMPILER_VAR_344[5] = str;____BAH_COMPILER_VAR_344[4] = "\n\e[1;37m\t";____BAH_COMPILER_VAR_344[3] = info;____BAH_COMPILER_VAR_344[2] = ":";____BAH_COMPILER_VAR_344[1] = compilerState.currentFile;____BAH_COMPILER_VAR_344[0] = "\e[1;31m[ERROR]\e[0m ";char * ____BAH_COMPILER_VAR_345 =__Bah_multiple_concat(____BAH_COMPILER_VAR_344, 8);println(____BAH_COMPILER_VAR_345);
}

#line 82 "/home/alois/Documents/bah-bah/src/errors.bah"
exit(1);
};

#line 86 "/home/alois/Documents/bah-bah/src/errors.bah"
void throwWarning(char * s){

#line 87 "/home/alois/Documents/bah-bah/src/errors.bah"
if (debug) {

#line 88 "/home/alois/Documents/bah-bah/src/errors.bah"
char ** ____BAH_COMPILER_VAR_346 = &s;
struct reflectElement ____BAH_COMPILER_VAR_347 = __reflect(____BAH_COMPILER_VAR_346, sizeof(char **), "cpstring*", "&s", 0, 0, 0, 0, 0);
debugError("warning",-1,-1,-1,____BAH_COMPILER_VAR_347);

#line 89 "/home/alois/Documents/bah-bah/src/errors.bah"
return;
}

#line 91 "/home/alois/Documents/bah-bah/src/errors.bah"
char** ____BAH_COMPILER_VAR_348 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_348[4] = "\e[0m";____BAH_COMPILER_VAR_348[3] = s;____BAH_COMPILER_VAR_348[2] = "\n\e[0m\t";____BAH_COMPILER_VAR_348[1] = compilerState.currentFile;____BAH_COMPILER_VAR_348[0] = "\e[1;33m[WARNING]\e[0m ";char * ____BAH_COMPILER_VAR_349 =__Bah_multiple_concat(____BAH_COMPILER_VAR_348, 5);println(____BAH_COMPILER_VAR_349);
};

#line 94 "/home/alois/Documents/bah-bah/src/errors.bah"
void throwWarningLine(char * s,long int l){

#line 95 "/home/alois/Documents/bah-bah/src/errors.bah"
if (debug) {

#line 96 "/home/alois/Documents/bah-bah/src/errors.bah"
char ** ____BAH_COMPILER_VAR_350 = &s;
struct reflectElement ____BAH_COMPILER_VAR_351 = __reflect(____BAH_COMPILER_VAR_350, sizeof(char **), "cpstring*", "&s", 0, 0, 0, 0, 0);
debugError("warning",l,0,0,____BAH_COMPILER_VAR_351);

#line 97 "/home/alois/Documents/bah-bah/src/errors.bah"
return;
}

#line 99 "/home/alois/Documents/bah-bah/src/errors.bah"
char** ____BAH_COMPILER_VAR_352 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_352[6] = "\e[0m";____BAH_COMPILER_VAR_352[5] = s;____BAH_COMPILER_VAR_352[4] = "\n\e[0m\t";____BAH_COMPILER_VAR_352[3] = intToStr(l);____BAH_COMPILER_VAR_352[2] = ":";____BAH_COMPILER_VAR_352[1] = compilerState.currentFile;____BAH_COMPILER_VAR_352[0] = "\e[1;33m[WARNING]\e[0m ";char * ____BAH_COMPILER_VAR_353 =__Bah_multiple_concat(____BAH_COMPILER_VAR_352, 7);println(____BAH_COMPILER_VAR_353);
};

#line 102 "/home/alois/Documents/bah-bah/src/errors.bah"
void throwNoticeLine(char * s,long int l){

#line 103 "/home/alois/Documents/bah-bah/src/errors.bah"
if (debug) {

#line 104 "/home/alois/Documents/bah-bah/src/errors.bah"
char ** ____BAH_COMPILER_VAR_354 = &s;
struct reflectElement ____BAH_COMPILER_VAR_355 = __reflect(____BAH_COMPILER_VAR_354, sizeof(char **), "cpstring*", "&s", 0, 0, 0, 0, 0);
debugError("notice",l,0,0,____BAH_COMPILER_VAR_355);

#line 105 "/home/alois/Documents/bah-bah/src/errors.bah"
return;
}

#line 107 "/home/alois/Documents/bah-bah/src/errors.bah"
if ((noticeEnabled==false)) {

#line 108 "/home/alois/Documents/bah-bah/src/errors.bah"
return;
}

#line 110 "/home/alois/Documents/bah-bah/src/errors.bah"
char** ____BAH_COMPILER_VAR_356 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_356[6] = "\e[0m";____BAH_COMPILER_VAR_356[5] = s;____BAH_COMPILER_VAR_356[4] = "\n\e[0m\t";____BAH_COMPILER_VAR_356[3] = intToStr(l);____BAH_COMPILER_VAR_356[2] = ":";____BAH_COMPILER_VAR_356[1] = compilerState.currentFile;____BAH_COMPILER_VAR_356[0] = "\e[1;36m[NOTICE]\e[0m ";char * ____BAH_COMPILER_VAR_357 =__Bah_multiple_concat(____BAH_COMPILER_VAR_356, 7);println(____BAH_COMPILER_VAR_357);
};

#line 46 "/home/alois/Documents/bah-bah/src/main.bah"

#line 1 "/home/alois/Documents/bah-bah/src/parser.bah"

#line 2 "/home/alois/Documents/bah-bah/src/parser.bah"

#line 3 "/home/alois/Documents/bah-bah/src/parser.bah"

#line 1 "/opt/bah/path.bah"
#include <stdlib.h>

#line 2 "/opt/bah/path.bah"

#line 4 "/opt/bah/path.bah"

#line 10 "/opt/bah/path.bah"
char * absPath(char * path){

#line 11 "/opt/bah/path.bah"

#line 12 "/opt/bah/path.bah"
char * p = realpath(path,null);

#line 14 "/opt/bah/path.bah"

#line 17 "/opt/bah/path.bah"

#line 30 "/opt/bah/path.bah"
return p;
};

#line 35 "/opt/bah/path.bah"
char * getCurrentPath(){

#line 36 "/opt/bah/path.bah"
char * cwd = memoryAlloc(4096);

#line 37 "/opt/bah/path.bah"
getcwd(cwd,4096);

#line 38 "/opt/bah/path.bah"
return cwd;
};

#line 44 "/opt/bah/path.bah"
char isInside(char * basePath,char * subPath){

#line 45 "/opt/bah/path.bah"
char * abs1 = absPath(basePath);

#line 46 "/opt/bah/path.bah"
char * abs2 = absPath(subPath);

#line 47 "/opt/bah/path.bah"
return (strHasPrefix(subPath,basePath)==true);
};

#line 50 "/opt/bah/path.bah"

#line 53 "/opt/bah/path.bah"
void setCurrentPath(char * s){

#line 54 "/opt/bah/path.bah"
chdir(s);
};

#line 5 "/home/alois/Documents/bah-bah/src/parser.bah"

#line 6 "/home/alois/Documents/bah-bah/src/parser.bah"

#line 7 "/home/alois/Documents/bah-bah/src/parser.bah"

#line 1 "/home/alois/Documents/bah-bah/src/var.bah"

#line 2 "/home/alois/Documents/bah-bah/src/var.bah"

#line 4 "/home/alois/Documents/bah-bah/src/var.bah"

#line 7 "/home/alois/Documents/bah-bah/src/var.bah"

#line 8 "/home/alois/Documents/bah-bah/src/var.bah"

#line 9 "/home/alois/Documents/bah-bah/src/var.bah"

#line 10 "/home/alois/Documents/bah-bah/src/var.bah"

#line 1 "/home/alois/Documents/bah-bah/src/fns.bah"

#line 2 "/home/alois/Documents/bah-bah/src/fns.bah"

#line 4 "/home/alois/Documents/bah-bah/src/fns.bah"

#line 6 "/home/alois/Documents/bah-bah/src/fns.bah"
char isGlobal(){

#line 7 "/home/alois/Documents/bah-bah/src/fns.bah"
return (currentFn==null);
};

#line 12 "/home/alois/Documents/bah-bah/src/var.bah"
struct variable* getRealVar(char * n,struct Elems* elems){

#line 13 "/home/alois/Documents/bah-bah/src/var.bah"
register long int i = len(elems->vars)-1;

#line 13 "/home/alois/Documents/bah-bah/src/var.bah"
for (; (i!=-1); 
#line 13 "/home/alois/Documents/bah-bah/src/var.bah"
--i) {

#line 14 "/home/alois/Documents/bah-bah/src/var.bah"
if ((strcmp(elems->vars->data[i]->name, n) == 0)) {

#line 15 "/home/alois/Documents/bah-bah/src/var.bah"
return elems->vars->data[i];
}
};

#line 18 "/home/alois/Documents/bah-bah/src/var.bah"
return null;
};

#line 21 "/home/alois/Documents/bah-bah/src/var.bah"
void removeVarUnar(struct string* s){

#line 22 "/home/alois/Documents/bah-bah/src/var.bah"
array(char)* arr = string__asArr(s);

#line 23 "/home/alois/Documents/bah-bah/src/var.bah"
register long int i = 0;

#line 23 "/home/alois/Documents/bah-bah/src/var.bah"
for (; (i<len(arr)); 
#line 23 "/home/alois/Documents/bah-bah/src/var.bah"
++i) {

#line 24 "/home/alois/Documents/bah-bah/src/var.bah"
char c = arr->data[i];

#line 25 "/home/alois/Documents/bah-bah/src/var.bah"
if ((c==38)||(c==42)) {

#line 26 "/home/alois/Documents/bah-bah/src/var.bah"
delete(arr,i);

#line 27 "/home/alois/Documents/bah-bah/src/var.bah"
--i;

#line 28 "/home/alois/Documents/bah-bah/src/var.bah"
continue;
}
};
};

#line 33 "/home/alois/Documents/bah-bah/src/var.bah"
struct variable* searchVar(char * name,struct Elems* elems){

#line 35 "/home/alois/Documents/bah-bah/src/var.bah"
char * ogName = name;

#line 36 "/home/alois/Documents/bah-bah/src/var.bah"
struct string n = string(name);

#line 37 "/home/alois/Documents/bah-bah/src/var.bah"
removeVarUnar(&n);

#line 39 "/home/alois/Documents/bah-bah/src/var.bah"
if ((string__charAt(&n,n.length-1)==93)) {

#line 40 "/home/alois/Documents/bah-bah/src/var.bah"
register long int i = n.length;

#line 40 "/home/alois/Documents/bah-bah/src/var.bah"
while ((i>0)) {

#line 41 "/home/alois/Documents/bah-bah/src/var.bah"
char c = string__charAt(&n,i);

#line 42 "/home/alois/Documents/bah-bah/src/var.bah"
if ((c==91)) {

#line 43 "/home/alois/Documents/bah-bah/src/var.bah"
break;
}

#line 45 "/home/alois/Documents/bah-bah/src/var.bah"
i = i-1;
};

#line 47 "/home/alois/Documents/bah-bah/src/var.bah"
long int tamm = n.length-i;

#line 48 "/home/alois/Documents/bah-bah/src/var.bah"
string__trimRight(&n,tamm);

#line 49 "/home/alois/Documents/bah-bah/src/var.bah"
char isArr = (string__hasSuffix(&n,"->data")==1);

#line 50 "/home/alois/Documents/bah-bah/src/var.bah"
if ((isArr==true)) {

#line 51 "/home/alois/Documents/bah-bah/src/var.bah"
string__trimRight(&n,6);
}

#line 53 "/home/alois/Documents/bah-bah/src/var.bah"
name = string__str(&n);

#line 54 "/home/alois/Documents/bah-bah/src/var.bah"
struct variable* v = searchVar(name,elems);

#line 56 "/home/alois/Documents/bah-bah/src/var.bah"
struct string vt = string(v->type);

#line 57 "/home/alois/Documents/bah-bah/src/var.bah"
if ((isArr==true)) {

#line 58 "/home/alois/Documents/bah-bah/src/var.bah"
string__trimLeft(&vt,2);
}

#line 59 "/home/alois/Documents/bah-bah/src/var.bah"
else if (string__hasPrefix(&vt,"tuple:")) {

#line 60 "/home/alois/Documents/bah-bah/src/var.bah"
array(struct string)* parts = splitString(vt,":");

#line 61 "/home/alois/Documents/bah-bah/src/var.bah"
char * ____BAH_COMPILER_VAR_358 =string__str(&parts->data[2]);string__set(&vt,____BAH_COMPILER_VAR_358);
}

#line 62 "/home/alois/Documents/bah-bah/src/var.bah"
else {

#line 63 "/home/alois/Documents/bah-bah/src/var.bah"
string__set(&vt,"char");
}

#line 65 "/home/alois/Documents/bah-bah/src/var.bah"
char * vtstr = string__str(&vt);

#line 67 "/home/alois/Documents/bah-bah/src/var.bah"
struct variable* ____BAH_COMPILER_VAR_359 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_359->name = "";
____BAH_COMPILER_VAR_359->type = "";
____BAH_COMPILER_VAR_359->constVal = "";
____BAH_COMPILER_VAR_359->from = "";
struct variable* nv = ____BAH_COMPILER_VAR_359;

#line 68 "/home/alois/Documents/bah-bah/src/var.bah"
*nv = *v;

#line 69 "/home/alois/Documents/bah-bah/src/var.bah"
nv->type = vtstr;

#line 70 "/home/alois/Documents/bah-bah/src/var.bah"
nv->name = ogName;

#line 71 "/home/alois/Documents/bah-bah/src/var.bah"
nv->isArray = isArr;

#line 72 "/home/alois/Documents/bah-bah/src/var.bah"
return nv;
}

#line 75 "/home/alois/Documents/bah-bah/src/var.bah"
name = n.content;

#line 78 "/home/alois/Documents/bah-bah/src/var.bah"
if (hasStructSep(&n)&&(string__count(&n,")")==0)) {

#line 79 "/home/alois/Documents/bah-bah/src/var.bah"
struct string rn = splitStructSepBefore(&n);

#line 80 "/home/alois/Documents/bah-bah/src/var.bah"
name = rn.content;

#line 81 "/home/alois/Documents/bah-bah/src/var.bah"
string__trimLeft(&n,rn.length);

#line 82 "/home/alois/Documents/bah-bah/src/var.bah"
if (string__hasPrefix(&n,".")) {

#line 83 "/home/alois/Documents/bah-bah/src/var.bah"
string__trimLeft(&n,1);
}

#line 84 "/home/alois/Documents/bah-bah/src/var.bah"
else {

#line 85 "/home/alois/Documents/bah-bah/src/var.bah"
string__trimLeft(&n,2);
}

#line 87 "/home/alois/Documents/bah-bah/src/var.bah"
char * membs = n.content;

#line 88 "/home/alois/Documents/bah-bah/src/var.bah"
struct variable* v = searchVar(name,elems);

#line 89 "/home/alois/Documents/bah-bah/src/var.bah"
if ((v==null)) {

#line 90 "/home/alois/Documents/bah-bah/src/var.bah"
return null;
}

#line 92 "/home/alois/Documents/bah-bah/src/var.bah"
struct cStruct* s = searchStruct(v->type,elems);

#line 93 "/home/alois/Documents/bah-bah/src/var.bah"
if ((s==null)) {

#line 94 "/home/alois/Documents/bah-bah/src/var.bah"
return null;
}

#line 96 "/home/alois/Documents/bah-bah/src/var.bah"
struct structMemb* memb = searchStructMemb(membs,s,elems);

#line 97 "/home/alois/Documents/bah-bah/src/var.bah"
if ((memb==null)) {

#line 98 "/home/alois/Documents/bah-bah/src/var.bah"
return null;
}

#line 100 "/home/alois/Documents/bah-bah/src/var.bah"
struct variable* ____BAH_COMPILER_VAR_360 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_360->name = "";
____BAH_COMPILER_VAR_360->type = "";
____BAH_COMPILER_VAR_360->constVal = "";
____BAH_COMPILER_VAR_360->from = "";
struct variable* nv = ____BAH_COMPILER_VAR_360;

#line 101 "/home/alois/Documents/bah-bah/src/var.bah"
nv->from = memb->from;

#line 102 "/home/alois/Documents/bah-bah/src/var.bah"
nv->name = memb->name;

#line 103 "/home/alois/Documents/bah-bah/src/var.bah"
nv->type = memb->type;

#line 104 "/home/alois/Documents/bah-bah/src/var.bah"
nv->declScope = v->declScope;

#line 105 "/home/alois/Documents/bah-bah/src/var.bah"
nv->name = ogName;

#line 107 "/home/alois/Documents/bah-bah/src/var.bah"
char * r = nv->type;

#line 108 "/home/alois/Documents/bah-bah/src/var.bah"
struct string tcc = string(ogName);

#line 109 "/home/alois/Documents/bah-bah/src/var.bah"
if (string__count(&tcc,"&")) {

#line 110 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_361 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_361[1] = "*";____BAH_COMPILER_VAR_361[0] = r;char * ____BAH_COMPILER_VAR_362 =__Bah_multiple_concat(____BAH_COMPILER_VAR_361, 2);r = ____BAH_COMPILER_VAR_362;
}

#line 112 "/home/alois/Documents/bah-bah/src/var.bah"
long int nbUnaries = string__count(&tcc,"*");

#line 113 "/home/alois/Documents/bah-bah/src/var.bah"
if ((nbUnaries>0)) {

#line 114 "/home/alois/Documents/bah-bah/src/var.bah"
struct string ct = string(r);

#line 115 "/home/alois/Documents/bah-bah/src/var.bah"
long int pointerLevel = string__count(&ct,"*");

#line 116 "/home/alois/Documents/bah-bah/src/var.bah"
if (__builtin_expect((pointerLevel<nbUnaries), 0)) {

#line 117 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_363 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_363[2] = "' because it is not pointer.";____BAH_COMPILER_VAR_363[1] = name;____BAH_COMPILER_VAR_363[0] = "Cannot use '*' on '";char * ____BAH_COMPILER_VAR_364 =__Bah_multiple_concat(____BAH_COMPILER_VAR_363, 3);throwErr(null,____BAH_COMPILER_VAR_364);
}

#line 119 "/home/alois/Documents/bah-bah/src/var.bah"
string__trimRight(&ct,nbUnaries);

#line 120 "/home/alois/Documents/bah-bah/src/var.bah"
r = string__str(&ct);
}

#line 122 "/home/alois/Documents/bah-bah/src/var.bah"
nv->type = r;

#line 123 "/home/alois/Documents/bah-bah/src/var.bah"
nv->name = ogName;

#line 125 "/home/alois/Documents/bah-bah/src/var.bah"
return nv;
}

#line 128 "/home/alois/Documents/bah-bah/src/var.bah"
register long int i = len(elems->vars)-1;

#line 128 "/home/alois/Documents/bah-bah/src/var.bah"
for (; (i!=-1); 
#line 128 "/home/alois/Documents/bah-bah/src/var.bah"
--i) {

#line 129 "/home/alois/Documents/bah-bah/src/var.bah"
struct variable* v = elems->vars->data[i];

#line 130 "/home/alois/Documents/bah-bah/src/var.bah"
if ((strcmp(v->name, name) == 0)) {

#line 131 "/home/alois/Documents/bah-bah/src/var.bah"
struct variable* ____BAH_COMPILER_VAR_365 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_365->name = "";
____BAH_COMPILER_VAR_365->type = "";
____BAH_COMPILER_VAR_365->constVal = "";
____BAH_COMPILER_VAR_365->from = "";
struct variable* nv = ____BAH_COMPILER_VAR_365;

#line 132 "/home/alois/Documents/bah-bah/src/var.bah"
*nv = *v;

#line 133 "/home/alois/Documents/bah-bah/src/var.bah"
char * r = nv->type;

#line 134 "/home/alois/Documents/bah-bah/src/var.bah"
struct string tcc = string(ogName);

#line 135 "/home/alois/Documents/bah-bah/src/var.bah"
if (string__count(&tcc,"&")) {

#line 136 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_366 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_366[1] = "*";____BAH_COMPILER_VAR_366[0] = r;char * ____BAH_COMPILER_VAR_367 =__Bah_multiple_concat(____BAH_COMPILER_VAR_366, 2);r = ____BAH_COMPILER_VAR_367;
}

#line 139 "/home/alois/Documents/bah-bah/src/var.bah"
long int nbUnaries = string__count(&tcc,"*");

#line 140 "/home/alois/Documents/bah-bah/src/var.bah"
if ((nbUnaries>0)) {

#line 141 "/home/alois/Documents/bah-bah/src/var.bah"
struct string ct = string(r);

#line 142 "/home/alois/Documents/bah-bah/src/var.bah"
long int pointerLevel = string__count(&ct,"*");

#line 143 "/home/alois/Documents/bah-bah/src/var.bah"
if (__builtin_expect((pointerLevel<nbUnaries), 0)) {

#line 144 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_368 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_368[2] = "' because it is not pointer.";____BAH_COMPILER_VAR_368[1] = name;____BAH_COMPILER_VAR_368[0] = "Cannot use '*' on '";char * ____BAH_COMPILER_VAR_369 =__Bah_multiple_concat(____BAH_COMPILER_VAR_368, 3);throwErr(null,____BAH_COMPILER_VAR_369);
}

#line 146 "/home/alois/Documents/bah-bah/src/var.bah"
string__trimRight(&ct,nbUnaries);

#line 147 "/home/alois/Documents/bah-bah/src/var.bah"
r = string__str(&ct);
}

#line 149 "/home/alois/Documents/bah-bah/src/var.bah"
nv->type = r;

#line 150 "/home/alois/Documents/bah-bah/src/var.bah"
nv->name = ogName;

#line 151 "/home/alois/Documents/bah-bah/src/var.bah"
return nv;
}
};

#line 155 "/home/alois/Documents/bah-bah/src/var.bah"
i = 0;

#line 155 "/home/alois/Documents/bah-bah/src/var.bah"
for (; (i<len(elems->fns)); 
#line 155 "/home/alois/Documents/bah-bah/src/var.bah"
++i) {

#line 156 "/home/alois/Documents/bah-bah/src/var.bah"
struct func* fn = elems->fns->data[i];

#line 157 "/home/alois/Documents/bah-bah/src/var.bah"
if ((strcmp(fn->name, name) == 0)) {

#line 158 "/home/alois/Documents/bah-bah/src/var.bah"
struct variable* ____BAH_COMPILER_VAR_370 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_370->name = "";
____BAH_COMPILER_VAR_370->type = "";
____BAH_COMPILER_VAR_370->constVal = "";
____BAH_COMPILER_VAR_370->from = "";
struct variable* nv = ____BAH_COMPILER_VAR_370;

#line 159 "/home/alois/Documents/bah-bah/src/var.bah"
nv->name = name;

#line 160 "/home/alois/Documents/bah-bah/src/var.bah"
nv->type = "function(";

#line 161 "/home/alois/Documents/bah-bah/src/var.bah"
register long int j = 0;

#line 161 "/home/alois/Documents/bah-bah/src/var.bah"
while ((j<len(fn->args))) {

#line 162 "/home/alois/Documents/bah-bah/src/var.bah"
struct variable* arg = fn->args->data[j];

#line 163 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_371 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_371[1] = arg->type;____BAH_COMPILER_VAR_371[0] = nv->type;char * ____BAH_COMPILER_VAR_372 =__Bah_multiple_concat(____BAH_COMPILER_VAR_371, 2);nv->type = ____BAH_COMPILER_VAR_372;

#line 164 "/home/alois/Documents/bah-bah/src/var.bah"
j = j+1;

#line 165 "/home/alois/Documents/bah-bah/src/var.bah"
if ((j<len(fn->args))) {

#line 166 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_373 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_373[1] = ",";____BAH_COMPILER_VAR_373[0] = nv->type;char * ____BAH_COMPILER_VAR_374 =__Bah_multiple_concat(____BAH_COMPILER_VAR_373, 2);nv->type = ____BAH_COMPILER_VAR_374;
}
};

#line 169 "/home/alois/Documents/bah-bah/src/var.bah"
fn->used = true;

#line 170 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_375 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_375[2] = fn->returns->type;____BAH_COMPILER_VAR_375[1] = ")";____BAH_COMPILER_VAR_375[0] = nv->type;char * ____BAH_COMPILER_VAR_376 =__Bah_multiple_concat(____BAH_COMPILER_VAR_375, 3);nv->type = ____BAH_COMPILER_VAR_376;

#line 171 "/home/alois/Documents/bah-bah/src/var.bah"
return nv;
}
};

#line 177 "/home/alois/Documents/bah-bah/src/var.bah"
return null;
};

#line 181 "/home/alois/Documents/bah-bah/src/var.bah"
struct variable* searchVarByToken(struct Tok* t,struct Elems* elems){

#line 182 "/home/alois/Documents/bah-bah/src/var.bah"
if ((t->bahRef!=null)) {

#line 183 "/home/alois/Documents/bah-bah/src/var.bah"
return t->bahRef;
}

#line 185 "/home/alois/Documents/bah-bah/src/var.bah"
struct string cont = string(t->cont);

#line 186 "/home/alois/Documents/bah-bah/src/var.bah"
removeVarUnar(&cont);

#line 187 "/home/alois/Documents/bah-bah/src/var.bah"
char * ____BAH_COMPILER_VAR_377 =string__str(&cont);return getRealVar(____BAH_COMPILER_VAR_377,elems);
};

#line 190 "/home/alois/Documents/bah-bah/src/var.bah"
struct variable* searchVirtVarByToken(struct Tok* t,struct Elems* elems){

#line 191 "/home/alois/Documents/bah-bah/src/var.bah"
if ((t->isOper==true)) {

#line 192 "/home/alois/Documents/bah-bah/src/var.bah"
return null;
}

#line 194 "/home/alois/Documents/bah-bah/src/var.bah"
if ((t->bahRef!=null)) {

#line 195 "/home/alois/Documents/bah-bah/src/var.bah"
return t->bahRef;
}

#line 197 "/home/alois/Documents/bah-bah/src/var.bah"
return searchVar(t->cont,elems);
};

#line 200 "/home/alois/Documents/bah-bah/src/var.bah"
char * setCType(struct variable* v,struct Elems* elems){

#line 201 "/home/alois/Documents/bah-bah/src/var.bah"
struct string tp = getCType(v->type,elems);

#line 202 "/home/alois/Documents/bah-bah/src/var.bah"
char * t = string__str(&tp);

#line 203 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_378 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_378[2] = v->name;____BAH_COMPILER_VAR_378[1] = " ";____BAH_COMPILER_VAR_378[0] = t;char * ____BAH_COMPILER_VAR_379 =__Bah_multiple_concat(____BAH_COMPILER_VAR_378, 3);t = ____BAH_COMPILER_VAR_379;

#line 204 "/home/alois/Documents/bah-bah/src/var.bah"
return t;
};

#line 207 "/home/alois/Documents/bah-bah/src/var.bah"
void isMissingVar(struct Tok* t,struct Elems* elems){

#line 208 "/home/alois/Documents/bah-bah/src/var.bah"
register long int i = 0;

#line 208 "/home/alois/Documents/bah-bah/src/var.bah"
for (; (i<len(elems->deletedVars)); 
#line 208 "/home/alois/Documents/bah-bah/src/var.bah"
++i) {

#line 209 "/home/alois/Documents/bah-bah/src/var.bah"
if (__builtin_expect((strcmp(elems->deletedVars->data[i]->name, t->cont) == 0), 0)) {

#line 210 "/home/alois/Documents/bah-bah/src/var.bah"
throwErr(t,"Variable {TOKEN} has reached its end of life.");
}
};
};

#line 215 "/home/alois/Documents/bah-bah/src/var.bah"
char * getTypeFromToken(struct Tok* t,char strict,struct Elems* elems){

#line 217 "/home/alois/Documents/bah-bah/src/var.bah"
if ((strcmp(t->bahType, "") != 0)) {

#line 218 "/home/alois/Documents/bah-bah/src/var.bah"
char * r = t->bahType;

#line 219 "/home/alois/Documents/bah-bah/src/var.bah"
return r;
}

#line 221 "/home/alois/Documents/bah-bah/src/var.bah"
if ((t->type==TOKEN_TYPE_VAR)) {

#line 222 "/home/alois/Documents/bah-bah/src/var.bah"
struct variable* v = searchVar(t->cont,elems);

#line 223 "/home/alois/Documents/bah-bah/src/var.bah"
if ((v==null)) {

#line 224 "/home/alois/Documents/bah-bah/src/var.bah"
if (__builtin_expect((strict==true), 0)) {

#line 225 "/home/alois/Documents/bah-bah/src/var.bah"
isMissingVar(t,elems);

#line 226 "/home/alois/Documents/bah-bah/src/var.bah"
throwErr(t,"Unknown var {TOKEN}.");
}

#line 227 "/home/alois/Documents/bah-bah/src/var.bah"
else {

#line 228 "/home/alois/Documents/bah-bah/src/var.bah"
return "";
}
}

#line 231 "/home/alois/Documents/bah-bah/src/var.bah"
if ((strict==true)) {

#line 232 "/home/alois/Documents/bah-bah/src/var.bah"
if (__builtin_expect((strcmp(v->type, "") == 0), 0)) {

#line 233 "/home/alois/Documents/bah-bah/src/var.bah"
throwErr(t,"Cannot use {TOKEN} because it does not have any type.");
}
}

#line 236 "/home/alois/Documents/bah-bah/src/var.bah"
t->bahType = v->type;

#line 237 "/home/alois/Documents/bah-bah/src/var.bah"
return v->type;
}

#line 240 "/home/alois/Documents/bah-bah/src/var.bah"
if ((t->type==TOKEN_TYPE_FLOAT)) {

#line 241 "/home/alois/Documents/bah-bah/src/var.bah"
return "float";
}

#line 243 "/home/alois/Documents/bah-bah/src/var.bah"
if ((t->type==TOKEN_TYPE_INT)) {

#line 244 "/home/alois/Documents/bah-bah/src/var.bah"
return "int";
}

#line 246 "/home/alois/Documents/bah-bah/src/var.bah"
if ((t->type==TOKEN_TYPE_STR)) {

#line 247 "/home/alois/Documents/bah-bah/src/var.bah"
return "cpstring";
}

#line 249 "/home/alois/Documents/bah-bah/src/var.bah"
if ((t->type==TOKEN_TYPE_CHAR)) {

#line 250 "/home/alois/Documents/bah-bah/src/var.bah"
return "char";
}

#line 252 "/home/alois/Documents/bah-bah/src/var.bah"
if ((t->type==TOKEN_TYPE_BOOL)) {

#line 253 "/home/alois/Documents/bah-bah/src/var.bah"
return "bool";
}

#line 256 "/home/alois/Documents/bah-bah/src/var.bah"
throwErr(t,"Cannot use {TOKEN} as value.");

#line 257 "/home/alois/Documents/bah-bah/src/var.bah"
return "";
};

#line 261 "/home/alois/Documents/bah-bah/src/var.bah"
struct func* parseFnType(struct string cvt){

#line 262 "/home/alois/Documents/bah-bah/src/var.bah"
struct func* ____BAH_COMPILER_VAR_380 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_380->name = "";
____BAH_COMPILER_VAR_380->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_380->args->length = 0;
            ____BAH_COMPILER_VAR_380->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_380->from = "";
____BAH_COMPILER_VAR_380->file = "";
____BAH_COMPILER_VAR_380->line = 1;
struct func* nf = ____BAH_COMPILER_VAR_380;

#line 263 "/home/alois/Documents/bah-bah/src/var.bah"
string__trimLeft(&cvt,9);

#line 264 "/home/alois/Documents/bah-bah/src/var.bah"
array(char)* memory = memoryAlloc(sizeof(array(char)));

memory->length = 0;
memory->elemSize = sizeof(char);

#line 265 "/home/alois/Documents/bah-bah/src/var.bah"
register long int j = 0;

#line 265 "/home/alois/Documents/bah-bah/src/var.bah"
while ((j<cvt.length)) {

#line 266 "/home/alois/Documents/bah-bah/src/var.bah"
char c = string__charAt(&cvt,j);

#line 267 "/home/alois/Documents/bah-bah/src/var.bah"
if ((c==41)) {

#line 268 "/home/alois/Documents/bah-bah/src/var.bah"
break;
}

#line 270 "/home/alois/Documents/bah-bah/src/var.bah"
struct variable* ____BAH_COMPILER_VAR_381 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_381->name = "";
____BAH_COMPILER_VAR_381->type = "";
____BAH_COMPILER_VAR_381->constVal = "";
____BAH_COMPILER_VAR_381->from = "";
struct variable* arg = ____BAH_COMPILER_VAR_381;

#line 271 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_382 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_382[1] = intToStr(len(nf->args));____BAH_COMPILER_VAR_382[0] = "arg_";char * ____BAH_COMPILER_VAR_383 =__Bah_multiple_concat(____BAH_COMPILER_VAR_382, 2);arg->name = ____BAH_COMPILER_VAR_383;

#line 272 "/home/alois/Documents/bah-bah/src/var.bah"
while ((j<cvt.length)) {

#line 273 "/home/alois/Documents/bah-bah/src/var.bah"
c = string__charAt(&cvt,j);

#line 274 "/home/alois/Documents/bah-bah/src/var.bah"
if ((c==44)||(c==41)) {

#line 275 "/home/alois/Documents/bah-bah/src/var.bah"
break;
}

#line 277 "/home/alois/Documents/bah-bah/src/var.bah"

    unsigned int ____BAH_COMPILER_VAR_384 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_384);
    memory->data[____BAH_COMPILER_VAR_384] = c;

#line 278 "/home/alois/Documents/bah-bah/src/var.bah"
j = j+1;
};

#line 280 "/home/alois/Documents/bah-bah/src/var.bah"
arg->type = arrToStr(memory);

#line 281 "/home/alois/Documents/bah-bah/src/var.bah"
clear(memory);

#line 282 "/home/alois/Documents/bah-bah/src/var.bah"

    unsigned int ____BAH_COMPILER_VAR_385 = len(nf->args);
    __Bah_realocate_arr(nf->args, ____BAH_COMPILER_VAR_385);
    nf->args->data[____BAH_COMPILER_VAR_385] = arg;

#line 283 "/home/alois/Documents/bah-bah/src/var.bah"
if ((c==41)) {

#line 284 "/home/alois/Documents/bah-bah/src/var.bah"
break;
}

#line 286 "/home/alois/Documents/bah-bah/src/var.bah"
j = j+1;
};

#line 288 "/home/alois/Documents/bah-bah/src/var.bah"
j = j+1;

#line 289 "/home/alois/Documents/bah-bah/src/var.bah"
while ((j<cvt.length)) {

#line 290 "/home/alois/Documents/bah-bah/src/var.bah"
char c = string__charAt(&cvt,j);

#line 291 "/home/alois/Documents/bah-bah/src/var.bah"

    unsigned int ____BAH_COMPILER_VAR_386 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_386);
    memory->data[____BAH_COMPILER_VAR_386] = c;

#line 292 "/home/alois/Documents/bah-bah/src/var.bah"
j = j+1;
};

#line 294 "/home/alois/Documents/bah-bah/src/var.bah"
struct variable* ____BAH_COMPILER_VAR_387 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_387->name = "";
____BAH_COMPILER_VAR_387->type = "";
____BAH_COMPILER_VAR_387->constVal = "";
____BAH_COMPILER_VAR_387->from = "";
nf->returns = ____BAH_COMPILER_VAR_387;

#line 295 "/home/alois/Documents/bah-bah/src/var.bah"
nf->returns->name = "_return";

#line 296 "/home/alois/Documents/bah-bah/src/var.bah"
nf->returns->type = arrToStr(memory);

#line 297 "/home/alois/Documents/bah-bah/src/var.bah"
return nf;
};

#line 300 "/home/alois/Documents/bah-bah/src/var.bah"
struct func* searchFunc(char * name,struct Elems* elems,char inclCurr){

#line 302 "/home/alois/Documents/bah-bah/src/var.bah"
char * ogName = name;

#line 303 "/home/alois/Documents/bah-bah/src/var.bah"
if ((strcmp(name, "noCheck") == 0)) {

#line 304 "/home/alois/Documents/bah-bah/src/var.bah"
struct func* ____BAH_COMPILER_VAR_388 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_388->name = "";
____BAH_COMPILER_VAR_388->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_388->args->length = 0;
            ____BAH_COMPILER_VAR_388->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_388->from = "";
____BAH_COMPILER_VAR_388->file = "";
____BAH_COMPILER_VAR_388->line = 1;
struct func* fn = ____BAH_COMPILER_VAR_388;

#line 305 "/home/alois/Documents/bah-bah/src/var.bah"
fn->name = "noCheck";

#line 306 "/home/alois/Documents/bah-bah/src/var.bah"
return fn;
}

#line 308 "/home/alois/Documents/bah-bah/src/var.bah"
struct string n = string(name);

#line 309 "/home/alois/Documents/bah-bah/src/var.bah"
if (hasStructSep(&n)) {

#line 310 "/home/alois/Documents/bah-bah/src/var.bah"
struct string fnName = splitStructSepAfter(n);

#line 311 "/home/alois/Documents/bah-bah/src/var.bah"
string__trimRight(&n,fnName.length);

#line 312 "/home/alois/Documents/bah-bah/src/var.bah"
char c = string__charAt(&n,n.length-1);

#line 313 "/home/alois/Documents/bah-bah/src/var.bah"
if ((c==46)) {

#line 314 "/home/alois/Documents/bah-bah/src/var.bah"
string__trimRight(&n,1);
}

#line 315 "/home/alois/Documents/bah-bah/src/var.bah"
else {

#line 316 "/home/alois/Documents/bah-bah/src/var.bah"
string__trimRight(&n,2);
}

#line 318 "/home/alois/Documents/bah-bah/src/var.bah"
name = string__str(&n);

#line 319 "/home/alois/Documents/bah-bah/src/var.bah"
struct variable* v = searchVar(name,elems);

#line 320 "/home/alois/Documents/bah-bah/src/var.bah"
if ((v==null)) {

#line 321 "/home/alois/Documents/bah-bah/src/var.bah"
return null;
}

#line 323 "/home/alois/Documents/bah-bah/src/var.bah"
struct cStruct* s = searchStruct(v->type,elems);

#line 324 "/home/alois/Documents/bah-bah/src/var.bah"
if ((s==null)) {

#line 325 "/home/alois/Documents/bah-bah/src/var.bah"
return null;
}

#line 327 "/home/alois/Documents/bah-bah/src/var.bah"
char * ____BAH_COMPILER_VAR_389 =string__str(&fnName);struct structMemb* memb = searchStructMemb(____BAH_COMPILER_VAR_389,s,elems);

#line 328 "/home/alois/Documents/bah-bah/src/var.bah"
if ((memb==null)) {

#line 329 "/home/alois/Documents/bah-bah/src/var.bah"
return null;
}

#line 331 "/home/alois/Documents/bah-bah/src/var.bah"
name = fnName.content;

#line 332 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_390 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_390[2] = name;____BAH_COMPILER_VAR_390[1] = "__";____BAH_COMPILER_VAR_390[0] = memb->from;char * ____BAH_COMPILER_VAR_391 =__Bah_multiple_concat(____BAH_COMPILER_VAR_390, 3);name = ____BAH_COMPILER_VAR_391;
}

#line 336 "/home/alois/Documents/bah-bah/src/var.bah"
array(struct func*)* fns = elems->fns;

#line 337 "/home/alois/Documents/bah-bah/src/var.bah"
register long int i = 0;

#line 337 "/home/alois/Documents/bah-bah/src/var.bah"
while ((i<len(fns))) {

#line 338 "/home/alois/Documents/bah-bah/src/var.bah"
struct func* fn = fns->data[i];

#line 339 "/home/alois/Documents/bah-bah/src/var.bah"
if ((strcmp(fn->name, name) == 0)) {

#line 340 "/home/alois/Documents/bah-bah/src/var.bah"
fn->used = true;

#line 341 "/home/alois/Documents/bah-bah/src/var.bah"
return fn;
}

#line 343 "/home/alois/Documents/bah-bah/src/var.bah"
i = i+1;
};

#line 346 "/home/alois/Documents/bah-bah/src/var.bah"
if ((inclCurr==true)&&(currentFn!=null)) {

#line 347 "/home/alois/Documents/bah-bah/src/var.bah"
if ((strcmp(currentFn->name, name) == 0)) {

#line 348 "/home/alois/Documents/bah-bah/src/var.bah"
currentFn->used = true;

#line 349 "/home/alois/Documents/bah-bah/src/var.bah"
return currentFn;
}
}

#line 353 "/home/alois/Documents/bah-bah/src/var.bah"
struct variable* v = searchVar(ogName,elems);

#line 354 "/home/alois/Documents/bah-bah/src/var.bah"
if ((v==null)) {

#line 355 "/home/alois/Documents/bah-bah/src/var.bah"
return null;
}

#line 357 "/home/alois/Documents/bah-bah/src/var.bah"
struct func* ____BAH_COMPILER_VAR_392 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_392->name = "";
____BAH_COMPILER_VAR_392->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_392->args->length = 0;
            ____BAH_COMPILER_VAR_392->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_392->from = "";
____BAH_COMPILER_VAR_392->file = "";
____BAH_COMPILER_VAR_392->line = 1;
struct func* nf = ____BAH_COMPILER_VAR_392;

#line 358 "/home/alois/Documents/bah-bah/src/var.bah"
nf->name = ogName;

#line 359 "/home/alois/Documents/bah-bah/src/var.bah"
struct string cvt = string(v->type);

#line 360 "/home/alois/Documents/bah-bah/src/var.bah"
if ((string__hasPrefix(&cvt,"function(")==0)) {

#line 361 "/home/alois/Documents/bah-bah/src/var.bah"
return null;
}

#line 363 "/home/alois/Documents/bah-bah/src/var.bah"
struct func* pfn = parseFnType(cvt);

#line 364 "/home/alois/Documents/bah-bah/src/var.bah"
nf->returns = pfn->returns;

#line 365 "/home/alois/Documents/bah-bah/src/var.bah"
nf->args = pfn->args;

#line 366 "/home/alois/Documents/bah-bah/src/var.bah"
return nf;
};

#line 369 "/home/alois/Documents/bah-bah/src/var.bah"
struct func* searchFuncByToken(struct Tok* t,struct Elems* elems){

#line 370 "/home/alois/Documents/bah-bah/src/var.bah"
if ((t->bahRef!=null)) {

#line 371 "/home/alois/Documents/bah-bah/src/var.bah"
return t->bahRef;
}

#line 373 "/home/alois/Documents/bah-bah/src/var.bah"
struct string ____BAH_COMPILER_VAR_393 =string(t->cont);char * fnName = splitStringBefore(____BAH_COMPILER_VAR_393,"(");

#line 374 "/home/alois/Documents/bah-bah/src/var.bah"
return searchFunc(fnName,elems,true);
};

#line 377 "/home/alois/Documents/bah-bah/src/var.bah"
char RCPavailable();

#line 379 "/home/alois/Documents/bah-bah/src/var.bah"
char * declareStructMethods(struct variable* v,struct cStruct* s,struct Elems* elems){

#line 380 "/home/alois/Documents/bah-bah/src/var.bah"
char * code = "";

#line 381 "/home/alois/Documents/bah-bah/src/var.bah"
array(struct structMemb*)* members = s->members;

#line 382 "/home/alois/Documents/bah-bah/src/var.bah"
struct string typec = string(v->type);

#line 383 "/home/alois/Documents/bah-bah/src/var.bah"
char * sep = ".";

#line 384 "/home/alois/Documents/bah-bah/src/var.bah"
char * amp = "&";

#line 385 "/home/alois/Documents/bah-bah/src/var.bah"
if (string__count(&typec,"*")) {

#line 386 "/home/alois/Documents/bah-bah/src/var.bah"
sep = "->";

#line 387 "/home/alois/Documents/bah-bah/src/var.bah"
amp = "";
}

#line 389 "/home/alois/Documents/bah-bah/src/var.bah"
register long int i = 0;

#line 389 "/home/alois/Documents/bah-bah/src/var.bah"
for (; (i<len(members)); 
#line 389 "/home/alois/Documents/bah-bah/src/var.bah"
++i) {

#line 390 "/home/alois/Documents/bah-bah/src/var.bah"
struct structMemb* m = members->data[i];

#line 391 "/home/alois/Documents/bah-bah/src/var.bah"
struct string cmpt = string(m->type);

#line 392 "/home/alois/Documents/bah-bah/src/var.bah"
if ((strcmp(m->def, "") != 0)) {

#line 393 "/home/alois/Documents/bah-bah/src/var.bah"
if ((strcmp(m->def, "false") != 0)&&(strcmp(m->def, "0") != 0)&&(strcmp(m->def, "null") != 0)) {

#line 394 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_394 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_394[6] = ";\n";____BAH_COMPILER_VAR_394[5] = m->def;____BAH_COMPILER_VAR_394[4] = " = ";____BAH_COMPILER_VAR_394[3] = m->name;____BAH_COMPILER_VAR_394[2] = sep;____BAH_COMPILER_VAR_394[1] = v->name;____BAH_COMPILER_VAR_394[0] = code;char * ____BAH_COMPILER_VAR_395 =__Bah_multiple_concat(____BAH_COMPILER_VAR_394, 7);code = ____BAH_COMPILER_VAR_395;
}

#line 396 "/home/alois/Documents/bah-bah/src/var.bah"
continue;
}

#line 398 "/home/alois/Documents/bah-bah/src/var.bah"
if ((string__hasPrefix(&cmpt,"[]")==1)) {

#line 399 "/home/alois/Documents/bah-bah/src/var.bah"
string__trimLeft(&cmpt,2);

#line 400 "/home/alois/Documents/bah-bah/src/var.bah"
char * cmptstr = string__str(&cmpt);

#line 401 "/home/alois/Documents/bah-bah/src/var.bah"
struct string elemCType = getCType(cmptstr,elems);

#line 402 "/home/alois/Documents/bah-bah/src/var.bah"
char * elemCTypeStr = string__str(&elemCType);

#line 403 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_396 = alloca(17 * sizeof(char*));____BAH_COMPILER_VAR_396[16] = ");\n            ";____BAH_COMPILER_VAR_396[15] = elemCTypeStr;____BAH_COMPILER_VAR_396[14] = "->elemSize = sizeof(";____BAH_COMPILER_VAR_396[13] = m->name;____BAH_COMPILER_VAR_396[12] = sep;____BAH_COMPILER_VAR_396[11] = v->name;____BAH_COMPILER_VAR_396[10] = "->length = 0;\n            ";____BAH_COMPILER_VAR_396[9] = m->name;____BAH_COMPILER_VAR_396[8] = sep;____BAH_COMPILER_VAR_396[7] = v->name;____BAH_COMPILER_VAR_396[6] = ")));\n            ";____BAH_COMPILER_VAR_396[5] = elemCTypeStr;____BAH_COMPILER_VAR_396[4] = " = memoryAlloc(sizeof(array(";____BAH_COMPILER_VAR_396[3] = m->name;____BAH_COMPILER_VAR_396[2] = sep;____BAH_COMPILER_VAR_396[1] = v->name;____BAH_COMPILER_VAR_396[0] = code;char * ____BAH_COMPILER_VAR_397 =__Bah_multiple_concat(____BAH_COMPILER_VAR_396, 17);code = ____BAH_COMPILER_VAR_397;

#line 407 "/home/alois/Documents/bah-bah/src/var.bah"
continue;
}

#line 409 "/home/alois/Documents/bah-bah/src/var.bah"
if ((string__hasPrefix(&cmpt,"map:")==1)) {

#line 410 "/home/alois/Documents/bah-bah/src/var.bah"
string__trimLeft(&cmpt,4);

#line 411 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_398 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_398[3] = " = mapWrapper();\n";____BAH_COMPILER_VAR_398[2] = m->name;____BAH_COMPILER_VAR_398[1] = sep;____BAH_COMPILER_VAR_398[0] = v->name;char * ____BAH_COMPILER_VAR_399 =__Bah_multiple_concat(____BAH_COMPILER_VAR_398, 4);char** ____BAH_COMPILER_VAR_400 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_400[1] = ____BAH_COMPILER_VAR_399;____BAH_COMPILER_VAR_400[0] = code;char * ____BAH_COMPILER_VAR_401 =__Bah_multiple_concat(____BAH_COMPILER_VAR_400, 2);code = ____BAH_COMPILER_VAR_401;

#line 412 "/home/alois/Documents/bah-bah/src/var.bah"
continue;
}

#line 414 "/home/alois/Documents/bah-bah/src/var.bah"
if ((string__hasPrefix(&cmpt,"chan:")==1)) {

#line 415 "/home/alois/Documents/bah-bah/src/var.bah"
string__trimLeft(&cmpt,5);

#line 416 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_402 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_402[3] = " = channel();\n";____BAH_COMPILER_VAR_402[2] = m->name;____BAH_COMPILER_VAR_402[1] = sep;____BAH_COMPILER_VAR_402[0] = v->name;char * ____BAH_COMPILER_VAR_403 =__Bah_multiple_concat(____BAH_COMPILER_VAR_402, 4);char** ____BAH_COMPILER_VAR_404 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_404[1] = ____BAH_COMPILER_VAR_403;____BAH_COMPILER_VAR_404[0] = code;char * ____BAH_COMPILER_VAR_405 =__Bah_multiple_concat(____BAH_COMPILER_VAR_404, 2);code = ____BAH_COMPILER_VAR_405;
}
};

#line 420 "/home/alois/Documents/bah-bah/src/var.bah"
if ((s->isBinding==false)) {

#line 421 "/home/alois/Documents/bah-bah/src/var.bah"
long int found = 0;

#line 422 "/home/alois/Documents/bah-bah/src/var.bah"
i = 0;

#line 422 "/home/alois/Documents/bah-bah/src/var.bah"
for (; (i<len(s->methods)); 
#line 422 "/home/alois/Documents/bah-bah/src/var.bah"
++i) {

#line 423 "/home/alois/Documents/bah-bah/src/var.bah"
struct func* m = s->methods->data[i];

#line 424 "/home/alois/Documents/bah-bah/src/var.bah"
if ((strcmp(m->name, "_init") == 0)) {

#line 425 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_406 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_406[6] = ");\n";____BAH_COMPILER_VAR_406[5] = v->name;____BAH_COMPILER_VAR_406[4] = amp;____BAH_COMPILER_VAR_406[3] = "(";____BAH_COMPILER_VAR_406[2] = m->name;____BAH_COMPILER_VAR_406[1] = sep;____BAH_COMPILER_VAR_406[0] = v->name;char * ____BAH_COMPILER_VAR_407 =__Bah_multiple_concat(____BAH_COMPILER_VAR_406, 7);char** ____BAH_COMPILER_VAR_408 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_408[1] = ____BAH_COMPILER_VAR_407;____BAH_COMPILER_VAR_408[0] = NEXT_LINE;char * ____BAH_COMPILER_VAR_409 =__Bah_multiple_concat(____BAH_COMPILER_VAR_408, 2);NEXT_LINE = ____BAH_COMPILER_VAR_409;

#line 426 "/home/alois/Documents/bah-bah/src/var.bah"
++found;
}

#line 427 "/home/alois/Documents/bah-bah/src/var.bah"
else if ((strcmp(m->name, "_end") == 0)) {

#line 428 "/home/alois/Documents/bah-bah/src/var.bah"
if ((strcmp(sep, "->") == 0)) {

#line 429 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_410 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_410[6] = ");\n";____BAH_COMPILER_VAR_410[5] = m->name;____BAH_COMPILER_VAR_410[4] = sep;____BAH_COMPILER_VAR_410[3] = v->name;____BAH_COMPILER_VAR_410[2] = ", ";____BAH_COMPILER_VAR_410[1] = v->name;____BAH_COMPILER_VAR_410[0] = "memoryOnEnd(";char * ____BAH_COMPILER_VAR_411 =__Bah_multiple_concat(____BAH_COMPILER_VAR_410, 7);char** ____BAH_COMPILER_VAR_412 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_412[1] = ____BAH_COMPILER_VAR_411;____BAH_COMPILER_VAR_412[0] = code;char * ____BAH_COMPILER_VAR_413 =__Bah_multiple_concat(____BAH_COMPILER_VAR_412, 2);code = ____BAH_COMPILER_VAR_413;
}

#line 431 "/home/alois/Documents/bah-bah/src/var.bah"
++found;
}

#line 433 "/home/alois/Documents/bah-bah/src/var.bah"
if ((found==2)) {

#line 434 "/home/alois/Documents/bah-bah/src/var.bah"
break;
}
};
}

#line 439 "/home/alois/Documents/bah-bah/src/var.bah"
return code;
};

#line 442 "/home/alois/Documents/bah-bah/src/var.bah"
long int NB_COMP_VAR;

#line 444 "/home/alois/Documents/bah-bah/src/var.bah"
char * genCompilerVar(){

#line 445 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_414 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_414[1] = intToStr(NB_COMP_VAR);____BAH_COMPILER_VAR_414[0] = "____BAH_COMPILER_VAR_";char * ____BAH_COMPILER_VAR_415 =__Bah_multiple_concat(____BAH_COMPILER_VAR_414, 2);char * name = ____BAH_COMPILER_VAR_415;

#line 446 "/home/alois/Documents/bah-bah/src/var.bah"
NB_COMP_VAR = NB_COMP_VAR+1;

#line 447 "/home/alois/Documents/bah-bah/src/var.bah"
return name;
};

#line 450 "/home/alois/Documents/bah-bah/src/var.bah"
typedef array(struct variable*)* __BAH_ARR_TYPE_variable;
char varInArr(struct variable* v,__BAH_ARR_TYPE_variable arr){

#line 451 "/home/alois/Documents/bah-bah/src/var.bah"
if ((arr==null)) {

#line 452 "/home/alois/Documents/bah-bah/src/var.bah"
return false;
}

#line 454 "/home/alois/Documents/bah-bah/src/var.bah"
register long int j = 0;

#line 454 "/home/alois/Documents/bah-bah/src/var.bah"
while ((j<len(arr))) {

#line 455 "/home/alois/Documents/bah-bah/src/var.bah"
struct variable* ev = arr->data[j];

#line 456 "/home/alois/Documents/bah-bah/src/var.bah"
if ((strcmp(ev->name, v->name) == 0)) {

#line 457 "/home/alois/Documents/bah-bah/src/var.bah"
return true;
}

#line 459 "/home/alois/Documents/bah-bah/src/var.bah"
j = j+1;
};

#line 461 "/home/alois/Documents/bah-bah/src/var.bah"
return false;
};

#line 464 "/home/alois/Documents/bah-bah/src/var.bah"
char * pathToVarName(char * p){

#line 465 "/home/alois/Documents/bah-bah/src/var.bah"
array(char)* a = strToArr(p);

#line 466 "/home/alois/Documents/bah-bah/src/var.bah"
register long int i = 0;

#line 466 "/home/alois/Documents/bah-bah/src/var.bah"
for (; (i<len(a)); 
#line 466 "/home/alois/Documents/bah-bah/src/var.bah"
++i) {

#line 467 "/home/alois/Documents/bah-bah/src/var.bah"
long int c = a->data[i];

#line 468 "/home/alois/Documents/bah-bah/src/var.bah"
c = c-(long int)97;

#line 469 "/home/alois/Documents/bah-bah/src/var.bah"
if ((c<0)) {

#line 470 "/home/alois/Documents/bah-bah/src/var.bah"
c = 0-c;
}

#line 472 "/home/alois/Documents/bah-bah/src/var.bah"
c = c%((long int)122-(long int)97);

#line 473 "/home/alois/Documents/bah-bah/src/var.bah"
c = c+(long int)97;

#line 474 "/home/alois/Documents/bah-bah/src/var.bah"

    unsigned int ____BAH_COMPILER_VAR_416 = i;
    __Bah_realocate_arr(a, ____BAH_COMPILER_VAR_416);
    a->data[____BAH_COMPILER_VAR_416] = (char)c;
};

#line 476 "/home/alois/Documents/bah-bah/src/var.bah"
return arrToStr(a);
};

#line 479 "/home/alois/Documents/bah-bah/src/var.bah"
void makeInit(){

#line 480 "/home/alois/Documents/bah-bah/src/var.bah"
char * name = "__BAH_init";

#line 481 "/home/alois/Documents/bah-bah/src/var.bah"
if ((isObject==true)) {

#line 482 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_417 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_417[1] = pathToVarName(compilerState.currentFile);____BAH_COMPILER_VAR_417[0] = name;char * ____BAH_COMPILER_VAR_418 =__Bah_multiple_concat(____BAH_COMPILER_VAR_417, 2);name = ____BAH_COMPILER_VAR_418;
}

#line 485 "/home/alois/Documents/bah-bah/src/var.bah"
char * evals = "";

#line 486 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_419 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_419[2] = "] = {";____BAH_COMPILER_VAR_419[1] = intToStr(len(compilerState.evals));____BAH_COMPILER_VAR_419[0] = "volatile struct __eval_binding __tmp__evals_bindings[";char * ____BAH_COMPILER_VAR_420 =__Bah_multiple_concat(____BAH_COMPILER_VAR_419, 3);char * evalsTMPDecl = ____BAH_COMPILER_VAR_420;

#line 487 "/home/alois/Documents/bah-bah/src/var.bah"
register long int i = 0;

#line 487 "/home/alois/Documents/bah-bah/src/var.bah"
for (; (i<len(compilerState.evals)); 
#line 487 "/home/alois/Documents/bah-bah/src/var.bah"
++i) {

#line 488 "/home/alois/Documents/bah-bah/src/var.bah"
char * e = compilerState.evals->data[i];

#line 489 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_421 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_421[4] = "\n        }";____BAH_COMPILER_VAR_421[3] = e;____BAH_COMPILER_VAR_421[2] = "\",\n            .evalFn = __Bah_eval_";____BAH_COMPILER_VAR_421[1] = e;____BAH_COMPILER_VAR_421[0] = "{\n            .name = \"";char * ____BAH_COMPILER_VAR_422 =__Bah_multiple_concat(____BAH_COMPILER_VAR_421, 5);char** ____BAH_COMPILER_VAR_423 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_423[1] = ____BAH_COMPILER_VAR_422;____BAH_COMPILER_VAR_423[0] = evalsTMPDecl;char * ____BAH_COMPILER_VAR_424 =__Bah_multiple_concat(____BAH_COMPILER_VAR_423, 2);evalsTMPDecl = ____BAH_COMPILER_VAR_424;

#line 493 "/home/alois/Documents/bah-bah/src/var.bah"
if ((i+1!=len(compilerState.evals))) {

#line 494 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_425 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_425[1] = ",\n";____BAH_COMPILER_VAR_425[0] = evalsTMPDecl;char * ____BAH_COMPILER_VAR_426 =__Bah_multiple_concat(____BAH_COMPILER_VAR_425, 2);evalsTMPDecl = ____BAH_COMPILER_VAR_426;
}

#line 495 "/home/alois/Documents/bah-bah/src/var.bah"
else {

#line 496 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_427 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_427[1] = "};";____BAH_COMPILER_VAR_427[0] = evalsTMPDecl;char * ____BAH_COMPILER_VAR_428 =__Bah_multiple_concat(____BAH_COMPILER_VAR_427, 2);evalsTMPDecl = ____BAH_COMPILER_VAR_428;
}
};

#line 500 "/home/alois/Documents/bah-bah/src/var.bah"
if ((len(compilerState.evals)!=0)) {

#line 501 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_429 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_429[2] = ";";____BAH_COMPILER_VAR_429[1] = intToStr(len(compilerState.evals));____BAH_COMPILER_VAR_429[0] = "__evals_bindings = __tmp__evals_bindings; __evals_length = ";char * ____BAH_COMPILER_VAR_430 =__Bah_multiple_concat(____BAH_COMPILER_VAR_429, 3);evals = ____BAH_COMPILER_VAR_430;
}

#line 502 "/home/alois/Documents/bah-bah/src/var.bah"
else {

#line 503 "/home/alois/Documents/bah-bah/src/var.bah"
evalsTMPDecl = "";
}

#line 506 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_431 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_431[4] = "() {\n        ";____BAH_COMPILER_VAR_431[3] = name;____BAH_COMPILER_VAR_431[2] = "\n    void __attribute__((optimize(\"O0\"))) ";____BAH_COMPILER_VAR_431[1] = evalsTMPDecl;____BAH_COMPILER_VAR_431[0] = "\n    ";char * ____BAH_COMPILER_VAR_432 =__Bah_multiple_concat(____BAH_COMPILER_VAR_431, 5);char** ____BAH_COMPILER_VAR_433 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_433[2] = "\n    };\n    ";____BAH_COMPILER_VAR_433[1] = evals;____BAH_COMPILER_VAR_433[0] = "\n        ";char * ____BAH_COMPILER_VAR_434 =__Bah_multiple_concat(____BAH_COMPILER_VAR_433, 3);OUTPUT = rope__add(OUTPUT, (rope__add(rope(____BAH_COMPILER_VAR_432), rope__add(INIT, rope(____BAH_COMPILER_VAR_434)))));
};

#line 515 "/home/alois/Documents/bah-bah/src/var.bah"
char checkedNull(char * v,struct Elems* elems){

#line 516 "/home/alois/Documents/bah-bah/src/var.bah"
for (; (elems!=null); 
#line 516 "/home/alois/Documents/bah-bah/src/var.bah"
elems = elems->parent) {

#line 517 "/home/alois/Documents/bah-bah/src/var.bah"
register long int i = 0;

#line 517 "/home/alois/Documents/bah-bah/src/var.bah"
for (; (i<len(elems->branchChecks)); 
#line 517 "/home/alois/Documents/bah-bah/src/var.bah"
++i) {

#line 518 "/home/alois/Documents/bah-bah/src/var.bah"
struct varCheck bc = elems->branchChecks->data[i];

#line 519 "/home/alois/Documents/bah-bah/src/var.bah"
if ((bc.v==null)) {

#line 520 "/home/alois/Documents/bah-bah/src/var.bah"
continue;
}

#line 522 "/home/alois/Documents/bah-bah/src/var.bah"
if ((strcmp(bc.v->name, v) == 0)) {

#line 523 "/home/alois/Documents/bah-bah/src/var.bah"
return bc.checkNull;
}
};

#line 526 "/home/alois/Documents/bah-bah/src/var.bah"
i = 0;

#line 526 "/home/alois/Documents/bah-bah/src/var.bah"
for (; (i<len(currChecks)); 
#line 526 "/home/alois/Documents/bah-bah/src/var.bah"
++i) {

#line 527 "/home/alois/Documents/bah-bah/src/var.bah"
struct varCheck bc = currChecks->data[i];

#line 528 "/home/alois/Documents/bah-bah/src/var.bah"
if ((bc.v==null)) {

#line 529 "/home/alois/Documents/bah-bah/src/var.bah"
continue;
}

#line 531 "/home/alois/Documents/bah-bah/src/var.bah"
if ((strcmp(bc.v->name, v) == 0)) {

#line 532 "/home/alois/Documents/bah-bah/src/var.bah"
return bc.checkNull;
}
};
};

#line 536 "/home/alois/Documents/bah-bah/src/var.bah"
return false;
};

#line 539 "/home/alois/Documents/bah-bah/src/var.bah"
char checkedNotNull(char * v,struct Elems* elems){

#line 540 "/home/alois/Documents/bah-bah/src/var.bah"
for (; (elems!=null); 
#line 540 "/home/alois/Documents/bah-bah/src/var.bah"
elems = elems->parent) {

#line 541 "/home/alois/Documents/bah-bah/src/var.bah"
register long int i = 0;

#line 541 "/home/alois/Documents/bah-bah/src/var.bah"
for (; (i<len(elems->branchChecks)); 
#line 541 "/home/alois/Documents/bah-bah/src/var.bah"
++i) {

#line 542 "/home/alois/Documents/bah-bah/src/var.bah"
struct varCheck bc = elems->branchChecks->data[i];

#line 543 "/home/alois/Documents/bah-bah/src/var.bah"
if ((bc.v==null)) {

#line 544 "/home/alois/Documents/bah-bah/src/var.bah"
continue;
}

#line 546 "/home/alois/Documents/bah-bah/src/var.bah"
if ((strcmp(bc.v->name, v) == 0)) {

#line 547 "/home/alois/Documents/bah-bah/src/var.bah"
return (bc.checkNull==false);
}
};

#line 550 "/home/alois/Documents/bah-bah/src/var.bah"
i = 0;

#line 550 "/home/alois/Documents/bah-bah/src/var.bah"
for (; (i<len(currChecks)); 
#line 550 "/home/alois/Documents/bah-bah/src/var.bah"
++i) {

#line 551 "/home/alois/Documents/bah-bah/src/var.bah"
struct varCheck bc = currChecks->data[i];

#line 552 "/home/alois/Documents/bah-bah/src/var.bah"
if ((bc.v==null)) {

#line 553 "/home/alois/Documents/bah-bah/src/var.bah"
continue;
}

#line 555 "/home/alois/Documents/bah-bah/src/var.bah"
if ((strcmp(bc.v->name, v) == 0)) {

#line 556 "/home/alois/Documents/bah-bah/src/var.bah"
return (bc.checkNull==false);
}
};
};

#line 560 "/home/alois/Documents/bah-bah/src/var.bah"
return false;
};

#line 563 "/home/alois/Documents/bah-bah/src/var.bah"
char canChangeNullState(struct variable* v,struct Elems* elems){

#line 564 "/home/alois/Documents/bah-bah/src/var.bah"
if ((v->declScope==elems)) {

#line 565 "/home/alois/Documents/bah-bah/src/var.bah"
return true;
}

#line 567 "/home/alois/Documents/bah-bah/src/var.bah"
return checkedNull(v->name,elems);
};

#line 570 "/home/alois/Documents/bah-bah/src/var.bah"
char * removeCast(char * s){

#line 571 "/home/alois/Documents/bah-bah/src/var.bah"
register long int i = strlen(s)-1;

#line 571 "/home/alois/Documents/bah-bah/src/var.bah"
for (; (i>=0); 
#line 571 "/home/alois/Documents/bah-bah/src/var.bah"
--i) {

#line 572 "/home/alois/Documents/bah-bah/src/var.bah"
if ((s[i]==41)) {

#line 573 "/home/alois/Documents/bah-bah/src/var.bah"
s = cpstringSubsitute(s, i+1, strlen(s));

#line 574 "/home/alois/Documents/bah-bah/src/var.bah"
break;
}
};

#line 577 "/home/alois/Documents/bah-bah/src/var.bah"
return s;
};

#line 8 "/home/alois/Documents/bah-bah/src/parser.bah"

#line 1 "/home/alois/Documents/bah-bah/src/mem.bah"
char isOutterScope(void * ce,struct Elems* e){

#line 2 "/home/alois/Documents/bah-bah/src/mem.bah"
while ((e!=null)) {

#line 3 "/home/alois/Documents/bah-bah/src/mem.bah"
if ((ce==e)) {

#line 4 "/home/alois/Documents/bah-bah/src/mem.bah"
return true;
}

#line 6 "/home/alois/Documents/bah-bah/src/mem.bah"
e = e->parent;
};

#line 8 "/home/alois/Documents/bah-bah/src/mem.bah"
return false;
};

#line 11 "/home/alois/Documents/bah-bah/src/mem.bah"
struct rope* decrVar(struct variable* v,struct Elems* elems){

#line 12 "/home/alois/Documents/bah-bah/src/mem.bah"
struct rope* r = rope("");

#line 14 "/home/alois/Documents/bah-bah/src/mem.bah"
if (strHasPrefix(v->type,"[]")) {

#line 15 "/home/alois/Documents/bah-bah/src/mem.bah"
char** ____BAH_COMPILER_VAR_435 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_435[2] = ");\n";____BAH_COMPILER_VAR_435[1] = v->name;____BAH_COMPILER_VAR_435[0] = "RCP_decr(";char * ____BAH_COMPILER_VAR_436 =__Bah_multiple_concat(____BAH_COMPILER_VAR_435, 3);r = rope__add(r, rope(____BAH_COMPILER_VAR_436));
}

#line 16 "/home/alois/Documents/bah-bah/src/mem.bah"
else if (strHasPrefix(v->type,"chan:")) {

#line 17 "/home/alois/Documents/bah-bah/src/mem.bah"
char** ____BAH_COMPILER_VAR_437 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_437[2] = ");\n";____BAH_COMPILER_VAR_437[1] = v->name;____BAH_COMPILER_VAR_437[0] = "RCP_decr(";char * ____BAH_COMPILER_VAR_438 =__Bah_multiple_concat(____BAH_COMPILER_VAR_437, 3);r = rope__add(r, rope(____BAH_COMPILER_VAR_438));
}

#line 18 "/home/alois/Documents/bah-bah/src/mem.bah"
else {

#line 19 "/home/alois/Documents/bah-bah/src/mem.bah"
if (strHasPrefix(v->type,"map:")) {

#line 20 "/home/alois/Documents/bah-bah/src/mem.bah"
struct variable* ____BAH_COMPILER_VAR_439 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_439->name = "";
____BAH_COMPILER_VAR_439->type = "";
____BAH_COMPILER_VAR_439->constVal = "";
____BAH_COMPILER_VAR_439->from = "";
struct variable* nv = ____BAH_COMPILER_VAR_439;

#line 21 "/home/alois/Documents/bah-bah/src/mem.bah"
*nv = *v;

#line 22 "/home/alois/Documents/bah-bah/src/mem.bah"
v = nv;

#line 23 "/home/alois/Documents/bah-bah/src/mem.bah"
v->type = "mapWrapper*";
}

#line 26 "/home/alois/Documents/bah-bah/src/mem.bah"
char isPointer = isRCPpointerType(v->type);

#line 28 "/home/alois/Documents/bah-bah/src/mem.bah"
struct cStruct* s = searchStruct(v->type,elems);

#line 29 "/home/alois/Documents/bah-bah/src/mem.bah"
if ((s!=null)&&(s->isBinding==false)) {

#line 30 "/home/alois/Documents/bah-bah/src/mem.bah"
if ((isPointer==true)) {

#line 31 "/home/alois/Documents/bah-bah/src/mem.bah"
char** ____BAH_COMPILER_VAR_440 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_440[2] = ");\n";____BAH_COMPILER_VAR_440[1] = v->name;____BAH_COMPILER_VAR_440[0] = "RCP_decr(";char * ____BAH_COMPILER_VAR_441 =__Bah_multiple_concat(____BAH_COMPILER_VAR_440, 3);r = rope__add(r, rope(____BAH_COMPILER_VAR_441));
}

#line 32 "/home/alois/Documents/bah-bah/src/mem.bah"
else {

#line 33 "/home/alois/Documents/bah-bah/src/mem.bah"
char** ____BAH_COMPILER_VAR_442 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_442[4] = "), 1);\n";____BAH_COMPILER_VAR_442[3] = v->name;____BAH_COMPILER_VAR_442[2] = ", sizeof(";____BAH_COMPILER_VAR_442[1] = v->name;____BAH_COMPILER_VAR_442[0] = "RCP_scanStack(&";char * ____BAH_COMPILER_VAR_443 =__Bah_multiple_concat(____BAH_COMPILER_VAR_442, 5);r = rope__add(r, rope(____BAH_COMPILER_VAR_443));
}
}

#line 35 "/home/alois/Documents/bah-bah/src/mem.bah"
else if ((isPointer==true)) {

#line 37 "/home/alois/Documents/bah-bah/src/mem.bah"
char** ____BAH_COMPILER_VAR_444 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_444[2] = ");\n";____BAH_COMPILER_VAR_444[1] = v->name;____BAH_COMPILER_VAR_444[0] = "RCP_decr(";char * ____BAH_COMPILER_VAR_445 =__Bah_multiple_concat(____BAH_COMPILER_VAR_444, 3);r = rope__add(r, rope(____BAH_COMPILER_VAR_445));
}
}

#line 40 "/home/alois/Documents/bah-bah/src/mem.bah"
return r;
};

#line 43 "/home/alois/Documents/bah-bah/src/mem.bah"
struct rope* incrVar(struct variable* v,struct Elems* elems){

#line 45 "/home/alois/Documents/bah-bah/src/mem.bah"
if ((strCount(v->name,"*")>0)) {

#line 46 "/home/alois/Documents/bah-bah/src/mem.bah"
return rope("");
}

#line 49 "/home/alois/Documents/bah-bah/src/mem.bah"
struct cStruct* s = searchStruct(v->type,elems);

#line 50 "/home/alois/Documents/bah-bah/src/mem.bah"
if ((s!=null)&&(isRCPpointerType(v->type)==false)&&(s->isBinding==false)) {

#line 51 "/home/alois/Documents/bah-bah/src/mem.bah"
char** ____BAH_COMPILER_VAR_446 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_446[4] = "), 0);";____BAH_COMPILER_VAR_446[3] = v->name;____BAH_COMPILER_VAR_446[2] = ", sizeof(";____BAH_COMPILER_VAR_446[1] = v->name;____BAH_COMPILER_VAR_446[0] = "RCP_scanStack(&";char * ____BAH_COMPILER_VAR_447 =__Bah_multiple_concat(____BAH_COMPILER_VAR_446, 5);return rope(____BAH_COMPILER_VAR_447);
}

#line 54 "/home/alois/Documents/bah-bah/src/mem.bah"
char** ____BAH_COMPILER_VAR_448 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_448[2] = ");";____BAH_COMPILER_VAR_448[1] = v->name;____BAH_COMPILER_VAR_448[0] = "RCP_incr(";char * ____BAH_COMPILER_VAR_449 =__Bah_multiple_concat(____BAH_COMPILER_VAR_448, 3);return rope(____BAH_COMPILER_VAR_449);
};

#line 57 "/home/alois/Documents/bah-bah/src/mem.bah"
char RCPavailable(){

#line 58 "/home/alois/Documents/bah-bah/src/mem.bah"
return (RCPenabled==true);
};

#line 61 "/home/alois/Documents/bah-bah/src/mem.bah"
void beginRCPscope(struct Elems* elems,__BAH_ARR_TYPE_variable excl){

#line 62 "/home/alois/Documents/bah-bah/src/mem.bah"
if ((RCPavailable()==false)) {

#line 63 "/home/alois/Documents/bah-bah/src/mem.bah"
return;
}

#line 65 "/home/alois/Documents/bah-bah/src/mem.bah"
register long int i = 0;

#line 65 "/home/alois/Documents/bah-bah/src/mem.bah"
for (; (i<len(elems->vars)); 
#line 65 "/home/alois/Documents/bah-bah/src/mem.bah"
++i) {

#line 66 "/home/alois/Documents/bah-bah/src/mem.bah"
struct variable* v = elems->vars->data[i];

#line 67 "/home/alois/Documents/bah-bah/src/mem.bah"
if (varInArr(v,excl)) {

#line 68 "/home/alois/Documents/bah-bah/src/mem.bah"
continue;
}

#line 70 "/home/alois/Documents/bah-bah/src/mem.bah"
if ((v->isGlobal==false)&&isRCPtype(v->type,elems)) {

#line 71 "/home/alois/Documents/bah-bah/src/mem.bah"
OUTPUT = rope__add(OUTPUT, incrVar(v,elems));
}
};
};

#line 76 "/home/alois/Documents/bah-bah/src/mem.bah"
void beginRCPscopeLeaky(struct Elems* elems){

#line 77 "/home/alois/Documents/bah-bah/src/mem.bah"
if ((RCPavailable()==false)) {

#line 78 "/home/alois/Documents/bah-bah/src/mem.bah"
return;
}

#line 80 "/home/alois/Documents/bah-bah/src/mem.bah"
register long int i = 0;

#line 80 "/home/alois/Documents/bah-bah/src/mem.bah"
for (; (i<len(elems->vars)); 
#line 80 "/home/alois/Documents/bah-bah/src/mem.bah"
++i) {

#line 81 "/home/alois/Documents/bah-bah/src/mem.bah"
struct variable* v = elems->vars->data[i];

#line 82 "/home/alois/Documents/bah-bah/src/mem.bah"
if ((v->isGlobal==false)&&(v->declScope==elems)&&isRCPtype(v->type,elems)) {

#line 83 "/home/alois/Documents/bah-bah/src/mem.bah"
OUTPUT = rope__add(OUTPUT, incrVar(v,elems));
}
};
};

#line 109 "/home/alois/Documents/bah-bah/src/mem.bah"
void endRCPscope(struct Elems* elems,__BAH_ARR_TYPE_variable excl){

#line 110 "/home/alois/Documents/bah-bah/src/mem.bah"
if ((RCPavailable()==false)) {

#line 112 "/home/alois/Documents/bah-bah/src/mem.bah"
return;
}

#line 114 "/home/alois/Documents/bah-bah/src/mem.bah"
register long int i = 0;

#line 114 "/home/alois/Documents/bah-bah/src/mem.bah"
for (; (i<len(elems->vars)); 
#line 114 "/home/alois/Documents/bah-bah/src/mem.bah"
++i) {

#line 115 "/home/alois/Documents/bah-bah/src/mem.bah"
struct variable* v = elems->vars->data[i];

#line 116 "/home/alois/Documents/bah-bah/src/mem.bah"
if (varInArr(v,excl)) {

#line 117 "/home/alois/Documents/bah-bah/src/mem.bah"
continue;
}

#line 119 "/home/alois/Documents/bah-bah/src/mem.bah"
if ((v->isGlobal==false)&&isRCPtype(v->type,elems)) {

#line 120 "/home/alois/Documents/bah-bah/src/mem.bah"
OUTPUT = rope__add(OUTPUT, decrVar(v,elems));
}
};
};

#line 126 "/home/alois/Documents/bah-bah/src/mem.bah"
void endRCPscopeLeaky(struct Elems* elems,struct variable* excl,char undef){

#line 127 "/home/alois/Documents/bah-bah/src/mem.bah"
if ((RCPavailable()==false)) {

#line 131 "/home/alois/Documents/bah-bah/src/mem.bah"
return;
}

#line 133 "/home/alois/Documents/bah-bah/src/mem.bah"
register long int i = 0;

#line 133 "/home/alois/Documents/bah-bah/src/mem.bah"
for (; (i<len(elems->vars)); 
#line 133 "/home/alois/Documents/bah-bah/src/mem.bah"
++i) {

#line 134 "/home/alois/Documents/bah-bah/src/mem.bah"
struct variable* v = elems->vars->data[i];

#line 135 "/home/alois/Documents/bah-bah/src/mem.bah"
if ((excl!=null)&&(strcmp(excl->name, v->name) == 0)) {

#line 136 "/home/alois/Documents/bah-bah/src/mem.bah"
continue;
}

#line 138 "/home/alois/Documents/bah-bah/src/mem.bah"
if ((v->isGlobal==false)&&(v->declScope==elems)&&isRCPtype(v->type,elems)) {

#line 139 "/home/alois/Documents/bah-bah/src/mem.bah"
OUTPUT = rope__add(OUTPUT, decrVar(v,elems));
}
};
};

#line 147 "/home/alois/Documents/bah-bah/src/mem.bah"
char * registerRCPvar(char * t,char * c,struct Elems* elems){

#line 148 "/home/alois/Documents/bah-bah/src/mem.bah"
struct variable* ____BAH_COMPILER_VAR_450 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_450->name = "";
____BAH_COMPILER_VAR_450->type = "";
____BAH_COMPILER_VAR_450->constVal = "";
____BAH_COMPILER_VAR_450->from = "";
struct variable* av = ____BAH_COMPILER_VAR_450;

#line 149 "/home/alois/Documents/bah-bah/src/mem.bah"
av->type = t;

#line 150 "/home/alois/Documents/bah-bah/src/mem.bah"
av->declScope = elems;

#line 151 "/home/alois/Documents/bah-bah/src/mem.bah"
av->name = genCompilerVar();

#line 152 "/home/alois/Documents/bah-bah/src/mem.bah"

    unsigned int ____BAH_COMPILER_VAR_451 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_451);
    elems->vars->data[____BAH_COMPILER_VAR_451] = av;

#line 153 "/home/alois/Documents/bah-bah/src/mem.bah"
struct string cType = getCType(av->type,elems);

#line 154 "/home/alois/Documents/bah-bah/src/mem.bah"
if (isGlobal()) {

#line 155 "/home/alois/Documents/bah-bah/src/mem.bah"
char** ____BAH_COMPILER_VAR_452 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_452[3] = ";";____BAH_COMPILER_VAR_452[2] = av->name;____BAH_COMPILER_VAR_452[1] = " ";____BAH_COMPILER_VAR_452[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_453 =__Bah_multiple_concat(____BAH_COMPILER_VAR_452, 4);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_453));

#line 156 "/home/alois/Documents/bah-bah/src/mem.bah"
char** ____BAH_COMPILER_VAR_454 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_454[3] = ";";____BAH_COMPILER_VAR_454[2] = c;____BAH_COMPILER_VAR_454[1] = " =";____BAH_COMPILER_VAR_454[0] = av->name;char * ____BAH_COMPILER_VAR_455 =__Bah_multiple_concat(____BAH_COMPILER_VAR_454, 4);INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_455));
}

#line 157 "/home/alois/Documents/bah-bah/src/mem.bah"
else {

#line 158 "/home/alois/Documents/bah-bah/src/mem.bah"
char** ____BAH_COMPILER_VAR_456 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_456[5] = ";";____BAH_COMPILER_VAR_456[4] = c;____BAH_COMPILER_VAR_456[3] = " =";____BAH_COMPILER_VAR_456[2] = av->name;____BAH_COMPILER_VAR_456[1] = " ";____BAH_COMPILER_VAR_456[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_457 =__Bah_multiple_concat(____BAH_COMPILER_VAR_456, 6);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_457));
}

#line 160 "/home/alois/Documents/bah-bah/src/mem.bah"
return av->name;
};

#line 163 "/home/alois/Documents/bah-bah/src/mem.bah"
char RCPselfRef(struct variable* v){

#line 164 "/home/alois/Documents/bah-bah/src/mem.bah"
register long int i = 0;

#line 164 "/home/alois/Documents/bah-bah/src/mem.bah"
while ((i<len(compilerState.RCPvars))) {

#line 165 "/home/alois/Documents/bah-bah/src/mem.bah"
struct variable* r = compilerState.RCPvars->data[i];

#line 166 "/home/alois/Documents/bah-bah/src/mem.bah"
if ((strcmp(r->name, v->name) == 0)) {

#line 167 "/home/alois/Documents/bah-bah/src/mem.bah"
return true;
}

#line 169 "/home/alois/Documents/bah-bah/src/mem.bah"
i = i+1;
};

#line 171 "/home/alois/Documents/bah-bah/src/mem.bah"
return false;
};

#line 9 "/home/alois/Documents/bah-bah/src/parser.bah"

#line 3 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
#define ASCII_RESET "\\033[0m"

#line 5 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
#define ASCII_YELLOW "\\033[33m"

#line 6 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
#define ASCII_BLUE "\\033[36m"

#line 7 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
#define ASCII_GREEN "\\033[32m"

#line 8 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
#define ASCII_MAGENTA "\\033[35m"

#line 9 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
#define ASCII_GREY "\\033[2m"

#line 11 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
struct verboseOutVar {
char * markup;
char * content;
};

#line 16 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
array(char *)* noVOfns;

#line 20 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char ____BAH_COMPILER_VAR_458(array(char *)* arr, char * el) {
        if (arr == 0) {
            return 0;
        };
        for(int i=arr->length-1; i!=-1;i--) {
            if (arr->data[i] != 0 && strcmp(arr->data[i], el) == 0) {
                return 1;
            };
        }
        return 0;
        }
char verboseOutGuard(){

#line 21 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
if ((currentFn!=null)) {

#line 22 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
if (____BAH_COMPILER_VAR_458(noVOfns, currentFn->name)) {

#line 23 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
return false;
}
}

#line 26 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
return true;
};

#line 29 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
struct verboseOutVar verboseOutTransformVar(struct variable* v,char * cont,struct Elems* elems){

#line 30 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
struct verboseOutVar ____BAH_COMPILER_VAR_459 = {};
struct verboseOutVar rv = ____BAH_COMPILER_VAR_459;

#line 31 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char * ogCont = cont;

#line 32 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
if ((strcmp(v->type, "cpstring") == 0)) {

#line 33 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char** ____BAH_COMPILER_VAR_460 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_460[2] = ")";____BAH_COMPILER_VAR_460[1] = cont;____BAH_COMPILER_VAR_460[0] = "__Bah_safe_string(";char * ____BAH_COMPILER_VAR_461 =__Bah_multiple_concat(____BAH_COMPILER_VAR_460, 3);cont = ____BAH_COMPILER_VAR_461;
}

#line 35 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char** ____BAH_COMPILER_VAR_462 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_462[1] = cont;____BAH_COMPILER_VAR_462[0] = ", ";char * ____BAH_COMPILER_VAR_463 =__Bah_multiple_concat(____BAH_COMPILER_VAR_462, 2);cont = ____BAH_COMPILER_VAR_463;

#line 36 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char * ct = "";

#line 37 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
if ((strcmp(v->type, "cpstring") == 0)) {

#line 38 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
ct = "%s";
}

#line 39 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
else if ((strcmp(v->type, "int") == 0)) {

#line 40 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
ct = "%li";
}

#line 41 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
else if ((strcmp(v->type, "float") == 0)) {

#line 42 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
ct = "%d";
}

#line 43 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
else if ((isRCPpointerType(v->type)==true)) {

#line 44 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
ct = "%p";
}

#line 45 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
else {

#line 46 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
struct cStruct* s = searchStruct(v->type,elems);

#line 47 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
if ((s==null)) {

#line 48 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
ct = "%li";
}

#line 49 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
else {

#line 50 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char** ____BAH_COMPILER_VAR_464 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_464[1] = "{";____BAH_COMPILER_VAR_464[0] = ASCII_RESET;char * ____BAH_COMPILER_VAR_465 =__Bah_multiple_concat(____BAH_COMPILER_VAR_464, 2);ct = ____BAH_COMPILER_VAR_465;

#line 51 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
cont = "";

#line 52 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
register long int i = 0;

#line 52 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
for (; (i<len(s->members)); 
#line 52 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
++i) {

#line 53 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
struct variable* m = s->members->data[i];

#line 54 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char** ____BAH_COMPILER_VAR_466 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_466[4] = m->name;____BAH_COMPILER_VAR_466[3] = ".";____BAH_COMPILER_VAR_466[2] = ")";____BAH_COMPILER_VAR_466[1] = ogCont;____BAH_COMPILER_VAR_466[0] = "(";char * ____BAH_COMPILER_VAR_467 =__Bah_multiple_concat(____BAH_COMPILER_VAR_466, 5);struct verboseOutVar mv = verboseOutTransformVar(m,____BAH_COMPILER_VAR_467,elems);

#line 55 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
if ((i!=0)) {

#line 56 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char** ____BAH_COMPILER_VAR_468 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_468[1] = ", ";____BAH_COMPILER_VAR_468[0] = ct;char * ____BAH_COMPILER_VAR_469 =__Bah_multiple_concat(____BAH_COMPILER_VAR_468, 2);ct = ____BAH_COMPILER_VAR_469;
}

#line 58 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char** ____BAH_COMPILER_VAR_470 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_470[1] = mv.markup;____BAH_COMPILER_VAR_470[0] = ct;char * ____BAH_COMPILER_VAR_471 =__Bah_multiple_concat(____BAH_COMPILER_VAR_470, 2);ct = ____BAH_COMPILER_VAR_471;

#line 59 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char** ____BAH_COMPILER_VAR_472 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_472[1] = mv.content;____BAH_COMPILER_VAR_472[0] = cont;char * ____BAH_COMPILER_VAR_473 =__Bah_multiple_concat(____BAH_COMPILER_VAR_472, 2);cont = ____BAH_COMPILER_VAR_473;
};

#line 61 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char** ____BAH_COMPILER_VAR_474 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_474[1] = "}";____BAH_COMPILER_VAR_474[0] = ct;char * ____BAH_COMPILER_VAR_475 =__Bah_multiple_concat(____BAH_COMPILER_VAR_474, 2);ct = ____BAH_COMPILER_VAR_475;
}
}

#line 66 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char** ____BAH_COMPILER_VAR_476 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_476[6] = ASCII_RESET;____BAH_COMPILER_VAR_476[5] = ct;____BAH_COMPILER_VAR_476[4] = ASCII_MAGENTA;____BAH_COMPILER_VAR_476[3] = " = ";____BAH_COMPILER_VAR_476[2] = ASCII_RESET;____BAH_COMPILER_VAR_476[1] = v->name;____BAH_COMPILER_VAR_476[0] = ASCII_BLUE;char * ____BAH_COMPILER_VAR_477 =__Bah_multiple_concat(____BAH_COMPILER_VAR_476, 7);rv.markup = ____BAH_COMPILER_VAR_477;

#line 68 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
rv.content = cont;

#line 70 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
return rv;
};

#line 73 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
struct verboseOutVar verboseOutTransformTok(struct Tok* t,struct Elems* elems){

#line 74 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
if ((t->type==TOKEN_TYPE_VAR)&&(t->isOper==false)) {

#line 75 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
struct variable* v = searchVar(t->cont,elems);

#line 76 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
if ((v==null)) {

#line 77 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
struct verboseOutVar ____BAH_COMPILER_VAR_478 = {};
struct verboseOutVar rv = ____BAH_COMPILER_VAR_478;

#line 78 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
return rv;
}
}

#line 81 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
struct variable ____BAH_COMPILER_VAR_479 = {};
____BAH_COMPILER_VAR_479.name = "";
____BAH_COMPILER_VAR_479.type = "";
____BAH_COMPILER_VAR_479.constVal = "";
____BAH_COMPILER_VAR_479.from = "";
____BAH_COMPILER_VAR_479.name = "(value)";
____BAH_COMPILER_VAR_479.type = getTypeFromToken(t,true,elems);
struct variable v = ____BAH_COMPILER_VAR_479;

#line 85 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
return verboseOutTransformVar(&v,t->cont,elems);
};

#line 88 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
void verboseOutFunc(struct func* fn,__BAH_ARR_TYPE_Tok args,long int lineNb,struct Elems* elems){

#line 89 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
if ((verboseOutGuard()==false)) {

#line 90 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
return;
}

#line 92 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char * nameColor = ASCII_YELLOW;

#line 93 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
if ((fn->isBinding==true)) {

#line 94 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
if (strHasPrefix(compilerState.currentFile,BAH_DIR)) {

#line 95 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
return;
}

#line 97 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
nameColor = ASCII_GREY;
}

#line 99 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
if (strHasPrefix(fn->file,BAH_DIR)) {

#line 100 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char hasPtr = false;

#line 101 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
register long int i = 0;

#line 101 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
for (; (i<len(fn->args)); 
#line 101 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
++i) {

#line 102 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
struct variable* a = fn->args->data[i];

#line 103 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
if ((isRCPpointerType(a->type)==true)) {

#line 104 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
hasPtr = true;

#line 105 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
break;
}
};

#line 108 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
if ((hasPtr==false)) {

#line 109 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
return;
}
}

#line 113 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char * fnArgs = "";

#line 114 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char * fnArgsValues = "";

#line 115 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
register long int j = 0;

#line 115 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
for (; (j<len(fn->args)); 
#line 115 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
++j) {

#line 116 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
struct variable* a = fn->args->data[j];

#line 117 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
if ((j!=0)) {

#line 118 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char** ____BAH_COMPILER_VAR_480 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_480[1] = ", ";____BAH_COMPILER_VAR_480[0] = fnArgs;char * ____BAH_COMPILER_VAR_481 =__Bah_multiple_concat(____BAH_COMPILER_VAR_480, 2);fnArgs = ____BAH_COMPILER_VAR_481;
}

#line 121 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
struct Tok t = args->data[j];

#line 122 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
struct verboseOutVar v = verboseOutTransformVar(a,t.cont,elems);

#line 123 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char** ____BAH_COMPILER_VAR_482 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_482[1] = v.markup;____BAH_COMPILER_VAR_482[0] = fnArgs;char * ____BAH_COMPILER_VAR_483 =__Bah_multiple_concat(____BAH_COMPILER_VAR_482, 2);fnArgs = ____BAH_COMPILER_VAR_483;

#line 124 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char** ____BAH_COMPILER_VAR_484 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_484[1] = v.content;____BAH_COMPILER_VAR_484[0] = fnArgsValues;char * ____BAH_COMPILER_VAR_485 =__Bah_multiple_concat(____BAH_COMPILER_VAR_484, 2);fnArgsValues = ____BAH_COMPILER_VAR_485;
};

#line 126 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char** ____BAH_COMPILER_VAR_486 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_486[2] = intToStr(lineNb);____BAH_COMPILER_VAR_486[1] = ":";____BAH_COMPILER_VAR_486[0] = compilerState.currentFile;char * ____BAH_COMPILER_VAR_487 =__Bah_multiple_concat(____BAH_COMPILER_VAR_486, 3);char * line = ____BAH_COMPILER_VAR_487;

#line 127 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char** ____BAH_COMPILER_VAR_488 = alloca(13 * sizeof(char*));____BAH_COMPILER_VAR_488[12] = ");\n    //\n    ";____BAH_COMPILER_VAR_488[11] = fnArgsValues;____BAH_COMPILER_VAR_488[10] = "\\n\"";____BAH_COMPILER_VAR_488[9] = ASCII_RESET;____BAH_COMPILER_VAR_488[8] = line;____BAH_COMPILER_VAR_488[7] = ASCII_GREEN;____BAH_COMPILER_VAR_488[6] = ") -> ";____BAH_COMPILER_VAR_488[5] = fnArgs;____BAH_COMPILER_VAR_488[4] = "(";____BAH_COMPILER_VAR_488[3] = ASCII_RESET;____BAH_COMPILER_VAR_488[2] = fn->name;____BAH_COMPILER_VAR_488[1] = nameColor;____BAH_COMPILER_VAR_488[0] = "\n    //Verbose Runtime\n        printf(\"[VO] calling: ";char * ____BAH_COMPILER_VAR_489 =__Bah_multiple_concat(____BAH_COMPILER_VAR_488, 13);struct rope* verboseOut = rope(____BAH_COMPILER_VAR_489);

#line 132 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
if (isGlobal()) {

#line 133 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
INIT = rope__add(INIT, verboseOut);
}

#line 134 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
else {

#line 135 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
OUTPUT = rope__add(OUTPUT, verboseOut);
}
};

#line 140 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
void verboseOutOper(struct Tok* pt,struct Tok* nt,long int lineNb,struct Elems* elems){

#line 141 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
if ((verboseOutGuard()==false)) {

#line 142 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
return;
}

#line 144 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
struct verboseOutVar pvo = verboseOutTransformTok(pt,elems);

#line 145 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
struct verboseOutVar nvo = verboseOutTransformTok(nt,elems);

#line 147 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char** ____BAH_COMPILER_VAR_490 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_490[1] = nvo.content;____BAH_COMPILER_VAR_490[0] = pvo.content;char * ____BAH_COMPILER_VAR_491 =__Bah_multiple_concat(____BAH_COMPILER_VAR_490, 2);char * values = ____BAH_COMPILER_VAR_491;

#line 149 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char** ____BAH_COMPILER_VAR_492 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_492[2] = intToStr(lineNb);____BAH_COMPILER_VAR_492[1] = ":";____BAH_COMPILER_VAR_492[0] = compilerState.currentFile;char * ____BAH_COMPILER_VAR_493 =__Bah_multiple_concat(____BAH_COMPILER_VAR_492, 3);char * line = ____BAH_COMPILER_VAR_493;

#line 150 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char** ____BAH_COMPILER_VAR_494 = alloca(11 * sizeof(char*));____BAH_COMPILER_VAR_494[10] = ");\n    //\n    ";____BAH_COMPILER_VAR_494[9] = values;____BAH_COMPILER_VAR_494[8] = "\\n\"";____BAH_COMPILER_VAR_494[7] = ASCII_RESET;____BAH_COMPILER_VAR_494[6] = line;____BAH_COMPILER_VAR_494[5] = ASCII_GREEN;____BAH_COMPILER_VAR_494[4] = " -> ";____BAH_COMPILER_VAR_494[3] = nvo.markup;____BAH_COMPILER_VAR_494[2] = " AND ";____BAH_COMPILER_VAR_494[1] = pvo.markup;____BAH_COMPILER_VAR_494[0] = "\n    //Verbose Runtime\n        printf(\"[VO]    oper: ";char * ____BAH_COMPILER_VAR_495 =__Bah_multiple_concat(____BAH_COMPILER_VAR_494, 11);struct rope* verboseOut = rope(____BAH_COMPILER_VAR_495);

#line 155 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
if (isGlobal()) {

#line 156 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
INIT = rope__add(INIT, verboseOut);
}

#line 157 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
else {

#line 158 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
OUTPUT = rope__add(OUTPUT, verboseOut);
}
};

#line 10 "/home/alois/Documents/bah-bah/src/parser.bah"

#line 1 "/home/alois/Documents/bah-bah/src/cache.bah"

#line 2 "/home/alois/Documents/bah-bah/src/cache.bah"

#line 4 "/home/alois/Documents/bah-bah/src/cache.bah"
struct cacheFile {
char * file;
long int last;
char * ver;
long int date;
long int mem;
long int opti;
array(char *)* files;
};

#line 14 "/home/alois/Documents/bah-bah/src/cache.bah"
array(struct cacheFile*)* cache;

#line 16 "/home/alois/Documents/bah-bah/src/cache.bah"
void readCache(){

#line 17 "/home/alois/Documents/bah-bah/src/cache.bah"
struct fileStream ____BAH_COMPILER_VAR_496 = {};
struct fileStream fs = ____BAH_COMPILER_VAR_496;

#line 18 "/home/alois/Documents/bah-bah/src/cache.bah"
char** ____BAH_COMPILER_VAR_497 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_497[1] = "cache/cache.json";____BAH_COMPILER_VAR_497[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_498 =__Bah_multiple_concat(____BAH_COMPILER_VAR_497, 2);fileStream__open(&fs,____BAH_COMPILER_VAR_498,"r");

#line 19 "/home/alois/Documents/bah-bah/src/cache.bah"
if ((fileStream__isValid(&fs)==0)||(fileStream__getSize(&fs)==0)) {

#line 20 "/home/alois/Documents/bah-bah/src/cache.bah"
char** ____BAH_COMPILER_VAR_499 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_499[1] = "cache";____BAH_COMPILER_VAR_499[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_500 =__Bah_multiple_concat(____BAH_COMPILER_VAR_499, 2);mkdir(____BAH_COMPILER_VAR_500,S_IRWXU);

#line 21 "/home/alois/Documents/bah-bah/src/cache.bah"
char** ____BAH_COMPILER_VAR_501 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_501[1] = "cache/cache.json";____BAH_COMPILER_VAR_501[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_502 =__Bah_multiple_concat(____BAH_COMPILER_VAR_501, 2);fileStream__createFile(&fs,____BAH_COMPILER_VAR_502);

#line 22 "/home/alois/Documents/bah-bah/src/cache.bah"
return;
}

#line 24 "/home/alois/Documents/bah-bah/src/cache.bah"
if ((fileStream__getSize(&fs)>0)) {

#line 25 "/home/alois/Documents/bah-bah/src/cache.bah"
char * ____BAH_COMPILER_VAR_503 =fileStream__readContent(&fs);struct jsonElement* j = parseJson(____BAH_COMPILER_VAR_503);

#line 26 "/home/alois/Documents/bah-bah/src/cache.bah"
fileStream__close(&fs);

#line 27 "/home/alois/Documents/bah-bah/src/cache.bah"
array(struct cacheFile**)* ____BAH_COMPILER_VAR_504 = &cache;
struct cacheFile*** ____BAH_COMPILER_VAR_505 = 0;
char ** ____BAH_COMPILER_VAR_507 = (char **)((char*)(____BAH_COMPILER_VAR_505) + offsetof(struct cacheFile, file));
struct reflectElement ____BAH_COMPILER_VAR_508 = __reflect(____BAH_COMPILER_VAR_507, sizeof(char *), "cpstring", "file", 0, 0, 0, 0, offsetof(struct cacheFile, file));
long int* ____BAH_COMPILER_VAR_509 = (long int*)((char*)(____BAH_COMPILER_VAR_505) + offsetof(struct cacheFile, last));
struct reflectElement ____BAH_COMPILER_VAR_510 = __reflect(____BAH_COMPILER_VAR_509, sizeof(long int), "int", "last", 0, 0, 0, 0, offsetof(struct cacheFile, last));
char ** ____BAH_COMPILER_VAR_511 = (char **)((char*)(____BAH_COMPILER_VAR_505) + offsetof(struct cacheFile, ver));
struct reflectElement ____BAH_COMPILER_VAR_512 = __reflect(____BAH_COMPILER_VAR_511, sizeof(char *), "cpstring", "ver", 0, 0, 0, 0, offsetof(struct cacheFile, ver));
long int* ____BAH_COMPILER_VAR_513 = (long int*)((char*)(____BAH_COMPILER_VAR_505) + offsetof(struct cacheFile, date));
struct reflectElement ____BAH_COMPILER_VAR_514 = __reflect(____BAH_COMPILER_VAR_513, sizeof(long int), "int", "date", 0, 0, 0, 0, offsetof(struct cacheFile, date));
long int* ____BAH_COMPILER_VAR_515 = (long int*)((char*)(____BAH_COMPILER_VAR_505) + offsetof(struct cacheFile, mem));
struct reflectElement ____BAH_COMPILER_VAR_516 = __reflect(____BAH_COMPILER_VAR_515, sizeof(long int), "int", "mem", 0, 0, 0, 0, offsetof(struct cacheFile, mem));
long int* ____BAH_COMPILER_VAR_517 = (long int*)((char*)(____BAH_COMPILER_VAR_505) + offsetof(struct cacheFile, opti));
struct reflectElement ____BAH_COMPILER_VAR_518 = __reflect(____BAH_COMPILER_VAR_517, sizeof(long int), "int", "opti", 0, 0, 0, 0, offsetof(struct cacheFile, opti));
array(char *)** ____BAH_COMPILER_VAR_519 = (array(char *)**)((char*)(____BAH_COMPILER_VAR_505) + offsetof(struct cacheFile, files));
char ** ____BAH_COMPILER_VAR_520 = 0;
struct reflectElement ____BAH_COMPILER_VAR_521 = __reflect(____BAH_COMPILER_VAR_520, sizeof(char *), "cpstring", "", 0, 0, 0, 0, 0);

        struct reflectElement ____BAH_COMPILER_VAR_522 = ____BAH_COMPILER_VAR_521;
        struct reflectElement ____BAH_COMPILER_VAR_523 = __reflect(____BAH_COMPILER_VAR_519, sizeof(array(char *)*), "[]cpstring", "files", 1, &____BAH_COMPILER_VAR_522, 0, 0, offsetof(struct cacheFile, files));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_506 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_506->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_506->length = 7;
        ____BAH_COMPILER_VAR_506->data = memoryAlloc(____BAH_COMPILER_VAR_506->length * ____BAH_COMPILER_VAR_506->elemSize);
        ____BAH_COMPILER_VAR_506->data[0] = ____BAH_COMPILER_VAR_508;
____BAH_COMPILER_VAR_506->data[1] = ____BAH_COMPILER_VAR_510;
____BAH_COMPILER_VAR_506->data[2] = ____BAH_COMPILER_VAR_512;
____BAH_COMPILER_VAR_506->data[3] = ____BAH_COMPILER_VAR_514;
____BAH_COMPILER_VAR_506->data[4] = ____BAH_COMPILER_VAR_516;
____BAH_COMPILER_VAR_506->data[5] = ____BAH_COMPILER_VAR_518;
____BAH_COMPILER_VAR_506->data[6] = ____BAH_COMPILER_VAR_523;
struct reflectElement ____BAH_COMPILER_VAR_524 = __reflect(____BAH_COMPILER_VAR_505, sizeof(struct cacheFile), "cacheFile**", "", 0, 0, 1, ____BAH_COMPILER_VAR_506, 0);

        struct reflectElement ____BAH_COMPILER_VAR_525 = ____BAH_COMPILER_VAR_524;
        struct reflectElement ____BAH_COMPILER_VAR_526 = __reflect(____BAH_COMPILER_VAR_504, sizeof(array(struct cacheFile**)*), "[]cacheFile**", "&cache", 1, &____BAH_COMPILER_VAR_525, 0, 0, 0);
jsonElement__scan(j,____BAH_COMPILER_VAR_526);
}
};

#line 33 "/home/alois/Documents/bah-bah/src/cache.bah"
struct cacheFile* getCacheFile(char * s){

#line 34 "/home/alois/Documents/bah-bah/src/cache.bah"
if ((cache==null)) {

#line 35 "/home/alois/Documents/bah-bah/src/cache.bah"
return null;
}

#line 37 "/home/alois/Documents/bah-bah/src/cache.bah"
register long int i = 0;

#line 37 "/home/alois/Documents/bah-bah/src/cache.bah"
for (; (i<len(cache)); 
#line 37 "/home/alois/Documents/bah-bah/src/cache.bah"
++i) {

#line 38 "/home/alois/Documents/bah-bah/src/cache.bah"
struct cacheFile* c = cache->data[i];

#line 39 "/home/alois/Documents/bah-bah/src/cache.bah"
if ((strcmp(c->file, s) == 0)&&(c->mem==RCPlevel)&&(c->opti==isOptimized)) {

#line 40 "/home/alois/Documents/bah-bah/src/cache.bah"
return c;
}
};

#line 43 "/home/alois/Documents/bah-bah/src/cache.bah"
return null;
};

#line 46 "/home/alois/Documents/bah-bah/src/cache.bah"
void updateCacheFile(struct cacheFile* c){

#line 47 "/home/alois/Documents/bah-bah/src/cache.bah"
c->last = getLastModified(c->file);

#line 48 "/home/alois/Documents/bah-bah/src/cache.bah"
c->ver = BAH_VERSION;

#line 49 "/home/alois/Documents/bah-bah/src/cache.bah"
c->date = getTimeUnix();
};

#line 52 "/home/alois/Documents/bah-bah/src/cache.bah"
void makeCacheFile(char * f){

#line 53 "/home/alois/Documents/bah-bah/src/cache.bah"
struct cacheFile* ____BAH_COMPILER_VAR_527 = memoryAlloc(sizeof(struct cacheFile));
____BAH_COMPILER_VAR_527->files = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_527->files->length = 0;
            ____BAH_COMPILER_VAR_527->files->elemSize = sizeof(char *);
            struct cacheFile* c = ____BAH_COMPILER_VAR_527;

#line 54 "/home/alois/Documents/bah-bah/src/cache.bah"
c->file = f;

#line 55 "/home/alois/Documents/bah-bah/src/cache.bah"
c->ver = BAH_VERSION;

#line 56 "/home/alois/Documents/bah-bah/src/cache.bah"
c->mem = RCPlevel;

#line 57 "/home/alois/Documents/bah-bah/src/cache.bah"
c->opti = isOptimized;

#line 58 "/home/alois/Documents/bah-bah/src/cache.bah"
c->date = getTimeUnix();

#line 59 "/home/alois/Documents/bah-bah/src/cache.bah"
c->last = getLastModified(f);

#line 60 "/home/alois/Documents/bah-bah/src/cache.bah"
if ((cache==null)) {

#line 61 "/home/alois/Documents/bah-bah/src/cache.bah"
cache = memoryAlloc(sizeof(array(struct cacheFile*)));

cache->length = 0;
cache->elemSize = sizeof(struct cacheFile*);
}

#line 63 "/home/alois/Documents/bah-bah/src/cache.bah"

    unsigned int ____BAH_COMPILER_VAR_528 = len(cache);
    __Bah_realocate_arr(cache, ____BAH_COMPILER_VAR_528);
    cache->data[____BAH_COMPILER_VAR_528] = c;
};

#line 66 "/home/alois/Documents/bah-bah/src/cache.bah"
void writeCache(){

#line 67 "/home/alois/Documents/bah-bah/src/cache.bah"
struct fileStream ____BAH_COMPILER_VAR_529 = {};
struct fileStream fs = ____BAH_COMPILER_VAR_529;

#line 68 "/home/alois/Documents/bah-bah/src/cache.bah"
char** ____BAH_COMPILER_VAR_530 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_530[1] = "cache/cache.json";____BAH_COMPILER_VAR_530[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_531 =__Bah_multiple_concat(____BAH_COMPILER_VAR_530, 2);fileStream__open(&fs,____BAH_COMPILER_VAR_531,"w");

#line 69 "/home/alois/Documents/bah-bah/src/cache.bah"
array(struct cacheFile**)* ____BAH_COMPILER_VAR_532 = &cache;
struct cacheFile*** ____BAH_COMPILER_VAR_533 = 0;
char ** ____BAH_COMPILER_VAR_535 = (char **)((char*)(____BAH_COMPILER_VAR_533) + offsetof(struct cacheFile, file));
struct reflectElement ____BAH_COMPILER_VAR_536 = __reflect(____BAH_COMPILER_VAR_535, sizeof(char *), "cpstring", "file", 0, 0, 0, 0, offsetof(struct cacheFile, file));
long int* ____BAH_COMPILER_VAR_537 = (long int*)((char*)(____BAH_COMPILER_VAR_533) + offsetof(struct cacheFile, last));
struct reflectElement ____BAH_COMPILER_VAR_538 = __reflect(____BAH_COMPILER_VAR_537, sizeof(long int), "int", "last", 0, 0, 0, 0, offsetof(struct cacheFile, last));
char ** ____BAH_COMPILER_VAR_539 = (char **)((char*)(____BAH_COMPILER_VAR_533) + offsetof(struct cacheFile, ver));
struct reflectElement ____BAH_COMPILER_VAR_540 = __reflect(____BAH_COMPILER_VAR_539, sizeof(char *), "cpstring", "ver", 0, 0, 0, 0, offsetof(struct cacheFile, ver));
long int* ____BAH_COMPILER_VAR_541 = (long int*)((char*)(____BAH_COMPILER_VAR_533) + offsetof(struct cacheFile, date));
struct reflectElement ____BAH_COMPILER_VAR_542 = __reflect(____BAH_COMPILER_VAR_541, sizeof(long int), "int", "date", 0, 0, 0, 0, offsetof(struct cacheFile, date));
long int* ____BAH_COMPILER_VAR_543 = (long int*)((char*)(____BAH_COMPILER_VAR_533) + offsetof(struct cacheFile, mem));
struct reflectElement ____BAH_COMPILER_VAR_544 = __reflect(____BAH_COMPILER_VAR_543, sizeof(long int), "int", "mem", 0, 0, 0, 0, offsetof(struct cacheFile, mem));
long int* ____BAH_COMPILER_VAR_545 = (long int*)((char*)(____BAH_COMPILER_VAR_533) + offsetof(struct cacheFile, opti));
struct reflectElement ____BAH_COMPILER_VAR_546 = __reflect(____BAH_COMPILER_VAR_545, sizeof(long int), "int", "opti", 0, 0, 0, 0, offsetof(struct cacheFile, opti));
array(char *)** ____BAH_COMPILER_VAR_547 = (array(char *)**)((char*)(____BAH_COMPILER_VAR_533) + offsetof(struct cacheFile, files));
char ** ____BAH_COMPILER_VAR_548 = 0;
struct reflectElement ____BAH_COMPILER_VAR_549 = __reflect(____BAH_COMPILER_VAR_548, sizeof(char *), "cpstring", "", 0, 0, 0, 0, 0);

        struct reflectElement ____BAH_COMPILER_VAR_550 = ____BAH_COMPILER_VAR_549;
        struct reflectElement ____BAH_COMPILER_VAR_551 = __reflect(____BAH_COMPILER_VAR_547, sizeof(array(char *)*), "[]cpstring", "files", 1, &____BAH_COMPILER_VAR_550, 0, 0, offsetof(struct cacheFile, files));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_534 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_534->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_534->length = 7;
        ____BAH_COMPILER_VAR_534->data = memoryAlloc(____BAH_COMPILER_VAR_534->length * ____BAH_COMPILER_VAR_534->elemSize);
        ____BAH_COMPILER_VAR_534->data[0] = ____BAH_COMPILER_VAR_536;
____BAH_COMPILER_VAR_534->data[1] = ____BAH_COMPILER_VAR_538;
____BAH_COMPILER_VAR_534->data[2] = ____BAH_COMPILER_VAR_540;
____BAH_COMPILER_VAR_534->data[3] = ____BAH_COMPILER_VAR_542;
____BAH_COMPILER_VAR_534->data[4] = ____BAH_COMPILER_VAR_544;
____BAH_COMPILER_VAR_534->data[5] = ____BAH_COMPILER_VAR_546;
____BAH_COMPILER_VAR_534->data[6] = ____BAH_COMPILER_VAR_551;
struct reflectElement ____BAH_COMPILER_VAR_552 = __reflect(____BAH_COMPILER_VAR_533, sizeof(struct cacheFile), "cacheFile**", "", 0, 0, 1, ____BAH_COMPILER_VAR_534, 0);

        struct reflectElement ____BAH_COMPILER_VAR_553 = ____BAH_COMPILER_VAR_552;
        struct reflectElement ____BAH_COMPILER_VAR_554 = __reflect(____BAH_COMPILER_VAR_532, sizeof(array(struct cacheFile**)*), "[]cacheFile**", "&cache", 1, &____BAH_COMPILER_VAR_553, 0, 0, 0);
char * ____BAH_COMPILER_VAR_555 =toJson(____BAH_COMPILER_VAR_554);fileStream__writeFile(&fs,____BAH_COMPILER_VAR_555);

#line 70 "/home/alois/Documents/bah-bah/src/cache.bah"
fileStream__close(&fs);
};

#line 73 "/home/alois/Documents/bah-bah/src/cache.bah"
char isValidCacheFile(struct cacheFile* cf){

#line 74 "/home/alois/Documents/bah-bah/src/cache.bah"
if ((cf->last!=getLastModified(cf->file))) {

#line 75 "/home/alois/Documents/bah-bah/src/cache.bah"
return false;
}

#line 77 "/home/alois/Documents/bah-bah/src/cache.bah"
char** ____BAH_COMPILER_VAR_556 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_556[5] = ".o.o";____BAH_COMPILER_VAR_556[4] = intToStr(cf->opti);____BAH_COMPILER_VAR_556[3] = intToStr(cf->mem);____BAH_COMPILER_VAR_556[2] = pathToVarName(cf->file);____BAH_COMPILER_VAR_556[1] = "cache/";____BAH_COMPILER_VAR_556[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_557 =__Bah_multiple_concat(____BAH_COMPILER_VAR_556, 6);if ((fileExists(____BAH_COMPILER_VAR_557)==0)) {

#line 78 "/home/alois/Documents/bah-bah/src/cache.bah"
return false;
}

#line 81 "/home/alois/Documents/bah-bah/src/cache.bah"
if ((strcmp(cf->ver, BAH_VERSION) != 0)) {

#line 82 "/home/alois/Documents/bah-bah/src/cache.bah"
return false;
}

#line 84 "/home/alois/Documents/bah-bah/src/cache.bah"
return true;
};

#line 11 "/home/alois/Documents/bah-bah/src/parser.bah"

#line 1 "/home/alois/Documents/bah-bah/src/gen.bah"
char * genArrRealloc(struct variable* v,char * preVal,char * val,struct Elems* elems){

#line 3 "/home/alois/Documents/bah-bah/src/gen.bah"
struct string vn = string(v->name);

#line 4 "/home/alois/Documents/bah-bah/src/gen.bah"
char * nstr = splitStringBefore(vn,"->data[");

#line 6 "/home/alois/Documents/bah-bah/src/gen.bah"
string__trimLeft(&vn,strlen(nstr)+7);

#line 7 "/home/alois/Documents/bah-bah/src/gen.bah"
string__trimRight(&vn,1);

#line 8 "/home/alois/Documents/bah-bah/src/gen.bah"
char * nLengthStr = string__str(&vn);

#line 10 "/home/alois/Documents/bah-bah/src/gen.bah"
char * nLength = genCompilerVar();

#line 12 "/home/alois/Documents/bah-bah/src/gen.bah"
char** ____BAH_COMPILER_VAR_558 = alloca(15 * sizeof(char*));____BAH_COMPILER_VAR_558[14] = val;____BAH_COMPILER_VAR_558[13] = "] = ";____BAH_COMPILER_VAR_558[12] = nLength;____BAH_COMPILER_VAR_558[11] = "->data[";____BAH_COMPILER_VAR_558[10] = nstr;____BAH_COMPILER_VAR_558[9] = preVal;____BAH_COMPILER_VAR_558[8] = ");\n    ";____BAH_COMPILER_VAR_558[7] = nLength;____BAH_COMPILER_VAR_558[6] = ", ";____BAH_COMPILER_VAR_558[5] = nstr;____BAH_COMPILER_VAR_558[4] = ";\n    __Bah_realocate_arr(";____BAH_COMPILER_VAR_558[3] = nLengthStr;____BAH_COMPILER_VAR_558[2] = " = ";____BAH_COMPILER_VAR_558[1] = nLength;____BAH_COMPILER_VAR_558[0] = "\n    unsigned int ";char * ____BAH_COMPILER_VAR_559 =__Bah_multiple_concat(____BAH_COMPILER_VAR_558, 15);return ____BAH_COMPILER_VAR_559;
};

#line 18 "/home/alois/Documents/bah-bah/src/gen.bah"
char * genConcat(__BAH_ARR_TYPE_cpstring strs,struct Elems* elems){

#line 21 "/home/alois/Documents/bah-bah/src/gen.bah"
char * buff = genCompilerVar();

#line 22 "/home/alois/Documents/bah-bah/src/gen.bah"
char** ____BAH_COMPILER_VAR_560 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_560[4] = " * sizeof(char*));";____BAH_COMPILER_VAR_560[3] = intToStr(len(strs));____BAH_COMPILER_VAR_560[2] = " = alloca(";____BAH_COMPILER_VAR_560[1] = buff;____BAH_COMPILER_VAR_560[0] = "char** ";char * ____BAH_COMPILER_VAR_561 =__Bah_multiple_concat(____BAH_COMPILER_VAR_560, 5);char * r = ____BAH_COMPILER_VAR_561;

#line 24 "/home/alois/Documents/bah-bah/src/gen.bah"
register long int i = 0;

#line 24 "/home/alois/Documents/bah-bah/src/gen.bah"
for (; (i<len(strs)); 
#line 24 "/home/alois/Documents/bah-bah/src/gen.bah"
++i) {

#line 25 "/home/alois/Documents/bah-bah/src/gen.bah"
char** ____BAH_COMPILER_VAR_562 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_562[5] = ";";____BAH_COMPILER_VAR_562[4] = strs->data[i];____BAH_COMPILER_VAR_562[3] = "] = ";____BAH_COMPILER_VAR_562[2] = intToStr(len(strs)-i-1);____BAH_COMPILER_VAR_562[1] = "[";____BAH_COMPILER_VAR_562[0] = buff;char * ____BAH_COMPILER_VAR_563 =__Bah_multiple_concat(____BAH_COMPILER_VAR_562, 6);char** ____BAH_COMPILER_VAR_564 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_564[1] = ____BAH_COMPILER_VAR_563;____BAH_COMPILER_VAR_564[0] = r;char * ____BAH_COMPILER_VAR_565 =__Bah_multiple_concat(____BAH_COMPILER_VAR_564, 2);r = ____BAH_COMPILER_VAR_565;
};

#line 28 "/home/alois/Documents/bah-bah/src/gen.bah"
if (isGlobal()) {

#line 29 "/home/alois/Documents/bah-bah/src/gen.bah"
INIT = rope__add(INIT, rope(r));
}

#line 30 "/home/alois/Documents/bah-bah/src/gen.bah"
else {

#line 31 "/home/alois/Documents/bah-bah/src/gen.bah"
OUTPUT = rope__add(OUTPUT, rope(r));
}

#line 33 "/home/alois/Documents/bah-bah/src/gen.bah"
char** ____BAH_COMPILER_VAR_566 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_566[4] = ")";____BAH_COMPILER_VAR_566[3] = intToStr(len(strs));____BAH_COMPILER_VAR_566[2] = ", ";____BAH_COMPILER_VAR_566[1] = buff;____BAH_COMPILER_VAR_566[0] = "__Bah_multiple_concat(";char * ____BAH_COMPILER_VAR_567 =__Bah_multiple_concat(____BAH_COMPILER_VAR_566, 5);char * rstr = registerRCPvar("cpstring",____BAH_COMPILER_VAR_567,elems);

#line 35 "/home/alois/Documents/bah-bah/src/gen.bah"
return rstr;
};

#line 12 "/home/alois/Documents/bah-bah/src/parser.bah"

#line 2 "/home/alois/Documents/bah-bah/src/optimizations.bah"
void OPTI_checkFuncScopeRef(struct Elems* elems){

#line 3 "/home/alois/Documents/bah-bah/src/optimizations.bah"
if ((strHasPrefix(compilerState.currentFile,BAH_DIR)==true)) {

#line 4 "/home/alois/Documents/bah-bah/src/optimizations.bah"
return;
}

#line 6 "/home/alois/Documents/bah-bah/src/optimizations.bah"
register long int i = 0;

#line 6 "/home/alois/Documents/bah-bah/src/optimizations.bah"
for (; (i<len(elems->vars)); 
#line 6 "/home/alois/Documents/bah-bah/src/optimizations.bah"
++i) {

#line 7 "/home/alois/Documents/bah-bah/src/optimizations.bah"
struct variable* v = elems->vars->data[i];

#line 8 "/home/alois/Documents/bah-bah/src/optimizations.bah"
if ((v->isArg==false)) {

#line 9 "/home/alois/Documents/bah-bah/src/optimizations.bah"
continue;
}

#line 11 "/home/alois/Documents/bah-bah/src/optimizations.bah"
if ((v->lastSet!=elems)) {

#line 12 "/home/alois/Documents/bah-bah/src/optimizations.bah"

                struct string ____BAH_COMPILER_VAR_568 = string(v->name);
                if ((isRCPpointerType(v->type)==false)&&(strcmp(v->type, "reflectElement") != 0)&&(string__hasPrefix(&____BAH_COMPILER_VAR_568,"____BAH_COMPILER_VAR_")==false)) {

#line 13 "/home/alois/Documents/bah-bah/src/optimizations.bah"
struct cStruct* s = searchStruct(v->type,elems);

#line 14 "/home/alois/Documents/bah-bah/src/optimizations.bah"
if ((s!=null)&&(currentFn!=null)) {

#line 15 "/home/alois/Documents/bah-bah/src/optimizations.bah"
if (debug) {

#line 16 "/home/alois/Documents/bah-bah/src/optimizations.bah"
char** ____BAH_COMPILER_VAR_569 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_569[6] = ") could be passed by reference.";____BAH_COMPILER_VAR_569[5] = v->type;____BAH_COMPILER_VAR_569[4] = " (";____BAH_COMPILER_VAR_569[3] = v->name;____BAH_COMPILER_VAR_569[2] = "(): argument ";____BAH_COMPILER_VAR_569[1] = currentFn->name;____BAH_COMPILER_VAR_569[0] = "in ";char * ____BAH_COMPILER_VAR_570 =__Bah_multiple_concat(____BAH_COMPILER_VAR_569, 7);throwNoticeLine(____BAH_COMPILER_VAR_570,currentFn->line);
}

#line 18 "/home/alois/Documents/bah-bah/src/optimizations.bah"
else {

#line 19 "/home/alois/Documents/bah-bah/src/optimizations.bah"
char** ____BAH_COMPILER_VAR_571 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_571[6] = ") could be passed by reference.";____BAH_COMPILER_VAR_571[5] = v->type;____BAH_COMPILER_VAR_571[4] = "\e[0m (";____BAH_COMPILER_VAR_571[3] = v->name;____BAH_COMPILER_VAR_571[2] = "()\e[0m: argument \e[1;37m";____BAH_COMPILER_VAR_571[1] = currentFn->name;____BAH_COMPILER_VAR_571[0] = "in \e[1;37m";char * ____BAH_COMPILER_VAR_572 =__Bah_multiple_concat(____BAH_COMPILER_VAR_571, 7);throwNoticeLine(____BAH_COMPILER_VAR_572,currentFn->line);
}
}
}
}
};
};

#line 29 "/home/alois/Documents/bah-bah/src/optimizations.bah"
char isExprExpensive(struct Tok* t){

#line 30 "/home/alois/Documents/bah-bah/src/optimizations.bah"
if ((t->isExpensive==true)) {

#line 31 "/home/alois/Documents/bah-bah/src/optimizations.bah"
return true;
}

#line 34 "/home/alois/Documents/bah-bah/src/optimizations.bah"
if ((t->type!=TOKEN_TYPE_VAR)&&(t->type!=TOKEN_TYPE_INT)&&(t->type!=TOKEN_TYPE_FLOAT)) {

#line 35 "/home/alois/Documents/bah-bah/src/optimizations.bah"
return true;
}

#line 37 "/home/alois/Documents/bah-bah/src/optimizations.bah"
return false;
};

#line 41 "/home/alois/Documents/bah-bah/src/optimizations.bah"
char * byteToOctal(unsigned char b){

#line 42 "/home/alois/Documents/bah-bah/src/optimizations.bah"
unsigned int n = b;

#line 43 "/home/alois/Documents/bah-bah/src/optimizations.bah"
char * r = "";

#line 44 "/home/alois/Documents/bah-bah/src/optimizations.bah"
long int i = 0;

#line 44 "/home/alois/Documents/bah-bah/src/optimizations.bah"
for (; (n!=0); 
#line 44 "/home/alois/Documents/bah-bah/src/optimizations.bah"
++i) {

#line 45 "/home/alois/Documents/bah-bah/src/optimizations.bah"
char** ____BAH_COMPILER_VAR_573 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_573[1] = r;____BAH_COMPILER_VAR_573[0] = intToStr(n%8);char * ____BAH_COMPILER_VAR_574 =__Bah_multiple_concat(____BAH_COMPILER_VAR_573, 2);r = ____BAH_COMPILER_VAR_574;

#line 46 "/home/alois/Documents/bah-bah/src/optimizations.bah"
n = n/8;
};

#line 48 "/home/alois/Documents/bah-bah/src/optimizations.bah"
char * escp = "\\0";

#line 49 "/home/alois/Documents/bah-bah/src/optimizations.bah"
if ((i==3)) {

#line 50 "/home/alois/Documents/bah-bah/src/optimizations.bah"
escp = cpstringSubsitute(escp, 0, 1);
}

#line 52 "/home/alois/Documents/bah-bah/src/optimizations.bah"
char** ____BAH_COMPILER_VAR_575 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_575[1] = r;____BAH_COMPILER_VAR_575[0] = escp;char * ____BAH_COMPILER_VAR_576 =__Bah_multiple_concat(____BAH_COMPILER_VAR_575, 2);return ____BAH_COMPILER_VAR_576;
};

#line 56 "/home/alois/Documents/bah-bah/src/optimizations.bah"
char * escapeIntOctal(long int n){

#line 57 "/home/alois/Documents/bah-bah/src/optimizations.bah"
char * s = &n;

#line 58 "/home/alois/Documents/bah-bah/src/optimizations.bah"
char * r = "";

#line 59 "/home/alois/Documents/bah-bah/src/optimizations.bah"
register long int i = 0;

#line 59 "/home/alois/Documents/bah-bah/src/optimizations.bah"
for (; (i<8); 
#line 59 "/home/alois/Documents/bah-bah/src/optimizations.bah"
++i) {

#line 60 "/home/alois/Documents/bah-bah/src/optimizations.bah"
char** ____BAH_COMPILER_VAR_577 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_577[1] = byteToOctal((unsigned char)s[i]);____BAH_COMPILER_VAR_577[0] = r;char * ____BAH_COMPILER_VAR_578 =__Bah_multiple_concat(____BAH_COMPILER_VAR_577, 2);r = ____BAH_COMPILER_VAR_578;
};

#line 62 "/home/alois/Documents/bah-bah/src/optimizations.bah"
return r;
};

#line 65 "/home/alois/Documents/bah-bah/src/optimizations.bah"
unsigned long int getStrLen(char * s){

#line 66 "/home/alois/Documents/bah-bah/src/optimizations.bah"
long int l = 0;

#line 67 "/home/alois/Documents/bah-bah/src/optimizations.bah"
long int i = 0;

#line 67 "/home/alois/Documents/bah-bah/src/optimizations.bah"
for (; (s[i]!=null); 
#line 67 "/home/alois/Documents/bah-bah/src/optimizations.bah"
++i) {

#line 68 "/home/alois/Documents/bah-bah/src/optimizations.bah"
if ((s[i]==(char)92)) {

#line 69 "/home/alois/Documents/bah-bah/src/optimizations.bah"
continue;
}

#line 71 "/home/alois/Documents/bah-bah/src/optimizations.bah"
++l;
};

#line 73 "/home/alois/Documents/bah-bah/src/optimizations.bah"
return l;
};

#line 76 "/home/alois/Documents/bah-bah/src/optimizations.bah"
char * strLitteralToBahStr(char * s){

#line 77 "/home/alois/Documents/bah-bah/src/optimizations.bah"
return s;
};

#line 13 "/home/alois/Documents/bah-bah/src/parser.bah"

#line 2 "/home/alois/Documents/bah-bah/src/generics.bah"
struct Elems* dupElems(struct Elems* e);

#line 3 "/home/alois/Documents/bah-bah/src/generics.bah"
void parseLines(__BAH_ARR_TYPE_Tok l,struct Elems* elems);

#line 5 "/home/alois/Documents/bah-bah/src/generics.bah"
void * currGen;

#line 8 "/home/alois/Documents/bah-bah/src/generics.bah"
struct genericFunc {
array(struct Tok)* tokens;
array(struct func*)* declared;
struct func* baseFn;
struct Tok* tokenName;
struct Tok* callToken;
};
struct func* genericFunc__dupBaseFn(struct genericFunc* this){

#line 16 "/home/alois/Documents/bah-bah/src/generics.bah"
struct func* ____BAH_COMPILER_VAR_579 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_579->name = "";
____BAH_COMPILER_VAR_579->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_579->args->length = 0;
            ____BAH_COMPILER_VAR_579->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_579->from = "";
____BAH_COMPILER_VAR_579->file = "";
____BAH_COMPILER_VAR_579->line = 1;
struct func* r = ____BAH_COMPILER_VAR_579;

#line 17 "/home/alois/Documents/bah-bah/src/generics.bah"
r->name = this->baseFn->name;

#line 18 "/home/alois/Documents/bah-bah/src/generics.bah"
register long int i = 0;

#line 18 "/home/alois/Documents/bah-bah/src/generics.bah"
for (; (i<len(this->baseFn->args)); 
#line 18 "/home/alois/Documents/bah-bah/src/generics.bah"
++i) {

#line 19 "/home/alois/Documents/bah-bah/src/generics.bah"
struct variable* a = this->baseFn->args->data[i];

#line 20 "/home/alois/Documents/bah-bah/src/generics.bah"
struct variable* ____BAH_COMPILER_VAR_580 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_580->name = "";
____BAH_COMPILER_VAR_580->type = "";
____BAH_COMPILER_VAR_580->constVal = "";
____BAH_COMPILER_VAR_580->from = "";
struct variable* na = ____BAH_COMPILER_VAR_580;

#line 21 "/home/alois/Documents/bah-bah/src/generics.bah"
*na = *a;

#line 22 "/home/alois/Documents/bah-bah/src/generics.bah"

    unsigned int ____BAH_COMPILER_VAR_581 = i;
    __Bah_realocate_arr(r->args, ____BAH_COMPILER_VAR_581);
    r->args->data[____BAH_COMPILER_VAR_581] = na;
};

#line 24 "/home/alois/Documents/bah-bah/src/generics.bah"
r->returns = this->baseFn->returns;

#line 25 "/home/alois/Documents/bah-bah/src/generics.bah"
return r;
};
void genericFunc__setCurrGeneric(struct genericFunc* this,struct Tok* t){

#line 29 "/home/alois/Documents/bah-bah/src/generics.bah"
this->callToken = t;
};
char genericFunc__isAlreadyDecl(struct genericFunc* this,char * n){

#line 33 "/home/alois/Documents/bah-bah/src/generics.bah"
register long int i = 0;

#line 33 "/home/alois/Documents/bah-bah/src/generics.bah"
for (; (i<len(this->declared)); 
#line 33 "/home/alois/Documents/bah-bah/src/generics.bah"
++i) {

#line 34 "/home/alois/Documents/bah-bah/src/generics.bah"
if ((strcmp(this->declared->data[i]->name, n) == 0)) {

#line 35 "/home/alois/Documents/bah-bah/src/generics.bah"
return true;
}
};

#line 38 "/home/alois/Documents/bah-bah/src/generics.bah"
return false;
};
void genericFunc__declare(struct genericFunc* this,struct func* fn,struct Elems* elems){

#line 42 "/home/alois/Documents/bah-bah/src/generics.bah"
struct rope* oldOut = OUTPUT;

#line 43 "/home/alois/Documents/bah-bah/src/generics.bah"

    unsigned int ____BAH_COMPILER_VAR_582 = len(this->declared);
    __Bah_realocate_arr(this->declared, ____BAH_COMPILER_VAR_582);
    this->declared->data[____BAH_COMPILER_VAR_582] = fn;

#line 44 "/home/alois/Documents/bah-bah/src/generics.bah"

                struct string ____BAH_COMPILER_VAR_583 = getCType(fn->returns->type,elems);
                char** ____BAH_COMPILER_VAR_584 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_584[3] = "(";____BAH_COMPILER_VAR_584[2] = fn->name;____BAH_COMPILER_VAR_584[1] = " __generic_";____BAH_COMPILER_VAR_584[0] = string__str(&____BAH_COMPILER_VAR_583);char * ____BAH_COMPILER_VAR_585 =__Bah_multiple_concat(____BAH_COMPILER_VAR_584, 4);OUTPUT = rope(____BAH_COMPILER_VAR_585);

#line 46 "/home/alois/Documents/bah-bah/src/generics.bah"
struct Elems* fnElems = dupElems(elems);

#line 47 "/home/alois/Documents/bah-bah/src/generics.bah"
register long int i = 0;

#line 47 "/home/alois/Documents/bah-bah/src/generics.bah"
for (; (i<len(fn->args)); 
#line 47 "/home/alois/Documents/bah-bah/src/generics.bah"
++i) {

#line 48 "/home/alois/Documents/bah-bah/src/generics.bah"
struct variable* arg = fn->args->data[i];

#line 50 "/home/alois/Documents/bah-bah/src/generics.bah"
arg->declScope = elems;

#line 51 "/home/alois/Documents/bah-bah/src/generics.bah"
arg->isArg = true;

#line 52 "/home/alois/Documents/bah-bah/src/generics.bah"

    unsigned int ____BAH_COMPILER_VAR_586 = len(fnElems->vars);
    __Bah_realocate_arr(fnElems->vars, ____BAH_COMPILER_VAR_586);
    fnElems->vars->data[____BAH_COMPILER_VAR_586] = arg;

#line 54 "/home/alois/Documents/bah-bah/src/generics.bah"

                struct string ____BAH_COMPILER_VAR_587 = getCType(arg->type,elems);
                char** ____BAH_COMPILER_VAR_588 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_588[2] = arg->name;____BAH_COMPILER_VAR_588[1] = " ";____BAH_COMPILER_VAR_588[0] = string__str(&____BAH_COMPILER_VAR_587);char * ____BAH_COMPILER_VAR_589 =__Bah_multiple_concat(____BAH_COMPILER_VAR_588, 3);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_589));

#line 56 "/home/alois/Documents/bah-bah/src/generics.bah"
if ((i+1<len(fn->args))) {

#line 57 "/home/alois/Documents/bah-bah/src/generics.bah"
OUTPUT = rope__add(OUTPUT, rope(", "));
}
};

#line 61 "/home/alois/Documents/bah-bah/src/generics.bah"
OUTPUT = rope__add(OUTPUT, rope(") {\n"));

#line 63 "/home/alois/Documents/bah-bah/src/generics.bah"
beginRCPscope(fnElems,fn->args);

#line 64 "/home/alois/Documents/bah-bah/src/generics.bah"
struct Elems* ocurrFnElems = compilerState.currFnElems;

#line 65 "/home/alois/Documents/bah-bah/src/generics.bah"
void * oCurrGen = currGen;

#line 66 "/home/alois/Documents/bah-bah/src/generics.bah"
currGen = this;

#line 67 "/home/alois/Documents/bah-bah/src/generics.bah"
struct func* oCurrFn = currentFn;

#line 68 "/home/alois/Documents/bah-bah/src/generics.bah"
compilerState.currFnElems = fnElems;

#line 69 "/home/alois/Documents/bah-bah/src/generics.bah"
parseLines(this->tokens,fnElems);

#line 70 "/home/alois/Documents/bah-bah/src/generics.bah"
OPTI_checkFuncScopeRef(fnElems);

#line 72 "/home/alois/Documents/bah-bah/src/generics.bah"
compilerState.currFnElems = ocurrFnElems;

#line 73 "/home/alois/Documents/bah-bah/src/generics.bah"
currentFn = oCurrFn;

#line 74 "/home/alois/Documents/bah-bah/src/generics.bah"
currGen = oCurrGen;

#line 76 "/home/alois/Documents/bah-bah/src/generics.bah"
if ((fn->returned==false)) {

#line 77 "/home/alois/Documents/bah-bah/src/generics.bah"
if (__builtin_expect((strlen(fn->returns->type)>0), 0)) {

#line 78 "/home/alois/Documents/bah-bah/src/generics.bah"
char** ____BAH_COMPILER_VAR_590 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_590[2] = "' is not returned.";____BAH_COMPILER_VAR_590[1] = fn->name;____BAH_COMPILER_VAR_590[0] = "Function '";char * ____BAH_COMPILER_VAR_591 =__Bah_multiple_concat(____BAH_COMPILER_VAR_590, 3);throwErr(this->tokenName,____BAH_COMPILER_VAR_591);
}

#line 80 "/home/alois/Documents/bah-bah/src/generics.bah"
endRCPscope(fnElems,fn->args);
}

#line 82 "/home/alois/Documents/bah-bah/src/generics.bah"
else {
}

#line 86 "/home/alois/Documents/bah-bah/src/generics.bah"
struct rope* code = rope__add(OUTPUT, rope("};\n"));

#line 87 "/home/alois/Documents/bah-bah/src/generics.bah"
OUTPUT = oldOut;

#line 88 "/home/alois/Documents/bah-bah/src/generics.bah"
char** ____BAH_COMPILER_VAR_592 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_592[1] = rope__toStr(code);____BAH_COMPILER_VAR_592[0] = rope__toStr(postDeclHandle);char * ____BAH_COMPILER_VAR_593 =__Bah_multiple_concat(____BAH_COMPILER_VAR_592, 2);OUTPUT->totalLen = OUTPUT->totalLen+ropeSet(postDeclHandle,____BAH_COMPILER_VAR_593);
};

#line 92 "/home/alois/Documents/bah-bah/src/generics.bah"
array(struct genericFunc*)* generics;

#line 94 "/home/alois/Documents/bah-bah/src/generics.bah"
void advertiseGeneric(){

#line 95 "/home/alois/Documents/bah-bah/src/generics.bah"
if ((currGen==null)) {

#line 96 "/home/alois/Documents/bah-bah/src/generics.bah"
return;
}

#line 98 "/home/alois/Documents/bah-bah/src/generics.bah"
struct genericFunc* gen = currGen;

#line 100 "/home/alois/Documents/bah-bah/src/generics.bah"
char** ____BAH_COMPILER_VAR_594 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_594[3] = intToStr(gen->callToken->line);____BAH_COMPILER_VAR_594[2] = ":";____BAH_COMPILER_VAR_594[1] = compilerState.currentFile;____BAH_COMPILER_VAR_594[0] = "[Generic] called here: ";char * ____BAH_COMPILER_VAR_595 =__Bah_multiple_concat(____BAH_COMPILER_VAR_594, 4);println(____BAH_COMPILER_VAR_595);
};

#line 17 "/home/alois/Documents/bah-bah/src/parser.bah"
void debugLine(__BAH_ARR_TYPE_Tok line){

#line 18 "/home/alois/Documents/bah-bah/src/parser.bah"
char * cont = "";

#line 19 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int i = 0;

#line 19 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i<len(line))) {

#line 20 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = line->data[i];

#line 21 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_596 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_596[3] = "'";____BAH_COMPILER_VAR_596[2] = t.cont;____BAH_COMPILER_VAR_596[1] = " '";____BAH_COMPILER_VAR_596[0] = cont;char * ____BAH_COMPILER_VAR_597 =__Bah_multiple_concat(____BAH_COMPILER_VAR_596, 4);cont = ____BAH_COMPILER_VAR_597;

#line 22 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;
};

#line 24 "/home/alois/Documents/bah-bah/src/parser.bah"
println(cont);
};

#line 28 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Elems* dupElems(struct Elems* elems){

#line 29 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Elems* ____BAH_COMPILER_VAR_598 = memoryAlloc(sizeof(struct Elems));
____BAH_COMPILER_VAR_598->vars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_598->vars->length = 0;
            ____BAH_COMPILER_VAR_598->vars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_598->structs = memoryAlloc(sizeof(array(struct cStruct*)));
            ____BAH_COMPILER_VAR_598->structs->length = 0;
            ____BAH_COMPILER_VAR_598->structs->elemSize = sizeof(struct cStruct*);
            ____BAH_COMPILER_VAR_598->types = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_598->types->length = 0;
            ____BAH_COMPILER_VAR_598->types->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_598->fns = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_598->fns->length = 0;
            ____BAH_COMPILER_VAR_598->fns->elemSize = sizeof(struct func*);
            ____BAH_COMPILER_VAR_598->deletedVars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_598->deletedVars->length = 0;
            ____BAH_COMPILER_VAR_598->deletedVars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_598->branchChecks = memoryAlloc(sizeof(array(struct varCheck)));
            ____BAH_COMPILER_VAR_598->branchChecks->length = 0;
            ____BAH_COMPILER_VAR_598->branchChecks->elemSize = sizeof(struct varCheck);
            struct Elems* nElems = ____BAH_COMPILER_VAR_598;

#line 30 "/home/alois/Documents/bah-bah/src/parser.bah"
nElems->parent = elems;

#line 33 "/home/alois/Documents/bah-bah/src/parser.bah"
allocateArray(nElems->vars,len(elems->vars));

#line 34 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int j = 0;

#line 34 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (j<len(elems->vars)); 
#line 34 "/home/alois/Documents/bah-bah/src/parser.bah"
++j) {

#line 35 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_599 = j;
    __Bah_realocate_arr(nElems->vars, ____BAH_COMPILER_VAR_599);
    nElems->vars->data[____BAH_COMPILER_VAR_599] = elems->vars->data[j];
};

#line 39 "/home/alois/Documents/bah-bah/src/parser.bah"
nElems->structs = elems->structs;

#line 42 "/home/alois/Documents/bah-bah/src/parser.bah"
nElems->types = elems->types;

#line 45 "/home/alois/Documents/bah-bah/src/parser.bah"
nElems->fns = elems->fns;

#line 47 "/home/alois/Documents/bah-bah/src/parser.bah"
return nElems;
};

#line 50 "/home/alois/Documents/bah-bah/src/parser.bah"
typedef long int lineType;

#line 52 "/home/alois/Documents/bah-bah/src/parser.bah"
#define LINE_TYPE_INCLUDE (lineType)0

#line 53 "/home/alois/Documents/bah-bah/src/parser.bah"
#define LINE_TYPE_DEFINE (lineType)1

#line 54 "/home/alois/Documents/bah-bah/src/parser.bah"
#define LINE_TYPE_CONST (lineType)2

#line 55 "/home/alois/Documents/bah-bah/src/parser.bah"
#define LINE_TYPE_VAR (lineType)3

#line 56 "/home/alois/Documents/bah-bah/src/parser.bah"
#define LINE_TYPE_FN_DECL (lineType)4

#line 57 "/home/alois/Documents/bah-bah/src/parser.bah"
#define LINE_TYPE_FN_CALL (lineType)5

#line 58 "/home/alois/Documents/bah-bah/src/parser.bah"
#define LINE_TYPE_STRUCT (lineType)6

#line 59 "/home/alois/Documents/bah-bah/src/parser.bah"
#define LINE_TYPE_CLIB (lineType)7

#line 60 "/home/alois/Documents/bah-bah/src/parser.bah"
#define LINE_TYPE_RETURN (lineType)8

#line 61 "/home/alois/Documents/bah-bah/src/parser.bah"
#define LINE_TYPE_IF (lineType)9

#line 62 "/home/alois/Documents/bah-bah/src/parser.bah"
#define LINE_TYPE_ELSE (lineType)10

#line 63 "/home/alois/Documents/bah-bah/src/parser.bah"
#define LINE_TYPE_MACRO (lineType)11

#line 64 "/home/alois/Documents/bah-bah/src/parser.bah"
#define LINE_TYPE_FOR (lineType)12

#line 65 "/home/alois/Documents/bah-bah/src/parser.bah"
#define LINE_TYPE_FOR_OPERATOR (lineType)13

#line 66 "/home/alois/Documents/bah-bah/src/parser.bah"
#define LINE_TYPE_PRE_KEYWORD (lineType)14

#line 67 "/home/alois/Documents/bah-bah/src/parser.bah"
#define LINE_TYPE_ASYNC (lineType)15

#line 68 "/home/alois/Documents/bah-bah/src/parser.bah"
#define LINE_TYPE_IMPORT (lineType)16

#line 69 "/home/alois/Documents/bah-bah/src/parser.bah"
#define LINE_TYPE_CAPTURE (lineType)17

#line 71 "/home/alois/Documents/bah-bah/src/parser.bah"
lineType prevLine;

#line 73 "/home/alois/Documents/bah-bah/src/parser.bah"

#line 1 "/home/alois/Documents/bah-bah/src/safety.bah"
void checkCanBeNull(struct Tok* t,char * tt,struct Elems* elems){

#line 2 "/home/alois/Documents/bah-bah/src/safety.bah"

                struct string ____BAH_COMPILER_VAR_600 = string(compilerState.currentDir);
                if ((isUnsafe==false)&&(string__hasPrefix(&____BAH_COMPILER_VAR_600,BAH_DIR)==false)&&isRCPpointerType(tt)&&(t->cont[0]!=38)&&(t->cont[0]!=42)) {

#line 3 "/home/alois/Documents/bah-bah/src/safety.bah"
struct variable* sv = searchVarByToken(t,elems);

#line 4 "/home/alois/Documents/bah-bah/src/safety.bah"
if ((sv!=null)) {

#line 5 "/home/alois/Documents/bah-bah/src/safety.bah"
if (__builtin_expect((sv->canBeNull==true)&&(checkedNotNull(sv->name,elems)==false), 0)) {

#line 6 "/home/alois/Documents/bah-bah/src/safety.bah"
char * globCheck = "";

#line 7 "/home/alois/Documents/bah-bah/src/safety.bah"
struct cStruct* s = searchStruct(sv->type,elems);

#line 8 "/home/alois/Documents/bah-bah/src/safety.bah"
if ((sv->isGlobal==true)&&(s!=null)) {

#line 9 "/home/alois/Documents/bah-bah/src/safety.bah"
char** ____BAH_COMPILER_VAR_601 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_601[2] = "'.";____BAH_COMPILER_VAR_601[1] = s->name;____BAH_COMPILER_VAR_601[0] = " or declare the var as 'new ";char * ____BAH_COMPILER_VAR_602 =__Bah_multiple_concat(____BAH_COMPILER_VAR_601, 3);globCheck = ____BAH_COMPILER_VAR_602;
}

#line 11 "/home/alois/Documents/bah-bah/src/safety.bah"
char** ____BAH_COMPILER_VAR_603 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_603[2] = ".";____BAH_COMPILER_VAR_603[1] = globCheck;____BAH_COMPILER_VAR_603[0] = "{TOKEN} can contain a null value. Check if the value is null";char * ____BAH_COMPILER_VAR_604 =__Bah_multiple_concat(____BAH_COMPILER_VAR_603, 3);throwErr(t,____BAH_COMPILER_VAR_604);
}
}
}
};

#line 17 "/home/alois/Documents/bah-bah/src/safety.bah"
void setNullStateBranchFlowEnd(struct Elems* elems){

#line 18 "/home/alois/Documents/bah-bah/src/safety.bah"
if ((currentFn==null)) {

#line 19 "/home/alois/Documents/bah-bah/src/safety.bah"
return;
}

#line 21 "/home/alois/Documents/bah-bah/src/safety.bah"
if ((compilerState.isBranch==false)) {

#line 22 "/home/alois/Documents/bah-bah/src/safety.bah"
if ((currentFn->couldAlreadyReturn==false)) {

#line 23 "/home/alois/Documents/bah-bah/src/safety.bah"
currentFn->exits = true;
}
}

#line 25 "/home/alois/Documents/bah-bah/src/safety.bah"
else {

#line 26 "/home/alois/Documents/bah-bah/src/safety.bah"
register long int i = 0;

#line 26 "/home/alois/Documents/bah-bah/src/safety.bah"
for (; (i<len(elems->branchChecks)); 
#line 26 "/home/alois/Documents/bah-bah/src/safety.bah"
++i) {

#line 27 "/home/alois/Documents/bah-bah/src/safety.bah"
struct varCheck bc = elems->branchChecks->data[i];

#line 28 "/home/alois/Documents/bah-bah/src/safety.bah"
if ((bc.v==null)) {

#line 29 "/home/alois/Documents/bah-bah/src/safety.bah"
continue;
}

#line 31 "/home/alois/Documents/bah-bah/src/safety.bah"
if ((bc.checkNull==true)) {

#line 32 "/home/alois/Documents/bah-bah/src/safety.bah"
register long int j = 0;

#line 32 "/home/alois/Documents/bah-bah/src/safety.bah"
for (; (j<len(elems->parent->vars)); 
#line 32 "/home/alois/Documents/bah-bah/src/safety.bah"
++j) {

#line 33 "/home/alois/Documents/bah-bah/src/safety.bah"
struct variable* pv = elems->parent->vars->data[j];

#line 34 "/home/alois/Documents/bah-bah/src/safety.bah"
if ((strcmp(pv->name, bc.v->name) == 0)) {

#line 35 "/home/alois/Documents/bah-bah/src/safety.bah"
pv->canBeNull = false;

#line 36 "/home/alois/Documents/bah-bah/src/safety.bah"
break;
}
};
}
};

#line 41 "/home/alois/Documents/bah-bah/src/safety.bah"
if ((prevLine==LINE_TYPE_IF)&&(prevIfExits==true)) {

#line 42 "/home/alois/Documents/bah-bah/src/safety.bah"
struct Elems* currElems = elems;

#line 42 "/home/alois/Documents/bah-bah/src/safety.bah"
for (; (currElems!=null); 
#line 42 "/home/alois/Documents/bah-bah/src/safety.bah"
currElems = currElems->parent) {

#line 43 "/home/alois/Documents/bah-bah/src/safety.bah"
i = 0;

#line 43 "/home/alois/Documents/bah-bah/src/safety.bah"
for (; (i<len(currElems->branchChecks)); 
#line 43 "/home/alois/Documents/bah-bah/src/safety.bah"
++i) {

#line 44 "/home/alois/Documents/bah-bah/src/safety.bah"
struct varCheck bc = currElems->branchChecks->data[i];

#line 45 "/home/alois/Documents/bah-bah/src/safety.bah"
if ((bc.v==null)) {

#line 46 "/home/alois/Documents/bah-bah/src/safety.bah"
continue;
}

#line 48 "/home/alois/Documents/bah-bah/src/safety.bah"
if ((bc.checkNull==true)) {

#line 49 "/home/alois/Documents/bah-bah/src/safety.bah"
register long int j = 0;

#line 49 "/home/alois/Documents/bah-bah/src/safety.bah"
for (; (j<len(currElems->parent->vars)); 
#line 49 "/home/alois/Documents/bah-bah/src/safety.bah"
++j) {

#line 50 "/home/alois/Documents/bah-bah/src/safety.bah"
struct variable* pv = currElems->parent->vars->data[j];

#line 51 "/home/alois/Documents/bah-bah/src/safety.bah"
if ((strcmp(pv->name, bc.v->name) == 0)) {

#line 52 "/home/alois/Documents/bah-bah/src/safety.bah"
pv->canBeNull = false;

#line 53 "/home/alois/Documents/bah-bah/src/safety.bah"
break;
}
};
}
};
};
}

#line 60 "/home/alois/Documents/bah-bah/src/safety.bah"
prevIfExits = true;
}
};

#line 64 "/home/alois/Documents/bah-bah/src/safety.bah"
char fixMeEnabled(){

#line 65 "/home/alois/Documents/bah-bah/src/safety.bah"
if ((isFixMeEnabled==false)) {

#line 66 "/home/alois/Documents/bah-bah/src/safety.bah"
return false;
}

#line 68 "/home/alois/Documents/bah-bah/src/safety.bah"
return (isInside(BAH_DIR,compilerState.currentDir)==false);
};

#line 71 "/home/alois/Documents/bah-bah/src/safety.bah"
void fixMeRegisterVar(struct variable* v,struct Tok* t){

#line 72 "/home/alois/Documents/bah-bah/src/safety.bah"
if ((v->isReg==true)) {

#line 73 "/home/alois/Documents/bah-bah/src/safety.bah"
return;
}

#line 75 "/home/alois/Documents/bah-bah/src/safety.bah"
char * name = v->name;

#line 76 "/home/alois/Documents/bah-bah/src/safety.bah"
if ((isRCPpointerType(v->type)==false)) {

#line 77 "/home/alois/Documents/bah-bah/src/safety.bah"
char** ____BAH_COMPILER_VAR_605 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_605[1] = name;____BAH_COMPILER_VAR_605[0] = "&";char * ____BAH_COMPILER_VAR_606 =__Bah_multiple_concat(____BAH_COMPILER_VAR_605, 2);name = ____BAH_COMPILER_VAR_606;
}

#line 79 "/home/alois/Documents/bah-bah/src/safety.bah"
char** ____BAH_COMPILER_VAR_607 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_607[8] = "\");\n    ";____BAH_COMPILER_VAR_607[7] = intToStr(t->line);____BAH_COMPILER_VAR_607[6] = ":";____BAH_COMPILER_VAR_607[5] = compilerState.currentFile;____BAH_COMPILER_VAR_607[4] = ", \"";____BAH_COMPILER_VAR_607[3] = name;____BAH_COMPILER_VAR_607[2] = "\", ";____BAH_COMPILER_VAR_607[1] = v->name;____BAH_COMPILER_VAR_607[0] = "\n    fixMeAddVar(\"";char * ____BAH_COMPILER_VAR_608 =__Bah_multiple_concat(____BAH_COMPILER_VAR_607, 9);char** ____BAH_COMPILER_VAR_609 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_609[1] = ____BAH_COMPILER_VAR_608;____BAH_COMPILER_VAR_609[0] = NEXT_LINE;char * ____BAH_COMPILER_VAR_610 =__Bah_multiple_concat(____BAH_COMPILER_VAR_609, 2);NEXT_LINE = ____BAH_COMPILER_VAR_610;
};

#line 84 "/home/alois/Documents/bah-bah/src/safety.bah"
void fixMeEndScope(struct Elems* elems,struct Tok* t){

#line 85 "/home/alois/Documents/bah-bah/src/safety.bah"
if ((fixMeEnabled()==false)) {

#line 86 "/home/alois/Documents/bah-bah/src/safety.bah"
return;
}

#line 88 "/home/alois/Documents/bah-bah/src/safety.bah"
register long int i = 0;

#line 88 "/home/alois/Documents/bah-bah/src/safety.bah"
for (; (i<len(elems->vars)); 
#line 88 "/home/alois/Documents/bah-bah/src/safety.bah"
++i) {

#line 89 "/home/alois/Documents/bah-bah/src/safety.bah"
struct variable* v = elems->vars->data[i];

#line 90 "/home/alois/Documents/bah-bah/src/safety.bah"
if ((v->declScope==elems)) {

#line 91 "/home/alois/Documents/bah-bah/src/safety.bah"
if ((v->isReg==true)) {

#line 92 "/home/alois/Documents/bah-bah/src/safety.bah"
return;
}

#line 94 "/home/alois/Documents/bah-bah/src/safety.bah"
char * name = v->name;

#line 95 "/home/alois/Documents/bah-bah/src/safety.bah"
if ((isRCPpointerType(v->type)==false)) {

#line 96 "/home/alois/Documents/bah-bah/src/safety.bah"
char** ____BAH_COMPILER_VAR_611 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_611[1] = name;____BAH_COMPILER_VAR_611[0] = "&";char * ____BAH_COMPILER_VAR_612 =__Bah_multiple_concat(____BAH_COMPILER_VAR_611, 2);name = ____BAH_COMPILER_VAR_612;
}

#line 97 "/home/alois/Documents/bah-bah/src/safety.bah"
else {

#line 98 "/home/alois/Documents/bah-bah/src/safety.bah"
continue;
}

#line 100 "/home/alois/Documents/bah-bah/src/safety.bah"
char** ____BAH_COMPILER_VAR_613 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_613[8] = "\");\n            ";____BAH_COMPILER_VAR_613[7] = intToStr(t->line);____BAH_COMPILER_VAR_613[6] = ":";____BAH_COMPILER_VAR_613[5] = compilerState.currentFile;____BAH_COMPILER_VAR_613[4] = ", \"";____BAH_COMPILER_VAR_613[3] = name;____BAH_COMPILER_VAR_613[2] = "\", ";____BAH_COMPILER_VAR_613[1] = v->name;____BAH_COMPILER_VAR_613[0] = "\n            fixMeRemVar(\"";char * ____BAH_COMPILER_VAR_614 =__Bah_multiple_concat(____BAH_COMPILER_VAR_613, 9);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_614));
}
};
};

#line 107 "/home/alois/Documents/bah-bah/src/safety.bah"
void fixMeTestVar(struct Tok* t,lineType ltp,struct Elems* elems){

#line 108 "/home/alois/Documents/bah-bah/src/safety.bah"
if ((fixMeEnabled()==false)) {

#line 109 "/home/alois/Documents/bah-bah/src/safety.bah"
return;
}

#line 113 "/home/alois/Documents/bah-bah/src/safety.bah"
char * name = t->cont;

#line 114 "/home/alois/Documents/bah-bah/src/safety.bah"
char * tt = getTypeFromToken(t,true,elems);

#line 115 "/home/alois/Documents/bah-bah/src/safety.bah"
if ((isRCPtype(tt,elems)==false)) {

#line 116 "/home/alois/Documents/bah-bah/src/safety.bah"
return;
}

#line 118 "/home/alois/Documents/bah-bah/src/safety.bah"
if ((isRCPpointerType(tt)==false)) {

#line 119 "/home/alois/Documents/bah-bah/src/safety.bah"
if ((name[0]==42)) {

#line 120 "/home/alois/Documents/bah-bah/src/safety.bah"
name = cpstringSubsitute(name, 1, strlen(name));
}

#line 121 "/home/alois/Documents/bah-bah/src/safety.bah"
else {

#line 122 "/home/alois/Documents/bah-bah/src/safety.bah"
char** ____BAH_COMPILER_VAR_615 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_615[1] = name;____BAH_COMPILER_VAR_615[0] = "&";char * ____BAH_COMPILER_VAR_616 =__Bah_multiple_concat(____BAH_COMPILER_VAR_615, 2);name = ____BAH_COMPILER_VAR_616;
}
}

#line 126 "/home/alois/Documents/bah-bah/src/safety.bah"
if ((t->type==TOKEN_TYPE_FUNC)||(t->isOper==true)||(t->isFunc==true)) {

#line 127 "/home/alois/Documents/bah-bah/src/safety.bah"
name = registerRCPvar(tt,t->cont,elems);

#line 128 "/home/alois/Documents/bah-bah/src/safety.bah"
t->cont = name;
}

#line 131 "/home/alois/Documents/bah-bah/src/safety.bah"
char** ____BAH_COMPILER_VAR_617 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_617[8] = "\")";____BAH_COMPILER_VAR_617[7] = intToStr(t->line);____BAH_COMPILER_VAR_617[6] = ":";____BAH_COMPILER_VAR_617[5] = compilerState.currentFile;____BAH_COMPILER_VAR_617[4] = "\", \"";____BAH_COMPILER_VAR_617[3] = t->cont;____BAH_COMPILER_VAR_617[2] = ", \"";____BAH_COMPILER_VAR_617[1] = name;____BAH_COMPILER_VAR_617[0] = "fixMeIsVarOk(";char * ____BAH_COMPILER_VAR_618 =__Bah_multiple_concat(____BAH_COMPILER_VAR_617, 9);char * fn = ____BAH_COMPILER_VAR_618;

#line 133 "/home/alois/Documents/bah-bah/src/safety.bah"
if ((ltp==LINE_TYPE_ELSE)) {

#line 134 "/home/alois/Documents/bah-bah/src/safety.bah"
char** ____BAH_COMPILER_VAR_619 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_619[1] = "&&";____BAH_COMPILER_VAR_619[0] = fn;char * ____BAH_COMPILER_VAR_620 =__Bah_multiple_concat(____BAH_COMPILER_VAR_619, 2);prevIfShortcut = ____BAH_COMPILER_VAR_620;

#line 135 "/home/alois/Documents/bah-bah/src/safety.bah"
return;
}

#line 138 "/home/alois/Documents/bah-bah/src/safety.bah"
char** ____BAH_COMPILER_VAR_621 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_621[1] = ";\n";____BAH_COMPILER_VAR_621[0] = fn;char * ____BAH_COMPILER_VAR_622 =__Bah_multiple_concat(____BAH_COMPILER_VAR_621, 2);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_622));
};

#line 141 "/home/alois/Documents/bah-bah/src/safety.bah"
char isStaticToken(struct Tok* t,struct Elems* elems){

#line 142 "/home/alois/Documents/bah-bah/src/safety.bah"
if ((t->type==TOKEN_TYPE_BOOL)&&((strcmp(t->cont, "true") != 0)||(strcmp(t->cont, "false") != 0))) {

#line 143 "/home/alois/Documents/bah-bah/src/safety.bah"
return false;
}

#line 146 "/home/alois/Documents/bah-bah/src/safety.bah"
if ((t->type==TOKEN_TYPE_FUNC)) {

#line 147 "/home/alois/Documents/bah-bah/src/safety.bah"
return false;
}

#line 150 "/home/alois/Documents/bah-bah/src/safety.bah"
if ((t->type==TOKEN_TYPE_VAR)) {

#line 151 "/home/alois/Documents/bah-bah/src/safety.bah"
if ((t->isOper==true)) {

#line 152 "/home/alois/Documents/bah-bah/src/safety.bah"
return false;
}

#line 154 "/home/alois/Documents/bah-bah/src/safety.bah"
struct variable* v = searchVirtVarByToken(t,elems);

#line 155 "/home/alois/Documents/bah-bah/src/safety.bah"
if ((v!=null)) {

#line 156 "/home/alois/Documents/bah-bah/src/safety.bah"
return v->isConst;
}
}

#line 160 "/home/alois/Documents/bah-bah/src/safety.bah"
return true;
};

#line 77 "/home/alois/Documents/bah-bah/src/parser.bah"
lineType getLineType(__BAH_ARR_TYPE_Tok line){

#line 79 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok ft = line->data[0];

#line 81 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((ft.type==TOKEN_TYPE_FUNC)) {

#line 82 "/home/alois/Documents/bah-bah/src/parser.bah"
return LINE_TYPE_FN_CALL;
}

#line 84 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((ft.type==TOKEN_TYPE_KEYWORD)) {

#line 85 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(ft.cont, "#include") == 0)) {

#line 86 "/home/alois/Documents/bah-bah/src/parser.bah"
return LINE_TYPE_INCLUDE;
}

#line 87 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "#import") == 0)) {

#line 88 "/home/alois/Documents/bah-bah/src/parser.bah"
return LINE_TYPE_IMPORT;
}

#line 89 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "#define") == 0)) {

#line 90 "/home/alois/Documents/bah-bah/src/parser.bah"
return LINE_TYPE_DEFINE;
}

#line 91 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "const") == 0)) {

#line 92 "/home/alois/Documents/bah-bah/src/parser.bah"
return LINE_TYPE_CONST;
}

#line 93 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "struct") == 0)) {

#line 94 "/home/alois/Documents/bah-bah/src/parser.bah"
return LINE_TYPE_STRUCT;
}

#line 95 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "#cLib") == 0)) {

#line 96 "/home/alois/Documents/bah-bah/src/parser.bah"
return LINE_TYPE_CLIB;
}

#line 97 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "return") == 0)) {

#line 98 "/home/alois/Documents/bah-bah/src/parser.bah"
return LINE_TYPE_RETURN;
}

#line 99 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "if") == 0)) {

#line 100 "/home/alois/Documents/bah-bah/src/parser.bah"
return LINE_TYPE_IF;
}

#line 101 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "else") == 0)) {

#line 102 "/home/alois/Documents/bah-bah/src/parser.bah"
return LINE_TYPE_ELSE;
}

#line 103 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "#macro") == 0)) {

#line 104 "/home/alois/Documents/bah-bah/src/parser.bah"
return LINE_TYPE_MACRO;
}

#line 105 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "for") == 0)) {

#line 106 "/home/alois/Documents/bah-bah/src/parser.bah"
return LINE_TYPE_FOR;
}

#line 107 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "async") == 0)) {

#line 108 "/home/alois/Documents/bah-bah/src/parser.bah"
return LINE_TYPE_ASYNC;
}

#line 109 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "continue") == 0)||(strcmp(ft.cont, "break") == 0)) {

#line 110 "/home/alois/Documents/bah-bah/src/parser.bah"
return LINE_TYPE_FOR_OPERATOR;
}

#line 111 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "capture") == 0)) {

#line 112 "/home/alois/Documents/bah-bah/src/parser.bah"
return LINE_TYPE_CAPTURE;
}

#line 113 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 114 "/home/alois/Documents/bah-bah/src/parser.bah"
return LINE_TYPE_PRE_KEYWORD;
}
}

#line 116 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((ft.type==TOKEN_TYPE_VAR)) {

#line 117 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((len(line)>1)) {

#line 118 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok st = line->data[1];

#line 119 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((st.type==TOKEN_TYPE_ENCL)&&(strcmp(st.cont, "(") == 0)) {

#line 120 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok lt = line->data[len(line)-1];

#line 121 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((lt.type==TOKEN_TYPE_ENCL)&&(strcmp(lt.cont, "}") == 0)) {

#line 122 "/home/alois/Documents/bah-bah/src/parser.bah"
return LINE_TYPE_FN_DECL;
}

#line 124 "/home/alois/Documents/bah-bah/src/parser.bah"
return LINE_TYPE_FN_CALL;
}
}

#line 128 "/home/alois/Documents/bah-bah/src/parser.bah"
return LINE_TYPE_VAR;
}

#line 131 "/home/alois/Documents/bah-bah/src/parser.bah"
return (lineType)-1;
};

#line 135 "/home/alois/Documents/bah-bah/src/parser.bah"
__BAH_ARR_TYPE_Tok parseCast(__BAH_ARR_TYPE_Tok line,struct Elems* elems,char guard){

#line 138 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);

#line 139 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int i = 0;

#line 140 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((guard==true)) {

#line 141 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i<len(line))) {

#line 142 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = line->data[i];

#line 143 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((t.type==TOKEN_TYPE_CAST)) {

#line 144 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}

#line 146 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_623 = i;
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_623);
    nl->data[____BAH_COMPILER_VAR_623] = t;

#line 147 "/home/alois/Documents/bah-bah/src/parser.bah"
i = i+1;
};

#line 149 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((i==len(line))) {

#line 150 "/home/alois/Documents/bah-bah/src/parser.bah"
return line;
}
}

#line 154 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<len(line)); 
#line 154 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 155 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = line->data[i];

#line 156 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((t.type==TOKEN_TYPE_CAST)) {

#line 157 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((i+1<len(line))) {

#line 158 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok nnnt = line->data[i+1];

#line 160 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string tc = string(t.cont);

#line 161 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimLeft(&tc,1);

#line 162 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimRight(&tc,1);

#line 163 "/home/alois/Documents/bah-bah/src/parser.bah"
nnnt.bahType = string__str(&tc);

#line 164 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ____BAH_COMPILER_VAR_624 =string__str(&tc);struct string cCast = getCType(____BAH_COMPILER_VAR_624,elems);

#line 165 "/home/alois/Documents/bah-bah/src/parser.bah"
char * cCastStr = string__str(&cCast);

#line 166 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_625 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_625[3] = nnnt.cont;____BAH_COMPILER_VAR_625[2] = ")";____BAH_COMPILER_VAR_625[1] = cCastStr;____BAH_COMPILER_VAR_625[0] = "(";char * ____BAH_COMPILER_VAR_626 =__Bah_multiple_concat(____BAH_COMPILER_VAR_625, 4);nnnt.cont = ____BAH_COMPILER_VAR_626;

#line 167 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_627 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_627);
    nl->data[____BAH_COMPILER_VAR_627] = nnnt;

#line 168 "/home/alois/Documents/bah-bah/src/parser.bah"
i = i+2;

#line 169 "/home/alois/Documents/bah-bah/src/parser.bah"
continue;
}
}

#line 173 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_628 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_628);
    nl->data[____BAH_COMPILER_VAR_628] = t;
};

#line 176 "/home/alois/Documents/bah-bah/src/parser.bah"
return nl;
};

#line 179 "/home/alois/Documents/bah-bah/src/parser.bah"
char * getDirFromFile(char * f){

#line 180 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ____BAH_COMPILER_VAR_629 =__STR(f);array(char)* p = strAsArr(____BAH_COMPILER_VAR_629);

#line 181 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int i = len(p)-1;

#line 181 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i>=0)) {

#line 182 "/home/alois/Documents/bah-bah/src/parser.bah"
char c = p->data[i];

#line 183 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((c==47)) {

#line 184 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_630 = i+1;
    __Bah_realocate_arr(p, ____BAH_COMPILER_VAR_630);
    p->data[____BAH_COMPILER_VAR_630] = (char)0;

#line 185 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}

#line 187 "/home/alois/Documents/bah-bah/src/parser.bah"
i = i-1;
};

#line 190 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((i<=0)) {

#line 191 "/home/alois/Documents/bah-bah/src/parser.bah"
return "";
}

#line 194 "/home/alois/Documents/bah-bah/src/parser.bah"
return arrAsStr(p);
};

#line 197 "/home/alois/Documents/bah-bah/src/parser.bah"
void parseLines(__BAH_ARR_TYPE_Tok ts,struct Elems* elems);

#line 198 "/home/alois/Documents/bah-bah/src/parser.bah"
char ____BAH_COMPILER_VAR_631(array(char *)* arr, char * el) {
        if (arr == 0) {
            return 0;
        };
        for(int i=arr->length-1; i!=-1;i--) {
            if (arr->data[i] != 0 && strcmp(arr->data[i], el) == 0) {
                return 1;
            };
        }
        return 0;
        }
char includeFile(char * ccstr,struct Elems* elems){

#line 200 "/home/alois/Documents/bah-bah/src/parser.bah"
char needDisableRCP = false;

#line 203 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(ccstr, "BAH_MEM_COLLECTOR") == 0)) {

#line 204 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((RAIIenabled==true)) {

#line 205 "/home/alois/Documents/bah-bah/src/parser.bah"
ccstr = "raii.bah";
}

#line 206 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((RCPenabled==true)) {

#line 207 "/home/alois/Documents/bah-bah/src/parser.bah"
needDisableRCP = true;

#line 208 "/home/alois/Documents/bah-bah/src/parser.bah"
if (flags__isSet(&flags,"rcp")) {

#line 209 "/home/alois/Documents/bah-bah/src/parser.bah"
ccstr = "rcp.bah";
}

#line 210 "/home/alois/Documents/bah-bah/src/parser.bah"
else if (flags__isSet(&flags,"fastrcp")) {

#line 211 "/home/alois/Documents/bah-bah/src/parser.bah"
ccstr = "fastrcp.bah";
}
}

#line 213 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 214 "/home/alois/Documents/bah-bah/src/parser.bah"
ccstr = "gc.bah";
}
}

#line 219 "/home/alois/Documents/bah-bah/src/parser.bah"
if (____BAH_COMPILER_VAR_631(compilerState.includes, ccstr)) {

#line 220 "/home/alois/Documents/bah-bah/src/parser.bah"
return true;
}

#line 224 "/home/alois/Documents/bah-bah/src/parser.bah"
struct fileMap ____BAH_COMPILER_VAR_632 = {};
____BAH_COMPILER_VAR_632.handle = -1;
struct fileMap fm = ____BAH_COMPILER_VAR_632;

#line 225 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_633 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_633[1] = ccstr;____BAH_COMPILER_VAR_633[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_634 =__Bah_multiple_concat(____BAH_COMPILER_VAR_633, 2);char * fileName = ____BAH_COMPILER_VAR_634;

#line 226 "/home/alois/Documents/bah-bah/src/parser.bah"
char isBahDir = true;

#line 227 "/home/alois/Documents/bah-bah/src/parser.bah"
char * f = fileMap__open(&fm,fileName);

#line 228 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((fileMap__isValid(&fm)==0)) {

#line 229 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_635 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_635[1] = ccstr;____BAH_COMPILER_VAR_635[0] = compilerState.currentDir;char * ____BAH_COMPILER_VAR_636 =__Bah_multiple_concat(____BAH_COMPILER_VAR_635, 2);fileName = absPath(____BAH_COMPILER_VAR_636);

#line 230 "/home/alois/Documents/bah-bah/src/parser.bah"
f = fileMap__open(&fm,fileName);

#line 231 "/home/alois/Documents/bah-bah/src/parser.bah"
isBahDir = false;

#line 232 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((fileMap__isValid(&fm)==0)) {

#line 233 "/home/alois/Documents/bah-bah/src/parser.bah"
return false;
}
}

#line 238 "/home/alois/Documents/bah-bah/src/parser.bah"
char * oDir = compilerState.currentDir;

#line 239 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((isBahDir==false)) {

#line 240 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_637 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_637[1] = getDirFromFile(ccstr);____BAH_COMPILER_VAR_637[0] = compilerState.currentDir;char * ____BAH_COMPILER_VAR_638 =__Bah_multiple_concat(____BAH_COMPILER_VAR_637, 2);compilerState.currentDir = ____BAH_COMPILER_VAR_638;
}

#line 241 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 242 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_639 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_639[1] = getDirFromFile(ccstr);____BAH_COMPILER_VAR_639[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_640 =__Bah_multiple_concat(____BAH_COMPILER_VAR_639, 2);compilerState.currentDir = ____BAH_COMPILER_VAR_640;
}

#line 246 "/home/alois/Documents/bah-bah/src/parser.bah"
char * oFile = compilerState.currentFile;

#line 247 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.currentFile = fileName;

#line 248 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_641 = len(compilerState.includes);
    __Bah_realocate_arr(compilerState.includes, ____BAH_COMPILER_VAR_641);
    compilerState.includes->data[____BAH_COMPILER_VAR_641] = ccstr;

#line 251 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct Tok)* tokens = lexer(f,fm.size);

#line 252 "/home/alois/Documents/bah-bah/src/parser.bah"
fileMap__close(&fm);

#line 253 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((len(tokens)==0), 0)) {

#line 254 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_642 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_642[2] = "' not recognized.";____BAH_COMPILER_VAR_642[1] = ccstr;____BAH_COMPILER_VAR_642[0] = "File '";char * ____BAH_COMPILER_VAR_643 =__Bah_multiple_concat(____BAH_COMPILER_VAR_642, 3);__BAH_panic(____BAH_COMPILER_VAR_643,"/home/alois/Documents/bah-bah/src/parser.bah:254");
}

#line 258 "/home/alois/Documents/bah-bah/src/parser.bah"
char oshd = shouldOnlyDecl;

#line 259 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((isObject==true)) {

#line 260 "/home/alois/Documents/bah-bah/src/parser.bah"

                struct string ____BAH_COMPILER_VAR_644 = string(compilerState.currentFile);
                if ((isBahDir==true)||(string__hasPrefix(&____BAH_COMPILER_VAR_644,oDir)==false)) {

#line 261 "/home/alois/Documents/bah-bah/src/parser.bah"
shouldOnlyDecl = true;
}

#line 262 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 263 "/home/alois/Documents/bah-bah/src/parser.bah"
shouldOnlyDecl = false;
}
}

#line 265 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((isSubObject==true)) {

#line 266 "/home/alois/Documents/bah-bah/src/parser.bah"

                struct string ____BAH_COMPILER_VAR_645 = string(compilerState.currentFile);
                if ((isBahDir==true)||(string__hasPrefix(&____BAH_COMPILER_VAR_645,oDir)==false)) {

#line 267 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((isImportedSubObject==true)&&(isBahDir==false)) {

#line 268 "/home/alois/Documents/bah-bah/src/parser.bah"
shouldOnlyDecl = true;
}

#line 269 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 270 "/home/alois/Documents/bah-bah/src/parser.bah"
shouldOnlyDecl = false;
}
}

#line 272 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 273 "/home/alois/Documents/bah-bah/src/parser.bah"
shouldOnlyDecl = true;
}
}

#line 277 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((needDisableRCP==true)) {

#line 278 "/home/alois/Documents/bah-bah/src/parser.bah"
RCPenabled = false;
}

#line 281 "/home/alois/Documents/bah-bah/src/parser.bah"
parseLines(tokens,elems);

#line 283 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((needDisableRCP==true)) {

#line 284 "/home/alois/Documents/bah-bah/src/parser.bah"
RCPenabled = true;
}

#line 288 "/home/alois/Documents/bah-bah/src/parser.bah"
shouldOnlyDecl = oshd;

#line 289 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.currentFile = oFile;

#line 290 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.currentDir = oDir;

#line 292 "/home/alois/Documents/bah-bah/src/parser.bah"
return true;
};

#line 295 "/home/alois/Documents/bah-bah/src/parser.bah"
void parallelObjCompile(char * fn,char * oName,struct channel * done){

#line 296 "/home/alois/Documents/bah-bah/src/parser.bah"
readCache();

#line 297 "/home/alois/Documents/bah-bah/src/parser.bah"
struct cacheFile* cf = getCacheFile(fn);

#line 298 "/home/alois/Documents/bah-bah/src/parser.bah"
char * wrkd = getCurrentPath();

#line 300 "/home/alois/Documents/bah-bah/src/parser.bah"
char * rcp = "";

#line 301 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((RCPlevel==1)) {

#line 302 "/home/alois/Documents/bah-bah/src/parser.bah"
rcp = "-rcp";
}

#line 303 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((RCPlevel==2)) {

#line 304 "/home/alois/Documents/bah-bah/src/parser.bah"
rcp = "-fastrcp";
}

#line 307 "/home/alois/Documents/bah-bah/src/parser.bah"
struct cacheFile* scf = cf;

#line 308 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((scf==null)) {

#line 309 "/home/alois/Documents/bah-bah/src/parser.bah"
struct cacheFile* ____BAH_COMPILER_VAR_646 = memoryAlloc(sizeof(struct cacheFile));
____BAH_COMPILER_VAR_646->files = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_646->files->length = 0;
            ____BAH_COMPILER_VAR_646->files->elemSize = sizeof(char *);
            scf = ____BAH_COMPILER_VAR_646;
}

#line 313 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((cf==null)||(isValidCacheFile(scf)==false)) {

#line 314 "/home/alois/Documents/bah-bah/src/parser.bah"
setCurrentPath(compilerState.currentDir);

#line 315 "/home/alois/Documents/bah-bah/src/parser.bah"
char * verboseCC = "";

#line 316 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((flags__isSet(&flags,"verboseCC")==1)) {

#line 317 "/home/alois/Documents/bah-bah/src/parser.bah"
verboseCC = "-verboseCC";
}

#line 319 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((debug==false)) {

#line 320 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_647 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_647[1] = fn;____BAH_COMPILER_VAR_647[0] = "[compiling] ";char * ____BAH_COMPILER_VAR_648 =__Bah_multiple_concat(____BAH_COMPILER_VAR_647, 2);println(____BAH_COMPILER_VAR_648);
}

#line 322 "/home/alois/Documents/bah-bah/src/parser.bah"
char * opti = "";

#line 323 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((isOptimized==true)) {

#line 324 "/home/alois/Documents/bah-bah/src/parser.bah"
opti = "-optimize";
}

#line 326 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_649 = alloca(11 * sizeof(char*));____BAH_COMPILER_VAR_649[10] = oName;____BAH_COMPILER_VAR_649[9] = " -o ";____BAH_COMPILER_VAR_649[8] = verboseCC;____BAH_COMPILER_VAR_649[7] = " -object ";____BAH_COMPILER_VAR_649[6] = opti;____BAH_COMPILER_VAR_649[5] = " ";____BAH_COMPILER_VAR_649[4] = rcp;____BAH_COMPILER_VAR_649[3] = " ";____BAH_COMPILER_VAR_649[2] = fn;____BAH_COMPILER_VAR_649[1] = " ";____BAH_COMPILER_VAR_649[0] = execName;char * ____BAH_COMPILER_VAR_650 =__Bah_multiple_concat(____BAH_COMPILER_VAR_649, 11);struct command cmd = command(____BAH_COMPILER_VAR_650);

#line 327 "/home/alois/Documents/bah-bah/src/parser.bah"
array(char)* res = command__runBytes(&cmd);

#line 328 "/home/alois/Documents/bah-bah/src/parser.bah"
setCurrentPath(wrkd);

#line 329 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((cmd.status!=0), 0)) {

#line 330 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ____BAH_COMPILER_VAR_651 =arrToStr(res);print(____BAH_COMPILER_VAR_651);

#line 331 "/home/alois/Documents/bah-bah/src/parser.bah"
exit(1);
}

#line 333 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((cf==null)) {

#line 334 "/home/alois/Documents/bah-bah/src/parser.bah"
makeCacheFile(fn);
}

#line 335 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 336 "/home/alois/Documents/bah-bah/src/parser.bah"
updateCacheFile(cf);
}

#line 338 "/home/alois/Documents/bah-bah/src/parser.bah"
writeCache();
}

#line 340 "/home/alois/Documents/bah-bah/src/parser.bah"

        char ____BAH_COMPILER_VAR_652 = true;
        channel__sendAny(done, &____BAH_COMPILER_VAR_652, sizeof(____BAH_COMPILER_VAR_652));
        };

#line 343 "/home/alois/Documents/bah-bah/src/parser.bah"
char ____BAH_COMPILER_VAR_653(array(char *)* arr, char * el) {
        if (arr == 0) {
            return 0;
        };
        for(int i=arr->length-1; i!=-1;i--) {
            if (arr->data[i] != 0 && strcmp(arr->data[i], el) == 0) {
                return 1;
            };
        }
        return 0;
        }
void parseImport(__BAH_ARR_TYPE_Tok l,struct Elems* elems){

#line 344 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.hasImports = true;

#line 346 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((len(l)!=2), 0)) {

#line 347 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&l->data[0],"Invalid usage of {TOKEN}.");
}

#line 349 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok strt = l->data[1];

#line 350 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((strt.type!=TOKEN_TYPE_STR), 0)) {

#line 351 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&strt,"Cannot use {TOKEN} as file name (#import \"file\")");
}

#line 355 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string fileName = string(strt.cont);

#line 356 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimLeft(&fileName,1);

#line 357 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimRight(&fileName,1);

#line 360 "/home/alois/Documents/bah-bah/src/parser.bah"
if (____BAH_COMPILER_VAR_653(compilerState.includes, string__str(&fileName))) {

#line 361 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}

#line 363 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_654 = len(compilerState.includes);
    __Bah_realocate_arr(compilerState.includes, ____BAH_COMPILER_VAR_654);
    compilerState.includes->data[____BAH_COMPILER_VAR_654] = string__str(&fileName);

#line 366 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_655 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_655[1] = string__str(&fileName);____BAH_COMPILER_VAR_655[0] = compilerState.currentDir;char * ____BAH_COMPILER_VAR_656 =__Bah_multiple_concat(____BAH_COMPILER_VAR_655, 2);char * fn = absPath(____BAH_COMPILER_VAR_656);

#line 367 "/home/alois/Documents/bah-bah/src/parser.bah"
if (((void *)fn==null)) {

#line 368 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_657 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_657[1] = string__str(&fileName);____BAH_COMPILER_VAR_657[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_658 =__Bah_multiple_concat(____BAH_COMPILER_VAR_657, 2);fn = absPath(____BAH_COMPILER_VAR_658);

#line 369 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect(((void *)fn==null), 0)) {

#line 370 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&strt,"Unknown file {TOKEN}.");
}
}

#line 375 "/home/alois/Documents/bah-bah/src/parser.bah"
char * of = compilerState.currentFile;

#line 376 "/home/alois/Documents/bah-bah/src/parser.bah"
char * od = compilerState.currentDir;

#line 377 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.currentFile = fn;

#line 378 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.currentDir = getDirFromFile(fn);

#line 381 "/home/alois/Documents/bah-bah/src/parser.bah"
struct fileStream ____BAH_COMPILER_VAR_659 = {};
struct fileStream fs = ____BAH_COMPILER_VAR_659;

#line 382 "/home/alois/Documents/bah-bah/src/parser.bah"
fileStream__open(&fs,fn,"r");

#line 383 "/home/alois/Documents/bah-bah/src/parser.bah"
char * f = fileStream__readContent(&fs);

#line 386 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct Tok)* tokens = lexer(f,fileStream__getSize(&fs));

#line 387 "/home/alois/Documents/bah-bah/src/parser.bah"
fileStream__close(&fs);

#line 390 "/home/alois/Documents/bah-bah/src/parser.bah"
char osod = shouldOnlyDecl;

#line 391 "/home/alois/Documents/bah-bah/src/parser.bah"
char oiso = isSubObject;

#line 392 "/home/alois/Documents/bah-bah/src/parser.bah"
char oiiso = isImportedSubObject;

#line 394 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((isSubObject==true)) {

#line 395 "/home/alois/Documents/bah-bah/src/parser.bah"
isImportedSubObject = true;
}

#line 398 "/home/alois/Documents/bah-bah/src/parser.bah"
shouldOnlyDecl = true;

#line 399 "/home/alois/Documents/bah-bah/src/parser.bah"
isSubObject = true;

#line 401 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_660 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_660[5] = ".o";____BAH_COMPILER_VAR_660[4] = intToStr(isOptimized);____BAH_COMPILER_VAR_660[3] = intToStr(RCPlevel);____BAH_COMPILER_VAR_660[2] = pathToVarName(fn);____BAH_COMPILER_VAR_660[1] = "cache/";____BAH_COMPILER_VAR_660[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_661 =__Bah_multiple_concat(____BAH_COMPILER_VAR_660, 6);char * oName = ____BAH_COMPILER_VAR_661;

#line 403 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int i = len(compilerState.cLibs);

#line 403 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i!=0); 
#line 403 "/home/alois/Documents/bah-bah/src/parser.bah"
--i) {

#line 404 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_662 = i;
    __Bah_realocate_arr(compilerState.cLibs, ____BAH_COMPILER_VAR_662);
    compilerState.cLibs->data[____BAH_COMPILER_VAR_662] = compilerState.cLibs->data[i-1];
};

#line 407 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_663 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_663[2] = ".o";____BAH_COMPILER_VAR_663[1] = oName;____BAH_COMPILER_VAR_663[0] = "w ";char * ____BAH_COMPILER_VAR_664 =__Bah_multiple_concat(____BAH_COMPILER_VAR_663, 3);
    unsigned int ____BAH_COMPILER_VAR_665 = 0;
    __Bah_realocate_arr(compilerState.cLibs, ____BAH_COMPILER_VAR_665);
    compilerState.cLibs->data[____BAH_COMPILER_VAR_665] = ____BAH_COMPILER_VAR_664;

#line 409 "/home/alois/Documents/bah-bah/src/parser.bah"
struct channel * done = channel();

#line 412 "/home/alois/Documents/bah-bah/src/parser.bah"
parallelObjCompile(fn,oName,done);

#line 415 "/home/alois/Documents/bah-bah/src/parser.bah"
parseLines(tokens,elems);

#line 417 "/home/alois/Documents/bah-bah/src/parser.bah"
char ok = *(char*)channel__receive(done);

#line 420 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_666 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_666[2] = "();\n";____BAH_COMPILER_VAR_666[1] = pathToVarName(fn);____BAH_COMPILER_VAR_666[0] = "__BAH_init";char * ____BAH_COMPILER_VAR_667 =__Bah_multiple_concat(____BAH_COMPILER_VAR_666, 3);INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_667));

#line 423 "/home/alois/Documents/bah-bah/src/parser.bah"
shouldOnlyDecl = osod;

#line 424 "/home/alois/Documents/bah-bah/src/parser.bah"
isSubObject = oiso;

#line 425 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.currentFile = of;

#line 426 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.currentDir = od;

#line 427 "/home/alois/Documents/bah-bah/src/parser.bah"
isImportedSubObject = oiiso;
};

#line 430 "/home/alois/Documents/bah-bah/src/parser.bah"
void parseInclude(__BAH_ARR_TYPE_Tok l,struct Elems* elems){

#line 432 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((len(l)!=2)&&(len(l)!=3), 0)) {

#line 433 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&l->data[len(l)-1],"Invalid usage of include, ending by {TOKEN}.");
}

#line 435 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok strt = l->data[1];

#line 436 "/home/alois/Documents/bah-bah/src/parser.bah"
char isSupressed = false;

#line 437 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(strt.cont, "!") == 0)&&(len(l)>2)) {

#line 438 "/home/alois/Documents/bah-bah/src/parser.bah"
isSupressed = true;

#line 439 "/home/alois/Documents/bah-bah/src/parser.bah"
strt = l->data[2];
}

#line 441 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((strt.type!=TOKEN_TYPE_STR), 0)) {

#line 442 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&strt,"Cannot use {TOKEN} as string in include.");
}

#line 446 "/home/alois/Documents/bah-bah/src/parser.bah"
char * sc = strt.cont;

#line 447 "/home/alois/Documents/bah-bah/src/parser.bah"
strTrimLeft(&sc,1);

#line 448 "/home/alois/Documents/bah-bah/src/parser.bah"
strTrimRight(&sc,1);

#line 449 "/home/alois/Documents/bah-bah/src/parser.bah"
if (strHasPrefix(sc,"<")||strHasSuffix(sc,".h")||strHasSuffix(sc,".c")) {

#line 450 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((isSubObject==false)||(isSupressed==false)) {

#line 451 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_668 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_668[2] = "\n";____BAH_COMPILER_VAR_668[1] = sc;____BAH_COMPILER_VAR_668[0] = "#include ";char * ____BAH_COMPILER_VAR_669 =__Bah_multiple_concat(____BAH_COMPILER_VAR_668, 3);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_669));

#line 452 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_670 = len(compilerState.cIncludes);
    __Bah_realocate_arr(compilerState.cIncludes, ____BAH_COMPILER_VAR_670);
    compilerState.cIncludes->data[____BAH_COMPILER_VAR_670] = sc;
}
}

#line 454 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 455 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((includeFile(sc,elems)==false), 0)) {

#line 456 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&strt,"Could not find file {TOKEN}.");
}
}
};

#line 461 "/home/alois/Documents/bah-bah/src/parser.bah"
array(char *)* signs;

#line 464 "/home/alois/Documents/bah-bah/src/parser.bah"
__BAH_ARR_TYPE_Tok prePross(__BAH_ARR_TYPE_Tok line,lineType ltp,struct Elems* elems);

#line 467 "/home/alois/Documents/bah-bah/src/parser.bah"
__BAH_ARR_TYPE_Tok parseStructType(__BAH_ARR_TYPE_Tok line,lineType ltp,struct Elems* elems){

#line 470 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((ltp==LINE_TYPE_VAR)) {

#line 471 "/home/alois/Documents/bah-bah/src/parser.bah"
return line;
}

#line 474 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);

#line 475 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int i = 0;

#line 475 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i<len(line))) {

#line 476 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = line->data[i];

#line 477 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((t.type==TOKEN_TYPE_VAR)) {

#line 479 "/home/alois/Documents/bah-bah/src/parser.bah"
if (strHasPrefix(t.bahType,"[]")) {

#line 480 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_671 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_671);
    nl->data[____BAH_COMPILER_VAR_671] = t;

#line 481 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 482 "/home/alois/Documents/bah-bah/src/parser.bah"
continue;
}

#line 484 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 485 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok ____BAH_COMPILER_VAR_672 = {};
____BAH_COMPILER_VAR_672.cont = "";
____BAH_COMPILER_VAR_672.ogCont = "";
____BAH_COMPILER_VAR_672.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_672.line = 1;
____BAH_COMPILER_VAR_672.begLine = 1;
____BAH_COMPILER_VAR_672.bahType = "";
____BAH_COMPILER_VAR_672.cont = "";
struct Tok nt = ____BAH_COMPILER_VAR_672;

#line 488 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((i<len(line))) {

#line 489 "/home/alois/Documents/bah-bah/src/parser.bah"
nt = line->data[i];
}

#line 491 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((i==len(line))||(strcmp(nt.cont, "{") != 0)) {

#line 492 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((i-2>=0)) {

#line 493 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok newTk = line->data[i-2];

#line 495 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(newTk.cont, "new") == 0)) {

#line 496 "/home/alois/Documents/bah-bah/src/parser.bah"
struct cStruct* s = searchStruct(t.cont,elems);

#line 497 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((s==null), 0)) {

#line 498 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"Cannot initialize new unknown struct {TOKEN}.");
}

#line 500 "/home/alois/Documents/bah-bah/src/parser.bah"
t.cont = genCompilerVar();

#line 501 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* ____BAH_COMPILER_VAR_673 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_673->name = "";
____BAH_COMPILER_VAR_673->type = "";
____BAH_COMPILER_VAR_673->constVal = "";
____BAH_COMPILER_VAR_673->from = "";
struct variable* tmpV = ____BAH_COMPILER_VAR_673;

#line 502 "/home/alois/Documents/bah-bah/src/parser.bah"
tmpV->name = t.cont;

#line 503 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_674 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_674[1] = "*";____BAH_COMPILER_VAR_674[0] = s->name;char * ____BAH_COMPILER_VAR_675 =__Bah_multiple_concat(____BAH_COMPILER_VAR_674, 2);tmpV->type = ____BAH_COMPILER_VAR_675;

#line 504 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string cType = getCType(tmpV->type,elems);

#line 505 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string structType = getCType(s->name,elems);

#line 506 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_676 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_676);
    elems->vars->data[____BAH_COMPILER_VAR_676] = tmpV;

#line 508 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_677 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_677[6] = declareStructMethods(tmpV,s,elems);____BAH_COMPILER_VAR_677[5] = "));\n";____BAH_COMPILER_VAR_677[4] = string__str(&structType);____BAH_COMPILER_VAR_677[3] = " = memoryAlloc(sizeof(";____BAH_COMPILER_VAR_677[2] = t.cont;____BAH_COMPILER_VAR_677[1] = " ";____BAH_COMPILER_VAR_677[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_678 =__Bah_multiple_concat(____BAH_COMPILER_VAR_677, 7);struct rope* r = rope(____BAH_COMPILER_VAR_678);

#line 510 "/home/alois/Documents/bah-bah/src/parser.bah"
if (isGlobal()) {

#line 511 "/home/alois/Documents/bah-bah/src/parser.bah"
INIT = rope__add(INIT, r);
}

#line 512 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 513 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope__add(OUTPUT, r);
}

#line 516 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_679 = len(nl)-1;
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_679);
    nl->data[____BAH_COMPILER_VAR_679] = t;

#line 517 "/home/alois/Documents/bah-bah/src/parser.bah"
continue;
}
}
}

#line 522 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((i<len(line))) {

#line 523 "/home/alois/Documents/bah-bah/src/parser.bah"
nt = line->data[i];

#line 524 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(nt.cont, "{") == 0)) {

#line 525 "/home/alois/Documents/bah-bah/src/parser.bah"
char isHeap = false;

#line 526 "/home/alois/Documents/bah-bah/src/parser.bah"
char * sep = ".";

#line 527 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((i-2>=0)) {

#line 528 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok newTk = line->data[i-2];

#line 529 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(newTk.cont, "new") == 0)) {

#line 530 "/home/alois/Documents/bah-bah/src/parser.bah"
isHeap = true;

#line 531 "/home/alois/Documents/bah-bah/src/parser.bah"
sep = "->";
}
}

#line 534 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 535 "/home/alois/Documents/bah-bah/src/parser.bah"
struct cStruct* s = searchStruct(t.cont,elems);

#line 536 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((s==null), 0)) {

#line 537 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"Unknown struct name {TOKEN}.");
}

#line 540 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);

#line 541 "/home/alois/Documents/bah-bah/src/parser.bah"
long int nbBraces = 1;

#line 542 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<len(line)); 
#line 542 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 543 "/home/alois/Documents/bah-bah/src/parser.bah"
t = line->data[i];

#line 544 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "{") == 0)) {

#line 545 "/home/alois/Documents/bah-bah/src/parser.bah"
++nbBraces;
}

#line 546 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(t.cont, "}") == 0)) {

#line 547 "/home/alois/Documents/bah-bah/src/parser.bah"
--nbBraces;

#line 548 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((nbBraces==0)) {

#line 549 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}
}

#line 552 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_680 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_680);
    memory->data[____BAH_COMPILER_VAR_680] = t;
};

#line 556 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((len(memory)>0)) {

#line 557 "/home/alois/Documents/bah-bah/src/parser.bah"
memory = prePross(memory,(lineType)-1,elems);
}

#line 561 "/home/alois/Documents/bah-bah/src/parser.bah"
long int declType = 0;

#line 563 "/home/alois/Documents/bah-bah/src/parser.bah"
char * rvn = genCompilerVar();

#line 564 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* ____BAH_COMPILER_VAR_681 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_681->name = "";
____BAH_COMPILER_VAR_681->type = "";
____BAH_COMPILER_VAR_681->constVal = "";
____BAH_COMPILER_VAR_681->from = "";
struct variable* tmpV = ____BAH_COMPILER_VAR_681;

#line 565 "/home/alois/Documents/bah-bah/src/parser.bah"
tmpV->name = rvn;

#line 566 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((isHeap==true)) {

#line 567 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_682 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_682[1] = "*";____BAH_COMPILER_VAR_682[0] = s->name;char * ____BAH_COMPILER_VAR_683 =__Bah_multiple_concat(____BAH_COMPILER_VAR_682, 2);tmpV->type = ____BAH_COMPILER_VAR_683;

#line 568 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_684 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_684);
    elems->vars->data[____BAH_COMPILER_VAR_684] = tmpV;
}

#line 569 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 570 "/home/alois/Documents/bah-bah/src/parser.bah"
tmpV->type = s->name;
}

#line 572 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string rst = getCType(tmpV->type,elems);

#line 573 "/home/alois/Documents/bah-bah/src/parser.bah"
struct rope* r= null;

#line 576 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((isHeap==true)) {

#line 577 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ____BAH_COMPILER_VAR_685 =string__str(&rst);struct string structType = string(____BAH_COMPILER_VAR_685);

#line 578 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimRight(&structType,1);

#line 579 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_686 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_686[6] = declareStructMethods(tmpV,s,elems);____BAH_COMPILER_VAR_686[5] = "));\n";____BAH_COMPILER_VAR_686[4] = string__str(&structType);____BAH_COMPILER_VAR_686[3] = " = memoryAlloc(sizeof(";____BAH_COMPILER_VAR_686[2] = rvn;____BAH_COMPILER_VAR_686[1] = " ";____BAH_COMPILER_VAR_686[0] = string__str(&rst);char * ____BAH_COMPILER_VAR_687 =__Bah_multiple_concat(____BAH_COMPILER_VAR_686, 7);r = rope(____BAH_COMPILER_VAR_687);
}

#line 580 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 581 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_688 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_688[4] = declareStructMethods(tmpV,s,elems);____BAH_COMPILER_VAR_688[3] = " = {};\n";____BAH_COMPILER_VAR_688[2] = rvn;____BAH_COMPILER_VAR_688[1] = " ";____BAH_COMPILER_VAR_688[0] = string__str(&rst);char * ____BAH_COMPILER_VAR_689 =__Bah_multiple_concat(____BAH_COMPILER_VAR_688, 5);r = rope(____BAH_COMPILER_VAR_689);
}

#line 583 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int j = 0;

#line 583 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int k = 0;

#line 583 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((k<len(memory))) {

#line 584 "/home/alois/Documents/bah-bah/src/parser.bah"
t = memory->data[k];

#line 586 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((k+2<len(memory))) {

#line 587 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok st = memory->data[k+1];

#line 588 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok vl = memory->data[k+2];

#line 589 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(st.cont, ":") == 0)) {

#line 590 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((declType!=0)&&(declType!=1), 0)) {

#line 591 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"Cannot declare member {TOKEN} by name in list declaration.");
}

#line 593 "/home/alois/Documents/bah-bah/src/parser.bah"
declType = 1;

#line 594 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((t.type!=TOKEN_TYPE_VAR), 0)) {

#line 595 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"Cannot use {TOKEN} as struct member name.");
}

#line 597 "/home/alois/Documents/bah-bah/src/parser.bah"
j = 0;

#line 597 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((j<len(s->members))) {

#line 598 "/home/alois/Documents/bah-bah/src/parser.bah"
struct structMemb* m = s->members->data[j];

#line 599 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(m->name, t.cont) != 0)) {

#line 600 "/home/alois/Documents/bah-bah/src/parser.bah"
j = j+1;

#line 601 "/home/alois/Documents/bah-bah/src/parser.bah"
continue;
}

#line 603 "/home/alois/Documents/bah-bah/src/parser.bah"
char * vlt = getTypeFromToken(&vl,true,elems);

#line 604 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((compTypes(vlt,m->type)==false), 0)) {

#line 605 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_690 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_690[4] = "'.";____BAH_COMPILER_VAR_690[3] = m->type;____BAH_COMPILER_VAR_690[2] = ") as '";____BAH_COMPILER_VAR_690[1] = vlt;____BAH_COMPILER_VAR_690[0] = "Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_691 =__Bah_multiple_concat(____BAH_COMPILER_VAR_690, 5);throwErr(&vl,____BAH_COMPILER_VAR_691);
}

#line 607 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_692 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_692[5] = ";\n";____BAH_COMPILER_VAR_692[4] = vl.cont;____BAH_COMPILER_VAR_692[3] = " = ";____BAH_COMPILER_VAR_692[2] = m->name;____BAH_COMPILER_VAR_692[1] = sep;____BAH_COMPILER_VAR_692[0] = rvn;char * ____BAH_COMPILER_VAR_693 =__Bah_multiple_concat(____BAH_COMPILER_VAR_692, 6);r = rope__add(r, rope(____BAH_COMPILER_VAR_693));

#line 608 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
};

#line 610 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((j==len(s->members)), 0)) {

#line 611 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_694 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_694[2] = "' has no member called {TOKEN}.";____BAH_COMPILER_VAR_694[1] = s->name;____BAH_COMPILER_VAR_694[0] = "Struct '";char * ____BAH_COMPILER_VAR_695 =__Bah_multiple_concat(____BAH_COMPILER_VAR_694, 3);throwErr(&t,____BAH_COMPILER_VAR_695);
}

#line 613 "/home/alois/Documents/bah-bah/src/parser.bah"
k = k+3;

#line 614 "/home/alois/Documents/bah-bah/src/parser.bah"
continue;
}
}

#line 617 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((declType!=0)&&(declType!=2), 0)) {

#line 618 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"Cannot declare member {TOKEN} without specifying its name.");
}

#line 621 "/home/alois/Documents/bah-bah/src/parser.bah"
declType = 2;

#line 622 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((j>len(s->members)), 0)) {

#line 623 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"Too many members {TOKEN}.");
}

#line 625 "/home/alois/Documents/bah-bah/src/parser.bah"
struct structMemb* m = s->members->data[j];

#line 626 "/home/alois/Documents/bah-bah/src/parser.bah"
++j;

#line 628 "/home/alois/Documents/bah-bah/src/parser.bah"
char * tt = getTypeFromToken(&t,true,elems);

#line 629 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((compTypes(tt,m->type)==false), 0)) {

#line 630 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_696 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_696[4] = "'.";____BAH_COMPILER_VAR_696[3] = m->type;____BAH_COMPILER_VAR_696[2] = ") as '";____BAH_COMPILER_VAR_696[1] = tt;____BAH_COMPILER_VAR_696[0] = "Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_697 =__Bah_multiple_concat(____BAH_COMPILER_VAR_696, 5);throwErr(&t,____BAH_COMPILER_VAR_697);
}

#line 633 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_698 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_698[5] = ";\n";____BAH_COMPILER_VAR_698[4] = t.cont;____BAH_COMPILER_VAR_698[3] = " = ";____BAH_COMPILER_VAR_698[2] = m->name;____BAH_COMPILER_VAR_698[1] = sep;____BAH_COMPILER_VAR_698[0] = rvn;char * ____BAH_COMPILER_VAR_699 =__Bah_multiple_concat(____BAH_COMPILER_VAR_698, 6);r = rope__add(r, rope(____BAH_COMPILER_VAR_699));

#line 635 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((k+1<len(memory))) {

#line 636 "/home/alois/Documents/bah-bah/src/parser.bah"
++k;

#line 637 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok st = memory->data[k];

#line 638 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((strcmp(st.cont, ",") != 0), 0)) {

#line 639 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&st,"Need ',' separator between two values, not {TOKEN}.");
}
}

#line 642 "/home/alois/Documents/bah-bah/src/parser.bah"
++k;
};

#line 646 "/home/alois/Documents/bah-bah/src/parser.bah"
if (isGlobal()) {

#line 647 "/home/alois/Documents/bah-bah/src/parser.bah"
INIT = rope__add(INIT, r);
}

#line 648 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 649 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope__add(OUTPUT, r);
}

#line 653 "/home/alois/Documents/bah-bah/src/parser.bah"
t.bahType = tmpV->type;

#line 654 "/home/alois/Documents/bah-bah/src/parser.bah"
t.cont = rvn;

#line 655 "/home/alois/Documents/bah-bah/src/parser.bah"
t.isValue = true;

#line 656 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((isHeap==true)) {

#line 657 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_700 = len(nl)-1;
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_700);
    nl->data[____BAH_COMPILER_VAR_700] = t;
}

#line 658 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 659 "/home/alois/Documents/bah-bah/src/parser.bah"
t.isEqual = true;

#line 660 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_701 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_701);
    nl->data[____BAH_COMPILER_VAR_701] = t;
}

#line 662 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 663 "/home/alois/Documents/bah-bah/src/parser.bah"
continue;
}

#line 665 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 666 "/home/alois/Documents/bah-bah/src/parser.bah"
--i;
}
}
}

#line 670 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_702 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_702);
    nl->data[____BAH_COMPILER_VAR_702] = t;

#line 671 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;
};

#line 674 "/home/alois/Documents/bah-bah/src/parser.bah"
return nl;
};

#line 677 "/home/alois/Documents/bah-bah/src/parser.bah"
__BAH_ARR_TYPE_Tok parseArrayType(__BAH_ARR_TYPE_Tok line,struct Elems* elems,char guard){

#line 680 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int i = 0;

#line 680 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((guard==true)) {

#line 681 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<len(line)); 
#line 681 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 682 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = line->data[i];

#line 683 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "[") == 0)) {

#line 684 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}
};

#line 687 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((i==len(line))) {

#line 688 "/home/alois/Documents/bah-bah/src/parser.bah"
return line;
}
}

#line 691 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct Tok)* nl = arraySubstitute(line, 0, i);

#line 693 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<len(line)); 
#line 693 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 694 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = line->data[i];

#line 695 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "[") == 0)) {

#line 696 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 697 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((i<len(line))) {

#line 698 "/home/alois/Documents/bah-bah/src/parser.bah"
t = line->data[i];

#line 699 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "]") == 0)) {

#line 700 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 701 "/home/alois/Documents/bah-bah/src/parser.bah"
long int depth = 1;

#line 702 "/home/alois/Documents/bah-bah/src/parser.bah"
char * bracks = "[]";

#line 703 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<len(line)-1); 
#line 703 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 704 "/home/alois/Documents/bah-bah/src/parser.bah"
t = line->data[i];

#line 705 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok nt = line->data[i+1];

#line 706 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "[") == 0)&&(strcmp(nt.cont, "]") == 0)) {

#line 707 "/home/alois/Documents/bah-bah/src/parser.bah"
++depth;

#line 708 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_703 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_703[1] = "[]";____BAH_COMPILER_VAR_703[0] = bracks;char * ____BAH_COMPILER_VAR_704 =__Bah_multiple_concat(____BAH_COMPILER_VAR_703, 2);bracks = ____BAH_COMPILER_VAR_704;

#line 709 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;
}

#line 710 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 711 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}
};

#line 714 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((i<len(line))) {

#line 715 "/home/alois/Documents/bah-bah/src/parser.bah"
t = line->data[i];

#line 716 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((t.type!=TOKEN_TYPE_VAR), 0)) {

#line 717 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"Cannot use {TOKEN} as array type.");
}

#line 719 "/home/alois/Documents/bah-bah/src/parser.bah"
char * arrElem = t.cont;

#line 720 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_705 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_705[1] = arrElem;____BAH_COMPILER_VAR_705[0] = bracks;char * ____BAH_COMPILER_VAR_706 =__Bah_multiple_concat(____BAH_COMPILER_VAR_705, 2);t.bahType = ____BAH_COMPILER_VAR_706;

#line 721 "/home/alois/Documents/bah-bah/src/parser.bah"
t.cont = "";

#line 722 "/home/alois/Documents/bah-bah/src/parser.bah"
t.isValue = true;

#line 723 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_707 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_707);
    nl->data[____BAH_COMPILER_VAR_707] = t;

#line 724 "/home/alois/Documents/bah-bah/src/parser.bah"
continue;
}
}

#line 726 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 727 "/home/alois/Documents/bah-bah/src/parser.bah"
--i;

#line 728 "/home/alois/Documents/bah-bah/src/parser.bah"
t = line->data[i];
}
}

#line 730 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 731 "/home/alois/Documents/bah-bah/src/parser.bah"
--i;
}
}

#line 735 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_708 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_708);
    nl->data[____BAH_COMPILER_VAR_708] = t;
};

#line 738 "/home/alois/Documents/bah-bah/src/parser.bah"
return nl;
};

#line 741 "/home/alois/Documents/bah-bah/src/parser.bah"
array(char *)* comparators;

#line 742 "/home/alois/Documents/bah-bah/src/parser.bah"
array(char *)* compSep;

#line 745 "/home/alois/Documents/bah-bah/src/parser.bah"
__BAH_ARR_TYPE_Tok parsePointers(__BAH_ARR_TYPE_Tok l,struct Elems* elems){

#line 746 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int i = 0;

#line 746 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<len(l)); 
#line 746 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 747 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = l->data[i];

#line 748 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "&") == 0)||(strcmp(t.cont, "*") == 0)) {

#line 749 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((i>0)) {

#line 750 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((l->data[i-1].type==TOKEN_TYPE_VAR)||(l->data[i-1].isValue==true)) {

#line 751 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "*") == 0)) {

#line 752 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((i+1<len(l))) {

#line 753 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(l->data[i+1].cont, "(") != 0)&&(l->data[i+1].type!=TOKEN_TYPE_CAST)&&(l->data[i+1].isValue!=true)) {

#line 754 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_709 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_709[1] = t.cont;____BAH_COMPILER_VAR_709[0] = l->data[i-1].cont;char * ____BAH_COMPILER_VAR_710 =__Bah_multiple_concat(____BAH_COMPILER_VAR_709, 2);l->data[i-1].cont = ____BAH_COMPILER_VAR_710;

#line 755 "/home/alois/Documents/bah-bah/src/parser.bah"
delete(l,i);

#line 756 "/home/alois/Documents/bah-bah/src/parser.bah"
--i;
}
}

#line 758 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 759 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_711 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_711[1] = t.cont;____BAH_COMPILER_VAR_711[0] = l->data[i-1].cont;char * ____BAH_COMPILER_VAR_712 =__Bah_multiple_concat(____BAH_COMPILER_VAR_711, 2);l->data[i-1].cont = ____BAH_COMPILER_VAR_712;

#line 760 "/home/alois/Documents/bah-bah/src/parser.bah"
delete(l,i);

#line 761 "/home/alois/Documents/bah-bah/src/parser.bah"
--i;
}
}

#line 764 "/home/alois/Documents/bah-bah/src/parser.bah"
continue;
}
}

#line 768 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((i+1<len(l))) {

#line 769 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((i>0)) {

#line 770 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(l->data[i-1].cont, ")") == 0)||(l->data[i-1].isValue==true)) {

#line 771 "/home/alois/Documents/bah-bah/src/parser.bah"
continue;
}
}

#line 774 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((l->data[i+1].type==TOKEN_TYPE_VAR)) {

#line 775 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_713 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_713[1] = l->data[i+1].cont;____BAH_COMPILER_VAR_713[0] = t.cont;char * ____BAH_COMPILER_VAR_714 =__Bah_multiple_concat(____BAH_COMPILER_VAR_713, 2);l->data[i+1].cont = ____BAH_COMPILER_VAR_714;

#line 776 "/home/alois/Documents/bah-bah/src/parser.bah"
delete(l,i);

#line 777 "/home/alois/Documents/bah-bah/src/parser.bah"
--i;
}
}
}
};

#line 783 "/home/alois/Documents/bah-bah/src/parser.bah"
return l;
};

#line 787 "/home/alois/Documents/bah-bah/src/parser.bah"
char * parseSerialize(struct Tok* e,struct Elems* elems){

#line 790 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* v = searchVar(e->cont,elems);

#line 791 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((v==null), 0)) {

#line 792 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&e,"Must be a var, not {TOKEN}.");
}

#line 795 "/home/alois/Documents/bah-bah/src/parser.bah"
struct cStruct* s = searchStruct(v->type,elems);

#line 796 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((s==null), 0)) {

#line 797 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&e,"Must be a struct, not {TOKEN}.");
}

#line 800 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string svt = string(v->type);

#line 801 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int ptrLevel = string__count(&svt,"*");

#line 803 "/home/alois/Documents/bah-bah/src/parser.bah"
string__replace(&svt,"*","");

#line 805 "/home/alois/Documents/bah-bah/src/parser.bah"
char * code= null;

#line 807 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((ptrLevel==0)) {

#line 808 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_715 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_715[5] = ")";____BAH_COMPILER_VAR_715[4] = string__str(&svt);____BAH_COMPILER_VAR_715[3] = "sizeof(struct ";____BAH_COMPILER_VAR_715[2] = ", ";____BAH_COMPILER_VAR_715[1] = e->cont;____BAH_COMPILER_VAR_715[0] = "__serialize(&";char * ____BAH_COMPILER_VAR_716 =__Bah_multiple_concat(____BAH_COMPILER_VAR_715, 6);code = ____BAH_COMPILER_VAR_716;
}

#line 809 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 810 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ptrRect = "";

#line 811 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((ptrLevel>1)) {

#line 812 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_717 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_717[1] = "*";____BAH_COMPILER_VAR_717[0] = ptrRect;char * ____BAH_COMPILER_VAR_718 =__Bah_multiple_concat(____BAH_COMPILER_VAR_717, 2);ptrRect = ____BAH_COMPILER_VAR_718;

#line 813 "/home/alois/Documents/bah-bah/src/parser.bah"
ptrLevel = ptrLevel-1;
};

#line 815 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_719 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_719[6] = ")";____BAH_COMPILER_VAR_719[5] = string__str(&svt);____BAH_COMPILER_VAR_719[4] = "sizeof(struct ";____BAH_COMPILER_VAR_719[3] = ", ";____BAH_COMPILER_VAR_719[2] = e->cont;____BAH_COMPILER_VAR_719[1] = ptrRect;____BAH_COMPILER_VAR_719[0] = "__serialize(";char * ____BAH_COMPILER_VAR_720 =__Bah_multiple_concat(____BAH_COMPILER_VAR_719, 7);code = ____BAH_COMPILER_VAR_720;

#line 818 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int i = 0;

#line 818 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i<len(s->members))) {

#line 819 "/home/alois/Documents/bah-bah/src/parser.bah"
struct structMemb* m = s->members->data[i];

#line 820 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(m->type, "cpstring") == 0)) {

#line 821 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_721 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_721[5] = ")";____BAH_COMPILER_VAR_721[4] = m->name;____BAH_COMPILER_VAR_721[3] = "->";____BAH_COMPILER_VAR_721[2] = e->cont;____BAH_COMPILER_VAR_721[1] = "+strlen(";____BAH_COMPILER_VAR_721[0] = code;char * ____BAH_COMPILER_VAR_722 =__Bah_multiple_concat(____BAH_COMPILER_VAR_721, 6);code = ____BAH_COMPILER_VAR_722;
}

#line 823 "/home/alois/Documents/bah-bah/src/parser.bah"
i = i+1;
};
}

#line 829 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_723 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_723[1] = ")";____BAH_COMPILER_VAR_723[0] = code;char * ____BAH_COMPILER_VAR_724 =__Bah_multiple_concat(____BAH_COMPILER_VAR_723, 2);return ____BAH_COMPILER_VAR_724;
};

#line 832 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok parseReflect(struct Tok t,char * tt,struct Elems* elems,char parsedPointer,char * ogName,char * offset){

#line 834 "/home/alois/Documents/bah-bah/src/parser.bah"
char * isArr = "0";

#line 836 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((t.type!=TOKEN_TYPE_VAR)||(t.type!=TOKEN_TYPE_FUNC)) {

#line 837 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string cType;

#line 838 "/home/alois/Documents/bah-bah/src/parser.bah"
if (strHasPrefix(tt,"function(")) {

#line 839 "/home/alois/Documents/bah-bah/src/parser.bah"
cType = string("void*");
}

#line 840 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 841 "/home/alois/Documents/bah-bah/src/parser.bah"
cType = getCType(tt,elems);
}

#line 843 "/home/alois/Documents/bah-bah/src/parser.bah"
char * v = genCompilerVar();

#line 844 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((parsedPointer==true)) {

#line 845 "/home/alois/Documents/bah-bah/src/parser.bah"
string__append(&cType,"*");
}

#line 847 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_725 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_725[5] = ";\n";____BAH_COMPILER_VAR_725[4] = t.cont;____BAH_COMPILER_VAR_725[3] = " = ";____BAH_COMPILER_VAR_725[2] = v;____BAH_COMPILER_VAR_725[1] = " ";____BAH_COMPILER_VAR_725[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_726 =__Bah_multiple_concat(____BAH_COMPILER_VAR_725, 6);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_726));

#line 848 "/home/alois/Documents/bah-bah/src/parser.bah"
t.cont = v;

#line 849 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((t.type==TOKEN_TYPE_STR)) {

#line 850 "/home/alois/Documents/bah-bah/src/parser.bah"
ogName = "[bah cpstring]";
}
}

#line 854 "/home/alois/Documents/bah-bah/src/parser.bah"
char * arrElem = "0";

#line 855 "/home/alois/Documents/bah-bah/src/parser.bah"
if (strHasPrefix(tt,"[]")) {

#line 856 "/home/alois/Documents/bah-bah/src/parser.bah"
isArr = "1";

#line 857 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string aet = string(tt);

#line 858 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimLeft(&aet,2);

#line 859 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok ____BAH_COMPILER_VAR_727 = {};
____BAH_COMPILER_VAR_727.cont = "";
____BAH_COMPILER_VAR_727.ogCont = "";
____BAH_COMPILER_VAR_727.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_727.line = 1;
____BAH_COMPILER_VAR_727.begLine = 1;
____BAH_COMPILER_VAR_727.bahType = "";
struct Tok tmpT = ____BAH_COMPILER_VAR_727;

#line 860 "/home/alois/Documents/bah-bah/src/parser.bah"
tmpT.type = TOKEN_TYPE_VAR;

#line 861 "/home/alois/Documents/bah-bah/src/parser.bah"
tmpT.cont = "0";

#line 862 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ____BAH_COMPILER_VAR_728 =string__str(&aet);struct Tok rt = parseReflect(tmpT,____BAH_COMPILER_VAR_728,elems,true,"","0");

#line 864 "/home/alois/Documents/bah-bah/src/parser.bah"
char * aev = genCompilerVar();

#line 866 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_729 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_729[4] = ";\n        ";____BAH_COMPILER_VAR_729[3] = rt.cont;____BAH_COMPILER_VAR_729[2] = " = ";____BAH_COMPILER_VAR_729[1] = aev;____BAH_COMPILER_VAR_729[0] = "\n        struct reflectElement ";char * ____BAH_COMPILER_VAR_730 =__Bah_multiple_concat(____BAH_COMPILER_VAR_729, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_730));

#line 870 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_731 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_731[1] = aev;____BAH_COMPILER_VAR_731[0] = "&";char * ____BAH_COMPILER_VAR_732 =__Bah_multiple_concat(____BAH_COMPILER_VAR_731, 2);arrElem = ____BAH_COMPILER_VAR_732;
}

#line 871 "/home/alois/Documents/bah-bah/src/parser.bah"
else if (strHasPrefix(tt,"map:")) {

#line 872 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string aet = string(tt);

#line 873 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimLeft(&aet,4);

#line 874 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok ____BAH_COMPILER_VAR_733 = {};
____BAH_COMPILER_VAR_733.cont = "";
____BAH_COMPILER_VAR_733.ogCont = "";
____BAH_COMPILER_VAR_733.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_733.line = 1;
____BAH_COMPILER_VAR_733.begLine = 1;
____BAH_COMPILER_VAR_733.bahType = "";
struct Tok tmpT = ____BAH_COMPILER_VAR_733;

#line 875 "/home/alois/Documents/bah-bah/src/parser.bah"
tmpT.type = TOKEN_TYPE_VAR;

#line 876 "/home/alois/Documents/bah-bah/src/parser.bah"
tmpT.cont = "0";

#line 877 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ____BAH_COMPILER_VAR_734 =string__str(&aet);struct Tok rt = parseReflect(tmpT,____BAH_COMPILER_VAR_734,elems,true,"","0");

#line 878 "/home/alois/Documents/bah-bah/src/parser.bah"
char * aev = genCompilerVar();

#line 879 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_735 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_735[4] = ";\n        ";____BAH_COMPILER_VAR_735[3] = rt.cont;____BAH_COMPILER_VAR_735[2] = " = ";____BAH_COMPILER_VAR_735[1] = aev;____BAH_COMPILER_VAR_735[0] = "\n        struct reflectElement ";char * ____BAH_COMPILER_VAR_736 =__Bah_multiple_concat(____BAH_COMPILER_VAR_735, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_736));

#line 882 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_737 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_737[1] = aev;____BAH_COMPILER_VAR_737[0] = "&";char * ____BAH_COMPILER_VAR_738 =__Bah_multiple_concat(____BAH_COMPILER_VAR_737, 2);arrElem = ____BAH_COMPILER_VAR_738;
}

#line 885 "/home/alois/Documents/bah-bah/src/parser.bah"
char * isStruct = "0";

#line 886 "/home/alois/Documents/bah-bah/src/parser.bah"
struct cStruct* ts = searchStruct(tt,elems);

#line 887 "/home/alois/Documents/bah-bah/src/parser.bah"
char * structLayout = "0";

#line 889 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((ts!=null)) {

#line 890 "/home/alois/Documents/bah-bah/src/parser.bah"
isStruct = "1";

#line 891 "/home/alois/Documents/bah-bah/src/parser.bah"
structLayout = genCompilerVar();

#line 893 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* ____BAH_COMPILER_VAR_739 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_739->name = "";
____BAH_COMPILER_VAR_739->type = "";
____BAH_COMPILER_VAR_739->constVal = "";
____BAH_COMPILER_VAR_739->from = "";
struct variable* slv = ____BAH_COMPILER_VAR_739;

#line 894 "/home/alois/Documents/bah-bah/src/parser.bah"
slv->name = structLayout;

#line 895 "/home/alois/Documents/bah-bah/src/parser.bah"
slv->type = "[]reflectElement";

#line 897 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_740 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_740);
    elems->vars->data[____BAH_COMPILER_VAR_740] = slv;

#line 899 "/home/alois/Documents/bah-bah/src/parser.bah"
struct rope* dataLayout = rope("");

#line 901 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int i = 0;

#line 901 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<len(ts->members)); 
#line 901 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 902 "/home/alois/Documents/bah-bah/src/parser.bah"
struct structMemb* m = ts->members->data[i];

#line 903 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(m->type, tt) == 0)) {

#line 904 "/home/alois/Documents/bah-bah/src/parser.bah"
struct structMemb* ____BAH_COMPILER_VAR_741 = memoryAlloc(sizeof(struct structMemb));
____BAH_COMPILER_VAR_741->name = "";
____BAH_COMPILER_VAR_741->type = "";
____BAH_COMPILER_VAR_741->constVal = "";
____BAH_COMPILER_VAR_741->from = "";
____BAH_COMPILER_VAR_741->def = "";
struct structMemb* nm = ____BAH_COMPILER_VAR_741;

#line 905 "/home/alois/Documents/bah-bah/src/parser.bah"
*nm = *m;

#line 906 "/home/alois/Documents/bah-bah/src/parser.bah"
m = nm;

#line 907 "/home/alois/Documents/bah-bah/src/parser.bah"
m->type = "ptr";
}

#line 909 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok ____BAH_COMPILER_VAR_742 = {};
____BAH_COMPILER_VAR_742.cont = "";
____BAH_COMPILER_VAR_742.ogCont = "";
____BAH_COMPILER_VAR_742.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_742.line = 1;
____BAH_COMPILER_VAR_742.begLine = 1;
____BAH_COMPILER_VAR_742.bahType = "";
struct Tok tmpT = ____BAH_COMPILER_VAR_742;

#line 910 "/home/alois/Documents/bah-bah/src/parser.bah"
tmpT.type = TOKEN_TYPE_VAR;

#line 911 "/home/alois/Documents/bah-bah/src/parser.bah"
char * sep = "->";

#line 912 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strCount(tt,"*")==0)) {

#line 913 "/home/alois/Documents/bah-bah/src/parser.bah"
sep = ".";
}

#line 915 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string mCtype = getCType(m->type,elems);

#line 916 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string offsetTT = string(tt);

#line 917 "/home/alois/Documents/bah-bah/src/parser.bah"
string__replace(&offsetTT,"*","");

#line 918 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_743 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_743[8] = "))";____BAH_COMPILER_VAR_743[7] = m->name;____BAH_COMPILER_VAR_743[6] = ", ";____BAH_COMPILER_VAR_743[5] = string__str(&offsetTT);____BAH_COMPILER_VAR_743[4] = ") + offsetof(struct ";____BAH_COMPILER_VAR_743[3] = t.cont;____BAH_COMPILER_VAR_743[2] = "*)((char*)(";____BAH_COMPILER_VAR_743[1] = string__str(&mCtype);____BAH_COMPILER_VAR_743[0] = "(";char * ____BAH_COMPILER_VAR_744 =__Bah_multiple_concat(____BAH_COMPILER_VAR_743, 9);tmpT.cont = ____BAH_COMPILER_VAR_744;

#line 919 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_745 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_745[4] = ")";____BAH_COMPILER_VAR_745[3] = m->name;____BAH_COMPILER_VAR_745[2] = ", ";____BAH_COMPILER_VAR_745[1] = string__str(&offsetTT);____BAH_COMPILER_VAR_745[0] = "offsetof(struct ";char * ____BAH_COMPILER_VAR_746 =__Bah_multiple_concat(____BAH_COMPILER_VAR_745, 5);struct Tok rt = parseReflect(tmpT,m->type,elems,true,m->name,____BAH_COMPILER_VAR_746);

#line 920 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_747 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_747[5] = ";\n";____BAH_COMPILER_VAR_747[4] = rt.cont;____BAH_COMPILER_VAR_747[3] = "] = ";____BAH_COMPILER_VAR_747[2] = intToStr(i);____BAH_COMPILER_VAR_747[1] = "->data[";____BAH_COMPILER_VAR_747[0] = structLayout;char * ____BAH_COMPILER_VAR_748 =__Bah_multiple_concat(____BAH_COMPILER_VAR_747, 6);dataLayout = rope__add(dataLayout, rope(____BAH_COMPILER_VAR_748));
};

#line 923 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_749 = alloca(15 * sizeof(char*));____BAH_COMPILER_VAR_749[14] = "->elemSize);\n        ";____BAH_COMPILER_VAR_749[13] = structLayout;____BAH_COMPILER_VAR_749[12] = "->length * ";____BAH_COMPILER_VAR_749[11] = structLayout;____BAH_COMPILER_VAR_749[10] = "->data = memoryAlloc(";____BAH_COMPILER_VAR_749[9] = structLayout;____BAH_COMPILER_VAR_749[8] = ";\n        ";____BAH_COMPILER_VAR_749[7] = intToStr(len(ts->members));____BAH_COMPILER_VAR_749[6] = "->length = ";____BAH_COMPILER_VAR_749[5] = structLayout;____BAH_COMPILER_VAR_749[4] = "->elemSize = sizeof(struct reflectElement);\n        ";____BAH_COMPILER_VAR_749[3] = structLayout;____BAH_COMPILER_VAR_749[2] = " = memoryAlloc(sizeof(array(struct reflectElement)));\n        ";____BAH_COMPILER_VAR_749[1] = structLayout;____BAH_COMPILER_VAR_749[0] = "\n        array(struct reflectElement) * ";char * ____BAH_COMPILER_VAR_750 =__Bah_multiple_concat(____BAH_COMPILER_VAR_749, 15);OUTPUT = rope__add(OUTPUT, rope__add(rope(____BAH_COMPILER_VAR_750), dataLayout));
}

#line 931 "/home/alois/Documents/bah-bah/src/parser.bah"
char * amp = "";

#line 932 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strCount(tt,"*")==0)&&(strcmp(tt, "cpstring") != 0)&&(strcmp(tt, "ptr") != 0)&&(parsedPointer==false)) {

#line 933 "/home/alois/Documents/bah-bah/src/parser.bah"
amp = "&";
}

#line 936 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string name = string(ogName);

#line 937 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((hasStructSep(&name)==true)) {

#line 938 "/home/alois/Documents/bah-bah/src/parser.bah"
name = splitStructSepAfter(name);
}

#line 941 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string cType;

#line 943 "/home/alois/Documents/bah-bah/src/parser.bah"
if (strHasPrefix(tt,"function(")) {

#line 944 "/home/alois/Documents/bah-bah/src/parser.bah"
cType = string("void*");
}

#line 945 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 946 "/home/alois/Documents/bah-bah/src/parser.bah"
cType = getCType(tt,elems);
}

#line 950 "/home/alois/Documents/bah-bah/src/parser.bah"
if (string__hasPrefix(&cType,"struct ")) {

#line 951 "/home/alois/Documents/bah-bah/src/parser.bah"
string__replace(&cType,"*","");
}

#line 954 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((cType.length==0)) {

#line 955 "/home/alois/Documents/bah-bah/src/parser.bah"
string__set(&cType,"0");
}

#line 958 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* ____BAH_COMPILER_VAR_751 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_751->name = "";
____BAH_COMPILER_VAR_751->type = "";
____BAH_COMPILER_VAR_751->constVal = "";
____BAH_COMPILER_VAR_751->from = "";
struct variable* rv = ____BAH_COMPILER_VAR_751;

#line 959 "/home/alois/Documents/bah-bah/src/parser.bah"
rv->name = genCompilerVar();

#line 960 "/home/alois/Documents/bah-bah/src/parser.bah"
rv->type = "reflectElement";

#line 962 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_752 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_752);
    elems->vars->data[____BAH_COMPILER_VAR_752] = rv;

#line 964 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_753 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_753[2] = "\"";____BAH_COMPILER_VAR_753[1] = tt;____BAH_COMPILER_VAR_753[0] = "\"";char * ____BAH_COMPILER_VAR_754 =__Bah_multiple_concat(____BAH_COMPILER_VAR_753, 3);char** ____BAH_COMPILER_VAR_755 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_755[2] = "\"";____BAH_COMPILER_VAR_755[1] = string__str(&name);____BAH_COMPILER_VAR_755[0] = "\"";char * ____BAH_COMPILER_VAR_756 =__Bah_multiple_concat(____BAH_COMPILER_VAR_755, 3);char** ____BAH_COMPILER_VAR_757 = alloca(22 * sizeof(char*));____BAH_COMPILER_VAR_757[21] = ");\n";____BAH_COMPILER_VAR_757[20] = offset;____BAH_COMPILER_VAR_757[19] = ", ";____BAH_COMPILER_VAR_757[18] = structLayout;____BAH_COMPILER_VAR_757[17] = ", ";____BAH_COMPILER_VAR_757[16] = isStruct;____BAH_COMPILER_VAR_757[15] = ", ";____BAH_COMPILER_VAR_757[14] = arrElem;____BAH_COMPILER_VAR_757[13] = ", ";____BAH_COMPILER_VAR_757[12] = isArr;____BAH_COMPILER_VAR_757[11] = ", ";____BAH_COMPILER_VAR_757[10] = strLitteralToBahStr(____BAH_COMPILER_VAR_756);____BAH_COMPILER_VAR_757[9] = ", ";____BAH_COMPILER_VAR_757[8] = strLitteralToBahStr(____BAH_COMPILER_VAR_754);____BAH_COMPILER_VAR_757[7] = "), ";____BAH_COMPILER_VAR_757[6] = string__str(&cType);____BAH_COMPILER_VAR_757[5] = ", sizeof(";____BAH_COMPILER_VAR_757[4] = t.cont;____BAH_COMPILER_VAR_757[3] = amp;____BAH_COMPILER_VAR_757[2] = " = __reflect(";____BAH_COMPILER_VAR_757[1] = rv->name;____BAH_COMPILER_VAR_757[0] = "struct reflectElement ";char * ____BAH_COMPILER_VAR_758 =__Bah_multiple_concat(____BAH_COMPILER_VAR_757, 22);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_758));

#line 966 "/home/alois/Documents/bah-bah/src/parser.bah"
t.cont = rv->name;

#line 968 "/home/alois/Documents/bah-bah/src/parser.bah"
return t;
};

#line 972 "/home/alois/Documents/bah-bah/src/parser.bah"
char * parseArrayDecl(struct variable* v,__BAH_ARR_TYPE_Tok l,long int i,long int max,struct Elems* elems){

#line 973 "/home/alois/Documents/bah-bah/src/parser.bah"
long int arrayLength = 0;

#line 974 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string arrType = getCType(v->type,elems);

#line 975 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimRight(&arrType,1);

#line 976 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_759 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_759[2] = "))";____BAH_COMPILER_VAR_759[1] = string__str(&arrType);____BAH_COMPILER_VAR_759[0] = "memoryAlloc(sizeof(";char * ____BAH_COMPILER_VAR_760 =__Bah_multiple_concat(____BAH_COMPILER_VAR_759, 3);char * code = ____BAH_COMPILER_VAR_760;

#line 977 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimLeft(&arrType,6);

#line 978 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimRight(&arrType,1);

#line 979 "/home/alois/Documents/bah-bah/src/parser.bah"
char * elemTypeStr = string__str(&arrType);

#line 981 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((i+1!=max)) {

#line 982 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 983 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok nt = l->data[i];

#line 984 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((strcmp(nt.cont, "{") != 0), 0)) {

#line 985 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&l->data[i+1],"{TOKEN} not expected after array initialization.");
}

#line 987 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string elemBahType = string(v->type);

#line 988 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimLeft(&elemBahType,2);

#line 989 "/home/alois/Documents/bah-bah/src/parser.bah"
char * elemBahTypeStr = string__str(&elemBahType);

#line 990 "/home/alois/Documents/bah-bah/src/parser.bah"
i = i+1;

#line 991 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);

#line 992 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i<max)) {

#line 993 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_761 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_761);
    memory->data[____BAH_COMPILER_VAR_761] = l->data[i];

#line 994 "/home/alois/Documents/bah-bah/src/parser.bah"
i = i+1;
};

#line 996 "/home/alois/Documents/bah-bah/src/parser.bah"
memory = prePross(memory,(lineType)-1,elems);

#line 997 "/home/alois/Documents/bah-bah/src/parser.bah"
i = 0;

#line 997 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i<len(memory))) {

#line 998 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = memory->data[i];

#line 999 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "{") == 0)) {

#line 1001 "/home/alois/Documents/bah-bah/src/parser.bah"
long int j = i-1;

#line 1002 "/home/alois/Documents/bah-bah/src/parser.bah"
long int nbBraces = 0;

#line 1003 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<len(memory)); 
#line 1003 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 1004 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok tmpT = memory->data[i];

#line 1005 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(tmpT.cont, "{") == 0)) {

#line 1006 "/home/alois/Documents/bah-bah/src/parser.bah"
++nbBraces;
}

#line 1007 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(tmpT.cont, "}") == 0)) {

#line 1008 "/home/alois/Documents/bah-bah/src/parser.bah"
--nbBraces;
}

#line 1010 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((nbBraces==0)) {

#line 1011 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}
};

#line 1014 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* ____BAH_COMPILER_VAR_762 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_762->name = "";
____BAH_COMPILER_VAR_762->type = "";
____BAH_COMPILER_VAR_762->constVal = "";
____BAH_COMPILER_VAR_762->from = "";
struct variable* tmpV = ____BAH_COMPILER_VAR_762;

#line 1015 "/home/alois/Documents/bah-bah/src/parser.bah"
tmpV->name = genCompilerVar();

#line 1016 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string elemType = string(v->type);

#line 1017 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimLeft(&elemType,2);

#line 1018 "/home/alois/Documents/bah-bah/src/parser.bah"
tmpV->type = string__str(&elemType);

#line 1019 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_763 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_763);
    elems->vars->data[____BAH_COMPILER_VAR_763] = tmpV;

#line 1021 "/home/alois/Documents/bah-bah/src/parser.bah"
char * oldNL = NEXT_LINE;

#line 1022 "/home/alois/Documents/bah-bah/src/parser.bah"
NEXT_LINE = "";

#line 1023 "/home/alois/Documents/bah-bah/src/parser.bah"
char * innerCode = parseArrayDecl(tmpV,memory,j,i+1,elems);

#line 1024 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ____BAH_COMPILER_VAR_764 =string__str(&elemType);struct string cType = getCType(____BAH_COMPILER_VAR_764,elems);

#line 1025 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_765 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_765[8] = "\n                ";____BAH_COMPILER_VAR_765[7] = NEXT_LINE;____BAH_COMPILER_VAR_765[6] = ";\n                ";____BAH_COMPILER_VAR_765[5] = innerCode;____BAH_COMPILER_VAR_765[4] = " = ";____BAH_COMPILER_VAR_765[3] = tmpV->name;____BAH_COMPILER_VAR_765[2] = ") * ";____BAH_COMPILER_VAR_765[1] = string__str(&cType);____BAH_COMPILER_VAR_765[0] = "\n                array(";char * ____BAH_COMPILER_VAR_766 =__Bah_multiple_concat(____BAH_COMPILER_VAR_765, 9);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_766));

#line 1029 "/home/alois/Documents/bah-bah/src/parser.bah"
NEXT_LINE = oldNL;

#line 1031 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok ____BAH_COMPILER_VAR_767 = {};
____BAH_COMPILER_VAR_767.cont = "";
____BAH_COMPILER_VAR_767.ogCont = "";
____BAH_COMPILER_VAR_767.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_767.line = 1;
____BAH_COMPILER_VAR_767.begLine = 1;
____BAH_COMPILER_VAR_767.bahType = "";
____BAH_COMPILER_VAR_767.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_767.cont = tmpV->name;
____BAH_COMPILER_VAR_767.bahType = string__str(&elemType);
____BAH_COMPILER_VAR_767.isValue = true;
t = ____BAH_COMPILER_VAR_767;
}

#line 1039 "/home/alois/Documents/bah-bah/src/parser.bah"
char * tt = getTypeFromToken(&t,true,elems);

#line 1040 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((compTypes(tt,elemBahTypeStr)==false), 0)) {

#line 1041 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_768 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_768[3] = elemBahTypeStr;____BAH_COMPILER_VAR_768[2] = ") as ";____BAH_COMPILER_VAR_768[1] = tt;____BAH_COMPILER_VAR_768[0] = "Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_769 =__Bah_multiple_concat(____BAH_COMPILER_VAR_768, 4);throwErr(&t,____BAH_COMPILER_VAR_769);
}

#line 1044 "/home/alois/Documents/bah-bah/src/parser.bah"
char * strArrayLength = intToStr(arrayLength);

#line 1045 "/home/alois/Documents/bah-bah/src/parser.bah"
arrayLength = arrayLength+1;

#line 1047 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_770 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_770[6] = ";\n";____BAH_COMPILER_VAR_770[5] = t.cont;____BAH_COMPILER_VAR_770[4] = "] = ";____BAH_COMPILER_VAR_770[3] = strArrayLength;____BAH_COMPILER_VAR_770[2] = "->data[";____BAH_COMPILER_VAR_770[1] = v->name;____BAH_COMPILER_VAR_770[0] = NEXT_LINE;char * ____BAH_COMPILER_VAR_771 =__Bah_multiple_concat(____BAH_COMPILER_VAR_770, 7);NEXT_LINE = ____BAH_COMPILER_VAR_771;

#line 1048 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 1049 "/home/alois/Documents/bah-bah/src/parser.bah"
t = memory->data[i];

#line 1051 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, ",") != 0)) {

#line 1052 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "}") == 0)) {

#line 1053 "/home/alois/Documents/bah-bah/src/parser.bah"
long int allocLength = arrayLength;

#line 1054 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((allocLength>50)) {

#line 1055 "/home/alois/Documents/bah-bah/src/parser.bah"
long int modAllocAmm = allocLength%50;

#line 1056 "/home/alois/Documents/bah-bah/src/parser.bah"
allocLength = allocLength+modAllocAmm;
}

#line 1057 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1058 "/home/alois/Documents/bah-bah/src/parser.bah"
allocLength = 50;
}

#line 1060 "/home/alois/Documents/bah-bah/src/parser.bah"
char * allocLengthStr = intToStr(allocLength);

#line 1061 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_772 = alloca(11 * sizeof(char*));____BAH_COMPILER_VAR_772[10] = NEXT_LINE;____BAH_COMPILER_VAR_772[9] = ";\n";____BAH_COMPILER_VAR_772[8] = allocLengthStr;____BAH_COMPILER_VAR_772[7] = "->realLength = ";____BAH_COMPILER_VAR_772[6] = v->name;____BAH_COMPILER_VAR_772[5] = ");\n                    ";____BAH_COMPILER_VAR_772[4] = allocLengthStr;____BAH_COMPILER_VAR_772[3] = ") * ";____BAH_COMPILER_VAR_772[2] = elemTypeStr;____BAH_COMPILER_VAR_772[1] = "->data = memoryAlloc(sizeof(";____BAH_COMPILER_VAR_772[0] = v->name;char * ____BAH_COMPILER_VAR_773 =__Bah_multiple_concat(____BAH_COMPILER_VAR_772, 11);NEXT_LINE = ____BAH_COMPILER_VAR_773;

#line 1063 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}

#line 1064 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1065 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"Expected ',' got {TOKEN}.");
}
}

#line 1068 "/home/alois/Documents/bah-bah/src/parser.bah"
i = i+1;
};
}

#line 1071 "/home/alois/Documents/bah-bah/src/parser.bah"
char * strArrayLength = intToStr(arrayLength);

#line 1072 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_774 = alloca(10 * sizeof(char*));____BAH_COMPILER_VAR_774[9] = NEXT_LINE;____BAH_COMPILER_VAR_774[8] = ");\n";____BAH_COMPILER_VAR_774[7] = elemTypeStr;____BAH_COMPILER_VAR_774[6] = "->elemSize = sizeof(";____BAH_COMPILER_VAR_774[5] = v->name;____BAH_COMPILER_VAR_774[4] = ";\n";____BAH_COMPILER_VAR_774[3] = strArrayLength;____BAH_COMPILER_VAR_774[2] = "->length = ";____BAH_COMPILER_VAR_774[1] = v->name;____BAH_COMPILER_VAR_774[0] = "\n";char * ____BAH_COMPILER_VAR_775 =__Bah_multiple_concat(____BAH_COMPILER_VAR_774, 10);NEXT_LINE = ____BAH_COMPILER_VAR_775;

#line 1076 "/home/alois/Documents/bah-bah/src/parser.bah"
return code;
};

#line 1079 "/home/alois/Documents/bah-bah/src/parser.bah"
array(char *)* equalsTokens;

#line 1081 "/home/alois/Documents/bah-bah/src/parser.bah"
char ____BAH_COMPILER_VAR_782(array(char *)* arr, char * el) {
        if (arr == 0) {
            return 0;
        };
        for(int i=arr->length-1; i!=-1;i--) {
            if (arr->data[i] != 0 && strcmp(arr->data[i], el) == 0) {
                return 1;
            };
        }
        return 0;
        }
void parseVar(__BAH_ARR_TYPE_Tok l,struct Elems* elems){

#line 1083 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok ft = l->data[0];

#line 1084 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((ft.isFunc==true)) {

#line 1085 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((len(l)>1), 0)) {

#line 1086 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&l->data[len(l)-1],"Not expecting {TOKEN} after function call.");
}

#line 1088 "/home/alois/Documents/bah-bah/src/parser.bah"
ft = l->data[0];

#line 1089 "/home/alois/Documents/bah-bah/src/parser.bah"
char parsed = true;

#line 1090 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_776 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_776[1] = ";\n";____BAH_COMPILER_VAR_776[0] = ft.cont;char * ____BAH_COMPILER_VAR_777 =__Bah_multiple_concat(____BAH_COMPILER_VAR_776, 2);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_777));

#line 1091 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}

#line 1093 "/home/alois/Documents/bah-bah/src/parser.bah"
l = parseStructType(l,(lineType)-1,elems);

#line 1094 "/home/alois/Documents/bah-bah/src/parser.bah"
char isEqual = false;

#line 1095 "/home/alois/Documents/bah-bah/src/parser.bah"
long int equalIndex = 0;

#line 1096 "/home/alois/Documents/bah-bah/src/parser.bah"
char toVar = false;

#line 1097 "/home/alois/Documents/bah-bah/src/parser.bah"
char isPointedVar = false;

#line 1098 "/home/alois/Documents/bah-bah/src/parser.bah"
char isStruct = false;

#line 1099 "/home/alois/Documents/bah-bah/src/parser.bah"
char * currentType = "";

#line 1101 "/home/alois/Documents/bah-bah/src/parser.bah"
ft = l->data[0];

#line 1102 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* v = searchVar(ft.cont,elems);

#line 1103 "/home/alois/Documents/bah-bah/src/parser.bah"
char exists = true;

#line 1104 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ogName= null;

#line 1105 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((v==null)) {

#line 1106 "/home/alois/Documents/bah-bah/src/parser.bah"
exists = false;

#line 1107 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* ____BAH_COMPILER_VAR_778 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_778->name = "";
____BAH_COMPILER_VAR_778->type = "";
____BAH_COMPILER_VAR_778->constVal = "";
____BAH_COMPILER_VAR_778->from = "";
v = ____BAH_COMPILER_VAR_778;

#line 1108 "/home/alois/Documents/bah-bah/src/parser.bah"
v->name = ft.cont;

#line 1109 "/home/alois/Documents/bah-bah/src/parser.bah"
v->type = "";
}

#line 1110 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1111 "/home/alois/Documents/bah-bah/src/parser.bah"
ogName = v->name;
}

#line 1113 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((v->isConst==true), 0)) {

#line 1114 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&ft,"Cannot set the value of const {TOKEN}.");
}

#line 1116 "/home/alois/Documents/bah-bah/src/parser.bah"
char * code = "";

#line 1118 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((exists==true)&&isGlobal(), 0)) {

#line 1119 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&ft,"Cannot redeclare global variable {TOKEN}.");
}

#line 1123 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((len(l)==1)) {

#line 1124 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = l->data[0];

#line 1125 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string c = string(t.cont);

#line 1126 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimLeft(&c,2);

#line 1127 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ____BAH_COMPILER_VAR_779 =string__str(&c);v = searchVar(____BAH_COMPILER_VAR_779,elems);

#line 1128 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((v==null), 0)) {

#line 1129 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"Cannot increase/decrease not declared variable {TOKEN}.");
}

#line 1131 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* rv = getRealVar(v->name,elems);

#line 1132 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((rv!=null)) {

#line 1133 "/home/alois/Documents/bah-bah/src/parser.bah"
rv->lastSet = elems;
}

#line 1135 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_780 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_780[1] = ";\n";____BAH_COMPILER_VAR_780[0] = t.cont;char * ____BAH_COMPILER_VAR_781 =__Bah_multiple_concat(____BAH_COMPILER_VAR_780, 2);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_781));

#line 1136 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}

#line 1139 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((len(l)<2), 0)) {

#line 1140 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&ft,"Missing '=' after {TOKEN}.");
}

#line 1142 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok operT = l->data[1];

#line 1143 "/home/alois/Documents/bah-bah/src/parser.bah"
if (____BAH_COMPILER_VAR_782(equalsTokens, operT.cont)&&(strcmp(operT.cont, "=") != 0)) {

#line 1144 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 1;
nl->elemSize = sizeof(struct Tok);
nl->data = memoryAlloc(sizeof(struct Tok) * 50);
                    nl->realLength = 50;
nl->data[0] = l->data[0];

#line 1145 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((2==len(l)), 0)) {

#line 1146 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&operT,"Cannot use {TOKEN} on nothing.");
}

#line 1148 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string oper = string(operT.cont);

#line 1149 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimRight(&oper,1);

#line 1150 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok operTok = operT;

#line 1151 "/home/alois/Documents/bah-bah/src/parser.bah"
operTok.cont = string__str(&oper);

#line 1153 "/home/alois/Documents/bah-bah/src/parser.bah"
if (l->data[2].isOper) {

#line 1154 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_783 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_783[2] = ")";____BAH_COMPILER_VAR_783[1] = l->data[2].cont;____BAH_COMPILER_VAR_783[0] = "(";char * ____BAH_COMPILER_VAR_784 =__Bah_multiple_concat(____BAH_COMPILER_VAR_783, 3);l->data[2].cont = ____BAH_COMPILER_VAR_784;
}

#line 1157 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct Tok)* tmpL = memoryAlloc(sizeof(array(struct Tok)));

tmpL->length = 3;
tmpL->elemSize = sizeof(struct Tok);
tmpL->data = memoryAlloc(sizeof(struct Tok) * 50);
                    tmpL->realLength = 50;
tmpL->data[0] = ft;
tmpL->data[1] = operTok;
tmpL->data[2] = l->data[2];

#line 1163 "/home/alois/Documents/bah-bah/src/parser.bah"
tmpL = prePross(tmpL,LINE_TYPE_VAR,elems);

#line 1165 "/home/alois/Documents/bah-bah/src/parser.bah"
operT.cont = "=";

#line 1166 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_785 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_785);
    nl->data[____BAH_COMPILER_VAR_785] = operT;

#line 1168 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int j = 0;

#line 1168 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (j<len(tmpL)); 
#line 1168 "/home/alois/Documents/bah-bah/src/parser.bah"
++j) {

#line 1169 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_786 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_786);
    nl->data[____BAH_COMPILER_VAR_786] = tmpL->data[j];
};

#line 1173 "/home/alois/Documents/bah-bah/src/parser.bah"
l = nl;
}

#line 1176 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int i = 1;

#line 1176 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i<len(l))) {

#line 1177 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = l->data[i];

#line 1178 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((t.type==TOKEN_TYPE_SYNTAX)) {

#line 1179 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "=") == 0)) {

#line 1180 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strlen(currentType)>0)) {

#line 1181 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string sct = string(currentType);

#line 1182 "/home/alois/Documents/bah-bah/src/parser.bah"
string__replace(&sct," ","");

#line 1183 "/home/alois/Documents/bah-bah/src/parser.bah"
v->type = string__str(&sct);
}

#line 1185 "/home/alois/Documents/bah-bah/src/parser.bah"
isEqual = true;

#line 1186 "/home/alois/Documents/bah-bah/src/parser.bah"
equalIndex = i;

#line 1187 "/home/alois/Documents/bah-bah/src/parser.bah"
i = i+1;

#line 1188 "/home/alois/Documents/bah-bah/src/parser.bah"
continue;
}
}

#line 1191 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((isEqual==false)) {

#line 1192 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_787 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_787[1] = t.cont;____BAH_COMPILER_VAR_787[0] = currentType;char * ____BAH_COMPILER_VAR_788 =__Bah_multiple_concat(____BAH_COMPILER_VAR_787, 2);currentType = ____BAH_COMPILER_VAR_788;
}

#line 1193 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1195 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((t.isEqual==true)&&(exists==false)&&(isGlobal()==false)) {

#line 1197 "/home/alois/Documents/bah-bah/src/parser.bah"
v->canBeNull = false;
}

#line 1200 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "chan") == 0)) {

#line 1201 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((i>=len(l)), 0)) {

#line 1202 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"Cannot declare a {TOKEN} without a type (chan <type>).");
}

#line 1204 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 1205 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok nt = l->data[i];

#line 1206 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_789 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_789[1] = nt.cont;____BAH_COMPILER_VAR_789[0] = "chan:";char * ____BAH_COMPILER_VAR_790 =__Bah_multiple_concat(____BAH_COMPILER_VAR_789, 2);v->type = ____BAH_COMPILER_VAR_790;

#line 1207 "/home/alois/Documents/bah-bah/src/parser.bah"
code = "channel()";

#line 1208 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((i+1!=len(l)), 0)) {

#line 1209 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok errT = l->data[i+1];

#line 1210 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&errT,"{TOKEN} not expected after channel declaration.");
}

#line 1212 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}

#line 1213 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(t.cont, "map") == 0)) {

#line 1214 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((i>=len(l)), 0)) {

#line 1215 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"Cannot declare a {TOKEN} without a type (map <type>).");
}

#line 1217 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 1218 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok nt = l->data[i];

#line 1219 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_791 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_791[1] = nt.cont;____BAH_COMPILER_VAR_791[0] = "map:";char * ____BAH_COMPILER_VAR_792 =__Bah_multiple_concat(____BAH_COMPILER_VAR_791, 2);v->type = ____BAH_COMPILER_VAR_792;

#line 1220 "/home/alois/Documents/bah-bah/src/parser.bah"
code = "mapWrapper()";

#line 1221 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((i+1!=len(l)), 0)) {

#line 1222 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok errT = l->data[i+1];

#line 1223 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&errT,"{TOKEN} not expected after map declaration.");
}

#line 1225 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}

#line 1226 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(t.cont, "buffer") == 0)) {

#line 1227 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((i>=len(l)), 0)) {

#line 1228 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"Cannot declare a {TOKEN} without a length (buffer <length>).");
}

#line 1230 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 1231 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok nt = l->data[i];

#line 1232 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((nt.type!=TOKEN_TYPE_INT), 0)) {

#line 1233 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&nt,"Expected buffer length, not {TOKEN}.");
}

#line 1235 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_793 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_793[1] = nt.cont;____BAH_COMPILER_VAR_793[0] = "buffer:";char * ____BAH_COMPILER_VAR_794 =__Bah_multiple_concat(____BAH_COMPILER_VAR_793, 2);v->type = ____BAH_COMPILER_VAR_794;

#line 1236 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* ____BAH_COMPILER_VAR_795 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_795->name = "";
____BAH_COMPILER_VAR_795->type = "";
____BAH_COMPILER_VAR_795->constVal = "";
____BAH_COMPILER_VAR_795->from = "";
struct variable* av = ____BAH_COMPILER_VAR_795;

#line 1237 "/home/alois/Documents/bah-bah/src/parser.bah"
av->type = "char*";

#line 1238 "/home/alois/Documents/bah-bah/src/parser.bah"
av->name = genCompilerVar();

#line 1239 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_796 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_796);
    elems->vars->data[____BAH_COMPILER_VAR_796] = av;

#line 1240 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string cType = getCType(av->type,elems);

#line 1241 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_797 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_797[4] = "];";____BAH_COMPILER_VAR_797[3] = nt.cont;____BAH_COMPILER_VAR_797[2] = "[";____BAH_COMPILER_VAR_797[1] = av->name;____BAH_COMPILER_VAR_797[0] = "char ";char * ____BAH_COMPILER_VAR_798 =__Bah_multiple_concat(____BAH_COMPILER_VAR_797, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_798));

#line 1242 "/home/alois/Documents/bah-bah/src/parser.bah"
code = av->name;

#line 1243 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((i+1!=len(l)), 0)) {

#line 1244 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok errT = l->data[i+1];

#line 1245 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&errT,"{TOKEN} not expected after buffer declaration.");
}

#line 1247 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}

#line 1251 "/home/alois/Documents/bah-bah/src/parser.bah"
char * tp = getTypeFromToken(&t,true,elems);

#line 1254 "/home/alois/Documents/bah-bah/src/parser.bah"

                struct string ____BAH_COMPILER_VAR_799 = string(compilerState.currentDir);
                if ((isUnsafe==false)&&(string__hasPrefix(&____BAH_COMPILER_VAR_799,BAH_DIR)==false)&&isRCPpointerType(tp)) {

#line 1255 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "null") == 0)||(tp[strlen(tp)-1]==33)) {

#line 1256 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((exists==true)) {

#line 1257 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* rv = getRealVar(v->name,elems);

#line 1258 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((rv!=null)) {

#line 1259 "/home/alois/Documents/bah-bah/src/parser.bah"
rv->canBeNull = true;
}
}

#line 1261 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1262 "/home/alois/Documents/bah-bah/src/parser.bah"
v->canBeNull = true;
}
}

#line 1264 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((t.type==TOKEN_TYPE_VAR)) {

#line 1265 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* tv = searchVar(t.cont,elems);

#line 1266 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((tv!=null)) {

#line 1267 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((exists==true)&&(tv->canBeNull==false)) {

#line 1268 "/home/alois/Documents/bah-bah/src/parser.bah"
if (canChangeNullState(v,elems)) {

#line 1269 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* rv = getRealVar(v->name,elems);

#line 1270 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((rv!=null)) {

#line 1271 "/home/alois/Documents/bah-bah/src/parser.bah"
rv->canBeNull = false;
}
}
}

#line 1274 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1275 "/home/alois/Documents/bah-bah/src/parser.bah"
v->canBeNull = tv->canBeNull;
}
}
}

#line 1278 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((t.isFunc==true)) {

#line 1279 "/home/alois/Documents/bah-bah/src/parser.bah"
struct func* fn = searchFuncByToken(&t,elems);

#line 1280 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((fn!=null)&&(fn->returns!=null)) {

#line 1281 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((fn->returns->canBeNull==true)) {

#line 1282 "/home/alois/Documents/bah-bah/src/parser.bah"
v->canBeNull = true;
}

#line 1283 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1284 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((exists==true)) {

#line 1285 "/home/alois/Documents/bah-bah/src/parser.bah"
if (canChangeNullState(v,elems)) {

#line 1286 "/home/alois/Documents/bah-bah/src/parser.bah"
v->canBeNull = false;
}
}

#line 1288 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1289 "/home/alois/Documents/bah-bah/src/parser.bah"
v->canBeNull = false;
}
}
}
}

#line 1293 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1294 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((exists==true)) {

#line 1295 "/home/alois/Documents/bah-bah/src/parser.bah"
if (canChangeNullState(v,elems)) {

#line 1296 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* rv = getRealVar(v->name,elems);

#line 1297 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((rv!=null)) {

#line 1298 "/home/alois/Documents/bah-bah/src/parser.bah"
rv->canBeNull = false;
}
}
}

#line 1300 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1301 "/home/alois/Documents/bah-bah/src/parser.bah"
v->canBeNull = false;
}
}
}

#line 1307 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((exists==true)) {

#line 1308 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((compTypes(tp,v->type)==false), 0)) {

#line 1309 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_800 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_800[4] = ".";____BAH_COMPILER_VAR_800[3] = v->type;____BAH_COMPILER_VAR_800[2] = ") as ";____BAH_COMPILER_VAR_800[1] = tp;____BAH_COMPILER_VAR_800[0] = "Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_801 =__Bah_multiple_concat(____BAH_COMPILER_VAR_800, 5);throwErr(&t,____BAH_COMPILER_VAR_801);
}
}

#line 1311 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1312 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(currentType, "") == 0)) {

#line 1313 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(v->type, "") == 0)) {

#line 1314 "/home/alois/Documents/bah-bah/src/parser.bah"
v->type = tp;
}

#line 1315 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1316 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((compTypes(tp,v->type)==false), 0)) {

#line 1317 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_802 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_802[4] = ".";____BAH_COMPILER_VAR_802[3] = v->type;____BAH_COMPILER_VAR_802[2] = ") as ";____BAH_COMPILER_VAR_802[1] = tp;____BAH_COMPILER_VAR_802[0] = "Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_803 =__Bah_multiple_concat(____BAH_COMPILER_VAR_802, 5);throwErr(&t,____BAH_COMPILER_VAR_803);
}
}
}
}

#line 1323 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((RAIIenabled==true)&&(t.type==TOKEN_TYPE_VAR)&&isRCPtype(tp,elems)) {

#line 1324 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ____BAH_COMPILER_VAR_804 =removeCast(t.cont);struct variable* ov = searchVar(____BAH_COMPILER_VAR_804,elems);

#line 1325 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((ov!=null)) {

#line 1326 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int k = 0;

#line 1326 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (k<len(elems->vars)); 
#line 1326 "/home/alois/Documents/bah-bah/src/parser.bah"
++k) {

#line 1327 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(elems->vars->data[k]->name, ov->name) == 0)) {

#line 1328 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_805 = len(elems->deletedVars);
    __Bah_realocate_arr(elems->deletedVars, ____BAH_COMPILER_VAR_805);
    elems->deletedVars->data[____BAH_COMPILER_VAR_805] = elems->vars->data[k];

#line 1329 "/home/alois/Documents/bah-bah/src/parser.bah"
delete(elems->vars,k);

#line 1330 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}
};
}
}

#line 1337 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "") != 0)&&(strHasPrefix(t.cont,"{")==false)) {

#line 1338 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_806 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_806[1] = t.cont;____BAH_COMPILER_VAR_806[0] = code;char * ____BAH_COMPILER_VAR_807 =__Bah_multiple_concat(____BAH_COMPILER_VAR_806, 2);code = ____BAH_COMPILER_VAR_807;

#line 1339 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((t.isOper==false)&&(RCPavailable()==true)) {

#line 1340 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* iv = searchVar(t.cont,elems);

#line 1341 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((iv!=null)&&(iv->isConst==false)) {

#line 1342 "/home/alois/Documents/bah-bah/src/parser.bah"
toVar = true;

#line 1343 "/home/alois/Documents/bah-bah/src/parser.bah"
isPointedVar = strHasPrefix(t.cont,"&");

#line 1344 "/home/alois/Documents/bah-bah/src/parser.bah"
struct cStruct* s = searchStruct(iv->type,elems);

#line 1345 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((s!=null)&&(strCount(iv->type,"*")==0)&&(s->isBinding==false)) {

#line 1346 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strCount(iv->name,"*")==0)) {

#line 1347 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_808 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_808[5] = "), 0)";____BAH_COMPILER_VAR_808[4] = iv->name;____BAH_COMPILER_VAR_808[3] = ", sizeof(";____BAH_COMPILER_VAR_808[2] = iv->name;____BAH_COMPILER_VAR_808[1] = "; RCP_scanStack(&";____BAH_COMPILER_VAR_808[0] = code;char * ____BAH_COMPILER_VAR_809 =__Bah_multiple_concat(____BAH_COMPILER_VAR_808, 6);code = ____BAH_COMPILER_VAR_809;
}

#line 1348 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1349 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string ivn = string(iv->name);

#line 1350 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((string__count(&ivn,"*")>0)) {

#line 1351 "/home/alois/Documents/bah-bah/src/parser.bah"
string__replace(&ivn,"*","");

#line 1352 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_810 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_810[4] = "), 0)";____BAH_COMPILER_VAR_810[3] = iv->name;____BAH_COMPILER_VAR_810[2] = ", sizeof(";____BAH_COMPILER_VAR_810[1] = string__str(&ivn);____BAH_COMPILER_VAR_810[0] = "; RCP_scanStack(";char * ____BAH_COMPILER_VAR_811 =__Bah_multiple_concat(____BAH_COMPILER_VAR_810, 5);char** ____BAH_COMPILER_VAR_812 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_812[1] = ____BAH_COMPILER_VAR_811;____BAH_COMPILER_VAR_812[0] = code;char * ____BAH_COMPILER_VAR_813 =__Bah_multiple_concat(____BAH_COMPILER_VAR_812, 2);code = ____BAH_COMPILER_VAR_813;
}

#line 1353 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1354 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_814 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_814[3] = ")";____BAH_COMPILER_VAR_814[2] = iv->name;____BAH_COMPILER_VAR_814[1] = "; RCP_incr(";____BAH_COMPILER_VAR_814[0] = code;char * ____BAH_COMPILER_VAR_815 =__Bah_multiple_concat(____BAH_COMPILER_VAR_814, 4);code = ____BAH_COMPILER_VAR_815;
}
}
}
}
}

#line 1360 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}

#line 1364 "/home/alois/Documents/bah-bah/src/parser.bah"
if (strHasPrefix(v->type,"[]")) {

#line 1365 "/home/alois/Documents/bah-bah/src/parser.bah"
code = parseArrayDecl(v,l,i,len(l),elems);

#line 1366 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}

#line 1368 "/home/alois/Documents/bah-bah/src/parser.bah"
isStruct = true;

#line 1369 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((i+1!=len(l)), 0)) {

#line 1370 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&l->data[i+1],"{TOKEN} not expected after struct initialization.");
}

#line 1374 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_816 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_816[1] = t.cont;____BAH_COMPILER_VAR_816[0] = code;char * ____BAH_COMPILER_VAR_817 =__Bah_multiple_concat(____BAH_COMPILER_VAR_816, 2);code = ____BAH_COMPILER_VAR_817;
}

#line 1377 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;
};

#line 1380 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((exists==true)) {

#line 1383 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* rv = getRealVar(v->name,elems);

#line 1384 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((rv!=null)&&(isStaticToken(&l->data[equalIndex+1],elems)==false)) {

#line 1385 "/home/alois/Documents/bah-bah/src/parser.bah"
rv->lastSet = elems;

#line 1386 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((l->data[equalIndex+1].type==TOKEN_TYPE_VAR)) {

#line 1387 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* vv = searchVirtVarByToken(&l->data[equalIndex+1],elems);

#line 1388 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((vv!=null)) {

#line 1389 "/home/alois/Documents/bah-bah/src/parser.bah"
rv->lastSet = vv->lastSet;
}
}
}

#line 1394 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((ft.parent!=null)) {

#line 1395 "/home/alois/Documents/bah-bah/src/parser.bah"
ft.parent->lastSet = elems;
}

#line 1397 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((currentFn!=null)) {

#line 1398 "/home/alois/Documents/bah-bah/src/parser.bah"

                struct string ____BAH_COMPILER_VAR_818 = string(v->name);
                if ((strcmp(v->name, "this") == 0)||string__hasPrefix(&____BAH_COMPILER_VAR_818,"this->")) {

#line 1399 "/home/alois/Documents/bah-bah/src/parser.bah"
currentFn->isMut = true;
}
}

#line 1402 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((strlen(code)==0), 0)) {

#line 1403 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&ft,"Cannot re-declare {TOKEN}.");
}

#line 1405 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((strlen(currentType)>0), 0)) {

#line 1406 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok st = l->data[1];

#line 1407 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_819 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_819[2] = "' to {TOKEN}.";____BAH_COMPILER_VAR_819[1] = ft.cont;____BAH_COMPILER_VAR_819[0] = "Cannot change the type of already declared var '";char * ____BAH_COMPILER_VAR_820 =__Bah_multiple_concat(____BAH_COMPILER_VAR_819, 3);throwErr(&st,____BAH_COMPILER_VAR_820);
}

#line 1409 "/home/alois/Documents/bah-bah/src/parser.bah"
char * preCode = "";

#line 1410 "/home/alois/Documents/bah-bah/src/parser.bah"
char * val = code;

#line 1411 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((isStruct==false)) {

#line 1412 "/home/alois/Documents/bah-bah/src/parser.bah"
if (isRCPpointerType(v->type)&&(isPointedVar==false)&&(RCPavailable()==true)) {

#line 1413 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string cType = getCType(v->type,elems);

#line 1414 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((toVar==true)) {

#line 1415 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((RCPselfRef(v)==false)) {

#line 1416 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_821 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_821[8] = ")";____BAH_COMPILER_VAR_821[7] = code;____BAH_COMPILER_VAR_821[6] = "*)RCP_incrIL(&";____BAH_COMPILER_VAR_821[5] = string__str(&cType);____BAH_COMPILER_VAR_821[4] = ") = *(";____BAH_COMPILER_VAR_821[3] = v->name;____BAH_COMPILER_VAR_821[2] = "*)RCP_decrIL(&";____BAH_COMPILER_VAR_821[1] = string__str(&cType);____BAH_COMPILER_VAR_821[0] = "*(";char * ____BAH_COMPILER_VAR_822 =__Bah_multiple_concat(____BAH_COMPILER_VAR_821, 9);code = ____BAH_COMPILER_VAR_822;
}

#line 1417 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1418 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* ____BAH_COMPILER_VAR_823 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_823->name = "";
____BAH_COMPILER_VAR_823->type = "";
____BAH_COMPILER_VAR_823->constVal = "";
____BAH_COMPILER_VAR_823->from = "";
struct variable* tmpV = ____BAH_COMPILER_VAR_823;

#line 1419 "/home/alois/Documents/bah-bah/src/parser.bah"
tmpV->name = genCompilerVar();

#line 1420 "/home/alois/Documents/bah-bah/src/parser.bah"
tmpV->type = v->type;

#line 1421 "/home/alois/Documents/bah-bah/src/parser.bah"
struct rope* dv = decrVar(tmpV,elems);

#line 1422 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_824 = alloca(13 * sizeof(char*));____BAH_COMPILER_VAR_824[12] = rope__toStr(dv);____BAH_COMPILER_VAR_824[11] = ");";____BAH_COMPILER_VAR_824[10] = code;____BAH_COMPILER_VAR_824[9] = "*)RCP_incrIL(&";____BAH_COMPILER_VAR_824[8] = string__str(&cType);____BAH_COMPILER_VAR_824[7] = " = *(";____BAH_COMPILER_VAR_824[6] = v->name;____BAH_COMPILER_VAR_824[5] = "; ";____BAH_COMPILER_VAR_824[4] = v->name;____BAH_COMPILER_VAR_824[3] = " = ";____BAH_COMPILER_VAR_824[2] = tmpV->name;____BAH_COMPILER_VAR_824[1] = " ";____BAH_COMPILER_VAR_824[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_825 =__Bah_multiple_concat(____BAH_COMPILER_VAR_824, 13);code = ____BAH_COMPILER_VAR_825;
}
}

#line 1424 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1425 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* ____BAH_COMPILER_VAR_826 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_826->name = "";
____BAH_COMPILER_VAR_826->type = "";
____BAH_COMPILER_VAR_826->constVal = "";
____BAH_COMPILER_VAR_826->from = "";
struct variable* tmpV = ____BAH_COMPILER_VAR_826;

#line 1426 "/home/alois/Documents/bah-bah/src/parser.bah"
tmpV->name = genCompilerVar();

#line 1427 "/home/alois/Documents/bah-bah/src/parser.bah"
tmpV->type = v->type;

#line 1428 "/home/alois/Documents/bah-bah/src/parser.bah"
struct rope* dv = decrVar(tmpV,elems);

#line 1429 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_827 = alloca(11 * sizeof(char*));____BAH_COMPILER_VAR_827[10] = rope__toStr(dv);____BAH_COMPILER_VAR_827[9] = ";";____BAH_COMPILER_VAR_827[8] = code;____BAH_COMPILER_VAR_827[7] = " = ";____BAH_COMPILER_VAR_827[6] = v->name;____BAH_COMPILER_VAR_827[5] = "; ";____BAH_COMPILER_VAR_827[4] = v->name;____BAH_COMPILER_VAR_827[3] = " = ";____BAH_COMPILER_VAR_827[2] = tmpV->name;____BAH_COMPILER_VAR_827[1] = " ";____BAH_COMPILER_VAR_827[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_828 =__Bah_multiple_concat(____BAH_COMPILER_VAR_827, 11);code = ____BAH_COMPILER_VAR_828;
}
}

#line 1431 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1432 "/home/alois/Documents/bah-bah/src/parser.bah"
struct cStruct* s = searchStruct(v->type,elems);

#line 1433 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((s!=null)&&(RCPavailable()==true)&&(RCPselfRef(v)==false)&&(s->isBinding==false)) {

#line 1434 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strCount(v->name,"*")==0)) {

#line 1435 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_829 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_829[4] = "), 1); ";____BAH_COMPILER_VAR_829[3] = v->name;____BAH_COMPILER_VAR_829[2] = ", sizeof(";____BAH_COMPILER_VAR_829[1] = v->name;____BAH_COMPILER_VAR_829[0] = "RCP_scanStack(&";char * ____BAH_COMPILER_VAR_830 =__Bah_multiple_concat(____BAH_COMPILER_VAR_829, 5);preCode = ____BAH_COMPILER_VAR_830;
}

#line 1436 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1437 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string vn = string(v->name);

#line 1438 "/home/alois/Documents/bah-bah/src/parser.bah"
string__replace(&vn,"*","");

#line 1439 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_831 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_831[4] = "), 1); ";____BAH_COMPILER_VAR_831[3] = v->name;____BAH_COMPILER_VAR_831[2] = ", sizeof(";____BAH_COMPILER_VAR_831[1] = string__str(&vn);____BAH_COMPILER_VAR_831[0] = "RCP_scanStack(";char * ____BAH_COMPILER_VAR_832 =__Bah_multiple_concat(____BAH_COMPILER_VAR_831, 5);preCode = ____BAH_COMPILER_VAR_832;
}

#line 1441 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_833 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_833[2] = code;____BAH_COMPILER_VAR_833[1] = " = ";____BAH_COMPILER_VAR_833[0] = v->name;char * ____BAH_COMPILER_VAR_834 =__Bah_multiple_concat(____BAH_COMPILER_VAR_833, 3);code = ____BAH_COMPILER_VAR_834;
}

#line 1442 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1443 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_835 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_835[2] = code;____BAH_COMPILER_VAR_835[1] = " = ";____BAH_COMPILER_VAR_835[0] = v->name;char * ____BAH_COMPILER_VAR_836 =__Bah_multiple_concat(____BAH_COMPILER_VAR_835, 3);code = ____BAH_COMPILER_VAR_836;
}
}
}

#line 1446 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1447 "/home/alois/Documents/bah-bah/src/parser.bah"
strTrim(&code);

#line 1448 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strHasPrefix(code,"{")==false)) {

#line 1449 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_837 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_837[2] = code;____BAH_COMPILER_VAR_837[1] = " = ";____BAH_COMPILER_VAR_837[0] = v->name;char * ____BAH_COMPILER_VAR_838 =__Bah_multiple_concat(____BAH_COMPILER_VAR_837, 3);code = ____BAH_COMPILER_VAR_838;
}
}

#line 1452 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((v->isArray==true)) {

#line 1453 "/home/alois/Documents/bah-bah/src/parser.bah"
code = genArrRealloc(v,preCode,val,elems);
}

#line 1454 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1455 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_839 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_839[1] = code;____BAH_COMPILER_VAR_839[0] = preCode;char * ____BAH_COMPILER_VAR_840 =__Bah_multiple_concat(____BAH_COMPILER_VAR_839, 2);code = ____BAH_COMPILER_VAR_840;
}
}

#line 1457 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1458 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(currentType, "") != 0)) {

#line 1459 "/home/alois/Documents/bah-bah/src/parser.bah"
v->type = currentType;
}

#line 1462 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strlen(code)==0)) {

#line 1463 "/home/alois/Documents/bah-bah/src/parser.bah"
v->canBeNull = true;
}

#line 1466 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string vts = string(v->type);

#line 1467 "/home/alois/Documents/bah-bah/src/parser.bah"
string__replace(&vts," ","");

#line 1468 "/home/alois/Documents/bah-bah/src/parser.bah"
v->type = string__str(&vts);

#line 1469 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((strlen(v->type)==0), 0)) {

#line 1470 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&ft,"Cannot declare {TOKEN} without a type.");
}

#line 1472 "/home/alois/Documents/bah-bah/src/parser.bah"
char * vct= null;

#line 1473 "/home/alois/Documents/bah-bah/src/parser.bah"
if (string__hasPrefix(&vts,"function(")) {

#line 1474 "/home/alois/Documents/bah-bah/src/parser.bah"
struct func* tmpfn = parseFnType(vts);

#line 1475 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string tmpfnRetCType = getCType(tmpfn->returns->type,elems);

#line 1477 "/home/alois/Documents/bah-bah/src/parser.bah"
char * tmpfnArgsCType = "";

#line 1478 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int j = 0;

#line 1478 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((j<len(tmpfn->args))) {

#line 1479 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* arg = tmpfn->args->data[j];

#line 1480 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string ct = getCType(arg->type,elems);

#line 1481 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_841 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_841[1] = string__str(&ct);____BAH_COMPILER_VAR_841[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_842 =__Bah_multiple_concat(____BAH_COMPILER_VAR_841, 2);tmpfnArgsCType = ____BAH_COMPILER_VAR_842;

#line 1482 "/home/alois/Documents/bah-bah/src/parser.bah"
j = j+1;

#line 1483 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((j<len(tmpfn->args))) {

#line 1484 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_843 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_843[1] = ",";____BAH_COMPILER_VAR_843[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_844 =__Bah_multiple_concat(____BAH_COMPILER_VAR_843, 2);tmpfnArgsCType = ____BAH_COMPILER_VAR_844;
}
};

#line 1488 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_845 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_845[5] = ")";____BAH_COMPILER_VAR_845[4] = tmpfnArgsCType;____BAH_COMPILER_VAR_845[3] = ")(";____BAH_COMPILER_VAR_845[2] = v->name;____BAH_COMPILER_VAR_845[1] = " (*";____BAH_COMPILER_VAR_845[0] = string__str(&tmpfnRetCType);char * ____BAH_COMPILER_VAR_846 =__Bah_multiple_concat(____BAH_COMPILER_VAR_845, 6);vct = ____BAH_COMPILER_VAR_846;
}

#line 1489 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1490 "/home/alois/Documents/bah-bah/src/parser.bah"
vct = setCType(v,elems);
}

#line 1492 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(code, "") != 0)&&(shouldOnlyDecl==false)) {

#line 1495 "/home/alois/Documents/bah-bah/src/parser.bah"
if (isRCPpointerType(v->type)&&(RCPavailable()==true)&&(toVar==true)&&(isPointedVar==false)) {

#line 1496 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string cType = getCType(v->type,elems);

#line 1497 "/home/alois/Documents/bah-bah/src/parser.bah"
if (isGlobal()) {

#line 1498 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_847 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_847[5] = ");\n";____BAH_COMPILER_VAR_847[4] = code;____BAH_COMPILER_VAR_847[3] = "*)RCP_incrIL(&";____BAH_COMPILER_VAR_847[2] = string__str(&cType);____BAH_COMPILER_VAR_847[1] = " = *(";____BAH_COMPILER_VAR_847[0] = v->name;char * ____BAH_COMPILER_VAR_848 =__Bah_multiple_concat(____BAH_COMPILER_VAR_847, 6);INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_848));
}

#line 1499 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1500 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_849 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_849[5] = ")";____BAH_COMPILER_VAR_849[4] = code;____BAH_COMPILER_VAR_849[3] = "*)RCP_incrIL(&";____BAH_COMPILER_VAR_849[2] = string__str(&cType);____BAH_COMPILER_VAR_849[1] = " = *(";____BAH_COMPILER_VAR_849[0] = vct;char * ____BAH_COMPILER_VAR_850 =__Bah_multiple_concat(____BAH_COMPILER_VAR_849, 6);code = ____BAH_COMPILER_VAR_850;
}
}

#line 1502 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1503 "/home/alois/Documents/bah-bah/src/parser.bah"
if (isGlobal()) {

#line 1504 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_851 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_851[3] = ";\n";____BAH_COMPILER_VAR_851[2] = code;____BAH_COMPILER_VAR_851[1] = " = ";____BAH_COMPILER_VAR_851[0] = v->name;char * ____BAH_COMPILER_VAR_852 =__Bah_multiple_concat(____BAH_COMPILER_VAR_851, 4);INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_852));
}

#line 1505 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1506 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_853 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_853[2] = code;____BAH_COMPILER_VAR_853[1] = " = ";____BAH_COMPILER_VAR_853[0] = vct;char * ____BAH_COMPILER_VAR_854 =__Bah_multiple_concat(____BAH_COMPILER_VAR_853, 3);code = ____BAH_COMPILER_VAR_854;
}
}
}

#line 1509 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1510 "/home/alois/Documents/bah-bah/src/parser.bah"
if (isRCPpointerType(v->type)&&(shouldOnlyDecl==false)) {

#line 1511 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_855 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_855[1] = "= null";____BAH_COMPILER_VAR_855[0] = vct;char * ____BAH_COMPILER_VAR_856 =__Bah_multiple_concat(____BAH_COMPILER_VAR_855, 2);code = ____BAH_COMPILER_VAR_856;
}

#line 1512 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1513 "/home/alois/Documents/bah-bah/src/parser.bah"
code = vct;
}
}

#line 1517 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((shouldOnlyDecl==true)) {

#line 1518 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_857 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_857[1] = vct;____BAH_COMPILER_VAR_857[0] = "extern ";char * ____BAH_COMPILER_VAR_858 =__Bah_multiple_concat(____BAH_COMPILER_VAR_857, 2);vct = ____BAH_COMPILER_VAR_858;
}

#line 1521 "/home/alois/Documents/bah-bah/src/parser.bah"
if (isGlobal()) {

#line 1522 "/home/alois/Documents/bah-bah/src/parser.bah"
v->isGlobal = true;
}

#line 1523 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1524 "/home/alois/Documents/bah-bah/src/parser.bah"
v->isGlobal = false;
}

#line 1526 "/home/alois/Documents/bah-bah/src/parser.bah"
v->declScope = elems;

#line 1527 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_859 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_859);
    elems->vars->data[____BAH_COMPILER_VAR_859] = v;

#line 1529 "/home/alois/Documents/bah-bah/src/parser.bah"
if (fixMeEnabled()) {

#line 1530 "/home/alois/Documents/bah-bah/src/parser.bah"
fixMeRegisterVar(v,&ft);
}

#line 1534 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* ____BAH_COMPILER_VAR_860 = v;
char ** ____BAH_COMPILER_VAR_862 = (char **)((char*)(____BAH_COMPILER_VAR_860) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_863 = __reflect(____BAH_COMPILER_VAR_862, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_864 = (char **)((char*)(____BAH_COMPILER_VAR_860) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_865 = __reflect(____BAH_COMPILER_VAR_864, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_866 = (char*)((char*)(____BAH_COMPILER_VAR_860) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_867 = __reflect(____BAH_COMPILER_VAR_866, sizeof(char), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_868 = (char **)((char*)(____BAH_COMPILER_VAR_860) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_869 = __reflect(____BAH_COMPILER_VAR_868, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_870 = (char*)((char*)(____BAH_COMPILER_VAR_860) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_871 = __reflect(____BAH_COMPILER_VAR_870, sizeof(char), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_872 = (char **)((char*)(____BAH_COMPILER_VAR_860) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_873 = __reflect(____BAH_COMPILER_VAR_872, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
void ** ____BAH_COMPILER_VAR_874 = (void **)((char*)(____BAH_COMPILER_VAR_860) + offsetof(struct variable, declScope));
struct reflectElement ____BAH_COMPILER_VAR_875 = __reflect(____BAH_COMPILER_VAR_874, sizeof(void *), "ptr", "declScope", 0, 0, 0, 0, offsetof(struct variable, declScope));
char* ____BAH_COMPILER_VAR_876 = (char*)((char*)(____BAH_COMPILER_VAR_860) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_877 = __reflect(____BAH_COMPILER_VAR_876, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));
struct rope** ____BAH_COMPILER_VAR_878 = (struct rope**)((char*)(____BAH_COMPILER_VAR_860) + offsetof(struct variable, declRope));
void ** ____BAH_COMPILER_VAR_880 = (void **)((char*)(____BAH_COMPILER_VAR_878) + offsetof(struct rope, left));
struct reflectElement ____BAH_COMPILER_VAR_881 = __reflect(____BAH_COMPILER_VAR_880, sizeof(void *), "ptr", "left", 0, 0, 0, 0, offsetof(struct rope, left));
void ** ____BAH_COMPILER_VAR_882 = (void **)((char*)(____BAH_COMPILER_VAR_878) + offsetof(struct rope, right));
struct reflectElement ____BAH_COMPILER_VAR_883 = __reflect(____BAH_COMPILER_VAR_882, sizeof(void *), "ptr", "right", 0, 0, 0, 0, offsetof(struct rope, right));
char ** ____BAH_COMPILER_VAR_884 = (char **)((char*)(____BAH_COMPILER_VAR_878) + offsetof(struct rope, str));
struct reflectElement ____BAH_COMPILER_VAR_885 = __reflect(____BAH_COMPILER_VAR_884, sizeof(char *), "cpstring", "str", 0, 0, 0, 0, offsetof(struct rope, str));
int* ____BAH_COMPILER_VAR_886 = (int*)((char*)(____BAH_COMPILER_VAR_878) + offsetof(struct rope, lCount));
struct reflectElement ____BAH_COMPILER_VAR_887 = __reflect(____BAH_COMPILER_VAR_886, sizeof(int), "int32", "lCount", 0, 0, 0, 0, offsetof(struct rope, lCount));
int* ____BAH_COMPILER_VAR_888 = (int*)((char*)(____BAH_COMPILER_VAR_878) + offsetof(struct rope, len));
struct reflectElement ____BAH_COMPILER_VAR_889 = __reflect(____BAH_COMPILER_VAR_888, sizeof(int), "int32", "len", 0, 0, 0, 0, offsetof(struct rope, len));
int* ____BAH_COMPILER_VAR_890 = (int*)((char*)(____BAH_COMPILER_VAR_878) + offsetof(struct rope, totalLen));
struct reflectElement ____BAH_COMPILER_VAR_891 = __reflect(____BAH_COMPILER_VAR_890, sizeof(int), "int32", "totalLen", 0, 0, 0, 0, offsetof(struct rope, totalLen));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_879 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_879->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_879->length = 6;
        ____BAH_COMPILER_VAR_879->data = memoryAlloc(____BAH_COMPILER_VAR_879->length * ____BAH_COMPILER_VAR_879->elemSize);
        ____BAH_COMPILER_VAR_879->data[0] = ____BAH_COMPILER_VAR_881;
____BAH_COMPILER_VAR_879->data[1] = ____BAH_COMPILER_VAR_883;
____BAH_COMPILER_VAR_879->data[2] = ____BAH_COMPILER_VAR_885;
____BAH_COMPILER_VAR_879->data[3] = ____BAH_COMPILER_VAR_887;
____BAH_COMPILER_VAR_879->data[4] = ____BAH_COMPILER_VAR_889;
____BAH_COMPILER_VAR_879->data[5] = ____BAH_COMPILER_VAR_891;
struct reflectElement ____BAH_COMPILER_VAR_892 = __reflect(____BAH_COMPILER_VAR_878, sizeof(struct rope), "rope*", "declRope", 0, 0, 1, ____BAH_COMPILER_VAR_879, offsetof(struct variable, declRope));
char* ____BAH_COMPILER_VAR_893 = (char*)((char*)(____BAH_COMPILER_VAR_860) + offsetof(struct variable, canBeNull));
struct reflectElement ____BAH_COMPILER_VAR_894 = __reflect(____BAH_COMPILER_VAR_893, sizeof(char), "bool", "canBeNull", 0, 0, 0, 0, offsetof(struct variable, canBeNull));
void ** ____BAH_COMPILER_VAR_895 = (void **)((char*)(____BAH_COMPILER_VAR_860) + offsetof(struct variable, iterScope));
struct reflectElement ____BAH_COMPILER_VAR_896 = __reflect(____BAH_COMPILER_VAR_895, sizeof(void *), "ptr", "iterScope", 0, 0, 0, 0, offsetof(struct variable, iterScope));
char* ____BAH_COMPILER_VAR_897 = (char*)((char*)(____BAH_COMPILER_VAR_860) + offsetof(struct variable, canBeReg));
struct reflectElement ____BAH_COMPILER_VAR_898 = __reflect(____BAH_COMPILER_VAR_897, sizeof(char), "bool", "canBeReg", 0, 0, 0, 0, offsetof(struct variable, canBeReg));
char* ____BAH_COMPILER_VAR_899 = (char*)((char*)(____BAH_COMPILER_VAR_860) + offsetof(struct variable, isReg));
struct reflectElement ____BAH_COMPILER_VAR_900 = __reflect(____BAH_COMPILER_VAR_899, sizeof(char), "bool", "isReg", 0, 0, 0, 0, offsetof(struct variable, isReg));
void ** ____BAH_COMPILER_VAR_901 = (void **)((char*)(____BAH_COMPILER_VAR_860) + offsetof(struct variable, lastSet));
struct reflectElement ____BAH_COMPILER_VAR_902 = __reflect(____BAH_COMPILER_VAR_901, sizeof(void *), "ptr", "lastSet", 0, 0, 0, 0, offsetof(struct variable, lastSet));
char* ____BAH_COMPILER_VAR_903 = (char*)((char*)(____BAH_COMPILER_VAR_860) + offsetof(struct variable, isArg));
struct reflectElement ____BAH_COMPILER_VAR_904 = __reflect(____BAH_COMPILER_VAR_903, sizeof(char), "bool", "isArg", 0, 0, 0, 0, offsetof(struct variable, isArg));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_861 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_861->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_861->length = 15;
        ____BAH_COMPILER_VAR_861->data = memoryAlloc(____BAH_COMPILER_VAR_861->length * ____BAH_COMPILER_VAR_861->elemSize);
        ____BAH_COMPILER_VAR_861->data[0] = ____BAH_COMPILER_VAR_863;
____BAH_COMPILER_VAR_861->data[1] = ____BAH_COMPILER_VAR_865;
____BAH_COMPILER_VAR_861->data[2] = ____BAH_COMPILER_VAR_867;
____BAH_COMPILER_VAR_861->data[3] = ____BAH_COMPILER_VAR_869;
____BAH_COMPILER_VAR_861->data[4] = ____BAH_COMPILER_VAR_871;
____BAH_COMPILER_VAR_861->data[5] = ____BAH_COMPILER_VAR_873;
____BAH_COMPILER_VAR_861->data[6] = ____BAH_COMPILER_VAR_875;
____BAH_COMPILER_VAR_861->data[7] = ____BAH_COMPILER_VAR_877;
____BAH_COMPILER_VAR_861->data[8] = ____BAH_COMPILER_VAR_892;
____BAH_COMPILER_VAR_861->data[9] = ____BAH_COMPILER_VAR_894;
____BAH_COMPILER_VAR_861->data[10] = ____BAH_COMPILER_VAR_896;
____BAH_COMPILER_VAR_861->data[11] = ____BAH_COMPILER_VAR_898;
____BAH_COMPILER_VAR_861->data[12] = ____BAH_COMPILER_VAR_900;
____BAH_COMPILER_VAR_861->data[13] = ____BAH_COMPILER_VAR_902;
____BAH_COMPILER_VAR_861->data[14] = ____BAH_COMPILER_VAR_904;
struct reflectElement ____BAH_COMPILER_VAR_905 = __reflect(____BAH_COMPILER_VAR_860, sizeof(struct variable), "variable*", "v", 0, 0, 1, ____BAH_COMPILER_VAR_861, 0);
debugPrint("var_declaration",ft.line,____BAH_COMPILER_VAR_905);

#line 1537 "/home/alois/Documents/bah-bah/src/parser.bah"
if (isGlobal()) {

#line 1538 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_906 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_906[1] = ";\n";____BAH_COMPILER_VAR_906[0] = vct;char * ____BAH_COMPILER_VAR_907 =__Bah_multiple_concat(____BAH_COMPILER_VAR_906, 2);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_907));
}
}

#line 1542 "/home/alois/Documents/bah-bah/src/parser.bah"
if (isGlobal()) {

#line 1543 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((isSubObject==false)) {

#line 1544 "/home/alois/Documents/bah-bah/src/parser.bah"
INIT = rope__add(INIT, rope(NEXT_LINE));
}

#line 1546 "/home/alois/Documents/bah-bah/src/parser.bah"
NEXT_LINE = "";
}

#line 1547 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1548 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_908 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_908[1] = ";\n";____BAH_COMPILER_VAR_908[0] = code;char * ____BAH_COMPILER_VAR_909 =__Bah_multiple_concat(____BAH_COMPILER_VAR_908, 2);struct rope* declR = rope(____BAH_COMPILER_VAR_909);

#line 1549 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((exists==false)) {

#line 1551 "/home/alois/Documents/bah-bah/src/parser.bah"
v->declRope = declR;

#line 1552 "/home/alois/Documents/bah-bah/src/parser.bah"
v->canBeReg = true;
}

#line 1554 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope__add(OUTPUT, declR);
}
};

#line 1562 "/home/alois/Documents/bah-bah/src/parser.bah"
char * getCfunctionType(struct string* cfrt,char * elemName,struct Elems* elems){

#line 1564 "/home/alois/Documents/bah-bah/src/parser.bah"
struct func* tmpfn = parseFnType(*cfrt);

#line 1565 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string tmpfnRetCType = getCType(tmpfn->returns->type,elems);

#line 1566 "/home/alois/Documents/bah-bah/src/parser.bah"
char * tmpfnArgsCType = "";

#line 1567 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int j = 0;

#line 1567 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((j<len(tmpfn->args))) {

#line 1568 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* arg = tmpfn->args->data[j];

#line 1569 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string ct = getCType(arg->type,elems);

#line 1570 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_910 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_910[1] = string__str(&ct);____BAH_COMPILER_VAR_910[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_911 =__Bah_multiple_concat(____BAH_COMPILER_VAR_910, 2);tmpfnArgsCType = ____BAH_COMPILER_VAR_911;

#line 1571 "/home/alois/Documents/bah-bah/src/parser.bah"
j = j+1;

#line 1572 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((j<len(tmpfn->args))) {

#line 1573 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_912 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_912[1] = ",";____BAH_COMPILER_VAR_912[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_913 =__Bah_multiple_concat(____BAH_COMPILER_VAR_912, 2);tmpfnArgsCType = ____BAH_COMPILER_VAR_913;
}
};

#line 1577 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_914 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_914[5] = ")";____BAH_COMPILER_VAR_914[4] = tmpfnArgsCType;____BAH_COMPILER_VAR_914[3] = ")(";____BAH_COMPILER_VAR_914[2] = elemName;____BAH_COMPILER_VAR_914[1] = " (*";____BAH_COMPILER_VAR_914[0] = string__str(&tmpfnRetCType);char * ____BAH_COMPILER_VAR_915 =__Bah_multiple_concat(____BAH_COMPILER_VAR_914, 6);return ____BAH_COMPILER_VAR_915;
};

#line 1581 "/home/alois/Documents/bah-bah/src/parser.bah"
char * parseFnHeader(char * prev,__BAH_ARR_TYPE_Tok l,long int* i,struct func* fn,struct Elems* elems){

#line 1583 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int j = *i;

#line 1584 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok ft = l->data[j];

#line 1585 "/home/alois/Documents/bah-bah/src/parser.bah"
char * tpdf = "";

#line 1586 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((ft.type!=TOKEN_TYPE_VAR), 0)) {

#line 1587 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&ft,"Cannot use {TOKEN} as function name.");
}

#line 1589 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_916 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_916[1] = ft.cont;____BAH_COMPILER_VAR_916[0] = prev;char * ____BAH_COMPILER_VAR_917 =__Bah_multiple_concat(____BAH_COMPILER_VAR_916, 2);fn->name = ____BAH_COMPILER_VAR_917;

#line 1591 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct variable*)* arguments = memoryAlloc(sizeof(array(struct variable*)));

arguments->length = 0;
arguments->elemSize = sizeof(struct variable*);

#line 1593 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_918 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_918[1] = "(";____BAH_COMPILER_VAR_918[0] = fn->name;char * ____BAH_COMPILER_VAR_919 =__Bah_multiple_concat(____BAH_COMPILER_VAR_918, 2);char * code = ____BAH_COMPILER_VAR_919;

#line 1596 "/home/alois/Documents/bah-bah/src/parser.bah"
j = j+2;

#line 1598 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = l->data[j];

#line 1599 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, ")") != 0)) {

#line 1601 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((j<len(l))) {

#line 1602 "/home/alois/Documents/bah-bah/src/parser.bah"
t = l->data[j];

#line 1603 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((t.type!=TOKEN_TYPE_VAR), 0)) {

#line 1604 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"Cannot use {TOKEN} as argument name.");
}

#line 1606 "/home/alois/Documents/bah-bah/src/parser.bah"
char * argName = t.cont;

#line 1608 "/home/alois/Documents/bah-bah/src/parser.bah"
j = j+1;

#line 1609 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((j>=len(l)), 0)) {

#line 1610 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"Cannot declare argument {TOKEN} without a type.");
}

#line 1612 "/home/alois/Documents/bah-bah/src/parser.bah"
t = l->data[j];

#line 1613 "/home/alois/Documents/bah-bah/src/parser.bah"
char * argType = t.cont;

#line 1615 "/home/alois/Documents/bah-bah/src/parser.bah"
j = j+1;

#line 1616 "/home/alois/Documents/bah-bah/src/parser.bah"
char isComa = false;

#line 1617 "/home/alois/Documents/bah-bah/src/parser.bah"
long int nbPars = 1;

#line 1618 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((j<len(l))) {

#line 1619 "/home/alois/Documents/bah-bah/src/parser.bah"
t = l->data[j];

#line 1620 "/home/alois/Documents/bah-bah/src/parser.bah"
isComa = false;

#line 1621 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, ",") != 0)) {

#line 1622 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "(") == 0)) {

#line 1623 "/home/alois/Documents/bah-bah/src/parser.bah"
nbPars = nbPars+1;
}

#line 1624 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(t.cont, ")") == 0)) {

#line 1625 "/home/alois/Documents/bah-bah/src/parser.bah"
nbPars = nbPars-1;
}

#line 1627 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, ")") == 0)&&(nbPars==0)) {

#line 1628 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}

#line 1629 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1630 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_920 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_920[1] = t.cont;____BAH_COMPILER_VAR_920[0] = argType;char * ____BAH_COMPILER_VAR_921 =__Bah_multiple_concat(____BAH_COMPILER_VAR_920, 2);argType = ____BAH_COMPILER_VAR_921;
}
}

#line 1632 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1633 "/home/alois/Documents/bah-bah/src/parser.bah"
isComa = true;

#line 1634 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}

#line 1636 "/home/alois/Documents/bah-bah/src/parser.bah"
j = j+1;
};

#line 1639 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* ____BAH_COMPILER_VAR_922 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_922->name = "";
____BAH_COMPILER_VAR_922->type = "";
____BAH_COMPILER_VAR_922->constVal = "";
____BAH_COMPILER_VAR_922->from = "";
struct variable* argument = ____BAH_COMPILER_VAR_922;

#line 1640 "/home/alois/Documents/bah-bah/src/parser.bah"
argument->name = argName;

#line 1641 "/home/alois/Documents/bah-bah/src/parser.bah"
argument->type = argType;

#line 1642 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_923 = len(arguments);
    __Bah_realocate_arr(arguments, ____BAH_COMPILER_VAR_923);
    arguments->data[____BAH_COMPILER_VAR_923] = argument;

#line 1645 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string argCType = getCType(argType,elems);

#line 1647 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string cfrt = string(argType);

#line 1648 "/home/alois/Documents/bah-bah/src/parser.bah"
char * newArgType = string__str(&argCType);

#line 1649 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((string__hasPrefix(&cfrt,"[]")==1)) {

#line 1650 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimLeft(&cfrt,2);

#line 1651 "/home/alois/Documents/bah-bah/src/parser.bah"
if (string__hasSuffix(&cfrt,"*")) {

#line 1652 "/home/alois/Documents/bah-bah/src/parser.bah"
long int nbast = string__count(&cfrt,"*");

#line 1653 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimRight(&cfrt,nbast);
}

#line 1655 "/home/alois/Documents/bah-bah/src/parser.bah"
string__replace(&cfrt,"[]","_ARR_");

#line 1656 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_924 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_924[1] = string__str(&cfrt);____BAH_COMPILER_VAR_924[0] = "__BAH_ARR_TYPE_";char * ____BAH_COMPILER_VAR_925 =__Bah_multiple_concat(____BAH_COMPILER_VAR_924, 2);newArgType = ____BAH_COMPILER_VAR_925;

#line 1657 "/home/alois/Documents/bah-bah/src/parser.bah"
array(char *)* csatd = compilerState.arrTypesDecl;

#line 1658 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((inArrayStr(newArgType,csatd)==false)) {

#line 1659 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_926 = len(csatd);
    __Bah_realocate_arr(csatd, ____BAH_COMPILER_VAR_926);
    csatd->data[____BAH_COMPILER_VAR_926] = newArgType;

#line 1660 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_927 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_927[5] = ";\n";____BAH_COMPILER_VAR_927[4] = newArgType;____BAH_COMPILER_VAR_927[3] = " ";____BAH_COMPILER_VAR_927[2] = string__str(&argCType);____BAH_COMPILER_VAR_927[1] = "typedef ";____BAH_COMPILER_VAR_927[0] = tpdf;char * ____BAH_COMPILER_VAR_928 =__Bah_multiple_concat(____BAH_COMPILER_VAR_927, 6);tpdf = ____BAH_COMPILER_VAR_928;
}
}

#line 1663 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((string__hasPrefix(&cfrt,"function(")==1)) {

#line 1664 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_929 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_929[1] = getCfunctionType(&cfrt,argName,elems);____BAH_COMPILER_VAR_929[0] = code;char * ____BAH_COMPILER_VAR_930 =__Bah_multiple_concat(____BAH_COMPILER_VAR_929, 2);code = ____BAH_COMPILER_VAR_930;
}

#line 1665 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1666 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_931 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_931[3] = argName;____BAH_COMPILER_VAR_931[2] = " ";____BAH_COMPILER_VAR_931[1] = newArgType;____BAH_COMPILER_VAR_931[0] = code;char * ____BAH_COMPILER_VAR_932 =__Bah_multiple_concat(____BAH_COMPILER_VAR_931, 4);code = ____BAH_COMPILER_VAR_932;
}

#line 1668 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((isComa==true)) {

#line 1669 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_933 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_933[1] = ",";____BAH_COMPILER_VAR_933[0] = code;char * ____BAH_COMPILER_VAR_934 =__Bah_multiple_concat(____BAH_COMPILER_VAR_933, 2);code = ____BAH_COMPILER_VAR_934;
}

#line 1670 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1671 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_935 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_935[1] = ")";____BAH_COMPILER_VAR_935[0] = code;char * ____BAH_COMPILER_VAR_936 =__Bah_multiple_concat(____BAH_COMPILER_VAR_935, 2);code = ____BAH_COMPILER_VAR_936;

#line 1672 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}

#line 1674 "/home/alois/Documents/bah-bah/src/parser.bah"
j = j+1;
};
}

#line 1676 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1677 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_937 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_937[1] = ")";____BAH_COMPILER_VAR_937[0] = code;char * ____BAH_COMPILER_VAR_938 =__Bah_multiple_concat(____BAH_COMPILER_VAR_937, 2);code = ____BAH_COMPILER_VAR_938;
}

#line 1680 "/home/alois/Documents/bah-bah/src/parser.bah"
j = j+1;

#line 1682 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* ____BAH_COMPILER_VAR_939 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_939->name = "";
____BAH_COMPILER_VAR_939->type = "";
____BAH_COMPILER_VAR_939->constVal = "";
____BAH_COMPILER_VAR_939->from = "";
struct variable* returns = ____BAH_COMPILER_VAR_939;

#line 1683 "/home/alois/Documents/bah-bah/src/parser.bah"
returns->type = "";

#line 1684 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((j<len(l))) {

#line 1685 "/home/alois/Documents/bah-bah/src/parser.bah"
t = l->data[j];

#line 1686 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "{") == 0)) {

#line 1687 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}

#line 1689 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_940 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_940[1] = t.cont;____BAH_COMPILER_VAR_940[0] = returns->type;char * ____BAH_COMPILER_VAR_941 =__Bah_multiple_concat(____BAH_COMPILER_VAR_940, 2);returns->type = ____BAH_COMPILER_VAR_941;

#line 1690 "/home/alois/Documents/bah-bah/src/parser.bah"
j = j+1;
};

#line 1692 "/home/alois/Documents/bah-bah/src/parser.bah"
if (strlen(returns->type)) {

#line 1693 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string rts = string(returns->type);

#line 1694 "/home/alois/Documents/bah-bah/src/parser.bah"
string__replace(&rts," ","");

#line 1695 "/home/alois/Documents/bah-bah/src/parser.bah"
returns->type = rts.content;
}

#line 1697 "/home/alois/Documents/bah-bah/src/parser.bah"
*i = j;

#line 1698 "/home/alois/Documents/bah-bah/src/parser.bah"
returns->name = fn->name;

#line 1699 "/home/alois/Documents/bah-bah/src/parser.bah"
fn->returns = returns;

#line 1700 "/home/alois/Documents/bah-bah/src/parser.bah"
fn->args = arguments;

#line 1702 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string fnRetType = getCType(returns->type,elems);

#line 1703 "/home/alois/Documents/bah-bah/src/parser.bah"
char * newFnRetType = string__str(&fnRetType);

#line 1705 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string cfrt = string(returns->type);

#line 1706 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((string__hasPrefix(&cfrt,"[]")==1)) {

#line 1707 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimLeft(&cfrt,2);

#line 1708 "/home/alois/Documents/bah-bah/src/parser.bah"
if (string__hasSuffix(&cfrt,"*")) {

#line 1709 "/home/alois/Documents/bah-bah/src/parser.bah"
long int nbast = string__count(&cfrt,"*");

#line 1710 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimRight(&cfrt,nbast);
}

#line 1712 "/home/alois/Documents/bah-bah/src/parser.bah"
string__replace(&cfrt,"[]","_ARR_");

#line 1713 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_942 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_942[1] = string__str(&cfrt);____BAH_COMPILER_VAR_942[0] = "__BAH_ARR_TYPE_";char * ____BAH_COMPILER_VAR_943 =__Bah_multiple_concat(____BAH_COMPILER_VAR_942, 2);newFnRetType = ____BAH_COMPILER_VAR_943;

#line 1714 "/home/alois/Documents/bah-bah/src/parser.bah"
array(char *)* csatd = compilerState.arrTypesDecl;

#line 1715 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((inArrayStr(newFnRetType,csatd)==false)) {

#line 1716 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_944 = len(csatd);
    __Bah_realocate_arr(csatd, ____BAH_COMPILER_VAR_944);
    csatd->data[____BAH_COMPILER_VAR_944] = newFnRetType;

#line 1717 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_945 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_945[5] = ";\n";____BAH_COMPILER_VAR_945[4] = newFnRetType;____BAH_COMPILER_VAR_945[3] = " ";____BAH_COMPILER_VAR_945[2] = string__str(&fnRetType);____BAH_COMPILER_VAR_945[1] = "typedef ";____BAH_COMPILER_VAR_945[0] = tpdf;char * ____BAH_COMPILER_VAR_946 =__Bah_multiple_concat(____BAH_COMPILER_VAR_945, 6);tpdf = ____BAH_COMPILER_VAR_946;
}
}

#line 1720 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_947 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_947[3] = code;____BAH_COMPILER_VAR_947[2] = " ";____BAH_COMPILER_VAR_947[1] = newFnRetType;____BAH_COMPILER_VAR_947[0] = tpdf;char * ____BAH_COMPILER_VAR_948 =__Bah_multiple_concat(____BAH_COMPILER_VAR_947, 4);code = ____BAH_COMPILER_VAR_948;

#line 1724 "/home/alois/Documents/bah-bah/src/parser.bah"
return code;
};

#line 1727 "/home/alois/Documents/bah-bah/src/parser.bah"
void parseStruct(__BAH_ARR_TYPE_Tok l,struct Elems* elems){

#line 1729 "/home/alois/Documents/bah-bah/src/parser.bah"
struct cStruct* ____BAH_COMPILER_VAR_949 = memoryAlloc(sizeof(struct cStruct));
____BAH_COMPILER_VAR_949->name = "";
____BAH_COMPILER_VAR_949->members = memoryAlloc(sizeof(array(struct structMemb*)));
            ____BAH_COMPILER_VAR_949->members->length = 0;
            ____BAH_COMPILER_VAR_949->members->elemSize = sizeof(struct structMemb*);
            ____BAH_COMPILER_VAR_949->methods = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_949->methods->length = 0;
            ____BAH_COMPILER_VAR_949->methods->elemSize = sizeof(struct func*);
            ____BAH_COMPILER_VAR_949->postCode = "";
____BAH_COMPILER_VAR_949->extendedFrom = "";
struct cStruct* s = ____BAH_COMPILER_VAR_949;

#line 1730 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct cStruct*)* structs = elems->structs;

#line 1731 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_950 = len(structs);
    __Bah_realocate_arr(structs, ____BAH_COMPILER_VAR_950);
    structs->data[____BAH_COMPILER_VAR_950] = s;

#line 1732 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct func*)* methds = s->methods;

#line 1733 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((len(l)<4), 0)) {

#line 1734 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&l->data[len(l)-1],"Cannot declare struct has such, please do 'struct <name> { <memberName>:<memberType> }'.");
}

#line 1736 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok nameToken = l->data[1];

#line 1737 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int i = 2;

#line 1738 "/home/alois/Documents/bah-bah/src/parser.bah"
char doesOutput = true;

#line 1739 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(nameToken.cont, "!") == 0)) {

#line 1740 "/home/alois/Documents/bah-bah/src/parser.bah"
nameToken = l->data[2];

#line 1741 "/home/alois/Documents/bah-bah/src/parser.bah"
i = 3;

#line 1742 "/home/alois/Documents/bah-bah/src/parser.bah"
doesOutput = false;

#line 1743 "/home/alois/Documents/bah-bah/src/parser.bah"
s->isBinding = true;
}

#line 1745 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((nameToken.type!=TOKEN_TYPE_VAR), 0)) {

#line 1746 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&nameToken,"Cannot use {TOKEN} as struct name.");
}

#line 1748 "/home/alois/Documents/bah-bah/src/parser.bah"
struct cStruct* os = searchStruct(nameToken.cont,elems);

#line 1749 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((os!=null), 0)) {

#line 1750 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&nameToken,"Struct {TOKEN} already exists.");
}

#line 1752 "/home/alois/Documents/bah-bah/src/parser.bah"
s->name = nameToken.cont;

#line 1753 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct structMemb*)* members = s->members;

#line 1754 "/home/alois/Documents/bah-bah/src/parser.bah"
currentCStruct = s;

#line 1755 "/home/alois/Documents/bah-bah/src/parser.bah"
array(char *)* allMembs = memoryAlloc(sizeof(array(char *)));

allMembs->length = 0;
allMembs->elemSize = sizeof(char *);

#line 1756 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok st = l->data[i];

#line 1757 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((st.type==TOKEN_TYPE_KEYWORD)) {

#line 1758 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(st.cont, "extend") == 0)) {

#line 1759 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 1760 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok extdSNameTk = l->data[i];

#line 1761 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 1762 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((extdSNameTk.type!=TOKEN_TYPE_VAR), 0)) {

#line 1763 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&extdSNameTk,"Cannot use {TOKEN} as struct name.");
}

#line 1765 "/home/alois/Documents/bah-bah/src/parser.bah"
struct cStruct* extdS = searchStruct(extdSNameTk.cont,elems);

#line 1766 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((extdS==null), 0)) {

#line 1767 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&extdSNameTk,"Struct {TOKEN} does not exist.");
}

#line 1769 "/home/alois/Documents/bah-bah/src/parser.bah"
s->extendedFrom = extdS->name;

#line 1770 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct structMemb*)* extdsmbs = extdS->members;

#line 1771 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int j = 0;

#line 1771 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((j<len(extdsmbs))) {

#line 1772 "/home/alois/Documents/bah-bah/src/parser.bah"
struct structMemb* em = extdsmbs->data[j];

#line 1773 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string cemt = string(em->type);

#line 1774 "/home/alois/Documents/bah-bah/src/parser.bah"
char * membDeclStr= null;

#line 1775 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((string__hasPrefix(&cemt,"function(")==1)) {

#line 1776 "/home/alois/Documents/bah-bah/src/parser.bah"
struct func* tmpfn = parseFnType(cemt);

#line 1777 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string tmpfnRetCType = getCType(tmpfn->returns->type,elems);

#line 1778 "/home/alois/Documents/bah-bah/src/parser.bah"
char * tmpfnArgsCType = "";

#line 1779 "/home/alois/Documents/bah-bah/src/parser.bah"
j = 0;

#line 1779 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((j<len(tmpfn->args))) {

#line 1780 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* arg = tmpfn->args->data[j];

#line 1781 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string ct = getCType(arg->type,elems);

#line 1782 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_951 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_951[1] = string__str(&ct);____BAH_COMPILER_VAR_951[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_952 =__Bah_multiple_concat(____BAH_COMPILER_VAR_951, 2);tmpfnArgsCType = ____BAH_COMPILER_VAR_952;

#line 1783 "/home/alois/Documents/bah-bah/src/parser.bah"
j = j+1;

#line 1784 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((j<len(tmpfn->args))) {

#line 1785 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_953 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_953[1] = ",";____BAH_COMPILER_VAR_953[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_954 =__Bah_multiple_concat(____BAH_COMPILER_VAR_953, 2);tmpfnArgsCType = ____BAH_COMPILER_VAR_954;
}
};

#line 1788 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_955 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_955[5] = ")";____BAH_COMPILER_VAR_955[4] = tmpfnArgsCType;____BAH_COMPILER_VAR_955[3] = ")(";____BAH_COMPILER_VAR_955[2] = em->name;____BAH_COMPILER_VAR_955[1] = " (*";____BAH_COMPILER_VAR_955[0] = string__str(&tmpfnRetCType);char * ____BAH_COMPILER_VAR_956 =__Bah_multiple_concat(____BAH_COMPILER_VAR_955, 6);membDeclStr = ____BAH_COMPILER_VAR_956;
}

#line 1789 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1790 "/home/alois/Documents/bah-bah/src/parser.bah"
if (isRCPpointerType(em->type)) {

#line 1791 "/home/alois/Documents/bah-bah/src/parser.bah"
s->hasRCPmemb = true;
}

#line 1793 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string membDecl = getCType(em->type,elems);

#line 1794 "/home/alois/Documents/bah-bah/src/parser.bah"
string__append(&membDecl," ");

#line 1795 "/home/alois/Documents/bah-bah/src/parser.bah"
string__append(&membDecl,em->name);

#line 1796 "/home/alois/Documents/bah-bah/src/parser.bah"
membDeclStr = membDecl.content;
}

#line 1798 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_957 = len(allMembs);
    __Bah_realocate_arr(allMembs, ____BAH_COMPILER_VAR_957);
    allMembs->data[____BAH_COMPILER_VAR_957] = membDeclStr;

#line 1799 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_958 = len(members);
    __Bah_realocate_arr(members, ____BAH_COMPILER_VAR_958);
    members->data[____BAH_COMPILER_VAR_958] = em;

#line 1800 "/home/alois/Documents/bah-bah/src/parser.bah"
j = j+1;
};
}

#line 1802 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1803 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&st,"Cannot use keyword {TOKEN} in struct declaration.");
}
}

#line 1806 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok braceTk = l->data[i];

#line 1807 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 1808 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((strcmp(braceTk.cont, "{") != 0), 0)) {

#line 1809 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&braceTk,"Cannot use {TOKEN} in struct declaration.");
}

#line 1811 "/home/alois/Documents/bah-bah/src/parser.bah"
postDeclHandle = rope("");

#line 1812 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope__add(OUTPUT, postDeclHandle);

#line 1813 "/home/alois/Documents/bah-bah/src/parser.bah"
struct rope* OOUT = OUTPUT;

#line 1814 "/home/alois/Documents/bah-bah/src/parser.bah"
char * nextLine = "";

#line 1815 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i<len(l))) {

#line 1816 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = l->data[i];

#line 1817 "/home/alois/Documents/bah-bah/src/parser.bah"
long int max = i+2;

#line 1818 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((max>=len(l)), 0)) {

#line 1819 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((t.type==TOKEN_TYPE_ENCL)&&(strcmp(t.cont, "}") == 0)) {

#line 1820 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}

#line 1822 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&l->data[len(l)-1],"Not enough argument in member declaration, ending by {TOKEN}.");
}

#line 1824 "/home/alois/Documents/bah-bah/src/parser.bah"
struct structMemb* ____BAH_COMPILER_VAR_959 = memoryAlloc(sizeof(struct structMemb));
____BAH_COMPILER_VAR_959->name = "";
____BAH_COMPILER_VAR_959->type = "";
____BAH_COMPILER_VAR_959->constVal = "";
____BAH_COMPILER_VAR_959->from = "";
____BAH_COMPILER_VAR_959->def = "";
struct structMemb* memb = ____BAH_COMPILER_VAR_959;

#line 1825 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((t.type!=TOKEN_TYPE_VAR), 0)) {

#line 1826 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"Cannot use {TOKEN} as member name.");
}

#line 1828 "/home/alois/Documents/bah-bah/src/parser.bah"
memb->name = t.cont;

#line 1829 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int ii = 0;

#line 1829 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((ii<len(members))) {

#line 1830 "/home/alois/Documents/bah-bah/src/parser.bah"
struct structMemb* m = members->data[ii];

#line 1831 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((strcmp(m->name, memb->name) == 0), 0)) {

#line 1832 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"Member {TOKEN} has already been declared.");
}

#line 1834 "/home/alois/Documents/bah-bah/src/parser.bah"
ii = ii+1;
};

#line 1836 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 1837 "/home/alois/Documents/bah-bah/src/parser.bah"
t = l->data[i];

#line 1838 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, ":") != 0)) {

#line 1839 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((strcmp(t.cont, "(") != 0), 0)) {

#line 1840 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"Member name should be followed by ':' not {TOKEN}.");
}

#line 1841 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1842 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_960 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_960[1] = "__";____BAH_COMPILER_VAR_960[0] = s->name;char * ____BAH_COMPILER_VAR_961 =__Bah_multiple_concat(____BAH_COMPILER_VAR_960, 2);char * fnPrefix = ____BAH_COMPILER_VAR_961;

#line 1843 "/home/alois/Documents/bah-bah/src/parser.bah"
struct func* ____BAH_COMPILER_VAR_962 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_962->name = "";
____BAH_COMPILER_VAR_962->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_962->args->length = 0;
            ____BAH_COMPILER_VAR_962->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_962->from = "";
____BAH_COMPILER_VAR_962->file = "";
____BAH_COMPILER_VAR_962->line = 1;
struct func* fn = ____BAH_COMPILER_VAR_962;

#line 1844 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);

#line 1845 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int j = i-1;

#line 1845 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((j<len(l))) {

#line 1846 "/home/alois/Documents/bah-bah/src/parser.bah"
t = l->data[j];

#line 1847 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "{") == 0)) {

#line 1848 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}

#line 1850 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_963 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_963);
    nl->data[____BAH_COMPILER_VAR_963] = t;

#line 1851 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((j==i)) {

#line 1852 "/home/alois/Documents/bah-bah/src/parser.bah"
t.type = TOKEN_TYPE_VAR;

#line 1853 "/home/alois/Documents/bah-bah/src/parser.bah"
t.cont = "this";

#line 1854 "/home/alois/Documents/bah-bah/src/parser.bah"
t.isValue = true;

#line 1855 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_964 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_964);
    nl->data[____BAH_COMPILER_VAR_964] = t;

#line 1857 "/home/alois/Documents/bah-bah/src/parser.bah"
t.type = TOKEN_TYPE_VAR;

#line 1858 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_965 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_965[1] = "*";____BAH_COMPILER_VAR_965[0] = s->name;char * ____BAH_COMPILER_VAR_966 =__Bah_multiple_concat(____BAH_COMPILER_VAR_965, 2);t.cont = ____BAH_COMPILER_VAR_966;

#line 1859 "/home/alois/Documents/bah-bah/src/parser.bah"
t.isValue = true;

#line 1860 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_967 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_967);
    nl->data[____BAH_COMPILER_VAR_967] = t;

#line 1862 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok nt = l->data[j+1];

#line 1863 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(nt.cont, ")") != 0)) {

#line 1864 "/home/alois/Documents/bah-bah/src/parser.bah"
t.type = TOKEN_TYPE_SYNTAX;

#line 1865 "/home/alois/Documents/bah-bah/src/parser.bah"
t.cont = ",";

#line 1866 "/home/alois/Documents/bah-bah/src/parser.bah"
t.isValue = false;

#line 1867 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_968 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_968);
    nl->data[____BAH_COMPILER_VAR_968] = t;
}
}

#line 1870 "/home/alois/Documents/bah-bah/src/parser.bah"
j = j+1;
};

#line 1872 "/home/alois/Documents/bah-bah/src/parser.bah"
--i;

#line 1874 "/home/alois/Documents/bah-bah/src/parser.bah"
long int nli = 0;

#line 1876 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ____BAH_COMPILER_VAR_969 =parseFnHeader(fnPrefix,nl,&nli,fn,elems);struct rope* code = rope(____BAH_COMPILER_VAR_969);

#line 1877 "/home/alois/Documents/bah-bah/src/parser.bah"
i = i+nli;

#line 1878 "/home/alois/Documents/bah-bah/src/parser.bah"
i = i-2;

#line 1880 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* returns = fn->returns;

#line 1881 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct variable*)* arguments = fn->args;

#line 1882 "/home/alois/Documents/bah-bah/src/parser.bah"
fn->from = s->name;

#line 1883 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((shouldOnlyDecl==true)) {

#line 1884 "/home/alois/Documents/bah-bah/src/parser.bah"
code = rope__add(code, rope(";\n"));
}

#line 1885 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1886 "/home/alois/Documents/bah-bah/src/parser.bah"
code = rope__add(code, rope("{\n"));
}

#line 1889 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Elems* fnElems = dupElems(elems);

#line 1890 "/home/alois/Documents/bah-bah/src/parser.bah"
j = 0;

#line 1890 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (j<len(arguments)); 
#line 1890 "/home/alois/Documents/bah-bah/src/parser.bah"
++j) {

#line 1891 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* a = arguments->data[j];

#line 1892 "/home/alois/Documents/bah-bah/src/parser.bah"
a->declScope = elems;

#line 1893 "/home/alois/Documents/bah-bah/src/parser.bah"
a->isArg = true;

#line 1894 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_970 = len(fnElems->vars);
    __Bah_realocate_arr(fnElems->vars, ____BAH_COMPILER_VAR_970);
    fnElems->vars->data[____BAH_COMPILER_VAR_970] = a;
};

#line 1897 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct func*)* fns = elems->fns;

#line 1898 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_971 = len(fns);
    __Bah_realocate_arr(fns, ____BAH_COMPILER_VAR_971);
    fns->data[____BAH_COMPILER_VAR_971] = fn;

#line 1900 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct Tok)* tokens = memoryAlloc(sizeof(array(struct Tok)));

tokens->length = 0;
tokens->elemSize = sizeof(struct Tok);

#line 1901 "/home/alois/Documents/bah-bah/src/parser.bah"
long int nbBraces = 1;

#line 1902 "/home/alois/Documents/bah-bah/src/parser.bah"
t = l->data[i];

#line 1903 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "{") == 0)) {

#line 1904 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;
}

#line 1906 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i<len(l))) {

#line 1907 "/home/alois/Documents/bah-bah/src/parser.bah"
t = l->data[i];

#line 1908 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "{") == 0)) {

#line 1909 "/home/alois/Documents/bah-bah/src/parser.bah"
nbBraces = nbBraces+1;
}

#line 1910 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(t.cont, "}") == 0)) {

#line 1911 "/home/alois/Documents/bah-bah/src/parser.bah"
nbBraces = nbBraces-1;
}

#line 1913 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((nbBraces==0)) {

#line 1914 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}

#line 1916 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_972 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_972);
    tokens->data[____BAH_COMPILER_VAR_972] = t;

#line 1917 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;
};

#line 1921 "/home/alois/Documents/bah-bah/src/parser.bah"
struct func* ____BAH_COMPILER_VAR_973 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_973->name = "";
____BAH_COMPILER_VAR_973->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_973->args->length = 0;
            ____BAH_COMPILER_VAR_973->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_973->from = "";
____BAH_COMPILER_VAR_973->file = "";
____BAH_COMPILER_VAR_973->line = 1;
struct func* mfn = ____BAH_COMPILER_VAR_973;

#line 1922 "/home/alois/Documents/bah-bah/src/parser.bah"
mfn->args = fn->args;

#line 1923 "/home/alois/Documents/bah-bah/src/parser.bah"
mfn->name = fn->name;

#line 1924 "/home/alois/Documents/bah-bah/src/parser.bah"
mfn->returns = fn->returns;

#line 1925 "/home/alois/Documents/bah-bah/src/parser.bah"
mfn->from = s->name;

#line 1927 "/home/alois/Documents/bah-bah/src/parser.bah"
strTrimLeft(&mfn->name,strlen(fnPrefix));

#line 1929 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_974 = len(methds);
    __Bah_realocate_arr(methds, ____BAH_COMPILER_VAR_974);
    methds->data[____BAH_COMPILER_VAR_974] = mfn;

#line 1932 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((shouldOnlyDecl==false)) {

#line 1933 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((len(tokens)==0)) {

#line 1934 "/home/alois/Documents/bah-bah/src/parser.bah"
code = rope__add(code, rope("};\n"));
}

#line 1935 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1936 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope("");

#line 1937 "/home/alois/Documents/bah-bah/src/parser.bah"
currentFn = fn;

#line 1938 "/home/alois/Documents/bah-bah/src/parser.bah"
beginRCPscope(fnElems,fn->args);

#line 1939 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Elems* ocurrFnElems = compilerState.currFnElems;

#line 1940 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.currFnElems = fnElems;

#line 1941 "/home/alois/Documents/bah-bah/src/parser.bah"
parseLines(tokens,fnElems);

#line 1942 "/home/alois/Documents/bah-bah/src/parser.bah"
OPTI_checkFuncScopeRef(fnElems);

#line 1943 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.currFnElems = ocurrFnElems;

#line 1945 "/home/alois/Documents/bah-bah/src/parser.bah"
currentFn = null;

#line 1946 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((fn->returned==false)) {

#line 1947 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((strlen(fn->returns->type)>0), 0)) {

#line 1948 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_975 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_975[2] = "' is not returned.";____BAH_COMPILER_VAR_975[1] = fn->name;____BAH_COMPILER_VAR_975[0] = "Function '";char * ____BAH_COMPILER_VAR_976 =__Bah_multiple_concat(____BAH_COMPILER_VAR_975, 3);throwErr(&l->data[len(l)-1],____BAH_COMPILER_VAR_976);
}

#line 1950 "/home/alois/Documents/bah-bah/src/parser.bah"
endRCPscope(fnElems,fn->args);

#line 1951 "/home/alois/Documents/bah-bah/src/parser.bah"
fixMeEndScope(fnElems,&tokens->data[len(tokens)-1]);
}

#line 1954 "/home/alois/Documents/bah-bah/src/parser.bah"
code = rope__add(code, rope__add(OUTPUT, rope("};\n")));
}
}

#line 1956 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1957 "/home/alois/Documents/bah-bah/src/parser.bah"
fn->isImported = true;

#line 1957 "/home/alois/Documents/bah-bah/src/parser.bah"
mfn->isImported = true;
}

#line 1960 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((doesOutput==true)) {

#line 1961 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_977 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_977[1] = rope__toStr(code);____BAH_COMPILER_VAR_977[0] = nextLine;char * ____BAH_COMPILER_VAR_978 =__Bah_multiple_concat(____BAH_COMPILER_VAR_977, 2);nextLine = ____BAH_COMPILER_VAR_978;
}

#line 1980 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 1981 "/home/alois/Documents/bah-bah/src/parser.bah"
continue;
}
}

#line 1985 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 1986 "/home/alois/Documents/bah-bah/src/parser.bah"
char * mbmType = "";

#line 1987 "/home/alois/Documents/bah-bah/src/parser.bah"
unsigned int currentLine = t.line;

#line 1988 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i<len(l))) {

#line 1989 "/home/alois/Documents/bah-bah/src/parser.bah"
t = l->data[i];

#line 1990 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "=") == 0)) {

#line 1991 "/home/alois/Documents/bah-bah/src/parser.bah"
--i;

#line 1992 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}

#line 1994 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((t.line!=currentLine)) {

#line 1995 "/home/alois/Documents/bah-bah/src/parser.bah"
--i;

#line 1996 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}

#line 1998 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_979 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_979[1] = t.cont;____BAH_COMPILER_VAR_979[0] = mbmType;char * ____BAH_COMPILER_VAR_980 =__Bah_multiple_concat(____BAH_COMPILER_VAR_979, 2);mbmType = ____BAH_COMPILER_VAR_980;

#line 1999 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;
};

#line 2002 "/home/alois/Documents/bah-bah/src/parser.bah"
memb->type = mbmType;

#line 2003 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 2004 "/home/alois/Documents/bah-bah/src/parser.bah"
t = l->data[i];

#line 2005 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((i<len(l))) {

#line 2006 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "=") == 0)) {

#line 2007 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 2008 "/home/alois/Documents/bah-bah/src/parser.bah"
t = l->data[i];

#line 2009 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((t.isValue==false), 0)) {

#line 2010 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"Cannot use {TOKEN} as default value for member.");
}

#line 2012 "/home/alois/Documents/bah-bah/src/parser.bah"
char * tt = getTypeFromToken(&t,true,elems);

#line 2013 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((compTypes(tt,memb->type)==false), 0)) {

#line 2014 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_981 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_981[4] = " for member.";____BAH_COMPILER_VAR_981[3] = memb->type;____BAH_COMPILER_VAR_981[2] = ") as ";____BAH_COMPILER_VAR_981[1] = tt;____BAH_COMPILER_VAR_981[0] = "Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_982 =__Bah_multiple_concat(____BAH_COMPILER_VAR_981, 5);throwErr(&t,____BAH_COMPILER_VAR_982);
}

#line 2016 "/home/alois/Documents/bah-bah/src/parser.bah"
memb->def = t.cont;
}

#line 2018 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 2019 "/home/alois/Documents/bah-bah/src/parser.bah"
--i;
}
}

#line 2022 "/home/alois/Documents/bah-bah/src/parser.bah"
if (isRCPpointerType(memb->type)) {

#line 2023 "/home/alois/Documents/bah-bah/src/parser.bah"
s->hasRCPmemb = true;
}

#line 2025 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_983 = len(members);
    __Bah_realocate_arr(members, ____BAH_COMPILER_VAR_983);
    members->data[____BAH_COMPILER_VAR_983] = memb;

#line 2027 "/home/alois/Documents/bah-bah/src/parser.bah"
char * membDeclStr= null;

#line 2028 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string cmt = string(memb->type);

#line 2029 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((string__hasPrefix(&cmt,"function(")==1)) {

#line 2030 "/home/alois/Documents/bah-bah/src/parser.bah"
struct func* tmpfn = parseFnType(cmt);

#line 2031 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string tmpfnRetCType = getCType(tmpfn->returns->type,elems);

#line 2032 "/home/alois/Documents/bah-bah/src/parser.bah"
char * tmpfnArgsCType = "";

#line 2033 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int j = 0;

#line 2033 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((j<len(tmpfn->args))) {

#line 2034 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* arg = tmpfn->args->data[j];

#line 2035 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string ct = getCType(arg->type,elems);

#line 2036 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_984 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_984[1] = string__str(&ct);____BAH_COMPILER_VAR_984[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_985 =__Bah_multiple_concat(____BAH_COMPILER_VAR_984, 2);tmpfnArgsCType = ____BAH_COMPILER_VAR_985;

#line 2037 "/home/alois/Documents/bah-bah/src/parser.bah"
j = j+1;

#line 2038 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((j<len(tmpfn->args))) {

#line 2039 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_986 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_986[1] = ",";____BAH_COMPILER_VAR_986[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_987 =__Bah_multiple_concat(____BAH_COMPILER_VAR_986, 2);tmpfnArgsCType = ____BAH_COMPILER_VAR_987;
}
};

#line 2042 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_988 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_988[5] = ")";____BAH_COMPILER_VAR_988[4] = tmpfnArgsCType;____BAH_COMPILER_VAR_988[3] = ")(";____BAH_COMPILER_VAR_988[2] = memb->name;____BAH_COMPILER_VAR_988[1] = " (*";____BAH_COMPILER_VAR_988[0] = string__str(&tmpfnRetCType);char * ____BAH_COMPILER_VAR_989 =__Bah_multiple_concat(____BAH_COMPILER_VAR_988, 6);membDeclStr = ____BAH_COMPILER_VAR_989;
}

#line 2043 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 2044 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string membDecl = getCType(memb->type,elems);

#line 2045 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_990 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_990[1] = memb->name;____BAH_COMPILER_VAR_990[0] = " ";char * ____BAH_COMPILER_VAR_991 =__Bah_multiple_concat(____BAH_COMPILER_VAR_990, 2);string__append(&membDecl,____BAH_COMPILER_VAR_991);

#line 2046 "/home/alois/Documents/bah-bah/src/parser.bah"
membDeclStr = string__str(&membDecl);
}

#line 2048 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_992 = len(allMembs);
    __Bah_realocate_arr(allMembs, ____BAH_COMPILER_VAR_992);
    allMembs->data[____BAH_COMPILER_VAR_992] = membDeclStr;

#line 2049 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;
};

#line 2051 "/home/alois/Documents/bah-bah/src/parser.bah"
s->members = members;

#line 2052 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((doesOutput==true)) {

#line 2053 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = OOUT;

#line 2054 "/home/alois/Documents/bah-bah/src/parser.bah"
NEXT_LINE = nextLine;

#line 2055 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_993 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_993[2] = " {\n";____BAH_COMPILER_VAR_993[1] = s->name;____BAH_COMPILER_VAR_993[0] = "struct ";char * ____BAH_COMPILER_VAR_994 =__Bah_multiple_concat(____BAH_COMPILER_VAR_993, 3);struct rope* code = rope(____BAH_COMPILER_VAR_994);

#line 2056 "/home/alois/Documents/bah-bah/src/parser.bah"
i = 0;

#line 2056 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i<len(allMembs))) {

#line 2057 "/home/alois/Documents/bah-bah/src/parser.bah"
char * m = allMembs->data[i];

#line 2058 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_995 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_995[1] = ";\n";____BAH_COMPILER_VAR_995[0] = m;char * ____BAH_COMPILER_VAR_996 =__Bah_multiple_concat(____BAH_COMPILER_VAR_995, 2);code = rope__add(code, rope(____BAH_COMPILER_VAR_996));

#line 2059 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;
};

#line 2061 "/home/alois/Documents/bah-bah/src/parser.bah"
code = rope__add(code, rope("};\n"));

#line 2062 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope__add(OUTPUT, code);

#line 2063 "/home/alois/Documents/bah-bah/src/parser.bah"
char * phd = rope__toStr(postDeclHandle);

#line 2064 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT->totalLen = OUTPUT->totalLen+ropeSet(postDeclHandle,"");

#line 2065 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_997 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_997[1] = phd;____BAH_COMPILER_VAR_997[0] = NEXT_LINE;char * ____BAH_COMPILER_VAR_998 =__Bah_multiple_concat(____BAH_COMPILER_VAR_997, 2);NEXT_LINE = ____BAH_COMPILER_VAR_998;
}

#line 2068 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((debug==true)) {

#line 2070 "/home/alois/Documents/bah-bah/src/parser.bah"
struct debugStruct* ____BAH_COMPILER_VAR_999 = memoryAlloc(sizeof(struct debugStruct));
____BAH_COMPILER_VAR_999->membs = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_999->membs->length = 0;
            ____BAH_COMPILER_VAR_999->membs->elemSize = sizeof(struct variable*);
            struct debugStruct* ds = ____BAH_COMPILER_VAR_999;

#line 2071 "/home/alois/Documents/bah-bah/src/parser.bah"
ds->name = s->name;

#line 2072 "/home/alois/Documents/bah-bah/src/parser.bah"
i = 0;

#line 2072 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i<len(s->members))) {

#line 2073 "/home/alois/Documents/bah-bah/src/parser.bah"
struct structMemb* m = s->members->data[i];

#line 2074 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* ____BAH_COMPILER_VAR_1000 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1000->name = "";
____BAH_COMPILER_VAR_1000->type = "";
____BAH_COMPILER_VAR_1000->constVal = "";
____BAH_COMPILER_VAR_1000->from = "";
struct variable* mv = ____BAH_COMPILER_VAR_1000;

#line 2075 "/home/alois/Documents/bah-bah/src/parser.bah"
mv->name = m->name;

#line 2076 "/home/alois/Documents/bah-bah/src/parser.bah"
mv->type = m->type;

#line 2077 "/home/alois/Documents/bah-bah/src/parser.bah"
mv->isConst = false;

#line 2078 "/home/alois/Documents/bah-bah/src/parser.bah"
mv->isArray = m->isArray;

#line 2079 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1001 = i;
    __Bah_realocate_arr(ds->membs, ____BAH_COMPILER_VAR_1001);
    ds->membs->data[____BAH_COMPILER_VAR_1001] = mv;

#line 2080 "/home/alois/Documents/bah-bah/src/parser.bah"
i = i+1;
};

#line 2083 "/home/alois/Documents/bah-bah/src/parser.bah"
struct debugStruct* ____BAH_COMPILER_VAR_1002 = ds;
char ** ____BAH_COMPILER_VAR_1004 = (char **)((char*)(____BAH_COMPILER_VAR_1002) + offsetof(struct debugStruct, name));
struct reflectElement ____BAH_COMPILER_VAR_1005 = __reflect(____BAH_COMPILER_VAR_1004, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct debugStruct, name));
array(struct variable*)** ____BAH_COMPILER_VAR_1006 = (array(struct variable*)**)((char*)(____BAH_COMPILER_VAR_1002) + offsetof(struct debugStruct, membs));
struct variable** ____BAH_COMPILER_VAR_1007 = 0;
char ** ____BAH_COMPILER_VAR_1009 = (char **)((char*)(____BAH_COMPILER_VAR_1007) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_1010 = __reflect(____BAH_COMPILER_VAR_1009, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_1011 = (char **)((char*)(____BAH_COMPILER_VAR_1007) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_1012 = __reflect(____BAH_COMPILER_VAR_1011, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_1013 = (char*)((char*)(____BAH_COMPILER_VAR_1007) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_1014 = __reflect(____BAH_COMPILER_VAR_1013, sizeof(char), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_1015 = (char **)((char*)(____BAH_COMPILER_VAR_1007) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_1016 = __reflect(____BAH_COMPILER_VAR_1015, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_1017 = (char*)((char*)(____BAH_COMPILER_VAR_1007) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_1018 = __reflect(____BAH_COMPILER_VAR_1017, sizeof(char), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_1019 = (char **)((char*)(____BAH_COMPILER_VAR_1007) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_1020 = __reflect(____BAH_COMPILER_VAR_1019, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
void ** ____BAH_COMPILER_VAR_1021 = (void **)((char*)(____BAH_COMPILER_VAR_1007) + offsetof(struct variable, declScope));
struct reflectElement ____BAH_COMPILER_VAR_1022 = __reflect(____BAH_COMPILER_VAR_1021, sizeof(void *), "ptr", "declScope", 0, 0, 0, 0, offsetof(struct variable, declScope));
char* ____BAH_COMPILER_VAR_1023 = (char*)((char*)(____BAH_COMPILER_VAR_1007) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_1024 = __reflect(____BAH_COMPILER_VAR_1023, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));
struct rope** ____BAH_COMPILER_VAR_1025 = (struct rope**)((char*)(____BAH_COMPILER_VAR_1007) + offsetof(struct variable, declRope));
void ** ____BAH_COMPILER_VAR_1027 = (void **)((char*)(____BAH_COMPILER_VAR_1025) + offsetof(struct rope, left));
struct reflectElement ____BAH_COMPILER_VAR_1028 = __reflect(____BAH_COMPILER_VAR_1027, sizeof(void *), "ptr", "left", 0, 0, 0, 0, offsetof(struct rope, left));
void ** ____BAH_COMPILER_VAR_1029 = (void **)((char*)(____BAH_COMPILER_VAR_1025) + offsetof(struct rope, right));
struct reflectElement ____BAH_COMPILER_VAR_1030 = __reflect(____BAH_COMPILER_VAR_1029, sizeof(void *), "ptr", "right", 0, 0, 0, 0, offsetof(struct rope, right));
char ** ____BAH_COMPILER_VAR_1031 = (char **)((char*)(____BAH_COMPILER_VAR_1025) + offsetof(struct rope, str));
struct reflectElement ____BAH_COMPILER_VAR_1032 = __reflect(____BAH_COMPILER_VAR_1031, sizeof(char *), "cpstring", "str", 0, 0, 0, 0, offsetof(struct rope, str));
int* ____BAH_COMPILER_VAR_1033 = (int*)((char*)(____BAH_COMPILER_VAR_1025) + offsetof(struct rope, lCount));
struct reflectElement ____BAH_COMPILER_VAR_1034 = __reflect(____BAH_COMPILER_VAR_1033, sizeof(int), "int32", "lCount", 0, 0, 0, 0, offsetof(struct rope, lCount));
int* ____BAH_COMPILER_VAR_1035 = (int*)((char*)(____BAH_COMPILER_VAR_1025) + offsetof(struct rope, len));
struct reflectElement ____BAH_COMPILER_VAR_1036 = __reflect(____BAH_COMPILER_VAR_1035, sizeof(int), "int32", "len", 0, 0, 0, 0, offsetof(struct rope, len));
int* ____BAH_COMPILER_VAR_1037 = (int*)((char*)(____BAH_COMPILER_VAR_1025) + offsetof(struct rope, totalLen));
struct reflectElement ____BAH_COMPILER_VAR_1038 = __reflect(____BAH_COMPILER_VAR_1037, sizeof(int), "int32", "totalLen", 0, 0, 0, 0, offsetof(struct rope, totalLen));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_1026 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_1026->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_1026->length = 6;
        ____BAH_COMPILER_VAR_1026->data = memoryAlloc(____BAH_COMPILER_VAR_1026->length * ____BAH_COMPILER_VAR_1026->elemSize);
        ____BAH_COMPILER_VAR_1026->data[0] = ____BAH_COMPILER_VAR_1028;
____BAH_COMPILER_VAR_1026->data[1] = ____BAH_COMPILER_VAR_1030;
____BAH_COMPILER_VAR_1026->data[2] = ____BAH_COMPILER_VAR_1032;
____BAH_COMPILER_VAR_1026->data[3] = ____BAH_COMPILER_VAR_1034;
____BAH_COMPILER_VAR_1026->data[4] = ____BAH_COMPILER_VAR_1036;
____BAH_COMPILER_VAR_1026->data[5] = ____BAH_COMPILER_VAR_1038;
struct reflectElement ____BAH_COMPILER_VAR_1039 = __reflect(____BAH_COMPILER_VAR_1025, sizeof(struct rope), "rope*", "declRope", 0, 0, 1, ____BAH_COMPILER_VAR_1026, offsetof(struct variable, declRope));
char* ____BAH_COMPILER_VAR_1040 = (char*)((char*)(____BAH_COMPILER_VAR_1007) + offsetof(struct variable, canBeNull));
struct reflectElement ____BAH_COMPILER_VAR_1041 = __reflect(____BAH_COMPILER_VAR_1040, sizeof(char), "bool", "canBeNull", 0, 0, 0, 0, offsetof(struct variable, canBeNull));
void ** ____BAH_COMPILER_VAR_1042 = (void **)((char*)(____BAH_COMPILER_VAR_1007) + offsetof(struct variable, iterScope));
struct reflectElement ____BAH_COMPILER_VAR_1043 = __reflect(____BAH_COMPILER_VAR_1042, sizeof(void *), "ptr", "iterScope", 0, 0, 0, 0, offsetof(struct variable, iterScope));
char* ____BAH_COMPILER_VAR_1044 = (char*)((char*)(____BAH_COMPILER_VAR_1007) + offsetof(struct variable, canBeReg));
struct reflectElement ____BAH_COMPILER_VAR_1045 = __reflect(____BAH_COMPILER_VAR_1044, sizeof(char), "bool", "canBeReg", 0, 0, 0, 0, offsetof(struct variable, canBeReg));
char* ____BAH_COMPILER_VAR_1046 = (char*)((char*)(____BAH_COMPILER_VAR_1007) + offsetof(struct variable, isReg));
struct reflectElement ____BAH_COMPILER_VAR_1047 = __reflect(____BAH_COMPILER_VAR_1046, sizeof(char), "bool", "isReg", 0, 0, 0, 0, offsetof(struct variable, isReg));
void ** ____BAH_COMPILER_VAR_1048 = (void **)((char*)(____BAH_COMPILER_VAR_1007) + offsetof(struct variable, lastSet));
struct reflectElement ____BAH_COMPILER_VAR_1049 = __reflect(____BAH_COMPILER_VAR_1048, sizeof(void *), "ptr", "lastSet", 0, 0, 0, 0, offsetof(struct variable, lastSet));
char* ____BAH_COMPILER_VAR_1050 = (char*)((char*)(____BAH_COMPILER_VAR_1007) + offsetof(struct variable, isArg));
struct reflectElement ____BAH_COMPILER_VAR_1051 = __reflect(____BAH_COMPILER_VAR_1050, sizeof(char), "bool", "isArg", 0, 0, 0, 0, offsetof(struct variable, isArg));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_1008 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_1008->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_1008->length = 15;
        ____BAH_COMPILER_VAR_1008->data = memoryAlloc(____BAH_COMPILER_VAR_1008->length * ____BAH_COMPILER_VAR_1008->elemSize);
        ____BAH_COMPILER_VAR_1008->data[0] = ____BAH_COMPILER_VAR_1010;
____BAH_COMPILER_VAR_1008->data[1] = ____BAH_COMPILER_VAR_1012;
____BAH_COMPILER_VAR_1008->data[2] = ____BAH_COMPILER_VAR_1014;
____BAH_COMPILER_VAR_1008->data[3] = ____BAH_COMPILER_VAR_1016;
____BAH_COMPILER_VAR_1008->data[4] = ____BAH_COMPILER_VAR_1018;
____BAH_COMPILER_VAR_1008->data[5] = ____BAH_COMPILER_VAR_1020;
____BAH_COMPILER_VAR_1008->data[6] = ____BAH_COMPILER_VAR_1022;
____BAH_COMPILER_VAR_1008->data[7] = ____BAH_COMPILER_VAR_1024;
____BAH_COMPILER_VAR_1008->data[8] = ____BAH_COMPILER_VAR_1039;
____BAH_COMPILER_VAR_1008->data[9] = ____BAH_COMPILER_VAR_1041;
____BAH_COMPILER_VAR_1008->data[10] = ____BAH_COMPILER_VAR_1043;
____BAH_COMPILER_VAR_1008->data[11] = ____BAH_COMPILER_VAR_1045;
____BAH_COMPILER_VAR_1008->data[12] = ____BAH_COMPILER_VAR_1047;
____BAH_COMPILER_VAR_1008->data[13] = ____BAH_COMPILER_VAR_1049;
____BAH_COMPILER_VAR_1008->data[14] = ____BAH_COMPILER_VAR_1051;
struct reflectElement ____BAH_COMPILER_VAR_1052 = __reflect(____BAH_COMPILER_VAR_1007, sizeof(struct variable), "variable*", "", 0, 0, 1, ____BAH_COMPILER_VAR_1008, 0);

        struct reflectElement ____BAH_COMPILER_VAR_1053 = ____BAH_COMPILER_VAR_1052;
        struct reflectElement ____BAH_COMPILER_VAR_1054 = __reflect(____BAH_COMPILER_VAR_1006, sizeof(array(struct variable*)*), "[]variable*", "membs", 1, &____BAH_COMPILER_VAR_1053, 0, 0, offsetof(struct debugStruct, membs));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_1003 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_1003->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_1003->length = 2;
        ____BAH_COMPILER_VAR_1003->data = memoryAlloc(____BAH_COMPILER_VAR_1003->length * ____BAH_COMPILER_VAR_1003->elemSize);
        ____BAH_COMPILER_VAR_1003->data[0] = ____BAH_COMPILER_VAR_1005;
____BAH_COMPILER_VAR_1003->data[1] = ____BAH_COMPILER_VAR_1054;
struct reflectElement ____BAH_COMPILER_VAR_1055 = __reflect(____BAH_COMPILER_VAR_1002, sizeof(struct debugStruct), "debugStruct*", "ds", 0, 0, 1, ____BAH_COMPILER_VAR_1003, 0);
debugPrint("struct_declare",nameToken.line,____BAH_COMPILER_VAR_1055);
}
};

#line 2089 "/home/alois/Documents/bah-bah/src/parser.bah"
void parseDefine(__BAH_ARR_TYPE_Tok l,struct Elems* elems){

#line 2091 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((len(l)<3), 0)) {

#line 2092 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&l->data[len(l)-1],"Invalid usage of define, cannot end on {TOKEN}.");
}

#line 2095 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok ft = l->data[1];

#line 2096 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok st = l->data[2];

#line 2098 "/home/alois/Documents/bah-bah/src/parser.bah"
long int i = 1;

#line 2099 "/home/alois/Documents/bah-bah/src/parser.bah"
char doesOutput = true;

#line 2100 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(ft.cont, "!") == 0)) {

#line 2101 "/home/alois/Documents/bah-bah/src/parser.bah"
ft = l->data[2];

#line 2102 "/home/alois/Documents/bah-bah/src/parser.bah"
st = l->data[3];

#line 2103 "/home/alois/Documents/bah-bah/src/parser.bah"
i = 2;

#line 2104 "/home/alois/Documents/bah-bah/src/parser.bah"
doesOutput = false;
}

#line 2107 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(st.cont, "(") == 0)) {

#line 2109 "/home/alois/Documents/bah-bah/src/parser.bah"
struct func* ____BAH_COMPILER_VAR_1056 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_1056->name = "";
____BAH_COMPILER_VAR_1056->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_1056->args->length = 0;
            ____BAH_COMPILER_VAR_1056->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_1056->from = "";
____BAH_COMPILER_VAR_1056->file = "";
____BAH_COMPILER_VAR_1056->line = 1;
struct func* fn = ____BAH_COMPILER_VAR_1056;

#line 2110 "/home/alois/Documents/bah-bah/src/parser.bah"
char * code = parseFnHeader("",l,&i,fn,elems);

#line 2111 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct func*)* fns = elems->fns;

#line 2112 "/home/alois/Documents/bah-bah/src/parser.bah"
fn->isBinding = true;

#line 2113 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1057 = len(fns);
    __Bah_realocate_arr(fns, ____BAH_COMPILER_VAR_1057);
    fns->data[____BAH_COMPILER_VAR_1057] = fn;

#line 2114 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((doesOutput==true)) {

#line 2115 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1058 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1058[1] = ";\n";____BAH_COMPILER_VAR_1058[0] = code;char * ____BAH_COMPILER_VAR_1059 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1058, 2);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1059));
}
}

#line 2118 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 2119 "/home/alois/Documents/bah-bah/src/parser.bah"
char * tp = "";

#line 2120 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 2120 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<len(l)); 
#line 2120 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 2121 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = l->data[i];

#line 2122 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1060 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1060[1] = t.cont;____BAH_COMPILER_VAR_1060[0] = tp;char * ____BAH_COMPILER_VAR_1061 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1060, 2);tp = ____BAH_COMPILER_VAR_1061;
};

#line 2124 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((ft.type!=TOKEN_TYPE_VAR), 0)) {

#line 2125 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&ft,"Cannot use {TOKEN} as new type name.");
}

#line 2127 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string cTypeNewType = getCType(tp,elems);

#line 2128 "/home/alois/Documents/bah-bah/src/parser.bah"
char * cTypeNewTypeStr = string__str(&cTypeNewType);

#line 2129 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((doesOutput==true)) {

#line 2130 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1062 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1062[4] = ";\n";____BAH_COMPILER_VAR_1062[3] = ft.cont;____BAH_COMPILER_VAR_1062[2] = " ";____BAH_COMPILER_VAR_1062[1] = cTypeNewTypeStr;____BAH_COMPILER_VAR_1062[0] = "typedef ";char * ____BAH_COMPILER_VAR_1063 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1062, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1063));
}

#line 2133 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((debug==true)) {

#line 2134 "/home/alois/Documents/bah-bah/src/parser.bah"
struct debugType* ____BAH_COMPILER_VAR_1064 = memoryAlloc(sizeof(struct debugType));
struct debugType* dt = ____BAH_COMPILER_VAR_1064;

#line 2135 "/home/alois/Documents/bah-bah/src/parser.bah"
dt->name = ft.cont;

#line 2136 "/home/alois/Documents/bah-bah/src/parser.bah"
dt->refers = tp;

#line 2137 "/home/alois/Documents/bah-bah/src/parser.bah"
struct debugType* ____BAH_COMPILER_VAR_1065 = dt;
char ** ____BAH_COMPILER_VAR_1067 = (char **)((char*)(____BAH_COMPILER_VAR_1065) + offsetof(struct debugType, name));
struct reflectElement ____BAH_COMPILER_VAR_1068 = __reflect(____BAH_COMPILER_VAR_1067, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct debugType, name));
char ** ____BAH_COMPILER_VAR_1069 = (char **)((char*)(____BAH_COMPILER_VAR_1065) + offsetof(struct debugType, refers));
struct reflectElement ____BAH_COMPILER_VAR_1070 = __reflect(____BAH_COMPILER_VAR_1069, sizeof(char *), "cpstring", "refers", 0, 0, 0, 0, offsetof(struct debugType, refers));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_1066 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_1066->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_1066->length = 2;
        ____BAH_COMPILER_VAR_1066->data = memoryAlloc(____BAH_COMPILER_VAR_1066->length * ____BAH_COMPILER_VAR_1066->elemSize);
        ____BAH_COMPILER_VAR_1066->data[0] = ____BAH_COMPILER_VAR_1068;
____BAH_COMPILER_VAR_1066->data[1] = ____BAH_COMPILER_VAR_1070;
struct reflectElement ____BAH_COMPILER_VAR_1071 = __reflect(____BAH_COMPILER_VAR_1065, sizeof(struct debugType), "debugType*", "dt", 0, 0, 1, ____BAH_COMPILER_VAR_1066, 0);
debugPrint("type_declare",ft.line,____BAH_COMPILER_VAR_1071);
}

#line 2140 "/home/alois/Documents/bah-bah/src/parser.bah"
array(char *)* tps = elems->types;

#line 2141 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1072 = len(tps);
    __Bah_realocate_arr(tps, ____BAH_COMPILER_VAR_1072);
    tps->data[____BAH_COMPILER_VAR_1072] = ft.cont;
}
};

#line 2146 "/home/alois/Documents/bah-bah/src/parser.bah"
void parseClib(__BAH_ARR_TYPE_Tok line){

#line 2148 "/home/alois/Documents/bah-bah/src/parser.bah"
array(char *)* clibs = compilerState.cLibs;

#line 2150 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int i = 1;

#line 2150 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i<len(line))) {

#line 2151 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = line->data[i];

#line 2152 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((t.type!=TOKEN_TYPE_STR), 0)) {

#line 2153 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"Cannot use {TOKEN} as C library name.");
}

#line 2156 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string cc = string(t.cont);

#line 2157 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimLeft(&cc,1);

#line 2158 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimRight(&cc,1);

#line 2159 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ccstr = string__str(&cc);

#line 2161 "/home/alois/Documents/bah-bah/src/parser.bah"
char found = false;

#line 2162 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int j = 0;

#line 2162 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((j<len(clibs))) {

#line 2163 "/home/alois/Documents/bah-bah/src/parser.bah"
char * l = clibs->data[j];

#line 2164 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(l, ccstr) == 0)) {

#line 2165 "/home/alois/Documents/bah-bah/src/parser.bah"
found = true;

#line 2166 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}

#line 2168 "/home/alois/Documents/bah-bah/src/parser.bah"
j = j+1;
};

#line 2170 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((found==true)) {

#line 2171 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 2172 "/home/alois/Documents/bah-bah/src/parser.bah"
continue;
}

#line 2174 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1073 = len(clibs);
    __Bah_realocate_arr(clibs, ____BAH_COMPILER_VAR_1073);
    clibs->data[____BAH_COMPILER_VAR_1073] = ccstr;

#line 2176 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;
};
};

#line 2181 "/home/alois/Documents/bah-bah/src/parser.bah"
void parseConst(__BAH_ARR_TYPE_Tok l,struct Elems* elems){

#line 2182 "/home/alois/Documents/bah-bah/src/parser.bah"
l = parseCast(l,elems,true);

#line 2183 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((len(l)!=4), 0)) {

#line 2184 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&l->data[0],"Invalid usage of {TOKEN}, must be 'const <constName> = <constValue>'. ");
}

#line 2186 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok vart = l->data[1];

#line 2187 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok equt = l->data[2];

#line 2188 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok valt = l->data[3];

#line 2189 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((vart.type!=TOKEN_TYPE_VAR), 0)) {

#line 2190 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&vart,"Cannot take {TOKEN} as const name.");
}

#line 2192 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((strcmp(equt.cont, "=") != 0), 0)) {

#line 2193 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&equt,"Expected '=' not {TOKEN}.");
}

#line 2195 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((valt.isValue==false), 0)) {

#line 2196 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&equt,"Must be a value, not {TOKEN}.");
}

#line 2199 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((valt.type==TOKEN_TYPE_VAR)) {

#line 2200 "/home/alois/Documents/bah-bah/src/parser.bah"
struct func* fn = searchFunc(valt.cont,elems,true);

#line 2201 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((fn!=null)) {

#line 2202 "/home/alois/Documents/bah-bah/src/parser.bah"
fn->used = true;
}
}

#line 2206 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* ____BAH_COMPILER_VAR_1074 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1074->name = "";
____BAH_COMPILER_VAR_1074->type = "";
____BAH_COMPILER_VAR_1074->constVal = "";
____BAH_COMPILER_VAR_1074->from = "";
struct variable* v = ____BAH_COMPILER_VAR_1074;

#line 2208 "/home/alois/Documents/bah-bah/src/parser.bah"
if (isGlobal()) {

#line 2209 "/home/alois/Documents/bah-bah/src/parser.bah"
v->isGlobal = true;
}

#line 2212 "/home/alois/Documents/bah-bah/src/parser.bah"
v->isConst = true;

#line 2213 "/home/alois/Documents/bah-bah/src/parser.bah"
v->constVal = valt.cont;

#line 2214 "/home/alois/Documents/bah-bah/src/parser.bah"
v->name = vart.cont;

#line 2215 "/home/alois/Documents/bah-bah/src/parser.bah"
v->type = getTypeFromToken(&valt,true,elems);

#line 2216 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct variable*)* vars = elems->vars;

#line 2217 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1075 = len(vars);
    __Bah_realocate_arr(vars, ____BAH_COMPILER_VAR_1075);
    vars->data[____BAH_COMPILER_VAR_1075] = v;

#line 2219 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((valt.type==TOKEN_TYPE_STR)) {

#line 2220 "/home/alois/Documents/bah-bah/src/parser.bah"
valt.cont = strLitteralToBahStr(valt.cont);
}

#line 2223 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1076 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1076[4] = "\n";____BAH_COMPILER_VAR_1076[3] = valt.cont;____BAH_COMPILER_VAR_1076[2] = " ";____BAH_COMPILER_VAR_1076[1] = v->name;____BAH_COMPILER_VAR_1076[0] = "#define ";char * ____BAH_COMPILER_VAR_1077 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1076, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1077));
};

#line 2229 "/home/alois/Documents/bah-bah/src/parser.bah"
void parseReturn(__BAH_ARR_TYPE_Tok l,struct Elems* elems){

#line 2231 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((len(l)>2), 0)) {

#line 2232 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&l->data[0],"Invalid usage of {TOKEN}, must be 'return <returnValue>'");
}

#line 2234 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((currentFn==null), 0)) {

#line 2235 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&l->data[0],"Cannot return a value outside of a function.");
}

#line 2237 "/home/alois/Documents/bah-bah/src/parser.bah"
char * rv = "";

#line 2238 "/home/alois/Documents/bah-bah/src/parser.bah"
char * tt = "";

#line 2239 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* tmpV = null;

#line 2240 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((len(l)==1)) {

#line 2241 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((strlen(currentFn->returns->type)!=0), 0)) {

#line 2242 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1078 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1078[2] = ".";____BAH_COMPILER_VAR_1078[1] = currentFn->returns->type;____BAH_COMPILER_VAR_1078[0] = "Cannot return nothing as ";char * ____BAH_COMPILER_VAR_1079 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1078, 3);throwErr(&l->data[0],____BAH_COMPILER_VAR_1079);
}
}

#line 2244 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 2245 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok rvt = l->data[1];

#line 2246 "/home/alois/Documents/bah-bah/src/parser.bah"
tt = getTypeFromToken(&rvt,true,elems);

#line 2247 "/home/alois/Documents/bah-bah/src/parser.bah"
rv = rvt.cont;

#line 2248 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((rvt.type==TOKEN_TYPE_VAR)&&(rvt.isOper==false)) {

#line 2249 "/home/alois/Documents/bah-bah/src/parser.bah"
tmpV = searchVar(rvt.cont,compilerState.currFnElems);

#line 2250 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((tmpV==null)) {

#line 2251 "/home/alois/Documents/bah-bah/src/parser.bah"
tmpV = searchVar(rvt.cont,elems);
}

#line 2253 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((tmpV!=null)) {

#line 2254 "/home/alois/Documents/bah-bah/src/parser.bah"

                struct string ____BAH_COMPILER_VAR_1080 = string(compilerState.currentDir);
                if ((isUnsafe==false)&&(string__hasPrefix(&____BAH_COMPILER_VAR_1080,BAH_DIR)==false)&&(currentFn->returns->type[strlen(currentFn->returns->type)-1]!=33)) {

#line 2255 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((tmpV->canBeNull==true)||(strcmp(rv, "null") == 0)) {

#line 2256 "/home/alois/Documents/bah-bah/src/parser.bah"
currentFn->returns->canBeNull = true;

#line 2257 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1081 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1081[2] = "' that can be null as pointer.\n\tUse maybe values instead.";____BAH_COMPILER_VAR_1081[1] = tmpV->name;____BAH_COMPILER_VAR_1081[0] = "Returning '";char * ____BAH_COMPILER_VAR_1082 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1081, 3);throwNoticeLine(____BAH_COMPILER_VAR_1082,rvt.line);
}
}
}
}

#line 2261 "/home/alois/Documents/bah-bah/src/parser.bah"
else if (RCPavailable()&&(rvt.type==TOKEN_TYPE_FUNC)) {

#line 2262 "/home/alois/Documents/bah-bah/src/parser.bah"
rv = genCompilerVar();

#line 2263 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string cType = getCType(tt,elems);

#line 2264 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1083 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_1083[5] = ";\n";____BAH_COMPILER_VAR_1083[4] = rvt.cont;____BAH_COMPILER_VAR_1083[3] = "=";____BAH_COMPILER_VAR_1083[2] = rv;____BAH_COMPILER_VAR_1083[1] = " ";____BAH_COMPILER_VAR_1083[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_1084 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1083, 6);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1084));
}

#line 2266 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((compTypes(tt,currentFn->returns->type)==false), 0)) {

#line 2267 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1085 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1085[4] = ".";____BAH_COMPILER_VAR_1085[3] = currentFn->returns->type;____BAH_COMPILER_VAR_1085[2] = ") as ";____BAH_COMPILER_VAR_1085[1] = tt;____BAH_COMPILER_VAR_1085[0] = "Cannot return {TOKEN} (";char * ____BAH_COMPILER_VAR_1086 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1085, 5);throwErr(&rvt,____BAH_COMPILER_VAR_1086);
}
}

#line 2270 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((compilerState.isBranch==false)) {

#line 2271 "/home/alois/Documents/bah-bah/src/parser.bah"
currentFn->returned = true;
}

#line 2272 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 2273 "/home/alois/Documents/bah-bah/src/parser.bah"
currentFn->couldAlreadyReturn = true;

#line 2274 "/home/alois/Documents/bah-bah/src/parser.bah"
setNullStateBranchFlowEnd(elems);
}

#line 2277 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strlen(rv)>0)) {

#line 2278 "/home/alois/Documents/bah-bah/src/parser.bah"
char * rvar = rv;

#line 2279 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((RCPavailable()==true)&&isRCPtype(currentFn->returns->type,elems)) {

#line 2280 "/home/alois/Documents/bah-bah/src/parser.bah"
rvar = genCompilerVar();

#line 2281 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string cType = getCType(currentFn->returns->type,elems);

#line 2282 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1087 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_1087[5] = ";\n";____BAH_COMPILER_VAR_1087[4] = rv;____BAH_COMPILER_VAR_1087[3] = " = ";____BAH_COMPILER_VAR_1087[2] = rvar;____BAH_COMPILER_VAR_1087[1] = " ";____BAH_COMPILER_VAR_1087[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_1088 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1087, 6);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1088));

#line 2283 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((tmpV!=null)&&(tmpV->declScope!=elems)) {

#line 2284 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope__add(OUTPUT, incrVar(tmpV,elems));
}
}

#line 2287 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string stt = string(tt);

#line 2288 "/home/alois/Documents/bah-bah/src/parser.bah"
if (string__hasPrefix(&stt,"buffer:")) {

#line 2289 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1089 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1089[2] = ")";____BAH_COMPILER_VAR_1089[1] = rvar;____BAH_COMPILER_VAR_1089[0] = "__STR(";char * ____BAH_COMPILER_VAR_1090 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1089, 3);rvar = ____BAH_COMPILER_VAR_1090;
}

#line 2290 "/home/alois/Documents/bah-bah/src/parser.bah"
else if (string__hasPrefix(&stt,"tuple:")) {

#line 2291 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct string)* parts = splitString(stt,":");

#line 2292 "/home/alois/Documents/bah-bah/src/parser.bah"
char * v = genCompilerVar();

#line 2293 "/home/alois/Documents/bah-bah/src/parser.bah"

                struct string ____BAH_COMPILER_VAR_1091 = getCType(tt,elems);
                char * ____BAH_COMPILER_VAR_1092 =string__str(&parts->data[2]);
                struct string ____BAH_COMPILER_VAR_1093 = getCType(____BAH_COMPILER_VAR_1092,elems);
                char * ____BAH_COMPILER_VAR_1094 =string__str(&parts->data[2]);
                struct string ____BAH_COMPILER_VAR_1095 = getCType(____BAH_COMPILER_VAR_1094,elems);
                char** ____BAH_COMPILER_VAR_1096 = alloca(17 * sizeof(char*));____BAH_COMPILER_VAR_1096[16] = ");";____BAH_COMPILER_VAR_1096[15] = string__str(&parts->data[1]);____BAH_COMPILER_VAR_1096[14] = ") * ";____BAH_COMPILER_VAR_1096[13] = string__str(&____BAH_COMPILER_VAR_1095);____BAH_COMPILER_VAR_1096[12] = ", sizeof(";____BAH_COMPILER_VAR_1096[11] = rv;____BAH_COMPILER_VAR_1096[10] = ", ";____BAH_COMPILER_VAR_1096[9] = v;____BAH_COMPILER_VAR_1096[8] = "));\n            memcpy(";____BAH_COMPILER_VAR_1096[7] = string__str(&____BAH_COMPILER_VAR_1093);____BAH_COMPILER_VAR_1096[6] = " * sizeof(";____BAH_COMPILER_VAR_1096[5] = string__str(&parts->data[1]);____BAH_COMPILER_VAR_1096[4] = " = memoryAlloc(";____BAH_COMPILER_VAR_1096[3] = v;____BAH_COMPILER_VAR_1096[2] = " ";____BAH_COMPILER_VAR_1096[1] = string__str(&____BAH_COMPILER_VAR_1091);____BAH_COMPILER_VAR_1096[0] = "";char * ____BAH_COMPILER_VAR_1097 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1096, 17);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1097));

#line 2295 "/home/alois/Documents/bah-bah/src/parser.bah"
rvar = v;
}

#line 2297 "/home/alois/Documents/bah-bah/src/parser.bah"
if (RCPavailable()) {

#line 2298 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct variable*)* excl = memoryAlloc(sizeof(array(struct variable*)));

excl->length = 0;
excl->elemSize = sizeof(struct variable*);

#line 2299 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int j = 0;

#line 2299 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (j<len(currentFn->args)); 
#line 2299 "/home/alois/Documents/bah-bah/src/parser.bah"
++j) {

#line 2300 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1098 = j;
    __Bah_realocate_arr(excl, ____BAH_COMPILER_VAR_1098);
    excl->data[____BAH_COMPILER_VAR_1098] = currentFn->args->data[j];
};

#line 2302 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((tmpV!=null)) {

#line 2303 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1099 = len(excl);
    __Bah_realocate_arr(excl, ____BAH_COMPILER_VAR_1099);
    excl->data[____BAH_COMPILER_VAR_1099] = tmpV;
}

#line 2305 "/home/alois/Documents/bah-bah/src/parser.bah"
endRCPscope(elems,excl);
}

#line 2307 "/home/alois/Documents/bah-bah/src/parser.bah"
fixMeEndScope(elems,&l->data[0]);

#line 2308 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1100 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1100[2] = ";\n";____BAH_COMPILER_VAR_1100[1] = rvar;____BAH_COMPILER_VAR_1100[0] = "return ";char * ____BAH_COMPILER_VAR_1101 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1100, 3);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1101));
}

#line 2309 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 2310 "/home/alois/Documents/bah-bah/src/parser.bah"
if (RCPavailable()) {

#line 2311 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct variable*)* excl = memoryAlloc(sizeof(array(struct variable*)));

excl->length = 0;
excl->elemSize = sizeof(struct variable*);

#line 2312 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int j = 0;

#line 2312 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (j<len(currentFn->args)); 
#line 2312 "/home/alois/Documents/bah-bah/src/parser.bah"
++j) {

#line 2313 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1102 = j;
    __Bah_realocate_arr(excl, ____BAH_COMPILER_VAR_1102);
    excl->data[____BAH_COMPILER_VAR_1102] = currentFn->args->data[j];
};

#line 2315 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((tmpV!=null)) {

#line 2316 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1103 = len(excl);
    __Bah_realocate_arr(excl, ____BAH_COMPILER_VAR_1103);
    excl->data[____BAH_COMPILER_VAR_1103] = tmpV;
}

#line 2318 "/home/alois/Documents/bah-bah/src/parser.bah"
endRCPscope(elems,excl);
}

#line 2320 "/home/alois/Documents/bah-bah/src/parser.bah"
fixMeEndScope(elems,&l->data[0]);

#line 2321 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope__add(OUTPUT, rope("return;\n"));
}
};

#line 2325 "/home/alois/Documents/bah-bah/src/parser.bah"
void parseIf(__BAH_ARR_TYPE_Tok l,char fromElse,struct Elems* elems){

#line 2326 "/home/alois/Documents/bah-bah/src/parser.bah"
prevIfExits = false;

#line 2327 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok ft = l->data[0];

#line 2328 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((len(l)<4), 0)) {

#line 2329 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&ft,"Invalid usage of {TOKEN}, must be 'if <condition> {<code>}'");
}

#line 2331 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok condt = l->data[1];

#line 2332 "/home/alois/Documents/bah-bah/src/parser.bah"
char * tt = getTypeFromToken(&condt,true,elems);

#line 2333 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((compTypes(tt,"bool")==false), 0)) {

#line 2334 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&condt,"Cannot use {TOKEN} as condition in if statement.");
}

#line 2336 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = l->data[2];

#line 2337 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((strcmp(t.cont, "{") != 0), 0)) {

#line 2338 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"Expected '{' not {TOKEN} after condtition in if statement.");
}

#line 2340 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct Tok)* tokens = memoryAlloc(sizeof(array(struct Tok)));

tokens->length = 0;
tokens->elemSize = sizeof(struct Tok);

#line 2341 "/home/alois/Documents/bah-bah/src/parser.bah"
long int max = len(l)-1;

#line 2342 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int i = 3;

#line 2342 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i<max)) {

#line 2343 "/home/alois/Documents/bah-bah/src/parser.bah"
t = l->data[i];

#line 2344 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1104 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_1104);
    tokens->data[____BAH_COMPILER_VAR_1104] = t;

#line 2345 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;
};

#line 2348 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1105 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1105[3] = ") {\n";____BAH_COMPILER_VAR_1105[2] = condt.cont;____BAH_COMPILER_VAR_1105[1] = prevIfShortcut;____BAH_COMPILER_VAR_1105[0] = "if (";char * ____BAH_COMPILER_VAR_1106 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1105, 4);struct rope* ifHeader = rope(____BAH_COMPILER_VAR_1106);

#line 2350 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope__add(OUTPUT, ifHeader);

#line 2352 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Elems* ifElems = dupElems(elems);

#line 2354 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((fromElse==true)) {

#line 2355 "/home/alois/Documents/bah-bah/src/parser.bah"
i = 0;

#line 2355 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<len(prevIfChecks)); 
#line 2355 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 2356 "/home/alois/Documents/bah-bah/src/parser.bah"
struct varCheck bc = prevIfChecks->data[i];

#line 2357 "/home/alois/Documents/bah-bah/src/parser.bah"
bc.checkNull = (bc.checkNull==false);

#line 2358 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1107 = i;
    __Bah_realocate_arr(ifElems->branchChecks, ____BAH_COMPILER_VAR_1107);
    ifElems->branchChecks->data[____BAH_COMPILER_VAR_1107] = bc;
};
}

#line 2362 "/home/alois/Documents/bah-bah/src/parser.bah"
i = 0;

#line 2362 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<len(currChecks)); 
#line 2362 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 2363 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1108 = len(ifElems->branchChecks);
    __Bah_realocate_arr(ifElems->branchChecks, ____BAH_COMPILER_VAR_1108);
    ifElems->branchChecks->data[____BAH_COMPILER_VAR_1108] = currChecks->data[i];
};

#line 2365 "/home/alois/Documents/bah-bah/src/parser.bah"
prevIfChecks = ifElems->branchChecks;

#line 2367 "/home/alois/Documents/bah-bah/src/parser.bah"
char oldIB = compilerState.isBranch;

#line 2368 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.isBranch = true;

#line 2369 "/home/alois/Documents/bah-bah/src/parser.bah"
beginRCPscopeLeaky(ifElems);

#line 2370 "/home/alois/Documents/bah-bah/src/parser.bah"
parseLines(tokens,ifElems);

#line 2372 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((ifElems->currFlowEnd==true)) {

#line 2373 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1109 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1109[2] = ", 0)) {\n";____BAH_COMPILER_VAR_1109[1] = condt.cont;____BAH_COMPILER_VAR_1109[0] = "if (__builtin_expect(";char * ____BAH_COMPILER_VAR_1110 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1109, 3);OUTPUT->totalLen = OUTPUT->totalLen+ropeSet(ifHeader,____BAH_COMPILER_VAR_1110);
}

#line 2377 "/home/alois/Documents/bah-bah/src/parser.bah"
endRCPscopeLeaky(ifElems,null,true);

#line 2378 "/home/alois/Documents/bah-bah/src/parser.bah"
fixMeEndScope(ifElems,&tokens->data[len(tokens)-1]);

#line 2379 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((debug==true)) {

#line 2380 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok lt = l->data[len(l)-1];

#line 2381 "/home/alois/Documents/bah-bah/src/parser.bah"
debugEndScope(lt.line,ifElems);
}

#line 2383 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.isBranch = oldIB;

#line 2384 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope__add(OUTPUT, rope("}\n"));

#line 2386 "/home/alois/Documents/bah-bah/src/parser.bah"
prevIfShortcut = "";
};

#line 2389 "/home/alois/Documents/bah-bah/src/parser.bah"
void parseElse(__BAH_ARR_TYPE_Tok l,struct Elems* elems){

#line 2391 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((prevLine!=LINE_TYPE_IF)) {

#line 2392 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((prevLine!=LINE_TYPE_ELSE), 0)) {

#line 2393 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&l->data[0],"Can only use {TOKEN} after 'if' statement.");
}
}

#line 2396 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((len(l)<3), 0)) {

#line 2397 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&l->data[0],"Incalid usage of {TOKEN}, must be 'else {<code>}'.");
}

#line 2399 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok ft = l->data[1];

#line 2401 "/home/alois/Documents/bah-bah/src/parser.bah"
char prevReturned = prevIfExits;

#line 2403 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope__add(OUTPUT, rope("else "));

#line 2404 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(ft.cont, "if") == 0)) {

#line 2405 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);

#line 2406 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int i = 1;

#line 2406 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i<len(l))) {

#line 2407 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1111 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1111);
    memory->data[____BAH_COMPILER_VAR_1111] = l->data[i];

#line 2408 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;
};

#line 2410 "/home/alois/Documents/bah-bah/src/parser.bah"
parseIf(memory,true,elems);

#line 2411 "/home/alois/Documents/bah-bah/src/parser.bah"
prevLine = LINE_TYPE_IF;
}

#line 2413 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 2414 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((strcmp(ft.cont, "{") != 0), 0)) {

#line 2415 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&ft,"Expected 'if' or '{' not {TOKEN}.");
}

#line 2417 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);

#line 2418 "/home/alois/Documents/bah-bah/src/parser.bah"
long int max = len(l)-1;

#line 2419 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int i = 2;

#line 2419 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i<max)) {

#line 2420 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1112 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1112);
    memory->data[____BAH_COMPILER_VAR_1112] = l->data[i];

#line 2421 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;
};

#line 2423 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope__add(OUTPUT, rope("{\n"));

#line 2424 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Elems* ifElems = dupElems(elems);

#line 2426 "/home/alois/Documents/bah-bah/src/parser.bah"
i = 0;

#line 2426 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<len(prevIfChecks)); 
#line 2426 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 2427 "/home/alois/Documents/bah-bah/src/parser.bah"
struct varCheck bc = prevIfChecks->data[i];

#line 2428 "/home/alois/Documents/bah-bah/src/parser.bah"
bc.checkNull = (bc.checkNull==false);

#line 2429 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1113 = i;
    __Bah_realocate_arr(ifElems->branchChecks, ____BAH_COMPILER_VAR_1113);
    ifElems->branchChecks->data[____BAH_COMPILER_VAR_1113] = bc;
};

#line 2432 "/home/alois/Documents/bah-bah/src/parser.bah"
char oldIB = compilerState.isBranch;

#line 2433 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.isBranch = true;

#line 2434 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = l->data[0];

#line 2435 "/home/alois/Documents/bah-bah/src/parser.bah"
beginRCPscopeLeaky(ifElems);

#line 2436 "/home/alois/Documents/bah-bah/src/parser.bah"
parseLines(memory,ifElems);

#line 2437 "/home/alois/Documents/bah-bah/src/parser.bah"
endRCPscopeLeaky(ifElems,null,true);

#line 2438 "/home/alois/Documents/bah-bah/src/parser.bah"
fixMeEndScope(ifElems,&memory->data[len(memory)-1]);

#line 2439 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((debug==true)) {

#line 2440 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok lt = l->data[len(l)-1];

#line 2441 "/home/alois/Documents/bah-bah/src/parser.bah"
debugEndScope(lt.line,ifElems);
}

#line 2443 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.isBranch = oldIB;

#line 2444 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope__add(OUTPUT, rope("}\n"));

#line 2445 "/home/alois/Documents/bah-bah/src/parser.bah"
prevIfExits = false;
}
};

#line 2452 "/home/alois/Documents/bah-bah/src/parser.bah"
void parseLine(__BAH_ARR_TYPE_Tok l,struct Elems* elems);

#line 2454 "/home/alois/Documents/bah-bah/src/parser.bah"
void parseFor(__BAH_ARR_TYPE_Tok l,struct Elems* elems){

#line 2456 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((len(l)<4), 0)) {

#line 2457 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&l->data[0],"Invalid usage of {TOKEN}.");
}

#line 2460 "/home/alois/Documents/bah-bah/src/parser.bah"
long int nbComas = 0;

#line 2461 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int i = 1;

#line 2461 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i<len(l))) {

#line 2462 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = l->data[i];

#line 2463 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "{") == 0)) {

#line 2464 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}

#line 2466 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((t.type==TOKEN_TYPE_SYNTAX)&&(strcmp(t.cont, ",") == 0)) {

#line 2467 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((nbComas==1), 0)) {

#line 2468 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"Invalid line separation of for, cannot set more than 2 lines: {TOKEN}.");
}

#line 2470 "/home/alois/Documents/bah-bah/src/parser.bah"
nbComas = nbComas+1;
}

#line 2472 "/home/alois/Documents/bah-bah/src/parser.bah"
i = i+1;
};

#line 2475 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Elems* ifElems = dupElems(elems);

#line 2476 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct Tok)* tokens = memoryAlloc(sizeof(array(struct Tok)));

tokens->length = 0;
tokens->elemSize = sizeof(struct Tok);

#line 2478 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((nbComas>0)) {

#line 2479 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((nbComas!=1), 0)) {

#line 2480 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = l->data[0];

#line 2481 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"Invalid usage of {TOKEN}, can only partition line in 2 using 'for <condition>, <insctruction> {<code>}'.");
}

#line 2484 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct Tok)* inst = memoryAlloc(sizeof(array(struct Tok)));

inst->length = 0;
inst->elemSize = sizeof(struct Tok);

#line 2485 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok condt = l->data[1];

#line 2487 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((strcmp(condt.bahType, "bool") != 0)&&(strcmp(condt.bahType, "int") != 0), 0)) {

#line 2488 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&condt,"Cannot use {TOKEN} as condition in for statement.");
}

#line 2491 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok st = l->data[2];

#line 2493 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((st.type!=TOKEN_TYPE_SYNTAX)||(strcmp(st.cont, ",") != 0), 0)) {

#line 2494 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&st,"Cannot use {TOKEN}, need ',' to split for loop instructions.");
}

#line 2497 "/home/alois/Documents/bah-bah/src/parser.bah"
i = 3;

#line 2497 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<len(l)); 
#line 2497 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 2498 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = l->data[i];

#line 2499 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((t.type==TOKEN_TYPE_ENCL)&&(strcmp(t.cont, "{") == 0)) {

#line 2500 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}

#line 2502 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1114 = len(inst);
    __Bah_realocate_arr(inst, ____BAH_COMPILER_VAR_1114);
    inst->data[____BAH_COMPILER_VAR_1114] = t;
};

#line 2505 "/home/alois/Documents/bah-bah/src/parser.bah"
struct rope* oldOut = OUTPUT;

#line 2506 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope("");

#line 2508 "/home/alois/Documents/bah-bah/src/parser.bah"
parseLine(inst,ifElems);

#line 2510 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ____BAH_COMPILER_VAR_1115 =rope__toStr(OUTPUT);struct string instC = string(____BAH_COMPILER_VAR_1115);

#line 2511 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = oldOut;

#line 2512 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimRight(&instC,2);

#line 2514 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = l->data[i];

#line 2515 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((strcmp(t.cont, "{") != 0), 0)) {

#line 2516 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"Expected '{' not {TOKEN} after '<condition>,<instruction>' in for statement.");
}

#line 2519 "/home/alois/Documents/bah-bah/src/parser.bah"
long int max = len(l)-1;

#line 2520 "/home/alois/Documents/bah-bah/src/parser.bah"
i = i+1;

#line 2520 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<max); 
#line 2520 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 2521 "/home/alois/Documents/bah-bah/src/parser.bah"
t = l->data[i];

#line 2522 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1116 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_1116);
    tokens->data[____BAH_COMPILER_VAR_1116] = t;
};

#line 2525 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1117 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1117[4] = ") {\n";____BAH_COMPILER_VAR_1117[3] = string__str(&instC);____BAH_COMPILER_VAR_1117[2] = "; ";____BAH_COMPILER_VAR_1117[1] = condt.cont;____BAH_COMPILER_VAR_1117[0] = "for (; ";char * ____BAH_COMPILER_VAR_1118 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1117, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1118));
}

#line 2527 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 2528 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok condt = l->data[1];

#line 2529 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(condt.bahType, "bool") != 0)) {

#line 2530 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((strcmp(condt.bahType, "int") != 0), 0)) {

#line 2531 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&condt,"Cannot use {TOKEN} as condition in for statement.");
}
}

#line 2534 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = l->data[2];

#line 2535 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((strcmp(t.cont, "{") != 0), 0)) {

#line 2536 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"Expected '{' not {TOKEN} after condtition in for statement.");
}

#line 2538 "/home/alois/Documents/bah-bah/src/parser.bah"
long int max = len(l)-1;

#line 2539 "/home/alois/Documents/bah-bah/src/parser.bah"
i = 3;

#line 2539 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<max); 
#line 2539 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 2540 "/home/alois/Documents/bah-bah/src/parser.bah"
t = l->data[i];

#line 2541 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1119 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_1119);
    tokens->data[____BAH_COMPILER_VAR_1119] = t;
};

#line 2543 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1120 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1120[2] = ") {\n";____BAH_COMPILER_VAR_1120[1] = condt.cont;____BAH_COMPILER_VAR_1120[0] = "while (";char * ____BAH_COMPILER_VAR_1121 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1120, 3);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1121));
}

#line 2545 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Elems* oForElems = compilerState.currForElems;

#line 2546 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.currForElems = ifElems;

#line 2548 "/home/alois/Documents/bah-bah/src/parser.bah"
char oldIB = compilerState.isBranch;

#line 2549 "/home/alois/Documents/bah-bah/src/parser.bah"
char oldIF = compilerState.isFor;

#line 2550 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.isBranch = true;

#line 2551 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.isFor = true;

#line 2552 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = l->data[0];

#line 2553 "/home/alois/Documents/bah-bah/src/parser.bah"
beginRCPscopeLeaky(ifElems);

#line 2554 "/home/alois/Documents/bah-bah/src/parser.bah"
parseLines(tokens,ifElems);

#line 2555 "/home/alois/Documents/bah-bah/src/parser.bah"
endRCPscopeLeaky(ifElems,null,true);

#line 2556 "/home/alois/Documents/bah-bah/src/parser.bah"
fixMeEndScope(ifElems,&tokens->data[len(tokens)-1]);

#line 2558 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((isUnsafe==false)) {

#line 2559 "/home/alois/Documents/bah-bah/src/parser.bah"
i = 0;

#line 2559 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<len(ifElems->vars)); 
#line 2559 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 2560 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* v = ifElems->vars->data[i];

#line 2561 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((v->iterScope==elems)) {

#line 2562 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((v->lastSet!=ifElems)&&(Elems__isChildren(ifElems,v->lastSet)==false)) {

#line 2563 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1122 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1122[2] = "' but its value is not changed inside the scope of the for loop.\n    This may result in the loop never terminating.";____BAH_COMPILER_VAR_1122[1] = v->name;____BAH_COMPILER_VAR_1122[0] = "For loop iterates over variable '";char * ____BAH_COMPILER_VAR_1123 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1122, 3);throwWarningLine(____BAH_COMPILER_VAR_1123,t.line);
}

#line 2566 "/home/alois/Documents/bah-bah/src/parser.bah"
v->iterScope = null;
}
};
}

#line 2571 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((debug==true)) {

#line 2572 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok lt = l->data[len(l)-1];

#line 2573 "/home/alois/Documents/bah-bah/src/parser.bah"
debugEndScope(lt.line,ifElems);
}

#line 2575 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.isFor = oldIF;

#line 2576 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.isBranch = oldIB;

#line 2577 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.currForElems = oForElems;

#line 2578 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope__add(OUTPUT, rope("};\n"));
};

#line 2582 "/home/alois/Documents/bah-bah/src/parser.bah"
void parseForOp(__BAH_ARR_TYPE_Tok l,struct Elems* elems){

#line 2584 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok ft = l->data[0];

#line 2585 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((compilerState.isFor==false), 0)) {

#line 2586 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&ft,"Cannot {TOKEN} outside of for statement.");
}

#line 2588 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((len(l)!=1), 0)) {

#line 2589 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&ft,"Nothing expected after {TOKEN}.");
}

#line 2593 "/home/alois/Documents/bah-bah/src/parser.bah"
endRCPscopeLeaky(elems,null,false);

#line 2594 "/home/alois/Documents/bah-bah/src/parser.bah"
endRCPscopeLeaky(compilerState.currForElems,null,false);

#line 2595 "/home/alois/Documents/bah-bah/src/parser.bah"
fixMeEndScope(elems,&ft);

#line 2596 "/home/alois/Documents/bah-bah/src/parser.bah"
fixMeEndScope(compilerState.currForElems,&ft);

#line 2597 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1124 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1124[1] = ";\n";____BAH_COMPILER_VAR_1124[0] = ft.cont;char * ____BAH_COMPILER_VAR_1125 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1124, 2);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1125));
};

#line 2601 "/home/alois/Documents/bah-bah/src/parser.bah"
char ____BAH_COMPILER_VAR_1126(array(char *)* arr, char * el) {
        if (arr == 0) {
            return 0;
        };
        for(int i=arr->length-1; i!=-1;i--) {
            if (arr->data[i] != 0 && strcmp(arr->data[i], el) == 0) {
                return 1;
            };
        }
        return 0;
        }
void makeEvalFunc(struct func* fn,struct Elems* elems){

#line 2602 "/home/alois/Documents/bah-bah/src/parser.bah"
if (____BAH_COMPILER_VAR_1126(compilerState.evals, fn->name)) {

#line 2603 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}

#line 2606 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1127 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1127[1] = fn->name;____BAH_COMPILER_VAR_1127[0] = "__Bah_eval_";char * ____BAH_COMPILER_VAR_1128 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1127, 2);struct func* ____BAH_COMPILER_VAR_1129 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_1129->name = "";
____BAH_COMPILER_VAR_1129->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_1129->args->length = 0;
            ____BAH_COMPILER_VAR_1129->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_1129->from = "";
____BAH_COMPILER_VAR_1129->file = "";
____BAH_COMPILER_VAR_1129->line = 1;
____BAH_COMPILER_VAR_1129->name = ____BAH_COMPILER_VAR_1128;
struct func* efn = ____BAH_COMPILER_VAR_1129;

#line 2609 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* ____BAH_COMPILER_VAR_1130 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1130->name = "";
____BAH_COMPILER_VAR_1130->type = "";
____BAH_COMPILER_VAR_1130->constVal = "";
____BAH_COMPILER_VAR_1130->from = "";
____BAH_COMPILER_VAR_1130->type = "ptr";
efn->returns = ____BAH_COMPILER_VAR_1130;

#line 2613 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* ____BAH_COMPILER_VAR_1131 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1131->name = "";
____BAH_COMPILER_VAR_1131->type = "";
____BAH_COMPILER_VAR_1131->constVal = "";
____BAH_COMPILER_VAR_1131->from = "";
____BAH_COMPILER_VAR_1131->name = "fnArgs";
____BAH_COMPILER_VAR_1131->type = "[]ptr";
efn->args = memoryAlloc(sizeof(array(struct variable*)));

efn->args->length = 1;
efn->args->elemSize = sizeof(struct variable*);
efn->args->data = memoryAlloc(sizeof(struct variable*) * 50);
                    efn->args->realLength = 50;
efn->args->data[0] = ____BAH_COMPILER_VAR_1131;

#line 2620 "/home/alois/Documents/bah-bah/src/parser.bah"
char * fnBinding = "";

#line 2621 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1132 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1132[1] = "(";____BAH_COMPILER_VAR_1132[0] = fn->name;char * ____BAH_COMPILER_VAR_1133 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1132, 2);char * fnCall = ____BAH_COMPILER_VAR_1133;

#line 2622 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int i = 0;

#line 2622 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<len(fn->args)); 
#line 2622 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 2623 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* a = fn->args->data[i];

#line 2624 "/home/alois/Documents/bah-bah/src/parser.bah"
char * v = genCompilerVar();

#line 2625 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string cType = getCType(a->type,elems);

#line 2626 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((isRCPpointerType(a->type)==false)) {

#line 2627 "/home/alois/Documents/bah-bah/src/parser.bah"
string__append(&cType,"*");
}

#line 2629 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1134 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_1134[5] = "];";____BAH_COMPILER_VAR_1134[4] = intToStr(i);____BAH_COMPILER_VAR_1134[3] = " = fnArgs->data[";____BAH_COMPILER_VAR_1134[2] = v;____BAH_COMPILER_VAR_1134[1] = " ";____BAH_COMPILER_VAR_1134[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_1135 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1134, 6);char** ____BAH_COMPILER_VAR_1136 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1136[1] = ____BAH_COMPILER_VAR_1135;____BAH_COMPILER_VAR_1136[0] = fnBinding;char * ____BAH_COMPILER_VAR_1137 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1136, 2);fnBinding = ____BAH_COMPILER_VAR_1137;

#line 2630 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((i!=0)) {

#line 2631 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1138 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1138[1] = ", ";____BAH_COMPILER_VAR_1138[0] = fnCall;char * ____BAH_COMPILER_VAR_1139 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1138, 2);fnCall = ____BAH_COMPILER_VAR_1139;
}

#line 2633 "/home/alois/Documents/bah-bah/src/parser.bah"
if (isRCPpointerType(a->type)) {

#line 2634 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1140 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1140[1] = v;____BAH_COMPILER_VAR_1140[0] = fnCall;char * ____BAH_COMPILER_VAR_1141 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1140, 2);fnCall = ____BAH_COMPILER_VAR_1141;
}

#line 2635 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 2636 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1142 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1142[1] = v;____BAH_COMPILER_VAR_1142[0] = "*";char * ____BAH_COMPILER_VAR_1143 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1142, 2);char** ____BAH_COMPILER_VAR_1144 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1144[1] = ____BAH_COMPILER_VAR_1143;____BAH_COMPILER_VAR_1144[0] = fnCall;char * ____BAH_COMPILER_VAR_1145 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1144, 2);fnCall = ____BAH_COMPILER_VAR_1145;
}
};

#line 2640 "/home/alois/Documents/bah-bah/src/parser.bah"
char * setReturnValue = "void* r = 0;";

#line 2641 "/home/alois/Documents/bah-bah/src/parser.bah"
if (isRCPpointerType(fn->returns->type)) {

#line 2642 "/home/alois/Documents/bah-bah/src/parser.bah"
setReturnValue = "void* r = ";
}

#line 2643 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 2644 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string cType = getCType(fn->returns->type,elems);

#line 2645 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(string__str(&cType), "void") != 0)) {

#line 2646 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1146 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1146[3] = "));*r = ";____BAH_COMPILER_VAR_1146[2] = string__str(&cType);____BAH_COMPILER_VAR_1146[1] = "* r = memoryAlloc(sizeof(";____BAH_COMPILER_VAR_1146[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_1147 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1146, 4);setReturnValue = ____BAH_COMPILER_VAR_1147;
}
}

#line 2650 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1148 = alloca(12 * sizeof(char*));____BAH_COMPILER_VAR_1148[11] = ");\n        return (void*)r;\n    };";____BAH_COMPILER_VAR_1148[10] = fnCall;____BAH_COMPILER_VAR_1148[9] = setReturnValue;____BAH_COMPILER_VAR_1148[8] = "\n        ";____BAH_COMPILER_VAR_1148[7] = fnBinding;____BAH_COMPILER_VAR_1148[6] = "() with the wrong number of arguments.\", \"BAH_COMPILER_INTERNAL\");\n        }\n        ";____BAH_COMPILER_VAR_1148[5] = fn->name;____BAH_COMPILER_VAR_1148[4] = ") {\n            __BAH_panic((char*)\"eval: calling function ";____BAH_COMPILER_VAR_1148[3] = intToStr(len(fn->args));____BAH_COMPILER_VAR_1148[2] = "(array(void*)* fnArgs) {\n        if (fnArgs->length != ";____BAH_COMPILER_VAR_1148[1] = efn->name;____BAH_COMPILER_VAR_1148[0] = "void* __attribute__((optimize(\"O0\"))) ";char * ____BAH_COMPILER_VAR_1149 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1148, 12);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1149));

#line 2659 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1150 = len(compilerState.evals);
    __Bah_realocate_arr(compilerState.evals, ____BAH_COMPILER_VAR_1150);
    compilerState.evals->data[____BAH_COMPILER_VAR_1150] = fn->name;

#line 2660 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1151 = len(elems->fns);
    __Bah_realocate_arr(elems->fns, ____BAH_COMPILER_VAR_1151);
    elems->fns->data[____BAH_COMPILER_VAR_1151] = efn;
};

#line 2663 "/home/alois/Documents/bah-bah/src/parser.bah"
char ____BAH_COMPILER_VAR_1153(array(char *)* arr, char * el) {
        if (arr == 0) {
            return 0;
        };
        for(int i=arr->length-1; i!=-1;i--) {
            if (arr->data[i] != 0 && strcmp(arr->data[i], el) == 0) {
                return 1;
            };
        }
        return 0;
        }
void parsePreKeyword(__BAH_ARR_TYPE_Tok l,struct Elems* elems){

#line 2665 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok ft = l->data[0];

#line 2667 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(ft.cont, "#warning") == 0)) {

#line 2668 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((len(l)!=2), 0)) {

#line 2669 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&ft,"Invalid usage of {TOKEN} '#warning \"message\"'.");
}

#line 2671 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok mt = l->data[1];

#line 2672 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((mt.type!=TOKEN_TYPE_STR), 0)) {

#line 2673 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&mt,"Cannot use {TOKEN} as a string.");
}

#line 2676 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string msg = string(mt.cont);

#line 2677 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimLeft(&msg,1);

#line 2678 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimRight(&msg,1);

#line 2681 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ____BAH_COMPILER_VAR_1152 =string__str(&msg);throwWarning(____BAH_COMPILER_VAR_1152);

#line 2682 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}

#line 2686 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(ft.cont, "#eval") == 0)) {

#line 2688 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((____BAH_COMPILER_VAR_1153(compilerState.includes, "eval.bah")==false)) {

#line 2689 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((includeFile("eval.bah",elems)==false), 0)) {

#line 2690 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1154 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1154[2] = ").";____BAH_COMPILER_VAR_1154[1] = BAH_DIR;____BAH_COMPILER_VAR_1154[0] = "Could not find file 'eval.bah'. Check your bah directory (";char * ____BAH_COMPILER_VAR_1155 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1154, 3);throwErr(&l->data[0],____BAH_COMPILER_VAR_1155);
}
}

#line 2694 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((len(l)!=2)||(isGlobal()==false), 0)) {

#line 2695 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&l->data[0],"Invalid usage of {TOKEN} <#eval fnName>.");
}

#line 2698 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok fnT = l->data[1];

#line 2699 "/home/alois/Documents/bah-bah/src/parser.bah"
struct func* fn = searchFunc(fnT.cont,elems,false);

#line 2700 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((fn==null), 0)) {

#line 2701 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&fnT,"Unknown function {TOKEN}.");
}

#line 2703 "/home/alois/Documents/bah-bah/src/parser.bah"
fn->used = true;

#line 2705 "/home/alois/Documents/bah-bah/src/parser.bah"
makeEvalFunc(fn,elems);

#line 2707 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}

#line 2710 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(ft.cont, "#evalAll") == 0)) {

#line 2711 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int i = 0;

#line 2711 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<len(elems->fns)); 
#line 2711 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 2712 "/home/alois/Documents/bah-bah/src/parser.bah"
struct func* fn = elems->fns->data[i];

#line 2713 "/home/alois/Documents/bah-bah/src/parser.bah"
fn->used = true;

#line 2714 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((fn->isBinding==false)&&(strHasPrefix(fn->name,"__Bah_eval_")==false)) {

#line 2715 "/home/alois/Documents/bah-bah/src/parser.bah"
makeEvalFunc(fn,elems);
}
};

#line 2718 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}

#line 2721 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((len(l)<3), 0)) {

#line 2722 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&ft,"Invalid usage of keyword {TOKEN}.");
}

#line 2725 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(ft.cont, "#linux") == 0)||(strcmp(ft.cont, "#windows") == 0)||(strcmp(ft.cont, "#darwin") == 0)) {

#line 2726 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string isOS = string(ft.cont);

#line 2727 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimLeft(&isOS,1);

#line 2728 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(string__str(&isOS), BAH_OS) != 0)) {

#line 2729 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}
}

#line 2731 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "#static") == 0)) {

#line 2732 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((flags__isSet(&flags,"d")==1)) {

#line 2733 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}
}

#line 2735 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "#dynamic") == 0)) {

#line 2736 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((flags__isSet(&flags,"d")==0)) {

#line 2737 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}
}

#line 2739 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "#gc") == 0)) {

#line 2740 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((RCPavailable()==true)) {

#line 2741 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}
}

#line 2743 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "#rcp") == 0)) {

#line 2744 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((RCPavailable()==false)) {

#line 2745 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}
}

#line 2747 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "#lib") == 0)) {

#line 2748 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((flags__isSet(&flags,"l")==0)) {

#line 2749 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}
}

#line 2751 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "#exec") == 0)) {

#line 2752 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((flags__isSet(&flags,"l")==1)) {

#line 2753 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}
}

#line 2755 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "#imported") == 0)) {

#line 2756 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((isSubObject==false)||(isObject==false)) {

#line 2757 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}
}

#line 2759 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "#included") == 0)) {

#line 2760 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((isSubObject==true)||(isObject==true)) {

#line 2761 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}
}

#line 2763 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "#optimized") == 0)) {

#line 2764 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((isOptimized==false)) {

#line 2765 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}
}

#line 2767 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "#unoptimized") == 0)) {

#line 2768 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((isOptimized==true)) {

#line 2769 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}
}

#line 2771 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 2772 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&ft,"Undefined token {TOKEN}.");
}

#line 2775 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok st = l->data[1];

#line 2776 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok lt = l->data[len(l)-1];

#line 2777 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((strcmp(st.cont, "{") != 0)||(strcmp(lt.cont, "}") != 0), 0)) {

#line 2778 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&st,"Expected code block after keyword {TOKEN}.");
}

#line 2781 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);

#line 2782 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int i = 2;

#line 2782 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i<len(l)-1)) {

#line 2783 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1156 = i-2;
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_1156);
    nl->data[____BAH_COMPILER_VAR_1156] = l->data[i];

#line 2784 "/home/alois/Documents/bah-bah/src/parser.bah"
i = i+1;
};

#line 2787 "/home/alois/Documents/bah-bah/src/parser.bah"
parseLines(nl,elems);
};

#line 2791 "/home/alois/Documents/bah-bah/src/parser.bah"
void parseAsync(__BAH_ARR_TYPE_Tok l,struct Elems* elems){

#line 2792 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((len(l)!=2), 0)) {

#line 2793 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok ft = l->data[0];

#line 2794 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&ft,"Cannot use keyword {TOKEN} on a function call 'async <function call>'.");
}

#line 2796 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok fnT = l->data[1];

#line 2797 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((fnT.isFunc==false), 0)) {

#line 2798 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&fnT,"Cannot use keyword async on {TOKEN}. Usage: 'async <function call>'.");
}

#line 2801 "/home/alois/Documents/bah-bah/src/parser.bah"
char found = false;

#line 2802 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int i = 0;

#line 2802 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i<len(compilerState.cLibs))) {

#line 2803 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(compilerState.cLibs->data[i], "lpthread") == 0)) {

#line 2804 "/home/alois/Documents/bah-bah/src/parser.bah"
found = true;

#line 2805 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}

#line 2807 "/home/alois/Documents/bah-bah/src/parser.bah"
i = i+1;
};

#line 2809 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((found==false)) {

#line 2810 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1157 = len(compilerState.cLibs);
    __Bah_realocate_arr(compilerState.cLibs, ____BAH_COMPILER_VAR_1157);
    compilerState.cLibs->data[____BAH_COMPILER_VAR_1157] = "lpthread";
}

#line 2813 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string sFnT = string(fnT.cont);

#line 2815 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct string)* fnNameParts = splitString(sFnT,"(");

#line 2816 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string fnName = fnNameParts->data[0];

#line 2818 "/home/alois/Documents/bah-bah/src/parser.bah"
struct func* fn = searchFuncByToken(&fnT,elems);

#line 2820 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((fn==null), 0)) {

#line 2821 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1158 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1158[2] = "', arround {TOKEN}.";____BAH_COMPILER_VAR_1158[1] = string__str(&fnName);____BAH_COMPILER_VAR_1158[0] = "Internal compiler error.\n Error parsing async call for function '";char * ____BAH_COMPILER_VAR_1159 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1158, 3);throwErr(&fnT,____BAH_COMPILER_VAR_1159);
}

#line 2823 "/home/alois/Documents/bah-bah/src/parser.bah"
fnName = string(fn->name);

#line 2824 "/home/alois/Documents/bah-bah/src/parser.bah"
char * sMembs = "";

#line 2825 "/home/alois/Documents/bah-bah/src/parser.bah"
char * unSerMembs = "";

#line 2827 "/home/alois/Documents/bah-bah/src/parser.bah"
i = 0;

#line 2827 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i<len(fn->args))) {

#line 2828 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* a = fn->args->data[i];

#line 2829 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string cType = getCType(a->type,elems);

#line 2830 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1160 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1160[4] = ";\n";____BAH_COMPILER_VAR_1160[3] = a->name;____BAH_COMPILER_VAR_1160[2] = " ";____BAH_COMPILER_VAR_1160[1] = string__str(&cType);____BAH_COMPILER_VAR_1160[0] = sMembs;char * ____BAH_COMPILER_VAR_1161 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1160, 5);sMembs = ____BAH_COMPILER_VAR_1161;

#line 2831 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1162 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1162[2] = a->name;____BAH_COMPILER_VAR_1162[1] = "args->";____BAH_COMPILER_VAR_1162[0] = unSerMembs;char * ____BAH_COMPILER_VAR_1163 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1162, 3);unSerMembs = ____BAH_COMPILER_VAR_1163;

#line 2832 "/home/alois/Documents/bah-bah/src/parser.bah"
i = i+1;

#line 2833 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((i<len(fn->args))) {

#line 2834 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1164 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1164[1] = ", ";____BAH_COMPILER_VAR_1164[0] = unSerMembs;char * ____BAH_COMPILER_VAR_1165 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1164, 2);unSerMembs = ____BAH_COMPILER_VAR_1165;
}
};

#line 2838 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1166 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1166[2] = "}";____BAH_COMPILER_VAR_1166[1] = sMembs;____BAH_COMPILER_VAR_1166[0] = "struct {\n";char * ____BAH_COMPILER_VAR_1167 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1166, 3);char * tmpArgsStruct = ____BAH_COMPILER_VAR_1167;

#line 2839 "/home/alois/Documents/bah-bah/src/parser.bah"
char * fnWrapper = genCompilerVar();

#line 2840 "/home/alois/Documents/bah-bah/src/parser.bah"
char * tmpArgs = genCompilerVar();

#line 2842 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimLeft(&sFnT,fnName.length+1);

#line 2843 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimRight(&sFnT,1);

#line 2845 "/home/alois/Documents/bah-bah/src/parser.bah"
char * tCreate = "";

#line 2846 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(BAH_OS, "windows") == 0)) {

#line 2847 "/home/alois/Documents/bah-bah/src/parser.bah"
tCreate = "pthread_create";
}

#line 2848 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 2849 "/home/alois/Documents/bah-bah/src/parser.bah"
if (RCPavailable()||(RAIIenabled==true)) {

#line 2850 "/home/alois/Documents/bah-bah/src/parser.bah"
tCreate = "pthread_create";
}

#line 2851 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 2852 "/home/alois/Documents/bah-bah/src/parser.bah"
tCreate = "GC_pthread_create";
}
}

#line 2856 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1168 = alloca(25 * sizeof(char*));____BAH_COMPILER_VAR_1168[24] = ", tmpArgs);\n    }; \n    \n    ";____BAH_COMPILER_VAR_1168[23] = fnWrapper;____BAH_COMPILER_VAR_1168[22] = "(&id, 0, ";____BAH_COMPILER_VAR_1168[21] = tCreate;____BAH_COMPILER_VAR_1168[20] = "));\n        pthread_t id;\n        ";____BAH_COMPILER_VAR_1168[19] = tmpArgs;____BAH_COMPILER_VAR_1168[18] = ", sizeof(";____BAH_COMPILER_VAR_1168[17] = tmpArgs;____BAH_COMPILER_VAR_1168[16] = "));\n        memcpy(tmpArgs, &";____BAH_COMPILER_VAR_1168[15] = tmpArgs;____BAH_COMPILER_VAR_1168[14] = "};\n        void* tmpArgs = memoryAlloc(sizeof(";____BAH_COMPILER_VAR_1168[13] = string__str(&sFnT);____BAH_COMPILER_VAR_1168[12] = " = {";____BAH_COMPILER_VAR_1168[11] = tmpArgs;____BAH_COMPILER_VAR_1168[10] = " ";____BAH_COMPILER_VAR_1168[9] = tmpArgsStruct;____BAH_COMPILER_VAR_1168[8] = ");\n    };\n    {\n        ";____BAH_COMPILER_VAR_1168[7] = unSerMembs;____BAH_COMPILER_VAR_1168[6] = "(";____BAH_COMPILER_VAR_1168[5] = string__str(&fnName);____BAH_COMPILER_VAR_1168[4] = "* args) {\n        ";____BAH_COMPILER_VAR_1168[3] = tmpArgsStruct;____BAH_COMPILER_VAR_1168[2] = "(";____BAH_COMPILER_VAR_1168[1] = fnWrapper;____BAH_COMPILER_VAR_1168[0] = "\n    void ";char * ____BAH_COMPILER_VAR_1169 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1168, 25);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1169));
};

#line 2871 "/home/alois/Documents/bah-bah/src/parser.bah"
void addRCPvars(__BAH_ARR_TYPE_Tok l,lineType ltp,struct Elems* elems){

#line 2873 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int i = 0;

#line 2874 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((ltp==LINE_TYPE_VAR)) {

#line 2875 "/home/alois/Documents/bah-bah/src/parser.bah"
i = 1;
}

#line 2877 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i<len(l))) {

#line 2878 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = l->data[i];

#line 2879 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((t.type==TOKEN_TYPE_VAR)&&(t.isOper==false)) {

#line 2880 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* v = searchVirtVarByToken(&t,elems);

#line 2881 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((v!=null)) {

#line 2882 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1170 = len(compilerState.RCPvars);
    __Bah_realocate_arr(compilerState.RCPvars, ____BAH_COMPILER_VAR_1170);
    compilerState.RCPvars->data[____BAH_COMPILER_VAR_1170] = v;
}
}

#line 2885 "/home/alois/Documents/bah-bah/src/parser.bah"
i = i+1;
};
};

#line 2891 "/home/alois/Documents/bah-bah/src/parser.bah"
__BAH_ARR_TYPE_Tok parseChan(__BAH_ARR_TYPE_Tok l,struct Elems* elems){

#line 2893 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);

#line 2894 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int i = 0;

#line 2894 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<len(l)); 
#line 2894 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 2895 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = l->data[i];

#line 2896 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((t.type==TOKEN_TYPE_SYNTAX)&&(strcmp(t.cont, "->") == 0)||(strcmp(t.cont, "<-") == 0)) {

#line 2898 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "<-") == 0)) {

#line 2899 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 2900 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((i<len(l))) {

#line 2901 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok nt = l->data[i];

#line 2902 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((nt.type!=TOKEN_TYPE_VAR), 0)) {

#line 2903 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&nt,"Cannot use {TOKEN} as channel.");
}

#line 2905 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ____BAH_COMPILER_VAR_1171 =getTypeFromToken(&nt,true,elems);struct string ntt = string(____BAH_COMPILER_VAR_1171);

#line 2906 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((string__hasPrefix(&ntt,"chan:")==0), 0)) {

#line 2907 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1172 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1172[2] = ") as channel.";____BAH_COMPILER_VAR_1172[1] = string__str(&ntt);____BAH_COMPILER_VAR_1172[0] = "Cannot use var {TOKEN} (";char * ____BAH_COMPILER_VAR_1173 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1172, 3);throwErr(&nt,____BAH_COMPILER_VAR_1173);
}

#line 2909 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimLeft(&ntt,5);

#line 2911 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect(isGlobal(), 0)) {

#line 2912 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"Cannot receive ({TOKEN}) from a channel outside of a function.");
}

#line 2915 "/home/alois/Documents/bah-bah/src/parser.bah"
char * tmpV = "";

#line 2917 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ____BAH_COMPILER_VAR_1174 =string__str(&ntt);if (isRCPpointerType(____BAH_COMPILER_VAR_1174)) {

#line 2918 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ____BAH_COMPILER_VAR_1175 =string__str(&ntt);struct string ct = getCType(____BAH_COMPILER_VAR_1175,elems);

#line 2919 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1176 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_1176[6] = ")";____BAH_COMPILER_VAR_1176[5] = nt.cont;____BAH_COMPILER_VAR_1176[4] = "->receive(";____BAH_COMPILER_VAR_1176[3] = nt.cont;____BAH_COMPILER_VAR_1176[2] = ")";____BAH_COMPILER_VAR_1176[1] = string__str(&ct);____BAH_COMPILER_VAR_1176[0] = "(";char * ____BAH_COMPILER_VAR_1177 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1176, 7);t.cont = ____BAH_COMPILER_VAR_1177;
}

#line 2920 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 2921 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ____BAH_COMPILER_VAR_1178 =string__str(&ntt);struct string ct = getCType(____BAH_COMPILER_VAR_1178,elems);

#line 2922 "/home/alois/Documents/bah-bah/src/parser.bah"
if (RCPavailable()) {

#line 2923 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1179 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1179[1] = "*";____BAH_COMPILER_VAR_1179[0] = string__str(&ntt);char * ____BAH_COMPILER_VAR_1180 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1179, 2);char** ____BAH_COMPILER_VAR_1181 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_1181[6] = ")";____BAH_COMPILER_VAR_1181[5] = nt.cont;____BAH_COMPILER_VAR_1181[4] = "->receive(";____BAH_COMPILER_VAR_1181[3] = nt.cont;____BAH_COMPILER_VAR_1181[2] = "*)";____BAH_COMPILER_VAR_1181[1] = string__str(&ct);____BAH_COMPILER_VAR_1181[0] = "(";char * ____BAH_COMPILER_VAR_1182 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1181, 7);tmpV = registerRCPvar(____BAH_COMPILER_VAR_1180,____BAH_COMPILER_VAR_1182,elems);

#line 2924 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1183 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1183[1] = tmpV;____BAH_COMPILER_VAR_1183[0] = "*";char * ____BAH_COMPILER_VAR_1184 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1183, 2);t.cont = ____BAH_COMPILER_VAR_1184;
}

#line 2925 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 2926 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1185 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_1185[6] = ")";____BAH_COMPILER_VAR_1185[5] = nt.cont;____BAH_COMPILER_VAR_1185[4] = "->receive(";____BAH_COMPILER_VAR_1185[3] = nt.cont;____BAH_COMPILER_VAR_1185[2] = "*)";____BAH_COMPILER_VAR_1185[1] = string__str(&ct);____BAH_COMPILER_VAR_1185[0] = "*(";char * ____BAH_COMPILER_VAR_1186 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1185, 7);t.cont = ____BAH_COMPILER_VAR_1186;
}
}

#line 2929 "/home/alois/Documents/bah-bah/src/parser.bah"
t.type = TOKEN_TYPE_FUNC;

#line 2930 "/home/alois/Documents/bah-bah/src/parser.bah"
t.isFunc = true;

#line 2932 "/home/alois/Documents/bah-bah/src/parser.bah"
if (RCPavailable()) {

#line 2933 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ____BAH_COMPILER_VAR_1187 =string__str(&ntt);if (isRCPpointerType(____BAH_COMPILER_VAR_1187)) {

#line 2934 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ____BAH_COMPILER_VAR_1188 =string__str(&ntt);tmpV = registerRCPvar(____BAH_COMPILER_VAR_1188,t.cont,elems);

#line 2935 "/home/alois/Documents/bah-bah/src/parser.bah"
t.type = TOKEN_TYPE_VAR;

#line 2936 "/home/alois/Documents/bah-bah/src/parser.bah"
t.isFunc = false;

#line 2937 "/home/alois/Documents/bah-bah/src/parser.bah"
t.cont = tmpV;
}

#line 2938 "/home/alois/Documents/bah-bah/src/parser.bah"
else {
}
}

#line 2943 "/home/alois/Documents/bah-bah/src/parser.bah"
t.isValue = true;

#line 2944 "/home/alois/Documents/bah-bah/src/parser.bah"
t.bahType = string__str(&ntt);
}

#line 2945 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 2946 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"Cannot use {TOKEN} on nothing");
}
}

#line 2948 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 2949 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((i==0), 0)) {

#line 2950 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"Cannot une {TOKEN} on nothing.");
}

#line 2952 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((i+1>=len(l)), 0)) {

#line 2953 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"Cannot send ({TOKEN}) to nothing.");
}

#line 2955 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok pt = l->data[i+1];

#line 2956 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok nt = l->data[i-1];

#line 2957 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ntt = getTypeFromToken(&nt,true,elems);

#line 2959 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((pt.type!=TOKEN_TYPE_VAR), 0)) {

#line 2960 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&pt,"Cannot use {TOKEN} as channel.");
}

#line 2962 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ____BAH_COMPILER_VAR_1189 =getTypeFromToken(&pt,true,elems);struct string ptt = string(____BAH_COMPILER_VAR_1189);

#line 2963 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((string__hasPrefix(&ptt,"chan:")==0), 0)) {

#line 2964 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1190 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1190[2] = ") as channel.";____BAH_COMPILER_VAR_1190[1] = ntt;____BAH_COMPILER_VAR_1190[0] = "Cannot use var {TOKEN} (";char * ____BAH_COMPILER_VAR_1191 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1190, 3);throwErr(&pt,____BAH_COMPILER_VAR_1191);
}

#line 2966 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimLeft(&ptt,5);

#line 2968 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect(isGlobal(), 0)) {

#line 2969 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"Cannot send ({TOKEN}) to a channel outside of a function.");
}

#line 2972 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ____BAH_COMPILER_VAR_1192 =string__str(&ptt);if (__builtin_expect((compTypes(____BAH_COMPILER_VAR_1192,ntt)==false), 0)) {

#line 2973 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1193 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1193[4] = ".";____BAH_COMPILER_VAR_1193[3] = string__str(&ptt);____BAH_COMPILER_VAR_1193[2] = ") to channel of type ";____BAH_COMPILER_VAR_1193[1] = ntt;____BAH_COMPILER_VAR_1193[0] = "Cannot send {TOKEN} (";char * ____BAH_COMPILER_VAR_1194 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1193, 5);throwErr(&nt,____BAH_COMPILER_VAR_1194);
}

#line 2976 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 2977 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ____BAH_COMPILER_VAR_1195 =string__str(&ptt);if (isRCPpointerType(____BAH_COMPILER_VAR_1195)) {

#line 2978 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1196 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_1196[5] = ");\n";____BAH_COMPILER_VAR_1196[4] = nt.cont;____BAH_COMPILER_VAR_1196[3] = ", ";____BAH_COMPILER_VAR_1196[2] = pt.cont;____BAH_COMPILER_VAR_1196[1] = "->send(";____BAH_COMPILER_VAR_1196[0] = pt.cont;char * ____BAH_COMPILER_VAR_1197 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1196, 6);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1197));
}

#line 2979 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 2980 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string ct = getCType(ntt,elems);

#line 2981 "/home/alois/Documents/bah-bah/src/parser.bah"
char * tmpV = genCompilerVar();

#line 2982 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1198 = alloca(15 * sizeof(char*));____BAH_COMPILER_VAR_1198[14] = "));\n";____BAH_COMPILER_VAR_1198[13] = tmpV;____BAH_COMPILER_VAR_1198[12] = ", sizeof(";____BAH_COMPILER_VAR_1198[11] = tmpV;____BAH_COMPILER_VAR_1198[10] = ", &";____BAH_COMPILER_VAR_1198[9] = pt.cont;____BAH_COMPILER_VAR_1198[8] = "->sendAny(";____BAH_COMPILER_VAR_1198[7] = pt.cont;____BAH_COMPILER_VAR_1198[6] = ";\n                    ";____BAH_COMPILER_VAR_1198[5] = nt.cont;____BAH_COMPILER_VAR_1198[4] = " = ";____BAH_COMPILER_VAR_1198[3] = tmpV;____BAH_COMPILER_VAR_1198[2] = " ";____BAH_COMPILER_VAR_1198[1] = string__str(&ct);____BAH_COMPILER_VAR_1198[0] = "\n                    ";char * ____BAH_COMPILER_VAR_1199 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1198, 15);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1199));
}

#line 2987 "/home/alois/Documents/bah-bah/src/parser.bah"
nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);

#line 2988 "/home/alois/Documents/bah-bah/src/parser.bah"
return nl;
}
}

#line 2991 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1200 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_1200);
    nl->data[____BAH_COMPILER_VAR_1200] = t;
};

#line 2993 "/home/alois/Documents/bah-bah/src/parser.bah"
return nl;
};

#line 2996 "/home/alois/Documents/bah-bah/src/parser.bah"

#line 1 "/home/alois/Documents/bah-bah/src/values.bah"
long int valueFunc(struct func* fn,struct variable* parent,__BAH_ARR_TYPE_Tok l,long int i,lineType ltp,struct Elems* elems){

#line 2 "/home/alois/Documents/bah-bah/src/values.bah"
long int tokPos = i;

#line 4 "/home/alois/Documents/bah-bah/src/values.bah"
struct genericFunc* generic= null;

#line 7 "/home/alois/Documents/bah-bah/src/values.bah"
long int errPos = -1;

#line 8 "/home/alois/Documents/bah-bah/src/values.bah"
if ((fn==null)) {

#line 9 "/home/alois/Documents/bah-bah/src/values.bah"
if ((i>0)) {

#line 10 "/home/alois/Documents/bah-bah/src/values.bah"
tokPos = i-1;

#line 11 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok pt = l->data[tokPos];

#line 12 "/home/alois/Documents/bah-bah/src/values.bah"
if ((pt.type==TOKEN_TYPE_VAR)) {

#line 13 "/home/alois/Documents/bah-bah/src/values.bah"
delete(l,tokPos);

#line 14 "/home/alois/Documents/bah-bah/src/values.bah"
errPos = pt.pos;

#line 15 "/home/alois/Documents/bah-bah/src/values.bah"
fn = searchFunc(pt.cont,elems,true);

#line 16 "/home/alois/Documents/bah-bah/src/values.bah"
if ((fn==null)) {

#line 17 "/home/alois/Documents/bah-bah/src/values.bah"
register long int j = 0;

#line 17 "/home/alois/Documents/bah-bah/src/values.bah"
for (; (j<len(generics)); 
#line 17 "/home/alois/Documents/bah-bah/src/values.bah"
++j) {

#line 18 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(generics->data[j]->baseFn->name, pt.cont) == 0)) {

#line 19 "/home/alois/Documents/bah-bah/src/values.bah"
generic = generics->data[j];

#line 20 "/home/alois/Documents/bah-bah/src/values.bah"
genericFunc__setCurrGeneric(generics->data[j],&pt);

#line 21 "/home/alois/Documents/bah-bah/src/values.bah"
fn = genericFunc__dupBaseFn(generics->data[j]);

#line 22 "/home/alois/Documents/bah-bah/src/values.bah"
break;
}
};

#line 25 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((j==len(generics)), 0)) {

#line 26 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&pt,"Unknown func {TOKEN}.");
}
}
}

#line 29 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 30 "/home/alois/Documents/bah-bah/src/values.bah"
++tokPos;
}
}

#line 32 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 33 "/home/alois/Documents/bah-bah/src/values.bah"
return i;
}
}

#line 37 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok fnt = l->data[tokPos];

#line 38 "/home/alois/Documents/bah-bah/src/values.bah"
if ((errPos!=-1)) {

#line 39 "/home/alois/Documents/bah-bah/src/values.bah"
fnt.pos = errPos;
}

#line 44 "/home/alois/Documents/bah-bah/src/values.bah"
if ((fn==null)) {

#line 45 "/home/alois/Documents/bah-bah/src/values.bah"
long int nbEncls = 1;

#line 46 "/home/alois/Documents/bah-bah/src/values.bah"
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);

#line 47 "/home/alois/Documents/bah-bah/src/values.bah"
i = tokPos+1;

#line 48 "/home/alois/Documents/bah-bah/src/values.bah"
fnt.ogCont = "(";

#line 49 "/home/alois/Documents/bah-bah/src/values.bah"
for (; (i<len(l)); 
#line 49 "/home/alois/Documents/bah-bah/src/values.bah"
++i) {

#line 50 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok t = l->data[i];

#line 51 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1201 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1201[1] = t.ogCont;____BAH_COMPILER_VAR_1201[0] = fnt.ogCont;char * ____BAH_COMPILER_VAR_1202 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1201, 2);fnt.ogCont = ____BAH_COMPILER_VAR_1202;

#line 52 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(t.cont, "(") == 0)||(strcmp(t.cont, "{") == 0)||(strcmp(t.cont, "[") == 0)) {

#line 53 "/home/alois/Documents/bah-bah/src/values.bah"
++nbEncls;
}

#line 54 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((strcmp(t.cont, ")") == 0)||(strcmp(t.cont, "}") == 0)||(strcmp(t.cont, "]") == 0)) {

#line 55 "/home/alois/Documents/bah-bah/src/values.bah"
--nbEncls;

#line 56 "/home/alois/Documents/bah-bah/src/values.bah"
if ((nbEncls==0)) {

#line 57 "/home/alois/Documents/bah-bah/src/values.bah"
break;
}
}

#line 60 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1203 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1203);
    memory->data[____BAH_COMPILER_VAR_1203] = t;
};

#line 62 "/home/alois/Documents/bah-bah/src/values.bah"
deleteRange(l,tokPos+1,i);

#line 63 "/home/alois/Documents/bah-bah/src/values.bah"
array(struct Tok)* memort = prePross(memory,(lineType)-1,elems);

#line 64 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok ft = memory->data[0];

#line 65 "/home/alois/Documents/bah-bah/src/values.bah"
fnt.cont = "(";

#line 66 "/home/alois/Documents/bah-bah/src/values.bah"
fnt.isOper = true;

#line 67 "/home/alois/Documents/bah-bah/src/values.bah"
fnt.isValue = true;

#line 68 "/home/alois/Documents/bah-bah/src/values.bah"
fnt.bahType = getTypeFromToken(&ft,true,elems);

#line 69 "/home/alois/Documents/bah-bah/src/values.bah"
register long int j = 0;

#line 69 "/home/alois/Documents/bah-bah/src/values.bah"
for (; (j<len(memory)); 
#line 69 "/home/alois/Documents/bah-bah/src/values.bah"
++j) {

#line 70 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok t = memory->data[j];

#line 71 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1204 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1204[1] = t.cont;____BAH_COMPILER_VAR_1204[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1205 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1204, 2);fnt.cont = ____BAH_COMPILER_VAR_1205;
};

#line 73 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1206 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1206[1] = ")";____BAH_COMPILER_VAR_1206[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1207 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1206, 2);fnt.cont = ____BAH_COMPILER_VAR_1207;

#line 74 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1208 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1208);
    l->data[____BAH_COMPILER_VAR_1208] = fnt;

#line 75 "/home/alois/Documents/bah-bah/src/values.bah"
return tokPos;
}

#line 79 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(fn->name, "exit") == 0)||(strcmp(fn->name, "panic") == 0)||(fn->exits==true)) {

#line 80 "/home/alois/Documents/bah-bah/src/values.bah"
if ((compilerState.isBranch==true)) {

#line 81 "/home/alois/Documents/bah-bah/src/values.bah"
elems->currFlowEnd = true;
}

#line 83 "/home/alois/Documents/bah-bah/src/values.bah"
setNullStateBranchFlowEnd(elems);
}

#line 87 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1209 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1209[1] = "(";____BAH_COMPILER_VAR_1209[0] = fn->name;char * ____BAH_COMPILER_VAR_1210 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1209, 2);fnt.cont = ____BAH_COMPILER_VAR_1210;

#line 88 "/home/alois/Documents/bah-bah/src/values.bah"
if ((fn->returns!=null)&&(strcmp(fn->returns->type, "") != 0)) {

#line 89 "/home/alois/Documents/bah-bah/src/values.bah"
fnt.isValue = true;

#line 90 "/home/alois/Documents/bah-bah/src/values.bah"
fnt.bahType = fn->returns->type;
}

#line 92 "/home/alois/Documents/bah-bah/src/values.bah"
fnt.isFunc = true;

#line 93 "/home/alois/Documents/bah-bah/src/values.bah"
fnt.type = TOKEN_TYPE_FUNC;

#line 96 "/home/alois/Documents/bah-bah/src/values.bah"
long int nbEncls = 1;

#line 97 "/home/alois/Documents/bah-bah/src/values.bah"
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);

#line 98 "/home/alois/Documents/bah-bah/src/values.bah"
i = tokPos+1;

#line 99 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1211 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1211[1] = "(";____BAH_COMPILER_VAR_1211[0] = fn->name;char * ____BAH_COMPILER_VAR_1212 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1211, 2);fnt.ogCont = ____BAH_COMPILER_VAR_1212;

#line 100 "/home/alois/Documents/bah-bah/src/values.bah"
for (; (i<len(l)); 
#line 100 "/home/alois/Documents/bah-bah/src/values.bah"
++i) {

#line 101 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok t = l->data[i];

#line 102 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1213 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1213[1] = t.ogCont;____BAH_COMPILER_VAR_1213[0] = fnt.ogCont;char * ____BAH_COMPILER_VAR_1214 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1213, 2);fnt.ogCont = ____BAH_COMPILER_VAR_1214;

#line 103 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(t.cont, "(") == 0)||(strcmp(t.cont, "{") == 0)||(strcmp(t.cont, "[") == 0)) {

#line 104 "/home/alois/Documents/bah-bah/src/values.bah"
++nbEncls;
}

#line 105 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((strcmp(t.cont, ")") == 0)||(strcmp(t.cont, "}") == 0)||(strcmp(t.cont, "]") == 0)) {

#line 106 "/home/alois/Documents/bah-bah/src/values.bah"
--nbEncls;

#line 107 "/home/alois/Documents/bah-bah/src/values.bah"
if ((nbEncls==0)) {

#line 108 "/home/alois/Documents/bah-bah/src/values.bah"
break;
}
}

#line 111 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1215 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1215);
    memory->data[____BAH_COMPILER_VAR_1215] = t;
};

#line 113 "/home/alois/Documents/bah-bah/src/values.bah"
deleteRange(l,tokPos+1,i);

#line 116 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(fn->name, "noCheck") == 0)) {

#line 117 "/home/alois/Documents/bah-bah/src/values.bah"
fnt.cont = "";

#line 118 "/home/alois/Documents/bah-bah/src/values.bah"
fnt.isOper = true;

#line 119 "/home/alois/Documents/bah-bah/src/values.bah"
fnt.isValue = true;

#line 120 "/home/alois/Documents/bah-bah/src/values.bah"
fnt.bahType = "ptr";

#line 121 "/home/alois/Documents/bah-bah/src/values.bah"
register long int j = 0;

#line 121 "/home/alois/Documents/bah-bah/src/values.bah"
for (; (j<len(memory)); 
#line 121 "/home/alois/Documents/bah-bah/src/values.bah"
++j) {

#line 122 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok t = memory->data[j];

#line 123 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1216 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1216[1] = t.cont;____BAH_COMPILER_VAR_1216[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1217 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1216, 2);fnt.cont = ____BAH_COMPILER_VAR_1217;
};

#line 125 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1218 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1218);
    l->data[____BAH_COMPILER_VAR_1218] = fnt;

#line 126 "/home/alois/Documents/bah-bah/src/values.bah"
return tokPos;
}

#line 129 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1219 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1219[4] = "\"";____BAH_COMPILER_VAR_1219[3] = intToStr(fnt.line);____BAH_COMPILER_VAR_1219[2] = ":";____BAH_COMPILER_VAR_1219[1] = compilerState.currentFile;____BAH_COMPILER_VAR_1219[0] = "\"";char * ____BAH_COMPILER_VAR_1220 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1219, 5);char * currLine = ____BAH_COMPILER_VAR_1220;

#line 130 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(fn->name, "panic") == 0)) {

#line 131 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok ____BAH_COMPILER_VAR_1221 = {};
____BAH_COMPILER_VAR_1221.cont = "";
____BAH_COMPILER_VAR_1221.ogCont = "";
____BAH_COMPILER_VAR_1221.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1221.line = 1;
____BAH_COMPILER_VAR_1221.begLine = 1;
____BAH_COMPILER_VAR_1221.bahType = "";
____BAH_COMPILER_VAR_1221.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_1221.cont = ",";
____BAH_COMPILER_VAR_1221.line = fnt.line;

    unsigned int ____BAH_COMPILER_VAR_1222 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1222);
    memory->data[____BAH_COMPILER_VAR_1222] = ____BAH_COMPILER_VAR_1221;

#line 136 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok ____BAH_COMPILER_VAR_1223 = {};
____BAH_COMPILER_VAR_1223.cont = "";
____BAH_COMPILER_VAR_1223.ogCont = "";
____BAH_COMPILER_VAR_1223.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1223.line = 1;
____BAH_COMPILER_VAR_1223.begLine = 1;
____BAH_COMPILER_VAR_1223.bahType = "";
____BAH_COMPILER_VAR_1223.type = TOKEN_TYPE_STR;
____BAH_COMPILER_VAR_1223.cont = currLine;
____BAH_COMPILER_VAR_1223.line = fnt.line;

    unsigned int ____BAH_COMPILER_VAR_1224 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1224);
    memory->data[____BAH_COMPILER_VAR_1224] = ____BAH_COMPILER_VAR_1223;

#line 141 "/home/alois/Documents/bah-bah/src/values.bah"
fn = searchFunc("__BAH_panic",elems,true);

#line 142 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1225 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1225[1] = "(";____BAH_COMPILER_VAR_1225[0] = fn->name;char * ____BAH_COMPILER_VAR_1226 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1225, 2);fnt.cont = ____BAH_COMPILER_VAR_1226;
}

#line 143 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((strcmp(fn->name, "__dumpSymbols") == 0)) {

#line 144 "/home/alois/Documents/bah-bah/src/values.bah"
array(struct variable*)* symbols = memoryAlloc(sizeof(array(struct variable*)));

symbols->length = 0;
symbols->elemSize = sizeof(struct variable*);

#line 145 "/home/alois/Documents/bah-bah/src/values.bah"
register long int j = 0;

#line 145 "/home/alois/Documents/bah-bah/src/values.bah"
for (; (j<len(elems->vars)); 
#line 145 "/home/alois/Documents/bah-bah/src/values.bah"
++j) {

#line 146 "/home/alois/Documents/bah-bah/src/values.bah"
struct variable* v = elems->vars->data[j];

#line 147 "/home/alois/Documents/bah-bah/src/values.bah"
if ((v->isConst==false)) {

#line 148 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1227 = len(symbols);
    __Bah_realocate_arr(symbols, ____BAH_COMPILER_VAR_1227);
    symbols->data[____BAH_COMPILER_VAR_1227] = v;
}
};

#line 151 "/home/alois/Documents/bah-bah/src/values.bah"
struct variable* ____BAH_COMPILER_VAR_1228 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1228->name = "";
____BAH_COMPILER_VAR_1228->type = "";
____BAH_COMPILER_VAR_1228->constVal = "";
____BAH_COMPILER_VAR_1228->from = "";
____BAH_COMPILER_VAR_1228->name = genCompilerVar();
____BAH_COMPILER_VAR_1228->type = "[]reflectElement";
____BAH_COMPILER_VAR_1228->isArray = true;
struct variable* tmpV = ____BAH_COMPILER_VAR_1228;

#line 156 "/home/alois/Documents/bah-bah/src/values.bah"
char * decls = "";

#line 157 "/home/alois/Documents/bah-bah/src/values.bah"
j = 0;

#line 157 "/home/alois/Documents/bah-bah/src/values.bah"
for (; (j<len(symbols)); 
#line 157 "/home/alois/Documents/bah-bah/src/values.bah"
++j) {

#line 158 "/home/alois/Documents/bah-bah/src/values.bah"
struct variable* v = symbols->data[j];

#line 159 "/home/alois/Documents/bah-bah/src/values.bah"
char * vname = v->name;

#line 160 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strCount(v->type,"*")==0)) {

#line 161 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1229 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1229[1] = v->name;____BAH_COMPILER_VAR_1229[0] = "&";char * ____BAH_COMPILER_VAR_1230 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1229, 2);vname = ____BAH_COMPILER_VAR_1230;
}

#line 163 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok ____BAH_COMPILER_VAR_1231 = {};
____BAH_COMPILER_VAR_1231.cont = "";
____BAH_COMPILER_VAR_1231.ogCont = "";
____BAH_COMPILER_VAR_1231.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1231.line = 1;
____BAH_COMPILER_VAR_1231.begLine = 1;
____BAH_COMPILER_VAR_1231.bahType = "";
____BAH_COMPILER_VAR_1231.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_1231.cont = vname;
____BAH_COMPILER_VAR_1231.bahType = v->type;
____BAH_COMPILER_VAR_1231.isValue = true;
struct Tok tmpT = ____BAH_COMPILER_VAR_1231;

#line 169 "/home/alois/Documents/bah-bah/src/values.bah"
tmpT = parseReflect(tmpT,v->type,elems,true,v->name,"0");

#line 170 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1232 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_1232[5] = ";\n";____BAH_COMPILER_VAR_1232[4] = tmpT.cont;____BAH_COMPILER_VAR_1232[3] = "] = ";____BAH_COMPILER_VAR_1232[2] = intToStr(j);____BAH_COMPILER_VAR_1232[1] = "->data[";____BAH_COMPILER_VAR_1232[0] = tmpV->name;char * ____BAH_COMPILER_VAR_1233 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1232, 6);char** ____BAH_COMPILER_VAR_1234 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1234[1] = ____BAH_COMPILER_VAR_1233;____BAH_COMPILER_VAR_1234[0] = decls;char * ____BAH_COMPILER_VAR_1235 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1234, 2);decls = ____BAH_COMPILER_VAR_1235;
};

#line 172 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1236 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_1236);
    elems->vars->data[____BAH_COMPILER_VAR_1236] = tmpV;

#line 173 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1237 = alloca(15 * sizeof(char*));____BAH_COMPILER_VAR_1237[14] = "\n        ";____BAH_COMPILER_VAR_1237[13] = decls;____BAH_COMPILER_VAR_1237[12] = "->elemSize = sizeof(struct reflectElement);\n        ";____BAH_COMPILER_VAR_1237[11] = tmpV->name;____BAH_COMPILER_VAR_1237[10] = ";\n        ";____BAH_COMPILER_VAR_1237[9] = intToStr(len(symbols));____BAH_COMPILER_VAR_1237[8] = "->length = ";____BAH_COMPILER_VAR_1237[7] = tmpV->name;____BAH_COMPILER_VAR_1237[6] = ");\n        ";____BAH_COMPILER_VAR_1237[5] = intToStr(len(symbols));____BAH_COMPILER_VAR_1237[4] = "->data = memoryAlloc(sizeof(struct reflectElement) * ";____BAH_COMPILER_VAR_1237[3] = tmpV->name;____BAH_COMPILER_VAR_1237[2] = " = memoryAlloc(sizeof(array(struct reflectElement)));\n        ";____BAH_COMPILER_VAR_1237[1] = tmpV->name;____BAH_COMPILER_VAR_1237[0] = "\n        array(struct reflectElement)* ";char * ____BAH_COMPILER_VAR_1238 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1237, 15);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1238));

#line 180 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok ____BAH_COMPILER_VAR_1239 = {};
____BAH_COMPILER_VAR_1239.cont = "";
____BAH_COMPILER_VAR_1239.ogCont = "";
____BAH_COMPILER_VAR_1239.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1239.line = 1;
____BAH_COMPILER_VAR_1239.begLine = 1;
____BAH_COMPILER_VAR_1239.bahType = "";
____BAH_COMPILER_VAR_1239.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_1239.cont = tmpV->name;
____BAH_COMPILER_VAR_1239.line = fnt.line;
____BAH_COMPILER_VAR_1239.isValue = true;

    unsigned int ____BAH_COMPILER_VAR_1240 = 0;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1240);
    memory->data[____BAH_COMPILER_VAR_1240] = ____BAH_COMPILER_VAR_1239;
}

#line 186 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((strcmp(fn->name, "breakPoint") == 0)) {

#line 187 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok ____BAH_COMPILER_VAR_1241 = {};
____BAH_COMPILER_VAR_1241.cont = "";
____BAH_COMPILER_VAR_1241.ogCont = "";
____BAH_COMPILER_VAR_1241.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1241.line = 1;
____BAH_COMPILER_VAR_1241.begLine = 1;
____BAH_COMPILER_VAR_1241.bahType = "";
____BAH_COMPILER_VAR_1241.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_1241.cont = "__dumpSymbols";
____BAH_COMPILER_VAR_1241.line = fnt.line;
struct Tok ____BAH_COMPILER_VAR_1242 = {};
____BAH_COMPILER_VAR_1242.cont = "";
____BAH_COMPILER_VAR_1242.ogCont = "";
____BAH_COMPILER_VAR_1242.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1242.line = 1;
____BAH_COMPILER_VAR_1242.begLine = 1;
____BAH_COMPILER_VAR_1242.bahType = "";
____BAH_COMPILER_VAR_1242.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_1242.cont = "(";
____BAH_COMPILER_VAR_1242.line = fnt.line;
struct Tok ____BAH_COMPILER_VAR_1243 = {};
____BAH_COMPILER_VAR_1243.cont = "";
____BAH_COMPILER_VAR_1243.ogCont = "";
____BAH_COMPILER_VAR_1243.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1243.line = 1;
____BAH_COMPILER_VAR_1243.begLine = 1;
____BAH_COMPILER_VAR_1243.bahType = "";
____BAH_COMPILER_VAR_1243.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_1243.cont = ")";
____BAH_COMPILER_VAR_1243.line = fnt.line;
memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 3;
memory->elemSize = sizeof(struct Tok);
memory->data = memoryAlloc(sizeof(struct Tok) * 50);
                    memory->realLength = 50;
memory->data[0] = ____BAH_COMPILER_VAR_1241;
memory->data[1] = ____BAH_COMPILER_VAR_1242;
memory->data[2] = ____BAH_COMPILER_VAR_1243;

#line 204 "/home/alois/Documents/bah-bah/src/values.bah"
memory = prePross(memory,LINE_TYPE_FN_CALL,elems);

#line 205 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok ____BAH_COMPILER_VAR_1244 = {};
____BAH_COMPILER_VAR_1244.cont = "";
____BAH_COMPILER_VAR_1244.ogCont = "";
____BAH_COMPILER_VAR_1244.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1244.line = 1;
____BAH_COMPILER_VAR_1244.begLine = 1;
____BAH_COMPILER_VAR_1244.bahType = "";
____BAH_COMPILER_VAR_1244.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_1244.cont = ",";
____BAH_COMPILER_VAR_1244.line = fnt.line;

    unsigned int ____BAH_COMPILER_VAR_1245 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1245);
    memory->data[____BAH_COMPILER_VAR_1245] = ____BAH_COMPILER_VAR_1244;

#line 210 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok ____BAH_COMPILER_VAR_1246 = {};
____BAH_COMPILER_VAR_1246.cont = "";
____BAH_COMPILER_VAR_1246.ogCont = "";
____BAH_COMPILER_VAR_1246.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1246.line = 1;
____BAH_COMPILER_VAR_1246.begLine = 1;
____BAH_COMPILER_VAR_1246.bahType = "";
____BAH_COMPILER_VAR_1246.type = TOKEN_TYPE_STR;
____BAH_COMPILER_VAR_1246.cont = currLine;
____BAH_COMPILER_VAR_1246.line = fnt.line;

    unsigned int ____BAH_COMPILER_VAR_1247 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1247);
    memory->data[____BAH_COMPILER_VAR_1247] = ____BAH_COMPILER_VAR_1246;

#line 215 "/home/alois/Documents/bah-bah/src/values.bah"
fn = searchFunc("breakPoint__inner",elems,true);

#line 216 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1248 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1248[1] = "(";____BAH_COMPILER_VAR_1248[0] = fn->name;char * ____BAH_COMPILER_VAR_1249 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1248, 2);fnt.cont = ____BAH_COMPILER_VAR_1249;
}

#line 217 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((strcmp(fn->name, "sizeof") == 0)) {

#line 218 "/home/alois/Documents/bah-bah/src/values.bah"
char * tp = "";

#line 219 "/home/alois/Documents/bah-bah/src/values.bah"
register long int j = 0;

#line 219 "/home/alois/Documents/bah-bah/src/values.bah"
for (; (j<len(memory)); 
#line 219 "/home/alois/Documents/bah-bah/src/values.bah"
++j) {

#line 220 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok tmpT = memory->data[j];

#line 221 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1250 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1250[1] = tmpT.cont;____BAH_COMPILER_VAR_1250[0] = tp;char * ____BAH_COMPILER_VAR_1251 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1250, 2);tp = ____BAH_COMPILER_VAR_1251;
};

#line 223 "/home/alois/Documents/bah-bah/src/values.bah"
struct variable* tmpV = searchVar(tp,elems);

#line 224 "/home/alois/Documents/bah-bah/src/values.bah"
if ((tmpV!=null)) {

#line 225 "/home/alois/Documents/bah-bah/src/values.bah"
struct string cType = getCType(tmpV->type,elems);

#line 226 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1252 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1252[1] = ")";____BAH_COMPILER_VAR_1252[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_1253 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1252, 2);char** ____BAH_COMPILER_VAR_1254 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1254[1] = ____BAH_COMPILER_VAR_1253;____BAH_COMPILER_VAR_1254[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1255 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1254, 2);fnt.cont = ____BAH_COMPILER_VAR_1255;
}

#line 227 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 228 "/home/alois/Documents/bah-bah/src/values.bah"
struct string cType = getCType(tp,elems);

#line 229 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((cType.length==0), 0)) {

#line 230 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok ft = memory->data[0];

#line 231 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&ft,"Cannot get size of {TOKEN}.");
}

#line 233 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1256 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1256[1] = ")";____BAH_COMPILER_VAR_1256[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_1257 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1256, 2);char** ____BAH_COMPILER_VAR_1258 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1258[1] = ____BAH_COMPILER_VAR_1257;____BAH_COMPILER_VAR_1258[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1259 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1258, 2);fnt.cont = ____BAH_COMPILER_VAR_1259;
}

#line 235 "/home/alois/Documents/bah-bah/src/values.bah"
fnt.type = TOKEN_TYPE_FUNC;

#line 236 "/home/alois/Documents/bah-bah/src/values.bah"
fnt.isFunc = true;

#line 237 "/home/alois/Documents/bah-bah/src/values.bah"
fnt.bahType = "int";

#line 238 "/home/alois/Documents/bah-bah/src/values.bah"
fnt.bahRef = fn;

#line 239 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1260 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1260);
    l->data[____BAH_COMPILER_VAR_1260] = fnt;

#line 240 "/home/alois/Documents/bah-bah/src/values.bah"
return tokPos;
}

#line 244 "/home/alois/Documents/bah-bah/src/values.bah"
if ((len(memory)>0)) {

#line 245 "/home/alois/Documents/bah-bah/src/values.bah"
memory = prePross(memory,ltp,elems);
}

#line 248 "/home/alois/Documents/bah-bah/src/values.bah"
long int argIndex = 0;

#line 249 "/home/alois/Documents/bah-bah/src/values.bah"
if ((parent!=null)) {

#line 250 "/home/alois/Documents/bah-bah/src/values.bah"
char * amp = "&";

#line 251 "/home/alois/Documents/bah-bah/src/values.bah"
if (isRCPpointerType(parent->type)) {

#line 252 "/home/alois/Documents/bah-bah/src/values.bah"
amp = "";
}

#line 254 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1261 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1261[1] = parent->name;____BAH_COMPILER_VAR_1261[0] = amp;char * ____BAH_COMPILER_VAR_1262 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1261, 2);char** ____BAH_COMPILER_VAR_1263 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1263[1] = ____BAH_COMPILER_VAR_1262;____BAH_COMPILER_VAR_1263[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1264 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1263, 2);fnt.cont = ____BAH_COMPILER_VAR_1264;

#line 255 "/home/alois/Documents/bah-bah/src/values.bah"
++argIndex;

#line 256 "/home/alois/Documents/bah-bah/src/values.bah"
if ((len(fn->args)>argIndex)) {

#line 257 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1265 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1265[1] = ",";____BAH_COMPILER_VAR_1265[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1266 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1265, 2);fnt.cont = ____BAH_COMPILER_VAR_1266;
}
}

#line 261 "/home/alois/Documents/bah-bah/src/values.bah"
long int ogFntContL = strlen(fnt.cont);

#line 264 "/home/alois/Documents/bah-bah/src/values.bah"
register long int j = 0;

#line 264 "/home/alois/Documents/bah-bah/src/values.bah"
for (; (j<len(memory)); 
#line 264 "/home/alois/Documents/bah-bah/src/values.bah"
++j) {

#line 265 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok t = memory->data[j];

#line 266 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((argIndex==len(fn->args)), 0)) {

#line 267 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&t,"Too many arguments, expected ')' not {TOKEN}.");
}

#line 269 "/home/alois/Documents/bah-bah/src/values.bah"
struct variable* arg = fn->args->data[argIndex];

#line 270 "/home/alois/Documents/bah-bah/src/values.bah"
char * tt = getTypeFromToken(&t,true,elems);

#line 272 "/home/alois/Documents/bah-bah/src/values.bah"
if (((fn->isImported==true)||isInside(BAH_DIR,fn->file))&&(t.type==TOKEN_TYPE_VAR)) {

#line 273 "/home/alois/Documents/bah-bah/src/values.bah"
fixMeTestVar(&t,ltp,elems);
}

#line 276 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(arg->type, "reflectElement") == 0)&&(strcmp(tt, "reflectElement") != 0)) {

#line 277 "/home/alois/Documents/bah-bah/src/values.bah"
t = parseReflect(t,tt,elems,false,t.cont,"0");

#line 278 "/home/alois/Documents/bah-bah/src/values.bah"
tt = "reflectElement";
}

#line 281 "/home/alois/Documents/bah-bah/src/values.bah"
if ((generic!=null)&&(strcmp(arg->type, "<any>") == 0)) {

#line 282 "/home/alois/Documents/bah-bah/src/values.bah"
arg->type = tt;

#line 283 "/home/alois/Documents/bah-bah/src/values.bah"
struct string tts = string(tt);

#line 284 "/home/alois/Documents/bah-bah/src/values.bah"
string__replace(&tts,"*","_AST_");

#line 285 "/home/alois/Documents/bah-bah/src/values.bah"
string__replace(&tts,":","_DP_");

#line 286 "/home/alois/Documents/bah-bah/src/values.bah"
string__replace(&tts,"[]","_ARR_");

#line 287 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1267 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1267[1] = string__str(&tts);____BAH_COMPILER_VAR_1267[0] = "__";char * ____BAH_COMPILER_VAR_1268 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1267, 2);char** ____BAH_COMPILER_VAR_1269 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1269[1] = ____BAH_COMPILER_VAR_1268;____BAH_COMPILER_VAR_1269[0] = fn->name;char * ____BAH_COMPILER_VAR_1270 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1269, 2);fn->name = ____BAH_COMPILER_VAR_1270;
}

#line 288 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 289 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((compTypes(arg->type,tt)==false), 0)) {

#line 290 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1271 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1271[4] = " in function call.";____BAH_COMPILER_VAR_1271[3] = arg->type;____BAH_COMPILER_VAR_1271[2] = ") as ";____BAH_COMPILER_VAR_1271[1] = tt;____BAH_COMPILER_VAR_1271[0] = "Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_1272 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1271, 5);throwErr(&t,____BAH_COMPILER_VAR_1272);
}
}

#line 294 "/home/alois/Documents/bah-bah/src/values.bah"
checkCanBeNull(&t,tt,elems);

#line 296 "/home/alois/Documents/bah-bah/src/values.bah"
if ((RCPavailable()==true)&&(ltp==LINE_TYPE_VAR)&&(t.type==TOKEN_TYPE_VAR)&&(t.isOper==false)&&(currSetVar!=null)&&(strcmp(t.cont, currSetVar->name) == 0)&&isRCPtype(currSetVar->type,elems)) {

#line 297 "/home/alois/Documents/bah-bah/src/values.bah"
OUTPUT = rope__add(OUTPUT, incrVar(currSetVar,elems));
}

#line 300 "/home/alois/Documents/bah-bah/src/values.bah"
if ((t.type==TOKEN_TYPE_FUNC)) {

#line 301 "/home/alois/Documents/bah-bah/src/values.bah"
struct func* afn = searchFuncByToken(&t,elems);

#line 302 "/home/alois/Documents/bah-bah/src/values.bah"
if ((afn!=null)&&(isRCPtype(afn->returns->type,elems)==true)) {

#line 303 "/home/alois/Documents/bah-bah/src/values.bah"
t.cont = registerRCPvar(afn->returns->type,t.cont,elems);
}
}

#line 307 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1273 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1273[1] = t.cont;____BAH_COMPILER_VAR_1273[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1274 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1273, 2);fnt.cont = ____BAH_COMPILER_VAR_1274;

#line 309 "/home/alois/Documents/bah-bah/src/values.bah"
++argIndex;

#line 311 "/home/alois/Documents/bah-bah/src/values.bah"
if ((j+1<len(memory))) {

#line 312 "/home/alois/Documents/bah-bah/src/values.bah"
++j;

#line 313 "/home/alois/Documents/bah-bah/src/values.bah"
t = memory->data[j];

#line 314 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((strcmp(t.cont, ",") != 0), 0)) {

#line 315 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&t,"Need separator between arguments, not {TOKEN}.");
}

#line 317 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1275 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1275[1] = ",";____BAH_COMPILER_VAR_1275[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1276 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1275, 2);fnt.cont = ____BAH_COMPILER_VAR_1276;
}
};

#line 322 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((argIndex!=len(fn->args)), 0)) {

#line 323 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok lt = l->data[tokPos];

#line 324 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1277 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1277[2] = "'.";____BAH_COMPILER_VAR_1277[1] = fn->name;____BAH_COMPILER_VAR_1277[0] = "Not enough argument {TOKEN}, calling '";char * ____BAH_COMPILER_VAR_1278 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1277, 3);throwErr(&lt,____BAH_COMPILER_VAR_1278);
}

#line 327 "/home/alois/Documents/bah-bah/src/values.bah"
if ((generic!=null)) {

#line 328 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1279 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1279[3] = cpstringSubsitute(fnt.cont, ogFntContL, strlen(fnt.cont));____BAH_COMPILER_VAR_1279[2] = "(";____BAH_COMPILER_VAR_1279[1] = fn->name;____BAH_COMPILER_VAR_1279[0] = "__generic_";char * ____BAH_COMPILER_VAR_1280 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1279, 4);fnt.cont = ____BAH_COMPILER_VAR_1280;

#line 329 "/home/alois/Documents/bah-bah/src/values.bah"
if ((genericFunc__isAlreadyDecl(generic,fn->name)==false)) {

#line 330 "/home/alois/Documents/bah-bah/src/values.bah"
genericFunc__declare(generic,fn,elems);
}
}

#line 334 "/home/alois/Documents/bah-bah/src/values.bah"
fnt.bahRef = fn;

#line 335 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1281 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1281[1] = ")";____BAH_COMPILER_VAR_1281[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1282 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1281, 2);fnt.cont = ____BAH_COMPILER_VAR_1282;

#line 336 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1283 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1283);
    l->data[____BAH_COMPILER_VAR_1283] = fnt;

#line 337 "/home/alois/Documents/bah-bah/src/values.bah"
return tokPos;
};

#line 341 "/home/alois/Documents/bah-bah/src/values.bah"
long int valueStruct(__BAH_ARR_TYPE_Tok l,long int i,lineType ltp,struct Elems* elems){

#line 342 "/home/alois/Documents/bah-bah/src/values.bah"
long int tokPos = i-1;

#line 346 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok t = l->data[i-1];

#line 347 "/home/alois/Documents/bah-bah/src/values.bah"
char * tt = getTypeFromToken(&t,true,elems);

#line 349 "/home/alois/Documents/bah-bah/src/values.bah"
struct cStruct* s = searchStruct(tt,elems);

#line 350 "/home/alois/Documents/bah-bah/src/values.bah"
if ((s==null)) {

#line 351 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((tt[strlen(tt)-1]==33), 0)) {

#line 352 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1284 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1284[2] = ") as structure.";____BAH_COMPILER_VAR_1284[1] = tt;____BAH_COMPILER_VAR_1284[0] = "Cannot use maybe value {TOKEN} (";char * ____BAH_COMPILER_VAR_1285 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1284, 3);throwErr(&t,____BAH_COMPILER_VAR_1285);
}

#line 353 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 354 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1286 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1286[2] = ").";____BAH_COMPILER_VAR_1286[1] = tt;____BAH_COMPILER_VAR_1286[0] = "Unkown struct {TOKEN} (";char * ____BAH_COMPILER_VAR_1287 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1286, 3);throwErr(&t,____BAH_COMPILER_VAR_1287);
}
}

#line 358 "/home/alois/Documents/bah-bah/src/values.bah"
checkCanBeNull(&t,tt,elems);

#line 361 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok nt = l->data[i+1];

#line 363 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((nt.isValue==false), 0)) {

#line 364 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&nt,"Cannot use {TOKEN} as member.");
}

#line 366 "/home/alois/Documents/bah-bah/src/values.bah"
deleteRange(l,i,i+1);

#line 369 "/home/alois/Documents/bah-bah/src/values.bah"
char * sep = ".";

#line 370 "/home/alois/Documents/bah-bah/src/values.bah"
if (isRCPpointerType(tt)) {

#line 371 "/home/alois/Documents/bah-bah/src/values.bah"
sep = "->";
}

#line 375 "/home/alois/Documents/bah-bah/src/values.bah"
if ((t.type==TOKEN_TYPE_VAR)) {

#line 376 "/home/alois/Documents/bah-bah/src/values.bah"
fixMeTestVar(&t,ltp,elems);
}

#line 380 "/home/alois/Documents/bah-bah/src/values.bah"
if ((i<len(l))) {

#line 381 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok ntt = l->data[i];

#line 382 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(ntt.cont, "(") == 0)) {

#line 383 "/home/alois/Documents/bah-bah/src/values.bah"
struct variable* parent= null;

#line 384 "/home/alois/Documents/bah-bah/src/values.bah"
if ((t.type==TOKEN_TYPE_VAR)) {

#line 385 "/home/alois/Documents/bah-bah/src/values.bah"
if ((t.bahRef!=null)) {

#line 387 "/home/alois/Documents/bah-bah/src/values.bah"
parent = t.bahRef;
}

#line 388 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 389 "/home/alois/Documents/bah-bah/src/values.bah"
parent = searchVar(t.cont,elems);
}
}

#line 391 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 392 "/home/alois/Documents/bah-bah/src/values.bah"
char * tmpV = genCompilerVar();

#line 393 "/home/alois/Documents/bah-bah/src/values.bah"
struct string cType = getCType(tt,elems);

#line 394 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1288 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_1288[6] = ";\n                ";____BAH_COMPILER_VAR_1288[5] = t.cont;____BAH_COMPILER_VAR_1288[4] = " = ";____BAH_COMPILER_VAR_1288[3] = tmpV;____BAH_COMPILER_VAR_1288[2] = " ";____BAH_COMPILER_VAR_1288[1] = string__str(&cType);____BAH_COMPILER_VAR_1288[0] = "\n                ";char * ____BAH_COMPILER_VAR_1289 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1288, 7);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1289));

#line 397 "/home/alois/Documents/bah-bah/src/values.bah"
t.cont = tmpV;

#line 398 "/home/alois/Documents/bah-bah/src/values.bah"
struct variable* ____BAH_COMPILER_VAR_1290 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1290->name = "";
____BAH_COMPILER_VAR_1290->type = "";
____BAH_COMPILER_VAR_1290->constVal = "";
____BAH_COMPILER_VAR_1290->from = "";
____BAH_COMPILER_VAR_1290->name = tmpV;
____BAH_COMPILER_VAR_1290->type = tt;
parent = ____BAH_COMPILER_VAR_1290;

#line 402 "/home/alois/Documents/bah-bah/src/values.bah"
if (RCPavailable()) {

#line 403 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1291 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_1291);
    elems->vars->data[____BAH_COMPILER_VAR_1291] = parent;
}
}

#line 406 "/home/alois/Documents/bah-bah/src/values.bah"
struct func* fn = searchStructMethod(nt.cont,s,elems);

#line 407 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((fn==null), 0)) {

#line 408 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1292 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1292[2] = ".";____BAH_COMPILER_VAR_1292[1] = s->name;____BAH_COMPILER_VAR_1292[0] = "Unknown method {TOKEN} in struct ";char * ____BAH_COMPILER_VAR_1293 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1292, 3);throwErr(&nt,____BAH_COMPILER_VAR_1293);
}

#line 410 "/home/alois/Documents/bah-bah/src/values.bah"
if ((t.type==TOKEN_TYPE_VAR)) {

#line 411 "/home/alois/Documents/bah-bah/src/values.bah"
if ((fn->isImported==true)||(fn->isMut==true)) {

#line 412 "/home/alois/Documents/bah-bah/src/values.bah"
struct variable* rp = searchVarByToken(&t,elems);

#line 413 "/home/alois/Documents/bah-bah/src/values.bah"
rp->lastSet = elems;

#line 414 "/home/alois/Documents/bah-bah/src/values.bah"
if ((rp->isArg==true)) {

#line 415 "/home/alois/Documents/bah-bah/src/values.bah"
currentFn->isMut = true;
}
}
}

#line 419 "/home/alois/Documents/bah-bah/src/values.bah"
if ((fn->isVar==true)) {

#line 420 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1294 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1294[2] = fn->name;____BAH_COMPILER_VAR_1294[1] = sep;____BAH_COMPILER_VAR_1294[0] = t.cont;char * ____BAH_COMPILER_VAR_1295 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1294, 3);fn->name = ____BAH_COMPILER_VAR_1295;
}

#line 422 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((parent==null), 0)) {

#line 423 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&t,"Could not find structure {TOKEN}.");
}

#line 425 "/home/alois/Documents/bah-bah/src/values.bah"
valueFunc(fn,parent,l,i,ltp,elems);

#line 426 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok fnt = l->data[i];

#line 427 "/home/alois/Documents/bah-bah/src/values.bah"
delete(l,i);

#line 428 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1296 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1296[2] = nt.ogCont;____BAH_COMPILER_VAR_1296[1] = ".";____BAH_COMPILER_VAR_1296[0] = t.ogCont;char * ____BAH_COMPILER_VAR_1297 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1296, 3);fnt.ogCont = ____BAH_COMPILER_VAR_1297;

#line 429 "/home/alois/Documents/bah-bah/src/values.bah"
fnt.pos = t.pos;

#line 432 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1298 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1298);
    l->data[____BAH_COMPILER_VAR_1298] = fnt;

#line 433 "/home/alois/Documents/bah-bah/src/values.bah"
return tokPos;
}
}

#line 438 "/home/alois/Documents/bah-bah/src/values.bah"
struct structMemb* m = searchStructMemb(nt.cont,s,elems);

#line 439 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((m==null), 0)) {

#line 440 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1299 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1299[2] = "'.";____BAH_COMPILER_VAR_1299[1] = s->name;____BAH_COMPILER_VAR_1299[0] = "Unknown struct member {TOKEN} in struct '";char * ____BAH_COMPILER_VAR_1300 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1299, 3);throwErr(&nt,____BAH_COMPILER_VAR_1300);
}

#line 442 "/home/alois/Documents/bah-bah/src/values.bah"
char * ast = "";

#line 443 "/home/alois/Documents/bah-bah/src/values.bah"
if ((t.cont[0]==38)) {

#line 444 "/home/alois/Documents/bah-bah/src/values.bah"
ast = "*";
}

#line 446 "/home/alois/Documents/bah-bah/src/values.bah"
if ((m->isFn==true)) {

#line 447 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1301 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1301[2] = m->name;____BAH_COMPILER_VAR_1301[1] = "__";____BAH_COMPILER_VAR_1301[0] = s->name;char * ____BAH_COMPILER_VAR_1302 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1301, 3);t.cont = ____BAH_COMPILER_VAR_1302;
}

#line 448 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 449 "/home/alois/Documents/bah-bah/src/values.bah"
if ((t.type==TOKEN_TYPE_VAR)) {

#line 450 "/home/alois/Documents/bah-bah/src/values.bah"
t.parent = searchVarByToken(&t,elems);
}

#line 452 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1303 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1303[1] = nt.cont;____BAH_COMPILER_VAR_1303[0] = sep;char * ____BAH_COMPILER_VAR_1304 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1303, 2);char** ____BAH_COMPILER_VAR_1305 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1305[1] = ____BAH_COMPILER_VAR_1304;____BAH_COMPILER_VAR_1305[0] = t.cont;char * ____BAH_COMPILER_VAR_1306 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1305, 2);t.cont = ____BAH_COMPILER_VAR_1306;
}

#line 454 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1307 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1307[1] = nt.cont;____BAH_COMPILER_VAR_1307[0] = ".";char * ____BAH_COMPILER_VAR_1308 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1307, 2);char** ____BAH_COMPILER_VAR_1309 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1309[1] = ____BAH_COMPILER_VAR_1308;____BAH_COMPILER_VAR_1309[0] = t.ogCont;char * ____BAH_COMPILER_VAR_1310 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1309, 2);t.ogCont = ____BAH_COMPILER_VAR_1310;

#line 455 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1311 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1311[1] = ast;____BAH_COMPILER_VAR_1311[0] = m->type;char * ____BAH_COMPILER_VAR_1312 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1311, 2);t.bahType = ____BAH_COMPILER_VAR_1312;

#line 456 "/home/alois/Documents/bah-bah/src/values.bah"
struct variable* ____BAH_COMPILER_VAR_1313 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1313->name = "";
____BAH_COMPILER_VAR_1313->type = "";
____BAH_COMPILER_VAR_1313->constVal = "";
____BAH_COMPILER_VAR_1313->from = "";
____BAH_COMPILER_VAR_1313->name = t.cont;
____BAH_COMPILER_VAR_1313->type = t.bahType;
t.bahRef = ____BAH_COMPILER_VAR_1313;

#line 461 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1314 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1314);
    l->data[____BAH_COMPILER_VAR_1314] = t;

#line 462 "/home/alois/Documents/bah-bah/src/values.bah"
return tokPos;
};

#line 465 "/home/alois/Documents/bah-bah/src/values.bah"
long int valueArr(__BAH_ARR_TYPE_Tok l,long int i,lineType ltp,struct Elems* elems){

#line 466 "/home/alois/Documents/bah-bah/src/values.bah"
long int tokPos = i-1;

#line 468 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok pt = l->data[tokPos];

#line 469 "/home/alois/Documents/bah-bah/src/values.bah"
delete(l,tokPos);

#line 470 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((pt.isValue==false), 0)) {

#line 471 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&pt,"Cannot use {TOKEN} as value (array).");
}

#line 473 "/home/alois/Documents/bah-bah/src/values.bah"
char * ____BAH_COMPILER_VAR_1315 =getTypeFromToken(&pt,true,elems);struct string ptt = string(____BAH_COMPILER_VAR_1315);

#line 476 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok t = pt;

#line 477 "/home/alois/Documents/bah-bah/src/values.bah"
t.isValue = true;

#line 478 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1316 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1316[1] = "[";____BAH_COMPILER_VAR_1316[0] = t.ogCont;char * ____BAH_COMPILER_VAR_1317 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1316, 2);t.ogCont = ____BAH_COMPILER_VAR_1317;

#line 481 "/home/alois/Documents/bah-bah/src/values.bah"
long int nbEncls = 1;

#line 482 "/home/alois/Documents/bah-bah/src/values.bah"
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);

#line 483 "/home/alois/Documents/bah-bah/src/values.bah"
i = tokPos+1;

#line 484 "/home/alois/Documents/bah-bah/src/values.bah"
for (; (i<len(l)); 
#line 484 "/home/alois/Documents/bah-bah/src/values.bah"
++i) {

#line 485 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok tmpT = l->data[i];

#line 486 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(tmpT.cont, "(") == 0)||(strcmp(tmpT.cont, "{") == 0)||(strcmp(tmpT.cont, "[") == 0)) {

#line 487 "/home/alois/Documents/bah-bah/src/values.bah"
++nbEncls;
}

#line 488 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((strcmp(tmpT.cont, ")") == 0)||(strcmp(tmpT.cont, "}") == 0)||(strcmp(tmpT.cont, "]") == 0)) {

#line 489 "/home/alois/Documents/bah-bah/src/values.bah"
--nbEncls;

#line 490 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1318 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1318[1] = "]";____BAH_COMPILER_VAR_1318[0] = t.ogCont;char * ____BAH_COMPILER_VAR_1319 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1318, 2);t.ogCont = ____BAH_COMPILER_VAR_1319;

#line 491 "/home/alois/Documents/bah-bah/src/values.bah"
if ((nbEncls==0)) {

#line 492 "/home/alois/Documents/bah-bah/src/values.bah"
break;
}
}

#line 495 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1320 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1320[1] = tmpT.ogCont;____BAH_COMPILER_VAR_1320[0] = t.ogCont;char * ____BAH_COMPILER_VAR_1321 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1320, 2);t.ogCont = ____BAH_COMPILER_VAR_1321;

#line 496 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1322 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1322);
    memory->data[____BAH_COMPILER_VAR_1322] = tmpT;
};

#line 498 "/home/alois/Documents/bah-bah/src/values.bah"
deleteRange(l,tokPos+1,i);

#line 499 "/home/alois/Documents/bah-bah/src/values.bah"
memory = prePross(memory,(lineType)-1,elems);

#line 502 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((len(memory)==0), 0)) {

#line 503 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&pt,"Cannot access empty index of array {TOKEN}.");
}

#line 507 "/home/alois/Documents/bah-bah/src/values.bah"
char split = false;

#line 508 "/home/alois/Documents/bah-bah/src/values.bah"
char * from = "";

#line 509 "/home/alois/Documents/bah-bah/src/values.bah"
char * to = "";

#line 510 "/home/alois/Documents/bah-bah/src/values.bah"
if ((len(memory)>1)) {

#line 511 "/home/alois/Documents/bah-bah/src/values.bah"
split = true;

#line 512 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok first = memory->data[0];

#line 513 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok second;

#line 514 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok third;

#line 516 "/home/alois/Documents/bah-bah/src/values.bah"
if ((len(memory)==3)) {

#line 517 "/home/alois/Documents/bah-bah/src/values.bah"
second = memory->data[1];

#line 518 "/home/alois/Documents/bah-bah/src/values.bah"
third = memory->data[2];

#line 519 "/home/alois/Documents/bah-bah/src/values.bah"
char * firstT = getTypeFromToken(&first,true,elems);

#line 520 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((compTypes(firstT,"int")==false), 0)) {

#line 521 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&first,"Cannot use {TOKEN} as int.");
}

#line 523 "/home/alois/Documents/bah-bah/src/values.bah"
char * thirdT = getTypeFromToken(&third,true,elems);

#line 524 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((compTypes(thirdT,"int")==false), 0)) {

#line 525 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&third,"Cannot use {TOKEN} as int.");
}

#line 527 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((strcmp(second.cont, ":") != 0), 0)) {

#line 528 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&second,"Expected ':' not {TOKEN}.");
}

#line 530 "/home/alois/Documents/bah-bah/src/values.bah"
from = first.cont;

#line 531 "/home/alois/Documents/bah-bah/src/values.bah"
to = third.cont;
}

#line 532 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((len(memory)==2)) {

#line 533 "/home/alois/Documents/bah-bah/src/values.bah"
second = memory->data[1];

#line 535 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(first.cont, ":") == 0)) {

#line 536 "/home/alois/Documents/bah-bah/src/values.bah"
from = "0";

#line 537 "/home/alois/Documents/bah-bah/src/values.bah"
char * secondT = getTypeFromToken(&second,true,elems);

#line 538 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((compTypes(secondT,"int")==false), 0)) {

#line 539 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&second,"Cannot use {TOKEN} as int.");
}

#line 541 "/home/alois/Documents/bah-bah/src/values.bah"
to = second.cont;
}

#line 542 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((strcmp(second.cont, ":") == 0)) {

#line 543 "/home/alois/Documents/bah-bah/src/values.bah"
char * firstT = getTypeFromToken(&first,true,elems);

#line 544 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((compTypes(firstT,"int")==false), 0)) {

#line 545 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&first,"Cannot use {TOKEN} as int.");
}

#line 547 "/home/alois/Documents/bah-bah/src/values.bah"
from = first.cont;
}

#line 548 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 549 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&second,"Expected ':' not {TOKEN}");
}
}

#line 551 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 552 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&memory->data[3],"Cannot substiture with more than 2 values, expected ']' not {TOKEN}.");
}
}

#line 556 "/home/alois/Documents/bah-bah/src/values.bah"
if (string__hasPrefix(&ptt,"[]")) {

#line 557 "/home/alois/Documents/bah-bah/src/values.bah"
if ((split==false)) {

#line 558 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok index = memory->data[0];

#line 559 "/home/alois/Documents/bah-bah/src/values.bah"
char * ____BAH_COMPILER_VAR_1323 =getTypeFromToken(&index,true,elems);if (__builtin_expect((compTypes(____BAH_COMPILER_VAR_1323,"int")==false), 0)) {

#line 560 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&index,"Cannot use {TOKEN} as array index (int).");
}

#line 562 "/home/alois/Documents/bah-bah/src/values.bah"
string__trimLeft(&ptt,2);

#line 563 "/home/alois/Documents/bah-bah/src/values.bah"
t.bahType = string__str(&ptt);

#line 564 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1324 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1324[3] = "]";____BAH_COMPILER_VAR_1324[2] = index.cont;____BAH_COMPILER_VAR_1324[1] = "->data[";____BAH_COMPILER_VAR_1324[0] = pt.cont;char * ____BAH_COMPILER_VAR_1325 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1324, 4);t.cont = ____BAH_COMPILER_VAR_1325;

#line 566 "/home/alois/Documents/bah-bah/src/values.bah"
if ((tokPos+1<len(l))&&(strcmp(l->data[tokPos+1].cont, ".") == 0)) {

#line 567 "/home/alois/Documents/bah-bah/src/values.bah"
struct variable* ____BAH_COMPILER_VAR_1326 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1326->name = "";
____BAH_COMPILER_VAR_1326->type = "";
____BAH_COMPILER_VAR_1326->constVal = "";
____BAH_COMPILER_VAR_1326->from = "";
____BAH_COMPILER_VAR_1326->name = t.cont;
____BAH_COMPILER_VAR_1326->type = t.bahType;
struct variable* tmpV = ____BAH_COMPILER_VAR_1326;

#line 571 "/home/alois/Documents/bah-bah/src/values.bah"
t.bahRef = tmpV;
}
}

#line 574 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 575 "/home/alois/Documents/bah-bah/src/values.bah"
t.bahType = string__str(&ptt);

#line 576 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(to, "") == 0)) {

#line 577 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1327 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1327[1] = "->length";____BAH_COMPILER_VAR_1327[0] = pt.cont;char * ____BAH_COMPILER_VAR_1328 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1327, 2);to = ____BAH_COMPILER_VAR_1328;
}

#line 579 "/home/alois/Documents/bah-bah/src/values.bah"
t.isFunc = true;

#line 580 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1329 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_1329[6] = ")";____BAH_COMPILER_VAR_1329[5] = to;____BAH_COMPILER_VAR_1329[4] = ", ";____BAH_COMPILER_VAR_1329[3] = from;____BAH_COMPILER_VAR_1329[2] = ", ";____BAH_COMPILER_VAR_1329[1] = pt.cont;____BAH_COMPILER_VAR_1329[0] = "arraySubstitute(";char * ____BAH_COMPILER_VAR_1330 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1329, 7);t.cont = ____BAH_COMPILER_VAR_1330;
}
}

#line 583 "/home/alois/Documents/bah-bah/src/values.bah"
else if (string__hasPrefix(&ptt,"buffer:")) {

#line 584 "/home/alois/Documents/bah-bah/src/values.bah"
if ((split==false)) {

#line 585 "/home/alois/Documents/bah-bah/src/values.bah"
t.bahType = "char";

#line 586 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok index = memory->data[0];

#line 587 "/home/alois/Documents/bah-bah/src/values.bah"
char * ____BAH_COMPILER_VAR_1331 =getTypeFromToken(&index,true,elems);if (__builtin_expect((compTypes(____BAH_COMPILER_VAR_1331,"int")==false), 0)) {

#line 588 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&index,"Cannot use {TOKEN} as buffer index (int).");
}

#line 590 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1332 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1332[3] = "]";____BAH_COMPILER_VAR_1332[2] = index.cont;____BAH_COMPILER_VAR_1332[1] = "[";____BAH_COMPILER_VAR_1332[0] = pt.cont;char * ____BAH_COMPILER_VAR_1333 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1332, 4);t.cont = ____BAH_COMPILER_VAR_1333;
}

#line 591 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 592 "/home/alois/Documents/bah-bah/src/values.bah"
t.bahType = "cpstring";

#line 593 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(to, "") == 0)) {

#line 594 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1334 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1334[2] = ")";____BAH_COMPILER_VAR_1334[1] = pt.cont;____BAH_COMPILER_VAR_1334[0] = "strlen(";char * ____BAH_COMPILER_VAR_1335 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1334, 3);to = ____BAH_COMPILER_VAR_1335;
}

#line 596 "/home/alois/Documents/bah-bah/src/values.bah"
t.isFunc = true;

#line 597 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1336 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_1336[6] = ")";____BAH_COMPILER_VAR_1336[5] = to;____BAH_COMPILER_VAR_1336[4] = ", ";____BAH_COMPILER_VAR_1336[3] = from;____BAH_COMPILER_VAR_1336[2] = ", ";____BAH_COMPILER_VAR_1336[1] = pt.cont;____BAH_COMPILER_VAR_1336[0] = "cpstringSubsitute(";char * ____BAH_COMPILER_VAR_1337 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1336, 7);t.cont = ____BAH_COMPILER_VAR_1337;
}
}

#line 599 "/home/alois/Documents/bah-bah/src/values.bah"
else if (string__hasPrefix(&ptt,"map:")) {

#line 600 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((split==true), 0)) {

#line 601 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&pt,"Cannot do substitution on a map {TOKEN}.");
}

#line 603 "/home/alois/Documents/bah-bah/src/values.bah"
string__trimLeft(&ptt,4);

#line 604 "/home/alois/Documents/bah-bah/src/values.bah"
char * ____BAH_COMPILER_VAR_1338 =string__str(&ptt);struct string elemType = getCType(____BAH_COMPILER_VAR_1338,elems);

#line 605 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok index = memory->data[0];

#line 606 "/home/alois/Documents/bah-bah/src/values.bah"
char * ____BAH_COMPILER_VAR_1339 =getTypeFromToken(&index,true,elems);if (__builtin_expect((compTypes(____BAH_COMPILER_VAR_1339,"cpstring")==false), 0)) {

#line 607 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&index,"Cannot use {TOKEN} as map index (cpstring).");
}

#line 609 "/home/alois/Documents/bah-bah/src/values.bah"
if ((tokPos==0)&&(ltp==LINE_TYPE_VAR)) {

#line 610 "/home/alois/Documents/bah-bah/src/values.bah"
struct variable* ____BAH_COMPILER_VAR_1340 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1340->name = "";
____BAH_COMPILER_VAR_1340->type = "";
____BAH_COMPILER_VAR_1340->constVal = "";
____BAH_COMPILER_VAR_1340->from = "";
____BAH_COMPILER_VAR_1340->name = genCompilerVar();
____BAH_COMPILER_VAR_1340->type = string__str(&ptt);
struct variable* tmpV = ____BAH_COMPILER_VAR_1340;

#line 614 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1341 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_1341);
    elems->vars->data[____BAH_COMPILER_VAR_1341] = tmpV;

#line 615 "/home/alois/Documents/bah-bah/src/values.bah"
if (isGlobal()) {

#line 616 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1342 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1342[3] = ";\n";____BAH_COMPILER_VAR_1342[2] = tmpV->name;____BAH_COMPILER_VAR_1342[1] = " ";____BAH_COMPILER_VAR_1342[0] = string__str(&elemType);char * ____BAH_COMPILER_VAR_1343 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1342, 4);INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_1343));
}

#line 617 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 618 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1344 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1344[3] = ";\n";____BAH_COMPILER_VAR_1344[2] = tmpV->name;____BAH_COMPILER_VAR_1344[1] = " ";____BAH_COMPILER_VAR_1344[0] = string__str(&elemType);char * ____BAH_COMPILER_VAR_1345 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1344, 4);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1345));
}

#line 620 "/home/alois/Documents/bah-bah/src/values.bah"
char * ____BAH_COMPILER_VAR_1346 =string__str(&ptt);if (isRCPpointerType(____BAH_COMPILER_VAR_1346)) {

#line 621 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1347 = alloca(8 * sizeof(char*));____BAH_COMPILER_VAR_1347[7] = ");\n";____BAH_COMPILER_VAR_1347[6] = tmpV->name;____BAH_COMPILER_VAR_1347[5] = ", ";____BAH_COMPILER_VAR_1347[4] = index.cont;____BAH_COMPILER_VAR_1347[3] = ", ";____BAH_COMPILER_VAR_1347[2] = pt.cont;____BAH_COMPILER_VAR_1347[1] = "->set(";____BAH_COMPILER_VAR_1347[0] = pt.cont;char * ____BAH_COMPILER_VAR_1348 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1347, 8);NEXT_LINE = ____BAH_COMPILER_VAR_1348;
}

#line 622 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 623 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1349 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_1349[8] = "));\n";____BAH_COMPILER_VAR_1349[7] = string__str(&elemType);____BAH_COMPILER_VAR_1349[6] = ", sizeof(";____BAH_COMPILER_VAR_1349[5] = tmpV->name;____BAH_COMPILER_VAR_1349[4] = ", &";____BAH_COMPILER_VAR_1349[3] = index.cont;____BAH_COMPILER_VAR_1349[2] = ", ";____BAH_COMPILER_VAR_1349[1] = pt.cont;____BAH_COMPILER_VAR_1349[0] = "mapWrapper__setAny(";char * ____BAH_COMPILER_VAR_1350 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1349, 9);NEXT_LINE = ____BAH_COMPILER_VAR_1350;
}

#line 625 "/home/alois/Documents/bah-bah/src/values.bah"
t.cont = tmpV->name;

#line 626 "/home/alois/Documents/bah-bah/src/values.bah"
t.bahType = string__str(&ptt);
}

#line 627 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 628 "/home/alois/Documents/bah-bah/src/values.bah"
t.isFunc = true;

#line 629 "/home/alois/Documents/bah-bah/src/values.bah"
struct rope* res= null;

#line 630 "/home/alois/Documents/bah-bah/src/values.bah"
char * tmpV = genCompilerVar();

#line 631 "/home/alois/Documents/bah-bah/src/values.bah"
char * ____BAH_COMPILER_VAR_1351 =string__str(&ptt);if (isRCPpointerType(____BAH_COMPILER_VAR_1351)) {

#line 632 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1352 = alloca(10 * sizeof(char*));____BAH_COMPILER_VAR_1352[9] = ");\n";____BAH_COMPILER_VAR_1352[8] = index.cont;____BAH_COMPILER_VAR_1352[7] = ", ";____BAH_COMPILER_VAR_1352[6] = t.cont;____BAH_COMPILER_VAR_1352[5] = "->get(";____BAH_COMPILER_VAR_1352[4] = t.cont;____BAH_COMPILER_VAR_1352[3] = "=";____BAH_COMPILER_VAR_1352[2] = tmpV;____BAH_COMPILER_VAR_1352[1] = " ";____BAH_COMPILER_VAR_1352[0] = string__str(&elemType);char * ____BAH_COMPILER_VAR_1353 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1352, 10);res = rope(____BAH_COMPILER_VAR_1353);

#line 633 "/home/alois/Documents/bah-bah/src/values.bah"
t.cont = tmpV;
}

#line 634 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 635 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1354 = alloca(10 * sizeof(char*));____BAH_COMPILER_VAR_1354[9] = ");\n";____BAH_COMPILER_VAR_1354[8] = index.cont;____BAH_COMPILER_VAR_1354[7] = ", ";____BAH_COMPILER_VAR_1354[6] = pt.cont;____BAH_COMPILER_VAR_1354[5] = "->get(";____BAH_COMPILER_VAR_1354[4] = pt.cont;____BAH_COMPILER_VAR_1354[3] = "=";____BAH_COMPILER_VAR_1354[2] = tmpV;____BAH_COMPILER_VAR_1354[1] = "* ";____BAH_COMPILER_VAR_1354[0] = string__str(&elemType);char * ____BAH_COMPILER_VAR_1355 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1354, 10);res = rope(____BAH_COMPILER_VAR_1355);

#line 636 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1356 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1356[4] = ")";____BAH_COMPILER_VAR_1356[3] = tmpV;____BAH_COMPILER_VAR_1356[2] = ")(*";____BAH_COMPILER_VAR_1356[1] = string__str(&elemType);____BAH_COMPILER_VAR_1356[0] = "(";char * ____BAH_COMPILER_VAR_1357 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1356, 5);t.cont = ____BAH_COMPILER_VAR_1357;
}

#line 638 "/home/alois/Documents/bah-bah/src/values.bah"
if (RCPavailable()) {

#line 639 "/home/alois/Documents/bah-bah/src/values.bah"
struct variable* ____BAH_COMPILER_VAR_1358 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1358->name = "";
____BAH_COMPILER_VAR_1358->type = "";
____BAH_COMPILER_VAR_1358->constVal = "";
____BAH_COMPILER_VAR_1358->from = "";
____BAH_COMPILER_VAR_1358->name = tmpV;
____BAH_COMPILER_VAR_1358->type = string__str(&ptt);

    unsigned int ____BAH_COMPILER_VAR_1359 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_1359);
    elems->vars->data[____BAH_COMPILER_VAR_1359] = ____BAH_COMPILER_VAR_1358;
}

#line 644 "/home/alois/Documents/bah-bah/src/values.bah"
if (isGlobal()) {

#line 645 "/home/alois/Documents/bah-bah/src/values.bah"
INIT = rope__add(INIT, res);
}

#line 646 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 647 "/home/alois/Documents/bah-bah/src/values.bah"
OUTPUT = rope__add(OUTPUT, res);
}

#line 649 "/home/alois/Documents/bah-bah/src/values.bah"
t.bahType = string__str(&ptt);
}
}

#line 652 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((strcmp(string__str(&ptt), "cpstring") == 0)) {

#line 653 "/home/alois/Documents/bah-bah/src/values.bah"
t.isFunc = true;

#line 654 "/home/alois/Documents/bah-bah/src/values.bah"
t.type = TOKEN_TYPE_FUNC;

#line 655 "/home/alois/Documents/bah-bah/src/values.bah"
if ((split==false)) {

#line 656 "/home/alois/Documents/bah-bah/src/values.bah"
t.bahType = "char";

#line 657 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok index = memory->data[0];

#line 658 "/home/alois/Documents/bah-bah/src/values.bah"
char * ____BAH_COMPILER_VAR_1360 =getTypeFromToken(&index,true,elems);if (__builtin_expect((compTypes(____BAH_COMPILER_VAR_1360,"int")==false), 0)) {

#line 659 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&index,"Cannot use {TOKEN} as cpstring index (int).");
}

#line 661 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1361 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1361[3] = "]";____BAH_COMPILER_VAR_1361[2] = index.cont;____BAH_COMPILER_VAR_1361[1] = "[";____BAH_COMPILER_VAR_1361[0] = pt.cont;char * ____BAH_COMPILER_VAR_1362 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1361, 4);t.cont = ____BAH_COMPILER_VAR_1362;
}

#line 662 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 663 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(to, "") == 0)) {

#line 664 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1363 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1363[2] = ")";____BAH_COMPILER_VAR_1363[1] = pt.cont;____BAH_COMPILER_VAR_1363[0] = "strlen(";char * ____BAH_COMPILER_VAR_1364 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1363, 3);to = ____BAH_COMPILER_VAR_1364;
}

#line 666 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1365 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_1365[6] = ")";____BAH_COMPILER_VAR_1365[5] = to;____BAH_COMPILER_VAR_1365[4] = ", ";____BAH_COMPILER_VAR_1365[3] = from;____BAH_COMPILER_VAR_1365[2] = ", ";____BAH_COMPILER_VAR_1365[1] = pt.cont;____BAH_COMPILER_VAR_1365[0] = "cpstringSubsitute(";char * ____BAH_COMPILER_VAR_1366 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1365, 7);t.cont = ____BAH_COMPILER_VAR_1366;
}
}

#line 669 "/home/alois/Documents/bah-bah/src/values.bah"
else if (string__hasPrefix(&ptt,"tuple:")) {

#line 670 "/home/alois/Documents/bah-bah/src/values.bah"
t.isOper = true;

#line 671 "/home/alois/Documents/bah-bah/src/values.bah"
struct variable* v = searchVar(pt.cont,elems);

#line 672 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((v==null), 0)) {

#line 673 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&pt,"Unkown var {TOKEN}.");
}

#line 675 "/home/alois/Documents/bah-bah/src/values.bah"
array(struct string)* parts = splitString(ptt,":");

#line 676 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok index = memory->data[0];

#line 677 "/home/alois/Documents/bah-bah/src/values.bah"
if ((index.type==TOKEN_TYPE_INT)) {

#line 678 "/home/alois/Documents/bah-bah/src/values.bah"
long int ind = strToInt(index.cont);

#line 679 "/home/alois/Documents/bah-bah/src/values.bah"
char * ____BAH_COMPILER_VAR_1367 =string__str(&parts->data[1]);if (__builtin_expect((ind>=strToInt(____BAH_COMPILER_VAR_1367)), 0)) {

#line 680 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1368 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1368[4] = ".";____BAH_COMPILER_VAR_1368[3] = string__str(&parts->data[1]);____BAH_COMPILER_VAR_1368[2] = " of length ";____BAH_COMPILER_VAR_1368[1] = pt.cont;____BAH_COMPILER_VAR_1368[0] = "Cannot access index {TOKEN} of tupple ";char * ____BAH_COMPILER_VAR_1369 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1368, 5);throwErr(&index,____BAH_COMPILER_VAR_1369);
}
}

#line 682 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 683 "/home/alois/Documents/bah-bah/src/values.bah"
char * ____BAH_COMPILER_VAR_1370 =getTypeFromToken(&index,true,elems);if (__builtin_expect((compTypes(____BAH_COMPILER_VAR_1370,"int")==false), 0)) {

#line 684 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&index,"Cannot use {TOKEN} as tuple index (int).");
}
}

#line 687 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1371 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1371[3] = "]";____BAH_COMPILER_VAR_1371[2] = index.cont;____BAH_COMPILER_VAR_1371[1] = "[";____BAH_COMPILER_VAR_1371[0] = pt.cont;char * ____BAH_COMPILER_VAR_1372 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1371, 4);t.cont = ____BAH_COMPILER_VAR_1372;

#line 688 "/home/alois/Documents/bah-bah/src/values.bah"
t.bahType = string__str(&parts->data[2]);
}

#line 689 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 690 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1373 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1373[2] = ") as array.";____BAH_COMPILER_VAR_1373[1] = string__str(&ptt);____BAH_COMPILER_VAR_1373[0] = "Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_1374 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1373, 3);throwErr(&pt,____BAH_COMPILER_VAR_1374);
}

#line 693 "/home/alois/Documents/bah-bah/src/values.bah"
t.isValue = true;

#line 694 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1375 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1375);
    l->data[____BAH_COMPILER_VAR_1375] = t;

#line 696 "/home/alois/Documents/bah-bah/src/values.bah"
return tokPos;
};

#line 699 "/home/alois/Documents/bah-bah/src/values.bah"
long int valueBool(__BAH_ARR_TYPE_Tok l,long int i,lineType ltp,struct Elems* elems){

#line 701 "/home/alois/Documents/bah-bah/src/values.bah"
long int tokPos = i-2;

#line 704 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok pt = l->data[tokPos];

#line 705 "/home/alois/Documents/bah-bah/src/values.bah"
char * ptt = getTypeFromToken(&pt,true,elems);

#line 707 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok t = l->data[tokPos+1];

#line 709 "/home/alois/Documents/bah-bah/src/values.bah"
deleteRange(l,tokPos,tokPos+1);

#line 712 "/home/alois/Documents/bah-bah/src/values.bah"
if ((isFixMeEnabled==false)&&(ltp==LINE_TYPE_FOR)&&(strcmp(ptt, "int") == 0)||(strcmp(ptt, "float") == 0)) {

#line 713 "/home/alois/Documents/bah-bah/src/values.bah"
struct variable* v = getRealVar(pt.cont,elems);

#line 714 "/home/alois/Documents/bah-bah/src/values.bah"
if ((v!=null)) {

#line 715 "/home/alois/Documents/bah-bah/src/values.bah"
v->iterScope = elems;

#line 716 "/home/alois/Documents/bah-bah/src/values.bah"
if ((v->canBeReg==true)&&(v->isReg==false)&&(v->declRope!=null)) {

#line 717 "/home/alois/Documents/bah-bah/src/values.bah"
char * odecl = rope__toStr(v->declRope);

#line 718 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strHasPrefix(odecl,"register ")==false)) {

#line 719 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1376 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1376[1] = odecl;____BAH_COMPILER_VAR_1376[0] = "register ";char * ____BAH_COMPILER_VAR_1377 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1376, 2);OUTPUT->totalLen = OUTPUT->totalLen+ropeSet(v->declRope,____BAH_COMPILER_VAR_1377);
}

#line 721 "/home/alois/Documents/bah-bah/src/values.bah"
v->isReg = true;
}
}
}

#line 727 "/home/alois/Documents/bah-bah/src/values.bah"
if ((isUnsafe==false)) {

#line 728 "/home/alois/Documents/bah-bah/src/values.bah"
if ((tokPos>0)) {

#line 729 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(l->data[tokPos-1].cont, "&&") != 0)) {

#line 730 "/home/alois/Documents/bah-bah/src/values.bah"
clear(currChecks);
}
}

#line 732 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 733 "/home/alois/Documents/bah-bah/src/values.bah"
clear(currChecks);
}
}

#line 738 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok nt = l->data[tokPos];

#line 739 "/home/alois/Documents/bah-bah/src/values.bah"
char * ntt = getTypeFromToken(&nt,true,elems);

#line 740 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(t.cont, "in") == 0)) {

#line 741 "/home/alois/Documents/bah-bah/src/values.bah"
struct string arrT = string(ntt);

#line 742 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((string__hasPrefix(&arrT,"[]")==0), 0)) {

#line 743 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1378 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1378[2] = ") as array.";____BAH_COMPILER_VAR_1378[1] = ntt;____BAH_COMPILER_VAR_1378[0] = "Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_1379 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1378, 3);throwErr(&nt,____BAH_COMPILER_VAR_1379);
}

#line 745 "/home/alois/Documents/bah-bah/src/values.bah"
string__trimLeft(&arrT,2);

#line 746 "/home/alois/Documents/bah-bah/src/values.bah"
char * ____BAH_COMPILER_VAR_1380 =string__str(&arrT);if (__builtin_expect((compTypes(ptt,____BAH_COMPILER_VAR_1380)==false), 0)) {

#line 747 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1381 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1381[4] = ".";____BAH_COMPILER_VAR_1381[3] = ntt;____BAH_COMPILER_VAR_1381[2] = ") in ";____BAH_COMPILER_VAR_1381[1] = ptt;____BAH_COMPILER_VAR_1381[0] = "Cannot search for {TOKEN} (";char * ____BAH_COMPILER_VAR_1382 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1381, 5);throwErr(&pt,____BAH_COMPILER_VAR_1382);
}

#line 749 "/home/alois/Documents/bah-bah/src/values.bah"
char * comp = "";

#line 750 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(ptt, "cpstring") == 0)) {

#line 751 "/home/alois/Documents/bah-bah/src/values.bah"
comp = "arr->data[i] != 0 && strcmp(arr->data[i], el) == 0";
}

#line 752 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 753 "/home/alois/Documents/bah-bah/src/values.bah"
comp = "arr->data[i] == el";
}

#line 755 "/home/alois/Documents/bah-bah/src/values.bah"
char * name = genCompilerVar();

#line 756 "/home/alois/Documents/bah-bah/src/values.bah"

                struct string ____BAH_COMPILER_VAR_1383 = getCType(ntt,elems);
                
                struct string ____BAH_COMPILER_VAR_1384 = getCType(ptt,elems);
                char** ____BAH_COMPILER_VAR_1385 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_1385[8] = ") {\n                return 1;\n            };\n        }\n        return 0;\n        }\n";____BAH_COMPILER_VAR_1385[7] = comp;____BAH_COMPILER_VAR_1385[6] = " el) {\n        if (arr == 0) {\n            return 0;\n        };\n        for(int i=arr->length-1; i!=-1;i--) {\n            if (";____BAH_COMPILER_VAR_1385[5] = string__str(&____BAH_COMPILER_VAR_1384);____BAH_COMPILER_VAR_1385[4] = " arr, ";____BAH_COMPILER_VAR_1385[3] = string__str(&____BAH_COMPILER_VAR_1383);____BAH_COMPILER_VAR_1385[2] = "(";____BAH_COMPILER_VAR_1385[1] = name;____BAH_COMPILER_VAR_1385[0] = "char ";char * ____BAH_COMPILER_VAR_1386 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1385, 9);char * fnTest = ____BAH_COMPILER_VAR_1386;

#line 767 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1387 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1387[1] = fnTest;____BAH_COMPILER_VAR_1387[0] = rope__toStr(postDeclHandle);char * ____BAH_COMPILER_VAR_1388 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1387, 2);OUTPUT->totalLen = OUTPUT->totalLen+ropeSet(postDeclHandle,____BAH_COMPILER_VAR_1388);

#line 769 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1389 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_1389[5] = ")";____BAH_COMPILER_VAR_1389[4] = pt.cont;____BAH_COMPILER_VAR_1389[3] = ", ";____BAH_COMPILER_VAR_1389[2] = nt.cont;____BAH_COMPILER_VAR_1389[1] = "(";____BAH_COMPILER_VAR_1389[0] = name;char * ____BAH_COMPILER_VAR_1390 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1389, 6);char * fnCall = ____BAH_COMPILER_VAR_1390;

#line 771 "/home/alois/Documents/bah-bah/src/values.bah"
pt.isExpensive = true;

#line 772 "/home/alois/Documents/bah-bah/src/values.bah"
pt.cont = fnCall;
}

#line 773 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 774 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((compTypes(ptt,ntt)==false), 0)) {

#line 775 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1391 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1391[4] = ".";____BAH_COMPILER_VAR_1391[3] = ptt;____BAH_COMPILER_VAR_1391[2] = ") with type ";____BAH_COMPILER_VAR_1391[1] = ntt;____BAH_COMPILER_VAR_1391[0] = "Cannot compare {TOKEN} (";char * ____BAH_COMPILER_VAR_1392 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1391, 5);throwErr(&nt,____BAH_COMPILER_VAR_1392);
}

#line 777 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(ptt, "cpstring") == 0)) {

#line 778 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(t.cont, "==") == 0)) {

#line 779 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1393 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1393[4] = ") == 0)";____BAH_COMPILER_VAR_1393[3] = nt.cont;____BAH_COMPILER_VAR_1393[2] = ", ";____BAH_COMPILER_VAR_1393[1] = pt.cont;____BAH_COMPILER_VAR_1393[0] = "(strcmp(";char * ____BAH_COMPILER_VAR_1394 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1393, 5);pt.cont = ____BAH_COMPILER_VAR_1394;
}

#line 781 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((strcmp(t.cont, "!=") == 0)) {

#line 782 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1395 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1395[4] = ") != 0)";____BAH_COMPILER_VAR_1395[3] = nt.cont;____BAH_COMPILER_VAR_1395[2] = ", ";____BAH_COMPILER_VAR_1395[1] = pt.cont;____BAH_COMPILER_VAR_1395[0] = "(strcmp(";char * ____BAH_COMPILER_VAR_1396 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1395, 5);pt.cont = ____BAH_COMPILER_VAR_1396;
}

#line 783 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((strcmp(t.cont, ">") == 0)) {

#line 784 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1397 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1397[4] = "))";____BAH_COMPILER_VAR_1397[3] = nt.cont;____BAH_COMPILER_VAR_1397[2] = ") > srtlen(";____BAH_COMPILER_VAR_1397[1] = pt.cont;____BAH_COMPILER_VAR_1397[0] = "(strlen(";char * ____BAH_COMPILER_VAR_1398 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1397, 5);pt.cont = ____BAH_COMPILER_VAR_1398;
}

#line 785 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((strcmp(t.cont, "<") == 0)) {

#line 786 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1399 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1399[4] = "))";____BAH_COMPILER_VAR_1399[3] = nt.cont;____BAH_COMPILER_VAR_1399[2] = ") < srtlen(";____BAH_COMPILER_VAR_1399[1] = pt.cont;____BAH_COMPILER_VAR_1399[0] = "(strlen(";char * ____BAH_COMPILER_VAR_1400 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1399, 5);pt.cont = ____BAH_COMPILER_VAR_1400;
}

#line 787 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((strcmp(t.cont, ">=") == 0)) {

#line 788 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1401 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1401[4] = "))";____BAH_COMPILER_VAR_1401[3] = nt.cont;____BAH_COMPILER_VAR_1401[2] = ") >= srtlen(";____BAH_COMPILER_VAR_1401[1] = pt.cont;____BAH_COMPILER_VAR_1401[0] = "(strlen(";char * ____BAH_COMPILER_VAR_1402 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1401, 5);pt.cont = ____BAH_COMPILER_VAR_1402;
}

#line 789 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((strcmp(t.cont, "<=") == 0)) {

#line 790 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1403 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1403[4] = "))";____BAH_COMPILER_VAR_1403[3] = nt.cont;____BAH_COMPILER_VAR_1403[2] = ") <= srtlen(";____BAH_COMPILER_VAR_1403[1] = pt.cont;____BAH_COMPILER_VAR_1403[0] = "(strlen(";char * ____BAH_COMPILER_VAR_1404 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1403, 5);pt.cont = ____BAH_COMPILER_VAR_1404;
}

#line 792 "/home/alois/Documents/bah-bah/src/values.bah"
pt.isExpensive = true;
}

#line 793 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 794 "/home/alois/Documents/bah-bah/src/values.bah"
if ((isUnsafe==false)&&(pt.type==TOKEN_TYPE_VAR)&&(pt.isOper==false)&&isRCPpointerType(ptt)) {

#line 795 "/home/alois/Documents/bah-bah/src/values.bah"
struct variable* ptV = searchVar(pt.cont,elems);

#line 796 "/home/alois/Documents/bah-bah/src/values.bah"
if ((ptV!=null)) {

#line 797 "/home/alois/Documents/bah-bah/src/values.bah"
char ntIsNull = false;

#line 798 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(nt.cont, "null") == 0)) {

#line 799 "/home/alois/Documents/bah-bah/src/values.bah"
ntIsNull = true;
}

#line 800 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((nt.type==TOKEN_TYPE_VAR)&&(nt.isOper==false)) {

#line 801 "/home/alois/Documents/bah-bah/src/values.bah"
struct variable* nv = searchVar(nt.cont,elems);

#line 802 "/home/alois/Documents/bah-bah/src/values.bah"
if ((nv!=null)) {

#line 803 "/home/alois/Documents/bah-bah/src/values.bah"
ntIsNull = nv->canBeNull;
}
}

#line 805 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((nt.isFunc==true)) {

#line 806 "/home/alois/Documents/bah-bah/src/values.bah"
struct func* fn = searchFuncByToken(&nt,elems);

#line 807 "/home/alois/Documents/bah-bah/src/values.bah"
if ((fn!=null)&&(fn->returns!=null)) {

#line 808 "/home/alois/Documents/bah-bah/src/values.bah"
ntIsNull = (fn->returns->type[strlen(fn->returns->type)-1]==33);
}
}

#line 811 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(t.cont, "==") == 0)) {

#line 812 "/home/alois/Documents/bah-bah/src/values.bah"
struct varCheck ____BAH_COMPILER_VAR_1405 = {};
____BAH_COMPILER_VAR_1405.v = ptV;
____BAH_COMPILER_VAR_1405.checkNull = ntIsNull;

    unsigned int ____BAH_COMPILER_VAR_1406 = len(currChecks);
    __Bah_realocate_arr(currChecks, ____BAH_COMPILER_VAR_1406);
    currChecks->data[____BAH_COMPILER_VAR_1406] = ____BAH_COMPILER_VAR_1405;
}

#line 816 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((strcmp(t.cont, "!=") == 0)) {

#line 817 "/home/alois/Documents/bah-bah/src/values.bah"
struct varCheck ____BAH_COMPILER_VAR_1407 = {};
____BAH_COMPILER_VAR_1407.v = ptV;
____BAH_COMPILER_VAR_1407.checkNull = (ntIsNull==false);

    unsigned int ____BAH_COMPILER_VAR_1408 = len(currChecks);
    __Bah_realocate_arr(currChecks, ____BAH_COMPILER_VAR_1408);
    currChecks->data[____BAH_COMPILER_VAR_1408] = ____BAH_COMPILER_VAR_1407;
}
}
}

#line 824 "/home/alois/Documents/bah-bah/src/values.bah"
if (isExprExpensive(&pt)||isExprExpensive(&nt)) {

#line 825 "/home/alois/Documents/bah-bah/src/values.bah"
pt.isExpensive = true;
}

#line 826 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 827 "/home/alois/Documents/bah-bah/src/values.bah"
pt.isExpensive = false;
}

#line 829 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1409 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1409[4] = ")";____BAH_COMPILER_VAR_1409[3] = nt.cont;____BAH_COMPILER_VAR_1409[2] = t.cont;____BAH_COMPILER_VAR_1409[1] = pt.cont;____BAH_COMPILER_VAR_1409[0] = "(";char * ____BAH_COMPILER_VAR_1410 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1409, 5);pt.cont = ____BAH_COMPILER_VAR_1410;
}
}

#line 834 "/home/alois/Documents/bah-bah/src/values.bah"
pt.isOper = true;

#line 835 "/home/alois/Documents/bah-bah/src/values.bah"
pt.bahType = "bool";

#line 836 "/home/alois/Documents/bah-bah/src/values.bah"
pt.isValue = true;

#line 837 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1411 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1411);
    l->data[____BAH_COMPILER_VAR_1411] = pt;

#line 838 "/home/alois/Documents/bah-bah/src/values.bah"
return tokPos;
};

#line 842 "/home/alois/Documents/bah-bah/src/values.bah"
char ____BAH_COMPILER_VAR_1420(array(char *)* arr, char * el) {
        if (arr == 0) {
            return 0;
        };
        for(int i=arr->length-1; i!=-1;i--) {
            if (arr->data[i] != 0 && strcmp(arr->data[i], el) == 0) {
                return 1;
            };
        }
        return 0;
        }
long int valueOper(__BAH_ARR_TYPE_Tok l,long int i,struct Elems* elems){

#line 843 "/home/alois/Documents/bah-bah/src/values.bah"
long int tokPos = i-2;

#line 845 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok pt = l->data[tokPos];

#line 846 "/home/alois/Documents/bah-bah/src/values.bah"
char * ptt = getTypeFromToken(&pt,true,elems);

#line 849 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok t = l->data[tokPos+1];

#line 850 "/home/alois/Documents/bah-bah/src/values.bah"
deleteRange(l,tokPos,tokPos+1);

#line 853 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok nt = l->data[tokPos];

#line 856 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(nt.cont, t.cont) == 0)) {

#line 857 "/home/alois/Documents/bah-bah/src/values.bah"
pt.isOper = true;

#line 858 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1412 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1412[2] = pt.cont;____BAH_COMPILER_VAR_1412[1] = t.cont;____BAH_COMPILER_VAR_1412[0] = t.cont;char * ____BAH_COMPILER_VAR_1413 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1412, 3);pt.cont = ____BAH_COMPILER_VAR_1413;

#line 859 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1414 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1414);
    l->data[____BAH_COMPILER_VAR_1414] = pt;

#line 860 "/home/alois/Documents/bah-bah/src/values.bah"
return tokPos;
}

#line 864 "/home/alois/Documents/bah-bah/src/values.bah"
char * ntt = getTypeFromToken(&nt,true,elems);

#line 865 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((compTypes(ptt,ntt)==false), 0)) {

#line 866 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1415 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1415[4] = ".";____BAH_COMPILER_VAR_1415[3] = ptt;____BAH_COMPILER_VAR_1415[2] = ") as ";____BAH_COMPILER_VAR_1415[1] = ntt;____BAH_COMPILER_VAR_1415[0] = "Cannot compare {TOKEN} (";char * ____BAH_COMPILER_VAR_1416 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1415, 5);throwErr(&nt,____BAH_COMPILER_VAR_1416);
}

#line 870 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(ptt, "cpstring") == 0)) {

#line 873 "/home/alois/Documents/bah-bah/src/values.bah"
array(char *)* strs = memoryAlloc(sizeof(array(char *)));

strs->length = 2;
strs->elemSize = sizeof(char *);
strs->data = memoryAlloc(sizeof(char *) * 50);
                    strs->realLength = 50;
strs->data[0] = nt.cont;
strs->data[1] = pt.cont;

#line 875 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((strcmp(t.cont, "+") != 0), 0)) {

#line 876 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&t,"Can only do concatenation on cpstring, not {TOKEN}.");
}

#line 880 "/home/alois/Documents/bah-bah/src/values.bah"
if ((tokPos-1>=0)) {

#line 881 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok nat = l->data[tokPos-1];

#line 882 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(nat.cont, "+") == 0)) {

#line 884 "/home/alois/Documents/bah-bah/src/values.bah"
long int rangeEnds = tokPos-1;

#line 885 "/home/alois/Documents/bah-bah/src/values.bah"
i = tokPos-2;

#line 886 "/home/alois/Documents/bah-bah/src/values.bah"
long int nb = 2;

#line 887 "/home/alois/Documents/bah-bah/src/values.bah"
for (; (i>=0); 
#line 887 "/home/alois/Documents/bah-bah/src/values.bah"
--i) {

#line 888 "/home/alois/Documents/bah-bah/src/values.bah"
tokPos = i;

#line 889 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok currStrTk = l->data[i];

#line 891 "/home/alois/Documents/bah-bah/src/values.bah"
char * tt = getTypeFromToken(&currStrTk,true,elems);

#line 892 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((compTypes(tt,"cpstring")==false), 0)) {

#line 893 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1417 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1417[2] = ").";____BAH_COMPILER_VAR_1417[1] = tt;____BAH_COMPILER_VAR_1417[0] = "Cannot concatenate cpstring with {TOKEN} (";char * ____BAH_COMPILER_VAR_1418 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1417, 3);throwErr(&currStrTk,____BAH_COMPILER_VAR_1418);
}

#line 896 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1419 = len(strs);
    __Bah_realocate_arr(strs, ____BAH_COMPILER_VAR_1419);
    strs->data[____BAH_COMPILER_VAR_1419] = currStrTk.cont;

#line 899 "/home/alois/Documents/bah-bah/src/values.bah"
if ((i-1>=0)) {

#line 900 "/home/alois/Documents/bah-bah/src/values.bah"
--i;

#line 901 "/home/alois/Documents/bah-bah/src/values.bah"
t = l->data[i];

#line 902 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(t.cont, "+") != 0)) {

#line 903 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect(____BAH_COMPILER_VAR_1420(signs, t.cont), 0)) {

#line 904 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&t,"Can only do concatenation on cpstring, not {TOKEN}.");
}

#line 905 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 906 "/home/alois/Documents/bah-bah/src/values.bah"
++i;

#line 907 "/home/alois/Documents/bah-bah/src/values.bah"
break;
}
}
}

#line 911 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 912 "/home/alois/Documents/bah-bah/src/values.bah"
i = 0;

#line 913 "/home/alois/Documents/bah-bah/src/values.bah"
break;
}
};

#line 916 "/home/alois/Documents/bah-bah/src/values.bah"
deleteRange(l,i,rangeEnds);
}

#line 917 "/home/alois/Documents/bah-bah/src/values.bah"
else if (__builtin_expect(inArrayStr(nat.cont,signs), 0)) {

#line 918 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&nat,"Can only do concatenation on cpstring, not {TOKEN}.");
}
}

#line 924 "/home/alois/Documents/bah-bah/src/values.bah"
pt.type = TOKEN_TYPE_VAR;

#line 925 "/home/alois/Documents/bah-bah/src/values.bah"
pt.isValue = true;

#line 926 "/home/alois/Documents/bah-bah/src/values.bah"
pt.cont = genConcat(strs,elems);

#line 927 "/home/alois/Documents/bah-bah/src/values.bah"
pt.isOper = false;
}

#line 928 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 930 "/home/alois/Documents/bah-bah/src/values.bah"
struct cStruct* s = searchStruct(ptt,elems);

#line 931 "/home/alois/Documents/bah-bah/src/values.bah"
if ((s!=null)) {

#line 932 "/home/alois/Documents/bah-bah/src/values.bah"
char * sep = ".";

#line 933 "/home/alois/Documents/bah-bah/src/values.bah"
char * amp = "&";

#line 935 "/home/alois/Documents/bah-bah/src/values.bah"
if (isRCPpointerType(ptt)) {

#line 936 "/home/alois/Documents/bah-bah/src/values.bah"
sep = "->";

#line 937 "/home/alois/Documents/bah-bah/src/values.bah"
amp = "";
}

#line 939 "/home/alois/Documents/bah-bah/src/values.bah"
char * mName = "";

#line 940 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(t.cont, "+") == 0)) {

#line 941 "/home/alois/Documents/bah-bah/src/values.bah"
mName = "add";
}

#line 942 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((strcmp(t.cont, "-") == 0)) {

#line 943 "/home/alois/Documents/bah-bah/src/values.bah"
mName = "sub";
}

#line 944 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((strcmp(t.cont, "*") == 0)) {

#line 945 "/home/alois/Documents/bah-bah/src/values.bah"
mName = "mult";
}

#line 946 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((strcmp(t.cont, "/") == 0)) {

#line 947 "/home/alois/Documents/bah-bah/src/values.bah"
mName = "div";
}

#line 948 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 949 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1421 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1421[2] = ").";____BAH_COMPILER_VAR_1421[1] = ptt;____BAH_COMPILER_VAR_1421[0] = "Undefined operation on struct {TOKEN} (";char * ____BAH_COMPILER_VAR_1422 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1421, 3);throwErr(&pt,____BAH_COMPILER_VAR_1422);
}

#line 951 "/home/alois/Documents/bah-bah/src/values.bah"
struct structMemb* methd = searchStructMemb(mName,s,elems);

#line 952 "/home/alois/Documents/bah-bah/src/values.bah"
if ((methd!=null)&&(methd->isFn==true)) {

#line 953 "/home/alois/Documents/bah-bah/src/values.bah"
if (RCPavailable()) {

#line 954 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1423 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_1423[8] = ")";____BAH_COMPILER_VAR_1423[7] = nt.cont;____BAH_COMPILER_VAR_1423[6] = ", ";____BAH_COMPILER_VAR_1423[5] = pt.cont;____BAH_COMPILER_VAR_1423[4] = amp;____BAH_COMPILER_VAR_1423[3] = "(";____BAH_COMPILER_VAR_1423[2] = mName;____BAH_COMPILER_VAR_1423[1] = "__";____BAH_COMPILER_VAR_1423[0] = s->name;char * ____BAH_COMPILER_VAR_1424 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1423, 9);pt.cont = registerRCPvar(ptt,____BAH_COMPILER_VAR_1424,elems);

#line 955 "/home/alois/Documents/bah-bah/src/values.bah"
pt.type = TOKEN_TYPE_VAR;

#line 955 "/home/alois/Documents/bah-bah/src/values.bah"
pt.isFunc = false;

#line 955 "/home/alois/Documents/bah-bah/src/values.bah"
pt.isOper = false;
}

#line 956 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 957 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1425 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_1425[8] = ")";____BAH_COMPILER_VAR_1425[7] = nt.cont;____BAH_COMPILER_VAR_1425[6] = ", ";____BAH_COMPILER_VAR_1425[5] = pt.cont;____BAH_COMPILER_VAR_1425[4] = amp;____BAH_COMPILER_VAR_1425[3] = "(";____BAH_COMPILER_VAR_1425[2] = mName;____BAH_COMPILER_VAR_1425[1] = "__";____BAH_COMPILER_VAR_1425[0] = s->name;char * ____BAH_COMPILER_VAR_1426 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1425, 9);pt.cont = ____BAH_COMPILER_VAR_1426;

#line 958 "/home/alois/Documents/bah-bah/src/values.bah"
pt.isFunc = true;
}
}
}

#line 961 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 962 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1427 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1427[1] = nt.cont;____BAH_COMPILER_VAR_1427[0] = t.cont;char * ____BAH_COMPILER_VAR_1428 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1427, 2);char** ____BAH_COMPILER_VAR_1429 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1429[1] = ____BAH_COMPILER_VAR_1428;____BAH_COMPILER_VAR_1429[0] = pt.cont;char * ____BAH_COMPILER_VAR_1430 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1429, 2);pt.cont = ____BAH_COMPILER_VAR_1430;
}

#line 964 "/home/alois/Documents/bah-bah/src/values.bah"
pt.isOper = true;
}

#line 967 "/home/alois/Documents/bah-bah/src/values.bah"
pt.isNotExpsvOper = false;

#line 968 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1431 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1431);
    l->data[____BAH_COMPILER_VAR_1431] = pt;

#line 969 "/home/alois/Documents/bah-bah/src/values.bah"
return tokPos;
};

#line 972 "/home/alois/Documents/bah-bah/src/values.bah"
long int valueSendChan(__BAH_ARR_TYPE_Tok l,long int i,struct Elems* elems){

#line 973 "/home/alois/Documents/bah-bah/src/values.bah"
long int posTok = i-2;

#line 975 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok nt = l->data[posTok];

#line 977 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok pt = l->data[posTok+2];

#line 978 "/home/alois/Documents/bah-bah/src/values.bah"
deleteRange(l,posTok,posTok+2);

#line 980 "/home/alois/Documents/bah-bah/src/values.bah"
char * ntt = getTypeFromToken(&nt,true,elems);

#line 982 "/home/alois/Documents/bah-bah/src/values.bah"
char * ____BAH_COMPILER_VAR_1432 =getTypeFromToken(&pt,true,elems);struct string ptt = string(____BAH_COMPILER_VAR_1432);

#line 983 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((string__hasPrefix(&ptt,"chan:")==0), 0)) {

#line 984 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1433 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1433[2] = ") as chan.";____BAH_COMPILER_VAR_1433[1] = string__str(&ptt);____BAH_COMPILER_VAR_1433[0] = "Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_1434 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1433, 3);throwErr(&pt,____BAH_COMPILER_VAR_1434);
}

#line 986 "/home/alois/Documents/bah-bah/src/values.bah"
string__trimLeft(&ptt,5);

#line 988 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect(isGlobal(), 0)) {

#line 989 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&pt,"Cannot send to channel {TOKEN} of a function.");
}

#line 992 "/home/alois/Documents/bah-bah/src/values.bah"
char * ____BAH_COMPILER_VAR_1435 =string__str(&ptt);if (__builtin_expect((compTypes(ntt,____BAH_COMPILER_VAR_1435)==false), 0)) {

#line 993 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1436 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1436[4] = ".";____BAH_COMPILER_VAR_1436[3] = string__str(&ptt);____BAH_COMPILER_VAR_1436[2] = ") through chan:";____BAH_COMPILER_VAR_1436[1] = ntt;____BAH_COMPILER_VAR_1436[0] = "Cannot send {TOKEN} (";char * ____BAH_COMPILER_VAR_1437 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1436, 5);throwErr(&nt,____BAH_COMPILER_VAR_1437);
}

#line 996 "/home/alois/Documents/bah-bah/src/values.bah"
char * ____BAH_COMPILER_VAR_1438 =string__str(&ptt);if (isRCPpointerType(____BAH_COMPILER_VAR_1438)) {

#line 997 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1439 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1439[4] = ");\n";____BAH_COMPILER_VAR_1439[3] = nt.cont;____BAH_COMPILER_VAR_1439[2] = ", ";____BAH_COMPILER_VAR_1439[1] = pt.cont;____BAH_COMPILER_VAR_1439[0] = "channel__send(";char * ____BAH_COMPILER_VAR_1440 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1439, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1440));
}

#line 998 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 999 "/home/alois/Documents/bah-bah/src/values.bah"
struct string ct = getCType(ntt,elems);

#line 1000 "/home/alois/Documents/bah-bah/src/values.bah"
char * tmpV = genCompilerVar();

#line 1001 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1441 = alloca(13 * sizeof(char*));____BAH_COMPILER_VAR_1441[12] = "));\n        ";____BAH_COMPILER_VAR_1441[11] = tmpV;____BAH_COMPILER_VAR_1441[10] = ", sizeof(";____BAH_COMPILER_VAR_1441[9] = tmpV;____BAH_COMPILER_VAR_1441[8] = ", &";____BAH_COMPILER_VAR_1441[7] = pt.cont;____BAH_COMPILER_VAR_1441[6] = ";\n        channel__sendAny(";____BAH_COMPILER_VAR_1441[5] = nt.cont;____BAH_COMPILER_VAR_1441[4] = " = ";____BAH_COMPILER_VAR_1441[3] = tmpV;____BAH_COMPILER_VAR_1441[2] = " ";____BAH_COMPILER_VAR_1441[1] = string__str(&ct);____BAH_COMPILER_VAR_1441[0] = "\n        ";char * ____BAH_COMPILER_VAR_1442 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1441, 13);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1442));
}

#line 1007 "/home/alois/Documents/bah-bah/src/values.bah"
return posTok;
};

#line 1010 "/home/alois/Documents/bah-bah/src/values.bah"
long int valueChan(__BAH_ARR_TYPE_Tok l,long int i,struct Elems* elems){

#line 1011 "/home/alois/Documents/bah-bah/src/values.bah"
long int posTok = i-1;

#line 1012 "/home/alois/Documents/bah-bah/src/values.bah"
delete(l,posTok);

#line 1015 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok nt = l->data[posTok];

#line 1017 "/home/alois/Documents/bah-bah/src/values.bah"
char * ____BAH_COMPILER_VAR_1443 =getTypeFromToken(&nt,true,elems);struct string ntt = string(____BAH_COMPILER_VAR_1443);

#line 1018 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((string__hasPrefix(&ntt,"chan:")==0), 0)) {

#line 1019 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1444 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1444[2] = ") as chan.";____BAH_COMPILER_VAR_1444[1] = string__str(&ntt);____BAH_COMPILER_VAR_1444[0] = "Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_1445 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1444, 3);throwErr(&nt,____BAH_COMPILER_VAR_1445);
}

#line 1022 "/home/alois/Documents/bah-bah/src/values.bah"
string__trimLeft(&ntt,5);

#line 1024 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect(isGlobal(), 0)) {

#line 1025 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&nt,"Cannot receive from chan {TOKEN} outside a function body.");
}

#line 1028 "/home/alois/Documents/bah-bah/src/values.bah"
char * ____BAH_COMPILER_VAR_1446 =string__str(&ntt);struct string ct = getCType(____BAH_COMPILER_VAR_1446,elems);

#line 1029 "/home/alois/Documents/bah-bah/src/values.bah"
char * ____BAH_COMPILER_VAR_1447 =string__str(&ntt);if (isRCPpointerType(____BAH_COMPILER_VAR_1447)) {

#line 1030 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1448 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1448[2] = ")";____BAH_COMPILER_VAR_1448[1] = nt.cont;____BAH_COMPILER_VAR_1448[0] = "channel__receive(";char * ____BAH_COMPILER_VAR_1449 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1448, 3);char * ____BAH_COMPILER_VAR_1450 =string__str(&ntt);char * tmpV = registerRCPvar(____BAH_COMPILER_VAR_1450,____BAH_COMPILER_VAR_1449,elems);

#line 1031 "/home/alois/Documents/bah-bah/src/values.bah"
nt.cont = tmpV;
}

#line 1032 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 1033 "/home/alois/Documents/bah-bah/src/values.bah"
if (RCPavailable()) {

#line 1034 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1451 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1451[1] = "*";____BAH_COMPILER_VAR_1451[0] = string__str(&ntt);char * ____BAH_COMPILER_VAR_1452 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1451, 2);char** ____BAH_COMPILER_VAR_1453 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1453[4] = ")";____BAH_COMPILER_VAR_1453[3] = nt.cont;____BAH_COMPILER_VAR_1453[2] = "*)channel__receive(";____BAH_COMPILER_VAR_1453[1] = string__str(&ct);____BAH_COMPILER_VAR_1453[0] = "(";char * ____BAH_COMPILER_VAR_1454 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1453, 5);char * tmpV = registerRCPvar(____BAH_COMPILER_VAR_1452,____BAH_COMPILER_VAR_1454,elems);

#line 1035 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1455 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1455[1] = tmpV;____BAH_COMPILER_VAR_1455[0] = "*";char * ____BAH_COMPILER_VAR_1456 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1455, 2);nt.cont = ____BAH_COMPILER_VAR_1456;
}

#line 1036 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 1037 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1457 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1457[4] = ")";____BAH_COMPILER_VAR_1457[3] = nt.cont;____BAH_COMPILER_VAR_1457[2] = "*)channel__receive(";____BAH_COMPILER_VAR_1457[1] = string__str(&ct);____BAH_COMPILER_VAR_1457[0] = "*(";char * ____BAH_COMPILER_VAR_1458 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1457, 5);nt.cont = ____BAH_COMPILER_VAR_1458;
}
}

#line 1041 "/home/alois/Documents/bah-bah/src/values.bah"
nt.type = TOKEN_TYPE_FUNC;

#line 1042 "/home/alois/Documents/bah-bah/src/values.bah"
nt.isFunc = true;

#line 1043 "/home/alois/Documents/bah-bah/src/values.bah"
nt.isValue = true;

#line 1044 "/home/alois/Documents/bah-bah/src/values.bah"
nt.bahType = string__str(&ntt);

#line 1046 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1459 = posTok;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1459);
    l->data[____BAH_COMPILER_VAR_1459] = nt;

#line 1048 "/home/alois/Documents/bah-bah/src/values.bah"
return posTok;
};

#line 1051 "/home/alois/Documents/bah-bah/src/values.bah"
long int valueTuple(__BAH_ARR_TYPE_Tok l,long int i,struct Elems* elems){

#line 1052 "/home/alois/Documents/bah-bah/src/values.bah"
long int tokPos = i;

#line 1054 "/home/alois/Documents/bah-bah/src/values.bah"
long int nbBracks = 0;

#line 1055 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((strcmp(l->data[tokPos+1].cont, "]") == 0), 0)) {

#line 1057 "/home/alois/Documents/bah-bah/src/values.bah"
long int offset = 1;

#line 1058 "/home/alois/Documents/bah-bah/src/values.bah"
while ((strcmp(l->data[tokPos+offset+1].cont, "[") == 0)&&(strcmp(l->data[tokPos+offset+2].cont, "]") == 0)) {

#line 1059 "/home/alois/Documents/bah-bah/src/values.bah"
offset = offset+2;
};

#line 1061 "/home/alois/Documents/bah-bah/src/values.bah"
if ((l->data[tokPos+offset+1].type==TOKEN_TYPE_VAR)) {

#line 1062 "/home/alois/Documents/bah-bah/src/values.bah"
return tokPos+1;
}

#line 1064 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&l->data[tokPos],"Cannot declare {TOKEN} empty tuple.");
}

#line 1069 "/home/alois/Documents/bah-bah/src/values.bah"
array(char *)* vals = memoryAlloc(sizeof(array(char *)));

vals->length = 0;
vals->elemSize = sizeof(char *);

#line 1071 "/home/alois/Documents/bah-bah/src/values.bah"
long int nbEncl = 1;

#line 1072 "/home/alois/Documents/bah-bah/src/values.bah"
++i;

#line 1072 "/home/alois/Documents/bah-bah/src/values.bah"
for (; (i<len(l)); 
#line 1072 "/home/alois/Documents/bah-bah/src/values.bah"
++i) {

#line 1073 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(l->data[i].cont, "[") == 0)||(strcmp(l->data[i].cont, "(") == 0)) {

#line 1074 "/home/alois/Documents/bah-bah/src/values.bah"
++nbEncl;
}

#line 1075 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((strcmp(l->data[1].cont, "]") == 0)||(strcmp(l->data[i].cont, ")") == 0)) {

#line 1076 "/home/alois/Documents/bah-bah/src/values.bah"
--nbEncl;

#line 1077 "/home/alois/Documents/bah-bah/src/values.bah"
if ((nbEncl==0)) {

#line 1078 "/home/alois/Documents/bah-bah/src/values.bah"
break;
}
}
};

#line 1083 "/home/alois/Documents/bah-bah/src/values.bah"
array(struct Tok)* memory = arraySubstitute(l, tokPos+1, i);

#line 1085 "/home/alois/Documents/bah-bah/src/values.bah"
memory = prePross(memory,(lineType)-1,elems);

#line 1086 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok ft = memory->data[0];

#line 1087 "/home/alois/Documents/bah-bah/src/values.bah"
char * tupT = getTypeFromToken(&ft,true,elems);

#line 1089 "/home/alois/Documents/bah-bah/src/values.bah"
register long int j = 0;

#line 1089 "/home/alois/Documents/bah-bah/src/values.bah"
for (; (j<len(memory)); 
#line 1089 "/home/alois/Documents/bah-bah/src/values.bah"
j = j+2) {

#line 1090 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok t = memory->data[j];

#line 1091 "/home/alois/Documents/bah-bah/src/values.bah"
char * tt = getTypeFromToken(&t,true,elems);

#line 1092 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((compTypes(tupT,tt)==false), 0)) {

#line 1093 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1460 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1460[4] = " in tuple declaration.";____BAH_COMPILER_VAR_1460[3] = tupT;____BAH_COMPILER_VAR_1460[2] = ") as ";____BAH_COMPILER_VAR_1460[1] = tt;____BAH_COMPILER_VAR_1460[0] = "Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_1461 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1460, 5);throwErr(&t,____BAH_COMPILER_VAR_1461);
}

#line 1095 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1462 = len(vals);
    __Bah_realocate_arr(vals, ____BAH_COMPILER_VAR_1462);
    vals->data[____BAH_COMPILER_VAR_1462] = t.cont;

#line 1096 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok nt = memory->data[j+1];

#line 1097 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(nt.cont, "]") == 0)) {

#line 1098 "/home/alois/Documents/bah-bah/src/values.bah"
break;
}

#line 1099 "/home/alois/Documents/bah-bah/src/values.bah"
else if (__builtin_expect((strcmp(nt.cont, ",") != 0), 0)) {

#line 1100 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&nt,"Expected separator between values in tuple declaration, got {TOKEN}.");
}
};

#line 1104 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1463 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1463[3] = tupT;____BAH_COMPILER_VAR_1463[2] = ":";____BAH_COMPILER_VAR_1463[1] = intToStr(len(vals));____BAH_COMPILER_VAR_1463[0] = "tuple:";char * ____BAH_COMPILER_VAR_1464 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1463, 4);char * type = ____BAH_COMPILER_VAR_1464;

#line 1106 "/home/alois/Documents/bah-bah/src/values.bah"
deleteRange(l,tokPos+1,j+1);

#line 1108 "/home/alois/Documents/bah-bah/src/values.bah"

                struct string ____BAH_COMPILER_VAR_1465 = getCType(tupT,elems);
                char** ____BAH_COMPILER_VAR_1466 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1466[4] = ")";____BAH_COMPILER_VAR_1466[3] = intToStr(len(vals));____BAH_COMPILER_VAR_1466[2] = ") * ";____BAH_COMPILER_VAR_1466[1] = string__str(&____BAH_COMPILER_VAR_1465);____BAH_COMPILER_VAR_1466[0] = "alloca(sizeof(";char * ____BAH_COMPILER_VAR_1467 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1466, 5);char * v = registerRCPvar(type,____BAH_COMPILER_VAR_1467,elems);

#line 1110 "/home/alois/Documents/bah-bah/src/values.bah"
char * r = "";

#line 1111 "/home/alois/Documents/bah-bah/src/values.bah"
i = 0;

#line 1111 "/home/alois/Documents/bah-bah/src/values.bah"
for (; (i<len(vals)); 
#line 1111 "/home/alois/Documents/bah-bah/src/values.bah"
++i) {

#line 1112 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1468 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_1468[5] = ";";____BAH_COMPILER_VAR_1468[4] = vals->data[i];____BAH_COMPILER_VAR_1468[3] = "] = ";____BAH_COMPILER_VAR_1468[2] = intToStr(i);____BAH_COMPILER_VAR_1468[1] = "[";____BAH_COMPILER_VAR_1468[0] = v;char * ____BAH_COMPILER_VAR_1469 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1468, 6);char** ____BAH_COMPILER_VAR_1470 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1470[1] = ____BAH_COMPILER_VAR_1469;____BAH_COMPILER_VAR_1470[0] = r;char * ____BAH_COMPILER_VAR_1471 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1470, 2);r = ____BAH_COMPILER_VAR_1471;
};

#line 1115 "/home/alois/Documents/bah-bah/src/values.bah"
if (isGlobal()) {

#line 1116 "/home/alois/Documents/bah-bah/src/values.bah"
INIT = rope__add(INIT, rope(r));
}

#line 1117 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 1118 "/home/alois/Documents/bah-bah/src/values.bah"
OUTPUT = rope__add(OUTPUT, rope(r));
}

#line 1121 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok ____BAH_COMPILER_VAR_1472 = {};
____BAH_COMPILER_VAR_1472.cont = "";
____BAH_COMPILER_VAR_1472.ogCont = "";
____BAH_COMPILER_VAR_1472.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1472.line = 1;
____BAH_COMPILER_VAR_1472.begLine = 1;
____BAH_COMPILER_VAR_1472.bahType = "";
____BAH_COMPILER_VAR_1472.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_1472.bahType = type;
____BAH_COMPILER_VAR_1472.cont = v;

    unsigned int ____BAH_COMPILER_VAR_1473 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1473);
    l->data[____BAH_COMPILER_VAR_1473] = ____BAH_COMPILER_VAR_1472;

#line 1127 "/home/alois/Documents/bah-bah/src/values.bah"
return tokPos;
};

#line 1130 "/home/alois/Documents/bah-bah/src/values.bah"
char isSmallValue(__BAH_ARR_TYPE_Tok l,long int i){

#line 1131 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok t = l->data[i];

#line 1132 "/home/alois/Documents/bah-bah/src/values.bah"
if ((t.type==TOKEN_TYPE_CAST)||(strcmp(t.cont, "(") == 0)) {

#line 1133 "/home/alois/Documents/bah-bah/src/values.bah"
return false;
}

#line 1134 "/home/alois/Documents/bah-bah/src/values.bah"
else if (__builtin_expect((t.isValue==false), 0)) {

#line 1135 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&t,"Cannot use {TOKEN} as value.");
}

#line 1137 "/home/alois/Documents/bah-bah/src/values.bah"
if ((i+1<len(l))) {

#line 1138 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok nt = l->data[i+1];

#line 1139 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(nt.cont, "[") == 0)||(strcmp(nt.cont, ".") == 0)||(strcmp(nt.cont, "(") == 0)) {

#line 1140 "/home/alois/Documents/bah-bah/src/values.bah"
return false;
}
}

#line 1143 "/home/alois/Documents/bah-bah/src/values.bah"
return true;
};

#line 1146 "/home/alois/Documents/bah-bah/src/values.bah"
char isValue(__BAH_ARR_TYPE_Tok l,long int i){

#line 1147 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok t = l->data[i];

#line 1148 "/home/alois/Documents/bah-bah/src/values.bah"
if ((t.type==TOKEN_TYPE_CAST)||(strcmp(t.cont, "(") == 0)) {

#line 1149 "/home/alois/Documents/bah-bah/src/values.bah"
return false;
}

#line 1150 "/home/alois/Documents/bah-bah/src/values.bah"
else if (__builtin_expect((t.isValue==false), 0)) {

#line 1151 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&t,"Cannot use {TOKEN} as value.");
}

#line 1153 "/home/alois/Documents/bah-bah/src/values.bah"
if ((i+1<len(l))) {

#line 1154 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok nt = l->data[i+1];

#line 1155 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(nt.cont, "[") == 0)||(strcmp(nt.cont, ".") == 0)||(strcmp(nt.cont, "(") == 0)||inArrayStr(nt.cont,signs)) {

#line 1156 "/home/alois/Documents/bah-bah/src/values.bah"
return false;
}
}

#line 1159 "/home/alois/Documents/bah-bah/src/values.bah"
return true;
};

#line 2998 "/home/alois/Documents/bah-bah/src/parser.bah"
__BAH_ARR_TYPE_Tok prePross(__BAH_ARR_TYPE_Tok line,lineType ltp,struct Elems* elems){

#line 3000 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct Tok)* fl = memoryAlloc(sizeof(array(struct Tok)));

fl->length = 0;
fl->elemSize = sizeof(struct Tok);

#line 3001 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int i = 0;

#line 3002 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int sepI = 0;

#line 3003 "/home/alois/Documents/bah-bah/src/parser.bah"
long int nbPar = 0;

#line 3005 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((ltp!=(lineType)-1)) {

#line 3006 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<len(line)); 
#line 3006 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 3007 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = line->data[i];

#line 3008 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "(") == 0)) {

#line 3009 "/home/alois/Documents/bah-bah/src/parser.bah"
char isFunc = true;

#line 3010 "/home/alois/Documents/bah-bah/src/parser.bah"
nbPar = nbPar+1;
}

#line 3011 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(t.cont, ")") == 0)) {

#line 3012 "/home/alois/Documents/bah-bah/src/parser.bah"
nbPar = nbPar-1;
}

#line 3013 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((nbPar==0)&&(strcmp(t.cont, "{") == 0)) {

#line 3014 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((line->data[i+1].line!=t.line)) {

#line 3015 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}
}
};

#line 3019 "/home/alois/Documents/bah-bah/src/parser.bah"
fl = arraySubstitute(line, 0, i);

#line 3020 "/home/alois/Documents/bah-bah/src/parser.bah"
sepI = i;
}

#line 3021 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 3022 "/home/alois/Documents/bah-bah/src/parser.bah"
fl = line;
}

#line 3025 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok ____BAH_COMPILER_VAR_1474 = {};
____BAH_COMPILER_VAR_1474.cont = "";
____BAH_COMPILER_VAR_1474.ogCont = "";
____BAH_COMPILER_VAR_1474.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1474.line = 1;
____BAH_COMPILER_VAR_1474.begLine = 1;
____BAH_COMPILER_VAR_1474.bahType = "";
struct Tok pt = ____BAH_COMPILER_VAR_1474;

#line 3026 "/home/alois/Documents/bah-bah/src/parser.bah"
long int l = len(fl);

#line 3028 "/home/alois/Documents/bah-bah/src/parser.bah"
i = 0;

#line 3028 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<len(fl)); 
#line 3028 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 3029 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = fl->data[i];

#line 3030 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((t.type==TOKEN_TYPE_VAR)&&(t.isOper==false)&&(t.cont[0]==38)) {

#line 3031 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string tc = string(t.cont);

#line 3032 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimLeft(&tc,1);

#line 3033 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ____BAH_COMPILER_VAR_1475 =string__str(&tc);struct variable* rv = getRealVar(____BAH_COMPILER_VAR_1475,elems);

#line 3034 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((rv!=null)&&(rv->canBeReg==true)&&(rv->declRope!=null)) {

#line 3035 "/home/alois/Documents/bah-bah/src/parser.bah"
char * rvdr = rope__toStr(rv->declRope);

#line 3036 "/home/alois/Documents/bah-bah/src/parser.bah"
if (strHasPrefix(rvdr,"register ")) {

#line 3037 "/home/alois/Documents/bah-bah/src/parser.bah"
strTrimLeft(&rvdr,9);

#line 3038 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT->totalLen = OUTPUT->totalLen+ropeSet(rv->declRope,rvdr);
}

#line 3040 "/home/alois/Documents/bah-bah/src/parser.bah"
rv->canBeReg = false;
}
}
};

#line 3045 "/home/alois/Documents/bah-bah/src/parser.bah"
i = 0;

#line 3045 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<len(fl)); 
#line 3045 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 3046 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((fl->data[i].type==TOKEN_TYPE_STR)&&(fl->data[i].processedStr==false)) {

#line 3047 "/home/alois/Documents/bah-bah/src/parser.bah"
fl->data[i].cont = strLitteralToBahStr(fl->data[i].cont);

#line 3048 "/home/alois/Documents/bah-bah/src/parser.bah"
fl->data[i].processedStr = true;
}
};

#line 3052 "/home/alois/Documents/bah-bah/src/parser.bah"
if (fixMeEnabled()) {

#line 3053 "/home/alois/Documents/bah-bah/src/parser.bah"
i = 0;

#line 3053 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<len(fl)); 
#line 3053 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 3054 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((fl->data[i].cont[0]==42)) {

#line 3055 "/home/alois/Documents/bah-bah/src/parser.bah"
fixMeTestVar(&fl->data[i],ltp,elems);
}
};
}

#line 3060 "/home/alois/Documents/bah-bah/src/parser.bah"
i = 0;

#line 3060 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<len(fl)); 
#line 3060 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 3061 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = fl->data[i];

#line 3062 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((i>0)) {

#line 3063 "/home/alois/Documents/bah-bah/src/parser.bah"
pt = fl->data[i-1];
}

#line 3064 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 3065 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok ____BAH_COMPILER_VAR_1476 = {};
____BAH_COMPILER_VAR_1476.cont = "";
____BAH_COMPILER_VAR_1476.ogCont = "";
____BAH_COMPILER_VAR_1476.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1476.line = 1;
____BAH_COMPILER_VAR_1476.begLine = 1;
____BAH_COMPILER_VAR_1476.bahType = "";
pt = ____BAH_COMPILER_VAR_1476;
}

#line 3068 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, ".") == 0)&&(i>0)) {

#line 3069 "/home/alois/Documents/bah-bah/src/parser.bah"
i = valueStruct(fl,i,ltp,elems)-1;
}

#line 3070 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(t.cont, "(") == 0)&&(strcmp(pt.cont, "function") != 0)) {

#line 3071 "/home/alois/Documents/bah-bah/src/parser.bah"
i = valueFunc(null,null,fl,i,ltp,elems)-1;
}

#line 3072 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(t.cont, "[") == 0)&&(pt.isValue==true)) {

#line 3073 "/home/alois/Documents/bah-bah/src/parser.bah"
i = valueArr(fl,i,ltp,elems)-1;
}

#line 3074 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(t.cont, "[") == 0)) {

#line 3075 "/home/alois/Documents/bah-bah/src/parser.bah"
i = valueTuple(fl,i,elems)-1;
}

#line 3076 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((pt.type==TOKEN_TYPE_CAST)&&isSmallValue(fl,i)) {

#line 3077 "/home/alois/Documents/bah-bah/src/parser.bah"
delete(fl,i-1);

#line 3078 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string ptc = string(pt.cont);

#line 3079 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimLeft(&ptc,1);

#line 3080 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimRight(&ptc,1);

#line 3081 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((t.type==TOKEN_TYPE_VAR)) {

#line 3082 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* v = searchVar(t.cont,elems);

#line 3083 "/home/alois/Documents/bah-bah/src/parser.bah"
t.bahRef = v;
}

#line 3085 "/home/alois/Documents/bah-bah/src/parser.bah"
t.bahType = string__str(&ptc);

#line 3086 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ____BAH_COMPILER_VAR_1477 =string__str(&ptc);struct string cType = getCType(____BAH_COMPILER_VAR_1477,elems);

#line 3087 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1478 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1478[3] = t.cont;____BAH_COMPILER_VAR_1478[2] = ")";____BAH_COMPILER_VAR_1478[1] = string__str(&cType);____BAH_COMPILER_VAR_1478[0] = "(";char * ____BAH_COMPILER_VAR_1479 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1478, 4);t.cont = ____BAH_COMPILER_VAR_1479;

#line 3088 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1480 = i-1;
    __Bah_realocate_arr(fl, ____BAH_COMPILER_VAR_1480);
    fl->data[____BAH_COMPILER_VAR_1480] = t;

#line 3089 "/home/alois/Documents/bah-bah/src/parser.bah"
i = i-2;
}

#line 3090 "/home/alois/Documents/bah-bah/src/parser.bah"
else if (inArrayStr(pt.cont,signs)) {

#line 3091 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, pt.cont) == 0)&&(i>1)) {

#line 3092 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok ppt = fl->data[i-2];

#line 3093 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((ppt.type==TOKEN_TYPE_VAR)) {

#line 3094 "/home/alois/Documents/bah-bah/src/parser.bah"
long int posTok = i-2;

#line 3095 "/home/alois/Documents/bah-bah/src/parser.bah"
deleteRange(fl,i-1,i);

#line 3096 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1481 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1481[2] = ppt.cont;____BAH_COMPILER_VAR_1481[1] = t.cont;____BAH_COMPILER_VAR_1481[0] = t.cont;char * ____BAH_COMPILER_VAR_1482 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1481, 3);ppt.cont = ____BAH_COMPILER_VAR_1482;

#line 3097 "/home/alois/Documents/bah-bah/src/parser.bah"
ppt.isValue = true;

#line 3098 "/home/alois/Documents/bah-bah/src/parser.bah"
ppt.isOper = true;

#line 3099 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1483 = posTok;
    __Bah_realocate_arr(fl, ____BAH_COMPILER_VAR_1483);
    fl->data[____BAH_COMPILER_VAR_1483] = ppt;

#line 3100 "/home/alois/Documents/bah-bah/src/parser.bah"
i = posTok-1;
}

#line 3101 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 3102 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&ppt,"Cannot increment/decrement non variable value {TOKEN}.");
}
}

#line 3104 "/home/alois/Documents/bah-bah/src/parser.bah"
else if (isValue(fl,i)) {

#line 3105 "/home/alois/Documents/bah-bah/src/parser.bah"
i = valueOper(fl,i,elems)-1;
}
}

#line 3107 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((t.cont[0]==45)&&(pt.isValue==true)) {

#line 3109 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((t.type==TOKEN_TYPE_INT)||(t.type==TOKEN_TYPE_FLOAT)) {

#line 3110 "/home/alois/Documents/bah-bah/src/parser.bah"
delete(fl,i);

#line 3111 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ptt = getTypeFromToken(&pt,true,elems);

#line 3112 "/home/alois/Documents/bah-bah/src/parser.bah"
pt.bahType = ptt;

#line 3113 "/home/alois/Documents/bah-bah/src/parser.bah"
pt.isOper = true;

#line 3114 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1484 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1484[1] = t.cont;____BAH_COMPILER_VAR_1484[0] = pt.cont;char * ____BAH_COMPILER_VAR_1485 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1484, 2);pt.cont = ____BAH_COMPILER_VAR_1485;

#line 3115 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1486 = i-1;
    __Bah_realocate_arr(fl, ____BAH_COMPILER_VAR_1486);
    fl->data[____BAH_COMPILER_VAR_1486] = pt;

#line 3116 "/home/alois/Documents/bah-bah/src/parser.bah"
--i;
}
}

#line 3118 "/home/alois/Documents/bah-bah/src/parser.bah"
else if (inArrayStr(pt.cont,comparators)&&isValue(fl,i)) {

#line 3119 "/home/alois/Documents/bah-bah/src/parser.bah"
i = valueBool(fl,i,ltp,elems)-1;
}

#line 3120 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(pt.cont, "<-") == 0)&&isValue(fl,i)) {

#line 3121 "/home/alois/Documents/bah-bah/src/parser.bah"
i = valueChan(fl,i,elems)-1;
}

#line 3122 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(pt.cont, "->") == 0)&&isValue(fl,i)) {

#line 3123 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((i-2>=0)) {

#line 3124 "/home/alois/Documents/bah-bah/src/parser.bah"
if (isValue(fl,i-2)) {

#line 3125 "/home/alois/Documents/bah-bah/src/parser.bah"
i = valueSendChan(fl,i,elems)-1;
}
}

#line 3127 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 3128 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"Cannot {TOKEN} nothing through chan.");
}
}
};

#line 3134 "/home/alois/Documents/bah-bah/src/parser.bah"
i = 0;

#line 3134 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<len(fl)); 
#line 3134 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 3135 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = fl->data[i];

#line 3136 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "||") == 0)||(strcmp(t.cont, "&&") == 0)) {

#line 3137 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((i==0)||(i+1==len(fl)), 0)) {

#line 3138 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"Cannot use {TOKEN} on nothing.");
}

#line 3140 "/home/alois/Documents/bah-bah/src/parser.bah"
pt = fl->data[i-1];

#line 3141 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok nt = fl->data[i+1];

#line 3142 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ptt = getTypeFromToken(&pt,true,elems);

#line 3143 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ntt = getTypeFromToken(&nt,true,elems);

#line 3144 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((compTypes(ptt,ntt)==false)||(compTypes(ptt,"bool")==false), 0)) {

#line 3145 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1487 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1487[2] = ".";____BAH_COMPILER_VAR_1487[1] = ptt;____BAH_COMPILER_VAR_1487[0] = "Cannot use {TOKEN} on ";char * ____BAH_COMPILER_VAR_1488 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1487, 3);throwErr(&t,____BAH_COMPILER_VAR_1488);
}

#line 3148 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "||") == 0)&&(isExprExpensive(&pt)==false)&&(isExprExpensive(&nt)==false)) {

#line 3149 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1489 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1489[1] = nt.cont;____BAH_COMPILER_VAR_1489[0] = "||";char * ____BAH_COMPILER_VAR_1490 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1489, 2);char** ____BAH_COMPILER_VAR_1491 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1491[1] = ____BAH_COMPILER_VAR_1490;____BAH_COMPILER_VAR_1491[0] = pt.cont;char * ____BAH_COMPILER_VAR_1492 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1491, 2);pt.cont = ____BAH_COMPILER_VAR_1492;
}

#line 3150 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 3151 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1493 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1493[1] = nt.cont;____BAH_COMPILER_VAR_1493[0] = t.cont;char * ____BAH_COMPILER_VAR_1494 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1493, 2);char** ____BAH_COMPILER_VAR_1495 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1495[1] = ____BAH_COMPILER_VAR_1494;____BAH_COMPILER_VAR_1495[0] = pt.cont;char * ____BAH_COMPILER_VAR_1496 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1495, 2);pt.cont = ____BAH_COMPILER_VAR_1496;
}

#line 3153 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1497 = i-1;
    __Bah_realocate_arr(fl, ____BAH_COMPILER_VAR_1497);
    fl->data[____BAH_COMPILER_VAR_1497] = pt;

#line 3154 "/home/alois/Documents/bah-bah/src/parser.bah"
deleteRange(fl,i,i+1);

#line 3155 "/home/alois/Documents/bah-bah/src/parser.bah"
i = i-2;
}

#line 3156 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((t.type==TOKEN_TYPE_VAR)&&(t.cont[0]==38)) {

#line 3157 "/home/alois/Documents/bah-bah/src/parser.bah"
char * tt = getTypeFromToken(&t,true,elems);

#line 3158 "/home/alois/Documents/bah-bah/src/parser.bah"

                struct string ____BAH_COMPILER_VAR_1498 = string(tt);
                if (__builtin_expect(string__hasPrefix(&____BAH_COMPILER_VAR_1498,"tuple:"), 0)) {

#line 3159 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"Cannot get pointer of a tuple {TOKEN}.");
}
}
};

#line 3164 "/home/alois/Documents/bah-bah/src/parser.bah"
fl = parseArrayType(fl,elems,true);

#line 3165 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((RCPavailable()==true)) {

#line 3166 "/home/alois/Documents/bah-bah/src/parser.bah"
addRCPvars(fl,ltp,elems);
}

#line 3169 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((ltp!=(lineType)-1)) {

#line 3170 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((sepI<len(line))) {

#line 3171 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1499 = len(fl);
    __Bah_realocate_arr(fl, ____BAH_COMPILER_VAR_1499);
    fl->data[____BAH_COMPILER_VAR_1499] = line->data[sepI];

#line 3172 "/home/alois/Documents/bah-bah/src/parser.bah"
++sepI;
};
}

#line 3178 "/home/alois/Documents/bah-bah/src/parser.bah"
return fl;
};

#line 3181 "/home/alois/Documents/bah-bah/src/parser.bah"
void parseFnDeclare(__BAH_ARR_TYPE_Tok l,struct Elems* elems){

#line 3182 "/home/alois/Documents/bah-bah/src/parser.bah"
long int i = 0;

#line 3183 "/home/alois/Documents/bah-bah/src/parser.bah"
struct func* ____BAH_COMPILER_VAR_1500 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_1500->name = "";
____BAH_COMPILER_VAR_1500->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_1500->args->length = 0;
            ____BAH_COMPILER_VAR_1500->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_1500->from = "";
____BAH_COMPILER_VAR_1500->file = "";
____BAH_COMPILER_VAR_1500->line = 1;
struct func* fn = ____BAH_COMPILER_VAR_1500;

#line 3185 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((RCPavailable()==false)&&(RCPenabled==true)) {

#line 3186 "/home/alois/Documents/bah-bah/src/parser.bah"
fn->used = true;
}

#line 3189 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok ft = l->data[0];

#line 3190 "/home/alois/Documents/bah-bah/src/parser.bah"
char * code = parseFnHeader("",l,&i,fn,elems);

#line 3191 "/home/alois/Documents/bah-bah/src/parser.bah"
fn->line = ft.line;

#line 3192 "/home/alois/Documents/bah-bah/src/parser.bah"
fn->file = compilerState.currentFile;

#line 3193 "/home/alois/Documents/bah-bah/src/parser.bah"
struct func* ogFn = searchFunc(fn->name,elems,false);

#line 3194 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((ogFn!=null)) {

#line 3195 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((ogFn->isBinding==false), 0)) {

#line 3196 "/home/alois/Documents/bah-bah/src/parser.bah"
char * lineStr = intToStr(ogFn->line);

#line 3197 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1501 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1501[4] = ".";____BAH_COMPILER_VAR_1501[3] = lineStr;____BAH_COMPILER_VAR_1501[2] = ":";____BAH_COMPILER_VAR_1501[1] = ogFn->file;____BAH_COMPILER_VAR_1501[0] = "Cannot redeclare function {TOKEN}, previous declaration: ";char * ____BAH_COMPILER_VAR_1502 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1501, 5);throwErr(&ft,____BAH_COMPILER_VAR_1502);
}
}

#line 3201 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(fn->name, "main") == 0)) {

#line 3202 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.haveEntryPoint = true;

#line 3203 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((compTypes(fn->returns->type,"int")==false), 0)) {

#line 3204 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&ft,"{TOKEN} function should return 'int'.");
}

#line 3206 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((len(fn->args)!=1), 0)) {

#line 3207 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&ft,"{TOKEN} function should take one []cpstring argument. Should be: \n            'main(args []cpstring) int'");
}

#line 3210 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* fa = fn->args->data[0];

#line 3211 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((compTypes(fa->type,"[]cpstring")==false), 0)) {

#line 3212 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&ft,"{TOKEN} function should take []cpstring as argument. Should be: \n            'main(args []cpstring) int'");
}
}

#line 3217 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((debug==true)) {

#line 3218 "/home/alois/Documents/bah-bah/src/parser.bah"
struct debugFunction* ____BAH_COMPILER_VAR_1503 = memoryAlloc(sizeof(struct debugFunction));
____BAH_COMPILER_VAR_1503->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_1503->args->length = 0;
            ____BAH_COMPILER_VAR_1503->args->elemSize = sizeof(struct variable*);
            struct debugFunction* df = ____BAH_COMPILER_VAR_1503;

#line 3219 "/home/alois/Documents/bah-bah/src/parser.bah"
df->name = fn->name;

#line 3220 "/home/alois/Documents/bah-bah/src/parser.bah"
df->args = fn->args;

#line 3221 "/home/alois/Documents/bah-bah/src/parser.bah"
df->returns = fn->returns->type;

#line 3222 "/home/alois/Documents/bah-bah/src/parser.bah"
struct debugFunction* ____BAH_COMPILER_VAR_1504 = df;
char ** ____BAH_COMPILER_VAR_1506 = (char **)((char*)(____BAH_COMPILER_VAR_1504) + offsetof(struct debugFunction, name));
struct reflectElement ____BAH_COMPILER_VAR_1507 = __reflect(____BAH_COMPILER_VAR_1506, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct debugFunction, name));
char ** ____BAH_COMPILER_VAR_1508 = (char **)((char*)(____BAH_COMPILER_VAR_1504) + offsetof(struct debugFunction, returns));
struct reflectElement ____BAH_COMPILER_VAR_1509 = __reflect(____BAH_COMPILER_VAR_1508, sizeof(char *), "cpstring", "returns", 0, 0, 0, 0, offsetof(struct debugFunction, returns));
array(struct variable*)** ____BAH_COMPILER_VAR_1510 = (array(struct variable*)**)((char*)(____BAH_COMPILER_VAR_1504) + offsetof(struct debugFunction, args));
struct variable** ____BAH_COMPILER_VAR_1511 = 0;
char ** ____BAH_COMPILER_VAR_1513 = (char **)((char*)(____BAH_COMPILER_VAR_1511) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_1514 = __reflect(____BAH_COMPILER_VAR_1513, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_1515 = (char **)((char*)(____BAH_COMPILER_VAR_1511) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_1516 = __reflect(____BAH_COMPILER_VAR_1515, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_1517 = (char*)((char*)(____BAH_COMPILER_VAR_1511) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_1518 = __reflect(____BAH_COMPILER_VAR_1517, sizeof(char), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_1519 = (char **)((char*)(____BAH_COMPILER_VAR_1511) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_1520 = __reflect(____BAH_COMPILER_VAR_1519, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_1521 = (char*)((char*)(____BAH_COMPILER_VAR_1511) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_1522 = __reflect(____BAH_COMPILER_VAR_1521, sizeof(char), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_1523 = (char **)((char*)(____BAH_COMPILER_VAR_1511) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_1524 = __reflect(____BAH_COMPILER_VAR_1523, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
void ** ____BAH_COMPILER_VAR_1525 = (void **)((char*)(____BAH_COMPILER_VAR_1511) + offsetof(struct variable, declScope));
struct reflectElement ____BAH_COMPILER_VAR_1526 = __reflect(____BAH_COMPILER_VAR_1525, sizeof(void *), "ptr", "declScope", 0, 0, 0, 0, offsetof(struct variable, declScope));
char* ____BAH_COMPILER_VAR_1527 = (char*)((char*)(____BAH_COMPILER_VAR_1511) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_1528 = __reflect(____BAH_COMPILER_VAR_1527, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));
struct rope** ____BAH_COMPILER_VAR_1529 = (struct rope**)((char*)(____BAH_COMPILER_VAR_1511) + offsetof(struct variable, declRope));
void ** ____BAH_COMPILER_VAR_1531 = (void **)((char*)(____BAH_COMPILER_VAR_1529) + offsetof(struct rope, left));
struct reflectElement ____BAH_COMPILER_VAR_1532 = __reflect(____BAH_COMPILER_VAR_1531, sizeof(void *), "ptr", "left", 0, 0, 0, 0, offsetof(struct rope, left));
void ** ____BAH_COMPILER_VAR_1533 = (void **)((char*)(____BAH_COMPILER_VAR_1529) + offsetof(struct rope, right));
struct reflectElement ____BAH_COMPILER_VAR_1534 = __reflect(____BAH_COMPILER_VAR_1533, sizeof(void *), "ptr", "right", 0, 0, 0, 0, offsetof(struct rope, right));
char ** ____BAH_COMPILER_VAR_1535 = (char **)((char*)(____BAH_COMPILER_VAR_1529) + offsetof(struct rope, str));
struct reflectElement ____BAH_COMPILER_VAR_1536 = __reflect(____BAH_COMPILER_VAR_1535, sizeof(char *), "cpstring", "str", 0, 0, 0, 0, offsetof(struct rope, str));
int* ____BAH_COMPILER_VAR_1537 = (int*)((char*)(____BAH_COMPILER_VAR_1529) + offsetof(struct rope, lCount));
struct reflectElement ____BAH_COMPILER_VAR_1538 = __reflect(____BAH_COMPILER_VAR_1537, sizeof(int), "int32", "lCount", 0, 0, 0, 0, offsetof(struct rope, lCount));
int* ____BAH_COMPILER_VAR_1539 = (int*)((char*)(____BAH_COMPILER_VAR_1529) + offsetof(struct rope, len));
struct reflectElement ____BAH_COMPILER_VAR_1540 = __reflect(____BAH_COMPILER_VAR_1539, sizeof(int), "int32", "len", 0, 0, 0, 0, offsetof(struct rope, len));
int* ____BAH_COMPILER_VAR_1541 = (int*)((char*)(____BAH_COMPILER_VAR_1529) + offsetof(struct rope, totalLen));
struct reflectElement ____BAH_COMPILER_VAR_1542 = __reflect(____BAH_COMPILER_VAR_1541, sizeof(int), "int32", "totalLen", 0, 0, 0, 0, offsetof(struct rope, totalLen));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_1530 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_1530->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_1530->length = 6;
        ____BAH_COMPILER_VAR_1530->data = memoryAlloc(____BAH_COMPILER_VAR_1530->length * ____BAH_COMPILER_VAR_1530->elemSize);
        ____BAH_COMPILER_VAR_1530->data[0] = ____BAH_COMPILER_VAR_1532;
____BAH_COMPILER_VAR_1530->data[1] = ____BAH_COMPILER_VAR_1534;
____BAH_COMPILER_VAR_1530->data[2] = ____BAH_COMPILER_VAR_1536;
____BAH_COMPILER_VAR_1530->data[3] = ____BAH_COMPILER_VAR_1538;
____BAH_COMPILER_VAR_1530->data[4] = ____BAH_COMPILER_VAR_1540;
____BAH_COMPILER_VAR_1530->data[5] = ____BAH_COMPILER_VAR_1542;
struct reflectElement ____BAH_COMPILER_VAR_1543 = __reflect(____BAH_COMPILER_VAR_1529, sizeof(struct rope), "rope*", "declRope", 0, 0, 1, ____BAH_COMPILER_VAR_1530, offsetof(struct variable, declRope));
char* ____BAH_COMPILER_VAR_1544 = (char*)((char*)(____BAH_COMPILER_VAR_1511) + offsetof(struct variable, canBeNull));
struct reflectElement ____BAH_COMPILER_VAR_1545 = __reflect(____BAH_COMPILER_VAR_1544, sizeof(char), "bool", "canBeNull", 0, 0, 0, 0, offsetof(struct variable, canBeNull));
void ** ____BAH_COMPILER_VAR_1546 = (void **)((char*)(____BAH_COMPILER_VAR_1511) + offsetof(struct variable, iterScope));
struct reflectElement ____BAH_COMPILER_VAR_1547 = __reflect(____BAH_COMPILER_VAR_1546, sizeof(void *), "ptr", "iterScope", 0, 0, 0, 0, offsetof(struct variable, iterScope));
char* ____BAH_COMPILER_VAR_1548 = (char*)((char*)(____BAH_COMPILER_VAR_1511) + offsetof(struct variable, canBeReg));
struct reflectElement ____BAH_COMPILER_VAR_1549 = __reflect(____BAH_COMPILER_VAR_1548, sizeof(char), "bool", "canBeReg", 0, 0, 0, 0, offsetof(struct variable, canBeReg));
char* ____BAH_COMPILER_VAR_1550 = (char*)((char*)(____BAH_COMPILER_VAR_1511) + offsetof(struct variable, isReg));
struct reflectElement ____BAH_COMPILER_VAR_1551 = __reflect(____BAH_COMPILER_VAR_1550, sizeof(char), "bool", "isReg", 0, 0, 0, 0, offsetof(struct variable, isReg));
void ** ____BAH_COMPILER_VAR_1552 = (void **)((char*)(____BAH_COMPILER_VAR_1511) + offsetof(struct variable, lastSet));
struct reflectElement ____BAH_COMPILER_VAR_1553 = __reflect(____BAH_COMPILER_VAR_1552, sizeof(void *), "ptr", "lastSet", 0, 0, 0, 0, offsetof(struct variable, lastSet));
char* ____BAH_COMPILER_VAR_1554 = (char*)((char*)(____BAH_COMPILER_VAR_1511) + offsetof(struct variable, isArg));
struct reflectElement ____BAH_COMPILER_VAR_1555 = __reflect(____BAH_COMPILER_VAR_1554, sizeof(char), "bool", "isArg", 0, 0, 0, 0, offsetof(struct variable, isArg));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_1512 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_1512->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_1512->length = 15;
        ____BAH_COMPILER_VAR_1512->data = memoryAlloc(____BAH_COMPILER_VAR_1512->length * ____BAH_COMPILER_VAR_1512->elemSize);
        ____BAH_COMPILER_VAR_1512->data[0] = ____BAH_COMPILER_VAR_1514;
____BAH_COMPILER_VAR_1512->data[1] = ____BAH_COMPILER_VAR_1516;
____BAH_COMPILER_VAR_1512->data[2] = ____BAH_COMPILER_VAR_1518;
____BAH_COMPILER_VAR_1512->data[3] = ____BAH_COMPILER_VAR_1520;
____BAH_COMPILER_VAR_1512->data[4] = ____BAH_COMPILER_VAR_1522;
____BAH_COMPILER_VAR_1512->data[5] = ____BAH_COMPILER_VAR_1524;
____BAH_COMPILER_VAR_1512->data[6] = ____BAH_COMPILER_VAR_1526;
____BAH_COMPILER_VAR_1512->data[7] = ____BAH_COMPILER_VAR_1528;
____BAH_COMPILER_VAR_1512->data[8] = ____BAH_COMPILER_VAR_1543;
____BAH_COMPILER_VAR_1512->data[9] = ____BAH_COMPILER_VAR_1545;
____BAH_COMPILER_VAR_1512->data[10] = ____BAH_COMPILER_VAR_1547;
____BAH_COMPILER_VAR_1512->data[11] = ____BAH_COMPILER_VAR_1549;
____BAH_COMPILER_VAR_1512->data[12] = ____BAH_COMPILER_VAR_1551;
____BAH_COMPILER_VAR_1512->data[13] = ____BAH_COMPILER_VAR_1553;
____BAH_COMPILER_VAR_1512->data[14] = ____BAH_COMPILER_VAR_1555;
struct reflectElement ____BAH_COMPILER_VAR_1556 = __reflect(____BAH_COMPILER_VAR_1511, sizeof(struct variable), "variable*", "", 0, 0, 1, ____BAH_COMPILER_VAR_1512, 0);

        struct reflectElement ____BAH_COMPILER_VAR_1557 = ____BAH_COMPILER_VAR_1556;
        struct reflectElement ____BAH_COMPILER_VAR_1558 = __reflect(____BAH_COMPILER_VAR_1510, sizeof(array(struct variable*)*), "[]variable*", "args", 1, &____BAH_COMPILER_VAR_1557, 0, 0, offsetof(struct debugFunction, args));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_1505 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_1505->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_1505->length = 3;
        ____BAH_COMPILER_VAR_1505->data = memoryAlloc(____BAH_COMPILER_VAR_1505->length * ____BAH_COMPILER_VAR_1505->elemSize);
        ____BAH_COMPILER_VAR_1505->data[0] = ____BAH_COMPILER_VAR_1507;
____BAH_COMPILER_VAR_1505->data[1] = ____BAH_COMPILER_VAR_1509;
____BAH_COMPILER_VAR_1505->data[2] = ____BAH_COMPILER_VAR_1558;
struct reflectElement ____BAH_COMPILER_VAR_1559 = __reflect(____BAH_COMPILER_VAR_1504, sizeof(struct debugFunction), "debugFunction*", "df", 0, 0, 1, ____BAH_COMPILER_VAR_1505, 0);
debugPrint("fn_declare",ft.line,____BAH_COMPILER_VAR_1559);
}

#line 3225 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int j = 0;

#line 3225 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (j<len(fn->args)); 
#line 3225 "/home/alois/Documents/bah-bah/src/parser.bah"
++j) {

#line 3226 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(fn->args->data[j]->type, "<any>") == 0)) {

#line 3227 "/home/alois/Documents/bah-bah/src/parser.bah"
struct genericFunc* ____BAH_COMPILER_VAR_1560 = memoryAlloc(sizeof(struct genericFunc));
____BAH_COMPILER_VAR_1560->tokens = memoryAlloc(sizeof(array(struct Tok)));
            ____BAH_COMPILER_VAR_1560->tokens->length = 0;
            ____BAH_COMPILER_VAR_1560->tokens->elemSize = sizeof(struct Tok);
            ____BAH_COMPILER_VAR_1560->declared = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_1560->declared->length = 0;
            ____BAH_COMPILER_VAR_1560->declared->elemSize = sizeof(struct func*);
            ____BAH_COMPILER_VAR_1560->tokens = arraySubstitute(l, i+1, len(l)-1);
____BAH_COMPILER_VAR_1560->baseFn = fn;
____BAH_COMPILER_VAR_1560->tokenName = &ft;

    unsigned int ____BAH_COMPILER_VAR_1561 = len(generics);
    __Bah_realocate_arr(generics, ____BAH_COMPILER_VAR_1561);
    generics->data[____BAH_COMPILER_VAR_1561] = ____BAH_COMPILER_VAR_1560;

#line 3232 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}
};

#line 3236 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((shouldOnlyDecl==true)) {

#line 3237 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((ogFn!=null)) {

#line 3238 "/home/alois/Documents/bah-bah/src/parser.bah"
fn->isBinding = false;
}

#line 3240 "/home/alois/Documents/bah-bah/src/parser.bah"
fn->isImported = true;

#line 3241 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1562 = len(elems->fns);
    __Bah_realocate_arr(elems->fns, ____BAH_COMPILER_VAR_1562);
    elems->fns->data[____BAH_COMPILER_VAR_1562] = fn;

#line 3242 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1563 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1563[1] = ";\n";____BAH_COMPILER_VAR_1563[0] = code;char * ____BAH_COMPILER_VAR_1564 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1563, 2);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1564));

#line 3243 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}

#line 3246 "/home/alois/Documents/bah-bah/src/parser.bah"
postDeclHandle = rope("");

#line 3247 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope__add(OUTPUT, postDeclHandle);

#line 3249 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1565 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1565[1] = "{\n";____BAH_COMPILER_VAR_1565[0] = code;char * ____BAH_COMPILER_VAR_1566 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1565, 2);code = ____BAH_COMPILER_VAR_1566;

#line 3251 "/home/alois/Documents/bah-bah/src/parser.bah"
fn->code = rope(code);

#line 3254 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Elems* fnElems = dupElems(elems);

#line 3256 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct variable*)* vs = fnElems->vars;

#line 3257 "/home/alois/Documents/bah-bah/src/parser.bah"
j = 0;

#line 3257 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((j<len(fn->args))) {

#line 3258 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* a = fn->args->data[j];

#line 3259 "/home/alois/Documents/bah-bah/src/parser.bah"
a->declScope = elems;

#line 3260 "/home/alois/Documents/bah-bah/src/parser.bah"
a->isArg = true;

#line 3261 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1567 = len(vs);
    __Bah_realocate_arr(vs, ____BAH_COMPILER_VAR_1567);
    vs->data[____BAH_COMPILER_VAR_1567] = a;

#line 3262 "/home/alois/Documents/bah-bah/src/parser.bah"
j = j+1;
};

#line 3264 "/home/alois/Documents/bah-bah/src/parser.bah"
fnElems->vars = vs;

#line 3266 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((ogFn!=null)) {

#line 3267 "/home/alois/Documents/bah-bah/src/parser.bah"
ogFn->isBinding = false;

#line 3268 "/home/alois/Documents/bah-bah/src/parser.bah"
ogFn->used = true;

#line 3269 "/home/alois/Documents/bah-bah/src/parser.bah"
ogFn = fn;
}

#line 3270 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 3271 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct func*)* fns = elems->fns;

#line 3272 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1568 = len(fns);
    __Bah_realocate_arr(fns, ____BAH_COMPILER_VAR_1568);
    fns->data[____BAH_COMPILER_VAR_1568] = fn;
}

#line 3275 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 3276 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct Tok)* tokens = arraySubstitute(l, i, len(l)-1);

#line 3278 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((len(tokens)==0)) {

#line 3279 "/home/alois/Documents/bah-bah/src/parser.bah"
fn->code = rope__add(fn->code, rope("};\n"));

#line 3280 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope__add(OUTPUT, fn->code);

#line 3281 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}

#line 3284 "/home/alois/Documents/bah-bah/src/parser.bah"
currentFn = fn;

#line 3286 "/home/alois/Documents/bah-bah/src/parser.bah"
struct rope* oOut = OUTPUT;

#line 3287 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope("");

#line 3288 "/home/alois/Documents/bah-bah/src/parser.bah"
beginRCPscope(fnElems,fn->args);

#line 3289 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Elems* ocurrFnElems = compilerState.currFnElems;

#line 3290 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.currFnElems = fnElems;

#line 3291 "/home/alois/Documents/bah-bah/src/parser.bah"
parseLines(tokens,fnElems);

#line 3292 "/home/alois/Documents/bah-bah/src/parser.bah"
OPTI_checkFuncScopeRef(fnElems);

#line 3294 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.currFnElems = ocurrFnElems;

#line 3295 "/home/alois/Documents/bah-bah/src/parser.bah"
currentFn = null;

#line 3296 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((fn->returned==false)) {

#line 3297 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((strlen(fn->returns->type)>0), 0)) {

#line 3298 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1569 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1569[2] = "' is not returned.";____BAH_COMPILER_VAR_1569[1] = fn->name;____BAH_COMPILER_VAR_1569[0] = "Function '";char * ____BAH_COMPILER_VAR_1570 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1569, 3);throwErr(&l->data[len(l)-1],____BAH_COMPILER_VAR_1570);
}

#line 3300 "/home/alois/Documents/bah-bah/src/parser.bah"
endRCPscope(fnElems,fn->args);

#line 3301 "/home/alois/Documents/bah-bah/src/parser.bah"
fixMeEndScope(fnElems,&tokens->data[len(tokens)-1]);
}

#line 3305 "/home/alois/Documents/bah-bah/src/parser.bah"
fn->code = rope__add(fn->code, OUTPUT);

#line 3306 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = oOut;

#line 3307 "/home/alois/Documents/bah-bah/src/parser.bah"
fn->code = rope__add(fn->code, rope("};\n"));

#line 3309 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((debug==true)) {

#line 3310 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok lt = l->data[len(l)-1];

#line 3311 "/home/alois/Documents/bah-bah/src/parser.bah"
debugEndScope(lt.line,fnElems);
}

#line 3314 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope__add(OUTPUT, fn->code);
};

#line 3319 "/home/alois/Documents/bah-bah/src/parser.bah"
void parseCapture(__BAH_ARR_TYPE_Tok line,struct Elems* elems){

#line 3320 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((len(line)<7), 0)) {

#line 3321 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&line->data[0],"Invalid usage of {TOKEN} 'capture <var> = <maybe value> else {<code>}'");
}

#line 3324 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok varTok = line->data[1];

#line 3325 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok valTok = line->data[3];

#line 3326 "/home/alois/Documents/bah-bah/src/parser.bah"
char isThen = false;

#line 3328 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((varTok.type!=TOKEN_TYPE_VAR), 0)) {

#line 3329 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&varTok,"Cannot use {TOKEN} as variable.");
}

#line 3333 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((strcmp(line->data[2].cont, "=") != 0), 0)) {

#line 3334 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&line->data[2],"Expected '=' got {TOKEN}.");
}

#line 3338 "/home/alois/Documents/bah-bah/src/parser.bah"
char * valType = getTypeFromToken(&valTok,true,elems);

#line 3339 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((valType[strlen(valType)-1]!=33), 0)) {

#line 3340 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1571 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1571[2] = ") as maybe value.";____BAH_COMPILER_VAR_1571[1] = valType;____BAH_COMPILER_VAR_1571[0] = "Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_1572 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1571, 3);throwErr(&valTok,____BAH_COMPILER_VAR_1572);
}

#line 3342 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1573 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1573[1] = "*";____BAH_COMPILER_VAR_1573[0] = cpstringSubsitute(valType, 0, strlen(valType)-1);char * ____BAH_COMPILER_VAR_1574 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1573, 2);char * newType = ____BAH_COMPILER_VAR_1574;

#line 3345 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((strcmp(line->data[4].cont, "else") != 0)&&(strcmp(line->data[4].cont, "then") != 0), 0)) {

#line 3346 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&line->data[4],"Expected 'then' or 'else' got {TOKEN}.");
}

#line 3349 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(line->data[4].cont, "then") == 0)) {

#line 3350 "/home/alois/Documents/bah-bah/src/parser.bah"
isThen = true;
}

#line 3354 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* v = searchVar(varTok.cont,elems);

#line 3355 "/home/alois/Documents/bah-bah/src/parser.bah"
char * code = "";

#line 3356 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((v==null)) {

#line 3357 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* ____BAH_COMPILER_VAR_1575 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1575->name = "";
____BAH_COMPILER_VAR_1575->type = "";
____BAH_COMPILER_VAR_1575->constVal = "";
____BAH_COMPILER_VAR_1575->from = "";
____BAH_COMPILER_VAR_1575->name = varTok.cont;
____BAH_COMPILER_VAR_1575->type = newType;
v = ____BAH_COMPILER_VAR_1575;

#line 3361 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1576 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_1576);
    elems->vars->data[____BAH_COMPILER_VAR_1576] = v;

#line 3362 "/home/alois/Documents/bah-bah/src/parser.bah"

                struct string ____BAH_COMPILER_VAR_1577 = getCType(v->type,elems);
                char** ____BAH_COMPILER_VAR_1578 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1578[1] = " ";____BAH_COMPILER_VAR_1578[0] = string__str(&____BAH_COMPILER_VAR_1577);char * ____BAH_COMPILER_VAR_1579 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1578, 2);code = ____BAH_COMPILER_VAR_1579;
}

#line 3363 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 3364 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((strcmp(v->type, newType) != 0), 0)) {

#line 3365 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1580 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1580[4] = ".";____BAH_COMPILER_VAR_1580[3] = newType;____BAH_COMPILER_VAR_1580[2] = ") as ";____BAH_COMPILER_VAR_1580[1] = v->type;____BAH_COMPILER_VAR_1580[0] = "Cannot use var {TOKEN} (";char * ____BAH_COMPILER_VAR_1581 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1580, 5);throwErr(&varTok,____BAH_COMPILER_VAR_1581);
}
}

#line 3368 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1582 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1582[3] = ";";____BAH_COMPILER_VAR_1582[2] = valTok.cont;____BAH_COMPILER_VAR_1582[1] = " = ";____BAH_COMPILER_VAR_1582[0] = v->name;char * ____BAH_COMPILER_VAR_1583 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1582, 4);char** ____BAH_COMPILER_VAR_1584 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1584[1] = ____BAH_COMPILER_VAR_1583;____BAH_COMPILER_VAR_1584[0] = code;char * ____BAH_COMPILER_VAR_1585 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1584, 2);code = ____BAH_COMPILER_VAR_1585;

#line 3370 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((isThen==true)) {

#line 3371 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1586 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1586[2] = " != null) {";____BAH_COMPILER_VAR_1586[1] = v->name;____BAH_COMPILER_VAR_1586[0] = "if (";char * ____BAH_COMPILER_VAR_1587 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1586, 3);char** ____BAH_COMPILER_VAR_1588 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1588[1] = ____BAH_COMPILER_VAR_1587;____BAH_COMPILER_VAR_1588[0] = code;char * ____BAH_COMPILER_VAR_1589 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1588, 2);code = ____BAH_COMPILER_VAR_1589;
}

#line 3372 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 3373 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1590 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1590[2] = " == null) {";____BAH_COMPILER_VAR_1590[1] = v->name;____BAH_COMPILER_VAR_1590[0] = "if (";char * ____BAH_COMPILER_VAR_1591 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1590, 3);char** ____BAH_COMPILER_VAR_1592 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1592[1] = ____BAH_COMPILER_VAR_1591;____BAH_COMPILER_VAR_1592[0] = code;char * ____BAH_COMPILER_VAR_1593 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1592, 2);code = ____BAH_COMPILER_VAR_1593;
}

#line 3376 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope__add(OUTPUT, rope(code));

#line 3378 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct Tok)* tokens = arraySubstitute(line, 6, len(line)-1);

#line 3380 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Elems* CaptElems = dupElems(elems);

#line 3382 "/home/alois/Documents/bah-bah/src/parser.bah"
parseLines(tokens,CaptElems);

#line 3384 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((isThen==true)) {

#line 3385 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope__add(OUTPUT, rope("}\n"));
}

#line 3386 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 3387 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1594 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1594[4] = "\");}\n";____BAH_COMPILER_VAR_1594[3] = intToStr(line->data[0].line);____BAH_COMPILER_VAR_1594[2] = ":";____BAH_COMPILER_VAR_1594[1] = compilerState.currentFile;____BAH_COMPILER_VAR_1594[0] = "\n__BAH_panic(\"Undefined capture resolution.\", \"";char * ____BAH_COMPILER_VAR_1595 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1594, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1595));
}
};

#line 3393 "/home/alois/Documents/bah-bah/src/parser.bah"
void parseLine(__BAH_ARR_TYPE_Tok line,struct Elems* elems){

#line 3395 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((len(line)==0)) {

#line 3396 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}

#line 3399 "/home/alois/Documents/bah-bah/src/parser.bah"
clear(currChecks);

#line 3401 "/home/alois/Documents/bah-bah/src/parser.bah"
line = parsePointers(line,elems);

#line 3402 "/home/alois/Documents/bah-bah/src/parser.bah"
lineType ltp = getLineType(line);

#line 3404 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.RCPvars = memoryAlloc(sizeof(array(struct variable*)));

compilerState.RCPvars->length = 0;
compilerState.RCPvars->elemSize = sizeof(struct variable*);

#line 3405 "/home/alois/Documents/bah-bah/src/parser.bah"
currSetVar = null;

#line 3407 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((ltp==LINE_TYPE_VAR)&&(len(line)>1)) {

#line 3408 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok ft = line->data[0];

#line 3409 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok st = line->data[1];

#line 3410 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(st.cont, "=") == 0)) {

#line 3411 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* v = searchVar(ft.cont,elems);

#line 3412 "/home/alois/Documents/bah-bah/src/parser.bah"
currSetVar = v;
}
}

#line 3416 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1596 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1596[4] = "\"\n";____BAH_COMPILER_VAR_1596[3] = compilerState.currentFile;____BAH_COMPILER_VAR_1596[2] = " \"";____BAH_COMPILER_VAR_1596[1] = intToStr(line->data[0].line);____BAH_COMPILER_VAR_1596[0] = "\n#line ";char * ____BAH_COMPILER_VAR_1597 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1596, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1597));

#line 3418 "/home/alois/Documents/bah-bah/src/parser.bah"
char parsed = false;

#line 3419 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((ltp==LINE_TYPE_INCLUDE)) {

#line 3420 "/home/alois/Documents/bah-bah/src/parser.bah"
parsed = true;

#line 3421 "/home/alois/Documents/bah-bah/src/parser.bah"
parseInclude(line,elems);
}

#line 3422 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((ltp==LINE_TYPE_IMPORT)) {

#line 3423 "/home/alois/Documents/bah-bah/src/parser.bah"
parsed = true;

#line 3424 "/home/alois/Documents/bah-bah/src/parser.bah"
parseImport(line,elems);
}

#line 3425 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((ltp==LINE_TYPE_DEFINE)) {

#line 3426 "/home/alois/Documents/bah-bah/src/parser.bah"
parsed = true;

#line 3427 "/home/alois/Documents/bah-bah/src/parser.bah"
parseDefine(line,elems);
}

#line 3428 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((ltp==LINE_TYPE_CLIB)) {

#line 3429 "/home/alois/Documents/bah-bah/src/parser.bah"
parsed = true;

#line 3430 "/home/alois/Documents/bah-bah/src/parser.bah"
parseClib(line);
}

#line 3431 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((ltp==LINE_TYPE_STRUCT)) {

#line 3432 "/home/alois/Documents/bah-bah/src/parser.bah"
parsed = true;

#line 3433 "/home/alois/Documents/bah-bah/src/parser.bah"
parseStruct(line,elems);
}

#line 3434 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((ltp==LINE_TYPE_CONST)) {

#line 3435 "/home/alois/Documents/bah-bah/src/parser.bah"
parsed = true;

#line 3436 "/home/alois/Documents/bah-bah/src/parser.bah"
parseConst(line,elems);
}

#line 3437 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((ltp==LINE_TYPE_MACRO)) {

#line 3438 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}

#line 3439 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((ltp!=LINE_TYPE_FN_DECL)) {

#line 3440 "/home/alois/Documents/bah-bah/src/parser.bah"
line = prePross(line,ltp,elems);

#line 3441 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((len(line)==0)) {

#line 3442 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}
}

#line 3446 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok ft = line->data[0];

#line 3447 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((ft.isOper==false)&&(ft.isFunc==true)) {

#line 3448 "/home/alois/Documents/bah-bah/src/parser.bah"
struct func* fn = searchFuncByToken(&ft,elems);

#line 3449 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((fn!=null)&&(fn->returns!=null)&&isRCPtype(fn->returns->type,elems)) {

#line 3450 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ____BAH_COMPILER_VAR_1598 =registerRCPvar(fn->returns->type,ft.cont,elems);
#line 3451 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}
}

#line 3455 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((ltp==LINE_TYPE_VAR)) {

#line 3456 "/home/alois/Documents/bah-bah/src/parser.bah"
parsed = true;

#line 3457 "/home/alois/Documents/bah-bah/src/parser.bah"
parseVar(line,elems);
}

#line 3458 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((ltp==LINE_TYPE_FN_CALL)) {

#line 3459 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((len(line)>1), 0)) {

#line 3460 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&line->data[len(line)-1],"Not expecting {TOKEN} after function call.");
}

#line 3462 "/home/alois/Documents/bah-bah/src/parser.bah"
parsed = true;

#line 3463 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1599 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1599[1] = ";\n";____BAH_COMPILER_VAR_1599[0] = ft.cont;char * ____BAH_COMPILER_VAR_1600 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1599, 2);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1600));
}

#line 3464 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((ltp==LINE_TYPE_FN_DECL)) {

#line 3465 "/home/alois/Documents/bah-bah/src/parser.bah"
parsed = true;

#line 3466 "/home/alois/Documents/bah-bah/src/parser.bah"
parseFnDeclare(line,elems);
}

#line 3467 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((ltp==LINE_TYPE_RETURN)) {

#line 3468 "/home/alois/Documents/bah-bah/src/parser.bah"
parsed = true;

#line 3469 "/home/alois/Documents/bah-bah/src/parser.bah"
parseReturn(line,elems);
}

#line 3470 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((ltp==LINE_TYPE_IF)) {

#line 3471 "/home/alois/Documents/bah-bah/src/parser.bah"
parsed = true;

#line 3472 "/home/alois/Documents/bah-bah/src/parser.bah"
parseIf(line,false,elems);
}

#line 3473 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((ltp==LINE_TYPE_ELSE)) {

#line 3474 "/home/alois/Documents/bah-bah/src/parser.bah"
parsed = true;

#line 3475 "/home/alois/Documents/bah-bah/src/parser.bah"
parseElse(line,elems);
}

#line 3476 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((ltp==LINE_TYPE_FOR)) {

#line 3477 "/home/alois/Documents/bah-bah/src/parser.bah"
parsed = true;

#line 3478 "/home/alois/Documents/bah-bah/src/parser.bah"
parseFor(line,elems);
}

#line 3479 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((ltp==LINE_TYPE_FOR_OPERATOR)) {

#line 3480 "/home/alois/Documents/bah-bah/src/parser.bah"
parsed = true;

#line 3481 "/home/alois/Documents/bah-bah/src/parser.bah"
parseForOp(line,elems);
}

#line 3482 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((ltp==LINE_TYPE_PRE_KEYWORD)) {

#line 3483 "/home/alois/Documents/bah-bah/src/parser.bah"
parsePreKeyword(line,elems);

#line 3484 "/home/alois/Documents/bah-bah/src/parser.bah"
parsed = true;
}

#line 3485 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((ltp==LINE_TYPE_ASYNC)) {

#line 3486 "/home/alois/Documents/bah-bah/src/parser.bah"
parseAsync(line,elems);

#line 3487 "/home/alois/Documents/bah-bah/src/parser.bah"
parsed = true;
}

#line 3488 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((ltp==LINE_TYPE_CAPTURE)) {

#line 3489 "/home/alois/Documents/bah-bah/src/parser.bah"
parseCapture(line,elems);

#line 3490 "/home/alois/Documents/bah-bah/src/parser.bah"
parsed = true;
}

#line 3493 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((parsed==false), 0)) {

#line 3494 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&ft,"{TOKEN} not expected.");
}

#line 3497 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strlen(NEXT_LINE)>0)) {

#line 3498 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope__add(OUTPUT, rope(NEXT_LINE));

#line 3499 "/home/alois/Documents/bah-bah/src/parser.bah"
NEXT_LINE = "";
}

#line 3501 "/home/alois/Documents/bah-bah/src/parser.bah"
prevLine = ltp;
};

#line 3506 "/home/alois/Documents/bah-bah/src/parser.bah"
void parseLines(__BAH_ARR_TYPE_Tok tokens,struct Elems* elems){

#line 3508 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((len(tokens)==0)) {

#line 3509 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}

#line 3511 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct Tok)* line = memoryAlloc(sizeof(array(struct Tok)));

line->length = 0;
line->elemSize = sizeof(struct Tok);

#line 3512 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok ft = tokens->data[0];

#line 3513 "/home/alois/Documents/bah-bah/src/parser.bah"
unsigned int currentLine = ft.line;

#line 3514 "/home/alois/Documents/bah-bah/src/parser.bah"
long int nbEncl = 0;

#line 3515 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int i = 0;

#line 3515 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i<len(tokens))) {

#line 3516 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = tokens->data[i];

#line 3518 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((t.type==TOKEN_TYPE_ENCL)) {

#line 3519 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "(") == 0)) {

#line 3520 "/home/alois/Documents/bah-bah/src/parser.bah"
nbEncl = nbEncl+1;
}

#line 3521 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(t.cont, ")") == 0)) {

#line 3522 "/home/alois/Documents/bah-bah/src/parser.bah"
nbEncl = nbEncl-1;
}

#line 3523 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(t.cont, "{") == 0)) {

#line 3524 "/home/alois/Documents/bah-bah/src/parser.bah"
nbEncl = nbEncl+1;
}

#line 3525 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(t.cont, "}") == 0)) {

#line 3526 "/home/alois/Documents/bah-bah/src/parser.bah"
nbEncl = nbEncl-1;
}

#line 3527 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(t.cont, "[") == 0)) {

#line 3528 "/home/alois/Documents/bah-bah/src/parser.bah"
nbEncl = nbEncl+1;
}

#line 3529 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(t.cont, "]") == 0)) {

#line 3530 "/home/alois/Documents/bah-bah/src/parser.bah"
nbEncl = nbEncl-1;
}
}

#line 3534 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((t.type==TOKEN_TYPE_STR)&&(t.begLine==currentLine)) {

#line 3535 "/home/alois/Documents/bah-bah/src/parser.bah"
currentLine = t.line;
}

#line 3538 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((nbEncl==0)) {

#line 3539 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((t.line!=currentLine)) {

#line 3540 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((t.type==TOKEN_TYPE_ENCL)) {

#line 3541 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1601 = len(line);
    __Bah_realocate_arr(line, ____BAH_COMPILER_VAR_1601);
    line->data[____BAH_COMPILER_VAR_1601] = t;

#line 3542 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok pt = tokens->data[i-1];

#line 3543 "/home/alois/Documents/bah-bah/src/parser.bah"
currentLine = pt.line;
}

#line 3544 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 3545 "/home/alois/Documents/bah-bah/src/parser.bah"
currentLine = t.line;
}

#line 3547 "/home/alois/Documents/bah-bah/src/parser.bah"
parseLine(line,elems);

#line 3548 "/home/alois/Documents/bah-bah/src/parser.bah"
clear(line);

#line 3549 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((t.type==TOKEN_TYPE_ENCL)) {

#line 3550 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 3551 "/home/alois/Documents/bah-bah/src/parser.bah"
continue;
}
}

#line 3553 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(t.cont, ";") == 0)) {

#line 3554 "/home/alois/Documents/bah-bah/src/parser.bah"
currentLine = t.line;

#line 3555 "/home/alois/Documents/bah-bah/src/parser.bah"
parseLine(line,elems);

#line 3556 "/home/alois/Documents/bah-bah/src/parser.bah"
clear(line);

#line 3557 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 3558 "/home/alois/Documents/bah-bah/src/parser.bah"
continue;
}
}

#line 3562 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1602 = len(line);
    __Bah_realocate_arr(line, ____BAH_COMPILER_VAR_1602);
    line->data[____BAH_COMPILER_VAR_1602] = t;

#line 3563 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;
};

#line 3566 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((len(line)>0)) {

#line 3567 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((nbEncl==0)) {

#line 3568 "/home/alois/Documents/bah-bah/src/parser.bah"
parseLine(line,elems);

#line 3569 "/home/alois/Documents/bah-bah/src/parser.bah"
clear(line);
}

#line 3570 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 3571 "/home/alois/Documents/bah-bah/src/parser.bah"
ft = line->data[len(line)-1];

#line 3572 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&ft,"Missing closing token, line ending by {TOKEN}.");
}
}
};

#line 47 "/home/alois/Documents/bah-bah/src/main.bah"

#line 2 "/home/alois/Documents/bah-bah/src/declarative.bah"
void declareFunc(struct func* fn,struct Elems* elems){

#line 3 "/home/alois/Documents/bah-bah/src/declarative.bah"
struct string tmpfnRetCType = getCType(fn->returns->type,elems);

#line 4 "/home/alois/Documents/bah-bah/src/declarative.bah"
char * tmpfnArgsCType = "";

#line 5 "/home/alois/Documents/bah-bah/src/declarative.bah"
register long int j = 0;

#line 5 "/home/alois/Documents/bah-bah/src/declarative.bah"
while ((j<len(fn->args))) {

#line 6 "/home/alois/Documents/bah-bah/src/declarative.bah"
struct variable* arg = fn->args->data[j];

#line 7 "/home/alois/Documents/bah-bah/src/declarative.bah"
struct string ct = getCType(arg->type,elems);

#line 8 "/home/alois/Documents/bah-bah/src/declarative.bah"
char** ____BAH_COMPILER_VAR_1603 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1603[3] = arg->name;____BAH_COMPILER_VAR_1603[2] = " ";____BAH_COMPILER_VAR_1603[1] = string__str(&ct);____BAH_COMPILER_VAR_1603[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_1604 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1603, 4);tmpfnArgsCType = ____BAH_COMPILER_VAR_1604;

#line 9 "/home/alois/Documents/bah-bah/src/declarative.bah"
j = j+1;

#line 10 "/home/alois/Documents/bah-bah/src/declarative.bah"
if ((j<len(fn->args))) {

#line 11 "/home/alois/Documents/bah-bah/src/declarative.bah"
char** ____BAH_COMPILER_VAR_1605 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1605[1] = ", ";____BAH_COMPILER_VAR_1605[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_1606 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1605, 2);tmpfnArgsCType = ____BAH_COMPILER_VAR_1606;
}
};

#line 15 "/home/alois/Documents/bah-bah/src/declarative.bah"
char** ____BAH_COMPILER_VAR_1607 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_1607[5] = ");\n";____BAH_COMPILER_VAR_1607[4] = tmpfnArgsCType;____BAH_COMPILER_VAR_1607[3] = "(";____BAH_COMPILER_VAR_1607[2] = fn->name;____BAH_COMPILER_VAR_1607[1] = " ";____BAH_COMPILER_VAR_1607[0] = string__str(&tmpfnRetCType);char * ____BAH_COMPILER_VAR_1608 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1607, 6);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1608));
};

#line 18 "/home/alois/Documents/bah-bah/src/declarative.bah"
void declareVar(struct variable* v,struct Elems* elems){

#line 19 "/home/alois/Documents/bah-bah/src/declarative.bah"
if ((v->isConst==true)) {

#line 20 "/home/alois/Documents/bah-bah/src/declarative.bah"
char** ____BAH_COMPILER_VAR_1609 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1609[4] = "\n";____BAH_COMPILER_VAR_1609[3] = v->constVal;____BAH_COMPILER_VAR_1609[2] = " ";____BAH_COMPILER_VAR_1609[1] = v->name;____BAH_COMPILER_VAR_1609[0] = "#define ";char * ____BAH_COMPILER_VAR_1610 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1609, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1610));
}

#line 21 "/home/alois/Documents/bah-bah/src/declarative.bah"
else {

#line 22 "/home/alois/Documents/bah-bah/src/declarative.bah"
struct string cType = getCType(v->type,elems);

#line 23 "/home/alois/Documents/bah-bah/src/declarative.bah"
char** ____BAH_COMPILER_VAR_1611 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1611[3] = ";\n";____BAH_COMPILER_VAR_1611[2] = v->name;____BAH_COMPILER_VAR_1611[1] = " ";____BAH_COMPILER_VAR_1611[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_1612 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1611, 4);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1612));
}
};

#line 27 "/home/alois/Documents/bah-bah/src/declarative.bah"
void declareAll(struct Elems* elems){

#line 29 "/home/alois/Documents/bah-bah/src/declarative.bah"
OUTPUT = rope("\n#define noCheck(v) v\n#define array(type)	\
struct{	\
type *data; \
long int length; \
long int elemSize; \
}\ntypedef array(char*)* __BAH_ARR_TYPE_cpstring;\nlong int __BAH__main(__BAH_ARR_TYPE_cpstring);\n");

#line 41 "/home/alois/Documents/bah-bah/src/declarative.bah"
register long int i = 0;

#line 41 "/home/alois/Documents/bah-bah/src/declarative.bah"
for (; (i<len(compilerState.cIncludes)); 
#line 41 "/home/alois/Documents/bah-bah/src/declarative.bah"
++i) {

#line 42 "/home/alois/Documents/bah-bah/src/declarative.bah"
char** ____BAH_COMPILER_VAR_1613 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1613[2] = "\n";____BAH_COMPILER_VAR_1613[1] = compilerState.cIncludes->data[i];____BAH_COMPILER_VAR_1613[0] = "#include ";char * ____BAH_COMPILER_VAR_1614 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1613, 3);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1614));
};

#line 45 "/home/alois/Documents/bah-bah/src/declarative.bah"
i = 1;

#line 45 "/home/alois/Documents/bah-bah/src/declarative.bah"
for (; (i<len(compilerState.arrTypesDecl)); 
#line 45 "/home/alois/Documents/bah-bah/src/declarative.bah"
++i) {

#line 46 "/home/alois/Documents/bah-bah/src/declarative.bah"
char * t = compilerState.arrTypesDecl->data[i];

#line 47 "/home/alois/Documents/bah-bah/src/declarative.bah"
struct string elemType = string(t);

#line 48 "/home/alois/Documents/bah-bah/src/declarative.bah"
string__trimLeft(&elemType,15);

#line 49 "/home/alois/Documents/bah-bah/src/declarative.bah"
char * ____BAH_COMPILER_VAR_1615 =string__str(&elemType);struct string elemCtype = getCType(____BAH_COMPILER_VAR_1615,elems);

#line 50 "/home/alois/Documents/bah-bah/src/declarative.bah"
char** ____BAH_COMPILER_VAR_1616 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1616[4] = ";\n";____BAH_COMPILER_VAR_1616[3] = t;____BAH_COMPILER_VAR_1616[2] = ")* ";____BAH_COMPILER_VAR_1616[1] = string__str(&elemCtype);____BAH_COMPILER_VAR_1616[0] = "typedef array(";char * ____BAH_COMPILER_VAR_1617 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1616, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1617));
};

#line 53 "/home/alois/Documents/bah-bah/src/declarative.bah"
i = 0;

#line 53 "/home/alois/Documents/bah-bah/src/declarative.bah"
for (; (i<len(elems->vars)); 
#line 53 "/home/alois/Documents/bah-bah/src/declarative.bah"
++i) {

#line 54 "/home/alois/Documents/bah-bah/src/declarative.bah"
struct variable* v = elems->vars->data[i];

#line 55 "/home/alois/Documents/bah-bah/src/declarative.bah"
declareVar(v,elems);
};

#line 58 "/home/alois/Documents/bah-bah/src/declarative.bah"
i = 0;

#line 58 "/home/alois/Documents/bah-bah/src/declarative.bah"
for (; (i<len(elems->fns)); 
#line 58 "/home/alois/Documents/bah-bah/src/declarative.bah"
++i) {

#line 59 "/home/alois/Documents/bah-bah/src/declarative.bah"
struct func* fn = elems->fns->data[i];

#line 60 "/home/alois/Documents/bah-bah/src/declarative.bah"
if ((fn->isBinding==true)) {

#line 61 "/home/alois/Documents/bah-bah/src/declarative.bah"
continue;
}

#line 63 "/home/alois/Documents/bah-bah/src/declarative.bah"
declareFunc(fn,elems);
};
};

#line 50 "/home/alois/Documents/bah-bah/src/main.bah"
char * memErrHandle(){

#line 51 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1618 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1618[1] = compilerState.currentFile;____BAH_COMPILER_VAR_1618[0] = "file: ";char * ____BAH_COMPILER_VAR_1619 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1618, 2);char * r = ____BAH_COMPILER_VAR_1619;

#line 52 "/home/alois/Documents/bah-bah/src/main.bah"
if ((currentFn!=null)) {

#line 53 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1620 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1620[2] = "()";____BAH_COMPILER_VAR_1620[1] = currentFn->name;____BAH_COMPILER_VAR_1620[0] = "\nfunction: ";char * ____BAH_COMPILER_VAR_1621 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1620, 3);char** ____BAH_COMPILER_VAR_1622 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1622[1] = ____BAH_COMPILER_VAR_1621;____BAH_COMPILER_VAR_1622[0] = r;char * ____BAH_COMPILER_VAR_1623 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1622, 2);r = ____BAH_COMPILER_VAR_1623;
}

#line 55 "/home/alois/Documents/bah-bah/src/main.bah"
return r;
};

#line 58 "/home/alois/Documents/bah-bah/src/main.bah"
long int main(__BAH_ARR_TYPE_cpstring args){

#line 61 "/home/alois/Documents/bah-bah/src/main.bah"
onMemoryError = memErrHandle;

#line 63 "/home/alois/Documents/bah-bah/src/main.bah"
execName = args->data[0];

#line 65 "/home/alois/Documents/bah-bah/src/main.bah"
if ((execName[0]==46)||(execName[0]==47)) {

#line 66 "/home/alois/Documents/bah-bah/src/main.bah"
execName = absPath(execName);
}

#line 69 "/home/alois/Documents/bah-bah/src/main.bah"
struct flags ____BAH_COMPILER_VAR_1624 = {};
____BAH_COMPILER_VAR_1624.flags = memoryAlloc(sizeof(array(struct flag*)));
            ____BAH_COMPILER_VAR_1624.flags->length = 0;
            ____BAH_COMPILER_VAR_1624.flags->elemSize = sizeof(struct flag*);
            ____BAH_COMPILER_VAR_1624.args = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_1624.args->length = 0;
            ____BAH_COMPILER_VAR_1624.args->elemSize = sizeof(char *);
            flags = ____BAH_COMPILER_VAR_1624;

#line 70 "/home/alois/Documents/bah-bah/src/main.bah"
flags__addString(&flags,"o","Name of the file to output.");

#line 71 "/home/alois/Documents/bah-bah/src/main.bah"
flags__addBool(&flags,"c","Translate bah file to C instead of compiling it.");

#line 72 "/home/alois/Documents/bah-bah/src/main.bah"
flags__addBool(&flags,"v","Show version of the compiler.");

#line 73 "/home/alois/Documents/bah-bah/src/main.bah"
flags__addBool(&flags,"l","Compile as a library.");

#line 74 "/home/alois/Documents/bah-bah/src/main.bah"

#line 75 "/home/alois/Documents/bah-bah/src/main.bah"
flags__addBool(&flags,"d","Compile as a dynamic executable. (useful if you are using a library that is only available shared but might reduce portability).");

#line 77 "/home/alois/Documents/bah-bah/src/main.bah"

#line 80 "/home/alois/Documents/bah-bah/src/main.bah"
flags__addBool(&flags,"rcp","Enables RCP (reference counter) instead of the garbage collector. Warning: if you are using self-reference, this will lead to memory leaks!");

#line 81 "/home/alois/Documents/bah-bah/src/main.bah"
flags__addBool(&flags,"fastrcp","Enables RCP without leak detection. It is recommended to test you programs with the -rcp flag to test for leak detection before using this flag.");

#line 82 "/home/alois/Documents/bah-bah/src/main.bah"
flags__addBool(&flags,"debug","Enables verbose json output.");

#line 83 "/home/alois/Documents/bah-bah/src/main.bah"
flags__addBool(&flags,"verboseRuntime","Enables verbose runtime, a debug mode of the compiled program. (obsolete)");

#line 84 "/home/alois/Documents/bah-bah/src/main.bah"
flags__addBool(&flags,"verboseCC","Enables verbose C compiler output, USE IN LAST RESORT.");

#line 87 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1625 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1625[2] = ".";____BAH_COMPILER_VAR_1625[1] = BAH_OS;____BAH_COMPILER_VAR_1625[0] = "Select the target OS for cross compilling (linux, windows, darwin), default: ";char * ____BAH_COMPILER_VAR_1626 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1625, 3);flags__addString(&flags,"target",____BAH_COMPILER_VAR_1626);

#line 88 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1627 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1627[2] = ").";____BAH_COMPILER_VAR_1627[1] = BAH_DIR;____BAH_COMPILER_VAR_1627[0] = "If your Bah directory is not the default one (";char * ____BAH_COMPILER_VAR_1628 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1627, 3);flags__addString(&flags,"bahDir",____BAH_COMPILER_VAR_1628);

#line 89 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1629 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1629[2] = ".";____BAH_COMPILER_VAR_1629[1] = BAH_CC;____BAH_COMPILER_VAR_1629[0] = "To change the C compiler used, default: ";char * ____BAH_COMPILER_VAR_1630 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1629, 3);flags__addString(&flags,"CC",____BAH_COMPILER_VAR_1630);

#line 90 "/home/alois/Documents/bah-bah/src/main.bah"
flags__addBool(&flags,"object","Compile as an object.");

#line 91 "/home/alois/Documents/bah-bah/src/main.bah"
flags__addBool(&flags,"unsafe","Compile without safety checking. This will make for faster executable but if your program crashes, it will show less informations.");

#line 92 "/home/alois/Documents/bah-bah/src/main.bah"
flags__addBool(&flags,"nobuiltin","Does not include the builtin library (be really carefull, your program WILL break).");

#line 93 "/home/alois/Documents/bah-bah/src/main.bah"
flags__addBool(&flags,"optimize","Includes optimized functions");

#line 94 "/home/alois/Documents/bah-bah/src/main.bah"
flags__addBool(&flags,"n","Disables notices while keeping warnings enabled.");

#line 95 "/home/alois/Documents/bah-bah/src/main.bah"
flags__addBool(&flags,"raii","Enables RAII memory management.");

#line 96 "/home/alois/Documents/bah-bah/src/main.bah"
flags__addBool(&flags,"fixMe","Enables runtime debugging engine, useful for segfaults... Note that your program will be slower and use more memory, this is only a debug option.");

#line 97 "/home/alois/Documents/bah-bah/src/main.bah"
flags__parse(&flags,args);

#line 99 "/home/alois/Documents/bah-bah/src/main.bah"
RAIIenabled = (flags__isSet(&flags,"raii")==1);

#line 100 "/home/alois/Documents/bah-bah/src/main.bah"
isFixMeEnabled = (flags__isSet(&flags,"fixMe")==1);

#line 102 "/home/alois/Documents/bah-bah/src/main.bah"
if ((RAIIenabled==true)) {

#line 103 "/home/alois/Documents/bah-bah/src/main.bah"
println("RAII is not yet available...");

#line 104 "/home/alois/Documents/bah-bah/src/main.bah"
return 1;
}

#line 107 "/home/alois/Documents/bah-bah/src/main.bah"
if ((flags__isSet(&flags,"target")==1)) {

#line 108 "/home/alois/Documents/bah-bah/src/main.bah"
BAH_OS = flags__get(&flags,"target");

#line 109 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1631 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1631[1] = BAH_OS;____BAH_COMPILER_VAR_1631[0] = "Build target: ";char * ____BAH_COMPILER_VAR_1632 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1631, 2);println(____BAH_COMPILER_VAR_1632);
}

#line 111 "/home/alois/Documents/bah-bah/src/main.bah"
if ((flags__isSet(&flags,"bahDir")==1)) {

#line 112 "/home/alois/Documents/bah-bah/src/main.bah"
BAH_DIR = flags__get(&flags,"bahDir");

#line 113 "/home/alois/Documents/bah-bah/src/main.bah"
array(char)* bahDirArr = strAsArr(BAH_DIR);

#line 114 "/home/alois/Documents/bah-bah/src/main.bah"
if ((bahDirArr->data[len(bahDirArr)-1]!=47)) {

#line 115 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1633 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1633[1] = "/";____BAH_COMPILER_VAR_1633[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_1634 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1633, 2);BAH_DIR = ____BAH_COMPILER_VAR_1634;
}

#line 117 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1635 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1635[1] = BAH_DIR;____BAH_COMPILER_VAR_1635[0] = "Bah directory: ";char * ____BAH_COMPILER_VAR_1636 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1635, 2);println(____BAH_COMPILER_VAR_1636);
}

#line 119 "/home/alois/Documents/bah-bah/src/main.bah"
if ((flags__isSet(&flags,"CC")==1)) {

#line 120 "/home/alois/Documents/bah-bah/src/main.bah"
BAH_CC = flags__get(&flags,"CC");

#line 121 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1637 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1637[1] = BAH_CC;____BAH_COMPILER_VAR_1637[0] = "C compiler: ";char * ____BAH_COMPILER_VAR_1638 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1637, 2);println(____BAH_COMPILER_VAR_1638);
}

#line 124 "/home/alois/Documents/bah-bah/src/main.bah"
if (__builtin_expect(flags__isSet(&flags,"verboseRuntime"), 0)) {

#line 125 "/home/alois/Documents/bah-bah/src/main.bah"
println("-verboseRuntime is obsolete.");

#line 126 "/home/alois/Documents/bah-bah/src/main.bah"
exit(1);
}

#line 129 "/home/alois/Documents/bah-bah/src/main.bah"
noticeEnabled = (flags__isSet(&flags,"n")==0);

#line 131 "/home/alois/Documents/bah-bah/src/main.bah"
RCPlevel = 0;

#line 132 "/home/alois/Documents/bah-bah/src/main.bah"
if (flags__isSet(&flags,"rcp")) {

#line 133 "/home/alois/Documents/bah-bah/src/main.bah"
RCPlevel = 1;
}

#line 134 "/home/alois/Documents/bah-bah/src/main.bah"
else if (flags__isSet(&flags,"fastrcp")) {

#line 135 "/home/alois/Documents/bah-bah/src/main.bah"
RCPlevel = 2;
}

#line 138 "/home/alois/Documents/bah-bah/src/main.bah"
verboseRuntime = (flags__isSet(&flags,"verboseRuntime")==1);

#line 139 "/home/alois/Documents/bah-bah/src/main.bah"
debug = (flags__isSet(&flags,"debug")==1);

#line 140 "/home/alois/Documents/bah-bah/src/main.bah"
isObject = (flags__isSet(&flags,"object")==1);

#line 141 "/home/alois/Documents/bah-bah/src/main.bah"
isUnsafe = (flags__isSet(&flags,"unsafe")==1);

#line 142 "/home/alois/Documents/bah-bah/src/main.bah"
isOptimized = (flags__isSet(&flags,"optimize")==1);

#line 144 "/home/alois/Documents/bah-bah/src/main.bah"
if ((debug==true)) {

#line 145 "/home/alois/Documents/bah-bah/src/main.bah"
debugStart();
}

#line 148 "/home/alois/Documents/bah-bah/src/main.bah"
RCPenabled = (flags__isSet(&flags,"rcp")==1)||flags__isSet(&flags,"fastrcp");

#line 150 "/home/alois/Documents/bah-bah/src/main.bah"
if ((flags__isSet(&flags,"v")==1)) {

#line 151 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1639 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1639[2] = ".\n© Alois Laurent Boe";____BAH_COMPILER_VAR_1639[1] = BAH_VERSION;____BAH_COMPILER_VAR_1639[0] = "Bah compiler version: ";char * ____BAH_COMPILER_VAR_1640 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1639, 3);println(____BAH_COMPILER_VAR_1640);

#line 152 "/home/alois/Documents/bah-bah/src/main.bah"
return 0;
}

#line 155 "/home/alois/Documents/bah-bah/src/main.bah"
if (__builtin_expect((flags__isSet(&flags,"c")==1)&&(flags__isSet(&flags,"l")==1), 0)) {

#line 156 "/home/alois/Documents/bah-bah/src/main.bah"
__BAH_panic("Cannot use -c (to translate to C code) and -l (to compile as a library) at the same time.","/home/alois/Documents/bah-bah/src/main.bah:156");
}

#line 159 "/home/alois/Documents/bah-bah/src/main.bah"
INIT = rope("");

#line 162 "/home/alois/Documents/bah-bah/src/main.bah"
OUTPUT = rope("\n    void __BAH_init();\n    #define noCheck(v) v\n    #define array(type)	\
    struct{	\
    type *data; \
    long int length; \
    long int realLength; \
    long int elemSize; \
    }\n    typedef array(char*)* __BAH_ARR_TYPE_cpstring;\n    long int __BAH__main(__BAH_ARR_TYPE_cpstring);\n    ");

#line 176 "/home/alois/Documents/bah-bah/src/main.bah"
if ((flags__isSet(&flags,"l")==0)) {

#line 177 "/home/alois/Documents/bah-bah/src/main.bah"
if ((RCPenabled==true)) {

#line 178 "/home/alois/Documents/bah-bah/src/main.bah"
OUTPUT = rope__add(OUTPUT, rope("\n            void RCP_init();\n            void RCP_shutdown();\n            void free(void*);\n            #include <string.h>\n            int main(int argc, char ** argv) {\n            RCP_init();\n            array(char*) * args = malloc(sizeof(array(char*)));\n            args->data = malloc(sizeof(char*)*argc);\n            memcpy(args->data, argv, sizeof(char*)*argc);\n            args->elemSize = sizeof(char*);\n            args->length = argc;\n            __BAH_init();\n            long int r =  __BAH__main((__BAH_ARR_TYPE_cpstring)args);\n            free(args->data);\n            free(args);\n            RCP_shutdown();\n            return r;\n            };\n            #define main(v) __BAH__main(v)\n            "));
}

#line 200 "/home/alois/Documents/bah-bah/src/main.bah"
else if ((RAIIenabled==true)) {

#line 201 "/home/alois/Documents/bah-bah/src/main.bah"
OUTPUT = rope__add(OUTPUT, rope("\n            #include <string.h>\n            int main(int argc, char ** argv) {\n            array(char*) * args = malloc(sizeof(array(char*)));\n            args->data = malloc(sizeof(char*)*argc);\n            memcpy(args->data, argv, sizeof(char*)*argc);\n            args->elemSize = sizeof(char*);\n            args->length = argc;\n            __BAH_init();\n            long int r =  __BAH__main((__BAH_ARR_TYPE_cpstring)args);\n            free(args->data);\n            free(args);\n            return r;\n            };\n            #define main(v) __BAH__main(v)\n            "));
}

#line 217 "/home/alois/Documents/bah-bah/src/main.bah"
else {

#line 218 "/home/alois/Documents/bah-bah/src/main.bah"
OUTPUT = rope__add(OUTPUT, rope("\n            #include <gc.h>\n            #include <string.h>\n            int main(int argc, char ** argv) {\n            GC_INIT();\n            array(char*) * args = GC_MALLOC(sizeof(array(char*)));\n            args->data = GC_MALLOC(sizeof(char*)*argc);\n            memcpy(args->data, argv, sizeof(char*)*argc);\n            args->elemSize = sizeof(char*);\n            args->length = argc;\n            __BAH_init();\n            long int r =  __BAH__main((__BAH_ARR_TYPE_cpstring)args);\n            GC_FREE(args->data);\n            GC_FREE(args);\n            return r;\n            };\n            #define main(v) __BAH__main(v)\n            "));
}
}

#line 240 "/home/alois/Documents/bah-bah/src/main.bah"
struct compilerStateTag ____BAH_COMPILER_VAR_1641 = {};
____BAH_COMPILER_VAR_1641.includes = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_1641.includes->length = 0;
            ____BAH_COMPILER_VAR_1641.includes->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_1641.cIncludes = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_1641.cIncludes->length = 0;
            ____BAH_COMPILER_VAR_1641.cIncludes->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_1641.cLibs = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_1641.cLibs->length = 0;
            ____BAH_COMPILER_VAR_1641.cLibs->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_1641.currentDir = "./";
____BAH_COMPILER_VAR_1641.arrTypesDecl = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_1641.arrTypesDecl->length = 0;
            ____BAH_COMPILER_VAR_1641.arrTypesDecl->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_1641.RCPvars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_1641.RCPvars->length = 0;
            ____BAH_COMPILER_VAR_1641.RCPvars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_1641.evals = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_1641.evals->length = 0;
            ____BAH_COMPILER_VAR_1641.evals->elemSize = sizeof(char *);
            compilerState = ____BAH_COMPILER_VAR_1641;

#line 241 "/home/alois/Documents/bah-bah/src/main.bah"

    unsigned int ____BAH_COMPILER_VAR_1642 = 0;
    __Bah_realocate_arr(compilerState.arrTypesDecl, ____BAH_COMPILER_VAR_1642);
    compilerState.arrTypesDecl->data[____BAH_COMPILER_VAR_1642] = "__BAH_ARR_TYPE_cpstring";

#line 244 "/home/alois/Documents/bah-bah/src/main.bah"
char * fileName = absPath(args->data[1]);

#line 245 "/home/alois/Documents/bah-bah/src/main.bah"
compilerState.currentFile = fileName;

#line 246 "/home/alois/Documents/bah-bah/src/main.bah"
struct fileMap ____BAH_COMPILER_VAR_1643 = {};
____BAH_COMPILER_VAR_1643.handle = -1;
struct fileMap fm = ____BAH_COMPILER_VAR_1643;

#line 247 "/home/alois/Documents/bah-bah/src/main.bah"
char * f = fileMap__open(&fm,fileName);

#line 248 "/home/alois/Documents/bah-bah/src/main.bah"
if (__builtin_expect((fileMap__isValid(&fm)==0)||(fm.size==0), 0)) {

#line 249 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1644 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1644[2] = "'.";____BAH_COMPILER_VAR_1644[1] = args->data[1];____BAH_COMPILER_VAR_1644[0] = "Could not open file '";char * ____BAH_COMPILER_VAR_1645 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1644, 3);println(____BAH_COMPILER_VAR_1645);

#line 250 "/home/alois/Documents/bah-bah/src/main.bah"
exit(1);
}

#line 252 "/home/alois/Documents/bah-bah/src/main.bah"
long int startTime = getTimeUnix();

#line 253 "/home/alois/Documents/bah-bah/src/main.bah"
array(struct Tok)* tokens = lexer(f,fm.size);

#line 254 "/home/alois/Documents/bah-bah/src/main.bah"
fileMap__close(&fm);

#line 257 "/home/alois/Documents/bah-bah/src/main.bah"
if (__builtin_expect((len(tokens)==0), 0)) {

#line 258 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1646 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1646[2] = "' not recognized.";____BAH_COMPILER_VAR_1646[1] = fileName;____BAH_COMPILER_VAR_1646[0] = "File '";char * ____BAH_COMPILER_VAR_1647 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1646, 3);println(____BAH_COMPILER_VAR_1647);

#line 259 "/home/alois/Documents/bah-bah/src/main.bah"
exit(1);
}

#line 262 "/home/alois/Documents/bah-bah/src/main.bah"
struct Elems* ____BAH_COMPILER_VAR_1648 = memoryAlloc(sizeof(struct Elems));
____BAH_COMPILER_VAR_1648->vars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_1648->vars->length = 0;
            ____BAH_COMPILER_VAR_1648->vars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_1648->structs = memoryAlloc(sizeof(array(struct cStruct*)));
            ____BAH_COMPILER_VAR_1648->structs->length = 0;
            ____BAH_COMPILER_VAR_1648->structs->elemSize = sizeof(struct cStruct*);
            ____BAH_COMPILER_VAR_1648->types = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_1648->types->length = 0;
            ____BAH_COMPILER_VAR_1648->types->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_1648->fns = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_1648->fns->length = 0;
            ____BAH_COMPILER_VAR_1648->fns->elemSize = sizeof(struct func*);
            ____BAH_COMPILER_VAR_1648->deletedVars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_1648->deletedVars->length = 0;
            ____BAH_COMPILER_VAR_1648->deletedVars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_1648->branchChecks = memoryAlloc(sizeof(array(struct varCheck)));
            ____BAH_COMPILER_VAR_1648->branchChecks->length = 0;
            ____BAH_COMPILER_VAR_1648->branchChecks->elemSize = sizeof(struct varCheck);
            struct Elems* elems = ____BAH_COMPILER_VAR_1648;

#line 265 "/home/alois/Documents/bah-bah/src/main.bah"
if ((isObject==true)) {

#line 266 "/home/alois/Documents/bah-bah/src/main.bah"
OUTPUT = rope("\n        #define noCheck(v) v\n        #define array(type)	\
        struct{	\
        type *data; \
        long int length; \
        long int realLength; \
        long int elemSize; \
        }\n        typedef array(char*)* __BAH_ARR_TYPE_cpstring;\n        long int __BAH__main(__BAH_ARR_TYPE_cpstring);\n        ");

#line 278 "/home/alois/Documents/bah-bah/src/main.bah"
shouldOnlyDecl = true;
}

#line 282 "/home/alois/Documents/bah-bah/src/main.bah"

                struct string ____BAH_COMPILER_VAR_1649 = string(fileName);
                if ((flags__isSet(&flags,"nobuiltin")==0)&&(string__hasSuffix(&____BAH_COMPILER_VAR_1649,".bahstrp")==false)) {

#line 283 "/home/alois/Documents/bah-bah/src/main.bah"
if (__builtin_expect((includeFile("builtin.bah",elems)==false), 0)) {

#line 284 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1650 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1650[2] = "'";____BAH_COMPILER_VAR_1650[1] = BAH_DIR;____BAH_COMPILER_VAR_1650[0] = "Could not find std-libs, please check '";char * ____BAH_COMPILER_VAR_1651 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1650, 3);__BAH_panic(____BAH_COMPILER_VAR_1651,"/home/alois/Documents/bah-bah/src/main.bah:284");
}
}

#line 288 "/home/alois/Documents/bah-bah/src/main.bah"
if ((isFixMeEnabled==true)) {

#line 289 "/home/alois/Documents/bah-bah/src/main.bah"
if (__builtin_expect((includeFile("fixme.bah",elems)==false), 0)) {

#line 290 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1652 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1652[2] = "'";____BAH_COMPILER_VAR_1652[1] = BAH_DIR;____BAH_COMPILER_VAR_1652[0] = "Could not find fixme.bah, please check '";char * ____BAH_COMPILER_VAR_1653 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1652, 3);__BAH_panic(____BAH_COMPILER_VAR_1653,"/home/alois/Documents/bah-bah/src/main.bah:290");
}
}

#line 294 "/home/alois/Documents/bah-bah/src/main.bah"
shouldOnlyDecl = false;

#line 297 "/home/alois/Documents/bah-bah/src/main.bah"
if ((flags__isSet(&flags,"l")==1)) {

#line 298 "/home/alois/Documents/bah-bah/src/main.bah"
OUTPUT = rope("");

#line 299 "/home/alois/Documents/bah-bah/src/main.bah"
declareAll(elems);
}

#line 302 "/home/alois/Documents/bah-bah/src/main.bah"
compilerState.currentDir = getDirFromFile(fileName);

#line 303 "/home/alois/Documents/bah-bah/src/main.bah"
parseLines(tokens,elems);

#line 305 "/home/alois/Documents/bah-bah/src/main.bah"
if ((isObject==false)&&(isUnsafe==false)) {

#line 306 "/home/alois/Documents/bah-bah/src/main.bah"
long int l = 0;

#line 307 "/home/alois/Documents/bah-bah/src/main.bah"
register long int i = 0;

#line 307 "/home/alois/Documents/bah-bah/src/main.bah"
for (; (i<len(elems->fns)); 
#line 307 "/home/alois/Documents/bah-bah/src/main.bah"
++i) {

#line 308 "/home/alois/Documents/bah-bah/src/main.bah"
struct func* fn = elems->fns->data[i];

#line 309 "/home/alois/Documents/bah-bah/src/main.bah"
if ((fn->isBinding==true)) {

#line 310 "/home/alois/Documents/bah-bah/src/main.bah"
continue;
}

#line 312 "/home/alois/Documents/bah-bah/src/main.bah"
++l;
};

#line 314 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1654 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1654[2] = "];";____BAH_COMPILER_VAR_1654[1] = intToStr(l);____BAH_COMPILER_VAR_1654[0] = "volatile struct __Bah_fnName_mapper __tmp____Bah_fnNames[";char * ____BAH_COMPILER_VAR_1655 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1654, 3);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1655));

#line 315 "/home/alois/Documents/bah-bah/src/main.bah"
long int j = 0;

#line 316 "/home/alois/Documents/bah-bah/src/main.bah"
i = 0;

#line 316 "/home/alois/Documents/bah-bah/src/main.bah"
for (; (i<len(elems->fns)); 
#line 316 "/home/alois/Documents/bah-bah/src/main.bah"
++i) {

#line 317 "/home/alois/Documents/bah-bah/src/main.bah"
struct func* fn = elems->fns->data[i];

#line 318 "/home/alois/Documents/bah-bah/src/main.bah"
if ((fn->isBinding==true)) {

#line 319 "/home/alois/Documents/bah-bah/src/main.bah"
continue;
}

#line 321 "/home/alois/Documents/bah-bah/src/main.bah"
char * name = fn->name;

#line 322 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1656 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1656[1] = "__";____BAH_COMPILER_VAR_1656[0] = fn->from;char * ____BAH_COMPILER_VAR_1657 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1656, 2);if ((strcmp(fn->from, "") != 0)&&strHasPrefix(name,____BAH_COMPILER_VAR_1657)) {

#line 323 "/home/alois/Documents/bah-bah/src/main.bah"
struct string n = string(name);

#line 324 "/home/alois/Documents/bah-bah/src/main.bah"
string__trimLeft(&n,strlen(fn->from)+2);

#line 325 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1658 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1658[2] = string__str(&n);____BAH_COMPILER_VAR_1658[1] = ".";____BAH_COMPILER_VAR_1658[0] = fn->from;char * ____BAH_COMPILER_VAR_1659 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1658, 3);name = ____BAH_COMPILER_VAR_1659;
}

#line 327 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1660 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1660[2] = "\"";____BAH_COMPILER_VAR_1660[1] = name;____BAH_COMPILER_VAR_1660[0] = "\"";char * ____BAH_COMPILER_VAR_1661 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1660, 3);char** ____BAH_COMPILER_VAR_1662 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_1662[8] = ";\n";____BAH_COMPILER_VAR_1662[7] = fn->name;____BAH_COMPILER_VAR_1662[6] = "].p = ";____BAH_COMPILER_VAR_1662[5] = intToStr(j);____BAH_COMPILER_VAR_1662[4] = ";\n            __tmp____Bah_fnNames[";____BAH_COMPILER_VAR_1662[3] = strLitteralToBahStr(____BAH_COMPILER_VAR_1661);____BAH_COMPILER_VAR_1662[2] = "].n = ";____BAH_COMPILER_VAR_1662[1] = intToStr(j);____BAH_COMPILER_VAR_1662[0] = "\n            __tmp____Bah_fnNames[";char * ____BAH_COMPILER_VAR_1663 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1662, 9);INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_1663));

#line 330 "/home/alois/Documents/bah-bah/src/main.bah"
++j;
};

#line 332 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1664 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1664[2] = ";";____BAH_COMPILER_VAR_1664[1] = intToStr(l);____BAH_COMPILER_VAR_1664[0] = "\n        __Bah_fnNames->data = __tmp____Bah_fnNames;\n        __Bah_fnNames->length = ";char * ____BAH_COMPILER_VAR_1665 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1664, 3);INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_1665));
}

#line 337 "/home/alois/Documents/bah-bah/src/main.bah"
makeInit();

#line 339 "/home/alois/Documents/bah-bah/src/main.bah"
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

#line 360 "/home/alois/Documents/bah-bah/src/main.bah"
if ((debug==true)) {

#line 361 "/home/alois/Documents/bah-bah/src/main.bah"
debugEnd();

#line 362 "/home/alois/Documents/bah-bah/src/main.bah"
return 0;
}

#line 366 "/home/alois/Documents/bah-bah/src/main.bah"
if ((isObject==false)) {

#line 367 "/home/alois/Documents/bah-bah/src/main.bah"
long int totalTime = getTimeUnix()-startTime;

#line 368 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1666 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_1666[6] = "ms)\e[0m";____BAH_COMPILER_VAR_1666[5] = intToStr(totalLexerTime/1000000);____BAH_COMPILER_VAR_1666[4] = "ms, lexer time: ";____BAH_COMPILER_VAR_1666[3] = intToStr(totalTime/1000000);____BAH_COMPILER_VAR_1666[2] = " lines, total time: ";____BAH_COMPILER_VAR_1666[1] = intToStr(totalLines);____BAH_COMPILER_VAR_1666[0] = "Parsed. (";char * ____BAH_COMPILER_VAR_1667 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1666, 7);println(____BAH_COMPILER_VAR_1667);
}

#line 372 "/home/alois/Documents/bah-bah/src/main.bah"
if ((flags__isSet(&flags,"o")==1)) {

#line 373 "/home/alois/Documents/bah-bah/src/main.bah"
fileName = flags__get(&flags,"o");
}

#line 374 "/home/alois/Documents/bah-bah/src/main.bah"
else {

#line 375 "/home/alois/Documents/bah-bah/src/main.bah"
struct string outFileName = string(args->data[1]);

#line 376 "/home/alois/Documents/bah-bah/src/main.bah"
string__trimRight(&outFileName,4);

#line 377 "/home/alois/Documents/bah-bah/src/main.bah"
fileName = string__str(&outFileName);
}

#line 381 "/home/alois/Documents/bah-bah/src/main.bah"
char * isStatic = "-static";

#line 382 "/home/alois/Documents/bah-bah/src/main.bah"
if ((flags__isSet(&flags,"d")==1)||(strcmp(BAH_OS, "darwin") == 0)) {

#line 383 "/home/alois/Documents/bah-bah/src/main.bah"
isStatic = "";
}

#line 387 "/home/alois/Documents/bah-bah/src/main.bah"
if ((flags__isSet(&flags,"c")==0)) {

#line 389 "/home/alois/Documents/bah-bah/src/main.bah"
char * obj = "";

#line 390 "/home/alois/Documents/bah-bah/src/main.bah"
if ((flags__isSet(&flags,"object")==1)) {

#line 391 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1668 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1668[1] = ".o";____BAH_COMPILER_VAR_1668[0] = fileName;char * ____BAH_COMPILER_VAR_1669 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1668, 2);fileName = ____BAH_COMPILER_VAR_1669;

#line 392 "/home/alois/Documents/bah-bah/src/main.bah"
obj = "-c";
}

#line 395 "/home/alois/Documents/bah-bah/src/main.bah"
char * randFileName = "-x c - -x none";

#line 396 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1670 = alloca(17 * sizeof(char*));____BAH_COMPILER_VAR_1670[16] = fileName;____BAH_COMPILER_VAR_1670[15] = " -w -O1 -g1 -o ";____BAH_COMPILER_VAR_1670[14] = obj;____BAH_COMPILER_VAR_1670[13] = " ";____BAH_COMPILER_VAR_1670[12] = isStatic;____BAH_COMPILER_VAR_1670[11] = " ";____BAH_COMPILER_VAR_1670[10] = randFileName;____BAH_COMPILER_VAR_1670[9] = "/\" ";____BAH_COMPILER_VAR_1670[8] = BAH_OS;____BAH_COMPILER_VAR_1670[7] = "libs/";____BAH_COMPILER_VAR_1670[6] = BAH_DIR;____BAH_COMPILER_VAR_1670[5] = "/include/\" -L \"";____BAH_COMPILER_VAR_1670[4] = BAH_OS;____BAH_COMPILER_VAR_1670[3] = "libs/";____BAH_COMPILER_VAR_1670[2] = BAH_DIR;____BAH_COMPILER_VAR_1670[1] = " -I \"";____BAH_COMPILER_VAR_1670[0] = BAH_CC;char * ____BAH_COMPILER_VAR_1671 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1670, 17);char * gccArgs = ____BAH_COMPILER_VAR_1671;

#line 398 "/home/alois/Documents/bah-bah/src/main.bah"
if ((flags__isSet(&flags,"l")==1)) {

#line 399 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1672 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1672[1] = " -c";____BAH_COMPILER_VAR_1672[0] = gccArgs;char * ____BAH_COMPILER_VAR_1673 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1672, 2);gccArgs = ____BAH_COMPILER_VAR_1673;
}

#line 403 "/home/alois/Documents/bah-bah/src/main.bah"
array(char *)* cLibs = compilerState.cLibs;

#line 404 "/home/alois/Documents/bah-bah/src/main.bah"
register long int i = 0;

#line 404 "/home/alois/Documents/bah-bah/src/main.bah"
while ((i<len(cLibs))) {

#line 405 "/home/alois/Documents/bah-bah/src/main.bah"
char * l = cLibs->data[i];

#line 406 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1674 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1674[2] = l;____BAH_COMPILER_VAR_1674[1] = " -";____BAH_COMPILER_VAR_1674[0] = gccArgs;char * ____BAH_COMPILER_VAR_1675 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1674, 3);gccArgs = ____BAH_COMPILER_VAR_1675;

#line 407 "/home/alois/Documents/bah-bah/src/main.bah"
i = i+1;
};

#line 411 "/home/alois/Documents/bah-bah/src/main.bah"
struct command cmd = command(gccArgs);

#line 412 "/home/alois/Documents/bah-bah/src/main.bah"
cmd.input = rope__toStr(OUTPUT);

#line 413 "/home/alois/Documents/bah-bah/src/main.bah"

#line 414 "/home/alois/Documents/bah-bah/src/main.bah"
if ((flags__isSet(&flags,"verboseCC")==0)) {

#line 415 "/home/alois/Documents/bah-bah/src/main.bah"
cmd.error = false;
}

#line 418 "/home/alois/Documents/bah-bah/src/main.bah"
if ((flags__isSet(&flags,"verboseCC")==1)) {

#line 419 "/home/alois/Documents/bah-bah/src/main.bah"
char * ____BAH_COMPILER_VAR_1676 =command__run(&cmd);println(____BAH_COMPILER_VAR_1676);
}

#line 420 "/home/alois/Documents/bah-bah/src/main.bah"
else {

#line 421 "/home/alois/Documents/bah-bah/src/main.bah"
char * ____BAH_COMPILER_VAR_1677 =command__run(&cmd);}

#line 424 "/home/alois/Documents/bah-bah/src/main.bah"
if ((cmd.status!=0)) {

#line 425 "/home/alois/Documents/bah-bah/src/main.bah"
println("\e[1;31m[CC-ERROR]\e[0m\nCould not compiled.");

#line 426 "/home/alois/Documents/bah-bah/src/main.bah"
return 1;
}

#line 429 "/home/alois/Documents/bah-bah/src/main.bah"
if ((flags__isSet(&flags,"l")==1)) {

#line 430 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1678 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1678[3] = fileName;____BAH_COMPILER_VAR_1678[2] = ".a ";____BAH_COMPILER_VAR_1678[1] = fileName;____BAH_COMPILER_VAR_1678[0] = "ar rcs ";char * ____BAH_COMPILER_VAR_1679 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1678, 4);cmd = command(____BAH_COMPILER_VAR_1679);

#line 431 "/home/alois/Documents/bah-bah/src/main.bah"
char * ____BAH_COMPILER_VAR_1680 =command__run(&cmd);}
}

#line 434 "/home/alois/Documents/bah-bah/src/main.bah"
else {

#line 436 "/home/alois/Documents/bah-bah/src/main.bah"
if ((flags__isSet(&flags,"o")==0)) {

#line 437 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1681 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1681[1] = ".c";____BAH_COMPILER_VAR_1681[0] = fileName;char * ____BAH_COMPILER_VAR_1682 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1681, 2);fileName = ____BAH_COMPILER_VAR_1682;
}

#line 440 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1683 = alloca(14 * sizeof(char*));____BAH_COMPILER_VAR_1683[13] = " -O1 -w ";____BAH_COMPILER_VAR_1683[12] = isStatic;____BAH_COMPILER_VAR_1683[11] = " ";____BAH_COMPILER_VAR_1683[10] = fileName;____BAH_COMPILER_VAR_1683[9] = "/\" ";____BAH_COMPILER_VAR_1683[8] = BAH_OS;____BAH_COMPILER_VAR_1683[7] = "libs/";____BAH_COMPILER_VAR_1683[6] = BAH_DIR;____BAH_COMPILER_VAR_1683[5] = "/include/\" -L \"";____BAH_COMPILER_VAR_1683[4] = BAH_OS;____BAH_COMPILER_VAR_1683[3] = "libs/";____BAH_COMPILER_VAR_1683[2] = BAH_DIR;____BAH_COMPILER_VAR_1683[1] = " -I \"";____BAH_COMPILER_VAR_1683[0] = BAH_CC;char * ____BAH_COMPILER_VAR_1684 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1683, 14);char * gccArgs = ____BAH_COMPILER_VAR_1684;

#line 441 "/home/alois/Documents/bah-bah/src/main.bah"
array(char *)* cLibs = compilerState.cLibs;

#line 442 "/home/alois/Documents/bah-bah/src/main.bah"
register long int i = 0;

#line 442 "/home/alois/Documents/bah-bah/src/main.bah"
while ((i<len(cLibs))) {

#line 443 "/home/alois/Documents/bah-bah/src/main.bah"
char * l = cLibs->data[i];

#line 444 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1685 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1685[2] = l;____BAH_COMPILER_VAR_1685[1] = " -";____BAH_COMPILER_VAR_1685[0] = gccArgs;char * ____BAH_COMPILER_VAR_1686 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1685, 3);gccArgs = ____BAH_COMPILER_VAR_1686;

#line 445 "/home/alois/Documents/bah-bah/src/main.bah"
i = i+1;
};

#line 447 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1687 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1687[2] = "'\n";____BAH_COMPILER_VAR_1687[1] = gccArgs;____BAH_COMPILER_VAR_1687[0] = "//COMPILE WITH: '";char * ____BAH_COMPILER_VAR_1688 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1687, 3);OUTPUT = rope__add(rope(____BAH_COMPILER_VAR_1688), OUTPUT);

#line 448 "/home/alois/Documents/bah-bah/src/main.bah"
struct fileStream ____BAH_COMPILER_VAR_1689 = {};
struct fileStream fs = ____BAH_COMPILER_VAR_1689;

#line 449 "/home/alois/Documents/bah-bah/src/main.bah"
fileStream__open(&fs,fileName,"w");

#line 450 "/home/alois/Documents/bah-bah/src/main.bah"
char * ____BAH_COMPILER_VAR_1690 =rope__toStr(OUTPUT);fileStream__writeFile(&fs,____BAH_COMPILER_VAR_1690);

#line 451 "/home/alois/Documents/bah-bah/src/main.bah"
fileStream__close(&fs);
}

#line 455 "/home/alois/Documents/bah-bah/src/main.bah"
if ((isObject==false)) {

#line 456 "/home/alois/Documents/bah-bah/src/main.bah"
long int totalTime = getTimeUnix()-startTime;

#line 457 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1691 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1691[2] = "ms)\e[0m";____BAH_COMPILER_VAR_1691[1] = intToStr(totalTime/1000000);____BAH_COMPILER_VAR_1691[0] = "\e[1;32mDone. (compiled in ";char * ____BAH_COMPILER_VAR_1692 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1691, 3);println(____BAH_COMPILER_VAR_1692);
}

#line 460 "/home/alois/Documents/bah-bah/src/main.bah"
return 0;
};
volatile struct __Bah_fnName_mapper __tmp____Bah_fnNames[345];
    
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
prevIfShortcut = "";
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

            __tmp____Bah_fnNames[63].n = "fastExec";
            __tmp____Bah_fnNames[63].p = fastExec;

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

            __tmp____Bah_fnNames[71].n = "mapNode.calc";
            __tmp____Bah_fnNames[71].p = mapNode__calc;

            __tmp____Bah_fnNames[72].n = "mapNode.getFast";
            __tmp____Bah_fnNames[72].p = mapNode__getFast;

            __tmp____Bah_fnNames[73].n = "mapNode.append";
            __tmp____Bah_fnNames[73].p = mapNode__append;

            __tmp____Bah_fnNames[74].n = "mapWrapperSetAlgo";
            __tmp____Bah_fnNames[74].p = mapWrapperSetAlgo;

            __tmp____Bah_fnNames[75].n = "mapWrapper.algoChecks";
            __tmp____Bah_fnNames[75].p = mapWrapper__algoChecks;

            __tmp____Bah_fnNames[76].n = "mapWrapper.grow";
            __tmp____Bah_fnNames[76].p = mapWrapper__grow;

            __tmp____Bah_fnNames[77].n = "mapWrapper.set2";
            __tmp____Bah_fnNames[77].p = mapWrapper__set2;

            __tmp____Bah_fnNames[78].n = "mapWrapper.delete2";
            __tmp____Bah_fnNames[78].p = mapWrapper__delete2;

            __tmp____Bah_fnNames[79].n = "mapWrapper.get2";
            __tmp____Bah_fnNames[79].p = mapWrapper__get2;

            __tmp____Bah_fnNames[80].n = "mapWrapper.clearMsr";
            __tmp____Bah_fnNames[80].p = mapWrapper__clearMsr;

            __tmp____Bah_fnNames[81].n = "mapWrapper.get1";
            __tmp____Bah_fnNames[81].p = mapWrapper__get1;

            __tmp____Bah_fnNames[82].n = "mapWrapper.set1";
            __tmp____Bah_fnNames[82].p = mapWrapper__set1;

            __tmp____Bah_fnNames[83].n = "mapWrapper.delete1";
            __tmp____Bah_fnNames[83].p = mapWrapper__delete1;

            __tmp____Bah_fnNames[84].n = "mapWrapper.setAny";
            __tmp____Bah_fnNames[84].p = mapWrapper__setAny;

            __tmp____Bah_fnNames[85].n = "mapWrapper";
            __tmp____Bah_fnNames[85].p = mapWrapper;

            __tmp____Bah_fnNames[86].n = "deleteMap";
            __tmp____Bah_fnNames[86].p = deleteMap;

            __tmp____Bah_fnNames[87].n = "stdinput";
            __tmp____Bah_fnNames[87].p = stdinput;

            __tmp____Bah_fnNames[88].n = "println";
            __tmp____Bah_fnNames[88].p = println;

            __tmp____Bah_fnNames[89].n = "fileStream.isValid";
            __tmp____Bah_fnNames[89].p = fileStream__isValid;

            __tmp____Bah_fnNames[90].n = "fileStream.open";
            __tmp____Bah_fnNames[90].p = fileStream__open;

            __tmp____Bah_fnNames[91].n = "fileStream.close";
            __tmp____Bah_fnNames[91].p = fileStream__close;

            __tmp____Bah_fnNames[92].n = "fileStream.getPos";
            __tmp____Bah_fnNames[92].p = fileStream__getPos;

            __tmp____Bah_fnNames[93].n = "fileStream.setPos";
            __tmp____Bah_fnNames[93].p = fileStream__setPos;

            __tmp____Bah_fnNames[94].n = "fileStream.getSize";
            __tmp____Bah_fnNames[94].p = fileStream__getSize;

            __tmp____Bah_fnNames[95].n = "fileStream.rewind";
            __tmp____Bah_fnNames[95].p = fileStream__rewind;

            __tmp____Bah_fnNames[96].n = "fileStream.getChar";
            __tmp____Bah_fnNames[96].p = fileStream__getChar;

            __tmp____Bah_fnNames[97].n = "fileStream.setChar";
            __tmp____Bah_fnNames[97].p = fileStream__setChar;

            __tmp____Bah_fnNames[98].n = "fileStream.createFile";
            __tmp____Bah_fnNames[98].p = fileStream__createFile;

            __tmp____Bah_fnNames[99].n = "fileStream.writeFile";
            __tmp____Bah_fnNames[99].p = fileStream__writeFile;

            __tmp____Bah_fnNames[100].n = "fileStream.writePtr";
            __tmp____Bah_fnNames[100].p = fileStream__writePtr;

            __tmp____Bah_fnNames[101].n = "fileStream.readPtr";
            __tmp____Bah_fnNames[101].p = fileStream__readPtr;

            __tmp____Bah_fnNames[102].n = "fileStream.readContent";
            __tmp____Bah_fnNames[102].p = fileStream__readContent;

            __tmp____Bah_fnNames[103].n = "fileStream.readBytes";
            __tmp____Bah_fnNames[103].p = fileStream__readBytes;

            __tmp____Bah_fnNames[104].n = "fileStream.writeBytes";
            __tmp____Bah_fnNames[104].p = fileStream__writeBytes;

            __tmp____Bah_fnNames[105].n = "fileStream._end";
            __tmp____Bah_fnNames[105].p = fileStream___end;

            __tmp____Bah_fnNames[106].n = "fileMap.open";
            __tmp____Bah_fnNames[106].p = fileMap__open;

            __tmp____Bah_fnNames[107].n = "fileMap.isValid";
            __tmp____Bah_fnNames[107].p = fileMap__isValid;

            __tmp____Bah_fnNames[108].n = "fileMap.close";
            __tmp____Bah_fnNames[108].p = fileMap__close;

            __tmp____Bah_fnNames[109].n = "listFiles";
            __tmp____Bah_fnNames[109].p = listFiles;

            __tmp____Bah_fnNames[110].n = "fileExists";
            __tmp____Bah_fnNames[110].p = fileExists;

            __tmp____Bah_fnNames[111].n = "isFolder";
            __tmp____Bah_fnNames[111].p = isFolder;

            __tmp____Bah_fnNames[112].n = "removeFile";
            __tmp____Bah_fnNames[112].p = removeFile;

            __tmp____Bah_fnNames[113].n = "getLastModified";
            __tmp____Bah_fnNames[113].p = getLastModified;

            __tmp____Bah_fnNames[114].n = "strCatOffset";
            __tmp____Bah_fnNames[114].p = strCatOffset;

            __tmp____Bah_fnNames[115].n = "charToString";
            __tmp____Bah_fnNames[115].p = charToString;

            __tmp____Bah_fnNames[116].n = "isUpper";
            __tmp____Bah_fnNames[116].p = isUpper;

            __tmp____Bah_fnNames[117].n = "isLower";
            __tmp____Bah_fnNames[117].p = isLower;

            __tmp____Bah_fnNames[118].n = "isLetter";
            __tmp____Bah_fnNames[118].p = isLetter;

            __tmp____Bah_fnNames[119].n = "isNumber";
            __tmp____Bah_fnNames[119].p = isNumber;

            __tmp____Bah_fnNames[120].n = "isAlphaNumeric";
            __tmp____Bah_fnNames[120].p = isAlphaNumeric;

            __tmp____Bah_fnNames[121].n = "isSpace";
            __tmp____Bah_fnNames[121].p = isSpace;

            __tmp____Bah_fnNames[122].n = "string.set";
            __tmp____Bah_fnNames[122].p = string__set;

            __tmp____Bah_fnNames[123].n = "string.makeEditable";
            __tmp____Bah_fnNames[123].p = string__makeEditable;

            __tmp____Bah_fnNames[124].n = "string.append";
            __tmp____Bah_fnNames[124].p = string__append;

            __tmp____Bah_fnNames[125].n = "string.prepend";
            __tmp____Bah_fnNames[125].p = string__prepend;

            __tmp____Bah_fnNames[126].n = "string.charAt";
            __tmp____Bah_fnNames[126].p = string__charAt;

            __tmp____Bah_fnNames[127].n = "string.compare";
            __tmp____Bah_fnNames[127].p = string__compare;

            __tmp____Bah_fnNames[128].n = "string.str";
            __tmp____Bah_fnNames[128].p = string__str;

            __tmp____Bah_fnNames[129].n = "string.replace";
            __tmp____Bah_fnNames[129].p = string__replace;

            __tmp____Bah_fnNames[130].n = "string.countChar";
            __tmp____Bah_fnNames[130].p = string__countChar;

            __tmp____Bah_fnNames[131].n = "string.count";
            __tmp____Bah_fnNames[131].p = string__count;

            __tmp____Bah_fnNames[132].n = "string.hasPrefix";
            __tmp____Bah_fnNames[132].p = string__hasPrefix;

            __tmp____Bah_fnNames[133].n = "string.hasSuffix";
            __tmp____Bah_fnNames[133].p = string__hasSuffix;

            __tmp____Bah_fnNames[134].n = "string.trim";
            __tmp____Bah_fnNames[134].p = string__trim;

            __tmp____Bah_fnNames[135].n = "string.trimLeft";
            __tmp____Bah_fnNames[135].p = string__trimLeft;

            __tmp____Bah_fnNames[136].n = "string.trimRight";
            __tmp____Bah_fnNames[136].p = string__trimRight;

            __tmp____Bah_fnNames[137].n = "string.add";
            __tmp____Bah_fnNames[137].p = string__add;

            __tmp____Bah_fnNames[138].n = "string.asArr";
            __tmp____Bah_fnNames[138].p = string__asArr;

            __tmp____Bah_fnNames[139].n = "string";
            __tmp____Bah_fnNames[139].p = string;

            __tmp____Bah_fnNames[140].n = "intToStr";
            __tmp____Bah_fnNames[140].p = intToStr;

            __tmp____Bah_fnNames[141].n = "intToString";
            __tmp____Bah_fnNames[141].p = intToString;

            __tmp____Bah_fnNames[142].n = "floatToStr";
            __tmp____Bah_fnNames[142].p = floatToStr;

            __tmp____Bah_fnNames[143].n = "strToInt";
            __tmp____Bah_fnNames[143].p = strToInt;

            __tmp____Bah_fnNames[144].n = "strToFloat";
            __tmp____Bah_fnNames[144].p = strToFloat;

            __tmp____Bah_fnNames[145].n = "stringToInt";
            __tmp____Bah_fnNames[145].p = stringToInt;

            __tmp____Bah_fnNames[146].n = "splitString";
            __tmp____Bah_fnNames[146].p = splitString;

            __tmp____Bah_fnNames[147].n = "joinString";
            __tmp____Bah_fnNames[147].p = joinString;

            __tmp____Bah_fnNames[148].n = "splitStringBefore";
            __tmp____Bah_fnNames[148].p = splitStringBefore;

            __tmp____Bah_fnNames[149].n = "toLower";
            __tmp____Bah_fnNames[149].p = toLower;

            __tmp____Bah_fnNames[150].n = "strHasPrefix";
            __tmp____Bah_fnNames[150].p = strHasPrefix;

            __tmp____Bah_fnNames[151].n = "strHasSuffix";
            __tmp____Bah_fnNames[151].p = strHasSuffix;

            __tmp____Bah_fnNames[152].n = "strTrim";
            __tmp____Bah_fnNames[152].p = strTrim;

            __tmp____Bah_fnNames[153].n = "strCount";
            __tmp____Bah_fnNames[153].p = strCount;

            __tmp____Bah_fnNames[154].n = "flags.addString";
            __tmp____Bah_fnNames[154].p = flags__addString;

            __tmp____Bah_fnNames[155].n = "flags.addBool";
            __tmp____Bah_fnNames[155].p = flags__addBool;

            __tmp____Bah_fnNames[156].n = "flags.addInt";
            __tmp____Bah_fnNames[156].p = flags__addInt;

            __tmp____Bah_fnNames[157].n = "flags.addFloat";
            __tmp____Bah_fnNames[157].p = flags__addFloat;

            __tmp____Bah_fnNames[158].n = "flags.invalidate";
            __tmp____Bah_fnNames[158].p = flags__invalidate;

            __tmp____Bah_fnNames[159].n = "flags.getFlag";
            __tmp____Bah_fnNames[159].p = flags__getFlag;

            __tmp____Bah_fnNames[160].n = "flags.get";
            __tmp____Bah_fnNames[160].p = flags__get;

            __tmp____Bah_fnNames[161].n = "flags.getInt";
            __tmp____Bah_fnNames[161].p = flags__getInt;

            __tmp____Bah_fnNames[162].n = "flags.getFloat";
            __tmp____Bah_fnNames[162].p = flags__getFloat;

            __tmp____Bah_fnNames[163].n = "flags.isSet";
            __tmp____Bah_fnNames[163].p = flags__isSet;

            __tmp____Bah_fnNames[164].n = "flags.parse";
            __tmp____Bah_fnNames[164].p = flags__parse;

            __tmp____Bah_fnNames[165].n = "time.now";
            __tmp____Bah_fnNames[165].p = time__now;

            __tmp____Bah_fnNames[166].n = "time.format";
            __tmp____Bah_fnNames[166].p = time__format;

            __tmp____Bah_fnNames[167].n = "time.since";
            __tmp____Bah_fnNames[167].p = time__since;

            __tmp____Bah_fnNames[168].n = "getTimeUnix";
            __tmp____Bah_fnNames[168].p = getTimeUnix;

            __tmp____Bah_fnNames[169].n = "seedRandom";
            __tmp____Bah_fnNames[169].p = seedRandom;

            __tmp____Bah_fnNames[170].n = "randomInRange";
            __tmp____Bah_fnNames[170].p = randomInRange;

            __tmp____Bah_fnNames[171].n = "cryptoRand";
            __tmp____Bah_fnNames[171].p = cryptoRand;

            __tmp____Bah_fnNames[172].n = "rope.addStr";
            __tmp____Bah_fnNames[172].p = rope__addStr;

            __tmp____Bah_fnNames[173].n = "rope.toStr";
            __tmp____Bah_fnNames[173].p = rope__toStr;

            __tmp____Bah_fnNames[174].n = "rope.add";
            __tmp____Bah_fnNames[174].p = rope__add;

            __tmp____Bah_fnNames[175].n = "createRopeStructure";
            __tmp____Bah_fnNames[175].p = createRopeStructure;

            __tmp____Bah_fnNames[176].n = "ropeSet";
            __tmp____Bah_fnNames[176].p = ropeSet;

            __tmp____Bah_fnNames[177].n = "concatenateRopes";
            __tmp____Bah_fnNames[177].p = concatenateRopes;

            __tmp____Bah_fnNames[178].n = "rope";
            __tmp____Bah_fnNames[178].p = rope;

            __tmp____Bah_fnNames[179].n = "command.run";
            __tmp____Bah_fnNames[179].p = command__run;

            __tmp____Bah_fnNames[180].n = "command.runBytes";
            __tmp____Bah_fnNames[180].p = command__runBytes;

            __tmp____Bah_fnNames[181].n = "command";
            __tmp____Bah_fnNames[181].p = command;

            __tmp____Bah_fnNames[182].n = "exec";
            __tmp____Bah_fnNames[182].p = exec;

            __tmp____Bah_fnNames[183].n = "Elems.isChildren";
            __tmp____Bah_fnNames[183].p = Elems__isChildren;

            __tmp____Bah_fnNames[184].n = "inArray";
            __tmp____Bah_fnNames[184].p = inArray;

            __tmp____Bah_fnNames[185].n = "inArrayStr";
            __tmp____Bah_fnNames[185].p = inArrayStr;

            __tmp____Bah_fnNames[186].n = "makeToken";
            __tmp____Bah_fnNames[186].p = makeToken;

            __tmp____Bah_fnNames[187].n = "isMinus";
            __tmp____Bah_fnNames[187].p = isMinus;

            __tmp____Bah_fnNames[188].n = "lexerErr";
            __tmp____Bah_fnNames[188].p = lexerErr;

            __tmp____Bah_fnNames[189].n = "lexer";
            __tmp____Bah_fnNames[189].p = lexer;

            __tmp____Bah_fnNames[190].n = "hasStructSep";
            __tmp____Bah_fnNames[190].p = hasStructSep;

            __tmp____Bah_fnNames[191].n = "splitStructSepBefore";
            __tmp____Bah_fnNames[191].p = splitStructSepBefore;

            __tmp____Bah_fnNames[192].n = "splitStructSepAfter";
            __tmp____Bah_fnNames[192].p = splitStructSepAfter;

            __tmp____Bah_fnNames[193].n = "searchStruct";
            __tmp____Bah_fnNames[193].p = searchStruct;

            __tmp____Bah_fnNames[194].n = "searchStructMemb";
            __tmp____Bah_fnNames[194].p = searchStructMemb;

            __tmp____Bah_fnNames[195].n = "searchFunc";
            __tmp____Bah_fnNames[195].p = searchFunc;

            __tmp____Bah_fnNames[196].n = "parseFnType";
            __tmp____Bah_fnNames[196].p = parseFnType;

            __tmp____Bah_fnNames[197].n = "searchStructMethod";
            __tmp____Bah_fnNames[197].p = searchStructMethod;

            __tmp____Bah_fnNames[198].n = "typeAsStar";
            __tmp____Bah_fnNames[198].p = typeAsStar;

            __tmp____Bah_fnNames[199].n = "isRCPpointerType";
            __tmp____Bah_fnNames[199].p = isRCPpointerType;

            __tmp____Bah_fnNames[200].n = "isRCPtype";
            __tmp____Bah_fnNames[200].p = isRCPtype;

            __tmp____Bah_fnNames[201].n = "getCType";
            __tmp____Bah_fnNames[201].p = getCType;

            __tmp____Bah_fnNames[202].n = "maybeToPtr";
            __tmp____Bah_fnNames[202].p = maybeToPtr;

            __tmp____Bah_fnNames[203].n = "compTypeEquiv";
            __tmp____Bah_fnNames[203].p = compTypeEquiv;

            __tmp____Bah_fnNames[204].n = "compTypes";
            __tmp____Bah_fnNames[204].p = compTypes;

            __tmp____Bah_fnNames[205].n = "reflectElement.calculateOffset";
            __tmp____Bah_fnNames[205].p = reflectElement__calculateOffset;

            __tmp____Bah_fnNames[206].n = "__reflect";
            __tmp____Bah_fnNames[206].p = __reflect;

            __tmp____Bah_fnNames[207].n = "__dumpSymbols";
            __tmp____Bah_fnNames[207].p = __dumpSymbols;

            __tmp____Bah_fnNames[208].n = "__debug_get_sym";
            __tmp____Bah_fnNames[208].p = __debug_get_sym;

            __tmp____Bah_fnNames[209].n = "toJson";
            __tmp____Bah_fnNames[209].p = toJson;

            __tmp____Bah_fnNames[210].n = "json_scan_inner";
            __tmp____Bah_fnNames[210].p = json_scan_inner;

            __tmp____Bah_fnNames[211].n = "jsonElement.get";
            __tmp____Bah_fnNames[211].p = jsonElement__get;

            __tmp____Bah_fnNames[212].n = "jsonElement.str";
            __tmp____Bah_fnNames[212].p = jsonElement__str;

            __tmp____Bah_fnNames[213].n = "jsonElement.scan";
            __tmp____Bah_fnNames[213].p = jsonElement__scan;

            __tmp____Bah_fnNames[214].n = "parseJson";
            __tmp____Bah_fnNames[214].p = parseJson;

            __tmp____Bah_fnNames[215].n = "json_isPrintable";
            __tmp____Bah_fnNames[215].p = json_isPrintable;

            __tmp____Bah_fnNames[216].n = "jsonEscapeStr";
            __tmp____Bah_fnNames[216].p = jsonEscapeStr;

            __tmp____Bah_fnNames[217].n = "oldToJson__inner";
            __tmp____Bah_fnNames[217].p = oldToJson__inner;

            __tmp____Bah_fnNames[218].n = "oldToJson";
            __tmp____Bah_fnNames[218].p = oldToJson;

            __tmp____Bah_fnNames[219].n = "debugStart";
            __tmp____Bah_fnNames[219].p = debugStart;

            __tmp____Bah_fnNames[220].n = "debugPrint";
            __tmp____Bah_fnNames[220].p = debugPrint;

            __tmp____Bah_fnNames[221].n = "debugError";
            __tmp____Bah_fnNames[221].p = debugError;

            __tmp____Bah_fnNames[222].n = "debugEnd";
            __tmp____Bah_fnNames[222].p = debugEnd;

            __tmp____Bah_fnNames[223].n = "debugExit";
            __tmp____Bah_fnNames[223].p = debugExit;

            __tmp____Bah_fnNames[224].n = "debugEndScope";
            __tmp____Bah_fnNames[224].p = debugEndScope;

            __tmp____Bah_fnNames[225].n = "advertiseGeneric";
            __tmp____Bah_fnNames[225].p = advertiseGeneric;

            __tmp____Bah_fnNames[226].n = "throwErr";
            __tmp____Bah_fnNames[226].p = throwErr;

            __tmp____Bah_fnNames[227].n = "throwWarning";
            __tmp____Bah_fnNames[227].p = throwWarning;

            __tmp____Bah_fnNames[228].n = "throwWarningLine";
            __tmp____Bah_fnNames[228].p = throwWarningLine;

            __tmp____Bah_fnNames[229].n = "throwNoticeLine";
            __tmp____Bah_fnNames[229].p = throwNoticeLine;

            __tmp____Bah_fnNames[230].n = "absPath";
            __tmp____Bah_fnNames[230].p = absPath;

            __tmp____Bah_fnNames[231].n = "getCurrentPath";
            __tmp____Bah_fnNames[231].p = getCurrentPath;

            __tmp____Bah_fnNames[232].n = "isInside";
            __tmp____Bah_fnNames[232].p = isInside;

            __tmp____Bah_fnNames[233].n = "setCurrentPath";
            __tmp____Bah_fnNames[233].p = setCurrentPath;

            __tmp____Bah_fnNames[234].n = "isGlobal";
            __tmp____Bah_fnNames[234].p = isGlobal;

            __tmp____Bah_fnNames[235].n = "getRealVar";
            __tmp____Bah_fnNames[235].p = getRealVar;

            __tmp____Bah_fnNames[236].n = "removeVarUnar";
            __tmp____Bah_fnNames[236].p = removeVarUnar;

            __tmp____Bah_fnNames[237].n = "searchVar";
            __tmp____Bah_fnNames[237].p = searchVar;

            __tmp____Bah_fnNames[238].n = "searchVarByToken";
            __tmp____Bah_fnNames[238].p = searchVarByToken;

            __tmp____Bah_fnNames[239].n = "searchVirtVarByToken";
            __tmp____Bah_fnNames[239].p = searchVirtVarByToken;

            __tmp____Bah_fnNames[240].n = "setCType";
            __tmp____Bah_fnNames[240].p = setCType;

            __tmp____Bah_fnNames[241].n = "isMissingVar";
            __tmp____Bah_fnNames[241].p = isMissingVar;

            __tmp____Bah_fnNames[242].n = "getTypeFromToken";
            __tmp____Bah_fnNames[242].p = getTypeFromToken;

            __tmp____Bah_fnNames[243].n = "searchFuncByToken";
            __tmp____Bah_fnNames[243].p = searchFuncByToken;

            __tmp____Bah_fnNames[244].n = "RCPavailable";
            __tmp____Bah_fnNames[244].p = RCPavailable;

            __tmp____Bah_fnNames[245].n = "declareStructMethods";
            __tmp____Bah_fnNames[245].p = declareStructMethods;

            __tmp____Bah_fnNames[246].n = "genCompilerVar";
            __tmp____Bah_fnNames[246].p = genCompilerVar;

            __tmp____Bah_fnNames[247].n = "varInArr";
            __tmp____Bah_fnNames[247].p = varInArr;

            __tmp____Bah_fnNames[248].n = "pathToVarName";
            __tmp____Bah_fnNames[248].p = pathToVarName;

            __tmp____Bah_fnNames[249].n = "makeInit";
            __tmp____Bah_fnNames[249].p = makeInit;

            __tmp____Bah_fnNames[250].n = "checkedNull";
            __tmp____Bah_fnNames[250].p = checkedNull;

            __tmp____Bah_fnNames[251].n = "checkedNotNull";
            __tmp____Bah_fnNames[251].p = checkedNotNull;

            __tmp____Bah_fnNames[252].n = "canChangeNullState";
            __tmp____Bah_fnNames[252].p = canChangeNullState;

            __tmp____Bah_fnNames[253].n = "removeCast";
            __tmp____Bah_fnNames[253].p = removeCast;

            __tmp____Bah_fnNames[254].n = "isOutterScope";
            __tmp____Bah_fnNames[254].p = isOutterScope;

            __tmp____Bah_fnNames[255].n = "decrVar";
            __tmp____Bah_fnNames[255].p = decrVar;

            __tmp____Bah_fnNames[256].n = "incrVar";
            __tmp____Bah_fnNames[256].p = incrVar;

            __tmp____Bah_fnNames[257].n = "beginRCPscope";
            __tmp____Bah_fnNames[257].p = beginRCPscope;

            __tmp____Bah_fnNames[258].n = "beginRCPscopeLeaky";
            __tmp____Bah_fnNames[258].p = beginRCPscopeLeaky;

            __tmp____Bah_fnNames[259].n = "endRCPscope";
            __tmp____Bah_fnNames[259].p = endRCPscope;

            __tmp____Bah_fnNames[260].n = "endRCPscopeLeaky";
            __tmp____Bah_fnNames[260].p = endRCPscopeLeaky;

            __tmp____Bah_fnNames[261].n = "registerRCPvar";
            __tmp____Bah_fnNames[261].p = registerRCPvar;

            __tmp____Bah_fnNames[262].n = "RCPselfRef";
            __tmp____Bah_fnNames[262].p = RCPselfRef;

            __tmp____Bah_fnNames[263].n = "verboseOutGuard";
            __tmp____Bah_fnNames[263].p = verboseOutGuard;

            __tmp____Bah_fnNames[264].n = "verboseOutTransformVar";
            __tmp____Bah_fnNames[264].p = verboseOutTransformVar;

            __tmp____Bah_fnNames[265].n = "verboseOutTransformTok";
            __tmp____Bah_fnNames[265].p = verboseOutTransformTok;

            __tmp____Bah_fnNames[266].n = "verboseOutFunc";
            __tmp____Bah_fnNames[266].p = verboseOutFunc;

            __tmp____Bah_fnNames[267].n = "verboseOutOper";
            __tmp____Bah_fnNames[267].p = verboseOutOper;

            __tmp____Bah_fnNames[268].n = "readCache";
            __tmp____Bah_fnNames[268].p = readCache;

            __tmp____Bah_fnNames[269].n = "getCacheFile";
            __tmp____Bah_fnNames[269].p = getCacheFile;

            __tmp____Bah_fnNames[270].n = "updateCacheFile";
            __tmp____Bah_fnNames[270].p = updateCacheFile;

            __tmp____Bah_fnNames[271].n = "makeCacheFile";
            __tmp____Bah_fnNames[271].p = makeCacheFile;

            __tmp____Bah_fnNames[272].n = "writeCache";
            __tmp____Bah_fnNames[272].p = writeCache;

            __tmp____Bah_fnNames[273].n = "isValidCacheFile";
            __tmp____Bah_fnNames[273].p = isValidCacheFile;

            __tmp____Bah_fnNames[274].n = "genArrRealloc";
            __tmp____Bah_fnNames[274].p = genArrRealloc;

            __tmp____Bah_fnNames[275].n = "genConcat";
            __tmp____Bah_fnNames[275].p = genConcat;

            __tmp____Bah_fnNames[276].n = "OPTI_checkFuncScopeRef";
            __tmp____Bah_fnNames[276].p = OPTI_checkFuncScopeRef;

            __tmp____Bah_fnNames[277].n = "isExprExpensive";
            __tmp____Bah_fnNames[277].p = isExprExpensive;

            __tmp____Bah_fnNames[278].n = "byteToOctal";
            __tmp____Bah_fnNames[278].p = byteToOctal;

            __tmp____Bah_fnNames[279].n = "escapeIntOctal";
            __tmp____Bah_fnNames[279].p = escapeIntOctal;

            __tmp____Bah_fnNames[280].n = "getStrLen";
            __tmp____Bah_fnNames[280].p = getStrLen;

            __tmp____Bah_fnNames[281].n = "strLitteralToBahStr";
            __tmp____Bah_fnNames[281].p = strLitteralToBahStr;

            __tmp____Bah_fnNames[282].n = "dupElems";
            __tmp____Bah_fnNames[282].p = dupElems;

            __tmp____Bah_fnNames[283].n = "parseLines";
            __tmp____Bah_fnNames[283].p = parseLines;

            __tmp____Bah_fnNames[284].n = "genericFunc.dupBaseFn";
            __tmp____Bah_fnNames[284].p = genericFunc__dupBaseFn;

            __tmp____Bah_fnNames[285].n = "genericFunc.setCurrGeneric";
            __tmp____Bah_fnNames[285].p = genericFunc__setCurrGeneric;

            __tmp____Bah_fnNames[286].n = "genericFunc.isAlreadyDecl";
            __tmp____Bah_fnNames[286].p = genericFunc__isAlreadyDecl;

            __tmp____Bah_fnNames[287].n = "genericFunc.declare";
            __tmp____Bah_fnNames[287].p = genericFunc__declare;

            __tmp____Bah_fnNames[288].n = "debugLine";
            __tmp____Bah_fnNames[288].p = debugLine;

            __tmp____Bah_fnNames[289].n = "checkCanBeNull";
            __tmp____Bah_fnNames[289].p = checkCanBeNull;

            __tmp____Bah_fnNames[290].n = "setNullStateBranchFlowEnd";
            __tmp____Bah_fnNames[290].p = setNullStateBranchFlowEnd;

            __tmp____Bah_fnNames[291].n = "fixMeEnabled";
            __tmp____Bah_fnNames[291].p = fixMeEnabled;

            __tmp____Bah_fnNames[292].n = "fixMeRegisterVar";
            __tmp____Bah_fnNames[292].p = fixMeRegisterVar;

            __tmp____Bah_fnNames[293].n = "fixMeEndScope";
            __tmp____Bah_fnNames[293].p = fixMeEndScope;

            __tmp____Bah_fnNames[294].n = "fixMeTestVar";
            __tmp____Bah_fnNames[294].p = fixMeTestVar;

            __tmp____Bah_fnNames[295].n = "isStaticToken";
            __tmp____Bah_fnNames[295].p = isStaticToken;

            __tmp____Bah_fnNames[296].n = "getLineType";
            __tmp____Bah_fnNames[296].p = getLineType;

            __tmp____Bah_fnNames[297].n = "parseCast";
            __tmp____Bah_fnNames[297].p = parseCast;

            __tmp____Bah_fnNames[298].n = "getDirFromFile";
            __tmp____Bah_fnNames[298].p = getDirFromFile;

            __tmp____Bah_fnNames[299].n = "includeFile";
            __tmp____Bah_fnNames[299].p = includeFile;

            __tmp____Bah_fnNames[300].n = "parallelObjCompile";
            __tmp____Bah_fnNames[300].p = parallelObjCompile;

            __tmp____Bah_fnNames[301].n = "parseImport";
            __tmp____Bah_fnNames[301].p = parseImport;

            __tmp____Bah_fnNames[302].n = "parseInclude";
            __tmp____Bah_fnNames[302].p = parseInclude;

            __tmp____Bah_fnNames[303].n = "prePross";
            __tmp____Bah_fnNames[303].p = prePross;

            __tmp____Bah_fnNames[304].n = "parseStructType";
            __tmp____Bah_fnNames[304].p = parseStructType;

            __tmp____Bah_fnNames[305].n = "parseArrayType";
            __tmp____Bah_fnNames[305].p = parseArrayType;

            __tmp____Bah_fnNames[306].n = "parsePointers";
            __tmp____Bah_fnNames[306].p = parsePointers;

            __tmp____Bah_fnNames[307].n = "parseSerialize";
            __tmp____Bah_fnNames[307].p = parseSerialize;

            __tmp____Bah_fnNames[308].n = "parseReflect";
            __tmp____Bah_fnNames[308].p = parseReflect;

            __tmp____Bah_fnNames[309].n = "parseArrayDecl";
            __tmp____Bah_fnNames[309].p = parseArrayDecl;

            __tmp____Bah_fnNames[310].n = "parseVar";
            __tmp____Bah_fnNames[310].p = parseVar;

            __tmp____Bah_fnNames[311].n = "getCfunctionType";
            __tmp____Bah_fnNames[311].p = getCfunctionType;

            __tmp____Bah_fnNames[312].n = "parseFnHeader";
            __tmp____Bah_fnNames[312].p = parseFnHeader;

            __tmp____Bah_fnNames[313].n = "parseStruct";
            __tmp____Bah_fnNames[313].p = parseStruct;

            __tmp____Bah_fnNames[314].n = "parseDefine";
            __tmp____Bah_fnNames[314].p = parseDefine;

            __tmp____Bah_fnNames[315].n = "parseClib";
            __tmp____Bah_fnNames[315].p = parseClib;

            __tmp____Bah_fnNames[316].n = "parseConst";
            __tmp____Bah_fnNames[316].p = parseConst;

            __tmp____Bah_fnNames[317].n = "parseReturn";
            __tmp____Bah_fnNames[317].p = parseReturn;

            __tmp____Bah_fnNames[318].n = "parseIf";
            __tmp____Bah_fnNames[318].p = parseIf;

            __tmp____Bah_fnNames[319].n = "parseElse";
            __tmp____Bah_fnNames[319].p = parseElse;

            __tmp____Bah_fnNames[320].n = "parseLine";
            __tmp____Bah_fnNames[320].p = parseLine;

            __tmp____Bah_fnNames[321].n = "parseFor";
            __tmp____Bah_fnNames[321].p = parseFor;

            __tmp____Bah_fnNames[322].n = "parseForOp";
            __tmp____Bah_fnNames[322].p = parseForOp;

            __tmp____Bah_fnNames[323].n = "makeEvalFunc";
            __tmp____Bah_fnNames[323].p = makeEvalFunc;

            __tmp____Bah_fnNames[324].n = "parsePreKeyword";
            __tmp____Bah_fnNames[324].p = parsePreKeyword;

            __tmp____Bah_fnNames[325].n = "parseAsync";
            __tmp____Bah_fnNames[325].p = parseAsync;

            __tmp____Bah_fnNames[326].n = "addRCPvars";
            __tmp____Bah_fnNames[326].p = addRCPvars;

            __tmp____Bah_fnNames[327].n = "parseChan";
            __tmp____Bah_fnNames[327].p = parseChan;

            __tmp____Bah_fnNames[328].n = "valueFunc";
            __tmp____Bah_fnNames[328].p = valueFunc;

            __tmp____Bah_fnNames[329].n = "valueStruct";
            __tmp____Bah_fnNames[329].p = valueStruct;

            __tmp____Bah_fnNames[330].n = "valueArr";
            __tmp____Bah_fnNames[330].p = valueArr;

            __tmp____Bah_fnNames[331].n = "valueBool";
            __tmp____Bah_fnNames[331].p = valueBool;

            __tmp____Bah_fnNames[332].n = "valueOper";
            __tmp____Bah_fnNames[332].p = valueOper;

            __tmp____Bah_fnNames[333].n = "valueSendChan";
            __tmp____Bah_fnNames[333].p = valueSendChan;

            __tmp____Bah_fnNames[334].n = "valueChan";
            __tmp____Bah_fnNames[334].p = valueChan;

            __tmp____Bah_fnNames[335].n = "valueTuple";
            __tmp____Bah_fnNames[335].p = valueTuple;

            __tmp____Bah_fnNames[336].n = "isSmallValue";
            __tmp____Bah_fnNames[336].p = isSmallValue;

            __tmp____Bah_fnNames[337].n = "isValue";
            __tmp____Bah_fnNames[337].p = isValue;

            __tmp____Bah_fnNames[338].n = "parseFnDeclare";
            __tmp____Bah_fnNames[338].p = parseFnDeclare;

            __tmp____Bah_fnNames[339].n = "parseCapture";
            __tmp____Bah_fnNames[339].p = parseCapture;

            __tmp____Bah_fnNames[340].n = "declareFunc";
            __tmp____Bah_fnNames[340].p = declareFunc;

            __tmp____Bah_fnNames[341].n = "declareVar";
            __tmp____Bah_fnNames[341].p = declareVar;

            __tmp____Bah_fnNames[342].n = "declareAll";
            __tmp____Bah_fnNames[342].p = declareAll;

            __tmp____Bah_fnNames[343].n = "memErrHandle";
            __tmp____Bah_fnNames[343].p = memErrHandle;

            __tmp____Bah_fnNames[344].n = "main";
            __tmp____Bah_fnNames[344].p = main;

        __Bah_fnNames->data = __tmp____Bah_fnNames;
        __Bah_fnNames->length = 345;
        
    };
    