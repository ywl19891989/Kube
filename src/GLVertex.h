/*
 * GLVertex.h
 *
 *  Created on: 2013-1-12
 *      Author: Hali
 */

#ifndef GLVERTEX_H_
#define GLVERTEX_H_

#include <GL/gl.h>

class GLColor;
class M4;

class GLVertex {
public:
	GLfloat x;
	GLfloat y;
	GLfloat z;
	GLshort index; // index in vertex table
	GLColor* color;

	GLVertex(GLfloat x, GLfloat y, GLfloat z, GLshort index);

	bool equals(GLVertex* v);

	static int toFixed(float x);

	void put(GLfloat* & vertexBuffer, GLfloat* & colorBuffer);

	void update(GLfloat* vertexBuffer, M4* transform);
};

#endif /* GLVERTEX_H_ */
