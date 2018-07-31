#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>
#include<time.h>



	// function definition
void str_echo(int s)
{
    char buf[55];
    int size;
    char letter[9];
    char word[10];
    int i, j, m, n, counter;
    char ch;
    char letter1,letter2;
    char word1[10],word2[10];
    char str[55],str2[55], str1[55];
    char dbl[9] = {"double"};
    char del[9] = {"delete"};
    char rev[9] = {"reverse"};
    char replc[9] = {"replace"};
    char ecrpt[9] = {"encrypt"};
    char decrpt[9] = {"decrypt"};
    char function[9];
    FILE *fptr;
    time_t t;   // not a primitive datatype
    time(&t);


//receiving data from client
 d :recv(s,buf,55,0);
 puts("Message from Client...");
 printf("\nThis job has been sent at (date and time): %s", ctime(&t));
 strcpy(function, strtok(buf , " "));

        // delete code 
 if(strcmp(function, del) == 0){ 
  strcpy(&ch, strtok(NULL, " "));
  strcpy(word, strtok(NULL, " " ));
  strcpy(str2, strtok(NULL, " "));


  printf(" function :%s\n", function );
  printf(" character :%c\n", ch);
  printf(" ignore :%s\n", word );
  printf("string :%s\n", str2 );

  n = strlen(str2);
   for (i = 0, j = 0; i < n; i++)
   {
    if (str2[i] != ch)
    {
      str2[j] = str2[i];
      j++;
    }
   }

   str2[j] = '\0';
   strcpy(buf,str2);
   fputs(buf,stdout);
   
   send(s,buf,55,0);

   fptr = fopen("ready_list.txt", "a");
    if (fptr == NULL){
 	  	printf("file doesn't exit\n" );
 	}else {
 		printf("\nsaving client's result to ready_list\n");
 		fprintf(fptr, "%s,%s\n", function, buf);
 		printf("\nsaved Successfully to ready_list\n");
 		fclose(fptr);
 	}

   goto d;
 }


        //replace code
 else if(strcmp(function, replc) == 0){ 
    strcpy(&letter1, strtok(NULL, " "));
    strcpy(word1, strtok(NULL, " " ));
    strcpy(&letter2, strtok(NULL, " "));
    strcpy(word2, strtok(NULL, " " ));
    strcpy(str2, strtok(NULL, " "));

    printf(" function :%s\n", function );
    printf(" character1 :%c\n", letter1);
    printf(" ignore :%s\n", word1 );
    printf(" character2 :%c\n", letter2);
    printf(" ignore2 :%s\n", word2 );
    printf(" string :%s\n", str2 );

      while(str2[counter] != '\0')
      {
        if(str2[counter] == letter1)
        {
            str2[counter] = letter2;
        }
        counter++;
      }
      strcpy(buf,str2);
      fputs(buf,stdout);
      
      send(s, buf, 55,0);

      fptr = fopen("ready_list.txt", "a");
 	  if (fptr == NULL){
 		printf("file doesn't exit");
 	  }else {
 		printf("\nsaving client's result  to ready_list\n");
 		fprintf(fptr, "%s,%s\n", function, buf);
 		printf("saved Successfully to ready_list");
 		fclose(fptr);
 	  }
 	  goto d;
}


   strcpy(str1, strtok(NULL, " "));

   
      //double code 
 if(strcmp(function, dbl)== 0){    
      strcat(str1,str1);
      strcpy(buf,str1);
      fputs(buf,stdout);
      
      send(s, buf, 55, 0);

      fptr = fopen("ready_list.txt", "a");
 	  if (fptr == NULL){
 		printf("file doesn't exit\n" );
 	  }else {
 		printf("\nsaving client's result to ready_list\n");
 		fprintf(fptr, "%s,%s\n", function, buf);
 		printf("saved Successfully to ready_list");
 		fclose(fptr);
 	  }
goto d;
    }

    // reverse code     
 else if(strcmp(function, rev) == 0){      
    void reverse(char str1[], int index, int size)
    {
      char temp;
      temp = str1[index];
      str1[index] = str1[size - index];
      str1[size - index] = temp;
      if(index == size / 2){
        return;
      }
      reverse(str1, index + 1, size);
    } 
      int size;
      
      size = strlen(str1);
      reverse(str1, 0, size - 1);
      strcpy(buf,str1);
      fputs(buf,stdout);

      send(s, buf, 55, 0);

      fptr = fopen("ready_list.txt", "a");
      if (fptr == NULL){
 		printf("file doesn't exit\n" );
 	  }else {
 		printf("\nsaving client's result to ready_list\n");
 		fprintf(fptr, "%s,%s\n", function, buf);
 		printf("saved Successfully to ready_list");
 		fclose(fptr);
 	  }
goto d;
}

}
	// end of function definition

	// main program
int main()
{
    int ls,cs,len;
    struct sockaddr_in serv,cli;
    pid_t pid;
    clock_t t;

    puts("\t\t *** Trojan Server Started ***");

    //creating socket
    ls=socket(AF_INET,SOCK_STREAM,0);
    puts("Socket Created Successfully...");

    //socket address structure
    serv.sin_family=AF_INET;
    serv.sin_addr.s_addr=INADDR_ANY;
    serv.sin_port=htons(5000);
    bind(ls,(struct sockaddr*)&serv,sizeof(serv));
    puts("Binding Done...");
    listen(ls,10);
    puts("Listening for Client...");
    for(; ;)
    {
        len=sizeof(cli);
        //accepting client connection
        cs=accept(ls,(struct sockaddr*)&cli,&len);
        puts("\nConnected to Client...");
        //creating child process
        if((pid=fork()) == 0)
        {
            puts("Child process created...");
            close(ls);
            t = clock();
            str_echo(cs);
            t = clock() - t;
            double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
            printf("\nprogram took %f seconds to execute \n", time_taken);
            close(cs);
            exit(0);
        }
        close(cs);
    }
return 0;
}
