/*
 * Constants.h
 *
 *  Created on: 2013-1-12
 *      Author: Hali
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#define PI 3.1415926535

namespace Constants {

// names for our 9 layers (based on notation from http://www.cubefreak.net/notation.html)
	extern const int kUp;
	extern const int kDown;
	extern const int kLeft;
	extern const int kRight;
	extern const int kFront;
	extern const int kBack;
	extern const int kMiddle;
	extern const int kEquator;
	extern const int kSide;

	extern const int sceneWidth;
	extern const int sceneHeight;

	extern int mLayerPermutations[9][27];
}

#endif /* CONSTANTS_H_ */
