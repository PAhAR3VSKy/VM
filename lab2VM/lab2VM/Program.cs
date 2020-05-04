using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace lab2VM
{
    class Program
    {
        
        public static int Size = 3;

        static double[] Gauss_Method(double[,] A, double[] b)
        {
            int k = 0,
                index = 0;
            double max;
            double[] x = new double[Size];

            max = Math.Abs(A[0, 0]);
            while (k < Size)
            {
                for (int i = 0; i < Size; i++)  // Поиск строки с максимальным элементом
                {
                    for (int j = 0; j < Size; j++)
                    {
                        if (Math.Abs(A[i, j]) > max)
                        {
                            max = Math.Abs(A[i, j]);
                            index = i;
                        }
                    }
                }
                // Перестановка строк
                if (max < 0)    // нет ненулевых диагональных элементов
                {
                    Console.WriteLine("Решение получить невозможно из-за нулевого столбца");
                    Console.WriteLine(index + " матрицы A\n");
                    return null;
                }
                for (int i = 0; i < Size; i++)
                {
                    double temp1 = A[k, i];
                    A[k, i] = A[index, i];
                    A[index, i] = temp1;
                }
                double temp2 = b[k];
                b[k] = b[index];
                b[index] = temp2;
                // Нормализация уравнений
                for (int i = k; i < Size; i++)
                {
                    double temp = A[i, k];
                    if (Math.Abs(temp) < 0) continue;   // для нулевого коэффициента пропустить
                    for (int j = 0; j < Size; j++)
                        A[i, j] = A[i, j] / temp;
                    b[i] = b[i] / temp;
                    if (i == k) continue;   // уравнение не вычитать само из себя
                    for (int j = 0; j < Size; j++)
                        A[i, j] = A[i, j] - A[k, j];
                    b[i] = b[i] - b[k];
                }
                k++;
            }
            // обратная подстановка
            for (k = Size - 1; k >= 0; k--)
            {
                x[k] = b[k];
                for (int i = 0; i < k; i++)
                    b[i] = b[i] - A[i, k] * x[k];
            }
            return x;
        }
        static void Main(string[] args)
        {
            double[,] matrixA = new double[Size, Size];
            double[] matrixB = new double[Size];
            double[] matrixCout = new double[Size];

            matrixA[0, 0] = 3;  matrixA[0, 1] = 1;  matrixA[0, 2] = 10;
            matrixA[1, 0] = 14; matrixA[1, 1] = 2;  matrixA[1, 2] = 3;
            matrixA[2, 0] = 2;  matrixA[2, 1] = 12; matrixA[2, 2] = 3;

            matrixB[0] = 18;    matrixB[1] = 35;    matrixB[2] = 31;

            matrixCout = Gauss_Method(matrixA, matrixB);
            for (int i = 0; i < Size; i++)
                matrixCout[i] = Math.Round(matrixCout[i], 0, MidpointRounding.ToEven);

            Console.WriteLine("{0}", string.Join("\n", matrixCout));
        }
    }
}

