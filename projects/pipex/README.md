# Pipex

A 42 School C project exploring how Unix shells connect two commands through a pipe and redirect input and output files.

## What this demonstrates

`fork`, `pipe`, `dup2`, file descriptors, command lookup and process execution.

## Build and run

Requires a C compiler, POSIX system calls and commands available through `PATH`. There is no Makefile in this repository.

**Current build status:** the direct build below fails on the checked Linux toolchain: `waitpid` lacks a visible declaration and `strnstr` is used without a declaration or bundled implementation. `strnstr` is also not supplied by glibc. These portability issues must be resolved before running the example. The commands show the intended build and interface.

```sh
git clone https://github.com/derealthink/42-school.git
cd 42-school/projects/pipex
cc main.c utils.c temp_split.c temp_strjoin.c -o pipex
printf 'hello world
' > input.txt
./pipex input.txt "cat" "wc -w" output.txt
cat output.txt
```

The command-line interface is:

```text
./pipex input_file "command_1 [arguments]" "command_2 [arguments]" output_file
```

The intended shell equivalent is `< input_file command_1 | command_2 > output_file`.

## Implementation notes

`main.c` creates the pipe, forks and sets up file redirections. Supporting files handle command execution and string processing.

The current parent waits for the first child before starting the second command. Large output can fill the pipe and block the program. The example uses a small input; the implementation does not yet provide concurrent pipeline behavior for arbitrary workloads.

---

Part of my [42 School project collection](../../README.md).
