//설명: close 함수는 KVS의 모든 메모리를 해제
#include "kvs.h"
#include <stdlib.h>

int close(kvs_t* kvs)
{
    if (kvs != NULL) {
        // 데이터베이스에 할당된 노드들의 메모리 해제
        node_t* current = kvs->db;
        while (current != NULL) {
            node_t* next = current->next;
            free(current->value); // value에 할당된 메모리 해제
            free(current);        // 노드에 할당된 메모리 해제
            current = next;
        }

        // kvs_t 구조체에 할당된 메모리 해제
        free(kvs);
    }

    return 0;
}
