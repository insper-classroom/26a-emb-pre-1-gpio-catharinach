#include <stdio.h>

void foo(int *a) {
    *a = *a + 1; // acessa ponteiro
}

int main(void) {
    int a = 0;
    int b = 0;

    while (a <= 10) {
        foo(&a);
        printf("a = %d\n", a);

        if (a > 5) {
            b = 1;
            printf("b foi setado para: %d\n", b);
        }
    }

    return 0;
}
