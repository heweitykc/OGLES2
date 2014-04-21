#ifndef demo2_h
#define demo2_h

#include <windows.h>
#include "opengl.h"

#define TIME GetTickCount();

void touchBegin(int x,int y);
void touchMove(int x,int y);
void touchEnd(int x,int y);

void glInit2(GLsizei width, GLsizei height);
void glRender2();

#endif