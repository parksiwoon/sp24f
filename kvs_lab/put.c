#include "kvs.h"

int put(kvs_t *kvs, const char *key, const char *value) {
    node_t *update[MAX_LEVEL];
    node_t *x = kvs->header;

    for (int i = kvs->level - 1; i >= 0; i--) {
        while (x->forward[i] != NULL && strcmp(x->forward[i]->key, key) < 0) {
            x = x->forward[i];
        }
        update[i] = x;
    }
    x = x->forward[0];

    if (x != NULL && strcmp(x->key, key) == 0) {
        free(x->value);
        x->value = strdup(value);
    } else {
        int level = random_level();
        if (level > kvs->level) {
            for (int i = kvs->level; i < level; i++) {
                update[i] = kvs->header;
            }
            kvs->level = level;
        }

        x = (node_t *)malloc(sizeof(node_t));
        strcpy(x->key, key);
        x->value = strdup(value);
        x->forward = (node_t **)malloc(sizeof(node_t *) * level);

        for (int i = 0; i < level; i++) {
            x->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = x;
        }
        kvs->items++;
    }
    return 0;
}
