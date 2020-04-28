#ifndef PROTOTYPES_H
#define PROTOTYPES_H


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stats
{
    char characterName[35];
    char characterClass[35]; //Barbarian, mage, necromancer, bard, warrior?
    char preferredWeapon[35];
    int stats[6]; //Should be strength, dexterity, constitution, intelligence, wisdom, and charisma scores
    double height;
    float hitPoints;
    bool isQuestLeader;
    struct Stats* next;
} Stats;


extern void interactUser(struct Stats* record);
extern void saveFile(struct Stats* record);

#endif