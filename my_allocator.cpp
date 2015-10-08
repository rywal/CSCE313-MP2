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
#include <stdio.h>
#include <math.h>
#include "my_allocator.h"

int header_size = sizeof(node);
node** headers;
node* head;
int M, b;

void print_list(){
    for (int x = 0; x <= log2(M/b); x++) {
        if(headers[x] != NULL){
            printf("Element %i: size(%i)", x, headers[x]->size);
            node* current_node = headers[x];
            while (current_node->next != NULL) {
                printf(" - > size(%i)", current_node->size);
                current_node = current_node->next;
            }
            printf("\n");
        } else {
            printf("Element %i: NULL\n", x);
        }
        
    }
}

/* Don't forget to implement "init_allocator" and "release_allocator"! */
unsigned int init_allocator(unsigned int _basic_block_size, unsigned int _length){
	//TODO: input error checking
	M = _length;
	b = _basic_block_size;
	int last_index = log2 (M/b);
	headers = new node*[last_index + 1]();
	head = (node *)malloc(M);
	headers[last_index] = (struct node*) head;
	headers[last_index]->next = NULL;
	headers[last_index]->size = M;
	return 0;
}

int release_allocator(){
    return 0;
}

int size_available(int i){
	return (b*pow(2, i))-header_size;
}

void init_block(node* start, int size){
	
}

int choose_index(unsigned int _length){
    // printf("\n--In choose_index\n");
    // print_list();git s
    int number_headers = log2 (M/b);
	for(int i = 0; i <= number_headers; i++){
		if(headers[i] != NULL && (_length <= size_available(i))) {
			if(i == 0)	return i;
			if(_length <= size_available(i-1)){
				//Split block and recursivly call
				headers[i-1] = headers[i];
				if(headers[i]->next != NULL && headers[i]->next->size % 2 == 0){
					headers[i] = headers[i]->next;
				}else{
					headers[i] = NULL;
				}
				char* next = (char*)headers[i-1] + b*(int)pow(2, i-1);
				struct node *new_node = (struct node*)next;
				new_node->next = NULL;
				new_node->size = b*(int)pow(2, i-1);
				headers[i-1]->size = b*(int)pow(2, i-1);
				headers[i-1]->next = new_node;
				return choose_index(_length);
			}else{
				return i;
			}
		}
	}
    return -1;
}

extern Addr my_malloc(unsigned int _length) {
	/* This preliminary implementation simply hands the call over the 
	 the C standard library! 
	 Of course this needs to be replaced by your implementation.
	*/
	int index = choose_index(_length);
	headers[index]->size += 1;
	Addr result = (Addr)((char *)headers[index] + header_size);
	if(headers[index]->next != NULL && headers[index]->next->size %2 == 0){
		headers[index] = headers[index]->next;
	}else{
		headers[index] = NULL;
	}
	return result;
}

extern int my_free(Addr _a) {
    // Get start of header
    Addr adjusted_address = _a - header_size;
    
    // Find node with adjusted address
    node* current_node = adjusted_address;
    
    
    return 0;
}

