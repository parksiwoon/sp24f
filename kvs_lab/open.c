//설명: open 함수는 kvs_t 인스턴스를 생성하고 초기화
#include "kvs.h"

kvs_t* open()
{
    kvs_t* kvs = (kvs_t*) malloc (sizeof(kvs_t));

    if (!kvs) {
        printf("Failed to open kvs\n");
        return NULL;
    }
    kvs->header = (node_t *)malloc(sizeof(node_t));
    if (!kvs->header) {
        printf("Failed to allocate memory for header\n");
        free(kvs);
        return NULL;
    }
    kvs->header->forward = (node_t **)malloc(sizeof(node_t *) * MAX_LEVEL);
    if (!kvs->header->forward) {
        printf("Failed to allocate memory for forward pointers\n");
        free(kvs->header);
        free(kvs);
        return NULL;
    }
    for (int i = 0; i < MAX_LEVEL; i++) {
        kvs->header->forward[i] = NULL;
    }

    kvs->level = 0;
    kvs->items = 0;
    printf("Open: kvs has %d items\n", kvs->items);

    return kvs;
}

