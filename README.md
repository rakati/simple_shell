
<h1  align="center"><img src="https://miro.medium.com/v2/resize:fit:2400/1*E1LonYGC5Fx4QLY4W5SaVA.jpeg" width="100" alt="Udacity logo">ALX-Africa Software Engineering Program</h1>

# Simple Shell Project
A simple shell command interpreter

### Overview

This project is part of the ALX Software Engineering program - Low level programming part.
In this project, we will implement a simple shell based on `csh` and using C89.
Our shell will:
- Display a prompt and wait for the user to type a command. A command line always ends with a new line.
- The prompt is displayed again each time a command has been executed.
- Support command with multiple arguments.
- The command lines handles `semicolons`, `&&`, and `||`
- No pipes, no redirections or any other advanced features.
- If an executable cannot be found, print an error message and display the prompt again.
- Handle errors.
- Handle the “end of file” condition (Ctrl+D)
- Implement some builtins `cd`, `wait`, `env`,  `setenv`, `unsetenv`, `alias`.
- Support comments.
- can be run as in interactive and non interactive mode (passing shell script
  as argument).

### Re-implement some functions:
- `getline`
- `Path` handling.
- strdup`
- realloc`
- `strtok`
- `puts`
- `strlen`
- `strcmp`
- `strncpy`
- `strcat`


### General requirement
- Allowed editors: `vi`, `vim`, `emacs`
- All your files will be compiled on Ubuntu 20.04 LTS using `gcc`,
  using the options `-Wall -Werror -Wextra -pedantic -std=gnu89`
- All your files should end with a new line
- A `README.md` file, at the root of the folder of the project is mandatory
- Your code should use the `Betty` style. It will be checked using
  [`betty-style.pl`](https://github.com/alx-tools/Betty/blob/master/betty-style.pl)
  and [`betty-doc.pl`](https://github.com/alx-tools/Betty/blob/master/betty-doc.pl)
- Your shell should not have any memory leaks
- No more than 5 functions per file
- All your header files should be include guarded
- Use system calls only when you need to [`why?`](https://www.quora.com/Why-are-system-calls-expensive-in-operating-systems)
- Write a `README` with the description of your project
- You should have an `AUTHORS` file at the root of your repository,
  listing all individuals having contributed content to the repository.

### List of allowed functions and system calls
- `access` (man 2 access)
- `chdir` (man 2 chdir)
- `close` (man 2 close)
- `closedir` (man 3 closedir)
- `execve` (man 2 execve)
- `exit` (man 3 exit)
- `_exit` (man 2 _exit)
- `fflush` (man 3 fflush)
- `fork` (man 2 fork)
- `free` (man 3 free)
- `getcwd` (man 3 getcwd)
- `getpid` (man 2 getpid)
- `isatty` (man 3 isatty)
- `kill` (man 2 kill)
- `malloc` (man 3 malloc)
- `open` (man 2 open)
- `opendir` (man 3 opendir)
- `perror` (man 3 perror)
- `read` (man 2 read)
- `readdir` (man 3 readdir)
- `signal` (man 2 signal)
- `stat` (__xstat) (man 2 stat)
- `lstat` (__lxstat) (man 2 lstat)
- `fstat` (__fxstat) (man 2 fstat)
- `wait` (man 2 wait)
- `waitpid` (man 2 waitpid)
- `wait3` (man 2 wait3)
- `wait4` (man 2 wait4)
- `write` (man 2 write)
