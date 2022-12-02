#include "InitialMatrixFileOutput.h"
using namespace std;

void InitialMatrixFileOutput(vector<vector<int>> matrix) {
	const int this_file = 1;
	string name;
	ofstream  file;
	file.exceptions(ofstream::badbit | ofstream::failbit);

	while (true) {
		try {
			name = GetFileName(output);
			file.open(name);
		}
		catch (const exception&) {
			cout << "Ошибка доступа." << endl;
			continue;
		}
		break;
	}

	int number_of_lines = static_cast<int> (matrix.size());
	int number_of_colums = static_cast<int>(matrix[0].size());

	file << number_of_lines << endl;
	file << number_of_colums << endl;
	for (int i = 0; i < number_of_lines; i++) {
		for (int j = 0; j < number_of_colums; j++) {
			file << matrix[i][j] << endl;
		}
	}
	file.close();
}

