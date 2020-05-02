#include <iostream>
#define SIZE 3

using namespace std;

class SLAU
{
public:
	double* Gauss_Method(double **, double *);
	double Simple_Iteration();
};

double* SLAU::Gauss_Method(double **A, double *b)
{
	int k = 0,
		index = 0;
	double max,
		   *x = new double[SIZE];

	max = abs(A[0][0]);
	while (k < SIZE)
	{
		for (int i = 0; i < SIZE; i++)	// Поиск строки с максимальным элементом
		{
			for (int j = 0; j < SIZE; j++)
			{
				if (abs(A[i][j]) > max)
				{
					max = abs(A[i][j]);
					index = i;
				}
			}
		}
		// Перестановка строк
		if (max < 0)	// нет ненулевых диагональных элементов
		{
			cout << "Решение получить невозможно из-за нулевого столбца ";
			cout << index << " матрицы A" << endl;
			return 0;
		}
		for (int i = 0; i < SIZE; i++)
		{
			double temp = A[k][i];
			A[k][i] = A[index][i];
			A[index][i] = temp;
		}
		double temp = b[k];
		b[k] = b[index];
		b[index] = temp;
		// Нормализация уравнений
		for (int i = k; i < SIZE; i++)
		{
			double temp = A[i][k];
			if (abs(temp) < 0) continue; // для нулевого коэффициента пропустить
			for (int j = 0; j < SIZE; j++)
				A[i][j] = A[i][j] / temp;
			b[i] = b[i] / temp;
			if (i == k)  continue; // уравнение не вычитать само из себя
			for (int j = 0; j < SIZE; j++)
				A[i][j] = A[i][j] - A[k][j];
			b[i] = b[i] - b[k];
		}
		k++;
	}
	// обратная подстановка
	for (k = SIZE - 1; k >= 0; k--)
	{
		x[k] = b[k];
		for (int i = 0; i < k; i++)
			b[i] = b[i] - A[i][k] * x[k];
	}
	return x;
}

int main()
{
	SLAU equation;
	double **matrixA = new double*[SIZE],
			*matrixB = new double[SIZE];
	for (int i = 0; i < SIZE; i++)
		matrixA[i] = new double[SIZE];
	matrixA[0][0] = 3;  matrixA[0][1] = 1;  matrixA[0][2] = 10;
	matrixA[1][0] = 14; matrixA[1][1] = 2;  matrixA[1][2] = 3;
	matrixA[2][0] = 2;  matrixA[2][1] = 12; matrixA[2][2] = 3;

	matrixB[0] = 18; matrixB[1] = 35; matrixB[2] = 31;

	equation.Gauss_Method(matrixA, matrixB);

	for (int i = 0; i < SIZE; i++)
		delete matrixA[i];
	delete[] matrixA;
	delete[] matrixB;
	return 0;
}