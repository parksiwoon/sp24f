//설명: query.dat 파일을 읽고, put 또는 get 작업을 수행한 뒤 결과를 answer.dat에 저장
#include "kvs.h"

int main()
{
    kvs_t* kvs = open();

    if (!kvs) return -1;

    FILE *query = fopen("query.dat", "r");
    FILE *answer = fopen("answer.dat", "w");
    if (!query || !answer) {
        printf("Failed to open file\n");
        return -1;
    }

    char line[256];
    char operation[10], key[100], value[100];
    while (fgets(line, sizeof(line), query)) {
        // 개행 문자 제거
        line[strcspn(line, "\n")] = '\0';

        // 라인 파싱
        int num_tokens = sscanf(line, "%[^,],%[^,],%s", operation, key, value);
        if (num_tokens != 3) {
            printf("Failed to parse line: %s\n", line);
            continue;
        }

        if (strcmp(operation, "get") == 0) {
            char *result = get(kvs, key);
            if (result) {
                fprintf(answer, "%s\n", result);
                free(result);
            } else {
                fprintf(answer, "-1\n");
            }
        }
        // set 연산을 무시합니다.
        else if (strcmp(operation, "set") == 0) {
            // set 연산을 처리하지 않으므로 아무 작업도 하지 않습니다.
            // put(kvs, key, value);  // 주석 처리 또는 삭제
        } else {
            printf("Unknown operation: %s\n", operation);
        }
    }

    fclose(query);
    fclose(answer);
    close(kvs);

    return 0;
}

