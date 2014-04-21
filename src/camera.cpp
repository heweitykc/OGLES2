#include "camera.h"

Camera::Camera(CameraType cameraType)
{
	_cameraType = cameraType;
	_pos.x = _pos.y = 0;
	_pos.z = -50.0f;

	_right.y = _right.z = 0;
	_right.x = 1;

	_up.x = _up.z = 0;
	_up.y = 1;

	_look.x = _look.y = 0;
	_look.z = 1;
}

void Camera::viewMatrix()
{
	_look.normalize();
	_up = crossProduct(_look , _right);
	_up.normalize();

	_right = crossProduct(_up , _look);
	_right.normalize();

	float x = -1 * (_right * _pos);
	float y = -1 * (_up * _pos);
	float z = -1 * (_look * _pos);

	_viewMatrix.m11 = _right.x;
	_viewMatrix.m12 = _up.x;
	_viewMatrix.m13 = _look.x;

	_viewMatrix.m21 = _right.y;
	_viewMatrix.m22 = _up.y;
	_viewMatrix.m23 = _look.y;

	_viewMatrix.m31 = _right.z;
	_viewMatrix.m32 = _up.z;
	_viewMatrix.m33 = _look.z;

	_viewMatrix.tx = x;
	_viewMatrix.ty = y;
	_viewMatrix.tz = z;
}

void Camera::pitch(float angle)
{
	Matrix4x3 t;
	t.setupRotate(_right, angle);
	_right = _right * t;
	_look = _look * t;
}

void Camera::yaw(float angle)
{
	Matrix4x3 t;

	if(_cameraType == LANDOBJECT){
		t.setupRotate(2,angle);
	}
	
	if(_cameraType == AIRCRAFT){
		t.setupRotate(_up, angle);
	}

	_right = _right * t;
	_look = _look * t;
}

void Camera::roll(float angle)
{
	if(_cameraType != AIRCRAFT) return;

	Matrix4x3 t;
	t.setupRotate(_look,angle);

	_right = _right * t;
	_up = _up * t;
}

void Camera::straft(float units)
{
	if(_cameraType == LANDOBJECT){
		_pos += Vector3(_right.x,0.0f,_right.z)*units;
	}
	
	if(_cameraType == AIRCRAFT){
		_pos += _right * units;
	}
}

void Camera::fly(float units)
{
	if(_cameraType == LANDOBJECT){
		_pos.y += units;
	}
	
	if(_cameraType == AIRCRAFT){
		_pos += _up * units;
	}
}

void Camera::walk(float units)
{
	if(_cameraType == LANDOBJECT){
		_pos += Vector3(_look.x,0.0f,_look.z)*units;
	}
	
	if(_cameraType == AIRCRAFT){
		_pos += _look * units;
	}
}

void Camera::perspectiveFieldOfView(
	float filedOfView,float aspectRation,float zNear,float zFar,float *m)
{
	float yScale = 1.0/tan(filedOfView/2.0);
	float xScale = yScale / aspectRation;

	m[0] = xScale;
	m[1] = 0.0f;
	m[2] = 0.0f;
	m[3] = 0.0f;
	
	m[4] = 0.0f;
	m[5] = yScale;
	m[6] = 0.0f;
	m[7] = 0.0f;

	m[8] = 0.0f;
	m[9] = 0.0f;
	m[10] = zFar/(zFar-zNear);
	m[11] = 1.0f;

	m[12] = 0.0f;
	m[13] = 0.0f;
	m[14] = (zNear*zFar)/(zNear-zFar);
	m[15] = 0.0f;
}

void Camera::getMatrix(float *m)
{
	this->viewMatrix();

	Matrix4x3 v = _viewMatrix;
	m[0] = v.m11;
	m[1] = v.m12;
	m[2] = v.m13;
	m[3] = 0.0f;

	m[4] = v.m21;
	m[5] = v.m22;
	m[6] = v.m23;
	m[7] = 0.0f;

	m[8] = v.m31;
	m[9] = v.m32;
	m[10] = v.m33;
	m[11] = 0.0f;

	m[12] = v.tx;
	m[13] = v.ty;
	m[14] = v.tz;
	m[15] = 1.0f;
}

Camera::~Camera()
{

}