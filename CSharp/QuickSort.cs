using System;

namespace QuickSort {
    class Program {
        static int partition(int[] A, int start, int end) {
            int pivot = A[(start + end) / 2];
            int i = start;
            int j = end;

            while (i <= j) {
                while (A[i] < pivot)
                    i++;
                while (A[j] > pivot)
                    j--;
                if (i <= j) {
                    int temp = A[i];
                    A[i] = A[j];
                    A[j] = temp;

                    i++;
                    j--;
                }
            }

            return i;
        }

        static void qSort(int[] A, int start, int end) {
            if (start < end) {
                int temp = partition(A, start, end);

                qSort(A, start, temp - 1);
                qSort(A, temp, end);
            }
        }

        static void print(int[] A) {
            for (int i = 0; i < A.Length; ++i)
                Console.Write("{0} ", A[i]);
            Console.WriteLine();
        }

        static void Main(string[] args) {
            Random rnd = new Random();
            const int n = 10;
            int[] A = new int[n];

            for (int i = 0; i < n; ++i)
                A[i] = rnd.Next(10);

            print(A);
            qSort(A, 0, A.Length - 1);
            print(A);
        }
    }
}
