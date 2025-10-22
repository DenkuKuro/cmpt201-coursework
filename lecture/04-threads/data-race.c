#define _GNU_SOURCE
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX 1000000

int cnt = 0;

void *counter(void *arg) {
  for (int i = 0; i < MAX; ++i)
    ++cnt;

  return NULL;
}

int main(void) {

  pthread_t thread1;
  pthread_create(&thread1, NULL, counter, NULL);
  pthread_t thread2;
  pthread_create(&thread2, NULL, counter, NULL);
  pthread_join(thread2, NULL);
  pthread_join(thread1, NULL);
  printf("The answer is...\n");
  sleep(1);
  printf(" = %d\n", cnt);
}
