#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "prototypes.h"
#define MAX_CHAR_LIMIT 35

void interactUser(struct Stats* record) {

    Stats* current = NULL;
    record->next = NULL;
    current = &record;//head of the linked list

    char *descriptions[] = {"Strength", "Dexterity", "Constitution", "Intelligence", "Wisdom", "Charisma"};
    char leaderResponse[4];
    
    printf("What is your player name?: ");
    fgets(current->characterName, MAX_CHAR_LIMIT, stdin);
    
    current->next = calloc(1,sizeof(struct Stats));
    current = current->next;

    printf("What is your player class? (Warrior, Bard, Mage etc.?): ");
    fgets(current->characterClass, MAX_CHAR_LIMIT, stdin);

    current->next = calloc(1,sizeof(struct Stats));
    current = current->next;

    printf("What is your preferred weapon?: ");
    fgets(current->preferredWeapon, MAX_CHAR_LIMIT, stdin);

    current -> next = calloc(1,sizeof(struct Stats));
    current = current -> next;

    printf("What is your primary language? (English, Spanish, Reptilian?) ");
    fgets(current -> primaryLanguage, MAX_CHAR_LIMIT, stdin);
    
    // TODO add no as a possible answer.
    // Done with else catch

    current->next = calloc(1,sizeof(struct Stats));
    current = current->next;

    printf("Are you the quest leader? ");
    fgets(leaderResponse, 4, stdin);
    
    if (strcmp("Yes", leaderResponse) == 0) {
        current->isQuestLeader = 1;
    }
    else if (strcmp("yes", leaderResponse) == 0) {
        current->isQuestLeader = 1; 
    }
    else {
        current->isQuestLeader = 0;
    }

    current->next = calloc(1,sizeof(struct Stats));
    current = current->next;

    printf("What is your player height? (Enter as decimal value, e.g. '5.9'): ");
    scanf("%lf", &current->height);
    

    current->next = calloc(1,sizeof(struct Stats));
    current = current->next;
    
    
    printf("What is your base hitpoint count? (Enter as number): ");
    scanf("%f", &current->hitPoints);
    current->next = calloc(1,sizeof(struct Stats));
    current = current->next;
   
   for (int i = 0; i < 6; i++) {
        char *pos = descriptions[i];
        printf("What is your %s score? (0-10): ", pos);
        scanf("%d", &current->stats[i]);
    }
    
    current -> next = calloc(1,sizeof(struct Stats));
    current = current -> next;

    printf("What is your desired challenge level? (0-50) ");
    scanf("%d", &current -> challengeLevel);

    current -> next = calloc(1,sizeof(struct Stats));
    current = current -> next;

    printf("What is your armor class? (0-10) ");
    scanf("%d", &current -> armorClass);
           
    saveFile(&record);
}
