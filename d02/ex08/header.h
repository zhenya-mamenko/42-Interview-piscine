#ifndef HEADER_H
# define HEADER_H

# include <stdio.h> //printf, scanf, ...
# include <string.h> //memcpy, strlen, ...
# include <unistd.h> //fork, write, sleep...
# include <stdlib.h> //malloc, free, exit...
# include <sys/resource.h>
# include <sys/stat.h>
# include <removefile.h>

/*--------------------------------
  !! required structure
  --------------------------------*/
#define SCOREFILE "grannyScores.txt"
#define SORTEDFILE "grannyScoresSorted.txt"

struct s_block {
	int *scores;
	int n;
};

/*--------------------------------
  :) function you must implement
  --------------------------------*/
void externalSort(char *scoreFile, char *sortedFile, int ram);

/*--------------------------------
  ?? test function used in main
  --------------------------------*/
FILE *openFile(char *filename, char *flag);

int readBlock(FILE *f, int *arr, int size);

void writeFile(char *filename, int *arr, int n);

int fileIsSorted(char *filename);

/*--------------------------------
  &  your own other function
  --------------------------------*/
# define HILO(hilo, X, Y)	hilo.h=(X);hilo.l=(Y)

typedef struct	s_hilo
{
	size_t		h;
	size_t		l;
}				t_hilo;

#endif
