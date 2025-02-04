#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to count subarrays with sum K
int countSubarraysWithSumK(const vector<int> &arr, int k) {
    unordered_map<int, int> prefixSumFreq; // Hashmap to store the frequency of prefix sums
    prefixSumFreq[0] = 1; // Special case for subarrays starting from index 0
    int cnt = 0;
    int ps = 0;
    for (int num : arr) {
        ps += num; // Update the current prefix sum
        // Calculate the number of subarrays with sum K ending at the current index
        if (prefixSumFreq.find(ps - k) != prefixSumFreq.end()) {
            cnt += prefixSumFreq[ps - k];
        }
        // Increment the frequency of the current prefix sum
        prefixSumFreq[ps]++;
    }
    return cnt;
}

int main() {
    vector<int> arr = {2,1,5,-6,2};
    int k = 2;
    int result = countSubarraysWithSumK(arr, k);
    cout << "Number of subarrays with sum " << k << " is: " << result << endl;
    return 0;
}