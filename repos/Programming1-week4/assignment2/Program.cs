namespace assignment2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Enter target number: ");
            int targetNum = int.Parse(Console.ReadLine());
            Console.Write("Enter a number: ");
            int num = int.Parse(Console.ReadLine());
            int count = 0;

            while (num != 0)
            {
                if (num == targetNum)
                {
                    count++;
                }
                Console.Write("Enter a number: ");
                num = int.Parse(Console.ReadLine());
            }
            Console.WriteLine($"Count of numbers equal to target number: {count}");
        }
    }
}



