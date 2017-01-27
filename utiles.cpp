#include <iostream>
#include <ctime>
#include <cstdlib>
#include "../include/utiles.hpp"

using namespace std;

void sudoku::generateGrid(int grid[][sudoku::size])
{
	int tab[9] = {1,2,3,4,5,6,7,8,9};
	int n;	

	for(int i = 0; i<sudoku::size; i++)
	{
		for(int j = 0; j<sudoku::size; j++)
		{

			do 
			{
				n = randomInt(1,9);

				 
			}while(!(testRow(grid, j, n) && testCol(grid, i, n) && testSquare(grid, j+1,i+1,n)));

			grid[j][i] = n;		
		}
		drawGrid(grid);
		cout << endl;
	}
	
}
		


void sudoku::drawGrid(int  grid[][sudoku::size])
{
	for(int i = 0; i<sudoku::size; i++)
	{
		for(int j = 0; j<sudoku::size; j++)
		{
			cout <<"|"<< grid[i][j] <<"|";
		}
		cout << endl;
	}
}

int sudoku::randomInt(int a, int b)
{
	srand(time(NULL));
	return rand() % b + a;
}

bool sudoku::testRow(int grid[][sudoku::size], int l, int v)
{
	for(int i=0; i<sudoku::size;i++)
	{
		if(grid[l][i] == v)
		{
			return false;
		}			
	}

	return true;
	
}

bool sudoku::testCol(int grid[][sudoku::size], int c, int v)
{
	for(int i=0; i<sudoku::size;i++)
	{
		if(grid[i][c] == v)
		{
			return false;
		}			
	}

	return true;
	
}

bool sudoku::testSquare(int grid[][size], int x, int y, int v)
{
	int xOffset = setOffset(x);
	int yOffset = setOffset(y);


	for(int i = 0; i<3; i++)
	{
		for(int j = 0; j<3; j++)
		{
			if(grid[xOffset+i][yOffset+j] == v){
				return false;
				
			}
		}
	}	
	return true;

}

int sudoku::resetNumber(int * a)
{
	if(*a>6)
		*a -= 6;	
	else if(*a>3)
		*a -= 3;
}

int sudoku::setOffset(int a)
{
	if(a>6)
		return 6;	
	else if(a>3)
		return 3;

	else
		return 0;
}

int sudoku::randomIntInTab(int tab[9])
{
	return tab[randomInt(0,8)];
}

void sudoku::deleteTabMember(int tab[9], int member)
{
	for(int i = 0; i<sudoku::size; i++)
	{
		if(tab[i] == member)
		{
			tab[i] = 7 ; 
		}
	}
}