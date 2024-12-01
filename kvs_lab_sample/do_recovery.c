#include "kvs.h"
#include <fcntl.h>  // open(), O_RDONLY 등 사용
#include <unistd.h> // read(), close() 등 사용
#include <string.h> // strtok(), sscanf() 등 사용
#include <stdio.h>  // printf() 등 사용

int do_recovery(kvs_t* kvs, const char* path, int custom) {
    if (!kvs) return -1;

    int fd = open(path, O_RDONLY);
    if (fd < 0) {
        perror("Error opening recovery file");
        return -1;
    }

    char buffer[512];
    ssize_t len;
    while ((len = read(fd, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[len] = '\0';
        char key[100], value[256];

        char* line = strtok(buffer, "\n");
        while (line != NULL) {
            if (sscanf(line, "%99[^,],%255s", key, value) == 2) {
                put(kvs, key, value);
                // 디버깅 메시지 제거
                // printf("Parsed key: %s, value: %s\n", key, value);
            }
            line = strtok(NULL, "\n");
        }
    }

    if (len < 0) {
        perror("Error reading recovery file");
        close(fd);
        return -1;
    }

    close(fd);
    return 0;
}


