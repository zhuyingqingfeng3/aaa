#include<iostream>
#include<list>
#include<algorithm>
using namespace std;
//生成一个数组快速排序函数
void quickSort(int a[], int low, int high) {
	int i = low, j = high;
	int temp = a[low];
	while (i < j) {
		while (i < j && a[j] >= temp)
			j--;
		if (i < j)
			a[i++] = a[j];
		while (i < j && a[i] <= temp)
			i++;
		if (i < j)
			a[j--] = a[i];
	}
	a[i] = temp;
	if (low < i - 1)
		quickSort(a, low, i - 1);
	if (high > i + 1)
		quickSort(a, i + 1, high);
}
//生成一个数组冒泡排序函数
void bubbleSort(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (a[j] > a[j + 1]) {
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
//生成一个可以在字符串a中查找字符串b出现位置的函数
int get(string s, string b, int k) {
	int a = s.find(b, k);
	return a;
}
//生成一个判断是否是素数的函数
bool isPrime(int n) {
	if (n == 1)
		return false;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}
struct dd {
	int a;
	int b;
};
//生成一个给结构体dd排序的函数，规则是a越大越好，a相同的情况下b越小越好
bool cmp(dd a, dd b) {
	if (a.a > b.a)
		return true;
	else if (a.a == b.a)
		return a.b < b.b;
	else
		return false;
}
//创建一个临接表储存图的邻接表
int k[20][20];
//shengcheng一个对k深度遍历的函数
void dfs(int n, int v) {
	cout << v << " ";
	for (int i = 1; i <= n; i++) {
		if (k[v][i] == 1)
			dfs(n, i);
	}
}
//shengcheng一个对k广度遍历的函数
void bfs(int n, int v) {
	list<int> q;
	q.push_back(v);
	cout << v << " ";
	while (!q.empty()) {
		v = q.front();
		q.pop_front();
		for (int i = 1; i <= n; i++) {
			if (k[v][i] == 1) {
				q.push_back(i);
				cout << i << " ";
			}
		}
	}
}
//生成对k的拓扑排序的函数
void topo(int n) {
	int cnt = 0;
	int v = 0;
	for (int i = 1; i <= n; i++) {
		if (k[i][0] == 0) {
			cnt++;
			v = i;
		}
	}
	if (cnt > 1)
		cout << "不是拓扑排序" << endl;
	else {
		dfs(n, v);
		cout << endl;
	}
}

int get(string s, string b, int k) {
	int a = s.find(b, k);
	return a;
}
int get(string s, string b, int k) {
	int a = s.find(b, k);
	return a;
}
typedef list<int>chain;
int main(){
	//声明一个整数变量啊
	string s="acbca";
	string b="c";
	cout<<get(s,b,1);
	




    
}

