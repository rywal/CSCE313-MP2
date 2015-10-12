#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ackerman.h"
#include "my_allocator.h"
#include <getopt.h>
#include <stdlib.h>

int main(int argc, char ** argv) {
    // Default values
    int memory = 512*1024;
    int base = 128;
    
    int opt;
    
    while ((opt = getopt(argc, argv, "b:s:")) != -1) {
        switch (opt) {
            case 'b':
                base = atoi(optarg);
                break;
            case 's':
                memory = atoi(optarg);
                break;
            default:
                base = 128;
                memory = 512*1024;
        }
    }

    
    init_allocator(base, memory);
    
    ackerman_main();
    
    release_allocator();
}
