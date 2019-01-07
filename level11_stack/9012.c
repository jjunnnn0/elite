// 9012
// 문제: 괄호 문자열 VPS(Valid parenthesis)
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int T = 0; // Test case 수
	scanf("%d", &T);
	
	int *isvps = (int*)calloc(T, sizeof(int)); // VPS가 맞는지 아닌지 확인하는 변수 0 이면 VPS

	for (int i = 0; i < T; i++) {
		char input[100];
		scanf("%s", &input);
		for (int j = 0; j < 100; j++) {
			if (input[j] == '\0') break; // 문자열이 끝나면 break
			if (input[j] == '(') isvps[i]++; // 왼쪽 괄호는 +1
			if (input[j] == ')')isvps[i]--; // 오른쪽 괄호는 -1
			if (isvps[i] == -1) break; // 오른쪽 괄호가 먼저 나오는순간 break
		}
	}
	
	for (int i = 0; i < T; i++) {
		if (isvps[i] == 0) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}
// 이 문제는 스택문제로 안풀고 그냥 숫자놀이로 풀었음. 
//스택으로 어떻게 풀어야할지 모르겠다.