/*
05-树7 堆中的路径   (25分)
将一系列给定数字插入一个初始为空的小顶堆H[]。随后对任意给定的
下标i，打印从H[i]到根结点的路径。

输入格式:

每组测试第1行包含2个正整数N和M(≤1000)，分别是插入元素的个数、
以及需要打印的路径条数。下一行给出区间[-10000, 10000]内的N个要
被插入一个初始为空的小顶堆的整数。最后一行给出M个下标。

输出格式:

对输入中给出的每个下标i，在一行中输出从H[i]到根结点的路径上的
数据。数字间以1个空格分隔，行末不得有多余空格。

输入样例:

5 3
46 23 26 24 10
5 4 3
输出样例:

24 23 10
46 23 10
26 10
*/

#include <iostream>
using namespace std;

void swap(int &A, int&B);
void insertMinHeap(int H[], int i, int var);
void printPath(int H[], int i);

int main() {
	int H[1024];
	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		int var;
		cin >> var;
		insertMinHeap(H, i, var);
	}


	for (int i = 0; i < M; i++) {
		int index;
		cin >> index;
		printPath(H, index);
	}

	system("pause");
	return 0;
}

void swap(int &A, int&B) {
	int temp;
	temp = A;
	A = B;
	B = temp;
}

void insertMinHeap(int H[], int i, int var) {
	if (i == 1) {
		H[i] = var;
		return;
	}
	H[i] = var;
	for (; i > 1; i /= 2) {
		if (H[i / 2] > H[i]) {
			swap(H[i / 2], H[i]);
		}
	}
}

void printPath(int H[], int i) {
	while (i > 1) {
		cout << H[i] << ' ';
		i /= 2;
	}
	cout << H[i] << endl;
}