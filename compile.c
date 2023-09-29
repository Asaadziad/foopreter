#include "stdio.h"

#include "compile.h"
#include "common.h"
#include "scanner.h"

bool compile(const char* source,Chunk* chunk){
    initScanner(source);
    advance();
    expression();
    consume(TOKEN_EOF, "Expect end of expression.");
}