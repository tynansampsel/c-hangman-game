#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayHangMan(int failures)
{
	if (failures == 0)
	{
		printf(	"      |		  \n"
				"      |		  \n"
				"      |		  \n"
				"      |          \n"
				"      |          \n"
				"  ____T________  \n\n");
	}
	else if (failures == 1)
	{
		printf(	"      |       0  \n"
				"      |          \n"
				"      |          \n"
				"      |          \n"
				"      |          \n"
				"  ____T________  \n\n");
	}
	else if (failures == 2)
	{
		printf(	"      |       0  \n"
				"      |       |  \n"
				"      |          \n"
				"      |          \n"
				"      |          \n"
				"  ____T________  \n\n");
	}
	else if (failures == 3)
	{
		printf(	"      |       0  \n"
				"      |      /|  \n"
				"      |		  \n"
				"      |          \n"
				"      |          \n"
				"  ____T________  \n\n");
	}
	else if (failures == 4)
	{
		printf(	"      |       0  \n"
				"      |      /|\\  \n"
				"      |          \n"
				"      |          \n"
				"      |          \n"
				"  ____T________  \n\n");
	}
	else if (failures == 5)
	{
		printf(	"      |       0  \n"
				"      |      /|\\  \n"
				"      |      /   \n"
				"      |          \n"
				"      |          \n"
				"  ____T________  \n\n");
	}
	else if (failures == 6)
	{
		printf(	"      |       0  \n"
				"      |      /|\\  \n"
				"      |      / \\  \n"
				"      |          \n"
				"      |   DEAD   \n"
				"  ____T________  \n\n");
	}
}