#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX 100

int main(void) {
  key_t key;
  int msg_id;

  key = ftok("msgcreate.c", 65);
  msg_id = msgget(key, 0664 | IPC_CREAT);

  msgctl(msg_id, IPC_RMID, NULL);

  return 0;
}
