#include<iostream>

using namespace std;

const int UNIVERSE = 5; 

class Set {
	bool elements[UNIVERSE];
public:
	Set();	
	bool getElement(int) const;
	void operator = (int);
	void operator += (int);
	int cardinality() const;
	void print();
	void clear();
	Set operator + (const Set&) const;
	Set operator - (const Set&) const;
	Set intersect(const Set&) const;
	Set complement() const;
};

