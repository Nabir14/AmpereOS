#define VMEM_ADDR 0xb8000

void main(){
	char* vmem = (char*) VMEM_ADDR;
	*vmem[0x0] = 'AmpereOS v0.2';
	*vmem[0x2] = 0x0f;
	clear_screen();
}

void clea_screen(){
	for(int i = 0; i < 80 * 25; i++){
		char* vmem = (char*) VMEM_ADDR;
		*vmem[i * 2] = ' ';
		*vmem[(i * 2) + 1] = 0x0f;
	}
}

