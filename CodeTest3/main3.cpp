#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

#define MAX_T 50
#define MAX_n 50
#define MAX_m 50

#define FOR(i,n) for( int i = 0 ; i < n ; i++)

using namespace std;

vector <int> eaters[MAX_n];
int n, m;
int best;

void slowSearch(int food, vector<int>& edible, int chosen) {
	if (chosen >= best) return;
	if (food == m) {
		if (find(edible.begin(), edible.end(), 0) == edible.end()) {
			best = chosen;
		}
		return;
	}
	slowSearch(food + 1, edible, chosen);

	FOR(j, eaters[food].size()) {
		edible[eaters[food][j]]++;
	}
	slowSearch(food + 1, edible, chosen + 1);
	FOR(j, eaters[food].size()) {
		edible[eaters[food][j]]--;
	}
	return;
}

int main() {
	int T, mm;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		map<string, int> myMap;
		vector <int> edible(n, 0);
		FOR(i, MAX_n) {
			eaters[i].clear();
		}
		best = n;
		FOR(i, n) {
			string input;
			cin >> input;
			myMap[input] = i;
		}
		FOR(i, m) {
			cin >> mm;
			FOR(j, mm) {
				string input2;
				cin >> input2;
				eaters[i].push_back(myMap[input2]);
			}
		}
		slowSearch(0, edible, 0);
		cout << best << endl;
	}
	return 0;
}