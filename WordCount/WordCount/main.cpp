#define _CRT_SECURE_NO_WARNINGS  // 加上这一行，解决fopen安全警告
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 统计字符数
int count_characters(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("错误：无法打开文件 %s\n", filename);
        return -1;
    }

    int count = 0;
    char ch;
    while ((ch = fgetc(fp)) != EOF) {
        count++;
    }

    fclose(fp);
    return count;
}

// 统计单词数：空格、逗号分隔都算单词
int count_words(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("错误：无法打开文件 %s\n", filename);
        return -1;
    }

    int count = 0;
    char ch;
    int in_word = 0;

    while ((ch = fgetc(fp)) != EOF) {
        if (ch == ' ' || ch == ',') {
            in_word = 0;
        }
        else if (in_word == 0) {
            in_word = 1;
            count++;
        }
    }

    fclose(fp);
    return count;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("使用方法: WordCount [参数] 文件名\n");
        printf("  -c    统计字符数\n");
        printf("  -w    统计单词数\n");
        return 1;
    }

    if (strcmp(argv[1], "-c") == 0) {
        int n = count_characters(argv[2]);
        if (n >= 0)
            printf("字符数：%d\n", n);
    }
    else if (strcmp(argv[1], "-w") == 0) {
        int n = count_words(argv[2]);
        if (n >= 0)
            printf("单词数：%d\n", n);
    }
    else {
        printf("错误：无效参数！仅支持 -c 和 -w\n");
    }

    return 0;
}