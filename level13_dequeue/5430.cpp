// 5430 AC
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
	tail->next = tail;
	head->prev = head;
	tail->prev = head;
}

void tail_head() {
	head->next->prev = tail;
	tail->next = head->next;
	
	head->next = head;
	head->prev = tail->prev;
	
	tail->prev->next = head;
	tail->prev = tail;	
}

void head_tail() {
	head->next = tail->next;
	tail->prev = head->prev;
	tail->next->prev = head;
	head->prev->next = tail;
	head->prev = head;
	tail->next = tail;
}

int discard() {
	node *t;
	t = head->next;
	if (t == tail) {
		cout << "error" << endl;
		return -1;
	}
	head->next = t->next;
	t->next->prev = head;
	free(t);
	return 1;
}

int discard_reverse() {
	node *t;
	t = head->prev;
	if (t == tail) {
		cout << "error" << endl;
		return -1;
	}
	t->prev->next = head;
	head->prev = t->prev;
	free(t);
	return 1;
}

void clear_dequeue() {
	node *t;
	t = head;
	while (t->next!= tail) {
		node *s;
		s = t->next;
		t->next = s->next;
		s->next->prev = t;
		free(s);
	}
	head->next = tail;
	tail->prev = head;
}

void push_front(int k) {
	node *t = (node*)calloc(1, sizeof(node));
	
	t->key = k;
	t->prev = tail->prev;
	tail->prev->next = t;
	t->next = tail;
	tail->prev = t;
}

void print_dequeue() {
	node *t;
	t = head->next;
	if (t == tail) {
		cout << "[]" << endl;
		return;
	}
	cout << "[";
	while (t->next != tail) {
		cout << t->key << ',';
		t = t->next;
	}
	cout << t->key << ']' << endl;
}

void print_reverse() {
	node *t;
	t = head->prev;
	if (t == tail) {
		cout << "[]" << endl;
		return;
	}
	cout << '[';
	while (t->prev != tail) {
		cout << t->key << ',';
		t = t->prev;
	}
	cout << t->key << ']' << endl;
}

int main(void) {
	int T; // no. of test cases
	cin >> T;

	init_dequeue();
	for (int i = 0; i < T; i++) {
		char p[100001]; // 함수입력
		int n; // 배열에 들어있는 수의 개수
		char arr[400001]; // [1,2,3...] 형태의 배열
		cin >> p;
		cin >> n;
		cin >> arr;
		//int *input = (int*)calloc(n, sizeof(int));
		for (int j = 1; j < 400001; j++) { // 홀수번째에 숫자가 들어가있다.
			if (arr[j] == ']' || arr[j] == ',') continue;
			if (arr[j] == '\0') break;
			else {
				char num[4] = { '\0' };
				num[0] = arr[j];
				if (arr[j + 1] != ',' && arr[j + 1] != ']') {
					j++;
					num[1] = arr[j];
					//cout <<"num "<< num << endl;
					if (arr[j + 1] != ',' && arr[j + 1] != ']') {						
						j++;
						num[2] = arr[j];
						//cout << "num " << num << endl;
					}
				}
				//cout << "j "<<j<<' '<<atoi(num) << endl;
				push_front(atoi(num));
			}
		}
		//print_dequeue();
		//cout << "!!!!";
		bool REVERSE = false;
		int error = 0;
		for (int j = 0; j < 100001; j++) {
			if (p[j] == 'R') {
				if (REVERSE) {
					head_tail();
					REVERSE = false;
				}
				else if (!REVERSE) {
					tail_head();
					REVERSE = true;
				}
				//cout << REVERSE << endl;
				//cout << "REVERSE"<<endl;
				//print_dequeue();
			}
			if (p[j] == 'D') {
				if (REVERSE) error=discard_reverse();
				if (!REVERSE) error=discard();
				if (error == -1) break;
			}
			if (p[j] == '\0') break;
		}
		if (error == -1) {// error 발생시 print 안함
			if (REVERSE) head_tail();
			clear_dequeue();
			continue;
		}

		if (REVERSE) {
			print_reverse();
			head_tail(); // clear_dequeue를 위해 원래 순서로 돌려놓기
		}
		if (!REVERSE) print_dequeue();
		clear_dequeue();
	}
	return 0;
}
// reverse일때랑 아닐때를 구분해서 함수로 만듬 - 너무 어렵게 짠듯. 개까다로움
// 주의사항!!
// 빈 배열 []일때 R을 하면 error가 나는게 아니라 []이 출력되어야 한다.
// arr가 1의자리만 들어오는게 아니라 100까지 들어올수 있다.
// error 발생했을때 또 print하면 안되고 그때 reverse상태일수도있으니 reverse이면 되돌리기