#include <iostream>
#define SIZE 3

using namespace std;

class SLAU
{
public:
	double Gauss_Method(double **, double *);
	double Simple_Iteration();
};

double SLAU::Gauss_Method(double **A, double *x)
{
	double max;
	int k = 0,
		index = 0;

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
	}
	
}

int main()
{
	int **matrixA = new int*[SIZE];
	int* matrixB = new int[SIZE];
	for (int i = 0; i < SIZE; i++)
		matrixA[i] = new int[SIZE];
	matrixA[0][0] = 3;  matrixA[0][1] = 1;  matrixA[0][2] = 10;
	matrixA[1][0] = 14; matrixA[1][1] = 2;  matrixA[1][2] = 3;
	matrixA[2][0] = 2;  matrixA[2][1] = 12; matrixA[2][2] = 3;

	matrixB[0] = 18; matrixB[1] = 35; matrixB[2] = 31;



	for (int i = 0; i < SIZE; i++)
		delete matrixA[i];
	delete[] matrixA;
	delete[] matrixB;
	return 0;
}