#include "func.h"
#include "ui.h"

 int number_check() {
	int a;
	while (!(cin >> a) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Ошибка! Пожалуйста введите число! " << endl;
	}
	return a;
}

double numb_check() {
	double a;
	while (!(cin >> a) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Ошибка! Пожалуйста введите число! " << endl;
	}
	return a;
}

bool file_name_check(string filename) {
	size_t found = filename.find_last_of("\\");
	size_t point = filename.find_last_of(".");
	size_t base = point - found - 1;
	string basefilenameStr = filename.substr(found + 1, base);
	const char* basefilenameChar = basefilenameStr.c_str();
	ofstream file(filename, ios::app);
	if (!_strcmpi(basefilenameChar, "con")) return true;
	if (!is_regular_file(filename)) return true;
	file.close();
	return false;
}

bool file_check_size(string pFile) {
	ifstream file_check_size;
	file_check_size.open(pFile, ios::in);
	file_check_size.seekg(0, ios::end);
	streamoff size = file_check_size.tellg();
	if (size == 0) {
		file_check_size.close();
		return true;
	}
	else {
		file_check_size.close();
		return false;
	}
}

bool error_check() {
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Пожалуйста введите цифру из ниже указанных! " << endl;
		return 0;
	}
	return 1;
}

void print_mat(int** array, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << setw(5) << "U" << "[" << i + 1 << "]" << "[" << j + 1 << "]" << " = ";
			cout << setw(5) << array[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

int** create_mat(int m, int n) {
	int** array = new int* [m];
	for (int i = 0; i < m; i++) {
		array[i] = new int[n];
	}
	return array;
}

void keyboard_input(int** array, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << "U" << "[" << i + 1 << "]" << "[" << j + 1 << "]" << " = ";
			array[i][j] = number_check();
		}
		cout << endl;
	}
}

void bubble_sort(int** array, int m, int n, int& compare, int& change) {
	vector<int> temp_mat, index_mat;
	int next;
	for (int j = 0; j < n; j++) {	
		for (int i = 0; i < m; i++) {
			if (array[i][j] % 2 == 0) {
				temp_mat.push_back(array[i][j]);
				index_mat.push_back(i);
			}
		}
		int size = static_cast<int>(temp_mat.size());
		for (int l = 0; l < size - 1; l++) {
			if (l == 1 && change == 0) {
				break;
			}
			for (int i = 0; i < size - 1 - l; i++) {
				compare++;
				next = i + 1;
				if (temp_mat[i] < temp_mat[next]) {
					swap(temp_mat[i], temp_mat[next]);
					change++;
				}				
			}
		}	
		for (int i = 0; i < static_cast<int>(index_mat.size()); i++) {		
				array[index_mat[i]][j] = temp_mat[i];		
		}
		temp_mat.clear();
		index_mat.clear();
	}
}

void selection_sort(int** array, int m, int n, int& compare, int& change) { 
	vector<int> temp_mat, index_mat;
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < m; i++) {
			if (array[i][j] % 2 == 0) {
				temp_mat.push_back(array[i][j]);
				index_mat.push_back(i);
			}
		}	
		for (int l = 0; l < static_cast<int>(temp_mat.size()) - 1; l++) {
			int max = l;
			for (int i = l + 1; i < static_cast<int>(temp_mat.size()); i++) {
				compare++;
				if (temp_mat[i] > temp_mat[max]) {
					max = i;
				}
			}
			if (temp_mat[max] != temp_mat[l]) {
				swap(temp_mat[l], temp_mat[max]);
				change++;
			}
		}
	
		for (int i = 0; i < static_cast<int>(index_mat.size()); i++) {
			array[index_mat[i]][j] = temp_mat[i];
		}
		temp_mat.clear();
		index_mat.clear();
	}
}

void insertion_sort(int** array, int m, int n, int& compare, int& change) { 
	vector<int> temp_mat, index_mat;
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < m; i++) {
			if (array[i][j] % 2 == 0) {
				temp_mat.push_back(array[i][j]);
				index_mat.push_back(i);
			}
		}
	  for (int i = 1; i < static_cast<int>(temp_mat.size()); i++) {		
			for (int l = i; l > 0; l--) {
				compare++;
				if (temp_mat[l - 1] < temp_mat[l]) {
					change++;
					swap(temp_mat[l - 1], temp_mat[l]);
				}
				else {
					break;
				}
			}
		}		
		for (int i = 0; i < static_cast<int>(index_mat.size()); i++) {
			array[index_mat[i]][j] = temp_mat[i];
		}
		temp_mat.clear();
		index_mat.clear();
	}
}

void shell_sort(int** array, int m, int n, int& compare, int& change) { 
	vector<int> temp_mat, index_mat;
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < m; i++) {
			if (array[i][j] % 2 == 0) {
				temp_mat.push_back(array[i][j]);
				index_mat.push_back(i);
			}
		}		
		int size = static_cast<int>(temp_mat.size());
		for (int step = size / 2; step > 0; step /= 2) {
			for (int i = step; i < size; i++) {
				for (int l = i - step; l >= 0; l -= step) {				
					if (temp_mat[l] < temp_mat[l + step]) {
						compare++;
						swap(temp_mat[l], temp_mat[l + step]);						
						change++;
					}
					else {
						compare++;
						break;
					}
				}
			}
		}
		for (int i = 0; i < static_cast<int>(index_mat.size()); i++) {
			array[index_mat[i]][j] = temp_mat[i];
		}
		temp_mat.clear();
		index_mat.clear();
	}
}

void quick_sort(int** array, int m, int n, int& compare, int& change) { 
	vector<int> temp_mat, index_mat;
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < m; i++) {
			if (array[i][j] % 2 == 0) {
				temp_mat.push_back(array[i][j]);
				index_mat.push_back(i);
			}
		}
		qsort_recursive(temp_mat, 0, static_cast<int>(index_mat.size()) - 1, compare, change);
		for (int i = 0; i < static_cast<int>(index_mat.size()); i++) {
			array[index_mat[i]][j] = temp_mat[i];
		}
		temp_mat.clear();
		index_mat.clear();
	}
}

void qsort_recursive(vector<int>& temp_mat, int left, int right, int& compare, int& change) {
	int l = left;
	int r = right;
	int temp, middle;
	bool whileOne, whileTwo;
	middle = temp_mat[(l + r) / 2];
	while (l <= r) {
		whileOne = false; whileTwo = false;
		while ((temp_mat[l] > middle) && (l >= left)) {
			l++;
			whileOne = true;
			compare++;
		}
		if (whileOne == false)
			compare++;
		while ((temp_mat[r] < middle) && (r <= right)) {
			r--;
			whileTwo = true;
			compare++;
		}
		if (whileTwo == false)
			compare++;
		if (l <= r) {
			if (temp_mat[l] != temp_mat[r]) {
				swap(temp_mat[r], temp_mat[l]);				
				change++;
			}
			l++;
			r--;
		}
	}
	if (r > left)
		qsort_recursive(temp_mat, left, r, compare, change);
	if (l < right)
		qsort_recursive(temp_mat, l, right, compare, change);
}

void print_source(int** array, int m, int n) {
	string inpath;
	cin >> inpath;
	ifstream fcheck;
	fcheck.open(inpath);
	while (!check_read_only(inpath)) {
		fcheck.close();
		cout << "Введите путь к файлу: " << endl;
		cin >> inpath;
		fcheck.open(inpath);
	}
	while (file_name_check(inpath)) {
		fcheck.close();
		cout << "Ошибка! Некорректное путь или имя файла." << endl;
		cout << "Введите путь к файлу: " << endl;
		cin >> inpath;
		fcheck.open(inpath, ios::in);
	}
	if (file_exist(inpath) == false) {
		fcheck.close();
		save_source(inpath, array, rewrite, m, n);
	}
	else {
		fcheck.close();
		if (file_check_size(inpath) == true) {
			save_source(inpath, array, rewrite, m, n);
		}
		else {
			save_source(inpath, array, wtdw_file(inpath), m, n);
		}
	}
}


void save_source(string inpath, int** array, int modout, int m, int n) {
	ofstream fout;
	int rewrite = 1, add = 2;
	if (modout == rewrite) {
		fout.open(inpath, ios::out);
		fout << " " << endl;
	}
	if (modout == add) {
		fout.open(inpath, ios::app);
		fout << " " << endl;
	}
	fout << m << " " << n << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			fout << array[i][j] << " ";
		}
		fout << endl;
	}
	cout << "Данные успешно сохранены! " << endl;
}


void print_result_in_file(string inpath, string& outpath, int** array, int** arr, int m, int n, struct stats_of_all_methods STATS) {
	cin >> outpath;
	ifstream fcheck;
	if (inpath == outpath) {
		print_result(outpath, wtdw_file(outpath), array, arr, m, n, STATS);
		main_menu();
	}
	fcheck.open(outpath);
	while (!check_read_only(outpath)) {
		fcheck.close();
		cout << "Введите путь к файлу: " << endl;
		cin >> outpath;
		if (inpath == outpath) {
			print_result(outpath, wtdw_file(outpath), array, arr, m, n, STATS);
			main_menu();
		}
		fcheck.open(outpath);
	}
	while (file_name_check(outpath)) {
		fcheck.close();
		cout << "Ошибка! Некорректное путь или имя файла." << endl;
		cout << "Введите путь к файлу: " << endl;
		cin >> outpath;
		if (inpath == outpath) {
			print_result(outpath, wtdw_file(outpath), array, arr, m, n, STATS);
			main_menu();
		}
		fcheck.open(outpath, ios::in);
	}
	if (file_exist(outpath) == false) {
		fcheck.close();
		print_result(outpath, rewrite, array, arr, m, n, STATS);
	}
	else {
		fcheck.close();
		if (file_check_size(outpath) == true) {
			print_result(outpath, rewrite, array, arr, m, n, STATS);
		}
		else {
			print_result(outpath, wtdw_file(outpath), array, arr, m, n, STATS);
		}
	}
}

void print_result(string outpath, int modout, int** array, int** arr, int m, int n, struct stats_of_all_methods STATS){
	ofstream fout;
	if (modout == 1) {
		fout.open(outpath, ios::out);
		fout << " " << endl;
	}
	if (modout == 2) {
		fout.open(outpath, ios::app);
		fout << " " << endl;
	}
	fout << "Исходная матрица: " << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			fout << setw(10) << array[i][j];
		}
		fout << endl;
	}
	fout << endl;
	fout << "Отсортированная матрица: " << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			fout << setw(10) << arr[i][j];
		}
		fout << endl;
	}
	fout << endl;
	fout << "-------------------- Таблица результатов --------------------" << endl;
	fout << "Метод" << setw(33) << "Кол-во сравнений" << setw(23) << "Кол-во перестановок" << endl;
	fout << "Сортировка пузырьком" << setw(10) << STATS.bubble_sort_st.compare << setw(20) << STATS.bubble_sort_st.change << endl;
	fout << "Сортировка отбором  " << setw(10) << STATS.selection_sort_st.compare << setw(20) << STATS.selection_sort_st.change << endl;
	fout << "Сортировка вставкой " << setw(10) << STATS.insertion_sort_st.compare << setw(20) << STATS.insertion_sort_st.change << endl;
	fout << "Сортировка Шелла    " << setw(10) << STATS.shell_sort_st.compare << setw(20) << STATS.shell_sort_st.change << endl;
	fout << "Быстрая сортировка  " << setw(10) << STATS.quick_sort_st.compare << setw(20) << STATS.quick_sort_st.change << endl;
}



bool check_read_only(string filename) {
	ofstream file(filename, ios::in);
	LPCSTR name = filename.c_str();
	WIN32_FIND_DATAA findData;
	FindFirstFileA(name, &findData);
	if (findData.dwFileAttributes & FILE_ATTRIBUTE_READONLY) {
		cerr << "Ошибка! Невозможно сохранить данные в файл, предназначенный только для чтения! " << endl;
		return false;
	}
	else {
		return true;
	}
}


bool file_exist(string path) {
	ifstream file(path);
	file.open(path, ios::in);
	if (file.is_open())
		return true;
	else
		return false;
}


void random_input(int** array, int m, int n) {
	srand(time(NULL));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			array[i][j] = rand();
			 while (array[i][j] % 2 != 0) {
				 array[i][j] = rand();
			}
		}
		cout << endl;
	}
}