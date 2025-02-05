#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include "msgq.h"

int main() {
    int msgid = msgget(key, IPC_CREAT | 0666);
    MQ msg;

    msgrcv(msgid, &msg, sizeof(msg.md), 2, 0);
    printf("Binary: %s\n", msg.md);

    return 0;
}

