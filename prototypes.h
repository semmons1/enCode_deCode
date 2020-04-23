#ifndef PROTOTYPES_H
#define PROTOTYPES_H


#include <stdio.h>
#include <stdbool.h>

struct stats{
    char characterName[35];
    char characterClass[35]; //Barbarian, mage, necromancer, bard, warrior?
    char preferredWeapon[35];
    int stats[6]; //Should be strength, dexterity, constitution, intelligence, wisdom, and charisma scores
    double height;
    float hitPoints;
    bool isQuestLeader;
    struct stats *next;
};

extern void interactUser(char cN[], char cC[], char pW[], int st[], double ht, float hp, bool iQL);
extern void saveFile(char cN[], char cC[], char pW[], int st[], double ht, float hp, bool iQL);

#endif
