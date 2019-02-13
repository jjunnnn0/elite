// 3036 링
#include <iostream>

using namespace std;

int main(void) {
	int T;
	cin >> T;
	long long int a, b, GCD, LCM;
	cin >> a;
	int A = a;
	for (int i = 1; i < T; i++) {
		cin >> b;
		a = A;
		int B = b;
		while (1) {
			long long int r = a % b;
			if (r == 0)break;
			a = b;
			b = r;
		}
		GCD = b;
		cout << A / GCD << '/' << B / GCD<<endl;
	}
	return 0;
}