#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "prototypes.h"


void saveFile(struct Stats* record) {
    FILE *fp;
    
    fp = fopen("outfile.txt", "wb");
    

    char temp[35];
    char s[1] = { '*'};

    
    memset(temp, 0, sizeof(temp));

    //write charactername
    memcpy(temp, record->characterName, 35);
    size_t len = strlen(temp);
    
    for (int i = 0; i < len; i++) {
        temp[i] = temp[i] ^ s[i % (sizeof(s) / sizeof(char))];
    }

    fputs(temp, fp);
    memset(temp, 0, sizeof(temp));


    //Select next member variable, rinse and repeat. 
    //kinda primitive, but can't see any other way :/
    record = record -> next;
       
    memcpy(temp, record -> characterClass, 35);

    len = strlen(temp);

    for (int i = 0; i < len; i++) {
        temp[i] = temp[i] ^ s[i % (sizeof(s) / sizeof(char))];
    }

    fputs(temp, fp);
    memset(temp, 0, sizeof(temp));



    record = record -> next;
       
    memcpy(temp, record -> preferredWeapon, 35);
    
    len = strlen(temp);

    for (int i = 0; i < len; i++) {
        temp[i] = temp[i] ^ s[i % (sizeof(s) / sizeof(char))];
    }

    fputs(temp, fp);
    memset(temp, 0, sizeof(temp));



    record = record -> next;

    memcpy(temp, record -> primaryLanguage, 35);

    len = strlen(temp);

    for (int i = 0; i < len; i++) {
        temp[i] = temp[i] ^ s[i % (sizeof(s) / sizeof(char))];
    }

    fputs(temp, fp);
    


    memset(temp, 0, sizeof(temp));
    record = record -> next;
      
    sprintf(temp, "%d\n", record -> isQuestLeader);//send XOR'd non char values through a buffer so that they can be written
    
    len = strlen(temp);

    for (int i = 0; i < len; i++) {
        temp[i] = temp[i] ^ s[i % (sizeof(s) / sizeof(char))];
    }

    fputs(temp, fp);
    memset(temp, 0, sizeof(temp));
    

    record = record -> next;

    sprintf(temp, "%lf\n", record -> height);
    
    len = strlen(temp);

    for (int i = 0; i < len; i++) {
        temp[i] = temp[i] ^ s[i % (sizeof(s) / sizeof(char))];
    }

    fputs(temp, fp);
    memset(temp, 0, sizeof(temp));


    record = record -> next;

    sprintf(temp, "%f\n", record -> hitPoints);
    
    len = strlen(temp);

    for (int i = 0; i < len; i++) {
        temp[i] = temp[i] ^ s[i % (sizeof(s) / sizeof(char))];
    }

    fputs(temp, fp);
    memset(temp, 0, sizeof(temp));



    record = record -> next;

    for (int i = 0; i < 6; i++) {
        sprintf(temp, "%d\n", record -> stats[i]);
        len = strlen(temp);
        for (int j = 0; j < len; j++) {
            temp[j] = temp[j] ^ s[j % (sizeof(s) / sizeof(char))];

        }
        fputs(temp, fp);
        memset(temp, 0, sizeof(temp));


    }
    record = record -> next;

    sprintf(temp, "%d\n", record -> challengeLevel);

    len = strlen(temp);

    for (int i = 0; i < len; i++) {
        temp[i] = temp[i] ^ s[i % (sizeof(s) / sizeof(char))];
    }

    fputs(temp, fp);
    memset(temp, 0, sizeof(temp));


   

    record = record -> next;

    sprintf(temp, "%d\n", record -> armorClass);

    len = strlen(temp);

    for (int i = 0; i < len; i++) {
        temp[i] = temp[i] ^ s[i % (sizeof(s) / sizeof(char))];
    }

    fputs(temp, fp);
    memset(temp, 0, sizeof(temp));

    fclose(fp);
  
      
    return;
}
