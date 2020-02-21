#pragma once
#include <string>
#include <cmath>

template<class T>
class VectorGeneric3
{
public:
	VectorGeneric3(T _x, T _y, T _z) {
		x = _x;
		y = _y;
		z = _z;
	};
	VectorGeneric3(const VectorGeneric3& vector) {
		this->x = vector.x;
		this->y = vector.y;
		this->z = vector.z;
	};
	//THIS LOOKS SLOPPY AF
	VectorGeneric3& operator= (const VectorGeneric3& rhs)
	{
		if (&rhs == this)
			return *this;

		this->x = rhs.x;
		this->y = rhs.y;
		this->z = rhs.z;
		return *this;
	}
	
	std::string ToString()
	{
		return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
	};
	T realLength() {
		return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
	};
	VectorGeneric3 directorVector() {
		double length = realLength();
		return VectorGeneric3(this->x / length, this->y / length, this->z / length);
	}

	VectorGeneric3 operator+ (const VectorGeneric3& rhs) {
		return VectorGeneric3(this->x + rhs.x, this->y + rhs.y, this-> z + rhs.z);
	};
	VectorGeneric3& operator+=(const VectorGeneric3& rhs) {
		this->x += rhs.x;
		this->y += rhs.y;
		this->z += rhs.z;
		return this;
	}

	VectorGeneric3 operator- (const VectorGeneric3& rhs) {
		return VectorGeneric3(this->x - rhs.x, this->y - rhs.y, this->z - rhs.z);
	};
	VectorGeneric3& operator-=(const VectorGeneric3& rhs) {
		this->x -= rhs.x;
		this->y -= rhs.y;
		this->z -= rhs.z;
		return this;
	}

	T operator* (const VectorGeneric3& rhs) {
		return ((this->x * rhs.x) + ( this->y * rhs.y) + (this->z * rhs.z));
	};
	VectorGeneric3 operator* (const double& rhs)
	{
		return VectorGeneric3(this->x * rhs, this->y * rhs, this ->z * rhs);
	}
	VectorGeneric3 operator* (const float& rhs)
	{
		return VectorGeneric3(this->x * rhs, this->y * rhs, this->z * rhs);
	}
	VectorGeneric3 operator* (const int& rhs)
	{
		return VectorGeneric3(this->x * rhs, this->y * rhs, this->z * rhs);
	}
	
	VectorGeneric3 operator^ (const VectorGeneric3& rhs)
	{
		return VectorGeneric3(((this->y * rhs.z) - (this->z * rhs.y)), -((this->x * rhs.z) + (this->z * rhs.x)), ((this->x * rhs.y) - (this->y * rhs.x)));
	}

	
	//LOGIC OPERATORS
	bool operator<(const VectorGeneric3& rhs) {
		T lengthThis = this->realLength();
		T lengthRhs = rhs.realLength();
		return (lengthThis < lengthRhs);
	}
	bool operator<=(const VectorGeneric3& rhs) {
		T lengthThis = this->realLength();
		T lengthRhs = rhs.realLength();
		return (lengthThis <= lengthRhs);
	}
	bool operator>(const VectorGeneric3& rhs) {
		T lengthThis = this->realLength();
		T lengthRhs = rhs.realLength();
		return (lengthThis > lengthRhs);
	}
	bool operator>=(const VectorGeneric3& rhs) {
		T lengthThis = this->realLength();
		T lengthRhs = rhs.realLength();
		return (lengthThis >= lengthRhs);
	}
	bool operator==(const VectorGeneric3& rhs) {
		T lengthThis = this->realLength();
		T lengthRhs = rhs.realLength();
		return (lengthThis == lengthRhs);
	}
private:
	T x;
	T y;
	T z;
};

typedef VectorGeneric3<double> Vector3D;
typedef VectorGeneric3<float> Vector3F;