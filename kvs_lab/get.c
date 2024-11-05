//설명: get 함수는 Skip List에서 해당 key를 검색하고, 있으면 value를 반환
#include "kvs.h"

char* get(kvs_t* kvs, const char* key){
    // 빈 데이터베이스인 경우
    if (kvs->db == NULL) {
        printf("Key not found: %s\n", key);
        return NULL;
    }

    // 데이터베이스를 처음부터 끝까지 탐색
    node_t* current = kvs->db;
    while (current != NULL) {
        // 키를 찾았을 경우
        if (strcmp(current->key, key) == 0) {
            // 값을 복제하여 반환
            char* value = strdup(current->value);
            if (value == NULL) {
                fprintf(stderr, "Failed to strdup\n");
                return NULL;
            }
            return value;
        }
        current = current->next;
    }

    // 키를 찾지 못한 경우
    printf("Key not found: %s\n", key);
    return NULL;
}




/**
 이 코드에서는 다음과 같은 기능을 수행합니다:

1. key를 검색하여 해당하는 노드를 찾습니다.
2. key가 존재하면 해당 value를 복사하여 반환합니다.
3. value가 NULL일 경우 메모리 할당 실패 메시지를 출력하고 NULL을 반환합니다.
 */
