using System;

namespace Assignment1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Enter your name:");
            string name = Console.ReadLine();

            Console.Write("Enter your age:");
            string age = Console.ReadLine();

            Console.WriteLine("Your name is " + name);
            Console.WriteLine("Your age is " + age);
        }
    }
}