#ifndef _SUDOKU_H_
#define _SUDOKU_H_

#include <stdint.h>

#define ARROW_UP 1
#define ARROW_DOWN 2
#define ARROW_LEFT 3
#define ARROW_RIGHT 4

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

// Escribe en una casilla el numero indicado
void write_at(uint8_t num, uint8_t row, uint8_t col);

#endif