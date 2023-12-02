//1. Execute "wc" command from your program (using fork() + exec()). The command should read data from the ﬁle "in.txt" (instead of terminal) and output
//should be displayed on terminal.

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>


int main()
{

	int ret,s,mqid,fd,err;
	printf("program started!\n");
	ret = fork();
	
		if(ret == 0)
		{
		 fd = open("test.txt",O_CREAT | O_WRONLY| O_TRUNC, 0644);
		 close(1);
		 dup(fd);
		 close(fd);

		err = execlp("wc","wc",NULL);
		
		if(err < 0)
		{
		perror("exec() failed!\n");
		_exit(1);
		}
		
		}
		
		else
		{
		waitpid(ret, &s ,0);
		printf("program completed!\n");

		}
		return 0;
}
