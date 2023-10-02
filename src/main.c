#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "vm.h"
#include "common.h"


static void repl(){
    char line[1024];

    for(;;){
        printf("> ");
        if(!fgets(line,sizeof(line),stdin)){
            printf("\n");
            break;
        }

        interpret(line);
    }
}

static char* readFile(const char* path){
    FILE* source = fopen(path,"rb");
    if(!source){
        fprintf(stderr, "Couldn't open file - %s", path);
        exit(74);
    }
    fseek(source, 0L, SEEK_END);
    size_t file_size = ftell(source);
    rewind(source);

    char* buffer = (char*)malloc(file_size + 1);
    if(!buffer){
        fprintf(stderr,"Couldn't allocate memory");
        exit(74);
    }
    size_t bytesRead = fread(buffer,sizeof(char),file_size,source);
    if(bytesRead < file_size){
        fprintf(stderr, "Couldn't read file");
        exit(74);
    }
    buffer[bytesRead] = '\0';


    fclose(source);
    
    return buffer;
}

static void runFile(const char* path){
    char* source = readFile(path);
    InterpretResult result = interpret(source);
    free(source);

    if(result == INTERPRET_COMPILE_ERROR) exit(65);
    if(result == INTERPRET_RUNTIME_ERROR) exit(70);
}
int main(int argc,char** argv){
    initVM();
    
    if(argc == 1){
        repl();
    } else if(argc == 2){
        runFile(argv[1]);
    } else {
        fprintf(stderr, "Usage: clox [path]");
        exit(64);        
    }

    freeVM();

    return 0;
}