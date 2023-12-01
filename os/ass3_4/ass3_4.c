#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pid1, pid2, pid3, pid4, pid5, pid6, s1, s2, s3, s4, s5, s6;

    printf("parent started!\n");
    
    pid1 = fork();

    
    if (pid1 == -1) {
        perror("fork() failed");
        exit(1);
    }
    
    if (pid1 == 0) {
        // Child process >>|- child1 gcc -c circle.c
        printf("Object file of circle.c GENERATED........\n");
        execlp("gcc", "gcc", "-c", "circle.c", NULL);
        perror("execlp() failed");
        _exit(1);  // Use _exit() to avoid flushing stdio buffers
    }
    
    pid2 = fork();
    if (pid2 == 0) {
        // Child process >> |- child2 gcc -c square.c
        printf("Object file of square.c GENERATED........\n");
        execlp("gcc", "gcc", "-c", "square.c", NULL);
        perror("execlp() failed");
        _exit(1);  
    }
    pid3 = fork();
    if (pid3 == 0) {
        // Child process >> |- child2 gcc -c rectangel.c
        printf("Object file of rectangel.c GENERATED........\n");
        execlp("gcc", "gcc", "-c", "rectangle.c", NULL);
        perror("execlp() failed");
        _exit(1);  
    }
    pid4 = fork();
    if (pid4 == 0) {
        // Child process >> |- child4 gcc -c main.c
        printf("Object file of main.c GENERATED........\n");
        execlp("gcc", "gcc", "-c", "main.c", NULL);
        perror("execlp() failed");
        _exit(1);  
    }
    
    waitpid(pid1, &s1, 0);
    waitpid(pid2, &s2, 0);
    waitpid(pid3, &s3, 0);
    waitpid(pid4, &s4, 0);
    // wait for all child 
    int e1, e2, e3, e4, e5, e6;
    e1 = WEXITSTATUS(s1); 
    e2 = WEXITSTATUS(s2); 
    e3 = WEXITSTATUS(s3); 
    e4 = WEXITSTATUS(s4);



        //  check exit status. If all exit status 0 (success), then link
        if (e1 == 0 && e2 == 0 && e3 == 0 && e4 == 0)  
        {

            pid5 = fork();
    		if (pid5 == 0) 
    		{
       		 execlp("gcc", "gcc", "-o", "program.out", "circle.o","square.o", "rectangle.o", "main.o", NULL);

        	 perror("execlp() failed");
       		 _exit(1);  
                }	                     
        } 
              // |- child5 (gcc -o program.out circle.o square.o rectangle.o main.o)
        else {
            printf("Compilation failed!\n");
        }
            
        // wait for child 
    waitpid(pid5, &s5, 0);
    e5 = WEXITSTATUS(s5);
    
    // check exit status. If all exit status 0 (success), then run it.
    	if (e1 == 0 && e2 == 0 && e3 == 0 && e4 == 0 && e5 == 0)  
        {
          pid6 = fork();
          if (pid6 == 0) 
          {
             printf("Running.......");
            execle("/home/parag/work/eos/Assignment/e_os/ass3.4/program.out", "./program.out", NULL, (char *)NULL);
            perror("execlp() failed");
            _exit(1); 
          }
        }
        else{
        	printf("Final Failed...\n");
        }
    waitpid(pid6, &s6, 0);
    return 0;
}
/*
 gcc -c main.c
 gcc -c square.c
 gcc -c rectangle.c
 gcc -c circle.c
 
 gcc -o program.out main.o square.o rectangle.o circle.o
 
 ./program.out
*/

