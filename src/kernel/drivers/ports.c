unsigned char IO_BYTE_READ(unsigned short port){
	unsigned char res;
	__asm__("in %%dx, %%al": "=a" (res) : "d" (port));
	return res;
}
void IO_BYTE_WRITE(unsigned short port, unsigned char data){
	__asm__("out %%al, %%dx": : "a" (data), "d" (port));
}
