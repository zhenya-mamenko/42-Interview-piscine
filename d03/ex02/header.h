#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>

/*--------------------------------
  !! required structure
  --------------------------------*/
struct s_node {
	char	*name;
	struct s_node **children;
};


/*--------------------------------
  :) function you must implement
  --------------------------------*/
struct s_node *findParent(struct s_node *root, char *firstSpecies, char *secondSpecies);


/*--------------------------------
  ?? test function used in main
  --------------------------------*/
struct s_node *getTreeOfLife(void);


/*--------------------------------
  &  your own other function
  --------------------------------*/
struct s_item {
  struct s_node *node;
  struct s_item *next;
};

struct s_stack {
	struct s_item *item;
};



struct s_queue *queueInit(void);

struct s_node *dequeue(struct s_queue *queue);

void enqueue(struct s_queue *queue, struct s_node *value);

char *peek(struct s_queue *queue);

int isEmpty(struct s_queue *queue);

#endif
