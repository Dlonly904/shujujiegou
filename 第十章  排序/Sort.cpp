#include "Sort.h"

int main() {
	int a[10] = { 53, 17, 19, 61, 98, 75, 79, 63, 46, 49 };
	int b[10] = {9, 75,	35,	76,	23,	3,	13,	54	, 49,	43};


	cout << "���������У�";

	for (int i = 0; i < 10; i++) {

		cout << a[i] << "  ";
	}

	cout << endl;
	cout << "�Ľ�������������У�";
	QuickSort_2(a, 0, 9);

	for (int i = 0; i < 10; i++) {

		cout << b[i] << "  ";
	}

	cout << endl << "���������У�";

	for (int i = 0; i < 10; i++) {

		cout << b[i] << "  ";
	}

	cout << endl;
	cout << "ѡ����������У�";
	SelectSort(b, 10);

	for (int i = 0; i < 10; i++) {

		cout << b[i] << "  ";
	}

	int c[10] = {34, 73,	32,	74,	21,	80,	25,	70,	43,	85};//34 73 32 74 21 80 25 70 43 85
	cout << endl << "���������У�";

	for (int i = 0; i < 10; i++) {

		cout << c[i] << "  ";
	}

	cout << endl;
	cout << "ϣ����������У�";
	ShellSort(c, 10);

	for (int i = 0; i < 10; i++) {

		cout << c[i] << "  ";
	}

	int d[10] = {34, 73,	32,	74,	21,	80,	25,	70,	43,	85};
	cout << endl << "���������У�";

	for (int i = 0; i < 10; i++) {

		cout << d[i] << "  ";
	}

	cout << endl;
	cout << "������������У�";
	BinInsertSort(d, 10);

	for (int i = 0; i < 10; i++) {

		cout << d[i] << "  ";
	}

	int e[8] = {50, 38, 66, 98, 77, 13, 28, 50};
	cout << endl << "���������У�";

	for (int i = 0; i < 8; i++) {

		cout << e[i] << "  ";
	}

	cout << endl;
	cout << "����������У�";
	HeapSort(e, 8);

	for (int i = 0; i < 8; i++) {

		cout << e[i] << "  ";
	}

	int f[10] = {1, 34, 73, 32, 74, 21, 80, 25, 70, 43};
	int g[10];
	MergeSort(f, g, 10);
	cout << endl << "�鲢��������У�" ;

	for (int i = 0; i < 10; i++) {

		cout << g[i] << "  ";
	}




}