#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *buff = NULL;
  size_t size = 0;

  while (getline(&buff, &size, stdin) != -1) {

    char *tok;
    char *saveptr;

    tok = strtok_r(buff, " ", &saveptr);
    while (tok != NULL) {
      printf("%s\n", tok);
      tok = strtok_r(NULL, " ", &saveptr);
    }
  }
  perror("no getline input, ending program");
  free(buff);
}
