namespace PrimeNumber
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Prime numbers less than 100: \n");
            for (int i = 0; i < 100; i++)
            {
                if (IsPrimeNumber(i))
                {
                    Console.WriteLine(i);
                }
            }
        }
        static bool IsPrimeNumber (int n)
        {
            for (int i = 2; i < n; i++)
            {
                if (n % i == 0)
                {
                    return false;
                }
            }
            return true;
        }
    }
}