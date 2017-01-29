#ifndef SUDOKU_H
#define SUDOKU_H

#include <vector>

using namespace std;

class Sudoku
{
    public:
        Sudoku();
        virtual ~Sudoku();
        void generateGrid();
        void drawGrid();

    protected:

    private:
        int grid[9][9] = {{0}};
        vector<int> tab  = {1,2,3,4,5,6,7,8,9};
        vector<int> tabCp  = {1,2,3,4,5,6,7,8,9};
        static const int size = 9;

        int randomInt(int a, int b);
        int randomIntInTab();
        int setOffset(int a);

        bool testRow(int l, int v);
        bool testCol(int c, int v);
        bool testSquare(int x, int y, int v);

        void resetNumber(int *a);
        void deleteTabMember(int member);

        void printTab();
};

#endif // SUDOKU_H
