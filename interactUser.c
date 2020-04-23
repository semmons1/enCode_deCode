#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "saveFile.h"
#define MAX_CHAR_LIMIT 35

void interactUser(char cN[], char cC[], char pW[], int st[], double ht, float hp, bool iQL) {

    char *descriptions[] = {"Strength", "Dexterity", "Constitution", "Intelligence", "Wisdom", "Charisma"};
    char leaderResponse[4];

    printf("What is your player name?: ");
    fgets(cN, MAX_CHAR_LIMIT, stdin);
    printf("What is your player class? (Warrior, Bard, Mage etc.?): ");
    fgets(cC, MAX_CHAR_LIMIT, stdin);
    printf("What is your preferred weapon?: ");
    fgets(pW, MAX_CHAR_LIMIT, stdin);
    printf("Are you the quest leader? ");
    fgets(leaderResponse, 4, stdin);
    
    if (strcmp("Yes", leaderResponse) == 0) {
        iQL = true;
    }
    else if (strcmp("yes", leaderResponse) == 0) {
        iQL = true; 
    }

    printf("What is your player height? (Enter as decimal value, e.g. '5.9'): ");
    scanf("%f", &ht);
    printf("What is your base hitpoint count? (Enter as number): ");
    scanf("%f", &hp);
   
   for (int i = 0; i < 6; i++) {
        char *pos = descriptions[i];
        printf("What is your %s score? (0-10): ", pos);
        scanf("%d", &st[i]);
    }

    saveFile(cN, cC, pW, st, ht, hp, iQL);
    
}