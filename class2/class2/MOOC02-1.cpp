/*
02-线性结构1 一元多项式的乘法与加法运算   (20分)
设计函数分别求两个一元多项式的乘积与和。

输入格式:

输入分2行，每行分别先给出多项式非零项的个数，再以
指数递降方式输入一个多项式非零项系数和指数（绝对值
均为不超过1000的整数）。数字间以空格分隔。

输出格式:

输出分2行，分别以指数递降方式输出乘积多项式以及和
多项式非零项的系数和指数。数字间以空格分隔，但结尾
不能有多余空格。零多项式应输出0 0。

输入样例:

4 3 4 -5 2  6 1  -2 0
3 5 20  -7 4  3 1
输出样例:

15 24 -25 22 30 21 -10 20 -21 8 35 6 -33 5 14 4 -15 3 18 2 -6 1
5 20 -4 4 -5 2 9 1 -2 0
*/

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