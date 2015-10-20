/*
01-复杂度2 Maximum Subsequence Sum   (25分)
Given a sequence of K integers {N1, N2, ..., NK}. 
A continuous subsequence is defined to be { Ni, Ni+1,
..., Nj} where 1≤i≤j≤K. The Maximum Subsequence is
the continuous subsequence which has the largest sum 
of its elements. For example, given sequence { -2, 11,
-4, 13, -5, -2 }, its maximum subsequence is { 11, -4,
13 } with the largest sum being 20.

Now you are supposed to find the largest sum, together
with the first and the last numbers of the maximum 
subsequence.

Input Specification:

Each input file contains one test case. Each case 
occupies two lines. The first line contains a positive 
integer K (≤10000). The second line contains K numbers,
separated by a space.

Output Specification:

For each test case, output in one line the largest sum, 
together with the first and the last numbers of the 
maximum subsequence. The numbers must be separated by 
one space, but there must be no extra space at the end 
of a line. In case that the maximum subsequence is not 
unique, output the one with the smallest indices i and 
j (as shown by the sample case). If all the K numbers 
are negative, then its maximum sum is defined to be 0, 
and you are supposed to output the first and the last 
numbers of the whole sequence.

Sample Input:

10
-10 1 2 3 4 -5 -23 3 7 -21
Sample Output:

10 1 4
*/
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