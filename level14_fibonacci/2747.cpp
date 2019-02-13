// 2747 피보나치 수
#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n; // n이 90일때는 19자리
	int fibo;
	int prev = 0;
	int now = 1;
	for (int i = 1; i < n; i++) {
		fibo = prev + now;
		prev = now;
		now = fibo;
	}
	if (n == 1) cout << 1;
	else cout << fibo;
	return 0;
}


// 메모이제이션 적용
#include <iostream>

using namespace std;
int memo[50];
int fibonacci(int n) {
	if (n <= 1)
		return n;
	else if (memo[n] != 0)
		return memo[n];
	else
		return memo[n] = (fibonacci(n - 1) + fibonacci(n - 2));	
}

int main(void) {
	int n;
	cin >> n;
	
	cout << fibonacci(n);
	return 0;
}