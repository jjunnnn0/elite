//2748 피보나치 수 2
//입력받는수가 더 커진다면?
#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n; // n이 90일때는 19자리
	long long fibo;
	long long prev = 0;
	long long now = 1;
	for (int i = 1; i < n; i++) {
		fibo = prev + now;
		prev = now;
		now = fibo;
	}
	if (n == 1) cout << 1;
	else cout << fibo;
	return 0;
}

// memoization 적용
#include <iostream>

using namespace std;
long long int memo[100];
long long int fibonacci(long long int n) {
	if (n <= 1)
		return n;
	else if (memo[n] != 0)
		return memo[n];
	else
		return memo[n] = (fibonacci(n - 1) + fibonacci(n - 2));	
}

int main(void) {
	long long int n;
	cin >> n;
	
	cout << fibonacci(n);
	return 0;
}