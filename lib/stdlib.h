#ifndef _cstdlib_
#define _cstdlib_

#include "../libsrc/MemoryManager.h"

// TODO: implement all 47 functions, macros, and types

void* malloc(size_t size) {
    return _mm_allocate(size);
}

void* realloc(void* ptr, size_t size) {
    return _mm_reallocate(ptr, size);
}

void free(void* ptr) {
    return _mm_free(ptr);
}

#endif
