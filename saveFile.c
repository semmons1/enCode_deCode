#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "prototypes.h"
//Will probably need more imports

void saveFile(struct Stats* record) {
    
    char superSECRETKEY[20] = {'A','Y', 'U', 'F', 'E', 'T', 'V', 'B', 'I','H','S','I','O','C','Z','8','1','3','6', '4'};
    
    //Will retrieve character name, but not the other character array variables.
    //Not entirely sure why.
    for(int i = 0; i < 3; i++) {
        int len = strlen(getStats(&record, i));
        printf("%s\n", getStats(&record, i));
        printf("%d\n", len);
        //Below is the encoding sequence, for when this works.
        //for(int j = 0; j < len; j++) {
        //    getStats(&vector, i)[i] = getStats(&vector, i)[i] ^ superSECRETKEY[i % (sizeof(superSECRETKEY) / sizeof(char))];
        //}
        //printf("%s", getStats(&vector, i));
    }
   
    /*for (current = &name; current != NULL; current = current->next) {
        printf("%s", current);

    }*/
    
    return;
}