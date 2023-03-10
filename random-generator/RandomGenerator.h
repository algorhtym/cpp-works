#pragma once

#include <iostream>

using namespace std;

#define MAX_SIZE 100

class RandomGenerator {
private:
	int s;
	int size; 
	unsigned long long * elements;
public:
	RandomGenerator();
	RandomGenerator(int, int, int);
	RandomGenerator(const RandomGenerator&);
	~RandomGenerator();
	int& operator [] (int);
	bool operator == (RandomGenerator) const;
	bool operator != (RandomGenerator) const;
	RandomGenerator operator + (RandomGenerator); 
	RandomGenerator operator - (RandomGenerator);
	RandomGenerator operator * (RandomGenerator);
	RandomGenerator operator += (RandomGenerator);
	RandomGenerator operator -= (RandomGenerator);
	RandomGenerator operator *= (RandomGenerator);
	void operator ++ ();
	void operator ++ (int);
	void operator -- ();
	void operator -- (int);
	friend ostream& operator << (ostream&, RandomGenerator);



};