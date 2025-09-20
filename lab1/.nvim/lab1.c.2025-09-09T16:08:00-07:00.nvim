#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *buffer = NULL;
  size_t n = 0;

  printf("Please enter some text: ");

  ssize_t line = getline(&buffer, &n, stdin);
  char *token = NULL;
  char *delim = " ";
  char *saveptr = NULL;

  token = strtok_r(buffer, delim, &saveptr);
  while (token) {
    printf("%s\n", token);
    token = strtok_r(NULL, delim, &saveptr);
  }
  free(buffer);
}
