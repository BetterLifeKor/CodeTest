#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	for (int i = 1; i <= s.size(); i++) {
		if (s[i] != s[i - 1]) {
			break;
		}
	}


	int T, a, b;
	int flag = 0;
	cin >> s;
	cin >> T;
	while (T--) {
		cin >> a >> b;
		if (a > b) {
			int temp = b;
			b = a;
			a = temp;
		}
		flag = 0;
		for (int i = a+1; i <= b; i++) {
			if (s[i] != s[i - 1]) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
	return 0;
}