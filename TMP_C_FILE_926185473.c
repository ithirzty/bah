#include<signal.h>
#include<gc.h>
#include<sys/mman.h>
#include<stdlib.h>
#include<stdio.h>
#include<dirent.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<math.h>
#define true 1
#define false 0
#define noCheck(v) v
#define array(type)	\
    struct{	\
        type *data; \
        long int length; \
		long int elemSize; \
    }
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
#define SIZE_OF_INT 8
#define SIZE_OF_CHAR 1
#define SIZE_OF_INT32 4
#define SIZE_OF_FLOAT32 4
#define SIZE_OF_FLOAT 8
void * memoryAlloc(long int s);
void  destroy(void *a);
void  clear(void *a);
void  append(void *a,void *b);
void * memoryRealloc(void *p,long int s);
void * sharedMemory(long int size);
long int  len(void *a);
char *  concatCPSTRING(char * a,char * b);
char *  __STR(char * a);
#define null (void *)0
#define true (int )1
#define false (int )0
char *  charToString(char c);
long int  isUpper(char c);
long int  isLower(char c);
long int  isLetter(char s);
long int  isNumber(char c);
long int  isAlphaNumeric(char s);
long int  isSpace(char c);
struct string  string(char * s);
struct string  intToString(long int i);
char *  intToStr(long int i);
char *  stdinput(long int len);
void  print(char * s);
void  println(char * s);
void  panic(char * e);
long int  fileExists(char * path);
#define FLAG_TYPE_CPSTRING 0
#define FLAG_TYPE_INT 1
#define FLAG_TYPE_FLOAT 2
#define FLAG_TYPE_BOOL 3
typedef long int tokenType;
#define TOKEN_TYPE_INT (tokenType )0
#define TOKEN_TYPE_FLOAT (tokenType )1
#define TOKEN_TYPE_VAR (tokenType )2
#define TOKEN_TYPE_ENCL (tokenType )3
#define TOKEN_TYPE_SEP (tokenType )4
#define TOKEN_TYPE_STR (tokenType )5
#define TOKEN_TYPE_KEYWORD (tokenType )6
#define TOKEN_TYPE_CHAR (tokenType )7
#define TOKEN_TYPE_BOOL (tokenType )8
#define TOKEN_TYPE_SYNTAX (tokenType )10
void  throwErr(void *tp,char * format);
typedef long int lineType;
#define LINE_TYPE_INCLUDE (lineType )0
#define LINE_TYPE_DEFINE (lineType )1
#define LINE_TYPE_CONST (lineType )2
#define LINE_TYPE_VAR (lineType )3
#define LINE_TYPE_FN_DECL (lineType )4
#define LINE_TYPE_FN_CALL (lineType )5
#define LINE_TYPE_STRUCT (lineType )6
struct string {
char * content;
long int length;
void (*set)(struct string*,char * );
void (*append)(struct string*,char * );
void (*prepend)(struct string*,char * );
char (*charAt)(struct string*,long int );
long int (*compare)(struct string*,char * );
char * (*str)(struct string*);
void (*replace)(struct string*,char * ,char * );
long int (*count)(struct string*,char * );
long int (*hasPrefix)(struct string*,char * );
long int (*hasSuffix)(struct string*,char * );
void (*trim)(struct string*);
void (*trimLeft)(struct string*,long int );
void (*trimRight)(struct string*,long int );
};
void  string__set(void *__BAH_PTR__this,char * s){
struct string* this=__BAH_PTR__this;
this->length=strlen( s ) ;
this->content=memoryAlloc( this->length + 1 ) ;
strcpy( this->content , s ) ;
};

void  string__append(void *__BAH_PTR__this,char * s){
struct string* this=__BAH_PTR__this;
this->length=this->length+strlen( s ) ;
char * tmpS=memoryRealloc( this->content , this->length ) ;
if (((long int )tmpS==0)) {
tmpS=memoryAlloc( this->length ) ;
strncpy( tmpS , this->content , this->length ) ;
}
strcat( tmpS , s ) ;
this->content=tmpS;
};

void  string__prepend(void *__BAH_PTR__this,char * s){
struct string* this=__BAH_PTR__this;
char * tmpS=memoryAlloc( this->length + 1 ) ;
strcpy( tmpS , this->content ) ;
this->length=this->length+strlen( s ) ;
this->content=memoryAlloc( this->length + 1 ) ;
strcpy( this->content , s ) ;
strcat( this->content , tmpS ) ;
};

char  string__charAt(void *__BAH_PTR__this,long int i){
struct string* this=__BAH_PTR__this;
char c=(char )0;
if ((i<this->length)) {
noCheck( c = this -> content [ i ] ) ;
return c ;
}
return c ;
};

long int  string__compare(void *__BAH_PTR__this,char * s){
struct string* this=__BAH_PTR__this;
long int r=strcmp( this->content , s ) ;
if ((r==0)) {
return 1 ;
}
return 0 ;
};

char *  string__str(void *__BAH_PTR__this){
struct string* this=__BAH_PTR__this;
char * r=this->content;
return r ;
};

void  string__replace(void *__BAH_PTR__this,char * nd,char * rl){
struct string* this=__BAH_PTR__this;
struct string needle={};
needle.append=string__append;
needle.prepend=string__prepend;
needle.charAt=string__charAt;
needle.compare=string__compare;
needle.str=string__str;
needle.set=string__set;
needle.set( &needle , nd ) ;
struct string repl={};
repl.compare=string__compare;
repl.str=string__str;
repl.set=string__set;
repl.append=string__append;
repl.prepend=string__prepend;
repl.charAt=string__charAt;
repl.set( &repl , rl ) ;
long int i=0;
long int si=0;
struct string replcBuff={};
replcBuff.set=string__set;
replcBuff.append=string__append;
replcBuff.prepend=string__prepend;
replcBuff.charAt=string__charAt;
replcBuff.compare=string__compare;
replcBuff.str=string__str;
replcBuff.set( &replcBuff , "" ) ;
array(char ) *buff = memoryAlloc(sizeof(array(char )));
buff->length=0;
buff->elemSize=sizeof(char );
buff->data;
while ((i<this->length)) {
char c=this->charAt( this , i ) ;
char rc=needle.charAt( &needle , si ) ;
if ((c==rc)) {
si=si+1;
char * cs=charToString( c ) ;
replcBuff.append( &replcBuff , cs ) ;
}
else {
if ((replcBuff.length>0)) {
si=0;
long int ii=0;
while ((ii<replcBuff.length)) {

			{
				long nLength = len(buff);
			if (buff->length < nLength+1) {
				if ((nLength+1) % 50 == 0 || nLength == 0) {
					void * newPtr = GC_REALLOC(buff->data, (nLength+50)*sizeof(char ));
					//memcpy(newPtr, buff->data, (nLength)*sizeof(char ));
					buff->data = newPtr;
				}
				buff->data[len(buff)]=replcBuff.charAt( &replcBuff , ii ) ;
				buff->length = nLength+1;
			} else {
				buff->data[len(buff)]=replcBuff.charAt( &replcBuff , ii ) ;
			};
			};
ii=ii+1;
};
replcBuff.set( &replcBuff , "" ) ;
}

			{
				long nLength = len(buff);
			if (buff->length < nLength+1) {
				if ((nLength+1) % 50 == 0 || nLength == 0) {
					void * newPtr = GC_REALLOC(buff->data, (nLength+50)*sizeof(char ));
					//memcpy(newPtr, buff->data, (nLength)*sizeof(char ));
					buff->data = newPtr;
				}
				buff->data[len(buff)]=c;
				buff->length = nLength+1;
			} else {
				buff->data[len(buff)]=c;
			};
			};
}
if ((si==needle.length)) {
replcBuff.set( &replcBuff , "" ) ;
long int ii=0;
while ((ii<repl.length)) {

			{
				long nLength = len(buff);
			if (buff->length < nLength+1) {
				if ((nLength+1) % 50 == 0 || nLength == 0) {
					void * newPtr = GC_REALLOC(buff->data, (nLength+50)*sizeof(char ));
					//memcpy(newPtr, buff->data, (nLength)*sizeof(char ));
					buff->data = newPtr;
				}
				buff->data[len(buff)]=repl.charAt( &repl , ii ) ;
				buff->length = nLength+1;
			} else {
				buff->data[len(buff)]=repl.charAt( &repl , ii ) ;
			};
			};
ii=ii+1;
};
si=0;
}
i=i+1;
};
char * r="";
noCheck( r = buff -> data ) ;
if ((replcBuff.length>0)) {
char * replbuffStr=replcBuff.str( &replcBuff ) ;
r=concatCPSTRING(r, replbuffStr);
}
this->set( this , r ) ;
};

long int  string__count(void *__BAH_PTR__this,char * need){
struct string* this=__BAH_PTR__this;
long int i=0;
long int count=0;
struct string needle={};
needle.charAt=string__charAt;
needle.compare=string__compare;
needle.str=string__str;
needle.replace=string__replace;
needle.prepend=string__prepend;
needle.set=string__set;
needle.append=string__append;
needle.set( &needle , need ) ;
long int countIndex=0;
while ((i<this->length)) {
char c=this->charAt( this , i ) ;
char sc=needle.charAt( &needle , countIndex ) ;
if ((c==sc)) {
countIndex=countIndex+1;
}
else {
countIndex=0;
}
if ((countIndex==needle.length)) {
count=count+1;
countIndex=0;
}
i=i+1;
};
return count ;
};

long int  string__hasPrefix(void *__BAH_PTR__this,char * need){
struct string* this=__BAH_PTR__this;
long int i=0;
struct string needle={};
needle.set=string__set;
needle.append=string__append;
needle.prepend=string__prepend;
needle.count=string__count;
needle.charAt=string__charAt;
needle.compare=string__compare;
needle.str=string__str;
needle.replace=string__replace;
needle.set( &needle , need ) ;
if ((this->length<needle.length)) {
return 0 ;
}
while ((i<needle.length)) {
char c=this->charAt( this , i ) ;
char sc=needle.charAt( &needle , i ) ;
if ((c!=sc)) {
return 0 ;
}
i=i+1;
};
return 1 ;
};

long int  string__hasSuffix(void *__BAH_PTR__this,char * need){
struct string* this=__BAH_PTR__this;
struct string needle={};
needle.set=string__set;
needle.append=string__append;
needle.prepend=string__prepend;
needle.count=string__count;
needle.hasPrefix=string__hasPrefix;
needle.charAt=string__charAt;
needle.compare=string__compare;
needle.str=string__str;
needle.replace=string__replace;
needle.set( &needle , need ) ;
if ((this->length<needle.length)) {
return 0 ;
}
long int i=this->length-needle.length;
long int needleIndex=0;
while ((i<this->length)) {
char c=this->charAt( this , i ) ;
char sc=needle.charAt( &needle , needleIndex ) ;
if ((c!=sc)) {
return 0 ;
}
needleIndex=needleIndex+1;
i=i+1;
};
return 1 ;
};

void  string__trim(void *__BAH_PTR__this){
struct string* this=__BAH_PTR__this;
if ((this->length==0)) {
return ;
}
char fc=this->charAt( this , 0 ) ;
if ((isSpace( fc ) ==0)) {
return ;
}
long int i=0;
while ((i<this->length)) {
char c=this->charAt( this , i ) ;
if ((isSpace( c ) ==0)) {
break;
}
i=i+1;
};
if ((i>0)) {
this->length=this->length-i;
char * tmpS=memoryAlloc( this->length + 1 ) ;
memcpy( tmpS , noCheck( this->content + i )  , this->length + 1 ) ;
this->content=tmpS;
}
};

void  string__trimLeft(void *__BAH_PTR__this,long int s){
struct string* this=__BAH_PTR__this;
long int nSize=this->length-s;
void *tmpS=memoryAlloc( nSize ) ;
memcpy( tmpS , noCheck( this->content + s )  , nSize ) ;
this->content=tmpS;
this->length=nSize;
};

void  string__trimRight(void *__BAH_PTR__this,long int s){
struct string* this=__BAH_PTR__this;
long int nSize=this->length-s;
void *tmpS=memoryAlloc( nSize ) ;
memcpy( tmpS , this->content , nSize ) ;
this->content=tmpS;
this->length=nSize;
};

struct fileStream {
FILE* handle;
long int (*isValid)(struct fileStream*);
void (*open)(struct fileStream*,char * ,char * );
void (*close)(struct fileStream*);
long int (*getSize)(struct fileStream*);
char * (*readContent)(struct fileStream*);
void (*rewind)(struct fileStream*);
char (*getChar)(struct fileStream*);
void (*createFile)(struct fileStream*,char * );
long int (*writeFile)(struct fileStream*,char * );
};
long int  fileStream__isValid(void *__BAH_PTR__this){
struct fileStream* this=__BAH_PTR__this;
if ((this->handle==0)) {
return 0 ;
}
return 1 ;
};

void  fileStream__open(void *__BAH_PTR__this,char * path,char * mode){
struct fileStream* this=__BAH_PTR__this;
this->handle=fopen( path , mode ) ;
};

void  fileStream__close(void *__BAH_PTR__this){
struct fileStream* this=__BAH_PTR__this;
if ((this->isValid( this ) ==0)) {
return ;
}
fclose( this->handle ) ;
};

long int  fileStream__getSize(void *__BAH_PTR__this){
struct fileStream* this=__BAH_PTR__this;
if ((this->isValid( this ) ==0)) {
return -1 ;
}
fseek( this->handle , 0 , 2 ) ;
long int size=ftell( this->handle ) ;
fclose( this->handle ) ;
return size ;
};

char *  fileStream__readContent(void *__BAH_PTR__this){
struct fileStream* this=__BAH_PTR__this;
if ((this->isValid( this ) ==0)) {
return "invalid" ;
}
fseek( this->handle , 0 , 2 ) ;
long int size=ftell( this->handle ) ;
rewind( this->handle ) ;
char c=getc( this->handle ) ;
long int i=0;
array(char ) *s = memoryAlloc(sizeof(array(char )));
s->length=0;
s->elemSize=sizeof(char );
s->data;
while ((c!=(char )noCheck( EOF ) )) {

			{
				long nLength = len(s);
			if (s->length < nLength+1) {
				if ((nLength+1) % 50 == 0 || nLength == 0) {
					void * newPtr = GC_REALLOC(s->data, (nLength+50)*sizeof(char ));
					//memcpy(newPtr, s->data, (nLength)*sizeof(char ));
					s->data = newPtr;
				}
				s->data[len(s)]=c;
				s->length = nLength+1;
			} else {
				s->data[len(s)]=c;
			};
			};
i=i+1;
c=getc( this->handle ) ;
};

			{
				long nLength = len(s);
			if (s->length < nLength+1) {
				if ((nLength+1) % 50 == 0 || nLength == 0) {
					void * newPtr = GC_REALLOC(s->data, (nLength+50)*sizeof(char ));
					//memcpy(newPtr, s->data, (nLength)*sizeof(char ));
					s->data = newPtr;
				}
				s->data[len(s)]=(char )0;
				s->length = nLength+1;
			} else {
				s->data[len(s)]=(char )0;
			};
			};
long int ls=len( s ) ;
char * r="";
noCheck( r = s -> data ) ;
return r ;
};

void  fileStream__rewind(void *__BAH_PTR__this){
struct fileStream* this=__BAH_PTR__this;
rewind( this->handle ) ;
};

char  fileStream__getChar(void *__BAH_PTR__this){
struct fileStream* this=__BAH_PTR__this;
char c=getc( this->handle ) ;
return c ;
};

void  fileStream__createFile(void *__BAH_PTR__this,char * path){
struct fileStream* this=__BAH_PTR__this;
this->open( this , path , "w" ) ;
this->close( this ) ;
};

long int  fileStream__writeFile(void *__BAH_PTR__this,char * content){
struct fileStream* this=__BAH_PTR__this;
if ((this->isValid( this ) ==0)) {
return -1 ;
}
fputs( content , this->handle ) ;
return 1 ;
};

struct fileMap {
long int handle;
char * (*open)(struct fileMap*,char * );
long int (*isValid)(struct fileMap*);
void (*close)(struct fileMap*);
};
char *  fileMap__open(void *__BAH_PTR__this,char * fileName){
struct fileMap* this=__BAH_PTR__this;
this->handle=open( fileName , noCheck( O_RDWR )  , noCheck( S_IRUSR |S_IWUSR )  ) ;
struct stat sb={};
fstat( this->handle , &sb ) ;
char * file=mmap( 0 , sb.st_size , noCheck( PROT_READ |PROT_WRITE )  , noCheck( MAP_SHARED )  , this->handle , 0 ) ;
return file ;
};

long int  fileMap__isValid(void *__BAH_PTR__this){
struct fileMap* this=__BAH_PTR__this;
if ((this->handle<0)) {
return 0 ;
}
else {
return 1 ;
}
};

void  fileMap__close(void *__BAH_PTR__this){
struct fileMap* this=__BAH_PTR__this;
close( this->handle ) ;
};

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
array(struct flag* ) * flags;
array(char * ) * args;
void (*addString)(struct flags*,char * ,char * );
void (*addBool)(struct flags*,char * ,char * );
void (*addInt)(struct flags*,char * ,char * );
void (*addFloat)(struct flags*,char * ,char * );
void (*invalidate)(struct flags*);
struct flag* (*getFlag)(struct flags*,struct string );
char * (*get)(struct flags*,char * );
long int (*getInt)(struct flags*,char * );
double (*getFloat)(struct flags*,char * );
long int (*isSet)(struct flags*,char * );
void (*parse)(struct flags*,char * );
};
void  flags__addString(void *__BAH_PTR__this,char * name,char * help){
struct flags* this=__BAH_PTR__this;
struct flag* f=GC_malloc(sizeof(struct flag));
f->name=name;
f->help=help;
f->type=FLAG_TYPE_CPSTRING;
long int lf=len( this->flags ) ;

			{
				long nLength = lf;
			if (this->flags->length < nLength+1) {
				if ((nLength+1) % 50 == 0 || nLength == 0) {
					void * newPtr = GC_REALLOC(this->flags->data, (nLength+50)*sizeof(struct flag ));
					//memcpy(newPtr, this->flags->data, (nLength)*sizeof(struct flag ));
					this->flags->data = newPtr;
				}
				this->flags->data[lf]=f;
				this->flags->length = nLength+1;
			} else {
				this->flags->data[lf]=f;
			};
			};
};

void  flags__addBool(void *__BAH_PTR__this,char * name,char * help){
struct flags* this=__BAH_PTR__this;
struct flag* f=GC_malloc(sizeof(struct flag));
f->name=name;
f->help=help;
f->type=FLAG_TYPE_BOOL;
long int lf=len( this->flags ) ;

			{
				long nLength = lf;
			if (this->flags->length < nLength+1) {
				if ((nLength+1) % 50 == 0 || nLength == 0) {
					void * newPtr = GC_REALLOC(this->flags->data, (nLength+50)*sizeof(struct flag ));
					//memcpy(newPtr, this->flags->data, (nLength)*sizeof(struct flag ));
					this->flags->data = newPtr;
				}
				this->flags->data[lf]=f;
				this->flags->length = nLength+1;
			} else {
				this->flags->data[lf]=f;
			};
			};
};

void  flags__addInt(void *__BAH_PTR__this,char * name,char * help){
struct flags* this=__BAH_PTR__this;
struct flag* f=GC_malloc(sizeof(struct flag));
f->name=name;
f->help=help;
f->type=FLAG_TYPE_INT;
long int lf=len( this->flags ) ;

			{
				long nLength = lf;
			if (this->flags->length < nLength+1) {
				if ((nLength+1) % 50 == 0 || nLength == 0) {
					void * newPtr = GC_REALLOC(this->flags->data, (nLength+50)*sizeof(struct flag ));
					//memcpy(newPtr, this->flags->data, (nLength)*sizeof(struct flag ));
					this->flags->data = newPtr;
				}
				this->flags->data[lf]=f;
				this->flags->length = nLength+1;
			} else {
				this->flags->data[lf]=f;
			};
			};
};

void  flags__addFloat(void *__BAH_PTR__this,char * name,char * help){
struct flags* this=__BAH_PTR__this;
struct flag* f=GC_malloc(sizeof(struct flag));
f->name=name;
f->help=help;
f->type=FLAG_TYPE_FLOAT;
long int lf=len( this->flags ) ;

			{
				long nLength = lf;
			if (this->flags->length < nLength+1) {
				if ((nLength+1) % 50 == 0 || nLength == 0) {
					void * newPtr = GC_REALLOC(this->flags->data, (nLength+50)*sizeof(struct flag ));
					//memcpy(newPtr, this->flags->data, (nLength)*sizeof(struct flag ));
					this->flags->data = newPtr;
				}
				this->flags->data[lf]=f;
				this->flags->length = nLength+1;
			} else {
				this->flags->data[lf]=f;
			};
			};
};

void  flags__invalidate(void *__BAH_PTR__this){
struct flags* this=__BAH_PTR__this;
print( "Usage of " ) ;
print( this->args->data[0] ) ;
println( ":" ) ;
long int i=0;
while ((i<len( this->flags ) )) {
struct flag *flag=this->flags->data[i];
print( "    -" ) ;
print( flag->name ) ;
if ((flag->type==FLAG_TYPE_CPSTRING)) {
println( " (string)" ) ;
}
else if ((flag->type==FLAG_TYPE_BOOL)) {
println( " (bool)" ) ;
}
else if ((flag->type==FLAG_TYPE_INT)) {
println( " (int)" ) ;
}
else if ((flag->type==FLAG_TYPE_FLOAT)) {
println( " (float)" ) ;
}
print( "\t" ) ;
println( flag->help ) ;
i=i+1;
};
exit( 1 ) ;
};

struct flag*  flags__getFlag(void *__BAH_PTR__this,struct string name){
struct flags* this=__BAH_PTR__this;
long int i=0;
while ((i<len( this->flags ) )) {
struct flag *flag=this->flags->data[i];
if (name.compare( &name , flag->name ) ) {
return flag ;
}
i=i+1;
};
struct flag* z=GC_malloc(sizeof(struct flag));
z->isSet=0;
return z ;
};

char *  flags__get(void *__BAH_PTR__this,char * name){
struct flags* this=__BAH_PTR__this;
struct flag* flag=this->getFlag( this , string( name )  ) ;
char * ctn=flag->content;
return ctn ;
};

long int  flags__getInt(void *__BAH_PTR__this,char * name){
struct flags* this=__BAH_PTR__this;
struct flag* flag=this->getFlag( this , string( name )  ) ;
if ((flag->type!=FLAG_TYPE_INT)) {
struct string error=string( flag->name ) ;
error.prepend( &error , "Flag '" ) ;
error.append( &error , "' is not int." ) ;
panic( error.str(&error) ) ;
}
long int ctn=flag->cont_int;
return ctn ;
};

double  flags__getFloat(void *__BAH_PTR__this,char * name){
struct flags* this=__BAH_PTR__this;
struct flag* flag=this->getFlag( this , string( name )  ) ;
if ((flag->type!=FLAG_TYPE_FLOAT)) {
struct string error=string( flag->name ) ;
error.prepend( &error , "Flag '" ) ;
error.append( &error , "' is not float." ) ;
panic( error.str(&error) ) ;
}
double ctn=flag->cont_float;
return ctn ;
};

long int  flags__isSet(void *__BAH_PTR__this,char * name){
struct flags* this=__BAH_PTR__this;
struct flag* flag=this->getFlag( this , string( name )  ) ;
long int ctn=flag->isSet;
return ctn ;
};

void  flags__parse(void *__BAH_PTR__this,array(char * )* args){
struct flags* this=__BAH_PTR__this;
struct flag* currentFlag;
long int isVal=0;
this->args=args;
long int i=1;
while ((i<len( args ) )) {
struct string argName=string( args->data[i] ) ;
if (isVal) {
currentFlag->content=argName.str( &argName ) ;
if ((currentFlag->type==FLAG_TYPE_INT)) {
currentFlag->cont_int=atoi( argName.str(&argName) ) ;
}
else if ((currentFlag->type==FLAG_TYPE_FLOAT)) {
currentFlag->cont_float=strtod( argName.str(&argName) , 0 ) ;
}
isVal=0;
}
else {
if ((argName.charAt( &argName , 0 ) !='-')) {
i=i+1;
continue;
}
argName.trimLeft( &argName , 1 ) ;
if (argName.compare( &argName , "help" ) ) {
this->invalidate( this ) ;
}
else if (argName.compare( &argName , "h" ) ) {
this->invalidate( this ) ;
}
currentFlag=this->getFlag( this , argName ) ;
if ((currentFlag==0)) {
this->invalidate( this ) ;
}
currentFlag->isSet=1;
if ((currentFlag->type!=FLAG_TYPE_BOOL)) {
isVal=1;
}
}
i=i+1;
};
if ((isVal==1)) {
if ((currentFlag->type!=FLAG_TYPE_BOOL)) {
this->invalidate( this ) ;
}
}
};

struct variable {
char * name;
char * type;
};
struct structMemb {
char * name;
char * type;
char * def;
};
struct cStruct {
char * name;
array(struct structMemb* ) * members;
char * postCode;
int print;
char * extendedFrom;
};
struct Elems {
array(struct variable* ) * vars;
array(struct cStruct* ) * structs;
array(char * ) * types;
};
struct Tok {
char * cont;
tokenType type;
long int pos;
long int line;
char * bahType;
int isValue;
};
void * memoryAlloc(long int s){
void *p=GC_MALLOC( s ) ;
return p ;
};
void  destroy(void *a){
GC_FREE( a ) ;
};
void  clear(void *a){
noCheck( array( void* ) * arr = a ) ;
noCheck( destroy( arr -> data ) ) ;
noCheck( arr -> data = memoryAlloc( sizeof( 0 ) ) ) ;
noCheck( arr -> length = 0 ) ;
};
void  append(void *a,void *b){
noCheck( array( void* ) * arrA = a ) ;
noCheck( array( void* ) * arrB = b ) ;
long int lenA=0;
long int lenB=0;
long int realSizeA=0;
long int realSizeB=0;
noCheck( lenA = len( arrA ) ) ;
noCheck( lenB = len( arrB ) ) ;
if ((lenB==0)) {
return ;
}
if ((lenA==0)) {
noCheck( arrA -> data = arrB -> data ) ;
noCheck( arrA -> length = arrB -> length ) ;
return ;
}
noCheck( realSizeA = lenA * arrA -> elemSize ) ;
noCheck( realSizeB = lenB * arrB -> elemSize ) ;
void *buff=memoryAlloc( realSizeA + realSizeB + 32 ) ;
noCheck( memcpy( buff , arrA -> data , realSizeA ) ) ;
noCheck( memcpy( buff + lenA , arrB -> data , realSizeB ) ) ;
noCheck( arrA -> length = lenA + lenB ) ;
noCheck( arrA -> data = buff ) ;
};
void * memoryRealloc(void *p,long int s){
void *np=GC_REALLOC( p , s ) ;
return np ;
};
void * sharedMemory(long int size){
if ((size==0)) {
size=4096;
}
void *r=mmap( 0 , size , noCheck( PROT_READ |PROT_WRITE )  , noCheck( MAP_SHARED |MAP_ANONYMOUS )  , -1 , 0 ) ;
return r ;
};
long int  len(void *a){
long int i=0;
noCheck( array( void* ) * arr = a ) ;
noCheck( i = arr -> length ) ;
return i ;
};
char *  concatCPSTRING(char * a,char * b){
long int lenA=strlen( a ) ;
long int lenB=strlen( b ) ;
char * r=memoryAlloc( lenA + lenB + 1 ) ;
strncpy( r , a , lenA ) ;
strcat( r , b ) ;
return r ;
};
char *  __STR(char * a){
long int lenA=strlen( a ) ;
void *r=memoryAlloc( lenA + 1 ) ;
strncpy( r , a , lenA ) ;
return r ;
};
char *  charToString(char c){
char * s=memoryAlloc( 2 ) ;
strncpy( s , (char * )&c , 1 ) ;
return s ;
};
long int  isUpper(char c){
if ((c>(char )64)) {
if ((c<(char )91)) {
return 1 ;
}
}
return 0 ;
};
long int  isLower(char c){
if ((c>(char )96)) {
if ((c<(char )123)) {
return 1 ;
}
}
return 0 ;
};
long int  isLetter(char s){
if (isUpper( s ) ) {
return 1 ;
}
if (isLower( s ) ) {
return 1 ;
}
return 0 ;
};
long int  isNumber(char c){
if ((c>(char )47)) {
if ((c<(char )58)) {
return 1 ;
}
}
return 0 ;
};
long int  isAlphaNumeric(char s){
if (isLetter( s ) ) {
return 1 ;
}
if (isNumber( s ) ) {
return 1 ;
}
return 0 ;
};
long int  isSpace(char c){
if ((c==(char )32)) {
return 1 ;
}
if ((c==(char )9)) {
return 1 ;
}
if ((c==(char )10)) {
return 1 ;
}
if ((c==(char )11)) {
return 1 ;
}
if ((c==(char )13)) {
return 1 ;
}
return 0 ;
};
struct string  string(char * s){
struct string a={};
a.hasSuffix=string__hasSuffix;
a.trimLeft=string__trimLeft;
a.compare=string__compare;
a.replace=string__replace;
a.count=string__count;
a.hasPrefix=string__hasPrefix;
a.trimRight=string__trimRight;
a.charAt=string__charAt;
a.str=string__str;
a.trim=string__trim;
a.set=string__set;
a.append=string__append;
a.prepend=string__prepend;
a.content=(char * )0;
a.length=0;
a.set( &a , s ) ;
return a ;
};
char *  arrToStr(array(char )* arr){
long int strLen=len( arr ) ;
char * str=memoryAlloc( strLen + 1 ) ;
noCheck( memcpy( str , arr -> data , strLen ) ) ;
return str ;
};
array(char )* strToArr(char * str){
long int strLen=strlen( str ) ;
array(char ) *arr = memoryAlloc(sizeof(array(char )));
arr->length=0;
arr->elemSize=sizeof(char );
arr->data;
noCheck( arr -> data = memoryAlloc( strLen + 1 ) ) ;
noCheck( memcpy( arr -> data , str , strLen ) ) ;
noCheck( arr -> length = strLen ) ;
return arr ;
};
char *  arrAsStr(array(char )* arr){
char * r="";
noCheck( r = arr -> data ) ;
return r ;
};
struct string  intToString(long int i){
char * buff=memoryAlloc( 65 ) ;
void *ptri=(void *)i;
sprintf( buff , "%d" , ptri ) ;
struct string r=string( buff ) ;
return r ;
};
char *  intToStr(long int i){
char * buff=memoryAlloc( 65 ) ;
sprintf( buff , "%ld" , (void *)i ) ;
return buff ;
};
long int  stringToInt(struct string s){
long int i=atoi( s.content ) ;
return i ;
};
array(struct string )* splitString(struct string s,char * sp){
struct string sep=string( sp ) ;
array(struct string ) *res = memoryAlloc(sizeof(array(struct string )));
res->length=0;
res->elemSize=sizeof(struct string );
res->data;
struct string sepBuffer=string( "" ) ;
long int sepIndex=0;
long int i=0;
struct string replcBuff=string( "" ) ;
array(char ) *tmpString = memoryAlloc(sizeof(array(char )));
tmpString->length=0;
tmpString->elemSize=sizeof(char );
tmpString->data;
while ((i<s.length)) {
char c=s.charAt( &s , i ) ;
char sepc=sep.charAt( &sep , sepIndex ) ;
if ((c==sepc)) {
sepIndex=sepIndex+1;
replcBuff.append( &replcBuff , charToString( c )  ) ;
}
else {
if ((sepIndex>0)) {
sepIndex=0;
replcBuff.append( &replcBuff , charToString( c )  ) ;
long int ii=0;
while ((ii<replcBuff.length)) {

			{
				long nLength = len(tmpString);
			if (tmpString->length < nLength+1) {
				if ((nLength+1) % 50 == 0 || nLength == 0) {
					void * newPtr = GC_REALLOC(tmpString->data, (nLength+50)*sizeof(char ));
					//memcpy(newPtr, tmpString->data, (nLength)*sizeof(char ));
					tmpString->data = newPtr;
				}
				tmpString->data[len(tmpString)]=replcBuff.charAt( &replcBuff , ii ) ;
				tmpString->length = nLength+1;
			} else {
				tmpString->data[len(tmpString)]=replcBuff.charAt( &replcBuff , ii ) ;
			};
			};
ii=ii+1;
};
replcBuff.set( &replcBuff , "" ) ;
}
else {

			{
				long nLength = len(tmpString);
			if (tmpString->length < nLength+1) {
				if ((nLength+1) % 50 == 0 || nLength == 0) {
					void * newPtr = GC_REALLOC(tmpString->data, (nLength+50)*sizeof(char ));
					//memcpy(newPtr, tmpString->data, (nLength)*sizeof(char ));
					tmpString->data = newPtr;
				}
				tmpString->data[len(tmpString)]=c;
				tmpString->length = nLength+1;
			} else {
				tmpString->data[len(tmpString)]=c;
			};
			};
}
}
if ((sepIndex==sep.length)) {
replcBuff.set( &replcBuff , "" ) ;
struct string* elem=GC_malloc(sizeof(struct string));
elem->trimLeft=string__trimLeft;
elem->compare=string__compare;
elem->replace=string__replace;
elem->hasSuffix=string__hasSuffix;
elem->count=string__count;
elem->hasPrefix=string__hasPrefix;
elem->charAt=string__charAt;
elem->str=string__str;
elem->trimRight=string__trimRight;
elem->set=string__set;
elem->append=string__append;
elem->prepend=string__prepend;
elem->trim=string__trim;
elem->set( elem , arrToStr( tmpString )  ) ;
long int lenRes=len( res ) ;

			{
				long nLength = lenRes;
			if (res->length < nLength+1) {
				if ((nLength+1) % 50 == 0 || nLength == 0) {
					void * newPtr = GC_REALLOC(res->data, (nLength+50)*sizeof(struct string ));
					//memcpy(newPtr, res->data, (nLength)*sizeof(struct string ));
					res->data = newPtr;
				}
				res->data[lenRes]=*elem;
				res->length = nLength+1;
			} else {
				res->data[lenRes]=*elem;
			};
			};
clear( tmpString ) ;
sepIndex=0;
}
i=i+1;
};
if ((replcBuff.length>0)) {
long int ii=0;
while ((ii<replcBuff.length)) {

			{
				long nLength = len(tmpString);
			if (tmpString->length < nLength+1) {
				if ((nLength+1) % 50 == 0 || nLength == 0) {
					void * newPtr = GC_REALLOC(tmpString->data, (nLength+50)*sizeof(char ));
					//memcpy(newPtr, tmpString->data, (nLength)*sizeof(char ));
					tmpString->data = newPtr;
				}
				tmpString->data[len(tmpString)]=replcBuff.charAt( &replcBuff , ii ) ;
				tmpString->length = nLength+1;
			} else {
				tmpString->data[len(tmpString)]=replcBuff.charAt( &replcBuff , ii ) ;
			};
			};
ii=ii+1;
};
}
if ((len( tmpString ) >0)) {
struct string* elem=GC_malloc(sizeof(struct string));
elem->set=string__set;
elem->append=string__append;
elem->prepend=string__prepend;
elem->trim=string__trim;
elem->trimLeft=string__trimLeft;
elem->compare=string__compare;
elem->replace=string__replace;
elem->hasSuffix=string__hasSuffix;
elem->count=string__count;
elem->hasPrefix=string__hasPrefix;
elem->charAt=string__charAt;
elem->str=string__str;
elem->trimRight=string__trimRight;
elem->set( elem , arrToStr( tmpString )  ) ;
long int lenRes=len( res ) ;

			{
				long nLength = lenRes;
			if (res->length < nLength+1) {
				if ((nLength+1) % 50 == 0 || nLength == 0) {
					void * newPtr = GC_REALLOC(res->data, (nLength+50)*sizeof(struct string ));
					//memcpy(newPtr, res->data, (nLength)*sizeof(struct string ));
					res->data = newPtr;
				}
				res->data[lenRes]=*elem;
				res->length = nLength+1;
			} else {
				res->data[lenRes]=*elem;
			};
			};
}
return res ;
};
struct string  joinString(array(struct string )* a,char * sep){
long int i=0;
struct string s=string( "" ) ;
long int max=len( a ) -1;
while ((i<len( a ) )) {
struct string e=a->data[i];
if ((e.length==0)) {
i=i+1;
continue;
}
struct string tmpS=string( e.str(&e) ) ;
if ((i!=max)) {
tmpS.append( &tmpS , sep ) ;
}
s.append( &s , tmpS.str(&tmpS) ) ;
i=i+1;
};
return s ;
};
char *  splitStringBefore(struct string s,char * sp){
struct string sep=string( sp ) ;
if ((sep.length>=s.length)) {
return "" ;
}
long int sepIndex=0;
long int foundIndex=0;
long int i=0;
while ((i<s.length)) {
char c=s.charAt( &s , i ) ;
char sc=sep.charAt( &sep , sepIndex ) ;
if ((c==sc)) {
if ((sepIndex==0)) {
foundIndex=i-1;
}
sepIndex=sepIndex+1;
if ((sepIndex==sep.length)) {
long int max=s.length-foundIndex-1;
s.trimRight( &s , max ) ;
return s.str( &s )  ;
}
}
else {
foundIndex=0;
sepIndex=0;
}
i=i+1;
};
return "" ;
};
struct string  toLower(struct string s){
array(char ) *ns = memoryAlloc(sizeof(array(char )));
ns->length=0;
ns->elemSize=sizeof(char );
ns->data;
long int i=0;
while ((i<s.length)) {
char c=s.charAt( &s , i ) ;
if (isUpper( c ) ) {
c=c+(char )32;
}

			{
				long nLength = len(ns);
			if (ns->length < nLength+1) {
				if ((nLength+1) % 50 == 0 || nLength == 0) {
					void * newPtr = GC_REALLOC(ns->data, (nLength+50)*sizeof(char ));
					//memcpy(newPtr, ns->data, (nLength)*sizeof(char ));
					ns->data = newPtr;
				}
				ns->data[len(ns)]=c;
				ns->length = nLength+1;
			} else {
				ns->data[len(ns)]=c;
			};
			};
i=i+1;
};
return string( arrToStr( ns )  )  ;
};
char *  stdinput(long int len){
char * buff=memoryAlloc( len ) ;
fgets( buff , len , noCheck( stdin )  ) ;
return buff ;
};
void  print(char * s){
write( 1 , s , strlen( s )  ) ;
};
void  println(char * s){
write( 1 , s , strlen( s )  ) ;
write( 1 , "\n" , 1 ) ;
};
void  panic(char * e){
if (strlen( e ) ) {
println( e ) ;
exit( 1 ) ;
}
};
array(char * )* listFiles(char * dir){
array(char * ) *files = memoryAlloc(sizeof(array(char * )));
files->length=0;
files->elemSize=sizeof(char * );
files->data;
DIR* d=opendir( dir ) ;
struct dirent* file=readdir( d ) ;
while ((file!=0)) {
long int lf=len( files ) ;
if ((strcmp( file->d_name , "." ) ==0)) {
file=readdir( d ) ;
continue;
}
if ((strcmp( file->d_name , ".." ) ==0)) {
file=readdir( d ) ;
continue;
}

			{
				long nLength = lf;
			if (files->length < nLength+1) {
				if ((nLength+1) % 50 == 0 || nLength == 0) {
					void * newPtr = GC_REALLOC(files->data, (nLength+50)*sizeof(char * ));
					//memcpy(newPtr, files->data, (nLength)*sizeof(char * ));
					files->data = newPtr;
				}
				files->data[lf]=file->d_name;
				files->length = nLength+1;
			} else {
				files->data[lf]=file->d_name;
			};
			};
file=readdir( d ) ;
};
closedir( d ) ;
return files ;
};
long int  fileExists(char * path){
long int is=access( path , 0 ) ;
if ((is==0)) {
return 1 ;
}
else {
return 0 ;
}
};
struct string SOURCE;
char * OUTPUT="\n#define true 1\n#define false 0\n#define noCheck(v) v\n#define array(type)	\
    struct{	\
        type *data; \
        long int length; \
		long int elemSize; \
    }\nint main(int argc, char ** argv) {\n	GC_INIT();\n	array(char*) * args = GC_MALLOC(sizeof(array(char*)));\n	args->data = GC_MALLOC(sizeof(char*)*argc);\n	memcpy(args->data, argv, sizeof(char*)*argc);\n	args->elemSize = sizeof(char*);\n	args->length = argc;\n	__BAH__main(args);\n};\n#define main(v) __BAH__main(v)\n";
char * NEXT_LINE="";
int  inArray(char needle,array(char )* arr){
long int i=0;
while ((i<len( arr ) )) {
if ((needle==arr->data[i])) {
return true ;
}
i=i+1;
};
return false ;
};
int  inArrayStr(char * needle,array(char * )* arr){
long int i=0;
while ((i<len( arr ) )) {
if ((strcmp(needle,arr->data[i])==0)) {
return true ;
}
i=i+1;
};
return false ;
};
struct Tok  makeToken(long int pos,long int lineNb,array(char )* cont,tokenType type){
struct Tok t={};
t.isValue=false;
t.cont="";
t.type=(tokenType )-1;
t.pos=0;
t.line=1;
t.bahType="";
t.cont=arrToStr( cont ) ;
clear( cont ) ;
t.pos=pos;
t.line=lineNb;
t.type=type;
if ((type==TOKEN_TYPE_INT)) {
t.isValue=true;
}
else if ((type==TOKEN_TYPE_STR)) {
t.isValue=true;
}
else if ((type==TOKEN_TYPE_FLOAT)) {
t.isValue=true;
}
else if ((type==TOKEN_TYPE_VAR)) {
t.isValue=true;
}
if ((type==TOKEN_TYPE_BOOL)) {
t.isValue=true;
}
else if ((type==TOKEN_TYPE_CHAR)) {
t.isValue=true;
}
return t ;
};
array(struct Tok )* lexer(char * s){
array(struct Tok ) *tokens = memoryAlloc(sizeof(array(struct Tok )));
tokens->length=0;
tokens->elemSize=sizeof(struct Tok );
tokens->data;
struct string code=string( s ) ;
SOURCE=code;
array(char ) *memory = memoryAlloc(sizeof(array(char )));
memory->length=0;
memory->elemSize=sizeof(char );
memory->data;
long int lineNb=1;
array(char ) *enclavers = memoryAlloc(sizeof(array(char )));
enclavers->length=6;
enclavers->elemSize=sizeof(char );
enclavers->data=memoryAlloc(sizeof(char )* 50);
enclavers->data[0] = '(' ;
enclavers->data[1] = ')' ;
enclavers->data[2] = '{' ;
enclavers->data[3] = '}' ;
enclavers->data[4] = '[' ;
enclavers->data[5] = ']' ;
array(char ) *syntaxes = memoryAlloc(sizeof(array(char )));
syntaxes->length=14;
syntaxes->elemSize=sizeof(char );
syntaxes->data=memoryAlloc(sizeof(char )* 50);
syntaxes->data[0] = '!' ;
syntaxes->data[1] = '=' ;
syntaxes->data[2] = '|' ;
syntaxes->data[3] = (char )38 ;
syntaxes->data[4] = '%' ;
syntaxes->data[5] = '+' ;
syntaxes->data[6] = '-' ;
syntaxes->data[7] = '*' ;
syntaxes->data[8] = '/' ;
syntaxes->data[9] = ',' ;
syntaxes->data[10] = '<' ;
syntaxes->data[11] = '>' ;
syntaxes->data[12] = ':' ;
syntaxes->data[13] = (char )59 ;
array(char * ) *keywords = memoryAlloc(sizeof(array(char * )));
keywords->length=8;
keywords->elemSize=sizeof(char * );
keywords->data=memoryAlloc(sizeof(char * )* 50);
keywords->data[0] = __STR("if") ;
keywords->data[1] = __STR("else") ;
keywords->data[2] = __STR("for") ;
keywords->data[3] = __STR("struct") ;
keywords->data[4] = __STR("const") ;
keywords->data[5] = __STR("return") ;
keywords->data[6] = __STR("extend") ;
keywords->data[7] = __STR("new") ;
array(char * ) *bools = memoryAlloc(sizeof(array(char * )));
bools->length=2;
bools->elemSize=sizeof(char * );
bools->data=memoryAlloc(sizeof(char * )* 50);
bools->data[0] = __STR("true") ;
bools->data[1] = __STR("false") ;
array(char ) *seps = memoryAlloc(sizeof(array(char )));
seps->length=1;
seps->elemSize=sizeof(char );
seps->data=memoryAlloc(sizeof(char )* 50);
seps->data[0] = '.' ;
long int i=0;
while ((i<code.length)) {
char c=code.charAt( &code , i ) ;
if ((c==(char )10)) {
lineNb=lineNb+1;
}
if ((c==(char )34)) {
long int pos=i;
i=i+1;
while ((i<code.length)) {
c=code.charAt( &code , i ) ;
if ((c==(char )34)) {
char pc=code.charAt( &code , i -1 ) ;
if ((pc!=(char )92)) {
break;
}
}

			{
				long nLength = len(memory);
			if (memory->length < nLength+1) {
				if ((nLength+1) % 50 == 0 || nLength == 0) {
					void * newPtr = GC_REALLOC(memory->data, (nLength+50)*sizeof(char ));
					//memcpy(newPtr, memory->data, (nLength)*sizeof(char ));
					memory->data = newPtr;
				}
				memory->data[len(memory)]=c;
				memory->length = nLength+1;
			} else {
				memory->data[len(memory)]=c;
			};
			};
i=i+1;
};

			{
				long nLength = len(tokens);
			if (tokens->length < nLength+1) {
				if ((nLength+1) % 50 == 0 || nLength == 0) {
					void * newPtr = GC_REALLOC(tokens->data, (nLength+50)*sizeof(struct Tok ));
					//memcpy(newPtr, tokens->data, (nLength)*sizeof(struct Tok ));
					tokens->data = newPtr;
				}
				tokens->data[len(tokens)]=makeToken( pos , lineNb , memory , TOKEN_TYPE_STR ) ;
				tokens->length = nLength+1;
			} else {
				tokens->data[len(tokens)]=makeToken( pos , lineNb , memory , TOKEN_TYPE_STR ) ;
			};
			};
}
else if (isNumber( c ) ) {

			{
				long nLength = 0;
			if (memory->length < nLength+1) {
				if ((nLength+1) % 50 == 0 || nLength == 0) {
					void * newPtr = GC_REALLOC(memory->data, (nLength+50)*sizeof(char ));
					//memcpy(newPtr, memory->data, (nLength)*sizeof(char ));
					memory->data = newPtr;
				}
				memory->data[0]=c;
				memory->length = nLength+1;
			} else {
				memory->data[0]=c;
			};
			};
long int pos=i;
i=i+1;
tokenType currentType=TOKEN_TYPE_INT;
while ((i<code.length)) {
c=code.charAt( &code , i ) ;
if ((c==(char )46)) {
currentType=TOKEN_TYPE_FLOAT;
}
else if ((isNumber( c ) ==0)) {
break;
}

			{
				long nLength = len(memory);
			if (memory->length < nLength+1) {
				if ((nLength+1) % 50 == 0 || nLength == 0) {
					void * newPtr = GC_REALLOC(memory->data, (nLength+50)*sizeof(char ));
					//memcpy(newPtr, memory->data, (nLength)*sizeof(char ));
					memory->data = newPtr;
				}
				memory->data[len(memory)]=c;
				memory->length = nLength+1;
			} else {
				memory->data[len(memory)]=c;
			};
			};
i=i+1;
};
i=i-1;

			{
				long nLength = len(tokens);
			if (tokens->length < nLength+1) {
				if ((nLength+1) % 50 == 0 || nLength == 0) {
					void * newPtr = GC_REALLOC(tokens->data, (nLength+50)*sizeof(struct Tok ));
					//memcpy(newPtr, tokens->data, (nLength)*sizeof(struct Tok ));
					tokens->data = newPtr;
				}
				tokens->data[len(tokens)]=makeToken( pos , lineNb , memory , currentType ) ;
				tokens->length = nLength+1;
			} else {
				tokens->data[len(tokens)]=makeToken( pos , lineNb , memory , currentType ) ;
			};
			};
}
else if ((c==(char )39)) {
i=i+1;
c=code.charAt( &code , i ) ;
char * toInt=intToStr( (long int )c ) ;
memory=strToArr( toInt ) ;

			{
				long nLength = len(tokens);
			if (tokens->length < nLength+1) {
				if ((nLength+1) % 50 == 0 || nLength == 0) {
					void * newPtr = GC_REALLOC(tokens->data, (nLength+50)*sizeof(struct Tok ));
					//memcpy(newPtr, tokens->data, (nLength)*sizeof(struct Tok ));
					tokens->data = newPtr;
				}
				tokens->data[len(tokens)]=makeToken( i -1 , lineNb , memory , TOKEN_TYPE_CHAR ) ;
				tokens->length = nLength+1;
			} else {
				tokens->data[len(tokens)]=makeToken( i -1 , lineNb , memory , TOKEN_TYPE_CHAR ) ;
			};
			};
}
else if ((c==(char )35)) {
long int pos=i;

			{
				long nLength = 0;
			if (memory->length < nLength+1) {
				if ((nLength+1) % 50 == 0 || nLength == 0) {
					void * newPtr = GC_REALLOC(memory->data, (nLength+50)*sizeof(char ));
					//memcpy(newPtr, memory->data, (nLength)*sizeof(char ));
					memory->data = newPtr;
				}
				memory->data[0]=c;
				memory->length = nLength+1;
			} else {
				memory->data[0]=c;
			};
			};
i=i+1;
while ((i<code.length)) {
c=code.charAt( &code , i ) ;
if ((isAlphaNumeric( c ) ==0)) {
break;
}

			{
				long nLength = len(memory);
			if (memory->length < nLength+1) {
				if ((nLength+1) % 50 == 0 || nLength == 0) {
					void * newPtr = GC_REALLOC(memory->data, (nLength+50)*sizeof(char ));
					//memcpy(newPtr, memory->data, (nLength)*sizeof(char ));
					memory->data = newPtr;
				}
				memory->data[len(memory)]=c;
				memory->length = nLength+1;
			} else {
				memory->data[len(memory)]=c;
			};
			};
i=i+1;
};
i=i-1;

			{
				long nLength = len(tokens);
			if (tokens->length < nLength+1) {
				if ((nLength+1) % 50 == 0 || nLength == 0) {
					void * newPtr = GC_REALLOC(tokens->data, (nLength+50)*sizeof(struct Tok ));
					//memcpy(newPtr, tokens->data, (nLength)*sizeof(struct Tok ));
					tokens->data = newPtr;
				}
				tokens->data[len(tokens)]=makeToken( pos , lineNb , memory , TOKEN_TYPE_KEYWORD ) ;
				tokens->length = nLength+1;
			} else {
				tokens->data[len(tokens)]=makeToken( pos , lineNb , memory , TOKEN_TYPE_KEYWORD ) ;
			};
			};
}
else if (inArray( c , enclavers ) ) {

			{
				long nLength = 0;
			if (memory->length < nLength+1) {
				if ((nLength+1) % 50 == 0 || nLength == 0) {
					void * newPtr = GC_REALLOC(memory->data, (nLength+50)*sizeof(char ));
					//memcpy(newPtr, memory->data, (nLength)*sizeof(char ));
					memory->data = newPtr;
				}
				memory->data[0]=c;
				memory->length = nLength+1;
			} else {
				memory->data[0]=c;
			};
			};

			{
				long nLength = len(tokens);
			if (tokens->length < nLength+1) {
				if ((nLength+1) % 50 == 0 || nLength == 0) {
					void * newPtr = GC_REALLOC(tokens->data, (nLength+50)*sizeof(struct Tok ));
					//memcpy(newPtr, tokens->data, (nLength)*sizeof(struct Tok ));
					tokens->data = newPtr;
				}
				tokens->data[len(tokens)]=makeToken( i , lineNb , memory , TOKEN_TYPE_ENCL ) ;
				tokens->length = nLength+1;
			} else {
				tokens->data[len(tokens)]=makeToken( i , lineNb , memory , TOKEN_TYPE_ENCL ) ;
			};
			};
}
else if (inArray( c , syntaxes ) ) {

			{
				long nLength = 0;
			if (memory->length < nLength+1) {
				if ((nLength+1) % 50 == 0 || nLength == 0) {
					void * newPtr = GC_REALLOC(memory->data, (nLength+50)*sizeof(char ));
					//memcpy(newPtr, memory->data, (nLength)*sizeof(char ));
					memory->data = newPtr;
				}
				memory->data[0]=c;
				memory->length = nLength+1;
			} else {
				memory->data[0]=c;
			};
			};
long int pos=i;
i=i+1;
while ((i<code.length)) {
c=code.charAt( &code , i ) ;
if ((inArray( c , syntaxes ) ==false)) {
break;
}

			{
				long nLength = len(memory);
			if (memory->length < nLength+1) {
				if ((nLength+1) % 50 == 0 || nLength == 0) {
					void * newPtr = GC_REALLOC(memory->data, (nLength+50)*sizeof(char ));
					//memcpy(newPtr, memory->data, (nLength)*sizeof(char ));
					memory->data = newPtr;
				}
				memory->data[len(memory)]=c;
				memory->length = nLength+1;
			} else {
				memory->data[len(memory)]=c;
			};
			};
i=i+1;
};
i=i-1;

			{
				long nLength = len(tokens);
			if (tokens->length < nLength+1) {
				if ((nLength+1) % 50 == 0 || nLength == 0) {
					void * newPtr = GC_REALLOC(tokens->data, (nLength+50)*sizeof(struct Tok ));
					//memcpy(newPtr, tokens->data, (nLength)*sizeof(struct Tok ));
					tokens->data = newPtr;
				}
				tokens->data[len(tokens)]=makeToken( pos , lineNb , memory , TOKEN_TYPE_SYNTAX ) ;
				tokens->length = nLength+1;
			} else {
				tokens->data[len(tokens)]=makeToken( pos , lineNb , memory , TOKEN_TYPE_SYNTAX ) ;
			};
			};
}
else if (inArray( c , seps ) ) {

			{
				long nLength = 0;
			if (memory->length < nLength+1) {
				if ((nLength+1) % 50 == 0 || nLength == 0) {
					void * newPtr = GC_REALLOC(memory->data, (nLength+50)*sizeof(char ));
					//memcpy(newPtr, memory->data, (nLength)*sizeof(char ));
					memory->data = newPtr;
				}
				memory->data[0]=c;
				memory->length = nLength+1;
			} else {
				memory->data[0]=c;
			};
			};

			{
				long nLength = len(tokens);
			if (tokens->length < nLength+1) {
				if ((nLength+1) % 50 == 0 || nLength == 0) {
					void * newPtr = GC_REALLOC(tokens->data, (nLength+50)*sizeof(struct Tok ));
					//memcpy(newPtr, tokens->data, (nLength)*sizeof(struct Tok ));
					tokens->data = newPtr;
				}
				tokens->data[len(tokens)]=makeToken( i , lineNb , memory , TOKEN_TYPE_SEP ) ;
				tokens->length = nLength+1;
			} else {
				tokens->data[len(tokens)]=makeToken( i , lineNb , memory , TOKEN_TYPE_SEP ) ;
			};
			};
}
else if (isAlphaNumeric( c ) ) {

			{
				long nLength = 0;
			if (memory->length < nLength+1) {
				if ((nLength+1) % 50 == 0 || nLength == 0) {
					void * newPtr = GC_REALLOC(memory->data, (nLength+50)*sizeof(char ));
					//memcpy(newPtr, memory->data, (nLength)*sizeof(char ));
					memory->data = newPtr;
				}
				memory->data[0]=c;
				memory->length = nLength+1;
			} else {
				memory->data[0]=c;
			};
			};
long int pos=i;
i=i+1;
while ((i<code.length)) {
c=code.charAt( &code , i ) ;
if ((isAlphaNumeric( c ) ==0)) {
break;
}

			{
				long nLength = len(memory);
			if (memory->length < nLength+1) {
				if ((nLength+1) % 50 == 0 || nLength == 0) {
					void * newPtr = GC_REALLOC(memory->data, (nLength+50)*sizeof(char ));
					//memcpy(newPtr, memory->data, (nLength)*sizeof(char ));
					memory->data = newPtr;
				}
				memory->data[len(memory)]=c;
				memory->length = nLength+1;
			} else {
				memory->data[len(memory)]=c;
			};
			};
i=i+1;
};
i=i-1;
tokenType currentType=TOKEN_TYPE_VAR;
char * memstr=arrAsStr( memory ) ;
if (inArrayStr( memstr , keywords ) ) {
currentType=TOKEN_TYPE_KEYWORD;
}
else if (inArrayStr( memstr , bools ) ) {
currentType=TOKEN_TYPE_BOOL;
}

			{
				long nLength = len(tokens);
			if (tokens->length < nLength+1) {
				if ((nLength+1) % 50 == 0 || nLength == 0) {
					void * newPtr = GC_REALLOC(tokens->data, (nLength+50)*sizeof(struct Tok ));
					//memcpy(newPtr, tokens->data, (nLength)*sizeof(struct Tok ));
					tokens->data = newPtr;
				}
				tokens->data[len(tokens)]=makeToken( pos , lineNb , memory , currentType ) ;
				tokens->length = nLength+1;
			} else {
				tokens->data[len(tokens)]=makeToken( pos , lineNb , memory , currentType ) ;
			};
			};
}
i=i+1;
};
return tokens ;
};
struct cStruct*  searchStruct(char * name,void *__BAH_PTR__elems){
struct Elems* elems=__BAH_PTR__elems;
struct string n=string( name ) ;
n.replace( &n , "*" , "" ) ;
name=n.content;
long int i=0;
while ((i<len( elems->structs ) )) {
struct cStruct *s=elems->structs->data[i];
if ((strcmp(s->name,name)==0)) {
return s ;
}
i=i+1;
};
return null ;
};
struct structMemb*  searchStructMemb(char * name,void *__BAH_PTR__s,void *__BAH_PTR__elems){
struct Elems* elems=__BAH_PTR__elems;
struct cStruct* s=__BAH_PTR__s;
struct string n=string( name ) ;
if (n.count( &n , "." ) ) {
struct string rn=string( splitStringBefore( n , "." )  ) ;
name=rn.content;
n.trimLeft( &n , rn.length + 1 ) ;
char * membs=n.content;
struct structMemb* memb=searchStructMemb( name , s , elems ) ;
if ((n.length>0)) {
s=searchStruct( memb->type , elems ) ;
memb=searchStructMemb( n.str(&n) , s , elems ) ;
}
return memb ;
}
array(struct structMemb* ) *members=s->members;
long int i=0;
while ((i<len( members ) )) {
struct structMemb *m=members->data[i];
if ((strcmp(m->name,name)==0)) {
return m ;
}
i=i+1;
};
return null ;
};
char *  declareStructMethods(void *__BAH_PTR__v,void *__BAH_PTR__s){
struct cStruct* s=__BAH_PTR__s;
struct variable* v=__BAH_PTR__v;
char * code="";
array(struct structMemb* ) *members=s->members;
struct string typec=string( v->type ) ;
char * sep=".";
if (typec.count( &typec , "*" ) ) {
sep="->";
}
long int i=0;
while ((i<len( members ) )) {
struct structMemb *m=members->data[i];
if ((strlen( m->def ) >0)) {
code=concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(code, v->name), sep), m->name), " = "), m->def), ";\n");
}
i=i+1;
};
return code ;
};
struct string  getCType(char * t,void *__BAH_PTR__elems){
struct Elems* elems=__BAH_PTR__elems;
if ((strlen( t ) ==0)) {
return string( "void" )  ;
}
struct string tp=string( t ) ;
tp.replace( &tp , " " , "" ) ;
if (tp.hasPrefix( &tp , "[]" ) ) {
tp.trimLeft( &tp , 2 ) ;
tp=getCType( tp.str(&tp) , elems ) ;
t=tp.str( &tp ) ;
char * r=concatCPSTRING(concatCPSTRING("array(", t), ")*");
return string( r )  ;
}
struct string ctp=tp;
ctp.replace( &ctp , "*" , "" ) ;
if (ctp.compare( &ctp , "int" ) ) {
tp.replace( &tp , "int" , "long int" ) ;
}
else if (ctp.compare( &ctp , "int32" ) ) {
tp.replace( &tp , "int32" , "int" ) ;
}
else if (ctp.compare( &ctp , "uint32" ) ) {
tp.replace( &tp , "uint32" , "unsigned int" ) ;
}
else if (ctp.compare( &ctp , "uint" ) ) {
tp.replace( &tp , "uint" , "unsigned long int" ) ;
}
else if (ctp.compare( &ctp , "float32" ) ) {
tp.replace( &tp , "float32" , "float" ) ;
}
else if (ctp.compare( &ctp , "ufloat32" ) ) {
tp.replace( &tp , "ufloat32" , "unsigned float" ) ;
}
else if (ctp.compare( &ctp , "ufloat" ) ) {
tp.replace( &tp , "ufloat" , "unsigned double" ) ;
}
else if (ctp.compare( &ctp , "float" ) ) {
tp.replace( &tp , "float" , "double" ) ;
}
else if (ctp.compare( &ctp , "long" ) ) {
tp.replace( &tp , "long" , "long long" ) ;
}
else if (ctp.compare( &ctp , "ulong" ) ) {
tp.replace( &tp , "ulong" , "unsigned long long" ) ;
}
else if (ctp.compare( &ctp , "cpstring" ) ) {
tp.replace( &tp , "cpstring" , "char *" ) ;
}
else if (ctp.compare( &ctp , "ptr" ) ) {
tp.replace( &tp , "ptr" , "void *" ) ;
}
else if (ctp.compare( &ctp , "ushort" ) ) {
tp.replace( &tp , "ushort" , "unsigned short" ) ;
}
else if (ctp.compare( &ctp , "byte" ) ) {
tp.replace( &tp , "byte" , "unsigned char" ) ;
}
else if (ctp.compare( &ctp , "bool" ) ) {
tp.replace( &tp , "bool" , "int" ) ;
}
else {
struct cStruct* s=searchStruct( ctp.str(&ctp) , elems ) ;
if ((s!=null)) {
tp.prepend( &tp , "struct " ) ;
}
else {
long int i=0;
while ((i<len( elems->types ) )) {
char * ct=elems->types->data[i];
if (ctp.compare( &ctp , ct ) ) {
return tp ;
}
i=i+1;
};
return string( "" )  ;
}
}
return tp ;
};
void  throwErr(void *tp,char * format){
struct Tok* t=tp;
if ((t->type==TOKEN_TYPE_STR)) {
t->cont=concatCPSTRING(concatCPSTRING("\"", t->cont), "\"");
}
struct string ffmt=string( format ) ;
ffmt.replace( &ffmt , "{TOKEN}" , concatCPSTRING(concatCPSTRING("'", t->cont), "'") ) ;
format=ffmt.str( &ffmt ) ;
array(char ) *line = memoryAlloc(sizeof(array(char )));
line->length=0;
line->elemSize=sizeof(char );
line->data;
long int beg=t->pos;
while ((beg>0)) {
char c=SOURCE.charAt( &SOURCE , beg ) ;
if ((c==(char )10)) {
beg=beg+1;
break;
}
beg=beg-1;
};
long int pos=t->pos-beg;
long int i=beg;
while ((i<SOURCE.length)) {
char c=SOURCE.charAt( &SOURCE , i ) ;
if ((c==(char )10)) {
break;
}
if ((i==t->pos)) {
array(char ) *errTk=strToArr( concatCPSTRING(concatCPSTRING("\e[1;31m", t->cont), "\e[1;37m") ) ;
long int ii=0;
while ((ii<len( errTk ) )) {

			{
				long nLength = len(line);
			if (line->length < nLength+1) {
				if ((nLength+1) % 50 == 0 || nLength == 0) {
					void * newPtr = GC_REALLOC(line->data, (nLength+50)*sizeof(char ));
					//memcpy(newPtr, line->data, (nLength)*sizeof(char ));
					line->data = newPtr;
				}
				line->data[len(line)]=errTk->data[ii];
				line->length = nLength+1;
			} else {
				line->data[len(line)]=errTk->data[ii];
			};
			};
ii=ii+1;
};
i=i+strlen( t->cont ) ;
continue;
}

			{
				long nLength = len(line);
			if (line->length < nLength+1) {
				if ((nLength+1) % 50 == 0 || nLength == 0) {
					void * newPtr = GC_REALLOC(line->data, (nLength+50)*sizeof(char ));
					//memcpy(newPtr, line->data, (nLength)*sizeof(char ));
					line->data = newPtr;
				}
				line->data[len(line)]=c;
				line->length = nLength+1;
			} else {
				line->data[len(line)]=c;
			};
			};
i=i+1;
};
char * str=arrToStr( line ) ;
char * info=intToStr( t->line ) ;
println( concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING("\e[1;31m[ERROR]\e[0m Line ", info), ":\n\e[1;37m\t"), str), "\e[0m\n"), format) ) ;
exit( 1 ) ;
};
struct variable*  searchVar(char * name,void *__BAH_PTR__elems){
struct Elems* elems=__BAH_PTR__elems;
struct string n=string( name ) ;
if (n.count( &n , "." ) ) {
struct string rn=string( splitStringBefore( n , "." )  ) ;
name=rn.content;
n.trimLeft( &n , rn.length + 1 ) ;
char * membs=n.content;
struct variable* v=searchVar( name , elems ) ;
struct cStruct* s=searchStruct( v->type , elems ) ;
struct structMemb* memb=searchStructMemb( membs , s , elems ) ;
v=GC_malloc(sizeof(struct variable));
v->type="";
v->name="";
v->name=memb->name;
v->type=memb->type;
return v ;
}
long int i=0;
while ((i<len( elems->vars ) )) {
struct variable *v=elems->vars->data[i];
if ((strcmp(v->name,name)==0)) {
return v ;
}
i=i+1;
};
return null ;
};
char *  setCType(void *__BAH_PTR__v,void *__BAH_PTR__elems){
struct Elems* elems=__BAH_PTR__elems;
struct variable* v=__BAH_PTR__v;
struct string tp=getCType( v->type , elems ) ;
char * t=tp.str( &tp ) ;
t=concatCPSTRING(concatCPSTRING(t, " "), v->name);
return t ;
};
char *  getTypeFromToken(void *__BAH_PTR__t,int strict,void *__BAH_PTR__elems){
struct Elems* elems=__BAH_PTR__elems;
struct Tok* t=__BAH_PTR__t;
if ((strlen( t->bahType ) >0)) {
char * r=t->bahType;
return r ;
}
if ((t->type==TOKEN_TYPE_VAR)) {
struct variable* v=searchVar( t->cont , elems ) ;
if ((v==null)) {
if (strict) {
throwErr( t , "Unknown var {TOKEN}." ) ;
}
else {
return "" ;
}
}
if (strict) {
if ((strlen( v->type ) ==0)) {
throwErr( t , "Cannot use {TOKEN} because it does not have any type." ) ;
}
}
char * r=v->type;
return r ;
}
if ((t->type==TOKEN_TYPE_FLOAT)) {
return "float" ;
}
if ((t->type==TOKEN_TYPE_INT)) {
return "int" ;
}
if ((t->type==TOKEN_TYPE_STR)) {
return "cpstring" ;
}
if ((t->type==TOKEN_TYPE_CHAR)) {
return "char" ;
}
if ((t->type==TOKEN_TYPE_BOOL)) {
return "bool" ;
}
throwErr( t , "Cannot use {TOKEN} as value." ) ;
};
void  debugLine(array(struct Tok )* line){
char * cont="";
long int i=0;
while ((i<len( line ) )) {
struct Tok t=line->data[i];
cont=concatCPSTRING(concatCPSTRING(cont, " "), t.cont);
i=i+1;
};
println( cont ) ;
};
lineType  getLineType(array(struct Tok )* line){
struct Tok ft=line->data[0];
if ((ft.type==TOKEN_TYPE_KEYWORD)) {
if ((strcmp(ft.cont,"#include")==0)) {
return LINE_TYPE_INCLUDE ;
}
else if ((strcmp(ft.cont,"#define")==0)) {
return LINE_TYPE_DEFINE ;
}
else if ((strcmp(ft.cont,"const")==0)) {
return LINE_TYPE_CONST ;
}
else if ((strcmp(ft.cont,"struct")==0)) {
return LINE_TYPE_STRUCT ;
}
}
else if ((ft.type==TOKEN_TYPE_VAR)) {
if ((len( line ) ==1)) {
throwErr( &ft , "Cannot declare var {TOKEN} without a type." ) ;
}
struct Tok st=line->data[1];
if ((st.type==TOKEN_TYPE_ENCL)) {
if ((strcmp(st.cont,"(")==0)) {
struct Tok lt=line->data[len(line)-1];
if ((lt.type==TOKEN_TYPE_ENCL)) {
if ((strcmp(lt.cont,"}")==0)) {
return LINE_TYPE_FN_DECL ;
}
else {
println( concatCPSTRING(concatCPSTRING("NOPE: '", lt.cont), "'") ) ;
}
}
return LINE_TYPE_FN_CALL ;
}
}
return LINE_TYPE_VAR ;
}
};
array(struct Tok )* parseCast(array(struct Tok )* line,void *__BAH_PTR__elems){
struct Elems* elems=__BAH_PTR__elems;
array(struct Tok ) *nl = memoryAlloc(sizeof(array(struct Tok )));
nl->length=0;
nl->elemSize=sizeof(struct Tok );
nl->data;
long int i=0;
while ((i<len( line ) )) {
struct Tok t=line->data[i];
if ((t.type==TOKEN_TYPE_SYNTAX)) {
if ((strcmp(t.cont,"<")==0)) {
long int max=i+3;
if ((max<len( line ) )) {
struct Tok nt=line->data[i+1];
struct Tok nnt=line->data[i+2];
struct Tok nnnt=line->data[i+3];
if ((nt.type==TOKEN_TYPE_VAR)) {
if ((nnt.type==TOKEN_TYPE_SYNTAX)) {
if ((strcmp(nnt.cont,">")==0)) {
nnnt.bahType=nt.cont;
struct string cCast=getCType( nt.cont , elems ) ;
char * cCastStr=cCast.str( &cCast ) ;
nnnt.cont=concatCPSTRING(concatCPSTRING(concatCPSTRING("(", cCastStr), ")"), nnnt.cont);

			{
				long nLength = len(nl);
			if (nl->length < nLength+1) {
				if ((nLength+1) % 50 == 0 || nLength == 0) {
					void * newPtr = GC_REALLOC(nl->data, (nLength+50)*sizeof(struct Tok ));
					//memcpy(newPtr, nl->data, (nLength)*sizeof(struct Tok ));
					nl->data = newPtr;
				}
				nl->data[len(nl)]=nnnt;
				nl->length = nLength+1;
			} else {
				nl->data[len(nl)]=nnnt;
			};
			};
i=i+4;
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
					void * newPtr = GC_REALLOC(nl->data, (nLength+50)*sizeof(struct Tok ));
					//memcpy(newPtr, nl->data, (nLength)*sizeof(struct Tok ));
					nl->data = newPtr;
				}
				nl->data[len(nl)]=t;
				nl->length = nLength+1;
			} else {
				nl->data[len(nl)]=t;
			};
			};
i=i+1;
};
return nl ;
};
array(struct Tok )* parseOperations(array(struct Tok )* line,void *__BAH_PTR__elems){
struct Elems* elems=__BAH_PTR__elems;
array(char * ) *signs = memoryAlloc(sizeof(array(char * )));
signs->length=7;
signs->elemSize=sizeof(char * );
signs->data=memoryAlloc(sizeof(char * )* 50);
signs->data[0] = __STR("|") ;
signs->data[1] = __STR("&") ;
signs->data[2] = __STR("%") ;
signs->data[3] = __STR("+") ;
signs->data[4] = __STR("-") ;
signs->data[5] = __STR("*") ;
signs->data[6] = __STR("/") ;
array(struct Tok ) *nl = memoryAlloc(sizeof(array(struct Tok )));
nl->length=1;
nl->elemSize=sizeof(struct Tok );
nl->data=memoryAlloc(sizeof(struct Tok )* 50);
nl->data[0] = line->data[0] ;
long int i=1;
while ((i<len( line ) )) {
struct Tok t=line->data[i];
if ((t.type==TOKEN_TYPE_SYNTAX)) {
if (inArrayStr( t.cont , signs ) ) {
long int max=i+1;
if ((max>=len( line ) )) {
throwErr( &t , "Cannot use {TOKEN} on nothing." ) ;
}
struct Tok pt=nl->data[len(nl)-1];
struct Tok nt=line->data[i+1];
char * ptt=getTypeFromToken( &pt , true , elems ) ;
char * ntt=getTypeFromToken( &nt , true , elems ) ;
if ((strcmp(ptt,ntt)!=0)) {
throwErr( &nt , concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING("Cannot use {TOKEN} (", ntt), ") as "), ptt), ".") ) ;
}
t.isValue=true;
if ((strcmp(ptt,"cpstring")==0)) {
if ((strcmp(t.cont,"+")!=0)) {
throwErr( &t , "Can only do concatenation (+) on cpstrings, not {TOKEN}." ) ;
}
t.cont=concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING("concatCPSTRING(", pt.cont), ","), nt.cont), ")");
}
else {
t.cont=concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(pt.cont, " "), t.cont), " "), nt.cont);
}
t.type=TOKEN_TYPE_VAR;
t.bahType=ptt;
t.pos=pt.pos;

			{
				long nLength = len(nl)-1;
			if (nl->length < nLength+1) {
				if ((nLength+1) % 50 == 0 || nLength == 0) {
					void * newPtr = GC_REALLOC(nl->data, (nLength+50)*sizeof(struct Tok ));
					//memcpy(newPtr, nl->data, (nLength)*sizeof(struct Tok ));
					nl->data = newPtr;
				}
				nl->data[len(nl)-1]=t;
				nl->length = nLength+1;
			} else {
				nl->data[len(nl)-1]=t;
			};
			};
i=i+2;
continue;
}
}

			{
				long nLength = len(nl);
			if (nl->length < nLength+1) {
				if ((nLength+1) % 50 == 0 || nLength == 0) {
					void * newPtr = GC_REALLOC(nl->data, (nLength+50)*sizeof(struct Tok ));
					//memcpy(newPtr, nl->data, (nLength)*sizeof(struct Tok ));
					nl->data = newPtr;
				}
				nl->data[len(nl)]=t;
				nl->length = nLength+1;
			} else {
				nl->data[len(nl)]=t;
			};
			};
i=i+1;
};
return nl ;
};
array(struct Tok )* parseStructType(array(struct Tok )* line,void *__BAH_PTR__elems){
struct Elems* elems=__BAH_PTR__elems;
array(struct Tok ) *nl = memoryAlloc(sizeof(array(struct Tok )));
nl->length=0;
nl->elemSize=sizeof(struct Tok );
nl->data;
long int i=0;
while ((i<len( line ) )) {
struct Tok t=line->data[i];
if ((t.type==TOKEN_TYPE_VAR)) {
struct string ctbt=string( t.bahType ) ;
if (ctbt.hasPrefix( &ctbt , "[]" ) ) {

			{
				long nLength = len(nl);
			if (nl->length < nLength+1) {
				if ((nLength+1) % 50 == 0 || nLength == 0) {
					void * newPtr = GC_REALLOC(nl->data, (nLength+50)*sizeof(struct Tok ));
					//memcpy(newPtr, nl->data, (nLength)*sizeof(struct Tok ));
					nl->data = newPtr;
				}
				nl->data[len(nl)]=t;
				nl->length = nLength+1;
			} else {
				nl->data[len(nl)]=t;
			};
			};
i=i+1;
continue;
}
i=i+1;
if ((i<len( line ) )) {
struct Tok nt=line->data[i];
if ((strcmp(nt.cont,"{")==0)) {
i=i+1;
struct cStruct* s=searchStruct( t.cont , elems ) ;
if ((s==null)) {
throwErr( &t , "Unknown struct name {TOKEN}." ) ;
}
char * memory="";
while ((i<len( line ) )) {
t=line->data[i];
if ((strcmp(t.cont,"}")==0)) {
break;
}
memory=concatCPSTRING(concatCPSTRING(memory, t.cont), " ");
i=i+1;
};
t.bahType=s->name;
t.cont=concatCPSTRING(concatCPSTRING("{", memory), "}");
t.isValue=true;

			{
				long nLength = len(nl);
			if (nl->length < nLength+1) {
				if ((nLength+1) % 50 == 0 || nLength == 0) {
					void * newPtr = GC_REALLOC(nl->data, (nLength+50)*sizeof(struct Tok ));
					//memcpy(newPtr, nl->data, (nLength)*sizeof(struct Tok ));
					nl->data = newPtr;
				}
				nl->data[len(nl)]=t;
				nl->length = nLength+1;
			} else {
				nl->data[len(nl)]=t;
			};
			};
i=i+1;
continue;
}
else {
i=i-1;
}
}
}

			{
				long nLength = len(nl);
			if (nl->length < nLength+1) {
				if ((nLength+1) % 50 == 0 || nLength == 0) {
					void * newPtr = GC_REALLOC(nl->data, (nLength+50)*sizeof(struct Tok ));
					//memcpy(newPtr, nl->data, (nLength)*sizeof(struct Tok ));
					nl->data = newPtr;
				}
				nl->data[len(nl)]=t;
				nl->length = nLength+1;
			} else {
				nl->data[len(nl)]=t;
			};
			};
i=i+1;
};
return nl ;
};
array(struct Tok )* parseStructVars(array(struct Tok )* line,void *__BAH_PTR__elems){
struct Elems* elems=__BAH_PTR__elems;
array(struct Tok ) *nl = memoryAlloc(sizeof(array(struct Tok )));
nl->length=0;
nl->elemSize=sizeof(struct Tok );
nl->data;
long int i=0;
while ((i<len( line ) )) {
struct Tok t=line->data[i];
if ((t.type==TOKEN_TYPE_VAR)) {
i=i+1;
while ((i<len( line ) )) {
struct Tok it=line->data[i];
if ((strcmp(it.cont,".")!=0)) {
break;
}
struct variable* v=searchVar( t.cont , elems ) ;
if ((v==null)) {
throwErr( &t , "Unknown var {TOKEN}." ) ;
}
struct string ct=string( v->type ) ;
char * sep=".";
if (ct.count( &ct , "*" ) ) {
sep="->";
}
struct cStruct* s=searchStruct( v->type , elems ) ;
i=i+1;
struct Tok nt=line->data[i];
if ((nt.type!=TOKEN_TYPE_VAR)) {
throwErr( &nt , "Cannot use {TOKEN} as struct member name." ) ;
}
struct structMemb* memb=searchStructMemb( nt.cont , s , elems ) ;
if ((memb==null)) {
throwErr( &nt , "Unknown struct member {TOKEN}." ) ;
}
t.cont=concatCPSTRING(concatCPSTRING(t.cont, sep), memb->name);
i=i+1;
};

			{
				long nLength = len(nl);
			if (nl->length < nLength+1) {
				if ((nLength+1) % 50 == 0 || nLength == 0) {
					void * newPtr = GC_REALLOC(nl->data, (nLength+50)*sizeof(struct Tok ));
					//memcpy(newPtr, nl->data, (nLength)*sizeof(struct Tok ));
					nl->data = newPtr;
				}
				nl->data[len(nl)]=t;
				nl->length = nLength+1;
			} else {
				nl->data[len(nl)]=t;
			};
			};
continue;
}

			{
				long nLength = len(nl);
			if (nl->length < nLength+1) {
				if ((nLength+1) % 50 == 0 || nLength == 0) {
					void * newPtr = GC_REALLOC(nl->data, (nLength+50)*sizeof(struct Tok ));
					//memcpy(newPtr, nl->data, (nLength)*sizeof(struct Tok ));
					nl->data = newPtr;
				}
				nl->data[len(nl)]=t;
				nl->length = nLength+1;
			} else {
				nl->data[len(nl)]=t;
			};
			};
i=i+1;
};
return nl ;
};
array(struct Tok )* parseArrayType(array(struct Tok )* line,void *__BAH_PTR__elems){
struct Elems* elems=__BAH_PTR__elems;
array(struct Tok ) *nl = memoryAlloc(sizeof(array(struct Tok )));
nl->length=0;
nl->elemSize=sizeof(struct Tok );
nl->data;
long int i=0;
while ((i<len( line ) )) {
struct Tok t=line->data[i];
if ((strcmp(t.cont,"[")==0)) {
i=i+1;
if ((i<len( line ) )) {
t=line->data[i];
if ((strcmp(t.cont,"]")==0)) {
i=i+1;
if ((i<len( line ) )) {
t=line->data[i];
if ((t.type!=TOKEN_TYPE_VAR)) {
throwErr( &t , "Cannot use {TOKEN} as array type." ) ;
}
char * arrElem=t.cont;
t.bahType=concatCPSTRING("[]", arrElem);
t.cont="";
t.isValue=true;

			{
				long nLength = len(nl);
			if (nl->length < nLength+1) {
				if ((nLength+1) % 50 == 0 || nLength == 0) {
					void * newPtr = GC_REALLOC(nl->data, (nLength+50)*sizeof(struct Tok ));
					//memcpy(newPtr, nl->data, (nLength)*sizeof(struct Tok ));
					nl->data = newPtr;
				}
				nl->data[len(nl)]=t;
				nl->length = nLength+1;
			} else {
				nl->data[len(nl)]=t;
			};
			};
i=i+1;
continue;
}
}
}
}

			{
				long nLength = len(nl);
			if (nl->length < nLength+1) {
				if ((nLength+1) % 50 == 0 || nLength == 0) {
					void * newPtr = GC_REALLOC(nl->data, (nLength+50)*sizeof(struct Tok ));
					//memcpy(newPtr, nl->data, (nLength)*sizeof(struct Tok ));
					nl->data = newPtr;
				}
				nl->data[len(nl)]=t;
				nl->length = nLength+1;
			} else {
				nl->data[len(nl)]=t;
			};
			};
i=i+1;
};
return nl ;
};
void  parseVar(array(struct Tok )* l,void *__BAH_PTR__elems){
struct Elems* elems=__BAH_PTR__elems;
l=parseStructType( l , elems ) ;
int isEqual=false;
char * currentType="";
struct Tok ft=l->data[0];
struct variable* v=searchVar( ft.cont , elems ) ;
int exists=true;
if ((v==null)) {
exists=false;
v=GC_malloc(sizeof(struct variable));
v->name="";
v->type="";
v->name=ft.cont;
v->type="";
}
char * code="";
long int arrayLength=0;
long int i=1;
while ((i<len( l ) )) {
struct Tok t=l->data[i];
if ((t.type==TOKEN_TYPE_SYNTAX)) {
if ((strcmp(t.cont,"=")==0)) {
if ((strlen( currentType ) >0)) {
struct string sct=string( currentType ) ;
sct.replace( &sct , " " , "" ) ;
v->type=sct.str( &sct ) ;
}
isEqual=true;
i=i+1;
continue;
}
}
if ((isEqual==false)) {
if ((t.type!=TOKEN_TYPE_VAR)) {
if ((strcmp(t.cont,"*")!=0)) {
throwErr( &t , "Cannot use {TOKEN} as type for a variable." ) ;
}
}
currentType=concatCPSTRING(concatCPSTRING(currentType, " "), t.cont);
}
else {
if ((t.isValue==false)) {
throwErr( &t , "Cannot use {TOKEN} as value in var declaration." ) ;
}
char * tp=getTypeFromToken( &t , true , elems ) ;
if (exists) {
if ((strcmp(tp,v->type)!=0)) {
throwErr( &t , concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING("Cannot use {TOKEN} (", tp), ") as "), v->type), ".") ) ;
}
}
else {
if ((strlen( v->type ) ==0)) {
v->type=tp;
}
else {
if ((strcmp(tp,v->type)!=0)) {
throwErr( &t , concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING("Cannot use {TOKEN} (", tp), ") as "), v->type), ".") ) ;
}
}
}
struct string cvt=string( v->type ) ;
if (cvt.hasPrefix( &cvt , "[]" ) ) {
struct string arrType=getCType( v->type , elems ) ;
arrType.trimRight( &arrType , 1 ) ;
char * arrTypeStr=arrType.str( &arrType ) ;
code=concatCPSTRING(concatCPSTRING("memoryAlloc(sizeof(", arrTypeStr), "))");
char * strArrayLength;
arrType.trimLeft( &arrType , 6 ) ;
arrType.trimRight( &arrType , 1 ) ;
struct string elemType=getCType( arrType.str(&arrType) , elems ) ;
char * elemTypeStr=elemType.str( &elemType ) ;
long int max=i+1;
if ((max!=len( l ) )) {
i=i+1;
struct Tok nt=l->data[i];
if ((strcmp(nt.cont,"{")!=0)) {
throwErr( &l->data[i+1] , "{TOKEN} not expected after array initialization." ) ;
}
struct string elemBahType=string( v->type ) ;
elemBahType.trimLeft( &elemBahType , 2 ) ;
char * elemBahTypeStr=elemBahType.str( &elemBahType ) ;
i=i+1;
while ((i<len( l ) )) {
t=l->data[i];
char * tt=getTypeFromToken( &t , true , elems ) ;
if ((strcmp(tt,elemBahTypeStr)!=0)) {
throwErr( &t , concatCPSTRING(concatCPSTRING(concatCPSTRING("Cannot use {TOKEN} (", tt), ") as "), elemBahTypeStr) ) ;
}
strArrayLength=intToStr( arrayLength ) ;
arrayLength=arrayLength+1;
NEXT_LINE=concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(NEXT_LINE, v->name), "->data["), strArrayLength), "] = "), t.cont), ";\n");
i=i+1;
t=l->data[i];
if ((strcmp(t.cont,",")!=0)) {
if ((strcmp(t.cont,"}")==0)) {
long int allocLength=arrayLength;
if ((allocLength>50)) {
long int modAllocAmm=allocLength%50;
allocLength=allocLength+modAllocAmm;
}
else {
allocLength=50;
}
NEXT_LINE=concatCPSTRING(concatCPSTRING(concatCPSTRING(v->name, "->data = memoryAlloc(sizeof("), elemTypeStr), ") * ")+allocLength+concatCPSTRING(");", NEXT_LINE);
break;
}
else {
throwErr( &t , "Expected ',' got {TOKEN}." ) ;
}
}
i=i+1;
};
}
strArrayLength=intToStr( arrayLength ) ;
NEXT_LINE=concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING("\n                ", v->name), "->length = "), strArrayLength), ";\n                "), v->name), "->elemSize = sizeof("), elemTypeStr), ");\n                "), NEXT_LINE);
break;
}
struct string ctc=string( t.cont ) ;
if (ctc.hasPrefix( &ctc , "{" ) ) {
long int max=i+1;
if ((max!=len( l ) )) {
throwErr( &l->data[i+1] , "{TOKEN} not expected after struct initialization." ) ;
}
struct cStruct* s=searchStruct( v->type , elems ) ;
NEXT_LINE=declareStructMethods( v , s ) ;
}
code=concatCPSTRING(concatCPSTRING(code, " "), t.cont);
}
i=i+1;
};
if (exists) {
if ((strlen( code ) ==0)) {
throwErr( &ft , "Cannot re-declare {TOKEN}." ) ;
}
if ((strlen( currentType ) >0)) {
struct Tok st=l->data[1];
throwErr( &st , concatCPSTRING(concatCPSTRING("Cannot change the type of already declared var '", ft.cont), "' to {TOKEN}.") ) ;
}
code=concatCPSTRING(concatCPSTRING(v->name, " = "), code);
}
else {
if ((strlen( currentType ) >0)) {
v->type=currentType;
}
if ((strlen( v->type ) ==0)) {
throwErr( &ft , "Cannot declare {TOKEN} without a type." ) ;
}
char * vct=setCType( v , elems ) ;
if ((strlen( code ) >0)) {
code=concatCPSTRING(concatCPSTRING(vct, " = "), code);
}
else {
code=vct;
}
}
OUTPUT=concatCPSTRING(concatCPSTRING(OUTPUT, code), ";\n");
array(struct variable* ) *vars=elems->vars;

			{
				long nLength = len(vars);
			if (vars->length < nLength+1) {
				if ((nLength+1) % 50 == 0 || nLength == 0) {
					void * newPtr = GC_REALLOC(vars->data, (nLength+50)*sizeof(struct variable ));
					//memcpy(newPtr, vars->data, (nLength)*sizeof(struct variable ));
					vars->data = newPtr;
				}
				vars->data[len(vars)]=v;
				vars->length = nLength+1;
			} else {
				vars->data[len(vars)]=v;
			};
			};
};
void  parseStruct(array(struct Tok )* l,void *__BAH_PTR__elems){
struct Elems* elems=__BAH_PTR__elems;
struct cStruct* s=GC_malloc(sizeof(struct cStruct));
s->name="";
s->members=memoryAlloc(sizeof(array(struct structMemb* )));
;
s->postCode="";
s->extendedFrom="";
if ((len( l ) <4)) {
throwErr( &l->data[len(l)-1] , "Cannot declare struct has such, please do 'struct <name> { <memberName>:<memberType> }'." ) ;
}
struct Tok nameToken=l->data[1];
if ((nameToken.type!=TOKEN_TYPE_VAR)) {
throwErr( &nameToken , "Cannot use {TOKEN} as struct name." ) ;
}
struct cStruct* os=searchStruct( nameToken.cont , elems ) ;
if ((os!=null)) {
throwErr( &nameToken , "Struct {TOKEN} already exists." ) ;
}
s->name=nameToken.cont;
array(struct structMemb* ) *members=s->members;
long int i=2;
struct Tok st=l->data[i];
if ((st.type==TOKEN_TYPE_KEYWORD)) {
if ((strcmp(st.cont,"extend")==0)) {
i=i+1;
struct Tok extdSNameTk=l->data[i];
i=i+1;
if ((extdSNameTk.type!=TOKEN_TYPE_VAR)) {
throwErr( &extdSNameTk , "Cannot use {TOKEN} as struct name." ) ;
}
struct cStruct* extdS=searchStruct( extdSNameTk.cont , elems ) ;
if ((extdS==null)) {
throwErr( &extdSNameTk , "Struct {TOKEN} does not exist." ) ;
}
members=extdS->members;
}
else {
throwErr( &st , "Cannot use keyword {TOKEN} in struct declaration." ) ;
}
}
struct Tok braceTk=l->data[i];
i=i+1;
if ((strcmp(braceTk.cont,"{")!=0)) {
throwErr( &braceTk , "Cannot use {TOKEN} in struct declaration." ) ;
}
while ((i<len( l ) )) {
struct Tok t=l->data[i];
long int max=i+2;
if ((max>=len( l ) )) {
if ((t.type==TOKEN_TYPE_ENCL)) {
if ((strcmp(t.cont,"}")==0)) {
break;
}
}
throwErr( &l->data[len(l)-1] , "Not enough argument in member declaration, ending by {TOKEN}." ) ;
}
struct structMemb* memb=GC_malloc(sizeof(struct structMemb));
memb->name="";
memb->type="";
memb->def="";
if ((t.type!=TOKEN_TYPE_VAR)) {
throwErr( &t , "Cannot use {TOKEN} as member name." ) ;
}
memb->name=t.cont;
long int ii=0;
while ((ii<len( members ) )) {
struct structMemb *m=members->data[ii];
if ((strcmp(m->name,memb->name)==0)) {
throwErr( &t , "Member {TOKEN} has already been declared." ) ;
}
ii=ii+1;
};
i=i+1;
t=l->data[i];
if ((strcmp(t.cont,":")!=0)) {
throwErr( &t , "Member name should be followed by ':' not {TOKEN}." ) ;
}
i=i+1;
t=l->data[i];
if ((t.type!=TOKEN_TYPE_VAR)) {
throwErr( &t , "Cannot use {TOKEN} as member type." ) ;
}
memb->type=t.cont;
i=i+1;
t=l->data[i];
if ((i<len( l ) )) {
if ((strcmp(t.cont,"=")==0)) {
i=i+1;
t=l->data[i];
if ((t.isValue==false)) {
throwErr( &t , "Cannot use {TOKEN} as default value for member." ) ;
}
char * tt=getTypeFromToken( &t , true , elems ) ;
if ((strcmp(tt,memb->type)!=0)) {
throwErr( &t , concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING("Cannot use {TOKEN} (", tt), ") as "), memb->type), " for member.") ) ;
}
memb->def=t.cont;
}
else {
i=i-1;
}
}

			{
				long nLength = len(members);
			if (members->length < nLength+1) {
				if ((nLength+1) % 50 == 0 || nLength == 0) {
					void * newPtr = GC_REALLOC(members->data, (nLength+50)*sizeof(struct structMemb ));
					//memcpy(newPtr, members->data, (nLength)*sizeof(struct structMemb ));
					members->data = newPtr;
				}
				members->data[len(members)]=memb;
				members->length = nLength+1;
			} else {
				members->data[len(members)]=memb;
			};
			};
s->members=members;
i=i+1;
};
array(struct cStruct* ) *structs=elems->structs;

			{
				long nLength = len(structs);
			if (structs->length < nLength+1) {
				if ((nLength+1) % 50 == 0 || nLength == 0) {
					void * newPtr = GC_REALLOC(structs->data, (nLength+50)*sizeof(struct cStruct ));
					//memcpy(newPtr, structs->data, (nLength)*sizeof(struct cStruct ));
					structs->data = newPtr;
				}
				structs->data[len(structs)]=s;
				structs->length = nLength+1;
			} else {
				structs->data[len(structs)]=s;
			};
			};
char * code=concatCPSTRING(concatCPSTRING("struct ", s->name), " {\n");
i=0;
while ((i<len( members ) )) {
struct structMemb *m=members->data[i];
struct string membCType=getCType( m->type , elems ) ;
char * membCTypeStr=membCType.str( &membCType ) ;
code=concatCPSTRING(concatCPSTRING(concatCPSTRING(concatCPSTRING(code, membCTypeStr), " "), m->name), ";\n");
i=i+1;
};
code=concatCPSTRING(code, "};\n");
OUTPUT=concatCPSTRING(OUTPUT, code);
};
array(struct Tok )* prePross(array(struct Tok )* line,void *__BAH_PTR__elems){
struct Elems* elems=__BAH_PTR__elems;
line=parseArrayType( line , elems ) ;
line=parseStructVars( line , elems ) ;
line=parseCast( line , elems ) ;
line=parseOperations( line , elems ) ;
return line ;
};
void  parseLine(array(struct Tok )* line,void *__BAH_PTR__elems){
struct Elems* elems=__BAH_PTR__elems;
if ((len( line ) ==0)) {
return ;
}
lineType ltp=getLineType( line ) ;
line=prePross( line , elems ) ;
if ((ltp==LINE_TYPE_VAR)) {
parseVar( line , elems ) ;
}
else if ((ltp==LINE_TYPE_STRUCT)) {
parseStruct( line , elems ) ;
}
else {
char * ltps=intToStr( (long int )ltp ) ;
println( concatCPSTRING("===>", ltps) ) ;
}
if ((strlen( NEXT_LINE ) >0)) {
OUTPUT=concatCPSTRING(OUTPUT, NEXT_LINE);
NEXT_LINE="";
}
};
void  parseLines(array(struct Tok )* tokens,void *__BAH_PTR__elems){
struct Elems* elems=__BAH_PTR__elems;
array(struct Tok ) *line = memoryAlloc(sizeof(array(struct Tok )));
line->length=0;
line->elemSize=sizeof(struct Tok );
line->data;
struct Tok ft=tokens->data[0];
long int currentLine=ft.line;
long int nbEncl=0;
long int i=0;
while ((i<len( tokens ) )) {
struct Tok t=tokens->data[i];
if ((t.type==TOKEN_TYPE_ENCL)) {
if ((strcmp(t.cont,"(")==0)) {
nbEncl=nbEncl+1;
}
else if ((strcmp(t.cont,")")==0)) {
nbEncl=nbEncl-1;
}
else if ((strcmp(t.cont,"{")==0)) {
nbEncl=nbEncl+1;
}
else if ((strcmp(t.cont,"}")==0)) {
nbEncl=nbEncl-1;
}
else if ((strcmp(t.cont,"[")==0)) {
nbEncl=nbEncl+1;
}
else if ((strcmp(t.cont,"]")==0)) {
nbEncl=nbEncl-1;
}
}
if ((nbEncl==0)) {
if ((t.line!=currentLine)) {
if ((t.type==TOKEN_TYPE_ENCL)) {

			{
				long nLength = len(line);
			if (line->length < nLength+1) {
				if ((nLength+1) % 50 == 0 || nLength == 0) {
					void * newPtr = GC_REALLOC(line->data, (nLength+50)*sizeof(struct Tok ));
					//memcpy(newPtr, line->data, (nLength)*sizeof(struct Tok ));
					line->data = newPtr;
				}
				line->data[len(line)]=t;
				line->length = nLength+1;
			} else {
				line->data[len(line)]=t;
			};
			};
struct Tok pt=tokens->data[i-1];
currentLine=pt.line;
}
else {
currentLine=t.line;
}
parseLine( line , elems ) ;
clear( line ) ;
if ((t.type==TOKEN_TYPE_ENCL)) {
i=i+1;
continue;
}
}
}

			{
				long nLength = len(line);
			if (line->length < nLength+1) {
				if ((nLength+1) % 50 == 0 || nLength == 0) {
					void * newPtr = GC_REALLOC(line->data, (nLength+50)*sizeof(struct Tok ));
					//memcpy(newPtr, line->data, (nLength)*sizeof(struct Tok ));
					line->data = newPtr;
				}
				line->data[len(line)]=t;
				line->length = nLength+1;
			} else {
				line->data[len(line)]=t;
			};
			};
i=i+1;
};
if ((len( line ) >0)) {
if ((nbEncl==0)) {
parseLine( line , elems ) ;
clear( line ) ;
}
else {
ft=line->data[len(line)-1];
throwErr( &ft , "Missing closing token, line ending by {TOKEN}." ) ;
}
}
};
void  main(array(char * )* args){
if ((len( args ) !=2)) {
panic( "Invalid usage of bah." ) ;
}
char * fileName=args->data[1];
struct fileMap fm={};
fm.open=fileMap__open;
fm.isValid=fileMap__isValid;
fm.close=fileMap__close;
char * f=fm.open( &fm , fileName ) ;
array(struct Tok ) *tokens=lexer( f ) ;
fm.close( &fm ) ;
if ((len( tokens ) ==0)) {
panic( concatCPSTRING(concatCPSTRING("File '", fileName), "' not recognized.") ) ;
}
struct Elems* elems=GC_malloc(sizeof(struct Elems));
elems->vars=memoryAlloc(sizeof(array(struct variable* )));
;
elems->structs=memoryAlloc(sizeof(array(struct cStruct* )));
;
elems->types=memoryAlloc(sizeof(array(char * )));
;
parseLines( tokens , elems ) ;
println( OUTPUT ) ;
};
