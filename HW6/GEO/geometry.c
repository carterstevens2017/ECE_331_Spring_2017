#include <stdlib.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/hdreg.h>
#include <linux/fs.h>

int main(void)
{
	//creates structure to hold SD card info
	struct hd_geometry *geo = (struct hd_geometry*)malloc(sizeof(struct hd_geometry));
	int status;

	//opens SD card file descriptor
	int sd = open("/dev/mmcblk0", O_RDONLY);
	//checks that file descriptor opened correctly
	if(sd < 0){
		printf("File failed to open\n");
		return 1;
	}
	//checks that allocation exited cleanly
	if (geo == NULL){
		printf("Unable to allocate struct\n");
		return 1;
	}
	//calls ioctl to populate structure
	status = ioctl(sd, HDIO_GETGEO, geo);
	//checks if ioctl failed
	if(status < 0){
		printf("IOCTL failed\n");
		return 1;
	}
	//print information
	printf("SD Card Heads: %u\n", geo->heads);
	printf("SD Card Sectors: %u\n", geo->sectors);
	printf("SD Card Cylinders: %d\n", geo->cylinders);
	printf("SD Card Start: %lu\n", geo->start);
	//free allocated memory
	free(geo);
	return 0;
}
