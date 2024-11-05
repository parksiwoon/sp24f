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

    char operation[10], key[100], value[100];
    while (fscanf(query, "%[^,],%[^,],%s", operation, key, value) != EOF) {
        if (strcmp(operation, "put") == 0) {
            // put 연산은 없으므로 무시
        } else if (strcmp(operation, "set") == 0) {
            // set 연산을 무시하여 키-값을 저장하지 않음
        } else if (strcmp(operation, "get") == 0) {
            char *result = get(kvs, key);
            if (result) {
                fprintf(answer, "%s\n", result);
                free(result);
            } else {
                fprintf(answer, "-1\n");
            }
        }
    }

	/** 
	if(!kvs) {
		printf("Failed to open kvs\n");
		return -1;
	}
	*/

	// workload execution  
	
	// 1) 	file read 
	// 2) 	if put, insert (key, value) into kvs.
	// 		if get, seach the key in kvs and return the value. 
	//		Return -1 if the key is not found  

	fclose(query);
    fclose(answer);
	close(kvs);
	
	return 0;
}
