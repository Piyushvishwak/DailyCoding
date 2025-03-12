#include <iostream>
#include <vector>

using namespace std;

void generateSubsequences(const vector<int>& input, vector<vector<int>>& subsequences, vector<int>& current, int index) {
    if (index == input.size()) {
        subsequences.push_back(current);
        return;
    }

    current.push_back(input[index]);
    generateSubsequences(input, subsequences, current, index + 1);

    current.pop_back();
    generateSubsequences(input, subsequences, current, index + 1);
}

vector<vector<int>> getAllSubsequences(const vector<int>& input) {
    vector<vector<int>> subsequences;
    vector<int> current;
    generateSubsequences(input, subsequences, current, 0);
    return subsequences;
}

int main() {
    vector<int> input = {1, 2, 3};
    vector<vector<int>> subsequences = getAllSubsequences(input);

    cout << "All Subsequences:" << endl;
    for (const auto& subsequence : subsequences) {
        cout << "{ ";
        for (int num : subsequence) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}