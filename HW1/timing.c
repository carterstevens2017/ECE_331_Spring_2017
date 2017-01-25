#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
	int buffsize = atoi(argv[1]);
	int *values, i;
	struct timespec start, end;
	uint64_t time;
	FILE *fp;
	char timestr[256];

	fp = fopen("timing.txt", "a");
	if (argc < 2 || argc > 2){
		printf("Program requires one argument\n");
		return 1;
	}
	values = (int *) malloc(sizeof(int)*buffsize);
	if (values == NULL){
		printf("Allocation failed\n");
		return 1;
	}
	clock_gettime(CLOCK_MONOTONIC, &start);
	for (i=0; i<buffsize; i++){
		values[i] = buffsize;
	}
	clock_gettime(CLOCK_MONOTONIC, &end);
	time = end.tv_nsec - start.tv_nsec;
	sprintf(timestr, "%lld", (long long unsigned int) time);
	fputs(argv[1] , fp);
	fputs("\t" , fp);
	fputs(timestr , fp);
	fputs("\n" , fp);
	fclose(fp);
	printf("Elapsed time accessing memory: %llu nanoseconds\n", (long long unsigned int) time);
	free(values);
	return 0;
}
