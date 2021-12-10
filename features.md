# List of all features
Here is a list of most of the features supported by the Bah compiler.

| Name | Description | Support | Example |
| ---- | ----------- | ------- | ------- |
| Keywords | These are used for modifying code behavior at compile time, such as #include #define #cLib #linux... | All keywords are fully supported except for #macro. | `#include "iostream.bah"` |
| Conditional statements | Used for changing code behavior at runtime, such as if/else statements and for loops with continue and break. | Fully supported. | `if a == b { println("a is equal to b!") }` |
| Declarations | Variable, constant, function, type and function binding declaration. <br>-> A type declared will be handled by the compiler as a fully new type, without any link to the old one. <br>-> A variable can be declared with a type without any value and defined with a value without precising its type. <br>-> Function binding and types are defined using the #define keyword. | Fully supported. | `test(a int) int { return a + 1 }` |
| Operations | Using an operation between two values as a value. <br>-> This includes string operations and struct operation. <br>-> Defining an operation for a struct type can be made by defining its methods named `.add() .mult() .div() .sub()`. | Fully supported except for bitwise operations (this will come soon). | `a + b` |
| Casting | Casting a variable with a new type. <br>-> Inline casting with `<type>value` if the type only contains alphanumerical characters. <br>-> Declaring a variable with a specific type independently from its value with `var type = value` | Fully supported except if inline cast contains non alphanumerical character such as a '*' | `a int = <ptr>"this is a string casted as a pointer"` |
| Structures | <br>-> Declaring a structure using the `struct <name> {<fields>}` where there is one field by line. <br>->  Methods are declared as usual functions inside the fields. <br>-> A default value can be set for every field with the '=' operator followed by a constant value. <br>-> Here is a field declaration syntax `field: type = defaultValue` with an optional default value. <br>-> A new variable with a struct type can be allocated on the stack with `a = myStruct{}` or on the heap, returnning a pointer to the struct as `a = new myStruct`. <br>-> Accessing a variable's field is done by separating fields with a '.'. | Fully supported. | `a = new myStruct; a.numberFiled = 12` |
| Arrays | Arrays are dynamic lists of elements. <br>-> Appending to an array will automatically grow the array if needed. It can be done by setting the element with an index equal to the array's length. If attempting to append an element larger than the length of the array, it will lead to undefined behavior. <br>-> An array var points to a location in the stack. <br>-> The length of an array can be returned using the `len(array) int` function. <br>-> When declaring an array, you can use brackets to fill its initial values separated by a coma. <br>-> The indexing of arrays starts at 0. | Fully supported. | `arr = []type{value1, value2}; arr[2] = value3` |
| Booleans | A boolean is a datatype that is either true or false.<br>-> It can be defined as a condition `a operator b` etc... using the operators `==`, `!=`, `>`, `<`, `>=`, `<=` and combinned using the logic operators `\|\|` (or) and `&&` (and). <br>-> It can also be defined with the keywords `true` and `false`. | Fully supported. | `isAequalTo55 = a == 55` |
| Pointers | A pointer is a reference to a memory block. <br>-> A pointer to a var can be made using `&a`. <br>-> Accessing the content of a pointer can be made using `*a` | Supported with undefined behaviors on structures fields. | `a = 32; pointerToA = &a; contentOfA = *pointerToA` |
| Reflection | When including the "reflect.bah" library, you can get a reflection of a var as a function argument by declaring a function argument with the type `reflectElement`. <br>-> A reflection of a variable is used for getting informations about its type at runtime. | Supported with some occasional bugs. | `printType(e reflectElement) {println(a.type)} a = 10; printType(a)` |
| Function calls | A function can be called and used as a value as following: `functionName(<args>)`. <br>-> The args needs to be separated by comas where every argument is a value. <br>-> The number of arguments passed to the function must be equal to the number of argument when declaring the function. | Fully supported. | `println("Hi!")` |
| Function pointers | A variable can be declared as a function pointer by defining its type as `function(args)`. <br>-> You can then point to a function with a function pointer using `functionPointer = functionName`. | Fully supported. | `printFunction = println; printFuncion("Hi!")` |
| Function bindings | You can bind a function from a C library using `#define! functionName(<args>) returnType`. <br>-> If you want to pre-declare a function, you can use `#define functionName(<args>) returnType`. | Fully supported. | `#define! print(s cpstring)` |
| C library | You can link the program with a C library using the `#cLib` keyword followed by libraries to link inside double quotes. | Fully supported. | `#cLib "lm" "lpthread"` |
| Constant | A constant can be declared using a constant value using the `const` keyword. <br>-> You cannot change the value of a constant. | Supported with undefined behaviors if reusing const name in other scopes. | `const myConst = 23` |
| Return | When declaring a function, you can make it return a value while stopping its execution using the `return` keyword followed by a value. | Fully suported. | `return "I'm a return value."` |

If **you find any bug** with the features listed above or you feel a **feature should be detailed in the table above**, you can open an issue on the [repository](https://github.com/ithirzty/bah) or by [contacting me](mailto:alois@alois.xyz).