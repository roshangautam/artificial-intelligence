
#include "Set.h"

Set::Set() {
	for (int i = 0; i < UNIVERSE; ++i)
	{
		elements[i] = true;
	}
}

void Set::clear() {
	for (int i = 0; i < UNIVERSE; ++i)
	{
		elements[i] = false;
	}
}

void Set::operator = (int i) {
	clear();
	elements[i] = true;
}

bool Set::getElement(int i) const {
	return elements[i];
}

void Set::operator += (int i) {
	elements[i] = true;
}

int Set::cardinality() const {
	int cardinality = 0;
	for (int i = 0; i <= UNIVERSE; ++i)
	{
		if(elements[i]) cardinality++ ;
	}
	return cardinality;
}

void Set::print() {
	int total = cardinality();
	cout << '{';
	for (int i = 0; i <= UNIVERSE; ++i)
	{
		if(elements[i]) {
			cout << i;
			total--;
			if(total > 0) cout << ", ";
		}
	}
	cout << "}" << endl;
}

Set Set::operator + (const Set& rhSet) const {
	Set result;
	for (int i = 0; i <= UNIVERSE; ++i)
	{
		if(elements[i] || rhSet.getElement(i)) result += i;
	}
	return result;
}

Set Set::operator - (const Set& rhSet) const {
	Set result;
	for (int i = 0; i <= UNIVERSE; ++i)
	{
		if(elements[i] && !rhSet.getElement(i)) result += i;
	}
	return result;
}

Set Set::intersect(const Set& rhSet) const {
	Set result;
	for (int i = 0; i <= UNIVERSE; ++i)
	{
		if(elements[i] && rhSet.getElement(i)) result += i;
	}
	return result;
}

Set Set::complement() const {
	Set result;
	for (int i = 0; i <= UNIVERSE; ++i)
	{
		if(!elements[i]) result += i;
	}
	return result;
}