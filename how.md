# How does the Bah compiler works?
This system and its implementation were invented and made by Aloïs Laurent Boë.

## Steps
 - **Lexing** the Bah code. This resulting in tokens.
 - **Parsing** the previously generated tokens.
 - **Generating** lower level code from the result of the parsing.

### The lexer
The Bah code in string format is passed through a lexer that will analyse it and generate an array of tokens from it.
The lexer makes an empty array of tokens and populates-it by iterating through every characters of the string.

Note that every variable name is case sensitive.

A token cannot contain any space character and must be contained by a single line (see exceptions below).

#### Classes
There is five classes of tokens:
- **enclavers** (any token that can only enclave other tokens),

    { } ( ) [ ]
- **syntax** tokens (any token that detail the operation to perform),

    ! = | & % + - * / , < > : ;
- **keywords** any token that define the flow of the program or any syntax token that should be represented by a word,

    if else for struct const return extend new break continue function
- **separators** any token that separates two tokens of the same, class.

    .
- **values** any token that is taken as a value. A value is a token containing data rather than a token containing logic.

#### Exceptions
Values are either a variable/function/type name, a char, a string or a number.

A string can contain any character including spaces, is starting by a double quote and ending by a double quote. It can extend to multiple lines. Any character such as a double quote can be inserted in the string if it is escaped, meaning it is precedated by a back slash.

A char is defined by a single character inside two single quotes.

A number is represented either by one or multiple digits if it is an integral number or by one or multiple digits followed by a point and one or multiple digits again.

A variable name is defined by alpha-numeric characters, that can be linked by an underscore.

A hash-keyword is defined the same way as a variable name, precedated by a hash character. These are classed as keywords.

The compiler should be able to ignore comments (starting by two slashes character and ending in a line return).

#### Additional informations
The lexer will take note of the line number, the position, the contentt and the class of a token of the token.


### The parser
The parser will take an array of tokens and generate lower level code.
Doing so, the parser will check for errors that would make the program unclear or not understandable.

#### Lines
The first step will be to separate tokens in lines. 
A line can end only if it contains as much openning enclaver tokens as it contains closing enclaver tokens.
If all of the above conditions are met, a line can be ended by a semicolon or a line return.

#### Pre-processing
Each line will be pre-processed before being parsed.
Low level tokens will then be higher level.

This includes parsing 
- structure var that are variable name separated by a full-stop,
- function calls that are defined by a variable name followed by an opening parenthesis, optional arguments that must be able to be reduced to a value, separated by a coma and finally a closing parenthesis,
- array variables that are defined by a variable name followed by an opening bracket, an index that must be able to be reduced to an integer and finally a closing bracket,
- array types that are defined by an variable name, followed by a opening and a closing braces,
- casts that are defined by a type enclaved in less-than and more-than characters followed by a value,
- operations that are defined by an operand followed by an operator and antother operand,
- booleans that are defined by two operand separated by a boolean operator.

#### Line type
Onced pre-processed, each line is then assigned a type that is how the line should be parsed.
- **Function call** if the line starts with a function token,
- **include** if the line starts with the hash-keyword *#include*,
- **define** (for type declaration/function declaration or binding) if the line starts with the hash-keyword *#define*. This line can be muted by using an exclamation point after the hash-keyword.
- **Constant declaration** if the line starts with the *const* keyword,
- **structure declaration** if the line starts with the *struct* keyword. This line can be muted by using an exclamation point after the hash-keyword.
- **C compiler flag** if the line starts with the hash-keyword *#cLib*,
- **return line** if the line starts with the *return* keyword,
- **iterating flow line** if the line starts with the *for* keyword,
- **logical flow line** if the line starts with a *if*, *else*, *break* or *continue* keyword.

Each line will then be parsed accordingly. For more information about how the lines are parsed, you can refer to the [parser code](https://github.com/ithirzty/bah/blob/main/src/parser.bah).