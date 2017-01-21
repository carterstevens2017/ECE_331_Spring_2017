#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int i;

	if (argc > 1){
		for (i = 1; i < argc; i++){
			printf("%s\t",argv[i]);
		}
	}
	return 0;
}
