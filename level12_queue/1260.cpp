// 1260
// 문제: DFS와 BFS
#include <iostream>
#include <vector>
#include <algorithm>

typedef struct _node {
	int key;
	struct _node *prev;
	struct _node *next;
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

void push(int k) {
	node *t = (node*)calloc(1, sizeof(node));
	
	t->key = k;
	t->next = head->next;
	head->next = t;
}

int front() {
	node *t;
	int k;
	if (head->next == tail) return -1;
	t = head->next;
	k = t->key;
	return k;
}

int pop() {
	node *t;
	int k;
	if (head->next == tail) return -1;
	
	t = head->next;
	k = t->key;
	head->next = t->next;
	free(t);
	return k;
}

void free_stack() {
	node *t, *s;
	t = head;
	while (t->next != tail) {
		s = t->next;
		t->next = s->next;
		free(s);
		t = t->next;
	}
	head->next = tail;
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

	tail->prev = t->prev;
	t->prev->next = tail;	
	free(t);
	return k;
}

int isempty() {
	node *t;
	t = head;
	if (t->next == tail) return 1;
	else return 0;
}

int main(void) {
	int N, M, start;
	std::vector<int> a[1001];
	std::cin >> N >> M >> start;
	int i;

	for (i = 0; i < M; i++) {
		int u, v;
		std::cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for (i = 0; i < N; i++) {
		sort(a[i].begin(), a[i].end());
	}

	init_queue();
	
	//DFS
	bool check_dfs[1001] = { false };
	push(start);
	check_dfs[start] = true;
	std::cout << start << ' ';
	while (!isempty()) {
		int now = front();		
		int num=a[now].size();
		int count = 0;
		for (i = 0; i < num; i++) {
			int next = a[now][i];
			if (check_dfs[next] == false) {
				push(next);
				check_dfs[next] = true;
				std::cout << next << ' ';
				break;
			}
			else count++;
			if (count == num) {
				pop();
			}
		}
	}
	std::cout << '\n';

	//BFS
	bool check[1001] = { false };
	enqueue(start);
	check[start] = 1;
	while(!isempty()) {
		int now=dequeue();
		std::cout << now << ' ';
		int num = a[now].size();
		for (i = 0; i < num; i++) {
			if (check[a[now][i]] != true) {
				enqueue(a[now][i]);
				check[a[now][i]] = true;
			}
		}
	}
	return 0;
}
// DFS는 pop하면서 확인하는게 아니라 front를 보면서 진행