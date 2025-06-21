void mcopy(char* from, char* to, int totalBytes){
	for(int i = 0; i < totalBytes; i++){
		*(to + i) = *(from + i);
	}
}
