#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void str_echo(int s)
    {
        char buf[55],buf1[55];
      e :  puts("\nEnter the task...");
        gets(buf);

    //sending data to server
        send(s,buf,55,0); 

    //receiving data from server
        recv(s,buf1,55,0);
        puts("Message from Server...");
        fputs(buf1,stdout);
        goto e;
    }
int main()
{
    int ls, cs;
    struct sockaddr_in cli;
    puts("I am Client...");
/*creating socket*/
    ls=socket(AF_INET,SOCK_STREAM,0);
    puts("Socket Created Successfully...");
/*socket address structure*/
    cli.sin_family=AF_INET;
    cli.sin_addr.s_addr=inet_addr("127.0.0.1");
    cli.sin_port=htons(5000);
 /*connecting to server*/
    connect(ls,(struct sockaddr*)&cli,sizeof(cli));
    puts("Connected to Trojan Server...");

    str_echo(ls);

    puts("\n\t\t \\\\\\\\ thank you for using our server ////\n \t \t \t|||Trojans forever|||");
    close(ls);
    return 0;
}
