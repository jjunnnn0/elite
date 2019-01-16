// 7569
// 문제: 토마토 3D
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
	if (t == head) cout << "no queue\n";
	cout << "queue: ";
	while (t != head) {
		cout << t->key << ' ';
		t = t->prev;
	}
	cout << '\n';
}

int main(void) {
	int m, n, h;
	cin >> m >> n >> h;
	int *check = (int*)calloc(m*n*h + 1, sizeof(int));
	int *graph = (int*)calloc(m*n*h, sizeof(int));
	vector<int> edge[1001];
	int numof1s = 0;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> check[k*(m*n)+i*m + j + 1]; //토마토 상태는 check로
				graph[k*(m*n) + i * m + j] = k * (m*n) + i * m + j + 1;
				if (check[k*(m*n) + i * m + j + 1] == 1) numof1s++;// 익은 토마토 세기
			}
		}
	}
	// 토마토 상태 잘 들어갔나 확인
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << check[k*(m*n) + i * m + j + 1] << ' ';
			}
			cout << '\n';
		}
	}
	for (int i = 0; i < h; i++) {
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < m; x++) {
				int now = i * n * m + y * m + x + 1;
				if (x + 1 < m) edge[now].push_back(graph[i*n*m + y * m + x + 1]);
				if (y + 1 < n) edge[now].push_back(graph[i*n*m + (y + 1)*m + x]);
				if (x - 1 >= 0) edge[now].push_back(graph[i*n*m + y*m + x - 1]);
				if (y - 1 >= 0) edge[now].push_back(graph[i*n*m + (y - 1)*m + x]);
				if (i + 1 < h) edge[now].push_back(graph[(i + 1)*n*m + y * m + x]);
				if (i - 1 >= 0) edge[now].push_back(graph[(i - 1)*n*m + y * m + x]);
			}
		}
	}
	// edge들이 잘 들어갔나 확인
	for (int k = 0; k < h; k++) {
		for (int i = 1; i <= m * n; i++) {
			cout << k*m*n + i << ' ';
			for (int j = 0; j < edge[i].size(); j++) {
				cout << edge[i][j] << ' ';
			}
			cout << '\n';
		}
	}

	init_queue();
	int count = 0;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (check[k*(m*n) + i * m + j + 1] == 1) {
					enqueue(graph[k*(m*n) + i * m + j]);
					//cout << "enqueue " << graph[i*m + j] << '\n';
				}
			}
		}
	}
	//print_queue();
	//cout << "1의개수: " << numof1s << '\n';

	while (!isempty()) {
		for (int i = 0; i < numof1s; i++) {
			int now = front();
			dequeue();
			//cout << now << ' ';
			int num = edge[now].size();
			for (int j = 0; j < num; j++) {
				int next = edge[now][j];
				if (check[next] == 0) {
					enqueue(next);
					//cout << "enqueue " << next << '\n';
					check[next] = 1;
				}
			}
		}
		cout << '\n';
		for (int k = 0; k < h; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					cout << check[i*m + j + 1] << ' ';
				}
				cout << '\n';
			}
		}
		count++;
	}
	cout << '\n';
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (check[k*(m*n) + i * m + j + 1] == 0) { // 다 안익었으면 -1
					cout << -1;
					return 0;
				}
				cout << check[k*(m*n) + i * m + j + 1] << ' ';
			}
			cout << '\n';
		}
	}
	cout << count;

	return 0;
}