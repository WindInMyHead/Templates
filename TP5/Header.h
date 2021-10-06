#pragma once
#include <iostream>
#include<iomanip>
#include<Windows.h>

using namespace std;

template<typename T>
void PrintMas(T& a, const int size);

template<typename T>
void SetMas(T& a, const int size);

template<typename T>
void SortMas(T& a, const int size);

template<class T>
class Mass {
    T* head;
    int size;
public:
    Mass() {
        size = 0;
    }
    void setHead(T* head);
    void Add(T value);

	friend ostream& operator <<(ostream& out, Mass<T>& M) {
		for (int i = 0; i < (M.size); i++) {
			out << M.head[i] << " ";
		}
		cout << endl;
		return out;
	}

	friend istream& operator>>(istream& in, Mass<T>& M) {
		int cnt = 0;
		cout << "Enter size: ";
		cin >> cnt;
		T* head = new T[cnt];
		M.setHead(head);
		for (int i = 0; i < cnt; i++) {
			T value;
			cout << "Enter " << i + 1 << " value ->";
			cin >> value;
			M.Add(value);
		}
		return in;
	}

    T operator[] (int x);

	friend bool operator<(Mass<T> m, T n) {
		for (int i = 0; i < m.size; ) {
			if (m[i] < n) cout << m[i] << "<" << n << endl;
			else cout << m[i] << ">" << n << endl;;
			i++;
		}
		return TRUE;
	}

	template<class T>
    friend bool operator>(Mass m, T n) {
		for (int i = 0; i < m.size; ) {
			if (m[i] > n) cout << m[i] << ">" << n << endl;
			else cout << m[i] << "<" << n << endl;;
			i++;
		}
		return TRUE;
	}
	int GetSize();
};
