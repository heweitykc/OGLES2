#ifndef Matrix4x3_h
#define Matrix4x3_h

class Vector3;
class EulerAngles;
class Quaternion;
class RotationMatrix;

class Matrix4x3
{
public:
	float m11, m12, m13;
	float m21, m22, m23;
	float m31, m32, m33;
	float tx, ty, tz;

	void identity();

	void zeroTranslation();
	void setTranslation(const Vector3 &d);
	void setupTranslation(const Vector3 &d);

	void setupLocalToParent(const Vector3 &pos, const EulerAngles &orient);
	void setupLocalToParent(const Vector3 &pos, const RotationMatrix &orient);
	void setupParentToLocal(const Vector3 &pos, const EulerAngles &orient);
	void setupParentToLocal(const Vector3 &pos, const RotationMatrix &orient);

	void setupRotate(int axis, float theta);
	void setupRotate(const Vector3 &axis, float theta);
	void fromQuaternion(const Quaternion &q);
	void setupScale(const Vector3 &s);
	void setupScaleAlongAxis(const Vector3 &axis, float k);
	void setupShear(int axis, float s, float t);
	void setupProject(const Vector3 &n);

	void getRawData(float *m);
};

Vector3 operator*(const Vector3 &p, const Matrix4x3 &m);
Matrix4x3 operator*(const Matrix4x3 &a, const Matrix4x3 &m);

Vector3 operator*=(const Vector3 &p, const Matrix4x3 &m);
Matrix4x3 operator*=(const Matrix4x3 &a, const Matrix4x3 &m);

float determinant(const Matrix4x3 &m);
Matrix4x3 inverse(const Matrix4x3 &m);
Vector3 getTranslation(const Matrix4x3 &m);
Vector3 getPositionFromParentToLocalMatrix(const Matrix4x3 &m);
Vector3 getPositionFromLocalToParentMatrix(const Matrix4x3 &m);

extern const Vector3 xVector;
extern const Vector3 yVector;
extern const Vector3 zVector;

#endif