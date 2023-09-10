#include <stdio.h>
#include "menu.h"

void print_menu() {
    int select_len;
    printf("                           三阶魔方\n");
    const char *select[10] = {
            "        _______________________________________________\n",
            "        |                                             |\n",
            "        |        请输入编号:                          |\n",
            "        |       1.自定打乱     2.随机打乱             |\n",
            "        |       3.自动还原     4.公式取反             |\n",
            "        |       5.退出程序                            |\n",
            "        |                                             |\n",
            "        |                                             |\n",
            "        -----------------------------------------------\n",
            "                    请输入编号[1/2]:"
    };
    select_len=sizeof(select)/sizeof(select[0]);
    for (int i = 0; i < select_len; ++i) {//打印菜单
        printf("%s", select[i]);
    }
}