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

    1 3 223 231
    122 123 2 2  :6  
    2   3 2 2*  
    info    
*/

#define SUDOKU_SCREEN_START_X 41
#define SUDOKU_SCREEN_END_X 80

#define SUDOKU_SCREEN_START_Y 0
#define SUDOKU_SCREEN_END_Y 14

#define BLANK_TOKEN '_'

static uint8_t grill[9][9] =
    {
        {0, 8, 0, 7, 0, 1, 0, 3, 0},
        {4, 0, 9, 0, 0, 0, 0, 0, 0},
        {0, 5, 0, 0, 5, 0, 4, 1, 8},
        {7, 0, 0, 0, 0, 9, 0, 0, 0},
        {8, 0, 0, 6, 1, 0, 5, 0, 0},
        {0, 3, 5, 0, 0, 0, 0, 2, 9},
        {0, 6, 0, 4, 0, 7, 0, 9, 0},
        {1, 0, 0, 0, 0, 8, 0, 0, 4},
        {0, 2, 0, 0, 5, 0, 0, 7, 0},
};

static uint8_t solution[9][9] =
    {
        {2, 8, 6, 7, 4, 1, 9, 3, 5},
        {4, 1, 9, 3, 8, 5, 7, 6, 2},
        {3, 5, 7, 9, 6, 2, 4, 1, 8},
        {7, 4, 1, 5, 2, 9, 3, 8, 6},
        {8, 9, 2, 6, 1, 3, 5, 4, 7},
        {6, 3, 5, 8, 7, 4, 1, 2, 9},
        {5, 6, 8, 4, 3, 7, 2, 9, 1},
        {1, 7, 3, 2, 9, 8, 6, 5, 4},
        {9, 2, 4, 1, 5, 6, 8, 7, 3},
};

// row | col | value
#define VALUES_LEN 3
static uint8_t values[VALUES_LEN] = {0, 0, 0};
static uint8_t values_idx = 0;

static uint8_t *won_string = "Congratulations";
static uint8_t *bad_move_string = "Wrong move";

static uint8_t won = 0;

uint8_t processSudoku(uint8_t key)
{
    if (won)
        return;
    if (isNumber(key))
    {
        // sin cursor
        values[values_idx] = key - '0';
        values_idx = (values_idx + 1) % 3;
    }
    else if (key == '\n')
    {
        uint8_t isGoodMove = check_move(values[2], values[0], values[1]);
        if (isGoodMove)
        {
            grill[values[0] - 1][values[1] - 1] = values[2];
        }
    }
    won = check_win();
    print_sudoku();
    //cambiar
    return 1;
}

uint8_t check_win()
{
    uint8_t won = 1;
    for (int i = 0; i < MAX_ROWS && won; i++)
    {
        for (int j = 0; j < MAX_COLS && won; j++)
        {
            won = (grill[i][j] == solution[i]);
        }
    }
    return won;
}

uint8_t check_move(uint8_t num, uint8_t row, uint8_t col)
{
    if (row < 1 || row > 9)
        return 0;
    if (col < 1 || col > 9)
        return 0;

    return (num == solution[row - 1][col - 1]);
}

uint8_t check_row(uint8_t num, uint8_t row)
{
    for (int i = 0; i < MAX_COLS; i++)
    {
        if (num == grill[row][i])
            return 0;
    }
    return 1;
}

uint8_t check_col(uint8_t num, uint8_t col)
{
    for (int i = 0; i < MAX_ROWS; i++)
    {
        if (num == grill[i][col])
            return 0;
    }
    return 1;
}

uint8_t check_square(uint8_t num, uint8_t row, uint8_t col)
{
    uint8_t r, rmax, c, cmax;
    r = row / 3;
    rmax = r + 2;
    c = col / 3;
    cmax = c + 2;

    for (; r <= rmax; r++)
    {
        for (; c <= cmax; c++)
        {
            if (num == grill[r][c])
                return 0;
        }
    }
    return 1;
}

// void clear_buffer()
// {
//     for (int i = 0; i < info_idx; i++)
//     {
//         info_buffer[i] = 0;
//     }
// }

void print_sudoku()
{
    print_grill();
}

/*
    123 4 4 234
    1 2  23  *3
    1 3   3   3

    NUM: 6

    Movimiento ilegal

*/

void print_grill()
{
    // int offset_x, offset_y;
    // uint8_t token;
    // uint8_t num;
    // offset_x = 10;
    // offset_y = 0;
    // for (int i = 0; i < MAX_ROWS; i++)
    // {
    //     for (int j = 0; j < MAX_COLS; j++)
    //     {
    //         num = grill[i][j];
    //         if (num >= 1 && num <= 9)
    //         {
    //             token = num + '0';
    //         }
    //         else
    //         {
    //             token = BLANK_TOKEN;
    //         }
    //         printCharAt(token, SUDOKU_SCREEN_START_X + offset_x + i, SUDOKU_SCREEN_START_Y + offset_y + j);
    //     }
    // }

    uint8_t num;
    uint8_t token;
    uint8_t offset_x = 0;
    for (int i = 0; i < MAX_ROWS; i++)
    {
        for (int j = 0; j < MAX_COLS; j++)
        {
            num = grill[i][j];
            token = (num != 0 ? num + '0' : BLANK_TOKEN);
            printCharAt(token, SUDOKU_SCREEN_START_X + offset_x + j, SUDOKU_SCREEN_START_Y + i);
        }
    }

    printCharAt(values[0] + '0', SUDOKU_SCREEN_START_X + 2, SUDOKU_SCREEN_START_Y + 10);
    printCharAt(values[1] + '0', SUDOKU_SCREEN_START_X + 4, SUDOKU_SCREEN_START_Y + 10);
    printCharAt(values[2] + '0', SUDOKU_SCREEN_START_X + 6, SUDOKU_SCREEN_START_Y + 10);

    for (int b = SUDOKU_SCREEN_START_X; b < SUDOKU_SCREEN_END_X; b++)
    {
        printCharAt(' ', b, SUDOKU_SCREEN_START_Y + 11);
    }
    printCharAt('^', SUDOKU_SCREEN_START_X + (values_idx + 1) * 2, SUDOKU_SCREEN_START_Y + 11);
}

uint8_t isNumber(uint8_t key)
{
    return (key >= '1' && key <= '9');
}