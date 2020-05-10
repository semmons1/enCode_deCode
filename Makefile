
CC = gcc 
CFLAGS = -ggdb -Wall -lcrypto -lssl


.PHONY : tidy clean

all : main fileRead

main : main.c 
	$(CC) $(CFLAGS) main.c interactUser.c saveFile.c hashCheck.c -o encodeDecode.out

fileRead : fileRead.c 
	$(CC) $(CFLAGS) fileRead.c -o fileRead.out
	
tidy : 
	/bin/rm -f $(OBJS) a.out core.*

clean : tidy
	/bin/rm -f encodeDecode
