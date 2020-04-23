#include <stdio.h>
#include <stdbool.h>
#include "prototypes.h"

int main() {
   
    //Call user input function, and pass these variables as arguments
    //they will be filled with data from the user. Need to make a header 
    //file with function prototypes, and then the actual C file.
    struct stats params;

    interactUser(params.characterName, params.characterClass, params.preferredWeapon, params.stats, 
    params.height, params.hitPoints, params.isQuestLeader);

    //Once arguments have been filled with data in the above function,
    //pass them to an XOR encoding function. Potentially write the encoded 
    //data to a file, and produce a checksum. Need to make another header file
    //for this. Needs an anonymous signature?
    //saveInfo(variables to encrypt)
    
    return 0;
    
}