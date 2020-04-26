
CC = gcc 
CFLAGS = -ggdb -Wall #-Wno-unused-function



.PHONY : tidy clean 

main : main.c 
	$(CC) $(CFLAGS) main.c interactUser.c saveFile.c getStats.c -o encodeDecode
	
tidy : 
	/bin/rm -f $(OBJS) a.out core.*

clean : tidy
	/bin/rm -f encodeDecode
