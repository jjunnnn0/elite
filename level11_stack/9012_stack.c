// 9012 스택으로 풀기
// 괄호 문자열 VPS(Valid parenthesis)
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int key;
	struct _node *next;
}node;

node *head, *tail;

void init_stack() {
	head = (node*)calloc(1, sizeof(node));
	tail = (node*)calloc(1, sizeof(node));

	head->next = tail;
	tail->next = tail;
}

int push(int k) {
	node *t;
	if ((t = (node*)malloc(sizeof(node))) == NULL) {
		printf("stack OVERFLOW!!\n");
		return -1;
	}
	t->key = k;
	t->next = head->next;
	head->next = t;

	return k;
}

int pop() {
	node *t;
	if (head->next == tail)	return -1;
	int k;
	t = head->next;
	k = t->key;
	head->next = t->next;
	free(t);
	
	return k;
}

int main(void) {
	int T = 0;
	scanf("%d", &T); // test case

	int result = 0;
	for (int i = 0; i < T; i++) {
		char input[100];
		init_stack();
		scanf("%s", &input);
		result = 0;
		for (int j = 0; j < 100; j++) {
			if (input[j] == '\0') break;

			if (input[j] == '(') result+=push(1);
			else if (input[j] == ')') result -= pop();
		}
		if (result != 0) printf("NO\n");
		if (result == 0) printf("YES\n");		
	}
	return 0;
}