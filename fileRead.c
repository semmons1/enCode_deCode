#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
    char buffer[50];
    FILE *fp;
    int rtn;

    //handle usage errors
    if(argc==1)
    {
        fprintf(stderr, "At least one argument required.\nUsage: %s <filename>\n", argv[0]);
        exit(1);
    }

    //opens the file
    fp =fopen(argv[1], "r");
                
    //tests if argument is a valid file
    if(fp == NULL)
    {
        perror(argv[1]);
        exit(1);
    } 

    

    fclose(fp);
  
    
    return 0;
    
}
