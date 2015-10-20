/*
03-树2 List Leaves   (25分)
Given a tree, you are supposed to list all the 
leaves in the order of top down, and left to 
right.

Input Specification:

Each input file contains one test case. For each 
case, the first line gives a positive integer 
N (≤10) which is the total number of nodes in 
the tree -- and hence the nodes are numbered from 
0 to N−1. Then N lines follow, each corresponds 
to a node, and gives the indices of the left and 
right children of the node. If the child does not 
exist, a "-" will be put at the position. Any pair 
of children are separated by a space.

Output Specification:

For each test case, print in one line all the 
leaves' indices in the order of top down, and left 
to right. There must be exactly one space between 
any adjacent numbers, and no extra space at the end 
of the line.

Sample Input:

8
1 -
- -
0 -
2 7
- -
- -
5 -
4 6
Sample Output:

4 1 5
*/

#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
	int num;
	int left;
	int right;
};

int initTree(Node tree[]) {
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		tree[i].num = i;
		char left, right;
		cin >> left >> right;
		if (left == '-') {
			tree[i].left = -1;
		}
		else {
			tree[i].left = left - '0';
		}
		if (right == '-') {
			tree[i].right = -1;
		}
		else {
			tree[i].right = right - '0';
		}
	}
	return num;
}

int getRoot(Node tree[], int count) {
	bool isRoot[10];
	for (int i = 0; i < 10; i++) {
		isRoot[i] = true;
	}
	for (int i = 0; i < count; i++) {
		int left = tree[i].left;
		int right = tree[i].right;
		if (left != -1) {
			isRoot[left] = false;
		}
		if (right != -1) {
			isRoot[right] = false;
		}
	}
	for (int i = 0; i < count; i++) {
		if (isRoot[i] == true) {
			return i;
		}
	}
}

void printLeaves(Node tree[], int root) {
	queue<Node> q;
	queue<Node> leaves;
	q.push(tree[root]);
	while (!q.empty()) {
		Node a = q.front();
		q.pop();
		if (a.left == -1 && a.right == -1) {
			leaves.push(a);
		}
		if (a.left != -1) {
			q.push(tree[a.left]);
		}
		if (a.right != -1) {
			q.push(tree[a.right]);
		}
	}
	cout << leaves.front().num;
	leaves.pop();
	while (!leaves.empty()) {
		cout<<' '<< leaves.front().num;
		leaves.pop();
	}
}

int main() {
	Node tree[10];
	int count	= initTree(tree);
	int root	= getRoot(tree, count);
	printLeaves(tree,root);
	system("pause");
	return 0;
}