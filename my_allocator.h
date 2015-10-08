/* 
    File: my_allocator.h

    Author: R.Bettati
            Department of Computer Science
            Texas A&M University
    Date  : 08/02/08

    Modified:

*/

#ifndef _my_allocator_h_                   // include file only once
#define _my_allocator_h_

#pragma pack(1)
struct node {
    // --Header
    struct node* next;
    //Note: if size is odd, size = size + 1 (i.e. block is used)
    int size;
};

typedef void * Addr;

void print_list();

extern unsigned int init_allocator(unsigned int _basic_block_size,
			    unsigned int _length); 
/* This function initializes the memory allocator and makes a portion of 
   ’_length’ bytes available. The allocator uses a ’_basic_block_size’ as 
   its minimal unit of allocation. The function returns the amount of 
   memory made available to the allocator. If an error occurred, 
   it returns 0. 
*/ 

int release_allocator(); 
/* This function returns any allocated memory to the operating system. 
   After this function is called, any allocation fails.
*/ 

Addr my_malloc(unsigned int _length); 
/* Allocate _length number of bytes of free memory and returns the 
   address of the allocated portion. Returns 0 when out of memory. */ 
   
void add_to_free(struct node *new_node, int index);

void combine(Addr _a);
   
int my_free(Addr _a); 
/* Frees the section of physical memory previously allocated 
   using ’my_malloc’. Returns 0 if everything ok. */ 

#endif 
