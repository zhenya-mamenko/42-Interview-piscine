#ifndef HEADER_H
# define HEADER_H

#include <stdlib.h>

/*--------------------------------
  !! required structure
  --------------------------------*/
struct s_node {
	int value;
	struct s_node *random;
	struct s_node *next;
};

typedef struct s_list {
	struct s_node *old;
	struct s_node *new;
	struct s_list *next;
} t_list;

/*--------------------------------
  :) function you must implement
  --------------------------------*/
struct s_node *cloneGameBoard(struct s_node *node);

/*--------------------------------
  ?? test function used in main
  --------------------------------*/
struct s_node *genRandomSnakesAndLadders(int n);
void    printSnakeAndLadders(struct s_node *node);

/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif
