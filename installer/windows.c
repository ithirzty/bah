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
array(char)* r = memoryAlloc(sizeof(array(char)));

r->length = 0;
r->elemSize = sizeof(char);

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

    unsigned int ____BAH_COMPILER_VAR_48 = len(r);
    __Bah_realocate_arr(r, ____BAH_COMPILER_VAR_48);
    r->data[____BAH_COMPILER_VAR_48] = by[j+4];
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

    unsigned int ____BAH_COMPILER_VAR_49 = len(r);
    __Bah_realocate_arr(r, ____BAH_COMPILER_VAR_49);
    r->data[____BAH_COMPILER_VAR_49] = s[i-ind+j+4];
};

#line 81 "/opt/bah/string.bah"
ind = 0;

#line 82 "/opt/bah/string.bah"

    unsigned int ____BAH_COMPILER_VAR_50 = len(r);
    __Bah_realocate_arr(r, ____BAH_COMPILER_VAR_50);
    r->data[____BAH_COMPILER_VAR_50] = c;
}
};

#line 85 "/opt/bah/string.bah"
register long int j = 0;

#line 85 "/opt/bah/string.bah"
for (; (j<ind); 
#line 85 "/opt/bah/string.bah"
++j) {

#line 86 "/opt/bah/string.bah"

    unsigned int ____BAH_COMPILER_VAR_51 = len(r);
    __Bah_realocate_arr(r, ____BAH_COMPILER_VAR_51);
    r->data[____BAH_COMPILER_VAR_51] = s[i-ind+j+4];
};

#line 88 "/opt/bah/string.bah"
return arrToStr(r);
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
char * ____BAH_COMPILER_VAR_52 =strReplace(this->content,nd,rl);string__set(this,____BAH_COMPILER_VAR_52);
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
struct string ____BAH_COMPILER_VAR_53 = {};
struct string needle = ____BAH_COMPILER_VAR_53;

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
struct string ____BAH_COMPILER_VAR_54 = {};
struct string r = ____BAH_COMPILER_VAR_54;

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
struct string ____BAH_COMPILER_VAR_55 = {};
struct string a = ____BAH_COMPILER_VAR_55;

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
char ____BAH_COMPILER_VAR_56[66];char* s = ____BAH_COMPILER_VAR_56;

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
char * ____BAH_COMPILER_VAR_57 =intToStr(i);struct string r = string(____BAH_COMPILER_VAR_57);

#line 370 "/opt/bah/string.bah"
return r;
};

#line 374 "/opt/bah/string.bah"
char * floatToStr(double f){

#line 375 "/opt/bah/string.bah"
char ____BAH_COMPILER_VAR_58[50];char* buff = ____BAH_COMPILER_VAR_58;

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

    unsigned int ____BAH_COMPILER_VAR_59 = len(r);
    __Bah_realocate_arr(r, ____BAH_COMPILER_VAR_59);
    r->data[____BAH_COMPILER_VAR_59] = string(cpstringSubsitute(s.content, start, end));
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
if ((start!=end)) {

#line 440 "/opt/bah/string.bah"

    unsigned int ____BAH_COMPILER_VAR_60 = len(r);
    __Bah_realocate_arr(r, ____BAH_COMPILER_VAR_60);
    r->data[____BAH_COMPILER_VAR_60] = string(cpstringSubsitute(s.content, start, end));
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
char * ____BAH_COMPILER_VAR_61 =string__str(&e);struct string tmpS = string(____BAH_COMPILER_VAR_61);

#line 458 "/opt/bah/string.bah"
if ((i!=max)) {

#line 459 "/opt/bah/string.bah"
string__append(&tmpS,sep);
}

#line 461 "/opt/bah/string.bah"
char * ____BAH_COMPILER_VAR_62 =string__str(&tmpS);string__append(&s,____BAH_COMPILER_VAR_62);

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

    unsigned int ____BAH_COMPILER_VAR_63 = len(ns);
    __Bah_realocate_arr(ns, ____BAH_COMPILER_VAR_63);
    ns->data[____BAH_COMPILER_VAR_63] = c;

#line 509 "/opt/bah/string.bah"
i = i+1;
};

#line 511 "/opt/bah/string.bah"
char * ____BAH_COMPILER_VAR_64 =arrToStr(ns);return string(____BAH_COMPILER_VAR_64);
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
struct flag* ____BAH_COMPILER_VAR_65 = memoryAlloc(sizeof(struct flag));
struct flag* f = ____BAH_COMPILER_VAR_65;

#line 29 "/opt/bah/flags.bah"
f->name = name;

#line 30 "/opt/bah/flags.bah"
f->help = help;

#line 31 "/opt/bah/flags.bah"
f->type = FLAG_TYPE_CPSTRING;

#line 32 "/opt/bah/flags.bah"
unsigned long int lf = len(this->flags);

#line 33 "/opt/bah/flags.bah"

    unsigned int ____BAH_COMPILER_VAR_66 = lf;
    __Bah_realocate_arr(this->flags, ____BAH_COMPILER_VAR_66);
    this->flags->data[____BAH_COMPILER_VAR_66] = f;
};
void flags__addBool(struct flags* this,char * name,char * help){

#line 39 "/opt/bah/flags.bah"
struct flag* ____BAH_COMPILER_VAR_67 = memoryAlloc(sizeof(struct flag));
struct flag* f = ____BAH_COMPILER_VAR_67;

#line 40 "/opt/bah/flags.bah"
f->name = name;

#line 41 "/opt/bah/flags.bah"
f->help = help;

#line 42 "/opt/bah/flags.bah"
f->type = FLAG_TYPE_BOOL;

#line 43 "/opt/bah/flags.bah"
unsigned long int lf = len(this->flags);

#line 44 "/opt/bah/flags.bah"

    unsigned int ____BAH_COMPILER_VAR_68 = lf;
    __Bah_realocate_arr(this->flags, ____BAH_COMPILER_VAR_68);
    this->flags->data[____BAH_COMPILER_VAR_68] = f;
};
void flags__addInt(struct flags* this,char * name,char * help){

#line 49 "/opt/bah/flags.bah"
struct flag* ____BAH_COMPILER_VAR_69 = memoryAlloc(sizeof(struct flag));
struct flag* f = ____BAH_COMPILER_VAR_69;

#line 50 "/opt/bah/flags.bah"
f->name = name;

#line 51 "/opt/bah/flags.bah"
f->help = help;

#line 52 "/opt/bah/flags.bah"
f->type = FLAG_TYPE_INT;

#line 53 "/opt/bah/flags.bah"
unsigned long int lf = len(this->flags);

#line 54 "/opt/bah/flags.bah"

    unsigned int ____BAH_COMPILER_VAR_70 = lf;
    __Bah_realocate_arr(this->flags, ____BAH_COMPILER_VAR_70);
    this->flags->data[____BAH_COMPILER_VAR_70] = f;
};
void flags__addFloat(struct flags* this,char * name,char * help){

#line 59 "/opt/bah/flags.bah"
struct flag* ____BAH_COMPILER_VAR_71 = memoryAlloc(sizeof(struct flag));
struct flag* f = ____BAH_COMPILER_VAR_71;

#line 60 "/opt/bah/flags.bah"
f->name = name;

#line 61 "/opt/bah/flags.bah"
f->help = help;

#line 62 "/opt/bah/flags.bah"
f->type = FLAG_TYPE_FLOAT;

#line 63 "/opt/bah/flags.bah"
unsigned long int lf = len(this->flags);

#line 64 "/opt/bah/flags.bah"

    unsigned int ____BAH_COMPILER_VAR_72 = lf;
    __Bah_realocate_arr(this->flags, ____BAH_COMPILER_VAR_72);
    this->flags->data[____BAH_COMPILER_VAR_72] = f;
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
struct flag* ____BAH_COMPILER_VAR_73 = memoryAlloc(sizeof(struct flag));
struct flag* z = ____BAH_COMPILER_VAR_73;

#line 104 "/opt/bah/flags.bah"
z->isSet = 0;

#line 105 "/opt/bah/flags.bah"
return z;
};
char * flags__get(struct flags* this,char * name){

#line 112 "/opt/bah/flags.bah"
struct string ____BAH_COMPILER_VAR_74 =string(name);struct flag* flag = flags__getFlag(this,____BAH_COMPILER_VAR_74);

#line 113 "/opt/bah/flags.bah"
return flag->content;
};
long int flags__getInt(struct flags* this,char * name){

#line 119 "/opt/bah/flags.bah"
struct string ____BAH_COMPILER_VAR_75 =string(name);struct flag* flag = flags__getFlag(this,____BAH_COMPILER_VAR_75);

#line 120 "/opt/bah/flags.bah"
if (__builtin_expect((flag->type!=FLAG_TYPE_INT), 0)) {

#line 121 "/opt/bah/flags.bah"
char** ____BAH_COMPILER_VAR_76 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_76[2] = "\015\0\0\0""' is not int.";____BAH_COMPILER_VAR_76[1] = flag->name;____BAH_COMPILER_VAR_76[0] = "\06\0\0\0""Flag '";char * ____BAH_COMPILER_VAR_77 =__Bah_multiple_concat(____BAH_COMPILER_VAR_76, 3);__BAH_panic(____BAH_COMPILER_VAR_77,"\026\0\0\0""/opt/bah/flags.bah:121");
}

#line 123 "/opt/bah/flags.bah"
return flag->cont_int;
};
double flags__getFloat(struct flags* this,char * name){

#line 129 "/opt/bah/flags.bah"
struct string ____BAH_COMPILER_VAR_78 =string(name);struct flag* flag = flags__getFlag(this,____BAH_COMPILER_VAR_78);

#line 130 "/opt/bah/flags.bah"
if (__builtin_expect((flag->type!=FLAG_TYPE_FLOAT), 0)) {

#line 131 "/opt/bah/flags.bah"
char** ____BAH_COMPILER_VAR_79 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_79[2] = "\017\0\0\0""' is not float.";____BAH_COMPILER_VAR_79[1] = flag->name;____BAH_COMPILER_VAR_79[0] = "\06\0\0\0""Flag '";char * ____BAH_COMPILER_VAR_80 =__Bah_multiple_concat(____BAH_COMPILER_VAR_79, 3);__BAH_panic(____BAH_COMPILER_VAR_80,"\026\0\0\0""/opt/bah/flags.bah:131");
}

#line 133 "/opt/bah/flags.bah"
return flag->cont_float;
};
long int flags__isSet(struct flags* this,char * name){

#line 139 "/opt/bah/flags.bah"
struct string ____BAH_COMPILER_VAR_81 =string(name);struct flag* flag = flags__getFlag(this,____BAH_COMPILER_VAR_81);

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
char * ____BAH_COMPILER_VAR_82 =string__str(&argName);currentFlag->cont_int = strToInt(____BAH_COMPILER_VAR_82);
}

#line 155 "/opt/bah/flags.bah"
else if ((currentFlag->type==FLAG_TYPE_FLOAT)) {

#line 156 "/opt/bah/flags.bah"
char * ____BAH_COMPILER_VAR_83 =string__str(&argName);currentFlag->cont_float = strToFloat(____BAH_COMPILER_VAR_83);
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
char * date = memoryAlloc(1024);

#line 33 "/opt/bah/time.bah"
strftime(cStr(date),1024,cStr(a),lt);

#line 34 "/opt/bah/time.bah"
return date;
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
struct timespec ____BAH_COMPILER_VAR_84 = {};
struct timespec ts = ____BAH_COMPILER_VAR_84;

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
memcpy(s+off+cpstringLenSize,cStr(this->str),this->lCount+1);

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
char * s = memoryAllocSTR(this->totalLen+1);

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
struct rope* ____BAH_COMPILER_VAR_85 = memoryAlloc(sizeof(struct rope));
struct rope* tmp = ____BAH_COMPILER_VAR_85;

#line 46 "/opt/bah/rope.bah"
tmp->left = this;

#line 47 "/opt/bah/rope.bah"
tmp->right = root2;

#line 48 "/opt/bah/rope.bah"
tmp->totalLen = this->totalLen+root2->totalLen;

#line 49 "/opt/bah/rope.bah"
tmp->str = null;

#line 50 "/opt/bah/rope.bah"
return tmp;
};

#line 59 "/opt/bah/rope.bah"
struct rope* createRopeStructure(struct rope* par,char * a,long int l,long int r){

#line 60 "/opt/bah/rope.bah"
struct rope* ____BAH_COMPILER_VAR_86 = memoryAlloc(sizeof(struct rope));
struct rope* tmp = ____BAH_COMPILER_VAR_86;

#line 62 "/opt/bah/rope.bah"
tmp->left = null;

#line 63 "/opt/bah/rope.bah"
tmp->right = null;

#line 67 "/opt/bah/rope.bah"
if ((r-l>ROPE_LEAF_LEN)) {

#line 68 "/opt/bah/rope.bah"
tmp->str = null;

#line 69 "/opt/bah/rope.bah"
tmp->lCount = r-l;

#line 70 "/opt/bah/rope.bah"
tmp->lCount = tmp->lCount/2;

#line 71 "/opt/bah/rope.bah"
struct rope* node = tmp;

#line 72 "/opt/bah/rope.bah"
long int m = l+r;

#line 73 "/opt/bah/rope.bah"
m = m/2;

#line 74 "/opt/bah/rope.bah"
node->left = createRopeStructure(node,a,l,m);

#line 75 "/opt/bah/rope.bah"
node->right = createRopeStructure(node,a,m+1,r);
}

#line 76 "/opt/bah/rope.bah"
else {

#line 77 "/opt/bah/rope.bah"
struct rope* node = tmp;

#line 78 "/opt/bah/rope.bah"
tmp->lCount = r-l;

#line 79 "/opt/bah/rope.bah"
tmp->str = cpstringSubsitute(a, l, r+1);
}

#line 81 "/opt/bah/rope.bah"
return tmp;
};

#line 87 "/opt/bah/rope.bah"
long int ropeSet(struct rope* r,char * a){

#line 88 "/opt/bah/rope.bah"
unsigned long int n1 = strlen(a);

#line 89 "/opt/bah/rope.bah"
unsigned long int diff = n1-r->totalLen;

#line 90 "/opt/bah/rope.bah"
struct rope* nr = createRopeStructure(null,a,0,n1-1);

#line 91 "/opt/bah/rope.bah"
nr->totalLen = n1;

#line 92 "/opt/bah/rope.bah"
nr->len = n1;

#line 93 "/opt/bah/rope.bah"
*r = *nr;

#line 94 "/opt/bah/rope.bah"
return diff;
};

#line 98 "/opt/bah/rope.bah"
struct rope* concatenateRopes(struct rope* root1,struct rope* root2){

#line 99 "/opt/bah/rope.bah"
int n1 = root1->len;

#line 100 "/opt/bah/rope.bah"
struct rope* ____BAH_COMPILER_VAR_87 = memoryAlloc(sizeof(struct rope));
struct rope* tmp = ____BAH_COMPILER_VAR_87;

#line 101 "/opt/bah/rope.bah"
tmp->left = root1;

#line 102 "/opt/bah/rope.bah"
tmp->right = root2;

#line 103 "/opt/bah/rope.bah"
tmp->totalLen = root1->totalLen+root2->totalLen;

#line 104 "/opt/bah/rope.bah"
tmp->str = null;

#line 105 "/opt/bah/rope.bah"
return tmp;
};

#line 109 "/opt/bah/rope.bah"
struct rope* rope(char * a){

#line 110 "/opt/bah/rope.bah"
unsigned long int n1 = strlen(a);

#line 111 "/opt/bah/rope.bah"
struct rope* r = createRopeStructure(null,a,0,n1-1);

#line 112 "/opt/bah/rope.bah"
r->totalLen = n1;

#line 113 "/opt/bah/rope.bah"
r->len = n1;

#line 114 "/opt/bah/rope.bah"
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
char** ____BAH_COMPILER_VAR_88 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_88[1] = "\014\0\0\0"" 2>/dev/null";____BAH_COMPILER_VAR_88[0] = cm;char * ____BAH_COMPILER_VAR_89 =__Bah_multiple_concat(____BAH_COMPILER_VAR_88, 2);cm = ____BAH_COMPILER_VAR_89;
}

#line 28 "/opt/bah/exec.bah"
else {

#line 29 "/opt/bah/exec.bah"
char** ____BAH_COMPILER_VAR_90 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_90[1] = "\05\0\0\0"" 2>&1";____BAH_COMPILER_VAR_90[0] = cm;char * ____BAH_COMPILER_VAR_91 =__Bah_multiple_concat(____BAH_COMPILER_VAR_90, 2);cm = ____BAH_COMPILER_VAR_91;
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
char** ____BAH_COMPILER_VAR_92 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_92[1] = "\014\0\0\0"" 2>/dev/null";____BAH_COMPILER_VAR_92[0] = cm;char * ____BAH_COMPILER_VAR_93 =__Bah_multiple_concat(____BAH_COMPILER_VAR_92, 2);cm = ____BAH_COMPILER_VAR_93;
}

#line 66 "/opt/bah/exec.bah"
else {

#line 67 "/opt/bah/exec.bah"
char** ____BAH_COMPILER_VAR_94 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_94[1] = "\05\0\0\0"" 2>&1";____BAH_COMPILER_VAR_94[0] = cm;char * ____BAH_COMPILER_VAR_95 =__Bah_multiple_concat(____BAH_COMPILER_VAR_94, 2);cm = ____BAH_COMPILER_VAR_95;
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
char ____BAH_COMPILER_VAR_96[1024];char* buff = ____BAH_COMPILER_VAR_96;

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

    unsigned int ____BAH_COMPILER_VAR_97 = len(arr);
    __Bah_realocate_arr(arr, ____BAH_COMPILER_VAR_97);
    arr->data[____BAH_COMPILER_VAR_97] = buff[i];
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
struct command ____BAH_COMPILER_VAR_98 = {};
____BAH_COMPILER_VAR_98.error = true;
struct command cmd = ____BAH_COMPILER_VAR_98;

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

    unsigned int ____BAH_COMPILER_VAR_99 = 0;
    __Bah_realocate_arr(nArgs, ____BAH_COMPILER_VAR_99);
    nArgs->data[____BAH_COMPILER_VAR_99] = s;

#line 109 "/opt/bah/exec.bah"
register long int i = 0;

#line 109 "/opt/bah/exec.bah"
while ((i<len(args))) {

#line 110 "/opt/bah/exec.bah"

    unsigned int ____BAH_COMPILER_VAR_100 = i+1;
    __Bah_realocate_arr(nArgs, ____BAH_COMPILER_VAR_100);
    nArgs->data[____BAH_COMPILER_VAR_100] = args->data[i];

#line 111 "/opt/bah/exec.bah"
i = i+1;
};

#line 113 "/opt/bah/exec.bah"

    unsigned int ____BAH_COMPILER_VAR_101 = i+2;
    __Bah_realocate_arr(nArgs, ____BAH_COMPILER_VAR_101);
    nArgs->data[____BAH_COMPILER_VAR_101] = (char *)0;

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
struct reflectElement ____BAH_COMPILER_VAR_102 = {};
____BAH_COMPILER_VAR_102.structLayout = memoryAlloc(sizeof(array(struct reflectElement)));
            ____BAH_COMPILER_VAR_102.structLayout->length = 0;
            ____BAH_COMPILER_VAR_102.structLayout->elemSize = sizeof(struct reflectElement);
            struct reflectElement re = ____BAH_COMPILER_VAR_102;

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
struct reflectElement ____BAH_COMPILER_VAR_103 = {};
____BAH_COMPILER_VAR_103.structLayout = memoryAlloc(sizeof(array(struct reflectElement)));
            ____BAH_COMPILER_VAR_103.structLayout->length = 0;
            ____BAH_COMPILER_VAR_103.structLayout->elemSize = sizeof(struct reflectElement);
            struct reflectElement ns = ____BAH_COMPILER_VAR_103;

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

    unsigned int ____BAH_COMPILER_VAR_104 = j-1;
    __Bah_realocate_arr(nk, ____BAH_COMPILER_VAR_104);
    nk->data[____BAH_COMPILER_VAR_104] = c;

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
char * ____BAH_COMPILER_VAR_105 =jsonElement__str(this);*ep = strToInt(____BAH_COMPILER_VAR_105);
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
char * ____BAH_COMPILER_VAR_106 =jsonElement__str(this);*ep = strToFloat(____BAH_COMPILER_VAR_106);
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
char * ____BAH_COMPILER_VAR_107 =jsonElement__str(c);
    unsigned int ____BAH_COMPILER_VAR_108 = i;
    __Bah_realocate_arr(arr, ____BAH_COMPILER_VAR_108);
    arr->data[____BAH_COMPILER_VAR_108] = strToInt(____BAH_COMPILER_VAR_107);

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
char * ____BAH_COMPILER_VAR_109 =jsonElement__str(c);
    unsigned int ____BAH_COMPILER_VAR_110 = i;
    __Bah_realocate_arr(arr, ____BAH_COMPILER_VAR_110);
    arr->data[____BAH_COMPILER_VAR_110] = strToFloat(____BAH_COMPILER_VAR_109);

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

    unsigned int ____BAH_COMPILER_VAR_111 = i;
    __Bah_realocate_arr(arr, ____BAH_COMPILER_VAR_111);
    arr->data[____BAH_COMPILER_VAR_111] = jsonElement__str(c);

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

    unsigned int ____BAH_COMPILER_VAR_112 = i;
    __Bah_realocate_arr(arr, ____BAH_COMPILER_VAR_112);
    arr->data[____BAH_COMPILER_VAR_112] = ne;

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

    unsigned int ____BAH_COMPILER_VAR_113 = j;
    __Bah_realocate_arr(ae->structLayout, ____BAH_COMPILER_VAR_113);
    ae->structLayout->data[____BAH_COMPILER_VAR_113] = m;
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
char * ____BAH_COMPILER_VAR_114 =string__str(&k);m->set(m,____BAH_COMPILER_VAR_114,v);
}

#line 189 "/opt/bah/json.bah"
else {

#line 190 "/opt/bah/json.bah"
struct mapWrapper* m = *p;

#line 191 "/opt/bah/json.bah"
char * ____BAH_COMPILER_VAR_115 =string__str(&k);m->set(m,____BAH_COMPILER_VAR_115,&v);
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
struct jsonElement* ____BAH_COMPILER_VAR_116 = memoryAlloc(sizeof(struct jsonElement));
____BAH_COMPILER_VAR_116->children = memoryAlloc(sizeof(array(struct jsonElement*)));
            ____BAH_COMPILER_VAR_116->children->length = 0;
            ____BAH_COMPILER_VAR_116->children->elemSize = sizeof(struct jsonElement*);
            ____BAH_COMPILER_VAR_116->content = s;
____BAH_COMPILER_VAR_116->from = i;
____BAH_COMPILER_VAR_116->to = l;
struct jsonElement* j = ____BAH_COMPILER_VAR_116;

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

    unsigned int ____BAH_COMPILER_VAR_117 = len(j->children);
    __Bah_realocate_arr(j->children, ____BAH_COMPILER_VAR_117);
    j->children->data[____BAH_COMPILER_VAR_117] = child;

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
char** ____BAH_COMPILER_VAR_118 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_118[4] = "\01\0\0\0"")";____BAH_COMPILER_VAR_118[3] = intToStr(i);____BAH_COMPILER_VAR_118[2] = "\010\0\0\0"") (pos: ";____BAH_COMPILER_VAR_118[1] = charToString(s[i+4]);____BAH_COMPILER_VAR_118[0] = "\045\0\0\0""json: expected array separator (got: ";char * ____BAH_COMPILER_VAR_119 =__Bah_multiple_concat(____BAH_COMPILER_VAR_118, 5);jError = ____BAH_COMPILER_VAR_119;

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
char** ____BAH_COMPILER_VAR_120 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_120[2] = "\01\0\0\0"")";____BAH_COMPILER_VAR_120[1] = intToStr(i);____BAH_COMPILER_VAR_120[0] = "\047\0\0\0""json: expected string as map key (pos: ";char * ____BAH_COMPILER_VAR_121 =__Bah_multiple_concat(____BAH_COMPILER_VAR_120, 3);jError = ____BAH_COMPILER_VAR_121;

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
char** ____BAH_COMPILER_VAR_122 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_122[4] = "\01\0\0\0"")";____BAH_COMPILER_VAR_122[3] = intToStr(i);____BAH_COMPILER_VAR_122[2] = "\010\0\0\0"") (pos: ";____BAH_COMPILER_VAR_122[1] = intToStr((long int)s[i+4]);____BAH_COMPILER_VAR_122[0] = "\055\0\0\0""json: expected : between key and value (got: ";char * ____BAH_COMPILER_VAR_123 =__Bah_multiple_concat(____BAH_COMPILER_VAR_122, 5);jError = ____BAH_COMPILER_VAR_123;

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

    unsigned int ____BAH_COMPILER_VAR_124 = len(j->children);
    __Bah_realocate_arr(j->children, ____BAH_COMPILER_VAR_124);
    j->children->data[____BAH_COMPILER_VAR_124] = child;

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
char** ____BAH_COMPILER_VAR_125 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_125[2] = "\01\0\0\0"")";____BAH_COMPILER_VAR_125[1] = intToStr(i);____BAH_COMPILER_VAR_125[0] = "\043\0\0\0""json: expected map separator (pos: ";char * ____BAH_COMPILER_VAR_126 =__Bah_multiple_concat(____BAH_COMPILER_VAR_125, 3);jError = ____BAH_COMPILER_VAR_126;

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

    unsigned int ____BAH_COMPILER_VAR_127 = len(mem);
    __Bah_realocate_arr(mem, ____BAH_COMPILER_VAR_127);
    mem->data[____BAH_COMPILER_VAR_127] = (char)13;
}

#line 340 "/opt/bah/json.bah"
else if ((s[i+1+4]==110)) {

#line 341 "/opt/bah/json.bah"

    unsigned int ____BAH_COMPILER_VAR_128 = len(mem);
    __Bah_realocate_arr(mem, ____BAH_COMPILER_VAR_128);
    mem->data[____BAH_COMPILER_VAR_128] = (char)10;
}

#line 342 "/opt/bah/json.bah"
else {

#line 343 "/opt/bah/json.bah"

    unsigned int ____BAH_COMPILER_VAR_129 = len(mem);
    __Bah_realocate_arr(mem, ____BAH_COMPILER_VAR_129);
    mem->data[____BAH_COMPILER_VAR_129] = s[i+1+4];
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

    unsigned int ____BAH_COMPILER_VAR_130 = len(mem);
    __Bah_realocate_arr(mem, ____BAH_COMPILER_VAR_130);
    mem->data[____BAH_COMPILER_VAR_130] = s[i+4];
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
struct strBuilder ____BAH_COMPILER_VAR_131 = {};
strBuilder___init(&____BAH_COMPILER_VAR_131);
struct strBuilder r = ____BAH_COMPILER_VAR_131;

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
char** ____BAH_COMPILER_VAR_132 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_132[1] = "\01\0\0\0""\t";____BAH_COMPILER_VAR_132[0] = tabsStr;char * ____BAH_COMPILER_VAR_133 =__Bah_multiple_concat(____BAH_COMPILER_VAR_132, 2);tabsStr = ____BAH_COMPILER_VAR_133;

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
char** ____BAH_COMPILER_VAR_134 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_134[6] = "\02\0\0\0"",\n";____BAH_COMPILER_VAR_134[5] = oldToJson__inner(m,true,tabs);____BAH_COMPILER_VAR_134[4] = "\03\0\0\0""\": ";____BAH_COMPILER_VAR_134[3] = m.name;____BAH_COMPILER_VAR_134[2] = "\01\0\0\0""\"";____BAH_COMPILER_VAR_134[1] = tabsStr;____BAH_COMPILER_VAR_134[0] = s;char * ____BAH_COMPILER_VAR_135 =__Bah_multiple_concat(____BAH_COMPILER_VAR_134, 7);s = ____BAH_COMPILER_VAR_135;
}

#line 467 "/opt/bah/json.bah"
else {

#line 468 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_136 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_136[6] = "\01\0\0\0""\n";____BAH_COMPILER_VAR_136[5] = oldToJson__inner(m,true,tabs);____BAH_COMPILER_VAR_136[4] = "\03\0\0\0""\": ";____BAH_COMPILER_VAR_136[3] = m.name;____BAH_COMPILER_VAR_136[2] = "\01\0\0\0""\"";____BAH_COMPILER_VAR_136[1] = tabsStr;____BAH_COMPILER_VAR_136[0] = s;char * ____BAH_COMPILER_VAR_137 =__Bah_multiple_concat(____BAH_COMPILER_VAR_136, 7);s = ____BAH_COMPILER_VAR_137;
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
char** ____BAH_COMPILER_VAR_138 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_138[1] = "\01\0\0\0""\t";____BAH_COMPILER_VAR_138[0] = tabsStr;char * ____BAH_COMPILER_VAR_139 =__Bah_multiple_concat(____BAH_COMPILER_VAR_138, 2);tabsStr = ____BAH_COMPILER_VAR_139;

#line 475 "/opt/bah/json.bah"
i = i+1;
};

#line 477 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_140 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_140[2] = "\01\0\0\0""}";____BAH_COMPILER_VAR_140[1] = tabsStr;____BAH_COMPILER_VAR_140[0] = s;char * ____BAH_COMPILER_VAR_141 =__Bah_multiple_concat(____BAH_COMPILER_VAR_140, 3);s = ____BAH_COMPILER_VAR_141;

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
char** ____BAH_COMPILER_VAR_142 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_142[2] = "\01\0\0\0""\"";____BAH_COMPILER_VAR_142[1] = jsonEscapeStr(s);____BAH_COMPILER_VAR_142[0] = "\01\0\0\0""\"";char * ____BAH_COMPILER_VAR_143 =__Bah_multiple_concat(____BAH_COMPILER_VAR_142, 3);return ____BAH_COMPILER_VAR_143;
}

#line 489 "/opt/bah/json.bah"
else {

#line 490 "/opt/bah/json.bah"
char ** sp = e.value;

#line 491 "/opt/bah/json.bah"
char * s = *sp;

#line 492 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_144 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_144[2] = "\01\0\0\0""\"";____BAH_COMPILER_VAR_144[1] = jsonEscapeStr(s);____BAH_COMPILER_VAR_144[0] = "\01\0\0\0""\"";char * ____BAH_COMPILER_VAR_145 =__Bah_multiple_concat(____BAH_COMPILER_VAR_144, 3);return ____BAH_COMPILER_VAR_145;
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
char** ____BAH_COMPILER_VAR_146 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_146[1] = intToStr(arr->data[i]);____BAH_COMPILER_VAR_146[0] = s;char * ____BAH_COMPILER_VAR_147 =__Bah_multiple_concat(____BAH_COMPILER_VAR_146, 2);s = ____BAH_COMPILER_VAR_147;

#line 512 "/opt/bah/json.bah"
i = i+1;

#line 513 "/opt/bah/json.bah"
if ((i<len(arr))) {

#line 514 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_148 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_148[1] = "\01\0\0\0"",";____BAH_COMPILER_VAR_148[0] = s;char * ____BAH_COMPILER_VAR_149 =__Bah_multiple_concat(____BAH_COMPILER_VAR_148, 2);s = ____BAH_COMPILER_VAR_149;
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
char** ____BAH_COMPILER_VAR_150 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_150[1] = floatToStr(arr->data[i]);____BAH_COMPILER_VAR_150[0] = s;char * ____BAH_COMPILER_VAR_151 =__Bah_multiple_concat(____BAH_COMPILER_VAR_150, 2);s = ____BAH_COMPILER_VAR_151;

#line 523 "/opt/bah/json.bah"
i = i+1;

#line 524 "/opt/bah/json.bah"
if ((i<len(arr))) {

#line 525 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_152 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_152[1] = "\01\0\0\0"",";____BAH_COMPILER_VAR_152[0] = s;char * ____BAH_COMPILER_VAR_153 =__Bah_multiple_concat(____BAH_COMPILER_VAR_152, 2);s = ____BAH_COMPILER_VAR_153;
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
char** ____BAH_COMPILER_VAR_154 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_154[1] = "\01\0\0\0""\n";____BAH_COMPILER_VAR_154[0] = s;char * ____BAH_COMPILER_VAR_155 =__Bah_multiple_concat(____BAH_COMPILER_VAR_154, 2);s = ____BAH_COMPILER_VAR_155;

#line 533 "/opt/bah/json.bah"
register long int i = 0;

#line 533 "/opt/bah/json.bah"
while ((i<len(arr))) {

#line 534 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_156 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_156[3] = "\01\0\0\0""\"";____BAH_COMPILER_VAR_156[2] = jsonEscapeStr(arr->data[i]);____BAH_COMPILER_VAR_156[1] = "\01\0\0\0""\"";____BAH_COMPILER_VAR_156[0] = s;char * ____BAH_COMPILER_VAR_157 =__Bah_multiple_concat(____BAH_COMPILER_VAR_156, 4);s = ____BAH_COMPILER_VAR_157;

#line 535 "/opt/bah/json.bah"
i = i+1;

#line 536 "/opt/bah/json.bah"
if ((i<len(arr))) {

#line 537 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_158 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_158[1] = "\02\0\0\0"",\n";____BAH_COMPILER_VAR_158[0] = s;char * ____BAH_COMPILER_VAR_159 =__Bah_multiple_concat(____BAH_COMPILER_VAR_158, 2);s = ____BAH_COMPILER_VAR_159;
}

#line 538 "/opt/bah/json.bah"
else {

#line 539 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_160 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_160[1] = "\01\0\0\0""\n";____BAH_COMPILER_VAR_160[0] = s;char * ____BAH_COMPILER_VAR_161 =__Bah_multiple_concat(____BAH_COMPILER_VAR_160, 2);s = ____BAH_COMPILER_VAR_161;
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

    unsigned int ____BAH_COMPILER_VAR_162 = j;
    __Bah_realocate_arr(ae->structLayout, ____BAH_COMPILER_VAR_162);
    ae->structLayout->data[____BAH_COMPILER_VAR_162] = m;

#line 558 "/opt/bah/json.bah"
j = j+1;
};

#line 560 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_163 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_163[1] = oldToJson__inner(*ae,false,tabs);____BAH_COMPILER_VAR_163[0] = s;char * ____BAH_COMPILER_VAR_164 =__Bah_multiple_concat(____BAH_COMPILER_VAR_163, 2);s = ____BAH_COMPILER_VAR_164;

#line 561 "/opt/bah/json.bah"
i = i+1;

#line 562 "/opt/bah/json.bah"
if ((i<len(arr))) {

#line 563 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_165 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_165[1] = "\02\0\0\0"",\n";____BAH_COMPILER_VAR_165[0] = s;char * ____BAH_COMPILER_VAR_166 =__Bah_multiple_concat(____BAH_COMPILER_VAR_165, 2);s = ____BAH_COMPILER_VAR_166;
}

#line 564 "/opt/bah/json.bah"
else {

#line 565 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_167 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_167[1] = "\01\0\0\0""\n";____BAH_COMPILER_VAR_167[0] = s;char * ____BAH_COMPILER_VAR_168 =__Bah_multiple_concat(____BAH_COMPILER_VAR_167, 2);s = ____BAH_COMPILER_VAR_168;
}
};
}

#line 569 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_169 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_169[1] = "\01\0\0\0""]";____BAH_COMPILER_VAR_169[0] = s;char * ____BAH_COMPILER_VAR_170 =__Bah_multiple_concat(____BAH_COMPILER_VAR_169, 2);s = ____BAH_COMPILER_VAR_170;

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
char** ____BAH_COMPILER_VAR_171 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_171[6] = "\02\0\0\0"").";____BAH_COMPILER_VAR_171[5] = e.name;____BAH_COMPILER_VAR_171[4] = "\051\0\0\0"" but a pointer is required, try: toJson(&";____BAH_COMPILER_VAR_171[3] = e.type;____BAH_COMPILER_VAR_171[2] = "\012\0\0\0"") of type ";____BAH_COMPILER_VAR_171[1] = e.name;____BAH_COMPILER_VAR_171[0] = "\07\0\0\0""toJson(";char * ____BAH_COMPILER_VAR_172 =__Bah_multiple_concat(____BAH_COMPILER_VAR_171, 7);__BAH_panic(____BAH_COMPILER_VAR_172,"\025\0\0\0""/opt/bah/json.bah:590");
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
char** ____BAH_COMPILER_VAR_173 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_173[1] = "\01\0\0\0""*";____BAH_COMPILER_VAR_173[0] = m.arrayElem->type;char * ____BAH_COMPILER_VAR_174 =__Bah_multiple_concat(____BAH_COMPILER_VAR_173, 2);m.arrayElem->type = ____BAH_COMPILER_VAR_174;
}

#line 618 "/opt/bah/json.bah"
else if ((m.type[strlen(m.type)-1+4]!=42)) {

#line 619 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_175 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_175[1] = "\01\0\0\0""*";____BAH_COMPILER_VAR_175[0] = m.type;char * ____BAH_COMPILER_VAR_176 =__Bah_multiple_concat(____BAH_COMPILER_VAR_175, 2);m.type = ____BAH_COMPILER_VAR_176;
}

#line 621 "/opt/bah/json.bah"
m.value = reflectElement__calculateOffset(&m,e.value);

#line 622 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_177 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_177[3] = toJson(m);____BAH_COMPILER_VAR_177[2] = "\03\0\0\0""\": ";____BAH_COMPILER_VAR_177[1] = m.name;____BAH_COMPILER_VAR_177[0] = "\01\0\0\0""\"";char * ____BAH_COMPILER_VAR_178 =__Bah_multiple_concat(____BAH_COMPILER_VAR_177, 4);char** ____BAH_COMPILER_VAR_179 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_179[1] = ____BAH_COMPILER_VAR_178;____BAH_COMPILER_VAR_179[0] = s;char * ____BAH_COMPILER_VAR_180 =__Bah_multiple_concat(____BAH_COMPILER_VAR_179, 2);s = ____BAH_COMPILER_VAR_180;

#line 623 "/opt/bah/json.bah"
if ((i+1<len(e.structLayout))) {

#line 624 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_181 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_181[1] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_181[0] = s;char * ____BAH_COMPILER_VAR_182 =__Bah_multiple_concat(____BAH_COMPILER_VAR_181, 2);s = ____BAH_COMPILER_VAR_182;
}
};

#line 627 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_183 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_183[1] = "\01\0\0\0""}";____BAH_COMPILER_VAR_183[0] = s;char * ____BAH_COMPILER_VAR_184 =__Bah_multiple_concat(____BAH_COMPILER_VAR_183, 2);s = ____BAH_COMPILER_VAR_184;

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
char** ____BAH_COMPILER_VAR_185 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_185[1] = "\01\0\0\0""*";____BAH_COMPILER_VAR_185[0] = ae->type;char * ____BAH_COMPILER_VAR_186 =__Bah_multiple_concat(____BAH_COMPILER_VAR_185, 2);ae->type = ____BAH_COMPILER_VAR_186;
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
char** ____BAH_COMPILER_VAR_187 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_187[1] = toJson(m);____BAH_COMPILER_VAR_187[0] = s;char * ____BAH_COMPILER_VAR_188 =__Bah_multiple_concat(____BAH_COMPILER_VAR_187, 2);s = ____BAH_COMPILER_VAR_188;

#line 649 "/opt/bah/json.bah"
if ((i+1<l)) {

#line 650 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_189 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_189[1] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_189[0] = s;char * ____BAH_COMPILER_VAR_190 =__Bah_multiple_concat(____BAH_COMPILER_VAR_189, 2);s = ____BAH_COMPILER_VAR_190;
}
};

#line 653 "/opt/bah/json.bah"
char** ____BAH_COMPILER_VAR_191 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_191[1] = "\01\0\0\0""]";____BAH_COMPILER_VAR_191[0] = s;char * ____BAH_COMPILER_VAR_192 =__Bah_multiple_concat(____BAH_COMPILER_VAR_191, 2);s = ____BAH_COMPILER_VAR_192;

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
char** ____BAH_COMPILER_VAR_193 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_193[2] = "\01\0\0\0""\"";____BAH_COMPILER_VAR_193[1] = jsonEscapeStr(*s);____BAH_COMPILER_VAR_193[0] = "\01\0\0\0""\"";char * ____BAH_COMPILER_VAR_194 =__Bah_multiple_concat(____BAH_COMPILER_VAR_193, 3);return ____BAH_COMPILER_VAR_194;
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
char** ____BAH_COMPILER_VAR_195 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_195[2] = "\01\0\0\0""\"";____BAH_COMPILER_VAR_195[1] = charToString(*c);____BAH_COMPILER_VAR_195[0] = "\01\0\0\0""\"";char * ____BAH_COMPILER_VAR_196 =__Bah_multiple_concat(____BAH_COMPILER_VAR_195, 3);return ____BAH_COMPILER_VAR_196;
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
#define BAH_VERSION "\020\0\0\0""v1.3 (build 136)"

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
char ____BAH_COMPILER_VAR_198(array(char *)* arr, char * el) {
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
struct Tok ____BAH_COMPILER_VAR_197 = {};
____BAH_COMPILER_VAR_197.cont = "\0\0\0\0""";
____BAH_COMPILER_VAR_197.ogCont = "\0\0\0\0""";
____BAH_COMPILER_VAR_197.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_197.line = 1;
____BAH_COMPILER_VAR_197.begLine = 1;
____BAH_COMPILER_VAR_197.bahType = "\0\0\0\0""";
struct Tok t = ____BAH_COMPILER_VAR_197;

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
if ((type==TOKEN_TYPE_VAR)&&____BAH_COMPILER_VAR_198(keywords, t.cont)) {

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
char** ____BAH_COMPILER_VAR_199 = alloca(8 * sizeof(char*));____BAH_COMPILER_VAR_199[7] = msg;____BAH_COMPILER_VAR_199[6] = "\06\0\0\0""\n\e[0m\n";____BAH_COMPILER_VAR_199[5] = posStr;____BAH_COMPILER_VAR_199[4] = "\01\0\0\0"":";____BAH_COMPILER_VAR_199[3] = lineStr;____BAH_COMPILER_VAR_199[2] = "\01\0\0\0"":";____BAH_COMPILER_VAR_199[1] = compilerState.currentFile;____BAH_COMPILER_VAR_199[0] = "\031\0\0\0""\e[1;31m[LEXER-ERROR]\e[0m ";char * ____BAH_COMPILER_VAR_200 =__Bah_multiple_concat(____BAH_COMPILER_VAR_199, 8);println(____BAH_COMPILER_VAR_200);

#line 80 "/home/alois/Documents/bah-bah/src/lexer.bah"
exit(1);
};

#line 83 "/home/alois/Documents/bah-bah/src/lexer.bah"
char ____BAH_COMPILER_VAR_217(array(char)* arr, char el) {
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
char ____BAH_COMPILER_VAR_220(array(char)* arr, char el) {
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
char ____BAH_COMPILER_VAR_226(array(char)* arr, char el) {
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

    unsigned int ____BAH_COMPILER_VAR_201 = 0;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_201);
    memory->data[____BAH_COMPILER_VAR_201] = c;

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

    unsigned int ____BAH_COMPILER_VAR_202 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_202);
    memory->data[____BAH_COMPILER_VAR_202] = (char)92;

#line 134 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_203 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_203);
    memory->data[____BAH_COMPILER_VAR_203] = s[i+1+4];

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

    unsigned int ____BAH_COMPILER_VAR_204 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_204);
    memory->data[____BAH_COMPILER_VAR_204] = c;

#line 145 "/home/alois/Documents/bah-bah/src/lexer.bah"
break;
}

#line 148 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((c==(char)10)) {

#line 149 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_205 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_205);
    memory->data[____BAH_COMPILER_VAR_205] = (char)92;

#line 150 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_206 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_206);
    memory->data[____BAH_COMPILER_VAR_206] = 110;

#line 151 "/home/alois/Documents/bah-bah/src/lexer.bah"
++lineNb;

#line 152 "/home/alois/Documents/bah-bah/src/lexer.bah"
continue;
}

#line 154 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_207 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_207);
    memory->data[____BAH_COMPILER_VAR_207] = c;
};

#line 156 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_208 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_208);
    tokens->data[____BAH_COMPILER_VAR_208] = makeToken(pos,lineNb,memory,TOKEN_TYPE_STR);

#line 157 "/home/alois/Documents/bah-bah/src/lexer.bah"
struct Tok lt = tokens->data[len(tokens)-1];

#line 158 "/home/alois/Documents/bah-bah/src/lexer.bah"
lt.begLine = begLine;

#line 159 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_209 = len(tokens)-1;
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_209);
    tokens->data[____BAH_COMPILER_VAR_209] = lt;
}

#line 160 "/home/alois/Documents/bah-bah/src/lexer.bah"
else if (isNumber(c)||isMinus(c,nc)) {

#line 162 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_210 = 0;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_210);
    memory->data[____BAH_COMPILER_VAR_210] = c;

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

    unsigned int ____BAH_COMPILER_VAR_211 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_211);
    memory->data[____BAH_COMPILER_VAR_211] = c;
};

#line 192 "/home/alois/Documents/bah-bah/src/lexer.bah"
--i;

#line 193 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_212 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_212);
    tokens->data[____BAH_COMPILER_VAR_212] = makeToken(pos,lineNb,memory,currentType);
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

    unsigned int ____BAH_COMPILER_VAR_213 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_213);
    tokens->data[____BAH_COMPILER_VAR_213] = makeToken(i-1,lineNb,memory,TOKEN_TYPE_CHAR);
}

#line 206 "/home/alois/Documents/bah-bah/src/lexer.bah"
else if ((c==(char)35)) {

#line 208 "/home/alois/Documents/bah-bah/src/lexer.bah"
long int pos = i;

#line 209 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_214 = 0;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_214);
    memory->data[____BAH_COMPILER_VAR_214] = c;

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

    unsigned int ____BAH_COMPILER_VAR_215 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_215);
    memory->data[____BAH_COMPILER_VAR_215] = c;
};

#line 218 "/home/alois/Documents/bah-bah/src/lexer.bah"
--i;

#line 219 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_216 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_216);
    tokens->data[____BAH_COMPILER_VAR_216] = makeToken(pos,lineNb,memory,TOKEN_TYPE_KEYWORD);
}

#line 220 "/home/alois/Documents/bah-bah/src/lexer.bah"
else if (____BAH_COMPILER_VAR_217(enclavers, c)) {

#line 222 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_218 = 0;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_218);
    memory->data[____BAH_COMPILER_VAR_218] = c;

#line 223 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_219 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_219);
    tokens->data[____BAH_COMPILER_VAR_219] = makeToken(i,lineNb,memory,TOKEN_TYPE_ENCL);
}

#line 224 "/home/alois/Documents/bah-bah/src/lexer.bah"
else if (____BAH_COMPILER_VAR_220(syntaxes, c)) {

#line 228 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((c==60)) {

#line 229 "/home/alois/Documents/bah-bah/src/lexer.bah"
long int pos = i;

#line 230 "/home/alois/Documents/bah-bah/src/lexer.bah"
char isCast = false;

#line 231 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_221 = 0;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_221);
    memory->data[____BAH_COMPILER_VAR_221] = c;

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

    unsigned int ____BAH_COMPILER_VAR_222 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_222);
    memory->data[____BAH_COMPILER_VAR_222] = c;

#line 238 "/home/alois/Documents/bah-bah/src/lexer.bah"
break;
}

#line 240 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((isAlphaNumeric(c)==false)&&(c!=42)&&(c!=58)&&(c!=95)&&(c!=91)&&(c!=93)) {

#line 241 "/home/alois/Documents/bah-bah/src/lexer.bah"
break;
}

#line 243 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_223 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_223);
    memory->data[____BAH_COMPILER_VAR_223] = c;
};

#line 245 "/home/alois/Documents/bah-bah/src/lexer.bah"
if ((isCast==true)) {

#line 246 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_224 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_224);
    tokens->data[____BAH_COMPILER_VAR_224] = makeToken(pos,lineNb,memory,TOKEN_TYPE_CAST);

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

    unsigned int ____BAH_COMPILER_VAR_225 = 0;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_225);
    memory->data[____BAH_COMPILER_VAR_225] = c;

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
if ((____BAH_COMPILER_VAR_226(syntaxes, c)==false)) {

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

    unsigned int ____BAH_COMPILER_VAR_227 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_227);
    memory->data[____BAH_COMPILER_VAR_227] = c;
};

#line 283 "/home/alois/Documents/bah-bah/src/lexer.bah"
--i;

#line 284 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_228 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_228);
    tokens->data[____BAH_COMPILER_VAR_228] = makeToken(pos,lineNb,memory,TOKEN_TYPE_SYNTAX);
}

#line 285 "/home/alois/Documents/bah-bah/src/lexer.bah"
else if ((c==46)) {

#line 287 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_229 = 0;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_229);
    memory->data[____BAH_COMPILER_VAR_229] = c;

#line 288 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_230 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_230);
    tokens->data[____BAH_COMPILER_VAR_230] = makeToken(i,lineNb,memory,TOKEN_TYPE_SEP);
}

#line 289 "/home/alois/Documents/bah-bah/src/lexer.bah"
else if (isAlphaNumeric(c)||(c==95)) {

#line 291 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_231 = 0;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_231);
    memory->data[____BAH_COMPILER_VAR_231] = c;

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

    unsigned int ____BAH_COMPILER_VAR_232 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_232);
    memory->data[____BAH_COMPILER_VAR_232] = c;
};

#line 312 "/home/alois/Documents/bah-bah/src/lexer.bah"
--i;

#line 313 "/home/alois/Documents/bah-bah/src/lexer.bah"
tokenType currentType = TOKEN_TYPE_VAR;

#line 315 "/home/alois/Documents/bah-bah/src/lexer.bah"

    unsigned int ____BAH_COMPILER_VAR_233 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_233);
    tokens->data[____BAH_COMPILER_VAR_233] = makeToken(pos,lineNb,memory,currentType);
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
char * ____BAH_COMPILER_VAR_234 =splitStringBefore(*n,"\01\0\0\0"".");struct string res = string(____BAH_COMPILER_VAR_234);

#line 21 "/home/alois/Documents/bah-bah/src/struct.bah"
return res;
}

#line 23 "/home/alois/Documents/bah-bah/src/struct.bah"
if (string__count(n,"\02\0\0\0""->")) {

#line 24 "/home/alois/Documents/bah-bah/src/struct.bah"
char * ____BAH_COMPILER_VAR_235 =splitStringBefore(*n,"\02\0\0\0""->");struct string res = string(____BAH_COMPILER_VAR_235);

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
struct structMemb* ____BAH_COMPILER_VAR_236 = memoryAlloc(sizeof(struct structMemb));
____BAH_COMPILER_VAR_236->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_236->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_236->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_236->from = "\0\0\0\0""";
____BAH_COMPILER_VAR_236->def = "\0\0\0\0""";
struct structMemb* sm = ____BAH_COMPILER_VAR_236;

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
char** ____BAH_COMPILER_VAR_237 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_237[2] = name;____BAH_COMPILER_VAR_237[1] = "\02\0\0\0""__";____BAH_COMPILER_VAR_237[0] = s->name;char * ____BAH_COMPILER_VAR_238 =__Bah_multiple_concat(____BAH_COMPILER_VAR_237, 3);struct func* fn = searchFunc(____BAH_COMPILER_VAR_238,elems,true);

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
struct string ____BAH_COMPILER_VAR_239 =string(s->members->data[i]->type);fn = parseFnType(____BAH_COMPILER_VAR_239);

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
char** ____BAH_COMPILER_VAR_240 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_240[2] = "\02\0\0\0"")*";____BAH_COMPILER_VAR_240[1] = t;____BAH_COMPILER_VAR_240[0] = "\06\0\0\0""array(";char * ____BAH_COMPILER_VAR_241 =__Bah_multiple_concat(____BAH_COMPILER_VAR_240, 3);char * r = ____BAH_COMPILER_VAR_241;

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
char * ____BAH_COMPILER_VAR_242 =string__str(&parts->data[2]);
                struct string ____BAH_COMPILER_VAR_243 = getCType(____BAH_COMPILER_VAR_242,elems);
                char** ____BAH_COMPILER_VAR_244 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_244[1] = "\01\0\0\0""*";____BAH_COMPILER_VAR_244[0] = string__str(&____BAH_COMPILER_VAR_243);char * ____BAH_COMPILER_VAR_245 =__Bah_multiple_concat(____BAH_COMPILER_VAR_244, 2);string__set(&tp,____BAH_COMPILER_VAR_245);
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
char** ____BAH_COMPILER_VAR_246 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_246[1] = "\01\0\0\0""*";____BAH_COMPILER_VAR_246[0] = cpstringSubsitute(a, 0, strlen(a)-1);char * ____BAH_COMPILER_VAR_247 =__Bah_multiple_concat(____BAH_COMPILER_VAR_246, 2);a = ____BAH_COMPILER_VAR_247;

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
char ____BAH_COMPILER_VAR_248(array(char *)* arr, char * el) {
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
char ____BAH_COMPILER_VAR_249(array(char *)* arr, char * el) {
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
char ____BAH_COMPILER_VAR_250(array(char *)* arr, char * el) {
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
char ____BAH_COMPILER_VAR_251(array(char *)* arr, char * el) {
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
if (____BAH_COMPILER_VAR_248(intTypes, a)&&____BAH_COMPILER_VAR_249(intTypes, b)) {

#line 162 "/home/alois/Documents/bah-bah/src/type.bah"
return true;
}

#line 164 "/home/alois/Documents/bah-bah/src/type.bah"
if (____BAH_COMPILER_VAR_250(floatTypes, a)&&____BAH_COMPILER_VAR_251(floatTypes, b)) {

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
struct strBuilder ____BAH_COMPILER_VAR_252 = {};
strBuilder___init(&____BAH_COMPILER_VAR_252);
struct strBuilder sb = ____BAH_COMPILER_VAR_252;

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
char ** ____BAH_COMPILER_VAR_253 = &name;
struct reflectElement ____BAH_COMPILER_VAR_254 = __reflect(____BAH_COMPILER_VAR_253, sizeof(char **), "\011\0\0\0""cpstring*", "\05\0\0\0""&name", 0, 0, 0, 0, 0);
char** ____BAH_COMPILER_VAR_255 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_255[8] = "\014\0\0\0""\n    },\n    ";____BAH_COMPILER_VAR_255[7] = toJson(e);____BAH_COMPILER_VAR_255[6] = "\026\0\0\0""\",\n        \"element\": ";____BAH_COMPILER_VAR_255[5] = intToStr(line);____BAH_COMPILER_VAR_255[4] = "\01\0\0\0"":";____BAH_COMPILER_VAR_255[3] = compilerState.currentFile;____BAH_COMPILER_VAR_255[2] = "\023\0\0\0"",\n        \"path\": \"";____BAH_COMPILER_VAR_255[1] = toJson(____BAH_COMPILER_VAR_254);____BAH_COMPILER_VAR_255[0] = "\027\0\0\0""\n    {\n        \"name\": ";char * ____BAH_COMPILER_VAR_256 =__Bah_multiple_concat(____BAH_COMPILER_VAR_255, 9);println(____BAH_COMPILER_VAR_256);
};

#line 60 "/home/alois/Documents/bah-bah/src/logger.bah"
void debugError(char * name,long int line,long int from,long int to,struct reflectElement e){

#line 61 "/home/alois/Documents/bah-bah/src/logger.bah"
if ((debug==false)) {

#line 62 "/home/alois/Documents/bah-bah/src/logger.bah"
return;
}

#line 64 "/home/alois/Documents/bah-bah/src/logger.bah"
char ** ____BAH_COMPILER_VAR_257 = &name;
struct reflectElement ____BAH_COMPILER_VAR_258 = __reflect(____BAH_COMPILER_VAR_257, sizeof(char **), "\011\0\0\0""cpstring*", "\05\0\0\0""&name", 0, 0, 0, 0, 0);
char** ____BAH_COMPILER_VAR_259 = alloca(13 * sizeof(char*));____BAH_COMPILER_VAR_259[12] = "\014\0\0\0""\n    },\n    ";____BAH_COMPILER_VAR_259[11] = toJson(e);____BAH_COMPILER_VAR_259[10] = "\037\0\0\0""\n        ],\n        \"element\": ";____BAH_COMPILER_VAR_259[9] = intToStr(to);____BAH_COMPILER_VAR_259[8] = "\016\0\0\0"",\n            ";____BAH_COMPILER_VAR_259[7] = intToStr(from);____BAH_COMPILER_VAR_259[6] = "\042\0\0\0""\",\n        \"range\": [\n            ";____BAH_COMPILER_VAR_259[5] = intToStr(line);____BAH_COMPILER_VAR_259[4] = "\01\0\0\0"":";____BAH_COMPILER_VAR_259[3] = compilerState.currentFile;____BAH_COMPILER_VAR_259[2] = "\023\0\0\0"",\n        \"path\": \"";____BAH_COMPILER_VAR_259[1] = toJson(____BAH_COMPILER_VAR_258);____BAH_COMPILER_VAR_259[0] = "\027\0\0\0""\n    {\n        \"name\": ";char * ____BAH_COMPILER_VAR_260 =__Bah_multiple_concat(____BAH_COMPILER_VAR_259, 13);println(____BAH_COMPILER_VAR_260);
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
struct variable* ____BAH_COMPILER_VAR_261 = v;
char ** ____BAH_COMPILER_VAR_263 = (char **)((char*)(____BAH_COMPILER_VAR_261) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_264 = __reflect(____BAH_COMPILER_VAR_263, sizeof(char *), "\010\0\0\0""cpstring", "\04\0\0\0""name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_265 = (char **)((char*)(____BAH_COMPILER_VAR_261) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_266 = __reflect(____BAH_COMPILER_VAR_265, sizeof(char *), "\010\0\0\0""cpstring", "\04\0\0\0""type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_267 = (char*)((char*)(____BAH_COMPILER_VAR_261) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_268 = __reflect(____BAH_COMPILER_VAR_267, sizeof(char), "\04\0\0\0""bool", "\07\0\0\0""isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_269 = (char **)((char*)(____BAH_COMPILER_VAR_261) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_270 = __reflect(____BAH_COMPILER_VAR_269, sizeof(char *), "\010\0\0\0""cpstring", "\010\0\0\0""constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_271 = (char*)((char*)(____BAH_COMPILER_VAR_261) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_272 = __reflect(____BAH_COMPILER_VAR_271, sizeof(char), "\04\0\0\0""bool", "\07\0\0\0""isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_273 = (char **)((char*)(____BAH_COMPILER_VAR_261) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_274 = __reflect(____BAH_COMPILER_VAR_273, sizeof(char *), "\010\0\0\0""cpstring", "\04\0\0\0""from", 0, 0, 0, 0, offsetof(struct variable, from));
void ** ____BAH_COMPILER_VAR_275 = (void **)((char*)(____BAH_COMPILER_VAR_261) + offsetof(struct variable, declScope));
struct reflectElement ____BAH_COMPILER_VAR_276 = __reflect(____BAH_COMPILER_VAR_275, sizeof(void *), "\03\0\0\0""ptr", "\011\0\0\0""declScope", 0, 0, 0, 0, offsetof(struct variable, declScope));
char* ____BAH_COMPILER_VAR_277 = (char*)((char*)(____BAH_COMPILER_VAR_261) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_278 = __reflect(____BAH_COMPILER_VAR_277, sizeof(char), "\04\0\0\0""bool", "\010\0\0\0""isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));
struct rope** ____BAH_COMPILER_VAR_279 = (struct rope**)((char*)(____BAH_COMPILER_VAR_261) + offsetof(struct variable, declRope));
void ** ____BAH_COMPILER_VAR_281 = (void **)((char*)(____BAH_COMPILER_VAR_279) + offsetof(struct rope, left));
struct reflectElement ____BAH_COMPILER_VAR_282 = __reflect(____BAH_COMPILER_VAR_281, sizeof(void *), "\03\0\0\0""ptr", "\04\0\0\0""left", 0, 0, 0, 0, offsetof(struct rope, left));
void ** ____BAH_COMPILER_VAR_283 = (void **)((char*)(____BAH_COMPILER_VAR_279) + offsetof(struct rope, right));
struct reflectElement ____BAH_COMPILER_VAR_284 = __reflect(____BAH_COMPILER_VAR_283, sizeof(void *), "\03\0\0\0""ptr", "\05\0\0\0""right", 0, 0, 0, 0, offsetof(struct rope, right));
char ** ____BAH_COMPILER_VAR_285 = (char **)((char*)(____BAH_COMPILER_VAR_279) + offsetof(struct rope, str));
struct reflectElement ____BAH_COMPILER_VAR_286 = __reflect(____BAH_COMPILER_VAR_285, sizeof(char *), "\010\0\0\0""cpstring", "\03\0\0\0""str", 0, 0, 0, 0, offsetof(struct rope, str));
int* ____BAH_COMPILER_VAR_287 = (int*)((char*)(____BAH_COMPILER_VAR_279) + offsetof(struct rope, lCount));
struct reflectElement ____BAH_COMPILER_VAR_288 = __reflect(____BAH_COMPILER_VAR_287, sizeof(int), "\05\0\0\0""int32", "\06\0\0\0""lCount", 0, 0, 0, 0, offsetof(struct rope, lCount));
int* ____BAH_COMPILER_VAR_289 = (int*)((char*)(____BAH_COMPILER_VAR_279) + offsetof(struct rope, len));
struct reflectElement ____BAH_COMPILER_VAR_290 = __reflect(____BAH_COMPILER_VAR_289, sizeof(int), "\05\0\0\0""int32", "\03\0\0\0""len", 0, 0, 0, 0, offsetof(struct rope, len));
int* ____BAH_COMPILER_VAR_291 = (int*)((char*)(____BAH_COMPILER_VAR_279) + offsetof(struct rope, totalLen));
struct reflectElement ____BAH_COMPILER_VAR_292 = __reflect(____BAH_COMPILER_VAR_291, sizeof(int), "\05\0\0\0""int32", "\010\0\0\0""totalLen", 0, 0, 0, 0, offsetof(struct rope, totalLen));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_280 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_280->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_280->length = 6;
        ____BAH_COMPILER_VAR_280->data = memoryAlloc(____BAH_COMPILER_VAR_280->length * ____BAH_COMPILER_VAR_280->elemSize);
        ____BAH_COMPILER_VAR_280->data[0] = ____BAH_COMPILER_VAR_282;
____BAH_COMPILER_VAR_280->data[1] = ____BAH_COMPILER_VAR_284;
____BAH_COMPILER_VAR_280->data[2] = ____BAH_COMPILER_VAR_286;
____BAH_COMPILER_VAR_280->data[3] = ____BAH_COMPILER_VAR_288;
____BAH_COMPILER_VAR_280->data[4] = ____BAH_COMPILER_VAR_290;
____BAH_COMPILER_VAR_280->data[5] = ____BAH_COMPILER_VAR_292;
struct reflectElement ____BAH_COMPILER_VAR_293 = __reflect(____BAH_COMPILER_VAR_279, sizeof(struct rope), "\05\0\0\0""rope*", "\010\0\0\0""declRope", 0, 0, 1, ____BAH_COMPILER_VAR_280, offsetof(struct variable, declRope));
char* ____BAH_COMPILER_VAR_294 = (char*)((char*)(____BAH_COMPILER_VAR_261) + offsetof(struct variable, canBeNull));
struct reflectElement ____BAH_COMPILER_VAR_295 = __reflect(____BAH_COMPILER_VAR_294, sizeof(char), "\04\0\0\0""bool", "\011\0\0\0""canBeNull", 0, 0, 0, 0, offsetof(struct variable, canBeNull));
void ** ____BAH_COMPILER_VAR_296 = (void **)((char*)(____BAH_COMPILER_VAR_261) + offsetof(struct variable, iterScope));
struct reflectElement ____BAH_COMPILER_VAR_297 = __reflect(____BAH_COMPILER_VAR_296, sizeof(void *), "\03\0\0\0""ptr", "\011\0\0\0""iterScope", 0, 0, 0, 0, offsetof(struct variable, iterScope));
char* ____BAH_COMPILER_VAR_298 = (char*)((char*)(____BAH_COMPILER_VAR_261) + offsetof(struct variable, canBeReg));
struct reflectElement ____BAH_COMPILER_VAR_299 = __reflect(____BAH_COMPILER_VAR_298, sizeof(char), "\04\0\0\0""bool", "\010\0\0\0""canBeReg", 0, 0, 0, 0, offsetof(struct variable, canBeReg));
char* ____BAH_COMPILER_VAR_300 = (char*)((char*)(____BAH_COMPILER_VAR_261) + offsetof(struct variable, isReg));
struct reflectElement ____BAH_COMPILER_VAR_301 = __reflect(____BAH_COMPILER_VAR_300, sizeof(char), "\04\0\0\0""bool", "\05\0\0\0""isReg", 0, 0, 0, 0, offsetof(struct variable, isReg));
void ** ____BAH_COMPILER_VAR_302 = (void **)((char*)(____BAH_COMPILER_VAR_261) + offsetof(struct variable, lastSet));
struct reflectElement ____BAH_COMPILER_VAR_303 = __reflect(____BAH_COMPILER_VAR_302, sizeof(void *), "\03\0\0\0""ptr", "\07\0\0\0""lastSet", 0, 0, 0, 0, offsetof(struct variable, lastSet));
char* ____BAH_COMPILER_VAR_304 = (char*)((char*)(____BAH_COMPILER_VAR_261) + offsetof(struct variable, isArg));
struct reflectElement ____BAH_COMPILER_VAR_305 = __reflect(____BAH_COMPILER_VAR_304, sizeof(char), "\04\0\0\0""bool", "\05\0\0\0""isArg", 0, 0, 0, 0, offsetof(struct variable, isArg));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_262 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_262->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_262->length = 15;
        ____BAH_COMPILER_VAR_262->data = memoryAlloc(____BAH_COMPILER_VAR_262->length * ____BAH_COMPILER_VAR_262->elemSize);
        ____BAH_COMPILER_VAR_262->data[0] = ____BAH_COMPILER_VAR_264;
____BAH_COMPILER_VAR_262->data[1] = ____BAH_COMPILER_VAR_266;
____BAH_COMPILER_VAR_262->data[2] = ____BAH_COMPILER_VAR_268;
____BAH_COMPILER_VAR_262->data[3] = ____BAH_COMPILER_VAR_270;
____BAH_COMPILER_VAR_262->data[4] = ____BAH_COMPILER_VAR_272;
____BAH_COMPILER_VAR_262->data[5] = ____BAH_COMPILER_VAR_274;
____BAH_COMPILER_VAR_262->data[6] = ____BAH_COMPILER_VAR_276;
____BAH_COMPILER_VAR_262->data[7] = ____BAH_COMPILER_VAR_278;
____BAH_COMPILER_VAR_262->data[8] = ____BAH_COMPILER_VAR_293;
____BAH_COMPILER_VAR_262->data[9] = ____BAH_COMPILER_VAR_295;
____BAH_COMPILER_VAR_262->data[10] = ____BAH_COMPILER_VAR_297;
____BAH_COMPILER_VAR_262->data[11] = ____BAH_COMPILER_VAR_299;
____BAH_COMPILER_VAR_262->data[12] = ____BAH_COMPILER_VAR_301;
____BAH_COMPILER_VAR_262->data[13] = ____BAH_COMPILER_VAR_303;
____BAH_COMPILER_VAR_262->data[14] = ____BAH_COMPILER_VAR_305;
struct reflectElement ____BAH_COMPILER_VAR_306 = __reflect(____BAH_COMPILER_VAR_261, sizeof(struct variable), "\011\0\0\0""variable*", "\01\0\0\0""v", 0, 0, 1, ____BAH_COMPILER_VAR_262, 0);
debugPrint("\07\0\0\0""var_end",line,____BAH_COMPILER_VAR_306);
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
char** ____BAH_COMPILER_VAR_307 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_307[3] = "\01\0\0\0""(";____BAH_COMPILER_VAR_307[2] = ASCII_RESET;____BAH_COMPILER_VAR_307[1] = fn->name;____BAH_COMPILER_VAR_307[0] = ASCII_YELLOW;char * ____BAH_COMPILER_VAR_308 =__Bah_multiple_concat(____BAH_COMPILER_VAR_307, 4);char * def = ____BAH_COMPILER_VAR_308;

#line 17 "/home/alois/Documents/bah-bah/src/errors.bah"
register long int i = 0;

#line 17 "/home/alois/Documents/bah-bah/src/errors.bah"
for (; (i<len(fn->args)); 
#line 17 "/home/alois/Documents/bah-bah/src/errors.bah"
++i) {

#line 18 "/home/alois/Documents/bah-bah/src/errors.bah"
char** ____BAH_COMPILER_VAR_309 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_309[5] = ASCII_RESET;____BAH_COMPILER_VAR_309[4] = fn->args->data[i]->type;____BAH_COMPILER_VAR_309[3] = ASCII_BLUE;____BAH_COMPILER_VAR_309[2] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_309[1] = fn->args->data[i]->name;____BAH_COMPILER_VAR_309[0] = ASCII_MAGENTA;char * ____BAH_COMPILER_VAR_310 =__Bah_multiple_concat(____BAH_COMPILER_VAR_309, 6);char** ____BAH_COMPILER_VAR_311 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_311[1] = ____BAH_COMPILER_VAR_310;____BAH_COMPILER_VAR_311[0] = def;char * ____BAH_COMPILER_VAR_312 =__Bah_multiple_concat(____BAH_COMPILER_VAR_311, 2);def = ____BAH_COMPILER_VAR_312;

#line 19 "/home/alois/Documents/bah-bah/src/errors.bah"
if ((i+1<len(fn->args))) {

#line 20 "/home/alois/Documents/bah-bah/src/errors.bah"
char** ____BAH_COMPILER_VAR_313 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_313[1] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_313[0] = def;char * ____BAH_COMPILER_VAR_314 =__Bah_multiple_concat(____BAH_COMPILER_VAR_313, 2);def = ____BAH_COMPILER_VAR_314;
}
};

#line 24 "/home/alois/Documents/bah-bah/src/errors.bah"
char** ____BAH_COMPILER_VAR_315 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_315[6] = ASCII_RESET;____BAH_COMPILER_VAR_315[5] = intToStr(fn->line);____BAH_COMPILER_VAR_315[4] = "\01\0\0\0"":";____BAH_COMPILER_VAR_315[3] = fn->file;____BAH_COMPILER_VAR_315[2] = ASCII_GREEN;____BAH_COMPILER_VAR_315[1] = fn->returns->type;____BAH_COMPILER_VAR_315[0] = "\02\0\0\0"") ";char * ____BAH_COMPILER_VAR_316 =__Bah_multiple_concat(____BAH_COMPILER_VAR_315, 7);char** ____BAH_COMPILER_VAR_317 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_317[1] = ____BAH_COMPILER_VAR_316;____BAH_COMPILER_VAR_317[0] = def;char * ____BAH_COMPILER_VAR_318 =__Bah_multiple_concat(____BAH_COMPILER_VAR_317, 2);def = ____BAH_COMPILER_VAR_318;

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
struct fileStream ____BAH_COMPILER_VAR_319 = {};
struct fileStream fs = ____BAH_COMPILER_VAR_319;

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
char** ____BAH_COMPILER_VAR_320 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_320[2] = "\01\0\0\0""'";____BAH_COMPILER_VAR_320[1] = t->ogCont;____BAH_COMPILER_VAR_320[0] = "\01\0\0\0""'";char * ____BAH_COMPILER_VAR_321 =__Bah_multiple_concat(____BAH_COMPILER_VAR_320, 3);string__replace(&ffmt,"\07\0\0\0""{TOKEN}",____BAH_COMPILER_VAR_321);

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

    unsigned int ____BAH_COMPILER_VAR_322 = len(errCont);
    __Bah_realocate_arr(errCont, ____BAH_COMPILER_VAR_322);
    errCont->data[____BAH_COMPILER_VAR_322] = fileSrcStr[i+4];
};

#line 79 "/home/alois/Documents/bah-bah/src/errors.bah"
char** ____BAH_COMPILER_VAR_323 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_323[2] = "\07\0\0\0""\e[1;37m";____BAH_COMPILER_VAR_323[1] = arrToStr(errCont);____BAH_COMPILER_VAR_323[0] = "\07\0\0\0""\e[1;31m";char * ____BAH_COMPILER_VAR_324 =__Bah_multiple_concat(____BAH_COMPILER_VAR_323, 3);array(char)* errTk = strToArr(____BAH_COMPILER_VAR_324);

#line 80 "/home/alois/Documents/bah-bah/src/errors.bah"
register long int ii = 0;

#line 80 "/home/alois/Documents/bah-bah/src/errors.bah"
for (; (ii<len(errTk)); 
#line 80 "/home/alois/Documents/bah-bah/src/errors.bah"
++ii) {

#line 81 "/home/alois/Documents/bah-bah/src/errors.bah"

    unsigned int ____BAH_COMPILER_VAR_325 = len(line);
    __Bah_realocate_arr(line, ____BAH_COMPILER_VAR_325);
    line->data[____BAH_COMPILER_VAR_325] = errTk->data[ii];
};

#line 83 "/home/alois/Documents/bah-bah/src/errors.bah"
--i;

#line 84 "/home/alois/Documents/bah-bah/src/errors.bah"
continue;
}

#line 86 "/home/alois/Documents/bah-bah/src/errors.bah"

    unsigned int ____BAH_COMPILER_VAR_326 = len(line);
    __Bah_realocate_arr(line, ____BAH_COMPILER_VAR_326);
    line->data[____BAH_COMPILER_VAR_326] = c;
};

#line 89 "/home/alois/Documents/bah-bah/src/errors.bah"
fileStream__close(&fs);

#line 90 "/home/alois/Documents/bah-bah/src/errors.bah"
str = arrToStr(line);

#line 91 "/home/alois/Documents/bah-bah/src/errors.bah"
char** ____BAH_COMPILER_VAR_327 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_327[2] = intToStr(pos);____BAH_COMPILER_VAR_327[1] = "\01\0\0\0"":";____BAH_COMPILER_VAR_327[0] = intToStr(t->line);char * ____BAH_COMPILER_VAR_328 =__Bah_multiple_concat(____BAH_COMPILER_VAR_327, 3);info = ____BAH_COMPILER_VAR_328;
}

#line 94 "/home/alois/Documents/bah-bah/src/errors.bah"
if (debug) {

#line 95 "/home/alois/Documents/bah-bah/src/errors.bah"
struct Tok* t = tp;

#line 96 "/home/alois/Documents/bah-bah/src/errors.bah"
format = noASCIIescape(format);

#line 97 "/home/alois/Documents/bah-bah/src/errors.bah"
char ** ____BAH_COMPILER_VAR_329 = &format;
struct reflectElement ____BAH_COMPILER_VAR_330 = __reflect(____BAH_COMPILER_VAR_329, sizeof(char **), "\011\0\0\0""cpstring*", "\07\0\0\0""&format", 0, 0, 0, 0, 0);
debugError("\05\0\0\0""error",t->line,pos,pos+strlen(t->ogCont),____BAH_COMPILER_VAR_330);

#line 98 "/home/alois/Documents/bah-bah/src/errors.bah"
debugExit();
}

#line 99 "/home/alois/Documents/bah-bah/src/errors.bah"
else {

#line 100 "/home/alois/Documents/bah-bah/src/errors.bah"
advertiseGeneric();

#line 101 "/home/alois/Documents/bah-bah/src/errors.bah"
char** ____BAH_COMPILER_VAR_331 = alloca(8 * sizeof(char*));____BAH_COMPILER_VAR_331[7] = format;____BAH_COMPILER_VAR_331[6] = "\05\0\0\0""\e[0m\n";____BAH_COMPILER_VAR_331[5] = str;____BAH_COMPILER_VAR_331[4] = "\011\0\0\0""\n\e[1;37m\t";____BAH_COMPILER_VAR_331[3] = info;____BAH_COMPILER_VAR_331[2] = "\01\0\0\0"":";____BAH_COMPILER_VAR_331[1] = compilerState.currentFile;____BAH_COMPILER_VAR_331[0] = "\023\0\0\0""\e[1;31m[ERROR]\e[0m ";char * ____BAH_COMPILER_VAR_332 =__Bah_multiple_concat(____BAH_COMPILER_VAR_331, 8);println(____BAH_COMPILER_VAR_332);
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
char ** ____BAH_COMPILER_VAR_333 = &s;
struct reflectElement ____BAH_COMPILER_VAR_334 = __reflect(____BAH_COMPILER_VAR_333, sizeof(char **), "\011\0\0\0""cpstring*", "\02\0\0\0""&s", 0, 0, 0, 0, 0);
debugError("\07\0\0\0""warning",-1,-1,-1,____BAH_COMPILER_VAR_334);

#line 112 "/home/alois/Documents/bah-bah/src/errors.bah"
return;
}

#line 114 "/home/alois/Documents/bah-bah/src/errors.bah"
char** ____BAH_COMPILER_VAR_335 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_335[4] = "\04\0\0\0""\e[0m";____BAH_COMPILER_VAR_335[3] = s;____BAH_COMPILER_VAR_335[2] = "\06\0\0\0""\n\e[0m\t";____BAH_COMPILER_VAR_335[1] = compilerState.currentFile;____BAH_COMPILER_VAR_335[0] = "\025\0\0\0""\e[1;33m[WARNING]\e[0m ";char * ____BAH_COMPILER_VAR_336 =__Bah_multiple_concat(____BAH_COMPILER_VAR_335, 5);println(____BAH_COMPILER_VAR_336);
};

#line 117 "/home/alois/Documents/bah-bah/src/errors.bah"
void throwWarningLine(char * s,long int l){

#line 118 "/home/alois/Documents/bah-bah/src/errors.bah"
if (debug) {

#line 119 "/home/alois/Documents/bah-bah/src/errors.bah"
s = noASCIIescape(s);

#line 120 "/home/alois/Documents/bah-bah/src/errors.bah"
char ** ____BAH_COMPILER_VAR_337 = &s;
struct reflectElement ____BAH_COMPILER_VAR_338 = __reflect(____BAH_COMPILER_VAR_337, sizeof(char **), "\011\0\0\0""cpstring*", "\02\0\0\0""&s", 0, 0, 0, 0, 0);
debugError("\07\0\0\0""warning",l,0,0,____BAH_COMPILER_VAR_338);

#line 121 "/home/alois/Documents/bah-bah/src/errors.bah"
return;
}

#line 123 "/home/alois/Documents/bah-bah/src/errors.bah"
char** ____BAH_COMPILER_VAR_339 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_339[6] = "\04\0\0\0""\e[0m";____BAH_COMPILER_VAR_339[5] = s;____BAH_COMPILER_VAR_339[4] = "\06\0\0\0""\n\e[0m\t";____BAH_COMPILER_VAR_339[3] = intToStr(l);____BAH_COMPILER_VAR_339[2] = "\01\0\0\0"":";____BAH_COMPILER_VAR_339[1] = compilerState.currentFile;____BAH_COMPILER_VAR_339[0] = "\025\0\0\0""\e[1;33m[WARNING]\e[0m ";char * ____BAH_COMPILER_VAR_340 =__Bah_multiple_concat(____BAH_COMPILER_VAR_339, 7);println(____BAH_COMPILER_VAR_340);
};

#line 126 "/home/alois/Documents/bah-bah/src/errors.bah"
void throwNoticeLine(char * s,long int l){

#line 127 "/home/alois/Documents/bah-bah/src/errors.bah"
if (debug) {

#line 128 "/home/alois/Documents/bah-bah/src/errors.bah"
s = noASCIIescape(s);

#line 129 "/home/alois/Documents/bah-bah/src/errors.bah"
char ** ____BAH_COMPILER_VAR_341 = &s;
struct reflectElement ____BAH_COMPILER_VAR_342 = __reflect(____BAH_COMPILER_VAR_341, sizeof(char **), "\011\0\0\0""cpstring*", "\02\0\0\0""&s", 0, 0, 0, 0, 0);
debugError("\06\0\0\0""notice",l,0,0,____BAH_COMPILER_VAR_342);

#line 130 "/home/alois/Documents/bah-bah/src/errors.bah"
return;
}

#line 132 "/home/alois/Documents/bah-bah/src/errors.bah"
if ((noticeEnabled==false)) {

#line 133 "/home/alois/Documents/bah-bah/src/errors.bah"
return;
}

#line 135 "/home/alois/Documents/bah-bah/src/errors.bah"
char** ____BAH_COMPILER_VAR_343 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_343[6] = "\04\0\0\0""\e[0m";____BAH_COMPILER_VAR_343[5] = s;____BAH_COMPILER_VAR_343[4] = "\06\0\0\0""\n\e[0m\t";____BAH_COMPILER_VAR_343[3] = intToStr(l);____BAH_COMPILER_VAR_343[2] = "\01\0\0\0"":";____BAH_COMPILER_VAR_343[1] = compilerState.currentFile;____BAH_COMPILER_VAR_343[0] = "\024\0\0\0""\e[1;36m[NOTICE]\e[0m ";char * ____BAH_COMPILER_VAR_344 =__Bah_multiple_concat(____BAH_COMPILER_VAR_343, 7);println(____BAH_COMPILER_VAR_344);
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
struct variable* ____BAH_COMPILER_VAR_345 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_345->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_345->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_345->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_345->from = "\0\0\0\0""";
struct variable* nv = ____BAH_COMPILER_VAR_345;

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
struct variable* ____BAH_COMPILER_VAR_346 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_346->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_346->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_346->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_346->from = "\0\0\0\0""";
struct variable* nv = ____BAH_COMPILER_VAR_346;

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
char** ____BAH_COMPILER_VAR_347 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_347[1] = "\01\0\0\0""*";____BAH_COMPILER_VAR_347[0] = r;char * ____BAH_COMPILER_VAR_348 =__Bah_multiple_concat(____BAH_COMPILER_VAR_347, 2);r = ____BAH_COMPILER_VAR_348;
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
char** ____BAH_COMPILER_VAR_349 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_349[2] = "\034\0\0\0""' because it is not pointer.";____BAH_COMPILER_VAR_349[1] = name;____BAH_COMPILER_VAR_349[0] = "\023\0\0\0""Cannot use '*' on '";char * ____BAH_COMPILER_VAR_350 =__Bah_multiple_concat(____BAH_COMPILER_VAR_349, 3);throwErr(null,____BAH_COMPILER_VAR_350);
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
struct variable* ____BAH_COMPILER_VAR_351 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_351->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_351->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_351->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_351->from = "\0\0\0\0""";
struct variable* nv = ____BAH_COMPILER_VAR_351;

#line 131 "/home/alois/Documents/bah-bah/src/var.bah"
*nv = *v;

#line 132 "/home/alois/Documents/bah-bah/src/var.bah"
char * r = nv->type;

#line 133 "/home/alois/Documents/bah-bah/src/var.bah"
struct string tcc = string(ogName);

#line 134 "/home/alois/Documents/bah-bah/src/var.bah"
if (string__count(&tcc,"\01\0\0\0""&")) {

#line 135 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_352 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_352[1] = "\01\0\0\0""*";____BAH_COMPILER_VAR_352[0] = r;char * ____BAH_COMPILER_VAR_353 =__Bah_multiple_concat(____BAH_COMPILER_VAR_352, 2);r = ____BAH_COMPILER_VAR_353;
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
char** ____BAH_COMPILER_VAR_354 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_354[2] = "\034\0\0\0""' because it is not pointer.";____BAH_COMPILER_VAR_354[1] = name;____BAH_COMPILER_VAR_354[0] = "\023\0\0\0""Cannot use '*' on '";char * ____BAH_COMPILER_VAR_355 =__Bah_multiple_concat(____BAH_COMPILER_VAR_354, 3);throwErr(null,____BAH_COMPILER_VAR_355);
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
struct variable* ____BAH_COMPILER_VAR_356 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_356->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_356->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_356->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_356->from = "\0\0\0\0""";
struct variable* nv = ____BAH_COMPILER_VAR_356;

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
char** ____BAH_COMPILER_VAR_357 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_357[1] = arg->type;____BAH_COMPILER_VAR_357[0] = nv->type;char * ____BAH_COMPILER_VAR_358 =__Bah_multiple_concat(____BAH_COMPILER_VAR_357, 2);nv->type = ____BAH_COMPILER_VAR_358;

#line 163 "/home/alois/Documents/bah-bah/src/var.bah"
j = j+1;

#line 164 "/home/alois/Documents/bah-bah/src/var.bah"
if ((j<len(fn->args))) {

#line 165 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_359 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_359[1] = "\01\0\0\0"",";____BAH_COMPILER_VAR_359[0] = nv->type;char * ____BAH_COMPILER_VAR_360 =__Bah_multiple_concat(____BAH_COMPILER_VAR_359, 2);nv->type = ____BAH_COMPILER_VAR_360;
}
};

#line 168 "/home/alois/Documents/bah-bah/src/var.bah"
fn->used = true;

#line 169 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_361 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_361[2] = fn->returns->type;____BAH_COMPILER_VAR_361[1] = "\01\0\0\0"")";____BAH_COMPILER_VAR_361[0] = nv->type;char * ____BAH_COMPILER_VAR_362 =__Bah_multiple_concat(____BAH_COMPILER_VAR_361, 3);nv->type = ____BAH_COMPILER_VAR_362;

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
char * ____BAH_COMPILER_VAR_363 =string__str(&cont);return getRealVar(____BAH_COMPILER_VAR_363,elems);
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
char** ____BAH_COMPILER_VAR_364 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_364[2] = v->name;____BAH_COMPILER_VAR_364[1] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_364[0] = t;char * ____BAH_COMPILER_VAR_365 =__Bah_multiple_concat(____BAH_COMPILER_VAR_364, 3);t = ____BAH_COMPILER_VAR_365;

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
struct func* ____BAH_COMPILER_VAR_366 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_366->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_366->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_366->args->length = 0;
            ____BAH_COMPILER_VAR_366->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_366->from = "\0\0\0\0""";
____BAH_COMPILER_VAR_366->file = "\0\0\0\0""";
____BAH_COMPILER_VAR_366->line = 1;
struct func* nf = ____BAH_COMPILER_VAR_366;

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
struct variable* ____BAH_COMPILER_VAR_367 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_367->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_367->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_367->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_367->from = "\0\0\0\0""";
struct variable* arg = ____BAH_COMPILER_VAR_367;

#line 270 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_368 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_368[1] = intToStr(len(nf->args));____BAH_COMPILER_VAR_368[0] = "\04\0\0\0""arg_";char * ____BAH_COMPILER_VAR_369 =__Bah_multiple_concat(____BAH_COMPILER_VAR_368, 2);arg->name = ____BAH_COMPILER_VAR_369;

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

    unsigned int ____BAH_COMPILER_VAR_370 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_370);
    memory->data[____BAH_COMPILER_VAR_370] = c;

#line 277 "/home/alois/Documents/bah-bah/src/var.bah"
j = j+1;
};

#line 279 "/home/alois/Documents/bah-bah/src/var.bah"
arg->type = arrToStr(memory);

#line 280 "/home/alois/Documents/bah-bah/src/var.bah"
clear(memory);

#line 281 "/home/alois/Documents/bah-bah/src/var.bah"

    unsigned int ____BAH_COMPILER_VAR_371 = len(nf->args);
    __Bah_realocate_arr(nf->args, ____BAH_COMPILER_VAR_371);
    nf->args->data[____BAH_COMPILER_VAR_371] = arg;

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

    unsigned int ____BAH_COMPILER_VAR_372 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_372);
    memory->data[____BAH_COMPILER_VAR_372] = c;

#line 291 "/home/alois/Documents/bah-bah/src/var.bah"
j = j+1;
};

#line 293 "/home/alois/Documents/bah-bah/src/var.bah"
struct variable* ____BAH_COMPILER_VAR_373 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_373->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_373->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_373->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_373->from = "\0\0\0\0""";
nf->returns = ____BAH_COMPILER_VAR_373;

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
struct func* ____BAH_COMPILER_VAR_374 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_374->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_374->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_374->args->length = 0;
            ____BAH_COMPILER_VAR_374->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_374->from = "\0\0\0\0""";
____BAH_COMPILER_VAR_374->file = "\0\0\0\0""";
____BAH_COMPILER_VAR_374->line = 1;
struct func* fn = ____BAH_COMPILER_VAR_374;

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
char * ____BAH_COMPILER_VAR_375 =string__str(&fnName);struct structMemb* memb = searchStructMemb(____BAH_COMPILER_VAR_375,s,elems);

#line 325 "/home/alois/Documents/bah-bah/src/var.bah"
if ((memb==null)) {

#line 326 "/home/alois/Documents/bah-bah/src/var.bah"
return null;
}

#line 328 "/home/alois/Documents/bah-bah/src/var.bah"
name = fnName.content;

#line 329 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_376 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_376[2] = name;____BAH_COMPILER_VAR_376[1] = "\02\0\0\0""__";____BAH_COMPILER_VAR_376[0] = memb->from;char * ____BAH_COMPILER_VAR_377 =__Bah_multiple_concat(____BAH_COMPILER_VAR_376, 3);name = ____BAH_COMPILER_VAR_377;
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
struct func* ____BAH_COMPILER_VAR_378 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_378->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_378->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_378->args->length = 0;
            ____BAH_COMPILER_VAR_378->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_378->from = "\0\0\0\0""";
____BAH_COMPILER_VAR_378->file = "\0\0\0\0""";
____BAH_COMPILER_VAR_378->line = 1;
struct func* nf = ____BAH_COMPILER_VAR_378;

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
struct string ____BAH_COMPILER_VAR_379 =string(t->cont);char * fnName = splitStringBefore(____BAH_COMPILER_VAR_379,"\01\0\0\0""(");

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
char** ____BAH_COMPILER_VAR_380 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_380[6] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_380[5] = m->def;____BAH_COMPILER_VAR_380[4] = "\03\0\0\0"" = ";____BAH_COMPILER_VAR_380[3] = m->name;____BAH_COMPILER_VAR_380[2] = sep;____BAH_COMPILER_VAR_380[1] = v->name;____BAH_COMPILER_VAR_380[0] = code;char * ____BAH_COMPILER_VAR_381 =__Bah_multiple_concat(____BAH_COMPILER_VAR_380, 7);code = ____BAH_COMPILER_VAR_381;
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
char** ____BAH_COMPILER_VAR_382 = alloca(17 * sizeof(char*));____BAH_COMPILER_VAR_382[16] = "\017\0\0\0"");\n            ";____BAH_COMPILER_VAR_382[15] = elemCTypeStr;____BAH_COMPILER_VAR_382[14] = "\024\0\0\0""->elemSize = sizeof(";____BAH_COMPILER_VAR_382[13] = m->name;____BAH_COMPILER_VAR_382[12] = sep;____BAH_COMPILER_VAR_382[11] = v->name;____BAH_COMPILER_VAR_382[10] = "\032\0\0\0""->length = 0;\n            ";____BAH_COMPILER_VAR_382[9] = m->name;____BAH_COMPILER_VAR_382[8] = sep;____BAH_COMPILER_VAR_382[7] = v->name;____BAH_COMPILER_VAR_382[6] = "\021\0\0\0"")));\n            ";____BAH_COMPILER_VAR_382[5] = elemCTypeStr;____BAH_COMPILER_VAR_382[4] = "\034\0\0\0"" = memoryAlloc(sizeof(array(";____BAH_COMPILER_VAR_382[3] = m->name;____BAH_COMPILER_VAR_382[2] = sep;____BAH_COMPILER_VAR_382[1] = v->name;____BAH_COMPILER_VAR_382[0] = code;char * ____BAH_COMPILER_VAR_383 =__Bah_multiple_concat(____BAH_COMPILER_VAR_382, 17);code = ____BAH_COMPILER_VAR_383;

#line 404 "/home/alois/Documents/bah-bah/src/var.bah"
continue;
}

#line 406 "/home/alois/Documents/bah-bah/src/var.bah"
if ((string__hasPrefix(&cmpt,"\04\0\0\0""map:")==1)) {

#line 407 "/home/alois/Documents/bah-bah/src/var.bah"
string__trimLeft(&cmpt,4);

#line 408 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_384 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_384[3] = "\021\0\0\0"" = mapWrapper();\n";____BAH_COMPILER_VAR_384[2] = m->name;____BAH_COMPILER_VAR_384[1] = sep;____BAH_COMPILER_VAR_384[0] = v->name;char * ____BAH_COMPILER_VAR_385 =__Bah_multiple_concat(____BAH_COMPILER_VAR_384, 4);char** ____BAH_COMPILER_VAR_386 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_386[1] = ____BAH_COMPILER_VAR_385;____BAH_COMPILER_VAR_386[0] = code;char * ____BAH_COMPILER_VAR_387 =__Bah_multiple_concat(____BAH_COMPILER_VAR_386, 2);code = ____BAH_COMPILER_VAR_387;

#line 409 "/home/alois/Documents/bah-bah/src/var.bah"
continue;
}

#line 411 "/home/alois/Documents/bah-bah/src/var.bah"
if ((string__hasPrefix(&cmpt,"\05\0\0\0""chan:")==1)) {

#line 412 "/home/alois/Documents/bah-bah/src/var.bah"
string__trimLeft(&cmpt,5);

#line 413 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_388 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_388[3] = "\016\0\0\0"" = channel();\n";____BAH_COMPILER_VAR_388[2] = m->name;____BAH_COMPILER_VAR_388[1] = sep;____BAH_COMPILER_VAR_388[0] = v->name;char * ____BAH_COMPILER_VAR_389 =__Bah_multiple_concat(____BAH_COMPILER_VAR_388, 4);char** ____BAH_COMPILER_VAR_390 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_390[1] = ____BAH_COMPILER_VAR_389;____BAH_COMPILER_VAR_390[0] = code;char * ____BAH_COMPILER_VAR_391 =__Bah_multiple_concat(____BAH_COMPILER_VAR_390, 2);code = ____BAH_COMPILER_VAR_391;
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
char** ____BAH_COMPILER_VAR_392 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_392[6] = "\03\0\0\0"");\n";____BAH_COMPILER_VAR_392[5] = v->name;____BAH_COMPILER_VAR_392[4] = amp;____BAH_COMPILER_VAR_392[3] = "\01\0\0\0""(";____BAH_COMPILER_VAR_392[2] = m->name;____BAH_COMPILER_VAR_392[1] = "\02\0\0\0""__";____BAH_COMPILER_VAR_392[0] = s->name;char * ____BAH_COMPILER_VAR_393 =__Bah_multiple_concat(____BAH_COMPILER_VAR_392, 7);char** ____BAH_COMPILER_VAR_394 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_394[1] = ____BAH_COMPILER_VAR_393;____BAH_COMPILER_VAR_394[0] = code;char * ____BAH_COMPILER_VAR_395 =__Bah_multiple_concat(____BAH_COMPILER_VAR_394, 2);code = ____BAH_COMPILER_VAR_395;

#line 423 "/home/alois/Documents/bah-bah/src/var.bah"
++found;
}

#line 424 "/home/alois/Documents/bah-bah/src/var.bah"
else if ((strcmp(m->name, "\04\0\0\0""_end") == 0)) {

#line 425 "/home/alois/Documents/bah-bah/src/var.bah"
if ((strcmp(sep, "\02\0\0\0""->") == 0)) {

#line 426 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_396 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_396[6] = "\03\0\0\0"");\n";____BAH_COMPILER_VAR_396[5] = m->name;____BAH_COMPILER_VAR_396[4] = "\02\0\0\0""__";____BAH_COMPILER_VAR_396[3] = s->name;____BAH_COMPILER_VAR_396[2] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_396[1] = v->name;____BAH_COMPILER_VAR_396[0] = "\014\0\0\0""memoryOnEnd(";char * ____BAH_COMPILER_VAR_397 =__Bah_multiple_concat(____BAH_COMPILER_VAR_396, 7);char** ____BAH_COMPILER_VAR_398 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_398[1] = ____BAH_COMPILER_VAR_397;____BAH_COMPILER_VAR_398[0] = code;char * ____BAH_COMPILER_VAR_399 =__Bah_multiple_concat(____BAH_COMPILER_VAR_398, 2);code = ____BAH_COMPILER_VAR_399;
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
char * genCompilerVar(){

#line 442 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_400 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_400[1] = intToStr(NB_COMP_VAR);____BAH_COMPILER_VAR_400[0] = "\025\0\0\0""____BAH_COMPILER_VAR_";char * ____BAH_COMPILER_VAR_401 =__Bah_multiple_concat(____BAH_COMPILER_VAR_400, 2);char * name = ____BAH_COMPILER_VAR_401;

#line 443 "/home/alois/Documents/bah-bah/src/var.bah"
NB_COMP_VAR = NB_COMP_VAR+1;

#line 444 "/home/alois/Documents/bah-bah/src/var.bah"
return name;
};

#line 447 "/home/alois/Documents/bah-bah/src/var.bah"
typedef array(struct variable*)* __BAH_ARR_TYPE_variable;
char varInArr(struct variable* v,__BAH_ARR_TYPE_variable arr){

#line 448 "/home/alois/Documents/bah-bah/src/var.bah"
if ((arr==null)) {

#line 449 "/home/alois/Documents/bah-bah/src/var.bah"
return false;
}

#line 451 "/home/alois/Documents/bah-bah/src/var.bah"
register long int j = 0;

#line 451 "/home/alois/Documents/bah-bah/src/var.bah"
while ((j<len(arr))) {

#line 452 "/home/alois/Documents/bah-bah/src/var.bah"
struct variable* ev = arr->data[j];

#line 453 "/home/alois/Documents/bah-bah/src/var.bah"
if ((strcmp(ev->name, v->name) == 0)) {

#line 454 "/home/alois/Documents/bah-bah/src/var.bah"
return true;
}

#line 456 "/home/alois/Documents/bah-bah/src/var.bah"
j = j+1;
};

#line 458 "/home/alois/Documents/bah-bah/src/var.bah"
return false;
};

#line 461 "/home/alois/Documents/bah-bah/src/var.bah"
char * pathToVarName(char * p){

#line 462 "/home/alois/Documents/bah-bah/src/var.bah"
array(char)* a = strToArr(p);

#line 463 "/home/alois/Documents/bah-bah/src/var.bah"
register long int i = 0;

#line 463 "/home/alois/Documents/bah-bah/src/var.bah"
for (; (i<len(a)); 
#line 463 "/home/alois/Documents/bah-bah/src/var.bah"
++i) {

#line 464 "/home/alois/Documents/bah-bah/src/var.bah"
long int c = a->data[i];

#line 465 "/home/alois/Documents/bah-bah/src/var.bah"
c = c-(long int)97;

#line 466 "/home/alois/Documents/bah-bah/src/var.bah"
if ((c<0)) {

#line 467 "/home/alois/Documents/bah-bah/src/var.bah"
c = 0-c;
}

#line 469 "/home/alois/Documents/bah-bah/src/var.bah"
c = c%((long int)122-(long int)97);

#line 470 "/home/alois/Documents/bah-bah/src/var.bah"
c = c+(long int)97;

#line 471 "/home/alois/Documents/bah-bah/src/var.bah"

    unsigned int ____BAH_COMPILER_VAR_402 = i;
    __Bah_realocate_arr(a, ____BAH_COMPILER_VAR_402);
    a->data[____BAH_COMPILER_VAR_402] = (char)c;
};

#line 473 "/home/alois/Documents/bah-bah/src/var.bah"
return arrToStr(a);
};
char * strLitteralToBahStr(char * s);

#line 478 "/home/alois/Documents/bah-bah/src/var.bah"
void makeInit(){

#line 479 "/home/alois/Documents/bah-bah/src/var.bah"
char * name = "\012\0\0\0""__BAH_init";

#line 480 "/home/alois/Documents/bah-bah/src/var.bah"
if ((isObject==true)) {

#line 481 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_403 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_403[1] = pathToVarName(compilerState.currentFile);____BAH_COMPILER_VAR_403[0] = name;char * ____BAH_COMPILER_VAR_404 =__Bah_multiple_concat(____BAH_COMPILER_VAR_403, 2);name = ____BAH_COMPILER_VAR_404;
}

#line 484 "/home/alois/Documents/bah-bah/src/var.bah"
char * evals = "\0\0\0\0""";

#line 485 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_405 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_405[2] = "\05\0\0\0""] = {";____BAH_COMPILER_VAR_405[1] = intToStr(len(compilerState.evals));____BAH_COMPILER_VAR_405[0] = "\065\0\0\0""volatile struct __eval_binding __tmp__evals_bindings[";char * ____BAH_COMPILER_VAR_406 =__Bah_multiple_concat(____BAH_COMPILER_VAR_405, 3);char * evalsTMPDecl = ____BAH_COMPILER_VAR_406;

#line 486 "/home/alois/Documents/bah-bah/src/var.bah"
register long int i = 0;

#line 486 "/home/alois/Documents/bah-bah/src/var.bah"
for (; (i<len(compilerState.evals)); 
#line 486 "/home/alois/Documents/bah-bah/src/var.bah"
++i) {

#line 487 "/home/alois/Documents/bah-bah/src/var.bah"
char * e = compilerState.evals->data[i];

#line 488 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_407 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_407[2] = "\01\0\0\0""\"";____BAH_COMPILER_VAR_407[1] = e;____BAH_COMPILER_VAR_407[0] = "\01\0\0\0""\"";char * ____BAH_COMPILER_VAR_408 =__Bah_multiple_concat(____BAH_COMPILER_VAR_407, 3);char** ____BAH_COMPILER_VAR_409 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_409[4] = "\012\0\0\0""\n        }";____BAH_COMPILER_VAR_409[3] = e;____BAH_COMPILER_VAR_409[2] = "\043\0\0\0"",\n            .evalFn = __Bah_eval_";____BAH_COMPILER_VAR_409[1] = strLitteralToBahStr(____BAH_COMPILER_VAR_408);____BAH_COMPILER_VAR_409[0] = "\026\0\0\0""{\n            .name = ";char * ____BAH_COMPILER_VAR_410 =__Bah_multiple_concat(____BAH_COMPILER_VAR_409, 5);char** ____BAH_COMPILER_VAR_411 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_411[1] = ____BAH_COMPILER_VAR_410;____BAH_COMPILER_VAR_411[0] = evalsTMPDecl;char * ____BAH_COMPILER_VAR_412 =__Bah_multiple_concat(____BAH_COMPILER_VAR_411, 2);evalsTMPDecl = ____BAH_COMPILER_VAR_412;

#line 492 "/home/alois/Documents/bah-bah/src/var.bah"
if ((i+1!=len(compilerState.evals))) {

#line 493 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_413 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_413[1] = "\02\0\0\0"",\n";____BAH_COMPILER_VAR_413[0] = evalsTMPDecl;char * ____BAH_COMPILER_VAR_414 =__Bah_multiple_concat(____BAH_COMPILER_VAR_413, 2);evalsTMPDecl = ____BAH_COMPILER_VAR_414;
}

#line 494 "/home/alois/Documents/bah-bah/src/var.bah"
else {

#line 495 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_415 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_415[1] = "\02\0\0\0""};";____BAH_COMPILER_VAR_415[0] = evalsTMPDecl;char * ____BAH_COMPILER_VAR_416 =__Bah_multiple_concat(____BAH_COMPILER_VAR_415, 2);evalsTMPDecl = ____BAH_COMPILER_VAR_416;
}
};

#line 499 "/home/alois/Documents/bah-bah/src/var.bah"
if ((len(compilerState.evals)!=0)) {

#line 500 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_417 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_417[2] = "\01\0\0\0"";";____BAH_COMPILER_VAR_417[1] = intToStr(len(compilerState.evals));____BAH_COMPILER_VAR_417[0] = "\073\0\0\0""__evals_bindings = __tmp__evals_bindings; __evals_length = ";char * ____BAH_COMPILER_VAR_418 =__Bah_multiple_concat(____BAH_COMPILER_VAR_417, 3);evals = ____BAH_COMPILER_VAR_418;
}

#line 501 "/home/alois/Documents/bah-bah/src/var.bah"
else {

#line 502 "/home/alois/Documents/bah-bah/src/var.bah"
evalsTMPDecl = "\0\0\0\0""";
}

#line 505 "/home/alois/Documents/bah-bah/src/var.bah"
char** ____BAH_COMPILER_VAR_419 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_419[4] = "\015\0\0\0""() {\n        ";____BAH_COMPILER_VAR_419[3] = name;____BAH_COMPILER_VAR_419[2] = "\052\0\0\0""\n    void __attribute__((optimize(\"O0\"))) ";____BAH_COMPILER_VAR_419[1] = evalsTMPDecl;____BAH_COMPILER_VAR_419[0] = "\05\0\0\0""\n    ";char * ____BAH_COMPILER_VAR_420 =__Bah_multiple_concat(____BAH_COMPILER_VAR_419, 5);char** ____BAH_COMPILER_VAR_421 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_421[2] = "\014\0\0\0""\n    };\n    ";____BAH_COMPILER_VAR_421[1] = evals;____BAH_COMPILER_VAR_421[0] = "\011\0\0\0""\n        ";char * ____BAH_COMPILER_VAR_422 =__Bah_multiple_concat(____BAH_COMPILER_VAR_421, 3);OUTPUT = rope__add(OUTPUT, (rope__add(rope(____BAH_COMPILER_VAR_420), rope__add(INIT, rope(____BAH_COMPILER_VAR_422)))));
};

#line 514 "/home/alois/Documents/bah-bah/src/var.bah"
char checkedNull(char * v,struct Elems* elems){

#line 515 "/home/alois/Documents/bah-bah/src/var.bah"
for (; (elems!=null); 
#line 515 "/home/alois/Documents/bah-bah/src/var.bah"
elems = elems->parent) {

#line 516 "/home/alois/Documents/bah-bah/src/var.bah"
register long int i = 0;

#line 516 "/home/alois/Documents/bah-bah/src/var.bah"
for (; (i<len(elems->branchChecks)); 
#line 516 "/home/alois/Documents/bah-bah/src/var.bah"
++i) {

#line 517 "/home/alois/Documents/bah-bah/src/var.bah"
struct varCheck bc = elems->branchChecks->data[i];

#line 518 "/home/alois/Documents/bah-bah/src/var.bah"
if ((bc.v==null)) {

#line 519 "/home/alois/Documents/bah-bah/src/var.bah"
continue;
}

#line 521 "/home/alois/Documents/bah-bah/src/var.bah"
if ((strcmp(bc.v->name, v) == 0)) {

#line 522 "/home/alois/Documents/bah-bah/src/var.bah"
return bc.checkNull;
}
};

#line 525 "/home/alois/Documents/bah-bah/src/var.bah"
i = 0;

#line 525 "/home/alois/Documents/bah-bah/src/var.bah"
for (; (i<len(currChecks)); 
#line 525 "/home/alois/Documents/bah-bah/src/var.bah"
++i) {

#line 526 "/home/alois/Documents/bah-bah/src/var.bah"
struct varCheck bc = currChecks->data[i];

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
};

#line 535 "/home/alois/Documents/bah-bah/src/var.bah"
return false;
};

#line 538 "/home/alois/Documents/bah-bah/src/var.bah"
char checkedNotNull(char * v,struct Elems* elems){

#line 539 "/home/alois/Documents/bah-bah/src/var.bah"
for (; (elems!=null); 
#line 539 "/home/alois/Documents/bah-bah/src/var.bah"
elems = elems->parent) {

#line 540 "/home/alois/Documents/bah-bah/src/var.bah"
register long int i = 0;

#line 540 "/home/alois/Documents/bah-bah/src/var.bah"
for (; (i<len(elems->branchChecks)); 
#line 540 "/home/alois/Documents/bah-bah/src/var.bah"
++i) {

#line 541 "/home/alois/Documents/bah-bah/src/var.bah"
struct varCheck bc = elems->branchChecks->data[i];

#line 542 "/home/alois/Documents/bah-bah/src/var.bah"
if ((bc.v==null)) {

#line 543 "/home/alois/Documents/bah-bah/src/var.bah"
continue;
}

#line 545 "/home/alois/Documents/bah-bah/src/var.bah"
if ((strcmp(bc.v->name, v) == 0)) {

#line 546 "/home/alois/Documents/bah-bah/src/var.bah"
return (bc.checkNull==false);
}
};

#line 549 "/home/alois/Documents/bah-bah/src/var.bah"
i = 0;

#line 549 "/home/alois/Documents/bah-bah/src/var.bah"
for (; (i<len(currChecks)); 
#line 549 "/home/alois/Documents/bah-bah/src/var.bah"
++i) {

#line 550 "/home/alois/Documents/bah-bah/src/var.bah"
struct varCheck bc = currChecks->data[i];

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
};

#line 559 "/home/alois/Documents/bah-bah/src/var.bah"
return false;
};

#line 562 "/home/alois/Documents/bah-bah/src/var.bah"
char canChangeNullState(struct variable* v,struct Elems* elems){

#line 563 "/home/alois/Documents/bah-bah/src/var.bah"
if ((v->declScope==elems)) {

#line 564 "/home/alois/Documents/bah-bah/src/var.bah"
return true;
}

#line 566 "/home/alois/Documents/bah-bah/src/var.bah"
return checkedNull(v->name,elems);
};

#line 569 "/home/alois/Documents/bah-bah/src/var.bah"
char * removeCast(char * s){

#line 570 "/home/alois/Documents/bah-bah/src/var.bah"
unsigned long int i = strlen(s)-1;

#line 570 "/home/alois/Documents/bah-bah/src/var.bah"
for (; (i>=0); 
#line 570 "/home/alois/Documents/bah-bah/src/var.bah"
--i) {

#line 571 "/home/alois/Documents/bah-bah/src/var.bah"
if ((s[i+4]==41)) {

#line 572 "/home/alois/Documents/bah-bah/src/var.bah"
s = cpstringSubsitute(s, i+1, strlen(s));

#line 573 "/home/alois/Documents/bah-bah/src/var.bah"
break;
}
};

#line 576 "/home/alois/Documents/bah-bah/src/var.bah"
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
char** ____BAH_COMPILER_VAR_423 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_423[2] = "\03\0\0\0"");\n";____BAH_COMPILER_VAR_423[1] = v->name;____BAH_COMPILER_VAR_423[0] = "\011\0\0\0""RCP_decr(";char * ____BAH_COMPILER_VAR_424 =__Bah_multiple_concat(____BAH_COMPILER_VAR_423, 3);r = rope__add(r, rope(____BAH_COMPILER_VAR_424));
}

#line 16 "/home/alois/Documents/bah-bah/src/mem.bah"
else if (strHasPrefix(v->type,"\05\0\0\0""chan:")) {

#line 17 "/home/alois/Documents/bah-bah/src/mem.bah"
char** ____BAH_COMPILER_VAR_425 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_425[2] = "\03\0\0\0"");\n";____BAH_COMPILER_VAR_425[1] = v->name;____BAH_COMPILER_VAR_425[0] = "\011\0\0\0""RCP_decr(";char * ____BAH_COMPILER_VAR_426 =__Bah_multiple_concat(____BAH_COMPILER_VAR_425, 3);r = rope__add(r, rope(____BAH_COMPILER_VAR_426));
}

#line 18 "/home/alois/Documents/bah-bah/src/mem.bah"
else {

#line 19 "/home/alois/Documents/bah-bah/src/mem.bah"
if (strHasPrefix(v->type,"\04\0\0\0""map:")) {

#line 20 "/home/alois/Documents/bah-bah/src/mem.bah"
struct variable* ____BAH_COMPILER_VAR_427 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_427->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_427->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_427->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_427->from = "\0\0\0\0""";
struct variable* nv = ____BAH_COMPILER_VAR_427;

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
char** ____BAH_COMPILER_VAR_428 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_428[2] = "\03\0\0\0"");\n";____BAH_COMPILER_VAR_428[1] = v->name;____BAH_COMPILER_VAR_428[0] = "\011\0\0\0""RCP_decr(";char * ____BAH_COMPILER_VAR_429 =__Bah_multiple_concat(____BAH_COMPILER_VAR_428, 3);r = rope__add(r, rope(____BAH_COMPILER_VAR_429));
}

#line 32 "/home/alois/Documents/bah-bah/src/mem.bah"
else {

#line 33 "/home/alois/Documents/bah-bah/src/mem.bah"
char** ____BAH_COMPILER_VAR_430 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_430[4] = "\07\0\0\0""), 1);\n";____BAH_COMPILER_VAR_430[3] = v->name;____BAH_COMPILER_VAR_430[2] = "\011\0\0\0"", sizeof(";____BAH_COMPILER_VAR_430[1] = v->name;____BAH_COMPILER_VAR_430[0] = "\017\0\0\0""RCP_scanStack(&";char * ____BAH_COMPILER_VAR_431 =__Bah_multiple_concat(____BAH_COMPILER_VAR_430, 5);r = rope__add(r, rope(____BAH_COMPILER_VAR_431));
}
}

#line 35 "/home/alois/Documents/bah-bah/src/mem.bah"
else if ((isPointer==true)) {

#line 37 "/home/alois/Documents/bah-bah/src/mem.bah"
char** ____BAH_COMPILER_VAR_432 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_432[2] = "\03\0\0\0"");\n";____BAH_COMPILER_VAR_432[1] = v->name;____BAH_COMPILER_VAR_432[0] = "\011\0\0\0""RCP_decr(";char * ____BAH_COMPILER_VAR_433 =__Bah_multiple_concat(____BAH_COMPILER_VAR_432, 3);r = rope__add(r, rope(____BAH_COMPILER_VAR_433));
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
char** ____BAH_COMPILER_VAR_434 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_434[4] = "\06\0\0\0""), 0);";____BAH_COMPILER_VAR_434[3] = v->name;____BAH_COMPILER_VAR_434[2] = "\011\0\0\0"", sizeof(";____BAH_COMPILER_VAR_434[1] = v->name;____BAH_COMPILER_VAR_434[0] = "\017\0\0\0""RCP_scanStack(&";char * ____BAH_COMPILER_VAR_435 =__Bah_multiple_concat(____BAH_COMPILER_VAR_434, 5);return rope(____BAH_COMPILER_VAR_435);
}

#line 54 "/home/alois/Documents/bah-bah/src/mem.bah"
char** ____BAH_COMPILER_VAR_436 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_436[2] = "\02\0\0\0"");";____BAH_COMPILER_VAR_436[1] = v->name;____BAH_COMPILER_VAR_436[0] = "\011\0\0\0""RCP_incr(";char * ____BAH_COMPILER_VAR_437 =__Bah_multiple_concat(____BAH_COMPILER_VAR_436, 3);return rope(____BAH_COMPILER_VAR_437);
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
struct variable* ____BAH_COMPILER_VAR_438 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_438->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_438->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_438->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_438->from = "\0\0\0\0""";
struct variable* av = ____BAH_COMPILER_VAR_438;

#line 149 "/home/alois/Documents/bah-bah/src/mem.bah"
av->type = t;

#line 150 "/home/alois/Documents/bah-bah/src/mem.bah"
av->declScope = elems;

#line 151 "/home/alois/Documents/bah-bah/src/mem.bah"
av->name = genCompilerVar();

#line 152 "/home/alois/Documents/bah-bah/src/mem.bah"

    unsigned int ____BAH_COMPILER_VAR_439 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_439);
    elems->vars->data[____BAH_COMPILER_VAR_439] = av;

#line 153 "/home/alois/Documents/bah-bah/src/mem.bah"
struct string cType = getCType(av->type,elems);

#line 154 "/home/alois/Documents/bah-bah/src/mem.bah"
if (isGlobal()) {

#line 155 "/home/alois/Documents/bah-bah/src/mem.bah"
char** ____BAH_COMPILER_VAR_440 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_440[3] = "\01\0\0\0"";";____BAH_COMPILER_VAR_440[2] = av->name;____BAH_COMPILER_VAR_440[1] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_440[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_441 =__Bah_multiple_concat(____BAH_COMPILER_VAR_440, 4);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_441));

#line 156 "/home/alois/Documents/bah-bah/src/mem.bah"
char** ____BAH_COMPILER_VAR_442 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_442[3] = "\01\0\0\0"";";____BAH_COMPILER_VAR_442[2] = c;____BAH_COMPILER_VAR_442[1] = "\02\0\0\0"" =";____BAH_COMPILER_VAR_442[0] = av->name;char * ____BAH_COMPILER_VAR_443 =__Bah_multiple_concat(____BAH_COMPILER_VAR_442, 4);INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_443));
}

#line 157 "/home/alois/Documents/bah-bah/src/mem.bah"
else {

#line 158 "/home/alois/Documents/bah-bah/src/mem.bah"
char** ____BAH_COMPILER_VAR_444 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_444[5] = "\01\0\0\0"";";____BAH_COMPILER_VAR_444[4] = c;____BAH_COMPILER_VAR_444[3] = "\02\0\0\0"" =";____BAH_COMPILER_VAR_444[2] = av->name;____BAH_COMPILER_VAR_444[1] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_444[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_445 =__Bah_multiple_concat(____BAH_COMPILER_VAR_444, 6);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_445));
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
char ____BAH_COMPILER_VAR_446(array(char *)* arr, char * el) {
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
if (____BAH_COMPILER_VAR_446(noVOfns, currentFn->name)) {

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
struct verboseOutVar ____BAH_COMPILER_VAR_447 = {};
struct verboseOutVar rv = ____BAH_COMPILER_VAR_447;

#line 21 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char * ogCont = cont;

#line 22 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
if ((strcmp(v->type, "\010\0\0\0""cpstring") == 0)) {

#line 23 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char** ____BAH_COMPILER_VAR_448 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_448[2] = "\01\0\0\0"")";____BAH_COMPILER_VAR_448[1] = cont;____BAH_COMPILER_VAR_448[0] = "\022\0\0\0""__Bah_safe_string(";char * ____BAH_COMPILER_VAR_449 =__Bah_multiple_concat(____BAH_COMPILER_VAR_448, 3);cont = ____BAH_COMPILER_VAR_449;
}

#line 25 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char** ____BAH_COMPILER_VAR_450 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_450[1] = cont;____BAH_COMPILER_VAR_450[0] = "\02\0\0\0"", ";char * ____BAH_COMPILER_VAR_451 =__Bah_multiple_concat(____BAH_COMPILER_VAR_450, 2);cont = ____BAH_COMPILER_VAR_451;

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
char** ____BAH_COMPILER_VAR_452 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_452[1] = "\01\0\0\0""{";____BAH_COMPILER_VAR_452[0] = ASCII_RESET;char * ____BAH_COMPILER_VAR_453 =__Bah_multiple_concat(____BAH_COMPILER_VAR_452, 2);ct = ____BAH_COMPILER_VAR_453;

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
char** ____BAH_COMPILER_VAR_454 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_454[4] = m->name;____BAH_COMPILER_VAR_454[3] = "\01\0\0\0"".";____BAH_COMPILER_VAR_454[2] = "\01\0\0\0"")";____BAH_COMPILER_VAR_454[1] = ogCont;____BAH_COMPILER_VAR_454[0] = "\01\0\0\0""(";char * ____BAH_COMPILER_VAR_455 =__Bah_multiple_concat(____BAH_COMPILER_VAR_454, 5);struct verboseOutVar mv = verboseOutTransformVar(m,____BAH_COMPILER_VAR_455,elems);

#line 45 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
if ((i!=0)) {

#line 46 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char** ____BAH_COMPILER_VAR_456 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_456[1] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_456[0] = ct;char * ____BAH_COMPILER_VAR_457 =__Bah_multiple_concat(____BAH_COMPILER_VAR_456, 2);ct = ____BAH_COMPILER_VAR_457;
}

#line 48 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char** ____BAH_COMPILER_VAR_458 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_458[1] = mv.markup;____BAH_COMPILER_VAR_458[0] = ct;char * ____BAH_COMPILER_VAR_459 =__Bah_multiple_concat(____BAH_COMPILER_VAR_458, 2);ct = ____BAH_COMPILER_VAR_459;

#line 49 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char** ____BAH_COMPILER_VAR_460 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_460[1] = mv.content;____BAH_COMPILER_VAR_460[0] = cont;char * ____BAH_COMPILER_VAR_461 =__Bah_multiple_concat(____BAH_COMPILER_VAR_460, 2);cont = ____BAH_COMPILER_VAR_461;
};

#line 51 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char** ____BAH_COMPILER_VAR_462 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_462[1] = "\01\0\0\0""}";____BAH_COMPILER_VAR_462[0] = ct;char * ____BAH_COMPILER_VAR_463 =__Bah_multiple_concat(____BAH_COMPILER_VAR_462, 2);ct = ____BAH_COMPILER_VAR_463;
}
}

#line 56 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char** ____BAH_COMPILER_VAR_464 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_464[6] = ASCII_RESET;____BAH_COMPILER_VAR_464[5] = ct;____BAH_COMPILER_VAR_464[4] = ASCII_MAGENTA;____BAH_COMPILER_VAR_464[3] = "\03\0\0\0"" = ";____BAH_COMPILER_VAR_464[2] = ASCII_RESET;____BAH_COMPILER_VAR_464[1] = v->name;____BAH_COMPILER_VAR_464[0] = ASCII_BLUE;char * ____BAH_COMPILER_VAR_465 =__Bah_multiple_concat(____BAH_COMPILER_VAR_464, 7);rv.markup = ____BAH_COMPILER_VAR_465;

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
struct verboseOutVar ____BAH_COMPILER_VAR_466 = {};
struct verboseOutVar rv = ____BAH_COMPILER_VAR_466;

#line 68 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
return rv;
}
}

#line 71 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
struct variable ____BAH_COMPILER_VAR_467 = {};
____BAH_COMPILER_VAR_467.name = "\0\0\0\0""";
____BAH_COMPILER_VAR_467.type = "\0\0\0\0""";
____BAH_COMPILER_VAR_467.constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_467.from = "\0\0\0\0""";
____BAH_COMPILER_VAR_467.name = "\07\0\0\0""(value)";
____BAH_COMPILER_VAR_467.type = getTypeFromToken(t,true,elems);
struct variable v = ____BAH_COMPILER_VAR_467;

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
char** ____BAH_COMPILER_VAR_468 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_468[1] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_468[0] = fnArgs;char * ____BAH_COMPILER_VAR_469 =__Bah_multiple_concat(____BAH_COMPILER_VAR_468, 2);fnArgs = ____BAH_COMPILER_VAR_469;
}

#line 111 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
struct Tok t = args->data[j];

#line 112 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
struct verboseOutVar v = verboseOutTransformVar(a,t.cont,elems);

#line 113 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char** ____BAH_COMPILER_VAR_470 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_470[1] = v.markup;____BAH_COMPILER_VAR_470[0] = fnArgs;char * ____BAH_COMPILER_VAR_471 =__Bah_multiple_concat(____BAH_COMPILER_VAR_470, 2);fnArgs = ____BAH_COMPILER_VAR_471;

#line 114 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char** ____BAH_COMPILER_VAR_472 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_472[1] = v.content;____BAH_COMPILER_VAR_472[0] = fnArgsValues;char * ____BAH_COMPILER_VAR_473 =__Bah_multiple_concat(____BAH_COMPILER_VAR_472, 2);fnArgsValues = ____BAH_COMPILER_VAR_473;
};

#line 116 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char** ____BAH_COMPILER_VAR_474 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_474[2] = intToStr(lineNb);____BAH_COMPILER_VAR_474[1] = "\01\0\0\0"":";____BAH_COMPILER_VAR_474[0] = compilerState.currentFile;char * ____BAH_COMPILER_VAR_475 =__Bah_multiple_concat(____BAH_COMPILER_VAR_474, 3);char * line = ____BAH_COMPILER_VAR_475;

#line 117 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char** ____BAH_COMPILER_VAR_476 = alloca(13 * sizeof(char*));____BAH_COMPILER_VAR_476[12] = "\016\0\0\0"");\n    //\n    ";____BAH_COMPILER_VAR_476[11] = fnArgsValues;____BAH_COMPILER_VAR_476[10] = "\03\0\0\0""\\n\"";____BAH_COMPILER_VAR_476[9] = ASCII_RESET;____BAH_COMPILER_VAR_476[8] = line;____BAH_COMPILER_VAR_476[7] = ASCII_GREEN;____BAH_COMPILER_VAR_476[6] = "\05\0\0\0"") -> ";____BAH_COMPILER_VAR_476[5] = fnArgs;____BAH_COMPILER_VAR_476[4] = "\01\0\0\0""(";____BAH_COMPILER_VAR_476[3] = ASCII_RESET;____BAH_COMPILER_VAR_476[2] = fn->name;____BAH_COMPILER_VAR_476[1] = nameColor;____BAH_COMPILER_VAR_476[0] = "\065\0\0\0""\n    //Verbose Runtime\n        printf(\"[VO] calling: ";char * ____BAH_COMPILER_VAR_477 =__Bah_multiple_concat(____BAH_COMPILER_VAR_476, 13);struct rope* verboseOut = rope(____BAH_COMPILER_VAR_477);

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
char** ____BAH_COMPILER_VAR_478 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_478[1] = nvo.content;____BAH_COMPILER_VAR_478[0] = pvo.content;char * ____BAH_COMPILER_VAR_479 =__Bah_multiple_concat(____BAH_COMPILER_VAR_478, 2);char * values = ____BAH_COMPILER_VAR_479;

#line 139 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char** ____BAH_COMPILER_VAR_480 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_480[2] = intToStr(lineNb);____BAH_COMPILER_VAR_480[1] = "\01\0\0\0"":";____BAH_COMPILER_VAR_480[0] = compilerState.currentFile;char * ____BAH_COMPILER_VAR_481 =__Bah_multiple_concat(____BAH_COMPILER_VAR_480, 3);char * line = ____BAH_COMPILER_VAR_481;

#line 140 "/home/alois/Documents/bah-bah/src/verboseOut.bah"
char** ____BAH_COMPILER_VAR_482 = alloca(11 * sizeof(char*));____BAH_COMPILER_VAR_482[10] = "\016\0\0\0"");\n    //\n    ";____BAH_COMPILER_VAR_482[9] = values;____BAH_COMPILER_VAR_482[8] = "\03\0\0\0""\\n\"";____BAH_COMPILER_VAR_482[7] = ASCII_RESET;____BAH_COMPILER_VAR_482[6] = line;____BAH_COMPILER_VAR_482[5] = ASCII_GREEN;____BAH_COMPILER_VAR_482[4] = "\04\0\0\0"" -> ";____BAH_COMPILER_VAR_482[3] = nvo.markup;____BAH_COMPILER_VAR_482[2] = "\05\0\0\0"" AND ";____BAH_COMPILER_VAR_482[1] = pvo.markup;____BAH_COMPILER_VAR_482[0] = "\065\0\0\0""\n    //Verbose Runtime\n        printf(\"[VO]    oper: ";char * ____BAH_COMPILER_VAR_483 =__Bah_multiple_concat(____BAH_COMPILER_VAR_482, 11);struct rope* verboseOut = rope(____BAH_COMPILER_VAR_483);

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
struct fileStream ____BAH_COMPILER_VAR_484 = {};
struct fileStream fs = ____BAH_COMPILER_VAR_484;

#line 15 "/home/alois/Documents/bah-bah/src/cache.bah"
char** ____BAH_COMPILER_VAR_485 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_485[1] = "\020\0\0\0""cache/cache.json";____BAH_COMPILER_VAR_485[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_486 =__Bah_multiple_concat(____BAH_COMPILER_VAR_485, 2);fileStream__open(&fs,____BAH_COMPILER_VAR_486,"\01\0\0\0""r");

#line 16 "/home/alois/Documents/bah-bah/src/cache.bah"
if ((fileStream__isValid(&fs)==0)||(fileStream__getSize(&fs)==0)) {

#line 17 "/home/alois/Documents/bah-bah/src/cache.bah"
char** ____BAH_COMPILER_VAR_487 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_487[1] = "\05\0\0\0""cache";____BAH_COMPILER_VAR_487[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_488 =__Bah_multiple_concat(____BAH_COMPILER_VAR_487, 2);mkdir(cStr(____BAH_COMPILER_VAR_488),S_IRWXU);

#line 18 "/home/alois/Documents/bah-bah/src/cache.bah"
char** ____BAH_COMPILER_VAR_489 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_489[1] = "\020\0\0\0""cache/cache.json";____BAH_COMPILER_VAR_489[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_490 =__Bah_multiple_concat(____BAH_COMPILER_VAR_489, 2);fileStream__createFile(&fs,____BAH_COMPILER_VAR_490);

#line 19 "/home/alois/Documents/bah-bah/src/cache.bah"
return;
}

#line 21 "/home/alois/Documents/bah-bah/src/cache.bah"
if ((fileStream__getSize(&fs)>0)) {

#line 22 "/home/alois/Documents/bah-bah/src/cache.bah"
char * ____BAH_COMPILER_VAR_491 =fileStream__readContent(&fs);struct jsonElement* j = parseJson(____BAH_COMPILER_VAR_491);

#line 23 "/home/alois/Documents/bah-bah/src/cache.bah"
fileStream__close(&fs);

#line 24 "/home/alois/Documents/bah-bah/src/cache.bah"
array(struct cacheFile**)* ____BAH_COMPILER_VAR_492 = &cache;
struct cacheFile*** ____BAH_COMPILER_VAR_493 = 0;
char ** ____BAH_COMPILER_VAR_495 = (char **)((char*)(____BAH_COMPILER_VAR_493) + offsetof(struct cacheFile, file));
struct reflectElement ____BAH_COMPILER_VAR_496 = __reflect(____BAH_COMPILER_VAR_495, sizeof(char *), "\010\0\0\0""cpstring", "\04\0\0\0""file", 0, 0, 0, 0, offsetof(struct cacheFile, file));
long int* ____BAH_COMPILER_VAR_497 = (long int*)((char*)(____BAH_COMPILER_VAR_493) + offsetof(struct cacheFile, last));
struct reflectElement ____BAH_COMPILER_VAR_498 = __reflect(____BAH_COMPILER_VAR_497, sizeof(long int), "\03\0\0\0""int", "\04\0\0\0""last", 0, 0, 0, 0, offsetof(struct cacheFile, last));
char ** ____BAH_COMPILER_VAR_499 = (char **)((char*)(____BAH_COMPILER_VAR_493) + offsetof(struct cacheFile, ver));
struct reflectElement ____BAH_COMPILER_VAR_500 = __reflect(____BAH_COMPILER_VAR_499, sizeof(char *), "\010\0\0\0""cpstring", "\03\0\0\0""ver", 0, 0, 0, 0, offsetof(struct cacheFile, ver));
long int* ____BAH_COMPILER_VAR_501 = (long int*)((char*)(____BAH_COMPILER_VAR_493) + offsetof(struct cacheFile, date));
struct reflectElement ____BAH_COMPILER_VAR_502 = __reflect(____BAH_COMPILER_VAR_501, sizeof(long int), "\03\0\0\0""int", "\04\0\0\0""date", 0, 0, 0, 0, offsetof(struct cacheFile, date));
long int* ____BAH_COMPILER_VAR_503 = (long int*)((char*)(____BAH_COMPILER_VAR_493) + offsetof(struct cacheFile, mem));
struct reflectElement ____BAH_COMPILER_VAR_504 = __reflect(____BAH_COMPILER_VAR_503, sizeof(long int), "\03\0\0\0""int", "\03\0\0\0""mem", 0, 0, 0, 0, offsetof(struct cacheFile, mem));
long int* ____BAH_COMPILER_VAR_505 = (long int*)((char*)(____BAH_COMPILER_VAR_493) + offsetof(struct cacheFile, opti));
struct reflectElement ____BAH_COMPILER_VAR_506 = __reflect(____BAH_COMPILER_VAR_505, sizeof(long int), "\03\0\0\0""int", "\04\0\0\0""opti", 0, 0, 0, 0, offsetof(struct cacheFile, opti));
array(char *)** ____BAH_COMPILER_VAR_507 = (array(char *)**)((char*)(____BAH_COMPILER_VAR_493) + offsetof(struct cacheFile, files));
char ** ____BAH_COMPILER_VAR_508 = 0;
struct reflectElement ____BAH_COMPILER_VAR_509 = __reflect(____BAH_COMPILER_VAR_508, sizeof(char *), "\010\0\0\0""cpstring", "\0\0\0\0""", 0, 0, 0, 0, 0);

        struct reflectElement ____BAH_COMPILER_VAR_510 = ____BAH_COMPILER_VAR_509;
        struct reflectElement ____BAH_COMPILER_VAR_511 = __reflect(____BAH_COMPILER_VAR_507, sizeof(array(char *)*), "\012\0\0\0""[]cpstring", "\05\0\0\0""files", 1, &____BAH_COMPILER_VAR_510, 0, 0, offsetof(struct cacheFile, files));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_494 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_494->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_494->length = 7;
        ____BAH_COMPILER_VAR_494->data = memoryAlloc(____BAH_COMPILER_VAR_494->length * ____BAH_COMPILER_VAR_494->elemSize);
        ____BAH_COMPILER_VAR_494->data[0] = ____BAH_COMPILER_VAR_496;
____BAH_COMPILER_VAR_494->data[1] = ____BAH_COMPILER_VAR_498;
____BAH_COMPILER_VAR_494->data[2] = ____BAH_COMPILER_VAR_500;
____BAH_COMPILER_VAR_494->data[3] = ____BAH_COMPILER_VAR_502;
____BAH_COMPILER_VAR_494->data[4] = ____BAH_COMPILER_VAR_504;
____BAH_COMPILER_VAR_494->data[5] = ____BAH_COMPILER_VAR_506;
____BAH_COMPILER_VAR_494->data[6] = ____BAH_COMPILER_VAR_511;
struct reflectElement ____BAH_COMPILER_VAR_512 = __reflect(____BAH_COMPILER_VAR_493, sizeof(struct cacheFile), "\013\0\0\0""cacheFile**", "\0\0\0\0""", 0, 0, 1, ____BAH_COMPILER_VAR_494, 0);

        struct reflectElement ____BAH_COMPILER_VAR_513 = ____BAH_COMPILER_VAR_512;
        struct reflectElement ____BAH_COMPILER_VAR_514 = __reflect(____BAH_COMPILER_VAR_492, sizeof(array(struct cacheFile**)*), "\015\0\0\0""[]cacheFile**", "\06\0\0\0""&cache", 1, &____BAH_COMPILER_VAR_513, 0, 0, 0);
jsonElement__scan(j,____BAH_COMPILER_VAR_514);
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
struct cacheFile* ____BAH_COMPILER_VAR_515 = memoryAlloc(sizeof(struct cacheFile));
____BAH_COMPILER_VAR_515->files = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_515->files->length = 0;
            ____BAH_COMPILER_VAR_515->files->elemSize = sizeof(char *);
            struct cacheFile* c = ____BAH_COMPILER_VAR_515;

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

    unsigned int ____BAH_COMPILER_VAR_516 = len(cache);
    __Bah_realocate_arr(cache, ____BAH_COMPILER_VAR_516);
    cache->data[____BAH_COMPILER_VAR_516] = c;
};

#line 63 "/home/alois/Documents/bah-bah/src/cache.bah"
void writeCache(){

#line 64 "/home/alois/Documents/bah-bah/src/cache.bah"
struct fileStream ____BAH_COMPILER_VAR_517 = {};
struct fileStream fs = ____BAH_COMPILER_VAR_517;

#line 65 "/home/alois/Documents/bah-bah/src/cache.bah"
char** ____BAH_COMPILER_VAR_518 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_518[1] = "\020\0\0\0""cache/cache.json";____BAH_COMPILER_VAR_518[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_519 =__Bah_multiple_concat(____BAH_COMPILER_VAR_518, 2);fileStream__open(&fs,____BAH_COMPILER_VAR_519,"\01\0\0\0""w");

#line 66 "/home/alois/Documents/bah-bah/src/cache.bah"
array(struct cacheFile**)* ____BAH_COMPILER_VAR_520 = &cache;
struct cacheFile*** ____BAH_COMPILER_VAR_521 = 0;
char ** ____BAH_COMPILER_VAR_523 = (char **)((char*)(____BAH_COMPILER_VAR_521) + offsetof(struct cacheFile, file));
struct reflectElement ____BAH_COMPILER_VAR_524 = __reflect(____BAH_COMPILER_VAR_523, sizeof(char *), "\010\0\0\0""cpstring", "\04\0\0\0""file", 0, 0, 0, 0, offsetof(struct cacheFile, file));
long int* ____BAH_COMPILER_VAR_525 = (long int*)((char*)(____BAH_COMPILER_VAR_521) + offsetof(struct cacheFile, last));
struct reflectElement ____BAH_COMPILER_VAR_526 = __reflect(____BAH_COMPILER_VAR_525, sizeof(long int), "\03\0\0\0""int", "\04\0\0\0""last", 0, 0, 0, 0, offsetof(struct cacheFile, last));
char ** ____BAH_COMPILER_VAR_527 = (char **)((char*)(____BAH_COMPILER_VAR_521) + offsetof(struct cacheFile, ver));
struct reflectElement ____BAH_COMPILER_VAR_528 = __reflect(____BAH_COMPILER_VAR_527, sizeof(char *), "\010\0\0\0""cpstring", "\03\0\0\0""ver", 0, 0, 0, 0, offsetof(struct cacheFile, ver));
long int* ____BAH_COMPILER_VAR_529 = (long int*)((char*)(____BAH_COMPILER_VAR_521) + offsetof(struct cacheFile, date));
struct reflectElement ____BAH_COMPILER_VAR_530 = __reflect(____BAH_COMPILER_VAR_529, sizeof(long int), "\03\0\0\0""int", "\04\0\0\0""date", 0, 0, 0, 0, offsetof(struct cacheFile, date));
long int* ____BAH_COMPILER_VAR_531 = (long int*)((char*)(____BAH_COMPILER_VAR_521) + offsetof(struct cacheFile, mem));
struct reflectElement ____BAH_COMPILER_VAR_532 = __reflect(____BAH_COMPILER_VAR_531, sizeof(long int), "\03\0\0\0""int", "\03\0\0\0""mem", 0, 0, 0, 0, offsetof(struct cacheFile, mem));
long int* ____BAH_COMPILER_VAR_533 = (long int*)((char*)(____BAH_COMPILER_VAR_521) + offsetof(struct cacheFile, opti));
struct reflectElement ____BAH_COMPILER_VAR_534 = __reflect(____BAH_COMPILER_VAR_533, sizeof(long int), "\03\0\0\0""int", "\04\0\0\0""opti", 0, 0, 0, 0, offsetof(struct cacheFile, opti));
array(char *)** ____BAH_COMPILER_VAR_535 = (array(char *)**)((char*)(____BAH_COMPILER_VAR_521) + offsetof(struct cacheFile, files));
char ** ____BAH_COMPILER_VAR_536 = 0;
struct reflectElement ____BAH_COMPILER_VAR_537 = __reflect(____BAH_COMPILER_VAR_536, sizeof(char *), "\010\0\0\0""cpstring", "\0\0\0\0""", 0, 0, 0, 0, 0);

        struct reflectElement ____BAH_COMPILER_VAR_538 = ____BAH_COMPILER_VAR_537;
        struct reflectElement ____BAH_COMPILER_VAR_539 = __reflect(____BAH_COMPILER_VAR_535, sizeof(array(char *)*), "\012\0\0\0""[]cpstring", "\05\0\0\0""files", 1, &____BAH_COMPILER_VAR_538, 0, 0, offsetof(struct cacheFile, files));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_522 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_522->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_522->length = 7;
        ____BAH_COMPILER_VAR_522->data = memoryAlloc(____BAH_COMPILER_VAR_522->length * ____BAH_COMPILER_VAR_522->elemSize);
        ____BAH_COMPILER_VAR_522->data[0] = ____BAH_COMPILER_VAR_524;
____BAH_COMPILER_VAR_522->data[1] = ____BAH_COMPILER_VAR_526;
____BAH_COMPILER_VAR_522->data[2] = ____BAH_COMPILER_VAR_528;
____BAH_COMPILER_VAR_522->data[3] = ____BAH_COMPILER_VAR_530;
____BAH_COMPILER_VAR_522->data[4] = ____BAH_COMPILER_VAR_532;
____BAH_COMPILER_VAR_522->data[5] = ____BAH_COMPILER_VAR_534;
____BAH_COMPILER_VAR_522->data[6] = ____BAH_COMPILER_VAR_539;
struct reflectElement ____BAH_COMPILER_VAR_540 = __reflect(____BAH_COMPILER_VAR_521, sizeof(struct cacheFile), "\013\0\0\0""cacheFile**", "\0\0\0\0""", 0, 0, 1, ____BAH_COMPILER_VAR_522, 0);

        struct reflectElement ____BAH_COMPILER_VAR_541 = ____BAH_COMPILER_VAR_540;
        struct reflectElement ____BAH_COMPILER_VAR_542 = __reflect(____BAH_COMPILER_VAR_520, sizeof(array(struct cacheFile**)*), "\015\0\0\0""[]cacheFile**", "\06\0\0\0""&cache", 1, &____BAH_COMPILER_VAR_541, 0, 0, 0);
char * ____BAH_COMPILER_VAR_543 =toJson(____BAH_COMPILER_VAR_542);fileStream__writeFile(&fs,____BAH_COMPILER_VAR_543);

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
char** ____BAH_COMPILER_VAR_544 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_544[5] = "\04\0\0\0"".o.o";____BAH_COMPILER_VAR_544[4] = intToStr(cf->opti);____BAH_COMPILER_VAR_544[3] = intToStr(cf->mem);____BAH_COMPILER_VAR_544[2] = pathToVarName(cf->file);____BAH_COMPILER_VAR_544[1] = "\06\0\0\0""cache/";____BAH_COMPILER_VAR_544[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_545 =__Bah_multiple_concat(____BAH_COMPILER_VAR_544, 6);if ((fileExists(____BAH_COMPILER_VAR_545)==0)) {

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
char** ____BAH_COMPILER_VAR_546 = alloca(15 * sizeof(char*));____BAH_COMPILER_VAR_546[14] = val;____BAH_COMPILER_VAR_546[13] = "\04\0\0\0""] = ";____BAH_COMPILER_VAR_546[12] = nLength;____BAH_COMPILER_VAR_546[11] = "\07\0\0\0""->data[";____BAH_COMPILER_VAR_546[10] = nstr;____BAH_COMPILER_VAR_546[9] = preVal;____BAH_COMPILER_VAR_546[8] = "\07\0\0\0"");\n    ";____BAH_COMPILER_VAR_546[7] = nLength;____BAH_COMPILER_VAR_546[6] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_546[5] = nstr;____BAH_COMPILER_VAR_546[4] = "\032\0\0\0"";\n    __Bah_realocate_arr(";____BAH_COMPILER_VAR_546[3] = nLengthStr;____BAH_COMPILER_VAR_546[2] = "\03\0\0\0"" = ";____BAH_COMPILER_VAR_546[1] = nLength;____BAH_COMPILER_VAR_546[0] = "\022\0\0\0""\n    unsigned int ";char * ____BAH_COMPILER_VAR_547 =__Bah_multiple_concat(____BAH_COMPILER_VAR_546, 15);return ____BAH_COMPILER_VAR_547;
};

#line 18 "/home/alois/Documents/bah-bah/src/gen.bah"
char * genConcat(__BAH_ARR_TYPE_cpstring strs,struct Elems* elems){

#line 21 "/home/alois/Documents/bah-bah/src/gen.bah"
char * buff = genCompilerVar();

#line 22 "/home/alois/Documents/bah-bah/src/gen.bah"
char** ____BAH_COMPILER_VAR_548 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_548[4] = "\022\0\0\0"" * sizeof(char*));";____BAH_COMPILER_VAR_548[3] = intToStr(len(strs));____BAH_COMPILER_VAR_548[2] = "\012\0\0\0"" = alloca(";____BAH_COMPILER_VAR_548[1] = buff;____BAH_COMPILER_VAR_548[0] = "\07\0\0\0""char** ";char * ____BAH_COMPILER_VAR_549 =__Bah_multiple_concat(____BAH_COMPILER_VAR_548, 5);char * r = ____BAH_COMPILER_VAR_549;

#line 24 "/home/alois/Documents/bah-bah/src/gen.bah"
register long int i = 0;

#line 24 "/home/alois/Documents/bah-bah/src/gen.bah"
for (; (i<len(strs)); 
#line 24 "/home/alois/Documents/bah-bah/src/gen.bah"
++i) {

#line 25 "/home/alois/Documents/bah-bah/src/gen.bah"
char** ____BAH_COMPILER_VAR_550 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_550[5] = "\01\0\0\0"";";____BAH_COMPILER_VAR_550[4] = strs->data[i];____BAH_COMPILER_VAR_550[3] = "\04\0\0\0""] = ";____BAH_COMPILER_VAR_550[2] = intToStr(len(strs)-i-1);____BAH_COMPILER_VAR_550[1] = "\01\0\0\0""[";____BAH_COMPILER_VAR_550[0] = buff;char * ____BAH_COMPILER_VAR_551 =__Bah_multiple_concat(____BAH_COMPILER_VAR_550, 6);char** ____BAH_COMPILER_VAR_552 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_552[1] = ____BAH_COMPILER_VAR_551;____BAH_COMPILER_VAR_552[0] = r;char * ____BAH_COMPILER_VAR_553 =__Bah_multiple_concat(____BAH_COMPILER_VAR_552, 2);r = ____BAH_COMPILER_VAR_553;
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
char** ____BAH_COMPILER_VAR_554 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_554[4] = "\01\0\0\0"")";____BAH_COMPILER_VAR_554[3] = intToStr(len(strs));____BAH_COMPILER_VAR_554[2] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_554[1] = buff;____BAH_COMPILER_VAR_554[0] = "\026\0\0\0""__Bah_multiple_concat(";char * ____BAH_COMPILER_VAR_555 =__Bah_multiple_concat(____BAH_COMPILER_VAR_554, 5);char * rstr = registerRCPvar("\010\0\0\0""cpstring",____BAH_COMPILER_VAR_555,elems);

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

                struct string ____BAH_COMPILER_VAR_556 = string(v->name);
                if ((isRCPpointerType(v->type)==false)&&(strcmp(v->type, "\016\0\0\0""reflectElement") != 0)&&(string__hasPrefix(&____BAH_COMPILER_VAR_556,"\025\0\0\0""____BAH_COMPILER_VAR_")==false)) {

#line 13 "/home/alois/Documents/bah-bah/src/optimizations.bah"
struct cStruct* s = searchStruct(v->type,elems);

#line 14 "/home/alois/Documents/bah-bah/src/optimizations.bah"
if ((s!=null)&&(currentFn!=null)) {

#line 15 "/home/alois/Documents/bah-bah/src/optimizations.bah"
char** ____BAH_COMPILER_VAR_557 = alloca(8 * sizeof(char*));____BAH_COMPILER_VAR_557[7] = getFuncDef(currentFn);____BAH_COMPILER_VAR_557[6] = "\040\0\0\0"") could be passed by reference.\n";____BAH_COMPILER_VAR_557[5] = v->type;____BAH_COMPILER_VAR_557[4] = "\06\0\0\0""\e[0m (";____BAH_COMPILER_VAR_557[3] = v->name;____BAH_COMPILER_VAR_557[2] = "\030\0\0\0""()\e[0m: argument \e[1;37m";____BAH_COMPILER_VAR_557[1] = currentFn->name;____BAH_COMPILER_VAR_557[0] = "\012\0\0\0""in \e[1;37m";char * ____BAH_COMPILER_VAR_558 =__Bah_multiple_concat(____BAH_COMPILER_VAR_557, 8);throwNoticeLine(____BAH_COMPILER_VAR_558,currentFn->line);
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
char** ____BAH_COMPILER_VAR_559 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_559[1] = r;____BAH_COMPILER_VAR_559[0] = intToStr(n%8);char * ____BAH_COMPILER_VAR_560 =__Bah_multiple_concat(____BAH_COMPILER_VAR_559, 2);r = ____BAH_COMPILER_VAR_560;

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
char** ____BAH_COMPILER_VAR_561 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_561[1] = r;____BAH_COMPILER_VAR_561[0] = escp;char * ____BAH_COMPILER_VAR_562 =__Bah_multiple_concat(____BAH_COMPILER_VAR_561, 2);return ____BAH_COMPILER_VAR_562;
};

#line 51 "/home/alois/Documents/bah-bah/src/optimizations.bah"
char * escapeIntOctal(long int n){

#line 52 "/home/alois/Documents/bah-bah/src/optimizations.bah"
char* s = &n;

#line 53 "/home/alois/Documents/bah-bah/src/optimizations.bah"
char** ____BAH_COMPILER_VAR_563 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_563[3] = byteToOctal((unsigned char)s[3]);____BAH_COMPILER_VAR_563[2] = byteToOctal((unsigned char)s[2]);____BAH_COMPILER_VAR_563[1] = byteToOctal((unsigned char)s[1]);____BAH_COMPILER_VAR_563[0] = byteToOctal((unsigned char)s[0]);char * ____BAH_COMPILER_VAR_564 =__Bah_multiple_concat(____BAH_COMPILER_VAR_563, 4);char * r = ____BAH_COMPILER_VAR_564;

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
char** ____BAH_COMPILER_VAR_565 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_565[3] = s;____BAH_COMPILER_VAR_565[2] = "\01\0\0\0""\"";____BAH_COMPILER_VAR_565[1] = escapeIntOctal(l);____BAH_COMPILER_VAR_565[0] = "\01\0\0\0""\"";char * ____BAH_COMPILER_VAR_566 =__Bah_multiple_concat(____BAH_COMPILER_VAR_565, 4);return ____BAH_COMPILER_VAR_566;
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
struct func* ____BAH_COMPILER_VAR_567 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_567->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_567->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_567->args->length = 0;
            ____BAH_COMPILER_VAR_567->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_567->from = "\0\0\0\0""";
____BAH_COMPILER_VAR_567->file = "\0\0\0\0""";
____BAH_COMPILER_VAR_567->line = 1;
struct func* r = ____BAH_COMPILER_VAR_567;

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
struct variable* ____BAH_COMPILER_VAR_568 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_568->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_568->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_568->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_568->from = "\0\0\0\0""";
struct variable* na = ____BAH_COMPILER_VAR_568;

#line 21 "/home/alois/Documents/bah-bah/src/generics.bah"
*na = *a;

#line 22 "/home/alois/Documents/bah-bah/src/generics.bah"

    unsigned int ____BAH_COMPILER_VAR_569 = i;
    __Bah_realocate_arr(r->args, ____BAH_COMPILER_VAR_569);
    r->args->data[____BAH_COMPILER_VAR_569] = na;
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

    unsigned int ____BAH_COMPILER_VAR_570 = len(this->declared);
    __Bah_realocate_arr(this->declared, ____BAH_COMPILER_VAR_570);
    this->declared->data[____BAH_COMPILER_VAR_570] = fn;

#line 44 "/home/alois/Documents/bah-bah/src/generics.bah"

                struct string ____BAH_COMPILER_VAR_571 = getCType(fn->returns->type,elems);
                char** ____BAH_COMPILER_VAR_572 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_572[3] = "\01\0\0\0""(";____BAH_COMPILER_VAR_572[2] = fn->name;____BAH_COMPILER_VAR_572[1] = "\013\0\0\0"" __generic_";____BAH_COMPILER_VAR_572[0] = string__str(&____BAH_COMPILER_VAR_571);char * ____BAH_COMPILER_VAR_573 =__Bah_multiple_concat(____BAH_COMPILER_VAR_572, 4);OUTPUT = rope(____BAH_COMPILER_VAR_573);

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

    unsigned int ____BAH_COMPILER_VAR_574 = len(fnElems->vars);
    __Bah_realocate_arr(fnElems->vars, ____BAH_COMPILER_VAR_574);
    fnElems->vars->data[____BAH_COMPILER_VAR_574] = arg;

#line 54 "/home/alois/Documents/bah-bah/src/generics.bah"

                struct string ____BAH_COMPILER_VAR_575 = getCType(arg->type,elems);
                char** ____BAH_COMPILER_VAR_576 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_576[2] = arg->name;____BAH_COMPILER_VAR_576[1] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_576[0] = string__str(&____BAH_COMPILER_VAR_575);char * ____BAH_COMPILER_VAR_577 =__Bah_multiple_concat(____BAH_COMPILER_VAR_576, 3);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_577));

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
char** ____BAH_COMPILER_VAR_578 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_578[2] = "\022\0\0\0""' is not returned.";____BAH_COMPILER_VAR_578[1] = fn->name;____BAH_COMPILER_VAR_578[0] = "\012\0\0\0""Function '";char * ____BAH_COMPILER_VAR_579 =__Bah_multiple_concat(____BAH_COMPILER_VAR_578, 3);throwErr(this->tokenName,____BAH_COMPILER_VAR_579);
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
char** ____BAH_COMPILER_VAR_580 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_580[1] = rope__toStr(code);____BAH_COMPILER_VAR_580[0] = rope__toStr(postDeclHandle);char * ____BAH_COMPILER_VAR_581 =__Bah_multiple_concat(____BAH_COMPILER_VAR_580, 2);OUTPUT->totalLen = OUTPUT->totalLen+ropeSet(postDeclHandle,____BAH_COMPILER_VAR_581);
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
char** ____BAH_COMPILER_VAR_582 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_582[3] = intToStr(gen->callToken->line);____BAH_COMPILER_VAR_582[2] = "\01\0\0\0"":";____BAH_COMPILER_VAR_582[1] = compilerState.currentFile;____BAH_COMPILER_VAR_582[0] = "\027\0\0\0""[Generic] called here: ";char * ____BAH_COMPILER_VAR_583 =__Bah_multiple_concat(____BAH_COMPILER_VAR_582, 4);println(____BAH_COMPILER_VAR_583);
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
char** ____BAH_COMPILER_VAR_584 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_584[3] = "\01\0\0\0""'";____BAH_COMPILER_VAR_584[2] = t.cont;____BAH_COMPILER_VAR_584[1] = "\02\0\0\0"" '";____BAH_COMPILER_VAR_584[0] = cont;char * ____BAH_COMPILER_VAR_585 =__Bah_multiple_concat(____BAH_COMPILER_VAR_584, 4);cont = ____BAH_COMPILER_VAR_585;

#line 20 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;
};

#line 22 "/home/alois/Documents/bah-bah/src/parser.bah"
println(cont);
};

#line 26 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Elems* dupElems(struct Elems* elems){

#line 27 "/home/alois/Documents/bah-bah/src/parser.bah"
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

    unsigned int ____BAH_COMPILER_VAR_587 = j;
    __Bah_realocate_arr(nElems->vars, ____BAH_COMPILER_VAR_587);
    nElems->vars->data[____BAH_COMPILER_VAR_587] = elems->vars->data[j];
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

                struct string ____BAH_COMPILER_VAR_588 = string(compilerState.currentDir);
                if ((isUnsafe==false)&&(string__hasPrefix(&____BAH_COMPILER_VAR_588,BAH_DIR)==false)&&isRCPpointerType(tt)&&(t->cont[0+4]!=38)&&(t->cont[0+4]!=42)) {

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
char** ____BAH_COMPILER_VAR_589 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_589[2] = "\02\0\0\0""'.";____BAH_COMPILER_VAR_589[1] = s->name;____BAH_COMPILER_VAR_589[0] = "\034\0\0\0"" or declare the var as 'new ";char * ____BAH_COMPILER_VAR_590 =__Bah_multiple_concat(____BAH_COMPILER_VAR_589, 3);globCheck = ____BAH_COMPILER_VAR_590;
}

#line 11 "/home/alois/Documents/bah-bah/src/safety.bah"
char** ____BAH_COMPILER_VAR_591 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_591[2] = "\01\0\0\0"".";____BAH_COMPILER_VAR_591[1] = globCheck;____BAH_COMPILER_VAR_591[0] = "\074\0\0\0""{TOKEN} can contain a null value. Check if the value is null";char * ____BAH_COMPILER_VAR_592 =__Bah_multiple_concat(____BAH_COMPILER_VAR_591, 3);throwErr(t,____BAH_COMPILER_VAR_592);
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
char** ____BAH_COMPILER_VAR_593 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_593[1] = name;____BAH_COMPILER_VAR_593[0] = "\01\0\0\0""&";char * ____BAH_COMPILER_VAR_594 =__Bah_multiple_concat(____BAH_COMPILER_VAR_593, 2);name = ____BAH_COMPILER_VAR_594;
}

#line 79 "/home/alois/Documents/bah-bah/src/safety.bah"
char** ____BAH_COMPILER_VAR_595 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_595[8] = "\010\0\0\0""\");\n    ";____BAH_COMPILER_VAR_595[7] = intToStr(t->line);____BAH_COMPILER_VAR_595[6] = "\01\0\0\0"":";____BAH_COMPILER_VAR_595[5] = compilerState.currentFile;____BAH_COMPILER_VAR_595[4] = "\03\0\0\0"", \"";____BAH_COMPILER_VAR_595[3] = name;____BAH_COMPILER_VAR_595[2] = "\03\0\0\0""\", ";____BAH_COMPILER_VAR_595[1] = v->name;____BAH_COMPILER_VAR_595[0] = "\022\0\0\0""\n    fixMeAddVar(\"";char * ____BAH_COMPILER_VAR_596 =__Bah_multiple_concat(____BAH_COMPILER_VAR_595, 9);char** ____BAH_COMPILER_VAR_597 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_597[1] = ____BAH_COMPILER_VAR_596;____BAH_COMPILER_VAR_597[0] = NEXT_LINE;char * ____BAH_COMPILER_VAR_598 =__Bah_multiple_concat(____BAH_COMPILER_VAR_597, 2);NEXT_LINE = ____BAH_COMPILER_VAR_598;
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
char** ____BAH_COMPILER_VAR_599 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_599[1] = name;____BAH_COMPILER_VAR_599[0] = "\01\0\0\0""&";char * ____BAH_COMPILER_VAR_600 =__Bah_multiple_concat(____BAH_COMPILER_VAR_599, 2);name = ____BAH_COMPILER_VAR_600;
}

#line 97 "/home/alois/Documents/bah-bah/src/safety.bah"
else {

#line 98 "/home/alois/Documents/bah-bah/src/safety.bah"
continue;
}

#line 100 "/home/alois/Documents/bah-bah/src/safety.bah"
char** ____BAH_COMPILER_VAR_601 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_601[8] = "\020\0\0\0""\");\n            ";____BAH_COMPILER_VAR_601[7] = intToStr(t->line);____BAH_COMPILER_VAR_601[6] = "\01\0\0\0"":";____BAH_COMPILER_VAR_601[5] = compilerState.currentFile;____BAH_COMPILER_VAR_601[4] = "\03\0\0\0"", \"";____BAH_COMPILER_VAR_601[3] = name;____BAH_COMPILER_VAR_601[2] = "\03\0\0\0""\", ";____BAH_COMPILER_VAR_601[1] = v->name;____BAH_COMPILER_VAR_601[0] = "\032\0\0\0""\n            fixMeRemVar(\"";char * ____BAH_COMPILER_VAR_602 =__Bah_multiple_concat(____BAH_COMPILER_VAR_601, 9);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_602));
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
char** ____BAH_COMPILER_VAR_603 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_603[1] = name;____BAH_COMPILER_VAR_603[0] = "\01\0\0\0""&";char * ____BAH_COMPILER_VAR_604 =__Bah_multiple_concat(____BAH_COMPILER_VAR_603, 2);name = ____BAH_COMPILER_VAR_604;
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
char** ____BAH_COMPILER_VAR_605 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_605[8] = "\02\0\0\0""\")";____BAH_COMPILER_VAR_605[7] = intToStr(t->line);____BAH_COMPILER_VAR_605[6] = "\01\0\0\0"":";____BAH_COMPILER_VAR_605[5] = compilerState.currentFile;____BAH_COMPILER_VAR_605[4] = "\04\0\0\0""\", \"";____BAH_COMPILER_VAR_605[3] = t->cont;____BAH_COMPILER_VAR_605[2] = "\03\0\0\0"", \"";____BAH_COMPILER_VAR_605[1] = name;____BAH_COMPILER_VAR_605[0] = "\015\0\0\0""fixMeIsVarOk(";char * ____BAH_COMPILER_VAR_606 =__Bah_multiple_concat(____BAH_COMPILER_VAR_605, 9);char * fn = ____BAH_COMPILER_VAR_606;

#line 133 "/home/alois/Documents/bah-bah/src/safety.bah"
if ((ltp==LINE_TYPE_ELSE)) {

#line 134 "/home/alois/Documents/bah-bah/src/safety.bah"
char** ____BAH_COMPILER_VAR_607 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_607[1] = "\02\0\0\0""&&";____BAH_COMPILER_VAR_607[0] = fn;char * ____BAH_COMPILER_VAR_608 =__Bah_multiple_concat(____BAH_COMPILER_VAR_607, 2);prevIfShortcut = ____BAH_COMPILER_VAR_608;

#line 135 "/home/alois/Documents/bah-bah/src/safety.bah"
return;
}

#line 138 "/home/alois/Documents/bah-bah/src/safety.bah"
char** ____BAH_COMPILER_VAR_609 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_609[1] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_609[0] = fn;char * ____BAH_COMPILER_VAR_610 =__Bah_multiple_concat(____BAH_COMPILER_VAR_609, 2);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_610));
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

    unsigned int ____BAH_COMPILER_VAR_611 = i;
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_611);
    nl->data[____BAH_COMPILER_VAR_611] = t;

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
char * ____BAH_COMPILER_VAR_612 =string__str(&tc);struct string cCast = getCType(____BAH_COMPILER_VAR_612,elems);

#line 163 "/home/alois/Documents/bah-bah/src/parser.bah"
char * cCastStr = string__str(&cCast);

#line 164 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_613 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_613[3] = nnnt.cont;____BAH_COMPILER_VAR_613[2] = "\01\0\0\0"")";____BAH_COMPILER_VAR_613[1] = cCastStr;____BAH_COMPILER_VAR_613[0] = "\01\0\0\0""(";char * ____BAH_COMPILER_VAR_614 =__Bah_multiple_concat(____BAH_COMPILER_VAR_613, 4);nnnt.cont = ____BAH_COMPILER_VAR_614;

#line 165 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_615 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_615);
    nl->data[____BAH_COMPILER_VAR_615] = nnnt;

#line 166 "/home/alois/Documents/bah-bah/src/parser.bah"
i = i+2;

#line 167 "/home/alois/Documents/bah-bah/src/parser.bah"
continue;
}
}

#line 171 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_616 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_616);
    nl->data[____BAH_COMPILER_VAR_616] = t;
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
char ____BAH_COMPILER_VAR_617(array(char *)* arr, char * el) {
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
if (____BAH_COMPILER_VAR_617(compilerState.includes, ccstr)) {

#line 217 "/home/alois/Documents/bah-bah/src/parser.bah"
return true;
}

#line 221 "/home/alois/Documents/bah-bah/src/parser.bah"
struct fileStream ____BAH_COMPILER_VAR_618 = {};
struct fileStream fs = ____BAH_COMPILER_VAR_618;

#line 222 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_619 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_619[1] = ccstr;____BAH_COMPILER_VAR_619[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_620 =__Bah_multiple_concat(____BAH_COMPILER_VAR_619, 2);char * fileName = ____BAH_COMPILER_VAR_620;

#line 223 "/home/alois/Documents/bah-bah/src/parser.bah"
char isBahDir = true;

#line 224 "/home/alois/Documents/bah-bah/src/parser.bah"
fileStream__open(&fs,fileName,"\01\0\0\0""r");

#line 225 "/home/alois/Documents/bah-bah/src/parser.bah"
char * f = fileStream__readContent(&fs);

#line 226 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((fileStream__isValid(&fs)==0)) {

#line 227 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_621 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_621[1] = ccstr;____BAH_COMPILER_VAR_621[0] = compilerState.currentDir;char * ____BAH_COMPILER_VAR_622 =__Bah_multiple_concat(____BAH_COMPILER_VAR_621, 2);fileName = absPath(____BAH_COMPILER_VAR_622);

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
char** ____BAH_COMPILER_VAR_623 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_623[1] = getDirFromFile(ccstr);____BAH_COMPILER_VAR_623[0] = compilerState.currentDir;char * ____BAH_COMPILER_VAR_624 =__Bah_multiple_concat(____BAH_COMPILER_VAR_623, 2);compilerState.currentDir = ____BAH_COMPILER_VAR_624;
}

#line 240 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 241 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_625 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_625[1] = getDirFromFile(ccstr);____BAH_COMPILER_VAR_625[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_626 =__Bah_multiple_concat(____BAH_COMPILER_VAR_625, 2);compilerState.currentDir = ____BAH_COMPILER_VAR_626;
}

#line 245 "/home/alois/Documents/bah-bah/src/parser.bah"
char * oFile = compilerState.currentFile;

#line 246 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.currentFile = fileName;

#line 247 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_627 = len(compilerState.includes);
    __Bah_realocate_arr(compilerState.includes, ____BAH_COMPILER_VAR_627);
    compilerState.includes->data[____BAH_COMPILER_VAR_627] = ccstr;

#line 250 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct Tok)* tokens = lexer(f,fileStream__getSize(&fs));

#line 251 "/home/alois/Documents/bah-bah/src/parser.bah"
fileStream__close(&fs);

#line 252 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((len(tokens)==0), 0)) {

#line 253 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_628 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_628[2] = "\021\0\0\0""' not recognized.";____BAH_COMPILER_VAR_628[1] = ccstr;____BAH_COMPILER_VAR_628[0] = "\06\0\0\0""File '";char * ____BAH_COMPILER_VAR_629 =__Bah_multiple_concat(____BAH_COMPILER_VAR_628, 3);__BAH_panic(____BAH_COMPILER_VAR_629,"\060\0\0\0""/home/alois/Documents/bah-bah/src/parser.bah:253");
}

#line 257 "/home/alois/Documents/bah-bah/src/parser.bah"
char oshd = shouldOnlyDecl;

#line 258 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((isObject==true)) {

#line 259 "/home/alois/Documents/bah-bah/src/parser.bah"

                struct string ____BAH_COMPILER_VAR_630 = string(compilerState.currentFile);
                if ((isBahDir==true)||(string__hasPrefix(&____BAH_COMPILER_VAR_630,oDir)==false)) {

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

                struct string ____BAH_COMPILER_VAR_631 = string(compilerState.currentFile);
                if ((isBahDir==true)||(string__hasPrefix(&____BAH_COMPILER_VAR_631,oDir)==false)) {

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
struct cacheFile* ____BAH_COMPILER_VAR_632 = memoryAlloc(sizeof(struct cacheFile));
____BAH_COMPILER_VAR_632->files = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_632->files->length = 0;
            ____BAH_COMPILER_VAR_632->files->elemSize = sizeof(char *);
            scf = ____BAH_COMPILER_VAR_632;
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
char** ____BAH_COMPILER_VAR_633 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_633[1] = fn;____BAH_COMPILER_VAR_633[0] = "\014\0\0\0""[compiling] ";char * ____BAH_COMPILER_VAR_634 =__Bah_multiple_concat(____BAH_COMPILER_VAR_633, 2);println(____BAH_COMPILER_VAR_634);
}

#line 321 "/home/alois/Documents/bah-bah/src/parser.bah"
char * opti = "\0\0\0\0""";

#line 322 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((isOptimized==true)) {

#line 323 "/home/alois/Documents/bah-bah/src/parser.bah"
opti = "\011\0\0\0""-optimize";
}

#line 325 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_635 = alloca(11 * sizeof(char*));____BAH_COMPILER_VAR_635[10] = oName;____BAH_COMPILER_VAR_635[9] = "\04\0\0\0"" -o ";____BAH_COMPILER_VAR_635[8] = verboseCC;____BAH_COMPILER_VAR_635[7] = "\011\0\0\0"" -object ";____BAH_COMPILER_VAR_635[6] = opti;____BAH_COMPILER_VAR_635[5] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_635[4] = rcp;____BAH_COMPILER_VAR_635[3] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_635[2] = fn;____BAH_COMPILER_VAR_635[1] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_635[0] = execName;char * ____BAH_COMPILER_VAR_636 =__Bah_multiple_concat(____BAH_COMPILER_VAR_635, 11);struct command cmd = command(____BAH_COMPILER_VAR_636);

#line 326 "/home/alois/Documents/bah-bah/src/parser.bah"
array(char)* res = command__runBytes(&cmd);

#line 327 "/home/alois/Documents/bah-bah/src/parser.bah"
setCurrentPath(wrkd);

#line 328 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((cmd.status!=0), 0)) {

#line 329 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ____BAH_COMPILER_VAR_637 =arrToStr(res);print(____BAH_COMPILER_VAR_637);

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

        char ____BAH_COMPILER_VAR_638 = true;
        channel__sendAny(done, &____BAH_COMPILER_VAR_638, sizeof(____BAH_COMPILER_VAR_638));
        };

#line 342 "/home/alois/Documents/bah-bah/src/parser.bah"
char ____BAH_COMPILER_VAR_639(array(char *)* arr, char * el) {
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
if (____BAH_COMPILER_VAR_639(compilerState.includes, string__str(&fileName))) {

#line 360 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}

#line 362 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_640 = len(compilerState.includes);
    __Bah_realocate_arr(compilerState.includes, ____BAH_COMPILER_VAR_640);
    compilerState.includes->data[____BAH_COMPILER_VAR_640] = string__str(&fileName);

#line 365 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_641 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_641[1] = string__str(&fileName);____BAH_COMPILER_VAR_641[0] = compilerState.currentDir;char * ____BAH_COMPILER_VAR_642 =__Bah_multiple_concat(____BAH_COMPILER_VAR_641, 2);char * fn = absPath(____BAH_COMPILER_VAR_642);

#line 366 "/home/alois/Documents/bah-bah/src/parser.bah"
if (((void *)fn==null)) {

#line 367 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_643 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_643[1] = string__str(&fileName);____BAH_COMPILER_VAR_643[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_644 =__Bah_multiple_concat(____BAH_COMPILER_VAR_643, 2);fn = absPath(____BAH_COMPILER_VAR_644);

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
struct fileStream ____BAH_COMPILER_VAR_645 = {};
struct fileStream fs = ____BAH_COMPILER_VAR_645;

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
char** ____BAH_COMPILER_VAR_646 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_646[5] = "\02\0\0\0"".o";____BAH_COMPILER_VAR_646[4] = intToStr(isOptimized);____BAH_COMPILER_VAR_646[3] = intToStr(RCPlevel);____BAH_COMPILER_VAR_646[2] = pathToVarName(fn);____BAH_COMPILER_VAR_646[1] = "\06\0\0\0""cache/";____BAH_COMPILER_VAR_646[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_647 =__Bah_multiple_concat(____BAH_COMPILER_VAR_646, 6);char * oName = ____BAH_COMPILER_VAR_647;

#line 402 "/home/alois/Documents/bah-bah/src/parser.bah"
unsigned long int i = len(compilerState.cLibs);

#line 402 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i!=0); 
#line 402 "/home/alois/Documents/bah-bah/src/parser.bah"
--i) {

#line 403 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_648 = i;
    __Bah_realocate_arr(compilerState.cLibs, ____BAH_COMPILER_VAR_648);
    compilerState.cLibs->data[____BAH_COMPILER_VAR_648] = compilerState.cLibs->data[i-1];
};

#line 406 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_649 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_649[2] = "\02\0\0\0"".o";____BAH_COMPILER_VAR_649[1] = oName;____BAH_COMPILER_VAR_649[0] = "\02\0\0\0""w ";char * ____BAH_COMPILER_VAR_650 =__Bah_multiple_concat(____BAH_COMPILER_VAR_649, 3);
    unsigned int ____BAH_COMPILER_VAR_651 = 0;
    __Bah_realocate_arr(compilerState.cLibs, ____BAH_COMPILER_VAR_651);
    compilerState.cLibs->data[____BAH_COMPILER_VAR_651] = ____BAH_COMPILER_VAR_650;

#line 408 "/home/alois/Documents/bah-bah/src/parser.bah"
struct channel * done = channel();

#line 411 "/home/alois/Documents/bah-bah/src/parser.bah"
parallelObjCompile(fn,oName,done);

#line 414 "/home/alois/Documents/bah-bah/src/parser.bah"
parseLines(tokens,elems);

#line 416 "/home/alois/Documents/bah-bah/src/parser.bah"
char ok = *(char*)channel__receive(done);

#line 419 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_652 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_652[2] = "\04\0\0\0""();\n";____BAH_COMPILER_VAR_652[1] = pathToVarName(fn);____BAH_COMPILER_VAR_652[0] = "\012\0\0\0""__BAH_init";char * ____BAH_COMPILER_VAR_653 =__Bah_multiple_concat(____BAH_COMPILER_VAR_652, 3);INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_653));

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
char** ____BAH_COMPILER_VAR_654 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_654[2] = "\01\0\0\0""\n";____BAH_COMPILER_VAR_654[1] = sc;____BAH_COMPILER_VAR_654[0] = "\011\0\0\0""#include ";char * ____BAH_COMPILER_VAR_655 =__Bah_multiple_concat(____BAH_COMPILER_VAR_654, 3);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_655));

#line 451 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_656 = len(compilerState.cIncludes);
    __Bah_realocate_arr(compilerState.cIncludes, ____BAH_COMPILER_VAR_656);
    compilerState.cIncludes->data[____BAH_COMPILER_VAR_656] = sc;
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

    unsigned int ____BAH_COMPILER_VAR_657 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_657);
    nl->data[____BAH_COMPILER_VAR_657] = t;

#line 480 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 481 "/home/alois/Documents/bah-bah/src/parser.bah"
continue;
}

#line 483 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 484 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok ____BAH_COMPILER_VAR_658 = {};
____BAH_COMPILER_VAR_658.cont = "\0\0\0\0""";
____BAH_COMPILER_VAR_658.ogCont = "\0\0\0\0""";
____BAH_COMPILER_VAR_658.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_658.line = 1;
____BAH_COMPILER_VAR_658.begLine = 1;
____BAH_COMPILER_VAR_658.bahType = "\0\0\0\0""";
____BAH_COMPILER_VAR_658.cont = "\0\0\0\0""";
struct Tok nt = ____BAH_COMPILER_VAR_658;

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
struct variable* ____BAH_COMPILER_VAR_659 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_659->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_659->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_659->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_659->from = "\0\0\0\0""";
struct variable* tmpV = ____BAH_COMPILER_VAR_659;

#line 501 "/home/alois/Documents/bah-bah/src/parser.bah"
tmpV->name = t.cont;

#line 502 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_660 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_660[1] = "\01\0\0\0""*";____BAH_COMPILER_VAR_660[0] = s->name;char * ____BAH_COMPILER_VAR_661 =__Bah_multiple_concat(____BAH_COMPILER_VAR_660, 2);tmpV->type = ____BAH_COMPILER_VAR_661;

#line 503 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string cType = getCType(tmpV->type,elems);

#line 504 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string structType = getCType(s->name,elems);

#line 505 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_662 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_662);
    elems->vars->data[____BAH_COMPILER_VAR_662] = tmpV;

#line 507 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_663 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_663[6] = declareStructMethods(tmpV,s,elems);____BAH_COMPILER_VAR_663[5] = "\04\0\0\0""));\n";____BAH_COMPILER_VAR_663[4] = string__str(&structType);____BAH_COMPILER_VAR_663[3] = "\026\0\0\0"" = memoryAlloc(sizeof(";____BAH_COMPILER_VAR_663[2] = t.cont;____BAH_COMPILER_VAR_663[1] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_663[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_664 =__Bah_multiple_concat(____BAH_COMPILER_VAR_663, 7);struct rope* r = rope(____BAH_COMPILER_VAR_664);

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

    unsigned int ____BAH_COMPILER_VAR_665 = len(nl)-1;
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_665);
    nl->data[____BAH_COMPILER_VAR_665] = t;

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

    unsigned int ____BAH_COMPILER_VAR_666 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_666);
    memory->data[____BAH_COMPILER_VAR_666] = t;
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
struct variable* ____BAH_COMPILER_VAR_667 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_667->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_667->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_667->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_667->from = "\0\0\0\0""";
struct variable* tmpV = ____BAH_COMPILER_VAR_667;

#line 564 "/home/alois/Documents/bah-bah/src/parser.bah"
tmpV->name = rvn;

#line 565 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((isHeap==true)) {

#line 566 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_668 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_668[1] = "\01\0\0\0""*";____BAH_COMPILER_VAR_668[0] = s->name;char * ____BAH_COMPILER_VAR_669 =__Bah_multiple_concat(____BAH_COMPILER_VAR_668, 2);tmpV->type = ____BAH_COMPILER_VAR_669;

#line 567 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_670 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_670);
    elems->vars->data[____BAH_COMPILER_VAR_670] = tmpV;
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
char * ____BAH_COMPILER_VAR_671 =string__str(&rst);struct string structType = string(____BAH_COMPILER_VAR_671);

#line 577 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimRight(&structType,1);

#line 578 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_672 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_672[6] = declareStructMethods(tmpV,s,elems);____BAH_COMPILER_VAR_672[5] = "\04\0\0\0""));\n";____BAH_COMPILER_VAR_672[4] = string__str(&structType);____BAH_COMPILER_VAR_672[3] = "\026\0\0\0"" = memoryAlloc(sizeof(";____BAH_COMPILER_VAR_672[2] = rvn;____BAH_COMPILER_VAR_672[1] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_672[0] = string__str(&rst);char * ____BAH_COMPILER_VAR_673 =__Bah_multiple_concat(____BAH_COMPILER_VAR_672, 7);r = rope(____BAH_COMPILER_VAR_673);
}

#line 579 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 580 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_674 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_674[4] = declareStructMethods(tmpV,s,elems);____BAH_COMPILER_VAR_674[3] = "\07\0\0\0"" = {};\n";____BAH_COMPILER_VAR_674[2] = rvn;____BAH_COMPILER_VAR_674[1] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_674[0] = string__str(&rst);char * ____BAH_COMPILER_VAR_675 =__Bah_multiple_concat(____BAH_COMPILER_VAR_674, 5);r = rope(____BAH_COMPILER_VAR_675);
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
char** ____BAH_COMPILER_VAR_676 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_676[4] = "\02\0\0\0""'.";____BAH_COMPILER_VAR_676[3] = m->type;____BAH_COMPILER_VAR_676[2] = "\06\0\0\0"") as '";____BAH_COMPILER_VAR_676[1] = vlt;____BAH_COMPILER_VAR_676[0] = "\024\0\0\0""Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_677 =__Bah_multiple_concat(____BAH_COMPILER_VAR_676, 5);throwErr(&vl,____BAH_COMPILER_VAR_677);
}

#line 606 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_678 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_678[5] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_678[4] = vl.cont;____BAH_COMPILER_VAR_678[3] = "\03\0\0\0"" = ";____BAH_COMPILER_VAR_678[2] = m->name;____BAH_COMPILER_VAR_678[1] = sep;____BAH_COMPILER_VAR_678[0] = rvn;char * ____BAH_COMPILER_VAR_679 =__Bah_multiple_concat(____BAH_COMPILER_VAR_678, 6);r = rope__add(r, rope(____BAH_COMPILER_VAR_679));

#line 607 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
};

#line 609 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((j==len(s->members)), 0)) {

#line 610 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_680 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_680[2] = "\037\0\0\0""' has no member called {TOKEN}.";____BAH_COMPILER_VAR_680[1] = s->name;____BAH_COMPILER_VAR_680[0] = "\010\0\0\0""Struct '";char * ____BAH_COMPILER_VAR_681 =__Bah_multiple_concat(____BAH_COMPILER_VAR_680, 3);throwErr(&t,____BAH_COMPILER_VAR_681);
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
char** ____BAH_COMPILER_VAR_682 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_682[4] = "\02\0\0\0""'.";____BAH_COMPILER_VAR_682[3] = m->type;____BAH_COMPILER_VAR_682[2] = "\06\0\0\0"") as '";____BAH_COMPILER_VAR_682[1] = tt;____BAH_COMPILER_VAR_682[0] = "\024\0\0\0""Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_683 =__Bah_multiple_concat(____BAH_COMPILER_VAR_682, 5);throwErr(&t,____BAH_COMPILER_VAR_683);
}

#line 632 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_684 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_684[5] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_684[4] = t.cont;____BAH_COMPILER_VAR_684[3] = "\03\0\0\0"" = ";____BAH_COMPILER_VAR_684[2] = m->name;____BAH_COMPILER_VAR_684[1] = sep;____BAH_COMPILER_VAR_684[0] = rvn;char * ____BAH_COMPILER_VAR_685 =__Bah_multiple_concat(____BAH_COMPILER_VAR_684, 6);r = rope__add(r, rope(____BAH_COMPILER_VAR_685));

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

    unsigned int ____BAH_COMPILER_VAR_686 = len(nl)-1;
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_686);
    nl->data[____BAH_COMPILER_VAR_686] = t;
}

#line 657 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 658 "/home/alois/Documents/bah-bah/src/parser.bah"
t.isEqual = true;

#line 659 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_687 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_687);
    nl->data[____BAH_COMPILER_VAR_687] = t;
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

    unsigned int ____BAH_COMPILER_VAR_688 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_688);
    nl->data[____BAH_COMPILER_VAR_688] = t;

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
char** ____BAH_COMPILER_VAR_689 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_689[1] = "\02\0\0\0""[]";____BAH_COMPILER_VAR_689[0] = bracks;char * ____BAH_COMPILER_VAR_690 =__Bah_multiple_concat(____BAH_COMPILER_VAR_689, 2);bracks = ____BAH_COMPILER_VAR_690;

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
char** ____BAH_COMPILER_VAR_691 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_691[1] = arrElem;____BAH_COMPILER_VAR_691[0] = bracks;char * ____BAH_COMPILER_VAR_692 =__Bah_multiple_concat(____BAH_COMPILER_VAR_691, 2);t.bahType = ____BAH_COMPILER_VAR_692;

#line 720 "/home/alois/Documents/bah-bah/src/parser.bah"
t.cont = "\0\0\0\0""";

#line 721 "/home/alois/Documents/bah-bah/src/parser.bah"
t.isValue = true;

#line 722 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_693 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_693);
    nl->data[____BAH_COMPILER_VAR_693] = t;

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

    unsigned int ____BAH_COMPILER_VAR_694 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_694);
    nl->data[____BAH_COMPILER_VAR_694] = t;
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
char** ____BAH_COMPILER_VAR_695 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_695[1] = t.cont;____BAH_COMPILER_VAR_695[0] = l->data[i-1].cont;char * ____BAH_COMPILER_VAR_696 =__Bah_multiple_concat(____BAH_COMPILER_VAR_695, 2);l->data[i-1].cont = ____BAH_COMPILER_VAR_696;

#line 754 "/home/alois/Documents/bah-bah/src/parser.bah"
delete(l,i);

#line 755 "/home/alois/Documents/bah-bah/src/parser.bah"
--i;
}
}

#line 757 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 758 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_697 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_697[1] = t.cont;____BAH_COMPILER_VAR_697[0] = l->data[i-1].cont;char * ____BAH_COMPILER_VAR_698 =__Bah_multiple_concat(____BAH_COMPILER_VAR_697, 2);l->data[i-1].cont = ____BAH_COMPILER_VAR_698;

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
char** ____BAH_COMPILER_VAR_699 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_699[1] = l->data[i+1].cont;____BAH_COMPILER_VAR_699[0] = t.cont;char * ____BAH_COMPILER_VAR_700 =__Bah_multiple_concat(____BAH_COMPILER_VAR_699, 2);l->data[i+1].cont = ____BAH_COMPILER_VAR_700;

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
char** ____BAH_COMPILER_VAR_701 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_701[5] = "\01\0\0\0"")";____BAH_COMPILER_VAR_701[4] = string__str(&svt);____BAH_COMPILER_VAR_701[3] = "\016\0\0\0""sizeof(struct ";____BAH_COMPILER_VAR_701[2] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_701[1] = e->cont;____BAH_COMPILER_VAR_701[0] = "\015\0\0\0""__serialize(&";char * ____BAH_COMPILER_VAR_702 =__Bah_multiple_concat(____BAH_COMPILER_VAR_701, 6);code = ____BAH_COMPILER_VAR_702;
}

#line 808 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 809 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ptrRect = "\0\0\0\0""";

#line 810 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((ptrLevel>1)) {

#line 811 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_703 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_703[1] = "\01\0\0\0""*";____BAH_COMPILER_VAR_703[0] = ptrRect;char * ____BAH_COMPILER_VAR_704 =__Bah_multiple_concat(____BAH_COMPILER_VAR_703, 2);ptrRect = ____BAH_COMPILER_VAR_704;

#line 812 "/home/alois/Documents/bah-bah/src/parser.bah"
ptrLevel = ptrLevel-1;
};

#line 814 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_705 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_705[6] = "\01\0\0\0"")";____BAH_COMPILER_VAR_705[5] = string__str(&svt);____BAH_COMPILER_VAR_705[4] = "\016\0\0\0""sizeof(struct ";____BAH_COMPILER_VAR_705[3] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_705[2] = e->cont;____BAH_COMPILER_VAR_705[1] = ptrRect;____BAH_COMPILER_VAR_705[0] = "\014\0\0\0""__serialize(";char * ____BAH_COMPILER_VAR_706 =__Bah_multiple_concat(____BAH_COMPILER_VAR_705, 7);code = ____BAH_COMPILER_VAR_706;

#line 817 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int i = 0;

#line 817 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i<len(s->members))) {

#line 818 "/home/alois/Documents/bah-bah/src/parser.bah"
struct structMemb* m = s->members->data[i];

#line 819 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(m->type, "\010\0\0\0""cpstring") == 0)) {

#line 820 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_707 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_707[5] = "\01\0\0\0"")";____BAH_COMPILER_VAR_707[4] = m->name;____BAH_COMPILER_VAR_707[3] = "\02\0\0\0""->";____BAH_COMPILER_VAR_707[2] = e->cont;____BAH_COMPILER_VAR_707[1] = "\010\0\0\0""+strlen(";____BAH_COMPILER_VAR_707[0] = code;char * ____BAH_COMPILER_VAR_708 =__Bah_multiple_concat(____BAH_COMPILER_VAR_707, 6);code = ____BAH_COMPILER_VAR_708;
}

#line 822 "/home/alois/Documents/bah-bah/src/parser.bah"
i = i+1;
};
}

#line 828 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_709 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_709[1] = "\01\0\0\0"")";____BAH_COMPILER_VAR_709[0] = code;char * ____BAH_COMPILER_VAR_710 =__Bah_multiple_concat(____BAH_COMPILER_VAR_709, 2);return ____BAH_COMPILER_VAR_710;
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
char** ____BAH_COMPILER_VAR_711 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_711[5] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_711[4] = t.cont;____BAH_COMPILER_VAR_711[3] = "\03\0\0\0"" = ";____BAH_COMPILER_VAR_711[2] = v;____BAH_COMPILER_VAR_711[1] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_711[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_712 =__Bah_multiple_concat(____BAH_COMPILER_VAR_711, 6);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_712));

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
struct Tok ____BAH_COMPILER_VAR_713 = {};
____BAH_COMPILER_VAR_713.cont = "\0\0\0\0""";
____BAH_COMPILER_VAR_713.ogCont = "\0\0\0\0""";
____BAH_COMPILER_VAR_713.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_713.line = 1;
____BAH_COMPILER_VAR_713.begLine = 1;
____BAH_COMPILER_VAR_713.bahType = "\0\0\0\0""";
struct Tok tmpT = ____BAH_COMPILER_VAR_713;

#line 859 "/home/alois/Documents/bah-bah/src/parser.bah"
tmpT.type = TOKEN_TYPE_VAR;

#line 860 "/home/alois/Documents/bah-bah/src/parser.bah"
tmpT.cont = "\01\0\0\0""0";

#line 861 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ____BAH_COMPILER_VAR_714 =string__str(&aet);struct Tok rt = parseReflect(tmpT,____BAH_COMPILER_VAR_714,elems,true,"\0\0\0\0""","\01\0\0\0""0");

#line 863 "/home/alois/Documents/bah-bah/src/parser.bah"
char * aev = genCompilerVar();

#line 865 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_715 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_715[4] = "\012\0\0\0"";\n        ";____BAH_COMPILER_VAR_715[3] = rt.cont;____BAH_COMPILER_VAR_715[2] = "\03\0\0\0"" = ";____BAH_COMPILER_VAR_715[1] = aev;____BAH_COMPILER_VAR_715[0] = "\037\0\0\0""\n        struct reflectElement ";char * ____BAH_COMPILER_VAR_716 =__Bah_multiple_concat(____BAH_COMPILER_VAR_715, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_716));

#line 869 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_717 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_717[1] = aev;____BAH_COMPILER_VAR_717[0] = "\01\0\0\0""&";char * ____BAH_COMPILER_VAR_718 =__Bah_multiple_concat(____BAH_COMPILER_VAR_717, 2);arrElem = ____BAH_COMPILER_VAR_718;
}

#line 870 "/home/alois/Documents/bah-bah/src/parser.bah"
else if (strHasPrefix(tt,"\04\0\0\0""map:")) {

#line 871 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string aet = string(tt);

#line 872 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimLeft(&aet,4);

#line 873 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok ____BAH_COMPILER_VAR_719 = {};
____BAH_COMPILER_VAR_719.cont = "\0\0\0\0""";
____BAH_COMPILER_VAR_719.ogCont = "\0\0\0\0""";
____BAH_COMPILER_VAR_719.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_719.line = 1;
____BAH_COMPILER_VAR_719.begLine = 1;
____BAH_COMPILER_VAR_719.bahType = "\0\0\0\0""";
struct Tok tmpT = ____BAH_COMPILER_VAR_719;

#line 874 "/home/alois/Documents/bah-bah/src/parser.bah"
tmpT.type = TOKEN_TYPE_VAR;

#line 875 "/home/alois/Documents/bah-bah/src/parser.bah"
tmpT.cont = "\01\0\0\0""0";

#line 876 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ____BAH_COMPILER_VAR_720 =string__str(&aet);struct Tok rt = parseReflect(tmpT,____BAH_COMPILER_VAR_720,elems,true,"\0\0\0\0""","\01\0\0\0""0");

#line 877 "/home/alois/Documents/bah-bah/src/parser.bah"
char * aev = genCompilerVar();

#line 878 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_721 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_721[4] = "\012\0\0\0"";\n        ";____BAH_COMPILER_VAR_721[3] = rt.cont;____BAH_COMPILER_VAR_721[2] = "\03\0\0\0"" = ";____BAH_COMPILER_VAR_721[1] = aev;____BAH_COMPILER_VAR_721[0] = "\037\0\0\0""\n        struct reflectElement ";char * ____BAH_COMPILER_VAR_722 =__Bah_multiple_concat(____BAH_COMPILER_VAR_721, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_722));

#line 881 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_723 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_723[1] = aev;____BAH_COMPILER_VAR_723[0] = "\01\0\0\0""&";char * ____BAH_COMPILER_VAR_724 =__Bah_multiple_concat(____BAH_COMPILER_VAR_723, 2);arrElem = ____BAH_COMPILER_VAR_724;
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
struct variable* ____BAH_COMPILER_VAR_725 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_725->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_725->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_725->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_725->from = "\0\0\0\0""";
struct variable* slv = ____BAH_COMPILER_VAR_725;

#line 893 "/home/alois/Documents/bah-bah/src/parser.bah"
slv->name = structLayout;

#line 894 "/home/alois/Documents/bah-bah/src/parser.bah"
slv->type = "\020\0\0\0""[]reflectElement";

#line 896 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_726 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_726);
    elems->vars->data[____BAH_COMPILER_VAR_726] = slv;

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
struct structMemb* ____BAH_COMPILER_VAR_727 = memoryAlloc(sizeof(struct structMemb));
____BAH_COMPILER_VAR_727->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_727->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_727->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_727->from = "\0\0\0\0""";
____BAH_COMPILER_VAR_727->def = "\0\0\0\0""";
struct structMemb* nm = ____BAH_COMPILER_VAR_727;

#line 904 "/home/alois/Documents/bah-bah/src/parser.bah"
*nm = *m;

#line 905 "/home/alois/Documents/bah-bah/src/parser.bah"
m = nm;

#line 906 "/home/alois/Documents/bah-bah/src/parser.bah"
m->type = "\03\0\0\0""ptr";
}

#line 908 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok ____BAH_COMPILER_VAR_728 = {};
____BAH_COMPILER_VAR_728.cont = "\0\0\0\0""";
____BAH_COMPILER_VAR_728.ogCont = "\0\0\0\0""";
____BAH_COMPILER_VAR_728.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_728.line = 1;
____BAH_COMPILER_VAR_728.begLine = 1;
____BAH_COMPILER_VAR_728.bahType = "\0\0\0\0""";
struct Tok tmpT = ____BAH_COMPILER_VAR_728;

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
char** ____BAH_COMPILER_VAR_729 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_729[8] = "\02\0\0\0""))";____BAH_COMPILER_VAR_729[7] = m->name;____BAH_COMPILER_VAR_729[6] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_729[5] = string__str(&offsetTT);____BAH_COMPILER_VAR_729[4] = "\024\0\0\0"") + offsetof(struct ";____BAH_COMPILER_VAR_729[3] = t.cont;____BAH_COMPILER_VAR_729[2] = "\013\0\0\0""*)((char*)(";____BAH_COMPILER_VAR_729[1] = string__str(&mCtype);____BAH_COMPILER_VAR_729[0] = "\01\0\0\0""(";char * ____BAH_COMPILER_VAR_730 =__Bah_multiple_concat(____BAH_COMPILER_VAR_729, 9);tmpT.cont = ____BAH_COMPILER_VAR_730;

#line 918 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_731 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_731[4] = "\01\0\0\0"")";____BAH_COMPILER_VAR_731[3] = m->name;____BAH_COMPILER_VAR_731[2] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_731[1] = string__str(&offsetTT);____BAH_COMPILER_VAR_731[0] = "\020\0\0\0""offsetof(struct ";char * ____BAH_COMPILER_VAR_732 =__Bah_multiple_concat(____BAH_COMPILER_VAR_731, 5);struct Tok rt = parseReflect(tmpT,m->type,elems,true,m->name,____BAH_COMPILER_VAR_732);

#line 919 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_733 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_733[5] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_733[4] = rt.cont;____BAH_COMPILER_VAR_733[3] = "\04\0\0\0""] = ";____BAH_COMPILER_VAR_733[2] = intToStr(i);____BAH_COMPILER_VAR_733[1] = "\07\0\0\0""->data[";____BAH_COMPILER_VAR_733[0] = structLayout;char * ____BAH_COMPILER_VAR_734 =__Bah_multiple_concat(____BAH_COMPILER_VAR_733, 6);dataLayout = rope__add(dataLayout, rope(____BAH_COMPILER_VAR_734));
};

#line 922 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_735 = alloca(15 * sizeof(char*));____BAH_COMPILER_VAR_735[14] = "\025\0\0\0""->elemSize);\n        ";____BAH_COMPILER_VAR_735[13] = structLayout;____BAH_COMPILER_VAR_735[12] = "\013\0\0\0""->length * ";____BAH_COMPILER_VAR_735[11] = structLayout;____BAH_COMPILER_VAR_735[10] = "\025\0\0\0""->data = memoryAlloc(";____BAH_COMPILER_VAR_735[9] = structLayout;____BAH_COMPILER_VAR_735[8] = "\012\0\0\0"";\n        ";____BAH_COMPILER_VAR_735[7] = intToStr(len(ts->members));____BAH_COMPILER_VAR_735[6] = "\013\0\0\0""->length = ";____BAH_COMPILER_VAR_735[5] = structLayout;____BAH_COMPILER_VAR_735[4] = "\064\0\0\0""->elemSize = sizeof(struct reflectElement);\n        ";____BAH_COMPILER_VAR_735[3] = structLayout;____BAH_COMPILER_VAR_735[2] = "\076\0\0\0"" = memoryAlloc(sizeof(array(struct reflectElement)));\n        ";____BAH_COMPILER_VAR_735[1] = structLayout;____BAH_COMPILER_VAR_735[0] = "\050\0\0\0""\n        array(struct reflectElement) * ";char * ____BAH_COMPILER_VAR_736 =__Bah_multiple_concat(____BAH_COMPILER_VAR_735, 15);OUTPUT = rope__add(OUTPUT, rope__add(rope(____BAH_COMPILER_VAR_736), dataLayout));
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
struct variable* ____BAH_COMPILER_VAR_737 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_737->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_737->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_737->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_737->from = "\0\0\0\0""";
struct variable* rv = ____BAH_COMPILER_VAR_737;

#line 958 "/home/alois/Documents/bah-bah/src/parser.bah"
rv->name = genCompilerVar();

#line 959 "/home/alois/Documents/bah-bah/src/parser.bah"
rv->type = "\016\0\0\0""reflectElement";

#line 961 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_738 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_738);
    elems->vars->data[____BAH_COMPILER_VAR_738] = rv;

#line 963 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_739 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_739[2] = "\01\0\0\0""\"";____BAH_COMPILER_VAR_739[1] = tt;____BAH_COMPILER_VAR_739[0] = "\01\0\0\0""\"";char * ____BAH_COMPILER_VAR_740 =__Bah_multiple_concat(____BAH_COMPILER_VAR_739, 3);char** ____BAH_COMPILER_VAR_741 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_741[2] = "\01\0\0\0""\"";____BAH_COMPILER_VAR_741[1] = string__str(&name);____BAH_COMPILER_VAR_741[0] = "\01\0\0\0""\"";char * ____BAH_COMPILER_VAR_742 =__Bah_multiple_concat(____BAH_COMPILER_VAR_741, 3);char** ____BAH_COMPILER_VAR_743 = alloca(22 * sizeof(char*));____BAH_COMPILER_VAR_743[21] = "\03\0\0\0"");\n";____BAH_COMPILER_VAR_743[20] = offset;____BAH_COMPILER_VAR_743[19] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_743[18] = structLayout;____BAH_COMPILER_VAR_743[17] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_743[16] = isStruct;____BAH_COMPILER_VAR_743[15] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_743[14] = arrElem;____BAH_COMPILER_VAR_743[13] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_743[12] = isArr;____BAH_COMPILER_VAR_743[11] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_743[10] = strLitteralToBahStr(____BAH_COMPILER_VAR_742);____BAH_COMPILER_VAR_743[9] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_743[8] = strLitteralToBahStr(____BAH_COMPILER_VAR_740);____BAH_COMPILER_VAR_743[7] = "\03\0\0\0""), ";____BAH_COMPILER_VAR_743[6] = string__str(&cType);____BAH_COMPILER_VAR_743[5] = "\011\0\0\0"", sizeof(";____BAH_COMPILER_VAR_743[4] = t.cont;____BAH_COMPILER_VAR_743[3] = amp;____BAH_COMPILER_VAR_743[2] = "\015\0\0\0"" = __reflect(";____BAH_COMPILER_VAR_743[1] = rv->name;____BAH_COMPILER_VAR_743[0] = "\026\0\0\0""struct reflectElement ";char * ____BAH_COMPILER_VAR_744 =__Bah_multiple_concat(____BAH_COMPILER_VAR_743, 22);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_744));

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
char** ____BAH_COMPILER_VAR_745 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_745[2] = "\02\0\0\0""))";____BAH_COMPILER_VAR_745[1] = string__str(&arrType);____BAH_COMPILER_VAR_745[0] = "\023\0\0\0""memoryAlloc(sizeof(";char * ____BAH_COMPILER_VAR_746 =__Bah_multiple_concat(____BAH_COMPILER_VAR_745, 3);char * code = ____BAH_COMPILER_VAR_746;

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

    unsigned int ____BAH_COMPILER_VAR_747 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_747);
    memory->data[____BAH_COMPILER_VAR_747] = l->data[i];

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
struct variable* ____BAH_COMPILER_VAR_748 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_748->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_748->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_748->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_748->from = "\0\0\0\0""";
struct variable* tmpV = ____BAH_COMPILER_VAR_748;

#line 1014 "/home/alois/Documents/bah-bah/src/parser.bah"
tmpV->name = genCompilerVar();

#line 1015 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string elemType = string(v->type);

#line 1016 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimLeft(&elemType,2);

#line 1017 "/home/alois/Documents/bah-bah/src/parser.bah"
tmpV->type = string__str(&elemType);

#line 1018 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_749 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_749);
    elems->vars->data[____BAH_COMPILER_VAR_749] = tmpV;

#line 1020 "/home/alois/Documents/bah-bah/src/parser.bah"
char * oldNL = NEXT_LINE;

#line 1021 "/home/alois/Documents/bah-bah/src/parser.bah"
NEXT_LINE = "\0\0\0\0""";

#line 1022 "/home/alois/Documents/bah-bah/src/parser.bah"
char * innerCode = parseArrayDecl(tmpV,memory,j,i+1,elems);

#line 1023 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ____BAH_COMPILER_VAR_750 =string__str(&elemType);struct string cType = getCType(____BAH_COMPILER_VAR_750,elems);

#line 1024 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_751 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_751[8] = "\021\0\0\0""\n                ";____BAH_COMPILER_VAR_751[7] = NEXT_LINE;____BAH_COMPILER_VAR_751[6] = "\022\0\0\0"";\n                ";____BAH_COMPILER_VAR_751[5] = innerCode;____BAH_COMPILER_VAR_751[4] = "\03\0\0\0"" = ";____BAH_COMPILER_VAR_751[3] = tmpV->name;____BAH_COMPILER_VAR_751[2] = "\04\0\0\0"") * ";____BAH_COMPILER_VAR_751[1] = string__str(&cType);____BAH_COMPILER_VAR_751[0] = "\027\0\0\0""\n                array(";char * ____BAH_COMPILER_VAR_752 =__Bah_multiple_concat(____BAH_COMPILER_VAR_751, 9);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_752));

#line 1028 "/home/alois/Documents/bah-bah/src/parser.bah"
NEXT_LINE = oldNL;

#line 1030 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok ____BAH_COMPILER_VAR_753 = {};
____BAH_COMPILER_VAR_753.cont = "\0\0\0\0""";
____BAH_COMPILER_VAR_753.ogCont = "\0\0\0\0""";
____BAH_COMPILER_VAR_753.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_753.line = 1;
____BAH_COMPILER_VAR_753.begLine = 1;
____BAH_COMPILER_VAR_753.bahType = "\0\0\0\0""";
____BAH_COMPILER_VAR_753.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_753.cont = tmpV->name;
____BAH_COMPILER_VAR_753.bahType = string__str(&elemType);
____BAH_COMPILER_VAR_753.isValue = true;
t = ____BAH_COMPILER_VAR_753;
}

#line 1038 "/home/alois/Documents/bah-bah/src/parser.bah"
char * tt = getTypeFromToken(&t,true,elems);

#line 1039 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((compTypes(tt,elemBahTypeStr)==false), 0)) {

#line 1040 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_754 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_754[3] = elemBahTypeStr;____BAH_COMPILER_VAR_754[2] = "\05\0\0\0"") as ";____BAH_COMPILER_VAR_754[1] = tt;____BAH_COMPILER_VAR_754[0] = "\024\0\0\0""Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_755 =__Bah_multiple_concat(____BAH_COMPILER_VAR_754, 4);throwErr(&t,____BAH_COMPILER_VAR_755);
}

#line 1043 "/home/alois/Documents/bah-bah/src/parser.bah"
char * strArrayLength = intToStr(arrayLength);

#line 1044 "/home/alois/Documents/bah-bah/src/parser.bah"
arrayLength = arrayLength+1;

#line 1046 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_756 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_756[6] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_756[5] = t.cont;____BAH_COMPILER_VAR_756[4] = "\04\0\0\0""] = ";____BAH_COMPILER_VAR_756[3] = strArrayLength;____BAH_COMPILER_VAR_756[2] = "\07\0\0\0""->data[";____BAH_COMPILER_VAR_756[1] = v->name;____BAH_COMPILER_VAR_756[0] = NEXT_LINE;char * ____BAH_COMPILER_VAR_757 =__Bah_multiple_concat(____BAH_COMPILER_VAR_756, 7);NEXT_LINE = ____BAH_COMPILER_VAR_757;

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
char** ____BAH_COMPILER_VAR_758 = alloca(11 * sizeof(char*));____BAH_COMPILER_VAR_758[10] = NEXT_LINE;____BAH_COMPILER_VAR_758[9] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_758[8] = allocLengthStr;____BAH_COMPILER_VAR_758[7] = "\017\0\0\0""->realLength = ";____BAH_COMPILER_VAR_758[6] = v->name;____BAH_COMPILER_VAR_758[5] = "\027\0\0\0"");\n                    ";____BAH_COMPILER_VAR_758[4] = allocLengthStr;____BAH_COMPILER_VAR_758[3] = "\04\0\0\0"") * ";____BAH_COMPILER_VAR_758[2] = elemTypeStr;____BAH_COMPILER_VAR_758[1] = "\034\0\0\0""->data = memoryAlloc(sizeof(";____BAH_COMPILER_VAR_758[0] = v->name;char * ____BAH_COMPILER_VAR_759 =__Bah_multiple_concat(____BAH_COMPILER_VAR_758, 11);NEXT_LINE = ____BAH_COMPILER_VAR_759;

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
char** ____BAH_COMPILER_VAR_760 = alloca(10 * sizeof(char*));____BAH_COMPILER_VAR_760[9] = NEXT_LINE;____BAH_COMPILER_VAR_760[8] = "\03\0\0\0"");\n";____BAH_COMPILER_VAR_760[7] = elemTypeStr;____BAH_COMPILER_VAR_760[6] = "\024\0\0\0""->elemSize = sizeof(";____BAH_COMPILER_VAR_760[5] = v->name;____BAH_COMPILER_VAR_760[4] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_760[3] = strArrayLength;____BAH_COMPILER_VAR_760[2] = "\013\0\0\0""->length = ";____BAH_COMPILER_VAR_760[1] = v->name;____BAH_COMPILER_VAR_760[0] = "\01\0\0\0""\n";char * ____BAH_COMPILER_VAR_761 =__Bah_multiple_concat(____BAH_COMPILER_VAR_760, 10);NEXT_LINE = ____BAH_COMPILER_VAR_761;

#line 1075 "/home/alois/Documents/bah-bah/src/parser.bah"
return code;
};

#line 1078 "/home/alois/Documents/bah-bah/src/parser.bah"
array(char *)* equalsTokens;

#line 1080 "/home/alois/Documents/bah-bah/src/parser.bah"
char ____BAH_COMPILER_VAR_768(array(char *)* arr, char * el) {
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
char** ____BAH_COMPILER_VAR_762 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_762[1] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_762[0] = ft.cont;char * ____BAH_COMPILER_VAR_763 =__Bah_multiple_concat(____BAH_COMPILER_VAR_762, 2);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_763));

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
struct variable* ____BAH_COMPILER_VAR_764 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_764->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_764->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_764->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_764->from = "\0\0\0\0""";
v = ____BAH_COMPILER_VAR_764;

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
char * ____BAH_COMPILER_VAR_765 =string__str(&c);v = searchVar(____BAH_COMPILER_VAR_765,elems);

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
char** ____BAH_COMPILER_VAR_766 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_766[1] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_766[0] = t.cont;char * ____BAH_COMPILER_VAR_767 =__Bah_multiple_concat(____BAH_COMPILER_VAR_766, 2);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_767));

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
if (____BAH_COMPILER_VAR_768(equalsTokens, operT.cont)&&(strcmp(operT.cont, "\01\0\0\0""=") != 0)) {

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
char** ____BAH_COMPILER_VAR_769 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_769[2] = "\01\0\0\0"")";____BAH_COMPILER_VAR_769[1] = l->data[2].cont;____BAH_COMPILER_VAR_769[0] = "\01\0\0\0""(";char * ____BAH_COMPILER_VAR_770 =__Bah_multiple_concat(____BAH_COMPILER_VAR_769, 3);l->data[2].cont = ____BAH_COMPILER_VAR_770;
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

    unsigned int ____BAH_COMPILER_VAR_771 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_771);
    nl->data[____BAH_COMPILER_VAR_771] = operT;

#line 1167 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int j = 0;

#line 1167 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (j<len(tmpL)); 
#line 1167 "/home/alois/Documents/bah-bah/src/parser.bah"
++j) {

#line 1168 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_772 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_772);
    nl->data[____BAH_COMPILER_VAR_772] = tmpL->data[j];
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
char** ____BAH_COMPILER_VAR_773 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_773[1] = t.cont;____BAH_COMPILER_VAR_773[0] = currentType;char * ____BAH_COMPILER_VAR_774 =__Bah_multiple_concat(____BAH_COMPILER_VAR_773, 2);currentType = ____BAH_COMPILER_VAR_774;
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
char** ____BAH_COMPILER_VAR_775 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_775[1] = nt.cont;____BAH_COMPILER_VAR_775[0] = "\05\0\0\0""chan:";char * ____BAH_COMPILER_VAR_776 =__Bah_multiple_concat(____BAH_COMPILER_VAR_775, 2);v->type = ____BAH_COMPILER_VAR_776;

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
char** ____BAH_COMPILER_VAR_777 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_777[1] = nt.cont;____BAH_COMPILER_VAR_777[0] = "\04\0\0\0""map:";char * ____BAH_COMPILER_VAR_778 =__Bah_multiple_concat(____BAH_COMPILER_VAR_777, 2);v->type = ____BAH_COMPILER_VAR_778;

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
char** ____BAH_COMPILER_VAR_779 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_779[1] = nt.cont;____BAH_COMPILER_VAR_779[0] = "\07\0\0\0""buffer:";char * ____BAH_COMPILER_VAR_780 =__Bah_multiple_concat(____BAH_COMPILER_VAR_779, 2);v->type = ____BAH_COMPILER_VAR_780;

#line 1235 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* ____BAH_COMPILER_VAR_781 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_781->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_781->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_781->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_781->from = "\0\0\0\0""";
struct variable* av = ____BAH_COMPILER_VAR_781;

#line 1236 "/home/alois/Documents/bah-bah/src/parser.bah"
av->type = "\05\0\0\0""char*";

#line 1237 "/home/alois/Documents/bah-bah/src/parser.bah"
av->name = genCompilerVar();

#line 1238 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_782 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_782);
    elems->vars->data[____BAH_COMPILER_VAR_782] = av;

#line 1239 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string cType = getCType(av->type,elems);

#line 1240 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_783 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_783[4] = "\02\0\0\0""];";____BAH_COMPILER_VAR_783[3] = nt.cont;____BAH_COMPILER_VAR_783[2] = "\01\0\0\0""[";____BAH_COMPILER_VAR_783[1] = av->name;____BAH_COMPILER_VAR_783[0] = "\05\0\0\0""char ";char * ____BAH_COMPILER_VAR_784 =__Bah_multiple_concat(____BAH_COMPILER_VAR_783, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_784));

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

                struct string ____BAH_COMPILER_VAR_785 = string(compilerState.currentDir);
                if ((isUnsafe==false)&&(string__hasPrefix(&____BAH_COMPILER_VAR_785,BAH_DIR)==false)&&isRCPpointerType(tp)) {

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
char** ____BAH_COMPILER_VAR_786 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_786[4] = "\01\0\0\0"".";____BAH_COMPILER_VAR_786[3] = v->type;____BAH_COMPILER_VAR_786[2] = "\05\0\0\0"") as ";____BAH_COMPILER_VAR_786[1] = tp;____BAH_COMPILER_VAR_786[0] = "\024\0\0\0""Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_787 =__Bah_multiple_concat(____BAH_COMPILER_VAR_786, 5);throwErr(&t,____BAH_COMPILER_VAR_787);
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
char** ____BAH_COMPILER_VAR_788 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_788[4] = "\01\0\0\0"".";____BAH_COMPILER_VAR_788[3] = v->type;____BAH_COMPILER_VAR_788[2] = "\05\0\0\0"") as ";____BAH_COMPILER_VAR_788[1] = tp;____BAH_COMPILER_VAR_788[0] = "\024\0\0\0""Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_789 =__Bah_multiple_concat(____BAH_COMPILER_VAR_788, 5);throwErr(&t,____BAH_COMPILER_VAR_789);
}
}
}
}

#line 1322 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((RAIIenabled==true)&&(t.type==TOKEN_TYPE_VAR)&&isRCPtype(tp,elems)) {

#line 1323 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ____BAH_COMPILER_VAR_790 =removeCast(t.cont);struct variable* ov = searchVar(____BAH_COMPILER_VAR_790,elems);

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

    unsigned int ____BAH_COMPILER_VAR_791 = len(elems->deletedVars);
    __Bah_realocate_arr(elems->deletedVars, ____BAH_COMPILER_VAR_791);
    elems->deletedVars->data[____BAH_COMPILER_VAR_791] = elems->vars->data[k];

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
char** ____BAH_COMPILER_VAR_792 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_792[1] = t.cont;____BAH_COMPILER_VAR_792[0] = code;char * ____BAH_COMPILER_VAR_793 =__Bah_multiple_concat(____BAH_COMPILER_VAR_792, 2);code = ____BAH_COMPILER_VAR_793;

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
char** ____BAH_COMPILER_VAR_794 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_794[5] = "\05\0\0\0""), 0)";____BAH_COMPILER_VAR_794[4] = iv->name;____BAH_COMPILER_VAR_794[3] = "\011\0\0\0"", sizeof(";____BAH_COMPILER_VAR_794[2] = iv->name;____BAH_COMPILER_VAR_794[1] = "\021\0\0\0""; RCP_scanStack(&";____BAH_COMPILER_VAR_794[0] = code;char * ____BAH_COMPILER_VAR_795 =__Bah_multiple_concat(____BAH_COMPILER_VAR_794, 6);code = ____BAH_COMPILER_VAR_795;
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
char** ____BAH_COMPILER_VAR_796 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_796[4] = "\05\0\0\0""), 0)";____BAH_COMPILER_VAR_796[3] = iv->name;____BAH_COMPILER_VAR_796[2] = "\011\0\0\0"", sizeof(";____BAH_COMPILER_VAR_796[1] = string__str(&ivn);____BAH_COMPILER_VAR_796[0] = "\020\0\0\0""; RCP_scanStack(";char * ____BAH_COMPILER_VAR_797 =__Bah_multiple_concat(____BAH_COMPILER_VAR_796, 5);char** ____BAH_COMPILER_VAR_798 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_798[1] = ____BAH_COMPILER_VAR_797;____BAH_COMPILER_VAR_798[0] = code;char * ____BAH_COMPILER_VAR_799 =__Bah_multiple_concat(____BAH_COMPILER_VAR_798, 2);code = ____BAH_COMPILER_VAR_799;
}

#line 1352 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1353 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_800 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_800[3] = "\01\0\0\0"")";____BAH_COMPILER_VAR_800[2] = iv->name;____BAH_COMPILER_VAR_800[1] = "\013\0\0\0""; RCP_incr(";____BAH_COMPILER_VAR_800[0] = code;char * ____BAH_COMPILER_VAR_801 =__Bah_multiple_concat(____BAH_COMPILER_VAR_800, 4);code = ____BAH_COMPILER_VAR_801;
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
char** ____BAH_COMPILER_VAR_802 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_802[1] = t.cont;____BAH_COMPILER_VAR_802[0] = code;char * ____BAH_COMPILER_VAR_803 =__Bah_multiple_concat(____BAH_COMPILER_VAR_802, 2);code = ____BAH_COMPILER_VAR_803;
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

                struct string ____BAH_COMPILER_VAR_804 = string(v->name);
                if ((strcmp(v->name, "\04\0\0\0""this") == 0)||string__hasPrefix(&____BAH_COMPILER_VAR_804,"\06\0\0\0""this->")) {

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
char** ____BAH_COMPILER_VAR_805 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_805[2] = "\015\0\0\0""' to {TOKEN}.";____BAH_COMPILER_VAR_805[1] = ft.cont;____BAH_COMPILER_VAR_805[0] = "\060\0\0\0""Cannot change the type of already declared var '";char * ____BAH_COMPILER_VAR_806 =__Bah_multiple_concat(____BAH_COMPILER_VAR_805, 3);throwErr(&st,____BAH_COMPILER_VAR_806);
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
char** ____BAH_COMPILER_VAR_807 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_807[8] = "\01\0\0\0"")";____BAH_COMPILER_VAR_807[7] = code;____BAH_COMPILER_VAR_807[6] = "\016\0\0\0""*)RCP_incrIL(&";____BAH_COMPILER_VAR_807[5] = string__str(&cType);____BAH_COMPILER_VAR_807[4] = "\06\0\0\0"") = *(";____BAH_COMPILER_VAR_807[3] = v->name;____BAH_COMPILER_VAR_807[2] = "\016\0\0\0""*)RCP_decrIL(&";____BAH_COMPILER_VAR_807[1] = string__str(&cType);____BAH_COMPILER_VAR_807[0] = "\02\0\0\0""*(";char * ____BAH_COMPILER_VAR_808 =__Bah_multiple_concat(____BAH_COMPILER_VAR_807, 9);code = ____BAH_COMPILER_VAR_808;
}

#line 1416 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1417 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* ____BAH_COMPILER_VAR_809 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_809->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_809->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_809->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_809->from = "\0\0\0\0""";
struct variable* tmpV = ____BAH_COMPILER_VAR_809;

#line 1418 "/home/alois/Documents/bah-bah/src/parser.bah"
tmpV->name = genCompilerVar();

#line 1419 "/home/alois/Documents/bah-bah/src/parser.bah"
tmpV->type = v->type;

#line 1420 "/home/alois/Documents/bah-bah/src/parser.bah"
struct rope* dv = decrVar(tmpV,elems);

#line 1421 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_810 = alloca(13 * sizeof(char*));____BAH_COMPILER_VAR_810[12] = rope__toStr(dv);____BAH_COMPILER_VAR_810[11] = "\02\0\0\0"");";____BAH_COMPILER_VAR_810[10] = code;____BAH_COMPILER_VAR_810[9] = "\016\0\0\0""*)RCP_incrIL(&";____BAH_COMPILER_VAR_810[8] = string__str(&cType);____BAH_COMPILER_VAR_810[7] = "\05\0\0\0"" = *(";____BAH_COMPILER_VAR_810[6] = v->name;____BAH_COMPILER_VAR_810[5] = "\02\0\0\0""; ";____BAH_COMPILER_VAR_810[4] = v->name;____BAH_COMPILER_VAR_810[3] = "\03\0\0\0"" = ";____BAH_COMPILER_VAR_810[2] = tmpV->name;____BAH_COMPILER_VAR_810[1] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_810[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_811 =__Bah_multiple_concat(____BAH_COMPILER_VAR_810, 13);code = ____BAH_COMPILER_VAR_811;
}
}

#line 1423 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1424 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* ____BAH_COMPILER_VAR_812 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_812->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_812->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_812->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_812->from = "\0\0\0\0""";
struct variable* tmpV = ____BAH_COMPILER_VAR_812;

#line 1425 "/home/alois/Documents/bah-bah/src/parser.bah"
tmpV->name = genCompilerVar();

#line 1426 "/home/alois/Documents/bah-bah/src/parser.bah"
tmpV->type = v->type;

#line 1427 "/home/alois/Documents/bah-bah/src/parser.bah"
struct rope* dv = decrVar(tmpV,elems);

#line 1428 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_813 = alloca(11 * sizeof(char*));____BAH_COMPILER_VAR_813[10] = rope__toStr(dv);____BAH_COMPILER_VAR_813[9] = "\01\0\0\0"";";____BAH_COMPILER_VAR_813[8] = code;____BAH_COMPILER_VAR_813[7] = "\03\0\0\0"" = ";____BAH_COMPILER_VAR_813[6] = v->name;____BAH_COMPILER_VAR_813[5] = "\02\0\0\0""; ";____BAH_COMPILER_VAR_813[4] = v->name;____BAH_COMPILER_VAR_813[3] = "\03\0\0\0"" = ";____BAH_COMPILER_VAR_813[2] = tmpV->name;____BAH_COMPILER_VAR_813[1] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_813[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_814 =__Bah_multiple_concat(____BAH_COMPILER_VAR_813, 11);code = ____BAH_COMPILER_VAR_814;
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
char** ____BAH_COMPILER_VAR_815 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_815[4] = "\07\0\0\0""), 1); ";____BAH_COMPILER_VAR_815[3] = v->name;____BAH_COMPILER_VAR_815[2] = "\011\0\0\0"", sizeof(";____BAH_COMPILER_VAR_815[1] = v->name;____BAH_COMPILER_VAR_815[0] = "\017\0\0\0""RCP_scanStack(&";char * ____BAH_COMPILER_VAR_816 =__Bah_multiple_concat(____BAH_COMPILER_VAR_815, 5);preCode = ____BAH_COMPILER_VAR_816;
}

#line 1435 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1436 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string vn = string(v->name);

#line 1437 "/home/alois/Documents/bah-bah/src/parser.bah"
string__replace(&vn,"\01\0\0\0""*","\0\0\0\0""");

#line 1438 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_817 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_817[4] = "\07\0\0\0""), 1); ";____BAH_COMPILER_VAR_817[3] = v->name;____BAH_COMPILER_VAR_817[2] = "\011\0\0\0"", sizeof(";____BAH_COMPILER_VAR_817[1] = string__str(&vn);____BAH_COMPILER_VAR_817[0] = "\016\0\0\0""RCP_scanStack(";char * ____BAH_COMPILER_VAR_818 =__Bah_multiple_concat(____BAH_COMPILER_VAR_817, 5);preCode = ____BAH_COMPILER_VAR_818;
}

#line 1440 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_819 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_819[2] = code;____BAH_COMPILER_VAR_819[1] = "\03\0\0\0"" = ";____BAH_COMPILER_VAR_819[0] = v->name;char * ____BAH_COMPILER_VAR_820 =__Bah_multiple_concat(____BAH_COMPILER_VAR_819, 3);code = ____BAH_COMPILER_VAR_820;
}

#line 1441 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1442 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_821 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_821[2] = code;____BAH_COMPILER_VAR_821[1] = "\03\0\0\0"" = ";____BAH_COMPILER_VAR_821[0] = v->name;char * ____BAH_COMPILER_VAR_822 =__Bah_multiple_concat(____BAH_COMPILER_VAR_821, 3);code = ____BAH_COMPILER_VAR_822;
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
char** ____BAH_COMPILER_VAR_823 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_823[2] = code;____BAH_COMPILER_VAR_823[1] = "\03\0\0\0"" = ";____BAH_COMPILER_VAR_823[0] = v->name;char * ____BAH_COMPILER_VAR_824 =__Bah_multiple_concat(____BAH_COMPILER_VAR_823, 3);code = ____BAH_COMPILER_VAR_824;
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
char** ____BAH_COMPILER_VAR_825 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_825[1] = code;____BAH_COMPILER_VAR_825[0] = preCode;char * ____BAH_COMPILER_VAR_826 =__Bah_multiple_concat(____BAH_COMPILER_VAR_825, 2);code = ____BAH_COMPILER_VAR_826;
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
char** ____BAH_COMPILER_VAR_827 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_827[1] = string__str(&ct);____BAH_COMPILER_VAR_827[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_828 =__Bah_multiple_concat(____BAH_COMPILER_VAR_827, 2);tmpfnArgsCType = ____BAH_COMPILER_VAR_828;

#line 1481 "/home/alois/Documents/bah-bah/src/parser.bah"
j = j+1;

#line 1482 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((j<len(tmpfn->args))) {

#line 1483 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_829 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_829[1] = "\01\0\0\0"",";____BAH_COMPILER_VAR_829[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_830 =__Bah_multiple_concat(____BAH_COMPILER_VAR_829, 2);tmpfnArgsCType = ____BAH_COMPILER_VAR_830;
}
};

#line 1487 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_831 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_831[5] = "\01\0\0\0"")";____BAH_COMPILER_VAR_831[4] = tmpfnArgsCType;____BAH_COMPILER_VAR_831[3] = "\02\0\0\0"")(";____BAH_COMPILER_VAR_831[2] = v->name;____BAH_COMPILER_VAR_831[1] = "\03\0\0\0"" (*";____BAH_COMPILER_VAR_831[0] = string__str(&tmpfnRetCType);char * ____BAH_COMPILER_VAR_832 =__Bah_multiple_concat(____BAH_COMPILER_VAR_831, 6);vct = ____BAH_COMPILER_VAR_832;
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
char** ____BAH_COMPILER_VAR_833 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_833[5] = "\03\0\0\0"");\n";____BAH_COMPILER_VAR_833[4] = code;____BAH_COMPILER_VAR_833[3] = "\016\0\0\0""*)RCP_incrIL(&";____BAH_COMPILER_VAR_833[2] = string__str(&cType);____BAH_COMPILER_VAR_833[1] = "\05\0\0\0"" = *(";____BAH_COMPILER_VAR_833[0] = v->name;char * ____BAH_COMPILER_VAR_834 =__Bah_multiple_concat(____BAH_COMPILER_VAR_833, 6);INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_834));
}

#line 1498 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1499 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_835 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_835[5] = "\01\0\0\0"")";____BAH_COMPILER_VAR_835[4] = code;____BAH_COMPILER_VAR_835[3] = "\016\0\0\0""*)RCP_incrIL(&";____BAH_COMPILER_VAR_835[2] = string__str(&cType);____BAH_COMPILER_VAR_835[1] = "\05\0\0\0"" = *(";____BAH_COMPILER_VAR_835[0] = vct;char * ____BAH_COMPILER_VAR_836 =__Bah_multiple_concat(____BAH_COMPILER_VAR_835, 6);code = ____BAH_COMPILER_VAR_836;
}
}

#line 1501 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1502 "/home/alois/Documents/bah-bah/src/parser.bah"
if (isGlobal()) {

#line 1503 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_837 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_837[3] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_837[2] = code;____BAH_COMPILER_VAR_837[1] = "\03\0\0\0"" = ";____BAH_COMPILER_VAR_837[0] = v->name;char * ____BAH_COMPILER_VAR_838 =__Bah_multiple_concat(____BAH_COMPILER_VAR_837, 4);INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_838));
}

#line 1504 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1505 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_839 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_839[2] = code;____BAH_COMPILER_VAR_839[1] = "\03\0\0\0"" = ";____BAH_COMPILER_VAR_839[0] = vct;char * ____BAH_COMPILER_VAR_840 =__Bah_multiple_concat(____BAH_COMPILER_VAR_839, 3);code = ____BAH_COMPILER_VAR_840;
}
}
}

#line 1508 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1509 "/home/alois/Documents/bah-bah/src/parser.bah"
if (isRCPpointerType(v->type)&&(shouldOnlyDecl==false)) {

#line 1510 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_841 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_841[1] = "\06\0\0\0""= null";____BAH_COMPILER_VAR_841[0] = vct;char * ____BAH_COMPILER_VAR_842 =__Bah_multiple_concat(____BAH_COMPILER_VAR_841, 2);code = ____BAH_COMPILER_VAR_842;
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
char** ____BAH_COMPILER_VAR_843 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_843[1] = vct;____BAH_COMPILER_VAR_843[0] = "\07\0\0\0""extern ";char * ____BAH_COMPILER_VAR_844 =__Bah_multiple_concat(____BAH_COMPILER_VAR_843, 2);vct = ____BAH_COMPILER_VAR_844;
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

    unsigned int ____BAH_COMPILER_VAR_845 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_845);
    elems->vars->data[____BAH_COMPILER_VAR_845] = v;

#line 1528 "/home/alois/Documents/bah-bah/src/parser.bah"
if (fixMeEnabled()) {

#line 1529 "/home/alois/Documents/bah-bah/src/parser.bah"
fixMeRegisterVar(v,&ft);
}

#line 1533 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* ____BAH_COMPILER_VAR_846 = v;
char ** ____BAH_COMPILER_VAR_848 = (char **)((char*)(____BAH_COMPILER_VAR_846) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_849 = __reflect(____BAH_COMPILER_VAR_848, sizeof(char *), "\010\0\0\0""cpstring", "\04\0\0\0""name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_850 = (char **)((char*)(____BAH_COMPILER_VAR_846) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_851 = __reflect(____BAH_COMPILER_VAR_850, sizeof(char *), "\010\0\0\0""cpstring", "\04\0\0\0""type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_852 = (char*)((char*)(____BAH_COMPILER_VAR_846) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_853 = __reflect(____BAH_COMPILER_VAR_852, sizeof(char), "\04\0\0\0""bool", "\07\0\0\0""isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_854 = (char **)((char*)(____BAH_COMPILER_VAR_846) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_855 = __reflect(____BAH_COMPILER_VAR_854, sizeof(char *), "\010\0\0\0""cpstring", "\010\0\0\0""constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_856 = (char*)((char*)(____BAH_COMPILER_VAR_846) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_857 = __reflect(____BAH_COMPILER_VAR_856, sizeof(char), "\04\0\0\0""bool", "\07\0\0\0""isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_858 = (char **)((char*)(____BAH_COMPILER_VAR_846) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_859 = __reflect(____BAH_COMPILER_VAR_858, sizeof(char *), "\010\0\0\0""cpstring", "\04\0\0\0""from", 0, 0, 0, 0, offsetof(struct variable, from));
void ** ____BAH_COMPILER_VAR_860 = (void **)((char*)(____BAH_COMPILER_VAR_846) + offsetof(struct variable, declScope));
struct reflectElement ____BAH_COMPILER_VAR_861 = __reflect(____BAH_COMPILER_VAR_860, sizeof(void *), "\03\0\0\0""ptr", "\011\0\0\0""declScope", 0, 0, 0, 0, offsetof(struct variable, declScope));
char* ____BAH_COMPILER_VAR_862 = (char*)((char*)(____BAH_COMPILER_VAR_846) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_863 = __reflect(____BAH_COMPILER_VAR_862, sizeof(char), "\04\0\0\0""bool", "\010\0\0\0""isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));
struct rope** ____BAH_COMPILER_VAR_864 = (struct rope**)((char*)(____BAH_COMPILER_VAR_846) + offsetof(struct variable, declRope));
void ** ____BAH_COMPILER_VAR_866 = (void **)((char*)(____BAH_COMPILER_VAR_864) + offsetof(struct rope, left));
struct reflectElement ____BAH_COMPILER_VAR_867 = __reflect(____BAH_COMPILER_VAR_866, sizeof(void *), "\03\0\0\0""ptr", "\04\0\0\0""left", 0, 0, 0, 0, offsetof(struct rope, left));
void ** ____BAH_COMPILER_VAR_868 = (void **)((char*)(____BAH_COMPILER_VAR_864) + offsetof(struct rope, right));
struct reflectElement ____BAH_COMPILER_VAR_869 = __reflect(____BAH_COMPILER_VAR_868, sizeof(void *), "\03\0\0\0""ptr", "\05\0\0\0""right", 0, 0, 0, 0, offsetof(struct rope, right));
char ** ____BAH_COMPILER_VAR_870 = (char **)((char*)(____BAH_COMPILER_VAR_864) + offsetof(struct rope, str));
struct reflectElement ____BAH_COMPILER_VAR_871 = __reflect(____BAH_COMPILER_VAR_870, sizeof(char *), "\010\0\0\0""cpstring", "\03\0\0\0""str", 0, 0, 0, 0, offsetof(struct rope, str));
int* ____BAH_COMPILER_VAR_872 = (int*)((char*)(____BAH_COMPILER_VAR_864) + offsetof(struct rope, lCount));
struct reflectElement ____BAH_COMPILER_VAR_873 = __reflect(____BAH_COMPILER_VAR_872, sizeof(int), "\05\0\0\0""int32", "\06\0\0\0""lCount", 0, 0, 0, 0, offsetof(struct rope, lCount));
int* ____BAH_COMPILER_VAR_874 = (int*)((char*)(____BAH_COMPILER_VAR_864) + offsetof(struct rope, len));
struct reflectElement ____BAH_COMPILER_VAR_875 = __reflect(____BAH_COMPILER_VAR_874, sizeof(int), "\05\0\0\0""int32", "\03\0\0\0""len", 0, 0, 0, 0, offsetof(struct rope, len));
int* ____BAH_COMPILER_VAR_876 = (int*)((char*)(____BAH_COMPILER_VAR_864) + offsetof(struct rope, totalLen));
struct reflectElement ____BAH_COMPILER_VAR_877 = __reflect(____BAH_COMPILER_VAR_876, sizeof(int), "\05\0\0\0""int32", "\010\0\0\0""totalLen", 0, 0, 0, 0, offsetof(struct rope, totalLen));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_865 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_865->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_865->length = 6;
        ____BAH_COMPILER_VAR_865->data = memoryAlloc(____BAH_COMPILER_VAR_865->length * ____BAH_COMPILER_VAR_865->elemSize);
        ____BAH_COMPILER_VAR_865->data[0] = ____BAH_COMPILER_VAR_867;
____BAH_COMPILER_VAR_865->data[1] = ____BAH_COMPILER_VAR_869;
____BAH_COMPILER_VAR_865->data[2] = ____BAH_COMPILER_VAR_871;
____BAH_COMPILER_VAR_865->data[3] = ____BAH_COMPILER_VAR_873;
____BAH_COMPILER_VAR_865->data[4] = ____BAH_COMPILER_VAR_875;
____BAH_COMPILER_VAR_865->data[5] = ____BAH_COMPILER_VAR_877;
struct reflectElement ____BAH_COMPILER_VAR_878 = __reflect(____BAH_COMPILER_VAR_864, sizeof(struct rope), "\05\0\0\0""rope*", "\010\0\0\0""declRope", 0, 0, 1, ____BAH_COMPILER_VAR_865, offsetof(struct variable, declRope));
char* ____BAH_COMPILER_VAR_879 = (char*)((char*)(____BAH_COMPILER_VAR_846) + offsetof(struct variable, canBeNull));
struct reflectElement ____BAH_COMPILER_VAR_880 = __reflect(____BAH_COMPILER_VAR_879, sizeof(char), "\04\0\0\0""bool", "\011\0\0\0""canBeNull", 0, 0, 0, 0, offsetof(struct variable, canBeNull));
void ** ____BAH_COMPILER_VAR_881 = (void **)((char*)(____BAH_COMPILER_VAR_846) + offsetof(struct variable, iterScope));
struct reflectElement ____BAH_COMPILER_VAR_882 = __reflect(____BAH_COMPILER_VAR_881, sizeof(void *), "\03\0\0\0""ptr", "\011\0\0\0""iterScope", 0, 0, 0, 0, offsetof(struct variable, iterScope));
char* ____BAH_COMPILER_VAR_883 = (char*)((char*)(____BAH_COMPILER_VAR_846) + offsetof(struct variable, canBeReg));
struct reflectElement ____BAH_COMPILER_VAR_884 = __reflect(____BAH_COMPILER_VAR_883, sizeof(char), "\04\0\0\0""bool", "\010\0\0\0""canBeReg", 0, 0, 0, 0, offsetof(struct variable, canBeReg));
char* ____BAH_COMPILER_VAR_885 = (char*)((char*)(____BAH_COMPILER_VAR_846) + offsetof(struct variable, isReg));
struct reflectElement ____BAH_COMPILER_VAR_886 = __reflect(____BAH_COMPILER_VAR_885, sizeof(char), "\04\0\0\0""bool", "\05\0\0\0""isReg", 0, 0, 0, 0, offsetof(struct variable, isReg));
void ** ____BAH_COMPILER_VAR_887 = (void **)((char*)(____BAH_COMPILER_VAR_846) + offsetof(struct variable, lastSet));
struct reflectElement ____BAH_COMPILER_VAR_888 = __reflect(____BAH_COMPILER_VAR_887, sizeof(void *), "\03\0\0\0""ptr", "\07\0\0\0""lastSet", 0, 0, 0, 0, offsetof(struct variable, lastSet));
char* ____BAH_COMPILER_VAR_889 = (char*)((char*)(____BAH_COMPILER_VAR_846) + offsetof(struct variable, isArg));
struct reflectElement ____BAH_COMPILER_VAR_890 = __reflect(____BAH_COMPILER_VAR_889, sizeof(char), "\04\0\0\0""bool", "\05\0\0\0""isArg", 0, 0, 0, 0, offsetof(struct variable, isArg));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_847 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_847->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_847->length = 15;
        ____BAH_COMPILER_VAR_847->data = memoryAlloc(____BAH_COMPILER_VAR_847->length * ____BAH_COMPILER_VAR_847->elemSize);
        ____BAH_COMPILER_VAR_847->data[0] = ____BAH_COMPILER_VAR_849;
____BAH_COMPILER_VAR_847->data[1] = ____BAH_COMPILER_VAR_851;
____BAH_COMPILER_VAR_847->data[2] = ____BAH_COMPILER_VAR_853;
____BAH_COMPILER_VAR_847->data[3] = ____BAH_COMPILER_VAR_855;
____BAH_COMPILER_VAR_847->data[4] = ____BAH_COMPILER_VAR_857;
____BAH_COMPILER_VAR_847->data[5] = ____BAH_COMPILER_VAR_859;
____BAH_COMPILER_VAR_847->data[6] = ____BAH_COMPILER_VAR_861;
____BAH_COMPILER_VAR_847->data[7] = ____BAH_COMPILER_VAR_863;
____BAH_COMPILER_VAR_847->data[8] = ____BAH_COMPILER_VAR_878;
____BAH_COMPILER_VAR_847->data[9] = ____BAH_COMPILER_VAR_880;
____BAH_COMPILER_VAR_847->data[10] = ____BAH_COMPILER_VAR_882;
____BAH_COMPILER_VAR_847->data[11] = ____BAH_COMPILER_VAR_884;
____BAH_COMPILER_VAR_847->data[12] = ____BAH_COMPILER_VAR_886;
____BAH_COMPILER_VAR_847->data[13] = ____BAH_COMPILER_VAR_888;
____BAH_COMPILER_VAR_847->data[14] = ____BAH_COMPILER_VAR_890;
struct reflectElement ____BAH_COMPILER_VAR_891 = __reflect(____BAH_COMPILER_VAR_846, sizeof(struct variable), "\011\0\0\0""variable*", "\01\0\0\0""v", 0, 0, 1, ____BAH_COMPILER_VAR_847, 0);
debugPrint("\017\0\0\0""var_declaration",ft.line,____BAH_COMPILER_VAR_891);

#line 1536 "/home/alois/Documents/bah-bah/src/parser.bah"
if (isGlobal()) {

#line 1537 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_892 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_892[1] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_892[0] = vct;char * ____BAH_COMPILER_VAR_893 =__Bah_multiple_concat(____BAH_COMPILER_VAR_892, 2);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_893));
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
char** ____BAH_COMPILER_VAR_894 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_894[1] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_894[0] = code;char * ____BAH_COMPILER_VAR_895 =__Bah_multiple_concat(____BAH_COMPILER_VAR_894, 2);struct rope* declR = rope(____BAH_COMPILER_VAR_895);

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
char** ____BAH_COMPILER_VAR_896 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_896[1] = string__str(&ct);____BAH_COMPILER_VAR_896[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_897 =__Bah_multiple_concat(____BAH_COMPILER_VAR_896, 2);tmpfnArgsCType = ____BAH_COMPILER_VAR_897;

#line 1570 "/home/alois/Documents/bah-bah/src/parser.bah"
j = j+1;

#line 1571 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((j<len(tmpfn->args))) {

#line 1572 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_898 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_898[1] = "\01\0\0\0"",";____BAH_COMPILER_VAR_898[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_899 =__Bah_multiple_concat(____BAH_COMPILER_VAR_898, 2);tmpfnArgsCType = ____BAH_COMPILER_VAR_899;
}
};

#line 1576 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_900 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_900[5] = "\01\0\0\0"")";____BAH_COMPILER_VAR_900[4] = tmpfnArgsCType;____BAH_COMPILER_VAR_900[3] = "\02\0\0\0"")(";____BAH_COMPILER_VAR_900[2] = elemName;____BAH_COMPILER_VAR_900[1] = "\03\0\0\0"" (*";____BAH_COMPILER_VAR_900[0] = string__str(&tmpfnRetCType);char * ____BAH_COMPILER_VAR_901 =__Bah_multiple_concat(____BAH_COMPILER_VAR_900, 6);return ____BAH_COMPILER_VAR_901;
};

#line 1580 "/home/alois/Documents/bah-bah/src/parser.bah"
char ____BAH_COMPILER_VAR_912(array(char *)* arr, char * el) {
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
char ____BAH_COMPILER_VAR_931(array(char *)* arr, char * el) {
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
char** ____BAH_COMPILER_VAR_902 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_902[1] = ft.cont;____BAH_COMPILER_VAR_902[0] = prev;char * ____BAH_COMPILER_VAR_903 =__Bah_multiple_concat(____BAH_COMPILER_VAR_902, 2);fn->name = ____BAH_COMPILER_VAR_903;

#line 1590 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct variable*)* arguments = memoryAlloc(sizeof(array(struct variable*)));

arguments->length = 0;
arguments->elemSize = sizeof(struct variable*);

#line 1592 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_904 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_904[1] = "\01\0\0\0""(";____BAH_COMPILER_VAR_904[0] = fn->name;char * ____BAH_COMPILER_VAR_905 =__Bah_multiple_concat(____BAH_COMPILER_VAR_904, 2);char * code = ____BAH_COMPILER_VAR_905;

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
char** ____BAH_COMPILER_VAR_906 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_906[1] = t.cont;____BAH_COMPILER_VAR_906[0] = argType;char * ____BAH_COMPILER_VAR_907 =__Bah_multiple_concat(____BAH_COMPILER_VAR_906, 2);argType = ____BAH_COMPILER_VAR_907;
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
struct variable* ____BAH_COMPILER_VAR_908 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_908->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_908->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_908->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_908->from = "\0\0\0\0""";
struct variable* argument = ____BAH_COMPILER_VAR_908;

#line 1639 "/home/alois/Documents/bah-bah/src/parser.bah"
argument->name = argName;

#line 1640 "/home/alois/Documents/bah-bah/src/parser.bah"
argument->type = argType;

#line 1641 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_909 = len(arguments);
    __Bah_realocate_arr(arguments, ____BAH_COMPILER_VAR_909);
    arguments->data[____BAH_COMPILER_VAR_909] = argument;

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
char** ____BAH_COMPILER_VAR_910 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_910[1] = string__str(&cfrt);____BAH_COMPILER_VAR_910[0] = "\017\0\0\0""__BAH_ARR_TYPE_";char * ____BAH_COMPILER_VAR_911 =__Bah_multiple_concat(____BAH_COMPILER_VAR_910, 2);newArgType = ____BAH_COMPILER_VAR_911;

#line 1656 "/home/alois/Documents/bah-bah/src/parser.bah"
array(char *)* csatd = compilerState.arrTypesDecl;

#line 1657 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((____BAH_COMPILER_VAR_912(csatd, newArgType)==false)) {

#line 1658 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_913 = len(csatd);
    __Bah_realocate_arr(csatd, ____BAH_COMPILER_VAR_913);
    csatd->data[____BAH_COMPILER_VAR_913] = newArgType;

#line 1659 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_914 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_914[5] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_914[4] = newArgType;____BAH_COMPILER_VAR_914[3] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_914[2] = string__str(&argCType);____BAH_COMPILER_VAR_914[1] = "\010\0\0\0""typedef ";____BAH_COMPILER_VAR_914[0] = tpdf;char * ____BAH_COMPILER_VAR_915 =__Bah_multiple_concat(____BAH_COMPILER_VAR_914, 6);tpdf = ____BAH_COMPILER_VAR_915;
}
}

#line 1662 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((string__hasPrefix(&cfrt,"\011\0\0\0""function(")==1)) {

#line 1663 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_916 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_916[1] = getCfunctionType(&cfrt,argName,elems);____BAH_COMPILER_VAR_916[0] = code;char * ____BAH_COMPILER_VAR_917 =__Bah_multiple_concat(____BAH_COMPILER_VAR_916, 2);code = ____BAH_COMPILER_VAR_917;
}

#line 1664 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1665 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_918 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_918[3] = argName;____BAH_COMPILER_VAR_918[2] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_918[1] = newArgType;____BAH_COMPILER_VAR_918[0] = code;char * ____BAH_COMPILER_VAR_919 =__Bah_multiple_concat(____BAH_COMPILER_VAR_918, 4);code = ____BAH_COMPILER_VAR_919;
}

#line 1667 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((isComa==true)) {

#line 1668 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_920 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_920[1] = "\01\0\0\0"",";____BAH_COMPILER_VAR_920[0] = code;char * ____BAH_COMPILER_VAR_921 =__Bah_multiple_concat(____BAH_COMPILER_VAR_920, 2);code = ____BAH_COMPILER_VAR_921;
}

#line 1669 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 1670 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_922 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_922[1] = "\01\0\0\0"")";____BAH_COMPILER_VAR_922[0] = code;char * ____BAH_COMPILER_VAR_923 =__Bah_multiple_concat(____BAH_COMPILER_VAR_922, 2);code = ____BAH_COMPILER_VAR_923;

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
char** ____BAH_COMPILER_VAR_924 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_924[1] = "\01\0\0\0"")";____BAH_COMPILER_VAR_924[0] = code;char * ____BAH_COMPILER_VAR_925 =__Bah_multiple_concat(____BAH_COMPILER_VAR_924, 2);code = ____BAH_COMPILER_VAR_925;
}

#line 1679 "/home/alois/Documents/bah-bah/src/parser.bah"
j = j+1;

#line 1681 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* ____BAH_COMPILER_VAR_926 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_926->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_926->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_926->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_926->from = "\0\0\0\0""";
struct variable* returns = ____BAH_COMPILER_VAR_926;

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
char** ____BAH_COMPILER_VAR_927 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_927[1] = t.cont;____BAH_COMPILER_VAR_927[0] = returns->type;char * ____BAH_COMPILER_VAR_928 =__Bah_multiple_concat(____BAH_COMPILER_VAR_927, 2);returns->type = ____BAH_COMPILER_VAR_928;

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
char** ____BAH_COMPILER_VAR_929 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_929[1] = string__str(&cfrt);____BAH_COMPILER_VAR_929[0] = "\017\0\0\0""__BAH_ARR_TYPE_";char * ____BAH_COMPILER_VAR_930 =__Bah_multiple_concat(____BAH_COMPILER_VAR_929, 2);newFnRetType = ____BAH_COMPILER_VAR_930;

#line 1713 "/home/alois/Documents/bah-bah/src/parser.bah"
array(char *)* csatd = compilerState.arrTypesDecl;

#line 1714 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((____BAH_COMPILER_VAR_931(csatd, newFnRetType)==false)) {

#line 1715 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_932 = len(csatd);
    __Bah_realocate_arr(csatd, ____BAH_COMPILER_VAR_932);
    csatd->data[____BAH_COMPILER_VAR_932] = newFnRetType;

#line 1716 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_933 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_933[5] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_933[4] = newFnRetType;____BAH_COMPILER_VAR_933[3] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_933[2] = string__str(&fnRetType);____BAH_COMPILER_VAR_933[1] = "\010\0\0\0""typedef ";____BAH_COMPILER_VAR_933[0] = tpdf;char * ____BAH_COMPILER_VAR_934 =__Bah_multiple_concat(____BAH_COMPILER_VAR_933, 6);tpdf = ____BAH_COMPILER_VAR_934;
}
}

#line 1719 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_935 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_935[3] = code;____BAH_COMPILER_VAR_935[2] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_935[1] = newFnRetType;____BAH_COMPILER_VAR_935[0] = tpdf;char * ____BAH_COMPILER_VAR_936 =__Bah_multiple_concat(____BAH_COMPILER_VAR_935, 4);code = ____BAH_COMPILER_VAR_936;

#line 1723 "/home/alois/Documents/bah-bah/src/parser.bah"
return code;
};

#line 1726 "/home/alois/Documents/bah-bah/src/parser.bah"
void parseStruct(__BAH_ARR_TYPE_Tok l,struct Elems* elems){

#line 1728 "/home/alois/Documents/bah-bah/src/parser.bah"
struct cStruct* ____BAH_COMPILER_VAR_937 = memoryAlloc(sizeof(struct cStruct));
____BAH_COMPILER_VAR_937->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_937->members = memoryAlloc(sizeof(array(struct structMemb*)));
            ____BAH_COMPILER_VAR_937->members->length = 0;
            ____BAH_COMPILER_VAR_937->members->elemSize = sizeof(struct structMemb*);
            ____BAH_COMPILER_VAR_937->methods = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_937->methods->length = 0;
            ____BAH_COMPILER_VAR_937->methods->elemSize = sizeof(struct func*);
            ____BAH_COMPILER_VAR_937->postCode = "\0\0\0\0""";
____BAH_COMPILER_VAR_937->extendedFrom = "\0\0\0\0""";
struct cStruct* s = ____BAH_COMPILER_VAR_937;

#line 1729 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct cStruct*)* structs = elems->structs;

#line 1730 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_938 = len(structs);
    __Bah_realocate_arr(structs, ____BAH_COMPILER_VAR_938);
    structs->data[____BAH_COMPILER_VAR_938] = s;

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
char** ____BAH_COMPILER_VAR_939 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_939[1] = string__str(&ct);____BAH_COMPILER_VAR_939[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_940 =__Bah_multiple_concat(____BAH_COMPILER_VAR_939, 2);tmpfnArgsCType = ____BAH_COMPILER_VAR_940;

#line 1782 "/home/alois/Documents/bah-bah/src/parser.bah"
j = j+1;

#line 1783 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((j<len(tmpfn->args))) {

#line 1784 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_941 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_941[1] = "\01\0\0\0"",";____BAH_COMPILER_VAR_941[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_942 =__Bah_multiple_concat(____BAH_COMPILER_VAR_941, 2);tmpfnArgsCType = ____BAH_COMPILER_VAR_942;
}
};

#line 1787 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_943 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_943[5] = "\01\0\0\0"")";____BAH_COMPILER_VAR_943[4] = tmpfnArgsCType;____BAH_COMPILER_VAR_943[3] = "\02\0\0\0"")(";____BAH_COMPILER_VAR_943[2] = em->name;____BAH_COMPILER_VAR_943[1] = "\03\0\0\0"" (*";____BAH_COMPILER_VAR_943[0] = string__str(&tmpfnRetCType);char * ____BAH_COMPILER_VAR_944 =__Bah_multiple_concat(____BAH_COMPILER_VAR_943, 6);membDeclStr = ____BAH_COMPILER_VAR_944;
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

    unsigned int ____BAH_COMPILER_VAR_945 = len(allMembs);
    __Bah_realocate_arr(allMembs, ____BAH_COMPILER_VAR_945);
    allMembs->data[____BAH_COMPILER_VAR_945] = membDeclStr;

#line 1798 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_946 = len(members);
    __Bah_realocate_arr(members, ____BAH_COMPILER_VAR_946);
    members->data[____BAH_COMPILER_VAR_946] = em;

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
struct structMemb* ____BAH_COMPILER_VAR_947 = memoryAlloc(sizeof(struct structMemb));
____BAH_COMPILER_VAR_947->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_947->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_947->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_947->from = "\0\0\0\0""";
____BAH_COMPILER_VAR_947->def = "\0\0\0\0""";
struct structMemb* memb = ____BAH_COMPILER_VAR_947;

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
char** ____BAH_COMPILER_VAR_948 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_948[1] = "\02\0\0\0""__";____BAH_COMPILER_VAR_948[0] = s->name;char * ____BAH_COMPILER_VAR_949 =__Bah_multiple_concat(____BAH_COMPILER_VAR_948, 2);char * fnPrefix = ____BAH_COMPILER_VAR_949;

#line 1848 "/home/alois/Documents/bah-bah/src/parser.bah"
struct func* ____BAH_COMPILER_VAR_950 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_950->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_950->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_950->args->length = 0;
            ____BAH_COMPILER_VAR_950->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_950->from = "\0\0\0\0""";
____BAH_COMPILER_VAR_950->file = "\0\0\0\0""";
____BAH_COMPILER_VAR_950->line = 1;
struct func* fn = ____BAH_COMPILER_VAR_950;

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

    unsigned int ____BAH_COMPILER_VAR_951 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_951);
    nl->data[____BAH_COMPILER_VAR_951] = t;

#line 1856 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((j==i)) {

#line 1857 "/home/alois/Documents/bah-bah/src/parser.bah"
t.type = TOKEN_TYPE_VAR;

#line 1858 "/home/alois/Documents/bah-bah/src/parser.bah"
t.cont = "\04\0\0\0""this";

#line 1859 "/home/alois/Documents/bah-bah/src/parser.bah"
t.isValue = true;

#line 1860 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_952 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_952);
    nl->data[____BAH_COMPILER_VAR_952] = t;

#line 1862 "/home/alois/Documents/bah-bah/src/parser.bah"
t.type = TOKEN_TYPE_VAR;

#line 1863 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_953 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_953[1] = "\01\0\0\0""*";____BAH_COMPILER_VAR_953[0] = s->name;char * ____BAH_COMPILER_VAR_954 =__Bah_multiple_concat(____BAH_COMPILER_VAR_953, 2);t.cont = ____BAH_COMPILER_VAR_954;

#line 1864 "/home/alois/Documents/bah-bah/src/parser.bah"
t.isValue = true;

#line 1865 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_955 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_955);
    nl->data[____BAH_COMPILER_VAR_955] = t;

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

    unsigned int ____BAH_COMPILER_VAR_956 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_956);
    nl->data[____BAH_COMPILER_VAR_956] = t;
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
char * ____BAH_COMPILER_VAR_957 =parseFnHeader(fnPrefix,nl,&nli,fn,elems);struct rope* code = rope(____BAH_COMPILER_VAR_957);

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

    unsigned int ____BAH_COMPILER_VAR_958 = len(fnElems->vars);
    __Bah_realocate_arr(fnElems->vars, ____BAH_COMPILER_VAR_958);
    fnElems->vars->data[____BAH_COMPILER_VAR_958] = a;
};

#line 1902 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct func*)* fns = elems->fns;

#line 1903 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_959 = len(fns);
    __Bah_realocate_arr(fns, ____BAH_COMPILER_VAR_959);
    fns->data[____BAH_COMPILER_VAR_959] = fn;

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

    unsigned int ____BAH_COMPILER_VAR_960 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_960);
    tokens->data[____BAH_COMPILER_VAR_960] = t;

#line 1922 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;
};

#line 1926 "/home/alois/Documents/bah-bah/src/parser.bah"
struct func* ____BAH_COMPILER_VAR_961 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_961->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_961->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_961->args->length = 0;
            ____BAH_COMPILER_VAR_961->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_961->from = "\0\0\0\0""";
____BAH_COMPILER_VAR_961->file = "\0\0\0\0""";
____BAH_COMPILER_VAR_961->line = 1;
struct func* mfn = ____BAH_COMPILER_VAR_961;

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

    unsigned int ____BAH_COMPILER_VAR_962 = len(methds);
    __Bah_realocate_arr(methds, ____BAH_COMPILER_VAR_962);
    methds->data[____BAH_COMPILER_VAR_962] = mfn;

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
char** ____BAH_COMPILER_VAR_963 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_963[2] = "\022\0\0\0""' is not returned.";____BAH_COMPILER_VAR_963[1] = fn->name;____BAH_COMPILER_VAR_963[0] = "\012\0\0\0""Function '";char * ____BAH_COMPILER_VAR_964 =__Bah_multiple_concat(____BAH_COMPILER_VAR_963, 3);throwErr(&l->data[len(l)-1],____BAH_COMPILER_VAR_964);
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
char** ____BAH_COMPILER_VAR_965 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_965[1] = rope__toStr(code);____BAH_COMPILER_VAR_965[0] = nextLine;char * ____BAH_COMPILER_VAR_966 =__Bah_multiple_concat(____BAH_COMPILER_VAR_965, 2);nextLine = ____BAH_COMPILER_VAR_966;
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
char** ____BAH_COMPILER_VAR_967 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_967[1] = t.cont;____BAH_COMPILER_VAR_967[0] = mbmType;char * ____BAH_COMPILER_VAR_968 =__Bah_multiple_concat(____BAH_COMPILER_VAR_967, 2);mbmType = ____BAH_COMPILER_VAR_968;

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
char** ____BAH_COMPILER_VAR_969 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_969[4] = "\014\0\0\0"" for member.";____BAH_COMPILER_VAR_969[3] = memb->type;____BAH_COMPILER_VAR_969[2] = "\05\0\0\0"") as ";____BAH_COMPILER_VAR_969[1] = tt;____BAH_COMPILER_VAR_969[0] = "\024\0\0\0""Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_970 =__Bah_multiple_concat(____BAH_COMPILER_VAR_969, 5);throwErr(&t,____BAH_COMPILER_VAR_970);
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

    unsigned int ____BAH_COMPILER_VAR_971 = len(members);
    __Bah_realocate_arr(members, ____BAH_COMPILER_VAR_971);
    members->data[____BAH_COMPILER_VAR_971] = memb;

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
char** ____BAH_COMPILER_VAR_972 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_972[1] = string__str(&ct);____BAH_COMPILER_VAR_972[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_973 =__Bah_multiple_concat(____BAH_COMPILER_VAR_972, 2);tmpfnArgsCType = ____BAH_COMPILER_VAR_973;

#line 2042 "/home/alois/Documents/bah-bah/src/parser.bah"
j = j+1;

#line 2043 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((j<len(tmpfn->args))) {

#line 2044 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_974 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_974[1] = "\01\0\0\0"",";____BAH_COMPILER_VAR_974[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_975 =__Bah_multiple_concat(____BAH_COMPILER_VAR_974, 2);tmpfnArgsCType = ____BAH_COMPILER_VAR_975;
}
};

#line 2047 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_976 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_976[5] = "\01\0\0\0"")";____BAH_COMPILER_VAR_976[4] = tmpfnArgsCType;____BAH_COMPILER_VAR_976[3] = "\02\0\0\0"")(";____BAH_COMPILER_VAR_976[2] = memb->name;____BAH_COMPILER_VAR_976[1] = "\03\0\0\0"" (*";____BAH_COMPILER_VAR_976[0] = string__str(&tmpfnRetCType);char * ____BAH_COMPILER_VAR_977 =__Bah_multiple_concat(____BAH_COMPILER_VAR_976, 6);membDeclStr = ____BAH_COMPILER_VAR_977;
}

#line 2048 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 2049 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string membDecl = getCType(memb->type,elems);

#line 2050 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_978 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_978[1] = memb->name;____BAH_COMPILER_VAR_978[0] = "\01\0\0\0"" ";char * ____BAH_COMPILER_VAR_979 =__Bah_multiple_concat(____BAH_COMPILER_VAR_978, 2);string__append(&membDecl,____BAH_COMPILER_VAR_979);

#line 2051 "/home/alois/Documents/bah-bah/src/parser.bah"
membDeclStr = string__str(&membDecl);
}

#line 2053 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_980 = len(allMembs);
    __Bah_realocate_arr(allMembs, ____BAH_COMPILER_VAR_980);
    allMembs->data[____BAH_COMPILER_VAR_980] = membDeclStr;

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
char** ____BAH_COMPILER_VAR_981 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_981[2] = "\03\0\0\0"" {\n";____BAH_COMPILER_VAR_981[1] = s->name;____BAH_COMPILER_VAR_981[0] = "\07\0\0\0""struct ";char * ____BAH_COMPILER_VAR_982 =__Bah_multiple_concat(____BAH_COMPILER_VAR_981, 3);struct rope* code = rope(____BAH_COMPILER_VAR_982);

#line 2061 "/home/alois/Documents/bah-bah/src/parser.bah"
i = 0;

#line 2061 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i<len(allMembs))) {

#line 2062 "/home/alois/Documents/bah-bah/src/parser.bah"
char * m = allMembs->data[i];

#line 2063 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_983 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_983[1] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_983[0] = m;char * ____BAH_COMPILER_VAR_984 =__Bah_multiple_concat(____BAH_COMPILER_VAR_983, 2);code = rope__add(code, rope(____BAH_COMPILER_VAR_984));

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
OUTPUT->totalLen = OUTPUT->totalLen+ropeSet(postDeclHandle,"\0\0\0\0""");

#line 2070 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_985 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_985[1] = phd;____BAH_COMPILER_VAR_985[0] = NEXT_LINE;char * ____BAH_COMPILER_VAR_986 =__Bah_multiple_concat(____BAH_COMPILER_VAR_985, 2);NEXT_LINE = ____BAH_COMPILER_VAR_986;
}

#line 2073 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((debug==true)) {

#line 2075 "/home/alois/Documents/bah-bah/src/parser.bah"
struct debugStruct* ____BAH_COMPILER_VAR_987 = memoryAlloc(sizeof(struct debugStruct));
____BAH_COMPILER_VAR_987->membs = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_987->membs->length = 0;
            ____BAH_COMPILER_VAR_987->membs->elemSize = sizeof(struct variable*);
            struct debugStruct* ds = ____BAH_COMPILER_VAR_987;

#line 2076 "/home/alois/Documents/bah-bah/src/parser.bah"
ds->name = s->name;

#line 2077 "/home/alois/Documents/bah-bah/src/parser.bah"
i = 0;

#line 2077 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i<len(s->members))) {

#line 2078 "/home/alois/Documents/bah-bah/src/parser.bah"
struct structMemb* m = s->members->data[i];

#line 2079 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* ____BAH_COMPILER_VAR_988 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_988->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_988->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_988->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_988->from = "\0\0\0\0""";
struct variable* mv = ____BAH_COMPILER_VAR_988;

#line 2080 "/home/alois/Documents/bah-bah/src/parser.bah"
mv->name = m->name;

#line 2081 "/home/alois/Documents/bah-bah/src/parser.bah"
mv->type = m->type;

#line 2082 "/home/alois/Documents/bah-bah/src/parser.bah"
mv->isConst = false;

#line 2083 "/home/alois/Documents/bah-bah/src/parser.bah"
mv->isArray = m->isArray;

#line 2084 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_989 = i;
    __Bah_realocate_arr(ds->membs, ____BAH_COMPILER_VAR_989);
    ds->membs->data[____BAH_COMPILER_VAR_989] = mv;

#line 2085 "/home/alois/Documents/bah-bah/src/parser.bah"
i = i+1;
};

#line 2088 "/home/alois/Documents/bah-bah/src/parser.bah"
struct debugStruct* ____BAH_COMPILER_VAR_990 = ds;
char ** ____BAH_COMPILER_VAR_992 = (char **)((char*)(____BAH_COMPILER_VAR_990) + offsetof(struct debugStruct, name));
struct reflectElement ____BAH_COMPILER_VAR_993 = __reflect(____BAH_COMPILER_VAR_992, sizeof(char *), "\010\0\0\0""cpstring", "\04\0\0\0""name", 0, 0, 0, 0, offsetof(struct debugStruct, name));
array(struct variable*)** ____BAH_COMPILER_VAR_994 = (array(struct variable*)**)((char*)(____BAH_COMPILER_VAR_990) + offsetof(struct debugStruct, membs));
struct variable** ____BAH_COMPILER_VAR_995 = 0;
char ** ____BAH_COMPILER_VAR_997 = (char **)((char*)(____BAH_COMPILER_VAR_995) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_998 = __reflect(____BAH_COMPILER_VAR_997, sizeof(char *), "\010\0\0\0""cpstring", "\04\0\0\0""name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_999 = (char **)((char*)(____BAH_COMPILER_VAR_995) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_1000 = __reflect(____BAH_COMPILER_VAR_999, sizeof(char *), "\010\0\0\0""cpstring", "\04\0\0\0""type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_1001 = (char*)((char*)(____BAH_COMPILER_VAR_995) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_1002 = __reflect(____BAH_COMPILER_VAR_1001, sizeof(char), "\04\0\0\0""bool", "\07\0\0\0""isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_1003 = (char **)((char*)(____BAH_COMPILER_VAR_995) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_1004 = __reflect(____BAH_COMPILER_VAR_1003, sizeof(char *), "\010\0\0\0""cpstring", "\010\0\0\0""constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_1005 = (char*)((char*)(____BAH_COMPILER_VAR_995) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_1006 = __reflect(____BAH_COMPILER_VAR_1005, sizeof(char), "\04\0\0\0""bool", "\07\0\0\0""isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_1007 = (char **)((char*)(____BAH_COMPILER_VAR_995) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_1008 = __reflect(____BAH_COMPILER_VAR_1007, sizeof(char *), "\010\0\0\0""cpstring", "\04\0\0\0""from", 0, 0, 0, 0, offsetof(struct variable, from));
void ** ____BAH_COMPILER_VAR_1009 = (void **)((char*)(____BAH_COMPILER_VAR_995) + offsetof(struct variable, declScope));
struct reflectElement ____BAH_COMPILER_VAR_1010 = __reflect(____BAH_COMPILER_VAR_1009, sizeof(void *), "\03\0\0\0""ptr", "\011\0\0\0""declScope", 0, 0, 0, 0, offsetof(struct variable, declScope));
char* ____BAH_COMPILER_VAR_1011 = (char*)((char*)(____BAH_COMPILER_VAR_995) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_1012 = __reflect(____BAH_COMPILER_VAR_1011, sizeof(char), "\04\0\0\0""bool", "\010\0\0\0""isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));
struct rope** ____BAH_COMPILER_VAR_1013 = (struct rope**)((char*)(____BAH_COMPILER_VAR_995) + offsetof(struct variable, declRope));
void ** ____BAH_COMPILER_VAR_1015 = (void **)((char*)(____BAH_COMPILER_VAR_1013) + offsetof(struct rope, left));
struct reflectElement ____BAH_COMPILER_VAR_1016 = __reflect(____BAH_COMPILER_VAR_1015, sizeof(void *), "\03\0\0\0""ptr", "\04\0\0\0""left", 0, 0, 0, 0, offsetof(struct rope, left));
void ** ____BAH_COMPILER_VAR_1017 = (void **)((char*)(____BAH_COMPILER_VAR_1013) + offsetof(struct rope, right));
struct reflectElement ____BAH_COMPILER_VAR_1018 = __reflect(____BAH_COMPILER_VAR_1017, sizeof(void *), "\03\0\0\0""ptr", "\05\0\0\0""right", 0, 0, 0, 0, offsetof(struct rope, right));
char ** ____BAH_COMPILER_VAR_1019 = (char **)((char*)(____BAH_COMPILER_VAR_1013) + offsetof(struct rope, str));
struct reflectElement ____BAH_COMPILER_VAR_1020 = __reflect(____BAH_COMPILER_VAR_1019, sizeof(char *), "\010\0\0\0""cpstring", "\03\0\0\0""str", 0, 0, 0, 0, offsetof(struct rope, str));
int* ____BAH_COMPILER_VAR_1021 = (int*)((char*)(____BAH_COMPILER_VAR_1013) + offsetof(struct rope, lCount));
struct reflectElement ____BAH_COMPILER_VAR_1022 = __reflect(____BAH_COMPILER_VAR_1021, sizeof(int), "\05\0\0\0""int32", "\06\0\0\0""lCount", 0, 0, 0, 0, offsetof(struct rope, lCount));
int* ____BAH_COMPILER_VAR_1023 = (int*)((char*)(____BAH_COMPILER_VAR_1013) + offsetof(struct rope, len));
struct reflectElement ____BAH_COMPILER_VAR_1024 = __reflect(____BAH_COMPILER_VAR_1023, sizeof(int), "\05\0\0\0""int32", "\03\0\0\0""len", 0, 0, 0, 0, offsetof(struct rope, len));
int* ____BAH_COMPILER_VAR_1025 = (int*)((char*)(____BAH_COMPILER_VAR_1013) + offsetof(struct rope, totalLen));
struct reflectElement ____BAH_COMPILER_VAR_1026 = __reflect(____BAH_COMPILER_VAR_1025, sizeof(int), "\05\0\0\0""int32", "\010\0\0\0""totalLen", 0, 0, 0, 0, offsetof(struct rope, totalLen));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_1014 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_1014->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_1014->length = 6;
        ____BAH_COMPILER_VAR_1014->data = memoryAlloc(____BAH_COMPILER_VAR_1014->length * ____BAH_COMPILER_VAR_1014->elemSize);
        ____BAH_COMPILER_VAR_1014->data[0] = ____BAH_COMPILER_VAR_1016;
____BAH_COMPILER_VAR_1014->data[1] = ____BAH_COMPILER_VAR_1018;
____BAH_COMPILER_VAR_1014->data[2] = ____BAH_COMPILER_VAR_1020;
____BAH_COMPILER_VAR_1014->data[3] = ____BAH_COMPILER_VAR_1022;
____BAH_COMPILER_VAR_1014->data[4] = ____BAH_COMPILER_VAR_1024;
____BAH_COMPILER_VAR_1014->data[5] = ____BAH_COMPILER_VAR_1026;
struct reflectElement ____BAH_COMPILER_VAR_1027 = __reflect(____BAH_COMPILER_VAR_1013, sizeof(struct rope), "\05\0\0\0""rope*", "\010\0\0\0""declRope", 0, 0, 1, ____BAH_COMPILER_VAR_1014, offsetof(struct variable, declRope));
char* ____BAH_COMPILER_VAR_1028 = (char*)((char*)(____BAH_COMPILER_VAR_995) + offsetof(struct variable, canBeNull));
struct reflectElement ____BAH_COMPILER_VAR_1029 = __reflect(____BAH_COMPILER_VAR_1028, sizeof(char), "\04\0\0\0""bool", "\011\0\0\0""canBeNull", 0, 0, 0, 0, offsetof(struct variable, canBeNull));
void ** ____BAH_COMPILER_VAR_1030 = (void **)((char*)(____BAH_COMPILER_VAR_995) + offsetof(struct variable, iterScope));
struct reflectElement ____BAH_COMPILER_VAR_1031 = __reflect(____BAH_COMPILER_VAR_1030, sizeof(void *), "\03\0\0\0""ptr", "\011\0\0\0""iterScope", 0, 0, 0, 0, offsetof(struct variable, iterScope));
char* ____BAH_COMPILER_VAR_1032 = (char*)((char*)(____BAH_COMPILER_VAR_995) + offsetof(struct variable, canBeReg));
struct reflectElement ____BAH_COMPILER_VAR_1033 = __reflect(____BAH_COMPILER_VAR_1032, sizeof(char), "\04\0\0\0""bool", "\010\0\0\0""canBeReg", 0, 0, 0, 0, offsetof(struct variable, canBeReg));
char* ____BAH_COMPILER_VAR_1034 = (char*)((char*)(____BAH_COMPILER_VAR_995) + offsetof(struct variable, isReg));
struct reflectElement ____BAH_COMPILER_VAR_1035 = __reflect(____BAH_COMPILER_VAR_1034, sizeof(char), "\04\0\0\0""bool", "\05\0\0\0""isReg", 0, 0, 0, 0, offsetof(struct variable, isReg));
void ** ____BAH_COMPILER_VAR_1036 = (void **)((char*)(____BAH_COMPILER_VAR_995) + offsetof(struct variable, lastSet));
struct reflectElement ____BAH_COMPILER_VAR_1037 = __reflect(____BAH_COMPILER_VAR_1036, sizeof(void *), "\03\0\0\0""ptr", "\07\0\0\0""lastSet", 0, 0, 0, 0, offsetof(struct variable, lastSet));
char* ____BAH_COMPILER_VAR_1038 = (char*)((char*)(____BAH_COMPILER_VAR_995) + offsetof(struct variable, isArg));
struct reflectElement ____BAH_COMPILER_VAR_1039 = __reflect(____BAH_COMPILER_VAR_1038, sizeof(char), "\04\0\0\0""bool", "\05\0\0\0""isArg", 0, 0, 0, 0, offsetof(struct variable, isArg));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_996 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_996->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_996->length = 15;
        ____BAH_COMPILER_VAR_996->data = memoryAlloc(____BAH_COMPILER_VAR_996->length * ____BAH_COMPILER_VAR_996->elemSize);
        ____BAH_COMPILER_VAR_996->data[0] = ____BAH_COMPILER_VAR_998;
____BAH_COMPILER_VAR_996->data[1] = ____BAH_COMPILER_VAR_1000;
____BAH_COMPILER_VAR_996->data[2] = ____BAH_COMPILER_VAR_1002;
____BAH_COMPILER_VAR_996->data[3] = ____BAH_COMPILER_VAR_1004;
____BAH_COMPILER_VAR_996->data[4] = ____BAH_COMPILER_VAR_1006;
____BAH_COMPILER_VAR_996->data[5] = ____BAH_COMPILER_VAR_1008;
____BAH_COMPILER_VAR_996->data[6] = ____BAH_COMPILER_VAR_1010;
____BAH_COMPILER_VAR_996->data[7] = ____BAH_COMPILER_VAR_1012;
____BAH_COMPILER_VAR_996->data[8] = ____BAH_COMPILER_VAR_1027;
____BAH_COMPILER_VAR_996->data[9] = ____BAH_COMPILER_VAR_1029;
____BAH_COMPILER_VAR_996->data[10] = ____BAH_COMPILER_VAR_1031;
____BAH_COMPILER_VAR_996->data[11] = ____BAH_COMPILER_VAR_1033;
____BAH_COMPILER_VAR_996->data[12] = ____BAH_COMPILER_VAR_1035;
____BAH_COMPILER_VAR_996->data[13] = ____BAH_COMPILER_VAR_1037;
____BAH_COMPILER_VAR_996->data[14] = ____BAH_COMPILER_VAR_1039;
struct reflectElement ____BAH_COMPILER_VAR_1040 = __reflect(____BAH_COMPILER_VAR_995, sizeof(struct variable), "\011\0\0\0""variable*", "\0\0\0\0""", 0, 0, 1, ____BAH_COMPILER_VAR_996, 0);

        struct reflectElement ____BAH_COMPILER_VAR_1041 = ____BAH_COMPILER_VAR_1040;
        struct reflectElement ____BAH_COMPILER_VAR_1042 = __reflect(____BAH_COMPILER_VAR_994, sizeof(array(struct variable*)*), "\013\0\0\0""[]variable*", "\05\0\0\0""membs", 1, &____BAH_COMPILER_VAR_1041, 0, 0, offsetof(struct debugStruct, membs));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_991 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_991->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_991->length = 2;
        ____BAH_COMPILER_VAR_991->data = memoryAlloc(____BAH_COMPILER_VAR_991->length * ____BAH_COMPILER_VAR_991->elemSize);
        ____BAH_COMPILER_VAR_991->data[0] = ____BAH_COMPILER_VAR_993;
____BAH_COMPILER_VAR_991->data[1] = ____BAH_COMPILER_VAR_1042;
struct reflectElement ____BAH_COMPILER_VAR_1043 = __reflect(____BAH_COMPILER_VAR_990, sizeof(struct debugStruct), "\014\0\0\0""debugStruct*", "\02\0\0\0""ds", 0, 0, 1, ____BAH_COMPILER_VAR_991, 0);
debugPrint("\016\0\0\0""struct_declare",nameToken.line,____BAH_COMPILER_VAR_1043);
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
struct func* ____BAH_COMPILER_VAR_1044 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_1044->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_1044->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_1044->args->length = 0;
            ____BAH_COMPILER_VAR_1044->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_1044->from = "\0\0\0\0""";
____BAH_COMPILER_VAR_1044->file = "\0\0\0\0""";
____BAH_COMPILER_VAR_1044->line = 1;
struct func* fn = ____BAH_COMPILER_VAR_1044;

#line 2115 "/home/alois/Documents/bah-bah/src/parser.bah"
char * code = parseFnHeader("\0\0\0\0""",l,&i,fn,elems);

#line 2116 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct func*)* fns = elems->fns;

#line 2117 "/home/alois/Documents/bah-bah/src/parser.bah"
fn->isBinding = true;

#line 2118 "/home/alois/Documents/bah-bah/src/parser.bah"
fn->isCbinding = (doesOutput==false);

#line 2119 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1045 = len(fns);
    __Bah_realocate_arr(fns, ____BAH_COMPILER_VAR_1045);
    fns->data[____BAH_COMPILER_VAR_1045] = fn;

#line 2120 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((doesOutput==true)) {

#line 2121 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1046 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1046[1] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_1046[0] = code;char * ____BAH_COMPILER_VAR_1047 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1046, 2);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1047));
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
char** ____BAH_COMPILER_VAR_1048 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1048[1] = t.cont;____BAH_COMPILER_VAR_1048[0] = tp;char * ____BAH_COMPILER_VAR_1049 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1048, 2);tp = ____BAH_COMPILER_VAR_1049;
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
char** ____BAH_COMPILER_VAR_1050 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1050[4] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_1050[3] = ft.cont;____BAH_COMPILER_VAR_1050[2] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_1050[1] = cTypeNewTypeStr;____BAH_COMPILER_VAR_1050[0] = "\010\0\0\0""typedef ";char * ____BAH_COMPILER_VAR_1051 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1050, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1051));
}

#line 2139 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((debug==true)) {

#line 2140 "/home/alois/Documents/bah-bah/src/parser.bah"
struct debugType* ____BAH_COMPILER_VAR_1052 = memoryAlloc(sizeof(struct debugType));
struct debugType* dt = ____BAH_COMPILER_VAR_1052;

#line 2141 "/home/alois/Documents/bah-bah/src/parser.bah"
dt->name = ft.cont;

#line 2142 "/home/alois/Documents/bah-bah/src/parser.bah"
dt->refers = tp;

#line 2143 "/home/alois/Documents/bah-bah/src/parser.bah"
struct debugType* ____BAH_COMPILER_VAR_1053 = dt;
char ** ____BAH_COMPILER_VAR_1055 = (char **)((char*)(____BAH_COMPILER_VAR_1053) + offsetof(struct debugType, name));
struct reflectElement ____BAH_COMPILER_VAR_1056 = __reflect(____BAH_COMPILER_VAR_1055, sizeof(char *), "\010\0\0\0""cpstring", "\04\0\0\0""name", 0, 0, 0, 0, offsetof(struct debugType, name));
char ** ____BAH_COMPILER_VAR_1057 = (char **)((char*)(____BAH_COMPILER_VAR_1053) + offsetof(struct debugType, refers));
struct reflectElement ____BAH_COMPILER_VAR_1058 = __reflect(____BAH_COMPILER_VAR_1057, sizeof(char *), "\010\0\0\0""cpstring", "\06\0\0\0""refers", 0, 0, 0, 0, offsetof(struct debugType, refers));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_1054 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_1054->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_1054->length = 2;
        ____BAH_COMPILER_VAR_1054->data = memoryAlloc(____BAH_COMPILER_VAR_1054->length * ____BAH_COMPILER_VAR_1054->elemSize);
        ____BAH_COMPILER_VAR_1054->data[0] = ____BAH_COMPILER_VAR_1056;
____BAH_COMPILER_VAR_1054->data[1] = ____BAH_COMPILER_VAR_1058;
struct reflectElement ____BAH_COMPILER_VAR_1059 = __reflect(____BAH_COMPILER_VAR_1053, sizeof(struct debugType), "\012\0\0\0""debugType*", "\02\0\0\0""dt", 0, 0, 1, ____BAH_COMPILER_VAR_1054, 0);
debugPrint("\014\0\0\0""type_declare",ft.line,____BAH_COMPILER_VAR_1059);
}

#line 2146 "/home/alois/Documents/bah-bah/src/parser.bah"
array(char *)* tps = elems->types;

#line 2147 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1060 = len(tps);
    __Bah_realocate_arr(tps, ____BAH_COMPILER_VAR_1060);
    tps->data[____BAH_COMPILER_VAR_1060] = ft.cont;
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

    unsigned int ____BAH_COMPILER_VAR_1061 = len(clibs);
    __Bah_realocate_arr(clibs, ____BAH_COMPILER_VAR_1061);
    clibs->data[____BAH_COMPILER_VAR_1061] = ccstr;

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
struct variable* ____BAH_COMPILER_VAR_1062 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1062->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_1062->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_1062->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_1062->from = "\0\0\0\0""";
struct variable* v = ____BAH_COMPILER_VAR_1062;

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

    unsigned int ____BAH_COMPILER_VAR_1063 = len(vars);
    __Bah_realocate_arr(vars, ____BAH_COMPILER_VAR_1063);
    vars->data[____BAH_COMPILER_VAR_1063] = v;

#line 2225 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((valt.type==TOKEN_TYPE_STR)) {

#line 2226 "/home/alois/Documents/bah-bah/src/parser.bah"
valt.cont = strLitteralToBahStr(valt.cont);
}

#line 2229 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1064 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1064[4] = "\01\0\0\0""\n";____BAH_COMPILER_VAR_1064[3] = valt.cont;____BAH_COMPILER_VAR_1064[2] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_1064[1] = v->name;____BAH_COMPILER_VAR_1064[0] = "\010\0\0\0""#define ";char * ____BAH_COMPILER_VAR_1065 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1064, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1065));
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
char** ____BAH_COMPILER_VAR_1066 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1066[2] = "\01\0\0\0"".";____BAH_COMPILER_VAR_1066[1] = currentFn->returns->type;____BAH_COMPILER_VAR_1066[0] = "\031\0\0\0""Cannot return nothing as ";char * ____BAH_COMPILER_VAR_1067 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1066, 3);throwErr(&l->data[0],____BAH_COMPILER_VAR_1067);
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

                struct string ____BAH_COMPILER_VAR_1068 = string(compilerState.currentDir);
                if ((isUnsafe==false)&&(string__hasPrefix(&____BAH_COMPILER_VAR_1068,BAH_DIR)==false)&&(currentFn->returns->type[strlen(currentFn->returns->type)-1+4]!=33)) {

#line 2261 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((tmpV->canBeNull==true)||(strcmp(rv, "\04\0\0\0""null") == 0)) {

#line 2262 "/home/alois/Documents/bah-bah/src/parser.bah"
currentFn->returns->canBeNull = true;

#line 2263 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1069 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1069[2] = "\071\0\0\0""' that can be null as pointer.\n\tUse maybe values instead.";____BAH_COMPILER_VAR_1069[1] = tmpV->name;____BAH_COMPILER_VAR_1069[0] = "\013\0\0\0""Returning '";char * ____BAH_COMPILER_VAR_1070 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1069, 3);throwNoticeLine(____BAH_COMPILER_VAR_1070,rvt.line);
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
char** ____BAH_COMPILER_VAR_1071 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_1071[5] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_1071[4] = rvt.cont;____BAH_COMPILER_VAR_1071[3] = "\01\0\0\0""=";____BAH_COMPILER_VAR_1071[2] = rv;____BAH_COMPILER_VAR_1071[1] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_1071[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_1072 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1071, 6);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1072));
}

#line 2272 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((compTypes(tt,currentFn->returns->type)==false), 0)) {

#line 2273 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1073 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1073[4] = "\01\0\0\0"".";____BAH_COMPILER_VAR_1073[3] = currentFn->returns->type;____BAH_COMPILER_VAR_1073[2] = "\05\0\0\0"") as ";____BAH_COMPILER_VAR_1073[1] = tt;____BAH_COMPILER_VAR_1073[0] = "\027\0\0\0""Cannot return {TOKEN} (";char * ____BAH_COMPILER_VAR_1074 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1073, 5);throwErr(&rvt,____BAH_COMPILER_VAR_1074);
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
char** ____BAH_COMPILER_VAR_1075 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_1075[5] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_1075[4] = rv;____BAH_COMPILER_VAR_1075[3] = "\03\0\0\0"" = ";____BAH_COMPILER_VAR_1075[2] = rvar;____BAH_COMPILER_VAR_1075[1] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_1075[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_1076 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1075, 6);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1076));

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
char** ____BAH_COMPILER_VAR_1077 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1077[2] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1077[1] = rvar;____BAH_COMPILER_VAR_1077[0] = "\012\0\0\0""buffToStr(";char * ____BAH_COMPILER_VAR_1078 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1077, 3);rvar = ____BAH_COMPILER_VAR_1078;
}

#line 2296 "/home/alois/Documents/bah-bah/src/parser.bah"
else if (string__hasPrefix(&stt,"\06\0\0\0""tuple:")) {

#line 2297 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct string)* parts = splitString(stt,"\01\0\0\0"":");

#line 2298 "/home/alois/Documents/bah-bah/src/parser.bah"
char * v = genCompilerVar();

#line 2299 "/home/alois/Documents/bah-bah/src/parser.bah"

                struct string ____BAH_COMPILER_VAR_1079 = getCType(tt,elems);
                char * ____BAH_COMPILER_VAR_1080 =string__str(&parts->data[2]);
                struct string ____BAH_COMPILER_VAR_1081 = getCType(____BAH_COMPILER_VAR_1080,elems);
                char * ____BAH_COMPILER_VAR_1082 =string__str(&parts->data[2]);
                struct string ____BAH_COMPILER_VAR_1083 = getCType(____BAH_COMPILER_VAR_1082,elems);
                char** ____BAH_COMPILER_VAR_1084 = alloca(17 * sizeof(char*));____BAH_COMPILER_VAR_1084[16] = "\02\0\0\0"");";____BAH_COMPILER_VAR_1084[15] = string__str(&parts->data[1]);____BAH_COMPILER_VAR_1084[14] = "\04\0\0\0"") * ";____BAH_COMPILER_VAR_1084[13] = string__str(&____BAH_COMPILER_VAR_1083);____BAH_COMPILER_VAR_1084[12] = "\011\0\0\0"", sizeof(";____BAH_COMPILER_VAR_1084[11] = rv;____BAH_COMPILER_VAR_1084[10] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_1084[9] = v;____BAH_COMPILER_VAR_1084[8] = "\027\0\0\0""));\n            memcpy(";____BAH_COMPILER_VAR_1084[7] = string__str(&____BAH_COMPILER_VAR_1081);____BAH_COMPILER_VAR_1084[6] = "\012\0\0\0"" * sizeof(";____BAH_COMPILER_VAR_1084[5] = string__str(&parts->data[1]);____BAH_COMPILER_VAR_1084[4] = "\017\0\0\0"" = memoryAlloc(";____BAH_COMPILER_VAR_1084[3] = v;____BAH_COMPILER_VAR_1084[2] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_1084[1] = string__str(&____BAH_COMPILER_VAR_1079);____BAH_COMPILER_VAR_1084[0] = "\0\0\0\0""";char * ____BAH_COMPILER_VAR_1085 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1084, 17);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1085));

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

    unsigned int ____BAH_COMPILER_VAR_1086 = j;
    __Bah_realocate_arr(excl, ____BAH_COMPILER_VAR_1086);
    excl->data[____BAH_COMPILER_VAR_1086] = currentFn->args->data[j];
};

#line 2308 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((tmpV!=null)) {

#line 2309 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1087 = len(excl);
    __Bah_realocate_arr(excl, ____BAH_COMPILER_VAR_1087);
    excl->data[____BAH_COMPILER_VAR_1087] = tmpV;
}

#line 2311 "/home/alois/Documents/bah-bah/src/parser.bah"
endRCPscope(elems,excl);
}

#line 2313 "/home/alois/Documents/bah-bah/src/parser.bah"
fixMeEndScope(elems,&l->data[0]);

#line 2314 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1088 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1088[2] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_1088[1] = rvar;____BAH_COMPILER_VAR_1088[0] = "\07\0\0\0""return ";char * ____BAH_COMPILER_VAR_1089 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1088, 3);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1089));
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

    unsigned int ____BAH_COMPILER_VAR_1090 = j;
    __Bah_realocate_arr(excl, ____BAH_COMPILER_VAR_1090);
    excl->data[____BAH_COMPILER_VAR_1090] = currentFn->args->data[j];
};

#line 2321 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((tmpV!=null)) {

#line 2322 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1091 = len(excl);
    __Bah_realocate_arr(excl, ____BAH_COMPILER_VAR_1091);
    excl->data[____BAH_COMPILER_VAR_1091] = tmpV;
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

    unsigned int ____BAH_COMPILER_VAR_1092 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_1092);
    tokens->data[____BAH_COMPILER_VAR_1092] = t;

#line 2351 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;
};

#line 2354 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1093 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1093[3] = "\04\0\0\0"") {\n";____BAH_COMPILER_VAR_1093[2] = condt.cont;____BAH_COMPILER_VAR_1093[1] = prevIfShortcut;____BAH_COMPILER_VAR_1093[0] = "\04\0\0\0""if (";char * ____BAH_COMPILER_VAR_1094 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1093, 4);struct rope* ifHeader = rope(____BAH_COMPILER_VAR_1094);

#line 2356 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope__add(OUTPUT, ifHeader);

#line 2358 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Elems* ifElems = dupElems(elems);

#line 2360 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((fromElse==true)) {

#line 2361 "/home/alois/Documents/bah-bah/src/parser.bah"
i = 0;

#line 2361 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<len(prevIfChecks)); 
#line 2361 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 2362 "/home/alois/Documents/bah-bah/src/parser.bah"
struct varCheck bc = prevIfChecks->data[i];

#line 2363 "/home/alois/Documents/bah-bah/src/parser.bah"
bc.checkNull = (bc.checkNull==false);

#line 2364 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1095 = i;
    __Bah_realocate_arr(ifElems->branchChecks, ____BAH_COMPILER_VAR_1095);
    ifElems->branchChecks->data[____BAH_COMPILER_VAR_1095] = bc;
};
}

#line 2368 "/home/alois/Documents/bah-bah/src/parser.bah"
i = 0;

#line 2368 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<len(currChecks)); 
#line 2368 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 2369 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1096 = len(ifElems->branchChecks);
    __Bah_realocate_arr(ifElems->branchChecks, ____BAH_COMPILER_VAR_1096);
    ifElems->branchChecks->data[____BAH_COMPILER_VAR_1096] = currChecks->data[i];
};

#line 2371 "/home/alois/Documents/bah-bah/src/parser.bah"
prevIfChecks = ifElems->branchChecks;

#line 2373 "/home/alois/Documents/bah-bah/src/parser.bah"
char oldIB = compilerState.isBranch;

#line 2374 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.isBranch = true;

#line 2375 "/home/alois/Documents/bah-bah/src/parser.bah"
beginRCPscopeLeaky(ifElems);

#line 2376 "/home/alois/Documents/bah-bah/src/parser.bah"
parseLines(tokens,ifElems);

#line 2378 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((ifElems->currFlowEnd==true)) {

#line 2379 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1097 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1097[2] = "\010\0\0\0"", 0)) {\n";____BAH_COMPILER_VAR_1097[1] = condt.cont;____BAH_COMPILER_VAR_1097[0] = "\025\0\0\0""if (__builtin_expect(";char * ____BAH_COMPILER_VAR_1098 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1097, 3);OUTPUT->totalLen = OUTPUT->totalLen+ropeSet(ifHeader,____BAH_COMPILER_VAR_1098);
}

#line 2383 "/home/alois/Documents/bah-bah/src/parser.bah"
endRCPscopeLeaky(ifElems,null,true);

#line 2384 "/home/alois/Documents/bah-bah/src/parser.bah"
fixMeEndScope(ifElems,&tokens->data[len(tokens)-1]);

#line 2385 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((debug==true)) {

#line 2386 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok lt = l->data[len(l)-1];

#line 2387 "/home/alois/Documents/bah-bah/src/parser.bah"
debugEndScope(lt.line,ifElems);
}

#line 2389 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.isBranch = oldIB;

#line 2390 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope__add(OUTPUT, rope("\02\0\0\0""}\n"));

#line 2392 "/home/alois/Documents/bah-bah/src/parser.bah"
prevIfShortcut = "\0\0\0\0""";
};

#line 2395 "/home/alois/Documents/bah-bah/src/parser.bah"
void parseElse(__BAH_ARR_TYPE_Tok l,struct Elems* elems){

#line 2397 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((prevLine!=LINE_TYPE_IF)) {

#line 2398 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((prevLine!=LINE_TYPE_ELSE), 0)) {

#line 2399 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&l->data[0],"\052\0\0\0""Can only use {TOKEN} after 'if' statement.");
}
}

#line 2402 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((len(l)<3), 0)) {

#line 2403 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&l->data[0],"\062\0\0\0""Incalid usage of {TOKEN}, must be 'else {<code>}'.");
}

#line 2405 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok ft = l->data[1];

#line 2407 "/home/alois/Documents/bah-bah/src/parser.bah"
char prevReturned = prevIfExits;

#line 2409 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope__add(OUTPUT, rope("\05\0\0\0""else "));

#line 2410 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(ft.cont, "\02\0\0\0""if") == 0)) {

#line 2411 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);

#line 2412 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int i = 1;

#line 2412 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i<len(l))) {

#line 2413 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1099 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1099);
    memory->data[____BAH_COMPILER_VAR_1099] = l->data[i];

#line 2414 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;
};

#line 2416 "/home/alois/Documents/bah-bah/src/parser.bah"
parseIf(memory,true,elems);

#line 2417 "/home/alois/Documents/bah-bah/src/parser.bah"
prevLine = LINE_TYPE_IF;
}

#line 2419 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 2420 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((strcmp(ft.cont, "\01\0\0\0""{") != 0), 0)) {

#line 2421 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&ft,"\041\0\0\0""Expected 'if' or '{' not {TOKEN}.");
}

#line 2423 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);

#line 2424 "/home/alois/Documents/bah-bah/src/parser.bah"
unsigned long int max = len(l)-1;

#line 2425 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int i = 2;

#line 2425 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i<max)) {

#line 2426 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1100 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1100);
    memory->data[____BAH_COMPILER_VAR_1100] = l->data[i];

#line 2427 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;
};

#line 2429 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope__add(OUTPUT, rope("\02\0\0\0""{\n"));

#line 2430 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Elems* ifElems = dupElems(elems);

#line 2432 "/home/alois/Documents/bah-bah/src/parser.bah"
i = 0;

#line 2432 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<len(prevIfChecks)); 
#line 2432 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 2433 "/home/alois/Documents/bah-bah/src/parser.bah"
struct varCheck bc = prevIfChecks->data[i];

#line 2434 "/home/alois/Documents/bah-bah/src/parser.bah"
bc.checkNull = (bc.checkNull==false);

#line 2435 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1101 = i;
    __Bah_realocate_arr(ifElems->branchChecks, ____BAH_COMPILER_VAR_1101);
    ifElems->branchChecks->data[____BAH_COMPILER_VAR_1101] = bc;
};

#line 2438 "/home/alois/Documents/bah-bah/src/parser.bah"
char oldIB = compilerState.isBranch;

#line 2439 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.isBranch = true;

#line 2440 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = l->data[0];

#line 2441 "/home/alois/Documents/bah-bah/src/parser.bah"
beginRCPscopeLeaky(ifElems);

#line 2442 "/home/alois/Documents/bah-bah/src/parser.bah"
parseLines(memory,ifElems);

#line 2443 "/home/alois/Documents/bah-bah/src/parser.bah"
endRCPscopeLeaky(ifElems,null,true);

#line 2444 "/home/alois/Documents/bah-bah/src/parser.bah"
fixMeEndScope(ifElems,&memory->data[len(memory)-1]);

#line 2445 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((debug==true)) {

#line 2446 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok lt = l->data[len(l)-1];

#line 2447 "/home/alois/Documents/bah-bah/src/parser.bah"
debugEndScope(lt.line,ifElems);
}

#line 2449 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.isBranch = oldIB;

#line 2450 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope__add(OUTPUT, rope("\02\0\0\0""}\n"));

#line 2451 "/home/alois/Documents/bah-bah/src/parser.bah"
prevIfExits = false;
}
};
void parseLine(__BAH_ARR_TYPE_Tok l,struct Elems* elems);

#line 2460 "/home/alois/Documents/bah-bah/src/parser.bah"
void parseFor(__BAH_ARR_TYPE_Tok l,struct Elems* elems){

#line 2462 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((len(l)<4), 0)) {

#line 2463 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&l->data[0],"\031\0\0\0""Invalid usage of {TOKEN}.");
}

#line 2466 "/home/alois/Documents/bah-bah/src/parser.bah"
long int nbComas = 0;

#line 2467 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int i = 1;

#line 2467 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i<len(l))) {

#line 2468 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = l->data[i];

#line 2469 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "\01\0\0\0""{") == 0)) {

#line 2470 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}

#line 2472 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((t.type==TOKEN_TYPE_SYNTAX)&&(strcmp(t.cont, "\01\0\0\0"",") == 0)) {

#line 2473 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((nbComas==1), 0)) {

#line 2474 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"\106\0\0\0""Invalid line separation of for, cannot set more than 2 lines: {TOKEN}.");
}

#line 2476 "/home/alois/Documents/bah-bah/src/parser.bah"
nbComas = nbComas+1;
}

#line 2478 "/home/alois/Documents/bah-bah/src/parser.bah"
i = i+1;
};

#line 2481 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Elems* ifElems = dupElems(elems);

#line 2482 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct Tok)* tokens = memoryAlloc(sizeof(array(struct Tok)));

tokens->length = 0;
tokens->elemSize = sizeof(struct Tok);

#line 2483 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok condt = l->data[1];

#line 2484 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ____BAH_COMPILER_VAR_1102 =getTypeFromToken(&condt,true,elems);if (__builtin_expect((compTypes(____BAH_COMPILER_VAR_1102,"\04\0\0\0""bool")==false), 0)) {

#line 2485 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&condt,"\061\0\0\0""Cannot use {TOKEN} as condition in for statement.");
}

#line 2488 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((nbComas>0)) {

#line 2489 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((nbComas!=1), 0)) {

#line 2490 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = l->data[0];

#line 2491 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"\150\0\0\0""Invalid usage of {TOKEN}, can only partition line in 2 using 'for <condition>, <insctruction> {<code>}'.");
}

#line 2494 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct Tok)* inst = memoryAlloc(sizeof(array(struct Tok)));

inst->length = 0;
inst->elemSize = sizeof(struct Tok);

#line 2497 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok st = l->data[2];

#line 2499 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((st.type!=TOKEN_TYPE_SYNTAX)||(strcmp(st.cont, "\01\0\0\0"",") != 0), 0)) {

#line 2500 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&st,"\074\0\0\0""Cannot use {TOKEN}, need ',' to split for loop instructions.");
}

#line 2503 "/home/alois/Documents/bah-bah/src/parser.bah"
i = 3;

#line 2503 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<len(l)); 
#line 2503 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 2504 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = l->data[i];

#line 2505 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((t.type==TOKEN_TYPE_ENCL)&&(strcmp(t.cont, "\01\0\0\0""{") == 0)) {

#line 2506 "/home/alois/Documents/bah-bah/src/parser.bah"
break;
}

#line 2508 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1103 = len(inst);
    __Bah_realocate_arr(inst, ____BAH_COMPILER_VAR_1103);
    inst->data[____BAH_COMPILER_VAR_1103] = t;
};

#line 2511 "/home/alois/Documents/bah-bah/src/parser.bah"
struct rope* oldOut = OUTPUT;

#line 2512 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope("\0\0\0\0""");

#line 2514 "/home/alois/Documents/bah-bah/src/parser.bah"
parseLine(inst,ifElems);

#line 2516 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ____BAH_COMPILER_VAR_1104 =rope__toStr(OUTPUT);struct string instC = string(____BAH_COMPILER_VAR_1104);

#line 2517 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = oldOut;

#line 2518 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimRight(&instC,2);

#line 2520 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = l->data[i];

#line 2521 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((strcmp(t.cont, "\01\0\0\0""{") != 0), 0)) {

#line 2522 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"\114\0\0\0""Expected '{' not {TOKEN} after '<condition>,<instruction>' in for statement.");
}

#line 2525 "/home/alois/Documents/bah-bah/src/parser.bah"
unsigned long int max = len(l)-1;

#line 2526 "/home/alois/Documents/bah-bah/src/parser.bah"
i = i+1;

#line 2526 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<max); 
#line 2526 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 2527 "/home/alois/Documents/bah-bah/src/parser.bah"
t = l->data[i];

#line 2528 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1105 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_1105);
    tokens->data[____BAH_COMPILER_VAR_1105] = t;
};

#line 2531 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1106 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1106[4] = "\04\0\0\0"") {\n";____BAH_COMPILER_VAR_1106[3] = string__str(&instC);____BAH_COMPILER_VAR_1106[2] = "\02\0\0\0""; ";____BAH_COMPILER_VAR_1106[1] = condt.cont;____BAH_COMPILER_VAR_1106[0] = "\07\0\0\0""for (; ";char * ____BAH_COMPILER_VAR_1107 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1106, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1107));
}

#line 2533 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 2534 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = l->data[2];

#line 2535 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((strcmp(t.cont, "\01\0\0\0""{") != 0), 0)) {

#line 2536 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"\073\0\0\0""Expected '{' not {TOKEN} after condtition in for statement.");
}

#line 2538 "/home/alois/Documents/bah-bah/src/parser.bah"
unsigned long int max = len(l)-1;

#line 2539 "/home/alois/Documents/bah-bah/src/parser.bah"
i = 3;

#line 2539 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<max); 
#line 2539 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 2540 "/home/alois/Documents/bah-bah/src/parser.bah"
t = l->data[i];

#line 2541 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1108 = len(tokens);
    __Bah_realocate_arr(tokens, ____BAH_COMPILER_VAR_1108);
    tokens->data[____BAH_COMPILER_VAR_1108] = t;
};

#line 2543 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1109 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1109[2] = "\04\0\0\0"") {\n";____BAH_COMPILER_VAR_1109[1] = condt.cont;____BAH_COMPILER_VAR_1109[0] = "\07\0\0\0""while (";char * ____BAH_COMPILER_VAR_1110 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1109, 3);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1110));
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
char** ____BAH_COMPILER_VAR_1111 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1111[2] = "\163\0\0\0""' but its value is not changed inside the scope of the for loop.\n    This may result in the loop never terminating.";____BAH_COMPILER_VAR_1111[1] = v->name;____BAH_COMPILER_VAR_1111[0] = "\041\0\0\0""For loop iterates over variable '";char * ____BAH_COMPILER_VAR_1112 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1111, 3);throwWarningLine(____BAH_COMPILER_VAR_1112,t.line);
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
OUTPUT = rope__add(OUTPUT, rope("\03\0\0\0""};\n"));
};

#line 2582 "/home/alois/Documents/bah-bah/src/parser.bah"
void parseForOp(__BAH_ARR_TYPE_Tok l,struct Elems* elems){

#line 2584 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok ft = l->data[0];

#line 2585 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((compilerState.isFor==false), 0)) {

#line 2586 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&ft,"\050\0\0\0""Cannot {TOKEN} outside of for statement.");
}

#line 2588 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((len(l)!=1), 0)) {

#line 2589 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&ft,"\037\0\0\0""Nothing expected after {TOKEN}.");
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
char** ____BAH_COMPILER_VAR_1113 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1113[1] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_1113[0] = ft.cont;char * ____BAH_COMPILER_VAR_1114 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1113, 2);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1114));
};

#line 2601 "/home/alois/Documents/bah-bah/src/parser.bah"
char ____BAH_COMPILER_VAR_1115(array(char *)* arr, char * el) {
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
if (____BAH_COMPILER_VAR_1115(compilerState.evals, fn->name)) {

#line 2603 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}

#line 2606 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1116 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1116[1] = fn->name;____BAH_COMPILER_VAR_1116[0] = "\013\0\0\0""__Bah_eval_";char * ____BAH_COMPILER_VAR_1117 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1116, 2);struct func* ____BAH_COMPILER_VAR_1118 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_1118->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_1118->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_1118->args->length = 0;
            ____BAH_COMPILER_VAR_1118->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_1118->from = "\0\0\0\0""";
____BAH_COMPILER_VAR_1118->file = "\0\0\0\0""";
____BAH_COMPILER_VAR_1118->line = 1;
____BAH_COMPILER_VAR_1118->name = ____BAH_COMPILER_VAR_1117;
struct func* efn = ____BAH_COMPILER_VAR_1118;

#line 2609 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* ____BAH_COMPILER_VAR_1119 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1119->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_1119->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_1119->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_1119->from = "\0\0\0\0""";
____BAH_COMPILER_VAR_1119->type = "\03\0\0\0""ptr";
efn->returns = ____BAH_COMPILER_VAR_1119;

#line 2613 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* ____BAH_COMPILER_VAR_1120 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1120->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_1120->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_1120->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_1120->from = "\0\0\0\0""";
____BAH_COMPILER_VAR_1120->name = "\06\0\0\0""fnArgs";
____BAH_COMPILER_VAR_1120->type = "\05\0\0\0""[]ptr";
efn->args = memoryAlloc(sizeof(array(struct variable*)));

efn->args->length = 1;
efn->args->elemSize = sizeof(struct variable*);
efn->args->data = memoryAlloc(sizeof(struct variable*) * 50);
                    efn->args->realLength = 50;
efn->args->data[0] = ____BAH_COMPILER_VAR_1120;

#line 2620 "/home/alois/Documents/bah-bah/src/parser.bah"
char * fnBinding = "\0\0\0\0""";

#line 2621 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1121 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1121[1] = "\01\0\0\0""(";____BAH_COMPILER_VAR_1121[0] = fn->name;char * ____BAH_COMPILER_VAR_1122 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1121, 2);char * fnCall = ____BAH_COMPILER_VAR_1122;

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
string__append(&cType,"\01\0\0\0""*");
}

#line 2629 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1123 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_1123[5] = "\02\0\0\0""];";____BAH_COMPILER_VAR_1123[4] = intToStr(i);____BAH_COMPILER_VAR_1123[3] = "\020\0\0\0"" = fnArgs->data[";____BAH_COMPILER_VAR_1123[2] = v;____BAH_COMPILER_VAR_1123[1] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_1123[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_1124 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1123, 6);char** ____BAH_COMPILER_VAR_1125 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1125[1] = ____BAH_COMPILER_VAR_1124;____BAH_COMPILER_VAR_1125[0] = fnBinding;char * ____BAH_COMPILER_VAR_1126 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1125, 2);fnBinding = ____BAH_COMPILER_VAR_1126;

#line 2630 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((i!=0)) {

#line 2631 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1127 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1127[1] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_1127[0] = fnCall;char * ____BAH_COMPILER_VAR_1128 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1127, 2);fnCall = ____BAH_COMPILER_VAR_1128;
}

#line 2633 "/home/alois/Documents/bah-bah/src/parser.bah"
if (isRCPpointerType(a->type)) {

#line 2634 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1129 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1129[1] = v;____BAH_COMPILER_VAR_1129[0] = fnCall;char * ____BAH_COMPILER_VAR_1130 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1129, 2);fnCall = ____BAH_COMPILER_VAR_1130;
}

#line 2635 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 2636 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1131 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1131[1] = v;____BAH_COMPILER_VAR_1131[0] = "\01\0\0\0""*";char * ____BAH_COMPILER_VAR_1132 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1131, 2);char** ____BAH_COMPILER_VAR_1133 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1133[1] = ____BAH_COMPILER_VAR_1132;____BAH_COMPILER_VAR_1133[0] = fnCall;char * ____BAH_COMPILER_VAR_1134 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1133, 2);fnCall = ____BAH_COMPILER_VAR_1134;
}
};

#line 2640 "/home/alois/Documents/bah-bah/src/parser.bah"
char * setReturnValue = "\014\0\0\0""void* r = 0;";

#line 2641 "/home/alois/Documents/bah-bah/src/parser.bah"
if (isRCPpointerType(fn->returns->type)) {

#line 2642 "/home/alois/Documents/bah-bah/src/parser.bah"
setReturnValue = "\012\0\0\0""void* r = ";
}

#line 2643 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 2644 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string cType = getCType(fn->returns->type,elems);

#line 2645 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(string__str(&cType), "\04\0\0\0""void") != 0)) {

#line 2646 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1135 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1135[3] = "\010\0\0\0""));*r = ";____BAH_COMPILER_VAR_1135[2] = string__str(&cType);____BAH_COMPILER_VAR_1135[1] = "\031\0\0\0""* r = memoryAlloc(sizeof(";____BAH_COMPILER_VAR_1135[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_1136 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1135, 4);setReturnValue = ____BAH_COMPILER_VAR_1136;
}
}

#line 2650 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1137 = alloca(12 * sizeof(char*));____BAH_COMPILER_VAR_1137[11] = "\042\0\0\0"");\n        return (void*)r;\n    };";____BAH_COMPILER_VAR_1137[10] = fnCall;____BAH_COMPILER_VAR_1137[9] = setReturnValue;____BAH_COMPILER_VAR_1137[8] = "\011\0\0\0""\n        ";____BAH_COMPILER_VAR_1137[7] = fnBinding;____BAH_COMPILER_VAR_1137[6] = "\125\0\0\0""() with the wrong number of arguments.\", \"BAH_COMPILER_INTERNAL\");\n        }\n        ";____BAH_COMPILER_VAR_1137[5] = fn->name;____BAH_COMPILER_VAR_1137[4] = "\073\0\0\0"") {\n            __BAH_panic((char*)\"eval: calling function ";____BAH_COMPILER_VAR_1137[3] = intToStr(len(fn->args));____BAH_COMPILER_VAR_1137[2] = "\067\0\0\0""(array(void*)* fnArgs) {\n        if (fnArgs->length != ";____BAH_COMPILER_VAR_1137[1] = efn->name;____BAH_COMPILER_VAR_1137[0] = "\046\0\0\0""void* __attribute__((optimize(\"O0\"))) ";char * ____BAH_COMPILER_VAR_1138 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1137, 12);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1138));

#line 2659 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1139 = len(compilerState.evals);
    __Bah_realocate_arr(compilerState.evals, ____BAH_COMPILER_VAR_1139);
    compilerState.evals->data[____BAH_COMPILER_VAR_1139] = fn->name;

#line 2660 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1140 = len(elems->fns);
    __Bah_realocate_arr(elems->fns, ____BAH_COMPILER_VAR_1140);
    elems->fns->data[____BAH_COMPILER_VAR_1140] = efn;
};

#line 2663 "/home/alois/Documents/bah-bah/src/parser.bah"
char ____BAH_COMPILER_VAR_1142(array(char *)* arr, char * el) {
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
if ((strcmp(ft.cont, "\010\0\0\0""#warning") == 0)) {

#line 2668 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((len(l)!=2), 0)) {

#line 2669 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&ft,"\056\0\0\0""Invalid usage of {TOKEN} '#warning \"message\"'.");
}

#line 2671 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok mt = l->data[1];

#line 2672 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((mt.type!=TOKEN_TYPE_STR), 0)) {

#line 2673 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&mt,"\037\0\0\0""Cannot use {TOKEN} as a string.");
}

#line 2676 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string msg = string(mt.cont);

#line 2677 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimLeft(&msg,1);

#line 2678 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimRight(&msg,1);

#line 2681 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ____BAH_COMPILER_VAR_1141 =string__str(&msg);throwWarning(____BAH_COMPILER_VAR_1141);

#line 2682 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}

#line 2686 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(ft.cont, "\05\0\0\0""#eval") == 0)) {

#line 2688 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((____BAH_COMPILER_VAR_1142(compilerState.includes, "\010\0\0\0""eval.bah")==false)) {

#line 2689 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((includeFile("\010\0\0\0""eval.bah",elems)==false), 0)) {

#line 2690 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1143 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1143[2] = "\02\0\0\0"").";____BAH_COMPILER_VAR_1143[1] = BAH_DIR;____BAH_COMPILER_VAR_1143[0] = "\072\0\0\0""Could not find file 'eval.bah'. Check your bah directory (";char * ____BAH_COMPILER_VAR_1144 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1143, 3);throwErr(&l->data[0],____BAH_COMPILER_VAR_1144);
}
}

#line 2694 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((len(l)!=2)||(isGlobal()==false), 0)) {

#line 2695 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&l->data[0],"\050\0\0\0""Invalid usage of {TOKEN} <#eval fnName>.");
}

#line 2698 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok fnT = l->data[1];

#line 2699 "/home/alois/Documents/bah-bah/src/parser.bah"
struct func* fn = searchFunc(fnT.cont,elems,false);

#line 2700 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((fn==null), 0)) {

#line 2701 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&fnT,"\031\0\0\0""Unknown function {TOKEN}.");
}

#line 2703 "/home/alois/Documents/bah-bah/src/parser.bah"
fn->used = true;

#line 2705 "/home/alois/Documents/bah-bah/src/parser.bah"
makeEvalFunc(fn,elems);

#line 2707 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}

#line 2710 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(ft.cont, "\010\0\0\0""#evalAll") == 0)) {

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
if ((fn->isBinding==false)&&(strHasPrefix(fn->name,"\013\0\0\0""__Bah_eval_")==false)) {

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
throwErr(&ft,"\041\0\0\0""Invalid usage of keyword {TOKEN}.");
}

#line 2725 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(ft.cont, "\06\0\0\0""#linux") == 0)||(strcmp(ft.cont, "\010\0\0\0""#windows") == 0)||(strcmp(ft.cont, "\07\0\0\0""#darwin") == 0)) {

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
else if ((strcmp(ft.cont, "\07\0\0\0""#static") == 0)) {

#line 2732 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((flags__isSet(&flags,"\01\0\0\0""d")==1)) {

#line 2733 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}
}

#line 2735 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "\010\0\0\0""#dynamic") == 0)) {

#line 2736 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((flags__isSet(&flags,"\01\0\0\0""d")==0)) {

#line 2737 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}
}

#line 2739 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "\03\0\0\0""#gc") == 0)) {

#line 2740 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((RCPavailable()==true)) {

#line 2741 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}
}

#line 2743 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "\04\0\0\0""#rcp") == 0)) {

#line 2744 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((RCPavailable()==false)) {

#line 2745 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}
}

#line 2747 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "\04\0\0\0""#lib") == 0)) {

#line 2748 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((flags__isSet(&flags,"\01\0\0\0""l")==0)) {

#line 2749 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}
}

#line 2751 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "\05\0\0\0""#exec") == 0)) {

#line 2752 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((flags__isSet(&flags,"\01\0\0\0""l")==1)) {

#line 2753 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}
}

#line 2755 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "\011\0\0\0""#imported") == 0)) {

#line 2756 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((isSubObject==false)||(isObject==false)) {

#line 2757 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}
}

#line 2759 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "\011\0\0\0""#included") == 0)) {

#line 2760 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((isSubObject==true)||(isObject==true)) {

#line 2761 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}
}

#line 2763 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "\012\0\0\0""#optimized") == 0)) {

#line 2764 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((isOptimized==false)) {

#line 2765 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}
}

#line 2767 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(ft.cont, "\014\0\0\0""#unoptimized") == 0)) {

#line 2768 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((isOptimized==true)) {

#line 2769 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}
}

#line 2771 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 2772 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&ft,"\030\0\0\0""Undefined token {TOKEN}.");
}

#line 2775 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok st = l->data[1];

#line 2776 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok lt = l->data[len(l)-1];

#line 2777 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((strcmp(st.cont, "\01\0\0\0""{") != 0)||(strcmp(lt.cont, "\01\0\0\0""}") != 0), 0)) {

#line 2778 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&st,"\052\0\0\0""Expected code block after keyword {TOKEN}.");
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

    unsigned int ____BAH_COMPILER_VAR_1145 = i-2;
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_1145);
    nl->data[____BAH_COMPILER_VAR_1145] = l->data[i];

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
throwErr(&ft,"\106\0\0\0""Cannot use keyword {TOKEN} on a function call 'async <function call>'.");
}

#line 2796 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok fnT = l->data[1];

#line 2797 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((fnT.isFunc==false), 0)) {

#line 2798 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&fnT,"\104\0\0\0""Cannot use keyword async on {TOKEN}. Usage: 'async <function call>'.");
}

#line 2801 "/home/alois/Documents/bah-bah/src/parser.bah"
char found = false;

#line 2802 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int i = 0;

#line 2802 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i<len(compilerState.cLibs))) {

#line 2803 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(compilerState.cLibs->data[i], "\010\0\0\0""lpthread") == 0)) {

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

    unsigned int ____BAH_COMPILER_VAR_1146 = len(compilerState.cLibs);
    __Bah_realocate_arr(compilerState.cLibs, ____BAH_COMPILER_VAR_1146);
    compilerState.cLibs->data[____BAH_COMPILER_VAR_1146] = "\010\0\0\0""lpthread";
}

#line 2813 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string sFnT = string(fnT.cont);

#line 2815 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct string)* fnNameParts = splitString(sFnT,"\01\0\0\0""(");

#line 2816 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string fnName = fnNameParts->data[0];

#line 2818 "/home/alois/Documents/bah-bah/src/parser.bah"
struct func* fn = searchFuncByToken(&fnT,elems);

#line 2820 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((fn==null), 0)) {

#line 2821 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1147 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1147[2] = "\023\0\0\0""', arround {TOKEN}.";____BAH_COMPILER_VAR_1147[1] = string__str(&fnName);____BAH_COMPILER_VAR_1147[0] = "\101\0\0\0""Internal compiler error.\n Error parsing async call for function '";char * ____BAH_COMPILER_VAR_1148 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1147, 3);throwErr(&fnT,____BAH_COMPILER_VAR_1148);
}

#line 2823 "/home/alois/Documents/bah-bah/src/parser.bah"
fnName = string(fn->name);

#line 2824 "/home/alois/Documents/bah-bah/src/parser.bah"
char * sMembs = "\0\0\0\0""";

#line 2825 "/home/alois/Documents/bah-bah/src/parser.bah"
char * unSerMembs = "\0\0\0\0""";

#line 2827 "/home/alois/Documents/bah-bah/src/parser.bah"
i = 0;

#line 2827 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i<len(fn->args))) {

#line 2828 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* a = fn->args->data[i];

#line 2829 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string cType = getCType(a->type,elems);

#line 2830 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1149 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1149[4] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_1149[3] = a->name;____BAH_COMPILER_VAR_1149[2] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_1149[1] = string__str(&cType);____BAH_COMPILER_VAR_1149[0] = sMembs;char * ____BAH_COMPILER_VAR_1150 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1149, 5);sMembs = ____BAH_COMPILER_VAR_1150;

#line 2831 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1151 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1151[2] = a->name;____BAH_COMPILER_VAR_1151[1] = "\06\0\0\0""args->";____BAH_COMPILER_VAR_1151[0] = unSerMembs;char * ____BAH_COMPILER_VAR_1152 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1151, 3);unSerMembs = ____BAH_COMPILER_VAR_1152;

#line 2832 "/home/alois/Documents/bah-bah/src/parser.bah"
i = i+1;

#line 2833 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((i<len(fn->args))) {

#line 2834 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1153 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1153[1] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_1153[0] = unSerMembs;char * ____BAH_COMPILER_VAR_1154 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1153, 2);unSerMembs = ____BAH_COMPILER_VAR_1154;
}
};

#line 2838 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1155 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1155[2] = "\01\0\0\0""}";____BAH_COMPILER_VAR_1155[1] = sMembs;____BAH_COMPILER_VAR_1155[0] = "\011\0\0\0""struct {\n";char * ____BAH_COMPILER_VAR_1156 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1155, 3);char * tmpArgsStruct = ____BAH_COMPILER_VAR_1156;

#line 2839 "/home/alois/Documents/bah-bah/src/parser.bah"
char * fnWrapper = genCompilerVar();

#line 2840 "/home/alois/Documents/bah-bah/src/parser.bah"
char * tmpArgs = genCompilerVar();

#line 2842 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimLeft(&sFnT,fnName.length+1);

#line 2843 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimRight(&sFnT,1);

#line 2845 "/home/alois/Documents/bah-bah/src/parser.bah"
char * tCreate = "\0\0\0\0""";

#line 2846 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(BAH_OS, "\07\0\0\0""windows") == 0)) {

#line 2847 "/home/alois/Documents/bah-bah/src/parser.bah"
tCreate = "\016\0\0\0""pthread_create";
}

#line 2848 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 2849 "/home/alois/Documents/bah-bah/src/parser.bah"
if (RCPavailable()||(RAIIenabled==true)) {

#line 2850 "/home/alois/Documents/bah-bah/src/parser.bah"
tCreate = "\016\0\0\0""pthread_create";
}

#line 2851 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 2852 "/home/alois/Documents/bah-bah/src/parser.bah"
tCreate = "\021\0\0\0""GC_pthread_create";
}
}

#line 2856 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1157 = alloca(25 * sizeof(char*));____BAH_COMPILER_VAR_1157[24] = "\035\0\0\0"", tmpArgs);\n    }; \n    \n    ";____BAH_COMPILER_VAR_1157[23] = fnWrapper;____BAH_COMPILER_VAR_1157[22] = "\011\0\0\0""(&id, 0, ";____BAH_COMPILER_VAR_1157[21] = tCreate;____BAH_COMPILER_VAR_1157[20] = "\042\0\0\0""));\n        pthread_t id;\n        ";____BAH_COMPILER_VAR_1157[19] = tmpArgs;____BAH_COMPILER_VAR_1157[18] = "\011\0\0\0"", sizeof(";____BAH_COMPILER_VAR_1157[17] = tmpArgs;____BAH_COMPILER_VAR_1157[16] = "\035\0\0\0""));\n        memcpy(tmpArgs, &";____BAH_COMPILER_VAR_1157[15] = tmpArgs;____BAH_COMPILER_VAR_1157[14] = "\056\0\0\0""};\n        void* tmpArgs = memoryAlloc(sizeof(";____BAH_COMPILER_VAR_1157[13] = string__str(&sFnT);____BAH_COMPILER_VAR_1157[12] = "\04\0\0\0"" = {";____BAH_COMPILER_VAR_1157[11] = tmpArgs;____BAH_COMPILER_VAR_1157[10] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_1157[9] = tmpArgsStruct;____BAH_COMPILER_VAR_1157[8] = "\030\0\0\0"");\n    };\n    {\n        ";____BAH_COMPILER_VAR_1157[7] = unSerMembs;____BAH_COMPILER_VAR_1157[6] = "\01\0\0\0""(";____BAH_COMPILER_VAR_1157[5] = string__str(&fnName);____BAH_COMPILER_VAR_1157[4] = "\022\0\0\0""* args) {\n        ";____BAH_COMPILER_VAR_1157[3] = tmpArgsStruct;____BAH_COMPILER_VAR_1157[2] = "\01\0\0\0""(";____BAH_COMPILER_VAR_1157[1] = fnWrapper;____BAH_COMPILER_VAR_1157[0] = "\012\0\0\0""\n    void ";char * ____BAH_COMPILER_VAR_1158 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1157, 25);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1158));
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

    unsigned int ____BAH_COMPILER_VAR_1159 = len(compilerState.RCPvars);
    __Bah_realocate_arr(compilerState.RCPvars, ____BAH_COMPILER_VAR_1159);
    compilerState.RCPvars->data[____BAH_COMPILER_VAR_1159] = v;
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
if ((t.type==TOKEN_TYPE_SYNTAX)&&(strcmp(t.cont, "\02\0\0\0""->") == 0)||(strcmp(t.cont, "\02\0\0\0""<-") == 0)) {

#line 2898 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "\02\0\0\0""<-") == 0)) {

#line 2899 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 2900 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((i<len(l))) {

#line 2901 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok nt = l->data[i];

#line 2902 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((nt.type!=TOKEN_TYPE_VAR), 0)) {

#line 2903 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&nt,"\036\0\0\0""Cannot use {TOKEN} as channel.");
}

#line 2905 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ____BAH_COMPILER_VAR_1160 =getTypeFromToken(&nt,true,elems);struct string ntt = string(____BAH_COMPILER_VAR_1160);

#line 2906 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((string__hasPrefix(&ntt,"\05\0\0\0""chan:")==0), 0)) {

#line 2907 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1161 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1161[2] = "\015\0\0\0"") as channel.";____BAH_COMPILER_VAR_1161[1] = string__str(&ntt);____BAH_COMPILER_VAR_1161[0] = "\030\0\0\0""Cannot use var {TOKEN} (";char * ____BAH_COMPILER_VAR_1162 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1161, 3);throwErr(&nt,____BAH_COMPILER_VAR_1162);
}

#line 2909 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimLeft(&ntt,5);

#line 2911 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect(isGlobal(), 0)) {

#line 2912 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"\076\0\0\0""Cannot receive ({TOKEN}) from a channel outside of a function.");
}

#line 2915 "/home/alois/Documents/bah-bah/src/parser.bah"
char * tmpV = "\0\0\0\0""";

#line 2917 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ____BAH_COMPILER_VAR_1163 =string__str(&ntt);if (isRCPpointerType(____BAH_COMPILER_VAR_1163)) {

#line 2918 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ____BAH_COMPILER_VAR_1164 =string__str(&ntt);struct string ct = getCType(____BAH_COMPILER_VAR_1164,elems);

#line 2919 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1165 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_1165[6] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1165[5] = nt.cont;____BAH_COMPILER_VAR_1165[4] = "\012\0\0\0""->receive(";____BAH_COMPILER_VAR_1165[3] = nt.cont;____BAH_COMPILER_VAR_1165[2] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1165[1] = string__str(&ct);____BAH_COMPILER_VAR_1165[0] = "\01\0\0\0""(";char * ____BAH_COMPILER_VAR_1166 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1165, 7);t.cont = ____BAH_COMPILER_VAR_1166;
}

#line 2920 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 2921 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ____BAH_COMPILER_VAR_1167 =string__str(&ntt);struct string ct = getCType(____BAH_COMPILER_VAR_1167,elems);

#line 2922 "/home/alois/Documents/bah-bah/src/parser.bah"
if (RCPavailable()) {

#line 2923 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1168 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1168[1] = "\01\0\0\0""*";____BAH_COMPILER_VAR_1168[0] = string__str(&ntt);char * ____BAH_COMPILER_VAR_1169 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1168, 2);char** ____BAH_COMPILER_VAR_1170 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_1170[6] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1170[5] = nt.cont;____BAH_COMPILER_VAR_1170[4] = "\012\0\0\0""->receive(";____BAH_COMPILER_VAR_1170[3] = nt.cont;____BAH_COMPILER_VAR_1170[2] = "\02\0\0\0""*)";____BAH_COMPILER_VAR_1170[1] = string__str(&ct);____BAH_COMPILER_VAR_1170[0] = "\01\0\0\0""(";char * ____BAH_COMPILER_VAR_1171 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1170, 7);tmpV = registerRCPvar(____BAH_COMPILER_VAR_1169,____BAH_COMPILER_VAR_1171,elems);

#line 2924 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1172 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1172[1] = tmpV;____BAH_COMPILER_VAR_1172[0] = "\01\0\0\0""*";char * ____BAH_COMPILER_VAR_1173 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1172, 2);t.cont = ____BAH_COMPILER_VAR_1173;
}

#line 2925 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 2926 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1174 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_1174[6] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1174[5] = nt.cont;____BAH_COMPILER_VAR_1174[4] = "\012\0\0\0""->receive(";____BAH_COMPILER_VAR_1174[3] = nt.cont;____BAH_COMPILER_VAR_1174[2] = "\02\0\0\0""*)";____BAH_COMPILER_VAR_1174[1] = string__str(&ct);____BAH_COMPILER_VAR_1174[0] = "\02\0\0\0""*(";char * ____BAH_COMPILER_VAR_1175 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1174, 7);t.cont = ____BAH_COMPILER_VAR_1175;
}
}

#line 2929 "/home/alois/Documents/bah-bah/src/parser.bah"
t.type = TOKEN_TYPE_FUNC;

#line 2930 "/home/alois/Documents/bah-bah/src/parser.bah"
t.isFunc = true;

#line 2932 "/home/alois/Documents/bah-bah/src/parser.bah"
if (RCPavailable()) {

#line 2933 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ____BAH_COMPILER_VAR_1176 =string__str(&ntt);if (isRCPpointerType(____BAH_COMPILER_VAR_1176)) {

#line 2934 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ____BAH_COMPILER_VAR_1177 =string__str(&ntt);tmpV = registerRCPvar(____BAH_COMPILER_VAR_1177,t.cont,elems);

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
throwErr(&t,"\035\0\0\0""Cannot use {TOKEN} on nothing");
}
}

#line 2948 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 2949 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((i==0), 0)) {

#line 2950 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"\036\0\0\0""Cannot une {TOKEN} on nothing.");
}

#line 2952 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((i+1>=len(l)), 0)) {

#line 2953 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"\041\0\0\0""Cannot send ({TOKEN}) to nothing.");
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
throwErr(&pt,"\036\0\0\0""Cannot use {TOKEN} as channel.");
}

#line 2962 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ____BAH_COMPILER_VAR_1178 =getTypeFromToken(&pt,true,elems);struct string ptt = string(____BAH_COMPILER_VAR_1178);

#line 2963 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((string__hasPrefix(&ptt,"\05\0\0\0""chan:")==0), 0)) {

#line 2964 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1179 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1179[2] = "\015\0\0\0"") as channel.";____BAH_COMPILER_VAR_1179[1] = ntt;____BAH_COMPILER_VAR_1179[0] = "\030\0\0\0""Cannot use var {TOKEN} (";char * ____BAH_COMPILER_VAR_1180 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1179, 3);throwErr(&pt,____BAH_COMPILER_VAR_1180);
}

#line 2966 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimLeft(&ptt,5);

#line 2968 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect(isGlobal(), 0)) {

#line 2969 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"\071\0\0\0""Cannot send ({TOKEN}) to a channel outside of a function.");
}

#line 2972 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ____BAH_COMPILER_VAR_1181 =string__str(&ptt);if (__builtin_expect((compTypes(____BAH_COMPILER_VAR_1181,ntt)==false), 0)) {

#line 2973 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1182 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1182[4] = "\01\0\0\0"".";____BAH_COMPILER_VAR_1182[3] = string__str(&ptt);____BAH_COMPILER_VAR_1182[2] = "\025\0\0\0"") to channel of type ";____BAH_COMPILER_VAR_1182[1] = ntt;____BAH_COMPILER_VAR_1182[0] = "\025\0\0\0""Cannot send {TOKEN} (";char * ____BAH_COMPILER_VAR_1183 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1182, 5);throwErr(&nt,____BAH_COMPILER_VAR_1183);
}

#line 2976 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 2977 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ____BAH_COMPILER_VAR_1184 =string__str(&ptt);if (isRCPpointerType(____BAH_COMPILER_VAR_1184)) {

#line 2978 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1185 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_1185[5] = "\03\0\0\0"");\n";____BAH_COMPILER_VAR_1185[4] = nt.cont;____BAH_COMPILER_VAR_1185[3] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_1185[2] = pt.cont;____BAH_COMPILER_VAR_1185[1] = "\07\0\0\0""->send(";____BAH_COMPILER_VAR_1185[0] = pt.cont;char * ____BAH_COMPILER_VAR_1186 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1185, 6);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1186));
}

#line 2979 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 2980 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string ct = getCType(ntt,elems);

#line 2981 "/home/alois/Documents/bah-bah/src/parser.bah"
char * tmpV = genCompilerVar();

#line 2982 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1187 = alloca(15 * sizeof(char*));____BAH_COMPILER_VAR_1187[14] = "\04\0\0\0""));\n";____BAH_COMPILER_VAR_1187[13] = tmpV;____BAH_COMPILER_VAR_1187[12] = "\011\0\0\0"", sizeof(";____BAH_COMPILER_VAR_1187[11] = tmpV;____BAH_COMPILER_VAR_1187[10] = "\03\0\0\0"", &";____BAH_COMPILER_VAR_1187[9] = pt.cont;____BAH_COMPILER_VAR_1187[8] = "\012\0\0\0""->sendAny(";____BAH_COMPILER_VAR_1187[7] = pt.cont;____BAH_COMPILER_VAR_1187[6] = "\026\0\0\0"";\n                    ";____BAH_COMPILER_VAR_1187[5] = nt.cont;____BAH_COMPILER_VAR_1187[4] = "\03\0\0\0"" = ";____BAH_COMPILER_VAR_1187[3] = tmpV;____BAH_COMPILER_VAR_1187[2] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_1187[1] = string__str(&ct);____BAH_COMPILER_VAR_1187[0] = "\025\0\0\0""\n                    ";char * ____BAH_COMPILER_VAR_1188 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1187, 15);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1188));
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

    unsigned int ____BAH_COMPILER_VAR_1189 = len(nl);
    __Bah_realocate_arr(nl, ____BAH_COMPILER_VAR_1189);
    nl->data[____BAH_COMPILER_VAR_1189] = t;
};

#line 2993 "/home/alois/Documents/bah-bah/src/parser.bah"
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
char** ____BAH_COMPILER_VAR_1190 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1190[1] = t.ogCont;____BAH_COMPILER_VAR_1190[0] = fnt.ogCont;char * ____BAH_COMPILER_VAR_1191 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1190, 2);fnt.ogCont = ____BAH_COMPILER_VAR_1191;

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

    unsigned int ____BAH_COMPILER_VAR_1192 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1192);
    memory->data[____BAH_COMPILER_VAR_1192] = t;
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
char** ____BAH_COMPILER_VAR_1193 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1193[1] = t.cont;____BAH_COMPILER_VAR_1193[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1194 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1193, 2);fnt.cont = ____BAH_COMPILER_VAR_1194;
};

#line 73 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1195 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1195[1] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1195[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1196 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1195, 2);fnt.cont = ____BAH_COMPILER_VAR_1196;

#line 74 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1197 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1197);
    l->data[____BAH_COMPILER_VAR_1197] = fnt;

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
char** ____BAH_COMPILER_VAR_1198 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1198[1] = "\01\0\0\0""(";____BAH_COMPILER_VAR_1198[0] = fn->name;char * ____BAH_COMPILER_VAR_1199 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1198, 2);fnt.cont = ____BAH_COMPILER_VAR_1199;

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
char** ____BAH_COMPILER_VAR_1200 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1200[1] = "\01\0\0\0""(";____BAH_COMPILER_VAR_1200[0] = fn->name;char * ____BAH_COMPILER_VAR_1201 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1200, 2);fnt.ogCont = ____BAH_COMPILER_VAR_1201;

#line 100 "/home/alois/Documents/bah-bah/src/values.bah"
long int start = i;

#line 101 "/home/alois/Documents/bah-bah/src/values.bah"
for (; (i<len(l)); 
#line 101 "/home/alois/Documents/bah-bah/src/values.bah"
++i) {

#line 102 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok t = l->data[i];

#line 103 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1202 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1202[1] = t.ogCont;____BAH_COMPILER_VAR_1202[0] = fnt.ogCont;char * ____BAH_COMPILER_VAR_1203 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1202, 2);fnt.ogCont = ____BAH_COMPILER_VAR_1203;

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
char** ____BAH_COMPILER_VAR_1204 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1204[1] = t.cont;____BAH_COMPILER_VAR_1204[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1205 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1204, 2);fnt.cont = ____BAH_COMPILER_VAR_1205;
};

#line 126 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1206 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1206);
    l->data[____BAH_COMPILER_VAR_1206] = fnt;

#line 127 "/home/alois/Documents/bah-bah/src/values.bah"
return tokPos;
}

#line 130 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1207 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1207[4] = "\01\0\0\0""\"";____BAH_COMPILER_VAR_1207[3] = intToStr(fnt.line);____BAH_COMPILER_VAR_1207[2] = "\01\0\0\0"":";____BAH_COMPILER_VAR_1207[1] = compilerState.currentFile;____BAH_COMPILER_VAR_1207[0] = "\01\0\0\0""\"";char * ____BAH_COMPILER_VAR_1208 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1207, 5);char * currLine = ____BAH_COMPILER_VAR_1208;

#line 131 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(fn->name, "\05\0\0\0""panic") == 0)) {

#line 132 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok ____BAH_COMPILER_VAR_1209 = {};
____BAH_COMPILER_VAR_1209.cont = "\0\0\0\0""";
____BAH_COMPILER_VAR_1209.ogCont = "\0\0\0\0""";
____BAH_COMPILER_VAR_1209.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1209.line = 1;
____BAH_COMPILER_VAR_1209.begLine = 1;
____BAH_COMPILER_VAR_1209.bahType = "\0\0\0\0""";
____BAH_COMPILER_VAR_1209.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_1209.cont = "\01\0\0\0"",";
____BAH_COMPILER_VAR_1209.line = fnt.line;

    unsigned int ____BAH_COMPILER_VAR_1210 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1210);
    memory->data[____BAH_COMPILER_VAR_1210] = ____BAH_COMPILER_VAR_1209;

#line 137 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok ____BAH_COMPILER_VAR_1211 = {};
____BAH_COMPILER_VAR_1211.cont = "\0\0\0\0""";
____BAH_COMPILER_VAR_1211.ogCont = "\0\0\0\0""";
____BAH_COMPILER_VAR_1211.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1211.line = 1;
____BAH_COMPILER_VAR_1211.begLine = 1;
____BAH_COMPILER_VAR_1211.bahType = "\0\0\0\0""";
____BAH_COMPILER_VAR_1211.type = TOKEN_TYPE_STR;
____BAH_COMPILER_VAR_1211.cont = currLine;
____BAH_COMPILER_VAR_1211.line = fnt.line;

    unsigned int ____BAH_COMPILER_VAR_1212 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1212);
    memory->data[____BAH_COMPILER_VAR_1212] = ____BAH_COMPILER_VAR_1211;

#line 142 "/home/alois/Documents/bah-bah/src/values.bah"
fn = searchFunc("\013\0\0\0""__BAH_panic",elems,true);

#line 143 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1213 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1213[1] = "\01\0\0\0""(";____BAH_COMPILER_VAR_1213[0] = fn->name;char * ____BAH_COMPILER_VAR_1214 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1213, 2);fnt.cont = ____BAH_COMPILER_VAR_1214;
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

    unsigned int ____BAH_COMPILER_VAR_1215 = len(symbols);
    __Bah_realocate_arr(symbols, ____BAH_COMPILER_VAR_1215);
    symbols->data[____BAH_COMPILER_VAR_1215] = v;
}
};

#line 152 "/home/alois/Documents/bah-bah/src/values.bah"
struct variable* ____BAH_COMPILER_VAR_1216 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1216->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_1216->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_1216->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_1216->from = "\0\0\0\0""";
____BAH_COMPILER_VAR_1216->name = genCompilerVar();
____BAH_COMPILER_VAR_1216->type = "\020\0\0\0""[]reflectElement";
____BAH_COMPILER_VAR_1216->isArray = true;
struct variable* tmpV = ____BAH_COMPILER_VAR_1216;

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
char** ____BAH_COMPILER_VAR_1217 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1217[1] = v->name;____BAH_COMPILER_VAR_1217[0] = "\01\0\0\0""&";char * ____BAH_COMPILER_VAR_1218 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1217, 2);vname = ____BAH_COMPILER_VAR_1218;
}

#line 164 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok ____BAH_COMPILER_VAR_1219 = {};
____BAH_COMPILER_VAR_1219.cont = "\0\0\0\0""";
____BAH_COMPILER_VAR_1219.ogCont = "\0\0\0\0""";
____BAH_COMPILER_VAR_1219.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1219.line = 1;
____BAH_COMPILER_VAR_1219.begLine = 1;
____BAH_COMPILER_VAR_1219.bahType = "\0\0\0\0""";
____BAH_COMPILER_VAR_1219.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_1219.cont = vname;
____BAH_COMPILER_VAR_1219.bahType = v->type;
____BAH_COMPILER_VAR_1219.isValue = true;
struct Tok tmpT = ____BAH_COMPILER_VAR_1219;

#line 170 "/home/alois/Documents/bah-bah/src/values.bah"
tmpT = parseReflect(tmpT,v->type,elems,true,v->name,"\01\0\0\0""0");

#line 171 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1220 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_1220[5] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_1220[4] = tmpT.cont;____BAH_COMPILER_VAR_1220[3] = "\04\0\0\0""] = ";____BAH_COMPILER_VAR_1220[2] = intToStr(j);____BAH_COMPILER_VAR_1220[1] = "\07\0\0\0""->data[";____BAH_COMPILER_VAR_1220[0] = tmpV->name;char * ____BAH_COMPILER_VAR_1221 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1220, 6);char** ____BAH_COMPILER_VAR_1222 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1222[1] = ____BAH_COMPILER_VAR_1221;____BAH_COMPILER_VAR_1222[0] = decls;char * ____BAH_COMPILER_VAR_1223 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1222, 2);decls = ____BAH_COMPILER_VAR_1223;
};

#line 173 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1224 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_1224);
    elems->vars->data[____BAH_COMPILER_VAR_1224] = tmpV;

#line 174 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1225 = alloca(15 * sizeof(char*));____BAH_COMPILER_VAR_1225[14] = "\011\0\0\0""\n        ";____BAH_COMPILER_VAR_1225[13] = decls;____BAH_COMPILER_VAR_1225[12] = "\064\0\0\0""->elemSize = sizeof(struct reflectElement);\n        ";____BAH_COMPILER_VAR_1225[11] = tmpV->name;____BAH_COMPILER_VAR_1225[10] = "\012\0\0\0"";\n        ";____BAH_COMPILER_VAR_1225[9] = intToStr(len(symbols));____BAH_COMPILER_VAR_1225[8] = "\013\0\0\0""->length = ";____BAH_COMPILER_VAR_1225[7] = tmpV->name;____BAH_COMPILER_VAR_1225[6] = "\013\0\0\0"");\n        ";____BAH_COMPILER_VAR_1225[5] = intToStr(len(symbols));____BAH_COMPILER_VAR_1225[4] = "\065\0\0\0""->data = memoryAlloc(sizeof(struct reflectElement) * ";____BAH_COMPILER_VAR_1225[3] = tmpV->name;____BAH_COMPILER_VAR_1225[2] = "\076\0\0\0"" = memoryAlloc(sizeof(array(struct reflectElement)));\n        ";____BAH_COMPILER_VAR_1225[1] = tmpV->name;____BAH_COMPILER_VAR_1225[0] = "\047\0\0\0""\n        array(struct reflectElement)* ";char * ____BAH_COMPILER_VAR_1226 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1225, 15);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1226));

#line 181 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok ____BAH_COMPILER_VAR_1227 = {};
____BAH_COMPILER_VAR_1227.cont = "\0\0\0\0""";
____BAH_COMPILER_VAR_1227.ogCont = "\0\0\0\0""";
____BAH_COMPILER_VAR_1227.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1227.line = 1;
____BAH_COMPILER_VAR_1227.begLine = 1;
____BAH_COMPILER_VAR_1227.bahType = "\0\0\0\0""";
____BAH_COMPILER_VAR_1227.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_1227.cont = tmpV->name;
____BAH_COMPILER_VAR_1227.line = fnt.line;
____BAH_COMPILER_VAR_1227.isValue = true;

    unsigned int ____BAH_COMPILER_VAR_1228 = 0;
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1228);
    memory->data[____BAH_COMPILER_VAR_1228] = ____BAH_COMPILER_VAR_1227;
}

#line 187 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((strcmp(fn->name, "\012\0\0\0""breakPoint") == 0)) {

#line 188 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok ____BAH_COMPILER_VAR_1229 = {};
____BAH_COMPILER_VAR_1229.cont = "\0\0\0\0""";
____BAH_COMPILER_VAR_1229.ogCont = "\0\0\0\0""";
____BAH_COMPILER_VAR_1229.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1229.line = 1;
____BAH_COMPILER_VAR_1229.begLine = 1;
____BAH_COMPILER_VAR_1229.bahType = "\0\0\0\0""";
____BAH_COMPILER_VAR_1229.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_1229.cont = "\015\0\0\0""__dumpSymbols";
____BAH_COMPILER_VAR_1229.line = fnt.line;
struct Tok ____BAH_COMPILER_VAR_1230 = {};
____BAH_COMPILER_VAR_1230.cont = "\0\0\0\0""";
____BAH_COMPILER_VAR_1230.ogCont = "\0\0\0\0""";
____BAH_COMPILER_VAR_1230.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1230.line = 1;
____BAH_COMPILER_VAR_1230.begLine = 1;
____BAH_COMPILER_VAR_1230.bahType = "\0\0\0\0""";
____BAH_COMPILER_VAR_1230.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_1230.cont = "\01\0\0\0""(";
____BAH_COMPILER_VAR_1230.line = fnt.line;
struct Tok ____BAH_COMPILER_VAR_1231 = {};
____BAH_COMPILER_VAR_1231.cont = "\0\0\0\0""";
____BAH_COMPILER_VAR_1231.ogCont = "\0\0\0\0""";
____BAH_COMPILER_VAR_1231.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1231.line = 1;
____BAH_COMPILER_VAR_1231.begLine = 1;
____BAH_COMPILER_VAR_1231.bahType = "\0\0\0\0""";
____BAH_COMPILER_VAR_1231.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_1231.cont = "\01\0\0\0"")";
____BAH_COMPILER_VAR_1231.line = fnt.line;
memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 3;
memory->elemSize = sizeof(struct Tok);
memory->data = memoryAlloc(sizeof(struct Tok) * 50);
                    memory->realLength = 50;
memory->data[0] = ____BAH_COMPILER_VAR_1229;
memory->data[1] = ____BAH_COMPILER_VAR_1230;
memory->data[2] = ____BAH_COMPILER_VAR_1231;

#line 205 "/home/alois/Documents/bah-bah/src/values.bah"
memory = prePross(memory,LINE_TYPE_FN_CALL,elems);

#line 206 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok ____BAH_COMPILER_VAR_1232 = {};
____BAH_COMPILER_VAR_1232.cont = "\0\0\0\0""";
____BAH_COMPILER_VAR_1232.ogCont = "\0\0\0\0""";
____BAH_COMPILER_VAR_1232.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1232.line = 1;
____BAH_COMPILER_VAR_1232.begLine = 1;
____BAH_COMPILER_VAR_1232.bahType = "\0\0\0\0""";
____BAH_COMPILER_VAR_1232.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_1232.cont = "\01\0\0\0"",";
____BAH_COMPILER_VAR_1232.line = fnt.line;

    unsigned int ____BAH_COMPILER_VAR_1233 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1233);
    memory->data[____BAH_COMPILER_VAR_1233] = ____BAH_COMPILER_VAR_1232;

#line 211 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok ____BAH_COMPILER_VAR_1234 = {};
____BAH_COMPILER_VAR_1234.cont = "\0\0\0\0""";
____BAH_COMPILER_VAR_1234.ogCont = "\0\0\0\0""";
____BAH_COMPILER_VAR_1234.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1234.line = 1;
____BAH_COMPILER_VAR_1234.begLine = 1;
____BAH_COMPILER_VAR_1234.bahType = "\0\0\0\0""";
____BAH_COMPILER_VAR_1234.type = TOKEN_TYPE_STR;
____BAH_COMPILER_VAR_1234.cont = currLine;
____BAH_COMPILER_VAR_1234.line = fnt.line;

    unsigned int ____BAH_COMPILER_VAR_1235 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1235);
    memory->data[____BAH_COMPILER_VAR_1235] = ____BAH_COMPILER_VAR_1234;

#line 216 "/home/alois/Documents/bah-bah/src/values.bah"
fn = searchFunc("\021\0\0\0""breakPoint__inner",elems,true);

#line 217 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1236 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1236[1] = "\01\0\0\0""(";____BAH_COMPILER_VAR_1236[0] = fn->name;char * ____BAH_COMPILER_VAR_1237 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1236, 2);fnt.cont = ____BAH_COMPILER_VAR_1237;
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
char** ____BAH_COMPILER_VAR_1238 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1238[1] = tmpT.cont;____BAH_COMPILER_VAR_1238[0] = tp;char * ____BAH_COMPILER_VAR_1239 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1238, 2);tp = ____BAH_COMPILER_VAR_1239;
};

#line 224 "/home/alois/Documents/bah-bah/src/values.bah"
struct variable* tmpV = searchVar(tp,elems);

#line 225 "/home/alois/Documents/bah-bah/src/values.bah"
if ((tmpV!=null)) {

#line 226 "/home/alois/Documents/bah-bah/src/values.bah"
struct string cType = getCType(tmpV->type,elems);

#line 227 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1240 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1240[1] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1240[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_1241 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1240, 2);char** ____BAH_COMPILER_VAR_1242 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1242[1] = ____BAH_COMPILER_VAR_1241;____BAH_COMPILER_VAR_1242[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1243 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1242, 2);fnt.cont = ____BAH_COMPILER_VAR_1243;
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
char** ____BAH_COMPILER_VAR_1244 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1244[1] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1244[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_1245 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1244, 2);char** ____BAH_COMPILER_VAR_1246 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1246[1] = ____BAH_COMPILER_VAR_1245;____BAH_COMPILER_VAR_1246[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1247 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1246, 2);fnt.cont = ____BAH_COMPILER_VAR_1247;
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

    unsigned int ____BAH_COMPILER_VAR_1248 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1248);
    l->data[____BAH_COMPILER_VAR_1248] = fnt;

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
char** ____BAH_COMPILER_VAR_1249 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1249[1] = parent->name;____BAH_COMPILER_VAR_1249[0] = amp;char * ____BAH_COMPILER_VAR_1250 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1249, 2);char** ____BAH_COMPILER_VAR_1251 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1251[1] = ____BAH_COMPILER_VAR_1250;____BAH_COMPILER_VAR_1251[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1252 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1251, 2);fnt.cont = ____BAH_COMPILER_VAR_1252;

#line 256 "/home/alois/Documents/bah-bah/src/values.bah"
++argIndex;

#line 257 "/home/alois/Documents/bah-bah/src/values.bah"
if ((len(fn->args)>argIndex)) {

#line 258 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1253 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1253[1] = "\01\0\0\0"",";____BAH_COMPILER_VAR_1253[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1254 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1253, 2);fnt.cont = ____BAH_COMPILER_VAR_1254;
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
char** ____BAH_COMPILER_VAR_1255 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1255[1] = getFuncDef(fn);____BAH_COMPILER_VAR_1255[0] = "\056\0\0\0""Too many arguments, expected ')' not {TOKEN}.\n";char * ____BAH_COMPILER_VAR_1256 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1255, 2);throwErr(&t,____BAH_COMPILER_VAR_1256);
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
char** ____BAH_COMPILER_VAR_1257 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1257[1] = string__str(&tts);____BAH_COMPILER_VAR_1257[0] = "\02\0\0\0""__";char * ____BAH_COMPILER_VAR_1258 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1257, 2);char** ____BAH_COMPILER_VAR_1259 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1259[1] = ____BAH_COMPILER_VAR_1258;____BAH_COMPILER_VAR_1259[0] = fn->name;char * ____BAH_COMPILER_VAR_1260 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1259, 2);fn->name = ____BAH_COMPILER_VAR_1260;
}

#line 292 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 293 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((compTypes(arg->type,tt)==false), 0)) {

#line 294 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1261 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_1261[5] = getFuncDef(fn);____BAH_COMPILER_VAR_1261[4] = "\023\0\0\0"" in function call.\n";____BAH_COMPILER_VAR_1261[3] = arg->type;____BAH_COMPILER_VAR_1261[2] = "\05\0\0\0"") as ";____BAH_COMPILER_VAR_1261[1] = tt;____BAH_COMPILER_VAR_1261[0] = "\024\0\0\0""Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_1262 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1261, 6);throwErr(&t,____BAH_COMPILER_VAR_1262);
}
}

#line 298 "/home/alois/Documents/bah-bah/src/values.bah"

                struct string ____BAH_COMPILER_VAR_1263 = string(tt);
                if (string__hasPrefix(&____BAH_COMPILER_VAR_1263,"\07\0\0\0""buffer:")&&(fn->isCbinding==false)&&(strcmp(arg->type, "\010\0\0\0""cpstring") == 0)) {

#line 299 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1264 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1264[2] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1264[1] = t.cont;____BAH_COMPILER_VAR_1264[0] = "\012\0\0\0""buffToStr(";char * ____BAH_COMPILER_VAR_1265 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1264, 3);t.cont = ____BAH_COMPILER_VAR_1265;
}

#line 302 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(tt, "\010\0\0\0""cpstring") == 0)&&fn->isCbinding&&(strcmp(fn->name, "\06\0\0\0""strlen") != 0)) {

#line 303 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1266 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1266[2] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1266[1] = t.cont;____BAH_COMPILER_VAR_1266[0] = "\05\0\0\0""cStr(";char * ____BAH_COMPILER_VAR_1267 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1266, 3);t.cont = ____BAH_COMPILER_VAR_1267;
}

#line 306 "/home/alois/Documents/bah-bah/src/values.bah"
checkCanBeNull(&t,tt,elems);

#line 308 "/home/alois/Documents/bah-bah/src/values.bah"
if ((RCPavailable()==true)&&(ltp==LINE_TYPE_VAR)&&(t.type==TOKEN_TYPE_VAR)&&(t.isOper==false)&&(currSetVar!=null)&&(strcmp(t.cont, currSetVar->name) == 0)&&isRCPtype(currSetVar->type,elems)) {

#line 309 "/home/alois/Documents/bah-bah/src/values.bah"
OUTPUT = rope__add(OUTPUT, incrVar(currSetVar,elems));
}

#line 312 "/home/alois/Documents/bah-bah/src/values.bah"
if ((t.type==TOKEN_TYPE_FUNC)) {

#line 313 "/home/alois/Documents/bah-bah/src/values.bah"
struct func* afn = searchFuncByToken(&t,elems);

#line 314 "/home/alois/Documents/bah-bah/src/values.bah"
if ((afn!=null)&&(isRCPtype(afn->returns->type,elems)==true)) {

#line 315 "/home/alois/Documents/bah-bah/src/values.bah"
t.cont = registerRCPvar(afn->returns->type,t.cont,elems);
}
}

#line 319 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1268 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1268[1] = t.cont;____BAH_COMPILER_VAR_1268[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1269 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1268, 2);fnt.cont = ____BAH_COMPILER_VAR_1269;

#line 321 "/home/alois/Documents/bah-bah/src/values.bah"
++argIndex;

#line 323 "/home/alois/Documents/bah-bah/src/values.bah"
if ((j+1<len(memory))) {

#line 324 "/home/alois/Documents/bah-bah/src/values.bah"
++j;

#line 325 "/home/alois/Documents/bah-bah/src/values.bah"
t = memory->data[j];

#line 326 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((strcmp(t.cont, "\01\0\0\0"",") != 0), 0)) {

#line 327 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1270 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1270[1] = getFuncDef(fn);____BAH_COMPILER_VAR_1270[0] = "\057\0\0\0""Need separator between arguments, not {TOKEN}.\n";char * ____BAH_COMPILER_VAR_1271 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1270, 2);throwErr(&t,____BAH_COMPILER_VAR_1271);
}

#line 329 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((j+1>=len(memory)), 0)) {

#line 330 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1272 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1272[1] = getFuncDef(fn);____BAH_COMPILER_VAR_1272[0] = "\051\0\0\0""Trailing {TOKEN} with no argument after.\n";char * ____BAH_COMPILER_VAR_1273 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1272, 2);throwErr(&t,____BAH_COMPILER_VAR_1273);
}

#line 332 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1274 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1274[1] = "\01\0\0\0"",";____BAH_COMPILER_VAR_1274[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1275 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1274, 2);fnt.cont = ____BAH_COMPILER_VAR_1275;
}
};

#line 337 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((argIndex!=len(fn->args)), 0)) {

#line 338 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1276 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1276[3] = getFuncDef(fn);____BAH_COMPILER_VAR_1276[2] = "\03\0\0\0""'.\n";____BAH_COMPILER_VAR_1276[1] = fn->name;____BAH_COMPILER_VAR_1276[0] = "\046\0\0\0""Not enough argument {TOKEN}, calling '";char * ____BAH_COMPILER_VAR_1277 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1276, 4);throwErr(&fnt,____BAH_COMPILER_VAR_1277);
}

#line 341 "/home/alois/Documents/bah-bah/src/values.bah"
if ((generic!=null)) {

#line 342 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1278 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1278[3] = cpstringSubsitute(fnt.cont, ogFntContL, strlen(fnt.cont));____BAH_COMPILER_VAR_1278[2] = "\01\0\0\0""(";____BAH_COMPILER_VAR_1278[1] = fn->name;____BAH_COMPILER_VAR_1278[0] = "\012\0\0\0""__generic_";char * ____BAH_COMPILER_VAR_1279 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1278, 4);fnt.cont = ____BAH_COMPILER_VAR_1279;

#line 343 "/home/alois/Documents/bah-bah/src/values.bah"
if ((genericFunc__isAlreadyDecl(generic,fn->name)==false)) {

#line 344 "/home/alois/Documents/bah-bah/src/values.bah"
genericFunc__declare(generic,fn,elems);
}
}

#line 349 "/home/alois/Documents/bah-bah/src/values.bah"
fnt.bahRef = fn;

#line 350 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1280 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1280[1] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1280[0] = fnt.cont;char * ____BAH_COMPILER_VAR_1281 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1280, 2);fnt.cont = ____BAH_COMPILER_VAR_1281;

#line 351 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(fn->name, "\06\0\0\0""strlen") == 0)&&(strcmp(ltt, "\010\0\0\0""cpstring") != 0)) {

#line 352 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1282 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1282[1] = fnt.cont;____BAH_COMPILER_VAR_1282[0] = "\01\0\0\0""C";char * ____BAH_COMPILER_VAR_1283 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1282, 2);fnt.cont = ____BAH_COMPILER_VAR_1283;
}

#line 353 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((strcmp(fn->name, "\03\0\0\0""len") == 0)&&(strcmp(ltt, "\010\0\0\0""cpstring") == 0)) {

#line 354 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1284 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1284[1] = fnt.cont;____BAH_COMPILER_VAR_1284[0] = "\03\0\0\0""str";char * ____BAH_COMPILER_VAR_1285 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1284, 2);fnt.cont = ____BAH_COMPILER_VAR_1285;
}

#line 355 "/home/alois/Documents/bah-bah/src/values.bah"
else if (fn->isCbinding&&(strcmp(fn->returns->type, "\010\0\0\0""cpstring") == 0)) {

#line 356 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1286 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1286[2] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1286[1] = fnt.cont;____BAH_COMPILER_VAR_1286[0] = "\012\0\0\0""cStrToBah(";char * ____BAH_COMPILER_VAR_1287 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1286, 3);fnt.cont = ____BAH_COMPILER_VAR_1287;
}

#line 359 "/home/alois/Documents/bah-bah/src/values.bah"
if ((noticeEnabled==true)&&(strcmp(ltt, "\010\0\0\0""cpstring") == 0)&&(strcmp(fn->name, "\06\0\0\0""strlen") == 0)) {

#line 360 "/home/alois/Documents/bah-bah/src/values.bah"
throwNoticeLine("\117\0\0\0""Function strlen() can be used for char*. Use len() for better code readability.",l->data[tokPos].line);
}

#line 362 "/home/alois/Documents/bah-bah/src/values.bah"

                struct string ____BAH_COMPILER_VAR_1288 = string(ltt);
                if (__builtin_expect((isUnsafe==false)&&(strcmp(fn->name, "\03\0\0\0""len") == 0)&&(strcmp(ltt, "\010\0\0\0""cpstring") != 0)&&(string__hasPrefix(&____BAH_COMPILER_VAR_1288,"\02\0\0\0""[]")==false), 0)) {

#line 363 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1289 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1289[2] = "\027\0\0\0"") as cpstring or array.";____BAH_COMPILER_VAR_1289[1] = ltt;____BAH_COMPILER_VAR_1289[0] = "\031\0\0\0""Cannot use len({TOKEN}) (";char * ____BAH_COMPILER_VAR_1290 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1289, 3);throwErr(&memory->data[0],____BAH_COMPILER_VAR_1290);
}

#line 366 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1291 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1291);
    l->data[____BAH_COMPILER_VAR_1291] = fnt;

#line 367 "/home/alois/Documents/bah-bah/src/values.bah"
return tokPos;
};

#line 371 "/home/alois/Documents/bah-bah/src/values.bah"
long int valueStruct(__BAH_ARR_TYPE_Tok l,long int i,lineType ltp,struct Elems* elems){

#line 372 "/home/alois/Documents/bah-bah/src/values.bah"
long int tokPos = i-1;

#line 376 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok t = l->data[i-1];

#line 377 "/home/alois/Documents/bah-bah/src/values.bah"
char * tt = getTypeFromToken(&t,true,elems);

#line 379 "/home/alois/Documents/bah-bah/src/values.bah"
struct cStruct* s = searchStruct(tt,elems);

#line 380 "/home/alois/Documents/bah-bah/src/values.bah"
if ((s==null)) {

#line 381 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((tt[strlen(tt)-1+4]==33), 0)) {

#line 382 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1292 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1292[2] = "\017\0\0\0"") as structure.";____BAH_COMPILER_VAR_1292[1] = tt;____BAH_COMPILER_VAR_1292[0] = "\040\0\0\0""Cannot use maybe value {TOKEN} (";char * ____BAH_COMPILER_VAR_1293 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1292, 3);throwErr(&t,____BAH_COMPILER_VAR_1293);
}

#line 383 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 384 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1294 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1294[2] = "\02\0\0\0"").";____BAH_COMPILER_VAR_1294[1] = tt;____BAH_COMPILER_VAR_1294[0] = "\027\0\0\0""Unkown struct {TOKEN} (";char * ____BAH_COMPILER_VAR_1295 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1294, 3);throwErr(&t,____BAH_COMPILER_VAR_1295);
}
}

#line 388 "/home/alois/Documents/bah-bah/src/values.bah"
checkCanBeNull(&t,tt,elems);

#line 391 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok nt = l->data[i+1];

#line 393 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((nt.isValue==false), 0)) {

#line 394 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&nt,"\035\0\0\0""Cannot use {TOKEN} as member.");
}

#line 396 "/home/alois/Documents/bah-bah/src/values.bah"
deleteRange(l,i,i+1);

#line 399 "/home/alois/Documents/bah-bah/src/values.bah"
char * sep = "\01\0\0\0"".";

#line 400 "/home/alois/Documents/bah-bah/src/values.bah"
if (isRCPpointerType(tt)) {

#line 401 "/home/alois/Documents/bah-bah/src/values.bah"
sep = "\02\0\0\0""->";
}

#line 405 "/home/alois/Documents/bah-bah/src/values.bah"
if ((t.type==TOKEN_TYPE_VAR)) {

#line 406 "/home/alois/Documents/bah-bah/src/values.bah"
fixMeTestVar(&t,ltp,elems);
}

#line 410 "/home/alois/Documents/bah-bah/src/values.bah"
if ((i<len(l))) {

#line 411 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok ntt = l->data[i];

#line 412 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(ntt.cont, "\01\0\0\0""(") == 0)) {

#line 413 "/home/alois/Documents/bah-bah/src/values.bah"
struct variable* parent= null;

#line 414 "/home/alois/Documents/bah-bah/src/values.bah"
if ((t.type==TOKEN_TYPE_VAR)) {

#line 415 "/home/alois/Documents/bah-bah/src/values.bah"
if ((t.bahRef!=null)) {

#line 417 "/home/alois/Documents/bah-bah/src/values.bah"
parent = t.bahRef;
}

#line 418 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 419 "/home/alois/Documents/bah-bah/src/values.bah"
parent = searchVar(t.cont,elems);
}
}

#line 421 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 422 "/home/alois/Documents/bah-bah/src/values.bah"
char * tmpV = genCompilerVar();

#line 423 "/home/alois/Documents/bah-bah/src/values.bah"
struct string cType = getCType(tt,elems);

#line 424 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1296 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_1296[6] = "\022\0\0\0"";\n                ";____BAH_COMPILER_VAR_1296[5] = t.cont;____BAH_COMPILER_VAR_1296[4] = "\03\0\0\0"" = ";____BAH_COMPILER_VAR_1296[3] = tmpV;____BAH_COMPILER_VAR_1296[2] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_1296[1] = string__str(&cType);____BAH_COMPILER_VAR_1296[0] = "\021\0\0\0""\n                ";char * ____BAH_COMPILER_VAR_1297 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1296, 7);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1297));

#line 427 "/home/alois/Documents/bah-bah/src/values.bah"
t.cont = tmpV;

#line 428 "/home/alois/Documents/bah-bah/src/values.bah"
struct variable* ____BAH_COMPILER_VAR_1298 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1298->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_1298->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_1298->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_1298->from = "\0\0\0\0""";
____BAH_COMPILER_VAR_1298->name = tmpV;
____BAH_COMPILER_VAR_1298->type = tt;
parent = ____BAH_COMPILER_VAR_1298;

#line 432 "/home/alois/Documents/bah-bah/src/values.bah"
if (RCPavailable()) {

#line 433 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1299 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_1299);
    elems->vars->data[____BAH_COMPILER_VAR_1299] = parent;
}
}

#line 436 "/home/alois/Documents/bah-bah/src/values.bah"
struct func* fn = searchStructMethod(nt.cont,s,elems);

#line 437 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((fn==null), 0)) {

#line 438 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1300 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1300[2] = "\01\0\0\0"".";____BAH_COMPILER_VAR_1300[1] = s->name;____BAH_COMPILER_VAR_1300[0] = "\041\0\0\0""Unknown method {TOKEN} in struct ";char * ____BAH_COMPILER_VAR_1301 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1300, 3);throwErr(&nt,____BAH_COMPILER_VAR_1301);
}

#line 440 "/home/alois/Documents/bah-bah/src/values.bah"
if ((t.type==TOKEN_TYPE_VAR)) {

#line 441 "/home/alois/Documents/bah-bah/src/values.bah"
if ((fn->isImported==true)||(fn->isMut==true)) {

#line 442 "/home/alois/Documents/bah-bah/src/values.bah"
struct variable* rp = searchVarByToken(&t,elems);

#line 443 "/home/alois/Documents/bah-bah/src/values.bah"
rp->lastSet = elems;

#line 444 "/home/alois/Documents/bah-bah/src/values.bah"
if ((rp->isArg==true)) {

#line 445 "/home/alois/Documents/bah-bah/src/values.bah"
currentFn->isMut = true;
}
}
}

#line 449 "/home/alois/Documents/bah-bah/src/values.bah"
if ((fn->isVar==true)) {

#line 450 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1302 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1302[2] = fn->name;____BAH_COMPILER_VAR_1302[1] = sep;____BAH_COMPILER_VAR_1302[0] = t.cont;char * ____BAH_COMPILER_VAR_1303 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1302, 3);fn->name = ____BAH_COMPILER_VAR_1303;
}

#line 452 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((parent==null), 0)) {

#line 453 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&t,"\041\0\0\0""Could not find structure {TOKEN}.");
}

#line 455 "/home/alois/Documents/bah-bah/src/values.bah"
valueFunc(fn,parent,l,i,ltp,elems);

#line 456 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok fnt = l->data[i];

#line 457 "/home/alois/Documents/bah-bah/src/values.bah"
delete(l,i);

#line 458 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1304 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1304[2] = nt.ogCont;____BAH_COMPILER_VAR_1304[1] = "\01\0\0\0"".";____BAH_COMPILER_VAR_1304[0] = t.ogCont;char * ____BAH_COMPILER_VAR_1305 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1304, 3);fnt.ogCont = ____BAH_COMPILER_VAR_1305;

#line 459 "/home/alois/Documents/bah-bah/src/values.bah"
fnt.pos = t.pos;

#line 462 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1306 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1306);
    l->data[____BAH_COMPILER_VAR_1306] = fnt;

#line 463 "/home/alois/Documents/bah-bah/src/values.bah"
return tokPos;
}
}

#line 468 "/home/alois/Documents/bah-bah/src/values.bah"
struct structMemb* m = searchStructMemb(nt.cont,s,elems);

#line 469 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((m==null), 0)) {

#line 470 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1307 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1307[2] = "\02\0\0\0""'.";____BAH_COMPILER_VAR_1307[1] = s->name;____BAH_COMPILER_VAR_1307[0] = "\051\0\0\0""Unknown struct member {TOKEN} in struct '";char * ____BAH_COMPILER_VAR_1308 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1307, 3);throwErr(&nt,____BAH_COMPILER_VAR_1308);
}

#line 472 "/home/alois/Documents/bah-bah/src/values.bah"
char * ast = "\0\0\0\0""";

#line 473 "/home/alois/Documents/bah-bah/src/values.bah"
if ((t.cont[0+4]==38)) {

#line 474 "/home/alois/Documents/bah-bah/src/values.bah"
ast = "\01\0\0\0""*";
}

#line 476 "/home/alois/Documents/bah-bah/src/values.bah"
if ((m->isFn==true)) {

#line 477 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1309 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1309[2] = m->name;____BAH_COMPILER_VAR_1309[1] = "\02\0\0\0""__";____BAH_COMPILER_VAR_1309[0] = s->name;char * ____BAH_COMPILER_VAR_1310 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1309, 3);t.cont = ____BAH_COMPILER_VAR_1310;
}

#line 478 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 479 "/home/alois/Documents/bah-bah/src/values.bah"
if ((t.type==TOKEN_TYPE_VAR)) {

#line 480 "/home/alois/Documents/bah-bah/src/values.bah"
t.parent = searchVarByToken(&t,elems);
}

#line 482 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1311 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1311[1] = nt.cont;____BAH_COMPILER_VAR_1311[0] = sep;char * ____BAH_COMPILER_VAR_1312 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1311, 2);char** ____BAH_COMPILER_VAR_1313 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1313[1] = ____BAH_COMPILER_VAR_1312;____BAH_COMPILER_VAR_1313[0] = t.cont;char * ____BAH_COMPILER_VAR_1314 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1313, 2);t.cont = ____BAH_COMPILER_VAR_1314;
}

#line 484 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1315 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1315[1] = nt.cont;____BAH_COMPILER_VAR_1315[0] = "\01\0\0\0"".";char * ____BAH_COMPILER_VAR_1316 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1315, 2);char** ____BAH_COMPILER_VAR_1317 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1317[1] = ____BAH_COMPILER_VAR_1316;____BAH_COMPILER_VAR_1317[0] = t.ogCont;char * ____BAH_COMPILER_VAR_1318 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1317, 2);t.ogCont = ____BAH_COMPILER_VAR_1318;

#line 485 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1319 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1319[1] = ast;____BAH_COMPILER_VAR_1319[0] = m->type;char * ____BAH_COMPILER_VAR_1320 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1319, 2);t.bahType = ____BAH_COMPILER_VAR_1320;

#line 486 "/home/alois/Documents/bah-bah/src/values.bah"
struct variable* ____BAH_COMPILER_VAR_1321 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1321->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_1321->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_1321->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_1321->from = "\0\0\0\0""";
____BAH_COMPILER_VAR_1321->name = t.cont;
____BAH_COMPILER_VAR_1321->type = t.bahType;
t.bahRef = ____BAH_COMPILER_VAR_1321;

#line 491 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1322 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1322);
    l->data[____BAH_COMPILER_VAR_1322] = t;

#line 492 "/home/alois/Documents/bah-bah/src/values.bah"
return tokPos;
};

#line 495 "/home/alois/Documents/bah-bah/src/values.bah"
long int valueArr(__BAH_ARR_TYPE_Tok l,long int i,lineType ltp,struct Elems* elems){

#line 496 "/home/alois/Documents/bah-bah/src/values.bah"
long int tokPos = i-1;

#line 498 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok pt = l->data[tokPos];

#line 499 "/home/alois/Documents/bah-bah/src/values.bah"
delete(l,tokPos);

#line 500 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((pt.isValue==false), 0)) {

#line 501 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&pt,"\044\0\0\0""Cannot use {TOKEN} as value (array).");
}

#line 503 "/home/alois/Documents/bah-bah/src/values.bah"
char * ____BAH_COMPILER_VAR_1323 =getTypeFromToken(&pt,true,elems);struct string ptt = string(____BAH_COMPILER_VAR_1323);

#line 506 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok t = pt;

#line 507 "/home/alois/Documents/bah-bah/src/values.bah"
t.isValue = true;

#line 508 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1324 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1324[1] = "\01\0\0\0""[";____BAH_COMPILER_VAR_1324[0] = t.ogCont;char * ____BAH_COMPILER_VAR_1325 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1324, 2);t.ogCont = ____BAH_COMPILER_VAR_1325;

#line 511 "/home/alois/Documents/bah-bah/src/values.bah"
long int nbEncls = 1;

#line 512 "/home/alois/Documents/bah-bah/src/values.bah"
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);

#line 513 "/home/alois/Documents/bah-bah/src/values.bah"
i = tokPos+1;

#line 514 "/home/alois/Documents/bah-bah/src/values.bah"
for (; (i<len(l)); 
#line 514 "/home/alois/Documents/bah-bah/src/values.bah"
++i) {

#line 515 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok tmpT = l->data[i];

#line 516 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(tmpT.cont, "\01\0\0\0""(") == 0)||(strcmp(tmpT.cont, "\01\0\0\0""{") == 0)||(strcmp(tmpT.cont, "\01\0\0\0""[") == 0)) {

#line 517 "/home/alois/Documents/bah-bah/src/values.bah"
++nbEncls;
}

#line 518 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((strcmp(tmpT.cont, "\01\0\0\0"")") == 0)||(strcmp(tmpT.cont, "\01\0\0\0""}") == 0)||(strcmp(tmpT.cont, "\01\0\0\0""]") == 0)) {

#line 519 "/home/alois/Documents/bah-bah/src/values.bah"
--nbEncls;

#line 520 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1326 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1326[1] = "\01\0\0\0""]";____BAH_COMPILER_VAR_1326[0] = t.ogCont;char * ____BAH_COMPILER_VAR_1327 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1326, 2);t.ogCont = ____BAH_COMPILER_VAR_1327;

#line 521 "/home/alois/Documents/bah-bah/src/values.bah"
if ((nbEncls==0)) {

#line 522 "/home/alois/Documents/bah-bah/src/values.bah"
break;
}
}

#line 525 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1328 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1328[1] = tmpT.ogCont;____BAH_COMPILER_VAR_1328[0] = t.ogCont;char * ____BAH_COMPILER_VAR_1329 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1328, 2);t.ogCont = ____BAH_COMPILER_VAR_1329;

#line 526 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1330 = len(memory);
    __Bah_realocate_arr(memory, ____BAH_COMPILER_VAR_1330);
    memory->data[____BAH_COMPILER_VAR_1330] = tmpT;
};

#line 528 "/home/alois/Documents/bah-bah/src/values.bah"
deleteRange(l,tokPos+1,i);

#line 529 "/home/alois/Documents/bah-bah/src/values.bah"
memory = prePross(memory,(lineType)-1,elems);

#line 532 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((len(memory)==0), 0)) {

#line 533 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&pt,"\053\0\0\0""Cannot access empty index of array {TOKEN}.");
}

#line 537 "/home/alois/Documents/bah-bah/src/values.bah"
char split = false;

#line 538 "/home/alois/Documents/bah-bah/src/values.bah"
char * from = "\0\0\0\0""";

#line 539 "/home/alois/Documents/bah-bah/src/values.bah"
char * to = "\0\0\0\0""";

#line 540 "/home/alois/Documents/bah-bah/src/values.bah"
if ((len(memory)>1)) {

#line 541 "/home/alois/Documents/bah-bah/src/values.bah"
split = true;

#line 542 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok first = memory->data[0];

#line 543 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok second;

#line 544 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok third;

#line 546 "/home/alois/Documents/bah-bah/src/values.bah"
if ((len(memory)==3)) {

#line 547 "/home/alois/Documents/bah-bah/src/values.bah"
second = memory->data[1];

#line 548 "/home/alois/Documents/bah-bah/src/values.bah"
third = memory->data[2];

#line 549 "/home/alois/Documents/bah-bah/src/values.bah"
char * firstT = getTypeFromToken(&first,true,elems);

#line 550 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((compTypes(firstT,"\03\0\0\0""int")==false), 0)) {

#line 551 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&first,"\032\0\0\0""Cannot use {TOKEN} as int.");
}

#line 553 "/home/alois/Documents/bah-bah/src/values.bah"
char * thirdT = getTypeFromToken(&third,true,elems);

#line 554 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((compTypes(thirdT,"\03\0\0\0""int")==false), 0)) {

#line 555 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&third,"\032\0\0\0""Cannot use {TOKEN} as int.");
}

#line 557 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((strcmp(second.cont, "\01\0\0\0"":") != 0), 0)) {

#line 558 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&second,"\031\0\0\0""Expected ':' not {TOKEN}.");
}

#line 560 "/home/alois/Documents/bah-bah/src/values.bah"
from = first.cont;

#line 561 "/home/alois/Documents/bah-bah/src/values.bah"
to = third.cont;
}

#line 562 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((len(memory)==2)) {

#line 563 "/home/alois/Documents/bah-bah/src/values.bah"
second = memory->data[1];

#line 565 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(first.cont, "\01\0\0\0"":") == 0)) {

#line 566 "/home/alois/Documents/bah-bah/src/values.bah"
from = "\01\0\0\0""0";

#line 567 "/home/alois/Documents/bah-bah/src/values.bah"
char * secondT = getTypeFromToken(&second,true,elems);

#line 568 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((compTypes(secondT,"\03\0\0\0""int")==false), 0)) {

#line 569 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&second,"\032\0\0\0""Cannot use {TOKEN} as int.");
}

#line 571 "/home/alois/Documents/bah-bah/src/values.bah"
to = second.cont;
}

#line 572 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((strcmp(second.cont, "\01\0\0\0"":") == 0)) {

#line 573 "/home/alois/Documents/bah-bah/src/values.bah"
char * firstT = getTypeFromToken(&first,true,elems);

#line 574 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((compTypes(firstT,"\03\0\0\0""int")==false), 0)) {

#line 575 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&first,"\032\0\0\0""Cannot use {TOKEN} as int.");
}

#line 577 "/home/alois/Documents/bah-bah/src/values.bah"
from = first.cont;
}

#line 578 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 579 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&second,"\030\0\0\0""Expected ':' not {TOKEN}");
}
}

#line 581 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 582 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&memory->data[3],"\104\0\0\0""Cannot substiture with more than 2 values, expected ']' not {TOKEN}.");
}
}

#line 586 "/home/alois/Documents/bah-bah/src/values.bah"
if (string__hasPrefix(&ptt,"\02\0\0\0""[]")) {

#line 587 "/home/alois/Documents/bah-bah/src/values.bah"
if ((split==false)) {

#line 588 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok index = memory->data[0];

#line 589 "/home/alois/Documents/bah-bah/src/values.bah"
char * ____BAH_COMPILER_VAR_1331 =getTypeFromToken(&index,true,elems);if (__builtin_expect((compTypes(____BAH_COMPILER_VAR_1331,"\03\0\0\0""int")==false), 0)) {

#line 590 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&index,"\050\0\0\0""Cannot use {TOKEN} as array index (int).");
}

#line 592 "/home/alois/Documents/bah-bah/src/values.bah"
string__trimLeft(&ptt,2);

#line 593 "/home/alois/Documents/bah-bah/src/values.bah"
t.bahType = string__str(&ptt);

#line 594 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1332 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1332[3] = "\01\0\0\0""]";____BAH_COMPILER_VAR_1332[2] = index.cont;____BAH_COMPILER_VAR_1332[1] = "\07\0\0\0""->data[";____BAH_COMPILER_VAR_1332[0] = pt.cont;char * ____BAH_COMPILER_VAR_1333 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1332, 4);t.cont = ____BAH_COMPILER_VAR_1333;

#line 596 "/home/alois/Documents/bah-bah/src/values.bah"
if ((tokPos+1<len(l))&&(strcmp(l->data[tokPos+1].cont, "\01\0\0\0"".") == 0)) {

#line 597 "/home/alois/Documents/bah-bah/src/values.bah"
struct variable* ____BAH_COMPILER_VAR_1334 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1334->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_1334->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_1334->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_1334->from = "\0\0\0\0""";
____BAH_COMPILER_VAR_1334->name = t.cont;
____BAH_COMPILER_VAR_1334->type = t.bahType;
struct variable* tmpV = ____BAH_COMPILER_VAR_1334;

#line 601 "/home/alois/Documents/bah-bah/src/values.bah"
t.bahRef = tmpV;
}
}

#line 604 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 605 "/home/alois/Documents/bah-bah/src/values.bah"
t.bahType = string__str(&ptt);

#line 606 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(to, "\0\0\0\0""") == 0)) {

#line 607 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1335 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1335[1] = "\010\0\0\0""->length";____BAH_COMPILER_VAR_1335[0] = pt.cont;char * ____BAH_COMPILER_VAR_1336 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1335, 2);to = ____BAH_COMPILER_VAR_1336;
}

#line 609 "/home/alois/Documents/bah-bah/src/values.bah"
t.isFunc = true;

#line 610 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1337 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_1337[6] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1337[5] = to;____BAH_COMPILER_VAR_1337[4] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_1337[3] = from;____BAH_COMPILER_VAR_1337[2] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_1337[1] = pt.cont;____BAH_COMPILER_VAR_1337[0] = "\020\0\0\0""arraySubstitute(";char * ____BAH_COMPILER_VAR_1338 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1337, 7);t.cont = ____BAH_COMPILER_VAR_1338;
}
}

#line 613 "/home/alois/Documents/bah-bah/src/values.bah"
else if (string__hasPrefix(&ptt,"\07\0\0\0""buffer:")) {

#line 614 "/home/alois/Documents/bah-bah/src/values.bah"
if ((split==false)) {

#line 615 "/home/alois/Documents/bah-bah/src/values.bah"
t.bahType = "\04\0\0\0""char";

#line 616 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok index = memory->data[0];

#line 617 "/home/alois/Documents/bah-bah/src/values.bah"
char * ____BAH_COMPILER_VAR_1339 =getTypeFromToken(&index,true,elems);if (__builtin_expect((compTypes(____BAH_COMPILER_VAR_1339,"\03\0\0\0""int")==false), 0)) {

#line 618 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&index,"\051\0\0\0""Cannot use {TOKEN} as buffer index (int).");
}

#line 620 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1340 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1340[3] = "\01\0\0\0""]";____BAH_COMPILER_VAR_1340[2] = index.cont;____BAH_COMPILER_VAR_1340[1] = "\01\0\0\0""[";____BAH_COMPILER_VAR_1340[0] = pt.cont;char * ____BAH_COMPILER_VAR_1341 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1340, 4);t.cont = ____BAH_COMPILER_VAR_1341;
}

#line 621 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 622 "/home/alois/Documents/bah-bah/src/values.bah"
t.bahType = "\010\0\0\0""cpstring";

#line 623 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(to, "\0\0\0\0""") == 0)) {

#line 624 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1342 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1342[2] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1342[1] = pt.cont;____BAH_COMPILER_VAR_1342[0] = "\07\0\0\0""strlen(";char * ____BAH_COMPILER_VAR_1343 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1342, 3);to = ____BAH_COMPILER_VAR_1343;
}

#line 626 "/home/alois/Documents/bah-bah/src/values.bah"
t.isFunc = true;

#line 627 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1344 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_1344[6] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1344[5] = to;____BAH_COMPILER_VAR_1344[4] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_1344[3] = from;____BAH_COMPILER_VAR_1344[2] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_1344[1] = pt.cont;____BAH_COMPILER_VAR_1344[0] = "\022\0\0\0""cpstringSubsitute(";char * ____BAH_COMPILER_VAR_1345 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1344, 7);t.cont = ____BAH_COMPILER_VAR_1345;
}
}

#line 629 "/home/alois/Documents/bah-bah/src/values.bah"
else if (string__hasPrefix(&ptt,"\04\0\0\0""map:")) {

#line 630 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((split==true), 0)) {

#line 631 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&pt,"\050\0\0\0""Cannot do substitution on a map {TOKEN}.");
}

#line 633 "/home/alois/Documents/bah-bah/src/values.bah"
string__trimLeft(&ptt,4);

#line 634 "/home/alois/Documents/bah-bah/src/values.bah"
char * ____BAH_COMPILER_VAR_1346 =string__str(&ptt);struct string elemType = getCType(____BAH_COMPILER_VAR_1346,elems);

#line 635 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok index = memory->data[0];

#line 636 "/home/alois/Documents/bah-bah/src/values.bah"
char * ____BAH_COMPILER_VAR_1347 =getTypeFromToken(&index,true,elems);if (__builtin_expect((compTypes(____BAH_COMPILER_VAR_1347,"\010\0\0\0""cpstring")==false), 0)) {

#line 637 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&index,"\053\0\0\0""Cannot use {TOKEN} as map index (cpstring).");
}

#line 639 "/home/alois/Documents/bah-bah/src/values.bah"
if ((tokPos==0)&&(ltp==LINE_TYPE_VAR)) {

#line 640 "/home/alois/Documents/bah-bah/src/values.bah"
struct variable* ____BAH_COMPILER_VAR_1348 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1348->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_1348->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_1348->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_1348->from = "\0\0\0\0""";
____BAH_COMPILER_VAR_1348->name = genCompilerVar();
____BAH_COMPILER_VAR_1348->type = string__str(&ptt);
struct variable* tmpV = ____BAH_COMPILER_VAR_1348;

#line 644 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1349 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_1349);
    elems->vars->data[____BAH_COMPILER_VAR_1349] = tmpV;

#line 645 "/home/alois/Documents/bah-bah/src/values.bah"
if (isGlobal()) {

#line 646 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1350 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1350[3] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_1350[2] = tmpV->name;____BAH_COMPILER_VAR_1350[1] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_1350[0] = string__str(&elemType);char * ____BAH_COMPILER_VAR_1351 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1350, 4);INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_1351));
}

#line 647 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 648 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1352 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1352[3] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_1352[2] = tmpV->name;____BAH_COMPILER_VAR_1352[1] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_1352[0] = string__str(&elemType);char * ____BAH_COMPILER_VAR_1353 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1352, 4);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1353));
}

#line 650 "/home/alois/Documents/bah-bah/src/values.bah"
char * ____BAH_COMPILER_VAR_1354 =string__str(&ptt);if (isRCPpointerType(____BAH_COMPILER_VAR_1354)) {

#line 651 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1355 = alloca(8 * sizeof(char*));____BAH_COMPILER_VAR_1355[7] = "\03\0\0\0"");\n";____BAH_COMPILER_VAR_1355[6] = tmpV->name;____BAH_COMPILER_VAR_1355[5] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_1355[4] = index.cont;____BAH_COMPILER_VAR_1355[3] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_1355[2] = pt.cont;____BAH_COMPILER_VAR_1355[1] = "\06\0\0\0""->set(";____BAH_COMPILER_VAR_1355[0] = pt.cont;char * ____BAH_COMPILER_VAR_1356 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1355, 8);NEXT_LINE = ____BAH_COMPILER_VAR_1356;
}

#line 652 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 653 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1357 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_1357[8] = "\04\0\0\0""));\n";____BAH_COMPILER_VAR_1357[7] = string__str(&elemType);____BAH_COMPILER_VAR_1357[6] = "\011\0\0\0"", sizeof(";____BAH_COMPILER_VAR_1357[5] = tmpV->name;____BAH_COMPILER_VAR_1357[4] = "\03\0\0\0"", &";____BAH_COMPILER_VAR_1357[3] = index.cont;____BAH_COMPILER_VAR_1357[2] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_1357[1] = pt.cont;____BAH_COMPILER_VAR_1357[0] = "\023\0\0\0""mapWrapper__setAny(";char * ____BAH_COMPILER_VAR_1358 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1357, 9);NEXT_LINE = ____BAH_COMPILER_VAR_1358;
}

#line 655 "/home/alois/Documents/bah-bah/src/values.bah"
t.cont = tmpV->name;

#line 656 "/home/alois/Documents/bah-bah/src/values.bah"
t.bahType = string__str(&ptt);
}

#line 657 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 658 "/home/alois/Documents/bah-bah/src/values.bah"
t.isFunc = true;

#line 659 "/home/alois/Documents/bah-bah/src/values.bah"
struct rope* res= null;

#line 660 "/home/alois/Documents/bah-bah/src/values.bah"
char * tmpV = genCompilerVar();

#line 661 "/home/alois/Documents/bah-bah/src/values.bah"
char * ____BAH_COMPILER_VAR_1359 =string__str(&ptt);if (isRCPpointerType(____BAH_COMPILER_VAR_1359)) {

#line 662 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1360 = alloca(10 * sizeof(char*));____BAH_COMPILER_VAR_1360[9] = "\03\0\0\0"");\n";____BAH_COMPILER_VAR_1360[8] = index.cont;____BAH_COMPILER_VAR_1360[7] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_1360[6] = t.cont;____BAH_COMPILER_VAR_1360[5] = "\06\0\0\0""->get(";____BAH_COMPILER_VAR_1360[4] = t.cont;____BAH_COMPILER_VAR_1360[3] = "\01\0\0\0""=";____BAH_COMPILER_VAR_1360[2] = tmpV;____BAH_COMPILER_VAR_1360[1] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_1360[0] = string__str(&elemType);char * ____BAH_COMPILER_VAR_1361 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1360, 10);res = rope(____BAH_COMPILER_VAR_1361);

#line 663 "/home/alois/Documents/bah-bah/src/values.bah"
t.cont = tmpV;
}

#line 664 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 665 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1362 = alloca(10 * sizeof(char*));____BAH_COMPILER_VAR_1362[9] = "\03\0\0\0"");\n";____BAH_COMPILER_VAR_1362[8] = index.cont;____BAH_COMPILER_VAR_1362[7] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_1362[6] = pt.cont;____BAH_COMPILER_VAR_1362[5] = "\06\0\0\0""->get(";____BAH_COMPILER_VAR_1362[4] = pt.cont;____BAH_COMPILER_VAR_1362[3] = "\01\0\0\0""=";____BAH_COMPILER_VAR_1362[2] = tmpV;____BAH_COMPILER_VAR_1362[1] = "\02\0\0\0""* ";____BAH_COMPILER_VAR_1362[0] = string__str(&elemType);char * ____BAH_COMPILER_VAR_1363 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1362, 10);res = rope(____BAH_COMPILER_VAR_1363);

#line 666 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1364 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1364[4] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1364[3] = tmpV;____BAH_COMPILER_VAR_1364[2] = "\03\0\0\0"")(*";____BAH_COMPILER_VAR_1364[1] = string__str(&elemType);____BAH_COMPILER_VAR_1364[0] = "\01\0\0\0""(";char * ____BAH_COMPILER_VAR_1365 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1364, 5);t.cont = ____BAH_COMPILER_VAR_1365;
}

#line 668 "/home/alois/Documents/bah-bah/src/values.bah"
if (RCPavailable()) {

#line 669 "/home/alois/Documents/bah-bah/src/values.bah"
struct variable* ____BAH_COMPILER_VAR_1366 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1366->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_1366->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_1366->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_1366->from = "\0\0\0\0""";
____BAH_COMPILER_VAR_1366->name = tmpV;
____BAH_COMPILER_VAR_1366->type = string__str(&ptt);

    unsigned int ____BAH_COMPILER_VAR_1367 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_1367);
    elems->vars->data[____BAH_COMPILER_VAR_1367] = ____BAH_COMPILER_VAR_1366;
}

#line 674 "/home/alois/Documents/bah-bah/src/values.bah"
if (isGlobal()) {

#line 675 "/home/alois/Documents/bah-bah/src/values.bah"
INIT = rope__add(INIT, res);
}

#line 676 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 677 "/home/alois/Documents/bah-bah/src/values.bah"
OUTPUT = rope__add(OUTPUT, res);
}

#line 679 "/home/alois/Documents/bah-bah/src/values.bah"
t.bahType = string__str(&ptt);
}
}

#line 682 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((strcmp(string__str(&ptt), "\010\0\0\0""cpstring") == 0)) {

#line 683 "/home/alois/Documents/bah-bah/src/values.bah"
t.isFunc = true;

#line 684 "/home/alois/Documents/bah-bah/src/values.bah"
if ((split==false)) {

#line 685 "/home/alois/Documents/bah-bah/src/values.bah"
t.bahType = "\04\0\0\0""char";

#line 686 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok index = memory->data[0];

#line 687 "/home/alois/Documents/bah-bah/src/values.bah"
char * ____BAH_COMPILER_VAR_1368 =getTypeFromToken(&index,true,elems);if (__builtin_expect((compTypes(____BAH_COMPILER_VAR_1368,"\03\0\0\0""int")==false), 0)) {

#line 688 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&index,"\053\0\0\0""Cannot use {TOKEN} as cpstring index (int).");
}

#line 690 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1369 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1369[3] = "\03\0\0\0""+4]";____BAH_COMPILER_VAR_1369[2] = index.cont;____BAH_COMPILER_VAR_1369[1] = "\01\0\0\0""[";____BAH_COMPILER_VAR_1369[0] = pt.cont;char * ____BAH_COMPILER_VAR_1370 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1369, 4);t.cont = ____BAH_COMPILER_VAR_1370;
}

#line 691 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 692 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(to, "\0\0\0\0""") == 0)) {

#line 693 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1371 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1371[2] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1371[1] = pt.cont;____BAH_COMPILER_VAR_1371[0] = "\07\0\0\0""strlen(";char * ____BAH_COMPILER_VAR_1372 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1371, 3);to = ____BAH_COMPILER_VAR_1372;
}

#line 695 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1373 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_1373[6] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1373[5] = to;____BAH_COMPILER_VAR_1373[4] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_1373[3] = from;____BAH_COMPILER_VAR_1373[2] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_1373[1] = pt.cont;____BAH_COMPILER_VAR_1373[0] = "\022\0\0\0""cpstringSubsitute(";char * ____BAH_COMPILER_VAR_1374 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1373, 7);t.cont = ____BAH_COMPILER_VAR_1374;
}
}

#line 698 "/home/alois/Documents/bah-bah/src/values.bah"
else if (string__hasPrefix(&ptt,"\06\0\0\0""tuple:")) {

#line 699 "/home/alois/Documents/bah-bah/src/values.bah"
t.isOper = true;

#line 700 "/home/alois/Documents/bah-bah/src/values.bah"
struct variable* v = searchVar(pt.cont,elems);

#line 701 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((v==null), 0)) {

#line 702 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&pt,"\023\0\0\0""Unkown var {TOKEN}.");
}

#line 704 "/home/alois/Documents/bah-bah/src/values.bah"
array(struct string)* parts = splitString(ptt,"\01\0\0\0"":");

#line 705 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok index = memory->data[0];

#line 706 "/home/alois/Documents/bah-bah/src/values.bah"
if ((index.type==TOKEN_TYPE_INT)) {

#line 707 "/home/alois/Documents/bah-bah/src/values.bah"
long int ind = strToInt(index.cont);

#line 708 "/home/alois/Documents/bah-bah/src/values.bah"
char * ____BAH_COMPILER_VAR_1375 =string__str(&parts->data[1]);if (__builtin_expect((ind>=strToInt(____BAH_COMPILER_VAR_1375)), 0)) {

#line 709 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1376 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1376[4] = "\01\0\0\0"".";____BAH_COMPILER_VAR_1376[3] = string__str(&parts->data[1]);____BAH_COMPILER_VAR_1376[2] = "\013\0\0\0"" of length ";____BAH_COMPILER_VAR_1376[1] = pt.cont;____BAH_COMPILER_VAR_1376[0] = "\046\0\0\0""Cannot access index {TOKEN} of tupple ";char * ____BAH_COMPILER_VAR_1377 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1376, 5);throwErr(&index,____BAH_COMPILER_VAR_1377);
}
}

#line 711 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 712 "/home/alois/Documents/bah-bah/src/values.bah"
char * ____BAH_COMPILER_VAR_1378 =getTypeFromToken(&index,true,elems);if (__builtin_expect((compTypes(____BAH_COMPILER_VAR_1378,"\03\0\0\0""int")==false), 0)) {

#line 713 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&index,"\050\0\0\0""Cannot use {TOKEN} as tuple index (int).");
}
}

#line 716 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1379 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1379[3] = "\01\0\0\0""]";____BAH_COMPILER_VAR_1379[2] = index.cont;____BAH_COMPILER_VAR_1379[1] = "\01\0\0\0""[";____BAH_COMPILER_VAR_1379[0] = pt.cont;char * ____BAH_COMPILER_VAR_1380 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1379, 4);t.cont = ____BAH_COMPILER_VAR_1380;

#line 717 "/home/alois/Documents/bah-bah/src/values.bah"
t.bahType = string__str(&parts->data[2]);
}

#line 718 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 719 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1381 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1381[2] = "\013\0\0\0"") as array.";____BAH_COMPILER_VAR_1381[1] = string__str(&ptt);____BAH_COMPILER_VAR_1381[0] = "\024\0\0\0""Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_1382 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1381, 3);throwErr(&pt,____BAH_COMPILER_VAR_1382);
}

#line 722 "/home/alois/Documents/bah-bah/src/values.bah"
t.isValue = true;

#line 723 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1383 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1383);
    l->data[____BAH_COMPILER_VAR_1383] = t;

#line 725 "/home/alois/Documents/bah-bah/src/values.bah"
return tokPos;
};

#line 728 "/home/alois/Documents/bah-bah/src/values.bah"
long int valueBool(__BAH_ARR_TYPE_Tok l,long int i,lineType ltp,struct Elems* elems){

#line 730 "/home/alois/Documents/bah-bah/src/values.bah"
long int tokPos = i-2;

#line 733 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok pt = l->data[tokPos];

#line 734 "/home/alois/Documents/bah-bah/src/values.bah"
char * ptt = getTypeFromToken(&pt,true,elems);

#line 736 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok t = l->data[tokPos+1];

#line 738 "/home/alois/Documents/bah-bah/src/values.bah"
deleteRange(l,tokPos,tokPos+1);

#line 741 "/home/alois/Documents/bah-bah/src/values.bah"
if ((isFixMeEnabled==false)&&(ltp==LINE_TYPE_FOR)&&(strcmp(ptt, "\03\0\0\0""int") == 0)||(strcmp(ptt, "\05\0\0\0""float") == 0)) {

#line 742 "/home/alois/Documents/bah-bah/src/values.bah"
struct variable* v = getRealVar(pt.cont,elems);

#line 743 "/home/alois/Documents/bah-bah/src/values.bah"
if ((v!=null)) {

#line 744 "/home/alois/Documents/bah-bah/src/values.bah"
v->iterScope = elems;

#line 745 "/home/alois/Documents/bah-bah/src/values.bah"
if ((v->canBeReg==true)&&(v->isReg==false)&&(v->declRope!=null)) {

#line 746 "/home/alois/Documents/bah-bah/src/values.bah"
char * odecl = rope__toStr(v->declRope);

#line 747 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strHasPrefix(odecl,"\011\0\0\0""register ")==false)) {

#line 748 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1384 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1384[1] = odecl;____BAH_COMPILER_VAR_1384[0] = "\011\0\0\0""register ";char * ____BAH_COMPILER_VAR_1385 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1384, 2);OUTPUT->totalLen = OUTPUT->totalLen+ropeSet(v->declRope,____BAH_COMPILER_VAR_1385);
}

#line 750 "/home/alois/Documents/bah-bah/src/values.bah"
v->isReg = true;
}
}
}

#line 756 "/home/alois/Documents/bah-bah/src/values.bah"
if ((isUnsafe==false)) {

#line 757 "/home/alois/Documents/bah-bah/src/values.bah"
if ((tokPos>0)) {

#line 758 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(l->data[tokPos-1].cont, "\02\0\0\0""&&") != 0)) {

#line 759 "/home/alois/Documents/bah-bah/src/values.bah"
clear(currChecks);
}
}

#line 761 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 762 "/home/alois/Documents/bah-bah/src/values.bah"
clear(currChecks);
}
}

#line 767 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok nt = l->data[tokPos];

#line 768 "/home/alois/Documents/bah-bah/src/values.bah"
char * ntt = getTypeFromToken(&nt,true,elems);

#line 769 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(t.cont, "\02\0\0\0""in") == 0)) {

#line 770 "/home/alois/Documents/bah-bah/src/values.bah"
struct string arrT = string(ntt);

#line 771 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((string__hasPrefix(&arrT,"\02\0\0\0""[]")==0), 0)) {

#line 772 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1386 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1386[2] = "\013\0\0\0"") as array.";____BAH_COMPILER_VAR_1386[1] = ntt;____BAH_COMPILER_VAR_1386[0] = "\024\0\0\0""Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_1387 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1386, 3);throwErr(&nt,____BAH_COMPILER_VAR_1387);
}

#line 774 "/home/alois/Documents/bah-bah/src/values.bah"
string__trimLeft(&arrT,2);

#line 775 "/home/alois/Documents/bah-bah/src/values.bah"
char * ____BAH_COMPILER_VAR_1388 =string__str(&arrT);if (__builtin_expect((compTypes(ptt,____BAH_COMPILER_VAR_1388)==false), 0)) {

#line 776 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1389 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1389[4] = "\01\0\0\0"".";____BAH_COMPILER_VAR_1389[3] = ntt;____BAH_COMPILER_VAR_1389[2] = "\05\0\0\0"") in ";____BAH_COMPILER_VAR_1389[1] = ptt;____BAH_COMPILER_VAR_1389[0] = "\033\0\0\0""Cannot search for {TOKEN} (";char * ____BAH_COMPILER_VAR_1390 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1389, 5);throwErr(&pt,____BAH_COMPILER_VAR_1390);
}

#line 778 "/home/alois/Documents/bah-bah/src/values.bah"
char * comp = "\0\0\0\0""";

#line 779 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(ptt, "\010\0\0\0""cpstring") == 0)) {

#line 780 "/home/alois/Documents/bah-bah/src/values.bah"
comp = "\062\0\0\0""arr->data[i] != 0 && strcmp(arr->data[i], el) == 0";
}

#line 781 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 782 "/home/alois/Documents/bah-bah/src/values.bah"
comp = "\022\0\0\0""arr->data[i] == el";
}

#line 784 "/home/alois/Documents/bah-bah/src/values.bah"
char * name = genCompilerVar();

#line 785 "/home/alois/Documents/bah-bah/src/values.bah"

                struct string ____BAH_COMPILER_VAR_1391 = getCType(ntt,elems);
                
                struct string ____BAH_COMPILER_VAR_1392 = getCType(ptt,elems);
                char** ____BAH_COMPILER_VAR_1393 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_1393[8] = "\123\0\0\0"") {\n                return 1;\n            };\n        }\n        return 0;\n        }\n";____BAH_COMPILER_VAR_1393[7] = comp;____BAH_COMPILER_VAR_1393[6] = "\176\0\0\0"" el) {\n        if (arr == 0) {\n            return 0;\n        };\n        for(int i=arr->length-1; i!=-1;i--) {\n            if (";____BAH_COMPILER_VAR_1393[5] = string__str(&____BAH_COMPILER_VAR_1392);____BAH_COMPILER_VAR_1393[4] = "\06\0\0\0"" arr, ";____BAH_COMPILER_VAR_1393[3] = string__str(&____BAH_COMPILER_VAR_1391);____BAH_COMPILER_VAR_1393[2] = "\01\0\0\0""(";____BAH_COMPILER_VAR_1393[1] = name;____BAH_COMPILER_VAR_1393[0] = "\05\0\0\0""char ";char * ____BAH_COMPILER_VAR_1394 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1393, 9);char * fnTest = ____BAH_COMPILER_VAR_1394;

#line 796 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1395 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1395[1] = fnTest;____BAH_COMPILER_VAR_1395[0] = rope__toStr(postDeclHandle);char * ____BAH_COMPILER_VAR_1396 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1395, 2);OUTPUT->totalLen = OUTPUT->totalLen+ropeSet(postDeclHandle,____BAH_COMPILER_VAR_1396);

#line 798 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1397 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_1397[5] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1397[4] = pt.cont;____BAH_COMPILER_VAR_1397[3] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_1397[2] = nt.cont;____BAH_COMPILER_VAR_1397[1] = "\01\0\0\0""(";____BAH_COMPILER_VAR_1397[0] = name;char * ____BAH_COMPILER_VAR_1398 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1397, 6);char * fnCall = ____BAH_COMPILER_VAR_1398;

#line 800 "/home/alois/Documents/bah-bah/src/values.bah"
pt.isExpensive = true;

#line 801 "/home/alois/Documents/bah-bah/src/values.bah"
pt.cont = fnCall;
}

#line 802 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 803 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((compTypes(ptt,ntt)==false), 0)) {

#line 804 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1399 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1399[4] = "\01\0\0\0"".";____BAH_COMPILER_VAR_1399[3] = ptt;____BAH_COMPILER_VAR_1399[2] = "\014\0\0\0"") with type ";____BAH_COMPILER_VAR_1399[1] = ntt;____BAH_COMPILER_VAR_1399[0] = "\030\0\0\0""Cannot compare {TOKEN} (";char * ____BAH_COMPILER_VAR_1400 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1399, 5);throwErr(&nt,____BAH_COMPILER_VAR_1400);
}

#line 806 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(ptt, "\010\0\0\0""cpstring") == 0)) {

#line 807 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(t.cont, "\02\0\0\0""==") == 0)) {

#line 808 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1401 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1401[4] = "\07\0\0\0"") == 0)";____BAH_COMPILER_VAR_1401[3] = nt.cont;____BAH_COMPILER_VAR_1401[2] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_1401[1] = pt.cont;____BAH_COMPILER_VAR_1401[0] = "\010\0\0\0""(strcmp(";char * ____BAH_COMPILER_VAR_1402 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1401, 5);pt.cont = ____BAH_COMPILER_VAR_1402;
}

#line 810 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((strcmp(t.cont, "\02\0\0\0""!=") == 0)) {

#line 811 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1403 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1403[4] = "\07\0\0\0"") != 0)";____BAH_COMPILER_VAR_1403[3] = nt.cont;____BAH_COMPILER_VAR_1403[2] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_1403[1] = pt.cont;____BAH_COMPILER_VAR_1403[0] = "\010\0\0\0""(strcmp(";char * ____BAH_COMPILER_VAR_1404 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1403, 5);pt.cont = ____BAH_COMPILER_VAR_1404;
}

#line 812 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((strcmp(t.cont, "\01\0\0\0"">") == 0)) {

#line 813 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1405 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1405[4] = "\02\0\0\0""))";____BAH_COMPILER_VAR_1405[3] = nt.cont;____BAH_COMPILER_VAR_1405[2] = "\013\0\0\0"") > srtlen(";____BAH_COMPILER_VAR_1405[1] = pt.cont;____BAH_COMPILER_VAR_1405[0] = "\010\0\0\0""(strlen(";char * ____BAH_COMPILER_VAR_1406 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1405, 5);pt.cont = ____BAH_COMPILER_VAR_1406;
}

#line 814 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((strcmp(t.cont, "\01\0\0\0""<") == 0)) {

#line 815 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1407 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1407[4] = "\02\0\0\0""))";____BAH_COMPILER_VAR_1407[3] = nt.cont;____BAH_COMPILER_VAR_1407[2] = "\013\0\0\0"") < srtlen(";____BAH_COMPILER_VAR_1407[1] = pt.cont;____BAH_COMPILER_VAR_1407[0] = "\010\0\0\0""(strlen(";char * ____BAH_COMPILER_VAR_1408 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1407, 5);pt.cont = ____BAH_COMPILER_VAR_1408;
}

#line 816 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((strcmp(t.cont, "\02\0\0\0"">=") == 0)) {

#line 817 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1409 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1409[4] = "\02\0\0\0""))";____BAH_COMPILER_VAR_1409[3] = nt.cont;____BAH_COMPILER_VAR_1409[2] = "\014\0\0\0"") >= srtlen(";____BAH_COMPILER_VAR_1409[1] = pt.cont;____BAH_COMPILER_VAR_1409[0] = "\010\0\0\0""(strlen(";char * ____BAH_COMPILER_VAR_1410 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1409, 5);pt.cont = ____BAH_COMPILER_VAR_1410;
}

#line 818 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((strcmp(t.cont, "\02\0\0\0""<=") == 0)) {

#line 819 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1411 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1411[4] = "\02\0\0\0""))";____BAH_COMPILER_VAR_1411[3] = nt.cont;____BAH_COMPILER_VAR_1411[2] = "\014\0\0\0"") <= srtlen(";____BAH_COMPILER_VAR_1411[1] = pt.cont;____BAH_COMPILER_VAR_1411[0] = "\010\0\0\0""(strlen(";char * ____BAH_COMPILER_VAR_1412 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1411, 5);pt.cont = ____BAH_COMPILER_VAR_1412;
}

#line 821 "/home/alois/Documents/bah-bah/src/values.bah"
pt.isExpensive = true;
}

#line 822 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 823 "/home/alois/Documents/bah-bah/src/values.bah"
if ((isUnsafe==false)&&(pt.type==TOKEN_TYPE_VAR)&&(pt.isOper==false)&&isRCPpointerType(ptt)) {

#line 824 "/home/alois/Documents/bah-bah/src/values.bah"
struct variable* ptV = searchVar(pt.cont,elems);

#line 825 "/home/alois/Documents/bah-bah/src/values.bah"
if ((ptV!=null)) {

#line 826 "/home/alois/Documents/bah-bah/src/values.bah"
char ntIsNull = false;

#line 827 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(nt.cont, "\04\0\0\0""null") == 0)) {

#line 828 "/home/alois/Documents/bah-bah/src/values.bah"
ntIsNull = true;
}

#line 829 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((nt.type==TOKEN_TYPE_VAR)&&(nt.isOper==false)) {

#line 830 "/home/alois/Documents/bah-bah/src/values.bah"
struct variable* nv = searchVar(nt.cont,elems);

#line 831 "/home/alois/Documents/bah-bah/src/values.bah"
if ((nv!=null)) {

#line 832 "/home/alois/Documents/bah-bah/src/values.bah"
ntIsNull = nv->canBeNull;
}
}

#line 834 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((nt.isFunc==true)) {

#line 835 "/home/alois/Documents/bah-bah/src/values.bah"
struct func* fn = searchFuncByToken(&nt,elems);

#line 836 "/home/alois/Documents/bah-bah/src/values.bah"
if ((fn!=null)&&(fn->returns!=null)) {

#line 837 "/home/alois/Documents/bah-bah/src/values.bah"
ntIsNull = (fn->returns->type[strlen(fn->returns->type)-1+4]==33);
}
}

#line 840 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(t.cont, "\02\0\0\0""==") == 0)) {

#line 841 "/home/alois/Documents/bah-bah/src/values.bah"
struct varCheck ____BAH_COMPILER_VAR_1413 = {};
____BAH_COMPILER_VAR_1413.v = ptV;
____BAH_COMPILER_VAR_1413.checkNull = ntIsNull;

    unsigned int ____BAH_COMPILER_VAR_1414 = len(currChecks);
    __Bah_realocate_arr(currChecks, ____BAH_COMPILER_VAR_1414);
    currChecks->data[____BAH_COMPILER_VAR_1414] = ____BAH_COMPILER_VAR_1413;
}

#line 845 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((strcmp(t.cont, "\02\0\0\0""!=") == 0)) {

#line 846 "/home/alois/Documents/bah-bah/src/values.bah"
struct varCheck ____BAH_COMPILER_VAR_1415 = {};
____BAH_COMPILER_VAR_1415.v = ptV;
____BAH_COMPILER_VAR_1415.checkNull = (ntIsNull==false);

    unsigned int ____BAH_COMPILER_VAR_1416 = len(currChecks);
    __Bah_realocate_arr(currChecks, ____BAH_COMPILER_VAR_1416);
    currChecks->data[____BAH_COMPILER_VAR_1416] = ____BAH_COMPILER_VAR_1415;
}
}
}

#line 853 "/home/alois/Documents/bah-bah/src/values.bah"
if (isExprExpensive(&pt)||isExprExpensive(&nt)) {

#line 854 "/home/alois/Documents/bah-bah/src/values.bah"
pt.isExpensive = true;
}

#line 855 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 856 "/home/alois/Documents/bah-bah/src/values.bah"
pt.isExpensive = false;
}

#line 858 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1417 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1417[4] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1417[3] = nt.cont;____BAH_COMPILER_VAR_1417[2] = t.cont;____BAH_COMPILER_VAR_1417[1] = pt.cont;____BAH_COMPILER_VAR_1417[0] = "\01\0\0\0""(";char * ____BAH_COMPILER_VAR_1418 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1417, 5);pt.cont = ____BAH_COMPILER_VAR_1418;
}
}

#line 863 "/home/alois/Documents/bah-bah/src/values.bah"
pt.isOper = true;

#line 864 "/home/alois/Documents/bah-bah/src/values.bah"
pt.bahType = "\04\0\0\0""bool";

#line 865 "/home/alois/Documents/bah-bah/src/values.bah"
pt.isValue = true;

#line 866 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1419 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1419);
    l->data[____BAH_COMPILER_VAR_1419] = pt;

#line 867 "/home/alois/Documents/bah-bah/src/values.bah"
return tokPos;
};

#line 871 "/home/alois/Documents/bah-bah/src/values.bah"
char ____BAH_COMPILER_VAR_1428(array(char *)* arr, char * el) {
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
char ____BAH_COMPILER_VAR_1429(array(char *)* arr, char * el) {
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

#line 872 "/home/alois/Documents/bah-bah/src/values.bah"
long int tokPos = i-2;

#line 874 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok pt = l->data[tokPos];

#line 875 "/home/alois/Documents/bah-bah/src/values.bah"
char * ptt = getTypeFromToken(&pt,true,elems);

#line 878 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok t = l->data[tokPos+1];

#line 879 "/home/alois/Documents/bah-bah/src/values.bah"
deleteRange(l,tokPos,tokPos+1);

#line 882 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok nt = l->data[tokPos];

#line 885 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(nt.cont, t.cont) == 0)) {

#line 886 "/home/alois/Documents/bah-bah/src/values.bah"
pt.isOper = true;

#line 887 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1420 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1420[2] = pt.cont;____BAH_COMPILER_VAR_1420[1] = t.cont;____BAH_COMPILER_VAR_1420[0] = t.cont;char * ____BAH_COMPILER_VAR_1421 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1420, 3);pt.cont = ____BAH_COMPILER_VAR_1421;

#line 888 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1422 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1422);
    l->data[____BAH_COMPILER_VAR_1422] = pt;

#line 889 "/home/alois/Documents/bah-bah/src/values.bah"
return tokPos;
}

#line 893 "/home/alois/Documents/bah-bah/src/values.bah"
char * ntt = getTypeFromToken(&nt,true,elems);

#line 894 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((compTypes(ptt,ntt)==false), 0)) {

#line 895 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1423 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1423[4] = "\01\0\0\0"".";____BAH_COMPILER_VAR_1423[3] = ptt;____BAH_COMPILER_VAR_1423[2] = "\05\0\0\0"") as ";____BAH_COMPILER_VAR_1423[1] = ntt;____BAH_COMPILER_VAR_1423[0] = "\030\0\0\0""Cannot operate {TOKEN} (";char * ____BAH_COMPILER_VAR_1424 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1423, 5);throwErr(&nt,____BAH_COMPILER_VAR_1424);
}

#line 898 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((strcmp(ptt, "\03\0\0\0""ptr") == 0), 0)) {

#line 899 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&pt,"\045\0\0\0""Cannot do operation on {TOKEN} (ptr).");
}

#line 901 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((strcmp(ntt, "\03\0\0\0""ptr") == 0), 0)) {

#line 902 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&nt,"\045\0\0\0""Cannot do operation on {TOKEN} (ptr).");
}

#line 906 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(ptt, "\010\0\0\0""cpstring") == 0)) {

#line 909 "/home/alois/Documents/bah-bah/src/values.bah"
array(char *)* strs = memoryAlloc(sizeof(array(char *)));

strs->length = 2;
strs->elemSize = sizeof(char *);
strs->data = memoryAlloc(sizeof(char *) * 50);
                    strs->realLength = 50;
strs->data[0] = nt.cont;
strs->data[1] = pt.cont;

#line 911 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((strcmp(t.cont, "\01\0\0\0""+") != 0), 0)) {

#line 912 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&t,"\063\0\0\0""Can only do concatenation on cpstring, not {TOKEN}.");
}

#line 916 "/home/alois/Documents/bah-bah/src/values.bah"
if ((tokPos-1>=0)) {

#line 917 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok nat = l->data[tokPos-1];

#line 918 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(nat.cont, "\01\0\0\0""+") == 0)) {

#line 920 "/home/alois/Documents/bah-bah/src/values.bah"
long int rangeEnds = tokPos-1;

#line 921 "/home/alois/Documents/bah-bah/src/values.bah"
i = tokPos-2;

#line 922 "/home/alois/Documents/bah-bah/src/values.bah"
long int nb = 2;

#line 923 "/home/alois/Documents/bah-bah/src/values.bah"
for (; (i>=0); 
#line 923 "/home/alois/Documents/bah-bah/src/values.bah"
--i) {

#line 924 "/home/alois/Documents/bah-bah/src/values.bah"
tokPos = i;

#line 925 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok currStrTk = l->data[i];

#line 927 "/home/alois/Documents/bah-bah/src/values.bah"
char * tt = getTypeFromToken(&currStrTk,true,elems);

#line 928 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((compTypes(tt,"\010\0\0\0""cpstring")==false), 0)) {

#line 929 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1425 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1425[2] = "\02\0\0\0"").";____BAH_COMPILER_VAR_1425[1] = tt;____BAH_COMPILER_VAR_1425[0] = "\052\0\0\0""Cannot concatenate cpstring with {TOKEN} (";char * ____BAH_COMPILER_VAR_1426 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1425, 3);throwErr(&currStrTk,____BAH_COMPILER_VAR_1426);
}

#line 932 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1427 = len(strs);
    __Bah_realocate_arr(strs, ____BAH_COMPILER_VAR_1427);
    strs->data[____BAH_COMPILER_VAR_1427] = currStrTk.cont;

#line 935 "/home/alois/Documents/bah-bah/src/values.bah"
if ((i-1>=0)) {

#line 936 "/home/alois/Documents/bah-bah/src/values.bah"
--i;

#line 937 "/home/alois/Documents/bah-bah/src/values.bah"
t = l->data[i];

#line 938 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(t.cont, "\01\0\0\0""+") != 0)) {

#line 939 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect(____BAH_COMPILER_VAR_1428(signs, t.cont), 0)) {

#line 940 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&t,"\063\0\0\0""Can only do concatenation on cpstring, not {TOKEN}.");
}

#line 941 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 942 "/home/alois/Documents/bah-bah/src/values.bah"
++i;

#line 943 "/home/alois/Documents/bah-bah/src/values.bah"
break;
}
}
}

#line 947 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 948 "/home/alois/Documents/bah-bah/src/values.bah"
i = 0;

#line 949 "/home/alois/Documents/bah-bah/src/values.bah"
break;
}
};

#line 952 "/home/alois/Documents/bah-bah/src/values.bah"
deleteRange(l,i,rangeEnds);
}

#line 953 "/home/alois/Documents/bah-bah/src/values.bah"
else if (__builtin_expect(____BAH_COMPILER_VAR_1429(signs, nat.cont), 0)) {

#line 954 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&nat,"\063\0\0\0""Can only do concatenation on cpstring, not {TOKEN}.");
}
}

#line 960 "/home/alois/Documents/bah-bah/src/values.bah"
pt.type = TOKEN_TYPE_VAR;

#line 961 "/home/alois/Documents/bah-bah/src/values.bah"
pt.isValue = true;

#line 962 "/home/alois/Documents/bah-bah/src/values.bah"
pt.cont = genConcat(strs,elems);

#line 963 "/home/alois/Documents/bah-bah/src/values.bah"
pt.isOper = false;
}

#line 964 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 966 "/home/alois/Documents/bah-bah/src/values.bah"
struct cStruct* s = searchStruct(ptt,elems);

#line 967 "/home/alois/Documents/bah-bah/src/values.bah"
if ((s!=null)) {

#line 968 "/home/alois/Documents/bah-bah/src/values.bah"
char * sep = "\01\0\0\0"".";

#line 969 "/home/alois/Documents/bah-bah/src/values.bah"
char * amp = "\01\0\0\0""&";

#line 971 "/home/alois/Documents/bah-bah/src/values.bah"
if (isRCPpointerType(ptt)) {

#line 972 "/home/alois/Documents/bah-bah/src/values.bah"
sep = "\02\0\0\0""->";

#line 973 "/home/alois/Documents/bah-bah/src/values.bah"
amp = "\0\0\0\0""";
}

#line 975 "/home/alois/Documents/bah-bah/src/values.bah"
char * mName = "\0\0\0\0""";

#line 976 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(t.cont, "\01\0\0\0""+") == 0)) {

#line 977 "/home/alois/Documents/bah-bah/src/values.bah"
mName = "\03\0\0\0""add";
}

#line 978 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((strcmp(t.cont, "\01\0\0\0""-") == 0)) {

#line 979 "/home/alois/Documents/bah-bah/src/values.bah"
mName = "\03\0\0\0""sub";
}

#line 980 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((strcmp(t.cont, "\01\0\0\0""*") == 0)) {

#line 981 "/home/alois/Documents/bah-bah/src/values.bah"
mName = "\04\0\0\0""mult";
}

#line 982 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((strcmp(t.cont, "\01\0\0\0""/") == 0)) {

#line 983 "/home/alois/Documents/bah-bah/src/values.bah"
mName = "\03\0\0\0""div";
}

#line 984 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 985 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1430 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1430[2] = "\02\0\0\0"").";____BAH_COMPILER_VAR_1430[1] = ptt;____BAH_COMPILER_VAR_1430[0] = "\047\0\0\0""Undefined operation on struct {TOKEN} (";char * ____BAH_COMPILER_VAR_1431 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1430, 3);throwErr(&pt,____BAH_COMPILER_VAR_1431);
}

#line 987 "/home/alois/Documents/bah-bah/src/values.bah"
struct structMemb* methd = searchStructMemb(mName,s,elems);

#line 988 "/home/alois/Documents/bah-bah/src/values.bah"
if ((methd!=null)&&(methd->isFn==true)) {

#line 989 "/home/alois/Documents/bah-bah/src/values.bah"
if (RCPavailable()) {

#line 990 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1432 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_1432[8] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1432[7] = nt.cont;____BAH_COMPILER_VAR_1432[6] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_1432[5] = pt.cont;____BAH_COMPILER_VAR_1432[4] = amp;____BAH_COMPILER_VAR_1432[3] = "\01\0\0\0""(";____BAH_COMPILER_VAR_1432[2] = mName;____BAH_COMPILER_VAR_1432[1] = "\02\0\0\0""__";____BAH_COMPILER_VAR_1432[0] = s->name;char * ____BAH_COMPILER_VAR_1433 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1432, 9);pt.cont = registerRCPvar(ptt,____BAH_COMPILER_VAR_1433,elems);

#line 991 "/home/alois/Documents/bah-bah/src/values.bah"
pt.type = TOKEN_TYPE_VAR;

#line 991 "/home/alois/Documents/bah-bah/src/values.bah"
pt.isFunc = false;

#line 991 "/home/alois/Documents/bah-bah/src/values.bah"
pt.isOper = false;
}

#line 992 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 993 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1434 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_1434[8] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1434[7] = nt.cont;____BAH_COMPILER_VAR_1434[6] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_1434[5] = pt.cont;____BAH_COMPILER_VAR_1434[4] = amp;____BAH_COMPILER_VAR_1434[3] = "\01\0\0\0""(";____BAH_COMPILER_VAR_1434[2] = mName;____BAH_COMPILER_VAR_1434[1] = "\02\0\0\0""__";____BAH_COMPILER_VAR_1434[0] = s->name;char * ____BAH_COMPILER_VAR_1435 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1434, 9);pt.cont = ____BAH_COMPILER_VAR_1435;

#line 994 "/home/alois/Documents/bah-bah/src/values.bah"
pt.isFunc = true;
}
}
}

#line 997 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 998 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1436 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1436[1] = nt.cont;____BAH_COMPILER_VAR_1436[0] = t.cont;char * ____BAH_COMPILER_VAR_1437 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1436, 2);char** ____BAH_COMPILER_VAR_1438 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1438[1] = ____BAH_COMPILER_VAR_1437;____BAH_COMPILER_VAR_1438[0] = pt.cont;char * ____BAH_COMPILER_VAR_1439 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1438, 2);pt.cont = ____BAH_COMPILER_VAR_1439;
}

#line 1000 "/home/alois/Documents/bah-bah/src/values.bah"
pt.isOper = true;
}

#line 1003 "/home/alois/Documents/bah-bah/src/values.bah"
pt.isNotExpsvOper = false;

#line 1004 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1440 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1440);
    l->data[____BAH_COMPILER_VAR_1440] = pt;

#line 1005 "/home/alois/Documents/bah-bah/src/values.bah"
return tokPos;
};

#line 1008 "/home/alois/Documents/bah-bah/src/values.bah"
long int valueSendChan(__BAH_ARR_TYPE_Tok l,long int i,struct Elems* elems){

#line 1009 "/home/alois/Documents/bah-bah/src/values.bah"
long int posTok = i-2;

#line 1011 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok nt = l->data[posTok];

#line 1013 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok pt = l->data[posTok+2];

#line 1014 "/home/alois/Documents/bah-bah/src/values.bah"
deleteRange(l,posTok,posTok+2);

#line 1016 "/home/alois/Documents/bah-bah/src/values.bah"
char * ntt = getTypeFromToken(&nt,true,elems);

#line 1018 "/home/alois/Documents/bah-bah/src/values.bah"
char * ____BAH_COMPILER_VAR_1441 =getTypeFromToken(&pt,true,elems);struct string ptt = string(____BAH_COMPILER_VAR_1441);

#line 1019 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((string__hasPrefix(&ptt,"\05\0\0\0""chan:")==0), 0)) {

#line 1020 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1442 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1442[2] = "\012\0\0\0"") as chan.";____BAH_COMPILER_VAR_1442[1] = string__str(&ptt);____BAH_COMPILER_VAR_1442[0] = "\024\0\0\0""Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_1443 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1442, 3);throwErr(&pt,____BAH_COMPILER_VAR_1443);
}

#line 1022 "/home/alois/Documents/bah-bah/src/values.bah"
string__trimLeft(&ptt,5);

#line 1024 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect(isGlobal(), 0)) {

#line 1025 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&pt,"\055\0\0\0""Cannot send to channel {TOKEN} of a function.");
}

#line 1028 "/home/alois/Documents/bah-bah/src/values.bah"
char * ____BAH_COMPILER_VAR_1444 =string__str(&ptt);if (__builtin_expect((compTypes(ntt,____BAH_COMPILER_VAR_1444)==false), 0)) {

#line 1029 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1445 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1445[4] = "\01\0\0\0"".";____BAH_COMPILER_VAR_1445[3] = string__str(&ptt);____BAH_COMPILER_VAR_1445[2] = "\017\0\0\0"") through chan:";____BAH_COMPILER_VAR_1445[1] = ntt;____BAH_COMPILER_VAR_1445[0] = "\025\0\0\0""Cannot send {TOKEN} (";char * ____BAH_COMPILER_VAR_1446 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1445, 5);throwErr(&nt,____BAH_COMPILER_VAR_1446);
}

#line 1032 "/home/alois/Documents/bah-bah/src/values.bah"
char * ____BAH_COMPILER_VAR_1447 =string__str(&ptt);if (isRCPpointerType(____BAH_COMPILER_VAR_1447)) {

#line 1033 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1448 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1448[4] = "\03\0\0\0"");\n";____BAH_COMPILER_VAR_1448[3] = nt.cont;____BAH_COMPILER_VAR_1448[2] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_1448[1] = pt.cont;____BAH_COMPILER_VAR_1448[0] = "\016\0\0\0""channel__send(";char * ____BAH_COMPILER_VAR_1449 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1448, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1449));
}

#line 1034 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 1035 "/home/alois/Documents/bah-bah/src/values.bah"
struct string ct = getCType(ntt,elems);

#line 1036 "/home/alois/Documents/bah-bah/src/values.bah"
char * tmpV = genCompilerVar();

#line 1037 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1450 = alloca(13 * sizeof(char*));____BAH_COMPILER_VAR_1450[12] = "\014\0\0\0""));\n        ";____BAH_COMPILER_VAR_1450[11] = tmpV;____BAH_COMPILER_VAR_1450[10] = "\011\0\0\0"", sizeof(";____BAH_COMPILER_VAR_1450[9] = tmpV;____BAH_COMPILER_VAR_1450[8] = "\03\0\0\0"", &";____BAH_COMPILER_VAR_1450[7] = pt.cont;____BAH_COMPILER_VAR_1450[6] = "\033\0\0\0"";\n        channel__sendAny(";____BAH_COMPILER_VAR_1450[5] = nt.cont;____BAH_COMPILER_VAR_1450[4] = "\03\0\0\0"" = ";____BAH_COMPILER_VAR_1450[3] = tmpV;____BAH_COMPILER_VAR_1450[2] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_1450[1] = string__str(&ct);____BAH_COMPILER_VAR_1450[0] = "\011\0\0\0""\n        ";char * ____BAH_COMPILER_VAR_1451 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1450, 13);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1451));
}

#line 1043 "/home/alois/Documents/bah-bah/src/values.bah"
return posTok;
};

#line 1046 "/home/alois/Documents/bah-bah/src/values.bah"
long int valueChan(__BAH_ARR_TYPE_Tok l,long int i,struct Elems* elems){

#line 1047 "/home/alois/Documents/bah-bah/src/values.bah"
long int posTok = i-1;

#line 1048 "/home/alois/Documents/bah-bah/src/values.bah"
delete(l,posTok);

#line 1051 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok nt = l->data[posTok];

#line 1053 "/home/alois/Documents/bah-bah/src/values.bah"
char * ____BAH_COMPILER_VAR_1452 =getTypeFromToken(&nt,true,elems);struct string ntt = string(____BAH_COMPILER_VAR_1452);

#line 1054 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((string__hasPrefix(&ntt,"\05\0\0\0""chan:")==0), 0)) {

#line 1055 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1453 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1453[2] = "\012\0\0\0"") as chan.";____BAH_COMPILER_VAR_1453[1] = string__str(&ntt);____BAH_COMPILER_VAR_1453[0] = "\024\0\0\0""Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_1454 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1453, 3);throwErr(&nt,____BAH_COMPILER_VAR_1454);
}

#line 1058 "/home/alois/Documents/bah-bah/src/values.bah"
string__trimLeft(&ntt,5);

#line 1060 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect(isGlobal(), 0)) {

#line 1061 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&nt,"\071\0\0\0""Cannot receive from chan {TOKEN} outside a function body.");
}

#line 1064 "/home/alois/Documents/bah-bah/src/values.bah"
char * ____BAH_COMPILER_VAR_1455 =string__str(&ntt);struct string ct = getCType(____BAH_COMPILER_VAR_1455,elems);

#line 1065 "/home/alois/Documents/bah-bah/src/values.bah"
char * ____BAH_COMPILER_VAR_1456 =string__str(&ntt);if (isRCPpointerType(____BAH_COMPILER_VAR_1456)) {

#line 1066 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1457 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1457[2] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1457[1] = nt.cont;____BAH_COMPILER_VAR_1457[0] = "\021\0\0\0""channel__receive(";char * ____BAH_COMPILER_VAR_1458 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1457, 3);char * ____BAH_COMPILER_VAR_1459 =string__str(&ntt);char * tmpV = registerRCPvar(____BAH_COMPILER_VAR_1459,____BAH_COMPILER_VAR_1458,elems);

#line 1067 "/home/alois/Documents/bah-bah/src/values.bah"
nt.cont = tmpV;
}

#line 1068 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 1069 "/home/alois/Documents/bah-bah/src/values.bah"
if (RCPavailable()) {

#line 1070 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1460 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1460[1] = "\01\0\0\0""*";____BAH_COMPILER_VAR_1460[0] = string__str(&ntt);char * ____BAH_COMPILER_VAR_1461 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1460, 2);char** ____BAH_COMPILER_VAR_1462 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1462[4] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1462[3] = nt.cont;____BAH_COMPILER_VAR_1462[2] = "\023\0\0\0""*)channel__receive(";____BAH_COMPILER_VAR_1462[1] = string__str(&ct);____BAH_COMPILER_VAR_1462[0] = "\01\0\0\0""(";char * ____BAH_COMPILER_VAR_1463 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1462, 5);char * tmpV = registerRCPvar(____BAH_COMPILER_VAR_1461,____BAH_COMPILER_VAR_1463,elems);

#line 1071 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1464 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1464[1] = tmpV;____BAH_COMPILER_VAR_1464[0] = "\01\0\0\0""*";char * ____BAH_COMPILER_VAR_1465 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1464, 2);nt.cont = ____BAH_COMPILER_VAR_1465;
}

#line 1072 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 1073 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1466 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1466[4] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1466[3] = nt.cont;____BAH_COMPILER_VAR_1466[2] = "\023\0\0\0""*)channel__receive(";____BAH_COMPILER_VAR_1466[1] = string__str(&ct);____BAH_COMPILER_VAR_1466[0] = "\02\0\0\0""*(";char * ____BAH_COMPILER_VAR_1467 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1466, 5);nt.cont = ____BAH_COMPILER_VAR_1467;
}
}

#line 1077 "/home/alois/Documents/bah-bah/src/values.bah"
nt.type = TOKEN_TYPE_FUNC;

#line 1078 "/home/alois/Documents/bah-bah/src/values.bah"
nt.isFunc = true;

#line 1079 "/home/alois/Documents/bah-bah/src/values.bah"
nt.isValue = true;

#line 1080 "/home/alois/Documents/bah-bah/src/values.bah"
nt.bahType = string__str(&ntt);

#line 1082 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1468 = posTok;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1468);
    l->data[____BAH_COMPILER_VAR_1468] = nt;

#line 1084 "/home/alois/Documents/bah-bah/src/values.bah"
return posTok;
};

#line 1087 "/home/alois/Documents/bah-bah/src/values.bah"
long int valueTuple(__BAH_ARR_TYPE_Tok l,long int i,struct Elems* elems){

#line 1088 "/home/alois/Documents/bah-bah/src/values.bah"
long int tokPos = i;

#line 1090 "/home/alois/Documents/bah-bah/src/values.bah"
long int nbBracks = 0;

#line 1091 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((strcmp(l->data[tokPos+1].cont, "\01\0\0\0""]") == 0), 0)) {

#line 1093 "/home/alois/Documents/bah-bah/src/values.bah"
long int offset = 1;

#line 1094 "/home/alois/Documents/bah-bah/src/values.bah"
while ((strcmp(l->data[tokPos+offset+1].cont, "\01\0\0\0""[") == 0)&&(strcmp(l->data[tokPos+offset+2].cont, "\01\0\0\0""]") == 0)) {

#line 1095 "/home/alois/Documents/bah-bah/src/values.bah"
offset = offset+2;
};

#line 1097 "/home/alois/Documents/bah-bah/src/values.bah"
if ((l->data[tokPos+offset+1].type==TOKEN_TYPE_VAR)) {

#line 1098 "/home/alois/Documents/bah-bah/src/values.bah"
return tokPos+1;
}

#line 1100 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&l->data[tokPos],"\043\0\0\0""Cannot declare {TOKEN} empty tuple.");
}

#line 1105 "/home/alois/Documents/bah-bah/src/values.bah"
array(char *)* vals = memoryAlloc(sizeof(array(char *)));

vals->length = 0;
vals->elemSize = sizeof(char *);

#line 1107 "/home/alois/Documents/bah-bah/src/values.bah"
long int nbEncl = 1;

#line 1108 "/home/alois/Documents/bah-bah/src/values.bah"
++i;

#line 1108 "/home/alois/Documents/bah-bah/src/values.bah"
for (; (i<len(l)); 
#line 1108 "/home/alois/Documents/bah-bah/src/values.bah"
++i) {

#line 1109 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(l->data[i].cont, "\01\0\0\0""[") == 0)||(strcmp(l->data[i].cont, "\01\0\0\0""(") == 0)) {

#line 1110 "/home/alois/Documents/bah-bah/src/values.bah"
++nbEncl;
}

#line 1111 "/home/alois/Documents/bah-bah/src/values.bah"
else if ((strcmp(l->data[1].cont, "\01\0\0\0""]") == 0)||(strcmp(l->data[i].cont, "\01\0\0\0"")") == 0)) {

#line 1112 "/home/alois/Documents/bah-bah/src/values.bah"
--nbEncl;

#line 1113 "/home/alois/Documents/bah-bah/src/values.bah"
if ((nbEncl==0)) {

#line 1114 "/home/alois/Documents/bah-bah/src/values.bah"
break;
}
}
};

#line 1119 "/home/alois/Documents/bah-bah/src/values.bah"
array(struct Tok)* memory = arraySubstitute(l, tokPos+1, i);

#line 1121 "/home/alois/Documents/bah-bah/src/values.bah"
memory = prePross(memory,(lineType)-1,elems);

#line 1122 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok ft = memory->data[0];

#line 1123 "/home/alois/Documents/bah-bah/src/values.bah"
char * tupT = getTypeFromToken(&ft,true,elems);

#line 1125 "/home/alois/Documents/bah-bah/src/values.bah"
register long int j = 0;

#line 1125 "/home/alois/Documents/bah-bah/src/values.bah"
for (; (j<len(memory)); 
#line 1125 "/home/alois/Documents/bah-bah/src/values.bah"
j = j+2) {

#line 1126 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok t = memory->data[j];

#line 1127 "/home/alois/Documents/bah-bah/src/values.bah"
char * tt = getTypeFromToken(&t,true,elems);

#line 1128 "/home/alois/Documents/bah-bah/src/values.bah"
if (__builtin_expect((compTypes(tupT,tt)==false), 0)) {

#line 1129 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1469 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1469[4] = "\026\0\0\0"" in tuple declaration.";____BAH_COMPILER_VAR_1469[3] = tupT;____BAH_COMPILER_VAR_1469[2] = "\05\0\0\0"") as ";____BAH_COMPILER_VAR_1469[1] = tt;____BAH_COMPILER_VAR_1469[0] = "\024\0\0\0""Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_1470 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1469, 5);throwErr(&t,____BAH_COMPILER_VAR_1470);
}

#line 1131 "/home/alois/Documents/bah-bah/src/values.bah"

    unsigned int ____BAH_COMPILER_VAR_1471 = len(vals);
    __Bah_realocate_arr(vals, ____BAH_COMPILER_VAR_1471);
    vals->data[____BAH_COMPILER_VAR_1471] = t.cont;

#line 1132 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok nt = memory->data[j+1];

#line 1133 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(nt.cont, "\01\0\0\0""]") == 0)) {

#line 1134 "/home/alois/Documents/bah-bah/src/values.bah"
break;
}

#line 1135 "/home/alois/Documents/bah-bah/src/values.bah"
else if (__builtin_expect((strcmp(nt.cont, "\01\0\0\0"",") != 0), 0)) {

#line 1136 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&nt,"\104\0\0\0""Expected separator between values in tuple declaration, got {TOKEN}.");
}
};

#line 1140 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1472 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1472[3] = tupT;____BAH_COMPILER_VAR_1472[2] = "\01\0\0\0"":";____BAH_COMPILER_VAR_1472[1] = intToStr(len(vals));____BAH_COMPILER_VAR_1472[0] = "\06\0\0\0""tuple:";char * ____BAH_COMPILER_VAR_1473 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1472, 4);char * type = ____BAH_COMPILER_VAR_1473;

#line 1142 "/home/alois/Documents/bah-bah/src/values.bah"
deleteRange(l,tokPos+1,j+1);

#line 1144 "/home/alois/Documents/bah-bah/src/values.bah"

                struct string ____BAH_COMPILER_VAR_1474 = getCType(tupT,elems);
                char** ____BAH_COMPILER_VAR_1475 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1475[4] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1475[3] = intToStr(len(vals));____BAH_COMPILER_VAR_1475[2] = "\04\0\0\0"") * ";____BAH_COMPILER_VAR_1475[1] = string__str(&____BAH_COMPILER_VAR_1474);____BAH_COMPILER_VAR_1475[0] = "\016\0\0\0""alloca(sizeof(";char * ____BAH_COMPILER_VAR_1476 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1475, 5);char * v = registerRCPvar(type,____BAH_COMPILER_VAR_1476,elems);

#line 1146 "/home/alois/Documents/bah-bah/src/values.bah"
char * r = "\0\0\0\0""";

#line 1147 "/home/alois/Documents/bah-bah/src/values.bah"
i = 0;

#line 1147 "/home/alois/Documents/bah-bah/src/values.bah"
for (; (i<len(vals)); 
#line 1147 "/home/alois/Documents/bah-bah/src/values.bah"
++i) {

#line 1148 "/home/alois/Documents/bah-bah/src/values.bah"
char** ____BAH_COMPILER_VAR_1477 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_1477[5] = "\01\0\0\0"";";____BAH_COMPILER_VAR_1477[4] = vals->data[i];____BAH_COMPILER_VAR_1477[3] = "\04\0\0\0""] = ";____BAH_COMPILER_VAR_1477[2] = intToStr(i);____BAH_COMPILER_VAR_1477[1] = "\01\0\0\0""[";____BAH_COMPILER_VAR_1477[0] = v;char * ____BAH_COMPILER_VAR_1478 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1477, 6);char** ____BAH_COMPILER_VAR_1479 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1479[1] = ____BAH_COMPILER_VAR_1478;____BAH_COMPILER_VAR_1479[0] = r;char * ____BAH_COMPILER_VAR_1480 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1479, 2);r = ____BAH_COMPILER_VAR_1480;
};

#line 1151 "/home/alois/Documents/bah-bah/src/values.bah"
if (isGlobal()) {

#line 1152 "/home/alois/Documents/bah-bah/src/values.bah"
INIT = rope__add(INIT, rope(r));
}

#line 1153 "/home/alois/Documents/bah-bah/src/values.bah"
else {

#line 1154 "/home/alois/Documents/bah-bah/src/values.bah"
OUTPUT = rope__add(OUTPUT, rope(r));
}

#line 1157 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok ____BAH_COMPILER_VAR_1481 = {};
____BAH_COMPILER_VAR_1481.cont = "\0\0\0\0""";
____BAH_COMPILER_VAR_1481.ogCont = "\0\0\0\0""";
____BAH_COMPILER_VAR_1481.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1481.line = 1;
____BAH_COMPILER_VAR_1481.begLine = 1;
____BAH_COMPILER_VAR_1481.bahType = "\0\0\0\0""";
____BAH_COMPILER_VAR_1481.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_1481.bahType = type;
____BAH_COMPILER_VAR_1481.cont = v;

    unsigned int ____BAH_COMPILER_VAR_1482 = tokPos;
    __Bah_realocate_arr(l, ____BAH_COMPILER_VAR_1482);
    l->data[____BAH_COMPILER_VAR_1482] = ____BAH_COMPILER_VAR_1481;

#line 1163 "/home/alois/Documents/bah-bah/src/values.bah"
return tokPos;
};

#line 1166 "/home/alois/Documents/bah-bah/src/values.bah"
char isSmallValue(__BAH_ARR_TYPE_Tok l,long int i){

#line 1167 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok t = l->data[i];

#line 1168 "/home/alois/Documents/bah-bah/src/values.bah"
if ((t.type==TOKEN_TYPE_CAST)||(strcmp(t.cont, "\01\0\0\0""(") == 0)) {

#line 1169 "/home/alois/Documents/bah-bah/src/values.bah"
return false;
}

#line 1170 "/home/alois/Documents/bah-bah/src/values.bah"
else if (__builtin_expect((t.isValue==false), 0)) {

#line 1171 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&t,"\034\0\0\0""Cannot use {TOKEN} as value.");
}

#line 1173 "/home/alois/Documents/bah-bah/src/values.bah"
if ((i+1<len(l))) {

#line 1174 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok nt = l->data[i+1];

#line 1175 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(nt.cont, "\01\0\0\0""[") == 0)||(strcmp(nt.cont, "\01\0\0\0"".") == 0)||(strcmp(nt.cont, "\01\0\0\0""(") == 0)) {

#line 1176 "/home/alois/Documents/bah-bah/src/values.bah"
return false;
}
}

#line 1179 "/home/alois/Documents/bah-bah/src/values.bah"
return true;
};

#line 1182 "/home/alois/Documents/bah-bah/src/values.bah"
char ____BAH_COMPILER_VAR_1483(array(char *)* arr, char * el) {
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

#line 1183 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok t = l->data[i];

#line 1184 "/home/alois/Documents/bah-bah/src/values.bah"
if ((t.type==TOKEN_TYPE_CAST)||(strcmp(t.cont, "\01\0\0\0""(") == 0)) {

#line 1185 "/home/alois/Documents/bah-bah/src/values.bah"
return false;
}

#line 1186 "/home/alois/Documents/bah-bah/src/values.bah"
else if (__builtin_expect((t.isValue==false), 0)) {

#line 1187 "/home/alois/Documents/bah-bah/src/values.bah"
throwErr(&t,"\034\0\0\0""Cannot use {TOKEN} as value.");
}

#line 1189 "/home/alois/Documents/bah-bah/src/values.bah"
if ((i+1<len(l))) {

#line 1190 "/home/alois/Documents/bah-bah/src/values.bah"
struct Tok nt = l->data[i+1];

#line 1191 "/home/alois/Documents/bah-bah/src/values.bah"
if ((strcmp(nt.cont, "\01\0\0\0""[") == 0)||(strcmp(nt.cont, "\01\0\0\0"".") == 0)||(strcmp(nt.cont, "\01\0\0\0""(") == 0)||____BAH_COMPILER_VAR_1483(signs, nt.cont)||(nt.isValue&&(nt.cont[0+4]==45))) {

#line 1192 "/home/alois/Documents/bah-bah/src/values.bah"
return false;
}
}

#line 1195 "/home/alois/Documents/bah-bah/src/values.bah"
return true;
};

#line 2998 "/home/alois/Documents/bah-bah/src/parser.bah"
char ____BAH_COMPILER_VAR_1491(array(char *)* arr, char * el) {
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
char ____BAH_COMPILER_VAR_1498(array(char *)* arr, char * el) {
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
if ((strcmp(t.cont, "\01\0\0\0""(") == 0)) {

#line 3009 "/home/alois/Documents/bah-bah/src/parser.bah"
char isFunc = true;

#line 3010 "/home/alois/Documents/bah-bah/src/parser.bah"
nbPar = nbPar+1;
}

#line 3011 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(t.cont, "\01\0\0\0"")") == 0)) {

#line 3012 "/home/alois/Documents/bah-bah/src/parser.bah"
nbPar = nbPar-1;
}

#line 3013 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((nbPar==0)&&(strcmp(t.cont, "\01\0\0\0""{") == 0)) {

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
struct Tok ____BAH_COMPILER_VAR_1484 = {};
____BAH_COMPILER_VAR_1484.cont = "\0\0\0\0""";
____BAH_COMPILER_VAR_1484.ogCont = "\0\0\0\0""";
____BAH_COMPILER_VAR_1484.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1484.line = 1;
____BAH_COMPILER_VAR_1484.begLine = 1;
____BAH_COMPILER_VAR_1484.bahType = "\0\0\0\0""";
struct Tok pt = ____BAH_COMPILER_VAR_1484;

#line 3026 "/home/alois/Documents/bah-bah/src/parser.bah"
unsigned long int l = len(fl);

#line 3028 "/home/alois/Documents/bah-bah/src/parser.bah"
i = 0;

#line 3028 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<len(fl)); 
#line 3028 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 3029 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = fl->data[i];

#line 3030 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((t.type==TOKEN_TYPE_VAR)&&(t.isOper==false)&&(t.cont[0+4]==38)) {

#line 3031 "/home/alois/Documents/bah-bah/src/parser.bah"
struct string tc = string(t.cont);

#line 3032 "/home/alois/Documents/bah-bah/src/parser.bah"
string__trimLeft(&tc,1);

#line 3033 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ____BAH_COMPILER_VAR_1485 =string__str(&tc);struct variable* rv = getRealVar(____BAH_COMPILER_VAR_1485,elems);

#line 3034 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((rv!=null)&&(rv->canBeReg==true)&&(rv->declRope!=null)) {

#line 3035 "/home/alois/Documents/bah-bah/src/parser.bah"
char * rvdr = rope__toStr(rv->declRope);

#line 3036 "/home/alois/Documents/bah-bah/src/parser.bah"
if (strHasPrefix(rvdr,"\011\0\0\0""register ")) {

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
if ((fl->data[i].cont[0+4]==42)) {

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
struct Tok ____BAH_COMPILER_VAR_1486 = {};
____BAH_COMPILER_VAR_1486.cont = "\0\0\0\0""";
____BAH_COMPILER_VAR_1486.ogCont = "\0\0\0\0""";
____BAH_COMPILER_VAR_1486.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_1486.line = 1;
____BAH_COMPILER_VAR_1486.begLine = 1;
____BAH_COMPILER_VAR_1486.bahType = "\0\0\0\0""";
pt = ____BAH_COMPILER_VAR_1486;
}

#line 3068 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "\01\0\0\0"".") == 0)&&(i>0)) {

#line 3069 "/home/alois/Documents/bah-bah/src/parser.bah"
i = valueStruct(fl,i,ltp,elems)-1;
}

#line 3070 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(t.cont, "\01\0\0\0""(") == 0)&&(strcmp(pt.cont, "\010\0\0\0""function") != 0)) {

#line 3071 "/home/alois/Documents/bah-bah/src/parser.bah"
i = valueFunc(null,null,fl,i,ltp,elems)-1;
}

#line 3072 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(t.cont, "\01\0\0\0""[") == 0)&&(pt.isValue==true)) {

#line 3073 "/home/alois/Documents/bah-bah/src/parser.bah"
i = valueArr(fl,i,ltp,elems)-1;
}

#line 3074 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(t.cont, "\01\0\0\0""[") == 0)) {

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
char * ____BAH_COMPILER_VAR_1487 =string__str(&ptc);struct string cType = getCType(____BAH_COMPILER_VAR_1487,elems);

#line 3087 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1488 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1488[3] = t.cont;____BAH_COMPILER_VAR_1488[2] = "\01\0\0\0"")";____BAH_COMPILER_VAR_1488[1] = string__str(&cType);____BAH_COMPILER_VAR_1488[0] = "\01\0\0\0""(";char * ____BAH_COMPILER_VAR_1489 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1488, 4);t.cont = ____BAH_COMPILER_VAR_1489;

#line 3088 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1490 = i-1;
    __Bah_realocate_arr(fl, ____BAH_COMPILER_VAR_1490);
    fl->data[____BAH_COMPILER_VAR_1490] = t;

#line 3089 "/home/alois/Documents/bah-bah/src/parser.bah"
i = i-2;
}

#line 3090 "/home/alois/Documents/bah-bah/src/parser.bah"
else if (____BAH_COMPILER_VAR_1491(signs, pt.cont)) {

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
char** ____BAH_COMPILER_VAR_1492 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1492[2] = ppt.cont;____BAH_COMPILER_VAR_1492[1] = t.cont;____BAH_COMPILER_VAR_1492[0] = t.cont;char * ____BAH_COMPILER_VAR_1493 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1492, 3);ppt.cont = ____BAH_COMPILER_VAR_1493;

#line 3097 "/home/alois/Documents/bah-bah/src/parser.bah"
ppt.isValue = true;

#line 3098 "/home/alois/Documents/bah-bah/src/parser.bah"
ppt.isOper = true;

#line 3099 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1494 = posTok;
    __Bah_realocate_arr(fl, ____BAH_COMPILER_VAR_1494);
    fl->data[____BAH_COMPILER_VAR_1494] = ppt;

#line 3100 "/home/alois/Documents/bah-bah/src/parser.bah"
i = posTok-1;
}

#line 3101 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 3102 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&ppt,"\066\0\0\0""Cannot increment/decrement non variable value {TOKEN}.");
}
}

#line 3104 "/home/alois/Documents/bah-bah/src/parser.bah"
else if (isValue(fl,i)) {

#line 3105 "/home/alois/Documents/bah-bah/src/parser.bah"
i = valueOper(fl,i,elems)-1;
}
}

#line 3107 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((t.cont[0+4]==45)&&(pt.isValue==true)) {

#line 3108 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((t.type==TOKEN_TYPE_INT)||(t.type==TOKEN_TYPE_FLOAT)) {

#line 3109 "/home/alois/Documents/bah-bah/src/parser.bah"
delete(fl,i);

#line 3110 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ptt = getTypeFromToken(&pt,true,elems);

#line 3111 "/home/alois/Documents/bah-bah/src/parser.bah"
pt.bahType = ptt;

#line 3112 "/home/alois/Documents/bah-bah/src/parser.bah"
pt.isOper = true;

#line 3113 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1495 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1495[1] = t.cont;____BAH_COMPILER_VAR_1495[0] = pt.cont;char * ____BAH_COMPILER_VAR_1496 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1495, 2);pt.cont = ____BAH_COMPILER_VAR_1496;

#line 3114 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1497 = i-1;
    __Bah_realocate_arr(fl, ____BAH_COMPILER_VAR_1497);
    fl->data[____BAH_COMPILER_VAR_1497] = pt;

#line 3115 "/home/alois/Documents/bah-bah/src/parser.bah"
i = i-2;
}
}

#line 3117 "/home/alois/Documents/bah-bah/src/parser.bah"
else if (____BAH_COMPILER_VAR_1498(comparators, pt.cont)&&isValue(fl,i)) {

#line 3118 "/home/alois/Documents/bah-bah/src/parser.bah"
i = valueBool(fl,i,ltp,elems)-1;
}

#line 3119 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(pt.cont, "\02\0\0\0""<-") == 0)&&isValue(fl,i)) {

#line 3120 "/home/alois/Documents/bah-bah/src/parser.bah"
i = valueChan(fl,i,elems)-1;
}

#line 3121 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(pt.cont, "\02\0\0\0""->") == 0)&&isValue(fl,i)) {

#line 3122 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((i-2>=0)) {

#line 3123 "/home/alois/Documents/bah-bah/src/parser.bah"
if (isValue(fl,i-2)) {

#line 3124 "/home/alois/Documents/bah-bah/src/parser.bah"
i = valueSendChan(fl,i,elems)-1;
}
}

#line 3126 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 3127 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"\044\0\0\0""Cannot {TOKEN} nothing through chan.");
}
}
};

#line 3133 "/home/alois/Documents/bah-bah/src/parser.bah"
i = 0;

#line 3133 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (i<len(fl)); 
#line 3133 "/home/alois/Documents/bah-bah/src/parser.bah"
++i) {

#line 3134 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = fl->data[i];

#line 3135 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "\02\0\0\0""||") == 0)||(strcmp(t.cont, "\02\0\0\0""&&") == 0)) {

#line 3136 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((i==0)||(i+1==len(fl)), 0)) {

#line 3137 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"\036\0\0\0""Cannot use {TOKEN} on nothing.");
}

#line 3139 "/home/alois/Documents/bah-bah/src/parser.bah"
pt = fl->data[i-1];

#line 3140 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok nt = fl->data[i+1];

#line 3141 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ptt = getTypeFromToken(&pt,true,elems);

#line 3142 "/home/alois/Documents/bah-bah/src/parser.bah"
char * ntt = getTypeFromToken(&nt,true,elems);

#line 3143 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((compTypes(ptt,ntt)==false)||(compTypes(ptt,"\04\0\0\0""bool")==false), 0)) {

#line 3144 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1499 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1499[2] = "\01\0\0\0"".";____BAH_COMPILER_VAR_1499[1] = ptt;____BAH_COMPILER_VAR_1499[0] = "\026\0\0\0""Cannot use {TOKEN} on ";char * ____BAH_COMPILER_VAR_1500 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1499, 3);throwErr(&t,____BAH_COMPILER_VAR_1500);
}

#line 3147 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "\02\0\0\0""||") == 0)&&(isExprExpensive(&pt)==false)&&(isExprExpensive(&nt)==false)) {

#line 3148 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1501 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1501[1] = nt.cont;____BAH_COMPILER_VAR_1501[0] = "\02\0\0\0""||";char * ____BAH_COMPILER_VAR_1502 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1501, 2);char** ____BAH_COMPILER_VAR_1503 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1503[1] = ____BAH_COMPILER_VAR_1502;____BAH_COMPILER_VAR_1503[0] = pt.cont;char * ____BAH_COMPILER_VAR_1504 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1503, 2);pt.cont = ____BAH_COMPILER_VAR_1504;
}

#line 3149 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 3150 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1505 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1505[1] = nt.cont;____BAH_COMPILER_VAR_1505[0] = t.cont;char * ____BAH_COMPILER_VAR_1506 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1505, 2);char** ____BAH_COMPILER_VAR_1507 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1507[1] = ____BAH_COMPILER_VAR_1506;____BAH_COMPILER_VAR_1507[0] = pt.cont;char * ____BAH_COMPILER_VAR_1508 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1507, 2);pt.cont = ____BAH_COMPILER_VAR_1508;
}

#line 3152 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1509 = i-1;
    __Bah_realocate_arr(fl, ____BAH_COMPILER_VAR_1509);
    fl->data[____BAH_COMPILER_VAR_1509] = pt;

#line 3153 "/home/alois/Documents/bah-bah/src/parser.bah"
deleteRange(fl,i,i+1);

#line 3154 "/home/alois/Documents/bah-bah/src/parser.bah"
i = i-2;
}

#line 3155 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((t.type==TOKEN_TYPE_VAR)&&(t.cont[0+4]==38)) {

#line 3156 "/home/alois/Documents/bah-bah/src/parser.bah"
char * tt = getTypeFromToken(&t,true,elems);

#line 3157 "/home/alois/Documents/bah-bah/src/parser.bah"

                struct string ____BAH_COMPILER_VAR_1510 = string(tt);
                if (__builtin_expect(string__hasPrefix(&____BAH_COMPILER_VAR_1510,"\06\0\0\0""tuple:"), 0)) {

#line 3158 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&t,"\046\0\0\0""Cannot get pointer of a tuple {TOKEN}.");
}
}
};

#line 3163 "/home/alois/Documents/bah-bah/src/parser.bah"
fl = parseArrayType(fl,elems,true);

#line 3164 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((RCPavailable()==true)) {

#line 3165 "/home/alois/Documents/bah-bah/src/parser.bah"
addRCPvars(fl,ltp,elems);
}

#line 3168 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((ltp!=(lineType)-1)) {

#line 3169 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((sepI<len(line))) {

#line 3170 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1511 = len(fl);
    __Bah_realocate_arr(fl, ____BAH_COMPILER_VAR_1511);
    fl->data[____BAH_COMPILER_VAR_1511] = line->data[sepI];

#line 3171 "/home/alois/Documents/bah-bah/src/parser.bah"
++sepI;
};
}

#line 3177 "/home/alois/Documents/bah-bah/src/parser.bah"
return fl;
};

#line 3180 "/home/alois/Documents/bah-bah/src/parser.bah"
void parseFnDeclare(__BAH_ARR_TYPE_Tok l,struct Elems* elems){

#line 3181 "/home/alois/Documents/bah-bah/src/parser.bah"
long int i = 0;

#line 3182 "/home/alois/Documents/bah-bah/src/parser.bah"
struct func* ____BAH_COMPILER_VAR_1512 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_1512->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_1512->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_1512->args->length = 0;
            ____BAH_COMPILER_VAR_1512->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_1512->from = "\0\0\0\0""";
____BAH_COMPILER_VAR_1512->file = "\0\0\0\0""";
____BAH_COMPILER_VAR_1512->line = 1;
struct func* fn = ____BAH_COMPILER_VAR_1512;

#line 3184 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((RCPavailable()==false)&&(RCPenabled==true)) {

#line 3185 "/home/alois/Documents/bah-bah/src/parser.bah"
fn->used = true;
}

#line 3188 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok ft = l->data[0];

#line 3189 "/home/alois/Documents/bah-bah/src/parser.bah"
char * code = parseFnHeader("\0\0\0\0""",l,&i,fn,elems);

#line 3190 "/home/alois/Documents/bah-bah/src/parser.bah"
fn->line = ft.line;

#line 3191 "/home/alois/Documents/bah-bah/src/parser.bah"
fn->file = compilerState.currentFile;

#line 3192 "/home/alois/Documents/bah-bah/src/parser.bah"
struct func* ogFn = searchFunc(fn->name,elems,false);

#line 3193 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((ogFn!=null)) {

#line 3194 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((ogFn->isBinding==false), 0)) {

#line 3195 "/home/alois/Documents/bah-bah/src/parser.bah"
char * lineStr = intToStr(ogFn->line);

#line 3196 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1513 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1513[4] = "\01\0\0\0"".";____BAH_COMPILER_VAR_1513[3] = lineStr;____BAH_COMPILER_VAR_1513[2] = "\01\0\0\0"":";____BAH_COMPILER_VAR_1513[1] = ogFn->file;____BAH_COMPILER_VAR_1513[0] = "\071\0\0\0""Cannot redeclare function {TOKEN}, previous declaration: ";char * ____BAH_COMPILER_VAR_1514 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1513, 5);throwErr(&ft,____BAH_COMPILER_VAR_1514);
}
}

#line 3200 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(fn->name, "\04\0\0\0""main") == 0)) {

#line 3201 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.haveEntryPoint = true;

#line 3202 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((compTypes(fn->returns->type,"\03\0\0\0""int")==false), 0)) {

#line 3203 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&ft,"\045\0\0\0""{TOKEN} function should return 'int'.");
}

#line 3205 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((len(fn->args)!=1), 0)) {

#line 3206 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&ft,"\151\0\0\0""{TOKEN} function should take one []cpstring argument. Should be: \n            'main(args []cpstring) int'");
}

#line 3209 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* fa = fn->args->data[0];

#line 3210 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((compTypes(fa->type,"\012\0\0\0""[]cpstring")==false), 0)) {

#line 3211 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&ft,"\150\0\0\0""{TOKEN} function should take []cpstring as argument. Should be: \n            'main(args []cpstring) int'");
}
}

#line 3216 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((debug==true)) {

#line 3217 "/home/alois/Documents/bah-bah/src/parser.bah"
struct debugFunction* ____BAH_COMPILER_VAR_1515 = memoryAlloc(sizeof(struct debugFunction));
____BAH_COMPILER_VAR_1515->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_1515->args->length = 0;
            ____BAH_COMPILER_VAR_1515->args->elemSize = sizeof(struct variable*);
            struct debugFunction* df = ____BAH_COMPILER_VAR_1515;

#line 3218 "/home/alois/Documents/bah-bah/src/parser.bah"
df->name = fn->name;

#line 3219 "/home/alois/Documents/bah-bah/src/parser.bah"
df->args = fn->args;

#line 3220 "/home/alois/Documents/bah-bah/src/parser.bah"
df->returns = fn->returns->type;

#line 3221 "/home/alois/Documents/bah-bah/src/parser.bah"
struct debugFunction* ____BAH_COMPILER_VAR_1516 = df;
char ** ____BAH_COMPILER_VAR_1518 = (char **)((char*)(____BAH_COMPILER_VAR_1516) + offsetof(struct debugFunction, name));
struct reflectElement ____BAH_COMPILER_VAR_1519 = __reflect(____BAH_COMPILER_VAR_1518, sizeof(char *), "\010\0\0\0""cpstring", "\04\0\0\0""name", 0, 0, 0, 0, offsetof(struct debugFunction, name));
char ** ____BAH_COMPILER_VAR_1520 = (char **)((char*)(____BAH_COMPILER_VAR_1516) + offsetof(struct debugFunction, returns));
struct reflectElement ____BAH_COMPILER_VAR_1521 = __reflect(____BAH_COMPILER_VAR_1520, sizeof(char *), "\010\0\0\0""cpstring", "\07\0\0\0""returns", 0, 0, 0, 0, offsetof(struct debugFunction, returns));
array(struct variable*)** ____BAH_COMPILER_VAR_1522 = (array(struct variable*)**)((char*)(____BAH_COMPILER_VAR_1516) + offsetof(struct debugFunction, args));
struct variable** ____BAH_COMPILER_VAR_1523 = 0;
char ** ____BAH_COMPILER_VAR_1525 = (char **)((char*)(____BAH_COMPILER_VAR_1523) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_1526 = __reflect(____BAH_COMPILER_VAR_1525, sizeof(char *), "\010\0\0\0""cpstring", "\04\0\0\0""name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_1527 = (char **)((char*)(____BAH_COMPILER_VAR_1523) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_1528 = __reflect(____BAH_COMPILER_VAR_1527, sizeof(char *), "\010\0\0\0""cpstring", "\04\0\0\0""type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_1529 = (char*)((char*)(____BAH_COMPILER_VAR_1523) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_1530 = __reflect(____BAH_COMPILER_VAR_1529, sizeof(char), "\04\0\0\0""bool", "\07\0\0\0""isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_1531 = (char **)((char*)(____BAH_COMPILER_VAR_1523) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_1532 = __reflect(____BAH_COMPILER_VAR_1531, sizeof(char *), "\010\0\0\0""cpstring", "\010\0\0\0""constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_1533 = (char*)((char*)(____BAH_COMPILER_VAR_1523) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_1534 = __reflect(____BAH_COMPILER_VAR_1533, sizeof(char), "\04\0\0\0""bool", "\07\0\0\0""isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_1535 = (char **)((char*)(____BAH_COMPILER_VAR_1523) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_1536 = __reflect(____BAH_COMPILER_VAR_1535, sizeof(char *), "\010\0\0\0""cpstring", "\04\0\0\0""from", 0, 0, 0, 0, offsetof(struct variable, from));
void ** ____BAH_COMPILER_VAR_1537 = (void **)((char*)(____BAH_COMPILER_VAR_1523) + offsetof(struct variable, declScope));
struct reflectElement ____BAH_COMPILER_VAR_1538 = __reflect(____BAH_COMPILER_VAR_1537, sizeof(void *), "\03\0\0\0""ptr", "\011\0\0\0""declScope", 0, 0, 0, 0, offsetof(struct variable, declScope));
char* ____BAH_COMPILER_VAR_1539 = (char*)((char*)(____BAH_COMPILER_VAR_1523) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_1540 = __reflect(____BAH_COMPILER_VAR_1539, sizeof(char), "\04\0\0\0""bool", "\010\0\0\0""isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));
struct rope** ____BAH_COMPILER_VAR_1541 = (struct rope**)((char*)(____BAH_COMPILER_VAR_1523) + offsetof(struct variable, declRope));
void ** ____BAH_COMPILER_VAR_1543 = (void **)((char*)(____BAH_COMPILER_VAR_1541) + offsetof(struct rope, left));
struct reflectElement ____BAH_COMPILER_VAR_1544 = __reflect(____BAH_COMPILER_VAR_1543, sizeof(void *), "\03\0\0\0""ptr", "\04\0\0\0""left", 0, 0, 0, 0, offsetof(struct rope, left));
void ** ____BAH_COMPILER_VAR_1545 = (void **)((char*)(____BAH_COMPILER_VAR_1541) + offsetof(struct rope, right));
struct reflectElement ____BAH_COMPILER_VAR_1546 = __reflect(____BAH_COMPILER_VAR_1545, sizeof(void *), "\03\0\0\0""ptr", "\05\0\0\0""right", 0, 0, 0, 0, offsetof(struct rope, right));
char ** ____BAH_COMPILER_VAR_1547 = (char **)((char*)(____BAH_COMPILER_VAR_1541) + offsetof(struct rope, str));
struct reflectElement ____BAH_COMPILER_VAR_1548 = __reflect(____BAH_COMPILER_VAR_1547, sizeof(char *), "\010\0\0\0""cpstring", "\03\0\0\0""str", 0, 0, 0, 0, offsetof(struct rope, str));
int* ____BAH_COMPILER_VAR_1549 = (int*)((char*)(____BAH_COMPILER_VAR_1541) + offsetof(struct rope, lCount));
struct reflectElement ____BAH_COMPILER_VAR_1550 = __reflect(____BAH_COMPILER_VAR_1549, sizeof(int), "\05\0\0\0""int32", "\06\0\0\0""lCount", 0, 0, 0, 0, offsetof(struct rope, lCount));
int* ____BAH_COMPILER_VAR_1551 = (int*)((char*)(____BAH_COMPILER_VAR_1541) + offsetof(struct rope, len));
struct reflectElement ____BAH_COMPILER_VAR_1552 = __reflect(____BAH_COMPILER_VAR_1551, sizeof(int), "\05\0\0\0""int32", "\03\0\0\0""len", 0, 0, 0, 0, offsetof(struct rope, len));
int* ____BAH_COMPILER_VAR_1553 = (int*)((char*)(____BAH_COMPILER_VAR_1541) + offsetof(struct rope, totalLen));
struct reflectElement ____BAH_COMPILER_VAR_1554 = __reflect(____BAH_COMPILER_VAR_1553, sizeof(int), "\05\0\0\0""int32", "\010\0\0\0""totalLen", 0, 0, 0, 0, offsetof(struct rope, totalLen));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_1542 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_1542->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_1542->length = 6;
        ____BAH_COMPILER_VAR_1542->data = memoryAlloc(____BAH_COMPILER_VAR_1542->length * ____BAH_COMPILER_VAR_1542->elemSize);
        ____BAH_COMPILER_VAR_1542->data[0] = ____BAH_COMPILER_VAR_1544;
____BAH_COMPILER_VAR_1542->data[1] = ____BAH_COMPILER_VAR_1546;
____BAH_COMPILER_VAR_1542->data[2] = ____BAH_COMPILER_VAR_1548;
____BAH_COMPILER_VAR_1542->data[3] = ____BAH_COMPILER_VAR_1550;
____BAH_COMPILER_VAR_1542->data[4] = ____BAH_COMPILER_VAR_1552;
____BAH_COMPILER_VAR_1542->data[5] = ____BAH_COMPILER_VAR_1554;
struct reflectElement ____BAH_COMPILER_VAR_1555 = __reflect(____BAH_COMPILER_VAR_1541, sizeof(struct rope), "\05\0\0\0""rope*", "\010\0\0\0""declRope", 0, 0, 1, ____BAH_COMPILER_VAR_1542, offsetof(struct variable, declRope));
char* ____BAH_COMPILER_VAR_1556 = (char*)((char*)(____BAH_COMPILER_VAR_1523) + offsetof(struct variable, canBeNull));
struct reflectElement ____BAH_COMPILER_VAR_1557 = __reflect(____BAH_COMPILER_VAR_1556, sizeof(char), "\04\0\0\0""bool", "\011\0\0\0""canBeNull", 0, 0, 0, 0, offsetof(struct variable, canBeNull));
void ** ____BAH_COMPILER_VAR_1558 = (void **)((char*)(____BAH_COMPILER_VAR_1523) + offsetof(struct variable, iterScope));
struct reflectElement ____BAH_COMPILER_VAR_1559 = __reflect(____BAH_COMPILER_VAR_1558, sizeof(void *), "\03\0\0\0""ptr", "\011\0\0\0""iterScope", 0, 0, 0, 0, offsetof(struct variable, iterScope));
char* ____BAH_COMPILER_VAR_1560 = (char*)((char*)(____BAH_COMPILER_VAR_1523) + offsetof(struct variable, canBeReg));
struct reflectElement ____BAH_COMPILER_VAR_1561 = __reflect(____BAH_COMPILER_VAR_1560, sizeof(char), "\04\0\0\0""bool", "\010\0\0\0""canBeReg", 0, 0, 0, 0, offsetof(struct variable, canBeReg));
char* ____BAH_COMPILER_VAR_1562 = (char*)((char*)(____BAH_COMPILER_VAR_1523) + offsetof(struct variable, isReg));
struct reflectElement ____BAH_COMPILER_VAR_1563 = __reflect(____BAH_COMPILER_VAR_1562, sizeof(char), "\04\0\0\0""bool", "\05\0\0\0""isReg", 0, 0, 0, 0, offsetof(struct variable, isReg));
void ** ____BAH_COMPILER_VAR_1564 = (void **)((char*)(____BAH_COMPILER_VAR_1523) + offsetof(struct variable, lastSet));
struct reflectElement ____BAH_COMPILER_VAR_1565 = __reflect(____BAH_COMPILER_VAR_1564, sizeof(void *), "\03\0\0\0""ptr", "\07\0\0\0""lastSet", 0, 0, 0, 0, offsetof(struct variable, lastSet));
char* ____BAH_COMPILER_VAR_1566 = (char*)((char*)(____BAH_COMPILER_VAR_1523) + offsetof(struct variable, isArg));
struct reflectElement ____BAH_COMPILER_VAR_1567 = __reflect(____BAH_COMPILER_VAR_1566, sizeof(char), "\04\0\0\0""bool", "\05\0\0\0""isArg", 0, 0, 0, 0, offsetof(struct variable, isArg));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_1524 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_1524->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_1524->length = 15;
        ____BAH_COMPILER_VAR_1524->data = memoryAlloc(____BAH_COMPILER_VAR_1524->length * ____BAH_COMPILER_VAR_1524->elemSize);
        ____BAH_COMPILER_VAR_1524->data[0] = ____BAH_COMPILER_VAR_1526;
____BAH_COMPILER_VAR_1524->data[1] = ____BAH_COMPILER_VAR_1528;
____BAH_COMPILER_VAR_1524->data[2] = ____BAH_COMPILER_VAR_1530;
____BAH_COMPILER_VAR_1524->data[3] = ____BAH_COMPILER_VAR_1532;
____BAH_COMPILER_VAR_1524->data[4] = ____BAH_COMPILER_VAR_1534;
____BAH_COMPILER_VAR_1524->data[5] = ____BAH_COMPILER_VAR_1536;
____BAH_COMPILER_VAR_1524->data[6] = ____BAH_COMPILER_VAR_1538;
____BAH_COMPILER_VAR_1524->data[7] = ____BAH_COMPILER_VAR_1540;
____BAH_COMPILER_VAR_1524->data[8] = ____BAH_COMPILER_VAR_1555;
____BAH_COMPILER_VAR_1524->data[9] = ____BAH_COMPILER_VAR_1557;
____BAH_COMPILER_VAR_1524->data[10] = ____BAH_COMPILER_VAR_1559;
____BAH_COMPILER_VAR_1524->data[11] = ____BAH_COMPILER_VAR_1561;
____BAH_COMPILER_VAR_1524->data[12] = ____BAH_COMPILER_VAR_1563;
____BAH_COMPILER_VAR_1524->data[13] = ____BAH_COMPILER_VAR_1565;
____BAH_COMPILER_VAR_1524->data[14] = ____BAH_COMPILER_VAR_1567;
struct reflectElement ____BAH_COMPILER_VAR_1568 = __reflect(____BAH_COMPILER_VAR_1523, sizeof(struct variable), "\011\0\0\0""variable*", "\0\0\0\0""", 0, 0, 1, ____BAH_COMPILER_VAR_1524, 0);

        struct reflectElement ____BAH_COMPILER_VAR_1569 = ____BAH_COMPILER_VAR_1568;
        struct reflectElement ____BAH_COMPILER_VAR_1570 = __reflect(____BAH_COMPILER_VAR_1522, sizeof(array(struct variable*)*), "\013\0\0\0""[]variable*", "\04\0\0\0""args", 1, &____BAH_COMPILER_VAR_1569, 0, 0, offsetof(struct debugFunction, args));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_1517 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_1517->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_1517->length = 3;
        ____BAH_COMPILER_VAR_1517->data = memoryAlloc(____BAH_COMPILER_VAR_1517->length * ____BAH_COMPILER_VAR_1517->elemSize);
        ____BAH_COMPILER_VAR_1517->data[0] = ____BAH_COMPILER_VAR_1519;
____BAH_COMPILER_VAR_1517->data[1] = ____BAH_COMPILER_VAR_1521;
____BAH_COMPILER_VAR_1517->data[2] = ____BAH_COMPILER_VAR_1570;
struct reflectElement ____BAH_COMPILER_VAR_1571 = __reflect(____BAH_COMPILER_VAR_1516, sizeof(struct debugFunction), "\016\0\0\0""debugFunction*", "\02\0\0\0""df", 0, 0, 1, ____BAH_COMPILER_VAR_1517, 0);
debugPrint("\012\0\0\0""fn_declare",ft.line,____BAH_COMPILER_VAR_1571);
}

#line 3224 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int j = 0;

#line 3224 "/home/alois/Documents/bah-bah/src/parser.bah"
for (; (j<len(fn->args)); 
#line 3224 "/home/alois/Documents/bah-bah/src/parser.bah"
++j) {

#line 3225 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(fn->args->data[j]->type, "\05\0\0\0""<any>") == 0)) {

#line 3226 "/home/alois/Documents/bah-bah/src/parser.bah"
struct genericFunc* ____BAH_COMPILER_VAR_1572 = memoryAlloc(sizeof(struct genericFunc));
____BAH_COMPILER_VAR_1572->tokens = memoryAlloc(sizeof(array(struct Tok)));
            ____BAH_COMPILER_VAR_1572->tokens->length = 0;
            ____BAH_COMPILER_VAR_1572->tokens->elemSize = sizeof(struct Tok);
            ____BAH_COMPILER_VAR_1572->declared = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_1572->declared->length = 0;
            ____BAH_COMPILER_VAR_1572->declared->elemSize = sizeof(struct func*);
            ____BAH_COMPILER_VAR_1572->tokens = arraySubstitute(l, i+1, len(l)-1);
____BAH_COMPILER_VAR_1572->baseFn = fn;
____BAH_COMPILER_VAR_1572->tokenName = &ft;

    unsigned int ____BAH_COMPILER_VAR_1573 = len(generics);
    __Bah_realocate_arr(generics, ____BAH_COMPILER_VAR_1573);
    generics->data[____BAH_COMPILER_VAR_1573] = ____BAH_COMPILER_VAR_1572;

#line 3231 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}
};

#line 3235 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((shouldOnlyDecl==true)) {

#line 3236 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((ogFn!=null)) {

#line 3237 "/home/alois/Documents/bah-bah/src/parser.bah"
fn->isBinding = false;
}

#line 3239 "/home/alois/Documents/bah-bah/src/parser.bah"
fn->isImported = true;

#line 3240 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1574 = len(elems->fns);
    __Bah_realocate_arr(elems->fns, ____BAH_COMPILER_VAR_1574);
    elems->fns->data[____BAH_COMPILER_VAR_1574] = fn;

#line 3241 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1575 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1575[1] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_1575[0] = code;char * ____BAH_COMPILER_VAR_1576 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1575, 2);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1576));

#line 3242 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}

#line 3245 "/home/alois/Documents/bah-bah/src/parser.bah"
postDeclHandle = rope("\0\0\0\0""");

#line 3246 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope__add(OUTPUT, postDeclHandle);

#line 3248 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1577 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1577[1] = "\02\0\0\0""{\n";____BAH_COMPILER_VAR_1577[0] = code;char * ____BAH_COMPILER_VAR_1578 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1577, 2);code = ____BAH_COMPILER_VAR_1578;

#line 3250 "/home/alois/Documents/bah-bah/src/parser.bah"
fn->code = rope(code);

#line 3253 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Elems* fnElems = dupElems(elems);

#line 3255 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct variable*)* vs = fnElems->vars;

#line 3256 "/home/alois/Documents/bah-bah/src/parser.bah"
j = 0;

#line 3256 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((j<len(fn->args))) {

#line 3257 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* a = fn->args->data[j];

#line 3258 "/home/alois/Documents/bah-bah/src/parser.bah"
a->declScope = elems;

#line 3259 "/home/alois/Documents/bah-bah/src/parser.bah"
a->isArg = true;

#line 3260 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1579 = len(vs);
    __Bah_realocate_arr(vs, ____BAH_COMPILER_VAR_1579);
    vs->data[____BAH_COMPILER_VAR_1579] = a;

#line 3261 "/home/alois/Documents/bah-bah/src/parser.bah"
j = j+1;
};

#line 3263 "/home/alois/Documents/bah-bah/src/parser.bah"
fnElems->vars = vs;

#line 3265 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((ogFn!=null)) {

#line 3266 "/home/alois/Documents/bah-bah/src/parser.bah"
ogFn->isBinding = false;

#line 3267 "/home/alois/Documents/bah-bah/src/parser.bah"
ogFn->used = true;

#line 3268 "/home/alois/Documents/bah-bah/src/parser.bah"
ogFn = fn;
}

#line 3269 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 3270 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct func*)* fns = elems->fns;

#line 3271 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1580 = len(fns);
    __Bah_realocate_arr(fns, ____BAH_COMPILER_VAR_1580);
    fns->data[____BAH_COMPILER_VAR_1580] = fn;
}

#line 3274 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 3275 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct Tok)* tokens = arraySubstitute(l, i, len(l)-1);

#line 3277 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((len(tokens)==0)) {

#line 3278 "/home/alois/Documents/bah-bah/src/parser.bah"
fn->code = rope__add(fn->code, rope("\03\0\0\0""};\n"));

#line 3279 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope__add(OUTPUT, fn->code);

#line 3280 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}

#line 3283 "/home/alois/Documents/bah-bah/src/parser.bah"
currentFn = fn;

#line 3285 "/home/alois/Documents/bah-bah/src/parser.bah"
struct rope* oOut = OUTPUT;

#line 3286 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope("\0\0\0\0""");

#line 3287 "/home/alois/Documents/bah-bah/src/parser.bah"
beginRCPscope(fnElems,fn->args);

#line 3288 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Elems* ocurrFnElems = compilerState.currFnElems;

#line 3289 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.currFnElems = fnElems;

#line 3290 "/home/alois/Documents/bah-bah/src/parser.bah"
parseLines(tokens,fnElems);

#line 3291 "/home/alois/Documents/bah-bah/src/parser.bah"
OPTI_checkFuncScopeRef(fnElems);

#line 3293 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.currFnElems = ocurrFnElems;

#line 3294 "/home/alois/Documents/bah-bah/src/parser.bah"
currentFn = null;

#line 3295 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((fn->returned==false)) {

#line 3296 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((strlen(fn->returns->type)>0), 0)) {

#line 3297 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1581 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1581[2] = "\022\0\0\0""' is not returned.";____BAH_COMPILER_VAR_1581[1] = fn->name;____BAH_COMPILER_VAR_1581[0] = "\012\0\0\0""Function '";char * ____BAH_COMPILER_VAR_1582 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1581, 3);throwErr(&l->data[len(l)-1],____BAH_COMPILER_VAR_1582);
}

#line 3299 "/home/alois/Documents/bah-bah/src/parser.bah"
endRCPscope(fnElems,fn->args);

#line 3300 "/home/alois/Documents/bah-bah/src/parser.bah"
fixMeEndScope(fnElems,&tokens->data[len(tokens)-1]);
}

#line 3304 "/home/alois/Documents/bah-bah/src/parser.bah"
fn->code = rope__add(fn->code, OUTPUT);

#line 3305 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = oOut;

#line 3306 "/home/alois/Documents/bah-bah/src/parser.bah"
fn->code = rope__add(fn->code, rope("\03\0\0\0""};\n"));

#line 3308 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((debug==true)) {

#line 3309 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok lt = l->data[len(l)-1];

#line 3310 "/home/alois/Documents/bah-bah/src/parser.bah"
debugEndScope(lt.line,fnElems);
}

#line 3313 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope__add(OUTPUT, fn->code);
};

#line 3318 "/home/alois/Documents/bah-bah/src/parser.bah"
void parseCapture(__BAH_ARR_TYPE_Tok line,struct Elems* elems){

#line 3319 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((len(line)<7), 0)) {

#line 3320 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&line->data[0],"\106\0\0\0""Invalid usage of {TOKEN} 'capture <var> = <maybe value> else {<code>}'");
}

#line 3323 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok varTok = line->data[1];

#line 3324 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok valTok = line->data[3];

#line 3325 "/home/alois/Documents/bah-bah/src/parser.bah"
char isThen = false;

#line 3327 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((varTok.type!=TOKEN_TYPE_VAR), 0)) {

#line 3328 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&varTok,"\037\0\0\0""Cannot use {TOKEN} as variable.");
}

#line 3332 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((strcmp(line->data[2].cont, "\01\0\0\0""=") != 0), 0)) {

#line 3333 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&line->data[2],"\031\0\0\0""Expected '=' got {TOKEN}.");
}

#line 3337 "/home/alois/Documents/bah-bah/src/parser.bah"
char * valType = getTypeFromToken(&valTok,true,elems);

#line 3338 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((valType[strlen(valType)-1+4]!=33), 0)) {

#line 3339 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1583 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1583[2] = "\021\0\0\0"") as maybe value.";____BAH_COMPILER_VAR_1583[1] = valType;____BAH_COMPILER_VAR_1583[0] = "\024\0\0\0""Cannot use {TOKEN} (";char * ____BAH_COMPILER_VAR_1584 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1583, 3);throwErr(&valTok,____BAH_COMPILER_VAR_1584);
}

#line 3341 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1585 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1585[1] = "\01\0\0\0""*";____BAH_COMPILER_VAR_1585[0] = cpstringSubsitute(valType, 0, strlen(valType)-1);char * ____BAH_COMPILER_VAR_1586 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1585, 2);char * newType = ____BAH_COMPILER_VAR_1586;

#line 3344 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((strcmp(line->data[4].cont, "\04\0\0\0""else") != 0)&&(strcmp(line->data[4].cont, "\04\0\0\0""then") != 0), 0)) {

#line 3345 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&line->data[4],"\046\0\0\0""Expected 'then' or 'else' got {TOKEN}.");
}

#line 3348 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(line->data[4].cont, "\04\0\0\0""then") == 0)) {

#line 3349 "/home/alois/Documents/bah-bah/src/parser.bah"
isThen = true;
}

#line 3353 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* v = searchVar(varTok.cont,elems);

#line 3354 "/home/alois/Documents/bah-bah/src/parser.bah"
char * code = "\0\0\0\0""";

#line 3355 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((v==null)) {

#line 3356 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* ____BAH_COMPILER_VAR_1587 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_1587->name = "\0\0\0\0""";
____BAH_COMPILER_VAR_1587->type = "\0\0\0\0""";
____BAH_COMPILER_VAR_1587->constVal = "\0\0\0\0""";
____BAH_COMPILER_VAR_1587->from = "\0\0\0\0""";
____BAH_COMPILER_VAR_1587->name = varTok.cont;
____BAH_COMPILER_VAR_1587->type = newType;
v = ____BAH_COMPILER_VAR_1587;

#line 3360 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1588 = len(elems->vars);
    __Bah_realocate_arr(elems->vars, ____BAH_COMPILER_VAR_1588);
    elems->vars->data[____BAH_COMPILER_VAR_1588] = v;

#line 3361 "/home/alois/Documents/bah-bah/src/parser.bah"

                struct string ____BAH_COMPILER_VAR_1589 = getCType(v->type,elems);
                char** ____BAH_COMPILER_VAR_1590 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1590[1] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_1590[0] = string__str(&____BAH_COMPILER_VAR_1589);char * ____BAH_COMPILER_VAR_1591 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1590, 2);code = ____BAH_COMPILER_VAR_1591;
}

#line 3362 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 3363 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((strcmp(v->type, newType) != 0), 0)) {

#line 3364 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1592 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1592[4] = "\01\0\0\0"".";____BAH_COMPILER_VAR_1592[3] = newType;____BAH_COMPILER_VAR_1592[2] = "\05\0\0\0"") as ";____BAH_COMPILER_VAR_1592[1] = v->type;____BAH_COMPILER_VAR_1592[0] = "\030\0\0\0""Cannot use var {TOKEN} (";char * ____BAH_COMPILER_VAR_1593 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1592, 5);throwErr(&varTok,____BAH_COMPILER_VAR_1593);
}
}

#line 3367 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1594 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1594[3] = "\01\0\0\0"";";____BAH_COMPILER_VAR_1594[2] = valTok.cont;____BAH_COMPILER_VAR_1594[1] = "\03\0\0\0"" = ";____BAH_COMPILER_VAR_1594[0] = v->name;char * ____BAH_COMPILER_VAR_1595 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1594, 4);char** ____BAH_COMPILER_VAR_1596 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1596[1] = ____BAH_COMPILER_VAR_1595;____BAH_COMPILER_VAR_1596[0] = code;char * ____BAH_COMPILER_VAR_1597 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1596, 2);code = ____BAH_COMPILER_VAR_1597;

#line 3369 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((isThen==true)) {

#line 3370 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1598 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1598[2] = "\013\0\0\0"" != null) {";____BAH_COMPILER_VAR_1598[1] = v->name;____BAH_COMPILER_VAR_1598[0] = "\04\0\0\0""if (";char * ____BAH_COMPILER_VAR_1599 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1598, 3);char** ____BAH_COMPILER_VAR_1600 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1600[1] = ____BAH_COMPILER_VAR_1599;____BAH_COMPILER_VAR_1600[0] = code;char * ____BAH_COMPILER_VAR_1601 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1600, 2);code = ____BAH_COMPILER_VAR_1601;
}

#line 3371 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 3372 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1602 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1602[2] = "\013\0\0\0"" == null) {";____BAH_COMPILER_VAR_1602[1] = v->name;____BAH_COMPILER_VAR_1602[0] = "\04\0\0\0""if (";char * ____BAH_COMPILER_VAR_1603 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1602, 3);char** ____BAH_COMPILER_VAR_1604 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1604[1] = ____BAH_COMPILER_VAR_1603;____BAH_COMPILER_VAR_1604[0] = code;char * ____BAH_COMPILER_VAR_1605 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1604, 2);code = ____BAH_COMPILER_VAR_1605;
}

#line 3375 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope__add(OUTPUT, rope(code));

#line 3377 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct Tok)* tokens = arraySubstitute(line, 6, len(line)-1);

#line 3379 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Elems* CaptElems = dupElems(elems);

#line 3381 "/home/alois/Documents/bah-bah/src/parser.bah"
parseLines(tokens,CaptElems);

#line 3383 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((isThen==true)) {

#line 3384 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope__add(OUTPUT, rope("\02\0\0\0""}\n"));
}

#line 3385 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 3386 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1606 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1606[4] = "\05\0\0\0""\");}\n";____BAH_COMPILER_VAR_1606[3] = intToStr(line->data[0].line);____BAH_COMPILER_VAR_1606[2] = "\01\0\0\0"":";____BAH_COMPILER_VAR_1606[1] = compilerState.currentFile;____BAH_COMPILER_VAR_1606[0] = "\057\0\0\0""\n__BAH_panic(\"Undefined capture resolution.\", \"";char * ____BAH_COMPILER_VAR_1607 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1606, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1607));
}
};

#line 3392 "/home/alois/Documents/bah-bah/src/parser.bah"
void parseLine(__BAH_ARR_TYPE_Tok line,struct Elems* elems){

#line 3394 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((len(line)==0)) {

#line 3395 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}

#line 3398 "/home/alois/Documents/bah-bah/src/parser.bah"
clear(currChecks);

#line 3400 "/home/alois/Documents/bah-bah/src/parser.bah"
line = parsePointers(line,elems);

#line 3401 "/home/alois/Documents/bah-bah/src/parser.bah"
lineType ltp = getLineType(line);

#line 3403 "/home/alois/Documents/bah-bah/src/parser.bah"
compilerState.RCPvars = memoryAlloc(sizeof(array(struct variable*)));

compilerState.RCPvars->length = 0;
compilerState.RCPvars->elemSize = sizeof(struct variable*);

#line 3404 "/home/alois/Documents/bah-bah/src/parser.bah"
currSetVar = null;

#line 3406 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((ltp==LINE_TYPE_VAR)&&(len(line)>1)) {

#line 3407 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok ft = line->data[0];

#line 3408 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok st = line->data[1];

#line 3409 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(st.cont, "\01\0\0\0""=") == 0)) {

#line 3410 "/home/alois/Documents/bah-bah/src/parser.bah"
struct variable* v = searchVar(ft.cont,elems);

#line 3411 "/home/alois/Documents/bah-bah/src/parser.bah"
currSetVar = v;
}
}

#line 3416 "/home/alois/Documents/bah-bah/src/parser.bah"
char parsed = false;

#line 3417 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((ltp==LINE_TYPE_INCLUDE)) {

#line 3418 "/home/alois/Documents/bah-bah/src/parser.bah"
parsed = true;

#line 3419 "/home/alois/Documents/bah-bah/src/parser.bah"
parseInclude(line,elems);
}

#line 3420 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((ltp==LINE_TYPE_IMPORT)) {

#line 3421 "/home/alois/Documents/bah-bah/src/parser.bah"
parsed = true;

#line 3422 "/home/alois/Documents/bah-bah/src/parser.bah"
parseImport(line,elems);
}

#line 3423 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((ltp==LINE_TYPE_DEFINE)) {

#line 3424 "/home/alois/Documents/bah-bah/src/parser.bah"
parsed = true;

#line 3425 "/home/alois/Documents/bah-bah/src/parser.bah"
parseDefine(line,elems);
}

#line 3426 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((ltp==LINE_TYPE_CLIB)) {

#line 3427 "/home/alois/Documents/bah-bah/src/parser.bah"
parsed = true;

#line 3428 "/home/alois/Documents/bah-bah/src/parser.bah"
parseClib(line);
}

#line 3429 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((ltp==LINE_TYPE_PRE_KEYWORD)) {

#line 3430 "/home/alois/Documents/bah-bah/src/parser.bah"
parsePreKeyword(line,elems);

#line 3431 "/home/alois/Documents/bah-bah/src/parser.bah"
parsed = true;
}

#line 3432 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 3433 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1608 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1608[4] = "\02\0\0\0""\"\n";____BAH_COMPILER_VAR_1608[3] = compilerState.currentFile;____BAH_COMPILER_VAR_1608[2] = "\02\0\0\0"" \"";____BAH_COMPILER_VAR_1608[1] = intToStr(line->data[0].line);____BAH_COMPILER_VAR_1608[0] = "\07\0\0\0""\n#line ";char * ____BAH_COMPILER_VAR_1609 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1608, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1609));

#line 3434 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((ltp==LINE_TYPE_STRUCT)) {

#line 3435 "/home/alois/Documents/bah-bah/src/parser.bah"
parsed = true;

#line 3436 "/home/alois/Documents/bah-bah/src/parser.bah"
parseStruct(line,elems);
}

#line 3437 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((ltp==LINE_TYPE_CONST)) {

#line 3438 "/home/alois/Documents/bah-bah/src/parser.bah"
parsed = true;

#line 3439 "/home/alois/Documents/bah-bah/src/parser.bah"
parseConst(line,elems);
}

#line 3440 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((ltp==LINE_TYPE_MACRO)) {

#line 3441 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}

#line 3442 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((ltp!=LINE_TYPE_FN_DECL)) {

#line 3443 "/home/alois/Documents/bah-bah/src/parser.bah"
line = prePross(line,ltp,elems);

#line 3444 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((len(line)==0)) {

#line 3445 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}
}

#line 3449 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok ft = line->data[0];

#line 3450 "/home/alois/Documents/bah-bah/src/parser.bah"
if (RCPavailable()&&(ft.isOper==false)&&(ft.isFunc==true)) {

#line 3451 "/home/alois/Documents/bah-bah/src/parser.bah"
struct func* fn = searchFuncByToken(&ft,elems);

#line 3452 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((fn!=null)&&(fn->returns!=null)&&isRCPtype(fn->returns->type,elems)) {

#line 3453 "/home/alois/Documents/bah-bah/src/parser.bah"
registerRCPvar(fn->returns->type,ft.cont,elems);

#line 3454 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}
}

#line 3458 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((ltp==LINE_TYPE_VAR)) {

#line 3459 "/home/alois/Documents/bah-bah/src/parser.bah"
parsed = true;

#line 3460 "/home/alois/Documents/bah-bah/src/parser.bah"
parseVar(line,elems);
}

#line 3461 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((ltp==LINE_TYPE_FN_CALL)) {

#line 3462 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((len(line)>1), 0)) {

#line 3463 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&line->data[len(line)-1],"\052\0\0\0""Not expecting {TOKEN} after function call.");
}

#line 3465 "/home/alois/Documents/bah-bah/src/parser.bah"
parsed = true;

#line 3466 "/home/alois/Documents/bah-bah/src/parser.bah"
char** ____BAH_COMPILER_VAR_1610 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1610[1] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_1610[0] = ft.cont;char * ____BAH_COMPILER_VAR_1611 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1610, 2);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1611));
}

#line 3467 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((ltp==LINE_TYPE_FN_DECL)) {

#line 3468 "/home/alois/Documents/bah-bah/src/parser.bah"
parsed = true;

#line 3469 "/home/alois/Documents/bah-bah/src/parser.bah"
parseFnDeclare(line,elems);
}

#line 3470 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((ltp==LINE_TYPE_RETURN)) {

#line 3471 "/home/alois/Documents/bah-bah/src/parser.bah"
parsed = true;

#line 3472 "/home/alois/Documents/bah-bah/src/parser.bah"
parseReturn(line,elems);
}

#line 3473 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((ltp==LINE_TYPE_IF)) {

#line 3474 "/home/alois/Documents/bah-bah/src/parser.bah"
parsed = true;

#line 3475 "/home/alois/Documents/bah-bah/src/parser.bah"
parseIf(line,false,elems);
}

#line 3476 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((ltp==LINE_TYPE_ELSE)) {

#line 3477 "/home/alois/Documents/bah-bah/src/parser.bah"
parsed = true;

#line 3478 "/home/alois/Documents/bah-bah/src/parser.bah"
parseElse(line,elems);
}

#line 3479 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((ltp==LINE_TYPE_FOR)) {

#line 3480 "/home/alois/Documents/bah-bah/src/parser.bah"
parsed = true;

#line 3481 "/home/alois/Documents/bah-bah/src/parser.bah"
parseFor(line,elems);
}

#line 3482 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((ltp==LINE_TYPE_FOR_OPERATOR)) {

#line 3483 "/home/alois/Documents/bah-bah/src/parser.bah"
parsed = true;

#line 3484 "/home/alois/Documents/bah-bah/src/parser.bah"
parseForOp(line,elems);
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
}

#line 3494 "/home/alois/Documents/bah-bah/src/parser.bah"
if (__builtin_expect((parsed==false), 0)) {

#line 3495 "/home/alois/Documents/bah-bah/src/parser.bah"
throwErr(&line->data[0],"\025\0\0\0""{TOKEN} not expected.");
}

#line 3498 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strlen(NEXT_LINE)>0)) {

#line 3499 "/home/alois/Documents/bah-bah/src/parser.bah"
OUTPUT = rope__add(OUTPUT, rope(NEXT_LINE));

#line 3500 "/home/alois/Documents/bah-bah/src/parser.bah"
NEXT_LINE = "\0\0\0\0""";
}

#line 3502 "/home/alois/Documents/bah-bah/src/parser.bah"
prevLine = ltp;
};

#line 3507 "/home/alois/Documents/bah-bah/src/parser.bah"
void parseLines(__BAH_ARR_TYPE_Tok tokens,struct Elems* elems){

#line 3509 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((len(tokens)==0)) {

#line 3510 "/home/alois/Documents/bah-bah/src/parser.bah"
return;
}

#line 3512 "/home/alois/Documents/bah-bah/src/parser.bah"
array(struct Tok)* line = memoryAlloc(sizeof(array(struct Tok)));

line->length = 0;
line->elemSize = sizeof(struct Tok);

#line 3513 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok ft = tokens->data[0];

#line 3514 "/home/alois/Documents/bah-bah/src/parser.bah"
unsigned int currentLine = ft.line;

#line 3515 "/home/alois/Documents/bah-bah/src/parser.bah"
long int nbEncl = 0;

#line 3516 "/home/alois/Documents/bah-bah/src/parser.bah"
register long int i = 0;

#line 3516 "/home/alois/Documents/bah-bah/src/parser.bah"
while ((i<len(tokens))) {

#line 3517 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok t = tokens->data[i];

#line 3519 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((t.type==TOKEN_TYPE_ENCL)) {

#line 3520 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((strcmp(t.cont, "\01\0\0\0""(") == 0)) {

#line 3521 "/home/alois/Documents/bah-bah/src/parser.bah"
nbEncl = nbEncl+1;
}

#line 3522 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(t.cont, "\01\0\0\0"")") == 0)) {

#line 3523 "/home/alois/Documents/bah-bah/src/parser.bah"
nbEncl = nbEncl-1;
}

#line 3524 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(t.cont, "\01\0\0\0""{") == 0)) {

#line 3525 "/home/alois/Documents/bah-bah/src/parser.bah"
nbEncl = nbEncl+1;
}

#line 3526 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(t.cont, "\01\0\0\0""}") == 0)) {

#line 3527 "/home/alois/Documents/bah-bah/src/parser.bah"
nbEncl = nbEncl-1;
}

#line 3528 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(t.cont, "\01\0\0\0""[") == 0)) {

#line 3529 "/home/alois/Documents/bah-bah/src/parser.bah"
nbEncl = nbEncl+1;
}

#line 3530 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(t.cont, "\01\0\0\0""]") == 0)) {

#line 3531 "/home/alois/Documents/bah-bah/src/parser.bah"
nbEncl = nbEncl-1;
}
}

#line 3535 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((t.type==TOKEN_TYPE_STR)&&(t.begLine==currentLine)) {

#line 3536 "/home/alois/Documents/bah-bah/src/parser.bah"
currentLine = t.line;
}

#line 3539 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((nbEncl==0)) {

#line 3540 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((t.line!=currentLine)) {

#line 3541 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((t.type==TOKEN_TYPE_ENCL)) {

#line 3542 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1612 = len(line);
    __Bah_realocate_arr(line, ____BAH_COMPILER_VAR_1612);
    line->data[____BAH_COMPILER_VAR_1612] = t;

#line 3543 "/home/alois/Documents/bah-bah/src/parser.bah"
struct Tok pt = tokens->data[i-1];

#line 3544 "/home/alois/Documents/bah-bah/src/parser.bah"
currentLine = pt.line;
}

#line 3545 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 3546 "/home/alois/Documents/bah-bah/src/parser.bah"
currentLine = t.line;
}

#line 3548 "/home/alois/Documents/bah-bah/src/parser.bah"
parseLine(line,elems);

#line 3549 "/home/alois/Documents/bah-bah/src/parser.bah"
clear(line);

#line 3550 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((t.type==TOKEN_TYPE_ENCL)) {

#line 3551 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 3552 "/home/alois/Documents/bah-bah/src/parser.bah"
continue;
}
}

#line 3554 "/home/alois/Documents/bah-bah/src/parser.bah"
else if ((strcmp(t.cont, "\01\0\0\0"";") == 0)) {

#line 3555 "/home/alois/Documents/bah-bah/src/parser.bah"
currentLine = t.line;

#line 3556 "/home/alois/Documents/bah-bah/src/parser.bah"
parseLine(line,elems);

#line 3557 "/home/alois/Documents/bah-bah/src/parser.bah"
clear(line);

#line 3558 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;

#line 3559 "/home/alois/Documents/bah-bah/src/parser.bah"
continue;
}
}

#line 3563 "/home/alois/Documents/bah-bah/src/parser.bah"

    unsigned int ____BAH_COMPILER_VAR_1613 = len(line);
    __Bah_realocate_arr(line, ____BAH_COMPILER_VAR_1613);
    line->data[____BAH_COMPILER_VAR_1613] = t;

#line 3564 "/home/alois/Documents/bah-bah/src/parser.bah"
++i;
};

#line 3567 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((len(line)>0)) {

#line 3568 "/home/alois/Documents/bah-bah/src/parser.bah"
if ((nbEncl==0)) {

#line 3569 "/home/alois/Documents/bah-bah/src/parser.bah"
parseLine(line,elems);

#line 3570 "/home/alois/Documents/bah-bah/src/parser.bah"
clear(line);
}

#line 3571 "/home/alois/Documents/bah-bah/src/parser.bah"
else {

#line 3572 "/home/alois/Documents/bah-bah/src/parser.bah"
ft = line->data[len(line)-1];

#line 3573 "/home/alois/Documents/bah-bah/src/parser.bah"
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
char** ____BAH_COMPILER_VAR_1614 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1614[3] = arg->name;____BAH_COMPILER_VAR_1614[2] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_1614[1] = string__str(&ct);____BAH_COMPILER_VAR_1614[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_1615 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1614, 4);tmpfnArgsCType = ____BAH_COMPILER_VAR_1615;

#line 9 "/home/alois/Documents/bah-bah/src/declarative.bah"
j = j+1;

#line 10 "/home/alois/Documents/bah-bah/src/declarative.bah"
if ((j<len(fn->args))) {

#line 11 "/home/alois/Documents/bah-bah/src/declarative.bah"
char** ____BAH_COMPILER_VAR_1616 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1616[1] = "\02\0\0\0"", ";____BAH_COMPILER_VAR_1616[0] = tmpfnArgsCType;char * ____BAH_COMPILER_VAR_1617 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1616, 2);tmpfnArgsCType = ____BAH_COMPILER_VAR_1617;
}
};

#line 15 "/home/alois/Documents/bah-bah/src/declarative.bah"
char** ____BAH_COMPILER_VAR_1618 = alloca(6 * sizeof(char*));____BAH_COMPILER_VAR_1618[5] = "\03\0\0\0"");\n";____BAH_COMPILER_VAR_1618[4] = tmpfnArgsCType;____BAH_COMPILER_VAR_1618[3] = "\01\0\0\0""(";____BAH_COMPILER_VAR_1618[2] = fn->name;____BAH_COMPILER_VAR_1618[1] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_1618[0] = string__str(&tmpfnRetCType);char * ____BAH_COMPILER_VAR_1619 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1618, 6);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1619));
};

#line 18 "/home/alois/Documents/bah-bah/src/declarative.bah"
void declareVar(struct variable* v,struct Elems* elems){

#line 19 "/home/alois/Documents/bah-bah/src/declarative.bah"
if ((v->isConst==true)) {

#line 20 "/home/alois/Documents/bah-bah/src/declarative.bah"
char** ____BAH_COMPILER_VAR_1620 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1620[4] = "\01\0\0\0""\n";____BAH_COMPILER_VAR_1620[3] = v->constVal;____BAH_COMPILER_VAR_1620[2] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_1620[1] = v->name;____BAH_COMPILER_VAR_1620[0] = "\010\0\0\0""#define ";char * ____BAH_COMPILER_VAR_1621 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1620, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1621));
}

#line 21 "/home/alois/Documents/bah-bah/src/declarative.bah"
else {

#line 22 "/home/alois/Documents/bah-bah/src/declarative.bah"
struct string cType = getCType(v->type,elems);

#line 23 "/home/alois/Documents/bah-bah/src/declarative.bah"
char** ____BAH_COMPILER_VAR_1622 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1622[3] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_1622[2] = v->name;____BAH_COMPILER_VAR_1622[1] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_1622[0] = string__str(&cType);char * ____BAH_COMPILER_VAR_1623 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1622, 4);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1623));
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
char** ____BAH_COMPILER_VAR_1624 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1624[2] = "\01\0\0\0""\n";____BAH_COMPILER_VAR_1624[1] = compilerState.cIncludes->data[i];____BAH_COMPILER_VAR_1624[0] = "\011\0\0\0""#include ";char * ____BAH_COMPILER_VAR_1625 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1624, 3);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1625));
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
char * ____BAH_COMPILER_VAR_1626 =string__str(&elemType);struct string elemCtype = getCType(____BAH_COMPILER_VAR_1626,elems);

#line 50 "/home/alois/Documents/bah-bah/src/declarative.bah"
char** ____BAH_COMPILER_VAR_1627 = alloca(5 * sizeof(char*));____BAH_COMPILER_VAR_1627[4] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_1627[3] = t;____BAH_COMPILER_VAR_1627[2] = "\03\0\0\0"")* ";____BAH_COMPILER_VAR_1627[1] = string__str(&elemCtype);____BAH_COMPILER_VAR_1627[0] = "\016\0\0\0""typedef array(";char * ____BAH_COMPILER_VAR_1628 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1627, 5);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1628));
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
char** ____BAH_COMPILER_VAR_1629 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1629[1] = compilerState.currentFile;____BAH_COMPILER_VAR_1629[0] = "\06\0\0\0""file: ";char * ____BAH_COMPILER_VAR_1630 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1629, 2);char * r = ____BAH_COMPILER_VAR_1630;

#line 54 "/home/alois/Documents/bah-bah/src/main.bah"
if ((currentFn!=null)) {

#line 55 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1631 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1631[2] = "\02\0\0\0""()";____BAH_COMPILER_VAR_1631[1] = currentFn->name;____BAH_COMPILER_VAR_1631[0] = "\013\0\0\0""\nfunction: ";char * ____BAH_COMPILER_VAR_1632 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1631, 3);char** ____BAH_COMPILER_VAR_1633 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1633[1] = ____BAH_COMPILER_VAR_1632;____BAH_COMPILER_VAR_1633[0] = r;char * ____BAH_COMPILER_VAR_1634 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1633, 2);r = ____BAH_COMPILER_VAR_1634;
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
struct flags ____BAH_COMPILER_VAR_1635 = {};
____BAH_COMPILER_VAR_1635.flags = memoryAlloc(sizeof(array(struct flag*)));
            ____BAH_COMPILER_VAR_1635.flags->length = 0;
            ____BAH_COMPILER_VAR_1635.flags->elemSize = sizeof(struct flag*);
            ____BAH_COMPILER_VAR_1635.args = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_1635.args->length = 0;
            ____BAH_COMPILER_VAR_1635.args->elemSize = sizeof(char *);
            flags = ____BAH_COMPILER_VAR_1635;

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
char** ____BAH_COMPILER_VAR_1636 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1636[2] = "\01\0\0\0"".";____BAH_COMPILER_VAR_1636[1] = BAH_OS;____BAH_COMPILER_VAR_1636[0] = "\115\0\0\0""Select the target OS for cross compilling (linux, windows, darwin), default: ";char * ____BAH_COMPILER_VAR_1637 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1636, 3);flags__addString(&flags,"\06\0\0\0""target",____BAH_COMPILER_VAR_1637);

#line 90 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1638 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1638[2] = "\02\0\0\0"").";____BAH_COMPILER_VAR_1638[1] = BAH_DIR;____BAH_COMPILER_VAR_1638[0] = "\056\0\0\0""If your Bah directory is not the default one (";char * ____BAH_COMPILER_VAR_1639 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1638, 3);flags__addString(&flags,"\06\0\0\0""bahDir",____BAH_COMPILER_VAR_1639);

#line 91 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1640 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1640[2] = "\01\0\0\0"".";____BAH_COMPILER_VAR_1640[1] = BAH_CC;____BAH_COMPILER_VAR_1640[0] = "\050\0\0\0""To change the C compiler used, default: ";char * ____BAH_COMPILER_VAR_1641 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1640, 3);flags__addString(&flags,"\02\0\0\0""CC",____BAH_COMPILER_VAR_1641);

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
char** ____BAH_COMPILER_VAR_1642 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1642[1] = BAH_OS;____BAH_COMPILER_VAR_1642[0] = "\016\0\0\0""Build target: ";char * ____BAH_COMPILER_VAR_1643 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1642, 2);println(____BAH_COMPILER_VAR_1643);
}

#line 113 "/home/alois/Documents/bah-bah/src/main.bah"
if ((flags__isSet(&flags,"\06\0\0\0""bahDir")==1)) {

#line 114 "/home/alois/Documents/bah-bah/src/main.bah"
BAH_DIR = flags__get(&flags,"\06\0\0\0""bahDir");

#line 115 "/home/alois/Documents/bah-bah/src/main.bah"
if ((BAH_DIR[strlen(BAH_DIR)-1+4]!=47)) {

#line 116 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1644 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1644[1] = "\01\0\0\0""/";____BAH_COMPILER_VAR_1644[0] = BAH_DIR;char * ____BAH_COMPILER_VAR_1645 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1644, 2);BAH_DIR = ____BAH_COMPILER_VAR_1645;
}

#line 118 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1646 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1646[1] = BAH_DIR;____BAH_COMPILER_VAR_1646[0] = "\017\0\0\0""Bah directory: ";char * ____BAH_COMPILER_VAR_1647 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1646, 2);println(____BAH_COMPILER_VAR_1647);
}

#line 120 "/home/alois/Documents/bah-bah/src/main.bah"
if ((flags__isSet(&flags,"\02\0\0\0""CC")==1)) {

#line 121 "/home/alois/Documents/bah-bah/src/main.bah"
BAH_CC = flags__get(&flags,"\02\0\0\0""CC");

#line 122 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1648 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1648[1] = BAH_CC;____BAH_COMPILER_VAR_1648[0] = "\014\0\0\0""C compiler: ";char * ____BAH_COMPILER_VAR_1649 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1648, 2);println(____BAH_COMPILER_VAR_1649);
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
char** ____BAH_COMPILER_VAR_1650 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1650[2] = "\026\0\0\0"".\n© Alois Laurent Boe";____BAH_COMPILER_VAR_1650[1] = BAH_VERSION;____BAH_COMPILER_VAR_1650[0] = "\026\0\0\0""Bah compiler version: ";char * ____BAH_COMPILER_VAR_1651 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1650, 3);println(____BAH_COMPILER_VAR_1651);

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
struct compilerStateTag ____BAH_COMPILER_VAR_1652 = {};
____BAH_COMPILER_VAR_1652.includes = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_1652.includes->length = 0;
            ____BAH_COMPILER_VAR_1652.includes->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_1652.cIncludes = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_1652.cIncludes->length = 0;
            ____BAH_COMPILER_VAR_1652.cIncludes->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_1652.cLibs = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_1652.cLibs->length = 0;
            ____BAH_COMPILER_VAR_1652.cLibs->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_1652.currentDir = "\02\0\0\0""./";
____BAH_COMPILER_VAR_1652.arrTypesDecl = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_1652.arrTypesDecl->length = 0;
            ____BAH_COMPILER_VAR_1652.arrTypesDecl->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_1652.RCPvars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_1652.RCPvars->length = 0;
            ____BAH_COMPILER_VAR_1652.RCPvars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_1652.evals = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_1652.evals->length = 0;
            ____BAH_COMPILER_VAR_1652.evals->elemSize = sizeof(char *);
            compilerState = ____BAH_COMPILER_VAR_1652;

#line 236 "/home/alois/Documents/bah-bah/src/main.bah"

    unsigned int ____BAH_COMPILER_VAR_1653 = 0;
    __Bah_realocate_arr(compilerState.arrTypesDecl, ____BAH_COMPILER_VAR_1653);
    compilerState.arrTypesDecl->data[____BAH_COMPILER_VAR_1653] = "\027\0\0\0""__BAH_ARR_TYPE_cpstring";

#line 239 "/home/alois/Documents/bah-bah/src/main.bah"
char * fileName = absPath(args->data[1]);

#line 240 "/home/alois/Documents/bah-bah/src/main.bah"
compilerState.currentFile = fileName;

#line 241 "/home/alois/Documents/bah-bah/src/main.bah"
struct fileStream ____BAH_COMPILER_VAR_1654 = {};
struct fileStream fs = ____BAH_COMPILER_VAR_1654;

#line 242 "/home/alois/Documents/bah-bah/src/main.bah"
fileStream__open(&fs,fileName,"\01\0\0\0""r");

#line 243 "/home/alois/Documents/bah-bah/src/main.bah"
char * f = fileStream__readContent(&fs);

#line 244 "/home/alois/Documents/bah-bah/src/main.bah"
if (__builtin_expect((fileStream__isValid(&fs)==0)||(fileStream__getSize(&fs)==0), 0)) {

#line 245 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1655 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1655[2] = "\02\0\0\0""'.";____BAH_COMPILER_VAR_1655[1] = args->data[1];____BAH_COMPILER_VAR_1655[0] = "\025\0\0\0""Could not open file '";char * ____BAH_COMPILER_VAR_1656 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1655, 3);println(____BAH_COMPILER_VAR_1656);

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
char** ____BAH_COMPILER_VAR_1657 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1657[2] = "\021\0\0\0""' not recognized.";____BAH_COMPILER_VAR_1657[1] = fileName;____BAH_COMPILER_VAR_1657[0] = "\06\0\0\0""File '";char * ____BAH_COMPILER_VAR_1658 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1657, 3);println(____BAH_COMPILER_VAR_1658);

#line 255 "/home/alois/Documents/bah-bah/src/main.bah"
exit(1);
}

#line 258 "/home/alois/Documents/bah-bah/src/main.bah"
struct Elems* ____BAH_COMPILER_VAR_1659 = memoryAlloc(sizeof(struct Elems));
____BAH_COMPILER_VAR_1659->vars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_1659->vars->length = 0;
            ____BAH_COMPILER_VAR_1659->vars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_1659->structs = memoryAlloc(sizeof(array(struct cStruct*)));
            ____BAH_COMPILER_VAR_1659->structs->length = 0;
            ____BAH_COMPILER_VAR_1659->structs->elemSize = sizeof(struct cStruct*);
            ____BAH_COMPILER_VAR_1659->types = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_1659->types->length = 0;
            ____BAH_COMPILER_VAR_1659->types->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_1659->fns = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_1659->fns->length = 0;
            ____BAH_COMPILER_VAR_1659->fns->elemSize = sizeof(struct func*);
            ____BAH_COMPILER_VAR_1659->deletedVars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_1659->deletedVars->length = 0;
            ____BAH_COMPILER_VAR_1659->deletedVars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_1659->branchChecks = memoryAlloc(sizeof(array(struct varCheck)));
            ____BAH_COMPILER_VAR_1659->branchChecks->length = 0;
            ____BAH_COMPILER_VAR_1659->branchChecks->elemSize = sizeof(struct varCheck);
            struct Elems* elems = ____BAH_COMPILER_VAR_1659;

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

                struct string ____BAH_COMPILER_VAR_1660 = string(fileName);
                if ((flags__isSet(&flags,"\011\0\0\0""nobuiltin")==0)&&(string__hasSuffix(&____BAH_COMPILER_VAR_1660,"\010\0\0\0"".bahstrp")==false)) {

#line 279 "/home/alois/Documents/bah-bah/src/main.bah"
if (__builtin_expect((includeFile("\013\0\0\0""builtin.bah",elems)==false), 0)) {

#line 280 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1661 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1661[2] = "\01\0\0\0""'";____BAH_COMPILER_VAR_1661[1] = BAH_DIR;____BAH_COMPILER_VAR_1661[0] = "\047\0\0\0""Could not find std-libs, please check '";char * ____BAH_COMPILER_VAR_1662 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1661, 3);__BAH_panic(____BAH_COMPILER_VAR_1662,"\056\0\0\0""/home/alois/Documents/bah-bah/src/main.bah:280");
}
}

#line 284 "/home/alois/Documents/bah-bah/src/main.bah"
if ((isFixMeEnabled==true)) {

#line 285 "/home/alois/Documents/bah-bah/src/main.bah"
if (__builtin_expect((includeFile("\011\0\0\0""fixme.bah",elems)==false), 0)) {

#line 286 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1663 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1663[2] = "\01\0\0\0""'";____BAH_COMPILER_VAR_1663[1] = BAH_DIR;____BAH_COMPILER_VAR_1663[0] = "\050\0\0\0""Could not find fixme.bah, please check '";char * ____BAH_COMPILER_VAR_1664 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1663, 3);__BAH_panic(____BAH_COMPILER_VAR_1664,"\056\0\0\0""/home/alois/Documents/bah-bah/src/main.bah:286");
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
char** ____BAH_COMPILER_VAR_1665 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1665[2] = "\02\0\0\0""];";____BAH_COMPILER_VAR_1665[1] = intToStr(l);____BAH_COMPILER_VAR_1665[0] = "\071\0\0\0""volatile struct __Bah_fnName_mapper __tmp____Bah_fnNames[";char * ____BAH_COMPILER_VAR_1666 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1665, 3);OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_1666));

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
char** ____BAH_COMPILER_VAR_1667 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1667[1] = "\02\0\0\0""__";____BAH_COMPILER_VAR_1667[0] = fn->from;char * ____BAH_COMPILER_VAR_1668 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1667, 2);if ((strcmp(fn->from, "\0\0\0\0""") != 0)&&strHasPrefix(name,____BAH_COMPILER_VAR_1668)) {

#line 319 "/home/alois/Documents/bah-bah/src/main.bah"
struct string n = string(name);

#line 320 "/home/alois/Documents/bah-bah/src/main.bah"
string__trimLeft(&n,strlen(fn->from)+2);

#line 321 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1669 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1669[2] = string__str(&n);____BAH_COMPILER_VAR_1669[1] = "\01\0\0\0"".";____BAH_COMPILER_VAR_1669[0] = fn->from;char * ____BAH_COMPILER_VAR_1670 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1669, 3);name = ____BAH_COMPILER_VAR_1670;
}

#line 323 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1671 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1671[2] = "\01\0\0\0""\"";____BAH_COMPILER_VAR_1671[1] = name;____BAH_COMPILER_VAR_1671[0] = "\01\0\0\0""\"";char * ____BAH_COMPILER_VAR_1672 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1671, 3);char** ____BAH_COMPILER_VAR_1673 = alloca(9 * sizeof(char*));____BAH_COMPILER_VAR_1673[8] = "\02\0\0\0"";\n";____BAH_COMPILER_VAR_1673[7] = fn->name;____BAH_COMPILER_VAR_1673[6] = "\06\0\0\0""].p = ";____BAH_COMPILER_VAR_1673[5] = intToStr(j);____BAH_COMPILER_VAR_1673[4] = "\043\0\0\0"";\n            __tmp____Bah_fnNames[";____BAH_COMPILER_VAR_1673[3] = strLitteralToBahStr(____BAH_COMPILER_VAR_1672);____BAH_COMPILER_VAR_1673[2] = "\06\0\0\0""].n = ";____BAH_COMPILER_VAR_1673[1] = intToStr(j);____BAH_COMPILER_VAR_1673[0] = "\042\0\0\0""\n            __tmp____Bah_fnNames[";char * ____BAH_COMPILER_VAR_1674 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1673, 9);INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_1674));

#line 326 "/home/alois/Documents/bah-bah/src/main.bah"
++j;
};

#line 328 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1675 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1675[2] = "\01\0\0\0"";";____BAH_COMPILER_VAR_1675[1] = intToStr(l);____BAH_COMPILER_VAR_1675[0] = "\125\0\0\0""\n        __Bah_fnNames->data = __tmp____Bah_fnNames;\n        __Bah_fnNames->length = ";char * ____BAH_COMPILER_VAR_1676 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1675, 3);INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_1676));
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
char** ____BAH_COMPILER_VAR_1677 = alloca(7 * sizeof(char*));____BAH_COMPILER_VAR_1677[6] = "\07\0\0\0""ms)\e[0m";____BAH_COMPILER_VAR_1677[5] = intToStr(totalLexerTime/1000000);____BAH_COMPILER_VAR_1677[4] = "\020\0\0\0""ms, lexer time: ";____BAH_COMPILER_VAR_1677[3] = intToStr(totalTime/1000000);____BAH_COMPILER_VAR_1677[2] = "\024\0\0\0"" lines, total time: ";____BAH_COMPILER_VAR_1677[1] = intToStr(totalLines);____BAH_COMPILER_VAR_1677[0] = "\011\0\0\0""Parsed. (";char * ____BAH_COMPILER_VAR_1678 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1677, 7);println(____BAH_COMPILER_VAR_1678);
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
char** ____BAH_COMPILER_VAR_1679 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1679[1] = "\02\0\0\0"".o";____BAH_COMPILER_VAR_1679[0] = fileName;char * ____BAH_COMPILER_VAR_1680 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1679, 2);fileName = ____BAH_COMPILER_VAR_1680;

#line 388 "/home/alois/Documents/bah-bah/src/main.bah"
obj = "\02\0\0\0""-c";
}

#line 391 "/home/alois/Documents/bah-bah/src/main.bah"
char * randFileName = "\016\0\0\0""-x c - -x none";

#line 392 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1681 = alloca(17 * sizeof(char*));____BAH_COMPILER_VAR_1681[16] = fileName;____BAH_COMPILER_VAR_1681[15] = "\017\0\0\0"" -w -O1 -g1 -o ";____BAH_COMPILER_VAR_1681[14] = obj;____BAH_COMPILER_VAR_1681[13] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_1681[12] = isStatic;____BAH_COMPILER_VAR_1681[11] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_1681[10] = randFileName;____BAH_COMPILER_VAR_1681[9] = "\03\0\0\0""/\" ";____BAH_COMPILER_VAR_1681[8] = BAH_OS;____BAH_COMPILER_VAR_1681[7] = "\05\0\0\0""libs/";____BAH_COMPILER_VAR_1681[6] = BAH_DIR;____BAH_COMPILER_VAR_1681[5] = "\017\0\0\0""/include/\" -L \"";____BAH_COMPILER_VAR_1681[4] = BAH_OS;____BAH_COMPILER_VAR_1681[3] = "\05\0\0\0""libs/";____BAH_COMPILER_VAR_1681[2] = BAH_DIR;____BAH_COMPILER_VAR_1681[1] = "\05\0\0\0"" -I \"";____BAH_COMPILER_VAR_1681[0] = BAH_CC;char * ____BAH_COMPILER_VAR_1682 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1681, 17);char * gccArgs = ____BAH_COMPILER_VAR_1682;

#line 394 "/home/alois/Documents/bah-bah/src/main.bah"
if ((flags__isSet(&flags,"\01\0\0\0""l")==1)) {

#line 395 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1683 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1683[1] = "\03\0\0\0"" -c";____BAH_COMPILER_VAR_1683[0] = gccArgs;char * ____BAH_COMPILER_VAR_1684 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1683, 2);gccArgs = ____BAH_COMPILER_VAR_1684;
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
char** ____BAH_COMPILER_VAR_1685 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1685[2] = l;____BAH_COMPILER_VAR_1685[1] = "\02\0\0\0"" -";____BAH_COMPILER_VAR_1685[0] = gccArgs;char * ____BAH_COMPILER_VAR_1686 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1685, 3);gccArgs = ____BAH_COMPILER_VAR_1686;

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
char * ____BAH_COMPILER_VAR_1687 =command__run(&cmd);println(____BAH_COMPILER_VAR_1687);
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
char** ____BAH_COMPILER_VAR_1688 = alloca(4 * sizeof(char*));____BAH_COMPILER_VAR_1688[3] = fileName;____BAH_COMPILER_VAR_1688[2] = "\03\0\0\0"".a ";____BAH_COMPILER_VAR_1688[1] = fileName;____BAH_COMPILER_VAR_1688[0] = "\07\0\0\0""ar rcs ";char * ____BAH_COMPILER_VAR_1689 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1688, 4);cmd = command(____BAH_COMPILER_VAR_1689);

#line 427 "/home/alois/Documents/bah-bah/src/main.bah"
command__run(&cmd);
}
}

#line 430 "/home/alois/Documents/bah-bah/src/main.bah"
else {

#line 432 "/home/alois/Documents/bah-bah/src/main.bah"
if ((flags__isSet(&flags,"\01\0\0\0""o")==0)) {

#line 433 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1690 = alloca(2 * sizeof(char*));____BAH_COMPILER_VAR_1690[1] = "\02\0\0\0"".c";____BAH_COMPILER_VAR_1690[0] = fileName;char * ____BAH_COMPILER_VAR_1691 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1690, 2);fileName = ____BAH_COMPILER_VAR_1691;
}

#line 436 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1692 = alloca(14 * sizeof(char*));____BAH_COMPILER_VAR_1692[13] = "\010\0\0\0"" -O1 -w ";____BAH_COMPILER_VAR_1692[12] = isStatic;____BAH_COMPILER_VAR_1692[11] = "\01\0\0\0"" ";____BAH_COMPILER_VAR_1692[10] = fileName;____BAH_COMPILER_VAR_1692[9] = "\03\0\0\0""/\" ";____BAH_COMPILER_VAR_1692[8] = BAH_OS;____BAH_COMPILER_VAR_1692[7] = "\05\0\0\0""libs/";____BAH_COMPILER_VAR_1692[6] = BAH_DIR;____BAH_COMPILER_VAR_1692[5] = "\017\0\0\0""/include/\" -L \"";____BAH_COMPILER_VAR_1692[4] = BAH_OS;____BAH_COMPILER_VAR_1692[3] = "\05\0\0\0""libs/";____BAH_COMPILER_VAR_1692[2] = BAH_DIR;____BAH_COMPILER_VAR_1692[1] = "\05\0\0\0"" -I \"";____BAH_COMPILER_VAR_1692[0] = BAH_CC;char * ____BAH_COMPILER_VAR_1693 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1692, 14);char * gccArgs = ____BAH_COMPILER_VAR_1693;

#line 437 "/home/alois/Documents/bah-bah/src/main.bah"
array(char *)* cLibs = compilerState.cLibs;

#line 438 "/home/alois/Documents/bah-bah/src/main.bah"
register long int i = 0;

#line 438 "/home/alois/Documents/bah-bah/src/main.bah"
while ((i<len(cLibs))) {

#line 439 "/home/alois/Documents/bah-bah/src/main.bah"
char * l = cLibs->data[i];

#line 440 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1694 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1694[2] = l;____BAH_COMPILER_VAR_1694[1] = "\02\0\0\0"" -";____BAH_COMPILER_VAR_1694[0] = gccArgs;char * ____BAH_COMPILER_VAR_1695 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1694, 3);gccArgs = ____BAH_COMPILER_VAR_1695;

#line 441 "/home/alois/Documents/bah-bah/src/main.bah"
i = i+1;
};

#line 445 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1696 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1696[2] = "\02\0\0\0""'\n";____BAH_COMPILER_VAR_1696[1] = gccArgs;____BAH_COMPILER_VAR_1696[0] = "\021\0\0\0""//COMPILE WITH: '";char * ____BAH_COMPILER_VAR_1697 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1696, 3);OUTPUT = rope__add(rope(____BAH_COMPILER_VAR_1697), OUTPUT);

#line 446 "/home/alois/Documents/bah-bah/src/main.bah"
struct fileStream ____BAH_COMPILER_VAR_1698 = {};
fs = ____BAH_COMPILER_VAR_1698;

#line 447 "/home/alois/Documents/bah-bah/src/main.bah"
fileStream__open(&fs,fileName,"\01\0\0\0""w");

#line 448 "/home/alois/Documents/bah-bah/src/main.bah"
char * ____BAH_COMPILER_VAR_1699 =rope__toStr(OUTPUT);fileStream__writeFile(&fs,____BAH_COMPILER_VAR_1699);

#line 449 "/home/alois/Documents/bah-bah/src/main.bah"
fileStream__close(&fs);
}

#line 453 "/home/alois/Documents/bah-bah/src/main.bah"
if ((isObject==false)) {

#line 454 "/home/alois/Documents/bah-bah/src/main.bah"
long int totalTime = getTimeUnix()-startTime;

#line 455 "/home/alois/Documents/bah-bah/src/main.bah"
char** ____BAH_COMPILER_VAR_1700 = alloca(3 * sizeof(char*));____BAH_COMPILER_VAR_1700[2] = "\07\0\0\0""ms)\e[0m";____BAH_COMPILER_VAR_1700[1] = intToStr(totalTime/1000000);____BAH_COMPILER_VAR_1700[0] = "\032\0\0\0""\e[1;32mDone. (compiled in ";char * ____BAH_COMPILER_VAR_1701 =__Bah_multiple_concat(____BAH_COMPILER_VAR_1700, 3);println(____BAH_COMPILER_VAR_1701);
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

            __tmp____Bah_fnNames[183].n = "\012\0\0\0""rope.toStr";
            __tmp____Bah_fnNames[183].p = rope__toStr;

            __tmp____Bah_fnNames[184].n = "\010\0\0\0""rope.add";
            __tmp____Bah_fnNames[184].p = rope__add;

            __tmp____Bah_fnNames[185].n = "\023\0\0\0""createRopeStructure";
            __tmp____Bah_fnNames[185].p = createRopeStructure;

            __tmp____Bah_fnNames[186].n = "\07\0\0\0""ropeSet";
            __tmp____Bah_fnNames[186].p = ropeSet;

            __tmp____Bah_fnNames[187].n = "\020\0\0\0""concatenateRopes";
            __tmp____Bah_fnNames[187].p = concatenateRopes;

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

            __tmp____Bah_fnNames[257].n = "\016\0\0\0""genCompilerVar";
            __tmp____Bah_fnNames[257].p = genCompilerVar;

            __tmp____Bah_fnNames[258].n = "\010\0\0\0""varInArr";
            __tmp____Bah_fnNames[258].p = varInArr;

            __tmp____Bah_fnNames[259].n = "\015\0\0\0""pathToVarName";
            __tmp____Bah_fnNames[259].p = pathToVarName;

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
    