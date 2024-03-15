namespace assignment5
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Enter a year: ");
            int year = int.Parse(Console.ReadLine());
            int count = 1;

            while (year != 0)
            {
                if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
                {
                    Console.WriteLine($"{year} is a leap year.");
                }
                else if (year < 0)
                {
                    Console.WriteLine($"Year must be positive!");
                }
                else
                {
                    Console.WriteLine($"{year} is not a leap year.");
                }
                count++;
                Console.Write("Enter a year: ");
                year = int.Parse(Console.ReadLine());
            }
        }
    }
}