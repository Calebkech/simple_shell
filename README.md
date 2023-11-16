# Simple Shell

This is a simple shell program implemented in C. It provides basic functionality for executing commands, both directly and from the PATH environment variable.

## Table of Contents

- [Introduction](#introduction)
- [Files](#files)
- [Usage](#usage)
- [Example](#example)
- [Contributing](#contributing)
- [License](#license)

## Introduction

The Simple Shell program is a basic implementation of a shell in C. It allows users to execute commands and provides support for executing commands directly or from the PATH environment variable.

## Files

The Simple Shell program consists of the following files:

- `shell.h`: Header file containing function declarations and necessary includes.
- `execute_command.c`: Contains the `execute_command` function, which executes a given command.
- `execute_directly.c`: Contains the `execute_directly` function, which executes a command directly.
- `execute_from_path.c`: Contains the `execute_from_path` function, which executes a command from the PATH.
- `main.c`: Contains the main function that runs the shell program.
- `shell.c`: Contains helper functions for parsing and executing commands.
- `print.c`: Contains the `print` function for displaying output.
- `check_exit.c`: Contains the `check_exit` function for checking the `exit` command.

## Usage

To compile the shell program, run the following command: `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

This will generate an executable file named `hsh`.

To run the shell, execute the following command: `./hsh`.

The shell will display a prompt where you can enter commands. It supports executing commands directly or from the PATH environment variable.

## Example

Here's an example of using the shell program:

```
$ ./shell
$> ls
file1.txt file2.txt directory
$> pwd
/home/user
```

## Contributing

## License
