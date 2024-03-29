#include "input_func.h"
// Реализация readline
char *get_str()
{
    char buf[81] = {0};
    char *res = NULL;
    int len = 0;
    int n = 0;
    do {
        n = scanf("%80[^\n]", buf);
        if (n < 0) {
            if (!res) {
                return NULL;
            }
        }
        else if (n > 0) {
            int chunk_len = (int) strlen(buf);
            int str_len = len + chunk_len;
            res = realloc(res, str_len + 1);
            memcpy(res + len, buf, chunk_len);
            len = str_len;
        }
        else {
            scanf("%*c");
        }
    } while (n > 0);

    if (len > 0) {
        res[len] = '\0';
    }
    else {
        res = calloc(1, sizeof(char));
    }
    return res;
}
int input_int (int *num) {
    int a = 0;
    do {
        a = scanf ("%d", num);
        if (a < 0) {
            return 0;
        }
        
        if (a == 0) {
            scanf("%*c");
        }
    } while (a == 0);
    return 1;
}
