#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <sys/types.h>

int main(void){
	pid_t childpid;

	childpid = fork();
	
	//check if fork was successful
	if(childpid >= 0){
		//child process
		if(childpid == 0){
			while(1){
				sleep(1);
			}
		}
		//parent process
		else{
			//kill child process
			kill(childpid, SIGKILL);
			//wait so that processes could be checked
			sleep(10);
		}
	}
	//if fork failed
	else{
		printf("Fork failed\n");
		return 1;
	}
	return 0;
}
