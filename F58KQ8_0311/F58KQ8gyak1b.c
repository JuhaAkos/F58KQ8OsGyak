#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
    int hf1;
    if((hf1 = system("alma"))<0){
        printf("system() error");
    }
    if (WIFEXITED(hf1)){
        printf("A visszaadott érték: %d\n",WEXITSTATUS(hf1));
    }

    exit(0);
}
