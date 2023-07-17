#pragma once
#include <iostream>
using namespace std;

void InsertSort(int r[], int n) {
	int j, temp;

	for (int i = 1; i < n; i++) {

		temp = r[i];

		for (j = i - 1; j >= 0 && temp < r[j]; j--) {

			r[j + 1] = r[j];
		}

		r[j + 1] = temp;
	}
}

void BinInsertSort(int r[], int n) {
	int i, low, mid, high, j, temp;

	for (i = 1; i < n; i++) {

		temp = r[i];
		low = 0;
		high = i - 1;

		while (low <= high) {
			mid = (low + high) / 2;

			if (temp < r[mid])
				high = mid - 1;
			else
				low = mid + 1;
		}

		for (j = i - 1; j >= low; j--)

			r[j + 1] = r[j];
		r[low] = temp;
	}
}

void SelectSort(int r[], int n) {
	int i, j, k, temp;

	for (i = 0; i < n - 1; i++) {

		k = i;

		for (j = i + 1; j < n; j++) {

			if (r[j] < r[k])
				k = j;
		}

		if (k != i) {
			temp = r[i];
			r[i] = r[k];
			r[k] = temp;
		}
	}
}

int BubbleSort3(int r[], int n) { //双向
	int num = 0;
	int low = 0, high = n - 1;
	int exchange;
	exchange = low;

	while (low < high) {
		for (int j = low; j < high; j++) { //正向起泡

			num++;

			if (r[j] > r[j + 1]) {
				int temp = r[j];
				r[j] = r[j + 1];
				r[j + 1] = temp;
				exchange = j;
			}
		}

		high = exchange;

		for (int j = high; j > low; j--) { //反向起泡

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

void ShellSort(int r[], int n) { //希尔排序
	int d, i, temp, j;

	for (d = n / 2; d >= 1; d = d / 2) {

		for (i = d; i < n; i++) {

			temp = r[i];

			for (j = i - d; j >= 0 && temp < r[j]; j = j - d)

				r[j + d] = r[j];
			r[j + d] = temp;
		}
	}
}

int Partition(int r[], int i, int j) {
	int temp;
	temp = r[i];

	while (i < j) {
		while (i < j && r[j] >= temp)
			j--;

		if (i < j)
			r[i++] = r[j];

		while (i < j && r[i] <= temp)
			i++;

		if (i < j)
			r[j--] = r[i];
	}

	r[i] = temp;
	return i;











}//快速排序的一次划分算法
void QuickSort(int r[], int i, int j) {
	int pivot;

	if (i < j) {
		pivot = Partition(r, i, j);
		QuickSort(r, i, pivot);
		QuickSort(r, pivot + 1, j);
	}
}

void QuickSort_2(int r[], int m, int n) {
	if (m >= n)
		return;
	int i = m - 1, j = n + 1;
	int tmp = r[i + ((j - i) >> 1)], temp;

	while (i < j) {
		while (r[++i] < tmp);

		while (r[--j] > tmp);

		if (i < j) {
			temp = r[i];
			r[i] = r[j];
			r[j] = temp;
		}
	}

	QuickSort_2(r, m, j);
	QuickSort_2(r, j + 1, n);
}

void Sift(int r[], int k, int m) { //堆排序中的筛选算法Sift
	int i, j, temp;
	i = k;
	j = 2 * i;

	while (j <= m) {
		if (j < m && r[j] < r[j + 1])
			j++;

		if (r[i] > r[j])
			break;
		else {
			temp = r[j];
			r[j] = r[i];
			r[i] = temp;
			i = j;
			j = 2 * i;
		}
	}
}

void HeapSort(int r[], int n) { //堆排序算法
	int i, temp;

	for (i = n / 2; i >= 1; i--)

		Sift(r, i, n);

	for (i = 1; i < n; i++) {

		temp = r[1];
		r[1] = r[n - i - 1];
		r[n - i - 1] = temp;
		Sift(r, 1, n - i);
	}
}

void Merge(int r[], int r1[], int s, int m, int t) { //一次归并
	int i, j, k;
	i = s;
	j = m + 1;
	k = s;

	while (i <= m && j <= t)
		if (r[i] <= r[j])
			r1[k++] = r[i++];
		else
			r1[k++] = r[j++];

	if (i <= m)
		while (i <= m)
			r1[k++] = r[i++];
	else
		while (j <= t)
			r1[k++] = r[j++];
}

void MergePass(int r[], int r1[], int n, int h) { //一趟归并
	int i = 1, k;

	while (i <= n - 2 * h + 1) {
		Merge(r, r1, i, i + h - 1, i + 2 * h - 1);
		i += 2 * h;
	}

	if (i < n - h + 1)
		Merge(r, r1, i, i + h - 1, n);
	else
		for (k = i; k <= n; k++)

			r1[k] = r[k];
}

void MergeSort(int r[], int r1[], int n) {
	int h = 1;

	while (h < n) {
		MergePass(r, r1, n, h);
		h = 2 * h;
		MergePass(r1, r, n, h);
		h = 2 * h;
	}
}
