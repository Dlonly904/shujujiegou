#include "BubbleSort.h"
void BubbleSort(int r[], int n);
int BubbleSort1(int r[], int n);
int BubbleSort2(int r[], int n);
int BubbleSort3(int r[], int n);

int main() {
	int r[10], n = 10;
	cout << "������������10������";

	for (int i = 0; i < 10; i++) {

		cin >> r[i];
	}

	cout << "ð�ݱȽϴ�����" << BubbleSort3(r, n) << endl;

	for (int i = 0; i < 10; i++) {

		cout << r[i] << "  ";
	}
}