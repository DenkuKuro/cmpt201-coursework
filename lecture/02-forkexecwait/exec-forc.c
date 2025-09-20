#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  pid_t pid = fork();

  if (pid == 0) {
    printf("CHILD!\n");
    char *args[] = {"/bin/ls", "-a", "-l", "-h", (char *)NULL};
    execv("/bin/ls", args);
  } else {
    printf("PARENT!\n");
    execlp("/bin/ls", "/bin/ls", "-a", (char *)NULL);
  }

  printf("%d\n", getpid());
}
