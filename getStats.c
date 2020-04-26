#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "prototypes.h"

Stats* getStats(vector_Template* vector, int index) 
{
    int i = 0;
    Stats* item = NULL;
    if (vector == NULL) {
        return NULL;
    }
    item = vector -> head;
    for (i = 0; i < index && item != NULL; i++) {
        item = item -> next;
    }
    return item;
}