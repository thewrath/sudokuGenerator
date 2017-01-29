#include <iostream>
#include "include/Sudoku.h"

using namespace std;

int main(){

    Sudoku sudoku;
	sudoku.generateGrid();
	sudoku.drawGrid();
	return 0;
}
