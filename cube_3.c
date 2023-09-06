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

// rotary operations
// rotating Rubik's cube
void cube_rotating(cube c, enum rotary rot) {
    int lump_temp[3] = {0};
    int *trans[4][3]; // rotation transform queue
    int (*face)[3][3]; // face rotate
    trans_init(trans, c, rot); // init trans
    face_init(face, c, rot); //init face
    switch (rot % 4) {
        case 0:
            clockwise_90(trans, face);
            break;
        case 1:
            anticlockwise_90(trans, face);
            break;
        case 2://向下"跟随"(?)
        case 3:
            rotate_180(trans, face);
            break;
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
            } else if (c == '\'') {
                //逆时针90度
                f[idx++] = (face - 1) * 4 + 1;
            } else if (c == '2') {
                //确定为180度,继续判断顺逆---此时实际顺逆都可,
                //单纯的为了进行兼容公式和代码逻辑
                char c2 = getchar();
                if (c2 == ' ') {
                    //顺时针180度
                    f[idx++] = (face - 1) * 4 + 2;
                } else if (c2 == '\'') {
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
            "U", "U'", "U2", "U2'",
            "D", "D'", "D2", "D2'",
            "F", "F'", "F2", "F2'",
            "B", "B'", "B2", "B2'",
            "L", "L'", "L2", "L2'",
            "R", "R'", "R2", "R2'",
    };
    int idx = 0;
    enum rotary r = f[idx++];
    while (r != END) {
        printf("%s ", rotary_str[r]);
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

// init trans array
void trans_init(int *trans[4][3], cube c, enum rotary rot) {
    //面编号:U 1,D 2,F 3,B 4,L 5,R 6
    //对应到数组下标时减一
    int focus_face=(rot-(rot%4))/4+1; //旋转的焦点面
    //焦点面相邻的4个面---优先从U和F开始,顺时针遍历
    int adjacent_face[6][4]={
            {3,5,4,6},
            {3,6,4,5},
            {1,6,2,5},
            {1,5,2,6},
            {1,3,2,4},
            {1,4,2,3}
    };
    //相邻面需要变换的色块编号---[0]存所在行,[1-3]存所在列
    int trans_list[6][4][4]={
            {
                    {3,3,2,1},
                    {1,1,2,3},
                    {1,1,2,3},
                    {1,1,2,3},
                },
            {
                    {3,3,2,1},
                    {3,3,2,1},
                    {3,3,2,1},
                    {3,3,2,1}
                },
            {
                    {3,},
                    {},
                    {},
                    {}
                },
            {
                    {},
                    {},
                    {},
                    {}
                },
            {
                    {},
                    {},
                    {},
                    {}
                },
            {
                    {},
                    {},
                    {},
                    {}
                }
    };

}