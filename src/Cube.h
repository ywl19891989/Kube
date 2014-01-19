/*
 * Cube.h
 *
 *  Created on: 2013-1-12
 *      Author: Hali
 */

#ifndef CUBE_H_
#define CUBE_H_

#include "GLShape.h"
#include "GLFace.h"
#include <GL/gl.h>

class Cube: public GLShape {

public:
	Cube(GLWorld* world, GLfloat left, GLfloat bottom, GLfloat back, GLfloat right, GLfloat top, GLfloat front);

	static const int kBottom = 0;
	static const int kFront = 1;
	static const int kLeft = 2;
	static const int kRight = 3;
	static const int kBack = 4;
	static const int kTop = 5;

};

#endif /* CUBE_H_ */
