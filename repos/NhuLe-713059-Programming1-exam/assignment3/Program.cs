using System;

namespace assignment3
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Enter a number: ");
            int input = int.Parse(Console.ReadLine());
            int[] array = new int[20];
            Random random = new Random();

            for (int i = 0; i < array.Length; i++)
            {
                array[i] = random.Next(1, 100);
                if (array[i] == input - 10 && array[i] == input + 10)
                {
                    Console.ForegroundColor = ConsoleColor.Green;
                }
                else if (array[i] == input - 20 && array[i] == input + 20)
                {
                    Console.ForegroundColor = ConsoleColor.Yellow;
                }
                else
                {
                    Console.ResetColor();
                }
                Console.Write(" " + array[i]);
            }
            
        }
    }
}

