/*
 * 打印菱形 
 * 
 * 
 * 
 * 
 *
 * 
 */

#include <stdio.h>

// 打印上半部分的三角形 
void printTopPart(int n) {
    for (int i = 1; i <= n; i++) {
        // 打印空格
        for (int j = 1; j <= n - i; ++j) {
            printf(" ");
        }

        // 打印递增数字
        for (int j = 1; j <= i; j++) {
            printf("%d", j);
        }

        // 打印递减数字
        for (int j = i - 1; j >= 1; j--) {
            printf("%d", j);
        }
        printf("\n");
    }
}

// 打印下半部分的三角形 
void printBottomPart(int n) {
    for (int i = n - 1; i >= 1; i--) {
        // 打印空格
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }

        // 打印递增数字
        for (int j = 1; j <= i; j++) {
            printf("%d", j);
        }

        // 打印递减数字
        for (int j = i - 1; j >= 1; j--) {
            printf("%d", j);
        }
        printf("\n");
    }
}

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        if (n < 1 || n > 9) {
            printf("n 值不合法\n");
        }
        printTopPart(n);
        printBottomPart(n);
    }
    return 0;
}
