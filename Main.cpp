#include <unistd.h>
#include <cstdio>
#include <ctype.h>
#include <stdlib.h>
//#include "Ackerman.h"
//#include "BuddyAllocator.h"

bool IsPowerOfTwo(int x)
{
	return (x != 0) && ((x & (x - 1)) == 0);
}

int main(int argc, char ** argv) {

	int basic_block_size = 128, memory_length = 512 * 1024;

	// get input args
	int opt;
	opt = getopt(argc, argv, "b:s:");
	while (opt != -1)
	{
		switch (opt)
		{
			case 'b':
			basic_block_size = atoi(optarg);
			if (!(IsPowerOfTwo(basic_block_size)))
			{
				printf("%d is not a power of 2. Using default 128.\n", 
					basic_block_size);
				basic_block_size = 128;
			}
			break;
		
			case 's':
			memory_length = atoi(optarg);
			break;
	
			case '?':
				if (optopt == 'b' || optopt == 's')
					printf("Argument -%c requires an input.\n", optopt);
				else if (isprint(optopt))
					printf("Unknown option '-%c'.\n", optopt);
				else
					printf("Unknown input. Stop trying to break my program.\n");
		}
		opt = getopt(argc, argv, "b:s:");
	}
	if (!(IsPowerOfTwo(memory_length)) || memory_length < basic_block_size)
		{
			printf("%d is not a valid memory length. Using default 512kB.\n",
				memory_length);
			memory_length = 512 * 1024;
		}
	printf("Basic block size: %d \nMemory Length: %d \n", 
		basic_block_size, memory_length);
	
	// create memory manager
	//BuddyAllocator * allocator = 
	//	new BuddyAllocator(basic_block_size, memory_length);

	// test memory manager
	//Ackerman* am = new Ackerman ();
	//am->test(allocator); // this is the full-fledged test. 
	
	// destroy memory manager
	//delete allocator;
}
