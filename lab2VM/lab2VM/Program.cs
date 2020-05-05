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

        static double convergence(double[,] A)
        {
            double count = 0;
            double tempValue = 0;
            for (int i = 0; i < Size; i++)
            {
                for (int j = 0; j < Size; j++)
                {
                    tempValue += Math.Abs(A[i, j]);
                }
                if (Math.Abs(A[i, i]) > tempValue - Math.Abs(A[i, i]))
                    count++;
            }
            return count;
        }

        static void Iter_Form(double[,]A, double[]b) //получение итерационной формы системы
        {
            double[,] C = new double[Size, Size];
            double[] d = new double[Size];
            for (int i = 0; i < Size; i++)
            {
                for (int j = 0; j < Size; j++)
                {
                    if (i == j)
                        C[i, j] = 0;
                    else
                        C[i, j] = -A[i, j] / A[i, i];
                }
                d[i] = b[i] / A[i, i];
            }
        }

        static void Check_Convergence(double[,]C, double[]d)
        {
            int summ = 0;
            for (int i = 0; i < Size; i++)
            {
                for (int j = 0; j < Size; j++)
                    summ = (int)(summ + C[i, j] * C[i, j]);
            }

            if (Math.Sqrt(Math.Abs(summ)) > 1)
            {
                Console.WriteLine("Данная система не удовлетворяет условию сходимости");
                return null;
            }
            else
                return 0;
        }



        static double[] Simple_Iteration(double[,] A, double[] b) //метод простых итераций
        {
            double[] x0 = new double[Size];
            double[] X = new double[Size];
            double[] E = new double[Size];
            double delta;
            x0 = b;
            // do while
            for (int i = 0; i < Size; i++)
            {
                X[i] = 0;
                for (int j = 0; j < Size; j++)
                {
                    X[i] = X[i] + A[i, j] * x0[j];
                }
                X[i] = X[i] + b[i];
                E[i] = Math.Abs(X[i] - x0[i]);
            }
            delta = E[0];

            for (int i = 0; i < Size; i++)
            {
                if (delta < E[i])
                    delta = E[i];
            }
            x0 = X;
        }

        static double[] Gauss_Method(double[,] A, double[] b)
        {
            int k = 0,
                index = 0;
            double max = 0;
            double[] x = new double[Size];
            double[] tempMass = new double[2];

            while (k < Size)
            {
                max = Math.Abs(A[0, 0]);
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

