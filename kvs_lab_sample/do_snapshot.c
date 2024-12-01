#include "kvs.h"
#include <fcntl.h>  // open(), O_CREAT, O_WRONLY 등 사용
#include <unistd.h> // write(), close(), fsync() 등 사용
#include <string.h> // strlen(), snprintf() 등 사용
#include <stdio.h>  // printf() 등 사용

int do_snapshot(kvs_t* kvs, const char* path, int custom) {
    if (!kvs) return -1;

    int fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("Error opening snapshot file");
        return -1;
    }

    node_t* node = kvs->header->next[0];
    while (node) {
        char line[356];  // 최대 key(100) + value(255) + 구분자와 개행문자
        snprintf(line, sizeof(line), "%s,%s\n", node->key, node->value);

        ssize_t written = write(fd, line, strlen(line));
        if (written != strlen(line)) {
            perror("Error writing to snapshot file");
            close(fd);
            return -1;
        }

        node = node->next[0];
    }

    fsync(fd);  // 데이터가 디스크에 저장되도록 보장
    close(fd);
    return 0;
}

