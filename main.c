//
// Created by chris on 2023/8/10.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//ȫ��δ��ʼ����
char *p1;

int USE_MEMORY = 0;
int rand_sleep = 0;
int rand_use_memory = 0;

// TODO ռ��1G�ڴ�
void main() {
//    printf("%d\n", (1 << 30));
//    printf("char: %d\n", sizeof(char));
//    printf("int: %d\n", sizeof(int));

    // ���� m ~ n �������
    // int rand_number = rand() % (n - m + 1) + m;
    /*while (1) {
        // ���� 90 ~ 100 ������������� 90 �� 100
        int rand_number = rand() % 11 + 90;
        printf("random number: %d\n", rand_number);
        sleep(1);
    }*/

    // TODO
    // ��ӡռ�õ��ڴ�ռ�
    // https://blog.csdn.net/qq_20386411/article/details/89072507
    // https://blog.csdn.net/m0_61025131/article/details/119987809
    // https://blog.csdn.net/qq_45656248/article/details/116395312

    while (1) {
        printf("USE_MEMORY: %d\n", USE_MEMORY);
        if (USE_MEMORY) {
            printf("use memory\n");

            // ռ���ڴ�
            // ����ռ�
            p1 = (char *) malloc(1 << 30);
            // ���ڴ�ռ����������
            memset(p1, 0xFF, 1 << 30);
            printf("memset\n");

            // ��ȡ�������20 ~ 30
            rand_sleep = rand() % 11 + 20;
            printf("rand_sleep: %d\n", rand_sleep);

            sleep(rand_sleep);
        } else {
            // �ͷ��ڴ�
            printf("release memory\n");
            // �ͷ��ڴ�
            free(p1);

            // ��ȡ�������20 ~ 30
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