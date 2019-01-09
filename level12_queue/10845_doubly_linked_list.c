// 10845 doubly linked list 사용
// 큐 구현하기
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int key;
	struct _node *next;
	struct _node *prev;
}node;

node *head, *tail;

void init_queue() {
	head = (node*)calloc(1, sizeof(node));
	tail = (node*)calloc(1, sizeof(node));

	head->next = tail;
	head->prev = head;
	tail->next = tail;
	tail->prev = head;	
}

void enqueue(int k) {
	node *t = (node*)calloc(1, sizeof(node));
	
	t->key = k;

	t->next = head->next;
	t->prev = head;
	t->next->prev = t;
	head->next = t;
}

int dequeue() {
	node *t; // 지울 노드
	t = tail->prev;
	if (t == head) return -1;
	node *s; // 지우기 전 노드, tail이랑 연결
	int k;
	k = t->key;

	s = tail->prev->prev;
	s->next = tail;
	tail->prev = s;
	free(t);
	return k;
}

int size() {
	int count = 0;
	node *t;
	t = head;
	while (t->next != tail) {
		t = t->next;
		count++;
	}
	return count;
}

int empty() {
	node *t;
	t = head;
	if (t->next == tail) return 1;
	else return 0;
}

int front() {
	node *t;
	t = tail->prev;
	if (t == head) return -1;
	else return t->key;
}

int back() {
	node *t;
	t = head->next;
	if (t == tail) return -1;
	else return t->key;
}

int main(void) {
	int N;
	scanf("%d", &N);
	getchar();
	init_queue();

	for (int i = 0; i < N; i++) {
		char input[20];
		int num = 0;
		scanf("%s", &input);
		if (input[1] == 'u') {
			scanf("%d", &num);
			enqueue(num);
			continue;
		}
		if (input[1] == 'o') {
			printf("%d\n", dequeue());
			continue;
		}
		if (input[1] == 'i') {
			printf("%d\n", size());
			continue;
		}
		if (input[1] == 'm') {
			printf("%d\n", empty());
			continue;
		}
		if (input[1] == 'r') {
			printf("%d\n", front());
			continue;
		}
		if (input[1] == 'a') {
			printf("%d\n", back());
			continue;
		}
	}
	return 0;
}