#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void) {

int pid = fork();

if (pid < 0) {
    perror("fork error");
}
else if (pid == 0) {
    if ((execlp("ls", "ls", (char*)NULL))<0) {
        perror("execlp error");
    }
}
else {
    if ((waitpid(pid, NULL, 0))<0){
        perror("wait error");
    }
}
return 0;
}
