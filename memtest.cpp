#include "ackerman.h"
#include "my_allocator.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char ** argv) {

    // input parameters (basic block size, memory length)

    // init_allocator(basic block size, memory length)
    init_allocator(128, 1024);
    
    ackerman_main();

    // release_allocator()
}
