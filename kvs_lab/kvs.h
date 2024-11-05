//설명: kvs.h 파일에서 Skip List 구조를 사용할 수 있도록 node_t 구조체를 확장합니다. 각 노드가 여러 레벨의 포인터를 가질 수 있도록 level을 추가
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node {
	char key[100];
	char* value;
	struct node* next;
};	
typedef struct node node_t;


struct kvs{
	struct node* db; // database
	int items; // number of data 
};
typedef struct kvs kvs_t; 

kvs_t* open();
int close(kvs_t* kvs); // free all memory space 
int put(kvs_t* kvs, const char* key, const char* value); // return -1 if failed.
char* get(kvs_t* kvs, const char* key); // return NULL if not found. 
