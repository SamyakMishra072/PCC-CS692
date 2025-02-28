/* Server Program */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#define SOCKET_PATH "crc_socket"
#define BUFFER_SIZE 1024

void computeCRC(char *data, char *divisor, char *codeword) {
    int dataLen = strlen(data);
    int divisorLen = strlen(divisor);
    char temp[BUFFER_SIZE];
    strcpy(temp, data);
    
    for (int i = 0; i < divisorLen - 1; i++)
        strcat(temp, "0");
    
    char remainder[BUFFER_SIZE];
    strcpy(remainder, temp);
    
    for (int i = 0; i <= strlen(temp) - divisorLen; i++) {
        if (remainder[i] == '1') {
            for (int j = 0; j < divisorLen; j++) {
                remainder[i + j] = (remainder[i + j] == divisor[j]) ? '0' : '1';
            }
        }
    }
    
    strcpy(codeword, data);
    strcat(codeword, remainder + dataLen);
}

int main() {
    int server_fd, client_fd;
    struct sockaddr_un server_addr;
    char data[BUFFER_SIZE], divisor[BUFFER_SIZE], codeword[BUFFER_SIZE];
    
    unlink(SOCKET_PATH);
    server_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Socket creation failed");
        exit(1);
    }
    
    server_addr.sun_family = AF_UNIX;
    strcpy(server_addr.sun_path, SOCKET_PATH);
    
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Bind failed");
        exit(1);
    }
    
    if (listen(server_fd, 5) == -1) {
        perror("Listen failed");
        exit(1);
    }
    
    printf("Server is waiting for a connection...\n");
    client_fd = accept(server_fd, NULL, NULL);
    if (client_fd == -1) {
        perror("Accept failed");
        exit(1);
    }
    
    read(client_fd, data, BUFFER_SIZE);
    read(client_fd, divisor, BUFFER_SIZE);
    
    computeCRC(data, divisor, codeword);
    write(client_fd, codeword, BUFFER_SIZE);
    
    close(client_fd);
    close(server_fd);
    unlink(SOCKET_PATH);
    
    return 0;
}
