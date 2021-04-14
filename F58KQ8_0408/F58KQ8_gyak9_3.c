#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void do_something();

int main()
{
    printf("PID: %d\n", (int)getpid());
    signal(SIGALRM, do_something);
    printf(" %d varok de meddig?\n");
    pause();
    printf(" Kibillent - terminálás: \n");
}
void do_something(){
    printf("F58KQ8");
}
