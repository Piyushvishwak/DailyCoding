#include <iostream>
#include <vector>
using namespace std;

int lowerBoundBinary(const vector<int>& arr, int target) {
    int low = 0, high = arr.size();
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid; // Narrow down to the left half
        }
    }
    return low; // `low` now holds the index of the lower bound
}

int main() {
    vector<int> arr = {1, 3, 3,3, 7, 9};
    int target = 3;
    int index = lowerBoundBinary(arr, target);
    if (index < arr.size() && arr[index] >= target) {
        cout << "Lower bound of " << target << " is at index " << index;
    } else {
        cout << "No lower bound found for " << target;
    }
    return 0;
}
