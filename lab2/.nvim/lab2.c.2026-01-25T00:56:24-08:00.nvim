#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  char *buff = NULL;
  size_t size = 0;

  printf("Enter programs to run\n");

  while (getline(&buff, &size, stdin) != -1) {

    printf("Enter programs to run\n");

    char *tok;
    char *saveptr;
    tok = strtok_r(buff, "\n", &saveptr);

    // printf("%s\n", tok);
    pid_t pid = fork(); // 0 = child -1 = fail

    if (pid == -1) { // fail
      printf("fork failed");
    } else if (pid == 0) { // child
      if (execl(buff, tok, NULL) == -1) {
        perror("exec failed");
      }
    } else { // parent
      waitpid(pid, NULL, 0);
    }
  }
  perror("no getline input, ending program");
  free(buff);
}
