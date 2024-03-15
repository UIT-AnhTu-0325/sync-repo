namespace assignment4
{
    internal class Program
    {
        static void Main(string[] args)
        {
            for (int i = 1; i <= 100; i++)
            {
                var result = CountDivisors(i);
                if (result >= 10)
                {
                    Console.WriteLine($"{i}: {result}");
                }
            }
            Console.WriteLine();
            Console.WriteLine("end of program");
        }
        static int CountDivisors(int number)
        {
            int count = 0;

            for (int i = 1; i <= number; i++)
            {
                if (number % i == 0)
                {
                    count++;
                }
            }
            return count;
        }
    }
}