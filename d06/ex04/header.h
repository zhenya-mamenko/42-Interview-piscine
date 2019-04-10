#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>

/*--------------------------------
  !! required structure
  --------------------------------*/
#define WIDTH 8

/*--------------------------------
  :) function you must implement
  --------------------------------*/
int getInitialPos(uint64_t board);
double knightOut(uint64_t board, int n);

/*--------------------------------
  ?? test function used in main
  --------------------------------*/
void printBoard(uint64_t board);

/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif
