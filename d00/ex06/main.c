#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{
	char *cBook;

	//getting the compressed book!
	cBook = readFile();

	/*-------------------
	launch your test here
	--------------------*/
/*	struct s_string *s = stringInit();
	stringAppend(s, "Hello");
	printf("%s\n", s->content); //’Hello’
	stringAppend(s, " World!");
	printf("%s\n", s->content);
*/
	printf("%s", decompress(cBook));

	return (0);
}


// Function used for the test
// Don't go further :)

#define FILENAME "cbook.txt"

void	leave(void){
	dprintf(STDERR_FILENO, "Failed to load the file.\n");
	exit(0);
}

char	*readFile(void)
{
	char *fcontent = NULL;
	int size = 0;
	FILE *fp;

//	printf("Loading the file... ");
	if (NULL == (fp = fopen(FILENAME, "r")))
		leave();
	fseek(fp, 0L, SEEK_END);
	size = ftell(fp);
	rewind(fp);
	if (NULL == (fcontent = malloc(sizeof(char) * (size + 1))))
		leave();
	fread(fcontent, 1, size, fp);
	fclose(fp);
//	printf("finish!\n");
	return (fcontent);
}
