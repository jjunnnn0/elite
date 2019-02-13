// 1850 최대공약수와 최소공배수
#include <iostream>

using namespace std;

int main(void) {	
	long long int a, b, GCD, LCM;
	cin >> a >> b;		
	LCM = a * b;
	while (1) {
		long long int r = a % b;
		if (r == 0)break;
		a = b;
		b = r;
	}
	GCD = b;
	for (int i = 0; i < GCD; i++) {
		cout << '1';
	}
	
	return 0;
}