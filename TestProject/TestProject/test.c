#include <stdio.h>

void spira(int n);

int main(void)
{
    spira(4);
    return 0;
}

void spira(int n)
{
    for (int i = n;i > 0;i--) {
        for (int j = 0;j < n + 1;j++) {
            if (i > j) {
                printf(" ");
            }
            else {
                printf("*");
            }
        }
        for (int k = i ;k > 1 ;k--) {
            printf("!");
        }
        printf("\n");
    }
}