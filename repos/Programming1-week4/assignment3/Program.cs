namespace assignment3
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Enter a number: ");
            int num = int.Parse(Console.ReadLine());
            int count = 1;
            int sum = 0;

            while (num != 0)
            {
                if (count % 5 == 0)
                {
                    sum += num;
                }
                count++;
                Console.Write("Enter a number: ");
                num = int.Parse(Console.ReadLine());
            }
            Console.WriteLine($"Sum of 5th, 10th, 15th, ... number is: {sum}");
        }
    }
}