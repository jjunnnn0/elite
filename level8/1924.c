// 2007년 x월 y일의 요일 찾기
// 1,3,5,7,8,10,12월 - 31일
// 4,6,9,11월 - 30일
// 2월 28일
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int x = 0, y = 0;
	scanf("%d %d", &x, &y);
	int *calendar = (int*)calloc(12 * 7, sizeof(int));
	char twoweeks[14] = { 0,1,2,3,4,5,6,0,1,2,3,4,5,6,}; // 0부터 월요일
	int firstday = 0; // 1월 1일은 월요일이므로 0부터 시작
	
	for (int i = 1; i <= 12; i++) {
		if (i == 2 || i == 4 || i == 6 || i == 8 || i == 9 || i == 11) // 4,6,8,9,11월은 +3요일
			firstday += 3;
		else if (i == 1 || i == 3) firstday = firstday; // 1월 3월은 +0 요일
		else firstday += 2; // 나머지 +2요일
		if (firstday >= 7) firstday %= 7;

		for (int j = 1; j <= 7; j++) {			
			calendar[(i - 1) * 7 + j - 1] = twoweeks[firstday + j - 1];
		}
	}

	y %= 7; // 요일 주기가 7이므로 7로 나눔
	if (y == 0) y += 7; // 0 이되면 밑에서 -1 이 되므로 주기 7이내에서 끝으로 가게끔 7을 더해줌
	firstday = calendar[(x - 1) * 7 + (y - 1)]; // firstday에 해당 날짜 저장하고 다음 조건문 만족 시 출력

	// 제대로 되었나 확인용
	//for (int i = 0; i < 12; i++) {
	//	printf("%d월 ", i + 1);
	//	for (int j = 0; j < 7; j++) {
	//		printf("%d ", calendar[i * 7 + j]);
	//	}
	//	printf("\n");
	//}
	if (firstday == 0) printf("%s\n", "MON");
	if (firstday == 1) printf("%s\n", "TUE");
	if (firstday == 2) printf("%s\n", "WED");
	if (firstday == 3) printf("%s\n", "THU");
	if (firstday == 4) printf("%s\n", "FRI");
	if (firstday == 5) printf("%s\n", "SAT");
	if (firstday == 6) printf("%s\n", "SUN");
	
	return 0;
}
// 1일이 무슨 요일부터 시작하는지 알아내고 일에 %7을 해서 요일 알아내기
// 4,6,9,11월은 30일이지만 요일에 영향을 주는건 해당 달이 아닌 전 달
// 즉, 4월이면 3월이 31일까지이므로 +3 해줘야함
// 근데 이거 index는 0부터 시작이고 달은 1부터 시작이라 너무 헷갈림...