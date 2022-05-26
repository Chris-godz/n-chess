#include"chess.h"
#define _CRT_SECURE_NO_WARNINGS 
constexpr auto ROW = 3
constexpr auto COL = 3


int main()
{   
	extern char arr[ROW][COL] = { 0 };
	char res ='c';
	openner();
	boardclean();
	boardprint();
	while (1)
	{
		playermove();
		boardprint();
		res=judge();
		printf("%c\n", res);
		if (res !='c')
		{
			break;
		}
		computermove();
		boardprint();
		res = judge();
		printf("%c\n", res);
		if (res != 'c')
		{
			break;
		}
	}
	if (res == 'o')
	{
		printf("you have won this game");
	}
	else if (res == '#')
	{
		printf("you are a loser");
	}
	else if(res=='n')
	{
		printf("this round are close");
	}
}