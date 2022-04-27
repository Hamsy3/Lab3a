#include "table.h"
long long hash_function (char *key) {
    int multiply = 59;
    long long hash = 0;
    int multiply_pow = 1;
    for (int i = 0; i < strlen(key); ++i ) {
        hash += key[i] * multiply_pow;
        multiply_pow *= multiply;
    }
    return hash;
}
int solve_index (char *key, int size) {
    int index = (hash_function(key)) % size;
    return index;
}
int search (table table, char *key) {
    int cur = solve_index(key, table.msize);
    for (int checked = 0; (table.items[cur].busy != 0) && (checked < table.csize); ++checked) {
        if (strcmp (table.items[cur].key, key) == 0) {
            return cur;
        }
        cur = ((cur+1) % table.msize);
    }
    return -1;
}
int insert (table *table, char *key, char *info) {
    int checked = 0;
    int cur = solve_index(key, table->msize);
    while ((table->items[cur].busy != 0) && (checked < table->csize)) {
        if (strcmp (table->items[cur].key, key) == 0) {
            return -1;
        }
        cur = ((cur+1) % table->msize);
        ++checked;
    }
    if ((checked < table->msize) && (table->csize<=table->msize)) {
        table->items[cur].key = key;
        table->items[cur].info = info;
        table->items[cur].busy = 1;
        table->items[cur].ind = cur;
        (table->csize++);
        return 0;
    }
    return -2;
}