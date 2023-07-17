#include "BubbleSort.h"
void BubbleSort(int r[], int n);
int BubbleSort1(int r[], int n);
int BubbleSort2(int r[], int n);
int BubbleSort3(int r[], int n);

int main() {
	int r[10], n = 10;
	cout << "请输入待排序的10个数：";

	for (int i = 0; i < 10; i++) {

		cin >> r[i];
	}

	cout << "冒泡比较次数：" << BubbleSort3(r, n) << endl;

	for (int i = 0; i < 10; i++) {

		cout << r[i] << "  ";
	}
}