#include <stdio.h>
#include <fcntl.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/ioctl.h>

#include "car.h"

#define SERV_PORT 	8888
#define FILENAME 	"/dev/car"

unsigned int str2cmd(char *str, unsigned int size)
{
	unsigned int cmd;

	switch (

int main(int argc, char *argv[])
{
	int fd;
	int listen_fd, conn_fd;
	socklen_t cli_len;
	struct sockaddr_in cli_addr, serv_addr;
	char cmd_buf[32] = { 0 };
	ssize_t size;

	fd = open(FILENAME, O_RDWR);
	if (fd < 0) {
		printf("can't open %s\n", FILENAME);
		return 0;
	}

	listen_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (listen_fd == -1) {
		printf("socket fail...\n");
		return -1;
	}

	bzero(&serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(SERV_PORT);

	bind(listen_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
	listen(listen_fd, 5);
	ioctl(fd, 1);

	conn_fd = accept(listen_fd, (struct sockaddr *)&cli_addr, &cli_len);
	while (1) {
		memset(cmd_buf, 0, sizeof(cmd_buf));
		if (size = read(conn_fd, cmd_buf, sizeof(cmd_buf)) > 0) {
			printf("command: %s\n", cmd_buf);
			ioctl(fd, cmd_buf);
		write(conn_fd, "OK", strlen("OK"));
	}

	close(listen_fd);

	return 0;
}

