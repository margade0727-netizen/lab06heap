#include "DS.h"
#include <stdio.h>

Heap hp;

int main()
{
        int n, i;
        scanf("%d", &n);
        char cmd[5];
        Msg x;

        for (i = 0; i < n; i++) {
                scanf("%s", cmd);
                if (strcmp(cmd, "PUT") == 0) {
                        scanf("%s%d", x.text, &x.priority);
                        x.time = i;
                        insert(&hp, x);
                } else if (strcmp(cmd, "GET") == 0) {
                        x = delMin(&hp);
                        printf("%s\n", x.text);
                }
        }
        
        return 0;
}
