// Fly me to the Alpha Centauri
// 거리에 따른 장치 사용 횟수를 출력하는 문제
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int T=0; // T: test case, 
	scanf("%d", &T);
	int *x = (int*)calloc(T, sizeof(int)); // 0<=x<y<2^31, 2^31=2,147,483,648
	int *y = (int*)calloc(T, sizeof(int));

	int *minimum = (int*)calloc(92681, sizeof(int));
	int max = 0;
	for (int i = 1; i <= 92680; i++) { 
		if (i % 2 == 1) max++;
		minimum[i] = minimum[i - 1] + max;	
	}
	
	for (int i = 0; i < T; i++) {
		scanf("%d %d", &x[i], &y[i]);
	}

	int dist = 0;
	for (int i = 0; i < T; i++) {
		dist = y[i] - x[i];
		if (dist > minimum[92680]) { // 92,680보다 커지면 out of boundary
			printf("%d\n", 92681);
			continue;
		}
		for (int j = 0; j <= 92680; j++) {
			if (minimum[j] >= dist) { 
				printf("%d\n", j);
				break;
			}
		}
	}
	return 0;
}