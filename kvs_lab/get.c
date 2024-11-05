//설명: get 함수는 Skip List에서 해당 key를 검색하고, 있으면 value를 반환
#include "kvs.h"

char* get(kvs_t* kvs, const char* key){
    node_t *current = kvs->header;

    for (int i = kvs->level; i >= 0; i--) {
        while (current->forward[i] != NULL && strcmp(current->forward[i]->key, key) < 0) {
            current = current->forward[i];
        }
    }
    current = current->forward[0];

    if (current != NULL && strcmp(current->key, key) == 0) {
        char *value = strdup(current->value);
        if (!value) {
            printf("Failed to allocate memory for value\n");
            return NULL;
        }
        return value;
    }
    return NULL;
}




/**
 이 코드에서는 다음과 같은 기능을 수행합니다:

1. key를 검색하여 해당하는 노드를 찾습니다.
2. key가 존재하면 해당 value를 복사하여 반환합니다.
3. value가 NULL일 경우 메모리 할당 실패 메시지를 출력하고 NULL을 반환합니다.
 */
