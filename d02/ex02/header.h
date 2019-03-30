#ifndef HEADER_H
# define HEADER_H

# include <string.h>

/*--------------------------------
  !! required structure
  --------------------------------*/
struct s_player {
  int   score;
  char  *name;
};

/*--------------------------------
  :) function you must implement
  --------------------------------*/
void quickSort(struct s_player **players);

/*--------------------------------
  ?? test function used in main
  --------------------------------*/
struct s_player **genRandomPlayers(int n);
struct s_player *createRandomPlayer(char *name);
void printPlayers(struct s_player **players);

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
