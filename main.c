//
// Created by WAHAHA on 2023/9/8.
//
#include <stdio.h>
#include "cube_3.h"
#include "menu.h"

/*
END=24

1
R2' U2' D F L2 F' B L2 B' D2' R F2' B' R2 B2 D2 F L2 D B2
23,3,4,8,18,9,12,18,13,7,20,11,13,22,14,6,8,18,4,14
R B D' F U2 L D' R F2 L F' D' L2 F2 D2 B2 U' F2 B2 U2
20,12,5,8,2,16,5,20,10,16,9,5,18,10,6,14,1,10,14,2

reverse
B2' D' L2' F' D2' B2' R2' B F2 R' D2 B L2' B' F L2' F' D' U2 R2

2
D2 R2 D2' B' U' D U2 F R2 L2' D2 F2 L2' R' L2' D2' L' F D2' B
6,22,7,13,1,4,2,8,22,19,6,10,19,21,19,7,17,8,7,12
D2 L D R' B D' F R2 L' B' D L2 D R2 D B2 U2 B2 U' B2
6,16,4,21,12,5,8,22,17,13,4,18,4,22,4,14,2,14,1,14

reverse
B' D2 F' L D2 L2 R L2 F2' D2' L2 R2' F' U2' D' U B D2 R2' D2'

3
D' B2' L2' U2 D' L' B F' D2' B L2 D' B U2' F2' B2 D' L2 D2 R2
5,15,19,2,5,17,12,9,7,12,18,5,12,3,11,14,5,18,6,22
B L2 D' F' L B' U' D F L U L' D2 F2 U2 D' L2 F2 D B2
12,18,5,9,16,13,1,4,8,16,0,17,6,10,2,5,18,10,4,14

reverse
R2' D2' L2' D B2' F2 U2 B' D L2' B' D2 F B' L D U2' L2 B2 D

4
R B D2' R' B2 R2' L2' B' U2' L2 D2' U2' R2 U F U' L2 D2' L2 F2'
20,12,7,21,14,23,19,13,3,18,7,3,22,0,8,1,18,7,18,11
R2 B' R' B R D F U' L2 U' D L D' F2 U B2 R2 U' L2 U2
22,13,21,12,20,4,8,1,18,1,4,16,5,10,0,14,22,1,18,2

reverse
F2 L2' D2 L2' U F' U' R2' U2 D2 L2' U2 B L2 R2 B2' R D2 B' R'


 */

int main() {
    cube cube1;
    cube_init(cube1);
    formula f_scramble, rotate,f_reverse;

    print_menu();
    char c = getchar();
    getchar(); // 吸收回车
    if (c >= '1' && c <= '4') {
        formula_get_by_id(f_scramble, c - '0');
        cube_scramble(cube1, f_scramble);
        cube_print(cube1);

        int idx = 0;
        formula_input(rotate);
        while (rotate[idx] != END) {
            cube_rotating(cube1, rotate[idx]);
            ++idx;
        }
        cube_print(cube1);
        formula_reverse(rotate,f_reverse);

        if (cube_isorigin(cube1) && !formula_cmp(f_scramble,f_reverse)) {
            printf("Restore successfully!!!You reversed the formula!!!\n");
        }
        else if (cube_isorigin(cube1) && formula_cmp(f_scramble,f_reverse)) {
            printf("Restore successfully!!!But not reverse!!!\n");
        } else
            printf("Restore failed!!!\n");
    } else if (c == '5') {
        printf("bye!\n");
    } else {
        printf("error!\n");
    }

    printf("press anykey to continue...");
    getchar();
    return 0;
}
