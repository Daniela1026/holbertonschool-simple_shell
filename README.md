![Algorithm schema](./images/holberton.jpg)

# Simple Shell Project 🤓🚀


## What is a simple shell❔📎

What is a simple shell. This is a simple implementation of the command line interpreter for the Unix operating system created this time by the holbis.

## Files Description Shell 📋

* **AUTHORS** - List of contributors to this repository
* **man_1_simple_shell** - Manual page for the simple_shell
* **shell.h** - Header File
* **shell.c** - Main Function
* **hello.c** - Check the code Betty
* **hsh_execbuilt.c** - 
    * **read_line** - Use getline
    * **token_generate** - Generate token
    * **execute** - Execute new process
    * **cmd** - Parse Command 
* **hsh_strfunc.c** - Function to get the arguments
    * **_strlen** - Length of the string
    * **_strcat** - Concatenates two strings
    * **_strcpy** - Copies string
    * **_strdup** - Duplicate one string
    * **_strcmp** - Comparation string
* **hsh_supbuilt.c** - Command required for builtin
    * **builtin_cmd** - We get the commands
    * **h_exit** - Commands the builtin
    * **h_cd** - Commands the builtin
    * **h_help** - Commands the builtin
    * **h_env** - Commands the builtin

## Usage Simple Shell ⚙️

* **Step 1:** Clone our repository using this command
```
git clone https://github.com/Daniela1026/holbertonschool-simple_shell.git
```
* **Step 2:** Change directory to holbertonschool-simple_shell
```
cd holbertonschool-simple_shell
```
* **Step 3:** Compile the C files in this way
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
* **Step 4:** Run the shell
```
./hsh
```
* **Step 5:** Example interactive mode with **/bin/ls**, **ls**, **ls -la**
```
$ /bin/ls
AUTHORS  README.md  hello.c  hsh  hsh_execbuilt.c  hsh_strfunc.c  hsh_supbuilt.c  man_1_simple_shell  shell.c  shell.h

$ ls
AUTHORS  README.md  hello.c  hsh  hsh_execbuilt.c  hsh_strfunc.c  hsh_supbuilt.c  man_1_simple_shell  shell.c  shell.h

$ ls -la
total 49
drwxr-xr-x 1 luiyi_fhb luiyi_fhb   512 Aug 18 12:32 .
drwxr-xr-x 1 luiyi_fhb luiyi_fhb   512 Aug 17 22:39 ..
drwxr-xr-x 1 luiyi_fhb luiyi_fhb   512 Aug 17 22:38 .git
-rw-r--r-- 1 luiyi_fhb luiyi_fhb   165 Aug 17 22:38 AUTHORS
-rw-r--r-- 1 luiyi_fhb luiyi_fhb    16 Aug 17 22:38 README.md
-rw-r--r-- 1 luiyi_fhb luiyi_fhb   132 Aug 17 22:38 hello.c
-rwxr-xr-x 1 luiyi_fhb luiyi_fhb 18264 Aug 18 11:05 hsh
-rw-r--r-- 1 luiyi_fhb luiyi_fhb  2250 Aug 18 11:05 hsh_execbuilt.c
-rw-r--r-- 1 luiyi_fhb luiyi_fhb  1458 Aug 17 22:38 hsh_strfunc.c
-rw-r--r-- 1 luiyi_fhb luiyi_fhb  1380 Aug 17 22:38 hsh_supbuilt.c
-rw-r--r-- 1 luiyi_fhb luiyi_fhb     0 Aug 17 22:38 man_1_simple_shell
-rwxr-xr-x 1 luiyi_fhb luiyi_fhb   532 Aug 18 12:32 shell.c
-rw-r--r-- 1 luiyi_fhb luiyi_fhb   923 Aug 17 22:38 shell.h
```
* **Step 6:** Example non-interactive mode with **echo "/bin/ls" | ./hsh**, **echo "ls" | ./hsh**, **echo "ls -la" | ./hsh**
```
dev@DESKTOP:~$ echo '/bin/ls' | ./hsh
AUTHORS  README.md  hello.c  hsh  hsh_execbuilt.c  hsh_strfunc.c  hsh_supbuilt.c  man_1_simple_shell  shell.c  shell.h
dev@DESKTOP:~$

dev@DESKTOP:~$ echo 'ls' | ./hsh
AUTHORS  README.md  hello.c  hsh  hsh_execbuilt.c  hsh_strfunc.c  hsh_supbuilt.c  man_1_simple_shell  shell.c  shell.h
dev@DESKTOP:~$ 

dev@DESKTOP:~$ echo 'ls -la' | ./hsh
total 49
drwxr-xr-x 1 luiyi_fhb luiyi_fhb   512 Aug 18 12:32 .
drwxr-xr-x 1 luiyi_fhb luiyi_fhb   512 Aug 17 22:39 ..
drwxr-xr-x 1 luiyi_fhb luiyi_fhb   512 Aug 17 22:38 .git
-rw-r--r-- 1 luiyi_fhb luiyi_fhb   165 Aug 17 22:38 AUTHORS
-rw-r--r-- 1 luiyi_fhb luiyi_fhb    16 Aug 17 22:38 README.md
-rw-r--r-- 1 luiyi_fhb luiyi_fhb   132 Aug 17 22:38 hello.c
-rwxr-xr-x 1 luiyi_fhb luiyi_fhb 18264 Aug 18 11:05 hsh
-rw-r--r-- 1 luiyi_fhb luiyi_fhb  2250 Aug 18 11:05 hsh_execbuilt.c
-rw-r--r-- 1 luiyi_fhb luiyi_fhb  1458 Aug 17 22:38 hsh_strfunc.c
-rw-r--r-- 1 luiyi_fhb luiyi_fhb  1380 Aug 17 22:38 hsh_supbuilt.c
-rw-r--r-- 1 luiyi_fhb luiyi_fhb     0 Aug 17 22:38 man_1_simple_shell
-rwxr-xr-x 1 luiyi_fhb luiyi_fhb   532 Aug 18 12:32 shell.c
-rw-r--r-- 1 luiyi_fhb luiyi_fhb   923 Aug 17 22:38 shell.h
dev@DESKTOP:~$  
```
## Requirements 👓

* Allowed editors: `vi`, `vim`, `emacs`
* All files will be compiled on `Ubuntu 14.04 LTS`
* Programs and functions will be compiled with `gcc 4.8.4` using the flats `-Wall` `-Werror` `-Wextra` `-pedantic` `-std=gnu89`
* The files will end with a new line
* A `README.md` file, at the root of the folder of the project is mandatory
* The code use the `Betty` style. It will be checked using [betty-style.pl](https://github.com/holbertonschool/Betty/blob/master/betty-style.pl) and [betty-doc.pl](https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl)
* Your shell should not have any memory leaks 
* No more than 5 functions per file
* All your header files should be include guarded
* Use system calls only when you need to [why?](https://www.quora.com/Why-are-system-calls-expensive-in-operating-systems)

## Authors ✒️

* 👩🏻‍💻**Daniela Cartagena** - [Daniela](https://github.com/Daniela1026)
* 👩🏻‍💻**Johanna Balcazar** - [Johanna](https://github.com/LiJoBaZar)
* 👨🏻‍💻**Luiyi Hurtado** - [Luiyi](https://github.com/Luiyi-F)



