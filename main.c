//
// Created by chris on 2023/8/10.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//全局未初始化区
char *p1;

// TODO 占用1G内存
int main() {
    printf("%d\n", (1 << 30));
    printf("char: %d\n", sizeof(char));
    printf("int: %d\n", sizeof(int));
    p1 = (char *) malloc(1 << 30);

    printf("memset\n");

    // 向内存空间内填充数据
    memset(p1, 0xFF, 1 << 30);
    sleep(30);

    // TODO
    // 打印占用的内存空间
    // https://blog.csdn.net/qq_20386411/article/details/89072507
    // https://blog.csdn.net/m0_61025131/article/details/119987809
    // https://blog.csdn.net/qq_45656248/article/details/116395312

    printf("free\n");
    // 释放内存
    free(p1);
    sleep(30);
    return 0;
}

/*#include <stdio.h>
#include <stdlib.h>

void main() {
    int *a;
    while (1) {
        a = (int *) malloc(1000 * sizeof(int));
    }
}*/