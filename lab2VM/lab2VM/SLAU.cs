using System;
namespace lab2VM
{

    class SLAU
    {

        private void Print(double[,]A, double[]b, int n)
        {
            for (int i = 0; i < n; i++)
            {
                Console.WriteLine("|");
                for (int j = 0; j < n; j++)
                    Console.Write(A[i, j]);
                Console.Write("|" + b[i] + "|");

            }
        }

        private bool Check_Convergence(double[,]A, int n)
        {
            double summ = 0, mid = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i == j)
                        mid = Math.Abs(A[i, j]);
                    else
                        summ += Math.Abs(A[i, j]);
                }
                if (mid < summ)
                    return false;
                summ = 0;
            }
            return true;
        }

        private bool Check_Pogr(double[]E, double eps, int n)
        {
            for (int i = 0; i < n; i++)
                if (Math.Abs(E[i]) > eps)
                    return false;
            return true;
        }

        public double[] Simple_Iter(double[,]A, double[]b, int n)
        {
            double[] x0 = new double[n];
            double[] X = new double[n];
            double[] E = new double[n];
            double eps, summ;

            for (int i = 0; i < n; i++)
                X[i] = 0;

            Console.WriteLine("Введите погрешность: ");
            eps = Convert.ToDouble(Console.ReadLine());

            if(!Check_Convergence(A, n))
            {
                Console.WriteLine("Матрица не может быт решена методом простых итераций!");
                return null;
            }
            else
            {
                int count = 0;
                do
                {
                    for (int i = 0; i < n; i++)
                    {
                        for (int k = 0; k < n; k++)
                            x0[k] = X[k];
                        summ = 0;

                        for (int j = 0; j < n; j++)
                        {
                            if (j != i)
                                summ += (A[i, j] * x0[j]);
                        }

                        X[i] = (b[i] - summ) / A[i, i];
                        E[i] = X[i] - x0[i];
                    }
                    count++;
                } while (!Check_Pogr(E, eps, n));
                Console.WriteLine("Количество итераций = " + count);
                return X;
            }
        }

        public double[] Gauss_Method(double[,] A, double[] b, int n)
        {
            int k = 0,
                index = 0;
            double max;
            double eps = 0.00001;
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
                if (max < eps)    // нет ненулевых диагональных элементов
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

