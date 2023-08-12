//
// Created by chris on 2023/8/10.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "include/log.h"


void info(char *info);

//全局未初始化区
FILE *fp;
char *memory;
long long memory_size;

bool use_memory = false;
int rand_release_seconds = 0;
int rand_use_seconds = 0;
int rand_memory = 0;
long long one = 1;

void main() {
    // 设置日志级别
    log_set_level(0);
    log_set_quiet(0);

    while (1) {
        char use_memory_str[4] = {0};
        //value: 要转换的整数，string: 转换后的字符串,radix: 转换进制数，如2,8,10,16 进制等。
        itoa(use_memory, use_memory_str, 10);
        info("USE_MEMORY");
        info(use_memory_str);

        if (use_memory) {
            info("use memory");

            // 获取随机数，3 ~ 8
            rand_memory = rand() % 6 + 3;
            char rand_memory_str[4] = {0};
            //value: 要转换的整数，string: 转换后的字符串,radix: 转换进制数，如2,8,10,16 进制等。
            itoa(rand_memory, rand_memory_str, 10);
            info("rand_memory");
            info(rand_memory_str);

            // 1 << 29 = 512 MB
            memory_size = (one << 29) * rand_memory;

            // 分配空间
            memory = (char *) malloc(memory_size);

            // 向内存空间内填充数据
            memset(memory, 0xFF, memory_size);

            // 获取随机数，10 ~ 20
            rand_use_seconds = rand() % 11 + 5;
            char rand_use_str[4] = {0};
            itoa(rand_use_seconds, rand_use_str, 10);
            info("rand_use");
            info(rand_use_str);

            sleep(rand_use_seconds * 60);
            use_memory = false;
        } else {
            info("release memory");
            // 释放内存
            free(memory);

            // 获取随机数，1 ~ 4
            rand_release_seconds = rand() % 4 + 1;
            char rand_release_str[4] = {0};
            itoa(rand_release_seconds, rand_release_str, 10);
            info("rand_release");
            info(rand_release_str);

            sleep(rand_release_seconds * 3600);
            use_memory = true;
        }
    }
}

void info(char *info) {
    fp = fopen("./info.log", "ab");
    if (fp != NULL) {
        log_add_fp(fp, LOG_INFO);
        log_info(info);
        fclose(fp);
    }
}