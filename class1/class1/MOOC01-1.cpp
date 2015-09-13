#include <iostream>
using namespace std;

int maxSubSum(int a[], int n) {
	int maxSum = 0, thisSum = 0;
	for (int i = 0; i < n; i++) {
		thisSum += a[i];
		if (thisSum > maxSum) {
			maxSum = thisSum;
		}
		else if (thisSum < 0) {
			thisSum = 0;
		}
	}
	return maxSum;
}

int main() {
	int K;
	int num[100000];
	cin >> K;
	for (int i = 0; i != K; i++) {
		cin >> num[i];
	}
	cout<<maxSubSum(num, K);
	return 0;
}