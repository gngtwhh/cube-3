//
// Created by WAHAHA on 2023/9/8.
//
#include <stdio.h>
#include <string.h>
#include "cube_3.h"

// Check whether the cube is restored
int cube_isorigin(cube c) {
    // 创建一个还原好的魔方
    cube cube_origin;
    cube_init(cube_origin);
    int flag;
    // 直接逐字节进行比较
    flag = memcmp(c, cube_origin, sizeof(cube));
    return !flag;
}

// initialize the Rubik's cube
void cube_init(cube c) {
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                c[i][j][k] = i;
            }
        }
    }
}

// scramble the Rubik's cube
void cube_scramble(cube c, formula f) {
    int i = 0;
    while (f[i] != END) {
        cube_rotating(c, f[i]);
        ++i;
    }
}

// rotary operations
// rotating Rubik's cube
void cube_rotating(cube c, enum rotary rot) {
    int focus_face = (rot - (rot % 4)) / 4 + 1; //旋转的焦点面
    switch (rot % 4) {
        case 0:
            clockwise_90(c, focus_face);
            break;
        case 1:
            anticlockwise_90(c, focus_face);
            break;
        case 2://向下"跟随"(?)
        case 3:
            rotate_180(c, focus_face);
            break;
    }
}

// clockwise rotate 90
void clockwise_90(cube c, int focus_face) {
    /*
        {3, 5, 4, 6},
        {3, 6, 4, 5},
        {1, 6, 2, 5},
        {1, 5, 2, 6},
        {1, 3, 2, 4},
        {1, 4, 2, 3}
     */
    int temp[3];

    //旋转焦点面侧棱
    switch (focus_face) {
        case 1: {
            //backup 3
            temp[0] = c[3][1][1];
            temp[1] = c[3][1][2];
            temp[2] = c[3][1][3];
            //6->3
            c[3][1][1] = c[6][1][1];
            c[3][1][2] = c[6][1][2];
            c[3][1][3] = c[6][1][3];
            //4->6
            c[6][1][1] = c[4][1][1];
            c[6][1][2] = c[4][1][2];
            c[6][1][3] = c[4][1][3];
            //5->4
            c[4][1][1] = c[5][1][1];
            c[4][1][2] = c[5][1][2];
            c[4][1][3] = c[5][1][3];
            //temp(3)->5
            c[5][1][1] = temp[0];
            c[5][1][2] = temp[1];
            c[5][1][3] = temp[2];
        }
            break;
        case 2: {
            //backup 3
            temp[0] = c[3][3][1];
            temp[1] = c[3][3][2];
            temp[2] = c[3][3][3];
            //5->3
            c[3][3][1] = c[5][3][1];
            c[3][3][2] = c[5][3][2];
            c[3][3][3] = c[5][3][3];
            //4->5
            c[5][3][1] = c[4][3][1];
            c[5][3][2] = c[4][3][2];
            c[5][3][3] = c[4][3][3];
            //6->4
            c[4][3][1] = c[6][3][1];
            c[4][3][2] = c[6][3][2];
            c[4][3][3] = c[6][3][3];
            //temp(3)->6
            c[6][3][1] = temp[0];
            c[6][3][2] = temp[1];
            c[6][3][3] = temp[2];
        }
            break;
        case 3: {
            //backup 1
            temp[0] = c[1][3][3];
            temp[1] = c[1][3][2];
            temp[2] = c[1][3][1];
            //5->1
            c[1][3][3] = c[5][1][3];
            c[1][3][2] = c[5][2][3];
            c[1][3][1] = c[5][3][3];
            //2->5
            c[5][1][3] = c[2][1][1];
            c[5][2][3] = c[2][1][2];
            c[5][3][3] = c[2][1][3];
            //6->2
            c[2][1][1] = c[6][3][1];
            c[2][1][2] = c[6][2][1];
            c[2][1][3] = c[6][1][1];
            //temp(1)->6
            c[6][3][1] = temp[0];
            c[6][2][1] = temp[1];
            c[6][1][1] = temp[2];
        }
            break;
        case 4: {
            //backup 1
            temp[0] = c[1][1][1];
            temp[1] = c[1][1][2];
            temp[2] = c[1][1][3];
            //6->1
            c[1][1][1] = c[6][1][3];
            c[1][1][2] = c[6][2][3];
            c[1][1][3] = c[6][3][3];
            //2->6
            c[6][1][3] = c[2][3][3];
            c[6][2][3] = c[2][3][2];
            c[6][3][3] = c[2][3][1];
            //5->2
            c[2][3][3] = c[5][3][1];
            c[2][3][2] = c[5][2][1];
            c[2][3][1] = c[5][1][1];
            //temp(1)->5
            c[5][3][1] = temp[0];
            c[5][2][1] = temp[1];
            c[5][1][1] = temp[2];
        }
            break;
        case 5: {
            //backup 1
            temp[0] = c[1][3][1];
            temp[1] = c[1][2][1];
            temp[2] = c[1][1][1];
            //4->1
            c[1][3][1] = c[4][1][3];
            c[1][2][1] = c[4][2][3];
            c[1][1][1] = c[4][3][3];
            //2->4
            c[4][1][3] = c[2][3][1];
            c[4][2][3] = c[2][2][1];
            c[4][3][3] = c[2][1][1];
            //3->2
            c[2][3][1] = c[3][3][1];
            c[2][2][1] = c[3][2][1];
            c[2][1][1] = c[3][1][1];
            //temp(1)->3
            c[3][3][1] = temp[0];
            c[3][2][1] = temp[1];
            c[3][1][1] = temp[2];
        }
            break;
        case 6: {
            //backup 1
            temp[0] = c[1][1][3];
            temp[1] = c[1][2][3];
            temp[2] = c[1][3][3];
            //3->1
            c[1][1][3] = c[3][1][3];
            c[1][2][3] = c[3][2][3];
            c[1][3][3] = c[3][3][3];
            //2->3
            c[3][1][3] = c[2][1][3];
            c[3][2][3] = c[2][2][3];
            c[3][3][3] = c[2][3][3];
            //4->2
            c[2][1][3] = c[4][3][1];
            c[2][2][3] = c[4][2][1];
            c[2][3][3] = c[4][1][1];
            //temp(1)->4
            c[4][3][1] = temp[0];
            c[4][2][1] = temp[1];
            c[4][1][1] = temp[2];
        }
            break;
    }

    //旋转焦点面矩阵
    for (int j = 0; j < 3; ++j)
        focus_face_anticlockwise_90(c, focus_face);
}

// anticlockwise rotate 90
void anticlockwise_90(cube c, int focus_face) {
    //待优化
    for (int i = 0; i < 3; ++i) {
        clockwise_90(c, focus_face);
    }
}

// rotate 180
void rotate_180(cube c, int focus_face) {
    //待优化
    for (int i = 0; i < 2; ++i) {
        clockwise_90(c, focus_face);
    }
}

// The square matrix rotates clockwise
void focus_face_anticlockwise_90(cube c, int focus_face) {
    int i, j, temp[3][3];
    for (i = 0; i < 3; ++i)
        for (j = 0; j < 3; ++j)
            temp[3 - j - 1][i] = c[focus_face][i + 1][j + 1];
    for (i = 0; i < 3; ++i)
        for (j = 0; j < 3; ++j)
            c[focus_face][i + 1][j + 1] = temp[i][j];
}

// External interface of the automatic restore function
void cube_auto_restore(cube c, formula restore) {
    ;
}

// enter a formula and return a formula object
void formula_input(formula f) {
    //不使用字符数组对应是要方便程序找到公式,下标转换的逻辑有点乱
    //宁可代码乱点也要逻辑清晰
    memset(f, 0, sizeof(formula));
    printf("Enter a formula and separate each step with a space\n");
    printf("Tip: The format of the operation is like R2 R2' R\n");
    printf("['] represents a counterclockwise rotation\n>>> ");
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
    f[idx] = END;
}

void formula_output(formula f) {
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

// get scramble formula by id
void formula_get_by_id(formula f, int id) {
    formula temp[4] = {
            {23, 3,  4,  8,  18, 9,  12, 18, 13, 7,  20, 11, 13, 22, 14, 6,  8,  18, 4,  14, 24},
            {6,  22, 7,  13, 1,  4,  2,  8,  22, 19, 6,  10, 19, 21, 19, 7,  17, 8,  7,  12, 24},
            {5,  15, 19, 2,  5,  17, 12, 9,  7,  12, 18, 5,  12, 3,  11, 14, 5,  18, 6,  22, 24},
            {20, 12, 7,  21, 14, 23, 19, 13, 3,  18, 7,  3,  22, 0,  8,  1,  18, 7,  18, 11, 24},
    };
    int idx = 0;
    while (temp[id - 1][idx] != END) {
        f[idx] = temp[id - 1][idx];
        idx++;
    }
    f[idx] = END;
}

// count step of a formula
int formula_count(formula f) {
    int idx = 0;
    int cnt = 0;
    while (f[idx++] != END)
        ++cnt;
    return cnt;
}

// reverse a formula
void formula_reverse(formula f_origin, formula f_reversed) {
    int idx_ogn = 0, idx_rev = 0;
    int temp_rot;
    while (f_origin[idx_ogn++] != END);
    idx_ogn -= 2;
    /*
     enum rotary {
        U, U_, U2, U2_,
        D, D_, D2, D2_,
        F, F_, F2, F2_,
        B, B_, B2, B2_,
        L, L_, L2, L2_,
        R, R_, R2, R2_,
        END
    };
     */
    while (idx_ogn >= 0) {
        temp_rot = f_origin[idx_ogn--];
        if (temp_rot % 4 == 0 || temp_rot % 4 == 2) {
            // 顺时针
            f_reversed[idx_rev++] = temp_rot + 1;
        } else {
            // 逆时针
            f_reversed[idx_rev++] = temp_rot - 1;
        }
    }
    f_reversed[idx_rev] = END;
}

// compare two formula
int formula_cmp(formula f_a, formula f_b) {
    int idx1 = 0, idx2 = 0;
    while (f_a[idx1] != END && f_b[idx2] != END) {
        if (f_a[idx1] != f_b[idx2])
            return 1;
        idx1++;
        idx2++;
    }
    if (f_a[idx1] != END || f_b[idx2] != END)
        return 1;
    return 0;
}



//print the cube as 3D img
void cube_print(cube c) {
    printf("                            ________________\n"
           "                            |  %d |  %d |  %d |\n"
           "                            +----+----+----+\n"
           "                            |  %d |  %d |  %d |\n"
           "                            +----+----+----+\n"
           "                            |  %d |  %d |  %d |\n"
           "                            +----+----+----+\n"
           "                           /  %d / %d  / %d  /|\n"
           "                          /____/____/____/ |\n"
           "                         /  %d /  %d /  %d /|%d+ \n"
           "                        /____/____/____/ |/|\n"
           "                       /  %d /  %d /  %d /|%d|%d|\n"
           "        ______________/____/____/____/%d|/|/|\n"
           "        | %d |  %d |  %d |  %d |  %d |  %d |/|%d+%d|\n"
           "        +---+----+----+----+----+----+%d|/|/\n"
           "        | %d |  %d |  %d |  %d |  %d |  %d |/|%d+\n"
           "        +---+----+----+----+----+----+%d|/\n"
           "        | %d |  %d |  %d |  %d |  %d |  %d |/\n"
           "        +---+----+----+----+----+----+\n"
           "                      |  %d |  %d |  %d |\n"
           "                      +----+----+----+\n"
           "                      |  %d |  %d |  %d |\n"
           "                      +----+----+----+\n"
           "                      |  %d |  %d |  %d |\n"
           "                      +----+----+----+\n",
           c[4][3][3], c[4][3][2], c[4][3][1],
           c[4][2][3], c[4][2][2], c[4][2][1],
           c[4][1][3], c[4][1][2], c[4][1][1],

           c[1][1][1], c[1][1][2], c[1][1][3],
           c[1][2][1], c[1][2][2], c[1][2][3],
           c[6][1][3],

           c[1][3][1], c[1][3][2], c[1][3][3],
           c[6][1][2], c[6][2][3], c[6][1][1],

           c[5][1][1], c[5][1][2], c[5][1][3], c[3][1][1], c[3][1][2], c[3][1][3],
           c[6][2][2], c[6][3][3], c[6][2][1],
           c[5][2][1], c[5][2][2], c[5][2][3], c[3][2][1], c[3][2][2], c[3][2][3],
           c[6][3][2], c[6][3][1],
           c[5][3][1], c[5][3][2], c[5][3][3], c[3][3][1], c[3][3][2], c[3][3][3],

           c[2][1][1], c[2][1][2], c[2][1][3],
           c[2][2][1], c[2][2][2], c[2][2][3],
           c[2][3][1], c[2][3][2], c[2][3][3]
    );
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