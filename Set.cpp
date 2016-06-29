//
//  Set.cpp
//  Zebra-Water Problem
//
//  Created by Roshan Gautam on 6/10/16.
//  Copyright © 2016 Roshan Gautam. All rights reserved.
//

#ifndef Set_cpp
#define Set_cpp

#include "Set.h"

#endif /* Set_cpp */

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

void Set::remove(int i) {
	elements[i] = false;
}

void Set::operator = (int i) {
	clear();
	elements[i] = true;
}

bool Set::memberOf(int i) const {
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
	cout << '{';
	for (int i = 0; i < UNIVERSE; ++i)
	{
		cout << elements[i];
		if(i < UNIVERSE - 1) cout << ", ";
	}
	cout << "}" << endl;
}

Set Set::operator + (const Set& rhSet) const {
	Set result;
	for (int i = 0; i <= UNIVERSE; ++i)
	{
		if(elements[i] || rhSet.memberOf(i)) result += i;
	}
	return result;
}

Set Set::operator - (const Set& rhSet) const {
	Set result;
	for (int i = 0; i <= UNIVERSE; ++i)
	{
		if(elements[i] && !rhSet.memberOf(i)) result += i;
	}
	return result;
}

Set Set::intersect(const Set& rhSet) const {
	Set result;
	for (int i = 0; i <= UNIVERSE; ++i)
	{
		if(elements[i] && rhSet.memberOf(i)) result += i;
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