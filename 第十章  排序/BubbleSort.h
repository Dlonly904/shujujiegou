#pragma once
#include <iostream>
using namespace std;

void BubbleSort(int *r, int n) {
	int temp;

	for (int i = 1; i < n; i++)

		for (int j = 0; j < n - i; j++) {

			if (r[j] > r[j + 1])
				temp = r[j];
			r[j] = r[j + 1];
			r[j + 1] = temp;
		}
}

int BubbleSort1(int r[], int n) { //�ж��Ƿ�������
	int i = 1, j, temp, d = 0;
	bool exchange = true;

	while (exchange) {
		exchange = false;

		for (j = 0; j < n - i; j++) {

			d++;

			if (r[j] > r[j + 1]) {
				temp = r[j];
				r[j] = r[j + 1];
				r[j + 1] = temp;
				exchange = true;
			}
		}

		i++;
	}

	return d;
}

int BubbleSort2(int r[], int n) { //Ѱ�ҷ���������λ��
	int i = 1, j, temp, d = 0;
	int exchange = n - 1, bound;

	while (exchange) {
		bound = exchange, exchange = 0;

		for (j = 0; j < bound; j++) {

			d++;

			if (r[j] > r[j + 1]) {
				temp = r[j];
				r[j] = r[j + 1];
				r[j + 1] = temp;
				exchange = j;
			}
		}
	}

	return d;
}

int BubbleSort3(int r[], int n) { //˫��
	int num = 0;
	int low = 0, high = n - 1;
	int exchange;


	while (low < high) {
		exchange = low;

		for (int j = low; j < high; j++) { //��������

			num++;

			if (r[j] > r[j + 1]) {
				int temp = r[j];
				r[j] = r[j + 1];
				r[j + 1] = temp;
				exchange = j;
			}
		}

		high = exchange;

		for (int j = high; j > low; j--) { //��������

			num++;

			if (r[j] < r[j - 1]) {
				int temp = r[j];
				r[j] = r[j - 1];
				r[j - 1] = temp;
				exchange = j;
			}
		}

		low = exchange;
	}

	return num;
}
