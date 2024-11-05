//설명: kvs.h 파일에서 Skip List 구조를 사용할 수 있도록 node_t 구조체를 확장합니다. 각 노드가 여러 레벨의 포인터를 가질 수 있도록 level을 추가
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEVEL 16 // Skip List의 최대 레벨

// Skip List 노드를 정의
typedef struct node {
    char key[100];
    char *value;
    struct node **forward; // 각 레벨의 다음 노드를 가리킴
} node_t;

// KVS 구조체를 정의
typedef struct kvs {
    node_t *header;
    int level;
    int items;
} kvs_t;

// 함수 원형 선언
kvs_t *open(); // KVS 초기화
int close(kvs_t *kvs); // 모든 메모리 해제
int put(kvs_t *kvs, const char *key, const char *value); // KVS에 키-값 삽입
char *get(kvs_t *kvs, const char *key); // KVS에서 키를 이용해 값 검색

int random_level(); // 레벨을 무작위로 생성하는 함수

