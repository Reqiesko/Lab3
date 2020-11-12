#include "ex_work.h"
#include "func.h"
#include "ui.h"




void keyboard_way() {
	stats_of_method bubble_sort_st;
	stats_of_method selection_sort_st;
	stats_of_method insertion_sort_st;
	stats_of_method shell_sort_st;
	stats_of_method quick_sort_st;
	int m, n, count = 0;
	const int min_rows = 2, min_cols = 1, min_ev_num = 2;
	string outpath;
	string inpath;
	cout << "Введите количество строк: " << endl;
	m = number_check();
	while (m < min_rows) {
		cout << "Ошибка! Количество строк не может быть меньше 2. \nВведите число: " << endl;
		m = number_check();
	}
	cout << "Введите количество столбцов: " << endl;
	n = number_check();
	while (n < min_cols) {
		cout << "Ошибка! Количество столбцов не может быть меньше 1. \nВведите число: " << endl;
		n = number_check();
	}		
	int** unsorted_mat = create_mat(m, n);
	keyboard_input(unsorted_mat, m, n);		
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (unsorted_mat[i][j] % 2 == 0) {
				count++;
			}
		}
	}
	if (count < min_ev_num) {
		cout << "Необходимо минимум 2 четных элемента, для сортировки!" << endl;
		main_menu();
	}
	int** temp_mat = create_mat(m, n);
	int** sorted_mat = create_mat(m, n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			sorted_mat[i][j] = unsorted_mat[i][j];
			temp_mat[i][j] = unsorted_mat[i][j];
		}
	}
	cout << "Исходный массив: " << endl;
	print_mat(unsorted_mat, m, n);
	cout << "Сохранить исходные данные в файл? " << endl;
	if (save_result_q() == yes) {
		cout << "Введите путь к файлу вывода: " << endl;
		print_source(unsorted_mat, m, n);
	}
	bubble_sort_st = {};
	bubble_sort(temp_mat, m, n, bubble_sort_st.compare, bubble_sort_st.change);
	cout << "Сортировка методом пузырька: " << endl;
	print_mat(temp_mat, m, n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			temp_mat[i][j] = unsorted_mat[i][j];
		}
	}
	selection_sort_st = {};
	selection_sort(temp_mat, m, n, selection_sort_st.compare, selection_sort_st.change);
	cout << "Сортировка методом отбора: " << endl;
	print_mat(temp_mat, m, n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			temp_mat[i][j] = unsorted_mat[i][j];
		}
	}
	insertion_sort_st = {};
	insertion_sort(temp_mat, m, n, insertion_sort_st.compare, insertion_sort_st.change);
	cout << "Сортировка методом вставки: " << endl;
	print_mat(temp_mat, m, n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			temp_mat[i][j] = unsorted_mat[i][j];
		}
	}
	shell_sort_st = {};
	shell_sort(temp_mat, m, n, shell_sort_st.compare, shell_sort_st.change);
	cout << "Сортировка методом Шелла: " << endl;
	print_mat(temp_mat, m, n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			temp_mat[i][j] = unsorted_mat[i][j];
		}
	}
	quick_sort_st = {};
	quick_sort(sorted_mat, m, n, quick_sort_st.compare, quick_sort_st.change);
	cout << "Быстрая сортировка: " << endl;
	print_mat(sorted_mat, m, n);
	stats_of_all_methods STATS = {
		bubble_sort_st.compare, bubble_sort_st.change,
		selection_sort_st.compare, selection_sort_st.change,
		insertion_sort_st.compare, insertion_sort_st.change,
		shell_sort_st.compare, shell_sort_st.change,
		quick_sort_st.compare, quick_sort_st.change };
	cout << "-------------------- Таблица результатов --------------------" << endl;
	cout << "Метод" << setw(33) << "Кол-во сравнений" << setw(23) << "Кол-во перестановок" << endl;
	cout << "Сортировка пузырьком" << setw(10) << bubble_sort_st.compare << setw(20) << bubble_sort_st.change << endl;
	cout << "Сортировка отбором  " << setw(10) << selection_sort_st.compare << setw(20) << selection_sort_st.change << endl;
	cout << "Сортировка вставкой " << setw(10) << insertion_sort_st.compare << setw(20) << insertion_sort_st.change << endl;
	cout << "Сортировка Шелла    " << setw(10) << shell_sort_st.compare << setw(20) << shell_sort_st.change << endl;
	cout << "Быстрая сортировка  " << setw(10) << quick_sort_st.compare << setw(20) << quick_sort_st.change << endl;
	cout << endl;

	cout << "Сохранить результат в файл? " << endl;
	if (save_result_q() == yes) {
		cout << "Введите путь к файлу вывода: " << endl;
		print_result_in_file(inpath, outpath, unsorted_mat, sorted_mat, m, n, STATS);
	}
	system("pause");
	if (n > min_cols) {
		for (int i = 0; i < m; i++) {
			delete[] unsorted_mat[i];
			delete[] temp_mat[i];
			delete[] sorted_mat[i];
		}
	}
	else {
		delete[] unsorted_mat;
		delete[] temp_mat;
		delete[] sorted_mat;
	}
	main_menu();
}

void file_way() {
	const int ignor = 32767, r_and_c = 2, min_ev_num = 2, min_cols = 1;
	stats_of_method bubble_sort_st;
	stats_of_method selection_sort_st;
	stats_of_method insertion_sort_st;
	stats_of_method shell_sort_st;
	stats_of_method quick_sort_st;
	int m, n;
	vector<int>c_check;
	string outpath;
	string inpath;
	ifstream fin;
	cout << "Укажите путь к файлу: " << endl;
	cin >> inpath;
	fin.open(inpath);
	while (file_name_check(inpath)) {
		fin.close();
		cout << "Ошибка! Введен неккоректный путь к файлу! \nВведите путь к файлу: " << endl;
		cin >> inpath;
		fin.open(inpath);
	}
	if (!fin.is_open()) {
		cout << "Ошибка! Не удаётся открыть файл!" << endl;
		cin.clear();
		cin.ignore(ignor, '\n');
		main_menu();
	}
	else {
		int temp_int, count = 0;
		if (file_check_size(inpath) == true) {
			cout << "Ошибка! Файл пуст!" << endl;
			cin.clear();
			cin.ignore(ignor, '\n');
			fin.close();
			main_menu();
		}
		while (fin) {
			while (count < r_and_c) {				
				fin >> temp_int;
				if (fin.fail() && !fin.eof()) {
					cout << "Ошибка! Файл содержит некорректные данные. " << endl;
					cin.clear();
					cin.ignore(ignor, '\n');
					fin.close();
					main_menu();
				}
				count++;
				c_check.push_back(temp_int);				
			}
			count = 0;
			c_check.push_back(c_check[0] * c_check[1]);
			while (fin) {				
				fin >> temp_int;
				if (fin.fail()) {
					cout << "Ошибка! Файл содержит некорректные данные. " << endl;
					cin.clear();
					cin.ignore(ignor, '\n');
					fin.close();
					main_menu();
				}	
				else {
					count++;
				}
				if (count == c_check[2]) {
					break;
				}	
			}			
			break;
		}
		fin.close();
		fin.open(inpath, ios::in);
		fin >> m;
		fin >> n;
		int** unsorted_mat = create_mat(m, n);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				fin >> unsorted_mat[i][j];
			}
		}
		count = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (unsorted_mat[i][j] % 2 == 0) {
					count++;
				}
			}
		}
		if (count < min_ev_num) {
			cout << "Необходимо минимум 2 четных элемента, для сортировки!" << endl;
			main_menu();
		}
		int** temp_mat = create_mat(m, n);
		int** sorted_mat = create_mat(m, n);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				sorted_mat[i][j] = unsorted_mat[i][j];
				temp_mat[i][j] = unsorted_mat[i][j];
			}
		}
		cout << "Исходный массив: " << endl;
		print_mat(unsorted_mat, m, n);
		bubble_sort_st = {};
		bubble_sort(temp_mat, m, n, bubble_sort_st.compare, bubble_sort_st.change);
		cout << "Сортировка методом пузырька: " << endl;
		print_mat(temp_mat, m, n);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				temp_mat[i][j] = unsorted_mat[i][j];
			}
		}
		selection_sort_st = {};
		selection_sort(temp_mat, m, n, selection_sort_st.compare, selection_sort_st.change);
		cout << "Сортировка методом отбора: " << endl;
		print_mat(temp_mat, m, n);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				temp_mat[i][j] = unsorted_mat[i][j];
			}
		}
		insertion_sort_st = {};
		insertion_sort(temp_mat, m, n, insertion_sort_st.compare, insertion_sort_st.change);
		cout << "Сортировка методом вставки: " << endl;
		print_mat(temp_mat, m, n);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				temp_mat[i][j] = unsorted_mat[i][j];
			}
		}
		shell_sort_st = {};
		shell_sort(temp_mat, m, n, shell_sort_st.compare, shell_sort_st.change);
		cout << "Сортировка методом Шелла: " << endl;
		print_mat(temp_mat, m, n);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				temp_mat[i][j] = unsorted_mat[i][j];
			}
		}
		quick_sort_st = {};
		quick_sort(sorted_mat, m, n, quick_sort_st.compare, quick_sort_st.change);
		cout << "Быстрая сортировка: " << endl;
		print_mat(sorted_mat, m, n);
		stats_of_all_methods STATS = {
			bubble_sort_st.compare, bubble_sort_st.change,
			selection_sort_st.compare, selection_sort_st.change,
			insertion_sort_st.compare, insertion_sort_st.change,
			shell_sort_st.compare, shell_sort_st.change,
			quick_sort_st.compare, quick_sort_st.change };
		cout << "-------------------- Таблица результатов --------------------" << endl;
		cout << "Метод" << setw(33) << "Кол-во сравнений" << setw(23) << "Кол-во перестановок" << endl;
		cout << "Сортировка пузырьком" << setw(10) << bubble_sort_st.compare << setw(20) << bubble_sort_st.change << endl;
		cout << "Сортировка отбором  " << setw(10) << selection_sort_st.compare << setw(20) << selection_sort_st.change << endl;
		cout << "Сортировка вставкой " << setw(10) << insertion_sort_st.compare << setw(20) << insertion_sort_st.change << endl;
		cout << "Сортировка Шелла    " << setw(10) << shell_sort_st.compare << setw(20) << shell_sort_st.change << endl;
		cout << "Быстрая сортировка  " << setw(10) << quick_sort_st.compare << setw(20) << quick_sort_st.change << endl;
		cout << endl;

		cout << "Сохранить результат в файл? " << endl;
		if (save_result_q() == yes) {
			cout << "Введите путь к файлу вывода: " << endl;
			print_result_in_file(inpath, outpath, unsorted_mat, sorted_mat, m, n, STATS);
		}
		system("pause");
		if (n > min_cols) {
			for (int i = 0; i < m; i++) {
				delete[] unsorted_mat[i];
				delete[] temp_mat[i];
				delete[] sorted_mat[i];
			}
		}
		else {
			delete[] unsorted_mat;
			delete[] temp_mat;
			delete[] sorted_mat;
		}
		main_menu();
	}
}

void random_way() {
	stats_of_method bubble_sort_st;
	stats_of_method selection_sort_st;
	stats_of_method insertion_sort_st;
	stats_of_method shell_sort_st;
	stats_of_method quick_sort_st;
	string outpath;
	string inpath;
	int m, n;
	const int min_rows = 2, min_cols = 1;
	cout << "Введите количество строк: " << endl;
	m = number_check();
	while (m < min_rows) {
		cout << "Ошибка! Количество строк не может быть меньше 2. \nВведите число: " << endl;
		m = number_check();
	}
	cout << "Введите количество столбцов: " << endl;
	n = number_check();
	while (n < min_cols) {
		cout << "Ошибка! Количество столбцов не может быть меньше 1. \nВведите число: " << endl;
		n = number_check();
	}
	int** unsorted_mat = create_mat(m, n);
	random_input(unsorted_mat, m, n);
	int** temp_mat = create_mat(m, n);
	int** sorted_mat = create_mat(m, n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			sorted_mat[i][j] = unsorted_mat[i][j];
			temp_mat[i][j] = unsorted_mat[i][j];
		}
	}
	cout << "Исходный массив: " << endl;
	print_mat(unsorted_mat, m, n);
	cout << "Сохранить исходные данные в файл? " << endl;
	if (save_result_q() == yes) {
		cout << "Введите путь к файлу вывода: " << endl;
		print_source(unsorted_mat, m, n);
	}
	bubble_sort_st = {};
	bubble_sort(temp_mat, m, n, bubble_sort_st.compare, bubble_sort_st.change);
	cout << "Сортировка методом пузырька: " << endl;
	print_mat(temp_mat, m, n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			temp_mat[i][j] = unsorted_mat[i][j];
		}
	}
	selection_sort_st = {};
	selection_sort(temp_mat, m, n, selection_sort_st.compare, selection_sort_st.change);
	cout << "Сортировка методом отбора: " << endl;
	print_mat(temp_mat, m, n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			temp_mat[i][j] = unsorted_mat[i][j];
		}
	}
	insertion_sort_st = {};
	insertion_sort(temp_mat, m, n, insertion_sort_st.compare, insertion_sort_st.change);
	cout << "Сортировка методом вставки: " << endl;
	print_mat(temp_mat, m, n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			temp_mat[i][j] = unsorted_mat[i][j];
		}
	}
	shell_sort_st = {};
	shell_sort(temp_mat, m, n, shell_sort_st.compare, shell_sort_st.change);
	cout << "Сортировка методом Шелла: " << endl;
	print_mat(temp_mat, m, n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			temp_mat[i][j] = unsorted_mat[i][j];
		}
	}
	quick_sort_st = {};
	quick_sort(sorted_mat, m, n, quick_sort_st.compare, quick_sort_st.change);
	cout << "Быстрая сортировка: " << endl;
	print_mat(sorted_mat, m, n);
	stats_of_all_methods STATS = {
		bubble_sort_st.compare, bubble_sort_st.change,
		selection_sort_st.compare, selection_sort_st.change,
		insertion_sort_st.compare, insertion_sort_st.change,
		shell_sort_st.compare, shell_sort_st.change,
		quick_sort_st.compare, quick_sort_st.change };
	
	cout << "-------------------- Таблица результатов --------------------" << endl;
	cout << "Метод" << setw(33) << "Кол-во сравнений" << setw(23) << "Кол-во перестановок" << endl;
	cout << "Сортировка пузырьком" << setw(10) << bubble_sort_st.compare << setw(20) << bubble_sort_st.change << endl;
	cout << "Сортировка отбором  " << setw(10) << selection_sort_st.compare << setw(20) << selection_sort_st.change << endl;
	cout << "Сортировка вставкой " << setw(10) << insertion_sort_st.compare << setw(20) << insertion_sort_st.change << endl;
	cout << "Сортировка Шелла    " << setw(10) << shell_sort_st.compare << setw(20) << shell_sort_st.change << endl;
	cout << "Быстрая сортировка  " << setw(10) << quick_sort_st.compare << setw(20) << quick_sort_st.change << endl;
	cout << endl;

	cout << "Сохранить результат в файл? " << endl;
	if (save_result_q() == yes) {
		cout << "Введите путь к файлу вывода: " << endl;
		print_result_in_file(inpath, outpath, unsorted_mat, sorted_mat, m, n, STATS);
	}
	system("pause");
	if (n > min_cols) {
		for (int i = 0; i < m; i++) {
			delete[] unsorted_mat[i];
			delete[] temp_mat[i];
		  delete[] sorted_mat[i];
		}
	}
	else {
		delete[] unsorted_mat;
		delete[] temp_mat;
		delete[] sorted_mat;
	}
	main_menu();
}