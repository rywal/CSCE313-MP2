#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ackerman.h"
#include "my_allocator.h"

int main(int argc, char ** argv) {
    // Default values
    int M = 512*1024;
    int b = 128;
    
    init_allocator(b, M);
    
//    printf("Step 1 - Printing\n");
//    print_list();
//    
//    printf("\nStep 2 - Adding 200\n");
//    Addr address1 = my_malloc(200);
//    print_list();
//    
//    printf("\nStep 3 - Deleting 200\n");
//    my_free(address1);
//    print_list();
//    
//    printf("\nStep 4 - Adding 500\n");
//    Addr address2 = my_malloc(500);
//    print_list();
//    
//    printf("\nStep 5 - Adding 100\n");
//    Addr address3 = my_malloc(100);
//    print_list();
//    
//    printf("\nStep 6 - Delete 100\n");
//    my_free(address3);
//    print_list();
//    
//    printf("\nStep 7 - Delete 500\n");
//    my_free(address2);
//    print_list();
    
    ackerman_main();

    release_allocator();
}
