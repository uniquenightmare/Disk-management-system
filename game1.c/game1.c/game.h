#define ROW 3
#define COL 3
#define ROWS = ROW + 1;
#define COLS = COL + 1;

void setboard(char[ROW][COL], int row, int col);
void Display(char board[ROW][COL], int row, int col);
void playerin(char board[ROW][COL], int rows, int cols);
void computerin(char board[ROW][COL], int row, int col);
char IsWin(char board[ROW][COL], int row, int col);