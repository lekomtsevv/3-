#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

class InputCheck {
private:
	static string value_input;
	static int value;
public:
	static int CheckIntValue();
	static int CheckIntValuePlus();
	static int CheckMenu(int items);
	static int CheckLineInt(ifstream& file);
	static int CheckLineUnsInt(ifstream& file);
};

