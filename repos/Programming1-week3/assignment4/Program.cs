using System;

namespace assignment4
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Enter first number: ");
            int number1 = int.Parse(Console.ReadLine());
            Console.Write("Enter second number: ");
            int number2 = int.Parse(Console.ReadLine());
            Console.Write("Enter third number: ");
            int number3 = int.Parse(Console.ReadLine());

            int highest, lowest;
            int sum = number1 + number2 + number3;
            double avg = sum / 3.0;
            int product = number1 * number2 * number3;

            if (number1 > number2)
            {
                highest = number1;
                lowest = number2;
            }
            else
            {
                highest = number2;
                lowest = number1;
            }
            if (highest < number3)
            {
                highest = number3;
            }
            if (lowest > number3)
            {
                lowest = number3;
            }

            Console.WriteLine("sum = " + sum);
            Console.WriteLine("average = " + avg.ToString("0.00"));
            Console.WriteLine("product = " + product);
            Console.WriteLine("highest = " + highest);
            Console.WriteLine("lowest = " + lowest);
        }
    }
}