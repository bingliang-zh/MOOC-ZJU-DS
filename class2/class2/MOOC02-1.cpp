#include <iostream>
#include <vector>
using namespace std;

class node {
public:
	int coef;//系数
	int exp;//指数
};

void initVec(vector<node>& param) {
	int count;
	cin >> count;
	node temp;
	for (int i = 0; i < count; i++) {
		cin >> temp.coef >> temp.exp;
		param.push_back(temp);
	}
}

void printVec(vector<node>& param) {
	int size = param.size();
	if (size == 0) {
		cout << "0 0"<<endl;
		return;
	}
	cout << param[0].coef << ' ' << param[0].exp;
	for (int i = 1; i < size; i++) {
		cout << ' ' << param[i].coef << ' ' << param[i].exp;
	}
	cout << endl;
}

void calcSum(vector<node>& a, vector<node>& b, vector<node>& sum) {
	vector<node>::iterator it1,it2;
	it1 = a.begin();
	it2 = b.begin();
	while (it1 != a.end() || it2 != b.end()) {
		if (it1 == a.end()) {
			node temp = *it2;
			sum.push_back(temp);
			it2++;
		}
		else if (it2 == b.end()) {
			node temp = *it1;
			sum.push_back(temp);
			it1++;
		}
		else if (it1->exp > it2->exp) {
			node temp = *it1;
			sum.push_back(temp);
			it1++;
		}
		else if (it1->exp < it2->exp) {
			node temp = *it2;
			sum.push_back(temp);
			it2++;
		}
		else if(it1->exp == it2->exp){
			node temp = *it1;
			temp.coef += it2->coef;
			if (temp.coef != 0) {
				sum.push_back(temp);
			}
			it1++;
			it2++;
		}
	}
}

void insertNode(vector<node>& pro, node nd) {
	if (nd.coef == 0) {
		return;
	}
	if (pro.size() == 0) {
		pro.push_back(nd);
		return;
	}
	vector<node>::iterator it;
	for (it = pro.begin(); it != pro.end(); it++) {
		if (nd.exp == it->exp) {
			it->coef += nd.coef;
			if (it->coef == 0) {
				pro.erase(it);
			}
			return;
		}
		else if (nd.exp > it->exp) {
			pro.insert(it, nd);
			return;
		}
	}
	pro.insert(it, nd);
	return;
}

void calcPro(vector<node>& a, vector<node>& b, vector<node>& pro) {
	vector<node>::iterator it1, it2;
	for (it1 = a.begin(); it1 != a.end(); it1++) {
		for (it2 = b.begin(); it2 != b.end(); it2++) {
			node temp;
			temp.coef = it1->coef * it2->coef;
			temp.exp = it1->exp + it2->exp;
			insertNode(pro, temp);
		}
	}
}

int main() {
	vector<node> a;
	vector<node> b;
	vector<node> sum;
	vector<node> pro;
	initVec(a);
	initVec(b);
	calcSum(a, b, sum);
	calcPro(a, b, pro);
	printVec(pro);
	printVec(sum);
	system("pause");
	return 0;
}