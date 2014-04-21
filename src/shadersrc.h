#ifndef shadersrc_h
#define shadersrc_h

#include "opengl.h"

#define LOG(format, ...) printf(format, __VA_ARGS__)

char VSRC_0[];
char FSRC_0[];

void buildShader(GLuint *prog,char *vscr, char *fsrc);

#endif