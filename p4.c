#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include "msgq.h"

int main() {
    int msgid = msgget(key, IPC_CREAT | 0666);
    MQ msg;

    msgrcv(msgid, &msg, sizeof(msg.md), 4, 0);
    printf("Hexadecimal: %s\n", msg.md);

    msgctl(msgid, IPC_RMID, NULL); // Cleanup the message queue

    return 0;
}

