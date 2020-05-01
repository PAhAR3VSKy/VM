#include <iostream>

using namespace std;

class SLAU
{
public:
	double Gauss_Method();
	double Simple_Iteration();
};

int main()
{
	int **matrixA = new int*[3];
	int* matrixB = new int[3];
	for (int i = 0; i < 3; i++)
		matrixA[i] = new int[3];
	matrixA[0][0] = 3;  matrixA[0][1] = 1;  matrixA[0][2] = 10;
	matrixA[1][0] = 14; matrixA[1][1] = 2;  matrixA[1][2] = 3;
	matrixA[2][0] = 2;  matrixA[2][1] = 12; matrixA[2][2] = 3;

	matrixB[0] = 18; matrixB[1] = 35; matrixB[2] = 31;



	for (int i = 0; i < 3; i++)
		delete matrixA[i];
	delete[] matrixA;
	delete[] matrixB;
	return 0;
}