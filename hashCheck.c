#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/md5.h>
#include "prototypes.h"

char *hashCheck() {

    unsigned char c[MD5_DIGEST_LENGTH];
    char *res;
    res = (char*)malloc(MD5_DIGEST_LENGTH);
    char *fname = "outfile.txt";
    FILE *inFile = fopen(fname, "rb");
    MD5_CTX mdCtx;
    int bytes;
    unsigned char data[1024];

    if (inFile == NULL) {
       // printf("%s can't be opened or does not exist. \n", fname);
        perror("fopen()");
        exit(1);

    }

    MD5_Init (&mdCtx);
    while ((bytes = fread (data, 1, 1024, inFile)) !=0) {
        MD5_Update (&mdCtx, data, bytes);
    }
    MD5_Final (c, &mdCtx);

    for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        res[i] = c[i];
    }
    fclose(inFile);

    return (char *)res;

}