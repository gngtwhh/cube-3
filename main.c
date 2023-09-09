#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "cube_3.h"
#include "menu.h"

int main() {
    cube cube1;
    cube_init(cube1);
    formula f_scramble, rotate, restore;

    while (1) {
        print_menu();
        char c = getchar();
        getchar(); // 吸收回车
        if (c == '1') {
            // 指定公式打乱
            printf("please enter the scramble formula:\n>>> ");
            formular_input(f_scramble);
            if (f_scramble[0] == END) {
                printf("error: scramble formula is empty!");
                continue;
            }
            cube_scramble(cube1, f_scramble);
            cube_print(cube1);
            while (!cube_isorigin(cube1)) {
                int idx = 0;
                formular_input(rotate);
                while (f_scramble[idx] != END) {
                    cube_rotating(cube1, f_scramble[idx]);
                    ++idx;
                }
                cube_print(cube1);
            }
            printf("Restore successfully!!!\n");
        } else if (c == '2') {
            // 随机打乱
            formula_get_rand(f_scramble);
            formular_output(f_scramble);
            cube_scramble(cube1, f_scramble);
            cube_print(cube1);
            while (!cube_isorigin(cube1)) {
                int idx = 0;
                formular_input(rotate);
                while (rotate[idx] != END) {
                    cube_rotating(cube1, rotate[idx]);

                    ++idx;
                }
                cube_print(cube1);
            }
            printf("Restore successfully!!!\n");
        } else if (c == '3') {
            //自动还原
            printf("please enter the scramble formula:\n>>> ");
            formular_input(f_scramble);
            if (f_scramble[0] == END) {
                printf("error: scramble formula is empty!");
                continue;
            }
            cube_scramble(cube1, f_scramble);
            printf("restoring...");
            cube_auto_restore(cube1, restore);
            formular_output(restore);
        } else if (c == '4') {
            break;
        } else {
            printf("error!");
            Sleep(1000);
            system("cls");
        }
    }
    system("pause");
    return 0;
}
