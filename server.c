// socket server example, handles multiple clients using threads

#include <stdio.h>
#include <string.h> //strlen
#include <stdlib.h> //strlen
#include <sys/socket.h>
#include <arpa/inet.h> //inet_addr
#include <unistd.h>    //write
#include <pthread.h>   //for threading , link with lpthread
#include <time.h>

// the thread function
void *connection_handler(void *);

int main(int argc, char *argv[])
{
	int socket_desc, client_sock, c, *new_sock;
	struct sockaddr_in server, client;

	// Create socket
	socket_desc = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_desc == -1)
	{
		printf("Could not create socket");
	}
	puts("Socket created");

	// Prepare the sockaddr_in structure
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(atoi(argv[1]));

	// Bind
	if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0)
	{
		// print the error message
		perror("bind failed. Error");
		return 1;
	}
	printf("Bind done\n");

	// Listen
	listen(socket_desc, 3);
	srand(time(NULL));

	// Accept and incoming connection
	puts("Waiting for incoming connections...");
	c = sizeof(struct sockaddr_in);

	c = sizeof(struct sockaddr_in);
	client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t *)&c);
	if(client_sock < 0)
	{
		perror("accept");
        exit(EXIT_FAILURE);
	}
	puts("Connection accepted");

	pthread_t read_t;
	int rc;
	new_sock = malloc(1);
	*new_sock = client_sock;

	if (pthread_create(&read_t, NULL, connection_handler, (void *)new_sock) < 0)
	{
		perror("could not create thread");
		return 1;
	}
	else
	{
		printf("Thread created\n");
	}

	rc = pthread_join(read_t, NULL);
	printf("%d\n", rc);

	if (client_sock < 0)
	{
		perror("accept failed");
		return 1;
	}

	close(client_sock);

	return 0;
}

/*
	This will handle connection for each client
	*/
void *connection_handler(void *socket_desc)
{
	while(1)
	{
		// Get the socket descriptor
		time_t start_time;
		int sock = *(int *)socket_desc;
		int n;

		char sendBuff[100], client_message[2000];

		while ((n = recv(sock, client_message, 2000, 0)) > 0)
		{
			time(&start_time);
			char command[2000];
			int num = rand() % 3500;
			sprintf(command, "gcc %s.c -o %d;./%d> temp", client_message, num, num);
			printf("%s\n", command);
			printf("%s\n", client_message);
			system(command);
			time_t end_time;
			time(&end_time);
			FILE *fp;
			char *line = NULL;
			size_t len = 0;
			ssize_t read;

			fp = fopen("temp", "r");
			if (fp == NULL)
				exit(EXIT_FAILURE);

			while ((read = getline(&line, &len, fp)) != -1)
			{
				// printf("Retrieved line of length %zu :\n", read);
				printf("%s", line);
				write(sock, line, strlen(line));
			}
			int server_utilization_time = difftime(end_time, start_time);
			char* server_utilization_time_str[50];
			sprintf(server_utilization_time_str, "%d", server_utilization_time);
			write(sock, "serverUtilizationTime#", 22);
			write(sock, strcat(server_utilization_time_str, "#"), strlen(server_utilization_time_str)+1);
			write(sock, "!@$%^&*()#", 10);
			fclose(fp);
			if (line)
				free(line);
		}
	}
	return 0;
}
