#include "func.h"
#include "module_tests.h"

int** copy_mat(int** array, int m, int n) {
	int** arr = create_mat(m, n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = array[i][j];
		}
	}
	return arr;
}


void module_tests() {
	const int count_of_tests = 33;
	const int r1 = 2, c1 = 2, r2 = 3, c2 = 2, r3 = 2, c3 = 3, r4 = 3, c4 = 3, r5 = 4, c5 = 2;
	system("cls");
	int count = 0, i, j;
	int compare = 0, change = 0;

	int** source_mat1 = create_mat(r1, c1);
	source_mat1[0][0] = -19; source_mat1[0][1] = -64;
	source_mat1[1][0] = -10; source_mat1[1][1] = -30;

	int** source_mat2 = create_mat(r2, c2);
	source_mat2[0][0] = 31;		source_mat2[0][1] = 57;
	source_mat2[1][0] = 4;		source_mat2[1][1] = 10;
	source_mat2[2][0] = 39;		source_mat2[2][1] = 34;

	int** source_mat3 = create_mat(r3, c3);
	source_mat3[0][0] = 45;		source_mat3[0][1] = 59;    source_mat3[0][2] = 53;
	source_mat3[1][0] = -9;		source_mat3[1][1] = 45;		 source_mat3[1][2] = 74;

	int** source_mat4 = create_mat(r4, c4);
	source_mat4[0][0] = 17;		source_mat4[0][1] = 26;		source_mat4[0][2] = 101;
	source_mat4[1][0] = 74;		source_mat4[1][1] = 52;		source_mat4[1][2] = 23;
	source_mat4[2][0] = 42;   source_mat4[2][1] = 12;		source_mat4[2][2] = 11;

	int** source_mat5 = create_mat(r5, c5);
	source_mat5[0][0] = 68;		 source_mat5[0][1] = 6;
	source_mat5[1][0] = 25;    source_mat5[1][1] = 80;
	source_mat5[2][0] = 32;		 source_mat5[2][1] = 78;
	source_mat5[3][0] = -4;		 source_mat5[3][1] = 30;

	int** result_mat1 = copy_mat(source_mat1, r1, c1);
	bubble_sort(result_mat1, r1, c1, compare, change);

	int** expected_mat1 = create_mat(r1, c1);
	expected_mat1[0][0] = -19; expected_mat1[0][1] = -30;
	expected_mat1[1][0] = -10; expected_mat1[1][1] = -64;

	int** expected_mat2 = create_mat(r2, c2);
	expected_mat2[0][0] = 31;		expected_mat2[0][1] = 57;
	expected_mat2[1][0] = 4;		expected_mat2[1][1] = 34;
	expected_mat2[2][0] = 39;		expected_mat2[2][1] = 10;

	int** result_mat2 = copy_mat(source_mat2, r2, c2);
	selection_sort(result_mat2, r2, c2, compare, change);

	int** expected_mat3 = create_mat(r3, c3);
	expected_mat3[0][0] = 45;		expected_mat3[0][1] = 59;   expected_mat3[0][2] = 53;
	expected_mat3[1][0] = -9;		expected_mat3[1][1] = 45;		expected_mat3[1][2] = 74;

	int** result_mat3 = copy_mat(source_mat3, r3, c3);
	insertion_sort(result_mat3, r3, c3, compare, change);
	
	int** expected_mat4 = create_mat(r4, c4);
	expected_mat4[0][0] = 17;		expected_mat4[0][1] = 52;		expected_mat4[0][2] = 101;
	expected_mat4[1][0] = 74;		expected_mat4[1][1] = 26;		expected_mat4[1][2] = 23;
	expected_mat4[2][0] = 42;   expected_mat4[2][1] = 12;	  expected_mat4[2][2] = 11;

	int** result_mat4 = copy_mat(source_mat4, r4, c4);
	shell_sort(result_mat4, r4, c4, compare, change);

	int** expected_mat5 = create_mat(r5, c5);
	expected_mat5[0][0] = 68;		 expected_mat5[0][1] = 80;
	expected_mat5[1][0] = 25;    expected_mat5[1][1] = 78;
	expected_mat5[2][0] = 32;		 expected_mat5[2][1] = 30;
	expected_mat5[3][0] = -4;	 	 expected_mat5[3][1] = 6;

	int** result_mat5 = copy_mat(source_mat5, r5, c5);
	quick_sort(result_mat5, r5, c5, compare, change);

	for (i = 0; i < r1; i++) {
		for (j = 0; j < c1; j++) {
			if (expected_mat1[i][j] == result_mat1[i][j]) {
				count++;
			}
			else {
				cout << "В массиве №1" << endl;
				cout << "Ожидался элемент " << "U" << "[" << i << "]" << "," << "[" << j << "] = " << expected_mat1[i][j] << endl;
				cout << "А получен элемент " << "U" << "[" << i << "]" << "," << "[" << j << "] = " << result_mat1[i][j] << endl;
			}
		}
	}

	for (i = 0; i < r2; i++) {
		for (j = 0; j < c2; j++) {
			if (expected_mat2[i][j] == result_mat2[i][j]) {
				count++;
			}
			else {
				cout << "В массиве №2" << endl;
				cout << "Ожидался элемент " << "U" << "[" << i << "]" << "," << "[" << j << "] = " << expected_mat2[i][j] << endl;
				cout << "А получен элемент " << "U" << "[" << i << "]" << "," << "[" << j << "] = " << result_mat2[i][j] << endl;
			}
		}
	}

	for (i = 0; i < r3; i++) {
		for (j = 0; j < c3; j++) {
			if (expected_mat3[i][j] == result_mat3[i][j]) {
				count++;
			}
			else {
				cout << "В массиве №4" << endl;
				cout << "Ожидался элемент " << "U" << "[" << i << "]" << "," << "[" << j << "] = " << expected_mat3[i][j] << endl;
				cout << "А получен элемент " << "U" << "[" << i << "]" << "," << "[" << j << "] = " << result_mat3[i][j] << endl;
			}
		}
	}

	for (i = 0; i < r4; i++) {
		for (j = 0; j < c4; j++) {
			if (expected_mat4[i][j] == result_mat4[i][j]) {
				count++;
			}
			else {
				cout << "В массиве №4" << endl;
				cout << "Ожидался элемент " << "U" << "[" << i << "]" << "," << "[" << j << "] = " << expected_mat4[i][j] << endl;
				cout << "А получен элемент " << "U" << "[" << i << "]" << "," << "[" << j << "] = " << result_mat4[i][j] << endl;
			}
		}
	}

	for (i = 0; i < r5; i++) {
		for (j = 0; j < c5; j++) {
			if (expected_mat5[i][j] == result_mat5[i][j]) {
				count++;
			}
			else {
				cout << "В массиве №5" << endl;
				cout << "Ожидался элемент " << "U" << "[" << i << "]" << "," << "[" << j << "] = " << expected_mat5[i][j] << endl;
				cout << "А получен элемент " << "U" << "[" << i << "]" << "," << "[" << j << "] = " << result_mat5[i][j] << endl;
			}
		}
	}


	if (count == count_of_tests) {
		cout << "Тест успешно пройден!" << endl;
	}
	else {
		cout << "Тест провален!" << endl;
	}

	for (i = 0; i < r1; i++) {
		delete[] source_mat1[i];
		delete[] result_mat1[i];
		delete[] expected_mat1[i];
	}
	for (i = 0; i < r2; i++) {
		delete[] source_mat2[i];
		delete[] result_mat2[i];
		delete[] expected_mat2[i];
	}

	for (i = 0; i < r3; i++) {
		delete[] source_mat3[i];
		delete[] result_mat3[i];
		delete[] expected_mat3[i];
	}

	for (i = 0; i < r4; i++) {
		delete[] source_mat4[i];
		delete[] result_mat4[i];
		delete[] expected_mat4[i];
	}

	for (i = 0; i < r5; i++) {
		delete[] source_mat5[i];
		delete[] result_mat5[i];
		delete[] expected_mat5[i];
	}
	delete[] source_mat1;
	delete[] source_mat2;
	delete[] source_mat3;
	delete[] source_mat4;
	delete[] source_mat5;
	delete[] expected_mat1;
	delete[] expected_mat2;
	delete[] expected_mat3;
	delete[] expected_mat4;
	delete[] expected_mat5;
	delete[] result_mat1;
	delete[] result_mat2;
	delete[] result_mat3;
	delete[] result_mat4;
	delete[] result_mat5;
}