#include "header.h"

int compare(const void *a, const void *b) { return strcmp(*(char **)a, *(char **)b); }

int main() {
    int n, i, msgid = msgget(KEY, 0666 | IPC_CREAT);
    total tot; message mname = {1}, mnamereturn = {5};
    char **names;

    msgrcv(msgid, &tot, sizeof(total), 3, 0);
    n = tot.tot;
    names = malloc(n * sizeof(char *));
    
    for (i = 0; i < n; i++) {
        msgrcv(msgid, &mname, sizeof(mname), 1, 0);
        names[i] = strdup(mname.data);
    }

    qsort(names, n, sizeof(char *), compare);

    for (i = 0; i < n; i++) {
        strcpy(mnamereturn.data, names[i]);
        msgsnd(msgid, &mnamereturn, sizeof(mnamereturn), 0);
        free(names[i]);
    }
    
    free(names);
    return 0;
}
