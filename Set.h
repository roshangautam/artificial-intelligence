#include<iostream>

using namespace std;

const int UNIVERSE = 5; 

class Set {
	bool elements[UNIVERSE];
public:
	Set();	
	bool memberOf(int) const;
	void operator = (int);
	void operator += (int);
	//
	int cardinality() const;
	void print();
	void clear();
	
	//union
	Set operator + (const Set&) const;
	//difference
	Set operator - (const Set&) const;
	//intersect
	Set intersect(const Set&) const;
	//complement
	Set complement() const;
};

