#include <stdio.h>
// 벌집이 형성되는 규칙 찾기
int main(void) {
	int N;
	scanf("%d", &N);
	int d = 6;
	int sum = 1, n = 0;
	while(1){
		n++;
		sum += (n - 1)*d; // ´©Àû? µîÂ÷¼ö¿­
		if (N <= sum) {
			printf("%d\n", n);
			return 0;
		}
	}	
}
