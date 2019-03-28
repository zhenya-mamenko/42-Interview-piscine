#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <string.h>

/*--------------------------------
  !! required structure
  --------------------------------*/
struct s_node {
	int value;
	int isFinal;
	struct s_node *random;
	struct s_node *next;
};

struct s_queue {
  struct s_node *first;
	struct s_node *last;
};

/*--------------------------------
  :) function you must implement
  --------------------------------*/
int	minimumMoves(struct s_node *begin); //you must return the minimum number of strokes to access to the final

/*--------------------------------
  ?? test function used in main
  --------------------------------*/
struct s_node *getBoardFromFile(char *file);

/*--------------------------------
  &  your own other function
  --------------------------------*/

struct s_queue *queueInit(void);

struct s_node *dequeue(struct s_queue *queue);

void enqueue(struct s_queue *queue, struct s_node *node);

int isEmpty(struct s_queue *queue);


#endif
