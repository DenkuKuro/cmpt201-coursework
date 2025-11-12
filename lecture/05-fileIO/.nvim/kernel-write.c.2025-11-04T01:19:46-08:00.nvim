#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main(void) {
  int fd = open("tmp", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);

  char *msg = "Hello, hope this works well!\n";
  int res = write(fd, msg, strlen(msg));

  while (true) {
    sleep(30);
  }

}
