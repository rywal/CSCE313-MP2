/* 
    File: my_allocator.c

    Author: <your name>
            Department of Computer Science
            Texas A&M University
    Date  : <date>

    Modified: 

    This file contains the implementation of the module "MY_ALLOCATOR".

*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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

int choose_index(unsigned int _length){
    // printf("\n--In choose_index\n");
    // print_list();
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
void add_to_free(struct node *new_node, int index){
	new_node->next = NULL;
	if(headers[index] != NULL){
		struct node *ittr = headers[index];
		while(ittr->next != NULL){
			ittr = ittr->next;
		}
		ittr->next = new_node;
	}else{
		headers[index] = new_node;			
	}
}

void combine(Addr _a){
	struct node *current_node = (struct node*)_a;
	int size = current_node->size - 1;
	int current_index = log2(size/b);
	if(current_index == log2(M/b))	return;
    struct node *buddy_node = (struct node*)((unsigned long)current_node ^ (unsigned long) size);
	if(buddy_node->size % 2 == 0){
		//buddy node is empty
		//combine
		struct node *large_node = current_node;
		large_node->size = size * 2;
		large_node->next = NULL;
        void* start_point = (char*)_a + header_size;
		memset(start_point, 0, (int)(large_node->size - header_size));
		combine(_a);
	}else{
		//buddy node in use
		//don't combine
		add_to_free(current_node, current_index);
		return;
	}
	
}

extern int my_free(Addr _a) {
	//TODO: Handle case of trying to free already free address
    // Get start of header
    Addr adjusted_address = (Addr)((char*)_a - header_size);
	struct node *current_node = (struct node*)adjusted_address;
    memset(_a, 0, current_node->size - header_size);
	combine(adjusted_address);     
    return 0;
}

