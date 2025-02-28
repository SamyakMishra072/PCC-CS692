/* Client Program */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#define SOCKET_PATH "crc_socket"
#define BUFFER_SIZE 1024

int main() {
    int client_fd;
    struct sockaddr_un server_addr;
    char data[BUFFER_SIZE], divisor[BUFFER_SIZE], codeword[BUFFER_SIZE];

    client_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (client_fd == -1) {
        perror("Socket creation failed");
        exit(1);
    }

    server_addr.sun_family = AF_UNIX;
    strcpy(server_addr.sun_path, SOCKET_PATH);

    if (connect(client_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Connection failed");
        exit(1);
    }

    printf("Enter data word: ");
    scanf("%s", data);
    printf("Enter divisor: ");
    scanf("%s", divisor);

    write(client_fd, data, BUFFER_SIZE);
    write(client_fd, divisor, BUFFER_SIZE);
    
    read(client_fd, codeword, BUFFER_SIZE);
    printf("Received codeword from server: %s\n", codeword);

    close(client_fd);
    return 0;
}
