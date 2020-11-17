#include "ui.h"
#include "func.h"
#include "ex_work.h"
#include "module_tests.h"

void greeting() { 
	cout << "Эта программа сортирует матрицу различными методами и " << endl;
	cout << "выводит таблицу эффективности разных методов." << endl;
	cout << "Функция упорядочивает все четные элементы (значения элементов) столбцов массива по убыванию." << endl;
	cout << endl;
	cout << "Автор: Нерадовский Артемий" << endl;
	cout << "Группа: 494" << endl;
	cout << "Лабораторная работа №3" << endl;
	cout << "Вариант 12" << endl;
	cout << endl;
}

void main_menu() {
	int var;
	const int ignor = 32767;
	cout << endl;
	while (true) {
		cout << "Menu" << endl;
		cout << "Выберите вариант: " << endl;
		cout << "1. Заполнить массив с клавиатуры. " << endl;
		cout << "2. Заполнить массив значениями из файла. " << endl;
		cout << "3. Заполнить массив случайными значениями. " << endl;
		cout << "4. Выполнить тесты. " << endl;
		cout << "5. Выйти из программы. " << endl;
		cout << endl;
		cin >> var;
		if (!error_check()) {
			continue;
		}
		cin.ignore(ignor, '\n');
		switch (var) {
			case keyboard: {
				keyboard_way();
				break;
			}
			case from_file: {
				file_way();
				break;
			}
			case random: {
				random_way();
				break;
			}
			case test: {
				module_tests();
				main_menu();
			}
			case out: {
				cout << "Программа завершена." << endl;
				exit(0);
				break;
			}
			default: {
				cout << "Пожалуйста введите цифру из ниже указанных! " << endl;
			}
		}
		cin.clear();
	}
}


int save_result_q() {
	int var;
	const int ignor = 32767;
	bool sw = true;
	while (sw) {
		cout << "1. Да " << endl;
		cout << "2. Нет " << endl;
		cin >> var;
		if (!error_check()) {
			continue;
		}
		cin.ignore(ignor, '\n');
		switch (var) {
			case yes: {
				return yes;
				break;
			}
			case no: {
				return no;
				break;
			}
			default: {
				cout << "Пожалуйста введите цифру 1 или 2. " << endl;
			}
		}
		cin.clear();
	}
	return 0;
}


int wtdw_file(string& pFile) {
	const int ignor = 32767;
	bool d = true;
	ifstream foutcheck;
	int del;

	while (d) {
		cout << "Файл не пуст! Выберите вариант." << endl;
		cout << "1. Перезаписать." << endl;
		cout << "2. Дописать в конец." << endl;
		cout << "3. Указать другой файл." << endl;
		cin >> del;

		if (!error_check()) {
			continue;
		}
		cin.ignore(ignor, '\n');
		switch (del) {
			case rewrite: {
				return rewrite;
			}
			case add: {
				return add;
			}
			case newfile: {
				bool trg = true;
				while (trg) {
					cout << "Введите путь к файлу. " << endl;
					cin >> pFile;
					foutcheck.open(pFile, ios::in);
					while (file_name_check(pFile)) {
						foutcheck.close();
						cout << "Ошибка! Некорректный путь или имя файла." << endl;
						cout << "Введите путь к файлу: " << endl;
						cin >> pFile;
						foutcheck.open(pFile, ios::in);
					}
					while (!check_read_only(pFile)) {
						foutcheck.close();
						cout << "Введите путь к файлу: " << endl;
						cin >> pFile;
						foutcheck.open(pFile);
					}
					if (!foutcheck.is_open()) {
						ifstream newfile(pFile);
						newfile.close();
						return rewrite;
					}
					else {
						bool check = file_check_size(pFile);
						foutcheck.close();
						if (check) {
							return 0;
						}
						else {
							return wtdw_file(pFile);
						}
					}
				}
			}
			default: {
				cout << "Пожалуйста введите цифру 1, 2 или 3. " << endl;
			}
		}
	}
	return 0;
}