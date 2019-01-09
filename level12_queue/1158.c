// 11866 && 1158
// 문제: 조세퍼스 문제 Joshepus problem
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int key;
	struct _node *next;
	struct _node *prev;
}node;

node *head,*tail;

void init_queue(int n) {
	head = (node*)calloc(1, sizeof(node));
	tail = (node*)calloc(1, sizeof(node));

	head->prev = head;
	head->next = tail;
	tail->prev = head;
	tail->next = tail;
}

void enqueue(int k) {
	node *t = (node*)calloc(1, sizeof(node));
	t->key = k;
	t->next = head->next;
	head->next->prev = t;
	t->prev = head;
	head->next = t;
}

int dequeue() {
	node *t;
	int k;
	if (tail->prev == head) return -1;
	t = tail->prev;		
	k = t->key;
	t->prev->next = tail;
	tail->prev = t->prev;
	free(t);
	return k;
}

int size() {
	node *t;
	int count = 0;
	t = head;
	while (t->next != tail) {
		t = t->next;
		count++;
	}
	return count;
}

int main(void) {
	int N = 0, M = 0; // N: 사람수, M: interval
	scanf("%d %d", &N, &M);
		
	init_queue(N);
	for (int i = 1; i <= N; i++) {
		enqueue(i);		
	}

	printf("<");
	while (size() != 1) {
		for (int i = 0; i < M - 1; i++) {
			enqueue(dequeue());
		}
		printf("%d, ", dequeue());		
	}
	printf("%d>\n",dequeue());

	return 0;
}
// circular로 하는건 실패. 직선 queue도 어렵게 성공