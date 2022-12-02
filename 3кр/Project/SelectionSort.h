#pragma once
#include "ISort.h"

using namespace std;

class SelectionSort : public ISort {
public:
	void PrintCounters() override;						//оверрайд по идее можно не писать же, но я напишу потому что так надежнее

	void Sort(vector<int>& arr, int size) override;

	void AbsoluteSort(vector<int>& arr, int size) override;
};

