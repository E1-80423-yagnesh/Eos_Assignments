/*
From a parent process (A) create a child process (B). 
The child (B) in turn creates new child process (C) and it (C) in turn create new child (D). 
All these
processes should run concurrently for 5 seconds and cleaned up properly upon termination.
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

			// parent A -> child B -> child C  -> child D
int main() 
{

    int i, pidb, pidc, pidd, sb, sc, sd;
    
	    
     pidb = fork();     
    if(pidb == 0)
    { 
        
          pidc = fork(); 
      	  if(pidc == 0) 
          {

              	pidd = fork();
              	if(pidd == 0) 
             	 {
             		 for(i=1; i<=5; i++) 
            		 {
              	  	  printf("child d: pid=%d,ppid=%d\n", i,getpid(),getppid());
                  	  sleep(1);
                	 } 
                	_exit(0);
             	 }
            for(int j=1; j<=5; j++) 
            {
                printf("child c: pid=%d,ppid=%d\n", j,getpid(),getppid());
                sleep(1);
            }
            waitpid(pidd, &sd, 0);    
            _exit(0);
          }
        
      for(i=1; i<=5; i++) 
      {
          printf("child B: pid=%d,ppid=%d\n",i,getpid(),getppid());
          sleep(1);
      }
      waitpid(pidc, &sc, 0);  
      _exit(0);
    }

    
    for(i=1; i<=5; i++) 
    {
        printf("A Parent : %d\n", i);
        sleep(1);
    }
    waitpid(pidb, &sb, 0); 

    return 0;
}

	
