#include <stdio.h>
#include "cube_3.h"

int main() {
    cube cube1;
    cube_init(cube1);
    /*for (int i = 0; i < 7; ++i) {
        for (int j = 1; j < 4; ++j) {
            for (int k = 1; k < 4; ++k) {
                printf("%d", cube1[i][j][k]);
            }
            putchar('\n');
        }
        putchar('\n');
    }*/

    formula f_scramble;
    formular_input(f_scramble);
    /*for(int i=0;i<20;++i)
        printf("%d ",f_scramble[i]);*/
    formular_output(f_scramble);
    return 0;
}
