#include "InputCheck.h"
using namespace std;

int InputCheck::value = 0;
string InputCheck::value_input = "";

int InputCheck::CheckIntValue() {
	while (true) {
		cout << "Ввод: ";
		getline(cin, value_input);
		try {
			value = stoi(value_input);
			return value;
		}
		catch (exception&) {
			cout << "Ошибка. Попробуйте снова." << endl;
		}

	}
}

int InputCheck::CheckIntValuePlus() {
	while (true) {
		cout << "Ввод: ";
		getline(cin, value_input);
		try {
			value = stoi(value_input);

			if (value <= 0) {
				throw exception("NegativeInt");
			}
			else {
				return value;
			}
		}
		catch (exception&) {
			cout << "Ошибка. Попробуйте снова." << endl;
		}

	}
}

int InputCheck::CheckMenu(int items) {
	while (true) {
		cout << "ENTER : ";
		getline(cin, value_input);
		try {
			value = stoi(value_input);
			if (value <= items && value >= 1) {
				return value;
			}
			else {
				throw value;
			}
		}
		catch (exception&) {
			cout << "Пункт меню не существует. Повторите ввод." << endl;
		}
		catch (int ex_value) {
			cout << ex_value << "Пункт меню не существует. Повторите ввод." << endl;
		}
	}
}

int InputCheck::CheckLineInt(ifstream& file) {
	string temp_v = "";
	int temp_i = 0;
	try {
		getline(file, temp_v);
	}
	catch (const exception&) {
		cout << "Недостаточно данных в файле или неправильная форма заполнения файла." << endl;
		throw exception("Wrong data");
	}
	try {
		temp_i = stoi(temp_v);
		return temp_i;
	}
	catch (const exception&) {
		cout << "Некорректные данные." << endl;
		throw exception("Wrong data");
	}
}

int InputCheck::CheckLineUnsInt(ifstream& file) {
	string temp_v = "";
	int temp_i = 0;
	try {
		getline(file, temp_v);
	}
	catch (const exception&) {
		cout << "Недостаточно данных в файле или неправильная форма заполнения файла. " << endl;
		throw exception("Wrong data");
	}
	try {
		temp_i = stoi(temp_v);
		if (temp_i < 0) {
			throw  exception("Wrong data");
		}
		else {
			return temp_i;
		}
	}
	catch (const exception&) {
		cout << "Некорректные данные." << endl;
		throw exception("Wrong data");
	}
}

