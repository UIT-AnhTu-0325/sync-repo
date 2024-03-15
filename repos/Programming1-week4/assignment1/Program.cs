namespace assignment1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Enter a number: ");
            double input = int.Parse(Console.ReadLine());
            double sum = 0;
            double count = 0;

            while (input != 0)
            {             
                if (input > 0)
                {
                    sum += input;
                    count++;
                }
                Console.Write("Enter a number: ");
                input = double.Parse(Console.ReadLine());
            }
            if (count == 0)
            {
                count = 1;
                sum = 0;
            }
            Console.WriteLine($"Average of all positive numbers is: {(sum / count).ToString("0.00")}");
        }
    }
}

