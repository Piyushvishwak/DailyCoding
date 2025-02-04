#include <bits/stdc++.h>
#include <vector>

using namespace std;

vector<long long> computeFib(int maxN, long long mod) {
    vector<long long> fib(maxN + 1);
    fib[0] = 0;
    if (maxN > 0)
        fib[1] = 1;
    for (int i = 2; i <= maxN; ++i) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
    }
    return fib;
}

int main() {
    const long long MOD = 1000000007;

    vector<int> queries = {4, 32, 4, 3, 43, 23};
    int maxQuery = *max_element(queries.begin(), queries.end());

    vector<long long> fibSeries = computeFib(maxQuery, MOD);

    for (int query : queries) {
        cout << "Fibonacci(" << query << ") = " << fibSeries[query] << "\n";
    }

    return 0;
}