#pragma once
#include <iostream>

#define ERROR -999

using namespace std;

class Vector
{
	/* OPERATORS OVERRIDE */

	/**
	* Output all vector values into the user console
	*/
	friend ostream& operator<< (ostream& out, Vector& v);

	/**
	* Add scaler with vector
	*/
	friend Vector& operator+ (double d, Vector& v);
	/**
	* Duplicate scaler with vector
	*/
	friend Vector& operator* (double d, Vector& v);

private:
	double* elements;	// vector values array
	int size;			// vector length

public:
	/**
	* c'tors
	*/
	Vector(
		int n = 0	// vector size
	);

	Vector(
		double a[]	// vector array
		,int n		// vector size
	);

	~Vector(
	);

	/**
	* Get vector size
	* 
	* @return vector size
	*/
	int getSize(
	);

	/**
	* Dot product
	* 
	* @return cartesian product
	*/
	double dot(
		Vector& v	// vector two
	);

	/* OPERATOR OVERRIDE */

	/**
	* Get column value by index
	*/
	double& operator[] (int ind);	

	/**
	* Add vector with scaler
	*/
	Vector& operator+ (double d) const;
	/**
	* Duplicate vector with scaler
	*/
	Vector& operator* (double d) const;
	/**
	* Duplicate two vectors
	*/
	Vector& operator* (const Vector& v) const;

	/**
	* Comparison two vectors
	*/
	bool operator== (Vector& v);
};