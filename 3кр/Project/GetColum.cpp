#include "GetColum.h"
using namespace std;

vector<int> GetColum(vector<vector<int>> matrix, int colum, int lines) {
	vector<int> tempColum;
	for (int i = 0; i < lines; i++) {
		tempColum.push_back(matrix[i][colum]);
	}
	return tempColum;
}

void SetColum(vector<vector<int>>& matrix, vector<int> colum, int columNumber, int lines) {
	for (int i = 0; i < lines; i++) {
		matrix[i][columNumber] = colum[i];
	}
}
