#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

void do_nothing(int sig) {}
void handleSignals(int sig)
{
    printf("Az int paraméter értéke: %d\n", sig);
}

int main(void) {
    printf("A kellő PID: %d\n", (int)getpid());

    signal(SIGTERM, handleSignals);
    unsigned sec=3;

    while (1) {
        printf("Varok, de meddig?\n");
        alarm(sec);
        signal(SIGALRM, do_nothing);
        pause();
    }

    return 0;
}

