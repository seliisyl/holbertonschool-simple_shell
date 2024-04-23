# holbertonschool-simple_shell
this is a team project on SIMPLE-SHELL done by Selimata Sylla, Pauline Onier and Aline Laurier

# Content
- What is the shell ?
- About this project
- Essentiel Fonctionalitie of the simple shell
- File description
- List of allowed functions and system calls fot this project
- Usage
- Bugs
- Team

# What is the shell
A shell is a computer program that provides a user interface for the services of an operating system. It acts as a command interpreter, allowing the user to enter text commands to run programs, manipulate files, navigate directories, and interact with the operating system.

# About this project
simple shell is a simple version of the linux shell made by the holberton school 

# Essentiel fonctionalities of the simple shell
- Entry point of utilisateur
- Runs all "executable program" commands (ls, ls -l, /bin/ls, /bin/ls -l)
- Executes all buil_in commands (exit, env, getenv)
- manage commands with arguments
- manage the global PATH variable.
- manages the EOF condition (end of file)
- handles the Ctrl + c signal -> it does not leave the shell

# Files description
- Shell.h -> header file
- simple_shell.c -> main function
       main:
- execve.c ->
- token.c ->
- strdup.c ->
- free.c ->
- read.c ->
- path.c ->
- build.c ->
- getenv.c ->

# List of allowed functions and system calls for this project
all functions from string.h
access (man 2 access)
chdir (man 2 chdir)
close (man 2 close)
closedir (man 3 closedir)
execve (man 2 execve)
exit (man 3 exit)
_exit (man 2 _exit)
fflush (man 3 fflush)
fork (man 2 fork)
free (man 3 free)
getcwd (man 3 getcwd)
getline (man 3 getline)
getpid (man 2 getpid)
isatty (man 3 isatty)
kill (man 2 kill)
malloc (man 3 malloc)
open (man 2 open)
opendir (man 3 opendir)
perror (man 3 perror)
printf (man 3 printf)
fprintf (man 3 fprintf)
vfprintf (man 3 vfprintf)
sprintf (man 3 sprintf)
putchar (man 3 putchar)
read (man 2 read)
readdir (man 3 readdir)
signal (man 2 signal)
stat (__xstat) (man 2 stat)
lstat (__lxstat) (man 2 lstat)
fstat (__fxstat) (man 2 fstat)
strtok (man 3 strtok)
wait (man 2 wait)
waitpid (man 2 waitpid)
wait3 (man 2 wait3)
wait4 (man 2 wait4)
write (man 2 write)
