#ifndef camera_h
#define camera_h

#include "Vector3.h"
#include "Matrix4x3.h"

class Camera
{
public:
	enum CameraType { LANDOBJECT, AIRCRAFT};
	Camera(CameraType cameraType);
	~Camera();

	void straft(float units);
	void fly(float units);
	void walk(float units);

	void pitch(float angle);
	void yaw(float angle);
	void roll(float angle);
	
	void setCameraType(CameraType cameraType);
	void getPosition(Vector3* pos);
	void setPosition(Vector3* pos);
	void getRight(Vector3* right);
	void getUp(Vector3* up);
	void getLook(Vector3* look);

	void viewMatrix();
	void perspectiveFieldOfView(
		float filedOfView,
		float aspectRation,
		float zNear,
		float zFar,
		float *m
	);

	void getMatrix(float *m);

private:
	CameraType _cameraType;
	Vector3 _right;
	Vector3 _up;
	Vector3 _look;
	Vector3 _pos;

	Matrix4x3 _viewMatrix;
};

#endif