#include <sudoku.h>
#include <userlibc.h>
#include <syscalls.h>

/*
    SUDOKU SCREEN LIMITS
    ROW / COL
        41  .   .   .   80
    0
    .
    .
    .
    14
*/

#define SUDOKU_SCREEN_START_X 41
#define SUDOKU_SCREEN_END_X 80

#define SUDOKU_SCREEN_START_Y 0
#define SUDOKU_SCREEN_END_Y  14

#define BLANK_TOKEN '_'

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


static const char * num_buff_prompt = "TO INSERT: ";
static uint8_t *num_buffer;
static uint8_t cursor_x = 0, cursor_y = 0;

static char * info_buffer[BUFFER_LENGHT] = {0};
static uint8_t  info_idx = 0;

uint8_t processSudoku(uint8_t key) {
    if (isNumber(key)) {
        *num_buffer = strToNum(key);
    } else if (key == '\n') {
        uint8_t goodMove = check_move(*num_buffer, cursor_x, cursor_y);
        if (goodMove) {
            grill[cursor_x][cursor_y] = *num_buffer;
            *info_buffer = "Movimiento realizado con exito";
        } else {
            *info_buffer = "Movimiento ilegal";
        }
    } else if (isArrow(key)) {
        uint8_t arrow = parseArrow(key); 
    }

    print_sudoku();
    //cambiar
    return 1;
}

uint8_t parseArrow(uint8_t key) {
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

uint8_t check_win() {
    uint8_t won = 1;
    for (int i = 0; i < MAX_ROWS && won; i++) {
        for (int j = 0; j < MAX_COLS && won; j++) {
            won = check_move(grill[i][j], i, j);
        }
    }
    return won;
}

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

uint8_t check_row( uint8_t num, uint8_t row) {
    for (int i = 0; i < MAX_COLS; i++) {
        if (num == grill[row][i])
            return 0;
    }
    return 1;
}

uint8_t check_col(uint8_t num, uint8_t col) {
    for (int i = 0; i < MAX_ROWS; i++) {
        if (num == grill[i][col])
            return 0;
    }
        return 1;
}

uint8_t check_square(uint8_t num, uint8_t row, uint8_t col) {
    uint8_t r, rmax, c, cmax;
    r = row / 3; rmax = r + 2;
    c = col / 3; cmax = c + 2;

    for (r; r <= rmax; r++) {
        for (c; c <= cmax; c++) {
            if (num == grill[r][c])
                return 0;
        }
    }
    return 1;
}

void clear_buffer() {
    for (int i = 0; i < info_idx; i++) {
        info_buffer[i] = 0;
    }
}

void print_sudoku() {
    print_grill();
    print_num_buffer();
    print_info();
    clear_buffer();
}


/*
    123 4 4 234
    1 2  23  *3
    1 3   3   3

    NUM: 6

    Movimiento ilegal

*/

void print_grill() {
    int offset_x, offset_y;
    uint8_t token;
    uint8_t num;
    offset_x = 0;
    offset_y = 10;
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            num = grill[i][j];
            if (num >= 1 && num <= 9) {
                token = numToStr(num, 10);
            } else {
                token = BLANK_TOKEN;
            }
            sys_writeAt(token,
                SUDOKU_SCREEN_START_X + offset_x + i,
                SUDOKU_SCREEN_START_Y + offset_y + j);
        }
    }

    // Prints the cursor
    sys_writeAt('*', offset_x + cursor_x, offset_y + cursor_y);
}

void print_num_buff() {
    uint8_t offset_x = 23;
    uint8_t offset_y = 5;
    int i;
    for (i = 0; num_buff_prompt[i]; i++) {
        sys_writeAt(num_buff_prompt[i], SUDOKU_SCREEN_START_X + offset_x + i, SUDOKU_SCREEN_START_Y + offset_y);
    }
    sys_writeAt(numToStr(*num_buffer, 10), SUDOKU_SCREEN_START_X + offset_x + i, SUDOKU_SCREEN_START_Y + offset_y);
}



void print_info() {
    int info_offset_x = 12;
    for (int i = 0; i < info_idx; i++) {
        sys_writeAt(info_buffer[i], SUDOKU_SCREEN_START_X + info_offset_x, SUDOKU_SCREEN_START_Y + i);
    }
    clear_buffer();
}