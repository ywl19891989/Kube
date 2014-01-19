/*
 * GLVertex.cpp
 *
 *  Created on: 2013-1-12
 *      Author: Hali
 */

#include "GLVertex.h"
#include "GLColor.h"
#include "GLWorld.h"
#include "m4.h"
#include <stdio.h>

GLVertex::GLVertex(GLfloat x, GLfloat y, GLfloat z, GLshort index) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->index = index;
	this->color = NULL;
}

bool GLVertex::equals(GLVertex* v) {
	return (x == v->x && y == v->y && z == v->z);
}

int GLVertex::toFixed(float x) {
	return (int) (x * 65536.0f);
}

void GLVertex::put(GLfloat* & vertexBuffer, GLfloat* & colorBuffer) {
	float* & tempV = vertexBuffer;
	float* & tempC = colorBuffer;
	*(tempV++) = x;
	*(tempV++) = y;
	*(tempV++) = z;
	if (color == 0) {
		*(tempC++) = 0;
		*(tempC++) = 0;
		*(tempC++) = 0;
		*(tempC++) = 0;
	} else {
		*(tempC++) = color->red;
		*(tempC++) = color->green;
		*(tempC++) = color->blue;
		*(tempC++) = color->alpha;
	}

	char temp[128];
	sprintf(temp, "x %f, y %f, z %f", x, y, z);
	printf("putColor index %d , %s\n", index, temp);
}

void GLVertex::update(float* vertexBuffer, M4* transform) {
	// skip to location of vertex in mVertex buffer
	float* tempV = vertexBuffer + (index * 3);

	if (transform == NULL) {
		*(tempV++) = x;
		*(tempV++) = y;
		*(tempV++) = z;
	} else {
		GLVertex* temp = new GLVertex(0, 0, 0, -1);
		transform->multiply(this, temp);
		*(tempV++) = temp->x;
		*(tempV++) = temp->y;
		*(tempV++) = temp->z;
	}
}

