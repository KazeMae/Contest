#include <stdio.h>
#include <string.h>


int main() {
    char wu_ji[10], jia_jie[10];
    scanf("%s%s", wu_ji, jia_jie);
    
    // 平局的结果
    if(strcmp(wu_ji, jia_jie) == 0) {
        printf("Wish you AC fun!");
    // 枚举乌鸡赢
    }else if(strcmp(wu_ji, "shitou") == 0 && strcmp(jia_jie, "jiandao") == 0) {
        printf("Black chicken be!");
    }else if(strcmp(wu_ji, "jiandao") == 0 && strcmp(jia_jie, "bu") == 0) {
        printf("Black chicken be!");
    }else if(strcmp(wu_ji, "bu") == 0 && strcmp(jia_jie, "shitou") == 0) {
        printf("Black chicken be!");

    }else {
        printf("Joyous festival be!");
    }
}
