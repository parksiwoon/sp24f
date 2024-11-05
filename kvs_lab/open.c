//설명: open 함수는 kvs_t 인스턴스를 생성하고 초기화
#include "kvs.h"

// 레벨을 무작위로 생성하는 함수
int random_level() {
    int level = 1;
    while (rand() < RAND_MAX / 2 && level < MAX_LEVEL) {
        level++;
    }
    return level;
}

// KVS 초기화 함수
kvs_t *open() {
    kvs_t *kvs = (kvs_t *)malloc(sizeof(kvs_t));
    kvs->level = 1;
    kvs->items = 0;
    kvs->header = (node_t *)malloc(sizeof(node_t));
    memset(kvs->header->key, 0, sizeof(kvs->header->key));
    kvs->header->value = NULL;
    kvs->header->forward = (node_t **)malloc(sizeof(node_t *) * MAX_LEVEL);
    for (int i = 0; i < MAX_LEVEL; i++) {
        kvs->header->forward[i] = NULL;
    }
    return kvs;
}
