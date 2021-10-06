#include"Header.h"
#include"Header.cpp"

int checkEnter(int vl, istream& cin) {//проверка корректности ввода
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	while (cin.fail() || vl < 0) {
		cin.clear();
		cin.ignore(64, '\n');
		SetConsoleTextAttribute(handle, 4);
		cout << "Retry: ";
		SetConsoleTextAttribute(handle, 7);
		cin >> vl;
	}
	return vl;
}

int main() {
	int menu = 1, menu1 = 1;
	while (menu) {
		int v = 1;
		cout << "1.Make insertion sort(int)." << endl;
		cout << "2.Make insertion sort(double)." << endl;
		cout << "3.Create int array" << endl;
		cout << "4.Create double array" << endl;
		cout << "0.Exit" << endl;
		cout << "You entered: ";
		cin >> v;
		v = checkEnter(v, cin);
		switch (v){
		case 1:
		{
			const int a = 10 + (rand() % 100) / 10;
			int* buf = new int[a];
			SetMas(buf, a);
			SortMas(buf, a);
			PrintMas(buf, a);
			delete[] buf;
			break;
		}
		case 2:
		{
			const int a = 10 + (rand() % 10);
			double* buf = new double[a];
			SetMas(buf, a);
			SortMas(buf, a);
			PrintMas(buf, a);
			delete[] buf;
			break;
		}
		case 3:
		{
			Mass<int> arr;
			cin >> arr;
			while (menu1) {
				int v1 = 1;
				cout << "1.Print element #i." << endl;
				cout << "2.Mas[all] < b." << endl;
				cout << "3.Mas[all] > b." << endl;
				cout << "0.Exit" << endl;
				cout << "You entered: ";
				cin >> v1;
				v1 = checkEnter(v1, cin);
				switch (v1) {
				case 1: 
				{
					int num1, num2;
					cout << "Enter element num: ";
					cin >> num1;
					num1 = checkEnter(num1, cin);
					try {
						if (num1 > arr.GetSize()) throw 1;
					}
					catch (int a) {
						cout << "Error " << a << endl;
						break;
					}
					cout << arr[num1 - 1] << endl;
					break; 
				}
				case 2:
				{
					int b;
					cout << "Enter b:";
					cin >> b;
					b = checkEnter(b, cin);
					arr < b;
					break;
				}
				case 3:
				{
					int b;
					cout << "Enter b:";
					cin >> b;
					b = checkEnter(b, cin);
					arr > b;
					break;
				}
				case 0:
					menu1 = 0;
					break;
				default:
				{
					cout << "Incorrectly number!";
					break;
				}
				}
			}
			break;
		}
		case 4:
		{
			Mass<double> arr;
			cin >> arr;
			while (menu1) {
				int v1 = 1;
				cout << "1.Print element #i." << endl;
				cout << "2.Mas[all] < b." << endl;
				cout << "3.Mas[all] > b." << endl;
				cout << "0.Exit" << endl;
				cout << "You entered: ";
				cin >> v1;
				v1 = checkEnter(v1, cin);
				switch (v1) {
				case 1:
				{
					int num1, num2;
					cout << "Enter element num: ";
					cin >> num1;
					num1 = checkEnter(num1, cin);
					try {
						if (num1 > arr.GetSize()) throw 1;
					}
					catch (int a) {
						cout << "Error " << a << endl;
						break;
					}
					cout << arr[num1 - 1] << endl;
					break;
				}
				case 2:
				{
					double b;
					cout << "Enter b:";
					cin >> b;
					b = checkEnter(b, cin);
					arr < b;
					break;
				}
				case 3:
				{
					double b;
					cout << "Enter b:";
					cin >> b;
					b = checkEnter(b, cin);
					arr > b;
					break;
				}
				case 0:
					menu1 = 0;
					break;
				default:
				{
					cout << "Incorrectly number!";
					break;
				}
				}
			}
			break;
		}
		case 0:
		{
			menu = 0;
			break;
		}
		default:
		{
			cout << "Incorrectly number!" << endl;
			break;
		}
		}
	}
}
