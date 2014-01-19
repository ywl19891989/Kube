/*
 * GLWorld.h
 *
 *  Created on: 2013-1-12
 *      Author: Hali
 */

#ifndef GLWORLD_H_
#define GLWORLD_H_

#include <vector>
#include <GL/gl.h>

using std::vector;

class GLShape;
class GLVertex;
class M4;

class GLWorld {

public:

	GLWorld();

	void addShape(GLShape* shape);

	void generate();

	GLVertex* addVertex(GLfloat x, GLfloat y, GLfloat z);

	void transformVertex(GLVertex* vertex, M4* transform);

	int count;
	void draw();

	static float toFloat(int x);

	void testGLError();

private:
	vector<GLShape*> mShapeList;
	vector<GLVertex*> mVertexList;

	GLsizei mIndexCount;

	GLfloat* mVertexBuffer;
	GLfloat* mColorBuffer;
	GLshort* mIndexBuffer;
};

#endif /* GLWORLD_H_ */
