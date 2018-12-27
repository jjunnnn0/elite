#include <stdio.h>
// 분수 찾기
int main(void) {
	int N;
	scanf("%d", &N);
	int n = 0, sum = 0, i = 0;
	while (1) {
		n++;
		sum += n;
		if (N <= sum) {
			i = sum - N;
			if (n % 2 == 1) printf("%d/%d\n", i + 1, n - i); // n이 홀수일 경우
			if (n % 2 == 0) printf("%d/%d\n", n - i, i + 1); // n이 짝수일 경우
			return 0;
		}
	}	
}