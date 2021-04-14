#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#define SIZE 6

int main(void) {
    int fds[2];
    int pid;

    if (pipe(fds) < 0) {
        exit(1);
    }

    pid = fork();

    if (pid > 0) {
        char msg[] = "F58KQ8";
        write(fds[1], msg, SIZE);
        close(fds[1]);
        wait(NULL);

    return 0;
    }

    char inbuf[SIZE];
    read(fds[0], inbuf, SIZE/sizeof(char));
    close(fds[0]);

    printf("A kiolvasott szoveg:\n%s\n", inbuf);

    wait(NULL);

    return 0;
}
