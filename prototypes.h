#ifndef PROTOTYPES_H
#define PROTOTYPES_H


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stats
{
    char characterName[32];
    char characterClass[32]; //Barbarian, mage, necromancer, bard, warrior?
    char preferredWeapon[32];
    int stats[6]; //Should be strength, dexterity, constitution, intelligence, wisdom, and charisma scores
    double height;
    float hitPoints;
    bool isQuestLeader;
    struct Stats* next;
} Stats;


extern void interactUser(struct Stats* record);
extern void saveFile(struct Stats* record);

#endif