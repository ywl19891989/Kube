/*
 * GLShape.cpp
 *
 *  Created on: 2013-12-29
 *      Author: Hali
 */

#include "GLShape.h"
#include <stdio.h>

GLShape::GLShape(GLWorld* world) :
		mWorld(NULL) {
	mWorld = world;
	mAnimateTransform = NULL;
	mTransform = NULL;
}

void GLShape::addFace(GLFace* face) {
	printf("addFace %d %p\n", mFaceList.size(), face);
	mFaceList.push_back(face);
}

void GLShape::setFaceColor(int faceIndex, GLColor* color) {
	mFaceList[faceIndex]->setColor(color);
}

void GLShape::putIndices(GLshort* & buffer) {
	vector<GLFace*>::iterator iter = mFaceList.begin();
	while (iter != mFaceList.end()) {
		GLFace* face = *iter;
		face->putIndices(buffer);
		iter++;
	}
}

int GLShape::getIndexCount() {
	int count = 0;
	vector<GLFace*>::iterator iter = mFaceList.begin();
	while (iter != mFaceList.end()) {
		GLFace* face = *iter;
		count += face->getIndexCount();
		iter++;
	}
	return count;
}

GLVertex* GLShape::addVertex(GLfloat x, GLfloat y, GLfloat z) {

	// look for an existing GLVertex first

	GLVertex* vertex = NULL;

	for (unsigned int i = 0; i < mVertexList.size(); i++) {
		vertex = mVertexList[i];
		if (vertex != NULL && vertex->x == x && vertex->y == y && vertex->z == z) {
			printf("got vertext %p\n", vertex);
			return vertex;
		}
	}

	// doesn't exist, so create new vertex
	vertex = mWorld->addVertex(x, y, z);
	mVertexList.push_back(vertex);
	return vertex;
}

void GLShape::animateTransform(M4* transform) {
	mAnimateTransform = transform;

	if (mTransform != NULL){
		transform = mTransform->multiply(transform);
	}

	vector<GLVertex*>::iterator iter = mVertexList.begin();
	while (iter != mVertexList.end()) {
		GLVertex* vertex = *iter;
		mWorld->transformVertex(vertex, transform);
		iter++;
	}
}

void GLShape::startAnimation() {
}

void GLShape::endAnimation() {
	if (mTransform == NULL) {
		mTransform = new M4(mAnimateTransform);
	} else {
		mTransform = mTransform->multiply(mAnimateTransform);
	}
}

