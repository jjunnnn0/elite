#include <stdio.h>
// º° Âï±â-1
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