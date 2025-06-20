#include "io-ports.h"
#include "io-text.h"

int vga_offset(int col, int row);
int vga_row(int offset);
int vga_col(int offset);

int AMPEREK_GET_CURSOR_OFFSET(){
	IO_BYTE_WRITE(IO_WRITE, 14);
	int offset = IO_BYTE_READ(IO_READ) << 8;
	IO_BYTE_WRITE(IO_WRITE, 15);
	offset += IO_BYTE_READ(IO_READ);
	return offset * 2;
}

void AMPEREK_SET_CURSOR_OFFSET(int offset){
    offset /= 2;
    IO_BYTE_WRITE(IO_WRITE, 14);
    IO_BYTE_WRITE(IO_READ, (unsigned char)(offset >> 8));
    IO_BYTE_WRITE(IO_WRITE, 15);
    IO_BYTE_WRITE(IO_READ, (unsigned char)(offset & 0xff));
}

void AMPEREK_TEXT_MODE_CLEAR(){
	for(int i = 0; i < MAX_COL * MAX_ROW; i++){
		char* VGA = (char*) VGA_MEM_ADDR;
		int offset = i * 2;
		VGA[offset] = ' ';
		VGA[offset+1] = 0x0f;
	}
	AMPEREK_SET_CURSOR_OFFSET(vga_offset(0, 0));
}

int AMPEREK_PRINT_CHAR(char c, int col, int row, char attrib){
    unsigned char* VGA = (unsigned char*) VGA_MEM_ADDR;
    if(col >= MAX_COL || row >= MAX_ROW){
        VGA[2*(MAX_COL)*(MAX_ROW)-2] = 'X';
        VGA[2*(MAX_COL)*(MAX_ROW)-1] = RED_TEXT;
        return vga_offset(col, row);
    }
    int offset;
    if(col >= 0 && row >= 0){
	    offset = vga_offset(col, row);
    }else{
	    offset = AMPEREK_GET_CURSOR_OFFSET();
    }

    if(c == '\n'){
	row = vga_row(offset);
        offset = vga_offset(0, row+1);
    }else{
        VGA[offset] = c;
        VGA[offset+1] = attrib;
        offset+=2;
    }
    AMPEREK_SET_CURSOR_OFFSET(offset);
    return offset;
}

void AMPEREK_PRINT(char* str, int col, int row, char attrib){
    int offset = vga_offset(col, row);
    int i = 0;
    while(str[i] != 0){
        offset = AMPEREK_PRINT_CHAR(str[i++], col, row, attrib);
	col = vga_col(offset);
	row = vga_row(offset);
    }
}

void AMPEREK_PRINT_AT_CURSOR(char* str, char attrib){
	int offset = AMPEREK_GET_CURSOR_OFFSET();
	int col = vga_col(offset);
	int row = vga_row(offset);
	int i = 0;
	while(str[i] != 0){
        	offset = AMPEREK_PRINT_CHAR(str[i++], col, row, attrib);
		col = vga_col(offset);
		row = vga_row(offset);	
	}
}

int vga_offset(int col, int row){
    return 2 * (row * MAX_COL + col);
}
int vga_row(int offset){
	return offset / (2 * MAX_COL);
}
int vga_col(int offset){
	return (offset - (vga_row(offset) * 2 * MAX_COL))/2;
}
