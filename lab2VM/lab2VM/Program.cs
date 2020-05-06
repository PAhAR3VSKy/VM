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

        static void Iter_Form(double[,]A, double[]b, ref double[,] C, ref double[]d) //получение итерационной формы системы
        {
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

        static bool Check_Convergence(ref double[,]C, ref double[]d)
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
                return false;
            }
            else
                return true;
        }



        static double[] Simple_Iteration(ref double[,] A, ref double[] b) //метод простых итераций
        {
            double[,] matrixC = new double[Size, Size];
            double[] matrixD = new double[Size];
            double[] x0 = new double[Size];
            double[] X = new double[Size];
            double[] E = new double[Size];
            double delta;
            x0 = b;

            Iter_Form(A, b, ref matrixC, ref matrixD);
            while(!(Check_Convergence(ref matrixC, ref matrixD)))
            {
                // перестановка строк
            }
            do
            {
                for (int i = 0; i < Size; i++)
                {
                    X[i] = 0;
                    for (int j = 0; j < Size; j++)
                        X[i] = X[i] + matrixC[i, j] * x0[j];
                    X[i] = X[i] + matrixD[i];
                    E[i] = Math.Abs(X[i] - x0[i]);
                }
                delta = E[0];

                for (int i = 0; i < Size; i++)
                {
                    if (delta < E[i])
                        delta = E[i];
                }
                x0 = X;
            } while (delta <= 0.00001);

            return X;
        }

    
        static void Main(string[] args)
        {
            SLAU matrix = new SLAU();

            double[,] matrixA = new double[Size, Size];
            double[] matrixB = new double[Size];
            double[] matrixCout;

            matrixA[0, 0] = 3;  matrixA[0, 1] = 1;  matrixA[0, 2] = 10;
            matrixA[1, 0] = 14; matrixA[1, 1] = 2;  matrixA[1, 2] = 3;
            matrixA[2, 0] = 2;  matrixA[2, 1] = 12; matrixA[2, 2] = 3;

            matrixB[0] = 18;    matrixB[1] = 35;    matrixB[2] = 31;

            matrixCout = matrix.Gauss_Method(matrixA, matrixB);
            for (int i = 0; i < Size; i++)
                matrixCout[i] = Math.Round(matrixCout[i], 0, MidpointRounding.ToEven);

            Console.WriteLine("{0}", string.Join("\n", matrixCout));
        }
    }
}

