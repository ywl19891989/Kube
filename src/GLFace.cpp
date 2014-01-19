/*
 * GLFace.cpp
 *
 *  Created on: 2013-1-12
 *      Author: Hali
 */

#include "GLFace.h"
#include "GLVertex.h"
#include "GLColor.h"

// for quadrilaterals
GLFace::GLFace(GLVertex* v1, GLVertex* v2, GLVertex* v3, GLVertex* v4) {
	mColor = NULL;
	addVertex(v1);
	addVertex(v2);
	addVertex(v3);
	addVertex(v4);
}

void GLFace::addVertex(GLVertex* v) {
	mVertexList.push_back(v);
}

// must be called after all vertices are added
void GLFace::setColor(GLColor* c) {

	mColor = c;

	int vertexCount = mVertexList.size();
	if (vertexCount < 3) {
		printf("[GLFace]: not enough vertices in setColor()");
	} else {
		// only need to do this if the color has never been set
		int i = vertexCount - 1;
		GLVertex* vertex = mVertexList[i];

		if (mColor == NULL) {
			while (vertex->color != NULL && i >= 0) {
				i--;
				vertex = mVertexList[i];
			}
		}
		vertex->color = c;
	}

}

int GLFace::getIndexCount() {
	return (mVertexList.size() - 2) * 3;
}

void GLFace::putIndices(GLshort* & buffer) {
	int last = mVertexList.size() - 1;

	GLVertex* v0 = mVertexList[0];
	GLVertex* vn = mVertexList[last];

	// push triangles into the buffer
	for (int i = 1; i < last; i++) {
		GLVertex* v1 = mVertexList[i];
		*(buffer++) = v0->index;
		*(buffer++) = v1->index;
		*(buffer++) = vn->index;
		v0 = v1;
	}
}
