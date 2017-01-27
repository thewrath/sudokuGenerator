#ifndef UTILES_HPP
#define UTILES_HPP

namespace sudoku 
{
	const int size = 9;
	void generateGrid(int grid[][size]);
	void drawGrid(int grid[][size]);
	int randomInt(int a, int b);
	int randomIntInTab(int tab[size]);
	bool testRow(int grid[][size], int l, int v);
	bool testCol(int grid[][size], int c, int v);
	bool testSquare(int grid[][size], int x, int y, int v);
	int resetNumber(int *a);
	int setOffset(int a);
	void deleteTabMember(int tab[size], int member);
}


#endif //UTILES_HPP