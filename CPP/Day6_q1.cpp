#include <bits/stdc++.h>
using namespace std;

int checkgrid(char grid[130][130], int row, int column) {
    int count = 0;
    int dir = 0; 
    int startrow, startcolumn;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (grid[i][j] == '^') {
                startrow = i;
                startcolumn = j;
                break;
            }
        }
    }
    int currrow = startrow, currcolumn = startcolumn;
    int nextrow, nextcolumn;
    
    while (currrow < row && currrow >= 0 && currcolumn >= 0 && currcolumn < column) {
        if (grid[currrow][currcolumn] != '#' && grid[currrow][currcolumn] != 'X') {
            grid[currrow][currcolumn] = 'X';
            count++;
        }

        nextrow = currrow + (dir == 0 ? -1 : dir == 2 ? 1 : 0);
        nextcolumn = currcolumn + (dir == 1 ? 1 : dir == 3 ? -1 : 0);

        if (nextrow >= 0 && nextrow < row && nextcolumn >= 0 && nextcolumn < column && grid[nextrow][nextcolumn] == '#') {
            dir = (dir + 1) % 4; 
            continue; 
        }

        currrow = nextrow;
        currcolumn = nextcolumn;
    }

    return count;
}

int main() {
    char grid[130][130];
    for (int i = 0; i < 130; i++) {
        for (int j = 0; j < 130; j++) {
            cin >> grid[i][j];
        }
    }

    int count = checkgrid(grid, 130, 130);
    cout << count << endl;

    return 0;
}
