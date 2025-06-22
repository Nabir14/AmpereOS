void mcopy(char* from, char* to, int totalBytes){
	for(int i = 0; i < totalBytes; i++){
		*((char*)to + i) = *((char*)from + i);
	}
}
