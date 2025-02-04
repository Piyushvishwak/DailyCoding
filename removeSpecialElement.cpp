#include <bits/stdc++.h>
using namespace std;


int cntIndexesToMakeBalance(int arr[], int n)
{

	if (n == 1) {
		return 1;
	}

	// If size of the array is 2
	if (n == 2)
		return 0;

	int sumEven = 0;
	int sumOdd = 0;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {

			sumEven += arr[i];
		}
		else {
			sumOdd += arr[i];
		}
	}
	int currOdd = 0;
	int currEven = arr[0];
	int res = 0;
	int newEvenSum = 0;
	int newOddSum = 0;

	for (int i = 1; i < n - 1; i++) {
		if (i % 2) {
			currOdd += arr[i];
			newEvenSum = currEven + sumOdd
						- currOdd;
			newOddSum = currOdd + sumEven
						- currEven - arr[i];
		}
		else {
			currEven += arr[i];
			newOddSum = currOdd + sumEven
						- currEven;
			newEvenSum = currEven + sumOdd
						- currOdd - arr[i];
		}
		if (newEvenSum == newOddSum) {
			res++;
		}
	}
	if (sumOdd == sumEven - arr[0]) {

		res++;
	}
	// If length of the array
	// is an odd number
	if (n % 2 == 1) {

		// If sum of even-indexed and odd-indexed
		// elements is equal by removing the last element
		if (sumOdd == sumEven - arr[n - 1]) {

			// Increase the count
			res++;
		}
	}

	// If length of the array
	// is an even number
	else {

		// If sum of even-indexed and odd-indexed
		// elements is equal by removing the last element
		if (sumEven == sumOdd - arr[n - 1]) {
			// Increase the count
			res++;
		}
	}
	return res;
}
// Driver Code
int main()
{

	int arr[] = { 1, 1, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << cntIndexesToMakeBalance(arr, n);
	return 0;
}
