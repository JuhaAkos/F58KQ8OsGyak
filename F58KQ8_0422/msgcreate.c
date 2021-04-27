#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX 100

struct msg_buffer {
    long msg_type;
    char msg_text[100];
} message;

int main(void) {
    key_t key;
    int msg_id;

    key = ftok("msgcreate.c", 65);
    msg_id = msgget(key, 0664 | IPC_CREAT);
    message.msg_type = 1;

    printf("Kerem az uzenetet: \n");
    fgets(message.msg_text,MAX,stdin);
    msgsnd(msg_id, &message, sizeof(message), 0);
    printf("Uzenet elkuldve: %s", message.msg_text);
    printf("\n");
    return 0;
}
