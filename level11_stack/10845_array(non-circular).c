// 10845 배열 사용하기 (circular x)
// 문제 : 큐
#include <stdio.h>
#include <stdlib.h>

int queue[10000];
int rear = -1;
int front = 0;
int push(int X) {
	if (rear == 9999) {
		printf("queue OVERFLOW!\n");
		return 0;
	}
	queue[++rear] = X;
	return X;
}

int pop() {
	if (rear + 1 == front) return -1;
	return queue[front++];
}

int size() {
	return rear - front + 1;
}

int empty() {
	if (rear + 1 == front) return 1;
	else return 0;
}

int first() {
	if (rear + 1 == front) return -1;
	else return queue[front];
}

int back() {
	if (rear + 1 == front) return -1;
	else return queue[rear];
}

int main(void) {
	int N = 0;
	int trash = 0;
	scanf("%d", &N);
	scanf("%d", &trash); // \n 넣어두기 위함

	int *result = (int*)calloc(N, sizeof(int)); // 한번에 출력하기 위한 결과값들 저장
	int count_push = 0;

	for (int i = 0; i < N; i++) {
		char input[100];
		gets_s(input);
		
		if (input[2] == 's') { // push
			for (int j = 0; j < 6; j++) {
				input[j] = input[j + 5];
				input[j + 5] = '\0'; // 문자열의 끝을 알리는 null 문자 넣기				
			}
			push(atoi(input)); // 이거 문자열 바꾸는 for문에 넣으면 안돼...
			count_push++;			
			continue;
		}

		if (input[1] == 'o') { // pop
			result[i - count_push] = pop();
			continue;
		}
		if (input[0] == 's') { // size
			result[i - count_push] = size();
			continue;
		}
		if (input[1] == 'm') { // empty
			result[i - count_push] = empty();
			continue;
		}
		if (input[0] == 'f') { // front
			result[i - count_push] = first();
			continue;
		}
		if (input[1] == 'a') { // back
			result[i - count_push] = back();
			continue;
		}
	}
	
	for (int i = 0; i < N - count_push; i++) {
		printf("%d\n", result[i]);		
	}
	
	return 0;
}
// if 문 조건에서 제발 = 이거 안쓰고 제대로 == 썻나 확인하자