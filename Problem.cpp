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
    colorsNationality[RED].clear();
    colorsNationality[RED] = ENGLISH;
    colorsNationality[GREEN] = colorsNationality[GREEN] - colorsNationality[RED];
    colorsNationality[BLUE] = colorsNationality[BLUE] - colorsNationality[RED];
    colorsNationality[YELLOW] = colorsNationality[YELLOW] -  colorsNationality[RED];
    colorsNationality[WHITE] = colorsNationality[WHITE] - colorsNationality[RED];

    //The Spaniard owns the dog.
    petsNationality[DOG] = SPANISH;
    petsNationality[HORSE] = petsNationality[HORSE] - petsNationality[DOG];
    petsNationality[SNAILS] = petsNationality[SNAILS] - petsNationality[DOG];
    petsNationality[FOX] = petsNationality[FOX] - petsNationality[DOG];
    petsNationality[ZEBRA] = petsNationality[ZEBRA] - petsNationality[DOG];

    //Coffee is drunk in the green house.
    drinksColors[COFFEE] = GREEN;
    drinksColors[MILK] = drinksColors[MILK] - drinksColors[COFFEE];
    drinksColors[WATER] = drinksColors[WATER] - drinksColors[COFFEE];
    drinksColors[OJ] = drinksColors[OJ] - drinksColors[COFFEE];
    drinksColors[TEA] = drinksColors[TEA] - drinksColors[COFFEE];

    //The Ukrainian drinks tea.
    drinksNationality[UKRANIAN] = TEA;
    drinksNationality[NORWEGIAN] = drinksNationality[NORWEGIAN] - drinksNationality[UKRANIAN];
    drinksNationality[ENGLISH] = drinksNationality[ENGLISH] - drinksNationality[UKRANIAN];
    drinksNationality[SPANISH] = drinksNationality[SPANISH] - drinksNationality[UKRANIAN];
    drinksNationality[JAPANESE] = drinksNationality[JAPANESE] - drinksNationality[UKRANIAN];

    //The Old Gold smoker owns snails.
    petsCigarettes[SNAILS] = OLD_GOLDS;
    petsCigarettes[DOG] = petsCigarettes[DOG] - petsCigarettes[SNAILS];
    petsCigarettes[FOX] = petsCigarettes[FOX] - petsCigarettes[SNAILS];
    petsCigarettes[HORSE] = petsCigarettes[HORSE] - petsCigarettes[SNAILS];
    petsCigarettes[ZEBRA] = petsCigarettes[ZEBRA] - petsCigarettes[SNAILS];

    //Kools are smoked in the yellow house.
    cigarettesColors[KOOLS] = YELLOW;
    cigarettesColors[LUCKY_STRIKE] = cigarettesColors[LUCKY_STRIKE] - cigarettesColors[KOOLS];
    cigarettesColors[OLD_GOLDS] = cigarettesColors[OLD_GOLDS] - cigarettesColors[KOOLS];
    cigarettesColors[CHESTERFIELDS] = cigarettesColors[CHESTERFIELDS] - cigarettesColors[KOOLS];
    cigarettesColors[PARLIAMENTS] = cigarettesColors[PARLIAMENTS] - cigarettesColors[KOOLS];


    //Milk is drunk in the middle house.
    drinksPosition[MILK] = THIRD;
    drinksPosition[OJ] = drinksPosition[MILK] - drinksPosition[MILK];
    drinksPosition[WATER] = drinksPosition[WATER] - drinksPosition[MILK];
    drinksPosition[TEA] = drinksPosition[TEA] - drinksPosition[MILK];
    drinksPosition[COFFEE] = drinksPosition[COFFEE] - drinksPosition[MILK];

    //The Norwegian lives in the first house.
    positionNationality[FIRST] = NORWEGIAN;
    positionNationality[SECOND] = positionNationality[SECOND] - positionNationality[FIRST];
    positionNationality[THIRD] = positionNationality[THIRD] - positionNationality[FIRST];
    positionNationality[FOURTH] = positionNationality[FOURTH] - positionNationality[FIRST];
    positionNationality[FIFTH] = positionNationality[FIFTH] - positionNationality[FIRST];

    //The Lucky Strike smoker drinks orange juice.
    cigarettesDrinks[LUCKY_STRIKE] = OJ;
    cigarettesDrinks[CHESTERFIELDS] = cigarettesDrinks[CHESTERFIELDS] - cigarettesDrinks[LUCKY_STRIKE];
    cigarettesDrinks[KOOLS] = cigarettesDrinks[KOOLS] - cigarettesDrinks[LUCKY_STRIKE];
    cigarettesDrinks[PARLIAMENTS] = cigarettesDrinks[PARLIAMENTS] - cigarettesDrinks[LUCKY_STRIKE];
    cigarettesDrinks[OLD_GOLDS] = cigarettesDrinks[OLD_GOLDS] - cigarettesDrinks[LUCKY_STRIKE];

    // The Japanese smokes Parliaments.
    nationalityCigarettes[JAPANESE] = PARLIAMENTS;
    nationalityCigarettes[NORWEGIAN] = nationalityCigarettes[NORWEGIAN] - nationalityCigarettes[JAPANESE];
    nationalityCigarettes[ENGLISH] = nationalityCigarettes[ENGLISH] - nationalityCigarettes[JAPANESE];
    nationalityCigarettes[SPANISH] = nationalityCigarettes[SPANISH] - nationalityCigarettes[JAPANESE];
    nationalityCigarettes[UKRANIAN] = nationalityCigarettes[UKRANIAN] - nationalityCigarettes[JAPANESE];
}