#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "table.h"
#include "input_func.h"
int main() {
    int choice = 0;
    char *key = NULL;
    char *info = NULL;
    table table;
    table.msize = 0;
    table.csize = 0;
    do {
        printf("Please write size of vector\n");
        input_int(&table.msize);
        ;
    } while (table.msize <=0);
    table.items = calloc(table.msize, sizeof(item));
    do {
    choice = menu_action();
    switch (choice) {
        case 0:
            break;
        case 1:
            printf("Write a key\n");
            char t;
            scanf("%c", &t);
            key = get_str();
            printf("Write info\n");
            info = get_str();
            int inserted = insert(&table, key, info);
            if (inserted == -1) {
                printf("Duplicate keys\n");
                break;
            } else if (inserted == -2) {
                printf ("All positions are busy\n");
                break;
            }
            break;
        case 2:
            printf("Write a key\n");
            scanf("%c", &t);
            key = get_str();
            if (delete(&table, key) == -1) {
                printf("Element not found\n");
            }
            break;
        case 3:
            printf("Write a key\n");
            scanf("%c", &t);
            key = get_str();
            int searched = search(table, key);
            if (searched == -1) {
                printf("Key not found\n");
                break;
            } else {
                printf ("The index of element: %d\n", searched);
                printf("Info: %s\n",table.items[searched].info);
            }
            break;
        case 4:
            for (int i = 0; i<table.msize; ++i) {
                printf("%d %s %s", table.items[i].busy, table.items[i].key, table.items[i].info );
                printf("\n");
            }
            break;

        default:
            
            break;
    }
    } while (choice != 0);
    free(table.items);
    free(key);
    free(info);
    return 0;
}
