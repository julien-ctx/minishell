# Minishell: A Basic Shell Implementation | 42

## Overview

Minishell is a basic but quite complete shell that allows you to **browse files and directories** and execute many commands like in `bash 3.2`.

## Implementation

This shell uses the **readline library** which is automatically downloaded when you run `make` command. It allows you to get a prompt and to enter commands in the terminal.

There are two types of commands : **executables** executed with the `execve()` function like `ls`, and **builtins** that I have recreated myself. Here is the list of builtin commands:

- `export`: create environment variables, list them and modify them.
- `env`: list environment variables that meet several criteria.
- `unset`: delete environment variables.
- `pwd`: display the current directory on the standard output.
- `cd`: change the current directory and display the necessary errors if the path is not correct.
- `echo`: display messages on the standard output. The -n parameter is supported.
- `exit`: exit the shell with a return value.

This minishell works like a real shell and manages many features. That's why a **lexer and a parser** had to be implemented. It was one of the biggest part of the work. Here are some cool feature that are supported:

- simple quotes and double quotes.
- environment variables.
- redirects: `<<`, `>>`, `<`, `>`.
