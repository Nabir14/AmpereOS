#define IO_WRITE 0x3d4
#define IO_READ 0x3d5

unsigned char IO_BYTE_READ(unsigned short port);
void IO_BYTE_WRITE(unsigned short port, unsigned char data);
