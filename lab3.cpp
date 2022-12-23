#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

void IDZ(int*, int, int, const int);
void PrintArray(int*, int, int);
void SwapAndPrint1(int*, int);
void SwapAndPrint2(int*, int);
void SwapAndPrint3(int*, int);
void SwapAndPrint4(int*, int);
void SortAndPrint(int*, int);
void ChangeAndPrint(int*, int);

int main() {
	setlocale(0, "");

	

	// Идз 2
	//cout << "\t\t\tИдз 2" << endl;
	srand(time(0));
	const int N = 8;
	int matrix[N][N];
	int mx = 0, index = 0;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) {
			matrix[i][j] = 1 + rand() % 100;
			if (matrix[i][j] > mx) {
				mx = matrix[i][j];
				index = i * N + j;
			}
		}
	

	int x = index % N, y = index / N;
	//cout << "Максимальное значение массива - " << mx << endl << "Элемент находится по адресу (" << x + 1 << "; " << y + 1 << ")" << endl << endl;
	//IDZ((int*)matrix, x, y, N);

	// 1.1) Вводим размерность
	cout << "\t\t\tЗадание 1" << endl << endl;
	int n;
	bool incorrect = 1;
	do {
		cout << "Введите размерность: ";
		cin >> n;
		if (n == 6 || n == 8 || n == 10)
			incorrect = 0;
		else
			cout << "Введено неверное значение." << endl;
	} while (incorrect);

	// 1.2) Создаем массив
	const int N6 = 6;
	const int N8 = 8;
	const int N10 = 10;

	int Arr6[6][6];
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 6; j++)
			Arr6[i][j] = 0;
	int Arr8[8][8];
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			Arr8[i][j] = 0;
	int Arr10[10][10];

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			Arr10[i][j] = 0;
	cout << "Выберите схему заполнения массива (1 или 2): ";
	int number;
	cin >> number;
	switch(number) {
	case 1:
		if (n == 6)
		{

			int k = 0;
			for (int i = 0; i < N6 / 2; i++) {
				int* ptr = &Arr6[i][i];
				for (int j = 0; j < (N6 - 1 - 2 * i); j++) {
					*ptr = ++k;
					ptr += 1;
				}
				for (int j = 0; j < (N6 - 1 - 2 * i); j++) {
					*ptr = ++k;
					ptr += N6;
				}
				for (int j = 0; j < (N6 - 1 - 2 * i); j++) {
					*ptr = ++k;
					ptr -= 1;
				}
				for (int j = 0; j < (N6 - 1 - 2 * i); j++) {
					*ptr = ++k;
					ptr -= N6;
				}
			}
		}
		else if (n == 8)
		{

			int k = 0;
			for (int i = 0; i < N8 / 2; i++) {
				int* ptr = &Arr8[i][i];
				for (int j = 0; j < (N8 - 1 - 2 * i); j++) {
					*ptr = ++k;
					ptr += 1;
				}
				for (int j = 0; j < (N8 - 1 - 2 * i); j++) {
					*ptr = ++k;
					ptr += N8;
				}
				for (int j = 0; j < (N8 - 1 - 2 * i); j++) {
					*ptr = ++k;
					ptr -= 1;
				}
				for (int j = 0; j < (N8 - 1 - 2 * i); j++) {
					*ptr = ++k;
					ptr -= N8;
				}
			}
		}
		else if (n == 10)
		{

			int k = 0;
			for (int i = 0; i < N10 / 2; i++) {
				int* ptr = &Arr10[i][i];
				for (int j = 0; j < (N10 - 1 - 2 * i); j++) {
					*ptr = ++k;
					ptr += 1;
				}
				for (int j = 0; j < (N10 - 1 - 2 * i); j++) {
					*ptr = ++k;
					ptr += N10;
				}
				for (int j = 0; j < (N10 - 1 - 2 * i); j++) {
					*ptr = ++k;
					ptr -= 1;
				}
				for (int j = 0; j < (N10 - 1 - 2 * i); j++) {
					*ptr = ++k;
					ptr -= N10;
				}
			}
		}
		break;
	case 2:
		if (n == 6)
		{
			int k = 0;
			int* ptr = &Arr6[0][0];
			for (int i = 0; i < N6 / 2; i++) {
				for (int j = 0; j < (N6-1); j++) {
					*ptr = ++k;
					ptr += N6;
				}
				*ptr = ++k;
				ptr += 1;
				for (int j = 0; j < (N6 - 1); j++) {
					*ptr = ++k;
					ptr -= N6;
				}
				*ptr = ++k;
				ptr += 1;
			}
		}
		else if (n == 8)
		{
			int k = 0;
			int* ptr = &Arr8[0][0];
			for (int i = 0; i < N8 / 2; i++) {
				for (int j = 0; j < (N8 - 1); j++) {
					*ptr = ++k;
					ptr += N8;
				}
				*ptr = ++k;
				ptr += 1;
				for (int j = 0; j < (N8 - 1); j++) {
					*ptr = ++k;
					ptr -= N8;
				}
				*ptr = ++k;
				ptr += 1;
			}
		}
		else if (n == 10)
		{
			int k = 0;
			int* ptr = &Arr10[0][0];
			for (int i = 0; i < N10 / 2; i++) {
				for (int j = 0; j < (N10 - 1); j++) {
					*ptr = ++k;
					ptr += N10;
				}
				*ptr = ++k;
				ptr += 1;
				for (int j = 0; j < (N10 - 1); j++) {
					*ptr = ++k;
					ptr -= N10;
				}
				*ptr = ++k;
				ptr += 1;
			}
		}
		break;

	}

	// 1.3) Выводим массив
	if (n == 6) PrintArray((int*)Arr6, n, n);
	else if (n == 8) PrintArray((int*)Arr8, n, n);
	else if (n == 10) PrintArray((int*)Arr10, n, n);

	// 2) Меняем блоки местами
	cout << "\t\t\tЗадание 2" << endl << endl;
	bool not_enough = 1;
	do {
		
		incorrect = 1;
		do {
			cout << "Выберите схему перестановки (от 1 до 4): ";
			cin >> number;
			if (number >= 1 && number <= 4)
				incorrect = 0;
			else
				cout << "Введено неверное значение." << endl;
		} while (incorrect);
		switch (number) {
		case 1:
			if (n == 6) SwapAndPrint1((int*)Arr6, n);
			else if (n == 8) SwapAndPrint1((int*)Arr8, n);
			else if (n == 10) SwapAndPrint1((int*)Arr10, n);
			break;
		case 2:
			if (n == 6) SwapAndPrint2((int*)Arr6, n);
			else if (n == 8) SwapAndPrint2((int*)Arr8, n);
			else if (n == 10) SwapAndPrint2((int*)Arr10, n);
			break;
		case 3:
			if (n == 6) SwapAndPrint3((int*)Arr6, n);
			else if (n == 8) SwapAndPrint3((int*)Arr8, n);
			else if (n == 10) SwapAndPrint3((int*)Arr10, n);
			break;
		case 4:
			if (n == 6) SwapAndPrint4((int*)Arr6, n);
			else if (n == 8) SwapAndPrint4((int*)Arr8, n);
			else if (n == 10) SwapAndPrint4((int*)Arr10, n);
			break;
		}

		cout << "Повторить - введите 1; дальше - введите 0: ";
		cin >> not_enough;
		cout << endl;
	} while (not_enough);

	// 3) Сортируем массив - не сортирует тварь
	cout << "\t\t\tЗадание 3" << endl << endl;
	if (n == 6) SortAndPrint((int*)Arr6, n);
	else if (n == 8) SortAndPrint((int*)Arr8, n);
	else if (n == 10) SortAndPrint((int*)Arr10, n);

	// 4) Изменяем элементы массива
	cout << "\t\t\tЗадание 4" << endl << endl;
	if (n == 6) ChangeAndPrint((int*)Arr6, n);
	else if (n == 8) ChangeAndPrint((int*)Arr8, n);
	else if (n == 10) ChangeAndPrint((int*)Arr10, n);
	

	/*Sleep(1000);
	HANDLE hStdout;
	COORD destCoord;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < 10; i++)
	{
		destCoord.X = i;
		destCoord.Y = i;
		SetConsoleCursorPosition(hStdout, destCoord);
		cout << i << '\r';
		cout.flush();
		Sleep(100);
	}

	for (int i = 10; i > 0; i--)
	{
		destCoord.X = i;
		destCoord.Y = i;
		SetConsoleCursorPosition(hStdout, destCoord);
		cout << '*' << '\r';
		cout.flush();
		Sleep(100);
	}*/
}

void IDZ(int* ptr, int m, int n, const int N) {
	cout << "Массив до преобразования:" << endl;
	PrintArray((int*)ptr, N, N);

	for (int i = 0; i < m; i++)
		for (int j = 0; j < N; j++) {
			int var = ptr[m - i + j * N];
			ptr[m - i + j * N] = ptr[m - i - 1 + j * N];
			ptr[m - i - 1 + j * N] = var;
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < N; j++) {
			int var = ptr[n * N - i*N + j];
			ptr[n * N - i*N + j] = ptr[n * N - N - i*N + j];
			ptr[n * N - N - i*N + j] = var;
		}

	cout << "Массив после преобразования:" << endl;
	PrintArray((int*)ptr, N, N);
}

void PrintArray(int* ptr, int m, int n) {
	int count = 0;
	for (int i = 0; i < m * n; i++) {
		++count;
		cout << ptr[i] << "\t";
		if (count % n == 0)
			cout << endl;
		Sleep(10);
	}
	cout << endl << endl;

	/*HANDLE hStdout;
	COORD destCoord;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < m * n; i++)
	{
		


		destCoord.X = i;
		destCoord.Y = i;
		SetConsoleCursorPosition(hStdout, destCoord);
		cout << i << '\r';
		cout.flush();
		Sleep(100);
	}

	for (int i = 10; i > 0; i--)
	{
		destCoord.X = i;
		destCoord.Y = i;
		SetConsoleCursorPosition(hStdout, destCoord);
		cout << '*' << '\r';
		cout.flush();
		Sleep(100);
	}*/
}

void SwapAndPrint1(int* ptr, int n) {
	int count = n * n, k = n / 2;
	for (int i = 0; i < k; i++)
		for (int j = 0; j < k; j++) {
			int var1 = ptr[j + n * i];
			int var2 = ptr[j + k + n * i];
			int var3 = ptr[j + k + n * k + n * i];
			int var4 = ptr[j + n * k + n * i];

			ptr[j + n * i] = var4;
			ptr[j + k + n * i] = var1;
			ptr[j + k + n * k + n * i] = var2;
			ptr[j + n * k + n * i] = var3;
		}

	PrintArray((int*)ptr, n, n);

	for (int i = 0; i < k; i++)
		for (int j = 0; j < k; j++) {
			int var1 = ptr[j + n * i];
			int var2 = ptr[j + k + n * i];
			int var3 = ptr[j + k + n * k + n * i];
			int var4 = ptr[j + n * k + n * i];

			ptr[j + n * i] = var2;
			ptr[j + k + n * i] = var3;
			ptr[j + k + n * k + n * i] = var4;
			ptr[j + n * k + n * i] = var1;
		}
}

void SwapAndPrint2(int* ptr, int n) {
	int count = n * n, k = n / 2;
	for (int i = 0; i < k; i++)
		for (int j = 0; j < k; j++) {
			int var1 = ptr[j + n * i];
			int var2 = ptr[j + k + n * i];
			int var3 = ptr[j + k + n * k + n * i];
			int var4 = ptr[j + n * k + n * i];

			ptr[j + n * i] = var3;
			ptr[j + k + n * i] = var4;
			ptr[j + k + n * k + n * i] = var1;
			ptr[j + n * k + n * i] = var2;
		}

	PrintArray((int*)ptr, n, n);

	for (int i = 0; i < k; i++)
		for (int j = 0; j < k; j++) {
			int var1 = ptr[j + n * i];
			int var2 = ptr[j + k + n * i];
			int var3 = ptr[j + k + n * k + n * i];
			int var4 = ptr[j + n * k + n * i];

			ptr[j + n * i] = var3;
			ptr[j + k + n * i] = var4;
			ptr[j + k + n * k + n * i] = var1;
			ptr[j + n * k + n * i] = var2;
		}
}

void SwapAndPrint3(int* ptr, int n) {
	int count = n * n, k = n / 2;
	for (int i = 0; i < k; i++)
		for (int j = 0; j < k; j++) {
			int var1 = ptr[j + n * i];
			int var2 = ptr[j + k + n * i];
			int var3 = ptr[j + k + n * k + n * i];
			int var4 = ptr[j + n * k + n * i];

			ptr[j + n * i] = var4;
			ptr[j + k + n * i] = var3;
			ptr[j + k + n * k + n * i] = var2;
			ptr[j + n * k + n * i] = var1;
		}

	PrintArray((int*)ptr, n, n);

	for (int i = 0; i < k; i++)
		for (int j = 0; j < k; j++) {
			int var1 = ptr[j + n * i];
			int var2 = ptr[j + k + n * i];
			int var3 = ptr[j + k + n * k + n * i];
			int var4 = ptr[j + n * k + n * i];

			ptr[j + n * i] = var4;
			ptr[j + k + n * i] = var3;
			ptr[j + k + n * k + n * i] = var2;
			ptr[j + n * k + n * i] = var1;
		}
}

void SwapAndPrint4(int* ptr, int n) {
	int count = n * n, k = n / 2;
	for (int i = 0; i < k; i++)
		for (int j = 0; j < k; j++) {
			int var1 = ptr[j + n * i];
			int var2 = ptr[j + k + n * i];
			int var3 = ptr[j + k + n * k + n * i];
			int var4 = ptr[j + n * k + n * i];

			ptr[j + n * i] = var2;
			ptr[j + k + n * i] = var1;
			ptr[j + k + n * k + n * i] = var4;
			ptr[j + n * k + n * i] = var3;
		}

	PrintArray((int*)ptr, n, n);

	for (int i = 0; i < k; i++)
		for (int j = 0; j < k; j++) {
			int var1 = ptr[j + n * i];
			int var2 = ptr[j + k + n * i];
			int var3 = ptr[j + k + n * k + n * i];
			int var4 = ptr[j + n * k + n * i];

			ptr[j + n * i] = var2;
			ptr[j + k + n * i] = var1;
			ptr[j + k + n * k + n * i] = var4;
			ptr[j + n * k + n * i] = var3;
		}
}

void SortAndPrint(int* ptr, int n) {
	for (int i = 0; i < n * n; i++)
		for (int j = 0; j < n * n - 1; j++)
			if (ptr[j] > ptr[j + 1])
				swap(ptr[j], ptr[j + 1]);

	PrintArray((int*)ptr, n, n);
}

void ChangeAndPrint(int* ptr, int n) {
	int k;

	cout << "1) Умножить элементы массива на ";
	cin >> k;
	for (int i = 0; i < n * n; i++)
		ptr[i] *= k;
	cout << endl;

	cout << "2) Разделить элементы массива на ";
	cin >> k;
	for (int i = 0; i < n * n; i++)
		ptr[i] /= k;
	cout << endl;

	cout << "3) Прибавить к элементам массива ";
	cin >> k;
	for (int i = 0; i < n * n; i++)
		ptr[i] += k;
	cout << endl;

	cout << "4) Вычесть из элементов массива  ";
	cin >> k;
	for (int i = 0; i < n * n; i++)
		ptr[i] -= k;
	cout << endl;

	PrintArray((int*)ptr, n, n);
}
