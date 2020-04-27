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
    
    // TODO add no as a possible answer.
    // Done with else catch

    current->next = calloc(1,sizeof(struct Stats));
    current = current->next;

    printf("Are you the quest leader? ");
    fgets(leaderResponse, 4, stdin);
    
    if (strcmp("Yes", leaderResponse) == 0) {
        current->isQuestLeader = 1;;
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
    
    
    // Check to see if data is loaded properly into nodes.
    current = &record; 
    printf("%s", current->characterName);
    current = current -> next;
    printf("%s", current->characterClass);
    current = current -> next;
    printf("%s", current->preferredWeapon);
    current = current -> next;
    printf("%d\n", current->isQuestLeader);
    current = current -> next;
    printf("%f\n", current->height);
    current = current -> next;
    printf("%f\n", current->hitPoints);
    current = current -> next;
    for (int i = 0; i < 6; i++) {
        printf("%d\n", current -> stats[i]);
    }

   
   
    //This would work if we are storing multiple pieces of data in a single data type i.E:
    //int data, and we keep adding values to this. However, because all of our variables are
    //independent and have different data types, we have to manually increment through them
    //and call the individual member variables, as seen above.
    /*for(current = &record; current != NULL; current = current->next)
    {   
        printf(current);
        if(current->characterName != NULL)
            printf("%s\n", current->characterName);
        else if (current->characterClass != NULL)
            printf("%s\n", current->characterClass);
        else if(current->preferredWeapon != NULL)
            printf("%s\n", current->preferredWeapon);
        else if(current->isQuestLeader !=NULL)
            printf("%s\n", current->isQuestLeader);
        else if(current->height > 0)
            printf("%s\n", current->height);
        else if(current->hitPoints > 0)
            printf("%s\n", current->hitPoints);
        else
            printf("%s\n", current);
    }*/


    //struct Stats record;
    saveFile(&record);
    
    //printf("%s", getStats(&record, 2) -> preferredWeapon);
}
