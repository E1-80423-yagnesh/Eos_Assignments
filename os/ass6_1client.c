/*
1. Create a server that accept multiple clients connected over UNIX sockets. Each client send two numbers, server do the addition and send the result back.
The client connection should be closed immediately after sending response.


*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>


#define SERVER_PATH "/tmp/server.sock"

typedef struct number{
    int n1;
    int n2;
}num_t;

typedef struct result{
    int add;
}res_t;


int main()
{
	int cli_fd, ret;
        struct sockaddr_un serv_addr;
        
	num_t num;
        res_t result;
	
	printf("	CLIENT ~\n");
	
	// create A server socket
  	cli_fd = socket(AF_UNIX, SOCK_STREAM, 0);
        if(cli_fd == -1)
        {
           printf("failed to create client socket\n");
           _exit(0);
        }
    

	// Assign address to server socket
   	 memset(&serv_addr, 0, sizeof(serv_addr));
   	 serv_addr.sun_family = AF_UNIX;
   	 strcpy(serv_addr.sun_path, SERVER_PATH);
   
   
   	 ret = connect(cli_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
   	 if(ret < 0)
   	 {
   	 	printf("Failed to  connect to server socket\n");
   	 	_exit(1);
   	 }
	
	// Take a two numbers from user
	printf("Enter the first number : ");
	scanf("%d", &num.n1);

	printf("Enter the second number : ");
	scanf("%d", &num.n2);

	// send to the server
	write(cli_fd, &num, sizeof(num_t));
	
	// receive calculated result from server
	read(cli_fd, &result, sizeof(res_t));
	
	// And print the result
	printf("The Addition is %d\n", result.add);


	close(cli_fd);

	return 0;
}
