#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <IP> <PORT>\n", argv[0]);
        return -1;
    }

    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    sock = socket(PF_INET, SOCK_STREAM, 0); // 소켓 생성
    if (sock == -1) {
        perror("socket() error");
        return -1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]); // 서버 IP 설정
    server_addr.sin_port = htons(atoi(argv[2])); // 포트 설정

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect() error");
        close(sock);
        return -1;
    }

    printf("Connected to server...\n");

    while (1) {
    printf("Input message (q to quit): ");
    
    // fgets() 반환값 확인
    if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
        printf("Error reading input.\n");
        break;
    }

    if (!strcmp(buffer, "q\n")) break;

    // write() 반환값 확인
    int bytes_written = write(sock, buffer, strlen(buffer));
    if (bytes_written == -1) {
        perror("write() error");
        break;
    }

    int str_len = read(sock, buffer, BUFFER_SIZE - 1);
    buffer[str_len] = '\0';

    printf("Server replied: %s", buffer);
}


    close(sock);
    return 0;
}
