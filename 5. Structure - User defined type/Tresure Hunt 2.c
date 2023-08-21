
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

#define MinimumPathLength 10
#define MaximumPathLength 70
#define MaximumLife 10
#define MinimumLife 1
#define MultipleForLength 5

struct PlayerInfo
{
	int lives;
	char playerSymbol;
	int treasureCounter;
	int records[MaximumPathLength];
};

struct GameInfo
{
	int totalMoves;
	int pathLength;
	int bombs[MaximumPathLength];
	int treasure[MaximumPathLength];

};

int main(void)
{
	struct PlayerInfo Player;
	struct GameInfo Game;

	int minMove = 0, maxMove = 0, temp1 = 0, temp2 = 0, i = 0, j = 0, nextMove = 1, flag = 0 , k =1;
	double temp = 0.0;
	char undiscovered = '-', bomb = '!', treasure = '$', bothBomTre = '&',notBomTre = '.';


	printf("================================\n");
	printf("         Treasure Hunt!         \n");
	printf("================================\n");

	//player configuration starts from here.

	printf("\nPLAYER Configuration");
	printf("\n--------------------\n");

	printf("Enter a single character to represent the player: ");
	scanf(" %c", &Player.playerSymbol);

	//a do while loop for validation of prompted number of life.
	do
	{
		printf("Set the number of lives: ");
		scanf("%d", &Player.lives);
		if (Player.lives < MinimumLife || Player.lives > MaximumLife)
			printf("     Must be between %d and %d!\n", MinimumLife, MaximumLife);
	} while (Player.lives < MinimumLife || Player.lives > MaximumLife);
	printf("Player configuration set-up is complete\n");

	// Now the configuration of the game begins from here

	printf("\nGAME Configuration");
	printf("\n------------------\n");

	// here do while loop is used to validate the value of pathlength entered by the user

	do
	{
		printf("Set the path length (a multiple of %d between %d-%d): ", MultipleForLength, MinimumPathLength, MaximumPathLength);
		scanf("%d", &Game.pathLength);
		if ((Game.pathLength < MinimumPathLength) || (Game.pathLength > MaximumPathLength) || (Game.pathLength % MultipleForLength != 0))
			printf("     Must be a multiple of %d and between %d-%d!!!\n", MultipleForLength, MinimumPathLength, MaximumPathLength);
	} while ((Game.pathLength < MinimumPathLength) || (Game.pathLength > MaximumPathLength) || (Game.pathLength % MultipleForLength != 0));

	// here do while loop is used to validate the number of moves for the game

	do
	{
		printf("Set the limit for number of moves allowed: ");
		scanf("%d", &Game.totalMoves);         // here minMove and maxMove variables are taken for the storage of moves and later checking the condition.
		minMove = Player.lives;
		temp = Game.pathLength * 0.75;
		maxMove = (int)temp;
		if ((temp - maxMove) > 0.5)
		{
			++maxMove;   // if the value of temp would be grater than maxmoves the program can go wrong so the maxmoves is increamented by 1 if such happens.
		}
		if (Game.totalMoves < minMove || Game.totalMoves >maxMove)
		{
			printf("    Value must be between %d and %d\n", minMove, maxMove);
		}
	} while (Game.totalMoves < minMove || Game.totalMoves >maxMove);

	// placement of bombs start from here.


	printf("\nBOMB Placement");
	printf("\n--------------\n");

	printf("Enter the bomb positions in sets of %d where a value\n", MultipleForLength);
	printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", Game.pathLength);
	temp1 = 0;
	temp2 = MultipleForLength;

	for (i = 0; i < Game.pathLength / MultipleForLength; i++)
	{
		printf("   Positions [%2d-%2d]: ", temp1 + 1, temp2);
		for (j = temp1;j < temp2;j++)
		{

			scanf("%d", &Game.bombs[j]);
		}
		temp1 = temp2;
		temp2 = (i + 2) * MultipleForLength;

	}
	printf("BOMB placement set\n");


	// placement for treasure starts from here

	printf("\nTREASURE Placement");
	printf("\n------------------\n");
	printf("Enter the treasure placements in sets of %d where a value\n", MultipleForLength);
	printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", Game.pathLength);
	temp1 = 0;
	temp2 = MultipleForLength;

	for (i = 0; i < Game.pathLength / MultipleForLength; i++)
	{
		printf("   Positions [%2d-%2d]: ", temp1 + 1, temp2);
		for (j = temp1;j < temp2;j++)
		{

			scanf("%d", &Game.treasure[j]);
		}
		temp1 = temp2;
		temp2 = (i + 2) * MultipleForLength;

	}

	printf("TREASURE placement set\n");
	//tresure config is done
	printf("\nGAME configuration set-up is complete...\n");


	//now trasure hunt config

	printf("\n------------------------------------");
	printf("\nTREASURE HUNT Configuration Settings");
	printf("\n------------------------------------");

	printf("\nPlayer:");
	printf("\n   Symbol     : %c", Player.playerSymbol);
	printf("\n   Lives      : %d", Player.lives);
	printf("\n   Treasure   : [ready for gameplay]");
	printf("\n   History    : [ready for gameplay]\n");

	printf("\nGame:");
	printf("\n   Path Length: %d", Game.pathLength);
	printf("\n   Bombs      : ");

	// displaying bombs

	for (i = 0; i < Game.pathLength; i++)
	{
		printf("%d", Game.bombs[i]);
	}

	// displaying the treasure

	printf("\n   Treasure   : ");
	for (i = 0; i < Game.pathLength; i++)
	{
		printf("%d", Game.treasure[i]);
	}

	//  TREASURE HUNT Configuration  Settings is ended here

	printf("\n");
	printf("\n====================================");
	printf("\n~ Get ready to play TREASURE HUNT! ~");
	printf("\n====================================\n");

	//here we start our game

	temp = 0;
	Player.treasureCounter = 0;
	for ( i = 0; i < MaximumPathLength; i++)  // this for loop is to remove garbage value from array so that it functions perfectly.
	{
		Player.records[i] =  0 ;
	}
	
	while (1)
	{
		if (temp == 0)         
			++temp;
		else
		{
			printf("\n  ");
			for (i = 0; i < Game.pathLength; i++)
			{
				if (Player.records[i] == 1 && i == (nextMove - 1))
				{
					printf("%c", Player.playerSymbol);   // This will print the position of the player using the character symbol
				}
				else
					printf(" ");
			}
		}
		printf("\n  ");
		for (i = 0; i < Game.pathLength; i++)   // here it is checked on position that what player have found and will display it.
		{
			if (Player.records[i] == 0)
				printf("%c", undiscovered);
			else if (Game.bombs[i] == 1 && Game.treasure[i] == 1)
			{
				printf("%c", bothBomTre);
			}
			else if (Game.bombs[i] == 1)
			{
				printf("%c", bomb);
			}
			else if (Game.treasure[i] == 1)
			{
				printf("%c", treasure);
			}
			else
				printf("%c", notBomTre);
		}
		printf("\n  ");
		for (i = 0; i < Game.pathLength; i++)
		{
			if ((i + 1) % 10 == 0)
			{
				++flag;
				printf("%d", flag);
			}
			else
				printf("|");
		}
		flag = 0;
		printf("\n  ");
		for (i = 0; i < Game.pathLength; i++)
		{
			if ((i + 1) % 10 == 0)
			{
				printf("0");
				k = 1;
			}
			else
				printf("%d", k++);
		}
		printf("\n");
		printf("+---------------------------------------------------+\n");
		printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n",Player.lives, Player.treasureCounter, Game.totalMoves);
		printf("+---------------------------------------------------+\n");
		if (Player.lives == 0 || Game.totalMoves == 0)  // this will check the lives and break
		{
			break;
		}
		while (1)
		{
			printf("Next Move [1-%d]: ", Game.pathLength);
			scanf("%d", &nextMove);
			if (nextMove<1 || nextMove > Game.pathLength)
				printf("  Out of Range!!!\n");
			else
				break;
		}
		if (Player.records[nextMove - 1] == 1)
		{
			printf("\n===============> Dope! You've been here before!\n");
		}
		else
		{
			Player.records[nextMove - 1] = 1;
			Game.totalMoves -= 1;
			if (Game.bombs[nextMove - 1] == 1 && Game.treasure[nextMove - 1] == 1)
			{
				Player.lives -= 1;
				Player.treasureCounter += 1;
				printf("\n===============> [%c] !!! BOOOOOM !!! [%c]",bothBomTre, bothBomTre);
				printf("\n===============> [%c] $$$ Life Insurance Payout!!! [%c]\n",bothBomTre,bothBomTre);
					if (Player.lives == 0)
						printf("\nNo more LIVES remaining!\n");
					else if (Game.totalMoves == 0)
						printf("\nNo more MOVES remaining!\n");
			}
			else if (Game.bombs[nextMove - 1] == 1)
			{
				Player.lives -= 1;
				printf("\n===============> [%c] !!! BOOOOOM !!! [%c]\n",
					bomb, bomb);
				if (Player.lives == 0)
					printf("\nNo more LIVES remaining!\n");
				else if (Game.totalMoves == 0)
					printf("\nNo more MOVES remaining!\n");
			}
			else if (Game.treasure[nextMove - 1] == 1)
			{
				Player.treasureCounter += 1;
				printf("\n===============> [%c] $$$ Found Treasure! $$$ [%c]\n",treasure,treasure);
			}
			else
			{
				printf("\n===============> [%c] ...Nothing found here... [%c]\n",notBomTre,notBomTre);
			}
		}
}
printf("\n##################\n");
printf("#   Game over!   #\n");
printf("##################\n");
printf("\nYou should play again and try to beat your score!\n");





	return 0;

}
