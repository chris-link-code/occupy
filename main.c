//
// Created by chris on 2023/8/10.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *memory;
long long memory_size;

int use_memory = 1;
int rand_release_seconds = 0;
int rand_use_seconds = 0;
int rand_memory = 0;
long long one = 1;

void main() {
    while (1) {
        printf("USE_MEMORY: %d\n", use_memory);

        if (use_memory) {
            // 获取随机数，3 ~ 8
            rand_memory = rand() % 6 + 3;
//            rand_memory = 8;
            printf("rand_memory: %d\n", rand_memory);

            // 1 << 29 = 512 MB
            memory_size = (one << 29) * rand_memory;

            // 分配空间
            memory = (char *) malloc(memory_size);

            // 向内存空间内填充数据
            memset(memory, 0xFF, memory_size);

            // 获取随机数，5 ~ 15
            rand_use_seconds = rand() % 11 + 5;
            printf("rand_use_seconds: %d\n", rand_use_seconds);

            sleep(rand_use_seconds * 60);
//            sleep(rand_use_seconds);
            use_memory = 0;
        } else {
            printf("release memory");

            // 释放内存
            free(memory);

            // 获取随机数，1 ~ 4
            rand_release_seconds = rand() % 4 + 1;

            printf("rand_release_seconds: %d\n", rand_release_seconds);

            sleep(rand_release_seconds * 3600);
//            sleep(rand_release_seconds);
            use_memory = 1;
        }
    }
}