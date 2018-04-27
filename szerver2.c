/***************************************/
/*              TCP server             */
/***************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h> 
#include <sys/types.h>

#define BUFSIZE 1024                      // buffer size
#define PORT_NO 2001                      // port number
#define error(a,b) fprintf(stderr, a, b)  // error 'function'

int sendall(int s, char *buf, int *len)
{

    int total = 0; // mennyi bájtot küldtünk már el
    int bytesleft = *len; // mennyi maradt még elküldetlenül
    int n;

    while(total < *len)
        n = send(s, buf+total, bytesleft, 0);
        if (n == -1) { break; }
        total += n;
        bytesleft -= n; }

    *len = total; // vissza adja azt a számot, amit itt aktuálisan küldtünk el

    return n==-1?-1:0; // hiba esetén -1, siker esetén pedig 0 a visszatérő érték

}



int main(int argc, char *argv[] ){ 	// arg count, arg vector 

   /* Declarations */
   int fd;	        	           		// socket endpt
   int fdc;                        	// socket endpt
   int flags;                      	// rcv flags
   struct sockaddr_in server;      	// socket name (addr) of server
   struct sockaddr_in client;	     	// socket name of client
   int server_size;                	// length of the socket addr. server
   int client_size;                	// length of the socket addr. client
   int bytes;		           					// length of buffer 
   int rcvsize;                    	// received bytes
   int trnmsize;                   	// transmitted bytes
   int err;                        	// error code
   char on;                        	// 
   char buffer[BUFSIZE+1];	     		// datagram dat buffer area   
   char *buf;
   buf=&buffer
   int fdc2=0;
   int bytes2=0;
   int kliensek[2];
   /* Initialization */
   on                     = 1;
   flags                  = 0;
   bytes                  = BUFSIZE;
   server_size            = sizeof server;
   client_size            = sizeof client;
   server.sin_family      = AF_INET;
   server.sin_addr.s_addr = INADDR_ANY;
   server.sin_port        = htons(PORT_NO);

   /* Creating socket */
   fd = socket(AF_INET, SOCK_STREAM, 0 );
   if (fd < 0) {
      error("%s: Socket creation error\n",argv[0]);
      exit(1);
      }

   /* Setting socket options */
   setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, (char *)&on, sizeof on);
   setsockopt(fd, SOL_SOCKET, SO_KEEPALIVE, (char *)&on, sizeof on);

   /* Binding socket */
   err = bind(fd, (struct sockaddr *) &server, server_size);
   if (err < 0) {
      error("%s: Cannot bind to the socket\n",argv[0]);
      exit(2);
      }

   /* Listening */
   err = listen(fd, 10);
   if (err < 0) {
      error("%s: Cannot listen to the socket\n",argv[0]);
      exit(3);
      }

   /* Accepting connection request */

   kliensek[0] = accept(fd, (struct sockaddr *) &client, &client_size);
   kliensek[1] =accept(fd, (struct sockaddr *) &client, &client_size);
   /*if (fdc < 0) {
      error("%s: Cannot accept on socket\n",argv[0]);
      exit(4);
      }*/

   /* Receiving data from the client */
	int b=1;
	int len=0;
while(b==1)
{
	for(int j=0;j<2;j++)
	  {		
	if((rcvsize=recv( kliensek[j],buffer, bytes, flags ))==-1)
		{printf("Nincs csatlakozás \n");}
	/*else
   	  {
		printf("%i bytes have been received from client.\n Message: %s \n", rcvsize-1, buffer);
		trnmsize = send(kliensek[(j+1)%2], buffer, bytes, flags);
	  }*/
	else 
		{
		   len = strlen(buffer);
		   if (sendall(s, buf, &len) == -1) {
    			perror("sendall");
    			printf("We only sent %d bytes because of the error!\n", len);

}
		}
	}
}	
/*if(recv( fdc, buffer, bytes, flags )>0)
   {
   printf("%i bytes have been received from client.\n Message: %s \n", 
           bytes-1, buffer);
   }
else if(recv( fdc2, buffer, bytes2, flags )>0)
   {
   printf("%i bytes have been received from client 2.\n Message: %s \n", 
           bytes2-1, buffer);
   }
*/
   /* Sending acknowledgement to the client */
   /*sprintf(buffer,"Transmit is OK.");
   bytes = strlen(buffer) + 1;
   trnmsize = send(fdc, buffer, bytes, flags);
   if (trnmsize < 0) {
      error("%s: Cannot send data to the client.\n",argv[0]);
      exit(6);
      }
   trnmsize = send(fdc2, buffer, bytes, flags);
   /* User interface */
   /*printf ("Acknowledgement has been sent to the client.\n");
rcvsize=0;*/
}
   /* Closing sockets and quit */
   close(fdc);
   close(fdc2);
   close(fd);
   exit(0);
} 

