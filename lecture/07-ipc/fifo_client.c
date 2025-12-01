#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define FIFO_FILE "myfifo"

int main() {
  int fd;
  char sendbuf[80] = "Hello from client";
  fd = open(FIFO_FILE, O_WRONLY);

  if (fd == -1) {
    perror("open");
    exit(1);
  }

  if (write(fd, sendbuf, strlen(sendbuf)) == -2) {
    perror("write");
    exit(1);
  }

  close(fd);
  return 0;
}
