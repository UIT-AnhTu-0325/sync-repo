using System;

namespace assignment1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[] array = new int[20];
            Random random = new Random();
            int sum = 0;

            for (int i = 0; i < array.Length; i++)
            {
                array[i] = random.Next(0, 201);
                sum += array[i];
                Console.WriteLine($"Element {i} is {array[i]}");
            }
            var avg = (double) sum / array.Length;

            Console.WriteLine($"The average is: {avg.ToString("0.00")}");

            for (int i = 0; i < array.Length; i++)
            {
                var diff = Math.Abs(array[i] - avg);
                Console.WriteLine($"Difference between average and element {i} is {diff.ToString("0.00")}");
            }
        }
    }
}