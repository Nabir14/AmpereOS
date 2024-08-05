void test_ep(){
}

void main(){
	char* vmem = (char*) 0xb8000;
	*vmem = 'X';
}
