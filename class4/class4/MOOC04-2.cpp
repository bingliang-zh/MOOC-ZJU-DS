/*
04-树5 Root of AVL Tree   (25分)
An AVL tree is a self-balancing binary search tree. In an AVL 
tree, the heights of the two child subtrees of any node differ 
by at most one; if at any time they differ by more than one, 
rebalancing is done to restore this property. Figures 1-4 
illustrate the rotation rules.

Figures 1-4 omitted

Now given a sequence of insertions, you are supposed to tell 
the root of the resulting AVL tree.
Input Specification:

Each input file contains one test case. For each case, the 
first line contains a positive integer N (≤20) which is the 
total number of keys to be inserted. Then N distinct integer 
keys are given in the next line. All the numbers in a line are 
separated by a space.

Output Specification:

For each test case, print the root of the resulting AVL tree 
in one line.

Sample Input 1:

5
88 70 61 96 120
Sample Output 1:

70
Sample Input 2:

7
88 70 61 96 120 90 65
Sample Output 2:

88
*/
#include <iostream>
#include <algorithm>
using namespace std;

class AVLNode {
public:
	int value;
	int height;
	AVLNode *lson;
	AVLNode *rson;
	AVLNode() {
		height = 1;
		lson = NULL;
		rson = NULL;
	}
};

int getHeight(AVLNode * tree) {
	if (tree) return tree->height;
	else return 0;
}

void updateHeight(AVLNode * tree) {
	tree->height = max(getHeight(tree->lson), getHeight(tree->rson)) + 1;
}

AVLNode * LLRotate(AVLNode * tree) {
	AVLNode * left = tree->lson;
	tree->lson = left->rson;
	left->rson = tree;

	updateHeight(tree);
	updateHeight(left);
	return left;
}

AVLNode * RRRotate(AVLNode * tree) {
	AVLNode * right = tree->rson;
	tree->rson = right->lson;
	right->lson = tree;

	updateHeight(tree);
	updateHeight(right);
	return right;
}

AVLNode * LRRotate(AVLNode * tree) {
	AVLNode * left = tree->lson;
	AVLNode * root = left->rson;
	tree->lson = root->rson;
	left->rson = root->lson;
	root->lson = left;
	root->rson = tree;

	updateHeight(left);
	updateHeight(tree);
	updateHeight(root);
	return root;
}

AVLNode * RLRotate(AVLNode * tree) {
	AVLNode * right = tree->rson;
	AVLNode * root = right->lson;
	tree->rson = root->lson;
	right->lson = root->rson;
	root->lson = tree;
	root->rson = right;

	updateHeight(tree);
	updateHeight(right);
	updateHeight(root);
	return root;
}

AVLNode * insert(AVLNode * tree, int var) {
	if (tree == NULL) {
		tree = new AVLNode;
		tree->value = var;
	}
	else if (var < tree->value) {
		tree->lson = insert(tree->lson, var);
		if (2 == getHeight(tree->lson) - getHeight(tree->rson)) {
			if (var < tree->lson->value) {
				tree = LLRotate(tree);
			}
			else {
				tree = LRRotate(tree);
			}
		}
	}
	else if (var > tree->value) {
		tree->rson = insert(tree->rson, var);
		if (2 == getHeight(tree->rson) - getHeight(tree->lson)) {
			if (var > tree->rson->value) {
				tree = RRRotate(tree);
			}
			else {
				tree = RLRotate(tree);
			}
		}
	}
	updateHeight(tree);
	return tree;
}

int main() {
	int N;
	cin >> N;
	AVLNode * tree = NULL;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		tree = insert(tree, temp);
	}

	cout << tree->value << endl;

	system("pause");
	return 0;
}