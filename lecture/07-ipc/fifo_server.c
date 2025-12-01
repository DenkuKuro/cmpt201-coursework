#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

#define FIFO_FILE "myfifo"

int main() {
  int fd;
  char readbuf[80];

  mkfifo(FIFO_FILE, S_IRUSR | S_IWUSR);

  fd = open(FIFO_FILE, O_RDONLY);
  if (fd == -1) {
    perror("open");
    exit(1);
  }

  while (read(fd, readbuf, sizeof(readbuf)) > 0) {
    printf("Received: %s\n", readbuf);
  }

  close(fd);
  return 0;
}

