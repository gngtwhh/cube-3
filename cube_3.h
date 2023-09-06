//
// Contains declarations of related data types and
// computation functions for the Rubik's cube
//

#ifndef CUBE_3_CUBE_3_H
#define CUBE_3_CUBE_3_H

// cube data structure
typedef int cube[7][4][4]; // cube is specified as int [7][4][4]

// rotary operations
// 这里不使用字符数组对应是要方便程序找到公式,下标转换的逻辑有点乱
enum rotary {
    U, U_, U2, U2_,
    D, D_, D2, D2_,
    F, F_, F2, F2_,
    B, B_, B2, B2_,
    L, L_, L2, L2_,
    R, R_, R2, R2_,
    END
};

// formula data structure
#define MAX_FORMULA_LEN 20
typedef enum rotary formula[MAX_FORMULA_LEN];

// initialization and result processing
void cube_init(cube c); // initialize the Rubik's cube
void cube_scramble(cube *c, formula *f); // scramble the Rubik's cube

// rotary operations
void cube_rotating(cube c,enum rotary rot); // rotating Rubik's cube

// formula operations
void formular_input(formula f); // enter a formula and return a formula object
void formular_output(formula f); // output a formula

// internal auxiliary function
int isface(char c); // determines whether the input character is the correct face
void trans_init(int* trans[4][3],cube c,enum rotary rot); // init rotating trans array
void face_init(int (*face)[3][3], cube c,enum rotary rot); //init rotating face
#endif //CUBE_3_CUBE_3_H
