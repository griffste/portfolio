Small Shell
===========

To Compile:

gcc smallsh.c -o smallsh


Description: 

A simple shell written in C, for which the goal of the project is to display basic knowledge
of fork(), exec(), and parent/child processes. 

The shell should do the following:
-Use a colon as the prompt for each command line
-Allow blank lines and comments beginning with '#' character
-Run the following built in commands:
	-"cd" - changes directory to HOME with no argument or a new path with argument
	-"status" - displays exit status of last process
	-"exit" - kills all processes and exits shell
-Run non-built in commands using fork() and exec()
-Run I/O redirection with single argument
-Run a process in the background if last argument is '&' character
-Only termintate the child process when SIGINT signal is sent, do not terminate the shell

