// Problem Name : KAKURO 2
// 알고스팟 11.7
// 문제유형 : 구현

#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_T 50
#define MAX_N 20
#define MAX_List 1000
#define FOR(i,n) for(int i = 0; i < n; i++)
using namespace std;

vector<vector<int>> myList(MAX_List, vector<int>(4, 0));

int solve(vector<vector<int>> myMatrix, int n) {
	int nList = -1;
	int tempSum = 0;
	bool flagSum = false;
	FOR(i, n) {
		tempSum = 0;
		flagSum = false;
		FOR(j, n) {
			if (myMatrix[i][j] == 0 ) {
				flagSum = false;
				tempSum = 0;
			} else if (~flagSum) {
				if (myMatrix[i][j-1] == 0) {
					nList = nList + 1;
					myList[nList][0] = i + 1;
					myList[nList][1] = j;
					myList[nList][2] = 0;
				}
				flagSum = true;
			}
			if (flagSum) {
				tempSum = tempSum + myMatrix[i][j];
				myList[nList][3] = tempSum;
			}
		}
	}
	FOR(j, n) {
		tempSum = 0;
		flagSum = false;
		FOR(i, n) {
			if (myMatrix[i][j] == 0) {
				flagSum = false;
				tempSum = 0;
			}
			else if (~flagSum) {
				if (myMatrix[i-1][j] == 0) {
					nList = nList + 1;
					myList[nList][0] = i;
					myList[nList][1] = j+1;
					myList[nList][2] = 1;
				}
				flagSum = true;
			}
			if (flagSum) {
				tempSum = tempSum + myMatrix[i][j];
				myList[nList][3] = tempSum;
			}
		}
	}
	return nList;
}

bool compare1(const vector<int> &a, const vector<int> &b) {
	return a[2] < b[2];
}
bool compare2(const vector<int> &a, const vector<int> &b) {
	return a[0] < b[0];
}
bool compare3(const vector<int> &a, const vector<int> &b) {
	return a[1] < b[1];
}

int main() {
	int t, n, temp, nList;
	scanf("%d", &t);
	printf("%d\n", t);
	while (t--) {
		scanf("%d", &n);
		printf("%d\n", n);
		vector<vector<int>> myMatrix(n, vector<int>(n, 0));
		FOR(i, n) {
			FOR(j, n) {
				scanf("%d", &temp);
				myMatrix[i][j] = temp;
				if (temp == 0) {
					printf("0");
				}
				else {
					printf("1");
				}
				if (j == n - 1) {
					printf("\n");
				}
				else {
					printf(" ");
				}
			}
		}

		nList = solve(myMatrix, n);
		printf("%d\n", nList + 1);

		sort(myList.begin(), myList.begin() + nList + 1, compare1);	
		
		int index;
		index = 0;
		FOR(i, nList) {
			if (myList[i][2] != myList[i + 1][2]) {
				sort(myList.begin() + index, myList.begin() + i + 1, compare2);
				index = i+1;
			}
			if( i == nList - 1)	sort(myList.begin() + index, myList.begin() + nList+1, compare2);
		}
		
		index = 0;
		FOR(i, nList) {
			if (myList[i][0] != myList[i + 1][0]) {
				sort(myList.begin() + index, myList.begin() + i+1, compare3);
				index = i + 1;
			}
			if (i == nList - 1)	sort(myList.begin() + index, myList.begin() + nList+1, compare3);
		}
		FOR(i, nList) {
			printf("%d %d %d %d\n", myList[i][0], myList[i][1], myList[i][2], myList[i][3]);
		}
		printf("%d %d %d %d", myList[nList][0], myList[nList][1], myList[nList][2], myList[nList][3]);
	}
	
	return 0;
}