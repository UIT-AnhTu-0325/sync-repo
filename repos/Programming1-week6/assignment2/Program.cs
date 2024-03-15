namespace assignment2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Enter number (0 is stop value): ");
            int input = int.Parse(Console.ReadLine());

            while (input != 0)
            {
                if (input < 0)
                {
                    Console.WriteLine("Negative number entered...");
                }
                else
                {
                    var result = IsPrimeNumber(input);

                    if (result == false)
                    {
                        Console.WriteLine($"{input} is not a prime number.");
                    }
                    if (result == true)
                    {
                        Console.WriteLine($"{input} is a prime number.");
                    }
                }
                Console.Write("Enter number (0 is stop value): ");
                input = int.Parse(Console.ReadLine());
            }
            Console.WriteLine("end of program");
        }

        static bool IsPrimeNumber(int number)
        {
            for (int i = 2; i < number; i++)
            {
                if (number % i == 0)
                {
                    return false;
                }
            }
            return true;
        }
    }
}