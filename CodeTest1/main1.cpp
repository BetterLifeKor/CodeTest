// Date   : 2017.8.18.
// Title  : LGE CodeJam 1
// Editor by Jihoon Kim

//_CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#define FOR(i,n) for(int i =0; i<n; i++)

using namespace std;

int MIN(int a, int b) { return a < b ? a : b; }
int MAX(int a, int b) { return a > b ? a : b; }
int MAX3(int a, int b, int c) { return MAX(MAX(a, b), c); }
int MIN3(int a, int b, int c) { return MIN(MIN(a, b), c); }

void displayV(vector<int> v) { for (auto a : v) printf("%d\n", a); }
void displayV2(vector<vector<int>> v) {
	int n_r = v.size(); int n_c = v[0].size();
	for (int i = 0; i < n_r; i++) {
		for (int j = 0; j < n_c; j++) { printf("%d\t", v[i][j]); }
		printf("\n");
	}
}
void displayVS(vector<string> v) { for (auto a : v) printf("%s", a.c_str()); printf("\n"); }
void displayQ(queue<int> q) {
	while (!q.empty()) {
		printf("%d\n", q.front());
		q.pop();
	}
}

bool find_Q(queue<int> Q, int value) {
	bool flag = false;
	while (!Q.empty()) {
		if (Q.front() == value)
		{
			flag = true; break;
		}
		Q.pop();
	}
	return flag;
}
int find_Q2(queue<int> Q, queue<int> Q2, int value) {
	while (!Q.empty()) {
		if (Q.front() == value)	break;
		Q.pop(); Q2.pop();
	}
	return Q2.front();
}
int count_Q(queue<int> Q, int value) {
	int count = 0;
	while (!Q.empty()) {
		if (Q.front() == value) count++;
		Q.pop();
	}
	return count;
}

vector<int> myV; // myV = vector<int>(num_r,0)
vector<int> myD; // myD = vector<int>(num_r,0)

vector<vector<int>> myV2; // myV2 = vector<vector<int>>(num_r,vector<int>(num_c,0))
vector<vector<int>> myD2; // myD2 = vector<vector<int>>(num_r,vector<int>(num_c,0))

queue<int> myQ;

int main() {
	int t, n;

	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		printf("%d\n", n);
	}
	return 0;
}