#include <stdio.h>

// 练习1：实现 my_strlen
int my_strlen(char *str) {
    int count = 0;
    while (*str != '\0') {
        count++;
        str++;
    }
    return count; // 【必须改】之前你写的是 return 0; 会导致结果永远是0
}

// 练习2：实现 my_strcat
void my_strcat(char *str_1, char *str_2) {
    // 1. 找到 str_1 的末尾
    while (*str_1 != '\0') {
        str_1++;
    }
    // 2. 逐个拷贝字符
    while (*str_2 != '\0') {
        *str_1 = *str_2;
        str_1++;
        str_2++;
    }
    // 3. 加上结束符
    *str_1 = '\0';
}

// 练习3：实现 my_strstr
char* my_strstr(char *s, char *p) {
    if (*p == '\0') return s; // 如果要查的空字符串，直接返回 s

    while (*s != '\0') {
        char *s_curr = s;
        char *p_curr = p;

        // 逐个字符匹配
        while (*p_curr != '\0' && *s_curr == *p_curr) {
            s_curr++;
            p_curr++;
        }

        // 如果 p 匹配到末尾，说明找到了
        if (*p_curr == '\0') {
            return s;
        }
        s++;
    }
    return NULL; // 找不到返回空指针
}

// ================= 测试代码 =================
// 之前的报错是因为缺少 main 函数，现在加上它
int main() {
    // 1. 测试 my_strlen
    char str_len[] = "hello";
    int len = my_strlen(str_len);
    printf("测试 my_strlen: 长度是 %d (应该是 5)\n", len);

    // 2. 测试 my_strcat
    // 【注意】必须用字符数组！不能用 char *str1 = "hello"; 否则会报之前的只读错误
    char str1[50] = "hello"; 
    char str2[] = "world";
    my_strcat(str1, str2);
    printf("测试 my_strcat: 拼接结果是 %s (应该是 helloworld)\n", str1);

    // 3. 测试 my_strstr
    char s[] = "123456";
    char p[] = "34";
    char *result = my_strstr(s, p);
    if (result != NULL) {
        printf("测试 my_strstr: 找到了！从 '%s' 开始\n", result); // 应该输出 3456
    } else {
        printf("测试 my_strstr: 没找到\n");
    }

    return 0;
}
