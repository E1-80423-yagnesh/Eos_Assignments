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
    int serv_fd, cli_fd, ret;

    struct sockaddr_un serv_addr, cli_addr;
    socklen_t socklen;
    
    num_t num;
    res_t result;
	
    printf("	SERVER ~\n");
	
    unlink(SERVER_PATH);
	
    // create A server socket
    serv_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if(serv_fd == -1)
    {
        perror("failed to create listing socket\n");
        exit(1);
    }
    

    // Assign address to server socket
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sun_family = AF_UNIX;
    strncpy(serv_addr.sun_path, SERVER_PATH, sizeof(serv_addr.sun_path)-1 );
    serv_addr.sun_path[sizeof(serv_addr.sun_path)-1] = '\0';
   
   // BIND THE SERVER SOCKET
    ret = bind(serv_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    if(ret < 0)
    {
    	perror("Failed to bind address to server socket\n");
    	exit(2);
    }
    
    //listen to the server socket
    listen(serv_fd, 5);
    

   // Accept client connection
   
   while(1)
   {
      memset(&cli_addr, 0, sizeof(cli_addr));

      socklen = sizeof(cli_addr);
 
      cli_fd = accept(serv_fd, (struct sockaddr*)&cli_addr, &socklen);
      if(cli_fd < 0)
      {
         perror("failed to accept client connection");
         _exit(3);
       }
    
  
    	// read from client
    	read(cli_fd, &num, sizeof(num_t));
    	printf("Numbers %d and %d received from client\n", num.n1, num.n2);
    	
    	// calculating result
    	result.add = num.n1 + num.n2;

	// send back to the client
    	write(cli_fd, &result, sizeof(res_t));
    	printf("Result send to the client...\n\n");
    	
        // close client connecting socket
	close(cli_fd);
    }
        //shutdown listening socket	
	shutdown(serv_fd, SHUT_RDWR);

    return 0;
}


