//COMPILE WITH: 'gcc darwin.c -w  -w /opt/bah/libs/libgc.a -lpthread -lm -g'

#include "/opt/bah/libs/include/gc.h"

#define noCheck(v) v
#define array(type)	struct{	type *data; long int length; long int elemSize; }
typedef array(char*)* __BAH_ARR_TYPE_cpstring;
long int __BAH__main(__BAH_ARR_TYPE_cpstring);

int main(int argc, char ** argv) {
GC_INIT();
array(char*) * args = GC_MALLOC(sizeof(array(char*)));
args->data = GC_MALLOC(sizeof(char*)*argc);
memcpy(args->data, argv, sizeof(char*)*argc);
args->elemSize = sizeof(char*);
args->length = argc;
return __BAH__main((__BAH_ARR_TYPE_cpstring)args);
};
#define main(v) __BAH__main(v)
#include <signal.h>
#include <string.h>
#define null (void *)0
#define true (int)1
#define false (int)0
#include </opt/bah/libs/include/gc.h>
#include <sys/mman.h>
#define SIZE_OF_INT 8
#define SIZE_OF_CHAR 1
#define SIZE_OF_INT32 4
#define SIZE_OF_FLOAT32 4
#define SIZE_OF_FLOAT 8
long int len(void * a){
long int i =  0;
noCheck( array ( void* ) *arr = a );
noCheck( i = arr -> length );
return i;
};
void fastZeroSet(void * p,long int s){
long int byte =  0;
long int* v;
long int i =  0;
while ((i<s)) {
if ((i + 8>s)) {
memset(noCheck( p + i ),0,s - i);
break;
}
v =  noCheck( p + i );
*v =  byte;
i =  i + 8;
};
};
void * memoryAlloc(long int s){
void * p =  GC_MALLOC(s);
return p;
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
return ;
}
if ((lenA==0)) {
noCheck( arrA -> data = arrB -> data );
noCheck( arrA -> length = arrB -> length );
return ;
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
void * memoryRealloc(void * p,long int s){
void * np =  GC_REALLOC(p,s);
return np;
};
#define PROT_READ 1
#define PROT_WRITE 2
#define PROT_READWRITE 3
#define MAP_SHARED 1
#define MAP_ANONYMOUS 32
void * sharedMemory(long int size){
if ((size==0)) {
size =  4096;
}
void * r =  mmap(0,size,PROT_READ + PROT_WRITE,MAP_SHARED + MAP_ANONYMOUS,-1,0);
return r;
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
long int* sptr =  noCheck( sarr -> data );
return *sptr;
};
void * unser(__BAH_ARR_TYPE_char data){
long int sptr =  serlen(data);
void * r =  memoryAlloc(sptr);
memcpy(r,noCheck( data -> data + 8 ),sptr);
return r;
};
char * concatCPSTRING(char * a,char * b){
long int lenA =  strlen(a);
long int lenB =  strlen(b);
char * r =  memoryAlloc(lenA + lenB + 1);
strncpy(r,a,lenA);
strcat(r,b);
return r;
};
char * __STR(char * a){
long int lenA =  strlen(a);
char * r =  memoryAlloc(lenA + 1);
strncpy(r,a,lenA);
return r;
};
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <math.h>
char cpstringCharAt(char * s,long int i){
char c =  (char)0;
noCheck( c = s [ i ] );
return c;
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
};
void string__set(struct string* this,char * s){
this->length =  strlen(s);
this->content =  (char *)memoryAlloc(this->length + 1);
strcpy(this->content,s);
};
void string__append(struct string* this,char * s){
this->length =  this->length + strlen(s);
char * tmpS =  (char *)memoryRealloc((void *)this->content,this->length);
if (((long int)tmpS==0)) {
tmpS =  (char *)memoryAlloc(this->length);
strncpy(tmpS,this->content,this->length);
}
strcat(tmpS,s);
this->content =  tmpS;
};
void string__prepend(struct string* this,char * s){
char * tmpS =  this->content;
this->length =  this->length + strlen(s);
this->content =  (char *)memoryAlloc(this->length + 1);
strcpy(this->content,s);
strcat(this->content,tmpS);
};
char string__charAt(struct string* this,long int i){
char c =  (char)0;
if ((i<this->length)) {
noCheck( c = this -> content [ i ] );
return c;
}
return c;
};
long int string__compare(struct string* this,char * s){
long int r =  strcmp(this->content,s);
if ((r==0)) {
return 1;
}
return 0;
};
char * string__str(struct string* this){
char * r =  this->content;
return r;
};
void string__replace(struct string* this,char * nd,char * rl){
struct string needle =  {};
needle.set = string__set;
needle.append = string__append;
needle.prepend = string__prepend;
needle.charAt = string__charAt;
needle.compare = string__compare;
needle.str = string__str;
needle.replace = string__replace;
needle.set((struct string*)&needle,nd);
struct string repl =  {};
repl.set = string__set;
repl.append = string__append;
repl.prepend = string__prepend;
repl.charAt = string__charAt;
repl.compare = string__compare;
repl.str = string__str;
repl.replace = string__replace;
repl.set((struct string*)&repl,rl);
long int i =  0;
long int si =  0;
array(char)* replcBuff = memoryAlloc(sizeof(array(char)));

replcBuff->length = 0;
replcBuff->elemSize = sizeof(char);
array(char)* buff = memoryAlloc(sizeof(array(char)));

buff->length = 0;
buff->elemSize = sizeof(char);
while ((i<this->length)) {
char c =  this->charAt((struct string*)this,i);
char rc =  needle.charAt((struct string*)&needle,si);
if ((c==rc)) {
si =  si + 1;

{
long nLength = len(replcBuff);
if (replcBuff->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(replcBuff->data, (nLength+50)*sizeof(char));
replcBuff->data = newPtr;
}
replcBuff->data[len(replcBuff)] =  c;
replcBuff->length = nLength+1;
} else {
replcBuff->data[len(replcBuff)] =  c;
};
};
}
else {
if ((len(replcBuff)>0)) {
si =  0;
append(buff,replcBuff);
clear(replcBuff);
}

{
long nLength = len(buff);
if (buff->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(buff->data, (nLength+50)*sizeof(char));
buff->data = newPtr;
}
buff->data[len(buff)] =  c;
buff->length = nLength+1;
} else {
buff->data[len(buff)] =  c;
};
};
}
if ((si==needle.length)) {
clear(replcBuff);
long int ii =  0;
while ((ii<repl.length)) {
long int a =  ii;

{
long nLength = len(buff);
if (buff->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(buff->data, (nLength+50)*sizeof(char));
buff->data = newPtr;
}
buff->data[len(buff)] =  repl.charAt((struct string*)&repl,ii);
buff->length = nLength+1;
} else {
buff->data[len(buff)] =  repl.charAt((struct string*)&repl,ii);
};
};
ii =  ii + 1;
};
si =  0;
}
i =  i + 1;
};
char * r =  "";
noCheck( r = buff -> data );
if ((len(replcBuff)>0)) {
char * replbuffStr;
noCheck( replbuffStr = replcBuff -> data );
r =  concatCPSTRING(r,replbuffStr);
}
if (((void *)r!=null)) {
this->set((struct string*)this,r);
}
};
long int string__count(struct string* this,char * need){
long int i =  0;
long int count =  0;
struct string needle =  {};
needle.set = string__set;
needle.append = string__append;
needle.prepend = string__prepend;
needle.charAt = string__charAt;
needle.compare = string__compare;
needle.str = string__str;
needle.replace = string__replace;
needle.count = string__count;
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
return ;
}
char fc =  this->charAt((struct string*)this,0);
if ((isSpace(fc)==0)) {
return ;
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
struct string string(char * s){
struct string a =  {};
a.set = string__set;
a.append = string__append;
a.prepend = string__prepend;
a.charAt = string__charAt;
a.compare = string__compare;
a.str = string__str;
a.replace = string__replace;
a.count = string__count;
a.hasPrefix = string__hasPrefix;
a.hasSuffix = string__hasSuffix;
a.trim = string__trim;
a.trimLeft = string__trimLeft;
a.trimRight = string__trimRight;
a.content =  (char *)0;
a.length =  0;
a.set((struct string*)&a,s);
return a;
};
char * arrToStr(__BAH_ARR_TYPE_char arr){
long int strLen =  len(arr);
char * str =  memoryAlloc(strLen + 1);
noCheck( memcpy ( str , arr -> data , strLen ) );
return str;
};
__BAH_ARR_TYPE_char strToArr(char * str){
long int strLen =  strlen(str);
array(char)* arr = memoryAlloc(sizeof(array(char)));

arr->length = 0;
arr->elemSize = sizeof(char);
noCheck( arr -> data = memoryAlloc ( strLen + 1 ) );
noCheck( memcpy ( arr -> data , str , strLen ) );
noCheck( arr -> elemSize = 1 );
noCheck( arr -> length = strLen );
return arr;
};
char * arrAsStr(__BAH_ARR_TYPE_char arr){
char * r =  "";
noCheck( r = arr -> data );
return r;
};
__BAH_ARR_TYPE_char strAsArr(char * str){
long int l =  strlen(str);
array(char)* arr = memoryAlloc(sizeof(array(char)));

arr->length = 0;
arr->elemSize = sizeof(char);
noCheck( arr -> length = l );
noCheck( arr -> elemSize = 1 );
noCheck( arr -> data = str );
return arr;
};
struct string intToString(long int i){
char * buff =  memoryAlloc(65);
void * ptri =  (void *)i;
sprintf(buff,"%d",ptri);
struct string r =  string(buff);
return r;
};
char * intToStr(long int i){
char * buff =  memoryAlloc(50);
sprintf(buff,"%ld",i);
return buff;
};
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
long int stringToInt(struct string s){
long int i =  atol(s.content);
return i;
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
replcBuff.append((struct string*)&replcBuff,charToString(c));
}
else {
if ((sepIndex>0)) {
sepIndex =  0;
replcBuff.append((struct string*)&replcBuff,charToString(c));
long int ii =  0;
while ((ii<replcBuff.length)) {

{
long nLength = len(tmpString);
if (tmpString->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(tmpString->data, (nLength+50)*sizeof(char));
tmpString->data = newPtr;
}
tmpString->data[len(tmpString)] =  replcBuff.charAt((struct string*)&replcBuff,ii);
tmpString->length = nLength+1;
} else {
tmpString->data[len(tmpString)] =  replcBuff.charAt((struct string*)&replcBuff,ii);
};
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
void * newPtr = GC_REALLOC(tmpString->data, (nLength+50)*sizeof(char));
tmpString->data = newPtr;
}
tmpString->data[len(tmpString)] =  c;
tmpString->length = nLength+1;
} else {
tmpString->data[len(tmpString)] =  c;
};
};
}
}
if ((sepIndex==sep.length)) {
replcBuff.set((struct string*)&replcBuff,"");
struct string* elem = memoryAlloc(sizeof(struct string));
elem->set = string__set;
elem->append = string__append;
elem->prepend = string__prepend;
elem->charAt = string__charAt;
elem->compare = string__compare;
elem->str = string__str;
elem->replace = string__replace;
elem->count = string__count;
elem->hasPrefix = string__hasPrefix;
elem->hasSuffix = string__hasSuffix;
elem->trim = string__trim;
elem->trimLeft = string__trimLeft;
elem->trimRight = string__trimRight;
elem->set((struct string*)elem,arrToStr(tmpString));
long int lenRes =  len(res);

{
long nLength = lenRes;
if (res->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(res->data, (nLength+50)*sizeof(struct string));
res->data = newPtr;
}
res->data[lenRes] =  *elem;
res->length = nLength+1;
} else {
res->data[lenRes] =  *elem;
};
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
void * newPtr = GC_REALLOC(tmpString->data, (nLength+50)*sizeof(char));
tmpString->data = newPtr;
}
tmpString->data[len(tmpString)] =  replcBuff.charAt((struct string*)&replcBuff,ii);
tmpString->length = nLength+1;
} else {
tmpString->data[len(tmpString)] =  replcBuff.charAt((struct string*)&replcBuff,ii);
};
};
ii =  ii + 1;
};
}
if ((len(tmpString)>0)) {
struct string* elem = memoryAlloc(sizeof(struct string));
elem->set = string__set;
elem->append = string__append;
elem->prepend = string__prepend;
elem->charAt = string__charAt;
elem->compare = string__compare;
elem->str = string__str;
elem->replace = string__replace;
elem->count = string__count;
elem->hasPrefix = string__hasPrefix;
elem->hasSuffix = string__hasSuffix;
elem->trim = string__trim;
elem->trimLeft = string__trimLeft;
elem->trimRight = string__trimRight;
elem->set((struct string*)elem,arrToStr(tmpString));
long int lenRes =  len(res);

{
long nLength = lenRes;
if (res->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(res->data, (nLength+50)*sizeof(struct string));
res->data = newPtr;
}
res->data[lenRes] =  *elem;
res->length = nLength+1;
} else {
res->data[lenRes] =  *elem;
};
};
}
return res;
};
struct string joinString(__BAH_ARR_TYPE_string a,char * sep){
long int i =  0;
struct string s =  string("");
long int max =  len(a) - 1;
while ((i<len(a))) {
struct string e =  a->data[i];
if ((e.length==0)) {
i =  i + 1;
continue;
}
struct string tmpS =  string(e.str((struct string*)&e));
if ((i!=max)) {
tmpS.append((struct string*)&tmpS,sep);
}
s.append((struct string*)&s,tmpS.str((struct string*)&tmpS));
i =  i + 1;
};
return s;
};
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
void * newPtr = GC_REALLOC(ns->data, (nLength+50)*sizeof(char));
ns->data = newPtr;
}
ns->data[len(ns)] =  c;
ns->length = nLength+1;
} else {
ns->data[len(ns)] =  c;
};
};
i =  i + 1;
};
return string(arrToStr(ns));
};
int strHasPrefix(char * s,char * need){
long int i =  0;
long int nl =  strlen(need);
long int sl =  strlen(s);
if ((sl<nl)) {
return false;
}
while ((i<nl)) {
char c =  cpstringCharAt(s,i);
char sc =  cpstringCharAt(need,i);
if ((c!=sc)) {
return false;
}
i =  i + 1;
};
return true;
};
void strTrimLeft(char ** s,long int i){
*s =  noCheck( *s + i );
};
void strTrimRight(char ** s,long int i){
long int ls =  strlen(*s);
char * ns =  memoryAlloc(ls - i);
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
return count;
};
char * stdinput(long int len){
char * buff =  memoryAlloc(len);
fgets(buff,len,noCheck( stdin ));
return buff;
};
void print(char * s){
write((void *)1,s,strlen(s));
};
void println(char * s){
write((void *)1,s,strlen(s));
write((void *)1,"\n",1);
};
void panic(char * e){
if (strlen(e)) {
println(e);
exit(1);
}
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
return ;
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
return ;
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
char * r =  memoryAlloc(sz + 1);
long int l =  fread(r,1,sz,this->handle);
if ((sz!=l)) {
array(char)* rarr =  strAsArr(r);

{
long nLength = l;
if (rarr->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(rarr->data, (nLength+50)*sizeof(char));
rarr->data = newPtr;
}
rarr->data[l] =  (char)0;
rarr->length = nLength+1;
} else {
rarr->data[l] =  (char)0;
};
};
}
return r;
};
__BAH_ARR_TYPE_char fileStream__readBytes(struct fileStream* this){
array(char)* r = memoryAlloc(sizeof(array(char)));

r->length = 0;
r->elemSize = sizeof(char);
allocateArray(r,this->getSize((struct fileStream*)this));
this->readPtr((struct fileStream*)this,noCheck( r -> data ),len(r));
return r;
};
void fileStream__writeBytes(struct fileStream* this,__BAH_ARR_TYPE_char d){
this->writePtr((struct fileStream*)this,noCheck( d -> data ),len(d));
};
struct fileMap {
long int handle;
long int size;
char *(*open)(struct fileMap* this,char * fileName);
long int(*isValid)(struct fileMap* this);
void(*close)(struct fileMap* this);
};
char * fileMap__open(struct fileMap* this,char * fileName){
this->handle =  open(fileName,noCheck( O_RDWR ),noCheck( S_IRUSR | S_IWUSR ));
struct stat sb =  {};
fstat(this->handle,&sb);
this->size =  sb.st_size;
char * file =  mmap(0,sb.st_size,noCheck( PROT_READ | PROT_WRITE ),noCheck( MAP_SHARED ),this->handle,0);
return file;
};
long int fileMap__isValid(struct fileMap* this){
if ((this->handle<0)) {
return 0;
}
return 1;
};
void fileMap__close(struct fileMap* this){
close(this->handle);
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
void * newPtr = GC_REALLOC(files->data, (nLength+50)*sizeof(char *));
files->data = newPtr;
}
files->data[lf] =  file->d_name;
files->length = nLength+1;
} else {
files->data[lf] =  file->d_name;
};
};
file =  readdir(d);
};
closedir(d);
return files;
};
long int fileExists(char * path){
long int is =  access(path,0);
if ((is==0)) {
return 1;
}
return 0;
};
int removeFile(char * name){
if ((remove(name)==0)) {
return true;
}
return false;
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
struct flag* f = memoryAlloc(sizeof(struct flag));
f->name =  name;
f->help =  help;
f->type =  FLAG_TYPE_CPSTRING;
long int lf =  len(this->flags);

{
long nLength = lf;
if (this->flags->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(this->flags->data, (nLength+50)*sizeof(struct flag*));
this->flags->data = newPtr;
}
this->flags->data[lf] =  f;
this->flags->length = nLength+1;
} else {
this->flags->data[lf] =  f;
};
};
};
void flags__addBool(struct flags* this,char * name,char * help){
struct flag* f = memoryAlloc(sizeof(struct flag));
f->name =  name;
f->help =  help;
f->type =  FLAG_TYPE_BOOL;
long int lf =  len(this->flags);

{
long nLength = lf;
if (this->flags->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(this->flags->data, (nLength+50)*sizeof(struct flag*));
this->flags->data = newPtr;
}
this->flags->data[lf] =  f;
this->flags->length = nLength+1;
} else {
this->flags->data[lf] =  f;
};
};
};
void flags__addInt(struct flags* this,char * name,char * help){
struct flag* f = memoryAlloc(sizeof(struct flag));
f->name =  name;
f->help =  help;
f->type =  FLAG_TYPE_INT;
long int lf =  len(this->flags);

{
long nLength = lf;
if (this->flags->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(this->flags->data, (nLength+50)*sizeof(struct flag*));
this->flags->data = newPtr;
}
this->flags->data[lf] =  f;
this->flags->length = nLength+1;
} else {
this->flags->data[lf] =  f;
};
};
};
void flags__addFloat(struct flags* this,char * name,char * help){
struct flag* f = memoryAlloc(sizeof(struct flag));
f->name =  name;
f->help =  help;
f->type =  FLAG_TYPE_FLOAT;
long int lf =  len(this->flags);

{
long nLength = lf;
if (this->flags->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(this->flags->data, (nLength+50)*sizeof(struct flag*));
this->flags->data = newPtr;
}
this->flags->data[lf] =  f;
this->flags->length = nLength+1;
} else {
this->flags->data[lf] =  f;
};
};
};
void flags__invalidate(struct flags* this){
print("Usage of ");
print(this->args->data[0]);
println(":");
long int i =  0;
while ((i<len(this->flags))) {
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
struct flag* flag =  this->flags->data[i];
if (name.compare((struct string*)&name,flag->name)) {
return flag;
}
i =  i + 1;
};
struct flag* z = memoryAlloc(sizeof(struct flag));
z->isSet =  0;
return z;
};
char * flags__get(struct flags* this,char * name){
struct flag* flag =  this->getFlag((struct flags*)this,string(name));
char * ctn =  flag->content;
return ctn;
};
long int flags__getInt(struct flags* this,char * name){
struct flag* flag =  this->getFlag((struct flags*)this,string(name));
if ((flag->type!=FLAG_TYPE_INT)) {

                        char* ____BAH_COMPILER_VAR_0; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("Flag '");
long int strLen_1 = strlen(flag->name);
long int strLen_2 = strlen("' is not int.");
;                            
                            ____BAH_COMPILER_VAR_0 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                            
                            strncpy(____BAH_COMPILER_VAR_0+currStrOff, "Flag '", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_0+currStrOff, flag->name, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_0+currStrOff, "' is not int.", strLen_2);
                            currStrOff += strLen_2;
                            
                        }
                        char * error =  ____BAH_COMPILER_VAR_0;
panic(error);
}
long int ctn =  flag->cont_int;
return ctn;
};
double flags__getFloat(struct flags* this,char * name){
struct flag* flag =  this->getFlag((struct flags*)this,string(name));
if ((flag->type!=FLAG_TYPE_FLOAT)) {

                        char* ____BAH_COMPILER_VAR_1; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("Flag '");
long int strLen_1 = strlen(flag->name);
long int strLen_2 = strlen("' is not float.");
;                            
                            ____BAH_COMPILER_VAR_1 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                            
                            strncpy(____BAH_COMPILER_VAR_1+currStrOff, "Flag '", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_1+currStrOff, flag->name, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_1+currStrOff, "' is not float.", strLen_2);
                            currStrOff += strLen_2;
                            
                        }
                        char * error =  ____BAH_COMPILER_VAR_1;
panic(error);
}
double ctn =  flag->cont_float;
return ctn;
};
long int flags__isSet(struct flags* this,char * name){
struct flag* flag =  this->getFlag((struct flags*)this,string(name));
long int ctn =  flag->isSet;
return ctn;
};
void flags__parse(struct flags* this,__BAH_ARR_TYPE_cpstring args){
struct flag* currentFlag;
int isVal =  false;
this->args =  args;
long int i =  1;
while ((i<len(args))) {
struct string argName =  string(args->data[i]);
if ((isVal==true)) {
currentFlag->content =  argName.str((struct string*)&argName);
if ((currentFlag->type==FLAG_TYPE_INT)) {
currentFlag->cont_int =  atoi(argName.str((struct string*)&argName));
}
else if ((currentFlag->type==FLAG_TYPE_FLOAT)) {
currentFlag->cont_float =  strtod(argName.str((struct string*)&argName),0);
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
struct timespec ts =  {};
long int s =  clock_gettime(noCheck( CLOCK_REALTIME ),&ts);
s =  ts.tv_sec * 1000000000 + ts.tv_nsec;
return s;
};
long int RAND_SEEDED =  0;
void seedRandom(long int i){
srand(i);
RAND_SEEDED =  1;
};
long int randomInRange(long int min,long int max){
if ((RAND_SEEDED==0)) {
srand(time(0));
RAND_SEEDED =  1;
}
long int range =  max - min;
long int i =  rand() % range + 1;
i =  i + min;
return i;
};
long int cryptoRand(){
struct fileStream fs =  {};
fs.isValid = fileStream__isValid;
fs.open = fileStream__open;
fs.close = fileStream__close;
fs.getPos = fileStream__getPos;
fs.setPos = fileStream__setPos;
fs.getSize = fileStream__getSize;
fs.rewind = fileStream__rewind;
fs.getChar = fileStream__getChar;
fs.createFile = fileStream__createFile;
fs.writeFile = fileStream__writeFile;
fs.writePtr = fileStream__writePtr;
fs.readPtr = fileStream__readPtr;
fs.readContent = fileStream__readContent;
fs.readBytes = fileStream__readBytes;
fs.writeBytes = fileStream__writeBytes;
fs.open((struct fileStream*)&fs,"/dev/urandom","r");
char c =  fs.getChar((struct fileStream*)&fs);
fs.close((struct fileStream*)&fs);
long int i =  (long int)c;
return i;
};
struct command {
char * command;
int error;
long int status;
FILE* handle;
char *(*run)(struct command* this);
};
char * command__run(struct command* this){
char * cm =  this->command;
if ((this->error==false)) {
cm =  concatCPSTRING(cm," 2>/dev/null");
}
else {
cm =  concatCPSTRING(cm," 2>&1");
}
this->handle =  popen(cm,"r");
if ((this->handle==null)) {
return "";
}
char * buff =  memoryAlloc(1025);
char * res =  "";
char * more =  "";
while (((void *)more!=null)) {
memset(buff,0,1025);
more =  fgets(buff,1024,this->handle);
res =  concatCPSTRING(res,buff);
};
this->status =  pclose(this->handle);
return res;
};
struct command command(char * s){
struct command cmd =  {};
cmd.error = true;
cmd.status = 0;
cmd.run = command__run;
cmd.command =  s;
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
void * newPtr = GC_REALLOC(nArgs->data, (nLength+50)*sizeof(char *));
nArgs->data = newPtr;
}
nArgs->data[0] =  s;
nArgs->length = nLength+1;
} else {
nArgs->data[0] =  s;
};
};
long int i =  0;
while ((i<len(args))) {

{
long nLength = i + 1;
if (nArgs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(nArgs->data, (nLength+50)*sizeof(char *));
nArgs->data = newPtr;
}
nArgs->data[i + 1] =  args->data[i];
nArgs->length = nLength+1;
} else {
nArgs->data[i + 1] =  args->data[i];
};
};
i =  i + 1;
};

{
long nLength = i + 2;
if (nArgs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(nArgs->data, (nLength+50)*sizeof(char *));
nArgs->data = newPtr;
}
nArgs->data[i + 2] =  (char *)0;
nArgs->length = nLength+1;
} else {
nArgs->data[i + 2] =  (char *)0;
};
};
noCheck( r = execvp ( s , nArgs -> data ) );
return r;
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
return this;
}
return this->parent->getParent((struct rope*)this->parent);
};
void rope__addStr(struct rope* this,char ** s){
if (((this->left==null)&&(this->right==null))) {
strcat(*s,this->str);
return ;
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
struct rope* tmp = memoryAlloc(sizeof(struct rope));
tmp->getParent = rope__getParent;
tmp->addStr = rope__addStr;
tmp->toStr = rope__toStr;
tmp->add = rope__add;
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
struct rope* tmp = memoryAlloc(sizeof(struct rope));
tmp->getParent = rope__getParent;
tmp->addStr = rope__addStr;
tmp->toStr = rope__toStr;
tmp->add = rope__add;
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
return tmp;
};
struct rope* concatenateRopes(struct rope* root1,struct rope* root2){
long int n1 =  root1->len;
struct rope* tmp = memoryAlloc(sizeof(struct rope));
tmp->getParent = rope__getParent;
tmp->addStr = rope__addStr;
tmp->toStr = rope__toStr;
tmp->add = rope__add;
tmp->parent =  null;
tmp->left =  root1;
tmp->right =  root2;
root2->parent =  tmp;
root1->parent =  root2->parent;
tmp->totalLen =  root1->totalLen + root2->totalLen;
tmp->str =  null;
return tmp;
};
struct rope* rope(char * a){
long int n1 =  strlen(a);
struct rope* r =  createRopeStructure(null,a,0,n1-1);
r->totalLen =  n1;
r->len =  n1;
return r;
};
#define BAH_DIR "/opt/bah/"
#define BAH_VERSION "v1.0 (build 29)"
struct rope* OUTPUT;
char * NEXT_LINE =  "";
struct variable {
char * name;
char * type;
int isConst;
int isArray;
char * from;
};
struct structMemb {
char * name;
char * type;
int isConst;
int isArray;
char * from;
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
};
struct Elems {
array(struct variable*)* vars;
array(struct cStruct*)* structs;
array(char *)* types;
array(struct func*)* fns;
};
struct compilerStateTag {
array(char *)* includes;
array(char *)* cLibs;
char * currentFile;
int isBranch;
int isFor;
array(char *)* arrTypesDecl;
int haveEntryPoint;
};
struct compilerStateTag compilerState;
struct cStruct* currentCStruct;
long int threadCount =  0;
struct func* currentFn;
long int totalLines =  0;
long int totalLexerTime =  0;
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
char * bahType;
int isValue;
int isFunc;
};
int inArray(char needle,__BAH_ARR_TYPE_char arr){
long int i =  0;
while ((i<len(arr))) {
if ((needle==arr->data[i])) {
return true;
}
i =  i + 1;
};
return false;
};
int inArrayStr(char * needle,__BAH_ARR_TYPE_cpstring arr){
long int i =  0;
while ((i<len(arr))) {
if ((strcmp(needle, arr->data[i]) == 0)) {
return true;
}
i =  i + 1;
};
return false;
};
struct Tok makeToken(long int pos,long int lineNb,__BAH_ARR_TYPE_char cont,tokenType type){
struct Tok t =  {};
t.cont = "";
t.ogCont = "";
t.type = TOKEN_NO_TYPE;
t.pos = 0;
t.line = 1;
t.bahType = "";
t.isValue = false;
t.isFunc = false;
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
int isMinus(char c,char nc){
if ((c==45)) {
if (isNumber(nc)) {
return true;
}
}
return false;
};
void lexerErr(long int line,long int pos,char * msg){
char * lineStr =  intToStr(line);
char * posStr =  intToStr(pos);

                        char* ____BAH_COMPILER_VAR_2; 
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
                            ____BAH_COMPILER_VAR_2 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7);
                            
                            strncpy(____BAH_COMPILER_VAR_2+currStrOff, "\e[1;31m[LEXER-ERROR]\e[0m ", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_2+currStrOff, compilerState.currentFile, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_2+currStrOff, ":", strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_2+currStrOff, lineStr, strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_2+currStrOff, ":", strLen_4);
                            currStrOff += strLen_4;
                            
                            strncpy(____BAH_COMPILER_VAR_2+currStrOff, posStr, strLen_5);
                            currStrOff += strLen_5;
                            
                            strncpy(____BAH_COMPILER_VAR_2+currStrOff, "\n\e[0m\n", strLen_6);
                            currStrOff += strLen_6;
                            
                            strncpy(____BAH_COMPILER_VAR_2+currStrOff, msg, strLen_7);
                            currStrOff += strLen_7;
                            
                        }
                        println(____BAH_COMPILER_VAR_2);
exit(1);
};
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
array(char)* enclavers = memoryAlloc(sizeof(array(char)));

enclavers->length = 6;
enclavers->elemSize = sizeof(char);
enclavers->data = memoryAlloc(sizeof(char) * 50);enclavers->data[0] = 40;
enclavers->data[1] = 41;
enclavers->data[2] = 123;
enclavers->data[3] = 125;
enclavers->data[4] = 91;
enclavers->data[5] = 93;
array(char)* syntaxes = memoryAlloc(sizeof(array(char)));

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
array(char *)* keywords = memoryAlloc(sizeof(array(char *)));

keywords->length = 16;
keywords->elemSize = sizeof(char *);
keywords->data = memoryAlloc(sizeof(char *) * 50);keywords->data[0] = __STR("if");
keywords->data[1] = __STR("else");
keywords->data[2] = __STR("for");
keywords->data[3] = __STR("struct");
keywords->data[4] = __STR("const");
keywords->data[5] = __STR("return");
keywords->data[6] = __STR("extend");
keywords->data[7] = __STR("new");
keywords->data[8] = __STR("break");
keywords->data[9] = __STR("continue");
keywords->data[10] = __STR("default");
keywords->data[11] = __STR("switch");
keywords->data[12] = __STR("case");
keywords->data[13] = __STR("while");
keywords->data[14] = __STR("typedef");
keywords->data[15] = __STR("function");
array(char)* varChars = memoryAlloc(sizeof(array(char)));

varChars->length = 1;
varChars->elemSize = sizeof(char);
varChars->data = memoryAlloc(sizeof(char) * 50);varChars->data[0] = 95;
array(char)* seps = memoryAlloc(sizeof(array(char)));

seps->length = 1;
seps->elemSize = sizeof(char);
seps->data = memoryAlloc(sizeof(char) * 50);seps->data[0] = 46;
long int i =  0;
while ((i<codeLength)) {
char c =  s->data[i];
long int nci =  i + 1;
char nc =  (char)0;
if ((nci<codeLength)) {
nc =  s->data[i + 1];
}
if ((c==47)) {
nc =  s->data[i + 1];
if ((nc==47)) {
while ((i<codeLength)) {
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

{
long nLength = 0;
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[0] =  c;
memory->length = nLength+1;
} else {
memory->data[0] =  c;
};
};
i =  i + 1;
while ((i<codeLength)) {
c =  s->data[i];
char pc =  s->data[i-1];
if ((c==(char)34)) {
if ((pc!=(char)92)) {

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[len(memory)] =  c;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  c;
};
};
break;
}
}
if ((c==(char)10)) {
if ((pc!=(char)92)) {

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[len(memory)] =  (char)92;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  (char)92;
};
};
c =  110;
}
}

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[len(memory)] =  c;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  c;
};
};
i =  i + 1;
};

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] =  makeToken(pos,lineNb,memory,TOKEN_TYPE_STR);
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] =  makeToken(pos,lineNb,memory,TOKEN_TYPE_STR);
};
};
}
else if ((isNumber(c)||isMinus(c,nc))) {

{
long nLength = 0;
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[0] =  c;
memory->length = nLength+1;
} else {
memory->data[0] =  c;
};
};
long int pos =  i;
i =  i + 1;
tokenType currentType =  TOKEN_TYPE_INT;
while ((i<codeLength)) {
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
void * newPtr = GC_REALLOC(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[len(memory)] =  c;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  c;
};
};
i =  i + 1;
};
i =  i - 1;

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] =  makeToken(pos,lineNb,memory,currentType);
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] =  makeToken(pos,lineNb,memory,currentType);
};
};
}
else if ((c==(char)39)) {
i =  i + 1;
char n =  s->data[i];
char * toInt =  intToStr((long int)nc);
memory =  strToArr(toInt);
i =  i + 1;
c =  s->data[i];
if ((c!=(char)39)) {
lexerErr(lineNb,i,"Missing closing tag in char declaration.");
}

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] =  makeToken(i-1,lineNb,memory,TOKEN_TYPE_CHAR);
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] =  makeToken(i-1,lineNb,memory,TOKEN_TYPE_CHAR);
};
};
}
else if ((c==(char)35)) {
long int pos =  i;

{
long nLength = 0;
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[0] =  c;
memory->length = nLength+1;
} else {
memory->data[0] =  c;
};
};
i =  i + 1;
while ((i<codeLength)) {
c =  s->data[i];
if ((isAlphaNumeric(c)==0)) {
break;
}

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[len(memory)] =  c;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  c;
};
};
i =  i + 1;
};
i =  i - 1;

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] =  makeToken(pos,lineNb,memory,TOKEN_TYPE_KEYWORD);
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] =  makeToken(pos,lineNb,memory,TOKEN_TYPE_KEYWORD);
};
};
}
else if (inArray(c,enclavers)) {

{
long nLength = 0;
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[0] =  c;
memory->length = nLength+1;
} else {
memory->data[0] =  c;
};
};

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] =  makeToken(i,lineNb,memory,TOKEN_TYPE_ENCL);
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] =  makeToken(i,lineNb,memory,TOKEN_TYPE_ENCL);
};
};
}
else if (inArray(c,syntaxes)) {

{
long nLength = 0;
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[0] =  c;
memory->length = nLength+1;
} else {
memory->data[0] =  c;
};
};
long int pos =  i;
i =  i + 1;
char fc =  c;
while ((i<codeLength)) {
c =  s->data[i];
if ((inArray(c,syntaxes)==false)) {
break;
}
if ((c==124)) {
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
void * newPtr = GC_REALLOC(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[len(memory)] =  c;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  c;
};
};
i =  i + 1;
};
i =  i - 1;

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] =  makeToken(pos,lineNb,memory,TOKEN_TYPE_SYNTAX);
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] =  makeToken(pos,lineNb,memory,TOKEN_TYPE_SYNTAX);
};
};
}
else if (inArray(c,seps)) {

{
long nLength = 0;
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[0] =  c;
memory->length = nLength+1;
} else {
memory->data[0] =  c;
};
};

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] =  makeToken(i,lineNb,memory,TOKEN_TYPE_SEP);
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] =  makeToken(i,lineNb,memory,TOKEN_TYPE_SEP);
};
};
}
else if ((isAlphaNumeric(c)||inArray(c,varChars))) {

{
long nLength = 0;
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[0] =  c;
memory->length = nLength+1;
} else {
memory->data[0] =  c;
};
};
long int pos =  i;
i =  i + 1;
while ((i<codeLength)) {
c =  s->data[i];
if ((isAlphaNumeric(c)==0)) {
if ((inArray(c,varChars)==false)) {
if ((c==62)) {
char lc =  memory->data[len(memory)-1];
if ((lc==45)) {

{
long nLength = len(memory)-1;
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[len(memory)-1] =  (char)0;
memory->length = nLength+1;
} else {
memory->data[len(memory)-1] =  (char)0;
};
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
void * newPtr = GC_REALLOC(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[len(memory)] =  c;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  c;
};
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
void * newPtr = GC_REALLOC(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] =  makeToken(pos,lineNb,memory,currentType);
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] =  makeToken(pos,lineNb,memory,currentType);
};
};
}
i =  i + 1;
};
totalLines =  totalLines + lineNb - 1;
dur =  getTimeUnix() - dur;
totalLexerTime =  totalLexerTime + dur;
return tokens;
};
int hasStructSep(struct string n){
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
struct string res =  string(splitStringBefore(n,"."));
return res;
}
if (n.count((struct string*)&n,"->")) {
struct string res =  string(splitStringBefore(n,"->"));
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
struct structMemb* m =  members->data[i];
if ((strcmp(m->name, name) == 0)) {
return m;
}
i =  i + 1;
};
array(struct func*)* mthds =  s->methods;
i =  0;
while ((i<len(mthds))) {
struct func* m =  mthds->data[i];
if ((strcmp(m->name, name) == 0)) {
struct structMemb* sm = memoryAlloc(sizeof(struct structMemb));
sm->name = "";
sm->type = "";
sm->isConst = false;
sm->isArray = false;
sm->from = "";
sm->def = "";
sm->isFn = false;
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

                        char* ____BAH_COMPILER_VAR_3; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("array(");
long int strLen_1 = strlen(t);
long int strLen_2 = strlen(")*");
;                            
                            ____BAH_COMPILER_VAR_3 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                            
                            strncpy(____BAH_COMPILER_VAR_3+currStrOff, "array(", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_3+currStrOff, t, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_3+currStrOff, ")*", strLen_2);
                            currStrOff += strLen_2;
                            
                        }
                        char * r =  ____BAH_COMPILER_VAR_3;
return string(r);
}
struct string ctp =  tp;
ctp.replace((struct string*)&ctp,"*","");
if (ctp.compare((struct string*)&ctp,"int")) {
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
int compTypes(char * a,char * b){
if ((strcmp(a, "ptr") == 0)) {
return true;
}
if ((strcmp(b, "ptr") == 0)) {
return true;
}
if ((strcmp(a, b) == 0)) {
return true;
}
return false;
};
void throwErr(void * tp,char * format){
char * str =  "";
char * info =  "";
if ((tp!=null)) {
struct fileMap fm =  {};
fm.open = fileMap__open;
fm.isValid = fileMap__isValid;
fm.close = fileMap__close;
char * fileSrcStr =  fm.open((struct fileMap*)&fm,compilerState.currentFile);
struct string fileSrc =  string(fileSrcStr);
fm.close((struct fileMap*)&fm);
struct Tok* t =  tp;
struct string ffmt =  string(format);
if ((strlen(t->ogCont)==0)) {
t->ogCont =  t->cont;
}

                        char* ____BAH_COMPILER_VAR_4; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("'");
long int strLen_1 = strlen(t->ogCont);
long int strLen_2 = strlen("'");
;                            
                            ____BAH_COMPILER_VAR_4 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                            
                            strncpy(____BAH_COMPILER_VAR_4+currStrOff, "'", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_4+currStrOff, t->ogCont, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_4+currStrOff, "'", strLen_2);
                            currStrOff += strLen_2;
                            
                        }
                        ffmt.replace((struct string*)&ffmt,"{TOKEN}",____BAH_COMPILER_VAR_4);
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
long int pos =  t->pos - beg;
long int i =  beg;
while ((i<fileSrc.length)) {
char c =  fileSrc.charAt((struct string*)&fileSrc,i);
if ((c==(char)10)) {
break;
}
if ((i==t->pos)) {

                        char* ____BAH_COMPILER_VAR_5; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("\e[1;31m");
long int strLen_1 = strlen(t->ogCont);
long int strLen_2 = strlen("\e[1;37m");
;                            
                            ____BAH_COMPILER_VAR_5 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                            
                            strncpy(____BAH_COMPILER_VAR_5+currStrOff, "\e[1;31m", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_5+currStrOff, t->ogCont, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_5+currStrOff, "\e[1;37m", strLen_2);
                            currStrOff += strLen_2;
                            
                        }
                        array(char)* errTk =  strToArr(____BAH_COMPILER_VAR_5);
long int ii =  0;
while ((ii<len(errTk))) {

{
long nLength = len(line);
if (line->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(line->data, (nLength+50)*sizeof(char));
line->data = newPtr;
}
line->data[len(line)] =  errTk->data[ii];
line->length = nLength+1;
} else {
line->data[len(line)] =  errTk->data[ii];
};
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
void * newPtr = GC_REALLOC(line->data, (nLength+50)*sizeof(char));
line->data = newPtr;
}
line->data[len(line)] =  c;
line->length = nLength+1;
} else {
line->data[len(line)] =  c;
};
};
i =  i + 1;
};
str =  arrToStr(line);
info =  intToStr(t->line);
}

                        char* ____BAH_COMPILER_VAR_6; 
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
                            ____BAH_COMPILER_VAR_6 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7);
                            
                            strncpy(____BAH_COMPILER_VAR_6+currStrOff, "\e[1;31m[ERROR]\e[0m ", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_6+currStrOff, compilerState.currentFile, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_6+currStrOff, ":", strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_6+currStrOff, info, strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_6+currStrOff, "\n\e[1;37m\t", strLen_4);
                            currStrOff += strLen_4;
                            
                            strncpy(____BAH_COMPILER_VAR_6+currStrOff, str, strLen_5);
                            currStrOff += strLen_5;
                            
                            strncpy(____BAH_COMPILER_VAR_6+currStrOff, "\e[0m\n", strLen_6);
                            currStrOff += strLen_6;
                            
                            strncpy(____BAH_COMPILER_VAR_6+currStrOff, format, strLen_7);
                            currStrOff += strLen_7;
                            
                        }
                        println(____BAH_COMPILER_VAR_6);
exit(1);
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
struct variable* nv = memoryAlloc(sizeof(struct variable));
nv->name = "";
nv->type = "";
nv->isConst = false;
nv->isArray = false;
nv->from = "";
nv->type =  vtstr;
nv->name =  ogName;
nv->isArray =  true;
return nv;
}
name =  n.content;
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
struct variable* nv = memoryAlloc(sizeof(struct variable));
nv->name = "";
nv->type = "";
nv->isConst = false;
nv->isArray = false;
nv->from = "";
nv->from =  memb->from;
nv->name =  memb->name;
nv->type =  memb->type;
nv->name =  ogName;
char * r =  nv->type;
struct string tcc =  string(ogName);
if (tcc.count((struct string*)&tcc,"&")) {
r =  concatCPSTRING(r,"*");
}
long int nbUnaries =  tcc.count((struct string*)&tcc,"*");
if ((nbUnaries>0)) {
struct string ct =  string(r);
long int pointerLevel =  ct.count((struct string*)&ct,"*");
if ((pointerLevel<nbUnaries)) {

                        char* ____BAH_COMPILER_VAR_7; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("Cannot use '*' on ");
long int strLen_1 = strlen(nv->name);
long int strLen_2 = strlen(" because it is not pointer.");
;                            
                            ____BAH_COMPILER_VAR_7 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                            
                            strncpy(____BAH_COMPILER_VAR_7+currStrOff, "Cannot use '*' on ", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_7+currStrOff, nv->name, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_7+currStrOff, " because it is not pointer.", strLen_2);
                            currStrOff += strLen_2;
                            
                        }
                        throwErr(null,____BAH_COMPILER_VAR_7);
}
ct.trimRight((struct string*)&ct,nbUnaries);
r =  ct.str((struct string*)&ct);
}
nv->type =  r;
nv->name =  ogName;
return nv;
}
long int i =  0;
while ((i<len(elems->vars))) {
struct variable* v =  elems->vars->data[i];
if ((v==null)) {

                        char* ____BAH_COMPILER_VAR_8; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("\e[1;31m[INTERNAL COMPILER ERROR]\e[0m\n Please report the bug as 'compiler searching '");
long int strLen_1 = strlen(name);
long int strLen_2 = strlen("' resulting in null var'.");
;                            
                            ____BAH_COMPILER_VAR_8 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                            
                            strncpy(____BAH_COMPILER_VAR_8+currStrOff, "\e[1;31m[INTERNAL COMPILER ERROR]\e[0m\n Please report the bug as 'compiler searching '", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_8+currStrOff, name, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_8+currStrOff, "' resulting in null var'.", strLen_2);
                            currStrOff += strLen_2;
                            
                        }
                        panic(____BAH_COMPILER_VAR_8);
}
if ((strcmp(v->name, name) == 0)) {
struct variable* nv = memoryAlloc(sizeof(struct variable));
nv->name = "";
nv->type = "";
nv->isConst = false;
nv->isArray = false;
nv->from = "";
nv->type =  v->type;
nv->name =  v->name;
char * r =  nv->type;
struct string tcc =  string(ogName);
if (tcc.count((struct string*)&tcc,"&")) {
r =  concatCPSTRING(r,"*");
}
long int nbUnaries =  tcc.count((struct string*)&tcc,"*");
if ((nbUnaries>0)) {
struct string ct =  string(r);
long int pointerLevel =  ct.count((struct string*)&ct,"*");
if ((pointerLevel<nbUnaries)) {

                        char* ____BAH_COMPILER_VAR_9; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("Cannot use '*' on ");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(" because it is not pointer.");
;                            
                            ____BAH_COMPILER_VAR_9 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                            
                            strncpy(____BAH_COMPILER_VAR_9+currStrOff, "Cannot use '*' on ", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_9+currStrOff, v->name, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_9+currStrOff, " because it is not pointer.", strLen_2);
                            currStrOff += strLen_2;
                            
                        }
                        throwErr(null,____BAH_COMPILER_VAR_9);
}
ct.trimRight((struct string*)&ct,nbUnaries);
r =  ct.str((struct string*)&ct);
}
nv->type =  r;
nv->name =  ogName;
return nv;
}
i =  i + 1;
};
i =  0;
while ((i<len(elems->fns))) {
struct func* fn =  elems->fns->data[i];
if ((strcmp(fn->name, name) == 0)) {
struct variable* nv = memoryAlloc(sizeof(struct variable));
nv->name = "";
nv->type = "";
nv->isConst = false;
nv->isArray = false;
nv->from = "";
nv->name =  name;
nv->type =  "function(";
long int j =  0;
while ((j<len(fn->args))) {
struct variable* arg =  fn->args->data[j];
nv->type =  concatCPSTRING(nv->type,arg->type);
j =  j + 1;
if ((j<len(fn->args))) {
nv->type =  concatCPSTRING(nv->type,",");
}
};

                        char* ____BAH_COMPILER_VAR_10; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen(nv->type);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen(fn->returns->type);
;                            
                            ____BAH_COMPILER_VAR_10 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                            
                            strncpy(____BAH_COMPILER_VAR_10+currStrOff, nv->type, strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_10+currStrOff, ")", strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_10+currStrOff, fn->returns->type, strLen_2);
                            currStrOff += strLen_2;
                            
                        }
                        nv->type =  ____BAH_COMPILER_VAR_10;
return nv;
}
i =  i + 1;
};
return null;
};
char * setCType(struct variable* v,struct Elems* elems){
struct string tp =  getCType(v->type,elems);
char * t =  tp.str((struct string*)&tp);

                        char* ____BAH_COMPILER_VAR_11; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen(t);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(v->name);
;                            
                            ____BAH_COMPILER_VAR_11 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                            
                            strncpy(____BAH_COMPILER_VAR_11+currStrOff, t, strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_11+currStrOff, " ", strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_11+currStrOff, v->name, strLen_2);
                            currStrOff += strLen_2;
                            
                        }
                        t =  ____BAH_COMPILER_VAR_11;
return t;
};
char * getTypeFromToken(struct Tok* t,int strict,struct Elems* elems){
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
struct func* nf = memoryAlloc(sizeof(struct func));
nf->name = "";
nf->args = memoryAlloc(sizeof(array(struct variable*)));
            nf->args->length = 0;
            nf->args->elemSize = sizeof(struct variable*);
            nf->isBinding = false;
nf->from = "";
nf->file = "";
nf->line = 1;
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
struct variable* arg = memoryAlloc(sizeof(struct variable));
arg->name = "";
arg->type = "";
arg->isConst = false;
arg->isArray = false;
arg->from = "";
arg->name =  concatCPSTRING("arg_",intToStr(len(nf->args)));
while ((j<cvt.length)) {
c =  cvt.charAt((struct string*)&cvt,j);
if (((c==44)||(c==41))) {
break;
}

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[len(memory)] =  c;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  c;
};
};
j =  j + 1;
};
arg->type =  arrToStr(memory);
clear(memory);

{
long nLength = len(nf->args);
if (nf->args->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(nf->args->data, (nLength+50)*sizeof(struct variable*));
nf->args->data = newPtr;
}
nf->args->data[len(nf->args)] =  arg;
nf->args->length = nLength+1;
} else {
nf->args->data[len(nf->args)] =  arg;
};
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
void * newPtr = GC_REALLOC(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[len(memory)] =  c;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  c;
};
};
j =  j + 1;
};
nf->returns = memoryAlloc(sizeof(struct variable));
nf->returns->name = "";
nf->returns->type = "";
nf->returns->isConst = false;
nf->returns->isArray = false;
nf->returns->from = "";
nf->returns->name =  "_return";
nf->returns->type =  arrToStr(memory);
return nf;
};
struct func* searchFunc(char * name,struct Elems* elems,int inclCurr){
char * ogName =  name;
if ((strcmp(name, "noCheck") == 0)) {
struct func* fn = memoryAlloc(sizeof(struct func));
fn->name = "";
fn->args = memoryAlloc(sizeof(array(struct variable*)));
            fn->args->length = 0;
            fn->args->elemSize = sizeof(struct variable*);
            fn->isBinding = false;
fn->from = "";
fn->file = "";
fn->line = 1;
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
struct structMemb* memb =  searchStructMemb(fnName.str((struct string*)&fnName),s,elems);
name =  fnName.content;

                        char* ____BAH_COMPILER_VAR_12; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen(memb->from);
long int strLen_1 = strlen("__");
long int strLen_2 = strlen(name);
;                            
                            ____BAH_COMPILER_VAR_12 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                            
                            strncpy(____BAH_COMPILER_VAR_12+currStrOff, memb->from, strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_12+currStrOff, "__", strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_12+currStrOff, name, strLen_2);
                            currStrOff += strLen_2;
                            
                        }
                        name =  ____BAH_COMPILER_VAR_12;
}
array(struct func*)* fns =  elems->fns;
long int i =  0;
while ((i<len(fns))) {
struct func* fn =  fns->data[i];
if ((fn==null)) {

                        char* ____BAH_COMPILER_VAR_13; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("\e[1;31m[INTERNAL COMPILER ERROR]\e[0m\n Please report the bug as 'compiler searching '");
long int strLen_1 = strlen(name);
long int strLen_2 = strlen("' resulting in null func'.");
;                            
                            ____BAH_COMPILER_VAR_13 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                            
                            strncpy(____BAH_COMPILER_VAR_13+currStrOff, "\e[1;31m[INTERNAL COMPILER ERROR]\e[0m\n Please report the bug as 'compiler searching '", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_13+currStrOff, name, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_13+currStrOff, "' resulting in null func'.", strLen_2);
                            currStrOff += strLen_2;
                            
                        }
                        panic(____BAH_COMPILER_VAR_13);
}
if ((strcmp(fn->name, name) == 0)) {
return fn;
}
i =  i + 1;
};
if ((inclCurr==true)) {
if ((strcmp(currentFn->name, name) == 0)) {
return currentFn;
}
}
struct variable* v =  searchVar(ogName,elems);
if ((v==null)) {
return null;
}
struct func* nf = memoryAlloc(sizeof(struct func));
nf->name = "";
nf->args = memoryAlloc(sizeof(array(struct variable*)));
            nf->args->length = 0;
            nf->args->elemSize = sizeof(struct variable*);
            nf->isBinding = false;
nf->from = "";
nf->file = "";
nf->line = 1;
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
struct structMemb* m =  members->data[i];
struct string cmpt =  string(m->type);
if ((strlen(m->def)>0)) {

                        char* ____BAH_COMPILER_VAR_14; 
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
                            ____BAH_COMPILER_VAR_14 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                            
                            strncpy(____BAH_COMPILER_VAR_14+currStrOff, code, strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_14+currStrOff, v->name, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_14+currStrOff, sep, strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_14+currStrOff, m->name, strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_14+currStrOff, " = ", strLen_4);
                            currStrOff += strLen_4;
                            
                            strncpy(____BAH_COMPILER_VAR_14+currStrOff, m->def, strLen_5);
                            currStrOff += strLen_5;
                            
                            strncpy(____BAH_COMPILER_VAR_14+currStrOff, ";\n", strLen_6);
                            currStrOff += strLen_6;
                            
                        }
                        code =  ____BAH_COMPILER_VAR_14;
}
if ((cmpt.hasPrefix((struct string*)&cmpt,"[]")==1)) {
cmpt.trimLeft((struct string*)&cmpt,2);
char * cmptstr =  cmpt.str((struct string*)&cmpt);
struct string elemCType =  getCType(cmptstr,elems);
char * elemCTypeStr =  elemCType.str((struct string*)&elemCType);

                        char* ____BAH_COMPILER_VAR_15; 
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
                            ____BAH_COMPILER_VAR_15 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14 + strLen_15 + strLen_16);
                            
                            strncpy(____BAH_COMPILER_VAR_15+currStrOff, code, strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_15+currStrOff, v->name, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_15+currStrOff, sep, strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_15+currStrOff, m->name, strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_15+currStrOff, " = memoryAlloc(sizeof(array(", strLen_4);
                            currStrOff += strLen_4;
                            
                            strncpy(____BAH_COMPILER_VAR_15+currStrOff, elemCTypeStr, strLen_5);
                            currStrOff += strLen_5;
                            
                            strncpy(____BAH_COMPILER_VAR_15+currStrOff, ")));\n            ", strLen_6);
                            currStrOff += strLen_6;
                            
                            strncpy(____BAH_COMPILER_VAR_15+currStrOff, v->name, strLen_7);
                            currStrOff += strLen_7;
                            
                            strncpy(____BAH_COMPILER_VAR_15+currStrOff, sep, strLen_8);
                            currStrOff += strLen_8;
                            
                            strncpy(____BAH_COMPILER_VAR_15+currStrOff, m->name, strLen_9);
                            currStrOff += strLen_9;
                            
                            strncpy(____BAH_COMPILER_VAR_15+currStrOff, "->length = 0;\n            ", strLen_10);
                            currStrOff += strLen_10;
                            
                            strncpy(____BAH_COMPILER_VAR_15+currStrOff, v->name, strLen_11);
                            currStrOff += strLen_11;
                            
                            strncpy(____BAH_COMPILER_VAR_15+currStrOff, sep, strLen_12);
                            currStrOff += strLen_12;
                            
                            strncpy(____BAH_COMPILER_VAR_15+currStrOff, m->name, strLen_13);
                            currStrOff += strLen_13;
                            
                            strncpy(____BAH_COMPILER_VAR_15+currStrOff, "->elemSize = sizeof(", strLen_14);
                            currStrOff += strLen_14;
                            
                            strncpy(____BAH_COMPILER_VAR_15+currStrOff, elemCTypeStr, strLen_15);
                            currStrOff += strLen_15;
                            
                            strncpy(____BAH_COMPILER_VAR_15+currStrOff, ");\n            ", strLen_16);
                            currStrOff += strLen_16;
                            
                        }
                        code =  ____BAH_COMPILER_VAR_15;
}
i =  i + 1;
};
if ((strlen(s->extendedFrom)>0)) {
struct cStruct* es =  searchStruct(s->extendedFrom,elems);
i =  0;
while ((i<len(es->methods))) {
struct func* m =  es->methods->data[i];

                        char* ____BAH_COMPILER_VAR_16; 
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
                            ____BAH_COMPILER_VAR_16 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                            
                            strncpy(____BAH_COMPILER_VAR_16+currStrOff, code, strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_16+currStrOff, v->name, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_16+currStrOff, sep, strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_16+currStrOff, m->name, strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_16+currStrOff, " = ", strLen_4);
                            currStrOff += strLen_4;
                            
                            strncpy(____BAH_COMPILER_VAR_16+currStrOff, es->name, strLen_5);
                            currStrOff += strLen_5;
                            
                            strncpy(____BAH_COMPILER_VAR_16+currStrOff, "__", strLen_6);
                            currStrOff += strLen_6;
                            
                            strncpy(____BAH_COMPILER_VAR_16+currStrOff, m->name, strLen_7);
                            currStrOff += strLen_7;
                            
                            strncpy(____BAH_COMPILER_VAR_16+currStrOff, ";\n", strLen_8);
                            currStrOff += strLen_8;
                            
                        }
                        code =  ____BAH_COMPILER_VAR_16;
i =  i + 1;
};
}
array(struct func*)* methods =  s->methods;
i =  0;
while ((i<len(methods))) {
struct func* m =  methods->data[i];

                        char* ____BAH_COMPILER_VAR_17; 
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
                            ____BAH_COMPILER_VAR_17 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                            
                            strncpy(____BAH_COMPILER_VAR_17+currStrOff, code, strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_17+currStrOff, v->name, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_17+currStrOff, sep, strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_17+currStrOff, m->name, strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_17+currStrOff, " = ", strLen_4);
                            currStrOff += strLen_4;
                            
                            strncpy(____BAH_COMPILER_VAR_17+currStrOff, s->name, strLen_5);
                            currStrOff += strLen_5;
                            
                            strncpy(____BAH_COMPILER_VAR_17+currStrOff, "__", strLen_6);
                            currStrOff += strLen_6;
                            
                            strncpy(____BAH_COMPILER_VAR_17+currStrOff, m->name, strLen_7);
                            currStrOff += strLen_7;
                            
                            strncpy(____BAH_COMPILER_VAR_17+currStrOff, ";\n", strLen_8);
                            currStrOff += strLen_8;
                            
                        }
                        code =  ____BAH_COMPILER_VAR_17;
i =  i + 1;
};
return code;
};
long int NB_COMP_VAR =  0;
char * genCompilerVar(){
char * name =  concatCPSTRING("____BAH_COMPILER_VAR_",intToStr(NB_COMP_VAR));
NB_COMP_VAR =  NB_COMP_VAR + 1;
return name;
};
void debugLine(__BAH_ARR_TYPE_Tok line){
char * cont =  "";
long int i =  0;
while ((i<len(line))) {
struct Tok t =  line->data[i];

                        char* ____BAH_COMPILER_VAR_18; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen(cont);
long int strLen_1 = strlen(" '");
long int strLen_2 = strlen(t.cont);
long int strLen_3 = strlen("'");
;                            
                            ____BAH_COMPILER_VAR_18 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                            
                            strncpy(____BAH_COMPILER_VAR_18+currStrOff, cont, strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_18+currStrOff, " '", strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_18+currStrOff, t.cont, strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_18+currStrOff, "'", strLen_3);
                            currStrOff += strLen_3;
                            
                        }
                        cont =  ____BAH_COMPILER_VAR_18;
i =  i + 1;
};
println(cont);
};
struct Elems* dupElems(struct Elems* elems){
struct Elems* nElems = memoryAlloc(sizeof(struct Elems));
nElems->vars = memoryAlloc(sizeof(array(struct variable*)));
            nElems->vars->length = 0;
            nElems->vars->elemSize = sizeof(struct variable*);
            nElems->structs = memoryAlloc(sizeof(array(struct cStruct*)));
            nElems->structs->length = 0;
            nElems->structs->elemSize = sizeof(struct cStruct*);
            nElems->types = memoryAlloc(sizeof(array(char *)));
            nElems->types->length = 0;
            nElems->types->elemSize = sizeof(char *);
            nElems->fns = memoryAlloc(sizeof(array(struct func*)));
            nElems->fns->length = 0;
            nElems->fns->elemSize = sizeof(struct func*);
            long int j =  0;
while ((j<len(elems->vars))) {
struct variable* v =  elems->vars->data[j];
struct variable* nv = memoryAlloc(sizeof(struct variable));
nv->name = "";
nv->type = "";
nv->isConst = false;
nv->isArray = false;
nv->from = "";
*nv =  *v;

{
long nLength = j;
if (nElems->vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(nElems->vars->data, (nLength+50)*sizeof(struct variable*));
nElems->vars->data = newPtr;
}
nElems->vars->data[j] =  nv;
nElems->vars->length = nLength+1;
} else {
nElems->vars->data[j] =  nv;
};
};
j =  j + 1;
};
j =  0;
while ((j<len(elems->structs))) {
struct cStruct* s =  elems->structs->data[j];
struct cStruct* ns = memoryAlloc(sizeof(struct cStruct));
ns->name = "";
ns->members = memoryAlloc(sizeof(array(struct structMemb*)));
            ns->members->length = 0;
            ns->members->elemSize = sizeof(struct structMemb*);
            ns->methods = memoryAlloc(sizeof(array(struct func*)));
            ns->methods->length = 0;
            ns->methods->elemSize = sizeof(struct func*);
            ns->postCode = "";
ns->extendedFrom = "";
*ns =  *s;

{
long nLength = j;
if (nElems->structs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(nElems->structs->data, (nLength+50)*sizeof(struct cStruct*));
nElems->structs->data = newPtr;
}
nElems->structs->data[j] =  ns;
nElems->structs->length = nLength+1;
} else {
nElems->structs->data[j] =  ns;
};
};
j =  j + 1;
};
j =  0;
while ((j<len(elems->types))) {
char * t =  elems->types->data[j];
char * nt =  t;

{
long nLength = j;
if (nElems->types->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(nElems->types->data, (nLength+50)*sizeof(char *));
nElems->types->data = newPtr;
}
nElems->types->data[j] =  nt;
nElems->types->length = nLength+1;
} else {
nElems->types->data[j] =  nt;
};
};
j =  j + 1;
};
j =  0;
while ((j<len(elems->fns))) {
struct func* f =  elems->fns->data[j];
struct func* nf = memoryAlloc(sizeof(struct func));
nf->name = "";
nf->args = memoryAlloc(sizeof(array(struct variable*)));
            nf->args->length = 0;
            nf->args->elemSize = sizeof(struct variable*);
            nf->isBinding = false;
nf->from = "";
nf->file = "";
nf->line = 1;
*nf =  *f;

{
long nLength = j;
if (nElems->fns->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(nElems->fns->data, (nLength+50)*sizeof(struct func*));
nElems->fns->data = newPtr;
}
nElems->fns->data[j] =  nf;
nElems->fns->length = nLength+1;
} else {
nElems->fns->data[j] =  nf;
};
};
j =  j + 1;
};
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
lineType prevLine =  (lineType)-1;
lineType getLineType(__BAH_ARR_TYPE_Tok line){
struct Tok ft =  line->data[0];
if ((ft.type==TOKEN_TYPE_FUNC)) {
return LINE_TYPE_FN_CALL;
}
if ((ft.type==TOKEN_TYPE_KEYWORD)) {
if ((strcmp(ft.cont, "#include") == 0)) {
return LINE_TYPE_INCLUDE;
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
else if ((strcmp(ft.cont, "continue") == 0)) {
return LINE_TYPE_FOR_OPERATOR;
}
else if ((strcmp(ft.cont, "break") == 0)) {
return LINE_TYPE_FOR_OPERATOR;
}
}
else if ((ft.type==TOKEN_TYPE_VAR)) {
if ((len(line)==1)) {
throwErr(&ft,"Cannot declare var {TOKEN} without a type.");
}
struct Tok st =  line->data[1];
if ((st.type==TOKEN_TYPE_ENCL)) {
if ((strcmp(st.cont, "(") == 0)) {
struct Tok lt =  line->data[len(line)-1];
if ((lt.type==TOKEN_TYPE_ENCL)) {
if ((strcmp(lt.cont, "}") == 0)) {
return LINE_TYPE_FN_DECL;
}
}
return LINE_TYPE_FN_CALL;
}
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
struct Tok t =  line->data[i];
if ((strcmp(t.cont, "<") == 0)) {
break;
}
i =  i + 1;
};
if ((i==len(line))) {
return line;
}
i =  0;
while ((i<len(line))) {
struct Tok t =  line->data[i];
if ((t.type==TOKEN_TYPE_SYNTAX)) {
if ((strcmp(t.cont, "<") == 0)) {
long int max =  i + 3;
if ((max<len(line))) {
struct Tok nt =  line->data[i + 1];
struct Tok nnt =  line->data[i + 2];
struct Tok nnnt =  line->data[i + 3];
if ((nt.type==TOKEN_TYPE_VAR)) {
if ((nnt.type==TOKEN_TYPE_SYNTAX)) {
if ((strcmp(nnt.cont, ">") == 0)) {
nnnt.bahType =  nt.cont;
struct string cCast =  getCType(nt.cont,elems);
char * cCastStr =  cCast.str((struct string*)&cCast);

                        char* ____BAH_COMPILER_VAR_19; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("(");
long int strLen_1 = strlen(cCastStr);
long int strLen_2 = strlen(")");
long int strLen_3 = strlen(nnnt.cont);
;                            
                            ____BAH_COMPILER_VAR_19 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                            
                            strncpy(____BAH_COMPILER_VAR_19+currStrOff, "(", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_19+currStrOff, cCastStr, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_19+currStrOff, ")", strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_19+currStrOff, nnnt.cont, strLen_3);
                            currStrOff += strLen_3;
                            
                        }
                        nnnt.cont =  ____BAH_COMPILER_VAR_19;

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  nnnt;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  nnnt;
};
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
void * newPtr = GC_REALLOC(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
};
};
i =  i + 1;
};
return nl;
};
void parseLines(__BAH_ARR_TYPE_Tok ts,struct Elems* elems);
int includeFile(char * ccstr,struct Elems* elems){
array(char *)* includes =  compilerState.includes;
long int i =  0;
while ((i<len(includes))) {
if ((strcmp(includes->data[i], ccstr) == 0)) {
return true;
}
i =  i + 1;
};
struct fileMap fm =  {};
fm.open = fileMap__open;
fm.isValid = fileMap__isValid;
fm.close = fileMap__close;
char * fileName =  concatCPSTRING(BAH_DIR,ccstr);
char * f =  fm.open((struct fileMap*)&fm,fileName);
if ((fm.isValid((struct fileMap*)&fm)==0)) {
fileName =  ccstr;
f =  fm.open((struct fileMap*)&fm,fileName);
if ((fm.isValid((struct fileMap*)&fm)==0)) {
return false;
}
}
char * oFile =  compilerState.currentFile;
compilerState.currentFile =  fileName;

{
long nLength = len(includes);
if (includes->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(includes->data, (nLength+50)*sizeof(char *));
includes->data = newPtr;
}
includes->data[len(includes)] =  ccstr;
includes->length = nLength+1;
} else {
includes->data[len(includes)] =  ccstr;
};
};
array(struct Tok)* tokens =  lexer(f);
fm.close((struct fileMap*)&fm);
if ((len(tokens)==0)) {

                        char* ____BAH_COMPILER_VAR_20; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("File '");
long int strLen_1 = strlen(ccstr);
long int strLen_2 = strlen("' not recognized.");
;                            
                            ____BAH_COMPILER_VAR_20 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                            
                            strncpy(____BAH_COMPILER_VAR_20+currStrOff, "File '", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_20+currStrOff, ccstr, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_20+currStrOff, "' not recognized.", strLen_2);
                            currStrOff += strLen_2;
                            
                        }
                        panic(____BAH_COMPILER_VAR_20);
}
parseLines(tokens,elems);
compilerState.currentFile =  oFile;
return true;
};
void parseInclude(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
if ((len(l)>2)) {
throwErr(&l->data[len(l)-1],"Invalid usage of include, ending by {TOKEN}.");
}
struct Tok strt =  l->data[1];
if ((strt.type!=TOKEN_TYPE_STR)) {
throwErr(&strt,"Cannot use {TOKEN} as string in include.");
}
struct string cc =  string(strt.cont);
cc.trimLeft((struct string*)&cc,1);
cc.trimRight((struct string*)&cc,1);
char * ccstr =  cc.str((struct string*)&cc);
if (cc.hasPrefix((struct string*)&cc,"<")) {

                        char* ____BAH_COMPILER_VAR_21; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("#include ");
long int strLen_1 = strlen(ccstr);
long int strLen_2 = strlen("\n");
;                            
                            ____BAH_COMPILER_VAR_21 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                            
                            strncpy(____BAH_COMPILER_VAR_21+currStrOff, "#include ", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_21+currStrOff, ccstr, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_21+currStrOff, "\n", strLen_2);
                            currStrOff += strLen_2;
                            
                        }
                        OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_21));
}
else {
if ((includeFile(ccstr,elems)==false)) {
throwErr(&strt,"Could not find file {TOKEN}.");
}
}
};
__BAH_ARR_TYPE_Tok parseOperations(__BAH_ARR_TYPE_Tok line,struct Elems* elems){
array(char *)* signs = memoryAlloc(sizeof(array(char *)));

signs->length = 7;
signs->elemSize = sizeof(char *);
signs->data = memoryAlloc(sizeof(char *) * 50);signs->data[0] = __STR("|");
signs->data[1] = __STR("&");
signs->data[2] = __STR("%");
signs->data[3] = __STR("+");
signs->data[4] = __STR("-");
signs->data[5] = __STR("*");
signs->data[6] = __STR("/");
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 1;
nl->elemSize = sizeof(struct Tok);
nl->data = memoryAlloc(sizeof(struct Tok) * 50);nl->data[0] = line->data[0];
long int i =  1;
while ((i<len(line))) {
struct Tok t =  line->data[i];
if ((t.type==TOKEN_TYPE_SYNTAX)) {
if (inArrayStr(t.cont,signs)) {
long int max =  i + 1;
if ((max>=len(line))) {
throwErr(&t,"Cannot use {TOKEN} on nothing.");
}
struct Tok pt =  nl->data[len(nl)-1];
struct Tok nt =  line->data[i + 1];
if ((strcmp(t.cont, "-") == 0)) {
if ((pt.isValue==false)) {
if ((nt.type==TOKEN_TYPE_INT)) {
if ((pt.isValue==false)) {
nt.cont =  concatCPSTRING(t.cont,nt.cont);

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  nt;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  nt;
};
};
i =  i + 2;
continue;
}
}
}
}
char * ptt =  getTypeFromToken(&pt,true,elems);
char * ntt =  getTypeFromToken(&nt,true,elems);
if ((compTypes(ptt,ntt)==false)) {

                        char* ____BAH_COMPILER_VAR_22; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(ntt);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(ptt);
long int strLen_4 = strlen(".");
;                            
                            ____BAH_COMPILER_VAR_22 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                            
                            strncpy(____BAH_COMPILER_VAR_22+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_22+currStrOff, ntt, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_22+currStrOff, ") as ", strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_22+currStrOff, ptt, strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_22+currStrOff, ".", strLen_4);
                            currStrOff += strLen_4;
                            
                        }
                        throwErr(&nt,____BAH_COMPILER_VAR_22);
}
t.isValue =  true;
if (compTypes(ptt,"cpstring")) {
if ((strcmp(t.cont, "+") != 0)) {
throwErr(&t,"Can only do concatenation (+) on cpstrings, not {TOKEN}.");
}
long int j =  i + 2;
int wasAdd =  false;
array(char *)* strConts = memoryAlloc(sizeof(array(char *)));

strConts->length = 2;
strConts->elemSize = sizeof(char *);
strConts->data = memoryAlloc(sizeof(char *) * 50);strConts->data[0] = __STR(pt.cont);
strConts->data[1] = __STR(nt.cont);
while ((j<len(line))) {
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

                        char* ____BAH_COMPILER_VAR_23; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(ntt);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(ptt);
long int strLen_4 = strlen(".");
;                            
                            ____BAH_COMPILER_VAR_23 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                            
                            strncpy(____BAH_COMPILER_VAR_23+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_23+currStrOff, ntt, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_23+currStrOff, ") as ", strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_23+currStrOff, ptt, strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_23+currStrOff, ".", strLen_4);
                            currStrOff += strLen_4;
                            
                        }
                        throwErr(&strAddTkT,____BAH_COMPILER_VAR_23);
break;
}

{
long nLength = len(strConts);
if (strConts->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(strConts->data, (nLength+50)*sizeof(char *));
strConts->data = newPtr;
}
strConts->data[len(strConts)] =  strAddTk.cont;
strConts->length = nLength+1;
} else {
strConts->data[len(strConts)] =  strAddTk.cont;
};
};
wasAdd =  false;
}
j =  j + 1;
};
if ((len(strConts)>2)) {
i =  j;
char * rstr =  genCompilerVar();
char * lens =  "";
char * totStrLen =  "1";
j =  0;
while ((j<len(strConts))) {
char * js =  intToStr(j);

                        char* ____BAH_COMPILER_VAR_24; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen(lens);
long int strLen_1 = strlen("long int strLen_");
long int strLen_2 = strlen(js);
long int strLen_3 = strlen(" = strlen(");
long int strLen_4 = strlen(strConts->data[j]);
long int strLen_5 = strlen(");\n");
;                            
                            ____BAH_COMPILER_VAR_24 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                            
                            strncpy(____BAH_COMPILER_VAR_24+currStrOff, lens, strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_24+currStrOff, "long int strLen_", strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_24+currStrOff, js, strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_24+currStrOff, " = strlen(", strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_24+currStrOff, strConts->data[j], strLen_4);
                            currStrOff += strLen_4;
                            
                            strncpy(____BAH_COMPILER_VAR_24+currStrOff, ");\n", strLen_5);
                            currStrOff += strLen_5;
                            
                        }
                        lens =  ____BAH_COMPILER_VAR_24;

                        char* ____BAH_COMPILER_VAR_25; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen(totStrLen);
long int strLen_1 = strlen(" + strLen_");
long int strLen_2 = strlen(js);
;                            
                            ____BAH_COMPILER_VAR_25 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                            
                            strncpy(____BAH_COMPILER_VAR_25+currStrOff, totStrLen, strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_25+currStrOff, " + strLen_", strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_25+currStrOff, js, strLen_2);
                            currStrOff += strLen_2;
                            
                        }
                        totStrLen =  ____BAH_COMPILER_VAR_25;
j =  j + 1;
};
struct rope* cats =  rope("");
j =  0;
while ((j<len(strConts))) {
char * js =  intToStr(j);

                        char* ____BAH_COMPILER_VAR_26; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("\n                            strncpy(");
long int strLen_1 = strlen(rstr);
long int strLen_2 = strlen("+currStrOff, ");
long int strLen_3 = strlen(strConts->data[j]);
long int strLen_4 = strlen(", strLen_");
long int strLen_5 = strlen(js);
long int strLen_6 = strlen(");\n                            currStrOff += strLen_");
long int strLen_7 = strlen(js);
long int strLen_8 = strlen(";\n                            ");
;                            
                            ____BAH_COMPILER_VAR_26 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                            
                            strncpy(____BAH_COMPILER_VAR_26+currStrOff, "\n                            strncpy(", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_26+currStrOff, rstr, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_26+currStrOff, "+currStrOff, ", strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_26+currStrOff, strConts->data[j], strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_26+currStrOff, ", strLen_", strLen_4);
                            currStrOff += strLen_4;
                            
                            strncpy(____BAH_COMPILER_VAR_26+currStrOff, js, strLen_5);
                            currStrOff += strLen_5;
                            
                            strncpy(____BAH_COMPILER_VAR_26+currStrOff, ");\n                            currStrOff += strLen_", strLen_6);
                            currStrOff += strLen_6;
                            
                            strncpy(____BAH_COMPILER_VAR_26+currStrOff, js, strLen_7);
                            currStrOff += strLen_7;
                            
                            strncpy(____BAH_COMPILER_VAR_26+currStrOff, ";\n                            ", strLen_8);
                            currStrOff += strLen_8;
                            
                        }
                        cats =  cats->add(cats, rope(____BAH_COMPILER_VAR_26));
j =  j + 1;
};

                        char* ____BAH_COMPILER_VAR_27; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("\n                        char* ");
long int strLen_1 = strlen(rstr);
long int strLen_2 = strlen("; \n                        {\n                            long int currStrOff = 0;\n                            ");
long int strLen_3 = strlen(lens);
long int strLen_4 = strlen(";                            \n                            ");
long int strLen_5 = strlen(rstr);
long int strLen_6 = strlen(" = memoryAlloc(");
long int strLen_7 = strlen(totStrLen);
long int strLen_8 = strlen(");\n                            ");
;                            
                            ____BAH_COMPILER_VAR_27 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                            
                            strncpy(____BAH_COMPILER_VAR_27+currStrOff, "\n                        char* ", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_27+currStrOff, rstr, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_27+currStrOff, "; \n                        {\n                            long int currStrOff = 0;\n                            ", strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_27+currStrOff, lens, strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_27+currStrOff, ";                            \n                            ", strLen_4);
                            currStrOff += strLen_4;
                            
                            strncpy(____BAH_COMPILER_VAR_27+currStrOff, rstr, strLen_5);
                            currStrOff += strLen_5;
                            
                            strncpy(____BAH_COMPILER_VAR_27+currStrOff, " = memoryAlloc(", strLen_6);
                            currStrOff += strLen_6;
                            
                            strncpy(____BAH_COMPILER_VAR_27+currStrOff, totStrLen, strLen_7);
                            currStrOff += strLen_7;
                            
                            strncpy(____BAH_COMPILER_VAR_27+currStrOff, ");\n                            ", strLen_8);
                            currStrOff += strLen_8;
                            
                        }
                        OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_27))->add(OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_27)), cats)->add(OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_27))->add(OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_27)), cats), rope("\n                        }\n                        "));
t.cont =  rstr;
t.type =  TOKEN_TYPE_VAR;
t.bahType =  ptt;
t.pos =  pt.pos;
t.ogCont =  pt.cont;

{
long nLength = len(nl)-1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)-1] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)-1] =  t;
};
};
continue;
}
else {

                        char* ____BAH_COMPILER_VAR_28; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("concatCPSTRING(");
long int strLen_1 = strlen(pt.cont);
long int strLen_2 = strlen(",");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen(")");
;                            
                            ____BAH_COMPILER_VAR_28 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                            
                            strncpy(____BAH_COMPILER_VAR_28+currStrOff, "concatCPSTRING(", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_28+currStrOff, pt.cont, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_28+currStrOff, ",", strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_28+currStrOff, nt.cont, strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_28+currStrOff, ")", strLen_4);
                            currStrOff += strLen_4;
                            
                        }
                        t.cont =  ____BAH_COMPILER_VAR_28;
}
}
else {
struct cStruct* s =  searchStruct(ptt,elems);
if ((s!=null)) {
struct structMemb* addMthd =  searchStructMemb("add",s,elems);
if ((((strcmp(t.cont, "+") == 0)&&(addMthd!=null))&&(addMthd->isFn==true))) {
char * sep =  ".";
char * amp =  "&";
if ((strCount(ptt,"*")>0)) {
sep =  "->";
amp =  "";
}

                        char* ____BAH_COMPILER_VAR_29; 
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
                            ____BAH_COMPILER_VAR_29 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7);
                            
                            strncpy(____BAH_COMPILER_VAR_29+currStrOff, pt.cont, strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_29+currStrOff, sep, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_29+currStrOff, "add(", strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_29+currStrOff, amp, strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_29+currStrOff, pt.cont, strLen_4);
                            currStrOff += strLen_4;
                            
                            strncpy(____BAH_COMPILER_VAR_29+currStrOff, ", ", strLen_5);
                            currStrOff += strLen_5;
                            
                            strncpy(____BAH_COMPILER_VAR_29+currStrOff, nt.cont, strLen_6);
                            currStrOff += strLen_6;
                            
                            strncpy(____BAH_COMPILER_VAR_29+currStrOff, ")", strLen_7);
                            currStrOff += strLen_7;
                            
                        }
                        t.cont =  ____BAH_COMPILER_VAR_29;
}
else {

                        char* ____BAH_COMPILER_VAR_30; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("Undefined operation on {TOKEN} (");
long int strLen_1 = strlen(ptt);
long int strLen_2 = strlen(").");
;                            
                            ____BAH_COMPILER_VAR_30 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                            
                            strncpy(____BAH_COMPILER_VAR_30+currStrOff, "Undefined operation on {TOKEN} (", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_30+currStrOff, ptt, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_30+currStrOff, ").", strLen_2);
                            currStrOff += strLen_2;
                            
                        }
                        throwErr(&pt,____BAH_COMPILER_VAR_30);
}
}
else {

                        char* ____BAH_COMPILER_VAR_31; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(t.cont);
long int strLen_3 = strlen(" ");
long int strLen_4 = strlen(nt.cont);
;                            
                            ____BAH_COMPILER_VAR_31 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                            
                            strncpy(____BAH_COMPILER_VAR_31+currStrOff, pt.cont, strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_31+currStrOff, " ", strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_31+currStrOff, t.cont, strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_31+currStrOff, " ", strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_31+currStrOff, nt.cont, strLen_4);
                            currStrOff += strLen_4;
                            
                        }
                        t.cont =  ____BAH_COMPILER_VAR_31;
}
}
t.type =  TOKEN_TYPE_VAR;
t.bahType =  ptt;
t.pos =  pt.pos;
t.ogCont =  pt.cont;

{
long nLength = len(nl)-1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)-1] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)-1] =  t;
};
};
i =  i + 2;
continue;
}
}
else if ((t.isValue==true)) {
if (strHasPrefix(t.cont,"-")) {
struct Tok pt =  nl->data[len(nl)-1];
if ((pt.isValue==true)) {
char * ptt =  getTypeFromToken(&pt,true,elems);
char * ntt =  getTypeFromToken(&t,true,elems);
if ((compTypes(ptt,ntt)==false)) {

                        char* ____BAH_COMPILER_VAR_32; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(ntt);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(ptt);
long int strLen_4 = strlen(".");
;                            
                            ____BAH_COMPILER_VAR_32 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                            
                            strncpy(____BAH_COMPILER_VAR_32+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_32+currStrOff, ntt, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_32+currStrOff, ") as ", strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_32+currStrOff, ptt, strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_32+currStrOff, ".", strLen_4);
                            currStrOff += strLen_4;
                            
                        }
                        throwErr(&t,____BAH_COMPILER_VAR_32);
}
t.type =  TOKEN_TYPE_VAR;
t.cont =  concatCPSTRING(pt.cont,t.cont);
t.bahType =  ptt;
t.pos =  pt.pos;

{
long nLength = len(nl)-1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)-1] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)-1] =  t;
};
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
void * newPtr = GC_REALLOC(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
};
};
i =  i + 1;
};
return nl;
};
__BAH_ARR_TYPE_Tok parseStructType(__BAH_ARR_TYPE_Tok line,struct Elems* elems){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
long int i =  0;
while ((i<len(line))) {
struct Tok t =  line->data[i];
if ((t.type==TOKEN_TYPE_VAR)) {
if (strHasPrefix(t.bahType,"[]")) {

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
};
};
i =  i + 1;
continue;
}
i =  i + 1;
if ((i<len(line))) {
struct Tok nt =  line->data[i];
if ((strcmp(nt.cont, "{") == 0)) {
i =  i + 1;
struct cStruct* s =  searchStruct(t.cont,elems);
if ((s==null)) {
throwErr(&t,"Unknown struct name {TOKEN}.");
}
char * memory =  "";
while ((i<len(line))) {
t =  line->data[i];
if ((strcmp(t.cont, "}") == 0)) {
break;
}

                        char* ____BAH_COMPILER_VAR_33; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen(memory);
long int strLen_1 = strlen(t.cont);
long int strLen_2 = strlen(" ");
;                            
                            ____BAH_COMPILER_VAR_33 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                            
                            strncpy(____BAH_COMPILER_VAR_33+currStrOff, memory, strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_33+currStrOff, t.cont, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_33+currStrOff, " ", strLen_2);
                            currStrOff += strLen_2;
                            
                        }
                        memory =  ____BAH_COMPILER_VAR_33;
i =  i + 1;
};
t.bahType =  s->name;

                        char* ____BAH_COMPILER_VAR_34; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("{");
long int strLen_1 = strlen(memory);
long int strLen_2 = strlen("}");
;                            
                            ____BAH_COMPILER_VAR_34 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                            
                            strncpy(____BAH_COMPILER_VAR_34+currStrOff, "{", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_34+currStrOff, memory, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_34+currStrOff, "}", strLen_2);
                            currStrOff += strLen_2;
                            
                        }
                        t.cont =  ____BAH_COMPILER_VAR_34;
t.isValue =  true;

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
};
};
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
void * newPtr = GC_REALLOC(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
};
};
i =  i + 1;
};
return nl;
};
__BAH_ARR_TYPE_Tok parseStructVars(__BAH_ARR_TYPE_Tok line,struct Elems* elems){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
long int i =  0;
while ((i<len(line))) {
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
struct Tok t =  line->data[i];
if ((t.type==TOKEN_TYPE_VAR)) {
i =  i + 1;
while ((i<len(line))) {
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
i =  i + 1;
struct Tok nt =  line->data[i];
if ((nt.type!=TOKEN_TYPE_VAR)) {
throwErr(&nt,"Cannot use {TOKEN} as struct member name.");
}
struct structMemb* memb =  searchStructMemb(nt.cont,s,elems);
if ((memb==null)) {
throwErr(&nt,"Unknown struct member {TOKEN}.");
}

                        char* ____BAH_COMPILER_VAR_35; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(sep);
long int strLen_2 = strlen(memb->name);
;                            
                            ____BAH_COMPILER_VAR_35 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                            
                            strncpy(____BAH_COMPILER_VAR_35+currStrOff, t.cont, strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_35+currStrOff, sep, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_35+currStrOff, memb->name, strLen_2);
                            currStrOff += strLen_2;
                            
                        }
                        t.cont =  ____BAH_COMPILER_VAR_35;
i =  i + 1;
};

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
};
};
continue;
}

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
};
};
i =  i + 1;
};
return nl;
};
__BAH_ARR_TYPE_Tok parseArrayType(__BAH_ARR_TYPE_Tok line,struct Elems* elems){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
long int i =  0;
while ((i<len(line))) {
struct Tok t =  line->data[i];
if ((strcmp(t.cont, "[") == 0)) {
break;
}
i =  i + 1;
};
if ((i==len(line))) {
return line;
}
i =  0;
while ((i<len(line))) {
struct Tok t =  line->data[i];
if ((strcmp(t.cont, "[") == 0)) {
i =  i + 1;
if ((i<len(line))) {
t =  line->data[i];
if ((strcmp(t.cont, "]") == 0)) {
i =  i + 1;
if ((i<len(line))) {
t =  line->data[i];
if ((t.type!=TOKEN_TYPE_VAR)) {
throwErr(&t,"Cannot use {TOKEN} as array type.");
}
char * arrElem =  t.cont;
t.bahType =  concatCPSTRING("[]",arrElem);
t.cont =  "";
t.isValue =  true;

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
};
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
void * newPtr = GC_REALLOC(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
};
};
i =  i + 1;
};
return nl;
};
__BAH_ARR_TYPE_Tok parseBool(__BAH_ARR_TYPE_Tok line,struct Elems* elems){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
array(char *)* comparators = memoryAlloc(sizeof(array(char *)));

comparators->length = 6;
comparators->elemSize = sizeof(char *);
comparators->data = memoryAlloc(sizeof(char *) * 50);comparators->data[0] = __STR("==");
comparators->data[1] = __STR("!=");
comparators->data[2] = __STR(">");
comparators->data[3] = __STR("<");
comparators->data[4] = __STR("<=");
comparators->data[5] = __STR(">=");
array(char *)* compSep = memoryAlloc(sizeof(array(char *)));

compSep->length = 2;
compSep->elemSize = sizeof(char *);
compSep->data = memoryAlloc(sizeof(char *) * 50);compSep->data[0] = __STR("||");
compSep->data[1] = __STR("&&");
long int i =  0;
while ((i<len(line))) {
struct Tok t =  line->data[i];
if ((inArrayStr(t.cont,comparators)||inArrayStr(t.cont,compSep))) {
break;
}
i =  i + 1;
};
if ((i==len(line))) {
return line;
}
i =  0;
while ((i<len(line))) {
struct Tok t =  line->data[i];
if (inArrayStr(t.cont,comparators)) {
if ((i==0)) {
throwErr(&t,"Cannot use {TOKEN} to compare with nothing.");
}
struct Tok pt =  nl->data[len(nl)-1];
long int max =  i + 1;
if ((max>=len(line))) {
throwErr(&t,"Cannot use {TOKEN} to compare with nothing.");
}
struct Tok nt =  line->data[i + 1];
char * ptt =  getTypeFromToken(&pt,true,elems);
char * ntt =  getTypeFromToken(&nt,true,elems);
if ((compTypes(ptt,ntt)==false)) {

                        char* ____BAH_COMPILER_VAR_36; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("Cannot compare {TOKEN} (");
long int strLen_1 = strlen(ntt);
long int strLen_2 = strlen(") to ");
long int strLen_3 = strlen(ptt);
long int strLen_4 = strlen(".");
;                            
                            ____BAH_COMPILER_VAR_36 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                            
                            strncpy(____BAH_COMPILER_VAR_36+currStrOff, "Cannot compare {TOKEN} (", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_36+currStrOff, ntt, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_36+currStrOff, ") to ", strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_36+currStrOff, ptt, strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_36+currStrOff, ".", strLen_4);
                            currStrOff += strLen_4;
                            
                        }
                        throwErr(&nt,____BAH_COMPILER_VAR_36);
}
if ((strcmp(ptt, "cpstring") == 0)) {
if ((strcmp(t.cont, "==") == 0)) {

                        char* ____BAH_COMPILER_VAR_37; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("(strcmp(");
long int strLen_1 = strlen(pt.cont);
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen(") == 0)");
;                            
                            ____BAH_COMPILER_VAR_37 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                            
                            strncpy(____BAH_COMPILER_VAR_37+currStrOff, "(strcmp(", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_37+currStrOff, pt.cont, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_37+currStrOff, ", ", strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_37+currStrOff, nt.cont, strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_37+currStrOff, ") == 0)", strLen_4);
                            currStrOff += strLen_4;
                            
                        }
                        pt.cont =  ____BAH_COMPILER_VAR_37;
}
else if ((strcmp(t.cont, "!=") == 0)) {

                        char* ____BAH_COMPILER_VAR_38; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("(strcmp(");
long int strLen_1 = strlen(pt.cont);
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen(") != 0)");
;                            
                            ____BAH_COMPILER_VAR_38 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                            
                            strncpy(____BAH_COMPILER_VAR_38+currStrOff, "(strcmp(", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_38+currStrOff, pt.cont, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_38+currStrOff, ", ", strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_38+currStrOff, nt.cont, strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_38+currStrOff, ") != 0)", strLen_4);
                            currStrOff += strLen_4;
                            
                        }
                        pt.cont =  ____BAH_COMPILER_VAR_38;
}
else if ((strcmp(t.cont, ">") == 0)) {

                        char* ____BAH_COMPILER_VAR_39; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("(strlen(");
long int strLen_1 = strlen(pt.cont);
long int strLen_2 = strlen(") > srtlen(");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen("))");
;                            
                            ____BAH_COMPILER_VAR_39 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                            
                            strncpy(____BAH_COMPILER_VAR_39+currStrOff, "(strlen(", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_39+currStrOff, pt.cont, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_39+currStrOff, ") > srtlen(", strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_39+currStrOff, nt.cont, strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_39+currStrOff, "))", strLen_4);
                            currStrOff += strLen_4;
                            
                        }
                        pt.cont =  ____BAH_COMPILER_VAR_39;
}
else if ((strcmp(t.cont, "<") == 0)) {

                        char* ____BAH_COMPILER_VAR_40; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("(strlen(");
long int strLen_1 = strlen(pt.cont);
long int strLen_2 = strlen(") < srtlen(");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen("))");
;                            
                            ____BAH_COMPILER_VAR_40 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                            
                            strncpy(____BAH_COMPILER_VAR_40+currStrOff, "(strlen(", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_40+currStrOff, pt.cont, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_40+currStrOff, ") < srtlen(", strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_40+currStrOff, nt.cont, strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_40+currStrOff, "))", strLen_4);
                            currStrOff += strLen_4;
                            
                        }
                        pt.cont =  ____BAH_COMPILER_VAR_40;
}
else if ((strcmp(t.cont, ">=") == 0)) {

                        char* ____BAH_COMPILER_VAR_41; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("(strlen(");
long int strLen_1 = strlen(pt.cont);
long int strLen_2 = strlen(") >= srtlen(");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen("))");
;                            
                            ____BAH_COMPILER_VAR_41 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                            
                            strncpy(____BAH_COMPILER_VAR_41+currStrOff, "(strlen(", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_41+currStrOff, pt.cont, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_41+currStrOff, ") >= srtlen(", strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_41+currStrOff, nt.cont, strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_41+currStrOff, "))", strLen_4);
                            currStrOff += strLen_4;
                            
                        }
                        pt.cont =  ____BAH_COMPILER_VAR_41;
}
else if ((strcmp(t.cont, "<=") == 0)) {

                        char* ____BAH_COMPILER_VAR_42; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("(strlen(");
long int strLen_1 = strlen(pt.cont);
long int strLen_2 = strlen(") <= srtlen(");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen("))");
;                            
                            ____BAH_COMPILER_VAR_42 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                            
                            strncpy(____BAH_COMPILER_VAR_42+currStrOff, "(strlen(", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_42+currStrOff, pt.cont, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_42+currStrOff, ") <= srtlen(", strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_42+currStrOff, nt.cont, strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_42+currStrOff, "))", strLen_4);
                            currStrOff += strLen_4;
                            
                        }
                        pt.cont =  ____BAH_COMPILER_VAR_42;
}
}
else {

                        char* ____BAH_COMPILER_VAR_43; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("(");
long int strLen_1 = strlen(pt.cont);
long int strLen_2 = strlen(t.cont);
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen(")");
;                            
                            ____BAH_COMPILER_VAR_43 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                            
                            strncpy(____BAH_COMPILER_VAR_43+currStrOff, "(", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_43+currStrOff, pt.cont, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_43+currStrOff, t.cont, strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_43+currStrOff, nt.cont, strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_43+currStrOff, ")", strLen_4);
                            currStrOff += strLen_4;
                            
                        }
                        pt.cont =  ____BAH_COMPILER_VAR_43;
}
pt.bahType =  "bool";

{
long nLength = len(nl)-1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)-1] =  pt;
nl->length = nLength+1;
} else {
nl->data[len(nl)-1] =  pt;
};
};
i =  i + 2;
continue;
}

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
};
};
i =  i + 1;
};
line =  nl;
nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
i =  0;
while ((i<len(line))) {
struct Tok t =  line->data[i];
if (inArrayStr(t.cont,compSep)) {
if ((i==0)) {
throwErr(&t,"Cannot use {TOKEN} to compare with nothing.");
}
struct Tok pt =  nl->data[len(nl)-1];
long int max =  i + 1;
if ((max>=len(line))) {
throwErr(&t,"Cannot use {TOKEN} to compare with nothing.");
}
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

                        char* ____BAH_COMPILER_VAR_44; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("(");
long int strLen_1 = strlen(pt.cont);
long int strLen_2 = strlen(t.cont);
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen(")");
;                            
                            ____BAH_COMPILER_VAR_44 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                            
                            strncpy(____BAH_COMPILER_VAR_44+currStrOff, "(", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_44+currStrOff, pt.cont, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_44+currStrOff, t.cont, strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_44+currStrOff, nt.cont, strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_44+currStrOff, ")", strLen_4);
                            currStrOff += strLen_4;
                            
                        }
                        pt.cont =  ____BAH_COMPILER_VAR_44;
pt.bahType =  "bool";

{
long nLength = len(nl)-1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)-1] =  pt;
nl->length = nLength+1;
} else {
nl->data[len(nl)-1] =  pt;
};
};
i =  i + 2;
continue;
}

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
};
};
i =  i + 1;
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
ptrOpers->data = memoryAlloc(sizeof(char *) * 50);ptrOpers->data[0] = __STR("&");
ptrOpers->data[1] = __STR("*");
long int i =  0;
while ((i<len(l))) {
struct Tok t =  l->data[i];
if ((t.type==TOKEN_TYPE_SYNTAX)) {
if ((strcmp(t.cont, "*") == 0)) {
if ((i>0)) {
struct Tok pt =  nl->data[len(nl)-1];
if ((pt.type==TOKEN_TYPE_VAR)) {
if ((i + 1<len(l))) {
struct Tok nt =  l->data[i + 1];
if ((nt.isValue==false)) {
pt.cont =  concatCPSTRING(pt.cont,t.cont);

{
long nLength = len(nl)-1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)-1] =  pt;
nl->length = nLength+1;
} else {
nl->data[len(nl)-1] =  pt;
};
};
i =  i + 1;
continue;
}
}
else {
pt.cont =  concatCPSTRING(pt.cont,t.cont);

{
long nLength = len(nl)-1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)-1] =  pt;
nl->length = nLength+1;
} else {
nl->data[len(nl)-1] =  pt;
};
};
i =  i + 1;
continue;
}
}
}
}
if (inArrayStr(t.cont,ptrOpers)) {
if ((i>0)) {
struct Tok pt =  nl->data[len(nl)-1];
if ((pt.isValue==true)) {

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
};
};
i =  i + 1;
continue;
}
}
i =  i + 1;
if ((i<len(l))) {
struct Tok nt =  l->data[i];
if ((nt.type==TOKEN_TYPE_VAR)) {
nt.cont =  concatCPSTRING(t.cont,nt.cont);

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  nt;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  nt;
};
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
void * newPtr = GC_REALLOC(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
};
};
i =  i + 1;
};
return nl;
};
__BAH_ARR_TYPE_Tok prePross(__BAH_ARR_TYPE_Tok line,struct Elems* elems);
__BAH_ARR_TYPE_Tok parseArrayVars(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
int found =  false;
long int i =  0;
while ((i<len(l))) {
struct Tok t =  l->data[i];
if ((t.type==TOKEN_TYPE_VAR)) {
i =  i + 1;
if ((i<len(l))) {
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
i =  0;
while ((i<len(l))) {
struct Tok t =  l->data[i];
if ((t.type==TOKEN_TYPE_VAR)) {
i =  i + 1;
if ((i<len(l))) {
struct Tok nt =  l->data[i];
if ((strcmp(nt.cont, "[") == 0)) {
struct variable* v =  searchVar(t.cont,elems);
if ((v==null)) {
throwErr(&t,"Unknown array-var {TOKEN}.");
}
if ((strHasPrefix(v->type,"[]")==false)) {

                        char* ____BAH_COMPILER_VAR_45; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("Cannot use ");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(" (");
long int strLen_3 = strlen(v->type);
long int strLen_4 = strlen(") as an array.");
;                            
                            ____BAH_COMPILER_VAR_45 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                            
                            strncpy(____BAH_COMPILER_VAR_45+currStrOff, "Cannot use ", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_45+currStrOff, v->name, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_45+currStrOff, " (", strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_45+currStrOff, v->type, strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_45+currStrOff, ") as an array.", strLen_4);
                            currStrOff += strLen_4;
                            
                        }
                        throwErr(&nt,____BAH_COMPILER_VAR_45);
}
strTrimLeft(&v->type,2);
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
i =  i + 1;
long int nbBracks =  1;
while ((i<len(l))) {
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
void * newPtr = GC_REALLOC(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] =  it;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  it;
};
};
i =  i + 1;
};
i =  i + 1;
if ((len(memory)==0)) {
throwErr(&l->data[i],"Expected index not {TOKEN}.");
}
memory =  prePross(memory,elems);
char * cont =  "";
long int j =  0;
while ((j<len(memory))) {
struct Tok mt =  memory->data[j];
cont =  concatCPSTRING(cont,mt.cont);
j =  j + 1;
};

                        char* ____BAH_COMPILER_VAR_46; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen("->data[");
long int strLen_2 = strlen(cont);
long int strLen_3 = strlen("]");
;                            
                            ____BAH_COMPILER_VAR_46 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                            
                            strncpy(____BAH_COMPILER_VAR_46+currStrOff, t.cont, strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_46+currStrOff, "->data[", strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_46+currStrOff, cont, strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_46+currStrOff, "]", strLen_3);
                            currStrOff += strLen_3;
                            
                        }
                        t.cont =  ____BAH_COMPILER_VAR_46;
t.bahType =  v->type;

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
};
};
continue;
}
}
i =  i - 1;
}

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
};
};
i =  i + 1;
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
char * code;
if ((ptrLevel==0)) {

                        char* ____BAH_COMPILER_VAR_47; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("__serialize(&");
long int strLen_1 = strlen(e.cont);
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen("sizeof(struct ");
long int strLen_4 = strlen(svt.str((struct string*)&svt));
long int strLen_5 = strlen(")");
;                            
                            ____BAH_COMPILER_VAR_47 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                            
                            strncpy(____BAH_COMPILER_VAR_47+currStrOff, "__serialize(&", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_47+currStrOff, e.cont, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_47+currStrOff, ", ", strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_47+currStrOff, "sizeof(struct ", strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_47+currStrOff, svt.str((struct string*)&svt), strLen_4);
                            currStrOff += strLen_4;
                            
                            strncpy(____BAH_COMPILER_VAR_47+currStrOff, ")", strLen_5);
                            currStrOff += strLen_5;
                            
                        }
                        code =  ____BAH_COMPILER_VAR_47;
}
else {
char * ptrRect =  "";
while ((ptrLevel>1)) {
ptrRect =  concatCPSTRING(ptrRect,"*");
ptrLevel =  ptrLevel - 1;
};

                        char* ____BAH_COMPILER_VAR_48; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("__serialize(");
long int strLen_1 = strlen(ptrRect);
long int strLen_2 = strlen(e.cont);
long int strLen_3 = strlen(", ");
long int strLen_4 = strlen("sizeof(struct ");
long int strLen_5 = strlen(svt.str((struct string*)&svt));
long int strLen_6 = strlen(")");
;                            
                            ____BAH_COMPILER_VAR_48 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                            
                            strncpy(____BAH_COMPILER_VAR_48+currStrOff, "__serialize(", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_48+currStrOff, ptrRect, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_48+currStrOff, e.cont, strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_48+currStrOff, ", ", strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_48+currStrOff, "sizeof(struct ", strLen_4);
                            currStrOff += strLen_4;
                            
                            strncpy(____BAH_COMPILER_VAR_48+currStrOff, svt.str((struct string*)&svt), strLen_5);
                            currStrOff += strLen_5;
                            
                            strncpy(____BAH_COMPILER_VAR_48+currStrOff, ")", strLen_6);
                            currStrOff += strLen_6;
                            
                        }
                        code =  ____BAH_COMPILER_VAR_48;
long int i =  0;
while ((i<len(s->members))) {
struct structMemb* m =  s->members->data[i];
if ((strcmp(m->type, "cpstring") == 0)) {

                        char* ____BAH_COMPILER_VAR_49; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen(code);
long int strLen_1 = strlen("+strlen(");
long int strLen_2 = strlen(e.cont);
long int strLen_3 = strlen("->");
long int strLen_4 = strlen(m->name);
long int strLen_5 = strlen(")");
;                            
                            ____BAH_COMPILER_VAR_49 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                            
                            strncpy(____BAH_COMPILER_VAR_49+currStrOff, code, strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_49+currStrOff, "+strlen(", strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_49+currStrOff, e.cont, strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_49+currStrOff, "->", strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_49+currStrOff, m->name, strLen_4);
                            currStrOff += strLen_4;
                            
                            strncpy(____BAH_COMPILER_VAR_49+currStrOff, ")", strLen_5);
                            currStrOff += strLen_5;
                            
                        }
                        code =  ____BAH_COMPILER_VAR_49;
}
i =  i + 1;
};
}
return concatCPSTRING(code,")");
};
struct Tok parseReflect(struct Tok t,char * tt,struct Elems* elems,int parsedPointer,char * ogName,char * offset){
char * isArr =  "0";
char * arrElem =  "0";
if (strHasPrefix(tt,"[]")) {
isArr =  "1";
struct string aet =  string(tt);
aet.trimLeft((struct string*)&aet,2);
struct Tok tmpT =  {};
tmpT.cont = "";
tmpT.ogCont = "";
tmpT.type = TOKEN_NO_TYPE;
tmpT.pos = 0;
tmpT.line = 1;
tmpT.bahType = "";
tmpT.isValue = false;
tmpT.isFunc = false;
tmpT.cont =  "0";
struct Tok rt =  parseReflect(tmpT,aet.str((struct string*)&aet),elems,true,"","0");
char * aev =  genCompilerVar();

                        char* ____BAH_COMPILER_VAR_50; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("\n        struct reflectElement ");
long int strLen_1 = strlen(aev);
long int strLen_2 = strlen(" = ");
long int strLen_3 = strlen(rt.cont);
long int strLen_4 = strlen(";\n        ");
;                            
                            ____BAH_COMPILER_VAR_50 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                            
                            strncpy(____BAH_COMPILER_VAR_50+currStrOff, "\n        struct reflectElement ", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_50+currStrOff, aev, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_50+currStrOff, " = ", strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_50+currStrOff, rt.cont, strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_50+currStrOff, ";\n        ", strLen_4);
                            currStrOff += strLen_4;
                            
                        }
                        OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_50));
arrElem =  concatCPSTRING("&",aev);
}
char * isStruct =  "0";
struct cStruct* ts =  searchStruct(tt,elems);
char * structLayout =  "0";
if ((ts!=null)) {
isStruct =  "1";
structLayout =  genCompilerVar();
struct rope* dataLayout =  rope("");
long int i =  0;
while ((i<len(ts->members))) {
struct structMemb* m =  ts->members->data[i];
struct Tok tmpT =  {};
tmpT.cont = "";
tmpT.ogCont = "";
tmpT.type = TOKEN_NO_TYPE;
tmpT.pos = 0;
tmpT.line = 1;
tmpT.bahType = "";
tmpT.isValue = false;
tmpT.isFunc = false;
char * sep =  "->";
if ((strCount(tt,"*")==0)) {
sep =  ".";
}
struct string mCtype =  getCType(m->type,elems);
struct string offsetTT =  string(tt);
offsetTT.replace((struct string*)&offsetTT,"*","");

                        char* ____BAH_COMPILER_VAR_51; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("(");
long int strLen_1 = strlen(mCtype.str((struct string*)&mCtype));
long int strLen_2 = strlen("*)((char*)(");
long int strLen_3 = strlen(t.cont);
long int strLen_4 = strlen(") + offsetof(struct ");
long int strLen_5 = strlen(offsetTT.str((struct string*)&offsetTT));
long int strLen_6 = strlen(", ");
long int strLen_7 = strlen(m->name);
long int strLen_8 = strlen("))");
;                            
                            ____BAH_COMPILER_VAR_51 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                            
                            strncpy(____BAH_COMPILER_VAR_51+currStrOff, "(", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_51+currStrOff, mCtype.str((struct string*)&mCtype), strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_51+currStrOff, "*)((char*)(", strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_51+currStrOff, t.cont, strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_51+currStrOff, ") + offsetof(struct ", strLen_4);
                            currStrOff += strLen_4;
                            
                            strncpy(____BAH_COMPILER_VAR_51+currStrOff, offsetTT.str((struct string*)&offsetTT), strLen_5);
                            currStrOff += strLen_5;
                            
                            strncpy(____BAH_COMPILER_VAR_51+currStrOff, ", ", strLen_6);
                            currStrOff += strLen_6;
                            
                            strncpy(____BAH_COMPILER_VAR_51+currStrOff, m->name, strLen_7);
                            currStrOff += strLen_7;
                            
                            strncpy(____BAH_COMPILER_VAR_51+currStrOff, "))", strLen_8);
                            currStrOff += strLen_8;
                            
                        }
                        tmpT.cont =  ____BAH_COMPILER_VAR_51;

                        char* ____BAH_COMPILER_VAR_52; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("offsetof(struct ");
long int strLen_1 = strlen(offsetTT.str((struct string*)&offsetTT));
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(m->name);
long int strLen_4 = strlen(")");
;                            
                            ____BAH_COMPILER_VAR_52 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                            
                            strncpy(____BAH_COMPILER_VAR_52+currStrOff, "offsetof(struct ", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_52+currStrOff, offsetTT.str((struct string*)&offsetTT), strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_52+currStrOff, ", ", strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_52+currStrOff, m->name, strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_52+currStrOff, ")", strLen_4);
                            currStrOff += strLen_4;
                            
                        }
                        struct Tok rt =  parseReflect(tmpT,m->type,elems,true,m->name,____BAH_COMPILER_VAR_52);

                        char* ____BAH_COMPILER_VAR_53; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen(structLayout);
long int strLen_1 = strlen("->data[");
long int strLen_2 = strlen(intToStr(i));
long int strLen_3 = strlen("] = ");
long int strLen_4 = strlen(rt.cont);
long int strLen_5 = strlen(";\n");
;                            
                            ____BAH_COMPILER_VAR_53 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                            
                            strncpy(____BAH_COMPILER_VAR_53+currStrOff, structLayout, strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_53+currStrOff, "->data[", strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_53+currStrOff, intToStr(i), strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_53+currStrOff, "] = ", strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_53+currStrOff, rt.cont, strLen_4);
                            currStrOff += strLen_4;
                            
                            strncpy(____BAH_COMPILER_VAR_53+currStrOff, ";\n", strLen_5);
                            currStrOff += strLen_5;
                            
                        }
                        dataLayout =  dataLayout->add(dataLayout, rope(____BAH_COMPILER_VAR_53));
i =  i + 1;
};

                        char* ____BAH_COMPILER_VAR_54; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("\n        array(struct reflectElement) * ");
long int strLen_1 = strlen(structLayout);
long int strLen_2 = strlen(" = memoryAlloc(sizeof(array(struct reflectElement)));\n        ");
long int strLen_3 = strlen(structLayout);
long int strLen_4 = strlen("->elemSize = sizeof(struct reflectElement);\n        ");
long int strLen_5 = strlen(structLayout);
long int strLen_6 = strlen("->length = ");
long int strLen_7 = strlen(intToStr(len(ts->members)));
long int strLen_8 = strlen(";\n        ");
long int strLen_9 = strlen(structLayout);
long int strLen_10 = strlen("->data = memoryAlloc(");
long int strLen_11 = strlen(structLayout);
long int strLen_12 = strlen("->length * ");
long int strLen_13 = strlen(structLayout);
long int strLen_14 = strlen("->elemSize);\n        ");
;                            
                            ____BAH_COMPILER_VAR_54 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14);
                            
                            strncpy(____BAH_COMPILER_VAR_54+currStrOff, "\n        array(struct reflectElement) * ", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_54+currStrOff, structLayout, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_54+currStrOff, " = memoryAlloc(sizeof(array(struct reflectElement)));\n        ", strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_54+currStrOff, structLayout, strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_54+currStrOff, "->elemSize = sizeof(struct reflectElement);\n        ", strLen_4);
                            currStrOff += strLen_4;
                            
                            strncpy(____BAH_COMPILER_VAR_54+currStrOff, structLayout, strLen_5);
                            currStrOff += strLen_5;
                            
                            strncpy(____BAH_COMPILER_VAR_54+currStrOff, "->length = ", strLen_6);
                            currStrOff += strLen_6;
                            
                            strncpy(____BAH_COMPILER_VAR_54+currStrOff, intToStr(len(ts->members)), strLen_7);
                            currStrOff += strLen_7;
                            
                            strncpy(____BAH_COMPILER_VAR_54+currStrOff, ";\n        ", strLen_8);
                            currStrOff += strLen_8;
                            
                            strncpy(____BAH_COMPILER_VAR_54+currStrOff, structLayout, strLen_9);
                            currStrOff += strLen_9;
                            
                            strncpy(____BAH_COMPILER_VAR_54+currStrOff, "->data = memoryAlloc(", strLen_10);
                            currStrOff += strLen_10;
                            
                            strncpy(____BAH_COMPILER_VAR_54+currStrOff, structLayout, strLen_11);
                            currStrOff += strLen_11;
                            
                            strncpy(____BAH_COMPILER_VAR_54+currStrOff, "->length * ", strLen_12);
                            currStrOff += strLen_12;
                            
                            strncpy(____BAH_COMPILER_VAR_54+currStrOff, structLayout, strLen_13);
                            currStrOff += strLen_13;
                            
                            strncpy(____BAH_COMPILER_VAR_54+currStrOff, "->elemSize);\n        ", strLen_14);
                            currStrOff += strLen_14;
                            
                        }
                        OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_54))->add(OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_54)), dataLayout);
}
char * amp =  "";
if (((((strCount(tt,"*")==0)&&(strcmp(tt, "cpstring") != 0))&&(strcmp(tt, "ptr") != 0))&&(parsedPointer==false))) {
amp =  "&";
}
struct string name =  string(ogName);
if ((hasStructSep(name)==true)) {
name =  splitStructSepAfter(name);
}
struct string cType =  getCType(tt,elems);

                        char* ____BAH_COMPILER_VAR_55; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("__reflect(");
long int strLen_1 = strlen(amp);
long int strLen_2 = strlen(t.cont);
long int strLen_3 = strlen(", sizeof(");
long int strLen_4 = strlen(cType.str((struct string*)&cType));
long int strLen_5 = strlen("), \"");
long int strLen_6 = strlen(tt);
long int strLen_7 = strlen("\", \"");
long int strLen_8 = strlen(name.str((struct string*)&name));
long int strLen_9 = strlen("\", ");
long int strLen_10 = strlen(isArr);
long int strLen_11 = strlen(", ");
long int strLen_12 = strlen(arrElem);
long int strLen_13 = strlen(", ");
long int strLen_14 = strlen(isStruct);
long int strLen_15 = strlen(", ");
long int strLen_16 = strlen(structLayout);
long int strLen_17 = strlen(", ");
long int strLen_18 = strlen(offset);
long int strLen_19 = strlen(")");
;                            
                            ____BAH_COMPILER_VAR_55 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14 + strLen_15 + strLen_16 + strLen_17 + strLen_18 + strLen_19);
                            
                            strncpy(____BAH_COMPILER_VAR_55+currStrOff, "__reflect(", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_55+currStrOff, amp, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_55+currStrOff, t.cont, strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_55+currStrOff, ", sizeof(", strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_55+currStrOff, cType.str((struct string*)&cType), strLen_4);
                            currStrOff += strLen_4;
                            
                            strncpy(____BAH_COMPILER_VAR_55+currStrOff, "), \"", strLen_5);
                            currStrOff += strLen_5;
                            
                            strncpy(____BAH_COMPILER_VAR_55+currStrOff, tt, strLen_6);
                            currStrOff += strLen_6;
                            
                            strncpy(____BAH_COMPILER_VAR_55+currStrOff, "\", \"", strLen_7);
                            currStrOff += strLen_7;
                            
                            strncpy(____BAH_COMPILER_VAR_55+currStrOff, name.str((struct string*)&name), strLen_8);
                            currStrOff += strLen_8;
                            
                            strncpy(____BAH_COMPILER_VAR_55+currStrOff, "\", ", strLen_9);
                            currStrOff += strLen_9;
                            
                            strncpy(____BAH_COMPILER_VAR_55+currStrOff, isArr, strLen_10);
                            currStrOff += strLen_10;
                            
                            strncpy(____BAH_COMPILER_VAR_55+currStrOff, ", ", strLen_11);
                            currStrOff += strLen_11;
                            
                            strncpy(____BAH_COMPILER_VAR_55+currStrOff, arrElem, strLen_12);
                            currStrOff += strLen_12;
                            
                            strncpy(____BAH_COMPILER_VAR_55+currStrOff, ", ", strLen_13);
                            currStrOff += strLen_13;
                            
                            strncpy(____BAH_COMPILER_VAR_55+currStrOff, isStruct, strLen_14);
                            currStrOff += strLen_14;
                            
                            strncpy(____BAH_COMPILER_VAR_55+currStrOff, ", ", strLen_15);
                            currStrOff += strLen_15;
                            
                            strncpy(____BAH_COMPILER_VAR_55+currStrOff, structLayout, strLen_16);
                            currStrOff += strLen_16;
                            
                            strncpy(____BAH_COMPILER_VAR_55+currStrOff, ", ", strLen_17);
                            currStrOff += strLen_17;
                            
                            strncpy(____BAH_COMPILER_VAR_55+currStrOff, offset, strLen_18);
                            currStrOff += strLen_18;
                            
                            strncpy(____BAH_COMPILER_VAR_55+currStrOff, ")", strLen_19);
                            currStrOff += strLen_19;
                            
                        }
                        t.cont =  ____BAH_COMPILER_VAR_55;
t.isFunc =  true;
return t;
};
__BAH_ARR_TYPE_Tok parseFnCall(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
int found =  false;
long int i =  0;
while ((i<len(l))) {
struct Tok t =  l->data[i];
if ((t.type==TOKEN_TYPE_VAR)) {
i =  i + 1;
if ((i<len(l))) {
t =  l->data[i];
if ((strcmp(t.cont, "(") == 0)) {
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
i =  0;
while ((i<len(l))) {
struct Tok ot =  l->data[i];
if ((ot.type==TOKEN_TYPE_VAR)) {
i =  i + 1;
if ((i<len(l))) {
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
struct variable* arg1;
if (hasStructSep(fnStr)) {
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

                        char* ____BAH_COMPILER_VAR_56; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("(");
long int strLen_1 = strlen(fnarg1t.str((struct string*)&fnarg1t));
long int strLen_2 = strlen(")");
;                            
                            ____BAH_COMPILER_VAR_56 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                            
                            strncpy(____BAH_COMPILER_VAR_56+currStrOff, "(", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_56+currStrOff, fnarg1t.str((struct string*)&fnarg1t), strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_56+currStrOff, ")", strLen_2);
                            currStrOff += strLen_2;
                            
                        }
                        varName.prepend((struct string*)&varName,____BAH_COMPILER_VAR_56);
}
ot.cont =  concatCPSTRING(fnName,"(");
array(struct variable*)* fnArgs =  fn->args;
long int paramIndex =  0;
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
if ((varName.length>0)) {
struct Tok tk =  {};
tk.cont = "";
tk.ogCont = "";
tk.type = TOKEN_NO_TYPE;
tk.pos = 0;
tk.line = 1;
tk.bahType = "";
tk.isValue = false;
tk.isFunc = false;
tk.cont =  varName.str((struct string*)&varName);
tk.bahType =  arg1->type;
tk.type =  TOKEN_TYPE_VAR;
tk.isValue =  true;

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] =  tk;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  tk;
};
};
nt =  l->data[i];
if ((strcmp(nt.cont, ")") != 0)) {
{};
tk.cont = "";
tk.ogCont = "";
tk.type = TOKEN_NO_TYPE;
tk.pos = 0;
tk.line = 1;
tk.bahType = "";
tk.isValue = false;
tk.isFunc = false;
tk.cont =  ",";
tk.type =  TOKEN_TYPE_SYNTAX;
tk.isValue =  false;

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] =  tk;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  tk;
};
};
}
}
while ((i<len(l))) {
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
void * newPtr = GC_REALLOC(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] =  t;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  t;
};
};
if ((nbPar==0)) {
i =  i + 1;
break;
}
i =  i + 1;
};
if ((strcmp(fnName, "noCheck") == 0)) {
long int j =  0;
while ((j<len(memory))) {
struct Tok t =  memory->data[j];

                        char* ____BAH_COMPILER_VAR_57; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen(ot.cont);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(t.cont);
;                            
                            ____BAH_COMPILER_VAR_57 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                            
                            strncpy(____BAH_COMPILER_VAR_57+currStrOff, ot.cont, strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_57+currStrOff, " ", strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_57+currStrOff, t.cont, strLen_2);
                            currStrOff += strLen_2;
                            
                        }
                        ot.cont =  ____BAH_COMPILER_VAR_57;
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
void * newPtr = GC_REALLOC(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  ot;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  ot;
};
};
continue;
}
memory =  prePross(memory,elems);
struct Tok ft =  memory->data[0];
if ((strcmp(ft.cont, ")") != 0)) {
long int j =  0;
while ((j<len(memory))) {
struct Tok t =  memory->data[j];
if ((paramIndex>=len(fnArgs))) {
throwErr(&t,"Too many arguments in function call.");
}
struct variable* arg =  fnArgs->data[paramIndex];
char * tt =  getTypeFromToken(&t,true,elems);
if (((strcmp(arg->type, "reflectElement") == 0)&&(strcmp(tt, "reflectElement") != 0))) {
t =  parseReflect(t,tt,elems,false,t.cont,"0");
tt =  "reflectElement";
}
if ((compTypes(tt,arg->type)==false)) {

                        char* ____BAH_COMPILER_VAR_58; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(tt);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(arg->type);
long int strLen_4 = strlen(" in function call.");
;                            
                            ____BAH_COMPILER_VAR_58 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                            
                            strncpy(____BAH_COMPILER_VAR_58+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_58+currStrOff, tt, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_58+currStrOff, ") as ", strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_58+currStrOff, arg->type, strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_58+currStrOff, " in function call.", strLen_4);
                            currStrOff += strLen_4;
                            
                        }
                        throwErr(&t,____BAH_COMPILER_VAR_58);
}
ot.cont =  concatCPSTRING(ot.cont,t.cont);
j =  j + 1;
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
ot.cont =  concatCPSTRING(ot.cont,",");
}
j =  j + 1;
};
}
if ((paramIndex<len(fnArgs))) {
ot.cont =  fnName;
throwErr(&ot,"Not enough arguments in function call, ending by {TOKEN}.");
}
if ((strcmp(fn->name, "ser") == 0)) {
ot.cont =  parseSerialize(memory->data[0],elems);
}
else {
ot.cont =  concatCPSTRING(ot.cont,")");
}
ot.type =  TOKEN_TYPE_FUNC;
ot.bahType =  fn->returns->type;
ot.isFunc =  true;

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  ot;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  ot;
};
};
continue;
}
}
i =  i - 1;
}

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  ot;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  ot;
};
};
i =  i + 1;
};
return nl;
};
void parseVar(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
struct Tok ft =  l->data[0];
if ((ft.isFunc==true)) {
if ((len(l)>1)) {
throwErr(&l->data[len(l)-1],"Not expecting {TOKEN} after function call.");
}
ft =  l->data[0];
int parsed =  true;
OUTPUT =  OUTPUT->add(OUTPUT, rope(concatCPSTRING(ft.cont,";\n")));
return ;
}
l =  parseStructType(l,elems);
int isEqual =  false;
int isStruct =  false;
char * currentType =  "";
ft =  l->data[0];
struct variable* v =  searchVar(ft.cont,elems);
int exists =  true;
char * ogName;
if ((v==null)) {
exists =  false;
v = memoryAlloc(sizeof(struct variable));
v->name = "";
v->type = "";
v->isConst = false;
v->isArray = false;
v->from = "";
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
long int arrayLength =  0;
long int i =  1;
while ((i<len(l))) {
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

                        char* ____BAH_COMPILER_VAR_59; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen(currentType);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(t.cont);
;                            
                            ____BAH_COMPILER_VAR_59 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                            
                            strncpy(____BAH_COMPILER_VAR_59+currStrOff, currentType, strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_59+currStrOff, " ", strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_59+currStrOff, t.cont, strLen_2);
                            currStrOff += strLen_2;
                            
                        }
                        currentType =  ____BAH_COMPILER_VAR_59;
}
else {
if ((strcmp(t.cont, "new") == 0)) {
isStruct =  true;
long int max =  i + 1;
if ((max>=len(l))) {
throwErr(&t,"Cannot initiate {TOKEN} struct without specifying struct name.");
}
max =  max + 1;
if ((max<len(l))) {
t =  l->data[i + 2];
throwErr(&t,"{TOKEN} not expected after initiating new struct.");
}
t =  l->data[i + 1];
if ((t.type!=TOKEN_TYPE_VAR)) {
throwErr(&t,"Cannot use {TOKEN} as a struct name.");
}
struct cStruct* s =  searchStruct(t.cont,elems);
if ((s==null)) {
throwErr(&t,"Unknown struct {TOKEN}.");
}
struct string vect =  getCType(s->name,elems);
char * vectStr =  vect.content;

                        char* ____BAH_COMPILER_VAR_60; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("memoryAlloc(sizeof(");
long int strLen_1 = strlen(vectStr);
long int strLen_2 = strlen("))");
;                            
                            ____BAH_COMPILER_VAR_60 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                            
                            strncpy(____BAH_COMPILER_VAR_60+currStrOff, "memoryAlloc(sizeof(", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_60+currStrOff, vectStr, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_60+currStrOff, "))", strLen_2);
                            currStrOff += strLen_2;
                            
                        }
                        code =  ____BAH_COMPILER_VAR_60;
v->type =  concatCPSTRING(s->name,"*");
NEXT_LINE =  declareStructMethods(v,s,elems);
break;
}
if ((t.isValue==false)) {
throwErr(&t,"Cannot use {TOKEN} as value in var declaration.");
}
char * tp =  getTypeFromToken(&t,true,elems);
if ((exists==true)) {
if ((compTypes(tp,v->type)==false)) {

                        char* ____BAH_COMPILER_VAR_61; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(tp);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(v->type);
long int strLen_4 = strlen(".");
;                            
                            ____BAH_COMPILER_VAR_61 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                            
                            strncpy(____BAH_COMPILER_VAR_61+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_61+currStrOff, tp, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_61+currStrOff, ") as ", strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_61+currStrOff, v->type, strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_61+currStrOff, ".", strLen_4);
                            currStrOff += strLen_4;
                            
                        }
                        throwErr(&t,____BAH_COMPILER_VAR_61);
}
}
else {
if ((strlen(currentType)==0)) {
if ((strlen(v->type)==0)) {
v->type =  tp;
}
else {
if ((compTypes(tp,v->type)==false)) {

                        char* ____BAH_COMPILER_VAR_62; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(tp);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(v->type);
long int strLen_4 = strlen(".");
;                            
                            ____BAH_COMPILER_VAR_62 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                            
                            strncpy(____BAH_COMPILER_VAR_62+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_62+currStrOff, tp, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_62+currStrOff, ") as ", strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_62+currStrOff, v->type, strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_62+currStrOff, ".", strLen_4);
                            currStrOff += strLen_4;
                            
                        }
                        throwErr(&t,____BAH_COMPILER_VAR_62);
}
}
}
}
if (((strlen(t.cont)>0)&&(strHasPrefix(t.cont,"{")==false))) {

                        char* ____BAH_COMPILER_VAR_63; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(t.cont);
;                            
                            ____BAH_COMPILER_VAR_63 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                            
                            strncpy(____BAH_COMPILER_VAR_63+currStrOff, code, strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_63+currStrOff, " ", strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_63+currStrOff, t.cont, strLen_2);
                            currStrOff += strLen_2;
                            
                        }
                        code =  ____BAH_COMPILER_VAR_63;
break;
}
if (strHasPrefix(v->type,"[]")) {
struct string arrType =  getCType(v->type,elems);
arrType.trimRight((struct string*)&arrType,1);

                        char* ____BAH_COMPILER_VAR_64; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("memoryAlloc(sizeof(");
long int strLen_1 = strlen(arrType.str((struct string*)&arrType));
long int strLen_2 = strlen("))");
;                            
                            ____BAH_COMPILER_VAR_64 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                            
                            strncpy(____BAH_COMPILER_VAR_64+currStrOff, "memoryAlloc(sizeof(", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_64+currStrOff, arrType.str((struct string*)&arrType), strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_64+currStrOff, "))", strLen_2);
                            currStrOff += strLen_2;
                            
                        }
                        code =  ____BAH_COMPILER_VAR_64;
arrType.trimLeft((struct string*)&arrType,6);
arrType.trimRight((struct string*)&arrType,1);
char * elemTypeStr =  arrType.str((struct string*)&arrType);
long int max =  i + 1;
if ((max!=len(l))) {
i =  i + 1;
struct Tok nt =  l->data[i];
if ((strcmp(nt.cont, "{") != 0)) {
throwErr(&l->data[i + 1],"{TOKEN} not expected after array initialization.");
}
struct string elemBahType =  string(v->type);
elemBahType.trimLeft((struct string*)&elemBahType,2);
char * elemBahTypeStr =  elemBahType.str((struct string*)&elemBahType);
i =  i + 1;
while ((i<len(l))) {
t =  l->data[i];
char * tt =  getTypeFromToken(&t,true,elems);
if ((compTypes(tt,elemBahTypeStr)==false)) {

                        char* ____BAH_COMPILER_VAR_65; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(tt);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(elemBahTypeStr);
;                            
                            ____BAH_COMPILER_VAR_65 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                            
                            strncpy(____BAH_COMPILER_VAR_65+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_65+currStrOff, tt, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_65+currStrOff, ") as ", strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_65+currStrOff, elemBahTypeStr, strLen_3);
                            currStrOff += strLen_3;
                            
                        }
                        throwErr(&t,____BAH_COMPILER_VAR_65);
}
char * strArrayLength =  intToStr(arrayLength);
arrayLength =  arrayLength + 1;
if ((strcmp(tt, "cpstring") == 0)) {

                        char* ____BAH_COMPILER_VAR_66; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("__STR(");
long int strLen_1 = strlen(t.cont);
long int strLen_2 = strlen(")");
;                            
                            ____BAH_COMPILER_VAR_66 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                            
                            strncpy(____BAH_COMPILER_VAR_66+currStrOff, "__STR(", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_66+currStrOff, t.cont, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_66+currStrOff, ")", strLen_2);
                            currStrOff += strLen_2;
                            
                        }
                        t.cont =  ____BAH_COMPILER_VAR_66;
}

                        char* ____BAH_COMPILER_VAR_67; 
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
                            ____BAH_COMPILER_VAR_67 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                            
                            strncpy(____BAH_COMPILER_VAR_67+currStrOff, NEXT_LINE, strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_67+currStrOff, v->name, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_67+currStrOff, "->data[", strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_67+currStrOff, strArrayLength, strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_67+currStrOff, "] = ", strLen_4);
                            currStrOff += strLen_4;
                            
                            strncpy(____BAH_COMPILER_VAR_67+currStrOff, t.cont, strLen_5);
                            currStrOff += strLen_5;
                            
                            strncpy(____BAH_COMPILER_VAR_67+currStrOff, ";\n", strLen_6);
                            currStrOff += strLen_6;
                            
                        }
                        NEXT_LINE =  ____BAH_COMPILER_VAR_67;
i =  i + 1;
t =  l->data[i];
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

                        char* ____BAH_COMPILER_VAR_68; 
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
                            ____BAH_COMPILER_VAR_68 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                            
                            strncpy(____BAH_COMPILER_VAR_68+currStrOff, v->name, strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_68+currStrOff, "->data = memoryAlloc(sizeof(", strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_68+currStrOff, elemTypeStr, strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_68+currStrOff, ") * ", strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_68+currStrOff, allocLengthStr, strLen_4);
                            currStrOff += strLen_4;
                            
                            strncpy(____BAH_COMPILER_VAR_68+currStrOff, ");", strLen_5);
                            currStrOff += strLen_5;
                            
                            strncpy(____BAH_COMPILER_VAR_68+currStrOff, NEXT_LINE, strLen_6);
                            currStrOff += strLen_6;
                            
                        }
                        NEXT_LINE =  ____BAH_COMPILER_VAR_68;
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

                        char* ____BAH_COMPILER_VAR_69; 
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
                            ____BAH_COMPILER_VAR_69 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9);
                            
                            strncpy(____BAH_COMPILER_VAR_69+currStrOff, "\n", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_69+currStrOff, v->name, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_69+currStrOff, "->length = ", strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_69+currStrOff, strArrayLength, strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_69+currStrOff, ";\n", strLen_4);
                            currStrOff += strLen_4;
                            
                            strncpy(____BAH_COMPILER_VAR_69+currStrOff, v->name, strLen_5);
                            currStrOff += strLen_5;
                            
                            strncpy(____BAH_COMPILER_VAR_69+currStrOff, "->elemSize = sizeof(", strLen_6);
                            currStrOff += strLen_6;
                            
                            strncpy(____BAH_COMPILER_VAR_69+currStrOff, elemTypeStr, strLen_7);
                            currStrOff += strLen_7;
                            
                            strncpy(____BAH_COMPILER_VAR_69+currStrOff, ");\n", strLen_8);
                            currStrOff += strLen_8;
                            
                            strncpy(____BAH_COMPILER_VAR_69+currStrOff, NEXT_LINE, strLen_9);
                            currStrOff += strLen_9;
                            
                        }
                        NEXT_LINE =  ____BAH_COMPILER_VAR_69;
break;
}
isStruct =  true;
long int max =  i + 1;
if ((max!=len(l))) {
throwErr(&l->data[i + 1],"{TOKEN} not expected after struct initialization.");
}
struct cStruct* s =  searchStruct(v->type,elems);
NEXT_LINE =  declareStructMethods(v,s,elems);

                        char* ____BAH_COMPILER_VAR_70; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(t.cont);
;                            
                            ____BAH_COMPILER_VAR_70 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                            
                            strncpy(____BAH_COMPILER_VAR_70+currStrOff, code, strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_70+currStrOff, " ", strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_70+currStrOff, t.cont, strLen_2);
                            currStrOff += strLen_2;
                            
                        }
                        code =  ____BAH_COMPILER_VAR_70;
}
i =  i + 1;
};
if ((exists==true)) {
if ((strlen(code)==0)) {
throwErr(&ft,"Cannot re-declare {TOKEN}.");
}
if ((strlen(currentType)>0)) {
struct Tok st =  l->data[1];

                        char* ____BAH_COMPILER_VAR_71; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("Cannot change the type of already declared var '");
long int strLen_1 = strlen(ft.cont);
long int strLen_2 = strlen("' to {TOKEN}.");
;                            
                            ____BAH_COMPILER_VAR_71 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                            
                            strncpy(____BAH_COMPILER_VAR_71+currStrOff, "Cannot change the type of already declared var '", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_71+currStrOff, ft.cont, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_71+currStrOff, "' to {TOKEN}.", strLen_2);
                            currStrOff += strLen_2;
                            
                        }
                        throwErr(&st,____BAH_COMPILER_VAR_71);
}
if ((isStruct==false)) {

                        char* ____BAH_COMPILER_VAR_72; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen(" = ");
long int strLen_2 = strlen(code);
;                            
                            ____BAH_COMPILER_VAR_72 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                            
                            strncpy(____BAH_COMPILER_VAR_72+currStrOff, v->name, strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_72+currStrOff, " = ", strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_72+currStrOff, code, strLen_2);
                            currStrOff += strLen_2;
                            
                        }
                        code =  ____BAH_COMPILER_VAR_72;
}
else {
strTrim(&code);
if ((strHasPrefix(code,"{")==false)) {

                        char* ____BAH_COMPILER_VAR_73; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen(" = ");
long int strLen_2 = strlen(code);
;                            
                            ____BAH_COMPILER_VAR_73 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                            
                            strncpy(____BAH_COMPILER_VAR_73+currStrOff, v->name, strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_73+currStrOff, " = ", strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_73+currStrOff, code, strLen_2);
                            currStrOff += strLen_2;
                            
                        }
                        code =  ____BAH_COMPILER_VAR_73;
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

                        char* ____BAH_COMPILER_VAR_74; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("\n{\nlong nLength = ");
long int strLen_1 = strlen(nLengthStr);
long int strLen_2 = strlen(";\nif (");
long int strLen_3 = strlen(nstr);
long int strLen_4 = strlen("->length < nLength+1) {\nif ((nLength+1) % 50 == 0 || nLength == 0) {\nvoid * newPtr = GC_REALLOC(");
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
long int strLen_16 = strlen(";\n};\n}");
;                            
                            ____BAH_COMPILER_VAR_74 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14 + strLen_15 + strLen_16);
                            
                            strncpy(____BAH_COMPILER_VAR_74+currStrOff, "\n{\nlong nLength = ", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_74+currStrOff, nLengthStr, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_74+currStrOff, ";\nif (", strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_74+currStrOff, nstr, strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_74+currStrOff, "->length < nLength+1) {\nif ((nLength+1) % 50 == 0 || nLength == 0) {\nvoid * newPtr = GC_REALLOC(", strLen_4);
                            currStrOff += strLen_4;
                            
                            strncpy(____BAH_COMPILER_VAR_74+currStrOff, nstr, strLen_5);
                            currStrOff += strLen_5;
                            
                            strncpy(____BAH_COMPILER_VAR_74+currStrOff, "->data, (nLength+50)*sizeof(", strLen_6);
                            currStrOff += strLen_6;
                            
                            strncpy(____BAH_COMPILER_VAR_74+currStrOff, elemTypeStr, strLen_7);
                            currStrOff += strLen_7;
                            
                            strncpy(____BAH_COMPILER_VAR_74+currStrOff, "));\n", strLen_8);
                            currStrOff += strLen_8;
                            
                            strncpy(____BAH_COMPILER_VAR_74+currStrOff, nstr, strLen_9);
                            currStrOff += strLen_9;
                            
                            strncpy(____BAH_COMPILER_VAR_74+currStrOff, "->data = newPtr;\n}\n", strLen_10);
                            currStrOff += strLen_10;
                            
                            strncpy(____BAH_COMPILER_VAR_74+currStrOff, code, strLen_11);
                            currStrOff += strLen_11;
                            
                            strncpy(____BAH_COMPILER_VAR_74+currStrOff, ";\n", strLen_12);
                            currStrOff += strLen_12;
                            
                            strncpy(____BAH_COMPILER_VAR_74+currStrOff, nstr, strLen_13);
                            currStrOff += strLen_13;
                            
                            strncpy(____BAH_COMPILER_VAR_74+currStrOff, "->length = nLength+1;\n} else {\n", strLen_14);
                            currStrOff += strLen_14;
                            
                            strncpy(____BAH_COMPILER_VAR_74+currStrOff, code, strLen_15);
                            currStrOff += strLen_15;
                            
                            strncpy(____BAH_COMPILER_VAR_74+currStrOff, ";\n};\n}", strLen_16);
                            currStrOff += strLen_16;
                            
                        }
                        code =  ____BAH_COMPILER_VAR_74;
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
char * vct;
if (vts.hasPrefix((struct string*)&vts,"function(")) {
struct func* tmpfn =  parseFnType(vts);
struct string tmpfnRetCType =  getCType(tmpfn->returns->type,elems);
char * tmpfnArgsCType =  "";
long int j =  0;
while ((j<len(tmpfn->args))) {
struct variable* arg =  tmpfn->args->data[j];
struct string ct =  getCType(arg->type,elems);
tmpfnArgsCType =  concatCPSTRING(tmpfnArgsCType,ct.str((struct string*)&ct));
j =  j + 1;
if ((j<len(tmpfn->args))) {
tmpfnArgsCType =  concatCPSTRING(tmpfnArgsCType,",");
}
};

                        char* ____BAH_COMPILER_VAR_75; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen(tmpfnRetCType.str((struct string*)&tmpfnRetCType));
long int strLen_1 = strlen(" (*");
long int strLen_2 = strlen(v->name);
long int strLen_3 = strlen(")(");
long int strLen_4 = strlen(tmpfnArgsCType);
long int strLen_5 = strlen(")");
;                            
                            ____BAH_COMPILER_VAR_75 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                            
                            strncpy(____BAH_COMPILER_VAR_75+currStrOff, tmpfnRetCType.str((struct string*)&tmpfnRetCType), strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_75+currStrOff, " (*", strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_75+currStrOff, v->name, strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_75+currStrOff, ")(", strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_75+currStrOff, tmpfnArgsCType, strLen_4);
                            currStrOff += strLen_4;
                            
                            strncpy(____BAH_COMPILER_VAR_75+currStrOff, ")", strLen_5);
                            currStrOff += strLen_5;
                            
                        }
                        vct =  ____BAH_COMPILER_VAR_75;
}
else {
vct =  setCType(v,elems);
}
if ((strlen(code)>0)) {

                        char* ____BAH_COMPILER_VAR_76; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen(vct);
long int strLen_1 = strlen(" = ");
long int strLen_2 = strlen(code);
;                            
                            ____BAH_COMPILER_VAR_76 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                            
                            strncpy(____BAH_COMPILER_VAR_76+currStrOff, vct, strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_76+currStrOff, " = ", strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_76+currStrOff, code, strLen_2);
                            currStrOff += strLen_2;
                            
                        }
                        code =  ____BAH_COMPILER_VAR_76;
}
else {
code =  vct;
}
array(struct variable*)* vars =  elems->vars;

{
long nLength = len(vars);
if (vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(vars->data, (nLength+50)*sizeof(struct variable*));
vars->data = newPtr;
}
vars->data[len(vars)] =  v;
vars->length = nLength+1;
} else {
vars->data[len(vars)] =  v;
};
};
}
OUTPUT =  OUTPUT->add(OUTPUT, rope(concatCPSTRING(code,";\n")));
};
char * getCfunctionType(struct string cfrt,char * elemName,struct Elems* elems){
struct func* tmpfn =  parseFnType(cfrt);
struct string tmpfnRetCType =  getCType(tmpfn->returns->type,elems);
char * tmpfnArgsCType =  "";
long int j =  0;
while ((j<len(tmpfn->args))) {
struct variable* arg =  tmpfn->args->data[j];
struct string ct =  getCType(arg->type,elems);
tmpfnArgsCType =  concatCPSTRING(tmpfnArgsCType,ct.str((struct string*)&ct));
j =  j + 1;
if ((j<len(tmpfn->args))) {
tmpfnArgsCType =  concatCPSTRING(tmpfnArgsCType,",");
}
};

                        char* ____BAH_COMPILER_VAR_77; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen(tmpfnRetCType.str((struct string*)&tmpfnRetCType));
long int strLen_1 = strlen(" (*");
long int strLen_2 = strlen(elemName);
long int strLen_3 = strlen(")(");
long int strLen_4 = strlen(tmpfnArgsCType);
long int strLen_5 = strlen(")");
;                            
                            ____BAH_COMPILER_VAR_77 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                            
                            strncpy(____BAH_COMPILER_VAR_77+currStrOff, tmpfnRetCType.str((struct string*)&tmpfnRetCType), strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_77+currStrOff, " (*", strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_77+currStrOff, elemName, strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_77+currStrOff, ")(", strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_77+currStrOff, tmpfnArgsCType, strLen_4);
                            currStrOff += strLen_4;
                            
                            strncpy(____BAH_COMPILER_VAR_77+currStrOff, ")", strLen_5);
                            currStrOff += strLen_5;
                            
                        }
                        return ____BAH_COMPILER_VAR_77;
};
char * parseFnHeader(char * prev,__BAH_ARR_TYPE_Tok l,long int* i,struct func* fn,struct Elems* elems){
long int j =  *i;
struct Tok ft =  l->data[j];
char * tpdf =  "";
if ((ft.type!=TOKEN_TYPE_VAR)) {
throwErr(&ft,"Cannot use {TOKEN} as function name.");
}
fn->name =  concatCPSTRING(prev,ft.cont);
array(struct variable*)* arguments = memoryAlloc(sizeof(array(struct variable*)));

arguments->length = 0;
arguments->elemSize = sizeof(struct variable*);
char * code =  concatCPSTRING(fn->name,"(");
j =  j + 2;
struct Tok t =  l->data[j];
if ((strcmp(t.cont, ")") != 0)) {
while ((j<len(l))) {
t =  l->data[j];
if ((t.type!=TOKEN_TYPE_VAR)) {
throwErr(&t,"Cannot use {TOKEN} as argument name.");
}
char * argName =  t.cont;
j =  j + 1;
if ((j>=len(l))) {
throwErr(&t,"Cannot declare argument {TOKEN} without a type.");
}
t =  l->data[j];
char * argType =  t.cont;
j =  j + 1;
int isComa =  false;
long int nbPars =  1;
while ((j<len(l))) {
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
argType =  concatCPSTRING(argType,t.cont);
}
}
else {
isComa =  true;
break;
}
j =  j + 1;
};
struct variable* argument = memoryAlloc(sizeof(struct variable));
argument->name = "";
argument->type = "";
argument->isConst = false;
argument->isArray = false;
argument->from = "";
argument->name =  argName;
argument->type =  argType;

{
long nLength = len(arguments);
if (arguments->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(arguments->data, (nLength+50)*sizeof(struct variable*));
arguments->data = newPtr;
}
arguments->data[len(arguments)] =  argument;
arguments->length = nLength+1;
} else {
arguments->data[len(arguments)] =  argument;
};
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
newArgType =  concatCPSTRING("__BAH_ARR_TYPE_",cfrt.str((struct string*)&cfrt));
array(char *)* csatd =  compilerState.arrTypesDecl;
if ((inArrayStr(newArgType,csatd)==false)) {

{
long nLength = len(csatd);
if (csatd->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(csatd->data, (nLength+50)*sizeof(char *));
csatd->data = newPtr;
}
csatd->data[len(csatd)] =  newArgType;
csatd->length = nLength+1;
} else {
csatd->data[len(csatd)] =  newArgType;
};
};

                        char* ____BAH_COMPILER_VAR_78; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen(tpdf);
long int strLen_1 = strlen("typedef ");
long int strLen_2 = strlen(argCType.str((struct string*)&argCType));
long int strLen_3 = strlen(" ");
long int strLen_4 = strlen(newArgType);
long int strLen_5 = strlen(";\n");
;                            
                            ____BAH_COMPILER_VAR_78 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                            
                            strncpy(____BAH_COMPILER_VAR_78+currStrOff, tpdf, strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_78+currStrOff, "typedef ", strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_78+currStrOff, argCType.str((struct string*)&argCType), strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_78+currStrOff, " ", strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_78+currStrOff, newArgType, strLen_4);
                            currStrOff += strLen_4;
                            
                            strncpy(____BAH_COMPILER_VAR_78+currStrOff, ";\n", strLen_5);
                            currStrOff += strLen_5;
                            
                        }
                        tpdf =  ____BAH_COMPILER_VAR_78;
}
}
if ((cfrt.hasPrefix((struct string*)&cfrt,"function(")==1)) {
code =  concatCPSTRING(code,getCfunctionType(cfrt,argName,elems));
}
else {

                        char* ____BAH_COMPILER_VAR_79; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(newArgType);
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(argName);
;                            
                            ____BAH_COMPILER_VAR_79 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                            
                            strncpy(____BAH_COMPILER_VAR_79+currStrOff, code, strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_79+currStrOff, newArgType, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_79+currStrOff, " ", strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_79+currStrOff, argName, strLen_3);
                            currStrOff += strLen_3;
                            
                        }
                        code =  ____BAH_COMPILER_VAR_79;
}
if ((isComa==true)) {
code =  concatCPSTRING(code,",");
}
else {
code =  concatCPSTRING(code,")");
break;
}
j =  j + 1;
};
}
else {
code =  concatCPSTRING(code,")");
}
j =  j + 1;
struct variable* returns = memoryAlloc(sizeof(struct variable));
returns->name = "";
returns->type = "";
returns->isConst = false;
returns->isArray = false;
returns->from = "";
returns->type =  "";
while ((j<len(l))) {
t =  l->data[j];
if ((strcmp(t.cont, "{") == 0)) {
break;
}
returns->type =  concatCPSTRING(returns->type,t.cont);
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
newFnRetType =  concatCPSTRING("__BAH_ARR_TYPE_",cfrt.str((struct string*)&cfrt));
array(char *)* csatd =  compilerState.arrTypesDecl;
if ((inArrayStr(newFnRetType,csatd)==false)) {

{
long nLength = len(csatd);
if (csatd->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(csatd->data, (nLength+50)*sizeof(char *));
csatd->data = newPtr;
}
csatd->data[len(csatd)] =  newFnRetType;
csatd->length = nLength+1;
} else {
csatd->data[len(csatd)] =  newFnRetType;
};
};

                        char* ____BAH_COMPILER_VAR_80; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen(tpdf);
long int strLen_1 = strlen("typedef ");
long int strLen_2 = strlen(fnRetType.str((struct string*)&fnRetType));
long int strLen_3 = strlen(" ");
long int strLen_4 = strlen(newFnRetType);
long int strLen_5 = strlen(";\n");
;                            
                            ____BAH_COMPILER_VAR_80 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                            
                            strncpy(____BAH_COMPILER_VAR_80+currStrOff, tpdf, strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_80+currStrOff, "typedef ", strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_80+currStrOff, fnRetType.str((struct string*)&fnRetType), strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_80+currStrOff, " ", strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_80+currStrOff, newFnRetType, strLen_4);
                            currStrOff += strLen_4;
                            
                            strncpy(____BAH_COMPILER_VAR_80+currStrOff, ";\n", strLen_5);
                            currStrOff += strLen_5;
                            
                        }
                        tpdf =  ____BAH_COMPILER_VAR_80;
}
}

                        char* ____BAH_COMPILER_VAR_81; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen(tpdf);
long int strLen_1 = strlen(newFnRetType);
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(code);
;                            
                            ____BAH_COMPILER_VAR_81 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                            
                            strncpy(____BAH_COMPILER_VAR_81+currStrOff, tpdf, strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_81+currStrOff, newFnRetType, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_81+currStrOff, " ", strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_81+currStrOff, code, strLen_3);
                            currStrOff += strLen_3;
                            
                        }
                        code =  ____BAH_COMPILER_VAR_81;
return code;
};
void parseStruct(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
struct cStruct* s = memoryAlloc(sizeof(struct cStruct));
s->name = "";
s->members = memoryAlloc(sizeof(array(struct structMemb*)));
            s->members->length = 0;
            s->members->elemSize = sizeof(struct structMemb*);
            s->methods = memoryAlloc(sizeof(array(struct func*)));
            s->methods->length = 0;
            s->methods->elemSize = sizeof(struct func*);
            s->postCode = "";
s->extendedFrom = "";
array(struct cStruct*)* structs =  elems->structs;

{
long nLength = len(structs);
if (structs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(structs->data, (nLength+50)*sizeof(struct cStruct*));
structs->data = newPtr;
}
structs->data[len(structs)] =  s;
structs->length = nLength+1;
} else {
structs->data[len(structs)] =  s;
};
};
array(struct func*)* methds =  s->methods;
if ((len(l)<4)) {
throwErr(&l->data[len(l)-1],"Cannot declare struct has such, please do 'struct <name> { <memberName>:<memberType> }'.");
}
struct Tok nameToken =  l->data[1];
long int i =  2;
int doesOutput =  true;
if ((strcmp(nameToken.cont, "!") == 0)) {
nameToken =  l->data[2];
i =  3;
doesOutput =  false;
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
struct Tok st =  l->data[i];
if ((st.type==TOKEN_TYPE_KEYWORD)) {
if ((strcmp(st.cont, "extend") == 0)) {
i =  i + 1;
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
struct structMemb* em =  extdsmbs->data[j];
struct string cemt =  string(em->type);
char * membDeclStr;
if ((cemt.hasPrefix((struct string*)&cemt,"function(")==1)) {
struct func* tmpfn =  parseFnType(cemt);
struct string tmpfnRetCType =  getCType(tmpfn->returns->type,elems);
char * tmpfnArgsCType =  "";
j =  0;
while ((j<len(tmpfn->args))) {
struct variable* arg =  tmpfn->args->data[j];
struct string ct =  getCType(arg->type,elems);
tmpfnArgsCType =  concatCPSTRING(tmpfnArgsCType,ct.str((struct string*)&ct));
j =  j + 1;
if ((j<len(tmpfn->args))) {
tmpfnArgsCType =  concatCPSTRING(tmpfnArgsCType,",");
}
};

                        char* ____BAH_COMPILER_VAR_82; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen(tmpfnRetCType.str((struct string*)&tmpfnRetCType));
long int strLen_1 = strlen(" (*");
long int strLen_2 = strlen(em->name);
long int strLen_3 = strlen(")(");
long int strLen_4 = strlen(tmpfnArgsCType);
long int strLen_5 = strlen(")");
;                            
                            ____BAH_COMPILER_VAR_82 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                            
                            strncpy(____BAH_COMPILER_VAR_82+currStrOff, tmpfnRetCType.str((struct string*)&tmpfnRetCType), strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_82+currStrOff, " (*", strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_82+currStrOff, em->name, strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_82+currStrOff, ")(", strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_82+currStrOff, tmpfnArgsCType, strLen_4);
                            currStrOff += strLen_4;
                            
                            strncpy(____BAH_COMPILER_VAR_82+currStrOff, ")", strLen_5);
                            currStrOff += strLen_5;
                            
                        }
                        membDeclStr =  ____BAH_COMPILER_VAR_82;
}
else {
struct string membDecl =  getCType(em->type,elems);
membDecl.append((struct string*)&membDecl," ");
membDecl.append((struct string*)&membDecl,em->name);
membDeclStr =  membDecl.content;
}

{
long nLength = len(allMembs);
if (allMembs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(allMembs->data, (nLength+50)*sizeof(char *));
allMembs->data = newPtr;
}
allMembs->data[len(allMembs)] =  membDeclStr;
allMembs->length = nLength+1;
} else {
allMembs->data[len(allMembs)] =  membDeclStr;
};
};

{
long nLength = len(members);
if (members->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(members->data, (nLength+50)*sizeof(struct structMemb*));
members->data = newPtr;
}
members->data[len(members)] =  em;
members->length = nLength+1;
} else {
members->data[len(members)] =  em;
};
};
j =  j + 1;
};
long int k =  0;
while ((k<len(extdS->methods))) {
struct func* emt =  extdS->methods->data[k];
struct string mthdDecl =  getCType(emt->returns->type,elems);

                        char* ____BAH_COMPILER_VAR_83; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("(*");
long int strLen_1 = strlen(emt->name);
long int strLen_2 = strlen(")(");
;                            
                            ____BAH_COMPILER_VAR_83 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                            
                            strncpy(____BAH_COMPILER_VAR_83+currStrOff, "(*", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_83+currStrOff, emt->name, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_83+currStrOff, ")(", strLen_2);
                            currStrOff += strLen_2;
                            
                        }
                        mthdDecl.append((struct string*)&mthdDecl,____BAH_COMPILER_VAR_83);
j =  0;
while ((j<len(emt->args))) {
struct variable* a =  emt->args->data[j];
struct string tp =  getCType(a->type,elems);
tp.append((struct string*)&tp,concatCPSTRING(" ",a->name));
long int max =  len(emt->args) - 1;
if ((j!=max)) {
tp.append((struct string*)&tp,",");
}
mthdDecl.append((struct string*)&mthdDecl,tp.str((struct string*)&tp));
j =  j + 1;
};
mthdDecl.append((struct string*)&mthdDecl,")");

{
long nLength = len(allMembs);
if (allMembs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(allMembs->data, (nLength+50)*sizeof(char *));
allMembs->data = newPtr;
}
allMembs->data[len(allMembs)] =  mthdDecl.str((struct string*)&mthdDecl);
allMembs->length = nLength+1;
} else {
allMembs->data[len(allMembs)] =  mthdDecl.str((struct string*)&mthdDecl);
};
};
k =  k + 1;
};
}
else {
throwErr(&st,"Cannot use keyword {TOKEN} in struct declaration.");
}
}
struct Tok braceTk =  l->data[i];
i =  i + 1;
if ((strcmp(braceTk.cont, "{") != 0)) {
throwErr(&braceTk,"Cannot use {TOKEN} in struct declaration.");
}
struct rope* OOUT =  OUTPUT;
char * nextLine =  "";
while ((i<len(l))) {
struct Tok t =  l->data[i];
long int max =  i + 2;
if ((max>=len(l))) {
if (((t.type==TOKEN_TYPE_ENCL)&&(strcmp(t.cont, "}") == 0))) {
break;
}
throwErr(&l->data[len(l)-1],"Not enough argument in member declaration, ending by {TOKEN}.");
}
struct structMemb* memb = memoryAlloc(sizeof(struct structMemb));
memb->name = "";
memb->type = "";
memb->isConst = false;
memb->isArray = false;
memb->from = "";
memb->def = "";
memb->isFn = false;
if ((t.type!=TOKEN_TYPE_VAR)) {
throwErr(&t,"Cannot use {TOKEN} as member name.");
}
memb->name =  t.cont;
long int ii =  0;
while ((ii<len(members))) {
struct structMemb* m =  members->data[ii];
if ((strcmp(m->name, memb->name) == 0)) {
throwErr(&t,"Member {TOKEN} has already been declared.");
}
ii =  ii + 1;
};
i =  i + 1;
t =  l->data[i];
if ((strcmp(t.cont, ":") != 0)) {
if ((strcmp(t.cont, "(") != 0)) {
throwErr(&t,"Member name should be followed by ':' not {TOKEN}.");
}
else {
char * fnPrefix =  concatCPSTRING(s->name,"__");
struct func* fn = memoryAlloc(sizeof(struct func));
fn->name = "";
fn->args = memoryAlloc(sizeof(array(struct variable*)));
            fn->args->length = 0;
            fn->args->elemSize = sizeof(struct variable*);
            fn->isBinding = false;
fn->from = "";
fn->file = "";
fn->line = 1;
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
long int j =  i-1;
while ((j<len(l))) {
t =  l->data[j];
if ((strcmp(t.cont, "{") == 0)) {
break;
}

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
};
};
if ((j==i)) {
t.type =  TOKEN_TYPE_VAR;
t.cont =  "this";
t.isValue =  true;

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
};
};
t.type =  TOKEN_TYPE_VAR;
t.cont =  concatCPSTRING(s->name,"*");
t.isValue =  true;

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
};
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
void * newPtr = GC_REALLOC(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
};
};
}
}
j =  j + 1;
};
i =  i - 1;
long int nli =  0;
struct rope* code =  rope(parseFnHeader(fnPrefix,nl,&nli,fn,elems));
i =  i + nli;
i =  i - 2;
struct variable* returns =  fn->returns;
array(struct variable*)* arguments =  fn->args;
fn->from =  s->name;
code =  code->add(code, rope("{\n"));
struct Elems* fnElems =  dupElems(elems);
j =  0;
while ((j<len(arguments))) {

{
long nLength = len(fnElems->vars);
if (fnElems->vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(fnElems->vars->data, (nLength+50)*sizeof(struct variable*));
fnElems->vars->data = newPtr;
}
fnElems->vars->data[len(fnElems->vars)] =  arguments->data[j];
fnElems->vars->length = nLength+1;
} else {
fnElems->vars->data[len(fnElems->vars)] =  arguments->data[j];
};
};
j =  j + 1;
};
array(struct func*)* fns =  elems->fns;

{
long nLength = len(fns);
if (fns->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(fns->data, (nLength+50)*sizeof(struct func*));
fns->data = newPtr;
}
fns->data[len(fns)] =  fn;
fns->length = nLength+1;
} else {
fns->data[len(fns)] =  fn;
};
};
array(struct Tok)* tokens = memoryAlloc(sizeof(array(struct Tok)));

tokens->length = 0;
tokens->elemSize = sizeof(struct Tok);
long int nbBraces =  1;
t =  l->data[i];
if ((strcmp(t.cont, "{") == 0)) {
i =  i + 1;
}
while ((i<len(l))) {
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
void * newPtr = GC_REALLOC(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] =  t;
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] =  t;
};
};
i =  i + 1;
};
struct func* mfn = memoryAlloc(sizeof(struct func));
mfn->name = "";
mfn->args = memoryAlloc(sizeof(array(struct variable*)));
            mfn->args->length = 0;
            mfn->args->elemSize = sizeof(struct variable*);
            mfn->isBinding = false;
mfn->from = "";
mfn->file = "";
mfn->line = 1;
mfn->args =  fn->args;
mfn->name =  fn->name;
mfn->returns =  fn->returns;
mfn->from =  s->name;
strTrimLeft(&mfn->name,strlen(fnPrefix));

{
long nLength = len(methds);
if (methds->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(methds->data, (nLength+50)*sizeof(struct func*));
methds->data = newPtr;
}
methds->data[len(methds)] =  mfn;
methds->length = nLength+1;
} else {
methds->data[len(methds)] =  mfn;
};
};
if ((len(tokens)==0)) {
code =  code->add(code, rope("};\n"));
}
else {
OUTPUT =  rope("");
currentFn =  fn;
parseLines(tokens,fnElems);
currentFn =  null;
if ((strlen(fn->returns->type)>0)) {
if ((fn->returned==false)) {

                        char* ____BAH_COMPILER_VAR_84; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("Function '");
long int strLen_1 = strlen(fn->name);
long int strLen_2 = strlen("' is not returned.");
;                            
                            ____BAH_COMPILER_VAR_84 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                            
                            strncpy(____BAH_COMPILER_VAR_84+currStrOff, "Function '", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_84+currStrOff, fn->name, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_84+currStrOff, "' is not returned.", strLen_2);
                            currStrOff += strLen_2;
                            
                        }
                        throwErr(&l->data[len(l)-1],____BAH_COMPILER_VAR_84);
}
}
code =  code->add(code, OUTPUT)->add(code->add(code, OUTPUT), rope("};\n"));
}
if ((doesOutput==true)) {
nextLine =  concatCPSTRING(nextLine,code->toStr((struct rope*)code));
}
struct string mthdDecl =  getCType(fn->returns->type,elems);

                        char* ____BAH_COMPILER_VAR_85; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("(*");
long int strLen_1 = strlen(mfn->name);
long int strLen_2 = strlen(")(");
;                            
                            ____BAH_COMPILER_VAR_85 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                            
                            strncpy(____BAH_COMPILER_VAR_85+currStrOff, "(*", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_85+currStrOff, mfn->name, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_85+currStrOff, ")(", strLen_2);
                            currStrOff += strLen_2;
                            
                        }
                        mthdDecl.append((struct string*)&mthdDecl,____BAH_COMPILER_VAR_85);
j =  0;
while ((j<len(arguments))) {
struct variable* a =  arguments->data[j];
struct string tp =  getCType(a->type,elems);
tp.append((struct string*)&tp,concatCPSTRING(" ",a->name));
max =  len(arguments) - 1;
if ((j!=max)) {
tp.append((struct string*)&tp,",");
}
mthdDecl.append((struct string*)&mthdDecl,tp.str((struct string*)&tp));
j =  j + 1;
};
mthdDecl.append((struct string*)&mthdDecl,")");

{
long nLength = len(allMembs);
if (allMembs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(allMembs->data, (nLength+50)*sizeof(char *));
allMembs->data = newPtr;
}
allMembs->data[len(allMembs)] =  mthdDecl.str((struct string*)&mthdDecl);
allMembs->length = nLength+1;
} else {
allMembs->data[len(allMembs)] =  mthdDecl.str((struct string*)&mthdDecl);
};
};
i =  i + 1;
continue;
}
}
i =  i + 1;
char * mbmType =  "";
long int currentLine =  t.line;
while ((i<len(l))) {
t =  l->data[i];
if ((strcmp(t.cont, "=") == 0)) {
i =  i - 1;
break;
}
if ((t.line!=currentLine)) {
i =  i - 1;
break;
}
mbmType =  concatCPSTRING(mbmType,t.cont);
i =  i + 1;
};
memb->type =  mbmType;
i =  i + 1;
t =  l->data[i];
if ((i<len(l))) {
if ((strcmp(t.cont, "=") == 0)) {
i =  i + 1;
t =  l->data[i];
if ((t.isValue==false)) {
throwErr(&t,"Cannot use {TOKEN} as default value for member.");
}
char * tt =  getTypeFromToken(&t,true,elems);
if ((compTypes(tt,memb->type)==false)) {

                        char* ____BAH_COMPILER_VAR_86; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(tt);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(memb->type);
long int strLen_4 = strlen(" for member.");
;                            
                            ____BAH_COMPILER_VAR_86 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                            
                            strncpy(____BAH_COMPILER_VAR_86+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_86+currStrOff, tt, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_86+currStrOff, ") as ", strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_86+currStrOff, memb->type, strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_86+currStrOff, " for member.", strLen_4);
                            currStrOff += strLen_4;
                            
                        }
                        throwErr(&t,____BAH_COMPILER_VAR_86);
}
memb->def =  t.cont;
}
else {
i =  i - 1;
}
}

{
long nLength = len(members);
if (members->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(members->data, (nLength+50)*sizeof(struct structMemb*));
members->data = newPtr;
}
members->data[len(members)] =  memb;
members->length = nLength+1;
} else {
members->data[len(members)] =  memb;
};
};
char * membDeclStr;
struct string cmt =  string(memb->type);
if ((cmt.hasPrefix((struct string*)&cmt,"function(")==1)) {
struct func* tmpfn =  parseFnType(cmt);
struct string tmpfnRetCType =  getCType(tmpfn->returns->type,elems);
char * tmpfnArgsCType =  "";
long int j =  0;
while ((j<len(tmpfn->args))) {
struct variable* arg =  tmpfn->args->data[j];
struct string ct =  getCType(arg->type,elems);
tmpfnArgsCType =  concatCPSTRING(tmpfnArgsCType,ct.str((struct string*)&ct));
j =  j + 1;
if ((j<len(tmpfn->args))) {
tmpfnArgsCType =  concatCPSTRING(tmpfnArgsCType,",");
}
};

                        char* ____BAH_COMPILER_VAR_87; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen(tmpfnRetCType.str((struct string*)&tmpfnRetCType));
long int strLen_1 = strlen(" (*");
long int strLen_2 = strlen(memb->name);
long int strLen_3 = strlen(")(");
long int strLen_4 = strlen(tmpfnArgsCType);
long int strLen_5 = strlen(")");
;                            
                            ____BAH_COMPILER_VAR_87 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                            
                            strncpy(____BAH_COMPILER_VAR_87+currStrOff, tmpfnRetCType.str((struct string*)&tmpfnRetCType), strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_87+currStrOff, " (*", strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_87+currStrOff, memb->name, strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_87+currStrOff, ")(", strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_87+currStrOff, tmpfnArgsCType, strLen_4);
                            currStrOff += strLen_4;
                            
                            strncpy(____BAH_COMPILER_VAR_87+currStrOff, ")", strLen_5);
                            currStrOff += strLen_5;
                            
                        }
                        membDeclStr =  ____BAH_COMPILER_VAR_87;
}
else {
struct string membDecl =  getCType(memb->type,elems);
membDecl.append((struct string*)&membDecl,concatCPSTRING(" ",memb->name));
membDeclStr =  membDecl.str((struct string*)&membDecl);
}

{
long nLength = len(allMembs);
if (allMembs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(allMembs->data, (nLength+50)*sizeof(char *));
allMembs->data = newPtr;
}
allMembs->data[len(allMembs)] =  membDeclStr;
allMembs->length = nLength+1;
} else {
allMembs->data[len(allMembs)] =  membDeclStr;
};
};
i =  i + 1;
};
s->members =  members;
if ((doesOutput==true)) {
OUTPUT =  OOUT;
NEXT_LINE =  nextLine;

                        char* ____BAH_COMPILER_VAR_88; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("struct ");
long int strLen_1 = strlen(s->name);
long int strLen_2 = strlen(" {\n");
;                            
                            ____BAH_COMPILER_VAR_88 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                            
                            strncpy(____BAH_COMPILER_VAR_88+currStrOff, "struct ", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_88+currStrOff, s->name, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_88+currStrOff, " {\n", strLen_2);
                            currStrOff += strLen_2;
                            
                        }
                        struct rope* code =  rope(____BAH_COMPILER_VAR_88);
i =  0;
while ((i<len(allMembs))) {
char * m =  allMembs->data[i];
code =  code->add(code, rope(concatCPSTRING(m,";\n")));
i =  i + 1;
};
code =  code->add(code, rope("};\n"));
OUTPUT =  OUTPUT->add(OUTPUT, code);
}
};
void parseDefine(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
if ((len(l)<3)) {
throwErr(&l->data[len(l)-1],"Invalid usage of define, cannot end on {TOKEN}.");
}
struct Tok ft =  l->data[1];
struct Tok st =  l->data[2];
long int i =  1;
int doesOutput =  true;
if ((strcmp(ft.cont, "!") == 0)) {
ft =  l->data[2];
st =  l->data[3];
i =  2;
doesOutput =  false;
}
if ((strcmp(st.cont, "(") == 0)) {
struct func* fn = memoryAlloc(sizeof(struct func));
fn->name = "";
fn->args = memoryAlloc(sizeof(array(struct variable*)));
            fn->args->length = 0;
            fn->args->elemSize = sizeof(struct variable*);
            fn->isBinding = false;
fn->from = "";
fn->file = "";
fn->line = 1;
char * code =  parseFnHeader("",l,&i,fn,elems);
array(struct func*)* fns =  elems->fns;
fn->isBinding =  true;

{
long nLength = len(fns);
if (fns->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(fns->data, (nLength+50)*sizeof(struct func*));
fns->data = newPtr;
}
fns->data[len(fns)] =  fn;
fns->length = nLength+1;
} else {
fns->data[len(fns)] =  fn;
};
};
if ((doesOutput==true)) {
OUTPUT =  OUTPUT->add(OUTPUT, rope(concatCPSTRING(code,";\n")));
}
}
else {
if ((st.type!=TOKEN_TYPE_VAR)) {
throwErr(&st,"Cannot use {TOKEN} as type.");
}
if ((ft.type!=TOKEN_TYPE_VAR)) {
throwErr(&ft,"Cannot use {TOKEN} as new type name.");
}
struct string cTypeNewType =  getCType(st.cont,elems);
char * cTypeNewTypeStr =  cTypeNewType.str((struct string*)&cTypeNewType);
if ((doesOutput==true)) {

                        char* ____BAH_COMPILER_VAR_89; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("typedef ");
long int strLen_1 = strlen(cTypeNewTypeStr);
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(ft.cont);
long int strLen_4 = strlen(";\n");
;                            
                            ____BAH_COMPILER_VAR_89 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                            
                            strncpy(____BAH_COMPILER_VAR_89+currStrOff, "typedef ", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_89+currStrOff, cTypeNewTypeStr, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_89+currStrOff, " ", strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_89+currStrOff, ft.cont, strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_89+currStrOff, ";\n", strLen_4);
                            currStrOff += strLen_4;
                            
                        }
                        OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_89));
}
array(char *)* tps =  elems->types;

{
long nLength = len(tps);
if (tps->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(tps->data, (nLength+50)*sizeof(char *));
tps->data = newPtr;
}
tps->data[len(tps)] =  ft.cont;
tps->length = nLength+1;
} else {
tps->data[len(tps)] =  ft.cont;
};
};
}
};
void parseClib(__BAH_ARR_TYPE_Tok line){
array(char *)* clibs =  compilerState.cLibs;
long int i =  1;
while ((i<len(line))) {
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
char * l =  clibs->data[j];
if ((strcmp(l, ccstr) == 0)) {
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
void * newPtr = GC_REALLOC(clibs->data, (nLength+50)*sizeof(char *));
clibs->data = newPtr;
}
clibs->data[len(clibs)] =  ccstr;
clibs->length = nLength+1;
} else {
clibs->data[len(clibs)] =  ccstr;
};
};
i =  i + 1;
};
};
void parseConst(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
l =  parseCast(l,elems);
if ((len(l)!=4)) {
throwErr(&l->data[0],"Invalid usage of {TOKEN}, must be 'const <constName> = <constValue>'. ");
}
struct Tok vart =  l->data[1];
struct Tok equt =  l->data[2];
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
struct variable* v = memoryAlloc(sizeof(struct variable));
v->name = "";
v->type = "";
v->isConst = false;
v->isArray = false;
v->from = "";
v->isConst =  true;
v->name =  vart.cont;
v->type =  getTypeFromToken(&valt,true,elems);
array(struct variable*)* vars =  elems->vars;

{
long nLength = len(vars);
if (vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(vars->data, (nLength+50)*sizeof(struct variable*));
vars->data = newPtr;
}
vars->data[len(vars)] =  v;
vars->length = nLength+1;
} else {
vars->data[len(vars)] =  v;
};
};

                        char* ____BAH_COMPILER_VAR_90; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("#define ");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(valt.cont);
long int strLen_4 = strlen("\n");
;                            
                            ____BAH_COMPILER_VAR_90 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                            
                            strncpy(____BAH_COMPILER_VAR_90+currStrOff, "#define ", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_90+currStrOff, v->name, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_90+currStrOff, " ", strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_90+currStrOff, valt.cont, strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_90+currStrOff, "\n", strLen_4);
                            currStrOff += strLen_4;
                            
                        }
                        OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_90));
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

                        char* ____BAH_COMPILER_VAR_91; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("Cannot return nothing as ");
long int strLen_1 = strlen(currentFn->returns->type);
long int strLen_2 = strlen(".");
;                            
                            ____BAH_COMPILER_VAR_91 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                            
                            strncpy(____BAH_COMPILER_VAR_91+currStrOff, "Cannot return nothing as ", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_91+currStrOff, currentFn->returns->type, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_91+currStrOff, ".", strLen_2);
                            currStrOff += strLen_2;
                            
                        }
                        throwErr(&l->data[0],____BAH_COMPILER_VAR_91);
}
}
else {
struct Tok rvt =  l->data[1];
if ((rvt.isValue==false)) {
throwErr(&rvt,"Must be a value, not {TOKEN}.");
}
rv =  rvt.cont;
char * tt =  getTypeFromToken(&rvt,true,elems);
if ((compTypes(tt,currentFn->returns->type)==false)) {

                        char* ____BAH_COMPILER_VAR_92; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("Cannot return {TOKEN} (");
long int strLen_1 = strlen(tt);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(currentFn->returns->type);
long int strLen_4 = strlen(".");
;                            
                            ____BAH_COMPILER_VAR_92 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                            
                            strncpy(____BAH_COMPILER_VAR_92+currStrOff, "Cannot return {TOKEN} (", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_92+currStrOff, tt, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_92+currStrOff, ") as ", strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_92+currStrOff, currentFn->returns->type, strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_92+currStrOff, ".", strLen_4);
                            currStrOff += strLen_4;
                            
                        }
                        throwErr(&rvt,____BAH_COMPILER_VAR_92);
}
}
if ((compilerState.isBranch==false)) {
currentFn->returned =  true;
}

                        char* ____BAH_COMPILER_VAR_93; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("return ");
long int strLen_1 = strlen(rv);
long int strLen_2 = strlen(";\n");
;                            
                            ____BAH_COMPILER_VAR_93 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                            
                            strncpy(____BAH_COMPILER_VAR_93+currStrOff, "return ", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_93+currStrOff, rv, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_93+currStrOff, ";\n", strLen_2);
                            currStrOff += strLen_2;
                            
                        }
                        OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_93));
};
void parseIf(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
if ((len(l)<4)) {
struct Tok ft =  l->data[0];
throwErr(&ft,"Invalid usage of {TOKEN}, must be 'if <condition> {<code>}'");
}
struct Tok condt =  l->data[1];
if ((strcmp(condt.bahType, "bool") != 0)) {
if ((strcmp(condt.bahType, "int") != 0)) {
throwErr(&condt,"Cannot use {TOKEN} as condition in if statement.");
}
}
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
t =  l->data[i];

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] =  t;
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] =  t;
};
};
i =  i + 1;
};

                        char* ____BAH_COMPILER_VAR_94; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("if (");
long int strLen_1 = strlen(condt.cont);
long int strLen_2 = strlen(") {\n");
;                            
                            ____BAH_COMPILER_VAR_94 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                            
                            strncpy(____BAH_COMPILER_VAR_94+currStrOff, "if (", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_94+currStrOff, condt.cont, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_94+currStrOff, ") {\n", strLen_2);
                            currStrOff += strLen_2;
                            
                        }
                        OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_94));
struct Elems* ifElems =  dupElems(elems);
int oldIB =  compilerState.isBranch;
compilerState.isBranch =  true;
parseLines(tokens,ifElems);
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
struct Tok ft =  l->data[1];
OUTPUT =  OUTPUT->add(OUTPUT, rope("else "));
if ((strcmp(ft.cont, "if") == 0)) {
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
long int i =  1;
while ((i<len(l))) {

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] =  l->data[i];
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  l->data[i];
};
};
i =  i + 1;
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

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] =  l->data[i];
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  l->data[i];
};
};
i =  i + 1;
};
OUTPUT =  OUTPUT->add(OUTPUT, rope("{\n"));
struct Elems* ifElems =  dupElems(elems);
int oldIB =  compilerState.isBranch;
compilerState.isBranch =  true;
parseLines(memory,ifElems);
compilerState.isBranch =  oldIB;
OUTPUT =  OUTPUT->add(OUTPUT, rope("}\n"));
}
};
void parseFor(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
if ((len(l)<4)) {
throwErr(&l->data[0],"Invalid usage of {TOKEN}.");
}
struct Tok condt =  l->data[1];
if ((strcmp(condt.bahType, "bool") != 0)) {
if ((strcmp(condt.bahType, "int") != 0)) {
throwErr(&condt,"Cannot use {TOKEN} as condition in for statement.");
}
}
struct Tok t =  l->data[2];
if ((strcmp(t.cont, "{") != 0)) {
throwErr(&t,"Expected '{' not {TOKEN} after condtition in for statement.");
}
array(struct Tok)* tokens = memoryAlloc(sizeof(array(struct Tok)));

tokens->length = 0;
tokens->elemSize = sizeof(struct Tok);
long int max =  len(l) - 1;
long int i =  3;
while ((i<max)) {
t =  l->data[i];

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] =  t;
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] =  t;
};
};
i =  i + 1;
};

                        char* ____BAH_COMPILER_VAR_95; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("while (");
long int strLen_1 = strlen(condt.cont);
long int strLen_2 = strlen(") {\n");
;                            
                            ____BAH_COMPILER_VAR_95 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                            
                            strncpy(____BAH_COMPILER_VAR_95+currStrOff, "while (", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_95+currStrOff, condt.cont, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_95+currStrOff, ") {\n", strLen_2);
                            currStrOff += strLen_2;
                            
                        }
                        OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_95));
struct Elems* ifElems =  dupElems(elems);
int oldIB =  compilerState.isBranch;
int oldIF =  compilerState.isFor;
compilerState.isBranch =  true;
compilerState.isFor =  true;
parseLines(tokens,ifElems);
compilerState.isFor =  oldIF;
compilerState.isBranch =  oldIB;
OUTPUT =  OUTPUT->add(OUTPUT, rope("};\n"));
};
void parseForOp(__BAH_ARR_TYPE_Tok l){
struct Tok ft =  l->data[0];
if ((compilerState.isFor==false)) {
throwErr(&ft,"Cannot {TOKEN} outside of for statement.");
}
if ((len(l)!=1)) {
throwErr(&ft,"Nothing expected after {TOKEN}.");
}
OUTPUT =  OUTPUT->add(OUTPUT, rope(concatCPSTRING(ft.cont,";\n")));
};
__BAH_ARR_TYPE_Tok prePross(__BAH_ARR_TYPE_Tok line,struct Elems* elems){
array(struct Tok)* fl = memoryAlloc(sizeof(array(struct Tok)));

fl->length = 0;
fl->elemSize = sizeof(struct Tok);
long int i =  0;
while ((i<len(line))) {
struct Tok t =  line->data[i];
if ((strcmp(t.cont, "{") == 0)) {
struct Tok nt =  line->data[i + 1];
if ((nt.line!=t.line)) {
break;
}
}

{
long nLength = len(fl);
if (fl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(fl->data, (nLength+50)*sizeof(struct Tok));
fl->data = newPtr;
}
fl->data[len(fl)] =  t;
fl->length = nLength+1;
} else {
fl->data[len(fl)] =  t;
};
};
i =  i + 1;
};
array(struct Tok)* sl = memoryAlloc(sizeof(array(struct Tok)));

sl->length = 0;
sl->elemSize = sizeof(struct Tok);
while ((i<len(line))) {

{
long nLength = len(sl);
if (sl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(sl->data, (nLength+50)*sizeof(struct Tok));
sl->data = newPtr;
}
sl->data[len(sl)] =  line->data[i];
sl->length = nLength+1;
} else {
sl->data[len(sl)] =  line->data[i];
};
};
i =  i + 1;
};
fl =  parseStructVars(fl,elems);
fl =  parseFnCall(fl,elems);
fl =  parseArrayVars(fl,elems);
fl =  parseArrayType(fl,elems);
fl =  parseCast(fl,elems);
fl =  parseOperations(fl,elems);
fl =  parseBool(fl,elems);
if ((len(sl)>0)) {
i =  0;
while ((i<len(sl))) {

{
long nLength = len(fl);
if (fl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(fl->data, (nLength+50)*sizeof(struct Tok));
fl->data = newPtr;
}
fl->data[len(fl)] =  sl->data[i];
fl->length = nLength+1;
} else {
fl->data[len(fl)] =  sl->data[i];
};
};
i =  i + 1;
};
}
return fl;
};
void parseFnDeclare(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
long int i =  0;
struct func* fn = memoryAlloc(sizeof(struct func));
fn->name = "";
fn->args = memoryAlloc(sizeof(array(struct variable*)));
            fn->args->length = 0;
            fn->args->elemSize = sizeof(struct variable*);
            fn->isBinding = false;
fn->from = "";
fn->file = "";
fn->line = 1;
struct Tok ft =  l->data[0];
char * code =  parseFnHeader("",l,&i,fn,elems);
fn->line =  ft.line;
fn->file =  compilerState.currentFile;
struct func* ogFn =  searchFunc(fn->name,elems,false);
if ((ogFn!=null)) {
if ((ogFn->isBinding==false)) {
char * lineStr =  intToStr(ogFn->line);

                        char* ____BAH_COMPILER_VAR_96; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("Cannot redeclare function {TOKEN}, previous declaration: ");
long int strLen_1 = strlen(ogFn->file);
long int strLen_2 = strlen(":");
long int strLen_3 = strlen(lineStr);
long int strLen_4 = strlen(".");
;                            
                            ____BAH_COMPILER_VAR_96 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                            
                            strncpy(____BAH_COMPILER_VAR_96+currStrOff, "Cannot redeclare function {TOKEN}, previous declaration: ", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_96+currStrOff, ogFn->file, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_96+currStrOff, ":", strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_96+currStrOff, lineStr, strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_96+currStrOff, ".", strLen_4);
                            currStrOff += strLen_4;
                            
                        }
                        throwErr(&ft,____BAH_COMPILER_VAR_96);
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
struct variable* fa =  fn->args->data[0];
if ((compTypes(fa->type,"[]cpstring")==false)) {
throwErr(&ft,"{TOKEN} function should take []cpstring as argument. Should be: \n            'main(args []cpstring) int'");
}
}
code =  concatCPSTRING(code,"{\n");
OUTPUT =  OUTPUT->add(OUTPUT, rope(code));
struct Elems* fnElems =  dupElems(elems);
array(struct variable*)* vs =  fnElems->vars;
long int j =  0;
while ((j<len(fn->args))) {
struct variable* a =  fn->args->data[j];

{
long nLength = len(vs);
if (vs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(vs->data, (nLength+50)*sizeof(struct variable*));
vs->data = newPtr;
}
vs->data[len(vs)] =  a;
vs->length = nLength+1;
} else {
vs->data[len(vs)] =  a;
};
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
void * newPtr = GC_REALLOC(fns->data, (nLength+50)*sizeof(struct func*));
fns->data = newPtr;
}
fns->data[len(fns)] =  fn;
fns->length = nLength+1;
} else {
fns->data[len(fns)] =  fn;
};
};
}
array(struct Tok)* tokens = memoryAlloc(sizeof(array(struct Tok)));

tokens->length = 0;
tokens->elemSize = sizeof(struct Tok);
i =  i + 1;
long int max =  len(l)-1;
while ((i<max)) {
struct Tok t =  l->data[i];

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] =  t;
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] =  t;
};
};
i =  i + 1;
};
if ((len(tokens)==0)) {
OUTPUT =  OUTPUT->add(OUTPUT, rope("};\n"));
return ;
}
currentFn =  fn;
parseLines(tokens,fnElems);
currentFn =  null;
if ((strlen(fn->returns->type)>0)) {
if ((fn->returned==false)) {

                        char* ____BAH_COMPILER_VAR_97; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("Function '");
long int strLen_1 = strlen(fn->name);
long int strLen_2 = strlen("' is not returned.");
;                            
                            ____BAH_COMPILER_VAR_97 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                            
                            strncpy(____BAH_COMPILER_VAR_97+currStrOff, "Function '", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_97+currStrOff, fn->name, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_97+currStrOff, "' is not returned.", strLen_2);
                            currStrOff += strLen_2;
                            
                        }
                        throwErr(&l->data[len(l)-1],____BAH_COMPILER_VAR_97);
}
}
OUTPUT =  OUTPUT->add(OUTPUT, rope("};\n"));
};
void parseLine(__BAH_ARR_TYPE_Tok line,struct Elems* elems){
if ((len(line)==0)) {
return ;
}
line =  parsePointers(line);
lineType ltp =  getLineType(line);
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
return ;
}
else if ((ltp!=LINE_TYPE_FN_DECL)) {
line =  prePross(line,elems);
}
if ((ltp==LINE_TYPE_VAR)) {
parsed =  true;
parseVar(line,elems);
}
else if ((ltp==LINE_TYPE_FN_CALL)) {
if ((len(line)>1)) {
throwErr(&line->data[len(line)-1],"Not expecting {TOKEN} after function call.");
}
struct Tok ft =  line->data[0];
parsed =  true;
OUTPUT =  OUTPUT->add(OUTPUT, rope(concatCPSTRING(ft.cont,";\n")));
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
parseForOp(line);
}
if ((parsed==false)) {
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
return ;
}
array(struct Tok)* line = memoryAlloc(sizeof(array(struct Tok)));

line->length = 0;
line->elemSize = sizeof(struct Tok);
struct Tok ft =  tokens->data[0];
long int currentLine =  ft.line;
long int nbEncl =  0;
long int i =  0;
while ((i<len(tokens))) {
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
if ((nbEncl==0)) {
if ((t.line!=currentLine)) {
if ((t.type==TOKEN_TYPE_ENCL)) {

{
long nLength = len(line);
if (line->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(line->data, (nLength+50)*sizeof(struct Tok));
line->data = newPtr;
}
line->data[len(line)] =  t;
line->length = nLength+1;
} else {
line->data[len(line)] =  t;
};
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
else if ((strcmp(t.cont, ";") == 0)) {
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
void * newPtr = GC_REALLOC(line->data, (nLength+50)*sizeof(struct Tok));
line->data = newPtr;
}
line->data[len(line)] =  t;
line->length = nLength+1;
} else {
line->data[len(line)] =  t;
};
};
i =  i + 1;
};
if ((len(line)>0)) {
if ((nbEncl==0)) {
parseLine(line,elems);
clear(line);
}
else {
ft =  line->data[len(line)-1];
throwErr(&ft,"Missing closing token, line ending by {TOKEN}.");
}
}
};
long int main(__BAH_ARR_TYPE_cpstring args){
struct flags flags =  {};
flags.flags = memoryAlloc(sizeof(array(struct flag*)));
            flags.flags->length = 0;
            flags.flags->elemSize = sizeof(struct flag*);
            flags.args = memoryAlloc(sizeof(array(char *)));
            flags.args->length = 0;
            flags.args->elemSize = sizeof(char *);
            flags.addString = flags__addString;
flags.addBool = flags__addBool;
flags.addInt = flags__addInt;
flags.addFloat = flags__addFloat;
flags.invalidate = flags__invalidate;
flags.getFlag = flags__getFlag;
flags.get = flags__get;
flags.getInt = flags__getInt;
flags.getFloat = flags__getFloat;
flags.isSet = flags__isSet;
flags.parse = flags__parse;
flags.addString((struct flags*)&flags,"o","Name of the file to output.");
flags.addBool((struct flags*)&flags,"c","Translate bah file to C instead of compiling it.");
flags.addBool((struct flags*)&flags,"v","Show version of the compiler.");
flags.addBool((struct flags*)&flags,"l","Compile as a library.");
flags.parse((struct flags*)&flags,args);
if ((flags.isSet((struct flags*)&flags,"v")==1)) {

                        char* ____BAH_COMPILER_VAR_98; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("Bah compiler version: ");
long int strLen_1 = strlen(BAH_VERSION);
long int strLen_2 = strlen(".\n© Alois Laurent Boe");
;                            
                            ____BAH_COMPILER_VAR_98 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                            
                            strncpy(____BAH_COMPILER_VAR_98+currStrOff, "Bah compiler version: ", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_98+currStrOff, BAH_VERSION, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_98+currStrOff, ".\n© Alois Laurent Boe", strLen_2);
                            currStrOff += strLen_2;
                            
                        }
                        println(____BAH_COMPILER_VAR_98);
return 0;
}
if (((flags.isSet((struct flags*)&flags,"c")==1)&&(flags.isSet((struct flags*)&flags,"l")==1))) {
panic("Cannot use -c (to translate to C code) and -l (to compile as a library) at the same time.");
}

                        char* ____BAH_COMPILER_VAR_99; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("\n#include \"");
long int strLen_1 = strlen(BAH_DIR);
long int strLen_2 = strlen("libs/include/gc.h\"\n\n#define noCheck(v) v\n#define array(type)	\
struct{	\
type *data; \
long int length; \
long int elemSize; \
}\ntypedef array(char*)* __BAH_ARR_TYPE_cpstring;\nlong int __BAH__main(__BAH_ARR_TYPE_cpstring);\n");
;                            
                            ____BAH_COMPILER_VAR_99 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                            
                            strncpy(____BAH_COMPILER_VAR_99+currStrOff, "\n#include \"", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_99+currStrOff, BAH_DIR, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_99+currStrOff, "libs/include/gc.h\"\n\n#define noCheck(v) v\n#define array(type)	\
struct{	\
type *data; \
long int length; \
long int elemSize; \
}\ntypedef array(char*)* __BAH_ARR_TYPE_cpstring;\nlong int __BAH__main(__BAH_ARR_TYPE_cpstring);\n", strLen_2);
                            currStrOff += strLen_2;
                            
                        }
                        OUTPUT =  rope(____BAH_COMPILER_VAR_99);
if ((flags.isSet((struct flags*)&flags,"l")==0)) {
OUTPUT =  OUTPUT->add(OUTPUT, rope("\nint main(int argc, char ** argv) {\nGC_INIT();\narray(char*) * args = GC_MALLOC(sizeof(array(char*)));\nargs->data = GC_MALLOC(sizeof(char*)*argc);\nmemcpy(args->data, argv, sizeof(char*)*argc);\nargs->elemSize = sizeof(char*);\nargs->length = argc;\nreturn __BAH__main((__BAH_ARR_TYPE_cpstring)args);\n};\n#define main(v) __BAH__main(v)\n"));
}
{};
compilerState.includes = memoryAlloc(sizeof(array(char *)));
            compilerState.includes->length = 0;
            compilerState.includes->elemSize = sizeof(char *);
            compilerState.cLibs = memoryAlloc(sizeof(array(char *)));
            compilerState.cLibs->length = 0;
            compilerState.cLibs->elemSize = sizeof(char *);
            compilerState.isBranch = false;
compilerState.isFor = false;
compilerState.arrTypesDecl = memoryAlloc(sizeof(array(char *)));
            compilerState.arrTypesDecl->length = 0;
            compilerState.arrTypesDecl->elemSize = sizeof(char *);
            compilerState.haveEntryPoint = false;

{
long nLength = 0;
if (compilerState.arrTypesDecl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(compilerState.arrTypesDecl->data, (nLength+50)*sizeof(char *));
compilerState.arrTypesDecl->data = newPtr;
}
compilerState.arrTypesDecl->data[0] =  "__BAH_ARR_TYPE_cpstring";
compilerState.arrTypesDecl->length = nLength+1;
} else {
compilerState.arrTypesDecl->data[0] =  "__BAH_ARR_TYPE_cpstring";
};
};
char * fileName =  args->data[1];
compilerState.currentFile =  fileName;
struct fileMap fm =  {};
fm.open = fileMap__open;
fm.isValid = fileMap__isValid;
fm.close = fileMap__close;
char * f =  fm.open((struct fileMap*)&fm,fileName);
long int startTime =  getTimeUnix();
array(struct Tok)* tokens =  lexer(f);
fm.close((struct fileMap*)&fm);
if ((len(tokens)==0)) {

                        char* ____BAH_COMPILER_VAR_100; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("File '");
long int strLen_1 = strlen(fileName);
long int strLen_2 = strlen("' not recognized.");
;                            
                            ____BAH_COMPILER_VAR_100 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                            
                            strncpy(____BAH_COMPILER_VAR_100+currStrOff, "File '", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_100+currStrOff, fileName, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_100+currStrOff, "' not recognized.", strLen_2);
                            currStrOff += strLen_2;
                            
                        }
                        panic(____BAH_COMPILER_VAR_100);
}
struct Elems* elems = memoryAlloc(sizeof(struct Elems));
elems->vars = memoryAlloc(sizeof(array(struct variable*)));
            elems->vars->length = 0;
            elems->vars->elemSize = sizeof(struct variable*);
            elems->structs = memoryAlloc(sizeof(array(struct cStruct*)));
            elems->structs->length = 0;
            elems->structs->elemSize = sizeof(struct cStruct*);
            elems->types = memoryAlloc(sizeof(array(char *)));
            elems->types->length = 0;
            elems->types->elemSize = sizeof(char *);
            elems->fns = memoryAlloc(sizeof(array(struct func*)));
            elems->fns->length = 0;
            elems->fns->elemSize = sizeof(struct func*);
            if ((includeFile("builtin.bah",elems)==false)) {

                        char* ____BAH_COMPILER_VAR_101; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("Could not find std-libs, please check '");
long int strLen_1 = strlen(BAH_DIR);
long int strLen_2 = strlen("'");
;                            
                            ____BAH_COMPILER_VAR_101 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                            
                            strncpy(____BAH_COMPILER_VAR_101+currStrOff, "Could not find std-libs, please check '", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_101+currStrOff, BAH_DIR, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_101+currStrOff, "'", strLen_2);
                            currStrOff += strLen_2;
                            
                        }
                        panic(____BAH_COMPILER_VAR_101);
}
parseLines(tokens,elems);
long int totalTime =  getTimeUnix() - startTime;

                        char* ____BAH_COMPILER_VAR_102; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("Parsed. (");
long int strLen_1 = strlen(intToStr(totalLines));
long int strLen_2 = strlen(" lines, total time: ");
long int strLen_3 = strlen(intToStr(totalTime / 1000000));
long int strLen_4 = strlen("ms, lexer time: ");
long int strLen_5 = strlen(intToStr(totalLexerTime / 1000000));
long int strLen_6 = strlen("ms)\e[0m");
;                            
                            ____BAH_COMPILER_VAR_102 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                            
                            strncpy(____BAH_COMPILER_VAR_102+currStrOff, "Parsed. (", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_102+currStrOff, intToStr(totalLines), strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_102+currStrOff, " lines, total time: ", strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_102+currStrOff, intToStr(totalTime / 1000000), strLen_3);
                            currStrOff += strLen_3;
                            
                            strncpy(____BAH_COMPILER_VAR_102+currStrOff, "ms, lexer time: ", strLen_4);
                            currStrOff += strLen_4;
                            
                            strncpy(____BAH_COMPILER_VAR_102+currStrOff, intToStr(totalLexerTime / 1000000), strLen_5);
                            currStrOff += strLen_5;
                            
                            strncpy(____BAH_COMPILER_VAR_102+currStrOff, "ms)\e[0m", strLen_6);
                            currStrOff += strLen_6;
                            
                        }
                        println(____BAH_COMPILER_VAR_102);
if ((flags.isSet((struct flags*)&flags,"o")==1)) {
fileName =  flags.get((struct flags*)&flags,"o");
}
else {
struct string outFileName =  string(fileName);
outFileName.trimRight((struct string*)&outFileName,4);
fileName =  outFileName.str((struct string*)&outFileName);
}
if ((flags.isSet((struct flags*)&flags,"c")==0)) {
char * randFileName =  "TMP_C_FILE_";
long int i =  0;
while ((i<9)) {
long int nb =  randomInRange(0,99);
char * s =  intToStr(nb);
randFileName =  concatCPSTRING(randFileName,s);
i =  i + 1;
};
randFileName =  concatCPSTRING(randFileName,".c");
struct fileStream fs =  {};
fs.isValid = fileStream__isValid;
fs.open = fileStream__open;
fs.close = fileStream__close;
fs.getPos = fileStream__getPos;
fs.setPos = fileStream__setPos;
fs.getSize = fileStream__getSize;
fs.rewind = fileStream__rewind;
fs.getChar = fileStream__getChar;
fs.createFile = fileStream__createFile;
fs.writeFile = fileStream__writeFile;
fs.writePtr = fileStream__writePtr;
fs.readPtr = fileStream__readPtr;
fs.readContent = fileStream__readContent;
fs.readBytes = fileStream__readBytes;
fs.writeBytes = fileStream__writeBytes;
fs.open((struct fileStream*)&fs,randFileName,"w");
fs.writeFile((struct fileStream*)&fs,OUTPUT->toStr((struct rope*)OUTPUT));
fs.close((struct fileStream*)&fs);

                        char* ____BAH_COMPILER_VAR_103; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("clang ");
long int strLen_1 = strlen(randFileName);
long int strLen_2 = strlen(" -w -o ");
long int strLen_3 = strlen(fileName);
;                            
                            ____BAH_COMPILER_VAR_103 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                            
                            strncpy(____BAH_COMPILER_VAR_103+currStrOff, "clang ", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_103+currStrOff, randFileName, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_103+currStrOff, " -w -o ", strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_103+currStrOff, fileName, strLen_3);
                            currStrOff += strLen_3;
                            
                        }
                        char * gccArgs =  ____BAH_COMPILER_VAR_103;
if ((flags.isSet((struct flags*)&flags,"l")==1)) {
gccArgs =  concatCPSTRING(gccArgs," -c");
}
array(char *)* cLibs =  compilerState.cLibs;
i =  0;
while ((i<len(cLibs))) {
char * l =  cLibs->data[i];

                        char* ____BAH_COMPILER_VAR_104; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen(gccArgs);
long int strLen_1 = strlen(" -");
long int strLen_2 = strlen(l);
;                            
                            ____BAH_COMPILER_VAR_104 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                            
                            strncpy(____BAH_COMPILER_VAR_104+currStrOff, gccArgs, strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_104+currStrOff, " -", strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_104+currStrOff, l, strLen_2);
                            currStrOff += strLen_2;
                            
                        }
                        gccArgs =  ____BAH_COMPILER_VAR_104;
i =  i + 1;
};
struct command cmd =  command(gccArgs);
char * gccOut =  cmd.run((struct command*)&cmd);
removeFile(randFileName);
if ((strlen(gccOut)>0)) {
println("\e[1;31m[CLANG-ERROR]\e[0m\nCould not compiled.");
exit(1);
}
if ((flags.isSet((struct flags*)&flags,"l")==1)) {

                        char* ____BAH_COMPILER_VAR_105; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("ar rcs ");
long int strLen_1 = strlen(fileName);
long int strLen_2 = strlen(".a ");
long int strLen_3 = strlen(fileName);
;                            
                            ____BAH_COMPILER_VAR_105 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                            
                            strncpy(____BAH_COMPILER_VAR_105+currStrOff, "ar rcs ", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_105+currStrOff, fileName, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_105+currStrOff, ".a ", strLen_2);
                            currStrOff += strLen_2;
                            
                            strncpy(____BAH_COMPILER_VAR_105+currStrOff, fileName, strLen_3);
                            currStrOff += strLen_3;
                            
                        }
                        cmd =  command(____BAH_COMPILER_VAR_105);
cmd.run((struct command*)&cmd);
}
}
else {
if ((flags.isSet((struct flags*)&flags,"o")==0)) {
fileName =  concatCPSTRING(fileName,".c");
}

                        char* ____BAH_COMPILER_VAR_106; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("gcc ");
long int strLen_1 = strlen(fileName);
long int strLen_2 = strlen(" -w ");
;                            
                            ____BAH_COMPILER_VAR_106 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                            
                            strncpy(____BAH_COMPILER_VAR_106+currStrOff, "gcc ", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_106+currStrOff, fileName, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_106+currStrOff, " -w ", strLen_2);
                            currStrOff += strLen_2;
                            
                        }
                        char * gccArgs =  ____BAH_COMPILER_VAR_106;
array(char *)* cLibs =  compilerState.cLibs;
long int i =  0;
while ((i<len(cLibs))) {
char * l =  cLibs->data[i];

                        char* ____BAH_COMPILER_VAR_107; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen(gccArgs);
long int strLen_1 = strlen(" -");
long int strLen_2 = strlen(l);
;                            
                            ____BAH_COMPILER_VAR_107 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                            
                            strncpy(____BAH_COMPILER_VAR_107+currStrOff, gccArgs, strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_107+currStrOff, " -", strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_107+currStrOff, l, strLen_2);
                            currStrOff += strLen_2;
                            
                        }
                        gccArgs =  ____BAH_COMPILER_VAR_107;
i =  i + 1;
};

                        char* ____BAH_COMPILER_VAR_108; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("//COMPILE WITH: '");
long int strLen_1 = strlen(gccArgs);
long int strLen_2 = strlen("'\n");
;                            
                            ____BAH_COMPILER_VAR_108 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                            
                            strncpy(____BAH_COMPILER_VAR_108+currStrOff, "//COMPILE WITH: '", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_108+currStrOff, gccArgs, strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_108+currStrOff, "'\n", strLen_2);
                            currStrOff += strLen_2;
                            
                        }
                        OUTPUT =  concatenateRopes(rope(____BAH_COMPILER_VAR_108),OUTPUT);
struct fileStream fs =  {};
fs.isValid = fileStream__isValid;
fs.open = fileStream__open;
fs.close = fileStream__close;
fs.getPos = fileStream__getPos;
fs.setPos = fileStream__setPos;
fs.getSize = fileStream__getSize;
fs.rewind = fileStream__rewind;
fs.getChar = fileStream__getChar;
fs.createFile = fileStream__createFile;
fs.writeFile = fileStream__writeFile;
fs.writePtr = fileStream__writePtr;
fs.readPtr = fileStream__readPtr;
fs.readContent = fileStream__readContent;
fs.readBytes = fileStream__readBytes;
fs.writeBytes = fileStream__writeBytes;
fs.open((struct fileStream*)&fs,fileName,"w");
fs.writeFile((struct fileStream*)&fs,OUTPUT->toStr((struct rope*)OUTPUT));
fs.close((struct fileStream*)&fs);
}
totalTime =  getTimeUnix() - startTime;

                        char* ____BAH_COMPILER_VAR_109; 
                        {
                            long int currStrOff = 0;
                            long int strLen_0 = strlen("\e[1;32mDone. (compiled in ");
long int strLen_1 = strlen(intToStr(totalTime / 1000000));
long int strLen_2 = strlen("ms)\e[0m");
;                            
                            ____BAH_COMPILER_VAR_109 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                            
                            strncpy(____BAH_COMPILER_VAR_109+currStrOff, "\e[1;32mDone. (compiled in ", strLen_0);
                            currStrOff += strLen_0;
                            
                            strncpy(____BAH_COMPILER_VAR_109+currStrOff, intToStr(totalTime / 1000000), strLen_1);
                            currStrOff += strLen_1;
                            
                            strncpy(____BAH_COMPILER_VAR_109+currStrOff, "ms)\e[0m", strLen_2);
                            currStrOff += strLen_2;
                            
                        }
                        println(____BAH_COMPILER_VAR_109);
return 0;
};
