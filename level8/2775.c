// 제목: 부녀회장이 될테야
// 층과 거주자 수의 규칙을 찾는 문제
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int T = 0;// test case T
	scanf("%d", &T);
	
	int *k = (int*)calloc(T, sizeof(int));// k층
	int *n = (int*)calloc(T, sizeof(int));// n호
	
	int *apartment = (int*)calloc(15 * 14, sizeof(int)); // 1<=k,n<=14 임
	// a층은 0층부터 b호는 1호부터이니 헷갈리지 말기
	// indexing할때는 a는 0부터 해서 상관없으나 b는 하나 빼야됨.
	for (int a = 0; a <= 14; a++) { // a층
		for (int b = 0; b < 14; b++) { // b호
			if (a == 0) apartment[a * 14 + b] = b + 1;
			else {
				for (int i = 0; i <= b; i++) { // 밑에 층 사람들 더하기
					apartment[a * 14 + b] += apartment[(a - 1) * 14 + i];
				}
			}
		}
	}
	for (int i = 0; i < T; i++) {
		scanf("%d", &k[i]);
		scanf("%d", &n[i]);
	}
	for (int i = 0; i < T; i++) {
		printf("%d\n", apartment[k[i] * 14 + n[i]-1]); // b호는 1호부터 이므로 index는 -1 해주기
	}
}