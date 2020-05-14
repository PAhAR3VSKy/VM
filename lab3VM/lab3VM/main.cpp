#include <iostream>
#include "Approximation.h"

using namespace std;

int main()
{
	Approximation system;
	setlocale(LC_ALL, "ru");
	int n, choice;
	cout << "�������� ���������� �����: ";
	cin >> n;
	double* x = new double[n];
	double* y = new double[n];
	cout << "������� �����:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "x[" << i << "] = ";
		cin >> x[i];
		cout << "y[" << i << "] = ";
		cin >> y[i];
	}

	system.Print(x, y, n);

	cout << "�������� �����: " << endl
		 << "1) ���������������� ��������� � ����� ��������. " << endl
		 << "2) ���������������� ��������� � ����� �������. " << endl
		 << "3) ������������ ���������. " << endl;
	cin >> choice;

	switch (choice)
	{
	case (1):
		cout << system.Lagrange(x, y, n);
		break;
	case (2):
		cout << system.Newton(x, y, n);
		break;
	case (3):
		cout << system.Smoothing(x, y, n);
		break;
	default:
		cout << "�������� ����!" << endl;
		break;
	}

	return 0;
}