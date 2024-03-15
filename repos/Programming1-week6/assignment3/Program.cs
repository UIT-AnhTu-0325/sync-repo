namespace assignment3
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Enter year (0 is stop value): ");
            int input = int.Parse(Console.ReadLine());

            while (input != 0)
            {
                if (input < 0)
                {
                    Console.WriteLine("Negative year entered...");
                }
                else
                {
                    var result = IsLeapYear(input);

                    if (result == true)
                    {
                        Console.WriteLine($"{input} is a leap year.");
                    }
                    if (result == false)
                    {
                        Console.WriteLine($"{input} is not a leap year.");
                    }
                }
                Console.Write("Enter year (0 is stop value): ");
                input = int.Parse(Console.ReadLine());
            }
            Console.WriteLine("end of program");
        }

        static bool IsLeapYear(int year)
        {
            if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
            {
                return true;
            }
            return false;
        }
    }
}