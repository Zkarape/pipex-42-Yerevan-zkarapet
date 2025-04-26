# Pipex - 42 School Project

📚 Project Overview
Pipex is a project from 42 School designed to teach students about UNIX system calls, file descriptors, and process piping.
The objective is to recreate a simplified version of shell piping (|) by executing two commands with input/output redirection between them.

This project was completed by:

zhenkar2003

🛠️ File Structure

File	Description
Makefile	Compilation instructions to easily build the project.
main.c	Entry point of the program. Handles parsing and execution flow.
pipex.c	Core pipe and process management logic.
child_1.c	Logic to handle the first child process (first command).
child_2.c	Logic to handle the second child process (second command).
parsing.c	Parses input arguments and prepares data structures.
free.c	Handles freeing of allocated memory to avoid leaks.
pipex.h	Header file containing all necessary function prototypes and includes.
ft_split.c	Custom implementation of string splitting.
ft_strdup.c	Custom implementation of strdup.
ft_strjoin.c	Custom implementation of strjoin.
ft_strlen.c	Custom implementation of strlen.
ft_strncmp.c	Custom implementation of strncmp.
test/	(Optional) Folder for testing scripts/files.
(Note: .DS_Store and .parsing.c.swp are system/temporary files and not related to the project.)

🎯 How to Compile and Run
Clone and Navigate
Clone the repository and go into the directory.

Compile with Makefile

bash

make
Run the program
The executable should be named pipex.
Usage:

bash

./pipex infile "cmd1" "cmd2" outfile
This is equivalent to the shell behavior:

bash

< infile cmd1 | cmd2 > outfile
Example:

bash

./pipex infile "grep hello" "wc -l" outfile
Clean the project
To remove object files and the executable:

bash

make clean
make fclean
🔥 Key Concepts
fork(): Create new processes.

pipe(): Create a unidirectional communication channel.

dup2(): Redirect file descriptors (stdin, stdout).

execve(): Execute a program.

File Descriptors: Manage input/output redirection.

Memory Management: Avoid memory leaks by properly freeing.

📄 Notes
No external functions like system() are used.

Only allowed functions from 42's norm are used.

Custom string handling functions are written from scratch (no <string.h>).

This project focuses heavily on process management and resource control.

