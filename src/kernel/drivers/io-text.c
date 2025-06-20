#include "io-ports.h"
#include "io-text.h"

int vga_offset(int col, int row){}
    
void AMPEREK_PRINT(char* str, int col, int row){
    int offset = vga_offset(col, row);
    int i = 0;
    while(str[i] != "0"){
        offset = AMPEREK_PRINT_CHAR(str[i++], col, row, WHITE_TEXT);
    }
}

void AMPEREK_PRINT_AT_CURSOR(char* str){

}

int AMPEREK_PRINT_CHAR(char c, int col, int row, int attrib){
    unsigned char* VGA = (unsigned char*) VGA_MEM_ADDR;
    if(col >= MAX_COL || row >= MAX_ROW){
        VGA[2*(MAX_COL)*(MAX_ROW)-2] = 'X';
        VGA[2*(MAX_COL)*(MAX_ROW)-1] = RED_TEXT;
        return vga_offset(col, row);
    }
    int offset = vga_offset(col, row);

    if(c =="/n"){
        offset = vga_offset(0, row+1);
    }else{
        VGA[offset] = c;
        VGA[offset+1] = WHITE_TEXT;
        offset+=2;
    }
    AMPEREK_SET_CURSOR_OFFSET(offset);
    return offset;
}

void AMPEREK_SET_CURSOR_OFFSET(int offset){
    offset /= 2;
    IO_BYTE_WRITE(IO_READ, 14);
    IO_BYTE_WRITE(IO_WRITE, (unsigned char)(offset >> 8));
    IO_BYTE_WRITE(IO_READ, 15);
    IO_BYTE_WRITE(IO_WRITE, (unsigned char)(offset & 0xff));
}

int vga_offset(int col, int row){
    return 2 * (row * MAX_COL + col);
}