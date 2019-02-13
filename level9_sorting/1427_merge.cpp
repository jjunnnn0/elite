// level 10 sorting
// 1427 merge sort
//#include <iostream>
//
//using namespace std;
//
//void merging(int *arr, int s1, int e1, int s2, int e2) {
//	int p, q;
//	int temp[1000001];
//	int temp_idx = 0;
//	p = s1; // 왼쪽 start
//	q = s2; // 오른쪽 start
//
//	while (p <= e1 && q <= e2) {
//		if (arr[p] <= arr[q]) {
//			temp[temp_idx++] = arr[p];
//			p++;
//		}
//		else {
//			temp[temp_idx++] = arr[q];
//			q++;
//		}
//	}
//
//	if (p > e1)
//		for (int i = q; i <= e2; i++) temp[temp_idx++] = arr[i];
//	else
//		for (int i = p; i <= e1; i++) temp[temp_idx++] = arr[i];
//
//	for (int i = s1; i <= e2; i++) {
//		arr[i] = temp[i - s1];
//	}
//}
//
//void mergeSort(int *arr, int start, int end) {
//	if (start >= end) return;
//	else {
//		int mid = (start + end) / 2;
//
//		mergeSort(arr, start, mid); // 왼쪽 반 정렬
//		mergeSort(arr, mid + 1, end); // 오른쪽 반 정렬
//
//		merging(arr, start, mid, mid + 1, end);
//	}
//}
//
//int main(void) {
//	int n; // sorting할 개수
//	cin >> n;
//	int input[1000001];
//
//	for (int i = 1; i <= n; i++) {
//		cin >> input[i];
//	}
//
//	mergeSort(input, 1, n);
//
//	for (int i = 1; i <= n; i++) {
//		cout << input[i] << ' ';
//	}
//
//	return 0;
//}