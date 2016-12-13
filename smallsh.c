/* 
 * Author: Stephen Grifin
 * Program: Small Shell

 * Description: 
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
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>


int main(int argc, char **argv)
{
	pid_t pid, bpid, bgpid;
	int status, bgstatus;
	int exitStatus = 0;

	//Ignore SIGINT in shell, unless otherwise handled
	struct sigaction act;
	act.sa_handler = SIG_IGN;
	sigaction(SIGINT, &act, NULL);


	//Program will continue to "exit" command is entered	
	while(1)
	{
		//Reset command line arguments to empty for new prompt	
		char cmd[2048] = {0};
		char* argArray[512] = {0};

		//Checks if background processes are completed
		//If so, then displays message to user 
		pid_t bgpid = waitpid(bpid, &bgstatus, WNOHANG);
		if(bgpid == bpid)
		{
			printf("backgrond pid %d is done: exit status %d\n", bpid, bgstatus);
			fflush(stdout);
		}


		//Print colon which prompts user for command
		printf(": ");
		fflush(stdout);

		//Assign keyboard input to cmd variable and eliminate any newline chars	
		fgets(cmd, sizeof(cmd), stdin);
		cmd[strcspn(cmd, "\n")] = '\0';
		
		//Tokenize command line input into array of strings wherever there are spaces
		int i = 0;
		int size = 0;
		char *p;
		p  = strtok(cmd, " ");
		
		while(p != NULL)
		{
			argArray[i++] = p;
			p = strtok(NULL, " ");
			size++;
		}

	
		//If command is blank or first character is # then treat as comment	
		if (cmd[0] == '#' || argArray[0] == NULL)
		{
			fflush(stdout);
			//Will return to beginning of while loop
		}

		//Otherwise it is a command
		else
		{
			///Built in status command
			if(strcmp(argArray[0], "status") == 0)
			{
				//Print exit status
				printf("exit status %d\n", exitStatus);
				fflush(stdout);
				//Reset exitStatus to 0
				exitStatus = 0;
			}

			//Built in cd (change directory) command
			else if(strcmp(argArray[0], "cd") == 0)
			{
				//If no argument, change directory to HOME
				if(argArray[1] == NULL)
				{
					int ret = chdir(getenv("HOME"));
				}
				//If there is argument - change directory to argument
				else
				{
					char* home = getenv("HOME");
					//Concatenates arugment on to HOME
					sprintf(home, "%s/%s",home, argArray[1]);
					chdir(home);
				}
			}
	
			//Built in exit command
			else if(strcmp(argArray[0], "exit") == 0)
			{
				//Kill all processes and terminate program
				kill(0, SIGTERM);
			}
			
	
			//NOT built-in function
			else
			{
				/***BACKGROUND PROCESS***/
				
				//If final command argument is & then background process
				if(strcmp(argArray[size-1], "&") == 0)
				{
					//Change & character to NULL 
					argArray[size-1] = NULL;

					//Fork
					bpid = fork();

					if(bpid == 0)  //child
					{
						//Redirect I/O of background processes to /dev/null
						//So that process is "displayed" in background
						int devNullIn = open("/dev/null", O_RDONLY);
						dup2(devNullIn, 0);

						int devNullOut = open("/dev/null", O_WRONLY);
						dup2(devNullOut, 1);
						
						//Execute command
						execvp (argArray[0],argArray);

						//Will print if error with exec
						perror("exec perror");
						exitStatus = 1;
					}
	
					else if (bpid > 0)  //parent
					{
						//Display background pid when process starts
						//Do NOT wait on process
						printf("background pid is %d\n", bpid);
						fflush(stdout);
					}
		
					else if(bpid == -1)  //fork failed
					{
						perror("fork error");
						exitStatus = 1;
					}

				}

				
				else
				{	
					/***FOREGROUND PROCESS***/

					pid = fork();

					if(pid == 0)  //child
					{
						//Allow SIGINT to interrupt foreground child processes
						act.sa_handler = SIG_DFL;
						act.sa_flags = 0;
						sigaction(SIGINT, &act, NULL);
				
						//Booleans for input/output characters
						int in = 0;
						int out = 0;	
		
						//Check for input character	
						int k = 0;
						while(argArray[k] != NULL)
						{
							if(strcmp(argArray[k], "<") == 0)
							{
								in = 1;
							}
							k++;
						}
				
						//Check for output character
						int m = 0;
						while(argArray[m] != NULL)
						{
							if(strcmp(argArray[m], ">") == 0)
							{
								out = 1;
							}
							m++;
						}	
						
						//Input redirection	
						if(in == 1)
						{
							//Assign input argument to filename
							char *infile;
							infile = argArray[2];

							//If file does not exist send to exec which will produce error
							if (access(infile, F_OK) == -1)
							{
								argArray[1] = argArray[2];	
								argArray[2] = NULL;
							}
 
							//If file exists, redirect stdin to file
							else
							{
								//Create and open file
					                	int fdin = open(infile, O_RDONLY);
								//Direct stdin to file
								int fdin2 = dup2(fdin, 0);
	
								close(fdin);
								
								//Sends only necessary command to exec()
								argArray[1] = NULL;
							}
						}


						//Output redirection
						if(out == 1)
						{
							//Assign output argument to filename
							char* outfile;
							outfile = argArray[2];

							//Create and open file
							int fdout = open(outfile, O_WRONLY|O_CREAT|O_TRUNC, 0644);
							//Direct stdout to file
							int fdout2 = dup2(fdout, 1);
					
							close(fdout);
							
							//Sends only necessary command to exec()
							argArray[1] = NULL;
			               		}
						
						//Execute command
						execvp (argArray[0],argArray);

						//Will print if error with exec
						perror("exec error");
						exitStatus = 1;
					}
	
					else if (pid > 0)  //parent
					{
						
						//loop until foreground process is finished
						do{
							waitpid(pid, &status, 0);
						}while(!WIFEXITED(status) && !WIFSIGNALED(status));

					
						//If error returned set exit status to 1
						if(status > 0)
						{
							exitStatus = 1;
							if(status == 2) //SIGINT
								printf("\n");
						}
						else
							exitStatus = 0;
					}
		
					else if(pid == -1)  //fork failed
					{
						perror("fork error");
						exitStatus = 1;
					}

			
				}
			}	
		}
	
	}

	return 0;
}
