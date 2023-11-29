/*
 * From one parent create 5 child processes. Each child should run for 5 seconds and print count along with its pid. 
 * Parent should wait for all child processes to complete and clean all of them. 
 * Hint: use loop to fork() multiple child processes.
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

// one parent and Five child processes.

int main() 
{
	int i, pid[5], s1[5];

	for(i=0; i<5; i++)
	{
		pid[i] = fork();
    		if(pid[i] == 0) 
    		{	 					
        		for(int j=1; j<=5; j++) 
        		{
         		   printf("child %d :pid= %d,ppid=%d\n",i,getpid(),getppid());
            		   sleep(1);
        		}
           	_exit(0);
    		}
	}
	
	for(i=0 ; i<5 ; i++)
	{
	    waitpid(pid[i], (s1+i), 0);
	}
	
	for(i=1; i<=5; i++) 
	{
            printf("Parent : %d: pid =%d,ppid=%d\n",i,getpid(),getppid());
            sleep(1);
        }
	return 0;
}


