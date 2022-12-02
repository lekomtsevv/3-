#include <windows.h>
#include "ISort.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "QuickSort.h"
#include "ShellSort.h"
#include "SelectionSort.h"
#include "MatrixInput.h"
#include "InitialMatrixFileOutput.h"
#include "SaveData.h"

enum class Answer {
	Yes = 1,
	No
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	int const sorts_count = 5;
	cout << "����������� ������ �4, ������� 4, ������� ��������� ������ 415 ��������� �.�." << std::endl
		<< "���������� ����������� ������ �������� ������ �� ����������� ���������� �������, ������ ������ ������� �� �����������." << std::endl
		<< "��� ����� ���������� ������������ ������: �����������, ������, �������, ����� � ������� ����������." << std::endl
		<< "������� �� ����� ���������������(���� ���) � �������������(��� ������� �� �������) ������� ������." << std::endl
		<< "��������� ������������� ������� ������������� �������, � ������� ���������� ������� ����� ��������� � ������������ ���������� � ������ ������ ����������." << std::endl;
		
	while (true) {
		vector <shared_ptr<ISort>> sorts_case;
		vector <shared_ptr<SortedMatrix>> sorts_matrix;
		vector <vector<int>> matrix;

		sorts_case.emplace_back(make_shared<BubbleSort>());
		sorts_case.emplace_back(make_shared<QuickSort>());
		sorts_case.emplace_back(make_shared<SelectionSort>());
		sorts_case.emplace_back(make_shared<ShellSort>());
		sorts_case.emplace_back(make_shared<InsertionSort>());
		
		InputMode mode = static_cast<InputMode> (MatrixInput(matrix));

		for (int i = 0; i < static_cast<int>(matrix.size()); i++) {
			for (int j = 0; j < static_cast<int>(matrix[0].size()); j++) {
				cout << matrix[i][j] << "\t";
			}
			cout << endl;
		}

		for (int i = 0; i < sorts_count; i++) {
			sorts_matrix.emplace_back(make_shared<SortedMatrix>(matrix, sorts_case[i]));
			sorts_case[i]->PrintCounters();
			sorts_matrix[i]->Show();
		}
		
		if (mode == InputMode::console_by_hand || mode == InputMode::console_random) {
			cout << "�� ������ ��������� �������� ������ ������� � ����?" << endl;
			cout << "1 - ��\n2 - ���" << endl;
			Answer initial_choice = static_cast<Answer> (InputCheck::CheckMenu(2));
			if (initial_choice == Answer::Yes)
				InitialMatrixFileOutput(matrix);
		}
		cout << "�� ������ ��������� ������� ��������� ���������� � ����?" << endl;
		cout << "1 - ��\n2 - ���" << endl;
		Answer data_choice = static_cast<Answer> (InputCheck::CheckMenu(2));
		if(data_choice == Answer::Yes)
			SaveData(sorts_case, sorts_matrix);

		cout << "����������?" << endl;
		cout << "1 - ��\n2 - ���" << endl;
		Answer continue_choice = static_cast<Answer> (InputCheck::CheckMenu(2));
		if (continue_choice == Answer::No) return 0;		
		system("cls");
	}
}