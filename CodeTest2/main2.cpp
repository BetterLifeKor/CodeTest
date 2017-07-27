#include <iostream>
#include <vector>
#include <map>

//#define FOR(i,n) for( int i = 0 ; i < n ; i++)


using namespace std;

int getZeroPeriod(int n) {
	return n * (n + 1) / 2;
}
int getSubArray(int a, int b) {
	return a * b;
}

int solve(int x, int y) {
	return x + y;
}

class myClass {
public:
	int size = 0;
	vector<int> myVector;
};

map<int, myClass > myMap;
int main() {
	int n;
	int q;
	cin >> n >> q;
	vector<int> arr(n);
	for (int arr_i = 0; arr_i < n; arr_i++) {
		cin >> arr[arr_i];
		if (myMap[arr[arr_i]].size == 0) {
			vector<int> temp_vector(8000);
			temp_vector[0] = arr_i;
			myMap[arr[arr_i]].myVector = temp_vector;
			myMap[arr[arr_i]].size++;
		}
		else {
			int pos = myMap[arr[arr_i]].size;
			myMap[arr[arr_i]].myVector[pos] = arr_i;
			myMap[arr[arr_i]].size++;
		}
	}
	for (int a0 = 0; a0 < q; a0++) {
		int x;
		int y;
		cin >> x >> y;
		// Write Your Code Here
		cout << solve(x, y) << endl;
		
	}
	return 0;
}