#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "prototypes.h"
//Will probably need more imports

void saveFile(struct Stats* record) {
    FILE *fp;
    fp = fopen("outfile.txt", "w");
    char temp[50];
    char s[20] = {'A','Y', 'U', 'F', 'E', 'T', 'V', 'B', 'I','H','S','I','O','C','Z','8','1','3','6', '4'};
    memset(temp, '\0', sizeof(temp));
    strcpy(temp, record -> characterName);
    printf("%s", temp);
    size_t len = strlen(temp);
    printf("%d\n", len);
    
    
    for (int i = 0; i < len-1; i++) {
        temp[i] = temp[i] ^ s[i % (sizeof(s) / sizeof(char))];
    }
    printf("%s", temp);

    fputs(temp, fp);
    //Retrieves next char array but wont encrypt or write?????
    record = record -> next;
    memset(temp, '\0', sizeof(temp));
    strcpy(temp, record -> characterClass);
    printf("%s", temp);
    len = strlen(temp);
    printf("%d\n", len);

    for (int j = 0; j < len-1; j++) {
        temp[j] = temp[j] ^ s[j % (sizeof(s) / sizeof(char))];
    }
    printf("%s", temp);

    fputs(temp, fp);

    
    return;
}