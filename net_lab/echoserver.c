#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <PORT>\n", argv[0]);
        return -1;
    }

    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_size;
    char buffer[BUFFER_SIZE];

    int port = atoi(argv[1]); // 포트 번호 설정
    server_sock = socket(PF_INET, SOCK_STREAM, 0); // 소켓 생성

    if (server_sock == -1) {
        perror("socket() error");
        return -1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY); // 모든 IP에서 접속 허용
    server_addr.sin_port = htons(port);

    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind() error");
        close(server_sock);
        return -1;
    }

    if (listen(server_sock, 5) == -1) {
        perror("listen() error");
        close(server_sock);
        return -1;
    }

    printf("Echo server is running on port %d...\n", port);

    client_addr_size = sizeof(client_addr);
    client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_addr_size);
    if (client_sock == -1) {
        perror("accept() error");
        close(server_sock);
        return -1;
    }

    while (1) {
    int str_len = read(client_sock, buffer, BUFFER_SIZE - 1);
    if (str_len == 0) {
        printf("Client disconnected.\n");
        break;
    }

    buffer[str_len] = '\0';
    printf("Received from client: %s", buffer);

    // write() 반환값 확인
    int bytes_written = write(client_sock, buffer, str_len);
    if (bytes_written == -1) {
        perror("write() error");
        break;
    }
}


    close(client_sock);
    close(server_sock);
    return 0;
}
