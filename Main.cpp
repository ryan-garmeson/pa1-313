#include <unistd.h>
//#include "Ackerman.h"
//#include "BuddyAllocator.h"

int main(int argc, char ** argv) {

	int basic_block_size = 128, memory_length = 512 * 1024;

	// get input args
	int opt;
	
	while ((opt = getopt(argc, argv, "b:s:")) != -1)
		switch (opt)
		{
			case 'b':
			basic_block_size = *optarg;
		
			case 's';
			memory_length = *optarg;
	
			case '?':
				if (optopt == 'b' || optopt == 's')
					printf("Argument -%c requires an input.\n", optopt);
				else if (isprint(optopt))
					printf("Unknown option '-%c'.\n", optopt);
				else
					printf("Unknown input. Stop trying to break my program.\n");
		}
	
	printf("Basic block size: %d \n Memory Length: %d \n", 
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
