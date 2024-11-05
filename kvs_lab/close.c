//설명: close 함수는 KVS의 모든 메모리를 해제
#include "kvs.h"

int close(kvs_t* kvs) {
    node_t* x = kvs->header;
    while (x) {
        node_t* next = x->forward[0];
        free(x->value);
        free(x->forward);
        free(x);
        x = next;
    }
    free(kvs);
    return 0;
}

