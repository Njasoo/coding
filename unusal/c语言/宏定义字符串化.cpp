#include <stdio.h>
#include <string.h>

#define STRCPY(a, b) strcpy(a##_p, #b) // # 字符串化见后面的字变成字符串, #b就是变量b的名称
// ## 拼接字符串, a = var1, -> var1_p

int main() {
    char var1_p[20];
    char var2_p[20];
    strcpy(var1_p, "aaaa");
    strcpy(var2_p, "bbbb");
    STRCPY(var1, var2);
    printf("%s\n", var1_p);
    STRCPY(var2, var1);
    printf("%s\n", var2_p);
    return 0;
}