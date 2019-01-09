#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int queue[MAX];
int front = 0, rear = 0;

int push(int X) {
	/*if ((rear + 1) % MAX == front) {
		printf("queue OVERFLOW!!\n");
		return -1;
	}*/
	queue[rear] = X;
	rear = (rear + 1) % MAX;
	return X;
}

int pop() {
	int k;
	/*if (front == rear) {
		printf("queue UNDERFLOW!!\n");
		return -1;
	}*/
	k = queue[front];
	queue[front] = 0;
	front = ++front % MAX;
	return k;
}

int main(void) {
	int N = 0, M = 0;
	int count = 0, k = 0;
	scanf("%d %d", &N, &M); // N : 사람 수, M : M번째 사람 수
	
	int *result = (int*)calloc(N, sizeof(int));

	for (int i = 1; i <= N; i++) {
		printf("%d ",push(i));
	}
	printf("\n");

	/*for (int i = 0; i < N; i++) {
		printf("%d ", queue[i]);
	}
	printf("\n");*/

	for (int i = 0; i < N; i++) {
		count = 0;
		for (int j = 0; j < M + count - 1; j++) {
			if (queue[j] == 0) {
				count++;
			}
			front = ++front % N;
			if (front >= N) front -= N;
		}
		//k = front;
		result[i] = pop();
	}
	printf("<");
	for (int i = 0; i < N; i++) {
		printf("%d", result[i]);
		if (i != N - 1) printf(", ");
	}
	printf(">");

	return 0;
}