/*
 * Layer.cpp
 *
 *  Created on: 2013-12-29
 *      Author: Hali
 */

#include "Layer.h"
#include "GLShape.h"
#include "Constants.h"

Layer::Layer(int axis) {
	// start with identity matrix for transformation
	mAxis = axis;
	mTransform = new M4();
	mTransform->setIdentity();

	for (int i = 0; i < 9; i++) {
		mShapes[i] = NULL;
	}
}

void Layer::startAnimation() {
	for (int i = 0; i < 9; i++) {
		GLShape* shape = mShapes[i];
		if (shape != NULL) {
			shape->startAnimation();
		}
	}
}

void Layer::endAnimation() {
	for (int i = 0; i < 9; i++) {
		GLShape* shape = mShapes[i];
		if (shape != NULL) {
			shape->endAnimation();
		}
	}
}

void Layer::setAngle(float angle) {
	// normalize the angle
	float twopi = (float) PI * 2;
	while (angle >= twopi) {
		angle -= twopi;
	}
	while (angle < 0) {
		angle += twopi;
	}

	float sinV = (float) sin(angle);
	float cosV = (float) cos(angle);

	float** m = mTransform->m;

	switch (mAxis) {
		case kAxisX:
			m[1][1] = cosV;
			m[1][2] = sinV;
			m[2][1] = -sinV;
			m[2][2] = cosV;
			m[0][0] = 1;
			m[0][1] = m[0][2] = m[1][0] = m[2][0] = 0;
			break;
		case kAxisY:
			m[0][0] = cosV;
			m[0][2] = sinV;
			m[2][0] = -sinV;
			m[2][2] = cosV;
			m[1][1] = 1;
			m[0][1] = m[1][0] = m[1][2] = m[2][1] = 0;
			break;
		case kAxisZ:
			m[0][0] = cosV;
			m[0][1] = sinV;
			m[1][0] = -sinV;
			m[1][1] = cosV;
			m[2][2] = 1;
			m[2][0] = m[2][1] = m[0][2] = m[1][2] = 0;
			break;
	}

	for (int i = 0; i < 9; i++) {
		GLShape* shape = mShapes[i];
		if (shape != NULL) {
			shape->animateTransform(mTransform);
		}
	}
}
