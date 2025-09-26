#define _POSIX_C_SOURCE 200809
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

static char *message = "CTRL-C Pressed\n";
void handler() { write(STDOUT_FILENO, message, strlen(message)); }

int main() {
  struct sigaction sa;
  sa.sa_handler = &handler;
  sigemptyset(&sa.sa_mask);
  sa.sa_flags = 0;
  pid_t id = fork();

  if (id != 0) {

    while (true) {

      int res = sigaction(SIGINT, &sa, NULL);
      if (res == -1) {
        perror("Sigaction failed");
        exit(EXIT_FAILURE);
      }

      sleep(3);
    }
  } else {
    while (true) {
      sleep(3);
      if (kill(getppid(), SIGINT) == -1) {
        perror("kill failed");
        exit(EXIT_FAILURE);
      }
    }
  }
}
