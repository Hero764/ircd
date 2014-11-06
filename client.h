#ifndef CLIENT_H
#define CLIENT_H

#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_CLIENTS 100
#define MAX_CHAN_JOIN 5

struct client {
	char pass[20];
	char user[20];
	char nick[20];
	char realname[30];

	struct channel *joined_channels[MAX_CHAN_JOIN];
	int n_joined;
	
	int mode;
	int fd;
	struct sockaddr_in peername;
	
	int registered;
	int welcomed;
};

void initialize_clients();

int new_client(int conn_fd);
int remove_client(int conn_fd);
int set_pass(int conn_fd, char *pass);
int set_nick(int conn_fd, char *nick);
int set_user(int conn_fd, char *username, int mode, char *realname);
struct client *get_client(int conn_fd);
int get_client_prefix(int cli_fd, char *sender_buffer);
void send_welcome(struct client *cli);

#endif
