#include <bits/stdc++.h>
using namespace std;

int checkgrid(char grid[130][130], int row, int column) {
    int dir = 0; 
    int startrow,startcolumn;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (grid[i][j] == '^') {
                startrow = i;
                startcolumn = j;
                break;
            }
        }
    }

    int countocc[130][130] = {0};
    int currrow = startrow, currcolumn = startcolumn;

    while (true) {
        countocc[currrow][currcolumn]++;
        if (countocc[currrow][currcolumn] > 4) return 1; 

        int nextrow = currrow + (dir == 0 ? -1 : dir == 2 ? 1 : 0);
        int nextcolumn = currcolumn + (dir == 1 ? 1 : dir == 3 ? -1 : 0);

        if (nextrow < 0 || nextrow >= row || nextcolumn < 0 || nextcolumn >= column) {
            break; 
        }
        if (grid[nextrow][nextcolumn] == '#') {
            dir = (dir + 1) % 4; 
            continue;
        }

        currrow = nextrow;
        currcolumn = nextcolumn;
    }

    return 0; 
}

int main() {
    char grid[130][130];

    for (int i = 0; i < 130; i++) {
        for (int j = 0; j < 130; j++) {
            cin >> grid[i][j];
        }
    }

    int count = 0;

    for (int i = 0; i < 130; i++) {
        for (int j = 0; j < 130; j++) {
            if (grid[i][j] == '.') { 
                grid[i][j] = '#'; 
                if (checkgrid(grid, 130, 130)) {
                    count++;
                }
                grid[i][j] = '.'; 
            }
        }
    }


    cout << count << endl;

    return 0;
}
