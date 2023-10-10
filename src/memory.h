#ifndef memory_h
#define memory_h

#include "common.h"
#include "object.h"

#define GROW_CAPACITY(capacity) \
    ((capacity) < 8 ? 8 : (capacity) * 2)

#define GROW_ARRAY(type, arrayPointer, oldCount, newCount) \
    (type*)reallocate(arrayPointer, sizeof(type) * oldCount, sizeof(type) * newCount)

#define FREE_ARRAY(type, arrayPointer, capacity) (type*)reallocate(arrayPointer, sizeof(type) * capacity, 0)

#define ALLOCATE(type, count) \
    (type*)reallocate(NULL, 0, sizeof(type) * (count))

#define FREE(type, pointer) reallocate(pointer, sizeof(type), 0)

void* reallocate(void* pointer, size_t old_size, size_t new_size);
void markObject(Obj* object);
void markValue(Value value);
void collectGarbage();
void freeObjects();

#endif