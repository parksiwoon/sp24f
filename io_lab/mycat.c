#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>  // open
#include <unistd.h> // read, write, close, dup2

#define BUFF_SIZE 16

int main(int argc, char* argv[])
{
    int ifd, ofd;
    char buff[BUFF_SIZE];
    ssize_t nreads;

    if(argc < 2) {
        fprintf(stdout, "No arguments\n");
        return 0;
    } else if(argc == 2) {
        // 입력 파일 읽기
        ifd = open(argv[1], O_RDONLY);
        if (ifd < 0) {
            perror("Failed to open input file");
            return -1;
        }

        // 읽고 출력
        while ((nreads = read(ifd, buff, BUFF_SIZE)) > 0) {
            write(STDOUT_FILENO, buff, nreads);
        }

        close(ifd);
    } else if(argc == 4 && !strcmp(argv[2], "into")) {
        // 입력 파일
        ifd = open(argv[1], O_RDONLY);
        if (ifd < 0) {
            perror("Failed to open input file");
            return -1;
        }

        // 출력 파일
        ofd = open(argv[3], O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (ofd < 0) {
            perror("Failed to open output file");
            close(ifd);
            return -1;
        }

        // 리다이렉션
        dup2(ofd, STDOUT_FILENO);

        // 읽고 출력
        while ((nreads = read(ifd, buff, BUFF_SIZE)) > 0) {
            write(STDOUT_FILENO, buff, nreads);
        }

        close(ifd);
        close(ofd);
    } else {
        fprintf(stdout, "Wrong arguments\n");
        return 0;
    }

    return 0;
}
