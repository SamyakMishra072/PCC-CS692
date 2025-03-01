#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX 512
#define KEY ftok("memory", 67)

typedef struct { long ttype; int tot; } total;
typedef struct { long mtype; char data[MAX]; } message;
typedef struct { long mtype; int num; } messageRoll;
