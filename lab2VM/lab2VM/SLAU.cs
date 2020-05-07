using System;
namespace lab2VM
{

    class SLAU
    {
        
        public void Print(double[,]A, double[]b, int n)
        {
            for (int i = 0; i < n; i++)
            {
                Console.WriteLine("|");
                for (int j = 0; j < n; j++)
                    Console.Write(A[i, j]);
                Console.Write("|" + b[i] + "|");

            }
        }

        public double[] Gauss_Method(double[,] A, double[] b, int n)
        {
            int k = 0,
                index = 0;
            double max;
            double[] x = new double[n];

            while (k < n)
            {
                max = Math.Abs(A[0, 0]);
                for (int i = 0; i < n; i++)  // Поиск строки с максимальным элементом
                {
                    for (int j = 0; j < n; j++)
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

                for (int i = 0; i < n; i++)
                {
                    double temp1 = A[k, i];
                    A[k, i] = A[index, i];
                    A[index, i] = temp1;
                }

                double temp2 = b[k];
                b[k] = b[index];
                b[index] = temp2;

                // Нормализация уравнений
                for (int i = k; i < n; i++)
                {
                    double temp = A[i, k];

                    if (Math.Abs(temp) < 0)
                        continue;   // для нулевого коэффициента пропустить

                    for (int j = 0; j < n; j++)
                        A[i, j] = A[i, j] / temp;

                    b[i] = b[i] / temp;

                    if (i == k)
                        continue;   // уравнение не вычитать само из себя

                    for (int j = 0; j < n; j++)
                        A[i, j] = A[i, j] - A[k, j];

                    b[i] = b[i] - b[k];
                }
                k++;
            }
            // обратная подстановка
            for (k = n - 1; k >= 0; k--)
            {
                x[k] = b[k];
                for (int i = 0; i < k; i++)
                    b[i] = b[i] - A[i, k] * x[k];
            }
            return x;
        }
    }

}

