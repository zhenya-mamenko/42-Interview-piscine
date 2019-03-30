#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>

/*--------------------------------
	!! required structure
	--------------------------------*/
struct s_stone {
	int size;
	struct s_stone *next;
};

typedef struct		s_blocks
{
	struct s_stone	*b;
	struct s_stone	*e;
	int				size;
}					t_blocks;

/*--------------------------------
	:) function you must implement
	--------------------------------*/
//stone is a pointer to the first
void sortStones(struct s_stone **stone);


/*--------------------------------
	?? test function used in main
	--------------------------------*/
struct s_stone *genRandomStoneList(int n);
void printStone(struct s_stone *stone);
struct s_stone *createStone(int size);
void exitWithMsg(char *msg);


/*--------------------------------
	&  your own other function
	--------------------------------*/

#endif
