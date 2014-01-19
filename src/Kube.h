/*
 * Kube.h
 *
 *  Created on: 2013-12-29
 *      Author: Hali
 */

#ifndef KUBE_H_
#define KUBE_H_

#include <sys/time.h>

class Cube;
class Layer;
class GLColor;
class GLWorld;
class Kube {
public:

	Kube();
	virtual ~Kube();

	void start(int argc, char *argv[]);

	void createLayers();
	void updateLayers();
	void makeGLWorld();

	void animate();

	void myDisplay();

	void idle();

	void testGLError();

	void reshape(int w, int h);

	void setCubeFaceColor(Cube* cube, int face, GLColor* color);

private:

	float mAngle;

	GLWorld* mWorld;

	static const int CUBE_NUM = 27;
	static const int LAYER_NUM = 9;

	Cube* mCubes[CUBE_NUM];

	// a Layer for each possible move
	Layer* mLayers[LAYER_NUM];

	// current permutation of starting position
	int* mPermutation;

	// currently turning layer
	Layer* mCurrentLayer;

	// current and final angle for current Layer animation
	float mCurrentAngle, mEndAngle;

	// amount to increment angle
	float mAngleIncrement;

	int* mCurrentLayerPermutation;

	struct timeval _lastTime;

	bool _isFirstDraw;

};

#endif /* KUBE_H_ */
