#include "header.h"

int main() {
    int n, i, msgid = msgget(KEY, 0666 | IPC_CREAT);
    total tot = {3};
    tot2 = {4}; 
    message mname = {1};
    mnamesorted = {5};
    messageRoll mroll = {2};
    mrollsorted = {6};
    if (msgid == -1) {
        exit(1);
    }
    printf("Enter number of students: ");
    scanf("%d", &n);
    tot.tot = tot2.tot = n;
    msgsnd(msgid, &tot, sizeof(total), 0);
    msgsnd(msgid, &tot2, sizeof(total), 0);
    for (i = 0; i < n; i++) {
        printf("Enter name & roll for student %d: ", i + 1);
        scanf("%s %d", mname.data, &mroll.num);
        msgsnd(msgid, &mname, sizeof(mname), 0);
        msgsnd(msgid, &mroll, sizeof(mroll), 0);
    }
    printf("\nSorted Names and Roll Numbers:\n");
    for (i = 0; i < n; i++) {
        msgrcv(msgid, &mnamesorted, sizeof(mnamesorted), 5, 0);
        msgrcv(msgid, &mrollsorted, sizeof(mrollsorted), 6, 0);
        printf("%s\t%d\n", mnamesorted.data, mrollsorted.num);
    }
    msgctl(msgid, IPC_RMID, NULL);
    return 0;
}
