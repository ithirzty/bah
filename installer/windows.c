//COMPILE WITH: 'x86_64-w64-mingw32-gcc -I "/opt/bah/libs/windows/include/" -L "/opt/bah/libs/windows/" ../installer/windows.c -static -O1 -w  -l:gc.a -lpthread -lm'

    void __BAH_init();
    #define noCheck(v) v
    #define array(type)	    struct{	    type *data;     unsigned long int length;     unsigned long int realLength;     unsigned long int elemSize;     }
    typedef array(char*)* __BAH_ARR_TYPE_cpstring;
    long int __BAH__main(__BAH_ARR_TYPE_cpstring);
    
            #include <gc.h>
            #include <string.h>
            __BAH_ARR_TYPE_cpstring argsToArr(char** a,long int l);
            int main(int argc, char ** argv) {
            GC_INIT();
            __BAH_init();
            long int r =  __BAH__main(argsToArr(argv, argc));
            return r;
            };
            #define main(v) __BAH__main(v)
            #include <signal.h>
#include <string.h>
void __BAH_panic(char * e,char * l);
char * __Bah_safe_string(char * s);
char * cpstringSubsitute(char * s,long int i,long int l);

#line 17 "/opt/bah/builtin.bah"
#define null (void *)0

#line 19 "/opt/bah/builtin.bah"
#define true (char)1

#line 20 "/opt/bah/builtin.bah"
#define false (char)0

#line 22 "/opt/bah/builtin.bah"
#define cpstringLenSize 4

#line 29 "/opt/bah/builtin.bah"
char* cStr(char * s){

#line 30 "/opt/bah/builtin.bah"
if (((void *)s==null)) {

#line 31 "/opt/bah/builtin.bah"
return null;
}

#line 33 "/opt/bah/builtin.bah"
return (char*)((long int)s+cpstringLenSize);
};

#line 38 "/opt/bah/builtin.bah"
long int __bah_strcmp(char * a,char * b){

#line 39 "/opt/bah/builtin.bah"
long int ai = a;

#line 40 "/opt/bah/builtin.bah"
long int bi = b;

#line 41 "/opt/bah/builtin.bah"
if ((ai*bi==0)) {

#line 42 "/opt/bah/builtin.bah"
return 1;
}

#line 44 "/opt/bah/builtin.bah"
return strcmp(cStr(a),cStr(b));
};

#line 47 "/opt/bah/builtin.bah"
#define strcmp __bah_strcmp

#line 51 "/opt/bah/builtin.bah"
long int Cstrlen(char* s){

#line 52 "/opt/bah/builtin.bah"
if ((s==null)) {

#line 53 "/opt/bah/builtin.bah"
return 0;
}

#line 55 "/opt/bah/builtin.bah"
return strlen(s);
};

#line 58 "/opt/bah/builtin.bah"
unsigned int __bah_strlenSTR(void * s){

#line 59 "/opt/bah/builtin.bah"
if ((s==null)) {

#line 60 "/opt/bah/builtin.bah"
return 0;
}

#line 62 "/opt/bah/builtin.bah"
unsigned int* i = s;

#line 63 "/opt/bah/builtin.bah"
return *i;
};

#line 66 "/opt/bah/builtin.bah"
#define strlen __bah_strlenSTR
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
unsigned long int len(void * a);

#line 80 "/opt/bah/builtin.bah"
void print(char * s){

#line 81 "/opt/bah/builtin.bah"
write((void *)1,cStr(s),strlen(s));
};
void __BAH_memcpy(char * dest,char * source,long int l);

#line 86 "/opt/bah/builtin.bah"
#define memcpy __BAH_memcpy
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>

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
unsigned long int len(void * a){

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
#include <gc.h>

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

#line 97 "/opt/bah/memory.bah"
#define PROT_READ 2

#line 98 "/opt/bah/memory.bah"
#define PROT_READWRITE 4

#line 100 "/opt/bah/memory.bah"
void * GLOBAL_MAPPED_MEMORY_FILE;

#line 126 "/opt/bah/memory.bah"
void * sharedMemory(long int size){

#line 127 "/opt/bah/memory.bah"
if ((size==0)) {

#line 128 "/opt/bah/memory.bah"
size = 4096;
}

#line 137 "/opt/bah/memory.bah"
if ((GLOBAL_MAPPED_MEMORY_FILE==null)) {

#line 138 "/opt/bah/memory.bah"
GLOBAL_MAPPED_MEMORY_FILE = CreateFileMapping(-1,0,PROT_READWRITE,0,size,cStr("\021\0\0\0""Global\\BahFileMap"));
}

#line 140 "/opt/bah/memory.bah"
if (__builtin_expect((GLOBAL_MAPPED_MEMORY_FILE==null), 0)) {

#line 141 "/opt/bah/memory.bah"
printf(cStr("\046\0\0\0""sharedMemory: could not make map file."));

#line 142 "/opt/bah/memory.bah"
exit(1);
}

#line 144 "/opt/bah/memory.bah"
void * r = MapViewOfFile(GLOBAL_MAPPED_MEMORY_FILE,FILE_MAP_ALL_ACCESS,0,0,size);

#line 146 "/opt/bah/memory.bah"
return r;
};

#line 152 "/opt/bah/memory.bah"
void closeSharedMemory(){

#line 153 "/opt/bah/memory.bah"
CloseHandle(GLOBAL_MAPPED_MEMORY_FILE);
};

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
typedef array(char)* __BAH_ARR_TYPE_char;
__BAH_ARR_TYPE_char ser(void * a);

#line 181 "/opt/bah/memory.bah"
__BAH_ARR_TYPE_char __serialize(void * a,long int s){

#line 182 "/opt/bah/memory.bah"
char * r = memoryAlloc(s+9);

#line 183 "/opt/bah/memory.bah"
memcpy(cStr(r),&s,8);

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

#line 214 "/opt/bah/memory.bah"
char * memoryAllocSTR(long int s){

#line 215 "/opt/bah/memory.bah"
char * r = memoryAlloc(s+cpstringLenSize);

#line 216 "/opt/bah/memory.bah"
unsigned int* ln = r;

#line 217 "/opt/bah/memory.bah"
*ln = (s-1);

#line 218 "/opt/bah/memory.bah"
r[s-1]=0;

#line 220 "/opt/bah/memory.bah"
return r;
};

#line 226 "/opt/bah/memory.bah"
void delete(void * a,long int i){

#line 227 "/opt/bah/memory.bah"
array(void *)* arr = (array(void *)*)a;

#line 228 "/opt/bah/memory.bah"
unsigned long int length = len(arr);

#line 229 "/opt/bah/memory.bah"
if ((i>=length)||(i<0)) {

#line 230 "/opt/bah/memory.bah"
return;
}

#line 232 "/opt/bah/memory.bah"
if ((length==1)) {

#line 233 "/opt/bah/memory.bah"
arr->length=0;

#line 234 "/opt/bah/memory.bah"
return;
}

#line 236 "/opt/bah/memory.bah"
long int elemSize = arr->elemSize;

#line 237 "/opt/bah/memory.bah"
char* data = arr->data;

#line 238 "/opt/bah/memory.bah"
void * destOffset = elemSize*i;

#line 239 "/opt/bah/memory.bah"
++i;

#line 240 "/opt/bah/memory.bah"
void * offset = elemSize*i;

#line 241 "/opt/bah/memory.bah"
char* src = (long int)data+(long int)offset;

#line 242 "/opt/bah/memory.bah"
char* dest = (long int)data+(long int)destOffset;

#line 243 "/opt/bah/memory.bah"
unsigned long int rightNB = length-(i-1);

#line 244 "/opt/bah/memory.bah"
memmove(dest,src,rightNB*elemSize);

#line 245 "/opt/bah/memory.bah"
arr->length=length-1;
};

#line 250 "/opt/bah/memory.bah"
void deleteRange(void * a,long int from,long int to){

#line 251 "/opt/bah/memory.bah"
if ((from==to)) {

#line 252 "/opt/bah/memory.bah"
delete(a,from);

#line 253 "/opt/bah/memory.bah"
return;
}

#line 256 "/opt/bah/memory.bah"
array(void *)* arr = (array(void *)*)a;

#line 257 "/opt/bah/memory.bah"
unsigned long int length = len(arr);

#line 259 "/opt/bah/memory.bah"
long int elemSize = arr->elemSize;

#line 260 "/opt/bah/memory.bah"
char* data = arr->data;

#line 261 "/opt/bah/memory.bah"
long int size = elemSize*(to-from);

#line 262 "/opt/bah/memory.bah"
void * dest = (long int)data+elemSize*from;

#line 263 "/opt/bah/memory.bah"
void * src = (long int)dest+size+elemSize;

#line 264 "/opt/bah/memory.bah"
unsigned long int rightNB = length-to;

#line 265 "/opt/bah/memory.bah"
memmove(dest,src,rightNB*elemSize);

#line 266 "/opt/bah/memory.bah"
arr->length=length-(to-from+1);
};

#line 271 "/opt/bah/memory.bah"
char * arrToStr(__BAH_ARR_TYPE_char arr){

#line 272 "/opt/bah/memory.bah"
unsigned long int strLen = len(arr);

#line 273 "/opt/bah/memory.bah"
if ((len(arr)>0)&&(arr->data[len(arr)-1]==null)) {

#line 274 "/opt/bah/memory.bah"
--strLen;
}

#line 276 "/opt/bah/memory.bah"
char * str = memoryAllocSTR(strLen+1);

#line 277 "/opt/bah/memory.bah"
memcpy(cStr(str),arr->data,strLen);

#line 278 "/opt/bah/memory.bah"
unsigned int* ln = str;

#line 279 "/opt/bah/memory.bah"
*ln = strLen;

#line 280 "/opt/bah/memory.bah"
return str;
};

#line 284 "/opt/bah/memory.bah"
__BAH_ARR_TYPE_char strToArr(char * str){

#line 285 "/opt/bah/memory.bah"
unsigned long int strLen = strlen(str);

#line 286 "/opt/bah/memory.bah"
array(char)* arr = memoryAlloc(sizeof(array(char)));

arr->length = 0;
arr->elemSize = sizeof(char);

#line 287 "/opt/bah/memory.bah"
arr->data=memoryAlloc(strLen+1);

#line 288 "/opt/bah/memory.bah"
memcpy(arr->data,cStr(str),strLen);

#line 289 "/opt/bah/memory.bah"
arr->length=strLen;

#line 291 "/opt/bah/memory.bah"
return arr;
};
char * cpstringSubsitute(char * s,long int i,long int l);

#line 299 "/opt/bah/memory.bah"
void strTrimLeft(char ** s,long int i){

#line 300 "/opt/bah/memory.bah"
char * rs = *s;

#line 301 "/opt/bah/memory.bah"
*s = cpstringSubsitute(rs, i, strlen(rs));
};

#line 305 "/opt/bah/memory.bah"
void strTrimRight(char ** s,long int i){

#line 306 "/opt/bah/memory.bah"
char * rs = *s;

#line 307 "/opt/bah/memory.bah"
*s = cpstringSubsitute(rs, 0, strlen(rs)-i);
};

#line 310 "/opt/bah/memory.bah"
#define __bah_memory_realloc memoryRealloc

#line 311 "/opt/bah/memory.bah"
#define __bah_memory_str memoryAllocSTR

#line 96 "/opt/bah/builtin.bah"
char * buffToStr(char* b){

#line 97 "/opt/bah/builtin.bah"
long int l = Cstrlen((void *)b);

#line 98 "/opt/bah/builtin.bah"
char * s = memoryAllocSTR(l+1);

#line 99 "/opt/bah/builtin.bah"
memcpy(cStr(s),b,l);

#line 100 "/opt/bah/builtin.bah"
unsigned int* ln = s;

#line 101 "/opt/bah/builtin.bah"
*ln = l;

#line 102 "/opt/bah/builtin.bah"
return s;
};

#line 106 "/opt/bah/builtin.bah"
typedef array(void *)* __BAH_ARR_TYPE_ptr;
void __Bah_realocate_arr(__BAH_ARR_TYPE_ptr arr,unsigned int nLength){

#line 107 "/opt/bah/builtin.bah"
if ((nLength<arr->length)) {

#line 108 "/opt/bah/builtin.bah"
return;
}

#line 110 "/opt/bah/builtin.bah"
if ((nLength>=arr->realLength)) {

#line 111 "/opt/bah/builtin.bah"
if ((arr->realLength!=0)) {

#line 112 "/opt/bah/builtin.bah"
arr->realLength*=2;
}

#line 113 "/opt/bah/builtin.bah"
else {

#line 114 "/opt/bah/builtin.bah"
arr->realLength=50;
}

#line 116 "/opt/bah/builtin.bah"
void * newPtr = memoryRealloc(arr->data,(long int)arr->realLength*(long int)arr->elemSize);

#line 117 "/opt/bah/builtin.bah"
arr->data=newPtr;
}

#line 122 "/opt/bah/builtin.bah"
arr->length=arr->length+1;

#line 123 "/opt/bah/builtin.bah"
return;
};

#line 126 "/opt/bah/builtin.bah"
__BAH_ARR_TYPE_cpstring argsToArr(char** a,long int l){

#line 127 "/opt/bah/builtin.bah"
array(char *)* r = memoryAlloc(sizeof(array(char *)));

r->length = 0;
r->elemSize = sizeof(char *);

#line 128 "/opt/bah/builtin.bah"
allocateArray(r,l);

#line 129 "/opt/bah/builtin.bah"
register long int i = 0;

#line 129 "/opt/bah/builtin.bah"
for (; (i<l); 
#line 129 "/opt/bah/builtin.bah"
++i) {

#line 130 "/opt/bah/builtin.bah"
char** sp = (char**)((long int)a+i*sizeof(char*));

#line 131 "/opt/bah/builtin.bah"
char* s = *sp;

#line 132 "/opt/bah/builtin.bah"

    unsigned int ____BAH_COMPILER_VAR_0 = i;
    __Bah_realocate_arr(r, ____BAH_COMPILER_VAR_0);
    r->data[____BAH_COMPILER_VAR_0] = buffToStr(s);
};

#line 134 "/opt/bah/builtin.bah"
return r;
};

#line 137 "/opt/bah/builtin.bah"
char * cStrToBah(char* s){

#line 138 "/opt/bah/builtin.bah"
if ((s==null)) {

#line 139 "/opt/bah/builtin.bah"
return null;
}

#line 141 "/opt/bah/builtin.bah"
long int l = Cstrlen((void *)s);

#line 142 "/opt/bah/builtin.bah"
char * nstr = memoryAllocSTR(l+1);

#line 143 "/opt/bah/builtin.bah"
unsigned int* ln = nstr;

#line 144 "/opt/bah/builtin.bah"
*ln = l;

#line 145 "/opt/bah/builtin.bah"
memcpy(cStr(nstr),s,l);

#line 146 "/opt/bah/builtin.bah"
return nstr;
};

#line 150 "/opt/bah/builtin.bah"
char * __Bah_multiple_concat(char ** b,unsigned int l){

#line 151 "/opt/bah/builtin.bah"
unsigned int* lens = alloca(l*sizeof(unsigned int));

#line 152 "/opt/bah/builtin.bah"
unsigned int tot = 0;

#line 153 "/opt/bah/builtin.bah"
int offset = 0;

#line 156 "/opt/bah/builtin.bah"
register long int i = 0;

#line 156 "/opt/bah/builtin.bah"
for (; (i<l); 
#line 156 "/opt/bah/builtin.bah"
++i) {

#line 157 "/opt/bah/builtin.bah"
unsigned long int sl = strlen((char *)b[i]);

#line 158 "/opt/bah/builtin.bah"
tot = tot+sl;

#line 159 "/opt/bah/builtin.bah"
lens[i]=sl;
};

#line 163 "/opt/bah/builtin.bah"
char * r = memoryAllocSTR(tot+1);

#line 166 "/opt/bah/builtin.bah"
i = 0;

#line 166 "/opt/bah/builtin.bah"
for (; (i<l); 
#line 166 "/opt/bah/builtin.bah"
++i) {

#line 167 "/opt/bah/builtin.bah"
memcpy((void *)((long int)r+offset+cpstringLenSize),b[i]+cpstringLenSize,lens[i]);

#line 168 "/opt/bah/builtin.bah"
offset = offset+((long int)lens[i]);
};

#line 171 "/opt/bah/builtin.bah"
unsigned int* ln = r;

#line 172 "/opt/bah/builtin.bah"
*ln = tot;

#line 174 "/opt/bah/builtin.bah"
return r;
};

#line 187 "/opt/bah/builtin.bah"
char * concatCPSTRING(char * a,char * b){

#line 188 "/opt/bah/builtin.bah"
unsigned long int lenA = strlen(a);

#line 189 "/opt/bah/builtin.bah"
unsigned long int lenB = strlen(b);

#line 190 "/opt/bah/builtin.bah"
char * r = memoryAlloc(lenA+lenB+1);

#line 191 "/opt/bah/builtin.bah"
strncpy(cStr(r),cStr(a),lenA);

#line 192 "/opt/bah/builtin.bah"
strcat(cStr(r),cStr(b));

#line 193 "/opt/bah/builtin.bah"
return r;
};

#line 198 "/opt/bah/builtin.bah"
char * __STR(char * a){

#line 199 "/opt/bah/builtin.bah"
unsigned long int lenA = strlen(a);

#line 200 "/opt/bah/builtin.bah"
char * r = memoryAllocSTR(lenA+1);

#line 201 "/opt/bah/builtin.bah"
memcpy(cStr(r),cStr(a),lenA);

#line 202 "/opt/bah/builtin.bah"
unsigned int* ln = r;

#line 203 "/opt/bah/builtin.bah"
*ln = lenA;

#line 204 "/opt/bah/builtin.bah"
return r;
};

#line 208 "/opt/bah/builtin.bah"
void * cArr(void * arr){

#line 209 "/opt/bah/builtin.bah"
array(void*)*a=arr;

#line 210 "/opt/bah/builtin.bah"
return a->data;
};

#line 215 "/opt/bah/builtin.bah"
char __checkString(char * s,char * l){

#line 217 "/opt/bah/builtin.bah"
if (__builtin_expect(((void *)s==null), 0)) {

#line 218 "/opt/bah/builtin.bah"
char** ____BAH_COMPILER_VAR_1 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1[2] = "\013\0\0\0"") is null \n";____BAH_COMPILER_VAR_1[1] = l;____BAH_COMPILER_VAR_1[0] = "\012\0\0\0""cpstring (";char * ____BAH_COMPILER_VAR_2 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1, 3);print(____BAH_COMPILER_VAR_2);

#line 219 "/opt/bah/builtin.bah"
exit(1);
}

#line 222 "/opt/bah/builtin.bah"
return true;
};
#include <pthread.h>

#line 25 "/opt/bah/thread.bah"
#define __thread_create pthread_create

#line 26 "/opt/bah/thread.bah"
#define __thread_join pthread_join

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
struct mutexCondition ____BAH_COMPILER_VAR_3 = {};
struct mutexCondition m = ____BAH_COMPILER_VAR_3;

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
struct mutex ____BAH_COMPILER_VAR_4 = {};
struct mutex m = ____BAH_COMPILER_VAR_4;

#line 151 "/opt/bah/thread.bah"
mutex__init(&m);

#line 152 "/opt/bah/thread.bah"
return m;
};

#line 2 "/opt/bah/queue.bah"
struct queueNode {
long int key;
void * data;
struct queueNode* next;
struct queueNode* prev;
};

#line 16 "/opt/bah/queue.bah"
struct queue {
long int length;
struct queueNode* head;
struct queueNode* end;
};
void queue__insert(struct queue* this,void * data){

#line 23 "/opt/bah/queue.bah"
struct queueNode* ____BAH_COMPILER_VAR_5 = memoryAlloc(sizeof(struct queueNode));
____BAH_COMPILER_VAR_5->key = this->length;
____BAH_COMPILER_VAR_5->data = data;
____BAH_COMPILER_VAR_5->prev = this->end;
struct queueNode* node = ____BAH_COMPILER_VAR_5;

#line 30 "/opt/bah/queue.bah"
++this->length;

#line 31 "/opt/bah/queue.bah"
if ((this->end==null)) {

#line 32 "/opt/bah/queue.bah"
this->head = node;

#line 33 "/opt/bah/queue.bah"
this->end = this->head;
}

#line 34 "/opt/bah/queue.bah"
else {

#line 35 "/opt/bah/queue.bah"
this->end->next = node;

#line 36 "/opt/bah/queue.bah"
this->end = node;
}
};
void queue__delete(struct queue* this,long int key){

#line 42 "/opt/bah/queue.bah"
if ((this->length==0)) {

#line 43 "/opt/bah/queue.bah"
return;
}

#line 45 "/opt/bah/queue.bah"
struct queueNode* current = this->head;

#line 46 "/opt/bah/queue.bah"
struct queueNode* previous= null;

#line 47 "/opt/bah/queue.bah"
while ((current->key!=key)) {

#line 48 "/opt/bah/queue.bah"
if ((current->next==null)) {

#line 49 "/opt/bah/queue.bah"
return;
}

#line 51 "/opt/bah/queue.bah"
previous = current;

#line 52 "/opt/bah/queue.bah"
current = current->next;
};

#line 54 "/opt/bah/queue.bah"
if ((current==this->head)) {

#line 55 "/opt/bah/queue.bah"
this->head = current->next;
}

#line 56 "/opt/bah/queue.bah"
else {

#line 57 "/opt/bah/queue.bah"
previous->next = current->next;
}

#line 59 "/opt/bah/queue.bah"
this->length = this->length-1;
};
void * queue__get(struct queue* this,long int key){

#line 64 "/opt/bah/queue.bah"
long int z = 0;

#line 65 "/opt/bah/queue.bah"
void * zp = (void *)z;

#line 66 "/opt/bah/queue.bah"
if ((this->length==0)) {

#line 67 "/opt/bah/queue.bah"
return zp;
}

#line 70 "/opt/bah/queue.bah"
struct queueNode* ptr = this->head;

#line 71 "/opt/bah/queue.bah"
while ((ptr->key!=key)) {

#line 72 "/opt/bah/queue.bah"
if ((ptr->next==null)) {

#line 73 "/opt/bah/queue.bah"
return zp;
}

#line 75 "/opt/bah/queue.bah"
ptr = ptr->next;
};

#line 78 "/opt/bah/queue.bah"
void * data = ptr->data;

#line 79 "/opt/bah/queue.bah"
return data;
};
void queue__set(struct queue* this,long int key,void * data){

#line 84 "/opt/bah/queue.bah"
queue__delete(this,key);

#line 86 "/opt/bah/queue.bah"
struct queueNode* ____BAH_COMPILER_VAR_6 = memoryAlloc(sizeof(struct queueNode));
struct queueNode* node = ____BAH_COMPILER_VAR_6;

#line 87 "/opt/bah/queue.bah"
node->key = key;

#line 88 "/opt/bah/queue.bah"
node->data = data;

#line 89 "/opt/bah/queue.bah"
node->next = this->head;

#line 91 "/opt/bah/queue.bah"
this->length = this->length+1;

#line 92 "/opt/bah/queue.bah"
this->head = node;
};
void * queue__pop(struct queue* this){

#line 99 "/opt/bah/queue.bah"
if ((this->head==null)) {

#line 100 "/opt/bah/queue.bah"
return null;
}

#line 102 "/opt/bah/queue.bah"
void * data = this->head->data;

#line 103 "/opt/bah/queue.bah"
this->head = this->head->next;

#line 104 "/opt/bah/queue.bah"
if ((this->head==null)) {

#line 105 "/opt/bah/queue.bah"
this->end = null;
}

#line 107 "/opt/bah/queue.bah"
--this->length;

#line 109 "/opt/bah/queue.bah"
return data;
};
void queue__clear(struct queue* this){

#line 114 "/opt/bah/queue.bah"
this->head = (void *)0;

#line 115 "/opt/bah/queue.bah"
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
struct channel* ____BAH_COMPILER_VAR_7 = memoryAlloc(sizeof(struct channel));
____BAH_COMPILER_VAR_7->cap = -1;
struct channel* c = ____BAH_COMPILER_VAR_7;

#line 99 "/opt/bah/channel.bah"
pthread_mutex_init(&c->m_mut,0);

#line 100 "/opt/bah/channel.bah"
pthread_cond_init(&c->w_cond,0);

#line 101 "/opt/bah/channel.bah"
pthread_cond_init(&c->r_cond,0);

#line 102 "/opt/bah/channel.bah"
struct queue* ____BAH_COMPILER_VAR_8 = memoryAlloc(sizeof(struct queue));
c->queue = ____BAH_COMPILER_VAR_8;

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

#line 226 "/opt/bah/builtin.bah"
struct channel * __BAH_panic_chan;

#line 230 "/opt/bah/builtin.bah"
void __Bah_common_panic(char * e){

#line 231 "/opt/bah/builtin.bah"
if (__builtin_expect(strlen(e), 0)) {

#line 232 "/opt/bah/builtin.bah"
print(e);

#line 233 "/opt/bah/builtin.bah"
print("\01\0\0\0""\n");

#line 234 "/opt/bah/builtin.bah"
cleanShutDown();
}
};

#line 238 "/opt/bah/builtin.bah"
#define panic __Bah_common_panic

#line 240 "/opt/bah/builtin.bah"
struct __Bah_fnName_mapper {
void * p;
char * n;
};

#line 245 "/opt/bah/builtin.bah"
array(struct __Bah_fnName_mapper)* __Bah_fnNames;

#line 248 "/opt/bah/builtin.bah"
void __Bah_fnNames_append(struct __Bah_fnName_mapper fnn){

#line 249 "/opt/bah/builtin.bah"

    unsigned int ____BAH_COMPILER_VAR_9 = len(__Bah_fnNames);
    __Bah_realocate_arr(__Bah_fnNames, ____BAH_COMPILER_VAR_9);
    __Bah_fnNames->data[____BAH_COMPILER_VAR_9] = fnn;
};

#line 261 "/opt/bah/builtin.bah"
char * fastExec(char * s){

#line 262 "/opt/bah/builtin.bah"
void * hdl = popen(cStr(s),cStr("\01\0\0\0""r"));

#line 264 "/opt/bah/builtin.bah"
char ____BAH_COMPILER_VAR_10[1024];char* buff = ____BAH_COMPILER_VAR_10;

#line 265 "/opt/bah/builtin.bah"
char * response = memoryAllocSTR(1);

#line 266 "/opt/bah/builtin.bah"
void * res = (void *)response;

#line 267 "/opt/bah/builtin.bah"
long int i = 0;

#line 267 "/opt/bah/builtin.bah"
for (; (res!=null); 
#line 267 "/opt/bah/builtin.bah"
++i) {

#line 268 "/opt/bah/builtin.bah"
memset(buff,0,1024);

#line 269 "/opt/bah/builtin.bah"
res = fgets((char*)buff,1023,hdl);

#line 270 "/opt/bah/builtin.bah"
if ((res==null)||(res==(void *)-1)) {

#line 271 "/opt/bah/builtin.bah"
break;
}

#line 273 "/opt/bah/builtin.bah"
response = memoryRealloc(response,(i+1)*1023);

#line 274 "/opt/bah/builtin.bah"
unsigned int* ln = response;

#line 275 "/opt/bah/builtin.bah"
*ln = (i)*1023+Cstrlen((void *)buff);

#line 276 "/opt/bah/builtin.bah"
memcpy((void *)((long int)response+cpstringLenSize+i*1023),buff,1024);
};

#line 279 "/opt/bah/builtin.bah"
pclose(hdl);

#line 280 "/opt/bah/builtin.bah"
return response;
};

#line 284 "/opt/bah/builtin.bah"
void __BAH_panic(char * e,char * line){

#line 285 "/opt/bah/builtin.bah"
if ((__BAH_panic_chan!=null)) {

#line 286 "/opt/bah/builtin.bah"
channel__send(__BAH_panic_chan, e);

#line 287 "/opt/bah/builtin.bah"
return;
}

#line 290 "/opt/bah/builtin.bah"
char** ____BAH_COMPILER_VAR_11 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_11[4] = "\01\0\0\0""\n";____BAH_COMPILER_VAR_11[3] = e;____BAH_COMPILER_VAR_11[2] = "\03\0\0\0""): ";____BAH_COMPILER_VAR_11[1] = line;____BAH_COMPILER_VAR_11[0] = "\07\0\0\0""panic (";char * ____BAH_COMPILER_VAR_12 =__Bah_multiple_concat(____BAH_COMPILER_VAR_11, 5);print(____BAH_COMPILER_VAR_12);

#line 339 "/opt/bah/builtin.bah"
cleanShutDown();
};

#line 342 "/opt/bah/builtin.bah"
char * (*onMemoryError)();

#line 345 "/opt/bah/builtin.bah"
void __Bah_segfault_handle(long int sig){

#line 346 "/opt/bah/builtin.bah"
char * res = "\0\0\0\0""";

#line 347 "/opt/bah/builtin.bah"
if ((onMemoryError!=null)) {

#line 348 "/opt/bah/builtin.bah"
res = onMemoryError();
}

#line 350 "/opt/bah/builtin.bah"
char** ____BAH_COMPILER_VAR_13 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_13[1] = res;____BAH_COMPILER_VAR_13[0] = "\031\0\0\0""Memory error (segfault).\n";char * ____BAH_COMPILER_VAR_14 =__Bah_multiple_concat(____BAH_COMPILER_VAR_13, 2);__BAH_panic(____BAH_COMPILER_VAR_14,"\03\0\0\0""???");
};

#line 354 "/opt/bah/builtin.bah"
char __Bah_init_segfaultHandle(){

#line 355 "/opt/bah/builtin.bah"
signal(SIGSEGV,__Bah_segfault_handle);

#line 356 "/opt/bah/builtin.bah"
return true;
};

#line 359 "/opt/bah/builtin.bah"
char __Bah_init_segfaultHandle_OK;

#line 364 "/opt/bah/builtin.bah"
char recover(char ** s){

#line 365 "/opt/bah/builtin.bah"
__BAH_panic_chan = channel();

#line 366 "/opt/bah/builtin.bah"
char * ____BAH_COMPILER_VAR_15 =channel__receive(__BAH_panic_chan);char * err = ____BAH_COMPILER_VAR_15;

#line 367 "/opt/bah/builtin.bah"
if ((s!=null)) {

#line 368 "/opt/bah/builtin.bah"
*s = err;
}

#line 370 "/opt/bah/builtin.bah"
return true;
};

#line 375 "/opt/bah/builtin.bah"
char * __Bah_safe_string(char * s){

#line 376 "/opt/bah/builtin.bah"
if (((void *)s==null)) {

#line 377 "/opt/bah/builtin.bah"
return "\05\0\0\0""(nil)";
}

#line 379 "/opt/bah/builtin.bah"
if ((strlen(s)>50)) {

#line 380 "/opt/bah/builtin.bah"
array(char)* a = strToArr(s);

#line 381 "/opt/bah/builtin.bah"

    unsigned int ____BAH_COMPILER_VAR_16 = 47;
    __Bah_realocate_arr(a, ____BAH_COMPILER_VAR_16);
    a->data[____BAH_COMPILER_VAR_16] = 46;

#line 382 "/opt/bah/builtin.bah"

    unsigned int ____BAH_COMPILER_VAR_17 = 48;
    __Bah_realocate_arr(a, ____BAH_COMPILER_VAR_17);
    a->data[____BAH_COMPILER_VAR_17] = 46;

#line 383 "/opt/bah/builtin.bah"

    unsigned int ____BAH_COMPILER_VAR_18 = 49;
    __Bah_realocate_arr(a, ____BAH_COMPILER_VAR_18);
    a->data[____BAH_COMPILER_VAR_18] = 46;

#line 384 "/opt/bah/builtin.bah"

    unsigned int ____BAH_COMPILER_VAR_19 = 50;
    __Bah_realocate_arr(a, ____BAH_COMPILER_VAR_19);
    a->data[____BAH_COMPILER_VAR_19] = (char)0;

#line 385 "/opt/bah/builtin.bah"
s = arrToStr(a);
}

#line 388 "/opt/bah/builtin.bah"
char** ____BAH_COMPILER_VAR_20 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_20[2] = "\01\0\0\0""\"";____BAH_COMPILER_VAR_20[1] = s;____BAH_COMPILER_VAR_20[0] = "\01\0\0\0""\"";char * ____BAH_COMPILER_VAR_21 =__Bah_multiple_concat(____BAH_COMPILER_VAR_20, 3);return ____BAH_COMPILER_VAR_21;
};

#line 394 "/opt/bah/builtin.bah"
char cpstringCharAt(char * s,long int i){

#line 395 "/opt/bah/builtin.bah"
char c = s[i+4];

#line 396 "/opt/bah/builtin.bah"
return c;
};

#line 400 "/opt/bah/builtin.bah"
char * cpstringSubsitute(char * s,long int i,long int l){

#line 401 "/opt/bah/builtin.bah"
long int size = l-i;

#line 402 "/opt/bah/builtin.bah"
char * ns = memoryAllocSTR(size+1);

#line 403 "/opt/bah/builtin.bah"
memcpy(cStr(ns),s+i+cpstringLenSize,size);

#line 404 "/opt/bah/builtin.bah"
return ns;
};

#line 408 "/opt/bah/builtin.bah"
void * arraySubstitute(__BAH_ARR_TYPE_ptr arr,long int i,long int l){

#line 409 "/opt/bah/builtin.bah"
long int length = l-i;

#line 410 "/opt/bah/builtin.bah"
long int offset = i*(long int)arr->elemSize;

#line 411 "/opt/bah/builtin.bah"
array(void *)* na = memoryAlloc(sizeof(array(void *)));

na->length = 0;
na->elemSize = sizeof(void *);

#line 412 "/opt/bah/builtin.bah"
na->elemSize=arr->elemSize;

#line 413 "/opt/bah/builtin.bah"
na->length=length;

#line 415 "/opt/bah/builtin.bah"
long int allocLength = length;

#line 416 "/opt/bah/builtin.bah"
if ((length>50)) {

#line 417 "/opt/bah/builtin.bah"
allocLength = allocLength+(allocLength%50);
}

#line 418 "/opt/bah/builtin.bah"
else {

#line 419 "/opt/bah/builtin.bah"
allocLength = 50;
}

#line 421 "/opt/bah/builtin.bah"
long int size = allocLength*(long int)arr->elemSize;

#line 422 "/opt/bah/builtin.bah"
long int realSize = length*(long int)arr->elemSize;

#line 423 "/opt/bah/builtin.bah"
void * data = memoryAlloc(size);

#line 424 "/opt/bah/builtin.bah"
char * oData = arr->data;

#line 425 "/opt/bah/builtin.bah"
memcpy(data,oData+offset,realSize);

#line 426 "/opt/bah/builtin.bah"
na->data=data;

#line 427 "/opt/bah/builtin.bah"
return na;
};

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
hash = ((long int)hash<<5+0)+hash+(long int)s[i+4];
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
if ((s[i+4]==null)||(this->str[i+4]!=s[i+4])) {

#line 42 "/opt/bah/map.bah"
break;
}
};

#line 45 "/opt/bah/map.bah"
if ((i==this->strL)&&(s[i+4]==null)) {

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
struct mapNode* ____BAH_COMPILER_VAR_22 = memoryAlloc(sizeof(struct mapNode));
____BAH_COMPILER_VAR_22->str = k;
____BAH_COMPILER_VAR_22->strL = strlen(k);
____BAH_COMPILER_VAR_22->value = e;
struct mapNode* ne = ____BAH_COMPILER_VAR_22;

#line 123 "/opt/bah/map.bah"
if ((l!=this->strL)) {

#line 124 "/opt/bah/map.bah"
struct mapNode* ____BAH_COMPILER_VAR_23 = memoryAlloc(sizeof(struct mapNode));
____BAH_COMPILER_VAR_23->value = this->value;
____BAH_COMPILER_VAR_23->right = this->right;
____BAH_COMPILER_VAR_23->left = this->left;
____BAH_COMPILER_VAR_23->str = this->str;
____BAH_COMPILER_VAR_23->strL = this->strL;
this->right = ____BAH_COMPILER_VAR_23;

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
struct mapNode* ____BAH_COMPILER_VAR_24 = memoryAlloc(sizeof(struct mapNode));
____BAH_COMPILER_VAR_24->str = this->str;
____BAH_COMPILER_VAR_24->strL = this->strL;
____BAH_COMPILER_VAR_24->value = null;
____BAH_COMPILER_VAR_24->left = ol;
____BAH_COMPILER_VAR_24->right = ne;
this->left = ____BAH_COMPILER_VAR_24;
};
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
unsigned long int l = len(this->elems);

#line 197 "/opt/bah/map.bah"
unsigned long int i = l;

#line 197 "/opt/bah/map.bah"
for (; (i<l+nb); 
#line 197 "/opt/bah/map.bah"
++i) {

#line 198 "/opt/bah/map.bah"

    unsigned int ____BAH_COMPILER_VAR_25 = i;
    __Bah_realocate_arr(this->elems, ____BAH_COMPILER_VAR_25);
    this->elems->data[____BAH_COMPILER_VAR_25] = null;
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

    unsigned int ____BAH_COMPILER_VAR_26 = i;
    __Bah_realocate_arr(this->elems, ____BAH_COMPILER_VAR_26);
    this->elems->data[____BAH_COMPILER_VAR_26] = null;

#line 212 "/opt/bah/map.bah"

    unsigned int ____BAH_COMPILER_VAR_27 = j;
    __Bah_realocate_arr(this->elems, ____BAH_COMPILER_VAR_27);
    this->elems->data[____BAH_COMPILER_VAR_27] = e;

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
struct mapElem* ____BAH_COMPILER_VAR_28 = memoryAlloc(sizeof(struct mapElem));
____BAH_COMPILER_VAR_28->key = k;
____BAH_COMPILER_VAR_28->val = e;
struct mapElem* elem = ____BAH_COMPILER_VAR_28;

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

    unsigned int ____BAH_COMPILER_VAR_29 = j;
    __Bah_realocate_arr(this->elems, ____BAH_COMPILER_VAR_29);
    this->elems->data[____BAH_COMPILER_VAR_29] = elem;

#line 238 "/opt/bah/map.bah"
++this->length;

#line 239 "/opt/bah/map.bah"
break;
}

#line 240 "/opt/bah/map.bah"
else if ((strcmp(ce->key, k) == 0)) {

#line 241 "/opt/bah/map.bah"

    unsigned int ____BAH_COMPILER_VAR_30 = j;
    __Bah_realocate_arr(this->elems, ____BAH_COMPILER_VAR_30);
    this->elems->data[____BAH_COMPILER_VAR_30] = elem;

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

    unsigned int ____BAH_COMPILER_VAR_31 = j;
    __Bah_realocate_arr(this->elems, ____BAH_COMPILER_VAR_31);
    this->elems->data[____BAH_COMPILER_VAR_31] = null;

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
struct mapNode* ____BAH_COMPILER_VAR_32 = memoryAlloc(sizeof(struct mapNode));
____BAH_COMPILER_VAR_32->str = k;
____BAH_COMPILER_VAR_32->strL = strlen(k);
____BAH_COMPILER_VAR_32->value = e;
this->nodes = ____BAH_COMPILER_VAR_32;

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
struct mapNode* ____BAH_COMPILER_VAR_33 = memoryAlloc(sizeof(struct mapNode));
____BAH_COMPILER_VAR_33->str = k;
____BAH_COMPILER_VAR_33->strL = strlen(k);
____BAH_COMPILER_VAR_33->value = e;
struct mapNode* ne = ____BAH_COMPILER_VAR_33;

#line 329 "/opt/bah/map.bah"
struct mapNode* ____BAH_COMPILER_VAR_34 = memoryAlloc(sizeof(struct mapNode));
____BAH_COMPILER_VAR_34->str = "\0\0\0\0""";
____BAH_COMPILER_VAR_34->strL = 0;
____BAH_COMPILER_VAR_34->left = ne;
____BAH_COMPILER_VAR_34->right = this->nodes;
struct mapNode* nh = ____BAH_COMPILER_VAR_34;

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

    unsigned int ____BAH_COMPILER_VAR_35 = len(stack);
    __Bah_realocate_arr(stack, ____BAH_COMPILER_VAR_35);
    stack->data[____BAH_COMPILER_VAR_35] = current;

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
struct mapWrapper* ____BAH_COMPILER_VAR_36 = memoryAlloc(sizeof(struct mapWrapper));
____BAH_COMPILER_VAR_36->algo = 2;
____BAH_COMPILER_VAR_36->elems = memoryAlloc(sizeof(array(struct mapElem*)));
            ____BAH_COMPILER_VAR_36->elems->length = 0;
            ____BAH_COMPILER_VAR_36->elems->elemSize = sizeof(struct mapElem*);
            ____BAH_COMPILER_VAR_36->nbTotal = 1;
struct mapWrapper* m = ____BAH_COMPILER_VAR_36;

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

#line 434 "/opt/bah/builtin.bah"
struct strBuilder {
char * buff;
unsigned int length;
};
void strBuilder___init(struct strBuilder* this){

#line 440 "/opt/bah/builtin.bah"
this->buff = memoryAlloc(cpstringLenSize+51);

#line 441 "/opt/bah/builtin.bah"
this->length = 50;
};
void strBuilder__append(struct strBuilder* this,char c){

#line 446 "/opt/bah/builtin.bah"
unsigned int* ln = this->buff;

#line 447 "/opt/bah/builtin.bah"
unsigned int l = *ln;

#line 448 "/opt/bah/builtin.bah"
if ((l>=this->length)) {

#line 449 "/opt/bah/builtin.bah"
this->length = this->length*2;

#line 450 "/opt/bah/builtin.bah"
void * b = memoryRealloc(this->buff,this->length+cpstringLenSize+1);

#line 451 "/opt/bah/builtin.bah"
this->buff = b;

#line 452 "/opt/bah/builtin.bah"
ln = (unsigned int*)this->buff;
}

#line 454 "/opt/bah/builtin.bah"
this->buff[cpstringLenSize+l]=c;

#line 455 "/opt/bah/builtin.bah"
*ln = l+1;
};
char * strBuilder__str(struct strBuilder* this){

#line 460 "/opt/bah/builtin.bah"
return this->buff;
};
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>

#line 11 "/opt/bah/iostream.bah"
char * __Bah_iostream_stdinputBuffer;

#line 12 "/opt/bah/iostream.bah"
long int __Bah_iostream_stdinputBufferLength;

#line 15 "/opt/bah/iostream.bah"
char * stdinput(){

#line 16 "/opt/bah/iostream.bah"
char * response = "\0\0\0\0""";

#line 17 "/opt/bah/iostream.bah"
register long int nDataLength = 0;

#line 18 "/opt/bah/iostream.bah"
if ((__Bah_iostream_stdinputBufferLength>0)) {

#line 19 "/opt/bah/iostream.bah"
response = __Bah_iostream_stdinputBuffer;

#line 20 "/opt/bah/iostream.bah"
nDataLength = __Bah_iostream_stdinputBufferLength;
}

#line 21 "/opt/bah/iostream.bah"
else {

#line 22 "/opt/bah/iostream.bah"
char ____BAH_COMPILER_VAR_37[1025];char* buff = ____BAH_COMPILER_VAR_37;

#line 23 "/opt/bah/iostream.bah"
nDataLength = read((void *)0,(void *)buff,1024);

#line 24 "/opt/bah/iostream.bah"
if ((nDataLength<1024)) {

#line 25 "/opt/bah/iostream.bah"
char * tmp = memoryAllocSTR(nDataLength+1);

#line 26 "/opt/bah/iostream.bah"
memcpy(cStr(tmp),buff,nDataLength);

#line 27 "/opt/bah/iostream.bah"
char** ____BAH_COMPILER_VAR_38 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_38[1] = tmp;____BAH_COMPILER_VAR_38[0] = response;char * ____BAH_COMPILER_VAR_39 =__Bah_multiple_concat(____BAH_COMPILER_VAR_38, 2);response = ____BAH_COMPILER_VAR_39;
}

#line 28 "/opt/bah/iostream.bah"
else {

#line 29 "/opt/bah/iostream.bah"
while ((nDataLength>0)) {

#line 30 "/opt/bah/iostream.bah"
char * tmp = memoryAllocSTR(nDataLength+1);

#line 31 "/opt/bah/iostream.bah"
memcpy(cStr(tmp),buff,nDataLength);

#line 32 "/opt/bah/iostream.bah"
char** ____BAH_COMPILER_VAR_40 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_40[1] = tmp;____BAH_COMPILER_VAR_40[0] = response;char * ____BAH_COMPILER_VAR_41 =__Bah_multiple_concat(____BAH_COMPILER_VAR_40, 2);response = ____BAH_COMPILER_VAR_41;

#line 33 "/opt/bah/iostream.bah"
if ((nDataLength<1024)) {

#line 34 "/opt/bah/iostream.bah"
long int trimAmm = 1024-nDataLength;

#line 35 "/opt/bah/iostream.bah"
strTrimRight(&response,trimAmm);

#line 36 "/opt/bah/iostream.bah"
break;
}

#line 37 "/opt/bah/iostream.bah"
else {

#line 38 "/opt/bah/iostream.bah"
nDataLength = read((void *)0,(void *)buff,1024);
}
};
}
}

#line 43 "/opt/bah/iostream.bah"
if ((response[nDataLength-1+4]==(char)10)) {

#line 44 "/opt/bah/iostream.bah"
strTrimRight(&response,1);
}

#line 47 "/opt/bah/iostream.bah"
register long int i = 0;

#line 47 "/opt/bah/iostream.bah"
for (; (i<nDataLength); 
#line 47 "/opt/bah/iostream.bah"
++i) {

#line 48 "/opt/bah/iostream.bah"
if ((response[i+4]==(char)10)) {

#line 49 "/opt/bah/iostream.bah"
__Bah_iostream_stdinputBuffer = cpstringSubsitute(response, i+1, strlen(response));

#line 50 "/opt/bah/iostream.bah"
__Bah_iostream_stdinputBufferLength = nDataLength-i;

#line 51 "/opt/bah/iostream.bah"
return cpstringSubsitute(response, 0, i);
}
};

#line 55 "/opt/bah/iostream.bah"
__Bah_iostream_stdinputBuffer = "\0\0\0\0""";

#line 56 "/opt/bah/iostream.bah"
__Bah_iostream_stdinputBufferLength = 0;

#line 58 "/opt/bah/iostream.bah"
return response;
};

#line 62 "/opt/bah/iostream.bah"
void println(char * s){

#line 63 "/opt/bah/iostream.bah"
char** ____BAH_COMPILER_VAR_42 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_42[1] = "\01\0\0\0""\n";____BAH_COMPILER_VAR_42[0] = s;char * ____BAH_COMPILER_VAR_43 =__Bah_multiple_concat(____BAH_COMPILER_VAR_42, 2);write((void *)1,cStr(____BAH_COMPILER_VAR_43),strlen(s)+1);
};

#line 76 "/opt/bah/iostream.bah"
struct fileStream {
FILE* handle;
char * name;
};
long int fileStream__isValid(struct fileStream* this){

#line 82 "/opt/bah/iostream.bah"
if ((this->handle==null)) {

#line 83 "/opt/bah/iostream.bah"
return 0;
}

#line 85 "/opt/bah/iostream.bah"
return 1;
};
void fileStream__open(struct fileStream* this,char * path,char * mode){

#line 91 "/opt/bah/iostream.bah"
this->name = path;

#line 92 "/opt/bah/iostream.bah"
this->handle = fopen(cStr(path),cStr(mode));
};
void fileStream__close(struct fileStream* this){

#line 97 "/opt/bah/iostream.bah"
if ((fileStream__isValid(this)==0)) {

#line 98 "/opt/bah/iostream.bah"
return;
}

#line 100 "/opt/bah/iostream.bah"
fclose(this->handle);

#line 101 "/opt/bah/iostream.bah"
this->handle = null;
};
long int fileStream__getPos(struct fileStream* this){

#line 106 "/opt/bah/iostream.bah"
if ((fileStream__isValid(this)==0)) {

#line 107 "/opt/bah/iostream.bah"
return 0;
}

#line 109 "/opt/bah/iostream.bah"
return ftell(this->handle);
};
void fileStream__setPos(struct fileStream* this,long int i){

#line 114 "/opt/bah/iostream.bah"
if ((fileStream__isValid(this)==0)) {

#line 115 "/opt/bah/iostream.bah"
return;
}

#line 117 "/opt/bah/iostream.bah"
fseek(this->handle,i,0);
};
long int fileStream__getSize(struct fileStream* this){

#line 122 "/opt/bah/iostream.bah"
if ((fileStream__isValid(this)==0)) {

#line 123 "/opt/bah/iostream.bah"
return -1;
}

#line 125 "/opt/bah/iostream.bah"
long int oldPos = fileStream__getPos(this);

#line 126 "/opt/bah/iostream.bah"
fseek(this->handle,0,2);

#line 127 "/opt/bah/iostream.bah"
long int size = ftell(this->handle);

#line 128 "/opt/bah/iostream.bah"
fileStream__setPos(this,oldPos);

#line 129 "/opt/bah/iostream.bah"
return size;
};
void fileStream__rewind(struct fileStream* this){

#line 134 "/opt/bah/iostream.bah"
rewind(this->handle);
};
char fileStream__getChar(struct fileStream* this){

#line 139 "/opt/bah/iostream.bah"
char c = getc(this->handle);

#line 140 "/opt/bah/iostream.bah"
return c;
};
void fileStream__setChar(struct fileStream* this,char c){

#line 145 "/opt/bah/iostream.bah"
fputc(c,this->handle);
};
void fileStream__createFile(struct fileStream* this,char * path){

#line 150 "/opt/bah/iostream.bah"
fileStream__open(this,path,"\01\0\0\0""w");

#line 151 "/opt/bah/iostream.bah"
fileStream__close(this);
};
long int fileStream__writeFile(struct fileStream* this,char * content){

#line 156 "/opt/bah/iostream.bah"
if ((fileStream__isValid(this)==0)) {

#line 157 "/opt/bah/iostream.bah"
return -1;
}

#line 160 "/opt/bah/iostream.bah"
fwrite(cStr(content),strlen(content),1,this->handle);

#line 162 "/opt/bah/iostream.bah"
return 1;
};
void fileStream__writePtr(struct fileStream* this,void * a,long int s){

#line 169 "/opt/bah/iostream.bah"
fwrite(a,s,1,this->handle);
};
long int fileStream__readPtr(struct fileStream* this,void * a,long int s){

#line 176 "/opt/bah/iostream.bah"
return fread(a,s,1,this->handle);
};
char * fileStream__readContent(struct fileStream* this){

#line 181 "/opt/bah/iostream.bah"
if ((fileStream__isValid(this)==0)) {

#line 182 "/opt/bah/iostream.bah"
return "\07\0\0\0""invalid";
}

#line 185 "/opt/bah/iostream.bah"
long int sz = fileStream__getSize(this);

#line 186 "/opt/bah/iostream.bah"
char * r = memoryAllocSTR(sz+1);

#line 187 "/opt/bah/iostream.bah"
fread(cStr(r),1,sz,this->handle);

#line 188 "/opt/bah/iostream.bah"
return r;
};
__BAH_ARR_TYPE_char fileStream__readBytes(struct fileStream* this){

#line 193 "/opt/bah/iostream.bah"
array(char)* r = memoryAlloc(sizeof(array(char)));

r->length = 0;
r->elemSize = sizeof(char);

#line 194 "/opt/bah/iostream.bah"
allocateArray(r,fileStream__getSize(this));

#line 196 "/opt/bah/iostream.bah"
fileStream__readPtr(this,r->data,len(r));

#line 198 "/opt/bah/iostream.bah"
return r;
};
void fileStream__writeBytes(struct fileStream* this,__BAH_ARR_TYPE_char d){

#line 203 "/opt/bah/iostream.bah"
fileStream__writePtr(this,d->data,len(d));
};
void fileStream___end(struct fileStream* this){

#line 207 "/opt/bah/iostream.bah"
if (fileStream__isValid(this)) {

#line 208 "/opt/bah/iostream.bah"
char** ____BAH_COMPILER_VAR_44 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_44[2] = "\02\0\0\0""'.";____BAH_COMPILER_VAR_44[1] = this->name;____BAH_COMPILER_VAR_44[0] = "\047\0\0\0""iostream: warning, auto-closing file: '";char * ____BAH_COMPILER_VAR_45 =__Bah_multiple_concat(____BAH_COMPILER_VAR_44, 3);println(____BAH_COMPILER_VAR_45);

#line 209 "/opt/bah/iostream.bah"
fileStream__close(this);
}
};

#line 215 "/opt/bah/iostream.bah"

#line 234 "/opt/bah/iostream.bah"
struct fileMap {
long int handle;
long int size;
void * p;
};
__BAH_ARR_TYPE_char fileMap__open(struct fileMap* this,char * fileName){

#line 266 "/opt/bah/iostream.bah"
struct fileStream ____BAH_COMPILER_VAR_46 = {};
struct fileStream fs = ____BAH_COMPILER_VAR_46;

#line 267 "/opt/bah/iostream.bah"
fileStream__open(&fs,fileName,"\02\0\0\0""r+");

#line 268 "/opt/bah/iostream.bah"
long int iv = fileStream__isValid(&fs);

#line 269 "/opt/bah/iostream.bah"
if ((iv==1)) {

#line 270 "/opt/bah/iostream.bah"
this->handle = 0;
}

#line 271 "/opt/bah/iostream.bah"
else {

#line 272 "/opt/bah/iostream.bah"
this->handle = -1;
}

#line 274 "/opt/bah/iostream.bah"
char * file = fileStream__readContent(&fs);

#line 275 "/opt/bah/iostream.bah"
fileStream__close(&fs);

#line 277 "/opt/bah/iostream.bah"
return strToArr(file);
};
long int fileMap__isValid(struct fileMap* this){

#line 284 "/opt/bah/iostream.bah"
if ((this->handle<0)) {

#line 285 "/opt/bah/iostream.bah"
return 0;
}

#line 287 "/opt/bah/iostream.bah"
return 1;
};
void fileMap__close(struct fileMap* this){
};

#line 311 "/opt/bah/iostream.bah"

#line 320 "/opt/bah/iostream.bah"
__BAH_ARR_TYPE_cpstring listFiles(char * dir){

#line 321 "/opt/bah/iostream.bah"
array(char *)* files = memoryAlloc(sizeof(array(char *)));

files->length = 0;
files->elemSize = sizeof(char *);

#line 322 "/opt/bah/iostream.bah"
DIR* d = opendir(cStr(dir));

#line 323 "/opt/bah/iostream.bah"
struct dirent* file = readdir(d);

#line 324 "/opt/bah/iostream.bah"
for (; (file!=null); 
#line 324 "/opt/bah/iostream.bah"
file = readdir(d)) {

#line 325 "/opt/bah/iostream.bah"
unsigned long int lf = len(files);

#line 326 "/opt/bah/iostream.bah"
char * name = cStrToBah(file->d_name);

#line 327 "/opt/bah/iostream.bah"
if ((strcmp(name, "\01\0\0\0"".") == 0)||(strcmp(name, "\02\0\0\0""..") == 0)) {

#line 328 "/opt/bah/iostream.bah"
continue;
}

#line 330 "/opt/bah/iostream.bah"

    unsigned int ____BAH_COMPILER_VAR_47 = lf;
    __Bah_realocate_arr(files, ____BAH_COMPILER_VAR_47);
    files->data[____BAH_COMPILER_VAR_47] = name;
};

#line 332 "/opt/bah/iostream.bah"
closedir(d);

#line 333 "/opt/bah/iostream.bah"
return files;
};

#line 339 "/opt/bah/iostream.bah"
long int fileExists(char * path){

#line 340 "/opt/bah/iostream.bah"
long int is = access(cStr(path),0);

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
if ((stat(cStr(path),&s)!=0)) {

#line 350 "/opt/bah/iostream.bah"
return false;
}

#line 352 "/opt/bah/iostream.bah"
if (s.st_mode&(long int)S_IFDIR) {

#line 353 "/opt/bah/iostream.bah"
return true;
}

#line 355 "/opt/bah/iostream.bah"
return false;
};

#line 361 "/opt/bah/iostream.bah"
char removeFile(char * name){

#line 362 "/opt/bah/iostream.bah"
if ((remove(cStr(name))==0)) {

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
stat(cStr(name),&attr);

#line 372 "/opt/bah/iostream.bah"
return attr.st_ctime;
};

#line 381 "/opt/bah/iostream.bah"
long int __windows_mkdir(char * s,long int m){

#line 382 "/opt/bah/iostream.bah"
return mkdir(s);
};

#line 384 "/opt/bah/iostream.bah"
#define mkdir __windows_mkdir
#include <string.h>
#include <math.h>
#include <stdlib.h>

#line 16 "/opt/bah/string.bah"
void strCatOffset(char * dest,long int destLen,char * src,long int srcLen){

#line 17 "/opt/bah/string.bah"
memcpy(dest+destLen+cpstringLenSize,cStr(src),srcLen);
};

#line 21 "/opt/bah/string.bah"
char * charToString(char c){

#line 22 "/opt/bah/string.bah"
char * s = memoryAllocSTR(2);

#line 23 "/opt/bah/string.bah"
unsigned int* ln = s;

#line 24 "/opt/bah/string.bah"
*ln = 1;

#line 25 "/opt/bah/string.bah"
strncpy(cStr(s),(void *)&c,1);

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
char * strReplace(char * s,char * what,char * by){

#line 62 "/opt/bah/string.bah"
unsigned long int l = strlen(s);

#line 63 "/opt/bah/string.bah"
unsigned long int wl = strlen(what);

#line 64 "/opt/bah/string.bah"
unsigned long int bl = strlen(by);

#line 65 "/opt/bah/string.bah"
long int ind = 0;

#line 66 "/opt/bah/string.bah"
struct strBuilder ____BAH_COMPILER_VAR_48 = {};
strBuilder___init(&____BAH_COMPILER_VAR_48);
struct strBuilder r = ____BAH_COMPILER_VAR_48;

#line 67 "/opt/bah/string.bah"
register long int i = 0;

#line 67 "/opt/bah/string.bah"
for (; (i<l); 
#line 67 "/opt/bah/string.bah"
++i) {

#line 68 "/opt/bah/string.bah"
char c = s[i+4];

#line 69 "/opt/bah/string.bah"
if ((c==what[ind+4])) {

#line 70 "/opt/bah/string.bah"
++ind;

#line 71 "/opt/bah/string.bah"
if ((ind==wl)) {

#line 72 "/opt/bah/string.bah"
ind = 0;

#line 73 "/opt/bah/string.bah"
register long int j = 0;

#line 73 "/opt/bah/string.bah"
for (; (j<bl); 
#line 73 "/opt/bah/string.bah"
++j) {

#line 74 "/opt/bah/string.bah"
strBuilder__append(&r,by[j+4]);
};
}
}

#line 77 "/opt/bah/string.bah"
else {

#line 78 "/opt/bah/string.bah"
register long int j = 0;

#line 78 "/opt/bah/string.bah"
for (; (j<ind); 
#line 78 "/opt/bah/string.bah"
++j) {

#line 79 "/opt/bah/string.bah"
strBuilder__append(&r,s[i-ind+j+4]);
};

#line 81 "/opt/bah/string.bah"
ind = 0;

#line 82 "/opt/bah/string.bah"
strBuilder__append(&r,c);
}
};

#line 85 "/opt/bah/string.bah"
register long int j = 0;

#line 85 "/opt/bah/string.bah"
for (; (j<ind); 
#line 85 "/opt/bah/string.bah"
++j) {

#line 86 "/opt/bah/string.bah"
strBuilder__append(&r,s[i-ind+j+4]);
};

#line 88 "/opt/bah/string.bah"
return strBuilder__str(&r);
};

#line 92 "/opt/bah/string.bah"
struct string {
char * content;
char editable;
long int length;
};
void string__set(struct string* this,char * s){

#line 102 "/opt/bah/string.bah"
this->length = strlen(s);

#line 103 "/opt/bah/string.bah"
this->editable = false;

#line 104 "/opt/bah/string.bah"
this->content = s;
};
void string__makeEditable(struct string* this){

#line 111 "/opt/bah/string.bah"
this->editable = true;

#line 112 "/opt/bah/string.bah"
char * old = this->content;

#line 113 "/opt/bah/string.bah"
this->content = (char *)memoryAllocSTR(this->length+1);

#line 114 "/opt/bah/string.bah"
strncpy(cStr(this->content),cStr(old),this->length);
};
void string__append(struct string* this,char * s){

#line 119 "/opt/bah/string.bah"
if ((this->editable==false)) {

#line 120 "/opt/bah/string.bah"
string__makeEditable(this);
}

#line 122 "/opt/bah/string.bah"
unsigned long int sl = strlen(s);

#line 123 "/opt/bah/string.bah"
char * nc = memoryAllocSTR(sl+this->length+1);

#line 124 "/opt/bah/string.bah"
memcpy(cStr(nc),cStr(this->content),this->length);

#line 125 "/opt/bah/string.bah"
strCatOffset(nc,this->length,s,sl);

#line 126 "/opt/bah/string.bah"
this->content = nc;

#line 127 "/opt/bah/string.bah"
this->length = this->length+sl;
};
void string__prepend(struct string* this,char * s){

#line 132 "/opt/bah/string.bah"
this->editable = true;

#line 133 "/opt/bah/string.bah"
unsigned long int sl = strlen(s);

#line 134 "/opt/bah/string.bah"
long int nl = this->length+sl;

#line 135 "/opt/bah/string.bah"
char * tmpS = this->content;

#line 136 "/opt/bah/string.bah"
char * nc = memoryAllocSTR(nl+1);

#line 137 "/opt/bah/string.bah"
if (__builtin_expect((strcmp(nc, null) == 0), 0)) {

#line 138 "/opt/bah/string.bah"
__BAH_panic("\073\0\0\0""Error appending to string, possibly due to memory shortage.","\027\0\0\0""/opt/bah/string.bah:138");
}

#line 140 "/opt/bah/string.bah"
this->content = nc;

#line 141 "/opt/bah/string.bah"
strncpy(cStr(this->content),cStr(s),sl);

#line 142 "/opt/bah/string.bah"
strCatOffset(this->content,sl,tmpS,this->length);

#line 143 "/opt/bah/string.bah"
this->length = nl;
};
char string__charAt(struct string* this,long int i){

#line 148 "/opt/bah/string.bah"
return this->content[i+4];
};
long int string__compare(struct string* this,char * s){

#line 153 "/opt/bah/string.bah"
return ((long int)strcmp(this->content,s)==0);
};
char * string__str(struct string* this){

#line 158 "/opt/bah/string.bah"
return this->content;
};
void string__replace(struct string* this,char * nd,char * rl){

#line 163 "/opt/bah/string.bah"
string__set(this,strReplace(this->content,nd,rl));
};
long int string__countChar(struct string* this,char need){

#line 168 "/opt/bah/string.bah"
long int c = 0;

#line 169 "/opt/bah/string.bah"
register long int i = 0;

#line 169 "/opt/bah/string.bah"
for (; (i<this->length); 
#line 169 "/opt/bah/string.bah"
++i) {

#line 170 "/opt/bah/string.bah"
if ((string__charAt(this,i)==need)) {

#line 171 "/opt/bah/string.bah"
++c;
}
};

#line 174 "/opt/bah/string.bah"
return c;
};
long int string__count(struct string* this,char * need){

#line 179 "/opt/bah/string.bah"
if ((strlen(need)==1)) {

#line 180 "/opt/bah/string.bah"
return string__countChar(this,need[0+4]);
}

#line 182 "/opt/bah/string.bah"
register long int i = 0;

#line 183 "/opt/bah/string.bah"
long int count = 0;

#line 184 "/opt/bah/string.bah"
struct string ____BAH_COMPILER_VAR_49 = {};
struct string needle = ____BAH_COMPILER_VAR_49;

#line 185 "/opt/bah/string.bah"
string__set(&needle,need);

#line 186 "/opt/bah/string.bah"
long int countIndex = 0;

#line 187 "/opt/bah/string.bah"
while ((i<this->length)) {

#line 188 "/opt/bah/string.bah"
char c = string__charAt(this,i);

#line 189 "/opt/bah/string.bah"
char sc = string__charAt(&needle,countIndex);

#line 190 "/opt/bah/string.bah"
if ((c==sc)) {

#line 191 "/opt/bah/string.bah"
countIndex = countIndex+1;
}

#line 192 "/opt/bah/string.bah"
else {

#line 193 "/opt/bah/string.bah"
countIndex = 0;
}

#line 195 "/opt/bah/string.bah"
if ((countIndex==needle.length)) {

#line 196 "/opt/bah/string.bah"
count = count+1;

#line 197 "/opt/bah/string.bah"
countIndex = 0;
}

#line 199 "/opt/bah/string.bah"
i = i+1;
};

#line 201 "/opt/bah/string.bah"
return count;
};
long int string__hasPrefix(struct string* this,char * need){

#line 206 "/opt/bah/string.bah"
register long int i = 0;

#line 207 "/opt/bah/string.bah"
unsigned long int nl = strlen(need);

#line 208 "/opt/bah/string.bah"
if ((this->length<nl)) {

#line 209 "/opt/bah/string.bah"
return 0;
}

#line 211 "/opt/bah/string.bah"
while ((i<nl)) {

#line 212 "/opt/bah/string.bah"
char c = string__charAt(this,i);

#line 213 "/opt/bah/string.bah"
char sc = cpstringCharAt(need,i);

#line 214 "/opt/bah/string.bah"
if ((c!=sc)) {

#line 215 "/opt/bah/string.bah"
return 0;
}

#line 217 "/opt/bah/string.bah"
i = i+1;
};

#line 219 "/opt/bah/string.bah"
return 1;
};
long int string__hasSuffix(struct string* this,char * need){

#line 224 "/opt/bah/string.bah"
unsigned long int nl = strlen(need);

#line 225 "/opt/bah/string.bah"
if ((this->length<nl)) {

#line 226 "/opt/bah/string.bah"
return 0;
}

#line 228 "/opt/bah/string.bah"
register long int i = this->length-nl;

#line 229 "/opt/bah/string.bah"
long int needleIndex = 0;

#line 230 "/opt/bah/string.bah"
while ((i<this->length)) {

#line 231 "/opt/bah/string.bah"
char c = string__charAt(this,i);

#line 232 "/opt/bah/string.bah"
char sc = cpstringCharAt(need,needleIndex);

#line 233 "/opt/bah/string.bah"
if ((c!=sc)) {

#line 234 "/opt/bah/string.bah"
return 0;
}

#line 236 "/opt/bah/string.bah"
needleIndex = needleIndex+1;

#line 237 "/opt/bah/string.bah"
i = i+1;
};

#line 240 "/opt/bah/string.bah"
return 1;
};
void string__trim(struct string* this){

#line 246 "/opt/bah/string.bah"
if ((this->length==0)) {

#line 247 "/opt/bah/string.bah"
return;
}

#line 249 "/opt/bah/string.bah"
char fc = string__charAt(this,0);

#line 250 "/opt/bah/string.bah"
if ((isSpace(fc)==false)) {

#line 251 "/opt/bah/string.bah"
return;
}

#line 253 "/opt/bah/string.bah"
register long int i = 0;

#line 253 "/opt/bah/string.bah"
for (; (i<this->length); 
#line 253 "/opt/bah/string.bah"
++i) {

#line 254 "/opt/bah/string.bah"
if ((isSpace(string__charAt(this,i))==false)) {

#line 255 "/opt/bah/string.bah"
break;
}
};

#line 258 "/opt/bah/string.bah"
if ((i>0)) {

#line 259 "/opt/bah/string.bah"
this->length = this->length-i;

#line 260 "/opt/bah/string.bah"
char * tmpS = memoryAllocSTR(this->length+1);

#line 261 "/opt/bah/string.bah"
memcpy(cStr(tmpS),this->content+i,this->length+1);

#line 262 "/opt/bah/string.bah"
this->content = tmpS;

#line 263 "/opt/bah/string.bah"
this->editable = true;
}
};
void string__trimLeft(struct string* this,long int s){

#line 269 "/opt/bah/string.bah"
if ((s>this->length)) {

#line 270 "/opt/bah/string.bah"
return;
}

#line 272 "/opt/bah/string.bah"
this->content = cpstringSubsitute(this->content, s, this->length);

#line 273 "/opt/bah/string.bah"
this->editable = true;

#line 274 "/opt/bah/string.bah"
this->length = this->length-s;
};
void string__trimRight(struct string* this,long int s){

#line 279 "/opt/bah/string.bah"
if ((s>this->length)) {

#line 280 "/opt/bah/string.bah"
return;
}

#line 282 "/opt/bah/string.bah"
this->content = cpstringSubsitute(this->content, 0, this->length-s);

#line 283 "/opt/bah/string.bah"
this->editable = true;

#line 284 "/opt/bah/string.bah"
this->length = this->length-s;
};
struct string string__add(struct string* this,struct string s2){

#line 290 "/opt/bah/string.bah"
struct string ____BAH_COMPILER_VAR_50 = {};
struct string r = ____BAH_COMPILER_VAR_50;

#line 291 "/opt/bah/string.bah"
r.length = this->length+s2.length;

#line 292 "/opt/bah/string.bah"
r.content = memoryAllocSTR(r.length+1);

#line 293 "/opt/bah/string.bah"
strncpy(cStr(r.content),cStr(this->content),this->length);

#line 294 "/opt/bah/string.bah"
strCatOffset(r.content,this->length,s2.content,s2.length);

#line 295 "/opt/bah/string.bah"
return r;
};
__BAH_ARR_TYPE_char string__asArr(struct string* this){

#line 300 "/opt/bah/string.bah"
if ((this->editable==false)) {

#line 301 "/opt/bah/string.bah"
string__makeEditable(this);
}

#line 303 "/opt/bah/string.bah"
array(char)* arr = memoryAlloc(sizeof(array(char)));

arr->length = 0;
arr->elemSize = sizeof(char);

#line 304 "/opt/bah/string.bah"
arr->data=this->content+cpstringLenSize;

#line 305 "/opt/bah/string.bah"
arr->length=this->length;

#line 306 "/opt/bah/string.bah"
arr->realLength=this->length;

#line 307 "/opt/bah/string.bah"
return arr;
};
void string__resetLength(struct string* this){

#line 311 "/opt/bah/string.bah"
if ((this->editable==false)||((void *)this->content==null)) {

#line 312 "/opt/bah/string.bah"
return;
}

#line 314 "/opt/bah/string.bah"
unsigned int* ln = this->content;

#line 315 "/opt/bah/string.bah"
*ln = this->length;
};

#line 321 "/opt/bah/string.bah"
struct string string(char * s){

#line 322 "/opt/bah/string.bah"
struct string ____BAH_COMPILER_VAR_51 = {};
struct string a = ____BAH_COMPILER_VAR_51;

#line 323 "/opt/bah/string.bah"
string__set(&a,s);

#line 324 "/opt/bah/string.bah"
return a;
};

#line 328 "/opt/bah/string.bah"
char * intToStr(long int i){

#line 329 "/opt/bah/string.bah"
if ((i==0)) {

#line 330 "/opt/bah/string.bah"
return "\01\0\0\0""0";
}

#line 333 "/opt/bah/string.bah"
char ____BAH_COMPILER_VAR_52[66];char* s = ____BAH_COMPILER_VAR_52;

#line 334 "/opt/bah/string.bah"
long int ind = -1;

#line 336 "/opt/bah/string.bah"
char subZero = (i<0);

#line 338 "/opt/bah/string.bah"
if ((subZero==true)) {

#line 339 "/opt/bah/string.bah"
i = 0-i;
}

#line 342 "/opt/bah/string.bah"
for (; (i!=0); 
#line 342 "/opt/bah/string.bah"
i = i/10) {

#line 343 "/opt/bah/string.bah"
long int conv = i%10;

#line 344 "/opt/bah/string.bah"
conv = conv+48;

#line 345 "/opt/bah/string.bah"
s[ind+1] = (char)conv;

#line 346 "/opt/bah/string.bah"
++ind;
};

#line 349 "/opt/bah/string.bah"
if ((subZero==true)) {

#line 350 "/opt/bah/string.bah"
s[ind+1] = 45;

#line 351 "/opt/bah/string.bah"
++ind;
}

#line 353 "/opt/bah/string.bah"
long int ls = ind+1;

#line 354 "/opt/bah/string.bah"
i = 0;

#line 354 "/opt/bah/string.bah"
for (; (i<ls/2); 
#line 354 "/opt/bah/string.bah"
++i) {

#line 355 "/opt/bah/string.bah"
long int ii = ls-i-1;

#line 356 "/opt/bah/string.bah"
char osi = s[i];

#line 357 "/opt/bah/string.bah"
s[i] = s[ii];

#line 358 "/opt/bah/string.bah"
s[ii] = osi;
};

#line 361 "/opt/bah/string.bah"
s[ind+1] = (char)0;

#line 363 "/opt/bah/string.bah"
return buffToStr((char*)s);
};

#line 368 "/opt/bah/string.bah"
struct string intToString(long int i){

#line 369 "/opt/bah/string.bah"
struct string r = string(intToStr(i));

#line 370 "/opt/bah/string.bah"
return r;
};

#line 374 "/opt/bah/string.bah"
char * floatToStr(double f){

#line 375 "/opt/bah/string.bah"
char ____BAH_COMPILER_VAR_53[50];char* buff = ____BAH_COMPILER_VAR_53;

#line 376 "/opt/bah/string.bah"
sprintf((void *)buff,cStr("\03\0\0\0""%lf"),f);

#line 377 "/opt/bah/string.bah"
return buffToStr((char*)buff);
};

#line 381 "/opt/bah/string.bah"
long int strToInt(char * s){

#line 382 "/opt/bah/string.bah"
register long int l = strlen(s)-1;

#line 383 "/opt/bah/string.bah"
long int offset = 1;

#line 384 "/opt/bah/string.bah"
long int r = 0;

#line 385 "/opt/bah/string.bah"
long int end = 0;

#line 386 "/opt/bah/string.bah"
if ((s[0+4]==45)) {

#line 387 "/opt/bah/string.bah"
end = 1;
}

#line 389 "/opt/bah/string.bah"
for (; (l>=end); 
#line 389 "/opt/bah/string.bah"
--l) {

#line 390 "/opt/bah/string.bah"
if ((s[l+4]<48)||(s[l+4]>57)) {

#line 391 "/opt/bah/string.bah"
continue;
}

#line 393 "/opt/bah/string.bah"
r = r+(((long int)s[l+4]-48)*offset);

#line 394 "/opt/bah/string.bah"
offset = offset*10;
};

#line 396 "/opt/bah/string.bah"
if ((end==1)) {

#line 397 "/opt/bah/string.bah"
r = 0-r;
}

#line 399 "/opt/bah/string.bah"
return r;
};

#line 403 "/opt/bah/string.bah"
double strToFloat(char * s){

#line 404 "/opt/bah/string.bah"
return strtod(cStr(s),null);
};

#line 410 "/opt/bah/string.bah"
long int stringToInt(struct string s){

#line 411 "/opt/bah/string.bah"
long int i = atol(cStr(s.content));

#line 412 "/opt/bah/string.bah"
return i;
};

#line 416 "/opt/bah/string.bah"
typedef array(struct string)* __BAH_ARR_TYPE_string;
__BAH_ARR_TYPE_string splitString(struct string s,char * sep){

#line 417 "/opt/bah/string.bah"
long int sepInd = 0;

#line 418 "/opt/bah/string.bah"
long int start = 0;

#line 419 "/opt/bah/string.bah"
array(struct string)* r = memoryAlloc(sizeof(array(struct string)));

r->length = 0;
r->elemSize = sizeof(struct string);

#line 421 "/opt/bah/string.bah"
register long int i = 0;

#line 421 "/opt/bah/string.bah"
for (; (i<s.length); 
#line 421 "/opt/bah/string.bah"
++i) {

#line 422 "/opt/bah/string.bah"
char c = string__charAt(&s,i);

#line 423 "/opt/bah/string.bah"
if ((c==sep[sepInd+4])) {

#line 424 "/opt/bah/string.bah"
++sepInd;

#line 425 "/opt/bah/string.bah"
if ((sepInd==strlen(sep))) {

#line 426 "/opt/bah/string.bah"
sepInd = 0;

#line 427 "/opt/bah/string.bah"
long int end = i-strlen(sep)+1;

#line 428 "/opt/bah/string.bah"
if ((start!=end)) {

#line 429 "/opt/bah/string.bah"

    unsigned int ____BAH_COMPILER_VAR_54 = len(r);
    __Bah_realocate_arr(r, ____BAH_COMPILER_VAR_54);
    r->data[____BAH_COMPILER_VAR_54] = string(cpstringSubsitute(s.content, start, end));
}

#line 431 "/opt/bah/string.bah"
start = i+1;
}
}

#line 433 "/opt/bah/string.bah"
else {

#line 434 "/opt/bah/string.bah"
sepInd = 0;
}
};

#line 438 "/opt/bah/string.bah"
long int end = i-strlen(sep)+1;

#line 439 "/opt/bah/string.bah"
if ((start<end)) {

#line 440 "/opt/bah/string.bah"

    unsigned int ____BAH_COMPILER_VAR_55 = len(r);
    __Bah_realocate_arr(r, ____BAH_COMPILER_VAR_55);
    r->data[____BAH_COMPILER_VAR_55] = string(cpstringSubsitute(s.content, start, end));
}

#line 443 "/opt/bah/string.bah"
return r;
};

#line 447 "/opt/bah/string.bah"
struct string joinString(__BAH_ARR_TYPE_string a,char * sep){

#line 448 "/opt/bah/string.bah"
register long int i = 0;

#line 449 "/opt/bah/string.bah"
struct string s = string("\0\0\0\0""");

#line 450 "/opt/bah/string.bah"
unsigned long int max = len(a)-1;

#line 451 "/opt/bah/string.bah"
while ((i<len(a))) {

#line 452 "/opt/bah/string.bah"
struct string e = a->data[i];

#line 453 "/opt/bah/string.bah"
if ((e.length==0)) {

#line 454 "/opt/bah/string.bah"
i = i+1;

#line 455 "/opt/bah/string.bah"
continue;
}

#line 457 "/opt/bah/string.bah"
struct string tmpS = string(string__str(&e));

#line 458 "/opt/bah/string.bah"
if ((i!=max)) {

#line 459 "/opt/bah/string.bah"
string__append(&tmpS,sep);
}

#line 461 "/opt/bah/string.bah"
string__append(&s,string__str(&tmpS));

#line 462 "/opt/bah/string.bah"
i = i+1;
};

#line 464 "/opt/bah/string.bah"
return s;
};

#line 468 "/opt/bah/string.bah"
char * splitStringBefore(struct string s,char * sp){

#line 469 "/opt/bah/string.bah"
struct string sep = string(sp);

#line 470 "/opt/bah/string.bah"
if ((sep.length>=s.length)) {

#line 471 "/opt/bah/string.bah"
return "\0\0\0\0""";
}

#line 473 "/opt/bah/string.bah"
long int sepIndex = 0;

#line 474 "/opt/bah/string.bah"
long int foundIndex = 0;

#line 475 "/opt/bah/string.bah"
register long int i = 0;

#line 475 "/opt/bah/string.bah"
while ((i<s.length)) {

#line 476 "/opt/bah/string.bah"
char c = string__charAt(&s,i);

#line 477 "/opt/bah/string.bah"
char sc = string__charAt(&sep,sepIndex);

#line 478 "/opt/bah/string.bah"
if ((c==sc)) {

#line 479 "/opt/bah/string.bah"
if ((sepIndex==0)) {

#line 480 "/opt/bah/string.bah"
foundIndex = i-1;
}

#line 482 "/opt/bah/string.bah"
sepIndex = sepIndex+1;

#line 483 "/opt/bah/string.bah"
if ((sepIndex==sep.length)) {

#line 484 "/opt/bah/string.bah"
long int max = s.length-foundIndex-1;

#line 485 "/opt/bah/string.bah"
string__trimRight(&s,max);

#line 486 "/opt/bah/string.bah"
return string__str(&s);
}
}

#line 488 "/opt/bah/string.bah"
else {

#line 489 "/opt/bah/string.bah"
foundIndex = 0;

#line 490 "/opt/bah/string.bah"
sepIndex = 0;
}

#line 493 "/opt/bah/string.bah"
i = i+1;
};

#line 496 "/opt/bah/string.bah"
return "\0\0\0\0""";
};

#line 501 "/opt/bah/string.bah"
struct string toLower(struct string s){

#line 502 "/opt/bah/string.bah"
array(char)* ns = memoryAlloc(sizeof(array(char)));

ns->length = 0;
ns->elemSize = sizeof(char);

#line 503 "/opt/bah/string.bah"
register long int i = 0;

#line 503 "/opt/bah/string.bah"
while ((i<s.length)) {

#line 504 "/opt/bah/string.bah"
char c = string__charAt(&s,i);

#line 505 "/opt/bah/string.bah"
if (isUpper(c)) {

#line 506 "/opt/bah/string.bah"
c = c+(char)32;
}

#line 508 "/opt/bah/string.bah"

    unsigned int ____BAH_COMPILER_VAR_56 = len(ns);
    __Bah_realocate_arr(ns, ____BAH_COMPILER_VAR_56);
    ns->data[____BAH_COMPILER_VAR_56] = c;

#line 509 "/opt/bah/string.bah"
i = i+1;
};

#line 511 "/opt/bah/string.bah"
return string(arrToStr(ns));
};

#line 516 "/opt/bah/string.bah"
char strHasPrefix(char * s,char * need){

#line 517 "/opt/bah/string.bah"
register long int i = 0;

#line 518 "/opt/bah/string.bah"
unsigned long int nl = strlen(need);

#line 519 "/opt/bah/string.bah"
unsigned long int sl = strlen(s);

#line 520 "/opt/bah/string.bah"
if ((sl<nl)) {

#line 521 "/opt/bah/string.bah"
return false;
}

#line 523 "/opt/bah/string.bah"
while ((i<nl)) {

#line 524 "/opt/bah/string.bah"
if ((cpstringCharAt(s,i)!=cpstringCharAt(need,i))) {

#line 525 "/opt/bah/string.bah"
return false;
}

#line 527 "/opt/bah/string.bah"
i = i+1;
};

#line 529 "/opt/bah/string.bah"
return true;
};

#line 534 "/opt/bah/string.bah"
char strHasSuffix(char * s,char * need){

#line 535 "/opt/bah/string.bah"
unsigned long int sl = strlen(s);

#line 536 "/opt/bah/string.bah"
unsigned long int nl = strlen(need);

#line 537 "/opt/bah/string.bah"
if ((nl>sl)) {

#line 538 "/opt/bah/string.bah"
return false;
}

#line 540 "/opt/bah/string.bah"
unsigned long int i = sl-nl;

#line 540 "/opt/bah/string.bah"
while ((i<sl)) {

#line 541 "/opt/bah/string.bah"
if ((cpstringCharAt(s,i)!=cpstringCharAt(need,i))) {

#line 542 "/opt/bah/string.bah"
return false;
}

#line 544 "/opt/bah/string.bah"
i = i+1;
};

#line 546 "/opt/bah/string.bah"
return true;
};

#line 551 "/opt/bah/string.bah"
void strTrim(char ** s){

#line 552 "/opt/bah/string.bah"
unsigned long int l = strlen(*s);

#line 553 "/opt/bah/string.bah"
register long int i = 0;

#line 553 "/opt/bah/string.bah"
while ((i<l)) {

#line 554 "/opt/bah/string.bah"
char c = cpstringCharAt(*s,i);

#line 555 "/opt/bah/string.bah"
if ((isSpace(c)==false)) {

#line 556 "/opt/bah/string.bah"
break;
}

#line 558 "/opt/bah/string.bah"
i = i+1;
};

#line 560 "/opt/bah/string.bah"
*s = *s+i;
};

#line 565 "/opt/bah/string.bah"
long int strCount(char * src,char * needle){

#line 566 "/opt/bah/string.bah"
register long int i = 0;

#line 567 "/opt/bah/string.bah"
long int count = 0;

#line 568 "/opt/bah/string.bah"
long int countIndex = 0;

#line 569 "/opt/bah/string.bah"
unsigned long int sl = strlen(src);

#line 570 "/opt/bah/string.bah"
unsigned long int nl = strlen(needle);

#line 571 "/opt/bah/string.bah"
while ((i<sl)) {

#line 572 "/opt/bah/string.bah"
char c = cpstringCharAt(src,i);

#line 573 "/opt/bah/string.bah"
char sc = cpstringCharAt(needle,countIndex);

#line 574 "/opt/bah/string.bah"
if ((c==sc)) {

#line 575 "/opt/bah/string.bah"
countIndex = countIndex+1;
}

#line 576 "/opt/bah/string.bah"
else {

#line 577 "/opt/bah/string.bah"
countIndex = 0;
}

#line 579 "/opt/bah/string.bah"
if ((countIndex==nl)) {

#line 580 "/opt/bah/string.bah"
count = count+1;

#line 581 "/opt/bah/string.bah"
countIndex = 0;
}

#line 583 "/opt/bah/string.bah"
i = i+1;
};

#line 585 "/opt/bah/string.bah"
return count;
};

#line 4 "/opt/bah/flags.bah"
#define FLAG_TYPE_CPSTRING 0

#line 5 "/opt/bah/flags.bah"
#define FLAG_TYPE_INT 1

#line 6 "/opt/bah/flags.bah"
#define FLAG_TYPE_FLOAT 2

#line 7 "/opt/bah/flags.bah"
#define FLAG_TYPE_BOOL 3

#line 12 "/opt/bah/flags.bah"
struct flag {
char * name;
char * help;
char * content;
long int cont_int;
double cont_float;
long int isSet;
long int type;
};

#line 22 "/opt/bah/flags.bah"
struct flags {
array(struct flag*)* flags;
array(char *)* args;
};
void flags__addString(struct flags* this,char * name,char * help){

#line 28 "/opt/bah/flags.bah"
struct flag* ____BAH_COMPILER_VAR_57 = memoryAlloc(sizeof(struct flag));
struct flag* f = ____BAH_COMPILER_VAR_57;

#line 29 "/opt/bah/flags.bah"
f->name = name;

#line 30 "/opt/bah/flags.bah"
f->help = help;

#line 31 "/opt/bah/flags.bah"
f->type = FLAG_TYPE_CPSTRING;

#line 32 "/opt/bah/flags.bah"
unsigned long int lf = len(this->flags);

#line 33 "/opt/bah/flags.bah"

    unsigned int ____BAH_COMPILER_VAR_58 = lf;
    __Bah_realocate_arr(this->flags, ____BAH_COMPILER_VAR_58);
    this->flags->data[____BAH_COMPILER_VAR_58] = f;
};
void flags__addBool(struct flags* this,char * name,char * help){

#line 39 "/opt/bah/flags.bah"
struct flag* ____BAH_COMPILER_VAR_59 = memoryAlloc(sizeof(struct flag));
struct flag* f = ____BAH_COMPILER_VAR_59;

#line 40 "/opt/bah/flags.bah"
f->name = name;

#line 41 "/opt/bah/flags.bah"
f->help = help;

#line 42 "/opt/bah/flags.bah"
f->type = FLAG_TYPE_BOOL;

#line 43 "/opt/bah/flags.bah"
unsigned long int lf = len(this->flags);

#line 44 "/opt/bah/flags.bah"

    unsigned int ____BAH_COMPILER_VAR_60 = lf;
    __Bah_realocate_arr(this->flags, ____BAH_COMPILER_VAR_60);
    this->flags->data[____BAH_COMPILER_VAR_60] = f;
};
void flags__addInt(struct flags* this,char * name,char * help){

#line 49 "/opt/bah/flags.bah"
struct flag* ____BAH_COMPILER_VAR_61 = memoryAlloc(sizeof(struct flag));
struct flag* f = ____BAH_COMPILER_VAR_61;

#line 50 "/opt/bah/flags.bah"
f->name = name;

#line 51 "/opt/bah/flags.bah"
f->help = help;

#line 52 "/opt/bah/flags.bah"
f->type = FLAG_TYPE_INT;

#line 53 "/opt/bah/flags.bah"
unsigned long int lf = len(this->flags);

#line 54 "/opt/bah/flags.bah"

    unsigned int ____BAH_COMPILER_VAR_62 = lf;
    __Bah_realocate_arr(this->flags, ____BAH_COMPILER_VAR_62);
    this->flags->data[____BAH_COMPILER_VAR_62] = f;
};
void flags__addFloat(struct flags* this,char * name,char * help){

#line 59 "/opt/bah/flags.bah"
struct flag* ____BAH_COMPILER_VAR_63 = memoryAlloc(sizeof(struct flag));
struct flag* f = ____BAH_COMPILER_VAR_63;

#line 60 "/opt/bah/flags.bah"
f->name = name;

#line 61 "/opt/bah/flags.bah"
f->help = help;

#line 62 "/opt/bah/flags.bah"
f->type = FLAG_TYPE_FLOAT;

#line 63 "/opt/bah/flags.bah"
unsigned long int lf = len(this->flags);

#line 64 "/opt/bah/flags.bah"

    unsigned int ____BAH_COMPILER_VAR_64 = lf;
    __Bah_realocate_arr(this->flags, ____BAH_COMPILER_VAR_64);
    this->flags->data[____BAH_COMPILER_VAR_64] = f;
};
void flags__invalidate(struct flags* this){

#line 70 "/opt/bah/flags.bah"
print("\011\0\0\0""Usage of ");

#line 71 "/opt/bah/flags.bah"
print(this->args->data[0]);

#line 72 "/opt/bah/flags.bah"
println("\01\0\0\0"":");

#line 73 "/opt/bah/flags.bah"
register long int i = 0;

#line 73 "/opt/bah/flags.bah"
while ((i<len(this->flags))) {

#line 74 "/opt/bah/flags.bah"
struct flag* flag = this->flags->data[i];

#line 75 "/opt/bah/flags.bah"
print("\05\0\0\0""    -");

#line 76 "/opt/bah/flags.bah"
print(flag->name);

#line 77 "/opt/bah/flags.bah"
if ((flag->type==FLAG_TYPE_CPSTRING)) {

#line 78 "/opt/bah/flags.bah"
println("\011\0\0\0"" (string)");
}

#line 79 "/opt/bah/flags.bah"
else if ((flag->type==FLAG_TYPE_BOOL)) {

#line 80 "/opt/bah/flags.bah"
println("\07\0\0\0"" (bool)");
}

#line 81 "/opt/bah/flags.bah"
else if ((flag->type==FLAG_TYPE_INT)) {

#line 82 "/opt/bah/flags.bah"
println("\06\0\0\0"" (int)");
}

#line 83 "/opt/bah/flags.bah"
else if ((flag->type==FLAG_TYPE_FLOAT)) {

#line 84 "/opt/bah/flags.bah"
println("\010\0\0\0"" (float)");
}

#line 86 "/opt/bah/flags.bah"
print("\01\0\0\0""\t");

#line 87 "/opt/bah/flags.bah"
println(flag->help);

#line 88 "/opt/bah/flags.bah"
i = i+1;
};

#line 90 "/opt/bah/flags.bah"
exit(1);
};
struct flag* flags__getFlag(struct flags* this,struct string name){

#line 96 "/opt/bah/flags.bah"
register long int i = 0;

#line 96 "/opt/bah/flags.bah"
while ((i<len(this->flags))) {

#line 97 "/opt/bah/flags.bah"
struct flag* flag = this->flags->data[i];

#line 98 "/opt/bah/flags.bah"
if (string__compare(&name,flag->name)) {

#line 99 "/opt/bah/flags.bah"
return flag;
}

#line 101 "/opt/bah/flags.bah"
i = i+1;
};

#line 103 "/opt/bah/flags.bah"
struct flag* ____BAH_COMPILER_VAR_65 = memoryAlloc(sizeof(struct flag));
struct flag* z = ____BAH_COMPILER_VAR_65;

#line 104 "/opt/bah/flags.bah"
z->isSet = 0;

#line 105 "/opt/bah/flags.bah"
return z;
};
char * flags__get(struct flags* this,char * name){

#line 112 "/opt/bah/flags.bah"
struct flag* flag = flags__getFlag(this,string(name));

#line 113 "/opt/bah/flags.bah"
return flag->content;
};
long int flags__getInt(struct flags* this,char * name){

#line 119 "/opt/bah/flags.bah"
struct flag* flag = flags__getFlag(this,string(name));

#line 120 "/opt/bah/flags.bah"
if (__builtin_expect((flag->type!=FLAG_TYPE_INT), 0)) {

#line 121 "/opt/bah/flags.bah"
char** ____BAH_COMPILER_VAR_66 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_66[2] = "\015\0\0\0""' is not int.";____BAH_COMPILER_VAR_66[1] = flag->name;____BAH_COMPILER_VAR_66[0] = "\06\0\0\0""Flag '";char * ____BAH_COMPILER_VAR_67 =__Bah_multiple_concat(____BAH_COMPILER_VAR_66, 3);__BAH_panic(____BAH_COMPILER_VAR_67,"\026\0\0\0""/opt/bah/flags.bah:121");
}

#line 123 "/opt/bah/flags.bah"
return flag->cont_int;
};
double flags__getFloat(struct flags* this,char * name){

#line 129 "/opt/bah/flags.bah"
struct flag* flag = flags__getFlag(this,string(name));

#line 130 "/opt/bah/flags.bah"
if (__builtin_expect((flag->type!=FLAG_TYPE_FLOAT), 0)) {

#line 131 "/opt/bah/flags.bah"
char** ____BAH_COMPILER_VAR_68 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_68[2] = "\017\0\0\0""' is not float.";____BAH_COMPILER_VAR_68[1] = flag->name;____BAH_COMPILER_VAR_68[0] = "\06\0\0\0""Flag '";char * ____BAH_COMPILER_VAR_69 =__Bah_multiple_concat(____BAH_COMPILER_VAR_68, 3);__BAH_panic(____BAH_COMPILER_VAR_69,"\026\0\0\0""/opt/bah/flags.bah:131");
}

#line 133 "/opt/bah/flags.bah"
return flag->cont_float;
};
long int flags__isSet(struct flags* this,char * name){

#line 139 "/opt/bah/flags.bah"
struct flag* flag = flags__getFlag(this,string(name));

#line 140 "/opt/bah/flags.bah"
return flag->isSet;
};
void flags__parse(struct flags* this,__BAH_ARR_TYPE_cpstring args){

#line 146 "/opt/bah/flags.bah"
struct flag* currentFlag= null;

#line 147 "/opt/bah/flags.bah"
char isVal = false;

#line 148 "/opt/bah/flags.bah"
this->args = args;

#line 149 "/opt/bah/flags.bah"
register long int i = 1;

#line 149 "/opt/bah/flags.bah"
while ((i<len(args))) {

#line 150 "/opt/bah/flags.bah"
struct string argName = string(args->data[i]);

#line 151 "/opt/bah/flags.bah"
if ((isVal==true)) {

#line 152 "/opt/bah/flags.bah"
currentFlag->content = string__str(&argName);

#line 153 "/opt/bah/flags.bah"
if ((currentFlag->type==FLAG_TYPE_INT)) {

#line 154 "/opt/bah/flags.bah"
currentFlag->cont_int = strToInt(string__str(&argName));
}

#line 155 "/opt/bah/flags.bah"
else if ((currentFlag->type==FLAG_TYPE_FLOAT)) {

#line 156 "/opt/bah/flags.bah"
currentFlag->cont_float = strToFloat(string__str(&argName));
}

#line 158 "/opt/bah/flags.bah"
isVal = false;
}

#line 159 "/opt/bah/flags.bah"
else {

#line 160 "/opt/bah/flags.bah"
if ((string__charAt(&argName,0)!=45)) {

#line 161 "/opt/bah/flags.bah"
i = i+1;

#line 162 "/opt/bah/flags.bah"
continue;
}

#line 164 "/opt/bah/flags.bah"
string__trimLeft(&argName,1);

#line 165 "/opt/bah/flags.bah"
if (__builtin_expect(string__compare(&argName,"\04\0\0\0""help"), 0)) {

#line 166 "/opt/bah/flags.bah"
flags__invalidate(this);
}

#line 167 "/opt/bah/flags.bah"
else if (__builtin_expect(string__compare(&argName,"\01\0\0\0""h"), 0)) {

#line 168 "/opt/bah/flags.bah"
flags__invalidate(this);
}

#line 170 "/opt/bah/flags.bah"
currentFlag = flags__getFlag(this,argName);

#line 171 "/opt/bah/flags.bah"
if (__builtin_expect((currentFlag==null), 0)) {

#line 172 "/opt/bah/flags.bah"
flags__invalidate(this);
}

#line 174 "/opt/bah/flags.bah"
currentFlag->isSet = 1;

#line 175 "/opt/bah/flags.bah"
if ((currentFlag->type!=FLAG_TYPE_BOOL)) {

#line 176 "/opt/bah/flags.bah"
isVal = true;
}
}

#line 179 "/opt/bah/flags.bah"
i = i+1;
};

#line 181 "/opt/bah/flags.bah"
if ((isVal==true)) {

#line 182 "/opt/bah/flags.bah"
if (__builtin_expect((currentFlag->type!=FLAG_TYPE_BOOL), 0)) {

#line 183 "/opt/bah/flags.bah"
flags__invalidate(this);
}
}
};
#include <stdlib.h>
#include <wincrypt.h>
#include <time.h>

#line 10 "/opt/bah/time.bah"
#define TIME_MS 1000000

#line 12 "/opt/bah/time.bah"
#define TIME_S 1000000000

#line 14 "/opt/bah/time.bah"
#define TIME_MIN 60000000000

#line 18 "/opt/bah/time.bah"
struct time {
long int timestamp;
};
void time__now(struct time* this){

#line 23 "/opt/bah/time.bah"
this->timestamp = time(0);
};
char * time__format(struct time* this,char * a){

#line 30 "/opt/bah/time.bah"
long int lt = localtime(&this->timestamp);

#line 32 "/opt/bah/time.bah"
char ____BAH_COMPILER_VAR_70[1024];char* buff = ____BAH_COMPILER_VAR_70;

#line 33 "/opt/bah/time.bah"
strftime((void *)buff,1024,cStr(a),lt);

#line 34 "/opt/bah/time.bah"
return buffToStr((char*)buff);
};
long int time__since(struct time* this){

#line 39 "/opt/bah/time.bah"
long int nt = time(0);

#line 40 "/opt/bah/time.bah"
long int r = nt-this->timestamp;

#line 41 "/opt/bah/time.bah"
return r;
};

#line 45 "/opt/bah/time.bah"

#line 71 "/opt/bah/time.bah"
long int getTimeUnix(){

#line 72 "/opt/bah/time.bah"
struct timespec ____BAH_COMPILER_VAR_71 = {};
struct timespec ts = ____BAH_COMPILER_VAR_71;

#line 87 "/opt/bah/time.bah"
long int s = clock_gettime(CLOCK_REALTIME,&ts);

#line 89 "/opt/bah/time.bah"
s = ts.tv_sec*1000000000+ts.tv_nsec;

#line 90 "/opt/bah/time.bah"
return s;
};

#line 94 "/opt/bah/time.bah"

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

#line 45 "/opt/bah/rand.bah"
long int cryptoRand(){

#line 61 "/opt/bah/rand.bah"
HCRYPTPROV hp;

#line 62 "/opt/bah/rand.bah"
long int* buff = memoryAlloc(SIZE_OF_INT);

#line 63 "/opt/bah/rand.bah"
CryptGenRandom(hp,1,buff);

#line 64 "/opt/bah/rand.bah"
long int i = *buff;

#line 66 "/opt/bah/rand.bah"
return i;
};

#line 4 "/opt/bah/rope.bah"
struct rope {
char * str;
int totalLen;
struct rope* left;
struct rope* right;
};
void rope__addStr(struct rope* this,char * s,long int* off){

#line 13 "/opt/bah/rope.bah"
if ((this->left==null)&&(this->right==null)) {

#line 14 "/opt/bah/rope.bah"
long int o = *off;

#line 15 "/opt/bah/rope.bah"
memcpy(s+cpstringLenSize+o,cStr(this->str),strlen(this->str));

#line 16 "/opt/bah/rope.bah"
*off = o+strlen(this->str);

#line 17 "/opt/bah/rope.bah"
return;
}

#line 20 "/opt/bah/rope.bah"
rope__addStr(this->left,s,off);

#line 21 "/opt/bah/rope.bah"
rope__addStr(this->right,s,off);
};
unsigned int rope__getLen(struct rope* this){

#line 25 "/opt/bah/rope.bah"
if ((this->left==null)&&(this->right==null)) {

#line 26 "/opt/bah/rope.bah"
unsigned long int l = strlen(this->str);

#line 27 "/opt/bah/rope.bah"
return l;
}

#line 29 "/opt/bah/rope.bah"
return rope__getLen(this->left)+rope__getLen(this->right);
};
char * rope__toStr(struct rope* this){

#line 34 "/opt/bah/rope.bah"
unsigned int tl = rope__getLen(this);

#line 35 "/opt/bah/rope.bah"
char * s = memoryAllocSTR(tl+1);

#line 36 "/opt/bah/rope.bah"
long int off = 0;

#line 37 "/opt/bah/rope.bah"
rope__addStr(this,s,&off);

#line 38 "/opt/bah/rope.bah"
return s;
};
struct rope* rope__add(struct rope* this,struct rope* r){

#line 44 "/opt/bah/rope.bah"
struct rope* ____BAH_COMPILER_VAR_72 = memoryAlloc(sizeof(struct rope));
____BAH_COMPILER_VAR_72->left = this;
____BAH_COMPILER_VAR_72->right = r;
struct rope* n = ____BAH_COMPILER_VAR_72;

#line 48 "/opt/bah/rope.bah"
return n;
};
void rope__append(struct rope* this,struct rope* r){

#line 52 "/opt/bah/rope.bah"
struct rope* ____BAH_COMPILER_VAR_73 = memoryAlloc(sizeof(struct rope));
struct rope* l = ____BAH_COMPILER_VAR_73;

#line 53 "/opt/bah/rope.bah"
*l = *this;

#line 54 "/opt/bah/rope.bah"
this->left = l;

#line 55 "/opt/bah/rope.bah"
this->right = r;

#line 56 "/opt/bah/rope.bah"
this->str = "\0\0\0\0""";
};

#line 63 "/opt/bah/rope.bah"
long int ropeSet(struct rope* r,char * a){

#line 64 "/opt/bah/rope.bah"
r->str = a;

#line 65 "/opt/bah/rope.bah"
r->left = null;

#line 66 "/opt/bah/rope.bah"
r->right = null;

#line 67 "/opt/bah/rope.bah"
return 0;
};

#line 71 "/opt/bah/rope.bah"
struct rope* rope(char * a){

#line 72 "/opt/bah/rope.bah"
struct rope* ____BAH_COMPILER_VAR_74 = memoryAlloc(sizeof(struct rope));
____BAH_COMPILER_VAR_74->str = a;
struct rope* r = ____BAH_COMPILER_VAR_74;

#line 75 "/opt/bah/rope.bah"
return r;
};

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
char** ____BAH_COMPILER_VAR_75 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_75[1] = "\014\0\0\0"" 2>/dev/null";____BAH_COMPILER_VAR_75[0] = cm;char * ____BAH_COMPILER_VAR_76 =__Bah_multiple_concat(____BAH_COMPILER_VAR_75, 2);cm = ____BAH_COMPILER_VAR_76;
}

#line 28 "/opt/bah/exec.bah"
else {

#line 29 "/opt/bah/exec.bah"
char** ____BAH_COMPILER_VAR_77 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_77[1] = "\05\0\0\0"" 2>&1";____BAH_COMPILER_VAR_77[0] = cm;char * ____BAH_COMPILER_VAR_78 =__Bah_multiple_concat(____BAH_COMPILER_VAR_77, 2);cm = ____BAH_COMPILER_VAR_78;
}

#line 31 "/opt/bah/exec.bah"
this->handle = popen(cStr(cm),cStr("\01\0\0\0""w"));

#line 32 "/opt/bah/exec.bah"
if ((this->handle==null)) {

#line 33 "/opt/bah/exec.bah"
return "\0\0\0\0""";
}

#line 35 "/opt/bah/exec.bah"
if ((strcmp(this->input, null) != 0)) {

#line 36 "/opt/bah/exec.bah"
fputs(cStr(this->input),(void *)this->handle);
}

#line 39 "/opt/bah/exec.bah"
char * buff = memoryAllocSTR(1024);

#line 40 "/opt/bah/exec.bah"
char * response = memoryAllocSTR(1);

#line 41 "/opt/bah/exec.bah"
void * res = (void *)response;

#line 42 "/opt/bah/exec.bah"
long int i = 0;

#line 42 "/opt/bah/exec.bah"
for (; (res!=null); 
#line 42 "/opt/bah/exec.bah"
++i) {

#line 43 "/opt/bah/exec.bah"
memset(cStr(buff),0,1024);

#line 44 "/opt/bah/exec.bah"
res = fgets((void *)buff,1023,this->handle);

#line 45 "/opt/bah/exec.bah"
if ((res==null)||(res==(void *)-1)) {

#line 46 "/opt/bah/exec.bah"
break;
}

#line 48 "/opt/bah/exec.bah"
response = memoryRealloc(response,(i+1)*1023);

#line 49 "/opt/bah/exec.bah"
long int* ln = response;

#line 50 "/opt/bah/exec.bah"
*ln = (i+1)*1023;

#line 51 "/opt/bah/exec.bah"
memcpy((void *)((long int)response+cpstringLenSize+i*1023),cStr(buff),1024);
};

#line 55 "/opt/bah/exec.bah"
this->status = pclose(this->handle);

#line 56 "/opt/bah/exec.bah"
return res;
};
__BAH_ARR_TYPE_char command__runBytes(struct command* this){

#line 62 "/opt/bah/exec.bah"
array(char)* arr = memoryAlloc(sizeof(array(char)));

arr->length = 0;
arr->elemSize = sizeof(char);

#line 63 "/opt/bah/exec.bah"
char * cm = this->command;

#line 64 "/opt/bah/exec.bah"
if ((this->error==false)) {

#line 65 "/opt/bah/exec.bah"
char** ____BAH_COMPILER_VAR_79 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_79[1] = "\014\0\0\0"" 2>/dev/null";____BAH_COMPILER_VAR_79[0] = cm;char * ____BAH_COMPILER_VAR_80 =__Bah_multiple_concat(____BAH_COMPILER_VAR_79, 2);cm = ____BAH_COMPILER_VAR_80;
}

#line 66 "/opt/bah/exec.bah"
else {

#line 67 "/opt/bah/exec.bah"
char** ____BAH_COMPILER_VAR_81 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_81[1] = "\05\0\0\0"" 2>&1";____BAH_COMPILER_VAR_81[0] = cm;char * ____BAH_COMPILER_VAR_82 =__Bah_multiple_concat(____BAH_COMPILER_VAR_81, 2);cm = ____BAH_COMPILER_VAR_82;
}

#line 69 "/opt/bah/exec.bah"
this->handle = popen(cStr(cm),cStr("\01\0\0\0""r"));

#line 70 "/opt/bah/exec.bah"
if ((this->handle==null)) {

#line 71 "/opt/bah/exec.bah"
return arr;
}

#line 74 "/opt/bah/exec.bah"
long int total = 0;

#line 76 "/opt/bah/exec.bah"
char ____BAH_COMPILER_VAR_83[1024];char* buff = ____BAH_COMPILER_VAR_83;

#line 78 "/opt/bah/exec.bah"
void * res = fgets((void *)buff,1023,this->handle);

#line 79 "/opt/bah/exec.bah"
while ((res!=null)&&(res!=(void *)-1)) {

#line 80 "/opt/bah/exec.bah"
long int i = 0;

#line 80 "/opt/bah/exec.bah"
for (; (buff[i]!=null); 
#line 80 "/opt/bah/exec.bah"
++i) {

#line 81 "/opt/bah/exec.bah"

    unsigned int ____BAH_COMPILER_VAR_84 = len(arr);
    __Bah_realocate_arr(arr, ____BAH_COMPILER_VAR_84);
    arr->data[____BAH_COMPILER_VAR_84] = buff[i];
};

#line 83 "/opt/bah/exec.bah"
res = fgets((void *)buff,1023,this->handle);
};

#line 86 "/opt/bah/exec.bah"
this->status = pclose(this->handle);

#line 88 "/opt/bah/exec.bah"
return arr;
};

#line 95 "/opt/bah/exec.bah"
struct command command(char * s){

#line 96 "/opt/bah/exec.bah"
struct command ____BAH_COMPILER_VAR_85 = {};
____BAH_COMPILER_VAR_85.error = true;
struct command cmd = ____BAH_COMPILER_VAR_85;

#line 97 "/opt/bah/exec.bah"
cmd.command = s;

#line 98 "/opt/bah/exec.bah"
return cmd;
};

#line 105 "/opt/bah/exec.bah"
long int exec(char * s,__BAH_ARR_TYPE_cpstring args){

#line 106 "/opt/bah/exec.bah"
long int r;

#line 107 "/opt/bah/exec.bah"
array(char *)* nArgs = memoryAlloc(sizeof(array(char *)));

nArgs->length = 0;
nArgs->elemSize = sizeof(char *);

#line 108 "/opt/bah/exec.bah"

    unsigned int ____BAH_COMPILER_VAR_86 = 0;
    __Bah_realocate_arr(nArgs, ____BAH_COMPILER_VAR_86);
    nArgs->data[____BAH_COMPILER_VAR_86] = s;

#line 109 "/opt/bah/exec.bah"
register long int i = 0;

#line 109 "/opt/bah/exec.bah"
while ((i<len(args))) {

#line 110 "/opt/bah/exec.bah"

    unsigned int ____BAH_COMPILER_VAR_87 = i+1;
    __Bah_realocate_arr(nArgs, ____BAH_COMPILER_VAR_87);
    nArgs->data[____BAH_COMPILER_VAR_87] = args->data[i];

#line 111 "/opt/bah/exec.bah"
i = i+1;
};

#line 113 "/opt/bah/exec.bah"

    unsigned int ____BAH_COMPILER_VAR_88 = i+2;
    __Bah_realocate_arr(nArgs, ____BAH_COMPILER_VAR_88);
    nArgs->data[____BAH_COMPILER_VAR_88] = (char *)0;

#line 114 "/opt/bah/exec.bah"
r=execvp(s,nArgs->data);

#line 115 "/opt/bah/exec.bah"
return r;
};
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
struct reflectElement ____BAH_COMPILER_VAR_89 = {};
____BAH_COMPILER_VAR_89.structLayout = memoryAlloc(sizeof(array(struct reflectElement)));
            ____BAH_COMPILER_VAR_89.structLayout->length = 0;
            ____BAH_COMPILER_VAR_89.structLayout->elemSize = sizeof(struct reflectElement);
            struct reflectElement re = ____BAH_COMPILER_VAR_89;

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
typedef void * reflectSymbols;

#line 59 "/opt/bah/reflect.bah"
__BAH_ARR_TYPE_reflectElement __dumpSymbols(__BAH_ARR_TYPE_reflectElement syms){

#line 60 "/opt/bah/reflect.bah"
return syms;
};

#line 64 "/opt/bah/reflect.bah"
struct reflectElement __debug_get_sym(__BAH_ARR_TYPE_reflectElement syms,struct string a){

#line 65 "/opt/bah/reflect.bah"
if ((string__count(&a,"\01\0\0\0"".")>0)) {

#line 66 "/opt/bah/reflect.bah"
array(struct string)* parts = splitString(a,"\01\0\0\0"".");

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
struct reflectElement ____BAH_COMPILER_VAR_90 = {};
____BAH_COMPILER_VAR_90.structLayout = memoryAlloc(sizeof(array(struct reflectElement)));
            ____BAH_COMPILER_VAR_90.structLayout->length = 0;
            ____BAH_COMPILER_VAR_90.structLayout->elemSize = sizeof(struct reflectElement);
            struct reflectElement ns = ____BAH_COMPILER_VAR_90;

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
char * toJson(struct reflectElement e);
void json_scan_inner(void * this,struct reflectElement e,char isMember);

#line 19 "/opt/bah/json.bah"
struct jsonElement {
long int type;
char * key;
char * content;
array(struct jsonElement*)* children;
char contentFinal;
long int from;
long int to;
};
struct jsonElement* jsonElement__get(struct jsonElement* this,char * key){

#line 31 "/opt/bah/json.bah"
unsigned long int l = len(this->children);

#line 32 "/opt/bah/json.bah"
register long int i = 0;

#line 32 "/opt/bah/json.bah"
while ((i<l)) {

#line 33 "/opt/bah/json.bah"
struct jsonElement* elem = this->children->data[i];

#line 34 "/opt/bah/json.bah"
char fc = cpstringCharAt(elem->key,0);

#line 35 "/opt/bah/json.bah"
if ((fc==(char)34)) {

#line 36 "/opt/bah/json.bah"
array(char)* nk = memoryAlloc(sizeof(array(char)));

nk->length = 0;
nk->elemSize = sizeof(char);

#line 37 "/opt/bah/json.bah"
unsigned long int lk = strlen(elem->key);

#line 38 "/opt/bah/json.bah"
register long int j = 1;

#line 38 "/opt/bah/json.bah"
while ((j<lk-1)) {

#line 39 "/opt/bah/json.bah"
char c = cpstringCharAt(elem->key,j);

#line 40 "/opt/bah/json.bah"

    unsigned int ____BAH_COMPILER_VAR_91 = j-1;
    __Bah_realocate_arr(nk, ____BAH_COMPILER_VAR_91);
    nk->data[____BAH_COMPILER_VAR_91] = c;

#line 41 "/opt/bah/json.bah"
j = j+1;
};

#line 43 "/opt/bah/json.bah"
if ((strcmp(arrToStr(nk), key) == 0)) {

#line 44 "/opt/bah/json.bah"
return elem;
}
}

#line 46 "/opt/bah/json.bah"
else {

#line 47 "/opt/bah/json.bah"
if ((strcmp(elem->key, key) == 0)) {

#line 48 "/opt/bah/json.bah"
return elem;
}
}

#line 51 "/opt/bah/json.bah"
i = i+1;
};

#line 53 "/opt/bah/json.bah"
void * z = (void *)0;

#line 54 "/opt/bah/json.bah"
return z;
};
char * jsonElement__str(struct jsonElement* this){

#line 59 "/opt/bah/json.bah"
if ((this->contentFinal==false)) {

#line 60 "/opt/bah/json.bah"
this->content = cpstringSubsitute(this->content, this->from, this->to);
}

#line 62 "/opt/bah/json.bah"
return this->content;
};
void jsonElement__scan(struct jsonElement* this,struct reflectElement e){

#line 68 "/opt/bah/json.bah"
json_scan_inner(this,e,false);
};

#line 73 "/opt/bah/json.bah"
void json_scan_inner(void * thisp,struct reflectElement e,char isMember){

#line 74 "/opt/bah/json.bah"
struct jsonElement* this = thisp;

#line 75 "/opt/bah/json.bah"
if ((e.isStruct==true)) {

#line 76 "/opt/bah/json.bah"
register long int i = 0;

#line 76 "/opt/bah/json.bah"
while ((i<len(e.structLayout))) {

#line 77 "/opt/bah/json.bah"
struct reflectElement m = e.structLayout->data[i];

#line 78 "/opt/bah/json.bah"
m.value = reflectElement__calculateOffset(&m,e.value);

#line 79 "/opt/bah/json.bah"
struct jsonElement* ov = jsonElement__get(this,m.name);

#line 80 "/opt/bah/json.bah"
if ((ov!=null)) {

#line 81 "/opt/bah/json.bah"
json_scan_inner(ov,m,true);
}

#line 83 "/opt/bah/json.bah"
i = i+1;
};
}

#line 85 "/opt/bah/json.bah"
else if ((strcmp(e.type, "\03\0\0\0""int") == 0)) {

#line 86 "/opt/bah/json.bah"
long int* ep = e.value;

#line 87 "/opt/bah/json.bah"
*ep = strToInt(jsonElement__str(this));
}

#line 88 "/opt/bah/json.bah"
else if ((strcmp(e.type, "\010\0\0\0""cpstring") == 0)) {

#line 89 "/opt/bah/json.bah"
char ** ep = e.value;

#line 90 "/opt/bah/json.bah"
*ep = jsonElement__str(this);
}

#line 91 "/opt/bah/json.bah"
else if ((strcmp(e.type, "\05\0\0\0""float") == 0)) {

#line 92 "/opt/bah/json.bah"
double* ep = e.value;

#line 93 "/opt/bah/json.bah"
*ep = strToFloat(jsonElement__str(this));
}

#line 94 "/opt/bah/json.bah"
else if ((strcmp(e.type, "\04\0\0\0""bool") == 0)) {

#line 95 "/opt/bah/json.bah"
char* ep = e.value;

#line 96 "/opt/bah/json.bah"
if ((strcmp(jsonElement__str(this), "\01\0\0\0""1") == 0)||(strcmp(jsonElement__str(this), "\04\0\0\0""true") == 0)) {

#line 97 "/opt/bah/json.bah"
*ep = true;
}

#line 98 "/opt/bah/json.bah"
else {

#line 99 "/opt/bah/json.bah"
*ep = false;
}
}

#line 101 "/opt/bah/json.bah"
else if ((e.isArray==true)) {

#line 102 "/opt/bah/json.bah"
if ((len(this->children)==0)) {

#line 103 "/opt/bah/json.bah"
return;
}

#line 106 "/opt/bah/json.bah"
struct reflectElement* ae = e.arrayElem;

#line 107 "/opt/bah/json.bah"
if ((strcmp(ae->type, "\03\0\0\0""int") == 0)) {

#line 108 "/opt/bah/json.bah"
array(long int)* arr = memoryAlloc(sizeof(array(long int)));

arr->length = 0;
arr->elemSize = sizeof(long int);

#line 109 "/opt/bah/json.bah"
void ** arrPtr = e.value;

#line 110 "/opt/bah/json.bah"
if ((isMember==true)) {

#line 111 "/opt/bah/json.bah"
*arrPtr = arr;
}

#line 112 "/opt/bah/json.bah"
else {

#line 113 "/opt/bah/json.bah"
arr = *arrPtr;
}

#line 115 "/opt/bah/json.bah"
register long int i = 0;

#line 115 "/opt/bah/json.bah"
while ((i<len(this->children))) {

#line 116 "/opt/bah/json.bah"
struct jsonElement* c = this->children->data[i];

#line 117 "/opt/bah/json.bah"

    unsigned int ____BAH_COMPILER_VAR_92 = i;
    __Bah_realocate_arr(arr, ____BAH_COMPILER_VAR_92);
    arr->data[____BAH_COMPILER_VAR_92] = strToInt(jsonElement__str(c));

#line 118 "/opt/bah/json.bah"
i = i+1;
};
}

#line 120 "/opt/bah/json.bah"
else if ((strcmp(ae->type, "\05\0\0\0""float") == 0)) {

#line 121 "/opt/bah/json.bah"
array(double)* arr = memoryAlloc(sizeof(array(double)));

arr->length = 0;
arr->elemSize = sizeof(double);

#line 122 "/opt/bah/json.bah"
void ** arrPtr = e.value;

#line 123 "/opt/bah/json.bah"
if ((isMember==true)) {

#line 124 "/opt/bah/json.bah"
*arrPtr = arr;
}

#line 125 "/opt/bah/json.bah"
else {

#line 126 "/opt/bah/json.bah"
arr = *arrPtr;
}

#line 128 "/opt/bah/json.bah"
register long int i = 0;

#line 128 "/opt/bah/json.bah"
while ((i<len(this->children))) {

#line 129 "/opt/bah/json.bah"
struct jsonElement* c = this->children->data[i];

#line 130 "/opt/bah/json.bah"

    unsigned int ____BAH_COMPILER_VAR_93 = i;
    __Bah_realocate_arr(arr, ____BAH_COMPILER_VAR_93);
    arr->data[____BAH_COMPILER_VAR_93] = strToFloat(jsonElement__str(c));

#line 131 "/opt/bah/json.bah"
i = i+1;
};
}

#line 133 "/opt/bah/json.bah"
else if ((strcmp(ae->type, "\010\0\0\0""cpstring") == 0)) {

#line 134 "/opt/bah/json.bah"
array(char *)* arr = memoryAlloc(sizeof(array(char *)));

arr->length = 0;
arr->elemSize = sizeof(char *);

#line 135 "/opt/bah/json.bah"
void ** arrPtr = e.value;

#line 136 "/opt/bah/json.bah"
if ((isMember==true)) {

#line 137 "/opt/bah/json.bah"
*arrPtr = arr;
}

#line 138 "/opt/bah/json.bah"
else {

#line 139 "/opt/bah/json.bah"
arr = *arrPtr;
}

#line 141 "/opt/bah/json.bah"
register long int i = 0;

#line 141 "/opt/bah/json.bah"
while ((i<len(this->children))) {

#line 142 "/opt/bah/json.bah"
struct jsonElement* c = this->children->data[i];

#line 143 "/opt/bah/json.bah"

    unsigned int ____BAH_COMPILER_VAR_94 = i;
    __Bah_realocate_arr(arr, ____BAH_COMPILER_VAR_94);
    arr->data[____BAH_COMPILER_VAR_94] = jsonElement__str(c);

#line 144 "/opt/bah/json.bah"
i = i+1;
};
}

#line 146 "/opt/bah/json.bah"
else if ((ae->isStruct==true)) {

#line 147 "/opt/bah/json.bah"
array(void *)* arr = memoryAlloc(sizeof(array(void *)));

arr->length = 0;
arr->elemSize = sizeof(void *);

#line 148 "/opt/bah/json.bah"
void ** arrPtr = e.value;

#line 149 "/opt/bah/json.bah"
if ((isMember==true)) {

#line 150 "/opt/bah/json.bah"
*arrPtr = arr;
}

#line 151 "/opt/bah/json.bah"
else {

#line 152 "/opt/bah/json.bah"
arr = *arrPtr;
}

#line 154 "/opt/bah/json.bah"
register long int i = 0;

#line 154 "/opt/bah/json.bah"
while ((i<len(this->children))) {

#line 155 "/opt/bah/json.bah"
struct jsonElement* c = this->children->data[i];

#line 156 "/opt/bah/json.bah"
void * ne = memoryAlloc(ae->size);

#line 157 "/opt/bah/json.bah"
register long int j = 0;

#line 157 "/opt/bah/json.bah"
while ((j<len(ae->structLayout))) {

#line 158 "/opt/bah/json.bah"
struct reflectElement m = ae->structLayout->data[j];

#line 159 "/opt/bah/json.bah"
m.value = reflectElement__calculateOffset(&m,ne);

#line 160 "/opt/bah/json.bah"
struct jsonElement* ov = jsonElement__get(c,m.name);

#line 161 "/opt/bah/json.bah"
if ((ov!=null)) {

#line 162 "/opt/bah/json.bah"
json_scan_inner(ov,m,true);
}

#line 164 "/opt/bah/json.bah"
j = j+1;
};

#line 166 "/opt/bah/json.bah"

    unsigned int ____BAH_COMPILER_VAR_95 = i;
    __Bah_realocate_arr(arr, ____BAH_COMPILER_VAR_95);
    arr->data[____BAH_COMPILER_VAR_95] = ne;

#line 167 "/opt/bah/json.bah"
i = i+1;
};
}
}

#line 170 "/opt/bah/json.bah"
else if (strHasPrefix(e.type,"\04\0\0\0""map:")) {

#line 171 "/opt/bah/json.bah"
struct mapWrapper** p = e.value;

#line 172 "/opt/bah/json.bah"
register long int i = 0;

#line 172 "/opt/bah/json.bah"
for (; (i<len(this->children)); 
#line 172 "/opt/bah/json.bah"
++i) {

#line 173 "/opt/bah/json.bah"
struct jsonElement* c = this->children->data[i];

#line 174 "/opt/bah/json.bah"
struct reflectElement* ae = e.arrayElem;

#line 175 "/opt/bah/json.bah"
void * v = memoryAlloc(ae->size);

#line 176 "/opt/bah/json.bah"
ae->value = &v;

#line 177 "/opt/bah/json.bah"
register long int j = 0;

#line 177 "/opt/bah/json.bah"
for (; (j<len(ae->structLayout)); 
#line 177 "/opt/bah/json.bah"
++j) {

#line 178 "/opt/bah/json.bah"
struct reflectElement m = ae->structLayout->data[j];

#line 179 "/opt/bah/json.bah"
m.value = reflectElement__calculateOffset(&m,&v);

#line 180 "/opt/bah/json.bah"

    unsigned int ____BAH_COMPILER_VAR_96 = j;
    __Bah_realocate_arr(ae->structLayout, ____BAH_COMPILER_VAR_96);
    ae->structLayout->data[____BAH_COMPILER_VAR_96] = m;
};

#line 182 "/opt/bah/json.bah"
json_scan_inner(c,*ae,true);

#line 183 "/opt/bah/json.bah"
struct string k = string(c->key);

#line 184 "/opt/bah/json.bah"
string__trimLeft(&k,1);

#line 185 "/opt/bah/json.bah"
string__trimRight(&k,1);

#line 186 "/opt/bah/json.bah"
if (strCount(ae->type,"\01\0\0\0""*")||(strcmp(ae->type, "\03\0\0\0""ptr") == 0)||(strcmp(ae->type, "\010\0\0\0""cpstring") == 0)||strHasPrefix(ae->type,"\02\0\0\0""[]")||strHasPrefix(ae->type,"\04\0\0\0""map:")) {

#line 187 "/opt/bah/json.bah"
struct mapWrapper* m = *p;

#line 188 "/opt/bah/json.bah"
m->set(m,string__str(&k),v);
}

#line 189 "/opt/bah/json.bah"
else {

#line 190 "/opt/bah/json.bah"
struct mapWrapper* m = *p;

#line 191 "/opt/bah/json.bah"
m->set(m,string__str(&k),&v);
}
};
}
};

#line 197 "/opt/bah/json.bah"
char * jError;

#line 200 "/opt/bah/json.bah"
struct jsonElement* parseJson_inner(char * s,long int* ip,long int l){

#line 201 "/opt/bah/json.bah"
jError = "\0\0\0\0""";

#line 202 "/opt/bah/json.bah"
long int i = *ip;

#line 204 "/opt/bah/json.bah"
for (; (i<l); 
#line 204 "/opt/bah/json.bah"
++i) {

#line 205 "/opt/bah/json.bah"
if ((isSpace(s[i+4])==false)) {

#line 206 "/opt/bah/json.bah"
break;
}
};

#line 210 "/opt/bah/json.bah"
struct jsonElement* ____BAH_COMPILER_VAR_97 = memoryAlloc(sizeof(struct jsonElement));
____BAH_COMPILER_VAR_97->children = memoryAlloc(sizeof(array(struct jsonElement*)));
            ____BAH_COMPILER_VAR_97->children->length = 0;
            ____BAH_COMPILER_VAR_97->children->elemSize = sizeof(struct jsonElement*);
            ____BAH_COMPILER_VAR_97->content = s;
____BAH_COMPILER_VAR_97->from = i;
____BAH_COMPILER_VAR_97->to = l;
struct jsonElement* j = ____BAH_COMPILER_VAR_97;

#line 216 "/opt/bah/json.bah"
if ((s[i+4]==91)) {

#line 217 "/opt/bah/json.bah"
j->type = JSON_TYPE_ARRAY;

#line 218 "/opt/bah/json.bah"
++i;

#line 219 "/opt/bah/json.bah"
for (; (i<l); 
#line 219 "/opt/bah/json.bah"
++i) {

#line 220 "/opt/bah/json.bah"
if ((isSpace(s[i+4])==false)) {

#line 221 "/opt/bah/json.bah"
break;
}
};

#line 224 "/opt/bah/json.bah"
if ((s[i+4]!=93)) {

#line 225 "/opt/bah/json.bah"
for (; (i<l); 
#line 225 "/opt/bah/json.bah"
++i) {

#line 226 "/opt/bah/json.bah"
struct jsonElement* child = parseJson_inner(s,&i,l);

#line 227 "/opt/bah/json.bah"
if ((child==null)) {

#line 228 "/opt/bah/json.bah"
return null;
}

#line 230 "/opt/bah/json.bah"

    unsigned int ____BAH_COMPILER_VAR_98 = len(j->children);
    __Bah_realocate_arr(j->children, ____BAH_COMPILER_VAR_98);
    j->children->data[____BAH_COMPILER_VAR_98] = child;

#line 231 "/opt/bah/json.bah"
for (; (i<l); 
#line 231 "/opt/bah/json.bah"
++i) {

#line 232 "/opt/bah/json.bah"
if ((isSpace(s[i+4])==false)) {

#line 233 "/opt/bah/json.bah"
break;
}
};

#line 237 "/opt/bah/json.bah"
if ((s[i+4]!=44)) {

#line 238 "/opt/bah/json.bah"
if ((s[i+4]!=93)) {

#line 239 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_99 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_99[4] = "\01\0\0\0"")";____BAH_COMPILER_VAR_99[3] = intToStr(i);____BAH_COMPILER_VAR_99[2] = "\010\0\0\0"") (pos: ";____BAH_COMPILER_VAR_99[1] = charToString(s[i+4]);____BAH_COMPILER_VAR_99[0] = "\045\0\0\0""json: expected array separator (got: ";char * ____BAH_COMPILER_VAR_100 =__Bah_multiple_concat(____BAH_COMPILER_VAR_99, 5);jError = ____BAH_COMPILER_VAR_100;

#line 240 "/opt/bah/json.bah"
return null;
}

#line 242 "/opt/bah/json.bah"
++i;

#line 243 "/opt/bah/json.bah"
break;
}

#line 246 "/opt/bah/json.bah"
for (; (i<l); 
#line 246 "/opt/bah/json.bah"
++i) {

#line 247 "/opt/bah/json.bah"
if ((isSpace(s[i+4])==false)) {

#line 248 "/opt/bah/json.bah"
break;
}
};
};
}

#line 253 "/opt/bah/json.bah"
else {

#line 254 "/opt/bah/json.bah"
++i;
}

#line 256 "/opt/bah/json.bah"
j->to = i;
}

#line 257 "/opt/bah/json.bah"
else if ((s[i+4]==123)) {

#line 258 "/opt/bah/json.bah"
j->type = JSON_TYPE_MAP;

#line 259 "/opt/bah/json.bah"
++i;

#line 260 "/opt/bah/json.bah"
for (; (i<l); 
#line 260 "/opt/bah/json.bah"
++i) {

#line 261 "/opt/bah/json.bah"
if ((isSpace(s[i+4])==false)) {

#line 262 "/opt/bah/json.bah"
break;
}
};

#line 265 "/opt/bah/json.bah"
if ((s[i+4]!=125)) {

#line 266 "/opt/bah/json.bah"
for (; (i<l); 
#line 266 "/opt/bah/json.bah"
++i) {

#line 267 "/opt/bah/json.bah"
for (; (i<l); 
#line 267 "/opt/bah/json.bah"
++i) {

#line 268 "/opt/bah/json.bah"
if ((isSpace(s[i+4])==false)) {

#line 269 "/opt/bah/json.bah"
break;
}
};

#line 272 "/opt/bah/json.bah"
if ((s[i+4]!=34)) {

#line 273 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_101 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_101[2] = "\01\0\0\0"")";____BAH_COMPILER_VAR_101[1] = intToStr(i);____BAH_COMPILER_VAR_101[0] = "\047\0\0\0""json: expected string as map key (pos: ";char * ____BAH_COMPILER_VAR_102 =__Bah_multiple_concat(____BAH_COMPILER_VAR_101, 3);jError = ____BAH_COMPILER_VAR_102;

#line 274 "/opt/bah/json.bah"
return null;
}

#line 276 "/opt/bah/json.bah"
++i;

#line 277 "/opt/bah/json.bah"
long int ns = i;

#line 278 "/opt/bah/json.bah"
for (; (i<l); 
#line 278 "/opt/bah/json.bah"
++i) {

#line 279 "/opt/bah/json.bah"
if ((s[i+4]==34)&&(s[i-1+4]!=(char)92)) {

#line 280 "/opt/bah/json.bah"
break;
}
};

#line 283 "/opt/bah/json.bah"
char * name = cpstringSubsitute(s, ns, i);

#line 284 "/opt/bah/json.bah"
++i;

#line 286 "/opt/bah/json.bah"
for (; (i<l); 
#line 286 "/opt/bah/json.bah"
++i) {

#line 287 "/opt/bah/json.bah"
if ((isSpace(s[i+4])==false)) {

#line 288 "/opt/bah/json.bah"
break;
}
};

#line 292 "/opt/bah/json.bah"
if ((s[i+4]!=58)) {

#line 293 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_103 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_103[4] = "\01\0\0\0"")";____BAH_COMPILER_VAR_103[3] = intToStr(i);____BAH_COMPILER_VAR_103[2] = "\010\0\0\0"") (pos: ";____BAH_COMPILER_VAR_103[1] = intToStr((long int)s[i+4]);____BAH_COMPILER_VAR_103[0] = "\055\0\0\0""json: expected : between key and value (got: ";char * ____BAH_COMPILER_VAR_104 =__Bah_multiple_concat(____BAH_COMPILER_VAR_103, 5);jError = ____BAH_COMPILER_VAR_104;

#line 294 "/opt/bah/json.bah"
return null;
}

#line 297 "/opt/bah/json.bah"
++i;

#line 299 "/opt/bah/json.bah"
struct jsonElement* child = parseJson_inner(s,&i,l);

#line 300 "/opt/bah/json.bah"
if ((child==null)) {

#line 301 "/opt/bah/json.bah"
return null;
}

#line 303 "/opt/bah/json.bah"
child->key = name;

#line 304 "/opt/bah/json.bah"

    unsigned int ____BAH_COMPILER_VAR_105 = len(j->children);
    __Bah_realocate_arr(j->children, ____BAH_COMPILER_VAR_105);
    j->children->data[____BAH_COMPILER_VAR_105] = child;

#line 306 "/opt/bah/json.bah"
for (; (i<l); 
#line 306 "/opt/bah/json.bah"
++i) {

#line 307 "/opt/bah/json.bah"
if ((isSpace(s[i+4])==false)) {

#line 308 "/opt/bah/json.bah"
break;
}
};

#line 312 "/opt/bah/json.bah"
if ((s[i+4]!=44)) {

#line 313 "/opt/bah/json.bah"
if ((s[i+4]!=125)) {

#line 314 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_106 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_106[2] = "\01\0\0\0"")";____BAH_COMPILER_VAR_106[1] = intToStr(i);____BAH_COMPILER_VAR_106[0] = "\043\0\0\0""json: expected map separator (pos: ";char * ____BAH_COMPILER_VAR_107 =__Bah_multiple_concat(____BAH_COMPILER_VAR_106, 3);jError = ____BAH_COMPILER_VAR_107;

#line 315 "/opt/bah/json.bah"
return null;
}

#line 317 "/opt/bah/json.bah"
++i;

#line 318 "/opt/bah/json.bah"
break;
}
};
}

#line 321 "/opt/bah/json.bah"
else {

#line 322 "/opt/bah/json.bah"
++i;
}

#line 324 "/opt/bah/json.bah"
j->to = i;
}

#line 325 "/opt/bah/json.bah"
else if ((s[i+4]==34)) {

#line 326 "/opt/bah/json.bah"
j->type = JSON_TYPE_STRING;

#line 327 "/opt/bah/json.bah"
++i;

#line 328 "/opt/bah/json.bah"
j->from = i;

#line 329 "/opt/bah/json.bah"
array(char)* mem = memoryAlloc(sizeof(array(char)));

mem->length = 0;
mem->elemSize = sizeof(char);

#line 330 "/opt/bah/json.bah"
for (; (i<l); 
#line 330 "/opt/bah/json.bah"
++i) {

#line 331 "/opt/bah/json.bah"
if ((s[i+4]==34)) {

#line 332 "/opt/bah/json.bah"
break;
}

#line 334 "/opt/bah/json.bah"
if ((s[i+4]==(char)92)) {

#line 335 "/opt/bah/json.bah"
j->contentFinal = true;

#line 336 "/opt/bah/json.bah"
if ((len(mem)==0)) {

#line 337 "/opt/bah/json.bah"
mem = strToArr(cpstringSubsitute(s, j->from, i));

#line 338 "/opt/bah/json.bah"
if ((s[i+1+4]==114)) {

#line 339 "/opt/bah/json.bah"

    unsigned int ____BAH_COMPILER_VAR_108 = len(mem);
    __Bah_realocate_arr(mem, ____BAH_COMPILER_VAR_108);
    mem->data[____BAH_COMPILER_VAR_108] = (char)13;
}

#line 340 "/opt/bah/json.bah"
else if ((s[i+1+4]==110)) {

#line 341 "/opt/bah/json.bah"

    unsigned int ____BAH_COMPILER_VAR_109 = len(mem);
    __Bah_realocate_arr(mem, ____BAH_COMPILER_VAR_109);
    mem->data[____BAH_COMPILER_VAR_109] = (char)10;
}

#line 342 "/opt/bah/json.bah"
else {

#line 343 "/opt/bah/json.bah"

    unsigned int ____BAH_COMPILER_VAR_110 = len(mem);
    __Bah_realocate_arr(mem, ____BAH_COMPILER_VAR_110);
    mem->data[____BAH_COMPILER_VAR_110] = s[i+1+4];
}
}

#line 346 "/opt/bah/json.bah"
++i;

#line 347 "/opt/bah/json.bah"
continue;
}

#line 349 "/opt/bah/json.bah"
if ((len(mem)!=0)) {

#line 350 "/opt/bah/json.bah"

    unsigned int ____BAH_COMPILER_VAR_111 = len(mem);
    __Bah_realocate_arr(mem, ____BAH_COMPILER_VAR_111);
    mem->data[____BAH_COMPILER_VAR_111] = s[i+4];
}
};

#line 353 "/opt/bah/json.bah"
if ((len(mem)!=0)) {

#line 354 "/opt/bah/json.bah"
j->content = arrToStr(mem);
}

#line 356 "/opt/bah/json.bah"
j->to = i;

#line 357 "/opt/bah/json.bah"
++i;
}

#line 358 "/opt/bah/json.bah"
else if (isNumber(s[i+4])||(s[i+4]==45)) {

#line 359 "/opt/bah/json.bah"
j->type = JSON_TYPE_INT;

#line 360 "/opt/bah/json.bah"
++i;

#line 361 "/opt/bah/json.bah"
for (; (i<l); 
#line 361 "/opt/bah/json.bah"
++i) {

#line 362 "/opt/bah/json.bah"
if ((isNumber(s[i+4])==false)) {

#line 363 "/opt/bah/json.bah"
break;
}

#line 365 "/opt/bah/json.bah"
if ((s[i+4]==46)) {

#line 366 "/opt/bah/json.bah"
j->type = JSON_TYPE_FLOAT;
}
};

#line 369 "/opt/bah/json.bah"
j->to = i;
}

#line 370 "/opt/bah/json.bah"
else {

#line 371 "/opt/bah/json.bah"
long int si = i;

#line 372 "/opt/bah/json.bah"
for (; (i<l); 
#line 372 "/opt/bah/json.bah"
++i) {

#line 373 "/opt/bah/json.bah"
if ((isLetter(s[i+4])==false)) {

#line 374 "/opt/bah/json.bah"
break;
}
};

#line 377 "/opt/bah/json.bah"
s = cpstringSubsitute(s, si, i);

#line 378 "/opt/bah/json.bah"
if ((strcmp(s, "\04\0\0\0""true") == 0)||(strcmp(s, "\05\0\0\0""false") == 0)||(strcmp(s, "\04\0\0\0""null") == 0)) {

#line 379 "/opt/bah/json.bah"
j->type = JSON_TYPE_INT;

#line 380 "/opt/bah/json.bah"
j->content = s;

#line 381 "/opt/bah/json.bah"
j->contentFinal = true;
}
}

#line 385 "/opt/bah/json.bah"
*ip = i;

#line 386 "/opt/bah/json.bah"
return j;
};

#line 392 "/opt/bah/json.bah"
struct jsonElement* parseJson(char * s){

#line 393 "/opt/bah/json.bah"
unsigned long int l = strlen(s);

#line 394 "/opt/bah/json.bah"
long int i = 0;

#line 395 "/opt/bah/json.bah"
return parseJson_inner(s,&i,l);
};

#line 399 "/opt/bah/json.bah"
char json_isPrintable(unsigned int c){

#line 400 "/opt/bah/json.bah"
if ((c<32)||(c>255)) {

#line 401 "/opt/bah/json.bah"
return false;
}

#line 403 "/opt/bah/json.bah"
return (c!=127)&&(c!=129)&&(c!=141)&&(c!=143)&&(c!=144)&&(c!=157);
};

#line 407 "/opt/bah/json.bah"
char * jsonEscapeStr(char * s){

#line 408 "/opt/bah/json.bah"
struct strBuilder ____BAH_COMPILER_VAR_112 = {};
strBuilder___init(&____BAH_COMPILER_VAR_112);
struct strBuilder r = ____BAH_COMPILER_VAR_112;

#line 409 "/opt/bah/json.bah"
unsigned long int l = strlen(s);

#line 411 "/opt/bah/json.bah"
register long int i = 0;

#line 411 "/opt/bah/json.bah"
for (; (i<l); 
#line 411 "/opt/bah/json.bah"
++i) {

#line 412 "/opt/bah/json.bah"
char c = s[i+4];

#line 413 "/opt/bah/json.bah"
if ((c==(char)34)) {

#line 414 "/opt/bah/json.bah"
strBuilder__append(&r,(char)92);
}

#line 415 "/opt/bah/json.bah"
else if ((c==(char)10)) {

#line 416 "/opt/bah/json.bah"
strBuilder__append(&r,(char)92);

#line 417 "/opt/bah/json.bah"
strBuilder__append(&r,110);

#line 418 "/opt/bah/json.bah"
continue;
}

#line 419 "/opt/bah/json.bah"
else if ((c==(char)13)) {

#line 420 "/opt/bah/json.bah"
strBuilder__append(&r,(char)92);

#line 421 "/opt/bah/json.bah"
strBuilder__append(&r,114);

#line 422 "/opt/bah/json.bah"
continue;
}

#line 424 "/opt/bah/json.bah"
if ((json_isPrintable((unsigned int)c)==false)) {

#line 425 "/opt/bah/json.bah"
if (((unsigned char)c==(unsigned char)195)) {

#line 426 "/opt/bah/json.bah"
strBuilder__append(&r,c);

#line 427 "/opt/bah/json.bah"
strBuilder__append(&r,s[i+1+4]);

#line 428 "/opt/bah/json.bah"
++i;
}

#line 430 "/opt/bah/json.bah"
continue;
}

#line 432 "/opt/bah/json.bah"
strBuilder__append(&r,c);
};

#line 435 "/opt/bah/json.bah"
return strBuilder__str(&r);
};

#line 440 "/opt/bah/json.bah"
char * oldToJson__inner(struct reflectElement e,char isMember,long int tabs){

#line 441 "/opt/bah/json.bah"
void ** v = e.value;

#line 442 "/opt/bah/json.bah"
if ((e.value==null)) {

#line 443 "/opt/bah/json.bah"
if ((strcmp(e.type, "\03\0\0\0""int") == 0)||(strcmp(e.type, "\05\0\0\0""float") == 0)) {

#line 444 "/opt/bah/json.bah"
return "\01\0\0\0""0";
}

#line 446 "/opt/bah/json.bah"
if ((strcmp(e.type, "\04\0\0\0""bool") == 0)) {

#line 447 "/opt/bah/json.bah"
return "\05\0\0\0""false";
}

#line 449 "/opt/bah/json.bah"
if ((strcmp(e.type, "\03\0\0\0""ptr") == 0)||(strcmp(e.type, "\010\0\0\0""cpstring") == 0)||(strCount(e.type,"\01\0\0\0""*")!=0)) {

#line 450 "/opt/bah/json.bah"
return "\04\0\0\0""null";
}
}

#line 453 "/opt/bah/json.bah"
if ((e.isStruct==true)) {

#line 454 "/opt/bah/json.bah"
tabs = tabs+1;

#line 455 "/opt/bah/json.bah"
char * tabsStr = "\0\0\0\0""";

#line 456 "/opt/bah/json.bah"
register long int i = 0;

#line 456 "/opt/bah/json.bah"
while ((i<tabs)) {

#line 457 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_113 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_113[1] = "\01\0\0\0""\t";____BAH_COMPILER_VAR_113[0] = tabsStr;char * ____BAH_COMPILER_VAR_114 =__Bah_multiple_concat(____BAH_COMPILER_VAR_113, 2);tabsStr = ____BAH_COMPILER_VAR_114;

#line 458 "/opt/bah/json.bah"
i = i+1;
};

#line 460 "/opt/bah/json.bah"
char * s = "\02\0\0\0""{\n";

#line 461 "/opt/bah/json.bah"
i = 0;

#line 461 "/opt/bah/json.bah"
while ((i<len(e.structLayout))) {

#line 462 "/opt/bah/json.bah"
struct reflectElement m = e.structLayout->data[i];

#line 463 "/opt/bah/json.bah"
i = i+1;

#line 464 "/opt/bah/json.bah"
m.value = reflectElement__calculateOffset(&m,e.value);

#line 465 "/opt/bah/json.bah"
if ((i<len(e.structLayout))) {

#line 466 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_115 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_115[6] = "\02\0\0\0"",\n";____BAH_COMPILER_VAR_115[5] = oldToJson__inner(m,true,tabs);____BAH_COMPILER_VAR_115[4] = "\03\0\0\0""\": ";____BAH_COMPILER_VAR_115[3] = m.name;____BAH_COMPILER_VAR_115[2] = "\01\0\0\0""\"";____BAH_COMPILER_VAR_115[1] = tabsStr;____BAH_COMPILER_VAR_115[0] = s;char * ____BAH_COMPILER_VAR_116 =__Bah_multiple_concat(____BAH_COMPILER_VAR_115, 7);s = ____BAH_COMPILER_VAR_116;
}

#line 467 "/opt/bah/json.bah"
else {

#line 468 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_117 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_117[6] = "\01\0\0\0""\n";____BAH_COMPILER_VAR_117[5] = oldToJson__inner(m,true,tabs);____BAH_COMPILER_VAR_117[4] = "\03\0\0\0""\": ";____BAH_COMPILER_VAR_117[3] = m.name;____BAH_COMPILER_VAR_117[2] = "\01\0\0\0""\"";____BAH_COMPILER_VAR_117[1] = tabsStr;____BAH_COMPILER_VAR_117[0] = s;char * ____BAH_COMPILER_VAR_118 =__Bah_multiple_concat(____BAH_COMPILER_VAR_117, 7);s = ____BAH_COMPILER_VAR_118;
}
};

#line 471 "/opt/bah/json.bah"
tabs = tabs-1;

#line 472 "/opt/bah/json.bah"
tabsStr = "\0\0\0\0""";

#line 473 "/opt/bah/json.bah"
i = 0;

#line 473 "/opt/bah/json.bah"
while ((i<tabs)) {

#line 474 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_119 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_119[1] = "\01\0\0\0""\t";____BAH_COMPILER_VAR_119[0] = tabsStr;char * ____BAH_COMPILER_VAR_120 =__Bah_multiple_concat(____BAH_COMPILER_VAR_119, 2);tabsStr = ____BAH_COMPILER_VAR_120;

#line 475 "/opt/bah/json.bah"
i = i+1;
};

#line 477 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_121 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_121[2] = "\01\0\0\0""}";____BAH_COMPILER_VAR_121[1] = tabsStr;____BAH_COMPILER_VAR_121[0] = s;char * ____BAH_COMPILER_VAR_122 =__Bah_multiple_concat(____BAH_COMPILER_VAR_121, 3);s = ____BAH_COMPILER_VAR_122;

#line 478 "/opt/bah/json.bah"
return s;
}

#line 479 "/opt/bah/json.bah"
else if ((strcmp(e.type, "\03\0\0\0""int") == 0)) {

#line 480 "/opt/bah/json.bah"
long int* ip = e.value;

#line 481 "/opt/bah/json.bah"
return intToStr(*ip);
}

#line 482 "/opt/bah/json.bah"
else if ((strcmp(e.type, "\05\0\0\0""float") == 0)) {

#line 483 "/opt/bah/json.bah"
double* fp = e.value;

#line 484 "/opt/bah/json.bah"
return floatToStr(*fp);
}

#line 485 "/opt/bah/json.bah"
else if ((strcmp(e.type, "\010\0\0\0""cpstring") == 0)) {

#line 486 "/opt/bah/json.bah"
if ((isMember==false)) {

#line 487 "/opt/bah/json.bah"
void * s = e.value;

#line 488 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_123 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_123[2] = "\01\0\0\0""\"";____BAH_COMPILER_VAR_123[1] = jsonEscapeStr(s);____BAH_COMPILER_VAR_123[0] = "\01\0\0\0""\"";char * ____BAH_COMPILER_VAR_124 =__Bah_multiple_concat(____BAH_COMPILER_VAR_123, 3);return ____BAH_COMPILER_VAR_124;
}

#line 489 "/opt/bah/json.bah"
else {

#line 490 "/opt/bah/json.bah"
char ** sp = e.value;

#line 491 "/opt/bah/json.bah"
char * s = *sp;

#line 492 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_125 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_125[2] = "\01\0\0\0""\"";____BAH_COMPILER_VAR_125[1] = jsonEscapeStr(s);____BAH_COMPILER_VAR_125[0] = "\01\0\0\0""\"";char * ____BAH_COMPILER_VAR_126 =__Bah_multiple_concat(____BAH_COMPILER_VAR_125, 3);return ____BAH_COMPILER_VAR_126;
}
}

#line 494 "/opt/bah/json.bah"
else if ((strcmp(e.type, "\04\0\0\0""bool") == 0)) {

#line 495 "/opt/bah/json.bah"
char* bp = e.value;

#line 496 "/opt/bah/json.bah"
if ((*bp==true)) {

#line 497 "/opt/bah/json.bah"
return "\04\0\0\0""true";
}

#line 499 "/opt/bah/json.bah"
return "\05\0\0\0""false";
}

#line 500 "/opt/bah/json.bah"
else if ((e.isArray==true)) {

#line 501 "/opt/bah/json.bah"
char * s = "\01\0\0\0""[";

#line 502 "/opt/bah/json.bah"
struct reflectElement* ae = e.arrayElem;

#line 503 "/opt/bah/json.bah"
if ((e.value==null)) {

#line 504 "/opt/bah/json.bah"
return "\04\0\0\0""null";
}

#line 506 "/opt/bah/json.bah"
if ((strcmp(ae->type, "\03\0\0\0""int") == 0)) {

#line 507 "/opt/bah/json.bah"
array(long int)* arr = memoryAlloc(sizeof(array(long int)));

arr->length = 0;
arr->elemSize = sizeof(long int);

#line 508 "/opt/bah/json.bah"
void ** arrPtr = e.value;

#line 509 "/opt/bah/json.bah"
arr = *arrPtr;

#line 510 "/opt/bah/json.bah"
register long int i = 0;

#line 510 "/opt/bah/json.bah"
while ((i<len(arr))) {

#line 511 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_127 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_127[1] = intToStr(arr->data[i]);____BAH_COMPILER_VAR_127[0] = s;char * ____BAH_COMPILER_VAR_128 =__Bah_multiple_concat(____BAH_COMPILER_VAR_127, 2);s = ____BAH_COMPILER_VAR_128;

#line 512 "/opt/bah/json.bah"
i = i+1;

#line 513 "/opt/bah/json.bah"
if ((i<len(arr))) {

#line 514 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_129 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_129[1] = "\01\0\0\0"",";____BAH_COMPILER_VAR_129[0] = s;char * ____BAH_COMPILER_VAR_130 =__Bah_multiple_concat(____BAH_COMPILER_VAR_129, 2);s = ____BAH_COMPILER_VAR_130;
}
};
}

#line 517 "/opt/bah/json.bah"
else if ((strcmp(ae->type, "\05\0\0\0""float") == 0)) {

#line 518 "/opt/bah/json.bah"
array(double)* arr = memoryAlloc(sizeof(array(double)));

arr->length = 0;
arr->elemSize = sizeof(double);

#line 519 "/opt/bah/json.bah"
void ** arrPtr = e.value;

#line 520 "/opt/bah/json.bah"
arr = *arrPtr;

#line 521 "/opt/bah/json.bah"
register long int i = 0;

#line 521 "/opt/bah/json.bah"
while ((i<len(arr))) {

#line 522 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_131 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_131[1] = floatToStr(arr->data[i]);____BAH_COMPILER_VAR_131[0] = s;char * ____BAH_COMPILER_VAR_132 =__Bah_multiple_concat(____BAH_COMPILER_VAR_131, 2);s = ____BAH_COMPILER_VAR_132;

#line 523 "/opt/bah/json.bah"
i = i+1;

#line 524 "/opt/bah/json.bah"
if ((i<len(arr))) {

#line 525 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_133 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_133[1] = "\01\0\0\0"",";____BAH_COMPILER_VAR_133[0] = s;char * ____BAH_COMPILER_VAR_134 =__Bah_multiple_concat(____BAH_COMPILER_VAR_133, 2);s = ____BAH_COMPILER_VAR_134;
}
};
}

#line 528 "/opt/bah/json.bah"
else if ((strcmp(ae->type, "\010\0\0\0""cpstring") == 0)) {

#line 529 "/opt/bah/json.bah"
array(char *)* arr = memoryAlloc(sizeof(array(char *)));

arr->length = 0;
arr->elemSize = sizeof(char *);

#line 530 "/opt/bah/json.bah"
void ** arrPtr = e.value;

#line 531 "/opt/bah/json.bah"
arr = *arrPtr;

#line 532 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_135 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_135[1] = "\01\0\0\0""\n";____BAH_COMPILER_VAR_135[0] = s;char * ____BAH_COMPILER_VAR_136 =__Bah_multiple_concat(____BAH_COMPILER_VAR_135, 2);s = ____BAH_COMPILER_VAR_136;

#line 533 "/opt/bah/json.bah"
register long int i = 0;

#line 533 "/opt/bah/json.bah"
while ((i<len(arr))) {

#line 534 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_137 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_137[3] = "\01\0\0\0""\"";____BAH_COMPILER_VAR_137[2] = jsonEscapeStr(arr->data[i]);____BAH_COMPILER_VAR_137[1] = "\01\0\0\0""\"";____BAH_COMPILER_VAR_137[0] = s;char * ____BAH_COMPILER_VAR_138 =__Bah_multiple_concat(____BAH_COMPILER_VAR_137, 4);s = ____BAH_COMPILER_VAR_138;

#line 535 "/opt/bah/json.bah"
i = i+1;

#line 536 "/opt/bah/json.bah"
if ((i<len(arr))) {

#line 537 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_139 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_139[1] = "\02\0\0\0"",\n";____BAH_COMPILER_VAR_139[0] = s;char * ____BAH_COMPILER_VAR_140 =__Bah_multiple_concat(____BAH_COMPILER_VAR_139, 2);s = ____BAH_COMPILER_VAR_140;
}

#line 538 "/opt/bah/json.bah"
else {

#line 539 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_141 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_141[1] = "\01\0\0\0""\n";____BAH_COMPILER_VAR_141[0] = s;char * ____BAH_COMPILER_VAR_142 =__Bah_multiple_concat(____BAH_COMPILER_VAR_141, 2);s = ____BAH_COMPILER_VAR_142;
}
};
}

#line 542 "/opt/bah/json.bah"
else if ((ae->isStruct==true)) {

#line 543 "/opt/bah/json.bah"
array(void *)* arr = memoryAlloc(sizeof(array(void *)));

arr->length = 0;
arr->elemSize = sizeof(void *);

#line 544 "/opt/bah/json.bah"
if ((isMember==false)) {

#line 545 "/opt/bah/json.bah"
arr = e.value;
}

#line 546 "/opt/bah/json.bah"
else {

#line 547 "/opt/bah/json.bah"
void ** ev = e.value;

#line 548 "/opt/bah/json.bah"
arr = *ev;
}

#line 551 "/opt/bah/json.bah"
register long int i = 0;

#line 551 "/opt/bah/json.bah"
while ((i<len(arr))) {

#line 552 "/opt/bah/json.bah"
void * arrElem = arr->data[i];

#line 553 "/opt/bah/json.bah"
ae->value = arrElem;

#line 554 "/opt/bah/json.bah"
register long int j = 0;

#line 554 "/opt/bah/json.bah"
while ((j<len(ae->structLayout))) {

#line 555 "/opt/bah/json.bah"
struct reflectElement m = ae->structLayout->data[j];

#line 556 "/opt/bah/json.bah"
m.value = reflectElement__calculateOffset(&m,ae->value);

#line 557 "/opt/bah/json.bah"

    unsigned int ____BAH_COMPILER_VAR_143 = j;
    __Bah_realocate_arr(ae->structLayout, ____BAH_COMPILER_VAR_143);
    ae->structLayout->data[____BAH_COMPILER_VAR_143] = m;

#line 558 "/opt/bah/json.bah"
j = j+1;
};

#line 560 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_144 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_144[1] = oldToJson__inner(*ae,false,tabs);____BAH_COMPILER_VAR_144[0] = s;char * ____BAH_COMPILER_VAR_145 =__Bah_multiple_concat(____BAH_COMPILER_VAR_144, 2);s = ____BAH_COMPILER_VAR_145;

#line 561 "/opt/bah/json.bah"
i = i+1;

#line 562 "/opt/bah/json.bah"
if ((i<len(arr))) {

#line 563 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_146 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_146[1] = "\02\0\0\0"",\n";____BAH_COMPILER_VAR_146[0] = s;char * ____BAH_COMPILER_VAR_147 =__Bah_multiple_concat(____BAH_COMPILER_VAR_146, 2);s = ____BAH_COMPILER_VAR_147;
}

#line 564 "/opt/bah/json.bah"
else {

#line 565 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_148 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_148[1] = "\01\0\0\0""\n";____BAH_COMPILER_VAR_148[0] = s;char * ____BAH_COMPILER_VAR_149 =__Bah_multiple_concat(____BAH_COMPILER_VAR_148, 2);s = ____BAH_COMPILER_VAR_149;
}
};
}

#line 569 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_150 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_150[1] = "\01\0\0\0""]";____BAH_COMPILER_VAR_150[0] = s;char * ____BAH_COMPILER_VAR_151 =__Bah_multiple_concat(____BAH_COMPILER_VAR_150, 2);s = ____BAH_COMPILER_VAR_151;

#line 570 "/opt/bah/json.bah"
return s;
}

#line 572 "/opt/bah/json.bah"
return "\01\0\0\0""0";
};

#line 577 "/opt/bah/json.bah"
char * oldToJson(struct reflectElement e){

#line 578 "/opt/bah/json.bah"
return oldToJson__inner(e,false,0);
};

#line 586 "/opt/bah/json.bah"
char * toJson(struct reflectElement e){

#line 587 "/opt/bah/json.bah"
unsigned long int l = strlen(e.type);

#line 589 "/opt/bah/json.bah"
if (__builtin_expect((e.isArray==false)&&(e.type[l-1+4]!=42), 0)) {

#line 590 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_152 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_152[6] = "\02\0\0\0"").";____BAH_COMPILER_VAR_152[5] = e.name;____BAH_COMPILER_VAR_152[4] = "\051\0\0\0"" but a pointer is required, try: toJson(&";____BAH_COMPILER_VAR_152[3] = e.type;____BAH_COMPILER_VAR_152[2] = "\012\0\0\0"") of type ";____BAH_COMPILER_VAR_152[1] = e.name;____BAH_COMPILER_VAR_152[0] = "\07\0\0\0""toJson(";char * ____BAH_COMPILER_VAR_153 =__Bah_multiple_concat(____BAH_COMPILER_VAR_152, 7);__BAH_panic(____BAH_COMPILER_VAR_153,"\025\0\0\0""/opt/bah/json.bah:590");
}

#line 593 "/opt/bah/json.bah"
if ((e.isArray==false)) {

#line 594 "/opt/bah/json.bah"
unsigned long int ol = l;

#line 595 "/opt/bah/json.bah"
for (; (l>=2)&&(e.type[l-1+4]==42)&&(e.type[l-2+4]==42); 
#line 595 "/opt/bah/json.bah"
--l) {

#line 596 "/opt/bah/json.bah"
if ((e.value==null)) {

#line 597 "/opt/bah/json.bah"
return "\01\0\0\0""0";
}

#line 599 "/opt/bah/json.bah"
void ** v = e.value;

#line 600 "/opt/bah/json.bah"
e.value = *v;
};

#line 602 "/opt/bah/json.bah"
if ((l!=ol)) {

#line 603 "/opt/bah/json.bah"
e.type = cpstringSubsitute(e.type, 0, l);
}
}

#line 607 "/opt/bah/json.bah"
if ((e.value==null)) {

#line 608 "/opt/bah/json.bah"
return "\01\0\0\0""0";
}

#line 611 "/opt/bah/json.bah"
if ((e.isStruct==true)) {

#line 612 "/opt/bah/json.bah"
char * s = "\01\0\0\0""{";

#line 613 "/opt/bah/json.bah"
register long int i = 0;

#line 613 "/opt/bah/json.bah"
for (; (i<len(e.structLayout)); 
#line 613 "/opt/bah/json.bah"
++i) {

#line 614 "/opt/bah/json.bah"
struct reflectElement m = e.structLayout->data[i];

#line 615 "/opt/bah/json.bah"
void * v = e.value;

#line 616 "/opt/bah/json.bah"
if ((m.isArray==true)) {

#line 617 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_154 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_154[1] = "\01\0\0\0""*";____BAH_COMPILER_VAR_154[0] = m.arrayElem->type;char * ____BAH_COMPILER_VAR_155 =__Bah_multiple_concat(____BAH_COMPILER_VAR_154, 2);m.arrayElem->type = ____BAH_COMPILER_VAR_155;
}

#line 618 "/opt/bah/json.bah"
else if ((m.type[strlen(m.type)-1+4]!=42)) {

#line 619 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_156 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_156[1] = "\01\0\0\0""*";____BAH_COMPILER_VAR_156[0] = m.type;char * ____BAH_COMPILER_VAR_157 =__Bah_multiple_concat(____BAH_COMPILER_VAR_156, 2);m.type = ____BAH_COMPILER_VAR_157;
}

#line 621 "/opt/bah/json.bah"
m.value = reflectElement__calculateOffset(&m,e.value);

#line 622 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_158 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_158[3] = toJson(m);____BAH_COMPILER_VAR_158[2] = "\03\0\0\0""\": ";____BAH_COMPILER_VAR_158[1] = m.name;____BAH_COMPILER_VAR_158[0] = "\01\0\0\0""\"";char * ____BAH_COMPILER_VAR_159 =__Bah_multiple_concat(____BAH_COMPILER_VAR_158, 4);char** ____BAH_COMPILER_VAR_160 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_160[1] = ____BAH_COMPILER_VAR_159;____BAH_COMPILER_VAR_160[0] = s;char * ____BAH_COMPILER_VAR_161 =__Bah_multiple_concat(____BAH_COMPILER_VAR_160, 2);s = ____BAH_COMPILER_VAR_161;

#line 623 "/opt/bah/json.bah"
if ((i+1<len(e.structLayout))) {

#line 624 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_162 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_162[1] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_162[0] = s;char * ____BAH_COMPILER_VAR_163 =__Bah_multiple_concat(____BAH_COMPILER_VAR_162, 2);s = ____BAH_COMPILER_VAR_163;
}
};

#line 627 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_164 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_164[1] = "\01\0\0\0""}";____BAH_COMPILER_VAR_164[0] = s;char * ____BAH_COMPILER_VAR_165 =__Bah_multiple_concat(____BAH_COMPILER_VAR_164, 2);s = ____BAH_COMPILER_VAR_165;

#line 628 "/opt/bah/json.bah"
return s;
}

#line 631 "/opt/bah/json.bah"
if ((e.isArray==true)) {

#line 632 "/opt/bah/json.bah"
char * s = "\01\0\0\0""[";

#line 633 "/opt/bah/json.bah"
void ** arrp = e.value;

#line 634 "/opt/bah/json.bah"
array(void *)* arr = (array(void *)*)*arrp;

#line 635 "/opt/bah/json.bah"
if ((arr==null)) {

#line 636 "/opt/bah/json.bah"
return "\02\0\0\0""[]";
}

#line 638 "/opt/bah/json.bah"
void * base = cArr(arr);

#line 639 "/opt/bah/json.bah"
l = len(arr);

#line 640 "/opt/bah/json.bah"
long int es = arr->elemSize;

#line 641 "/opt/bah/json.bah"
struct reflectElement* ae = e.arrayElem;

#line 642 "/opt/bah/json.bah"
if ((ae->type[strlen(ae->type)-1+4]!=42)&&(ae->isArray==false)) {

#line 643 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_166 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_166[1] = "\01\0\0\0""*";____BAH_COMPILER_VAR_166[0] = ae->type;char * ____BAH_COMPILER_VAR_167 =__Bah_multiple_concat(____BAH_COMPILER_VAR_166, 2);ae->type = ____BAH_COMPILER_VAR_167;
}

#line 645 "/opt/bah/json.bah"
register long int i = 0;

#line 645 "/opt/bah/json.bah"
for (; (i<l); 
#line 645 "/opt/bah/json.bah"
++i) {

#line 646 "/opt/bah/json.bah"
struct reflectElement m = *ae;

#line 647 "/opt/bah/json.bah"
m.value = (void *)((long int)base+es*i);

#line 648 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_168 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_168[1] = toJson(m);____BAH_COMPILER_VAR_168[0] = s;char * ____BAH_COMPILER_VAR_169 =__Bah_multiple_concat(____BAH_COMPILER_VAR_168, 2);s = ____BAH_COMPILER_VAR_169;

#line 649 "/opt/bah/json.bah"
if ((i+1<l)) {

#line 650 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_170 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_170[1] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_170[0] = s;char * ____BAH_COMPILER_VAR_171 =__Bah_multiple_concat(____BAH_COMPILER_VAR_170, 2);s = ____BAH_COMPILER_VAR_171;
}
};

#line 653 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_172 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_172[1] = "\01\0\0\0""]";____BAH_COMPILER_VAR_172[0] = s;char * ____BAH_COMPILER_VAR_173 =__Bah_multiple_concat(____BAH_COMPILER_VAR_172, 2);s = ____BAH_COMPILER_VAR_173;

#line 654 "/opt/bah/json.bah"
return s;
}

#line 657 "/opt/bah/json.bah"
if ((strcmp(e.type, "\04\0\0\0""int*") == 0)||(strcmp(e.type, "\06\0\0\0""int32*") == 0)) {

#line 658 "/opt/bah/json.bah"
long int* j = e.value;

#line 659 "/opt/bah/json.bah"
return intToStr(*j);
}

#line 662 "/opt/bah/json.bah"
if ((strcmp(e.type, "\011\0\0\0""cpstring*") == 0)) {

#line 663 "/opt/bah/json.bah"
char ** s = e.value;

#line 664 "/opt/bah/json.bah"
if ((s==null)) {

#line 665 "/opt/bah/json.bah"
return "\02\0\0\0""\"\"";
}

#line 667 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_174 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_174[2] = "\01\0\0\0""\"";____BAH_COMPILER_VAR_174[1] = jsonEscapeStr(*s);____BAH_COMPILER_VAR_174[0] = "\01\0\0\0""\"";char * ____BAH_COMPILER_VAR_175 =__Bah_multiple_concat(____BAH_COMPILER_VAR_174, 3);return ____BAH_COMPILER_VAR_175;
}

#line 670 "/opt/bah/json.bah"
if ((strcmp(e.type, "\06\0\0\0""float*") == 0)||(strcmp(e.type, "\010\0\0\0""float32*") == 0)) {

#line 671 "/opt/bah/json.bah"
double* f = e.value;

#line 672 "/opt/bah/json.bah"
return floatToStr(*f);
}

#line 675 "/opt/bah/json.bah"
if ((strcmp(e.type, "\05\0\0\0""uint*") == 0)||(strcmp(e.type, "\07\0\0\0""uint32*") == 0)) {

#line 676 "/opt/bah/json.bah"
unsigned long int* uj = e.value;

#line 677 "/opt/bah/json.bah"
return intToStr(*uj);
}

#line 680 "/opt/bah/json.bah"
if ((strcmp(e.type, "\05\0\0\0""char*") == 0)) {

#line 681 "/opt/bah/json.bah"
char* c = e.value;

#line 682 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_176 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_176[2] = "\01\0\0\0""\"";____BAH_COMPILER_VAR_176[1] = charToString(*c);____BAH_COMPILER_VAR_176[0] = "\01\0\0\0""\"";char * ____BAH_COMPILER_VAR_177 =__Bah_multiple_concat(____BAH_COMPILER_VAR_176, 3);return ____BAH_COMPILER_VAR_177;
}

#line 685 "/opt/bah/json.bah"
if ((strcmp(e.type, "\05\0\0\0""bool*") == 0)) {

#line 686 "/opt/bah/json.bah"
char* b = e.value;

#line 687 "/opt/bah/json.bah"
if ((*b==true)) {

#line 688 "/opt/bah/json.bah"
return "\04\0\0\0""true";
}

#line 690 "/opt/bah/json.bah"
return "\05\0\0\0""false";
}

#line 693 "/opt/bah/json.bah"
return "\04\0\0\0""null";
};
#include <stdlib.h>

#line 10 "/opt/bah/path.bah"
char * absPath(char * path){

#line 18 "/opt/bah/path.bah"
char * buff = memoryAlloc(4096);

#line 19 "/opt/bah/path.bah"
char * p = cStrToBah(_fullpath(cStr(buff),cStr(path),4095));

#line 20 "/opt/bah/path.bah"
struct string s = string(p);

#line 21 "/opt/bah/path.bah"
string__replace(&s,"\01\0\0\0""\\","\01\0\0\0""/");

#line 22 "/opt/bah/path.bah"
p = string__str(&s);

#line 24 "/opt/bah/path.bah"
return p;
};

#line 29 "/opt/bah/path.bah"
char * getCurrentPath(){

#line 30 "/opt/bah/path.bah"
char * cwd = memoryAlloc(4096);

#line 31 "/opt/bah/path.bah"
getcwd(cStr(cwd),4096);

#line 32 "/opt/bah/path.bah"
return cwd;
};

#line 38 "/opt/bah/path.bah"
char isInside(char * basePath,char * subPath){

#line 39 "/opt/bah/path.bah"
char * abs1 = absPath(basePath);

#line 40 "/opt/bah/path.bah"
char * abs2 = absPath(subPath);

#line 41 "/opt/bah/path.bah"
return (strHasPrefix(subPath,basePath)==true);
};

#line 47 "/opt/bah/path.bah"
void setCurrentPath(char * s){

#line 48 "/opt/bah/path.bah"
chdir(cStr(s));
};

#line 24 "/home/alois/Documents/bah-bah/src/main.bah"
char * BAH_DIR;

#line 25 "/home/alois/Documents/bah-bah/src/main.bah"
char * BAH_OS;

#line 26 "/home/alois/Documents/bah-bah/src/main.bah"
char * BAH_CC;

#line 29 "/home/alois/Documents/bah-bah/src/main.bah"
#define BAH_VERSION "\020\0\0\0""v1.3 (build 139)"

#line 31 "/home/alois/Documents/bah-bah/src/main.bah"
char debug;

#line 32 "/home/alois/Documents/bah-bah/src/main.bah"
char verboseRuntime;

#line 33 "/home/alois/Documents/bah-bah/src/main.bah"
char isObject;

#line 34 "/home/alois/Documents/bah-bah/src/main.bah"
char isUnsafe;

#line 35 "/home/alois/Documents/bah-bah/src/main.bah"
char isOptimized;

#line 36 "/home/alois/Documents/bah-bah/src/main.bah"
char noticeEnabled;

#line 37 "/home/alois/Documents/bah-bah/src/main.bah"
char RAIIenabled;

#line 38 "/home/alois/Documents/bah-bah/src/main.bah"
char isFixMeEnabled;

#line 40 "/home/alois/Documents/bah-bah/src/main.bah"
char * execName;

#line 41 "/home/alois/Documents/bah-bah/src/main.bah"
char isSubObject;

#line 42 "/home/alois/Documents/bah-bah/src/main.bah"
char isImportedSubObject;

#line 1 "/home/alois/Documents/bah-bah/src/globals.bah"
struct rope* OUTPUT;

#line 2 "/home/alois/Documents/bah-bah/src/globals.bah"
char * NEXT_LINE;

#line 4 "/home/alois/Documents/bah-bah/src/globals.bah"
struct rope* INIT;

#line 6 "/home/alois/Documents/bah-bah/src/globals.bah"
struct rope* postDeclHandle;

#line 9 "/home/alois/Documents/bah-bah/src/globals.bah"
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

#line 30 "/home/alois/Documents/bah-bah/src/globals.bah"
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

#line 36 "/home/alois/Documents/bah-bah/src/globals.bah"
struct func {
char * name;
array(struct variable*)* args;
struct variable* returns;
char returned;
char isBinding;
char isCbinding;
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

#line 58 "/home/alois/Documents/bah-bah/src/globals.bah"
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

#line 69 "/home/alois/Documents/bah-bah/src/globals.bah"
struct varCheck {
struct variable* v;
char checkNull;
};

#line 75 "/home/alois/Documents/bah-bah/src/globals.bah"
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

#line 89 "/home/alois/Documents/bah-bah/src/globals.bah"
if ((e==null)) {

#line 90 "/home/alois/Documents/bah-bah/src/globals.bah"
return false;
}

#line 92 "/home/alois/Documents/bah-bah/src/globals.bah"
while ((e->parent!=null)) {

#line 93 "/home/alois/Documents/bah-bah/src/globals.bah"
if ((e->parent==this)) {

#line 94 "/home/alois/Documents/bah-bah/src/globals.bah"
return true;
}

#line 96 "/home/alois/Documents/bah-bah/src/globals.bah"
e = e->parent;
};

#line 98 "/home/alois/Documents/bah-bah/src/globals.bah"
return false;
};

#line 104 "/home/alois/Documents/bah-bah/src/globals.bah"
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

#line 121 "/home/alois/Documents/bah-bah/src/globals.bah"
char shouldOnlyDecl;

#line 123 "/home/alois/Documents/bah-bah/src/globals.bah"
struct compilerStateTag compilerState;

#line 125 "/home/alois/Documents/bah-bah/src/globals.bah"
struct cStruct* currentCStruct;

#line 127 "/home/alois/Documents/bah-bah/src/globals.bah"
long int threadCount;

#line 129 "/home/alois/Documents/bah-bah/src/globals.bah"
struct func* currentFn;

#line 131 "/home/alois/Documents/bah-bah/src/globals.bah"
long int totalLines;

#line 133 "/home/alois/Documents/bah-bah/src/globals.bah"
long int totalSize;

#line 135 "/home/alois/Documents/bah-bah/src/globals.bah"
long int totalLexerTime;

#line 137 "/home/alois/Documents/bah-bah/src/globals.bah"
char RCPenabled;

#line 139 "/home/alois/Documents/bah-bah/src/globals.bah"
long int RCPlevel;

#line 141 "/home/alois/Documents/bah-bah/src/globals.bah"
struct flags flags;

#line 143 "/home/alois/Documents/bah-bah/src/globals.bah"
struct variable* currSetVar;

#line 146 "/home/alois/Documents/bah-bah/src/globals.bah"
array(struct varCheck)* currChecks;

#line 148 "/home/alois/Documents/bah-bah/src/globals.bah"
char prevIfExits;

#line 150 "/home/alois/Documents/bah-bah/src/globals.bah"
array(struct varCheck)* prevIfChecks;

#line 152 "/home/alois/Documents/bah-bah/src/globals.bah"
char * prevIfShortcut;

#line 154 "/home/alois/Documents/bah-bah/src/globals.bah"
struct rope* begIfHandle;
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
array(char)* enclavers;

#line 46 "/home/alois/Documents/bah-bah/src/lexer.bah"
array(char)* syntaxes;

#line 48 "/home/alois/Documents/bah-bah/src/lexer.bah"
array(char *)* keywords;

#line 54 "/home/alois/Documents/bah-bah/src/lexer.bah"
char ____BAH_COMPILER_VAR_179(array(char *)* arr, char * el) {
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
struct Tok makeToken(long int pos,long int lineNb,__BAH_ARR_TYPE_char cont,tokenType type){

#line 55 "/home/alois/Documents/bah-bah/src/lexer.bah"
struct Tok ____BAH_COMPILER_VAR_178 = {};
____BAH_COMPILER_VAR_178.cont = "\0\0\0\0""";
____BAH_COMPILER_VAR_178.ogCont = "\0\0\0\0""";
____BAH_COMPILER_VAR_178.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_178.line = 1;
____BAH_COMPILER_VAR_178.begLine = 1;
____BAH_COMPILER_VAR_178.bahType = "\0\0\0\0""";
struct Tok t = ____BAH_COMPILER_VAR_178;

#line 56 "/home/alois/Documents/bah-bah/src/lexer.bah"
t.cont = arrToStr(cont);

#line 57 "/home/alois/Documents/bah-bah/src/lexer.bah"
t.ogCont = t.cont;

#line 58 "/home/alois/Documents/bah-bah/src/lexer.bah"
clear(cont);

#line 60 "/home/alois/Documents/bah-bah/src/lexer.bah"
t.pos = pos;

#line 61 "/home/alois/Documents/bah-bah/src/lexer.bah"
t.line = lineNb;

#line 62 "/home/alois/Documents/bah-bah/src/lexer.bah"
t.type = type;

#line 64 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((type==TOKEN_TYPE_VAR)&&____BAH_COMPILER_VAR_179(keywords, t.cont)) {

#line 65 "/home/alois/Documents/bah-bah/src/lexer.bah"
t.type = TOKEN_TYPE_KEYWORD;
}

#line 66 "/home/alois/Documents/bah-bah/src/lexer.bah"
else if ((type==TOKEN_TYPE_INT)||(type==TOKEN_TYPE_STR)||(type==TOKEN_TYPE_FLOAT)||(type==TOKEN_TYPE_VAR)||(type==TOKEN_TYPE_BOOL)||(type==TOKEN_TYPE_CHAR)) {

#line 67 "/home/alois/Documents/bah-bah/src/lexer.bah"
t.isValue = true;
}

#line 69 "/home/alois/Documents/bah-bah/src/lexer.bah"
return t;
};

#line 72 "/home/alois/Documents/bah-bah/src/lexer.bah"
char isMinus(char c,char nc){

#line 73 "/home/alois/Documents/bah-bah/src/lexer.bah"
return (c==45)&&isNumber(nc);
};

#line 76 "/home/alois/Documents/bah-bah/src/lexer.bah"
void lexerErr(long int line,long int pos,char * msg){

#line 77 "/home/alois/Documents/bah-bah/src/lexer.bah"
char * lineStr = intToStr(line);

#line 78 "/home/alois/Documents/bah-bah/src/lexer.bah"
char * posStr = intToStr(pos);

#line 79 "/home/alois/Documents/bah-bah/src/lexer.bah"
char** ____BAH_COMPILER_VAR_180 = alloca(8 * sizeof(char*));____BAH_COMPILER_VAR_180[7] = msg;____BAH_COMPILER_VAR_180[6] = "\06\0\0\0""\n\e[0m\n";____BAH_COMPILER_VAR_180[5] = posStr;____BAH_COMPILER_VAR_180[4] = "\01\0\0\0"":";____BAH_COMPILER_VAR_180[3] = lineStr;____BAH_COMPILER_VAR_180[2] = "\01\0\0\0"":";____BAH_COMPILER_VAR_180[1] = compilerState.currentFile;____BAH_COMPILER_VAR_180[0] = "\031\0\0\0""\e[1;31m[LEXER-ERROR]\e[0m ";char * ____BAH_COMPILER_VAR_181 =__Bah_multiple_concat(____BAH_COMPILER_VAR_180, 8);println(____BAH_COMPILER_VAR_181);

#line 80 "/home/alois/Documents/bah-bah/src/lexer.bah"
exit(1);
};

#line 83 "/home/alois/Documents/bah-bah/src/lexer.bah"
char ____BAH_COMPILER_VAR_198(array(char)* arr, char el) {
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
char ____BAH_COMPILER_VAR_201(array(char)* arr, char el) {
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
char ____BAH_COMPILER_VAR_207(array(char)* arr, char el) {
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
typedef array(struct Tok)* __BAH_ARR_TYPE_Tok;
__BAH_ARR_TYPE_Tok lexer(char * s,unsigned long int codeLength){

#line 85 "/home/alois/Documents/bah-bah/src/lexer.bah"
long int dur = getTimeUnix();

#line 86 "/home/alois/Documents/bah-bah/src/lexer.bah"
array(struct Tok)* tokens = memoryAlloc(sizeof(array(struct Tok)));

tokens->length = 0;
tokens->elemSize = sizeof(struct Tok);

#line 88 "/home/alois/Documents/bah-bah/src/lexer.bah"
totalSize = totalSize+codeLength;

#line 90 "/home/alois/Documents/bah-bah/src/lexer.bah"
array(char)* memory = memoryAlloc(sizeof(array(char)));

memory->length = 0;
memory->elemSize = sizeof(char);

#line 92 "/home/alois/Documents/bah-bah/src/lexer.bah"
long int lineNb = 1;

#line 94 "/home/alois/Documents/bah-bah/src/lexer.bah"
register long int i = 0;

#line 94 "/home/alois/Documents/bah-bah/src/lexer.bah"
for (; (i<codeLength); 
#line 94 "/home/alois/Documents/bah-bah/src/lexer.bah"
++i) {

#line 95 "/home/alois/Documents/bah-bah/src/lexer.bah"
char c = s[i+4];

#line 96 "/home/alois/Documents/bah-bah/src/lexer.bah"
char nc = (char)0;

#line 97 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((i+1<codeLength)) {

#line 98 "/home/alois/Documents/bah-bah/src/lexer.bah"
nc = s[i+1+4];
}

#line 101 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((c==47)) {

#line 103 "/home/alois/Documents/bah-bah/src/lexer.bah"
nc = s[i+1+4];

#line 104 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((nc==47)) {

#line 106 "/home/alois/Documents/bah-bah/src/lexer.bah"
for (; (i<codeLength); 
#line 106 "/home/alois/Documents/bah-bah/src/lexer.bah"
++i) {

#line 107 "/home/alois/Documents/bah-bah/src/lexer.bah"
c = s[i+4];

#line 108 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((c==(char)10)) {

#line 109 "/home/alois/Documents/bah-bah/src/lexer.bah"
break;
}
};

#line 113 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((i==codeLength)) {

#line 114 "/home/alois/Documents/bah-bah/src/lexer.bah"
break;
}
}
}

#line 120 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((c==(char)10)) {

#line 121 "/home/alois/Documents/bah-bah/src/lexer.bah"
++lineNb;
}

#line 125 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((c==34)) {

#line 126 "/home/alois/Documents/bah-bah/src/lexer.bah"
long int pos = i;

#line 127 "/home/alois/Documents/bah-bah/src/lexer.bah"
long int begLine = lineNb;

#line 128 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_182 = 0;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_182);
    memory->data[____BAH_COMPILER_VAR_182] = c;

#line 129 "/home/alois/Documents/bah-bah/src/lexer.bah"
i = i+1;

#line 130 "/home/alois/Documents/bah-bah/src/lexer.bah"
for (; (i<codeLength); 
#line 130 "/home/alois/Documents/bah-bah/src/lexer.bah"
++i) {

#line 131 "/home/alois/Documents/bah-bah/src/lexer.bah"
c = s[i+4];

#line 132 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((c==(char)92)) {

#line 133 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_183 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_183);
    memory->data[____BAH_COMPILER_VAR_183] = (char)92;

#line 134 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_184 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_184);
    memory->data[____BAH_COMPILER_VAR_184] = s[i+1+4];

#line 135 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((s[i+1+4]==(char)10)) {

#line 136 "/home/alois/Documents/bah-bah/src/lexer.bah"
++lineNb;
}

#line 138 "/home/alois/Documents/bah-bah/src/lexer.bah"
++i;

#line 139 "/home/alois/Documents/bah-bah/src/lexer.bah"
continue;
}

#line 143 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((c==34)) {

#line 144 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_185 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_185);
    memory->data[____BAH_COMPILER_VAR_185] = c;

#line 145 "/home/alois/Documents/bah-bah/src/lexer.bah"
break;
}

#line 148 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((c==(char)10)) {

#line 149 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_186 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_186);
    memory->data[____BAH_COMPILER_VAR_186] = (char)92;

#line 150 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_187 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_187);
    memory->data[____BAH_COMPILER_VAR_187] = 110;

#line 151 "/home/alois/Documents/bah-bah/src/lexer.bah"
++lineNb;

#line 152 "/home/alois/Documents/bah-bah/src/lexer.bah"
continue;
}

#line 154 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_188 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_188);
    memory->data[____BAH_COMPILER_VAR_188] = c;
};

#line 156 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_189 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_189);
    tokens->data[____BAH_COMPILER_VAR_189] = makeToken(pos,lineNb,memory,TOKEN_TYPE_STR);

#line 157 "/home/alois/Documents/bah-bah/src/lexer.bah"
struct Tok lt = tokens->data[len(tokens)-1];

#line 158 "/home/alois/Documents/bah-bah/src/lexer.bah"
lt.begLine = begLine;

#line 159 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_190 = len(tokens)-1;
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_190);
    tokens->data[____BAH_COMPILER_VAR_190] = lt;
}

#line 160 "/home/alois/Documents/bah-bah/src/lexer.bah"
else if (isNumber(c)||isMinus(c,nc)) {

#line 162 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_191 = 0;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_191);
    memory->data[____BAH_COMPILER_VAR_191] = c;

#line 163 "/home/alois/Documents/bah-bah/src/lexer.bah"
long int pos = i;

#line 164 "/home/alois/Documents/bah-bah/src/lexer.bah"
i = i+1;

#line 165 "/home/alois/Documents/bah-bah/src/lexer.bah"
tokenType currentType = TOKEN_TYPE_INT;

#line 166 "/home/alois/Documents/bah-bah/src/lexer.bah"
char isHex = false;

#line 167 "/home/alois/Documents/bah-bah/src/lexer.bah"
for (; (i<codeLength); 
#line 167 "/home/alois/Documents/bah-bah/src/lexer.bah"
++i) {

#line 168 "/home/alois/Documents/bah-bah/src/lexer.bah"
c = s[i+4];

#line 169 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((c==(char)46)) {

#line 170 "/home/alois/Documents/bah-bah/src/lexer.bah"
currentType = TOKEN_TYPE_FLOAT;
}

#line 171 "/home/alois/Documents/bah-bah/src/lexer.bah"
else if ((isNumber(c)==false)) {

#line 172 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((isHex==false)) {

#line 173 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((c==120)) {

#line 174 "/home/alois/Documents/bah-bah/src/lexer.bah"
isHex = true;
}

#line 175 "/home/alois/Documents/bah-bah/src/lexer.bah"
else {

#line 176 "/home/alois/Documents/bah-bah/src/lexer.bah"
break;
}
}

#line 178 "/home/alois/Documents/bah-bah/src/lexer.bah"
else {

#line 179 "/home/alois/Documents/bah-bah/src/lexer.bah"
if (isUpper(c)) {

#line 180 "/home/alois/Documents/bah-bah/src/lexer.bah"
c = c+(char)32;
}

#line 182 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((c<97)||(c>102)) {

#line 183 "/home/alois/Documents/bah-bah/src/lexer.bah"
break;
}
}

#line 186 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((isHex==false)) {

#line 187 "/home/alois/Documents/bah-bah/src/lexer.bah"
break;
}
}

#line 190 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_192 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_192);
    memory->data[____BAH_COMPILER_VAR_192] = c;
};

#line 192 "/home/alois/Documents/bah-bah/src/lexer.bah"
--i;

#line 193 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_193 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_193);
    tokens->data[____BAH_COMPILER_VAR_193] = makeToken(pos,lineNb,memory,currentType);
}

#line 194 "/home/alois/Documents/bah-bah/src/lexer.bah"
else if ((c==(char)39)) {

#line 196 "/home/alois/Documents/bah-bah/src/lexer.bah"
++i;

#line 197 "/home/alois/Documents/bah-bah/src/lexer.bah"
char n = s[i+4];

#line 198 "/home/alois/Documents/bah-bah/src/lexer.bah"
char * toInt = intToStr((long int)nc);

#line 199 "/home/alois/Documents/bah-bah/src/lexer.bah"
memory = strToArr(toInt);

#line 200 "/home/alois/Documents/bah-bah/src/lexer.bah"
++i;

#line 201 "/home/alois/Documents/bah-bah/src/lexer.bah"
c = s[i+4];

#line 202 "/home/alois/Documents/bah-bah/src/lexer.bah"
if (__builtin_expect((c!=(char)39), 0)) {

#line 203 "/home/alois/Documents/bah-bah/src/lexer.bah"
lexerErr(lineNb,i,"\050\0\0\0""Missing closing tag in char declaration.");
}

#line 205 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_194 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_194);
    tokens->data[____BAH_COMPILER_VAR_194] = makeToken(i-1,lineNb,memory,TOKEN_TYPE_CHAR);
}

#line 206 "/home/alois/Documents/bah-bah/src/lexer.bah"
else if ((c==(char)35)) {

#line 208 "/home/alois/Documents/bah-bah/src/lexer.bah"
long int pos = i;

#line 209 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_195 = 0;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_195);
    memory->data[____BAH_COMPILER_VAR_195] = c;

#line 210 "/home/alois/Documents/bah-bah/src/lexer.bah"
++i;

#line 211 "/home/alois/Documents/bah-bah/src/lexer.bah"
for (; (i<codeLength); 
#line 211 "/home/alois/Documents/bah-bah/src/lexer.bah"
++i) {

#line 212 "/home/alois/Documents/bah-bah/src/lexer.bah"
c = s[i+4];

#line 213 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((isAlphaNumeric(c)==false)) {

#line 214 "/home/alois/Documents/bah-bah/src/lexer.bah"
break;
}

#line 216 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_196 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_196);
    memory->data[____BAH_COMPILER_VAR_196] = c;
};

#line 218 "/home/alois/Documents/bah-bah/src/lexer.bah"
--i;

#line 219 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_197 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_197);
    tokens->data[____BAH_COMPILER_VAR_197] = makeToken(pos,lineNb,memory,TOKEN_TYPE_KEYWORD);
}

#line 220 "/home/alois/Documents/bah-bah/src/lexer.bah"
else if (____BAH_COMPILER_VAR_198(enclavers, c)) {

#line 222 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_199 = 0;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_199);
    memory->data[____BAH_COMPILER_VAR_199] = c;

#line 223 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_200 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_200);
    tokens->data[____BAH_COMPILER_VAR_200] = makeToken(i,lineNb,memory,TOKEN_TYPE_ENCL);
}

#line 224 "/home/alois/Documents/bah-bah/src/lexer.bah"
else if (____BAH_COMPILER_VAR_201(syntaxes, c)) {

#line 228 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((c==60)) {

#line 229 "/home/alois/Documents/bah-bah/src/lexer.bah"
long int pos = i;

#line 230 "/home/alois/Documents/bah-bah/src/lexer.bah"
char isCast = false;

#line 231 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_202 = 0;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_202);
    memory->data[____BAH_COMPILER_VAR_202] = c;

#line 232 "/home/alois/Documents/bah-bah/src/lexer.bah"
++i;

#line 233 "/home/alois/Documents/bah-bah/src/lexer.bah"
for (; (i<codeLength); 
#line 233 "/home/alois/Documents/bah-bah/src/lexer.bah"
++i) {

#line 234 "/home/alois/Documents/bah-bah/src/lexer.bah"
c = s[i+4];

#line 235 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((c==62)) {

#line 236 "/home/alois/Documents/bah-bah/src/lexer.bah"
isCast = true;

#line 237 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_203 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_203);
    memory->data[____BAH_COMPILER_VAR_203] = c;

#line 238 "/home/alois/Documents/bah-bah/src/lexer.bah"
break;
}

#line 240 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((isAlphaNumeric(c)==false)&&(c!=42)&&(c!=58)&&(c!=95)&&(c!=91)&&(c!=93)) {

#line 241 "/home/alois/Documents/bah-bah/src/lexer.bah"
break;
}

#line 243 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_204 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_204);
    memory->data[____BAH_COMPILER_VAR_204] = c;
};

#line 245 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((isCast==true)) {

#line 246 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_205 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_205);
    tokens->data[____BAH_COMPILER_VAR_205] = makeToken(pos,lineNb,memory,TOKEN_TYPE_CAST);

#line 247 "/home/alois/Documents/bah-bah/src/lexer.bah"
continue;
}

#line 249 "/home/alois/Documents/bah-bah/src/lexer.bah"
i = pos;

#line 250 "/home/alois/Documents/bah-bah/src/lexer.bah"
c = 60;

#line 251 "/home/alois/Documents/bah-bah/src/lexer.bah"
clear(memory);
}

#line 254 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_206 = 0;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_206);
    memory->data[____BAH_COMPILER_VAR_206] = c;

#line 255 "/home/alois/Documents/bah-bah/src/lexer.bah"
long int pos = i;

#line 256 "/home/alois/Documents/bah-bah/src/lexer.bah"
++i;

#line 257 "/home/alois/Documents/bah-bah/src/lexer.bah"
char fc = c;

#line 258 "/home/alois/Documents/bah-bah/src/lexer.bah"
for (; (i<codeLength); 
#line 258 "/home/alois/Documents/bah-bah/src/lexer.bah"
++i) {

#line 259 "/home/alois/Documents/bah-bah/src/lexer.bah"
c = s[i+4];

#line 260 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((____BAH_COMPILER_VAR_207(syntaxes, c)==false)) {

#line 261 "/home/alois/Documents/bah-bah/src/lexer.bah"
break;
}

#line 264 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((fc==60)) {

#line 265 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((c!=45)&&(c!=61)&&(c!=60)) {

#line 266 "/home/alois/Documents/bah-bah/src/lexer.bah"
break;
}
}

#line 268 "/home/alois/Documents/bah-bah/src/lexer.bah"
else if ((c==124)) {

#line 269 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((fc!=c)) {

#line 270 "/home/alois/Documents/bah-bah/src/lexer.bah"
break;
}
}

#line 272 "/home/alois/Documents/bah-bah/src/lexer.bah"
else if ((c==38)) {

#line 273 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((fc!=c)) {

#line 274 "/home/alois/Documents/bah-bah/src/lexer.bah"
break;
}
}

#line 276 "/home/alois/Documents/bah-bah/src/lexer.bah"
else if ((c!=61)) {

#line 277 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((c!=62)) {

#line 278 "/home/alois/Documents/bah-bah/src/lexer.bah"
break;
}
}

#line 281 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_208 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_208);
    memory->data[____BAH_COMPILER_VAR_208] = c;
};

#line 283 "/home/alois/Documents/bah-bah/src/lexer.bah"
--i;

#line 284 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_209 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_209);
    tokens->data[____BAH_COMPILER_VAR_209] = makeToken(pos,lineNb,memory,TOKEN_TYPE_SYNTAX);
}

#line 285 "/home/alois/Documents/bah-bah/src/lexer.bah"
else if ((c==46)) {

#line 287 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_210 = 0;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_210);
    memory->data[____BAH_COMPILER_VAR_210] = c;

#line 288 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_211 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_211);
    tokens->data[____BAH_COMPILER_VAR_211] = makeToken(i,lineNb,memory,TOKEN_TYPE_SEP);
}

#line 289 "/home/alois/Documents/bah-bah/src/lexer.bah"
else if (isAlphaNumeric(c)||(c==95)) {

#line 291 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_212 = 0;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_212);
    memory->data[____BAH_COMPILER_VAR_212] = c;

#line 292 "/home/alois/Documents/bah-bah/src/lexer.bah"
long int pos = i;

#line 293 "/home/alois/Documents/bah-bah/src/lexer.bah"
++i;

#line 295 "/home/alois/Documents/bah-bah/src/lexer.bah"
for (; (i<codeLength); 
#line 295 "/home/alois/Documents/bah-bah/src/lexer.bah"
++i) {

#line 296 "/home/alois/Documents/bah-bah/src/lexer.bah"
c = s[i+4];

#line 297 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((isAlphaNumeric(c)==false)) {

#line 298 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((c!=95)) {

#line 299 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((c==62)) {

#line 300 "/home/alois/Documents/bah-bah/src/lexer.bah"
char lc = memory->data[len(memory)-1];

#line 301 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((lc==45)) {

#line 302 "/home/alois/Documents/bah-bah/src/lexer.bah"
--i;

#line 303 "/home/alois/Documents/bah-bah/src/lexer.bah"
break;
}
}

#line 306 "/home/alois/Documents/bah-bah/src/lexer.bah"
break;
}
}

#line 310 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_213 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_213);
    memory->data[____BAH_COMPILER_VAR_213] = c;
};

#line 312 "/home/alois/Documents/bah-bah/src/lexer.bah"
--i;

#line 313 "/home/alois/Documents/bah-bah/src/lexer.bah"
tokenType currentType = TOKEN_TYPE_VAR;

#line 315 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_214 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_214);
    tokens->data[____BAH_COMPILER_VAR_214] = makeToken(pos,lineNb,memory,currentType);
}
};

#line 319 "/home/alois/Documents/bah-bah/src/lexer.bah"
totalLines = totalLines+lineNb-1;

#line 320 "/home/alois/Documents/bah-bah/src/lexer.bah"
dur = getTimeUnix()-dur;

#line 321 "/home/alois/Documents/bah-bah/src/lexer.bah"
totalLexerTime = totalLexerTime+dur;

#line 322 "/home/alois/Documents/bah-bah/src/lexer.bah"
return tokens;
};

#line 3 "/home/alois/Documents/bah-bah/src/struct.bah"
char hasStructSep(struct string* n){

#line 4 "/home/alois/Documents/bah-bah/src/struct.bah"
long int max = n->length-1;

#line 5 "/home/alois/Documents/bah-bah/src/struct.bah"
register long int i = 0;

#line 5 "/home/alois/Documents/bah-bah/src/struct.bah"
for (; (i<max); 
#line 5 "/home/alois/Documents/bah-bah/src/struct.bah"
++i) {

#line 6 "/home/alois/Documents/bah-bah/src/struct.bah"
char c = string__charAt(n,i);

#line 7 "/home/alois/Documents/bah-bah/src/struct.bah"
if ((c==46)) {

#line 8 "/home/alois/Documents/bah-bah/src/struct.bah"
return true;
}

#line 9 "/home/alois/Documents/bah-bah/src/struct.bah"
else if ((c==45)&&(string__charAt(n,i+1)==62)) {

#line 10 "/home/alois/Documents/bah-bah/src/struct.bah"
return true;
}
};

#line 14 "/home/alois/Documents/bah-bah/src/struct.bah"
return false;
};

#line 17 "/home/alois/Documents/bah-bah/src/struct.bah"
struct string splitStructSepBefore(struct string* n){

#line 19 "/home/alois/Documents/bah-bah/src/struct.bah"
if (string__count(n,"\01\0\0\0"".")) {

#line 20 "/home/alois/Documents/bah-bah/src/struct.bah"
struct string res = string(splitStringBefore(*n,"\01\0\0\0""."));

#line 21 "/home/alois/Documents/bah-bah/src/struct.bah"
return res;
}

#line 23 "/home/alois/Documents/bah-bah/src/struct.bah"
if (string__count(n,"\02\0\0\0""->")) {

#line 24 "/home/alois/Documents/bah-bah/src/struct.bah"
struct string res = string(splitStringBefore(*n,"\02\0\0\0""->"));

#line 25 "/home/alois/Documents/bah-bah/src/struct.bah"
return res;
}

#line 28 "/home/alois/Documents/bah-bah/src/struct.bah"
return string("\0\0\0\0""");
};

#line 31 "/home/alois/Documents/bah-bah/src/struct.bah"
struct string splitStructSepAfter(struct string n){

#line 32 "/home/alois/Documents/bah-bah/src/struct.bah"
register long int i = n.length;

#line 32 "/home/alois/Documents/bah-bah/src/struct.bah"
while ((i>0)) {

#line 33 "/home/alois/Documents/bah-bah/src/struct.bah"
char c = string__charAt(&n,i);

#line 34 "/home/alois/Documents/bah-bah/src/struct.bah"
if ((c==46)) {

#line 35 "/home/alois/Documents/bah-bah/src/struct.bah"
break;
}

#line 36 "/home/alois/Documents/bah-bah/src/struct.bah"
else if ((c==62)) {

#line 37 "/home/alois/Documents/bah-bah/src/struct.bah"
char pc = string__charAt(&n,i-1);

#line 38 "/home/alois/Documents/bah-bah/src/struct.bah"
if ((pc==45)) {

#line 39 "/home/alois/Documents/bah-bah/src/struct.bah"
break;
}
}

#line 42 "/home/alois/Documents/bah-bah/src/struct.bah"
i = i-1;
};

#line 44 "/home/alois/Documents/bah-bah/src/struct.bah"
i = i+1;

#line 45 "/home/alois/Documents/bah-bah/src/struct.bah"
string__trimLeft(&n,i);

#line 46 "/home/alois/Documents/bah-bah/src/struct.bah"
return n;
};

#line 50 "/home/alois/Documents/bah-bah/src/struct.bah"
struct cStruct* searchStruct(char * name,struct Elems* elems){

#line 51 "/home/alois/Documents/bah-bah/src/struct.bah"
if ((strlen(name)==0)) {

#line 52 "/home/alois/Documents/bah-bah/src/struct.bah"
return null;
}

#line 56 "/home/alois/Documents/bah-bah/src/struct.bah"
register long int i = 0;

#line 56 "/home/alois/Documents/bah-bah/src/struct.bah"
for (; (i<strlen(name)); 
#line 56 "/home/alois/Documents/bah-bah/src/struct.bah"
++i) {

#line 57 "/home/alois/Documents/bah-bah/src/struct.bah"
if ((name[strlen(name)-i-1+4]!=42)) {

#line 58 "/home/alois/Documents/bah-bah/src/struct.bah"
break;
}
};

#line 61 "/home/alois/Documents/bah-bah/src/struct.bah"
if ((i!=0)) {

#line 62 "/home/alois/Documents/bah-bah/src/struct.bah"
name = cpstringSubsitute(name, 0, strlen(name)-i);
}

#line 65 "/home/alois/Documents/bah-bah/src/struct.bah"
i = len(elems->structs)-1;

#line 65 "/home/alois/Documents/bah-bah/src/struct.bah"
for (; (i!=-1); 
#line 65 "/home/alois/Documents/bah-bah/src/struct.bah"
--i) {

#line 66 "/home/alois/Documents/bah-bah/src/struct.bah"
struct cStruct* s = elems->structs->data[i];

#line 67 "/home/alois/Documents/bah-bah/src/struct.bah"
if ((strcmp(s->name, name) == 0)) {

#line 68 "/home/alois/Documents/bah-bah/src/struct.bah"
return s;
}
};

#line 71 "/home/alois/Documents/bah-bah/src/struct.bah"
return null;
};

#line 74 "/home/alois/Documents/bah-bah/src/struct.bah"
struct structMemb* searchStructMemb(char * name,struct cStruct* s,struct Elems* elems){

#line 75 "/home/alois/Documents/bah-bah/src/struct.bah"
struct string n = string(name);

#line 76 "/home/alois/Documents/bah-bah/src/struct.bah"
if (hasStructSep(&n)) {

#line 77 "/home/alois/Documents/bah-bah/src/struct.bah"
struct string rn = splitStructSepBefore(&n);

#line 78 "/home/alois/Documents/bah-bah/src/struct.bah"
name = rn.content;

#line 79 "/home/alois/Documents/bah-bah/src/struct.bah"
if ((string__charAt(&n,rn.length)==46)) {

#line 80 "/home/alois/Documents/bah-bah/src/struct.bah"
string__trimLeft(&n,1+rn.length);
}

#line 81 "/home/alois/Documents/bah-bah/src/struct.bah"
else {

#line 82 "/home/alois/Documents/bah-bah/src/struct.bah"
string__trimLeft(&n,2+rn.length);
}

#line 84 "/home/alois/Documents/bah-bah/src/struct.bah"
char * membs = n.content;

#line 85 "/home/alois/Documents/bah-bah/src/struct.bah"
struct structMemb* memb = searchStructMemb(name,s,elems);

#line 86 "/home/alois/Documents/bah-bah/src/struct.bah"
if ((n.length>0)) {

#line 87 "/home/alois/Documents/bah-bah/src/struct.bah"
s = searchStruct(memb->type,elems);

#line 88 "/home/alois/Documents/bah-bah/src/struct.bah"
char * nstr = string__str(&n);

#line 89 "/home/alois/Documents/bah-bah/src/struct.bah"
memb = searchStructMemb(nstr,s,elems);
}

#line 91 "/home/alois/Documents/bah-bah/src/struct.bah"
return memb;
}

#line 94 "/home/alois/Documents/bah-bah/src/struct.bah"
array(struct structMemb*)* members = s->members;

#line 95 "/home/alois/Documents/bah-bah/src/struct.bah"
register long int i = 0;

#line 95 "/home/alois/Documents/bah-bah/src/struct.bah"
while ((i<len(members))) {

#line 96 "/home/alois/Documents/bah-bah/src/struct.bah"
struct structMemb* m = members->data[i];

#line 97 "/home/alois/Documents/bah-bah/src/struct.bah"
if ((strcmp(m->name, name) == 0)) {

#line 98 "/home/alois/Documents/bah-bah/src/struct.bah"
return m;
}

#line 100 "/home/alois/Documents/bah-bah/src/struct.bah"
i = i+1;
};

#line 102 "/home/alois/Documents/bah-bah/src/struct.bah"
array(struct func*)* mthds = s->methods;

#line 103 "/home/alois/Documents/bah-bah/src/struct.bah"
i = 0;

#line 103 "/home/alois/Documents/bah-bah/src/struct.bah"
while ((i<len(mthds))) {

#line 104 "/home/alois/Documents/bah-bah/src/struct.bah"
struct func* m = mthds->data[i];

#line 105 "/home/alois/Documents/bah-bah/src/struct.bah"
if ((strcmp(m->name, name) == 0)) {

#line 106 "/home/alois/Documents/bah-bah/src/struct.bah"
struct structMemb* ____BAH_COMPILER_VAR_215 = memoryAlloc(sizeof(struct structMemb));
____BAH_COMPILER_VAR_215->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_215->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_215->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_215->from = "\0\0\0\0""";
____BAH_COMPILER_VAR_215->def = "\0\0\0\0""";
struct structMemb* sm = ____BAH_COMPILER_VAR_215;

#line 107 "/home/alois/Documents/bah-bah/src/struct.bah"
sm->name = m->name;

#line 108 "/home/alois/Documents/bah-bah/src/struct.bah"
sm->from = m->from;

#line 109 "/home/alois/Documents/bah-bah/src/struct.bah"
sm->type = m->returns->type;

#line 110 "/home/alois/Documents/bah-bah/src/struct.bah"
sm->isFn = true;

#line 111 "/home/alois/Documents/bah-bah/src/struct.bah"
return sm;
}

#line 113 "/home/alois/Documents/bah-bah/src/struct.bah"
i = i+1;
};

#line 116 "/home/alois/Documents/bah-bah/src/struct.bah"
if ((strlen(s->extendedFrom)==0)) {

#line 117 "/home/alois/Documents/bah-bah/src/struct.bah"
return null;
}

#line 120 "/home/alois/Documents/bah-bah/src/struct.bah"
struct cStruct* es = searchStruct(s->extendedFrom,elems);

#line 121 "/home/alois/Documents/bah-bah/src/struct.bah"
if ((es==null)) {

#line 122 "/home/alois/Documents/bah-bah/src/struct.bah"
return null;
}

#line 125 "/home/alois/Documents/bah-bah/src/struct.bah"
return searchStructMemb(name,es,elems);
};
struct func* searchFunc(char * n,struct Elems* e,char c);
struct func* parseFnType(struct string n);

#line 131 "/home/alois/Documents/bah-bah/src/struct.bah"
struct func* searchStructMethod(char * name,struct cStruct* s,struct Elems* elems){

#line 132 "/home/alois/Documents/bah-bah/src/struct.bah"
if ((s==null)) {

#line 133 "/home/alois/Documents/bah-bah/src/struct.bah"
return null;
}

#line 136 "/home/alois/Documents/bah-bah/src/struct.bah"
char** ____BAH_COMPILER_VAR_216 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_216[2] = name;____BAH_COMPILER_VAR_216[1] = "\02\0\0\0""__";____BAH_COMPILER_VAR_216[0] = s->name;char * ____BAH_COMPILER_VAR_217 =__Bah_multiple_concat(____BAH_COMPILER_VAR_216, 3);struct func* fn = searchFunc(____BAH_COMPILER_VAR_217,elems,true);

#line 137 "/home/alois/Documents/bah-bah/src/struct.bah"
if ((fn!=null)) {

#line 138 "/home/alois/Documents/bah-bah/src/struct.bah"
return fn;
}

#line 141 "/home/alois/Documents/bah-bah/src/struct.bah"
register long int i = 0;

#line 141 "/home/alois/Documents/bah-bah/src/struct.bah"
for (; (i<len(s->members)); 
#line 141 "/home/alois/Documents/bah-bah/src/struct.bah"
++i) {

#line 143 "/home/alois/Documents/bah-bah/src/struct.bah"
if ((strcmp(s->members->data[i]->name, name) == 0)) {

#line 144 "/home/alois/Documents/bah-bah/src/struct.bah"
fn = parseFnType(string(s->members->data[i]->type));

#line 145 "/home/alois/Documents/bah-bah/src/struct.bah"
fn->name = name;

#line 146 "/home/alois/Documents/bah-bah/src/struct.bah"
fn->isVar = true;

#line 147 "/home/alois/Documents/bah-bah/src/struct.bah"
return fn;
}
};

#line 151 "/home/alois/Documents/bah-bah/src/struct.bah"
s = searchStruct(s->extendedFrom,elems);

#line 153 "/home/alois/Documents/bah-bah/src/struct.bah"
return searchStructMethod(name,s,elems);
};

#line 4 "/home/alois/Documents/bah-bah/src/type.bah"
char typeAsStar(char * t){

#line 5 "/home/alois/Documents/bah-bah/src/type.bah"
return (t[strlen(t)-1+4]==42);
};

#line 8 "/home/alois/Documents/bah-bah/src/type.bah"
char isRCPpointerType(char * t){

#line 9 "/home/alois/Documents/bah-bah/src/type.bah"
if (strHasPrefix(t,"\011\0\0\0""function(")) {

#line 10 "/home/alois/Documents/bah-bah/src/type.bah"
return false;
}

#line 12 "/home/alois/Documents/bah-bah/src/type.bah"
return (strcmp(t, "\010\0\0\0""cpstring") == 0)||(strcmp(t, "\03\0\0\0""ptr") == 0)||typeAsStar(t)||strHasPrefix(t,"\02\0\0\0""[]")||strHasPrefix(t,"\05\0\0\0""chan:")||strHasPrefix(t,"\04\0\0\0""map:");
};

#line 15 "/home/alois/Documents/bah-bah/src/type.bah"
char isRCPtype(char * t,struct Elems* elems){

#line 16 "/home/alois/Documents/bah-bah/src/type.bah"
if ((isRCPpointerType(t)==true)) {

#line 17 "/home/alois/Documents/bah-bah/src/type.bah"
return true;
}

#line 19 "/home/alois/Documents/bah-bah/src/type.bah"
struct cStruct* s = searchStruct(t,elems);

#line 20 "/home/alois/Documents/bah-bah/src/type.bah"
return (s!=null)&&(s->isBinding==false);
};

#line 24 "/home/alois/Documents/bah-bah/src/type.bah"
struct string getCType(char * t,struct Elems* elems){

#line 25 "/home/alois/Documents/bah-bah/src/type.bah"
if ((strlen(t)==0)) {

#line 26 "/home/alois/Documents/bah-bah/src/type.bah"
return string("\04\0\0\0""void");
}

#line 29 "/home/alois/Documents/bah-bah/src/type.bah"
struct string tp = string(t);

#line 30 "/home/alois/Documents/bah-bah/src/type.bah"
string__replace(&tp,"\01\0\0\0"" ","\0\0\0\0""");

#line 31 "/home/alois/Documents/bah-bah/src/type.bah"
if (string__hasPrefix(&tp,"\02\0\0\0""[]")) {

#line 32 "/home/alois/Documents/bah-bah/src/type.bah"
string__trimLeft(&tp,2);

#line 33 "/home/alois/Documents/bah-bah/src/type.bah"
char * tpstr = string__str(&tp);

#line 34 "/home/alois/Documents/bah-bah/src/type.bah"
tp = getCType(tpstr,elems);

#line 35 "/home/alois/Documents/bah-bah/src/type.bah"
t = string__str(&tp);

#line 36 "/home/alois/Documents/bah-bah/src/type.bah"
char** ____BAH_COMPILER_VAR_218 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_218[2] = "\02\0\0\0"")*";____BAH_COMPILER_VAR_218[1] = t;____BAH_COMPILER_VAR_218[0] = "\06\0\0\0""array(";char * ____BAH_COMPILER_VAR_219 =__Bah_multiple_concat(____BAH_COMPILER_VAR_218, 3);char * r = ____BAH_COMPILER_VAR_219;

#line 37 "/home/alois/Documents/bah-bah/src/type.bah"
return string(r);
}

#line 39 "/home/alois/Documents/bah-bah/src/type.bah"
string__replace(&tp,"\01\0\0\0""!","\01\0\0\0""*");

#line 42 "/home/alois/Documents/bah-bah/src/type.bah"
struct string ctp = tp;

#line 43 "/home/alois/Documents/bah-bah/src/type.bah"
string__replace(&ctp,"\01\0\0\0""*","\0\0\0\0""");

#line 45 "/home/alois/Documents/bah-bah/src/type.bah"
if (string__hasPrefix(&tp,"\06\0\0\0""tuple:")) {

#line 46 "/home/alois/Documents/bah-bah/src/type.bah"
array(struct string)* parts = splitString(tp,"\01\0\0\0"":");

#line 47 "/home/alois/Documents/bah-bah/src/type.bah"

                struct string ____BAH_COMPILER_VAR_220 = getCType(string__str(&parts->data[2]),elems);
                char** ____BAH_COMPILER_VAR_221 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_221[1] = "\01\0\0\0""*";____BAH_COMPILER_VAR_221[0] = string__str(&____BAH_COMPILER_VAR_220);char * ____BAH_COMPILER_VAR_222 =__Bah_multiple_concat(____BAH_COMPILER_VAR_221, 2);string__set(&tp,____BAH_COMPILER_VAR_222);
}

#line 48 "/home/alois/Documents/bah-bah/src/type.bah"
else if ((string__hasPrefix(&tp,"\05\0\0\0""chan:")==1)) {

#line 49 "/home/alois/Documents/bah-bah/src/type.bah"
string__set(&tp,"\020\0\0\0""struct channel *");
}

#line 50 "/home/alois/Documents/bah-bah/src/type.bah"
else if ((string__hasPrefix(&tp,"\04\0\0\0""map:")==1)) {

#line 51 "/home/alois/Documents/bah-bah/src/type.bah"
string__set(&tp,"\023\0\0\0""struct mapWrapper *");
}

#line 52 "/home/alois/Documents/bah-bah/src/type.bah"
else if ((string__hasPrefix(&tp,"\07\0\0\0""buffer:")==1)) {

#line 53 "/home/alois/Documents/bah-bah/src/type.bah"
string__set(&tp,"\05\0\0\0""char*");
}

#line 54 "/home/alois/Documents/bah-bah/src/type.bah"
else if ((strcmp(string__str(&ctp), "\03\0\0\0""int") == 0)) {

#line 55 "/home/alois/Documents/bah-bah/src/type.bah"
string__replace(&tp,"\03\0\0\0""int","\010\0\0\0""long int");
}

#line 56 "/home/alois/Documents/bah-bah/src/type.bah"
else if ((strcmp(string__str(&ctp), "\05\0\0\0""int32") == 0)) {

#line 57 "/home/alois/Documents/bah-bah/src/type.bah"
string__replace(&tp,"\05\0\0\0""int32","\03\0\0\0""int");
}

#line 58 "/home/alois/Documents/bah-bah/src/type.bah"
else if ((strcmp(string__str(&ctp), "\06\0\0\0""uint32") == 0)) {

#line 59 "/home/alois/Documents/bah-bah/src/type.bah"
string__replace(&tp,"\06\0\0\0""uint32","\014\0\0\0""unsigned int");
}

#line 60 "/home/alois/Documents/bah-bah/src/type.bah"
else if ((strcmp(string__str(&ctp), "\04\0\0\0""uint") == 0)) {

#line 61 "/home/alois/Documents/bah-bah/src/type.bah"
string__replace(&tp,"\04\0\0\0""uint","\021\0\0\0""unsigned long int");
}

#line 62 "/home/alois/Documents/bah-bah/src/type.bah"
else if ((strcmp(string__str(&ctp), "\07\0\0\0""float32") == 0)) {

#line 63 "/home/alois/Documents/bah-bah/src/type.bah"
string__replace(&tp,"\07\0\0\0""float32","\05\0\0\0""float");
}

#line 64 "/home/alois/Documents/bah-bah/src/type.bah"
else if ((strcmp(string__str(&ctp), "\010\0\0\0""ufloat32") == 0)) {

#line 65 "/home/alois/Documents/bah-bah/src/type.bah"
string__replace(&tp,"\010\0\0\0""ufloat32","\016\0\0\0""unsigned float");
}

#line 66 "/home/alois/Documents/bah-bah/src/type.bah"
else if ((strcmp(string__str(&ctp), "\06\0\0\0""ufloat") == 0)) {

#line 67 "/home/alois/Documents/bah-bah/src/type.bah"
string__replace(&tp,"\06\0\0\0""ufloat","\017\0\0\0""unsigned double");
}

#line 68 "/home/alois/Documents/bah-bah/src/type.bah"
else if ((strcmp(string__str(&ctp), "\05\0\0\0""float") == 0)) {

#line 69 "/home/alois/Documents/bah-bah/src/type.bah"
string__replace(&tp,"\05\0\0\0""float","\06\0\0\0""double");
}

#line 70 "/home/alois/Documents/bah-bah/src/type.bah"
else if ((strcmp(string__str(&ctp), "\04\0\0\0""long") == 0)) {

#line 71 "/home/alois/Documents/bah-bah/src/type.bah"
string__replace(&tp,"\04\0\0\0""long","\011\0\0\0""long long");
}

#line 72 "/home/alois/Documents/bah-bah/src/type.bah"
else if ((strcmp(string__str(&ctp), "\05\0\0\0""ulong") == 0)) {

#line 73 "/home/alois/Documents/bah-bah/src/type.bah"
string__replace(&tp,"\05\0\0\0""ulong","\022\0\0\0""unsigned long long");
}

#line 74 "/home/alois/Documents/bah-bah/src/type.bah"
else if ((strcmp(string__str(&ctp), "\010\0\0\0""cpstring") == 0)) {

#line 75 "/home/alois/Documents/bah-bah/src/type.bah"
string__replace(&tp,"\010\0\0\0""cpstring","\06\0\0\0""char *");
}

#line 80 "/home/alois/Documents/bah-bah/src/type.bah"
else if ((strcmp(string__str(&ctp), "\03\0\0\0""ptr") == 0)) {

#line 81 "/home/alois/Documents/bah-bah/src/type.bah"
string__replace(&tp,"\03\0\0\0""ptr","\06\0\0\0""void *");
}

#line 82 "/home/alois/Documents/bah-bah/src/type.bah"
else if ((strcmp(string__str(&ctp), "\06\0\0\0""ushort") == 0)) {

#line 83 "/home/alois/Documents/bah-bah/src/type.bah"
string__replace(&tp,"\06\0\0\0""ushort","\016\0\0\0""unsigned short");
}

#line 84 "/home/alois/Documents/bah-bah/src/type.bah"
else if ((strcmp(string__str(&ctp), "\04\0\0\0""byte") == 0)) {

#line 85 "/home/alois/Documents/bah-bah/src/type.bah"
string__replace(&tp,"\04\0\0\0""byte","\015\0\0\0""unsigned char");
}

#line 86 "/home/alois/Documents/bah-bah/src/type.bah"
else if ((strcmp(string__str(&ctp), "\04\0\0\0""bool") == 0)) {

#line 87 "/home/alois/Documents/bah-bah/src/type.bah"
string__replace(&tp,"\04\0\0\0""bool","\04\0\0\0""char");
}

#line 88 "/home/alois/Documents/bah-bah/src/type.bah"
else if ((strcmp(string__str(&ctp), "\04\0\0\0""char") == 0)) {
}

#line 90 "/home/alois/Documents/bah-bah/src/type.bah"
else {

#line 92 "/home/alois/Documents/bah-bah/src/type.bah"
char * ctpstr = string__str(&ctp);

#line 93 "/home/alois/Documents/bah-bah/src/type.bah"
struct cStruct* s = searchStruct(ctpstr,elems);

#line 94 "/home/alois/Documents/bah-bah/src/type.bah"
if ((s!=null)) {

#line 95 "/home/alois/Documents/bah-bah/src/type.bah"
string__prepend(&tp,"\07\0\0\0""struct ");
}

#line 96 "/home/alois/Documents/bah-bah/src/type.bah"
else {

#line 97 "/home/alois/Documents/bah-bah/src/type.bah"
register long int i = 0;

#line 97 "/home/alois/Documents/bah-bah/src/type.bah"
while ((i<len(elems->types))) {

#line 98 "/home/alois/Documents/bah-bah/src/type.bah"
char * ct = elems->types->data[i];

#line 99 "/home/alois/Documents/bah-bah/src/type.bah"
if (string__compare(&ctp,ct)) {

#line 100 "/home/alois/Documents/bah-bah/src/type.bah"
return tp;
}

#line 102 "/home/alois/Documents/bah-bah/src/type.bah"
i = i+1;
};

#line 104 "/home/alois/Documents/bah-bah/src/type.bah"
return string("\0\0\0\0""");
}
}

#line 109 "/home/alois/Documents/bah-bah/src/type.bah"
return tp;
};

#line 113 "/home/alois/Documents/bah-bah/src/type.bah"
array(char *)* intTypes;

#line 121 "/home/alois/Documents/bah-bah/src/type.bah"
array(char *)* floatTypes;

#line 128 "/home/alois/Documents/bah-bah/src/type.bah"
char * maybeToPtr(char * a){

#line 129 "/home/alois/Documents/bah-bah/src/type.bah"
if ((a[strlen(a)-1+4]!=33)) {

#line 130 "/home/alois/Documents/bah-bah/src/type.bah"
return a;
}

#line 132 "/home/alois/Documents/bah-bah/src/type.bah"
char** ____BAH_COMPILER_VAR_223 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_223[1] = "\01\0\0\0""*";____BAH_COMPILER_VAR_223[0] = cpstringSubsitute(a, 0, strlen(a)-1);char * ____BAH_COMPILER_VAR_224 =__Bah_multiple_concat(____BAH_COMPILER_VAR_223, 2);a = ____BAH_COMPILER_VAR_224;

#line 133 "/home/alois/Documents/bah-bah/src/type.bah"
return a;
};

#line 136 "/home/alois/Documents/bah-bah/src/type.bah"
char compTypeEquiv(char * a,char * b,char first){

#line 142 "/home/alois/Documents/bah-bah/src/type.bah"
if ((first==false)) {

#line 143 "/home/alois/Documents/bah-bah/src/type.bah"
return false;
}

#line 146 "/home/alois/Documents/bah-bah/src/type.bah"
if (compTypeEquiv(b,a,false)) {

#line 147 "/home/alois/Documents/bah-bah/src/type.bah"
return true;
}

#line 151 "/home/alois/Documents/bah-bah/src/type.bah"
return (strcmp(a, b) == 0);
};

#line 154 "/home/alois/Documents/bah-bah/src/type.bah"
char ____BAH_COMPILER_VAR_225(array(char *)* arr, char * el) {
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
char ____BAH_COMPILER_VAR_226(array(char *)* arr, char * el) {
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
char ____BAH_COMPILER_VAR_227(array(char *)* arr, char * el) {
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
char ____BAH_COMPILER_VAR_228(array(char *)* arr, char * el) {
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

#line 155 "/home/alois/Documents/bah-bah/src/type.bah"
a = maybeToPtr(a);

#line 156 "/home/alois/Documents/bah-bah/src/type.bah"
b = maybeToPtr(b);

#line 157 "/home/alois/Documents/bah-bah/src/type.bah"
if ((strcmp(a, b) == 0)||(strcmp(a, "\03\0\0\0""ptr") == 0)||(strcmp(b, "\03\0\0\0""ptr") == 0)) {

#line 158 "/home/alois/Documents/bah-bah/src/type.bah"
return true;
}

#line 161 "/home/alois/Documents/bah-bah/src/type.bah"
if (____BAH_COMPILER_VAR_225(intTypes, a)&&____BAH_COMPILER_VAR_226(intTypes, b)) {

#line 162 "/home/alois/Documents/bah-bah/src/type.bah"
return true;
}

#line 164 "/home/alois/Documents/bah-bah/src/type.bah"
if (____BAH_COMPILER_VAR_227(floatTypes, a)&&____BAH_COMPILER_VAR_228(floatTypes, b)) {

#line 165 "/home/alois/Documents/bah-bah/src/type.bah"
return true;
}

#line 168 "/home/alois/Documents/bah-bah/src/type.bah"
return compTypeEquiv(a,b,true);
};

#line 3 "/home/alois/Documents/bah-bah/src/logger.bah"
struct debugFunctionArgument {
char * name;
char * type;
};

#line 8 "/home/alois/Documents/bah-bah/src/logger.bah"
struct debugFunction {
char * name;
char * returns;
array(struct variable*)* args;
};

#line 14 "/home/alois/Documents/bah-bah/src/logger.bah"
struct debugStruct {
char * name;
array(struct variable*)* membs;
};

#line 19 "/home/alois/Documents/bah-bah/src/logger.bah"
struct debugType {
char * name;
char * refers;
};

#line 24 "/home/alois/Documents/bah-bah/src/logger.bah"
void debugStart(){

#line 25 "/home/alois/Documents/bah-bah/src/logger.bah"
println("\01\0\0\0""[");
};

#line 28 "/home/alois/Documents/bah-bah/src/logger.bah"
char * noASCIIescape(char * s){

#line 29 "/home/alois/Documents/bah-bah/src/logger.bah"
struct strBuilder ____BAH_COMPILER_VAR_229 = {};
strBuilder___init(&____BAH_COMPILER_VAR_229);
struct strBuilder sb = ____BAH_COMPILER_VAR_229;

#line 31 "/home/alois/Documents/bah-bah/src/logger.bah"
register long int i = 0;

#line 31 "/home/alois/Documents/bah-bah/src/logger.bah"
for (; (i<strlen(s)); 
#line 31 "/home/alois/Documents/bah-bah/src/logger.bah"
++i) {

#line 32 "/home/alois/Documents/bah-bah/src/logger.bah"
if ((s[i+4]==(char)27)) {

#line 33 "/home/alois/Documents/bah-bah/src/logger.bah"
for (; (i<strlen(s)); 
#line 33 "/home/alois/Documents/bah-bah/src/logger.bah"
++i) {

#line 34 "/home/alois/Documents/bah-bah/src/logger.bah"
if ((s[i+4]==109)) {

#line 35 "/home/alois/Documents/bah-bah/src/logger.bah"
break;
}
};

#line 38 "/home/alois/Documents/bah-bah/src/logger.bah"
continue;
}

#line 40 "/home/alois/Documents/bah-bah/src/logger.bah"
strBuilder__append(&sb,s[i+4]);
};

#line 43 "/home/alois/Documents/bah-bah/src/logger.bah"
return strBuilder__str(&sb);
};

#line 47 "/home/alois/Documents/bah-bah/src/logger.bah"
void debugPrint(char * name,long int line,struct reflectElement e){

#line 48 "/home/alois/Documents/bah-bah/src/logger.bah"
if ((debug==false)) {

#line 49 "/home/alois/Documents/bah-bah/src/logger.bah"
return;
}

#line 51 "/home/alois/Documents/bah-bah/src/logger.bah"
char ** ____BAH_COMPILER_VAR_230 = &name;
struct reflectElement ____BAH_COMPILER_VAR_231 = __reflect(____BAH_COMPILER_VAR_230, sizeof(char **), "\011\0\0\0""cpstring*", "\05\0\0\0""&name", 0, 0, 0, 0, 0);
char** ____BAH_COMPILER_VAR_232 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_232[8] = "\014\0\0\0""\n    },\n    ";____BAH_COMPILER_VAR_232[7] = toJson(e);____BAH_COMPILER_VAR_232[6] = "\026\0\0\0""\",\n        \"element\": ";____BAH_COMPILER_VAR_232[5] = intToStr(line);____BAH_COMPILER_VAR_232[4] = "\01\0\0\0"":";____BAH_COMPILER_VAR_232[3] = compilerState.currentFile;____BAH_COMPILER_VAR_232[2] = "\023\0\0\0"",\n        \"path\": \"";____BAH_COMPILER_VAR_232[1] = toJson(____BAH_COMPILER_VAR_231);____BAH_COMPILER_VAR_232[0] = "\027\0\0\0""\n    {\n        \"name\": ";char * ____BAH_COMPILER_VAR_233 =__Bah_multiple_concat(____BAH_COMPILER_VAR_232, 9);println(____BAH_COMPILER_VAR_233);
};

#line 60 "/home/alois/Documents/bah-bah/src/logger.bah"
void debugError(char * name,long int line,long int from,long int to,struct reflectElement e){

#line 61 "/home/alois/Documents/bah-bah/src/logger.bah"
if ((debug==false)) {

#line 62 "/home/alois/Documents/bah-bah/src/logger.bah"
return;
}

#line 64 "/home/alois/Documents/bah-bah/src/logger.bah"
char ** ____BAH_COMPILER_VAR_234 = &name;
struct reflectElement ____BAH_COMPILER_VAR_235 = __reflect(____BAH_COMPILER_VAR_234, sizeof(char **), "\011\0\0\0""cpstring*", "\05\0\0\0""&name", 0, 0, 0, 0, 0);
char** ____BAH_COMPILER_VAR_236 = alloca(13 * sizeof(char*));____BAH_COMPILER_VAR_236[12] = "\014\0\0\0""\n    },\n    ";____BAH_COMPILER_VAR_236[11] = toJson(e);____BAH_COMPILER_VAR_236[10] = "\037\0\0\0""\n        ],\n        \"element\": ";____BAH_COMPILER_VAR_236[9] = intToStr(to);____BAH_COMPILER_VAR_236[8] = "\016\0\0\0"",\n            ";____BAH_COMPILER_VAR_236[7] = intToStr(from);____BAH_COMPILER_VAR_236[6] = "\042\0\0\0""\",\n        \"range\": [\n            ";____BAH_COMPILER_VAR_236[5] = intToStr(line);____BAH_COMPILER_VAR_236[4] = "\01\0\0\0"":";____BAH_COMPILER_VAR_236[3] = compilerState.currentFile;____BAH_COMPILER_VAR_236[2] = "\023\0\0\0"",\n        \"path\": \"";____BAH_COMPILER_VAR_236[1] = toJson(____BAH_COMPILER_VAR_235);____BAH_COMPILER_VAR_236[0] = "\027\0\0\0""\n    {\n        \"name\": ";char * ____BAH_COMPILER_VAR_237 =__Bah_multiple_concat(____BAH_COMPILER_VAR_236, 13);println(____BAH_COMPILER_VAR_237);
};

#line 77 "/home/alois/Documents/bah-bah/src/logger.bah"
void debugEnd(){

#line 78 "/home/alois/Documents/bah-bah/src/logger.bah"
println("\062\0\0\0""\n    {\n        \"name\": \"file_end\"\n    }\n    ]\n    ");
};

#line 87 "/home/alois/Documents/bah-bah/src/logger.bah"
void debugExit(){

#line 88 "/home/alois/Documents/bah-bah/src/logger.bah"
println("\063\0\0\0""\n    {\n        \"name\": \"error_end\"\n    }\n    ]\n    ");
};

#line 96 "/home/alois/Documents/bah-bah/src/logger.bah"
void debugEndScope(long int line,struct Elems* elems){

#line 97 "/home/alois/Documents/bah-bah/src/logger.bah"
if ((debug==false)) {

#line 98 "/home/alois/Documents/bah-bah/src/logger.bah"
return;
}

#line 100 "/home/alois/Documents/bah-bah/src/logger.bah"
register long int i = 0;

#line 100 "/home/alois/Documents/bah-bah/src/logger.bah"
while ((i<len(elems->vars))) {

#line 101 "/home/alois/Documents/bah-bah/src/logger.bah"
struct variable* v = elems->vars->data[i];

#line 102 "/home/alois/Documents/bah-bah/src/logger.bah"
if ((v->declScope==elems)&&(v->isConst==false)) {

#line 103 "/home/alois/Documents/bah-bah/src/logger.bah"
struct variable* ____BAH_COMPILER_VAR_238 = v;
char ** ____BAH_COMPILER_VAR_240 = (char **)((char*)(____BAH_COMPILER_VAR_238) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_241 = __reflect(____BAH_COMPILER_VAR_240, sizeof(char *), "\010\0\0\0""cpstring", "\04\0\0\0""name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_242 = (char **)((char*)(____BAH_COMPILER_VAR_238) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_243 = __reflect(____BAH_COMPILER_VAR_242, sizeof(char *), "\010\0\0\0""cpstring", "\04\0\0\0""type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_244 = (char*)((char*)(____BAH_COMPILER_VAR_238) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_245 = __reflect(____BAH_COMPILER_VAR_244, sizeof(char), "\04\0\0\0""bool", "\07\0\0\0""isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_246 = (char **)((char*)(____BAH_COMPILER_VAR_238) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_247 = __reflect(____BAH_COMPILER_VAR_246, sizeof(char *), "\010\0\0\0""cpstring", "\010\0\0\0""constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_248 = (char*)((char*)(____BAH_COMPILER_VAR_238) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_249 = __reflect(____BAH_COMPILER_VAR_248, sizeof(char), "\04\0\0\0""bool", "\07\0\0\0""isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_250 = (char **)((char*)(____BAH_COMPILER_VAR_238) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_251 = __reflect(____BAH_COMPILER_VAR_250, sizeof(char *), "\010\0\0\0""cpstring", "\04\0\0\0""from", 0, 0, 0, 0, offsetof(struct variable, from));
void ** ____BAH_COMPILER_VAR_252 = (void **)((char*)(____BAH_COMPILER_VAR_238) + offsetof(struct variable, declScope));
struct reflectElement ____BAH_COMPILER_VAR_253 = __reflect(____BAH_COMPILER_VAR_252, sizeof(void *), "\03\0\0\0""ptr", "\011\0\0\0""declScope", 0, 0, 0, 0, offsetof(struct variable, declScope));
char* ____BAH_COMPILER_VAR_254 = (char*)((char*)(____BAH_COMPILER_VAR_238) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_255 = __reflect(____BAH_COMPILER_VAR_254, sizeof(char), "\04\0\0\0""bool", "\010\0\0\0""isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));
struct rope** ____BAH_COMPILER_VAR_256 = (struct rope**)((char*)(____BAH_COMPILER_VAR_238) + offsetof(struct variable, declRope));
char ** ____BAH_COMPILER_VAR_258 = (char **)((char*)(____BAH_COMPILER_VAR_256) + offsetof(struct rope, str));
struct reflectElement ____BAH_COMPILER_VAR_259 = __reflect(____BAH_COMPILER_VAR_258, sizeof(char *), "\010\0\0\0""cpstring", "\03\0\0\0""str", 0, 0, 0, 0, offsetof(struct rope, str));
int* ____BAH_COMPILER_VAR_260 = (int*)((char*)(____BAH_COMPILER_VAR_256) + offsetof(struct rope, totalLen));
struct reflectElement ____BAH_COMPILER_VAR_261 = __reflect(____BAH_COMPILER_VAR_260, sizeof(int), "\05\0\0\0""int32", "\010\0\0\0""totalLen", 0, 0, 0, 0, offsetof(struct rope, totalLen));
void ** ____BAH_COMPILER_VAR_262 = (void **)((char*)(____BAH_COMPILER_VAR_256) + offsetof(struct rope, left));
struct reflectElement ____BAH_COMPILER_VAR_263 = __reflect(____BAH_COMPILER_VAR_262, sizeof(void *), "\03\0\0\0""ptr", "\04\0\0\0""left", 0, 0, 0, 0, offsetof(struct rope, left));
void ** ____BAH_COMPILER_VAR_264 = (void **)((char*)(____BAH_COMPILER_VAR_256) + offsetof(struct rope, right));
struct reflectElement ____BAH_COMPILER_VAR_265 = __reflect(____BAH_COMPILER_VAR_264, sizeof(void *), "\03\0\0\0""ptr", "\05\0\0\0""right", 0, 0, 0, 0, offsetof(struct rope, right));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_257 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_257->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_257->length = 4;
        ____BAH_COMPILER_VAR_257->data = memoryAlloc(____BAH_COMPILER_VAR_257->length * ____BAH_COMPILER_VAR_257->elemSize);
        ____BAH_COMPILER_VAR_257->data[0] = ____BAH_COMPILER_VAR_259;
____BAH_COMPILER_VAR_257->data[1] = ____BAH_COMPILER_VAR_261;
____BAH_COMPILER_VAR_257->data[2] = ____BAH_COMPILER_VAR_263;
____BAH_COMPILER_VAR_257->data[3] = ____BAH_COMPILER_VAR_265;
struct reflectElement ____BAH_COMPILER_VAR_266 = __reflect(____BAH_COMPILER_VAR_256, sizeof(struct rope), "\05\0\0\0""rope*", "\010\0\0\0""declRope", 0, 0, 1, ____BAH_COMPILER_VAR_257, offsetof(struct variable, declRope));
char* ____BAH_COMPILER_VAR_267 = (char*)((char*)(____BAH_COMPILER_VAR_238) + offsetof(struct variable, canBeNull));
struct reflectElement ____BAH_COMPILER_VAR_268 = __reflect(____BAH_COMPILER_VAR_267, sizeof(char), "\04\0\0\0""bool", "\011\0\0\0""canBeNull", 0, 0, 0, 0, offsetof(struct variable, canBeNull));
void ** ____BAH_COMPILER_VAR_269 = (void **)((char*)(____BAH_COMPILER_VAR_238) + offsetof(struct variable, iterScope));
struct reflectElement ____BAH_COMPILER_VAR_270 = __reflect(____BAH_COMPILER_VAR_269, sizeof(void *), "\03\0\0\0""ptr", "\011\0\0\0""iterScope", 0, 0, 0, 0, offsetof(struct variable, iterScope));
char* ____BAH_COMPILER_VAR_271 = (char*)((char*)(____BAH_COMPILER_VAR_238) + offsetof(struct variable, canBeReg));
struct reflectElement ____BAH_COMPILER_VAR_272 = __reflect(____BAH_COMPILER_VAR_271, sizeof(char), "\04\0\0\0""bool", "\010\0\0\0""canBeReg", 0, 0, 0, 0, offsetof(struct variable, canBeReg));
char* ____BAH_COMPILER_VAR_273 = (char*)((char*)(____BAH_COMPILER_VAR_238) + offsetof(struct variable, isReg));
struct reflectElement ____BAH_COMPILER_VAR_274 = __reflect(____BAH_COMPILER_VAR_273, sizeof(char), "\04\0\0\0""bool", "\05\0\0\0""isReg", 0, 0, 0, 0, offsetof(struct variable, isReg));
void ** ____BAH_COMPILER_VAR_275 = (void **)((char*)(____BAH_COMPILER_VAR_238) + offsetof(struct variable, lastSet));
struct reflectElement ____BAH_COMPILER_VAR_276 = __reflect(____BAH_COMPILER_VAR_275, sizeof(void *), "\03\0\0\0""ptr", "\07\0\0\0""lastSet", 0, 0, 0, 0, offsetof(struct variable, lastSet));
char* ____BAH_COMPILER_VAR_277 = (char*)((char*)(____BAH_COMPILER_VAR_238) + offsetof(struct variable, isArg));
struct reflectElement ____BAH_COMPILER_VAR_278 = __reflect(____BAH_COMPILER_VAR_277, sizeof(char), "\04\0\0\0""bool", "\05\0\0\0""isArg", 0, 0, 0, 0, offsetof(struct variable, isArg));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_239 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_239->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_239->length = 15;
        ____BAH_COMPILER_VAR_239->data = memoryAlloc(____BAH_COMPILER_VAR_239->length * ____BAH_COMPILER_VAR_239->elemSize);
        ____BAH_COMPILER_VAR_239->data[0] = ____BAH_COMPILER_VAR_241;
____BAH_COMPILER_VAR_239->data[1] = ____BAH_COMPILER_VAR_243;
____BAH_COMPILER_VAR_239->data[2] = ____BAH_COMPILER_VAR_245;
____BAH_COMPILER_VAR_239->data[3] = ____BAH_COMPILER_VAR_247;
____BAH_COMPILER_VAR_239->data[4] = ____BAH_COMPILER_VAR_249;
____BAH_COMPILER_VAR_239->data[5] = ____BAH_COMPILER_VAR_251;
____BAH_COMPILER_VAR_239->data[6] = ____BAH_COMPILER_VAR_253;
____BAH_COMPILER_VAR_239->data[7] = ____BAH_COMPILER_VAR_255;
____BAH_COMPILER_VAR_239->data[8] = ____BAH_COMPILER_VAR_266;
____BAH_COMPILER_VAR_239->data[9] = ____BAH_COMPILER_VAR_268;
____BAH_COMPILER_VAR_239->data[10] = ____BAH_COMPILER_VAR_270;
____BAH_COMPILER_VAR_239->data[11] = ____BAH_COMPILER_VAR_272;
____BAH_COMPILER_VAR_239->data[12] = ____BAH_COMPILER_VAR_274;
____BAH_COMPILER_VAR_239->data[13] = ____BAH_COMPILER_VAR_276;
____BAH_COMPILER_VAR_239->data[14] = ____BAH_COMPILER_VAR_278;
struct reflectElement ____BAH_COMPILER_VAR_279 = __reflect(____BAH_COMPILER_VAR_238, sizeof(struct variable), "\011\0\0\0""variable*", "\01\0\0\0""v", 0, 0, 1, ____BAH_COMPILER_VAR_239, 0);
debugPrint("\07\0\0\0""var_end",line,____BAH_COMPILER_VAR_279);
}

#line 105 "/home/alois/Documents/bah-bah/src/logger.bah"
i = i+1;
};
};

#line 5 "/home/alois/Documents/bah-bah/src/errors.bah"
#define ASCII_RESET "\04\0\0\0""\033[0m"

#line 7 "/home/alois/Documents/bah-bah/src/errors.bah"
#define ASCII_YELLOW "\05\0\0\0""\033[33m"

#line 8 "/home/alois/Documents/bah-bah/src/errors.bah"
#define ASCII_BLUE "\05\0\0\0""\033[36m"

#line 9 "/home/alois/Documents/bah-bah/src/errors.bah"
#define ASCII_GREEN "\05\0\0\0""\033[32m"

#line 10 "/home/alois/Documents/bah-bah/src/errors.bah"
#define ASCII_MAGENTA "\05\0\0\0""\033[35m"

#line 11 "/home/alois/Documents/bah-bah/src/errors.bah"
#define ASCII_GREY "\04\0\0\0""\033[2m"
void advertiseGeneric();

#line 15 "/home/alois/Documents/bah-bah/src/errors.bah"
char * getFuncDef(struct func* fn){

#line 16 "/home/alois/Documents/bah-bah/src/errors.bah"
char** ____BAH_COMPILER_VAR_280 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_280[3] = "\01\0\0\0""(";____BAH_COMPILER_VAR_280[2] = ASCII_RESET;____BAH_COMPILER_VAR_280[1] = fn->name;____BAH_COMPILER_VAR_280[0] = ASCII_YELLOW;char * ____BAH_COMPILER_VAR_281 =__Bah_multiple_concat(____BAH_COMPILER_VAR_280, 4);char * def = ____BAH_COMPILER_VAR_281;

#line 17 "/home/alois/Documents/bah-bah/src/errors.bah"
register long int i = 0;

#line 17 "/home/alois/Documents/bah-bah/src/errors.bah"
for (; (i<len(fn->args)); 
#line 17 "/home/alois/Documents/bah-bah/src/errors.bah"
++i) {

#line 18 "/home/alois/Documents/bah-bah/src/errors.bah"
char** ____BAH_COMPILER_VAR_282 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_282[5] = ASCII_RESET;____BAH_COMPILER_VAR_282[4] = fn->args->data[i]->type;____BAH_COMPILER_VAR_282[3] = ASCII_BLUE;____BAH_COMPILER_VAR_282[2] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_282[1] = fn->args->data[i]->name;____BAH_COMPILER_VAR_282[0] = ASCII_MAGENTA;char * ____BAH_COMPILER_VAR_283 =__Bah_multiple_concat(____BAH_COMPILER_VAR_282, 6);char** ____BAH_COMPILER_VAR_284 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_284[1] = ____BAH_COMPILER_VAR_283;____BAH_COMPILER_VAR_284[0] = def;char * ____BAH_COMPILER_VAR_285 =__Bah_multiple_concat(____BAH_COMPILER_VAR_284, 2);def = ____BAH_COMPILER_VAR_285;

#line 19 "/home/alois/Documents/bah-bah/src/errors.bah"
if ((i+1<len(fn->args))) {

#line 20 "/home/alois/Documents/bah-bah/src/errors.bah"
char** ____BAH_COMPILER_VAR_286 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_286[1] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_286[0] = def;char * ____BAH_COMPILER_VAR_287 =__Bah_multiple_concat(____BAH_COMPILER_VAR_286, 2);def = ____BAH_COMPILER_VAR_287;
}
};

#line 24 "/home/alois/Documents/bah-bah/src/errors.bah"
char** ____BAH_COMPILER_VAR_288 = alloca(8 * sizeof(char*));____BAH_COMPILER_VAR_288[7] = ASCII_RESET;____BAH_COMPILER_VAR_288[6] = intToStr(fn->line);____BAH_COMPILER_VAR_288[5] = "\01\0\0\0"":";____BAH_COMPILER_VAR_288[4] = fn->file;____BAH_COMPILER_VAR_288[3] = ASCII_GREEN;____BAH_COMPILER_VAR_288[2] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_288[1] = fn->returns->type;____BAH_COMPILER_VAR_288[0] = "\02\0\0\0"") ";char * ____BAH_COMPILER_VAR_289 =__Bah_multiple_concat(____BAH_COMPILER_VAR_288, 8);char** ____BAH_COMPILER_VAR_290 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_290[1] = ____BAH_COMPILER_VAR_289;____BAH_COMPILER_VAR_290[0] = def;char * ____BAH_COMPILER_VAR_291 =__Bah_multiple_concat(____BAH_COMPILER_VAR_290, 2);def = ____BAH_COMPILER_VAR_291;

#line 25 "/home/alois/Documents/bah-bah/src/errors.bah"
return def;
};

#line 28 "/home/alois/Documents/bah-bah/src/errors.bah"
void throwErr(void * tp,char * format){

#line 30 "/home/alois/Documents/bah-bah/src/errors.bah"
char * str = "\0\0\0\0""";

#line 31 "/home/alois/Documents/bah-bah/src/errors.bah"
char * info = "\0\0\0\0""";

#line 32 "/home/alois/Documents/bah-bah/src/errors.bah"
long int pos = 0;

#line 33 "/home/alois/Documents/bah-bah/src/errors.bah"
if ((tp!=null)) {

#line 34 "/home/alois/Documents/bah-bah/src/errors.bah"
struct fileStream ____BAH_COMPILER_VAR_292 = {};
struct fileStream fs = ____BAH_COMPILER_VAR_292;

#line 35 "/home/alois/Documents/bah-bah/src/errors.bah"
fileStream__open(&fs,compilerState.currentFile,"\01\0\0\0""r");

#line 36 "/home/alois/Documents/bah-bah/src/errors.bah"
char * fileSrcStr = fileStream__readContent(&fs);

#line 37 "/home/alois/Documents/bah-bah/src/errors.bah"
struct Tok* t = tp;

#line 38 "/home/alois/Documents/bah-bah/src/errors.bah"
struct string ffmt = string(format);

#line 39 "/home/alois/Documents/bah-bah/src/errors.bah"
if ((strlen(t->ogCont)==0)) {

#line 40 "/home/alois/Documents/bah-bah/src/errors.bah"
t->ogCont = t->cont;
}

#line 42 "/home/alois/Documents/bah-bah/src/errors.bah"
char** ____BAH_COMPILER_VAR_293 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_293[2] = "\01\0\0\0""'";____BAH_COMPILER_VAR_293[1] = t->ogCont;____BAH_COMPILER_VAR_293[0] = "\01\0\0\0""'";char * ____BAH_COMPILER_VAR_294 =__Bah_multiple_concat(____BAH_COMPILER_VAR_293, 3);string__replace(&ffmt,"\07\0\0\0""{TOKEN}",____BAH_COMPILER_VAR_294);

#line 43 "/home/alois/Documents/bah-bah/src/errors.bah"
format = string__str(&ffmt);

#line 45 "/home/alois/Documents/bah-bah/src/errors.bah"
array(char)* line = memoryAlloc(sizeof(array(char)));

line->length = 0;
line->elemSize = sizeof(char);

#line 47 "/home/alois/Documents/bah-bah/src/errors.bah"
unsigned int beg = t->pos;

#line 47 "/home/alois/Documents/bah-bah/src/errors.bah"
while ((beg>0)) {

#line 48 "/home/alois/Documents/bah-bah/src/errors.bah"
char c = fileSrcStr[beg+4];

#line 49 "/home/alois/Documents/bah-bah/src/errors.bah"
if ((c==(char)10)) {

#line 50 "/home/alois/Documents/bah-bah/src/errors.bah"
beg = beg+1;

#line 51 "/home/alois/Documents/bah-bah/src/errors.bah"
break;
}

#line 53 "/home/alois/Documents/bah-bah/src/errors.bah"
beg = beg-1;
};

#line 56 "/home/alois/Documents/bah-bah/src/errors.bah"
pos = t->pos-beg+1;

#line 57 "/home/alois/Documents/bah-bah/src/errors.bah"
long int size = fileStream__getSize(&fs);

#line 59 "/home/alois/Documents/bah-bah/src/errors.bah"
unsigned int i = beg;

#line 59 "/home/alois/Documents/bah-bah/src/errors.bah"
for (; (i<size); 
#line 59 "/home/alois/Documents/bah-bah/src/errors.bah"
++i) {

#line 60 "/home/alois/Documents/bah-bah/src/errors.bah"
char c = fileSrcStr[i+4];

#line 61 "/home/alois/Documents/bah-bah/src/errors.bah"
if ((c==(char)10)) {

#line 62 "/home/alois/Documents/bah-bah/src/errors.bah"
break;
}

#line 64 "/home/alois/Documents/bah-bah/src/errors.bah"
if ((i==t->pos)) {

#line 65 "/home/alois/Documents/bah-bah/src/errors.bah"
array(char)* errCont = memoryAlloc(sizeof(array(char)));

errCont->length = 0;
errCont->elemSize = sizeof(char);

#line 66 "/home/alois/Documents/bah-bah/src/errors.bah"
unsigned int offset = i;

#line 67 "/home/alois/Documents/bah-bah/src/errors.bah"
for (; (i<size); 
#line 67 "/home/alois/Documents/bah-bah/src/errors.bah"
++i) {

#line 68 "/home/alois/Documents/bah-bah/src/errors.bah"
if ((i-offset>=strlen(t->ogCont))) {

#line 69 "/home/alois/Documents/bah-bah/src/errors.bah"
break;
}

#line 71 "/home/alois/Documents/bah-bah/src/errors.bah"
if ((fileSrcStr[i+4]!=t->ogCont[i-offset+4])) {

#line 72 "/home/alois/Documents/bah-bah/src/errors.bah"
if ((isSpace(fileSrcStr[i+4])==false)) {

#line 73 "/home/alois/Documents/bah-bah/src/errors.bah"
break;
}

#line 75 "/home/alois/Documents/bah-bah/src/errors.bah"
++offset;
}

#line 77 "/home/alois/Documents/bah-bah/src/errors.bah"

    unsigned int ____BAH_COMPILER_VAR_295 = len(errCont);
    __Bah_realocate_arr(errCont, ____BAH_COMPILER_VAR_295);
    errCont->data[____BAH_COMPILER_VAR_295] = fileSrcStr[i+4];
};

#line 79 "/home/alois/Documents/bah-bah/src/errors.bah"
char** ____BAH_COMPILER_VAR_296 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_296[2] = "\07\0\0\0""\e[1;37m";____BAH_COMPILER_VAR_296[1] = arrToStr(errCont);____BAH_COMPILER_VAR_296[0] = "\07\0\0\0""\e[1;31m";char * ____BAH_COMPILER_VAR_297 =__Bah_multiple_concat(____BAH_COMPILER_VAR_296, 3);array(char)* errTk = strToArr(____BAH_COMPILER_VAR_297);

#line 80 "/home/alois/Documents/bah-bah/src/errors.bah"
register long int ii = 0;

#line 80 "/home/alois/Documents/bah-bah/src/errors.bah"
for (; (ii<len(errTk)); 
#line 80 "/home/alois/Documents/bah-bah/src/errors.bah"
++ii) {

#line 81 "/home/alois/Documents/bah-bah/src/errors.bah"

    unsigned int ____BAH_COMPILER_VAR_298 = len(line);
    __Bah_realocate_arr(line, ____BAH_COMPILER_VAR_298);
    line->data[____BAH_COMPILER_VAR_298] = errTk->data[ii];
};

#line 83 "/home/alois/Documents/bah-bah/src/errors.bah"
--i;

#line 84 "/home/alois/Documents/bah-bah/src/errors.bah"
continue;
}

#line 86 "/home/alois/Documents/bah-bah/src/errors.bah"

    unsigned int ____BAH_COMPILER_VAR_299 = len(line);
    __Bah_realocate_arr(line, ____BAH_COMPILER_VAR_299);
    line->data[____BAH_COMPILER_VAR_299] = c;
};

#line 89 "/home/alois/Documents/bah-bah/src/errors.bah"
fileStream__close(&fs);

#line 90 "/home/alois/Documents/bah-bah/src/errors.bah"
str = arrToStr(line);

#line 91 "/home/alois/Documents/bah-bah/src/errors.bah"
char** ____BAH_COMPILER_VAR_300 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_300[2] = intToStr(pos);____BAH_COMPILER_VAR_300[1] = "\01\0\0\0"":";____BAH_COMPILER_VAR_300[0] = intToStr(t->line);char * ____BAH_COMPILER_VAR_301 =__Bah_multiple_concat(____BAH_COMPILER_VAR_300, 3);info = ____BAH_COMPILER_VAR_301;
}

#line 94 "/home/alois/Documents/bah-bah/src/errors.bah"
if (debug) {

#line 95 "/home/alois/Documents/bah-bah/src/errors.bah"
struct Tok* t = tp;

#line 96 "/home/alois/Documents/bah-bah/src/errors.bah"
format = noASCIIescape(format);

#line 97 "/home/alois/Documents/bah-bah/src/errors.bah"
char ** ____BAH_COMPILER_VAR_302 = &format;
struct reflectElement ____BAH_COMPILER_VAR_303 = __reflect(____BAH_COMPILER_VAR_302, sizeof(char **), "\011\0\0\0""cpstring*", "\07\0\0\0""&format", 0, 0, 0, 0, 0);
debugError("\05\0\0\0""error",t->line,pos,pos+strlen(t->ogCont),____BAH_COMPILER_VAR_303);

#line 98 "/home/alois/Documents/bah-bah/src/errors.bah"
debugExit();
}

#line 99 "/home/alois/Documents/bah-bah/src/errors.bah"
else {

#line 100 "/home/alois/Documents/bah-bah/src/errors.bah"
advertiseGeneric();

#line 101 "/home/alois/Documents/bah-bah/src/errors.bah"
char** ____BAH_COMPILER_VAR_304 = alloca(8 * sizeof(char*));____BAH_COMPILER_VAR_304[7] = format;____BAH_COMPILER_VAR_304[6] = "\05\0\0\0""\e[0m\n";____BAH_COMPILER_VAR_304[5] = str;____BAH_COMPILER_VAR_304[4] = "\011\0\0\0""\n\e[1;37m\t";____BAH_COMPILER_VAR_304[3] = info;____BAH_COMPILER_VAR_304[2] = "\01\0\0\0"":";____BAH_COMPILER_VAR_304[1] = compilerState.currentFile;____BAH_COMPILER_VAR_304[0] = "\023\0\0\0""\e[1;31m[ERROR]\e[0m ";char * ____BAH_COMPILER_VAR_305 =__Bah_multiple_concat(____BAH_COMPILER_VAR_304, 8);println(____BAH_COMPILER_VAR_305);
}

#line 104 "/home/alois/Documents/bah-bah/src/errors.bah"
exit(1);
};

#line 108 "/home/alois/Documents/bah-bah/src/errors.bah"
void throwWarning(char * s){

#line 109 "/home/alois/Documents/bah-bah/src/errors.bah"
if (debug) {

#line 110 "/home/alois/Documents/bah-bah/src/errors.bah"
s = noASCIIescape(s);

#line 111 "/home/alois/Documents/bah-bah/src/errors.bah"
char ** ____BAH_COMPILER_VAR_306 = &s;
struct reflectElement ____BAH_COMPILER_VAR_307 = __reflect(____BAH_COMPILER_VAR_306, sizeof(char **), "\011\0\0\0""cpstring*", "\02\0\0\0""&s", 0, 0, 0, 0, 0);
debugError("\07\0\0\0""warning",-1,-1,-1,____BAH_COMPILER_VAR_307);

#line 112 "/home/alois/Documents/bah-bah/src/errors.bah"
return;
}

#line 114 "/home/alois/Documents/bah-bah/src/errors.bah"
char** ____BAH_COMPILER_VAR_308 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_308[4] = "\04\0\0\0""\e[0m";____BAH_COMPILER_VAR_308[3] = s;____BAH_COMPILER_VAR_308[2] = "\06\0\0\0""\n\e[0m\t";____BAH_COMPILER_VAR_308[1] = compilerState.currentFile;____BAH_COMPILER_VAR_308[0] = "\025\0\0\0""\e[1;33m[WARNING]\e[0m ";char * ____BAH_COMPILER_VAR_309 =__Bah_multiple_concat(____BAH_COMPILER_VAR_308, 5);println(____BAH_COMPILER_VAR_309);
};

#line 117 "/home/alois/Documents/bah-bah/src/errors.bah"
void throwWarningLine(char * s,long int l){

#line 118 "/home/alois/Documents/bah-bah/src/errors.bah"
if (debug) {

#line 119 "/home/alois/Documents/bah-bah/src/errors.bah"
s = noASCIIescape(s);

#line 120 "/home/alois/Documents/bah-bah/src/errors.bah"
char ** ____BAH_COMPILER_VAR_310 = &s;
struct reflectElement ____BAH_COMPILER_VAR_311 = __reflect(____BAH_COMPILER_VAR_310, sizeof(char **), "\011\0\0\0""cpstring*", "\02\0\0\0""&s", 0, 0, 0, 0, 0);
debugError("\07\0\0\0""warning",l,0,0,____BAH_COMPILER_VAR_311);

#line 121 "/home/alois/Documents/bah-bah/src/errors.bah"
return;
}

#line 123 "/home/alois/Documents/bah-bah/src/errors.bah"
char** ____BAH_COMPILER_VAR_312 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_312[6] = "\04\0\0\0""\e[0m";____BAH_COMPILER_VAR_312[5] = s;____BAH_COMPILER_VAR_312[4] = "\06\0\0\0""\n\e[0m\t";____BAH_COMPILER_VAR_312[3] = intToStr(l);____BAH_COMPILER_VAR_312[2] = "\01\0\0\0"":";____BAH_COMPILER_VAR_312[1] = compilerState.currentFile;____BAH_COMPILER_VAR_312[0] = "\025\0\0\0""\e[1;33m[WARNING]\e[0m ";char * ____BAH_COMPILER_VAR_313 =__Bah_multiple_concat(____BAH_COMPILER_VAR_312, 7);println(____BAH_COMPILER_VAR_313);
};

#line 126 "/home/alois/Documents/bah-bah/src/errors.bah"
void throwNoticeLine(char * s,long int l){

#line 127 "/home/alois/Documents/bah-bah/src/errors.bah"
if (debug) {

#line 128 "/home/alois/Documents/bah-bah/src/errors.bah"
s = noASCIIescape(s);

#line 129 "/home/alois/Documents/bah-bah/src/errors.bah"
char ** ____BAH_COMPILER_VAR_314 = &s;
struct reflectElement ____BAH_COMPILER_VAR_315 = __reflect(____BAH_COMPILER_VAR_314, sizeof(char **), "\011\0\0\0""cpstring*", "\02\0\0\0""&s", 0, 0, 0, 0, 0);
debugError("\06\0\0\0""notice",l,0,0,____BAH_COMPILER_VAR_315);

#line 130 "/home/alois/Documents/bah-bah/src/errors.bah"
return;
}

#line 132 "/home/alois/Documents/bah-bah/src/errors.bah"
if ((noticeEnabled==false)) {

#line 133 "/home/alois/Documents/bah-bah/src/errors.bah"
return;
}

#line 135 "/home/alois/Documents/bah-bah/src/errors.bah"
char** ____BAH_COMPILER_VAR_316 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_316[6] = "\04\0\0\0""\e[0m";____BAH_COMPILER_VAR_316[5] = s;____BAH_COMPILER_VAR_316[4] = "\06\0\0\0""\n\e[0m\t";____BAH_COMPILER_VAR_316[3] = intToStr(l);____BAH_COMPILER_VAR_316[2] = "\01\0\0\0"":";____BAH_COMPILER_VAR_316[1] = compilerState.currentFile;____BAH_COMPILER_VAR_316[0] = "\024\0\0\0""\e[1;36m[NOTICE]\e[0m ";char * ____BAH_COMPILER_VAR_317 =__Bah_multiple_concat(____BAH_COMPILER_VAR_316, 7);println(____BAH_COMPILER_VAR_317);
};

#line 3 "/home/alois/Documents/bah-bah/src/fns.bah"
char isGlobal(){

#line 4 "/home/alois/Documents/bah-bah/src/fns.bah"
return (currentFn==null);
};

#line 9 "/home/alois/Documents/bah-bah/src/var.bah"
struct variable* getRealVar(char * n,struct Elems* elems){

#line 10 "/home/alois/Documents/bah-bah/src/var.bah"
unsigned long int i = len(elems->vars)-1;

#line 10 "/home/alois/Documents/bah-bah/src/var.bah"
for (; (i!=-1); 
#line 10 "/home/alois/Documents/bah-bah/src/var.bah"
--i) {

#line 11 "/home/alois/Documents/bah-bah/src/var.bah"
if ((strcmp(elems->vars->data[i]->name, n) == 0)) {

#line 12 "/home/alois/Documents/bah-bah/src/var.bah"
return elems->vars->data[i];
}
};

#line 15 "/home/alois/Documents/bah-bah/src/var.bah"
return null;
};

#line 18 "/home/alois/Documents/bah-bah/src/var.bah"
void removeVarUnar(struct string* s){

#line 19 "/home/alois/Documents/bah-bah/src/var.bah"
register long int i = 0;

#line 19 "/home/alois/Documents/bah-bah/src/var.bah"
for (; (i<s->length); 
#line 19 "/home/alois/Documents/bah-bah/src/var.bah"
++i) {

#line 20 "/home/alois/Documents/bah-bah/src/var.bah"
char c = string__charAt(s,i);

#line 21 "/home/alois/Documents/bah-bah/src/var.bah"
if ((c!=38)&&(c!=42)) {

#line 22 "/home/alois/Documents/bah-bah/src/var.bah"
break;
}
};

#line 25 "/home/alois/Documents/bah-bah/src/var.bah"
if ((i!=0)) {

#line 26 "/home/alois/Documents/bah-bah/src/var.bah"
string__trimLeft(s,i);
}
};

#line 30 "/home/alois/Documents/bah-bah/src/var.bah"
struct variable* searchVar(char * name,struct Elems* elems){

#line 32 "/home/alois/Documents/bah-bah/src/var.bah"
char * ogName = name;

#line 33 "/home/alois/Documents/bah-bah/src/var.bah"
struct string n = string(name);

#line 34 "/home/alois/Documents/bah-bah/src/var.bah"
removeVarUnar(&n);

#line 36 "/home/alois/Documents/bah-bah/src/var.bah"
if ((string__charAt(&n,n.length-1)==93)) {

#line 37 "/home/alois/Documents/bah-bah/src/var.bah"
register long int i = n.length;

#line 37 "/home/alois/Documents/bah-bah/src/var.bah"
for (; (i>0); 
#line 37 "/home/alois/Documents/bah-bah/src/var.bah"
--i) {

#line 38 "/home/alois/Documents/bah-bah/src/var.bah"
char c = string__charAt(&n,i);

#line 39 "/home/alois/Documents/bah-bah/src/var.bah"
if ((c==91)) {

#line 40 "/home/alois/Documents/bah-bah/src/var.bah"
break;
}
};

#line 43 "/home/alois/Documents/bah-bah/src/var.bah"
long int tamm = n.length-i;

#line 44 "/home/alois/Documents/bah-bah/src/var.bah"
string__trimRight(&n,tamm);

#line 45 "/home/alois/Documents/bah-bah/src/var.bah"
char isArr = (string__hasSuffix(&n,"\06\0\0\0""->data")==1);

#line 46 "/home/alois/Documents/bah-bah/src/var.bah"
if ((isArr==true)) {

#line 47 "/home/alois/Documents/bah-bah/src/var.bah"
string__trimRight(&n,6);
}

#line 49 "/home/alois/Documents/bah-bah/src/var.bah"
name = string__str(&n);

#line 50 "/home/alois/Documents/bah-bah/src/var.bah"
struct variable* v = searchVar(name,elems);

#line 52 "/home/alois/Documents/bah-bah/src/var.bah"
struct string vt = string(v->type);

#line 53 "/home/alois/Documents/bah-bah/src/var.bah"
if ((isArr==true)) {

#line 54 "/home/alois/Documents/bah-bah/src/var.bah"
string__trimLeft(&vt,2);
}

#line 55 "/home/alois/Documents/bah-bah/src/var.bah"
else if (string__hasPrefix(&vt,"\06\0\0\0""tuple:")) {

#line 56 "/home/alois/Documents/bah-bah/src/var.bah"
i = vt.length-1;

#line 56 "/home/alois/Documents/bah-bah/src/var.bah"
for (; (i>=0); 
#line 56 "/home/alois/Documents/bah-bah/src/var.bah"
--i) {

#line 57 "/home/alois/Documents/bah-bah/src/var.bah"
if ((string__charAt(&vt,i)==58)) {

#line 58 "/home/alois/Documents/bah-bah/src/var.bah"
break;
}
};

#line 61 "/home/alois/Documents/bah-bah/src/var.bah"
string__trimLeft(&vt,i);
}

#line 62 "/home/alois/Documents/bah-bah/src/var.bah"
else {

#line 63 "/home/alois/Documents/bah-bah/src/var.bah"
string__set(&vt,"\04\0\0\0""char");
}

#line 65 "/home/alois/Documents/bah-bah/src/var.bah"
char * vtstr = string__str(&vt);

#line 67 "/home/alois/Documents/bah-bah/src/var.bah"
struct variable* ____BAH_COMPILER_VAR_318 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_318->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_318->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_318->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_318->from = "\0\0\0\0""";
struct variable* nv = ____BAH_COMPILER_VAR_318;

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
if (hasStructSep(&n)&&(string__count(&n,"\01\0\0\0"")")==0)) {

#line 79 "/home/alois/Documents/bah-bah/src/var.bah"
struct string rn = splitStructSepBefore(&n);

#line 80 "/home/alois/Documents/bah-bah/src/var.bah"
name = rn.content;

#line 81 "/home/alois/Documents/bah-bah/src/var.bah"
if ((string__charAt(&n,rn.length)==46)) {

#line 82 "/home/alois/Documents/bah-bah/src/var.bah"
string__trimLeft(&n,1+rn.length);
}

#line 83 "/home/alois/Documents/bah-bah/src/var.bah"
else {

#line 84 "/home/alois/Documents/bah-bah/src/var.bah"
string__trimLeft(&n,2+rn.length);
}

#line 86 "/home/alois/Documents/bah-bah/src/var.bah"
char * membs = n.content;

#line 87 "/home/alois/Documents/bah-bah/src/var.bah"
struct variable* v = searchVar(name,elems);

#line 88 "/home/alois/Documents/bah-bah/src/var.bah"
if ((v==null)) {

#line 89 "/home/alois/Documents/bah-bah/src/var.bah"
return null;
}

#line 91 "/home/alois/Documents/bah-bah/src/var.bah"
struct cStruct* s = searchStruct(v->type,elems);

#line 92 "/home/alois/Documents/bah-bah/src/var.bah"
if ((s==null)) {

#line 93 "/home/alois/Documents/bah-bah/src/var.bah"
return null;
}

#line 95 "/home/alois/Documents/bah-bah/src/var.bah"
struct structMemb* memb = searchStructMemb(membs,s,elems);

#line 96 "/home/alois/Documents/bah-bah/src/var.bah"
if ((memb==null)) {

#line 97 "/home/alois/Documents/bah-bah/src/var.bah"
return null;
}

#line 99 "/home/alois/Documents/bah-bah/src/var.bah"
struct variable* ____BAH_COMPILER_VAR_319 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_319->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_319->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_319->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_319->from = "\0\0\0\0""";
struct variable* nv = ____BAH_COMPILER_VAR_319;

#line 100 "/home/alois/Documents/bah-bah/src/var.bah"
nv->from = memb->from;

#line 101 "/home/alois/Documents/bah-bah/src/var.bah"
nv->name = memb->name;

#line 102 "/home/alois/Documents/bah-bah/src/var.bah"
nv->type = memb->type;

#line 103 "/home/alois/Documents/bah-bah/src/var.bah"
nv->declScope = v->declScope;

#line 104 "/home/alois/Documents/bah-bah/src/var.bah"
nv->name = ogName;

#line 106 "/home/alois/Documents/bah-bah/src/var.bah"
char * r = nv->type;

#line 107 "/home/alois/Documents/bah-bah/src/var.bah"
struct string tcc = string(ogName);

#line 108 "/home/alois/Documents/bah-bah/src/var.bah"
if ((string__charAt(&tcc,0)==38)) {

#line 109 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_320 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_320[1] = "\01\0\0\0""*";____BAH_COMPILER_VAR_320[0] = r;char * ____BAH_COMPILER_VAR_321 =__Bah_multiple_concat(____BAH_COMPILER_VAR_320, 2);r = ____BAH_COMPILER_VAR_321;
}

#line 111 "/home/alois/Documents/bah-bah/src/var.bah"
long int nbUnaries = string__count(&tcc,"\01\0\0\0""*");

#line 112 "/home/alois/Documents/bah-bah/src/var.bah"
if ((nbUnaries>0)) {

#line 113 "/home/alois/Documents/bah-bah/src/var.bah"
struct string ct = string(r);

#line 114 "/home/alois/Documents/bah-bah/src/var.bah"
long int pointerLevel = string__count(&ct,"\01\0\0\0""*");

#line 115 "/home/alois/Documents/bah-bah/src/var.bah"
if (__builtin_expect((pointerLevel<nbUnaries), 0)) {

#line 116 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_322 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_322[2] = "\034\0\0\0""' because it is not pointer.";____BAH_COMPILER_VAR_322[1] = name;____BAH_COMPILER_VAR_322[0] = "\023\0\0\0""Cannot use '*' on '";char * ____BAH_COMPILER_VAR_323 =__Bah_multiple_concat(____BAH_COMPILER_VAR_322, 3);throwErr(null,____BAH_COMPILER_VAR_323);
}

#line 118 "/home/alois/Documents/bah-bah/src/var.bah"
string__trimRight(&ct,nbUnaries);

#line 119 "/home/alois/Documents/bah-bah/src/var.bah"
r = string__str(&ct);
}

#line 121 "/home/alois/Documents/bah-bah/src/var.bah"
nv->type = r;

#line 122 "/home/alois/Documents/bah-bah/src/var.bah"
nv->name = ogName;

#line 124 "/home/alois/Documents/bah-bah/src/var.bah"
return nv;
}

#line 127 "/home/alois/Documents/bah-bah/src/var.bah"
unsigned long int i = len(elems->vars)-1;

#line 127 "/home/alois/Documents/bah-bah/src/var.bah"
for (; (i!=-1); 
#line 127 "/home/alois/Documents/bah-bah/src/var.bah"
--i) {

#line 128 "/home/alois/Documents/bah-bah/src/var.bah"
struct variable* v = elems->vars->data[i];

#line 129 "/home/alois/Documents/bah-bah/src/var.bah"
if ((strcmp(v->name, name) == 0)) {

#line 130 "/home/alois/Documents/bah-bah/src/var.bah"
struct variable* ____BAH_COMPILER_VAR_324 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_324->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_324->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_324->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_324->from = "\0\0\0\0""";
struct variable* nv = ____BAH_COMPILER_VAR_324;

#line 131 "/home/alois/Documents/bah-bah/src/var.bah"
*nv = *v;

#line 132 "/home/alois/Documents/bah-bah/src/var.bah"
char * r = nv->type;

#line 133 "/home/alois/Documents/bah-bah/src/var.bah"
struct string tcc = string(ogName);

#line 134 "/home/alois/Documents/bah-bah/src/var.bah"
if (string__count(&tcc,"\01\0\0\0""&")) {

#line 135 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_325 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_325[1] = "\01\0\0\0""*";____BAH_COMPILER_VAR_325[0] = r;char * ____BAH_COMPILER_VAR_326 =__Bah_multiple_concat(____BAH_COMPILER_VAR_325, 2);r = ____BAH_COMPILER_VAR_326;
}

#line 138 "/home/alois/Documents/bah-bah/src/var.bah"
long int nbUnaries = string__count(&tcc,"\01\0\0\0""*");

#line 139 "/home/alois/Documents/bah-bah/src/var.bah"
if ((nbUnaries>0)) {

#line 140 "/home/alois/Documents/bah-bah/src/var.bah"
struct string ct = string(r);

#line 141 "/home/alois/Documents/bah-bah/src/var.bah"
long int pointerLevel = string__count(&ct,"\01\0\0\0""*");

#line 142 "/home/alois/Documents/bah-bah/src/var.bah"
if (__builtin_expect((pointerLevel<nbUnaries), 0)) {

#line 143 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_327 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_327[2] = "\034\0\0\0""' because it is not pointer.";____BAH_COMPILER_VAR_327[1] = name;____BAH_COMPILER_VAR_327[0] = "\023\0\0\0""Cannot use '*' on '";char * ____BAH_COMPILER_VAR_328 =__Bah_multiple_concat(____BAH_COMPILER_VAR_327, 3);throwErr(null,____BAH_COMPILER_VAR_328);
}

#line 145 "/home/alois/Documents/bah-bah/src/var.bah"
string__trimRight(&ct,nbUnaries);

#line 146 "/home/alois/Documents/bah-bah/src/var.bah"
r = string__str(&ct);
}

#line 148 "/home/alois/Documents/bah-bah/src/var.bah"
nv->type = r;

#line 149 "/home/alois/Documents/bah-bah/src/var.bah"
nv->name = ogName;

#line 150 "/home/alois/Documents/bah-bah/src/var.bah"
return nv;
}
};

#line 154 "/home/alois/Documents/bah-bah/src/var.bah"
i = 0;

#line 154 "/home/alois/Documents/bah-bah/src/var.bah"
for (; (i<len(elems->fns)); 
#line 154 "/home/alois/Documents/bah-bah/src/var.bah"
++i) {

#line 155 "/home/alois/Documents/bah-bah/src/var.bah"
struct func* fn = elems->fns->data[i];

#line 156 "/home/alois/Documents/bah-bah/src/var.bah"
if ((strcmp(fn->name, name) == 0)) {

#line 157 "/home/alois/Documents/bah-bah/src/var.bah"
struct variable* ____BAH_COMPILER_VAR_329 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_329->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_329->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_329->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_329->from = "\0\0\0\0""";
struct variable* nv = ____BAH_COMPILER_VAR_329;

#line 158 "/home/alois/Documents/bah-bah/src/var.bah"
nv->name = name;

#line 159 "/home/alois/Documents/bah-bah/src/var.bah"
nv->type = "\011\0\0\0""function(";

#line 160 "/home/alois/Documents/bah-bah/src/var.bah"
register long int j = 0;

#line 160 "/home/alois/Documents/bah-bah/src/var.bah"
while ((j<len(fn->args))) {

#line 161 "/home/alois/Documents/bah-bah/src/var.bah"
struct variable* arg = fn->args->data[j];

#line 162 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_330 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_330[1] = arg->type;____BAH_COMPILER_VAR_330[0] = nv->type;char * ____BAH_COMPILER_VAR_331 =__Bah_multiple_concat(____BAH_COMPILER_VAR_330, 2);nv->type = ____BAH_COMPILER_VAR_331;

#line 163 "/home/alois/Documents/bah-bah/src/var.bah"
j = j+1;

#line 164 "/home/alois/Documents/bah-bah/src/var.bah"
if ((j<len(fn->args))) {

#line 165 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_332 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_332[1] = "\01\0\0\0"",";____BAH_COMPILER_VAR_332[0] = nv->type;char * ____BAH_COMPILER_VAR_333 =__Bah_multiple_concat(____BAH_COMPILER_VAR_332, 2);nv->type = ____BAH_COMPILER_VAR_333;
}
};

#line 168 "/home/alois/Documents/bah-bah/src/var.bah"
fn->used = true;

#line 169 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_334 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_334[2] = fn->returns->type;____BAH_COMPILER_VAR_334[1] = "\01\0\0\0"")";____BAH_COMPILER_VAR_334[0] = nv->type;char * ____BAH_COMPILER_VAR_335 =__Bah_multiple_concat(____BAH_COMPILER_VAR_334, 3);nv->type = ____BAH_COMPILER_VAR_335;

#line 170 "/home/alois/Documents/bah-bah/src/var.bah"
return nv;
}
};

#line 176 "/home/alois/Documents/bah-bah/src/var.bah"
return null;
};

#line 180 "/home/alois/Documents/bah-bah/src/var.bah"
struct variable* searchVarByToken(struct Tok* t,struct Elems* elems){

#line 181 "/home/alois/Documents/bah-bah/src/var.bah"
if ((t->bahRef!=null)) {

#line 182 "/home/alois/Documents/bah-bah/src/var.bah"
return t->bahRef;
}

#line 184 "/home/alois/Documents/bah-bah/src/var.bah"
struct string cont = string(t->cont);

#line 185 "/home/alois/Documents/bah-bah/src/var.bah"
removeVarUnar(&cont);

#line 186 "/home/alois/Documents/bah-bah/src/var.bah"
return getRealVar(string__str(&cont),elems);
};

#line 189 "/home/alois/Documents/bah-bah/src/var.bah"
struct variable* searchVirtVarByToken(struct Tok* t,struct Elems* elems){

#line 190 "/home/alois/Documents/bah-bah/src/var.bah"
if ((t->isOper==true)) {

#line 191 "/home/alois/Documents/bah-bah/src/var.bah"
return null;
}

#line 193 "/home/alois/Documents/bah-bah/src/var.bah"
if ((t->bahRef!=null)) {

#line 194 "/home/alois/Documents/bah-bah/src/var.bah"
return t->bahRef;
}

#line 196 "/home/alois/Documents/bah-bah/src/var.bah"
return searchVar(t->cont,elems);
};

#line 199 "/home/alois/Documents/bah-bah/src/var.bah"
char * setCType(struct variable* v,struct Elems* elems){

#line 200 "/home/alois/Documents/bah-bah/src/var.bah"
struct string tp = getCType(v->type,elems);

#line 201 "/home/alois/Documents/bah-bah/src/var.bah"
char * t = string__str(&tp);

#line 202 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_336 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_336[2] = v->name;____BAH_COMPILER_VAR_336[1] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_336[0] = t;char * ____BAH_COMPILER_VAR_337 =__Bah_multiple_concat(____BAH_COMPILER_VAR_336, 3);t = ____BAH_COMPILER_VAR_337;

#line 203 "/home/alois/Documents/bah-bah/src/var.bah"
return t;
};

#line 206 "/home/alois/Documents/bah-bah/src/var.bah"
void isMissingVar(struct Tok* t,struct Elems* elems){

#line 207 "/home/alois/Documents/bah-bah/src/var.bah"
register long int i = 0;

#line 207 "/home/alois/Documents/bah-bah/src/var.bah"
for (; (i<len(elems->deletedVars)); 
#line 207 "/home/alois/Documents/bah-bah/src/var.bah"
++i) {

#line 208 "/home/alois/Documents/bah-bah/src/var.bah"
if (__builtin_expect((strcmp(elems->deletedVars->data[i]->name, t->cont) == 0), 0)) {

#line 209 "/home/alois/Documents/bah-bah/src/var.bah"
throwErr(t,"\055\0\0\0""Variable {TOKEN} has reached its end of life.");
}
};
};

#line 214 "/home/alois/Documents/bah-bah/src/var.bah"
char * getTypeFromToken(struct Tok* t,char strict,struct Elems* elems){

#line 216 "/home/alois/Documents/bah-bah/src/var.bah"
if ((strcmp(t->bahType, "\0\0\0\0""") != 0)) {

#line 217 "/home/alois/Documents/bah-bah/src/var.bah"
char * r = t->bahType;

#line 218 "/home/alois/Documents/bah-bah/src/var.bah"
return r;
}

#line 220 "/home/alois/Documents/bah-bah/src/var.bah"
if ((t->type==TOKEN_TYPE_VAR)) {

#line 221 "/home/alois/Documents/bah-bah/src/var.bah"
struct variable* v = searchVar(t->cont,elems);

#line 222 "/home/alois/Documents/bah-bah/src/var.bah"
if ((v==null)) {

#line 223 "/home/alois/Documents/bah-bah/src/var.bah"
if (__builtin_expect((strict==true), 0)) {

#line 224 "/home/alois/Documents/bah-bah/src/var.bah"
isMissingVar(t,elems);

#line 225 "/home/alois/Documents/bah-bah/src/var.bah"
throwErr(t,"\024\0\0\0""Unknown var {TOKEN}.");
}

#line 226 "/home/alois/Documents/bah-bah/src/var.bah"
else {

#line 227 "/home/alois/Documents/bah-bah/src/var.bah"
return "\0\0\0\0""";
}
}

#line 230 "/home/alois/Documents/bah-bah/src/var.bah"
if ((strict==true)) {

#line 231 "/home/alois/Documents/bah-bah/src/var.bah"
if (__builtin_expect((strcmp(v->type, "\0\0\0\0""") == 0), 0)) {

#line 232 "/home/alois/Documents/bah-bah/src/var.bah"
throwErr(t,"\065\0\0\0""Cannot use {TOKEN} because it does not have any type.");
}
}

#line 235 "/home/alois/Documents/bah-bah/src/var.bah"
t->bahType = v->type;

#line 236 "/home/alois/Documents/bah-bah/src/var.bah"
return v->type;
}

#line 239 "/home/alois/Documents/bah-bah/src/var.bah"
if ((t->type==TOKEN_TYPE_FLOAT)) {

#line 240 "/home/alois/Documents/bah-bah/src/var.bah"
return "\05\0\0\0""float";
}

#line 242 "/home/alois/Documents/bah-bah/src/var.bah"
if ((t->type==TOKEN_TYPE_INT)) {

#line 243 "/home/alois/Documents/bah-bah/src/var.bah"
return "\03\0\0\0""int";
}

#line 245 "/home/alois/Documents/bah-bah/src/var.bah"
if ((t->type==TOKEN_TYPE_STR)) {

#line 246 "/home/alois/Documents/bah-bah/src/var.bah"
return "\010\0\0\0""cpstring";
}

#line 248 "/home/alois/Documents/bah-bah/src/var.bah"
if ((t->type==TOKEN_TYPE_CHAR)) {

#line 249 "/home/alois/Documents/bah-bah/src/var.bah"
return "\04\0\0\0""char";
}

#line 251 "/home/alois/Documents/bah-bah/src/var.bah"
if ((t->type==TOKEN_TYPE_BOOL)) {

#line 252 "/home/alois/Documents/bah-bah/src/var.bah"
return "\04\0\0\0""bool";
}

#line 255 "/home/alois/Documents/bah-bah/src/var.bah"
throwErr(t,"\034\0\0\0""Cannot use {TOKEN} as value.");

#line 256 "/home/alois/Documents/bah-bah/src/var.bah"
return "\0\0\0\0""";
};

#line 260 "/home/alois/Documents/bah-bah/src/var.bah"
struct func* parseFnType(struct string cvt){

#line 261 "/home/alois/Documents/bah-bah/src/var.bah"
struct func* ____BAH_COMPILER_VAR_338 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_338->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_338->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_338->args->length = 0;
            ____BAH_COMPILER_VAR_338->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_338->from = "\0\0\0\0""";
____BAH_COMPILER_VAR_338->file = "\0\0\0\0""";
____BAH_COMPILER_VAR_338->line = 1;
struct func* nf = ____BAH_COMPILER_VAR_338;

#line 262 "/home/alois/Documents/bah-bah/src/var.bah"
string__trimLeft(&cvt,9);

#line 263 "/home/alois/Documents/bah-bah/src/var.bah"
array(char)* memory = memoryAlloc(sizeof(array(char)));

memory->length = 0;
memory->elemSize = sizeof(char);

#line 264 "/home/alois/Documents/bah-bah/src/var.bah"
register long int j = 0;

#line 264 "/home/alois/Documents/bah-bah/src/var.bah"
while ((j<cvt.length)) {

#line 265 "/home/alois/Documents/bah-bah/src/var.bah"
char c = string__charAt(&cvt,j);

#line 266 "/home/alois/Documents/bah-bah/src/var.bah"
if ((c==41)) {

#line 267 "/home/alois/Documents/bah-bah/src/var.bah"
break;
}

#line 269 "/home/alois/Documents/bah-bah/src/var.bah"
struct variable* ____BAH_COMPILER_VAR_339 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_339->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_339->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_339->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_339->from = "\0\0\0\0""";
struct variable* arg = ____BAH_COMPILER_VAR_339;

#line 270 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_340 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_340[1] = intToStr(len(nf->args));____BAH_COMPILER_VAR_340[0] = "\04\0\0\0""arg_";char * ____BAH_COMPILER_VAR_341 =__Bah_multiple_concat(____BAH_COMPILER_VAR_340, 2);arg->name = ____BAH_COMPILER_VAR_341;

#line 271 "/home/alois/Documents/bah-bah/src/var.bah"
while ((j<cvt.length)) {

#line 272 "/home/alois/Documents/bah-bah/src/var.bah"
c = string__charAt(&cvt,j);

#line 273 "/home/alois/Documents/bah-bah/src/var.bah"
if ((c==44)||(c==41)) {

#line 274 "/home/alois/Documents/bah-bah/src/var.bah"
break;
}

#line 276 "/home/alois/Documents/bah-bah/src/var.bah"

    unsigned int ____BAH_COMPILER_VAR_342 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_342);
    memory->data[____BAH_COMPILER_VAR_342] = c;

#line 277 "/home/alois/Documents/bah-bah/src/var.bah"
j = j+1;
};

#line 279 "/home/alois/Documents/bah-bah/src/var.bah"
arg->type = arrToStr(memory);

#line 280 "/home/alois/Documents/bah-bah/src/var.bah"
clear(memory);

#line 281 "/home/alois/Documents/bah-bah/src/var.bah"

    unsigned int ____BAH_COMPILER_VAR_343 = len(nf->args);
    __Bah_realocate_arr(nf->args, ____BAH_COMPILER_VAR_343);
    nf->args->data[____BAH_COMPILER_VAR_343] = arg;

#line 282 "/home/alois/Documents/bah-bah/src/var.bah"
if ((c==41)) {

#line 283 "/home/alois/Documents/bah-bah/src/var.bah"
break;
}

#line 285 "/home/alois/Documents/bah-bah/src/var.bah"
j = j+1;
};

#line 287 "/home/alois/Documents/bah-bah/src/var.bah"
j = j+1;

#line 288 "/home/alois/Documents/bah-bah/src/var.bah"
while ((j<cvt.length)) {

#line 289 "/home/alois/Documents/bah-bah/src/var.bah"
char c = string__charAt(&cvt,j);

#line 290 "/home/alois/Documents/bah-bah/src/var.bah"

    unsigned int ____BAH_COMPILER_VAR_344 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_344);
    memory->data[____BAH_COMPILER_VAR_344] = c;

#line 291 "/home/alois/Documents/bah-bah/src/var.bah"
j = j+1;
};

#line 293 "/home/alois/Documents/bah-bah/src/var.bah"
struct variable* ____BAH_COMPILER_VAR_345 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_345->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_345->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_345->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_345->from = "\0\0\0\0""";
nf->returns = ____BAH_COMPILER_VAR_345;

#line 294 "/home/alois/Documents/bah-bah/src/var.bah"
nf->returns->name = "\07\0\0\0""_return";

#line 295 "/home/alois/Documents/bah-bah/src/var.bah"
nf->returns->type = arrToStr(memory);

#line 296 "/home/alois/Documents/bah-bah/src/var.bah"
return nf;
};

#line 299 "/home/alois/Documents/bah-bah/src/var.bah"
struct func* searchFunc(char * name,struct Elems* elems,char inclCurr){

#line 301 "/home/alois/Documents/bah-bah/src/var.bah"
char * ogName = name;

#line 302 "/home/alois/Documents/bah-bah/src/var.bah"
if ((strcmp(name, "\07\0\0\0""noCheck") == 0)) {

#line 303 "/home/alois/Documents/bah-bah/src/var.bah"
struct func* ____BAH_COMPILER_VAR_346 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_346->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_346->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_346->args->length = 0;
            ____BAH_COMPILER_VAR_346->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_346->from = "\0\0\0\0""";
____BAH_COMPILER_VAR_346->file = "\0\0\0\0""";
____BAH_COMPILER_VAR_346->line = 1;
struct func* fn = ____BAH_COMPILER_VAR_346;

#line 304 "/home/alois/Documents/bah-bah/src/var.bah"
fn->name = "\07\0\0\0""noCheck";

#line 305 "/home/alois/Documents/bah-bah/src/var.bah"
return fn;
}

#line 307 "/home/alois/Documents/bah-bah/src/var.bah"
struct string n = string(name);

#line 308 "/home/alois/Documents/bah-bah/src/var.bah"
if (hasStructSep(&n)) {

#line 309 "/home/alois/Documents/bah-bah/src/var.bah"
struct string fnName = splitStructSepAfter(n);

#line 310 "/home/alois/Documents/bah-bah/src/var.bah"
if ((string__charAt(&n,n.length-1-fnName.length)==46)) {

#line 311 "/home/alois/Documents/bah-bah/src/var.bah"
string__trimRight(&n,fnName.length+1);
}

#line 312 "/home/alois/Documents/bah-bah/src/var.bah"
else {

#line 313 "/home/alois/Documents/bah-bah/src/var.bah"
string__trimRight(&n,fnName.length+2);
}

#line 315 "/home/alois/Documents/bah-bah/src/var.bah"
name = string__str(&n);

#line 316 "/home/alois/Documents/bah-bah/src/var.bah"
struct variable* v = searchVar(name,elems);

#line 317 "/home/alois/Documents/bah-bah/src/var.bah"
if ((v==null)) {

#line 318 "/home/alois/Documents/bah-bah/src/var.bah"
return null;
}

#line 320 "/home/alois/Documents/bah-bah/src/var.bah"
struct cStruct* s = searchStruct(v->type,elems);

#line 321 "/home/alois/Documents/bah-bah/src/var.bah"
if ((s==null)) {

#line 322 "/home/alois/Documents/bah-bah/src/var.bah"
return null;
}

#line 324 "/home/alois/Documents/bah-bah/src/var.bah"
struct structMemb* memb = searchStructMemb(string__str(&fnName),s,elems);

#line 325 "/home/alois/Documents/bah-bah/src/var.bah"
if ((memb==null)) {

#line 326 "/home/alois/Documents/bah-bah/src/var.bah"
return null;
}

#line 328 "/home/alois/Documents/bah-bah/src/var.bah"
name = fnName.content;

#line 329 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_347 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_347[2] = name;____BAH_COMPILER_VAR_347[1] = "\02\0\0\0""__";____BAH_COMPILER_VAR_347[0] = memb->from;char * ____BAH_COMPILER_VAR_348 =__Bah_multiple_concat(____BAH_COMPILER_VAR_347, 3);name = ____BAH_COMPILER_VAR_348;
}

#line 333 "/home/alois/Documents/bah-bah/src/var.bah"
array(struct func*)* fns = elems->fns;

#line 334 "/home/alois/Documents/bah-bah/src/var.bah"
register long int i = 0;

#line 334 "/home/alois/Documents/bah-bah/src/var.bah"
while ((i<len(fns))) {

#line 335 "/home/alois/Documents/bah-bah/src/var.bah"
struct func* fn = fns->data[i];

#line 336 "/home/alois/Documents/bah-bah/src/var.bah"
if ((strcmp(fn->name, name) == 0)) {

#line 337 "/home/alois/Documents/bah-bah/src/var.bah"
fn->used = true;

#line 338 "/home/alois/Documents/bah-bah/src/var.bah"
return fn;
}

#line 340 "/home/alois/Documents/bah-bah/src/var.bah"
i = i+1;
};

#line 343 "/home/alois/Documents/bah-bah/src/var.bah"
if ((inclCurr==true)&&(currentFn!=null)) {

#line 344 "/home/alois/Documents/bah-bah/src/var.bah"
if ((strcmp(currentFn->name, name) == 0)) {

#line 345 "/home/alois/Documents/bah-bah/src/var.bah"
currentFn->used = true;

#line 346 "/home/alois/Documents/bah-bah/src/var.bah"
return currentFn;
}
}

#line 350 "/home/alois/Documents/bah-bah/src/var.bah"
struct variable* v = searchVar(ogName,elems);

#line 351 "/home/alois/Documents/bah-bah/src/var.bah"
if ((v==null)) {

#line 352 "/home/alois/Documents/bah-bah/src/var.bah"
return null;
}

#line 354 "/home/alois/Documents/bah-bah/src/var.bah"
struct func* ____BAH_COMPILER_VAR_349 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_349->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_349->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_349->args->length = 0;
            ____BAH_COMPILER_VAR_349->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_349->from = "\0\0\0\0""";
____BAH_COMPILER_VAR_349->file = "\0\0\0\0""";
____BAH_COMPILER_VAR_349->line = 1;
struct func* nf = ____BAH_COMPILER_VAR_349;

#line 355 "/home/alois/Documents/bah-bah/src/var.bah"
nf->name = ogName;

#line 356 "/home/alois/Documents/bah-bah/src/var.bah"
struct string cvt = string(v->type);

#line 357 "/home/alois/Documents/bah-bah/src/var.bah"
if ((string__hasPrefix(&cvt,"\011\0\0\0""function(")==0)) {

#line 358 "/home/alois/Documents/bah-bah/src/var.bah"
return null;
}

#line 360 "/home/alois/Documents/bah-bah/src/var.bah"
struct func* pfn = parseFnType(cvt);

#line 361 "/home/alois/Documents/bah-bah/src/var.bah"
nf->returns = pfn->returns;

#line 362 "/home/alois/Documents/bah-bah/src/var.bah"
nf->args = pfn->args;

#line 363 "/home/alois/Documents/bah-bah/src/var.bah"
return nf;
};

#line 366 "/home/alois/Documents/bah-bah/src/var.bah"
struct func* searchFuncByToken(struct Tok* t,struct Elems* elems){

#line 367 "/home/alois/Documents/bah-bah/src/var.bah"
if ((t->bahRef!=null)) {

#line 368 "/home/alois/Documents/bah-bah/src/var.bah"
return t->bahRef;
}

#line 370 "/home/alois/Documents/bah-bah/src/var.bah"
char * fnName = splitStringBefore(string(t->cont),"\01\0\0\0""(");

#line 371 "/home/alois/Documents/bah-bah/src/var.bah"
return searchFunc(fnName,elems,true);
};
char RCPavailable();

#line 376 "/home/alois/Documents/bah-bah/src/var.bah"
char * declareStructMethods(struct variable* v,struct cStruct* s,struct Elems* elems){

#line 377 "/home/alois/Documents/bah-bah/src/var.bah"
char * code = "\0\0\0\0""";

#line 378 "/home/alois/Documents/bah-bah/src/var.bah"
array(struct structMemb*)* members = s->members;

#line 379 "/home/alois/Documents/bah-bah/src/var.bah"
struct string typec = string(v->type);

#line 380 "/home/alois/Documents/bah-bah/src/var.bah"
char * sep = "\01\0\0\0"".";

#line 381 "/home/alois/Documents/bah-bah/src/var.bah"
char * amp = "\01\0\0\0""&";

#line 382 "/home/alois/Documents/bah-bah/src/var.bah"
if (string__count(&typec,"\01\0\0\0""*")) {

#line 383 "/home/alois/Documents/bah-bah/src/var.bah"
sep = "\02\0\0\0""->";

#line 384 "/home/alois/Documents/bah-bah/src/var.bah"
amp = "\0\0\0\0""";
}

#line 386 "/home/alois/Documents/bah-bah/src/var.bah"
register long int i = 0;

#line 386 "/home/alois/Documents/bah-bah/src/var.bah"
for (; (i<len(members)); 
#line 386 "/home/alois/Documents/bah-bah/src/var.bah"
++i) {

#line 387 "/home/alois/Documents/bah-bah/src/var.bah"
struct structMemb* m = members->data[i];

#line 388 "/home/alois/Documents/bah-bah/src/var.bah"
struct string cmpt = string(m->type);

#line 389 "/home/alois/Documents/bah-bah/src/var.bah"
if ((strcmp(m->def, "\0\0\0\0""") != 0)) {

#line 390 "/home/alois/Documents/bah-bah/src/var.bah"
if ((strcmp(m->def, "\05\0\0\0""false") != 0)&&(strcmp(m->def, "\01\0\0\0""0") != 0)&&(strcmp(m->def, "\04\0\0\0""null") != 0)) {

#line 391 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_350 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_350[6] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_350[5] = m->def;____BAH_COMPILER_VAR_350[4] = "\03\0\0\0"" = ";____BAH_COMPILER_VAR_350[3] = m->name;____BAH_COMPILER_VAR_350[2] = sep;____BAH_COMPILER_VAR_350[1] = v->name;____BAH_COMPILER_VAR_350[0] = code;char * ____BAH_COMPILER_VAR_351 =__Bah_multiple_concat(____BAH_COMPILER_VAR_350, 7);code = ____BAH_COMPILER_VAR_351;
}

#line 393 "/home/alois/Documents/bah-bah/src/var.bah"
continue;
}

#line 395 "/home/alois/Documents/bah-bah/src/var.bah"
if ((string__hasPrefix(&cmpt,"\02\0\0\0""[]")==1)) {

#line 396 "/home/alois/Documents/bah-bah/src/var.bah"
string__trimLeft(&cmpt,2);

#line 397 "/home/alois/Documents/bah-bah/src/var.bah"
char * cmptstr = string__str(&cmpt);

#line 398 "/home/alois/Documents/bah-bah/src/var.bah"
struct string elemCType = getCType(cmptstr,elems);

#line 399 "/home/alois/Documents/bah-bah/src/var.bah"
char * elemCTypeStr = string__str(&elemCType);

#line 400 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_352 = alloca(17 * sizeof(char*));____BAH_COMPILER_VAR_352[16] = "\017\0\0\0"");\n            ";____BAH_COMPILER_VAR_352[15] = elemCTypeStr;____BAH_COMPILER_VAR_352[14] = "\024\0\0\0""->elemSize = sizeof(";____BAH_COMPILER_VAR_352[13] = m->name;____BAH_COMPILER_VAR_352[12] = sep;____BAH_COMPILER_VAR_352[11] = v->name;____BAH_COMPILER_VAR_352[10] = "\032\0\0\0""->length = 0;\n            ";____BAH_COMPILER_VAR_352[9] = m->name;____BAH_COMPILER_VAR_352[8] = sep;____BAH_COMPILER_VAR_352[7] = v->name;____BAH_COMPILER_VAR_352[6] = "\021\0\0\0"")));\n            ";____BAH_COMPILER_VAR_352[5] = elemCTypeStr;____BAH_COMPILER_VAR_352[4] = "\034\0\0\0"" = memoryAlloc(sizeof(array(";____BAH_COMPILER_VAR_352[3] = m->name;____BAH_COMPILER_VAR_352[2] = sep;____BAH_COMPILER_VAR_352[1] = v->name;____BAH_COMPILER_VAR_352[0] = code;char * ____BAH_COMPILER_VAR_353 =__Bah_multiple_concat(____BAH_COMPILER_VAR_352, 17);code = ____BAH_COMPILER_VAR_353;

#line 404 "/home/alois/Documents/bah-bah/src/var.bah"
continue;
}

#line 406 "/home/alois/Documents/bah-bah/src/var.bah"
if ((string__hasPrefix(&cmpt,"\04\0\0\0""map:")==1)) {

#line 407 "/home/alois/Documents/bah-bah/src/var.bah"
string__trimLeft(&cmpt,4);

#line 408 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_354 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_354[3] = "\021\0\0\0"" = mapWrapper();\n";____BAH_COMPILER_VAR_354[2] = m->name;____BAH_COMPILER_VAR_354[1] = sep;____BAH_COMPILER_VAR_354[0] = v->name;char * ____BAH_COMPILER_VAR_355 =__Bah_multiple_concat(____BAH_COMPILER_VAR_354, 4);char** ____BAH_COMPILER_VAR_356 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_356[1] = ____BAH_COMPILER_VAR_355;____BAH_COMPILER_VAR_356[0] = code;char * ____BAH_COMPILER_VAR_357 =__Bah_multiple_concat(____BAH_COMPILER_VAR_356, 2);code = ____BAH_COMPILER_VAR_357;

#line 409 "/home/alois/Documents/bah-bah/src/var.bah"
continue;
}

#line 411 "/home/alois/Documents/bah-bah/src/var.bah"
if ((string__hasPrefix(&cmpt,"\05\0\0\0""chan:")==1)) {

#line 412 "/home/alois/Documents/bah-bah/src/var.bah"
string__trimLeft(&cmpt,5);

#line 413 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_358 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_358[3] = "\016\0\0\0"" = channel();\n";____BAH_COMPILER_VAR_358[2] = m->name;____BAH_COMPILER_VAR_358[1] = sep;____BAH_COMPILER_VAR_358[0] = v->name;char * ____BAH_COMPILER_VAR_359 =__Bah_multiple_concat(____BAH_COMPILER_VAR_358, 4);char** ____BAH_COMPILER_VAR_360 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_360[1] = ____BAH_COMPILER_VAR_359;____BAH_COMPILER_VAR_360[0] = code;char * ____BAH_COMPILER_VAR_361 =__Bah_multiple_concat(____BAH_COMPILER_VAR_360, 2);code = ____BAH_COMPILER_VAR_361;
}
};

#line 417 "/home/alois/Documents/bah-bah/src/var.bah"
if ((s->isBinding==false)) {

#line 418 "/home/alois/Documents/bah-bah/src/var.bah"
long int found = 0;

#line 419 "/home/alois/Documents/bah-bah/src/var.bah"
i = 0;

#line 419 "/home/alois/Documents/bah-bah/src/var.bah"
for (; (i<len(s->methods)); 
#line 419 "/home/alois/Documents/bah-bah/src/var.bah"
++i) {

#line 420 "/home/alois/Documents/bah-bah/src/var.bah"
struct func* m = s->methods->data[i];

#line 421 "/home/alois/Documents/bah-bah/src/var.bah"
if ((strcmp(m->name, "\05\0\0\0""_init") == 0)) {

#line 422 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_362 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_362[6] = "\03\0\0\0"");\n";____BAH_COMPILER_VAR_362[5] = v->name;____BAH_COMPILER_VAR_362[4] = amp;____BAH_COMPILER_VAR_362[3] = "\01\0\0\0""(";____BAH_COMPILER_VAR_362[2] = m->name;____BAH_COMPILER_VAR_362[1] = "\02\0\0\0""__";____BAH_COMPILER_VAR_362[0] = s->name;char * ____BAH_COMPILER_VAR_363 =__Bah_multiple_concat(____BAH_COMPILER_VAR_362, 7);char** ____BAH_COMPILER_VAR_364 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_364[1] = ____BAH_COMPILER_VAR_363;____BAH_COMPILER_VAR_364[0] = code;char * ____BAH_COMPILER_VAR_365 =__Bah_multiple_concat(____BAH_COMPILER_VAR_364, 2);code = ____BAH_COMPILER_VAR_365;

#line 423 "/home/alois/Documents/bah-bah/src/var.bah"
++found;
}

#line 424 "/home/alois/Documents/bah-bah/src/var.bah"
else if ((strcmp(m->name, "\04\0\0\0""_end") == 0)) {

#line 425 "/home/alois/Documents/bah-bah/src/var.bah"
if ((strcmp(sep, "\02\0\0\0""->") == 0)) {

#line 426 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_366 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_366[6] = "\03\0\0\0"");\n";____BAH_COMPILER_VAR_366[5] = m->name;____BAH_COMPILER_VAR_366[4] = "\02\0\0\0""__";____BAH_COMPILER_VAR_366[3] = s->name;____BAH_COMPILER_VAR_366[2] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_366[1] = v->name;____BAH_COMPILER_VAR_366[0] = "\014\0\0\0""memoryOnEnd(";char * ____BAH_COMPILER_VAR_367 =__Bah_multiple_concat(____BAH_COMPILER_VAR_366, 7);char** ____BAH_COMPILER_VAR_368 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_368[1] = ____BAH_COMPILER_VAR_367;____BAH_COMPILER_VAR_368[0] = code;char * ____BAH_COMPILER_VAR_369 =__Bah_multiple_concat(____BAH_COMPILER_VAR_368, 2);code = ____BAH_COMPILER_VAR_369;
}

#line 428 "/home/alois/Documents/bah-bah/src/var.bah"
++found;
}

#line 430 "/home/alois/Documents/bah-bah/src/var.bah"
if ((found==2)) {

#line 431 "/home/alois/Documents/bah-bah/src/var.bah"
break;
}
};
}

#line 436 "/home/alois/Documents/bah-bah/src/var.bah"
return code;
};

#line 439 "/home/alois/Documents/bah-bah/src/var.bah"
long int NB_COMP_VAR;

#line 441 "/home/alois/Documents/bah-bah/src/var.bah"
char * currFileHashed;

#line 442 "/home/alois/Documents/bah-bah/src/var.bah"
char * currFileHash;
char * pathToVarName(char * s);

#line 446 "/home/alois/Documents/bah-bah/src/var.bah"
char * genCompilerVar(){

#line 447 "/home/alois/Documents/bah-bah/src/var.bah"
if ((strcmp(currFileHashed, compilerState.currentFile) != 0)) {

#line 448 "/home/alois/Documents/bah-bah/src/var.bah"
currFileHash = pathToVarName(compilerState.currentFile);

#line 449 "/home/alois/Documents/bah-bah/src/var.bah"
currFileHashed = compilerState.currentFile;
}

#line 451 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_370 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_370[3] = currFileHash;____BAH_COMPILER_VAR_370[2] = "\01\0\0\0""_";____BAH_COMPILER_VAR_370[1] = intToStr(NB_COMP_VAR);____BAH_COMPILER_VAR_370[0] = "\025\0\0\0""____BAH_COMPILER_VAR_";char * ____BAH_COMPILER_VAR_371 =__Bah_multiple_concat(____BAH_COMPILER_VAR_370, 4);char * name = ____BAH_COMPILER_VAR_371;

#line 452 "/home/alois/Documents/bah-bah/src/var.bah"
NB_COMP_VAR = NB_COMP_VAR+1;

#line 453 "/home/alois/Documents/bah-bah/src/var.bah"
return name;
};

#line 456 "/home/alois/Documents/bah-bah/src/var.bah"
typedef array(struct variable*)* __BAH_ARR_TYPE_variable;
char varInArr(struct variable* v,__BAH_ARR_TYPE_variable arr){

#line 457 "/home/alois/Documents/bah-bah/src/var.bah"
if ((arr==null)) {

#line 458 "/home/alois/Documents/bah-bah/src/var.bah"
return false;
}

#line 460 "/home/alois/Documents/bah-bah/src/var.bah"
register long int j = 0;

#line 460 "/home/alois/Documents/bah-bah/src/var.bah"
while ((j<len(arr))) {

#line 461 "/home/alois/Documents/bah-bah/src/var.bah"
struct variable* ev = arr->data[j];

#line 462 "/home/alois/Documents/bah-bah/src/var.bah"
if ((strcmp(ev->name, v->name) == 0)) {

#line 463 "/home/alois/Documents/bah-bah/src/var.bah"
return true;
}

#line 465 "/home/alois/Documents/bah-bah/src/var.bah"
j = j+1;
};

#line 467 "/home/alois/Documents/bah-bah/src/var.bah"
return false;
};

#line 470 "/home/alois/Documents/bah-bah/src/var.bah"
char * pathToVarName(char * p){

#line 471 "/home/alois/Documents/bah-bah/src/var.bah"
array(char)* a = strToArr(p);

#line 472 "/home/alois/Documents/bah-bah/src/var.bah"
register long int i = 0;

#line 472 "/home/alois/Documents/bah-bah/src/var.bah"
for (; (i<len(a)); 
#line 472 "/home/alois/Documents/bah-bah/src/var.bah"
++i) {

#line 473 "/home/alois/Documents/bah-bah/src/var.bah"
long int c = a->data[i];

#line 474 "/home/alois/Documents/bah-bah/src/var.bah"
c = c-(long int)97;

#line 475 "/home/alois/Documents/bah-bah/src/var.bah"
if ((c<0)) {

#line 476 "/home/alois/Documents/bah-bah/src/var.bah"
c = 0-c;
}

#line 478 "/home/alois/Documents/bah-bah/src/var.bah"
c = c%((long int)122-(long int)97);

#line 479 "/home/alois/Documents/bah-bah/src/var.bah"
c = c+(long int)97;

#line 480 "/home/alois/Documents/bah-bah/src/var.bah"

    unsigned int ____BAH_COMPILER_VAR_372 = i;
    __Bah_realocate_arr(a, ____BAH_COMPILER_VAR_372);
    a->data[____BAH_COMPILER_VAR_372] = (char)c;
};

#line 482 "/home/alois/Documents/bah-bah/src/var.bah"
return arrToStr(a);
};
char * strLitteralToBahStr(char * s);

#line 487 "/home/alois/Documents/bah-bah/src/var.bah"
void makeInit(){

#line 488 "/home/alois/Documents/bah-bah/src/var.bah"
char * name = "\012\0\0\0""__BAH_init";

#line 489 "/home/alois/Documents/bah-bah/src/var.bah"
if ((isObject==true)) {

#line 490 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_373 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_373[1] = pathToVarName(compilerState.currentFile);____BAH_COMPILER_VAR_373[0] = name;char * ____BAH_COMPILER_VAR_374 =__Bah_multiple_concat(____BAH_COMPILER_VAR_373, 2);name = ____BAH_COMPILER_VAR_374;
}

#line 493 "/home/alois/Documents/bah-bah/src/var.bah"
char * evals = "\0\0\0\0""";

#line 494 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_375 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_375[2] = "\05\0\0\0""] = {";____BAH_COMPILER_VAR_375[1] = intToStr(len(compilerState.evals));____BAH_COMPILER_VAR_375[0] = "\065\0\0\0""volatile struct __eval_binding __tmp__evals_bindings[";char * ____BAH_COMPILER_VAR_376 =__Bah_multiple_concat(____BAH_COMPILER_VAR_375, 3);char * evalsTMPDecl = ____BAH_COMPILER_VAR_376;

#line 495 "/home/alois/Documents/bah-bah/src/var.bah"
register long int i = 0;

#line 495 "/home/alois/Documents/bah-bah/src/var.bah"
for (; (i<len(compilerState.evals)); 
#line 495 "/home/alois/Documents/bah-bah/src/var.bah"
++i) {

#line 496 "/home/alois/Documents/bah-bah/src/var.bah"
char * e = compilerState.evals->data[i];

#line 497 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_377 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_377[2] = "\01\0\0\0""\"";____BAH_COMPILER_VAR_377[1] = e;____BAH_COMPILER_VAR_377[0] = "\01\0\0\0""\"";char * ____BAH_COMPILER_VAR_378 =__Bah_multiple_concat(____BAH_COMPILER_VAR_377, 3);char** ____BAH_COMPILER_VAR_379 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_379[4] = "\012\0\0\0""\n        }";____BAH_COMPILER_VAR_379[3] = e;____BAH_COMPILER_VAR_379[2] = "\043\0\0\0"",\n            .evalFn = __Bah_eval_";____BAH_COMPILER_VAR_379[1] = strLitteralToBahStr(____BAH_COMPILER_VAR_378);____BAH_COMPILER_VAR_379[0] = "\026\0\0\0""{\n            .name = ";char * ____BAH_COMPILER_VAR_380 =__Bah_multiple_concat(____BAH_COMPILER_VAR_379, 5);char** ____BAH_COMPILER_VAR_381 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_381[1] = ____BAH_COMPILER_VAR_380;____BAH_COMPILER_VAR_381[0] = evalsTMPDecl;char * ____BAH_COMPILER_VAR_382 =__Bah_multiple_concat(____BAH_COMPILER_VAR_381, 2);evalsTMPDecl = ____BAH_COMPILER_VAR_382;

#line 501 "/home/alois/Documents/bah-bah/src/var.bah"
if ((i+1!=len(compilerState.evals))) {

#line 502 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_383 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_383[1] = "\02\0\0\0"",\n";____BAH_COMPILER_VAR_383[0] = evalsTMPDecl;char * ____BAH_COMPILER_VAR_384 =__Bah_multiple_concat(____BAH_COMPILER_VAR_383, 2);evalsTMPDecl = ____BAH_COMPILER_VAR_384;
}

#line 503 "/home/alois/Documents/bah-bah/src/var.bah"
else {

#line 504 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_385 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_385[1] = "\02\0\0\0""};";____BAH_COMPILER_VAR_385[0] = evalsTMPDecl;char * ____BAH_COMPILER_VAR_386 =__Bah_multiple_concat(____BAH_COMPILER_VAR_385, 2);evalsTMPDecl = ____BAH_COMPILER_VAR_386;
}
};

#line 508 "/home/alois/Documents/bah-bah/src/var.bah"
if ((len(compilerState.evals)!=0)) {

#line 509 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_387 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_387[2] = "\01\0\0\0"";";____BAH_COMPILER_VAR_387[1] = intToStr(len(compilerState.evals));____BAH_COMPILER_VAR_387[0] = "\073\0\0\0""__evals_bindings = __tmp__evals_bindings; __evals_length = ";char * ____BAH_COMPILER_VAR_388 =__Bah_multiple_concat(____BAH_COMPILER_VAR_387, 3);evals = ____BAH_COMPILER_VAR_388;
}

#line 510 "/home/alois/Documents/bah-bah/src/var.bah"
else {

#line 511 "/home/alois/Documents/bah-bah/src/var.bah"
evalsTMPDecl = "\0\0\0\0""";
}

#line 514 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_389 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_389[4] = "\015\0\0\0""() {\n        ";____BAH_COMPILER_VAR_389[3] = name;____BAH_COMPILER_VAR_389[2] = "\052\0\0\0""\n    void __attribute__((optimize(\"O0\"))) ";____BAH_COMPILER_VAR_389[1] = evalsTMPDecl;____BAH_COMPILER_VAR_389[0] = "\05\0\0\0""\n    ";char * ____BAH_COMPILER_VAR_390 =__Bah_multiple_concat(____BAH_COMPILER_VAR_389, 5);char** ____BAH_COMPILER_VAR_391 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_391[2] = "\014\0\0\0""\n    };\n    ";____BAH_COMPILER_VAR_391[1] = evals;____BAH_COMPILER_VAR_391[0] = "\011\0\0\0""\n        ";char * ____BAH_COMPILER_VAR_392 =__Bah_multiple_concat(____BAH_COMPILER_VAR_391, 3);OUTPUT = rope__add(OUTPUT, (rope__add(rope(____BAH_COMPILER_VAR_390), rope__add(INIT, rope(____BAH_COMPILER_VAR_392)))));
};

#line 523 "/home/alois/Documents/bah-bah/src/var.bah"
char checkedNull(char * v,struct Elems* elems){

#line 524 "/home/alois/Documents/bah-bah/src/var.bah"
for (; (elems!=null); 
#line 524 "/home/alois/Documents/bah-bah/src/var.bah"
elems = elems->parent) {

#line 525 "/home/alois/Documents/bah-bah/src/var.bah"
register long int i = 0;

#line 525 "/home/alois/Documents/bah-bah/src/var.bah"
for (; (i<len(elems->branchChecks)); 
#line 525 "/home/alois/Documents/bah-bah/src/var.bah"
++i) {

#line 526 "/home/alois/Documents/bah-bah/src/var.bah"
struct varCheck bc = elems->branchChecks->data[i];

#line 527 "/home/alois/Documents/bah-bah/src/var.bah"
if ((bc.v==null)) {

#line 528 "/home/alois/Documents/bah-bah/src/var.bah"
continue;
}

#line 530 "/home/alois/Documents/bah-bah/src/var.bah"
if ((strcmp(bc.v->name, v) == 0)) {

#line 531 "/home/alois/Documents/bah-bah/src/var.bah"
return bc.checkNull;
}
};

#line 534 "/home/alois/Documents/bah-bah/src/var.bah"
i = 0;

#line 534 "/home/alois/Documents/bah-bah/src/var.bah"
for (; (i<len(currChecks)); 
#line 534 "/home/alois/Documents/bah-bah/src/var.bah"
++i) {

#line 535 "/home/alois/Documents/bah-bah/src/var.bah"
struct varCheck bc = currChecks->data[i];

#line 536 "/home/alois/Documents/bah-bah/src/var.bah"
if ((bc.v==null)) {

#line 537 "/home/alois/Documents/bah-bah/src/var.bah"
continue;
}

#line 539 "/home/alois/Documents/bah-bah/src/var.bah"
if ((strcmp(bc.v->name, v) == 0)) {

#line 540 "/home/alois/Documents/bah-bah/src/var.bah"
return bc.checkNull;
}
};
};

#line 544 "/home/alois/Documents/bah-bah/src/var.bah"
return false;
};

#line 547 "/home/alois/Documents/bah-bah/src/var.bah"
char checkedNotNull(char * v,struct Elems* elems){

#line 548 "/home/alois/Documents/bah-bah/src/var.bah"
for (; (elems!=null); 
#line 548 "/home/alois/Documents/bah-bah/src/var.bah"
elems = elems->parent) {

#line 549 "/home/alois/Documents/bah-bah/src/var.bah"
register long int i = 0;

#line 549 "/home/alois/Documents/bah-bah/src/var.bah"
for (; (i<len(elems->branchChecks)); 
#line 549 "/home/alois/Documents/bah-bah/src/var.bah"
++i) {

#line 550 "/home/alois/Documents/bah-bah/src/var.bah"
struct varCheck bc = elems->branchChecks->data[i];

#line 551 "/home/alois/Documents/bah-bah/src/var.bah"
if ((bc.v==null)) {

#line 552 "/home/alois/Documents/bah-bah/src/var.bah"
continue;
}

#line 554 "/home/alois/Documents/bah-bah/src/var.bah"
if ((strcmp(bc.v->name, v) == 0)) {

#line 555 "/home/alois/Documents/bah-bah/src/var.bah"
return (bc.checkNull==false);
}
};

#line 558 "/home/alois/Documents/bah-bah/src/var.bah"
i = 0;

#line 558 "/home/alois/Documents/bah-bah/src/var.bah"
for (; (i<len(currChecks)); 
#line 558 "/home/alois/Documents/bah-bah/src/var.bah"
++i) {

#line 559 "/home/alois/Documents/bah-bah/src/var.bah"
struct varCheck bc = currChecks->data[i];

#line 560 "/home/alois/Documents/bah-bah/src/var.bah"
if ((bc.v==null)) {

#line 561 "/home/alois/Documents/bah-bah/src/var.bah"
continue;
}

#line 563 "/home/alois/Documents/bah-bah/src/var.bah"
if ((strcmp(bc.v->name, v) == 0)) {

#line 564 "/home/alois/Documents/bah-bah/src/var.bah"
return (bc.checkNull==false);
}
};
};

#line 568 "/home/alois/Documents/bah-bah/src/var.bah"
return false;
};

#line 571 "/home/alois/Documents/bah-bah/src/var.bah"
char canChangeNullState(struct variable* v,struct Elems* elems){

#line 572 "/home/alois/Documents/bah-bah/src/var.bah"
if ((v->declScope==elems)) {

#line 573 "/home/alois/Documents/bah-bah/src/var.bah"
return true;
}

#line 575 "/home/alois/Documents/bah-bah/src/var.bah"
return checkedNull(v->name,elems);
};

#line 578 "/home/alois/Documents/bah-bah/src/var.bah"
char * removeCast(char * s){

#line 579 "/home/alois/Documents/bah-bah/src/var.bah"
unsigned long int i = strlen(s)-1;

#line 579 "/home/alois/Documents/bah-bah/src/var.bah"
for (; (i>=0); 
#line 579 "/home/alois/Documents/bah-bah/src/var.bah"
--i) {

#line 580 "/home/alois/Documents/bah-bah/src/var.bah"
if ((s[i+4]==41)) {

#line 581 "/home/alois/Documents/bah-bah/src/var.bah"
s = cpstringSubsitute(s, i+1, strlen(s));

#line 582 "/home/alois/Documents/bah-bah/src/var.bah"
break;
}
};

#line 585 "/home/alois/Documents/bah-bah/src/var.bah"
return s;
};

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
struct rope* r = rope("\0\0\0\0""");

#line 14 "/home/alois/Documents/bah-bah/src/mem.bah"
if (strHasPrefix(v->type,"\02\0\0\0""[]")) {

#line 15 "/home/alois/Documents/bah-bah/src/mem.bah"
char** ____BAH_COMPILER_VAR_393 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_393[2] = "\03\0\0\0"");\n";____BAH_COMPILER_VAR_393[1] = v->name;____BAH_COMPILER_VAR_393[0] = "\011\0\0\0""RCP_decr(";char * ____BAH_COMPILER_VAR_394 =__Bah_multiple_concat(____BAH_COMPILER_VAR_393, 3);r = rope__add(r, rope(____BAH_COMPILER_VAR_394));
}

#line 16 "/home/alois/Documents/bah-bah/src/mem.bah"
else if (strHasPrefix(v->type,"\05\0\0\0""chan:")) {

#line 17 "/home/alois/Documents/bah-bah/src/mem.bah"
char** ____BAH_COMPILER_VAR_395 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_395[2] = "\03\0\0\0"");\n";____BAH_COMPILER_VAR_395[1] = v->name;____BAH_COMPILER_VAR_395[0] = "\011\0\0\0""RCP_decr(";char * ____BAH_COMPILER_VAR_396 =__Bah_multiple_concat(____BAH_COMPILER_VAR_395, 3);r = rope__add(r, rope(____BAH_COMPILER_VAR_396));
}

#line 18 "/home/alois/Documents/bah-bah/src/mem.bah"
else {

#line 19 "/home/alois/Documents/bah-bah/src/mem.bah"
if (strHasPrefix(v->type,"\04\0\0\0""map:")) {

#line 20 "/home/alois/Documents/bah-bah/src/mem.bah"
struct variable* ____BAH_COMPILER_VAR_397 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_397->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_397->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_397->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_397->from = "\0\0\0\0""";
struct variable* nv = ____BAH_COMPILER_VAR_397;

#line 21 "/home/alois/Documents/bah-bah/src/mem.bah"
*nv = *v;

#line 22 "/home/alois/Documents/bah-bah/src/mem.bah"
v = nv;

#line 23 "/home/alois/Documents/bah-bah/src/mem.bah"
v->type = "\013\0\0\0""mapWrapper*";
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
char** ____BAH_COMPILER_VAR_398 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_398[2] = "\03\0\0\0"");\n";____BAH_COMPILER_VAR_398[1] = v->name;____BAH_COMPILER_VAR_398[0] = "\011\0\0\0""RCP_decr(";char * ____BAH_COMPILER_VAR_399 =__Bah_multiple_concat(____BAH_COMPILER_VAR_398, 3);r = rope__add(r, rope(____BAH_COMPILER_VAR_399));
}

#line 32 "/home/alois/Documents/bah-bah/src/mem.bah"
else {

#line 33 "/home/alois/Documents/bah-bah/src/mem.bah"
char** ____BAH_COMPILER_VAR_400 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_400[4] = "\07\0\0\0""), 1);\n";____BAH_COMPILER_VAR_400[3] = v->name;____BAH_COMPILER_VAR_400[2] = "\011\0\0\0"", sizeof(";____BAH_COMPILER_VAR_400[1] = v->name;____BAH_COMPILER_VAR_400[0] = "\017\0\0\0""RCP_scanStack(&";char * ____BAH_COMPILER_VAR_401 =__Bah_multiple_concat(____BAH_COMPILER_VAR_400, 5);r = rope__add(r, rope(____BAH_COMPILER_VAR_401));
}
}

#line 35 "/home/alois/Documents/bah-bah/src/mem.bah"
else if ((isPointer==true)) {

#line 37 "/home/alois/Documents/bah-bah/src/mem.bah"
char** ____BAH_COMPILER_VAR_402 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_402[2] = "\03\0\0\0"");\n";____BAH_COMPILER_VAR_402[1] = v->name;____BAH_COMPILER_VAR_402[0] = "\011\0\0\0""RCP_decr(";char * ____BAH_COMPILER_VAR_403 =__Bah_multiple_concat(____BAH_COMPILER_VAR_402, 3);r = rope__add(r, rope(____BAH_COMPILER_VAR_403));
}
}

#line 40 "/home/alois/Documents/bah-bah/src/mem.bah"
return r;
};

#line 43 "/home/alois/Documents/bah-bah/src/mem.bah"
struct rope* incrVar(struct variable* v,struct Elems* elems){

#line 45 "/home/alois/Documents/bah-bah/src/mem.bah"
if ((strCount(v->name,"\01\0\0\0""*")>0)) {

#line 46 "/home/alois/Documents/bah-bah/src/mem.bah"
return rope("\0\0\0\0""");
}

#line 49 "/home/alois/Documents/bah-bah/src/mem.bah"
struct cStruct* s = searchStruct(v->type,elems);

#line 50 "/home/alois/Documents/bah-bah/src/mem.bah"
if ((s!=null)&&(isRCPpointerType(v->type)==false)&&(s->isBinding==false)) {

#line 51 "/home/alois/Documents/bah-bah/src/mem.bah"
char** ____BAH_COMPILER_VAR_404 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_404[4] = "\06\0\0\0""), 0);";____BAH_COMPILER_VAR_404[3] = v->name;____BAH_COMPILER_VAR_404[2] = "\011\0\0\0"", sizeof(";____BAH_COMPILER_VAR_404[1] = v->name;____BAH_COMPILER_VAR_404[0] = "\017\0\0\0""RCP_scanStack(&";char * ____BAH_COMPILER_VAR_405 =__Bah_multiple_concat(____BAH_COMPILER_VAR_404, 5);return rope(____BAH_COMPILER_VAR_405);
}

#line 54 "/home/alois/Documents/bah-bah/src/mem.bah"
char** ____BAH_COMPILER_VAR_406 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_406[2] = "\02\0\0\0"");";____BAH_COMPILER_VAR_406[1] = v->name;____BAH_COMPILER_VAR_406[0] = "\011\0\0\0""RCP_incr(";char * ____BAH_COMPILER_VAR_407 =__Bah_multiple_concat(____BAH_COMPILER_VAR_406, 3);return rope(____BAH_COMPILER_VAR_407);
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
struct variable* ____BAH_COMPILER_VAR_408 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_408->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_408->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_408->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_408->from = "\0\0\0\0""";
struct variable* av = ____BAH_COMPILER_VAR_408;

#line 149 "/home/alois/Documents/bah-bah/src/mem.bah"
av->type = t;

#line 150 "/home/alois/Documents/bah-bah/src/mem.bah"
av->declScope = elems;

#line 151 "/home/alois/Documents/bah-bah/src/mem.bah"
av->name = genCompilerVar();

#line 152 "/home/alois/Documents/bah-bah/src/mem.bah"

    unsigned int ____BAH_COMPILER_VAR_409 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_409);
    elems->vars->data[____BAH_COMPILER_VAR_409] = av;

#line 153 "/home/alois/Documents/bah-bah/src/mem.bah"
struct string cType = getCType(av->type,elems);

#line 154 "/home/alois/Documents/bah-bah/src/mem.bah"
if (isGlobal()) {

#line 155 "/home/alois/Documents/bah-bah/src/mem.bah"
char** ____BAH_COMPILER_VAR_410 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_410[3] = "\01\0\0\0"";";____BAH_COMPILER_VAR_410[2] = av->name;____BAH_COMPILER_VAR_410[1] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_410[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_411 =__Bah_multiple_concat(____BAH_COMPILER_VAR_410, 4);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_411));

#line 156 "/home/alois/Documents/bah-bah/src/mem.bah"
char** ____BAH_COMPILER_VAR_412 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_412[3] = "\01\0\0\0"";";____BAH_COMPILER_VAR_412[2] = c;____BAH_COMPILER_VAR_412[1] = "\02\0\0\0"" =";____BAH_COMPILER_VAR_412[0] = av->name;char * ____BAH_COMPILER_VAR_413 =__Bah_multiple_concat(____BAH_COMPILER_VAR_412, 4);INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_413));
}

#line 157 "/home/alois/Documents/bah-bah/src/mem.bah"
else {

#line 158 "/home/alois/Documents/bah-bah/src/mem.bah"
char** ____BAH_COMPILER_VAR_414 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_414[5] = "\01\0\0\0"";";____BAH_COMPILER_VAR_414[4] = c;____BAH_COMPILER_VAR_414[3] = "\02\0\0\0"" =";____BAH_COMPILER_VAR_414[2] = av->name;____BAH_COMPILER_VAR_414[1] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_414[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_415 =__Bah_multiple_concat(____BAH_COMPILER_VAR_414, 6);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_415));
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

#line 1 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
struct verboseOutVar {
char * markup;
char * content;
};

#line 6 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
array(char *)* noVOfns;

#line 10 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char ____BAH_COMPILER_VAR_416(array(char *)* arr, char * el) {
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

#line 11 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
if ((currentFn!=null)) {

#line 12 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
if (____BAH_COMPILER_VAR_416(noVOfns, currentFn->name)) {

#line 13 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
return false;
}
}

#line 16 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
return true;
};

#line 19 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
struct verboseOutVar verboseOutTransformVar(struct variable* v,char * cont,struct Elems* elems){

#line 20 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
struct verboseOutVar ____BAH_COMPILER_VAR_417 = {};
struct verboseOutVar rv = ____BAH_COMPILER_VAR_417;

#line 21 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char * ogCont = cont;

#line 22 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
if ((strcmp(v->type, "\010\0\0\0""cpstring") == 0)) {

#line 23 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char** ____BAH_COMPILER_VAR_418 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_418[2] = "\01\0\0\0"")";____BAH_COMPILER_VAR_418[1] = cont;____BAH_COMPILER_VAR_418[0] = "\022\0\0\0""__Bah_safe_string(";char * ____BAH_COMPILER_VAR_419 =__Bah_multiple_concat(____BAH_COMPILER_VAR_418, 3);cont = ____BAH_COMPILER_VAR_419;
}

#line 25 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char** ____BAH_COMPILER_VAR_420 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_420[1] = cont;____BAH_COMPILER_VAR_420[0] = "\02\0\0\0"", ";char * ____BAH_COMPILER_VAR_421 =__Bah_multiple_concat(____BAH_COMPILER_VAR_420, 2);cont = ____BAH_COMPILER_VAR_421;

#line 26 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char * ct = "\0\0\0\0""";

#line 27 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
if ((strcmp(v->type, "\010\0\0\0""cpstring") == 0)) {

#line 28 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
ct = "\02\0\0\0""%s";
}

#line 29 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
else if ((strcmp(v->type, "\03\0\0\0""int") == 0)) {

#line 30 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
ct = "\03\0\0\0""%li";
}

#line 31 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
else if ((strcmp(v->type, "\05\0\0\0""float") == 0)) {

#line 32 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
ct = "\02\0\0\0""%d";
}

#line 33 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
else if ((isRCPpointerType(v->type)==true)) {

#line 34 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
ct = "\02\0\0\0""%p";
}

#line 35 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
else {

#line 36 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
struct cStruct* s = searchStruct(v->type,elems);

#line 37 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
if ((s==null)) {

#line 38 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
ct = "\03\0\0\0""%li";
}

#line 39 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
else {

#line 40 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char** ____BAH_COMPILER_VAR_422 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_422[1] = "\01\0\0\0""{";____BAH_COMPILER_VAR_422[0] = ASCII_RESET;char * ____BAH_COMPILER_VAR_423 =__Bah_multiple_concat(____BAH_COMPILER_VAR_422, 2);ct = ____BAH_COMPILER_VAR_423;

#line 41 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
cont = "\0\0\0\0""";

#line 42 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
register long int i = 0;

#line 42 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
for (; (i<len(s->members)); 
#line 42 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
++i) {

#line 43 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
struct variable* m = s->members->data[i];

#line 44 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char** ____BAH_COMPILER_VAR_424 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_424[4] = m->name;____BAH_COMPILER_VAR_424[3] = "\01\0\0\0"".";____BAH_COMPILER_VAR_424[2] = "\01\0\0\0"")";____BAH_COMPILER_VAR_424[1] = ogCont;____BAH_COMPILER_VAR_424[0] = "\01\0\0\0""(";char * ____BAH_COMPILER_VAR_425 =__Bah_multiple_concat(____BAH_COMPILER_VAR_424, 5);struct verboseOutVar mv = verboseOutTransformVar(m,____BAH_COMPILER_VAR_425,elems);

#line 45 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
if ((i!=0)) {

#line 46 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char** ____BAH_COMPILER_VAR_426 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_426[1] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_426[0] = ct;char * ____BAH_COMPILER_VAR_427 =__Bah_multiple_concat(____BAH_COMPILER_VAR_426, 2);ct = ____BAH_COMPILER_VAR_427;
}

#line 48 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char** ____BAH_COMPILER_VAR_428 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_428[1] = mv.markup;____BAH_COMPILER_VAR_428[0] = ct;char * ____BAH_COMPILER_VAR_429 =__Bah_multiple_concat(____BAH_COMPILER_VAR_428, 2);ct = ____BAH_COMPILER_VAR_429;

#line 49 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char** ____BAH_COMPILER_VAR_430 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_430[1] = mv.content;____BAH_COMPILER_VAR_430[0] = cont;char * ____BAH_COMPILER_VAR_431 =__Bah_multiple_concat(____BAH_COMPILER_VAR_430, 2);cont = ____BAH_COMPILER_VAR_431;
};

#line 51 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char** ____BAH_COMPILER_VAR_432 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_432[1] = "\01\0\0\0""}";____BAH_COMPILER_VAR_432[0] = ct;char * ____BAH_COMPILER_VAR_433 =__Bah_multiple_concat(____BAH_COMPILER_VAR_432, 2);ct = ____BAH_COMPILER_VAR_433;
}
}

#line 56 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char** ____BAH_COMPILER_VAR_434 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_434[6] = ASCII_RESET;____BAH_COMPILER_VAR_434[5] = ct;____BAH_COMPILER_VAR_434[4] = ASCII_MAGENTA;____BAH_COMPILER_VAR_434[3] = "\03\0\0\0"" = ";____BAH_COMPILER_VAR_434[2] = ASCII_RESET;____BAH_COMPILER_VAR_434[1] = v->name;____BAH_COMPILER_VAR_434[0] = ASCII_BLUE;char * ____BAH_COMPILER_VAR_435 =__Bah_multiple_concat(____BAH_COMPILER_VAR_434, 7);rv.markup = ____BAH_COMPILER_VAR_435;

#line 58 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
rv.content = cont;

#line 60 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
return rv;
};

#line 63 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
struct verboseOutVar verboseOutTransformTok(struct Tok* t,struct Elems* elems){

#line 64 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
if ((t->type==TOKEN_TYPE_VAR)&&(t->isOper==false)) {

#line 65 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
struct variable* v = searchVar(t->cont,elems);

#line 66 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
if ((v==null)) {

#line 67 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
struct verboseOutVar ____BAH_COMPILER_VAR_436 = {};
struct verboseOutVar rv = ____BAH_COMPILER_VAR_436;

#line 68 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
return rv;
}
}

#line 71 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
struct variable ____BAH_COMPILER_VAR_437 = {};
____BAH_COMPILER_VAR_437.name = "\0\0\0\0""";
____BAH_COMPILER_VAR_437.type = "\0\0\0\0""";
____BAH_COMPILER_VAR_437.constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_437.from = "\0\0\0\0""";
____BAH_COMPILER_VAR_437.name = "\07\0\0\0""(value)";
____BAH_COMPILER_VAR_437.type = getTypeFromToken(t,true,elems);
struct variable v = ____BAH_COMPILER_VAR_437;

#line 75 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
return verboseOutTransformVar(&v,t->cont,elems);
};

#line 78 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
void verboseOutFunc(struct func* fn,__BAH_ARR_TYPE_Tok args,long int lineNb,struct Elems* elems){

#line 79 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
if ((verboseOutGuard()==false)) {

#line 80 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
return;
}

#line 82 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char * nameColor = ASCII_YELLOW;

#line 83 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
if ((fn->isBinding==true)) {

#line 84 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
if (strHasPrefix(compilerState.currentFile,BAH_DIR)) {

#line 85 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
return;
}

#line 87 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
nameColor = ASCII_GREY;
}

#line 89 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
if (strHasPrefix(fn->file,BAH_DIR)) {

#line 90 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char hasPtr = false;

#line 91 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
register long int i = 0;

#line 91 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
for (; (i<len(fn->args)); 
#line 91 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
++i) {

#line 92 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
struct variable* a = fn->args->data[i];

#line 93 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
if ((isRCPpointerType(a->type)==true)) {

#line 94 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
hasPtr = true;

#line 95 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
break;
}
};

#line 98 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
if ((hasPtr==false)) {

#line 99 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
return;
}
}

#line 103 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char * fnArgs = "\0\0\0\0""";

#line 104 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char * fnArgsValues = "\0\0\0\0""";

#line 105 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
register long int j = 0;

#line 105 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
for (; (j<len(fn->args)); 
#line 105 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
++j) {

#line 106 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
struct variable* a = fn->args->data[j];

#line 107 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
if ((j!=0)) {

#line 108 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char** ____BAH_COMPILER_VAR_438 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_438[1] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_438[0] = fnArgs;char * ____BAH_COMPILER_VAR_439 =__Bah_multiple_concat(____BAH_COMPILER_VAR_438, 2);fnArgs = ____BAH_COMPILER_VAR_439;
}

#line 111 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
struct Tok t = args->data[j];

#line 112 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
struct verboseOutVar v = verboseOutTransformVar(a,t.cont,elems);

#line 113 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char** ____BAH_COMPILER_VAR_440 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_440[1] = v.markup;____BAH_COMPILER_VAR_440[0] = fnArgs;char * ____BAH_COMPILER_VAR_441 =__Bah_multiple_concat(____BAH_COMPILER_VAR_440, 2);fnArgs = ____BAH_COMPILER_VAR_441;

#line 114 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char** ____BAH_COMPILER_VAR_442 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_442[1] = v.content;____BAH_COMPILER_VAR_442[0] = fnArgsValues;char * ____BAH_COMPILER_VAR_443 =__Bah_multiple_concat(____BAH_COMPILER_VAR_442, 2);fnArgsValues = ____BAH_COMPILER_VAR_443;
};

#line 116 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char** ____BAH_COMPILER_VAR_444 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_444[2] = intToStr(lineNb);____BAH_COMPILER_VAR_444[1] = "\01\0\0\0"":";____BAH_COMPILER_VAR_444[0] = compilerState.currentFile;char * ____BAH_COMPILER_VAR_445 =__Bah_multiple_concat(____BAH_COMPILER_VAR_444, 3);char * line = ____BAH_COMPILER_VAR_445;

#line 117 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char** ____BAH_COMPILER_VAR_446 = alloca(13 * sizeof(char*));____BAH_COMPILER_VAR_446[12] = "\016\0\0\0"");\n    //\n    ";____BAH_COMPILER_VAR_446[11] = fnArgsValues;____BAH_COMPILER_VAR_446[10] = "\03\0\0\0""\\n\"";____BAH_COMPILER_VAR_446[9] = ASCII_RESET;____BAH_COMPILER_VAR_446[8] = line;____BAH_COMPILER_VAR_446[7] = ASCII_GREEN;____BAH_COMPILER_VAR_446[6] = "\05\0\0\0"") -> ";____BAH_COMPILER_VAR_446[5] = fnArgs;____BAH_COMPILER_VAR_446[4] = "\01\0\0\0""(";____BAH_COMPILER_VAR_446[3] = ASCII_RESET;____BAH_COMPILER_VAR_446[2] = fn->name;____BAH_COMPILER_VAR_446[1] = nameColor;____BAH_COMPILER_VAR_446[0] = "\065\0\0\0""\n    //Verbose Runtime\n        printf(\"[VO] calling: ";char * ____BAH_COMPILER_VAR_447 =__Bah_multiple_concat(____BAH_COMPILER_VAR_446, 13);struct rope* verboseOut = rope(____BAH_COMPILER_VAR_447);

#line 122 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
if (isGlobal()) {

#line 123 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
INIT = rope__add(INIT, verboseOut);
}

#line 124 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
else {

#line 125 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
OUTPUT = rope__add(OUTPUT, verboseOut);
}
};

#line 130 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
void verboseOutOper(struct Tok* pt,struct Tok* nt,long int lineNb,struct Elems* elems){

#line 131 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
if ((verboseOutGuard()==false)) {

#line 132 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
return;
}

#line 134 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
struct verboseOutVar pvo = verboseOutTransformTok(pt,elems);

#line 135 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
struct verboseOutVar nvo = verboseOutTransformTok(nt,elems);

#line 137 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char** ____BAH_COMPILER_VAR_448 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_448[1] = nvo.content;____BAH_COMPILER_VAR_448[0] = pvo.content;char * ____BAH_COMPILER_VAR_449 =__Bah_multiple_concat(____BAH_COMPILER_VAR_448, 2);char * values = ____BAH_COMPILER_VAR_449;

#line 139 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char** ____BAH_COMPILER_VAR_450 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_450[2] = intToStr(lineNb);____BAH_COMPILER_VAR_450[1] = "\01\0\0\0"":";____BAH_COMPILER_VAR_450[0] = compilerState.currentFile;char * ____BAH_COMPILER_VAR_451 =__Bah_multiple_concat(____BAH_COMPILER_VAR_450, 3);char * line = ____BAH_COMPILER_VAR_451;

#line 140 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char** ____BAH_COMPILER_VAR_452 = alloca(11 * sizeof(char*));____BAH_COMPILER_VAR_452[10] = "\016\0\0\0"");\n    //\n    ";____BAH_COMPILER_VAR_452[9] = values;____BAH_COMPILER_VAR_452[8] = "\03\0\0\0""\\n\"";____BAH_COMPILER_VAR_452[7] = ASCII_RESET;____BAH_COMPILER_VAR_452[6] = line;____BAH_COMPILER_VAR_452[5] = ASCII_GREEN;____BAH_COMPILER_VAR_452[4] = "\04\0\0\0"" -> ";____BAH_COMPILER_VAR_452[3] = nvo.markup;____BAH_COMPILER_VAR_452[2] = "\05\0\0\0"" AND ";____BAH_COMPILER_VAR_452[1] = pvo.markup;____BAH_COMPILER_VAR_452[0] = "\065\0\0\0""\n    //Verbose Runtime\n        printf(\"[VO]    oper: ";char * ____BAH_COMPILER_VAR_453 =__Bah_multiple_concat(____BAH_COMPILER_VAR_452, 11);struct rope* verboseOut = rope(____BAH_COMPILER_VAR_453);

#line 145 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
if (isGlobal()) {

#line 146 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
INIT = rope__add(INIT, verboseOut);
}

#line 147 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
else {

#line 148 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
OUTPUT = rope__add(OUTPUT, verboseOut);
}
};

#line 1 "/home/alois/Documents/bah-bah/src/cache.bah"
struct cacheFile {
char * file;
long int last;
char * ver;
long int date;
long int mem;
long int opti;
array(char *)* files;
};

#line 11 "/home/alois/Documents/bah-bah/src/cache.bah"
array(struct cacheFile*)* cache;

#line 13 "/home/alois/Documents/bah-bah/src/cache.bah"
void readCache(){

#line 14 "/home/alois/Documents/bah-bah/src/cache.bah"
struct fileStream ____BAH_COMPILER_VAR_454 = {};
struct fileStream fs = ____BAH_COMPILER_VAR_454;

#line 15 "/home/alois/Documents/bah-bah/src/cache.bah"
char** ____BAH_COMPILER_VAR_455 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_455[1] = "\020\0\0\0""cache/cache.json";____BAH_COMPILER_VAR_455[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_456 =__Bah_multiple_concat(____BAH_COMPILER_VAR_455, 2);fileStream__open(&fs,____BAH_COMPILER_VAR_456,"\01\0\0\0""r");

#line 16 "/home/alois/Documents/bah-bah/src/cache.bah"
if ((fileStream__isValid(&fs)==0)||(fileStream__getSize(&fs)==0)) {

#line 17 "/home/alois/Documents/bah-bah/src/cache.bah"
char** ____BAH_COMPILER_VAR_457 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_457[1] = "\05\0\0\0""cache";____BAH_COMPILER_VAR_457[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_458 =__Bah_multiple_concat(____BAH_COMPILER_VAR_457, 2);mkdir(cStr(____BAH_COMPILER_VAR_458),S_IRWXU);

#line 18 "/home/alois/Documents/bah-bah/src/cache.bah"
char** ____BAH_COMPILER_VAR_459 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_459[1] = "\020\0\0\0""cache/cache.json";____BAH_COMPILER_VAR_459[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_460 =__Bah_multiple_concat(____BAH_COMPILER_VAR_459, 2);fileStream__createFile(&fs,____BAH_COMPILER_VAR_460);

#line 19 "/home/alois/Documents/bah-bah/src/cache.bah"
return;
}

#line 21 "/home/alois/Documents/bah-bah/src/cache.bah"
if ((fileStream__getSize(&fs)>0)) {

#line 22 "/home/alois/Documents/bah-bah/src/cache.bah"
struct jsonElement* j = parseJson(fileStream__readContent(&fs));

#line 23 "/home/alois/Documents/bah-bah/src/cache.bah"
fileStream__close(&fs);

#line 24 "/home/alois/Documents/bah-bah/src/cache.bah"
array(struct cacheFile**)* ____BAH_COMPILER_VAR_461 = &cache;
struct cacheFile*** ____BAH_COMPILER_VAR_462 = 0;
char ** ____BAH_COMPILER_VAR_464 = (char **)((char*)(____BAH_COMPILER_VAR_462) + offsetof(struct cacheFile, file));
struct reflectElement ____BAH_COMPILER_VAR_465 = __reflect(____BAH_COMPILER_VAR_464, sizeof(char *), "\010\0\0\0""cpstring", "\04\0\0\0""file", 0, 0, 0, 0, offsetof(struct cacheFile, file));
long int* ____BAH_COMPILER_VAR_466 = (long int*)((char*)(____BAH_COMPILER_VAR_462) + offsetof(struct cacheFile, last));
struct reflectElement ____BAH_COMPILER_VAR_467 = __reflect(____BAH_COMPILER_VAR_466, sizeof(long int), "\03\0\0\0""int", "\04\0\0\0""last", 0, 0, 0, 0, offsetof(struct cacheFile, last));
char ** ____BAH_COMPILER_VAR_468 = (char **)((char*)(____BAH_COMPILER_VAR_462) + offsetof(struct cacheFile, ver));
struct reflectElement ____BAH_COMPILER_VAR_469 = __reflect(____BAH_COMPILER_VAR_468, sizeof(char *), "\010\0\0\0""cpstring", "\03\0\0\0""ver", 0, 0, 0, 0, offsetof(struct cacheFile, ver));
long int* ____BAH_COMPILER_VAR_470 = (long int*)((char*)(____BAH_COMPILER_VAR_462) + offsetof(struct cacheFile, date));
struct reflectElement ____BAH_COMPILER_VAR_471 = __reflect(____BAH_COMPILER_VAR_470, sizeof(long int), "\03\0\0\0""int", "\04\0\0\0""date", 0, 0, 0, 0, offsetof(struct cacheFile, date));
long int* ____BAH_COMPILER_VAR_472 = (long int*)((char*)(____BAH_COMPILER_VAR_462) + offsetof(struct cacheFile, mem));
struct reflectElement ____BAH_COMPILER_VAR_473 = __reflect(____BAH_COMPILER_VAR_472, sizeof(long int), "\03\0\0\0""int", "\03\0\0\0""mem", 0, 0, 0, 0, offsetof(struct cacheFile, mem));
long int* ____BAH_COMPILER_VAR_474 = (long int*)((char*)(____BAH_COMPILER_VAR_462) + offsetof(struct cacheFile, opti));
struct reflectElement ____BAH_COMPILER_VAR_475 = __reflect(____BAH_COMPILER_VAR_474, sizeof(long int), "\03\0\0\0""int", "\04\0\0\0""opti", 0, 0, 0, 0, offsetof(struct cacheFile, opti));
array(char *)** ____BAH_COMPILER_VAR_476 = (array(char *)**)((char*)(____BAH_COMPILER_VAR_462) + offsetof(struct cacheFile, files));
char ** ____BAH_COMPILER_VAR_477 = 0;
struct reflectElement ____BAH_COMPILER_VAR_478 = __reflect(____BAH_COMPILER_VAR_477, sizeof(char *), "\010\0\0\0""cpstring", "\0\0\0\0""", 0, 0, 0, 0, 0);

        struct reflectElement ____BAH_COMPILER_VAR_479 = ____BAH_COMPILER_VAR_478;
        struct reflectElement ____BAH_COMPILER_VAR_480 = __reflect(____BAH_COMPILER_VAR_476, sizeof(array(char *)*), "\012\0\0\0""[]cpstring", "\05\0\0\0""files", 1, &____BAH_COMPILER_VAR_479, 0, 0, offsetof(struct cacheFile, files));

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
struct reflectElement ____BAH_COMPILER_VAR_481 = __reflect(____BAH_COMPILER_VAR_462, sizeof(struct cacheFile), "\013\0\0\0""cacheFile**", "\0\0\0\0""", 0, 0, 1, ____BAH_COMPILER_VAR_463, 0);

        struct reflectElement ____BAH_COMPILER_VAR_482 = ____BAH_COMPILER_VAR_481;
        struct reflectElement ____BAH_COMPILER_VAR_483 = __reflect(____BAH_COMPILER_VAR_461, sizeof(array(struct cacheFile**)*), "\015\0\0\0""[]cacheFile**", "\06\0\0\0""&cache", 1, &____BAH_COMPILER_VAR_482, 0, 0, 0);
jsonElement__scan(j,____BAH_COMPILER_VAR_483);
}
};

#line 30 "/home/alois/Documents/bah-bah/src/cache.bah"
struct cacheFile* getCacheFile(char * s){

#line 31 "/home/alois/Documents/bah-bah/src/cache.bah"
if ((cache==null)) {

#line 32 "/home/alois/Documents/bah-bah/src/cache.bah"
return null;
}

#line 34 "/home/alois/Documents/bah-bah/src/cache.bah"
register long int i = 0;

#line 34 "/home/alois/Documents/bah-bah/src/cache.bah"
for (; (i<len(cache)); 
#line 34 "/home/alois/Documents/bah-bah/src/cache.bah"
++i) {

#line 35 "/home/alois/Documents/bah-bah/src/cache.bah"
struct cacheFile* c = cache->data[i];

#line 36 "/home/alois/Documents/bah-bah/src/cache.bah"
if ((strcmp(c->file, s) == 0)&&(c->mem==RCPlevel)&&(c->opti==isOptimized)) {

#line 37 "/home/alois/Documents/bah-bah/src/cache.bah"
return c;
}
};

#line 40 "/home/alois/Documents/bah-bah/src/cache.bah"
return null;
};

#line 43 "/home/alois/Documents/bah-bah/src/cache.bah"
void updateCacheFile(struct cacheFile* c){

#line 44 "/home/alois/Documents/bah-bah/src/cache.bah"
c->last = getLastModified(c->file);

#line 45 "/home/alois/Documents/bah-bah/src/cache.bah"
c->ver = BAH_VERSION;

#line 46 "/home/alois/Documents/bah-bah/src/cache.bah"
c->date = getTimeUnix();
};

#line 49 "/home/alois/Documents/bah-bah/src/cache.bah"
void makeCacheFile(char * f){

#line 50 "/home/alois/Documents/bah-bah/src/cache.bah"
struct cacheFile* ____BAH_COMPILER_VAR_484 = memoryAlloc(sizeof(struct cacheFile));
____BAH_COMPILER_VAR_484->files = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_484->files->length = 0;
            ____BAH_COMPILER_VAR_484->files->elemSize = sizeof(char *);
            struct cacheFile* c = ____BAH_COMPILER_VAR_484;

#line 51 "/home/alois/Documents/bah-bah/src/cache.bah"
c->file = f;

#line 52 "/home/alois/Documents/bah-bah/src/cache.bah"
c->ver = BAH_VERSION;

#line 53 "/home/alois/Documents/bah-bah/src/cache.bah"
c->mem = RCPlevel;

#line 54 "/home/alois/Documents/bah-bah/src/cache.bah"
c->opti = isOptimized;

#line 55 "/home/alois/Documents/bah-bah/src/cache.bah"
c->date = getTimeUnix();

#line 56 "/home/alois/Documents/bah-bah/src/cache.bah"
c->last = getLastModified(f);

#line 57 "/home/alois/Documents/bah-bah/src/cache.bah"
if ((cache==null)) {

#line 58 "/home/alois/Documents/bah-bah/src/cache.bah"
cache = memoryAlloc(sizeof(array(struct cacheFile*)));

cache->length = 0;
cache->elemSize = sizeof(struct cacheFile*);
}

#line 60 "/home/alois/Documents/bah-bah/src/cache.bah"

    unsigned int ____BAH_COMPILER_VAR_485 = len(cache);
    __Bah_realocate_arr(cache, ____BAH_COMPILER_VAR_485);
    cache->data[____BAH_COMPILER_VAR_485] = c;
};

#line 63 "/home/alois/Documents/bah-bah/src/cache.bah"
void writeCache(){

#line 64 "/home/alois/Documents/bah-bah/src/cache.bah"
struct fileStream ____BAH_COMPILER_VAR_486 = {};
struct fileStream fs = ____BAH_COMPILER_VAR_486;

#line 65 "/home/alois/Documents/bah-bah/src/cache.bah"
char** ____BAH_COMPILER_VAR_487 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_487[1] = "\020\0\0\0""cache/cache.json";____BAH_COMPILER_VAR_487[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_488 =__Bah_multiple_concat(____BAH_COMPILER_VAR_487, 2);fileStream__open(&fs,____BAH_COMPILER_VAR_488,"\01\0\0\0""w");

#line 66 "/home/alois/Documents/bah-bah/src/cache.bah"
array(struct cacheFile**)* ____BAH_COMPILER_VAR_489 = &cache;
struct cacheFile*** ____BAH_COMPILER_VAR_490 = 0;
char ** ____BAH_COMPILER_VAR_492 = (char **)((char*)(____BAH_COMPILER_VAR_490) + offsetof(struct cacheFile, file));
struct reflectElement ____BAH_COMPILER_VAR_493 = __reflect(____BAH_COMPILER_VAR_492, sizeof(char *), "\010\0\0\0""cpstring", "\04\0\0\0""file", 0, 0, 0, 0, offsetof(struct cacheFile, file));
long int* ____BAH_COMPILER_VAR_494 = (long int*)((char*)(____BAH_COMPILER_VAR_490) + offsetof(struct cacheFile, last));
struct reflectElement ____BAH_COMPILER_VAR_495 = __reflect(____BAH_COMPILER_VAR_494, sizeof(long int), "\03\0\0\0""int", "\04\0\0\0""last", 0, 0, 0, 0, offsetof(struct cacheFile, last));
char ** ____BAH_COMPILER_VAR_496 = (char **)((char*)(____BAH_COMPILER_VAR_490) + offsetof(struct cacheFile, ver));
struct reflectElement ____BAH_COMPILER_VAR_497 = __reflect(____BAH_COMPILER_VAR_496, sizeof(char *), "\010\0\0\0""cpstring", "\03\0\0\0""ver", 0, 0, 0, 0, offsetof(struct cacheFile, ver));
long int* ____BAH_COMPILER_VAR_498 = (long int*)((char*)(____BAH_COMPILER_VAR_490) + offsetof(struct cacheFile, date));
struct reflectElement ____BAH_COMPILER_VAR_499 = __reflect(____BAH_COMPILER_VAR_498, sizeof(long int), "\03\0\0\0""int", "\04\0\0\0""date", 0, 0, 0, 0, offsetof(struct cacheFile, date));
long int* ____BAH_COMPILER_VAR_500 = (long int*)((char*)(____BAH_COMPILER_VAR_490) + offsetof(struct cacheFile, mem));
struct reflectElement ____BAH_COMPILER_VAR_501 = __reflect(____BAH_COMPILER_VAR_500, sizeof(long int), "\03\0\0\0""int", "\03\0\0\0""mem", 0, 0, 0, 0, offsetof(struct cacheFile, mem));
long int* ____BAH_COMPILER_VAR_502 = (long int*)((char*)(____BAH_COMPILER_VAR_490) + offsetof(struct cacheFile, opti));
struct reflectElement ____BAH_COMPILER_VAR_503 = __reflect(____BAH_COMPILER_VAR_502, sizeof(long int), "\03\0\0\0""int", "\04\0\0\0""opti", 0, 0, 0, 0, offsetof(struct cacheFile, opti));
array(char *)** ____BAH_COMPILER_VAR_504 = (array(char *)**)((char*)(____BAH_COMPILER_VAR_490) + offsetof(struct cacheFile, files));
char ** ____BAH_COMPILER_VAR_505 = 0;
struct reflectElement ____BAH_COMPILER_VAR_506 = __reflect(____BAH_COMPILER_VAR_505, sizeof(char *), "\010\0\0\0""cpstring", "\0\0\0\0""", 0, 0, 0, 0, 0);

        struct reflectElement ____BAH_COMPILER_VAR_507 = ____BAH_COMPILER_VAR_506;
        struct reflectElement ____BAH_COMPILER_VAR_508 = __reflect(____BAH_COMPILER_VAR_504, sizeof(array(char *)*), "\012\0\0\0""[]cpstring", "\05\0\0\0""files", 1, &____BAH_COMPILER_VAR_507, 0, 0, offsetof(struct cacheFile, files));

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
struct reflectElement ____BAH_COMPILER_VAR_509 = __reflect(____BAH_COMPILER_VAR_490, sizeof(struct cacheFile), "\013\0\0\0""cacheFile**", "\0\0\0\0""", 0, 0, 1, ____BAH_COMPILER_VAR_491, 0);

        struct reflectElement ____BAH_COMPILER_VAR_510 = ____BAH_COMPILER_VAR_509;
        struct reflectElement ____BAH_COMPILER_VAR_511 = __reflect(____BAH_COMPILER_VAR_489, sizeof(array(struct cacheFile**)*), "\015\0\0\0""[]cacheFile**", "\06\0\0\0""&cache", 1, &____BAH_COMPILER_VAR_510, 0, 0, 0);
fileStream__writeFile(&fs,toJson(____BAH_COMPILER_VAR_511));

#line 67 "/home/alois/Documents/bah-bah/src/cache.bah"
fileStream__close(&fs);
};

#line 70 "/home/alois/Documents/bah-bah/src/cache.bah"
char isValidCacheFile(struct cacheFile* cf){

#line 71 "/home/alois/Documents/bah-bah/src/cache.bah"
if ((cf->last!=getLastModified(cf->file))) {

#line 72 "/home/alois/Documents/bah-bah/src/cache.bah"
return false;
}

#line 74 "/home/alois/Documents/bah-bah/src/cache.bah"
char** ____BAH_COMPILER_VAR_512 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_512[5] = "\04\0\0\0"".o.o";____BAH_COMPILER_VAR_512[4] = intToStr(cf->opti);____BAH_COMPILER_VAR_512[3] = intToStr(cf->mem);____BAH_COMPILER_VAR_512[2] = pathToVarName(cf->file);____BAH_COMPILER_VAR_512[1] = "\06\0\0\0""cache/";____BAH_COMPILER_VAR_512[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_513 =__Bah_multiple_concat(____BAH_COMPILER_VAR_512, 6);if ((fileExists(____BAH_COMPILER_VAR_513)==0)) {

#line 75 "/home/alois/Documents/bah-bah/src/cache.bah"
return false;
}

#line 78 "/home/alois/Documents/bah-bah/src/cache.bah"
if ((strcmp(cf->ver, BAH_VERSION) != 0)) {

#line 79 "/home/alois/Documents/bah-bah/src/cache.bah"
return false;
}

#line 81 "/home/alois/Documents/bah-bah/src/cache.bah"
return true;
};

#line 1 "/home/alois/Documents/bah-bah/src/gen.bah"
char * genArrRealloc(struct variable* v,char * preVal,char * val,struct Elems* elems){

#line 3 "/home/alois/Documents/bah-bah/src/gen.bah"
struct string vn = string(v->name);

#line 4 "/home/alois/Documents/bah-bah/src/gen.bah"
char * nstr = splitStringBefore(vn,"\07\0\0\0""->data[");

#line 6 "/home/alois/Documents/bah-bah/src/gen.bah"
string__trimLeft(&vn,strlen(nstr)+7);

#line 7 "/home/alois/Documents/bah-bah/src/gen.bah"
string__trimRight(&vn,1);

#line 8 "/home/alois/Documents/bah-bah/src/gen.bah"
char * nLengthStr = string__str(&vn);

#line 10 "/home/alois/Documents/bah-bah/src/gen.bah"
char * nLength = genCompilerVar();

#line 12 "/home/alois/Documents/bah-bah/src/gen.bah"
char** ____BAH_COMPILER_VAR_514 = alloca(15 * sizeof(char*));____BAH_COMPILER_VAR_514[14] = val;____BAH_COMPILER_VAR_514[13] = "\04\0\0\0""] = ";____BAH_COMPILER_VAR_514[12] = nLength;____BAH_COMPILER_VAR_514[11] = "\07\0\0\0""->data[";____BAH_COMPILER_VAR_514[10] = nstr;____BAH_COMPILER_VAR_514[9] = preVal;____BAH_COMPILER_VAR_514[8] = "\07\0\0\0"");\n    ";____BAH_COMPILER_VAR_514[7] = nLength;____BAH_COMPILER_VAR_514[6] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_514[5] = nstr;____BAH_COMPILER_VAR_514[4] = "\032\0\0\0"";\n    __Bah_realocate_arr(";____BAH_COMPILER_VAR_514[3] = nLengthStr;____BAH_COMPILER_VAR_514[2] = "\03\0\0\0"" = ";____BAH_COMPILER_VAR_514[1] = nLength;____BAH_COMPILER_VAR_514[0] = "\022\0\0\0""\n    unsigned int ";char * ____BAH_COMPILER_VAR_515 =__Bah_multiple_concat(____BAH_COMPILER_VAR_514, 15);return ____BAH_COMPILER_VAR_515;
};

#line 18 "/home/alois/Documents/bah-bah/src/gen.bah"
char * genConcat(__BAH_ARR_TYPE_cpstring strs,struct Elems* elems){

#line 21 "/home/alois/Documents/bah-bah/src/gen.bah"
char * buff = genCompilerVar();

#line 22 "/home/alois/Documents/bah-bah/src/gen.bah"
char** ____BAH_COMPILER_VAR_516 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_516[4] = "\022\0\0\0"" * sizeof(char*));";____BAH_COMPILER_VAR_516[3] = intToStr(len(strs));____BAH_COMPILER_VAR_516[2] = "\012\0\0\0"" = alloca(";____BAH_COMPILER_VAR_516[1] = buff;____BAH_COMPILER_VAR_516[0] = "\07\0\0\0""char** ";char * ____BAH_COMPILER_VAR_517 =__Bah_multiple_concat(____BAH_COMPILER_VAR_516, 5);char * r = ____BAH_COMPILER_VAR_517;

#line 24 "/home/alois/Documents/bah-bah/src/gen.bah"
register long int i = 0;

#line 24 "/home/alois/Documents/bah-bah/src/gen.bah"
for (; (i<len(strs)); 
#line 24 "/home/alois/Documents/bah-bah/src/gen.bah"
++i) {

#line 25 "/home/alois/Documents/bah-bah/src/gen.bah"
char** ____BAH_COMPILER_VAR_518 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_518[5] = "\01\0\0\0"";";____BAH_COMPILER_VAR_518[4] = strs->data[i];____BAH_COMPILER_VAR_518[3] = "\04\0\0\0""] = ";____BAH_COMPILER_VAR_518[2] = intToStr(len(strs)-i-1);____BAH_COMPILER_VAR_518[1] = "\01\0\0\0""[";____BAH_COMPILER_VAR_518[0] = buff;char * ____BAH_COMPILER_VAR_519 =__Bah_multiple_concat(____BAH_COMPILER_VAR_518, 6);char** ____BAH_COMPILER_VAR_520 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_520[1] = ____BAH_COMPILER_VAR_519;____BAH_COMPILER_VAR_520[0] = r;char * ____BAH_COMPILER_VAR_521 =__Bah_multiple_concat(____BAH_COMPILER_VAR_520, 2);r = ____BAH_COMPILER_VAR_521;
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
char** ____BAH_COMPILER_VAR_522 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_522[4] = "\01\0\0\0"")";____BAH_COMPILER_VAR_522[3] = intToStr(len(strs));____BAH_COMPILER_VAR_522[2] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_522[1] = buff;____BAH_COMPILER_VAR_522[0] = "\026\0\0\0""__Bah_multiple_concat(";char * ____BAH_COMPILER_VAR_523 =__Bah_multiple_concat(____BAH_COMPILER_VAR_522, 5);char * rstr = registerRCPvar("\010\0\0\0""cpstring",____BAH_COMPILER_VAR_523,elems);

#line 35 "/home/alois/Documents/bah-bah/src/gen.bah"
return rstr;
};

#line 2 "/home/alois/Documents/bah-bah/src/optimizations.bah"
void OPTI_checkFuncScopeRef(struct Elems* elems){

#line 3 "/home/alois/Documents/bah-bah/src/optimizations.bah"
if ((strHasPrefix(compilerState.currentFile,BAH_DIR)==true)) {

#line 4 "/home/alois/Documents/bah-bah/src/optimizations.bah"
return;
}

#line 6 "/home/alois/Documents/bah-bah/src/optimizations.bah"
unsigned long int i = len(elems->vars)-1;

#line 6 "/home/alois/Documents/bah-bah/src/optimizations.bah"
for (; (i>0); 
#line 6 "/home/alois/Documents/bah-bah/src/optimizations.bah"
--i) {

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

                struct string ____BAH_COMPILER_VAR_524 = string(v->name);
                if ((isRCPpointerType(v->type)==false)&&(strcmp(v->type, "\016\0\0\0""reflectElement") != 0)&&(string__hasPrefix(&____BAH_COMPILER_VAR_524,"\025\0\0\0""____BAH_COMPILER_VAR_")==false)) {

#line 13 "/home/alois/Documents/bah-bah/src/optimizations.bah"
struct cStruct* s = searchStruct(v->type,elems);

#line 14 "/home/alois/Documents/bah-bah/src/optimizations.bah"
if ((s!=null)&&(currentFn!=null)) {

#line 15 "/home/alois/Documents/bah-bah/src/optimizations.bah"
char** ____BAH_COMPILER_VAR_525 = alloca(8 * sizeof(char*));____BAH_COMPILER_VAR_525[7] = getFuncDef(currentFn);____BAH_COMPILER_VAR_525[6] = "\040\0\0\0"") could be passed by reference.\n";____BAH_COMPILER_VAR_525[5] = v->type;____BAH_COMPILER_VAR_525[4] = "\06\0\0\0""\e[0m (";____BAH_COMPILER_VAR_525[3] = v->name;____BAH_COMPILER_VAR_525[2] = "\030\0\0\0""()\e[0m: argument \e[1;37m";____BAH_COMPILER_VAR_525[1] = currentFn->name;____BAH_COMPILER_VAR_525[0] = "\012\0\0\0""in \e[1;37m";char * ____BAH_COMPILER_VAR_526 =__Bah_multiple_concat(____BAH_COMPILER_VAR_525, 8);throwNoticeLine(____BAH_COMPILER_VAR_526,currentFn->line);
}
}
}
};
};

#line 24 "/home/alois/Documents/bah-bah/src/optimizations.bah"
char isExprExpensive(struct Tok* t){

#line 25 "/home/alois/Documents/bah-bah/src/optimizations.bah"
if ((t->isExpensive==true)) {

#line 26 "/home/alois/Documents/bah-bah/src/optimizations.bah"
return true;
}

#line 29 "/home/alois/Documents/bah-bah/src/optimizations.bah"
if ((t->type!=TOKEN_TYPE_VAR)&&(t->type!=TOKEN_TYPE_INT)&&(t->type!=TOKEN_TYPE_FLOAT)) {

#line 30 "/home/alois/Documents/bah-bah/src/optimizations.bah"
return true;
}

#line 32 "/home/alois/Documents/bah-bah/src/optimizations.bah"
return false;
};

#line 36 "/home/alois/Documents/bah-bah/src/optimizations.bah"
char * byteToOctal(unsigned char b){

#line 37 "/home/alois/Documents/bah-bah/src/optimizations.bah"
unsigned int n = b;

#line 38 "/home/alois/Documents/bah-bah/src/optimizations.bah"
char * r = "\0\0\0\0""";

#line 39 "/home/alois/Documents/bah-bah/src/optimizations.bah"
long int i = 0;

#line 39 "/home/alois/Documents/bah-bah/src/optimizations.bah"
for (; (n!=0); 
#line 39 "/home/alois/Documents/bah-bah/src/optimizations.bah"
++i) {

#line 40 "/home/alois/Documents/bah-bah/src/optimizations.bah"
char** ____BAH_COMPILER_VAR_527 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_527[1] = r;____BAH_COMPILER_VAR_527[0] = intToStr(n%8);char * ____BAH_COMPILER_VAR_528 =__Bah_multiple_concat(____BAH_COMPILER_VAR_527, 2);r = ____BAH_COMPILER_VAR_528;

#line 41 "/home/alois/Documents/bah-bah/src/optimizations.bah"
n = n/8;
};

#line 43 "/home/alois/Documents/bah-bah/src/optimizations.bah"
char * escp = "\02\0\0\0""\\0";

#line 44 "/home/alois/Documents/bah-bah/src/optimizations.bah"
if ((i==3)) {

#line 45 "/home/alois/Documents/bah-bah/src/optimizations.bah"
escp = cpstringSubsitute(escp, 0, 1);
}

#line 47 "/home/alois/Documents/bah-bah/src/optimizations.bah"
char** ____BAH_COMPILER_VAR_529 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_529[1] = r;____BAH_COMPILER_VAR_529[0] = escp;char * ____BAH_COMPILER_VAR_530 =__Bah_multiple_concat(____BAH_COMPILER_VAR_529, 2);return ____BAH_COMPILER_VAR_530;
};

#line 51 "/home/alois/Documents/bah-bah/src/optimizations.bah"
char * escapeIntOctal(long int n){

#line 52 "/home/alois/Documents/bah-bah/src/optimizations.bah"
char* s = &n;

#line 53 "/home/alois/Documents/bah-bah/src/optimizations.bah"
char** ____BAH_COMPILER_VAR_531 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_531[3] = byteToOctal((unsigned char)s[3]);____BAH_COMPILER_VAR_531[2] = byteToOctal((unsigned char)s[2]);____BAH_COMPILER_VAR_531[1] = byteToOctal((unsigned char)s[1]);____BAH_COMPILER_VAR_531[0] = byteToOctal((unsigned char)s[0]);char * ____BAH_COMPILER_VAR_532 =__Bah_multiple_concat(____BAH_COMPILER_VAR_531, 4);char * r = ____BAH_COMPILER_VAR_532;

#line 54 "/home/alois/Documents/bah-bah/src/optimizations.bah"
return r;
};

#line 57 "/home/alois/Documents/bah-bah/src/optimizations.bah"
unsigned long int getStrLen(char * s){

#line 58 "/home/alois/Documents/bah-bah/src/optimizations.bah"
unsigned long int l = strlen(s);

#line 59 "/home/alois/Documents/bah-bah/src/optimizations.bah"
long int n = 0;

#line 60 "/home/alois/Documents/bah-bah/src/optimizations.bah"
long int i = 1;

#line 60 "/home/alois/Documents/bah-bah/src/optimizations.bah"
for (; (i+1<l); 
#line 60 "/home/alois/Documents/bah-bah/src/optimizations.bah"
++i) {

#line 61 "/home/alois/Documents/bah-bah/src/optimizations.bah"
++n;

#line 62 "/home/alois/Documents/bah-bah/src/optimizations.bah"
if ((s[i+4]==(char)92)) {

#line 63 "/home/alois/Documents/bah-bah/src/optimizations.bah"
if ((s[i+1+4]==(char)10)) {

#line 64 "/home/alois/Documents/bah-bah/src/optimizations.bah"
++i;
}

#line 65 "/home/alois/Documents/bah-bah/src/optimizations.bah"
else if ((s[i+1+4]==48)) {

#line 66 "/home/alois/Documents/bah-bah/src/optimizations.bah"
++i;

#line 67 "/home/alois/Documents/bah-bah/src/optimizations.bah"
long int start = i;

#line 68 "/home/alois/Documents/bah-bah/src/optimizations.bah"
for (; (i-start<2); 
#line 68 "/home/alois/Documents/bah-bah/src/optimizations.bah"
++i) {

#line 69 "/home/alois/Documents/bah-bah/src/optimizations.bah"
if ((isNumber(s[i+4])==false)) {

#line 70 "/home/alois/Documents/bah-bah/src/optimizations.bah"
break;
}
};

#line 73 "/home/alois/Documents/bah-bah/src/optimizations.bah"
--i;
}

#line 75 "/home/alois/Documents/bah-bah/src/optimizations.bah"
++i;
}
};

#line 79 "/home/alois/Documents/bah-bah/src/optimizations.bah"
return n;
};

#line 82 "/home/alois/Documents/bah-bah/src/optimizations.bah"
char * strLitteralToBahStr(char * s){

#line 83 "/home/alois/Documents/bah-bah/src/optimizations.bah"
unsigned long int l = getStrLen(s);

#line 84 "/home/alois/Documents/bah-bah/src/optimizations.bah"
char** ____BAH_COMPILER_VAR_533 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_533[3] = s;____BAH_COMPILER_VAR_533[2] = "\01\0\0\0""\"";____BAH_COMPILER_VAR_533[1] = escapeIntOctal(l);____BAH_COMPILER_VAR_533[0] = "\01\0\0\0""\"";char * ____BAH_COMPILER_VAR_534 =__Bah_multiple_concat(____BAH_COMPILER_VAR_533, 4);return ____BAH_COMPILER_VAR_534;
};
struct Elems* dupElems(struct Elems* e);
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
struct func* ____BAH_COMPILER_VAR_535 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_535->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_535->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_535->args->length = 0;
            ____BAH_COMPILER_VAR_535->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_535->from = "\0\0\0\0""";
____BAH_COMPILER_VAR_535->file = "\0\0\0\0""";
____BAH_COMPILER_VAR_535->line = 1;
struct func* r = ____BAH_COMPILER_VAR_535;

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
struct variable* ____BAH_COMPILER_VAR_536 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_536->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_536->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_536->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_536->from = "\0\0\0\0""";
struct variable* na = ____BAH_COMPILER_VAR_536;

#line 21 "/home/alois/Documents/bah-bah/src/generics.bah"
*na = *a;

#line 22 "/home/alois/Documents/bah-bah/src/generics.bah"

    unsigned int ____BAH_COMPILER_VAR_537 = i;
    __Bah_realocate_arr(r->args, ____BAH_COMPILER_VAR_537);
    r->args->data[____BAH_COMPILER_VAR_537] = na;
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

    unsigned int ____BAH_COMPILER_VAR_538 = len(this->declared);
    __Bah_realocate_arr(this->declared, ____BAH_COMPILER_VAR_538);
    this->declared->data[____BAH_COMPILER_VAR_538] = fn;

#line 44 "/home/alois/Documents/bah-bah/src/generics.bah"

                struct string ____BAH_COMPILER_VAR_539 = getCType(fn->returns->type,elems);
                char** ____BAH_COMPILER_VAR_540 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_540[3] = "\01\0\0\0""(";____BAH_COMPILER_VAR_540[2] = fn->name;____BAH_COMPILER_VAR_540[1] = "\013\0\0\0"" __generic_";____BAH_COMPILER_VAR_540[0] = string__str(&____BAH_COMPILER_VAR_539);char * ____BAH_COMPILER_VAR_541 =__Bah_multiple_concat(____BAH_COMPILER_VAR_540, 4);OUTPUT = rope(____BAH_COMPILER_VAR_541);

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

    unsigned int ____BAH_COMPILER_VAR_542 = len(fnElems->vars);
    __Bah_realocate_arr(fnElems->vars, ____BAH_COMPILER_VAR_542);
    fnElems->vars->data[____BAH_COMPILER_VAR_542] = arg;

#line 54 "/home/alois/Documents/bah-bah/src/generics.bah"

                struct string ____BAH_COMPILER_VAR_543 = getCType(arg->type,elems);
                char** ____BAH_COMPILER_VAR_544 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_544[2] = arg->name;____BAH_COMPILER_VAR_544[1] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_544[0] = string__str(&____BAH_COMPILER_VAR_543);char * ____BAH_COMPILER_VAR_545 =__Bah_multiple_concat(____BAH_COMPILER_VAR_544, 3);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_545));

#line 56 "/home/alois/Documents/bah-bah/src/generics.bah"
if ((i+1<len(fn->args))) {

#line 57 "/home/alois/Documents/bah-bah/src/generics.bah"
OUTPUT = rope__add(OUTPUT, rope("\02\0\0\0"", "));
}
};

#line 61 "/home/alois/Documents/bah-bah/src/generics.bah"
OUTPUT = rope__add(OUTPUT, rope("\04\0\0\0"") {\n"));

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
char** ____BAH_COMPILER_VAR_546 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_546[2] = "\022\0\0\0""' is not returned.";____BAH_COMPILER_VAR_546[1] = fn->name;____BAH_COMPILER_VAR_546[0] = "\012\0\0\0""Function '";char * ____BAH_COMPILER_VAR_547 =__Bah_multiple_concat(____BAH_COMPILER_VAR_546, 3);throwErr(this->tokenName,____BAH_COMPILER_VAR_547);
}

#line 80 "/home/alois/Documents/bah-bah/src/generics.bah"
endRCPscope(fnElems,fn->args);
}

#line 82 "/home/alois/Documents/bah-bah/src/generics.bah"
else {
}

#line 86 "/home/alois/Documents/bah-bah/src/generics.bah"
struct rope* code = rope__add(OUTPUT, rope("\03\0\0\0""};\n"));

#line 87 "/home/alois/Documents/bah-bah/src/generics.bah"
OUTPUT = oldOut;

#line 88 "/home/alois/Documents/bah-bah/src/generics.bah"
rope__append(postDeclHandle,code);
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
char** ____BAH_COMPILER_VAR_548 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_548[3] = intToStr(gen->callToken->line);____BAH_COMPILER_VAR_548[2] = "\01\0\0\0"":";____BAH_COMPILER_VAR_548[1] = compilerState.currentFile;____BAH_COMPILER_VAR_548[0] = "\027\0\0\0""[Generic] called here: ";char * ____BAH_COMPILER_VAR_549 =__Bah_multiple_concat(____BAH_COMPILER_VAR_548, 4);println(____BAH_COMPILER_VAR_549);
};

#line 15 "/home/alois/Documents/bah-bah/src/parser.bah"
void debugLine(__BAH_ARR_TYPE_Tok line){

#line 16 "/home/alois/Documents/bah-bah/src/parser.bah"
char * cont = "\0\0\0\0""";

#line 17 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int i = 0;

#line 17 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i<len(line))) {

#line 18 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = line->data[i];

#line 19 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_550 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_550[3] = "\01\0\0\0""'";____BAH_COMPILER_VAR_550[2] = t.cont;____BAH_COMPILER_VAR_550[1] = "\02\0\0\0"" '";____BAH_COMPILER_VAR_550[0] = cont;char * ____BAH_COMPILER_VAR_551 =__Bah_multiple_concat(____BAH_COMPILER_VAR_550, 4);cont = ____BAH_COMPILER_VAR_551;

#line 20 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;
};

#line 22 "/home/alois/Documents/bah-bah/src/parser.bah"
println(cont);
};

#line 26 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Elems* dupElems(struct Elems* elems){

#line 27 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Elems* ____BAH_COMPILER_VAR_552 = memoryAlloc(sizeof(struct Elems));
____BAH_COMPILER_VAR_552->vars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_552->vars->length = 0;
            ____BAH_COMPILER_VAR_552->vars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_552->structs = memoryAlloc(sizeof(array(struct cStruct*)));
            ____BAH_COMPILER_VAR_552->structs->length = 0;
            ____BAH_COMPILER_VAR_552->structs->elemSize = sizeof(struct cStruct*);
            ____BAH_COMPILER_VAR_552->types = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_552->types->length = 0;
            ____BAH_COMPILER_VAR_552->types->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_552->fns = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_552->fns->length = 0;
            ____BAH_COMPILER_VAR_552->fns->elemSize = sizeof(struct func*);
            ____BAH_COMPILER_VAR_552->deletedVars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_552->deletedVars->length = 0;
            ____BAH_COMPILER_VAR_552->deletedVars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_552->branchChecks = memoryAlloc(sizeof(array(struct varCheck)));
            ____BAH_COMPILER_VAR_552->branchChecks->length = 0;
            ____BAH_COMPILER_VAR_552->branchChecks->elemSize = sizeof(struct varCheck);
            struct Elems* nElems = ____BAH_COMPILER_VAR_552;

#line 28 "/home/alois/Documents/bah-bah/src/parser.bah"
nElems->parent = elems;

#line 31 "/home/alois/Documents/bah-bah/src/parser.bah"
allocateArray(nElems->vars,len(elems->vars));

#line 32 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int j = 0;

#line 32 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (j<len(elems->vars)); 
#line 32 "/home/alois/Documents/bah-bah/src/parser.bah"
++j) {

#line 33 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_553 = j;
    __Bah_realocate_arr(nElems->vars, ____BAH_COMPILER_VAR_553);
    nElems->vars->data[____BAH_COMPILER_VAR_553] = elems->vars->data[j];
};

#line 37 "/home/alois/Documents/bah-bah/src/parser.bah"
nElems->structs = elems->structs;

#line 40 "/home/alois/Documents/bah-bah/src/parser.bah"
nElems->types = elems->types;

#line 43 "/home/alois/Documents/bah-bah/src/parser.bah"
nElems->fns = elems->fns;

#line 45 "/home/alois/Documents/bah-bah/src/parser.bah"
return nElems;
};
typedef long int lineType;

#line 50 "/home/alois/Documents/bah-bah/src/parser.bah"
#define LINE_TYPE_INCLUDE (lineType)0

#line 51 "/home/alois/Documents/bah-bah/src/parser.bah"
#define LINE_TYPE_DEFINE (lineType)1

#line 52 "/home/alois/Documents/bah-bah/src/parser.bah"
#define LINE_TYPE_CONST (lineType)2

#line 53 "/home/alois/Documents/bah-bah/src/parser.bah"
#define LINE_TYPE_VAR (lineType)3

#line 54 "/home/alois/Documents/bah-bah/src/parser.bah"
#define LINE_TYPE_FN_DECL (lineType)4

#line 55 "/home/alois/Documents/bah-bah/src/parser.bah"
#define LINE_TYPE_FN_CALL (lineType)5

#line 56 "/home/alois/Documents/bah-bah/src/parser.bah"
#define LINE_TYPE_STRUCT (lineType)6

#line 57 "/home/alois/Documents/bah-bah/src/parser.bah"
#define LINE_TYPE_CLIB (lineType)7

#line 58 "/home/alois/Documents/bah-bah/src/parser.bah"
#define LINE_TYPE_RETURN (lineType)8

#line 59 "/home/alois/Documents/bah-bah/src/parser.bah"
#define LINE_TYPE_IF (lineType)9

#line 60 "/home/alois/Documents/bah-bah/src/parser.bah"
#define LINE_TYPE_ELSE (lineType)10

#line 61 "/home/alois/Documents/bah-bah/src/parser.bah"
#define LINE_TYPE_MACRO (lineType)11

#line 62 "/home/alois/Documents/bah-bah/src/parser.bah"
#define LINE_TYPE_FOR (lineType)12

#line 63 "/home/alois/Documents/bah-bah/src/parser.bah"
#define LINE_TYPE_FOR_OPERATOR (lineType)13

#line 64 "/home/alois/Documents/bah-bah/src/parser.bah"
#define LINE_TYPE_PRE_KEYWORD (lineType)14

#line 65 "/home/alois/Documents/bah-bah/src/parser.bah"
#define LINE_TYPE_ASYNC (lineType)15

#line 66 "/home/alois/Documents/bah-bah/src/parser.bah"
#define LINE_TYPE_IMPORT (lineType)16

#line 67 "/home/alois/Documents/bah-bah/src/parser.bah"
#define LINE_TYPE_CAPTURE (lineType)17

#line 69 "/home/alois/Documents/bah-bah/src/parser.bah"
lineType prevLine;

#line 1 "/home/alois/Documents/bah-bah/src/safety.bah"
void checkCanBeNull(struct Tok* t,char * tt,struct Elems* elems){

#line 2 "/home/alois/Documents/bah-bah/src/safety.bah"

                struct string ____BAH_COMPILER_VAR_554 = string(compilerState.currentDir);
                if ((isUnsafe==false)&&(string__hasPrefix(&____BAH_COMPILER_VAR_554,BAH_DIR)==false)&&isRCPpointerType(tt)&&(t->cont[0+4]!=38)&&(t->cont[0+4]!=42)) {

#line 3 "/home/alois/Documents/bah-bah/src/safety.bah"
struct variable* sv = searchVarByToken(t,elems);

#line 4 "/home/alois/Documents/bah-bah/src/safety.bah"
if ((sv!=null)) {

#line 5 "/home/alois/Documents/bah-bah/src/safety.bah"
if (__builtin_expect((sv->canBeNull==true)&&(checkedNotNull(sv->name,elems)==false), 0)) {

#line 6 "/home/alois/Documents/bah-bah/src/safety.bah"
char * globCheck = "\0\0\0\0""";

#line 7 "/home/alois/Documents/bah-bah/src/safety.bah"
struct cStruct* s = searchStruct(sv->type,elems);

#line 8 "/home/alois/Documents/bah-bah/src/safety.bah"
if ((sv->isGlobal==true)&&(s!=null)) {

#line 9 "/home/alois/Documents/bah-bah/src/safety.bah"
char** ____BAH_COMPILER_VAR_555 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_555[2] = "\02\0\0\0""'.";____BAH_COMPILER_VAR_555[1] = s->name;____BAH_COMPILER_VAR_555[0] = "\034\0\0\0"" or declare the var as 'new ";char * ____BAH_COMPILER_VAR_556 =__Bah_multiple_concat(____BAH_COMPILER_VAR_555, 3);globCheck = ____BAH_COMPILER_VAR_556;
}

#line 11 "/home/alois/Documents/bah-bah/src/safety.bah"
char** ____BAH_COMPILER_VAR_557 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_557[2] = "\01\0\0\0"".";____BAH_COMPILER_VAR_557[1] = globCheck;____BAH_COMPILER_VAR_557[0] = "\074\0\0\0""{TOKEN} can contain a null value. Check if the value is null";char * ____BAH_COMPILER_VAR_558 =__Bah_multiple_concat(____BAH_COMPILER_VAR_557, 3);throwErr(t,____BAH_COMPILER_VAR_558);
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
char** ____BAH_COMPILER_VAR_559 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_559[1] = name;____BAH_COMPILER_VAR_559[0] = "\01\0\0\0""&";char * ____BAH_COMPILER_VAR_560 =__Bah_multiple_concat(____BAH_COMPILER_VAR_559, 2);name = ____BAH_COMPILER_VAR_560;
}

#line 79 "/home/alois/Documents/bah-bah/src/safety.bah"
char** ____BAH_COMPILER_VAR_561 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_561[8] = "\010\0\0\0""\");\n    ";____BAH_COMPILER_VAR_561[7] = intToStr(t->line);____BAH_COMPILER_VAR_561[6] = "\01\0\0\0"":";____BAH_COMPILER_VAR_561[5] = compilerState.currentFile;____BAH_COMPILER_VAR_561[4] = "\03\0\0\0"", \"";____BAH_COMPILER_VAR_561[3] = name;____BAH_COMPILER_VAR_561[2] = "\03\0\0\0""\", ";____BAH_COMPILER_VAR_561[1] = v->name;____BAH_COMPILER_VAR_561[0] = "\022\0\0\0""\n    fixMeAddVar(\"";char * ____BAH_COMPILER_VAR_562 =__Bah_multiple_concat(____BAH_COMPILER_VAR_561, 9);char** ____BAH_COMPILER_VAR_563 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_563[1] = ____BAH_COMPILER_VAR_562;____BAH_COMPILER_VAR_563[0] = NEXT_LINE;char * ____BAH_COMPILER_VAR_564 =__Bah_multiple_concat(____BAH_COMPILER_VAR_563, 2);NEXT_LINE = ____BAH_COMPILER_VAR_564;
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
char** ____BAH_COMPILER_VAR_565 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_565[1] = name;____BAH_COMPILER_VAR_565[0] = "\01\0\0\0""&";char * ____BAH_COMPILER_VAR_566 =__Bah_multiple_concat(____BAH_COMPILER_VAR_565, 2);name = ____BAH_COMPILER_VAR_566;
}

#line 97 "/home/alois/Documents/bah-bah/src/safety.bah"
else {

#line 98 "/home/alois/Documents/bah-bah/src/safety.bah"
continue;
}

#line 100 "/home/alois/Documents/bah-bah/src/safety.bah"
char** ____BAH_COMPILER_VAR_567 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_567[8] = "\020\0\0\0""\");\n            ";____BAH_COMPILER_VAR_567[7] = intToStr(t->line);____BAH_COMPILER_VAR_567[6] = "\01\0\0\0"":";____BAH_COMPILER_VAR_567[5] = compilerState.currentFile;____BAH_COMPILER_VAR_567[4] = "\03\0\0\0"", \"";____BAH_COMPILER_VAR_567[3] = name;____BAH_COMPILER_VAR_567[2] = "\03\0\0\0""\", ";____BAH_COMPILER_VAR_567[1] = v->name;____BAH_COMPILER_VAR_567[0] = "\032\0\0\0""\n            fixMeRemVar(\"";char * ____BAH_COMPILER_VAR_568 =__Bah_multiple_concat(____BAH_COMPILER_VAR_567, 9);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_568));
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
if ((name[0+4]==42)) {

#line 120 "/home/alois/Documents/bah-bah/src/safety.bah"
name = cpstringSubsitute(name, 1, strlen(name));
}

#line 121 "/home/alois/Documents/bah-bah/src/safety.bah"
else {

#line 122 "/home/alois/Documents/bah-bah/src/safety.bah"
char** ____BAH_COMPILER_VAR_569 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_569[1] = name;____BAH_COMPILER_VAR_569[0] = "\01\0\0\0""&";char * ____BAH_COMPILER_VAR_570 =__Bah_multiple_concat(____BAH_COMPILER_VAR_569, 2);name = ____BAH_COMPILER_VAR_570;
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
char** ____BAH_COMPILER_VAR_571 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_571[8] = "\02\0\0\0""\")";____BAH_COMPILER_VAR_571[7] = intToStr(t->line);____BAH_COMPILER_VAR_571[6] = "\01\0\0\0"":";____BAH_COMPILER_VAR_571[5] = compilerState.currentFile;____BAH_COMPILER_VAR_571[4] = "\04\0\0\0""\", \"";____BAH_COMPILER_VAR_571[3] = t->cont;____BAH_COMPILER_VAR_571[2] = "\03\0\0\0"", \"";____BAH_COMPILER_VAR_571[1] = name;____BAH_COMPILER_VAR_571[0] = "\015\0\0\0""fixMeIsVarOk(";char * ____BAH_COMPILER_VAR_572 =__Bah_multiple_concat(____BAH_COMPILER_VAR_571, 9);char * fn = ____BAH_COMPILER_VAR_572;

#line 133 "/home/alois/Documents/bah-bah/src/safety.bah"
if ((ltp==LINE_TYPE_ELSE)) {

#line 134 "/home/alois/Documents/bah-bah/src/safety.bah"
char** ____BAH_COMPILER_VAR_573 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_573[1] = "\02\0\0\0""&&";____BAH_COMPILER_VAR_573[0] = fn;char * ____BAH_COMPILER_VAR_574 =__Bah_multiple_concat(____BAH_COMPILER_VAR_573, 2);prevIfShortcut = ____BAH_COMPILER_VAR_574;

#line 135 "/home/alois/Documents/bah-bah/src/safety.bah"
return;
}

#line 138 "/home/alois/Documents/bah-bah/src/safety.bah"
char** ____BAH_COMPILER_VAR_575 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_575[1] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_575[0] = fn;char * ____BAH_COMPILER_VAR_576 =__Bah_multiple_concat(____BAH_COMPILER_VAR_575, 2);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_576));
};

#line 141 "/home/alois/Documents/bah-bah/src/safety.bah"
char isStaticToken(struct Tok* t,struct Elems* elems){

#line 142 "/home/alois/Documents/bah-bah/src/safety.bah"
if ((t->type==TOKEN_TYPE_BOOL)&&((strcmp(t->cont, "\04\0\0\0""true") != 0)||(strcmp(t->cont, "\05\0\0\0""false") != 0))) {

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

#line 75 "/home/alois/Documents/bah-bah/src/parser.bah"
lineType getLineType(__BAH_ARR_TYPE_Tok line){

#line 77 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok ft = line->data[0];

#line 79 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((ft.type==TOKEN_TYPE_FUNC)) {

#line 80 "/home/alois/Documents/bah-bah/src/parser.bah"
return LINE_TYPE_FN_CALL;
}

#line 82 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((ft.type==TOKEN_TYPE_KEYWORD)) {

#line 83 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(ft.cont, "\010\0\0\0""#include") == 0)) {

#line 84 "/home/alois/Documents/bah-bah/src/parser.bah"
return LINE_TYPE_INCLUDE;
}

#line 85 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "\07\0\0\0""#import") == 0)) {

#line 86 "/home/alois/Documents/bah-bah/src/parser.bah"
return LINE_TYPE_IMPORT;
}

#line 87 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "\07\0\0\0""#define") == 0)) {

#line 88 "/home/alois/Documents/bah-bah/src/parser.bah"
return LINE_TYPE_DEFINE;
}

#line 89 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "\05\0\0\0""const") == 0)) {

#line 90 "/home/alois/Documents/bah-bah/src/parser.bah"
return LINE_TYPE_CONST;
}

#line 91 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "\06\0\0\0""struct") == 0)) {

#line 92 "/home/alois/Documents/bah-bah/src/parser.bah"
return LINE_TYPE_STRUCT;
}

#line 93 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "\05\0\0\0""#cLib") == 0)) {

#line 94 "/home/alois/Documents/bah-bah/src/parser.bah"
return LINE_TYPE_CLIB;
}

#line 95 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "\06\0\0\0""return") == 0)) {

#line 96 "/home/alois/Documents/bah-bah/src/parser.bah"
return LINE_TYPE_RETURN;
}

#line 97 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "\02\0\0\0""if") == 0)) {

#line 98 "/home/alois/Documents/bah-bah/src/parser.bah"
return LINE_TYPE_IF;
}

#line 99 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "\04\0\0\0""else") == 0)) {

#line 100 "/home/alois/Documents/bah-bah/src/parser.bah"
return LINE_TYPE_ELSE;
}

#line 101 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "\06\0\0\0""#macro") == 0)) {

#line 102 "/home/alois/Documents/bah-bah/src/parser.bah"
return LINE_TYPE_MACRO;
}

#line 103 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "\03\0\0\0""for") == 0)) {

#line 104 "/home/alois/Documents/bah-bah/src/parser.bah"
return LINE_TYPE_FOR;
}

#line 105 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "\05\0\0\0""async") == 0)) {

#line 106 "/home/alois/Documents/bah-bah/src/parser.bah"
return LINE_TYPE_ASYNC;
}

#line 107 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "\010\0\0\0""continue") == 0)||(strcmp(ft.cont, "\05\0\0\0""break") == 0)) {

#line 108 "/home/alois/Documents/bah-bah/src/parser.bah"
return LINE_TYPE_FOR_OPERATOR;
}

#line 109 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "\07\0\0\0""capture") == 0)) {

#line 110 "/home/alois/Documents/bah-bah/src/parser.bah"
return LINE_TYPE_CAPTURE;
}

#line 111 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 112 "/home/alois/Documents/bah-bah/src/parser.bah"
return LINE_TYPE_PRE_KEYWORD;
}
}

#line 114 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((ft.type==TOKEN_TYPE_VAR)) {

#line 115 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((len(line)>1)) {

#line 116 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok st = line->data[1];

#line 117 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((st.type==TOKEN_TYPE_ENCL)&&(strcmp(st.cont, "\01\0\0\0""(") == 0)) {

#line 118 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok lt = line->data[len(line)-1];

#line 119 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((lt.type==TOKEN_TYPE_ENCL)&&(strcmp(lt.cont, "\01\0\0\0""}") == 0)) {

#line 120 "/home/alois/Documents/bah-bah/src/parser.bah"
return LINE_TYPE_FN_DECL;
}

#line 122 "/home/alois/Documents/bah-bah/src/parser.bah"
return LINE_TYPE_FN_CALL;
}
}

#line 126 "/home/alois/Documents/bah-bah/src/parser.bah"
return LINE_TYPE_VAR;
}

#line 129 "/home/alois/Documents/bah-bah/src/parser.bah"
return (lineType)-1;
};

#line 133 "/home/alois/Documents/bah-bah/src/parser.bah"
__BAH_ARR_TYPE_Tok parseCast(__BAH_ARR_TYPE_Tok line,struct Elems* elems,char guard){

#line 136 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);

#line 137 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int i = 0;

#line 138 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((guard==true)) {

#line 139 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i<len(line))) {

#line 140 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = line->data[i];

#line 141 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((t.type==TOKEN_TYPE_CAST)) {

#line 142 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}

#line 144 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_577 = i;
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_577);
    nl->data[____BAH_COMPILER_VAR_577] = t;

#line 145 "/home/alois/Documents/bah-bah/src/parser.bah"
i = i+1;
};

#line 147 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((i==len(line))) {

#line 148 "/home/alois/Documents/bah-bah/src/parser.bah"
return line;
}
}

#line 152 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<len(line)); 
#line 152 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 153 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = line->data[i];

#line 154 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((t.type==TOKEN_TYPE_CAST)) {

#line 155 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((i+1<len(line))) {

#line 156 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok nnnt = line->data[i+1];

#line 158 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string tc = string(t.cont);

#line 159 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimLeft(&tc,1);

#line 160 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimRight(&tc,1);

#line 161 "/home/alois/Documents/bah-bah/src/parser.bah"
nnnt.bahType = string__str(&tc);

#line 162 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string cCast = getCType(string__str(&tc),elems);

#line 163 "/home/alois/Documents/bah-bah/src/parser.bah"
char * cCastStr = string__str(&cCast);

#line 164 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_578 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_578[3] = nnnt.cont;____BAH_COMPILER_VAR_578[2] = "\01\0\0\0"")";____BAH_COMPILER_VAR_578[1] = cCastStr;____BAH_COMPILER_VAR_578[0] = "\01\0\0\0""(";char * ____BAH_COMPILER_VAR_579 =__Bah_multiple_concat(____BAH_COMPILER_VAR_578, 4);nnnt.cont = ____BAH_COMPILER_VAR_579;

#line 165 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_580 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_580);
    nl->data[____BAH_COMPILER_VAR_580] = nnnt;

#line 166 "/home/alois/Documents/bah-bah/src/parser.bah"
i = i+2;

#line 167 "/home/alois/Documents/bah-bah/src/parser.bah"
continue;
}
}

#line 171 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_581 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_581);
    nl->data[____BAH_COMPILER_VAR_581] = t;
};

#line 174 "/home/alois/Documents/bah-bah/src/parser.bah"
return nl;
};

#line 177 "/home/alois/Documents/bah-bah/src/parser.bah"
char * getDirFromFile(char * f){

#line 178 "/home/alois/Documents/bah-bah/src/parser.bah"
long int l = strlen(f);

#line 179 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int i = l-1;

#line 179 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i>=0)) {

#line 180 "/home/alois/Documents/bah-bah/src/parser.bah"
char c = f[i+4];

#line 181 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((c==47)) {

#line 182 "/home/alois/Documents/bah-bah/src/parser.bah"
return cpstringSubsitute(f, 0, i+1);
}

#line 184 "/home/alois/Documents/bah-bah/src/parser.bah"
i = i-1;
};

#line 187 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((i<=0)) {

#line 188 "/home/alois/Documents/bah-bah/src/parser.bah"
return "\0\0\0\0""";
}

#line 191 "/home/alois/Documents/bah-bah/src/parser.bah"
return f;
};
void parseLines(__BAH_ARR_TYPE_Tok ts,struct Elems* elems);

#line 195 "/home/alois/Documents/bah-bah/src/parser.bah"
char ____BAH_COMPILER_VAR_582(array(char *)* arr, char * el) {
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

#line 197 "/home/alois/Documents/bah-bah/src/parser.bah"
char needDisableRCP = false;

#line 200 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(ccstr, "\021\0\0\0""BAH_MEM_COLLECTOR") == 0)) {

#line 201 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((RAIIenabled==true)) {

#line 202 "/home/alois/Documents/bah-bah/src/parser.bah"
ccstr = "\010\0\0\0""raii.bah";
}

#line 203 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((RCPenabled==true)) {

#line 204 "/home/alois/Documents/bah-bah/src/parser.bah"
needDisableRCP = true;

#line 205 "/home/alois/Documents/bah-bah/src/parser.bah"
if (flags__isSet(&flags,"\03\0\0\0""rcp")) {

#line 206 "/home/alois/Documents/bah-bah/src/parser.bah"
ccstr = "\07\0\0\0""rcp.bah";
}

#line 207 "/home/alois/Documents/bah-bah/src/parser.bah"
else if (flags__isSet(&flags,"\07\0\0\0""fastrcp")) {

#line 208 "/home/alois/Documents/bah-bah/src/parser.bah"
ccstr = "\013\0\0\0""fastrcp.bah";
}
}

#line 210 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 211 "/home/alois/Documents/bah-bah/src/parser.bah"
ccstr = "\06\0\0\0""gc.bah";
}
}

#line 216 "/home/alois/Documents/bah-bah/src/parser.bah"
if (____BAH_COMPILER_VAR_582(compilerState.includes, ccstr)) {

#line 217 "/home/alois/Documents/bah-bah/src/parser.bah"
return true;
}

#line 221 "/home/alois/Documents/bah-bah/src/parser.bah"
struct fileStream ____BAH_COMPILER_VAR_583 = {};
struct fileStream fs = ____BAH_COMPILER_VAR_583;

#line 222 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_584 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_584[1] = ccstr;____BAH_COMPILER_VAR_584[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_585 =__Bah_multiple_concat(____BAH_COMPILER_VAR_584, 2);char * fileName = ____BAH_COMPILER_VAR_585;

#line 223 "/home/alois/Documents/bah-bah/src/parser.bah"
char isBahDir = true;

#line 224 "/home/alois/Documents/bah-bah/src/parser.bah"
fileStream__open(&fs,fileName,"\01\0\0\0""r");

#line 225 "/home/alois/Documents/bah-bah/src/parser.bah"
char * f = fileStream__readContent(&fs);

#line 226 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((fileStream__isValid(&fs)==0)) {

#line 227 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_586 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_586[1] = ccstr;____BAH_COMPILER_VAR_586[0] = compilerState.currentDir;char * ____BAH_COMPILER_VAR_587 =__Bah_multiple_concat(____BAH_COMPILER_VAR_586, 2);fileName = absPath(____BAH_COMPILER_VAR_587);

#line 228 "/home/alois/Documents/bah-bah/src/parser.bah"
fileStream__open(&fs,fileName,"\01\0\0\0""r");

#line 229 "/home/alois/Documents/bah-bah/src/parser.bah"
f = fileStream__readContent(&fs);

#line 230 "/home/alois/Documents/bah-bah/src/parser.bah"
isBahDir = false;

#line 231 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((fileStream__isValid(&fs)==0)) {

#line 232 "/home/alois/Documents/bah-bah/src/parser.bah"
return false;
}
}

#line 237 "/home/alois/Documents/bah-bah/src/parser.bah"
char * oDir = compilerState.currentDir;

#line 238 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((isBahDir==false)) {

#line 239 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_588 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_588[1] = getDirFromFile(ccstr);____BAH_COMPILER_VAR_588[0] = compilerState.currentDir;char * ____BAH_COMPILER_VAR_589 =__Bah_multiple_concat(____BAH_COMPILER_VAR_588, 2);compilerState.currentDir = ____BAH_COMPILER_VAR_589;
}

#line 240 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 241 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_590 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_590[1] = getDirFromFile(ccstr);____BAH_COMPILER_VAR_590[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_591 =__Bah_multiple_concat(____BAH_COMPILER_VAR_590, 2);compilerState.currentDir = ____BAH_COMPILER_VAR_591;
}

#line 245 "/home/alois/Documents/bah-bah/src/parser.bah"
char * oFile = compilerState.currentFile;

#line 246 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.currentFile = fileName;

#line 247 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_592 = len(compilerState.includes);
    __Bah_realocate_arr(compilerState.includes, ____BAH_COMPILER_VAR_592);
    compilerState.includes->data[____BAH_COMPILER_VAR_592] = ccstr;

#line 250 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct Tok)* tokens = lexer(f,fileStream__getSize(&fs));

#line 251 "/home/alois/Documents/bah-bah/src/parser.bah"
fileStream__close(&fs);

#line 252 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((len(tokens)==0), 0)) {

#line 253 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_593 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_593[2] = "\021\0\0\0""' not recognized.";____BAH_COMPILER_VAR_593[1] = ccstr;____BAH_COMPILER_VAR_593[0] = "\06\0\0\0""File '";char * ____BAH_COMPILER_VAR_594 =__Bah_multiple_concat(____BAH_COMPILER_VAR_593, 3);__BAH_panic(____BAH_COMPILER_VAR_594,"\060\0\0\0""/home/alois/Documents/bah-bah/src/parser.bah:253");
}

#line 257 "/home/alois/Documents/bah-bah/src/parser.bah"
char oshd = shouldOnlyDecl;

#line 258 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((isObject==true)) {

#line 259 "/home/alois/Documents/bah-bah/src/parser.bah"

                struct string ____BAH_COMPILER_VAR_595 = string(compilerState.currentFile);
                if ((isBahDir==true)||(string__hasPrefix(&____BAH_COMPILER_VAR_595,oDir)==false)) {

#line 260 "/home/alois/Documents/bah-bah/src/parser.bah"
shouldOnlyDecl = true;
}

#line 261 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 262 "/home/alois/Documents/bah-bah/src/parser.bah"
shouldOnlyDecl = false;
}
}

#line 264 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((isSubObject==true)) {

#line 265 "/home/alois/Documents/bah-bah/src/parser.bah"

                struct string ____BAH_COMPILER_VAR_596 = string(compilerState.currentFile);
                if ((isBahDir==true)||(string__hasPrefix(&____BAH_COMPILER_VAR_596,oDir)==false)) {

#line 266 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((isImportedSubObject==true)&&(isBahDir==false)) {

#line 267 "/home/alois/Documents/bah-bah/src/parser.bah"
shouldOnlyDecl = true;
}

#line 268 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 269 "/home/alois/Documents/bah-bah/src/parser.bah"
shouldOnlyDecl = false;
}
}

#line 271 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 272 "/home/alois/Documents/bah-bah/src/parser.bah"
shouldOnlyDecl = true;
}
}

#line 276 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((needDisableRCP==true)) {

#line 277 "/home/alois/Documents/bah-bah/src/parser.bah"
RCPenabled = false;
}

#line 280 "/home/alois/Documents/bah-bah/src/parser.bah"
parseLines(tokens,elems);

#line 282 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((needDisableRCP==true)) {

#line 283 "/home/alois/Documents/bah-bah/src/parser.bah"
RCPenabled = true;
}

#line 287 "/home/alois/Documents/bah-bah/src/parser.bah"
shouldOnlyDecl = oshd;

#line 288 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.currentFile = oFile;

#line 289 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.currentDir = oDir;

#line 291 "/home/alois/Documents/bah-bah/src/parser.bah"
return true;
};

#line 294 "/home/alois/Documents/bah-bah/src/parser.bah"
void parallelObjCompile(char * fn,char * oName,struct channel * done){

#line 295 "/home/alois/Documents/bah-bah/src/parser.bah"
readCache();

#line 296 "/home/alois/Documents/bah-bah/src/parser.bah"
struct cacheFile* cf = getCacheFile(fn);

#line 297 "/home/alois/Documents/bah-bah/src/parser.bah"
char * wrkd = getCurrentPath();

#line 299 "/home/alois/Documents/bah-bah/src/parser.bah"
char * rcp = "\0\0\0\0""";

#line 300 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((RCPlevel==1)) {

#line 301 "/home/alois/Documents/bah-bah/src/parser.bah"
rcp = "\04\0\0\0""-rcp";
}

#line 302 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((RCPlevel==2)) {

#line 303 "/home/alois/Documents/bah-bah/src/parser.bah"
rcp = "\010\0\0\0""-fastrcp";
}

#line 306 "/home/alois/Documents/bah-bah/src/parser.bah"
struct cacheFile* scf = cf;

#line 307 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((scf==null)) {

#line 308 "/home/alois/Documents/bah-bah/src/parser.bah"
struct cacheFile* ____BAH_COMPILER_VAR_597 = memoryAlloc(sizeof(struct cacheFile));
____BAH_COMPILER_VAR_597->files = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_597->files->length = 0;
            ____BAH_COMPILER_VAR_597->files->elemSize = sizeof(char *);
            scf = ____BAH_COMPILER_VAR_597;
}

#line 312 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((cf==null)||(isValidCacheFile(scf)==false)) {

#line 313 "/home/alois/Documents/bah-bah/src/parser.bah"
setCurrentPath(compilerState.currentDir);

#line 314 "/home/alois/Documents/bah-bah/src/parser.bah"
char * verboseCC = "\0\0\0\0""";

#line 315 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((flags__isSet(&flags,"\011\0\0\0""verboseCC")==1)) {

#line 316 "/home/alois/Documents/bah-bah/src/parser.bah"
verboseCC = "\012\0\0\0""-verboseCC";
}

#line 318 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((debug==false)) {

#line 319 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_598 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_598[1] = fn;____BAH_COMPILER_VAR_598[0] = "\014\0\0\0""[compiling] ";char * ____BAH_COMPILER_VAR_599 =__Bah_multiple_concat(____BAH_COMPILER_VAR_598, 2);println(____BAH_COMPILER_VAR_599);
}

#line 321 "/home/alois/Documents/bah-bah/src/parser.bah"
char * opti = "\0\0\0\0""";

#line 322 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((isOptimized==true)) {

#line 323 "/home/alois/Documents/bah-bah/src/parser.bah"
opti = "\011\0\0\0""-optimize";
}

#line 325 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_600 = alloca(11 * sizeof(char*));____BAH_COMPILER_VAR_600[10] = oName;____BAH_COMPILER_VAR_600[9] = "\04\0\0\0"" -o ";____BAH_COMPILER_VAR_600[8] = verboseCC;____BAH_COMPILER_VAR_600[7] = "\011\0\0\0"" -object ";____BAH_COMPILER_VAR_600[6] = opti;____BAH_COMPILER_VAR_600[5] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_600[4] = rcp;____BAH_COMPILER_VAR_600[3] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_600[2] = fn;____BAH_COMPILER_VAR_600[1] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_600[0] = execName;char * ____BAH_COMPILER_VAR_601 =__Bah_multiple_concat(____BAH_COMPILER_VAR_600, 11);struct command cmd = command(____BAH_COMPILER_VAR_601);

#line 326 "/home/alois/Documents/bah-bah/src/parser.bah"
array(char)* res = command__runBytes(&cmd);

#line 327 "/home/alois/Documents/bah-bah/src/parser.bah"
setCurrentPath(wrkd);

#line 328 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((cmd.status!=0), 0)) {

#line 329 "/home/alois/Documents/bah-bah/src/parser.bah"
print(arrToStr(res));

#line 330 "/home/alois/Documents/bah-bah/src/parser.bah"
exit(1);
}

#line 332 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((cf==null)) {

#line 333 "/home/alois/Documents/bah-bah/src/parser.bah"
makeCacheFile(fn);
}

#line 334 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 335 "/home/alois/Documents/bah-bah/src/parser.bah"
updateCacheFile(cf);
}

#line 337 "/home/alois/Documents/bah-bah/src/parser.bah"
writeCache();
}

#line 339 "/home/alois/Documents/bah-bah/src/parser.bah"

        char ____BAH_COMPILER_VAR_602 = true;
        channel__sendAny(done, &____BAH_COMPILER_VAR_602, sizeof(____BAH_COMPILER_VAR_602));
        };

#line 342 "/home/alois/Documents/bah-bah/src/parser.bah"
char ____BAH_COMPILER_VAR_603(array(char *)* arr, char * el) {
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

#line 343 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.hasImports = true;

#line 345 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((len(l)!=2), 0)) {

#line 346 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&l->data[0],"\031\0\0\0""Invalid usage of {TOKEN}.");
}

#line 348 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok strt = l->data[1];

#line 349 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((strt.type!=TOKEN_TYPE_STR), 0)) {

#line 350 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&strt,"\060\0\0\0""Cannot use {TOKEN} as file name (#import \"file\")");
}

#line 354 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string fileName = string(strt.cont);

#line 355 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimLeft(&fileName,1);

#line 356 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimRight(&fileName,1);

#line 359 "/home/alois/Documents/bah-bah/src/parser.bah"
if (____BAH_COMPILER_VAR_603(compilerState.includes, string__str(&fileName))) {

#line 360 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}

#line 362 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_604 = len(compilerState.includes);
    __Bah_realocate_arr(compilerState.includes, ____BAH_COMPILER_VAR_604);
    compilerState.includes->data[____BAH_COMPILER_VAR_604] = string__str(&fileName);

#line 365 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_605 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_605[1] = string__str(&fileName);____BAH_COMPILER_VAR_605[0] = compilerState.currentDir;char * ____BAH_COMPILER_VAR_606 =__Bah_multiple_concat(____BAH_COMPILER_VAR_605, 2);char * fn = absPath(____BAH_COMPILER_VAR_606);

#line 366 "/home/alois/Documents/bah-bah/src/parser.bah"
if (((void *)fn==null)) {

#line 367 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_607 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_607[1] = string__str(&fileName);____BAH_COMPILER_VAR_607[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_608 =__Bah_multiple_concat(____BAH_COMPILER_VAR_607, 2);fn = absPath(____BAH_COMPILER_VAR_608);

#line 368 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect(((void *)fn==null), 0)) {

#line 369 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&strt,"\025\0\0\0""Unknown file {TOKEN}.");
}
}

#line 374 "/home/alois/Documents/bah-bah/src/parser.bah"
char * of = compilerState.currentFile;

#line 375 "/home/alois/Documents/bah-bah/src/parser.bah"
char * od = compilerState.currentDir;

#line 376 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.currentFile = fn;

#line 377 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.currentDir = getDirFromFile(fn);

#line 380 "/home/alois/Documents/bah-bah/src/parser.bah"
struct fileStream ____BAH_COMPILER_VAR_609 = {};
struct fileStream fs = ____BAH_COMPILER_VAR_609;

#line 381 "/home/alois/Documents/bah-bah/src/parser.bah"
fileStream__open(&fs,fn,"\01\0\0\0""r");

#line 382 "/home/alois/Documents/bah-bah/src/parser.bah"
char * f = fileStream__readContent(&fs);

#line 385 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct Tok)* tokens = lexer(f,fileStream__getSize(&fs));

#line 386 "/home/alois/Documents/bah-bah/src/parser.bah"
fileStream__close(&fs);

#line 389 "/home/alois/Documents/bah-bah/src/parser.bah"
char osod = shouldOnlyDecl;

#line 390 "/home/alois/Documents/bah-bah/src/parser.bah"
char oiso = isSubObject;

#line 391 "/home/alois/Documents/bah-bah/src/parser.bah"
char oiiso = isImportedSubObject;

#line 393 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((isSubObject==true)) {

#line 394 "/home/alois/Documents/bah-bah/src/parser.bah"
isImportedSubObject = true;
}

#line 397 "/home/alois/Documents/bah-bah/src/parser.bah"
shouldOnlyDecl = true;

#line 398 "/home/alois/Documents/bah-bah/src/parser.bah"
isSubObject = true;

#line 400 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_610 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_610[5] = "\02\0\0\0"".o";____BAH_COMPILER_VAR_610[4] = intToStr(isOptimized);____BAH_COMPILER_VAR_610[3] = intToStr(RCPlevel);____BAH_COMPILER_VAR_610[2] = pathToVarName(fn);____BAH_COMPILER_VAR_610[1] = "\06\0\0\0""cache/";____BAH_COMPILER_VAR_610[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_611 =__Bah_multiple_concat(____BAH_COMPILER_VAR_610, 6);char * oName = ____BAH_COMPILER_VAR_611;

#line 402 "/home/alois/Documents/bah-bah/src/parser.bah"
unsigned long int i = len(compilerState.cLibs);

#line 402 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i!=0); 
#line 402 "/home/alois/Documents/bah-bah/src/parser.bah"
--i) {

#line 403 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_612 = i;
    __Bah_realocate_arr(compilerState.cLibs, ____BAH_COMPILER_VAR_612);
    compilerState.cLibs->data[____BAH_COMPILER_VAR_612] = compilerState.cLibs->data[i-1];
};

#line 406 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_613 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_613[2] = "\02\0\0\0"".o";____BAH_COMPILER_VAR_613[1] = oName;____BAH_COMPILER_VAR_613[0] = "\02\0\0\0""w ";char * ____BAH_COMPILER_VAR_614 =__Bah_multiple_concat(____BAH_COMPILER_VAR_613, 3);
    unsigned int ____BAH_COMPILER_VAR_615 = 0;
    __Bah_realocate_arr(compilerState.cLibs, ____BAH_COMPILER_VAR_615);
    compilerState.cLibs->data[____BAH_COMPILER_VAR_615] = ____BAH_COMPILER_VAR_614;

#line 408 "/home/alois/Documents/bah-bah/src/parser.bah"
struct channel * done = channel();

#line 411 "/home/alois/Documents/bah-bah/src/parser.bah"
parallelObjCompile(fn,oName,done);

#line 414 "/home/alois/Documents/bah-bah/src/parser.bah"
parseLines(tokens,elems);

#line 416 "/home/alois/Documents/bah-bah/src/parser.bah"
char ok = *(char*)channel__receive(done);

#line 419 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_616 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_616[2] = "\04\0\0\0""();\n";____BAH_COMPILER_VAR_616[1] = pathToVarName(fn);____BAH_COMPILER_VAR_616[0] = "\012\0\0\0""__BAH_init";char * ____BAH_COMPILER_VAR_617 =__Bah_multiple_concat(____BAH_COMPILER_VAR_616, 3);INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_617));

#line 422 "/home/alois/Documents/bah-bah/src/parser.bah"
shouldOnlyDecl = osod;

#line 423 "/home/alois/Documents/bah-bah/src/parser.bah"
isSubObject = oiso;

#line 424 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.currentFile = of;

#line 425 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.currentDir = od;

#line 426 "/home/alois/Documents/bah-bah/src/parser.bah"
isImportedSubObject = oiiso;
};

#line 429 "/home/alois/Documents/bah-bah/src/parser.bah"
void parseInclude(__BAH_ARR_TYPE_Tok l,struct Elems* elems){

#line 431 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((len(l)!=2)&&(len(l)!=3), 0)) {

#line 432 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&l->data[len(l)-1],"\054\0\0\0""Invalid usage of include, ending by {TOKEN}.");
}

#line 434 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok strt = l->data[1];

#line 435 "/home/alois/Documents/bah-bah/src/parser.bah"
char isSupressed = false;

#line 436 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(strt.cont, "\01\0\0\0""!") == 0)&&(len(l)>2)) {

#line 437 "/home/alois/Documents/bah-bah/src/parser.bah"
isSupressed = true;

#line 438 "/home/alois/Documents/bah-bah/src/parser.bah"
strt = l->data[2];
}

#line 440 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((strt.type!=TOKEN_TYPE_STR), 0)) {

#line 441 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&strt,"\050\0\0\0""Cannot use {TOKEN} as string in include.");
}

#line 445 "/home/alois/Documents/bah-bah/src/parser.bah"
char * sc = strt.cont;

#line 446 "/home/alois/Documents/bah-bah/src/parser.bah"
strTrimLeft(&sc,1);

#line 447 "/home/alois/Documents/bah-bah/src/parser.bah"
strTrimRight(&sc,1);

#line 448 "/home/alois/Documents/bah-bah/src/parser.bah"
if (strHasPrefix(sc,"\01\0\0\0""<")||strHasSuffix(sc,"\02\0\0\0"".h")||strHasSuffix(sc,"\02\0\0\0"".c")) {

#line 449 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((isSubObject==false)||(isSupressed==false)) {

#line 450 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_618 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_618[2] = "\01\0\0\0""\n";____BAH_COMPILER_VAR_618[1] = sc;____BAH_COMPILER_VAR_618[0] = "\011\0\0\0""#include ";char * ____BAH_COMPILER_VAR_619 =__Bah_multiple_concat(____BAH_COMPILER_VAR_618, 3);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_619));

#line 451 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_620 = len(compilerState.cIncludes);
    __Bah_realocate_arr(compilerState.cIncludes, ____BAH_COMPILER_VAR_620);
    compilerState.cIncludes->data[____BAH_COMPILER_VAR_620] = sc;
}
}

#line 453 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 454 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((includeFile(sc,elems)==false), 0)) {

#line 455 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&strt,"\034\0\0\0""Could not find file {TOKEN}.");
}
}
};

#line 460 "/home/alois/Documents/bah-bah/src/parser.bah"
array(char *)* signs;
__BAH_ARR_TYPE_Tok prePross(__BAH_ARR_TYPE_Tok line,lineType ltp,struct Elems* elems);

#line 466 "/home/alois/Documents/bah-bah/src/parser.bah"
__BAH_ARR_TYPE_Tok parseStructType(__BAH_ARR_TYPE_Tok line,lineType ltp,struct Elems* elems){

#line 469 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((ltp==LINE_TYPE_VAR)) {

#line 470 "/home/alois/Documents/bah-bah/src/parser.bah"
return line;
}

#line 473 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);

#line 474 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int i = 0;

#line 474 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i<len(line))) {

#line 475 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = line->data[i];

#line 476 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((t.type==TOKEN_TYPE_VAR)) {

#line 478 "/home/alois/Documents/bah-bah/src/parser.bah"
if (strHasPrefix(t.bahType,"\02\0\0\0""[]")) {

#line 479 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_621 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_621);
    nl->data[____BAH_COMPILER_VAR_621] = t;

#line 480 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 481 "/home/alois/Documents/bah-bah/src/parser.bah"
continue;
}

#line 483 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 484 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok ____BAH_COMPILER_VAR_622 = {};
____BAH_COMPILER_VAR_622.cont = "\0\0\0\0""";
____BAH_COMPILER_VAR_622.ogCont = "\0\0\0\0""";
____BAH_COMPILER_VAR_622.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_622.line = 1;
____BAH_COMPILER_VAR_622.begLine = 1;
____BAH_COMPILER_VAR_622.bahType = "\0\0\0\0""";
____BAH_COMPILER_VAR_622.cont = "\0\0\0\0""";
struct Tok nt = ____BAH_COMPILER_VAR_622;

#line 487 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((i<len(line))) {

#line 488 "/home/alois/Documents/bah-bah/src/parser.bah"
nt = line->data[i];
}

#line 490 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((i==len(line))||(strcmp(nt.cont, "\01\0\0\0""{") != 0)) {

#line 491 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((i-2>=0)) {

#line 492 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok newTk = line->data[i-2];

#line 494 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(newTk.cont, "\03\0\0\0""new") == 0)) {

#line 495 "/home/alois/Documents/bah-bah/src/parser.bah"
struct cStruct* s = searchStruct(t.cont,elems);

#line 496 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((s==null), 0)) {

#line 497 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"\055\0\0\0""Cannot initialize new unknown struct {TOKEN}.");
}

#line 499 "/home/alois/Documents/bah-bah/src/parser.bah"
t.cont = genCompilerVar();

#line 500 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* ____BAH_COMPILER_VAR_623 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_623->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_623->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_623->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_623->from = "\0\0\0\0""";
struct variable* tmpV = ____BAH_COMPILER_VAR_623;

#line 501 "/home/alois/Documents/bah-bah/src/parser.bah"
tmpV->name = t.cont;

#line 502 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_624 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_624[1] = "\01\0\0\0""*";____BAH_COMPILER_VAR_624[0] = s->name;char * ____BAH_COMPILER_VAR_625 =__Bah_multiple_concat(____BAH_COMPILER_VAR_624, 2);tmpV->type = ____BAH_COMPILER_VAR_625;

#line 503 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string cType = getCType(tmpV->type,elems);

#line 504 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string structType = getCType(s->name,elems);

#line 505 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_626 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_626);
    elems->vars->data[____BAH_COMPILER_VAR_626] = tmpV;

#line 507 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_627 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_627[6] = declareStructMethods(tmpV,s,elems);____BAH_COMPILER_VAR_627[5] = "\04\0\0\0""));\n";____BAH_COMPILER_VAR_627[4] = string__str(&structType);____BAH_COMPILER_VAR_627[3] = "\026\0\0\0"" = memoryAlloc(sizeof(";____BAH_COMPILER_VAR_627[2] = t.cont;____BAH_COMPILER_VAR_627[1] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_627[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_628 =__Bah_multiple_concat(____BAH_COMPILER_VAR_627, 7);struct rope* r = rope(____BAH_COMPILER_VAR_628);

#line 509 "/home/alois/Documents/bah-bah/src/parser.bah"
if (isGlobal()) {

#line 510 "/home/alois/Documents/bah-bah/src/parser.bah"
INIT = rope__add(INIT, r);
}

#line 511 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 512 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope__add(OUTPUT, r);
}

#line 515 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_629 = len(nl)-1;
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_629);
    nl->data[____BAH_COMPILER_VAR_629] = t;

#line 516 "/home/alois/Documents/bah-bah/src/parser.bah"
continue;
}
}
}

#line 521 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((i<len(line))) {

#line 522 "/home/alois/Documents/bah-bah/src/parser.bah"
nt = line->data[i];

#line 523 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(nt.cont, "\01\0\0\0""{") == 0)) {

#line 524 "/home/alois/Documents/bah-bah/src/parser.bah"
char isHeap = false;

#line 525 "/home/alois/Documents/bah-bah/src/parser.bah"
char * sep = "\01\0\0\0"".";

#line 526 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((i-2>=0)) {

#line 527 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok newTk = line->data[i-2];

#line 528 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(newTk.cont, "\03\0\0\0""new") == 0)) {

#line 529 "/home/alois/Documents/bah-bah/src/parser.bah"
isHeap = true;

#line 530 "/home/alois/Documents/bah-bah/src/parser.bah"
sep = "\02\0\0\0""->";
}
}

#line 533 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 534 "/home/alois/Documents/bah-bah/src/parser.bah"
struct cStruct* s = searchStruct(t.cont,elems);

#line 535 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((s==null), 0)) {

#line 536 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"\034\0\0\0""Unknown struct name {TOKEN}.");
}

#line 539 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);

#line 540 "/home/alois/Documents/bah-bah/src/parser.bah"
long int nbBraces = 1;

#line 541 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<len(line)); 
#line 541 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 542 "/home/alois/Documents/bah-bah/src/parser.bah"
t = line->data[i];

#line 543 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "\01\0\0\0""{") == 0)) {

#line 544 "/home/alois/Documents/bah-bah/src/parser.bah"
++nbBraces;
}

#line 545 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(t.cont, "\01\0\0\0""}") == 0)) {

#line 546 "/home/alois/Documents/bah-bah/src/parser.bah"
--nbBraces;

#line 547 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((nbBraces==0)) {

#line 548 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}
}

#line 551 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_630 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_630);
    memory->data[____BAH_COMPILER_VAR_630] = t;
};

#line 555 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((len(memory)>0)) {

#line 556 "/home/alois/Documents/bah-bah/src/parser.bah"
memory = prePross(memory,(lineType)-1,elems);
}

#line 560 "/home/alois/Documents/bah-bah/src/parser.bah"
long int declType = 0;

#line 562 "/home/alois/Documents/bah-bah/src/parser.bah"
char * rvn = genCompilerVar();

#line 563 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* ____BAH_COMPILER_VAR_631 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_631->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_631->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_631->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_631->from = "\0\0\0\0""";
struct variable* tmpV = ____BAH_COMPILER_VAR_631;

#line 564 "/home/alois/Documents/bah-bah/src/parser.bah"
tmpV->name = rvn;

#line 565 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((isHeap==true)) {

#line 566 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_632 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_632[1] = "\01\0\0\0""*";____BAH_COMPILER_VAR_632[0] = s->name;char * ____BAH_COMPILER_VAR_633 =__Bah_multiple_concat(____BAH_COMPILER_VAR_632, 2);tmpV->type = ____BAH_COMPILER_VAR_633;

#line 567 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_634 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_634);
    elems->vars->data[____BAH_COMPILER_VAR_634] = tmpV;
}

#line 568 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 569 "/home/alois/Documents/bah-bah/src/parser.bah"
tmpV->type = s->name;
}

#line 571 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string rst = getCType(tmpV->type,elems);

#line 572 "/home/alois/Documents/bah-bah/src/parser.bah"
struct rope* r= null;

#line 575 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((isHeap==true)) {

#line 576 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string structType = string(string__str(&rst));

#line 577 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimRight(&structType,1);

#line 578 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_635 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_635[6] = declareStructMethods(tmpV,s,elems);____BAH_COMPILER_VAR_635[5] = "\04\0\0\0""));\n";____BAH_COMPILER_VAR_635[4] = string__str(&structType);____BAH_COMPILER_VAR_635[3] = "\026\0\0\0"" = memoryAlloc(sizeof(";____BAH_COMPILER_VAR_635[2] = rvn;____BAH_COMPILER_VAR_635[1] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_635[0] = string__str(&rst);char * ____BAH_COMPILER_VAR_636 =__Bah_multiple_concat(____BAH_COMPILER_VAR_635, 7);r = rope(____BAH_COMPILER_VAR_636);
}

#line 579 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 580 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_637 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_637[4] = declareStructMethods(tmpV,s,elems);____BAH_COMPILER_VAR_637[3] = "\07\0\0\0"" = {};\n";____BAH_COMPILER_VAR_637[2] = rvn;____BAH_COMPILER_VAR_637[1] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_637[0] = string__str(&rst);char * ____BAH_COMPILER_VAR_638 =__Bah_multiple_concat(____BAH_COMPILER_VAR_637, 5);r = rope(____BAH_COMPILER_VAR_638);
}

#line 582 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int j = 0;

#line 582 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int k = 0;

#line 582 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((k<len(memory))) {

#line 583 "/home/alois/Documents/bah-bah/src/parser.bah"
t = memory->data[k];

#line 585 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((k+2<len(memory))) {

#line 586 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok st = memory->data[k+1];

#line 587 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok vl = memory->data[k+2];

#line 588 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(st.cont, "\01\0\0\0"":") == 0)) {

#line 589 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((declType!=0)&&(declType!=1), 0)) {

#line 590 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"\072\0\0\0""Cannot declare member {TOKEN} by name in list declaration.");
}

#line 592 "/home/alois/Documents/bah-bah/src/parser.bah"
declType = 1;

#line 593 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((t.type!=TOKEN_TYPE_VAR), 0)) {

#line 594 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"\051\0\0\0""Cannot use {TOKEN} as struct member name.");
}

#line 596 "/home/alois/Documents/bah-bah/src/parser.bah"
j = 0;

#line 596 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((j<len(s->members))) {

#line 597 "/home/alois/Documents/bah-bah/src/parser.bah"
struct structMemb* m = s->members->data[j];

#line 598 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(m->name, t.cont) != 0)) {

#line 599 "/home/alois/Documents/bah-bah/src/parser.bah"
j = j+1;

#line 600 "/home/alois/Documents/bah-bah/src/parser.bah"
continue;
}

#line 602 "/home/alois/Documents/bah-bah/src/parser.bah"
char * vlt = getTypeFromToken(&vl,true,elems);

#line 603 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((compTypes(vlt,m->type)==false), 0)) {

#line 604 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_639 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_639[4] = "\02\0\0\0""'.";____BAH_COMPILER_VAR_639[3] = m->type;____BAH_COMPILER_VAR_639[2] = "\06\0\0\0"") as '";____BAH_COMPILER_VAR_639[1] = vlt;____BAH_COMPILER_VAR_639[0] = "\024\0\0\0""Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_640 =__Bah_multiple_concat(____BAH_COMPILER_VAR_639, 5);throwErr(&vl,____BAH_COMPILER_VAR_640);
}

#line 606 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_641 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_641[5] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_641[4] = vl.cont;____BAH_COMPILER_VAR_641[3] = "\03\0\0\0"" = ";____BAH_COMPILER_VAR_641[2] = m->name;____BAH_COMPILER_VAR_641[1] = sep;____BAH_COMPILER_VAR_641[0] = rvn;char * ____BAH_COMPILER_VAR_642 =__Bah_multiple_concat(____BAH_COMPILER_VAR_641, 6);r = rope__add(r, rope(____BAH_COMPILER_VAR_642));

#line 607 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
};

#line 609 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((j==len(s->members)), 0)) {

#line 610 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_643 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_643[2] = "\037\0\0\0""' has no member called {TOKEN}.";____BAH_COMPILER_VAR_643[1] = s->name;____BAH_COMPILER_VAR_643[0] = "\010\0\0\0""Struct '";char * ____BAH_COMPILER_VAR_644 =__Bah_multiple_concat(____BAH_COMPILER_VAR_643, 3);throwErr(&t,____BAH_COMPILER_VAR_644);
}

#line 612 "/home/alois/Documents/bah-bah/src/parser.bah"
k = k+3;

#line 613 "/home/alois/Documents/bah-bah/src/parser.bah"
continue;
}
}

#line 616 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((declType!=0)&&(declType!=2), 0)) {

#line 617 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"\072\0\0\0""Cannot declare member {TOKEN} without specifying its name.");
}

#line 620 "/home/alois/Documents/bah-bah/src/parser.bah"
declType = 2;

#line 621 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((j>len(s->members)), 0)) {

#line 622 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"\031\0\0\0""Too many members {TOKEN}.");
}

#line 624 "/home/alois/Documents/bah-bah/src/parser.bah"
struct structMemb* m = s->members->data[j];

#line 625 "/home/alois/Documents/bah-bah/src/parser.bah"
++j;

#line 627 "/home/alois/Documents/bah-bah/src/parser.bah"
char * tt = getTypeFromToken(&t,true,elems);

#line 628 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((compTypes(tt,m->type)==false), 0)) {

#line 629 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_645 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_645[4] = "\02\0\0\0""'.";____BAH_COMPILER_VAR_645[3] = m->type;____BAH_COMPILER_VAR_645[2] = "\06\0\0\0"") as '";____BAH_COMPILER_VAR_645[1] = tt;____BAH_COMPILER_VAR_645[0] = "\024\0\0\0""Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_646 =__Bah_multiple_concat(____BAH_COMPILER_VAR_645, 5);throwErr(&t,____BAH_COMPILER_VAR_646);
}

#line 632 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_647 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_647[5] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_647[4] = t.cont;____BAH_COMPILER_VAR_647[3] = "\03\0\0\0"" = ";____BAH_COMPILER_VAR_647[2] = m->name;____BAH_COMPILER_VAR_647[1] = sep;____BAH_COMPILER_VAR_647[0] = rvn;char * ____BAH_COMPILER_VAR_648 =__Bah_multiple_concat(____BAH_COMPILER_VAR_647, 6);r = rope__add(r, rope(____BAH_COMPILER_VAR_648));

#line 634 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((k+1<len(memory))) {

#line 635 "/home/alois/Documents/bah-bah/src/parser.bah"
++k;

#line 636 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok st = memory->data[k];

#line 637 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((strcmp(st.cont, "\01\0\0\0"",") != 0), 0)) {

#line 638 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&st,"\063\0\0\0""Need ',' separator between two values, not {TOKEN}.");
}
}

#line 641 "/home/alois/Documents/bah-bah/src/parser.bah"
++k;
};

#line 645 "/home/alois/Documents/bah-bah/src/parser.bah"
if (isGlobal()) {

#line 646 "/home/alois/Documents/bah-bah/src/parser.bah"
INIT = rope__add(INIT, r);
}

#line 647 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 648 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope__add(OUTPUT, r);
}

#line 652 "/home/alois/Documents/bah-bah/src/parser.bah"
t.bahType = tmpV->type;

#line 653 "/home/alois/Documents/bah-bah/src/parser.bah"
t.cont = rvn;

#line 654 "/home/alois/Documents/bah-bah/src/parser.bah"
t.isValue = true;

#line 655 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((isHeap==true)) {

#line 656 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_649 = len(nl)-1;
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_649);
    nl->data[____BAH_COMPILER_VAR_649] = t;
}

#line 657 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 658 "/home/alois/Documents/bah-bah/src/parser.bah"
t.isEqual = true;

#line 659 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_650 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_650);
    nl->data[____BAH_COMPILER_VAR_650] = t;
}

#line 661 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 662 "/home/alois/Documents/bah-bah/src/parser.bah"
continue;
}

#line 664 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 665 "/home/alois/Documents/bah-bah/src/parser.bah"
--i;
}
}
}

#line 669 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_651 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_651);
    nl->data[____BAH_COMPILER_VAR_651] = t;

#line 670 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;
};

#line 673 "/home/alois/Documents/bah-bah/src/parser.bah"
return nl;
};

#line 676 "/home/alois/Documents/bah-bah/src/parser.bah"
__BAH_ARR_TYPE_Tok parseArrayType(__BAH_ARR_TYPE_Tok line,struct Elems* elems,char guard){

#line 679 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int i = 0;

#line 679 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((guard==true)) {

#line 680 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<len(line)); 
#line 680 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 681 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = line->data[i];

#line 682 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "\01\0\0\0""[") == 0)) {

#line 683 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}
};

#line 686 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((i==len(line))) {

#line 687 "/home/alois/Documents/bah-bah/src/parser.bah"
return line;
}
}

#line 690 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct Tok)* nl = arraySubstitute(line, 0, i);

#line 692 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<len(line)); 
#line 692 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 693 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = line->data[i];

#line 694 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "\01\0\0\0""[") == 0)) {

#line 695 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 696 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((i<len(line))) {

#line 697 "/home/alois/Documents/bah-bah/src/parser.bah"
t = line->data[i];

#line 698 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "\01\0\0\0""]") == 0)) {

#line 699 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 700 "/home/alois/Documents/bah-bah/src/parser.bah"
long int depth = 1;

#line 701 "/home/alois/Documents/bah-bah/src/parser.bah"
char * bracks = "\02\0\0\0""[]";

#line 702 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<len(line)-1); 
#line 702 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 703 "/home/alois/Documents/bah-bah/src/parser.bah"
t = line->data[i];

#line 704 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok nt = line->data[i+1];

#line 705 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "\01\0\0\0""[") == 0)&&(strcmp(nt.cont, "\01\0\0\0""]") == 0)) {

#line 706 "/home/alois/Documents/bah-bah/src/parser.bah"
++depth;

#line 707 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_652 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_652[1] = "\02\0\0\0""[]";____BAH_COMPILER_VAR_652[0] = bracks;char * ____BAH_COMPILER_VAR_653 =__Bah_multiple_concat(____BAH_COMPILER_VAR_652, 2);bracks = ____BAH_COMPILER_VAR_653;

#line 708 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;
}

#line 709 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 710 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}
};

#line 713 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((i<len(line))) {

#line 714 "/home/alois/Documents/bah-bah/src/parser.bah"
t = line->data[i];

#line 715 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((t.type!=TOKEN_TYPE_VAR), 0)) {

#line 716 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"\041\0\0\0""Cannot use {TOKEN} as array type.");
}

#line 718 "/home/alois/Documents/bah-bah/src/parser.bah"
char * arrElem = t.cont;

#line 719 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_654 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_654[1] = arrElem;____BAH_COMPILER_VAR_654[0] = bracks;char * ____BAH_COMPILER_VAR_655 =__Bah_multiple_concat(____BAH_COMPILER_VAR_654, 2);t.bahType = ____BAH_COMPILER_VAR_655;

#line 720 "/home/alois/Documents/bah-bah/src/parser.bah"
t.cont = "\0\0\0\0""";

#line 721 "/home/alois/Documents/bah-bah/src/parser.bah"
t.isValue = true;

#line 722 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_656 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_656);
    nl->data[____BAH_COMPILER_VAR_656] = t;

#line 723 "/home/alois/Documents/bah-bah/src/parser.bah"
continue;
}
}

#line 725 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 726 "/home/alois/Documents/bah-bah/src/parser.bah"
--i;

#line 727 "/home/alois/Documents/bah-bah/src/parser.bah"
t = line->data[i];
}
}

#line 729 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 730 "/home/alois/Documents/bah-bah/src/parser.bah"
--i;
}
}

#line 734 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_657 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_657);
    nl->data[____BAH_COMPILER_VAR_657] = t;
};

#line 737 "/home/alois/Documents/bah-bah/src/parser.bah"
return nl;
};

#line 740 "/home/alois/Documents/bah-bah/src/parser.bah"
array(char *)* comparators;

#line 741 "/home/alois/Documents/bah-bah/src/parser.bah"
array(char *)* compSep;

#line 744 "/home/alois/Documents/bah-bah/src/parser.bah"
__BAH_ARR_TYPE_Tok parsePointers(__BAH_ARR_TYPE_Tok l,struct Elems* elems){

#line 745 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int i = 0;

#line 745 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<len(l)); 
#line 745 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 746 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = l->data[i];

#line 747 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "\01\0\0\0""&") == 0)||(strcmp(t.cont, "\01\0\0\0""*") == 0)) {

#line 748 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((i>0)) {

#line 749 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((l->data[i-1].type==TOKEN_TYPE_VAR)||(l->data[i-1].isValue==true)) {

#line 750 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "\01\0\0\0""*") == 0)) {

#line 751 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((i+1<len(l))) {

#line 752 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(l->data[i+1].cont, "\01\0\0\0""(") != 0)&&(l->data[i+1].type!=TOKEN_TYPE_CAST)&&(l->data[i+1].isValue!=true)) {

#line 753 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_658 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_658[1] = t.cont;____BAH_COMPILER_VAR_658[0] = l->data[i-1].cont;char * ____BAH_COMPILER_VAR_659 =__Bah_multiple_concat(____BAH_COMPILER_VAR_658, 2);l->data[i-1].cont = ____BAH_COMPILER_VAR_659;

#line 754 "/home/alois/Documents/bah-bah/src/parser.bah"
delete(l,i);

#line 755 "/home/alois/Documents/bah-bah/src/parser.bah"
--i;
}
}

#line 757 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 758 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_660 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_660[1] = t.cont;____BAH_COMPILER_VAR_660[0] = l->data[i-1].cont;char * ____BAH_COMPILER_VAR_661 =__Bah_multiple_concat(____BAH_COMPILER_VAR_660, 2);l->data[i-1].cont = ____BAH_COMPILER_VAR_661;

#line 759 "/home/alois/Documents/bah-bah/src/parser.bah"
delete(l,i);

#line 760 "/home/alois/Documents/bah-bah/src/parser.bah"
--i;
}
}

#line 763 "/home/alois/Documents/bah-bah/src/parser.bah"
continue;
}
}

#line 767 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((i+1<len(l))) {

#line 768 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((i>0)) {

#line 769 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(l->data[i-1].cont, "\01\0\0\0"")") == 0)||(l->data[i-1].isValue==true)) {

#line 770 "/home/alois/Documents/bah-bah/src/parser.bah"
continue;
}
}

#line 773 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((l->data[i+1].type==TOKEN_TYPE_VAR)) {

#line 774 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_662 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_662[1] = l->data[i+1].cont;____BAH_COMPILER_VAR_662[0] = t.cont;char * ____BAH_COMPILER_VAR_663 =__Bah_multiple_concat(____BAH_COMPILER_VAR_662, 2);l->data[i+1].cont = ____BAH_COMPILER_VAR_663;

#line 775 "/home/alois/Documents/bah-bah/src/parser.bah"
delete(l,i);

#line 776 "/home/alois/Documents/bah-bah/src/parser.bah"
--i;
}
}
}
};

#line 782 "/home/alois/Documents/bah-bah/src/parser.bah"
return l;
};

#line 786 "/home/alois/Documents/bah-bah/src/parser.bah"
char * parseSerialize(struct Tok* e,struct Elems* elems){

#line 789 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* v = searchVar(e->cont,elems);

#line 790 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((v==null), 0)) {

#line 791 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&e,"\033\0\0\0""Must be a var, not {TOKEN}.");
}

#line 794 "/home/alois/Documents/bah-bah/src/parser.bah"
struct cStruct* s = searchStruct(v->type,elems);

#line 795 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((s==null), 0)) {

#line 796 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&e,"\036\0\0\0""Must be a struct, not {TOKEN}.");
}

#line 799 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string svt = string(v->type);

#line 800 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int ptrLevel = string__count(&svt,"\01\0\0\0""*");

#line 802 "/home/alois/Documents/bah-bah/src/parser.bah"
string__replace(&svt,"\01\0\0\0""*","\0\0\0\0""");

#line 804 "/home/alois/Documents/bah-bah/src/parser.bah"
char * code= null;

#line 806 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((ptrLevel==0)) {

#line 807 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_664 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_664[5] = "\01\0\0\0"")";____BAH_COMPILER_VAR_664[4] = string__str(&svt);____BAH_COMPILER_VAR_664[3] = "\016\0\0\0""sizeof(struct ";____BAH_COMPILER_VAR_664[2] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_664[1] = e->cont;____BAH_COMPILER_VAR_664[0] = "\015\0\0\0""__serialize(&";char * ____BAH_COMPILER_VAR_665 =__Bah_multiple_concat(____BAH_COMPILER_VAR_664, 6);code = ____BAH_COMPILER_VAR_665;
}

#line 808 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 809 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ptrRect = "\0\0\0\0""";

#line 810 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((ptrLevel>1)) {

#line 811 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_666 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_666[1] = "\01\0\0\0""*";____BAH_COMPILER_VAR_666[0] = ptrRect;char * ____BAH_COMPILER_VAR_667 =__Bah_multiple_concat(____BAH_COMPILER_VAR_666, 2);ptrRect = ____BAH_COMPILER_VAR_667;

#line 812 "/home/alois/Documents/bah-bah/src/parser.bah"
ptrLevel = ptrLevel-1;
};

#line 814 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_668 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_668[6] = "\01\0\0\0"")";____BAH_COMPILER_VAR_668[5] = string__str(&svt);____BAH_COMPILER_VAR_668[4] = "\016\0\0\0""sizeof(struct ";____BAH_COMPILER_VAR_668[3] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_668[2] = e->cont;____BAH_COMPILER_VAR_668[1] = ptrRect;____BAH_COMPILER_VAR_668[0] = "\014\0\0\0""__serialize(";char * ____BAH_COMPILER_VAR_669 =__Bah_multiple_concat(____BAH_COMPILER_VAR_668, 7);code = ____BAH_COMPILER_VAR_669;

#line 817 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int i = 0;

#line 817 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i<len(s->members))) {

#line 818 "/home/alois/Documents/bah-bah/src/parser.bah"
struct structMemb* m = s->members->data[i];

#line 819 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(m->type, "\010\0\0\0""cpstring") == 0)) {

#line 820 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_670 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_670[5] = "\01\0\0\0"")";____BAH_COMPILER_VAR_670[4] = m->name;____BAH_COMPILER_VAR_670[3] = "\02\0\0\0""->";____BAH_COMPILER_VAR_670[2] = e->cont;____BAH_COMPILER_VAR_670[1] = "\010\0\0\0""+strlen(";____BAH_COMPILER_VAR_670[0] = code;char * ____BAH_COMPILER_VAR_671 =__Bah_multiple_concat(____BAH_COMPILER_VAR_670, 6);code = ____BAH_COMPILER_VAR_671;
}

#line 822 "/home/alois/Documents/bah-bah/src/parser.bah"
i = i+1;
};
}

#line 828 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_672 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_672[1] = "\01\0\0\0"")";____BAH_COMPILER_VAR_672[0] = code;char * ____BAH_COMPILER_VAR_673 =__Bah_multiple_concat(____BAH_COMPILER_VAR_672, 2);return ____BAH_COMPILER_VAR_673;
};

#line 831 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok parseReflect(struct Tok t,char * tt,struct Elems* elems,char parsedPointer,char * ogName,char * offset){

#line 833 "/home/alois/Documents/bah-bah/src/parser.bah"
char * isArr = "\01\0\0\0""0";

#line 835 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((t.type!=TOKEN_TYPE_VAR)||(t.type!=TOKEN_TYPE_FUNC)) {

#line 836 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string cType;

#line 837 "/home/alois/Documents/bah-bah/src/parser.bah"
if (strHasPrefix(tt,"\011\0\0\0""function(")) {

#line 838 "/home/alois/Documents/bah-bah/src/parser.bah"
cType = string("\05\0\0\0""void*");
}

#line 839 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 840 "/home/alois/Documents/bah-bah/src/parser.bah"
cType = getCType(tt,elems);
}

#line 842 "/home/alois/Documents/bah-bah/src/parser.bah"
char * v = genCompilerVar();

#line 843 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((parsedPointer==true)) {

#line 844 "/home/alois/Documents/bah-bah/src/parser.bah"
string__append(&cType,"\01\0\0\0""*");
}

#line 846 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_674 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_674[5] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_674[4] = t.cont;____BAH_COMPILER_VAR_674[3] = "\03\0\0\0"" = ";____BAH_COMPILER_VAR_674[2] = v;____BAH_COMPILER_VAR_674[1] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_674[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_675 =__Bah_multiple_concat(____BAH_COMPILER_VAR_674, 6);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_675));

#line 847 "/home/alois/Documents/bah-bah/src/parser.bah"
t.cont = v;

#line 848 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((t.type==TOKEN_TYPE_STR)) {

#line 849 "/home/alois/Documents/bah-bah/src/parser.bah"
ogName = "\016\0\0\0""[bah cpstring]";
}
}

#line 853 "/home/alois/Documents/bah-bah/src/parser.bah"
char * arrElem = "\01\0\0\0""0";

#line 854 "/home/alois/Documents/bah-bah/src/parser.bah"
if (strHasPrefix(tt,"\02\0\0\0""[]")) {

#line 855 "/home/alois/Documents/bah-bah/src/parser.bah"
isArr = "\01\0\0\0""1";

#line 856 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string aet = string(tt);

#line 857 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimLeft(&aet,2);

#line 858 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok ____BAH_COMPILER_VAR_676 = {};
____BAH_COMPILER_VAR_676.cont = "\0\0\0\0""";
____BAH_COMPILER_VAR_676.ogCont = "\0\0\0\0""";
____BAH_COMPILER_VAR_676.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_676.line = 1;
____BAH_COMPILER_VAR_676.begLine = 1;
____BAH_COMPILER_VAR_676.bahType = "\0\0\0\0""";
struct Tok tmpT = ____BAH_COMPILER_VAR_676;

#line 859 "/home/alois/Documents/bah-bah/src/parser.bah"
tmpT.type = TOKEN_TYPE_VAR;

#line 860 "/home/alois/Documents/bah-bah/src/parser.bah"
tmpT.cont = "\01\0\0\0""0";

#line 861 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok rt = parseReflect(tmpT,string__str(&aet),elems,true,"\0\0\0\0""","\01\0\0\0""0");

#line 863 "/home/alois/Documents/bah-bah/src/parser.bah"
char * aev = genCompilerVar();

#line 865 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_677 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_677[4] = "\012\0\0\0"";\n        ";____BAH_COMPILER_VAR_677[3] = rt.cont;____BAH_COMPILER_VAR_677[2] = "\03\0\0\0"" = ";____BAH_COMPILER_VAR_677[1] = aev;____BAH_COMPILER_VAR_677[0] = "\037\0\0\0""\n        struct reflectElement ";char * ____BAH_COMPILER_VAR_678 =__Bah_multiple_concat(____BAH_COMPILER_VAR_677, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_678));

#line 869 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_679 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_679[1] = aev;____BAH_COMPILER_VAR_679[0] = "\01\0\0\0""&";char * ____BAH_COMPILER_VAR_680 =__Bah_multiple_concat(____BAH_COMPILER_VAR_679, 2);arrElem = ____BAH_COMPILER_VAR_680;
}

#line 870 "/home/alois/Documents/bah-bah/src/parser.bah"
else if (strHasPrefix(tt,"\04\0\0\0""map:")) {

#line 871 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string aet = string(tt);

#line 872 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimLeft(&aet,4);

#line 873 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok ____BAH_COMPILER_VAR_681 = {};
____BAH_COMPILER_VAR_681.cont = "\0\0\0\0""";
____BAH_COMPILER_VAR_681.ogCont = "\0\0\0\0""";
____BAH_COMPILER_VAR_681.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_681.line = 1;
____BAH_COMPILER_VAR_681.begLine = 1;
____BAH_COMPILER_VAR_681.bahType = "\0\0\0\0""";
struct Tok tmpT = ____BAH_COMPILER_VAR_681;

#line 874 "/home/alois/Documents/bah-bah/src/parser.bah"
tmpT.type = TOKEN_TYPE_VAR;

#line 875 "/home/alois/Documents/bah-bah/src/parser.bah"
tmpT.cont = "\01\0\0\0""0";

#line 876 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok rt = parseReflect(tmpT,string__str(&aet),elems,true,"\0\0\0\0""","\01\0\0\0""0");

#line 877 "/home/alois/Documents/bah-bah/src/parser.bah"
char * aev = genCompilerVar();

#line 878 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_682 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_682[4] = "\012\0\0\0"";\n        ";____BAH_COMPILER_VAR_682[3] = rt.cont;____BAH_COMPILER_VAR_682[2] = "\03\0\0\0"" = ";____BAH_COMPILER_VAR_682[1] = aev;____BAH_COMPILER_VAR_682[0] = "\037\0\0\0""\n        struct reflectElement ";char * ____BAH_COMPILER_VAR_683 =__Bah_multiple_concat(____BAH_COMPILER_VAR_682, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_683));

#line 881 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_684 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_684[1] = aev;____BAH_COMPILER_VAR_684[0] = "\01\0\0\0""&";char * ____BAH_COMPILER_VAR_685 =__Bah_multiple_concat(____BAH_COMPILER_VAR_684, 2);arrElem = ____BAH_COMPILER_VAR_685;
}

#line 884 "/home/alois/Documents/bah-bah/src/parser.bah"
char * isStruct = "\01\0\0\0""0";

#line 885 "/home/alois/Documents/bah-bah/src/parser.bah"
struct cStruct* ts = searchStruct(tt,elems);

#line 886 "/home/alois/Documents/bah-bah/src/parser.bah"
char * structLayout = "\01\0\0\0""0";

#line 888 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((ts!=null)) {

#line 889 "/home/alois/Documents/bah-bah/src/parser.bah"
isStruct = "\01\0\0\0""1";

#line 890 "/home/alois/Documents/bah-bah/src/parser.bah"
structLayout = genCompilerVar();

#line 892 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* ____BAH_COMPILER_VAR_686 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_686->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_686->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_686->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_686->from = "\0\0\0\0""";
struct variable* slv = ____BAH_COMPILER_VAR_686;

#line 893 "/home/alois/Documents/bah-bah/src/parser.bah"
slv->name = structLayout;

#line 894 "/home/alois/Documents/bah-bah/src/parser.bah"
slv->type = "\020\0\0\0""[]reflectElement";

#line 896 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_687 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_687);
    elems->vars->data[____BAH_COMPILER_VAR_687] = slv;

#line 898 "/home/alois/Documents/bah-bah/src/parser.bah"
struct rope* dataLayout = rope("\0\0\0\0""");

#line 900 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int i = 0;

#line 900 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<len(ts->members)); 
#line 900 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 901 "/home/alois/Documents/bah-bah/src/parser.bah"
struct structMemb* m = ts->members->data[i];

#line 902 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(m->type, tt) == 0)) {

#line 903 "/home/alois/Documents/bah-bah/src/parser.bah"
struct structMemb* ____BAH_COMPILER_VAR_688 = memoryAlloc(sizeof(struct structMemb));
____BAH_COMPILER_VAR_688->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_688->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_688->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_688->from = "\0\0\0\0""";
____BAH_COMPILER_VAR_688->def = "\0\0\0\0""";
struct structMemb* nm = ____BAH_COMPILER_VAR_688;

#line 904 "/home/alois/Documents/bah-bah/src/parser.bah"
*nm = *m;

#line 905 "/home/alois/Documents/bah-bah/src/parser.bah"
m = nm;

#line 906 "/home/alois/Documents/bah-bah/src/parser.bah"
m->type = "\03\0\0\0""ptr";
}

#line 908 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok ____BAH_COMPILER_VAR_689 = {};
____BAH_COMPILER_VAR_689.cont = "\0\0\0\0""";
____BAH_COMPILER_VAR_689.ogCont = "\0\0\0\0""";
____BAH_COMPILER_VAR_689.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_689.line = 1;
____BAH_COMPILER_VAR_689.begLine = 1;
____BAH_COMPILER_VAR_689.bahType = "\0\0\0\0""";
struct Tok tmpT = ____BAH_COMPILER_VAR_689;

#line 909 "/home/alois/Documents/bah-bah/src/parser.bah"
tmpT.type = TOKEN_TYPE_VAR;

#line 910 "/home/alois/Documents/bah-bah/src/parser.bah"
char * sep = "\02\0\0\0""->";

#line 911 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strCount(tt,"\01\0\0\0""*")==0)) {

#line 912 "/home/alois/Documents/bah-bah/src/parser.bah"
sep = "\01\0\0\0"".";
}

#line 914 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string mCtype = getCType(m->type,elems);

#line 915 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string offsetTT = string(tt);

#line 916 "/home/alois/Documents/bah-bah/src/parser.bah"
string__replace(&offsetTT,"\01\0\0\0""*","\0\0\0\0""");

#line 917 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_690 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_690[8] = "\02\0\0\0""))";____BAH_COMPILER_VAR_690[7] = m->name;____BAH_COMPILER_VAR_690[6] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_690[5] = string__str(&offsetTT);____BAH_COMPILER_VAR_690[4] = "\024\0\0\0"") + offsetof(struct ";____BAH_COMPILER_VAR_690[3] = t.cont;____BAH_COMPILER_VAR_690[2] = "\013\0\0\0""*)((char*)(";____BAH_COMPILER_VAR_690[1] = string__str(&mCtype);____BAH_COMPILER_VAR_690[0] = "\01\0\0\0""(";char * ____BAH_COMPILER_VAR_691 =__Bah_multiple_concat(____BAH_COMPILER_VAR_690, 9);tmpT.cont = ____BAH_COMPILER_VAR_691;

#line 918 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_692 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_692[4] = "\01\0\0\0"")";____BAH_COMPILER_VAR_692[3] = m->name;____BAH_COMPILER_VAR_692[2] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_692[1] = string__str(&offsetTT);____BAH_COMPILER_VAR_692[0] = "\020\0\0\0""offsetof(struct ";char * ____BAH_COMPILER_VAR_693 =__Bah_multiple_concat(____BAH_COMPILER_VAR_692, 5);struct Tok rt = parseReflect(tmpT,m->type,elems,true,m->name,____BAH_COMPILER_VAR_693);

#line 919 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_694 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_694[5] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_694[4] = rt.cont;____BAH_COMPILER_VAR_694[3] = "\04\0\0\0""] = ";____BAH_COMPILER_VAR_694[2] = intToStr(i);____BAH_COMPILER_VAR_694[1] = "\07\0\0\0""->data[";____BAH_COMPILER_VAR_694[0] = structLayout;char * ____BAH_COMPILER_VAR_695 =__Bah_multiple_concat(____BAH_COMPILER_VAR_694, 6);dataLayout = rope__add(dataLayout, rope(____BAH_COMPILER_VAR_695));
};

#line 922 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_696 = alloca(15 * sizeof(char*));____BAH_COMPILER_VAR_696[14] = "\025\0\0\0""->elemSize);\n        ";____BAH_COMPILER_VAR_696[13] = structLayout;____BAH_COMPILER_VAR_696[12] = "\013\0\0\0""->length * ";____BAH_COMPILER_VAR_696[11] = structLayout;____BAH_COMPILER_VAR_696[10] = "\025\0\0\0""->data = memoryAlloc(";____BAH_COMPILER_VAR_696[9] = structLayout;____BAH_COMPILER_VAR_696[8] = "\012\0\0\0"";\n        ";____BAH_COMPILER_VAR_696[7] = intToStr(len(ts->members));____BAH_COMPILER_VAR_696[6] = "\013\0\0\0""->length = ";____BAH_COMPILER_VAR_696[5] = structLayout;____BAH_COMPILER_VAR_696[4] = "\064\0\0\0""->elemSize = sizeof(struct reflectElement);\n        ";____BAH_COMPILER_VAR_696[3] = structLayout;____BAH_COMPILER_VAR_696[2] = "\076\0\0\0"" = memoryAlloc(sizeof(array(struct reflectElement)));\n        ";____BAH_COMPILER_VAR_696[1] = structLayout;____BAH_COMPILER_VAR_696[0] = "\050\0\0\0""\n        array(struct reflectElement) * ";char * ____BAH_COMPILER_VAR_697 =__Bah_multiple_concat(____BAH_COMPILER_VAR_696, 15);OUTPUT = rope__add(OUTPUT, rope__add(rope(____BAH_COMPILER_VAR_697), dataLayout));
}

#line 930 "/home/alois/Documents/bah-bah/src/parser.bah"
char * amp = "\0\0\0\0""";

#line 931 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strCount(tt,"\01\0\0\0""*")==0)&&(strcmp(tt, "\010\0\0\0""cpstring") != 0)&&(strcmp(tt, "\03\0\0\0""ptr") != 0)&&(parsedPointer==false)) {

#line 932 "/home/alois/Documents/bah-bah/src/parser.bah"
amp = "\01\0\0\0""&";
}

#line 935 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string name = string(ogName);

#line 936 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((hasStructSep(&name)==true)) {

#line 937 "/home/alois/Documents/bah-bah/src/parser.bah"
name = splitStructSepAfter(name);
}

#line 940 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string cType;

#line 942 "/home/alois/Documents/bah-bah/src/parser.bah"
if (strHasPrefix(tt,"\011\0\0\0""function(")) {

#line 943 "/home/alois/Documents/bah-bah/src/parser.bah"
cType = string("\05\0\0\0""void*");
}

#line 944 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 945 "/home/alois/Documents/bah-bah/src/parser.bah"
cType = getCType(tt,elems);
}

#line 949 "/home/alois/Documents/bah-bah/src/parser.bah"
if (string__hasPrefix(&cType,"\07\0\0\0""struct ")) {

#line 950 "/home/alois/Documents/bah-bah/src/parser.bah"
string__replace(&cType,"\01\0\0\0""*","\0\0\0\0""");
}

#line 953 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((cType.length==0)) {

#line 954 "/home/alois/Documents/bah-bah/src/parser.bah"
string__set(&cType,"\01\0\0\0""0");
}

#line 957 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* ____BAH_COMPILER_VAR_698 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_698->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_698->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_698->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_698->from = "\0\0\0\0""";
struct variable* rv = ____BAH_COMPILER_VAR_698;

#line 958 "/home/alois/Documents/bah-bah/src/parser.bah"
rv->name = genCompilerVar();

#line 959 "/home/alois/Documents/bah-bah/src/parser.bah"
rv->type = "\016\0\0\0""reflectElement";

#line 961 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_699 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_699);
    elems->vars->data[____BAH_COMPILER_VAR_699] = rv;

#line 963 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_700 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_700[2] = "\01\0\0\0""\"";____BAH_COMPILER_VAR_700[1] = tt;____BAH_COMPILER_VAR_700[0] = "\01\0\0\0""\"";char * ____BAH_COMPILER_VAR_701 =__Bah_multiple_concat(____BAH_COMPILER_VAR_700, 3);char** ____BAH_COMPILER_VAR_702 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_702[2] = "\01\0\0\0""\"";____BAH_COMPILER_VAR_702[1] = string__str(&name);____BAH_COMPILER_VAR_702[0] = "\01\0\0\0""\"";char * ____BAH_COMPILER_VAR_703 =__Bah_multiple_concat(____BAH_COMPILER_VAR_702, 3);char** ____BAH_COMPILER_VAR_704 = alloca(22 * sizeof(char*));____BAH_COMPILER_VAR_704[21] = "\03\0\0\0"");\n";____BAH_COMPILER_VAR_704[20] = offset;____BAH_COMPILER_VAR_704[19] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_704[18] = structLayout;____BAH_COMPILER_VAR_704[17] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_704[16] = isStruct;____BAH_COMPILER_VAR_704[15] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_704[14] = arrElem;____BAH_COMPILER_VAR_704[13] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_704[12] = isArr;____BAH_COMPILER_VAR_704[11] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_704[10] = strLitteralToBahStr(____BAH_COMPILER_VAR_703);____BAH_COMPILER_VAR_704[9] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_704[8] = strLitteralToBahStr(____BAH_COMPILER_VAR_701);____BAH_COMPILER_VAR_704[7] = "\03\0\0\0""), ";____BAH_COMPILER_VAR_704[6] = string__str(&cType);____BAH_COMPILER_VAR_704[5] = "\011\0\0\0"", sizeof(";____BAH_COMPILER_VAR_704[4] = t.cont;____BAH_COMPILER_VAR_704[3] = amp;____BAH_COMPILER_VAR_704[2] = "\015\0\0\0"" = __reflect(";____BAH_COMPILER_VAR_704[1] = rv->name;____BAH_COMPILER_VAR_704[0] = "\026\0\0\0""struct reflectElement ";char * ____BAH_COMPILER_VAR_705 =__Bah_multiple_concat(____BAH_COMPILER_VAR_704, 22);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_705));

#line 965 "/home/alois/Documents/bah-bah/src/parser.bah"
t.cont = rv->name;

#line 967 "/home/alois/Documents/bah-bah/src/parser.bah"
return t;
};

#line 971 "/home/alois/Documents/bah-bah/src/parser.bah"
char * parseArrayDecl(struct variable* v,__BAH_ARR_TYPE_Tok l,long int i,long int max,struct Elems* elems){

#line 972 "/home/alois/Documents/bah-bah/src/parser.bah"
long int arrayLength = 0;

#line 973 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string arrType = getCType(v->type,elems);

#line 974 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimRight(&arrType,1);

#line 975 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_706 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_706[2] = "\02\0\0\0""))";____BAH_COMPILER_VAR_706[1] = string__str(&arrType);____BAH_COMPILER_VAR_706[0] = "\023\0\0\0""memoryAlloc(sizeof(";char * ____BAH_COMPILER_VAR_707 =__Bah_multiple_concat(____BAH_COMPILER_VAR_706, 3);char * code = ____BAH_COMPILER_VAR_707;

#line 976 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimLeft(&arrType,6);

#line 977 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimRight(&arrType,1);

#line 978 "/home/alois/Documents/bah-bah/src/parser.bah"
char * elemTypeStr = string__str(&arrType);

#line 980 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((i+1!=max)) {

#line 981 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 982 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok nt = l->data[i];

#line 983 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((strcmp(nt.cont, "\01\0\0\0""{") != 0), 0)) {

#line 984 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&l->data[i+1],"\060\0\0\0""{TOKEN} not expected after array initialization.");
}

#line 986 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string elemBahType = string(v->type);

#line 987 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimLeft(&elemBahType,2);

#line 988 "/home/alois/Documents/bah-bah/src/parser.bah"
char * elemBahTypeStr = string__str(&elemBahType);

#line 989 "/home/alois/Documents/bah-bah/src/parser.bah"
i = i+1;

#line 990 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);

#line 991 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i<max)) {

#line 992 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_708 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_708);
    memory->data[____BAH_COMPILER_VAR_708] = l->data[i];

#line 993 "/home/alois/Documents/bah-bah/src/parser.bah"
i = i+1;
};

#line 995 "/home/alois/Documents/bah-bah/src/parser.bah"
memory = prePross(memory,(lineType)-1,elems);

#line 996 "/home/alois/Documents/bah-bah/src/parser.bah"
i = 0;

#line 996 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i<len(memory))) {

#line 997 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = memory->data[i];

#line 998 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "\01\0\0\0""{") == 0)) {

#line 1000 "/home/alois/Documents/bah-bah/src/parser.bah"
long int j = i-1;

#line 1001 "/home/alois/Documents/bah-bah/src/parser.bah"
long int nbBraces = 0;

#line 1002 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<len(memory)); 
#line 1002 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 1003 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok tmpT = memory->data[i];

#line 1004 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(tmpT.cont, "\01\0\0\0""{") == 0)) {

#line 1005 "/home/alois/Documents/bah-bah/src/parser.bah"
++nbBraces;
}

#line 1006 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(tmpT.cont, "\01\0\0\0""}") == 0)) {

#line 1007 "/home/alois/Documents/bah-bah/src/parser.bah"
--nbBraces;
}

#line 1009 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((nbBraces==0)) {

#line 1010 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}
};

#line 1013 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* ____BAH_COMPILER_VAR_709 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_709->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_709->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_709->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_709->from = "\0\0\0\0""";
struct variable* tmpV = ____BAH_COMPILER_VAR_709;

#line 1014 "/home/alois/Documents/bah-bah/src/parser.bah"
tmpV->name = genCompilerVar();

#line 1015 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string elemType = string(v->type);

#line 1016 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimLeft(&elemType,2);

#line 1017 "/home/alois/Documents/bah-bah/src/parser.bah"
tmpV->type = string__str(&elemType);

#line 1018 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_710 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_710);
    elems->vars->data[____BAH_COMPILER_VAR_710] = tmpV;

#line 1020 "/home/alois/Documents/bah-bah/src/parser.bah"
char * oldNL = NEXT_LINE;

#line 1021 "/home/alois/Documents/bah-bah/src/parser.bah"
NEXT_LINE = "\0\0\0\0""";

#line 1022 "/home/alois/Documents/bah-bah/src/parser.bah"
char * innerCode = parseArrayDecl(tmpV,memory,j,i+1,elems);

#line 1023 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string cType = getCType(string__str(&elemType),elems);

#line 1024 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_711 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_711[8] = "\021\0\0\0""\n                ";____BAH_COMPILER_VAR_711[7] = NEXT_LINE;____BAH_COMPILER_VAR_711[6] = "\022\0\0\0"";\n                ";____BAH_COMPILER_VAR_711[5] = innerCode;____BAH_COMPILER_VAR_711[4] = "\03\0\0\0"" = ";____BAH_COMPILER_VAR_711[3] = tmpV->name;____BAH_COMPILER_VAR_711[2] = "\04\0\0\0"") * ";____BAH_COMPILER_VAR_711[1] = string__str(&cType);____BAH_COMPILER_VAR_711[0] = "\027\0\0\0""\n                array(";char * ____BAH_COMPILER_VAR_712 =__Bah_multiple_concat(____BAH_COMPILER_VAR_711, 9);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_712));

#line 1028 "/home/alois/Documents/bah-bah/src/parser.bah"
NEXT_LINE = oldNL;

#line 1030 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok ____BAH_COMPILER_VAR_713 = {};
____BAH_COMPILER_VAR_713.cont = "\0\0\0\0""";
____BAH_COMPILER_VAR_713.ogCont = "\0\0\0\0""";
____BAH_COMPILER_VAR_713.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_713.line = 1;
____BAH_COMPILER_VAR_713.begLine = 1;
____BAH_COMPILER_VAR_713.bahType = "\0\0\0\0""";
____BAH_COMPILER_VAR_713.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_713.cont = tmpV->name;
____BAH_COMPILER_VAR_713.bahType = string__str(&elemType);
____BAH_COMPILER_VAR_713.isValue = true;
t = ____BAH_COMPILER_VAR_713;
}

#line 1038 "/home/alois/Documents/bah-bah/src/parser.bah"
char * tt = getTypeFromToken(&t,true,elems);

#line 1039 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((compTypes(tt,elemBahTypeStr)==false), 0)) {

#line 1040 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_714 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_714[3] = elemBahTypeStr;____BAH_COMPILER_VAR_714[2] = "\05\0\0\0"") as ";____BAH_COMPILER_VAR_714[1] = tt;____BAH_COMPILER_VAR_714[0] = "\024\0\0\0""Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_715 =__Bah_multiple_concat(____BAH_COMPILER_VAR_714, 4);throwErr(&t,____BAH_COMPILER_VAR_715);
}

#line 1043 "/home/alois/Documents/bah-bah/src/parser.bah"
char * strArrayLength = intToStr(arrayLength);

#line 1044 "/home/alois/Documents/bah-bah/src/parser.bah"
arrayLength = arrayLength+1;

#line 1046 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_716 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_716[6] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_716[5] = t.cont;____BAH_COMPILER_VAR_716[4] = "\04\0\0\0""] = ";____BAH_COMPILER_VAR_716[3] = strArrayLength;____BAH_COMPILER_VAR_716[2] = "\07\0\0\0""->data[";____BAH_COMPILER_VAR_716[1] = v->name;____BAH_COMPILER_VAR_716[0] = NEXT_LINE;char * ____BAH_COMPILER_VAR_717 =__Bah_multiple_concat(____BAH_COMPILER_VAR_716, 7);NEXT_LINE = ____BAH_COMPILER_VAR_717;

#line 1047 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 1048 "/home/alois/Documents/bah-bah/src/parser.bah"
t = memory->data[i];

#line 1050 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "\01\0\0\0"",") != 0)) {

#line 1051 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "\01\0\0\0""}") == 0)) {

#line 1052 "/home/alois/Documents/bah-bah/src/parser.bah"
long int allocLength = arrayLength;

#line 1053 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((allocLength>50)) {

#line 1054 "/home/alois/Documents/bah-bah/src/parser.bah"
long int modAllocAmm = allocLength%50;

#line 1055 "/home/alois/Documents/bah-bah/src/parser.bah"
allocLength = allocLength+modAllocAmm;
}

#line 1056 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1057 "/home/alois/Documents/bah-bah/src/parser.bah"
allocLength = 50;
}

#line 1059 "/home/alois/Documents/bah-bah/src/parser.bah"
char * allocLengthStr = intToStr(allocLength);

#line 1060 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_718 = alloca(11 * sizeof(char*));____BAH_COMPILER_VAR_718[10] = NEXT_LINE;____BAH_COMPILER_VAR_718[9] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_718[8] = allocLengthStr;____BAH_COMPILER_VAR_718[7] = "\017\0\0\0""->realLength = ";____BAH_COMPILER_VAR_718[6] = v->name;____BAH_COMPILER_VAR_718[5] = "\027\0\0\0"");\n                    ";____BAH_COMPILER_VAR_718[4] = allocLengthStr;____BAH_COMPILER_VAR_718[3] = "\04\0\0\0"") * ";____BAH_COMPILER_VAR_718[2] = elemTypeStr;____BAH_COMPILER_VAR_718[1] = "\034\0\0\0""->data = memoryAlloc(sizeof(";____BAH_COMPILER_VAR_718[0] = v->name;char * ____BAH_COMPILER_VAR_719 =__Bah_multiple_concat(____BAH_COMPILER_VAR_718, 11);NEXT_LINE = ____BAH_COMPILER_VAR_719;

#line 1062 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}

#line 1063 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1064 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"\031\0\0\0""Expected ',' got {TOKEN}.");
}
}

#line 1067 "/home/alois/Documents/bah-bah/src/parser.bah"
i = i+1;
};
}

#line 1070 "/home/alois/Documents/bah-bah/src/parser.bah"
char * strArrayLength = intToStr(arrayLength);

#line 1071 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_720 = alloca(10 * sizeof(char*));____BAH_COMPILER_VAR_720[9] = NEXT_LINE;____BAH_COMPILER_VAR_720[8] = "\03\0\0\0"");\n";____BAH_COMPILER_VAR_720[7] = elemTypeStr;____BAH_COMPILER_VAR_720[6] = "\024\0\0\0""->elemSize = sizeof(";____BAH_COMPILER_VAR_720[5] = v->name;____BAH_COMPILER_VAR_720[4] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_720[3] = strArrayLength;____BAH_COMPILER_VAR_720[2] = "\013\0\0\0""->length = ";____BAH_COMPILER_VAR_720[1] = v->name;____BAH_COMPILER_VAR_720[0] = "\01\0\0\0""\n";char * ____BAH_COMPILER_VAR_721 =__Bah_multiple_concat(____BAH_COMPILER_VAR_720, 10);NEXT_LINE = ____BAH_COMPILER_VAR_721;

#line 1075 "/home/alois/Documents/bah-bah/src/parser.bah"
return code;
};

#line 1078 "/home/alois/Documents/bah-bah/src/parser.bah"
array(char *)* equalsTokens;

#line 1080 "/home/alois/Documents/bah-bah/src/parser.bah"
char ____BAH_COMPILER_VAR_727(array(char *)* arr, char * el) {
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

#line 1082 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok ft = l->data[0];

#line 1083 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((ft.isFunc==true)) {

#line 1084 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((len(l)>1), 0)) {

#line 1085 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&l->data[len(l)-1],"\052\0\0\0""Not expecting {TOKEN} after function call.");
}

#line 1087 "/home/alois/Documents/bah-bah/src/parser.bah"
ft = l->data[0];

#line 1088 "/home/alois/Documents/bah-bah/src/parser.bah"
char parsed = true;

#line 1089 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_722 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_722[1] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_722[0] = ft.cont;char * ____BAH_COMPILER_VAR_723 =__Bah_multiple_concat(____BAH_COMPILER_VAR_722, 2);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_723));

#line 1090 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}

#line 1092 "/home/alois/Documents/bah-bah/src/parser.bah"
l = parseStructType(l,(lineType)-1,elems);

#line 1093 "/home/alois/Documents/bah-bah/src/parser.bah"
char isEqual = false;

#line 1094 "/home/alois/Documents/bah-bah/src/parser.bah"
long int equalIndex = 0;

#line 1095 "/home/alois/Documents/bah-bah/src/parser.bah"
char toVar = false;

#line 1096 "/home/alois/Documents/bah-bah/src/parser.bah"
char isPointedVar = false;

#line 1097 "/home/alois/Documents/bah-bah/src/parser.bah"
char isStruct = false;

#line 1098 "/home/alois/Documents/bah-bah/src/parser.bah"
char * currentType = "\0\0\0\0""";

#line 1100 "/home/alois/Documents/bah-bah/src/parser.bah"
ft = l->data[0];

#line 1101 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* v = searchVar(ft.cont,elems);

#line 1102 "/home/alois/Documents/bah-bah/src/parser.bah"
char exists = true;

#line 1103 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ogName= null;

#line 1104 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((v==null)) {

#line 1105 "/home/alois/Documents/bah-bah/src/parser.bah"
exists = false;

#line 1106 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* ____BAH_COMPILER_VAR_724 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_724->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_724->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_724->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_724->from = "\0\0\0\0""";
v = ____BAH_COMPILER_VAR_724;

#line 1107 "/home/alois/Documents/bah-bah/src/parser.bah"
v->name = ft.cont;

#line 1108 "/home/alois/Documents/bah-bah/src/parser.bah"
v->type = "\0\0\0\0""";
}

#line 1109 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1110 "/home/alois/Documents/bah-bah/src/parser.bah"
ogName = v->name;
}

#line 1112 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((v->isConst==true), 0)) {

#line 1113 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&ft,"\046\0\0\0""Cannot set the value of const {TOKEN}.");
}

#line 1115 "/home/alois/Documents/bah-bah/src/parser.bah"
char * code = "\0\0\0\0""";

#line 1117 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((exists==true)&&isGlobal(), 0)) {

#line 1118 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&ft,"\051\0\0\0""Cannot redeclare global variable {TOKEN}.");
}

#line 1122 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((len(l)==1)) {

#line 1123 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = l->data[0];

#line 1124 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string c = string(t.cont);

#line 1125 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimLeft(&c,2);

#line 1126 "/home/alois/Documents/bah-bah/src/parser.bah"
v = searchVar(string__str(&c),elems);

#line 1127 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((v==null), 0)) {

#line 1128 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"\067\0\0\0""Cannot increase/decrease not declared variable {TOKEN}.");
}

#line 1130 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* rv = getRealVar(v->name,elems);

#line 1131 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((rv!=null)) {

#line 1132 "/home/alois/Documents/bah-bah/src/parser.bah"
rv->lastSet = elems;
}

#line 1134 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_725 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_725[1] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_725[0] = t.cont;char * ____BAH_COMPILER_VAR_726 =__Bah_multiple_concat(____BAH_COMPILER_VAR_725, 2);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_726));

#line 1135 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}

#line 1138 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((len(l)<2), 0)) {

#line 1139 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&ft,"\032\0\0\0""Missing '=' after {TOKEN}.");
}

#line 1141 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok operT = l->data[1];

#line 1142 "/home/alois/Documents/bah-bah/src/parser.bah"
if (____BAH_COMPILER_VAR_727(equalsTokens, operT.cont)&&(strcmp(operT.cont, "\01\0\0\0""=") != 0)) {

#line 1143 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 1;
nl->elemSize = sizeof(struct Tok);
nl->data = memoryAlloc(sizeof(struct Tok) * 50);
                    nl->realLength = 50;
nl->data[0] = l->data[0];

#line 1144 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((2==len(l)), 0)) {

#line 1145 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&operT,"\036\0\0\0""Cannot use {TOKEN} on nothing.");
}

#line 1147 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string oper = string(operT.cont);

#line 1148 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimRight(&oper,1);

#line 1149 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok operTok = operT;

#line 1150 "/home/alois/Documents/bah-bah/src/parser.bah"
operTok.cont = string__str(&oper);

#line 1152 "/home/alois/Documents/bah-bah/src/parser.bah"
if (l->data[2].isOper) {

#line 1153 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_728 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_728[2] = "\01\0\0\0"")";____BAH_COMPILER_VAR_728[1] = l->data[2].cont;____BAH_COMPILER_VAR_728[0] = "\01\0\0\0""(";char * ____BAH_COMPILER_VAR_729 =__Bah_multiple_concat(____BAH_COMPILER_VAR_728, 3);l->data[2].cont = ____BAH_COMPILER_VAR_729;
}

#line 1156 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct Tok)* tmpL = memoryAlloc(sizeof(array(struct Tok)));

tmpL->length = 3;
tmpL->elemSize = sizeof(struct Tok);
tmpL->data = memoryAlloc(sizeof(struct Tok) * 50);
                    tmpL->realLength = 50;
tmpL->data[0] = ft;
tmpL->data[1] = operTok;
tmpL->data[2] = l->data[2];

#line 1162 "/home/alois/Documents/bah-bah/src/parser.bah"
tmpL = prePross(tmpL,LINE_TYPE_VAR,elems);

#line 1164 "/home/alois/Documents/bah-bah/src/parser.bah"
operT.cont = "\01\0\0\0""=";

#line 1165 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_730 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_730);
    nl->data[____BAH_COMPILER_VAR_730] = operT;

#line 1167 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int j = 0;

#line 1167 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (j<len(tmpL)); 
#line 1167 "/home/alois/Documents/bah-bah/src/parser.bah"
++j) {

#line 1168 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_731 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_731);
    nl->data[____BAH_COMPILER_VAR_731] = tmpL->data[j];
};

#line 1172 "/home/alois/Documents/bah-bah/src/parser.bah"
l = nl;
}

#line 1175 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int i = 1;

#line 1175 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i<len(l))) {

#line 1176 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = l->data[i];

#line 1177 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((t.type==TOKEN_TYPE_SYNTAX)) {

#line 1178 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "\01\0\0\0""=") == 0)) {

#line 1179 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strlen(currentType)>0)) {

#line 1180 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string sct = string(currentType);

#line 1181 "/home/alois/Documents/bah-bah/src/parser.bah"
string__replace(&sct,"\01\0\0\0"" ","\0\0\0\0""");

#line 1182 "/home/alois/Documents/bah-bah/src/parser.bah"
v->type = string__str(&sct);
}

#line 1184 "/home/alois/Documents/bah-bah/src/parser.bah"
isEqual = true;

#line 1185 "/home/alois/Documents/bah-bah/src/parser.bah"
equalIndex = i;

#line 1186 "/home/alois/Documents/bah-bah/src/parser.bah"
i = i+1;

#line 1187 "/home/alois/Documents/bah-bah/src/parser.bah"
continue;
}
}

#line 1190 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((isEqual==false)) {

#line 1191 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_732 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_732[1] = t.cont;____BAH_COMPILER_VAR_732[0] = currentType;char * ____BAH_COMPILER_VAR_733 =__Bah_multiple_concat(____BAH_COMPILER_VAR_732, 2);currentType = ____BAH_COMPILER_VAR_733;
}

#line 1192 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1194 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((t.isEqual==true)&&(exists==false)&&(isGlobal()==false)) {

#line 1196 "/home/alois/Documents/bah-bah/src/parser.bah"
v->canBeNull = false;
}

#line 1199 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "\04\0\0\0""chan") == 0)) {

#line 1200 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((i>=len(l)), 0)) {

#line 1201 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"\066\0\0\0""Cannot declare a {TOKEN} without a type (chan <type>).");
}

#line 1203 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 1204 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok nt = l->data[i];

#line 1205 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_734 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_734[1] = nt.cont;____BAH_COMPILER_VAR_734[0] = "\05\0\0\0""chan:";char * ____BAH_COMPILER_VAR_735 =__Bah_multiple_concat(____BAH_COMPILER_VAR_734, 2);v->type = ____BAH_COMPILER_VAR_735;

#line 1206 "/home/alois/Documents/bah-bah/src/parser.bah"
code = "\011\0\0\0""channel()";

#line 1207 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((i+1!=len(l)), 0)) {

#line 1208 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok errT = l->data[i+1];

#line 1209 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&errT,"\057\0\0\0""{TOKEN} not expected after channel declaration.");
}

#line 1211 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}

#line 1212 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(t.cont, "\03\0\0\0""map") == 0)) {

#line 1213 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((i>=len(l)), 0)) {

#line 1214 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"\065\0\0\0""Cannot declare a {TOKEN} without a type (map <type>).");
}

#line 1216 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 1217 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok nt = l->data[i];

#line 1218 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_736 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_736[1] = nt.cont;____BAH_COMPILER_VAR_736[0] = "\04\0\0\0""map:";char * ____BAH_COMPILER_VAR_737 =__Bah_multiple_concat(____BAH_COMPILER_VAR_736, 2);v->type = ____BAH_COMPILER_VAR_737;

#line 1219 "/home/alois/Documents/bah-bah/src/parser.bah"
code = "\014\0\0\0""mapWrapper()";

#line 1220 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((i+1!=len(l)), 0)) {

#line 1221 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok errT = l->data[i+1];

#line 1222 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&errT,"\053\0\0\0""{TOKEN} not expected after map declaration.");
}

#line 1224 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}

#line 1225 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(t.cont, "\06\0\0\0""buffer") == 0)) {

#line 1226 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((i>=len(l)), 0)) {

#line 1227 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"\074\0\0\0""Cannot declare a {TOKEN} without a length (buffer <length>).");
}

#line 1229 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 1230 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok nt = l->data[i];

#line 1231 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((nt.type!=TOKEN_TYPE_INT), 0)) {

#line 1232 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&nt,"\044\0\0\0""Expected buffer length, not {TOKEN}.");
}

#line 1234 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_738 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_738[1] = nt.cont;____BAH_COMPILER_VAR_738[0] = "\07\0\0\0""buffer:";char * ____BAH_COMPILER_VAR_739 =__Bah_multiple_concat(____BAH_COMPILER_VAR_738, 2);v->type = ____BAH_COMPILER_VAR_739;

#line 1235 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* ____BAH_COMPILER_VAR_740 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_740->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_740->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_740->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_740->from = "\0\0\0\0""";
struct variable* av = ____BAH_COMPILER_VAR_740;

#line 1236 "/home/alois/Documents/bah-bah/src/parser.bah"
av->type = "\05\0\0\0""char*";

#line 1237 "/home/alois/Documents/bah-bah/src/parser.bah"
av->name = genCompilerVar();

#line 1238 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_741 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_741);
    elems->vars->data[____BAH_COMPILER_VAR_741] = av;

#line 1239 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string cType = getCType(av->type,elems);

#line 1240 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_742 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_742[4] = "\02\0\0\0""];";____BAH_COMPILER_VAR_742[3] = nt.cont;____BAH_COMPILER_VAR_742[2] = "\01\0\0\0""[";____BAH_COMPILER_VAR_742[1] = av->name;____BAH_COMPILER_VAR_742[0] = "\05\0\0\0""char ";char * ____BAH_COMPILER_VAR_743 =__Bah_multiple_concat(____BAH_COMPILER_VAR_742, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_743));

#line 1241 "/home/alois/Documents/bah-bah/src/parser.bah"
code = av->name;

#line 1242 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((i+1!=len(l)), 0)) {

#line 1243 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok errT = l->data[i+1];

#line 1244 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&errT,"\056\0\0\0""{TOKEN} not expected after buffer declaration.");
}

#line 1246 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}

#line 1250 "/home/alois/Documents/bah-bah/src/parser.bah"
char * tp = getTypeFromToken(&t,true,elems);

#line 1253 "/home/alois/Documents/bah-bah/src/parser.bah"

                struct string ____BAH_COMPILER_VAR_744 = string(compilerState.currentDir);
                if ((isUnsafe==false)&&(string__hasPrefix(&____BAH_COMPILER_VAR_744,BAH_DIR)==false)&&isRCPpointerType(tp)) {

#line 1254 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "\04\0\0\0""null") == 0)||(tp[strlen(tp)-1+4]==33)) {

#line 1255 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((exists==true)) {

#line 1256 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* rv = getRealVar(v->name,elems);

#line 1257 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((rv!=null)) {

#line 1258 "/home/alois/Documents/bah-bah/src/parser.bah"
rv->canBeNull = true;
}
}

#line 1260 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1261 "/home/alois/Documents/bah-bah/src/parser.bah"
v->canBeNull = true;
}
}

#line 1263 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((t.type==TOKEN_TYPE_VAR)) {

#line 1264 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* tv = searchVar(t.cont,elems);

#line 1265 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((tv!=null)) {

#line 1266 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((exists==true)&&(tv->canBeNull==false)) {

#line 1267 "/home/alois/Documents/bah-bah/src/parser.bah"
if (canChangeNullState(v,elems)) {

#line 1268 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* rv = getRealVar(v->name,elems);

#line 1269 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((rv!=null)) {

#line 1270 "/home/alois/Documents/bah-bah/src/parser.bah"
rv->canBeNull = false;
}
}
}

#line 1273 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1274 "/home/alois/Documents/bah-bah/src/parser.bah"
v->canBeNull = tv->canBeNull;
}
}
}

#line 1277 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((t.isFunc==true)) {

#line 1278 "/home/alois/Documents/bah-bah/src/parser.bah"
struct func* fn = searchFuncByToken(&t,elems);

#line 1279 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((fn!=null)&&(fn->returns!=null)) {

#line 1280 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((fn->returns->canBeNull==true)) {

#line 1281 "/home/alois/Documents/bah-bah/src/parser.bah"
v->canBeNull = true;
}

#line 1282 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1283 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((exists==true)) {

#line 1284 "/home/alois/Documents/bah-bah/src/parser.bah"
if (canChangeNullState(v,elems)) {

#line 1285 "/home/alois/Documents/bah-bah/src/parser.bah"
v->canBeNull = false;
}
}

#line 1287 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1288 "/home/alois/Documents/bah-bah/src/parser.bah"
v->canBeNull = false;
}
}
}
}

#line 1292 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1293 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((exists==true)) {

#line 1294 "/home/alois/Documents/bah-bah/src/parser.bah"
if (canChangeNullState(v,elems)) {

#line 1295 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* rv = getRealVar(v->name,elems);

#line 1296 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((rv!=null)) {

#line 1297 "/home/alois/Documents/bah-bah/src/parser.bah"
rv->canBeNull = false;
}
}
}

#line 1299 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1300 "/home/alois/Documents/bah-bah/src/parser.bah"
v->canBeNull = false;
}
}
}

#line 1306 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((exists==true)) {

#line 1307 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((compTypes(tp,v->type)==false), 0)) {

#line 1308 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_745 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_745[4] = "\01\0\0\0"".";____BAH_COMPILER_VAR_745[3] = v->type;____BAH_COMPILER_VAR_745[2] = "\05\0\0\0"") as ";____BAH_COMPILER_VAR_745[1] = tp;____BAH_COMPILER_VAR_745[0] = "\024\0\0\0""Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_746 =__Bah_multiple_concat(____BAH_COMPILER_VAR_745, 5);throwErr(&t,____BAH_COMPILER_VAR_746);
}
}

#line 1310 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1311 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(currentType, "\0\0\0\0""") == 0)) {

#line 1312 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(v->type, "\0\0\0\0""") == 0)) {

#line 1313 "/home/alois/Documents/bah-bah/src/parser.bah"
v->type = tp;
}

#line 1314 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1315 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((compTypes(tp,v->type)==false), 0)) {

#line 1316 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_747 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_747[4] = "\01\0\0\0"".";____BAH_COMPILER_VAR_747[3] = v->type;____BAH_COMPILER_VAR_747[2] = "\05\0\0\0"") as ";____BAH_COMPILER_VAR_747[1] = tp;____BAH_COMPILER_VAR_747[0] = "\024\0\0\0""Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_748 =__Bah_multiple_concat(____BAH_COMPILER_VAR_747, 5);throwErr(&t,____BAH_COMPILER_VAR_748);
}
}
}
}

#line 1322 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((RAIIenabled==true)&&(t.type==TOKEN_TYPE_VAR)&&isRCPtype(tp,elems)) {

#line 1323 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* ov = searchVar(removeCast(t.cont),elems);

#line 1324 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((ov!=null)) {

#line 1325 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int k = 0;

#line 1325 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (k<len(elems->vars)); 
#line 1325 "/home/alois/Documents/bah-bah/src/parser.bah"
++k) {

#line 1326 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(elems->vars->data[k]->name, ov->name) == 0)) {

#line 1327 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_749 = len(elems->deletedVars);
    __Bah_realocate_arr(elems->deletedVars, ____BAH_COMPILER_VAR_749);
    elems->deletedVars->data[____BAH_COMPILER_VAR_749] = elems->vars->data[k];

#line 1328 "/home/alois/Documents/bah-bah/src/parser.bah"
delete(elems->vars,k);

#line 1329 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}
};
}
}

#line 1336 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "\0\0\0\0""") != 0)&&(strHasPrefix(t.cont,"\01\0\0\0""{")==false)) {

#line 1337 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_750 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_750[1] = t.cont;____BAH_COMPILER_VAR_750[0] = code;char * ____BAH_COMPILER_VAR_751 =__Bah_multiple_concat(____BAH_COMPILER_VAR_750, 2);code = ____BAH_COMPILER_VAR_751;

#line 1338 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((t.isOper==false)&&(RCPavailable()==true)) {

#line 1339 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* iv = searchVar(t.cont,elems);

#line 1340 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((iv!=null)&&(iv->isConst==false)) {

#line 1341 "/home/alois/Documents/bah-bah/src/parser.bah"
toVar = true;

#line 1342 "/home/alois/Documents/bah-bah/src/parser.bah"
isPointedVar = strHasPrefix(t.cont,"\01\0\0\0""&");

#line 1343 "/home/alois/Documents/bah-bah/src/parser.bah"
struct cStruct* s = searchStruct(iv->type,elems);

#line 1344 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((s!=null)&&(strCount(iv->type,"\01\0\0\0""*")==0)&&(s->isBinding==false)) {

#line 1345 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strCount(iv->name,"\01\0\0\0""*")==0)) {

#line 1346 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_752 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_752[5] = "\05\0\0\0""), 0)";____BAH_COMPILER_VAR_752[4] = iv->name;____BAH_COMPILER_VAR_752[3] = "\011\0\0\0"", sizeof(";____BAH_COMPILER_VAR_752[2] = iv->name;____BAH_COMPILER_VAR_752[1] = "\021\0\0\0""; RCP_scanStack(&";____BAH_COMPILER_VAR_752[0] = code;char * ____BAH_COMPILER_VAR_753 =__Bah_multiple_concat(____BAH_COMPILER_VAR_752, 6);code = ____BAH_COMPILER_VAR_753;
}

#line 1347 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1348 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string ivn = string(iv->name);

#line 1349 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((string__count(&ivn,"\01\0\0\0""*")>0)) {

#line 1350 "/home/alois/Documents/bah-bah/src/parser.bah"
string__replace(&ivn,"\01\0\0\0""*","\0\0\0\0""");

#line 1351 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_754 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_754[4] = "\05\0\0\0""), 0)";____BAH_COMPILER_VAR_754[3] = iv->name;____BAH_COMPILER_VAR_754[2] = "\011\0\0\0"", sizeof(";____BAH_COMPILER_VAR_754[1] = string__str(&ivn);____BAH_COMPILER_VAR_754[0] = "\020\0\0\0""; RCP_scanStack(";char * ____BAH_COMPILER_VAR_755 =__Bah_multiple_concat(____BAH_COMPILER_VAR_754, 5);char** ____BAH_COMPILER_VAR_756 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_756[1] = ____BAH_COMPILER_VAR_755;____BAH_COMPILER_VAR_756[0] = code;char * ____BAH_COMPILER_VAR_757 =__Bah_multiple_concat(____BAH_COMPILER_VAR_756, 2);code = ____BAH_COMPILER_VAR_757;
}

#line 1352 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1353 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_758 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_758[3] = "\01\0\0\0"")";____BAH_COMPILER_VAR_758[2] = iv->name;____BAH_COMPILER_VAR_758[1] = "\013\0\0\0""; RCP_incr(";____BAH_COMPILER_VAR_758[0] = code;char * ____BAH_COMPILER_VAR_759 =__Bah_multiple_concat(____BAH_COMPILER_VAR_758, 4);code = ____BAH_COMPILER_VAR_759;
}
}
}
}
}

#line 1359 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}

#line 1363 "/home/alois/Documents/bah-bah/src/parser.bah"
if (strHasPrefix(v->type,"\02\0\0\0""[]")) {

#line 1364 "/home/alois/Documents/bah-bah/src/parser.bah"
code = parseArrayDecl(v,l,i,len(l),elems);

#line 1365 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}

#line 1367 "/home/alois/Documents/bah-bah/src/parser.bah"
isStruct = true;

#line 1368 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((i+1!=len(l)), 0)) {

#line 1369 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&l->data[i+1],"\061\0\0\0""{TOKEN} not expected after struct initialization.");
}

#line 1373 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_760 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_760[1] = t.cont;____BAH_COMPILER_VAR_760[0] = code;char * ____BAH_COMPILER_VAR_761 =__Bah_multiple_concat(____BAH_COMPILER_VAR_760, 2);code = ____BAH_COMPILER_VAR_761;
}

#line 1376 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;
};

#line 1379 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((exists==true)) {

#line 1382 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* rv = getRealVar(v->name,elems);

#line 1383 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((rv!=null)&&(isStaticToken(&l->data[equalIndex+1],elems)==false)) {

#line 1384 "/home/alois/Documents/bah-bah/src/parser.bah"
rv->lastSet = elems;

#line 1385 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((l->data[equalIndex+1].type==TOKEN_TYPE_VAR)) {

#line 1386 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* vv = searchVirtVarByToken(&l->data[equalIndex+1],elems);

#line 1387 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((vv!=null)) {

#line 1388 "/home/alois/Documents/bah-bah/src/parser.bah"
rv->lastSet = vv->lastSet;
}
}
}

#line 1393 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((ft.parent!=null)) {

#line 1394 "/home/alois/Documents/bah-bah/src/parser.bah"
ft.parent->lastSet = elems;
}

#line 1396 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((currentFn!=null)) {

#line 1397 "/home/alois/Documents/bah-bah/src/parser.bah"

                struct string ____BAH_COMPILER_VAR_762 = string(v->name);
                if ((strcmp(v->name, "\04\0\0\0""this") == 0)||string__hasPrefix(&____BAH_COMPILER_VAR_762,"\06\0\0\0""this->")) {

#line 1398 "/home/alois/Documents/bah-bah/src/parser.bah"
currentFn->isMut = true;
}
}

#line 1401 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((strlen(code)==0), 0)) {

#line 1402 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&ft,"\032\0\0\0""Cannot re-declare {TOKEN}.");
}

#line 1404 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((strlen(currentType)>0), 0)) {

#line 1405 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok st = l->data[1];

#line 1406 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_763 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_763[2] = "\015\0\0\0""' to {TOKEN}.";____BAH_COMPILER_VAR_763[1] = ft.cont;____BAH_COMPILER_VAR_763[0] = "\060\0\0\0""Cannot change the type of already declared var '";char * ____BAH_COMPILER_VAR_764 =__Bah_multiple_concat(____BAH_COMPILER_VAR_763, 3);throwErr(&st,____BAH_COMPILER_VAR_764);
}

#line 1408 "/home/alois/Documents/bah-bah/src/parser.bah"
char * preCode = "\0\0\0\0""";

#line 1409 "/home/alois/Documents/bah-bah/src/parser.bah"
char * val = code;

#line 1410 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((isStruct==false)) {

#line 1411 "/home/alois/Documents/bah-bah/src/parser.bah"
if (isRCPpointerType(v->type)&&(isPointedVar==false)&&(RCPavailable()==true)) {

#line 1412 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string cType = getCType(v->type,elems);

#line 1413 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((toVar==true)) {

#line 1414 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((RCPselfRef(v)==false)) {

#line 1415 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_765 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_765[8] = "\01\0\0\0"")";____BAH_COMPILER_VAR_765[7] = code;____BAH_COMPILER_VAR_765[6] = "\016\0\0\0""*)RCP_incrIL(&";____BAH_COMPILER_VAR_765[5] = string__str(&cType);____BAH_COMPILER_VAR_765[4] = "\06\0\0\0"") = *(";____BAH_COMPILER_VAR_765[3] = v->name;____BAH_COMPILER_VAR_765[2] = "\016\0\0\0""*)RCP_decrIL(&";____BAH_COMPILER_VAR_765[1] = string__str(&cType);____BAH_COMPILER_VAR_765[0] = "\02\0\0\0""*(";char * ____BAH_COMPILER_VAR_766 =__Bah_multiple_concat(____BAH_COMPILER_VAR_765, 9);code = ____BAH_COMPILER_VAR_766;
}

#line 1416 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1417 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* ____BAH_COMPILER_VAR_767 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_767->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_767->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_767->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_767->from = "\0\0\0\0""";
struct variable* tmpV = ____BAH_COMPILER_VAR_767;

#line 1418 "/home/alois/Documents/bah-bah/src/parser.bah"
tmpV->name = genCompilerVar();

#line 1419 "/home/alois/Documents/bah-bah/src/parser.bah"
tmpV->type = v->type;

#line 1420 "/home/alois/Documents/bah-bah/src/parser.bah"
struct rope* dv = decrVar(tmpV,elems);

#line 1421 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_768 = alloca(13 * sizeof(char*));____BAH_COMPILER_VAR_768[12] = rope__toStr(dv);____BAH_COMPILER_VAR_768[11] = "\02\0\0\0"");";____BAH_COMPILER_VAR_768[10] = code;____BAH_COMPILER_VAR_768[9] = "\016\0\0\0""*)RCP_incrIL(&";____BAH_COMPILER_VAR_768[8] = string__str(&cType);____BAH_COMPILER_VAR_768[7] = "\05\0\0\0"" = *(";____BAH_COMPILER_VAR_768[6] = v->name;____BAH_COMPILER_VAR_768[5] = "\02\0\0\0""; ";____BAH_COMPILER_VAR_768[4] = v->name;____BAH_COMPILER_VAR_768[3] = "\03\0\0\0"" = ";____BAH_COMPILER_VAR_768[2] = tmpV->name;____BAH_COMPILER_VAR_768[1] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_768[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_769 =__Bah_multiple_concat(____BAH_COMPILER_VAR_768, 13);code = ____BAH_COMPILER_VAR_769;
}
}

#line 1423 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1424 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* ____BAH_COMPILER_VAR_770 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_770->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_770->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_770->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_770->from = "\0\0\0\0""";
struct variable* tmpV = ____BAH_COMPILER_VAR_770;

#line 1425 "/home/alois/Documents/bah-bah/src/parser.bah"
tmpV->name = genCompilerVar();

#line 1426 "/home/alois/Documents/bah-bah/src/parser.bah"
tmpV->type = v->type;

#line 1427 "/home/alois/Documents/bah-bah/src/parser.bah"
struct rope* dv = decrVar(tmpV,elems);

#line 1428 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_771 = alloca(11 * sizeof(char*));____BAH_COMPILER_VAR_771[10] = rope__toStr(dv);____BAH_COMPILER_VAR_771[9] = "\01\0\0\0"";";____BAH_COMPILER_VAR_771[8] = code;____BAH_COMPILER_VAR_771[7] = "\03\0\0\0"" = ";____BAH_COMPILER_VAR_771[6] = v->name;____BAH_COMPILER_VAR_771[5] = "\02\0\0\0""; ";____BAH_COMPILER_VAR_771[4] = v->name;____BAH_COMPILER_VAR_771[3] = "\03\0\0\0"" = ";____BAH_COMPILER_VAR_771[2] = tmpV->name;____BAH_COMPILER_VAR_771[1] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_771[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_772 =__Bah_multiple_concat(____BAH_COMPILER_VAR_771, 11);code = ____BAH_COMPILER_VAR_772;
}
}

#line 1430 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1431 "/home/alois/Documents/bah-bah/src/parser.bah"
struct cStruct* s = searchStruct(v->type,elems);

#line 1432 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((s!=null)&&(RCPavailable()==true)&&(RCPselfRef(v)==false)&&(s->isBinding==false)) {

#line 1433 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strCount(v->name,"\01\0\0\0""*")==0)) {

#line 1434 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_773 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_773[4] = "\07\0\0\0""), 1); ";____BAH_COMPILER_VAR_773[3] = v->name;____BAH_COMPILER_VAR_773[2] = "\011\0\0\0"", sizeof(";____BAH_COMPILER_VAR_773[1] = v->name;____BAH_COMPILER_VAR_773[0] = "\017\0\0\0""RCP_scanStack(&";char * ____BAH_COMPILER_VAR_774 =__Bah_multiple_concat(____BAH_COMPILER_VAR_773, 5);preCode = ____BAH_COMPILER_VAR_774;
}

#line 1435 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1436 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string vn = string(v->name);

#line 1437 "/home/alois/Documents/bah-bah/src/parser.bah"
string__replace(&vn,"\01\0\0\0""*","\0\0\0\0""");

#line 1438 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_775 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_775[4] = "\07\0\0\0""), 1); ";____BAH_COMPILER_VAR_775[3] = v->name;____BAH_COMPILER_VAR_775[2] = "\011\0\0\0"", sizeof(";____BAH_COMPILER_VAR_775[1] = string__str(&vn);____BAH_COMPILER_VAR_775[0] = "\016\0\0\0""RCP_scanStack(";char * ____BAH_COMPILER_VAR_776 =__Bah_multiple_concat(____BAH_COMPILER_VAR_775, 5);preCode = ____BAH_COMPILER_VAR_776;
}

#line 1440 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_777 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_777[2] = code;____BAH_COMPILER_VAR_777[1] = "\03\0\0\0"" = ";____BAH_COMPILER_VAR_777[0] = v->name;char * ____BAH_COMPILER_VAR_778 =__Bah_multiple_concat(____BAH_COMPILER_VAR_777, 3);code = ____BAH_COMPILER_VAR_778;
}

#line 1441 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1442 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_779 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_779[2] = code;____BAH_COMPILER_VAR_779[1] = "\03\0\0\0"" = ";____BAH_COMPILER_VAR_779[0] = v->name;char * ____BAH_COMPILER_VAR_780 =__Bah_multiple_concat(____BAH_COMPILER_VAR_779, 3);code = ____BAH_COMPILER_VAR_780;
}
}
}

#line 1445 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1446 "/home/alois/Documents/bah-bah/src/parser.bah"
strTrim(&code);

#line 1447 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strHasPrefix(code,"\01\0\0\0""{")==false)) {

#line 1448 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_781 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_781[2] = code;____BAH_COMPILER_VAR_781[1] = "\03\0\0\0"" = ";____BAH_COMPILER_VAR_781[0] = v->name;char * ____BAH_COMPILER_VAR_782 =__Bah_multiple_concat(____BAH_COMPILER_VAR_781, 3);code = ____BAH_COMPILER_VAR_782;
}
}

#line 1451 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((v->isArray==true)) {

#line 1452 "/home/alois/Documents/bah-bah/src/parser.bah"
code = genArrRealloc(v,preCode,val,elems);
}

#line 1453 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1454 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_783 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_783[1] = code;____BAH_COMPILER_VAR_783[0] = preCode;char * ____BAH_COMPILER_VAR_784 =__Bah_multiple_concat(____BAH_COMPILER_VAR_783, 2);code = ____BAH_COMPILER_VAR_784;
}
}

#line 1456 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1457 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(currentType, "\0\0\0\0""") != 0)) {

#line 1458 "/home/alois/Documents/bah-bah/src/parser.bah"
v->type = currentType;
}

#line 1461 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strlen(code)==0)) {

#line 1462 "/home/alois/Documents/bah-bah/src/parser.bah"
v->canBeNull = true;
}

#line 1465 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string vts = string(v->type);

#line 1466 "/home/alois/Documents/bah-bah/src/parser.bah"
string__replace(&vts,"\01\0\0\0"" ","\0\0\0\0""");

#line 1467 "/home/alois/Documents/bah-bah/src/parser.bah"
v->type = string__str(&vts);

#line 1468 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((strlen(v->type)==0), 0)) {

#line 1469 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&ft,"\046\0\0\0""Cannot declare {TOKEN} without a type.");
}

#line 1471 "/home/alois/Documents/bah-bah/src/parser.bah"
char * vct= null;

#line 1472 "/home/alois/Documents/bah-bah/src/parser.bah"
if (string__hasPrefix(&vts,"\011\0\0\0""function(")) {

#line 1473 "/home/alois/Documents/bah-bah/src/parser.bah"
struct func* tmpfn = parseFnType(vts);

#line 1474 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string tmpfnRetCType = getCType(tmpfn->returns->type,elems);

#line 1476 "/home/alois/Documents/bah-bah/src/parser.bah"
char * tmpfnArgsCType = "\0\0\0\0""";

#line 1477 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int j = 0;

#line 1477 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((j<len(tmpfn->args))) {

#line 1478 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* arg = tmpfn->args->data[j];

#line 1479 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string ct = getCType(arg->type,elems);

#line 1480 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_785 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_785[1] = string__str(&ct);____BAH_COMPILER_VAR_785[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_786 =__Bah_multiple_concat(____BAH_COMPILER_VAR_785, 2);tmpfnArgsCType = ____BAH_COMPILER_VAR_786;

#line 1481 "/home/alois/Documents/bah-bah/src/parser.bah"
j = j+1;

#line 1482 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((j<len(tmpfn->args))) {

#line 1483 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_787 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_787[1] = "\01\0\0\0"",";____BAH_COMPILER_VAR_787[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_788 =__Bah_multiple_concat(____BAH_COMPILER_VAR_787, 2);tmpfnArgsCType = ____BAH_COMPILER_VAR_788;
}
};

#line 1487 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_789 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_789[5] = "\01\0\0\0"")";____BAH_COMPILER_VAR_789[4] = tmpfnArgsCType;____BAH_COMPILER_VAR_789[3] = "\02\0\0\0"")(";____BAH_COMPILER_VAR_789[2] = v->name;____BAH_COMPILER_VAR_789[1] = "\03\0\0\0"" (*";____BAH_COMPILER_VAR_789[0] = string__str(&tmpfnRetCType);char * ____BAH_COMPILER_VAR_790 =__Bah_multiple_concat(____BAH_COMPILER_VAR_789, 6);vct = ____BAH_COMPILER_VAR_790;
}

#line 1488 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1489 "/home/alois/Documents/bah-bah/src/parser.bah"
vct = setCType(v,elems);
}

#line 1491 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(code, "\0\0\0\0""") != 0)&&(shouldOnlyDecl==false)) {

#line 1494 "/home/alois/Documents/bah-bah/src/parser.bah"
if (isRCPpointerType(v->type)&&(RCPavailable()==true)&&(toVar==true)&&(isPointedVar==false)) {

#line 1495 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string cType = getCType(v->type,elems);

#line 1496 "/home/alois/Documents/bah-bah/src/parser.bah"
if (isGlobal()) {

#line 1497 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_791 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_791[5] = "\03\0\0\0"");\n";____BAH_COMPILER_VAR_791[4] = code;____BAH_COMPILER_VAR_791[3] = "\016\0\0\0""*)RCP_incrIL(&";____BAH_COMPILER_VAR_791[2] = string__str(&cType);____BAH_COMPILER_VAR_791[1] = "\05\0\0\0"" = *(";____BAH_COMPILER_VAR_791[0] = v->name;char * ____BAH_COMPILER_VAR_792 =__Bah_multiple_concat(____BAH_COMPILER_VAR_791, 6);INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_792));
}

#line 1498 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1499 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_793 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_793[5] = "\01\0\0\0"")";____BAH_COMPILER_VAR_793[4] = code;____BAH_COMPILER_VAR_793[3] = "\016\0\0\0""*)RCP_incrIL(&";____BAH_COMPILER_VAR_793[2] = string__str(&cType);____BAH_COMPILER_VAR_793[1] = "\05\0\0\0"" = *(";____BAH_COMPILER_VAR_793[0] = vct;char * ____BAH_COMPILER_VAR_794 =__Bah_multiple_concat(____BAH_COMPILER_VAR_793, 6);code = ____BAH_COMPILER_VAR_794;
}
}

#line 1501 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1502 "/home/alois/Documents/bah-bah/src/parser.bah"
if (isGlobal()) {

#line 1503 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_795 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_795[3] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_795[2] = code;____BAH_COMPILER_VAR_795[1] = "\03\0\0\0"" = ";____BAH_COMPILER_VAR_795[0] = v->name;char * ____BAH_COMPILER_VAR_796 =__Bah_multiple_concat(____BAH_COMPILER_VAR_795, 4);INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_796));
}

#line 1504 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1505 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_797 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_797[2] = code;____BAH_COMPILER_VAR_797[1] = "\03\0\0\0"" = ";____BAH_COMPILER_VAR_797[0] = vct;char * ____BAH_COMPILER_VAR_798 =__Bah_multiple_concat(____BAH_COMPILER_VAR_797, 3);code = ____BAH_COMPILER_VAR_798;
}
}
}

#line 1508 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1509 "/home/alois/Documents/bah-bah/src/parser.bah"
if (isRCPpointerType(v->type)&&(shouldOnlyDecl==false)) {

#line 1510 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_799 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_799[1] = "\06\0\0\0""= null";____BAH_COMPILER_VAR_799[0] = vct;char * ____BAH_COMPILER_VAR_800 =__Bah_multiple_concat(____BAH_COMPILER_VAR_799, 2);code = ____BAH_COMPILER_VAR_800;
}

#line 1511 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1512 "/home/alois/Documents/bah-bah/src/parser.bah"
code = vct;
}
}

#line 1516 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((shouldOnlyDecl==true)) {

#line 1517 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_801 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_801[1] = vct;____BAH_COMPILER_VAR_801[0] = "\07\0\0\0""extern ";char * ____BAH_COMPILER_VAR_802 =__Bah_multiple_concat(____BAH_COMPILER_VAR_801, 2);vct = ____BAH_COMPILER_VAR_802;
}

#line 1520 "/home/alois/Documents/bah-bah/src/parser.bah"
if (isGlobal()) {

#line 1521 "/home/alois/Documents/bah-bah/src/parser.bah"
v->isGlobal = true;
}

#line 1522 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1523 "/home/alois/Documents/bah-bah/src/parser.bah"
v->isGlobal = false;
}

#line 1525 "/home/alois/Documents/bah-bah/src/parser.bah"
v->declScope = elems;

#line 1526 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_803 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_803);
    elems->vars->data[____BAH_COMPILER_VAR_803] = v;

#line 1528 "/home/alois/Documents/bah-bah/src/parser.bah"
if (fixMeEnabled()) {

#line 1529 "/home/alois/Documents/bah-bah/src/parser.bah"
fixMeRegisterVar(v,&ft);
}

#line 1533 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* ____BAH_COMPILER_VAR_804 = v;
char ** ____BAH_COMPILER_VAR_806 = (char **)((char*)(____BAH_COMPILER_VAR_804) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_807 = __reflect(____BAH_COMPILER_VAR_806, sizeof(char *), "\010\0\0\0""cpstring", "\04\0\0\0""name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_808 = (char **)((char*)(____BAH_COMPILER_VAR_804) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_809 = __reflect(____BAH_COMPILER_VAR_808, sizeof(char *), "\010\0\0\0""cpstring", "\04\0\0\0""type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_810 = (char*)((char*)(____BAH_COMPILER_VAR_804) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_811 = __reflect(____BAH_COMPILER_VAR_810, sizeof(char), "\04\0\0\0""bool", "\07\0\0\0""isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_812 = (char **)((char*)(____BAH_COMPILER_VAR_804) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_813 = __reflect(____BAH_COMPILER_VAR_812, sizeof(char *), "\010\0\0\0""cpstring", "\010\0\0\0""constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_814 = (char*)((char*)(____BAH_COMPILER_VAR_804) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_815 = __reflect(____BAH_COMPILER_VAR_814, sizeof(char), "\04\0\0\0""bool", "\07\0\0\0""isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_816 = (char **)((char*)(____BAH_COMPILER_VAR_804) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_817 = __reflect(____BAH_COMPILER_VAR_816, sizeof(char *), "\010\0\0\0""cpstring", "\04\0\0\0""from", 0, 0, 0, 0, offsetof(struct variable, from));
void ** ____BAH_COMPILER_VAR_818 = (void **)((char*)(____BAH_COMPILER_VAR_804) + offsetof(struct variable, declScope));
struct reflectElement ____BAH_COMPILER_VAR_819 = __reflect(____BAH_COMPILER_VAR_818, sizeof(void *), "\03\0\0\0""ptr", "\011\0\0\0""declScope", 0, 0, 0, 0, offsetof(struct variable, declScope));
char* ____BAH_COMPILER_VAR_820 = (char*)((char*)(____BAH_COMPILER_VAR_804) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_821 = __reflect(____BAH_COMPILER_VAR_820, sizeof(char), "\04\0\0\0""bool", "\010\0\0\0""isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));
struct rope** ____BAH_COMPILER_VAR_822 = (struct rope**)((char*)(____BAH_COMPILER_VAR_804) + offsetof(struct variable, declRope));
char ** ____BAH_COMPILER_VAR_824 = (char **)((char*)(____BAH_COMPILER_VAR_822) + offsetof(struct rope, str));
struct reflectElement ____BAH_COMPILER_VAR_825 = __reflect(____BAH_COMPILER_VAR_824, sizeof(char *), "\010\0\0\0""cpstring", "\03\0\0\0""str", 0, 0, 0, 0, offsetof(struct rope, str));
int* ____BAH_COMPILER_VAR_826 = (int*)((char*)(____BAH_COMPILER_VAR_822) + offsetof(struct rope, totalLen));
struct reflectElement ____BAH_COMPILER_VAR_827 = __reflect(____BAH_COMPILER_VAR_826, sizeof(int), "\05\0\0\0""int32", "\010\0\0\0""totalLen", 0, 0, 0, 0, offsetof(struct rope, totalLen));
void ** ____BAH_COMPILER_VAR_828 = (void **)((char*)(____BAH_COMPILER_VAR_822) + offsetof(struct rope, left));
struct reflectElement ____BAH_COMPILER_VAR_829 = __reflect(____BAH_COMPILER_VAR_828, sizeof(void *), "\03\0\0\0""ptr", "\04\0\0\0""left", 0, 0, 0, 0, offsetof(struct rope, left));
void ** ____BAH_COMPILER_VAR_830 = (void **)((char*)(____BAH_COMPILER_VAR_822) + offsetof(struct rope, right));
struct reflectElement ____BAH_COMPILER_VAR_831 = __reflect(____BAH_COMPILER_VAR_830, sizeof(void *), "\03\0\0\0""ptr", "\05\0\0\0""right", 0, 0, 0, 0, offsetof(struct rope, right));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_823 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_823->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_823->length = 4;
        ____BAH_COMPILER_VAR_823->data = memoryAlloc(____BAH_COMPILER_VAR_823->length * ____BAH_COMPILER_VAR_823->elemSize);
        ____BAH_COMPILER_VAR_823->data[0] = ____BAH_COMPILER_VAR_825;
____BAH_COMPILER_VAR_823->data[1] = ____BAH_COMPILER_VAR_827;
____BAH_COMPILER_VAR_823->data[2] = ____BAH_COMPILER_VAR_829;
____BAH_COMPILER_VAR_823->data[3] = ____BAH_COMPILER_VAR_831;
struct reflectElement ____BAH_COMPILER_VAR_832 = __reflect(____BAH_COMPILER_VAR_822, sizeof(struct rope), "\05\0\0\0""rope*", "\010\0\0\0""declRope", 0, 0, 1, ____BAH_COMPILER_VAR_823, offsetof(struct variable, declRope));
char* ____BAH_COMPILER_VAR_833 = (char*)((char*)(____BAH_COMPILER_VAR_804) + offsetof(struct variable, canBeNull));
struct reflectElement ____BAH_COMPILER_VAR_834 = __reflect(____BAH_COMPILER_VAR_833, sizeof(char), "\04\0\0\0""bool", "\011\0\0\0""canBeNull", 0, 0, 0, 0, offsetof(struct variable, canBeNull));
void ** ____BAH_COMPILER_VAR_835 = (void **)((char*)(____BAH_COMPILER_VAR_804) + offsetof(struct variable, iterScope));
struct reflectElement ____BAH_COMPILER_VAR_836 = __reflect(____BAH_COMPILER_VAR_835, sizeof(void *), "\03\0\0\0""ptr", "\011\0\0\0""iterScope", 0, 0, 0, 0, offsetof(struct variable, iterScope));
char* ____BAH_COMPILER_VAR_837 = (char*)((char*)(____BAH_COMPILER_VAR_804) + offsetof(struct variable, canBeReg));
struct reflectElement ____BAH_COMPILER_VAR_838 = __reflect(____BAH_COMPILER_VAR_837, sizeof(char), "\04\0\0\0""bool", "\010\0\0\0""canBeReg", 0, 0, 0, 0, offsetof(struct variable, canBeReg));
char* ____BAH_COMPILER_VAR_839 = (char*)((char*)(____BAH_COMPILER_VAR_804) + offsetof(struct variable, isReg));
struct reflectElement ____BAH_COMPILER_VAR_840 = __reflect(____BAH_COMPILER_VAR_839, sizeof(char), "\04\0\0\0""bool", "\05\0\0\0""isReg", 0, 0, 0, 0, offsetof(struct variable, isReg));
void ** ____BAH_COMPILER_VAR_841 = (void **)((char*)(____BAH_COMPILER_VAR_804) + offsetof(struct variable, lastSet));
struct reflectElement ____BAH_COMPILER_VAR_842 = __reflect(____BAH_COMPILER_VAR_841, sizeof(void *), "\03\0\0\0""ptr", "\07\0\0\0""lastSet", 0, 0, 0, 0, offsetof(struct variable, lastSet));
char* ____BAH_COMPILER_VAR_843 = (char*)((char*)(____BAH_COMPILER_VAR_804) + offsetof(struct variable, isArg));
struct reflectElement ____BAH_COMPILER_VAR_844 = __reflect(____BAH_COMPILER_VAR_843, sizeof(char), "\04\0\0\0""bool", "\05\0\0\0""isArg", 0, 0, 0, 0, offsetof(struct variable, isArg));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_805 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_805->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_805->length = 15;
        ____BAH_COMPILER_VAR_805->data = memoryAlloc(____BAH_COMPILER_VAR_805->length * ____BAH_COMPILER_VAR_805->elemSize);
        ____BAH_COMPILER_VAR_805->data[0] = ____BAH_COMPILER_VAR_807;
____BAH_COMPILER_VAR_805->data[1] = ____BAH_COMPILER_VAR_809;
____BAH_COMPILER_VAR_805->data[2] = ____BAH_COMPILER_VAR_811;
____BAH_COMPILER_VAR_805->data[3] = ____BAH_COMPILER_VAR_813;
____BAH_COMPILER_VAR_805->data[4] = ____BAH_COMPILER_VAR_815;
____BAH_COMPILER_VAR_805->data[5] = ____BAH_COMPILER_VAR_817;
____BAH_COMPILER_VAR_805->data[6] = ____BAH_COMPILER_VAR_819;
____BAH_COMPILER_VAR_805->data[7] = ____BAH_COMPILER_VAR_821;
____BAH_COMPILER_VAR_805->data[8] = ____BAH_COMPILER_VAR_832;
____BAH_COMPILER_VAR_805->data[9] = ____BAH_COMPILER_VAR_834;
____BAH_COMPILER_VAR_805->data[10] = ____BAH_COMPILER_VAR_836;
____BAH_COMPILER_VAR_805->data[11] = ____BAH_COMPILER_VAR_838;
____BAH_COMPILER_VAR_805->data[12] = ____BAH_COMPILER_VAR_840;
____BAH_COMPILER_VAR_805->data[13] = ____BAH_COMPILER_VAR_842;
____BAH_COMPILER_VAR_805->data[14] = ____BAH_COMPILER_VAR_844;
struct reflectElement ____BAH_COMPILER_VAR_845 = __reflect(____BAH_COMPILER_VAR_804, sizeof(struct variable), "\011\0\0\0""variable*", "\01\0\0\0""v", 0, 0, 1, ____BAH_COMPILER_VAR_805, 0);
debugPrint("\017\0\0\0""var_declaration",ft.line,____BAH_COMPILER_VAR_845);

#line 1536 "/home/alois/Documents/bah-bah/src/parser.bah"
if (isGlobal()) {

#line 1537 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_846 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_846[1] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_846[0] = vct;char * ____BAH_COMPILER_VAR_847 =__Bah_multiple_concat(____BAH_COMPILER_VAR_846, 2);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_847));
}
}

#line 1541 "/home/alois/Documents/bah-bah/src/parser.bah"
if (isGlobal()) {

#line 1542 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((isSubObject==false)) {

#line 1543 "/home/alois/Documents/bah-bah/src/parser.bah"
INIT = rope__add(INIT, rope(NEXT_LINE));
}

#line 1545 "/home/alois/Documents/bah-bah/src/parser.bah"
NEXT_LINE = "\0\0\0\0""";
}

#line 1546 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1547 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_848 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_848[1] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_848[0] = code;char * ____BAH_COMPILER_VAR_849 =__Bah_multiple_concat(____BAH_COMPILER_VAR_848, 2);struct rope* declR = rope(____BAH_COMPILER_VAR_849);

#line 1548 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((exists==false)) {

#line 1550 "/home/alois/Documents/bah-bah/src/parser.bah"
v->declRope = declR;

#line 1551 "/home/alois/Documents/bah-bah/src/parser.bah"
v->canBeReg = true;
}

#line 1553 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope__add(OUTPUT, declR);
}
};

#line 1561 "/home/alois/Documents/bah-bah/src/parser.bah"
char * getCfunctionType(struct string* cfrt,char * elemName,struct Elems* elems){

#line 1563 "/home/alois/Documents/bah-bah/src/parser.bah"
struct func* tmpfn = parseFnType(*cfrt);

#line 1564 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string tmpfnRetCType = getCType(tmpfn->returns->type,elems);

#line 1565 "/home/alois/Documents/bah-bah/src/parser.bah"
char * tmpfnArgsCType = "\0\0\0\0""";

#line 1566 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int j = 0;

#line 1566 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((j<len(tmpfn->args))) {

#line 1567 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* arg = tmpfn->args->data[j];

#line 1568 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string ct = getCType(arg->type,elems);

#line 1569 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_850 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_850[1] = string__str(&ct);____BAH_COMPILER_VAR_850[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_851 =__Bah_multiple_concat(____BAH_COMPILER_VAR_850, 2);tmpfnArgsCType = ____BAH_COMPILER_VAR_851;

#line 1570 "/home/alois/Documents/bah-bah/src/parser.bah"
j = j+1;

#line 1571 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((j<len(tmpfn->args))) {

#line 1572 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_852 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_852[1] = "\01\0\0\0"",";____BAH_COMPILER_VAR_852[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_853 =__Bah_multiple_concat(____BAH_COMPILER_VAR_852, 2);tmpfnArgsCType = ____BAH_COMPILER_VAR_853;
}
};

#line 1576 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_854 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_854[5] = "\01\0\0\0"")";____BAH_COMPILER_VAR_854[4] = tmpfnArgsCType;____BAH_COMPILER_VAR_854[3] = "\02\0\0\0"")(";____BAH_COMPILER_VAR_854[2] = elemName;____BAH_COMPILER_VAR_854[1] = "\03\0\0\0"" (*";____BAH_COMPILER_VAR_854[0] = string__str(&tmpfnRetCType);char * ____BAH_COMPILER_VAR_855 =__Bah_multiple_concat(____BAH_COMPILER_VAR_854, 6);return ____BAH_COMPILER_VAR_855;
};

#line 1580 "/home/alois/Documents/bah-bah/src/parser.bah"
char ____BAH_COMPILER_VAR_866(array(char *)* arr, char * el) {
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
char ____BAH_COMPILER_VAR_885(array(char *)* arr, char * el) {
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
char * parseFnHeader(char * prev,__BAH_ARR_TYPE_Tok l,long int* i,struct func* fn,struct Elems* elems){

#line 1582 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int j = *i;

#line 1583 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok ft = l->data[j];

#line 1584 "/home/alois/Documents/bah-bah/src/parser.bah"
char * tpdf = "\0\0\0\0""";

#line 1585 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((ft.type!=TOKEN_TYPE_VAR), 0)) {

#line 1586 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&ft,"\044\0\0\0""Cannot use {TOKEN} as function name.");
}

#line 1588 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_856 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_856[1] = ft.cont;____BAH_COMPILER_VAR_856[0] = prev;char * ____BAH_COMPILER_VAR_857 =__Bah_multiple_concat(____BAH_COMPILER_VAR_856, 2);fn->name = ____BAH_COMPILER_VAR_857;

#line 1590 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct variable*)* arguments = memoryAlloc(sizeof(array(struct variable*)));

arguments->length = 0;
arguments->elemSize = sizeof(struct variable*);

#line 1592 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_858 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_858[1] = "\01\0\0\0""(";____BAH_COMPILER_VAR_858[0] = fn->name;char * ____BAH_COMPILER_VAR_859 =__Bah_multiple_concat(____BAH_COMPILER_VAR_858, 2);char * code = ____BAH_COMPILER_VAR_859;

#line 1595 "/home/alois/Documents/bah-bah/src/parser.bah"
j = j+2;

#line 1597 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = l->data[j];

#line 1598 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "\01\0\0\0"")") != 0)) {

#line 1600 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((j<len(l))) {

#line 1601 "/home/alois/Documents/bah-bah/src/parser.bah"
t = l->data[j];

#line 1602 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((t.type!=TOKEN_TYPE_VAR), 0)) {

#line 1603 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"\044\0\0\0""Cannot use {TOKEN} as argument name.");
}

#line 1605 "/home/alois/Documents/bah-bah/src/parser.bah"
char * argName = t.cont;

#line 1607 "/home/alois/Documents/bah-bah/src/parser.bah"
j = j+1;

#line 1608 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((j>=len(l)), 0)) {

#line 1609 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"\057\0\0\0""Cannot declare argument {TOKEN} without a type.");
}

#line 1611 "/home/alois/Documents/bah-bah/src/parser.bah"
t = l->data[j];

#line 1612 "/home/alois/Documents/bah-bah/src/parser.bah"
char * argType = t.cont;

#line 1614 "/home/alois/Documents/bah-bah/src/parser.bah"
j = j+1;

#line 1615 "/home/alois/Documents/bah-bah/src/parser.bah"
char isComa = false;

#line 1616 "/home/alois/Documents/bah-bah/src/parser.bah"
long int nbPars = 1;

#line 1617 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((j<len(l))) {

#line 1618 "/home/alois/Documents/bah-bah/src/parser.bah"
t = l->data[j];

#line 1619 "/home/alois/Documents/bah-bah/src/parser.bah"
isComa = false;

#line 1620 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "\01\0\0\0"",") != 0)) {

#line 1621 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "\01\0\0\0""(") == 0)) {

#line 1622 "/home/alois/Documents/bah-bah/src/parser.bah"
nbPars = nbPars+1;
}

#line 1623 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(t.cont, "\01\0\0\0"")") == 0)) {

#line 1624 "/home/alois/Documents/bah-bah/src/parser.bah"
nbPars = nbPars-1;
}

#line 1626 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "\01\0\0\0"")") == 0)&&(nbPars==0)) {

#line 1627 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}

#line 1628 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1629 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_860 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_860[1] = t.cont;____BAH_COMPILER_VAR_860[0] = argType;char * ____BAH_COMPILER_VAR_861 =__Bah_multiple_concat(____BAH_COMPILER_VAR_860, 2);argType = ____BAH_COMPILER_VAR_861;
}
}

#line 1631 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1632 "/home/alois/Documents/bah-bah/src/parser.bah"
isComa = true;

#line 1633 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}

#line 1635 "/home/alois/Documents/bah-bah/src/parser.bah"
j = j+1;
};

#line 1638 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* ____BAH_COMPILER_VAR_862 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_862->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_862->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_862->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_862->from = "\0\0\0\0""";
struct variable* argument = ____BAH_COMPILER_VAR_862;

#line 1639 "/home/alois/Documents/bah-bah/src/parser.bah"
argument->name = argName;

#line 1640 "/home/alois/Documents/bah-bah/src/parser.bah"
argument->type = argType;

#line 1641 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_863 = len(arguments);
    __Bah_realocate_arr(arguments, ____BAH_COMPILER_VAR_863);
    arguments->data[____BAH_COMPILER_VAR_863] = argument;

#line 1644 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string argCType = getCType(argType,elems);

#line 1646 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string cfrt = string(argType);

#line 1647 "/home/alois/Documents/bah-bah/src/parser.bah"
char * newArgType = string__str(&argCType);

#line 1648 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((string__hasPrefix(&cfrt,"\02\0\0\0""[]")==1)) {

#line 1649 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimLeft(&cfrt,2);

#line 1650 "/home/alois/Documents/bah-bah/src/parser.bah"
if (string__hasSuffix(&cfrt,"\01\0\0\0""*")) {

#line 1651 "/home/alois/Documents/bah-bah/src/parser.bah"
long int nbast = string__count(&cfrt,"\01\0\0\0""*");

#line 1652 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimRight(&cfrt,nbast);
}

#line 1654 "/home/alois/Documents/bah-bah/src/parser.bah"
string__replace(&cfrt,"\02\0\0\0""[]","\05\0\0\0""_ARR_");

#line 1655 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_864 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_864[1] = string__str(&cfrt);____BAH_COMPILER_VAR_864[0] = "\017\0\0\0""__BAH_ARR_TYPE_";char * ____BAH_COMPILER_VAR_865 =__Bah_multiple_concat(____BAH_COMPILER_VAR_864, 2);newArgType = ____BAH_COMPILER_VAR_865;

#line 1656 "/home/alois/Documents/bah-bah/src/parser.bah"
array(char *)* csatd = compilerState.arrTypesDecl;

#line 1657 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((____BAH_COMPILER_VAR_866(csatd, newArgType)==false)) {

#line 1658 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_867 = len(csatd);
    __Bah_realocate_arr(csatd, ____BAH_COMPILER_VAR_867);
    csatd->data[____BAH_COMPILER_VAR_867] = newArgType;

#line 1659 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_868 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_868[5] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_868[4] = newArgType;____BAH_COMPILER_VAR_868[3] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_868[2] = string__str(&argCType);____BAH_COMPILER_VAR_868[1] = "\010\0\0\0""typedef ";____BAH_COMPILER_VAR_868[0] = tpdf;char * ____BAH_COMPILER_VAR_869 =__Bah_multiple_concat(____BAH_COMPILER_VAR_868, 6);tpdf = ____BAH_COMPILER_VAR_869;
}
}

#line 1662 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((string__hasPrefix(&cfrt,"\011\0\0\0""function(")==1)) {

#line 1663 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_870 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_870[1] = getCfunctionType(&cfrt,argName,elems);____BAH_COMPILER_VAR_870[0] = code;char * ____BAH_COMPILER_VAR_871 =__Bah_multiple_concat(____BAH_COMPILER_VAR_870, 2);code = ____BAH_COMPILER_VAR_871;
}

#line 1664 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1665 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_872 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_872[3] = argName;____BAH_COMPILER_VAR_872[2] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_872[1] = newArgType;____BAH_COMPILER_VAR_872[0] = code;char * ____BAH_COMPILER_VAR_873 =__Bah_multiple_concat(____BAH_COMPILER_VAR_872, 4);code = ____BAH_COMPILER_VAR_873;
}

#line 1667 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((isComa==true)) {

#line 1668 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_874 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_874[1] = "\01\0\0\0"",";____BAH_COMPILER_VAR_874[0] = code;char * ____BAH_COMPILER_VAR_875 =__Bah_multiple_concat(____BAH_COMPILER_VAR_874, 2);code = ____BAH_COMPILER_VAR_875;
}

#line 1669 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1670 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_876 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_876[1] = "\01\0\0\0"")";____BAH_COMPILER_VAR_876[0] = code;char * ____BAH_COMPILER_VAR_877 =__Bah_multiple_concat(____BAH_COMPILER_VAR_876, 2);code = ____BAH_COMPILER_VAR_877;

#line 1671 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}

#line 1673 "/home/alois/Documents/bah-bah/src/parser.bah"
j = j+1;
};
}

#line 1675 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1676 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_878 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_878[1] = "\01\0\0\0"")";____BAH_COMPILER_VAR_878[0] = code;char * ____BAH_COMPILER_VAR_879 =__Bah_multiple_concat(____BAH_COMPILER_VAR_878, 2);code = ____BAH_COMPILER_VAR_879;
}

#line 1679 "/home/alois/Documents/bah-bah/src/parser.bah"
j = j+1;

#line 1681 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* ____BAH_COMPILER_VAR_880 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_880->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_880->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_880->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_880->from = "\0\0\0\0""";
struct variable* returns = ____BAH_COMPILER_VAR_880;

#line 1682 "/home/alois/Documents/bah-bah/src/parser.bah"
returns->type = "\0\0\0\0""";

#line 1683 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((j<len(l))) {

#line 1684 "/home/alois/Documents/bah-bah/src/parser.bah"
t = l->data[j];

#line 1685 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "\01\0\0\0""{") == 0)) {

#line 1686 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}

#line 1688 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_881 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_881[1] = t.cont;____BAH_COMPILER_VAR_881[0] = returns->type;char * ____BAH_COMPILER_VAR_882 =__Bah_multiple_concat(____BAH_COMPILER_VAR_881, 2);returns->type = ____BAH_COMPILER_VAR_882;

#line 1689 "/home/alois/Documents/bah-bah/src/parser.bah"
j = j+1;
};

#line 1691 "/home/alois/Documents/bah-bah/src/parser.bah"
if (strlen(returns->type)) {

#line 1692 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string rts = string(returns->type);

#line 1693 "/home/alois/Documents/bah-bah/src/parser.bah"
string__replace(&rts,"\01\0\0\0"" ","\0\0\0\0""");

#line 1694 "/home/alois/Documents/bah-bah/src/parser.bah"
returns->type = rts.content;
}

#line 1696 "/home/alois/Documents/bah-bah/src/parser.bah"
*i = j;

#line 1697 "/home/alois/Documents/bah-bah/src/parser.bah"
returns->name = fn->name;

#line 1698 "/home/alois/Documents/bah-bah/src/parser.bah"
fn->returns = returns;

#line 1699 "/home/alois/Documents/bah-bah/src/parser.bah"
fn->args = arguments;

#line 1701 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string fnRetType = getCType(returns->type,elems);

#line 1702 "/home/alois/Documents/bah-bah/src/parser.bah"
char * newFnRetType = string__str(&fnRetType);

#line 1704 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string cfrt = string(returns->type);

#line 1705 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((string__hasPrefix(&cfrt,"\02\0\0\0""[]")==1)) {

#line 1706 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimLeft(&cfrt,2);

#line 1707 "/home/alois/Documents/bah-bah/src/parser.bah"
if (string__hasSuffix(&cfrt,"\01\0\0\0""*")) {

#line 1708 "/home/alois/Documents/bah-bah/src/parser.bah"
long int nbast = string__count(&cfrt,"\01\0\0\0""*");

#line 1709 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimRight(&cfrt,nbast);
}

#line 1711 "/home/alois/Documents/bah-bah/src/parser.bah"
string__replace(&cfrt,"\02\0\0\0""[]","\05\0\0\0""_ARR_");

#line 1712 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_883 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_883[1] = string__str(&cfrt);____BAH_COMPILER_VAR_883[0] = "\017\0\0\0""__BAH_ARR_TYPE_";char * ____BAH_COMPILER_VAR_884 =__Bah_multiple_concat(____BAH_COMPILER_VAR_883, 2);newFnRetType = ____BAH_COMPILER_VAR_884;

#line 1713 "/home/alois/Documents/bah-bah/src/parser.bah"
array(char *)* csatd = compilerState.arrTypesDecl;

#line 1714 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((____BAH_COMPILER_VAR_885(csatd, newFnRetType)==false)) {

#line 1715 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_886 = len(csatd);
    __Bah_realocate_arr(csatd, ____BAH_COMPILER_VAR_886);
    csatd->data[____BAH_COMPILER_VAR_886] = newFnRetType;

#line 1716 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_887 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_887[5] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_887[4] = newFnRetType;____BAH_COMPILER_VAR_887[3] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_887[2] = string__str(&fnRetType);____BAH_COMPILER_VAR_887[1] = "\010\0\0\0""typedef ";____BAH_COMPILER_VAR_887[0] = tpdf;char * ____BAH_COMPILER_VAR_888 =__Bah_multiple_concat(____BAH_COMPILER_VAR_887, 6);tpdf = ____BAH_COMPILER_VAR_888;
}
}

#line 1719 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_889 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_889[3] = code;____BAH_COMPILER_VAR_889[2] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_889[1] = newFnRetType;____BAH_COMPILER_VAR_889[0] = tpdf;char * ____BAH_COMPILER_VAR_890 =__Bah_multiple_concat(____BAH_COMPILER_VAR_889, 4);code = ____BAH_COMPILER_VAR_890;

#line 1723 "/home/alois/Documents/bah-bah/src/parser.bah"
return code;
};

#line 1726 "/home/alois/Documents/bah-bah/src/parser.bah"
void parseStruct(__BAH_ARR_TYPE_Tok l,struct Elems* elems){

#line 1728 "/home/alois/Documents/bah-bah/src/parser.bah"
struct cStruct* ____BAH_COMPILER_VAR_891 = memoryAlloc(sizeof(struct cStruct));
____BAH_COMPILER_VAR_891->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_891->members = memoryAlloc(sizeof(array(struct structMemb*)));
            ____BAH_COMPILER_VAR_891->members->length = 0;
            ____BAH_COMPILER_VAR_891->members->elemSize = sizeof(struct structMemb*);
            ____BAH_COMPILER_VAR_891->methods = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_891->methods->length = 0;
            ____BAH_COMPILER_VAR_891->methods->elemSize = sizeof(struct func*);
            ____BAH_COMPILER_VAR_891->postCode = "\0\0\0\0""";
____BAH_COMPILER_VAR_891->extendedFrom = "\0\0\0\0""";
struct cStruct* s = ____BAH_COMPILER_VAR_891;

#line 1729 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct cStruct*)* structs = elems->structs;

#line 1730 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_892 = len(structs);
    __Bah_realocate_arr(structs, ____BAH_COMPILER_VAR_892);
    structs->data[____BAH_COMPILER_VAR_892] = s;

#line 1731 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct func*)* methds = s->methods;

#line 1732 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((len(l)<4), 0)) {

#line 1733 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&l->data[len(l)-1],"\130\0\0\0""Cannot declare struct has such, please do 'struct <name> { <memberName>:<memberType> }'.");
}

#line 1735 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok nameToken = l->data[1];

#line 1736 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int i = 2;

#line 1737 "/home/alois/Documents/bah-bah/src/parser.bah"
char doesOutput = true;

#line 1738 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(nameToken.cont, "\01\0\0\0""!") == 0)) {

#line 1739 "/home/alois/Documents/bah-bah/src/parser.bah"
nameToken = l->data[2];

#line 1740 "/home/alois/Documents/bah-bah/src/parser.bah"
i = 3;

#line 1741 "/home/alois/Documents/bah-bah/src/parser.bah"
doesOutput = false;

#line 1742 "/home/alois/Documents/bah-bah/src/parser.bah"
s->isBinding = true;
}

#line 1744 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((nameToken.type!=TOKEN_TYPE_VAR), 0)) {

#line 1745 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&nameToken,"\042\0\0\0""Cannot use {TOKEN} as struct name.");
}

#line 1747 "/home/alois/Documents/bah-bah/src/parser.bah"
struct cStruct* os = searchStruct(nameToken.cont,elems);

#line 1748 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((os!=null), 0)) {

#line 1749 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&nameToken,"\036\0\0\0""Struct {TOKEN} already exists.");
}

#line 1751 "/home/alois/Documents/bah-bah/src/parser.bah"
s->name = nameToken.cont;

#line 1752 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct structMemb*)* members = s->members;

#line 1753 "/home/alois/Documents/bah-bah/src/parser.bah"
currentCStruct = s;

#line 1754 "/home/alois/Documents/bah-bah/src/parser.bah"
array(char *)* allMembs = memoryAlloc(sizeof(array(char *)));

allMembs->length = 0;
allMembs->elemSize = sizeof(char *);

#line 1755 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok st = l->data[i];

#line 1756 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((st.type==TOKEN_TYPE_KEYWORD)) {

#line 1757 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(st.cont, "\06\0\0\0""extend") == 0)) {

#line 1758 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 1759 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok extdSNameTk = l->data[i];

#line 1760 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 1761 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((extdSNameTk.type!=TOKEN_TYPE_VAR), 0)) {

#line 1762 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&extdSNameTk,"\042\0\0\0""Cannot use {TOKEN} as struct name.");
}

#line 1764 "/home/alois/Documents/bah-bah/src/parser.bah"
struct cStruct* extdS = searchStruct(extdSNameTk.cont,elems);

#line 1765 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((extdS==null), 0)) {

#line 1766 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&extdSNameTk,"\036\0\0\0""Struct {TOKEN} does not exist.");
}

#line 1768 "/home/alois/Documents/bah-bah/src/parser.bah"
s->extendedFrom = extdS->name;

#line 1769 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct structMemb*)* extdsmbs = extdS->members;

#line 1770 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int j = 0;

#line 1770 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((j<len(extdsmbs))) {

#line 1771 "/home/alois/Documents/bah-bah/src/parser.bah"
struct structMemb* em = extdsmbs->data[j];

#line 1772 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string cemt = string(em->type);

#line 1773 "/home/alois/Documents/bah-bah/src/parser.bah"
char * membDeclStr= null;

#line 1774 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((string__hasPrefix(&cemt,"\011\0\0\0""function(")==1)) {

#line 1775 "/home/alois/Documents/bah-bah/src/parser.bah"
struct func* tmpfn = parseFnType(cemt);

#line 1776 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string tmpfnRetCType = getCType(tmpfn->returns->type,elems);

#line 1777 "/home/alois/Documents/bah-bah/src/parser.bah"
char * tmpfnArgsCType = "\0\0\0\0""";

#line 1778 "/home/alois/Documents/bah-bah/src/parser.bah"
j = 0;

#line 1778 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((j<len(tmpfn->args))) {

#line 1779 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* arg = tmpfn->args->data[j];

#line 1780 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string ct = getCType(arg->type,elems);

#line 1781 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_893 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_893[1] = string__str(&ct);____BAH_COMPILER_VAR_893[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_894 =__Bah_multiple_concat(____BAH_COMPILER_VAR_893, 2);tmpfnArgsCType = ____BAH_COMPILER_VAR_894;

#line 1782 "/home/alois/Documents/bah-bah/src/parser.bah"
j = j+1;

#line 1783 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((j<len(tmpfn->args))) {

#line 1784 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_895 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_895[1] = "\01\0\0\0"",";____BAH_COMPILER_VAR_895[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_896 =__Bah_multiple_concat(____BAH_COMPILER_VAR_895, 2);tmpfnArgsCType = ____BAH_COMPILER_VAR_896;
}
};

#line 1787 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_897 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_897[5] = "\01\0\0\0"")";____BAH_COMPILER_VAR_897[4] = tmpfnArgsCType;____BAH_COMPILER_VAR_897[3] = "\02\0\0\0"")(";____BAH_COMPILER_VAR_897[2] = em->name;____BAH_COMPILER_VAR_897[1] = "\03\0\0\0"" (*";____BAH_COMPILER_VAR_897[0] = string__str(&tmpfnRetCType);char * ____BAH_COMPILER_VAR_898 =__Bah_multiple_concat(____BAH_COMPILER_VAR_897, 6);membDeclStr = ____BAH_COMPILER_VAR_898;
}

#line 1788 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1789 "/home/alois/Documents/bah-bah/src/parser.bah"
if (isRCPpointerType(em->type)) {

#line 1790 "/home/alois/Documents/bah-bah/src/parser.bah"
s->hasRCPmemb = true;
}

#line 1792 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string membDecl = getCType(em->type,elems);

#line 1793 "/home/alois/Documents/bah-bah/src/parser.bah"
string__append(&membDecl,"\01\0\0\0"" ");

#line 1794 "/home/alois/Documents/bah-bah/src/parser.bah"
string__append(&membDecl,em->name);

#line 1795 "/home/alois/Documents/bah-bah/src/parser.bah"
membDeclStr = membDecl.content;
}

#line 1797 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_899 = len(allMembs);
    __Bah_realocate_arr(allMembs, ____BAH_COMPILER_VAR_899);
    allMembs->data[____BAH_COMPILER_VAR_899] = membDeclStr;

#line 1798 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_900 = len(members);
    __Bah_realocate_arr(members, ____BAH_COMPILER_VAR_900);
    members->data[____BAH_COMPILER_VAR_900] = em;

#line 1799 "/home/alois/Documents/bah-bah/src/parser.bah"
j = j+1;
};
}

#line 1801 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1802 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&st,"\061\0\0\0""Cannot use keyword {TOKEN} in struct declaration.");
}
}

#line 1805 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok braceTk = l->data[i];

#line 1806 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 1807 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((strcmp(braceTk.cont, "\01\0\0\0""{") != 0), 0)) {

#line 1808 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&braceTk,"\051\0\0\0""Cannot use {TOKEN} in struct declaration.");
}

#line 1810 "/home/alois/Documents/bah-bah/src/parser.bah"
postDeclHandle = rope("\0\0\0\0""");

#line 1811 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope__add(OUTPUT, postDeclHandle);

#line 1812 "/home/alois/Documents/bah-bah/src/parser.bah"
struct rope* OOUT = OUTPUT;

#line 1813 "/home/alois/Documents/bah-bah/src/parser.bah"
char * nextLine = "\0\0\0\0""";

#line 1814 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int j = 0;

#line 1814 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (j<len(l)); 
#line 1814 "/home/alois/Documents/bah-bah/src/parser.bah"
++j) {

#line 1815 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((l->data[j].type==TOKEN_TYPE_STR)&&(l->data[j].processedStr==false)) {

#line 1816 "/home/alois/Documents/bah-bah/src/parser.bah"
l->data[j].cont = strLitteralToBahStr(l->data[j].cont);

#line 1817 "/home/alois/Documents/bah-bah/src/parser.bah"
l->data[j].processedStr = true;
}
};

#line 1820 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i<len(l))) {

#line 1821 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = l->data[i];

#line 1822 "/home/alois/Documents/bah-bah/src/parser.bah"
long int max = i+2;

#line 1823 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((max>=len(l)), 0)) {

#line 1824 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((t.type==TOKEN_TYPE_ENCL)&&(strcmp(t.cont, "\01\0\0\0""}") == 0)) {

#line 1825 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}

#line 1827 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&l->data[len(l)-1],"\075\0\0\0""Not enough argument in member declaration, ending by {TOKEN}.");
}

#line 1829 "/home/alois/Documents/bah-bah/src/parser.bah"
struct structMemb* ____BAH_COMPILER_VAR_901 = memoryAlloc(sizeof(struct structMemb));
____BAH_COMPILER_VAR_901->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_901->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_901->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_901->from = "\0\0\0\0""";
____BAH_COMPILER_VAR_901->def = "\0\0\0\0""";
struct structMemb* memb = ____BAH_COMPILER_VAR_901;

#line 1830 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((t.type!=TOKEN_TYPE_VAR), 0)) {

#line 1831 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"\042\0\0\0""Cannot use {TOKEN} as member name.");
}

#line 1833 "/home/alois/Documents/bah-bah/src/parser.bah"
memb->name = t.cont;

#line 1834 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int ii = 0;

#line 1834 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((ii<len(members))) {

#line 1835 "/home/alois/Documents/bah-bah/src/parser.bah"
struct structMemb* m = members->data[ii];

#line 1836 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((strcmp(m->name, memb->name) == 0), 0)) {

#line 1837 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"\051\0\0\0""Member {TOKEN} has already been declared.");
}

#line 1839 "/home/alois/Documents/bah-bah/src/parser.bah"
ii = ii+1;
};

#line 1841 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 1842 "/home/alois/Documents/bah-bah/src/parser.bah"
t = l->data[i];

#line 1843 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "\01\0\0\0"":") != 0)) {

#line 1844 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((strcmp(t.cont, "\01\0\0\0""(") != 0), 0)) {

#line 1845 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"\062\0\0\0""Member name should be followed by ':' not {TOKEN}.");
}

#line 1846 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1847 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_902 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_902[1] = "\02\0\0\0""__";____BAH_COMPILER_VAR_902[0] = s->name;char * ____BAH_COMPILER_VAR_903 =__Bah_multiple_concat(____BAH_COMPILER_VAR_902, 2);char * fnPrefix = ____BAH_COMPILER_VAR_903;

#line 1848 "/home/alois/Documents/bah-bah/src/parser.bah"
struct func* ____BAH_COMPILER_VAR_904 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_904->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_904->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_904->args->length = 0;
            ____BAH_COMPILER_VAR_904->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_904->from = "\0\0\0\0""";
____BAH_COMPILER_VAR_904->file = "\0\0\0\0""";
____BAH_COMPILER_VAR_904->line = 1;
struct func* fn = ____BAH_COMPILER_VAR_904;

#line 1849 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);

#line 1850 "/home/alois/Documents/bah-bah/src/parser.bah"
j = i-1;

#line 1850 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((j<len(l))) {

#line 1851 "/home/alois/Documents/bah-bah/src/parser.bah"
t = l->data[j];

#line 1852 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "\01\0\0\0""{") == 0)) {

#line 1853 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}

#line 1855 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_905 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_905);
    nl->data[____BAH_COMPILER_VAR_905] = t;

#line 1856 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((j==i)) {

#line 1857 "/home/alois/Documents/bah-bah/src/parser.bah"
t.type = TOKEN_TYPE_VAR;

#line 1858 "/home/alois/Documents/bah-bah/src/parser.bah"
t.cont = "\04\0\0\0""this";

#line 1859 "/home/alois/Documents/bah-bah/src/parser.bah"
t.isValue = true;

#line 1860 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_906 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_906);
    nl->data[____BAH_COMPILER_VAR_906] = t;

#line 1862 "/home/alois/Documents/bah-bah/src/parser.bah"
t.type = TOKEN_TYPE_VAR;

#line 1863 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_907 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_907[1] = "\01\0\0\0""*";____BAH_COMPILER_VAR_907[0] = s->name;char * ____BAH_COMPILER_VAR_908 =__Bah_multiple_concat(____BAH_COMPILER_VAR_907, 2);t.cont = ____BAH_COMPILER_VAR_908;

#line 1864 "/home/alois/Documents/bah-bah/src/parser.bah"
t.isValue = true;

#line 1865 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_909 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_909);
    nl->data[____BAH_COMPILER_VAR_909] = t;

#line 1867 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok nt = l->data[j+1];

#line 1868 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(nt.cont, "\01\0\0\0"")") != 0)) {

#line 1869 "/home/alois/Documents/bah-bah/src/parser.bah"
t.type = TOKEN_TYPE_SYNTAX;

#line 1870 "/home/alois/Documents/bah-bah/src/parser.bah"
t.cont = "\01\0\0\0"",";

#line 1871 "/home/alois/Documents/bah-bah/src/parser.bah"
t.isValue = false;

#line 1872 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_910 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_910);
    nl->data[____BAH_COMPILER_VAR_910] = t;
}
}

#line 1875 "/home/alois/Documents/bah-bah/src/parser.bah"
j = j+1;
};

#line 1877 "/home/alois/Documents/bah-bah/src/parser.bah"
--i;

#line 1879 "/home/alois/Documents/bah-bah/src/parser.bah"
long int nli = 0;

#line 1881 "/home/alois/Documents/bah-bah/src/parser.bah"
struct rope* code = rope(parseFnHeader(fnPrefix,nl,&nli,fn,elems));

#line 1882 "/home/alois/Documents/bah-bah/src/parser.bah"
i = i+nli;

#line 1883 "/home/alois/Documents/bah-bah/src/parser.bah"
i = i-2;

#line 1885 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* returns = fn->returns;

#line 1886 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct variable*)* arguments = fn->args;

#line 1887 "/home/alois/Documents/bah-bah/src/parser.bah"
fn->from = s->name;

#line 1888 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((shouldOnlyDecl==true)) {

#line 1889 "/home/alois/Documents/bah-bah/src/parser.bah"
code = rope__add(code, rope("\02\0\0\0"";\n"));
}

#line 1890 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1891 "/home/alois/Documents/bah-bah/src/parser.bah"
code = rope__add(code, rope("\02\0\0\0""{\n"));
}

#line 1894 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Elems* fnElems = dupElems(elems);

#line 1895 "/home/alois/Documents/bah-bah/src/parser.bah"
j = 0;

#line 1895 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (j<len(arguments)); 
#line 1895 "/home/alois/Documents/bah-bah/src/parser.bah"
++j) {

#line 1896 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* a = arguments->data[j];

#line 1897 "/home/alois/Documents/bah-bah/src/parser.bah"
a->declScope = elems;

#line 1898 "/home/alois/Documents/bah-bah/src/parser.bah"
a->isArg = true;

#line 1899 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_911 = len(fnElems->vars);
    __Bah_realocate_arr(fnElems->vars, ____BAH_COMPILER_VAR_911);
    fnElems->vars->data[____BAH_COMPILER_VAR_911] = a;
};

#line 1902 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct func*)* fns = elems->fns;

#line 1903 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_912 = len(fns);
    __Bah_realocate_arr(fns, ____BAH_COMPILER_VAR_912);
    fns->data[____BAH_COMPILER_VAR_912] = fn;

#line 1905 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct Tok)* tokens = memoryAlloc(sizeof(array(struct Tok)));

tokens->length = 0;
tokens->elemSize = sizeof(struct Tok);

#line 1906 "/home/alois/Documents/bah-bah/src/parser.bah"
long int nbBraces = 1;

#line 1907 "/home/alois/Documents/bah-bah/src/parser.bah"
t = l->data[i];

#line 1908 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "\01\0\0\0""{") == 0)) {

#line 1909 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;
}

#line 1911 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i<len(l))) {

#line 1912 "/home/alois/Documents/bah-bah/src/parser.bah"
t = l->data[i];

#line 1913 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "\01\0\0\0""{") == 0)) {

#line 1914 "/home/alois/Documents/bah-bah/src/parser.bah"
nbBraces = nbBraces+1;
}

#line 1915 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(t.cont, "\01\0\0\0""}") == 0)) {

#line 1916 "/home/alois/Documents/bah-bah/src/parser.bah"
nbBraces = nbBraces-1;
}

#line 1918 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((nbBraces==0)) {

#line 1919 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}

#line 1921 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_913 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_913);
    tokens->data[____BAH_COMPILER_VAR_913] = t;

#line 1922 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;
};

#line 1926 "/home/alois/Documents/bah-bah/src/parser.bah"
struct func* ____BAH_COMPILER_VAR_914 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_914->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_914->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_914->args->length = 0;
            ____BAH_COMPILER_VAR_914->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_914->from = "\0\0\0\0""";
____BAH_COMPILER_VAR_914->file = "\0\0\0\0""";
____BAH_COMPILER_VAR_914->line = 1;
struct func* mfn = ____BAH_COMPILER_VAR_914;

#line 1927 "/home/alois/Documents/bah-bah/src/parser.bah"
mfn->args = fn->args;

#line 1928 "/home/alois/Documents/bah-bah/src/parser.bah"
mfn->name = fn->name;

#line 1929 "/home/alois/Documents/bah-bah/src/parser.bah"
mfn->returns = fn->returns;

#line 1930 "/home/alois/Documents/bah-bah/src/parser.bah"
mfn->from = s->name;

#line 1932 "/home/alois/Documents/bah-bah/src/parser.bah"
strTrimLeft(&mfn->name,strlen(fnPrefix));

#line 1934 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_915 = len(methds);
    __Bah_realocate_arr(methds, ____BAH_COMPILER_VAR_915);
    methds->data[____BAH_COMPILER_VAR_915] = mfn;

#line 1937 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((shouldOnlyDecl==false)) {

#line 1938 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((len(tokens)==0)) {

#line 1939 "/home/alois/Documents/bah-bah/src/parser.bah"
code = rope__add(code, rope("\03\0\0\0""};\n"));
}

#line 1940 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1941 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope("\0\0\0\0""");

#line 1942 "/home/alois/Documents/bah-bah/src/parser.bah"
currentFn = fn;

#line 1943 "/home/alois/Documents/bah-bah/src/parser.bah"
beginRCPscope(fnElems,fn->args);

#line 1944 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Elems* ocurrFnElems = compilerState.currFnElems;

#line 1945 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.currFnElems = fnElems;

#line 1946 "/home/alois/Documents/bah-bah/src/parser.bah"
parseLines(tokens,fnElems);

#line 1947 "/home/alois/Documents/bah-bah/src/parser.bah"
OPTI_checkFuncScopeRef(fnElems);

#line 1948 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.currFnElems = ocurrFnElems;

#line 1950 "/home/alois/Documents/bah-bah/src/parser.bah"
currentFn = null;

#line 1951 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((fn->returned==false)) {

#line 1952 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((strlen(fn->returns->type)>0), 0)) {

#line 1953 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_916 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_916[2] = "\022\0\0\0""' is not returned.";____BAH_COMPILER_VAR_916[1] = fn->name;____BAH_COMPILER_VAR_916[0] = "\012\0\0\0""Function '";char * ____BAH_COMPILER_VAR_917 =__Bah_multiple_concat(____BAH_COMPILER_VAR_916, 3);throwErr(&l->data[len(l)-1],____BAH_COMPILER_VAR_917);
}

#line 1955 "/home/alois/Documents/bah-bah/src/parser.bah"
endRCPscope(fnElems,fn->args);

#line 1956 "/home/alois/Documents/bah-bah/src/parser.bah"
fixMeEndScope(fnElems,&tokens->data[len(tokens)-1]);
}

#line 1959 "/home/alois/Documents/bah-bah/src/parser.bah"
code = rope__add(code, rope__add(OUTPUT, rope("\03\0\0\0""};\n")));
}
}

#line 1961 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1962 "/home/alois/Documents/bah-bah/src/parser.bah"
fn->isImported = true;

#line 1962 "/home/alois/Documents/bah-bah/src/parser.bah"
mfn->isImported = true;
}

#line 1965 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((doesOutput==true)) {

#line 1966 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_918 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_918[1] = rope__toStr(code);____BAH_COMPILER_VAR_918[0] = nextLine;char * ____BAH_COMPILER_VAR_919 =__Bah_multiple_concat(____BAH_COMPILER_VAR_918, 2);nextLine = ____BAH_COMPILER_VAR_919;
}

#line 1985 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 1986 "/home/alois/Documents/bah-bah/src/parser.bah"
continue;
}
}

#line 1990 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 1991 "/home/alois/Documents/bah-bah/src/parser.bah"
char * mbmType = "\0\0\0\0""";

#line 1992 "/home/alois/Documents/bah-bah/src/parser.bah"
unsigned int currentLine = t.line;

#line 1993 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i<len(l))) {

#line 1994 "/home/alois/Documents/bah-bah/src/parser.bah"
t = l->data[i];

#line 1995 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "\01\0\0\0""=") == 0)) {

#line 1996 "/home/alois/Documents/bah-bah/src/parser.bah"
--i;

#line 1997 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}

#line 1999 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((t.line!=currentLine)) {

#line 2000 "/home/alois/Documents/bah-bah/src/parser.bah"
--i;

#line 2001 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}

#line 2003 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_920 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_920[1] = t.cont;____BAH_COMPILER_VAR_920[0] = mbmType;char * ____BAH_COMPILER_VAR_921 =__Bah_multiple_concat(____BAH_COMPILER_VAR_920, 2);mbmType = ____BAH_COMPILER_VAR_921;

#line 2004 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;
};

#line 2007 "/home/alois/Documents/bah-bah/src/parser.bah"
memb->type = mbmType;

#line 2008 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 2009 "/home/alois/Documents/bah-bah/src/parser.bah"
t = l->data[i];

#line 2010 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((i<len(l))) {

#line 2011 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "\01\0\0\0""=") == 0)) {

#line 2012 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 2013 "/home/alois/Documents/bah-bah/src/parser.bah"
t = l->data[i];

#line 2014 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((t.isValue==false), 0)) {

#line 2015 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"\057\0\0\0""Cannot use {TOKEN} as default value for member.");
}

#line 2017 "/home/alois/Documents/bah-bah/src/parser.bah"
char * tt = getTypeFromToken(&t,true,elems);

#line 2018 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((compTypes(tt,memb->type)==false), 0)) {

#line 2019 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_922 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_922[4] = "\014\0\0\0"" for member.";____BAH_COMPILER_VAR_922[3] = memb->type;____BAH_COMPILER_VAR_922[2] = "\05\0\0\0"") as ";____BAH_COMPILER_VAR_922[1] = tt;____BAH_COMPILER_VAR_922[0] = "\024\0\0\0""Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_923 =__Bah_multiple_concat(____BAH_COMPILER_VAR_922, 5);throwErr(&t,____BAH_COMPILER_VAR_923);
}

#line 2021 "/home/alois/Documents/bah-bah/src/parser.bah"
memb->def = t.cont;
}

#line 2023 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 2024 "/home/alois/Documents/bah-bah/src/parser.bah"
--i;
}
}

#line 2027 "/home/alois/Documents/bah-bah/src/parser.bah"
if (isRCPpointerType(memb->type)) {

#line 2028 "/home/alois/Documents/bah-bah/src/parser.bah"
s->hasRCPmemb = true;
}

#line 2030 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_924 = len(members);
    __Bah_realocate_arr(members, ____BAH_COMPILER_VAR_924);
    members->data[____BAH_COMPILER_VAR_924] = memb;

#line 2032 "/home/alois/Documents/bah-bah/src/parser.bah"
char * membDeclStr= null;

#line 2033 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string cmt = string(memb->type);

#line 2034 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((string__hasPrefix(&cmt,"\011\0\0\0""function(")==1)) {

#line 2035 "/home/alois/Documents/bah-bah/src/parser.bah"
struct func* tmpfn = parseFnType(cmt);

#line 2036 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string tmpfnRetCType = getCType(tmpfn->returns->type,elems);

#line 2037 "/home/alois/Documents/bah-bah/src/parser.bah"
char * tmpfnArgsCType = "\0\0\0\0""";

#line 2038 "/home/alois/Documents/bah-bah/src/parser.bah"
j = 0;

#line 2038 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((j<len(tmpfn->args))) {

#line 2039 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* arg = tmpfn->args->data[j];

#line 2040 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string ct = getCType(arg->type,elems);

#line 2041 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_925 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_925[1] = string__str(&ct);____BAH_COMPILER_VAR_925[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_926 =__Bah_multiple_concat(____BAH_COMPILER_VAR_925, 2);tmpfnArgsCType = ____BAH_COMPILER_VAR_926;

#line 2042 "/home/alois/Documents/bah-bah/src/parser.bah"
j = j+1;

#line 2043 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((j<len(tmpfn->args))) {

#line 2044 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_927 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_927[1] = "\01\0\0\0"",";____BAH_COMPILER_VAR_927[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_928 =__Bah_multiple_concat(____BAH_COMPILER_VAR_927, 2);tmpfnArgsCType = ____BAH_COMPILER_VAR_928;
}
};

#line 2047 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_929 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_929[5] = "\01\0\0\0"")";____BAH_COMPILER_VAR_929[4] = tmpfnArgsCType;____BAH_COMPILER_VAR_929[3] = "\02\0\0\0"")(";____BAH_COMPILER_VAR_929[2] = memb->name;____BAH_COMPILER_VAR_929[1] = "\03\0\0\0"" (*";____BAH_COMPILER_VAR_929[0] = string__str(&tmpfnRetCType);char * ____BAH_COMPILER_VAR_930 =__Bah_multiple_concat(____BAH_COMPILER_VAR_929, 6);membDeclStr = ____BAH_COMPILER_VAR_930;
}

#line 2048 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 2049 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string membDecl = getCType(memb->type,elems);

#line 2050 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_931 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_931[1] = memb->name;____BAH_COMPILER_VAR_931[0] = "\01\0\0\0"" ";char * ____BAH_COMPILER_VAR_932 =__Bah_multiple_concat(____BAH_COMPILER_VAR_931, 2);string__append(&membDecl,____BAH_COMPILER_VAR_932);

#line 2051 "/home/alois/Documents/bah-bah/src/parser.bah"
membDeclStr = string__str(&membDecl);
}

#line 2053 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_933 = len(allMembs);
    __Bah_realocate_arr(allMembs, ____BAH_COMPILER_VAR_933);
    allMembs->data[____BAH_COMPILER_VAR_933] = membDeclStr;

#line 2054 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;
};

#line 2056 "/home/alois/Documents/bah-bah/src/parser.bah"
s->members = members;

#line 2057 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((doesOutput==true)) {

#line 2058 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = OOUT;

#line 2059 "/home/alois/Documents/bah-bah/src/parser.bah"
NEXT_LINE = nextLine;

#line 2060 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_934 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_934[2] = "\03\0\0\0"" {\n";____BAH_COMPILER_VAR_934[1] = s->name;____BAH_COMPILER_VAR_934[0] = "\07\0\0\0""struct ";char * ____BAH_COMPILER_VAR_935 =__Bah_multiple_concat(____BAH_COMPILER_VAR_934, 3);struct rope* code = rope(____BAH_COMPILER_VAR_935);

#line 2061 "/home/alois/Documents/bah-bah/src/parser.bah"
i = 0;

#line 2061 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i<len(allMembs))) {

#line 2062 "/home/alois/Documents/bah-bah/src/parser.bah"
char * m = allMembs->data[i];

#line 2063 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_936 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_936[1] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_936[0] = m;char * ____BAH_COMPILER_VAR_937 =__Bah_multiple_concat(____BAH_COMPILER_VAR_936, 2);code = rope__add(code, rope(____BAH_COMPILER_VAR_937));

#line 2064 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;
};

#line 2066 "/home/alois/Documents/bah-bah/src/parser.bah"
code = rope__add(code, rope("\03\0\0\0""};\n"));

#line 2067 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope__add(OUTPUT, code);

#line 2068 "/home/alois/Documents/bah-bah/src/parser.bah"
char * phd = rope__toStr(postDeclHandle);

#line 2069 "/home/alois/Documents/bah-bah/src/parser.bah"
ropeSet(postDeclHandle,"\0\0\0\0""");

#line 2070 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope__add(OUTPUT, rope(phd));
}

#line 2073 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((debug==true)) {

#line 2075 "/home/alois/Documents/bah-bah/src/parser.bah"
struct debugStruct* ____BAH_COMPILER_VAR_938 = memoryAlloc(sizeof(struct debugStruct));
____BAH_COMPILER_VAR_938->membs = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_938->membs->length = 0;
            ____BAH_COMPILER_VAR_938->membs->elemSize = sizeof(struct variable*);
            struct debugStruct* ds = ____BAH_COMPILER_VAR_938;

#line 2076 "/home/alois/Documents/bah-bah/src/parser.bah"
ds->name = s->name;

#line 2077 "/home/alois/Documents/bah-bah/src/parser.bah"
i = 0;

#line 2077 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i<len(s->members))) {

#line 2078 "/home/alois/Documents/bah-bah/src/parser.bah"
struct structMemb* m = s->members->data[i];

#line 2079 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* ____BAH_COMPILER_VAR_939 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_939->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_939->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_939->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_939->from = "\0\0\0\0""";
struct variable* mv = ____BAH_COMPILER_VAR_939;

#line 2080 "/home/alois/Documents/bah-bah/src/parser.bah"
mv->name = m->name;

#line 2081 "/home/alois/Documents/bah-bah/src/parser.bah"
mv->type = m->type;

#line 2082 "/home/alois/Documents/bah-bah/src/parser.bah"
mv->isConst = false;

#line 2083 "/home/alois/Documents/bah-bah/src/parser.bah"
mv->isArray = m->isArray;

#line 2084 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_940 = i;
    __Bah_realocate_arr(ds->membs, ____BAH_COMPILER_VAR_940);
    ds->membs->data[____BAH_COMPILER_VAR_940] = mv;

#line 2085 "/home/alois/Documents/bah-bah/src/parser.bah"
i = i+1;
};

#line 2088 "/home/alois/Documents/bah-bah/src/parser.bah"
struct debugStruct* ____BAH_COMPILER_VAR_941 = ds;
char ** ____BAH_COMPILER_VAR_943 = (char **)((char*)(____BAH_COMPILER_VAR_941) + offsetof(struct debugStruct, name));
struct reflectElement ____BAH_COMPILER_VAR_944 = __reflect(____BAH_COMPILER_VAR_943, sizeof(char *), "\010\0\0\0""cpstring", "\04\0\0\0""name", 0, 0, 0, 0, offsetof(struct debugStruct, name));
array(struct variable*)** ____BAH_COMPILER_VAR_945 = (array(struct variable*)**)((char*)(____BAH_COMPILER_VAR_941) + offsetof(struct debugStruct, membs));
struct variable** ____BAH_COMPILER_VAR_946 = 0;
char ** ____BAH_COMPILER_VAR_948 = (char **)((char*)(____BAH_COMPILER_VAR_946) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_949 = __reflect(____BAH_COMPILER_VAR_948, sizeof(char *), "\010\0\0\0""cpstring", "\04\0\0\0""name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_950 = (char **)((char*)(____BAH_COMPILER_VAR_946) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_951 = __reflect(____BAH_COMPILER_VAR_950, sizeof(char *), "\010\0\0\0""cpstring", "\04\0\0\0""type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_952 = (char*)((char*)(____BAH_COMPILER_VAR_946) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_953 = __reflect(____BAH_COMPILER_VAR_952, sizeof(char), "\04\0\0\0""bool", "\07\0\0\0""isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_954 = (char **)((char*)(____BAH_COMPILER_VAR_946) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_955 = __reflect(____BAH_COMPILER_VAR_954, sizeof(char *), "\010\0\0\0""cpstring", "\010\0\0\0""constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_956 = (char*)((char*)(____BAH_COMPILER_VAR_946) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_957 = __reflect(____BAH_COMPILER_VAR_956, sizeof(char), "\04\0\0\0""bool", "\07\0\0\0""isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_958 = (char **)((char*)(____BAH_COMPILER_VAR_946) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_959 = __reflect(____BAH_COMPILER_VAR_958, sizeof(char *), "\010\0\0\0""cpstring", "\04\0\0\0""from", 0, 0, 0, 0, offsetof(struct variable, from));
void ** ____BAH_COMPILER_VAR_960 = (void **)((char*)(____BAH_COMPILER_VAR_946) + offsetof(struct variable, declScope));
struct reflectElement ____BAH_COMPILER_VAR_961 = __reflect(____BAH_COMPILER_VAR_960, sizeof(void *), "\03\0\0\0""ptr", "\011\0\0\0""declScope", 0, 0, 0, 0, offsetof(struct variable, declScope));
char* ____BAH_COMPILER_VAR_962 = (char*)((char*)(____BAH_COMPILER_VAR_946) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_963 = __reflect(____BAH_COMPILER_VAR_962, sizeof(char), "\04\0\0\0""bool", "\010\0\0\0""isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));
struct rope** ____BAH_COMPILER_VAR_964 = (struct rope**)((char*)(____BAH_COMPILER_VAR_946) + offsetof(struct variable, declRope));
char ** ____BAH_COMPILER_VAR_966 = (char **)((char*)(____BAH_COMPILER_VAR_964) + offsetof(struct rope, str));
struct reflectElement ____BAH_COMPILER_VAR_967 = __reflect(____BAH_COMPILER_VAR_966, sizeof(char *), "\010\0\0\0""cpstring", "\03\0\0\0""str", 0, 0, 0, 0, offsetof(struct rope, str));
int* ____BAH_COMPILER_VAR_968 = (int*)((char*)(____BAH_COMPILER_VAR_964) + offsetof(struct rope, totalLen));
struct reflectElement ____BAH_COMPILER_VAR_969 = __reflect(____BAH_COMPILER_VAR_968, sizeof(int), "\05\0\0\0""int32", "\010\0\0\0""totalLen", 0, 0, 0, 0, offsetof(struct rope, totalLen));
void ** ____BAH_COMPILER_VAR_970 = (void **)((char*)(____BAH_COMPILER_VAR_964) + offsetof(struct rope, left));
struct reflectElement ____BAH_COMPILER_VAR_971 = __reflect(____BAH_COMPILER_VAR_970, sizeof(void *), "\03\0\0\0""ptr", "\04\0\0\0""left", 0, 0, 0, 0, offsetof(struct rope, left));
void ** ____BAH_COMPILER_VAR_972 = (void **)((char*)(____BAH_COMPILER_VAR_964) + offsetof(struct rope, right));
struct reflectElement ____BAH_COMPILER_VAR_973 = __reflect(____BAH_COMPILER_VAR_972, sizeof(void *), "\03\0\0\0""ptr", "\05\0\0\0""right", 0, 0, 0, 0, offsetof(struct rope, right));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_965 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_965->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_965->length = 4;
        ____BAH_COMPILER_VAR_965->data = memoryAlloc(____BAH_COMPILER_VAR_965->length * ____BAH_COMPILER_VAR_965->elemSize);
        ____BAH_COMPILER_VAR_965->data[0] = ____BAH_COMPILER_VAR_967;
____BAH_COMPILER_VAR_965->data[1] = ____BAH_COMPILER_VAR_969;
____BAH_COMPILER_VAR_965->data[2] = ____BAH_COMPILER_VAR_971;
____BAH_COMPILER_VAR_965->data[3] = ____BAH_COMPILER_VAR_973;
struct reflectElement ____BAH_COMPILER_VAR_974 = __reflect(____BAH_COMPILER_VAR_964, sizeof(struct rope), "\05\0\0\0""rope*", "\010\0\0\0""declRope", 0, 0, 1, ____BAH_COMPILER_VAR_965, offsetof(struct variable, declRope));
char* ____BAH_COMPILER_VAR_975 = (char*)((char*)(____BAH_COMPILER_VAR_946) + offsetof(struct variable, canBeNull));
struct reflectElement ____BAH_COMPILER_VAR_976 = __reflect(____BAH_COMPILER_VAR_975, sizeof(char), "\04\0\0\0""bool", "\011\0\0\0""canBeNull", 0, 0, 0, 0, offsetof(struct variable, canBeNull));
void ** ____BAH_COMPILER_VAR_977 = (void **)((char*)(____BAH_COMPILER_VAR_946) + offsetof(struct variable, iterScope));
struct reflectElement ____BAH_COMPILER_VAR_978 = __reflect(____BAH_COMPILER_VAR_977, sizeof(void *), "\03\0\0\0""ptr", "\011\0\0\0""iterScope", 0, 0, 0, 0, offsetof(struct variable, iterScope));
char* ____BAH_COMPILER_VAR_979 = (char*)((char*)(____BAH_COMPILER_VAR_946) + offsetof(struct variable, canBeReg));
struct reflectElement ____BAH_COMPILER_VAR_980 = __reflect(____BAH_COMPILER_VAR_979, sizeof(char), "\04\0\0\0""bool", "\010\0\0\0""canBeReg", 0, 0, 0, 0, offsetof(struct variable, canBeReg));
char* ____BAH_COMPILER_VAR_981 = (char*)((char*)(____BAH_COMPILER_VAR_946) + offsetof(struct variable, isReg));
struct reflectElement ____BAH_COMPILER_VAR_982 = __reflect(____BAH_COMPILER_VAR_981, sizeof(char), "\04\0\0\0""bool", "\05\0\0\0""isReg", 0, 0, 0, 0, offsetof(struct variable, isReg));
void ** ____BAH_COMPILER_VAR_983 = (void **)((char*)(____BAH_COMPILER_VAR_946) + offsetof(struct variable, lastSet));
struct reflectElement ____BAH_COMPILER_VAR_984 = __reflect(____BAH_COMPILER_VAR_983, sizeof(void *), "\03\0\0\0""ptr", "\07\0\0\0""lastSet", 0, 0, 0, 0, offsetof(struct variable, lastSet));
char* ____BAH_COMPILER_VAR_985 = (char*)((char*)(____BAH_COMPILER_VAR_946) + offsetof(struct variable, isArg));
struct reflectElement ____BAH_COMPILER_VAR_986 = __reflect(____BAH_COMPILER_VAR_985, sizeof(char), "\04\0\0\0""bool", "\05\0\0\0""isArg", 0, 0, 0, 0, offsetof(struct variable, isArg));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_947 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_947->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_947->length = 15;
        ____BAH_COMPILER_VAR_947->data = memoryAlloc(____BAH_COMPILER_VAR_947->length * ____BAH_COMPILER_VAR_947->elemSize);
        ____BAH_COMPILER_VAR_947->data[0] = ____BAH_COMPILER_VAR_949;
____BAH_COMPILER_VAR_947->data[1] = ____BAH_COMPILER_VAR_951;
____BAH_COMPILER_VAR_947->data[2] = ____BAH_COMPILER_VAR_953;
____BAH_COMPILER_VAR_947->data[3] = ____BAH_COMPILER_VAR_955;
____BAH_COMPILER_VAR_947->data[4] = ____BAH_COMPILER_VAR_957;
____BAH_COMPILER_VAR_947->data[5] = ____BAH_COMPILER_VAR_959;
____BAH_COMPILER_VAR_947->data[6] = ____BAH_COMPILER_VAR_961;
____BAH_COMPILER_VAR_947->data[7] = ____BAH_COMPILER_VAR_963;
____BAH_COMPILER_VAR_947->data[8] = ____BAH_COMPILER_VAR_974;
____BAH_COMPILER_VAR_947->data[9] = ____BAH_COMPILER_VAR_976;
____BAH_COMPILER_VAR_947->data[10] = ____BAH_COMPILER_VAR_978;
____BAH_COMPILER_VAR_947->data[11] = ____BAH_COMPILER_VAR_980;
____BAH_COMPILER_VAR_947->data[12] = ____BAH_COMPILER_VAR_982;
____BAH_COMPILER_VAR_947->data[13] = ____BAH_COMPILER_VAR_984;
____BAH_COMPILER_VAR_947->data[14] = ____BAH_COMPILER_VAR_986;
struct reflectElement ____BAH_COMPILER_VAR_987 = __reflect(____BAH_COMPILER_VAR_946, sizeof(struct variable), "\011\0\0\0""variable*", "\0\0\0\0""", 0, 0, 1, ____BAH_COMPILER_VAR_947, 0);

        struct reflectElement ____BAH_COMPILER_VAR_988 = ____BAH_COMPILER_VAR_987;
        struct reflectElement ____BAH_COMPILER_VAR_989 = __reflect(____BAH_COMPILER_VAR_945, sizeof(array(struct variable*)*), "\013\0\0\0""[]variable*", "\05\0\0\0""membs", 1, &____BAH_COMPILER_VAR_988, 0, 0, offsetof(struct debugStruct, membs));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_942 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_942->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_942->length = 2;
        ____BAH_COMPILER_VAR_942->data = memoryAlloc(____BAH_COMPILER_VAR_942->length * ____BAH_COMPILER_VAR_942->elemSize);
        ____BAH_COMPILER_VAR_942->data[0] = ____BAH_COMPILER_VAR_944;
____BAH_COMPILER_VAR_942->data[1] = ____BAH_COMPILER_VAR_989;
struct reflectElement ____BAH_COMPILER_VAR_990 = __reflect(____BAH_COMPILER_VAR_941, sizeof(struct debugStruct), "\014\0\0\0""debugStruct*", "\02\0\0\0""ds", 0, 0, 1, ____BAH_COMPILER_VAR_942, 0);
debugPrint("\016\0\0\0""struct_declare",nameToken.line,____BAH_COMPILER_VAR_990);
}
};

#line 2094 "/home/alois/Documents/bah-bah/src/parser.bah"
void parseDefine(__BAH_ARR_TYPE_Tok l,struct Elems* elems){

#line 2096 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((len(l)<3), 0)) {

#line 2097 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&l->data[len(l)-1],"\057\0\0\0""Invalid usage of define, cannot end on {TOKEN}.");
}

#line 2100 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok ft = l->data[1];

#line 2101 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok st = l->data[2];

#line 2103 "/home/alois/Documents/bah-bah/src/parser.bah"
long int i = 1;

#line 2104 "/home/alois/Documents/bah-bah/src/parser.bah"
char doesOutput = true;

#line 2105 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(ft.cont, "\01\0\0\0""!") == 0)) {

#line 2106 "/home/alois/Documents/bah-bah/src/parser.bah"
ft = l->data[2];

#line 2107 "/home/alois/Documents/bah-bah/src/parser.bah"
st = l->data[3];

#line 2108 "/home/alois/Documents/bah-bah/src/parser.bah"
i = 2;

#line 2109 "/home/alois/Documents/bah-bah/src/parser.bah"
doesOutput = false;
}

#line 2112 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(st.cont, "\01\0\0\0""(") == 0)) {

#line 2114 "/home/alois/Documents/bah-bah/src/parser.bah"
struct func* ____BAH_COMPILER_VAR_991 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_991->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_991->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_991->args->length = 0;
            ____BAH_COMPILER_VAR_991->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_991->from = "\0\0\0\0""";
____BAH_COMPILER_VAR_991->file = "\0\0\0\0""";
____BAH_COMPILER_VAR_991->line = 1;
struct func* fn = ____BAH_COMPILER_VAR_991;

#line 2115 "/home/alois/Documents/bah-bah/src/parser.bah"
char * code = parseFnHeader("\0\0\0\0""",l,&i,fn,elems);

#line 2116 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct func*)* fns = elems->fns;

#line 2117 "/home/alois/Documents/bah-bah/src/parser.bah"
fn->isBinding = true;

#line 2118 "/home/alois/Documents/bah-bah/src/parser.bah"
fn->isCbinding = (doesOutput==false);

#line 2119 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_992 = len(fns);
    __Bah_realocate_arr(fns, ____BAH_COMPILER_VAR_992);
    fns->data[____BAH_COMPILER_VAR_992] = fn;

#line 2120 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((doesOutput==true)) {

#line 2121 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_993 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_993[1] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_993[0] = code;char * ____BAH_COMPILER_VAR_994 =__Bah_multiple_concat(____BAH_COMPILER_VAR_993, 2);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_994));
}
}

#line 2124 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 2125 "/home/alois/Documents/bah-bah/src/parser.bah"
char * tp = "\0\0\0\0""";

#line 2126 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 2126 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<len(l)); 
#line 2126 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 2127 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = l->data[i];

#line 2128 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_995 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_995[1] = t.cont;____BAH_COMPILER_VAR_995[0] = tp;char * ____BAH_COMPILER_VAR_996 =__Bah_multiple_concat(____BAH_COMPILER_VAR_995, 2);tp = ____BAH_COMPILER_VAR_996;
};

#line 2130 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((ft.type!=TOKEN_TYPE_VAR), 0)) {

#line 2131 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&ft,"\044\0\0\0""Cannot use {TOKEN} as new type name.");
}

#line 2133 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string cTypeNewType = getCType(tp,elems);

#line 2134 "/home/alois/Documents/bah-bah/src/parser.bah"
char * cTypeNewTypeStr = string__str(&cTypeNewType);

#line 2135 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((doesOutput==true)) {

#line 2136 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_997 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_997[4] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_997[3] = ft.cont;____BAH_COMPILER_VAR_997[2] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_997[1] = cTypeNewTypeStr;____BAH_COMPILER_VAR_997[0] = "\010\0\0\0""typedef ";char * ____BAH_COMPILER_VAR_998 =__Bah_multiple_concat(____BAH_COMPILER_VAR_997, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_998));
}

#line 2139 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((debug==true)) {

#line 2140 "/home/alois/Documents/bah-bah/src/parser.bah"
struct debugType* ____BAH_COMPILER_VAR_999 = memoryAlloc(sizeof(struct debugType));
struct debugType* dt = ____BAH_COMPILER_VAR_999;

#line 2141 "/home/alois/Documents/bah-bah/src/parser.bah"
dt->name = ft.cont;

#line 2142 "/home/alois/Documents/bah-bah/src/parser.bah"
dt->refers = tp;

#line 2143 "/home/alois/Documents/bah-bah/src/parser.bah"
struct debugType* ____BAH_COMPILER_VAR_1000 = dt;
char ** ____BAH_COMPILER_VAR_1002 = (char **)((char*)(____BAH_COMPILER_VAR_1000) + offsetof(struct debugType, name));
struct reflectElement ____BAH_COMPILER_VAR_1003 = __reflect(____BAH_COMPILER_VAR_1002, sizeof(char *), "\010\0\0\0""cpstring", "\04\0\0\0""name", 0, 0, 0, 0, offsetof(struct debugType, name));
char ** ____BAH_COMPILER_VAR_1004 = (char **)((char*)(____BAH_COMPILER_VAR_1000) + offsetof(struct debugType, refers));
struct reflectElement ____BAH_COMPILER_VAR_1005 = __reflect(____BAH_COMPILER_VAR_1004, sizeof(char *), "\010\0\0\0""cpstring", "\06\0\0\0""refers", 0, 0, 0, 0, offsetof(struct debugType, refers));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_1001 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_1001->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_1001->length = 2;
        ____BAH_COMPILER_VAR_1001->data = memoryAlloc(____BAH_COMPILER_VAR_1001->length * ____BAH_COMPILER_VAR_1001->elemSize);
        ____BAH_COMPILER_VAR_1001->data[0] = ____BAH_COMPILER_VAR_1003;
____BAH_COMPILER_VAR_1001->data[1] = ____BAH_COMPILER_VAR_1005;
struct reflectElement ____BAH_COMPILER_VAR_1006 = __reflect(____BAH_COMPILER_VAR_1000, sizeof(struct debugType), "\012\0\0\0""debugType*", "\02\0\0\0""dt", 0, 0, 1, ____BAH_COMPILER_VAR_1001, 0);
debugPrint("\014\0\0\0""type_declare",ft.line,____BAH_COMPILER_VAR_1006);
}

#line 2146 "/home/alois/Documents/bah-bah/src/parser.bah"
array(char *)* tps = elems->types;

#line 2147 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1007 = len(tps);
    __Bah_realocate_arr(tps, ____BAH_COMPILER_VAR_1007);
    tps->data[____BAH_COMPILER_VAR_1007] = ft.cont;
}
};

#line 2152 "/home/alois/Documents/bah-bah/src/parser.bah"
void parseClib(__BAH_ARR_TYPE_Tok line){

#line 2154 "/home/alois/Documents/bah-bah/src/parser.bah"
array(char *)* clibs = compilerState.cLibs;

#line 2156 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int i = 1;

#line 2156 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i<len(line))) {

#line 2157 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = line->data[i];

#line 2158 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((t.type!=TOKEN_TYPE_STR), 0)) {

#line 2159 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"\045\0\0\0""Cannot use {TOKEN} as C library name.");
}

#line 2162 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string cc = string(t.cont);

#line 2163 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimLeft(&cc,1);

#line 2164 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimRight(&cc,1);

#line 2165 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ccstr = string__str(&cc);

#line 2167 "/home/alois/Documents/bah-bah/src/parser.bah"
char found = false;

#line 2168 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int j = 0;

#line 2168 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((j<len(clibs))) {

#line 2169 "/home/alois/Documents/bah-bah/src/parser.bah"
char * l = clibs->data[j];

#line 2170 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(l, ccstr) == 0)) {

#line 2171 "/home/alois/Documents/bah-bah/src/parser.bah"
found = true;

#line 2172 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}

#line 2174 "/home/alois/Documents/bah-bah/src/parser.bah"
j = j+1;
};

#line 2176 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((found==true)) {

#line 2177 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 2178 "/home/alois/Documents/bah-bah/src/parser.bah"
continue;
}

#line 2180 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1008 = len(clibs);
    __Bah_realocate_arr(clibs, ____BAH_COMPILER_VAR_1008);
    clibs->data[____BAH_COMPILER_VAR_1008] = ccstr;

#line 2182 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;
};
};

#line 2187 "/home/alois/Documents/bah-bah/src/parser.bah"
void parseConst(__BAH_ARR_TYPE_Tok l,struct Elems* elems){

#line 2188 "/home/alois/Documents/bah-bah/src/parser.bah"
l = parseCast(l,elems,true);

#line 2189 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((len(l)!=4), 0)) {

#line 2190 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&l->data[0],"\106\0\0\0""Invalid usage of {TOKEN}, must be 'const <constName> = <constValue>'. ");
}

#line 2192 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok vart = l->data[1];

#line 2193 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok equt = l->data[2];

#line 2194 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok valt = l->data[3];

#line 2195 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((vart.type!=TOKEN_TYPE_VAR), 0)) {

#line 2196 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&vart,"\042\0\0\0""Cannot take {TOKEN} as const name.");
}

#line 2198 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((strcmp(equt.cont, "\01\0\0\0""=") != 0), 0)) {

#line 2199 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&equt,"\031\0\0\0""Expected '=' not {TOKEN}.");
}

#line 2201 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((valt.isValue==false), 0)) {

#line 2202 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&equt,"\035\0\0\0""Must be a value, not {TOKEN}.");
}

#line 2205 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((valt.type==TOKEN_TYPE_VAR)) {

#line 2206 "/home/alois/Documents/bah-bah/src/parser.bah"
struct func* fn = searchFunc(valt.cont,elems,true);

#line 2207 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((fn!=null)) {

#line 2208 "/home/alois/Documents/bah-bah/src/parser.bah"
fn->used = true;
}
}

#line 2212 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* ____BAH_COMPILER_VAR_1009 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1009->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_1009->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_1009->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_1009->from = "\0\0\0\0""";
struct variable* v = ____BAH_COMPILER_VAR_1009;

#line 2214 "/home/alois/Documents/bah-bah/src/parser.bah"
if (isGlobal()) {

#line 2215 "/home/alois/Documents/bah-bah/src/parser.bah"
v->isGlobal = true;
}

#line 2218 "/home/alois/Documents/bah-bah/src/parser.bah"
v->isConst = true;

#line 2219 "/home/alois/Documents/bah-bah/src/parser.bah"
v->constVal = valt.cont;

#line 2220 "/home/alois/Documents/bah-bah/src/parser.bah"
v->name = vart.cont;

#line 2221 "/home/alois/Documents/bah-bah/src/parser.bah"
v->type = getTypeFromToken(&valt,true,elems);

#line 2222 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct variable*)* vars = elems->vars;

#line 2223 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1010 = len(vars);
    __Bah_realocate_arr(vars, ____BAH_COMPILER_VAR_1010);
    vars->data[____BAH_COMPILER_VAR_1010] = v;

#line 2225 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((valt.type==TOKEN_TYPE_STR)) {

#line 2226 "/home/alois/Documents/bah-bah/src/parser.bah"
valt.cont = strLitteralToBahStr(valt.cont);
}

#line 2229 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1011 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1011[4] = "\01\0\0\0""\n";____BAH_COMPILER_VAR_1011[3] = valt.cont;____BAH_COMPILER_VAR_1011[2] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_1011[1] = v->name;____BAH_COMPILER_VAR_1011[0] = "\010\0\0\0""#define ";char * ____BAH_COMPILER_VAR_1012 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1011, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1012));
};

#line 2235 "/home/alois/Documents/bah-bah/src/parser.bah"
void parseReturn(__BAH_ARR_TYPE_Tok l,struct Elems* elems){

#line 2237 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((len(l)>2), 0)) {

#line 2238 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&l->data[0],"\070\0\0\0""Invalid usage of {TOKEN}, must be 'return <returnValue>'");
}

#line 2240 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((currentFn==null), 0)) {

#line 2241 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&l->data[0],"\054\0\0\0""Cannot return a value outside of a function.");
}

#line 2243 "/home/alois/Documents/bah-bah/src/parser.bah"
char * rv = "\0\0\0\0""";

#line 2244 "/home/alois/Documents/bah-bah/src/parser.bah"
char * tt = "\0\0\0\0""";

#line 2245 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* tmpV = null;

#line 2246 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((len(l)==1)) {

#line 2247 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((strlen(currentFn->returns->type)!=0), 0)) {

#line 2248 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1013 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1013[2] = "\01\0\0\0"".";____BAH_COMPILER_VAR_1013[1] = currentFn->returns->type;____BAH_COMPILER_VAR_1013[0] = "\031\0\0\0""Cannot return nothing as ";char * ____BAH_COMPILER_VAR_1014 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1013, 3);throwErr(&l->data[0],____BAH_COMPILER_VAR_1014);
}
}

#line 2250 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 2251 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok rvt = l->data[1];

#line 2252 "/home/alois/Documents/bah-bah/src/parser.bah"
tt = getTypeFromToken(&rvt,true,elems);

#line 2253 "/home/alois/Documents/bah-bah/src/parser.bah"
rv = rvt.cont;

#line 2254 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((rvt.type==TOKEN_TYPE_VAR)&&(rvt.isOper==false)) {

#line 2255 "/home/alois/Documents/bah-bah/src/parser.bah"
tmpV = searchVar(rvt.cont,compilerState.currFnElems);

#line 2256 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((tmpV==null)) {

#line 2257 "/home/alois/Documents/bah-bah/src/parser.bah"
tmpV = searchVar(rvt.cont,elems);
}

#line 2259 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((tmpV!=null)) {

#line 2260 "/home/alois/Documents/bah-bah/src/parser.bah"

                struct string ____BAH_COMPILER_VAR_1015 = string(compilerState.currentDir);
                if ((isUnsafe==false)&&(string__hasPrefix(&____BAH_COMPILER_VAR_1015,BAH_DIR)==false)&&(currentFn->returns->type[strlen(currentFn->returns->type)-1+4]!=33)) {

#line 2261 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((tmpV->canBeNull==true)||(strcmp(rv, "\04\0\0\0""null") == 0)) {

#line 2262 "/home/alois/Documents/bah-bah/src/parser.bah"
currentFn->returns->canBeNull = true;

#line 2263 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1016 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1016[2] = "\071\0\0\0""' that can be null as pointer.\n\tUse maybe values instead.";____BAH_COMPILER_VAR_1016[1] = tmpV->name;____BAH_COMPILER_VAR_1016[0] = "\013\0\0\0""Returning '";char * ____BAH_COMPILER_VAR_1017 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1016, 3);throwNoticeLine(____BAH_COMPILER_VAR_1017,rvt.line);
}
}
}
}

#line 2267 "/home/alois/Documents/bah-bah/src/parser.bah"
else if (RCPavailable()&&(rvt.type==TOKEN_TYPE_FUNC)) {

#line 2268 "/home/alois/Documents/bah-bah/src/parser.bah"
rv = genCompilerVar();

#line 2269 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string cType = getCType(tt,elems);

#line 2270 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1018 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_1018[5] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_1018[4] = rvt.cont;____BAH_COMPILER_VAR_1018[3] = "\01\0\0\0""=";____BAH_COMPILER_VAR_1018[2] = rv;____BAH_COMPILER_VAR_1018[1] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_1018[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_1019 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1018, 6);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1019));
}

#line 2272 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((compTypes(tt,currentFn->returns->type)==false), 0)) {

#line 2273 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1020 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1020[4] = "\01\0\0\0"".";____BAH_COMPILER_VAR_1020[3] = currentFn->returns->type;____BAH_COMPILER_VAR_1020[2] = "\05\0\0\0"") as ";____BAH_COMPILER_VAR_1020[1] = tt;____BAH_COMPILER_VAR_1020[0] = "\027\0\0\0""Cannot return {TOKEN} (";char * ____BAH_COMPILER_VAR_1021 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1020, 5);throwErr(&rvt,____BAH_COMPILER_VAR_1021);
}
}

#line 2276 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((compilerState.isBranch==false)) {

#line 2277 "/home/alois/Documents/bah-bah/src/parser.bah"
currentFn->returned = true;
}

#line 2278 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 2279 "/home/alois/Documents/bah-bah/src/parser.bah"
currentFn->couldAlreadyReturn = true;

#line 2280 "/home/alois/Documents/bah-bah/src/parser.bah"
setNullStateBranchFlowEnd(elems);
}

#line 2283 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strlen(rv)>0)) {

#line 2284 "/home/alois/Documents/bah-bah/src/parser.bah"
char * rvar = rv;

#line 2285 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((RCPavailable()==true)&&isRCPtype(currentFn->returns->type,elems)) {

#line 2286 "/home/alois/Documents/bah-bah/src/parser.bah"
rvar = genCompilerVar();

#line 2287 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string cType = getCType(currentFn->returns->type,elems);

#line 2288 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1022 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_1022[5] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_1022[4] = rv;____BAH_COMPILER_VAR_1022[3] = "\03\0\0\0"" = ";____BAH_COMPILER_VAR_1022[2] = rvar;____BAH_COMPILER_VAR_1022[1] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_1022[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_1023 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1022, 6);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1023));

#line 2289 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((tmpV!=null)&&(tmpV->declScope!=elems)) {

#line 2290 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope__add(OUTPUT, incrVar(tmpV,elems));
}
}

#line 2293 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string stt = string(tt);

#line 2294 "/home/alois/Documents/bah-bah/src/parser.bah"
if (string__hasPrefix(&stt,"\07\0\0\0""buffer:")) {

#line 2295 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1024 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1024[2] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1024[1] = rvar;____BAH_COMPILER_VAR_1024[0] = "\012\0\0\0""buffToStr(";char * ____BAH_COMPILER_VAR_1025 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1024, 3);rvar = ____BAH_COMPILER_VAR_1025;
}

#line 2296 "/home/alois/Documents/bah-bah/src/parser.bah"
else if (string__hasPrefix(&stt,"\06\0\0\0""tuple:")) {

#line 2297 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct string)* parts = splitString(stt,"\01\0\0\0"":");

#line 2298 "/home/alois/Documents/bah-bah/src/parser.bah"
char * v = genCompilerVar();

#line 2299 "/home/alois/Documents/bah-bah/src/parser.bah"

                struct string ____BAH_COMPILER_VAR_1026 = getCType(tt,elems);
                
                struct string ____BAH_COMPILER_VAR_1027 = getCType(string__str(&parts->data[2]),elems);
                
                struct string ____BAH_COMPILER_VAR_1028 = getCType(string__str(&parts->data[2]),elems);
                char** ____BAH_COMPILER_VAR_1029 = alloca(17 * sizeof(char*));____BAH_COMPILER_VAR_1029[16] = "\02\0\0\0"");";____BAH_COMPILER_VAR_1029[15] = string__str(&parts->data[1]);____BAH_COMPILER_VAR_1029[14] = "\04\0\0\0"") * ";____BAH_COMPILER_VAR_1029[13] = string__str(&____BAH_COMPILER_VAR_1028);____BAH_COMPILER_VAR_1029[12] = "\011\0\0\0"", sizeof(";____BAH_COMPILER_VAR_1029[11] = rv;____BAH_COMPILER_VAR_1029[10] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_1029[9] = v;____BAH_COMPILER_VAR_1029[8] = "\027\0\0\0""));\n            memcpy(";____BAH_COMPILER_VAR_1029[7] = string__str(&____BAH_COMPILER_VAR_1027);____BAH_COMPILER_VAR_1029[6] = "\012\0\0\0"" * sizeof(";____BAH_COMPILER_VAR_1029[5] = string__str(&parts->data[1]);____BAH_COMPILER_VAR_1029[4] = "\017\0\0\0"" = memoryAlloc(";____BAH_COMPILER_VAR_1029[3] = v;____BAH_COMPILER_VAR_1029[2] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_1029[1] = string__str(&____BAH_COMPILER_VAR_1026);____BAH_COMPILER_VAR_1029[0] = "\0\0\0\0""";char * ____BAH_COMPILER_VAR_1030 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1029, 17);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1030));

#line 2301 "/home/alois/Documents/bah-bah/src/parser.bah"
rvar = v;
}

#line 2303 "/home/alois/Documents/bah-bah/src/parser.bah"
if (RCPavailable()) {

#line 2304 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct variable*)* excl = memoryAlloc(sizeof(array(struct variable*)));

excl->length = 0;
excl->elemSize = sizeof(struct variable*);

#line 2305 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int j = 0;

#line 2305 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (j<len(currentFn->args)); 
#line 2305 "/home/alois/Documents/bah-bah/src/parser.bah"
++j) {

#line 2306 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1031 = j;
    __Bah_realocate_arr(excl, ____BAH_COMPILER_VAR_1031);
    excl->data[____BAH_COMPILER_VAR_1031] = currentFn->args->data[j];
};

#line 2308 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((tmpV!=null)) {

#line 2309 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1032 = len(excl);
    __Bah_realocate_arr(excl, ____BAH_COMPILER_VAR_1032);
    excl->data[____BAH_COMPILER_VAR_1032] = tmpV;
}

#line 2311 "/home/alois/Documents/bah-bah/src/parser.bah"
endRCPscope(elems,excl);
}

#line 2313 "/home/alois/Documents/bah-bah/src/parser.bah"
fixMeEndScope(elems,&l->data[0]);

#line 2314 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1033 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1033[2] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_1033[1] = rvar;____BAH_COMPILER_VAR_1033[0] = "\07\0\0\0""return ";char * ____BAH_COMPILER_VAR_1034 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1033, 3);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1034));
}

#line 2315 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 2316 "/home/alois/Documents/bah-bah/src/parser.bah"
if (RCPavailable()) {

#line 2317 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct variable*)* excl = memoryAlloc(sizeof(array(struct variable*)));

excl->length = 0;
excl->elemSize = sizeof(struct variable*);

#line 2318 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int j = 0;

#line 2318 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (j<len(currentFn->args)); 
#line 2318 "/home/alois/Documents/bah-bah/src/parser.bah"
++j) {

#line 2319 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1035 = j;
    __Bah_realocate_arr(excl, ____BAH_COMPILER_VAR_1035);
    excl->data[____BAH_COMPILER_VAR_1035] = currentFn->args->data[j];
};

#line 2321 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((tmpV!=null)) {

#line 2322 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1036 = len(excl);
    __Bah_realocate_arr(excl, ____BAH_COMPILER_VAR_1036);
    excl->data[____BAH_COMPILER_VAR_1036] = tmpV;
}

#line 2324 "/home/alois/Documents/bah-bah/src/parser.bah"
endRCPscope(elems,excl);
}

#line 2326 "/home/alois/Documents/bah-bah/src/parser.bah"
fixMeEndScope(elems,&l->data[0]);

#line 2327 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope__add(OUTPUT, rope("\010\0\0\0""return;\n"));
}
};

#line 2331 "/home/alois/Documents/bah-bah/src/parser.bah"
void parseIf(__BAH_ARR_TYPE_Tok l,char fromElse,struct Elems* elems){

#line 2332 "/home/alois/Documents/bah-bah/src/parser.bah"
prevIfExits = false;

#line 2333 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok ft = l->data[0];

#line 2334 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((len(l)<4), 0)) {

#line 2335 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&ft,"\073\0\0\0""Invalid usage of {TOKEN}, must be 'if <condition> {<code>}'");
}

#line 2337 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok condt = l->data[1];

#line 2338 "/home/alois/Documents/bah-bah/src/parser.bah"
char * tt = getTypeFromToken(&condt,true,elems);

#line 2339 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((compTypes(tt,"\04\0\0\0""bool")==false), 0)) {

#line 2340 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&condt,"\060\0\0\0""Cannot use {TOKEN} as condition in if statement.");
}

#line 2342 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = l->data[2];

#line 2343 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((strcmp(t.cont, "\01\0\0\0""{") != 0), 0)) {

#line 2344 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"\072\0\0\0""Expected '{' not {TOKEN} after condtition in if statement.");
}

#line 2346 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct Tok)* tokens = memoryAlloc(sizeof(array(struct Tok)));

tokens->length = 0;
tokens->elemSize = sizeof(struct Tok);

#line 2347 "/home/alois/Documents/bah-bah/src/parser.bah"
unsigned long int max = len(l)-1;

#line 2348 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int i = 3;

#line 2348 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i<max)) {

#line 2349 "/home/alois/Documents/bah-bah/src/parser.bah"
t = l->data[i];

#line 2350 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1037 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_1037);
    tokens->data[____BAH_COMPILER_VAR_1037] = t;

#line 2351 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;
};

#line 2354 "/home/alois/Documents/bah-bah/src/parser.bah"
begIfHandle = rope("\0\0\0\0""");

#line 2355 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope__add(OUTPUT, begIfHandle);

#line 2358 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1038 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1038[3] = "\04\0\0\0"") {\n";____BAH_COMPILER_VAR_1038[2] = condt.cont;____BAH_COMPILER_VAR_1038[1] = prevIfShortcut;____BAH_COMPILER_VAR_1038[0] = "\04\0\0\0""if (";char * ____BAH_COMPILER_VAR_1039 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1038, 4);struct rope* ifHeader = rope(____BAH_COMPILER_VAR_1039);

#line 2360 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope__add(OUTPUT, ifHeader);

#line 2362 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Elems* ifElems = dupElems(elems);

#line 2364 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((fromElse==true)) {

#line 2365 "/home/alois/Documents/bah-bah/src/parser.bah"
i = 0;

#line 2365 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<len(prevIfChecks)); 
#line 2365 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 2366 "/home/alois/Documents/bah-bah/src/parser.bah"
struct varCheck bc = prevIfChecks->data[i];

#line 2367 "/home/alois/Documents/bah-bah/src/parser.bah"
bc.checkNull = (bc.checkNull==false);

#line 2368 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1040 = i;
    __Bah_realocate_arr(ifElems->branchChecks, ____BAH_COMPILER_VAR_1040);
    ifElems->branchChecks->data[____BAH_COMPILER_VAR_1040] = bc;
};
}

#line 2372 "/home/alois/Documents/bah-bah/src/parser.bah"
i = 0;

#line 2372 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<len(currChecks)); 
#line 2372 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 2373 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1041 = len(ifElems->branchChecks);
    __Bah_realocate_arr(ifElems->branchChecks, ____BAH_COMPILER_VAR_1041);
    ifElems->branchChecks->data[____BAH_COMPILER_VAR_1041] = currChecks->data[i];
};

#line 2375 "/home/alois/Documents/bah-bah/src/parser.bah"
prevIfChecks = ifElems->branchChecks;

#line 2377 "/home/alois/Documents/bah-bah/src/parser.bah"
char oldIB = compilerState.isBranch;

#line 2378 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.isBranch = true;

#line 2379 "/home/alois/Documents/bah-bah/src/parser.bah"
beginRCPscopeLeaky(ifElems);

#line 2380 "/home/alois/Documents/bah-bah/src/parser.bah"
parseLines(tokens,ifElems);

#line 2382 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((ifElems->currFlowEnd==true)) {

#line 2383 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1042 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1042[2] = "\010\0\0\0"", 0)) {\n";____BAH_COMPILER_VAR_1042[1] = condt.cont;____BAH_COMPILER_VAR_1042[0] = "\025\0\0\0""if (__builtin_expect(";char * ____BAH_COMPILER_VAR_1043 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1042, 3);OUTPUT->totalLen = OUTPUT->totalLen+ropeSet(ifHeader,____BAH_COMPILER_VAR_1043);
}

#line 2387 "/home/alois/Documents/bah-bah/src/parser.bah"
endRCPscopeLeaky(ifElems,null,true);

#line 2388 "/home/alois/Documents/bah-bah/src/parser.bah"
fixMeEndScope(ifElems,&tokens->data[len(tokens)-1]);

#line 2389 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((debug==true)) {

#line 2390 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok lt = l->data[len(l)-1];

#line 2391 "/home/alois/Documents/bah-bah/src/parser.bah"
debugEndScope(lt.line,ifElems);
}

#line 2393 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.isBranch = oldIB;

#line 2394 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope__add(OUTPUT, rope("\02\0\0\0""}\n"));

#line 2396 "/home/alois/Documents/bah-bah/src/parser.bah"
prevIfShortcut = "\0\0\0\0""";
};

#line 2399 "/home/alois/Documents/bah-bah/src/parser.bah"
void parseElse(__BAH_ARR_TYPE_Tok l,struct Elems* elems){

#line 2401 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((prevLine!=LINE_TYPE_IF)) {

#line 2402 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((prevLine!=LINE_TYPE_ELSE), 0)) {

#line 2403 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&l->data[0],"\052\0\0\0""Can only use {TOKEN} after 'if' statement.");
}
}

#line 2406 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((len(l)<3), 0)) {

#line 2407 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&l->data[0],"\062\0\0\0""Incalid usage of {TOKEN}, must be 'else {<code>}'.");
}

#line 2409 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok ft = l->data[1];

#line 2411 "/home/alois/Documents/bah-bah/src/parser.bah"
char prevReturned = prevIfExits;

#line 2413 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope__add(OUTPUT, rope("\05\0\0\0""else "));

#line 2414 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(ft.cont, "\02\0\0\0""if") == 0)) {

#line 2415 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);

#line 2416 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int i = 1;

#line 2416 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i<len(l))) {

#line 2417 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1044 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1044);
    memory->data[____BAH_COMPILER_VAR_1044] = l->data[i];

#line 2418 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;
};

#line 2420 "/home/alois/Documents/bah-bah/src/parser.bah"
parseIf(memory,true,elems);

#line 2421 "/home/alois/Documents/bah-bah/src/parser.bah"
prevLine = LINE_TYPE_IF;
}

#line 2423 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 2424 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((strcmp(ft.cont, "\01\0\0\0""{") != 0), 0)) {

#line 2425 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&ft,"\041\0\0\0""Expected 'if' or '{' not {TOKEN}.");
}

#line 2427 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);

#line 2428 "/home/alois/Documents/bah-bah/src/parser.bah"
unsigned long int max = len(l)-1;

#line 2429 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int i = 2;

#line 2429 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i<max)) {

#line 2430 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1045 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1045);
    memory->data[____BAH_COMPILER_VAR_1045] = l->data[i];

#line 2431 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;
};

#line 2433 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope__add(OUTPUT, rope("\02\0\0\0""{\n"));

#line 2434 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Elems* ifElems = dupElems(elems);

#line 2436 "/home/alois/Documents/bah-bah/src/parser.bah"
i = 0;

#line 2436 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<len(prevIfChecks)); 
#line 2436 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 2437 "/home/alois/Documents/bah-bah/src/parser.bah"
struct varCheck bc = prevIfChecks->data[i];

#line 2438 "/home/alois/Documents/bah-bah/src/parser.bah"
bc.checkNull = (bc.checkNull==false);

#line 2439 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1046 = i;
    __Bah_realocate_arr(ifElems->branchChecks, ____BAH_COMPILER_VAR_1046);
    ifElems->branchChecks->data[____BAH_COMPILER_VAR_1046] = bc;
};

#line 2442 "/home/alois/Documents/bah-bah/src/parser.bah"
char oldIB = compilerState.isBranch;

#line 2443 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.isBranch = true;

#line 2444 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = l->data[0];

#line 2445 "/home/alois/Documents/bah-bah/src/parser.bah"
beginRCPscopeLeaky(ifElems);

#line 2446 "/home/alois/Documents/bah-bah/src/parser.bah"
parseLines(memory,ifElems);

#line 2447 "/home/alois/Documents/bah-bah/src/parser.bah"
endRCPscopeLeaky(ifElems,null,true);

#line 2448 "/home/alois/Documents/bah-bah/src/parser.bah"
fixMeEndScope(ifElems,&memory->data[len(memory)-1]);

#line 2449 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((debug==true)) {

#line 2450 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok lt = l->data[len(l)-1];

#line 2451 "/home/alois/Documents/bah-bah/src/parser.bah"
debugEndScope(lt.line,ifElems);
}

#line 2453 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.isBranch = oldIB;

#line 2454 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope__add(OUTPUT, rope("\02\0\0\0""}\n"));

#line 2455 "/home/alois/Documents/bah-bah/src/parser.bah"
prevIfExits = false;
}
};
void parseLine(__BAH_ARR_TYPE_Tok l,struct Elems* elems);

#line 2464 "/home/alois/Documents/bah-bah/src/parser.bah"
void parseFor(__BAH_ARR_TYPE_Tok l,struct Elems* elems){

#line 2466 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((len(l)<4), 0)) {

#line 2467 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&l->data[0],"\031\0\0\0""Invalid usage of {TOKEN}.");
}

#line 2470 "/home/alois/Documents/bah-bah/src/parser.bah"
long int nbComas = 0;

#line 2471 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int i = 1;

#line 2471 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i<len(l))) {

#line 2472 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = l->data[i];

#line 2473 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "\01\0\0\0""{") == 0)) {

#line 2474 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}

#line 2476 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((t.type==TOKEN_TYPE_SYNTAX)&&(strcmp(t.cont, "\01\0\0\0"",") == 0)) {

#line 2477 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((nbComas==1), 0)) {

#line 2478 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"\106\0\0\0""Invalid line separation of for, cannot set more than 2 lines: {TOKEN}.");
}

#line 2480 "/home/alois/Documents/bah-bah/src/parser.bah"
nbComas = nbComas+1;
}

#line 2482 "/home/alois/Documents/bah-bah/src/parser.bah"
i = i+1;
};

#line 2485 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Elems* ifElems = dupElems(elems);

#line 2486 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct Tok)* tokens = memoryAlloc(sizeof(array(struct Tok)));

tokens->length = 0;
tokens->elemSize = sizeof(struct Tok);

#line 2487 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok condt = l->data[1];

#line 2488 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((compTypes(getTypeFromToken(&condt,true,elems),"\04\0\0\0""bool")==false), 0)) {

#line 2489 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&condt,"\061\0\0\0""Cannot use {TOKEN} as condition in for statement.");
}

#line 2492 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((nbComas>0)) {

#line 2493 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((nbComas!=1), 0)) {

#line 2494 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = l->data[0];

#line 2495 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"\150\0\0\0""Invalid usage of {TOKEN}, can only partition line in 2 using 'for <condition>, <insctruction> {<code>}'.");
}

#line 2498 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct Tok)* inst = memoryAlloc(sizeof(array(struct Tok)));

inst->length = 0;
inst->elemSize = sizeof(struct Tok);

#line 2501 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok st = l->data[2];

#line 2503 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((st.type!=TOKEN_TYPE_SYNTAX)||(strcmp(st.cont, "\01\0\0\0"",") != 0), 0)) {

#line 2504 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&st,"\074\0\0\0""Cannot use {TOKEN}, need ',' to split for loop instructions.");
}

#line 2507 "/home/alois/Documents/bah-bah/src/parser.bah"
i = 3;

#line 2507 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<len(l)); 
#line 2507 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 2508 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = l->data[i];

#line 2509 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((t.type==TOKEN_TYPE_ENCL)&&(strcmp(t.cont, "\01\0\0\0""{") == 0)) {

#line 2510 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}

#line 2512 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1047 = len(inst);
    __Bah_realocate_arr(inst, ____BAH_COMPILER_VAR_1047);
    inst->data[____BAH_COMPILER_VAR_1047] = t;
};

#line 2515 "/home/alois/Documents/bah-bah/src/parser.bah"
struct rope* oldOut = OUTPUT;

#line 2516 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope("\0\0\0\0""");

#line 2518 "/home/alois/Documents/bah-bah/src/parser.bah"
parseLine(inst,ifElems);

#line 2520 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string instC = string(rope__toStr(OUTPUT));

#line 2521 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = oldOut;

#line 2522 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimRight(&instC,2);

#line 2524 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = l->data[i];

#line 2525 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((strcmp(t.cont, "\01\0\0\0""{") != 0), 0)) {

#line 2526 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"\114\0\0\0""Expected '{' not {TOKEN} after '<condition>,<instruction>' in for statement.");
}

#line 2529 "/home/alois/Documents/bah-bah/src/parser.bah"
unsigned long int max = len(l)-1;

#line 2530 "/home/alois/Documents/bah-bah/src/parser.bah"
i = i+1;

#line 2530 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<max); 
#line 2530 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 2531 "/home/alois/Documents/bah-bah/src/parser.bah"
t = l->data[i];

#line 2532 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1048 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_1048);
    tokens->data[____BAH_COMPILER_VAR_1048] = t;
};

#line 2535 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1049 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1049[4] = "\04\0\0\0"") {\n";____BAH_COMPILER_VAR_1049[3] = string__str(&instC);____BAH_COMPILER_VAR_1049[2] = "\02\0\0\0""; ";____BAH_COMPILER_VAR_1049[1] = condt.cont;____BAH_COMPILER_VAR_1049[0] = "\07\0\0\0""for (; ";char * ____BAH_COMPILER_VAR_1050 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1049, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1050));
}

#line 2537 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 2538 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = l->data[2];

#line 2539 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((strcmp(t.cont, "\01\0\0\0""{") != 0), 0)) {

#line 2540 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"\073\0\0\0""Expected '{' not {TOKEN} after condtition in for statement.");
}

#line 2542 "/home/alois/Documents/bah-bah/src/parser.bah"
unsigned long int max = len(l)-1;

#line 2543 "/home/alois/Documents/bah-bah/src/parser.bah"
i = 3;

#line 2543 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<max); 
#line 2543 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 2544 "/home/alois/Documents/bah-bah/src/parser.bah"
t = l->data[i];

#line 2545 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1051 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_1051);
    tokens->data[____BAH_COMPILER_VAR_1051] = t;
};

#line 2547 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1052 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1052[2] = "\04\0\0\0"") {\n";____BAH_COMPILER_VAR_1052[1] = condt.cont;____BAH_COMPILER_VAR_1052[0] = "\07\0\0\0""while (";char * ____BAH_COMPILER_VAR_1053 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1052, 3);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1053));
}

#line 2549 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Elems* oForElems = compilerState.currForElems;

#line 2550 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.currForElems = ifElems;

#line 2552 "/home/alois/Documents/bah-bah/src/parser.bah"
char oldIB = compilerState.isBranch;

#line 2553 "/home/alois/Documents/bah-bah/src/parser.bah"
char oldIF = compilerState.isFor;

#line 2554 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.isBranch = true;

#line 2555 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.isFor = true;

#line 2556 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = l->data[0];

#line 2557 "/home/alois/Documents/bah-bah/src/parser.bah"
beginRCPscopeLeaky(ifElems);

#line 2558 "/home/alois/Documents/bah-bah/src/parser.bah"
parseLines(tokens,ifElems);

#line 2559 "/home/alois/Documents/bah-bah/src/parser.bah"
endRCPscopeLeaky(ifElems,null,true);

#line 2560 "/home/alois/Documents/bah-bah/src/parser.bah"
fixMeEndScope(ifElems,&tokens->data[len(tokens)-1]);

#line 2562 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((isUnsafe==false)) {

#line 2563 "/home/alois/Documents/bah-bah/src/parser.bah"
i = 0;

#line 2563 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<len(ifElems->vars)); 
#line 2563 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 2564 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* v = ifElems->vars->data[i];

#line 2565 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((v->iterScope==elems)) {

#line 2566 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((v->lastSet!=ifElems)&&(Elems__isChildren(ifElems,v->lastSet)==false)) {

#line 2567 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1054 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1054[2] = "\163\0\0\0""' but its value is not changed inside the scope of the for loop.\n    This may result in the loop never terminating.";____BAH_COMPILER_VAR_1054[1] = v->name;____BAH_COMPILER_VAR_1054[0] = "\041\0\0\0""For loop iterates over variable '";char * ____BAH_COMPILER_VAR_1055 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1054, 3);throwWarningLine(____BAH_COMPILER_VAR_1055,t.line);
}

#line 2570 "/home/alois/Documents/bah-bah/src/parser.bah"
v->iterScope = null;
}
};
}

#line 2575 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((debug==true)) {

#line 2576 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok lt = l->data[len(l)-1];

#line 2577 "/home/alois/Documents/bah-bah/src/parser.bah"
debugEndScope(lt.line,ifElems);
}

#line 2579 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.isFor = oldIF;

#line 2580 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.isBranch = oldIB;

#line 2581 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.currForElems = oForElems;

#line 2582 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope__add(OUTPUT, rope("\03\0\0\0""};\n"));
};

#line 2586 "/home/alois/Documents/bah-bah/src/parser.bah"
void parseForOp(__BAH_ARR_TYPE_Tok l,struct Elems* elems){

#line 2588 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok ft = l->data[0];

#line 2589 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((compilerState.isFor==false), 0)) {

#line 2590 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&ft,"\050\0\0\0""Cannot {TOKEN} outside of for statement.");
}

#line 2592 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((len(l)!=1), 0)) {

#line 2593 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&ft,"\037\0\0\0""Nothing expected after {TOKEN}.");
}

#line 2597 "/home/alois/Documents/bah-bah/src/parser.bah"
endRCPscopeLeaky(elems,null,false);

#line 2598 "/home/alois/Documents/bah-bah/src/parser.bah"
endRCPscopeLeaky(compilerState.currForElems,null,false);

#line 2599 "/home/alois/Documents/bah-bah/src/parser.bah"
fixMeEndScope(elems,&ft);

#line 2600 "/home/alois/Documents/bah-bah/src/parser.bah"
fixMeEndScope(compilerState.currForElems,&ft);

#line 2601 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1056 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1056[1] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_1056[0] = ft.cont;char * ____BAH_COMPILER_VAR_1057 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1056, 2);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1057));
};

#line 2605 "/home/alois/Documents/bah-bah/src/parser.bah"
char ____BAH_COMPILER_VAR_1058(array(char *)* arr, char * el) {
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

#line 2606 "/home/alois/Documents/bah-bah/src/parser.bah"
if (____BAH_COMPILER_VAR_1058(compilerState.evals, fn->name)) {

#line 2607 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}

#line 2610 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1059 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1059[1] = fn->name;____BAH_COMPILER_VAR_1059[0] = "\013\0\0\0""__Bah_eval_";char * ____BAH_COMPILER_VAR_1060 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1059, 2);struct func* ____BAH_COMPILER_VAR_1061 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_1061->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_1061->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_1061->args->length = 0;
            ____BAH_COMPILER_VAR_1061->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_1061->from = "\0\0\0\0""";
____BAH_COMPILER_VAR_1061->file = "\0\0\0\0""";
____BAH_COMPILER_VAR_1061->line = 1;
____BAH_COMPILER_VAR_1061->name = ____BAH_COMPILER_VAR_1060;
struct func* efn = ____BAH_COMPILER_VAR_1061;

#line 2613 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* ____BAH_COMPILER_VAR_1062 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1062->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_1062->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_1062->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_1062->from = "\0\0\0\0""";
____BAH_COMPILER_VAR_1062->type = "\03\0\0\0""ptr";
efn->returns = ____BAH_COMPILER_VAR_1062;

#line 2617 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* ____BAH_COMPILER_VAR_1063 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1063->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_1063->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_1063->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_1063->from = "\0\0\0\0""";
____BAH_COMPILER_VAR_1063->name = "\06\0\0\0""fnArgs";
____BAH_COMPILER_VAR_1063->type = "\05\0\0\0""[]ptr";
efn->args = memoryAlloc(sizeof(array(struct variable*)));

efn->args->length = 1;
efn->args->elemSize = sizeof(struct variable*);
efn->args->data = memoryAlloc(sizeof(struct variable*) * 50);
                    efn->args->realLength = 50;
efn->args->data[0] = ____BAH_COMPILER_VAR_1063;

#line 2624 "/home/alois/Documents/bah-bah/src/parser.bah"
char * fnBinding = "\0\0\0\0""";

#line 2625 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1064 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1064[1] = "\01\0\0\0""(";____BAH_COMPILER_VAR_1064[0] = fn->name;char * ____BAH_COMPILER_VAR_1065 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1064, 2);char * fnCall = ____BAH_COMPILER_VAR_1065;

#line 2626 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int i = 0;

#line 2626 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<len(fn->args)); 
#line 2626 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 2627 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* a = fn->args->data[i];

#line 2628 "/home/alois/Documents/bah-bah/src/parser.bah"
char * v = genCompilerVar();

#line 2629 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string cType = getCType(a->type,elems);

#line 2630 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((isRCPpointerType(a->type)==false)) {

#line 2631 "/home/alois/Documents/bah-bah/src/parser.bah"
string__append(&cType,"\01\0\0\0""*");
}

#line 2633 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1066 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_1066[5] = "\02\0\0\0""];";____BAH_COMPILER_VAR_1066[4] = intToStr(i);____BAH_COMPILER_VAR_1066[3] = "\020\0\0\0"" = fnArgs->data[";____BAH_COMPILER_VAR_1066[2] = v;____BAH_COMPILER_VAR_1066[1] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_1066[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_1067 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1066, 6);char** ____BAH_COMPILER_VAR_1068 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1068[1] = ____BAH_COMPILER_VAR_1067;____BAH_COMPILER_VAR_1068[0] = fnBinding;char * ____BAH_COMPILER_VAR_1069 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1068, 2);fnBinding = ____BAH_COMPILER_VAR_1069;

#line 2634 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((i!=0)) {

#line 2635 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1070 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1070[1] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_1070[0] = fnCall;char * ____BAH_COMPILER_VAR_1071 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1070, 2);fnCall = ____BAH_COMPILER_VAR_1071;
}

#line 2637 "/home/alois/Documents/bah-bah/src/parser.bah"
if (isRCPpointerType(a->type)) {

#line 2638 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1072 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1072[1] = v;____BAH_COMPILER_VAR_1072[0] = fnCall;char * ____BAH_COMPILER_VAR_1073 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1072, 2);fnCall = ____BAH_COMPILER_VAR_1073;
}

#line 2639 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 2640 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1074 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1074[1] = v;____BAH_COMPILER_VAR_1074[0] = "\01\0\0\0""*";char * ____BAH_COMPILER_VAR_1075 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1074, 2);char** ____BAH_COMPILER_VAR_1076 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1076[1] = ____BAH_COMPILER_VAR_1075;____BAH_COMPILER_VAR_1076[0] = fnCall;char * ____BAH_COMPILER_VAR_1077 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1076, 2);fnCall = ____BAH_COMPILER_VAR_1077;
}
};

#line 2644 "/home/alois/Documents/bah-bah/src/parser.bah"
char * setReturnValue = "\014\0\0\0""void* r = 0;";

#line 2645 "/home/alois/Documents/bah-bah/src/parser.bah"
if (isRCPpointerType(fn->returns->type)) {

#line 2646 "/home/alois/Documents/bah-bah/src/parser.bah"
setReturnValue = "\012\0\0\0""void* r = ";
}

#line 2647 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 2648 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string cType = getCType(fn->returns->type,elems);

#line 2649 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(string__str(&cType), "\04\0\0\0""void") != 0)) {

#line 2650 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1078 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1078[3] = "\010\0\0\0""));*r = ";____BAH_COMPILER_VAR_1078[2] = string__str(&cType);____BAH_COMPILER_VAR_1078[1] = "\031\0\0\0""* r = memoryAlloc(sizeof(";____BAH_COMPILER_VAR_1078[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_1079 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1078, 4);setReturnValue = ____BAH_COMPILER_VAR_1079;
}
}

#line 2654 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1080 = alloca(12 * sizeof(char*));____BAH_COMPILER_VAR_1080[11] = "\042\0\0\0"");\n        return (void*)r;\n    };";____BAH_COMPILER_VAR_1080[10] = fnCall;____BAH_COMPILER_VAR_1080[9] = setReturnValue;____BAH_COMPILER_VAR_1080[8] = "\011\0\0\0""\n        ";____BAH_COMPILER_VAR_1080[7] = fnBinding;____BAH_COMPILER_VAR_1080[6] = "\125\0\0\0""() with the wrong number of arguments.\", \"BAH_COMPILER_INTERNAL\");\n        }\n        ";____BAH_COMPILER_VAR_1080[5] = fn->name;____BAH_COMPILER_VAR_1080[4] = "\073\0\0\0"") {\n            __BAH_panic((char*)\"eval: calling function ";____BAH_COMPILER_VAR_1080[3] = intToStr(len(fn->args));____BAH_COMPILER_VAR_1080[2] = "\067\0\0\0""(array(void*)* fnArgs) {\n        if (fnArgs->length != ";____BAH_COMPILER_VAR_1080[1] = efn->name;____BAH_COMPILER_VAR_1080[0] = "\046\0\0\0""void* __attribute__((optimize(\"O0\"))) ";char * ____BAH_COMPILER_VAR_1081 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1080, 12);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1081));

#line 2663 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1082 = len(compilerState.evals);
    __Bah_realocate_arr(compilerState.evals, ____BAH_COMPILER_VAR_1082);
    compilerState.evals->data[____BAH_COMPILER_VAR_1082] = fn->name;

#line 2664 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1083 = len(elems->fns);
    __Bah_realocate_arr(elems->fns, ____BAH_COMPILER_VAR_1083);
    elems->fns->data[____BAH_COMPILER_VAR_1083] = efn;
};

#line 2667 "/home/alois/Documents/bah-bah/src/parser.bah"
char ____BAH_COMPILER_VAR_1084(array(char *)* arr, char * el) {
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

#line 2669 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok ft = l->data[0];

#line 2671 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(ft.cont, "\010\0\0\0""#warning") == 0)) {

#line 2672 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((len(l)!=2), 0)) {

#line 2673 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&ft,"\056\0\0\0""Invalid usage of {TOKEN} '#warning \"message\"'.");
}

#line 2675 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok mt = l->data[1];

#line 2676 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((mt.type!=TOKEN_TYPE_STR), 0)) {

#line 2677 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&mt,"\037\0\0\0""Cannot use {TOKEN} as a string.");
}

#line 2680 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string msg = string(mt.cont);

#line 2681 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimLeft(&msg,1);

#line 2682 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimRight(&msg,1);

#line 2685 "/home/alois/Documents/bah-bah/src/parser.bah"
throwWarning(string__str(&msg));

#line 2686 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}

#line 2690 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(ft.cont, "\05\0\0\0""#eval") == 0)) {

#line 2692 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((____BAH_COMPILER_VAR_1084(compilerState.includes, "\010\0\0\0""eval.bah")==false)) {

#line 2693 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((includeFile("\010\0\0\0""eval.bah",elems)==false), 0)) {

#line 2694 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1085 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1085[2] = "\02\0\0\0"").";____BAH_COMPILER_VAR_1085[1] = BAH_DIR;____BAH_COMPILER_VAR_1085[0] = "\072\0\0\0""Could not find file 'eval.bah'. Check your bah directory (";char * ____BAH_COMPILER_VAR_1086 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1085, 3);throwErr(&l->data[0],____BAH_COMPILER_VAR_1086);
}
}

#line 2698 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((len(l)!=2)||(isGlobal()==false), 0)) {

#line 2699 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&l->data[0],"\050\0\0\0""Invalid usage of {TOKEN} <#eval fnName>.");
}

#line 2702 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok fnT = l->data[1];

#line 2703 "/home/alois/Documents/bah-bah/src/parser.bah"
struct func* fn = searchFunc(fnT.cont,elems,false);

#line 2704 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((fn==null), 0)) {

#line 2705 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&fnT,"\031\0\0\0""Unknown function {TOKEN}.");
}

#line 2707 "/home/alois/Documents/bah-bah/src/parser.bah"
fn->used = true;

#line 2709 "/home/alois/Documents/bah-bah/src/parser.bah"
makeEvalFunc(fn,elems);

#line 2711 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}

#line 2714 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(ft.cont, "\010\0\0\0""#evalAll") == 0)) {

#line 2715 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int i = 0;

#line 2715 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<len(elems->fns)); 
#line 2715 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 2716 "/home/alois/Documents/bah-bah/src/parser.bah"
struct func* fn = elems->fns->data[i];

#line 2717 "/home/alois/Documents/bah-bah/src/parser.bah"
fn->used = true;

#line 2718 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((fn->isBinding==false)&&(strHasPrefix(fn->name,"\013\0\0\0""__Bah_eval_")==false)) {

#line 2719 "/home/alois/Documents/bah-bah/src/parser.bah"
makeEvalFunc(fn,elems);
}
};

#line 2722 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}

#line 2725 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((len(l)<3), 0)) {

#line 2726 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&ft,"\041\0\0\0""Invalid usage of keyword {TOKEN}.");
}

#line 2729 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(ft.cont, "\06\0\0\0""#linux") == 0)||(strcmp(ft.cont, "\010\0\0\0""#windows") == 0)||(strcmp(ft.cont, "\07\0\0\0""#darwin") == 0)) {

#line 2730 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string isOS = string(ft.cont);

#line 2731 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimLeft(&isOS,1);

#line 2732 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(string__str(&isOS), BAH_OS) != 0)) {

#line 2733 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}
}

#line 2735 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "\07\0\0\0""#static") == 0)) {

#line 2736 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((flags__isSet(&flags,"\01\0\0\0""d")==1)) {

#line 2737 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}
}

#line 2739 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "\010\0\0\0""#dynamic") == 0)) {

#line 2740 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((flags__isSet(&flags,"\01\0\0\0""d")==0)) {

#line 2741 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}
}

#line 2743 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "\03\0\0\0""#gc") == 0)) {

#line 2744 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((RCPavailable()==true)) {

#line 2745 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}
}

#line 2747 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "\04\0\0\0""#rcp") == 0)) {

#line 2748 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((RCPavailable()==false)) {

#line 2749 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}
}

#line 2751 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "\04\0\0\0""#lib") == 0)) {

#line 2752 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((flags__isSet(&flags,"\01\0\0\0""l")==0)) {

#line 2753 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}
}

#line 2755 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "\05\0\0\0""#exec") == 0)) {

#line 2756 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((flags__isSet(&flags,"\01\0\0\0""l")==1)) {

#line 2757 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}
}

#line 2759 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "\011\0\0\0""#imported") == 0)) {

#line 2760 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((isSubObject==false)||(isObject==false)) {

#line 2761 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}
}

#line 2763 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "\011\0\0\0""#included") == 0)) {

#line 2764 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((isSubObject==true)||(isObject==true)) {

#line 2765 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}
}

#line 2767 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "\012\0\0\0""#optimized") == 0)) {

#line 2768 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((isOptimized==false)) {

#line 2769 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}
}

#line 2771 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "\014\0\0\0""#unoptimized") == 0)) {

#line 2772 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((isOptimized==true)) {

#line 2773 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}
}

#line 2775 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 2776 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&ft,"\030\0\0\0""Undefined token {TOKEN}.");
}

#line 2779 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok st = l->data[1];

#line 2780 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok lt = l->data[len(l)-1];

#line 2781 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((strcmp(st.cont, "\01\0\0\0""{") != 0)||(strcmp(lt.cont, "\01\0\0\0""}") != 0), 0)) {

#line 2782 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&st,"\052\0\0\0""Expected code block after keyword {TOKEN}.");
}

#line 2785 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);

#line 2786 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int i = 2;

#line 2786 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i<len(l)-1)) {

#line 2787 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1087 = i-2;
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_1087);
    nl->data[____BAH_COMPILER_VAR_1087] = l->data[i];

#line 2788 "/home/alois/Documents/bah-bah/src/parser.bah"
i = i+1;
};

#line 2791 "/home/alois/Documents/bah-bah/src/parser.bah"
parseLines(nl,elems);
};

#line 2795 "/home/alois/Documents/bah-bah/src/parser.bah"
void parseAsync(__BAH_ARR_TYPE_Tok l,struct Elems* elems){

#line 2796 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((len(l)!=2), 0)) {

#line 2797 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok ft = l->data[0];

#line 2798 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&ft,"\106\0\0\0""Cannot use keyword {TOKEN} on a function call 'async <function call>'.");
}

#line 2800 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok fnT = l->data[1];

#line 2801 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((fnT.isFunc==false), 0)) {

#line 2802 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&fnT,"\104\0\0\0""Cannot use keyword async on {TOKEN}. Usage: 'async <function call>'.");
}

#line 2805 "/home/alois/Documents/bah-bah/src/parser.bah"
char found = false;

#line 2806 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int i = 0;

#line 2806 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i<len(compilerState.cLibs))) {

#line 2807 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(compilerState.cLibs->data[i], "\010\0\0\0""lpthread") == 0)) {

#line 2808 "/home/alois/Documents/bah-bah/src/parser.bah"
found = true;

#line 2809 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}

#line 2811 "/home/alois/Documents/bah-bah/src/parser.bah"
i = i+1;
};

#line 2813 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((found==false)) {

#line 2814 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1088 = len(compilerState.cLibs);
    __Bah_realocate_arr(compilerState.cLibs, ____BAH_COMPILER_VAR_1088);
    compilerState.cLibs->data[____BAH_COMPILER_VAR_1088] = "\010\0\0\0""lpthread";
}

#line 2817 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string sFnT = string(fnT.cont);

#line 2819 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct string)* fnNameParts = splitString(sFnT,"\01\0\0\0""(");

#line 2820 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string fnName = fnNameParts->data[0];

#line 2822 "/home/alois/Documents/bah-bah/src/parser.bah"
struct func* fn = searchFuncByToken(&fnT,elems);

#line 2824 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((fn==null), 0)) {

#line 2825 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1089 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1089[2] = "\023\0\0\0""', arround {TOKEN}.";____BAH_COMPILER_VAR_1089[1] = string__str(&fnName);____BAH_COMPILER_VAR_1089[0] = "\101\0\0\0""Internal compiler error.\n Error parsing async call for function '";char * ____BAH_COMPILER_VAR_1090 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1089, 3);throwErr(&fnT,____BAH_COMPILER_VAR_1090);
}

#line 2827 "/home/alois/Documents/bah-bah/src/parser.bah"
fnName = string(fn->name);

#line 2828 "/home/alois/Documents/bah-bah/src/parser.bah"
char * sMembs = "\0\0\0\0""";

#line 2829 "/home/alois/Documents/bah-bah/src/parser.bah"
char * unSerMembs = "\0\0\0\0""";

#line 2831 "/home/alois/Documents/bah-bah/src/parser.bah"
i = 0;

#line 2831 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i<len(fn->args))) {

#line 2832 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* a = fn->args->data[i];

#line 2833 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string cType = getCType(a->type,elems);

#line 2834 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1091 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1091[4] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_1091[3] = a->name;____BAH_COMPILER_VAR_1091[2] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_1091[1] = string__str(&cType);____BAH_COMPILER_VAR_1091[0] = sMembs;char * ____BAH_COMPILER_VAR_1092 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1091, 5);sMembs = ____BAH_COMPILER_VAR_1092;

#line 2835 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1093 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1093[2] = a->name;____BAH_COMPILER_VAR_1093[1] = "\06\0\0\0""args->";____BAH_COMPILER_VAR_1093[0] = unSerMembs;char * ____BAH_COMPILER_VAR_1094 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1093, 3);unSerMembs = ____BAH_COMPILER_VAR_1094;

#line 2836 "/home/alois/Documents/bah-bah/src/parser.bah"
i = i+1;

#line 2837 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((i<len(fn->args))) {

#line 2838 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1095 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1095[1] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_1095[0] = unSerMembs;char * ____BAH_COMPILER_VAR_1096 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1095, 2);unSerMembs = ____BAH_COMPILER_VAR_1096;
}
};

#line 2842 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1097 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1097[2] = "\01\0\0\0""}";____BAH_COMPILER_VAR_1097[1] = sMembs;____BAH_COMPILER_VAR_1097[0] = "\011\0\0\0""struct {\n";char * ____BAH_COMPILER_VAR_1098 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1097, 3);char * tmpArgsStruct = ____BAH_COMPILER_VAR_1098;

#line 2843 "/home/alois/Documents/bah-bah/src/parser.bah"
char * fnWrapper = genCompilerVar();

#line 2844 "/home/alois/Documents/bah-bah/src/parser.bah"
char * tmpArgs = genCompilerVar();

#line 2846 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimLeft(&sFnT,fnName.length+1);

#line 2847 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimRight(&sFnT,1);

#line 2849 "/home/alois/Documents/bah-bah/src/parser.bah"
char * tCreate = "\0\0\0\0""";

#line 2850 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(BAH_OS, "\07\0\0\0""windows") == 0)) {

#line 2851 "/home/alois/Documents/bah-bah/src/parser.bah"
tCreate = "\016\0\0\0""pthread_create";
}

#line 2852 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 2853 "/home/alois/Documents/bah-bah/src/parser.bah"
if (RCPavailable()||(RAIIenabled==true)) {

#line 2854 "/home/alois/Documents/bah-bah/src/parser.bah"
tCreate = "\016\0\0\0""pthread_create";
}

#line 2855 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 2856 "/home/alois/Documents/bah-bah/src/parser.bah"
tCreate = "\021\0\0\0""GC_pthread_create";
}
}

#line 2860 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1099 = alloca(25 * sizeof(char*));____BAH_COMPILER_VAR_1099[24] = "\035\0\0\0"", tmpArgs);\n    }; \n    \n    ";____BAH_COMPILER_VAR_1099[23] = fnWrapper;____BAH_COMPILER_VAR_1099[22] = "\011\0\0\0""(&id, 0, ";____BAH_COMPILER_VAR_1099[21] = tCreate;____BAH_COMPILER_VAR_1099[20] = "\042\0\0\0""));\n        pthread_t id;\n        ";____BAH_COMPILER_VAR_1099[19] = tmpArgs;____BAH_COMPILER_VAR_1099[18] = "\011\0\0\0"", sizeof(";____BAH_COMPILER_VAR_1099[17] = tmpArgs;____BAH_COMPILER_VAR_1099[16] = "\035\0\0\0""));\n        memcpy(tmpArgs, &";____BAH_COMPILER_VAR_1099[15] = tmpArgs;____BAH_COMPILER_VAR_1099[14] = "\056\0\0\0""};\n        void* tmpArgs = memoryAlloc(sizeof(";____BAH_COMPILER_VAR_1099[13] = string__str(&sFnT);____BAH_COMPILER_VAR_1099[12] = "\04\0\0\0"" = {";____BAH_COMPILER_VAR_1099[11] = tmpArgs;____BAH_COMPILER_VAR_1099[10] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_1099[9] = tmpArgsStruct;____BAH_COMPILER_VAR_1099[8] = "\030\0\0\0"");\n    };\n    {\n        ";____BAH_COMPILER_VAR_1099[7] = unSerMembs;____BAH_COMPILER_VAR_1099[6] = "\01\0\0\0""(";____BAH_COMPILER_VAR_1099[5] = string__str(&fnName);____BAH_COMPILER_VAR_1099[4] = "\022\0\0\0""* args) {\n        ";____BAH_COMPILER_VAR_1099[3] = tmpArgsStruct;____BAH_COMPILER_VAR_1099[2] = "\01\0\0\0""(";____BAH_COMPILER_VAR_1099[1] = fnWrapper;____BAH_COMPILER_VAR_1099[0] = "\012\0\0\0""\n    void ";char * ____BAH_COMPILER_VAR_1100 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1099, 25);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1100));
};

#line 2875 "/home/alois/Documents/bah-bah/src/parser.bah"
void addRCPvars(__BAH_ARR_TYPE_Tok l,lineType ltp,struct Elems* elems){

#line 2877 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int i = 0;

#line 2878 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((ltp==LINE_TYPE_VAR)) {

#line 2879 "/home/alois/Documents/bah-bah/src/parser.bah"
i = 1;
}

#line 2881 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i<len(l))) {

#line 2882 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = l->data[i];

#line 2883 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((t.type==TOKEN_TYPE_VAR)&&(t.isOper==false)) {

#line 2884 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* v = searchVirtVarByToken(&t,elems);

#line 2885 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((v!=null)) {

#line 2886 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1101 = len(compilerState.RCPvars);
    __Bah_realocate_arr(compilerState.RCPvars, ____BAH_COMPILER_VAR_1101);
    compilerState.RCPvars->data[____BAH_COMPILER_VAR_1101] = v;
}
}

#line 2889 "/home/alois/Documents/bah-bah/src/parser.bah"
i = i+1;
};
};

#line 2895 "/home/alois/Documents/bah-bah/src/parser.bah"
__BAH_ARR_TYPE_Tok parseChan(__BAH_ARR_TYPE_Tok l,struct Elems* elems){

#line 2897 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);

#line 2898 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int i = 0;

#line 2898 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<len(l)); 
#line 2898 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 2899 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = l->data[i];

#line 2900 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((t.type==TOKEN_TYPE_SYNTAX)&&(strcmp(t.cont, "\02\0\0\0""->") == 0)||(strcmp(t.cont, "\02\0\0\0""<-") == 0)) {

#line 2902 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "\02\0\0\0""<-") == 0)) {

#line 2903 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 2904 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((i<len(l))) {

#line 2905 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok nt = l->data[i];

#line 2906 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((nt.type!=TOKEN_TYPE_VAR), 0)) {

#line 2907 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&nt,"\036\0\0\0""Cannot use {TOKEN} as channel.");
}

#line 2909 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string ntt = string(getTypeFromToken(&nt,true,elems));

#line 2910 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((string__hasPrefix(&ntt,"\05\0\0\0""chan:")==0), 0)) {

#line 2911 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1102 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1102[2] = "\015\0\0\0"") as channel.";____BAH_COMPILER_VAR_1102[1] = string__str(&ntt);____BAH_COMPILER_VAR_1102[0] = "\030\0\0\0""Cannot use var {TOKEN} (";char * ____BAH_COMPILER_VAR_1103 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1102, 3);throwErr(&nt,____BAH_COMPILER_VAR_1103);
}

#line 2913 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimLeft(&ntt,5);

#line 2915 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect(isGlobal(), 0)) {

#line 2916 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"\076\0\0\0""Cannot receive ({TOKEN}) from a channel outside of a function.");
}

#line 2919 "/home/alois/Documents/bah-bah/src/parser.bah"
char * tmpV = "\0\0\0\0""";

#line 2921 "/home/alois/Documents/bah-bah/src/parser.bah"
if (isRCPpointerType(string__str(&ntt))) {

#line 2922 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string ct = getCType(string__str(&ntt),elems);

#line 2923 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1104 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_1104[6] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1104[5] = nt.cont;____BAH_COMPILER_VAR_1104[4] = "\012\0\0\0""->receive(";____BAH_COMPILER_VAR_1104[3] = nt.cont;____BAH_COMPILER_VAR_1104[2] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1104[1] = string__str(&ct);____BAH_COMPILER_VAR_1104[0] = "\01\0\0\0""(";char * ____BAH_COMPILER_VAR_1105 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1104, 7);t.cont = ____BAH_COMPILER_VAR_1105;
}

#line 2924 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 2925 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string ct = getCType(string__str(&ntt),elems);

#line 2926 "/home/alois/Documents/bah-bah/src/parser.bah"
if (RCPavailable()) {

#line 2927 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1106 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1106[1] = "\01\0\0\0""*";____BAH_COMPILER_VAR_1106[0] = string__str(&ntt);char * ____BAH_COMPILER_VAR_1107 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1106, 2);char** ____BAH_COMPILER_VAR_1108 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_1108[6] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1108[5] = nt.cont;____BAH_COMPILER_VAR_1108[4] = "\012\0\0\0""->receive(";____BAH_COMPILER_VAR_1108[3] = nt.cont;____BAH_COMPILER_VAR_1108[2] = "\02\0\0\0""*)";____BAH_COMPILER_VAR_1108[1] = string__str(&ct);____BAH_COMPILER_VAR_1108[0] = "\01\0\0\0""(";char * ____BAH_COMPILER_VAR_1109 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1108, 7);tmpV = registerRCPvar(____BAH_COMPILER_VAR_1107,____BAH_COMPILER_VAR_1109,elems);

#line 2928 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1110 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1110[1] = tmpV;____BAH_COMPILER_VAR_1110[0] = "\01\0\0\0""*";char * ____BAH_COMPILER_VAR_1111 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1110, 2);t.cont = ____BAH_COMPILER_VAR_1111;
}

#line 2929 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 2930 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1112 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_1112[6] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1112[5] = nt.cont;____BAH_COMPILER_VAR_1112[4] = "\012\0\0\0""->receive(";____BAH_COMPILER_VAR_1112[3] = nt.cont;____BAH_COMPILER_VAR_1112[2] = "\02\0\0\0""*)";____BAH_COMPILER_VAR_1112[1] = string__str(&ct);____BAH_COMPILER_VAR_1112[0] = "\02\0\0\0""*(";char * ____BAH_COMPILER_VAR_1113 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1112, 7);t.cont = ____BAH_COMPILER_VAR_1113;
}
}

#line 2933 "/home/alois/Documents/bah-bah/src/parser.bah"
t.type = TOKEN_TYPE_FUNC;

#line 2934 "/home/alois/Documents/bah-bah/src/parser.bah"
t.isFunc = true;

#line 2936 "/home/alois/Documents/bah-bah/src/parser.bah"
if (RCPavailable()) {

#line 2937 "/home/alois/Documents/bah-bah/src/parser.bah"
if (isRCPpointerType(string__str(&ntt))) {

#line 2938 "/home/alois/Documents/bah-bah/src/parser.bah"
tmpV = registerRCPvar(string__str(&ntt),t.cont,elems);

#line 2939 "/home/alois/Documents/bah-bah/src/parser.bah"
t.type = TOKEN_TYPE_VAR;

#line 2940 "/home/alois/Documents/bah-bah/src/parser.bah"
t.isFunc = false;

#line 2941 "/home/alois/Documents/bah-bah/src/parser.bah"
t.cont = tmpV;
}

#line 2942 "/home/alois/Documents/bah-bah/src/parser.bah"
else {
}
}

#line 2947 "/home/alois/Documents/bah-bah/src/parser.bah"
t.isValue = true;

#line 2948 "/home/alois/Documents/bah-bah/src/parser.bah"
t.bahType = string__str(&ntt);
}

#line 2949 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 2950 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"\035\0\0\0""Cannot use {TOKEN} on nothing");
}
}

#line 2952 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 2953 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((i==0), 0)) {

#line 2954 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"\036\0\0\0""Cannot une {TOKEN} on nothing.");
}

#line 2956 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((i+1>=len(l)), 0)) {

#line 2957 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"\041\0\0\0""Cannot send ({TOKEN}) to nothing.");
}

#line 2959 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok pt = l->data[i+1];

#line 2960 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok nt = l->data[i-1];

#line 2961 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ntt = getTypeFromToken(&nt,true,elems);

#line 2963 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((pt.type!=TOKEN_TYPE_VAR), 0)) {

#line 2964 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&pt,"\036\0\0\0""Cannot use {TOKEN} as channel.");
}

#line 2966 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string ptt = string(getTypeFromToken(&pt,true,elems));

#line 2967 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((string__hasPrefix(&ptt,"\05\0\0\0""chan:")==0), 0)) {

#line 2968 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1114 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1114[2] = "\015\0\0\0"") as channel.";____BAH_COMPILER_VAR_1114[1] = ntt;____BAH_COMPILER_VAR_1114[0] = "\030\0\0\0""Cannot use var {TOKEN} (";char * ____BAH_COMPILER_VAR_1115 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1114, 3);throwErr(&pt,____BAH_COMPILER_VAR_1115);
}

#line 2970 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimLeft(&ptt,5);

#line 2972 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect(isGlobal(), 0)) {

#line 2973 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"\071\0\0\0""Cannot send ({TOKEN}) to a channel outside of a function.");
}

#line 2976 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((compTypes(string__str(&ptt),ntt)==false), 0)) {

#line 2977 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1116 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1116[4] = "\01\0\0\0"".";____BAH_COMPILER_VAR_1116[3] = string__str(&ptt);____BAH_COMPILER_VAR_1116[2] = "\025\0\0\0"") to channel of type ";____BAH_COMPILER_VAR_1116[1] = ntt;____BAH_COMPILER_VAR_1116[0] = "\025\0\0\0""Cannot send {TOKEN} (";char * ____BAH_COMPILER_VAR_1117 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1116, 5);throwErr(&nt,____BAH_COMPILER_VAR_1117);
}

#line 2980 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 2981 "/home/alois/Documents/bah-bah/src/parser.bah"
if (isRCPpointerType(string__str(&ptt))) {

#line 2982 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1118 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_1118[5] = "\03\0\0\0"");\n";____BAH_COMPILER_VAR_1118[4] = nt.cont;____BAH_COMPILER_VAR_1118[3] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_1118[2] = pt.cont;____BAH_COMPILER_VAR_1118[1] = "\07\0\0\0""->send(";____BAH_COMPILER_VAR_1118[0] = pt.cont;char * ____BAH_COMPILER_VAR_1119 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1118, 6);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1119));
}

#line 2983 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 2984 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string ct = getCType(ntt,elems);

#line 2985 "/home/alois/Documents/bah-bah/src/parser.bah"
char * tmpV = genCompilerVar();

#line 2986 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1120 = alloca(15 * sizeof(char*));____BAH_COMPILER_VAR_1120[14] = "\04\0\0\0""));\n";____BAH_COMPILER_VAR_1120[13] = tmpV;____BAH_COMPILER_VAR_1120[12] = "\011\0\0\0"", sizeof(";____BAH_COMPILER_VAR_1120[11] = tmpV;____BAH_COMPILER_VAR_1120[10] = "\03\0\0\0"", &";____BAH_COMPILER_VAR_1120[9] = pt.cont;____BAH_COMPILER_VAR_1120[8] = "\012\0\0\0""->sendAny(";____BAH_COMPILER_VAR_1120[7] = pt.cont;____BAH_COMPILER_VAR_1120[6] = "\026\0\0\0"";\n                    ";____BAH_COMPILER_VAR_1120[5] = nt.cont;____BAH_COMPILER_VAR_1120[4] = "\03\0\0\0"" = ";____BAH_COMPILER_VAR_1120[3] = tmpV;____BAH_COMPILER_VAR_1120[2] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_1120[1] = string__str(&ct);____BAH_COMPILER_VAR_1120[0] = "\025\0\0\0""\n                    ";char * ____BAH_COMPILER_VAR_1121 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1120, 15);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1121));
}

#line 2991 "/home/alois/Documents/bah-bah/src/parser.bah"
nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);

#line 2992 "/home/alois/Documents/bah-bah/src/parser.bah"
return nl;
}
}

#line 2995 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1122 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_1122);
    nl->data[____BAH_COMPILER_VAR_1122] = t;
};

#line 2997 "/home/alois/Documents/bah-bah/src/parser.bah"
return nl;
};

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
throwErr(&pt,"\025\0\0\0""Unknown func {TOKEN}.");
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
fnt.ogCont = "\01\0\0\0""(";

#line 49 "/home/alois/Documents/bah-bah/src/values.bah"
for (; (i<len(l)); 
#line 49 "/home/alois/Documents/bah-bah/src/values.bah"
++i) {

#line 50 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok t = l->data[i];

#line 51 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1123 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1123[1] = t.ogCont;____BAH_COMPILER_VAR_1123[0] = fnt.ogCont;char * ____BAH_COMPILER_VAR_1124 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1123, 2);fnt.ogCont = ____BAH_COMPILER_VAR_1124;

#line 52 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(t.cont, "\01\0\0\0""(") == 0)||(strcmp(t.cont, "\01\0\0\0""{") == 0)||(strcmp(t.cont, "\01\0\0\0""[") == 0)) {

#line 53 "/home/alois/Documents/bah-bah/src/values.bah"
++nbEncls;
}

#line 54 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((strcmp(t.cont, "\01\0\0\0"")") == 0)||(strcmp(t.cont, "\01\0\0\0""}") == 0)||(strcmp(t.cont, "\01\0\0\0""]") == 0)) {

#line 55 "/home/alois/Documents/bah-bah/src/values.bah"
--nbEncls;

#line 56 "/home/alois/Documents/bah-bah/src/values.bah"
if ((nbEncls==0)) {

#line 57 "/home/alois/Documents/bah-bah/src/values.bah"
break;
}
}

#line 60 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1125 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1125);
    memory->data[____BAH_COMPILER_VAR_1125] = t;
};

#line 62 "/home/alois/Documents/bah-bah/src/values.bah"
deleteRange(l,tokPos+1,i);

#line 63 "/home/alois/Documents/bah-bah/src/values.bah"
array(struct Tok)* memort = prePross(memory,(lineType)-1,elems);

#line 64 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok ft = memory->data[0];

#line 65 "/home/alois/Documents/bah-bah/src/values.bah"
fnt.cont = "\01\0\0\0""(";

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
char** ____BAH_COMPILER_VAR_1126 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1126[1] = t.cont;____BAH_COMPILER_VAR_1126[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1127 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1126, 2);fnt.cont = ____BAH_COMPILER_VAR_1127;
};

#line 73 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1128 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1128[1] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1128[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1129 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1128, 2);fnt.cont = ____BAH_COMPILER_VAR_1129;

#line 74 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1130 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1130);
    l->data[____BAH_COMPILER_VAR_1130] = fnt;

#line 75 "/home/alois/Documents/bah-bah/src/values.bah"
return tokPos;
}

#line 79 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(fn->name, "\04\0\0\0""exit") == 0)||(strcmp(fn->name, "\05\0\0\0""panic") == 0)||(fn->exits==true)) {

#line 80 "/home/alois/Documents/bah-bah/src/values.bah"
if ((compilerState.isBranch==true)) {

#line 81 "/home/alois/Documents/bah-bah/src/values.bah"
elems->currFlowEnd = true;
}

#line 83 "/home/alois/Documents/bah-bah/src/values.bah"
setNullStateBranchFlowEnd(elems);
}

#line 87 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1131 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1131[1] = "\01\0\0\0""(";____BAH_COMPILER_VAR_1131[0] = fn->name;char * ____BAH_COMPILER_VAR_1132 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1131, 2);fnt.cont = ____BAH_COMPILER_VAR_1132;

#line 88 "/home/alois/Documents/bah-bah/src/values.bah"
if ((fn->returns!=null)&&(strcmp(fn->returns->type, "\0\0\0\0""") != 0)) {

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

#line 98 "/home/alois/Documents/bah-bah/src/values.bah"
i = tokPos+1;

#line 99 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1133 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1133[1] = "\01\0\0\0""(";____BAH_COMPILER_VAR_1133[0] = fn->name;char * ____BAH_COMPILER_VAR_1134 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1133, 2);fnt.ogCont = ____BAH_COMPILER_VAR_1134;

#line 100 "/home/alois/Documents/bah-bah/src/values.bah"
long int start = i;

#line 101 "/home/alois/Documents/bah-bah/src/values.bah"
for (; (i<len(l)); 
#line 101 "/home/alois/Documents/bah-bah/src/values.bah"
++i) {

#line 102 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok t = l->data[i];

#line 103 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1135 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1135[1] = t.ogCont;____BAH_COMPILER_VAR_1135[0] = fnt.ogCont;char * ____BAH_COMPILER_VAR_1136 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1135, 2);fnt.ogCont = ____BAH_COMPILER_VAR_1136;

#line 104 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(t.cont, "\01\0\0\0""(") == 0)||(strcmp(t.cont, "\01\0\0\0""{") == 0)||(strcmp(t.cont, "\01\0\0\0""[") == 0)) {

#line 105 "/home/alois/Documents/bah-bah/src/values.bah"
++nbEncls;
}

#line 106 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((strcmp(t.cont, "\01\0\0\0"")") == 0)||(strcmp(t.cont, "\01\0\0\0""}") == 0)||(strcmp(t.cont, "\01\0\0\0""]") == 0)) {

#line 107 "/home/alois/Documents/bah-bah/src/values.bah"
--nbEncls;

#line 108 "/home/alois/Documents/bah-bah/src/values.bah"
if ((nbEncls==0)) {

#line 109 "/home/alois/Documents/bah-bah/src/values.bah"
break;
}
}
};

#line 113 "/home/alois/Documents/bah-bah/src/values.bah"
array(struct Tok)* memory = arraySubstitute(l, start, i);

#line 114 "/home/alois/Documents/bah-bah/src/values.bah"
deleteRange(l,tokPos+1,i);

#line 117 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(fn->name, "\07\0\0\0""noCheck") == 0)) {

#line 118 "/home/alois/Documents/bah-bah/src/values.bah"
fnt.cont = "\0\0\0\0""";

#line 119 "/home/alois/Documents/bah-bah/src/values.bah"
fnt.isOper = true;

#line 120 "/home/alois/Documents/bah-bah/src/values.bah"
fnt.isValue = true;

#line 121 "/home/alois/Documents/bah-bah/src/values.bah"
fnt.bahType = "\03\0\0\0""ptr";

#line 122 "/home/alois/Documents/bah-bah/src/values.bah"
register long int j = 0;

#line 122 "/home/alois/Documents/bah-bah/src/values.bah"
for (; (j<len(memory)); 
#line 122 "/home/alois/Documents/bah-bah/src/values.bah"
++j) {

#line 123 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok t = memory->data[j];

#line 124 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1137 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1137[1] = t.cont;____BAH_COMPILER_VAR_1137[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1138 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1137, 2);fnt.cont = ____BAH_COMPILER_VAR_1138;
};

#line 126 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1139 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1139);
    l->data[____BAH_COMPILER_VAR_1139] = fnt;

#line 127 "/home/alois/Documents/bah-bah/src/values.bah"
return tokPos;
}

#line 130 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1140 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1140[4] = "\01\0\0\0""\"";____BAH_COMPILER_VAR_1140[3] = intToStr(fnt.line);____BAH_COMPILER_VAR_1140[2] = "\01\0\0\0"":";____BAH_COMPILER_VAR_1140[1] = compilerState.currentFile;____BAH_COMPILER_VAR_1140[0] = "\01\0\0\0""\"";char * ____BAH_COMPILER_VAR_1141 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1140, 5);char * currLine = ____BAH_COMPILER_VAR_1141;

#line 131 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(fn->name, "\05\0\0\0""panic") == 0)) {

#line 132 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok ____BAH_COMPILER_VAR_1142 = {};
____BAH_COMPILER_VAR_1142.cont = "\0\0\0\0""";
____BAH_COMPILER_VAR_1142.ogCont = "\0\0\0\0""";
____BAH_COMPILER_VAR_1142.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1142.line = 1;
____BAH_COMPILER_VAR_1142.begLine = 1;
____BAH_COMPILER_VAR_1142.bahType = "\0\0\0\0""";
____BAH_COMPILER_VAR_1142.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_1142.cont = "\01\0\0\0"",";
____BAH_COMPILER_VAR_1142.line = fnt.line;

    unsigned int ____BAH_COMPILER_VAR_1143 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1143);
    memory->data[____BAH_COMPILER_VAR_1143] = ____BAH_COMPILER_VAR_1142;

#line 137 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok ____BAH_COMPILER_VAR_1144 = {};
____BAH_COMPILER_VAR_1144.cont = "\0\0\0\0""";
____BAH_COMPILER_VAR_1144.ogCont = "\0\0\0\0""";
____BAH_COMPILER_VAR_1144.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1144.line = 1;
____BAH_COMPILER_VAR_1144.begLine = 1;
____BAH_COMPILER_VAR_1144.bahType = "\0\0\0\0""";
____BAH_COMPILER_VAR_1144.type = TOKEN_TYPE_STR;
____BAH_COMPILER_VAR_1144.cont = currLine;
____BAH_COMPILER_VAR_1144.line = fnt.line;

    unsigned int ____BAH_COMPILER_VAR_1145 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1145);
    memory->data[____BAH_COMPILER_VAR_1145] = ____BAH_COMPILER_VAR_1144;

#line 142 "/home/alois/Documents/bah-bah/src/values.bah"
fn = searchFunc("\013\0\0\0""__BAH_panic",elems,true);

#line 143 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1146 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1146[1] = "\01\0\0\0""(";____BAH_COMPILER_VAR_1146[0] = fn->name;char * ____BAH_COMPILER_VAR_1147 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1146, 2);fnt.cont = ____BAH_COMPILER_VAR_1147;
}

#line 144 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((strcmp(fn->name, "\015\0\0\0""__dumpSymbols") == 0)) {

#line 145 "/home/alois/Documents/bah-bah/src/values.bah"
array(struct variable*)* symbols = memoryAlloc(sizeof(array(struct variable*)));

symbols->length = 0;
symbols->elemSize = sizeof(struct variable*);

#line 146 "/home/alois/Documents/bah-bah/src/values.bah"
register long int j = 0;

#line 146 "/home/alois/Documents/bah-bah/src/values.bah"
for (; (j<len(elems->vars)); 
#line 146 "/home/alois/Documents/bah-bah/src/values.bah"
++j) {

#line 147 "/home/alois/Documents/bah-bah/src/values.bah"
struct variable* v = elems->vars->data[j];

#line 148 "/home/alois/Documents/bah-bah/src/values.bah"
if ((v->isConst==false)) {

#line 149 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1148 = len(symbols);
    __Bah_realocate_arr(symbols, ____BAH_COMPILER_VAR_1148);
    symbols->data[____BAH_COMPILER_VAR_1148] = v;
}
};

#line 152 "/home/alois/Documents/bah-bah/src/values.bah"
struct variable* ____BAH_COMPILER_VAR_1149 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1149->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_1149->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_1149->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_1149->from = "\0\0\0\0""";
____BAH_COMPILER_VAR_1149->name = genCompilerVar();
____BAH_COMPILER_VAR_1149->type = "\020\0\0\0""[]reflectElement";
____BAH_COMPILER_VAR_1149->isArray = true;
struct variable* tmpV = ____BAH_COMPILER_VAR_1149;

#line 157 "/home/alois/Documents/bah-bah/src/values.bah"
char * decls = "\0\0\0\0""";

#line 158 "/home/alois/Documents/bah-bah/src/values.bah"
j = 0;

#line 158 "/home/alois/Documents/bah-bah/src/values.bah"
for (; (j<len(symbols)); 
#line 158 "/home/alois/Documents/bah-bah/src/values.bah"
++j) {

#line 159 "/home/alois/Documents/bah-bah/src/values.bah"
struct variable* v = symbols->data[j];

#line 160 "/home/alois/Documents/bah-bah/src/values.bah"
char * vname = v->name;

#line 161 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strCount(v->type,"\01\0\0\0""*")==0)) {

#line 162 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1150 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1150[1] = v->name;____BAH_COMPILER_VAR_1150[0] = "\01\0\0\0""&";char * ____BAH_COMPILER_VAR_1151 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1150, 2);vname = ____BAH_COMPILER_VAR_1151;
}

#line 164 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok ____BAH_COMPILER_VAR_1152 = {};
____BAH_COMPILER_VAR_1152.cont = "\0\0\0\0""";
____BAH_COMPILER_VAR_1152.ogCont = "\0\0\0\0""";
____BAH_COMPILER_VAR_1152.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1152.line = 1;
____BAH_COMPILER_VAR_1152.begLine = 1;
____BAH_COMPILER_VAR_1152.bahType = "\0\0\0\0""";
____BAH_COMPILER_VAR_1152.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_1152.cont = vname;
____BAH_COMPILER_VAR_1152.bahType = v->type;
____BAH_COMPILER_VAR_1152.isValue = true;
struct Tok tmpT = ____BAH_COMPILER_VAR_1152;

#line 170 "/home/alois/Documents/bah-bah/src/values.bah"
tmpT = parseReflect(tmpT,v->type,elems,true,v->name,"\01\0\0\0""0");

#line 171 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1153 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_1153[5] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_1153[4] = tmpT.cont;____BAH_COMPILER_VAR_1153[3] = "\04\0\0\0""] = ";____BAH_COMPILER_VAR_1153[2] = intToStr(j);____BAH_COMPILER_VAR_1153[1] = "\07\0\0\0""->data[";____BAH_COMPILER_VAR_1153[0] = tmpV->name;char * ____BAH_COMPILER_VAR_1154 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1153, 6);char** ____BAH_COMPILER_VAR_1155 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1155[1] = ____BAH_COMPILER_VAR_1154;____BAH_COMPILER_VAR_1155[0] = decls;char * ____BAH_COMPILER_VAR_1156 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1155, 2);decls = ____BAH_COMPILER_VAR_1156;
};

#line 173 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1157 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_1157);
    elems->vars->data[____BAH_COMPILER_VAR_1157] = tmpV;

#line 174 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1158 = alloca(15 * sizeof(char*));____BAH_COMPILER_VAR_1158[14] = "\011\0\0\0""\n        ";____BAH_COMPILER_VAR_1158[13] = decls;____BAH_COMPILER_VAR_1158[12] = "\064\0\0\0""->elemSize = sizeof(struct reflectElement);\n        ";____BAH_COMPILER_VAR_1158[11] = tmpV->name;____BAH_COMPILER_VAR_1158[10] = "\012\0\0\0"";\n        ";____BAH_COMPILER_VAR_1158[9] = intToStr(len(symbols));____BAH_COMPILER_VAR_1158[8] = "\013\0\0\0""->length = ";____BAH_COMPILER_VAR_1158[7] = tmpV->name;____BAH_COMPILER_VAR_1158[6] = "\013\0\0\0"");\n        ";____BAH_COMPILER_VAR_1158[5] = intToStr(len(symbols));____BAH_COMPILER_VAR_1158[4] = "\065\0\0\0""->data = memoryAlloc(sizeof(struct reflectElement) * ";____BAH_COMPILER_VAR_1158[3] = tmpV->name;____BAH_COMPILER_VAR_1158[2] = "\076\0\0\0"" = memoryAlloc(sizeof(array(struct reflectElement)));\n        ";____BAH_COMPILER_VAR_1158[1] = tmpV->name;____BAH_COMPILER_VAR_1158[0] = "\047\0\0\0""\n        array(struct reflectElement)* ";char * ____BAH_COMPILER_VAR_1159 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1158, 15);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1159));

#line 181 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok ____BAH_COMPILER_VAR_1160 = {};
____BAH_COMPILER_VAR_1160.cont = "\0\0\0\0""";
____BAH_COMPILER_VAR_1160.ogCont = "\0\0\0\0""";
____BAH_COMPILER_VAR_1160.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1160.line = 1;
____BAH_COMPILER_VAR_1160.begLine = 1;
____BAH_COMPILER_VAR_1160.bahType = "\0\0\0\0""";
____BAH_COMPILER_VAR_1160.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_1160.cont = tmpV->name;
____BAH_COMPILER_VAR_1160.line = fnt.line;
____BAH_COMPILER_VAR_1160.isValue = true;

    unsigned int ____BAH_COMPILER_VAR_1161 = 0;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1161);
    memory->data[____BAH_COMPILER_VAR_1161] = ____BAH_COMPILER_VAR_1160;
}

#line 187 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((strcmp(fn->name, "\012\0\0\0""breakPoint") == 0)) {

#line 188 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok ____BAH_COMPILER_VAR_1162 = {};
____BAH_COMPILER_VAR_1162.cont = "\0\0\0\0""";
____BAH_COMPILER_VAR_1162.ogCont = "\0\0\0\0""";
____BAH_COMPILER_VAR_1162.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1162.line = 1;
____BAH_COMPILER_VAR_1162.begLine = 1;
____BAH_COMPILER_VAR_1162.bahType = "\0\0\0\0""";
____BAH_COMPILER_VAR_1162.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_1162.cont = "\015\0\0\0""__dumpSymbols";
____BAH_COMPILER_VAR_1162.line = fnt.line;
struct Tok ____BAH_COMPILER_VAR_1163 = {};
____BAH_COMPILER_VAR_1163.cont = "\0\0\0\0""";
____BAH_COMPILER_VAR_1163.ogCont = "\0\0\0\0""";
____BAH_COMPILER_VAR_1163.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1163.line = 1;
____BAH_COMPILER_VAR_1163.begLine = 1;
____BAH_COMPILER_VAR_1163.bahType = "\0\0\0\0""";
____BAH_COMPILER_VAR_1163.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_1163.cont = "\01\0\0\0""(";
____BAH_COMPILER_VAR_1163.line = fnt.line;
struct Tok ____BAH_COMPILER_VAR_1164 = {};
____BAH_COMPILER_VAR_1164.cont = "\0\0\0\0""";
____BAH_COMPILER_VAR_1164.ogCont = "\0\0\0\0""";
____BAH_COMPILER_VAR_1164.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1164.line = 1;
____BAH_COMPILER_VAR_1164.begLine = 1;
____BAH_COMPILER_VAR_1164.bahType = "\0\0\0\0""";
____BAH_COMPILER_VAR_1164.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_1164.cont = "\01\0\0\0"")";
____BAH_COMPILER_VAR_1164.line = fnt.line;
memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 3;
memory->elemSize = sizeof(struct Tok);
memory->data = memoryAlloc(sizeof(struct Tok) * 50);
                    memory->realLength = 50;
memory->data[0] = ____BAH_COMPILER_VAR_1162;
memory->data[1] = ____BAH_COMPILER_VAR_1163;
memory->data[2] = ____BAH_COMPILER_VAR_1164;

#line 205 "/home/alois/Documents/bah-bah/src/values.bah"
memory = prePross(memory,LINE_TYPE_FN_CALL,elems);

#line 206 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok ____BAH_COMPILER_VAR_1165 = {};
____BAH_COMPILER_VAR_1165.cont = "\0\0\0\0""";
____BAH_COMPILER_VAR_1165.ogCont = "\0\0\0\0""";
____BAH_COMPILER_VAR_1165.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1165.line = 1;
____BAH_COMPILER_VAR_1165.begLine = 1;
____BAH_COMPILER_VAR_1165.bahType = "\0\0\0\0""";
____BAH_COMPILER_VAR_1165.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_1165.cont = "\01\0\0\0"",";
____BAH_COMPILER_VAR_1165.line = fnt.line;

    unsigned int ____BAH_COMPILER_VAR_1166 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1166);
    memory->data[____BAH_COMPILER_VAR_1166] = ____BAH_COMPILER_VAR_1165;

#line 211 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok ____BAH_COMPILER_VAR_1167 = {};
____BAH_COMPILER_VAR_1167.cont = "\0\0\0\0""";
____BAH_COMPILER_VAR_1167.ogCont = "\0\0\0\0""";
____BAH_COMPILER_VAR_1167.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1167.line = 1;
____BAH_COMPILER_VAR_1167.begLine = 1;
____BAH_COMPILER_VAR_1167.bahType = "\0\0\0\0""";
____BAH_COMPILER_VAR_1167.type = TOKEN_TYPE_STR;
____BAH_COMPILER_VAR_1167.cont = currLine;
____BAH_COMPILER_VAR_1167.line = fnt.line;

    unsigned int ____BAH_COMPILER_VAR_1168 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1168);
    memory->data[____BAH_COMPILER_VAR_1168] = ____BAH_COMPILER_VAR_1167;

#line 216 "/home/alois/Documents/bah-bah/src/values.bah"
fn = searchFunc("\021\0\0\0""breakPoint__inner",elems,true);

#line 217 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1169 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1169[1] = "\01\0\0\0""(";____BAH_COMPILER_VAR_1169[0] = fn->name;char * ____BAH_COMPILER_VAR_1170 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1169, 2);fnt.cont = ____BAH_COMPILER_VAR_1170;
}

#line 218 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((strcmp(fn->name, "\06\0\0\0""sizeof") == 0)) {

#line 219 "/home/alois/Documents/bah-bah/src/values.bah"
char * tp = "\0\0\0\0""";

#line 220 "/home/alois/Documents/bah-bah/src/values.bah"
register long int j = 0;

#line 220 "/home/alois/Documents/bah-bah/src/values.bah"
for (; (j<len(memory)); 
#line 220 "/home/alois/Documents/bah-bah/src/values.bah"
++j) {

#line 221 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok tmpT = memory->data[j];

#line 222 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1171 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1171[1] = tmpT.cont;____BAH_COMPILER_VAR_1171[0] = tp;char * ____BAH_COMPILER_VAR_1172 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1171, 2);tp = ____BAH_COMPILER_VAR_1172;
};

#line 224 "/home/alois/Documents/bah-bah/src/values.bah"
struct variable* tmpV = searchVar(tp,elems);

#line 225 "/home/alois/Documents/bah-bah/src/values.bah"
if ((tmpV!=null)) {

#line 226 "/home/alois/Documents/bah-bah/src/values.bah"
struct string cType = getCType(tmpV->type,elems);

#line 227 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1173 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1173[1] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1173[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_1174 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1173, 2);char** ____BAH_COMPILER_VAR_1175 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1175[1] = ____BAH_COMPILER_VAR_1174;____BAH_COMPILER_VAR_1175[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1176 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1175, 2);fnt.cont = ____BAH_COMPILER_VAR_1176;
}

#line 228 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 229 "/home/alois/Documents/bah-bah/src/values.bah"
struct string cType = getCType(tp,elems);

#line 230 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((cType.length==0), 0)) {

#line 231 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok ft = memory->data[0];

#line 232 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&ft,"\033\0\0\0""Cannot get size of {TOKEN}.");
}

#line 234 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1177 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1177[1] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1177[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_1178 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1177, 2);char** ____BAH_COMPILER_VAR_1179 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1179[1] = ____BAH_COMPILER_VAR_1178;____BAH_COMPILER_VAR_1179[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1180 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1179, 2);fnt.cont = ____BAH_COMPILER_VAR_1180;
}

#line 236 "/home/alois/Documents/bah-bah/src/values.bah"
fnt.type = TOKEN_TYPE_FUNC;

#line 237 "/home/alois/Documents/bah-bah/src/values.bah"
fnt.isFunc = true;

#line 238 "/home/alois/Documents/bah-bah/src/values.bah"
fnt.bahType = "\03\0\0\0""int";

#line 239 "/home/alois/Documents/bah-bah/src/values.bah"
fnt.bahRef = fn;

#line 240 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1181 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1181);
    l->data[____BAH_COMPILER_VAR_1181] = fnt;

#line 241 "/home/alois/Documents/bah-bah/src/values.bah"
return tokPos;
}

#line 245 "/home/alois/Documents/bah-bah/src/values.bah"
if ((len(memory)>0)) {

#line 246 "/home/alois/Documents/bah-bah/src/values.bah"
memory = prePross(memory,ltp,elems);
}

#line 249 "/home/alois/Documents/bah-bah/src/values.bah"
long int argIndex = 0;

#line 250 "/home/alois/Documents/bah-bah/src/values.bah"
if ((parent!=null)) {

#line 251 "/home/alois/Documents/bah-bah/src/values.bah"
char * amp = "\01\0\0\0""&";

#line 252 "/home/alois/Documents/bah-bah/src/values.bah"
if (isRCPpointerType(parent->type)) {

#line 253 "/home/alois/Documents/bah-bah/src/values.bah"
amp = "\0\0\0\0""";
}

#line 255 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1182 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1182[1] = parent->name;____BAH_COMPILER_VAR_1182[0] = amp;char * ____BAH_COMPILER_VAR_1183 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1182, 2);char** ____BAH_COMPILER_VAR_1184 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1184[1] = ____BAH_COMPILER_VAR_1183;____BAH_COMPILER_VAR_1184[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1185 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1184, 2);fnt.cont = ____BAH_COMPILER_VAR_1185;

#line 256 "/home/alois/Documents/bah-bah/src/values.bah"
++argIndex;

#line 257 "/home/alois/Documents/bah-bah/src/values.bah"
if ((len(fn->args)>argIndex)) {

#line 258 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1186 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1186[1] = "\01\0\0\0"",";____BAH_COMPILER_VAR_1186[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1187 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1186, 2);fnt.cont = ____BAH_COMPILER_VAR_1187;
}
}

#line 262 "/home/alois/Documents/bah-bah/src/values.bah"
unsigned long int ogFntContL = strlen(fnt.cont);

#line 264 "/home/alois/Documents/bah-bah/src/values.bah"
char * ltt = "\0\0\0\0""";

#line 267 "/home/alois/Documents/bah-bah/src/values.bah"
register long int j = 0;

#line 267 "/home/alois/Documents/bah-bah/src/values.bah"
for (; (j<len(memory)); 
#line 267 "/home/alois/Documents/bah-bah/src/values.bah"
++j) {

#line 268 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok t = memory->data[j];

#line 269 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((argIndex==len(fn->args)), 0)) {

#line 270 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1188 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1188[1] = getFuncDef(fn);____BAH_COMPILER_VAR_1188[0] = "\056\0\0\0""Too many arguments, expected ')' not {TOKEN}.\n";char * ____BAH_COMPILER_VAR_1189 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1188, 2);throwErr(&t,____BAH_COMPILER_VAR_1189);
}

#line 272 "/home/alois/Documents/bah-bah/src/values.bah"
struct variable* arg = fn->args->data[argIndex];

#line 273 "/home/alois/Documents/bah-bah/src/values.bah"
char * tt = getTypeFromToken(&t,true,elems);

#line 274 "/home/alois/Documents/bah-bah/src/values.bah"
ltt = tt;

#line 276 "/home/alois/Documents/bah-bah/src/values.bah"
if (((fn->isImported==true)||isInside(BAH_DIR,fn->file))&&(t.type==TOKEN_TYPE_VAR)) {

#line 277 "/home/alois/Documents/bah-bah/src/values.bah"
fixMeTestVar(&t,ltp,elems);
}

#line 280 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(arg->type, "\016\0\0\0""reflectElement") == 0)&&(strcmp(tt, "\016\0\0\0""reflectElement") != 0)) {

#line 281 "/home/alois/Documents/bah-bah/src/values.bah"
t = parseReflect(t,tt,elems,false,t.cont,"\01\0\0\0""0");

#line 282 "/home/alois/Documents/bah-bah/src/values.bah"
tt = "\016\0\0\0""reflectElement";
}

#line 285 "/home/alois/Documents/bah-bah/src/values.bah"
if ((generic!=null)&&(strcmp(arg->type, "\05\0\0\0""<any>") == 0)) {

#line 286 "/home/alois/Documents/bah-bah/src/values.bah"
arg->type = tt;

#line 287 "/home/alois/Documents/bah-bah/src/values.bah"
struct string tts = string(tt);

#line 288 "/home/alois/Documents/bah-bah/src/values.bah"
string__replace(&tts,"\01\0\0\0""*","\05\0\0\0""_AST_");

#line 289 "/home/alois/Documents/bah-bah/src/values.bah"
string__replace(&tts,"\01\0\0\0"":","\04\0\0\0""_DP_");

#line 290 "/home/alois/Documents/bah-bah/src/values.bah"
string__replace(&tts,"\02\0\0\0""[]","\05\0\0\0""_ARR_");

#line 291 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1190 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1190[1] = string__str(&tts);____BAH_COMPILER_VAR_1190[0] = "\02\0\0\0""__";char * ____BAH_COMPILER_VAR_1191 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1190, 2);char** ____BAH_COMPILER_VAR_1192 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1192[1] = ____BAH_COMPILER_VAR_1191;____BAH_COMPILER_VAR_1192[0] = fn->name;char * ____BAH_COMPILER_VAR_1193 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1192, 2);fn->name = ____BAH_COMPILER_VAR_1193;
}

#line 292 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 293 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((compTypes(arg->type,tt)==false), 0)) {

#line 294 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1194 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_1194[5] = getFuncDef(fn);____BAH_COMPILER_VAR_1194[4] = "\023\0\0\0"" in function call.\n";____BAH_COMPILER_VAR_1194[3] = arg->type;____BAH_COMPILER_VAR_1194[2] = "\05\0\0\0"") as ";____BAH_COMPILER_VAR_1194[1] = tt;____BAH_COMPILER_VAR_1194[0] = "\024\0\0\0""Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_1195 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1194, 6);throwErr(&t,____BAH_COMPILER_VAR_1195);
}
}

#line 298 "/home/alois/Documents/bah-bah/src/values.bah"

                struct string ____BAH_COMPILER_VAR_1196 = string(tt);
                if (string__hasPrefix(&____BAH_COMPILER_VAR_1196,"\07\0\0\0""buffer:")&&(fn->isCbinding==false)&&(strcmp(arg->type, "\010\0\0\0""cpstring") == 0)) {

#line 299 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1197 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1197[2] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1197[1] = t.cont;____BAH_COMPILER_VAR_1197[0] = "\012\0\0\0""buffToStr(";char * ____BAH_COMPILER_VAR_1198 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1197, 3);t.cont = ____BAH_COMPILER_VAR_1198;
}

#line 302 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(tt, "\010\0\0\0""cpstring") == 0)&&fn->isCbinding&&(strcmp(fn->name, "\06\0\0\0""strlen") != 0)) {

#line 303 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1199 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1199[2] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1199[1] = t.cont;____BAH_COMPILER_VAR_1199[0] = "\05\0\0\0""cStr(";char * ____BAH_COMPILER_VAR_1200 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1199, 3);t.cont = ____BAH_COMPILER_VAR_1200;
}

#line 306 "/home/alois/Documents/bah-bah/src/values.bah"
checkCanBeNull(&t,tt,elems);

#line 308 "/home/alois/Documents/bah-bah/src/values.bah"
if ((RCPavailable()==true)&&(ltp==LINE_TYPE_VAR)&&(t.type==TOKEN_TYPE_VAR)&&(t.isOper==false)&&(currSetVar!=null)&&(strcmp(t.cont, currSetVar->name) == 0)&&isRCPtype(currSetVar->type,elems)) {

#line 309 "/home/alois/Documents/bah-bah/src/values.bah"
OUTPUT = rope__add(OUTPUT, incrVar(currSetVar,elems));
}

#line 312 "/home/alois/Documents/bah-bah/src/values.bah"
if (RCPavailable()&&(t.type==TOKEN_TYPE_FUNC)) {

#line 313 "/home/alois/Documents/bah-bah/src/values.bah"
struct func* afn = searchFuncByToken(&t,elems);

#line 314 "/home/alois/Documents/bah-bah/src/values.bah"
if ((afn!=null)&&(isRCPtype(afn->returns->type,elems)==true)) {

#line 315 "/home/alois/Documents/bah-bah/src/values.bah"
if ((ltp==LINE_TYPE_ELSE)) {

#line 316 "/home/alois/Documents/bah-bah/src/values.bah"
char * vName = genCompilerVar();

#line 317 "/home/alois/Documents/bah-bah/src/values.bah"

                struct string ____BAH_COMPILER_VAR_1201 = getCType(afn->returns->type,elems);
                char** ____BAH_COMPILER_VAR_1202 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1202[3] = "\01\0\0\0"";";____BAH_COMPILER_VAR_1202[2] = vName;____BAH_COMPILER_VAR_1202[1] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_1202[0] = string__str(&____BAH_COMPILER_VAR_1201);char * ____BAH_COMPILER_VAR_1203 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1202, 4);char * code = ____BAH_COMPILER_VAR_1203;

#line 318 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1204 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1204[1] = code;____BAH_COMPILER_VAR_1204[0] = rope__toStr(begIfHandle);char * ____BAH_COMPILER_VAR_1205 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1204, 2);long int diff = ropeSet(begIfHandle,____BAH_COMPILER_VAR_1205);

#line 319 "/home/alois/Documents/bah-bah/src/values.bah"
println(intToStr(diff));

#line 320 "/home/alois/Documents/bah-bah/src/values.bah"
OUTPUT->totalLen = OUTPUT->totalLen+diff;

#line 321 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1206 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1206[4] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1206[3] = t.cont;____BAH_COMPILER_VAR_1206[2] = "\01\0\0\0""=";____BAH_COMPILER_VAR_1206[1] = vName;____BAH_COMPILER_VAR_1206[0] = "\01\0\0\0""(";char * ____BAH_COMPILER_VAR_1207 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1206, 5);t.cont = ____BAH_COMPILER_VAR_1207;

#line 322 "/home/alois/Documents/bah-bah/src/values.bah"
struct variable* ____BAH_COMPILER_VAR_1208 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1208->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_1208->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_1208->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_1208->from = "\0\0\0\0""";
____BAH_COMPILER_VAR_1208->name = vName;
____BAH_COMPILER_VAR_1208->type = afn->returns->type;

    unsigned int ____BAH_COMPILER_VAR_1209 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_1209);
    elems->vars->data[____BAH_COMPILER_VAR_1209] = ____BAH_COMPILER_VAR_1208;
}

#line 326 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 327 "/home/alois/Documents/bah-bah/src/values.bah"
t.cont = registerRCPvar(afn->returns->type,t.cont,elems);
}
}
}

#line 332 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1210 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1210[1] = t.cont;____BAH_COMPILER_VAR_1210[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1211 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1210, 2);fnt.cont = ____BAH_COMPILER_VAR_1211;

#line 334 "/home/alois/Documents/bah-bah/src/values.bah"
++argIndex;

#line 336 "/home/alois/Documents/bah-bah/src/values.bah"
if ((j+1<len(memory))) {

#line 337 "/home/alois/Documents/bah-bah/src/values.bah"
++j;

#line 338 "/home/alois/Documents/bah-bah/src/values.bah"
t = memory->data[j];

#line 339 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((strcmp(t.cont, "\01\0\0\0"",") != 0), 0)) {

#line 340 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1212 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1212[1] = getFuncDef(fn);____BAH_COMPILER_VAR_1212[0] = "\057\0\0\0""Need separator between arguments, not {TOKEN}.\n";char * ____BAH_COMPILER_VAR_1213 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1212, 2);throwErr(&t,____BAH_COMPILER_VAR_1213);
}

#line 342 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((j+1>=len(memory)), 0)) {

#line 343 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1214 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1214[1] = getFuncDef(fn);____BAH_COMPILER_VAR_1214[0] = "\051\0\0\0""Trailing {TOKEN} with no argument after.\n";char * ____BAH_COMPILER_VAR_1215 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1214, 2);throwErr(&t,____BAH_COMPILER_VAR_1215);
}

#line 345 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1216 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1216[1] = "\01\0\0\0"",";____BAH_COMPILER_VAR_1216[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1217 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1216, 2);fnt.cont = ____BAH_COMPILER_VAR_1217;
}
};

#line 350 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((argIndex!=len(fn->args)), 0)) {

#line 351 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1218 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1218[3] = getFuncDef(fn);____BAH_COMPILER_VAR_1218[2] = "\03\0\0\0""'.\n";____BAH_COMPILER_VAR_1218[1] = fn->name;____BAH_COMPILER_VAR_1218[0] = "\046\0\0\0""Not enough argument {TOKEN}, calling '";char * ____BAH_COMPILER_VAR_1219 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1218, 4);throwErr(&fnt,____BAH_COMPILER_VAR_1219);
}

#line 354 "/home/alois/Documents/bah-bah/src/values.bah"
if ((generic!=null)) {

#line 355 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1220 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1220[3] = cpstringSubsitute(fnt.cont, ogFntContL, strlen(fnt.cont));____BAH_COMPILER_VAR_1220[2] = "\01\0\0\0""(";____BAH_COMPILER_VAR_1220[1] = fn->name;____BAH_COMPILER_VAR_1220[0] = "\012\0\0\0""__generic_";char * ____BAH_COMPILER_VAR_1221 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1220, 4);fnt.cont = ____BAH_COMPILER_VAR_1221;

#line 356 "/home/alois/Documents/bah-bah/src/values.bah"
if ((genericFunc__isAlreadyDecl(generic,fn->name)==false)) {

#line 357 "/home/alois/Documents/bah-bah/src/values.bah"
genericFunc__declare(generic,fn,elems);
}
}

#line 362 "/home/alois/Documents/bah-bah/src/values.bah"
fnt.bahRef = fn;

#line 363 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1222 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1222[1] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1222[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1223 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1222, 2);fnt.cont = ____BAH_COMPILER_VAR_1223;

#line 364 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(fn->name, "\06\0\0\0""strlen") == 0)&&(strcmp(ltt, "\010\0\0\0""cpstring") != 0)) {

#line 365 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1224 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1224[1] = fnt.cont;____BAH_COMPILER_VAR_1224[0] = "\01\0\0\0""C";char * ____BAH_COMPILER_VAR_1225 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1224, 2);fnt.cont = ____BAH_COMPILER_VAR_1225;
}

#line 366 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((strcmp(fn->name, "\03\0\0\0""len") == 0)&&(strcmp(ltt, "\010\0\0\0""cpstring") == 0)) {

#line 367 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1226 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1226[1] = fnt.cont;____BAH_COMPILER_VAR_1226[0] = "\03\0\0\0""str";char * ____BAH_COMPILER_VAR_1227 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1226, 2);fnt.cont = ____BAH_COMPILER_VAR_1227;
}

#line 368 "/home/alois/Documents/bah-bah/src/values.bah"
else if (fn->isCbinding&&(strcmp(fn->returns->type, "\010\0\0\0""cpstring") == 0)) {

#line 369 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1228 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1228[2] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1228[1] = fnt.cont;____BAH_COMPILER_VAR_1228[0] = "\012\0\0\0""cStrToBah(";char * ____BAH_COMPILER_VAR_1229 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1228, 3);fnt.cont = ____BAH_COMPILER_VAR_1229;
}

#line 372 "/home/alois/Documents/bah-bah/src/values.bah"
if ((noticeEnabled==true)&&(strcmp(ltt, "\010\0\0\0""cpstring") == 0)&&(strcmp(fn->name, "\06\0\0\0""strlen") == 0)) {

#line 373 "/home/alois/Documents/bah-bah/src/values.bah"
throwNoticeLine("\117\0\0\0""Function strlen() can be used for char*. Use len() for better code readability.",l->data[tokPos].line);
}

#line 375 "/home/alois/Documents/bah-bah/src/values.bah"

                struct string ____BAH_COMPILER_VAR_1230 = string(ltt);
                if (__builtin_expect((isUnsafe==false)&&(strcmp(fn->name, "\03\0\0\0""len") == 0)&&(strcmp(ltt, "\010\0\0\0""cpstring") != 0)&&(string__hasPrefix(&____BAH_COMPILER_VAR_1230,"\02\0\0\0""[]")==false), 0)) {

#line 376 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1231 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1231[2] = "\027\0\0\0"") as cpstring or array.";____BAH_COMPILER_VAR_1231[1] = ltt;____BAH_COMPILER_VAR_1231[0] = "\031\0\0\0""Cannot use len({TOKEN}) (";char * ____BAH_COMPILER_VAR_1232 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1231, 3);throwErr(&memory->data[0],____BAH_COMPILER_VAR_1232);
}

#line 379 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1233 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1233);
    l->data[____BAH_COMPILER_VAR_1233] = fnt;

#line 380 "/home/alois/Documents/bah-bah/src/values.bah"
return tokPos;
};

#line 384 "/home/alois/Documents/bah-bah/src/values.bah"
long int valueStruct(__BAH_ARR_TYPE_Tok l,long int i,lineType ltp,struct Elems* elems){

#line 385 "/home/alois/Documents/bah-bah/src/values.bah"
long int tokPos = i-1;

#line 389 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok t = l->data[i-1];

#line 390 "/home/alois/Documents/bah-bah/src/values.bah"
char * tt = getTypeFromToken(&t,true,elems);

#line 392 "/home/alois/Documents/bah-bah/src/values.bah"
struct cStruct* s = searchStruct(tt,elems);

#line 393 "/home/alois/Documents/bah-bah/src/values.bah"
if ((s==null)) {

#line 394 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((tt[strlen(tt)-1+4]==33), 0)) {

#line 395 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1234 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1234[2] = "\017\0\0\0"") as structure.";____BAH_COMPILER_VAR_1234[1] = tt;____BAH_COMPILER_VAR_1234[0] = "\040\0\0\0""Cannot use maybe value {TOKEN} (";char * ____BAH_COMPILER_VAR_1235 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1234, 3);throwErr(&t,____BAH_COMPILER_VAR_1235);
}

#line 396 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 397 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1236 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1236[2] = "\02\0\0\0"").";____BAH_COMPILER_VAR_1236[1] = tt;____BAH_COMPILER_VAR_1236[0] = "\027\0\0\0""Unkown struct {TOKEN} (";char * ____BAH_COMPILER_VAR_1237 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1236, 3);throwErr(&t,____BAH_COMPILER_VAR_1237);
}
}

#line 401 "/home/alois/Documents/bah-bah/src/values.bah"
checkCanBeNull(&t,tt,elems);

#line 404 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok nt = l->data[i+1];

#line 406 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((nt.isValue==false), 0)) {

#line 407 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&nt,"\035\0\0\0""Cannot use {TOKEN} as member.");
}

#line 409 "/home/alois/Documents/bah-bah/src/values.bah"
deleteRange(l,i,i+1);

#line 412 "/home/alois/Documents/bah-bah/src/values.bah"
char * sep = "\01\0\0\0"".";

#line 413 "/home/alois/Documents/bah-bah/src/values.bah"
if (isRCPpointerType(tt)) {

#line 414 "/home/alois/Documents/bah-bah/src/values.bah"
sep = "\02\0\0\0""->";
}

#line 418 "/home/alois/Documents/bah-bah/src/values.bah"
if ((t.type==TOKEN_TYPE_VAR)) {

#line 419 "/home/alois/Documents/bah-bah/src/values.bah"
fixMeTestVar(&t,ltp,elems);
}

#line 423 "/home/alois/Documents/bah-bah/src/values.bah"
if ((i<len(l))) {

#line 424 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok ntt = l->data[i];

#line 425 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(ntt.cont, "\01\0\0\0""(") == 0)) {

#line 426 "/home/alois/Documents/bah-bah/src/values.bah"
struct variable* parent= null;

#line 427 "/home/alois/Documents/bah-bah/src/values.bah"
if ((t.type==TOKEN_TYPE_VAR)) {

#line 428 "/home/alois/Documents/bah-bah/src/values.bah"
if ((t.bahRef!=null)) {

#line 430 "/home/alois/Documents/bah-bah/src/values.bah"
parent = t.bahRef;
}

#line 431 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 432 "/home/alois/Documents/bah-bah/src/values.bah"
parent = searchVar(t.cont,elems);
}
}

#line 434 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 435 "/home/alois/Documents/bah-bah/src/values.bah"
char * tmpV = genCompilerVar();

#line 436 "/home/alois/Documents/bah-bah/src/values.bah"
struct string cType = getCType(tt,elems);

#line 437 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1238 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_1238[6] = "\022\0\0\0"";\n                ";____BAH_COMPILER_VAR_1238[5] = t.cont;____BAH_COMPILER_VAR_1238[4] = "\03\0\0\0"" = ";____BAH_COMPILER_VAR_1238[3] = tmpV;____BAH_COMPILER_VAR_1238[2] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_1238[1] = string__str(&cType);____BAH_COMPILER_VAR_1238[0] = "\021\0\0\0""\n                ";char * ____BAH_COMPILER_VAR_1239 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1238, 7);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1239));

#line 440 "/home/alois/Documents/bah-bah/src/values.bah"
t.cont = tmpV;

#line 441 "/home/alois/Documents/bah-bah/src/values.bah"
struct variable* ____BAH_COMPILER_VAR_1240 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1240->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_1240->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_1240->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_1240->from = "\0\0\0\0""";
____BAH_COMPILER_VAR_1240->name = tmpV;
____BAH_COMPILER_VAR_1240->type = tt;
parent = ____BAH_COMPILER_VAR_1240;

#line 445 "/home/alois/Documents/bah-bah/src/values.bah"
if (RCPavailable()) {

#line 446 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1241 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_1241);
    elems->vars->data[____BAH_COMPILER_VAR_1241] = parent;
}
}

#line 449 "/home/alois/Documents/bah-bah/src/values.bah"
struct func* fn = searchStructMethod(nt.cont,s,elems);

#line 450 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((fn==null), 0)) {

#line 451 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1242 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1242[2] = "\01\0\0\0"".";____BAH_COMPILER_VAR_1242[1] = s->name;____BAH_COMPILER_VAR_1242[0] = "\041\0\0\0""Unknown method {TOKEN} in struct ";char * ____BAH_COMPILER_VAR_1243 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1242, 3);throwErr(&nt,____BAH_COMPILER_VAR_1243);
}

#line 453 "/home/alois/Documents/bah-bah/src/values.bah"
if ((t.type==TOKEN_TYPE_VAR)) {

#line 454 "/home/alois/Documents/bah-bah/src/values.bah"
if ((fn->isImported==true)||(fn->isMut==true)) {

#line 455 "/home/alois/Documents/bah-bah/src/values.bah"
struct variable* rp = searchVarByToken(&t,elems);

#line 456 "/home/alois/Documents/bah-bah/src/values.bah"
rp->lastSet = elems;

#line 457 "/home/alois/Documents/bah-bah/src/values.bah"
if ((rp->isArg==true)) {

#line 458 "/home/alois/Documents/bah-bah/src/values.bah"
currentFn->isMut = true;
}
}
}

#line 462 "/home/alois/Documents/bah-bah/src/values.bah"
if ((fn->isVar==true)) {

#line 463 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1244 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1244[2] = fn->name;____BAH_COMPILER_VAR_1244[1] = sep;____BAH_COMPILER_VAR_1244[0] = t.cont;char * ____BAH_COMPILER_VAR_1245 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1244, 3);fn->name = ____BAH_COMPILER_VAR_1245;
}

#line 465 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((parent==null), 0)) {

#line 466 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&t,"\041\0\0\0""Could not find structure {TOKEN}.");
}

#line 468 "/home/alois/Documents/bah-bah/src/values.bah"
valueFunc(fn,parent,l,i,ltp,elems);

#line 469 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok fnt = l->data[i];

#line 470 "/home/alois/Documents/bah-bah/src/values.bah"
delete(l,i);

#line 471 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1246 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1246[2] = nt.ogCont;____BAH_COMPILER_VAR_1246[1] = "\01\0\0\0"".";____BAH_COMPILER_VAR_1246[0] = t.ogCont;char * ____BAH_COMPILER_VAR_1247 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1246, 3);fnt.ogCont = ____BAH_COMPILER_VAR_1247;

#line 472 "/home/alois/Documents/bah-bah/src/values.bah"
fnt.pos = t.pos;

#line 475 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1248 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1248);
    l->data[____BAH_COMPILER_VAR_1248] = fnt;

#line 476 "/home/alois/Documents/bah-bah/src/values.bah"
return tokPos;
}
}

#line 481 "/home/alois/Documents/bah-bah/src/values.bah"
struct structMemb* m = searchStructMemb(nt.cont,s,elems);

#line 482 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((m==null), 0)) {

#line 483 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1249 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1249[2] = "\02\0\0\0""'.";____BAH_COMPILER_VAR_1249[1] = s->name;____BAH_COMPILER_VAR_1249[0] = "\051\0\0\0""Unknown struct member {TOKEN} in struct '";char * ____BAH_COMPILER_VAR_1250 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1249, 3);throwErr(&nt,____BAH_COMPILER_VAR_1250);
}

#line 485 "/home/alois/Documents/bah-bah/src/values.bah"
char * ast = "\0\0\0\0""";

#line 486 "/home/alois/Documents/bah-bah/src/values.bah"
if ((t.cont[0+4]==38)) {

#line 487 "/home/alois/Documents/bah-bah/src/values.bah"
ast = "\01\0\0\0""*";
}

#line 489 "/home/alois/Documents/bah-bah/src/values.bah"
if ((m->isFn==true)) {

#line 490 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1251 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1251[2] = m->name;____BAH_COMPILER_VAR_1251[1] = "\02\0\0\0""__";____BAH_COMPILER_VAR_1251[0] = s->name;char * ____BAH_COMPILER_VAR_1252 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1251, 3);t.cont = ____BAH_COMPILER_VAR_1252;
}

#line 491 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 492 "/home/alois/Documents/bah-bah/src/values.bah"
if ((t.type==TOKEN_TYPE_VAR)) {

#line 493 "/home/alois/Documents/bah-bah/src/values.bah"
t.parent = searchVarByToken(&t,elems);
}

#line 495 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1253 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1253[1] = nt.cont;____BAH_COMPILER_VAR_1253[0] = sep;char * ____BAH_COMPILER_VAR_1254 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1253, 2);char** ____BAH_COMPILER_VAR_1255 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1255[1] = ____BAH_COMPILER_VAR_1254;____BAH_COMPILER_VAR_1255[0] = t.cont;char * ____BAH_COMPILER_VAR_1256 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1255, 2);t.cont = ____BAH_COMPILER_VAR_1256;
}

#line 497 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1257 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1257[1] = nt.cont;____BAH_COMPILER_VAR_1257[0] = "\01\0\0\0"".";char * ____BAH_COMPILER_VAR_1258 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1257, 2);char** ____BAH_COMPILER_VAR_1259 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1259[1] = ____BAH_COMPILER_VAR_1258;____BAH_COMPILER_VAR_1259[0] = t.ogCont;char * ____BAH_COMPILER_VAR_1260 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1259, 2);t.ogCont = ____BAH_COMPILER_VAR_1260;

#line 498 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1261 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1261[1] = ast;____BAH_COMPILER_VAR_1261[0] = m->type;char * ____BAH_COMPILER_VAR_1262 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1261, 2);t.bahType = ____BAH_COMPILER_VAR_1262;

#line 499 "/home/alois/Documents/bah-bah/src/values.bah"
struct variable* ____BAH_COMPILER_VAR_1263 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1263->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_1263->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_1263->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_1263->from = "\0\0\0\0""";
____BAH_COMPILER_VAR_1263->name = t.cont;
____BAH_COMPILER_VAR_1263->type = t.bahType;
t.bahRef = ____BAH_COMPILER_VAR_1263;

#line 504 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1264 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1264);
    l->data[____BAH_COMPILER_VAR_1264] = t;

#line 505 "/home/alois/Documents/bah-bah/src/values.bah"
return tokPos;
};

#line 508 "/home/alois/Documents/bah-bah/src/values.bah"
long int valueArr(__BAH_ARR_TYPE_Tok l,long int i,lineType ltp,struct Elems* elems){

#line 509 "/home/alois/Documents/bah-bah/src/values.bah"
long int tokPos = i-1;

#line 511 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok pt = l->data[tokPos];

#line 512 "/home/alois/Documents/bah-bah/src/values.bah"
delete(l,tokPos);

#line 513 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((pt.isValue==false), 0)) {

#line 514 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&pt,"\044\0\0\0""Cannot use {TOKEN} as value (array).");
}

#line 516 "/home/alois/Documents/bah-bah/src/values.bah"
struct string ptt = string(getTypeFromToken(&pt,true,elems));

#line 519 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok t = pt;

#line 520 "/home/alois/Documents/bah-bah/src/values.bah"
t.isValue = true;

#line 521 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1265 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1265[1] = "\01\0\0\0""[";____BAH_COMPILER_VAR_1265[0] = t.ogCont;char * ____BAH_COMPILER_VAR_1266 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1265, 2);t.ogCont = ____BAH_COMPILER_VAR_1266;

#line 524 "/home/alois/Documents/bah-bah/src/values.bah"
long int nbEncls = 1;

#line 525 "/home/alois/Documents/bah-bah/src/values.bah"
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);

#line 526 "/home/alois/Documents/bah-bah/src/values.bah"
i = tokPos+1;

#line 527 "/home/alois/Documents/bah-bah/src/values.bah"
for (; (i<len(l)); 
#line 527 "/home/alois/Documents/bah-bah/src/values.bah"
++i) {

#line 528 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok tmpT = l->data[i];

#line 529 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(tmpT.cont, "\01\0\0\0""(") == 0)||(strcmp(tmpT.cont, "\01\0\0\0""{") == 0)||(strcmp(tmpT.cont, "\01\0\0\0""[") == 0)) {

#line 530 "/home/alois/Documents/bah-bah/src/values.bah"
++nbEncls;
}

#line 531 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((strcmp(tmpT.cont, "\01\0\0\0"")") == 0)||(strcmp(tmpT.cont, "\01\0\0\0""}") == 0)||(strcmp(tmpT.cont, "\01\0\0\0""]") == 0)) {

#line 532 "/home/alois/Documents/bah-bah/src/values.bah"
--nbEncls;

#line 533 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1267 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1267[1] = "\01\0\0\0""]";____BAH_COMPILER_VAR_1267[0] = t.ogCont;char * ____BAH_COMPILER_VAR_1268 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1267, 2);t.ogCont = ____BAH_COMPILER_VAR_1268;

#line 534 "/home/alois/Documents/bah-bah/src/values.bah"
if ((nbEncls==0)) {

#line 535 "/home/alois/Documents/bah-bah/src/values.bah"
break;
}
}

#line 538 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1269 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1269[1] = tmpT.ogCont;____BAH_COMPILER_VAR_1269[0] = t.ogCont;char * ____BAH_COMPILER_VAR_1270 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1269, 2);t.ogCont = ____BAH_COMPILER_VAR_1270;

#line 539 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1271 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1271);
    memory->data[____BAH_COMPILER_VAR_1271] = tmpT;
};

#line 541 "/home/alois/Documents/bah-bah/src/values.bah"
deleteRange(l,tokPos+1,i);

#line 542 "/home/alois/Documents/bah-bah/src/values.bah"
memory = prePross(memory,(lineType)-1,elems);

#line 545 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((len(memory)==0), 0)) {

#line 546 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&pt,"\053\0\0\0""Cannot access empty index of array {TOKEN}.");
}

#line 550 "/home/alois/Documents/bah-bah/src/values.bah"
char split = false;

#line 551 "/home/alois/Documents/bah-bah/src/values.bah"
char * from = "\0\0\0\0""";

#line 552 "/home/alois/Documents/bah-bah/src/values.bah"
char * to = "\0\0\0\0""";

#line 553 "/home/alois/Documents/bah-bah/src/values.bah"
if ((len(memory)>1)) {

#line 554 "/home/alois/Documents/bah-bah/src/values.bah"
split = true;

#line 555 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok first = memory->data[0];

#line 556 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok second;

#line 557 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok third;

#line 559 "/home/alois/Documents/bah-bah/src/values.bah"
if ((len(memory)==3)) {

#line 560 "/home/alois/Documents/bah-bah/src/values.bah"
second = memory->data[1];

#line 561 "/home/alois/Documents/bah-bah/src/values.bah"
third = memory->data[2];

#line 562 "/home/alois/Documents/bah-bah/src/values.bah"
char * firstT = getTypeFromToken(&first,true,elems);

#line 563 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((compTypes(firstT,"\03\0\0\0""int")==false), 0)) {

#line 564 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&first,"\032\0\0\0""Cannot use {TOKEN} as int.");
}

#line 566 "/home/alois/Documents/bah-bah/src/values.bah"
char * thirdT = getTypeFromToken(&third,true,elems);

#line 567 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((compTypes(thirdT,"\03\0\0\0""int")==false), 0)) {

#line 568 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&third,"\032\0\0\0""Cannot use {TOKEN} as int.");
}

#line 570 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((strcmp(second.cont, "\01\0\0\0"":") != 0), 0)) {

#line 571 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&second,"\031\0\0\0""Expected ':' not {TOKEN}.");
}

#line 573 "/home/alois/Documents/bah-bah/src/values.bah"
from = first.cont;

#line 574 "/home/alois/Documents/bah-bah/src/values.bah"
to = third.cont;
}

#line 575 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((len(memory)==2)) {

#line 576 "/home/alois/Documents/bah-bah/src/values.bah"
second = memory->data[1];

#line 578 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(first.cont, "\01\0\0\0"":") == 0)) {

#line 579 "/home/alois/Documents/bah-bah/src/values.bah"
from = "\01\0\0\0""0";

#line 580 "/home/alois/Documents/bah-bah/src/values.bah"
char * secondT = getTypeFromToken(&second,true,elems);

#line 581 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((compTypes(secondT,"\03\0\0\0""int")==false), 0)) {

#line 582 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&second,"\032\0\0\0""Cannot use {TOKEN} as int.");
}

#line 584 "/home/alois/Documents/bah-bah/src/values.bah"
to = second.cont;
}

#line 585 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((strcmp(second.cont, "\01\0\0\0"":") == 0)) {

#line 586 "/home/alois/Documents/bah-bah/src/values.bah"
char * firstT = getTypeFromToken(&first,true,elems);

#line 587 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((compTypes(firstT,"\03\0\0\0""int")==false), 0)) {

#line 588 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&first,"\032\0\0\0""Cannot use {TOKEN} as int.");
}

#line 590 "/home/alois/Documents/bah-bah/src/values.bah"
from = first.cont;
}

#line 591 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 592 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&second,"\030\0\0\0""Expected ':' not {TOKEN}");
}
}

#line 594 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 595 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&memory->data[3],"\104\0\0\0""Cannot substiture with more than 2 values, expected ']' not {TOKEN}.");
}
}

#line 599 "/home/alois/Documents/bah-bah/src/values.bah"
if (string__hasPrefix(&ptt,"\02\0\0\0""[]")) {

#line 600 "/home/alois/Documents/bah-bah/src/values.bah"
if ((split==false)) {

#line 601 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok index = memory->data[0];

#line 602 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((compTypes(getTypeFromToken(&index,true,elems),"\03\0\0\0""int")==false), 0)) {

#line 603 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&index,"\050\0\0\0""Cannot use {TOKEN} as array index (int).");
}

#line 605 "/home/alois/Documents/bah-bah/src/values.bah"
string__trimLeft(&ptt,2);

#line 606 "/home/alois/Documents/bah-bah/src/values.bah"
t.bahType = string__str(&ptt);

#line 607 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1272 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1272[3] = "\01\0\0\0""]";____BAH_COMPILER_VAR_1272[2] = index.cont;____BAH_COMPILER_VAR_1272[1] = "\07\0\0\0""->data[";____BAH_COMPILER_VAR_1272[0] = pt.cont;char * ____BAH_COMPILER_VAR_1273 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1272, 4);t.cont = ____BAH_COMPILER_VAR_1273;

#line 609 "/home/alois/Documents/bah-bah/src/values.bah"
if ((tokPos+1<len(l))&&(strcmp(l->data[tokPos+1].cont, "\01\0\0\0"".") == 0)) {

#line 610 "/home/alois/Documents/bah-bah/src/values.bah"
struct variable* ____BAH_COMPILER_VAR_1274 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1274->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_1274->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_1274->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_1274->from = "\0\0\0\0""";
____BAH_COMPILER_VAR_1274->name = t.cont;
____BAH_COMPILER_VAR_1274->type = t.bahType;
struct variable* tmpV = ____BAH_COMPILER_VAR_1274;

#line 614 "/home/alois/Documents/bah-bah/src/values.bah"
t.bahRef = tmpV;
}
}

#line 617 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 618 "/home/alois/Documents/bah-bah/src/values.bah"
t.bahType = string__str(&ptt);

#line 619 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(to, "\0\0\0\0""") == 0)) {

#line 620 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1275 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1275[1] = "\010\0\0\0""->length";____BAH_COMPILER_VAR_1275[0] = pt.cont;char * ____BAH_COMPILER_VAR_1276 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1275, 2);to = ____BAH_COMPILER_VAR_1276;
}

#line 622 "/home/alois/Documents/bah-bah/src/values.bah"
t.isFunc = true;

#line 623 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1277 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_1277[6] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1277[5] = to;____BAH_COMPILER_VAR_1277[4] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_1277[3] = from;____BAH_COMPILER_VAR_1277[2] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_1277[1] = pt.cont;____BAH_COMPILER_VAR_1277[0] = "\020\0\0\0""arraySubstitute(";char * ____BAH_COMPILER_VAR_1278 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1277, 7);t.cont = ____BAH_COMPILER_VAR_1278;
}
}

#line 626 "/home/alois/Documents/bah-bah/src/values.bah"
else if (string__hasPrefix(&ptt,"\07\0\0\0""buffer:")) {

#line 627 "/home/alois/Documents/bah-bah/src/values.bah"
if ((split==false)) {

#line 628 "/home/alois/Documents/bah-bah/src/values.bah"
t.bahType = "\04\0\0\0""char";

#line 629 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok index = memory->data[0];

#line 630 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((compTypes(getTypeFromToken(&index,true,elems),"\03\0\0\0""int")==false), 0)) {

#line 631 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&index,"\051\0\0\0""Cannot use {TOKEN} as buffer index (int).");
}

#line 633 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1279 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1279[3] = "\01\0\0\0""]";____BAH_COMPILER_VAR_1279[2] = index.cont;____BAH_COMPILER_VAR_1279[1] = "\01\0\0\0""[";____BAH_COMPILER_VAR_1279[0] = pt.cont;char * ____BAH_COMPILER_VAR_1280 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1279, 4);t.cont = ____BAH_COMPILER_VAR_1280;
}

#line 634 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 635 "/home/alois/Documents/bah-bah/src/values.bah"
t.bahType = "\010\0\0\0""cpstring";

#line 636 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(to, "\0\0\0\0""") == 0)) {

#line 637 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1281 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1281[2] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1281[1] = pt.cont;____BAH_COMPILER_VAR_1281[0] = "\07\0\0\0""strlen(";char * ____BAH_COMPILER_VAR_1282 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1281, 3);to = ____BAH_COMPILER_VAR_1282;
}

#line 639 "/home/alois/Documents/bah-bah/src/values.bah"
t.isFunc = true;

#line 640 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1283 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_1283[6] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1283[5] = to;____BAH_COMPILER_VAR_1283[4] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_1283[3] = from;____BAH_COMPILER_VAR_1283[2] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_1283[1] = pt.cont;____BAH_COMPILER_VAR_1283[0] = "\022\0\0\0""cpstringSubsitute(";char * ____BAH_COMPILER_VAR_1284 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1283, 7);t.cont = ____BAH_COMPILER_VAR_1284;
}
}

#line 642 "/home/alois/Documents/bah-bah/src/values.bah"
else if (string__hasPrefix(&ptt,"\04\0\0\0""map:")) {

#line 643 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((split==true), 0)) {

#line 644 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&pt,"\050\0\0\0""Cannot do substitution on a map {TOKEN}.");
}

#line 646 "/home/alois/Documents/bah-bah/src/values.bah"
string__trimLeft(&ptt,4);

#line 647 "/home/alois/Documents/bah-bah/src/values.bah"
struct string elemType = getCType(string__str(&ptt),elems);

#line 648 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok index = memory->data[0];

#line 649 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((compTypes(getTypeFromToken(&index,true,elems),"\010\0\0\0""cpstring")==false), 0)) {

#line 650 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&index,"\053\0\0\0""Cannot use {TOKEN} as map index (cpstring).");
}

#line 652 "/home/alois/Documents/bah-bah/src/values.bah"
if ((tokPos==0)&&(ltp==LINE_TYPE_VAR)) {

#line 653 "/home/alois/Documents/bah-bah/src/values.bah"
struct variable* ____BAH_COMPILER_VAR_1285 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1285->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_1285->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_1285->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_1285->from = "\0\0\0\0""";
____BAH_COMPILER_VAR_1285->name = genCompilerVar();
____BAH_COMPILER_VAR_1285->type = string__str(&ptt);
struct variable* tmpV = ____BAH_COMPILER_VAR_1285;

#line 657 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1286 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_1286);
    elems->vars->data[____BAH_COMPILER_VAR_1286] = tmpV;

#line 658 "/home/alois/Documents/bah-bah/src/values.bah"
if (isGlobal()) {

#line 659 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1287 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1287[3] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_1287[2] = tmpV->name;____BAH_COMPILER_VAR_1287[1] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_1287[0] = string__str(&elemType);char * ____BAH_COMPILER_VAR_1288 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1287, 4);INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_1288));
}

#line 660 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 661 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1289 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1289[3] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_1289[2] = tmpV->name;____BAH_COMPILER_VAR_1289[1] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_1289[0] = string__str(&elemType);char * ____BAH_COMPILER_VAR_1290 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1289, 4);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1290));
}

#line 663 "/home/alois/Documents/bah-bah/src/values.bah"
if (isRCPpointerType(string__str(&ptt))) {

#line 664 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1291 = alloca(8 * sizeof(char*));____BAH_COMPILER_VAR_1291[7] = "\03\0\0\0"");\n";____BAH_COMPILER_VAR_1291[6] = tmpV->name;____BAH_COMPILER_VAR_1291[5] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_1291[4] = index.cont;____BAH_COMPILER_VAR_1291[3] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_1291[2] = pt.cont;____BAH_COMPILER_VAR_1291[1] = "\06\0\0\0""->set(";____BAH_COMPILER_VAR_1291[0] = pt.cont;char * ____BAH_COMPILER_VAR_1292 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1291, 8);NEXT_LINE = ____BAH_COMPILER_VAR_1292;
}

#line 665 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 666 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1293 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_1293[8] = "\04\0\0\0""));\n";____BAH_COMPILER_VAR_1293[7] = string__str(&elemType);____BAH_COMPILER_VAR_1293[6] = "\011\0\0\0"", sizeof(";____BAH_COMPILER_VAR_1293[5] = tmpV->name;____BAH_COMPILER_VAR_1293[4] = "\03\0\0\0"", &";____BAH_COMPILER_VAR_1293[3] = index.cont;____BAH_COMPILER_VAR_1293[2] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_1293[1] = pt.cont;____BAH_COMPILER_VAR_1293[0] = "\023\0\0\0""mapWrapper__setAny(";char * ____BAH_COMPILER_VAR_1294 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1293, 9);NEXT_LINE = ____BAH_COMPILER_VAR_1294;
}

#line 668 "/home/alois/Documents/bah-bah/src/values.bah"
t.cont = tmpV->name;

#line 669 "/home/alois/Documents/bah-bah/src/values.bah"
t.bahType = string__str(&ptt);
}

#line 670 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 671 "/home/alois/Documents/bah-bah/src/values.bah"
t.isFunc = true;

#line 672 "/home/alois/Documents/bah-bah/src/values.bah"
struct rope* res= null;

#line 673 "/home/alois/Documents/bah-bah/src/values.bah"
char * tmpV = genCompilerVar();

#line 674 "/home/alois/Documents/bah-bah/src/values.bah"
if (isRCPpointerType(string__str(&ptt))) {

#line 675 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1295 = alloca(10 * sizeof(char*));____BAH_COMPILER_VAR_1295[9] = "\03\0\0\0"");\n";____BAH_COMPILER_VAR_1295[8] = index.cont;____BAH_COMPILER_VAR_1295[7] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_1295[6] = t.cont;____BAH_COMPILER_VAR_1295[5] = "\06\0\0\0""->get(";____BAH_COMPILER_VAR_1295[4] = t.cont;____BAH_COMPILER_VAR_1295[3] = "\01\0\0\0""=";____BAH_COMPILER_VAR_1295[2] = tmpV;____BAH_COMPILER_VAR_1295[1] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_1295[0] = string__str(&elemType);char * ____BAH_COMPILER_VAR_1296 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1295, 10);res = rope(____BAH_COMPILER_VAR_1296);

#line 676 "/home/alois/Documents/bah-bah/src/values.bah"
t.cont = tmpV;
}

#line 677 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 678 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1297 = alloca(10 * sizeof(char*));____BAH_COMPILER_VAR_1297[9] = "\03\0\0\0"");\n";____BAH_COMPILER_VAR_1297[8] = index.cont;____BAH_COMPILER_VAR_1297[7] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_1297[6] = pt.cont;____BAH_COMPILER_VAR_1297[5] = "\06\0\0\0""->get(";____BAH_COMPILER_VAR_1297[4] = pt.cont;____BAH_COMPILER_VAR_1297[3] = "\01\0\0\0""=";____BAH_COMPILER_VAR_1297[2] = tmpV;____BAH_COMPILER_VAR_1297[1] = "\02\0\0\0""* ";____BAH_COMPILER_VAR_1297[0] = string__str(&elemType);char * ____BAH_COMPILER_VAR_1298 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1297, 10);res = rope(____BAH_COMPILER_VAR_1298);

#line 679 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1299 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1299[4] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1299[3] = tmpV;____BAH_COMPILER_VAR_1299[2] = "\03\0\0\0"")(*";____BAH_COMPILER_VAR_1299[1] = string__str(&elemType);____BAH_COMPILER_VAR_1299[0] = "\01\0\0\0""(";char * ____BAH_COMPILER_VAR_1300 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1299, 5);t.cont = ____BAH_COMPILER_VAR_1300;
}

#line 681 "/home/alois/Documents/bah-bah/src/values.bah"
if (RCPavailable()) {

#line 682 "/home/alois/Documents/bah-bah/src/values.bah"
struct variable* ____BAH_COMPILER_VAR_1301 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1301->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_1301->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_1301->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_1301->from = "\0\0\0\0""";
____BAH_COMPILER_VAR_1301->name = tmpV;
____BAH_COMPILER_VAR_1301->type = string__str(&ptt);

    unsigned int ____BAH_COMPILER_VAR_1302 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_1302);
    elems->vars->data[____BAH_COMPILER_VAR_1302] = ____BAH_COMPILER_VAR_1301;
}

#line 687 "/home/alois/Documents/bah-bah/src/values.bah"
if (isGlobal()) {

#line 688 "/home/alois/Documents/bah-bah/src/values.bah"
INIT = rope__add(INIT, res);
}

#line 689 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 690 "/home/alois/Documents/bah-bah/src/values.bah"
OUTPUT = rope__add(OUTPUT, res);
}

#line 692 "/home/alois/Documents/bah-bah/src/values.bah"
t.bahType = string__str(&ptt);
}
}

#line 695 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((strcmp(string__str(&ptt), "\010\0\0\0""cpstring") == 0)) {

#line 696 "/home/alois/Documents/bah-bah/src/values.bah"
t.isFunc = true;

#line 697 "/home/alois/Documents/bah-bah/src/values.bah"
if ((split==false)) {

#line 698 "/home/alois/Documents/bah-bah/src/values.bah"
t.bahType = "\04\0\0\0""char";

#line 699 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok index = memory->data[0];

#line 700 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((compTypes(getTypeFromToken(&index,true,elems),"\03\0\0\0""int")==false), 0)) {

#line 701 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&index,"\053\0\0\0""Cannot use {TOKEN} as cpstring index (int).");
}

#line 703 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1303 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1303[3] = "\03\0\0\0""+4]";____BAH_COMPILER_VAR_1303[2] = index.cont;____BAH_COMPILER_VAR_1303[1] = "\01\0\0\0""[";____BAH_COMPILER_VAR_1303[0] = pt.cont;char * ____BAH_COMPILER_VAR_1304 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1303, 4);t.cont = ____BAH_COMPILER_VAR_1304;
}

#line 704 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 705 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(to, "\0\0\0\0""") == 0)) {

#line 706 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1305 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1305[2] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1305[1] = pt.cont;____BAH_COMPILER_VAR_1305[0] = "\07\0\0\0""strlen(";char * ____BAH_COMPILER_VAR_1306 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1305, 3);to = ____BAH_COMPILER_VAR_1306;
}

#line 708 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1307 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_1307[6] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1307[5] = to;____BAH_COMPILER_VAR_1307[4] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_1307[3] = from;____BAH_COMPILER_VAR_1307[2] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_1307[1] = pt.cont;____BAH_COMPILER_VAR_1307[0] = "\022\0\0\0""cpstringSubsitute(";char * ____BAH_COMPILER_VAR_1308 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1307, 7);t.cont = ____BAH_COMPILER_VAR_1308;
}
}

#line 711 "/home/alois/Documents/bah-bah/src/values.bah"
else if (string__hasPrefix(&ptt,"\06\0\0\0""tuple:")) {

#line 712 "/home/alois/Documents/bah-bah/src/values.bah"
t.isOper = true;

#line 713 "/home/alois/Documents/bah-bah/src/values.bah"
struct variable* v = searchVar(pt.cont,elems);

#line 714 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((v==null), 0)) {

#line 715 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&pt,"\023\0\0\0""Unkown var {TOKEN}.");
}

#line 717 "/home/alois/Documents/bah-bah/src/values.bah"
array(struct string)* parts = splitString(ptt,"\01\0\0\0"":");

#line 718 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok index = memory->data[0];

#line 719 "/home/alois/Documents/bah-bah/src/values.bah"
if ((index.type==TOKEN_TYPE_INT)) {

#line 720 "/home/alois/Documents/bah-bah/src/values.bah"
long int ind = strToInt(index.cont);

#line 721 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((ind>=strToInt(string__str(&parts->data[1]))), 0)) {

#line 722 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1309 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1309[4] = "\01\0\0\0"".";____BAH_COMPILER_VAR_1309[3] = string__str(&parts->data[1]);____BAH_COMPILER_VAR_1309[2] = "\013\0\0\0"" of length ";____BAH_COMPILER_VAR_1309[1] = pt.cont;____BAH_COMPILER_VAR_1309[0] = "\046\0\0\0""Cannot access index {TOKEN} of tupple ";char * ____BAH_COMPILER_VAR_1310 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1309, 5);throwErr(&index,____BAH_COMPILER_VAR_1310);
}
}

#line 724 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 725 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((compTypes(getTypeFromToken(&index,true,elems),"\03\0\0\0""int")==false), 0)) {

#line 726 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&index,"\050\0\0\0""Cannot use {TOKEN} as tuple index (int).");
}
}

#line 729 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1311 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1311[3] = "\01\0\0\0""]";____BAH_COMPILER_VAR_1311[2] = index.cont;____BAH_COMPILER_VAR_1311[1] = "\01\0\0\0""[";____BAH_COMPILER_VAR_1311[0] = pt.cont;char * ____BAH_COMPILER_VAR_1312 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1311, 4);t.cont = ____BAH_COMPILER_VAR_1312;

#line 730 "/home/alois/Documents/bah-bah/src/values.bah"
t.bahType = string__str(&parts->data[2]);
}

#line 731 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 732 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1313 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1313[2] = "\013\0\0\0"") as array.";____BAH_COMPILER_VAR_1313[1] = string__str(&ptt);____BAH_COMPILER_VAR_1313[0] = "\024\0\0\0""Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_1314 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1313, 3);throwErr(&pt,____BAH_COMPILER_VAR_1314);
}

#line 735 "/home/alois/Documents/bah-bah/src/values.bah"
t.isValue = true;

#line 736 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1315 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1315);
    l->data[____BAH_COMPILER_VAR_1315] = t;

#line 738 "/home/alois/Documents/bah-bah/src/values.bah"
return tokPos;
};

#line 741 "/home/alois/Documents/bah-bah/src/values.bah"
char ____BAH_COMPILER_VAR_1327(array(char *)* arr, char * el) {
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
long int valueBool(__BAH_ARR_TYPE_Tok l,long int i,lineType ltp,struct Elems* elems){

#line 743 "/home/alois/Documents/bah-bah/src/values.bah"
long int tokPos = i-2;

#line 746 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok pt = l->data[tokPos];

#line 747 "/home/alois/Documents/bah-bah/src/values.bah"
char * ptt = getTypeFromToken(&pt,true,elems);

#line 749 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok t = l->data[tokPos+1];

#line 751 "/home/alois/Documents/bah-bah/src/values.bah"
deleteRange(l,tokPos,tokPos+1);

#line 754 "/home/alois/Documents/bah-bah/src/values.bah"
if ((isFixMeEnabled==false)&&(ltp==LINE_TYPE_FOR)&&(strcmp(ptt, "\03\0\0\0""int") == 0)||(strcmp(ptt, "\05\0\0\0""float") == 0)) {

#line 755 "/home/alois/Documents/bah-bah/src/values.bah"
struct variable* v = getRealVar(pt.cont,elems);

#line 756 "/home/alois/Documents/bah-bah/src/values.bah"
if ((v!=null)) {

#line 757 "/home/alois/Documents/bah-bah/src/values.bah"
v->iterScope = elems;

#line 758 "/home/alois/Documents/bah-bah/src/values.bah"
if ((v->canBeReg==true)&&(v->isReg==false)&&(v->declRope!=null)) {

#line 759 "/home/alois/Documents/bah-bah/src/values.bah"
char * odecl = rope__toStr(v->declRope);

#line 760 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strHasPrefix(odecl,"\011\0\0\0""register ")==false)) {

#line 761 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1316 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1316[1] = odecl;____BAH_COMPILER_VAR_1316[0] = "\011\0\0\0""register ";char * ____BAH_COMPILER_VAR_1317 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1316, 2);OUTPUT->totalLen = OUTPUT->totalLen+ropeSet(v->declRope,____BAH_COMPILER_VAR_1317);
}

#line 763 "/home/alois/Documents/bah-bah/src/values.bah"
v->isReg = true;
}
}
}

#line 769 "/home/alois/Documents/bah-bah/src/values.bah"
if ((isUnsafe==false)) {

#line 770 "/home/alois/Documents/bah-bah/src/values.bah"
if ((tokPos>0)) {

#line 771 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(l->data[tokPos-1].cont, "\02\0\0\0""&&") != 0)) {

#line 772 "/home/alois/Documents/bah-bah/src/values.bah"
clear(currChecks);
}
}

#line 774 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 775 "/home/alois/Documents/bah-bah/src/values.bah"
clear(currChecks);
}
}

#line 780 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok nt = l->data[tokPos];

#line 781 "/home/alois/Documents/bah-bah/src/values.bah"
char * ntt = getTypeFromToken(&nt,true,elems);

#line 782 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(t.cont, "\02\0\0\0""in") == 0)) {

#line 783 "/home/alois/Documents/bah-bah/src/values.bah"
struct string arrT = string(ntt);

#line 784 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((string__hasPrefix(&arrT,"\02\0\0\0""[]")==0), 0)) {

#line 785 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1318 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1318[2] = "\013\0\0\0"") as array.";____BAH_COMPILER_VAR_1318[1] = ntt;____BAH_COMPILER_VAR_1318[0] = "\024\0\0\0""Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_1319 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1318, 3);throwErr(&nt,____BAH_COMPILER_VAR_1319);
}

#line 787 "/home/alois/Documents/bah-bah/src/values.bah"
string__trimLeft(&arrT,2);

#line 788 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((compTypes(ptt,string__str(&arrT))==false), 0)) {

#line 789 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1320 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1320[4] = "\01\0\0\0"".";____BAH_COMPILER_VAR_1320[3] = ntt;____BAH_COMPILER_VAR_1320[2] = "\05\0\0\0"") in ";____BAH_COMPILER_VAR_1320[1] = ptt;____BAH_COMPILER_VAR_1320[0] = "\033\0\0\0""Cannot search for {TOKEN} (";char * ____BAH_COMPILER_VAR_1321 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1320, 5);throwErr(&pt,____BAH_COMPILER_VAR_1321);
}

#line 791 "/home/alois/Documents/bah-bah/src/values.bah"
char * comp = "\0\0\0\0""";

#line 792 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(ptt, "\010\0\0\0""cpstring") == 0)) {

#line 793 "/home/alois/Documents/bah-bah/src/values.bah"
comp = "\062\0\0\0""arr->data[i] != 0 && strcmp(arr->data[i], el) == 0";
}

#line 794 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 795 "/home/alois/Documents/bah-bah/src/values.bah"
comp = "\022\0\0\0""arr->data[i] == el";
}

#line 797 "/home/alois/Documents/bah-bah/src/values.bah"
char * name = genCompilerVar();

#line 798 "/home/alois/Documents/bah-bah/src/values.bah"
if (string__hasSuffix(&arrT,"\01\0\0\0""*")) {

#line 799 "/home/alois/Documents/bah-bah/src/values.bah"
long int nbast = string__count(&arrT,"\01\0\0\0""*");

#line 800 "/home/alois/Documents/bah-bah/src/values.bah"
string__trimRight(&arrT,nbast);
}

#line 802 "/home/alois/Documents/bah-bah/src/values.bah"
string__replace(&arrT,"\02\0\0\0""[]","\05\0\0\0""_ARR_");

#line 803 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1322 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1322[1] = string__str(&arrT);____BAH_COMPILER_VAR_1322[0] = "\017\0\0\0""__BAH_ARR_TYPE_";char * ____BAH_COMPILER_VAR_1323 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1322, 2);char * newArgType = ____BAH_COMPILER_VAR_1323;

#line 804 "/home/alois/Documents/bah-bah/src/values.bah"
array(char *)* csatd = compilerState.arrTypesDecl;

#line 805 "/home/alois/Documents/bah-bah/src/values.bah"

                struct string ____BAH_COMPILER_VAR_1324 = getCType(ptt,elems);
                char** ____BAH_COMPILER_VAR_1325 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_1325[8] = "\123\0\0\0"") {\n                return 1;\n            };\n        }\n        return 0;\n        }\n";____BAH_COMPILER_VAR_1325[7] = comp;____BAH_COMPILER_VAR_1325[6] = "\176\0\0\0"" el) {\n        if (arr == 0) {\n            return 0;\n        };\n        for(int i=arr->length-1; i!=-1;i--) {\n            if (";____BAH_COMPILER_VAR_1325[5] = string__str(&____BAH_COMPILER_VAR_1324);____BAH_COMPILER_VAR_1325[4] = "\06\0\0\0"" arr, ";____BAH_COMPILER_VAR_1325[3] = newArgType;____BAH_COMPILER_VAR_1325[2] = "\01\0\0\0""(";____BAH_COMPILER_VAR_1325[1] = name;____BAH_COMPILER_VAR_1325[0] = "\05\0\0\0""char ";char * ____BAH_COMPILER_VAR_1326 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1325, 9);char * fnTest = ____BAH_COMPILER_VAR_1326;

#line 816 "/home/alois/Documents/bah-bah/src/values.bah"
if ((____BAH_COMPILER_VAR_1327(csatd, newArgType)==false)) {

#line 817 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1328 = len(csatd);
    __Bah_realocate_arr(csatd, ____BAH_COMPILER_VAR_1328);
    csatd->data[____BAH_COMPILER_VAR_1328] = newArgType;

#line 818 "/home/alois/Documents/bah-bah/src/values.bah"

                struct string ____BAH_COMPILER_VAR_1329 = getCType(ntt,elems);
                char** ____BAH_COMPILER_VAR_1330 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_1330[5] = fnTest;____BAH_COMPILER_VAR_1330[4] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_1330[3] = newArgType;____BAH_COMPILER_VAR_1330[2] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_1330[1] = string__str(&____BAH_COMPILER_VAR_1329);____BAH_COMPILER_VAR_1330[0] = "\010\0\0\0""typedef ";char * ____BAH_COMPILER_VAR_1331 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1330, 6);fnTest = ____BAH_COMPILER_VAR_1331;
}

#line 820 "/home/alois/Documents/bah-bah/src/values.bah"
rope__append(postDeclHandle,rope(fnTest));

#line 822 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1332 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_1332[5] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1332[4] = pt.cont;____BAH_COMPILER_VAR_1332[3] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_1332[2] = nt.cont;____BAH_COMPILER_VAR_1332[1] = "\01\0\0\0""(";____BAH_COMPILER_VAR_1332[0] = name;char * ____BAH_COMPILER_VAR_1333 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1332, 6);char * fnCall = ____BAH_COMPILER_VAR_1333;

#line 824 "/home/alois/Documents/bah-bah/src/values.bah"
pt.isExpensive = true;

#line 825 "/home/alois/Documents/bah-bah/src/values.bah"
pt.cont = fnCall;
}

#line 826 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 827 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((compTypes(ptt,ntt)==false), 0)) {

#line 828 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1334 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1334[4] = "\01\0\0\0"".";____BAH_COMPILER_VAR_1334[3] = ptt;____BAH_COMPILER_VAR_1334[2] = "\014\0\0\0"") with type ";____BAH_COMPILER_VAR_1334[1] = ntt;____BAH_COMPILER_VAR_1334[0] = "\030\0\0\0""Cannot compare {TOKEN} (";char * ____BAH_COMPILER_VAR_1335 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1334, 5);throwErr(&nt,____BAH_COMPILER_VAR_1335);
}

#line 830 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(ptt, "\010\0\0\0""cpstring") == 0)) {

#line 831 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(t.cont, "\02\0\0\0""==") == 0)) {

#line 832 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1336 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1336[4] = "\07\0\0\0"") == 0)";____BAH_COMPILER_VAR_1336[3] = nt.cont;____BAH_COMPILER_VAR_1336[2] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_1336[1] = pt.cont;____BAH_COMPILER_VAR_1336[0] = "\010\0\0\0""(strcmp(";char * ____BAH_COMPILER_VAR_1337 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1336, 5);pt.cont = ____BAH_COMPILER_VAR_1337;
}

#line 834 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((strcmp(t.cont, "\02\0\0\0""!=") == 0)) {

#line 835 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1338 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1338[4] = "\07\0\0\0"") != 0)";____BAH_COMPILER_VAR_1338[3] = nt.cont;____BAH_COMPILER_VAR_1338[2] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_1338[1] = pt.cont;____BAH_COMPILER_VAR_1338[0] = "\010\0\0\0""(strcmp(";char * ____BAH_COMPILER_VAR_1339 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1338, 5);pt.cont = ____BAH_COMPILER_VAR_1339;
}

#line 836 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((strcmp(t.cont, "\01\0\0\0"">") == 0)) {

#line 837 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1340 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1340[4] = "\02\0\0\0""))";____BAH_COMPILER_VAR_1340[3] = nt.cont;____BAH_COMPILER_VAR_1340[2] = "\013\0\0\0"") > srtlen(";____BAH_COMPILER_VAR_1340[1] = pt.cont;____BAH_COMPILER_VAR_1340[0] = "\010\0\0\0""(strlen(";char * ____BAH_COMPILER_VAR_1341 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1340, 5);pt.cont = ____BAH_COMPILER_VAR_1341;
}

#line 838 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((strcmp(t.cont, "\01\0\0\0""<") == 0)) {

#line 839 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1342 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1342[4] = "\02\0\0\0""))";____BAH_COMPILER_VAR_1342[3] = nt.cont;____BAH_COMPILER_VAR_1342[2] = "\013\0\0\0"") < srtlen(";____BAH_COMPILER_VAR_1342[1] = pt.cont;____BAH_COMPILER_VAR_1342[0] = "\010\0\0\0""(strlen(";char * ____BAH_COMPILER_VAR_1343 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1342, 5);pt.cont = ____BAH_COMPILER_VAR_1343;
}

#line 840 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((strcmp(t.cont, "\02\0\0\0"">=") == 0)) {

#line 841 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1344 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1344[4] = "\02\0\0\0""))";____BAH_COMPILER_VAR_1344[3] = nt.cont;____BAH_COMPILER_VAR_1344[2] = "\014\0\0\0"") >= srtlen(";____BAH_COMPILER_VAR_1344[1] = pt.cont;____BAH_COMPILER_VAR_1344[0] = "\010\0\0\0""(strlen(";char * ____BAH_COMPILER_VAR_1345 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1344, 5);pt.cont = ____BAH_COMPILER_VAR_1345;
}

#line 842 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((strcmp(t.cont, "\02\0\0\0""<=") == 0)) {

#line 843 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1346 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1346[4] = "\02\0\0\0""))";____BAH_COMPILER_VAR_1346[3] = nt.cont;____BAH_COMPILER_VAR_1346[2] = "\014\0\0\0"") <= srtlen(";____BAH_COMPILER_VAR_1346[1] = pt.cont;____BAH_COMPILER_VAR_1346[0] = "\010\0\0\0""(strlen(";char * ____BAH_COMPILER_VAR_1347 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1346, 5);pt.cont = ____BAH_COMPILER_VAR_1347;
}

#line 845 "/home/alois/Documents/bah-bah/src/values.bah"
pt.isExpensive = true;
}

#line 846 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 847 "/home/alois/Documents/bah-bah/src/values.bah"
if ((isUnsafe==false)&&(pt.type==TOKEN_TYPE_VAR)&&(pt.isOper==false)&&isRCPpointerType(ptt)) {

#line 848 "/home/alois/Documents/bah-bah/src/values.bah"
struct variable* ptV = searchVar(pt.cont,elems);

#line 849 "/home/alois/Documents/bah-bah/src/values.bah"
if ((ptV!=null)) {

#line 850 "/home/alois/Documents/bah-bah/src/values.bah"
char ntIsNull = false;

#line 851 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(nt.cont, "\04\0\0\0""null") == 0)) {

#line 852 "/home/alois/Documents/bah-bah/src/values.bah"
ntIsNull = true;
}

#line 853 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((nt.type==TOKEN_TYPE_VAR)&&(nt.isOper==false)) {

#line 854 "/home/alois/Documents/bah-bah/src/values.bah"
struct variable* nv = searchVar(nt.cont,elems);

#line 855 "/home/alois/Documents/bah-bah/src/values.bah"
if ((nv!=null)) {

#line 856 "/home/alois/Documents/bah-bah/src/values.bah"
ntIsNull = nv->canBeNull;
}
}

#line 858 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((nt.isFunc==true)) {

#line 859 "/home/alois/Documents/bah-bah/src/values.bah"
struct func* fn = searchFuncByToken(&nt,elems);

#line 860 "/home/alois/Documents/bah-bah/src/values.bah"
if ((fn!=null)&&(fn->returns!=null)) {

#line 861 "/home/alois/Documents/bah-bah/src/values.bah"
ntIsNull = (fn->returns->type[strlen(fn->returns->type)-1+4]==33);
}
}

#line 864 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(t.cont, "\02\0\0\0""==") == 0)) {

#line 865 "/home/alois/Documents/bah-bah/src/values.bah"
struct varCheck ____BAH_COMPILER_VAR_1348 = {};
____BAH_COMPILER_VAR_1348.v = ptV;
____BAH_COMPILER_VAR_1348.checkNull = ntIsNull;

    unsigned int ____BAH_COMPILER_VAR_1349 = len(currChecks);
    __Bah_realocate_arr(currChecks, ____BAH_COMPILER_VAR_1349);
    currChecks->data[____BAH_COMPILER_VAR_1349] = ____BAH_COMPILER_VAR_1348;
}

#line 869 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((strcmp(t.cont, "\02\0\0\0""!=") == 0)) {

#line 870 "/home/alois/Documents/bah-bah/src/values.bah"
struct varCheck ____BAH_COMPILER_VAR_1350 = {};
____BAH_COMPILER_VAR_1350.v = ptV;
____BAH_COMPILER_VAR_1350.checkNull = (ntIsNull==false);

    unsigned int ____BAH_COMPILER_VAR_1351 = len(currChecks);
    __Bah_realocate_arr(currChecks, ____BAH_COMPILER_VAR_1351);
    currChecks->data[____BAH_COMPILER_VAR_1351] = ____BAH_COMPILER_VAR_1350;
}
}
}

#line 877 "/home/alois/Documents/bah-bah/src/values.bah"
if (isExprExpensive(&pt)||isExprExpensive(&nt)) {

#line 878 "/home/alois/Documents/bah-bah/src/values.bah"
pt.isExpensive = true;
}

#line 879 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 880 "/home/alois/Documents/bah-bah/src/values.bah"
pt.isExpensive = false;
}

#line 882 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1352 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1352[4] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1352[3] = nt.cont;____BAH_COMPILER_VAR_1352[2] = t.cont;____BAH_COMPILER_VAR_1352[1] = pt.cont;____BAH_COMPILER_VAR_1352[0] = "\01\0\0\0""(";char * ____BAH_COMPILER_VAR_1353 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1352, 5);pt.cont = ____BAH_COMPILER_VAR_1353;
}
}

#line 887 "/home/alois/Documents/bah-bah/src/values.bah"
pt.isOper = true;

#line 888 "/home/alois/Documents/bah-bah/src/values.bah"
pt.bahType = "\04\0\0\0""bool";

#line 889 "/home/alois/Documents/bah-bah/src/values.bah"
pt.isValue = true;

#line 890 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1354 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1354);
    l->data[____BAH_COMPILER_VAR_1354] = pt;

#line 891 "/home/alois/Documents/bah-bah/src/values.bah"
return tokPos;
};

#line 895 "/home/alois/Documents/bah-bah/src/values.bah"
char ____BAH_COMPILER_VAR_1363(array(char *)* arr, char * el) {
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
char ____BAH_COMPILER_VAR_1364(array(char *)* arr, char * el) {
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

#line 896 "/home/alois/Documents/bah-bah/src/values.bah"
long int tokPos = i-2;

#line 898 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok pt = l->data[tokPos];

#line 899 "/home/alois/Documents/bah-bah/src/values.bah"
char * ptt = getTypeFromToken(&pt,true,elems);

#line 902 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok t = l->data[tokPos+1];

#line 903 "/home/alois/Documents/bah-bah/src/values.bah"
deleteRange(l,tokPos,tokPos+1);

#line 906 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok nt = l->data[tokPos];

#line 909 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(nt.cont, t.cont) == 0)) {

#line 910 "/home/alois/Documents/bah-bah/src/values.bah"
pt.isOper = true;

#line 911 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1355 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1355[2] = pt.cont;____BAH_COMPILER_VAR_1355[1] = t.cont;____BAH_COMPILER_VAR_1355[0] = t.cont;char * ____BAH_COMPILER_VAR_1356 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1355, 3);pt.cont = ____BAH_COMPILER_VAR_1356;

#line 912 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1357 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1357);
    l->data[____BAH_COMPILER_VAR_1357] = pt;

#line 913 "/home/alois/Documents/bah-bah/src/values.bah"
return tokPos;
}

#line 917 "/home/alois/Documents/bah-bah/src/values.bah"
char * ntt = getTypeFromToken(&nt,true,elems);

#line 918 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((compTypes(ptt,ntt)==false), 0)) {

#line 919 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1358 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1358[4] = "\01\0\0\0"".";____BAH_COMPILER_VAR_1358[3] = ptt;____BAH_COMPILER_VAR_1358[2] = "\05\0\0\0"") as ";____BAH_COMPILER_VAR_1358[1] = ntt;____BAH_COMPILER_VAR_1358[0] = "\030\0\0\0""Cannot operate {TOKEN} (";char * ____BAH_COMPILER_VAR_1359 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1358, 5);throwErr(&nt,____BAH_COMPILER_VAR_1359);
}

#line 922 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((strcmp(ptt, "\03\0\0\0""ptr") == 0), 0)) {

#line 923 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&pt,"\045\0\0\0""Cannot do operation on {TOKEN} (ptr).");
}

#line 925 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((strcmp(ntt, "\03\0\0\0""ptr") == 0), 0)) {

#line 926 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&nt,"\045\0\0\0""Cannot do operation on {TOKEN} (ptr).");
}

#line 930 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(ptt, "\010\0\0\0""cpstring") == 0)) {

#line 933 "/home/alois/Documents/bah-bah/src/values.bah"
array(char *)* strs = memoryAlloc(sizeof(array(char *)));

strs->length = 2;
strs->elemSize = sizeof(char *);
strs->data = memoryAlloc(sizeof(char *) * 50);
                    strs->realLength = 50;
strs->data[0] = nt.cont;
strs->data[1] = pt.cont;

#line 935 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((strcmp(t.cont, "\01\0\0\0""+") != 0), 0)) {

#line 936 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&t,"\063\0\0\0""Can only do concatenation on cpstring, not {TOKEN}.");
}

#line 940 "/home/alois/Documents/bah-bah/src/values.bah"
if ((tokPos-1>=0)) {

#line 941 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok nat = l->data[tokPos-1];

#line 942 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(nat.cont, "\01\0\0\0""+") == 0)) {

#line 944 "/home/alois/Documents/bah-bah/src/values.bah"
long int rangeEnds = tokPos-1;

#line 945 "/home/alois/Documents/bah-bah/src/values.bah"
i = tokPos-2;

#line 946 "/home/alois/Documents/bah-bah/src/values.bah"
long int nb = 2;

#line 947 "/home/alois/Documents/bah-bah/src/values.bah"
for (; (i>=0); 
#line 947 "/home/alois/Documents/bah-bah/src/values.bah"
--i) {

#line 948 "/home/alois/Documents/bah-bah/src/values.bah"
tokPos = i;

#line 949 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok currStrTk = l->data[i];

#line 951 "/home/alois/Documents/bah-bah/src/values.bah"
char * tt = getTypeFromToken(&currStrTk,true,elems);

#line 952 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((compTypes(tt,"\010\0\0\0""cpstring")==false), 0)) {

#line 953 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1360 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1360[2] = "\02\0\0\0"").";____BAH_COMPILER_VAR_1360[1] = tt;____BAH_COMPILER_VAR_1360[0] = "\052\0\0\0""Cannot concatenate cpstring with {TOKEN} (";char * ____BAH_COMPILER_VAR_1361 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1360, 3);throwErr(&currStrTk,____BAH_COMPILER_VAR_1361);
}

#line 956 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1362 = len(strs);
    __Bah_realocate_arr(strs, ____BAH_COMPILER_VAR_1362);
    strs->data[____BAH_COMPILER_VAR_1362] = currStrTk.cont;

#line 959 "/home/alois/Documents/bah-bah/src/values.bah"
if ((i-1>=0)) {

#line 960 "/home/alois/Documents/bah-bah/src/values.bah"
--i;

#line 961 "/home/alois/Documents/bah-bah/src/values.bah"
t = l->data[i];

#line 962 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(t.cont, "\01\0\0\0""+") != 0)) {

#line 963 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect(____BAH_COMPILER_VAR_1363(signs, t.cont), 0)) {

#line 964 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&t,"\063\0\0\0""Can only do concatenation on cpstring, not {TOKEN}.");
}

#line 965 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 966 "/home/alois/Documents/bah-bah/src/values.bah"
++i;

#line 967 "/home/alois/Documents/bah-bah/src/values.bah"
break;
}
}
}

#line 971 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 972 "/home/alois/Documents/bah-bah/src/values.bah"
i = 0;

#line 973 "/home/alois/Documents/bah-bah/src/values.bah"
break;
}
};

#line 976 "/home/alois/Documents/bah-bah/src/values.bah"
deleteRange(l,i,rangeEnds);
}

#line 977 "/home/alois/Documents/bah-bah/src/values.bah"
else if (__builtin_expect(____BAH_COMPILER_VAR_1364(signs, nat.cont), 0)) {

#line 978 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&nat,"\063\0\0\0""Can only do concatenation on cpstring, not {TOKEN}.");
}
}

#line 984 "/home/alois/Documents/bah-bah/src/values.bah"
pt.type = TOKEN_TYPE_VAR;

#line 985 "/home/alois/Documents/bah-bah/src/values.bah"
pt.isValue = true;

#line 986 "/home/alois/Documents/bah-bah/src/values.bah"
pt.cont = genConcat(strs,elems);

#line 987 "/home/alois/Documents/bah-bah/src/values.bah"
pt.isOper = false;
}

#line 988 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 990 "/home/alois/Documents/bah-bah/src/values.bah"
struct cStruct* s = searchStruct(ptt,elems);

#line 991 "/home/alois/Documents/bah-bah/src/values.bah"
if ((s!=null)) {

#line 992 "/home/alois/Documents/bah-bah/src/values.bah"
char * sep = "\01\0\0\0"".";

#line 993 "/home/alois/Documents/bah-bah/src/values.bah"
char * amp = "\01\0\0\0""&";

#line 995 "/home/alois/Documents/bah-bah/src/values.bah"
if (isRCPpointerType(ptt)) {

#line 996 "/home/alois/Documents/bah-bah/src/values.bah"
sep = "\02\0\0\0""->";

#line 997 "/home/alois/Documents/bah-bah/src/values.bah"
amp = "\0\0\0\0""";
}

#line 999 "/home/alois/Documents/bah-bah/src/values.bah"
char * mName = "\0\0\0\0""";

#line 1000 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(t.cont, "\01\0\0\0""+") == 0)) {

#line 1001 "/home/alois/Documents/bah-bah/src/values.bah"
mName = "\03\0\0\0""add";
}

#line 1002 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((strcmp(t.cont, "\01\0\0\0""-") == 0)) {

#line 1003 "/home/alois/Documents/bah-bah/src/values.bah"
mName = "\03\0\0\0""sub";
}

#line 1004 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((strcmp(t.cont, "\01\0\0\0""*") == 0)) {

#line 1005 "/home/alois/Documents/bah-bah/src/values.bah"
mName = "\04\0\0\0""mult";
}

#line 1006 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((strcmp(t.cont, "\01\0\0\0""/") == 0)) {

#line 1007 "/home/alois/Documents/bah-bah/src/values.bah"
mName = "\03\0\0\0""div";
}

#line 1008 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 1009 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1365 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1365[2] = "\02\0\0\0"").";____BAH_COMPILER_VAR_1365[1] = ptt;____BAH_COMPILER_VAR_1365[0] = "\047\0\0\0""Undefined operation on struct {TOKEN} (";char * ____BAH_COMPILER_VAR_1366 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1365, 3);throwErr(&pt,____BAH_COMPILER_VAR_1366);
}

#line 1011 "/home/alois/Documents/bah-bah/src/values.bah"
struct structMemb* methd = searchStructMemb(mName,s,elems);

#line 1012 "/home/alois/Documents/bah-bah/src/values.bah"
if ((methd!=null)&&(methd->isFn==true)) {

#line 1013 "/home/alois/Documents/bah-bah/src/values.bah"
if (RCPavailable()) {

#line 1014 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1367 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_1367[8] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1367[7] = nt.cont;____BAH_COMPILER_VAR_1367[6] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_1367[5] = pt.cont;____BAH_COMPILER_VAR_1367[4] = amp;____BAH_COMPILER_VAR_1367[3] = "\01\0\0\0""(";____BAH_COMPILER_VAR_1367[2] = mName;____BAH_COMPILER_VAR_1367[1] = "\02\0\0\0""__";____BAH_COMPILER_VAR_1367[0] = s->name;char * ____BAH_COMPILER_VAR_1368 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1367, 9);pt.cont = registerRCPvar(ptt,____BAH_COMPILER_VAR_1368,elems);

#line 1015 "/home/alois/Documents/bah-bah/src/values.bah"
pt.type = TOKEN_TYPE_VAR;

#line 1015 "/home/alois/Documents/bah-bah/src/values.bah"
pt.isFunc = false;

#line 1015 "/home/alois/Documents/bah-bah/src/values.bah"
pt.isOper = false;
}

#line 1016 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 1017 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1369 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_1369[8] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1369[7] = nt.cont;____BAH_COMPILER_VAR_1369[6] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_1369[5] = pt.cont;____BAH_COMPILER_VAR_1369[4] = amp;____BAH_COMPILER_VAR_1369[3] = "\01\0\0\0""(";____BAH_COMPILER_VAR_1369[2] = mName;____BAH_COMPILER_VAR_1369[1] = "\02\0\0\0""__";____BAH_COMPILER_VAR_1369[0] = s->name;char * ____BAH_COMPILER_VAR_1370 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1369, 9);pt.cont = ____BAH_COMPILER_VAR_1370;

#line 1018 "/home/alois/Documents/bah-bah/src/values.bah"
pt.isFunc = true;
}
}
}

#line 1021 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 1022 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1371 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1371[1] = nt.cont;____BAH_COMPILER_VAR_1371[0] = t.cont;char * ____BAH_COMPILER_VAR_1372 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1371, 2);char** ____BAH_COMPILER_VAR_1373 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1373[1] = ____BAH_COMPILER_VAR_1372;____BAH_COMPILER_VAR_1373[0] = pt.cont;char * ____BAH_COMPILER_VAR_1374 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1373, 2);pt.cont = ____BAH_COMPILER_VAR_1374;
}

#line 1024 "/home/alois/Documents/bah-bah/src/values.bah"
pt.isOper = true;
}

#line 1027 "/home/alois/Documents/bah-bah/src/values.bah"
pt.isNotExpsvOper = false;

#line 1028 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1375 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1375);
    l->data[____BAH_COMPILER_VAR_1375] = pt;

#line 1029 "/home/alois/Documents/bah-bah/src/values.bah"
return tokPos;
};

#line 1032 "/home/alois/Documents/bah-bah/src/values.bah"
long int valueSendChan(__BAH_ARR_TYPE_Tok l,long int i,struct Elems* elems){

#line 1033 "/home/alois/Documents/bah-bah/src/values.bah"
long int posTok = i-2;

#line 1035 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok nt = l->data[posTok];

#line 1037 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok pt = l->data[posTok+2];

#line 1038 "/home/alois/Documents/bah-bah/src/values.bah"
deleteRange(l,posTok,posTok+2);

#line 1040 "/home/alois/Documents/bah-bah/src/values.bah"
char * ntt = getTypeFromToken(&nt,true,elems);

#line 1042 "/home/alois/Documents/bah-bah/src/values.bah"
struct string ptt = string(getTypeFromToken(&pt,true,elems));

#line 1043 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((string__hasPrefix(&ptt,"\05\0\0\0""chan:")==0), 0)) {

#line 1044 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1376 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1376[2] = "\012\0\0\0"") as chan.";____BAH_COMPILER_VAR_1376[1] = string__str(&ptt);____BAH_COMPILER_VAR_1376[0] = "\024\0\0\0""Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_1377 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1376, 3);throwErr(&pt,____BAH_COMPILER_VAR_1377);
}

#line 1046 "/home/alois/Documents/bah-bah/src/values.bah"
string__trimLeft(&ptt,5);

#line 1048 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect(isGlobal(), 0)) {

#line 1049 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&pt,"\055\0\0\0""Cannot send to channel {TOKEN} of a function.");
}

#line 1052 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((compTypes(ntt,string__str(&ptt))==false), 0)) {

#line 1053 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1378 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1378[4] = "\01\0\0\0"".";____BAH_COMPILER_VAR_1378[3] = string__str(&ptt);____BAH_COMPILER_VAR_1378[2] = "\017\0\0\0"") through chan:";____BAH_COMPILER_VAR_1378[1] = ntt;____BAH_COMPILER_VAR_1378[0] = "\025\0\0\0""Cannot send {TOKEN} (";char * ____BAH_COMPILER_VAR_1379 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1378, 5);throwErr(&nt,____BAH_COMPILER_VAR_1379);
}

#line 1056 "/home/alois/Documents/bah-bah/src/values.bah"
if (isRCPpointerType(string__str(&ptt))) {

#line 1057 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1380 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1380[4] = "\03\0\0\0"");\n";____BAH_COMPILER_VAR_1380[3] = nt.cont;____BAH_COMPILER_VAR_1380[2] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_1380[1] = pt.cont;____BAH_COMPILER_VAR_1380[0] = "\016\0\0\0""channel__send(";char * ____BAH_COMPILER_VAR_1381 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1380, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1381));
}

#line 1058 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 1059 "/home/alois/Documents/bah-bah/src/values.bah"
struct string ct = getCType(ntt,elems);

#line 1060 "/home/alois/Documents/bah-bah/src/values.bah"
char * tmpV = genCompilerVar();

#line 1061 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1382 = alloca(13 * sizeof(char*));____BAH_COMPILER_VAR_1382[12] = "\014\0\0\0""));\n        ";____BAH_COMPILER_VAR_1382[11] = tmpV;____BAH_COMPILER_VAR_1382[10] = "\011\0\0\0"", sizeof(";____BAH_COMPILER_VAR_1382[9] = tmpV;____BAH_COMPILER_VAR_1382[8] = "\03\0\0\0"", &";____BAH_COMPILER_VAR_1382[7] = pt.cont;____BAH_COMPILER_VAR_1382[6] = "\033\0\0\0"";\n        channel__sendAny(";____BAH_COMPILER_VAR_1382[5] = nt.cont;____BAH_COMPILER_VAR_1382[4] = "\03\0\0\0"" = ";____BAH_COMPILER_VAR_1382[3] = tmpV;____BAH_COMPILER_VAR_1382[2] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_1382[1] = string__str(&ct);____BAH_COMPILER_VAR_1382[0] = "\011\0\0\0""\n        ";char * ____BAH_COMPILER_VAR_1383 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1382, 13);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1383));
}

#line 1067 "/home/alois/Documents/bah-bah/src/values.bah"
return posTok;
};

#line 1070 "/home/alois/Documents/bah-bah/src/values.bah"
long int valueChan(__BAH_ARR_TYPE_Tok l,long int i,struct Elems* elems){

#line 1071 "/home/alois/Documents/bah-bah/src/values.bah"
long int posTok = i-1;

#line 1072 "/home/alois/Documents/bah-bah/src/values.bah"
delete(l,posTok);

#line 1075 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok nt = l->data[posTok];

#line 1077 "/home/alois/Documents/bah-bah/src/values.bah"
struct string ntt = string(getTypeFromToken(&nt,true,elems));

#line 1078 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((string__hasPrefix(&ntt,"\05\0\0\0""chan:")==0), 0)) {

#line 1079 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1384 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1384[2] = "\012\0\0\0"") as chan.";____BAH_COMPILER_VAR_1384[1] = string__str(&ntt);____BAH_COMPILER_VAR_1384[0] = "\024\0\0\0""Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_1385 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1384, 3);throwErr(&nt,____BAH_COMPILER_VAR_1385);
}

#line 1082 "/home/alois/Documents/bah-bah/src/values.bah"
string__trimLeft(&ntt,5);

#line 1084 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect(isGlobal(), 0)) {

#line 1085 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&nt,"\071\0\0\0""Cannot receive from chan {TOKEN} outside a function body.");
}

#line 1088 "/home/alois/Documents/bah-bah/src/values.bah"
struct string ct = getCType(string__str(&ntt),elems);

#line 1089 "/home/alois/Documents/bah-bah/src/values.bah"
if (isRCPpointerType(string__str(&ntt))) {

#line 1090 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1386 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1386[2] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1386[1] = nt.cont;____BAH_COMPILER_VAR_1386[0] = "\021\0\0\0""channel__receive(";char * ____BAH_COMPILER_VAR_1387 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1386, 3);char * tmpV = registerRCPvar(string__str(&ntt),____BAH_COMPILER_VAR_1387,elems);

#line 1091 "/home/alois/Documents/bah-bah/src/values.bah"
nt.cont = tmpV;
}

#line 1092 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 1093 "/home/alois/Documents/bah-bah/src/values.bah"
if (RCPavailable()) {

#line 1094 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1388 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1388[1] = "\01\0\0\0""*";____BAH_COMPILER_VAR_1388[0] = string__str(&ntt);char * ____BAH_COMPILER_VAR_1389 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1388, 2);char** ____BAH_COMPILER_VAR_1390 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1390[4] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1390[3] = nt.cont;____BAH_COMPILER_VAR_1390[2] = "\023\0\0\0""*)channel__receive(";____BAH_COMPILER_VAR_1390[1] = string__str(&ct);____BAH_COMPILER_VAR_1390[0] = "\01\0\0\0""(";char * ____BAH_COMPILER_VAR_1391 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1390, 5);char * tmpV = registerRCPvar(____BAH_COMPILER_VAR_1389,____BAH_COMPILER_VAR_1391,elems);

#line 1095 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1392 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1392[1] = tmpV;____BAH_COMPILER_VAR_1392[0] = "\01\0\0\0""*";char * ____BAH_COMPILER_VAR_1393 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1392, 2);nt.cont = ____BAH_COMPILER_VAR_1393;
}

#line 1096 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 1097 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1394 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1394[4] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1394[3] = nt.cont;____BAH_COMPILER_VAR_1394[2] = "\023\0\0\0""*)channel__receive(";____BAH_COMPILER_VAR_1394[1] = string__str(&ct);____BAH_COMPILER_VAR_1394[0] = "\02\0\0\0""*(";char * ____BAH_COMPILER_VAR_1395 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1394, 5);nt.cont = ____BAH_COMPILER_VAR_1395;
}
}

#line 1101 "/home/alois/Documents/bah-bah/src/values.bah"
nt.type = TOKEN_TYPE_FUNC;

#line 1102 "/home/alois/Documents/bah-bah/src/values.bah"
nt.isFunc = true;

#line 1103 "/home/alois/Documents/bah-bah/src/values.bah"
nt.isValue = true;

#line 1104 "/home/alois/Documents/bah-bah/src/values.bah"
nt.bahType = string__str(&ntt);

#line 1106 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1396 = posTok;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1396);
    l->data[____BAH_COMPILER_VAR_1396] = nt;

#line 1108 "/home/alois/Documents/bah-bah/src/values.bah"
return posTok;
};

#line 1111 "/home/alois/Documents/bah-bah/src/values.bah"
long int valueTuple(__BAH_ARR_TYPE_Tok l,long int i,struct Elems* elems){

#line 1112 "/home/alois/Documents/bah-bah/src/values.bah"
long int tokPos = i;

#line 1114 "/home/alois/Documents/bah-bah/src/values.bah"
long int nbBracks = 0;

#line 1115 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((strcmp(l->data[tokPos+1].cont, "\01\0\0\0""]") == 0), 0)) {

#line 1117 "/home/alois/Documents/bah-bah/src/values.bah"
long int offset = 1;

#line 1118 "/home/alois/Documents/bah-bah/src/values.bah"
while ((strcmp(l->data[tokPos+offset+1].cont, "\01\0\0\0""[") == 0)&&(strcmp(l->data[tokPos+offset+2].cont, "\01\0\0\0""]") == 0)) {

#line 1119 "/home/alois/Documents/bah-bah/src/values.bah"
offset = offset+2;
};

#line 1121 "/home/alois/Documents/bah-bah/src/values.bah"
if ((l->data[tokPos+offset+1].type==TOKEN_TYPE_VAR)) {

#line 1122 "/home/alois/Documents/bah-bah/src/values.bah"
return tokPos+1;
}

#line 1124 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&l->data[tokPos],"\043\0\0\0""Cannot declare {TOKEN} empty tuple.");
}

#line 1129 "/home/alois/Documents/bah-bah/src/values.bah"
array(char *)* vals = memoryAlloc(sizeof(array(char *)));

vals->length = 0;
vals->elemSize = sizeof(char *);

#line 1131 "/home/alois/Documents/bah-bah/src/values.bah"
long int nbEncl = 1;

#line 1132 "/home/alois/Documents/bah-bah/src/values.bah"
++i;

#line 1132 "/home/alois/Documents/bah-bah/src/values.bah"
for (; (i<len(l)); 
#line 1132 "/home/alois/Documents/bah-bah/src/values.bah"
++i) {

#line 1133 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(l->data[i].cont, "\01\0\0\0""[") == 0)||(strcmp(l->data[i].cont, "\01\0\0\0""(") == 0)) {

#line 1134 "/home/alois/Documents/bah-bah/src/values.bah"
++nbEncl;
}

#line 1135 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((strcmp(l->data[1].cont, "\01\0\0\0""]") == 0)||(strcmp(l->data[i].cont, "\01\0\0\0"")") == 0)) {

#line 1136 "/home/alois/Documents/bah-bah/src/values.bah"
--nbEncl;

#line 1137 "/home/alois/Documents/bah-bah/src/values.bah"
if ((nbEncl==0)) {

#line 1138 "/home/alois/Documents/bah-bah/src/values.bah"
break;
}
}
};

#line 1143 "/home/alois/Documents/bah-bah/src/values.bah"
array(struct Tok)* memory = arraySubstitute(l, tokPos+1, i);

#line 1145 "/home/alois/Documents/bah-bah/src/values.bah"
memory = prePross(memory,(lineType)-1,elems);

#line 1146 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok ft = memory->data[0];

#line 1147 "/home/alois/Documents/bah-bah/src/values.bah"
char * tupT = getTypeFromToken(&ft,true,elems);

#line 1149 "/home/alois/Documents/bah-bah/src/values.bah"
register long int j = 0;

#line 1149 "/home/alois/Documents/bah-bah/src/values.bah"
for (; (j<len(memory)); 
#line 1149 "/home/alois/Documents/bah-bah/src/values.bah"
j = j+2) {

#line 1150 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok t = memory->data[j];

#line 1151 "/home/alois/Documents/bah-bah/src/values.bah"
char * tt = getTypeFromToken(&t,true,elems);

#line 1152 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((compTypes(tupT,tt)==false), 0)) {

#line 1153 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1397 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1397[4] = "\026\0\0\0"" in tuple declaration.";____BAH_COMPILER_VAR_1397[3] = tupT;____BAH_COMPILER_VAR_1397[2] = "\05\0\0\0"") as ";____BAH_COMPILER_VAR_1397[1] = tt;____BAH_COMPILER_VAR_1397[0] = "\024\0\0\0""Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_1398 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1397, 5);throwErr(&t,____BAH_COMPILER_VAR_1398);
}

#line 1155 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1399 = len(vals);
    __Bah_realocate_arr(vals, ____BAH_COMPILER_VAR_1399);
    vals->data[____BAH_COMPILER_VAR_1399] = t.cont;

#line 1156 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok nt = memory->data[j+1];

#line 1157 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(nt.cont, "\01\0\0\0""]") == 0)) {

#line 1158 "/home/alois/Documents/bah-bah/src/values.bah"
break;
}

#line 1159 "/home/alois/Documents/bah-bah/src/values.bah"
else if (__builtin_expect((strcmp(nt.cont, "\01\0\0\0"",") != 0), 0)) {

#line 1160 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&nt,"\104\0\0\0""Expected separator between values in tuple declaration, got {TOKEN}.");
}
};

#line 1164 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1400 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1400[3] = tupT;____BAH_COMPILER_VAR_1400[2] = "\01\0\0\0"":";____BAH_COMPILER_VAR_1400[1] = intToStr(len(vals));____BAH_COMPILER_VAR_1400[0] = "\06\0\0\0""tuple:";char * ____BAH_COMPILER_VAR_1401 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1400, 4);char * type = ____BAH_COMPILER_VAR_1401;

#line 1166 "/home/alois/Documents/bah-bah/src/values.bah"
deleteRange(l,tokPos+1,j+1);

#line 1168 "/home/alois/Documents/bah-bah/src/values.bah"

                struct string ____BAH_COMPILER_VAR_1402 = getCType(tupT,elems);
                char** ____BAH_COMPILER_VAR_1403 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1403[4] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1403[3] = intToStr(len(vals));____BAH_COMPILER_VAR_1403[2] = "\04\0\0\0"") * ";____BAH_COMPILER_VAR_1403[1] = string__str(&____BAH_COMPILER_VAR_1402);____BAH_COMPILER_VAR_1403[0] = "\016\0\0\0""alloca(sizeof(";char * ____BAH_COMPILER_VAR_1404 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1403, 5);char * v = registerRCPvar(type,____BAH_COMPILER_VAR_1404,elems);

#line 1170 "/home/alois/Documents/bah-bah/src/values.bah"
char * r = "\0\0\0\0""";

#line 1171 "/home/alois/Documents/bah-bah/src/values.bah"
i = 0;

#line 1171 "/home/alois/Documents/bah-bah/src/values.bah"
for (; (i<len(vals)); 
#line 1171 "/home/alois/Documents/bah-bah/src/values.bah"
++i) {

#line 1172 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1405 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_1405[5] = "\01\0\0\0"";";____BAH_COMPILER_VAR_1405[4] = vals->data[i];____BAH_COMPILER_VAR_1405[3] = "\04\0\0\0""] = ";____BAH_COMPILER_VAR_1405[2] = intToStr(i);____BAH_COMPILER_VAR_1405[1] = "\01\0\0\0""[";____BAH_COMPILER_VAR_1405[0] = v;char * ____BAH_COMPILER_VAR_1406 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1405, 6);char** ____BAH_COMPILER_VAR_1407 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1407[1] = ____BAH_COMPILER_VAR_1406;____BAH_COMPILER_VAR_1407[0] = r;char * ____BAH_COMPILER_VAR_1408 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1407, 2);r = ____BAH_COMPILER_VAR_1408;
};

#line 1175 "/home/alois/Documents/bah-bah/src/values.bah"
if (isGlobal()) {

#line 1176 "/home/alois/Documents/bah-bah/src/values.bah"
INIT = rope__add(INIT, rope(r));
}

#line 1177 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 1178 "/home/alois/Documents/bah-bah/src/values.bah"
OUTPUT = rope__add(OUTPUT, rope(r));
}

#line 1181 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok ____BAH_COMPILER_VAR_1409 = {};
____BAH_COMPILER_VAR_1409.cont = "\0\0\0\0""";
____BAH_COMPILER_VAR_1409.ogCont = "\0\0\0\0""";
____BAH_COMPILER_VAR_1409.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1409.line = 1;
____BAH_COMPILER_VAR_1409.begLine = 1;
____BAH_COMPILER_VAR_1409.bahType = "\0\0\0\0""";
____BAH_COMPILER_VAR_1409.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_1409.bahType = type;
____BAH_COMPILER_VAR_1409.cont = v;

    unsigned int ____BAH_COMPILER_VAR_1410 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1410);
    l->data[____BAH_COMPILER_VAR_1410] = ____BAH_COMPILER_VAR_1409;

#line 1187 "/home/alois/Documents/bah-bah/src/values.bah"
return tokPos;
};

#line 1190 "/home/alois/Documents/bah-bah/src/values.bah"
char isSmallValue(__BAH_ARR_TYPE_Tok l,long int i){

#line 1191 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok t = l->data[i];

#line 1192 "/home/alois/Documents/bah-bah/src/values.bah"
if ((t.type==TOKEN_TYPE_CAST)||(strcmp(t.cont, "\01\0\0\0""(") == 0)) {

#line 1193 "/home/alois/Documents/bah-bah/src/values.bah"
return false;
}

#line 1194 "/home/alois/Documents/bah-bah/src/values.bah"
else if (__builtin_expect((t.isValue==false), 0)) {

#line 1195 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&t,"\034\0\0\0""Cannot use {TOKEN} as value.");
}

#line 1197 "/home/alois/Documents/bah-bah/src/values.bah"
if ((i+1<len(l))) {

#line 1198 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok nt = l->data[i+1];

#line 1199 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(nt.cont, "\01\0\0\0""[") == 0)||(strcmp(nt.cont, "\01\0\0\0"".") == 0)||(strcmp(nt.cont, "\01\0\0\0""(") == 0)) {

#line 1200 "/home/alois/Documents/bah-bah/src/values.bah"
return false;
}
}

#line 1203 "/home/alois/Documents/bah-bah/src/values.bah"
return true;
};

#line 1206 "/home/alois/Documents/bah-bah/src/values.bah"
char ____BAH_COMPILER_VAR_1411(array(char *)* arr, char * el) {
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
char isValue(__BAH_ARR_TYPE_Tok l,long int i){

#line 1207 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok t = l->data[i];

#line 1208 "/home/alois/Documents/bah-bah/src/values.bah"
if ((t.type==TOKEN_TYPE_CAST)||(strcmp(t.cont, "\01\0\0\0""(") == 0)) {

#line 1209 "/home/alois/Documents/bah-bah/src/values.bah"
return false;
}

#line 1210 "/home/alois/Documents/bah-bah/src/values.bah"
else if (__builtin_expect((t.isValue==false), 0)) {

#line 1211 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&t,"\034\0\0\0""Cannot use {TOKEN} as value.");
}

#line 1213 "/home/alois/Documents/bah-bah/src/values.bah"
if ((i+1<len(l))) {

#line 1214 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok nt = l->data[i+1];

#line 1215 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(nt.cont, "\01\0\0\0""[") == 0)||(strcmp(nt.cont, "\01\0\0\0"".") == 0)||(strcmp(nt.cont, "\01\0\0\0""(") == 0)||____BAH_COMPILER_VAR_1411(signs, nt.cont)||(nt.isValue&&(nt.cont[0+4]==45))) {

#line 1216 "/home/alois/Documents/bah-bah/src/values.bah"
return false;
}
}

#line 1219 "/home/alois/Documents/bah-bah/src/values.bah"
return true;
};

#line 3002 "/home/alois/Documents/bah-bah/src/parser.bah"
char ____BAH_COMPILER_VAR_1417(array(char *)* arr, char * el) {
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
char ____BAH_COMPILER_VAR_1424(array(char *)* arr, char * el) {
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
__BAH_ARR_TYPE_Tok prePross(__BAH_ARR_TYPE_Tok line,lineType ltp,struct Elems* elems){

#line 3004 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct Tok)* fl = memoryAlloc(sizeof(array(struct Tok)));

fl->length = 0;
fl->elemSize = sizeof(struct Tok);

#line 3005 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int i = 0;

#line 3006 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int sepI = 0;

#line 3007 "/home/alois/Documents/bah-bah/src/parser.bah"
long int nbPar = 0;

#line 3009 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((ltp!=(lineType)-1)) {

#line 3010 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<len(line)); 
#line 3010 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 3011 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = line->data[i];

#line 3012 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "\01\0\0\0""(") == 0)) {

#line 3013 "/home/alois/Documents/bah-bah/src/parser.bah"
char isFunc = true;

#line 3014 "/home/alois/Documents/bah-bah/src/parser.bah"
nbPar = nbPar+1;
}

#line 3015 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(t.cont, "\01\0\0\0"")") == 0)) {

#line 3016 "/home/alois/Documents/bah-bah/src/parser.bah"
nbPar = nbPar-1;
}

#line 3017 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((nbPar==0)&&(strcmp(t.cont, "\01\0\0\0""{") == 0)) {

#line 3018 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((line->data[i+1].line!=t.line)) {

#line 3019 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}
}
};

#line 3023 "/home/alois/Documents/bah-bah/src/parser.bah"
fl = arraySubstitute(line, 0, i);

#line 3024 "/home/alois/Documents/bah-bah/src/parser.bah"
sepI = i;
}

#line 3025 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 3026 "/home/alois/Documents/bah-bah/src/parser.bah"
fl = line;
}

#line 3029 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok ____BAH_COMPILER_VAR_1412 = {};
____BAH_COMPILER_VAR_1412.cont = "\0\0\0\0""";
____BAH_COMPILER_VAR_1412.ogCont = "\0\0\0\0""";
____BAH_COMPILER_VAR_1412.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1412.line = 1;
____BAH_COMPILER_VAR_1412.begLine = 1;
____BAH_COMPILER_VAR_1412.bahType = "\0\0\0\0""";
struct Tok pt = ____BAH_COMPILER_VAR_1412;

#line 3030 "/home/alois/Documents/bah-bah/src/parser.bah"
unsigned long int l = len(fl);

#line 3032 "/home/alois/Documents/bah-bah/src/parser.bah"
i = 0;

#line 3032 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<len(fl)); 
#line 3032 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 3033 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = fl->data[i];

#line 3034 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((t.type==TOKEN_TYPE_VAR)&&(t.isOper==false)&&(t.cont[0+4]==38)) {

#line 3035 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string tc = string(t.cont);

#line 3036 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimLeft(&tc,1);

#line 3037 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* rv = getRealVar(string__str(&tc),elems);

#line 3038 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((rv!=null)&&(rv->canBeReg==true)&&(rv->declRope!=null)) {

#line 3039 "/home/alois/Documents/bah-bah/src/parser.bah"
char * rvdr = rope__toStr(rv->declRope);

#line 3040 "/home/alois/Documents/bah-bah/src/parser.bah"
if (strHasPrefix(rvdr,"\011\0\0\0""register ")) {

#line 3041 "/home/alois/Documents/bah-bah/src/parser.bah"
strTrimLeft(&rvdr,9);

#line 3042 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT->totalLen = OUTPUT->totalLen+ropeSet(rv->declRope,rvdr);
}

#line 3044 "/home/alois/Documents/bah-bah/src/parser.bah"
rv->canBeReg = false;
}
}
};

#line 3049 "/home/alois/Documents/bah-bah/src/parser.bah"
i = 0;

#line 3049 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<len(fl)); 
#line 3049 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 3050 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((fl->data[i].type==TOKEN_TYPE_STR)&&(fl->data[i].processedStr==false)) {

#line 3051 "/home/alois/Documents/bah-bah/src/parser.bah"
fl->data[i].cont = strLitteralToBahStr(fl->data[i].cont);

#line 3052 "/home/alois/Documents/bah-bah/src/parser.bah"
fl->data[i].processedStr = true;
}
};

#line 3056 "/home/alois/Documents/bah-bah/src/parser.bah"
if (fixMeEnabled()) {

#line 3057 "/home/alois/Documents/bah-bah/src/parser.bah"
i = 0;

#line 3057 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<len(fl)); 
#line 3057 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 3058 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((fl->data[i].cont[0+4]==42)) {

#line 3059 "/home/alois/Documents/bah-bah/src/parser.bah"
fixMeTestVar(&fl->data[i],ltp,elems);
}
};
}

#line 3064 "/home/alois/Documents/bah-bah/src/parser.bah"
i = 0;

#line 3064 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<len(fl)); 
#line 3064 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 3065 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = fl->data[i];

#line 3066 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((i>0)) {

#line 3067 "/home/alois/Documents/bah-bah/src/parser.bah"
pt = fl->data[i-1];
}

#line 3068 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 3069 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok ____BAH_COMPILER_VAR_1413 = {};
____BAH_COMPILER_VAR_1413.cont = "\0\0\0\0""";
____BAH_COMPILER_VAR_1413.ogCont = "\0\0\0\0""";
____BAH_COMPILER_VAR_1413.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1413.line = 1;
____BAH_COMPILER_VAR_1413.begLine = 1;
____BAH_COMPILER_VAR_1413.bahType = "\0\0\0\0""";
pt = ____BAH_COMPILER_VAR_1413;
}

#line 3072 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "\01\0\0\0"".") == 0)&&(i>0)) {

#line 3073 "/home/alois/Documents/bah-bah/src/parser.bah"
i = valueStruct(fl,i,ltp,elems)-1;
}

#line 3074 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(t.cont, "\01\0\0\0""(") == 0)&&(strcmp(pt.cont, "\010\0\0\0""function") != 0)) {

#line 3075 "/home/alois/Documents/bah-bah/src/parser.bah"
i = valueFunc(null,null,fl,i,ltp,elems)-1;
}

#line 3076 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(t.cont, "\01\0\0\0""[") == 0)&&(pt.isValue==true)) {

#line 3077 "/home/alois/Documents/bah-bah/src/parser.bah"
i = valueArr(fl,i,ltp,elems)-1;
}

#line 3078 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(t.cont, "\01\0\0\0""[") == 0)) {

#line 3079 "/home/alois/Documents/bah-bah/src/parser.bah"
i = valueTuple(fl,i,elems)-1;
}

#line 3080 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((pt.type==TOKEN_TYPE_CAST)&&isSmallValue(fl,i)) {

#line 3081 "/home/alois/Documents/bah-bah/src/parser.bah"
delete(fl,i-1);

#line 3082 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string ptc = string(pt.cont);

#line 3083 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimLeft(&ptc,1);

#line 3084 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimRight(&ptc,1);

#line 3085 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((t.type==TOKEN_TYPE_VAR)) {

#line 3086 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* v = searchVar(t.cont,elems);

#line 3087 "/home/alois/Documents/bah-bah/src/parser.bah"
t.bahRef = v;
}

#line 3089 "/home/alois/Documents/bah-bah/src/parser.bah"
t.bahType = string__str(&ptc);

#line 3090 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string cType = getCType(string__str(&ptc),elems);

#line 3091 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1414 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1414[3] = t.cont;____BAH_COMPILER_VAR_1414[2] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1414[1] = string__str(&cType);____BAH_COMPILER_VAR_1414[0] = "\01\0\0\0""(";char * ____BAH_COMPILER_VAR_1415 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1414, 4);t.cont = ____BAH_COMPILER_VAR_1415;

#line 3092 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1416 = i-1;
    __Bah_realocate_arr(fl, ____BAH_COMPILER_VAR_1416);
    fl->data[____BAH_COMPILER_VAR_1416] = t;

#line 3093 "/home/alois/Documents/bah-bah/src/parser.bah"
i = i-2;
}

#line 3094 "/home/alois/Documents/bah-bah/src/parser.bah"
else if (____BAH_COMPILER_VAR_1417(signs, pt.cont)) {

#line 3095 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, pt.cont) == 0)&&(i>1)) {

#line 3096 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok ppt = fl->data[i-2];

#line 3097 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((ppt.type==TOKEN_TYPE_VAR)) {

#line 3098 "/home/alois/Documents/bah-bah/src/parser.bah"
long int posTok = i-2;

#line 3099 "/home/alois/Documents/bah-bah/src/parser.bah"
deleteRange(fl,i-1,i);

#line 3100 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1418 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1418[2] = ppt.cont;____BAH_COMPILER_VAR_1418[1] = t.cont;____BAH_COMPILER_VAR_1418[0] = t.cont;char * ____BAH_COMPILER_VAR_1419 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1418, 3);ppt.cont = ____BAH_COMPILER_VAR_1419;

#line 3101 "/home/alois/Documents/bah-bah/src/parser.bah"
ppt.isValue = true;

#line 3102 "/home/alois/Documents/bah-bah/src/parser.bah"
ppt.isOper = true;

#line 3103 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1420 = posTok;
    __Bah_realocate_arr(fl, ____BAH_COMPILER_VAR_1420);
    fl->data[____BAH_COMPILER_VAR_1420] = ppt;

#line 3104 "/home/alois/Documents/bah-bah/src/parser.bah"
i = posTok-1;
}

#line 3105 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 3106 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&ppt,"\066\0\0\0""Cannot increment/decrement non variable value {TOKEN}.");
}
}

#line 3108 "/home/alois/Documents/bah-bah/src/parser.bah"
else if (isValue(fl,i)) {

#line 3109 "/home/alois/Documents/bah-bah/src/parser.bah"
i = valueOper(fl,i,elems)-1;
}
}

#line 3111 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((t.cont[0+4]==45)&&(pt.isValue==true)) {

#line 3112 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((t.type==TOKEN_TYPE_INT)||(t.type==TOKEN_TYPE_FLOAT)) {

#line 3113 "/home/alois/Documents/bah-bah/src/parser.bah"
delete(fl,i);

#line 3114 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ptt = getTypeFromToken(&pt,true,elems);

#line 3115 "/home/alois/Documents/bah-bah/src/parser.bah"
pt.bahType = ptt;

#line 3116 "/home/alois/Documents/bah-bah/src/parser.bah"
pt.isOper = true;

#line 3117 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1421 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1421[1] = t.cont;____BAH_COMPILER_VAR_1421[0] = pt.cont;char * ____BAH_COMPILER_VAR_1422 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1421, 2);pt.cont = ____BAH_COMPILER_VAR_1422;

#line 3118 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1423 = i-1;
    __Bah_realocate_arr(fl, ____BAH_COMPILER_VAR_1423);
    fl->data[____BAH_COMPILER_VAR_1423] = pt;

#line 3119 "/home/alois/Documents/bah-bah/src/parser.bah"
i = i-2;
}
}

#line 3121 "/home/alois/Documents/bah-bah/src/parser.bah"
else if (____BAH_COMPILER_VAR_1424(comparators, pt.cont)&&isValue(fl,i)) {

#line 3122 "/home/alois/Documents/bah-bah/src/parser.bah"
i = valueBool(fl,i,ltp,elems)-1;
}

#line 3123 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(pt.cont, "\02\0\0\0""<-") == 0)&&isValue(fl,i)) {

#line 3124 "/home/alois/Documents/bah-bah/src/parser.bah"
i = valueChan(fl,i,elems)-1;
}

#line 3125 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(pt.cont, "\02\0\0\0""->") == 0)&&isValue(fl,i)) {

#line 3126 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((i-2>=0)) {

#line 3127 "/home/alois/Documents/bah-bah/src/parser.bah"
if (isValue(fl,i-2)) {

#line 3128 "/home/alois/Documents/bah-bah/src/parser.bah"
i = valueSendChan(fl,i,elems)-1;
}
}

#line 3130 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 3131 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"\044\0\0\0""Cannot {TOKEN} nothing through chan.");
}
}
};

#line 3137 "/home/alois/Documents/bah-bah/src/parser.bah"
i = 0;

#line 3137 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<len(fl)); 
#line 3137 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 3138 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = fl->data[i];

#line 3139 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "\02\0\0\0""||") == 0)||(strcmp(t.cont, "\02\0\0\0""&&") == 0)) {

#line 3140 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((i==0)||(i+1==len(fl)), 0)) {

#line 3141 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"\036\0\0\0""Cannot use {TOKEN} on nothing.");
}

#line 3143 "/home/alois/Documents/bah-bah/src/parser.bah"
pt = fl->data[i-1];

#line 3144 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok nt = fl->data[i+1];

#line 3145 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ptt = getTypeFromToken(&pt,true,elems);

#line 3146 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ntt = getTypeFromToken(&nt,true,elems);

#line 3147 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((compTypes(ptt,ntt)==false)||(compTypes(ptt,"\04\0\0\0""bool")==false), 0)) {

#line 3148 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1425 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1425[2] = "\01\0\0\0"".";____BAH_COMPILER_VAR_1425[1] = ptt;____BAH_COMPILER_VAR_1425[0] = "\026\0\0\0""Cannot use {TOKEN} on ";char * ____BAH_COMPILER_VAR_1426 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1425, 3);throwErr(&t,____BAH_COMPILER_VAR_1426);
}

#line 3151 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "\02\0\0\0""||") == 0)&&(isExprExpensive(&pt)==false)&&(isExprExpensive(&nt)==false)) {

#line 3152 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1427 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1427[1] = nt.cont;____BAH_COMPILER_VAR_1427[0] = "\02\0\0\0""||";char * ____BAH_COMPILER_VAR_1428 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1427, 2);char** ____BAH_COMPILER_VAR_1429 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1429[1] = ____BAH_COMPILER_VAR_1428;____BAH_COMPILER_VAR_1429[0] = pt.cont;char * ____BAH_COMPILER_VAR_1430 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1429, 2);pt.cont = ____BAH_COMPILER_VAR_1430;
}

#line 3153 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 3154 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1431 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1431[1] = nt.cont;____BAH_COMPILER_VAR_1431[0] = t.cont;char * ____BAH_COMPILER_VAR_1432 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1431, 2);char** ____BAH_COMPILER_VAR_1433 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1433[1] = ____BAH_COMPILER_VAR_1432;____BAH_COMPILER_VAR_1433[0] = pt.cont;char * ____BAH_COMPILER_VAR_1434 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1433, 2);pt.cont = ____BAH_COMPILER_VAR_1434;
}

#line 3156 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1435 = i-1;
    __Bah_realocate_arr(fl, ____BAH_COMPILER_VAR_1435);
    fl->data[____BAH_COMPILER_VAR_1435] = pt;

#line 3157 "/home/alois/Documents/bah-bah/src/parser.bah"
deleteRange(fl,i,i+1);

#line 3158 "/home/alois/Documents/bah-bah/src/parser.bah"
i = i-2;
}

#line 3159 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((t.type==TOKEN_TYPE_VAR)&&(t.cont[0+4]==38)) {

#line 3160 "/home/alois/Documents/bah-bah/src/parser.bah"
char * tt = getTypeFromToken(&t,true,elems);

#line 3161 "/home/alois/Documents/bah-bah/src/parser.bah"

                struct string ____BAH_COMPILER_VAR_1436 = string(tt);
                if (__builtin_expect(string__hasPrefix(&____BAH_COMPILER_VAR_1436,"\06\0\0\0""tuple:"), 0)) {

#line 3162 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"\046\0\0\0""Cannot get pointer of a tuple {TOKEN}.");
}
}
};

#line 3167 "/home/alois/Documents/bah-bah/src/parser.bah"
fl = parseArrayType(fl,elems,true);

#line 3168 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((RCPavailable()==true)) {

#line 3169 "/home/alois/Documents/bah-bah/src/parser.bah"
addRCPvars(fl,ltp,elems);
}

#line 3172 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((ltp!=(lineType)-1)) {

#line 3173 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((sepI<len(line))) {

#line 3174 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1437 = len(fl);
    __Bah_realocate_arr(fl, ____BAH_COMPILER_VAR_1437);
    fl->data[____BAH_COMPILER_VAR_1437] = line->data[sepI];

#line 3175 "/home/alois/Documents/bah-bah/src/parser.bah"
++sepI;
};
}

#line 3181 "/home/alois/Documents/bah-bah/src/parser.bah"
return fl;
};

#line 3184 "/home/alois/Documents/bah-bah/src/parser.bah"
void parseFnDeclare(__BAH_ARR_TYPE_Tok l,struct Elems* elems){

#line 3185 "/home/alois/Documents/bah-bah/src/parser.bah"
long int i = 0;

#line 3186 "/home/alois/Documents/bah-bah/src/parser.bah"
struct func* ____BAH_COMPILER_VAR_1438 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_1438->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_1438->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_1438->args->length = 0;
            ____BAH_COMPILER_VAR_1438->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_1438->from = "\0\0\0\0""";
____BAH_COMPILER_VAR_1438->file = "\0\0\0\0""";
____BAH_COMPILER_VAR_1438->line = 1;
struct func* fn = ____BAH_COMPILER_VAR_1438;

#line 3188 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((RCPavailable()==false)&&(RCPenabled==true)) {

#line 3189 "/home/alois/Documents/bah-bah/src/parser.bah"
fn->used = true;
}

#line 3192 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok ft = l->data[0];

#line 3193 "/home/alois/Documents/bah-bah/src/parser.bah"
char * code = parseFnHeader("\0\0\0\0""",l,&i,fn,elems);

#line 3194 "/home/alois/Documents/bah-bah/src/parser.bah"
fn->line = ft.line;

#line 3195 "/home/alois/Documents/bah-bah/src/parser.bah"
fn->file = compilerState.currentFile;

#line 3196 "/home/alois/Documents/bah-bah/src/parser.bah"
struct func* ogFn = searchFunc(fn->name,elems,false);

#line 3197 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((ogFn!=null)) {

#line 3198 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((ogFn->isBinding==false), 0)) {

#line 3199 "/home/alois/Documents/bah-bah/src/parser.bah"
char * lineStr = intToStr(ogFn->line);

#line 3200 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1439 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1439[4] = "\01\0\0\0"".";____BAH_COMPILER_VAR_1439[3] = lineStr;____BAH_COMPILER_VAR_1439[2] = "\01\0\0\0"":";____BAH_COMPILER_VAR_1439[1] = ogFn->file;____BAH_COMPILER_VAR_1439[0] = "\071\0\0\0""Cannot redeclare function {TOKEN}, previous declaration: ";char * ____BAH_COMPILER_VAR_1440 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1439, 5);throwErr(&ft,____BAH_COMPILER_VAR_1440);
}
}

#line 3204 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(fn->name, "\04\0\0\0""main") == 0)) {

#line 3205 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.haveEntryPoint = true;

#line 3206 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((compTypes(fn->returns->type,"\03\0\0\0""int")==false), 0)) {

#line 3207 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&ft,"\045\0\0\0""{TOKEN} function should return 'int'.");
}

#line 3209 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((len(fn->args)!=1), 0)) {

#line 3210 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&ft,"\151\0\0\0""{TOKEN} function should take one []cpstring argument. Should be: \n            'main(args []cpstring) int'");
}

#line 3213 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* fa = fn->args->data[0];

#line 3214 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((compTypes(fa->type,"\012\0\0\0""[]cpstring")==false), 0)) {

#line 3215 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&ft,"\150\0\0\0""{TOKEN} function should take []cpstring as argument. Should be: \n            'main(args []cpstring) int'");
}
}

#line 3220 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((debug==true)) {

#line 3221 "/home/alois/Documents/bah-bah/src/parser.bah"
struct debugFunction* ____BAH_COMPILER_VAR_1441 = memoryAlloc(sizeof(struct debugFunction));
____BAH_COMPILER_VAR_1441->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_1441->args->length = 0;
            ____BAH_COMPILER_VAR_1441->args->elemSize = sizeof(struct variable*);
            struct debugFunction* df = ____BAH_COMPILER_VAR_1441;

#line 3222 "/home/alois/Documents/bah-bah/src/parser.bah"
df->name = fn->name;

#line 3223 "/home/alois/Documents/bah-bah/src/parser.bah"
df->args = fn->args;

#line 3224 "/home/alois/Documents/bah-bah/src/parser.bah"
df->returns = fn->returns->type;

#line 3225 "/home/alois/Documents/bah-bah/src/parser.bah"
struct debugFunction* ____BAH_COMPILER_VAR_1442 = df;
char ** ____BAH_COMPILER_VAR_1444 = (char **)((char*)(____BAH_COMPILER_VAR_1442) + offsetof(struct debugFunction, name));
struct reflectElement ____BAH_COMPILER_VAR_1445 = __reflect(____BAH_COMPILER_VAR_1444, sizeof(char *), "\010\0\0\0""cpstring", "\04\0\0\0""name", 0, 0, 0, 0, offsetof(struct debugFunction, name));
char ** ____BAH_COMPILER_VAR_1446 = (char **)((char*)(____BAH_COMPILER_VAR_1442) + offsetof(struct debugFunction, returns));
struct reflectElement ____BAH_COMPILER_VAR_1447 = __reflect(____BAH_COMPILER_VAR_1446, sizeof(char *), "\010\0\0\0""cpstring", "\07\0\0\0""returns", 0, 0, 0, 0, offsetof(struct debugFunction, returns));
array(struct variable*)** ____BAH_COMPILER_VAR_1448 = (array(struct variable*)**)((char*)(____BAH_COMPILER_VAR_1442) + offsetof(struct debugFunction, args));
struct variable** ____BAH_COMPILER_VAR_1449 = 0;
char ** ____BAH_COMPILER_VAR_1451 = (char **)((char*)(____BAH_COMPILER_VAR_1449) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_1452 = __reflect(____BAH_COMPILER_VAR_1451, sizeof(char *), "\010\0\0\0""cpstring", "\04\0\0\0""name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_1453 = (char **)((char*)(____BAH_COMPILER_VAR_1449) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_1454 = __reflect(____BAH_COMPILER_VAR_1453, sizeof(char *), "\010\0\0\0""cpstring", "\04\0\0\0""type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_1455 = (char*)((char*)(____BAH_COMPILER_VAR_1449) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_1456 = __reflect(____BAH_COMPILER_VAR_1455, sizeof(char), "\04\0\0\0""bool", "\07\0\0\0""isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_1457 = (char **)((char*)(____BAH_COMPILER_VAR_1449) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_1458 = __reflect(____BAH_COMPILER_VAR_1457, sizeof(char *), "\010\0\0\0""cpstring", "\010\0\0\0""constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_1459 = (char*)((char*)(____BAH_COMPILER_VAR_1449) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_1460 = __reflect(____BAH_COMPILER_VAR_1459, sizeof(char), "\04\0\0\0""bool", "\07\0\0\0""isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_1461 = (char **)((char*)(____BAH_COMPILER_VAR_1449) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_1462 = __reflect(____BAH_COMPILER_VAR_1461, sizeof(char *), "\010\0\0\0""cpstring", "\04\0\0\0""from", 0, 0, 0, 0, offsetof(struct variable, from));
void ** ____BAH_COMPILER_VAR_1463 = (void **)((char*)(____BAH_COMPILER_VAR_1449) + offsetof(struct variable, declScope));
struct reflectElement ____BAH_COMPILER_VAR_1464 = __reflect(____BAH_COMPILER_VAR_1463, sizeof(void *), "\03\0\0\0""ptr", "\011\0\0\0""declScope", 0, 0, 0, 0, offsetof(struct variable, declScope));
char* ____BAH_COMPILER_VAR_1465 = (char*)((char*)(____BAH_COMPILER_VAR_1449) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_1466 = __reflect(____BAH_COMPILER_VAR_1465, sizeof(char), "\04\0\0\0""bool", "\010\0\0\0""isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));
struct rope** ____BAH_COMPILER_VAR_1467 = (struct rope**)((char*)(____BAH_COMPILER_VAR_1449) + offsetof(struct variable, declRope));
char ** ____BAH_COMPILER_VAR_1469 = (char **)((char*)(____BAH_COMPILER_VAR_1467) + offsetof(struct rope, str));
struct reflectElement ____BAH_COMPILER_VAR_1470 = __reflect(____BAH_COMPILER_VAR_1469, sizeof(char *), "\010\0\0\0""cpstring", "\03\0\0\0""str", 0, 0, 0, 0, offsetof(struct rope, str));
int* ____BAH_COMPILER_VAR_1471 = (int*)((char*)(____BAH_COMPILER_VAR_1467) + offsetof(struct rope, totalLen));
struct reflectElement ____BAH_COMPILER_VAR_1472 = __reflect(____BAH_COMPILER_VAR_1471, sizeof(int), "\05\0\0\0""int32", "\010\0\0\0""totalLen", 0, 0, 0, 0, offsetof(struct rope, totalLen));
void ** ____BAH_COMPILER_VAR_1473 = (void **)((char*)(____BAH_COMPILER_VAR_1467) + offsetof(struct rope, left));
struct reflectElement ____BAH_COMPILER_VAR_1474 = __reflect(____BAH_COMPILER_VAR_1473, sizeof(void *), "\03\0\0\0""ptr", "\04\0\0\0""left", 0, 0, 0, 0, offsetof(struct rope, left));
void ** ____BAH_COMPILER_VAR_1475 = (void **)((char*)(____BAH_COMPILER_VAR_1467) + offsetof(struct rope, right));
struct reflectElement ____BAH_COMPILER_VAR_1476 = __reflect(____BAH_COMPILER_VAR_1475, sizeof(void *), "\03\0\0\0""ptr", "\05\0\0\0""right", 0, 0, 0, 0, offsetof(struct rope, right));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_1468 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_1468->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_1468->length = 4;
        ____BAH_COMPILER_VAR_1468->data = memoryAlloc(____BAH_COMPILER_VAR_1468->length * ____BAH_COMPILER_VAR_1468->elemSize);
        ____BAH_COMPILER_VAR_1468->data[0] = ____BAH_COMPILER_VAR_1470;
____BAH_COMPILER_VAR_1468->data[1] = ____BAH_COMPILER_VAR_1472;
____BAH_COMPILER_VAR_1468->data[2] = ____BAH_COMPILER_VAR_1474;
____BAH_COMPILER_VAR_1468->data[3] = ____BAH_COMPILER_VAR_1476;
struct reflectElement ____BAH_COMPILER_VAR_1477 = __reflect(____BAH_COMPILER_VAR_1467, sizeof(struct rope), "\05\0\0\0""rope*", "\010\0\0\0""declRope", 0, 0, 1, ____BAH_COMPILER_VAR_1468, offsetof(struct variable, declRope));
char* ____BAH_COMPILER_VAR_1478 = (char*)((char*)(____BAH_COMPILER_VAR_1449) + offsetof(struct variable, canBeNull));
struct reflectElement ____BAH_COMPILER_VAR_1479 = __reflect(____BAH_COMPILER_VAR_1478, sizeof(char), "\04\0\0\0""bool", "\011\0\0\0""canBeNull", 0, 0, 0, 0, offsetof(struct variable, canBeNull));
void ** ____BAH_COMPILER_VAR_1480 = (void **)((char*)(____BAH_COMPILER_VAR_1449) + offsetof(struct variable, iterScope));
struct reflectElement ____BAH_COMPILER_VAR_1481 = __reflect(____BAH_COMPILER_VAR_1480, sizeof(void *), "\03\0\0\0""ptr", "\011\0\0\0""iterScope", 0, 0, 0, 0, offsetof(struct variable, iterScope));
char* ____BAH_COMPILER_VAR_1482 = (char*)((char*)(____BAH_COMPILER_VAR_1449) + offsetof(struct variable, canBeReg));
struct reflectElement ____BAH_COMPILER_VAR_1483 = __reflect(____BAH_COMPILER_VAR_1482, sizeof(char), "\04\0\0\0""bool", "\010\0\0\0""canBeReg", 0, 0, 0, 0, offsetof(struct variable, canBeReg));
char* ____BAH_COMPILER_VAR_1484 = (char*)((char*)(____BAH_COMPILER_VAR_1449) + offsetof(struct variable, isReg));
struct reflectElement ____BAH_COMPILER_VAR_1485 = __reflect(____BAH_COMPILER_VAR_1484, sizeof(char), "\04\0\0\0""bool", "\05\0\0\0""isReg", 0, 0, 0, 0, offsetof(struct variable, isReg));
void ** ____BAH_COMPILER_VAR_1486 = (void **)((char*)(____BAH_COMPILER_VAR_1449) + offsetof(struct variable, lastSet));
struct reflectElement ____BAH_COMPILER_VAR_1487 = __reflect(____BAH_COMPILER_VAR_1486, sizeof(void *), "\03\0\0\0""ptr", "\07\0\0\0""lastSet", 0, 0, 0, 0, offsetof(struct variable, lastSet));
char* ____BAH_COMPILER_VAR_1488 = (char*)((char*)(____BAH_COMPILER_VAR_1449) + offsetof(struct variable, isArg));
struct reflectElement ____BAH_COMPILER_VAR_1489 = __reflect(____BAH_COMPILER_VAR_1488, sizeof(char), "\04\0\0\0""bool", "\05\0\0\0""isArg", 0, 0, 0, 0, offsetof(struct variable, isArg));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_1450 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_1450->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_1450->length = 15;
        ____BAH_COMPILER_VAR_1450->data = memoryAlloc(____BAH_COMPILER_VAR_1450->length * ____BAH_COMPILER_VAR_1450->elemSize);
        ____BAH_COMPILER_VAR_1450->data[0] = ____BAH_COMPILER_VAR_1452;
____BAH_COMPILER_VAR_1450->data[1] = ____BAH_COMPILER_VAR_1454;
____BAH_COMPILER_VAR_1450->data[2] = ____BAH_COMPILER_VAR_1456;
____BAH_COMPILER_VAR_1450->data[3] = ____BAH_COMPILER_VAR_1458;
____BAH_COMPILER_VAR_1450->data[4] = ____BAH_COMPILER_VAR_1460;
____BAH_COMPILER_VAR_1450->data[5] = ____BAH_COMPILER_VAR_1462;
____BAH_COMPILER_VAR_1450->data[6] = ____BAH_COMPILER_VAR_1464;
____BAH_COMPILER_VAR_1450->data[7] = ____BAH_COMPILER_VAR_1466;
____BAH_COMPILER_VAR_1450->data[8] = ____BAH_COMPILER_VAR_1477;
____BAH_COMPILER_VAR_1450->data[9] = ____BAH_COMPILER_VAR_1479;
____BAH_COMPILER_VAR_1450->data[10] = ____BAH_COMPILER_VAR_1481;
____BAH_COMPILER_VAR_1450->data[11] = ____BAH_COMPILER_VAR_1483;
____BAH_COMPILER_VAR_1450->data[12] = ____BAH_COMPILER_VAR_1485;
____BAH_COMPILER_VAR_1450->data[13] = ____BAH_COMPILER_VAR_1487;
____BAH_COMPILER_VAR_1450->data[14] = ____BAH_COMPILER_VAR_1489;
struct reflectElement ____BAH_COMPILER_VAR_1490 = __reflect(____BAH_COMPILER_VAR_1449, sizeof(struct variable), "\011\0\0\0""variable*", "\0\0\0\0""", 0, 0, 1, ____BAH_COMPILER_VAR_1450, 0);

        struct reflectElement ____BAH_COMPILER_VAR_1491 = ____BAH_COMPILER_VAR_1490;
        struct reflectElement ____BAH_COMPILER_VAR_1492 = __reflect(____BAH_COMPILER_VAR_1448, sizeof(array(struct variable*)*), "\013\0\0\0""[]variable*", "\04\0\0\0""args", 1, &____BAH_COMPILER_VAR_1491, 0, 0, offsetof(struct debugFunction, args));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_1443 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_1443->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_1443->length = 3;
        ____BAH_COMPILER_VAR_1443->data = memoryAlloc(____BAH_COMPILER_VAR_1443->length * ____BAH_COMPILER_VAR_1443->elemSize);
        ____BAH_COMPILER_VAR_1443->data[0] = ____BAH_COMPILER_VAR_1445;
____BAH_COMPILER_VAR_1443->data[1] = ____BAH_COMPILER_VAR_1447;
____BAH_COMPILER_VAR_1443->data[2] = ____BAH_COMPILER_VAR_1492;
struct reflectElement ____BAH_COMPILER_VAR_1493 = __reflect(____BAH_COMPILER_VAR_1442, sizeof(struct debugFunction), "\016\0\0\0""debugFunction*", "\02\0\0\0""df", 0, 0, 1, ____BAH_COMPILER_VAR_1443, 0);
debugPrint("\012\0\0\0""fn_declare",ft.line,____BAH_COMPILER_VAR_1493);
}

#line 3228 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int j = 0;

#line 3228 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (j<len(fn->args)); 
#line 3228 "/home/alois/Documents/bah-bah/src/parser.bah"
++j) {

#line 3229 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(fn->args->data[j]->type, "\05\0\0\0""<any>") == 0)) {

#line 3230 "/home/alois/Documents/bah-bah/src/parser.bah"
struct genericFunc* ____BAH_COMPILER_VAR_1494 = memoryAlloc(sizeof(struct genericFunc));
____BAH_COMPILER_VAR_1494->tokens = memoryAlloc(sizeof(array(struct Tok)));
            ____BAH_COMPILER_VAR_1494->tokens->length = 0;
            ____BAH_COMPILER_VAR_1494->tokens->elemSize = sizeof(struct Tok);
            ____BAH_COMPILER_VAR_1494->declared = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_1494->declared->length = 0;
            ____BAH_COMPILER_VAR_1494->declared->elemSize = sizeof(struct func*);
            ____BAH_COMPILER_VAR_1494->tokens = arraySubstitute(l, i+1, len(l)-1);
____BAH_COMPILER_VAR_1494->baseFn = fn;
____BAH_COMPILER_VAR_1494->tokenName = &ft;

    unsigned int ____BAH_COMPILER_VAR_1495 = len(generics);
    __Bah_realocate_arr(generics, ____BAH_COMPILER_VAR_1495);
    generics->data[____BAH_COMPILER_VAR_1495] = ____BAH_COMPILER_VAR_1494;

#line 3235 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}
};

#line 3239 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((shouldOnlyDecl==true)) {

#line 3240 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((ogFn!=null)) {

#line 3241 "/home/alois/Documents/bah-bah/src/parser.bah"
fn->isBinding = false;
}

#line 3243 "/home/alois/Documents/bah-bah/src/parser.bah"
fn->isImported = true;

#line 3244 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1496 = len(elems->fns);
    __Bah_realocate_arr(elems->fns, ____BAH_COMPILER_VAR_1496);
    elems->fns->data[____BAH_COMPILER_VAR_1496] = fn;

#line 3245 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1497 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1497[1] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_1497[0] = code;char * ____BAH_COMPILER_VAR_1498 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1497, 2);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1498));

#line 3246 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}

#line 3249 "/home/alois/Documents/bah-bah/src/parser.bah"
postDeclHandle = rope("\0\0\0\0""");

#line 3250 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope__add(OUTPUT, postDeclHandle);

#line 3252 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1499 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1499[1] = "\02\0\0\0""{\n";____BAH_COMPILER_VAR_1499[0] = code;char * ____BAH_COMPILER_VAR_1500 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1499, 2);code = ____BAH_COMPILER_VAR_1500;

#line 3254 "/home/alois/Documents/bah-bah/src/parser.bah"
fn->code = rope(code);

#line 3257 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Elems* fnElems = dupElems(elems);

#line 3259 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct variable*)* vs = fnElems->vars;

#line 3260 "/home/alois/Documents/bah-bah/src/parser.bah"
j = 0;

#line 3260 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((j<len(fn->args))) {

#line 3261 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* a = fn->args->data[j];

#line 3262 "/home/alois/Documents/bah-bah/src/parser.bah"
a->declScope = elems;

#line 3263 "/home/alois/Documents/bah-bah/src/parser.bah"
a->isArg = true;

#line 3264 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1501 = len(vs);
    __Bah_realocate_arr(vs, ____BAH_COMPILER_VAR_1501);
    vs->data[____BAH_COMPILER_VAR_1501] = a;

#line 3265 "/home/alois/Documents/bah-bah/src/parser.bah"
j = j+1;
};

#line 3267 "/home/alois/Documents/bah-bah/src/parser.bah"
fnElems->vars = vs;

#line 3269 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((ogFn!=null)) {

#line 3270 "/home/alois/Documents/bah-bah/src/parser.bah"
ogFn->isBinding = false;

#line 3271 "/home/alois/Documents/bah-bah/src/parser.bah"
ogFn->used = true;

#line 3272 "/home/alois/Documents/bah-bah/src/parser.bah"
ogFn = fn;
}

#line 3273 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 3274 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct func*)* fns = elems->fns;

#line 3275 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1502 = len(fns);
    __Bah_realocate_arr(fns, ____BAH_COMPILER_VAR_1502);
    fns->data[____BAH_COMPILER_VAR_1502] = fn;
}

#line 3278 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 3279 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct Tok)* tokens = arraySubstitute(l, i, len(l)-1);

#line 3281 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((len(tokens)==0)) {

#line 3282 "/home/alois/Documents/bah-bah/src/parser.bah"
fn->code = rope__add(fn->code, rope("\03\0\0\0""};\n"));

#line 3283 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope__add(OUTPUT, fn->code);

#line 3284 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}

#line 3287 "/home/alois/Documents/bah-bah/src/parser.bah"
currentFn = fn;

#line 3289 "/home/alois/Documents/bah-bah/src/parser.bah"
struct rope* oOut = OUTPUT;

#line 3290 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope("\0\0\0\0""");

#line 3291 "/home/alois/Documents/bah-bah/src/parser.bah"
beginRCPscope(fnElems,fn->args);

#line 3292 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Elems* ocurrFnElems = compilerState.currFnElems;

#line 3293 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.currFnElems = fnElems;

#line 3294 "/home/alois/Documents/bah-bah/src/parser.bah"
parseLines(tokens,fnElems);

#line 3295 "/home/alois/Documents/bah-bah/src/parser.bah"
OPTI_checkFuncScopeRef(fnElems);

#line 3297 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.currFnElems = ocurrFnElems;

#line 3298 "/home/alois/Documents/bah-bah/src/parser.bah"
currentFn = null;

#line 3299 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((fn->returned==false)) {

#line 3300 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((strlen(fn->returns->type)>0), 0)) {

#line 3301 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1503 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1503[2] = "\022\0\0\0""' is not returned.";____BAH_COMPILER_VAR_1503[1] = fn->name;____BAH_COMPILER_VAR_1503[0] = "\012\0\0\0""Function '";char * ____BAH_COMPILER_VAR_1504 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1503, 3);throwErr(&l->data[len(l)-1],____BAH_COMPILER_VAR_1504);
}

#line 3303 "/home/alois/Documents/bah-bah/src/parser.bah"
endRCPscope(fnElems,fn->args);

#line 3304 "/home/alois/Documents/bah-bah/src/parser.bah"
fixMeEndScope(fnElems,&tokens->data[len(tokens)-1]);
}

#line 3308 "/home/alois/Documents/bah-bah/src/parser.bah"
fn->code = rope__add(fn->code, OUTPUT);

#line 3309 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = oOut;

#line 3310 "/home/alois/Documents/bah-bah/src/parser.bah"
fn->code = rope__add(fn->code, rope("\03\0\0\0""};\n"));

#line 3312 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((debug==true)) {

#line 3313 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok lt = l->data[len(l)-1];

#line 3314 "/home/alois/Documents/bah-bah/src/parser.bah"
debugEndScope(lt.line,fnElems);
}

#line 3317 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope__add(OUTPUT, fn->code);
};

#line 3322 "/home/alois/Documents/bah-bah/src/parser.bah"
void parseCapture(__BAH_ARR_TYPE_Tok line,struct Elems* elems){

#line 3323 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((len(line)<7), 0)) {

#line 3324 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&line->data[0],"\106\0\0\0""Invalid usage of {TOKEN} 'capture <var> = <maybe value> else {<code>}'");
}

#line 3327 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok varTok = line->data[1];

#line 3328 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok valTok = line->data[3];

#line 3329 "/home/alois/Documents/bah-bah/src/parser.bah"
char isThen = false;

#line 3331 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((varTok.type!=TOKEN_TYPE_VAR), 0)) {

#line 3332 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&varTok,"\037\0\0\0""Cannot use {TOKEN} as variable.");
}

#line 3336 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((strcmp(line->data[2].cont, "\01\0\0\0""=") != 0), 0)) {

#line 3337 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&line->data[2],"\031\0\0\0""Expected '=' got {TOKEN}.");
}

#line 3341 "/home/alois/Documents/bah-bah/src/parser.bah"
char * valType = getTypeFromToken(&valTok,true,elems);

#line 3342 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((valType[strlen(valType)-1+4]!=33), 0)) {

#line 3343 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1505 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1505[2] = "\021\0\0\0"") as maybe value.";____BAH_COMPILER_VAR_1505[1] = valType;____BAH_COMPILER_VAR_1505[0] = "\024\0\0\0""Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_1506 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1505, 3);throwErr(&valTok,____BAH_COMPILER_VAR_1506);
}

#line 3345 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1507 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1507[1] = "\01\0\0\0""*";____BAH_COMPILER_VAR_1507[0] = cpstringSubsitute(valType, 0, strlen(valType)-1);char * ____BAH_COMPILER_VAR_1508 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1507, 2);char * newType = ____BAH_COMPILER_VAR_1508;

#line 3348 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((strcmp(line->data[4].cont, "\04\0\0\0""else") != 0)&&(strcmp(line->data[4].cont, "\04\0\0\0""then") != 0), 0)) {

#line 3349 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&line->data[4],"\046\0\0\0""Expected 'then' or 'else' got {TOKEN}.");
}

#line 3352 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(line->data[4].cont, "\04\0\0\0""then") == 0)) {

#line 3353 "/home/alois/Documents/bah-bah/src/parser.bah"
isThen = true;
}

#line 3357 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* v = searchVar(varTok.cont,elems);

#line 3358 "/home/alois/Documents/bah-bah/src/parser.bah"
char * code = "\0\0\0\0""";

#line 3359 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((v==null)) {

#line 3360 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* ____BAH_COMPILER_VAR_1509 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1509->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_1509->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_1509->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_1509->from = "\0\0\0\0""";
____BAH_COMPILER_VAR_1509->name = varTok.cont;
____BAH_COMPILER_VAR_1509->type = newType;
v = ____BAH_COMPILER_VAR_1509;

#line 3364 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1510 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_1510);
    elems->vars->data[____BAH_COMPILER_VAR_1510] = v;

#line 3365 "/home/alois/Documents/bah-bah/src/parser.bah"

                struct string ____BAH_COMPILER_VAR_1511 = getCType(v->type,elems);
                char** ____BAH_COMPILER_VAR_1512 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1512[1] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_1512[0] = string__str(&____BAH_COMPILER_VAR_1511);char * ____BAH_COMPILER_VAR_1513 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1512, 2);code = ____BAH_COMPILER_VAR_1513;
}

#line 3366 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 3367 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((strcmp(v->type, newType) != 0), 0)) {

#line 3368 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1514 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1514[4] = "\01\0\0\0"".";____BAH_COMPILER_VAR_1514[3] = newType;____BAH_COMPILER_VAR_1514[2] = "\05\0\0\0"") as ";____BAH_COMPILER_VAR_1514[1] = v->type;____BAH_COMPILER_VAR_1514[0] = "\030\0\0\0""Cannot use var {TOKEN} (";char * ____BAH_COMPILER_VAR_1515 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1514, 5);throwErr(&varTok,____BAH_COMPILER_VAR_1515);
}
}

#line 3371 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1516 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1516[3] = "\01\0\0\0"";";____BAH_COMPILER_VAR_1516[2] = valTok.cont;____BAH_COMPILER_VAR_1516[1] = "\03\0\0\0"" = ";____BAH_COMPILER_VAR_1516[0] = v->name;char * ____BAH_COMPILER_VAR_1517 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1516, 4);char** ____BAH_COMPILER_VAR_1518 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1518[1] = ____BAH_COMPILER_VAR_1517;____BAH_COMPILER_VAR_1518[0] = code;char * ____BAH_COMPILER_VAR_1519 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1518, 2);code = ____BAH_COMPILER_VAR_1519;

#line 3373 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((isThen==true)) {

#line 3374 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1520 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1520[2] = "\013\0\0\0"" != null) {";____BAH_COMPILER_VAR_1520[1] = v->name;____BAH_COMPILER_VAR_1520[0] = "\04\0\0\0""if (";char * ____BAH_COMPILER_VAR_1521 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1520, 3);char** ____BAH_COMPILER_VAR_1522 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1522[1] = ____BAH_COMPILER_VAR_1521;____BAH_COMPILER_VAR_1522[0] = code;char * ____BAH_COMPILER_VAR_1523 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1522, 2);code = ____BAH_COMPILER_VAR_1523;
}

#line 3375 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 3376 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1524 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1524[2] = "\013\0\0\0"" == null) {";____BAH_COMPILER_VAR_1524[1] = v->name;____BAH_COMPILER_VAR_1524[0] = "\04\0\0\0""if (";char * ____BAH_COMPILER_VAR_1525 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1524, 3);char** ____BAH_COMPILER_VAR_1526 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1526[1] = ____BAH_COMPILER_VAR_1525;____BAH_COMPILER_VAR_1526[0] = code;char * ____BAH_COMPILER_VAR_1527 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1526, 2);code = ____BAH_COMPILER_VAR_1527;
}

#line 3379 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope__add(OUTPUT, rope(code));

#line 3381 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct Tok)* tokens = arraySubstitute(line, 6, len(line)-1);

#line 3383 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Elems* CaptElems = dupElems(elems);

#line 3385 "/home/alois/Documents/bah-bah/src/parser.bah"
parseLines(tokens,CaptElems);

#line 3387 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((isThen==true)) {

#line 3388 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope__add(OUTPUT, rope("\02\0\0\0""}\n"));
}

#line 3389 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 3390 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1528 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1528[4] = "\05\0\0\0""\");}\n";____BAH_COMPILER_VAR_1528[3] = intToStr(line->data[0].line);____BAH_COMPILER_VAR_1528[2] = "\01\0\0\0"":";____BAH_COMPILER_VAR_1528[1] = compilerState.currentFile;____BAH_COMPILER_VAR_1528[0] = "\057\0\0\0""\n__BAH_panic(\"Undefined capture resolution.\", \"";char * ____BAH_COMPILER_VAR_1529 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1528, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1529));
}
};

#line 3396 "/home/alois/Documents/bah-bah/src/parser.bah"
void parseLine(__BAH_ARR_TYPE_Tok line,struct Elems* elems){

#line 3398 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((len(line)==0)) {

#line 3399 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}

#line 3402 "/home/alois/Documents/bah-bah/src/parser.bah"
clear(currChecks);

#line 3404 "/home/alois/Documents/bah-bah/src/parser.bah"
line = parsePointers(line,elems);

#line 3405 "/home/alois/Documents/bah-bah/src/parser.bah"
lineType ltp = getLineType(line);

#line 3407 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.RCPvars = memoryAlloc(sizeof(array(struct variable*)));

compilerState.RCPvars->length = 0;
compilerState.RCPvars->elemSize = sizeof(struct variable*);

#line 3408 "/home/alois/Documents/bah-bah/src/parser.bah"
currSetVar = null;

#line 3410 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((ltp==LINE_TYPE_VAR)&&(len(line)>1)) {

#line 3411 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok ft = line->data[0];

#line 3412 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok st = line->data[1];

#line 3413 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(st.cont, "\01\0\0\0""=") == 0)) {

#line 3414 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* v = searchVar(ft.cont,elems);

#line 3415 "/home/alois/Documents/bah-bah/src/parser.bah"
currSetVar = v;
}
}

#line 3420 "/home/alois/Documents/bah-bah/src/parser.bah"
char parsed = false;

#line 3421 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((ltp==LINE_TYPE_INCLUDE)) {

#line 3422 "/home/alois/Documents/bah-bah/src/parser.bah"
parsed = true;

#line 3423 "/home/alois/Documents/bah-bah/src/parser.bah"
parseInclude(line,elems);
}

#line 3424 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((ltp==LINE_TYPE_IMPORT)) {

#line 3425 "/home/alois/Documents/bah-bah/src/parser.bah"
parsed = true;

#line 3426 "/home/alois/Documents/bah-bah/src/parser.bah"
parseImport(line,elems);
}

#line 3427 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((ltp==LINE_TYPE_DEFINE)) {

#line 3428 "/home/alois/Documents/bah-bah/src/parser.bah"
parsed = true;

#line 3429 "/home/alois/Documents/bah-bah/src/parser.bah"
parseDefine(line,elems);
}

#line 3430 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((ltp==LINE_TYPE_CLIB)) {

#line 3431 "/home/alois/Documents/bah-bah/src/parser.bah"
parsed = true;

#line 3432 "/home/alois/Documents/bah-bah/src/parser.bah"
parseClib(line);
}

#line 3433 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((ltp==LINE_TYPE_PRE_KEYWORD)) {

#line 3434 "/home/alois/Documents/bah-bah/src/parser.bah"
parsePreKeyword(line,elems);

#line 3435 "/home/alois/Documents/bah-bah/src/parser.bah"
parsed = true;
}

#line 3436 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 3437 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1530 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1530[4] = "\02\0\0\0""\"\n";____BAH_COMPILER_VAR_1530[3] = compilerState.currentFile;____BAH_COMPILER_VAR_1530[2] = "\02\0\0\0"" \"";____BAH_COMPILER_VAR_1530[1] = intToStr(line->data[0].line);____BAH_COMPILER_VAR_1530[0] = "\07\0\0\0""\n#line ";char * ____BAH_COMPILER_VAR_1531 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1530, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1531));

#line 3438 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((ltp==LINE_TYPE_STRUCT)) {

#line 3439 "/home/alois/Documents/bah-bah/src/parser.bah"
parsed = true;

#line 3440 "/home/alois/Documents/bah-bah/src/parser.bah"
parseStruct(line,elems);
}

#line 3441 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((ltp==LINE_TYPE_CONST)) {

#line 3442 "/home/alois/Documents/bah-bah/src/parser.bah"
parsed = true;

#line 3443 "/home/alois/Documents/bah-bah/src/parser.bah"
parseConst(line,elems);
}

#line 3444 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((ltp==LINE_TYPE_MACRO)) {

#line 3445 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}

#line 3446 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((ltp!=LINE_TYPE_FN_DECL)) {

#line 3447 "/home/alois/Documents/bah-bah/src/parser.bah"
line = prePross(line,ltp,elems);

#line 3448 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((len(line)==0)) {

#line 3449 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}
}

#line 3453 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok ft = line->data[0];

#line 3454 "/home/alois/Documents/bah-bah/src/parser.bah"
if (RCPavailable()&&(ft.isOper==false)&&(ft.isFunc==true)) {

#line 3455 "/home/alois/Documents/bah-bah/src/parser.bah"
struct func* fn = searchFuncByToken(&ft,elems);

#line 3456 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((fn!=null)&&(fn->returns!=null)&&isRCPtype(fn->returns->type,elems)) {

#line 3457 "/home/alois/Documents/bah-bah/src/parser.bah"
registerRCPvar(fn->returns->type,ft.cont,elems);

#line 3458 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}
}

#line 3462 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((ltp==LINE_TYPE_VAR)) {

#line 3463 "/home/alois/Documents/bah-bah/src/parser.bah"
parsed = true;

#line 3464 "/home/alois/Documents/bah-bah/src/parser.bah"
parseVar(line,elems);
}

#line 3465 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((ltp==LINE_TYPE_FN_CALL)) {

#line 3466 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((len(line)>1), 0)) {

#line 3467 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&line->data[len(line)-1],"\052\0\0\0""Not expecting {TOKEN} after function call.");
}

#line 3469 "/home/alois/Documents/bah-bah/src/parser.bah"
parsed = true;

#line 3470 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1532 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1532[1] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_1532[0] = ft.cont;char * ____BAH_COMPILER_VAR_1533 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1532, 2);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1533));
}

#line 3471 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((ltp==LINE_TYPE_FN_DECL)) {

#line 3472 "/home/alois/Documents/bah-bah/src/parser.bah"
parsed = true;

#line 3473 "/home/alois/Documents/bah-bah/src/parser.bah"
parseFnDeclare(line,elems);
}

#line 3474 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((ltp==LINE_TYPE_RETURN)) {

#line 3475 "/home/alois/Documents/bah-bah/src/parser.bah"
parsed = true;

#line 3476 "/home/alois/Documents/bah-bah/src/parser.bah"
parseReturn(line,elems);
}

#line 3477 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((ltp==LINE_TYPE_IF)) {

#line 3478 "/home/alois/Documents/bah-bah/src/parser.bah"
parsed = true;

#line 3479 "/home/alois/Documents/bah-bah/src/parser.bah"
parseIf(line,false,elems);
}

#line 3480 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((ltp==LINE_TYPE_ELSE)) {

#line 3481 "/home/alois/Documents/bah-bah/src/parser.bah"
parsed = true;

#line 3482 "/home/alois/Documents/bah-bah/src/parser.bah"
parseElse(line,elems);
}

#line 3483 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((ltp==LINE_TYPE_FOR)) {

#line 3484 "/home/alois/Documents/bah-bah/src/parser.bah"
parsed = true;

#line 3485 "/home/alois/Documents/bah-bah/src/parser.bah"
parseFor(line,elems);
}

#line 3486 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((ltp==LINE_TYPE_FOR_OPERATOR)) {

#line 3487 "/home/alois/Documents/bah-bah/src/parser.bah"
parsed = true;

#line 3488 "/home/alois/Documents/bah-bah/src/parser.bah"
parseForOp(line,elems);
}

#line 3489 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((ltp==LINE_TYPE_ASYNC)) {

#line 3490 "/home/alois/Documents/bah-bah/src/parser.bah"
parseAsync(line,elems);

#line 3491 "/home/alois/Documents/bah-bah/src/parser.bah"
parsed = true;
}

#line 3492 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((ltp==LINE_TYPE_CAPTURE)) {

#line 3493 "/home/alois/Documents/bah-bah/src/parser.bah"
parseCapture(line,elems);

#line 3494 "/home/alois/Documents/bah-bah/src/parser.bah"
parsed = true;
}
}

#line 3498 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((parsed==false), 0)) {

#line 3499 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&line->data[0],"\025\0\0\0""{TOKEN} not expected.");
}

#line 3502 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strlen(NEXT_LINE)>0)) {

#line 3503 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope__add(OUTPUT, rope(NEXT_LINE));

#line 3504 "/home/alois/Documents/bah-bah/src/parser.bah"
NEXT_LINE = "\0\0\0\0""";
}

#line 3506 "/home/alois/Documents/bah-bah/src/parser.bah"
prevLine = ltp;
};

#line 3511 "/home/alois/Documents/bah-bah/src/parser.bah"
void parseLines(__BAH_ARR_TYPE_Tok tokens,struct Elems* elems){

#line 3513 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((len(tokens)==0)) {

#line 3514 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}

#line 3516 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct Tok)* line = memoryAlloc(sizeof(array(struct Tok)));

line->length = 0;
line->elemSize = sizeof(struct Tok);

#line 3517 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok ft = tokens->data[0];

#line 3518 "/home/alois/Documents/bah-bah/src/parser.bah"
unsigned int currentLine = ft.line;

#line 3519 "/home/alois/Documents/bah-bah/src/parser.bah"
long int nbEncl = 0;

#line 3520 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int i = 0;

#line 3520 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i<len(tokens))) {

#line 3521 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = tokens->data[i];

#line 3523 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((t.type==TOKEN_TYPE_ENCL)) {

#line 3524 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "\01\0\0\0""(") == 0)) {

#line 3525 "/home/alois/Documents/bah-bah/src/parser.bah"
nbEncl = nbEncl+1;
}

#line 3526 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(t.cont, "\01\0\0\0"")") == 0)) {

#line 3527 "/home/alois/Documents/bah-bah/src/parser.bah"
nbEncl = nbEncl-1;
}

#line 3528 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(t.cont, "\01\0\0\0""{") == 0)) {

#line 3529 "/home/alois/Documents/bah-bah/src/parser.bah"
nbEncl = nbEncl+1;
}

#line 3530 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(t.cont, "\01\0\0\0""}") == 0)) {

#line 3531 "/home/alois/Documents/bah-bah/src/parser.bah"
nbEncl = nbEncl-1;
}

#line 3532 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(t.cont, "\01\0\0\0""[") == 0)) {

#line 3533 "/home/alois/Documents/bah-bah/src/parser.bah"
nbEncl = nbEncl+1;
}

#line 3534 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(t.cont, "\01\0\0\0""]") == 0)) {

#line 3535 "/home/alois/Documents/bah-bah/src/parser.bah"
nbEncl = nbEncl-1;
}
}

#line 3539 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((t.type==TOKEN_TYPE_STR)&&(t.begLine==currentLine)) {

#line 3540 "/home/alois/Documents/bah-bah/src/parser.bah"
currentLine = t.line;
}

#line 3543 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((nbEncl==0)) {

#line 3544 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((t.line!=currentLine)) {

#line 3545 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((t.type==TOKEN_TYPE_ENCL)) {

#line 3546 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1534 = len(line);
    __Bah_realocate_arr(line, ____BAH_COMPILER_VAR_1534);
    line->data[____BAH_COMPILER_VAR_1534] = t;

#line 3547 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok pt = tokens->data[i-1];

#line 3548 "/home/alois/Documents/bah-bah/src/parser.bah"
currentLine = pt.line;
}

#line 3549 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 3550 "/home/alois/Documents/bah-bah/src/parser.bah"
currentLine = t.line;
}

#line 3552 "/home/alois/Documents/bah-bah/src/parser.bah"
parseLine(line,elems);

#line 3553 "/home/alois/Documents/bah-bah/src/parser.bah"
clear(line);

#line 3554 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((t.type==TOKEN_TYPE_ENCL)) {

#line 3555 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 3556 "/home/alois/Documents/bah-bah/src/parser.bah"
continue;
}
}

#line 3558 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(t.cont, "\01\0\0\0"";") == 0)) {

#line 3559 "/home/alois/Documents/bah-bah/src/parser.bah"
currentLine = t.line;

#line 3560 "/home/alois/Documents/bah-bah/src/parser.bah"
parseLine(line,elems);

#line 3561 "/home/alois/Documents/bah-bah/src/parser.bah"
clear(line);

#line 3562 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 3563 "/home/alois/Documents/bah-bah/src/parser.bah"
continue;
}
}

#line 3567 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1535 = len(line);
    __Bah_realocate_arr(line, ____BAH_COMPILER_VAR_1535);
    line->data[____BAH_COMPILER_VAR_1535] = t;

#line 3568 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;
};

#line 3571 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((len(line)>0)) {

#line 3572 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((nbEncl==0)) {

#line 3573 "/home/alois/Documents/bah-bah/src/parser.bah"
parseLine(line,elems);

#line 3574 "/home/alois/Documents/bah-bah/src/parser.bah"
clear(line);
}

#line 3575 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 3576 "/home/alois/Documents/bah-bah/src/parser.bah"
ft = line->data[len(line)-1];

#line 3577 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&ft,"\056\0\0\0""Missing closing token, line ending by {TOKEN}.");
}
}
};

#line 2 "/home/alois/Documents/bah-bah/src/declarative.bah"
void declareFunc(struct func* fn,struct Elems* elems){

#line 3 "/home/alois/Documents/bah-bah/src/declarative.bah"
struct string tmpfnRetCType = getCType(fn->returns->type,elems);

#line 4 "/home/alois/Documents/bah-bah/src/declarative.bah"
char * tmpfnArgsCType = "\0\0\0\0""";

#line 5 "/home/alois/Documents/bah-bah/src/declarative.bah"
register long int j = 0;

#line 5 "/home/alois/Documents/bah-bah/src/declarative.bah"
while ((j<len(fn->args))) {

#line 6 "/home/alois/Documents/bah-bah/src/declarative.bah"
struct variable* arg = fn->args->data[j];

#line 7 "/home/alois/Documents/bah-bah/src/declarative.bah"
struct string ct = getCType(arg->type,elems);

#line 8 "/home/alois/Documents/bah-bah/src/declarative.bah"
char** ____BAH_COMPILER_VAR_1536 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1536[3] = arg->name;____BAH_COMPILER_VAR_1536[2] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_1536[1] = string__str(&ct);____BAH_COMPILER_VAR_1536[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_1537 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1536, 4);tmpfnArgsCType = ____BAH_COMPILER_VAR_1537;

#line 9 "/home/alois/Documents/bah-bah/src/declarative.bah"
j = j+1;

#line 10 "/home/alois/Documents/bah-bah/src/declarative.bah"
if ((j<len(fn->args))) {

#line 11 "/home/alois/Documents/bah-bah/src/declarative.bah"
char** ____BAH_COMPILER_VAR_1538 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1538[1] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_1538[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_1539 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1538, 2);tmpfnArgsCType = ____BAH_COMPILER_VAR_1539;
}
};

#line 15 "/home/alois/Documents/bah-bah/src/declarative.bah"
char** ____BAH_COMPILER_VAR_1540 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_1540[5] = "\03\0\0\0"");\n";____BAH_COMPILER_VAR_1540[4] = tmpfnArgsCType;____BAH_COMPILER_VAR_1540[3] = "\01\0\0\0""(";____BAH_COMPILER_VAR_1540[2] = fn->name;____BAH_COMPILER_VAR_1540[1] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_1540[0] = string__str(&tmpfnRetCType);char * ____BAH_COMPILER_VAR_1541 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1540, 6);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1541));
};

#line 18 "/home/alois/Documents/bah-bah/src/declarative.bah"
void declareVar(struct variable* v,struct Elems* elems){

#line 19 "/home/alois/Documents/bah-bah/src/declarative.bah"
if ((v->isConst==true)) {

#line 20 "/home/alois/Documents/bah-bah/src/declarative.bah"
char** ____BAH_COMPILER_VAR_1542 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1542[4] = "\01\0\0\0""\n";____BAH_COMPILER_VAR_1542[3] = v->constVal;____BAH_COMPILER_VAR_1542[2] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_1542[1] = v->name;____BAH_COMPILER_VAR_1542[0] = "\010\0\0\0""#define ";char * ____BAH_COMPILER_VAR_1543 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1542, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1543));
}

#line 21 "/home/alois/Documents/bah-bah/src/declarative.bah"
else {

#line 22 "/home/alois/Documents/bah-bah/src/declarative.bah"
struct string cType = getCType(v->type,elems);

#line 23 "/home/alois/Documents/bah-bah/src/declarative.bah"
char** ____BAH_COMPILER_VAR_1544 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1544[3] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_1544[2] = v->name;____BAH_COMPILER_VAR_1544[1] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_1544[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_1545 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1544, 4);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1545));
}
};

#line 27 "/home/alois/Documents/bah-bah/src/declarative.bah"
void declareAll(struct Elems* elems){

#line 29 "/home/alois/Documents/bah-bah/src/declarative.bah"
OUTPUT = rope("\302\0\0\0""\n#define noCheck(v) v\n#define array(type)	\
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
char** ____BAH_COMPILER_VAR_1546 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1546[2] = "\01\0\0\0""\n";____BAH_COMPILER_VAR_1546[1] = compilerState.cIncludes->data[i];____BAH_COMPILER_VAR_1546[0] = "\011\0\0\0""#include ";char * ____BAH_COMPILER_VAR_1547 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1546, 3);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1547));
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
struct string elemCtype = getCType(string__str(&elemType),elems);

#line 50 "/home/alois/Documents/bah-bah/src/declarative.bah"
char** ____BAH_COMPILER_VAR_1548 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1548[4] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_1548[3] = t;____BAH_COMPILER_VAR_1548[2] = "\03\0\0\0"")* ";____BAH_COMPILER_VAR_1548[1] = string__str(&elemCtype);____BAH_COMPILER_VAR_1548[0] = "\016\0\0\0""typedef array(";char * ____BAH_COMPILER_VAR_1549 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1548, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1549));
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

#line 52 "/home/alois/Documents/bah-bah/src/main.bah"
char * memErrHandle(){

#line 53 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1550 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1550[1] = compilerState.currentFile;____BAH_COMPILER_VAR_1550[0] = "\06\0\0\0""file: ";char * ____BAH_COMPILER_VAR_1551 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1550, 2);char * r = ____BAH_COMPILER_VAR_1551;

#line 54 "/home/alois/Documents/bah-bah/src/main.bah"
if ((currentFn!=null)) {

#line 55 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1552 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1552[2] = "\02\0\0\0""()";____BAH_COMPILER_VAR_1552[1] = currentFn->name;____BAH_COMPILER_VAR_1552[0] = "\013\0\0\0""\nfunction: ";char * ____BAH_COMPILER_VAR_1553 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1552, 3);char** ____BAH_COMPILER_VAR_1554 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1554[1] = ____BAH_COMPILER_VAR_1553;____BAH_COMPILER_VAR_1554[0] = r;char * ____BAH_COMPILER_VAR_1555 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1554, 2);r = ____BAH_COMPILER_VAR_1555;
}

#line 57 "/home/alois/Documents/bah-bah/src/main.bah"
return r;
};

#line 60 "/home/alois/Documents/bah-bah/src/main.bah"
long int main(__BAH_ARR_TYPE_cpstring args){

#line 63 "/home/alois/Documents/bah-bah/src/main.bah"
onMemoryError = memErrHandle;

#line 65 "/home/alois/Documents/bah-bah/src/main.bah"
execName = args->data[0];

#line 67 "/home/alois/Documents/bah-bah/src/main.bah"
if ((execName[0+4]==46)||(execName[0+4]==47)) {

#line 68 "/home/alois/Documents/bah-bah/src/main.bah"
execName = absPath(execName);
}

#line 71 "/home/alois/Documents/bah-bah/src/main.bah"
struct flags ____BAH_COMPILER_VAR_1556 = {};
____BAH_COMPILER_VAR_1556.flags = memoryAlloc(sizeof(array(struct flag*)));
            ____BAH_COMPILER_VAR_1556.flags->length = 0;
            ____BAH_COMPILER_VAR_1556.flags->elemSize = sizeof(struct flag*);
            ____BAH_COMPILER_VAR_1556.args = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_1556.args->length = 0;
            ____BAH_COMPILER_VAR_1556.args->elemSize = sizeof(char *);
            flags = ____BAH_COMPILER_VAR_1556;

#line 72 "/home/alois/Documents/bah-bah/src/main.bah"
flags__addString(&flags,"\01\0\0\0""o","\033\0\0\0""Name of the file to output.");

#line 73 "/home/alois/Documents/bah-bah/src/main.bah"
flags__addBool(&flags,"\01\0\0\0""c","\060\0\0\0""Translate bah file to C instead of compiling it.");

#line 74 "/home/alois/Documents/bah-bah/src/main.bah"
flags__addBool(&flags,"\01\0\0\0""v","\035\0\0\0""Show version of the compiler.");

#line 75 "/home/alois/Documents/bah-bah/src/main.bah"
flags__addBool(&flags,"\01\0\0\0""l","\025\0\0\0""Compile as a library.");

#line 80 "/home/alois/Documents/bah-bah/src/main.bah"
flags__addBool(&flags,"\01\0\0\0""d","\200\0\0\0""Compile as a dynamic executable. (useful if you are using a library that is only available shared but might reduce portability).");

#line 82 "/home/alois/Documents/bah-bah/src/main.bah"
flags__addBool(&flags,"\03\0\0\0""rcp","\213\0\0\0""Enables RCP (reference counter) instead of the garbage collector. Warning: if you are using self-reference, this will lead to memory leaks!");

#line 83 "/home/alois/Documents/bah-bah/src/main.bah"
flags__addBool(&flags,"\07\0\0\0""fastrcp","\220\0\0\0""Enables RCP without leak detection. It is recommended to test you programs with the -rcp flag to test for leak detection before using this flag.");

#line 84 "/home/alois/Documents/bah-bah/src/main.bah"
flags__addBool(&flags,"\05\0\0\0""debug","\034\0\0\0""Enables verbose json output.");

#line 85 "/home/alois/Documents/bah-bah/src/main.bah"
flags__addBool(&flags,"\016\0\0\0""verboseRuntime","\111\0\0\0""Enables verbose runtime, a debug mode of the compiled program. (obsolete)");

#line 86 "/home/alois/Documents/bah-bah/src/main.bah"
flags__addBool(&flags,"\011\0\0\0""verboseCC","\066\0\0\0""Enables verbose C compiler output, USE IN LAST RESORT.");

#line 89 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1557 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1557[2] = "\01\0\0\0"".";____BAH_COMPILER_VAR_1557[1] = BAH_OS;____BAH_COMPILER_VAR_1557[0] = "\115\0\0\0""Select the target OS for cross compilling (linux, windows, darwin), default: ";char * ____BAH_COMPILER_VAR_1558 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1557, 3);flags__addString(&flags,"\06\0\0\0""target",____BAH_COMPILER_VAR_1558);

#line 90 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1559 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1559[2] = "\02\0\0\0"").";____BAH_COMPILER_VAR_1559[1] = BAH_DIR;____BAH_COMPILER_VAR_1559[0] = "\056\0\0\0""If your Bah directory is not the default one (";char * ____BAH_COMPILER_VAR_1560 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1559, 3);flags__addString(&flags,"\06\0\0\0""bahDir",____BAH_COMPILER_VAR_1560);

#line 91 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1561 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1561[2] = "\01\0\0\0"".";____BAH_COMPILER_VAR_1561[1] = BAH_CC;____BAH_COMPILER_VAR_1561[0] = "\050\0\0\0""To change the C compiler used, default: ";char * ____BAH_COMPILER_VAR_1562 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1561, 3);flags__addString(&flags,"\02\0\0\0""CC",____BAH_COMPILER_VAR_1562);

#line 92 "/home/alois/Documents/bah-bah/src/main.bah"
flags__addBool(&flags,"\06\0\0\0""object","\025\0\0\0""Compile as an object.");

#line 93 "/home/alois/Documents/bah-bah/src/main.bah"
flags__addBool(&flags,"\06\0\0\0""unsafe","\202\0\0\0""Compile without safety checking. This will make for faster executable but if your program crashes, it will show less informations.");

#line 94 "/home/alois/Documents/bah-bah/src/main.bah"
flags__addBool(&flags,"\011\0\0\0""nobuiltin","\123\0\0\0""Does not include the builtin library (be really carefull, your program WILL break).");

#line 95 "/home/alois/Documents/bah-bah/src/main.bah"
flags__addBool(&flags,"\010\0\0\0""optimize","\034\0\0\0""Includes optimized functions");

#line 96 "/home/alois/Documents/bah-bah/src/main.bah"
flags__addBool(&flags,"\01\0\0\0""n","\060\0\0\0""Disables notices while keeping warnings enabled.");

#line 97 "/home/alois/Documents/bah-bah/src/main.bah"
flags__addBool(&flags,"\04\0\0\0""raii","\037\0\0\0""Enables RAII memory management.");

#line 98 "/home/alois/Documents/bah-bah/src/main.bah"
flags__addBool(&flags,"\05\0\0\0""fixMe","\221\0\0\0""Enables runtime debugging engine, useful for segfaults... Note that your program will be slower and use more memory, this is only a debug option.");

#line 99 "/home/alois/Documents/bah-bah/src/main.bah"
flags__parse(&flags,args);

#line 101 "/home/alois/Documents/bah-bah/src/main.bah"
RAIIenabled = (flags__isSet(&flags,"\04\0\0\0""raii")==1);

#line 102 "/home/alois/Documents/bah-bah/src/main.bah"
isFixMeEnabled = (flags__isSet(&flags,"\05\0\0\0""fixMe")==1);

#line 104 "/home/alois/Documents/bah-bah/src/main.bah"
if ((RAIIenabled==true)) {

#line 105 "/home/alois/Documents/bah-bah/src/main.bah"
println("\034\0\0\0""RAII is not yet available...");

#line 106 "/home/alois/Documents/bah-bah/src/main.bah"
return 1;
}

#line 109 "/home/alois/Documents/bah-bah/src/main.bah"
if ((flags__isSet(&flags,"\06\0\0\0""target")==1)) {

#line 110 "/home/alois/Documents/bah-bah/src/main.bah"
BAH_OS = flags__get(&flags,"\06\0\0\0""target");

#line 111 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1563 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1563[1] = BAH_OS;____BAH_COMPILER_VAR_1563[0] = "\016\0\0\0""Build target: ";char * ____BAH_COMPILER_VAR_1564 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1563, 2);println(____BAH_COMPILER_VAR_1564);
}

#line 113 "/home/alois/Documents/bah-bah/src/main.bah"
if ((flags__isSet(&flags,"\06\0\0\0""bahDir")==1)) {

#line 114 "/home/alois/Documents/bah-bah/src/main.bah"
BAH_DIR = flags__get(&flags,"\06\0\0\0""bahDir");

#line 115 "/home/alois/Documents/bah-bah/src/main.bah"
if ((BAH_DIR[strlen(BAH_DIR)-1+4]!=47)) {

#line 116 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1565 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1565[1] = "\01\0\0\0""/";____BAH_COMPILER_VAR_1565[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_1566 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1565, 2);BAH_DIR = ____BAH_COMPILER_VAR_1566;
}

#line 118 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1567 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1567[1] = BAH_DIR;____BAH_COMPILER_VAR_1567[0] = "\017\0\0\0""Bah directory: ";char * ____BAH_COMPILER_VAR_1568 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1567, 2);println(____BAH_COMPILER_VAR_1568);
}

#line 120 "/home/alois/Documents/bah-bah/src/main.bah"
if ((flags__isSet(&flags,"\02\0\0\0""CC")==1)) {

#line 121 "/home/alois/Documents/bah-bah/src/main.bah"
BAH_CC = flags__get(&flags,"\02\0\0\0""CC");

#line 122 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1569 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1569[1] = BAH_CC;____BAH_COMPILER_VAR_1569[0] = "\014\0\0\0""C compiler: ";char * ____BAH_COMPILER_VAR_1570 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1569, 2);println(____BAH_COMPILER_VAR_1570);
}

#line 125 "/home/alois/Documents/bah-bah/src/main.bah"
if (__builtin_expect(flags__isSet(&flags,"\016\0\0\0""verboseRuntime"), 0)) {

#line 126 "/home/alois/Documents/bah-bah/src/main.bah"
println("\034\0\0\0""-verboseRuntime is obsolete.");

#line 127 "/home/alois/Documents/bah-bah/src/main.bah"
exit(1);
}

#line 130 "/home/alois/Documents/bah-bah/src/main.bah"
noticeEnabled = (flags__isSet(&flags,"\01\0\0\0""n")==0);

#line 132 "/home/alois/Documents/bah-bah/src/main.bah"
RCPlevel = 0;

#line 133 "/home/alois/Documents/bah-bah/src/main.bah"
if (flags__isSet(&flags,"\03\0\0\0""rcp")) {

#line 134 "/home/alois/Documents/bah-bah/src/main.bah"
RCPlevel = 1;
}

#line 135 "/home/alois/Documents/bah-bah/src/main.bah"
else if (flags__isSet(&flags,"\07\0\0\0""fastrcp")) {

#line 136 "/home/alois/Documents/bah-bah/src/main.bah"
RCPlevel = 2;
}

#line 139 "/home/alois/Documents/bah-bah/src/main.bah"
verboseRuntime = (flags__isSet(&flags,"\016\0\0\0""verboseRuntime")==1);

#line 140 "/home/alois/Documents/bah-bah/src/main.bah"
debug = (flags__isSet(&flags,"\05\0\0\0""debug")==1);

#line 141 "/home/alois/Documents/bah-bah/src/main.bah"
isObject = (flags__isSet(&flags,"\06\0\0\0""object")==1);

#line 142 "/home/alois/Documents/bah-bah/src/main.bah"
isUnsafe = (flags__isSet(&flags,"\06\0\0\0""unsafe")==1);

#line 143 "/home/alois/Documents/bah-bah/src/main.bah"
isOptimized = (flags__isSet(&flags,"\010\0\0\0""optimize")==1);

#line 145 "/home/alois/Documents/bah-bah/src/main.bah"
if ((debug==true)) {

#line 146 "/home/alois/Documents/bah-bah/src/main.bah"
debugStart();
}

#line 149 "/home/alois/Documents/bah-bah/src/main.bah"
RCPenabled = (flags__isSet(&flags,"\03\0\0\0""rcp")==1)||flags__isSet(&flags,"\07\0\0\0""fastrcp");

#line 151 "/home/alois/Documents/bah-bah/src/main.bah"
if ((flags__isSet(&flags,"\01\0\0\0""v")==1)) {

#line 152 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1571 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1571[2] = "\026\0\0\0"".\n© Alois Laurent Boe";____BAH_COMPILER_VAR_1571[1] = BAH_VERSION;____BAH_COMPILER_VAR_1571[0] = "\026\0\0\0""Bah compiler version: ";char * ____BAH_COMPILER_VAR_1572 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1571, 3);println(____BAH_COMPILER_VAR_1572);

#line 153 "/home/alois/Documents/bah-bah/src/main.bah"
return 0;
}

#line 156 "/home/alois/Documents/bah-bah/src/main.bah"
if (__builtin_expect((flags__isSet(&flags,"\01\0\0\0""c")==1)&&(flags__isSet(&flags,"\01\0\0\0""l")==1), 0)) {

#line 157 "/home/alois/Documents/bah-bah/src/main.bah"
__BAH_panic("\131\0\0\0""Cannot use -c (to translate to C code) and -l (to compile as a library) at the same time.","\056\0\0\0""/home/alois/Documents/bah-bah/src/main.bah:157");
}

#line 160 "/home/alois/Documents/bah-bah/src/main.bah"
INIT = rope("\0\0\0\0""");

#line 163 "/home/alois/Documents/bah-bah/src/main.bah"
OUTPUT = rope("\065\01\0\0""\n    void __BAH_init();\n    #define noCheck(v) v\n    #define array(type)	\
    struct{	\
    type *data; \
    unsigned long int length; \
    unsigned long int realLength; \
    unsigned long int elemSize; \
    }\n    typedef array(char*)* __BAH_ARR_TYPE_cpstring;\n    long int __BAH__main(__BAH_ARR_TYPE_cpstring);\n    ");

#line 177 "/home/alois/Documents/bah-bah/src/main.bah"
if ((flags__isSet(&flags,"\01\0\0\0""l")==0)) {

#line 178 "/home/alois/Documents/bah-bah/src/main.bah"
if ((RCPenabled==true)) {

#line 179 "/home/alois/Documents/bah-bah/src/main.bah"
OUTPUT = rope__add(OUTPUT, rope("\316\02\0\0""\n            void RCP_init();\n            void RCP_shutdown();\n            void free(void*);\n            #include <string.h>\n            int main(int argc, char ** argv) {\n            RCP_init();\n            array(char*) * args = malloc(sizeof(array(char*)));\n            args->data = malloc(sizeof(char*)*argc);\n            memcpy(args->data, argv, sizeof(char*)*argc);\n            args->elemSize = sizeof(char*);\n            args->length = argc;\n            __BAH_init();\n            long int r =  __BAH__main((__BAH_ARR_TYPE_cpstring)args);\n            free(args->data);\n            free(args);\n            RCP_shutdown();\n            return r;\n            };\n            #define main(v) __BAH__main(v)\n            "));
}

#line 201 "/home/alois/Documents/bah-bah/src/main.bah"
else if ((RAIIenabled==true)) {

#line 202 "/home/alois/Documents/bah-bah/src/main.bah"
OUTPUT = rope__add(OUTPUT, rope("\076\02\0\0""\n            #include <string.h>\n            int main(int argc, char ** argv) {\n            array(char*) * args = malloc(sizeof(array(char*)));\n            args->data = malloc(sizeof(char*)*argc);\n            memcpy(args->data, argv, sizeof(char*)*argc);\n            args->elemSize = sizeof(char*);\n            args->length = argc;\n            __BAH_init();\n            long int r =  __BAH__main((__BAH_ARR_TYPE_cpstring)args);\n            free(args->data);\n            free(args);\n            return r;\n            };\n            #define main(v) __BAH__main(v)\n            "));
}

#line 218 "/home/alois/Documents/bah-bah/src/main.bah"
else {

#line 219 "/home/alois/Documents/bah-bah/src/main.bah"
OUTPUT = rope__add(OUTPUT, rope("\173\01\0\0""\n            #include <gc.h>\n            #include <string.h>\n            __BAH_ARR_TYPE_cpstring argsToArr(char** a,long int l);\n            int main(int argc, char ** argv) {\n            GC_INIT();\n            __BAH_init();\n            long int r =  __BAH__main(argsToArr(argv, argc));\n            return r;\n            };\n            #define main(v) __BAH__main(v)\n            "));
}
}

#line 235 "/home/alois/Documents/bah-bah/src/main.bah"
struct compilerStateTag ____BAH_COMPILER_VAR_1573 = {};
____BAH_COMPILER_VAR_1573.includes = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_1573.includes->length = 0;
            ____BAH_COMPILER_VAR_1573.includes->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_1573.cIncludes = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_1573.cIncludes->length = 0;
            ____BAH_COMPILER_VAR_1573.cIncludes->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_1573.cLibs = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_1573.cLibs->length = 0;
            ____BAH_COMPILER_VAR_1573.cLibs->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_1573.currentDir = "\02\0\0\0""./";
____BAH_COMPILER_VAR_1573.arrTypesDecl = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_1573.arrTypesDecl->length = 0;
            ____BAH_COMPILER_VAR_1573.arrTypesDecl->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_1573.RCPvars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_1573.RCPvars->length = 0;
            ____BAH_COMPILER_VAR_1573.RCPvars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_1573.evals = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_1573.evals->length = 0;
            ____BAH_COMPILER_VAR_1573.evals->elemSize = sizeof(char *);
            compilerState = ____BAH_COMPILER_VAR_1573;

#line 236 "/home/alois/Documents/bah-bah/src/main.bah"

    unsigned int ____BAH_COMPILER_VAR_1574 = 0;
    __Bah_realocate_arr(compilerState.arrTypesDecl, ____BAH_COMPILER_VAR_1574);
    compilerState.arrTypesDecl->data[____BAH_COMPILER_VAR_1574] = "\027\0\0\0""__BAH_ARR_TYPE_cpstring";

#line 239 "/home/alois/Documents/bah-bah/src/main.bah"
char * fileName = absPath(args->data[1]);

#line 240 "/home/alois/Documents/bah-bah/src/main.bah"
compilerState.currentFile = fileName;

#line 241 "/home/alois/Documents/bah-bah/src/main.bah"
struct fileStream ____BAH_COMPILER_VAR_1575 = {};
struct fileStream fs = ____BAH_COMPILER_VAR_1575;

#line 242 "/home/alois/Documents/bah-bah/src/main.bah"
fileStream__open(&fs,fileName,"\01\0\0\0""r");

#line 243 "/home/alois/Documents/bah-bah/src/main.bah"
char * f = fileStream__readContent(&fs);

#line 244 "/home/alois/Documents/bah-bah/src/main.bah"
if (__builtin_expect((fileStream__isValid(&fs)==0)||(fileStream__getSize(&fs)==0), 0)) {

#line 245 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1576 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1576[2] = "\02\0\0\0""'.";____BAH_COMPILER_VAR_1576[1] = args->data[1];____BAH_COMPILER_VAR_1576[0] = "\025\0\0\0""Could not open file '";char * ____BAH_COMPILER_VAR_1577 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1576, 3);println(____BAH_COMPILER_VAR_1577);

#line 246 "/home/alois/Documents/bah-bah/src/main.bah"
exit(1);
}

#line 248 "/home/alois/Documents/bah-bah/src/main.bah"
long int startTime = getTimeUnix();

#line 249 "/home/alois/Documents/bah-bah/src/main.bah"
array(struct Tok)* tokens = lexer(f,fileStream__getSize(&fs));

#line 250 "/home/alois/Documents/bah-bah/src/main.bah"
fileStream__close(&fs);

#line 253 "/home/alois/Documents/bah-bah/src/main.bah"
if (__builtin_expect((len(tokens)==0), 0)) {

#line 254 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1578 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1578[2] = "\021\0\0\0""' not recognized.";____BAH_COMPILER_VAR_1578[1] = fileName;____BAH_COMPILER_VAR_1578[0] = "\06\0\0\0""File '";char * ____BAH_COMPILER_VAR_1579 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1578, 3);println(____BAH_COMPILER_VAR_1579);

#line 255 "/home/alois/Documents/bah-bah/src/main.bah"
exit(1);
}

#line 258 "/home/alois/Documents/bah-bah/src/main.bah"
struct Elems* ____BAH_COMPILER_VAR_1580 = memoryAlloc(sizeof(struct Elems));
____BAH_COMPILER_VAR_1580->vars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_1580->vars->length = 0;
            ____BAH_COMPILER_VAR_1580->vars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_1580->structs = memoryAlloc(sizeof(array(struct cStruct*)));
            ____BAH_COMPILER_VAR_1580->structs->length = 0;
            ____BAH_COMPILER_VAR_1580->structs->elemSize = sizeof(struct cStruct*);
            ____BAH_COMPILER_VAR_1580->types = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_1580->types->length = 0;
            ____BAH_COMPILER_VAR_1580->types->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_1580->fns = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_1580->fns->length = 0;
            ____BAH_COMPILER_VAR_1580->fns->elemSize = sizeof(struct func*);
            ____BAH_COMPILER_VAR_1580->deletedVars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_1580->deletedVars->length = 0;
            ____BAH_COMPILER_VAR_1580->deletedVars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_1580->branchChecks = memoryAlloc(sizeof(array(struct varCheck)));
            ____BAH_COMPILER_VAR_1580->branchChecks->length = 0;
            ____BAH_COMPILER_VAR_1580->branchChecks->elemSize = sizeof(struct varCheck);
            struct Elems* elems = ____BAH_COMPILER_VAR_1580;

#line 261 "/home/alois/Documents/bah-bah/src/main.bah"
if ((isObject==true)) {

#line 262 "/home/alois/Documents/bah-bah/src/main.bah"
OUTPUT = rope("\057\01\0\0""\n        #define noCheck(v) v\n        #define array(type)	\
        struct{	\
        type *data; \
        long int length; \
        long int realLength; \
        long int elemSize; \
        }\n        typedef array(char*)* __BAH_ARR_TYPE_cpstring;\n        long int __BAH__main(__BAH_ARR_TYPE_cpstring);\n        ");

#line 274 "/home/alois/Documents/bah-bah/src/main.bah"
shouldOnlyDecl = true;
}

#line 278 "/home/alois/Documents/bah-bah/src/main.bah"

                struct string ____BAH_COMPILER_VAR_1581 = string(fileName);
                if ((flags__isSet(&flags,"\011\0\0\0""nobuiltin")==0)&&(string__hasSuffix(&____BAH_COMPILER_VAR_1581,"\010\0\0\0"".bahstrp")==false)) {

#line 279 "/home/alois/Documents/bah-bah/src/main.bah"
if (__builtin_expect((includeFile("\013\0\0\0""builtin.bah",elems)==false), 0)) {

#line 280 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1582 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1582[2] = "\01\0\0\0""'";____BAH_COMPILER_VAR_1582[1] = BAH_DIR;____BAH_COMPILER_VAR_1582[0] = "\047\0\0\0""Could not find std-libs, please check '";char * ____BAH_COMPILER_VAR_1583 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1582, 3);__BAH_panic(____BAH_COMPILER_VAR_1583,"\056\0\0\0""/home/alois/Documents/bah-bah/src/main.bah:280");
}
}

#line 284 "/home/alois/Documents/bah-bah/src/main.bah"
if ((isFixMeEnabled==true)) {

#line 285 "/home/alois/Documents/bah-bah/src/main.bah"
if (__builtin_expect((includeFile("\011\0\0\0""fixme.bah",elems)==false), 0)) {

#line 286 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1584 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1584[2] = "\01\0\0\0""'";____BAH_COMPILER_VAR_1584[1] = BAH_DIR;____BAH_COMPILER_VAR_1584[0] = "\050\0\0\0""Could not find fixme.bah, please check '";char * ____BAH_COMPILER_VAR_1585 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1584, 3);__BAH_panic(____BAH_COMPILER_VAR_1585,"\056\0\0\0""/home/alois/Documents/bah-bah/src/main.bah:286");
}
}

#line 290 "/home/alois/Documents/bah-bah/src/main.bah"
shouldOnlyDecl = false;

#line 293 "/home/alois/Documents/bah-bah/src/main.bah"
if ((flags__isSet(&flags,"\01\0\0\0""l")==1)) {

#line 294 "/home/alois/Documents/bah-bah/src/main.bah"
OUTPUT = rope("\0\0\0\0""");

#line 295 "/home/alois/Documents/bah-bah/src/main.bah"
declareAll(elems);
}

#line 298 "/home/alois/Documents/bah-bah/src/main.bah"
compilerState.currentDir = getDirFromFile(fileName);

#line 299 "/home/alois/Documents/bah-bah/src/main.bah"
parseLines(tokens,elems);

#line 301 "/home/alois/Documents/bah-bah/src/main.bah"
if ((isObject==false)&&(isUnsafe==false)) {

#line 302 "/home/alois/Documents/bah-bah/src/main.bah"
long int l = 0;

#line 303 "/home/alois/Documents/bah-bah/src/main.bah"
register long int i = 0;

#line 303 "/home/alois/Documents/bah-bah/src/main.bah"
for (; (i<len(elems->fns)); 
#line 303 "/home/alois/Documents/bah-bah/src/main.bah"
++i) {

#line 304 "/home/alois/Documents/bah-bah/src/main.bah"
struct func* fn = elems->fns->data[i];

#line 305 "/home/alois/Documents/bah-bah/src/main.bah"
if ((fn->isBinding==true)) {

#line 306 "/home/alois/Documents/bah-bah/src/main.bah"
continue;
}

#line 308 "/home/alois/Documents/bah-bah/src/main.bah"
++l;
};

#line 310 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1586 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1586[2] = "\02\0\0\0""];";____BAH_COMPILER_VAR_1586[1] = intToStr(l);____BAH_COMPILER_VAR_1586[0] = "\071\0\0\0""volatile struct __Bah_fnName_mapper __tmp____Bah_fnNames[";char * ____BAH_COMPILER_VAR_1587 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1586, 3);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1587));

#line 311 "/home/alois/Documents/bah-bah/src/main.bah"
long int j = 0;

#line 312 "/home/alois/Documents/bah-bah/src/main.bah"
i = 0;

#line 312 "/home/alois/Documents/bah-bah/src/main.bah"
for (; (i<len(elems->fns)); 
#line 312 "/home/alois/Documents/bah-bah/src/main.bah"
++i) {

#line 313 "/home/alois/Documents/bah-bah/src/main.bah"
struct func* fn = elems->fns->data[i];

#line 314 "/home/alois/Documents/bah-bah/src/main.bah"
if ((fn->isBinding==true)) {

#line 315 "/home/alois/Documents/bah-bah/src/main.bah"
continue;
}

#line 317 "/home/alois/Documents/bah-bah/src/main.bah"
char * name = fn->name;

#line 318 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1588 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1588[1] = "\02\0\0\0""__";____BAH_COMPILER_VAR_1588[0] = fn->from;char * ____BAH_COMPILER_VAR_1589 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1588, 2);if ((strcmp(fn->from, "\0\0\0\0""") != 0)&&strHasPrefix(name,____BAH_COMPILER_VAR_1589)) {

#line 319 "/home/alois/Documents/bah-bah/src/main.bah"
struct string n = string(name);

#line 320 "/home/alois/Documents/bah-bah/src/main.bah"
string__trimLeft(&n,strlen(fn->from)+2);

#line 321 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1590 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1590[2] = string__str(&n);____BAH_COMPILER_VAR_1590[1] = "\01\0\0\0"".";____BAH_COMPILER_VAR_1590[0] = fn->from;char * ____BAH_COMPILER_VAR_1591 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1590, 3);name = ____BAH_COMPILER_VAR_1591;
}

#line 323 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1592 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1592[2] = "\01\0\0\0""\"";____BAH_COMPILER_VAR_1592[1] = name;____BAH_COMPILER_VAR_1592[0] = "\01\0\0\0""\"";char * ____BAH_COMPILER_VAR_1593 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1592, 3);char** ____BAH_COMPILER_VAR_1594 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_1594[8] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_1594[7] = fn->name;____BAH_COMPILER_VAR_1594[6] = "\06\0\0\0""].p = ";____BAH_COMPILER_VAR_1594[5] = intToStr(j);____BAH_COMPILER_VAR_1594[4] = "\043\0\0\0"";\n            __tmp____Bah_fnNames[";____BAH_COMPILER_VAR_1594[3] = strLitteralToBahStr(____BAH_COMPILER_VAR_1593);____BAH_COMPILER_VAR_1594[2] = "\06\0\0\0""].n = ";____BAH_COMPILER_VAR_1594[1] = intToStr(j);____BAH_COMPILER_VAR_1594[0] = "\042\0\0\0""\n            __tmp____Bah_fnNames[";char * ____BAH_COMPILER_VAR_1595 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1594, 9);INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_1595));

#line 326 "/home/alois/Documents/bah-bah/src/main.bah"
++j;
};

#line 328 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1596 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1596[2] = "\01\0\0\0"";";____BAH_COMPILER_VAR_1596[1] = intToStr(l);____BAH_COMPILER_VAR_1596[0] = "\125\0\0\0""\n        __Bah_fnNames->data = __tmp____Bah_fnNames;\n        __Bah_fnNames->length = ";char * ____BAH_COMPILER_VAR_1597 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1596, 3);INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_1597));
}

#line 333 "/home/alois/Documents/bah-bah/src/main.bah"
makeInit();

#line 335 "/home/alois/Documents/bah-bah/src/main.bah"
array(char *)* excludeFns = memoryAlloc(sizeof(array(char *)));

excludeFns->length = 6;
excludeFns->elemSize = sizeof(char *);
excludeFns->data = memoryAlloc(sizeof(char *) * 50);
                    excludeFns->realLength = 50;
excludeFns->data[0] = "\04\0\0\0""main";
excludeFns->data[1] = "\016\0\0\0""cpstringCharAt";
excludeFns->data[2] = "\021\0\0\0""cpstringSubsitute";
excludeFns->data[3] = "\07\0\0\0""channel";
excludeFns->data[4] = "\012\0\0\0""mapWrapper";
excludeFns->data[5] = "\017\0\0\0""arraySubstitute";

#line 356 "/home/alois/Documents/bah-bah/src/main.bah"
if ((debug==true)) {

#line 357 "/home/alois/Documents/bah-bah/src/main.bah"
debugEnd();

#line 358 "/home/alois/Documents/bah-bah/src/main.bah"
return 0;
}

#line 362 "/home/alois/Documents/bah-bah/src/main.bah"
if ((isObject==false)) {

#line 363 "/home/alois/Documents/bah-bah/src/main.bah"
long int totalTime = getTimeUnix()-startTime;

#line 364 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1598 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_1598[6] = "\07\0\0\0""ms)\e[0m";____BAH_COMPILER_VAR_1598[5] = intToStr(totalLexerTime/1000000);____BAH_COMPILER_VAR_1598[4] = "\020\0\0\0""ms, lexer time: ";____BAH_COMPILER_VAR_1598[3] = intToStr(totalTime/1000000);____BAH_COMPILER_VAR_1598[2] = "\024\0\0\0"" lines, total time: ";____BAH_COMPILER_VAR_1598[1] = intToStr(totalLines);____BAH_COMPILER_VAR_1598[0] = "\011\0\0\0""Parsed. (";char * ____BAH_COMPILER_VAR_1599 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1598, 7);println(____BAH_COMPILER_VAR_1599);
}

#line 368 "/home/alois/Documents/bah-bah/src/main.bah"
if ((flags__isSet(&flags,"\01\0\0\0""o")==1)) {

#line 369 "/home/alois/Documents/bah-bah/src/main.bah"
fileName = flags__get(&flags,"\01\0\0\0""o");
}

#line 370 "/home/alois/Documents/bah-bah/src/main.bah"
else {

#line 371 "/home/alois/Documents/bah-bah/src/main.bah"
struct string outFileName = string(args->data[1]);

#line 372 "/home/alois/Documents/bah-bah/src/main.bah"
string__trimRight(&outFileName,4);

#line 373 "/home/alois/Documents/bah-bah/src/main.bah"
fileName = string__str(&outFileName);
}

#line 377 "/home/alois/Documents/bah-bah/src/main.bah"
char * isStatic = "\07\0\0\0""-static";

#line 378 "/home/alois/Documents/bah-bah/src/main.bah"
if ((flags__isSet(&flags,"\01\0\0\0""d")==1)||(strcmp(BAH_OS, "\06\0\0\0""darwin") == 0)) {

#line 379 "/home/alois/Documents/bah-bah/src/main.bah"
isStatic = "\0\0\0\0""";
}

#line 383 "/home/alois/Documents/bah-bah/src/main.bah"
if ((flags__isSet(&flags,"\01\0\0\0""c")==0)) {

#line 385 "/home/alois/Documents/bah-bah/src/main.bah"
char * obj = "\0\0\0\0""";

#line 386 "/home/alois/Documents/bah-bah/src/main.bah"
if ((flags__isSet(&flags,"\06\0\0\0""object")==1)) {

#line 387 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1600 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1600[1] = "\02\0\0\0"".o";____BAH_COMPILER_VAR_1600[0] = fileName;char * ____BAH_COMPILER_VAR_1601 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1600, 2);fileName = ____BAH_COMPILER_VAR_1601;

#line 388 "/home/alois/Documents/bah-bah/src/main.bah"
obj = "\02\0\0\0""-c";
}

#line 391 "/home/alois/Documents/bah-bah/src/main.bah"
char * randFileName = "\016\0\0\0""-x c - -x none";

#line 392 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1602 = alloca(17 * sizeof(char*));____BAH_COMPILER_VAR_1602[16] = fileName;____BAH_COMPILER_VAR_1602[15] = "\017\0\0\0"" -w -O1 -g1 -o ";____BAH_COMPILER_VAR_1602[14] = obj;____BAH_COMPILER_VAR_1602[13] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_1602[12] = isStatic;____BAH_COMPILER_VAR_1602[11] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_1602[10] = randFileName;____BAH_COMPILER_VAR_1602[9] = "\03\0\0\0""/\" ";____BAH_COMPILER_VAR_1602[8] = BAH_OS;____BAH_COMPILER_VAR_1602[7] = "\05\0\0\0""libs/";____BAH_COMPILER_VAR_1602[6] = BAH_DIR;____BAH_COMPILER_VAR_1602[5] = "\017\0\0\0""/include/\" -L \"";____BAH_COMPILER_VAR_1602[4] = BAH_OS;____BAH_COMPILER_VAR_1602[3] = "\05\0\0\0""libs/";____BAH_COMPILER_VAR_1602[2] = BAH_DIR;____BAH_COMPILER_VAR_1602[1] = "\05\0\0\0"" -I \"";____BAH_COMPILER_VAR_1602[0] = BAH_CC;char * ____BAH_COMPILER_VAR_1603 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1602, 17);char * gccArgs = ____BAH_COMPILER_VAR_1603;

#line 394 "/home/alois/Documents/bah-bah/src/main.bah"
if ((flags__isSet(&flags,"\01\0\0\0""l")==1)) {

#line 395 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1604 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1604[1] = "\03\0\0\0"" -c";____BAH_COMPILER_VAR_1604[0] = gccArgs;char * ____BAH_COMPILER_VAR_1605 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1604, 2);gccArgs = ____BAH_COMPILER_VAR_1605;
}

#line 399 "/home/alois/Documents/bah-bah/src/main.bah"
array(char *)* cLibs = compilerState.cLibs;

#line 400 "/home/alois/Documents/bah-bah/src/main.bah"
register long int i = 0;

#line 400 "/home/alois/Documents/bah-bah/src/main.bah"
while ((i<len(cLibs))) {

#line 401 "/home/alois/Documents/bah-bah/src/main.bah"
char * l = cLibs->data[i];

#line 402 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1606 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1606[2] = l;____BAH_COMPILER_VAR_1606[1] = "\02\0\0\0"" -";____BAH_COMPILER_VAR_1606[0] = gccArgs;char * ____BAH_COMPILER_VAR_1607 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1606, 3);gccArgs = ____BAH_COMPILER_VAR_1607;

#line 403 "/home/alois/Documents/bah-bah/src/main.bah"
i = i+1;
};

#line 407 "/home/alois/Documents/bah-bah/src/main.bah"
struct command cmd = command(gccArgs);

#line 408 "/home/alois/Documents/bah-bah/src/main.bah"
cmd.input = rope__toStr(OUTPUT);

#line 414 "/home/alois/Documents/bah-bah/src/main.bah"
if ((flags__isSet(&flags,"\011\0\0\0""verboseCC")==1)) {

#line 415 "/home/alois/Documents/bah-bah/src/main.bah"
println(command__run(&cmd));
}

#line 416 "/home/alois/Documents/bah-bah/src/main.bah"
else {

#line 417 "/home/alois/Documents/bah-bah/src/main.bah"
command__run(&cmd);
}

#line 420 "/home/alois/Documents/bah-bah/src/main.bah"
if ((cmd.status!=0)) {

#line 421 "/home/alois/Documents/bah-bah/src/main.bah"
println("\050\0\0\0""\e[1;31m[CC-ERROR]\e[0m\nCould not compile.");

#line 422 "/home/alois/Documents/bah-bah/src/main.bah"
return 1;
}

#line 425 "/home/alois/Documents/bah-bah/src/main.bah"
if ((flags__isSet(&flags,"\01\0\0\0""l")==1)) {

#line 426 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1608 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1608[3] = fileName;____BAH_COMPILER_VAR_1608[2] = "\03\0\0\0"".a ";____BAH_COMPILER_VAR_1608[1] = fileName;____BAH_COMPILER_VAR_1608[0] = "\07\0\0\0""ar rcs ";char * ____BAH_COMPILER_VAR_1609 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1608, 4);cmd = command(____BAH_COMPILER_VAR_1609);

#line 427 "/home/alois/Documents/bah-bah/src/main.bah"
command__run(&cmd);
}
}

#line 430 "/home/alois/Documents/bah-bah/src/main.bah"
else {

#line 432 "/home/alois/Documents/bah-bah/src/main.bah"
if ((flags__isSet(&flags,"\01\0\0\0""o")==0)) {

#line 433 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1610 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1610[1] = "\02\0\0\0"".c";____BAH_COMPILER_VAR_1610[0] = fileName;char * ____BAH_COMPILER_VAR_1611 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1610, 2);fileName = ____BAH_COMPILER_VAR_1611;
}

#line 436 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1612 = alloca(14 * sizeof(char*));____BAH_COMPILER_VAR_1612[13] = "\010\0\0\0"" -O1 -w ";____BAH_COMPILER_VAR_1612[12] = isStatic;____BAH_COMPILER_VAR_1612[11] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_1612[10] = fileName;____BAH_COMPILER_VAR_1612[9] = "\03\0\0\0""/\" ";____BAH_COMPILER_VAR_1612[8] = BAH_OS;____BAH_COMPILER_VAR_1612[7] = "\05\0\0\0""libs/";____BAH_COMPILER_VAR_1612[6] = BAH_DIR;____BAH_COMPILER_VAR_1612[5] = "\017\0\0\0""/include/\" -L \"";____BAH_COMPILER_VAR_1612[4] = BAH_OS;____BAH_COMPILER_VAR_1612[3] = "\05\0\0\0""libs/";____BAH_COMPILER_VAR_1612[2] = BAH_DIR;____BAH_COMPILER_VAR_1612[1] = "\05\0\0\0"" -I \"";____BAH_COMPILER_VAR_1612[0] = BAH_CC;char * ____BAH_COMPILER_VAR_1613 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1612, 14);char * gccArgs = ____BAH_COMPILER_VAR_1613;

#line 437 "/home/alois/Documents/bah-bah/src/main.bah"
array(char *)* cLibs = compilerState.cLibs;

#line 438 "/home/alois/Documents/bah-bah/src/main.bah"
register long int i = 0;

#line 438 "/home/alois/Documents/bah-bah/src/main.bah"
while ((i<len(cLibs))) {

#line 439 "/home/alois/Documents/bah-bah/src/main.bah"
char * l = cLibs->data[i];

#line 440 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1614 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1614[2] = l;____BAH_COMPILER_VAR_1614[1] = "\02\0\0\0"" -";____BAH_COMPILER_VAR_1614[0] = gccArgs;char * ____BAH_COMPILER_VAR_1615 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1614, 3);gccArgs = ____BAH_COMPILER_VAR_1615;

#line 441 "/home/alois/Documents/bah-bah/src/main.bah"
i = i+1;
};

#line 445 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1616 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1616[2] = "\02\0\0\0""'\n";____BAH_COMPILER_VAR_1616[1] = gccArgs;____BAH_COMPILER_VAR_1616[0] = "\021\0\0\0""//COMPILE WITH: '";char * ____BAH_COMPILER_VAR_1617 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1616, 3);OUTPUT = rope__add(rope(____BAH_COMPILER_VAR_1617), OUTPUT);

#line 446 "/home/alois/Documents/bah-bah/src/main.bah"
struct fileStream ____BAH_COMPILER_VAR_1618 = {};
fs = ____BAH_COMPILER_VAR_1618;

#line 447 "/home/alois/Documents/bah-bah/src/main.bah"
fileStream__open(&fs,fileName,"\01\0\0\0""w");

#line 448 "/home/alois/Documents/bah-bah/src/main.bah"
fileStream__writeFile(&fs,rope__toStr(OUTPUT));

#line 449 "/home/alois/Documents/bah-bah/src/main.bah"
fileStream__close(&fs);
}

#line 453 "/home/alois/Documents/bah-bah/src/main.bah"
if ((isObject==false)) {

#line 454 "/home/alois/Documents/bah-bah/src/main.bah"
long int totalTime = getTimeUnix()-startTime;

#line 455 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1619 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1619[2] = "\07\0\0\0""ms)\e[0m";____BAH_COMPILER_VAR_1619[1] = intToStr(totalTime/1000000);____BAH_COMPILER_VAR_1619[0] = "\032\0\0\0""\e[1;32mDone. (compiled in ";char * ____BAH_COMPILER_VAR_1620 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1619, 3);println(____BAH_COMPILER_VAR_1620);
}

#line 458 "/home/alois/Documents/bah-bah/src/main.bah"
return 0;
};
volatile struct __Bah_fnName_mapper __tmp____Bah_fnNames[356];
    
    void __attribute__((optimize("O0"))) __BAH_init() {
        __BAH_panic_chan = null;
__Bah_fnNames = memoryAlloc(sizeof(array(struct __Bah_fnName_mapper)));

__Bah_fnNames->length = 0;
__Bah_fnNames->elemSize = sizeof(struct __Bah_fnName_mapper);
onMemoryError = null;
__Bah_init_segfaultHandle_OK = __Bah_init_segfaultHandle();
__Bah_iostream_stdinputBuffer = "\0\0\0\0""";
__Bah_iostream_stdinputBufferLength = 0;
RAND_SEEDED = false;
jError = "\0\0\0\0""";
BAH_DIR = "\07\0\0\0""C:/Bah/";
BAH_OS = "\07\0\0\0""windows";
BAH_CC = "\03\0\0\0""gcc";
debug = false;
verboseRuntime = false;
isObject = false;
isUnsafe = false;
isOptimized = false;
noticeEnabled = true;
RAIIenabled = false;
isFixMeEnabled = false;
execName = "\03\0\0\0""bah";
isSubObject = false;
isImportedSubObject = false;
OUTPUT = rope("\0\0\0\0""");
NEXT_LINE = "\0\0\0\0""";
INIT = rope("\0\0\0\0""");
postDeclHandle = rope("\0\0\0\0""");
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
prevIfShortcut = "\0\0\0\0""";
begIfHandle = rope("\0\0\0\0""");
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
keywords->data[0] = "\02\0\0\0""if";
keywords->data[1] = "\04\0\0\0""else";
keywords->data[2] = "\03\0\0\0""for";
keywords->data[3] = "\06\0\0\0""struct";
keywords->data[4] = "\05\0\0\0""const";
keywords->data[5] = "\06\0\0\0""return";
keywords->data[6] = "\06\0\0\0""extend";
keywords->data[7] = "\03\0\0\0""new";
keywords->data[8] = "\05\0\0\0""break";
keywords->data[9] = "\010\0\0\0""continue";
keywords->data[10] = "\07\0\0\0""default";
keywords->data[11] = "\06\0\0\0""switch";
keywords->data[12] = "\04\0\0\0""case";
keywords->data[13] = "\05\0\0\0""while";
keywords->data[14] = "\07\0\0\0""typedef";
keywords->data[15] = "\010\0\0\0""function";
keywords->data[16] = "\05\0\0\0""async";
keywords->data[17] = "\02\0\0\0""in";
keywords->data[18] = "\04\0\0\0""chan";
keywords->data[19] = "\03\0\0\0""map";
keywords->data[20] = "\06\0\0\0""buffer";
keywords->data[21] = "\07\0\0\0""capture";
keywords->data[22] = "\04\0\0\0""then";
intTypes = memoryAlloc(sizeof(array(char *)));

intTypes->length = 5;
intTypes->elemSize = sizeof(char *);
intTypes->data = memoryAlloc(sizeof(char *) * 50);
                    intTypes->realLength = 50;
intTypes->data[0] = "\03\0\0\0""int";
intTypes->data[1] = "\05\0\0\0""int32";
intTypes->data[2] = "\04\0\0\0""uint";
intTypes->data[3] = "\06\0\0\0""uint32";
intTypes->data[4] = "\04\0\0\0""bool";
floatTypes = memoryAlloc(sizeof(array(char *)));

floatTypes->length = 4;
floatTypes->elemSize = sizeof(char *);
floatTypes->data = memoryAlloc(sizeof(char *) * 50);
                    floatTypes->realLength = 50;
floatTypes->data[0] = "\05\0\0\0""float";
floatTypes->data[1] = "\07\0\0\0""float32";
floatTypes->data[2] = "\06\0\0\0""ufloat";
floatTypes->data[3] = "\010\0\0\0""ufloat32";
NB_COMP_VAR = 0;
currFileHashed = "\0\0\0\0""";
currFileHash = "\0\0\0\0""";
noVOfns = memoryAlloc(sizeof(array(char *)));

noVOfns->length = 1;
noVOfns->elemSize = sizeof(char *);
noVOfns->data = memoryAlloc(sizeof(char *) * 50);
                    noVOfns->realLength = 50;
noVOfns->data[0] = "\021\0\0\0""__Bah_safe_string";
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
signs->data[0] = "\01\0\0\0""|";
signs->data[1] = "\01\0\0\0""&";
signs->data[2] = "\01\0\0\0""%";
signs->data[3] = "\01\0\0\0""+";
signs->data[4] = "\01\0\0\0""-";
signs->data[5] = "\01\0\0\0""*";
signs->data[6] = "\01\0\0\0""/";
signs->data[7] = "\02\0\0\0""<<";
signs->data[8] = "\02\0\0\0"">>";
signs->data[9] = "\01\0\0\0""^";
comparators = memoryAlloc(sizeof(array(char *)));

comparators->length = 7;
comparators->elemSize = sizeof(char *);
comparators->data = memoryAlloc(sizeof(char *) * 50);
                    comparators->realLength = 50;
comparators->data[0] = "\02\0\0\0""==";
comparators->data[1] = "\02\0\0\0""!=";
comparators->data[2] = "\01\0\0\0"">";
comparators->data[3] = "\01\0\0\0""<";
comparators->data[4] = "\02\0\0\0""<=";
comparators->data[5] = "\02\0\0\0"">=";
comparators->data[6] = "\02\0\0\0""in";
compSep = memoryAlloc(sizeof(array(char *)));

compSep->length = 2;
compSep->elemSize = sizeof(char *);
compSep->data = memoryAlloc(sizeof(char *) * 50);
                    compSep->realLength = 50;
compSep->data[0] = "\02\0\0\0""||";
compSep->data[1] = "\02\0\0\0""&&";
equalsTokens = memoryAlloc(sizeof(array(char *)));

equalsTokens->length = 5;
equalsTokens->elemSize = sizeof(char *);
equalsTokens->data = memoryAlloc(sizeof(char *) * 50);
                    equalsTokens->realLength = 50;
equalsTokens->data[0] = "\01\0\0\0""=";
equalsTokens->data[1] = "\02\0\0\0""+=";
equalsTokens->data[2] = "\02\0\0\0""-=";
equalsTokens->data[3] = "\02\0\0\0""*=";
equalsTokens->data[4] = "\02\0\0\0""/=";

            __tmp____Bah_fnNames[0].n = "\013\0\0\0""__BAH_panic";
            __tmp____Bah_fnNames[0].p = __BAH_panic;

            __tmp____Bah_fnNames[1].n = "\021\0\0\0""__Bah_safe_string";
            __tmp____Bah_fnNames[1].p = __Bah_safe_string;

            __tmp____Bah_fnNames[2].n = "\021\0\0\0""cpstringSubsitute";
            __tmp____Bah_fnNames[2].p = cpstringSubsitute;

            __tmp____Bah_fnNames[3].n = "\04\0\0\0""cStr";
            __tmp____Bah_fnNames[3].p = cStr;

            __tmp____Bah_fnNames[4].n = "\014\0\0\0""__bah_strcmp";
            __tmp____Bah_fnNames[4].p = __bah_strcmp;

            __tmp____Bah_fnNames[5].n = "\07\0\0\0""Cstrlen";
            __tmp____Bah_fnNames[5].p = Cstrlen;

            __tmp____Bah_fnNames[6].n = "\017\0\0\0""__bah_strlenSTR";
            __tmp____Bah_fnNames[6].p = __bah_strlenSTR;

            __tmp____Bah_fnNames[7].n = "\03\0\0\0""len";
            __tmp____Bah_fnNames[7].p = len;

            __tmp____Bah_fnNames[8].n = "\05\0\0\0""print";
            __tmp____Bah_fnNames[8].p = print;

            __tmp____Bah_fnNames[9].n = "\014\0\0\0""__BAH_memcpy";
            __tmp____Bah_fnNames[9].p = __BAH_memcpy;

            __tmp____Bah_fnNames[10].n = "\013\0\0\0""memoryAlloc";
            __tmp____Bah_fnNames[10].p = memoryAlloc;

            __tmp____Bah_fnNames[11].n = "\07\0\0\0""destroy";
            __tmp____Bah_fnNames[11].p = destroy;

            __tmp____Bah_fnNames[12].n = "\05\0\0\0""clear";
            __tmp____Bah_fnNames[12].p = clear;

            __tmp____Bah_fnNames[13].n = "\015\0\0\0""memoryRealloc";
            __tmp____Bah_fnNames[13].p = memoryRealloc;

            __tmp____Bah_fnNames[14].n = "\015\0\0\0""cleanShutDown";
            __tmp____Bah_fnNames[14].p = cleanShutDown;

            __tmp____Bah_fnNames[15].n = "\013\0\0\0""memoryOnEnd";
            __tmp____Bah_fnNames[15].p = memoryOnEnd;

            __tmp____Bah_fnNames[16].n = "\06\0\0\0""append";
            __tmp____Bah_fnNames[16].p = append;

            __tmp____Bah_fnNames[17].n = "\04\0\0\0""copy";
            __tmp____Bah_fnNames[17].p = copy;

            __tmp____Bah_fnNames[18].n = "\014\0\0\0""sharedMemory";
            __tmp____Bah_fnNames[18].p = sharedMemory;

            __tmp____Bah_fnNames[19].n = "\021\0\0\0""closeSharedMemory";
            __tmp____Bah_fnNames[19].p = closeSharedMemory;

            __tmp____Bah_fnNames[20].n = "\015\0\0\0""allocateArray";
            __tmp____Bah_fnNames[20].p = allocateArray;

            __tmp____Bah_fnNames[21].n = "\013\0\0\0""__serialize";
            __tmp____Bah_fnNames[21].p = __serialize;

            __tmp____Bah_fnNames[22].n = "\06\0\0\0""serlen";
            __tmp____Bah_fnNames[22].p = serlen;

            __tmp____Bah_fnNames[23].n = "\05\0\0\0""unser";
            __tmp____Bah_fnNames[23].p = unser;

            __tmp____Bah_fnNames[24].n = "\016\0\0\0""memoryAllocSTR";
            __tmp____Bah_fnNames[24].p = memoryAllocSTR;

            __tmp____Bah_fnNames[25].n = "\06\0\0\0""delete";
            __tmp____Bah_fnNames[25].p = delete;

            __tmp____Bah_fnNames[26].n = "\013\0\0\0""deleteRange";
            __tmp____Bah_fnNames[26].p = deleteRange;

            __tmp____Bah_fnNames[27].n = "\010\0\0\0""arrToStr";
            __tmp____Bah_fnNames[27].p = arrToStr;

            __tmp____Bah_fnNames[28].n = "\010\0\0\0""strToArr";
            __tmp____Bah_fnNames[28].p = strToArr;

            __tmp____Bah_fnNames[29].n = "\013\0\0\0""strTrimLeft";
            __tmp____Bah_fnNames[29].p = strTrimLeft;

            __tmp____Bah_fnNames[30].n = "\014\0\0\0""strTrimRight";
            __tmp____Bah_fnNames[30].p = strTrimRight;

            __tmp____Bah_fnNames[31].n = "\011\0\0\0""buffToStr";
            __tmp____Bah_fnNames[31].p = buffToStr;

            __tmp____Bah_fnNames[32].n = "\023\0\0\0""__Bah_realocate_arr";
            __tmp____Bah_fnNames[32].p = __Bah_realocate_arr;

            __tmp____Bah_fnNames[33].n = "\011\0\0\0""argsToArr";
            __tmp____Bah_fnNames[33].p = argsToArr;

            __tmp____Bah_fnNames[34].n = "\011\0\0\0""cStrToBah";
            __tmp____Bah_fnNames[34].p = cStrToBah;

            __tmp____Bah_fnNames[35].n = "\025\0\0\0""__Bah_multiple_concat";
            __tmp____Bah_fnNames[35].p = __Bah_multiple_concat;

            __tmp____Bah_fnNames[36].n = "\016\0\0\0""concatCPSTRING";
            __tmp____Bah_fnNames[36].p = concatCPSTRING;

            __tmp____Bah_fnNames[37].n = "\05\0\0\0""__STR";
            __tmp____Bah_fnNames[37].p = __STR;

            __tmp____Bah_fnNames[38].n = "\04\0\0\0""cArr";
            __tmp____Bah_fnNames[38].p = cArr;

            __tmp____Bah_fnNames[39].n = "\015\0\0\0""__checkString";
            __tmp____Bah_fnNames[39].p = __checkString;

            __tmp____Bah_fnNames[40].n = "\012\0\0\0""mutex.init";
            __tmp____Bah_fnNames[40].p = mutex__init;

            __tmp____Bah_fnNames[41].n = "\012\0\0\0""mutex.lock";
            __tmp____Bah_fnNames[41].p = mutex__lock;

            __tmp____Bah_fnNames[42].n = "\014\0\0\0""mutex.unlock";
            __tmp____Bah_fnNames[42].p = mutex__unlock;

            __tmp____Bah_fnNames[43].n = "\015\0\0\0""mutex.destroy";
            __tmp____Bah_fnNames[43].p = mutex__destroy;

            __tmp____Bah_fnNames[44].n = "\023\0\0\0""mutexCondition.init";
            __tmp____Bah_fnNames[44].p = mutexCondition__init;

            __tmp____Bah_fnNames[45].n = "\023\0\0\0""mutexCondition.wait";
            __tmp____Bah_fnNames[45].p = mutexCondition__wait;

            __tmp____Bah_fnNames[46].n = "\023\0\0\0""mutexCondition.send";
            __tmp____Bah_fnNames[46].p = mutexCondition__send;

            __tmp____Bah_fnNames[47].n = "\026\0\0\0""mutexCondition.destroy";
            __tmp____Bah_fnNames[47].p = mutexCondition__destroy;

            __tmp____Bah_fnNames[48].n = "\016\0\0\0""mutexCondition";
            __tmp____Bah_fnNames[48].p = mutexCondition;

            __tmp____Bah_fnNames[49].n = "\015\0\0\0""thread.create";
            __tmp____Bah_fnNames[49].p = thread__create;

            __tmp____Bah_fnNames[50].n = "\024\0\0\0""thread.createWithArg";
            __tmp____Bah_fnNames[50].p = thread__createWithArg;

            __tmp____Bah_fnNames[51].n = "\013\0\0\0""thread.wait";
            __tmp____Bah_fnNames[51].p = thread__wait;

            __tmp____Bah_fnNames[52].n = "\05\0\0\0""mutex";
            __tmp____Bah_fnNames[52].p = mutex;

            __tmp____Bah_fnNames[53].n = "\014\0\0\0""queue.insert";
            __tmp____Bah_fnNames[53].p = queue__insert;

            __tmp____Bah_fnNames[54].n = "\014\0\0\0""queue.delete";
            __tmp____Bah_fnNames[54].p = queue__delete;

            __tmp____Bah_fnNames[55].n = "\011\0\0\0""queue.get";
            __tmp____Bah_fnNames[55].p = queue__get;

            __tmp____Bah_fnNames[56].n = "\011\0\0\0""queue.set";
            __tmp____Bah_fnNames[56].p = queue__set;

            __tmp____Bah_fnNames[57].n = "\011\0\0\0""queue.pop";
            __tmp____Bah_fnNames[57].p = queue__pop;

            __tmp____Bah_fnNames[58].n = "\013\0\0\0""queue.clear";
            __tmp____Bah_fnNames[58].p = queue__clear;

            __tmp____Bah_fnNames[59].n = "\014\0\0\0""channel.send";
            __tmp____Bah_fnNames[59].p = channel__send;

            __tmp____Bah_fnNames[60].n = "\017\0\0\0""channel.sendAny";
            __tmp____Bah_fnNames[60].p = channel__sendAny;

            __tmp____Bah_fnNames[61].n = "\017\0\0\0""channel.receive";
            __tmp____Bah_fnNames[61].p = channel__receive;

            __tmp____Bah_fnNames[62].n = "\017\0\0\0""channel.destroy";
            __tmp____Bah_fnNames[62].p = channel__destroy;

            __tmp____Bah_fnNames[63].n = "\013\0\0\0""channel.len";
            __tmp____Bah_fnNames[63].p = channel__len;

            __tmp____Bah_fnNames[64].n = "\07\0\0\0""channel";
            __tmp____Bah_fnNames[64].p = channel;

            __tmp____Bah_fnNames[65].n = "\012\0\0\0""setChanCap";
            __tmp____Bah_fnNames[65].p = setChanCap;

            __tmp____Bah_fnNames[66].n = "\022\0\0\0""__Bah_common_panic";
            __tmp____Bah_fnNames[66].p = __Bah_common_panic;

            __tmp____Bah_fnNames[67].n = "\024\0\0\0""__Bah_fnNames_append";
            __tmp____Bah_fnNames[67].p = __Bah_fnNames_append;

            __tmp____Bah_fnNames[68].n = "\010\0\0\0""fastExec";
            __tmp____Bah_fnNames[68].p = fastExec;

            __tmp____Bah_fnNames[69].n = "\025\0\0\0""__Bah_segfault_handle";
            __tmp____Bah_fnNames[69].p = __Bah_segfault_handle;

            __tmp____Bah_fnNames[70].n = "\031\0\0\0""__Bah_init_segfaultHandle";
            __tmp____Bah_fnNames[70].p = __Bah_init_segfaultHandle;

            __tmp____Bah_fnNames[71].n = "\07\0\0\0""recover";
            __tmp____Bah_fnNames[71].p = recover;

            __tmp____Bah_fnNames[72].n = "\016\0\0\0""cpstringCharAt";
            __tmp____Bah_fnNames[72].p = cpstringCharAt;

            __tmp____Bah_fnNames[73].n = "\017\0\0\0""arraySubstitute";
            __tmp____Bah_fnNames[73].p = arraySubstitute;

            __tmp____Bah_fnNames[74].n = "\016\0\0\0""__Bah_map_hash";
            __tmp____Bah_fnNames[74].p = __Bah_map_hash;

            __tmp____Bah_fnNames[75].n = "\014\0\0\0""mapNode.calc";
            __tmp____Bah_fnNames[75].p = mapNode__calc;

            __tmp____Bah_fnNames[76].n = "\017\0\0\0""mapNode.getFast";
            __tmp____Bah_fnNames[76].p = mapNode__getFast;

            __tmp____Bah_fnNames[77].n = "\016\0\0\0""mapNode.append";
            __tmp____Bah_fnNames[77].p = mapNode__append;

            __tmp____Bah_fnNames[78].n = "\021\0\0\0""mapWrapperSetAlgo";
            __tmp____Bah_fnNames[78].p = mapWrapperSetAlgo;

            __tmp____Bah_fnNames[79].n = "\025\0\0\0""mapWrapper.algoChecks";
            __tmp____Bah_fnNames[79].p = mapWrapper__algoChecks;

            __tmp____Bah_fnNames[80].n = "\017\0\0\0""mapWrapper.grow";
            __tmp____Bah_fnNames[80].p = mapWrapper__grow;

            __tmp____Bah_fnNames[81].n = "\017\0\0\0""mapWrapper.set2";
            __tmp____Bah_fnNames[81].p = mapWrapper__set2;

            __tmp____Bah_fnNames[82].n = "\022\0\0\0""mapWrapper.delete2";
            __tmp____Bah_fnNames[82].p = mapWrapper__delete2;

            __tmp____Bah_fnNames[83].n = "\017\0\0\0""mapWrapper.get2";
            __tmp____Bah_fnNames[83].p = mapWrapper__get2;

            __tmp____Bah_fnNames[84].n = "\023\0\0\0""mapWrapper.clearMsr";
            __tmp____Bah_fnNames[84].p = mapWrapper__clearMsr;

            __tmp____Bah_fnNames[85].n = "\017\0\0\0""mapWrapper.get1";
            __tmp____Bah_fnNames[85].p = mapWrapper__get1;

            __tmp____Bah_fnNames[86].n = "\017\0\0\0""mapWrapper.set1";
            __tmp____Bah_fnNames[86].p = mapWrapper__set1;

            __tmp____Bah_fnNames[87].n = "\022\0\0\0""mapWrapper.delete1";
            __tmp____Bah_fnNames[87].p = mapWrapper__delete1;

            __tmp____Bah_fnNames[88].n = "\021\0\0\0""mapWrapper.setAny";
            __tmp____Bah_fnNames[88].p = mapWrapper__setAny;

            __tmp____Bah_fnNames[89].n = "\012\0\0\0""mapWrapper";
            __tmp____Bah_fnNames[89].p = mapWrapper;

            __tmp____Bah_fnNames[90].n = "\011\0\0\0""deleteMap";
            __tmp____Bah_fnNames[90].p = deleteMap;

            __tmp____Bah_fnNames[91].n = "\020\0\0\0""strBuilder._init";
            __tmp____Bah_fnNames[91].p = strBuilder___init;

            __tmp____Bah_fnNames[92].n = "\021\0\0\0""strBuilder.append";
            __tmp____Bah_fnNames[92].p = strBuilder__append;

            __tmp____Bah_fnNames[93].n = "\016\0\0\0""strBuilder.str";
            __tmp____Bah_fnNames[93].p = strBuilder__str;

            __tmp____Bah_fnNames[94].n = "\010\0\0\0""stdinput";
            __tmp____Bah_fnNames[94].p = stdinput;

            __tmp____Bah_fnNames[95].n = "\07\0\0\0""println";
            __tmp____Bah_fnNames[95].p = println;

            __tmp____Bah_fnNames[96].n = "\022\0\0\0""fileStream.isValid";
            __tmp____Bah_fnNames[96].p = fileStream__isValid;

            __tmp____Bah_fnNames[97].n = "\017\0\0\0""fileStream.open";
            __tmp____Bah_fnNames[97].p = fileStream__open;

            __tmp____Bah_fnNames[98].n = "\020\0\0\0""fileStream.close";
            __tmp____Bah_fnNames[98].p = fileStream__close;

            __tmp____Bah_fnNames[99].n = "\021\0\0\0""fileStream.getPos";
            __tmp____Bah_fnNames[99].p = fileStream__getPos;

            __tmp____Bah_fnNames[100].n = "\021\0\0\0""fileStream.setPos";
            __tmp____Bah_fnNames[100].p = fileStream__setPos;

            __tmp____Bah_fnNames[101].n = "\022\0\0\0""fileStream.getSize";
            __tmp____Bah_fnNames[101].p = fileStream__getSize;

            __tmp____Bah_fnNames[102].n = "\021\0\0\0""fileStream.rewind";
            __tmp____Bah_fnNames[102].p = fileStream__rewind;

            __tmp____Bah_fnNames[103].n = "\022\0\0\0""fileStream.getChar";
            __tmp____Bah_fnNames[103].p = fileStream__getChar;

            __tmp____Bah_fnNames[104].n = "\022\0\0\0""fileStream.setChar";
            __tmp____Bah_fnNames[104].p = fileStream__setChar;

            __tmp____Bah_fnNames[105].n = "\025\0\0\0""fileStream.createFile";
            __tmp____Bah_fnNames[105].p = fileStream__createFile;

            __tmp____Bah_fnNames[106].n = "\024\0\0\0""fileStream.writeFile";
            __tmp____Bah_fnNames[106].p = fileStream__writeFile;

            __tmp____Bah_fnNames[107].n = "\023\0\0\0""fileStream.writePtr";
            __tmp____Bah_fnNames[107].p = fileStream__writePtr;

            __tmp____Bah_fnNames[108].n = "\022\0\0\0""fileStream.readPtr";
            __tmp____Bah_fnNames[108].p = fileStream__readPtr;

            __tmp____Bah_fnNames[109].n = "\026\0\0\0""fileStream.readContent";
            __tmp____Bah_fnNames[109].p = fileStream__readContent;

            __tmp____Bah_fnNames[110].n = "\024\0\0\0""fileStream.readBytes";
            __tmp____Bah_fnNames[110].p = fileStream__readBytes;

            __tmp____Bah_fnNames[111].n = "\025\0\0\0""fileStream.writeBytes";
            __tmp____Bah_fnNames[111].p = fileStream__writeBytes;

            __tmp____Bah_fnNames[112].n = "\017\0\0\0""fileStream._end";
            __tmp____Bah_fnNames[112].p = fileStream___end;

            __tmp____Bah_fnNames[113].n = "\014\0\0\0""fileMap.open";
            __tmp____Bah_fnNames[113].p = fileMap__open;

            __tmp____Bah_fnNames[114].n = "\017\0\0\0""fileMap.isValid";
            __tmp____Bah_fnNames[114].p = fileMap__isValid;

            __tmp____Bah_fnNames[115].n = "\015\0\0\0""fileMap.close";
            __tmp____Bah_fnNames[115].p = fileMap__close;

            __tmp____Bah_fnNames[116].n = "\011\0\0\0""listFiles";
            __tmp____Bah_fnNames[116].p = listFiles;

            __tmp____Bah_fnNames[117].n = "\012\0\0\0""fileExists";
            __tmp____Bah_fnNames[117].p = fileExists;

            __tmp____Bah_fnNames[118].n = "\010\0\0\0""isFolder";
            __tmp____Bah_fnNames[118].p = isFolder;

            __tmp____Bah_fnNames[119].n = "\012\0\0\0""removeFile";
            __tmp____Bah_fnNames[119].p = removeFile;

            __tmp____Bah_fnNames[120].n = "\017\0\0\0""getLastModified";
            __tmp____Bah_fnNames[120].p = getLastModified;

            __tmp____Bah_fnNames[121].n = "\017\0\0\0""__windows_mkdir";
            __tmp____Bah_fnNames[121].p = __windows_mkdir;

            __tmp____Bah_fnNames[122].n = "\014\0\0\0""strCatOffset";
            __tmp____Bah_fnNames[122].p = strCatOffset;

            __tmp____Bah_fnNames[123].n = "\014\0\0\0""charToString";
            __tmp____Bah_fnNames[123].p = charToString;

            __tmp____Bah_fnNames[124].n = "\07\0\0\0""isUpper";
            __tmp____Bah_fnNames[124].p = isUpper;

            __tmp____Bah_fnNames[125].n = "\07\0\0\0""isLower";
            __tmp____Bah_fnNames[125].p = isLower;

            __tmp____Bah_fnNames[126].n = "\010\0\0\0""isLetter";
            __tmp____Bah_fnNames[126].p = isLetter;

            __tmp____Bah_fnNames[127].n = "\010\0\0\0""isNumber";
            __tmp____Bah_fnNames[127].p = isNumber;

            __tmp____Bah_fnNames[128].n = "\016\0\0\0""isAlphaNumeric";
            __tmp____Bah_fnNames[128].p = isAlphaNumeric;

            __tmp____Bah_fnNames[129].n = "\07\0\0\0""isSpace";
            __tmp____Bah_fnNames[129].p = isSpace;

            __tmp____Bah_fnNames[130].n = "\012\0\0\0""strReplace";
            __tmp____Bah_fnNames[130].p = strReplace;

            __tmp____Bah_fnNames[131].n = "\012\0\0\0""string.set";
            __tmp____Bah_fnNames[131].p = string__set;

            __tmp____Bah_fnNames[132].n = "\023\0\0\0""string.makeEditable";
            __tmp____Bah_fnNames[132].p = string__makeEditable;

            __tmp____Bah_fnNames[133].n = "\015\0\0\0""string.append";
            __tmp____Bah_fnNames[133].p = string__append;

            __tmp____Bah_fnNames[134].n = "\016\0\0\0""string.prepend";
            __tmp____Bah_fnNames[134].p = string__prepend;

            __tmp____Bah_fnNames[135].n = "\015\0\0\0""string.charAt";
            __tmp____Bah_fnNames[135].p = string__charAt;

            __tmp____Bah_fnNames[136].n = "\016\0\0\0""string.compare";
            __tmp____Bah_fnNames[136].p = string__compare;

            __tmp____Bah_fnNames[137].n = "\012\0\0\0""string.str";
            __tmp____Bah_fnNames[137].p = string__str;

            __tmp____Bah_fnNames[138].n = "\016\0\0\0""string.replace";
            __tmp____Bah_fnNames[138].p = string__replace;

            __tmp____Bah_fnNames[139].n = "\020\0\0\0""string.countChar";
            __tmp____Bah_fnNames[139].p = string__countChar;

            __tmp____Bah_fnNames[140].n = "\014\0\0\0""string.count";
            __tmp____Bah_fnNames[140].p = string__count;

            __tmp____Bah_fnNames[141].n = "\020\0\0\0""string.hasPrefix";
            __tmp____Bah_fnNames[141].p = string__hasPrefix;

            __tmp____Bah_fnNames[142].n = "\020\0\0\0""string.hasSuffix";
            __tmp____Bah_fnNames[142].p = string__hasSuffix;

            __tmp____Bah_fnNames[143].n = "\013\0\0\0""string.trim";
            __tmp____Bah_fnNames[143].p = string__trim;

            __tmp____Bah_fnNames[144].n = "\017\0\0\0""string.trimLeft";
            __tmp____Bah_fnNames[144].p = string__trimLeft;

            __tmp____Bah_fnNames[145].n = "\020\0\0\0""string.trimRight";
            __tmp____Bah_fnNames[145].p = string__trimRight;

            __tmp____Bah_fnNames[146].n = "\012\0\0\0""string.add";
            __tmp____Bah_fnNames[146].p = string__add;

            __tmp____Bah_fnNames[147].n = "\014\0\0\0""string.asArr";
            __tmp____Bah_fnNames[147].p = string__asArr;

            __tmp____Bah_fnNames[148].n = "\022\0\0\0""string.resetLength";
            __tmp____Bah_fnNames[148].p = string__resetLength;

            __tmp____Bah_fnNames[149].n = "\06\0\0\0""string";
            __tmp____Bah_fnNames[149].p = string;

            __tmp____Bah_fnNames[150].n = "\010\0\0\0""intToStr";
            __tmp____Bah_fnNames[150].p = intToStr;

            __tmp____Bah_fnNames[151].n = "\013\0\0\0""intToString";
            __tmp____Bah_fnNames[151].p = intToString;

            __tmp____Bah_fnNames[152].n = "\012\0\0\0""floatToStr";
            __tmp____Bah_fnNames[152].p = floatToStr;

            __tmp____Bah_fnNames[153].n = "\010\0\0\0""strToInt";
            __tmp____Bah_fnNames[153].p = strToInt;

            __tmp____Bah_fnNames[154].n = "\012\0\0\0""strToFloat";
            __tmp____Bah_fnNames[154].p = strToFloat;

            __tmp____Bah_fnNames[155].n = "\013\0\0\0""stringToInt";
            __tmp____Bah_fnNames[155].p = stringToInt;

            __tmp____Bah_fnNames[156].n = "\013\0\0\0""splitString";
            __tmp____Bah_fnNames[156].p = splitString;

            __tmp____Bah_fnNames[157].n = "\012\0\0\0""joinString";
            __tmp____Bah_fnNames[157].p = joinString;

            __tmp____Bah_fnNames[158].n = "\021\0\0\0""splitStringBefore";
            __tmp____Bah_fnNames[158].p = splitStringBefore;

            __tmp____Bah_fnNames[159].n = "\07\0\0\0""toLower";
            __tmp____Bah_fnNames[159].p = toLower;

            __tmp____Bah_fnNames[160].n = "\014\0\0\0""strHasPrefix";
            __tmp____Bah_fnNames[160].p = strHasPrefix;

            __tmp____Bah_fnNames[161].n = "\014\0\0\0""strHasSuffix";
            __tmp____Bah_fnNames[161].p = strHasSuffix;

            __tmp____Bah_fnNames[162].n = "\07\0\0\0""strTrim";
            __tmp____Bah_fnNames[162].p = strTrim;

            __tmp____Bah_fnNames[163].n = "\010\0\0\0""strCount";
            __tmp____Bah_fnNames[163].p = strCount;

            __tmp____Bah_fnNames[164].n = "\017\0\0\0""flags.addString";
            __tmp____Bah_fnNames[164].p = flags__addString;

            __tmp____Bah_fnNames[165].n = "\015\0\0\0""flags.addBool";
            __tmp____Bah_fnNames[165].p = flags__addBool;

            __tmp____Bah_fnNames[166].n = "\014\0\0\0""flags.addInt";
            __tmp____Bah_fnNames[166].p = flags__addInt;

            __tmp____Bah_fnNames[167].n = "\016\0\0\0""flags.addFloat";
            __tmp____Bah_fnNames[167].p = flags__addFloat;

            __tmp____Bah_fnNames[168].n = "\020\0\0\0""flags.invalidate";
            __tmp____Bah_fnNames[168].p = flags__invalidate;

            __tmp____Bah_fnNames[169].n = "\015\0\0\0""flags.getFlag";
            __tmp____Bah_fnNames[169].p = flags__getFlag;

            __tmp____Bah_fnNames[170].n = "\011\0\0\0""flags.get";
            __tmp____Bah_fnNames[170].p = flags__get;

            __tmp____Bah_fnNames[171].n = "\014\0\0\0""flags.getInt";
            __tmp____Bah_fnNames[171].p = flags__getInt;

            __tmp____Bah_fnNames[172].n = "\016\0\0\0""flags.getFloat";
            __tmp____Bah_fnNames[172].p = flags__getFloat;

            __tmp____Bah_fnNames[173].n = "\013\0\0\0""flags.isSet";
            __tmp____Bah_fnNames[173].p = flags__isSet;

            __tmp____Bah_fnNames[174].n = "\013\0\0\0""flags.parse";
            __tmp____Bah_fnNames[174].p = flags__parse;

            __tmp____Bah_fnNames[175].n = "\010\0\0\0""time.now";
            __tmp____Bah_fnNames[175].p = time__now;

            __tmp____Bah_fnNames[176].n = "\013\0\0\0""time.format";
            __tmp____Bah_fnNames[176].p = time__format;

            __tmp____Bah_fnNames[177].n = "\012\0\0\0""time.since";
            __tmp____Bah_fnNames[177].p = time__since;

            __tmp____Bah_fnNames[178].n = "\013\0\0\0""getTimeUnix";
            __tmp____Bah_fnNames[178].p = getTimeUnix;

            __tmp____Bah_fnNames[179].n = "\012\0\0\0""seedRandom";
            __tmp____Bah_fnNames[179].p = seedRandom;

            __tmp____Bah_fnNames[180].n = "\015\0\0\0""randomInRange";
            __tmp____Bah_fnNames[180].p = randomInRange;

            __tmp____Bah_fnNames[181].n = "\012\0\0\0""cryptoRand";
            __tmp____Bah_fnNames[181].p = cryptoRand;

            __tmp____Bah_fnNames[182].n = "\013\0\0\0""rope.addStr";
            __tmp____Bah_fnNames[182].p = rope__addStr;

            __tmp____Bah_fnNames[183].n = "\013\0\0\0""rope.getLen";
            __tmp____Bah_fnNames[183].p = rope__getLen;

            __tmp____Bah_fnNames[184].n = "\012\0\0\0""rope.toStr";
            __tmp____Bah_fnNames[184].p = rope__toStr;

            __tmp____Bah_fnNames[185].n = "\010\0\0\0""rope.add";
            __tmp____Bah_fnNames[185].p = rope__add;

            __tmp____Bah_fnNames[186].n = "\013\0\0\0""rope.append";
            __tmp____Bah_fnNames[186].p = rope__append;

            __tmp____Bah_fnNames[187].n = "\07\0\0\0""ropeSet";
            __tmp____Bah_fnNames[187].p = ropeSet;

            __tmp____Bah_fnNames[188].n = "\04\0\0\0""rope";
            __tmp____Bah_fnNames[188].p = rope;

            __tmp____Bah_fnNames[189].n = "\013\0\0\0""command.run";
            __tmp____Bah_fnNames[189].p = command__run;

            __tmp____Bah_fnNames[190].n = "\020\0\0\0""command.runBytes";
            __tmp____Bah_fnNames[190].p = command__runBytes;

            __tmp____Bah_fnNames[191].n = "\07\0\0\0""command";
            __tmp____Bah_fnNames[191].p = command;

            __tmp____Bah_fnNames[192].n = "\04\0\0\0""exec";
            __tmp____Bah_fnNames[192].p = exec;

            __tmp____Bah_fnNames[193].n = "\036\0\0\0""reflectElement.calculateOffset";
            __tmp____Bah_fnNames[193].p = reflectElement__calculateOffset;

            __tmp____Bah_fnNames[194].n = "\011\0\0\0""__reflect";
            __tmp____Bah_fnNames[194].p = __reflect;

            __tmp____Bah_fnNames[195].n = "\015\0\0\0""__dumpSymbols";
            __tmp____Bah_fnNames[195].p = __dumpSymbols;

            __tmp____Bah_fnNames[196].n = "\017\0\0\0""__debug_get_sym";
            __tmp____Bah_fnNames[196].p = __debug_get_sym;

            __tmp____Bah_fnNames[197].n = "\06\0\0\0""toJson";
            __tmp____Bah_fnNames[197].p = toJson;

            __tmp____Bah_fnNames[198].n = "\017\0\0\0""json_scan_inner";
            __tmp____Bah_fnNames[198].p = json_scan_inner;

            __tmp____Bah_fnNames[199].n = "\017\0\0\0""jsonElement.get";
            __tmp____Bah_fnNames[199].p = jsonElement__get;

            __tmp____Bah_fnNames[200].n = "\017\0\0\0""jsonElement.str";
            __tmp____Bah_fnNames[200].p = jsonElement__str;

            __tmp____Bah_fnNames[201].n = "\020\0\0\0""jsonElement.scan";
            __tmp____Bah_fnNames[201].p = jsonElement__scan;

            __tmp____Bah_fnNames[202].n = "\017\0\0\0""parseJson_inner";
            __tmp____Bah_fnNames[202].p = parseJson_inner;

            __tmp____Bah_fnNames[203].n = "\011\0\0\0""parseJson";
            __tmp____Bah_fnNames[203].p = parseJson;

            __tmp____Bah_fnNames[204].n = "\020\0\0\0""json_isPrintable";
            __tmp____Bah_fnNames[204].p = json_isPrintable;

            __tmp____Bah_fnNames[205].n = "\015\0\0\0""jsonEscapeStr";
            __tmp____Bah_fnNames[205].p = jsonEscapeStr;

            __tmp____Bah_fnNames[206].n = "\020\0\0\0""oldToJson__inner";
            __tmp____Bah_fnNames[206].p = oldToJson__inner;

            __tmp____Bah_fnNames[207].n = "\011\0\0\0""oldToJson";
            __tmp____Bah_fnNames[207].p = oldToJson;

            __tmp____Bah_fnNames[208].n = "\07\0\0\0""absPath";
            __tmp____Bah_fnNames[208].p = absPath;

            __tmp____Bah_fnNames[209].n = "\016\0\0\0""getCurrentPath";
            __tmp____Bah_fnNames[209].p = getCurrentPath;

            __tmp____Bah_fnNames[210].n = "\010\0\0\0""isInside";
            __tmp____Bah_fnNames[210].p = isInside;

            __tmp____Bah_fnNames[211].n = "\016\0\0\0""setCurrentPath";
            __tmp____Bah_fnNames[211].p = setCurrentPath;

            __tmp____Bah_fnNames[212].n = "\020\0\0\0""Elems.isChildren";
            __tmp____Bah_fnNames[212].p = Elems__isChildren;

            __tmp____Bah_fnNames[213].n = "\011\0\0\0""makeToken";
            __tmp____Bah_fnNames[213].p = makeToken;

            __tmp____Bah_fnNames[214].n = "\07\0\0\0""isMinus";
            __tmp____Bah_fnNames[214].p = isMinus;

            __tmp____Bah_fnNames[215].n = "\010\0\0\0""lexerErr";
            __tmp____Bah_fnNames[215].p = lexerErr;

            __tmp____Bah_fnNames[216].n = "\05\0\0\0""lexer";
            __tmp____Bah_fnNames[216].p = lexer;

            __tmp____Bah_fnNames[217].n = "\014\0\0\0""hasStructSep";
            __tmp____Bah_fnNames[217].p = hasStructSep;

            __tmp____Bah_fnNames[218].n = "\024\0\0\0""splitStructSepBefore";
            __tmp____Bah_fnNames[218].p = splitStructSepBefore;

            __tmp____Bah_fnNames[219].n = "\023\0\0\0""splitStructSepAfter";
            __tmp____Bah_fnNames[219].p = splitStructSepAfter;

            __tmp____Bah_fnNames[220].n = "\014\0\0\0""searchStruct";
            __tmp____Bah_fnNames[220].p = searchStruct;

            __tmp____Bah_fnNames[221].n = "\020\0\0\0""searchStructMemb";
            __tmp____Bah_fnNames[221].p = searchStructMemb;

            __tmp____Bah_fnNames[222].n = "\012\0\0\0""searchFunc";
            __tmp____Bah_fnNames[222].p = searchFunc;

            __tmp____Bah_fnNames[223].n = "\013\0\0\0""parseFnType";
            __tmp____Bah_fnNames[223].p = parseFnType;

            __tmp____Bah_fnNames[224].n = "\022\0\0\0""searchStructMethod";
            __tmp____Bah_fnNames[224].p = searchStructMethod;

            __tmp____Bah_fnNames[225].n = "\012\0\0\0""typeAsStar";
            __tmp____Bah_fnNames[225].p = typeAsStar;

            __tmp____Bah_fnNames[226].n = "\020\0\0\0""isRCPpointerType";
            __tmp____Bah_fnNames[226].p = isRCPpointerType;

            __tmp____Bah_fnNames[227].n = "\011\0\0\0""isRCPtype";
            __tmp____Bah_fnNames[227].p = isRCPtype;

            __tmp____Bah_fnNames[228].n = "\010\0\0\0""getCType";
            __tmp____Bah_fnNames[228].p = getCType;

            __tmp____Bah_fnNames[229].n = "\012\0\0\0""maybeToPtr";
            __tmp____Bah_fnNames[229].p = maybeToPtr;

            __tmp____Bah_fnNames[230].n = "\015\0\0\0""compTypeEquiv";
            __tmp____Bah_fnNames[230].p = compTypeEquiv;

            __tmp____Bah_fnNames[231].n = "\011\0\0\0""compTypes";
            __tmp____Bah_fnNames[231].p = compTypes;

            __tmp____Bah_fnNames[232].n = "\012\0\0\0""debugStart";
            __tmp____Bah_fnNames[232].p = debugStart;

            __tmp____Bah_fnNames[233].n = "\015\0\0\0""noASCIIescape";
            __tmp____Bah_fnNames[233].p = noASCIIescape;

            __tmp____Bah_fnNames[234].n = "\012\0\0\0""debugPrint";
            __tmp____Bah_fnNames[234].p = debugPrint;

            __tmp____Bah_fnNames[235].n = "\012\0\0\0""debugError";
            __tmp____Bah_fnNames[235].p = debugError;

            __tmp____Bah_fnNames[236].n = "\010\0\0\0""debugEnd";
            __tmp____Bah_fnNames[236].p = debugEnd;

            __tmp____Bah_fnNames[237].n = "\011\0\0\0""debugExit";
            __tmp____Bah_fnNames[237].p = debugExit;

            __tmp____Bah_fnNames[238].n = "\015\0\0\0""debugEndScope";
            __tmp____Bah_fnNames[238].p = debugEndScope;

            __tmp____Bah_fnNames[239].n = "\020\0\0\0""advertiseGeneric";
            __tmp____Bah_fnNames[239].p = advertiseGeneric;

            __tmp____Bah_fnNames[240].n = "\012\0\0\0""getFuncDef";
            __tmp____Bah_fnNames[240].p = getFuncDef;

            __tmp____Bah_fnNames[241].n = "\010\0\0\0""throwErr";
            __tmp____Bah_fnNames[241].p = throwErr;

            __tmp____Bah_fnNames[242].n = "\014\0\0\0""throwWarning";
            __tmp____Bah_fnNames[242].p = throwWarning;

            __tmp____Bah_fnNames[243].n = "\020\0\0\0""throwWarningLine";
            __tmp____Bah_fnNames[243].p = throwWarningLine;

            __tmp____Bah_fnNames[244].n = "\017\0\0\0""throwNoticeLine";
            __tmp____Bah_fnNames[244].p = throwNoticeLine;

            __tmp____Bah_fnNames[245].n = "\010\0\0\0""isGlobal";
            __tmp____Bah_fnNames[245].p = isGlobal;

            __tmp____Bah_fnNames[246].n = "\012\0\0\0""getRealVar";
            __tmp____Bah_fnNames[246].p = getRealVar;

            __tmp____Bah_fnNames[247].n = "\015\0\0\0""removeVarUnar";
            __tmp____Bah_fnNames[247].p = removeVarUnar;

            __tmp____Bah_fnNames[248].n = "\011\0\0\0""searchVar";
            __tmp____Bah_fnNames[248].p = searchVar;

            __tmp____Bah_fnNames[249].n = "\020\0\0\0""searchVarByToken";
            __tmp____Bah_fnNames[249].p = searchVarByToken;

            __tmp____Bah_fnNames[250].n = "\024\0\0\0""searchVirtVarByToken";
            __tmp____Bah_fnNames[250].p = searchVirtVarByToken;

            __tmp____Bah_fnNames[251].n = "\010\0\0\0""setCType";
            __tmp____Bah_fnNames[251].p = setCType;

            __tmp____Bah_fnNames[252].n = "\014\0\0\0""isMissingVar";
            __tmp____Bah_fnNames[252].p = isMissingVar;

            __tmp____Bah_fnNames[253].n = "\020\0\0\0""getTypeFromToken";
            __tmp____Bah_fnNames[253].p = getTypeFromToken;

            __tmp____Bah_fnNames[254].n = "\021\0\0\0""searchFuncByToken";
            __tmp____Bah_fnNames[254].p = searchFuncByToken;

            __tmp____Bah_fnNames[255].n = "\014\0\0\0""RCPavailable";
            __tmp____Bah_fnNames[255].p = RCPavailable;

            __tmp____Bah_fnNames[256].n = "\024\0\0\0""declareStructMethods";
            __tmp____Bah_fnNames[256].p = declareStructMethods;

            __tmp____Bah_fnNames[257].n = "\015\0\0\0""pathToVarName";
            __tmp____Bah_fnNames[257].p = pathToVarName;

            __tmp____Bah_fnNames[258].n = "\016\0\0\0""genCompilerVar";
            __tmp____Bah_fnNames[258].p = genCompilerVar;

            __tmp____Bah_fnNames[259].n = "\010\0\0\0""varInArr";
            __tmp____Bah_fnNames[259].p = varInArr;

            __tmp____Bah_fnNames[260].n = "\023\0\0\0""strLitteralToBahStr";
            __tmp____Bah_fnNames[260].p = strLitteralToBahStr;

            __tmp____Bah_fnNames[261].n = "\010\0\0\0""makeInit";
            __tmp____Bah_fnNames[261].p = makeInit;

            __tmp____Bah_fnNames[262].n = "\013\0\0\0""checkedNull";
            __tmp____Bah_fnNames[262].p = checkedNull;

            __tmp____Bah_fnNames[263].n = "\016\0\0\0""checkedNotNull";
            __tmp____Bah_fnNames[263].p = checkedNotNull;

            __tmp____Bah_fnNames[264].n = "\022\0\0\0""canChangeNullState";
            __tmp____Bah_fnNames[264].p = canChangeNullState;

            __tmp____Bah_fnNames[265].n = "\012\0\0\0""removeCast";
            __tmp____Bah_fnNames[265].p = removeCast;

            __tmp____Bah_fnNames[266].n = "\015\0\0\0""isOutterScope";
            __tmp____Bah_fnNames[266].p = isOutterScope;

            __tmp____Bah_fnNames[267].n = "\07\0\0\0""decrVar";
            __tmp____Bah_fnNames[267].p = decrVar;

            __tmp____Bah_fnNames[268].n = "\07\0\0\0""incrVar";
            __tmp____Bah_fnNames[268].p = incrVar;

            __tmp____Bah_fnNames[269].n = "\015\0\0\0""beginRCPscope";
            __tmp____Bah_fnNames[269].p = beginRCPscope;

            __tmp____Bah_fnNames[270].n = "\022\0\0\0""beginRCPscopeLeaky";
            __tmp____Bah_fnNames[270].p = beginRCPscopeLeaky;

            __tmp____Bah_fnNames[271].n = "\013\0\0\0""endRCPscope";
            __tmp____Bah_fnNames[271].p = endRCPscope;

            __tmp____Bah_fnNames[272].n = "\020\0\0\0""endRCPscopeLeaky";
            __tmp____Bah_fnNames[272].p = endRCPscopeLeaky;

            __tmp____Bah_fnNames[273].n = "\016\0\0\0""registerRCPvar";
            __tmp____Bah_fnNames[273].p = registerRCPvar;

            __tmp____Bah_fnNames[274].n = "\012\0\0\0""RCPselfRef";
            __tmp____Bah_fnNames[274].p = RCPselfRef;

            __tmp____Bah_fnNames[275].n = "\017\0\0\0""verboseOutGuard";
            __tmp____Bah_fnNames[275].p = verboseOutGuard;

            __tmp____Bah_fnNames[276].n = "\026\0\0\0""verboseOutTransformVar";
            __tmp____Bah_fnNames[276].p = verboseOutTransformVar;

            __tmp____Bah_fnNames[277].n = "\026\0\0\0""verboseOutTransformTok";
            __tmp____Bah_fnNames[277].p = verboseOutTransformTok;

            __tmp____Bah_fnNames[278].n = "\016\0\0\0""verboseOutFunc";
            __tmp____Bah_fnNames[278].p = verboseOutFunc;

            __tmp____Bah_fnNames[279].n = "\016\0\0\0""verboseOutOper";
            __tmp____Bah_fnNames[279].p = verboseOutOper;

            __tmp____Bah_fnNames[280].n = "\011\0\0\0""readCache";
            __tmp____Bah_fnNames[280].p = readCache;

            __tmp____Bah_fnNames[281].n = "\014\0\0\0""getCacheFile";
            __tmp____Bah_fnNames[281].p = getCacheFile;

            __tmp____Bah_fnNames[282].n = "\017\0\0\0""updateCacheFile";
            __tmp____Bah_fnNames[282].p = updateCacheFile;

            __tmp____Bah_fnNames[283].n = "\015\0\0\0""makeCacheFile";
            __tmp____Bah_fnNames[283].p = makeCacheFile;

            __tmp____Bah_fnNames[284].n = "\012\0\0\0""writeCache";
            __tmp____Bah_fnNames[284].p = writeCache;

            __tmp____Bah_fnNames[285].n = "\020\0\0\0""isValidCacheFile";
            __tmp____Bah_fnNames[285].p = isValidCacheFile;

            __tmp____Bah_fnNames[286].n = "\015\0\0\0""genArrRealloc";
            __tmp____Bah_fnNames[286].p = genArrRealloc;

            __tmp____Bah_fnNames[287].n = "\011\0\0\0""genConcat";
            __tmp____Bah_fnNames[287].p = genConcat;

            __tmp____Bah_fnNames[288].n = "\026\0\0\0""OPTI_checkFuncScopeRef";
            __tmp____Bah_fnNames[288].p = OPTI_checkFuncScopeRef;

            __tmp____Bah_fnNames[289].n = "\017\0\0\0""isExprExpensive";
            __tmp____Bah_fnNames[289].p = isExprExpensive;

            __tmp____Bah_fnNames[290].n = "\013\0\0\0""byteToOctal";
            __tmp____Bah_fnNames[290].p = byteToOctal;

            __tmp____Bah_fnNames[291].n = "\016\0\0\0""escapeIntOctal";
            __tmp____Bah_fnNames[291].p = escapeIntOctal;

            __tmp____Bah_fnNames[292].n = "\011\0\0\0""getStrLen";
            __tmp____Bah_fnNames[292].p = getStrLen;

            __tmp____Bah_fnNames[293].n = "\010\0\0\0""dupElems";
            __tmp____Bah_fnNames[293].p = dupElems;

            __tmp____Bah_fnNames[294].n = "\012\0\0\0""parseLines";
            __tmp____Bah_fnNames[294].p = parseLines;

            __tmp____Bah_fnNames[295].n = "\025\0\0\0""genericFunc.dupBaseFn";
            __tmp____Bah_fnNames[295].p = genericFunc__dupBaseFn;

            __tmp____Bah_fnNames[296].n = "\032\0\0\0""genericFunc.setCurrGeneric";
            __tmp____Bah_fnNames[296].p = genericFunc__setCurrGeneric;

            __tmp____Bah_fnNames[297].n = "\031\0\0\0""genericFunc.isAlreadyDecl";
            __tmp____Bah_fnNames[297].p = genericFunc__isAlreadyDecl;

            __tmp____Bah_fnNames[298].n = "\023\0\0\0""genericFunc.declare";
            __tmp____Bah_fnNames[298].p = genericFunc__declare;

            __tmp____Bah_fnNames[299].n = "\011\0\0\0""debugLine";
            __tmp____Bah_fnNames[299].p = debugLine;

            __tmp____Bah_fnNames[300].n = "\016\0\0\0""checkCanBeNull";
            __tmp____Bah_fnNames[300].p = checkCanBeNull;

            __tmp____Bah_fnNames[301].n = "\031\0\0\0""setNullStateBranchFlowEnd";
            __tmp____Bah_fnNames[301].p = setNullStateBranchFlowEnd;

            __tmp____Bah_fnNames[302].n = "\014\0\0\0""fixMeEnabled";
            __tmp____Bah_fnNames[302].p = fixMeEnabled;

            __tmp____Bah_fnNames[303].n = "\020\0\0\0""fixMeRegisterVar";
            __tmp____Bah_fnNames[303].p = fixMeRegisterVar;

            __tmp____Bah_fnNames[304].n = "\015\0\0\0""fixMeEndScope";
            __tmp____Bah_fnNames[304].p = fixMeEndScope;

            __tmp____Bah_fnNames[305].n = "\014\0\0\0""fixMeTestVar";
            __tmp____Bah_fnNames[305].p = fixMeTestVar;

            __tmp____Bah_fnNames[306].n = "\015\0\0\0""isStaticToken";
            __tmp____Bah_fnNames[306].p = isStaticToken;

            __tmp____Bah_fnNames[307].n = "\013\0\0\0""getLineType";
            __tmp____Bah_fnNames[307].p = getLineType;

            __tmp____Bah_fnNames[308].n = "\011\0\0\0""parseCast";
            __tmp____Bah_fnNames[308].p = parseCast;

            __tmp____Bah_fnNames[309].n = "\016\0\0\0""getDirFromFile";
            __tmp____Bah_fnNames[309].p = getDirFromFile;

            __tmp____Bah_fnNames[310].n = "\013\0\0\0""includeFile";
            __tmp____Bah_fnNames[310].p = includeFile;

            __tmp____Bah_fnNames[311].n = "\022\0\0\0""parallelObjCompile";
            __tmp____Bah_fnNames[311].p = parallelObjCompile;

            __tmp____Bah_fnNames[312].n = "\013\0\0\0""parseImport";
            __tmp____Bah_fnNames[312].p = parseImport;

            __tmp____Bah_fnNames[313].n = "\014\0\0\0""parseInclude";
            __tmp____Bah_fnNames[313].p = parseInclude;

            __tmp____Bah_fnNames[314].n = "\010\0\0\0""prePross";
            __tmp____Bah_fnNames[314].p = prePross;

            __tmp____Bah_fnNames[315].n = "\017\0\0\0""parseStructType";
            __tmp____Bah_fnNames[315].p = parseStructType;

            __tmp____Bah_fnNames[316].n = "\016\0\0\0""parseArrayType";
            __tmp____Bah_fnNames[316].p = parseArrayType;

            __tmp____Bah_fnNames[317].n = "\015\0\0\0""parsePointers";
            __tmp____Bah_fnNames[317].p = parsePointers;

            __tmp____Bah_fnNames[318].n = "\016\0\0\0""parseSerialize";
            __tmp____Bah_fnNames[318].p = parseSerialize;

            __tmp____Bah_fnNames[319].n = "\014\0\0\0""parseReflect";
            __tmp____Bah_fnNames[319].p = parseReflect;

            __tmp____Bah_fnNames[320].n = "\016\0\0\0""parseArrayDecl";
            __tmp____Bah_fnNames[320].p = parseArrayDecl;

            __tmp____Bah_fnNames[321].n = "\010\0\0\0""parseVar";
            __tmp____Bah_fnNames[321].p = parseVar;

            __tmp____Bah_fnNames[322].n = "\020\0\0\0""getCfunctionType";
            __tmp____Bah_fnNames[322].p = getCfunctionType;

            __tmp____Bah_fnNames[323].n = "\015\0\0\0""parseFnHeader";
            __tmp____Bah_fnNames[323].p = parseFnHeader;

            __tmp____Bah_fnNames[324].n = "\013\0\0\0""parseStruct";
            __tmp____Bah_fnNames[324].p = parseStruct;

            __tmp____Bah_fnNames[325].n = "\013\0\0\0""parseDefine";
            __tmp____Bah_fnNames[325].p = parseDefine;

            __tmp____Bah_fnNames[326].n = "\011\0\0\0""parseClib";
            __tmp____Bah_fnNames[326].p = parseClib;

            __tmp____Bah_fnNames[327].n = "\012\0\0\0""parseConst";
            __tmp____Bah_fnNames[327].p = parseConst;

            __tmp____Bah_fnNames[328].n = "\013\0\0\0""parseReturn";
            __tmp____Bah_fnNames[328].p = parseReturn;

            __tmp____Bah_fnNames[329].n = "\07\0\0\0""parseIf";
            __tmp____Bah_fnNames[329].p = parseIf;

            __tmp____Bah_fnNames[330].n = "\011\0\0\0""parseElse";
            __tmp____Bah_fnNames[330].p = parseElse;

            __tmp____Bah_fnNames[331].n = "\011\0\0\0""parseLine";
            __tmp____Bah_fnNames[331].p = parseLine;

            __tmp____Bah_fnNames[332].n = "\010\0\0\0""parseFor";
            __tmp____Bah_fnNames[332].p = parseFor;

            __tmp____Bah_fnNames[333].n = "\012\0\0\0""parseForOp";
            __tmp____Bah_fnNames[333].p = parseForOp;

            __tmp____Bah_fnNames[334].n = "\014\0\0\0""makeEvalFunc";
            __tmp____Bah_fnNames[334].p = makeEvalFunc;

            __tmp____Bah_fnNames[335].n = "\017\0\0\0""parsePreKeyword";
            __tmp____Bah_fnNames[335].p = parsePreKeyword;

            __tmp____Bah_fnNames[336].n = "\012\0\0\0""parseAsync";
            __tmp____Bah_fnNames[336].p = parseAsync;

            __tmp____Bah_fnNames[337].n = "\012\0\0\0""addRCPvars";
            __tmp____Bah_fnNames[337].p = addRCPvars;

            __tmp____Bah_fnNames[338].n = "\011\0\0\0""parseChan";
            __tmp____Bah_fnNames[338].p = parseChan;

            __tmp____Bah_fnNames[339].n = "\011\0\0\0""valueFunc";
            __tmp____Bah_fnNames[339].p = valueFunc;

            __tmp____Bah_fnNames[340].n = "\013\0\0\0""valueStruct";
            __tmp____Bah_fnNames[340].p = valueStruct;

            __tmp____Bah_fnNames[341].n = "\010\0\0\0""valueArr";
            __tmp____Bah_fnNames[341].p = valueArr;

            __tmp____Bah_fnNames[342].n = "\011\0\0\0""valueBool";
            __tmp____Bah_fnNames[342].p = valueBool;

            __tmp____Bah_fnNames[343].n = "\011\0\0\0""valueOper";
            __tmp____Bah_fnNames[343].p = valueOper;

            __tmp____Bah_fnNames[344].n = "\015\0\0\0""valueSendChan";
            __tmp____Bah_fnNames[344].p = valueSendChan;

            __tmp____Bah_fnNames[345].n = "\011\0\0\0""valueChan";
            __tmp____Bah_fnNames[345].p = valueChan;

            __tmp____Bah_fnNames[346].n = "\012\0\0\0""valueTuple";
            __tmp____Bah_fnNames[346].p = valueTuple;

            __tmp____Bah_fnNames[347].n = "\014\0\0\0""isSmallValue";
            __tmp____Bah_fnNames[347].p = isSmallValue;

            __tmp____Bah_fnNames[348].n = "\07\0\0\0""isValue";
            __tmp____Bah_fnNames[348].p = isValue;

            __tmp____Bah_fnNames[349].n = "\016\0\0\0""parseFnDeclare";
            __tmp____Bah_fnNames[349].p = parseFnDeclare;

            __tmp____Bah_fnNames[350].n = "\014\0\0\0""parseCapture";
            __tmp____Bah_fnNames[350].p = parseCapture;

            __tmp____Bah_fnNames[351].n = "\013\0\0\0""declareFunc";
            __tmp____Bah_fnNames[351].p = declareFunc;

            __tmp____Bah_fnNames[352].n = "\012\0\0\0""declareVar";
            __tmp____Bah_fnNames[352].p = declareVar;

            __tmp____Bah_fnNames[353].n = "\012\0\0\0""declareAll";
            __tmp____Bah_fnNames[353].p = declareAll;

            __tmp____Bah_fnNames[354].n = "\014\0\0\0""memErrHandle";
            __tmp____Bah_fnNames[354].p = memErrHandle;

            __tmp____Bah_fnNames[355].n = "\04\0\0\0""main";
            __tmp____Bah_fnNames[355].p = main;

        __Bah_fnNames->data = __tmp____Bah_fnNames;
        __Bah_fnNames->length = 356;
        
    };
    