/*
 * GLWorld.cpp
 *
 *  Created on: 2013-1-12
 *      Author: Hali
 */
#include "GLWorld.h"
#include "GLShape.h"
#include "GLVertex.h"
#include <gl/gl.h>
#include <gl/glut.h>
#include <iostream>
#include <stdio.h>

GLWorld::GLWorld() {
	count = 0;
	mIndexCount = 0;
	mVertexBuffer = NULL;
	mColorBuffer = NULL;
	mIndexBuffer = NULL;
}

void GLWorld::addShape(GLShape* shape) {
	mShapeList.push_back(shape);
	mIndexCount += shape->getIndexCount();
}

void GLWorld::generate() {

	mVertexBuffer = new GLfloat[mVertexList.size() * 3];
	mColorBuffer = new GLfloat[mVertexList.size() * 4];
	mIndexBuffer = new GLshort[mIndexCount];

	int vertextCount = mVertexList.size();

	GLfloat* vertexBuffer = mVertexBuffer;
	GLfloat* colorBuffer = mColorBuffer;
	GLshort* indexBuffer = mIndexBuffer;

	for (unsigned int i = 0; i < mVertexList.size(); i++) {
		GLVertex* vertex = mVertexList[i];
		vertex->put(vertexBuffer, colorBuffer);
	}

	for (unsigned int i = 0; i < mShapeList.size(); i++) {
		GLShape* shape = mShapeList[i];
		shape->putIndices(indexBuffer);
	}

	int realvertextCount = (vertexBuffer - mVertexBuffer);
	int realcolorCount = (colorBuffer - mColorBuffer);
	int realindexCount = (indexBuffer - mIndexBuffer);

	printf("%p-%d, %p-%d\n", mVertexBuffer, vertextCount * 3, vertexBuffer, realvertextCount);
	printf("after put mVertexBuffer: %p %p\n", mVertexBuffer + vertextCount * 3, vertexBuffer);
	printf("%p-%d, %p-%d\n", mColorBuffer, vertextCount * 4, colorBuffer, realcolorCount);
	printf("after put colorBuffer: %p %p\n", mColorBuffer + vertextCount * 4, colorBuffer);
	printf("%p-%d, %p-%d\n", mIndexBuffer, mIndexCount, indexBuffer, realindexCount);
	printf("after put indexBuffer: %p %p\n", mIndexBuffer + mIndexCount, indexBuffer);
}

GLVertex* GLWorld::addVertex(GLfloat x, GLfloat y, GLfloat z) {
	GLVertex* vertex = new GLVertex(x, y, z, mVertexList.size());
	printf("addVertex %d\n", mVertexList.size());
	mVertexList.push_back(vertex);
	return vertex;
}

void GLWorld::transformVertex(GLVertex* vertex, M4* transform) {
	vertex->update(mVertexBuffer, transform);
}

void GLWorld::draw() {
	printf("start GLWorld draw\n");
	glFrontFace(GL_CW);
	testGLError();
	glShadeModel(GL_FLAT);
	testGLError();
	glVertexPointer(3, GL_FLOAT, 0, mVertexBuffer);
	testGLError();
	glColorPointer(4, GL_FLOAT, 0, mColorBuffer);
	testGLError();
	glDrawElements(GL_TRIANGLES, mIndexCount, GL_UNSIGNED_SHORT, mIndexBuffer);
	testGLError();
	count++;
	printf("end GLWorld draw\n");
}

void GLWorld::testGLError() {
	GLenum errorNum = glGetError();
	if (errorNum != 0) {
		printf("glerror %d\n", errorNum);
	}
}

float GLWorld::toFloat(int x) {
	return x / 65536.0f;
}

