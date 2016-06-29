//
//  Enums.h
//  Zebra-Water Problem
//
//  Created by Roshan Gautam on 6/10/16.
//  Copyright © 2016 Roshan Gautam. All rights reserved.
//

#pragma once

#ifndef Enums_h
#define Enums_h

#include <iostream>

#endif /* Enums_h */

enum NATIONALITY
{
    ENGLISH = 0,
    SPANISH = 1,
    UKRANIAN = 2,
    JAPANESE = 3,
    NORWEGIAN = 4
};


enum PET
{
    DOG = 0,
    HORSE = 1,
    FOX = 2,
    ZEBRA = 3,
    SNAILS = 4
};


enum DRINK
{
    COFFEE = 0,
    TEA = 1,
    WATER = 2,
    MILK = 3,
    OJ = 4
};


enum CIGARETTE
{
    OLD_GOLDS = 0,
    KOOLS = 1,
    CHESTERFIELDS = 2,
    LUCKY_STRIKE = 3,
    PARLIAMENTS = 4
};


enum POSITION
{
    FIRST = 0,
    SECOND = 1,
    THIRD = 2,
    FOURTH = 3,
    FIFTH = 4
};


enum COLOR
{
    GREEN = 0,
    RED = 1,
    BLUE = 2,
    YELLOW = 3,
    IVORY = 4
};

enum Relation
{
    RIGHTOF,
    NEXTTO
};


struct BinaryConstraint
{
    Set* variable1;
    Set* variable2;
    Relation relation;
};
