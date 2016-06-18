//
//  Problem.cpp
//  Zebra-Water Problem
//
//  Created by Roshan Gautam on 6/10/16.
//  Copyright © 2016 Roshan Gautam. All rights reserved.
//

#ifndef Problem_cpp
#define Problem_cpp

#include"Problem.h"

#endif /* Problem_cpp */

Problem::Problem() {
    cout << "Zebra Water Problem Initialized" << endl;

    //The Englishman lives in the red house.
    colorsNationality[RED] = ENGLISH;
    colorsNationality[GREEN] = colorsNationality[RED] - colorsNationality[GREEN];
    colorsNationality[BLUE] = colorsNationality[RED] - colorsNationality[BLUE];
    colorsNationality[YELLOW] = colorsNationality[RED] - colorsNationality[YELLOW];
    colorsNationality[WHITE] = colorsNationality[RED] - colorsNationality[WHITE];

    //The Spaniard owns the dog.
    petsNationality[DOG] = SPANISH;
    petsNationality[HORSE] = petsNationality[DOG] - petsNationality[HORSE];
    petsNationality[SNAILS] = petsNationality[DOG] - petsNationality[SNAILS];
    petsNationality[FOX] = petsNationality[DOG] - petsNationality[FOX];
    petsNationality[ZEBRA] = petsNationality[DOG] - petsNationality[ZEBRA];

    //Coffee is drunk in the green house.
    drinksColors[COFFEE] = GREEN;
    drinksColors[MILK] = drinksColors[COFFEE] - drinksColors[MILK];
    drinksColors[WATER] = drinksColors[COFFEE] - drinksColors[WATER];
    drinksColors[OJ] = drinksColors[COFFEE] - drinksColors[OJ];
    drinksColors[TEA] = drinksColors[COFFEE] - drinksColors[TEA];

    //The Ukrainian drinks tea.
    drinksNationality[UKRANIAN] = TEA;
    drinksNationality[NORWEGIAN] = drinksNationality[UKRANIAN] - drinksNationality[NORWEGIAN];
    drinksNationality[ENGLISH] = drinksNationality[UKRANIAN] - drinksNationality[ENGLISH];
    drinksNationality[SPANISH] = drinksNationality[UKRANIAN] - drinksNationality[SPANISH];
    drinksNationality[JAPANESE] = drinksNationality[UKRANIAN] - drinksNationality[JAPANESE];

    //The Old Gold smoker owns snails.
    petsCigarettes[SNAILS] = OLD_GOLDS;
    petsCigarettes[DOG] = petsCigarettes[SNAILS] - petsCigarettes[DOG];
    petsCigarettes[FOX] = petsCigarettes[SNAILS] - petsCigarettes[FOX];
    petsCigarettes[HORSE] = petsCigarettes[SNAILS] - petsCigarettes[HORSE];
    petsCigarettes[ZEBRA] = petsCigarettes[SNAILS] - petsCigarettes[ZEBRA];

    //Kools are smoked in the yellow house.
    cigarettesColors[KOOLS] = YELLOW;
    cigarettesColors[LUCKY_STRIKE] = cigarettesColors[KOOLS] - cigarettesColors[LUCKY_STRIKE];
    cigarettesColors[OLD_GOLDS] = cigarettesColors[KOOLS] - cigarettesColors[OLD_GOLDS];
    cigarettesColors[CHESTERFIELDS] = cigarettesColors[KOOLS] - cigarettesColors[CHESTERFIELDS];
    cigarettesColors[PARLIAMENTS] = cigarettesColors[KOOLS] - cigarettesColors[PARLIAMENTS];


    //Milk is drunk in the middle house.
    drinksPosition[MILK] = THIRD;
    drinksPosition[OJ] = drinksPosition[MILK] - drinksPosition[MILK];
    drinksPosition[WATER] = drinksPosition[MILK] - drinksPosition[WATER];
    drinksPosition[TEA] = drinksPosition[MILK] - drinksPosition[TEA];
    drinksPosition[COFFEE] = drinksPosition[MILK] - drinksPosition[COFFEE];

    //The Norwegian lives in the first house.
    positionNationality[FIRST] = NORWEGIAN;
    positionNationality[SECOND] = positionNationality[FIRST] - positionNationality[SECOND];
    positionNationality[THIRD] = positionNationality[FIRST] - positionNationality[THIRD];
    positionNationality[FOURTH] = positionNationality[FIRST] - positionNationality[FOURTH];
    positionNationality[FIFTH] = positionNationality[FIRST] - positionNationality[FIFTH];

    //The Lucky Strike smoker drinks orange juice.
    cigarettesDrinks[LUCKY_STRIKE] = OJ;
    cigarettesDrinks[CHESTERFIELDS] = cigarettesDrinks[LUCKY_STRIKE] - cigarettesDrinks[CHESTERFIELDS];
    cigarettesDrinks[KOOLS] = cigarettesDrinks[LUCKY_STRIKE] - cigarettesDrinks[KOOLS];
    cigarettesDrinks[PARLIAMENTS] = cigarettesDrinks[LUCKY_STRIKE] - cigarettesDrinks[PARLIAMENTS];
    cigarettesDrinks[OLD_GOLDS] = cigarettesDrinks[LUCKY_STRIKE] - cigarettesDrinks[OLD_GOLDS];

    // The Japanese smokes Parliaments.
    nationalityCigarettes[JAPANESE] = PARLIAMENTS;
    nationalityCigarettes[NORWEGIAN] = nationalityCigarettes[JAPANESE] - nationalityCigarettes[NORWEGIAN];
    nationalityCigarettes[ENGLISH] = nationalityCigarettes[JAPANESE] - nationalityCigarettes[ENGLISH];
    nationalityCigarettes[SPANISH] = nationalityCigarettes[JAPANESE]- nationalityCigarettes[SPANISH];
    nationalityCigarettes[UKRANIAN] = nationalityCigarettes[JAPANESE] - nationalityCigarettes[UKRANIAN];
}