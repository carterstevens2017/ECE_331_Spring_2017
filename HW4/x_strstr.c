#include <stdio.h>
#include <stdlib.h>

char *x_strstr(const char *haystack, const char *needle);

int main(int argc, char *argv[]){
	const char *haystack = argv[1];
	const char *needle = argv[2];
	char *ret;

	if(argc != 3){
		printf("Incorrect arguments, FUNCTION_CALL HAYSTACK NEEDLE");
		return 1;
	}

	ret = x_strstr(haystack, needle);
	if(ret == NULL){
		printf("String not found\n");
		return 1;
	}
	printf("%s\n", ret);
	return 0;
}



char *x_strstr(const char *haystack, const char *needle){

	int hayind = 0, needind = 0, j = 0;
	char *ret = NULL;

	while(*(haystack + hayind)!='\0'){
		while(*(needle + needind) == *(haystack + hayind + j)){
			needind++;
			j++;
			if(*(haystack + hayind + j) == '\0') return ret;
			if(*(needle + needind) == '\0') return needle;	
		}
		hayind++;
		j = 0;
		needind = 0;
	}
	return ret;
}
