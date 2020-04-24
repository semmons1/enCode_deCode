#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "prototypes.h"
#define MAX_CHAR_LIMIT 35

void interactUser(struct stats* record) {

    
    struct stats* current = NULL;
    record->next = NULL;
    current = &record;//head of the linked list

    char *descriptions[] = {"Strength", "Dexterity", "Constitution", "Intelligence", "Wisdom", "Charisma"};
    char leaderResponse[4];
    
    //head = calloc(1,sizeof(struct stats));
    //head
    
    printf("What is your player name?: ");
    fgets(current->characterName, MAX_CHAR_LIMIT, stdin);
    //current = record->characterName;
    current->next = calloc(1,sizeof(struct stats));
    current = current->next;

    printf("What is your player class? (Warrior, Bard, Mage etc.?): ");
    fgets(current->characterClass, MAX_CHAR_LIMIT, stdin);
    //current = record->characterClass;
    current->next = calloc(1,sizeof(struct stats));
    current = current->next;

    printf("What is your preferred weapon?: ");
    fgets(current->preferredWeapon, MAX_CHAR_LIMIT, stdin);
    // TODO add no as a possible answer.
    printf("Are you the quest leader? ");
    fgets(leaderResponse, 4, stdin);
    
    if (strcmp("Yes", leaderResponse) == 0) {
        current->isQuestLeader = true;
    }
    else if (strcmp("yes", leaderResponse) == 0) {
        current->isQuestLeader = true; 
    }

    current->next = calloc(1,sizeof(struct stats));
    current = current->next;

    printf("What is your player height? (Enter as decimal value, e.g. '5.9'): ");
    scanf("%lf", &current->height);
    current->next = calloc(1,sizeof(struct stats));
    current = current->next;
    
    
    printf("What is your base hitpoint count? (Enter as number): ");
    scanf("%f", &current->hitPoints);
    current->next = calloc(1,sizeof(struct stats));
    current = current->next;
   
   for (int i = 0; i < 6; i++) {
        char *pos = descriptions[i];
        printf("What is your %s score? (0-10): ", pos);
        scanf("%d", &current->stats[i]);
    }
    

    
    for(current = &record; current != NULL; current = current->next)
    {   
        if(current->characterName != NULL)
            printf("%s\n", current);
        else if (current->characterClass != NULL)
            printf("%s\n", current);
        else if(current->preferredWeapon != NULL)
            printf("%s\n", current);
        else if(current->isQuestLeader !=NULL)
            printf("%s\n", current);
        else if(current->height > 0)
            printf("%s\n", current);
        else if(current->hitPoints > 0)
            printf("%s\n", current);
        else
            printf("%s\n", current);
    }


    struct stats params;
    //saveFile(cN, cC, pW, st, ht, hp, iQL);
    
}
