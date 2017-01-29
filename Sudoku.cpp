#include "../include/Sudoku.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

Sudoku::Sudoku()
{

}

Sudoku::~Sudoku()
{

}

void Sudoku::generateGrid()
{
	int n;

	for(int i = 0; i<this->size; i++)
	{
	    n = 0;
		for(int j = 0; j<this->size; j++)
		{
			do
			{
                n = randomIntInTab();
                this->deleteTabMember(n);



			}while(!(testRow(j, n) && testCol(i, n) && testSquare(j,i,n)));
			cout << endl;
			drawGrid();
			this->printTab();
            this->tab = this->tabCp;
			this->grid[j][i] = n;
		}

		cout << endl;
	}

}



void Sudoku::drawGrid()
{
	for(int i = 0; i<this->size; i++)
	{
		for(int j = 0; j<this->size; j++)
		{
			cout <<" "<< this->grid[i][j] <<" ";
		}
		cout << endl;
	}
}

int Sudoku::randomInt(int a, int b)
{
	srand(time(NULL));
	return rand() % b + a;
}

bool Sudoku::testRow(int l, int v)
{
	for(int i=0; i<this->size;i++)
	{
		if(this->grid[l][i] == v)
		{
			return false;
		}
	}

	return true;

}

bool Sudoku::testCol(int c, int v)
{
	for(int i=0; i<this->size;i++)
	{
		if(this->grid[i][c] == v)
		{
			return false;
		}
	}

	return true;

}

bool Sudoku::testSquare(int x, int y, int v)
{
	int xOffset = setOffset(x);
	int yOffset = setOffset(y);


	for(int i = 0; i<3; i++)
	{
		for(int j = 0; j<3; j++)
		{
			if(this->grid[xOffset+i][yOffset+j] == v){
				return false;

			}
		}
	}
	return true;

}

void Sudoku::resetNumber(int * a)
{
	if(*a>6)
		*a -= 6;
	else if(*a>3)
		*a -= 3;
}

int Sudoku::setOffset(int a)
{
	if(a>5)
		return 6;
	else if(a>2)
		return 3;

	else
		return 0;
}

int Sudoku::randomIntInTab()
{
    return this->tab[randomInt(0,this->tab.size())];
}

void Sudoku::deleteTabMember(int member)
{

	for(int i = 0; i<this->size; i++)
	{
		if(this->tab[i] == member)
		{
			this->tab.erase(this->tab.begin()+i);
		}
	}

}


void Sudoku::printTab()
{
    for(int i=0; i<9; i++)
        cout << this->tab[i];
}

