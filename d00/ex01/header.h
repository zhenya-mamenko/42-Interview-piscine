#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/

struct s_art {
	char *name;
	int price;
};


/*--------------------------------
  :) function you must implement
  --------------------------------*/

void  sortArts(struct s_art **arts);

/*--------------------------------
  ?? test function used in main
  --------------------------------*/

struct s_art **getArts(void);


/*--------------------------------
  &  your own other function
  --------------------------------*/
# include <string.h> //memcpy, strlen, ...

# define HILO(hilo, X, Y)	hilo.h=(X);hilo.l=(Y)


typedef struct	s_hilo
{
	size_t		h;
	size_t		l;
}				t_hilo;

#endif
