#ifndef submesh_h
#define submesh_h

#include "opengl.h"

struct submesh { 
	int vlen;
	int vsize;
	int ilen;
	GLfloat *vtxs;
	GLubyte *idxs;
};

#endif