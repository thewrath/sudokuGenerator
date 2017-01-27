#include <iostream>
#include "../include/utiles.hpp"

using namespace std;

int main(){
	int grid[sudoku::size][sudoku::size] = {{0}};
	sudoku::generateGrid(grid);
	sudoku::drawGrid(grid);
	return 0;
}