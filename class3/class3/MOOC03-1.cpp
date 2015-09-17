#include <iostream>
using namespace std;

class Node {
public:
	char value;
	int left;
	int right;
};

int initTree(Node tree[]) {
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		char val;
		char left, right;
		cin >> val >> left >> right;
		tree[i].value = val;
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
	return -1;
}

bool isomorphism(Node t1[], int r1, Node t2[], int r2) {
	if (r1 == -1 && r2 == -1) {
		return true;
	}
	if (t1[r1].value != t2[r2].value) {
		return false;
	}
	int t1LS = t1[r1].left;
	int t1RS = t1[r1].right;
	int t2LS = t2[r2].left;
	int t2RS = t2[r2].right;
	if (t1LS == -1 
		&& t1RS == -1
		&& t2LS == -1
		&& t2RS == -1) {
		return true;
	}
	else if (t1LS == -1) {
		if (t2LS == -1 && t1[t1RS].value == t2[t2RS].value) {
			return isomorphism(t1, t1RS, t2, t2RS);
		}
		else if (t2RS == -1 && t1[t1RS].value == t2[t2LS].value) {
			return isomorphism(t1, t1RS, t2, t2LS);
		}
		else {
			return false;
		}
	}
	else if (t1RS == -1) {
		if (t2LS == -1 && t1[t1LS].value == t2[t2RS].value) {
			return isomorphism(t1, t1LS, t2, t2RS);
		}
		else if (t2RS == -1 && t1[t1LS].value == t2[t2LS].value) {
			return isomorphism(t1, t1LS, t2, t2LS);
		}
		else {
			return false;
		}
	}
	else if (t1[t1LS].value == t2[t2LS].value
		&&t1[t1RS].value == t2[t2RS].value) {
		return (isomorphism(t1, t1LS, t2, t2LS)
			&& isomorphism(t1, t1RS, t2, t2RS));
	}
	else if (t1[t1LS].value == t2[t2RS].value
		&&t1[t1RS].value == t2[t2LS].value) {
		return (isomorphism(t1, t1LS, t2, t2RS)
			&& isomorphism(t1, t1RS, t2, t2LS));
	}
	else {
		return false;
	}
}


int main() {
	Node tree1[10];
	Node tree2[10];
	int count1 = initTree(tree1);
	int count2 = initTree(tree2);
	int root1 = getRoot(tree1, count1);
	int root2 = getRoot(tree2, count2);
	bool flag = isomorphism(tree1, root1, tree2, root2);
	if (flag) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	system("pause");
	return 0;
}