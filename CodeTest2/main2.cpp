// Baekjoon Problem. 
// No. 10844
// type : DP

#include <iostream>
#include <vector>

#define OUTPUT_NUM 1000000000
using namespace std;

vector<vector<int>> myCache(11, vector<int>(101, 0));

void makeStairNum(int n, int number, int* result) {
	if (number < 0 || number > 9 || n < 1) {
		return;
	}
	if (number == 9 && myCache[number - 1][n - 1] != 0) {
		myCache[number][n] = (myCache[number - 1][n - 1]) % OUTPUT_NUM;
		*result = (*result + myCache[number - 1][n - 1]) % OUTPUT_NUM;
		return;
	}else if (number == 0 && myCache[number + 1][n - 1] != 0) {
		myCache[number][n] = (myCache[number + 1][n - 1]) % OUTPUT_NUM;
		*result = (*result + myCache[number + 1][n - 1]) % OUTPUT_NUM;
		return;
	}
	else if (myCache[number + 1][n - 1] != 0 && myCache[number - 1][n - 1] != 0) {
		myCache[number][n] = (myCache[number - 1][n - 1] + myCache[number + 1][n - 1]) % OUTPUT_NUM;
		*result = (*result + myCache[number][n]) % OUTPUT_NUM;;
		return;
	}
	if (n == 1) {
		myCache[number][n] = 1;
		*result = (*result + 1) % OUTPUT_NUM;;;
		return;
	}
	makeStairNum(n - 1, number + 1, result);
	makeStairNum(n - 1, number - 1, result);

}

int main() {
	int n, number=0, result=0;
	scanf("%d", &n);
	for (int i = 1; i < 10; i++) {
		makeStairNum(n, i, &result);
	}
	printf("%d", result % OUTPUT_NUM);
	return 0;
}