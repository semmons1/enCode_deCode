#include <stdio.h>
#include <stdbool.h>
#include "interactUser.h"
#include "saveFile.h"

int main() {
    
    char characterName[35];
    char characterClass[35]; //Barbarian, mage, necromancer, bard, warrior?
    char preferredWeapon[35];
    int stats[6]; //Should be strength, dexterity, constitution, intelligence, wisdom, and charisma scores
    double height;
    float hitPoints;
    bool isQuestLeader;

    //Call user input function, and pass these variables as arguments
    //they will be filled with data from the user. Need to make a header 
    //file with function prototypes, and then the actual C file.
    
    interactUser(characterName, characterClass, preferredWeapon, stats, 
    height, hitPoints, isQuestLeader);


    //Once arguments have been filled with data in the above function,
    //pass them to an XOR encoding function. Potentially write the encoded 
    //data to a file, and produce a checksum. Need to make another header file
    //for this. Needs an anonymous signature?
    //saveInfo(variables to encrypt)
    
    return 0;
    
}