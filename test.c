
#include <gc.h>
#define noCheck(v) v
#define array(type)	struct{	type *data; long int length; long int elemSize; }
int main(int argc, char ** argv) {
GC_INIT();
array(char*) * args = GC_MALLOC(sizeof(array(char*)));
args->data = GC_MALLOC(sizeof(char*)*argc);
memcpy(args->data, argv, sizeof(char*)*argc);
args->elemSize = sizeof(char*);
args->length = argc;
__BAH__main(args);
};
#define main(v) __BAH__main(v)
#include <signal.h>
#include <string.h>
#include <gc.h>
#include <sys/mman.h>
#define SIZE_OF_INT 8
#define SIZE_OF_CHAR 1
#define SIZE_OF_INT32 4
#define SIZE_OF_FLOAT32 4
#define SIZE_OF_FLOAT 8
long int len(void * a){
long int i =  0;
;
noCheck( array ( void* ) *arr = a );
noCheck( i = arr -> length );
return i;
};
void * memoryAlloc(long int s){
void * p =  GC_MALLOC(s);
;
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
;
long int lenB =  0;
;
long int realSizeA =  0;
;
long int realSizeB =  0;
;
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
;
noCheck( memcpy ( buff , arrA -> data , realSizeA ) );
noCheck( memcpy ( buff + lenA , arrB -> data , realSizeB ) );
noCheck( arrA -> length = lenA + lenB );
noCheck( arrA -> data = buff );
};
void copy(void * a,void * b){
noCheck( array ( void* ) *arrA = a );
noCheck( array ( void* ) *arrB = b );
long int lenB =  0;
;
long int realSizeB =  0;
;
noCheck( lenB = len ( arrB ) );
noCheck( realSizeB = lenB * arrB -> elemSize );
noCheck( arrA -> data = memoryAlloc ( realSizeB ) );
noCheck( memcpy ( arrA -> data , arrB -> data , realSizeB ) );
noCheck( arrA -> length = arrB -> length );
};
void * memoryRealloc(void * p,long int s){
void * np =  GC_REALLOC(p,s);
;
return np;
};
#define PROT_READ 1
#define PROT_WRITE 2
#define MAP_SHARED 1
#define MAP_ANONYMOUS 2
void * sharedMemory(long int size){
if ((size==0)) {
size =  4096;
;
}
void * r =  mmap(0,size,PROT_READ + PROT_WRITE,MAP_SHARED + MAP_ANONYMOUS,-1,0);
;
return r;
};
char * concatCPSTRING(char * a,char * b){
long int lenA =  strlen(a);
;
long int lenB =  strlen(b);
;
char * r =  memoryAlloc(lenA + lenB + 1);
;
strncpy(r,a,lenA);
strcat(r,b);
return r;
};
char * __STR(char * a){
long int lenA =  strlen(a);
;
char * r =  memoryAlloc(lenA + 1);
;
strncpy(r,a,lenA);
return r;
};
#define null (void *)0
#define true (int)1
#define false (int)0
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <math.h>
char * charToString(char c){
char * s =  memoryAlloc(2);
;
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
;
this->content =  (char *)memoryAlloc(this->length + 1);
;
strcpy(this->content,s);
};
void string__append(struct string* this,char * s){
this->length =  this->length + strlen(s);
;
char * tmpS =  (char *)memoryRealloc((void *)this->content,this->length);
;
if (((long int)tmpS==0)) {
tmpS =  (char *)memoryAlloc(this->length);
;
strncpy(tmpS,this->content,this->length);
}
strcat(tmpS,s);
this->content =  tmpS;
;
};
void string__prepend(struct string* this,char * s){
char * tmpS =  memoryAlloc(this->length + 1);
;
strcpy(tmpS,this->content);
this->length =  this->length + strlen(s);
;
this->content =  (char *)memoryAlloc(this->length + 1);
;
strcpy(this->content,s);
strcat(this->content,tmpS);
};
char string__charAt(struct string* this,long int i){
char c =  (char)0;
;
if ((i<this->length)) {
noCheck( c = this -> content [ i ] );
return c;
}
return c;
};
long int string__compare(struct string* this,char * s){
long int r =  strcmp(this->content,s);
;
if ((r==0)) {
return 1;
}
return 0;
};
char * string__str(struct string* this){
char * r =  this->content;
;
return r;
};
void string__replace(struct string* this,char * nd,char * rl){
struct string needle =  {};
;
needle.set = string__set;
needle.append = string__append;
needle.prepend = string__prepend;
needle.charAt = string__charAt;
needle.compare = string__compare;
needle.str = string__str;
needle.set(&needle,nd);
struct string repl =  {};
;
repl.set = string__set;
repl.append = string__append;
repl.prepend = string__prepend;
repl.charAt = string__charAt;
repl.compare = string__compare;
repl.str = string__str;
repl.set(&repl,rl);
long int i =  0;
;
long int si =  0;
;
array(char)* replcBuff = memoryAlloc(sizeof(array(char)));;

replcBuff->length = 0;
replcBuff->elemSize = sizeof(char);
array(char)* buff = memoryAlloc(sizeof(array(char)));;

buff->length = 0;
buff->elemSize = sizeof(char);
while ((i<this->length)) {
char c =  this->charAt(this,i);
;
char rc =  needle.charAt(&needle,si);
;
if ((c==rc)) {
si =  si + 1;
;

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
;
}
else {
if ((len(replcBuff)>0)) {
si =  0;
;
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
;
}
if ((si==needle.length)) {
clear(replcBuff);
long int ii =  0;
;
while ((ii<repl.length)) {
long int a =  ii;
;

{
long nLength = len(buff);
if (buff->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(buff->data, (nLength+50)*sizeof(char));
buff->data = newPtr;
}
buff->data[len(buff)] =  repl.charAt(&repl,ii);

buff->length = nLength+1;
} else {
buff->data[len(buff)] =  repl.charAt(&repl,ii);

};
};
;
ii =  ii + 1;
;
};
si =  0;
;
}
i =  i + 1;
;
};
char * r =  "";
;
noCheck( r = buff -> data );
if ((len(replcBuff)>0)) {
char * replbuffStr;
noCheck( replbuffStr = replcBuff -> data );
r =  concatCPSTRING(r,replbuffStr);
;
}
this->set(this,r);
};
long int string__count(struct string* this,char * need){
long int i =  0;
;
long int count =  0;
;
struct string needle =  {};
;
needle.set = string__set;
needle.append = string__append;
needle.prepend = string__prepend;
needle.charAt = string__charAt;
needle.compare = string__compare;
needle.str = string__str;
needle.replace = string__replace;
needle.set(&needle,need);
long int countIndex =  0;
;
while ((i<this->length)) {
char c =  this->charAt(this,i);
;
char sc =  needle.charAt(&needle,countIndex);
;
if ((c==sc)) {
countIndex =  countIndex + 1;
;
}
else {
countIndex =  0;
;
}
if ((countIndex==needle.length)) {
count =  count + 1;
;
countIndex =  0;
;
}
i =  i + 1;
;
};
return count;
};
long int string__hasPrefix(struct string* this,char * need){
long int i =  0;
;
struct string needle =  {};
;
needle.set = string__set;
needle.append = string__append;
needle.prepend = string__prepend;
needle.charAt = string__charAt;
needle.compare = string__compare;
needle.str = string__str;
needle.replace = string__replace;
needle.count = string__count;
needle.set(&needle,need);
if ((this->length<needle.length)) {
return 0;
}
while ((i<needle.length)) {
char c =  this->charAt(this,i);
;
char sc =  needle.charAt(&needle,i);
;
if ((c!=sc)) {
return 0;
}
i =  i + 1;
;
};
return 1;
};
long int string__hasSuffix(struct string* this,char * need){
struct string needle =  {};
;
needle.set = string__set;
needle.append = string__append;
needle.prepend = string__prepend;
needle.charAt = string__charAt;
needle.compare = string__compare;
needle.str = string__str;
needle.replace = string__replace;
needle.count = string__count;
needle.hasPrefix = string__hasPrefix;
needle.set(&needle,need);
if ((this->length<needle.length)) {
return 0;
}
long int i =  this->length - needle.length;
;
long int needleIndex =  0;
;
while ((i<this->length)) {
char c =  this->charAt(this,i);
;
char sc =  needle.charAt(&needle,needleIndex);
;
if ((c!=sc)) {
return 0;
}
needleIndex =  needleIndex + 1;
;
i =  i + 1;
;
};
return 1;
};
void string__trim(struct string* this){
if ((this->length==0)) {
return ;
}
char fc =  this->charAt(this,0);
;
if ((isSpace(fc)==0)) {
return ;
}
long int i =  0;
;
while ((i<this->length)) {
char c =  this->charAt(this,i);
;
if ((isSpace(c)==0)) {
break;
}
i =  i + 1;
;
};
if ((i>0)) {
this->length =  this->length - i;
;
char * tmpS =  memoryAlloc(this->length + 1);
;
memcpy(tmpS,noCheck( this->content + i ),this->length + 1);
this->content =  tmpS;
;
}
};
void string__trimLeft(struct string* this,long int s){
long int nSize =  this->length - s;
;
void * tmpS =  memoryAlloc(nSize);
;
memcpy(tmpS,noCheck( this->content + s ),nSize);
this->content =  tmpS;
;
this->length =  nSize;
;
};
void string__trimRight(struct string* this,long int s){
long int nSize =  this->length - s;
;
void * tmpS =  memoryAlloc(nSize);
;
memcpy(tmpS,this->content,nSize);
this->content =  tmpS;
;
this->length =  nSize;
;
};
struct string string(char * s){
struct string a =  {};
;
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
;
a.length =  0;
;
a.set(&a,s);
return a;
};
char * arrToStr(array(char)* arr){
long int strLen =  len(arr);
;
char * str =  memoryAlloc(strLen + 1);
;
noCheck( memcpy ( str , arr -> data , strLen ) );
return str;
};
array(char)* strToArr(char * str){
long int strLen =  strlen(str);
;
array(char)* arr = memoryAlloc(sizeof(array(char)));;

arr->length = 0;
arr->elemSize = sizeof(char);
noCheck( arr -> data = memoryAlloc ( strLen + 1 ) );
noCheck( memcpy ( arr -> data , str , strLen ) );
noCheck( arr -> length = strLen );
return arr;
};
char * arrAsStr(array(char)* arr){
char * r =  "";
;
noCheck( r = arr -> data );
return r;
};
struct string intToString(long int i){
char * buff =  memoryAlloc(65);
;
void * ptri =  (void *)i;
;
sprintf(buff,"%d",ptri);
struct string r =  string(buff);
;
return r;
};
char * intToStr(long int i){
char * buff =  memoryAlloc(65);
;
sprintf(buff,"%ld",(void *)i);
return buff;
};
long int stringToInt(struct string s){
long int i =  atoi(s.content);
;
return i;
};
array(struct string)* splitString(struct string s,char * sp){
struct string sep =  string(sp);
;
array(struct string)* res = memoryAlloc(sizeof(array(struct string)));;

res->length = 0;
res->elemSize = sizeof(struct string);
struct string sepBuffer =  string("");
;
long int sepIndex =  0;
;
long int i =  0;
;
struct string replcBuff =  string("");
;
array(char)* tmpString = memoryAlloc(sizeof(array(char)));;

tmpString->length = 0;
tmpString->elemSize = sizeof(char);
while ((i<s.length)) {
char c =  s.charAt(&s,i);
;
char sepc =  sep.charAt(&sep,sepIndex);
;
if ((c==sepc)) {
sepIndex =  sepIndex + 1;
;
replcBuff.append(&replcBuff,charToString(c));
}
else {
if ((sepIndex>0)) {
sepIndex =  0;
;
replcBuff.append(&replcBuff,charToString(c));
long int ii =  0;
;
while ((ii<replcBuff.length)) {

{
long nLength = len(tmpString);
if (tmpString->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(tmpString->data, (nLength+50)*sizeof(char));
tmpString->data = newPtr;
}
tmpString->data[len(tmpString)] =  replcBuff.charAt(&replcBuff,ii);

tmpString->length = nLength+1;
} else {
tmpString->data[len(tmpString)] =  replcBuff.charAt(&replcBuff,ii);

};
};
;
ii =  ii + 1;
;
};
replcBuff.set(&replcBuff,"");
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
;
}
}
if ((sepIndex==sep.length)) {
replcBuff.set(&replcBuff,"");
struct string* elem = memoryAlloc(sizeof(struct string));
;
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
elem->set(elem,arrToStr(tmpString));
long int lenRes =  len(res);
;

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
;
clear(tmpString);
sepIndex =  0;
;
}
i =  i + 1;
;
};
if ((replcBuff.length>0)) {
long int ii =  0;
;
while ((ii<replcBuff.length)) {

{
long nLength = len(tmpString);
if (tmpString->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(tmpString->data, (nLength+50)*sizeof(char));
tmpString->data = newPtr;
}
tmpString->data[len(tmpString)] =  replcBuff.charAt(&replcBuff,ii);

tmpString->length = nLength+1;
} else {
tmpString->data[len(tmpString)] =  replcBuff.charAt(&replcBuff,ii);

};
};
;
ii =  ii + 1;
;
};
}
if ((len(tmpString)>0)) {
struct string* elem = memoryAlloc(sizeof(struct string));
;
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
elem->set(elem,arrToStr(tmpString));
long int lenRes =  len(res);
;

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
;
}
return res;
};
struct string joinString(array(struct string)* a,char * sep){
long int i =  0;
;
struct string s =  string("");
;
long int max =  len(a) - 1;
;
while ((i<len(a))) {
struct string e =  a->data[i];
;
if ((e.length==0)) {
i =  i + 1;
;
continue;
}
struct string tmpS =  string(e.str(&e));
;
if ((i!=max)) {
tmpS.append(&tmpS,sep);
}
s.append(&s,tmpS.str(&tmpS));
i =  i + 1;
;
};
return s;
};
char * splitStringBefore(struct string s,char * sp){
struct string sep =  string(sp);
;
if ((sep.length>=s.length)) {
return "";
}
long int sepIndex =  0;
;
long int foundIndex =  0;
;
long int i =  0;
;
while ((i<s.length)) {
char c =  s.charAt(&s,i);
;
char sc =  sep.charAt(&sep,sepIndex);
;
if ((c==sc)) {
if ((sepIndex==0)) {
foundIndex =  i - 1;
;
}
sepIndex =  sepIndex + 1;
;
if ((sepIndex==sep.length)) {
long int max =  s.length - foundIndex - 1;
;
s.trimRight(&s,max);
return s.str(&s);
}
}
else {
foundIndex =  0;
;
sepIndex =  0;
;
}
i =  i + 1;
;
};
return "";
};
struct string toLower(struct string s){
array(char)* ns = memoryAlloc(sizeof(array(char)));;

ns->length = 0;
ns->elemSize = sizeof(char);
long int i =  0;
;
while ((i<s.length)) {
char c =  s.charAt(&s,i);
;
if (isUpper(c)) {
c =  c + (char)32;
;
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
;
i =  i + 1;
;
};
return string(arrToStr(ns));
};
char * stdinput(long int len){
char * buff =  memoryAlloc(len);
;
fgets(buff,len,noCheck( stdin ));
return buff;
};
void print(char * s){
write(1,s,strlen(s));
};
void println(char * s){
write(1,s,strlen(s));
write(1,"\n",1);
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
long int(*getSize)(struct fileStream* this);
char *(*readContent)(struct fileStream* this);
void(*rewind)(struct fileStream* this);
char(*getChar)(struct fileStream* this);
void(*createFile)(struct fileStream* this,char * path);
long int(*writeFile)(struct fileStream* this,char * content);
};
long int fileStream__isValid(struct fileStream* this){
if ((this->handle==null)) {
return 0;
}
return 1;
};
void fileStream__open(struct fileStream* this,char * path,char * mode){
this->handle =  fopen(path,mode);
;
};
void fileStream__close(struct fileStream* this){
if ((this->isValid(this)==0)) {
return ;
}
fclose(this->handle);
};
long int fileStream__getSize(struct fileStream* this){
if ((this->isValid(this)==0)) {
return -1;
}
fseek(this->handle,0,2);
long int size =  ftell(this->handle);
;
fclose(this->handle);
return size;
};
char * fileStream__readContent(struct fileStream* this){
if ((this->isValid(this)==0)) {
return "invalid";
}
fseek(this->handle,0,2);
long int size =  ftell(this->handle);
;
rewind(this->handle);
char c =  getc(this->handle);
;
long int i =  0;
;
array(char)* s = memoryAlloc(sizeof(array(char)));;

s->length = 0;
s->elemSize = sizeof(char);
while ((c!=(char)noCheck( EOF ))) {

{
long nLength = len(s);
if (s->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(s->data, (nLength+50)*sizeof(char));
s->data = newPtr;
}
s->data[len(s)] =  c;

s->length = nLength+1;
} else {
s->data[len(s)] =  c;

};
};
;
i =  i + 1;
;
c =  getc(this->handle);
;
};

{
long nLength = len(s);
if (s->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(s->data, (nLength+50)*sizeof(char));
s->data = newPtr;
}
s->data[len(s)] =  (char)0;

s->length = nLength+1;
} else {
s->data[len(s)] =  (char)0;

};
};
;
long int ls =  len(s);
;
char * r =  "";
;
noCheck( r = s -> data );
return r;
};
void fileStream__rewind(struct fileStream* this){
rewind(this->handle);
};
char fileStream__getChar(struct fileStream* this){
char c =  getc(this->handle);
;
return c;
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
struct fileMap {
long int handle;
char *(*open)(struct fileMap* this,char * fileName);
long int(*isValid)(struct fileMap* this);
void(*close)(struct fileMap* this);
};
char * fileMap__open(struct fileMap* this,char * fileName){
this->handle =  open(fileName,noCheck( O_RDWR ),noCheck( S_IRUSR | S_IWUSR ));
;
struct stat sb =  {};
;
fstat(this->handle,&sb);
char * file =  mmap(0,sb.st_size,noCheck( PROT_READ | PROT_WRITE ),noCheck( MAP_SHARED ),this->handle,0);
;
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
array(char *)* listFiles(char * dir){
array(char *)* files = memoryAlloc(sizeof(array(char *)));;

files->length = 0;
files->elemSize = sizeof(char *);
DIR* d =  opendir(dir);
;
struct dirent* file =  readdir(d);
;
while ((file!=null)) {
long int lf =  len(files);
;
if ((strcmp(file->d_name,".")==0)) {
file =  readdir(d);
;
continue;
}
if ((strcmp(file->d_name,"..")==0)) {
file =  readdir(d);
;
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
;
file =  readdir(d);
;
};
closedir(d);
return files;
};
long int fileExists(char * path){
long int is =  access(path,0);
;
if ((is==0)) {
return 1;
}
return 0;
};
void main(){
struct string a =  string("je suis une tutu");
;
array(struct string)* arr = memoryAlloc(sizeof(array(struct string)));;

arr->length = 0;
arr->elemSize = sizeof(struct string);
long int i =  0;
;
while ((i<len(arr))) {
struct string s =  arr->data[i];
;
println(s.str(&s));
i =  i + 1;
;
};
};
