#include "SortedMatrix.h"

vector<vector<int>> SortedMatrix::SortLines(vector<vector<int>> matrix, shared_ptr<ISort> sort) {
	vector<int> temp_column;
	for (int i = 1; i < number_of_colums; i += 2) {
		temp_column = GetColum(matrix, i, number_of_lines);
		sort -> Sort(temp_column, number_of_lines);
		SetColum(matrix, temp_column, i, number_of_lines);
	}
	return matrix;
}

vector<vector<int>> SortedMatrix::SortClumns(vector<vector<int>> matrix, shared_ptr<ISort> sort) {
	for (int i = 0; i < number_of_lines; i += 2) {
		sort -> AbsoluteSort(matrix[i], number_of_colums);
	}
	return matrix;
}

int SortedMatrix::GetNumberOflines() {
	return number_of_lines;
}

int SortedMatrix::GetNumberOfColums() {
	return number_of_colums;
}

vector<vector<int>> SortedMatrix::GetMatrixColums() {
	return matrix_colums;
}

vector<vector<int>> SortedMatrix::GetMatrixLines() {
	return matrix_lines;
}

void SortedMatrix::Show() {
	cout << "Отсортированные столбцы." << endl;
	for (int i = 0; i < number_of_lines; i++) {
		for (int j = 0; j < number_of_colums; j++) {
			cout << matrix_colums[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "\n\n" << endl;
	cout << "Отсортированные строки." << endl;
	for (int i = 0; i < number_of_lines; i++) {
		for (int j = 0; j < number_of_colums; j++) {
			cout << matrix_lines[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "\n\n" << endl;
}
