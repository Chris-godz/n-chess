#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<time.h>
#include "chess.h"
#define row 3;
#define col 3;
#define win 3;
extern char arr[row][col];
void openner()
{
	
	printf("#######################\n");
	printf("###### welcome ########\n");
	printf("##start>1    close>0##\n");
	printf("#######################\n");
	while(1)
	{
		int x = 0;
		scanf("%d", &x);
		if (x == 1)
		{
			printf("game start\n");
			break;
		}
		else if (x == 0)
		{
			printf("plese close the game by hand\n");
		}
		else
		{
			printf("i can not know what you express to me\n");
		}
	}
}
void boardclean( )
{
	int i, j;
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{
			arr[i][j] = ' ';
		}
	}
}
void boardprint( )
{
	int i, j;
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{
			printf("%c", arr[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0;j < col;j++)
			{
				printf("_");
				printf(" ");
			}
		}
		printf("\n");
	}
}
void playermove()
{
	printf("your turn>");
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("your x>");
		scanf("%d", &x);
		printf("\n");
		printf("your y>");
		scanf("%d", &y);
		printf("\n");
		if (x <= col && y <= row && arr[y - 1][x - 1] == ' ')
		{
			arr[y - 1][x - 1] = 'o';
			break;
		}
		else
		{
			printf("your input is not right\n");
		}
	}

}
int isfull()
{
	int i, j;
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{
			if(arr[i][j] == ' ');
			{
				printf("%d%d", i, j);
				return 2;
			}
		}
	}
	return 1;
}
char judge()
{
	int i, j, n;
	int coun = 0;
	for (i = 0; i < row; i++)
	{
		int count = 1;
		for (j = 0;j < col - 1;j++)
		{
			if (arr[i][j] == arr[i][j + 1] && arr[i][j] != ' ')
			{
				count++;
			}
			else
			{
				count = 1;
			}
			if (count == win && arr[i][j] != '\0')
			{
				return arr[i][j];
			}
		}
	}
	for (i = 0; i < col; i++)
	{
		int count = 1;
		for (j = 0;j < row - 1;j++)
		{
			if (arr[j][i] == arr[j + 1][i] && arr[j][i] != ' ')
			{
				count++;
			}
			else
			{
				count = 1;
			}
			if (count == win && arr[i][j] != '\0')
			{
				return arr[j][i];
			}
		}
	}
	for (n = 0;n <= col - win;n++)
	{
		int count = 1;
		for (i = n, j = 0;i <= col;i++, j++)
		{
			if ((i >= row) || (j >= col) )
			{
				continue;
			}
			else if (arr[i][j] == arr[i + 1][j + 1] && arr[i][j] != ' ')
				{
					count++;
				}
			else
				{
					count = 1;
				}
				if (count == win)
				{
					return arr[j][i];
				}
			}
		}
	for (n = 0;n <= row - win;n++)
	{
		int count = 1;
		for (i = 0, j = n;j <= row;i++, j++)
		{
			if ((i >= row) || (j >= col))
			{
				continue;
			}
			else if (arr[i][j] == arr[i + 1][j + 1] && arr[i][j] != ' ')
					{
						count++;
					}
			else
					{
						count = 1;
					}
					if (count == win )
					{
						return arr[j][i];
					}
		}
	}
	/*for (n = row-1;n >= row - win;n--)
	{
		int count = 1;
		for (i = n, j = 0;i <= row;i--, j++)
		{
			if ((i >= row) || (j >= col))
			{
				continue;
			}
			else if (arr[i][j] == arr[i - 1][j + 1] && arr[i][j] != ' ')
			{
				count++;
			}
			else
			{
				count = 1;
			}
			if (count == win)
			{
				return arr[i][j];
			}
		}
	}*/
	if (1==isfull(char arr))
	{
		return'n';
	}
	return'c';
}
void computermove()
{
	int x, y;
	srand((unsigned int)time(NULL));
	while (1)
	{
		x = rand() % col;
		y = rand() % row;
		if (x <= col && y <= row && arr[y][x] == ' ')
		{
			arr[y][x] = '#';
			break;
		}
	}
}

	
		
	
	