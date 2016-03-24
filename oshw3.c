#include <stdio.h>
#include <fcntl.h>

#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BLOCK_SIZE 8

int main ( int argc, char *argv[] ) {
	if (argc != 3){
		printf("Please two arguments, an infile and an outfile.\n");
		return 0;
	}
	//inputs and outputs numerical references with read and write privileges, respectively
	int infile = open(argv[1], O_RDONLY);
	int outfile = open(argv[2], O_WRONLY);

	struct stat buff;
	stat(argv[1], &buff);
	int num_bytes = buff.st_size;
	printf("number of bytes in infile = %i\n", num_bytes);

	close(infile);
	close(outfile);
	return 0;
}
