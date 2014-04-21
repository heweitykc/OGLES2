#include "MathUtil.h"
#include "Vector3.h"

const Vector3 kZeroVector(0.0f,0.0f,0.0f);

float wrapPi(float theta)
{
	theta += kPi;
	theta -= floor(theta*k1Over2Pi) * k2Pi;
	theta -= kPi;
	return theta;
}

float safeAcos(float x)
{
	if(x<=-1.0f){
		return kPi;
	}
	if(x>=1.0f){
		return 0.0f;
	}
	return acos(x);
}

