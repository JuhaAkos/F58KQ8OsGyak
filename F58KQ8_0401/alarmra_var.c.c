#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void do_nothing();

int main()
{
    printf("PID: %d\n", (int)getpid());
    signal(SIGALRM, do_nothing);
    printf(" %d varok de meddig?\n");
    pause();
    printf(" Vegre, itt az alarm \n");
}
void do_nothing(){ ;}
