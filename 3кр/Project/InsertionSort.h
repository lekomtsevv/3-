#pragma once
#include "ISort.h"

class InsertionSort : public  ISort {
public:
	void PrintCounters() override;

	void Sort(vector<int>& arr, int size) override;

	void AbsoluteSort(vector<int>& arr, int size) override;
};

