# Simple memory allocator

Implemented a "buddy-system" memory allocator where memory block sizes are a power of two. Basic block size and memory size is read as an argument when the allocator is run. The correctness and performance of the allocator was tested with an implementation of an Ackermann function provided by the course. The `getopt()` C library function is used to parse command line arguments.

`memtest` is run in the following form:
```
memtest -b <blocksize, in bytes. Default: 128 bytes>
        -s <size of memory to be allocated, in bytes. Default: 512kB>
```

A performance analysis was conducted and documented in `analysis.pdf`.

_Created for CSCE 313 at Texas A&M University_

Contributors:
* Ryan Walters
* Garrett Haynes
