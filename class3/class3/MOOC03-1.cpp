/*
03-树1 树的同构   (25分)
给定两棵树T1和T2。如果T1可以通过若干次左右孩子互
换就变成T2，则我们称两棵树是“同构”的。例如图1给
出的两棵树就是同构的，因为我们把其中一棵树的结点
A、B、G的左右孩子互换后，就得到另外一棵树。而图2
就不是同构的。

图1略
图2略

现给定两棵树，请你判断它们是否是同构的。
输入格式:

输入给出2棵二叉树树的信息。对于每棵树，首先在一行
中给出一个非负整数N (≤10)，即该树的结点数（此时
假设结点从0到N−1编号）；随后N行，第i行对应编号第i
个结点，给出该结点中存储的1个英文大写字母、其左孩
子结点的编号、右孩子结点的编号。如果孩子结点为空，
则在相应位置上给出“-”。给出的数据间用一个空格分
隔。注意：题目保证每个结点中存储的字母是不同的。

输出格式:

如果两棵树是同构的，输出“Yes”，否则输出“No”。

输入样例1（对应图1）：

8
A 1 2
B 3 4
C 5 -
D - -
E 6 -
G 7 -
F - -
H - -
8
G - 4
B 7 6
F - -
A 5 1
H - -
C 0 -
D - -
E 2 -
输出样例1:

Yes
输入样例2（对应图2）：

8
B 5 7
F - -
A 0 3
C 6 -
H - -
D - -
G 4 -
E 1 -
8
D 6 -
B 5 -
E - -
H - -
C 0 2
G - 3
F - -
A 1 4
输出样例2:

No
*/

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