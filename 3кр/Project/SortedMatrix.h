#pragma once
#include <iostream>
#include <vector>
#include "ISort.h"
#include "GetColum.h"

using namespace std;

class SortedMatrix {
private:
	int number_of_lines;
	int number_of_colums;

	vector<vector<int>> matrix_colums;
	vector<vector<int>> matrix_lines;
	vector<vector<int>> SortLines(vector<vector<int>> matrix, shared_ptr<ISort> sort);
	vector<vector<int>> SortClumns(vector<vector<int>> matrix, shared_ptr<ISort> sort);

public:
	SortedMatrix(vector<vector <int>> matrix_value, shared_ptr<ISort> sort) {
		number_of_lines = static_cast<int>(matrix_value.size());
		number_of_colums = static_cast<int>(matrix_value[0].size());
		matrix_colums = SortLines(matrix_value, sort);
		matrix_lines = SortClumns(matrix_value, sort);
	}

	int GetNumberOflines();
	int GetNumberOfColums();
	vector<vector<int>> GetMatrixColums();
	vector<vector<int>> GetMatrixLines();
	void Show();
};

