#include <stdio.h>
#include <fcntl.h>

#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BLOCK_SIZE 8

void reverse(char original[], int size);

int main ( int argc, char *argv[] ) {
	if (argc != 3){
		printf("Please two arguments, an infile and an outfile.\n");
		return 0;
	}
	//inputs and outputs numerical references with read and write privileges, respectively
	int infile = open(argv[1], O_RDONLY);
	int outfile = open(argv[2], O_WRONLY);

	struct stat stat_buff;
	stat(argv[1], &stat_buff);
	int num_bytes = stat_buff.st_size -1;
	//printf("number of bytes in infile = %i\n", num_bytes);

	//how many full blocks
	int num_blocks = num_bytes / BLOCK_SIZE;
	//how many bytes in partial block
	int remainder_bytes = num_bytes % BLOCK_SIZE;

	//array the size of a block of bytes
	char copy_data[BLOCK_SIZE];
	//iterating through blocks
	for (int i=0; i<num_bytes; i+=BLOCK_SIZE){
		//data is read into copy data
		lseek(infile, -1*(i+BLOCK_SIZE), SEEK_END);
		//printf("%i\n", read(infile, copy_data, BLOCK_SIZE));
		//data is reversed
		reverse(copy_data, BLOCK_SIZE);
		write(outfile, copy_data, BLOCK_SIZE);
		printf("%i ", i);
	}

	close(infile);
	close(outfile);


	// test code for reversal
	// char test[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
	// reverse(test, 10);
	// for (int i=0; i<10; i++){
	// 	printf("%c", test[i]);
	// }
	return 0;
}

void reverse(char original[], int size){
	int front = 0;
	int back = size-1;
	int swap = -1;
	while( front < back ){
		original[swap] = original[front];
		original[front] = original[back];
		original[back] = original[swap];
		front += 1;
		back -= 1;
	}
}
