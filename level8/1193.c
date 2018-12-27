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
// 그려서 해보면 쉽다. n이 짝수일때 오름차순, 홀수일때 내림차순인걸 감안해서 코딩을 하면된다.