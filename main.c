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

bool USE_MEMORY = false;
int rand_sleep = 0;
int rand_use = 0;
FILE *fp;

void main() {
    // ������־����
    log_set_level(0);
    log_set_quiet(0);

    while (1) {
        info("USE_MEMORY");
        info((char *) USE_MEMORY);
        if (USE_MEMORY) {
            info("use memory");

            // ռ���ڴ�
            // ����ռ�
            memory = (char *) malloc(1 << 30);

            info("occupy");
            // ���ڴ�ռ����������
            memset(memory, 0xFF, 1 << 30);

            // ��ȡ�������10 ~ 30
            rand_sleep = rand() % 11 + 10;
            char rand_sleep_str[4] = {0};
            //value: Ҫת����������string: ת������ַ���,radix: ת������������2,8,10,16 ���Ƶȡ�
            itoa(rand_sleep, rand_sleep_str, 10);
            info("rand_sleep");
            info(rand_sleep_str);

            sleep(rand_sleep);
            USE_MEMORY = false;
        } else {
            // �ͷ��ڴ�
            info("release memory");
            // �ͷ��ڴ�
            free(memory);

            // ��ȡ�������20 ~ 30
            rand_use = rand() % 11 + 20;
            char rand_use_str[4] = {0};
            itoa(rand_use, rand_use_str, 10);
            info("rand_use");
            info(rand_use_str);

            sleep(rand_use);
            USE_MEMORY = true;
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