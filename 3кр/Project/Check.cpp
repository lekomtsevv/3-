#include "Check.h"

int CheckMenu(int items) {
	string value_input;
	int value;

	while (true) {
		cout << "Ввод: ";
		getline(cin, value_input);
		cout << endl;
		try {
			value = stoi(value_input);
			if (value <= items && value >= 1)
				return value;
			else
				throw value;
		}
		catch (exception&) {
			cout << "Не существующий пункт меню. Повторите ввод " << endl;
		}
		catch (int ex_value) {
			cout << ex_value << "Не существующий пункт меню. Повторите ввод." << endl;
		}
	}
}