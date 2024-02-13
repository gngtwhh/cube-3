//
// Contains declarations of related data types and
// computation functions for the Rubik's cube
//

#ifndef CUBE_3_CUBE_3_H
#define CUBE_3_CUBE_3_H

// cube data structure
typedef int cube[7][4][4]; // cube is specified as int [7][4][4]

// rotary operations
// ���ﲻʹ���ַ������Ӧ��Ҫ��������ҵ���ʽ,�±�ת�����߼��е���
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

// Automatically restore Rubik's cube
void cube_auto_restore(cube c,formula restore); // External interface of the automatic restore function

// formula operations
void formula_input(formula f); // enter a formula and return a formula object
void formula_output(formula f); // output a formula
void formula_reverse(formula f_origin,formula f_reversed); // reverse a formula
void formula_get_rand(formula f); // get random formula to scramble the cube

// cube I/O functions
void cube_print(cube c); // print the cube as 3D img
/*int get_color(int block); // get color by block id
void set_color(int i); // set console color
char *get_color_str(int block); //return color str*/

// internal auxiliary function
int isface(char c); // determines whether the input character is the correct face

#endif //CUBE_3_CUBE_3_H
