#include "stdio.h"

#include "compile.h"
#include "common.h"
#include "scanner.h"

void compile(const char* source){
    initScanner(source);
    for(;;){
        int line = -1;
        Token token = scanToken();
        if(token.line != line){
            prinf("%4d", token.line);
            line = token.line;
        } else {
            printf("    |");
        }
        printf("%2d '%.*s'", token.type,token.length,token.start);

        if(token.type == TOKEN_EOF) break;
    }
}