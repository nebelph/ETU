#include <iostream>
#include <chrono>
using namespace std::chrono;
struct Node {
	int val;
	Node* next;
	Node* prev;
	Node(int _val) : val(_val), next(nullptr), prev(nullptr) {}
};

struct list {
	Node* first;
	Node* last;
	list() : first(nullptr), last(nullptr) {}

	bool isEmpty() {
		return (first == nullptr);
	}

	void pushBack(int _val) {
		Node* p = new Node(_val);
		if (isEmpty()) {
			first = p;
			last = p;
			return;
		}
		last->next = p;
		p->prev = last;
		last = p;
	}

	void push(int _val, int ind) {
		if (isEmpty()) {
			pushBack(_val);
			return;
		}
		Node* p = new Node(_val);
		Node* cur = first;
		for (int i = 0; i < ind - 1; i++) {
			cur = cur->next;
		}
		p->next = cur->next;
		cur->next->prev = p;
		p->prev = cur;
		cur->next = p;

	}

	void printForward() {
		if (isEmpty()) {
			std::cout << "Список пуст. Печать невозможна." << std::endl;
			return;
		}
		Node* p = first;
		while (p) {
			std::cout << p->val << " ";
			p = p->next;
		}
		std::cout << std::endl;
	}

	void printBackwards() {
		if (isEmpty()) {
			std::cout << "Список пуст. Печать невозможна." << std::endl;
			return;
		}
		Node* p = last;
		while (p) {
			std::cout << p->val << " ";
			p = p->prev;
		}
		std::cout << std::endl;
	}

	void removeFirst() {
		if (isEmpty()) {
			std::cout << "Список пуст. Удаление невозможно." << std::endl;
			return;
		}
		Node* p = first;
		first = p->next;
		first->prev = nullptr;
		delete p;
	}

	void removeLast() {
		if (isEmpty()) {
			std::cout << "Список пуст. Удаление невозможно." << std::endl;
			return;
		}
		Node* p = last;
		last = p->prev;
		last->next = nullptr;
		delete p;
	}

	void removeVal(int _val) {
		if (isEmpty()) {
			std::cout << "Список пуст. Удаление невозможно." << std::endl;
			return;
		}
		if (first->val == _val) {
			removeFirst();
			return;
		}
		if (last->val == _val) {
			removeLast();
			return;
		}
		Node* slow = first;
		Node* fast = slow->next;
		while (fast && fast->val != _val) {
			slow = fast;
			fast = fast->next;
		}
		if (!fast) {
			std::cout << "Ваш элемент отсутствует в списке." << std::endl;
			return;
		}
		slow->next = fast->next;
		fast->next->prev = slow;
		delete fast;
		std::cout << "Элемент удалён. Новый список:" << std::endl;
		printForward();
	}

	void removeInd(int ind) {
		if (isEmpty()) {
			std::cout << "Список пуст. Удаление невозможно." << std::endl;
			return;
		}
		if (ind == 0) {
			removeFirst();
			return;
		}
		Node* cur = first;
		for (int i = 0; i < ind; i++) {
			cur = cur->next;
		}
		if (!cur) {
			std::cout << "Ваш индекс выходит за пределы списка. Удаление невозможно." << std::endl;
			return;
		}
		if (cur->next == nullptr) {
			cur->prev->next = nullptr;
			delete cur;
			std::cout << "Элемент удалён. Новый список:" << std::endl;
			printForward();
			return;
		}
		cur->prev->next = cur->next;
		cur->next->prev = cur->prev;
		delete cur;
		std::cout << "Элемент удалён. Новый список:" << std::endl;
		printForward();
	}

	void swap(int ind1, int ind2) {
		if (isEmpty()) {
			std::cout << "Список пуст." << std::endl;
			return;
		}
		if (first == last) {
			return;
		}
		Node* t1 = first;
		for (int i = 0; i < ind1; i++) {
			if (t1->next == nullptr) {
				std::cout << "Индекс " << ind1 << " выходит за пределы списка." << std::endl;
				return;
			}
			t1 = t1->next;
		}
		Node* t2 = first;
		for (int i = 0; i < ind2; i++) {
			if (t2->next == nullptr) {
				std::cout << "Индекс " << ind2 << " выходит за пределы списка." << std::endl;
				return;
			}
			t2 = t2->next;
		}
		Node* val1 = new Node(t1->val);
		Node* val2 = new Node(t2->val);
		t1->val = val2->val;
		t2->val = val1->val;
		delete val1;
		delete val2;
		std::cout << "Элементы поменяли местами. Новый список:" << std::endl;
		printForward();
	}

	void getInd(int _val) {
		if (isEmpty()) {
			std::cout << "Список пуст." << std::endl;
			return;
		}
		int ind = 0;
		Node* p = first;
		do {
			if (p->val == _val) {
				std::cout << "Индекс вашего элемента - " << ind << "." << std::endl;
				return;
			}
			p = p->next;
			ind += 1;
		} while (p->next != nullptr);
		std::cout << "Вашего элемента нет в списке." << std::endl;
	}

	void getVal(int ind) {
		if (isEmpty()) {
			std::cout << "Список пуст." << std::endl;
			return;
		}
		Node* p = first;
		int test = 0;
		for (int i = 0; i < ind; i++) {
			if (p->next != nullptr) {
				p = p->next;
				test += 1;
			}
		}
		if (test != ind) {
			std::cout << "Ваш индекс выходит за пределы списка." << std::endl;
			return;
		}
		std::cout << "Значение по вашему индексу - " << p->val << "." << std::endl;
	}
};

list task1a();
list task1b();
list task1();
list task3(list l);
int* createDynArr();

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	list l;
	// 1.   Формирование двусвязного списка размерности N, где:
	// a) пользователь вводит количество элементов в списке, который будет автоматически заполняться случайными числами (0 до 99);
	// б) пользователь вводит в консоль элементы списка, N определяется автоматически по количеству введенных элементов;
	// 2.   Определение скорости создания двусвязного списка п. 2.
	// 3.   Вставка, удаление, обмен и получение элемента двусвязного списка. Удаление и получение элемента необходимо реализовать по индексу и по значению.
	// 4.   Определение скорости вставки, удаление и получения элемента двусвязного списка п. 3.
	int tnum;
	int* mas = createDynArr();
	delete[] mas;
	do {
		std::cout << "Выберите номер задания (1/2/3/4, 0 - закончить): ";
		std::cin >> tnum;
		switch (tnum) {
		case 1:
			l = task1();
			break;
		case 2:
			l = task1();
			break;
		case 3:
			task3(l);
			break;
		case 4:
			task3(l);
			break;
		}
	} while (tnum);
	return 0;
}

list task1() {
	list l;
	int n;
	std::cout << "Выберите тип заполнения списка (1 - авто; 2 - вручную): ";
	std::cin >> n;
	switch (n) {
	case 1:
		l = task1a();
		break;
	case 2:
		l = task1b();
		break;
	}
	return l;
}

list task1a() {
	list la;
	std::cout << "Введите количество элементов в списке: ";
	int size;
	std::cin >> size;
	auto start = system_clock::now(); //
	for (int i = 0; i < size; i++) {
		la.pushBack(rand() % 99);
	}
	auto end = system_clock::now(); //
	auto result = duration_cast<nanoseconds>(end - start); //
	std::cout << "Время затраченное на создание двусвязного списка - " << result.count() << " наносекунд." << std::endl; //
	std::cout << "Готовый список:" << std::endl;
	la.printForward();
	return la;
}

list task1b() {
	list lb;
	std::cout << "Вводите элементы списка:" << std::endl; 
	int val;
	int amount = 0; //
	while (std::cin >> val) {
		auto start = system_clock::now(); //
		lb.pushBack(val);
		auto end = system_clock::now(); //
		auto result = duration_cast<nanoseconds>(end - start); //
		amount += result.count(); //
	}
	std::cout << "Время затраченное на создание двусвязного списка - " << amount << " наносекунд." << std::endl; //
	std::cout << "Готовый список:" << std::endl;
	lb.printForward();
	return lb;
}

list task3(list l) {
	int action;
	do {
		std::cout << "Выберите действие (1 - вставка; 2 - удаление; 3 - обмен; 4 - получение; 0 - закончить): ";
		std::cin >> action;
		if (action == 1) {
			int number;
			std::cout << "Введите число: ";
			std::cin >> number;
			auto start1 = system_clock::now(); //
			l.pushBack(number);
			auto end1 = system_clock::now(); //
			auto result1 = duration_cast<nanoseconds>(end1 - start1); //
			std::cout << "Время затраченное на вставку - " << result1.count() << " наносекунд." << std::endl; //
			std::cout << "Число " << number << " добавлено в конец списка. Новый список:" << std::endl;
			l.printForward();
		}
		else if (action == 2) {
			std::cout << "Выберите действие (1 - удаление по индексу; 2 - удаление по значению): ";
			int action2;
			std::cin >> action2;
			if (action2 == 1) {
				int ind;
				std::cout << "Введите индекс (нумерация начинается с 0): ";
				std::cin >> ind;
				auto start21 = system_clock::now(); //
				l.removeInd(ind);
				auto end21 = system_clock::now(); //
				auto result21 = duration_cast<nanoseconds>(end21 - start21); //
				std::cout << "Время затраченное на удаление - " << result21.count() << " наносекунд." << std::endl; //
			}
			else if (action2 == 2) {
				int val;
				std::cout << "Введите значение: ";
				std::cin >> val;
				auto start22 = system_clock::now(); //
				l.removeVal(val);
				auto end22 = system_clock::now(); //
				auto result22 = duration_cast<nanoseconds>(end22 - start22); //
				std::cout << "Время затраченное на удаление - " << result22.count() << " наносекунд." << std::endl; //
			}
		}
		else if (action == 3) {
			std::cout << "Введите индексы (нумерация начинается с 0): ";
			int ind1, ind2;
			std::cin >> ind1;
			std::cin >> ind2;
			auto start3 = system_clock::now(); //
			l.swap(ind1, ind2);
			auto end3 = system_clock::now(); //
			auto result3 = duration_cast<nanoseconds>(end3 - start3); //
			std::cout << "Время затраченное на обмен - " << result3.count() << " наносекунд." << std::endl; //
			std::cout << "Новый список:" << std::endl;
			l.printForward();
		}
		else if (action == 4) {
			std::cout << "Выберите действие (1 - получение по индексу; 2 - получение по значению): ";
			int action4;
			std::cin >> action4;
			if (action4 == 1) {
				int ind;
				std::cout << "Введите индекс (нумерация начинается с 0): ";
				std::cin >> ind;
				auto start41 = system_clock::now(); //
				l.getVal(ind);
				auto end41 = system_clock::now(); //
				auto result41 = duration_cast<nanoseconds>(end41 - start41); //
				std::cout << "Время затраченное на получение - " << result41.count() << " наносекунд." << std::endl; //
			}
			else if (action4 == 2) {
				int val;
				std::cout << "Введите значение: ";
				std::cin >> val;
				auto start42 = system_clock::now(); //
				l.getInd(val);
				auto end42 = system_clock::now(); //
				auto result42 = duration_cast<nanoseconds>(end42 - start42); //
				std::cout << "Время затраченное на получение - " << result42.count() << " наносекунд." << std::endl; //
			}
		}
	} while (action == 1 || action == 2 || action == 3 || action == 4);
	return l;
}

int* createDynArr() {
	int size = 0;
	int* arr = new int[size];
	std::cout << "Выберите тип заполнения массива (1 - авто; 2 - вручную): ";
	int act;
	std::cin >> act;
	if (act == 1) {
		std::cout << "Введите количество элементов в массиве: ";
		std::cin >> size;
		auto start = system_clock::now(); //
		int* rez = new int[size];
		arr = rez;
		for (int i = 0; i < size; i++) {
			*(arr + i) = rand() % 99;
		}
		auto end = system_clock::now(); //
		auto result = duration_cast<nanoseconds>(end - start); //
		std::cout << "Время затраченное на создание массива - " << result.count() << " наносекунд." << std::endl; //
		std::cout << "Новый массив:" << std::endl;
		for (int i = 0; i < size; i++) {
			std::cout << *(arr + i) << " ";
		}
		std::cout << std::endl;
	}
	if (act == 2) {
		std::cout << "Вводите элементы массива:" << std::endl;
		int val;
		while (std::cin >> val) {
			size += 1;
			int* rez = new int[size];
			for (int i = 0; i < size - 1; i++) {
				rez[i] = arr[i];
			}
			delete[] arr;
			arr = rez;
			*(arr + size - 1) = val;
		}
		std::cout << "Новый массив:" << std::endl;
		for (int i = 0; i < size; i++) {
			std::cout << *(arr + i) << " ";
		}
		std::cout << std::endl;
	}
	return arr;
}

/*
auto start = system_clock::now(); //
auto end = system_clock::now(); //
auto result = duration_cast<nanoseconds>(end - start); //
std::cout << "Время затраченное на  - " << result.count() << " наносекунд." << std::endl; //
*/
