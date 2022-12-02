#include "InsertionSort.h"
using namespace std;

void InsertionSort::PrintCounters() {
	cout << "Сортировка вставками." << endl;
	ISort::PrintCounters();
}

void InsertionSort::AbsoluteSort(vector<int>& arr, int size) {
    for (int k = 1; k < size; k++) {
        int temp = arr[k];
        int j = k - 1;
        comparison_counter++;
        while (j >= 0 && abs(temp) < abs(arr[j])) {
            comparison_counter++;
            swap_counter++;
            arr[j + 1] = arr[j];
            j--;
			if (j == 0) {
				comparison_counter--;
			}
        }
       arr[j + 1] = temp;
    }
}

void InsertionSort::Sort(vector<int>& arr, int size) {
	for (int k = 1; k < size; k++) {
		int temp = arr[k];
		int j = k - 1;
		comparison_counter++;
		while (j >= 0 && temp < arr[j]) {
			comparison_counter++;
			swap_counter++;
			arr[j + 1] = arr[j];
			j--;
			if (j == 0) {
				comparison_counter--;
			}		
		}
		arr[j + 1] = temp;
	}
}
