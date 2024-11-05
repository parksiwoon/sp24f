#include "kvs.h"

int main() {
    kvs_t* kvs = open();

    if (!kvs) {
        printf("Failed to open kvs\n");
        return -1;
    }

    FILE* fp1 = fopen("query.dat", "r");
    FILE* fp2 = fopen("answer.dat", "w");

    char line[256];
    while (fgets(line, sizeof(line), fp1) != NULL) {
        line[strcspn(line, "\n")] = '\0';

        char* command = strtok(line, ",");
        char* key = strtok(NULL, ",");
        char* value = strtok(NULL, ",");

        if (command != NULL && key != NULL) {
            //"GET" 명령어일 경우
            if (strcmp(command, "get") == 0) {
                char* result = get(kvs, key);
                if (result != NULL) {
                    printf("Get: %s = %s\n", key, result);
                    fprintf(fp2, "%s\n", result); // answer.dat 파일에 쓰기
                } else {
                    printf("Key not found: %s\n", key);
                }
            } else if (strcmp(command, "set") == 0 && value != NULL) {
                put(kvs, key, value);
                printf("put: %s = %s\n", key, value);
            } else {
                printf("Invalid command: %s\n", command);
            }
        }
    }

    fclose(fp1);
    fclose(fp2);
    close(kvs);

    return 0;
}