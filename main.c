//
// Created by chris on 2023/8/10.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//全局未初始化区
char *p1;

int USE_MEMORY = 0;
int rand_sleep = 0;
int rand_use_memory = 0;

// TODO 占用1G内存
void main() {
//    printf("%d\n", (1 << 30));
//    printf("char: %d\n", sizeof(char));
//    printf("int: %d\n", sizeof(int));

    // 生成 m ~ n 的随机数
    // int rand_number = rand() % (n - m + 1) + m;
    /*while (1) {
        // 生成 90 ~ 100 的随机数，包含 90 和 100
        int rand_number = rand() % 11 + 90;
        printf("random number: %d\n", rand_number);
        sleep(1);
    }*/

    // TODO
    // 打印占用的内存空间
    // https://blog.csdn.net/qq_20386411/article/details/89072507
    // https://blog.csdn.net/m0_61025131/article/details/119987809
    // https://blog.csdn.net/qq_45656248/article/details/116395312

    while (1) {
        printf("USE_MEMORY: %d\n", USE_MEMORY);
        if (USE_MEMORY) {
            printf("use memory\n");

            // 占用内存
            // 分配空间
            p1 = (char *) malloc(1 << 30);
            // 向内存空间内填充数据
            memset(p1, 0xFF, 1 << 30);
            printf("memset\n");

            // 获取随机数，20 ~ 30
            rand_sleep = rand() % 11 + 20;
            printf("rand_sleep: %d\n", rand_sleep);

            sleep(rand_sleep);
        } else {
            // 释放内存
            printf("release memory\n");
            // 释放内存
            free(p1);

            // 获取随机数，20 ~ 30
            rand_use_memory = rand() % 11 + 20;
            printf("rand_use_memory: %d\n", rand_use_memory);
            sleep(rand_use_memory);
        }
    }
}

/*#include <stdio.h>
#include <stdlib.h>

void main() {
    int *a;
    while (1) {
        a = (int *) malloc(1000 * sizeof(int));
    }
}*/