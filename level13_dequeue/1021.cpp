// 1021 회전하는 큐
#include <iostream>
using namespace std;

typedef struct _node {
	int key;
	struct _node *prev;
	struct _node *next;
}node;

node *head, *tail;

void init_dequeue() {
	head = (node*)calloc(1, sizeof(node));
	tail = (node*)calloc(1, sizeof(node));
	
	head->next = tail;
	head->prev = head;
	tail->next = tail;
	tail->prev = head;
}

void push_front(int N) {
	node *t = (node*)calloc(1, sizeof(node));
	t->key = N;
	tail->prev->next = t;
	t->prev = tail->prev;
	tail->prev = t;
	t->next = tail;	
}

int pop_front() {
	node *t;
	int k;
	t = head->next;
	if (t == tail) return -1;
	k = t->key;
	head->next = t->next;
	t->next->prev = head;
	return k;
}

int move_left() {
	int k;
	node* t;
	t = head->next;
	head->next = t->next;
	t->next->prev = head;

	t->next = tail;
	t->prev = tail->prev;
	tail->prev->next = t;
	tail->prev = t;

	k = head->next->key;
	return k;
}

int move_right() {
	int k;
	node *t;
	t = tail->prev;
	t->prev->next = tail;
	tail->prev = t->prev;

	t->next = head->next;
	head->next->prev = t;
	t->prev = head;
	head->next = t;

	k = t->key;
	return k;
}

int front() {
	node *t;
	int k;
	t = head->next;
	if (t == tail) return -1;
	k = t->key;
	return k;
}
int search_prev(int k) {
	node *t;
	int count = 0;
	
	t = tail->prev;
	count++;
	while (t->key != k) {
		t = t->prev;
		count++;
		if (t == head) t = tail->prev;
	}
	return count;
}

int search_next(int k) {
	node *t;
	int count = 0;

	t = head->next;
	while (t->key != k) {
		t = t->next;
		count++;
		if (t == tail) t = head->next;
	}
	return count;
}

void print_dequeue() {
	node *t;
	t = head->next;
	if (t == tail) {
		cout << "NO DEQUEUE" << endl;
		return;
	}
	while(t!=tail) {
		cout << t->key << ' ';
		t = t->next;
	}
	cout << endl;
}

int main(void) {
	int N, M; // N: 큐의 개수, M: 뽑아내려는 수
	cin >> N >> M;
	init_dequeue();
	int input[50];
	for (int i = 1; i <= N; i++) {
		push_front(i);
	}
	//print_dequeue();
	for (int i = 0; i < M; i++) {
		cin >> input[i];
	}

	int i = 0;
	int count = 0;
	int left, right;
	while (M != 0) {
		if (input[i] == front()) {
			pop_front();
			M--;
			i++;
			continue;
		}
		left = search_next(input[i]);
		right = search_prev(input[i]);
		//cout << "left " << left << "right " << right << endl;
		if (left >= right) {
			for (int j = 0; j < right; j++) {
				move_right();
			}
			count += right;
		}
		else if (right > left) {
			for (int j = 0; j < left; j++) {
				move_left();
			}
			count += left;
		}
	}

	cout << count;

	
	return 0;
}
// 순환 덱(큐)로 짜려고 했으나 실패