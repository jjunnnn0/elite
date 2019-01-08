//10828 linked list version
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int key;
	struct _node *next;
}node;

//global initialization
node *head, *tail;

void init_stack() {
	head = (node*)calloc(1, sizeof(node)); // 함수에서 선언을 하면 이게 유지가 되나?
	tail = (node*)calloc(1, sizeof(node));

	head->next = tail;
	tail->next = tail;
}

int push(int k) {
	node *t;
	if ((t = (node*)calloc(1, sizeof(node))) == NULL) {
		printf("stack OVERFLOW!!\n");
		return 0;
	}	
	t->key = k;
	t->next = head->next;
	head->next = t;	
	
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

int size() {
	node *t;
	int count = 0;
	t = head->next;
	while (t != tail) {
		t = t->next;
		count++;
	}
	return count;
}

int empty() {
	if (head->next == tail) return 1;
	else return 0;
}

int top() {
	node *t;
	t = head->next;
	if (head->next == tail) return -1;
	else return t->key;
}

int main(void) {
	int N = 0; // 1 <= N <= 10,000
	int trash = 0;
	scanf("%d", &N);
	scanf("%d", &trash); // 엔터를 넣어주기 위한 scanf
	init_stack();
	int *result = (int*)calloc(N, sizeof(int));

	for (int i = 0; i < N; i++) {
		char input[100];
		gets_s(input);
		if (input[1] == 'u') { // push
			for (int j = 0; j < 6; j++) { // 정수가 100,000까지 들어오므로 j는 6까지
				input[j] = input[j + 5]; // push라는 단어 지우기
				input[j + 5] = '\0'; // 문자열 끝을 알리는 null 문자 삽입
			}
			push(atoi(input));
			result[i] = -2;
			continue;
		}
		if (input[0] == 'p' && input[1]=='o') {// pop
			result[i] = pop();
			continue;
		}
		if (input[1] == 'i') {// size 
			result[i] = size();
			continue;
		}
		if (input[1] == 'm') {// empty
			result[i] = empty();
			continue;
		}
		if (input[0] = 't') {// top
			result[i] = top();
			continue;
		}
	}
	for (int i = 0; i < N; i++) {
		if (result[i] == -2) continue; // push의 경우 -2 이므로 continue
		printf("%d\n", result[i]);
	}
	return 0;
}