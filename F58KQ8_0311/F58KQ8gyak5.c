#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>



int main(void) {

pid_t ptomb[3];
int n = sizeof(ptomb) / sizeof(pid_t);

for (int i = 0; i < n; i++) {
    ptomb[i] = fork();
    if (ptomb[i] < 0) {
        perror("fork error");
    }
    else if (ptomb[i] == 0) {
        if (i == 0) {
            exit(0);
        }
        else if (i == 1) {
            abort();
        }
        else {
           printf("125 / 0 = %d", 125/0);
        }
    }
}
int stat;
pid_t pid;
pid = wait(&stat);
printf("PID: %ld\n",(long)pid);
printf("1.) Normális befejeződés, visszaadott érték: %d\n", stat);

int stat2;
pid_t pid2;
pid2 = wait(&stat2);
printf("PID: %ld\n",(long)pid2);
printf("2.) Normális befejeződés, visszaadott érték: %d\n", stat2);

int stat3;
pid_t pid3;
pid3 = wait(&stat3);
printf("PID: %ld\n",(long)pid3);
printf("3.) Normális befejeződés, visszaadott érték: %d\n", stat3);

}
