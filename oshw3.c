#include <stdio.h>
#include <fcntl.h>

#define BLOCK_SIZE 8

int main ( int argc, char *argv[] ) {
	if (argc != 3){
		printf("Please two arguments, an infile and an outfile.\n");
		return 0;
	}
	//inputs and outputs numerical references with read and write privileges, respectively
	int infile = open(argv[1], O_RDONLY);
	int outfile = open(argv[2], O_WRONLY);

	close(infile);
	close(outfile);
	return 0;
}
