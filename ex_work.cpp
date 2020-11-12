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
	cout << "������� ���������� �����: " << endl;
	m = number_check();
	while (m < min_rows) {
		cout << "������! ���������� ����� �� ����� ���� ������ 2. \n������� �����: " << endl;
		m = number_check();
	}
	cout << "������� ���������� ��������: " << endl;
	n = number_check();
	while (n < min_cols) {
		cout << "������! ���������� �������� �� ����� ���� ������ 1. \n������� �����: " << endl;
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
		cout << "���������� ������� 2 ������ ��������, ��� ����������!" << endl;
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
	cout << "�������� ������: " << endl;
	print_mat(unsorted_mat, m, n);
	cout << "��������� �������� ������ � ����? " << endl;
	if (save_result_q() == yes) {
		cout << "������� ���� � ����� ������: " << endl;
		print_source(unsorted_mat, m, n);
	}
	bubble_sort_st = {};
	bubble_sort(temp_mat, m, n, bubble_sort_st.compare, bubble_sort_st.change);
	cout << "���������� ������� ��������: " << endl;
	print_mat(temp_mat, m, n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			temp_mat[i][j] = unsorted_mat[i][j];
		}
	}
	selection_sort_st = {};
	selection_sort(temp_mat, m, n, selection_sort_st.compare, selection_sort_st.change);
	cout << "���������� ������� ������: " << endl;
	print_mat(temp_mat, m, n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			temp_mat[i][j] = unsorted_mat[i][j];
		}
	}
	insertion_sort_st = {};
	insertion_sort(temp_mat, m, n, insertion_sort_st.compare, insertion_sort_st.change);
	cout << "���������� ������� �������: " << endl;
	print_mat(temp_mat, m, n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			temp_mat[i][j] = unsorted_mat[i][j];
		}
	}
	shell_sort_st = {};
	shell_sort(temp_mat, m, n, shell_sort_st.compare, shell_sort_st.change);
	cout << "���������� ������� �����: " << endl;
	print_mat(temp_mat, m, n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			temp_mat[i][j] = unsorted_mat[i][j];
		}
	}
	quick_sort_st = {};
	quick_sort(sorted_mat, m, n, quick_sort_st.compare, quick_sort_st.change);
	cout << "������� ����������: " << endl;
	print_mat(sorted_mat, m, n);
	stats_of_all_methods STATS = {
		bubble_sort_st.compare, bubble_sort_st.change,
		selection_sort_st.compare, selection_sort_st.change,
		insertion_sort_st.compare, insertion_sort_st.change,
		shell_sort_st.compare, shell_sort_st.change,
		quick_sort_st.compare, quick_sort_st.change };
	cout << "-------------------- ������� ����������� --------------------" << endl;
	cout << "�����" << setw(33) << "���-�� ���������" << setw(23) << "���-�� ������������" << endl;
	cout << "���������� ���������" << setw(10) << bubble_sort_st.compare << setw(20) << bubble_sort_st.change << endl;
	cout << "���������� �������  " << setw(10) << selection_sort_st.compare << setw(20) << selection_sort_st.change << endl;
	cout << "���������� �������� " << setw(10) << insertion_sort_st.compare << setw(20) << insertion_sort_st.change << endl;
	cout << "���������� �����    " << setw(10) << shell_sort_st.compare << setw(20) << shell_sort_st.change << endl;
	cout << "������� ����������  " << setw(10) << quick_sort_st.compare << setw(20) << quick_sort_st.change << endl;
	cout << endl;

	cout << "��������� ��������� � ����? " << endl;
	if (save_result_q() == yes) {
		cout << "������� ���� � ����� ������: " << endl;
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
	cout << "������� ���� � �����: " << endl;
	cin >> inpath;
	fin.open(inpath);
	while (file_name_check(inpath)) {
		fin.close();
		cout << "������! ������ ������������ ���� � �����! \n������� ���� � �����: " << endl;
		cin >> inpath;
		fin.open(inpath);
	}
	if (!fin.is_open()) {
		cout << "������! �� ������ ������� ����!" << endl;
		cin.clear();
		cin.ignore(ignor, '\n');
		main_menu();
	}
	else {
		int temp_int, count = 0;
		if (file_check_size(inpath) == true) {
			cout << "������! ���� ����!" << endl;
			cin.clear();
			cin.ignore(ignor, '\n');
			fin.close();
			main_menu();
		}
		while (fin) {
			while (count < r_and_c) {				
				fin >> temp_int;
				if (fin.fail() && !fin.eof()) {
					cout << "������! ���� �������� ������������ ������. " << endl;
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
					cout << "������! ���� �������� ������������ ������. " << endl;
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
			cout << "���������� ������� 2 ������ ��������, ��� ����������!" << endl;
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
		cout << "�������� ������: " << endl;
		print_mat(unsorted_mat, m, n);
		bubble_sort_st = {};
		bubble_sort(temp_mat, m, n, bubble_sort_st.compare, bubble_sort_st.change);
		cout << "���������� ������� ��������: " << endl;
		print_mat(temp_mat, m, n);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				temp_mat[i][j] = unsorted_mat[i][j];
			}
		}
		selection_sort_st = {};
		selection_sort(temp_mat, m, n, selection_sort_st.compare, selection_sort_st.change);
		cout << "���������� ������� ������: " << endl;
		print_mat(temp_mat, m, n);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				temp_mat[i][j] = unsorted_mat[i][j];
			}
		}
		insertion_sort_st = {};
		insertion_sort(temp_mat, m, n, insertion_sort_st.compare, insertion_sort_st.change);
		cout << "���������� ������� �������: " << endl;
		print_mat(temp_mat, m, n);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				temp_mat[i][j] = unsorted_mat[i][j];
			}
		}
		shell_sort_st = {};
		shell_sort(temp_mat, m, n, shell_sort_st.compare, shell_sort_st.change);
		cout << "���������� ������� �����: " << endl;
		print_mat(temp_mat, m, n);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				temp_mat[i][j] = unsorted_mat[i][j];
			}
		}
		quick_sort_st = {};
		quick_sort(sorted_mat, m, n, quick_sort_st.compare, quick_sort_st.change);
		cout << "������� ����������: " << endl;
		print_mat(sorted_mat, m, n);
		stats_of_all_methods STATS = {
			bubble_sort_st.compare, bubble_sort_st.change,
			selection_sort_st.compare, selection_sort_st.change,
			insertion_sort_st.compare, insertion_sort_st.change,
			shell_sort_st.compare, shell_sort_st.change,
			quick_sort_st.compare, quick_sort_st.change };
		cout << "-------------------- ������� ����������� --------------------" << endl;
		cout << "�����" << setw(33) << "���-�� ���������" << setw(23) << "���-�� ������������" << endl;
		cout << "���������� ���������" << setw(10) << bubble_sort_st.compare << setw(20) << bubble_sort_st.change << endl;
		cout << "���������� �������  " << setw(10) << selection_sort_st.compare << setw(20) << selection_sort_st.change << endl;
		cout << "���������� �������� " << setw(10) << insertion_sort_st.compare << setw(20) << insertion_sort_st.change << endl;
		cout << "���������� �����    " << setw(10) << shell_sort_st.compare << setw(20) << shell_sort_st.change << endl;
		cout << "������� ����������  " << setw(10) << quick_sort_st.compare << setw(20) << quick_sort_st.change << endl;
		cout << endl;

		cout << "��������� ��������� � ����? " << endl;
		if (save_result_q() == yes) {
			cout << "������� ���� � ����� ������: " << endl;
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
	cout << "������� ���������� �����: " << endl;
	m = number_check();
	while (m < min_rows) {
		cout << "������! ���������� ����� �� ����� ���� ������ 2. \n������� �����: " << endl;
		m = number_check();
	}
	cout << "������� ���������� ��������: " << endl;
	n = number_check();
	while (n < min_cols) {
		cout << "������! ���������� �������� �� ����� ���� ������ 1. \n������� �����: " << endl;
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
	cout << "�������� ������: " << endl;
	print_mat(unsorted_mat, m, n);
	cout << "��������� �������� ������ � ����? " << endl;
	if (save_result_q() == yes) {
		cout << "������� ���� � ����� ������: " << endl;
		print_source(unsorted_mat, m, n);
	}
	bubble_sort_st = {};
	bubble_sort(temp_mat, m, n, bubble_sort_st.compare, bubble_sort_st.change);
	cout << "���������� ������� ��������: " << endl;
	print_mat(temp_mat, m, n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			temp_mat[i][j] = unsorted_mat[i][j];
		}
	}
	selection_sort_st = {};
	selection_sort(temp_mat, m, n, selection_sort_st.compare, selection_sort_st.change);
	cout << "���������� ������� ������: " << endl;
	print_mat(temp_mat, m, n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			temp_mat[i][j] = unsorted_mat[i][j];
		}
	}
	insertion_sort_st = {};
	insertion_sort(temp_mat, m, n, insertion_sort_st.compare, insertion_sort_st.change);
	cout << "���������� ������� �������: " << endl;
	print_mat(temp_mat, m, n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			temp_mat[i][j] = unsorted_mat[i][j];
		}
	}
	shell_sort_st = {};
	shell_sort(temp_mat, m, n, shell_sort_st.compare, shell_sort_st.change);
	cout << "���������� ������� �����: " << endl;
	print_mat(temp_mat, m, n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			temp_mat[i][j] = unsorted_mat[i][j];
		}
	}
	quick_sort_st = {};
	quick_sort(sorted_mat, m, n, quick_sort_st.compare, quick_sort_st.change);
	cout << "������� ����������: " << endl;
	print_mat(sorted_mat, m, n);
	stats_of_all_methods STATS = {
		bubble_sort_st.compare, bubble_sort_st.change,
		selection_sort_st.compare, selection_sort_st.change,
		insertion_sort_st.compare, insertion_sort_st.change,
		shell_sort_st.compare, shell_sort_st.change,
		quick_sort_st.compare, quick_sort_st.change };
	
	cout << "-------------------- ������� ����������� --------------------" << endl;
	cout << "�����" << setw(33) << "���-�� ���������" << setw(23) << "���-�� ������������" << endl;
	cout << "���������� ���������" << setw(10) << bubble_sort_st.compare << setw(20) << bubble_sort_st.change << endl;
	cout << "���������� �������  " << setw(10) << selection_sort_st.compare << setw(20) << selection_sort_st.change << endl;
	cout << "���������� �������� " << setw(10) << insertion_sort_st.compare << setw(20) << insertion_sort_st.change << endl;
	cout << "���������� �����    " << setw(10) << shell_sort_st.compare << setw(20) << shell_sort_st.change << endl;
	cout << "������� ����������  " << setw(10) << quick_sort_st.compare << setw(20) << quick_sort_st.change << endl;
	cout << endl;

	cout << "��������� ��������� � ����? " << endl;
	if (save_result_q() == yes) {
		cout << "������� ���� � ����� ������: " << endl;
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