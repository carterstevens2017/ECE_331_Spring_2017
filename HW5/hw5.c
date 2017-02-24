#include "morse.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]){
	
	
	initmorse();
	char *input;
	int len, i;
	unsigned int j;
	struct morse_char morse;
	
	//check for number of arguments
	if(argc!=2){
		perror("Incorrect number of arguments");
		return 1;
	}
	
	//gets data and size of input string
	input = argv[1];
	len = strlen(input);
	
	//print preamble
	printf("__*_");
	//iterates through input characters
	for(i = 0; i < len; i++){
		j=0;
		if(*(input + i) == ' ') printf("_______");
		else{
			//retrievs info from lookup table
			morse = lookup[toupper((int)*(input+i))];
			//looks through bits, converts 1 to * 0 to _
			while(morse.val > 0){
				if((morse.val & (0x01<<j)) != 0) printf("*");
				else printf("_");
				morse.val &= ~(0x01<<j); 
				j++;
			}
			//checks if there is a next letter
			if(((i+1) < len) && (*(input + i + 1) != ' ')) printf("___");
		}
	}
	printf("\n");	
	return 0;
}
