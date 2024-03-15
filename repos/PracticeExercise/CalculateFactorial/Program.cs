namespace CalculateFactorial
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Enter a number: ");
            int number = int.Parse(Console.ReadLine());
            int factorial = 1;

            if (number == 0 || number == 1)
            {
                Console.WriteLine($"Factorial is: {factorial}");
            }
            else if (number > 1)
            {
                for (int i = number - 1; i >= 1; i--)
                {
                    number *= i;
                }
                Console.WriteLine($"Factorial is: {number}");
            }
            else
            {
                Console.WriteLine("Cannot calculate factorial.");
            }
        }
    }
}