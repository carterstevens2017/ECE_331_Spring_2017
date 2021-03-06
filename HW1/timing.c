#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
	int buffsize = atoi(argv[1]);
	char *values;
	struct timespec start, end;
	//uint64_t time;
	FILE *fp;
	char timestr[256];

	//open file for data output
	fp = fopen("timing.dat", "a");
	//make sure there is one argument
	if (argc < 2 || argc > 2){
		printf("Program requires one argument\n");
		return 1;
	}
	//allocate argument number of integers
	values = (char *) malloc(sizeof(char)*buffsize);
	if (values == NULL){
		printf("Allocation failed\n");
		return 1;
	}
	//get start time
	clock_gettime(CLOCK_MONOTONIC, &start);
	//access buffer and set values
	//for (i=0; i<buffsize; i++){
	//	values[i] = buffsize;
	//}
	memset(values, buffsize, sizeof(char)*buffsize);
	//get end time
	clock_gettime(CLOCK_MONOTONIC, &end);
	//report times
	printf("Bytes allocated: %d\n", buffsize);
	printf("Start Time: %lds, %lluns\n",(long int) start.tv_sec, (long long unsigned int) start.tv_nsec);
	printf("End Time: %lds, %lluns\n", (long int) end.tv_sec, (long long unsigned int) end.tv_nsec);
	//time = end.tv_nsec - start.tv_nsec;

	fputs(argv[1] , fp);
	fputs("\t" , fp);

	sprintf(timestr, "%ld", (long int) start.tv_sec);
	fputs(timestr , fp);
	fputs("\t", fp);

	sprintf(timestr, "%lld", (long long unsigned int) start.tv_nsec);
	fputs(timestr , fp);
	fputs("\t", fp);

	sprintf(timestr, "%ld", (long int) end.tv_sec);
	fputs(timestr , fp);
	fputs("\t", fp);

	sprintf(timestr, "%lld", (long long unsigned int) end.tv_nsec);
	fputs(timestr , fp);
	fputs("\n" , fp);

	fclose(fp);

	//printf("Elapsed time accessing memory: %llu nanoseconds\n", (long long unsigned int) time);
	free(values);
	return 0;
}
