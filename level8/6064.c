// 문제: 카잉 달력
// 카잉 제국의 달력을 구현하기
// 최소 공배수를 구해서 배열 크기 지정하고 저장한다음 비교하기
#include <stdio.h>
#include <stdlib.h>

// 시간초과
int main(void) {
	int T = 0, xx = 0, yy = 0, k = 0;// 1<=M,N<=40,000 , 1<=x<=M , 1<=y<=N
	
	scanf("%d", &T); // test case 수
	int *M = (int*)calloc(T, sizeof(int));
	int *N = (int*)calloc(T, sizeof(int));
	int *x = (int*)calloc(T, sizeof(int));
	int *y = (int*)calloc(T, sizeof(int));

	for (int i = 0; i < T; i++) {
		scanf("%d %d %d %d", &M[i], &N[i], &x[i], &y[i]);
	}

	for (int i = 0; i < T; i++) {
		xx = 1, yy = 1, k = 1;		
		while (1) {			
			printf("k: %d x: %d y:%d\n", k, xx, yy);
			if (xx < M[i] && yy < N[i]) {
				xx++;
				yy++;
				k++;
			}
			else if (xx == M[i] && yy < N[i]) {
				xx = 1;
				yy++;
				k++;
			}
			else if (xx < M[i] && yy == N[i]) {
				xx++;
				yy = 1;
				k++;
			}			
			
			if (xx == M[i] && yy == N[i]) {				
				printf("%d\n", -1);
				break;
			}

			if (xx == x[i] && yy == y[i]) {
				printf("%d\n", k);
				break;
			}
		}
	}
	return 0;
}