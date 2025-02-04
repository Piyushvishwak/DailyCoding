// #include<bits/stdc++.h>
// using namespace std;

// // Function to get the total area of all cakes
// float getTotalArea(vector<vector<float>> cakes) {
//     float totalArea = 0;
//     for (auto cake : cakes) {
//         totalArea += cake[2];
//     }
//     return totalArea;
// }

// // Function to get the area of cakes on the left side of the cut
// float getLeftArea(vector<vector<float>> cakes, float cut) {
//     float leftArea = 0;
//     for (auto cake : cakes) {
//         if (cake[0] < cut) {
//             leftArea += cake[2];
//         }
//     }
//     return leftArea;
// }

// // Function to find the best cut
// float findBestCut(vector<vector<float>> cakes) {
//     float totalArea = getTotalArea(cakes);
//     float bestCut = 0;
//     float minDiff = FLT_MAX;

//     for (auto cake : cakes) {
//         float cut = cake[0];
//         float leftArea = getLeftArea(cakes, cut);
//         float rightArea = totalArea - leftArea;
//         float diff = abs(leftArea - rightArea);

//         if (diff < minDiff) {
//             minDiff = diff;
//             bestCut = cut;
//         }
//     }

//     return bestCut;
// }

// int main() {
//     int n = 5;
//     vector<vector<float>> cakes = {{1.0, 1.0, 3.0}, {5.0, 1.0, 2.0}, {8.0, 1.0, 1.0}, {4.0, 5.0, 2.0}, {10.0, 15.0, 6.0}};
//     float bestCut = findBestCut(cakes);
//     cout << "Best cut is at x = " << bestCut << endl;
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

struct cake {
    float x, y, side;
};

// Function to get the total area of all cakes
float getTotalArea(vector<cake>& cakes) {
    float totalArea = 0;
    for (cake c : cakes) {
        totalArea += c.side * c.side;
    }
    return totalArea;
}

// Function to get the area of cakes below the cut
float getBottomArea(vector<cake>& cakes, float cut) {
    float bottomArea = 0;
    for (cake c : cakes) {
        if (c.y < cut) {
            bottomArea += c.side * c.side;
        }
    }
    return bottomArea;
}

// Function to find the best horizontal cut using binary search
float findBestCut(vector<cake>& cakes) {
    float totalArea = getTotalArea(cakes);
    float left = 0;
    float right = FLT_MAX;
    float bestCut = 0;
    float minDiff = FLT_MAX;

    sort(cakes.begin(), cakes.end(), [](cake a, cake b) { return a.y < b.y; });

    while (left <= right) {
        float mid = left + (right - left) / 2;
        float bottomArea = getBottomArea(cakes, mid);
        float topArea = totalArea - bottomArea;
        float diff = abs(bottomArea - topArea);

        if (diff < minDiff) {
            minDiff = diff;
            bestCut = mid;
        }

        if (bottomArea < topArea) {
            left = mid + 0.01; // Adjust precision as needed
        } else {
            right = mid - 0.01; // Adjust precision as needed
        }
    }

    return bestCut;
}

int main() {
    int n = 5;
    vector<cake> cakes = {{1.0, 1.0, 3.0}, {5.0, 1.0, 2.0}, {8.0, 1.0, 1.0}, {4.0, 5.0, 2.0}, {4.0, 5.0, 2.0}};
    float bestCut = findBestCut(cakes);
    cout << "Best horizontal cut is at y = " << bestCut << endl;
    return 0;
}