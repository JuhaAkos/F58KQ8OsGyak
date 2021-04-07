
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

int main(int argc, char **argv) {
    pid_t pid;

    if (argc < 1) {
        perror(" Nincs kinek");
        exit(1);
    }

    pid = atoi(argv[1]);

    kill(pid, SIGALRM);

    return 0;
}
