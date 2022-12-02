#pragma once
#include "ISort.h"
using namespace std;

class QuickSort : public ISort {
public:
	void PrintCounters() override;

	void Sort(vector<int>& arr, int size) override;

	void AbsoluteSort(vector<int>& arr, int size) override;

	void Quicksort(vector<int>& arr, int start, int end);

	void AbsoluteQuicksort(vector<int>& arr, int start, int end);

	int Partition(vector<int>& arr, int start, int end);

	int AbsolutePartition(vector<int>& arr, int start, int end);
};

