#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  fork();
  for (int i = 0; i < 10; ++i) {
    printf("Sleeping\n");
  }
  sleep(5);
  printf("Done!\n");
}
