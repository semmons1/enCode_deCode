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
    int d = 0; //XOR for ints and floats
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

    //Stuck here, keeps returning zeroes from int array
    //i'm probably not referencing properly, but I haven't
    //figured how to reference this memeber properly here.
    record = record -> next;
    
    for (int i = 0; i < 6; i++) {
       
       d ^= record -> stats[i];
       printf("%d", d);
    }

    for (int i = 0; i < 6; i++) {
        record -> stats[i] = d ^ record -> stats[i];
        printf("%d", record -> stats[i]);
    }
    
    return;
}