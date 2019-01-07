// 10828
// 문제: 스택
// 정수를 저장하는 스택을 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int stack[10000] = { 0 };
int index = -1;

void push(int X) {
	stack[++index] = X;
}

int pop() {
	if (index == -1) return -1;
	int output = stack[index--];
	stack[index + 1] = 0; // index가 하나 줄어들었으므로 index+1에 0 넣어야함
	return output;
}

int size() {
	return index + 1;
}

int isempty() {
	if (index == -1) return 1;
	else return 0;
}

int top() {
	if (index == -1) return -1;
	else return stack[index];
}

int main(void) {
	int X = 0, N = 0;
	int cmp = 0;
	int pushes = 0;
	int trash = 0;
	
	scanf("%d", &N);
	scanf("%d", &trash);
	int *result = (int*)calloc(N, sizeof(int));
	for (int i = 0; i < N; i++) {
		char input[20];
		X = 0; // X 는 매번 초기화
		gets_s(input); // 명령 입력받기 scanf는 정수와 구분이 안되서 gets_s 씀
		if (input[1]=='u') {
			for (int j = 0; j < 6; j++) {
				input[j] = input[j + 5];
				input[j + 5] = '\0';
			}
			X = atoi(input);
			push(X);
			pushes++; // push 되면 result에 저장 안되게 하기
			//printf("push!\n");
			continue;
		}
		cmp = strcmp(input, "pop");
		if (cmp == 0) {
			result[i - pushes] = pop();
			//printf("pop!\n");
			continue;
		}
		cmp = strcmp(input, "size");
		if(cmp == 0){
			result[i - pushes] = size();
			//printf("size!\n");
			continue;
		}
		cmp = strcmp(input, "empty");
		if (cmp == 0) {
			result[i - pushes] = isempty();
			//printf("empty!\n");
			continue;
		}
		cmp = strcmp(input, "top");
		if (cmp == 0) {
			result[i - pushes] = top();
			//printf("top!\n");
			continue;
		}
	}

	for (int i = 0; i < N - pushes; i++) { // push 횟수 고려하여 for문 실행
		printf("%d\n", result[i]);
	}

	return 0;
}
// scanf로 입력을 받으려고 했으나 scanf는 push X 에서 X를 따로 구분하기 힘들고 구분하더라도 pop이나
// size empty는 정수를 입력 안받으므로 예외사항이 너무 많아져서 더 간단한 gets_s 사용
