#include "MatrixInput.h"
#include <time.h>

int MatrixInput(vector<vector<int>>& matrix) {
	cout << "[1] - Заполненить матрицу вручную " << endl;
	cout << "[2] - Заполнить матрицу случайными значениями " << endl;
	cout << "[3] - Заполнить матрицу из файла " << endl;

	InputMode mode = static_cast<InputMode>(InputCheck::CheckMenu(3));
	switch (mode) {
	case InputMode::console_by_hand:
		matrix = ConsoleInput();
		break;

	case InputMode::console_random:
		matrix = RandomInput();
		break;

	case InputMode::io_file:
		matrix = FileInput();
		break;
	}
	return static_cast<int>(mode);
}

vector<vector<int>> ConsoleInput() {
		cout << "Введите количество строк " << endl;
		int lines = InputCheck::CheckIntValuePlus();

		cout << "Введите количество столбцов " << endl;
		int colums = InputCheck::CheckIntValuePlus();

		vector<vector<int>> matrix;
		for (int i = 0; i < lines; i++) {
			matrix.push_back(vector<int>{});
			for (int j = 0; j < colums; j++) {
				cout << "Ввод [" << i + 1 << "] [" << j + 1 << "] ." << endl;
				matrix[i].push_back(InputCheck::CheckIntValue());
			}
		}
		return matrix;
}

vector<vector<int>> FileInput() {
	string name = "";
	ifstream file;
	vector<vector<int>> matrix;
	file.exceptions(ifstream::badbit | ifstream::failbit);
	while (true) {
		try {
			name = GetFileName(input);
			file.open(name);
		}
		catch (const exception&) {
			cout << "Ошибка доступа." << endl;
			continue;
		}
		try {
			int lines = (InputCheck::CheckLineUnsInt(file));
			int colums = (InputCheck::CheckLineUnsInt(file));
			if (lines <= 0 || colums <= 0)

			for (int i = 0; i < lines; i++) {
				matrix.push_back(vector<int>{});			//???????????? почему фигурные скобки пустые . . 
				for (int j = 0; j < colums; j++) {
					matrix[i].push_back( InputCheck::CheckLineInt(file));
				}
			}
		}
		catch (exception&) {
			file.close();
			continue;
		}
		cin.clear();
		cin.ignore();
		file.close();
		return matrix;
	}
}

vector<vector<int>> RandomInput() {
	srand(static_cast<unsigned>(time(nullptr)));
	cout << "Введите строки." << endl;;
	int lines = InputCheck::CheckIntValuePlus();
	
	cout << "Введите столбцы." << endl;;
	int colums = InputCheck::CheckIntValuePlus();

	vector<vector<int>> matrix;
	for (int i = 0; i < lines; i++) {
		matrix.push_back(vector<int>{});
		for (int j = 0; j < colums; j++) {
			matrix[i].push_back(rand() % 101 - 50);
		}
	}
	return matrix;
}

