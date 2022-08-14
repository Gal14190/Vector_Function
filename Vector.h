#pragma once
#include <iostream>

#define ERROR -999

using namespace std;

class Vector
{
	friend ostream& operator<< (ostream& out, Vector& v);

	friend Vector& operator+ (double d, Vector& v);
	friend Vector& operator* (double d, Vector& v);

private:
	double* elements;
	int size;

public:
	Vector(
		int n = 0
	);

	Vector(
		double a[]
		,int n
	);

	~Vector(
	);

	int getSize(
	);

	double& dot(
		Vector& v
	);

	double& operator[] (int ind);

	Vector& operator+ (double d) const;
	Vector& operator* (double d) const;
	Vector& operator* (const Vector& v) const;

	bool operator== (Vector& v);
};