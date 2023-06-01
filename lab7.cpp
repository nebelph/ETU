#include <iostream>
#include <string>
#include <stack>

class Stack {
private:
	struct Node {
		char val;
		Node* next;
		Node(char _val) : val(_val), next(nullptr) {}
	};
	Node* root;
public:
	Stack() : root(nullptr) {}
	
	bool empty() {
		return root == nullptr;
	}

	void push(int _val) {
		Node* newnode = new Node(_val);
		newnode->next = root;
		root = newnode;
	}

	void pop() {
		if (empty())
			return;
		else {
			Node* delnode = root;
			root = root->next;
			delete delnode;
		}
	}

	char top() {
		return root->val;
	}
};

int pr(char ch) {
	switch (ch) {
	case '(': return 1;
	case '+': case '-': return 2;
	case '*': case '/': return 3;
	default: return 0;
	}
}

std::string int2str(int num) {
	std::string rev_str = "";
	do {
		rev_str += char(num % 10 + 48);
		num /= 10;
	} while (num != 0);

	int len = rev_str.length();
	std::string str = "";
	for (int i = 0; i < len; i++) {
		str += rev_str[len - 1 - i];
	}

	return str;
}

int st(int a, int p) {
	int answer = 1;
	for (int i = 0; i < p; i++) {
		answer *= a;
	}
	return answer;
}

int str2int(std::string str) {
	int num = 0;
	int len = str.length();
	for (int i = 0; i < len; i++) {
		num += st(10, len - i - 1) * (int(str[i]) - 48);
	}
	return num;
}

int calcValue(std::string str, std::string vars, int* arr) {
	int answer = 0;
	int len = str.length();
	int var_count = 0;
	for (int i = 0; i < len; i++) {
		if (pr(str[i]) == 0 && !isdigit(str[i])) {
			var_count++;
		}
	}

	if (var_count != 0) {
		int p = 0;
		int i = 0;
		do {
			if (pr(str[i]) == 0 && !isdigit(str[i])) {
				str.replace(i, 1, int2str(arr[vars.find(str[i])])); // заменяем переменные на числа
				p++;
			}
			i++;
		} while (p != var_count);
	}
	// далее следует написать калькулятор для выражений без скобок
	len = str.length();
	int plus_count = 0, minus_count = 0, umnozh_count = 0, razdel_count = 0;
	for (int i = 0; i < len; i++) {
		if (pr(str[i]) != 0) {
			if (str[i] == '+')
				plus_count++;
			else if (str[i] == '-')
				minus_count++;
			else if (str[i] == '*')
				umnozh_count++;
			else if (str[i] == '/')
				razdel_count++;
		}
	}
	int pr2_count = plus_count + minus_count;
	int pr3_count = umnozh_count + razdel_count;
	while (pr3_count) {
		len = str.length();
		int left, right;
		for (int i = 0; i < len; i++) {
			if (pr(str[i]) == 3) {
				left = i;
				right = i;
				while (true) {
					if (left - 1 >= 0) {
						if (isdigit(str[left - 1])) {
							left--;
						}
						else
							break;
					}
					else
						break;
				}
				while (true) {
					if (right + 1 < len) {
						if (isdigit(str[right + 1])) {
							right++;
						}
						else
							break;
					}
					else
						break;
				}
				// на данном шаге мы имеем левый и правый индекс бинарного выражения
				int local_answer_int = 0;
				std::string l_str = "";
				for (int j = left; j < i; j++) {
					l_str += str[j];
				}
				int l_int = str2int(l_str);
				std::string r_str = "";
				for (int j = i + 1; j < right + 1; j++) {
					r_str += str[j];
				}
				int r_int = str2int(r_str);
				switch (str[i]) {
				case '*':
					local_answer_int = l_int * r_int;
					break;
				case '/':
					local_answer_int = l_int / r_int;
					break;
				}
				std::string local_answer_str = int2str(local_answer_int);
				str.replace(left, right - left + 1, local_answer_str);
				pr3_count--;
				break;
			}
		}
	}
	while (pr2_count) {
		len = str.length();
		int left, right;
		for (int i = 0; i < len; i++) {
			if (pr(str[i]) == 2) {
				left = i;
				right = i;
				while (true) {
					if (left - 1 >= 0) {
						if (isdigit(str[left - 1])) {
							left--;
						}
						else
							break;
					}
					else
						break;
				}
				while (true) {
					if (right + 1 < len) {
						if (isdigit(str[right + 1])) {
							right++;
						}
						else
							break;
					}
					else
						break;
				}
				// на данном шаге мы имеем левый и правый индекс бинарного выражения
				int local_answer_int = 0;
				std::string l_str = "";
				for (int j = left; j < i; j++) {
					l_str += str[j];
				}
				int l_int = str2int(l_str);
				std::string r_str = "";
				for (int j = i + 1; j < right + 1; j++) {
					r_str += str[j];
				}
				int r_int = str2int(r_str);
				switch (str[i]) {
				case '+':
					local_answer_int = l_int + r_int;
					break;
				case '-':
					local_answer_int = l_int - r_int;
					break;
				}
				std::string local_answer_str = int2str(local_answer_int);
				str.replace(left, right - left + 1, local_answer_str);
				pr2_count--;
				break;
			}
		}
	}
	answer = str2int(str);
	return answer;
}

int calc(std::string str) {
	int answer = 0;
	int len = str.length();
	int brackets_count = 0;
	std::string vars = ""; // строка с соответствующими переменными

	for (int i = 0; i < len; i++) { // считаем количество выражений в скобках
		if (str[i] == '(')
			brackets_count++;
	}
	int* arr_val = new int[brackets_count]; // массив со значениями внутри скобок

	for (int i = 0; i < brackets_count; i++) { // раскрываем скобки
		int right = str.find(')'); // находим индекс закрывающей скобки
		int left;
		for (left = right; str[left] != '('; left--); // находим индекс открывающей скобки
		std::string inside = "";
		for (int j = left + 1; j < right; j++) { // в строку inside добавляем внутреннее содержимое скобок
			inside += str[j];
		}
		arr_val[i] = calcValue(inside, vars, arr_val);
		std::string str_var = "0";
		str_var[0] = char(65 + i);
		str.replace(left, right - left + 1, str_var); // заменяем скобки переменными
		vars += char(65 + i);

	}

	//example: 7+X-Y, где Y = 5+Z, где Z = 7-W
	answer = calcValue(str, vars, arr_val);

	delete[] arr_val;

	return answer;
}

std::string initializing(std::string str) {
	int len = str.length();
	for (int i = 0; i < len; i++) {
		if (pr(str[i]) == 0) {
			if (!isdigit(str[i]) && str[i] != ')') {
				char value;
				const char var = str[i];
				std::cout << str[i] << " = ";
				std::cin >> value;
				bool in = true;

				while (in) {
					int ind = str.find(var);
					if (ind >= 0 && ind <= len) {
						str[ind] = value;
					}
					else
						in = false;
				}
			}
		}
	}
	return str;
}

std::string RPN(std::string input) {
	Stack st;
	std::cout << "Строим ОПЗ:";
	std::string output;
	std::cout << std::endl;
	int len = input.length();

	for (int i = 1; i < len; i++) { // проверка на корректность ввода
		if (input[i] != ')' && input[i - 1] != ')' && pr(input[i - 1]) == 0) {
			if (pr(input[i]) == pr(input[i - 1])) {
				std::cout << "Invalid input";
				return "";
			}
		}
	}

	int operand_count = 0, operation_count = 0;

	for (int i = 0; i < len; i++) {
		if (pr(input[i]) == 0 && input[i] != ')') { // встречается операнд
			if (input[i] == ' ') { // проверка на корректность ввода
				std::cout << "Invalid input";
				return "";
			}
			std::cout << "'" << input[i] << "' - переменная. Помещаем её в строку." << std::endl;
			operand_count++;
			output += input[i];
			std::cout << "Строка: " << output << std::endl;
		}

		else if (pr(input[i]) == 1) { // встречается '('
			std::cout << "'(' - открывающая скобка. Помещаем в стек." << std::endl;
			st.push(input[i]);
		}

		else if (input[i] == ')') { // встречается ')'
			std::cout << "')' - закрывающая скобка. Извлекаем из стека в строку все символы до открывающейся скобки. Уничтожаем обе скобки." << std::endl;
			do {
				output += st.top();
				std::cout << "Строка: " << output << std::endl;
				st.pop();
			} while (st.top() != '(');
			st.pop();
		}

		else { // встречаются '+', '-', '*', '/'
			operation_count++;
			if (st.empty()) { // если стек пуст
				std::cout << "'" << input[i] << "' - операция (приоритет " << pr(input[i]) << "). Стек пуст. Помещаем в стек." << std::endl;
				st.push(input[i]);
			}

			else if (pr(st.top()) < pr(input[i])) { // если приоритет данной операции больше приоритета вершины стека
				std::cout << "'" << input[i] << "' - операция (приоритет " << pr(input[i]) << "). Проверяем стек: на вершине символ '" << st.top() << "' (приоритет " << pr(st.top()) << "). Помещаем символ '" << input[i] << "' в стек." << std::endl;
				st.push(input[i]);
			}

			else { // если приоритет данной операции НЕ больше приоритета вершины стека
				std::cout << "'" << input[i] << "' - операция (приоритет " << pr(input[i]) << "). Проверяем стек: на вершине символ '" << st.top() << "' (приоритет " << pr(st.top()) << ").\nИзвлекаем символы из стека в строку, пока приоритет данной операции не больше приоритета операции на вершине стека." << std::endl;
				while (pr(st.top()) >= pr(input[i])) {
					output += st.top();
					std::cout << "Строка: " << output << std::endl;
					st.pop();
					if (st.empty())
						break;
				}
				if (st.empty())
					std::cout << "Стек пуст. Помещаем символ '" << input[i] << "' в стек." << std::endl;
				else
					std::cout << "Проверяем стек: на вершине символ '" << st.top() << "' (приоритет " << pr(st.top()) << "). Помещаем символ '" << input[i] << "' в стек." << std::endl;
				st.push(input[i]);
			}
		}
	}

	std::cout << "Выражение прочитано." << std::endl;
	if (!st.empty()) { // если в стеке остались знаки операций
		std::cout << "Проверяем стек. В стеке есть операции. Заносим операции в строку." << std::endl;
		while (pr(st.top())) {
			output += st.top();
			std::cout << "Строка: " << output << std::endl;
			st.pop();
			if (st.empty())
				break;
		}
	}
	std::cout << std::endl << "ОПЗ построена:" << std::endl;

	if (operand_count - 1 == operation_count && operation_count != 0) { // проверка на корректность ввода
		std::cout << output << std::endl;
		std::string new_output = initializing(output);
		if (new_output != output) {
			std::cout << new_output << std::endl << std::endl;
			return new_output;
		}
		return output;
	}
	else {
		std::cout << "Invalid input" << std::endl;
		return "";
	}
}

int calcRPN(std::string str) {
	std::stack<int> st;
	str = initializing(str);
	int len = str.length();

	for (int i = 0; i < len; i++) {
		if (pr(str[i]) == 0) {
			int num = int(str[i]) - 48;
			st.push(num);
		}
		else if (pr(str[i]) > 1) {
			switch (pr(str[i])) {
			case 2:
				if (str[i] == '+') {
					int right = st.top();
					st.pop();
					int left = st.top();
					st.pop();
					st.push(left + right);
					break;
				}
				else if (str[i] == '-') {
					int right = st.top();
					st.pop();
					int left = st.top();
					st.pop();
					st.push(left - right);
					break;
				}
			case 3:
				if (str[i] == '*') {
					int right = st.top();
					st.pop();
					int left = st.top();
					st.pop();
					st.push(left * right);
					break;
				}
				else if (str[i] == '/') {
					int right = st.top();
					st.pop();
					int left = st.top();
					st.pop();
					st.push(left / right);
					break;
				}
			}
		}
	}
	return st.top();
}

std::string PN(std::string input) {
	std::cout << "Строим ПЗ:" << std::endl;
	input = initializing(input);
	std::cout << "Переворачиваем:" << std::endl;
	reverse(input.begin(), input.end());
	std::cout << input << std::endl;
	int len = input.length();
	std::cout << "Разворачиваем скобки:" << std::endl;
	for (int i = 0; i < len; i++) {
		if (input[i] == ')') {
			input[i] = '[';
		}
		else if (input[i] == '(') {
			input[i] = ']';
		}
	}
	for (int i = 0; i < len; i++) {
		if (input[i] == ']') {
			input[i] = ')';
		}
		else if (input[i] == '[') {
			input[i] = '(';
		}
	}
	std::cout << input << std::endl;
	input = RPN(input);
	std::cout << "Переворачиваем." << std::endl;
	reverse(input.begin(), input.end());
	std::cout << std::endl << "ПЗ построена:" << std::endl << input << std::endl;
	return input;
}

int calcPN(std::string str) {
	reverse(str.begin(), str.end());
	std::stack<int> st;
	str = initializing(str);
	int len = str.length();

	for (int i = 0; i < len; i++) {
		if (pr(str[i]) == 0) {
			int num = int(str[i]) - 48;
			st.push(num);
		}
		else if (pr(str[i]) > 1) {
			switch (pr(str[i])) {
			case 2:
				if (str[i] == '+') {
					int right = st.top();
					st.pop();
					int left = st.top();
					st.pop();
					st.push(left + right);
					break;
				}
				else if (str[i] == '-') {
					int right = st.top();
					st.pop();
					int left = st.top();
					st.pop();
					st.push(right - left);
					break;
				}
			case 3:
				if (str[i] == '*') {
					int right = st.top();
					st.pop();
					int left = st.top();
					st.pop();
					st.push(left * right);
					break;
				}
				else if (str[i] == '/') {
					int right = st.top();
					st.pop();
					int left = st.top();
					st.pop();
					st.push(right / left);
					break;
				}
			}
		}
	}
	return st.top();
}

int main() {
	srand(time(0));
	setlocale(LC_ALL, "Russian");

	
	std::string infix, prefix, postfix;
	int infix_c, prefix_c, postfix_c;
	int task = 1;
	do {
		std::cout << "\t1) Ввести инфиксную форму;\n\t2) Посчитать инфиксную форму;\n\t3) Преобразовать в ОПЗ;\n\t4) Посчитать ОПЗ;\n\t5) Преобразовать в ПЗ;\n\t6) Посчитать ПЗ;\n\nВыберите задание: ";
		std::cin >> task;
		switch (task) {
		case 1:
			if (infix.size() == 0) {
				std::cout << "Введите инфиксное выражение:" << std::endl;
				std::cin.get();
				getline(std::cin, infix);
				std::cout << std::endl;
			}
			else {
				std::string new_infix;
				std::cout << "Введите инфиксное выражение или оставьте предыдущее выражение нажатием Enter:" << std::endl;
				std::cin.get();
				getline(std::cin, new_infix);
				std::cout << std::endl;
				if (new_infix.size() != 0) {
					infix = new_infix;
				}
			}
			break;
		case 2:
			if (infix.size() == 0) {
				std::cout << "Для начала выполните пункт 1." << std::endl << std::endl;
			}
			else {
				infix_c = calc(infix);
				std::cout << "Выражение равно " << infix_c << "." << std::endl << std::endl;
			}
			break;
		case 3:
			if (infix.size() == 0) {
				std::cout << "Для начала выполните пункт 1." << std::endl << std::endl;
			}
			else {
				postfix = RPN(infix);
				std::cout << std::endl;
			}
			break;
		case 4:
			if (postfix.size() == 0) {
				std::cout << "Для начала выполните пункт 3." << std::endl << std::endl;
			}
			else {
				postfix_c = calcRPN(postfix);
				std::cout << "Выражение равно " << postfix_c << "." << std::endl << std::endl;
			}
			break;
		case 5:
			if (infix.size() == 0) {
				std::cout << "Для начала выполните пункт 1." << std::endl << std::endl;
			}
			else {
				prefix = PN(infix);
				std::cout << std::endl;
			}
			break;
		case 6:
			if (prefix.size() == 0) {
				std::cout << "Для начала выполните пункт 5." << std::endl << std::endl;
			}
			else {
				prefix_c = calcPN(prefix);
				std::cout << "Выражение равно " << prefix_c << "." << std::endl << std::endl;
			}
			break;
		default:
			std::cout << "Работа программы прекращена." << std::endl;
			task = 0;
		}
	} while (task != 0);
	
	/*
	std::string a = "5*(6/3+(7*6)-1)+2*8-9";
	std::cout << "Инфиксная форма:" << std::endl << a << std::endl;
	int a_counted = calc(a);
	std::cout << "Выражение равно: " << a_counted << std::endl << std::endl;
	std::string a_rpn = RPN(a);
	int a_rpn_counted = calcRPN(a_rpn);
	std::cout << "Выражение для ОПЗ равно: " << a_rpn_counted << std::endl << std::endl;
	std::string a_pn = PN(a);
	int a_pn_counted = calcPN(a_pn);
	std::cout << "Выражение для ПЗ равно: " << a_pn_counted << std::endl << std::endl;
	// сделать проверку на корректность для простого калькулятора
	// написать прямую польскую нотацию
	*/
	return 0;
}
