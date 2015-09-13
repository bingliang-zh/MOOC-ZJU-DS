#include <iostream>
using namespace std;

void maxSubSum(int a[], int n) {
	bool flag = false;
	for (int i = 0; i < n; i++) {
		if (a[i] >= 0) {
			flag = true;
		}
	}
	if (!flag) {
		cout << 0 << ' ' << a[0] << ' ' << a[n-1];
		return;
	}
	int maxSum = 0, thisSum = 0;
	int maxHead = 0, thisHead = 0;
	int	end = 0;
	bool flag2 = false;
	for (int i = 0; i < n; i++) {
		thisSum += a[i];
		if (thisSum > maxSum) {
			maxSum = thisSum;
			end = i;
			maxHead = thisHead;
		}
		else if (thisSum == maxSum&&thisSum == 0&&!flag2) {
			flag2 = true;
			maxHead = i;
			end = i;
		}
		else if (thisSum < 0) {
			thisSum = 0;
			thisHead = i + 1;
		}
	}
	cout<<maxSum<<' '<<a[maxHead]<<' '<<a[end];
}

int main() {
	int K;
	int num[10000];
	cin >> K;
	for (int i = 0; i != K; i++) {
		cin >> num[i];
	}
	maxSubSum(num, K);
	system("pause");
	return 0;
}