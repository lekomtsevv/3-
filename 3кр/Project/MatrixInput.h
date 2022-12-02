#pragma once
#include "SortedMatrix.h"
#include "InputCheck.h"
#include "GetFileName.h"
using namespace std;

int MatrixInput(vector<vector<int>>& matrix);

vector<vector<int>> ConsoleInput();
vector<vector<int>> FileInput();
vector<vector<int>> RandomInput();