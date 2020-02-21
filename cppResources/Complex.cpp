#pragma once
#include <iostream>
#include <string>
#include <cmath>

#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062

template<class T>
class ComplexGeneric
{
public:
	ComplexGeneric(T _realrad, T _imagang, bool _isCartesian) {
		//Cartesian: a + bi
		//Polar:rcos ang + rsin ang i
		//Exponential: r e^(i angle)
		if (_isCartesian == true)
		{
			real = _realrad;
			imag = _imagang;
			isCartesian = true;
			makePolar();
			//Calculate radius and angle
		}
		else {
			radius = _realrad;
			angle = _imagang;
			isCartesian = false;
			makeCartesian();
		}
	};
	void makePolar()
	{
		radius = sqrt(pow(real, 2) + pow(imag, 2));
		if (real != 0)
		{
			angle = atan((imag / real) * (180 / PI));
		}
		else
		{
			angle = 90;
		}
	};
	void makeCartesian()
	{
		real = radius * cos(angle * PI / 180);
		imag = radius * sin(angle * PI / 180);
	};
	std::string ToString()
	{
		if (isCartesian == true)
		{
			return printCartesian();
		}
		else
		{
			return printPolar();
		}
	};
	std::string printCartesian() {
		{
			std::string printer = "";
			if (real != 0)
			{
				printer += std::to_string(real);
				if (imag != 0)
				{
					printer += " + ";
					if (imag == 1)
					{
						printer += "i";
						return printer;
					}
					else
					{
						printer += std::to_string(imag);
						printer += " i";
						return printer;
					}
				}
				else
				{
					return printer;
				}
			}
			else
			{
				if (imag != 0)
				{
					if (imag == 1)
					{
						printer += "i";
						return printer;
					}
					else
					{
						printer += std::to_string(imag);
						printer += " i";
						std::cout << printer;
						return printer;
					}
				}
				else
				{
					return "0";
				}
			}
		}
	}
	std::string printPolar()
	{
		//return (radius.ToString() + " cos (" + angle.ToString() + ")" + " + " + radius.ToString() + "i " + "sin(" + angle.ToString() + ")");
		if (radius != 0)
		{
			return (std::to_string(radius) + " |_ " + std::to_string(angle)+ "°");
		}
		else
		{
			return "0";
		}
	};

	ComplexGeneric operator+ (const ComplexGeneric& rhs) {
		return ComplexGeneric(this->real + rhs.real, this->imag + rhs.imag, this->isCartesian);
	};
	ComplexGeneric operator+ (const double& rhs) {
		return ComplexGeneric(this->real + rhs, this->imag, this->isCartesian);
	};
	ComplexGeneric operator+ (const float& rhs) {
		return ComplexGeneric(this->real + rhs, this->imag, this->isCartesian);
	};
	ComplexGeneric operator+ (const int& rhs){
		return ComplexGeneric(this->real + rhs, this->imag, this->isCartesian);
	};

	ComplexGeneric& operator+= (const ComplexGeneric& rhs) {
		this->real += rhs.real;
		this->imag += rhs.imag;
		return this;
	}
	ComplexGeneric& operator+= (const double& rhs) {
		this->real += rhs;
		return this;
	}
	ComplexGeneric& operator+= (const float& rhs) {
		this->real += rhs;
		return this;
	}
	ComplexGeneric& operator+= (const int& rhs) {
		this->real += rhs;
		return this;
	}
	
	ComplexGeneric operator- (const ComplexGeneric& rhs) {
		return ComplexGeneric(this->real - rhs.real, this->imag - rhs.imag, this->isCartesian);
	};
	ComplexGeneric operator- (const double& rhs) {
		return ComplexGeneric(this->real - rhs, this->imag, this->isCartesian);
	};
	ComplexGeneric operator- (const float& rhs) {
		return ComplexGeneric(this->real - rhs, this->imag, this->isCartesian);
	};
	ComplexGeneric operator- (const int& rhs) {
		return ComplexGeneric(this->real - rhs, this->imag, this->isCartesian);
	};

	ComplexGeneric& operator-= (const ComplexGeneric& rhs) {
		this->real -= rhs.real;
		this->imag -= rhs.imag;
		return this;
	}
	ComplexGeneric& operator-= (const double& rhs) {
		this->real -= rhs;
		return this;
	}
	ComplexGeneric& operator-= (const float& rhs) {
		this->real -= rhs;
		return this;
	}
	ComplexGeneric& operator-= (const int& rhs) {
		this->real -= rhs;
		return this;
	}
	
	ComplexGeneric operator* (const ComplexGeneric& rhs){
		if (isCartesian == false)
			return ComplexGeneric(this->radius * rhs.radius, this->angle + rhs.angle, this->isCartesian);
		else
			return ComplexGeneric(this->real * rhs.real + this->imag * rhs.imag, this->real * rhs.imag + this->imag * rhs.real, this->isCartesian);
	};
	ComplexGeneric operator* (const double& rhs) {
		if (isCartesian == false)
			return ComplexGeneric(this->radius * rhs, this->angle, this->isCartesian);
		else
			return ComplexGeneric(this->real * rhs, this->imag * rhs, this->isCartesian);
	};
	ComplexGeneric operator* (const float& rhs) {
		if (isCartesian == false)
			return ComplexGeneric(this->radius * rhs, this->angle, this->isCartesian);
		else
			return ComplexGeneric(this->real * rhs, this->imag * rhs, this->isCartesian);
	};
	ComplexGeneric operator* (const int& rhs) {
		if (isCartesian == false)
			return ComplexGeneric(this->radius * rhs, this->angle, this->isCartesian);
		else
			return ComplexGeneric(this->real * rhs, this->imag * rhs, this->isCartesian);
	};

	ComplexGeneric& operator*= (const ComplexGeneric& rhs) {
		if (isCartesian == false) {
			this->radius *= rhs.radius;
			this->angle *= rhs.radius;
			return this;
		}
		else
		{
			this->real = this->real * rhs.real + this->imag * rhs.imag;
			this->imag = this->real * rhs.imag + this->imag * rhs.real;
			return this;
		}
	};
	ComplexGeneric& operator*= (const double& rhs) {
		if (isCartesian == false)
		{
			this->radius *= rhs;
			return this;
		}
		else
		{
			this->real *= rhs;
			this->imag *= rhs;
			return this;
		}
	};
	ComplexGeneric& operator*= (const float& rhs) {
		if (isCartesian == false)
		{
			this->radius *= rhs;
			return this;
		}
		else
		{
			this->real *= rhs;
			this->imag *= rhs;
			return this;
		}
	};
	ComplexGeneric& operator*= (const int& rhs) {
		if (isCartesian == false)
		{
			this->radius *= rhs;
			return this;
		}
		else
		{
			this->real *= rhs;
			this->imag *= rhs;
			return this;

		}
	};
	
	//LOOKS LIKE DIVISION YIELDS A LITTLE ERROR ON THE ANGLE
	ComplexGeneric operator/ (const ComplexGeneric& rhs){
		if(isCartesian == false)
			return ComplexGeneric(this->radius / rhs.radius, this->angle - rhs.angle, this->isCartesian);
		else {
			double real = (this->real * rhs.real) + (this->imag * rhs.imag);
			double imag = (this->imag * rhs.real) - (this->real * rhs.imag);
			double divisor = pow(rhs.real, 2) + pow(rhs.imag, 2);
			return ComplexGeneric(real / divisor, imag / divisor, this->isCartesian);
		}
	};
	ComplexGeneric operator/ (const double& rhs) {
		if (isCartesian == false)
			return ComplexGeneric(this->radius / rhs, this->angle, this->isCartesian);
		else {
			return ComplexGeneric(this->real / rhs, this->imag / rhs, this->isCartesian);
		}
	};
	ComplexGeneric operator/ (const float& rhs) {
		if (isCartesian == false)
			return ComplexGeneric(this->radius / rhs, this->angle, this->isCartesian);
		else {
			return ComplexGeneric(this->real / rhs, this->imag / rhs, this->isCartesian);
		}
	};
	ComplexGeneric operator/ (const int& rhs) {
		if (isCartesian == false)
			return ComplexGeneric(this->radius / rhs, this->angle, this->isCartesian);
		else {
			return ComplexGeneric(this->real / rhs, this->imag / rhs, this->isCartesian);
		}
	};
	
	ComplexGeneric operator^ (const double& rhs){
		return ComplexGeneric(pow(this->radius, rhs), this->angle * rhs, this->isCartesian);
	};
	ComplexGeneric operator^ (const float& rhs) {
		return ComplexGeneric(pow(this->radius, rhs), this->angle * rhs, this->isCartesian);
	};
	ComplexGeneric operator^ (const int& rhs) {
		return ComplexGeneric(pow(this->radius, rhs), this->angle * rhs, this->isCartesian);
	};

	//ADD /=, <, <=, >, >=, ==, copy, shallow copy, move
private:
	T real;
	T imag;
	T radius;
	T angle;
	bool isCartesian;
};

typedef ComplexGeneric<double> ComplexD;
typedef ComplexGeneric<float> ComplexF;