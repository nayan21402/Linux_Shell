## Description
This is a simple shell program made in C that uses standard C libraries and Linux system calls such as `fork()`, `exec()` family system calls, and `wait()` family of system calls. It can handle the following commands:

### Commands and Flags:
- `cd`: Goes to a directory
  - `-`: Goes to the previous visited directory
  - `~`: Goes to the home directory
- `pwd`: Prints the current directory
  - `-L`: Prints the logical path
  - `-P`: Prints the physical path
- `echo`: Prints a string
  - `-n`: Prints the string without a newline
  - `-h`: Prints help
- `ls`: Prints all files and directories
  - `-r`: Prints all files and directories in reverse order
  - `-a`: Prints all files and directories, including hidden files
- `cat`: Prints the content of files
  - `-n`: Prints the content of the file followed by line numbers
  - `-E`: Prints the contents of the file followed by "$"
- `date`: Prints local date and time
  - `-r`: Prints last modified date and time of a file
  - `-u`: Prints date and time in UTC format
- `rm`: Removes files
  - `-I`: Gets confirmation before deleting a file
  - `-v`: Announces the file deletion
- `mkdir`: Makes a directory
  - `-p`: Makes parent directory if it doesn't exist
  - `-v`: Announces directory being created

## Assumptions
1. All external files are in the same directory as the shell.
2. Command length will not exceed 1024.
3. Command history is maintained for 1024 commands only.

## Command Execution and Error Handling

### 1. CD
- Errors handled:
  - No such file or directory
  - Invalid syntax

### 2. Echo
- Errors handled:
  - No error needs to be handled

### 3. PWD
- Errors handled:
  - Invalid syntax
  - Invalid option

### 4. LS
- Errors handled:
  - Invalid syntax
  - Invalid option

### 5. Cat
- Errors handled:
  - No such file
  - Invalid syntax
  - Invalid option

### 6. Mkdir
- Errors handled:
  - No such file or directory
  - Invalid syntax
  - Invalid option

### 7. Rm
- Errors handled:
  - No such file
  - Invalid syntax

### 8. Date
- Errors handled:
  - No such file or directory
  - Invalid syntax
