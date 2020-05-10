#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "prototypes.h"
#include "hashCheck.c"

int main(int argc, char *argv[]) 
{
    FILE *fp, *outFile, *hashCheckFile;
    //char s[10] = {'0','x', '0', '0', '4', '0', '1', '1', 'F', '3'};//Meant to look like a hex address
    //char s[1] = {'B'};
    char s[1] = { '*'};
   char buffer[50];

    //handle usage errors
    if(argc==1)
    {
        fprintf(stderr, "At least one argument required.\nUsage: %s <filename>\n", argv[0]);
        exit(1);
    }

    //opens the file
    fp =fopen(argv[1], "rb");

    outFile = fopen("decodedFile.txt", "wb");

    hashCheckFile = fopen("hashCheck.txt", "wb");

                
    //tests if argument is a valid file
    if(fp == NULL)
    {
        perror(argv[1]);
        exit(1);
    } 

    if(outFile == NULL)
    {
        perror("fopen()");
        exit(1);
    }

    if(hashCheckFile == NULL)
    {
        perror("fopen()");
        exit(1);
    }

    //############################################
    //for the hash check

    fgets(buffer, 50, fp);
    fputs(buffer, hashCheckFile);
    fclose(fp);
    fclose(hashCheckFile);

    //############################################

    //############################################
    //decoding the data
    fp =fopen(argv[1], "r");
    if(fp == NULL)
    {
        perror(argv[1]);
        exit(1);
    } 

    int c;
    do{
        c = fgetc(fp);
        //fputc(c,hashCheckFile);
        c = c ^ s[c % (sizeof(s)/sizeof(char))];
        if(feof(fp))
        {
            //fputc(c, outFile);
            break;
        }
        //printf("%c", c);
       
       fputc(c, outFile);
       //fputc(c,"decoded.txt");
        
    }while(1);
    fclose(fp);
    fclose(outFile);
    //#############################################

    

    //original file
    int rtn = hashCheck("outfile.txt");
    printf("Original file: %02x\n", rtn);

    //secondary file for the hash check
    int testHashCheck = hashCheck("hashCheck.txt");
    printf("Test file: %02x\n", testHashCheck);
    
    
    
    return 0;
    
}
