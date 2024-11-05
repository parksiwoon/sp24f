#include "kvs.h"

int main() {
    kvs_t* kvs = open();
    FILE *queryFile = fopen("query.dat", "r");
    FILE *answerFile = fopen("answer.dat", "w");
    char operation[10], key[100], value[100];

    while (fscanf(queryFile, "%[^,],%[^,],%[^\n]\n", operation, key, value) != EOF) {
        if (strcmp(operation, "get") == 0) {
            char *result = get(kvs, key);
            if (result) {
                fprintf(answerFile, "%s\n", result);
                free(result);
            } else {
                fprintf(answerFile, "-1\n");
            }
        } else if (strcmp(operation, "set") == 0) {
            put(kvs, key, value);
        }
    }
    fclose(queryFile);
    fclose(answerFile);
    close(kvs);
    return 0;
}
