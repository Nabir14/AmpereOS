#define VGA_MEM_ADDR 0xb8000
#define MAX_COL 80
#define MAX_ROW 25
#define WHITE_TEXT 0x0f
#define RED_TEXT 0xf4

void AMPEREK_TEXT_MODE_CLEAR();
void AMPEREK_PRINT(char* string, int col, int row, char attrib);
void AMPEREK_PRINT_AT_CURSOR(char* string, char attrib);
int AMPEREK_PRINT_CHAR(char c, int col, int row, char attrib);
int AMPEREK_GET_CURSOR_OFFSET();
void AMPEREK_SET_CURSOR_OFFSET(int offset);
