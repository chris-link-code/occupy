//
// Created by chris on 2023/8/10.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "include/log.h"


void info(char *info);

//全局未初始化区
char *memory;
long long memory_size;
long long one = 1;

bool use_memory = false;
int rand_use_seconds = 0;
int rand_release_seconds = 0;
FILE *fp;

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

            // 1 << 29 = 512 MB
            memory_size = (one << 29) * 8;

            // 占用内存
            // 分配空间
            memory = (char *) malloc(memory_size);

            info("occupy");
            // 向内存空间内填充数据
            memset(memory, 0xFF, memory_size);

            // 获取随机数，10 ~ 20
            rand_use_seconds = rand() % 11 + 10;
            char rand_release_str[4] = {0};
            //value: 要转换的整数，string: 转换后的字符串,radix: 转换进制数，如2,8,10,16 进制等。
            itoa(rand_use_seconds, rand_release_str, 10);
            info("rand_sleep");
            info(rand_release_str);

            sleep(rand_use_seconds);
            use_memory = false;
        } else {
            // 释放内存
            info("release memory");
            // 释放内存
            free(memory);

            // 获取随机数，10 ~ 20
            rand_release_seconds = rand() % 11 + 10;
            char rand_release_str[4] = {0};
            itoa(rand_release_seconds, rand_release_str, 10);
            info("rand_release");
            info(rand_release_str);

            sleep(rand_release_seconds);
            use_memory = true;
        }
    }



    // TODO
    // 打印占用的内存空间
    // https://blog.csdn.net/qq_20386411/article/details/89072507
    // https://blog.csdn.net/m0_61025131/article/details/119987809
    // https://blog.csdn.net/qq_45656248/article/details/116395312
}

void info(char *info) {
    fp = fopen("./info.log", "ab");
    if (fp != NULL) {
        log_add_fp(fp, LOG_INFO);
        log_info(info);
        fclose(fp);
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