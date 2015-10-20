/*
04 - 树4 是否同一棵二叉搜索树(25分)

给定一个插入序列就可以唯一确定一棵二叉搜索树。然而，一棵给定的二叉搜索树却
可以由多种不同的插入序列得到。例如分别按照序列{2, 1, 3}和{ 2, 3, 1 }插入初
始为空的二叉搜索树，都得到一样的结果。于是对于输入的各种插入序列，你需要判
断它们是否能生成一样的二叉搜索树。

输入格式 :
输入包含若干组测试数据。每组数据的第1行给出两个正整数N(≤10)和L，分别是每个
序列插入元素的个数和需要检查的序列个数。第2行给出N个以空格分隔的正整数，作
为初始插入序列。最后L行，每行给出N个插入的元素，属于L个需要检查的序列。
简单起见，我们保证每个插入序列都是1到N的一个排列。当读到N为0时，标志输入结
束，这组数据不要处理。

输出格式 :
对每一组需要检查的序列，如果其生成的二叉搜索树跟对应的初始序列生成的一样，
输出“Yes”，否则输出“No”。

输入样例 :
4 2
3 1 4 2
3 4 1 2
3 2 4 1
2 1
2 1
1 2
0

输出样例:
Yes
No
No
*/

#include <iostream>
using namespace std;

class BSTNode {
public:
	int key;
	BSTNode * left;
	BSTNode * right;
public:
	BSTNode() {
		left = NULL;
		right = NULL;
	}
};

BSTNode * insert(BSTNode * tree, int val);
bool isSame(BSTNode * tree, BSTNode * tree_n);

int main() {
	int N, L;
	cin >> N;
	while (N != 0) {
		cin >> L;
		BSTNode * tree = NULL;
		for (int i = 0; i < N; i++) {
			int temp;
			cin >> temp;
			tree = insert(tree, temp);
		}

		for (int j = 0; j < L; j++) {
			BSTNode * tree_new = NULL;
			for (int i = 0; i < N; i++) {
				int temp;
				cin >> temp;
				tree_new = insert(tree_new, temp);
			}

			if (isSame(tree, tree_new)) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
		}
		cin >> N;
	}

	system("pause");
	return 0;
}

BSTNode * insert(BSTNode * tree, int val) {
	if (tree == NULL) {
		tree = new BSTNode;
		tree->key = val;
	}
	else if (val < tree->key){
		if (tree->left == NULL) {
			tree->left = new BSTNode;
			tree->left->key = val;
		}
		else {
			insert(tree->left, val);
		}
		
	}
	else if (val > tree->key) {
		if (tree->right == NULL) {
			tree->right = new BSTNode;
			tree->right->key = val;
		}
		else {
			insert(tree->right, val);
		}
	}
	return tree;
}

bool isSame(BSTNode * tree, BSTNode * tree_n) {
	if (tree == NULL && tree_n == NULL) {
		return true;
	}
	else if (tree == NULL &&tree_n != NULL || tree != NULL&&tree_n == NULL) {
		return false;
	}
	else if (tree->key == tree_n->key) {
		return isSame(tree->left, tree_n->left) && isSame(tree->right, tree_n->right);
	}
	else {
		return false;
	}
}