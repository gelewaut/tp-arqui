#include <sudoku.h>

static uint8_t grill[9][9] =
{
    {5, 0, 0, 0, 8, 6, 0, 0, 1},
    {0, 0, 2, 7, 0, 1, 6, 0, 0},
    {0, 7, 1, 0, 0, 0, 2, 5, 0},
    {9, 1, 0, 0, 2, 0, 0, 7, 0},
    {3, 0, 0, 1, 4, 5, 0, 0, 6},
    {0, 6, 0, 0, 9, 0, 0, 2, 4},
    {0, 5, 3, 0, 0, 0, 4, 0, 0},
    {0, 0, 8, 9, 0, 3, 5, 0, 0},
    {2, 0, 0, 5, 1, 0, 0, 0, 7}
};

uint8_t processSudoku(uint8_t key) {
    if (isNumber(key)) {

    }
    if (isArrow(key)) {
        uint8_t arrow = parseArrow(key); 
    }

//cambiar
    return 1;
}

uint8_t parseArrow(key) {
    switch (key) {
        case ARROW_UP: {
            if(cursor_y < 8)
                cursor_y++;
        }
        case ARROW_DOWN: {
            if(cursor_y > 0)
                cursor_y--;
        }
        case ARROW_LEFT: {
            if(cursor_x > 0)
                cursor_x--;
        }
        case ARROW_RIGHT: {
            if(cursor_x < 8)
                cursor_x++;
        }
    }
}

static uint8_t cursor_x = 0;

static uint8_t cursor_y = 0;

uint8_t check_move(uint8_t num, uint8_t row, uint8_t col) {
    uint8_t isValid = 1;

    isValid = check_row(num, row);
    if (isValid) {
       isValid = check_col(num, col);
    }
    if (isValid) {
        isValid = check_square(num, row, col);
    }

    return isValid;
}