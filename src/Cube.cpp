/*
 * Cube.cpp
 *
 *  Created on: 2013-12-29
 *      Author: Hali
 */

#include "Cube.h"

Cube::Cube(GLWorld* world, float left, float bottom, float back, float right, float top, float front)
 : GLShape(world)
{

	GLVertex* leftBottomBack = addVertex(left, bottom, back);
	GLVertex* rightBottomBack = addVertex(right, bottom, back);
	GLVertex* leftTopBack = addVertex(left, top, back);
	GLVertex* rightTopBack = addVertex(right, top, back);
	GLVertex* leftBottomFront = addVertex(left, bottom, front);
	GLVertex* rightBottomFront = addVertex(right, bottom, front);
	GLVertex* leftTopFront = addVertex(left, top, front);
	GLVertex* rightTopFront = addVertex(right, top, front);

	// vertices are added in a clockwise orientation (when viewed from the outside)
	// bottom
	addFace(new GLFace(leftBottomBack, leftBottomFront, rightBottomFront, rightBottomBack));
	// front
	addFace(new GLFace(leftBottomFront, leftTopFront, rightTopFront, rightBottomFront));
	// left
	addFace(new GLFace(leftBottomBack, leftTopBack, leftTopFront, leftBottomFront));
	// right
	addFace(new GLFace(rightBottomBack, rightBottomFront, rightTopFront, rightTopBack));
	// back
	addFace(new GLFace(leftBottomBack, rightBottomBack, rightTopBack, leftTopBack));
	// top
	addFace(new GLFace(leftTopBack, rightTopBack, rightTopFront, leftTopFront));

}

