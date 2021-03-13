#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Ha nem akar tobb parancsot megadni, kerem adjon meg 'kilep'-et bemenetkent:\n\n");

    char sor[100];
    while (strcmp(sor,"kilep")!=0) {

        scanf("%s", sor);

        int hf1;
        if((hf1 = system(sor))<0){
            printf("system() error");
        }
        if (WIFEXITED(hf1)){
            printf("A visszaadott érték: %d\n",WEXITSTATUS(hf1));
        }
    }
    printf("A program vegzett!\n");
    return 0;
}
