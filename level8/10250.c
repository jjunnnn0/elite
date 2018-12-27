#include <stdio.h>
#include <stdlib.h>
// ACM 호텔
// 손님이 도착하는 대로 빈 방을 배정해주기
int main(void) {
	int T = 0; // 테스트 케이스 수
	scanf("%d", &T);
	int *H = (int*)calloc(T, sizeof(int)); // 층 수
	int *W = (int*)calloc(T, sizeof(int)); // 호 수
	int *N = (int*)calloc(T, sizeof(int)); // 몇 번째 손님

	int floor = 0, roomNo = 0;

	for (int i = 0; i < T; i++) {
		scanf("%d %d %d", &H[i], &W[i], &N[i]);
	}
	for (int i = 0; i < T; i++) {
		floor = N[i] % H[i];
		if (floor == 0) floor += H[i]; // 맨 위층이면 층 수 만큼 더하기 
		
		roomNo = N[i] / H[i] + 1; // 0호가 아닌 1호부터 시작이므로 + 1
		if (N[i] % H[i] == 0) roomNo -= 1; // 맨 위층이면 -1 
		printf("%d\n", floor * 100 + roomNo);
	}
	return 0;
}