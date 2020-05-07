using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace lab2VM
{
    
    class Program
    {
        
            
        static void Main(string[] args)
        {
            SLAU matrix = new SLAU();
            int n;
            int choice;
            Console.WriteLine("Введите количество уравнений: ");
            n = Convert.ToInt32(Console.ReadLine());
            double[,] matrixA = new double[n, n];
            double[] matrixB = new double[n];
            double[] x = new double[n];

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    Console.WriteLine("A[" + i + "][" + j + "] = ");
                    matrixA[i, j] = Convert.ToDouble(Console.ReadLine());
                }
            }
            Console.WriteLine("__________________________________________");
            for (int i = 0; i < n; i++)
            {
                Console.WriteLine("b[" + i + "] = ");
                matrixB[i] = Convert.ToDouble(Console.ReadLine());
            }

            Console.WriteLine("1. Метод Гаусса с выбором главного элемента по строке;\n" +
                              "2. Метод простой итерации.");
            choice = Convert.ToInt32(Console.ReadLine());
            switch (choice)
            {
                case 1:
                    x = matrix.Gauss_Method(matrixA, matrixB, n);
                    break;
                case 2:
                    x = matrix.Simple_Iter(matrixA, matrixB, n);
                    break;
                default:
                    Console.WriteLine("Неверный ввод!");
                    break;
            }
            if(x != null)
                for (int i = 0; i < n; i++)
                Console.WriteLine("x[" + i + "] = " + x[i]);
        }
    }
}

