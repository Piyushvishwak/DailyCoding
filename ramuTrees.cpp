// If Raju draws the vertical line after column x and the horizontal line after row y, we represent it by (x,y). 
// For each cut (x,y), we need to calculate the minimum rectangle that it creates. Then, over all the cuts, we choose
//  the one whose minimum rectangle is maximized.

// The problem is to efficiently calculate how a cut divides up the mango trees in the four rectangles.

// Let M[x,y] be the number of mango trees in the rectangle between (0,0) and (x,y). We can calculate M[x,y] 
// as follows:

//       M[x,y] = 1 + M[x-1,y] + M[x,y-1] - M[x-1,y-1], if tree at (x,y)
//              = 0 + M[x-1,y] + M[x,y-1] - M[x-1,y-1], if no tree at (x,y)

// Thus, M[x,y] is the number of mango trees in the top left rectangle formed by the cut. Using M[x,y], we can 
// also calculate the number of mango trees in the top right and bottom left rectangles defined by (x,y).

// Top right rectangle:

//       M[N,y] - M[x,y] : Number of mangos in rectangle defined by (x,y) and (N,0)
    
// Bottom left rectangle:

//       M[x,N] - M[x,y] : Number of mangos in rectangle defined by (0,N) and (x,y)
    
// Finally, we subtract these three quantities from total number of mango trees to get number of mangos in 
// fourth rectangle (bottom right), defined by (x,y) and (N,N).





#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate prefix sums
void calculatePrefixSums(const vector<vector<char>>& grid, vector<vector<int>>& prefixSum) {
    int N = grid.size();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            prefixSum[i + 1][j + 1] = (grid[i][j] == '#') + prefixSum[i][j + 1] + prefixSum[i + 1][j] - prefixSum[i][j];
        }
    }
}

// Function to get the number of mango trees in a subrectangle
int getMangoCount(const vector<vector<int>>& prefixSum, int x1, int y1, int x2, int y2) {
    return prefixSum[x2][y2] - prefixSum[x1][y2] - prefixSum[x2][y1] + prefixSum[x1][y1];
}

int main() {
    int N;
    cin >> N;
    vector<vector<char>> grid(N, vector<char>(N));
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> grid[i][j];
        }
    }
    
    vector<vector<int>> prefixSum(N + 1, vector<int>(N + 1, 0));
    calculatePrefixSums(grid, prefixSum);
    
    int maxMangosForRaju = 0;
    
    // Try every possible horizontal and vertical line
    for (int h = 1; h < N; ++h) {
        for (int v = 1; v < N; ++v) {
            // Calculate mango trees in each of the four rectangles
            int topLeft = getMangoCount(prefixSum, 0, 0, h, v);
            int topRight = getMangoCount(prefixSum, 0, v, h, N);
            int bottomLeft = getMangoCount(prefixSum, h, 0, N, v);
            int bottomRight = getMangoCount(prefixSum, h, v, N, N);
            
            // Put the counts in a vector and sort to find the smallest
            vector<int> counts = {topLeft, topRight, bottomLeft, bottomRight};
            sort(counts.begin(), counts.end());
            
            // Raju gets the smallest rectangle
            maxMangosForRaju = max(maxMangosForRaju, counts[0]);
        }
    }
    
    cout << maxMangosForRaju << endl;
    
    return 0;
}