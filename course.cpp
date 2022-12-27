#include <iomanip>
#include <iostream>
#include <Windows.h>
#include <chrono>
#include <string>

using namespace std;
using namespace chrono;

void Lab1(); // 1 пр

void Lab2(); // пр

void PrintArray(int*, int, int);
void SwapAndPrint1(int*, int);
void SwapAndPrint2(int*, int);
void SwapAndPrint3(int*, int);
void SwapAndPrint4(int*, int);
void SortAndPrint(int*, int);
void ChangeAndPrint(int*, int);
void Lab3(); // 3 пр

void Print(string);
string Task1(string);
string RemoveSpacebars(string);
string RemovePunctuationMarks(string);
string FixLetterCase(string);
string Task2(string);
bool NumberCheck(string);
void Task3(string);
string RemoveChar(string, string);
void Task4(string);
void LinearSearch(string, string);
void Task5(string);
void Lab4(); // 4 пр

int main()
{
    setlocale(0, "");
    cout << "\t\t\t\t\t   Курсовая работа\n\n";

    int lab_num = 0;
	do {
		if (lab_num == 0) {
			do {
				cout << "Выберите номер практической работы (для завершения работы программы напишите 0): ";
				cin >> lab_num;
			} while (lab_num < 0 || lab_num > 4);
		}
		if (lab_num == 0)
			break;

		switch (lab_num) {
		case 1:
			cout << "\n\n\t\t\t\t\tПрактическая работа 1\n\n";
			Lab1();
			break;
		case 2:
			cout << "\n\n\t\t\t\t\tПрактическая работа 2\n\n";
			Lab2();
			break;
		case 3:
			cout << "\n\n\t\t\t\t\tПрактическая работа 3\n\n";
			Lab3();
			break;
		case 4:
			cout << "\n\n\t\t\t\t\tПрактическая работа 4\n\n";
			Lab4();
			break;
		}

		do {
			cout << "\nВыберите номер практической работы (для завершения работы программы напишите 0): ";
			cin >> lab_num;
		} while (lab_num < 0 || lab_num > 4);
	} while (lab_num);
    return 0;
}

void Lab1() {
    cout << "\n\n\t\t\tЗадание 1\n";
    cout << "int: " << sizeof(int) << "\n";
    cout << "short int: " << sizeof(short int) << "\n";
    cout << "long int: " << sizeof(long int) << "\n";
    cout << "float: " << sizeof(float) << "\n";
    cout << "double: " << sizeof(double) << "\n";
    cout << "long double: " << sizeof(long double) << "\n";
    cout << "char: " << sizeof(char) << "\n";
    cout << "bool: " << sizeof(bool);

    cout << "\n\n\t\t\tЗадание 2\n";
    cout << "Enter int: ";
    int input;
    cin >> input;
    int a = sizeof(int) * 8;
    int mask = 1 << a - 1;
    for (int i = 1; i <= a; i++)
    {
        cout << ((input & mask) ? 1 : 0);
        if (i == 1 || i % 8 == 0)
            cout << " ";

        input <<= 1;
    }

    cout << "\n\n\t\t\tЗадание 3\n";
    union {
        int tool;
        float f;
    };
    cout << "Enter float: ";
    cin >> f;
    for (int i = 1; i <= a; i++)
    {
        cout << ((tool & mask) ? 1 : 0);
        if (i == 1 || i % 8 == 0)
            cout << " ";
        tool <<= 1;
    }

    cout << "\n\n\t\t\tЗадание 4\n";
    union {
        double d;
        int arr[2];
    };
    cout << "Enter double: ";
    cin >> d;
    for (int i = 1; i <= a; i++)
    {
        cout << ((arr[1] & mask) ? 1 : 0);
        if (i == 1 || i % 8 == 0)
            cout << " ";
        arr[1] <<= 1;
    }
    for (int i = 1; i <= a; i++)
    {
        cout << ((arr[0] & mask) ? 1 : 0);
        if (i % 8 == 0)
            cout << " ";
        arr[0] <<= 1;
    }
    cout << "\n\n";
}

void Lab2() {
	// 1) создаём массив
	cout << "\n\n\t\t\tЗадание 1\n";
	cout << "Неотсортированный массив:" << endl;
	const int N = 100;
	int arr[N], arr3[N];
	srand(time(0));
	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % 199 - 99;
		arr3[i] = arr[i];
	}
	for (int i = 0; i < N; i++)
		cout << arr[i] << " ";
	cout << endl << endl;



	// 2) сортируем и определяем затраченное время
	cout << "\n\n\t\t\tЗадание 2\n";
	cout << "Отсортированный массив:" << endl;
	auto start = system_clock::now();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}
	auto end = system_clock::now();
	auto result = duration_cast<nanoseconds>(end - start);
	for (int i = 0; i < N; i++)
		cout << arr[i] << " ";
	cout << endl;
	cout << "Время сортировки составляет " << result.count() << " наносек." << endl << endl;

	// 3) Находим макс. и мин., считаем время 
	cout << "\n\n\t\t\tЗадание 3\n";
	auto start0 = system_clock::now(); // отсортированный массив
	int mx0 = arr[0], mn0 = arr[0];
	for (int i = 1; i < N; i++)
	{
		if (arr[i] > mx0)
			mx0 = arr[i];
		if (arr[i] < mn0)
			mn0 = arr[i];
	}
	auto end0 = system_clock::now();
	auto result0 = duration_cast<nanoseconds>(end0 - start0);

	auto start1 = system_clock::now(); // неотсортированный массив
	int mx1 = arr3[0], mn1 = arr3[0];
	for (int i = 1; i < N; i++)
	{
		if (arr3[i] > mx1)
			mx1 = arr3[i];
		if (arr3[i] < mn1)
			mn1 = arr3[i];
	}
	auto end1 = system_clock::now();
	auto result1 = duration_cast<nanoseconds>(end1 - start1);

	auto start2 = system_clock::now(); // альтернативный способ для отсортированного массива
	int mx2 = arr[N - 1], mn2 = arr[0];
	auto end2 = system_clock::now();
	auto result2 = duration_cast<nanoseconds>(end2 - start2);

	cout << "Мин. элемент массива: " << mn0 << endl << "Макс. элемент массива: " << mx0 << endl;
	cout << "Время для отсортированного массива: " << result0.count() << " наносек." << endl << "Время для неотсортированного массива: " << result1.count() << " наносек." << endl << "Альтернативное время для отсортированного массива: " << result2.count() << " наносек." << endl << endl;

	// 4) Среднее значение, индексы элементов
	cout << "\n\n\t\t\tЗадание 4\n";
	int average;
	if ((mn0 * (-1)) > mx0)
	{
		if ((mx0 % 2 == 1 && mn0 % 2 == 0) || (mx0 % 2 == 0 && mn0 % 2 == -1))
			average = (mx0 + mn0) / 2 - 1;
		else
			average = (mx0 + mn0) / 2;
	}
	else
	{
		if ((mx0 % 2 == 1 && mn0 % 2 == 0) || (mx0 % 2 == 0 && mn0 % 2 == -1))
			average = (mx0 + mn0) / 2 + 1;
		else
			average = (mx0 + mn0) / 2;
	}
	cout << "Среднее значение между " << mn0 << " и " << mx0 << " составляет " << average << endl;

	int number = 0;
	cout << "Индекс(-ы) неотсортированного массива: ";
	for (int i = 0; i < N; i++) // неотсортированный массив
	{
		if (arr3[i] == average)
		{
			cout << i << " ";
			number += 1;
		}
	}
	if (number == 0)
		cout << "В массиве нет значений равных среднему";
	cout << endl;
	cout << "Индекс(-ы) отсортированного массива: ";
	number = 0;
	for (int i = 0; i < N; i++) // отсортированный массив
	{
		if (arr[i] == average)
		{
			cout << i << " ";
			number += 1;
		}
	}
	if (number == 0)
		cout << "В массиве нет значений равных среднему";
	cout << endl;
	cout << "Количество вхождений составляет " << number << endl << endl;

	// 5) Вывод кол-ва элементов меньших a
	cout << "\n\n\t\t\tЗадание 5\n";
	int a;
	cout << "Введите значение a: ";
	cin >> a;
	cout << "Число элементов, меньших a, равно ";
	if (a > arr[N - 1])
		cout << N << endl << endl;
	else if (a <= arr[0])
		cout << 0 << endl << endl;
	else
	{
		for (int i = 0; i < N; i++)
		{
			if (a <= arr[i])
			{
				cout << i << endl << endl;
				break;
			}
		}
	}

	// 6) Вывод кол-ва элементов больших b
	cout << "\n\n\t\t\tЗадание 6\n";
	int b;
	cout << "Введите значение b: ";
	cin >> b;
	cout << "Число элементов, больших b, равно ";
	if (b < arr[0])
		cout << N << endl << endl;
	else if (b >= arr[N - 1])
		cout << 0 << endl << endl;
	else
	{
		for (int i = 0; i < N; i++)
		{
			if (b < arr[i])
			{
				cout << (N - i) << endl << endl;
				break;
			}
		}
	}

	// 7) Нахождение числа в массиве
	cout << "\n\n\t\t\tЗадание 7\n";
	int value;
	cout << "Введите число: ";
	cin >> value;
	bool A = 0;
	auto start3 = system_clock::now();
	for (int i = 0; i < N; i++) // обычный перебор
	{
		if (arr[i] == value)
		{
			A = 1;
			break;
		}
	}
	auto end3 = system_clock::now();
	auto result3 = duration_cast<nanoseconds>(end3 - start3);

	if (A)
		cout << "Это число ЕСТЬ в массиве" << endl;
	else
		cout << "Этого числа НЕТ в массиве" << endl;
	A = 0;

	auto start4 = system_clock::now();
	int low = 0, high = N - 1, mid, const_value = value;
	while (low <= high) // бинарный поиск
	{
		mid = (low + high) / 2;
		if (value == arr[mid])
		{
			A = 1;
			break;
		}
		else if (value > arr[mid])
			low = mid + 1;
		else
			high = mid - 1;
	}
	auto end4 = system_clock::now();
	auto result4 = duration_cast<nanoseconds>(end4 - start4);

	if (A)
		cout << "Число " << const_value << " расположено под индексом " << mid << endl;
	A = 0;

	cout << "Время линейного поиска составляет: " << result3.count() << " наносек." << endl << "Время бинарного поиска составляет: " << result4.count() << " наносек." << endl << endl;

	// 8) Смена местами элементов массива
	cout << "\n\n\t\t\tЗадание 8\n";
	cout << "Введите индексы: ";
	int m, n;
	cin >> m >> n;
	if ((m >= 0 && m < N) && (n >= 0 && n < N))
	{
		auto start5 = system_clock::now();
		swap(arr[m], arr[n]);
		auto end5 = system_clock::now();
		auto result5 = duration_cast<nanoseconds>(end5 - start5);
		cout << "Время смены элементов составляет " << result5.count() << " наносек." << endl;
		cout << "Массив после смены местами " << m << " и " << n << " элементов:" << endl;
		for (int i = 0; i < N; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
	else
		cout << "Введены неверные индексы" << endl;
}

void PrintArray(int* ptr, int m, int n) {
	int count = 0;
	for (int i = 0; i < m * n; i++) {
		++count;
		cout << ptr[i] << "\t";
		if (count % n == 0)
			cout << endl;
		Sleep(0);
	}
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
void Lab3() {
	// 1.1) Вводим размерность
	cout << "\n\n\t\t\tЗадание 1\n";
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
	switch (number) {
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
				for (int j = 0; j < (N6 - 1); j++) {
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
	cout << "\n\n\t\t\tЗадание 2\n";
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
	cout << "\n\n\t\t\tЗадание 3\n";
	if (n == 6) SortAndPrint((int*)Arr6, n);
	else if (n == 8) SortAndPrint((int*)Arr8, n);
	else if (n == 10) SortAndPrint((int*)Arr10, n);

	// 4) Изменяем элементы массива
	cout << "\n\n\t\t\tЗадание 4\n";
	if (n == 6) ChangeAndPrint((int*)Arr6, n);
	else if (n == 8) ChangeAndPrint((int*)Arr8, n);
	else if (n == 10) ChangeAndPrint((int*)Arr10, n);
}

void Print(string str) {
	cout << str << endl << endl;
}
string Task1(string str) {
	cout << "\t\t\tЗадание 1\n";
	cout << "Введите исходную строку:\n";
	std::getline(std::cin, str);
	//getline(cin, str);
	cout << endl;
	return str;
}
string RemoveSpacebars(string str) {
	int len = str.length();
	while (str[0] == ' ')
		str.erase(0, 1);

	len = str.length();
	while (str[len - 2] == ' ') {
		str.erase(len - 2, 1);
		len = str.length();
	}

	len = str.length();
	int count = 0;
	for (int i = 0; i < len - 1 - count; i++) {
		if (str[i] == ' ' && str[i + 1] == ' ') {
			str.erase(i, 1);
			--i;
			++count;
		}
	}
	return str;
}
string RemovePunctuationMarks(string str) {
	int len = str.length();
	int count = 0;
	for (int i = 0; i < len - 1 - count; i++) {
		if ((int(str[i]) >= 33 && int(str[i]) <= 47 && str[i] == str[i + 1]) || (int(str[i]) >= 58 && int(str[i]) <= 63 && str[i] == str[i + 1])) {
			str.erase(i, 1);
			--i;
			++count;
		}
	}
	return str;
}
string FixLetterCase(string str) { // 65-90
	int len = str.length();
	for (int i = 0; i < len; i++) {
		if (int(str[i]) >= 65 && int(str[i]) <= 90)
			str[i] += 32;
	}
	return str;
}
string Task2(string str) {
	cout << "\n\t\t\tЗадание 2\n";
	str = RemoveSpacebars(str);
	cout << "Без лишних пробелов:\n";
	Print(str);

	str = RemovePunctuationMarks(str);
	cout << "Без лишних знаков пунктуации:\n";
	Print(str);

	str = FixLetterCase(str);
	cout << "С нижним регистром букв:\n";
	Print(str);

	return str;
}
bool NumberCheck(string str) {
	int len = str.length();
	for (int i = 0; i < len; i++)
		if (int(str[i]) >= 48 && int(str[i]) <= 57)
			return 0;
	return 1;
}
void Task3(string str) { // 97-122
	cout << "\n\t\t\tЗадание 3.3\n";
	string line = "";
	string word = "";
	int len = str.length();
	for (int i = 0; i < len; i++) {
		if (!((int(str[i]) >= 32 && int(str[i]) <= 47) || (int(str[i]) >= 58 && int(str[i]) <= 63))) {
			word += str[i];
		}
		else {
			if (NumberCheck(word)) {
				line += word;
				line += " ";
			}
			word = "";
		}
	}
	line = RemoveSpacebars(line);
	cout << "Слова без цифр:\n";
	Print(line);
}
string RemoveChar(string str, string list) {
	int len = str.length();
	int l_len = list.length();
	int count = 0;
	for (int i = 0; i < len - count; i++) {
		int help = 0;
		for (int j = 0; j < l_len; j++) {
			if (str[i + help] == list[j]) {
				str.erase(i, 1);
				--i;
				++count;
				++help;
			}
		}
	}
	return str;
}
void Task4(string str) {
	cout << "\n\t\t\tЗадание 4.3\n";
	string line = "";
	string word = "";
	string list;
	cout << "Введите набор букв (или цифр), который нужно удалить, без пробелов:\n";
	getline(cin, list);
	int len = str.length();
	for (int i = 0; i < len; i++) {
		if (!((int(str[i]) >= 32 && int(str[i]) <= 47) || (int(str[i]) >= 58 && int(str[i]) <= 63))) {
			word += str[i];
		}
		else {
			word = RemoveChar(word, list);
			line += word;
			line += " ";
			word = "";
		}
	}
	line = RemoveSpacebars(line);
	cout << "\nСлова без введённого набора символов:\n";
	Print(line);
}
void LinearSearch(string str, string sub) {
	cout << endl;
	int len = str.length();
	int s_len = sub.length();
	bool include = 0;
	for (int i = 0; i < len - s_len + 1; i++) {
		if (str[i] == sub[0]) {
			int count = 1;
			for (int j = 1; j < s_len; j++) {
				if (str[i + j] == sub[j])
					++count;
			}
			if (count == s_len) {
				cout << i << " ";
				include = 1;
			}
		}
	}
	switch (include) {
	case 0:
		cout << "Такой подстроки нет в строке.\n";
		break;
	case 1:
		cout << "- индекс(-ы) подстроки.\n";
		break;
	}
}
void Task5(string str) {
	cout << "\n\t\t\tЗадание 5\n";
	string sub;
	cout << "Введите искомую подстроку:\n";
	getline(cin, sub);
	bool choice;
	cout << "\nВыберите алгоритм.\nЛинейный поиск - 0; поиск Кнута-Морриса-Прата - 1: ";
	cin >> choice;
	switch (choice) {
	case 0:
		LinearSearch(str, sub);
		break;
	}
}
void Lab4() {
	// 1) Вводим строку
	string str;
	getline(cin, str);
	str = Task1(str);

	// 2) Редактируем строку
	str = Task2(str);

	// 3.3) Выводим слова без цифр
	Task3(str);

	// 4.3) Выводим слова без заданного набора букв (или цифр)
	Task4(str);

	// 5) Поиск подстроки в строке
	Task5(str);;
}
