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
    if ((execl("./child", "child", (char*)NULL))<0) {
        perror("execl error");
    }
}
else {
    if ((waitpid(pid, NULL, 0))<0){
        perror("wait error");
    }
}
return 0;
}
