#ifndef table_h
#define table_h
#include <stdio.h>
#include <string.h>
typedef struct item {
    char *info;
    char *key;
    int ind;
    int busy;
}item;
typedef struct table {
    item *items;
    int msize;
    int csize;
}table;
long long hash_function (char *key);
int solve_index (char *key, int size);
int search (table table, char* key);
int insert (table *table, char *key, char *info);
#endif
