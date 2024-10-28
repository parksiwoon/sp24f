#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_LEVEL 4 // Skip List 최대 레벨 설정
//각 노드가 여러 레벨의 포인터를 가질 수 있도록 추가

typedef struct node {
	char key[100];
	char* value;
	struct node **forward; // 여러 레벨을 가리킬 수 있는 포인터 배열
    int level;
	//struct node* next;
} node_t;


typedef struct kvs {
	//struct node* db; // database
	struct node *header; // Skip List의 시작 노드
    int level;           // 현재 Skip List의 레벨
	int items; // number of data 
} kvs_t;


kvs_t* open();
int close(kvs_t* kvs); // free all memory space 
int put(kvs_t* kvs, const char* key, const char* value); // return -1 if failed.
char* get(kvs_t* kvs, const char* key); // return NULL if not found. 
