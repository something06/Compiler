# Compiler

A compiler for a subset of C, written in C. I'm building it from scratch to teach myself C and to understand what happens between source code and a running program.

The compiler, `mycc`, emits x86-64 assembly. `gcc` is then used only to assemble and link that output into an executable.

## Status

The project is at its first stage. `mycc` currently takes a single integer on the command line and emits a program that exits with that value:

```
$ ./mycc 42
.intel_syntax noprefix
.globl main
main:
  mov eax, 42
  ret
```

It does not read C source files yet. That comes in the stages below.

## Building and running

You need `gcc` on your PATH. I develop on Windows with the MSYS2 UCRT64 toolchain, using a bash shell.

```
gcc -Wall -Wextra -o mycc main.c
```

To compile a value, assemble the result and check its exit code:

```
./mycc 42 > tmp.s
gcc -o tmp tmp.s
./tmp
echo $?
```

The last command prints `42`.

## Roadmap

- [x] Emit a program that returns an integer
- [ ] Reject input that is not a valid number
- [ ] Addition and subtraction
- [ ] A tokenizer, so whitespace is allowed
- [ ] Multiplication, division and parentheses, with correct precedence
- [ ] Comparison operators
- [ ] Local variables and assignment
- [ ] `if`, `while` and `for`
- [ ] Functions and function calls
- [ ] Pointers and arrays

## What I'm learning

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)

- C itself: pointers, strings, memory and the standard library
- How a compiler is structured: tokenizing, parsing and code generation
- x86-64 assembly and how function return values reach the operating system
