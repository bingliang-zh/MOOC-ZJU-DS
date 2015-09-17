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