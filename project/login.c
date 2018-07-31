#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

struct login{
	
	char username[45];
	char password[45];
}details;

  void login()
{
	char username[45], password[45];
	FILE *log;
	log = fopen("logs.txt", "r");
	printf("\t User Name:");
	scanf("%s", username);
	printf("\t password:");
	scanf("%s", password);

	while(fread(&details, sizeof(details),1,log))
	{
		if (strcmp(username, details.username) ==0 && strcmp(password, details.password) == 0)
		{
			printf("succesful login\n");
		}
		else {
			printf("Please Enter correct UserID and Password\n");
			break;
		}
	}
	fclose(log);
}


 void regist()
{
	char child[] = "client.c";
	FILE *log;
	log = fopen("logs.txt", "w");
	printf("Enter username :");
	scanf("%s", details.username);
	printf("Enter password :");
	scanf("%s", details.password);

	fwrite(&details, sizeof(details),1,log);

	fclose(log);

	
	printf("Now login with user Name and password\n");
	login();
	system("./a.out");
	
}


 int main(int argc, char const *argv[])
 {
 	int choice;

 	printf(" \t \t Welcome To The Trojan Server \n To regesiter an account Press '1' \nIf you already have an account Press '2' to login \n ");
 	scanf("%d", &choice);
 	if (choice == 1)
 	{
 		regist();
 	}
 	else if (choice == 2)
 	{
 		login();
 		system("./a.out");
 	}
 	return 0;
 }







