// #include<iostream>
// using namespace std;
// int main(){
//     int i=0;
//     int n=90;
//     while(i*i<=n){
//         i++;
//     }
//     cout<<i-1;
// }

// //time-> O(root(n))


#include <iostream>
#include <cmath>
using namespace std;

double findSquareRoot(int number, int precision) {
    int low = 0, high = number;
    int intPart = 0;

    // Step 1: Binary Search for the integer part
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (mid * mid <= number) {
            intPart = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    // Step 2: Linear Search for the decimal part
    double result = intPart;
    double increment = 0.1;
    for (int i = 0; i < precision; i++) {
        while (result * result <= number) {
            result += increment;
        }
        result -= increment; // Step back as we exceeded the value
        increment /= 10;     // Reduce the increment for the next decimal place
    }

    return result;
}

int main() {
    int number = 10;
    int precision = 5;
    double root = findSquareRoot(number, precision);

    cout << "Square root of " << number << " is " << root << endl;
    return 0;
}
