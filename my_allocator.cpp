/* 
    File: my_allocator.c

    Author: <your name>
            Department of Computer Science
            Texas A&M University
    Date  : <date>

    Modified: 

    This file contains the implementation of the module "MY_ALLOCATOR".

*/

#include<stdlib.h>
#include <math.h>
#include "my_allocator.h"

/* Don't forget to implement "init_allocator" and "release_allocator"! */
unsigned int init_allocator(unsigned int _basic_block_size, unsigned int _length){
	//TODO: input error checking
	M = _length;
	b = _basic_block_size;
	int last_index = log2 (M/b)
	headers = new node*[last_index + 1]();
	head = malloc(M);
	headers[last_index] = (struct node*) head;
	headers[last_index]->next = null_ptr;
	headers[last_index]->size = M;
	
} 

extern Addr my_malloc(unsigned int _length) {
  /* This preliminary implementation simply hands the call over the 
     the C standard library! 
     Of course this needs to be replaced by your implementation.
  */
  return malloc((size_t)_length);
}

extern int my_free(Addr _a) {
  /* Same here! */
  free(_a);
  return 0;
}

