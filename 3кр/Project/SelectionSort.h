#pragma once
#include "ISort.h"

using namespace std;

class SelectionSort : public ISort {
public:
	void PrintCounters() override;						//�������� �� ���� ����� �� ������ ��, �� � ������ ������ ��� ��� ��������

	void Sort(vector<int>& arr, int size) override;

	void AbsoluteSort(vector<int>& arr, int size) override;
};

