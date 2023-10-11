//
// Created by WAHAHA on 2023/9/8.
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
#define MAX_FORMULA_LEN 40
typedef enum rotary formula[MAX_FORMULA_LEN];

// logical judgment
int cube_isorigin(cube c); // Check whether the cube is restored

// initialization and result processing
void cube_init(cube c); // initialize the Rubik's cube
void cube_scramble(cube c, formula f); // scramble the Rubik's cube

// rotary operations
void cube_rotating(cube c,enum rotary rot); // rotating Rubik's cube
void clockwise_90(cube c,int focus_face); // clockwise rotate 90
void anticlockwise_90(cube c,int focus_face); // anticlockwise rotate 90
void rotate_180(cube c,int focus_face); // rotate 180
void focus_face_anticlockwise_90(cube c,int focus_face); // The square matrix rotates anticlockwise

// formula operations
void formula_input(formula f); // enter a formula and return a formula object
void formula_get_by_id(formula f,int id); // get scramble formula by id
int formula_count(formula f); // count step of a formula
int formula_cmp(formula f_a, formula f_b); // compare two formula
void formula_reverse(formula f_origin, formula f_reversed); // reverse a formula

// cube I/O functions
void cube_print(cube c); // print the cube as 3D img

// internal auxiliary function
int isface(char c); // determines whether the input character is the correct face

#endif //CUBE_3_CUBE_3_H
