#include "chunk.h"
#include "memory.h"
#include "value.h"

void initChunk(Chunk* chunk){
    if(!chunk) return;
    chunk->capacity = 0;
    chunk->count = 0;
    chunk->code = NULL;
    chunk->lines = NULL;
    initValueArray(&chunk->constants);
}

void freeChunk(Chunk* chunk){
    if(!chunk) return;
    FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
    FREE_ARRAY(int, chunk->lines, chunk->capacity);
    freeValueArray(&chunk->constants);
    initChunk(chunk);
}


void writeChunk(Chunk* chunk, uint8_t byte, int line){
    if(!chunk) return;

    if(chunk->capacity < chunk->count + 1){
        int old_capacity = chunk->capacity;
        chunk->capacity = GROW_CAPACITY(old_capacity);
        chunk->code = GROW_ARRAY(uint8_t, chunk->code,
                    old_capacity, chunk->capacity);
        chunk->lines = GROW_ARRAY(int, chunk->lines, old_capacity, chunk->capacity);
    }

   
    chunk->code[chunk->count] = byte;
    chunk->lines[chunk->count] = line;
    chunk->count++;
}

int addConstant(Chunk* chunk, Value value){
    writeValueArray(&chunk->constants, value);
    return chunk->constants.count - 1;
}