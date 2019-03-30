#ifndef HEADER_H
# define HEADER_H

# include <string.h>

/*--------------------------------
  !! required structure
  --------------------------------*/

#define NUMBER_OF_USTENSILS 15

/*--------------------------------
  :) function you must implement
  --------------------------------*/
void countSort(unsigned char *utensils, int n);


/*--------------------------------
  ?? test function used in main
  --------------------------------*/
unsigned char *genRandomUstensils(int *n);
void printUtensils(unsigned char *utensils, int n);

/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif
