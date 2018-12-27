#include <stdio.h>
// 별 찍기-1
// 출력 예시의 별 모양을 보고 규칙을 유추해 봅니다
int main(void) {
	int N;
	scanf("%d", &N);
	for (int j = 1; j < N; j++) {
		for (int i = 0; i < j+1; i++) {
			printf("*");
		}
		printf("\n");
	}	
}