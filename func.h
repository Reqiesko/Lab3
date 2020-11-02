#pragma once
#include <iostream>
#include <fstream>
#include <istream>
#include <iomanip>
#include <filesystem>
#include <Windows.h>


using namespace std;
using namespace std::experimental::filesystem;

int number_check();

double numb_check();

bool file_name_check(string filename);

bool file_check_size(string pFile);

bool error_check();

void print_mat(int** array, int m, int n);

int** create_mat(int m, int n);

void keyboard_input(int** array, int m, int n);

void bubble_sort(int** array, int m, int n, int& compare, int& change);

void selection_sort(int** array, int m, int n, int& compare, int& change);

void insertion_sort(int** array, int m, int n, int& compare, int& change);

void shell_sort(int** array, int m, int n, int& compare, int& change);

void quick_sort(int** array, int m, int n, int& compare, int& change);

void qsort_recursive(vector<int>& temp_mat, int left, int right, int& compare, int& change);

void print_source(int** array, int m, int n);

void save_source(string inpath, int** array, int modout, int m, int n);

void print_result_in_file(string inpath, string& outpath, int** array, int** arr, int m, int n, struct stats_of_all_methods STATS);

void print_result(string outpath, int modout, int** array, int** arr, int m, int n, stats_of_all_methods STATS);

bool check_read_only(string filename);

bool file_exist(string path);

void random_input(int** array, int m, int n);


struct stats_of_method {
	int compare, change;
};

struct stats_of_all_methods {
	stats_of_method bubble_sort_st;
	stats_of_method selection_sort_st;
	stats_of_method insertion_sort_st;
	stats_of_method shell_sort_st;
	stats_of_method quick_sort_st;
};