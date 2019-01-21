// 10866 덱
#include <iostream>

using namespace std;

typedef struct _node {
	int key;
	struct _node *prev;
	struct _node *next;
}node;

node *head, *tail;

void init_dequeue(){
	head = (node*)calloc(1, sizeof(node));
	tail = (node*)calloc(1, sizeof(node));

	head->next = tail;
	tail->next = tail;
	head->prev = head;
	tail->prev = head;
}

void push_front(int X) {//tail쪽이 앞
	node *t = (node*)calloc(1, sizeof(node));
	
	t->key = X;
	t->next = tail;
	tail->prev->next = t;
	t->prev = tail->prev;
	tail->prev = t;
}

void push_back(int X) { // 이게 enqueue
	node *t = (node*)calloc(1, sizeof(node));
	
	t->key = X;
	t->next = head->next;
	t->prev = head;
	head->next->prev = t;
	head->next = t;
}

int pop_front() {
	node *t;
	int k;
	t = tail->prev;
	if (t == head) return -1;
	
	k = t->key;
	t->prev->next = tail;
	tail->prev = t->prev;
	free(t);
	return k;
}

int pop_back() {
	node *t;
	int k;
	t = head->next;
	if (t == tail) return -1;

	k = t->key;
	head->next = t->next;
	t->next->prev = head;
	free(t);
	return k;
}

int size() {
	node *t;
	int count = 0;
	t = head->next;
	while (t != tail) {
		count++;
		t = t->next;
	}
	return count;
}

int isempty() {
	node *t;
	t = head->next;
	if (t == tail)return 1;
	else return 0;
}

int front() {
	node *t;
	int k;
	t = tail->prev;
	k = t->key;
	if (t == head) return -1;
	else return k;
}

int back() {
	node *t;
	int k;
	t = head->next;
	k = t->key;
	if (t == tail) return -1;
	else return k;
}

int main(void) {
	int n,num;
	cin >> n;

	init_dequeue();
	for (int i = 0; i < n; i++) {
		char input[20];
		cin >> input;
		if (input[1] == 'u'&& input[5] == 'f') {//push front
			cin >> num;
			push_front(num);
		}
		if (input[1] == 'u'&&input[5] == 'b') {//push back
			cin >> num;
			push_back(num);
		}
		if (input[1] == 'o'&&input[4] == 'f') {//pop front
			num = pop_front();
			cout << num << endl;
		}
		if (input[1] == 'o'&&input[4] == 'b') {//pop back
			num = pop_back();
			cout << num << endl;
		}
		if (input[1] == 'i') {
			num = size();
			cout << num << endl;
		}
		if (input[0] == 'e') {
			num = isempty();
			cout << num << endl;
		}
		if (input[0] == 'f') {
			num = front();
			cout << num << endl;
		}
		if (input[0] == 'b') {
			num = back();
			cout << num << endl;
		}
	}
	return 0;
}