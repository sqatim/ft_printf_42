# ft_printf: recoding of the original function printf.

The versatility of the printf function in C represents a great exercise in programming for us. This project is of moderate difficulty. It will enable us to discover variadic functions in C. The key to a successful ft_printf is a well-structured and good extensible code.


This Project consist of a recoding of the famous printf function in C language.
----


## Introduction
At 42_Network schools - Including 1337-, students are not allowed to use library functions.
so we re-write our own functions, and printf is one of must have functions, so we write our own.

## Subject
+ [ft_printf_subject](/ft_printf_subject.pdf)

## How To Use
1. clone this repo.
2. run the `make` command.
3. call by ft_printf, and use just as you gonna use the normal printf.
ps : this project is only tested in MAC os, I don't know it's behavios in other os.
4. To compile with the repository main:
    ```
    gcc -Wall -Werror -Wextra main.c libftprintf.a 
    ```

## What ft_printf supports:

| ft_printf         |			     |
| ----------------- | -------------- |
| The Conversions	| c s p d i u x X|
| Manage	        |           %    |
| The Flags         | - 0 . *        |
