#include <stdio.h>
#include <string.h>
#include "cube_3.h"

// initialize the Rubik's cube
void cube_init(cube c) {
    for (int i = 0; i < 7; ++i) {
//        memset(c[i],i,sizeof(c[i]));
        for (int j = 1; j < 4; ++j) {
            for (int k = 1; k < 4; ++k) {
                c[i][j][k] = i;
            }
        }
    }
}

// enter a formula and return a formula object
void formular_input(formula f) {
    //不使用字符数组对应是要方便程序找到公式,下标转换的逻辑有点乱
    //宁可代码乱点也要逻辑清晰
    memset(f, 0, sizeof(formula));
    printf("Enter a formula and separate each step with a space\n");
    printf("Tip: The format of the operation is like R2 R2_ R\n");
    printf("'_' represents a counterclockwise rotation\n>>> ");
    char c;
    int idx = 0, face;
    while ((c = getchar()) != '\n') {
        face = isface(c);
        if (face) {
            //获取到一个操作面,接下来解析具体转动方式
            c = getchar();
            if (c == ' ') {
                //顺时针90度
                f[idx++] = (face - 1) * 4 + 0;
            } else if (c == '_') {
                //逆时针90度
                f[idx++] = (face - 1) * 4 + 1;
            } else if (c == '2') {
                //确定为180度,继续判断顺逆---此时实际顺逆都可,
                //单纯的为了进行兼容公式和代码逻辑
                char c2 = getchar();
                if (c2 == ' ') {
                    //顺时针180度
                    f[idx++] = (face - 1) * 4 + 2;
                } else if (c2 == '_') {
                    //逆时针180度
                    f[idx++] = (face - 1) * 4 + 3;
                } else if (c2 == '\n') {
                    //此时因为最后仍然有一个操作没有记录,所以要多记录一次
                    f[idx++] = (face - 1) * 4 + 2;
                    f[idx++] = END;
                    return;
                }
            } else if (c == '\n') {
                //此时因为最后仍然有一个操作没有记录,所以要多记录一次
                f[idx++] = (face - 1) * 4 + 0;
                f[idx++] = END;
                return;
            }
        }
    }
}

void formular_output(formula f) {
    //因为使用了枚举进行映射,这里要使用一个对应的字符串数组来进行反映射
    const char *rotary_str[24] = {
            "U", "U_", "U2", "U2_",
            "D", "D_", "D2", "D2_",
            "F", "F_", "F2", "F2_",
            "B", "B_", "B2", "B2_",
            "L", "L_", "L2", "L2_",
            "R", "R_", "R2", "R2_",
    };
    int idx = 0;
    enum rotary r = f[idx++];
    while (r != END) {
        printf("%s ",rotary_str[r]);
        r = f[idx++];
    }
    putchar('\n');
}

// internal auxiliary function
int isface(char c) {
    switch (c) {
        case 'U':
            return 1;
        case 'D':
            return 2;
        case 'F':
            return 3;
        case 'B':
            return 4;
        case 'L':
            return 5;
        case 'R':
            return 6;
        default:
            return 0;
    }
}
