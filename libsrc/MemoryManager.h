#pragma once

#ifndef MEMORYMANAGER_H
#define MEMORYMANAGER_H

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#define MEMORY_RESERVED_ADDRESS 0x100000
#define MEMORY_BEGIN_ADDRESS 0x101000

#define TMP_NEXT_MEM_PTR 0x0100100

size_t _mm_getMemoryLimit() {
    // TODO: rework this, just forced to 10MB for now
    return 10 * 1024 * 1024;
//    return 1000 * 1000 + *reinterpret_cast<uint16_t *>(0x7c00 + 506) * 1000 + *reinterpret_cast<uint16_t *>(0x7c00 + 508) * 64 * 1000;
}

/**
 * You NEED to call this once before doing anything.
 */
void _mm_setUp() {
    *((size_t*)TMP_NEXT_MEM_PTR) = MEMORY_BEGIN_ADDRESS;
}

void* _mm_allocate(const size_t size) {
    size_t* allocated = (size_t*)TMP_NEXT_MEM_PTR;
    *((size_t*)TMP_NEXT_MEM_PTR) += size;

    return allocated;
}

void _mm_free(void* pointer) {
    // TODO
}

void* _mm_reallocate(void* ptr, size_t size) {
    void* reallocated = _mm_allocate(size);
    for (size_t i = 0; i < size; i++) {
        ((uint8_t*)reallocated)[i] = ((uint8_t*)ptr)[i];
    }
    _mm_free(ptr);

    return reallocated;
}

#endif //MEMORYMANAGER_H
