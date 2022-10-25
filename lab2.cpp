#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

int main()
{
	// 1) создаём массив
	cout << "Task 1" << endl;
	cout << "Unsorted array:" << endl;
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
	cout << "Task 2" << endl;
	cout << "Sorted array:" << endl;
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
	cout << "Sorting time is " << result.count() << " nanosec." << endl << endl;

	// 3) Находим макс. и мин., считаем время 
	cout << "Task 3" << endl;
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

	cout << "Min. array element: " << mn0 << endl << "Max. array element: " << mx0 << endl;
	cout << "Sorted array time: " << result0.count() << " nanosec." << endl << "Unsorted array time: " << result1.count() << " nanosec." << endl << "Alternative sorted array time: " << result2.count() << " nanosec." << endl << endl;

	// 4) Среднее значение, индексы элементов
	cout << "Task 4" << endl;
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
	cout << "Average value between " << mn0 << " and " << mx0 << " is " << average << endl;

	int number = 0;
	cout << "Unsorted array index(es): ";
	for (int i = 0; i < N; i++) // неотсортированный массив
	{
		if (arr3[i] == average)
		{
			cout << i << " ";
			number += 1;
		}
	}
	if (number == 0)
		cout << "There are no numbers equal to the average value in the current array";
	cout << endl;
	cout << "Sorted array index(es): ";
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
		cout << "There are no numbers equal to the average value in the current array";
	cout << endl;
	cout << "The number of indexes is " << number << endl << endl;

	// 5) Вывод кол-ва элементов меньших a
	cout << "Task 5" << endl;
	int a;
	cout << "Enter the value a: ";
	cin >> a;
	cout << "The number of elements less than a is equal to ";
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
	cout << "Task 6" << endl;
	int b;
	cout << "Enter the value b: ";
	cin >> b;
	cout << "The number of elements greater than b is ";
	if (b < arr[0])
		cout << N << endl << endl;
	else if (b >= arr[N-1])
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
	cout << "Task 7" << endl;
	int value;
	cout << "Enter the value: ";
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
		cout << "The value IS in the array" << endl;
	else
		cout << "The value IS NOT in the array" << endl;
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
		cout << "Value " << const_value << " is located at index of " << mid << endl;
	A = 0;

	cout << "Linear search time: " << result3.count() << " nanosec." << endl << "Binary search time: " << result4.count() << " nanosec." << endl << endl;
	
	// 8) Смена местами элементов массива
	cout << "Task 8" << endl;
	cout << "Enter the indexes: ";
	int m, n;
	cin >> m >> n;
	if ((m >= 0 && m < N) && (n >= 0 && n < N))
	{
		auto start5 = system_clock::now();
		swap(arr[m], arr[n]);
		auto end5 = system_clock::now();
		auto result5 = duration_cast<nanoseconds>(end5 - start5);
		cout << "Swapping time is " << result5.count() << " nanosec." << endl;
		cout << "The array after swapping " << m << " and " << n << " elements:" << endl;
		for (int i = 0; i < N; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
	else
		cout << "Wrong indexes" << endl;
}
