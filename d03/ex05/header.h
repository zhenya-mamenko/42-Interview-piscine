#ifndef HEADER_H
# define HEADER_H

# include <string.h>

/*--------------------------------
  !! required structure
  --------------------------------*/
struct s_node {
	char		      c;
	unsigned int	isWord:1;
	struct        s_node	**child;
};

struct s_trie {
	struct s_node *node;
};


/*--------------------------------
  :) function you must implement
  --------------------------------*/
struct s_trie *createTrie(char **dictionary);
char *understand(char *word, struct s_trie *trie);


/*--------------------------------
  ?? test function used in main
  --------------------------------*/
extern char *g_dict[];

char *understandAll(char *sentence, struct s_trie *trie);


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
