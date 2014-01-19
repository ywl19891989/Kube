/*
 * GLFace.h
 *
 *  Created on: 2013-1-12
 *      Author: Hali
 */

#ifndef GLFACE_H_
#define GLFACE_H_

#include <stdio.h>
#include <vector>
#include <GL/gl.h>
#include "GLVertex.h"

class GLColor;
using namespace std;

class GLFace {
private:
	vector<GLVertex*> mVertexList;
	GLColor* mColor;

public:
	// for quadrilaterals
	GLFace(GLVertex* v1, GLVertex* v2, GLVertex* v3, GLVertex* v4);

	void addVertex(GLVertex* v);

	// must be called after all vertices are added
	void setColor(GLColor* c);

	int getIndexCount();

	void putIndices(GLshort* & buffer);

};

#endif /* GLFACE_H_ */
