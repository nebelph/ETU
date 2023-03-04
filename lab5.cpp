#include <iostream>
#include <string>
#include <fstream>

void ofstream(struct Student*);
void ifstream(struct Student*);


struct Student {
	std::string full_name;
	char sex;
	int group;
	int id;
	int grades[8];
};

void PrintTasks();
std::string FIO(std::string);
void Change(struct Student*); // 2
void PrintStudent(struct Student*, int);
void Print(struct Student*); // 3
void PrintGroup(struct Student*); // 4
void PrintBestStudents(struct Student*); // 5
void MaleFemale(struct Student*); // 6
void Grades(struct Student*); // 7
void IdSearch(struct Student*); // 8

const int SIZE = 30;

void sizeOf(struct Student* students) {
	std::cout << sizeof(students) * SIZE;
}

int main() {
	setlocale(LC_ALL, "Russian");

	struct Student students[SIZE];

	sizeOf(students);

	int task = 1;
	while (task) {
		PrintTasks();
		std::cout << "Выберите номер задания (1-9): ";
		std::cin >> task;
		switch (task) {
		case 1:
			ifstream(students);
			std::cout << "Данные о студентах считаны из файла." << std::endl;
			break;
		case 2:
			Change(students);
			std::cout << std::endl;
			break;
		case 3:
			std::cout << "Список студентов:" << std::endl << std::endl;
			Print(students);
			std::cout << std::endl;
			break;
		case 4:
			PrintGroup(students);
			break;
		case 5:
			std::cout << "Тройка лучших студентов:" << std::endl << std::endl;
			PrintBestStudents(students);
			std::cout << std::endl;
			break;
		case 6:
			MaleFemale(students);
			std::cout << std::endl;
			break;
		case 7:
			Grades(students);
			std::cout << std::endl;
			break;
		case 8:
			IdSearch(students);
			std::cout << std::endl;
			break;
		case 9:
			ofstream(students);
			std::cout << "Данные о студентах записаны в файл." << std::endl;
			break;
		}
	}
	return 0;
}

void PrintTasks() {
	std::cout << std::endl << "1. Прочесть данные о студентах из файла." << std::endl;
	std::cout << "2. Внести изменения в данные о студентах." << std::endl;
	std::cout << "3. Вывести информацию обо всех студентах." << std::endl;
	std::cout << "4. Вывести информацию о студентах группы N." << std::endl;
	std::cout << "5. Вывести топ самых успешных студентов." << std::endl;
	std::cout << "6. Вывести количество студентов мужского и женского пола." << std::endl;
	std::cout << "7. Вывести информацию о студентах с разными оценками." << std::endl;
	std::cout << "8. Вывести информацию о студентах, имеющих номер в списке k." << std::endl;
	std::cout << "9. Записать данные о студентах в файл." << std::endl << std::endl;
}
std::string FIO(std::string string) {
	//std::getline(std::cin, string);
	std::string str1, str2, str3;
	std::cin >> str1;
	std::cin >> str2;
	std::cin >> str3;
	string = str1 + " " + str2 + " " + str3;
	return string;
}
void Change(struct Student* students) {
	int number;
	std::string parameter;
	bool yes, yes1;
	do {
		std::cout << "Введите номер студента (0-29): ";
		std::cin >> number;
		do {
			std::cout << "Что нужно изменить? (name/sex/group/id/grades) ";
			std::cin >> parameter;
			if (parameter == "name") {
				std::string name_new;
				std::cout << "Введите новое ФИО: ";
				(students + number)->full_name = FIO(name_new);
			}
			else if (parameter == "sex") {
				char sex_new;
				std::cout << "Введите новый пол: ";
				std::cin >> sex_new;
				(students + number)->sex = sex_new;
			}
			else if (parameter == "group") {
				int group_new;
				std::cout << "Введите новый номер группы: ";
				std::cin >> group_new;
				(students + number)->group = group_new;
			}
			else if (parameter == "id") {
				int id_new;
				std::cout << "Введите новый номер в списке: ";
				std::cin >> id_new;
				(students + number)->id = id_new;
			}
			else if (parameter == "grades") {
				int grades_new[8];
				std::cout << "Введите новые оценки (через пробел): ";
				for (int i = 0; i < 8; i++) {
					std::cin >> grades_new[i];
					(students + number)->grades[i] = grades_new[i];
				}
			}
			std::string yes_or_no;
			std::cout << "Хотите изменить что-то еще? (yes/no) ";
			std::cin >> yes_or_no;
			if (yes_or_no == "yes")
				yes1 = true;
			else
				yes1 = false;
		} while (yes1);
		std::string yes_or_no;
		std::cout << "Хотите внести изменения другому студенту? (yes/no) ";
		std::cin >> yes_or_no;
		if (yes_or_no == "yes")
			yes = true;
		else
			yes = false;
	} while (yes);
}
void PrintStudent(struct Student* students, int i) {
	std::cout << i+1 << ") " << "ФИО: " << (students + i)->full_name << "\n";
	std::cout << "Пол: " << (students + i)->sex << "\t";
	std::cout << "Номер группы: " << (students + i)->group << "\t";
	std::cout << "Номер в группе: " << (students + i)->id << "\t";
	std::cout << "Оценки: ";
	for (int j = 0; j < 8; j++) {
		std::cout << (students + i)->grades[j] << " ";
	}
	std::cout << std::endl << std::endl;
}
void Print(struct Student* students) {
	for (int i = 0; i < SIZE; i++) {
		PrintStudent(students, i);
	}
}
void PrintGroup(struct Student* students) {
	int group_num;
	std::cout << "Введите номер группы: ";
	std::cin >> group_num;
	std::cout << "Список студентов группы " << group_num << ":" << std::endl;
	for (int i = 0; i < SIZE; i++) {
		if ((students + i)->group == group_num) {
			PrintStudent(students, i);
		};
	}
}
void PrintBestStudents(struct Student* students) {
	double arr_grades[SIZE];
	int sum_grade;
	double curr_grade;
	for (int i = 0; i < SIZE; i++) {
		sum_grade = 0;
		for (int j = 0; j < 8; j++) {
			sum_grade += (students + i)->grades[j];
		}
		curr_grade = sum_grade / 8;
		arr_grades[i] = curr_grade;
	}

	int arr_numb[SIZE];

	for (int i = 0; i < SIZE; i++) {
		arr_numb[i] = i;
	}

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE - 1; j++) {
			if (arr_grades[i] > arr_grades[j + 1]) {
				std::swap(arr_grades[i], arr_grades[j + 1]);
				std::swap(arr_numb[i], arr_numb[j + 1]);
			}
		}
	}

	for (int i = 1; i < 4; i++) {
		PrintStudent(students, arr_numb[i]);
	}
}
void MaleFemale(struct Student* students) {
	int m_amount = 0, fem_amount = 0;
	for (int i = 0; i < SIZE; i++) {
		if ((students + i)->sex == 'M')
			m_amount += 1;
		else
			fem_amount += 1;
	}
	std::cout << "Количество парней: " << m_amount << std::endl;
	std::cout << "Количество девушек: " << fem_amount << std::endl;
}
void Grades(struct Student* students) {
	std::string arr_value[SIZE];
	for (int i = 0; i < SIZE; i++) {
		bool low = false;
		int sum = 0;
		for (int j = 0; j < 8; j++) {
			if ((students + i)->grades[j] <= 3) {
				low = true;
				break;
			}
			else {
				sum += (students + i)->grades[j];
			}
		}
		if (low) {
			arr_value[i] = "low";
			continue;
		}
		if (sum == 5 * 8)
			arr_value[i] = "high";
		else
			arr_value[i] = "middle";
	}
	std::cout << "Студенты, учащиеся на 5:" << std::endl;
	for (int i = 0; i < SIZE; i++) {
		if (arr_value[i] == "high")
			PrintStudent(students, i);
	}
	std::cout << "Студенты, учащиеся на 4 и 5:" << std::endl;
	for (int i = 0; i < SIZE; i++) {
		if (arr_value[i] == "middle")
			PrintStudent(students, i);
	}
	std::cout << "Студенты, не получающие стипендию:" << std::endl;
	for (int i = 0; i < SIZE; i++) {
		if (arr_value[i] == "low")
			PrintStudent(students, i);
	}
}
void IdSearch(struct Student* students) {
	int id;
	std::cout << "Введите номер из списка: ";
	std::cin >> id;
	std::cout << "Список студентов, имеющих " << id << " номер в списке группы:" << std::endl;
	for (int i = 0; i < SIZE; i++) {
		if ((students + i)->id == id)
			PrintStudent(students, i);
	}
}

void ofstream(struct Student* student) {
	std::ofstream fout;

	fout.open("database_new.txt", std::ofstream::app);

	if (!fout.is_open()) {
		std::cout << "Ошибка открытия файла!\n\n";
	}
	else {

		std::string full_name;
		char sex;
		int group;
		int id;
		int grades[8];

		for (int y = 0; y < SIZE; y++) {
			for (int i = 1; i <= 5; i++) {
				if (i % 5 == 1) {
					full_name = (student + y)->full_name;
					fout << full_name << std::endl;
				}
				else if (i % 5 == 2) {
					sex = (student + y)->sex;
					fout << sex << std::endl;
				}
				else if (i % 5 == 3) {
					group = (student + y)->group;
					fout << group << std::endl;
				}
				else if (i % 5 == 4) {
					id = (student + y)->id;
					fout << id << std::endl;
				}
				else if (i % 5 == 0) {
					for (int j = 0; j < 8; j++) {
						grades[j] = (student + y)->grades[j];
					}
					for (int j = 0; j < 8; j++) {
						fout << grades[j] << " ";
					}
					if (y != 29) {
						fout << std::endl;
					}
				}
			}
		}
	}
	fout.close();
}
void ifstream(struct Student* student) {
	std::ifstream fin;

	fin.open("database.txt");

	if (!fin.is_open()) {
		std::cout << "Error!\n\n";
	}
	else {
		std::string full_name;
		char sex;
		int group;
		int id;
		int grades[8];

		int d = 0;

		for (int y = 0; y < SIZE; y++) {
			fin.seekg(d);
			for (int i = 1; i <= 5; i++) {
				if (i % 5 == 1) {
					std::getline(fin, full_name);
					(student + y)->full_name = full_name;
				}
				else if (i % 5 == 2) {
					fin >> sex;
					(student + y)->sex = sex;
				}
				else if (i % 5 == 3) {
					fin >> group;
					(student + y)->group = group;
				}
				else if (i % 5 == 4) {
					fin >> id;
					(student + y)->id = id;
				}
				else if (i % 5 == 0) {
					for (int j = 0; j < 8; j++) {
						fin >> grades[j];
					}
					for (int j = 0; j < 8; j++) {
						(student + y)->grades[j] = grades[j];
					}
				}
			}
			d = fin.tellg();
			d += 2;
		}
	}
	fin.close();
}
