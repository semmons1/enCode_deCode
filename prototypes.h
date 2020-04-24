#ifndef PROTOTYPES_H
#define PROTOTYPES_H


#include <stdio.h>
#include <stdbool.h>

struct stats{
    char characterName[32];
    char characterClass[32]; //Barbarian, mage, necromancer, bard, warrior?
    char preferredWeapon[32];
    int stats[6]; //Should be strength, dexterity, constitution, intelligence, wisdom, and charisma scores
    double height;
    float hitPoints;
    bool isQuestLeader;
    struct stats *next;
};

extern void interactUser(struct stats* record);
extern void saveFile(char cN[], char cC[], char pW[], int st[], double ht, float hp, bool iQL);

#endif
