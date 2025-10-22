#define _GNU_SOURCE
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void *thread_func(void *arg) {
  printf("arg: %s\n", (char *)arg);
  printf("id: %d\n", gettid());

  return (void *)strlen(arg);
}

int main(void) {

  pthread_t thread;
  char *arg = "My very first thread!";
  pthread_create(&thread, NULL, thread_func, arg);
  void *ret_val = 0;
  pthread_join(thread, &ret_val);

  printf("%lld\n", (long long)ret_val);
}
