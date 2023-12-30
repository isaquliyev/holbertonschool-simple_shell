# C - Simple Shell Group Project
Team: Isa Guliyev, Aydan Jafarli

## HSH: The Holberton SHELL
In a software engineering context, a shell is a user interface that provides access to an operating system's services. When you're working on a Holberton Shell project, it likely involves creating a simple shell program that can interpret and execute commands.
## GENERAL
-**Who designed and implemented the original Unix operating system:**

-The original Unix operating system was designed and implemented by Ken Thompson, Dennis Ritchie, and others at Bell Labs (AT&T) in the early 1970s.
-**Who wrote the first version of the UNIX shell**

-Ken Thompson wrote the first version of the UNIX shell, known as the Thompson shell or sh.

-**Who invented the B programming language (the direct predecessor to the C programming language)**

-Ken Thompson invented the B programming language.

-**Who is Ken Thompson**

-Ken Thompson is a computer scientist and one of the key developers of the Unix operating system. He also contributed to the development of the B programming language and, along with Dennis Ritchie, played a significant role in creating the C programming language.

-**How does a shell work?**

-A shell serves as a pivotal command-line interpreter, bridging the interaction between users and the operating system. Functioning as an intermediary interface, it welcomes commands from users and orchestrates their execution. Essentially, the shell operates as a conduit, facilitating seamless communication between the user's instructions and the underlying functions of the operating system.

-**What is a pid and a ppid?**

-PID (Process ID):
A PID is a unique numerical identifier assigned to each running process in an operating system.
It is used to distinguish one process from another.
PIDs are assigned dynamically as processes are created, and they are recycled when a process terminates.
PIDs are essential for various operations, such as terminating or signaling specific processes.
-PPID (Parent Process ID):
PPID refers to the PID of the parent process that spawned or created a particular process.
Every process, except for the initial or root process (usually with PID 1), has a parent process.
The PPID is used to establish the hierarchical or parent-child relationship between processes.
When a process is created, the PPID of the new process is set to the PID of the process that created it.

-**How to manipulate the environment of the current process**

-The environment of the current process can be manipulated using environment variables. Commands like `export` in Unix/Linux shells are used to set environment variables.

-**What is the difference between a function and a system call**

-A function is a piece of code that performs a specific task and is part of a program. A system call is a request for a service from the operating system kernel.

-**How to create processes**

-Processes can indeed be generated using system calls such as fork() in the C programming language. The fork() system call initiates the creation of a new process by duplicating the existing or calling process.

-**What are the three prototypes of main**

-The three prototypes of the `main` function in C are:
    - `int main(void)`
    - `int main(int argc, char *argv[])`
    - `int main(int argc, char *argv[], char *envp[])`

-**How does the shell use the `PATH` to find the programs**

-The shell relies on the PATH environment variable to locate executable files. Upon receiving a command, the shell scans through the directories specified in the PATH to locate the executable file associated with that command.

-**How to execute another program with the `execve` system call**

The `execve()` system call in C is used to execute another program. It replaces the current process image with a new one.
test

-**How to suspend the execution of a process until one of its children terminates**

-The `wait()` system call is used to suspend the execution of a process until one of its child processes terminates.

-**What is `EOF` / “end-of-file”?**

-EOF (End-of-File) is a condition in a file or stream of data that indicates that there is no more data to be read. In Unix-like systems, pressing Ctrl+D at the beginning of a line in the terminal sends an EOF signal.

## Getting HSH
In order to install the shell and get benefits of it's features you need to clone the current project, and compile it.
You need to make sure that this shell tested and garantees work based on `gcc-4.8` and the `C90` standard.

## Requirements

Allowed editors: vi, vim, emacs

All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89

All your files should end with a new line

A README.md file, at the root of the folder of the project is mandatory

Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl

Your shell should not have any memory leaks

No more than 5 functions per file

All your header files should be include guarded

Use system calls only when you need to 


### Compilation

Your code will be compiled this way:

```
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

```

## Tasks

### 0. README, man, AUTHORS
Write a README

Write a man for your shell.

You should have an AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository. Format, see Docker

### 1. Betty would be proud
Write a beautiful code that passes the Betty checks

### 2. Simple shell 0.1
Write a UNIX command line interpreter.

Usage: simple_shell

Your Shell should:

Display a prompt and wait for the user to type a command. A command line always ends with a new line.

The prompt is displayed again each time a command has been executed.

The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.

The command lines are made only of one word. No arguments will be passed to programs.

If an executable cannot be found, print an error message and display the prompt again.

Handle errors.

You have to handle the “end of file” condition (Ctrl+D)

### 3. Simple shell 0.2
Handle command lines with arguments

### 4. Simple shell 0.3

Handle the PATH

fork must not be called if the command doesn’t exist
### 5. Simple shell 0.4

Implement the exit built-in, that exits the shell

Usage: exit

You don’t have to handle any argument to the built-in exit

### 6. Simple shell 1.0

Implement the env built-in, that prints the current environment

## Files

|File|Description|
|---|---|
|[AUTHORS](https://github.com/isaquliyev/holbertonschool-simple_shell/blob/master/AUTHORS)|Contributors in this repository|
|[README.md](https://github.com/isaquliyev/holbertonschool-simple_shell/blob/master/README.md)|Information about this repository|
|[_getline.c](https://github.com/isaquliyev/holbertonschool-simple_shell/blob/master/_getline.c)|Gets input and write it into line|
|[_shell.c](https://github.com/isaquliyev/holbertonschool-simple_shell/blob/master/_shell.c)|Main function for run shell|
|[splitter.c](https://github.com/isaquliyev/holbertonschool-simple_shell/blob/master/splitter.c)|For split and parse inputs|
|[envir.c](https://github.com/isaquliyev/holbertonschool-simple_shell/blob/master/envir.c)|Takes environment variable PATH|
|[man_1_simple_shell](https://github.com/isaquliyev/holbertonschool-simple_shell/blob/master/man_1_simple_shell)|Manual page of this version of Shell|
|[main.h](https://github.com/isaquliyev/holbertonschool-simple_shell/blob/master/header.h)|Used libraries, function prototypes|

## Flowchart

<p align="center"><img src="https://github.com/isaquliyev/holbertonschool-simple_shell/blob/master/assets/flowchart.png"></p>
