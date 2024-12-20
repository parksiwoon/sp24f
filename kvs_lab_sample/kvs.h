#ifndef KVS_H
#define KVS_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<fcntl.h>
#include<unistd.h>

#define MAX_LEVEL 16

struct node {
    char key[100];
    char* value;
    struct node* next[MAX_LEVEL];
};  
typedef struct node node_t;

struct kvs {
    struct node* header; 
    int items; 
    int kvs_mx_level;
};
typedef struct kvs kvs_t; 

kvs_t* kvs_open();
int kvs_close(kvs_t* kvs);
int put(kvs_t* kvs, const char* key, const char* value);
char* get(kvs_t* kvs, const char* key);
int rand_lv();
int do_snapshot(kvs_t* kvs, const char* path, int custom);
int do_recovery(kvs_t* kvs, const char* path, int custom);

#endif
