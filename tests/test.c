//COMPILE WITH: 'gcc ./test.c -static -w  -w /opt/bah/libs/libgc.a -lpthread -lm -w /opt/bah/libs/libssl.a -w /opt/bah/libs/libcrypto.a'

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
noCheck( arr -> length = s + 1 );
noCheck( arr -> elemSize = 1 );
noCheck( arr -> data = r );
return arr;
};
void * unser(__BAH_ARR_TYPE_char data){
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
void * r =  memoryAlloc(*sptr);
memcpy(r,noCheck( data -> data + 8 ),*sptr);
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
char * tmpS =  memoryAlloc(this->length + 1);
strcpy(tmpS,this->content);
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
char * buff =  memoryAlloc(65);
sprintf(buff,"%ld",(void *)i);
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
timespec_get(&ts,noCheck( TIME_UTC ));
long int s =  ts.tv_sec * 1000000000 + ts.tv_nsec;
return s;
};
void test(char * name, fn){
char * s;
long int start =  getTimeUnix();
int passed =  fn();
long int end =  getTimeUnix();
long int dur =  end - start;
char * durStr =  intToStr(dur);
if ((passed==true)) {
s =  concatCPSTRING("\e[0;32m✔ ",name);
}
else {
s =  concatCPSTRING("\e[0;31m❌ ",name);
}
s =  concatCPSTRING(concatCPSTRING(concatCPSTRING(s," ("),durStr),"ns)");
println(s);
};
void appendCharArr(__BAH_ARR_TYPE_char a,__BAH_ARR_TYPE_char b){
long int offset =  len(a);
long int lenB =  len(b);
long int i =  0;
while ((i<lenB)) {

{
long nLength = offset + i;
if (a->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(a->data, (nLength+50)*sizeof(char));
a->data = newPtr;
}
a->data[offset + i] =  b->data[i];
a->length = nLength+1;
} else {
a->data[offset + i] =  b->data[i];
};
};
i =  i + 1;
};
};
struct markdownLine {
struct string* line;
long int type;
struct string rel;
};
struct markdown {
array(struct markdownLine*)* lines;
char *(*str)(struct markdown* this);
char *(*html)(struct markdown* this);
};
char * markdown__str(struct markdown* this){
char * s =  "";
long int i =  0;
while ((i<len(this->lines))) {
struct markdownLine* mdl =  this->lines->data[i];
char * si =  intToStr(i);
char * l =  mdl->line->str((struct string*)mdl->line);
s =  concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(s,si),": "),l),"\n");
i =  i + 1;
};
return s;
};
char * markdown__html(struct markdown* this){
char * html =  "<p>";
long int i =  0;
while ((i<len(this->lines))) {
struct markdownLine* mdl =  this->lines->data[i];
char * l =  mdl->line->str((struct string*)mdl->line);
if ((mdl->type==1)) {
html =  concatCPSTRING(concatCPSTRING(concatCPSTRING(html,"<h1>"),l),"</h1><hr>");
}
else if ((mdl->type==2)) {
html =  concatCPSTRING(concatCPSTRING(concatCPSTRING(html,"<h2>"),l),"</h2><hr>");
}
else if ((mdl->type==3)) {
html =  concatCPSTRING(concatCPSTRING(concatCPSTRING(html,"<h3>"),l),"</h3>");
}
else if ((mdl->type==4)) {
html =  concatCPSTRING(concatCPSTRING(concatCPSTRING(html,"<h4>"),l),"</h4>");
}
else if ((mdl->type==5)) {
html =  concatCPSTRING(concatCPSTRING(concatCPSTRING(html,"<h5>"),l),"</h5>");
}
else if ((mdl->type==6)) {
html =  concatCPSTRING(concatCPSTRING(concatCPSTRING(html,"<h3>"),l),"</h3>");
}
else if ((mdl->type==7)) {
html =  concatCPSTRING(concatCPSTRING(concatCPSTRING(html,"&nbsp;• "),l),"<br>");
}
else if ((mdl->type==8)) {
html =  concatCPSTRING(concatCPSTRING(html,"\t"),l);
}
else if ((mdl->type==9)) {
html =  concatCPSTRING(concatCPSTRING(concatCPSTRING(html,"<blockquote>"),l),"</blockquote>");
}
else if ((mdl->type==10)) {
char * rel =  mdl->rel.str((struct string*)&mdl->rel);
html =  concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(html,"<pre class=\"highlight highlight-source-"),rel),"\">"),l),"</pre>");
}
else {
html =  concatCPSTRING(concatCPSTRING(html,l),"<br>");
}
html =  concatCPSTRING(html,"\n");
i =  i + 1;
};
html =  concatCPSTRING(html,"</p>");
return html;
};
struct string parseMarkdownInline(struct string l){
if ((l.length==0)) {
return l;
}
array(char)* nl = memoryAlloc(sizeof(array(char)));

nl->length = 0;
nl->elemSize = sizeof(char);
long int isBold =  0;
long int isItal =  0;
long int isUline =  0;
long int isImage =  0;
long int isLink =  0;
array(char)* linkName = memoryAlloc(sizeof(array(char)));

linkName->length = 0;
linkName->elemSize = sizeof(char);
array(char)* linkUrl = memoryAlloc(sizeof(array(char)));

linkUrl->length = 0;
linkUrl->elemSize = sizeof(char);
long int i =  0;
while ((i<l.length)) {
char c =  l.charAt((struct string*)&l,i);
if ((isLink==1)) {
if ((c==93)) {
isLink =  2;
}
else {

{
long nLength = len(linkName);
if (linkName->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(linkName->data, (nLength+50)*sizeof(char));
linkName->data = newPtr;
}
linkName->data[len(linkName)] =  c;
linkName->length = nLength+1;
} else {
linkName->data[len(linkName)] =  c;
};
};
}
i =  i + 1;
continue;
}
if ((isLink==2)) {
if ((c==40)) {
isLink =  3;
}
i =  i + 1;
continue;
}
if ((isLink==3)) {
if ((c==41)) {
if ((isImage==1)) {
appendCharArr(nl,strToArr("<img src=\""));
appendCharArr(nl,linkUrl);
appendCharArr(nl,strToArr("\" alt=\""));
appendCharArr(nl,linkName);
appendCharArr(nl,strToArr("\">"));
isImage =  0;
}
else {
appendCharArr(nl,strToArr("<a href=\""));
appendCharArr(nl,linkUrl);
appendCharArr(nl,strToArr("\">"));
appendCharArr(nl,linkName);
appendCharArr(nl,strToArr("</a>"));
}
isLink =  0;
clear(linkName);
clear(linkUrl);
}
else {

{
long nLength = len(linkUrl);
if (linkUrl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(linkUrl->data, (nLength+50)*sizeof(char));
linkUrl->data = newPtr;
}
linkUrl->data[len(linkUrl)] =  c;
linkUrl->length = nLength+1;
} else {
linkUrl->data[len(linkUrl)] =  c;
};
};
}
i =  i + 1;
continue;
}
if ((c==91)) {
long int validateState =  0;
long int ii =  i;
while ((ii<l.length)) {
char vc =  l.charAt((struct string*)&l,ii);
if ((validateState==0)) {
if ((vc==93)) {
validateState =  1;
}
}
else if ((validateState==1)) {
if ((vc==40)) {
validateState =  2;
ii =  ii + 1;
continue;
}
if ((isSpace(vc)==0)) {
validateState =  0;
}
}
else if ((validateState==2)) {
if ((vc==41)) {
validateState =  3;
break;
}
}
ii =  ii + 1;
};
if ((validateState==3)) {
isLink =  1;
i =  i + 1;
continue;
}
else if ((isImage==1)) {
isImage =  0;

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(nl->data, (nLength+50)*sizeof(char));
nl->data = newPtr;
}
nl->data[len(nl)] =  33;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  33;
};
};
}
}
if ((c==33)) {
char nc =  l.charAt((struct string*)&l,i + 1);
if ((nc==91)) {
isImage =  1;
}
i =  i + 1;
continue;
}
if ((c==42)) {
if ((l.charAt((struct string*)&l,i + 1)==42)) {
if ((isBold==1)) {
appendCharArr(nl,strToArr("</strong>"));
isBold =  0;
}
else {
appendCharArr(nl,strToArr("<strong>"));
isBold =  1;
}
i =  i + 2;
continue;
}
else {
if ((isItal==1)) {
appendCharArr(nl,strToArr("</em>"));
isItal =  0;
}
else {
appendCharArr(nl,strToArr("<em>"));
isItal =  1;
}
i =  i + 1;
continue;
}
}
if ((c==95)) {
if ((l.charAt((struct string*)&l,i + 1)==95)) {
if ((isUline==1)) {
appendCharArr(nl,strToArr("</u>"));
isUline =  0;
}
else {
appendCharArr(nl,strToArr("<u>"));
isUline =  1;
}
i =  i + 2;
continue;
}
}

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(nl->data, (nLength+50)*sizeof(char));
nl->data = newPtr;
}
nl->data[len(nl)] =  c;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  c;
};
};
i =  i + 1;
};
struct string r =  string(arrToStr(nl));
return r;
};
struct markdown parseMarkdown(char * a){
struct string md =  string(a);
array(struct string)* lines =  splitString(md,"\n");
struct markdown m =  {};
m.lines = memoryAlloc(sizeof(array(struct markdownLine*)));
            m.lines->length = 0;
            m.lines->elemSize = sizeof(struct markdownLine*);
            m.str = markdown__str;
m.html = markdown__html;
long int i =  0;
while ((i<len(lines))) {
struct string l =  lines->data[i];
struct string* nl = memoryAlloc(sizeof(struct string));
nl->set = string__set;
nl->append = string__append;
nl->prepend = string__prepend;
nl->charAt = string__charAt;
nl->compare = string__compare;
nl->str = string__str;
nl->replace = string__replace;
nl->count = string__count;
nl->hasPrefix = string__hasPrefix;
nl->hasSuffix = string__hasSuffix;
nl->trim = string__trim;
nl->trimLeft = string__trimLeft;
nl->trimRight = string__trimRight;
struct markdownLine* ml = memoryAlloc(sizeof(struct markdownLine));
ml->type = 0;
if ((l.count((struct string*)&l,"```")>0)) {
long int starts =  1;
array(struct string)* lineParts =  splitString(l,"```");
if ((len(lineParts)>0)) {
ml->rel =  lineParts->data[1];
}
else {
ml->rel =  string("");
}
ml->type =  10;
nl->set((struct string*)nl,"");
i =  i + 1;
while ((i<len(lines))) {
struct string ll =  lines->data[i];
if ((ll.count((struct string*)&ll,"```")>0)) {
break;
}
ll.append((struct string*)&ll,"\n");
nl->append((struct string*)nl,ll.str((struct string*)&ll));
i =  i + 1;
};
ml->line =  nl;

{
long nLength = len(m.lines);
if (m.lines->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(m.lines->data, (nLength+50)*sizeof(struct markdownLine*));
m.lines->data = newPtr;
}
m.lines->data[len(m.lines)] =  ml;
m.lines->length = nLength+1;
} else {
m.lines->data[len(m.lines)] =  ml;
};
};
i =  i + 1;
continue;
}
l.trim((struct string*)&l);
l =  parseMarkdownInline(l);
if (l.hasPrefix((struct string*)&l,"# ")) {
ml->type =  1;
nl->set((struct string*)nl,l.str((struct string*)&l));
nl->trimLeft((struct string*)nl,2);
}
else if (l.hasPrefix((struct string*)&l,"## ")) {
ml->type =  2;
nl->set((struct string*)nl,l.str((struct string*)&l));
nl->trimLeft((struct string*)nl,3);
}
else if (l.hasPrefix((struct string*)&l,"### ")) {
ml->type =  3;
nl->set((struct string*)nl,l.str((struct string*)&l));
nl->trimLeft((struct string*)nl,4);
}
else if (l.hasPrefix((struct string*)&l,"#### ")) {
ml->type =  4;
nl->set((struct string*)nl,l.str((struct string*)&l));
nl->trimLeft((struct string*)nl,5);
}
else if (l.hasPrefix((struct string*)&l,"##### ")) {
ml->type =  5;
nl->set((struct string*)nl,l.str((struct string*)&l));
nl->trimLeft((struct string*)nl,6);
}
else if (l.hasPrefix((struct string*)&l,"###### ")) {
ml->type =  6;
nl->set((struct string*)nl,l.str((struct string*)&l));
nl->trimLeft((struct string*)nl,7);
}
else if (l.hasPrefix((struct string*)&l,"- ")) {
ml->type =  7;
nl->set((struct string*)nl,l.str((struct string*)&l));
nl->trimLeft((struct string*)nl,2);
}
else if (l.hasPrefix((struct string*)&l,"> ")) {
ml->type =  9;
nl->set((struct string*)nl,l.str((struct string*)&l));
nl->trimLeft((struct string*)nl,2);
}
else {
if ((l.length>0)) {
char fc =  l.charAt((struct string*)&l,0);
if (isNumber(fc)) {
ml->type =  8;
}
}
nl->set((struct string*)nl,l.str((struct string*)&l));
}
ml->line =  nl;

{
long nLength = len(m.lines);
if (m.lines->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(m.lines->data, (nLength+50)*sizeof(struct markdownLine*));
m.lines->data = newPtr;
}
m.lines->data[len(m.lines)] =  ml;
m.lines->length = nLength+1;
} else {
m.lines->data[len(m.lines)] =  ml;
};
};
i =  i + 1;
};
return m;
};
void escapeMarkdownHTML(struct string* s){
s->replace((struct string*)s,"*","&ast;");
s->replace((struct string*)s,">","&gt;");
s->replace((struct string*)s,"<","&lt;");
s->replace((struct string*)s,"__","&lowbar;&lowbar;");
s->replace((struct string*)s,"-","&minus;");
s->replace((struct string*)s,"#","&num;");
};
int testMarkdown(){
#define MD_RES "<p><br>\n<h1>h1</h1><hr>\n<h2>h2</h2><hr>\n<h3>h3</h3>\n<h4>h4</h4>\n<h5>h5</h5>\n<h3>h5</h3>\n<blockquote>quote</blockquote>\n&nbsp;• list1<br>\n<em>this</em> <strong>is</strong> <u>a</u> <a href=\"./test\">test</a><br>\n<img src=\"./test.png\" alt=\"img\"><br>\n<pre class=\"highlight highlight-source-sh\">echo \"my test\"\n</pre>\n</p>"
#define doc "\n# h1\n## h2\n### h3\n#### h4\n##### h5\n###### h5\n> quote\n- list1\n*this* **is** __a__ [test](./test)\n![img](./test.png)\n```sh\necho \"my test\"\n```\n"
struct markdown md =  parseMarkdown(doc);
char * h =  md.html((struct markdown*)&md);
return (strcmp(h, MD_RES) == 0);
};
int testString(){
#define STR_RES "5preTESTpost"
struct string s =  string("TEST");
s.prepend((struct string*)&s,"   pre");
s.append((struct string*)&s,"postTRIM");
s.trim((struct string*)&s);
s.trimRight((struct string*)&s,4);
s.prepend((struct string*)&s,intToStr(5));
if ((s.compare((struct string*)&s,STR_RES)==0)) {
return false;
}
#define STR_ARR_RES "ABCDEFGHIJ"
array(char)* arr = memoryAlloc(sizeof(array(char)));

arr->length = 0;
arr->elemSize = sizeof(char);
long int i =  65;
while ((i<75)) {

{
long nLength = len(arr);
if (arr->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(arr->data, (nLength+50)*sizeof(char));
arr->data = newPtr;
}
arr->data[len(arr)] =  (char)i;
arr->length = nLength+1;
} else {
arr->data[len(arr)] =  (char)i;
};
};
i =  i + 1;
};
struct string str =  string(arrAsStr(arr));
if ((str.compare((struct string*)&str,STR_ARR_RES)==0)) {
return false;
}
#define STR_TOLWR_RES "abcdefghij"
struct string lowStr =  toLower(str);
if ((lowStr.compare((struct string*)&lowStr,STR_TOLWR_RES)==0)) {
return false;
}
#define STR_SPLIT_NB_RES 5
struct string splitTest =  string("a b c d e");
array(struct string)* splitted =  splitString(splitTest," ");
if ((len(splitted)!=STR_SPLIT_NB_RES)) {
return false;
}
#define STR_JOIN_RES "a-_-b-_-c-_-d-_-e"
struct string joined =  joinString(splitted,"-_-");
if ((joined.compare((struct string*)&joined,STR_JOIN_RES)==0)) {
return false;
}
struct string repl =  string(splitTest.str((struct string*)&splitTest));
repl.replace((struct string*)&repl," ","-_-");
if ((repl.compare((struct string*)&repl,STR_JOIN_RES)==0)) {
return false;
}
return true;
};
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/bio.h>
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
struct http_url {
struct string path;
struct string host;
struct string proto;
struct string port;
};
struct http_url* parseUrl(char * cps){
struct http_url* u = memoryAlloc(sizeof(struct http_url));
struct string s =  string(cps);
long int i =  0;
long int max =  s.length - 1;
long int hasProto =  0;
while ((i<s.length)) {
char c =  s.charAt((struct string*)&s,i);
if ((c==58)) {
hasProto =  1;
break;
}
i =  i + 1;
};
if ((hasProto==1)) {
struct string proto =  string("");
i =  0;
while ((s.charAt((struct string*)&s,i)!=58)) {
char c =  s.charAt((struct string*)&s,i);
proto.append((struct string*)&proto,charToString(c));
i =  i + 1;
};
i =  i + 1;
u->proto =  proto;
}
else {
u->proto =  string("http");
i =  0;
}
while ((s.charAt((struct string*)&s,i)==47)) {
if ((i==max)) {
break;
}
i =  i + 1;
};
struct string hn =  string("");
while (((s.charAt((struct string*)&s,i)!=47)&&(s.charAt((struct string*)&s,i)!=58))) {
char c =  s.charAt((struct string*)&s,i);
hn.append((struct string*)&hn,charToString(c));
if ((i==max)) {
break;
}
i =  i + 1;
};
u->host =  hn;
if ((i==max)) {
u->path =  string("/");
if (u->proto.compare((struct string*)&u->proto,"https")) {
u->port =  string("443");
}
else {
u->port =  string("80");
}
return u;
}
struct string port =  string("");
if ((s.charAt((struct string*)&s,i)==58)) {
i =  i + 1;
while ((i<s.length)) {
char c =  s.charAt((struct string*)&s,i);
if ((c==47)) {
break;
}
port.append((struct string*)&port,charToString(c));
i =  i + 1;
};
}
u->port =  port;
if ((i==max)) {
u->path =  string("/");
if (u->proto.compare((struct string*)&u->proto,"https")) {
u->port =  string("443");
}
else {
u->port =  string("80");
}
return u;
}
struct string path =  string("");
while ((i<=max)) {
char c =  s.charAt((struct string*)&s,i);
path.append((struct string*)&path,charToString(c));
i =  i + 1;
};
u->path =  path;
return u;
};
void closeSocket(long int sockfd){
shutdown(sockfd,noCheck( SHUT_RDWR ));
};
void sigchld_handler(long int signo){
long int status;
long int pid;
pid =  waitpid(-1,&status,1);
while ((pid>0)) {
pid =  waitpid(-1,&status,1);
};
};
typedef long int http_serverError;
#define HTTP_SERVER_NO_ERROR (http_serverError)0
#define HTTP_SERVER_SOCKET_ERROR (http_serverError)1
#define HTTP_SERVER_BIND_ERROR (http_serverError)2
#define HTTP_SERVER_LISTEN_ERROR (http_serverError)3
struct http_server {
long int port;
long int running;
long int sockfd;
http_serverError error;
void (*handle)(struct http_server*,long int);
void (*done)(struct http_server*);
void(*stop)(struct http_server* this);
void(*listenAndServe)(struct http_server* this);
};
void http_server__stop(struct http_server* this){
if ((this->sockfd==-1)) {
println("cannot stop http_server, not running");
return ;
}
this->running =  0;
closeSocket(this->sockfd);
};
void http_server__listenAndServe(struct http_server* this){
this->error =  HTTP_SERVER_NO_ERROR;
long int port =  this->port;
struct sockaddr_in servaddr;
struct sockaddr_in cliaddr;
struct sigaction sa;
long int sockfd =  socket(2,1,0);
if ((sockfd<0)) {
println("http: error opening socket");
this->error =  HTTP_SERVER_SOCKET_ERROR;
return ;
}
servaddr.sin_family =  2;
struct in_addr saddr =  {};
saddr.s_addr =  htonl(0);
servaddr.sin_addr =  saddr;
servaddr.sin_port =  htons(port);
long int isBind =  bind(sockfd,&servaddr,16);
if ((isBind!=0)) {
close(sockfd);
println(concatCPSTRING(concatCPSTRING("http: failed to bind port: '",intToStr(port)),"'"));
this->error =  HTTP_SERVER_BIND_ERROR;
return ;
}
long int isListening =  listen(sockfd,1024);
this->sockfd =  sockfd;
if ((isListening<0)) {
close(sockfd);
println("http: failed to start listening");
this->error =  HTTP_SERVER_LISTEN_ERROR;
return ;
}
memset((void *)&sa,0,152);
sa.sa_handler =  sigchld_handler;
sigaction(17,&sa,0);
if ((this->done!=null)) {
this->done((struct http_server*)this);
}
while ((this->running==1)) {
long int clilen =  16;
long int connfd =  accept(sockfd,&cliaddr,&clilen);
if ((connfd<0)) {
continue;
}
long int childpid =  fork();
if ((childpid<0)) {
println("http: failed to fork client handler");
close(connfd);
continue;
}
if ((childpid==0)) {
close(sockfd);
this->handle((struct http_server*)this,connfd);
exit(0);
}
close(connfd);
};
this->stop((struct http_server*)this);
};
void http_send(long int connfd,char * s){
send(connfd,s,strlen(s),0);
};
char * http_receive(long int connfd){
char * buffer =  memoryAlloc(1025);
struct string response =  string("");
long int nDataLength =  recv(connfd,buffer,1024,0);
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
nDataLength =  recv(connfd,buffer,1024,0);
}
};
}
return response.str((struct string*)&response);
};
#define HTTP_OK 200
#define HTTP_NOT_FOUND 404
#define HTTP_FORBIDDEN 400
#define HTTP_ERROR 500
#define HTTP_REDIRECT 301
#define HTTP_PARTIAL_CONTENT 206
struct http_transport {
long int connfd;
array(struct string*)* headers;
long int code;
struct string* body;
struct http_url* url;
char * method;
char * path;
void(*setHeader)(struct http_transport* this,char * name,char * value);
char *(*getHeader)(struct http_transport* this,char * name);
void(*write)(struct http_transport* this,char * content);
};
void http_transport__setHeader(struct http_transport* this,char * name,char * value){
struct string* h = memoryAlloc(sizeof(struct string));
h->set = string__set;
h->append = string__append;
h->prepend = string__prepend;
h->charAt = string__charAt;
h->compare = string__compare;
h->str = string__str;
h->replace = string__replace;
h->count = string__count;
h->hasPrefix = string__hasPrefix;
h->hasSuffix = string__hasSuffix;
h->trim = string__trim;
h->trimLeft = string__trimLeft;
h->trimRight = string__trimRight;
struct string ln =  toLower(string(name));
h->set((struct string*)h,ln.str((struct string*)&ln));
h->append((struct string*)h,": ");
h->append((struct string*)h,value);
long int lhs =  len(this->headers);

{
long nLength = lhs;
if (this->headers->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(this->headers->data, (nLength+50)*sizeof(struct string*));
this->headers->data = newPtr;
}
this->headers->data[lhs] =  h;
this->headers->length = nLength+1;
} else {
this->headers->data[lhs] =  h;
};
};
};
char * http_transport__getHeader(struct http_transport* this,char * name){
struct string headerName =  string(name);
headerName =  toLower(headerName);
headerName.append((struct string*)&headerName,":");
long int i =  0;
while ((i<len(this->headers))) {
struct string* currentHeader =  this->headers->data[i];
if (currentHeader->hasPrefix((struct string*)currentHeader,headerName.str((struct string*)&headerName))) {
struct string header =  string(currentHeader->str((struct string*)currentHeader));
long int space =  0;
char c =  header.charAt((struct string*)&header,headerName.length);
if (isSpace(c)) {
space =  1;
}
header.trimLeft((struct string*)&header,headerName.length + space);
return header.str((struct string*)&header);
}
i =  i + 1;
};
return "";
};
void http_transport__write(struct http_transport* this,char * content){
struct string* body =  this->body;
body->append((struct string*)body,content);
};
long int openSocket(char * host,long int port){
struct sockaddr_in serv_addr;
long int sockfd =  socket(2,1,0);
if ((sockfd<0)) {
panic("http: error opening socket");
}
struct hostent* server =  gethostbyname(host);
if ((server==null)) {
panic("http: error resolving host");
}
serv_addr.sin_port =  htons(port);
serv_addr.sin_family =  2;
unsigned long int* ha =  server->h_addr;
struct in_addr saddr =  {};
saddr.s_addr =  *ha;
serv_addr.sin_addr =  saddr;
long int canConnect =  connect(sockfd,&serv_addr,16);
if ((canConnect<0)) {
panic("error: error connecting socket");
}
return sockfd;
};
struct http_response {
long int connfd;
array(struct string*)* headers;
long int code;
struct string* body;
struct http_url* url;
char * method;
char * path;
void(*setHeader)(struct http_transport* this,char * name,char * value);
char *(*getHeader)(struct http_transport* this,char * name);
void(*write)(struct http_transport* this,char * content);
int headersSent;
void(*send)(struct http_response* this);
};
void http_response__send(struct http_response* this){
if ((this->headersSent==false)) {
struct string s =  string("HTTP/1.0 ");
if ((this->code==HTTP_OK)) {
s.append((struct string*)&s,"200 OK");
}
else if ((this->code==HTTP_NOT_FOUND)) {
s.append((struct string*)&s,"404 Not Found");
}
else if ((this->code==HTTP_FORBIDDEN)) {
s.append((struct string*)&s,"400 Bad Request");
}
else if ((this->code==HTTP_ERROR)) {
s.append((struct string*)&s,"500 Internal Server Error");
}
else if ((this->code==HTTP_REDIRECT)) {
s.append((struct string*)&s,"301 Moved Permanently");
}
else if ((this->code==HTTP_PARTIAL_CONTENT)) {
s.append((struct string*)&s,"206 Partial Content");
}
else {
s.append((struct string*)&s,intToStr(this->code));
}
s.append((struct string*)&s,"\r\n");
long int i =  0;
while ((i<len(this->headers))) {
struct string* e =  this->headers->data[i];
s.append((struct string*)&s,e->content);
s.append((struct string*)&s,"\r\n");
i =  i + 1;
};
s.append((struct string*)&s,"\r\n");
s.append((struct string*)&s,this->body->content);
this->body->set((struct string*)this->body,"");
http_send(this->connfd,s.content);
int headersSent =  true;
}
else {
http_send(this->connfd,this->body->str((struct string*)this->body));
this->body->set((struct string*)this->body,"");
}
};
struct http_response http_response(long int connfd){
struct http_response resp =  {};
resp.connfd = -1;
resp.headers = memoryAlloc(sizeof(array(struct string*)));
            resp.headers->length = 0;
            resp.headers->elemSize = sizeof(struct string*);
            resp.code = HTTP_OK;
resp.method = "";
resp.path = "";
resp.headersSent = false;
resp.setHeader = http_transport__setHeader;
resp.getHeader = http_transport__getHeader;
resp.write = http_transport__write;
resp.send = http_response__send;
resp.connfd =  connfd;
resp.setHeader((struct http_transport*)&resp,"Server","bah-http-framework");
resp.setHeader((struct http_transport*)&resp,"Connection","close");
struct string* body = memoryAlloc(sizeof(struct string));
body->set = string__set;
body->append = string__append;
body->prepend = string__prepend;
body->charAt = string__charAt;
body->compare = string__compare;
body->str = string__str;
body->replace = string__replace;
body->count = string__count;
body->hasPrefix = string__hasPrefix;
body->hasSuffix = string__hasSuffix;
body->trim = string__trim;
body->trimLeft = string__trimLeft;
body->trimRight = string__trimRight;
body->set((struct string*)body,"");
resp.body =  body;
return resp;
};
struct http_response* makeRespFromBody(struct string response){
struct http_response* resp = memoryAlloc(sizeof(struct http_response));
resp->connfd = -1;
resp->headers = memoryAlloc(sizeof(array(struct string*)));
            resp->headers->length = 0;
            resp->headers->elemSize = sizeof(struct string*);
            resp->code = HTTP_OK;
resp->method = "";
resp->path = "";
resp->headersSent = false;
resp->setHeader = http_transport__setHeader;
resp->getHeader = http_transport__getHeader;
resp->write = http_transport__write;
resp->send = http_response__send;
resp->body = memoryAlloc(sizeof(struct string));
resp->body->set = string__set;
resp->body->append = string__append;
resp->body->prepend = string__prepend;
resp->body->charAt = string__charAt;
resp->body->compare = string__compare;
resp->body->str = string__str;
resp->body->replace = string__replace;
resp->body->count = string__count;
resp->body->hasPrefix = string__hasPrefix;
resp->body->hasSuffix = string__hasSuffix;
resp->body->trim = string__trim;
resp->body->trimLeft = string__trimLeft;
resp->body->trimRight = string__trimRight;
array(struct string)* lines =  splitString(response,"\r\n");
if ((len(lines)==0)) {
return resp;
}
long int i =  0;
struct string head =  lines->data[0];
while ((i<head.length)) {
char c =  head.charAt((struct string*)&head,i);
if ((c==32)) {
i =  i + 1;
break;
}
i =  i + 1;
};
struct string httpCode =  string("");
while ((i<head.length)) {
char c =  head.charAt((struct string*)&head,i);
httpCode.append((struct string*)&httpCode,charToString(c));
if ((c==32)) {
break;
}
i =  i + 1;
};
long int httpCodeInt =  stringToInt(httpCode);
resp->code =  httpCodeInt;
long int isBody =  0;
long int max =  len(lines) - 1;
struct string body =  string("");
i =  1;
while ((i<len(lines))) {
struct string line =  lines->data[i];
if ((isBody==1)) {
struct string s =  string(line.str((struct string*)&line));
if ((i<max)) {
s.append((struct string*)&s,"\r\n");
}
body.append((struct string*)&body,s.str((struct string*)&s));
i =  i + 1;
continue;
}
if ((i>0)) {
struct string pl =  lines->data[i-1];
if ((strlen(pl.str((struct string*)&pl))==0)) {
isBody =  1;
line.trimLeft((struct string*)&line,2);
continue;
}
}
struct string* header = memoryAlloc(sizeof(struct string));
header->set = string__set;
header->append = string__append;
header->prepend = string__prepend;
header->charAt = string__charAt;
header->compare = string__compare;
header->str = string__str;
header->replace = string__replace;
header->count = string__count;
header->hasPrefix = string__hasPrefix;
header->hasSuffix = string__hasSuffix;
header->trim = string__trim;
header->trimLeft = string__trimLeft;
header->trimRight = string__trimRight;
struct string headerName =  string(splitStringBefore(line,":"));
if ((headerName.length>0)) {
headerName =  toLower(headerName);
line.trimLeft((struct string*)&line,headerName.length);
line.prepend((struct string*)&line,headerName.str((struct string*)&headerName));
}
header->set((struct string*)header,line.str((struct string*)&line));
long int lrh =  len(resp->headers);

{
long nLength = lrh;
if (resp->headers->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(resp->headers->data, (nLength+50)*sizeof(struct string*));
resp->headers->data = newPtr;
}
resp->headers->data[lrh] =  header;
resp->headers->length = nLength+1;
} else {
resp->headers->data[lrh] =  header;
};
};
i =  i + 1;
};
char * transferEncoding =  resp->getHeader((struct http_transport*)resp,"Transfer-Encoding");
if ((strcmp(transferEncoding,"chunked")==0)) {
resp->body->set((struct string*)resp->body,"");
while ((true==true)) {
char * chunkLen =  splitStringBefore(body,"\r\n");
if ((strcmp(chunkLen,"0")==0)) {
break;
}
long int l =  strtol(chunkLen,noCheck( 0 ),16);
l =  l;
body.trimLeft((struct string*)&body,strlen(chunkLen) + 2);
char * chunk =  memoryAlloc(l + 1);
memcpy(chunk,body.content,l);
resp->body->append((struct string*)resp->body,chunk);
body.trimLeft((struct string*)&body,l + 2);
};
}
else {
resp->body->set((struct string*)resp->body,body.str((struct string*)&body));
}
return resp;
};
char * makeRawHttpsRequest(char * host,char * message){
SSL_library_init();
SSL* ssl;
SSL_CTX* ctx =  SSL_CTX_new(SSLv23_client_method());
if ((ctx==null)) {
panic("http: cannot initialize ssl context");
}
BIO* bio =  BIO_new_ssl_connect(ctx);
BIO_get_ssl(bio,&ssl);
SSL_set_mode(ssl,4);
BIO_set_conn_hostname(bio,host);
if ((BIO_do_connect(bio)<=0)) {
panic(concatCPSTRING(concatCPSTRING("http: error connecting through ssl to '",host),"'"));
}
long int success =  BIO_write(bio,message,strlen(message));
if ((success<=0)) {
if ((BIO_should_retry(bio)==0)) {
panic("http: failed sending request");
}
}
char * buff =  memoryAlloc(1025);
struct string resp =  string("");
while ((true==true)) {
memset((void *)buff,0,1025);
long int size =  BIO_read(bio,buff,1025);
if ((size<=0)) {
break;
}
resp.append((struct string*)&resp,buff);
};
BIO_free_all(bio);
SSL_CTX_free(ctx);
return resp.str((struct string*)&resp);
};
struct http_request {
long int connfd;
array(struct string*)* headers;
long int code;
struct string* body;
struct http_url* url;
char * method;
char * path;
void(*setHeader)(struct http_transport* this,char * name,char * value);
char *(*getHeader)(struct http_transport* this,char * name);
void(*write)(struct http_transport* this,char * content);
char * request;
array(struct string)* form;
struct http_response*(*send)(struct http_request* this);
int(*parseForm)(struct http_request* this);
char *(*getFormValue)(struct http_request* this,char * name);
};
struct http_response* http_request__send(struct http_request* this){
int socketWasOpenned =  true;
int isTLS =  false;
char * host =  "";
if ((this->connfd==-1)) {
if ((this->url!=null)) {
socketWasOpenned =  false;
if ((strlen(this->path)==0)) {
this->path =  this->url->path.str((struct string*)&this->url->path);
}
if (this->url->proto.compare((struct string*)&this->url->proto,"https")) {
isTLS =  true;
if ((this->url->port.length==0)) {
this->url->port.set((struct string*)&this->url->port,"443");
}
host =  concatCPSTRING(concatCPSTRING(this->url->host.str((struct string*)&this->url->host),":"),this->url->port.str((struct string*)&this->url->port));
}
else {
if ((this->url->port.length==0)) {
this->url->port.set((struct string*)&this->url->port,"80");
}
this->connfd =  openSocket(this->url->host.str((struct string*)&this->url->host),atoi(this->url->port.str((struct string*)&this->url->port)));
}
this->setHeader((struct http_transport*)this,"host",concatCPSTRING(concatCPSTRING(this->url->host.str((struct string*)&this->url->host),":"),this->url->port.str((struct string*)&this->url->port)));
}
else {
return null;
}
}
char * method =  this->method;
if ((strlen(method)==0)) {
method =  "GET";
}
char * path =  this->path;
if ((strlen(path)==0)) {
path =  "/";
}
struct rope* message =  rope(concatCPSTRING(concatCPSTRING(concatCPSTRING(method," "),path)," HTTP/1.0\r\n"));
long int i =  0;
while ((i<len(this->headers))) {
struct string* h =  this->headers->data[i];
message =  message->add(message, rope(concatCPSTRING(h->str((struct string*)h),"\r\n")));
i =  i + 1;
};
message =  message->add(message, rope("\r\n"));
if ((this->body!=null)) {
message =  message->add(message, rope(this->body->str((struct string*)this->body)));
}
char * msg =  message->toStr((struct rope*)message);
struct string response =  string("");
if ((isTLS==true)) {
response.set((struct string*)&response,makeRawHttpsRequest(host,msg));
}
else {
if ((send(this->connfd,msg,strlen(msg),0)<=0)) {
panic("http: error sending trought socket");
}
char * buffer =  memoryAlloc(1025);
long int nDataLength =  recv(this->connfd,buffer,1024,0);
while ((nDataLength>0)) {
response.append((struct string*)&response,buffer);
if ((nDataLength<1024)) {
long int trimAmm =  1024 - nDataLength;
response.trimRight((struct string*)&response,trimAmm);
}
nDataLength =  recv(this->connfd,buffer,1024,0);
};
}
if ((socketWasOpenned==false)) {
closeSocket(this->connfd);
}
return makeRespFromBody(response);
};
int http_request__parseForm(struct http_request* this){
if ((strcmp(this->method, "POST") != 0)) {
return false;
}
char * contentType =  this->getHeader((struct http_transport*)this,"Content-Type");
if (strHasPrefix(contentType,"multipart/form-data")) {
return false;
}
if ((strcmp(contentType, "application/x-www-form-urlencoded") == 0)) {
struct string* body =  this->body;
this->form =  splitString(*body,"&");
}
return true;
};
char * http_request__getFormValue(struct http_request* this,char * name){
struct string rName =  string(name);
rName =  toLower(rName);
long int i =  0;
while ((i<len(this->form))) {
struct string f =  this->form->data[i];
if (f.hasPrefix((struct string*)&f,concatCPSTRING(rName.str((struct string*)&rName),"="))) {
f.trimLeft((struct string*)&f,rName.length + 1);
f.trim((struct string*)&f);
return f.str((struct string*)&f);
}
i =  i + 1;
};
return "";
};
struct http_request http_request(long int connfd){
struct http_request r =  {};
r.connfd = -1;
r.headers = memoryAlloc(sizeof(array(struct string*)));
            r.headers->length = 0;
            r.headers->elemSize = sizeof(struct string*);
            r.code = HTTP_OK;
r.method = "";
r.path = "";
r.form = memoryAlloc(sizeof(array(struct string)));
            r.form->length = 0;
            r.form->elemSize = sizeof(struct string);
            r.setHeader = http_transport__setHeader;
r.getHeader = http_transport__getHeader;
r.write = http_transport__write;
r.send = http_request__send;
r.parseForm = http_request__parseForm;
r.getFormValue = http_request__getFormValue;
r.connfd =  connfd;
char * reqcps =  http_receive(connfd);
struct string req =  string(reqcps);
long int i =  0;
struct string method =  string("");
while ((i<req.length)) {
char c =  req.charAt((struct string*)&req,i);
if ((c==32)) {
break;
}
char * cs =  charToString(c);
method.append((struct string*)&method,cs);
i =  i + 1;
};
r.method =  method.str((struct string*)&method);
struct string path =  string("");
i =  i + 1;
while ((i<req.length)) {
char c =  req.charAt((struct string*)&req,i);
if ((c==32)) {
break;
}
char * cs =  charToString(c);
path.append((struct string*)&path,cs);
i =  i + 1;
};
r.path =  path.str((struct string*)&path);
while ((i<req.length)) {
char c =  req.charAt((struct string*)&req,i);
if ((c==(char)10)) {
break;
}
i =  i + 1;
};
req.trimLeft((struct string*)&req,i);
array(struct string)* lines =  splitString(req,"\r\n");
int isBody =  false;
r.body = memoryAlloc(sizeof(struct string));
r.body->set = string__set;
r.body->append = string__append;
r.body->prepend = string__prepend;
r.body->charAt = string__charAt;
r.body->compare = string__compare;
r.body->str = string__str;
r.body->replace = string__replace;
r.body->count = string__count;
r.body->hasPrefix = string__hasPrefix;
r.body->hasSuffix = string__hasSuffix;
r.body->trim = string__trim;
r.body->trimLeft = string__trimLeft;
r.body->trimRight = string__trimRight;
i =  0;
while ((i<len(lines))) {
struct string l =  lines->data[i];
if ((isBody==true)) {
r.body->append((struct string*)r.body,concatCPSTRING(l.str((struct string*)&l),"\r\n"));
}
else if ((l.length==0)) {
isBody =  true;
}
else {
l.trim((struct string*)&l);
char * headerName =  splitStringBefore(l,":");
struct string headerCont =  string(l.str((struct string*)&l));
headerCont.trimLeft((struct string*)&headerCont,strlen(headerName) + 1);
headerCont.trim((struct string*)&headerCont);
r.setHeader((struct http_transport*)&r,headerName,headerCont.str((struct string*)&headerCont));
}
i =  i + 1;
};
r.request =  reqcps;
return r;
};
struct http_response makeRawRequest(char * method,struct http_url* u,__BAH_ARR_TYPE_cpstring args){
struct string proto =  u->proto;
struct string host =  u->host;
struct string path =  u->path;
struct sockaddr_in serv_addr;
long int portno =  80;
if ((u->port.length>0)) {
portno =  atoi(u->port.content);
}
struct string response =  string("");
struct string message =  string(" ");
message.prepend((struct string*)&message,method);
message.append((struct string*)&message,path.str((struct string*)&path));
struct string serialArgs =  string("?");
long int largs =  len(args);
long int max =  largs - 1;
long int i =  0;
while ((i<largs)) {
serialArgs.append((struct string*)&serialArgs,args->data[i]);
if ((i<max)) {
serialArgs.append((struct string*)&serialArgs,"&");
}
i =  i + 1;
};
if ((largs>0)) {
message.append((struct string*)&message,serialArgs.str((struct string*)&serialArgs));
}
message.append((struct string*)&message," HTTP/1.0\r\nHost: ");
if (proto.compare((struct string*)&proto,"https")) {
host.append((struct string*)&host,":443");
}
message.append((struct string*)&message,host.str((struct string*)&host));
message.append((struct string*)&message,"\r\nConnection: close\r\n\r\n");
if (proto.compare((struct string*)&proto,"https")) {
char * resp =  makeRawHttpsRequest(host.str((struct string*)&host),message.str((struct string*)&message));
response.set((struct string*)&response,resp);
}
else {
long int sockfd =  socket(2,1,0);
if ((sockfd<0)) {
panic("http: error opening socket");
}
struct hostent* server =  gethostbyname(host.content);
if ((server==null)) {
panic("http: error resolving host");
}
serv_addr.sin_port =  htons(portno);
serv_addr.sin_family =  2;
unsigned long int* ha =  server->h_addr;
struct in_addr saddr =  {};
saddr.s_addr =  *ha;
serv_addr.sin_addr =  saddr;
long int canConnect =  connect(sockfd,&serv_addr,16);
if ((canConnect<0)) {
panic("error: error connecting socket");
}
long int isSend =  send(sockfd,message.content,message.length,0);
if ((isSend<=0)) {
panic("http: error sending trought socket");
}
char * buffer =  memoryAlloc(1025);
long int nDataLength =  recv(sockfd,buffer,1024,0);
while ((nDataLength>0)) {
response.append((struct string*)&response,buffer);
if ((nDataLength<1024)) {
long int trimAmm =  1024 - nDataLength;
response.trimRight((struct string*)&response,trimAmm);
}
nDataLength =  recv(sockfd,buffer,1024,0);
};
close(sockfd);
}
struct http_response resp =  {};
resp.connfd = -1;
resp.headers = memoryAlloc(sizeof(array(struct string*)));
            resp.headers->length = 0;
            resp.headers->elemSize = sizeof(struct string*);
            resp.code = HTTP_OK;
resp.method = "";
resp.path = "";
resp.headersSent = false;
resp.setHeader = http_transport__setHeader;
resp.getHeader = http_transport__getHeader;
resp.write = http_transport__write;
resp.send = http_response__send;
resp.body = memoryAlloc(sizeof(struct string));
resp.body->set = string__set;
resp.body->append = string__append;
resp.body->prepend = string__prepend;
resp.body->charAt = string__charAt;
resp.body->compare = string__compare;
resp.body->str = string__str;
resp.body->replace = string__replace;
resp.body->count = string__count;
resp.body->hasPrefix = string__hasPrefix;
resp.body->hasSuffix = string__hasSuffix;
resp.body->trim = string__trim;
resp.body->trimLeft = string__trimLeft;
resp.body->trimRight = string__trimRight;
array(struct string)* lines =  splitString(response,"\r\n");
if ((len(lines)==0)) {
return resp;
}
i =  0;
struct string head =  lines->data[0];
while ((i<head.length)) {
char c =  head.charAt((struct string*)&head,i);
if ((c==32)) {
i =  i + 1;
break;
}
i =  i + 1;
};
struct string httpCode =  string("");
while ((i<head.length)) {
char c =  head.charAt((struct string*)&head,i);
httpCode.append((struct string*)&httpCode,charToString(c));
if ((c==32)) {
break;
}
i =  i + 1;
};
long int httpCodeInt =  stringToInt(httpCode);
resp.code =  httpCodeInt;
long int isBody =  0;
max =  len(lines) - 1;
struct string body =  string("");
i =  1;
while ((i<len(lines))) {
struct string line =  lines->data[i];
if ((isBody==1)) {
struct string s =  string(line.str((struct string*)&line));
if ((i<max)) {
s.append((struct string*)&s,"\r\n");
}
body.append((struct string*)&body,s.str((struct string*)&s));
i =  i + 1;
continue;
}
if ((i>0)) {
struct string pl =  lines->data[i-1];
if ((strlen(pl.str((struct string*)&pl))==0)) {
isBody =  1;
line.trimLeft((struct string*)&line,2);
continue;
}
}
struct string* header = memoryAlloc(sizeof(struct string));
header->set = string__set;
header->append = string__append;
header->prepend = string__prepend;
header->charAt = string__charAt;
header->compare = string__compare;
header->str = string__str;
header->replace = string__replace;
header->count = string__count;
header->hasPrefix = string__hasPrefix;
header->hasSuffix = string__hasSuffix;
header->trim = string__trim;
header->trimLeft = string__trimLeft;
header->trimRight = string__trimRight;
struct string headerName =  string(splitStringBefore(line,":"));
if ((headerName.length>0)) {
headerName =  toLower(headerName);
line.trimLeft((struct string*)&line,headerName.length);
line.prepend((struct string*)&line,headerName.str((struct string*)&headerName));
}
header->set((struct string*)header,line.str((struct string*)&line));
long int lrh =  len(resp.headers);

{
long nLength = lrh;
if (resp.headers->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(resp.headers->data, (nLength+50)*sizeof(struct string*));
resp.headers->data = newPtr;
}
resp.headers->data[lrh] =  header;
resp.headers->length = nLength+1;
} else {
resp.headers->data[lrh] =  header;
};
};
i =  i + 1;
};
char * transferEncoding =  resp.getHeader((struct http_transport*)&resp,"Transfer-Encoding");
if ((strcmp(transferEncoding,"chunked")==0)) {
resp.body->set((struct string*)resp.body,"");
while ((true==true)) {
char * chunkLen =  splitStringBefore(body,"\r\n");
if ((strcmp(chunkLen,"0")==0)) {
break;
}
long int l =  strtol(chunkLen,noCheck( 0 ),16);
l =  l;
body.trimLeft((struct string*)&body,strlen(chunkLen) + 2);
char * chunk =  memoryAlloc(l + 1);
memcpy(chunk,body.content,l);
resp.body->append((struct string*)resp.body,chunk);
body.trimLeft((struct string*)&body,l + 2);
};
}
else {
resp.body->set((struct string*)resp.body,body.str((struct string*)&body));
}
return resp;
};
struct http_response get(char * url){
array(char *)* args = memoryAlloc(sizeof(array(char *)));

args->length = 0;
args->elemSize = sizeof(char *);
struct http_response r =  makeRawRequest("GET",parseUrl(url),args);
return r;
};
struct http_response post(char * url,__BAH_ARR_TYPE_cpstring args){
struct http_response r =  makeRawRequest("POST",parseUrl(url),args);
return r;
};
long int isPortAvailable(long int port){
struct string cmdS =  intToString(port);
cmdS.prepend((struct string*)&cmdS,"netstat -antu | grep :");
struct command cmd =  command(cmdS.str((struct string*)&cmdS));
cmd.error =  false;
char * s =  cmd.run((struct command*)&cmd);
if ((strlen(s)>0)) {
return 0;
}
return 1;
};
int testHttp(){
struct http_response respTLS =  get("https://example.com");
struct http_response respTTP =  get("http://example.com");
if ((strcmp(respTLS.body->str((struct string*)respTLS.body), respTTP.body->str((struct string*)respTTP.body)) != 0)) {
return false;
}
char * ctntp =  respTLS.getHeader((struct http_transport*)&respTLS,"Content-Type");
if ((strcmp(ctntp, "text/html; charset=UTF-8") != 0)) {
return false;
}
return true;
};
int testIostream(){
char * ISTRM_SELF_PATH =  "./libs/iostream.bah";
struct fileMap fm =  {};
fm.open = fileMap__open;
fm.isValid = fileMap__isValid;
fm.close = fileMap__close;
char * fa =  fm.open((struct fileMap*)&fm,ISTRM_SELF_PATH);
fm.close((struct fileMap*)&fm);
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
fs.open((struct fileStream*)&fs,ISTRM_SELF_PATH,"r");
char * fb =  fs.readContent((struct fileStream*)&fs);
fs.close((struct fileStream*)&fs);
if ((strcmp(fa, fb) != 0)) {
return false;
}
return true;
};
#define JSON_TYPE_STRING 0
#define JSON_TYPE_INT 1
#define JSON_TYPE_FLOAT 2
#define JSON_TYPE_ARRAY 3
#define JSON_TYPE_MAP 4
struct jsonElement {
long int type;
char * key;
char * content;
array(struct jsonElement*)* children;
struct jsonElement*(*map)(struct jsonElement* this,char * key);
char *(*str)(struct jsonElement* this);
};
struct jsonElement* jsonElement__map(struct jsonElement* this,char * key){
long int l =  len(this->children);
long int i =  0;
while ((i<l)) {
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
void * newPtr = GC_REALLOC(nk->data, (nLength+50)*sizeof(char));
nk->data = newPtr;
}
nk->data[j-1] =  c;
nk->length = nLength+1;
} else {
nk->data[j-1] =  c;
};
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
struct jsonElement* parseJson(char * s){
struct jsonElement* jsonElem = memoryAlloc(sizeof(struct jsonElement));
jsonElem->children = memoryAlloc(sizeof(array(struct jsonElement*)));
            jsonElem->children->length = 0;
            jsonElem->children->elemSize = sizeof(struct jsonElement*);
            jsonElem->map = jsonElement__map;
jsonElem->str = jsonElement__str;
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
while ((i<lenS - 1)) {

{
long nLength = len(ns);
if (ns->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(ns->data, (nLength+50)*sizeof(char));
ns->data = newPtr;
}
ns->data[len(ns)] =  cpstringCharAt(s,i);
ns->length = nLength+1;
} else {
ns->data[len(ns)] =  cpstringCharAt(s,i);
};
};
i =  i + 1;
};
jsonElem->content =  arrToStr(ns);
}
else if (isNumber(fc)) {
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
jsonElem->type =  JSON_TYPE_STRING;
jsonElem->content =  s;
}
if ((jsonElem->type==JSON_TYPE_ARRAY)) {
i =  i + 1;
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
while ((i<lenS - 1)) {
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
void * newPtr = GC_REALLOC(currentElem->data, (nLength+50)*sizeof(char));
currentElem->data = newPtr;
}
currentElem->data[len(currentElem)] =  c;
currentElem->length = nLength+1;
} else {
currentElem->data[len(currentElem)] =  c;
};
};
i =  i + 1;
continue;
}
if ((c==44)) {

{
long nLength = elemIndex;
if (jsonElem->children->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(jsonElem->children->data, (nLength+50)*sizeof(struct jsonElement*));
jsonElem->children->data = newPtr;
}
jsonElem->children->data[elemIndex] =  parseJson(arrAsStr(currentElem));
jsonElem->children->length = nLength+1;
} else {
jsonElem->children->data[elemIndex] =  parseJson(arrAsStr(currentElem));
};
};
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
void * newPtr = GC_REALLOC(currentElem->data, (nLength+50)*sizeof(char));
currentElem->data = newPtr;
}
currentElem->data[len(currentElem)] =  c;
currentElem->length = nLength+1;
} else {
currentElem->data[len(currentElem)] =  c;
};
};
}
i =  i + 1;
};

{
long nLength = elemIndex;
if (jsonElem->children->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(jsonElem->children->data, (nLength+50)*sizeof(struct jsonElement*));
jsonElem->children->data = newPtr;
}
jsonElem->children->data[elemIndex] =  parseJson(arrAsStr(currentElem));
jsonElem->children->length = nLength+1;
} else {
jsonElem->children->data[elemIndex] =  parseJson(arrAsStr(currentElem));
};
};
}
else if ((jsonElem->type==JSON_TYPE_MAP)) {
i =  i + 1;
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
while ((i<lenS-1)) {
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
void * newPtr = GC_REALLOC(currentElem->data, (nLength+50)*sizeof(char));
currentElem->data = newPtr;
}
currentElem->data[len(currentElem)] =  c;
currentElem->length = nLength+1;
} else {
currentElem->data[len(currentElem)] =  c;
};
};
}
else {

{
long nLength = len(currentKey);
if (currentKey->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(currentKey->data, (nLength+50)*sizeof(char));
currentKey->data = newPtr;
}
currentKey->data[len(currentKey)] =  c;
currentKey->length = nLength+1;
} else {
currentKey->data[len(currentKey)] =  c;
};
};
}
i =  i + 1;
continue;
}
if ((c==58)) {
isVal =  1;
}
else if ((c==44)) {
struct jsonElement* elem =  parseJson(arrToStr(currentElem));
elem->key =  arrToStr(currentKey);
clear(currentElem);
clear(currentKey);
isVal =  0;

{
long nLength = elemIndex;
if (jsonElem->children->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(jsonElem->children->data, (nLength+50)*sizeof(struct jsonElement*));
jsonElem->children->data = newPtr;
}
jsonElem->children->data[elemIndex] =  elem;
jsonElem->children->length = nLength+1;
} else {
jsonElem->children->data[elemIndex] =  elem;
};
};
elemIndex =  elemIndex + 1;
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
void * newPtr = GC_REALLOC(currentElem->data, (nLength+50)*sizeof(char));
currentElem->data = newPtr;
}
currentElem->data[len(currentElem)] =  c;
currentElem->length = nLength+1;
} else {
currentElem->data[len(currentElem)] =  c;
};
};
}
else {

{
long nLength = len(currentKey);
if (currentKey->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(currentKey->data, (nLength+50)*sizeof(char));
currentKey->data = newPtr;
}
currentKey->data[len(currentKey)] =  c;
currentKey->length = nLength+1;
} else {
currentKey->data[len(currentKey)] =  c;
};
};
}
}
i =  i + 1;
};
struct jsonElement* elem =  parseJson(arrToStr(currentElem));
elem->key =  arrToStr(currentKey);

{
long nLength = elemIndex;
if (jsonElem->children->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(jsonElem->children->data, (nLength+50)*sizeof(struct jsonElement*));
jsonElem->children->data = newPtr;
}
jsonElem->children->data[elemIndex] =  elem;
jsonElem->children->length = nLength+1;
} else {
jsonElem->children->data[elemIndex] =  elem;
};
};
}
return jsonElem;
};
int testJson(){
#define JSON_DATA "\n    [\n        {\n            \"id\": 2489651045,\n            \"type\": \"user\"\n        },\n        {\n            \"id\": 2489651046,\n            \"type\": \"post\"\n        }\n    ]\n    "
struct jsonElement* json =  parseJson(JSON_DATA);
struct jsonElement* fe =  json->children->data[0];
struct jsonElement* id =  fe->map((struct jsonElement*)fe,"id");
if ((strcmp(id->content, "2489651045") != 0)) {
return false;
}
return true;
};
long int main(__BAH_ARR_TYPE_cpstring args){
long int start =  getTimeUnix();
test("string",testString);
start =  getTimeUnix();
test("markdown",testMarkdown);
start =  getTimeUnix();
test("http",testHttp);
start =  getTimeUnix();
test("iostream",testIostream);
start =  getTimeUnix();
test("json",testJson);
test("json",testJson);
return 0;
};
