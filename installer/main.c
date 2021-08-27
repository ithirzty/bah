//COMPILE WITH: 'gcc ././main.c -w  -lgc -DPARALLEL_MARK -lm'

#include <stdio.h>
#include <execinfo.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <gc.h>

#define noCheck(v) v
#define array(type)	struct{	type *data; long int length; long int elemSize; }

void __CRASH_BAH_HANDLE(int sig) {
void *array[10];
size_t size;
size = backtrace(array, 10);
char * sigStr = "unknown";
if (sig == 11) {
    sigStr = "Seg fault";
};
fprintf(stderr, "Program crashed, received signal %s:\n", sigStr);
backtrace_symbols_fd(array, size, STDERR_FILENO);
exit(1);
}


int main(int argc, char ** argv) {
GC_INIT();
array(char*) * args = GC_MALLOC(sizeof(array(char*)));
args->data = GC_MALLOC(sizeof(char*)*argc);
memcpy(args->data, argv, sizeof(char*)*argc);
args->elemSize = sizeof(char*);
args->length = argc;
signal(SIGSEGV, __CRASH_BAH_HANDLE);
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
typedef array(char)* __BAH_ARR_TYPE_char;
char * arrToStr(__BAH_ARR_TYPE_char arr){
long int strLen =  len(arr);
;
char * str =  memoryAlloc(strLen + 1);
;
noCheck( memcpy ( str , arr -> data , strLen ) );
return str;
};
__BAH_ARR_TYPE_char strToArr(char * str){
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
char * arrAsStr(__BAH_ARR_TYPE_char arr){
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
typedef array(struct string)* __BAH_ARR_TYPE_string;
__BAH_ARR_TYPE_string splitString(struct string s,char * sp){
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
struct string joinString(__BAH_ARR_TYPE_string a,char * sep){
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
typedef array(char *)* __BAH_ARR_TYPE_cpstring;
__BAH_ARR_TYPE_cpstring listFiles(char * dir){
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
;
f->name =  name;
;
f->help =  help;
;
f->type =  FLAG_TYPE_CPSTRING;
;
long int lf =  len(this->flags);
;

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
;
};
void flags__addBool(struct flags* this,char * name,char * help){
struct flag* f = memoryAlloc(sizeof(struct flag));
;
f->name =  name;
;
f->help =  help;
;
f->type =  FLAG_TYPE_BOOL;
;
long int lf =  len(this->flags);
;

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
;
};
void flags__addInt(struct flags* this,char * name,char * help){
struct flag* f = memoryAlloc(sizeof(struct flag));
;
f->name =  name;
;
f->help =  help;
;
f->type =  FLAG_TYPE_INT;
;
long int lf =  len(this->flags);
;

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
;
};
void flags__addFloat(struct flags* this,char * name,char * help){
struct flag* f = memoryAlloc(sizeof(struct flag));
;
f->name =  name;
;
f->help =  help;
;
f->type =  FLAG_TYPE_FLOAT;
;
long int lf =  len(this->flags);
;

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
;
};
void flags__invalidate(struct flags* this){
print("Usage of ");
print(this->args->data[0]);
println(":");
long int i =  0;
;
while ((i<len(this->flags))) {
struct flag* flag =  this->flags->data[i];
;
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
;
};
exit(1);
};
struct flag* flags__getFlag(struct flags* this,struct string name){
long int i =  0;
;
while ((i<len(this->flags))) {
struct flag* flag =  this->flags->data[i];
;
if (name.compare(&name,flag->name)) {
return flag;
}
i =  i + 1;
;
};
struct flag* z = memoryAlloc(sizeof(struct flag));
;
z->isSet =  0;
;
return z;
};
char * flags__get(struct flags* this,char * name){
struct flag* flag =  this->getFlag(this,string(name));
;
char * ctn =  flag->content;
;
return ctn;
};
long int flags__getInt(struct flags* this,char * name){
struct flag* flag =  this->getFlag(this,string(name));
;
if ((flag->type!=FLAG_TYPE_INT)) {
char * error =  concatCPSTRING(concatCPSTRING("Flag '",flag->name),"' is not int.");
;
panic(error);
}
long int ctn =  flag->cont_int;
;
return ctn;
};
double flags__getFloat(struct flags* this,char * name){
struct flag* flag =  this->getFlag(this,string(name));
;
if ((flag->type!=FLAG_TYPE_FLOAT)) {
char * error =  concatCPSTRING(concatCPSTRING("Flag '",flag->name),"' is not float.");
;
panic(error);
}
double ctn =  flag->cont_float;
;
return ctn;
};
long int flags__isSet(struct flags* this,char * name){
struct flag* flag =  this->getFlag(this,string(name));
;
long int ctn =  flag->isSet;
;
return ctn;
};
void flags__parse(struct flags* this,__BAH_ARR_TYPE_cpstring args){
struct flag* currentFlag;
int isVal =  false;
;
this->args =  args;
;
long int i =  1;
;
while ((i<len(args))) {
struct string argName =  string(args->data[i]);
;
if ((isVal==true)) {
currentFlag->content =  argName.str(&argName);
;
if ((currentFlag->type==FLAG_TYPE_INT)) {
currentFlag->cont_int =  atoi(argName.str(&argName));
;
}
else if ((currentFlag->type==FLAG_TYPE_FLOAT)) {
currentFlag->cont_float =  strtod(argName.str(&argName),0);
;
}
isVal =  false;
;
}
else {
if ((argName.charAt(&argName,0)!=45)) {
i =  i + 1;
;
continue;
}
argName.trimLeft(&argName,1);
if (argName.compare(&argName,"help")) {
this->invalidate(this);
}
else if (argName.compare(&argName,"h")) {
this->invalidate(this);
}
currentFlag =  this->getFlag(this,argName);
;
if ((currentFlag==null)) {
this->invalidate(this);
}
currentFlag->isSet =  1;
;
if ((currentFlag->type!=FLAG_TYPE_BOOL)) {
isVal =  true;
;
}
}
i =  i + 1;
;
};
if ((isVal==true)) {
if ((currentFlag->type!=FLAG_TYPE_BOOL)) {
this->invalidate(this);
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
;
};
char * time__format(struct time* this,char * a){
long int lt =  localtime(&this->timestamp);
;
char * date =  memoryAlloc(1024);
;
strftime(date,1024,a,lt);
return date;
};
long int time__since(struct time* this){
long int nt =  time(0);
;
long int r =  nt - this->timestamp;
;
return r;
};
long int getTimeUnix(){
struct timespec ts =  {};
;
timespec_get(&ts,noCheck( TIME_UTC ));
long int s =  ts.tv_sec * 1000000000 + ts.tv_nsec;
;
return s;
};
long int RAND_SEEDED =  0;
;
void seedRandom(long int i){
srand(i);
RAND_SEEDED =  1;
;
};
long int randomInRange(long int min,long int max){
if ((RAND_SEEDED==0)) {
srand(time(0));
RAND_SEEDED =  1;
;
}
long int range =  max - min;
;
long int i =  rand() % range + 1;
;
i =  i + min;
;
return i;
};
long int cryptoRand(){
struct fileStream fs =  {};
;
fs.isValid = fileStream__isValid;
fs.open = fileStream__open;
fs.close = fileStream__close;
fs.getSize = fileStream__getSize;
fs.readContent = fileStream__readContent;
fs.rewind = fileStream__rewind;
fs.getChar = fileStream__getChar;
fs.createFile = fileStream__createFile;
fs.writeFile = fileStream__writeFile;
fs.open(&fs,"/dev/urandom","r");
char c =  fs.getChar(&fs);
;
fs.close(&fs);
long int i =  (long int)c;
;
return i;
};
struct command {
char * command;
char *(*run)(struct command* this);
};
char * command__run(struct command* this){
FILE* handle =  popen(this->command,"r");
;
if ((handle==null)) {
return "";
}
char * buff =  memoryAlloc(1025);
;
struct string res =  string("");
;
long int more =  1;
;
while ((more==1)) {
more =  fgets(buff,1024,handle);
;
res.append(&res,buff);
};
pclose(handle);
return res.str(&res);
};
struct command command(char * s){
struct command cmd =  {};
;
cmd.run = command__run;
cmd.command =  s;
;
return cmd;
};
long int exec(char * s,__BAH_ARR_TYPE_cpstring args){
long int r;
array(char *)* nArgs = memoryAlloc(sizeof(array(char *)));;

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
;
long int i =  0;
;
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
;
i =  i + 1;
;
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
;
noCheck( r = execvp ( s , nArgs -> data ) );
return r;
};
#define BAH_DIR "/opt/bah/"
struct string SOURCE;
char * OUTPUT =  "\n#include <stdio.h>\n#include <execinfo.h>\n#include <signal.h>\n#include <stdlib.h>\n#include <unistd.h>\n#include <gc.h>\n\n#define noCheck(v) v\n#define array(type)	\
struct{	\
type *data; \
long int length; \
long int elemSize; \
}\n\nvoid __CRASH_BAH_HANDLE(int sig) {\nvoid *array[10];\nsize_t size;\nsize = backtrace(array, 10);\nchar * sigStr = \"unknown\";\nif (sig == 11) {\n    sigStr = \"Seg fault\";\n};\nfprintf(stderr, \"Program crashed, received signal %s:\\n\", sigStr);\nbacktrace_symbols_fd(array, size, STDERR_FILENO);\nexit(1);\n}\n\n\nint main(int argc, char ** argv) {\nGC_INIT();\narray(char*) * args = GC_MALLOC(sizeof(array(char*)));\nargs->data = GC_MALLOC(sizeof(char*)*argc);\nmemcpy(args->data, argv, sizeof(char*)*argc);\nargs->elemSize = sizeof(char*);\nargs->length = argc;\nsignal(SIGSEGV, __CRASH_BAH_HANDLE);\n__BAH__main(args);\n};\n#define main(v) __BAH__main(v)\n";
;
char * NEXT_LINE =  "";
;
struct variable {
char * name;
char * type;
int isConst;
int isArray;
};
struct structMemb {
char * name;
char * type;
int isConst;
int isArray;
char * def;
int isFn;
char * from;
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
};
struct compilerStateTag compilerState;
struct cStruct* currentCStruct;
long int threadCount =  0;
;
struct func* currentFn;
long int totalLines =  0;
;
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
tokenType type;
long int pos;
long int line;
char * bahType;
int isValue;
int isFunc;
};
int inArray(char needle,__BAH_ARR_TYPE_char arr){
long int i =  0;
;
while ((i<len(arr))) {
if ((needle==arr->data[i])) {
return true;
}
i =  i + 1;
;
};
return false;
};
int inArrayStr(char * needle,__BAH_ARR_TYPE_cpstring arr){
long int i =  0;
;
while ((i<len(arr))) {
if ((strcmp(needle, arr->data[i]) == 0)) {
return true;
}
i =  i + 1;
;
};
return false;
};
struct Tok makeToken(long int pos,long int lineNb,__BAH_ARR_TYPE_char cont,tokenType type){
struct Tok t =  {};
;
t.cont = "";
t.type = TOKEN_NO_TYPE;
t.pos = 0;
t.line = 1;
t.bahType = "";
t.isValue = false;
t.isFunc = false;
t.cont =  arrToStr(cont);
;
clear(cont);
t.pos =  pos;
;
t.line =  lineNb;
;
t.type =  type;
;
if ((type==TOKEN_TYPE_INT)) {
t.isValue =  true;
;
}
else if ((type==TOKEN_TYPE_STR)) {
t.isValue =  true;
;
}
else if ((type==TOKEN_TYPE_FLOAT)) {
t.isValue =  true;
;
}
else if ((type==TOKEN_TYPE_VAR)) {
t.isValue =  true;
;
}
if ((type==TOKEN_TYPE_BOOL)) {
t.isValue =  true;
;
}
else if ((type==TOKEN_TYPE_CHAR)) {
t.isValue =  true;
;
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
;
char * posStr =  intToStr(pos);
;
println(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING("\e[1;31m[LEXER-ERROR]\e[0m ",compilerState.currentFile),":"),lineStr),":"),posStr),"\n\e[0m\n"),msg));
exit(1);
};
typedef array(struct Tok)* __BAH_ARR_TYPE_Tok;
__BAH_ARR_TYPE_Tok lexer(char * s){
array(struct Tok)* tokens = memoryAlloc(sizeof(array(struct Tok)));;

tokens->length = 0;
tokens->elemSize = sizeof(struct Tok);
struct string code =  string(s);
;
SOURCE =  code;
;
array(char)* memory = memoryAlloc(sizeof(array(char)));;

memory->length = 0;
memory->elemSize = sizeof(char);
long int lineNb =  1;
;
array(char)* enclavers = memoryAlloc(sizeof(array(char)));;

enclavers->length = 6;
enclavers->elemSize = sizeof(char);
enclavers->data = memoryAlloc(sizeof(char) * 50);enclavers->data[0] = 40;
enclavers->data[1] = 41;
enclavers->data[2] = 123;
enclavers->data[3] = 125;
enclavers->data[4] = 91;
enclavers->data[5] = 93;
array(char)* syntaxes = memoryAlloc(sizeof(array(char)));;

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
array(char *)* keywords = memoryAlloc(sizeof(array(char *)));;

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
array(char)* varChars = memoryAlloc(sizeof(array(char)));;

varChars->length = 1;
varChars->elemSize = sizeof(char);
varChars->data = memoryAlloc(sizeof(char) * 50);varChars->data[0] = 95;
array(char)* seps = memoryAlloc(sizeof(array(char)));;

seps->length = 1;
seps->elemSize = sizeof(char);
seps->data = memoryAlloc(sizeof(char) * 50);seps->data[0] = 46;
long int i =  0;
;
while ((i<code.length)) {
char c =  code.charAt(&code,i);
;
long int nci =  i + 1;
;
char nc =  (char)0;
;
if ((nci<code.length)) {
nc =  code.charAt(&code,i + 1);
;
}
if ((c==47)) {
nc =  code.charAt(&code,i + 1);
;
if ((nc==47)) {
while ((i<code.length)) {
c =  code.charAt(&code,i);
;
if ((c==(char)10)) {
break;
}
i =  i + 1;
;
};
long int max =  code.length - 1;
;
if ((i>=max)) {
break;
}
}
}
if ((c==(char)10)) {
lineNb =  lineNb + 1;
;
}
if ((c==(char)34)) {
long int pos =  i;
;

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
;
i =  i + 1;
;
while ((i<code.length)) {
c =  code.charAt(&code,i);
;
char pc =  code.charAt(&code,i - 1);
;
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
;
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
;
c =  110;
;
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
;
i =  i + 1;
;
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
;
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
;
long int pos =  i;
;
i =  i + 1;
;
tokenType currentType =  TOKEN_TYPE_INT;
;
while ((i<code.length)) {
c =  code.charAt(&code,i);
;
if ((c==(char)46)) {
currentType =  TOKEN_TYPE_FLOAT;
;
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
;
i =  i + 1;
;
};
i =  i - 1;
;

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
;
}
else if ((c==(char)39)) {
i =  i + 1;
;
char n =  code.charAt(&code,i);
;
char * toInt =  intToStr((long int)nc);
;
memory =  strToArr(toInt);
;
i =  i + 1;
;
c =  code.charAt(&code,i);
;
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
;
}
else if ((c==(char)35)) {
long int pos =  i;
;

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
;
i =  i + 1;
;
while ((i<code.length)) {
c =  code.charAt(&code,i);
;
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
;
i =  i + 1;
;
};
i =  i - 1;
;
char * memstr =  arrAsStr(memory);
;

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
;
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
;

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
;
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
;
long int pos =  i;
;
i =  i + 1;
;
char fc =  c;
;
while ((i<code.length)) {
c =  code.charAt(&code,i);
;
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
;
i =  i + 1;
;
};
i =  i - 1;
;

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
;
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
;

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
;
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
;
long int pos =  i;
;
i =  i + 1;
;
while ((i<code.length)) {
c =  code.charAt(&code,i);
;
if ((isAlphaNumeric(c)==0)) {
if ((inArray(c,varChars)==false)) {
if ((c==62)) {
char lc =  memory->data[len(memory)-1];
;
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
;
i =  i - 1;
;
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
;
i =  i + 1;
;
};
i =  i - 1;
;
tokenType currentType =  TOKEN_TYPE_VAR;
;
char * memstr =  arrAsStr(memory);
;
if (inArrayStr(memstr,keywords)) {
currentType =  TOKEN_TYPE_KEYWORD;
;
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
;
}
i =  i + 1;
;
};
totalLines =  totalLines + lineNb - 1;
;
return tokens;
};
int hasStructSep(struct string n){
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
struct string res =  string(splitStringBefore(n,"."));
;
return res;
}
if (n.count(&n,"->")) {
struct string res =  string(splitStringBefore(n,"->"));
;
return res;
}
return string("");
};
struct string splitStructSepAfter(struct string n){
long int i =  n.length;
;
while ((i>0)) {
char c =  n.charAt(&n,i);
;
if ((c==46)) {
break;
}
else if ((c==62)) {
char pc =  n.charAt(&n,i-1);
;
if ((pc==45)) {
break;
}
}
i =  i - 1;
;
};
i =  i + 1;
;
n.trimLeft(&n,i);
return n;
};
struct cStruct* searchStruct(char * name,struct Elems* elems){
struct string n =  string(name);
;
n.replace(&n,"&","");
n.replace(&n,"*","");
name =  n.content;
;
long int i =  0;
;
while ((i<len(elems->structs))) {
struct cStruct* s =  elems->structs->data[i];
;
if ((strcmp(s->name, name) == 0)) {
return s;
}
i =  i + 1;
;
};
return null;
};
struct structMemb* searchStructMemb(char * name,struct cStruct* s,struct Elems* elems){
struct string n =  string(name);
;
if (hasStructSep(n)) {
struct string rn =  splitStructSepBefore(n);
;
name =  rn.content;
;
n.trimLeft(&n,rn.length);
if (n.hasPrefix(&n,".")) {
n.trimLeft(&n,1);
}
else {
n.trimLeft(&n,2);
}
char * membs =  n.content;
;
struct structMemb* memb =  searchStructMemb(name,s,elems);
;
if ((n.length>0)) {
s =  searchStruct(memb->type,elems);
;
char * nstr =  n.str(&n);
;
memb =  searchStructMemb(nstr,s,elems);
;
}
return memb;
}
array(struct structMemb*)* members =  s->members;
;
long int i =  0;
;
while ((i<len(members))) {
struct structMemb* m =  members->data[i];
;
if ((strcmp(m->name, name) == 0)) {
return m;
}
i =  i + 1;
;
};
array(struct func*)* mthds =  s->methods;
;
i =  0;
;
while ((i<len(mthds))) {
struct func* m =  mthds->data[i];
;
if ((strcmp(m->name, name) == 0)) {
struct structMemb* sm = memoryAlloc(sizeof(struct structMemb));
;
sm->name = "";
sm->type = "";
sm->isConst = false;
sm->isArray = false;
sm->def = "";
sm->isFn = false;
sm->from = "";
sm->name =  m->name;
;
sm->type =  m->returns->type;
;
sm->isFn =  true;
;
return sm;
}
i =  i + 1;
;
};
return null;
};
struct string getCType(char * t,struct Elems* elems){
if ((strlen(t)==0)) {
return string("void");
}
struct string tp =  string(t);
;
tp.replace(&tp," ","");
if (tp.hasPrefix(&tp,"[]")) {
tp.trimLeft(&tp,2);
char * tpstr =  tp.str(&tp);
;
tp =  getCType(tpstr,elems);
;
t =  tp.str(&tp);
;
char * r =  concatCPSTRING(concatCPSTRING("array(",t),")*");
;
return string(r);
}
struct string ctp =  tp;
;
ctp.replace(&ctp,"*","");
if (ctp.compare(&ctp,"int")) {
tp.replace(&tp,"int","long int");
}
else if (ctp.compare(&ctp,"int32")) {
tp.replace(&tp,"int32","int");
}
else if (ctp.compare(&ctp,"uint32")) {
tp.replace(&tp,"uint32","unsigned int");
}
else if (ctp.compare(&ctp,"uint")) {
tp.replace(&tp,"uint","unsigned long int");
}
else if (ctp.compare(&ctp,"float32")) {
tp.replace(&tp,"float32","float");
}
else if (ctp.compare(&ctp,"ufloat32")) {
tp.replace(&tp,"ufloat32","unsigned float");
}
else if (ctp.compare(&ctp,"ufloat")) {
tp.replace(&tp,"ufloat","unsigned double");
}
else if (ctp.compare(&ctp,"float")) {
tp.replace(&tp,"float","double");
}
else if (ctp.compare(&ctp,"long")) {
tp.replace(&tp,"long","long long");
}
else if (ctp.compare(&ctp,"ulong")) {
tp.replace(&tp,"ulong","unsigned long long");
}
else if (ctp.compare(&ctp,"cpstring")) {
tp.replace(&tp,"cpstring","char *");
}
else if (ctp.compare(&ctp,"ptr")) {
tp.replace(&tp,"ptr","void *");
}
else if (ctp.compare(&ctp,"ushort")) {
tp.replace(&tp,"ushort","unsigned short");
}
else if (ctp.compare(&ctp,"byte")) {
tp.replace(&tp,"byte","unsigned char");
}
else if (ctp.compare(&ctp,"bool")) {
tp.replace(&tp,"bool","int");
}
else if (ctp.compare(&ctp,"char")) {
}
else {
char * ctpstr =  ctp.str(&ctp);
;
struct cStruct* s =  searchStruct(ctpstr,elems);
;
if ((s!=null)) {
tp.prepend(&tp,"struct ");
}
else {
long int i =  0;
;
while ((i<len(elems->types))) {
char * ct =  elems->types->data[i];
;
if (ctp.compare(&ctp,ct)) {
return tp;
}
i =  i + 1;
;
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
;
char * info =  "";
;
if ((tp!=null)) {
struct fileMap fm =  {};
;
fm.open = fileMap__open;
fm.isValid = fileMap__isValid;
fm.close = fileMap__close;
char * fileSrcStr =  fm.open(&fm,compilerState.currentFile);
;
struct string fileSrc =  string(fileSrcStr);
;
fm.close(&fm);
struct Tok* t =  tp;
;
struct string ffmt =  string(format);
;
ffmt.replace(&ffmt,"{TOKEN}",concatCPSTRING(concatCPSTRING("'",t->cont),"'"));
format =  ffmt.str(&ffmt);
;
array(char)* line = memoryAlloc(sizeof(array(char)));;

line->length = 0;
line->elemSize = sizeof(char);
long int beg =  t->pos;
;
while ((beg>0)) {
char c =  fileSrc.charAt(&fileSrc,beg);
;
if ((c==(char)10)) {
beg =  beg + 1;
;
break;
}
beg =  beg - 1;
;
};
long int pos =  t->pos - beg;
;
long int i =  beg;
;
while ((i<fileSrc.length)) {
char c =  fileSrc.charAt(&fileSrc,i);
;
if ((c==(char)10)) {
break;
}
if ((i==t->pos)) {
array(char)* errTk =  strToArr(concatCPSTRING(concatCPSTRING("\e[1;31m",t->cont),"\e[1;37m"));
;
long int ii =  0;
;
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
;
ii =  ii + 1;
;
};
i =  i + strlen(t->cont);
;
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
;
i =  i + 1;
;
};
str =  arrToStr(line);
;
info =  intToStr(t->line);
;
}
println(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING("\e[1;31m[ERROR]\e[0m ",compilerState.currentFile),":"),info),"\n\e[1;37m\t"),str),"\e[0m\n"),format));
exit(1);
};
struct variable* searchVar(char * name,struct Elems* elems){
char * ogName =  name;
;
struct string n =  string(name);
;
n.replace(&n,"&","");
n.replace(&n,"*","");
if (n.hasSuffix(&n,"]")) {
long int i =  n.length;
;
while ((i>0)) {
char c =  n.charAt(&n,i);
;
if ((c==91)) {
break;
}
i =  i - 1;
;
};
long int tamm =  n.length - i;
;
n.trimRight(&n,tamm + 6);
name =  n.str(&n);
;
struct variable* v =  searchVar(name,elems);
;
struct string vt =  string(v->type);
;
vt.trimLeft(&vt,2);
char * vtstr =  vt.str(&vt);
;
struct variable* nv = memoryAlloc(sizeof(struct variable));
;
nv->name = "";
nv->type = "";
nv->isConst = false;
nv->isArray = false;
nv->type =  vtstr;
;
nv->name =  ogName;
;
nv->isArray =  true;
;
return nv;
}
name =  n.content;
;
if (hasStructSep(n)) {
struct string rn =  splitStructSepBefore(n);
;
name =  rn.content;
;
n.trimLeft(&n,rn.length);
if (n.hasPrefix(&n,".")) {
n.trimLeft(&n,1);
}
else {
n.trimLeft(&n,2);
}
char * membs =  n.content;
;
struct variable* v =  searchVar(name,elems);
;
if ((v==null)) {
return null;
}
struct cStruct* s =  searchStruct(v->type,elems);
;
if ((s==null)) {
return null;
}
struct structMemb* memb =  searchStructMemb(membs,s,elems);
;
if ((memb==null)) {
return null;
}
struct variable* nv = memoryAlloc(sizeof(struct variable));
;
nv->name = "";
nv->type = "";
nv->isConst = false;
nv->isArray = false;
nv->name =  memb->name;
;
nv->type =  memb->type;
;
nv->name =  ogName;
;
char * r =  nv->type;
;
struct string tcc =  string(ogName);
;
if (tcc.count(&tcc,"&")) {
r =  concatCPSTRING(r,"*");
;
}
long int nbUnaries =  tcc.count(&tcc,"*");
;
if ((nbUnaries>0)) {
struct string ct =  string(r);
;
long int pointerLevel =  ct.count(&ct,"*");
;
if ((pointerLevel<nbUnaries)) {
throwErr(null,concatCPSTRING(concatCPSTRING("Cannot use '*' on ",nv->name)," because it is not pointer."));
}
ct.trimRight(&ct,nbUnaries);
r =  ct.str(&ct);
;
}
nv->type =  r;
;
nv->name =  ogName;
;
return nv;
}
long int i =  0;
;
while ((i<len(elems->vars))) {
struct variable* v =  elems->vars->data[i];
;
if ((v==null)) {
panic(concatCPSTRING(concatCPSTRING("\e[1;31m[INTERNAL COMPILER ERROR]\e[0m\n Please report the bug as 'compiler searching '",name),"' resulting in null var'."));
}
if ((strcmp(v->name, name) == 0)) {
struct variable* nv = memoryAlloc(sizeof(struct variable));
;
nv->name = "";
nv->type = "";
nv->isConst = false;
nv->isArray = false;
nv->type =  v->type;
;
nv->name =  v->name;
;
char * r =  nv->type;
;
struct string tcc =  string(ogName);
;
if (tcc.count(&tcc,"&")) {
r =  concatCPSTRING(r,"*");
;
}
long int nbUnaries =  tcc.count(&tcc,"*");
;
if ((nbUnaries>0)) {
struct string ct =  string(r);
;
long int pointerLevel =  ct.count(&ct,"*");
;
if ((pointerLevel<nbUnaries)) {
throwErr(null,concatCPSTRING(concatCPSTRING("Cannot use '*' on ",v->name)," because it is not pointer."));
}
ct.trimRight(&ct,nbUnaries);
r =  ct.str(&ct);
;
}
nv->type =  r;
;
nv->name =  ogName;
;
return nv;
}
i =  i + 1;
;
};
i =  0;
;
while ((i<len(elems->fns))) {
struct func* fn =  elems->fns->data[i];
;
if ((strcmp(fn->name, name) == 0)) {
struct variable* nv = memoryAlloc(sizeof(struct variable));
;
nv->name = "";
nv->type = "";
nv->isConst = false;
nv->isArray = false;
nv->name =  name;
;
nv->type =  "function(";
;
long int j =  0;
;
while ((j<len(fn->args))) {
struct variable* arg =  fn->args->data[j];
;
nv->type =  concatCPSTRING(nv->type,arg->type);
;
j =  j + 1;
;
if ((j<len(fn->args))) {
nv->type =  concatCPSTRING(nv->type,",");
;
}
};
nv->type =  concatCPSTRING(concatCPSTRING(nv->type,")"),fn->returns->type);
;
return nv;
}
i =  i + 1;
;
};
return null;
};
char * setCType(struct variable* v,struct Elems* elems){
struct string tp =  getCType(v->type,elems);
;
char * t =  tp.str(&tp);
;
t =  concatCPSTRING(concatCPSTRING(t," "),v->name);
;
return t;
};
char * getTypeFromToken(struct Tok* t,int strict,struct Elems* elems){
if ((strlen(t->bahType)>0)) {
char * r =  t->bahType;
;
return r;
}
if ((t->type==TOKEN_TYPE_VAR)) {
struct variable* v =  searchVar(t->cont,elems);
;
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
;
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
;
nf->name = "";
nf->args = memoryAlloc(sizeof(array(struct variable*)));
            nf->args->length = 0;
            nf->args->elemSize = sizeof(struct variable*);
            nf->isBinding = false;
nf->from = "";
nf->file = "";
nf->line = 1;
cvt.trimLeft(&cvt,9);
array(char)* memory = memoryAlloc(sizeof(array(char)));;

memory->length = 0;
memory->elemSize = sizeof(char);
long int j =  0;
;
while ((j<cvt.length)) {
char c =  cvt.charAt(&cvt,j);
;
if ((c==41)) {
break;
}
struct variable* arg = memoryAlloc(sizeof(struct variable));
;
arg->name = "";
arg->type = "";
arg->isConst = false;
arg->isArray = false;
arg->name =  concatCPSTRING("arg_",intToStr(len(nf->args)));
;
while ((j<cvt.length)) {
c =  cvt.charAt(&cvt,j);
;
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
;
j =  j + 1;
;
};
arg->type =  arrToStr(memory);
;
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
;
if ((c==41)) {
break;
}
j =  j + 1;
;
};
j =  j + 1;
;
while ((j<cvt.length)) {
char c =  cvt.charAt(&cvt,j);
;

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
;
j =  j + 1;
;
};
nf->returns = memoryAlloc(sizeof(struct variable));
;
nf->returns->name = "";
nf->returns->type = "";
nf->returns->isConst = false;
nf->returns->isArray = false;
nf->returns->name =  "_return";
;
nf->returns->type =  arrToStr(memory);
;
return nf;
};
struct func* searchFunc(char * name,struct Elems* elems,int inclCurr){
char * ogName =  name;
;
if ((strcmp(name, "noCheck") == 0)) {
struct func* fn = memoryAlloc(sizeof(struct func));
;
fn->name = "";
fn->args = memoryAlloc(sizeof(array(struct variable*)));
            fn->args->length = 0;
            fn->args->elemSize = sizeof(struct variable*);
            fn->isBinding = false;
fn->from = "";
fn->file = "";
fn->line = 1;
fn->name =  "noCheck";
;
return fn;
}
struct string n =  string(name);
;
if (hasStructSep(n)) {
struct string fnName =  splitStructSepAfter(n);
;
n.trimRight(&n,fnName.length);
char c =  n.charAt(&n,n.length-1);
;
if ((c==46)) {
n.trimRight(&n,1);
}
else {
n.trimRight(&n,2);
}
name =  n.str(&n);
;
struct variable* v =  searchVar(name,elems);
;
struct cStruct* s =  searchStruct(v->type,elems);
;
name =  fnName.content;
;
name =  concatCPSTRING(concatCPSTRING(s->name,"__"),name);
;
}
array(struct func*)* fns =  elems->fns;
;
long int i =  0;
;
while ((i<len(fns))) {
struct func* fn =  fns->data[i];
;
if ((fn==null)) {
panic(concatCPSTRING(concatCPSTRING("\e[1;31m[INTERNAL COMPILER ERROR]\e[0m\n Please report the bug as 'compiler searching '",name),"' resulting in null func'."));
}
if ((strcmp(fn->name, name) == 0)) {
return fn;
}
i =  i + 1;
;
};
if ((inclCurr==true)) {
if ((strcmp(currentFn->name, name) == 0)) {
return currentFn;
}
}
struct variable* v =  searchVar(ogName,elems);
;
if ((v==null)) {
return null;
}
struct func* nf = memoryAlloc(sizeof(struct func));
;
nf->name = "";
nf->args = memoryAlloc(sizeof(array(struct variable*)));
            nf->args->length = 0;
            nf->args->elemSize = sizeof(struct variable*);
            nf->isBinding = false;
nf->from = "";
nf->file = "";
nf->line = 1;
nf->name =  ogName;
;
struct string cvt =  string(v->type);
;
if ((cvt.hasPrefix(&cvt,"function(")==0)) {
return null;
}
struct func* pfn =  parseFnType(cvt);
;
nf->returns =  pfn->returns;
;
nf->args =  pfn->args;
;
return nf;
};
char * declareStructMethods(struct variable* v,struct cStruct* s,struct Elems* elems){
char * code =  "";
;
array(struct structMemb*)* members =  s->members;
;
struct string typec =  string(v->type);
;
char * sep =  ".";
;
if (typec.count(&typec,"*")) {
sep =  "->";
;
}
long int i =  0;
;
while ((i<len(members))) {
struct structMemb* m =  members->data[i];
;
struct string cmpt =  string(m->type);
;
if ((strlen(m->def)>0)) {
code =  concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(code,v->name),sep),m->name)," = "),m->def),";\n");
;
}
if ((cmpt.hasPrefix(&cmpt,"[]")==1)) {
cmpt.trimLeft(&cmpt,2);
char * cmptstr =  cmpt.str(&cmpt);
;
struct string elemCType =  getCType(cmptstr,elems);
;
char * elemCTypeStr =  elemCType.str(&elemCType);
;
code =  concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(code,v->name),sep),m->name)," = memoryAlloc(sizeof(array("),elemCTypeStr),")));\n            "),v->name),sep),m->name),"->length = 0;\n            "),v->name),sep),m->name),"->elemSize = sizeof("),elemCTypeStr),");\n            ");
;
}
i =  i + 1;
;
};
array(struct func*)* methods =  s->methods;
;
i =  0;
;
while ((i<len(methods))) {
struct func* m =  methods->data[i];
;
code =  concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(code,v->name),sep),m->name)," = "),s->name),"__"),m->name),";\n");
;
i =  i + 1;
;
};
return code;
};
void debugLine(__BAH_ARR_TYPE_Tok line){
char * cont =  "";
;
long int i =  0;
;
while ((i<len(line))) {
struct Tok t =  line->data[i];
;
cont =  concatCPSTRING(concatCPSTRING(concatCPSTRING(cont," '"),t.cont),"'");
;
i =  i + 1;
;
};
println(cont);
};
struct Elems* dupElems(struct Elems* elems){
struct Elems* nElems = memoryAlloc(sizeof(struct Elems));
;
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
            array(struct variable*)* nvs = memoryAlloc(sizeof(array(struct variable*)));;

nvs->length = 0;
nvs->elemSize = sizeof(struct variable*);
array(struct variable*)* vs =  elems->vars;
;
long int j =  0;
;
while ((j<len(vs))) {
struct variable* v =  vs->data[j];
;
struct variable* nv = memoryAlloc(sizeof(struct variable));
;
nv->name = "";
nv->type = "";
nv->isConst = false;
nv->isArray = false;
*nv =  *v;
;

{
long nLength = len(nvs);
if (nvs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(nvs->data, (nLength+50)*sizeof(struct variable*));
nvs->data = newPtr;
}
nvs->data[len(nvs)] =  nv;

nvs->length = nLength+1;
} else {
nvs->data[len(nvs)] =  nv;

};
};
;
j =  j + 1;
;
};
nElems->vars =  nvs;
;
array(struct cStruct*)* nss = memoryAlloc(sizeof(array(struct cStruct*)));;

nss->length = 0;
nss->elemSize = sizeof(struct cStruct*);
array(struct cStruct*)* ss =  elems->structs;
;
j =  0;
;
while ((j<len(ss))) {
struct cStruct* s =  ss->data[j];
;
struct cStruct* ns = memoryAlloc(sizeof(struct cStruct));
;
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
;

{
long nLength = len(nss);
if (nss->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(nss->data, (nLength+50)*sizeof(struct cStruct*));
nss->data = newPtr;
}
nss->data[len(nss)] =  ns;

nss->length = nLength+1;
} else {
nss->data[len(nss)] =  ns;

};
};
;
j =  j + 1;
;
};
nElems->structs =  nss;
;
array(char *)* nts = memoryAlloc(sizeof(array(char *)));;

nts->length = 0;
nts->elemSize = sizeof(char *);
array(char *)* ts =  elems->types;
;
j =  0;
;
while ((j<len(ts))) {
char * t =  ts->data[j];
;
char * nt =  __STR(t);
;

{
long nLength = len(nts);
if (nts->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(nts->data, (nLength+50)*sizeof(char *));
nts->data = newPtr;
}
nts->data[len(nts)] =  nt;

nts->length = nLength+1;
} else {
nts->data[len(nts)] =  nt;

};
};
;
j =  j + 1;
;
};
nElems->types =  nts;
;
array(struct func*)* nfs = memoryAlloc(sizeof(array(struct func*)));;

nfs->length = 0;
nfs->elemSize = sizeof(struct func*);
array(struct func*)* fs =  elems->fns;
;
j =  0;
;
while ((j<len(fs))) {
struct func* f =  fs->data[j];
;
struct func* nf = memoryAlloc(sizeof(struct func));
;
nf->name = "";
nf->args = memoryAlloc(sizeof(array(struct variable*)));
            nf->args->length = 0;
            nf->args->elemSize = sizeof(struct variable*);
            nf->isBinding = false;
nf->from = "";
nf->file = "";
nf->line = 1;
*nf =  *f;
;

{
long nLength = len(nfs);
if (nfs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(nfs->data, (nLength+50)*sizeof(struct func*));
nfs->data = newPtr;
}
nfs->data[len(nfs)] =  nf;

nfs->length = nLength+1;
} else {
nfs->data[len(nfs)] =  nf;

};
};
;
j =  j + 1;
;
};
nElems->fns =  nfs;
;
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
;
lineType getLineType(__BAH_ARR_TYPE_Tok line){
struct Tok ft =  line->data[0];
;
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
;
if ((st.type==TOKEN_TYPE_ENCL)) {
if ((strcmp(st.cont, "(") == 0)) {
struct Tok lt =  line->data[len(line)-1];
;
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
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));;

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
long int i =  0;
;
while ((i<len(line))) {
struct Tok t =  line->data[i];
;
if ((t.type==TOKEN_TYPE_SYNTAX)) {
if ((strcmp(t.cont, "<") == 0)) {
long int max =  i + 3;
;
if ((max<len(line))) {
struct Tok nt =  line->data[i + 1];
;
struct Tok nnt =  line->data[i + 2];
;
struct Tok nnnt =  line->data[i + 3];
;
if ((nt.type==TOKEN_TYPE_VAR)) {
if ((nnt.type==TOKEN_TYPE_SYNTAX)) {
if ((strcmp(nnt.cont, ">") == 0)) {
nnnt.bahType =  nt.cont;
;
struct string cCast =  getCType(nt.cont,elems);
;
char * cCastStr =  cCast.str(&cCast);
;
nnnt.cont =  concatCPSTRING(concatCPSTRING(concatCPSTRING("(",cCastStr),")"),nnnt.cont);
;

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
;
i =  i + 4;
;
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
;
i =  i + 1;
;
};
return nl;
};
void parseLines(__BAH_ARR_TYPE_Tok ts,struct Elems* elems);
int includeFile(char * ccstr,struct Elems* elems){
array(char *)* includes =  compilerState.includes;
;
long int i =  0;
;
while ((i<len(includes))) {
if ((strcmp(includes->data[i], ccstr) == 0)) {
return true;
}
i =  i + 1;
;
};
struct fileMap fm =  {};
;
fm.open = fileMap__open;
fm.isValid = fileMap__isValid;
fm.close = fileMap__close;
char * fileName =  concatCPSTRING(BAH_DIR,ccstr);
;
char * f =  fm.open(&fm,fileName);
;
if ((fm.isValid(&fm)==0)) {
fileName =  ccstr;
;
f =  fm.open(&fm,fileName);
;
if ((fm.isValid(&fm)==0)) {
return false;
}
}
char * oFile =  compilerState.currentFile;
;
compilerState.currentFile =  fileName;
;

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
;
array(struct Tok)* tokens =  lexer(f);
;
fm.close(&fm);
if ((len(tokens)==0)) {
panic(concatCPSTRING(concatCPSTRING("File '",ccstr),"' not recognized."));
}
parseLines(tokens,elems);
compilerState.currentFile =  oFile;
;
return true;
};
void parseInclude(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
if ((len(l)>2)) {
throwErr(&l->data[len(l)-1],"Invalid usage of include, ending by {TOKEN}.");
}
struct Tok strt =  l->data[1];
;
if ((strt.type!=TOKEN_TYPE_STR)) {
throwErr(&strt,"Cannot use {TOKEN} as string in include.");
}
struct string cc =  string(strt.cont);
;
cc.trimLeft(&cc,1);
cc.trimRight(&cc,1);
char * ccstr =  cc.str(&cc);
;
if (cc.hasPrefix(&cc,"<")) {
OUTPUT =  concatCPSTRING(concatCPSTRING(concatCPSTRING(OUTPUT,"#include "),ccstr),"\n");
;
}
else {
if ((includeFile(ccstr,elems)==false)) {
throwErr(&strt,"Could not find file {TOKEN}.");
}
}
};
__BAH_ARR_TYPE_Tok parseOperations(__BAH_ARR_TYPE_Tok line,struct Elems* elems){
array(char *)* signs = memoryAlloc(sizeof(array(char *)));;

signs->length = 7;
signs->elemSize = sizeof(char *);
signs->data = memoryAlloc(sizeof(char *) * 50);signs->data[0] = __STR("|");
signs->data[1] = __STR("&");
signs->data[2] = __STR("%");
signs->data[3] = __STR("+");
signs->data[4] = __STR("-");
signs->data[5] = __STR("*");
signs->data[6] = __STR("/");
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));;

nl->length = 1;
nl->elemSize = sizeof(struct Tok);
nl->data = memoryAlloc(sizeof(struct Tok) * 50);nl->data[0] = line->data[0];
long int i =  1;
;
while ((i<len(line))) {
struct Tok t =  line->data[i];
;
if ((t.type==TOKEN_TYPE_SYNTAX)) {
if (inArrayStr(t.cont,signs)) {
long int max =  i + 1;
;
if ((max>=len(line))) {
throwErr(&t,"Cannot use {TOKEN} on nothing.");
}
struct Tok pt =  nl->data[len(nl)-1];
;
struct Tok nt =  line->data[i + 1];
;
if ((strcmp(t.cont, "-") == 0)) {
if ((pt.isValue==false)) {
if ((nt.type==TOKEN_TYPE_INT)) {
if ((pt.isValue==false)) {
nt.cont =  concatCPSTRING(t.cont,nt.cont);
;

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
;
i =  i + 2;
;
continue;
}
}
}
}
char * ptt =  getTypeFromToken(&pt,true,elems);
;
char * ntt =  getTypeFromToken(&nt,true,elems);
;
if ((compTypes(ptt,ntt)==false)) {
throwErr(&nt,concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING("Cannot use {TOKEN} (",ntt),") as "),ptt),"."));
}
t.isValue =  true;
;
if (compTypes(ptt,"cpstring")) {
if ((strcmp(t.cont, "+") != 0)) {
throwErr(&t,"Can only do concatenation (+) on cpstrings, not {TOKEN}.");
}
t.cont =  concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING("concatCPSTRING(",pt.cont),","),nt.cont),")");
;
}
else {
t.cont =  concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(pt.cont," "),t.cont)," "),nt.cont);
;
}
t.type =  TOKEN_TYPE_VAR;
;
t.bahType =  ptt;
;
t.pos =  pt.pos;
;

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
;
i =  i + 2;
;
continue;
}
}
else if ((t.isValue==true)) {
struct string cmtc =  string(t.cont);
;
if (cmtc.hasPrefix(&cmtc,"-")) {
struct Tok pt =  nl->data[len(nl)-1];
;
if ((pt.isValue==true)) {
char * ptt =  getTypeFromToken(&pt,true,elems);
;
char * ntt =  getTypeFromToken(&t,true,elems);
;
if ((compTypes(ptt,ntt)==false)) {
throwErr(&t,concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING("Cannot use {TOKEN} (",ntt),") as "),ptt),"."));
}
t.type =  TOKEN_TYPE_VAR;
;
t.cont =  concatCPSTRING(pt.cont,t.cont);
;
t.bahType =  ptt;
;
t.pos =  pt.pos;
;

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
;
i =  i + 1;
;
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
;
i =  i + 1;
;
};
return nl;
};
__BAH_ARR_TYPE_Tok parseStructType(__BAH_ARR_TYPE_Tok line,struct Elems* elems){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));;

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
long int i =  0;
;
while ((i<len(line))) {
struct Tok t =  line->data[i];
;
if ((t.type==TOKEN_TYPE_VAR)) {
struct string ctbt =  string(t.bahType);
;
if (ctbt.hasPrefix(&ctbt,"[]")) {

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
;
i =  i + 1;
;
continue;
}
i =  i + 1;
;
if ((i<len(line))) {
struct Tok nt =  line->data[i];
;
if ((strcmp(nt.cont, "{") == 0)) {
i =  i + 1;
;
struct cStruct* s =  searchStruct(t.cont,elems);
;
if ((s==null)) {
throwErr(&t,"Unknown struct name {TOKEN}.");
}
char * memory =  "";
;
while ((i<len(line))) {
t =  line->data[i];
;
if ((strcmp(t.cont, "}") == 0)) {
break;
}
memory =  concatCPSTRING(concatCPSTRING(memory,t.cont)," ");
;
i =  i + 1;
;
};
t.bahType =  s->name;
;
t.cont =  concatCPSTRING(concatCPSTRING("{",memory),"}");
;
t.isValue =  true;
;

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
;
i =  i + 1;
;
continue;
}
else {
i =  i - 1;
;
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
;
i =  i + 1;
;
};
return nl;
};
__BAH_ARR_TYPE_Tok parseStructVars(__BAH_ARR_TYPE_Tok line,struct Elems* elems){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));;

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
long int i =  0;
;
while ((i<len(line))) {
struct Tok t =  line->data[i];
;
if ((t.type==TOKEN_TYPE_VAR)) {
i =  i + 1;
;
while ((i<len(line))) {
struct Tok it =  line->data[i];
;
if ((strcmp(it.cont, ".") != 0)) {
break;
}
struct variable* v =  searchVar(t.cont,elems);
;
if ((v==null)) {
throwErr(&t,"Unknown var {TOKEN}.");
}
struct string ct =  string(v->type);
;
char * sep =  ".";
;
if (ct.count(&ct,"*")) {
sep =  "->";
;
}
struct cStruct* s =  searchStruct(v->type,elems);
;
i =  i + 1;
;
struct Tok nt =  line->data[i];
;
if ((nt.type!=TOKEN_TYPE_VAR)) {
throwErr(&nt,"Cannot use {TOKEN} as struct member name.");
}
struct structMemb* memb =  searchStructMemb(nt.cont,s,elems);
;
if ((memb==null)) {
throwErr(&nt,"Unknown struct member {TOKEN}.");
}
t.cont =  concatCPSTRING(concatCPSTRING(t.cont,sep),memb->name);
;
i =  i + 1;
;
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
;
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
;
i =  i + 1;
;
};
return nl;
};
__BAH_ARR_TYPE_Tok parseArrayType(__BAH_ARR_TYPE_Tok line,struct Elems* elems){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));;

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
long int i =  0;
;
while ((i<len(line))) {
struct Tok t =  line->data[i];
;
if ((strcmp(t.cont, "[") == 0)) {
i =  i + 1;
;
if ((i<len(line))) {
t =  line->data[i];
;
if ((strcmp(t.cont, "]") == 0)) {
i =  i + 1;
;
if ((i<len(line))) {
t =  line->data[i];
;
if ((t.type!=TOKEN_TYPE_VAR)) {
throwErr(&t,"Cannot use {TOKEN} as array type.");
}
char * arrElem =  t.cont;
;
t.bahType =  concatCPSTRING("[]",arrElem);
;
t.cont =  "";
;
t.isValue =  true;
;

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
;
i =  i + 1;
;
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
;
i =  i + 1;
;
};
return nl;
};
__BAH_ARR_TYPE_Tok parseBool(__BAH_ARR_TYPE_Tok line,struct Elems* elems){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));;

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
array(char *)* comparators = memoryAlloc(sizeof(array(char *)));;

comparators->length = 6;
comparators->elemSize = sizeof(char *);
comparators->data = memoryAlloc(sizeof(char *) * 50);comparators->data[0] = __STR("==");
comparators->data[1] = __STR("!=");
comparators->data[2] = __STR(">");
comparators->data[3] = __STR("<");
comparators->data[4] = __STR("<=");
comparators->data[5] = __STR(">=");
array(char *)* compSep = memoryAlloc(sizeof(array(char *)));;

compSep->length = 2;
compSep->elemSize = sizeof(char *);
compSep->data = memoryAlloc(sizeof(char *) * 50);compSep->data[0] = __STR("||");
compSep->data[1] = __STR("&&");
long int i =  0;
;
while ((i<len(line))) {
struct Tok t =  line->data[i];
;
if (inArrayStr(t.cont,comparators)) {
if ((i==0)) {
throwErr(&t,"Cannot use {TOKEN} to compare with nothing.");
}
struct Tok pt =  nl->data[len(nl)-1];
;
long int max =  i + 1;
;
if ((max>=len(line))) {
throwErr(&t,"Cannot use {TOKEN} to compare with nothing.");
}
struct Tok nt =  line->data[i + 1];
;
char * ptt =  getTypeFromToken(&pt,true,elems);
;
char * ntt =  getTypeFromToken(&nt,true,elems);
;
if ((compTypes(ptt,ntt)==false)) {
throwErr(&nt,concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING("Cannot compare {TOKEN} (",ntt),") to "),ptt),"."));
}
if ((strcmp(ptt, "cpstring") == 0)) {
if ((strcmp(t.cont, "==") == 0)) {
pt.cont =  concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING("(strcmp(",pt.cont),", "),nt.cont),") == 0)");
;
}
else if ((strcmp(t.cont, "!=") == 0)) {
pt.cont =  concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING("(strcmp(",pt.cont),", "),nt.cont),") != 0)");
;
}
else if ((strcmp(t.cont, ">") == 0)) {
pt.cont =  concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING("(strlen(",pt.cont),") > srtlen("),nt.cont),"))");
;
}
else if ((strcmp(t.cont, "<") == 0)) {
pt.cont =  concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING("(strlen(",pt.cont),") < srtlen("),nt.cont),"))");
;
}
else if ((strcmp(t.cont, ">=") == 0)) {
pt.cont =  concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING("(strlen(",pt.cont),") >= srtlen("),nt.cont),"))");
;
}
else if ((strcmp(t.cont, "<=") == 0)) {
pt.cont =  concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING("(strlen(",pt.cont),") <= srtlen("),nt.cont),"))");
;
}
}
else {
pt.cont =  concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING("(",pt.cont),t.cont),nt.cont),")");
;
}
pt.bahType =  "bool";
;

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
;
i =  i + 2;
;
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
;
i =  i + 1;
;
};
copy(line,nl);
clear(nl);
i =  0;
;
while ((i<len(line))) {
struct Tok t =  line->data[i];
;
if (inArrayStr(t.cont,compSep)) {
if ((i==0)) {
throwErr(&t,"Cannot use {TOKEN} to compare with nothing.");
}
struct Tok pt =  nl->data[len(nl)-1];
;
long int max =  i + 1;
;
if ((max>=len(line))) {
throwErr(&t,"Cannot use {TOKEN} to compare with nothing.");
}
struct Tok nt =  line->data[i + 1];
;
char * ptt =  getTypeFromToken(&pt,true,elems);
;
char * ntt =  getTypeFromToken(&nt,true,elems);
;
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
pt.cont =  concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING("(",pt.cont),t.cont),nt.cont),")");
;
pt.bahType =  "bool";
;

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
;
i =  i + 2;
;
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
;
i =  i + 1;
;
};
return nl;
};
__BAH_ARR_TYPE_Tok parsePointers(__BAH_ARR_TYPE_Tok l){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));;

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
array(char *)* ptrOpers = memoryAlloc(sizeof(array(char *)));;

ptrOpers->length = 2;
ptrOpers->elemSize = sizeof(char *);
ptrOpers->data = memoryAlloc(sizeof(char *) * 50);ptrOpers->data[0] = __STR("&");
ptrOpers->data[1] = __STR("*");
long int i =  0;
;
while ((i<len(l))) {
struct Tok t =  l->data[i];
;
if ((strcmp(t.cont, "*") == 0)) {
if ((i>0)) {
struct Tok pt =  nl->data[len(nl)-1];
;
if ((pt.type==TOKEN_TYPE_VAR)) {
long int max =  i + 1;
;
if ((max<len(l))) {
struct Tok nt =  l->data[i + 1];
;
if ((nt.isValue==false)) {
pt.cont =  concatCPSTRING(pt.cont,t.cont);
;

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
;
i =  i + 1;
;
continue;
}
}
else {
pt.cont =  concatCPSTRING(pt.cont,t.cont);
;

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
;
i =  i + 1;
;
continue;
}
}
}
}
if (inArrayStr(t.cont,ptrOpers)) {
if ((i>0)) {
struct Tok pt =  nl->data[len(nl)-1];
;
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
;
i =  i + 1;
;
continue;
}
}
i =  i + 1;
;
if ((i<len(l))) {
struct Tok nt =  l->data[i];
;
if ((nt.type==TOKEN_TYPE_VAR)) {
nt.cont =  concatCPSTRING(t.cont,nt.cont);
;

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
;
i =  i + 1;
;
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
;
i =  i + 1;
;
};
return nl;
};
__BAH_ARR_TYPE_Tok prePross(__BAH_ARR_TYPE_Tok line,struct Elems* elems);
__BAH_ARR_TYPE_Tok parseArrayVars(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));;

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
int found =  false;
;
long int i =  0;
;
while ((i<len(l))) {
struct Tok t =  l->data[i];
;
if ((t.type==TOKEN_TYPE_VAR)) {
i =  i + 1;
;
if ((i<len(l))) {
t =  l->data[i];
;
if ((strcmp(t.cont, "[") == 0)) {
found =  true;
;
break;
}
}
}
i =  i + 1;
;
};
if ((found==false)) {
return l;
}
i =  0;
;
while ((i<len(l))) {
struct Tok t =  l->data[i];
;
if ((t.type==TOKEN_TYPE_VAR)) {
i =  i + 1;
;
if ((i<len(l))) {
struct Tok nt =  l->data[i];
;
if ((strcmp(nt.cont, "[") == 0)) {
struct variable* v =  searchVar(t.cont,elems);
;
if ((v==null)) {
throwErr(&t,"Unknown array-var {TOKEN}.");
}
struct string cvt =  string(v->type);
;
if ((cvt.hasPrefix(&cvt,"[]")==0)) {
throwErr(&nt,concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING("Cannot use ",v->name)," ("),v->type),") as an array."));
}
cvt.trimLeft(&cvt,2);
v->type =  cvt.str(&cvt);
;
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));;

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
i =  i + 1;
;
long int nbBracks =  1;
;
while ((i<len(l))) {
struct Tok it =  l->data[i];
;
if ((strcmp(it.cont, "[") == 0)) {
nbBracks =  nbBracks + 1;
;
}
else if ((strcmp(it.cont, "]") == 0)) {
nbBracks =  nbBracks - 1;
;
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
;
i =  i + 1;
;
};
i =  i + 1;
;
if ((len(memory)==0)) {
throwErr(&l->data[i],"Expected index not {TOKEN}.");
}
memory =  prePross(memory,elems);
;
char * cont =  "";
;
long int j =  0;
;
while ((j<len(memory))) {
struct Tok mt =  memory->data[j];
;
cont =  concatCPSTRING(cont,mt.cont);
;
j =  j + 1;
;
};
t.cont =  concatCPSTRING(concatCPSTRING(concatCPSTRING(t.cont,"->data["),cont),"]");
;
t.bahType =  v->type;
;

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
;
continue;
}
}
i =  i - 1;
;
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
;
i =  i + 1;
;
};
return nl;
};
__BAH_ARR_TYPE_Tok parseFnCall(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));;

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
int found =  false;
;
long int i =  0;
;
while ((i<len(l))) {
struct Tok t =  l->data[i];
;
if ((t.type==TOKEN_TYPE_VAR)) {
i =  i + 1;
;
if ((i<len(l))) {
t =  l->data[i];
;
if ((strcmp(t.cont, "(") == 0)) {
found =  true;
;
break;
}
}
}
i =  i + 1;
;
};
if ((found==false)) {
return l;
}
i =  0;
;
while ((i<len(l))) {
struct Tok ot =  l->data[i];
;
if ((ot.type==TOKEN_TYPE_VAR)) {
i =  i + 1;
;
if ((i<len(l))) {
struct Tok nt =  l->data[i];
;
if ((strcmp(nt.cont, "(") == 0)) {
long int nbPar =  1;
;
i =  i + 1;
;
char * fnName =  ot.cont;
;
struct func* fn =  searchFunc(fnName,elems,true);
;
if ((fn==null)) {
throwErr(&ot,"Unknown function {TOKEN}.");
}
struct string varName =  string("");
;
struct string fnStr =  string(fnName);
;
if (hasStructSep(fnStr)) {
varName =  fnStr;
;
struct string realFn =  splitStructSepAfter(fnStr);
;
varName.trimRight(&varName,realFn.length);
char c =  varName.charAt(&varName,varName.length - 1);
;
if ((c==46)) {
varName.trimRight(&varName,1);
}
else {
varName.trimRight(&varName,2);
}
char * varNameStr =  varName.str(&varName);
;
struct variable* v =  searchVar(varNameStr,elems);
;
if ((v==null)) {
throwErr(&ot,"Cannot use {TOKEN} as a struct.");
}
struct string vct =  string(v->type);
;
if ((vct.count(&vct,"*")==0)) {
varName.prepend(&varName,"&");
}
}
ot.cont =  concatCPSTRING(fnName,"(");
;
array(struct variable*)* fnArgs =  fn->args;
;
long int paramIndex =  0;
;
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));;

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
if ((varName.length>0)) {
struct Tok tk =  {};
;
tk.cont = "";
tk.type = TOKEN_NO_TYPE;
tk.pos = 0;
tk.line = 1;
tk.bahType = "";
tk.isValue = false;
tk.isFunc = false;
tk.cont =  varName.str(&varName);
;
tk.type =  TOKEN_TYPE_VAR;
;
tk.isValue =  true;
;

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
;
nt =  l->data[i];
;
if ((strcmp(nt.cont, ")") != 0)) {
 {};
;
tk.cont = "";
tk.type = TOKEN_NO_TYPE;
tk.pos = 0;
tk.line = 1;
tk.bahType = "";
tk.isValue = false;
tk.isFunc = false;
tk.cont =  ",";
;
tk.type =  TOKEN_TYPE_SYNTAX;
;
tk.isValue =  false;
;

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
;
}
}
while ((i<len(l))) {
struct Tok t =  l->data[i];
;
if ((strcmp(t.cont, "(") == 0)) {
nbPar =  nbPar + 1;
;
}
else if ((strcmp(t.cont, ")") == 0)) {
nbPar =  nbPar - 1;
;
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
;
if ((nbPar==0)) {
i =  i + 1;
;
break;
}
i =  i + 1;
;
};
if ((strcmp(fnName, "noCheck") == 0)) {
long int j =  0;
;
while ((j<len(memory))) {
struct Tok t =  memory->data[j];
;
ot.cont =  concatCPSTRING(concatCPSTRING(ot.cont," "),t.cont);
;
j =  j + 1;
;
};
ot.cont =  ot.cont;
;
ot.type =  TOKEN_TYPE_FUNC;
;
ot.isFunc =  true;
;
ot.bahType =  "ptr";
;

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
;
continue;
}
memory =  prePross(memory,elems);
;
struct Tok ft =  memory->data[0];
;
if ((strcmp(ft.cont, ")") != 0)) {
long int j =  0;
;
while ((j<len(memory))) {
struct Tok t =  memory->data[j];
;
if ((paramIndex>=len(fnArgs))) {
throwErr(&t,"Too many arguments in function call.");
}
struct variable* arg =  fnArgs->data[paramIndex];
;
char * tt =  getTypeFromToken(&t,true,elems);
;
if ((compTypes(tt,arg->type)==false)) {
throwErr(&t,concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING("Cannot use {TOKEN} (",tt),") as "),arg->type)," in function call."));
}
ot.cont =  concatCPSTRING(ot.cont,t.cont);
;
j =  j + 1;
;
t =  memory->data[j];
;
if ((strcmp(t.cont, ",") != 0)) {
if ((strcmp(t.cont, ")") == 0)) {
j =  j + 1;
;
paramIndex =  paramIndex + 1;
;
break;
}
else {
throwErr(&t,"Expected separator between values, not {TOKEN} in function call.");
}
}
else {
paramIndex =  paramIndex + 1;
;
ot.cont =  concatCPSTRING(ot.cont,",");
;
}
j =  j + 1;
;
};
}
if ((paramIndex<len(fnArgs))) {
ot.cont =  fnName;
;
throwErr(&ot,"Not enough arguments in function call, ending by {TOKEN}.");
}
ot.cont =  concatCPSTRING(ot.cont,")");
;
ot.type =  TOKEN_TYPE_FUNC;
;
ot.bahType =  fn->returns->type;
;
ot.isFunc =  true;
;

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
;
continue;
}
}
i =  i - 1;
;
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
;
i =  i + 1;
;
};
return nl;
};
void parseVar(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
struct Tok ft =  l->data[0];
;
if ((ft.isFunc==true)) {
if ((len(l)>1)) {
throwErr(&l->data[len(l)-1],"Not expecting {TOKEN} after function call.");
}
ft =  l->data[0];
;
int parsed =  true;
;
OUTPUT =  concatCPSTRING(concatCPSTRING(OUTPUT,ft.cont),";\n");
;
return ;
}
l =  parseStructType(l,elems);
;
int isEqual =  false;
;
int isStruct =  false;
;
char * currentType =  "";
;
ft =  l->data[0];
;
struct variable* v =  searchVar(ft.cont,elems);
;
int exists =  true;
;
char * ogName;
if ((v==null)) {
exists =  false;
;
v = memoryAlloc(sizeof(struct variable));
;
v->name = "";
v->type = "";
v->isConst = false;
v->isArray = false;
v->name =  ft.cont;
;
v->type =  "";
;
}
else {
ogName =  v->name;
;
}
if ((v->isConst==true)) {
throwErr(&ft,"Cannot set the value of const {TOKEN}.");
}
char * code =  "";
;
long int arrayLength =  0;
;
long int i =  1;
;
while ((i<len(l))) {
struct Tok t =  l->data[i];
;
if ((t.type==TOKEN_TYPE_SYNTAX)) {
if ((strcmp(t.cont, "=") == 0)) {
if ((strlen(currentType)>0)) {
struct string sct =  string(currentType);
;
sct.replace(&sct," ","");
v->type =  sct.str(&sct);
;
}
isEqual =  true;
;
i =  i + 1;
;
continue;
}
}
if ((isEqual==false)) {
if ((t.type!=TOKEN_TYPE_VAR)) {
if ((strcmp(t.cont, "*") != 0)) {
throwErr(&t,"Cannot use {TOKEN} as type for a variable.");
}
}
currentType =  concatCPSTRING(concatCPSTRING(currentType," "),t.cont);
;
}
else {
if ((strcmp(t.cont, "new") == 0)) {
isStruct =  true;
;
long int max =  i + 1;
;
if ((max>=len(l))) {
throwErr(&t,"Cannot initiate {TOKEN} struct without specifying struct name.");
}
max =  max + 1;
;
if ((max<len(l))) {
t =  l->data[i + 2];
;
throwErr(&t,"{TOKEN} not expected after initiating new struct.");
}
t =  l->data[i + 1];
;
if ((t.type!=TOKEN_TYPE_VAR)) {
throwErr(&t,"Cannot use {TOKEN} as a struct name.");
}
struct cStruct* s =  searchStruct(t.cont,elems);
;
if ((s==null)) {
throwErr(&t,"Unknown struct {TOKEN}.");
}
struct string vect =  getCType(s->name,elems);
;
char * vectStr =  vect.content;
;
code =  concatCPSTRING(concatCPSTRING("memoryAlloc(sizeof(",vectStr),"));\n");
;
v->type =  concatCPSTRING(s->name,"*");
;
NEXT_LINE =  declareStructMethods(v,s,elems);
;
break;
}
if ((t.isValue==false)) {
throwErr(&t,"Cannot use {TOKEN} as value in var declaration.");
}
char * tp =  getTypeFromToken(&t,true,elems);
;
if ((exists==true)) {
if ((compTypes(tp,v->type)==false)) {
throwErr(&t,concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING("Cannot use {TOKEN} (",tp),") as "),v->type),"."));
}
}
else {
if ((strlen(currentType)!=0)) {
if ((compTypes(tp,v->type)==false)) {
}
}
else {
if ((strlen(v->type)==0)) {
v->type =  tp;
;
}
else {
if ((compTypes(tp,v->type)==false)) {
throwErr(&t,concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING("Cannot use {TOKEN} (",tp),") as "),v->type),"."));
}
}
}
}
struct string ctc =  string(t.cont);
;
struct string cvt =  string(v->type);
;
if ((ctc.hasPrefix(&ctc,"{")==0)) {
if ((strlen(t.cont)>0)) {
code =  concatCPSTRING(concatCPSTRING(concatCPSTRING(code," "),t.cont),";\n");
;
break;
}
}
if (cvt.hasPrefix(&cvt,"[]")) {
struct string arrType =  getCType(v->type,elems);
;
arrType.trimRight(&arrType,1);
char * arrTypeStr =  arrType.str(&arrType);
;
code =  concatCPSTRING(concatCPSTRING("memoryAlloc(sizeof(",arrTypeStr),"));");
;
arrType.trimLeft(&arrType,6);
arrType.trimRight(&arrType,1);
char * elemTypeStr =  arrType.str(&arrType);
;
long int max =  i + 1;
;
if ((max!=len(l))) {
i =  i + 1;
;
struct Tok nt =  l->data[i];
;
if ((strcmp(nt.cont, "{") != 0)) {
throwErr(&l->data[i + 1],"{TOKEN} not expected after array initialization.");
}
struct string elemBahType =  string(v->type);
;
elemBahType.trimLeft(&elemBahType,2);
char * elemBahTypeStr =  elemBahType.str(&elemBahType);
;
i =  i + 1;
;
while ((i<len(l))) {
t =  l->data[i];
;
char * tt =  getTypeFromToken(&t,true,elems);
;
if ((compTypes(tt,elemBahTypeStr)==false)) {
throwErr(&t,concatCPSTRING(concatCPSTRING(concatCPSTRING("Cannot use {TOKEN} (",tt),") as "),elemBahTypeStr));
}
char * strArrayLength =  intToStr(arrayLength);
;
arrayLength =  arrayLength + 1;
;
if ((strcmp(tt, "cpstring") == 0)) {
t.cont =  concatCPSTRING(concatCPSTRING("__STR(",t.cont),")");
;
}
NEXT_LINE =  concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(NEXT_LINE,v->name),"->data["),strArrayLength),"] = "),t.cont),";\n");
;
i =  i + 1;
;
t =  l->data[i];
;
if ((strcmp(t.cont, ",") != 0)) {
if ((strcmp(t.cont, "}") == 0)) {
long int allocLength =  arrayLength;
;
if ((allocLength>50)) {
long int modAllocAmm =  allocLength % 50;
;
allocLength =  allocLength + modAllocAmm;
;
}
else {
allocLength =  50;
;
}
char * allocLengthStr =  intToStr(allocLength);
;
NEXT_LINE =  concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(v->name,"->data = memoryAlloc(sizeof("),elemTypeStr),") * "),allocLengthStr),");"),NEXT_LINE);
;
break;
}
else {
throwErr(&t,"Expected ',' got {TOKEN}.");
}
}
i =  i + 1;
;
};
}
char * strArrayLength =  intToStr(arrayLength);
;
NEXT_LINE =  concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING("\n",v->name),"->length = "),strArrayLength),";\n"),v->name),"->elemSize = sizeof("),elemTypeStr),");\n"),NEXT_LINE);
;
break;
}
isStruct =  true;
;
long int max =  i + 1;
;
if ((max!=len(l))) {
throwErr(&l->data[i + 1],"{TOKEN} not expected after struct initialization.");
}
struct cStruct* s =  searchStruct(v->type,elems);
;
NEXT_LINE =  declareStructMethods(v,s,elems);
;
code =  concatCPSTRING(concatCPSTRING(concatCPSTRING(code," "),t.cont),";\n");
;
}
i =  i + 1;
;
};
if ((exists==true)) {
if ((strlen(code)==0)) {
throwErr(&ft,"Cannot re-declare {TOKEN}.");
}
if ((strlen(currentType)>0)) {
struct Tok st =  l->data[1];
;
throwErr(&st,concatCPSTRING(concatCPSTRING("Cannot change the type of already declared var '",ft.cont),"' to {TOKEN}."));
}
if ((isStruct==false)) {
code =  concatCPSTRING(concatCPSTRING(v->name," = "),code);
;
}
else {
struct string cmpCode =  string(code);
;
cmpCode.trim(&cmpCode);
if ((cmpCode.hasPrefix(&cmpCode,"{")==0)) {
code =  concatCPSTRING(concatCPSTRING(v->name," = "),code);
;
}
}
if ((v->isArray==true)) {
struct string nLength =  string(v->name);
;
struct string n =  string(v->name);
;
i =  0;
;
while ((i<nLength.length)) {
char c =  nLength.charAt(&nLength,i);
;
if ((c==91)) {
break;
}
i =  i + 1;
;
};
nLength.trimLeft(&nLength,i + 1);
nLength.trimRight(&nLength,1);
char * nLengthStr =  nLength.str(&nLength);
;
i =  n.length;
;
while ((i>0)) {
char c =  n.charAt(&n,i);
;
if ((c==91)) {
break;
}
i =  i - 1;
;
};
long int tamm =  n.length - i;
;
n.trimRight(&n,tamm + 6);
char * nstr =  n.str(&n);
;
struct string elemType =  getCType(v->type,elems);
;
char * elemTypeStr =  elemType.str(&elemType);
;
code =  concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING("\n{\nlong nLength = ",nLengthStr),";\nif ("),nstr),"->length < nLength+1) {\nif ((nLength+1) % 50 == 0 || nLength == 0) {\nvoid * newPtr = GC_REALLOC("),nstr),"->data, (nLength+50)*sizeof("),elemTypeStr),"));\n"),nstr),"->data = newPtr;\n}\n"),code),"\n"),nstr),"->length = nLength+1;\n} else {\n"),code),"\n};\n};\n");
;
}
}
else {
if ((strlen(currentType)>0)) {
v->type =  currentType;
;
}
struct string vts =  string(v->type);
;
vts.replace(&vts," ","");
v->type =  vts.content;
;
if ((strlen(v->type)==0)) {
throwErr(&ft,"Cannot declare {TOKEN} without a type.");
}
char * vct;
if (vts.hasPrefix(&vts,"function(")) {
struct func* tmpfn =  parseFnType(vts);
;
struct string tmpfnRetCType =  getCType(tmpfn->returns->type,elems);
;
char * tmpfnArgsCType =  "";
;
long int j =  0;
;
while ((j<len(tmpfn->args))) {
struct variable* arg =  tmpfn->args->data[j];
;
struct string ct =  getCType(arg->type,elems);
;
tmpfnArgsCType =  concatCPSTRING(tmpfnArgsCType,ct.str(&ct));
;
j =  j + 1;
;
if ((j<len(tmpfn->args))) {
tmpfnArgsCType =  concatCPSTRING(tmpfnArgsCType,",");
;
}
};
vct =  concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(tmpfnRetCType.str(&tmpfnRetCType)," (*"),v->name),")("),tmpfnArgsCType),")");
;
}
else {
vct =  setCType(v,elems);
;
}
if ((strlen(code)>0)) {
code =  concatCPSTRING(concatCPSTRING(vct," = "),code);
;
}
else {
code =  vct;
;
}
array(struct variable*)* vars =  elems->vars;
;

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
;
}
OUTPUT =  concatCPSTRING(concatCPSTRING(OUTPUT,code),";\n");
;
};
char * parseFnHeader(char * prev,__BAH_ARR_TYPE_Tok l,long int* i,struct func* fn,struct Elems* elems){
long int j =  *i;
;
struct Tok ft =  l->data[j];
;
char * tpdf =  "";
;
if ((ft.type!=TOKEN_TYPE_VAR)) {
throwErr(&ft,"Cannot use {TOKEN} as function name.");
}
fn->name =  concatCPSTRING(prev,ft.cont);
;
array(struct variable*)* arguments = memoryAlloc(sizeof(array(struct variable*)));;

arguments->length = 0;
arguments->elemSize = sizeof(struct variable*);
char * code =  concatCPSTRING(fn->name,"(");
;
j =  j + 2;
;
struct Tok t =  l->data[j];
;
if ((strcmp(t.cont, ")") != 0)) {
while ((j<len(l))) {
t =  l->data[j];
;
if ((t.type!=TOKEN_TYPE_VAR)) {
throwErr(&t,"Cannot use {TOKEN} as argument name.");
}
char * argName =  t.cont;
;
j =  j + 1;
;
if ((j>=len(l))) {
throwErr(&t,"Cannot declare argument {TOKEN} without a type.");
}
t =  l->data[j];
;
char * argType =  t.cont;
;
j =  j + 1;
;
int isComa =  false;
;
while ((j<len(l))) {
t =  l->data[j];
;
isComa =  false;
;
if ((strcmp(t.cont, ",") != 0)) {
if ((strcmp(t.cont, ")") != 0)) {
argType =  concatCPSTRING(argType,t.cont);
;
}
else {
break;
}
}
else {
isComa =  true;
;
break;
}
j =  j + 1;
;
};
struct variable* argument = memoryAlloc(sizeof(struct variable));
;
argument->name = "";
argument->type = "";
argument->isConst = false;
argument->isArray = false;
argument->name =  argName;
;
argument->type =  argType;
;

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
;
struct string argCType =  getCType(argType,elems);
;
struct string cfrt =  string(argType);
;
char * newArgType =  argCType.str(&argCType);
;
if ((cfrt.hasPrefix(&cfrt,"[]")==1)) {
cfrt.trimLeft(&cfrt,2);
newArgType =  concatCPSTRING("__BAH_ARR_TYPE_",cfrt.str(&cfrt));
;
array(char *)* csatd =  compilerState.arrTypesDecl;
;
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
;
tpdf =  concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(tpdf,"typedef "),argCType.str(&argCType))," "),newArgType),";\n");
;
}
}
code =  concatCPSTRING(concatCPSTRING(concatCPSTRING(code,newArgType)," "),argName);
;
if ((isComa==true)) {
code =  concatCPSTRING(code,",");
;
}
else {
code =  concatCPSTRING(code,")");
;
break;
}
j =  j + 1;
;
};
}
else {
code =  concatCPSTRING(code,")");
;
}
j =  j + 1;
;
struct variable* returns = memoryAlloc(sizeof(struct variable));
;
returns->name = "";
returns->type = "";
returns->isConst = false;
returns->isArray = false;
returns->type =  "";
;
while ((j<len(l))) {
t =  l->data[j];
;
if ((strcmp(t.cont, "{") == 0)) {
break;
}
returns->type =  concatCPSTRING(returns->type,t.cont);
;
j =  j + 1;
;
};
if (strlen(returns->type)) {
struct string rts =  string(returns->type);
;
rts.replace(&rts," ","");
returns->type =  rts.content;
;
}
*i =  j;
;
returns->name =  fn->name;
;
fn->returns =  returns;
;
fn->args =  arguments;
;
struct string fnRetType =  getCType(returns->type,elems);
;
char * newFnRetType =  fnRetType.str(&fnRetType);
;
struct string cfrt =  string(returns->type);
;
if ((cfrt.hasPrefix(&cfrt,"[]")==1)) {
cfrt.trimLeft(&cfrt,2);
newFnRetType =  concatCPSTRING("__BAH_ARR_TYPE_",cfrt.str(&cfrt));
;
array(char *)* csatd =  compilerState.arrTypesDecl;
;
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
;
tpdf =  concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(tpdf,"typedef "),fnRetType.str(&fnRetType))," "),newFnRetType),";\n");
;
}
}
code =  concatCPSTRING(concatCPSTRING(concatCPSTRING(tpdf,newFnRetType)," "),code);
;
return code;
};
void parseStruct(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
struct cStruct* s = memoryAlloc(sizeof(struct cStruct));
;
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
;

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
;
array(struct func*)* methds =  s->methods;
;
if ((len(l)<4)) {
throwErr(&l->data[len(l)-1],"Cannot declare struct has such, please do 'struct <name> { <memberName>:<memberType> }'.");
}
struct Tok nameToken =  l->data[1];
;
long int i =  2;
;
int doesOutput =  true;
;
if ((strcmp(nameToken.cont, "!") == 0)) {
nameToken =  l->data[2];
;
i =  3;
;
doesOutput =  false;
;
}
if ((nameToken.type!=TOKEN_TYPE_VAR)) {
throwErr(&nameToken,"Cannot use {TOKEN} as struct name.");
}
struct cStruct* os =  searchStruct(nameToken.cont,elems);
;
if ((os!=null)) {
throwErr(&nameToken,"Struct {TOKEN} already exists.");
}
s->name =  nameToken.cont;
;
array(struct structMemb*)* members =  s->members;
;
currentCStruct =  s;
;
array(char *)* allMembs = memoryAlloc(sizeof(array(char *)));;

allMembs->length = 0;
allMembs->elemSize = sizeof(char *);
struct Tok st =  l->data[i];
;
if ((st.type==TOKEN_TYPE_KEYWORD)) {
if ((strcmp(st.cont, "extend") == 0)) {
i =  i + 1;
;
struct Tok extdSNameTk =  l->data[i];
;
i =  i + 1;
;
if ((extdSNameTk.type!=TOKEN_TYPE_VAR)) {
throwErr(&extdSNameTk,"Cannot use {TOKEN} as struct name.");
}
struct cStruct* extdS =  searchStruct(extdSNameTk.cont,elems);
;
if ((extdS==null)) {
throwErr(&extdSNameTk,"Struct {TOKEN} does not exist.");
}
array(struct structMemb*)* extdsmbs =  extdS->members;
;
long int j =  0;
;
while ((j<len(extdsmbs))) {
struct structMemb* em =  extdsmbs->data[j];
;
struct string cemt =  string(em->type);
;
char * membDeclStr;
if ((cemt.hasPrefix(&cemt,"function(")==1)) {
struct func* tmpfn =  parseFnType(cemt);
;
struct string tmpfnRetCType =  getCType(tmpfn->returns->type,elems);
;
char * tmpfnArgsCType =  "";
;
j =  0;
;
while ((j<len(tmpfn->args))) {
struct variable* arg =  tmpfn->args->data[j];
;
struct string ct =  getCType(arg->type,elems);
;
tmpfnArgsCType =  concatCPSTRING(tmpfnArgsCType,ct.str(&ct));
;
j =  j + 1;
;
if ((j<len(tmpfn->args))) {
tmpfnArgsCType =  concatCPSTRING(tmpfnArgsCType,",");
;
}
};
membDeclStr =  concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(tmpfnRetCType.str(&tmpfnRetCType)," (*"),em->name),")("),tmpfnArgsCType),")");
;
}
else {
struct string membDecl =  getCType(em->type,elems);
;
membDecl.append(&membDecl," ");
membDecl.append(&membDecl,em->name);
membDeclStr =  membDecl.content;
;
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
;

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
;
j =  j + 1;
;
};
}
else {
throwErr(&st,"Cannot use keyword {TOKEN} in struct declaration.");
}
}
struct Tok braceTk =  l->data[i];
;
i =  i + 1;
;
if ((strcmp(braceTk.cont, "{") != 0)) {
throwErr(&braceTk,"Cannot use {TOKEN} in struct declaration.");
}
char * OOUT =  __STR(OUTPUT);
;
char * nextLine =  "";
;
while ((i<len(l))) {
struct Tok t =  l->data[i];
;
long int max =  i + 2;
;
if ((max>=len(l))) {
if ((t.type==TOKEN_TYPE_ENCL)) {
if ((strcmp(t.cont, "}") == 0)) {
break;
}
}
throwErr(&l->data[len(l)-1],"Not enough argument in member declaration, ending by {TOKEN}.");
}
struct structMemb* memb = memoryAlloc(sizeof(struct structMemb));
;
memb->name = "";
memb->type = "";
memb->isConst = false;
memb->isArray = false;
memb->def = "";
memb->isFn = false;
memb->from = "";
if ((t.type!=TOKEN_TYPE_VAR)) {
throwErr(&t,"Cannot use {TOKEN} as member name.");
}
memb->name =  t.cont;
;
long int ii =  0;
;
while ((ii<len(members))) {
struct structMemb* m =  members->data[ii];
;
if ((strcmp(m->name, memb->name) == 0)) {
throwErr(&t,"Member {TOKEN} has already been declared.");
}
ii =  ii + 1;
;
};
i =  i + 1;
;
t =  l->data[i];
;
if ((strcmp(t.cont, ":") != 0)) {
if ((strcmp(t.cont, "(") != 0)) {
throwErr(&t,"Member name should be followed by ':' not {TOKEN}.");
}
else {
char * fnPrefix =  concatCPSTRING(s->name,"__");
;
struct func* fn = memoryAlloc(sizeof(struct func));
;
fn->name = "";
fn->args = memoryAlloc(sizeof(array(struct variable*)));
            fn->args->length = 0;
            fn->args->elemSize = sizeof(struct variable*);
            fn->isBinding = false;
fn->from = "";
fn->file = "";
fn->line = 1;
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));;

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
long int j =  i-1;
;
while ((j<len(l))) {
t =  l->data[j];
;
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
;
if ((j==i)) {
t.type =  TOKEN_TYPE_VAR;
;
t.cont =  "this";
;
t.isValue =  true;
;

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
;
t.type =  TOKEN_TYPE_VAR;
;
t.cont =  concatCPSTRING(s->name,"*");
;
t.isValue =  true;
;

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
;
struct Tok nt =  l->data[j + 1];
;
if ((strcmp(nt.cont, ")") != 0)) {
t.type =  TOKEN_TYPE_SYNTAX;
;
t.cont =  ",";
;
t.isValue =  false;
;

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
;
}
}
j =  j + 1;
;
};
i =  i - 1;
;
long int nli =  0;
;
char * code =  parseFnHeader(fnPrefix,nl,&nli,fn,elems);
;
i =  i + nli;
;
i =  i - 2;
;
struct variable* returns =  fn->returns;
;
array(struct variable*)* arguments =  fn->args;
;
fn->from =  s->name;
;
code =  concatCPSTRING(code,"{\n");
;
struct Elems* fnElems = memoryAlloc(sizeof(struct Elems));
;
fnElems->vars = memoryAlloc(sizeof(array(struct variable*)));
            fnElems->vars->length = 0;
            fnElems->vars->elemSize = sizeof(struct variable*);
            fnElems->structs = memoryAlloc(sizeof(array(struct cStruct*)));
            fnElems->structs->length = 0;
            fnElems->structs->elemSize = sizeof(struct cStruct*);
            fnElems->types = memoryAlloc(sizeof(array(char *)));
            fnElems->types->length = 0;
            fnElems->types->elemSize = sizeof(char *);
            fnElems->fns = memoryAlloc(sizeof(array(struct func*)));
            fnElems->fns->length = 0;
            fnElems->fns->elemSize = sizeof(struct func*);
            append(fnElems->vars,elems->vars);
append(fnElems->structs,elems->structs);
append(fnElems->types,elems->types);
append(fnElems->fns,elems->fns);
array(struct variable*)* vs =  fnElems->vars;
;
j =  0;
;
while ((j<len(arguments))) {
struct variable* a =  arguments->data[j];
;

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
;
j =  j + 1;
;
};
fnElems->vars =  vs;
;
array(struct func*)* fns =  elems->fns;
;

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
;
array(struct Tok)* tokens = memoryAlloc(sizeof(array(struct Tok)));;

tokens->length = 0;
tokens->elemSize = sizeof(struct Tok);
long int nbBraces =  1;
;
t =  l->data[i];
;
if ((strcmp(t.cont, "{") == 0)) {
i =  i + 1;
;
}
while ((i<len(l))) {
t =  l->data[i];
;
if ((strcmp(t.cont, "{") == 0)) {
nbBraces =  nbBraces + 1;
;
}
else if ((strcmp(t.cont, "}") == 0)) {
nbBraces =  nbBraces - 1;
;
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
;
i =  i + 1;
;
};
if ((len(tokens)==0)) {
code =  concatCPSTRING(code,"};\n");
;
}
else {
OUTPUT =  "";
;
currentFn =  fn;
;
parseLines(tokens,fnElems);
currentFn =  null;
;
if ((strlen(fn->returns->type)>0)) {
if ((fn->returned==false)) {
throwErr(&l->data[len(l)-1],concatCPSTRING(concatCPSTRING("Function '",fn->name),"' is not returned."));
}
}
code =  concatCPSTRING(concatCPSTRING(code,OUTPUT),"};\n");
;
}
if ((doesOutput==true)) {
nextLine =  concatCPSTRING(nextLine,code);
;
}
struct func* mfn = memoryAlloc(sizeof(struct func));
;
mfn->name = "";
mfn->args = memoryAlloc(sizeof(array(struct variable*)));
            mfn->args->length = 0;
            mfn->args->elemSize = sizeof(struct variable*);
            mfn->isBinding = false;
mfn->from = "";
mfn->file = "";
mfn->line = 1;
mfn->args =  fn->args;
;
mfn->name =  fn->name;
;
mfn->returns =  fn->returns;
;
struct string sfn =  string(mfn->name);
;
sfn.trimLeft(&sfn,strlen(fnPrefix));
mfn->name =  sfn.content;
;

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
;
struct string mthdDecl =  getCType(fn->returns->type,elems);
;
mthdDecl.append(&mthdDecl,"(*");
mthdDecl.append(&mthdDecl,mfn->name);
mthdDecl.append(&mthdDecl,")(");
j =  0;
;
while ((j<len(arguments))) {
struct variable* a =  arguments->data[j];
;
struct string tp =  getCType(a->type,elems);
;
tp.append(&tp," ");
tp.append(&tp,a->name);
max =  len(arguments) - 1;
;
if ((j!=max)) {
tp.append(&tp,",");
}
char * tpstr =  tp.str(&tp);
;
mthdDecl.append(&mthdDecl,tpstr);
j =  j + 1;
;
};
mthdDecl.append(&mthdDecl,")");
char * mthdDeclStr =  mthdDecl.content;
;

{
long nLength = len(allMembs);
if (allMembs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = GC_REALLOC(allMembs->data, (nLength+50)*sizeof(char *));
allMembs->data = newPtr;
}
allMembs->data[len(allMembs)] =  mthdDeclStr;

allMembs->length = nLength+1;
} else {
allMembs->data[len(allMembs)] =  mthdDeclStr;

};
};
;
i =  i + 1;
;
continue;
}
}
i =  i + 1;
;
char * mbmType =  "";
;
long int currentLine =  t.line;
;
while ((i<len(l))) {
t =  l->data[i];
;
if ((strcmp(t.cont, "=") == 0)) {
i =  i - 1;
;
break;
}
if ((t.line!=currentLine)) {
i =  i - 1;
;
break;
}
mbmType =  concatCPSTRING(mbmType,t.cont);
;
i =  i + 1;
;
};
memb->type =  mbmType;
;
i =  i + 1;
;
t =  l->data[i];
;
if ((i<len(l))) {
if ((strcmp(t.cont, "=") == 0)) {
i =  i + 1;
;
t =  l->data[i];
;
if ((t.isValue==false)) {
throwErr(&t,"Cannot use {TOKEN} as default value for member.");
}
char * tt =  getTypeFromToken(&t,true,elems);
;
if ((compTypes(tt,memb->type)==false)) {
throwErr(&t,concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING("Cannot use {TOKEN} (",tt),") as "),memb->type)," for member."));
}
memb->def =  t.cont;
;
}
else {
i =  i - 1;
;
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
;
char * membDeclStr;
struct string cmt =  string(memb->type);
;
if ((cmt.hasPrefix(&cmt,"function(")==1)) {
struct func* tmpfn =  parseFnType(cmt);
;
struct string tmpfnRetCType =  getCType(tmpfn->returns->type,elems);
;
char * tmpfnArgsCType =  "";
;
long int j =  0;
;
while ((j<len(tmpfn->args))) {
struct variable* arg =  tmpfn->args->data[j];
;
struct string ct =  getCType(arg->type,elems);
;
tmpfnArgsCType =  concatCPSTRING(tmpfnArgsCType,ct.str(&ct));
;
j =  j + 1;
;
if ((j<len(tmpfn->args))) {
tmpfnArgsCType =  concatCPSTRING(tmpfnArgsCType,",");
;
}
};
membDeclStr =  concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(tmpfnRetCType.str(&tmpfnRetCType)," (*"),memb->name),")("),tmpfnArgsCType),")");
;
}
else {
struct string membDecl =  getCType(memb->type,elems);
;
membDecl.append(&membDecl," ");
membDecl.append(&membDecl,memb->name);
membDeclStr =  membDecl.content;
;
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
;
i =  i + 1;
;
};
s->members =  members;
;
if ((doesOutput==true)) {
OUTPUT =  OOUT;
;
NEXT_LINE =  nextLine;
;
char * code =  concatCPSTRING(concatCPSTRING("struct ",s->name)," {\n");
;
i =  0;
;
while ((i<len(allMembs))) {
char * m =  allMembs->data[i];
;
code =  concatCPSTRING(concatCPSTRING(code,m),";\n");
;
i =  i + 1;
;
};
code =  concatCPSTRING(code,"};\n");
;
OUTPUT =  concatCPSTRING(OUTPUT,code);
;
}
};
void parseDefine(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
if ((len(l)<3)) {
throwErr(&l->data[len(l)-1],"Invalid usage of define, cannot end on {TOKEN}.");
}
struct Tok ft =  l->data[1];
;
struct Tok st =  l->data[2];
;
long int i =  1;
;
int doesOutput =  true;
;
if ((strcmp(ft.cont, "!") == 0)) {
ft =  l->data[2];
;
st =  l->data[3];
;
i =  2;
;
doesOutput =  false;
;
}
if ((strcmp(st.cont, "(") == 0)) {
struct func* fn = memoryAlloc(sizeof(struct func));
;
fn->name = "";
fn->args = memoryAlloc(sizeof(array(struct variable*)));
            fn->args->length = 0;
            fn->args->elemSize = sizeof(struct variable*);
            fn->isBinding = false;
fn->from = "";
fn->file = "";
fn->line = 1;
char * code =  parseFnHeader("",l,&i,fn,elems);
;
array(struct func*)* fns =  elems->fns;
;
fn->isBinding =  true;
;

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
;
if ((doesOutput==true)) {
OUTPUT =  concatCPSTRING(concatCPSTRING(OUTPUT,code),";\n");
;
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
;
char * cTypeNewTypeStr =  cTypeNewType.str(&cTypeNewType);
;
if ((doesOutput==true)) {
OUTPUT =  concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(OUTPUT,"typedef "),cTypeNewTypeStr)," "),ft.cont),";\n");
;
}
array(char *)* tps =  elems->types;
;

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
;
}
};
void parseClib(__BAH_ARR_TYPE_Tok line){
array(char *)* clibs =  compilerState.cLibs;
;
long int i =  1;
;
while ((i<len(line))) {
struct Tok t =  line->data[i];
;
if ((t.type!=TOKEN_TYPE_STR)) {
throwErr(&t,"Cannot use {TOKEN} as C library name.");
}
struct string cc =  string(t.cont);
;
cc.trimLeft(&cc,1);
cc.trimRight(&cc,1);
char * ccstr =  cc.str(&cc);
;
int found =  false;
;
long int j =  0;
;
while ((j<len(clibs))) {
char * l =  clibs->data[j];
;
if ((strcmp(l, ccstr) == 0)) {
found =  true;
;
break;
}
j =  j + 1;
;
};
if ((found==true)) {
i =  i + 1;
;
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
;
i =  i + 1;
;
};
};
void parseConst(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
l =  parseCast(l,elems);
;
if ((len(l)!=4)) {
throwErr(&l->data[0],"Invalid usage of {TOKEN}, must be 'const <constName> = <constValue>'. ");
}
struct Tok vart =  l->data[1];
;
struct Tok equt =  l->data[2];
;
struct Tok valt =  l->data[3];
;
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
;
v->name = "";
v->type = "";
v->isConst = false;
v->isArray = false;
v->isConst =  true;
;
v->name =  vart.cont;
;
v->type =  getTypeFromToken(&valt,true,elems);
;
array(struct variable*)* vars =  elems->vars;
;

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
;
OUTPUT =  concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(OUTPUT,"#define "),v->name)," "),valt.cont),"\n");
;
};
void parseReturn(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
if ((len(l)>2)) {
throwErr(&l->data[0],"Invalid usage of {TOKEN}, must be 'return <returnValue>'");
}
if ((currentFn==null)) {
throwErr(&l->data[0],"Cannot return a value outside of a function.");
}
char * rv =  "";
;
if ((len(l)==1)) {
if ((strlen(currentFn->returns->type)!=0)) {
throwErr(&l->data[0],concatCPSTRING(concatCPSTRING("Cannot return nothing as ",currentFn->returns->type),"."));
}
}
else {
struct Tok rvt =  l->data[1];
;
if ((rvt.isValue==false)) {
throwErr(&rvt,"Must be a value, not {TOKEN}.");
}
rv =  rvt.cont;
;
char * tt =  getTypeFromToken(&rvt,true,elems);
;
if ((compTypes(tt,currentFn->returns->type)==false)) {
throwErr(&rvt,concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING("Cannot return {TOKEN} (",tt),") as "),currentFn->returns->type),"."));
}
}
if ((compilerState.isBranch==false)) {
currentFn->returned =  true;
;
}
OUTPUT =  concatCPSTRING(concatCPSTRING(concatCPSTRING(OUTPUT,"return "),rv),";\n");
;
};
void parseIf(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
if ((len(l)<4)) {
struct Tok ft =  l->data[0];
;
throwErr(&ft,"Invalid usage of {TOKEN}, must be 'if <condition> {<code>}'");
}
struct Tok condt =  l->data[1];
;
if ((strcmp(condt.bahType, "bool") != 0)) {
if ((strcmp(condt.bahType, "int") != 0)) {
throwErr(&condt,"Cannot use {TOKEN} as condition in if statement.");
}
}
struct Tok t =  l->data[2];
;
if ((strcmp(t.cont, "{") != 0)) {
throwErr(&t,"Expected '{' not {TOKEN} after condtition in if statement.");
}
array(struct Tok)* tokens = memoryAlloc(sizeof(array(struct Tok)));;

tokens->length = 0;
tokens->elemSize = sizeof(struct Tok);
long int max =  len(l) - 1;
;
long int i =  3;
;
while ((i<max)) {
t =  l->data[i];
;

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
;
i =  i + 1;
;
};
OUTPUT =  concatCPSTRING(concatCPSTRING(concatCPSTRING(OUTPUT,"if ("),condt.cont),") {\n");
;
struct Elems* ifElems =  dupElems(elems);
;
int oldIB =  compilerState.isBranch;
;
compilerState.isBranch =  true;
;
parseLines(tokens,ifElems);
compilerState.isBranch =  oldIB;
;
OUTPUT =  concatCPSTRING(OUTPUT,"}\n");
;
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
;
OUTPUT =  concatCPSTRING(OUTPUT,"else ");
;
if ((strcmp(ft.cont, "if") == 0)) {
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));;

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
long int i =  1;
;
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
;
i =  i + 1;
;
};
parseIf(memory,elems);
prevLine =  LINE_TYPE_IF;
;
}
else {
if ((strcmp(ft.cont, "{") != 0)) {
throwErr(&ft,"Expected 'if' or '{' not {TOKEN}.");
}
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));;

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
long int max =  len(l) - 1;
;
long int i =  2;
;
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
;
i =  i + 1;
;
};
OUTPUT =  concatCPSTRING(OUTPUT,"{\n");
;
struct Elems* ifElems =  dupElems(elems);
;
int oldIB =  compilerState.isBranch;
;
compilerState.isBranch =  true;
;
parseLines(memory,ifElems);
compilerState.isBranch =  oldIB;
;
OUTPUT =  concatCPSTRING(OUTPUT,"}\n");
;
}
};
void parseFor(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
if ((len(l)<4)) {
throwErr(&l->data[0],"Invalid usage of {TOKEN}.");
}
struct Tok condt =  l->data[1];
;
if ((strcmp(condt.bahType, "bool") != 0)) {
if ((strcmp(condt.bahType, "int") != 0)) {
throwErr(&condt,"Cannot use {TOKEN} as condition in for statement.");
}
}
struct Tok t =  l->data[2];
;
if ((strcmp(t.cont, "{") != 0)) {
throwErr(&t,"Expected '{' not {TOKEN} after condtition in for statement.");
}
array(struct Tok)* tokens = memoryAlloc(sizeof(array(struct Tok)));;

tokens->length = 0;
tokens->elemSize = sizeof(struct Tok);
long int max =  len(l) - 1;
;
long int i =  3;
;
while ((i<max)) {
t =  l->data[i];
;

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
;
i =  i + 1;
;
};
OUTPUT =  concatCPSTRING(concatCPSTRING(concatCPSTRING(OUTPUT,"while ("),condt.cont),") {\n");
;
struct Elems* ifElems =  dupElems(elems);
;
int oldIB =  compilerState.isBranch;
;
int oldIF =  compilerState.isFor;
;
compilerState.isBranch =  true;
;
compilerState.isFor =  true;
;
parseLines(tokens,ifElems);
compilerState.isFor =  oldIF;
;
compilerState.isBranch =  oldIB;
;
OUTPUT =  concatCPSTRING(OUTPUT,"};\n");
;
};
void parseForOp(__BAH_ARR_TYPE_Tok l){
struct Tok ft =  l->data[0];
;
if ((compilerState.isFor==false)) {
throwErr(&ft,"Cannot {TOKEN} outside of for statement.");
}
if ((len(l)!=1)) {
throwErr(&ft,"Nothing expected after {TOKEN}.");
}
OUTPUT =  concatCPSTRING(concatCPSTRING(OUTPUT,ft.cont),";\n");
;
};
__BAH_ARR_TYPE_Tok prePross(__BAH_ARR_TYPE_Tok line,struct Elems* elems){
array(struct Tok)* fl = memoryAlloc(sizeof(array(struct Tok)));;

fl->length = 0;
fl->elemSize = sizeof(struct Tok);
long int i =  0;
;
while ((i<len(line))) {
struct Tok t =  line->data[i];
;
if ((strcmp(t.cont, "{") == 0)) {
struct Tok nt =  line->data[i + 1];
;
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
;
i =  i + 1;
;
};
array(struct Tok)* sl = memoryAlloc(sizeof(array(struct Tok)));;

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
;
i =  i + 1;
;
};
fl =  parseStructVars(fl,elems);
;
fl =  parseFnCall(fl,elems);
;
fl =  parseArrayVars(fl,elems);
;
fl =  parseArrayType(fl,elems);
;
fl =  parseCast(fl,elems);
;
fl =  parseOperations(fl,elems);
;
fl =  parseBool(fl,elems);
;
if ((len(sl)>0)) {
i =  0;
;
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
;
i =  i + 1;
;
};
}
return fl;
};
void parseFnDeclare(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
long int i =  0;
;
struct func* fn = memoryAlloc(sizeof(struct func));
;
fn->name = "";
fn->args = memoryAlloc(sizeof(array(struct variable*)));
            fn->args->length = 0;
            fn->args->elemSize = sizeof(struct variable*);
            fn->isBinding = false;
fn->from = "";
fn->file = "";
fn->line = 1;
struct Tok ft =  l->data[0];
;
char * code =  parseFnHeader("",l,&i,fn,elems);
;
fn->line =  ft.line;
;
fn->file =  compilerState.currentFile;
;
struct func* ogFn =  searchFunc(fn->name,elems,false);
;
if ((ogFn!=null)) {
if ((ogFn->isBinding==false)) {
char * lineStr =  intToStr(ogFn->line);
;
throwErr(&ft,concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING("Cannot redeclare function {TOKEN}, previous declaration: ",ogFn->file),":"),lineStr),"."));
}
}
struct variable* returns =  fn->returns;
;
array(struct variable*)* arguments =  fn->args;
;
code =  concatCPSTRING(code,"{\n");
;
OUTPUT =  concatCPSTRING(OUTPUT,code);
;
struct Elems* fnElems =  dupElems(elems);
;
array(struct variable*)* vs =  fnElems->vars;
;
long int j =  0;
;
while ((j<len(arguments))) {
struct variable* a =  arguments->data[j];
;

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
;
j =  j + 1;
;
};
fnElems->vars =  vs;
;
if ((ogFn!=null)) {
ogFn->isBinding =  false;
;
ogFn =  fn;
;
}
else {
array(struct func*)* fns =  elems->fns;
;

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
;
}
array(struct Tok)* tokens = memoryAlloc(sizeof(array(struct Tok)));;

tokens->length = 0;
tokens->elemSize = sizeof(struct Tok);
i =  i + 1;
;
long int max =  len(l)-1;
;
while ((i<max)) {
struct Tok t =  l->data[i];
;

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
;
i =  i + 1;
;
};
if ((len(tokens)==0)) {
OUTPUT =  concatCPSTRING(OUTPUT,"};\n");
;
return ;
}
currentFn =  fn;
;
parseLines(tokens,fnElems);
currentFn =  null;
;
if ((strlen(fn->returns->type)>0)) {
if ((fn->returned==false)) {
throwErr(&l->data[len(l)-1],concatCPSTRING(concatCPSTRING("Function '",fn->name),"' is not returned."));
}
}
OUTPUT =  concatCPSTRING(OUTPUT,"};\n");
;
};
void parseLine(__BAH_ARR_TYPE_Tok line,struct Elems* elems){
if ((len(line)==0)) {
return ;
}
line =  parsePointers(line);
;
lineType ltp =  getLineType(line);
;
int parsed =  false;
;
if ((ltp==LINE_TYPE_INCLUDE)) {
parsed =  true;
;
parseInclude(line,elems);
}
else if ((ltp==LINE_TYPE_DEFINE)) {
parsed =  true;
;
parseDefine(line,elems);
}
else if ((ltp==LINE_TYPE_CLIB)) {
parsed =  true;
;
parseClib(line);
}
else if ((ltp==LINE_TYPE_STRUCT)) {
parsed =  true;
;
parseStruct(line,elems);
}
else if ((ltp==LINE_TYPE_CONST)) {
parsed =  true;
;
parseConst(line,elems);
}
else if ((ltp==LINE_TYPE_MACRO)) {
return ;
}
else if ((ltp!=LINE_TYPE_FN_DECL)) {
line =  prePross(line,elems);
;
}
if ((ltp==LINE_TYPE_VAR)) {
parsed =  true;
;
parseVar(line,elems);
}
else if ((ltp==LINE_TYPE_FN_CALL)) {
if ((len(line)>1)) {
throwErr(&line->data[len(line)-1],"Not expecting {TOKEN} after function call.");
}
struct Tok ft =  line->data[0];
;
parsed =  true;
;
OUTPUT =  concatCPSTRING(concatCPSTRING(OUTPUT,ft.cont),";\n");
;
}
else if ((ltp==LINE_TYPE_FN_DECL)) {
parsed =  true;
;
parseFnDeclare(line,elems);
}
else if ((ltp==LINE_TYPE_RETURN)) {
parsed =  true;
;
parseReturn(line,elems);
}
else if ((ltp==LINE_TYPE_IF)) {
parsed =  true;
;
parseIf(line,elems);
}
else if ((ltp==LINE_TYPE_ELSE)) {
parsed =  true;
;
parseElse(line,elems);
}
else if ((ltp==LINE_TYPE_FOR)) {
parsed =  true;
;
parseFor(line,elems);
}
else if ((ltp==LINE_TYPE_FOR_OPERATOR)) {
parsed =  true;
;
parseForOp(line);
}
if ((parsed==false)) {
struct Tok ft =  line->data[0];
;
throwErr(&ft,"{TOKEN} not expected.");
}
if ((strlen(NEXT_LINE)>0)) {
OUTPUT =  concatCPSTRING(OUTPUT,NEXT_LINE);
;
NEXT_LINE =  "";
;
}
prevLine =  ltp;
;
};
void parseLines(__BAH_ARR_TYPE_Tok tokens,struct Elems* elems){
if ((len(tokens)==0)) {
return ;
}
array(struct Tok)* line = memoryAlloc(sizeof(array(struct Tok)));;

line->length = 0;
line->elemSize = sizeof(struct Tok);
struct Tok ft =  tokens->data[0];
;
long int currentLine =  ft.line;
;
long int nbEncl =  0;
;
long int i =  0;
;
while ((i<len(tokens))) {
struct Tok t =  tokens->data[i];
;
if ((t.type==TOKEN_TYPE_ENCL)) {
if ((strcmp(t.cont, "(") == 0)) {
nbEncl =  nbEncl + 1;
;
}
else if ((strcmp(t.cont, ")") == 0)) {
nbEncl =  nbEncl - 1;
;
}
else if ((strcmp(t.cont, "{") == 0)) {
nbEncl =  nbEncl + 1;
;
}
else if ((strcmp(t.cont, "}") == 0)) {
nbEncl =  nbEncl - 1;
;
}
else if ((strcmp(t.cont, "[") == 0)) {
nbEncl =  nbEncl + 1;
;
}
else if ((strcmp(t.cont, "]") == 0)) {
nbEncl =  nbEncl - 1;
;
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
;
struct Tok pt =  tokens->data[i-1];
;
currentLine =  pt.line;
;
}
else {
currentLine =  t.line;
;
}
parseLine(line,elems);
clear(line);
if ((t.type==TOKEN_TYPE_ENCL)) {
i =  i + 1;
;
continue;
}
}
else if ((strcmp(t.cont, ";") == 0)) {
currentLine =  t.line;
;
parseLine(line,elems);
clear(line);
i =  i + 1;
;
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
;
i =  i + 1;
;
};
if ((len(line)>0)) {
if ((nbEncl==0)) {
parseLine(line,elems);
clear(line);
}
else {
ft =  line->data[len(line)-1];
;
throwErr(&ft,"Missing closing token, line ending by {TOKEN}.");
}
}
};
void main(__BAH_ARR_TYPE_cpstring args){
struct flags flags =  {};
;
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
flags.addString(&flags,"o","Name of the file to output.");
flags.addBool(&flags,"c","Translate bah file to C instead of compiling it.");
flags.parse(&flags,args);
 {};
;
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
            char * fileName =  args->data[1];
;
compilerState.currentFile =  fileName;
;
struct fileMap fm =  {};
;
fm.open = fileMap__open;
fm.isValid = fileMap__isValid;
fm.close = fileMap__close;
char * f =  fm.open(&fm,fileName);
;
long int startTime =  getTimeUnix();
;
array(struct Tok)* tokens =  lexer(f);
;
fm.close(&fm);
if ((len(tokens)==0)) {
panic(concatCPSTRING(concatCPSTRING("File '",fileName),"' not recognized."));
}
struct Elems* elems = memoryAlloc(sizeof(struct Elems));
;
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
panic(concatCPSTRING(concatCPSTRING("Could not find std-libs, please check '",BAH_DIR),"'"));
}
parseLines(tokens,elems);
if ((flags.isSet(&flags,"o")==1)) {
fileName =  flags.get(&flags,"o");
;
}
else {
struct string outFileName =  string(fileName);
;
outFileName.trimRight(&outFileName,4);
fileName =  outFileName.str(&outFileName);
;
}
if ((flags.isSet(&flags,"c")==0)) {
char * randFileName =  "TMP_C_FILE_";
;
long int i =  0;
;
while ((i<9)) {
long int nb =  randomInRange(0,99);
;
char * s =  intToStr(nb);
;
randFileName =  concatCPSTRING(randFileName,s);
;
i =  i + 1;
;
};
randFileName =  concatCPSTRING(randFileName,".c");
;
struct fileStream fs =  {};
;
fs.isValid = fileStream__isValid;
fs.open = fileStream__open;
fs.close = fileStream__close;
fs.getSize = fileStream__getSize;
fs.readContent = fileStream__readContent;
fs.rewind = fileStream__rewind;
fs.getChar = fileStream__getChar;
fs.createFile = fileStream__createFile;
fs.writeFile = fileStream__writeFile;
fs.open(&fs,randFileName,"w");
fs.writeFile(&fs,OUTPUT);
fs.close(&fs);
char * gccArgs =  concatCPSTRING(concatCPSTRING(concatCPSTRING("gcc ./",randFileName)," -w -o "),fileName);
;
array(char *)* cLibs =  compilerState.cLibs;
;
i =  0;
;
while ((i<len(cLibs))) {
char * l =  cLibs->data[i];
;
gccArgs =  concatCPSTRING(concatCPSTRING(gccArgs," -"),l);
;
i =  i + 1;
;
};
struct command cmd =  command(gccArgs);
;
char * gccOut =  cmd.run(&cmd);
;
removeFile(randFileName);
if ((strlen(gccOut)>0)) {
println("\e[1;31m[GCC-ERROR]\e[0m\nCould not compiled.");
exit(1);
}
}
else {
if ((flags.isSet(&flags,"o")==0)) {
fileName =  concatCPSTRING(fileName,".c");
;
}
char * gccArgs =  concatCPSTRING(concatCPSTRING("gcc ./",fileName)," -w ");
;
array(char *)* cLibs =  compilerState.cLibs;
;
long int i =  0;
;
while ((i<len(cLibs))) {
char * l =  cLibs->data[i];
;
gccArgs =  concatCPSTRING(concatCPSTRING(gccArgs," -"),l);
;
i =  i + 1;
;
};
OUTPUT =  concatCPSTRING(concatCPSTRING(concatCPSTRING("//COMPILE WITH: '",gccArgs),"'\n"),OUTPUT);
;
struct fileStream fs =  {};
;
fs.isValid = fileStream__isValid;
fs.open = fileStream__open;
fs.close = fileStream__close;
fs.getSize = fileStream__getSize;
fs.readContent = fileStream__readContent;
fs.rewind = fileStream__rewind;
fs.getChar = fileStream__getChar;
fs.createFile = fileStream__createFile;
fs.writeFile = fileStream__writeFile;
fs.open(&fs,fileName,"w");
fs.writeFile(&fs,OUTPUT);
fs.close(&fs);
}
long int totalTime =  getTimeUnix() - startTime;
;
println(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING("\e[1;32mDone. (",intToStr(totalLines))," lines compiled in "),intToStr(totalTime / 1000000)),"ms)"));
};
