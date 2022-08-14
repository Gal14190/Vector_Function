#include "Vector.h"

Vector::Vector(int n)
{
	this->elements = new double[n];
	this->size = n;

	memset(this->elements, 0, n * sizeof(double));
}

Vector::Vector(double a[], int n):Vector(n)
{
	for (int i = 0; i < n; i++)
		(*this)[i] = a[i];
}

Vector::~Vector()
{
	//delete this->elements;  // Base type (double) destroy automatic
}

int Vector::getSize()
{
	return this->size;
}

double& Vector::dot(Vector& v)
{
	double result = 0;

	for (int i = 0; i < this->size; i++)
		result += (*this)[i] * v[i];

	return result;
}

double& Vector::operator[] (int ind)
{
	double ERROR_REF = ERROR;

	if (ind >= getSize())
		return ERROR_REF;

	return this->elements[ind];
}

Vector& Vector::operator+ (double d) const
{
	Vector result(this->elements, this->size);

	for (int i = 0; i < result.size; i++)
		result[i] += d;

	return result;
}

Vector& operator+ (double d, Vector& v) 
{
	return (v + d);
}

Vector& Vector::operator* (double d) const
{
	Vector result(this->elements, this->size);

	for (int i = 0; i < result.getSize(); i++)
		result[i] *= d;

	return result;
}

Vector& operator* (double d, Vector& v)
{
	return (v * d);
}

Vector& Vector::operator* (const Vector& v) const
{
	Vector result(this->elements, this->size);

	for (int i = 0; i < result.getSize(); i++)
		result[i] *= v.elements[i];

	return result;
}

bool Vector::operator== (Vector& v)
{
	if (this->getSize() != v.getSize())
		return false;

	for (int i = 0; i < this->getSize(); i++)
	{
		if ((*this)[i] != v[i])
			return false;
	}

	return true;
}

ostream& operator<< (ostream& out, Vector& v)
{
	out << "[";
	for (int i = 0; i < v.getSize(); i++)
	{
		out << v[i];

		if (i < v.getSize() - 1)
			out << ",";
	}
	out << "]";

	return out;
}