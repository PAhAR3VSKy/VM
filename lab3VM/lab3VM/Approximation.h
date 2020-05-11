#pragma once
#include <string>

using namespace std;

class Approximation
{
public:
	void Print(double*, double*, int);
	std::string Lagrange(double*, double*, int);
	std::string Newton(double*, double*, int);
};

void Approximation::Print(double* x, double* y, int n)
{
	cout << "X: ";
	for (int i = 0; i < n; i++)
		cout << x[i] << " ";
	cout << endl;
	cout << "Y: ";
	for (int i = 0; i < n; i++)
		cout << y[i] << " ";
	cout << endl;
}

std::string Approximation::Lagrange(double* x, double* y, int n)
{
	int z = 1, L = 0;
	string P;
	for (int i = 0; i < n; i++)
	{
		P += to_string(y[i]) + "*";
		for (int j = 0; j < n; j++)
		{
			if (i != j)
				if (x[j] > 0)
					P += "(x-" + to_string(abs(x[j])) + ")";
				else
					P += "(x+" + to_string(abs(x[j])) + ")";
		}
		P += "/";
		for (int j = 0; j < n; j++)
			if (i != j)
				z *= (x[i] - x[j]);
		P += to_string(z);
		if (i != n - 1)
			P += " + ";
		z = 1;
	}
	return P;
}

inline std::string Approximation::Newton(double* x, double* y, int n)
{
	string term, res = to_string(y[0]);
	double F, den;
	for (int i = 1; i < n; i++) {
		F = 0;
		for (int j = 0; j <= i; j++)
		{
			den = 1;
			for (int k = 0; k <= i; k++)
			{
				if (k != j)
					den *= (x[j] - x[k]);
			}
			F += y[j] / den;
		}
		term = to_string(F);
		for (int k = 0; k < i; k++)
			if(x[k] > 0)
				term += ("(x-" + to_string(abs(x[k])) + ")");
			else
				term += ("(x+" + to_string(abs(x[k])) + ")");
		res += " + " + term;
	}
	return res;
}
