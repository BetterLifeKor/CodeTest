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

vector <int> canEat[MAX_n], eaters[MAX_n];
int n, m;
int best;

void search(vector<int>& edible, int chosen) {
	if (chosen >= best) return;

	int first = 0;
	while (first < n && edible[first] > 0) ++first;

	if (first == n) { 
		best = chosen;// < best ? chosen : best;
		return; 
	}
	FOR(i, canEat[first].size()) {
		int food = canEat[first][i];
		FOR(j, eaters[food].size()){
			edible[eaters[food][j]]++;
		}
		search(edible, chosen + 1);
		FOR(j, eaters[food].size()) {
			edible[eaters[food][j]]--;
		}
	}
}

int main() {
	int T, mm;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		map<string, int> myMap;
		vector <int> edible(n, 0);
		FOR(i, MAX_m) {
			eaters[i].clear();
		}
		FOR(i, MAX_n) {
			canEat[i].clear();
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
				canEat[myMap[input2]].push_back(i);
			}
		}
		search(edible, 0);
		cout << best << endl;
	}
	return 0;
}