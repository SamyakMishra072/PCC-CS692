#include "header.h"

int compare(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int main() {
    int n, i, msgid = msgget(KEY, 0666 | IPC_CREAT);
    total tot; messageRoll mroll = {2}, mrollreturn = {6};
    int *rolls;

    msgrcv(msgid, &tot, sizeof(total), 4, 0);
    n = tot.tot;
    rolls = malloc(n * sizeof(int));

    for (i = 0; i < n; i++) {
        msgrcv(msgid, &mroll, sizeof(mroll), 2, 0);
        rolls[i] = mroll.num;
    }

    qsort(rolls, n, sizeof(int), compare);

    for (i = 0; i < n; i++) {
        mrollreturn.num = rolls[i];
        msgsnd(msgid, &mrollreturn, sizeof(mrollreturn), 0);
    }
    
    free(rolls);
    return 0;
}
