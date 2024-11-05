#include "kvs.h"

int random_level() {
    int level = 0;
    while (rand() % 2 && level < MAX_LEVEL - 1) {
        level++;
    }
    return level;
}

int put(kvs_t* kvs, const char* key, const char* value)
{
    //printf("put: %s, %s\n", key, value);

    node_t *update[MAX_LEVEL];
    node_t *current = kvs->header;

    for (int i = kvs->level; i >= 0; i--) {
        while (current->forward[i] != NULL && strcmp(current->forward[i]->key, key) < 0) {
            current = current->forward[i];
        }
        update[i] = current;
    }

    current = current->forward[0];
    if (current != NULL && strcmp(current->key, key) == 0) {
        free(current->value);
        current->value = strdup(value);
    } else {
        int level = random_level();
        if (level > kvs->level) {
            for (int i = kvs->level + 1; i <= level; i++) {
                update[i] = kvs->header;
            }
            kvs->level = level;
        }

        current = (node_t *)malloc(sizeof(node_t));
        if (!current) {
            printf("Failed to allocate memory for node\n");
            return -1;
        }
        strcpy(current->key, key);
        current->value = strdup(value);
        if (!current->value) {
            printf("Failed to allocate memory for value\n");
            free(current);
            return -1;
        }
        current->forward = (node_t **)malloc(sizeof(node_t *) * (level + 1));
        if (!current->forward) {
            printf("Failed to allocate memory for forward pointers\n");
            free(current->value);
            free(current);
            return -1;
        }

        for (int i = 0; i <= level; i++) {
            current->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = current;
        }
        kvs->items++;
    }

    return 0;
}
