#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>

using namespace std;

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

int main() {
	setlocale(0, "");

	// 1) Вводим строку
	// 
	string str;
	str = Task1(str);

	// 2) Редактируем строку
	str = Task2(str);
	system("pause");

	// 3.3) Выводим слова без цифр
	Task3(str);
	system("pause");

	// 4.3) Выводим слова без заданного набора букв (или цифр)
	Task4(str);
	system("pause");

	// 5) Поиск подстроки в строке
	Task5(str);

	return 0;
}

void Print(string str) {
	cout << str << endl << endl;
}
string Task1(string str) {
	cout << "\t\t\tЗадание 1\n";
	cout << "Введите исходную строку:\n";
	getline(cin, str);
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
		if ((int(str[i]) >=33 && int(str[i]) <= 47 && str[i] == str[i+1]) || (int(str[i]) >= 58 && int(str[i]) <= 63 && str[i] == str[i + 1])) {
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
			if (str[i+help] == list[j]) {
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
	cout << "\nВыберите алгоритм.\nЛинейный поиск - 0; поиск КМП - 1: ";
	cin >> choice;
	switch (choice) {
	case 0:
		LinearSearch(str, sub);
		break;
	}

}
