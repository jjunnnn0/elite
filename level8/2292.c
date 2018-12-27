#include <stdio.h>
// 벌집이 형성되는 규칙 찾기
int main(void) {
	int N;
	scanf("%d", &N);
	int d = 6;
	int sum = 1, n = 0;
	while(1){
		n++;
		sum += (n - 1)*d; // 누적? 등차수열
		if (N <= sum) {
			printf("%d\n", n);
			return 0;
		}
	}	
}
// 벌집이 육각형이므로 각 단계별로 6개, 12개, 18개... 
// 6개씩 추가가 되어 증가한다.
// 처음에는 등차수열의 합인 줄 알았으나 그게 아니였다.
// 수학이 부족하다 수학을 해야한다