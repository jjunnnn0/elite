// 문제: 방 번호
// 다솜이의 옆집에서는 플라스틱 숫자를 한 세트로 판다. 
// 한 세트에는 0번부터 9번까지 숫자가 하나씩 들어있다.
// 다솜이의 방 번호가 주어졌을 때, 필요한 세트의 개수의 최솟값을 출력하시오. 
// 6은 9를 뒤집어서 이용할 수 있고, 9는 6을 뒤집어서 이용할 수 있다.
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int N = 0;
	scanf("%d", &N);
	int *numbers = (int*)calloc(9, sizeof(int)); // 0부터 8까지 9칸 (9는 6으로)
	int digit = 1; // 자릿수를 위한 변수
	int prev_digit = 1; // break문을 위한 변수
	int unit_digit = 0;
	int max_N = 1000000;
	while (1) {
		if (N % digit == N % max_N) break; // 맨 밑 주석 참고
		digit *= 10;
		unit_digit = N % digit / prev_digit;
		if (unit_digit == 9) unit_digit = 6; // 6 이거나 9이면 6에 카운트
		//printf("unit digit=%d\n", unit_digit);
		numbers[unit_digit]++;
		prev_digit = digit;		
	}
	if (N == 0) numbers[0]++; // N이 0부터 이므로 0도 고려
	if (numbers[6] % 2 == 1) numbers[6] += 1; // 2로 나누면 버림이니까 1 더해주기
	numbers[6] /= 2; // 6에 9도 count했으니 2로 나누기
	
	int max = -10000;
	for (int i = 0; i < 9; i++) {
		if (numbers[i] > max) max = numbers[i];
	}
	printf("%d", max);
	
	return 0;
}
// while안 if문에서 원래 N % digit == N % prev_digit 하면 break하려고 했으나
// 10003 같은 경우 0이 연속되다보면 break하는 경우가 생기므로
// N의 최대값인 1,000,000으로 나누었을때의 나머지를 비교해서 break하도록 하였다.