#include <stdio.h>
#include <stdlib.h>

struct A {
  char a;
  int b;
  char c;
};

int main(void) { printf("%lu\n", sizeof(struct A)); }
