#ifndef chunk_h
#define chunk_h

#include "common.h"
#include "value.h"

typedef enum {
    OP_CONSTANT,
    OP_NEGATE,
    OP_ADD,
    OP_SUBTRACT,
    OP_MULTIPLY,
    OP_DIVIDE,
    OP_PRINT,
    OP_RETURN,
    OP_NIL,
    OP_TRUE,
    OP_FALSE,
    OP_POP,
    OP_DEFINE_GLOBAL,
    OP_GET_GLOBAL,
    OP_SET_GLOBAL,
    OP_GET_LOCAL,
    OP_SET_LOCAL,
    OP_LOOP,
    OP_CALL,
    OP_JUMP_IF_FALSE,
    OP_JUMP,
    OP_NOT,
    OP_EQUAL,
    OP_GREATER,
    OP_LESS,
} OpCode;

typedef struct chunk_t {
    int count;
    int capacity;
    uint8_t* code;
    int* lines;
    ValueArray constants;    
} Chunk;


void initChunk(Chunk* chunk);
void freeChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte,int line);

int addConstant(Chunk* chunk, Value value);

#endif