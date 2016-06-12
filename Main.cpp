//
//  main.cpp
//  set
//
//  Created by Roshan Gautam on 06/08/16.
//  Copyright © 2016 Roshan Gautam. All rights reserved.
//


#include <iostream>
#include "Set.h"

using namespace std;


int main(int argc, char **argv) {
	Set s1, s2;
	s1 = 1;
	s1 += 2;
	s1 += 3;
	s1 += 4;
	cout << "Set A : ";s1.print();

	s2 = 3;
	s2 += 4;
	s2 += 5;
    s2 += 6;
    cout << "Set B : "; s2.print ();

	Set s3 = s1 + s2; // union
    cout << "A ∪ B : "; s3.print ();

	Set s4 = s1.intersect(s2); // intersection
    cout << "A ∩ B : "; s4.print (); 

	Set s5 = s1 - s2; // difference
    cout << "A - B : "; s5.print ();        

	Set s6 = s1.complement(); // complement
    cout << "A Complement : "; s6.print ();    

	return 0;
} 