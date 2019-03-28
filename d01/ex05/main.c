#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

void show_tank_state(struct s_tank *tank)
{
	int		i;

	i = 0;
	while (i < tank->n)
	{
		printf("%s%c = %d\n", i == 0 ? "normal" : "nitro", i == 0 ? ' ' : '0' + i,
			tank->stacks[i]->sum);
		i++;
	}
	printf("\n");
}

int main(void)
{
	struct s_tank *tank = initTank();

	/*-------------------
	launch your test here
	--------------------*/
	tankPush(tank, 800);
	show_tank_state(tank);
	tankPush(tank, 10);
	show_tank_state(tank);
	tankPush(tank, 100);
	show_tank_state(tank);
	tankPush(tank, 100);
	show_tank_state(tank);
	tankPop(tank);
	show_tank_state(tank);
	tankPush(tank, 50);
	show_tank_state(tank);
	tankPop(tank);
	show_tank_state(tank);
	tankPop(tank);
	show_tank_state(tank);
	tankPop(tank);
	show_tank_state(tank);
	tankPush(tank, 100);
	show_tank_state(tank);
	tankPush(tank, 50);
	show_tank_state(tank);
	tankPush(tank, 100);
	show_tank_state(tank);
	tankPush(tank, 100);
	show_tank_state(tank);
	tankPop(tank);
	show_tank_state(tank);
	tankPush(tank, 100);
	show_tank_state(tank);
	tankPush(tank, 50);
	show_tank_state(tank);
	tankPush(tank, 100);
	show_tank_state(tank);
	tankPush(tank, 100);
	show_tank_state(tank);
	tankPush(tank, 100);
	show_tank_state(tank);
	tankPush(tank, 100);
	show_tank_state(tank);
	tankPush(tank, 100);
	show_tank_state(tank);
	tankPush(tank, 100);
	show_tank_state(tank);
	tankPush(tank, 100);
	show_tank_state(tank);
	tankPush(tank, 100);
	show_tank_state(tank);
	tankPush(tank, 20);
	show_tank_state(tank);
	tankPush(tank, 30);
	show_tank_state(tank);
	tankPop(tank);
	show_tank_state(tank);

	int i = 0;
	while (i < 100)
	{
		tankPop(tank);
		show_tank_state(tank);
		i++;
	}
	return (0);
}



// Function used for the test
// Don't go further :)
