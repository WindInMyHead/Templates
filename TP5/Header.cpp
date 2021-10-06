#include "Header.h"
//==================
template<typename T>
void PrintMas(T& a, const int size)
{
	for (int i = 0; i < size; i++) {
		cout.width(10);
		cout << fixed << setprecision(2) << a[i];
		if ((i + 1) % 5 == 0) cout << endl;
	}
	cout << endl << endl;
}
//==================
template<typename T>
void SetMas(T& a, const int size) {
	srand(time(0));
	for (int i = 0; i < size; i++) {
		a[i] = (1 + rand() % 20000) / 3.5;
	}
	PrintMas(a, size);
}
//==================
template<typename T>
void SortMas(T& a, const int size) {
	for (int i = 1; i < size; i++) {
		for (int j = i; j > 0 && a[j - 1] > a[j]; j--) {
			swap(a[j - 1], a[j]);
		}
	}
}
//==================
template<class T>
void Mass<T>::setHead(T* head) {
	this->head = head;
}
//==================
template<class T>
void Mass<T>::Add(T value) {
	head[size] = value;
	size++;
}
//==================
template<class T>
T Mass<T>::operator[](int x){
	return this->head[x];
}
//==================
template<class T>
int Mass<T>::GetSize()
{
	return this->size;
}