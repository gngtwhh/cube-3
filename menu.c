#include <stdio.h>
#include "menu.h"

void print_menu() {
    int select_len;
    printf("                           ����ħ��\n");
    const char *select[10] = {
            "        _______________________________________________\n",
            "        |                                             |\n",
            "        |        ��������:                          |\n",
            "        |       1.�Զ�����     2.�������             |\n",
            "        |       3.�Զ���ԭ     4.��ʽȡ��             |\n",
            "        |       5.�˳�����                            |\n",
            "        |                                             |\n",
            "        |                                             |\n",
            "        -----------------------------------------------\n",
            "                    ��������[1/2]:"
    };
    select_len=sizeof(select)/sizeof(select[0]);
    for (int i = 0; i < select_len; ++i) {//��ӡ�˵�
        printf("%s", select[i]);
    }
}