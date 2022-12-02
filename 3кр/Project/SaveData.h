#pragma once
#include <vector>
#include <memory>						/// ??? кто 
#include <fstream>

#include "InputCheck.h"
#include "SortedMatrix.h"
#include "GetFileName.h"
#include "ISort.h"

using namespace std;

void SaveData(vector<shared_ptr<ISort>>& sorts_case, vector <shared_ptr<SortedMatrix>> sorts_matrix);


