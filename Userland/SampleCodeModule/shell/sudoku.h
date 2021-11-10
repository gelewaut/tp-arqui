#ifndef _SUDOKU_H_
#define _SUDOKU_H_

#include <stdint.h>

#define ARROW_UP 1
#define ARROW_DOWN 2
#define ARROW_LEFT 3
#define ARROW_RIGHT 4

#define MAX_ROWS 9
#define MAX_COLS 9

#define BUFFER_LENGHT 128

uint8_t processSudoku(uint8_t c);

// imprime estado del sudoku
void print_sudoku();

// checkea validez de un movimiento
uint8_t check_move(uint8_t num, uint8_t row, uint8_t col);

// checkea validez de una fila
uint8_t check_row(uint8_t num, uint8_t row);

// checkea validez en la comuna
uint8_t check_col(uint8_t num, uint8_t col);

uint8_t check_square(uint8_t num, uint8_t row, uint8_t col);

void clear_buffer();

void print_sudoku();

void print_grill();

void print_values_buff();

void print_num_buff();

void print_info();

uint8_t processSudoku(uint8_t key);

void parseArrow(uint8_t key);

uint8_t check_win();

uint8_t isArrow(uint8_t key);

uint8_t isNumber(uint8_t key);

#endif