#ifndef EulerAngles_h
#define EulerAngles_h

class Quaternion;
class Matrix4x3;
class RotationMatrix;

class EulerAngles
{
public:
	float heading;
	float pitch;
	float bank;

	EulerAngles(){};
	EulerAngles(float h, float p, float b):heading(h), pitch(p),bank(b) {}
	~EulerAngles();

	void identity() { pitch = bank = heading = 0.0f;}
	void canonize();

	void fromObjectToInertialQuaternion(const Quaternion &q);
	void fromInertialToObjectQuaternion(const Quaternion &q);

	void fromObjectToWorldMatrix(const Matrix4x3 &m);
	void fromWorldToObjectMatrix(const Matrix4x3 &m);

	void fromRotationMatrix(const RotationMatrix &m);

private:

};

extern const EulerAngles kEulerAnglesIdentity;

#endif