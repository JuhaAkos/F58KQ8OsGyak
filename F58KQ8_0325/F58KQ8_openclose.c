#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int fd, sz;
    char *c = (char *) calloc(100, sizeof(char));

    fd = open("F58KQ8.txt", O_RDWR);
    if (fd == -1) {
        perror("open() error");
        exit(-1);
    }

    sz = read(fd, c, 128);
    printf("called read(% d, c, 128). returned that"
            " %d bytes were read.\n", fd, sz);

    lseek(fd, 0, SEEK_SET);
    int result = lseek(fd, 0, SEEK_SET);
    printf("lseek() : %d is the new file cursor.\n", result);


    char stuff[] = "mennyit ír ki a konzolra.";
    //őszinté elnézést kérek, de itt tényleg nem volt tiszta pontosan mit/hogyan kellene megoldani
    write(fd, stuff,strlen(stuff));

    close(fd);
    return 0;
}
