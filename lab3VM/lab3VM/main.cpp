#include <iostream>
#include "Approximation.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	int n;
	cout << "�������� ���������� �����: ";
	cin >> n;
	int* x = new int[n];
	int* y = new int[n];
	cout << "������� �����:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "x[" << i << "] = ";
		cin >> x[i];
		cout << "y[" << i << "] = ";
		cin >> y[i];
	}
	return 0;
}