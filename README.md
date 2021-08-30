# [Bah-lang](https://bah-lang.xyz)

## Installation
> Bah supports only linux and windows for the moment.
Note that windows releases may be delayed compared to linux releases.

To install bah on your machine, get the terminal warmed up 🔥 , stretch your fingers up 🏋‍♂ and paste this 😎:
### Linux
```sh
git clone https://github.com/ithirzty/bah
cd ./bah
sudo ./linux_install.sh
```
If the installation fails for whatever reason, you will need to recompile the Bah compiler
befor installing it. Dont worry this is simple, simply run:
```sh
sudo ./linux_compile_install.sh
```

### Windows
**Please make sure that you have [mingw gcc](https://sourceforge.net/projects/mingw/) installed.**
```bat
git clone https://github.com/ithirzty/bah
cd ./bah
.\windows_install.bat
```
If the installation fails for whatever reason, you will need to recompile the Bah compiler
befor installing it. Dont worry this is simple, simply run:
```bat
.\windows_compile_install.bat
```


[![installation tutorial](https://i9.ytimg.com/vi/druJwBluvLc/mqdefault.jpg?sqp=CMyzpokG&rs=AOn4CLDa29d7a6ZVtodjDIzfLJmd0lakPw)](https://youtu.be/druJwBluvLc)

## Updating
To update, execute the following:
```sh
./linux_update.sh
```
If the repository is updated, this script will pull the main branch and install everything.

## Usage
Files containing bah code have the `.bah` extenstion.
- To compile your program, use `bah myFile.bah`.
- To translate your program as C code, use `bah myFile.bah -c`.
- To set an output name to your program, use the `bah myFile.bah -o myCompiledProgram`.

## Why?
Bah is a really fast language that is low level enough for most cases while being really simple.
As well as being easy to learn, you can create 
- website (such as the [bah-lang](https://bah-lang.xyz) website),
- compilers (the bah compiler is written in bah),
- web apps (the documentation of bah is wrapped up in a [web app](https://github.com/ithirzty/bah-website)),
- and many more.
> You did something awesome in bah? Add it to the list!
