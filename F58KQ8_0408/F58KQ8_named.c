#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#define SIZE 11

int main(void) {
    int pid;
    int fds;

    mkfifo("F58KQ8", 0666);

    pid = fork();

    if (pid == 0) {
        char msg[] = "Juhász Ákos";
        fds = open("F58KQ8", O_WRONLY);
        write(fds, msg, SIZE+2);
        close(fds);
        wait(NULL);
        return 0;
    }

    char inbuf[SIZE];
    fds = open("F58KQ8", O_RDONLY);
    read(fds, inbuf, SIZE+2);
    close(fds);
    unlink("F58KQ8");

    printf("A kiolvasott szoveg:\n%s\n", inbuf);

    wait(NULL);

    return 0;
}
