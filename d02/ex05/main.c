#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include <time.h>

#include "header.h"

int main(void)
{
	int n;
	int *rocks;
	//int r[] = {12,16,16,18,18,18,18,18,22,22,22,22,22,26,1,1,1,1,1,1,1,1,1,1,3,3,3,3,3,5,5,5,5,5,5,5,5,5,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,9,9,9,12};
	int value;

	srand(time(NULL));
	n = rand() % 90 + 10;
	rocks = createRandomArray(n);
	if (rand() % 2)
		value = rand() % 30;
	else
		value = rocks[rand() % n];

	/*-------------------
	launch your test here
	--------------------*/

	printArray(rocks, n);
	//n = 74;
	//printArray(r, n);
	//value = 3;
	//printf("Value %d at index %d\n", value, searchShifted(r, n, value));
	printf("Value %d at index %d\n", value, searchShifted(rocks, n, value));
}



// Function used for the test
// Don't go further :)

int *createRandomArray(int n) {
	int *arr, *arrShifted;
	int shift;
	int value = 1;

	if (!(arr = (int *)(malloc(sizeof(int) * n))))
		return (NULL);
	for (int i = 0; i < n; i++) {
		if (rand() % 5 == 0)
			value += rand() % 5;
		arr[i] = value;
	}
	if (!(arrShifted = (int *)(malloc(sizeof(int) * n))))
		return (NULL);
	shift = rand() % 100;
	for (int i = 0; i < n; i++) {
		arrShifted[i] = arr[(i + shift) % n];
	}
	free(arr);
	return (arrShifted);
}

void printArray(int *arr, int n) {
	printf("Rocks : ");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
