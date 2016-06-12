#include"problem.h"

Problem::Problem() {

    //The Englishman lives in the red house.
    colorNationality[RED] = ENGLISH;
    colorNationality[GREEN] = colorNationality[RED] - colorNationality[GREEN];
    colorNationality[BLUE] = colorNationality[RED] - colorNationality[BLUE];
    colorNationality[YELLOW] = colorNationality[RED] - colorNationality[YELLOW];
    colorNationality[WHITE] = colorNationality[RED] - colorNationality[WHITE];

    //The Spaniard owns the dog.
    petsNationality[DOG] = SPANISH;

    //Coffee is drunk in the green house.
    drinksColors[COFFEE] = GREEN;

    //The Ukrainian drinks tea.
    drinksNationality[TEA] = UKRANIAN;

    //The Old Gold smoker owns snails.
    petsCigarettes[SNAILS] = OLD_GOLD;

    //Kools are smoked in the yellow house.
    cigarettesColors[KOOLS] = YELLOW;

    //Milk is drunk in the middle house.
    drinksPosition[MILK] = THIRD;

    //The Norwegian lives in the first house.
    positionNationality[NORWEGIAN] = FIRST;

    //The Lucky Strike smoker drinks orange juice.
    cigarettesDrinks[LUCKY_STRIKE] = OJ;

    // The Japanese smokes Parliaments.
    nationalityCigarettes[JAPANESE] = PARLIAMENTS;
}