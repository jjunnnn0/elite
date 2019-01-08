//1874
// 문제: 스택수열
#include <stdio.h>
#include <stdlib.h>

int stack[100000] = { 0 };
int indexx = -1;

int pop() {
	if (indexx == -1) return -1;
	int output = stack[indexx];
	stack[indexx--] = 0;
	//printf("-\n");
	return output;
}

void push(int X) {
	//if (stack[indexx] == 99999) printf("stack is full\n");
	stack[++indexx] = X;
	//printf("+\n");	
}

int main(void) {
	int n = 0;
	scanf("%d", &n); // 1 <= n <= 100,000
	int *seq = (int*)calloc(n, sizeof(int));
	int *order = (int*)calloc(n, sizeof(int));
	int *plusminus = (int*)calloc(2 * n, sizeof(int)); // push이면 1, pop이면 -1 저장

	for (int i = 0; i < n; i++) {
		scanf("%d", &seq[i]);
		order[i] = i+1;
		if (seq[i] > n) { 
			printf("NO\n"); 
			return 0; 
		}
	} // 제대로 들어가는거 확인
	
	int i = 0;
	int index = 0; // n까지의 오름차순 번호들에 대한 index값
	int count = 0; // pop 몇번했는지 count
	int p = 0;
	int countboth = 0; // pop과 push 다 count

	for (int i = 0; i < n; i++) {
		for (int j = index; j < seq[i];j++) {
			push(order[j]);
			plusminus[countboth] = 1;
			countboth++;
		}
		p = pop(); // pop() 변수에 저장해서 출력물과 비교하기
		plusminus[countboth] = -1;
		countboth++;
		if (p != seq[count]) { // if문에서 pop()!= 이렇게 비교하려했더니 pop이 한번 더 실행되므로 변수에 저장
			printf("NO\n");
			return 0;
		}		count++;
		if (seq[i] > index) index = seq[i];
	}
	
	for (int i = 0; i < 2 * n; i++) {
		if (plusminus[i] == 1) printf("+\n");
		else if (plusminus[i] == -1) printf("-\n");
	}

	return 0;
}
// 처음에는 push하고 pop할 때 + 와 - 를 출력하려고 했으나 수열을 만들 수 없는 경우에는
// NO가 나와야 되므로 따로 배열을 선언해서 관리하게함.
// 백준 사이트에 제출할때 실패하면 return -1 을 해놨더니 틀렸다고 뜸
// return 0으로 해야함 -> return 0이 정상 정료 return -1이 비정상 종료