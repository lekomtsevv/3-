#include "SelectionSort.h"

void SelectionSort::PrintCounters() {
	cout << "Сортировка выбором " << endl;
	ISort::PrintCounters();
}

void SelectionSort::AbsoluteSort(vector<int>& arr, int size) {
	for (int i = 0; i < size - 1; i++) {
		int tmp = arr[i];
		int tmpid = i;
		for (int j = i + 1; j < size; j++) {
			comparison_counter++;
			if (abs(arr[tmpid]) >  abs(arr[j])) {
				tmp = arr[j];
				tmpid = j;
			}
		}
		if (tmpid != i) {
			swap_counter++;
			swap(arr[i], arr[tmpid]);
		}
	}
}

void SelectionSort::Sort(vector<int>& arr, int size) {
	for (int i = 0; i < size - 1; i++) {
		int tmp = arr[i];
		int tmpid = i;
		for (int j = i + 1; j < size; j++) {
			comparison_counter++;
			if ((arr[tmpid]) > arr[j]) {
				tmp = arr[j];
				tmpid = j;
			}
		}
		if (tmpid != i) {
			swap_counter++;
			swap(arr[i], arr[tmpid]);
		}
	}
}
