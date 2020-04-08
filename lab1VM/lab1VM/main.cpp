#include <iostream>
#include <math.h>

using namespace std;

class NonLinearEquations
{
private:
	double eps;
	double f(double);
	double df(double);
	double d2f(double);
	double equivalent(double);
public:
	double NewtonMethod(double, double);
	double IterationMethod(double, double);
	double secantMethod(double, double);
	NonLinearEquations(double);
};

NonLinearEquations::NonLinearEquations( double eps)
{
	this->eps = eps;
}

double NonLinearEquations::f(double x)
{
	return (exp(x) - 4 * pow(x, 2) - 3 * x);
}

double NonLinearEquations::df(double x)
{
	return (exp(x) - 8 * x - 3);
}

double NonLinearEquations::d2f(double x)
{
	return (exp(x) - 8);
}
double NonLinearEquations::equivalent(double x)
{
	return sqrt((exp(x) - 3 * x) / 4);
	//return ((exp(x) - 4 * pow(x, 2)) / 3);
}

double NonLinearEquations::NewtonMethod(double a, double b)
{
	
	double x0, 
		x;
	int i = 0;
	if (f(a) > 0 && d2f(a) > 0 || f(a) < 0 && d2f(a) < 0)
	{
		x0 = a;
	}
	else if (f(b) > 0 && d2f(b) > 0 || f(b) < 0 && d2f(b) < 0)
	{
		x0 = b;
	}
	else
	{
		cout << " нет приблизительного значения " << endl;
		return -1;
	}
	x = x0;
	do
	{
		i++;
		x0 = x;
		x = x0 - f(x0) / df(x0);
	} while (abs(x-x0)>eps);
	cout << "Количество итераций: " << i << endl;
	return x;
}

double NonLinearEquations::IterationMethod(double a, double b)
{
	double x1 = (a + b) / 2;
	double x0 = x1;
	
	int i = 0;
	do
	{
		x1 = equivalent(x0);
		if (fabs(x1 - x0) < eps) break;
		x0 = x1;
		i++;
	} while (i < 20000);
	cout << "Количество итераций: " << i << endl;
	return x1;
}

double NonLinearEquations::secantMethod(double a, double b)
{
	double res = b,
		fx,
		f0x;
	int i = 0;
	do
	{
		i++;
		fx = f(res);
		f0x = f(a);
		res = res - fx / (fx - f0x) * (res - a);
	} while (abs(fx) > eps);
	cout << "Количество итераций: " << i << endl;
	return res;
}



int main()
{
	setlocale(LC_ALL, "ru");

	double eps;
	int count;
	cout << "eps: " << endl;
	cin >> eps;

	NonLinearEquations equations(eps);

	while (1)
	{
		cout << "1. Метод Ньютона"
			<< endl << "2. Метод простых итераций"
			<< endl << "3. Метод секущих" << endl;
		cin >> count;
		switch (count)
		{
		case 1:
			cout << equations.NewtonMethod(-1, 0) << endl;
			cout << equations.NewtonMethod(0, 1) << endl;
			cout << equations.NewtonMethod(4, 5) << endl;
			break;
		case 2:
			cout << equations.IterationMethod(-1, 0) << endl;
			cout << equations.IterationMethod(0, 1) << endl;
			cout << equations.IterationMethod(4, 5) << endl;
			break;
		case 3:
			cout << equations.secantMethod(-1, 0) << endl;
			cout << equations.secantMethod(0, 1) << endl;
			cout << equations.secantMethod(4, 5) << endl;
			break;
		}
	}
}