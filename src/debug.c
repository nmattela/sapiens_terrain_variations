#include "debug.h"
#include <stdio.h>

void mjLog(char message[100]) {
    FILE* fp = fopen("/home/nmattela/Documents/sapiens_terrain_variations/c_log.txt", "w");

    if(fp == NULL) {
        printf("file couldn't be opened\n");
        return;
    }

    fputs(message, fp);

    fclose(fp);

}

void mjLogInt(int number) {
    // FILE* fp = fopen("/home/nmattela/Documents/sapiens_terrain_variations/c_log.txt", "w");

    // if(fp == NULL) {
    //     printf("file couldn't be opened\n");
    //     return;
    // }

    // char str[1024];
    // sprintf(str, "%d\n", number);
    // fputs(str, fp);

    // fclose(fp);
}