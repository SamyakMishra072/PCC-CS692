#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
#include<unistd.h>
#include "msgq.h"

// Function to convert decimal to binary using bitwise operations
void toBinary(int num, char *bin) {
    int i = 0;
    for (int bit = 31; bit >= 0; bit--) {
        bin[i++] = ((num >> bit) & 1) ? '1' : '0';
    }
    bin[i] = '\0';
}

// Function to convert decimal to octal using bitwise operations
void toOctal(int num, char *oct) {
    int i = 0;
    for (int shift = 30; shift >= 0; shift -= 3) { // Process 3 bits at a time
        int digit = (num >> shift) & 7; // Extract 3 bits
        if (i || digit) {  // Avoid leading zeros
            oct[i++] = digit + '0';
        }
    }
    if (i == 0) oct[i++] = '0'; // Handle zero case
    oct[i] = '\0';
}

// Function to convert decimal to hexadecimal using bitwise operations
void toHex(int num, char *hex) {
    int i = 0;
    for (int shift = 28; shift >= 0; shift -= 4) { // Process 4 bits at a time
        int digit = (num >> shift) & 15; // Extract 4 bits
        if (i || digit) { // Avoid leading zeros
            hex[i++] = digit < 10 ? (digit + '0') : (digit - 10 + 'A');
        }
    }
    if (i == 0) hex[i++] = '0'; // Handle zero case
    hex[i] = '\0';
}

int main() {
    int msgid = msgget(key, IPC_CREAT | 0666);
    MQ msg;

    char binary[N], octal[N], hex[N];
    int num;

    printf("Enter a decimal number: ");
    scanf("%d", &num);

    toBinary(num, binary);
    toOctal(num, octal);
    toHex(num, hex);

    // Send Binary
    msg.mt = 2;
    strcpy(msg.md, binary);
    msgsnd(msgid, &msg, sizeof(msg.md), 0);

    // Send Octal
    msg.mt = 3;
    strcpy(msg.md, octal);
    msgsnd(msgid, &msg, sizeof(msg.md), 0);

    // Send Hexadecimal
    msg.mt = 4;
    strcpy(msg.md, hex);
    msgsnd(msgid, &msg, sizeof(msg.md), 0);

    printf("Binary: %s sent\n", binary);
    printf("Octal: %s sent\n", octal);
    printf("Hexadecimal: %s sent\n", hex);

    return 0;
}

