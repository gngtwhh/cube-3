#include <stdio.h>
#include <stdlib.h>
#include "cube_3.h"

int main() {
    cube cube1;
    cube_init(cube1);
    formula f_scramble;
    while(1){
        formular_input(f_scramble);
        if(f_scramble[0]==END)
            break;
        int idx = 0;
        while (f_scramble[idx] != END) {
            cube_rotating(cube1, f_scramble[idx]);
            ++idx;
        }
        cube_print(cube1);
    }
    system("pause");
    return 0;
}
