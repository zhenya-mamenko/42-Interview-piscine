#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{

	/*-------------------
	launch your test here
	--------------------*/

	struct s_queue	*q;

	q = queueInit();
	enqueue(q, "Message 1");
	printf("enqueue: %s\n", "Message 1");
	enqueue(q, "Message 2");
	printf("enqueue: %s\n", "Message 2");
	enqueue(q, "Message 3");
	printf("enqueue: %s\n", "Message 3");
	printf("peek = %s\n", peek(q));
	printf("dequeue (1) = %s\n", dequeue(q));
	printf("dequeue (2) = %s\n", dequeue(q));
	printf("dequeue (3) = %s\n", dequeue(q));

	return (0);
}



// Function used for the test
// Don't go further :)

