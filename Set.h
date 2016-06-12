#include<iostream>

using namespace std;

class Set {
	bool elements[10];
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

