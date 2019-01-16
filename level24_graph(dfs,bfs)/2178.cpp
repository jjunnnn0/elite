// 2178
// 문제: 미로탐색
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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
	tail->next = tail;
	head->prev = head;
	tail->prev = head;
}

void enqueue(int k) {
	node *t = (node*)calloc(1, sizeof(node));
	t->key = k;

	t->next = head->next;
	head->next->prev = t;
	t->prev = head;
	head->next = t;
}

void dequeue() {
	node *t;
	int k;
	if (tail->prev == head) return;
	t = tail->prev;
	k = t->key;
	tail->prev = t->prev;
	t->prev->next = tail;
	free(t);
}

int front() {
	node *t;
	int k;
	if (tail->prev == head) return -1;
	t = tail->prev;
	k = t->key;
	return k;
}

int isempty() {
	node *t;
	t = head->next;
	if (t == tail) return 1;
	else return 0;
}

void print_queue() {
	node *t;
	t = tail->prev;
	if (t == head) cout<<"no queue\n";
	cout << "queue: ";
	while(t!=head){
		cout << t->key << ' ';
		t = t->prev;
	}
	cout << '\n';
}

int main(void) {
	int m, n;
	cin >> m >> n;
	int *check = (int*)calloc(m*n+1, sizeof(int));
	int *graph = (int*)calloc(m*n, sizeof(int));
	vector<int> edge[1001];
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> check[i*m + j + 1]; 
			graph[i*m + j] = i * m + j + 1;			
		}
	}
	// 미로 잘 들어갔나 확인
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << check[i*m + j + 1] << ' ';
		}
		cout << '\n';
	}
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			int now = y * m + x + 1;
			if (x + 1 < m && check[y*m + x + 1] == 1) edge[now].push_back(graph[y*m + x + 1]);
			if (y + 1 < n && check[(y + 1)*m + x] == 1) edge[now].push_back(graph[(y + 1)*m + x]);
			if (x - 1 >= 0 && check[y*m + x - 1] == 1) edge[now].push_back(graph[y*m + x - 1]);
			if (y - 1 >= 0 && check[(y - 1)*m + x] == 1) edge[now].push_back(graph[(y - 1)*m + x]);

		}
	}
	// edge 확인
	for (int i = 1; i <= m*n; i++) {
		cout << i << ' ';
		for (int j = 0; j < edge[i].size(); j++) {
			cout << edge[i][j] << ' ';
		}
		cout << '\n';
	}

	init_queue();
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (check[i*m + j + 1] == 1) {
				enqueue(graph[i*m + j]);
				//cout << "enqueue " << graph[i*m + j] << '\n';
			}
		}
	}
	//print_queue();
	

	while (!isempty()) {
		int now = front();
		dequeue();
		//cout << now << ' ';
		int num = edge[now].size();
		for (int j = 0; j < num; j++) {
			int next = edge[now][j];
			if (check[next] == 0) {
				enqueue(next);
				//cout << "enqueue " << next << '\n';
			}
		}
		count++;
	}
		
	cout << count;

	return 0;
}