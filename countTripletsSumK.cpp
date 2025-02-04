#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 4, 0, 6, 8};
    int k = 8;
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int count = 0;

    for (int i = 0; i < n - 2; i++) {
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int sum = arr[i] + arr[left] + arr[right];
            if (sum <= k) {
                count++;
                left++;
                right--;
            } else {
                right--;
            }
        }
    }

    cout << count << endl;
    return 0;
}
