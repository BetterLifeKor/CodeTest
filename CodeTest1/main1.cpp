
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> A_vector(500001, 0);
vector<int> B_vector(500001, 0);

int maximumGcdAndSum(vector <int> A, vector <int> B, int n) {
	// Complete this function
	int MaxNum, cnt_a, cnt_b, num_a, num_b;
	int MaxA, MaxB;
	MaxA = *max_element(A.begin(), A.end());
	MaxB = *max_element(B.begin(), B.end());
	//sort(A.begin(), A.end(), [](const int a, const int b) {return a > b; });
	//sort(B.begin(), B.end(), [](const int a, const int b) {return a > b; });

	MaxNum = MaxA >= MaxB ? MaxA : MaxB;
	int j, k;
	for (int i = MaxNum; i >0; i--) {
		j = i;
		k = 1;
		cnt_a = 0;
		cnt_b = 0;
		num_a = 1;
		num_b = 1;
		while (j <= MaxNum) {
			if (A_vector[j] == 1) {
				cnt_a++;
				num_a = j;
			}
			if (B_vector[j] == 1) {
				cnt_b++;
				num_b = j;
			}

			k++;
			j = i * k;
		}
		if (cnt_a >0 && cnt_b >0) {
			return num_a + num_b;
		}

	}
	return MaxA + MaxB;
}

int main() {
	int n;
	cin >> n;
	vector<int> A(n);
	for (int A_i = 0; A_i < n; A_i++) {
		cin >> A[A_i];
		A_vector[A[A_i]] = 1;
	}
	vector<int> B(n);
	for (int B_i = 0; B_i < n; B_i++) {
		cin >> B[B_i];
		B_vector[B[B_i]] = 1;
	}
	int res = maximumGcdAndSum(A, B, n);
	cout << res << endl;
	return 0;
}

