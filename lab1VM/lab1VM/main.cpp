#include <iostream>
#include <math.h>

using namespace std;

float f(double x)
{
	return (float)(pow(exp(1), x) - 4 * pow(x, 2) - 3 * x);
}

float df(float x) //���������� �������� �����������
{
	return (float)(pow(exp(1), x) - 8 * x - 3);
}

float d2f(float x) // �������� ������ �����������
{
	return (float)(pow(exp(1), x) - 8);
}

int main()
{
	int exit = 0, i = 0;//���������� ��� ������ � �����
	double x0, xn;// ����������� ����������� ��� �����
	double a, b, eps;// ������� ������� � ����������� ��������
	do {
		i = 0;
		cout << "Please input [a;b]\n=>";
		cin >> a >> b; // ������ ������� �������, �� ������� ����� ������ ������
		cout << "\nPlease input epsilon\n=>";
		cin >> eps; // ������ ������ �������� ����������
		if (a > b) // ���� ������������ ��������� ������� �������, ������ �� �������
		{
			x0 = a;
			a = b;
			b = x0;
		}
		if (f(a) * f(b) > 0) // ���� ����� ������� �� ����� ������� ����������, �� ����� ��� �����
			cout << "\nError! No roots in this interval\n";
		else
		{
			if (f(a) * d2f(a) > 0)
				x0 = a;
			else
				x0 = b;
			xn = x0 - f(x0) / df(x0); // ������� ������ �����������
			cout << ++i << "-th iteration = " << xn << "\n";
			while (fabs(x0 - xn) > eps) // ���� �� ��������� ����������� ��������, ����� ���������� ���������
			{
				x0 = xn;
				xn = x0 - f(x0) / df(x0); // ��������������� ������� �������
				cout << ++i << "-th iteration = " << xn << "\n";
			}
			cout << "\nRoot = " << xn; // ����� ������������ �����
		}
		cout << "\nExit?=>";
		cin >> exit;
	} while (exit != 1); // ���� ������������ �� ���� exit = 1

	return 0;

}