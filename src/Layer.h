/*
 * Layer.h
 *
 *  Created on: 2013-1-12
 *      Author: Hali
 */

#ifndef LAYER_H_
#define LAYER_H_

#include <stdio.h>
#include <cmath>
#include "m4.h"

class GLShape;
class Layer {

public:
	Layer(int axis);

	void startAnimation();

	void endAnimation();

	void setAngle(float angle);

	GLShape* mShapes[9];
	M4* mTransform;
//	float mAngle;

// which axis do we rotate around?
// 0 for X, 1 for Y, 2 for Z
	int mAxis;
	static const int kAxisX = 0;
	static const int kAxisY = 1;
	static const int kAxisZ = 2;
};

#endif /* LAYER_H_ */
