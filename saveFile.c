#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "prototypes.h"
//Will probably need more imports

void saveFile(struct Stats* record) {
    FILE *fp;
    fp = fopen("outfile.txt", "w");

    char temp[50];
    char s[10] = {'0','x', '0', '0', '4', '0', '1', '1', 'F', '3'};//Meant to look like a hex address
    

    //write charactername
    memcpy(temp, record -> characterName, 35);

    size_t len = strlen(temp);
    
    for (int i = 0; i < len; i++) {
        temp[i] = temp[i] ^ s[i % (sizeof(s) / sizeof(char))];
    }

    fputs(temp, fp);
    
    //Select next member variable, rinse and repeat. 
    //kinda primitive, but can't see any other way :/
    record = record -> next;
       
    memcpy(temp, record -> characterClass, 35);

    len = strlen(temp);

    for (int i = 0; i < len; i++) {
        temp[i] = temp[i] ^ s[i % (sizeof(s) / sizeof(char))];
    }

    fputs(temp, fp);

    record = record -> next;
       
    memcpy(temp, record -> preferredWeapon, 35);
    
    len = strlen(temp);

    for (int i = 0; i < len; i++) {
        temp[i] = temp[i] ^ s[i % (sizeof(s) / sizeof(char))];
    }

    fputs(temp, fp);

    record = record -> next;

    memcpy(temp, record -> primaryLanguage, 35);

    len = strlen(temp);

    for (int i = 0; i < len; i++) {
        temp[i] = temp[i] ^ s[i % (sizeof(s) / sizeof(char))];
    }

    fputs(temp, fp);

    record = record -> next;
      
    sprintf(temp, "%d", record -> isQuestLeader);//send XOR'd non char values through a buffer so that they can be written
    
    len = strlen(temp);

    for (int i = 0; i < len; i++) {
        temp[i] = temp[i] ^ s[i % (sizeof(s) / sizeof(char))];
    }

    fputs(temp, fp);

    record = record -> next;

    sprintf(temp, "%lf", record -> height);
    
    len = strlen(temp);

    for (int i = 0; i < len; i++) {
        temp[i] = temp[i] ^ s[i % (sizeof(s) / sizeof(char))];
    }

    fputs(temp, fp);

    record = record -> next;

    sprintf(temp, "%f", record -> hitPoints);
    
    len = strlen(temp);

    for (int i = 0; i < len; i++) {
        temp[i] = temp[i] ^ s[i % (sizeof(s) / sizeof(char))];
    }

    fputs(temp, fp);

    record = record -> next;

    for (int i = 0; i < 6; i++) {
        sprintf(temp, "%d", record -> stats[i]);
        len = strlen(temp);
        for (int j = 0; j < len; j++) {
            temp[j] = temp[j] ^ s[j % (sizeof(s) / sizeof(char))];

        }
        fputs(temp, fp);
    }

    record = record -> next;

    sprintf(temp, "%d", record -> challengeLevel);

    len = strlen(temp);

    for (int i = 0; i < len; i++) {
        temp[i] = temp[i] ^ s[i % (sizeof(s) / sizeof(char))];
    }

    fputs(temp, fp);

    record = record -> next;

    sprintf(temp, "%d", record -> armorClass);

    len = strlen(temp);

    for (int i = 0; i < len; i++) {
        temp[i] = temp[i] ^ s[i % (sizeof(s) / sizeof(char))];
    }

    fputs(temp, fp);
    fclose(fp);


    printf("%02x\n", hashCheck());

    
      
    return;
}