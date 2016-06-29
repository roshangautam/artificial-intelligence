//
//  Set.h
//  Zebra-Water Problem
//
//  Created by Roshan Gautam on 6/10/16.
//  Copyright © 2016 Roshan Gautam. All rights reserved.
//

#pragma once

#ifndef Set_h
#define Set_h

#include <iostream>

#endif /* Set_h */

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
	void remove(int);
	//union
	Set operator + (const Set&) const;
	//difference
	Set operator - (const Set&) const;
	//intersect
	Set intersect(const Set&) const;
	//complement
	Set complement() const;
};

