// level 10 sorting
// 2750 ����, ����, ���� ���� �����ϱ�
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
//	// ���� ����: �ּڰ� ã�Ƽ� ������
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
//	// ���� ���� �ٷ� �� ���� ���ϸ鼭 ���ĵ� ���� �ֱ�
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
//	// ��������: ��ó������ �ٷ� �ڿ� ���� ���ϸ鼭 �����ϱ�
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