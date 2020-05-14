#pragma once
#include <string>

using namespace std;

class Approximation
{
public:
	void Print(double*, double*, int);
	std::string Lagrange(double*, double*, int);
	std::string Newton(double*, double*, int);
	std::string Smoothing(double*, double*, int);
private:
	double* Matrix(double*, double*, int, int);
	double* Gauss(double**, double*, int);
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

inline std::string Approximation::Smoothing(double* x, double* y, int n)
{
	int degree;
	string result;
	cout << "Введите степень многочлена: ";
	cin >> degree;
	double* a = new double[degree];
	a = Matrix(x, y, n, degree);

	for (int i = degree; i >= 0; i--)
	{
		if (i != 0)
			result += to_string(a[i]) + "x^" + to_string(i) + "+";
		else
			result += to_string(a[i]);
	}

	delete[] a;
	return result;
}

inline double* Approximation::Matrix(double* x, double* y, int n, int k)
{
	double* b = new double[k + 1];
	double* c = new double[2 * k + 1];
	double** A = new double* [k + 1];
	for (int i = 0; i < k + 1; i++)
		A[i] = new double[k + 1];

	for (int i = 0; i < 2 * k + 1; i++)	//Подсчет суммы элиментов значений х
	{
		c[i] = 0;
		for (int j = 0; j < n; j++)
			c[i] += pow(x[j], i);
	}

	for (int i = 0; i < k + 1; i++) //Подсчет суммы элементов f
	{
		b[i] = 0;
		for (int j = 0; j < n; j++)
			b[i] += pow(x[j], i) * y[j];
	}

	for (size_t i = 0; i < k+1; i++) //Построение матрицы А
		for (int j = 0; j < k + 1; j++)
			A[i][j] = c[i + j];

	return Gauss(A, b, k + 1);
}

void sysout(double** a, double* y, int n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[i][j] << " ";
		cout << " = " << y[i] << endl;
	}
	return;
}

inline double* Approximation::Gauss(double** A, double* b, int n)
{
	double* x = new double[n],
			max;
	int k = 0,
		index;
	const double eps = 0.00001;

	sysout(A, b, n);

	while (k < n)
	{
		max = abs(A[k][k]);
		index = k;

		for (int i = k + 1; i < n; i++) // Поиск строки с максимальным элементом
		{
			if (abs(A[i][k]) > max)
			{
				max = abs(A[i][k]);
				index = i;
			}
		}
		// Перестановка строк
		if (max < eps)//нет ненулевых диагональных элементов
		{
			cout << "Решение получить невозможно из-за нулевого столбца ";
			cout << index << endl;
			return 0;
		}

		for (int i = 0; i < n; i++)
		{
			double temp = A[k][i];
			A[k][i] = A[index][i];
			A[index][i] = temp;
		}

		double temp = b[k];
		b[k] = b[index];
		b[index] = temp;

		//Нормализация уравнений
		for (int i = k; i < n; i++)
		{
			double temp = A[i][k];

			if (abs(temp) < eps) 
				continue;	//для нулевого коэффициента

			for (int j = 0; j < n; j++)
				A[i][j] = A[i][j] / temp;

			b[i] = b[i] / temp;

			if (i == k)  
				continue;	// уравнение не вычитать само из себя

			for (int j = 0; j < n; j++)
				A[i][j] = A[i][j] - A[k][j];

			b[i] = b[i] - b[k];
		}
		k++;
	}
	//Обратная подстановка
	for (k = n - 1; k >= 0; k--)
	{
		x[k] = b[k];
		for (int i = 0; i < k; i++)
			b[i] = b[i] - A[i][k] * x[k];
	}

	return x;
}


