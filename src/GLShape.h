/*
 * GLShape.h
 *
 *  Created on: 2013-1-12
 *      Author: Hali
 */

#ifndef GLSHAPE_H_
#define GLSHAPE_H_

#include <stdio.h>
#include <vector>
#include <GL/gl.h>
#include "M4.h"
#include "GLWorld.h"
#include "GLVertex.h"
#include "GLFace.h"

using namespace std;

class GLShape {

public:

	GLShape(GLWorld* world);

	void addFace(GLFace* face);

	void setFaceColor(int face, GLColor* color);

	void putIndices(GLshort* & buffer);

	int getIndexCount();

	GLVertex* addVertex(GLfloat x, GLfloat y, GLfloat z);

	void animateTransform(M4* transform);

	void startAnimation();

	void endAnimation();

	M4* mTransform;
	M4* mAnimateTransform;

protected:
	vector<GLFace*> mFaceList;
	vector<GLVertex*> mVertexList;
	vector<GLint> mIndexList; // make more efficient?
	GLWorld* mWorld;
};

#endif /* GLSHAPE_H_ */
