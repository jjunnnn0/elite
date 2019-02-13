// level 10 sorting
// 2750 선택, 삽입, 버블 정렬 구현하기
//#include <iostream>
//
//using namespace std;
//
//int main(void) {
//	int N;
//	cin >> N;
//	int input[1000];
//	for (int i = 0; i < N; i++) {
//		cin >> input[i];
//	}
//	int index = 0;
//
//	// 선택 정렬: 최솟값 찾아서 앞으로
//	/*for (int i = 0; i < N; i++) {
//		index = i;
//		for (int j = i; j < N; j++) {
//			if (input[index] > input[j]) index = j;
//		}
//		int temp;
//		temp = input[index];
//		input[index] = input[i];
//		input[i] = temp;
//	}*/
//
//	// 삽입 정렬 바로 앞 수와 비교하면서 정렬된 곳에 넣기
//	/*for (int i = 0; i < N; i++) {
//		for (int j = i; j >= 1; j--) {
//			if (input[j] < input[j - 1]) {
//				int temp;
//				temp = input[j];
//				input[j] = input[j - 1];
//				input[j - 1] = temp;
//			}
//		}
//	}*/
//
//	// 버블정렬: 맨처음부터 바로 뒤에 수랑 비교하면서 정렬하기
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N - i - 1; j++) {
//			if (input[j] > input[j + 1]) {
//				int temp;
//				temp = input[j];
//				input[j] = input[j + 1];
//				input[j + 1] = temp;
//			}
//		}
//	}
//	for (int i = 0; i < N; i++) {
//		cout << input[i] << endl;
//	}
//
//	return 0;
//}