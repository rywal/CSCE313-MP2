#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ackerman.h"
#include "my_allocator.h"

int main(int argc, char ** argv) {

    // input parameters (basic block size, memory length)

    // init_allocator(basic block size, memory length)
    init_allocator(128, 1024);
    
    printf("Step 1\n");
    print_list();
    
    printf("\nStep 2\n");
    Addr address1 = my_malloc(80);
    print_list();
    
    printf("\nStep 3\n");
    Addr address2 = my_malloc(100);
    print_list();
    
    
    //ackerman_main();

    // release_allocator()
}
