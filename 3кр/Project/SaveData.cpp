#include "SaveData.h"

void SaveData(vector<shared_ptr<ISort>>& sorts_case, vector<shared_ptr<SortedMatrix>> sorts_matrix) {
	const int this_file = 1;
	string name;
	ofstream file;
	file.exceptions(ofstream::badbit | ofstream::failbit);

	while (true) {
		try {
			name = GetFileName(output);
			file.open(name);
		}
		catch (const exception&) {
			cout << "������ �������." << endl;
			continue;
		}
		break;
	}
	vector<vector<int>> matrix_colums = sorts_matrix[0]->GetMatrixColums();
	vector<vector<int>> matrix_lines = sorts_matrix[0]->GetMatrixLines();

	file << string(15,' ') << "���������" << "\t" << "���������" << endl;
	for (int i = 0; i < sorts_case.size(); i++) {
		string temp_name = typeid(*sorts_case[i]).name();
		temp_name.erase(0, 6);
		file << temp_name << string(15 - temp_name.size(),' ') << sorts_case[i]->GetComprasionCounter() << "\t\t\t" << sorts_case[i]->GetSwapCountrt() << endl;
	}

	file << "\n��������������� ������ �������." << endl;
	for (int i = 0; i < sorts_matrix[0]->GetNumberOflines(); i++) {
		for (int j = 0; j < sorts_matrix[0]->GetNumberOfColums(); j++) {
			file << matrix_colums[i][j] << "\t";
		}
		file << endl;
	}

	file << "��������������� �������� ������ " << endl;
	for (int i = 0; i < sorts_matrix[0]->GetNumberOflines(); i++) {
		for (int j = 0; j < sorts_matrix[0]->GetNumberOfColums(); j++) {
			file << matrix_colums[i][j] << "\t";
		}
		file << endl;
	}
	file.close();
}
