﻿// 1934 최소공배수
#include <iostream>

using namespace std;

int main(void) {
	int T;
	cin >> T;
	int a, b, GCD, LCM;
	for (int i = 0; i < T; i++) {
		cin >> a >> b;		
		LCM = a * b;
		while (1) {
			int r = a % b;
			if (r == 0)break;
			a = b;
			b = r;
		}
		GCD = b;
		LCM /= GCD;
		cout << LCM << endl;
	}
	return 0;
}