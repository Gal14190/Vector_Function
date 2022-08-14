#include "Vector.h"

Vector::Vector(int n)
{
	this->elements = new double[n];		// set vector object
	this->size = n;		// set vector lenght

	memset(this->elements, 0, n * sizeof(double)); // set zero value for all columns
}

Vector::Vector(double a[], int n):Vector(n)
{
	// copy all columns value from vector a
	for (int i = 0; i < n; i++)
		(*this)[i] = a[i];
}

Vector::~Vector()
{
}

int Vector::getSize()
{
	return this->size;
}

double& Vector::dot(Vector& v)
{
	double result = 0;

	// check if the two vectors valid with the same length
	if (this->size != v.size)
	{
		cout << "INVALID. Vectors with different length." << endl;
		exit(ERROR);
	}

	// cartesian product
	for (int i = 0; i < this->size; i++)
		result += (*this)[i] * v[i];

	return result;
}

double& Vector::operator[] (int ind)
{
	double ERROR_REF = ERROR;

	// check if the index valid
	if (ind >= getSize())
		return ERROR_REF;

	// return the value
	return this->elements[ind];
}

Vector& Vector::operator+ (double d) const
{
	Vector result(this->elements, this->size);

	// add every column with scaler
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

	// duplicate every column with scaler
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

	// check if the two vectors valid with the same length
	if (this->size != v.size)
	{
		cout << "INVALID. Vectors with different length." << endl;
		exit(ERROR);
	}
		
	// duplicate every column with vector value
	for (int i = 0; i < result.getSize(); i++)
		result[i] *= v.elements[i];

	return result;
}

bool Vector::operator== (Vector& v)
{
	// check if the two vectors valid with the same length
	if (this->getSize() != v.getSize())
		return false;

	// check for diffrence value
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