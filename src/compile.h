#ifndef COMPILE_H
#define COMPILE_H

#include "chunk.h"
#include "object.h"

ObjFunction* compile(const char* source);
void markCompilerRoots();

#endif