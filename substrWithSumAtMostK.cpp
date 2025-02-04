#include <iostream>
#include <vector>
using namespace std;

int maxSubArraySumAtMostK(vector<int>& arr, int k) {
    int cnt = 0;
    int sum = 0;
    int res = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > k) {
            cnt = 0;
            sum = 0;
            continue;
        }
        if (arr[i] + sum <= k) {
            cnt++;
            sum += arr[i];
        } else {
            cnt++;
            sum += arr[i];
            while (sum > k) {
                sum -= arr[i - cnt + 1];
                cnt--;
            }
        }
        res = max(res, sum);
    }
    return res;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 7;
    cout << "Maximum subarray sum with sum at most " << k << " is: " << maxSubArraySumAtMostK(arr, k) << endl;
    return 0;
}