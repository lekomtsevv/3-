#include "ISort.h"
#include "Names.h"
using namespace std;

int ISort::GetComprasionCounter() {
	return comparison_counter;
}

int ISort::GetSwapCountrt() {
	return swap_counter;
}

void ISort::PrintCounters() {
	cout << "Сравнения" << "\t\t" << "изменения" << endl;
	cout << "\t" << comparison_counter << "\t\t" << swap_counter << endl;
}


