//
//  Problem.h
//  Zebra-Water Problem
//
//  Created by Roshan Gautam on 6/10/16.
//  Copyright © 2016 Roshan Gautam. All rights reserved.
//

#pragma once

#ifndef Problem_h
#define Problem_h

#include <iostream>
#include"Set.h"
#include"Enums.h"

#endif /* Problem_h */

using namespace std;

class Problem {

    Set colorsNationality[5];
    Set colorsDrinks[5];
    Set colorsPets[5];
    Set colorsCigarettes[5];
    Set colorsPosition[5];

    Set positionNationality[5];
    Set positionDrinks[5];
    Set positionPets[5];
    Set positionCigarettes[5];
    Set positionColors[5];

    Set nationalityColors[5];
    Set nationalityDrinks[5];
    Set nationalityPets[5];
    Set nationalityCigarettes[5];
    Set nationalityPosition[5];        

    Set drinksNationality[5];
    Set drinksColors[5];
    Set drinksPets[5];
    Set drinksCigarettes[5];
    Set drinksPosition[5];

    Set petsNationality[5];
    Set petsDrinks[5];
    Set petsColors[5];
    Set petsCigarettes[5];
    Set petsPosition[5];        

    Set cigarettesPosition[5];
    Set cigarettesPets[5];
    Set cigarettesColors[5];
    Set cigarettesDrinks[5];
    Set cigarettesNationality[5];

public:
    Problem();  
};

