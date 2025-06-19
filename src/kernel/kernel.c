#define VMEM_ADDR 0xb8000

void main(){
	char* vmem = (char*) VMEM_ADDR;
	*vmem = 'AmpereOS v0.2';
	clear_screen();
}

void clea_screen(){
	for(int i = 0; i < 80 * 25; i++){
		char* vmem = (char*) VMEM_ADDR;
		*vmem[i * 2] = ' ';
	}
}

