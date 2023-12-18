# C - Simple Shell Group Project
Team: Isa Guliyev, Aydan Jafarli

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


