//
// Created by chris on 2023/8/10.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "include/log.h"


void info(char *info);

//ȫ��δ��ʼ����
char *memory;
long long memory_size;
long long one = 1;

bool use_memory = false;
int rand_use_seconds = 0;
int rand_release_seconds = 0;
FILE *fp;

void main() {
    // ������־����
    log_set_level(0);
    log_set_quiet(0);

    while (1) {
        char use_memory_str[4] = {0};
        //value: Ҫת����������string: ת������ַ���,radix: ת������������2,8,10,16 ���Ƶȡ�
        itoa(use_memory, use_memory_str, 10);
        info("USE_MEMORY");
        info(use_memory_str);

        if (use_memory) {
            info("use memory");

            // 1 << 29 = 512 MB
            memory_size = (one << 29) * 8;

            // ռ���ڴ�
            // ����ռ�
            memory = (char *) malloc(memory_size);

            info("occupy");
            // ���ڴ�ռ����������
            memset(memory, 0xFF, memory_size);

            // ��ȡ�������10 ~ 20
            rand_use_seconds = rand() % 11 + 10;
            char rand_release_str[4] = {0};
            //value: Ҫת����������string: ת������ַ���,radix: ת������������2,8,10,16 ���Ƶȡ�
            itoa(rand_use_seconds, rand_release_str, 10);
            info("rand_sleep");
            info(rand_release_str);

            sleep(rand_use_seconds);
            use_memory = false;
        } else {
            // �ͷ��ڴ�
            info("release memory");
            // �ͷ��ڴ�
            free(memory);

            // ��ȡ�������10 ~ 20
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
    // ��ӡռ�õ��ڴ�ռ�
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