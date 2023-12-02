//2. The child process send two numbers to the parent process via pipe. The parent process calculate the sum and return via another pipe. The child process
//print the result and exit. The parent process wait for completion of the child and then exit.


#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>

int main()
{
	int ret,s,err,num1,num2,num3;
	int fd[2],fd1[2],sum,num4,num5;

	ret = pipe(fd);
	
		if(ret < 0)
		{
			perror("pipe1() failed!\n");
			_exit(1);
		}
		ret = pipe(fd1);
		
		if(ret < 0)
		{
			perror("pipe2() failed!\n");
			_exit(1);
		}

		ret = fork();
		
		if(ret == 0)
		{
		close(fd[0]);
		close(fd1[1]);
		printf("Enter the first number:\n");
		scanf("%d",&num1);
		printf("Enter the second number:\n");
		scanf("%d",&num2);
		write(fd[1],&num1,sizeof(num1));
		write(fd[1],&num2,sizeof(num2));

		read(fd1[0],&sum,sizeof(sum));
		printf("The child result is=%d\n",sum);
		close(fd[1]);
		close(fd1[0]);
		}
	
		else
		{
		//parent child
		close(fd[1]);
		close(fd1[0]);
		read(fd[0],&num1,sizeof(num1));
		read(fd[0],&num2,sizeof(num2));

		sum = num1 + num2;
		write(fd1[1],&sum,sizeof(sum));
		//printf("data read parent: %d",sum);
		close(fd[0]);
		close(fd1[1]);
		waitpid(-1,&s,0);
		}
		return 0;
		}
