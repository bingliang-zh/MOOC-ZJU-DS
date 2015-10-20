/*
01-复杂度1 最大子列和问题   (20分)

给定K个整数组成的序列{N1, N2, ...,NK}，“连续子列”
被定义为{Ni, Ni+1, ..., Nj}，其中 1≤i≤j≤K。“最
大子列和”则被定义为所有连续子列元素的和中最大者。
例如给定序列{ -2, 11, -4, 13, -5, -2 }，其连续子列
{ 11, -4, 13 }有最大的和20。现要求你编写程序，计算
给定整数序列的最大子列和。

输入格式:

输入第1行给出正整数K (≤100000)；第2行给出K个整数，
其间以空格分隔。

输出格式:

在一行中输出最大子列和。如果序列中所有整数皆为负数，
则输出0。

输入样例:

6
-2 11 -4 13 -5 -2
输出样例:

20
*/
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