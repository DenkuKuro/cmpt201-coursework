#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {

  printf("Start PID=%d, ", getpid());
  printf("parent PID=%d\n", getppid());
  pid_t id = fork();

  if (id == 0) {
    printf("CHILD: PID=%d, ", getpid());
    printf("parent PID=%d\n", getppid());
  } else {
    printf("PARENT PID=%d, ", getpid());
    printf("child PID=%d\n", id);
  }
}
