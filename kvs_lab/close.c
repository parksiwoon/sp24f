//설명: close 함수는 KVS의 모든 메모리를 해제
#include "kvs.h"

int close(kvs_t* kvs)
{
	/* do program */
	node_t *current = kvs->header->forward[0];
    while (current != NULL) {
        node_t *next = current->forward[0];
        free(current->value);
        free(current->forward);
        free(current);
        current = next;
    }
    free(kvs->header->forward);
    free(kvs->header);
    free(kvs);

	return 0;
}
